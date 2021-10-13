#include "ultra64.h"
#include "memp.h"
#include "game/objecthandler.h"

//newfile per EU
#ifdef NONMATCHING
void sub_GAME_7F06C060(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C060
/* 0A0B90 7F06C060 84A30014 */  lh    $v1, 0x14($a1)
/* 0A0B94 7F06C064 28620001 */  slti  $v0, $v1, 1
/* 0A0B98 7F06C068 14400008 */  bnez  $v0, .L7F06C08C
/* 0A0B9C 7F06C06C 00000000 */   nop   
/* 0A0BA0 7F06C070 8C820010 */  lw    $v0, 0x10($a0)
/* 0A0BA4 7F06C074 0002702B */  sltu  $t6, $zero, $v0
/* 0A0BA8 7F06C078 11C00004 */  beqz  $t6, .L7F06C08C
/* 0A0BAC 7F06C07C 01C01025 */   move  $v0, $t6
/* 0A0BB0 7F06C080 848F0002 */  lh    $t7, 2($a0)
/* 0A0BB4 7F06C084 01E3102A */  slt   $v0, $t7, $v1
/* 0A0BB8 7F06C088 38420001 */  xori  $v0, $v0, 1
.L7F06C08C:
/* 0A0BBC 7F06C08C 03E00008 */  jr    $ra
/* 0A0BC0 7F06C090 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void get_obj_instance_controller_for_header(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_obj_instance_controller_for_header
/* 0A0BC4 7F06C094 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0A0BC8 7F06C098 3C0F8003 */  lui   $t7, %hi(D_80036078) 
/* 0A0BCC 7F06C09C 8DEF6078 */  lw    $t7, %lo(D_80036078)($t7)
/* 0A0BD0 7F06C0A0 AFB60030 */  sw    $s6, 0x30($sp)
/* 0A0BD4 7F06C0A4 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0A0BD8 7F06C0A8 240EFFFF */  li    $t6, -1
/* 0A0BDC 7F06C0AC 0080A825 */  move  $s5, $a0
/* 0A0BE0 7F06C0B0 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0A0BE4 7F06C0B4 AFB40028 */  sw    $s4, 0x28($sp)
/* 0A0BE8 7F06C0B8 AFB30024 */  sw    $s3, 0x24($sp)
/* 0A0BEC 7F06C0BC AFB20020 */  sw    $s2, 0x20($sp)
/* 0A0BF0 7F06C0C0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0A0BF4 7F06C0C4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A0BF8 7F06C0C8 0000B025 */  move  $s6, $zero
/* 0A0BFC 7F06C0CC AFA00040 */  sw    $zero, 0x40($sp)
/* 0A0C00 7F06C0D0 11E00025 */  beqz  $t7, .L7F06C168
/* 0A0C04 7F06C0D4 A7AE003E */   sh    $t6, 0x3e($sp)
/* 0A0C08 7F06C0D8 3C148003 */  lui   $s4, %hi(D_80036074)
/* 0A0C0C 7F06C0DC 26946074 */  addiu $s4, %lo(D_80036074) # addiu $s4, $s4, 0x6074
/* 0A0C10 7F06C0E0 8E840000 */  lw    $a0, ($s4)
/* 0A0C14 7F06C0E4 00001025 */  move  $v0, $zero
/* 0A0C18 7F06C0E8 3C068008 */  lui   $a2, %hi(ptr_allocation_1)
/* 0A0C1C 7F06C0EC 2484FFE2 */  addiu $a0, $a0, -0x1e
/* 0A0C20 7F06C0F0 1880000C */  blez  $a0, .L7F06C124
/* 0A0C24 7F06C0F4 24050004 */   li    $a1, 4
/* 0A0C28 7F06C0F8 8CC69934 */  lw    $a2, %lo(ptr_allocation_1)($a2)
/* 0A0C2C 7F06C0FC 00C01825 */  move  $v1, $a2
.L7F06C100:
/* 0A0C30 7F06C100 8C780008 */  lw    $t8, 8($v1)
/* 0A0C34 7F06C104 17000003 */  bnez  $t8, .L7F06C114
/* 0A0C38 7F06C108 0002C940 */   sll   $t9, $v0, 5
/* 0A0C3C 7F06C10C 10000005 */  b     .L7F06C124
/* 0A0C40 7F06C110 0326B021 */   addu  $s6, $t9, $a2
.L7F06C114:
/* 0A0C44 7F06C114 24420001 */  addiu $v0, $v0, 1
/* 0A0C48 7F06C118 0044082A */  slt   $at, $v0, $a0
/* 0A0C4C 7F06C11C 1420FFF8 */  bnez  $at, .L7F06C100
/* 0A0C50 7F06C120 24630020 */   addiu $v1, $v1, 0x20
.L7F06C124:
/* 0A0C54 7F06C124 56C00005 */  bnezl $s6, .L7F06C13C
/* 0A0C58 7F06C128 86A20014 */   lh    $v0, 0x14($s5)
/* 0A0C5C 7F06C12C 0C0025C8 */  jal   mempAllocBytesInBank
/* 0A0C60 7F06C130 24040020 */   li    $a0, 32
/* 0A0C64 7F06C134 0040B025 */  move  $s6, $v0
/* 0A0C68 7F06C138 86A20014 */  lh    $v0, 0x14($s5)
.L7F06C13C:
/* 0A0C6C 7F06C13C 24050004 */  li    $a1, 4
/* 0A0C70 7F06C140 1840002A */  blez  $v0, .L7F06C1EC
/* 0A0C74 7F06C144 00022080 */   sll   $a0, $v0, 2
/* 0A0C78 7F06C148 2484000F */  addiu $a0, $a0, 0xf
/* 0A0C7C 7F06C14C 3488000F */  ori   $t0, $a0, 0xf
/* 0A0C80 7F06C150 0C0025C8 */  jal   mempAllocBytesInBank
/* 0A0C84 7F06C154 3904000F */   xori  $a0, $t0, 0xf
/* 0A0C88 7F06C158 AFA20040 */  sw    $v0, 0x40($sp)
/* 0A0C8C 7F06C15C 86AA0014 */  lh    $t2, 0x14($s5)
/* 0A0C90 7F06C160 10000022 */  b     .L7F06C1EC
/* 0A0C94 7F06C164 A7AA003E */   sh    $t2, 0x3e($sp)
.L7F06C168:
/* 0A0C98 7F06C168 3C148003 */  lui   $s4, %hi(D_80036074)
/* 0A0C9C 7F06C16C 26946074 */  addiu $s4, %lo(D_80036074) # addiu $s4, $s4, 0x6074
/* 0A0CA0 7F06C170 8E8B0000 */  lw    $t3, ($s4)
/* 0A0CA4 7F06C174 00008025 */  move  $s0, $zero
/* 0A0CA8 7F06C178 00008825 */  move  $s1, $zero
/* 0A0CAC 7F06C17C 1960001B */  blez  $t3, .L7F06C1EC
/* 0A0CB0 7F06C180 3C138008 */   lui   $s3, %hi(ptr_allocation_1)
/* 0A0CB4 7F06C184 26739934 */  addiu $s3, %lo(ptr_allocation_1) # addiu $s3, $s3, -0x66cc
/* 0A0CB8 7F06C188 8E660000 */  lw    $a2, ($s3)
.L7F06C18C:
/* 0A0CBC 7F06C18C 00109140 */  sll   $s2, $s0, 5
/* 0A0CC0 7F06C190 00D16021 */  addu  $t4, $a2, $s1
/* 0A0CC4 7F06C194 8D8D0008 */  lw    $t5, 8($t4)
/* 0A0CC8 7F06C198 02462021 */  addu  $a0, $s2, $a2
/* 0A0CCC 7F06C19C 55A0000E */  bnezl $t5, .L7F06C1D8
/* 0A0CD0 7F06C1A0 8E980000 */   lw    $t8, ($s4)
/* 0A0CD4 7F06C1A4 0FC1B018 */  jal   sub_GAME_7F06C060
/* 0A0CD8 7F06C1A8 02A02825 */   move  $a1, $s5
/* 0A0CDC 7F06C1AC 5040000A */  beql  $v0, $zero, .L7F06C1D8
/* 0A0CE0 7F06C1B0 8E980000 */   lw    $t8, ($s4)
/* 0A0CE4 7F06C1B4 8E660000 */  lw    $a2, ($s3)
/* 0A0CE8 7F06C1B8 00D11021 */  addu  $v0, $a2, $s1
/* 0A0CEC 7F06C1BC 8C4E0010 */  lw    $t6, 0x10($v0)
/* 0A0CF0 7F06C1C0 0246B021 */  addu  $s6, $s2, $a2
/* 0A0CF4 7F06C1C4 AFAE0040 */  sw    $t6, 0x40($sp)
/* 0A0CF8 7F06C1C8 844F0002 */  lh    $t7, 2($v0)
/* 0A0CFC 7F06C1CC 10000007 */  b     .L7F06C1EC
/* 0A0D00 7F06C1D0 A7AF003E */   sh    $t7, 0x3e($sp)
/* 0A0D04 7F06C1D4 8E980000 */  lw    $t8, ($s4)
.L7F06C1D8:
/* 0A0D08 7F06C1D8 26100001 */  addiu $s0, $s0, 1
/* 0A0D0C 7F06C1DC 26310020 */  addiu $s1, $s1, 0x20
/* 0A0D10 7F06C1E0 0218082A */  slt   $at, $s0, $t8
/* 0A0D14 7F06C1E4 5420FFE9 */  bnezl $at, .L7F06C18C
/* 0A0D18 7F06C1E8 8E660000 */   lw    $a2, ($s3)
.L7F06C1EC:
/* 0A0D1C 7F06C1EC 12C00006 */  beqz  $s6, .L7F06C208
/* 0A0D20 7F06C1F0 02C02025 */   move  $a0, $s6
/* 0A0D24 7F06C1F4 02A02825 */  move  $a1, $s5
/* 0A0D28 7F06C1F8 0FC1D7DA */  jal   sub_GAME_7F075F68
/* 0A0D2C 7F06C1FC 8FA60040 */   lw    $a2, 0x40($sp)
/* 0A0D30 7F06C200 87B9003E */  lh    $t9, 0x3e($sp)
/* 0A0D34 7F06C204 A6D90002 */  sh    $t9, 2($s6)
.L7F06C208:
/* 0A0D38 7F06C208 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0A0D3C 7F06C20C 02C01025 */  move  $v0, $s6
/* 0A0D40 7F06C210 8FB60030 */  lw    $s6, 0x30($sp)
/* 0A0D44 7F06C214 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A0D48 7F06C218 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0A0D4C 7F06C21C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0A0D50 7F06C220 8FB30024 */  lw    $s3, 0x24($sp)
/* 0A0D54 7F06C224 8FB40028 */  lw    $s4, 0x28($sp)
/* 0A0D58 7F06C228 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0A0D5C 7F06C22C 03E00008 */  jr    $ra
/* 0A0D60 7F06C230 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
void set_obj_instance_scale_to_zero(void) {

}
#else
GLOBAL_ASM(
.text
glabel set_obj_instance_scale_to_zero
/* 0A0D64 7F06C234 03E00008 */  jr    $ra
/* 0A0D68 7F06C238 AC800008 */   sw    $zero, 8($a0)
)
#endif





