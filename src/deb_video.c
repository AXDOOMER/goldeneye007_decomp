#include "ultra64.h"
#include "libultra/libultra_internal.h"
#include "PR/os_thread.h"
#include "bondgame.h"
#include "deb_video.h"
#include "tlb_manage.h"
#include "deb_print.h"
#include "ramrom.h"
#include "PR/R4300.h"


/**
 * @file deb_video.c
 * This file contains code to handle tlb paging. 
 * 
 * I should probably be renamed...
 */

/**
 * Size in bytes.
 */
#define INDY_READ_BUFFER_LEN 0x60

/**
 * Copied from n64devkit\ultra\usr\src\pr\demos\fault\fault.c
 */
#define MSG_FAULT	0x10

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

//bss
char tlbthread[0x6B0];
char tlbStack[0x2300];
OSMesgQueue tlbMesgQ;
u32 tlbMesgBuf;
OSThread *ptr_tlbthread_maybe;
u32 dword_CODE_bss_80063660;
u32 *current_indy_read_buf_resourceID;
u8 *ptr_indy_read_buf_string1;
u8 *ptr_indy_read_buf_string2;
char indy_read_buffer[INDY_READ_BUFFER_LEN];

/**
 * 5AE0	70004EE0
 */
void init_tlb(void) {
    deboutInitBuffers();
    osCreateMesgQueue(&tlbMesgQ, &tlbMesgBuf, 1);
    osCreateThread(&tlbthread, 5, &tlbproc, 0, &tlbStack, 0x28);
    osStartThread(&tlbthread);
}

/**
 * 5B54	70004F54
 * 
 * @param arg0 Unused.
 */
