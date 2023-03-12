#include <ultra64.h>
#include <PR/R4300.h>
#include <PR/os.h>
#include <PR/os_internal.h>
#include <PR/rcp.h>
#include <bondgame.h>
#include "boot.h"
#include "sched.h"
#include "rmon.h" /*<PR/rmon.h>*/
#include "tlb_resolve.h"
#include "tlb_hardwire.h"
#include "init.h"
#include "thread_config.h"

#include "usb.h"

/**
 * EU .data, offset from start of data_seg : 0x22B0
*/

/**
 * @file init.c
 * This file contains the initial non bootstrap code ran. 
 * 
 * In particular, it:
 *   - unpacks main data payload
 *   - starts idle and rmon loops
 *   - starts main loop
 */

#define NUM_FIELDS  1


u32 unknown_val_80023040 = 0;
/*D:80023044*/
u32 unknown_init_val = PI_CLR_INTR;

u32 cart_hw_address = PI_DOM1_ADDR2;

union debug_handler_container
{
    /* There is a bulk memory copy of debug_handler_table,
    * it seems to require a container with a known size,
    * which doesn't seem correct ....
    */
    struct debug_handler_entry rows[7];
    s32 data[14];
};

union debug_handler_container debug_handler_table = {
    {
        {sp_boot, "boot"},
        {sp_rmon, "rmon"},
        {sp_idle, "idle"},
        {sp_shed, "shed"},
        {sp_main, "main"},
        {sp_audi, "audi"},
        {0, 0}
    }
};

OSThread rmonThread;
OSThread idleThread;
OSThread mainThread;
OSThread shedThread;
OSMesgQueue gfxFrameMsgQ;
OSMesg gfxFrameMsgBuf[32];
OSMesgQueue *sched_cmdQ;

void mainproc(void *args);



/**
 * 1110	70000510
 * ???	initializes TLB index...
 *	copies compressed 21990 to virtual address 701EE400, using 70200000 to decompress
 */
void init(void)
{
    u32 inflateromSize;
    u8 *csegmentSegmentVaddrStart;
    u8 *cdataSegmentRomStart;
    u32 flags;
    u32 cdataSegmentRomSize;
    u8 *inflateSegmentRomStart;
    s32 i;
    s32 j;
    
    u8 *datazipram;
    s32 inflate_code_size;
    u32 decompress_result;
    s32 *dest;
    s32 *src;
    u32 copylen;
    s32 *stack_pointer;
    u8 *dataziprom;

    csegmentSegmentVaddrStart = get_csegmentSegmentStart();
    cdataSegmentRomStart = get_cdataSegmentRomStart();
    cdataSegmentRomSize = (u8*)get_cdataSegmentRomEnd() - cdataSegmentRomStart;
    inflateSegmentRomStart = get_inflateSegmentRomStart();
    inflateromSize = (u8*)get_inflateSegmentRomEnd() - inflateSegmentRomStart;
    copylen = cdataSegmentRomSize + inflateromSize;
    datazipram = (u8 *)(0x70200000 - cdataSegmentRomSize);
    dataziprom = csegmentSegmentVaddrStart;
    
    for (j = copylen - 1; j >= 0; j--)
    {
        datazipram[j] = dataziprom[j];
    }
    
    decompress_result = jump_decompressfile(datazipram, csegmentSegmentVaddrStart, 0x80300000);
    if(decompress_result);

    inflate_code_size = (s32)((u32)&_inflateSegmentRomStart - (u32)&_codeSegmentRomStart);
    
    if (inflate_code_size > 0xFFFB0)
    {
        osPiRawStartDma(0, &_alt_startSegmentRomStart, &_alt_startSegmentStart, inflate_code_size - 0xFFFB0);
        while ((osPiGetStatus() & 1)) {}
    }
    
    osInitialize();
    set_hardwire_TLB_to_2();
    
    src = &resolve_TLBaddress_for_InvalidHit;
    dest = (s32 *) K0BASE;
    while ( dest < (s32 *) XUT_VEC )
    {
        *dest++ = *src++;
    }
    
    osWritebackDCacheAll();
    osInvalICache((void *) K0BASE, ICACHE_SIZE);
    
    for (i=2; i<32; i++)
    {
        osUnmapTLB(i);
    }

    flags = __osGetFpcCsr();
    flags |= FPCSR_EI; // enable inexact operation
	flags |= FPCSR_EO; // enable overflow
	flags |= FPCSR_EZ; // enable division by zero
	flags |= FPCSR_EV; // enable invalid operation
    __osSetFpcCsr(flags);

    stack_pointer = set_stack_entry(sp_main, STACKSIZE_MAIN);
    osCreateThread(&mainThread, MAIN_THREAD_ID, &mainproc, NULL, stack_pointer, MAIN_THREAD_PRIORITY);
    osStartThread(&mainThread);
}