#ifdef NONMATCHING
void get_aircraft_obj_instance_controller(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_aircraft_obj_instance_controller
/* 0A0D6C 7F06C23C 3C0E8003 */  lui   $t6, %hi(D_80036078) 
/* 0A0D70 7F06C240 8DCE6078 */  lw    $t6, %lo(D_80036078)($t6)
/* 0A0D74 7F06C244 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A0D78 7F06C248 AFB00018 */  sw    $s0, 0x18($sp)
/* 0A0D7C 7F06C24C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0A0D80 7F06C250 AFA40030 */  sw    $a0, 0x30($sp)
/* 0A0D84 7F06C254 00008025 */  move  $s0, $zero
/* 0A0D88 7F06C258 AFA00028 */  sw    $zero, 0x28($sp)
/* 0A0D8C 7F06C25C 11C00028 */  beqz  $t6, .L7F06C300
/* 0A0D90 7F06C260 2408FFFF */   li    $t0, -1
/* 0A0D94 7F06C264 3C058003 */  lui   $a1, %hi(D_80036070)
/* 0A0D98 7F06C268 8CA56070 */  lw    $a1, %lo(D_80036070)($a1)
/* 0A0D9C 7F06C26C 00001025 */  move  $v0, $zero
/* 0A0DA0 7F06C270 3C078008 */  lui   $a3, %hi(ptr_allocation_0)
/* 0A0DA4 7F06C274 24A5FFF6 */  addiu $a1, $a1, -0xa
/* 0A0DA8 7F06C278 18A0000D */  blez  $a1, .L7F06C2B0
/* 0A0DAC 7F06C27C 00000000 */   nop   
/* 0A0DB0 7F06C280 8CE79930 */  lw    $a3, %lo(ptr_allocation_0)($a3)
/* 0A0DB4 7F06C284 00002025 */  move  $a0, $zero
/* 0A0DB8 7F06C288 00E01825 */  move  $v1, $a3
.L7F06C28C:
/* 0A0DBC 7F06C28C 8C6F0008 */  lw    $t7, 8($v1)
/* 0A0DC0 7F06C290 24420001 */  addiu $v0, $v0, 1
/* 0A0DC4 7F06C294 0045082A */  slt   $at, $v0, $a1
/* 0A0DC8 7F06C298 15E00003 */  bnez  $t7, .L7F06C2A8
/* 0A0DCC 7F06C29C 246300BC */   addiu $v1, $v1, 0xbc
/* 0A0DD0 7F06C2A0 10000003 */  b     .L7F06C2B0
/* 0A0DD4 7F06C2A4 00878021 */   addu  $s0, $a0, $a3
.L7F06C2A8:
/* 0A0DD8 7F06C2A8 1420FFF8 */  bnez  $at, .L7F06C28C
/* 0A0DDC 7F06C2AC 248400BC */   addiu $a0, $a0, 0xbc
.L7F06C2B0:
/* 0A0DE0 7F06C2B0 16000006 */  bnez  $s0, .L7F06C2CC
/* 0A0DE4 7F06C2B4 240400C0 */   li    $a0, 192
/* 0A0DE8 7F06C2B8 24050004 */  li    $a1, 4
/* 0A0DEC 7F06C2BC 0C0025C8 */  jal   mempAllocBytesInBank
/* 0A0DF0 7F06C2C0 A7A80026 */   sh    $t0, 0x26($sp)
/* 0A0DF4 7F06C2C4 87A80026 */  lh    $t0, 0x26($sp)
/* 0A0DF8 7F06C2C8 00408025 */  move  $s0, $v0
.L7F06C2CC:
/* 0A0DFC 7F06C2CC 8FB80030 */  lw    $t8, 0x30($sp)
/* 0A0E00 7F06C2D0 24050004 */  li    $a1, 4
/* 0A0E04 7F06C2D4 87060014 */  lh    $a2, 0x14($t8)
/* 0A0E08 7F06C2D8 18C00029 */  blez  $a2, .L7F06C380
/* 0A0E0C 7F06C2DC 00062080 */   sll   $a0, $a2, 2
/* 0A0E10 7F06C2E0 2484000F */  addiu $a0, $a0, 0xf
/* 0A0E14 7F06C2E4 3499000F */  ori   $t9, $a0, 0xf
/* 0A0E18 7F06C2E8 0C0025C8 */  jal   mempAllocBytesInBank
/* 0A0E1C 7F06C2EC 3B24000F */   xori  $a0, $t9, 0xf
/* 0A0E20 7F06C2F0 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0A0E24 7F06C2F4 AFA20028 */  sw    $v0, 0x28($sp)
/* 0A0E28 7F06C2F8 10000021 */  b     .L7F06C380
/* 0A0E2C 7F06C2FC 85480014 */   lh    $t0, 0x14($t2)
.L7F06C300:
/* 0A0E30 7F06C300 3C058003 */  lui   $a1, %hi(D_80036070)
/* 0A0E34 7F06C304 8CA56070 */  lw    $a1, %lo(D_80036070)($a1)
/* 0A0E38 7F06C308 8FAB0030 */  lw    $t3, 0x30($sp)
/* 0A0E3C 7F06C30C 00001825 */  move  $v1, $zero
/* 0A0E40 7F06C310 18A0001B */  blez  $a1, .L7F06C380
/* 0A0E44 7F06C314 85660014 */   lh    $a2, 0x14($t3)
/* 0A0E48 7F06C318 3C078008 */  lui   $a3, %hi(ptr_allocation_0)
/* 0A0E4C 7F06C31C 8CE79930 */  lw    $a3, %lo(ptr_allocation_0)($a3)
/* 0A0E50 7F06C320 00002025 */  move  $a0, $zero
/* 0A0E54 7F06C324 00E01025 */  move  $v0, $a3
.L7F06C328:
/* 0A0E58 7F06C328 8C4C0008 */  lw    $t4, 8($v0)
/* 0A0E5C 7F06C32C 24630001 */  addiu $v1, $v1, 1
/* 0A0E60 7F06C330 55800010 */  bnezl $t4, .L7F06C374
/* 0A0E64 7F06C334 0065082A */   slt   $at, $v1, $a1
/* 0A0E68 7F06C338 58C00009 */  blezl $a2, .L7F06C360
/* 0A0E6C 7F06C33C 8C4F0010 */   lw    $t7, 0x10($v0)
/* 0A0E70 7F06C340 8C4D0010 */  lw    $t5, 0x10($v0)
/* 0A0E74 7F06C344 51A0000B */  beql  $t5, $zero, .L7F06C374
/* 0A0E78 7F06C348 0065082A */   slt   $at, $v1, $a1
/* 0A0E7C 7F06C34C 844E0002 */  lh    $t6, 2($v0)
/* 0A0E80 7F06C350 01C6082A */  slt   $at, $t6, $a2
/* 0A0E84 7F06C354 54200007 */  bnezl $at, .L7F06C374
/* 0A0E88 7F06C358 0065082A */   slt   $at, $v1, $a1
/* 0A0E8C 7F06C35C 8C4F0010 */  lw    $t7, 0x10($v0)
.L7F06C360:
/* 0A0E90 7F06C360 00878021 */  addu  $s0, $a0, $a3
/* 0A0E94 7F06C364 AFAF0028 */  sw    $t7, 0x28($sp)
/* 0A0E98 7F06C368 10000005 */  b     .L7F06C380
/* 0A0E9C 7F06C36C 84480002 */   lh    $t0, 2($v0)
/* 0A0EA0 7F06C370 0065082A */  slt   $at, $v1, $a1
.L7F06C374:
/* 0A0EA4 7F06C374 248400BC */  addiu $a0, $a0, 0xbc
/* 0A0EA8 7F06C378 1420FFEB */  bnez  $at, .L7F06C328
/* 0A0EAC 7F06C37C 244200BC */   addiu $v0, $v0, 0xbc
.L7F06C380:
/* 0A0EB0 7F06C380 12000007 */  beqz  $s0, .L7F06C3A0
/* 0A0EB4 7F06C384 02002025 */   move  $a0, $s0
/* 0A0EB8 7F06C388 8FA50030 */  lw    $a1, 0x30($sp)
/* 0A0EBC 7F06C38C 8FA60028 */  lw    $a2, 0x28($sp)
/* 0A0EC0 7F06C390 0FC1D7EB */  jal   sub_GAME_7F075FAC
/* 0A0EC4 7F06C394 A7A80026 */   sh    $t0, 0x26($sp)
/* 0A0EC8 7F06C398 87A80026 */  lh    $t0, 0x26($sp)
/* 0A0ECC 7F06C39C A6080002 */  sh    $t0, 2($s0)
.L7F06C3A0:
/* 0A0ED0 7F06C3A0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0A0ED4 7F06C3A4 02001025 */  move  $v0, $s0
/* 0A0ED8 7F06C3A8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0A0EDC 7F06C3AC 03E00008 */  jr    $ra
/* 0A0EE0 7F06C3B0 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06C3B4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C3B4
/* 0A0EE4 7F06C3B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A0EE8 7F06C3B8 AFA60020 */  sw    $a2, 0x20($sp)
/* 0A0EEC 7F06C3BC 00A03025 */  move  $a2, $a1
/* 0A0EF0 7F06C3C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A0EF4 7F06C3C4 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0A0EF8 7F06C3C8 8C850008 */  lw    $a1, 8($a0)
/* 0A0EFC 7F06C3CC AFA40018 */  sw    $a0, 0x18($sp)
/* 0A0F00 7F06C3D0 0FC1D80C */  jal   sub_GAME_7F076030
/* 0A0F04 7F06C3D4 8FA70020 */   lw    $a3, 0x20($sp)
/* 0A0F08 7F06C3D8 8FAE0020 */  lw    $t6, 0x20($sp)
/* 0A0F0C 7F06C3DC 8FA40018 */  lw    $a0, 0x18($sp)
/* 0A0F10 7F06C3E0 0FC1D74B */  jal   unknown_object_microcode_handler
/* 0A0F14 7F06C3E4 8DC50000 */   lw    $a1, ($t6)
/* 0A0F18 7F06C3E8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A0F1C 7F06C3EC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0A0F20 7F06C3F0 03E00008 */  jr    $ra
/* 0A0F24 7F06C3F4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void set_aircraft_obj_inst_scale_to_zero(void) {

}
#else
GLOBAL_ASM(
.text
glabel set_aircraft_obj_inst_scale_to_zero
/* 0A0F28 7F06C3F8 03E00008 */  jr    $ra
/* 0A0F2C 7F06C3FC AC800008 */   sw    $zero, 8($a0)
)
#endif





