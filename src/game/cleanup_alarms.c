#include "ultra64.h"



#ifdef NONMATCHING
void cleanupAlarms(void) {
    stop_alarm();
    sub_GAME_7F055EF8();
}
#else
GLOBAL_ASM(
.text
glabel cleanupAlarms
/* 03C000 7F0074D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03C004 7F0074D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03C008 7F0074D8 0FC1578B */  jal   stop_alarm
/* 03C00C 7F0074DC 00000000 */   nop   
/* 03C010 7F0074E0 0FC157BE */  jal   sub_GAME_7F055EF8
/* 03C014 7F0074E4 00000000 */   nop   
/* 03C018 7F0074E8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03C01C 7F0074EC 27BD0018 */  addiu $sp, $sp, 0x18
/* 03C020 7F0074F0 03E00008 */  jr    $ra
/* 03C024 7F0074F4 00000000 */   nop   
)
#endif

