#ifndef _WATCH_H_
#define _WATCH_H_
#include "ultra64.h"

typedef enum WATCH_INDEX {
    WATCH_INDEX_MISSION_STATUS = 0,
    WATCH_INDEX_INVENTORY,
    WATCH_INDEX_CONTROL_OPTIONS,
    WATCH_INDEX_GAME_OPTIONS,
    WATCH_INDEX_MISSION_BRIEFING
} WATCH_INDEX;

typedef enum WATCH_BRIEF_INDEX {
    BRIEF_INDEX_BACKGROUND = 0,
    BRIEF_INDEX_M,
    BRIEF_INDEX_Q,
    BRIEF_INDEX_MONEYPENNY,
    BRIEF_INDEX_OBJECTIVES
} WATCH_BRIEF_INDEX;

void reset_controller_options_index();

void reset_game_options_index();

void zero_D_800409A4();

f32 sub_GAME_7F0A95C4(f32 param_1, f32 param_2, f32 param_3);

#endif