void set_80036084(s32 param_1) {
  D_80036084 = param_1;
}

void set_float_80036088(f32 param_1) {
  D_80036088 = param_1;
}





#ifdef NONMATCHING
void sub_GAME_7F06C418(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C418
/* 0A0F48 7F06C418 00803025 */  move  $a2, $a0
/* 0A0F4C 7F06C41C 24040004 */  li    $a0, 4
/* 0A0F50 7F06C420 00001025 */  move  $v0, $zero
/* 0A0F54 7F06C424 00A01825 */  move  $v1, $a1
.L7F06C428:
/* 0A0F58 7F06C428 8CCE0000 */  lw    $t6, ($a2)
/* 0A0F5C 7F06C42C 24420001 */  addiu $v0, $v0, 1
/* 0A0F60 7F06C430 24630010 */  addiu $v1, $v1, 0x10
/* 0A0F64 7F06C434 AC6EFFF0 */  sw    $t6, -0x10($v1)
/* 0A0F68 7F06C438 8CCF0004 */  lw    $t7, 4($a2)
/* 0A0F6C 7F06C43C 24C60010 */  addiu $a2, $a2, 0x10
/* 0A0F70 7F06C440 AC6FFFF4 */  sw    $t7, -0xc($v1)
/* 0A0F74 7F06C444 8CD8FFF8 */  lw    $t8, -8($a2)
/* 0A0F78 7F06C448 AC78FFF8 */  sw    $t8, -8($v1)
/* 0A0F7C 7F06C44C 8CD9FFFC */  lw    $t9, -4($a2)
/* 0A0F80 7F06C450 1444FFF5 */  bne   $v0, $a0, .L7F06C428
/* 0A0F84 7F06C454 AC79FFFC */   sw    $t9, -4($v1)
/* 0A0F88 7F06C458 03E00008 */  jr    $ra
/* 0A0F8C 7F06C45C 00000000 */   nop   
)
#endif





