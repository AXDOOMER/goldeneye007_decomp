#include <ultra64.h>
#include "libultra/os.h"
#include "init.h"
#include "sched.h"
#include "bondgame.h"
#include "deb_print.h"
#include "video.h"
#include "joy.h"

/**
 * @file sched.c
 * This file contains the scheduler. 
 * 
 * In particular, it:
 *   - is based on but modified by rare from code included in sdk
 *   - 
 *   - 
 */

#define VIDEO_MSG       666
#define RSP_DONE_MSG    667
#define RDP_DONE_MSG    668
#define PRE_NMI_MSG     669


#define OS_SC_DP                0x0001
#define OS_SC_SP                0x0002
#define OS_SC_YIELD             0x0010
#define OS_SC_YIELDED           0x0020


#define OS_SC_XBUS      (OS_SC_SP | OS_SC_DP)
#define OS_SC_DRAM      (OS_SC_SP | OS_SC_DP | OS_SC_DRAM_DLIST)
#define OS_SC_DP_XBUS   (OS_SC_SP)
#define OS_SC_DP_DRAM   (OS_SC_SP | OS_SC_DRAM_DLIST)
#define OS_SC_SP_XBUS   (OS_SC_DP)
#define OS_SC_SP_DRAM   (OS_SC_DP | OS_SC_DRAM_DLIST)



u32 stderr_unused = 0;
u32 stderr_enabled = 0;
u32 stderr_active = 0;
u32 stderr_permitted = 0;
u32 userCompareValue = 45000000;
u32 currentcount = 0;
u32 dp_busy = 0;
u32 dpCount = 0;
//800230b0
f32 something_with_osVI_0 = 0.0;
f32 something_with_osVI_4[2] = {1.0, 1.0};
f32 something_with_osVI_C[2] = {1.0, 1.0};
s32 something_with_osVI_14[2] = {0, 0};

u32 D_800230CC = 1;

OSSched sc;
//temporary until i get proper sized structs
OSScClient gfxClient[3];
//char gfxClient[0x18];

char target_for_counters_maybe[0x10];
OSViMode viModes[2];
OSViMode *viModePtrs[2];
s32 dword_CODE_bss_8005DBE8[2];

/**
 * 1570	70000970
 * A0-> stderr.activated	[80023098]; fry AT
 */
void activate_stderr(u32 flag)
{
	stderr_active = flag;
}

/**
 * 157C	7000097C
 * A0-> stderr.enable		[80023094]; fry AT
 */
void enable_stderr(u32 flag)
{
	stderr_enabled = flag;
}

/**
 * 1588	70000988
 * A0-> stderr.permitted	[8002309C]; fry AT
 */
void permit_stderr(u32 flag)
{
	stderr_permitted = flag;
}

/**
 * 1594	70000994
 * A0-> user.Compare		[800230A0]; fry AT
 */
void setUserCompareValue(u32 value)
{
	userCompareValue = value;
}

/**
 * 15A0	700009A0
 * test to display stderr and update Count
 */
void CheckDisplayErrorBuffer(u32 *buffer)
{
	if ((stderr_permitted && stderr_active) || stderr_enabled )
    {
		deboutDrawToBuffer(buffer);
		currentcount = osGetCount();
	}
}

/**
 * 15F8	700009F8
 * test to display stderr every 16th frame
 */

void CheckDisplayErrorBufferEvery16Frames(u32 framecount)
{
	if (!(framecount & 0xf))
    {
		if ((stderr_permitted && stderr_active) || stderr_enabled)
        {
			if (userCompareValue < (osGetCount() - currentcount))
            {
				deboutDrawToBuffer((u32*)cfb_16[0]);
				deboutDrawToBuffer((u32*)cfb_16[1]);
			}
		}
	}
}

/**
 * Not 100% on name, came from osInitialize's call to function
 * 1688	70000A88
 * store current Count to 800230A4
 */
void osCreateLog(void){
	currentcount=osGetCount();
}

/**
 * 16AC	70000AAC
 * (thread management)
 */
