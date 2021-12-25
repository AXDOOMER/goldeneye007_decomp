#include <os_internal.h>
#include "src/libultra/io/piint.h"

OSDevMgr __osPiDevMgr = {0};
OSPiHandle *__osPiTable = NULL;


#ifndef VERSION_EU
static OSThread piThread;
static char piThreadStack[OS_PIM_STACKSIZE];
static OSMesgQueue piEventQueue;
static OSMesg piEventBuf[1];
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt)
{
	u32 savedMask;
	OSPri oldPri;
	OSPri myPri;
	if (!__osPiDevMgr.active)
	{
		osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
		osCreateMesgQueue(&piEventQueue, (OSMesg*)&piEventBuf, 1);
		if (!__osPiAccessQueueEnabled)
			__osPiCreateAccessQueue();
		osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg)0x22222222);
		oldPri = -1;
		myPri = osGetThreadPri(NULL);
		if (myPri < pri)
		{
			oldPri = myPri;
			osSetThreadPri(NULL, pri);
		}
		savedMask = __osDisableInt();
		__osPiDevMgr.active = 1;
		__osPiDevMgr.thread = &piThread;
		__osPiDevMgr.cmdQueue = cmdQ;
		__osPiDevMgr.evtQueue = &piEventQueue;
		__osPiDevMgr.acsQueue = &__osPiAccessQueue;
		__osPiDevMgr.dma = osPiRawStartDma;
		__osPiDevMgr.edma = osEPiRawStartDma;
		osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, &piThreadStack[OS_PIM_STACKSIZE], pri);
		osStartThread(&piThread);
		__osRestoreInt(savedMask);
		if (oldPri != -1)
		{
			osSetThreadPri(NULL, oldPri);
		}
	}
}
#else

