#include "ultra64.h"


/* data
D:80048670     type_0_stru_800490F0:struct_2 <0, 0xCD, 1.0, 1, 0, 1>
D:80048670                                              # DATA XREF: D:mp_weapon_set_text_tableo
D:80048688                     struct_2 <0, 0xCD, 1.0, 1, 0, 1>
D:800486A0                     struct_2 <0, 0xCD, 1.0, 1, 0, 1>
D:800486B8                     struct_2 <0, 0xCD, 1.0, 1, 0, 1>
D:800486D0                     struct_2 <0, 0xCD, 1.0, 1, 0, 1>
D:800486E8                     struct_2 <0, 0xCD, 1.0, 1, 0, 1>
D:80048700                     struct_2 <0, 0xCD, 1.0, 1, 0, 1>
D:80048718                     struct_2 <0, 0xCD, 1.0, 1, 0, 1>
D:80048730     type_1_stru_800490F0:struct_2 <6, 0xCD, 1.0, 1, 0x32, 1>
D:80048730                                              # DATA XREF: D:800490F8o
D:80048748                     struct_2 <6, 0xCD, 1.0, 1, 0x32, 1>
D:80048760                     struct_2 <6, 0xCD, 1.0, 1, 0x32, 1>
D:80048778                     struct_2 <5, 0xCC, 1.0, 1, 0x32, 1>
D:80048790                     struct_2 <5, 0xCC, 1.0, 1, 0x32, 1>
D:800487A8                     struct_2 <5, 0xCC, 1.0, 1, 0x32, 1>
D:800487C0                     struct_2 <0x12, 0xBE, 1.0, 0xC, 0x32, 1>
D:800487D8                     struct_2 <0x12, 0xBE, 1.0, 0xC, 0x32, 1>
D:800487F0     type_D_stru_800490F0:struct_2 <3, 0xD1, 1.0, 0xA, 0xA, 0>
D:800487F0                                              # DATA XREF: D:80049100o
D:80048808                     struct_2 <3, 0xD1, 1.0, 0xA, 0xA, 0>
D:80048820                     struct_2 <3, 0xD1, 1.0, 0xA, 0xA, 0>
D:80048838                     struct_2 <3, 0xD1, 1.0, 0xA, 0xA, 0>
D:80048850                     struct_2 <3, 0xD1, 1.0, 0xA, 0xA, 0>
D:80048868                     struct_2 <3, 0xD1, 1.0, 0xA, 0xA, 0>
D:80048880                     struct_2 <3, 0xD1, 1.0, 0xA, 0xA, 0>
D:80048898                     struct_2 <3, 0xD1, 1.0, 0xA, 0xA, 0>
D:800488B0     type_2_stru_800490F0:struct_2 <5, 0xCC, 1.0, 1, 0x32, 1>
D:800488B0                                              # DATA XREF: D:80049108o
D:800488C8                     struct_2 <5, 0xCC, 1.0, 1, 0x32, 1>
D:800488E0                     struct_2 <6, 0xCD, 1.0, 1, 0x32, 1>
D:800488F8                     struct_2 <6, 0xCD, 1.0, 1, 0x32, 1>
D:80048910                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048928                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048940                     struct_2 <0xA, 0xBD, 1.0, 1, 0x64, 1>
D:80048958                     struct_2 <0xA, 0xBD, 1.0, 1, 0x64, 1>
D:80048970     type_3_stru_800490F0:struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048970                                              # DATA XREF: D:80049110o
D:80048988                     struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:800489A0                     struct_2 <0x12, 0xBE, 1.0, 0xC, 0x32, 1>
D:800489B8                     struct_2 <0x12, 0xBE, 1.0, 0xC, 0x32, 1>
D:800489D0                     struct_2 <0xE, 0xC5, 1.0, 1, 0x64, 1>
D:800489E8                     struct_2 <0xE, 0xC5, 1.0, 1, 0x64, 1>
D:80048A00                     struct_2 <0x10, 0xCF, 1.0, 4, 0x1E, 1>
D:80048A18                     struct_2 <0x10, 0xCF, 1.0, 4, 0x1E, 1>
D:80048A30     type_4_stru_800490F0:struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048A30                                              # DATA XREF: D:80049118o
D:80048A48                     struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048A60                     struct_2 <0x12, 0xBE, 1.0, 0xC, 0x32, 1>
D:80048A78                     struct_2 <0x12, 0xBE, 1.0, 0xC, 0x32, 1>
D:80048A90                     struct_2 <7, 0xC1, 1.0, 1, 0x64, 1>
D:80048AA8                     struct_2 <7, 0xC1, 1.0, 1, 0x64, 1>
D:80048AC0                     struct_2 <0x11, 0xD2, 1.0, 3, 0x32, 1>
D:80048AD8                     struct_2 <0x11, 0xD2, 1.0, 3, 0x32, 1>
D:80048AF0     type_5_stru_800490F0:struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048AF0                                              # DATA XREF: D:80049120o
D:80048B08                     struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048B20                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048B38                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048B50                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:80048B68                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:80048B80                     struct_2 <0x1A, 0xC4, 1.5, 5, 5, 0>
D:80048B98                     struct_2 <0x1A, 0xC4, 1.5, 5, 5, 0>
D:80048BB0     type_6_stru_800490F0:struct_2 <4, 0xBF, 3.0, 1, 0x32, 1>
D:80048BB0                                              # DATA XREF: D:80049128o
D:80048BC8                     struct_2 <4, 0xBF, 3.0, 1, 0x32, 1>
D:80048BE0                     struct_2 <9, 0xC3, 1.5, 1, 0x64, 1>
D:80048BF8                     struct_2 <9, 0xC3, 1.5, 1, 0x64, 1>
D:80048C10                     struct_2 <0xD, 0xB8, 1.5, 3, 0x64, 1>
D:80048C28                     struct_2 <0xD, 0xB8, 1.5, 3, 0x64, 1>
D:80048C40                     struct_2 <0x1D, 0xC7, 1.5, 7, 5, 0>
D:80048C58                     struct_2 <0x1D, 0xC7, 1.5, 7, 5, 0>
D:80048C70     type_7_stru_800490F0:struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048C70                                              # DATA XREF: D:80049130o
D:80048C88                     struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048CA0                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048CB8                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048CD0                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:80048CE8                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:80048D00                     struct_2 <0x18, 0xB9, 1.0, 0xB, 6, 1>
D:80048D18                     struct_2 <0x18, 0xB9, 1.0, 0xB, 6, 1>
D:80048D30     type_8_stru_800490F0:struct_2 <4, 0xBF, 3.0, 1, 0x32, 1>
D:80048D30                                              # DATA XREF: D:80049138o
D:80048D48                     struct_2 <4, 0xBF, 3.0, 1, 0x32, 1>
D:80048D60                     struct_2 <9, 0xC3, 1.5, 1, 0x64, 1>
D:80048D78                     struct_2 <9, 0xC3, 1.5, 1, 0x64, 1>
D:80048D90                     struct_2 <0xD, 0xB8, 1.5, 3, 0x64, 1>
D:80048DA8                     struct_2 <0xD, 0xB8, 1.5, 3, 0x64, 1>
D:80048DC0                     struct_2 <0x1B, 0xC9, 1.5, 9, 5, 0>
D:80048DD8                     struct_2 <0x1B, 0xC9, 1.5, 9, 5, 0>
D:80048DF0     type_9_stru_800490F0:struct_2 <4, 0xBF, 3.0, 1, 0x32, 1>
D:80048DF0                                              # DATA XREF: D:80049140o
D:80048E08                     struct_2 <4, 0xBF, 3.0, 1, 0x32, 1>
D:80048E20                     struct_2 <9, 0xC3, 1.5, 1, 0x64, 1>
D:80048E38                     struct_2 <9, 0xC3, 1.5, 1, 0x64, 1>
D:80048E50                     struct_2 <0xD, 0xBC, 1.5, 3, 0x64, 1>
D:80048E68                     struct_2 <0xD, 0xBC, 1.5, 3, 0x64, 1>
D:80048E80                     struct_2 <0x1C, 0xC8, 1.5, 8, 5, 0>
D:80048E98                     struct_2 <0x1C, 0xC8, 1.5, 8, 5, 0>
D:80048EB0     type_A_stru_800490F0:struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048EB0                                              # DATA XREF: D:80049148o
D:80048EC8                     struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048EE0                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048EF8                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048F10                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:80048F28                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:80048F40                     struct_2 <0x19, 0xD3, 1.5, 6, 6, 1>
D:80048F58                     struct_2 <0x19, 0xD3, 1.5, 6, 6, 1>
D:80048F70     type_B_stru_800490F0:struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048F70                                              # DATA XREF: D:80049150o
D:80048F88                     struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80048FA0                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048FB8                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80048FD0                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:80048FE8                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:80049000                     struct_2 <0x16, 0xBB, 1.5, 0, 0, 1>
D:80049018                     struct_2 <0x16, 0xBB, 1.5, 0, 0, 1>
D:80049030     type_C_stru_800490F0:struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80049030                                              # DATA XREF: D:80049158o
D:80049048                     struct_2 <6, 0xCD, 3.0, 1, 0x32, 1>
D:80049060                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80049078                     struct_2 <7, 0xC1, 1.5, 1, 0x64, 1>
D:80049090                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:800490A8                     struct_2 <8, 0xB8, 1.5, 3, 0x64, 1>
D:800490C0                     struct_2 <5, 0xCC, 1.0, 1, 0x32, 1>
D:800490D8                     struct_2 <0x13, 0xD0, 1.5, 0xD, 0xA, 1>
D:800490F0     mp_weapon_set_text_table:struct_8 <0xA8, 0, 0, 0, type_0_stru_800490F0>
D:800490F0                                              # DATA XREF: get_ptr_current_mp_weapon_set_text_code+8o
D:800490F8                     struct_8 <0xA8, 1, 0, 0, type_1_stru_800490F0>
D:80049100                     struct_8 <0xA8, 0xD, 0, 0, type_D_stru_800490F0>
D:80049108                     struct_8 <0xA8, 2, 0, 0, type_2_stru_800490F0>
D:80049110                     struct_8 <0xA8, 3, 0, 0, type_3_stru_800490F0>
D:80049118                     struct_8 <0xA8, 4, 0, 0, type_4_stru_800490F0>
D:80049120                     struct_8 <0xA8, 5, 0, 0, type_5_stru_800490F0>
D:80049128                     struct_8 <0xA8, 6, 0, 0, type_6_stru_800490F0>
D:80049130                     struct_8 <0xA8, 7, 0, 0, type_7_stru_800490F0>
D:80049138                     struct_8 <0xA8, 8, 0, 0, type_8_stru_800490F0>
D:80049140                     struct_8 <0xA8, 9, 0, 0, type_9_stru_800490F0>
D:80049148                     struct_8 <0xA8, 0xA, 0, 0, type_A_stru_800490F0>
D:80049150                     struct_8 <0xA8, 0xB, 0, 0, type_B_stru_800490F0>
D:80049158                     struct_8 <0xA8, 0xC, 0, 0, type_C_stru_800490F0>
D:80049160     mp_weapon_set:  .word 0xB                # DATA XREF: advance_mp_weapon_set_by_one_save_valueo
D:80049160                                              # advance_mp_weapon_set_by_one_save_value+8r
D:80049160                                              # advance_mp_weapon_set_by_one_save_value+1Cw
D:80049160                                              # get_ptr_current_mp_weapon_set_text_coder
D:80049160                                              # get_ptr_mp_weapon_set_datar
D:80049160                                              # set_mp_weapon_set+8w
D:80049160                                              # get_mp_weapon_set+8r
D:80049164                     .word 0
D:80049168                     .word 0
D:8004916C                     .word 0
*/



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



