#include <os_internal.h>
#include <rcp.h>
#include "src/libultra/io/viint.h"
#include "src/libultra/os/osint.h"

OSDevMgr __osViDevMgr = {0};
static OSThread viThread;
static unsigned char viThreadStack[OS_VIM_STACKSIZE];
static OSMesgQueue viEventQueue;
static OSMesg viEventBuf[5];
static OSIoMesg viRetraceMsg;
static OSIoMesg viCounterMsg;

static void viMgrMain(void *arg);

#ifndef VERSION_EU

void osCreateViManager(OSPri pri)
{
	u32 savedMask;
	OSPri oldPri;
	OSPri myPri;
	if (__osViDevMgr.active == 0)
	{
		__osTimerServicesInit();
		osCreateMesgQueue(&viEventQueue, viEventBuf, 5);
		viRetraceMsg.hdr.type = OS_MESG_TYPE_VRETRACE;
		viRetraceMsg.hdr.pri = OS_MESG_PRI_NORMAL;
		viRetraceMsg.hdr.retQueue = NULL;
		viCounterMsg.hdr.type = OS_MESG_TYPE_COUNTER;
		viCounterMsg.hdr.pri = OS_MESG_PRI_NORMAL;
		viCounterMsg.hdr.retQueue = NULL;
		osSetEventMesg(OS_EVENT_VI, &viEventQueue, &viRetraceMsg);
		osSetEventMesg(OS_EVENT_COUNTER, &viEventQueue, &viCounterMsg);
		oldPri = -1;
		myPri = osGetThreadPri(NULL);
		if (myPri < pri)
		{
			oldPri = myPri;
			osSetThreadPri(NULL, pri);
		}
		savedMask = __osDisableInt();
		__osViDevMgr.active = 1;
		__osViDevMgr.thread = &viThread;
		__osViDevMgr.cmdQueue = &viEventQueue;
		__osViDevMgr.evtQueue = &viEventQueue;
		__osViDevMgr.acsQueue = NULL;
		__osViDevMgr.dma = NULL;
		__osViDevMgr.edma = NULL;
		osCreateThread(&viThread, 0, viMgrMain, &__osViDevMgr, &viThreadStack[OS_VIM_STACKSIZE], pri);
		__osViInit();
		osStartThread(&viThread);
		__osRestoreInt(savedMask);
		if (oldPri != -1)
		{
			osSetThreadPri(0, oldPri);
		}
	}
}

static void viMgrMain(void *arg)
{
	__OSViContext *vc;
	OSDevMgr *dm;
	OSIoMesg *mb;
	static u16 retrace;
	s32 first;
	u32 count;

	mb = NULL;
	first = 0;
	vc = __osViGetCurrentContext();
	retrace = vc->retraceCount;
	if (retrace == 0)
		retrace = 1;
	dm = (OSDevMgr *)arg;
	while (TRUE)
	{
		osRecvMesg(dm->evtQueue, (OSMesg)&mb, OS_MESG_BLOCK);
		switch (mb->hdr.type)
		{
		case OS_MESG_TYPE_VRETRACE:
			__osViSwapContext();
			retrace--;
			if (retrace == 0)
			{
				vc = __osViGetCurrentContext();
				if (vc->msgq != NULL)
					osSendMesg(vc->msgq, vc->msg, OS_MESG_NOBLOCK);
				retrace = vc->retraceCount;
			}
			__osViIntrCount++;
			if (first)
			{

				count = osGetCount();
				__osCurrentTime = count;
				first = 0;
			}
			count = __osBaseCounter;
			__osBaseCounter = osGetCount();
			count = __osBaseCounter - count;
			__osCurrentTime = __osCurrentTime + count;
			break;
		case OS_MESG_TYPE_COUNTER:
			__osTimerInterrupt();
			break;
		}
	}
}


#else

#ifdef NONMATCHING
void osCreateViManager(OSPri pri)
{
}
static void viMgrMain(void *arg)
{
}
#else

/*vimgr asm VERSION_EU*/

.section .data
glabel __osViDevMgr
.word 0
glabel D_800269A4
.word 0
glabel D_800269A8
.word 0
glabel D_800269AC
.word 0
glabel D_800269B0
.word 0
glabel D_800269B4
.word 0
glabel D_800269B8
.word 0




.section .rodata