#ifdef NONMATCHING
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt)
{
}
#else
GLOBAL_ASM(
.section .bss
glabel piThread
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0

glabel piThreadStack
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0

glabel pieventQueue
.word 0, 0, 0, 0, 0, 0

glabel piEventBuf
.word 0, 0


.text
glabel osCreatePiManager
/* 0026F0 70001AF0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0026F4 70001AF4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0026F8 70001AF8 3C108002 */  lui   $s0, %hi(__osPiDevMgr) # $s0, 0x8002
/* 0026FC 70001AFC 26100FB0 */  addiu $s0, %lo(__osPiDevMgr) # addiu $s0, $s0, 0xfb0
/* 002700 70001B00 8E0E0000 */  lw    $t6, ($s0)
/* 002704 70001B04 AFBF0024 */  sw    $ra, 0x24($sp)
/* 002708 70001B08 AFA40030 */  sw    $a0, 0x30($sp)
/* 00270C 70001B0C AFA50034 */  sw    $a1, 0x34($sp)
/* 002710 70001B10 15C0004E */  bnez  $t6, .L70001C4C
/* 002714 70001B14 AFA60038 */   sw    $a2, 0x38($sp)
/* 002718 70001B18 00A02025 */  move  $a0, $a1
/* 00271C 70001B1C 00C02825 */  move  $a1, $a2
/* 002720 70001B20 0C00310C */  jal   osCreateMesgQueue
/* 002724 70001B24 00E03025 */   move  $a2, $a3
/* 002728 70001B28 3C048005 */  lui   $a0, %hi(pieventQueue) # $a0, 0x8005
/* 00272C 70001B2C 3C058005 */  lui   $a1, %hi(piEventBuf) # $a1, 0x8005
/* 002730 70001B30 24A52598 */  addiu $a1, %lo(piEventBuf) # addiu $a1, $a1, 0x2598
/* 002734 70001B34 24842580 */  addiu $a0, %lo(pieventQueue) # addiu $a0, $a0, 0x2580
/* 002738 70001B38 0C00310C */  jal   osCreateMesgQueue
/* 00273C 70001B3C 24060001 */   li    $a2, 1
/* 002740 70001B40 3C0F8002 */  lui   $t7, %hi(__osPiAccessQueueEnabled) # $t7, 0x8002
/* 002744 70001B44 8DEF31D0 */  lw    $t7, %lo(__osPiAccessQueueEnabled)($t7)
/* 002748 70001B48 15E00003 */  bnez  $t7, .L70001B58
/* 00274C 70001B4C 00000000 */   nop   
/* 002750 70001B50 0C0036D8 */  jal   __osPiCreateAccessQueue
/* 002754 70001B54 00000000 */   nop   
.L70001B58:
/* 002758 70001B58 3C058005 */  lui   $a1, %hi(pieventQueue) # $a1, 0x8005
/* 00275C 70001B5C 3C062222 */  lui   $a2, (0x22222222 >> 16) # lui $a2, 0x2222
/* 002760 70001B60 34C62222 */  ori   $a2, (0x22222222 & 0xFFFF) # ori $a2, $a2, 0x2222
/* 002764 70001B64 24A52580 */  addiu $a1, %lo(pieventQueue) # addiu $a1, $a1, 0x2580
/* 002768 70001B68 0C003194 */  jal   osSetEventMesg
/* 00276C 70001B6C 24040008 */   li    $a0, 8
/* 002770 70001B70 2418FFFF */  li    $t8, -1
/* 002774 70001B74 AFB80028 */  sw    $t8, 0x28($sp)
/* 002778 70001B78 0C0035A0 */  jal   osGetThreadPri
/* 00277C 70001B7C 00002025 */   move  $a0, $zero
/* 002780 70001B80 8FB90030 */  lw    $t9, 0x30($sp)
/* 002784 70001B84 00002025 */  move  $a0, $zero
/* 002788 70001B88 0059082A */  slt   $at, $v0, $t9
/* 00278C 70001B8C 10200003 */  beqz  $at, .L70001B9C
/* 002790 70001B90 03202825 */   move  $a1, $t9
/* 002794 70001B94 0C003158 */  jal   osSetThreadPri
/* 002798 70001B98 AFA20028 */   sw    $v0, 0x28($sp)
.L70001B9C:
/* 00279C 70001B9C 0C0035A8 */  jal   __osDisableInt
/* 0027A0 70001BA0 00000000 */   nop   
/* 0027A4 70001BA4 8FA90034 */  lw    $t1, 0x34($sp)
/* 0027A8 70001BA8 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0027AC 70001BAC 3C048005 */  lui   $a0, %hi(piThread) # $a0, 0x8005
/* 0027B0 70001BB0 3C0A8005 */  lui   $t2, %hi(pieventQueue) # $t2, 0x8005
/* 0027B4 70001BB4 3C0B8005 */  lui   $t3, %hi(__osPiAccessQueue) # $t3, 0x8005
/* 0027B8 70001BB8 3C0C7001 */  lui   $t4, %hi(osPiRawStartDma) # $t4, 0x7001
/* 0027BC 70001BBC 3C0D7001 */  lui   $t5, %hi(osEPiRawStartDma) # $t5, 0x7001
/* 0027C0 70001BC0 3C0E8005 */  lui   $t6, %hi(pieventQueue) # $t6, 0x8005
/* 0027C4 70001BC4 248422D0 */  addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x22d0
/* 0027C8 70001BC8 24080001 */  li    $t0, 1
/* 0027CC 70001BCC 254A2580 */  addiu $t2, %lo(pieventQueue) # addiu $t2, $t2, 0x2580
/* 0027D0 70001BD0 256B7CA8 */  addiu $t3, %lo(__osPiAccessQueue) # addiu $t3, $t3, 0x7ca8
/* 0027D4 70001BD4 258CBCF0 */  addiu $t4, %lo(osPiRawStartDma) # addiu $t4, $t4, -0x4310
/* 0027D8 70001BD8 25ADDC20 */  addiu $t5, %lo(osEPiRawStartDma) # addiu $t5, $t5, -0x23e0
/* 0027DC 70001BDC 25CE2580 */  addiu $t6, %lo(pieventQueue) # addiu $t6, $t6, 0x2580
/* 0027E0 70001BE0 3C067001 */  lui   $a2, %hi(__osDevMgrMain) # $a2, 0x7001
/* 0027E4 70001BE4 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0027E8 70001BE8 AE080000 */  sw    $t0, ($s0)
/* 0027EC 70001BEC AE040004 */  sw    $a0, 4($s0)
/* 0027F0 70001BF0 AE0A000C */  sw    $t2, 0xc($s0)
/* 0027F4 70001BF4 AE0B0010 */  sw    $t3, 0x10($s0)
/* 0027F8 70001BF8 AE0C0014 */  sw    $t4, 0x14($s0)
/* 0027FC 70001BFC AE0D0018 */  sw    $t5, 0x18($s0)
/* 002800 70001C00 24C6DD00 */  addiu $a2, %lo(__osDevMgrMain) # addiu $a2, $a2, -0x2300
/* 002804 70001C04 AFAE0010 */  sw    $t6, 0x10($sp)
/* 002808 70001C08 00002825 */  move  $a1, $zero
/* 00280C 70001C0C 02003825 */  move  $a3, $s0
/* 002810 70001C10 AE090008 */  sw    $t1, 8($s0)
/* 002814 70001C14 0C003064 */  jal   osCreateThread
/* 002818 70001C18 AFAF0014 */   sw    $t7, 0x14($sp)
/* 00281C 70001C1C 3C048005 */  lui   $a0, %hi(piThread) # $a0, 0x8005
/* 002820 70001C20 0C0030B8 */  jal   osStartThread
/* 002824 70001C24 248422D0 */   addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x22d0
/* 002828 70001C28 0C0035B0 */  jal   __osRestoreInt
/* 00282C 70001C2C 8FA4002C */   lw    $a0, 0x2c($sp)
/* 002830 70001C30 8FB80028 */  lw    $t8, 0x28($sp)
/* 002834 70001C34 2401FFFF */  li    $at, -1
/* 002838 70001C38 00002025 */  move  $a0, $zero
/* 00283C 70001C3C 53010004 */  beql  $t8, $at, .L70001C50
/* 002840 70001C40 8FBF0024 */   lw    $ra, 0x24($sp)
/* 002844 70001C44 0C003158 */  jal   osSetThreadPri
/* 002848 70001C48 03002825 */   move  $a1, $t8
.L70001C4C:
/* 00284C 70001C4C 8FBF0024 */  lw    $ra, 0x24($sp)
.L70001C50:
/* 002850 70001C50 8FB00020 */  lw    $s0, 0x20($sp)
/* 002854 70001C54 27BD0030 */  addiu $sp, $sp, 0x30
/* 002858 70001C58 03E00008 */  jr    $ra
/* 00285C 70001C5C 00000000 */   nop   
)
#endif

#endif
