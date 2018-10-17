#include "ultra64.h"


/* data
D:8004EAE0     dword_D_8004EAE0:.word 0, 0, 0, 0        # DATA XREF: something_game_c_debug_related+18o
*/



#ifdef NONMATCHING
void something_game_c_debug_related(void) {

}
#else
GLOBAL_ASM(
.text
glabel something_game_c_debug_related
/* 106550 7F0D1A20 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 106554 7F0D1A24 AFBF0014 */  sw    $ra, 0x14($sp)
/* 106558 7F0D1A28 3C048005 */  lui   $a0, %hi(D_8004EAE0) # $a0, 0x8005
/* 10655C 7F0D1A2C 3C058006 */  lui   $a1, %hi(aGame_c_debug) # $a1, 0x8006
/* 106560 7F0D1A30 24A5BFF0 */  addiu $a1, %lo(aGame_c_debug) # addiu $a1, $a1, -0x4010
/* 106564 7F0D1A34 0C001398 */  jal   get_ptr_debug_notice_list_entry
/* 106568 7F0D1A38 2484EAE0 */   addiu $a0, %lo(D_8004EAE0) # addiu $a0, $a0, -0x1520
/* 10656C 7F0D1A3C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 106570 7F0D1A40 27BD0018 */  addiu $sp, $sp, 0x18
/* 106574 7F0D1A44 03E00008 */  jr    $ra
/* 106578 7F0D1A48 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void reset_mem_bank_5(void) {

}
#else
GLOBAL_ASM(
.text
glabel reset_mem_bank_5
/* 10657C 7F0D1A4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 106580 7F0D1A50 AFBF0014 */  sw    $ra, 0x14($sp)
/* 106584 7F0D1A54 0FC2F48D */  jal   sub_GAME_7F0BD234
/* 106588 7F0D1A58 00000000 */   nop   
/* 10658C 7F0D1A5C 0C002667 */  jal   reset_mem_bank_a0
/* 106590 7F0D1A60 24040005 */   li    $a0, 5
/* 106594 7F0D1A64 0FC2F46F */  jal   something_mem_bank_a0
/* 106598 7F0D1A68 24040005 */   li    $a0, 5
/* 10659C 7F0D1A6C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1065A0 7F0D1A70 27BD0018 */  addiu $sp, $sp, 0x18
/* 1065A4 7F0D1A74 03E00008 */  jr    $ra
/* 1065A8 7F0D1A78 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1A7C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1A7C
/* 1065AC 7F0D1A7C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1065B0 7F0D1A80 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1065B4 7F0D1A84 0C002671 */  jal   memp_related_6
/* 1065B8 7F0D1A88 24040005 */   li    $a0, 5
/* 1065BC 7F0D1A8C 0FC2F46F */  jal   something_mem_bank_a0
/* 1065C0 7F0D1A90 24040005 */   li    $a0, 5
/* 1065C4 7F0D1A94 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1065C8 7F0D1A98 27BD0018 */  addiu $sp, $sp, 0x18
/* 1065CC 7F0D1A9C 03E00008 */  jr    $ra
/* 1065D0 7F0D1AA0 00000000 */   nop   
)
#endif




