#ifndef _CHEAT_BUTTONS_H_
#define _CHEAT_BUTTONS_H_
#include "ultra64.h"

struct struct_15 {
    u8 cheat_id;
    u8 count_of_something;
    u8 field_2;
    u8 field_3;
    u16 * anonymous_1;
    int anonymous_2;
    int maskfield;
};

extern char off_CODE_bss_80079E30[0x4C];

u32 cheatIsEnemyRockets(u32 cheatindex);
void turn_on_cheat_for_players(u32 cheatindex);
void cheat_buttons_mp_related(void);
s32 cheatCheckIfOn(CHEAT_ID cheat);

#endif
