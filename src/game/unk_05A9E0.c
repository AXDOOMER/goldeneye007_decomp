#include "ultra64.h"







#ifdef NONMATCHING
void sub_GAME_7F05A9E0(f32 arg0, ? arg8) {
    f32 sp18;

    // Node 0
    sp18 = sinf(arg8);
    sqrtf(((sp18 / cosf(arg8)) + 1.0f));
    return;
    // (possible return value: sqrtf(((sp18 / cosf(arg8)) + 1.0f)))
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05A9E0
/* 08F510 7F05A9E0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08F514 7F05A9E4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08F518 7F05A9E8 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 08F51C 7F05A9EC 0FC15FAB */  jal   sinf
/* 08F520 7F05A9F0 C7AC0020 */   lwc1  $f12, 0x20($sp)
/* 08F524 7F05A9F4 E7A00018 */  swc1  $f0, 0x18($sp)
/* 08F528 7F05A9F8 0FC15FA8 */  jal   cosf
/* 08F52C 7F05A9FC C7AC0020 */   lwc1  $f12, 0x20($sp)
/* 08F530 7F05AA00 C7A40018 */  lwc1  $f4, 0x18($sp)
/* 08F534 7F05AA04 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08F538 7F05AA08 44814000 */  mtc1  $at, $f8
/* 08F53C 7F05AA0C 46002183 */  div.s $f6, $f4, $f0
/* 08F540 7F05AA10 0C007DF8 */  jal   sqrtf
/* 08F544 7F05AA14 46083300 */   add.s $f12, $f6, $f8
/* 08F548 7F05AA18 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08F54C 7F05AA1C 27BD0020 */  addiu $sp, $sp, 0x20
/* 08F550 7F05AA20 03E00008 */  jr    $ra
/* 08F554 7F05AA24 00000000 */   nop   
)
#endif
  

