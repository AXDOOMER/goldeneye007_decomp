#include "ultra64.h"
#include "game/cheat_buttons_objectrelated.h"

//not s32 some arrary, ill get to when at that file

#ifdef NONMATCHING
void sub_GAME_7F000B60(void) {
    player_gait_object = &D_8003C580;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F000B60
/* 035690 7F000B60 3C0E8004 */  lui   $t6, %hi(dword_D_8003C580) # $t6, 0x8004
/* 035694 7F000B64 25CEC580 */  addiu $t6, %lo(dword_D_8003C580) # addiu $t6, $t6, -0x3a80
/* 035698 7F000B68 3C018004 */  lui   $at, %hi(player_gait_object)
/* 03569C 7F000B6C 03E00008 */  jr    $ra
/* 0356A0 7F000B70 AC2EC650 */   sw    $t6, %lo(player_gait_object)($at)
)
#endif