/**
 * 12F0	700006F0
 * V0= new stack pointer; A0+A1-8
 *	accepts: A0=base address, A1=size
 */
void *set_stack_entry(u8 *stack, u32 size) 
{
    return stack+size-8;
}

/**
 * 12FC	700006FC
 * 1->80023044, 10000000->80023048
 */
void set_hw_address_and_unknown(void) 
{
    unknown_init_val = PI_SET_RESET;
    cart_hw_address = PI_DOM1_ADDR2;
}

/**
 * 1318	70000718
 * A0->SP+0, infinite loop
 */
void idleproc(void *arg) 
{
	for (;;);
}

/**
 * 1338	70000738
 * Null thread; executes 70000718
 */
void idleCreateThread(void) 
{
    osCreateThread(&idleThread, IDLE_THREAD_ID, idleproc, 0, set_stack_entry(&sp_idle, 0x40), IDLE_THREAD_PRIORITY);
    osStartThread(&idleThread);
}

/**
 * 1390	70000790
 * Indi board detection thread; now forcably returns INDI_NOT_DETECTED (1)
 */
void rmonCreateThread(void) 
{
    osCreateThread(&rmonThread, RMON_THREAD_ID, rmonMain, 0, set_stack_entry(&sp_rmon, 0x300), RMON_THREAD_PRIORITY);
    osStartThread(&rmonThread);
}

/**
 * 13EC	700007EC
 */
void schedulerInitThread(void)
{
    osCreateMesgQueue(&gfxFrameMsgQ, &gfxFrameMsgBuf, 32);
    if (osTvType == 2) //OS_TV_MPAL
    { 
        osCreateScheduler(&os_scheduler, &shedThread, OS_VI_MPAL_LAN1, NUM_FIELDS);
    }
    else 
    {
        osCreateScheduler(&os_scheduler, &shedThread, OS_VI_NTSC_LAN1, NUM_FIELDS);
	}

    osScAddClient(&os_scheduler, &gfxClient, &gfxFrameMsgQ, 0);
    sched_cmdQ = osScGetCmdQ(&os_scheduler);
}

/**
 * 149C	7000089C	datastart main game setup and loop
 *	calls command line parser, debug console setup, etc.
 *	called by 70000510, using 7000D430: A0=8005D640, A1=3, A2=7000089C, A3=0, SP+10=[803B3948], SP+14=0xA
 *	never returns; 7000601C is an infinite loop
 */
void mainproc(void *args)
{
	idleCreateThread();
	viDebugRemoved();
	piCreateManager();
#ifdef ENABLE_USB
    // make debug print output available as soon as possible.
    // This uses blocking calls, and the PI manager, so can't be called
    // before here.
    usb_initialize();
#else
	rmonCreateThread();
#endif
	if (tokenReadIo() != 0)
	{
		osStopThread(0);
	}
	
    osSetThreadPri(NULL, 0xa);
    // Timers are initialized via:
    // schedulerInitThread -> osCreateScheduler -> osCreateViManager -> __osTimerServicesInit
    schedulerInitThread();
#ifdef ENABLE_USB
    // Unlike the pure source, this version injects a dependency on timer, so can't init
    // before here.
    rmonCreateThread();
#endif
    bossEntry();
}

/**
 * 1508	70000908	V0= p->last entry in copy of debug handler code/name table; fries AT,V1,T0,T1,T6,T9
 *	copies table from 8002304C-80023084 to stack
 */
void setuplastentryofdebughandler(void)
{
    union debug_handler_container dhe;
    struct debug_handler_entry *p;

    dhe = debug_handler_table;

    p = &dhe.rows[0];
    
    do
    {
        p++;
    } while (p->address != NULL);
}