#ifdef NONMATCHING
void tlbproc(s32 arg0)
{
    OSMesg msg = 0;
    OSIntMask startingInterruptMask;
    OSThread *faultedThread;
    OSThread **ptr_ptr_tlbthread = &ptr_tlbthread_maybe;

    osSetEventMesg(OS_EVENT_FAULT, &tlbMesgQ, (OSMesg)MSG_FAULT);
    dword_CODE_bss_80063660 = 0;

    while (1)
    {
        osRecvMesg(&tlbMesgQ, &msg, OS_MESG_BLOCK);
        startingInterruptMask = osSetIntMask(OS_IM_NONE);
        faultedThread = __osGetCurrFaultedThread();
        *ptr_ptr_tlbthread = faultedThread;

        if (faultedThread == NULL)
        {
            continue;
        }
        else if (((faultedThread->context.cause & CAUSE_EXCMASK) == EXC_RMISS) && ((faultedThread->context.badvaddr & 0xFFC00000) == (u32)0x7F000000))
        {
            tlbmanageTranslateLoadRomFromTlbAddress((*ptr_ptr_tlbthread)->context.badvaddr);
            (*ptr_ptr_tlbthread)->state = (u16)0xA;
            (*ptr_ptr_tlbthread)->flags = (u16)0;

            __osEnqueueThread(&__osRunQueue, *ptr_ptr_tlbthread);
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
glabel tlbproc
/* 005B54 70004F54 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 005B58 70004F58 AFB70030 */  sw    $s7, 0x30($sp)
/* 005B5C 70004F5C 3C178006 */  lui   $s7, %hi(tlbMesgQ) 
/* 005B60 70004F60 26F73640 */  addiu $s7, %lo(tlbMesgQ) # addiu $s7, $s7, 0x3640
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
/* 005BE0 70004FE0 3C018006 */  lui   $at, %hi(ptr_tlbthread_maybe)
/* 005BE4 70004FE4 1040FFF6 */  beqz  $v0, .L70004FC0
/* 005BE8 70004FE8 AC22365C */   sw    $v0, %lo(ptr_tlbthread_maybe)($at)
/* 005BEC 70004FEC 8C4E0120 */  lw    $t6, 0x120($v0)
/* 005BF0 70004FF0 3C088006 */  lui   $t0, %hi(ptr_tlbthread_maybe) 
/* 005BF4 70004FF4 31CF007C */  andi  $t7, $t6, 0x7c
/* 005BF8 70004FF8 164F0018 */  bne   $s2, $t7, .L7000505C
/* 005BFC 70004FFC 00000000 */   nop   
/* 005C00 70005000 8C580124 */  lw    $t8, 0x124($v0)
/* 005C04 70005004 0314C824 */  and   $t9, $t8, $s4
/* 005C08 70005008 16790014 */  bne   $s3, $t9, .L7000505C
/* 005C0C 7000500C 00000000 */   nop   
/* 005C10 70005010 8D08365C */  lw    $t0, %lo(ptr_tlbthread_maybe)($t0)
/* 005C14 70005014 0C000676 */  jal   tlbmanageTranslateLoadRomFromTlbAddress
/* 005C18 70005018 8D040124 */   lw    $a0, 0x124($t0)
/* 005C1C 7000501C 3C098006 */  lui   $t1, %hi(ptr_tlbthread_maybe) 
/* 005C20 70005020 8D29365C */  lw    $t1, %lo(ptr_tlbthread_maybe)($t1)
/* 005C24 70005024 3C0A8006 */  lui   $t2, %hi(ptr_tlbthread_maybe) 
/* 005C28 70005028 3C058006 */  lui   $a1, %hi(ptr_tlbthread_maybe)
/* 005C2C 7000502C A5350010 */  sh    $s5, 0x10($t1)
/* 005C30 70005030 8D4A365C */  lw    $t2, %lo(ptr_tlbthread_maybe)($t2)
/* 005C34 70005034 02C02025 */  move  $a0, $s6
/* 005C38 70005038 A5400012 */  sh    $zero, 0x12($t2)
/* 005C3C 7000503C 0C00422B */  jal   __osEnqueueThread
/* 005C40 70005040 8CA5365C */   lw    $a1, %lo(ptr_tlbthread_maybe)($a1)
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
 * 5CAC	700050AC
 *     V0= SP, A3=SP usage within function range (A1,A0) with initial SP A2
 *     accepts: A0=p->opcode.cur, A1=p->opcode.start, A2=SP w/i function, A3=p->register buffer
 * 
 * @param startAddress Starting address to get stack pointer for. Will decrement this value for search.
 * @param minAddress Low address cutoff. Will continue searching while the current address is higher than this.
 * @param startStackPointer Starting stack pointer address.
 * @param buffer Register buffer. Tracks which registers have been saved on the stack.
 * 
 * @returns Stack pointer, accounting for adjustments since @param startAddress, as long as
 * instructions for restoring the stack and `ra` have been found, otherwise NULL.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: yes
 * - identical registers: fail
 */
#ifdef NONMATCHING
u32 * debug_related_8(const u32 *startAddress, const u32 *minAddress, const u32 *startStackPointer, u32 *buffer)
{
    // I don't think this is (u16*). There are two places where
    // an offset is calculated using ssl 0x2 which implies this is
    // a u32 pointer, but I couldn't get that to match.
    const u16 *sp = (u16*)startStackPointer;
    u32 sp_found = 0; // v0
    u32 ra_found = 0; // t0
    s32 i;
    const u32 *addr;
    u32 addrval;
    
    // Do not remove the following trailing backslash. The while condition
    // needs to be on the same line as previous, otherwise the build breaks.
    // Search for WHILE_ONE_LINE to see other places in code like this.
    //
    // Note: this also occurs in PD:
    // src/game/game_0b69d0.c (bd15d298664e1a22cd31886cf87bfc40ab6842e9)
    // line 382:    p = i; while (sllen < 4) {
    i = 0; \
    while(i < 32)
    {
        buffer[i++] = 0;
    }

    for (addr = startAddress; addr >= minAddress; addr--) // else bnez L700051B8
    {
        // no validation on pointer
        addrval = *addr;

        // Dereferencing addr again after this point (in the for loop) will
        // insert an extra "move" instruction, but it might help explain why
        // addrval is being lw into 'a2' instead of 't1'.
        // (Currently addrval is being loaded into 'a2'.)
        // Also, dereferencing it further changes the instructions much
        // more (more mismatch from target).
        // 
        // adding this line here:
        //     if (*addr);
        // generates:
        // 238:   8c890000   lw     t1,0(a0)   # t1 matches
        // 23c:   2484fffc   addiu  a0,a0,-4   # addr--
        // 240:   0085082b   sltu   at,a0,a1
        // 244:   012b7824   and    t7,t1,t3   # if ((addrval & MIPS_ADDIU_SP_SP_ANY_MASK) == MIPS_ADDIU_SP_SP_ANY)
        // 248:   154f000b   bne    t2,t7,278  # jump to second if (first else if) in for loop
        // 24c:   01203025   move   a2,t1      # shouldnt be here

        //L7000511C:
        if ((addrval & MIPS_ADDIU_SP_SP_ANY_MASK) == MIPS_ADDIU_SP_SP_ANY)
        {
            sp_found = 1;

            if ((s16)addrval > 0)
            {
                break;
            }

            sp -= (((s16)addrval >> 2) << 1);
            
            if (ra_found) // beqz  $t0, .L700051B0
            {
                break;// b     .L700051B8
            }
        }
        //L70005158:
        else if ((addrval & MIPS_SW_SP_ANY_MASK) == MIPS_SW_SP_ANY)
        {
            u32 sw_reg = (addrval >> 0x10) & 0x1F;

            buffer[sw_reg] = sp + (((s16)addrval >> 2) << 1);
            // alternatively, get address of indexing into array:
            //buffer[sw_reg] = &sp[(((s16)addrval >> 2) << 1)];

            if (sw_reg == MIPS_REG_SOURCE_BITS_RA)
            {
                ra_found = 1;
            }

            //L70005190:
            if (sp_found && ra_found)
            {
                break;
            }
        }
        //L700051A8:
        else if (addrval == MIPS_JR_RA)
        {
            break;
        }
    }

    //L700051B8:
    if (sp_found && ra_found)
    {
        return (u32 *)sp;
    }

    return NULL;
}
#else
GLOBAL_ASM(
.text
glabel debug_related_8
/* 005CAC 700050AC 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 005CB0 700050B0 AFA40010 */  sw    $a0, 0x10($sp)
/* 005CB4 700050B4 AFB1000C */  sw    $s1, 0xc($sp)
/* 005CB8 700050B8 AFB00008 */  sw    $s0, 8($sp)
/* 005CBC 700050BC 00C01825 */  move  $v1, $a2
/* 005CC0 700050C0 00001025 */  move  $v0, $zero
/* 005CC4 700050C4 00004025 */  move  $t0, $zero
/* 005CC8 700050C8 24040020 */  li    $a0, 32
/* 005CCC 700050CC 00004825 */  move  $t1, $zero
/* 005CD0 700050D0 00E05025 */  move  $t2, $a3
.L700050D4:
/* 005CD4 700050D4 25290004 */  addiu $t1, $t1, 4
/* 005CD8 700050D8 AD400000 */  sw    $zero, ($t2)
/* 005CDC 700050DC AD400004 */  sw    $zero, 4($t2)
/* 005CE0 700050E0 AD400008 */  sw    $zero, 8($t2)
/* 005CE4 700050E4 AD40000C */  sw    $zero, 0xc($t2)
/* 005CE8 700050E8 1524FFFA */  bne   $t1, $a0, .L700050D4
/* 005CEC 700050EC 254A0010 */   addiu $t2, $t2, 0x10
/* 005CF0 700050F0 8FA40010 */  lw    $a0, 0x10($sp)
/* 005CF4 700050F4 3C1103E0 */  lui   $s1, (0x03E00008 >> 16) # lui $s1, 0x3e0
/* 005CF8 700050F8 36310008 */  ori   $s1, (0x03E00008 & 0xFFFF) # ori $s1, $s1, 8
/* 005CFC 700050FC 0085082B */  sltu  $at, $a0, $a1
/* 005D00 70005100 1420002D */  bnez  $at, .L700051B8
/* 005D04 70005104 2410001F */   li    $s0, 31
/* 005D08 70005108 3C0DFFE0 */  lui   $t5, 0xffe0
/* 005D0C 7000510C 3C0CAFA0 */  lui   $t4, 0xafa0
/* 005D10 70005110 3C0BFFFF */  lui   $t3, 0xffff
/* 005D14 70005114 3C0A27BD */  lui   $t2, 0x27bd
/* 005D18 70005118 8C890000 */  lw    $t1, ($a0)
.L7000511C:
/* 005D1C 7000511C 2484FFFC */  addiu $a0, $a0, -4
/* 005D20 70005120 0085082B */  sltu  $at, $a0, $a1
/* 005D24 70005124 012B7824 */  and   $t7, $t1, $t3
/* 005D28 70005128 154F000B */  bne   $t2, $t7, .L70005158
/* 005D2C 7000512C 012DC024 */   and   $t8, $t1, $t5
/* 005D30 70005130 0009C400 */  sll   $t8, $t1, 0x10
/* 005D34 70005134 0018CC03 */  sra   $t9, $t8, 0x10
/* 005D38 70005138 1F20001F */  bgtz  $t9, .L700051B8
/* 005D3C 7000513C 24020001 */   li    $v0, 1
/* 005D40 70005140 00197083 */  sra   $t6, $t9, 2
/* 005D44 70005144 000E7880 */  sll   $t7, $t6, 2
/* 005D48 70005148 11000019 */  beqz  $t0, .L700051B0
/* 005D4C 7000514C 006F1823 */   subu  $v1, $v1, $t7
/* 005D50 70005150 10000019 */  b     .L700051B8
/* 005D54 70005154 00000000 */   nop   
.L70005158:
/* 005D58 70005158 15980013 */  bne   $t4, $t8, .L700051A8
/* 005D5C 7000515C 00093402 */   srl   $a2, $t1, 0x10
/* 005D60 70005160 30D9001F */  andi  $t9, $a2, 0x1f
/* 005D64 70005164 00097C00 */  sll   $t7, $t1, 0x10
/* 005D68 70005168 000FC403 */  sra   $t8, $t7, 0x10
/* 005D6C 7000516C 03203025 */  move  $a2, $t9
/* 005D70 70005170 0018C883 */  sra   $t9, $t8, 2
/* 005D74 70005174 00197080 */  sll   $t6, $t9, 2
/* 005D78 70005178 0006C080 */  sll   $t8, $a2, 2
/* 005D7C 7000517C 00F8C821 */  addu  $t9, $a3, $t8
/* 005D80 70005180 01C37821 */  addu  $t7, $t6, $v1
/* 005D84 70005184 16060002 */  bne   $s0, $a2, .L70005190
/* 005D88 70005188 AF2F0000 */   sw    $t7, ($t9)
/* 005D8C 7000518C 24080001 */  li    $t0, 1
.L70005190:
/* 005D90 70005190 10400007 */  beqz  $v0, .L700051B0
/* 005D94 70005194 00000000 */   nop   
/* 005D98 70005198 11000005 */  beqz  $t0, .L700051B0
/* 005D9C 7000519C 00000000 */   nop   
/* 005DA0 700051A0 10000005 */  b     .L700051B8
/* 005DA4 700051A4 00000000 */   nop   
.L700051A8:
/* 005DA8 700051A8 11310003 */  beq   $t1, $s1, .L700051B8
/* 005DAC 700051AC 00000000 */   nop   
.L700051B0:
/* 005DB0 700051B0 5020FFDA */  beql  $at, $zero, .L7000511C
/* 005DB4 700051B4 8C890000 */   lw    $t1, ($a0)
.L700051B8:
/* 005DB8 700051B8 10400005 */  beqz  $v0, .L700051D0
/* 005DBC 700051BC 8FB00008 */   lw    $s0, 8($sp)
/* 005DC0 700051C0 51000004 */  beql  $t0, $zero, .L700051D4
/* 005DC4 700051C4 00001025 */   move  $v0, $zero
/* 005DC8 700051C8 10000002 */  b     .L700051D4
/* 005DCC 700051CC 00601025 */   move  $v0, $v1
.L700051D0:
/* 005DD0 700051D0 00001025 */  move  $v0, $zero
.L700051D4:
/* 005DD4 700051D4 8FB1000C */  lw    $s1, 0xc($sp)
/* 005DD8 700051D8 03E00008 */  jr    $ra
/* 005DDC 700051DC 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif

/**
 * 5DE0	700051E0
 *     V0=TRUE if opcode that set RA A0 was a JAL or JALR type within bounds (70000450,70020D90)
 *     accepts: A0=p->70-mapped TLB function, presumably from RA
 */
s32 tlbIsJumpOpInCodeSeg(u32 *currop)
{
    u32 prevop;

    if ((((s32) currop & 3) == 0) && ((u32) currop >= (u32) &_codeSegmentStart) && ((u32) &_codeSegmentEnd >= (u32) currop))
    {
        prevop = currop[-2];
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
 * 5E58	70005258
 *     V0= strlen(A0); used exclusively for scanning ind.rea.buf
 *     accepts: A0=p->string
 * 
 * Max length returned is 256.
 */
s32 return_strlen(u8 *arg0)
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
 * 5E94	70005294
 *     V0= total size of one word, two strings at hardware A0
 *     accepts: A0=hardware address
 */
u8 *indy_file_get_address_subsequent_data(u8 *arg0)
{
    u32 returnAddress;

    romCopy(&indy_read_buffer, arg0, INDY_READ_BUFFER_LEN);
    
    current_indy_read_buf_resourceID = *(s32*) &indy_read_buffer;
    ptr_indy_read_buf_string1 = &indy_read_buffer[4];
    ptr_indy_read_buf_string2 = (u8 *) (
        return_strlen(ptr_indy_read_buf_string1)
        + (u32)ptr_indy_read_buf_string1
        + 1);
    
    returnAddress = 
        return_strlen(ptr_indy_read_buf_string1) 
        + ((u32)arg0 + return_strlen(ptr_indy_read_buf_string2))
        + 6;

    if (returnAddress & 3)
    {
        returnAddress = ((returnAddress | 3) + 1);
    }

    return (u8 *)returnAddress;
}



/**
 * 5F40	70005340
 *     scan for and load resourceID A0 from indy.read.buf
 *     accepts: A0=resourceID
 */
s32 scan_load_resourceID_from_indy_read_buf(u32 arg0)
{
    u32 *temp_v1;
    u8 *phi_s0 = (u8 *)0xE00004;
    u8 *v0;
    u32 a0 = arg0;
    u8 *phi_s3;

    phi_s3 = phi_s0;

    while (1)
    {
        v0 = indy_file_get_address_subsequent_data(phi_s0);

        temp_v1 = current_indy_read_buf_resourceID;

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

    indy_file_get_address_subsequent_data(phi_s3);

    return 1;
}

/**
 * 5FC8	700053C8
 *     V0= TRUE if valid indy.read.buf.resourceID	[matches 826475BE]
 */
u32 is_valid_indy_read_buf_resourceID(void)
{
    indy_file_get_address_subsequent_data((u8*)0xe00000);
    return ((u32)current_indy_read_buf_resourceID ^ 0x826475be) == 0;
}

/**
 * 5FFC	700053FC
 *     unconditional return
 */
void debug_indy_stub(void) {
    return;
}

/**
 * 6004	70005404
 *     unconditional return
 */
void debug_indy_stub_0(void) {
    return;
}

/**
 * 600C	7000540C
 *     unconditional return
 */
void debug_indy_stub_1(void) {
    return;
}

/**
 * 6014	70005414
 *     V0= indy.read.buf.resourceID	[80063664]
 */
u32 * return_indy_read_buf_resourceID(void) {
  return current_indy_read_buf_resourceID;
}

/**
 * 6020	70005420
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 * 
 * If arg0 is above 0x80000000U and arg1 is valid, returns g_StackPtrs2 entry.
 * Otherwise, if arg1 is valid, returns arg0 & 0xF0000000, bitwise OR'd
 * with the difference from g_StackPtrs2 entry (pointer value) to 
 * g_StackPtrs1 entry (pointer value).
 * Otherwise, returns null.
 * 
 * @param arg0: address / address space
 * @param arg1: index into g_StackPtrs2/3. Must be (1 <= arg1 <= STACK_POINTER_COUNT).
 */
void * debug_sp_related_11(u32 arg0, u32 arg1)
{
    void *localStackPointers1[STACK_POINTER_COUNT] = g_StackPtrs1;
    void *localStackPointers2[STACK_POINTER_COUNT] = g_StackPtrs2;
    void *p2;
    void *p1;

    if ((s32)arg1 <= (s32)0 || (u32)arg1 > (u32)STACK_POINTER_COUNT)
    {
        return NULL;
    }

    p1 = localStackPointers1[arg1];
    p2 = localStackPointers2[arg1];
    
    if (arg0 >= 0x80000000U)
    {
        return p2;
    }
    
    p2 = (void*)(
        (arg0 & 0xF0000000) | ((u32)p2 - (u32)p1)
        );
    return p2;
}

/**
 * 60E4	700054E4
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 * 
 * If arg0 is above 0x80000000U and arg1 is valid, returns g_StackPtrs3 entry.
 * Otherwise, if arg1 is valid, returns arg0 & 0xF0000000.
 * Otherwise, returns null.
 * 
 * @param arg0: address / address space
 * @param arg1: index into g_StackPtrs3. Must be (1 <= arg1 <= STACK_POINTER_COUNT).
 */
void * debug_sp_related_12(u32 arg0, u32 arg1)
{
    void *localStackPointers3[STACK_POINTER_COUNT] = g_StackPtrs3;
    void *p;

    if ((s32)arg1 <= (s32)0 || (u32)arg1 > (u32)STACK_POINTER_COUNT)
    {
        return NULL;
    }

    p = localStackPointers3[arg1];

    if (arg0 >= 0x80000000U)
    {
        return p;
    }

    p = (void*)(arg0 & 0xF0000000);
    return p;
}


