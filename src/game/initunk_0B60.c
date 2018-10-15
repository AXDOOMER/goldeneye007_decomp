#include "ultra64.h"

//not s32 some arrary, ill get to when at that file
extern s32 D_8003C580;
extern s32 D_8003C650;

#ifdef NONMATCHING
void sub_GAME_7F000B60(void) {
    D_8003C650 = &D_8003C580;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F000B60
/* 035690 7F000B60 3C0E8004 */  lui   $t6, %hi(D_8003C580) # $t6, 0x8004
/* 035694 7F000B64 25CEC580 */  addiu $t6, %lo(D_8003C580) # addiu $t6, $t6, -0x3a80
/* 035698 7F000B68 3C018004 */  lui   $at, %hi(D_8003C650)
/* 03569C 7F000B6C 03E00008 */  jr    $ra
/* 0356A0 7F000B70 AC2EC650 */   sw    $t6, %lo(D_8003C650)($at)
)
#endif

