#include "ultra64.h"
#include "rsp.h"
#include "init.h"
#include "memp.h"
#include "deb.h"
#include "sched.h"
#include "PR/sptask.h"
#include "PR/ucode.h"

#define RSP_MEMP_BANK                   6
#define RSP_MEMP_ALLOC_SIZE_BYTES  0xA000

/**
 * Address 8008D370.
 */
u8 g_gfxDramStack[SP_DRAM_STACK_SIZE8];

/**
 * Address 8008D770.
 */
u8 g_gfxYieldBuf[OS_YIELD_GFX_DATA_SIZE];

/**
 * Address 8004E9E0.
 */
s32 g_gfxDebugEntryData = 0;

/**
 * Address 8004E9E4.
 */
s32 g_gfxMempAllocationEnd = 0;

/**
 * Address 8004E9E8.
 */
s32 g_gfxMempAllocationAddress = 0;

/**
 * Address 8004E9EC.
 */
s32 g_unused8004E9EC = 0;

/**
 * Address 8004E9F0.
 */
struct GfxInfo_s g_gfxTaskSettings[2] = 
{
    // 8004EA50
    {
        // next
        NULL,
        
        // state
        0,
        
        // flags
        0, 
        
        // framebuffer
        NULL,

        // list.t.type
        M_GFXTASK,
        
        // list.t.flags
        OS_TASK_DP_WAIT,
        
        // list.t.ucode_boot
        NULL,
        
        // list.t.ucode_boot_size
        0,
        
        // list.t.ucode
        NULL,
        
        // list.t.ucode_size
        SP_UCODE_SIZE,
        
        // list.t.ucode_data
        NULL,
        
        // list.t.ucode_data_size
        SP_UCODE_DATA_SIZE,
        
        // list.t.dram_stack
        &g_gfxDramStack,
        
        // list.t.dram_stack_size
        SP_DRAM_STACK_SIZE8,
        
        // list.t.output_buff
        NULL,
        
        // list.t.output_buff_size
        0,
        
        // list.t.data_ptr
        NULL,
        
        // list.t.data_size
        0,
        
        // list.t.yield_data_ptr
        NULL,
        
        // list.t.yield_data_size
        0,
        
        // msgQ
        NULL, 
        
        // msg
        NULL,
        
        // cfb (pointer)
        0,
        
        // unk5C
        0
    },

    // 8004EAB0
    {
        // next
        NULL,
        
        // state
        0,
        
        // flags
        0, 
        
        // framebuffer
        NULL,

        // list.t.type
        M_GFXTASK,
        
        // list.t.flags
        OS_TASK_DP_WAIT,
        
        // list.t.ucode_boot
        NULL,
        
        // list.t.ucode_boot_size
        0,
        
        // list.t.ucode
        NULL,
        
        // list.t.ucode_size
        SP_UCODE_SIZE,
        
        // list.t.ucode_data
        NULL,
        
        // list.t.ucode_data_size
        SP_UCODE_DATA_SIZE,
        
        // list.t.dram_stack
        &g_gfxDramStack,
        
        // list.t.dram_stack_size
        SP_DRAM_STACK_SIZE8,
        
        // list.t.output_buff
        NULL,
        
        // list.t.output_buff_size
        0,
        
        // list.t.data_ptr
        NULL,
        
        // list.t.data_size
        0,
        
        // list.t.yield_data_ptr
        NULL,
        
        // list.t.yield_data_size
        0,
        
        // msgQ
        NULL, 
        
        // msg
        NULL,
        
        // cfb (pointer)
        0,
        
        // unk5C
        0
    },
};

/**
 * Address 8004EAB0.
 */
struct GfxInfo_s **g_gfxTaskSettingsList = &g_gfxTaskSettings;

extern long long int rspbootTextStart[];
extern long long int gsp3DTextStart[];
extern long long int gsp3DDataStart[];

void rspInitDebugNoticeList(void)
{
    debTryAdd(&g_gfxDebugEntryData, "rsp_c_debug");
}

void rspAllocateBuffers(void)
{
    g_gfxMempAllocationAddress = mempAllocBytesInBank(RSP_MEMP_ALLOC_SIZE_BYTES, RSP_MEMP_BANK);
    g_gfxMempAllocationEnd = g_gfxMempAllocationAddress + RSP_MEMP_ALLOC_SIZE_BYTES;
}