void set_8003608C(s32 param_1) {
  D_8003608C = param_1;
}

void return_null(void) {
  return;
}






#ifdef NONMATCHING
void sub_GAME_7F06C474(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C474
/* 0A0FA4 7F06C474 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0A0FA8 7F06C478 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A0FAC 7F06C47C AFA40030 */  sw    $a0, 0x30($sp)
/* 0A0FB0 7F06C480 0FC1B1A8 */  jal   getsubmatrix
/* 0A0FB4 7F06C484 AFA50034 */   sw    $a1, 0x34($sp)
/* 0A0FB8 7F06C488 C44E0030 */  lwc1  $f14, 0x30($v0)
/* 0A0FBC 7F06C48C C4500034 */  lwc1  $f16, 0x34($v0)
/* 0A0FC0 7F06C490 C4520038 */  lwc1  $f18, 0x38($v0)
/* 0A0FC4 7F06C494 46007387 */  neg.s $f14, $f14
/* 0A0FC8 7F06C498 46008407 */  neg.s $f16, $f16
/* 0A0FCC 7F06C49C 460E7102 */  mul.s $f4, $f14, $f14
/* 0A0FD0 7F06C4A0 46009487 */  neg.s $f18, $f18
/* 0A0FD4 7F06C4A4 E7B00020 */  swc1  $f16, 0x20($sp)
/* 0A0FD8 7F06C4A8 46108182 */  mul.s $f6, $f16, $f16
/* 0A0FDC 7F06C4AC E7B2001C */  swc1  $f18, 0x1c($sp)
/* 0A0FE0 7F06C4B0 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 0A0FE4 7F06C4B4 46129282 */  mul.s $f10, $f18, $f18
/* 0A0FE8 7F06C4B8 46062200 */  add.s $f8, $f4, $f6
/* 0A0FEC 7F06C4BC 0C007DF8 */  jal   sqrtf
/* 0A0FF0 7F06C4C0 460A4300 */   add.s $f12, $f8, $f10
/* 0A0FF4 7F06C4C4 44801000 */  mtc1  $zero, $f2
/* 0A0FF8 7F06C4C8 8FA50034 */  lw    $a1, 0x34($sp)
/* 0A0FFC 7F06C4CC C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 0A1000 7F06C4D0 4600103C */  c.lt.s $f2, $f0
/* 0A1004 7F06C4D4 C7B00020 */  lwc1  $f16, 0x20($sp)
/* 0A1008 7F06C4D8 C7B2001C */  lwc1  $f18, 0x1c($sp)
/* 0A100C 7F06C4DC 8FAE0030 */  lw    $t6, 0x30($sp)
/* 0A1010 7F06C4E0 45020010 */  bc1fl .L7F06C524
/* 0A1014 7F06C4E4 E4A20000 */   swc1  $f2, ($a1)
/* 0A1018 7F06C4E8 C5C60014 */  lwc1  $f6, 0x14($t6)
/* 0A101C 7F06C4EC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A1020 7F06C4F0 44812000 */  mtc1  $at, $f4
/* 0A1024 7F06C4F4 46003202 */  mul.s $f8, $f6, $f0
/* 0A1028 7F06C4F8 46082083 */  div.s $f2, $f4, $f8
/* 0A102C 7F06C4FC 46027282 */  mul.s $f10, $f14, $f2
/* 0A1030 7F06C500 00000000 */  nop   
/* 0A1034 7F06C504 46028182 */  mul.s $f6, $f16, $f2
/* 0A1038 7F06C508 00000000 */  nop   
/* 0A103C 7F06C50C 46029102 */  mul.s $f4, $f18, $f2
/* 0A1040 7F06C510 E4AA0000 */  swc1  $f10, ($a1)
/* 0A1044 7F06C514 E4A60004 */  swc1  $f6, 4($a1)
/* 0A1048 7F06C518 10000009 */  b     .L7F06C540
/* 0A104C 7F06C51C E4A40008 */   swc1  $f4, 8($a1)
/* 0A1050 7F06C520 E4A20000 */  swc1  $f2, ($a1)
.L7F06C524:
/* 0A1054 7F06C524 E4A20004 */  swc1  $f2, 4($a1)
/* 0A1058 7F06C528 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0A105C 7F06C52C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0A1060 7F06C530 44814000 */  mtc1  $at, $f8
/* 0A1064 7F06C534 C5EA0014 */  lwc1  $f10, 0x14($t7)
/* 0A1068 7F06C538 460A4183 */  div.s $f6, $f8, $f10
/* 0A106C 7F06C53C E4A60008 */  swc1  $f6, 8($a1)
.L7F06C540:
/* 0A1070 7F06C540 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A1074 7F06C544 27BD0030 */  addiu $sp, $sp, 0x30
/* 0A1078 7F06C548 03E00008 */  jr    $ra
/* 0A107C 7F06C54C 00000000 */   nop   
)
#endif





