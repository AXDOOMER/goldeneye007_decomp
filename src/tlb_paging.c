#include "ultra64.h"
#include "libultra/libultra_internal.h"
#include "PR/os_thread.h"
#include "bondgame.h"
#include "tlb_manage.h"
#include "deb_print.h"
#include "ramrom.h"
#include "PR/R4300.h"
#include "thread_config.h"

/**
 * @file deb_video.c
 * This file contains code to handle tlb paging. 
 * 
 * Additionally, it contains unused/removed debug code, and code for indy.
 * The function addresses seem to indicate these methods are all in the same file ...
 */

/**
 * Size in bytes.
 */
#define g_indyReadBuffer_LEN 0x60

/**
 * Copied from n64devkit\ultra\usr\src\pr\demos\fault\fault.c
 */
#define MSG_FAULT    0x10

#define TLB_MESSAGE_QUEUE_SIZE      1

/*
-----------------------------------------------------------------
| ADDIU     | ADD Immediate Unsigned word                       |
|-----------|---------------------------------------------------|
|001001 (9) |   rs    |   rt    |          immediate            |
------6----------5---------5-------------------16----------------
 Format:  ADDIU rt, rs, immediate
 Purpose: To add a constant to a 32-bit integer.
 Descrip: rt = rs + immediate

-----------------------------------------------------------------
| SW        | Store Word                                        |
|-----------|---------------------------------------------------|
|101011 (43)|  base   |   rt    |             offset            |
------6----------5---------5-------------------16----------------
 Format:  SW rt, offset(base)
 Purpose: To store a word to memory.
 Descrip: word[base+offset] = rt

-----------------------------------------------------------------
| JR        | Jump Register                                     |
|-----------|---------------------------------------------------|
|  000000   |   rs    |     0000 0000 0000 000      |001000 (8) |
------6----------5------------------15--------------------6------
 Format:  JR rs
 Purpose: To branch to an instruction address in a register.
*/

/**
 * Add immediate unsigned word. Upper 6 bits out of 32.
 */
#define MIPS_OP_BITS_ADDIU 0x09

/**
 * Store word. Upper 6 bits out of 32.
 */
#define MIPS_OP_BITS_SW 0x2b

/**
 * Jump to register. Upper 6 bits out of 32.
 */
#define MIPS_OP_BITS_JR 0x00

/**
 * Five bits defining register source or destination, for stack pointer register.
 */
#define MIPS_REG_SOURCE_BITS_SP 0x1d

/**
 * Five bits defining register source or destination, for return address register.
 */
#define MIPS_REG_SOURCE_BITS_RA 0x1f

/**
 * Builds 32 bit word to perform ADDIU.
 * 
 * No error checking or input size validation are performed here.
 * 
 * @param source_r: source register number (5 bits).
 * @param dest_r: destination register number (5 bits).
 * @param imm: 16 bit immediate value to add.
 */
#define MIPS_INSTR_ADDIU(source_r, dest_r, imm) ((MIPS_OP_BITS_ADDIU << 26) | (source_r << 21) | (dest_r << 16) | imm)

/**
 * Builds 32 bit word to perform SW.
 * 
 * No error checking or input size validation are performed here.
 * 
 * @param val_r: source register holding value to store (5 bits).
 * @param dest_r: register holding destination base address (5 bits).
 * @param offset: 16 bit offset from base address to store value at.
 */
#define MIPS_INSTR_SW(val_r, dest_r, offset) ((MIPS_OP_BITS_SW << 26) | (dest_r << 21) | (val_r << 16) | offset)

/**
 * Builds 32 bit word to perform SW.
 * 
 * No error checking or input size validation are performed here.
 * 
 * Note: lower 6 bits of JR instruction are always 0x08.
 * 
 * @param dest_r: register holding destination address (5 bits).
 */
#define MIPS_INSTR_JR(dest_r) ((MIPS_OP_BITS_JR << 26) | (dest_r << 21) | 8)

/**
 * Any MIPS 32-bit instruction matching $sp increment
 * 
 * 0x27BD0000 = # addiu $sp, $sp <any_immediate>
 */
#define MIPS_ADDIU_SP_SP_ANY        MIPS_INSTR_ADDIU(MIPS_REG_SOURCE_BITS_SP, MIPS_REG_SOURCE_BITS_SP, 0)
#define MIPS_ADDIU_SP_SP_ANY_MASK   0xFFFF0000