.section .bss
glabel viThread
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0

glabel viThreadStack
        #[4096]
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.section .bss
glabel viEventQueue
.word 0, 0, 0, 0, 0, 0

glabel viEventBuf
.word 0, 0, 0, 0, 0, 0

glabel viRetraceMsg
.word 0, 0, 0, 0, 0, 0

glabel viCounterMsg
.word 0, 0, 0, 0, 0, 0

glabel retrace
.half 0


glabel osCreateViManager
/* 0023E0 700017E0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0023E4 700017E4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0023E8 700017E8 3C108002 */  lui   $s0, %hi(__osViDevMgr) # $s0, 0x8002
/* 0023EC 700017EC 26100F90 */  addiu $s0, %lo(__osViDevMgr) # addiu $s0, $s0, 0xf90
/* 0023F0 700017F0 8E0E0000 */  lw    $t6, ($s0)
/* 0023F4 700017F4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0023F8 700017F8 AFA40030 */  sw    $a0, 0x30($sp)
/* 0023FC 700017FC 55C00052 */  bnezl $t6, .L70001948
/* 002400 70001800 8FBF0024 */   lw    $ra, 0x24($sp)
/* 002404 70001804 0C0034A0 */  jal   __osTimerServicesInit
/* 002408 70001808 00000000 */   nop   
/* 00240C 7000180C 3C048005 */  lui   $a0, %hi(viEventQueue) # $a0, 0x8005
/* 002410 70001810 3C058005 */  lui   $a1, %hi(viEventBuf) # $a1, 0x8005
/* 002414 70001814 24A52278 */  addiu $a1, %lo(viEventBuf) # addiu $a1, $a1, 0x2278
/* 002418 70001818 24842260 */  addiu $a0, %lo(viEventQueue) # addiu $a0, $a0, 0x2260
/* 00241C 7000181C 0C00310C */  jal   osCreateMesgQueue
/* 002420 70001820 24060005 */   li    $a2, 5
/* 002424 70001824 3C068005 */  lui   $a2, %hi(viRetraceMsg) # $a2, 0x8005
/* 002428 70001828 3C078005 */  lui   $a3, %hi(viCounterMsg) # $a3, 0x8005
/* 00242C 7000182C 24E722A8 */  addiu $a3, %lo(viCounterMsg) # addiu $a3, $a3, 0x22a8
/* 002430 70001830 24C62290 */  addiu $a2, %lo(viRetraceMsg) # addiu $a2, $a2, 0x2290
/* 002434 70001834 240F000D */  li    $t7, 13
/* 002438 70001838 2418000E */  li    $t8, 14
/* 00243C 7000183C 3C058005 */  lui   $a1, %hi(viEventQueue) # $a1, 0x8005
/* 002440 70001840 A4CF0000 */  sh    $t7, ($a2)
/* 002444 70001844 A0C00002 */  sb    $zero, 2($a2)
/* 002448 70001848 ACC00004 */  sw    $zero, 4($a2)
/* 00244C 7000184C A4F80000 */  sh    $t8, ($a3)
/* 002450 70001850 A0E00002 */  sb    $zero, 2($a3)
/* 002454 70001854 ACE00004 */  sw    $zero, 4($a3)
/* 002458 70001858 24A52260 */  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x2260
/* 00245C 7000185C 0C003194 */  jal   osSetEventMesg
/* 002460 70001860 24040007 */   li    $a0, 7
/* 002464 70001864 3C078005 */  lui   $a3, %hi(viCounterMsg)
/* 002468 70001868 3C058005 */  lui   $a1, %hi(viEventQueue) # $a1, 0x8005
/* 00246C 7000186C 24E622A8 */  addiu $a2, $a3, %lo(viCounterMsg)
/* 002470 70001870 24A52260 */  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x2260
/* 002474 70001874 0C003194 */  jal   osSetEventMesg
/* 002478 70001878 24040003 */   li    $a0, 3
/* 00247C 7000187C 2419FFFF */  li    $t9, -1
/* 002480 70001880 AFB90028 */  sw    $t9, 0x28($sp)
/* 002484 70001884 0C0035A0 */  jal   osGetThreadPri
/* 002488 70001888 00002025 */   move  $a0, $zero
/* 00248C 7000188C 8FA80030 */  lw    $t0, 0x30($sp)
/* 002490 70001890 00002025 */  move  $a0, $zero
/* 002494 70001894 0048082A */  slt   $at, $v0, $t0
/* 002498 70001898 10200003 */  beqz  $at, .L700018A8
/* 00249C 7000189C 01002825 */   move  $a1, $t0
/* 0024A0 700018A0 0C003158 */  jal   osSetThreadPri
/* 0024A4 700018A4 AFA20028 */   sw    $v0, 0x28($sp)
.L700018A8:
/* 0024A8 700018A8 0C0035A8 */  jal   __osDisableInt
/* 0024AC 700018AC 00000000 */   nop   
/* 0024B0 700018B0 8FAB0030 */  lw    $t3, 0x30($sp)
/* 0024B4 700018B4 3C038005 */  lui   $v1, %hi(viEventQueue) # $v1, 0x8005
/* 0024B8 700018B8 3C048005 */  lui   $a0, %hi(viThread) # $a0, 0x8005
/* 0024BC 700018BC 3C0A8005 */  lui   $t2, %hi(viEventQueue) # $t2, 0x8005
/* 0024C0 700018C0 24841FB0 */  addiu $a0, %lo(viThread) # addiu $a0, $a0, 0x1fb0
/* 0024C4 700018C4 24632260 */  addiu $v1, %lo(viEventQueue) # addiu $v1, $v1, 0x2260
/* 0024C8 700018C8 24090001 */  li    $t1, 1
/* 0024CC 700018CC 254A2260 */  addiu $t2, %lo(viEventQueue) # addiu $t2, $t2, 0x2260
/* 0024D0 700018D0 3C067000 */  lui   $a2, %hi(viMgrMain) # $a2, 0x7000
/* 0024D4 700018D4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0024D8 700018D8 AE090000 */  sw    $t1, ($s0)
/* 0024DC 700018DC AE040004 */  sw    $a0, 4($s0)
/* 0024E0 700018E0 AE030008 */  sw    $v1, 8($s0)
/* 0024E4 700018E4 AE03000C */  sw    $v1, 0xc($s0)
/* 0024E8 700018E8 AE000010 */  sw    $zero, 0x10($s0)
/* 0024EC 700018EC AE000014 */  sw    $zero, 0x14($s0)
/* 0024F0 700018F0 AE000018 */  sw    $zero, 0x18($s0)
/* 0024F4 700018F4 24C61958 */  addiu $a2, %lo(viMgrMain) # addiu $a2, $a2, 0x1958
/* 0024F8 700018F8 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0024FC 700018FC 00002825 */  move  $a1, $zero
/* 002500 70001900 02003825 */  move  $a3, $s0
/* 002504 70001904 0C003064 */  jal   osCreateThread
/* 002508 70001908 AFAB0014 */   sw    $t3, 0x14($sp)
/* 00250C 7000190C 0C0035B8 */  jal   __osViInit
/* 002510 70001910 00000000 */   nop   
/* 002514 70001914 3C048005 */  lui   $a0, %hi(viThread) # $a0, 0x8005
/* 002518 70001918 0C0030B8 */  jal   osStartThread
/* 00251C 7000191C 24841FB0 */   addiu $a0, %lo(viThread) # addiu $a0, $a0, 0x1fb0
/* 002520 70001920 0C0035B0 */  jal   __osRestoreInt
/* 002524 70001924 8FA4002C */   lw    $a0, 0x2c($sp)
/* 002528 70001928 8FAC0028 */  lw    $t4, 0x28($sp)
/* 00252C 7000192C 2401FFFF */  li    $at, -1
/* 002530 70001930 00002025 */  move  $a0, $zero
/* 002534 70001934 51810004 */  beql  $t4, $at, .L70001948
/* 002538 70001938 8FBF0024 */   lw    $ra, 0x24($sp)
/* 00253C 7000193C 0C003158 */  jal   osSetThreadPri
/* 002540 70001940 01802825 */   move  $a1, $t4
/* 002544 70001944 8FBF0024 */  lw    $ra, 0x24($sp)
.L70001948:
/* 002548 70001948 8FB00020 */  lw    $s0, 0x20($sp)
/* 00254C 7000194C 27BD0030 */  addiu $sp, $sp, 0x30
/* 002550 70001950 03E00008 */  jr    $ra
/* 002554 70001954 00000000 */   nop   