#ifdef NONMATCHING
// 175c:    lui     at,0x8006                        | 175c:    li      a0,4
// 1760:    li      a0,4                             | 1760:    move    a1,s1
// 1764:    sw      t3,0x880(at)                     r 1764:    sw      t3,4(t2)
// 1768:    lw      t4,0x30(t2)                      r 1768:    lw      v0,0(v1)
// 176c:    lui     at,0x8006                        | 176c:    li      a2,0x29b
// 1770:    move    a1,s1                            | 1770:    lw      t4,0x30(v0)
// 1774:    sw      t4,0x884(at)                     r 1774:    sw      t4,8(v0)
// 1778:    lw      t5,0x44(t2)                      r 1778:    lw      v0,0(v1)
// 177c:    lui     at,0x8006                        <
// 1780:    li      a2,0x29b                         | 177c:    lw      t5,0x44(v0)
// 1784:    jal     0xdc50                             1780:    jal     0xdc50
// 1788:    sw      t5,0x888(at)                     r 1784:    sw      t5,0xc(v0)
extern OSViMode *viMode;
void osCreateScheduler (OSSched * sc, void * stack, u8 mode, u32 numFields)
{
    sc->curRSPTask = 0;
    sc->curRDPTask = 0;
    sc->clientList = 0;
    sc->frameCount = 0;
    sc->audioListHead = 0;
    sc->gfxListHead = 0;
    sc->audioListTail = 0;
    sc->gfxListTail = 0;
    sc->retraceMsg.type = OS_SC_RETRACE_MSG;
    sc->prenmiMsg.type = 5; // OS_SC_PRE_NMI_MSG
    sc->thread = stack;
    osCreateMesgQueue(&sc->interruptQ, sc->intBuf, OS_SC_MAX_MESGS);
    osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, OS_SC_MAX_MESGS);
    osCreateViManager(OS_PRIORITY_VIMGR);

    viMode = &osViModeTable[mode];
    viMode->comRegs.ctrl = viMode->comRegs.hStart;
    viMode->comRegs.width = viMode->fldRegs[0].vStart;
    viMode->comRegs.burst = viMode->fldRegs[1].vStart;

    osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg)RSP_DONE_MSG); 
    osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg)RDP_DONE_MSG);
    osSetEventMesg(OS_EVENT_PRENMI, &sc->interruptQ, (OSMesg)PRE_NMI_MSG);
    osViSetEvent(&sc->interruptQ, (OSMesg)VIDEO_MSG, numFields);
    osCreateLog();
    osCreateThread(sc->thread, 2, &__scMain, sc, set_stack_entry(&sp_shed, 0x200), 0x1e);
    osStartThread(sc->thread);
}
#else
GLOBAL_ASM(
glabel osCreateScheduler
/* 0016AC 70000AAC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0016B0 70000AB0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0016B4 70000AB4 AFB10020 */  sw    $s1, 0x20($sp)
/* 0016B8 70000AB8 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0016BC 70000ABC AFA5002C */  sw    $a1, 0x2c($sp)
/* 0016C0 70000AC0 AFA60030 */  sw    $a2, 0x30($sp)
/* 0016C4 70000AC4 AFA70034 */  sw    $a3, 0x34($sp)
/* 0016C8 70000AC8 240E0001 */  li    $t6, 1
/* 0016CC 70000ACC 240F0005 */  li    $t7, 5
/* 0016D0 70000AD0 AC8000C8 */  sw    $zero, 0xc8($a0)
/* 0016D4 70000AD4 AC8000CC */  sw    $zero, 0xcc($a0)
/* 0016D8 70000AD8 AC8000B4 */  sw    $zero, 0xb4($a0)
/* 0016DC 70000ADC AC8000D0 */  sw    $zero, 0xd0($a0)
/* 0016E0 70000AE0 AC8000B8 */  sw    $zero, 0xb8($a0)
/* 0016E4 70000AE4 AC8000BC */  sw    $zero, 0xbc($a0)
/* 0016E8 70000AE8 AC8000C0 */  sw    $zero, 0xc0($a0)
/* 0016EC 70000AEC AC8000C4 */  sw    $zero, 0xc4($a0)
/* 0016F0 70000AF0 A48E0000 */  sh    $t6, ($a0)
/* 0016F4 70000AF4 A48F0020 */  sh    $t7, 0x20($a0)
/* 0016F8 70000AF8 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0016FC 70000AFC 00808025 */  move  $s0, $a0
/* 001700 70000B00 24910040 */  addiu $s1, $a0, 0x40
/* 001704 70000B04 AC9800B0 */  sw    $t8, 0xb0($a0)
/* 001708 70000B08 02202025 */  move  $a0, $s1
/* 00170C 70000B0C 26050058 */  addiu $a1, $s0, 0x58
/* 001710 70000B10 0C0035B4 */  jal   osCreateMesgQueue
/* 001714 70000B14 24060008 */   li    $a2, 8
/* 001718 70000B18 26040078 */  addiu $a0, $s0, 0x78
/* 00171C 70000B1C 26050090 */  addiu $a1, $s0, 0x90
/* 001720 70000B20 0C0035B4 */  jal   osCreateMesgQueue
/* 001724 70000B24 24060008 */   li    $a2, 8
/* 001728 70000B28 0C00363C */  jal   osCreateViManager
/* 00172C 70000B2C 240400FE */   li    $a0, 254
/* 001730 70000B30 93B90033 */  lbu   $t9, 0x33($sp)
/* 001734 70000B34 3C098002 */  lui   $t1, %hi(osViModeTable) 
/* 001738 70000B38 3C038006 */  lui   $v1, %hi(viMode)
/* 00173C 70000B3C 00194080 */  sll   $t0, $t9, 2
/* 001740 70000B40 01194021 */  addu  $t0, $t0, $t9
/* 001744 70000B44 00084100 */  sll   $t0, $t0, 4
/* 001748 70000B48 252969C0 */  addiu $t1, %lo(osViModeTable) # addiu $t1, $t1, 0x69c0
/* 00174C 70000B4C 2463087C */  addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
/* 001750 70000B50 01095021 */  addu  $t2, $t0, $t1
/* 001754 70000B54 AC6A0000 */  sw    $t2, ($v1)
/* 001758 70000B58 8D4B001C */  lw    $t3, 0x1c($t2)
/* 00175C 70000B5C 3C018006 */  lui   $at, %hi(viMode+0x4)
/* 001760 70000B60 24040004 */  li    $a0, 4
/* 001764 70000B64 AC2B0880 */  sw    $t3, %lo(viMode+0x4)($at)
/* 001768 70000B68 8D4C0030 */  lw    $t4, 0x30($t2)
/* 00176C 70000B6C 3C018006 */  lui   $at, %hi(viMode+0x8)
/* 001770 70000B70 02202825 */  move  $a1, $s1
/* 001774 70000B74 AC2C0884 */  sw    $t4, %lo(viMode+0x8)($at)
/* 001778 70000B78 8D4D0044 */  lw    $t5, 0x44($t2)
/* 00177C 70000B7C 3C018006 */  lui   $at, %hi(viMode+0xC)
/* 001780 70000B80 2406029B */  li    $a2, 667
/* 001784 70000B84 0C003714 */  jal   osSetEventMesg
/* 001788 70000B88 AC2D0888 */   sw    $t5, %lo(viMode+0xC)($at)
/* 00178C 70000B8C 24040009 */  li    $a0, 9
/* 001790 70000B90 02202825 */  move  $a1, $s1
/* 001794 70000B94 0C003714 */  jal   osSetEventMesg
/* 001798 70000B98 2406029C */   li    $a2, 668
/* 00179C 70000B9C 2404000E */  li    $a0, 14
/* 0017A0 70000BA0 02202825 */  move  $a1, $s1
/* 0017A4 70000BA4 0C003714 */  jal   osSetEventMesg
/* 0017A8 70000BA8 2406029D */   li    $a2, 669
/* 0017AC 70000BAC 02202025 */  move  $a0, $s1
/* 0017B0 70000BB0 2405029A */  li    $a1, 666
/* 0017B4 70000BB4 0C003730 */  jal   osViSetEvent
/* 0017B8 70000BB8 8FA60034 */   lw    $a2, 0x34($sp)
/* 0017BC 70000BBC 0C0002A2 */  jal   osCreateLog
/* 0017C0 70000BC0 00000000 */   nop   
/* 0017C4 70000BC4 3C04803B */  lui   $a0, %hi(sp_shed) # $a0, 0x803b
/* 0017C8 70000BC8 2484B750 */  addiu $a0, %lo(sp_shed) # addiu $a0, $a0, -0x48b0
/* 0017CC 70000BCC 0C0001BC */  jal   set_stack_entry
/* 0017D0 70000BD0 24050200 */   li    $a1, 512
/* 0017D4 70000BD4 8E0400B0 */  lw    $a0, 0xb0($s0)
/* 0017D8 70000BD8 3C067000 */  lui   $a2, %hi(__scMain) # $a2, 0x7000
/* 0017DC 70000BDC 240E001E */  li    $t6, 30
/* 0017E0 70000BE0 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0017E4 70000BE4 24C60D00 */  addiu $a2, %lo(__scMain) # addiu $a2, $a2, 0xd00
/* 0017E8 70000BE8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0017EC 70000BEC 24050002 */  li    $a1, 2
/* 0017F0 70000BF0 0C00350C */  jal   osCreateThread
/* 0017F4 70000BF4 02003825 */   move  $a3, $s0
/* 0017F8 70000BF8 0C003560 */  jal   osStartThread
/* 0017FC 70000BFC 8E0400B0 */   lw    $a0, 0xb0($s0)
/* 001800 70000C00 8FBF0024 */  lw    $ra, 0x24($sp)
/* 001804 70000C04 8FB0001C */  lw    $s0, 0x1c($sp)
/* 001808 70000C08 8FB10020 */  lw    $s1, 0x20($sp)
/* 00180C 70000C0C 03E00008 */  jr    $ra
/* 001810 70000C10 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

/**
 * 1814	70000C14
 */
void osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ, OSScClient *next)
{
    OSIntMask mask;

    mask = osSetIntMask(1);

    c->msgQ = msgQ;
    c[1].next = next;
    c->next = sc->clientList;
    sc->clientList = c;

    osSetIntMask(mask);
}


