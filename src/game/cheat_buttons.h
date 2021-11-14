#ifndef _CHEAT_BUTTONS_H_
#define _CHEAT_BUTTONS_H_
#include "ultra64.h"

enum CHEAT_MASK {
    CHEAT_MASK_0 = 0,
    CHEAT_MASK_1 = (1 << 0),
    CHEAT_MASK_2 = (1 << 1),
    CHEAT_MASK_MULTIPLAYER = (1 << 2),
    CHEAT_MASK_8 = (1 << 3),
    CHEAT_MASK_16 = (1 << 4),
    CHEAT_MASK_32 = (1 << 5),
    CHEAT_MASK_64 = (1 << 6),
    CHEAT_MASK_128 = (1 << 7),
    CHEAT_MASK_256 = (1 << 8),
    CHEAT_MASK_512 = (1 << 9),
    CHEAT_MASK_1024 = (1 << 10)

    // ... 
};

struct struct_15 {
    u8 cheat_id;
    u8 count_of_something;
    u8 field_2;
    u8 field_3;
    u16 * anonymous_1;
    int anonymous_2;

    /**
     * 0x0 = ?
     * 0x1 = ?
     * 0x2 = ?
     * 0x4 = multiplayer
     */
    int maskfield;
};

extern char off_CODE_bss_80079E30[0x4C];

u32 cheatIsEnemyRockets(u32 cheatindex);
void cheatButtonTurnOnCheatForPlayers(u32 cheatindex);
void cheat_buttons_mp_related(void);
s32 cheatCheckIfOn(CHEAT_ID cheat);
s32 cheatCheckIfMPCheat(s32 arg0);
void cheatDisableAllCheats(void);

#endif
