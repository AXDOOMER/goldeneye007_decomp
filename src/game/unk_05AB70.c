#include "ultra64.h"










#ifdef NONMATCHING
void sub_GAME_7F05AB70(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05AB70
/* 08F6A0 7F05AB70 28817FE0 */  slti  $at, $a0, 0x7fe0
/* 08F6A4 7F05AB74 14200006 */  bnez  $at, .L7F05AB90
/* 08F6A8 7F05AB78 24030007 */   li    $v1, 7
/* 08F6AC 7F05AB7C 3C068003 */  lui   $a2, %hi(table_3) # $a2, 0x8003
/* 08F6B0 7F05AB80 24050003 */  li    $a1, 3
/* 08F6B4 7F05AB84 24C6241C */  addiu $a2, %lo(table_3) # addiu $a2, $a2, 0x241c
/* 08F6B8 7F05AB88 1000000D */  b     .L7F05ABC0
/* 08F6BC 7F05AB8C 24848020 */   addiu $a0, $a0, -0x7fe0
.L7F05AB90:
/* 08F6C0 7F05AB90 28817800 */  slti  $at, $a0, 0x7800
/* 08F6C4 7F05AB94 14200007 */  bnez  $at, .L7F05ABB4
/* 08F6C8 7F05AB98 240301FF */   li    $v1, 511
/* 08F6CC 7F05AB9C 3C068003 */  lui   $a2, %hi(table_2) # $a2, 0x8003
/* 08F6D0 7F05ABA0 2403001F */  li    $v1, 31
/* 08F6D4 7F05ABA4 24050005 */  li    $a1, 5
/* 08F6D8 7F05ABA8 24C6239C */  addiu $a2, %lo(table_2) # addiu $a2, $a2, 0x239c
/* 08F6DC 7F05ABAC 10000004 */  b     .L7F05ABC0
/* 08F6E0 7F05ABB0 24848800 */   addiu $a0, $a0, -0x7800
.L7F05ABB4:
/* 08F6E4 7F05ABB4 3C068003 */  lui   $a2, %hi(table_1) # $a2, 0x8003
/* 08F6E8 7F05ABB8 24050009 */  li    $a1, 9
/* 08F6EC 7F05ABBC 24C62320 */  addiu $a2, %lo(table_1) # addiu $a2, $a2, 0x2320
.L7F05ABC0:
/* 08F6F0 7F05ABC0 00A47007 */  srav  $t6, $a0, $a1
/* 08F6F4 7F05ABC4 000E7840 */  sll   $t7, $t6, 1
/* 08F6F8 7F05ABC8 00CF4021 */  addu  $t0, $a2, $t7
/* 08F6FC 7F05ABCC 95070000 */  lhu   $a3, ($t0)
/* 08F700 7F05ABD0 95090002 */  lhu   $t1, 2($t0)
/* 08F704 7F05ABD4 0083C824 */  and   $t9, $a0, $v1
/* 08F708 7F05ABD8 00E9C023 */  subu  $t8, $a3, $t1
/* 08F70C 7F05ABDC 03190019 */  multu $t8, $t9
/* 08F710 7F05ABE0 00005012 */  mflo  $t2
/* 08F714 7F05ABE4 00AA5807 */  srav  $t3, $t2, $a1
/* 08F718 7F05ABE8 03E00008 */  jr    $ra
/* 08F71C 7F05ABEC 00EB1023 */   subu  $v0, $a3, $t3
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05ABF0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05ABF0
/* 08F720 7F05ABF0 00042C00 */  sll   $a1, $a0, 0x10
/* 08F724 7F05ABF4 00057403 */  sra   $t6, $a1, 0x10
/* 08F728 7F05ABF8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08F72C 7F05ABFC AFBF0014 */  sw    $ra, 0x14($sp)
/* 08F730 7F05AC00 AFA40018 */  sw    $a0, 0x18($sp)
/* 08F734 7F05AC04 05C00003 */  bltz  $t6, .L7F05AC14
/* 08F738 7F05AC08 01C02825 */   move  $a1, $t6
/* 08F73C 7F05AC0C 10000002 */  b     .L7F05AC18
/* 08F740 7F05AC10 01C02025 */   move  $a0, $t6
.L7F05AC14:
/* 08F744 7F05AC14 00052023 */  negu  $a0, $a1
.L7F05AC18:
/* 08F748 7F05AC18 0FC16ADC */  jal   sub_GAME_7F05AB70
/* 08F74C 7F05AC1C A7A5001A */   sh    $a1, 0x1a($sp)
/* 08F750 7F05AC20 87A5001A */  lh    $a1, 0x1a($sp)
/* 08F754 7F05AC24 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08F758 7F05AC28 00402025 */  move  $a0, $v0
/* 08F75C 7F05AC2C 04A10003 */  bgez  $a1, .L7F05AC3C
/* 08F760 7F05AC30 27BD0018 */   addiu $sp, $sp, 0x18
/* 08F764 7F05AC34 340FFFFF */  li    $t7, 65535
/* 08F768 7F05AC38 01E22023 */  subu  $a0, $t7, $v0
.L7F05AC3C:
/* 08F76C 7F05AC3C 03E00008 */  jr    $ra
/* 08F770 7F05AC40 3082FFFF */   andi  $v0, $a0, 0xffff
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05AC44(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05AC44
/* 08F774 7F05AC44 00042C00 */  sll   $a1, $a0, 0x10
/* 08F778 7F05AC48 00057403 */  sra   $t6, $a1, 0x10
/* 08F77C 7F05AC4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08F780 7F05AC50 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08F784 7F05AC54 AFA40018 */  sw    $a0, 0x18($sp)
/* 08F788 7F05AC58 05C00003 */  bltz  $t6, .L7F05AC68
/* 08F78C 7F05AC5C 01C02825 */   move  $a1, $t6
/* 08F790 7F05AC60 10000002 */  b     .L7F05AC6C
/* 08F794 7F05AC64 01C02025 */   move  $a0, $t6
.L7F05AC68:
/* 08F798 7F05AC68 00052023 */  negu  $a0, $a1
.L7F05AC6C:
/* 08F79C 7F05AC6C 0FC16ADC */  jal   sub_GAME_7F05AB70
/* 08F7A0 7F05AC70 A7A5001A */   sh    $a1, 0x1a($sp)
/* 08F7A4 7F05AC74 87A5001A */  lh    $a1, 0x1a($sp)
/* 08F7A8 7F05AC78 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08F7AC 7F05AC7C 24018000 */  li    $at, -32768
/* 08F7B0 7F05AC80 04A00004 */  bltz  $a1, .L7F05AC94
/* 08F7B4 7F05AC84 27BD0018 */   addiu $sp, $sp, 0x18
/* 08F7B8 7F05AC88 240F7FFF */  li    $t7, 32767
/* 08F7BC 7F05AC8C 10000002 */  b     .L7F05AC98
/* 08F7C0 7F05AC90 01E22023 */   subu  $a0, $t7, $v0
.L7F05AC94:
/* 08F7C4 7F05AC94 00412021 */  addu  $a0, $v0, $at
.L7F05AC98:
/* 08F7C8 7F05AC98 00041400 */  sll   $v0, $a0, 0x10
/* 08F7CC 7F05AC9C 0002C403 */  sra   $t8, $v0, 0x10
/* 08F7D0 7F05ACA0 03E00008 */  jr    $ra
/* 08F7D4 7F05ACA4 03001025 */   move  $v0, $t8
)
#endif

   

