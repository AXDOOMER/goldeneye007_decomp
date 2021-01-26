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
s32 g_ViCurrentIndex = 0;
f32 g_ViXScales[2] = {1.0, 1.0};
f32 g_ViYScales[2] = {1.0, 1.0};
s32 something_with_osVI_14[2] = {0, 0}; // boolean

OSSched sc;
//temporary until i get proper sized structs
OSScClient gfxClient[3];
//char gfxClient[0x18];

u32 g_DisplayPerformanceCounters[4]; // clock, cmc, pipe, tmem
OSViMode g_ViModes[2];
OSViMode *g_ViModePtrs[2];

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

void osCreateScheduler (OSSched * sc, void * stack, u8 mode, u32 numFields) {
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
    dword_CODE_bss_80060880 = viMode->comRegs.hStart;
    dword_CODE_bss_80060884 = viMode->fldRegs[0].vStart;
    dword_CODE_bss_80060888 = viMode->fldRegs[1].vStart;
    osSetEventMesg(OS_EVENT_SP, &sc->interruptQ, (OSMesg)RSP_DONE_MSG); 
    osSetEventMesg(OS_EVENT_DP, &sc->interruptQ, (OSMesg)RDP_DONE_MSG);
    osSetEventMesg(OS_EVENT_PRENMI, &sc->interruptQ, (OSMesg)PRE_NMI_MSG);
    osViSetEvent(&sc->interruptQ, (OSMesg)VIDEO_MSG, numFields);
    osCreateLog();
    osCreateThread(sc->thread, 2, &__scMain, sc, set_stack_entry(&sp_shed, 0x200), 0x1e);
    osStartThread(sc->thread);
}

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

void __scHandleRetrace(OSSched *sc) {
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

void __scHandleRSP(OSSched *sc) {
    OSScTask *t, *sp = 0, *dp = 0;
    s32 state;
    t = sc->curRSPTask;
    sc->curRSPTask = 0;
    video_related_3(0x10001);
    if ((t->state & OS_SC_YIELD) && osSpTaskYielded(&t->list)) {
        t->state |= OS_SC_YIELDED;
        if ((t->flags & OS_SC_TYPE_MASK) == OS_SC_XBUS) {
            t->next = sc->gfxListHead;
            sc->gfxListHead = t;
            if (sc->gfxListTail == 0) {
                sc->gfxListTail = t;
            }
        }
    } else {
        t->state &= ~OS_SC_NEEDS_RSP;
        __scTaskComplete(sc, t);
    }
    state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
    if (__scSchedule(sc, &sp, &dp, state) != state) {
        __scExec(sc, sp, dp);
    }
}

u32 *get_counters(void)
{
    return g_DisplayPerformanceCounters;
}

void __scHandleRDP(OSSched *sc)
{
    OSScTask *t, *sp = NULL, *dp = NULL; 
    s32 state;
    if (sc->curRDPTask != NULL) {
        video_related_3(0x10002);
        osDpGetCounters(g_DisplayPerformanceCounters);
        t = sc->curRDPTask;
        sc->curRDPTask = NULL;
        t->state &= ~OS_SC_NEEDS_RDP;
        __scTaskComplete(sc, t);
        state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
        if (__scSchedule(sc, &sp, &dp, state) != state) {
            __scExec(sc, sp, dp);
        }
    }
}

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

s32 __scTaskComplete(OSSched *sc, OSScTask *t)
{
    int rv;
    static int firsttime = 1;
    if ((t->state & OS_SC_RCP_MASK) == 0) {
        rv = osSendMesg(t->msgQ, t->msg, OS_MESG_BLOCK);
        if (t->list.t.type == M_GFXTASK) {
            if ((t->flags & OS_SC_SWAPBUFFER) && (t->flags & OS_SC_LAST_TASK)){
                if (firsttime) {
                    osViBlack(FALSE);
                    firsttime = 0;
                }
                if (something_with_osVI_14[g_ViCurrentIndex]) {
                    OSIntMask mask = osSetIntMask(0x80401);
                    *g_ViModePtrs[g_ViCurrentIndex] = g_ViModes[g_ViCurrentIndex];
                    osSetIntMask(mask);
                }
                osViSetXScale(g_ViXScales[g_ViCurrentIndex]);
                osViSetYScale(g_ViYScales[g_ViCurrentIndex]);
                g_ViCurrentIndex = ((g_ViCurrentIndex + 1) % 2);
                CheckDisplayErrorBuffer(t->framebuffer);
                osViSwapBuffer(t->framebuffer);
            }
        }
        return 1;
    }    
    return 0;
}

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