void sub_GAME_7F06C550(void) {
  sub_GAME_7F06C474();
}





#ifdef NONMATCHING
void sub_GAME_7F06C570(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C570
/* 0A10A0 7F06C570 10800038 */  beqz  $a0, .L7F06C654
/* 0A10A4 7F06C574 00A03025 */   move  $a2, $a1
/* 0A10A8 7F06C578 24080015 */  li    $t0, 21
/* 0A10AC 7F06C57C 24070003 */  li    $a3, 3
/* 0A10B0 7F06C580 24050002 */  li    $a1, 2
/* 0A10B4 7F06C584 24020001 */  li    $v0, 1
/* 0A10B8 7F06C588 94830000 */  lhu   $v1, ($a0)
.L7F06C58C:
/* 0A10BC 7F06C58C 306E00FF */  andi  $t6, $v1, 0xff
/* 0A10C0 7F06C590 51C2000A */  beql  $t6, $v0, .L7F06C5BC
/* 0A10C4 7F06C594 8C830004 */   lw    $v1, 4($a0)
/* 0A10C8 7F06C598 51C5000B */  beql  $t6, $a1, .L7F06C5C8
/* 0A10CC 7F06C59C 24010200 */   li    $at, 512
/* 0A10D0 7F06C5A0 51C70018 */  beql  $t6, $a3, .L7F06C604
/* 0A10D4 7F06C5A4 24010200 */   li    $at, 512
/* 0A10D8 7F06C5A8 51C80025 */  beql  $t6, $t0, .L7F06C640
/* 0A10DC 7F06C5AC 8C830004 */   lw    $v1, 4($a0)
/* 0A10E0 7F06C5B0 10000026 */  b     .L7F06C64C
/* 0A10E4 7F06C5B4 8C840008 */   lw    $a0, 8($a0)
/* 0A10E8 7F06C5B8 8C830004 */  lw    $v1, 4($a0)
.L7F06C5BC:
/* 0A10EC 7F06C5BC 03E00008 */  jr    $ra
/* 0A10F0 7F06C5C0 84620002 */   lh    $v0, 2($v1)

/* 0A10F4 7F06C5C4 24010200 */  li    $at, 512
.L7F06C5C8:
/* 0A10F8 7F06C5C8 14C10003 */  bne   $a2, $at, .L7F06C5D8
/* 0A10FC 7F06C5CC 8C850004 */   lw    $a1, 4($a0)
/* 0A1100 7F06C5D0 10000007 */  b     .L7F06C5F0
/* 0A1104 7F06C5D4 24030002 */   li    $v1, 2
.L7F06C5D8:
/* 0A1108 7F06C5D8 24010100 */  li    $at, 256
/* 0A110C 7F06C5DC 14C10003 */  bne   $a2, $at, .L7F06C5EC
/* 0A1110 7F06C5E0 00001025 */   move  $v0, $zero
/* 0A1114 7F06C5E4 10000001 */  b     .L7F06C5EC
/* 0A1118 7F06C5E8 24020001 */   li    $v0, 1
.L7F06C5EC:
/* 0A111C 7F06C5EC 00401825 */  move  $v1, $v0
.L7F06C5F0:
/* 0A1120 7F06C5F0 00037840 */  sll   $t7, $v1, 1
/* 0A1124 7F06C5F4 00AFC021 */  addu  $t8, $a1, $t7
/* 0A1128 7F06C5F8 03E00008 */  jr    $ra
/* 0A112C 7F06C5FC 8702000E */   lh    $v0, 0xe($t8)

/* 0A1130 7F06C600 24010200 */  li    $at, 512
.L7F06C604:
/* 0A1134 7F06C604 14C10003 */  bne   $a2, $at, .L7F06C614
/* 0A1138 7F06C608 8C850004 */   lw    $a1, 4($a0)
/* 0A113C 7F06C60C 10000007 */  b     .L7F06C62C
/* 0A1140 7F06C610 24030002 */   li    $v1, 2
.L7F06C614:
/* 0A1144 7F06C614 24010100 */  li    $at, 256
/* 0A1148 7F06C618 14C10003 */  bne   $a2, $at, .L7F06C628
/* 0A114C 7F06C61C 00001025 */   move  $v0, $zero
/* 0A1150 7F06C620 10000001 */  b     .L7F06C628
/* 0A1154 7F06C624 24020001 */   li    $v0, 1
.L7F06C628:
/* 0A1158 7F06C628 00401825 */  move  $v1, $v0
.L7F06C62C:
/* 0A115C 7F06C62C 0003C840 */  sll   $t9, $v1, 1
/* 0A1160 7F06C630 00B94821 */  addu  $t1, $a1, $t9
/* 0A1164 7F06C634 03E00008 */  jr    $ra
/* 0A1168 7F06C638 8522000E */   lh    $v0, 0xe($t1)

/* 0A116C 7F06C63C 8C830004 */  lw    $v1, 4($a0)
.L7F06C640:
/* 0A1170 7F06C640 03E00008 */  jr    $ra
/* 0A1174 7F06C644 8462000C */   lh    $v0, 0xc($v1)

/* 0A1178 7F06C648 8C840008 */  lw    $a0, 8($a0)
.L7F06C64C:
/* 0A117C 7F06C64C 5480FFCF */  bnezl $a0, .L7F06C58C
/* 0A1180 7F06C650 94830000 */   lhu   $v1, ($a0)
.L7F06C654:
/* 0A1184 7F06C654 2402FFFF */  li    $v0, -1
/* 0A1188 7F06C658 03E00008 */  jr    $ra
/* 0A118C 7F06C65C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F06C660(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F06C660
/* 0A1190 7F06C660 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A1194 7F06C664 AFA40018 */  sw    $a0, 0x18($sp)
/* 0A1198 7F06C668 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A119C 7F06C66C 00A02025 */  move  $a0, $a1
/* 0A11A0 7F06C670 0FC1B15C */  jal   sub_GAME_7F06C570
/* 0A11A4 7F06C674 00C02825 */   move  $a1, $a2
/* 0A11A8 7F06C678 04400006 */  bltz  $v0, .L7F06C694
/* 0A11AC 7F06C67C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0A11B0 7F06C680 8FAE0018 */  lw    $t6, 0x18($sp)
/* 0A11B4 7F06C684 0002C180 */  sll   $t8, $v0, 6
/* 0A11B8 7F06C688 8DCF000C */  lw    $t7, 0xc($t6)
/* 0A11BC 7F06C68C 10000002 */  b     .L7F06C698
/* 0A11C0 7F06C690 01F81021 */   addu  $v0, $t7, $t8
.L7F06C694:
/* 0A11C4 7F06C694 00001025 */  move  $v0, $zero
.L7F06C698:
/* 0A11C8 7F06C698 03E00008 */  jr    $ra
/* 0A11CC 7F06C69C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif

