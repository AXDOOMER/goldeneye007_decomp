#include "ultra64.h"






#ifdef NONMATCHING
void advance_mp_weapon_set_by_one_save_value(void) {

}
#else
GLOBAL_ASM(
.text
glabel advance_mp_weapon_set_by_one_save_value
/* 0FB100 7F0C65D0 3C028005 */  lui   $v0, %hi(D_80049160) # $v0, 0x8005
/* 0FB104 7F0C65D4 24429160 */  addiu $v0, %lo(D_80049160) # addiu $v0, $v0, -0x6ea0
/* 0FB108 7F0C65D8 8C4E0000 */  lw    $t6, ($v0)
/* 0FB10C 7F0C65DC 2401000E */  li    $at, 14
/* 0FB110 7F0C65E0 25CF0001 */  addiu $t7, $t6, 1
/* 0FB114 7F0C65E4 01E1001A */  div   $zero, $t7, $at
/* 0FB118 7F0C65E8 0000C010 */  mfhi  $t8
/* 0FB11C 7F0C65EC AC580000 */  sw    $t8, ($v0)
/* 0FB120 7F0C65F0 03E00008 */  jr    $ra
/* 0FB124 7F0C65F4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void get_ptr_current_mp_weapon_set_text_code(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_ptr_current_mp_weapon_set_text_code
/* 0FB128 7F0C65F8 3C0E8005 */  lui   $t6, %hi(D_80049160) # $t6, 0x8005
/* 0FB12C 7F0C65FC 8DCE9160 */  lw    $t6, %lo(D_80049160)($t6)
/* 0FB130 7F0C6600 3C188005 */  lui   $t8, %hi(D_800490F0) # $t8, 0x8005
/* 0FB134 7F0C6604 271890F0 */  addiu $t8, %lo(D_800490F0) # addiu $t8, $t8, -0x6f10
/* 0FB138 7F0C6608 000E78C0 */  sll   $t7, $t6, 3
/* 0FB13C 7F0C660C 03E00008 */  jr    $ra
/* 0FB140 7F0C6610 01F81021 */   addu  $v0, $t7, $t8
)
#endif





#ifdef NONMATCHING
void get_ptr_mp_weapon_set_data(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_ptr_mp_weapon_set_data
/* 0FB144 7F0C6614 3C0E8005 */  lui   $t6, %hi(D_80049160) # $t6, 0x8005
/* 0FB148 7F0C6618 8DCE9160 */  lw    $t6, %lo(D_80049160)($t6)
/* 0FB14C 7F0C661C 3C028005 */  lui   $v0, 0x8005
/* 0FB150 7F0C6620 000E78C0 */  sll   $t7, $t6, 3
/* 0FB154 7F0C6624 004F1021 */  addu  $v0, $v0, $t7
/* 0FB158 7F0C6628 03E00008 */  jr    $ra
/* 0FB15C 7F0C662C 8C4290F4 */   lw    $v0, -0x6f0c($v0)
)
#endif





#ifdef NONMATCHING
void set_mp_weapon_set(void) {

}
#else
GLOBAL_ASM(
.text
glabel set_mp_weapon_set
/* 0FB160 7F0C6630 3C018005 */  lui   $at, 0x8005
/* 0FB164 7F0C6634 03E00008 */  jr    $ra
/* 0FB168 7F0C6638 AC249160 */   sw    $a0, -0x6ea0($at)
)
#endif





#ifdef NONMATCHING
void get_mp_weapon_set(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_mp_weapon_set
/* 0FB16C 7F0C663C 3C028005 */  lui   $v0, 0x8005
/* 0FB170 7F0C6640 03E00008 */  jr    $ra
/* 0FB174 7F0C6644 8C429160 */   lw    $v0, -0x6ea0($v0)
)
#endif