/**
 * Any MIPS 32-bit instruction matching sw into $sp
 * 
 * 0xAFA00000 = sw <any_register>, 0x[any_offset]($sp)
 */
#define MIPS_SW_SP_ANY       MIPS_INSTR_SW(0, MIPS_REG_SOURCE_BITS_SP, 0)
#define MIPS_SW_SP_ANY_MASK  0xFFE00000

/**
 * Any MIPS 32-bit instruction (should only be one...) matching jump to return address.
 * 
 * 0x03E00008 = jr ra
 */
#define MIPS_JR_RA MIPS_INSTR_JR(MIPS_REG_SOURCE_BITS_RA)

// bss - TLB section

OSThread g_tlbThread;
u8 g_tlbUnused[0x500];
char g_tlbStack[0x2300];
OSMesgQueue g_tlbMesgQ;
OSMesg *g_tlbMesgBuf;
OSThread *g_tlbFaultedThreadPtr;
u32 dword_CODE_bss_80063660;

// bss - indy/debug section

u32 *g_indyCurrentReadBufferResourceId;
u8 *g_indyReadBufferString1;
u8 *g_indyReadBufferString2;
char g_indyReadBuffer[g_indyReadBuffer_LEN];

// forward declarations

void tlbMain(void* arg0);

// end forward declarations

/**
 * 5AE0    70004EE0
 */
void tlbInit(void)
{
    deboutInitBuffers();
    osCreateMesgQueue(&g_tlbMesgQ, (OSMesg *)&g_tlbMesgBuf, TLB_MESSAGE_QUEUE_SIZE);
    osCreateThread(&g_tlbThread, TLB_THREAD_ID, &tlbMain, NULL, &g_tlbStack, TLB_THREAD_PRIORITY);
    osStartThread(&g_tlbThread);
}

/**
 * 5B54    70004F54
 * 
 * @param arg0 Unused.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: fail
 * - identical instructions: yes
 * - identical registers: yes
 * 
 * Only 5 words differ. Two are the location of `msg` on the stack, fixing
 * whatever is off should fix the 'msg' location automatically.
 * 
 * current                                target
 * addiu	sp,sp,-72                     addiu	sp,sp,-64
 * sw	a0,72(sp)                         sw	a0,64(sp)
 * sw	zero,68(sp)                       sw	zero,60(sp)
 * addiu	s1,sp,68                      addiu	s1,sp,60
 * addiu	sp,sp,72                      addiu	sp,sp,64
 */
