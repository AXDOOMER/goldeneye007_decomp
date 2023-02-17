#include <ultra64.h>
#include <PR/R4300.h>
#include <PR/os.h>
#include <PR/os_internal.h>
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
u32 unknown_init_val = 2;

u32 cart_hw_address = 0x10000000;

struct debug_handler_entry debug_handler_table[] = 
{
    {sp_boot, "boot"},
    {sp_rmon, "rmon"},
    {sp_idle, "idle"},
    {sp_shed, "shed"},
    {sp_main, "main"},
    {sp_audi, "audi"},
    {0, 0},
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
    unknown_init_val = 1;
    cart_hw_address = 0x10000000;
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
#ifdef NONMATCHING
void setuplastentryofdebughandler(void)

{
  //debug_handler_entry *new;
  //debug_handler_entry *old;
  debug_handler_entry local_38 [7];
  s32 i;
  
  //debug_handler_entry *nextnewname;
  //debug_handler_entry *nextoldname;
  /*
  nextoldname = debug_handler_table;
  nextnewname = local_38;
  do {
    new = nextnewname;
    old = nextoldname;
    new->address = old->address;
    new->ptr_name = old->ptr_name;
    new[1].address = old[1].address;
    nextoldname = &old[1].ptr_name;
    nextnewname = &new[1].ptr_name;
  } while (&old[1].ptr_name != debug_handler_table + 6);
  (&new[1].ptr_name)->address = debug_handler_table[6].address;
  new[2].address = old[2].address;
  nextnewname = local_38;
  while (local_38[1].address != 0x0) {
    local_38[1].address = nextnewname[2].address;
    nextnewname = nextnewname + 1;
  }
  return;
  */
 for (i=0;i<8;i++)
 {
     *(debug_handler_entry*)&local_38[i]=*(debug_handler_entry*)&debug_handler_table[i];
 }
 for (i=1;local_38[i].address; i++)
 {
     local_38[i].address = local_38[i+1].address;
 }
}
//#ifdef NONMATCHING
#else
GLOBAL_ASM(
.section .text
glabel setuplastentryofdebughandler
/* 001508 70000908 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 00150C 7000090C 3C0E8002 */  lui   $t6, %hi(debug_handler_table) 
/* 001510 70000910 27A30008 */  addiu $v1, $sp, 8
/* 001514 70000914 25CE304C */  addiu $t6, %lo(debug_handler_table) # addiu $t6, $t6, 0x304c
/* 001518 70000918 25D90030 */  addiu $t9, $t6, 0x30
/* 00151C 7000091C 00604025 */  move  $t0, $v1
.L70000920:
/* 001520 70000920 8DC10000 */  lw    $at, ($t6)
/* 001524 70000924 25CE000C */  addiu $t6, $t6, 0xc
/* 001528 70000928 2508000C */  addiu $t0, $t0, 0xc
/* 00152C 7000092C AD01FFF4 */  sw    $at, -0xc($t0)
/* 001530 70000930 8DC1FFF8 */  lw    $at, -8($t6)
/* 001534 70000934 AD01FFF8 */  sw    $at, -8($t0)
/* 001538 70000938 8DC1FFFC */  lw    $at, -4($t6)
/* 00153C 7000093C 15D9FFF8 */  bne   $t6, $t9, .L70000920
/* 001540 70000940 AD01FFFC */   sw    $at, -4($t0)
/* 001544 70000944 8DC10000 */  lw    $at, ($t6)
/* 001548 70000948 00601025 */  move  $v0, $v1
/* 00154C 7000094C AD010000 */  sw    $at, ($t0)
/* 001550 70000950 8DD90004 */  lw    $t9, 4($t6)
/* 001554 70000954 AD190004 */  sw    $t9, 4($t0)
/* 001558 70000958 8C490008 */  lw    $t1, 8($v0)
.L7000095C:
/* 00155C 7000095C 24420008 */  addiu $v0, $v0, 8
/* 001560 70000960 5520FFFE */  bnezl $t1, .L7000095C
/* 001564 70000964 8C490008 */   lw    $t1, 8($v0)
/* 001568 70000968 03E00008 */  jr    $ra
/* 00156C 7000096C 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif
