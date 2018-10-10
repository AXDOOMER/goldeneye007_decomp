#include "ultra64.h"


#ifdef NONMATCHING
void init_weapon_animation_groups_maybe(void) {

}
#else
GLOBAL_ASM(
.text
glabel init_weapon_animation_groups_maybe
/* 034C10 7F0000E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 034C14 7F0000E4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 034C18 7F0000E8 3C047F02 */  lui   $a0, %hi(get_ptr_allocated_block_for_vertices) # $a0, 0x7f02
/* 034C1C 7F0000EC 0FC1B118 */  jal   set_8003608C
/* 034C20 7F0000F0 2484F53C */   addiu $a0, %lo(get_ptr_allocated_block_for_vertices) # addiu $a0, $a0, -0xac4
/* 034C24 7F0000F4 0FC00146 */  jal   somethingwith_weapon_animation_groups
/* 034C28 7F0000F8 00000000 */   nop   
/* 034C2C 7F0000FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 034C30 7F000100 27BD0018 */  addiu $sp, $sp, 0x18
/* 034C34 7F000104 03E00008 */  jr    $ra
/* 034C38 7F000108 00000000 */   nop
)
#endif
