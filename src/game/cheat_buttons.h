#ifndef _CHEAT_BUTTONS_H_
#define _CHEAT_BUTTONS_H_
#include "ultra64.h"

enum CHEAT_MASK {
    CHEAT_MASK_0 = 0,

    /**
     * Title screen related.
     */
    CHEAT_MASK_1 = (1 << 0),

    /**
     * Maybe single player?
     */
    CHEAT_MASK_2 = (1 << 1),

    CHEAT_MASK_MULTIPLAYER = (1 << 2),
    
    CHEAT_MASK_8 = (1 << 3),

    /**
     * Text related when turning cheats on and off.
     */
    CHEAT_MASK_16 = (1 << 4),

    /**
     * Seems to be a "applies to all players" or "global" flag.
     * Logic branch when turning cheats on (set = single player, vs off = iterate all players)
     * Text related when turning cheats on and off
     */
    CHEAT_MASK_GLOBAL = (1 << 5),

    /**
     * Checked when disabling cheat
     */
    CHEAT_MASK_64 = (1 << 6),

    CHEAT_MASK_128 = (1 << 7),
    CHEAT_MASK_256 = (1 << 8),
    CHEAT_MASK_512 = (1 << 9),
    CHEAT_MASK_1024 = (1 << 10)

    // ... 
};

extern u8 g_CheatPlayerTextRelated[0x4C];

u32 cheatIsEnemyRockets(u32 cheatindex);
void cheatButtonTurnOnCheatForPlayers(u32 cheatindex);
void cheat_buttons_mp_related(void);
s32 cheatCheckIfOn(CHEAT_ID cheat);
s32 cheatCheckIfMPCheat(s32 arg0);
void cheatDisableAllCheats(void);
char *cheatGetMenuTextPointer(s32 arg0);

#endif