glabel viMgrMain
/* 002558 70001958 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 00255C 7000195C AFBF0034 */  sw    $ra, 0x34($sp)
/* 002560 70001960 AFB70030 */  sw    $s7, 0x30($sp)
/* 002564 70001964 0080B825 */  move  $s7, $a0
/* 002568 70001968 AFB6002C */  sw    $s6, 0x2c($sp)
/* 00256C 7000196C AFB50028 */  sw    $s5, 0x28($sp)
/* 002570 70001970 AFB40024 */  sw    $s4, 0x24($sp)
/* 002574 70001974 AFB30020 */  sw    $s3, 0x20($sp)
/* 002578 70001978 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00257C 7000197C AFB10018 */  sw    $s1, 0x18($sp)
/* 002580 70001980 AFB00014 */  sw    $s0, 0x14($sp)
/* 002584 70001984 0C0035FC */  jal   __osViGetCurrentContext
/* 002588 70001988 AFA00044 */   sw    $zero, 0x44($sp)
/* 00258C 7000198C 94430002 */  lhu   $v1, 2($v0)
/* 002590 70001990 3C018005 */  lui   $at, %hi(retrace) # $at, 0x8005
/* 002594 70001994 2416000E */  li    $s6, 14
/* 002598 70001998 14600004 */  bnez  $v1, .L700019AC
/* 00259C 7000199C A42322C0 */   sh    $v1, %lo(retrace)($at)
/* 0025A0 700019A0 24030001 */  li    $v1, 1
/* 0025A4 700019A4 3C018005 */  lui   $at, %hi(retrace) # $at, 0x8005
/* 0025A8 700019A8 A42322C0 */  sh    $v1, %lo(retrace)($at)
.L700019AC:
/* 0025AC 700019AC 3C138005 */  lui   $s3, %hi(__osViIntrCount) # $s3, 0x8005
/* 0025B0 700019B0 3C128005 */  lui   $s2, %hi(__osBaseCounter) # $s2, 0x8005
/* 0025B4 700019B4 3C118005 */  lui   $s1, %hi(__osCurrentTime) # $s1, 0x8005
/* 0025B8 700019B8 26317C80 */  addiu $s1, %lo(__osCurrentTime) # addiu $s1, $s1, 0x7c80
/* 0025BC 700019BC 26527C88 */  addiu $s2, %lo(__osBaseCounter) # addiu $s2, $s2, 0x7c88
/* 0025C0 700019C0 26737C8C */  addiu $s3, %lo(__osViIntrCount) # addiu $s3, $s3, 0x7c8c
/* 0025C4 700019C4 2415000D */  li    $s5, 13
/* 0025C8 700019C8 27B40044 */  addiu $s4, $sp, 0x44
.L700019CC:
/* 0025CC 700019CC 8EE4000C */  lw    $a0, 0xc($s7)
.L700019D0:
/* 0025D0 700019D0 02802825 */  move  $a1, $s4
/* 0025D4 700019D4 0C0031F4 */  jal   osRecvMesg
/* 0025D8 700019D8 24060001 */   li    $a2, 1
/* 0025DC 700019DC 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0025E0 700019E0 95C30000 */  lhu   $v1, ($t6)
/* 0025E4 700019E4 10750005 */  beq   $v1, $s5, .L700019FC
/* 0025E8 700019E8 00000000 */   nop   
/* 0025EC 700019EC 1076002A */  beq   $v1, $s6, .L70001A98
/* 0025F0 700019F0 00000000 */   nop   
/* 0025F4 700019F4 1000FFF6 */  b     .L700019D0
/* 0025F8 700019F8 8EE4000C */   lw    $a0, 0xc($s7)
.L700019FC:
/* 0025FC 700019FC 0C003600 */  jal   __osViSwapContext
/* 002600 70001A00 00000000 */   nop   
/* 002604 70001A04 3C038005 */  lui   $v1, %hi(retrace) # $v1, 0x8005
/* 002608 70001A08 946322C0 */  lhu   $v1, %lo(retrace)($v1)
/* 00260C 70001A0C 3C018005 */  lui   $at, %hi(retrace) # $at, 0x8005
/* 002610 70001A10 2463FFFF */  addiu $v1, $v1, -1
/* 002614 70001A14 306FFFFF */  andi  $t7, $v1, 0xffff
/* 002618 70001A18 15E0000E */  bnez  $t7, .L70001A54
/* 00261C 70001A1C A42F22C0 */   sh    $t7, %lo(retrace)($at)
/* 002620 70001A20 0C0035FC */  jal   __osViGetCurrentContext
/* 002624 70001A24 00000000 */   nop   
/* 002628 70001A28 8C580010 */  lw    $t8, 0x10($v0)
/* 00262C 70001A2C 00408025 */  move  $s0, $v0
/* 002630 70001A30 00003025 */  move  $a2, $zero
/* 002634 70001A34 53000005 */  beql  $t8, $zero, .L70001A4C
/* 002638 70001A38 96030002 */   lhu   $v1, 2($s0)
/* 00263C 70001A3C 8C440010 */  lw    $a0, 0x10($v0)
/* 002640 70001A40 0C003244 */  jal   osSendMesg
/* 002644 70001A44 8C450014 */   lw    $a1, 0x14($v0)
/* 002648 70001A48 96030002 */  lhu   $v1, 2($s0)
.L70001A4C:
/* 00264C 70001A4C 3C018005 */  lui   $at, %hi(retrace) # $at, 0x8005
/* 002650 70001A50 A42322C0 */  sh    $v1, %lo(retrace)($at)
.L70001A54:
/* 002654 70001A54 8E790000 */  lw    $t9, ($s3)
/* 002658 70001A58 8E500000 */  lw    $s0, ($s2)
/* 00265C 70001A5C 27280001 */  addiu $t0, $t9, 1
/* 002660 70001A60 0C003190 */  jal   osGetCount
/* 002664 70001A64 AE680000 */   sw    $t0, ($s3)
/* 002668 70001A68 8E2D0004 */  lw    $t5, 4($s1)
/* 00266C 70001A6C 00508023 */  subu  $s0, $v0, $s0
/* 002670 70001A70 8E2C0000 */  lw    $t4, ($s1)
/* 002674 70001A74 020D7821 */  addu  $t7, $s0, $t5
/* 002678 70001A78 240A0000 */  li    $t2, 0
/* 00267C 70001A7C 01ED082B */  sltu  $at, $t7, $t5
/* 002680 70001A80 002A7021 */  addu  $t6, $at, $t2
/* 002684 70001A84 01CC7021 */  addu  $t6, $t6, $t4
/* 002688 70001A88 AE420000 */  sw    $v0, ($s2)
/* 00268C 70001A8C AE2E0000 */  sw    $t6, ($s1)
/* 002690 70001A90 1000FFCE */  b     .L700019CC
/* 002694 70001A94 AE2F0004 */   sw    $t7, 4($s1)
.L70001A98:
/* 002698 70001A98 0C0034C3 */  jal   __osTimerInterrupt
/* 00269C 70001A9C 00000000 */   nop   
/* 0026A0 70001AA0 1000FFCB */  b     .L700019D0
/* 0026A4 70001AA4 8EE4000C */   lw    $a0, 0xc($s7)
/* 0026A8 70001AA8 00000000 */  nop   
/* 0026AC 70001AAC 00000000 */  nop   
/* 0026B0 70001AB0 00000000 */  nop   
/* 0026B4 70001AB4 00000000 */  nop   
/* 0026B8 70001AB8 00000000 */  nop   
/* 0026BC 70001ABC 00000000 */  nop   
/* 0026C0 70001AC0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0026C4 70001AC4 8FB00014 */  lw    $s0, 0x14($sp)
/* 0026C8 70001AC8 8FB10018 */  lw    $s1, 0x18($sp)
/* 0026CC 70001ACC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0026D0 70001AD0 8FB30020 */  lw    $s3, 0x20($sp)
/* 0026D4 70001AD4 8FB40024 */  lw    $s4, 0x24($sp)
/* 0026D8 70001AD8 8FB50028 */  lw    $s5, 0x28($sp)
/* 0026DC 70001ADC 8FB6002C */  lw    $s6, 0x2c($sp)
/* 0026E0 70001AE0 8FB70030 */  lw    $s7, 0x30($sp)
/* 0026E4 70001AE4 03E00008 */  jr    $ra
/* 0026E8 70001AE8 27BD0050 */   addiu $sp, $sp, 0x50

#endif

#endif