/**
 * 1870	70000C70
 */
void osScRemoveClient(OSSched *sc, OSScClient *c)
{
    OSScClient *client = sc->clientList; 
    OSScClient *prev   = 0;
    OSIntMask  mask;

    mask = osSetIntMask(1);
    
    while (client != 0) 
    {
        if (client == c) 
        {
	        if(prev)
		        prev->next = c->next;
	        else
		        sc->clientList = c->next;
                break;
        }
        prev   = client;
        client = client->next;
    }

    osSetIntMask(mask);
}


/**
 * 18F8	70000CF8
 * V0= A0+78
 */
OSMesgQueue *osScGetCmdQ(OSSched *sc)
{
    return &sc->cmdQ;
}

/**
 * 1900	70000D00
 */
#ifdef NONMATCHING
void __scMain(OSSched *sc)
{
    OSMesg msg;
    OSScClient *client;
    s32 done = FALSE;
    while (!done) {        
        osRecvMesg(&sc->interruptQ, &msg, OS_MESG_BLOCK);
        switch ((s32)msg) {
            case VIDEO_MSG:
                __scHandleRetrace(sc);
                break;

            case RSP_DONE_MSG:
                __scHandleRSP(sc);
                break;

            case RDP_DONE_MSG:
                __scHandleRDP(sc);
                break;

            case PRE_NMI_MSG:
                joyRumblePakStop();
                for (client = sc->clientList; (client != NULL); client = client->next) {
                      osSendMesg(client->msgQ, (OSMesg)&sc->prenmiMsg, OS_MESG_NOBLOCK);
                }
                done = TRUE;
                break;
        }
    }
    if (osTvType == TV_TYPE_MPAL) {
        osViSetMode(&osViModeTable[OS_VI_NTSC_LAN1]);
    } else {
        osViSetMode(&osViModeTable[OS_VI_MPAL_LAN1]);
    }
    osViSetXScale(1.0f);
    osViSetYScale(1.0f);
    osViRepeatLine(0);
    osViBlack(TRUE);
    while (TRUE) {
        do {
            osRecvMesg(&sc->interruptQ, &msg, OS_MESG_BLOCK);
        } while((s32)msg != VIDEO_MSG);
        joyPoll();
    }
}
#else
GLOBAL_ASM(
glabel __scMain
/* 001900 70000D00 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 001904 70000D04 AFB50028 */  sw    $s5, 0x28($sp)
/* 001908 70000D08 AFB40024 */  sw    $s4, 0x24($sp)
/* 00190C 70000D0C AFB30020 */  sw    $s3, 0x20($sp)
/* 001910 70000D10 AFB2001C */  sw    $s2, 0x1c($sp)
/* 001914 70000D14 AFB00014 */  sw    $s0, 0x14($sp)
/* 001918 70000D18 00809025 */  move  $s2, $a0
/* 00191C 70000D1C AFBF002C */  sw    $ra, 0x2c($sp)
/* 001920 70000D20 AFB10018 */  sw    $s1, 0x18($sp)
/* 001924 70000D24 AFA0004C */  sw    $zero, 0x4c($sp)
/* 001928 70000D28 00008025 */  move  $s0, $zero
/* 00192C 70000D2C 24930040 */  addiu $s3, $a0, 0x40
/* 001930 70000D30 27B4004C */  addiu $s4, $sp, 0x4c
/* 001934 70000D34 2415029A */  li    $s5, 666
/* 001938 70000D38 02602025 */  move  $a0, $s3
.L70000D3C:
/* 00193C 70000D3C 02802825 */  move  $a1, $s4
/* 001940 70000D40 0C003774 */  jal   osRecvMesg
/* 001944 70000D44 24060001 */   li    $a2, 1
/* 001948 70000D48 8FAE004C */  lw    $t6, 0x4c($sp)
/* 00194C 70000D4C 2401029B */  li    $at, 667
/* 001950 70000D50 11D50009 */  beq   $t6, $s5, .L70000D78
/* 001954 70000D54 00000000 */   nop   
/* 001958 70000D58 11C1000B */  beq   $t6, $at, .L70000D88
/* 00195C 70000D5C 2401029C */   li    $at, 668
/* 001960 70000D60 11C1000D */  beq   $t6, $at, .L70000D98
/* 001964 70000D64 2401029D */   li    $at, 669
/* 001968 70000D68 11C1000F */  beq   $t6, $at, .L70000DA8
/* 00196C 70000D6C 00000000 */   nop   
/* 001970 70000D70 1000001B */  b     .L70000DE0
/* 001974 70000D74 00000000 */   nop   
.L70000D78:
/* 001978 70000D78 0C0003AD */  jal   __scHandleRetrace
/* 00197C 70000D7C 02402025 */   move  $a0, $s2
/* 001980 70000D80 10000017 */  b     .L70000DE0
/* 001984 70000D84 00000000 */   nop   
.L70000D88:
/* 001988 70000D88 0C000405 */  jal   __scHandleRSP
/* 00198C 70000D8C 02402025 */   move  $a0, $s2
/* 001990 70000D90 10000013 */  b     .L70000DE0
/* 001994 70000D94 00000000 */   nop   
.L70000D98:
/* 001998 70000D98 0C00044A */  jal   __scHandleRDP
/* 00199C 70000D9C 02402025 */   move  $a0, $s2
/* 0019A0 70000DA0 1000000F */  b     .L70000DE0
/* 0019A4 70000DA4 00000000 */   nop   
.L70000DA8:
/* 0019A8 70000DA8 0C003237 */  jal   joyRumblePakStop
/* 0019AC 70000DAC 00000000 */   nop   
/* 0019B0 70000DB0 8E5000B4 */  lw    $s0, 0xb4($s2)
/* 0019B4 70000DB4 26510020 */  addiu $s1, $s2, 0x20
/* 0019B8 70000DB8 52000009 */  beql  $s0, $zero, .L70000DE0
/* 0019BC 70000DBC 24100001 */   li    $s0, 1
/* 0019C0 70000DC0 8E040004 */  lw    $a0, 4($s0)
.L70000DC4:
/* 0019C4 70000DC4 02202825 */  move  $a1, $s1
/* 0019C8 70000DC8 0C0037C4 */  jal   osSendMesg
/* 0019CC 70000DCC 00003025 */   move  $a2, $zero
/* 0019D0 70000DD0 8E100000 */  lw    $s0, ($s0)
/* 0019D4 70000DD4 5600FFFB */  bnezl $s0, .L70000DC4
/* 0019D8 70000DD8 8E040004 */   lw    $a0, 4($s0)
/* 0019DC 70000DDC 24100001 */  li    $s0, 1
.L70000DE0:
/* 0019E0 70000DE0 5200FFD6 */  beql  $s0, $zero, .L70000D3C
/* 0019E4 70000DE4 02602025 */   move  $a0, $s3
/* 0019E8 70000DE8 3C0F8000 */  lui   $t7, %hi(osTvType) 
/* 0019EC 70000DEC 8DEF0300 */  lw    $t7, %lo(osTvType)($t7)
/* 0019F0 70000DF0 24010002 */  li    $at, 2
/* 0019F4 70000DF4 3C048002 */  lui   $a0, %hi(osViModeTable_osViModeNtscLan1)
/* 0019F8 70000DF8 15E10006 */  bne   $t7, $at, .L70000E14
/* 0019FC 70000DFC 00000000 */   nop   
/* 001A00 70000E00 3C048002 */  lui   $a0, %hi(osViModeTable_osViModeMpalLan1)
/* 001A04 70000E04 0C003818 */  jal   osViSetMode
/* 001A08 70000E08 24847320 */   addiu $a0, %lo(osViModeTable_osViModeMpalLan1) # addiu $a0, $a0, 0x7320
/* 001A0C 70000E0C 10000004 */  b     .L70000E20
/* 001A10 70000E10 3C013F80 */   lui   $at, 0x3f80
.L70000E14:
/* 001A14 70000E14 0C003818 */  jal   osViSetMode
/* 001A18 70000E18 24846A60 */   addiu $a0, $a0, %lo(osViModeTable_osViModeNtscLan1)
/* 001A1C 70000E1C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
.L70000E20:
/* 001A20 70000E20 44816000 */  mtc1  $at, $f12
/* 001A24 70000E24 0C003834 */  jal   osViSetXScale
/* 001A28 70000E28 00000000 */   nop   
/* 001A2C 70000E2C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 001A30 70000E30 44816000 */  mtc1  $at, $f12
/* 001A34 70000E34 0C003880 */  jal   osViSetYScale
/* 001A38 70000E38 00000000 */   nop   
/* 001A3C 70000E3C 0C003898 */  jal   osViRepeatLine
/* 001A40 70000E40 00002025 */   move  $a0, $zero
/* 001A44 70000E44 0C0038B4 */  jal   osViBlack
/* 001A48 70000E48 24040001 */   li    $a0, 1
/* 001A4C 70000E4C 02602025 */  move  $a0, $s3
.L70000E50:
/* 001A50 70000E50 02802825 */  move  $a1, $s4
/* 001A54 70000E54 0C003774 */  jal   osRecvMesg
/* 001A58 70000E58 24060001 */   li    $a2, 1
/* 001A5C 70000E5C 8FB8004C */  lw    $t8, 0x4c($sp)
/* 001A60 70000E60 5715FFFB */  bnel  $t8, $s5, .L70000E50
/* 001A64 70000E64 02602025 */   move  $a0, $s3
/* 001A68 70000E68 0C002F62 */  jal   joyPoll
/* 001A6C 70000E6C 00000000 */   nop   
/* 001A70 70000E70 1000FFF7 */  b     .L70000E50
/* 001A74 70000E74 02602025 */   move  $a0, $s3
/* 001A78 70000E78 00000000 */  nop   
/* 001A7C 70000E7C 00000000 */  nop   
/* 001A80 70000E80 00000000 */  nop   
/* 001A84 70000E84 00000000 */  nop   
/* 001A88 70000E88 00000000 */  nop   
/* 001A8C 70000E8C 00000000 */  nop   
/* 001A90 70000E90 8FBF002C */  lw    $ra, 0x2c($sp)
/* 001A94 70000E94 8FB00014 */  lw    $s0, 0x14($sp)
/* 001A98 70000E98 8FB10018 */  lw    $s1, 0x18($sp)
/* 001A9C 70000E9C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 001AA0 70000EA0 8FB30020 */  lw    $s3, 0x20($sp)
/* 001AA4 70000EA4 8FB40024 */  lw    $s4, 0x24($sp)
/* 001AA8 70000EA8 8FB50028 */  lw    $s5, 0x28($sp)
/* 001AAC 70000EAC 03E00008 */  jr    $ra
/* 001AB0 70000EB0 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif

void __scHandleRetrace(OSSched *sc)
{
    OSScTask    *rspTask = 0;    
    OSScClient  *client;
    s32         state;
    OSScTask    *sp = 0;
    OSScTask    *dp = 0;
    video_related_1();
    sc->frameCount++;
    video_related_7();
    joyPoll();
    music_related_15();
    while (osRecvMesg(&sc->cmdQ, (OSMesg*)&rspTask, OS_MESG_NOBLOCK) != -1) {
        __scAppendList(sc, rspTask);
    }
    if (sc->doAudio && sc->curRSPTask) {
        __scYield(sc);
    } else {
        state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
        if ( __scSchedule (sc, &sp, &dp, state) != state)
            __scExec(sc, sp, dp);
    }
    for (client = sc->clientList; client != 0; client = client->next) {
        if ((*((s32*)client + 2) == 0) || ((sc->frameCount & 1) == 0)) {
            osSendMesg(client->msgQ, (OSMesg) &sc->retraceMsg, OS_MESG_NOBLOCK);
        }
    }
    CheckDisplayErrorBufferEvery16Frames(sc->frameCount);
}

/**
 * 1C14	70001014
 */
#ifdef NONMATCHING
void __scHandleRSP(OSSched *sc)
{
    OSScTask *t, *sp = 0, *dp = 0;
    s32 state;

    t = sc->curRSPTask;
    sc->curRSPTask = 0;
    video_related_3(0x10001);
    if (((t->state & 0x10) != 0) && (osSpTaskYielded(t->list) != 0))
    {
        t->state = (s32) (t->state | 0x20);
        if ((t->flags & 7) == 3)
        {
            *t = (void *) sc->gfxListHead;
            sc->gfxListHead = t;
            if (sc->gfxListTail == 0)
            {
                sc->gfxListTail = t;
            }
        }
    }
    else
    {
        t->state = (s32) (t->state & -3);
        __scTaskComplete(sc, t);
    }
    if (__scSchedule(sc, &sp, &dp, ((((u32) sc->curRSPTask < 1U) * 2) | ((u32) sc->curRDPTask < 1U))))
    {
        __scExec(sc, sp, dp);
    }
}

#else
GLOBAL_ASM(
glabel __scHandleRSP
/* 001C14 70001014 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 001C18 70001018 AFBF001C */  sw    $ra, 0x1c($sp)
/* 001C1C 7000101C AFB00018 */  sw    $s0, 0x18($sp)
/* 001C20 70001020 AFA00028 */  sw    $zero, 0x28($sp)
/* 001C24 70001024 AFA00024 */  sw    $zero, 0x24($sp)
/* 001C28 70001028 8C8500C8 */  lw    $a1, 0xc8($a0)
/* 001C2C 7000102C 00808025 */  move  $s0, $a0
/* 001C30 70001030 AC8000C8 */  sw    $zero, 0xc8($a0)
/* 001C34 70001034 3C040001 */  lui   $a0, (0x00010001 >> 16) # lui $a0, 1
/* 001C38 70001038 34840001 */  ori   $a0, (0x00010001 & 0xFFFF) # ori $a0, $a0, 1
/* 001C3C 7000103C 0C000A15 */  jal   video_related_3
/* 001C40 70001040 AFA5002C */   sw    $a1, 0x2c($sp)
/* 001C44 70001044 8FA5002C */  lw    $a1, 0x2c($sp)
/* 001C48 70001048 8CAE0004 */  lw    $t6, 4($a1)
/* 001C4C 7000104C 24A40010 */  addiu $a0, $a1, 0x10
/* 001C50 70001050 31CF0010 */  andi  $t7, $t6, 0x10
/* 001C54 70001054 51E00015 */  beql  $t7, $zero, .L700010AC
/* 001C58 70001058 8CAC0004 */   lw    $t4, 4($a1)
/* 001C5C 7000105C 0C0038D0 */  jal   osSpTaskYielded
/* 001C60 70001060 AFA5002C */   sw    $a1, 0x2c($sp)
/* 001C64 70001064 10400010 */  beqz  $v0, .L700010A8
/* 001C68 70001068 8FA5002C */   lw    $a1, 0x2c($sp)
/* 001C6C 7000106C 8CB80004 */  lw    $t8, 4($a1)
/* 001C70 70001070 8CA80008 */  lw    $t0, 8($a1)
/* 001C74 70001074 24010003 */  li    $at, 3
/* 001C78 70001078 37190020 */  ori   $t9, $t8, 0x20
/* 001C7C 7000107C 31090007 */  andi  $t1, $t0, 7
/* 001C80 70001080 1521000F */  bne   $t1, $at, .L700010C0
/* 001C84 70001084 ACB90004 */   sw    $t9, 4($a1)
/* 001C88 70001088 8E0A00BC */  lw    $t2, 0xbc($s0)
/* 001C8C 7000108C ACAA0000 */  sw    $t2, ($a1)
/* 001C90 70001090 8E0B00C4 */  lw    $t3, 0xc4($s0)
/* 001C94 70001094 AE0500BC */  sw    $a1, 0xbc($s0)
/* 001C98 70001098 5560000A */  bnezl $t3, .L700010C4
/* 001C9C 7000109C 8E0E00C8 */   lw    $t6, 0xc8($s0)
/* 001CA0 700010A0 10000007 */  b     .L700010C0
/* 001CA4 700010A4 AE0500C4 */   sw    $a1, 0xc4($s0)
.L700010A8:
/* 001CA8 700010A8 8CAC0004 */  lw    $t4, 4($a1)
.L700010AC:
/* 001CAC 700010AC 2401FFFD */  li    $at, -3
/* 001CB0 700010B0 02002025 */  move  $a0, $s0
/* 001CB4 700010B4 01816824 */  and   $t5, $t4, $at
/* 001CB8 700010B8 0C00048C */  jal   __scTaskComplete
/* 001CBC 700010BC ACAD0004 */   sw    $t5, 4($a1)
.L700010C0:
/* 001CC0 700010C0 8E0E00C8 */  lw    $t6, 0xc8($s0)
.L700010C4:
/* 001CC4 700010C4 8E1900CC */  lw    $t9, 0xcc($s0)
/* 001CC8 700010C8 02002025 */  move  $a0, $s0
/* 001CCC 700010CC 2DCF0001 */  sltiu $t7, $t6, 1
/* 001CD0 700010D0 000FC040 */  sll   $t8, $t7, 1
/* 001CD4 700010D4 2F280001 */  sltiu $t0, $t9, 1
/* 001CD8 700010D8 03083825 */  or    $a3, $t8, $t0
/* 001CDC 700010DC AFA70020 */  sw    $a3, 0x20($sp)
/* 001CE0 700010E0 27A50028 */  addiu $a1, $sp, 0x28
/* 001CE4 700010E4 0C000567 */  jal   __scSchedule
/* 001CE8 700010E8 27A60024 */   addiu $a2, $sp, 0x24
/* 001CEC 700010EC 8FA70020 */  lw    $a3, 0x20($sp)
/* 001CF0 700010F0 02002025 */  move  $a0, $s0
/* 001CF4 700010F4 8FA50028 */  lw    $a1, 0x28($sp)
/* 001CF8 700010F8 50470004 */  beql  $v0, $a3, .L7000110C
/* 001CFC 700010FC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 001D00 70001100 0C000510 */  jal   __scExec
/* 001D04 70001104 8FA60024 */   lw    $a2, 0x24($sp)
/* 001D08 70001108 8FBF001C */  lw    $ra, 0x1c($sp)
.L7000110C:
/* 001D0C 7000110C 8FB00018 */  lw    $s0, 0x18($sp)
/* 001D10 70001110 27BD0030 */  addiu $sp, $sp, 0x30
/* 001D14 70001114 03E00008 */  jr    $ra
/* 001D18 70001118 00000000 */   nop   
)
#endif

/**
 * 1D1C	7000111C
 * V0= 8005DB30: target for DP Cmd clock, buffer counter, pipe counter, and tmem counter
 */
char *get_counters(void)
{
    return &target_for_counters_maybe;
}

/**
 * 1D28	70001128
 */
#ifdef NONMATCHING
void __scHandleRDP(void *arg0)
{
    ?32 sp28;
    ?32 sp24;

    sp28 = 0;
    sp24 = 0;
    if (arg0->unkCC != 0)
    {
        video_related_3(0x10002);
        osDpGetCounters(&target_for_counters_maybe);
        arg0->unkCC = NULL;
        arg0->unkCC->unk4 = (s32) (arg0->unkCC->unk4 & -2);
        __scTaskComplete(arg0, arg0->unkCC);
        if (__scSchedule(arg0, &sp28, &sp24, ((((u32) arg0->unkC8 < 1U) * 2) | ((u32) arg0->unkCC < 1U))) != sp20)
        {
            __scExec(arg0, sp28, sp24, sp20);
        }
    }
}

#else
GLOBAL_ASM(
glabel __scHandleRDP
/* 001D28 70001128 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 001D2C 7000112C AFBF001C */  sw    $ra, 0x1c($sp)
/* 001D30 70001130 AFB00018 */  sw    $s0, 0x18($sp)
/* 001D34 70001134 AFA00028 */  sw    $zero, 0x28($sp)
/* 001D38 70001138 AFA00024 */  sw    $zero, 0x24($sp)
/* 001D3C 7000113C 8C8E00CC */  lw    $t6, 0xcc($a0)
/* 001D40 70001140 00808025 */  move  $s0, $a0
/* 001D44 70001144 3C040001 */  lui   $a0, (0x00010002 >> 16) # lui $a0, 1
/* 001D48 70001148 51C00021 */  beql  $t6, $zero, .L700011D0
/* 001D4C 7000114C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 001D50 70001150 0C000A15 */  jal   video_related_3
/* 001D54 70001154 34840002 */   ori   $a0, (0x00010002 & 0xFFFF) # ori $a0, $a0, 2
/* 001D58 70001158 3C048006 */  lui   $a0, %hi(target_for_counters_maybe)
/* 001D5C 7000115C 0C0038F0 */  jal   osDpGetCounters
/* 001D60 70001160 2484DB30 */   addiu $a0, %lo(target_for_counters_maybe) # addiu $a0, $a0, -0x24d0
/* 001D64 70001164 8E0500CC */  lw    $a1, 0xcc($s0)
/* 001D68 70001168 AE0000CC */  sw    $zero, 0xcc($s0)
/* 001D6C 7000116C 2401FFFE */  li    $at, -2
/* 001D70 70001170 8CAF0004 */  lw    $t7, 4($a1)
/* 001D74 70001174 02002025 */  move  $a0, $s0
/* 001D78 70001178 01E1C024 */  and   $t8, $t7, $at
/* 001D7C 7000117C 0C00048C */  jal   __scTaskComplete
/* 001D80 70001180 ACB80004 */   sw    $t8, 4($a1)
/* 001D84 70001184 8E1900C8 */  lw    $t9, 0xc8($s0)
/* 001D88 70001188 8E0A00CC */  lw    $t2, 0xcc($s0)
/* 001D8C 7000118C 02002025 */  move  $a0, $s0
/* 001D90 70001190 2F280001 */  sltiu $t0, $t9, 1
/* 001D94 70001194 00084840 */  sll   $t1, $t0, 1
/* 001D98 70001198 2D4B0001 */  sltiu $t3, $t2, 1
/* 001D9C 7000119C 012B3825 */  or    $a3, $t1, $t3
/* 001DA0 700011A0 AFA70020 */  sw    $a3, 0x20($sp)
/* 001DA4 700011A4 27A50028 */  addiu $a1, $sp, 0x28
/* 001DA8 700011A8 0C000567 */  jal   __scSchedule
/* 001DAC 700011AC 27A60024 */   addiu $a2, $sp, 0x24
/* 001DB0 700011B0 8FA70020 */  lw    $a3, 0x20($sp)
/* 001DB4 700011B4 02002025 */  move  $a0, $s0
/* 001DB8 700011B8 8FA50028 */  lw    $a1, 0x28($sp)
/* 001DBC 700011BC 50470004 */  beql  $v0, $a3, .L700011D0
/* 001DC0 700011C0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 001DC4 700011C4 0C000510 */  jal   __scExec
/* 001DC8 700011C8 8FA60024 */   lw    $a2, 0x24($sp)
/* 001DCC 700011CC 8FBF001C */  lw    $ra, 0x1c($sp)
.L700011D0:
/* 001DD0 700011D0 8FB00018 */  lw    $s0, 0x18($sp)
/* 001DD4 700011D4 27BD0030 */  addiu $sp, $sp, 0x30
/* 001DD8 700011D8 03E00008 */  jr    $ra
/* 001DDC 700011DC 00000000 */   nop   
)
#endif

/**
 * 1DE0	700011E0
 * 
 */
OSScTask *__scTaskReady(OSScTask *t) 
{
    void *a;
    void *b;    

    if (t) {    
        if ((a=osViGetCurrentFramebuffer()) != (b=osViGetNextFramebuffer())) {
            return 0;
        }

        return t;
    }

    return 0;
}

/**
 * 1E30	70001230
 */
#ifdef NONMATCHING
void __scTaskComplete(s32 arg0, void *arg1)
{
    s32 temp_t2;
    void *temp_t8;
    void *temp_t8_2;
    void *temp_t5;
    s32 temp_t7;
    s32 temp_t0;
    void *phi_t8;
    void *phi_t5;
    s32 phi_v1;
    s32 phi_t0;
    ? phi_return;

    phi_return = 0;
    if ((arg1->unk4 & 3) == 0)
    {
        osSendMesg(arg1->unk50, arg1->unk54, 1);
        if (arg1->unk10 == 1)
        {
            if ((arg1->unk8 & 0x40) != 0)
            {
                if ((arg1->unk8 & 0x20) != 0)
                {
                    if (D_800230CC != 0)
                    {
                        osViBlack(0);
                        D_800230CC = 0;
                    }
                    temp_t2 = (something_with_osVI * 4);
                    phi_v1 = temp_t2;
                    if ((0x80020000 + temp_t2)->unk30C4 != 0)
                    {
                        temp_t8 = ((something_with_osVI * 0x50) + &dword_CODE_bss_8005DB40);
                        phi_t8 = temp_t8;
                        phi_t5 = (0x80060000 + (something_with_osVI * 4))->unk-2420;
block_8:
                        temp_t8_2 = (phi_t8 + 0xc);
                        temp_t5 = (phi_t5 + 0xc);
                        temp_t5->unk-C = (?32) *phi_t8;
                        temp_t5->unk-8 = (?32) temp_t8_2->unk-8;
                        temp_t5->unk-4 = (?32) temp_t8_2->unk-4;
                        phi_t8 = temp_t8_2;
                        phi_t5 = temp_t5;
                        if (temp_t8_2 != (temp_t8 + 0x48))
                        {
                            goto block_8;
                        }
                        *temp_t5 = (?32) *temp_t8_2;
                        temp_t5->unk4 = (?32) temp_t8_2->unk4;
                        osSetIntMask(osSetIntMask(0x80401));
                        phi_v1 = (something_with_osVI * 4);
                    }
                    osViSetXScale((0x80020000 + phi_v1)->unk30B4);
                    osViSetYScale((0x80020000 + (something_with_osVI * 4))->unk30BC);
                    temp_t7 = (something_with_osVI + 1);
                    temp_t0 = (temp_t7 & 1);
                    phi_t0 = temp_t0;
                    if (temp_t7 < 0)
                    {
                        phi_t0 = temp_t0;
                        if (temp_t0 != 0)
                        {
                            phi_t0 = (temp_t0 + -2);
                        }
                    }
                    something_with_osVI = (s32) phi_t0;
                    CheckDisplayErrorBuffer(arg1->unkC);
                    osViSwapBuffer(arg1->unkC);
                }
            }
        }
        phi_return = 1;
    }
    return phi_return;
}
#else
GLOBAL_ASM(
glabel __scTaskComplete
/* 001E30 70001230 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 001E34 70001234 AFBF001C */  sw    $ra, 0x1c($sp)
/* 001E38 70001238 AFB00018 */  sw    $s0, 0x18($sp)
/* 001E3C 7000123C AFA40020 */  sw    $a0, 0x20($sp)
/* 001E40 70001240 8CAE0004 */  lw    $t6, 4($a1)
/* 001E44 70001244 00A08025 */  move  $s0, $a1
/* 001E48 70001248 24060001 */  li    $a2, 1
/* 001E4C 7000124C 31CF0003 */  andi  $t7, $t6, 3
/* 001E50 70001250 15E0005C */  bnez  $t7, .L700013C4
/* 001E54 70001254 00001025 */   move  $v0, $zero
/* 001E58 70001258 8CA40050 */  lw    $a0, 0x50($a1)
/* 001E5C 7000125C 0C0037C4 */  jal   osSendMesg
/* 001E60 70001260 8CA50054 */   lw    $a1, 0x54($a1)
/* 001E64 70001264 8E180010 */  lw    $t8, 0x10($s0)
/* 001E68 70001268 24010001 */  li    $at, 1
/* 001E6C 7000126C 17010053 */  bne   $t8, $at, .L700013BC
/* 001E70 70001270 00000000 */   nop   
/* 001E74 70001274 8E020008 */  lw    $v0, 8($s0)
/* 001E78 70001278 30590040 */  andi  $t9, $v0, 0x40
/* 001E7C 7000127C 1320004F */  beqz  $t9, .L700013BC
/* 001E80 70001280 30480020 */   andi  $t0, $v0, 0x20
/* 001E84 70001284 1100004D */  beqz  $t0, .L700013BC
/* 001E88 70001288 3C098002 */   lui   $t1, %hi(D_800230CC) 
/* 001E8C 7000128C 8D2930CC */  lw    $t1, %lo(D_800230CC)($t1)
/* 001E90 70001290 11200005 */  beqz  $t1, .L700012A8
/* 001E94 70001294 00000000 */   nop   
/* 001E98 70001298 0C0038B4 */  jal   osViBlack
/* 001E9C 7000129C 00002025 */   move  $a0, $zero
/* 001EA0 700012A0 3C018002 */  lui   $at, %hi(D_800230CC)
/* 001EA4 700012A4 AC2030CC */  sw    $zero, %lo(D_800230CC)($at)
.L700012A8:
/* 001EA8 700012A8 3C038002 */  lui   $v1, %hi(something_with_osVI_0)
/* 001EAC 700012AC 8C6330B0 */  lw    $v1, %lo(something_with_osVI_0)($v1)
/* 001EB0 700012B0 3C0B8002 */  lui   $t3, %hi(something_with_osVI_14)
/* 001EB4 700012B4 3C040008 */  lui   $a0, (0x00080401 >> 16) # lui $a0, 8
/* 001EB8 700012B8 00035080 */  sll   $t2, $v1, 2
/* 001EBC 700012BC 016A5821 */  addu  $t3, $t3, $t2
/* 001EC0 700012C0 8D6B30C4 */  lw    $t3, %lo(something_with_osVI_14)($t3)
/* 001EC4 700012C4 01401825 */  move  $v1, $t2
/* 001EC8 700012C8 11600023 */  beqz  $t3, .L70001358
/* 001ECC 700012CC 00000000 */   nop   
/* 001ED0 700012D0 0C00374C */  jal   osSetIntMask
/* 001ED4 700012D4 34840401 */   ori   $a0, (0x00080401 & 0xFFFF) # ori $a0, $a0, 0x401
/* 001ED8 700012D8 3C038002 */  lui   $v1, %hi(something_with_osVI_0)
/* 001EDC 700012DC 8C6330B0 */  lw    $v1, %lo(something_with_osVI_0)($v1)
/* 001EE0 700012E0 3C0F8006 */  lui   $t7, %hi(viModes) 
/* 001EE4 700012E4 25EFDB40 */  addiu $t7, %lo(viModes) # addiu $t7, $t7, -0x24c0
/* 001EE8 700012E8 00037080 */  sll   $t6, $v1, 2
/* 001EEC 700012EC 01C37021 */  addu  $t6, $t6, $v1
/* 001EF0 700012F0 000E7100 */  sll   $t6, $t6, 4
/* 001EF4 700012F4 3C0D8006 */  lui   $t5, %hi(sc+416)
/* 001EF8 700012F8 00036080 */  sll   $t4, $v1, 2
/* 001EFC 700012FC 01AC6821 */  addu  $t5, $t5, $t4
/* 001F00 70001300 01CFC021 */  addu  $t8, $t6, $t7
/* 001F04 70001304 27090048 */  addiu $t1, $t8, 0x48
/* 001F08 70001308 8DADDBE0 */  lw    $t5, %lo(sc+416)($t5)
.L7000130C:
/* 001F0C 7000130C 8F010000 */  lw    $at, ($t8)
/* 001F10 70001310 2718000C */  addiu $t8, $t8, 0xc
/* 001F14 70001314 25AD000C */  addiu $t5, $t5, 0xc
/* 001F18 70001318 ADA1FFF4 */  sw    $at, -0xc($t5)
/* 001F1C 7000131C 8F01FFF8 */  lw    $at, -8($t8)
/* 001F20 70001320 ADA1FFF8 */  sw    $at, -8($t5)
/* 001F24 70001324 8F01FFFC */  lw    $at, -4($t8)
/* 001F28 70001328 1709FFF8 */  bne   $t8, $t1, .L7000130C
/* 001F2C 7000132C ADA1FFFC */   sw    $at, -4($t5)
/* 001F30 70001330 8F010000 */  lw    $at, ($t8)
/* 001F34 70001334 00402025 */  move  $a0, $v0
/* 001F38 70001338 ADA10000 */  sw    $at, ($t5)
/* 001F3C 7000133C 8F090004 */  lw    $t1, 4($t8)
/* 001F40 70001340 0C00374C */  jal   osSetIntMask
/* 001F44 70001344 ADA90004 */   sw    $t1, 4($t5)
/* 001F48 70001348 3C038002 */  lui   $v1, %hi(something_with_osVI_0)
/* 001F4C 7000134C 8C6330B0 */  lw    $v1, %lo(something_with_osVI_0)($v1)
/* 001F50 70001350 00035080 */  sll   $t2, $v1, 2
/* 001F54 70001354 01401825 */  move  $v1, $t2
.L70001358:
/* 001F58 70001358 3C018002 */  lui   $at, %hi(something_with_osVI_4)
/* 001F5C 7000135C 00230821 */  addu  $at, $at, $v1
/* 001F60 70001360 0C003834 */  jal   osViSetXScale
/* 001F64 70001364 C42C30B4 */   lwc1  $f12, %lo(something_with_osVI_4)($at)
/* 001F68 70001368 3C0B8002 */  lui   $t3, %hi(something_with_osVI_0) 
/* 001F6C 7000136C 8D6B30B0 */  lw    $t3, %lo(something_with_osVI_0)($t3)
/* 001F70 70001370 3C018002 */  lui   $at, %hi(something_with_osVI_C)
/* 001F74 70001374 000B6080 */  sll   $t4, $t3, 2
/* 001F78 70001378 002C0821 */  addu  $at, $at, $t4
/* 001F7C 7000137C 0C003880 */  jal   osViSetYScale
/* 001F80 70001380 C42C30BC */   lwc1  $f12, %lo(something_with_osVI_C)($at)
/* 001F84 70001384 3C0E8002 */  lui   $t6, %hi(something_with_osVI_0) 
/* 001F88 70001388 8DCE30B0 */  lw    $t6, %lo(something_with_osVI_0)($t6)
/* 001F8C 7000138C 3C018002 */  lui   $at, %hi(something_with_osVI_0)
/* 001F90 70001390 25CF0001 */  addiu $t7, $t6, 1
/* 001F94 70001394 05E10004 */  bgez  $t7, .L700013A8
/* 001F98 70001398 31E80001 */   andi  $t0, $t7, 1
/* 001F9C 7000139C 11000002 */  beqz  $t0, .L700013A8
/* 001FA0 700013A0 00000000 */   nop   
/* 001FA4 700013A4 2508FFFE */  addiu $t0, $t0, -2
.L700013A8:
/* 001FA8 700013A8 AC2830B0 */  sw    $t0, %lo(something_with_osVI_0)($at)
/* 001FAC 700013AC 0C000268 */  jal   CheckDisplayErrorBuffer
/* 001FB0 700013B0 8E04000C */   lw    $a0, 0xc($s0)
/* 001FB4 700013B4 0C003924 */  jal   osViSwapBuffer
/* 001FB8 700013B8 8E04000C */   lw    $a0, 0xc($s0)
.L700013BC:
/* 001FBC 700013BC 10000001 */  b     .L700013C4
/* 001FC0 700013C0 24020001 */   li    $v0, 1
.L700013C4:
/* 001FC4 700013C4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 001FC8 700013C8 8FB00018 */  lw    $s0, 0x18($sp)
/* 001FCC 700013CC 27BD0020 */  addiu $sp, $sp, 0x20
/* 001FD0 700013D0 03E00008 */  jr    $ra
/* 001FD4 700013D4 00000000 */   nop   
)
#endif

/**
 * 1FD8	700013D8
 */

void __scAppendList(OSSched *sc, OSScTask *t) 
{
    long type = t->list.t.type;
    
    if (type == M_AUDTASK) {
        if (sc->audioListTail)
            sc->audioListTail->next = t;
        else
            sc->audioListHead = t;
            
        sc->audioListTail = t;
        sc->doAudio = 1;
    } else {
        if (sc->gfxListTail)
            sc->gfxListTail->next = t;
        else
            sc->gfxListHead = t;
        
	sc->gfxListTail = t;
    }
    
    t->next = NULL;
    t->state = t->flags & OS_SC_RCP_MASK;    
}

void __scExec(OSSched *sc, OSScTask *sp, OSScTask *dp)
{
    int rv;
    if (sp)
    {
        if (sp->list.t.type == M_AUDTASK)
        {
            osWritebackDCacheAll();
        } 
        
        if ((sp->list.t.type != M_AUDTASK) && (sp->state & 0x10) == 0)
        {
            osDpSetStatus(0x3c0);
        }
        
        if (sp->list.t.type == 2)
        {
            video_related_3(0x30001);
        }
        else
        {
            video_related_3(0x40001);
            video_related_3(0x20002);
        }
        sp->state &= ~(OS_SC_YIELD | OS_SC_YIELDED); 
        osSpTaskLoad(&sp->list);
        osSpTaskStartGo(&sp->list);
        sc->curRSPTask = sp;
        if (sp == dp)
        {
            sc->curRDPTask = dp;
        }
    }
    if (dp && (dp != sp))
    {
        rv = osDpSetNextBuffer(dp->list.t.output_buff, *dp->list.t.output_buff_size);

        dp_busy = 1;
        dpCount = 0;

        sc->curRDPTask = dp;        
    }
}

/**
 * 2160	70001560
 */

void __scYield(OSSched *sc) 
{
    if (sc->curRSPTask->list.t.type == M_GFXTASK) {
        sc->curRSPTask->state |= 0x0010;
        osSpTaskYield();
    } else {
      
    }    
}


/**
 * 219C	7000159C
 * ???
 *	uses TLB pointers at 80028400
 *	7000167C	3
 *	70001704	2,6,7
 *	70001758	default; 1,4,5
 */
s32 __scSchedule(OSSched *sc, OSScTask **sp, OSScTask **dp, s32 availRCP) 
{
    s32 avail = availRCP;
    OSScTask *gfx = sc->gfxListHead;
    OSScTask *audio = sc->audioListHead;

    if (sc->doAudio && (avail & OS_SC_SP))
    {
        if (gfx && (gfx->flags & OS_SC_PARALLEL_TASK))
        {
            *sp = gfx;
            avail &= ~OS_SC_SP;
        } else {
            *sp = audio;
            avail &= ~OS_SC_SP;
            sc->doAudio = 0;
            sc->audioListHead = sc->audioListHead->next;
            if (sc->audioListHead == NULL)
                sc->audioListTail = NULL; 
        }        
    } else {            
        if (__scTaskReady(gfx))
        {
            switch (gfx->flags & OS_SC_TYPE_MASK)
            {
              case (OS_SC_XBUS):
                  if (gfx->state & OS_SC_YIELDED)
                  {
                      if (avail & OS_SC_SP)
                      {
                          *sp = gfx;
                          avail &= ~OS_SC_SP;
                      
                          if (gfx->state & OS_SC_DP)
                          { 
                              *dp = gfx;
                              avail &= ~OS_SC_DP;

                              if (avail & OS_SC_DP == 0)
                                  assert(sc->curRDPTask == gfx);
                              
                          }
                          sc->gfxListHead = sc->gfxListHead->next;
                          if (sc->gfxListHead == NULL)
                              sc->gfxListTail = NULL;
                      }                  
                  } else {
                      if (avail == (OS_SC_SP | OS_SC_DP))
                      {
                          *sp = *dp = gfx;
                          avail &= ~(OS_SC_SP | OS_SC_DP);
                          sc->gfxListHead = sc->gfxListHead->next;
                          if (sc->gfxListHead == NULL)
                              sc->gfxListTail = NULL;
                      }
                  }
                  break;
          
              case (OS_SC_DRAM):
              case (OS_SC_DP_DRAM):
              case (OS_SC_DP_XBUS):
                  if (gfx->state & OS_SC_SP) 
                  {
                      if (avail & OS_SC_SP)
                      {
                          *sp = gfx;
                          avail &= ~OS_SC_SP;
                      }
                  } else if (gfx->state & OS_SC_DP) {
                      if (avail & OS_SC_DP)
                      {
                          *dp = gfx;
                          avail &= ~OS_SC_DP;
                          sc->gfxListHead = sc->gfxListHead->next;
                          if (sc->gfxListHead == NULL)
                              sc->gfxListTail = NULL;
                      }
                  }
                  break;

              case (OS_SC_SP_DRAM):
              case (OS_SC_SP_XBUS):
              default:
                  break;
            }
        }
    }

    if (avail != availRCP)
        avail = __scSchedule(sc, sp, dp, avail);

    return avail;
    
}