#ifdef NONMATCHING
void tlbMain(void* arg0)
{
    OSMesg msg = 0;
    OSIntMask startingInterruptMask;
    OSThread *faultedThread;

    /**
     * Target generates 5 separate dereferences of g_tlbFaultedThreadPtr,
     * only way I can get that to happen is with a pointer to a pointer.
     */
    OSThread **ppfaultedThread = &g_tlbFaultedThreadPtr;

    osSetEventMesg(OS_EVENT_FAULT, &g_tlbMesgQ, (OSMesg)MSG_FAULT);
    dword_CODE_bss_80063660 = 0;

    while (1)
    {
        osRecvMesg(&g_tlbMesgQ, &msg, OS_MESG_BLOCK);
        startingInterruptMask = osSetIntMask(OS_IM_NONE);
        faultedThread = __osGetCurrFaultedThread();
        *ppfaultedThread = faultedThread;

        if (faultedThread == NULL)
        {
            continue;
        }
        else if (((faultedThread->context.cause & CAUSE_EXCMASK) == EXC_RMISS) && ((faultedThread->context.badvaddr & 0xFFC00000) == (u32)0x7F000000))
        {
            tlbmanageTranslateLoadRomFromTlbAddress((*ppfaultedThread)->context.badvaddr);
            (*ppfaultedThread)->state = (u16)0xA;
            (*ppfaultedThread)->flags = (u16)0;

            __osEnqueueThread(&__osRunQueue, *ppfaultedThread);
            osSetIntMask(startingInterruptMask);
            osYieldThread();
        }
        else
        {
            break;
        }
    }

    osSetIntMask(startingInterruptMask);

    // infinite loop
    while (1) {}
}
#else
GLOBAL_ASM(
.text
glabel tlbMain
/* 005B54 70004F54 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 005B58 70004F58 AFB70030 */  sw    $s7, 0x30($sp)
/* 005B5C 70004F5C 3C178006 */  lui   $s7, %hi(g_tlbMesgQ) 
/* 005B60 70004F60 26F73640 */  addiu $s7, %lo(g_tlbMesgQ) # addiu $s7, $s7, 0x3640
/* 005B64 70004F64 AFBF0034 */  sw    $ra, 0x34($sp)
/* 005B68 70004F68 AFA40040 */  sw    $a0, 0x40($sp)
/* 005B6C 70004F6C AFB6002C */  sw    $s6, 0x2c($sp)
/* 005B70 70004F70 AFB50028 */  sw    $s5, 0x28($sp)
/* 005B74 70004F74 AFB40024 */  sw    $s4, 0x24($sp)
/* 005B78 70004F78 AFB30020 */  sw    $s3, 0x20($sp)
/* 005B7C 70004F7C AFB2001C */  sw    $s2, 0x1c($sp)
/* 005B80 70004F80 AFB10018 */  sw    $s1, 0x18($sp)
/* 005B84 70004F84 AFB00014 */  sw    $s0, 0x14($sp)
/* 005B88 70004F88 AFA0003C */  sw    $zero, 0x3c($sp)
/* 005B8C 70004F8C 2404000C */  li    $a0, 12
/* 005B90 70004F90 02E02825 */  move  $a1, $s7
/* 005B94 70004F94 0C003714 */  jal   osSetEventMesg
/* 005B98 70004F98 24060010 */   li    $a2, 16
/* 005B9C 70004F9C 3C018006 */  lui   $at, %hi(dword_CODE_bss_80063660)
/* 005BA0 70004FA0 3C168002 */  lui   $s6, %hi(__osRunQueue)
/* 005BA4 70004FA4 AC203660 */  sw    $zero, %lo(dword_CODE_bss_80063660)($at)
/* 005BA8 70004FA8 26D67728 */  addiu $s6, %lo(__osRunQueue) # addiu $s6, $s6, 0x7728
/* 005BAC 70004FAC 2415000A */  li    $s5, 10
/* 005BB0 70004FB0 3C14FFC0 */  lui   $s4, 0xffc0
/* 005BB4 70004FB4 3C137F00 */  lui   $s3, 0x7f00
/* 005BB8 70004FB8 24120008 */  li    $s2, 8
/* 005BBC 70004FBC 27B1003C */  addiu $s1, $sp, 0x3c
.L70004FC0:
/* 005BC0 70004FC0 02E02025 */  move  $a0, $s7
.L70004FC4:
/* 005BC4 70004FC4 02202825 */  move  $a1, $s1
/* 005BC8 70004FC8 0C003774 */  jal   osRecvMesg
/* 005BCC 70004FCC 24060001 */   li    $a2, 1
/* 005BD0 70004FD0 0C00374C */  jal   osSetIntMask
/* 005BD4 70004FD4 24040001 */   li    $a0, 1
/* 005BD8 70004FD8 0C004060 */  jal   __osGetCurrFaultedThread
/* 005BDC 70004FDC 00408025 */   move  $s0, $v0
/* 005BE0 70004FE0 3C018006 */  lui   $at, %hi(g_tlbFaultedThreadPtr)
/* 005BE4 70004FE4 1040FFF6 */  beqz  $v0, .L70004FC0
/* 005BE8 70004FE8 AC22365C */   sw    $v0, %lo(g_tlbFaultedThreadPtr)($at)
/* 005BEC 70004FEC 8C4E0120 */  lw    $t6, 0x120($v0)
/* 005BF0 70004FF0 3C088006 */  lui   $t0, %hi(g_tlbFaultedThreadPtr) 
/* 005BF4 70004FF4 31CF007C */  andi  $t7, $t6, 0x7c
/* 005BF8 70004FF8 164F0018 */  bne   $s2, $t7, .L7000505C
/* 005BFC 70004FFC 00000000 */   nop   
/* 005C00 70005000 8C580124 */  lw    $t8, 0x124($v0)
/* 005C04 70005004 0314C824 */  and   $t9, $t8, $s4
/* 005C08 70005008 16790014 */  bne   $s3, $t9, .L7000505C
/* 005C0C 7000500C 00000000 */   nop   
/* 005C10 70005010 8D08365C */  lw    $t0, %lo(g_tlbFaultedThreadPtr)($t0)
/* 005C14 70005014 0C000676 */  jal   tlbmanageTranslateLoadRomFromTlbAddress
/* 005C18 70005018 8D040124 */   lw    $a0, 0x124($t0)
/* 005C1C 7000501C 3C098006 */  lui   $t1, %hi(g_tlbFaultedThreadPtr) 
/* 005C20 70005020 8D29365C */  lw    $t1, %lo(g_tlbFaultedThreadPtr)($t1)
/* 005C24 70005024 3C0A8006 */  lui   $t2, %hi(g_tlbFaultedThreadPtr) 
/* 005C28 70005028 3C058006 */  lui   $a1, %hi(g_tlbFaultedThreadPtr)
/* 005C2C 7000502C A5350010 */  sh    $s5, 0x10($t1)
/* 005C30 70005030 8D4A365C */  lw    $t2, %lo(g_tlbFaultedThreadPtr)($t2)
/* 005C34 70005034 02C02025 */  move  $a0, $s6
/* 005C38 70005038 A5400012 */  sh    $zero, 0x12($t2)
/* 005C3C 7000503C 0C00422B */  jal   __osEnqueueThread
/* 005C40 70005040 8CA5365C */   lw    $a1, %lo(g_tlbFaultedThreadPtr)($a1)
/* 005C44 70005044 0C00374C */  jal   osSetIntMask
/* 005C48 70005048 02002025 */   move  $a0, $s0
/* 005C4C 7000504C 0C0042B4 */  jal   osYieldThread
/* 005C50 70005050 00000000 */   nop   
/* 005C54 70005054 1000FFDB */  b     .L70004FC4
/* 005C58 70005058 02E02025 */   move  $a0, $s7
.L7000505C:
/* 005C5C 7000505C 0C00374C */  jal   osSetIntMask
/* 005C60 70005060 02002025 */   move  $a0, $s0
.L70005064:
/* 005C64 70005064 1000FFFF */  b     .L70005064
/* 005C68 70005068 00000000 */   nop   
/* 005C6C 7000506C 00000000 */  nop   
/* 005C70 70005070 00000000 */  nop   
/* 005C74 70005074 00000000 */  nop   
/* 005C78 70005078 00000000 */  nop   
/* 005C7C 7000507C 00000000 */  nop   
/* 005C80 70005080 8FBF0034 */  lw    $ra, 0x34($sp)
/* 005C84 70005084 8FB00014 */  lw    $s0, 0x14($sp)
/* 005C88 70005088 8FB10018 */  lw    $s1, 0x18($sp)
/* 005C8C 7000508C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 005C90 70005090 8FB30020 */  lw    $s3, 0x20($sp)
/* 005C94 70005094 8FB40024 */  lw    $s4, 0x24($sp)
/* 005C98 70005098 8FB50028 */  lw    $s5, 0x28($sp)
/* 005C9C 7000509C 8FB6002C */  lw    $s6, 0x2c($sp)
/* 005CA0 700050A0 8FB70030 */  lw    $s7, 0x30($sp)
/* 005CA4 700050A4 03E00008 */  jr    $ra
/* 005CA8 700050A8 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

/**
 * Given a pointer to an instruction and a stack frame pointer, attempt to find
 * the calling function. Return the address of the caller's stack frame and
 * populate regs with stack addresses where that register was saved. This can be
 * used to retrieve the RA value and invoke crashGetParentStackFrame again to
 * build a backtrace.
 *
 * @param origptr is a pointer to an instruction. This should be either the value of
 *     the PC register of the faulted thread, or an RA register if searching a
 *     parent.
 * @param minaddr is the memory address of the start of the code segment,
 *     ie. 0x70001050. This is used to prevent the function from walking out of
 *     the code segment.
 * @param origsp is the address of the stack frame for the given origptr.
 * @param regs is a pointer to an array of 32 words.
 *
 * The function works by walking backwards one instruction at a time, looking
 * for stack frame adjustments and stores of $ra to the stack. Once both of
 * these are are found, the function returns with this information.
 *
 * @returns The function will return 0 if it can't reliably find the caller. This will
 * happen if the function being analysed didn't adjust the stack pointer or
 * store $ra in the stack. It can also fail if the function being analysed uses
 * returns within branches.
 * 
 * note: name copied from PD.
 */
const u32 *crashGetParentStackFrame(const u32 *origptr, const u32 *minaddr, const u32 *origsp, u32 *regs)
{
    const u32 *sp = origsp;
    const u32 *addr;
    u32 sp_found = 0; // v0
    u32 ra_found = 0; // t0
    s32 sw_reg;
    
    // Holds value of address while iterating, but also reused
    // to iterate while loop at start of method.
    u32 addrval;
    s16 value;    
    
    // Do not remove the following trailing backslash. The while condition
    // needs to be on the same line as previous, otherwise the build breaks.
    // Search for WHILE_ONE_LINE to see other places in code like this.
    //
    // Note: this also occurs in PD:
    // src/game/game_0b69d0.c (bd15d298664e1a22cd31886cf87bfc40ab6842e9)
    // line 382:    p = i; while (sllen < 4) {
    addrval = 0; \
    while(addrval < 32)
    {
        regs[addrval++] = 0;
    }

    // Walk backwards through the instructions
    for (addr = origptr; addr >= minaddr; addr--)
    {
        // no validation on pointer
        addrval = *addr;
        value = addrval & 0xffff;

        if ((addrval & MIPS_ADDIU_SP_SP_ANY_MASK) == MIPS_ADDIU_SP_SP_ANY)
        {
            // Found an addiu $sp, $sp, <amount> instruction, which adjusts the
			// stack pointer. These can exist near the start and end of any
			// function. The "add" at the start is done with a negative value
			// which increases the size of the stack, as the stack expands to
			// the left. This function is interested in these negative adds,
			// because it needs to reverse it and move the sp variable forward
			// to the next stack frame (the frame of the caller).
            sp_found = 1;

            if (value > 0)
            {
                // Found the addiu sp at the end of the function. It's pretty
				// rare to crash (or jump elsewhere) after restoring the sp,
				// so this situation is not supported by this function.

                break;
            }

            // Change sp to point to the caller's stack frame
            sp -= (value >> 2);

            if (ra_found)
            {
                break;
            }
        }
        else if ((addrval & MIPS_SW_SP_ANY_MASK) == MIPS_SW_SP_ANY)
        {
            // This looks for a store from $ra to the stack, so the value can
			// be read from the stack and used to find the caller's address.
            sw_reg = (addrval >> 16) & 0x1F;
            regs[sw_reg] = (u32)(sp + (value >> 2));

            if (sw_reg == MIPS_REG_SOURCE_BITS_RA)
            {
                ra_found = 1;
            }

            if (sp_found && ra_found)
            {
                // Found a jr $ra statement, which is a return. This will happen if
                // this loop has walked out of the current function and into the one
                // prior to it, so bail.

                // It can also happen if the function has return statements within
                // branches, but handling these correctly would involve a lot of
                // complexity so that's unsupported. Because of this, this function
                // can end the backtrace prematurely if it encounters a function
                // that does this.

                break;
            }
        }
        else if (addrval == MIPS_JR_RA)
        {
            break;
        }
    }

    if (sp_found && ra_found)
    {
        return sp;
    }

    return 0;
}

/**
 * 5DE0    700051E0
 *     V0=TRUE if opcode that set RA A0 was a JAL or JALR type within bounds (70000450,70020D90)
 *     accepts: A0=p->70-mapped TLB function, presumably from RA
 */
s32 crashIsReturnAddress(u32 *instruction)
{
    u32 prevop;

    if ((((s32) instruction & 3) == 0) && ((u32) instruction >= (u32) &_codeSegmentStart) && ((u32) &_codeSegmentEnd >= (u32) instruction))
    {
        prevop = instruction[-2];
        if ((prevop & 0xFC00003C) == 9)
        {
            return 1;
        }
        if ((prevop & 0xFC000000) == 0xC000000)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * 5E58    70005258
 *     V0= strlen(A0); used exclusively for scanning ind.rea.buf
 *     accepts: A0=p->string
 * 
 * Max length returned is 256.
 */
s32 indyStrlen(u8 *arg0)
{
    s32 count = 0;
    u8 c;

    for (c = *arg0++; c != '\0'; c = *arg0++)
    {
        count++;
        if (count > 255)
        {
            break;
        }
    }

    return count;
}

/**
 * 5E94    70005294
 *     V0= total size of one word, two strings at hardware A0
 *     accepts: A0=hardware address
 */
u8 *indyFileGetAddressSubsequentData(u8 *arg0)
{
    u32 returnAddress;

    romCopy(&g_indyReadBuffer, arg0, g_indyReadBuffer_LEN);
    
    g_indyCurrentReadBufferResourceId = (u32*)(*(s32*) &g_indyReadBuffer);
    g_indyReadBufferString1 = (u8*)&g_indyReadBuffer[4];
    g_indyReadBufferString2 = (u8 *) (
        indyStrlen(g_indyReadBufferString1)
        + (u32)g_indyReadBufferString1
        + 1);
    
    returnAddress = 
        indyStrlen(g_indyReadBufferString1) 
        + ((u32)arg0 + indyStrlen(g_indyReadBufferString2))
        + 6;

    if (returnAddress & 3)
    {
        returnAddress = ((returnAddress | 3) + 1);
    }

    return (u8 *)returnAddress;
}

/**
 * 5F40    70005340
 *     scan for and load resourceID A0 from indy.read.buf
 *     accepts: A0=resourceID
 */
s32 indyScanLoadResourceIdFromBuffer(u32 arg0)
{
    u32 *temp_v1;
    u8 *phi_s0 = (u8 *)0xE00004;
    u8 *v0;
    u32 a0 = arg0;
    u8 *phi_s3;

    phi_s3 = phi_s0;

    while (1)
    {
        v0 = indyFileGetAddressSubsequentData(phi_s0);

        temp_v1 = g_indyCurrentReadBufferResourceId;

        if (a0 < (u32)temp_v1)
        {
            break;
        }

        phi_s3 = phi_s0;

        if (temp_v1 == NULL)
        {
            return 0;
        }

        phi_s0 = v0;
    }

    indyFileGetAddressSubsequentData(phi_s3);

    return 1;
}

/**
 * 5FC8    700053C8
 *     V0= TRUE if valid indy.read.buf.resourceID    [matches 826475BE]
 */
u32 indyIsValidReadBufferResourceId(void)
{
    indyFileGetAddressSubsequentData((u8*)0xe00000);
    return ((u32)g_indyCurrentReadBufferResourceId ^ 0x826475be) == 0;
}

/**
 * 5FFC    700053FC
 *     unconditional return
 */
void indyRemoved01(void)
{
    return;
}

/**
 * 6004    70005404
 *     unconditional return
 */
void indyRemoved02(void)
{
    return;
}

/**
 * 600C    7000540C
 *     unconditional return
 */
void indyPrintReadBufferResourceId(void)
{
    #ifdef DEBUG
    osSyncPrintf("%08x",_g_indyCurrentReadBufferResourceId); //from pd beta
    #endif
    return;
}

/**
 * 6014    70005414
 *     V0= indy.read.buf.resourceID    [80063664]
 */
u32 * indyGetReadBufferResourceId(void)
{
    return g_indyCurrentReadBufferResourceId;
}

/**
 * 6020    70005420
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 * 
 * If sp is above 0x80000000U and tid is valid, returns g_StackPtrs2 entry.
 * Otherwise, if tid is valid, returns sp & 0xF0000000, bitwise OR'd
 * with the difference from g_StackPtrs2 entry (pointer value) to 
 * g_StackPtrs1 entry (pointer value).
 * Otherwise, returns null.
 * 
 * @param sp: address / address space
 * @param tid: index into g_StackPtrs2/3. Must be (1 <= tid <= STACK_POINTER_COUNT).
 */
void * crashGetStackEnd(u32 sp, u32 tid)
{
    void *localStackPointers1[STACK_POINTER_COUNT] = g_StackPtrs1;
    void *localStackPointers2[STACK_POINTER_COUNT] = g_StackPtrs2;
    void *p2;
    void *p1;

    if ((s32)tid <= (s32)0 || (u32)tid > (u32)STACK_POINTER_COUNT)
    {
        return NULL;
    }

    p1 = localStackPointers1[tid];
    p2 = localStackPointers2[tid];
    
    if (sp >= 0x80000000U)
    {
        return p2;
    }
    
    p2 = (void*)(
        (sp & 0xF0000000) | ((u32)p2 - (u32)p1)
        );
    return p2;
}

/**
 * 60E4    700054E4
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 * 
 * If sp is above 0x80000000U and tid is valid, returns g_StackPtrs3 entry.
 * Otherwise, if tid is valid, returns sp & 0xF0000000.
 * Otherwise, returns null.
 * 
 * @param sp: address / address space
 * @param tid: index into g_StackPtrs3. Must be (1 <= tid <= STACK_POINTER_COUNT).
 */
void * crashGetStackStart(u32 sp, u32 tid)
{
    void *localStackPointers3[STACK_POINTER_COUNT] = g_StackPtrs3;
    void *p;

    if ((s32)tid <= (s32)0 || (u32)tid > (u32)STACK_POINTER_COUNT)
    {
        return NULL;
    }

    p = localStackPointers3[tid];

    if (sp >= 0x80000000U)
    {
        return p;
    }

    p = (void*)(sp & 0xF0000000);
    return p;
}