/**
 * Has similarities to:
 * createGfxTask from n64devkit\ultra\usr\src\pr\demos_old\simple\gfx.c
 * gfxTaskStart from n64devkit\ultra\usr\src\pr\demos_old\nnsample2\graphic.c
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 */
#ifdef NONMATCHING
void rspGfxTaskStart(Gfx *firstGdl, Gfx *gdl, s32 arg2, OSMesg rspReplyMsg)
{
    struct GfxInfo_s *temp_s0 ;
    OSTask_t *t;

    // why does g_gfxTaskSettingsList prefer a2 over v1?
    temp_s0 = ((struct GfxInfo_s *)g_gfxTaskSettingsList);
    t = &((struct GfxInfo_s *)g_gfxTaskSettingsList)->task.list.t; // addiu	v0,s0,16

    // temp or t?
    temp_s0->task.list.t.ucode_boot = rspbootTextStart;
    //t->ucode_boot = (u64*)rspbootTextStart;
    
    // u64 pointers, cast to x32 to avoid (sra _,_,0x3)
    // temp or t?
    temp_s0->task.list.t.ucode_boot_size = ((s32)gsp3DTextStart - (s32)rspbootTextStart);
    //t->ucode_boot_size = ((s32)gsp3DTextStart - (s32)rspbootTextStart);
    
    // t->type = M_GFXTASK, set in bss constructor
    // t->flags = OS_TASK_DP_WAIT, set in bss constructor
    
    // Why is the second gsp3DTextStart optimized out?
    // temp or t?
    //temp_s0->task.list.t.ucode = (u64*)gsp3DTextStart;
    t->ucode = (u64*)gsp3DTextStart;
    
    // temp or t?
    //temp_s0->task.list.t.ucode_data = (u64*)gsp3DDataStart;
    t->ucode_data = (u64*)gsp3DDataStart;

    // t->ucode_data_size = SP_UCODE_DATA_SIZE, set in bss constructor
    // t->dram_stack = &g_gfxDramStack, set in bss constructor
    // t->dram_stack_size = SP_DRAM_STACK_SIZE8, set in bss constructor
    
    t->output_buff =  g_gfxMempAllocationAddress;
    t->output_buff_size =  g_gfxMempAllocationEnd;
    t->data_ptr = (u64 *) firstGdl;
    t->data_size = (s32) ((gdl - firstGdl) * sizeof (Gfx)); // u64 pointers, generates sra	t3,t2,0x3
    t->yield_data_ptr = &g_gfxYieldBuf;
    t->yield_data_size = OS_YIELD_GFX_DATA_SIZE;

    temp_s0->task.next = 0;
    temp_s0->task.flags = (OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP | OS_SC_LAST_TASK | OS_SC_SWAPBUFFER);

    /* reply to when finished */
    temp_s0->task.msgQ = &gfxFrameMsgQ;

    /* reply with this message */
    temp_s0->task.msg = rspReplyMsg;

    temp_s0->task.framebuffer = (void *) ((struct GfxInfo_s *)g_gfxTaskSettingsList)->cfb;

    osWritebackDCacheAll();

    /* start graphic task */
    osSendMesg(sched_cmdQ, (OSMesg)temp_s0, OS_MESG_BLOCK);
    
    // Not sure this is right, but codegen uses two xor ... not sure what this is doing.
    g_gfxTaskSettingsList[0][0].task.next = (s32) ((s32)&g_gfxTaskSettingsList ^ (s32) &g_gfxTaskSettings[0] ^ (s32) &g_gfxTaskSettings[1]);
}
#else
GLOBAL_ASM(
.text
glabel rspGfxTaskStart
/* 104948 7F0CFE18 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 10494C 7F0CFE1C 3C038005 */  lui   $v1, %hi(g_gfxTaskSettingsList)
/* 104950 7F0CFE20 2463EAB0 */  addiu $v1, %lo(g_gfxTaskSettingsList) # addiu $v1, $v1, -0x1550
/* 104954 7F0CFE24 AFB00018 */  sw    $s0, 0x18($sp)
/* 104958 7F0CFE28 8C700000 */  lw    $s0, ($v1)
/* 10495C 7F0CFE2C 3C028002 */  lui   $v0, %hi(rspbootTextStart)
/* 104960 7F0CFE30 3C0E8002 */  lui   $t6, %hi(gsp3DTextStart) 
/* 104964 7F0CFE34 24420D90 */  addiu $v0, %lo(rspbootTextStart) # addiu $v0, $v0, 0xd90
/* 104968 7F0CFE38 25CE0E60 */  addiu $t6, %lo(gsp3DTextStart) # addiu $t6, $t6, 0xe60
/* 10496C 7F0CFE3C AFBF001C */  sw    $ra, 0x1c($sp)
/* 104970 7F0CFE40 AFA60028 */  sw    $a2, 0x28($sp)
/* 104974 7F0CFE44 01C27823 */  subu  $t7, $t6, $v0
/* 104978 7F0CFE48 AE020018 */  sw    $v0, 0x18($s0)
/* 10497C 7F0CFE4C 3C188002 */  lui   $t8, %hi(gsp3DTextStart) 
/* 104980 7F0CFE50 3C198006 */  lui   $t9, %hi(gsp3DDataStart) 
/* 104984 7F0CFE54 AE0F001C */  sw    $t7, 0x1c($s0)
/* 104988 7F0CFE58 26020010 */  addiu $v0, $s0, 0x10
/* 10498C 7F0CFE5C 27180E60 */  addiu $t8, %lo(gsp3DTextStart) # addiu $t8, $t8, 0xe60
/* 104990 7F0CFE60 2739C820 */  addiu $t9, %lo(gsp3DDataStart) # addiu $t9, $t9, -0x37e0
/* 104994 7F0CFE64 AC580010 */  sw    $t8, 0x10($v0)
/* 104998 7F0CFE68 AC590018 */  sw    $t9, 0x18($v0)
/* 10499C 7F0CFE6C 3C088005 */  lui   $t0, %hi(g_gfxMempAllocationAddress) 
/* 1049A0 7F0CFE70 8D08E9E8 */  lw    $t0, %lo(g_gfxMempAllocationAddress)($t0)
/* 1049A4 7F0CFE74 3C098005 */  lui   $t1, %hi(g_gfxMempAllocationEnd) 
/* 1049A8 7F0CFE78 00A45023 */  subu  $t2, $a1, $a0
/* 1049AC 7F0CFE7C AC480028 */  sw    $t0, 0x28($v0)
/* 1049B0 7F0CFE80 8D29E9E4 */  lw    $t1, %lo(g_gfxMempAllocationEnd)($t1)
/* 1049B4 7F0CFE84 000A58C3 */  sra   $t3, $t2, 3
/* 1049B8 7F0CFE88 3C0D8009 */  lui   $t5, %hi(g_gfxYieldBuf) 
/* 1049BC 7F0CFE8C 000B60C0 */  sll   $t4, $t3, 3
/* 1049C0 7F0CFE90 25ADD770 */  addiu $t5, %lo(g_gfxYieldBuf) # addiu $t5, $t5, -0x2890
/* 1049C4 7F0CFE94 240E0BA0 */  li    $t6, 2976
/* 1049C8 7F0CFE98 AC440030 */  sw    $a0, 0x30($v0)
/* 1049CC 7F0CFE9C AC4C0034 */  sw    $t4, 0x34($v0)
/* 1049D0 7F0CFEA0 AC4D0038 */  sw    $t5, 0x38($v0)
/* 1049D4 7F0CFEA4 AC4E003C */  sw    $t6, 0x3c($v0)
/* 1049D8 7F0CFEA8 AC49002C */  sw    $t1, 0x2c($v0)
/* 1049DC 7F0CFEAC 3C188006 */  lui   $t8, %hi(gfxFrameMsgQ) 
/* 1049E0 7F0CFEB0 240F0063 */  li    $t7, 99
/* 1049E4 7F0CFEB4 2718D9A0 */  addiu $t8, %lo(gfxFrameMsgQ) # addiu $t8, $t8, -0x2660
/* 1049E8 7F0CFEB8 AE000000 */  sw    $zero, ($s0)
/* 1049EC 7F0CFEBC AE0F0008 */  sw    $t7, 8($s0)
/* 1049F0 7F0CFEC0 AE180050 */  sw    $t8, 0x50($s0)
/* 1049F4 7F0CFEC4 AE070054 */  sw    $a3, 0x54($s0)
/* 1049F8 7F0CFEC8 8C790000 */  lw    $t9, ($v1)
/* 1049FC 7F0CFECC 8F280058 */  lw    $t0, 0x58($t9)
/* 104A00 7F0CFED0 0C0034C8 */  jal   osWritebackDCacheAll
/* 104A04 7F0CFED4 AE08000C */   sw    $t0, 0xc($s0)
/* 104A08 7F0CFED8 3C048006 */  lui   $a0, %hi(sched_cmdQ)
/* 104A0C 7F0CFEDC 8C84DA38 */  lw    $a0, %lo(sched_cmdQ)($a0)
/* 104A10 7F0CFEE0 02002825 */  move  $a1, $s0
/* 104A14 7F0CFEE4 0C0037C4 */  jal   osSendMesg
/* 104A18 7F0CFEE8 24060001 */   li    $a2, 1
/* 104A1C 7F0CFEEC 3C028005 */  lui   $v0, %hi(g_gfxTaskSettingsList)
/* 104A20 7F0CFEF0 2442EAB0 */  addiu $v0, %lo(g_gfxTaskSettingsList) # addiu $v0, $v0, -0x1550
/* 104A24 7F0CFEF4 8C490000 */  lw    $t1, ($v0)
/* 104A28 7F0CFEF8 3C0A8005 */  lui   $t2, %hi(g_gfxTaskSettings) 
/* 104A2C 7F0CFEFC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 104A30 7F0CFF00 254AE9F0 */  addiu $t2, %lo(g_gfxTaskSettings) # addiu $t2, $t2, -0x1610
/* 104A34 7F0CFF04 3C0C8005 */  lui   $t4, %hi(g_gfxTaskSettings) 
/* 104A38 7F0CFF08 258CEA50 */  addiu $t4, %lo(g_gfxTaskSettings+96) # addiu $t4, $t4, -0x15b0
/* 104A3C 7F0CFF0C 012A5826 */  xor   $t3, $t1, $t2
/* 104A40 7F0CFF10 016C6826 */  xor   $t5, $t3, $t4
/* 104A44 7F0CFF14 8FB00018 */  lw    $s0, 0x18($sp)
/* 104A48 7F0CFF18 AC4D0000 */  sw    $t5, ($v0)
/* 104A4C 7F0CFF1C 03E00008 */  jr    $ra
/* 104A50 7F0CFF20 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif




