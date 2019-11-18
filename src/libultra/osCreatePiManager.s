# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osCreatePiManager
/* 0151B0 700145B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0151B4 700145B4 3C0E8002 */  lui   $t6, %hi(__osPiDevMgr) 
/* 0151B8 700145B8 8DCE7790 */  lw    $t6, %lo(__osPiDevMgr)($t6)
/* 0151BC 700145BC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0151C0 700145C0 AFA40030 */  sw    $a0, 0x30($sp)
/* 0151C4 700145C4 AFA50034 */  sw    $a1, 0x34($sp)
/* 0151C8 700145C8 AFA60038 */  sw    $a2, 0x38($sp)
/* 0151CC 700145CC 15C00056 */  bnez  $t6, .L70014728
/* 0151D0 700145D0 AFA7003C */   sw    $a3, 0x3c($sp)
/* 0151D4 700145D4 8FA40034 */  lw    $a0, 0x34($sp)
/* 0151D8 700145D8 8FA50038 */  lw    $a1, 0x38($sp)
/* 0151DC 700145DC 0C0035B4 */  jal   osCreateMesgQueue
/* 0151E0 700145E0 8FA6003C */   lw    $a2, 0x3c($sp)
/* 0151E4 700145E4 3C048006 */  lui   $a0, %hi(pieventQueue)
/* 0151E8 700145E8 3C058006 */  lui   $a1, %hi(piEventBuf)
/* 0151EC 700145EC 24A57C98 */  addiu $a1, %lo(piEventBuf) # addiu $a1, $a1, 0x7c98
/* 0151F0 700145F0 24847C80 */  addiu $a0, %lo(pieventQueue) # addiu $a0, $a0, 0x7c80
/* 0151F4 700145F4 0C0035B4 */  jal   osCreateMesgQueue
/* 0151F8 700145F8 24060001 */   li    $a2, 1
/* 0151FC 700145FC 3C0F8003 */  lui   $t7, %hi(__osPiAccessQueueEnabled) 
/* 015200 70014600 8DEF82E0 */  lw    $t7, %lo(__osPiAccessQueueEnabled)($t7)
/* 015204 70014604 15E00003 */  bnez  $t7, .L70014614
/* 015208 70014608 00000000 */   nop   
/* 01520C 7001460C 0C0075C4 */  jal   __osPiCreateAccessQueue
/* 015210 70014610 00000000 */   nop   
.L70014614:
/* 015214 70014614 3C058006 */  lui   $a1, %hi(pieventQueue)
/* 015218 70014618 3C062222 */  lui   $a2, (0x22222222 >> 16) # lui $a2, 0x2222
/* 01521C 7001461C 34C62222 */  ori   $a2, (0x22222222 & 0xFFFF) # ori $a2, $a2, 0x2222
/* 015220 70014620 24A57C80 */  addiu $a1, %lo(pieventQueue) # addiu $a1, $a1, 0x7c80
/* 015224 70014624 0C003714 */  jal   osSetEventMesg
/* 015228 70014628 24040008 */   li    $a0, 8
/* 01522C 7001462C 2418FFFF */  li    $t8, -1
/* 015230 70014630 AFB80028 */  sw    $t8, 0x28($sp)
/* 015234 70014634 0C00628C */  jal   osGetThreadPri
/* 015238 70014638 00002025 */   move  $a0, $zero
/* 01523C 7001463C AFA20024 */  sw    $v0, 0x24($sp)
/* 015240 70014640 8FB90024 */  lw    $t9, 0x24($sp)
/* 015244 70014644 8FA80030 */  lw    $t0, 0x30($sp)
/* 015248 70014648 0328082A */  slt   $at, $t9, $t0
/* 01524C 7001464C 10200005 */  beqz  $at, .L70014664
/* 015250 70014650 00000000 */   nop   
/* 015254 70014654 AFB90028 */  sw    $t9, 0x28($sp)
/* 015258 70014658 00002025 */  move  $a0, $zero
/* 01525C 7001465C 0C003600 */  jal   osSetThreadPri
/* 015260 70014660 01002825 */   move  $a1, $t0
.L70014664:
/* 015264 70014664 0C00617C */  jal   __osDisableInt
/* 015268 70014668 00000000 */   nop   
/* 01526C 7001466C 3C018002 */  lui   $at, %hi(__osPiDevMgr.cmdQueue)
/* 015270 70014670 8FAB0034 */  lw    $t3, 0x34($sp)
/* 015274 70014674 3C0A8006 */  lui   $t2, %hi(piThread) 
/* 015278 70014678 3C0C8006 */  lui   $t4, %hi(pieventQueue) 
/* 01527C 7001467C 24090001 */  li    $t1, 1
/* 015280 70014680 254A6AD0 */  addiu $t2, %lo(piThread) # addiu $t2, $t2, 0x6ad0
/* 015284 70014684 258C7C80 */  addiu $t4, %lo(pieventQueue) # addiu $t4, $t4, 0x7c80
/* 015288 70014688 AC297790 */  sw    $t1, %lo(__osPiDevMgr)($at)
/* 01528C 7001468C AC2A7794 */  sw    $t2, %lo(__osPiDevMgr.thread)($at)
/* 015290 70014690 AC2C779C */  sw    $t4, %lo(__osPiDevMgr.evtQueue)($at)
/* 015294 70014694 3C188006 */  lui   $t8, %hi(piThreadStack)
/* 015298 70014698 AC2B7798 */  sw    $t3, %lo(__osPiDevMgr.cmdQueue)($at)
/* 01529C 7001469C 8FA80030 */  lw    $t0, 0x30($sp)
/* 0152A0 700146A0 3C018002 */  lui   $at, %hi(__osPiDevMgr.edma)
/* 0152A4 700146A4 3C0D8007 */  lui   $t5, %hi(__osPiAccessQueue) 
/* 0152A8 700146A8 3C0E7001 */  lui   $t6, %hi(osPiRawStartDma) # $t6, 0x7001
/* 0152AC 700146AC 3C0F7002 */  lui   $t7, %hi(osEPiRawStartDma) # $t7, 0x7002
/* 0152B0 700146B0 27186C80 */  addiu $t8, $t8, %lo(piThreadStack)
/* 0152B4 700146B4 25AD8FE8 */  addiu $t5, %lo(__osPiAccessQueue) # addiu $t5, $t5, -0x7018
/* 0152B8 700146B8 25CECF90 */  addiu $t6, %lo(osPiRawStartDma) # addiu $t6, $t6, -0x3070
/* 0152BC 700146BC 25EFE530 */  addiu $t7, %lo(osEPiRawStartDma) # addiu $t7, $t7, -0x1ad0
/* 0152C0 700146C0 27191000 */  addiu $t9, $t8, 0x1000
/* 0152C4 700146C4 3C067002 */  lui   $a2, %hi(__osDevMgrMain) # $a2, 0x7002
/* 0152C8 700146C8 3C078002 */  lui   $a3, %hi(__osPiDevMgr)
/* 0152CC 700146CC AFA2002C */  sw    $v0, 0x2c($sp)
/* 0152D0 700146D0 AC2D77A0 */  sw    $t5, %lo(__osPiDevMgr.acsQueue)($at)
/* 0152D4 700146D4 AC2E77A4 */  sw    $t6, %lo(__osPiDevMgr.dma)($at)
/* 0152D8 700146D8 AC2F77A8 */  sw    $t7, %lo(__osPiDevMgr.edma)($at)
/* 0152DC 700146DC 24E77790 */  addiu $a3, %lo(__osPiDevMgr) # addiu $a3, $a3, 0x7790
/* 0152E0 700146E0 24C6E610 */  addiu $a2, %lo(__osDevMgrMain) # addiu $a2, $a2, -0x19f0
/* 0152E4 700146E4 AFB90010 */  sw    $t9, 0x10($sp)
/* 0152E8 700146E8 01402025 */  move  $a0, $t2
/* 0152EC 700146EC 00002825 */  move  $a1, $zero
/* 0152F0 700146F0 0C00350C */  jal   osCreateThread
/* 0152F4 700146F4 AFA80014 */   sw    $t0, 0x14($sp)
/* 0152F8 700146F8 3C048006 */  lui   $a0, %hi(piThread)
/* 0152FC 700146FC 0C003560 */  jal   osStartThread
/* 015300 70014700 24846AD0 */   addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x6ad0
/* 015304 70014704 0C006184 */  jal   __osRestoreInt
/* 015308 70014708 8FA4002C */   lw    $a0, 0x2c($sp)
/* 01530C 7001470C 8FA90028 */  lw    $t1, 0x28($sp)
/* 015310 70014710 2401FFFF */  li    $at, -1
/* 015314 70014714 11210004 */  beq   $t1, $at, .L70014728
/* 015318 70014718 00000000 */   nop   
/* 01531C 7001471C 00002025 */  move  $a0, $zero
/* 015320 70014720 0C003600 */  jal   osSetThreadPri
/* 015324 70014724 01202825 */   move  $a1, $t1
.L70014728:
/* 015328 70014728 8FBF001C */  lw    $ra, 0x1c($sp)
/* 01532C 7001472C 27BD0030 */  addiu $sp, $sp, 0x30
/* 015330 70014730 03E00008 */  jr    $ra
/* 015334 70014734 00000000 */   nop   



.section .data
glabel __osPiDevMgr
glabel __osPiDevMgr.active
.word 0
glabel __osPiDevMgr.thread
.word 0
glabel __osPiDevMgr.cmdQueue
.word 0
glabel __osPiDevMgr.evtQueue
.word 0
glabel __osPiDevMgr.acsQueue
.word 0
glabel __osPiDevMgr.dma
.word 0
glabel __osPiDevMgr.edma
.word 0


glabel __osPiTable
.word 0

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
