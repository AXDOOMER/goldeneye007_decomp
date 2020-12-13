#ifndef _WATCH_H_
#define _WATCH_H_
#include "ultra64.h"

#define WATCH_INDEX_MISSION_STATUS      0
#define WATCH_INDEX_INVENTORY           1
#define WATCH_INDEX_CONTROL_OPTIONS     2
#define WATCH_INDEX_GAME_OPTIONS        3
#define WATCH_INDEX_MISSION_BRIEFING    4

#define BRIEF_INDEX_BACKGROUND  0
#define BRIEF_INDEX_M           1
#define BRIEF_INDEX_Q           2
#define BRIEF_INDEX_MONEYPENNY  3
#define BRIEF_INDEX_OBJECTIVES  4

void zero_D_80040998();

void reset_game_options_index();

void zero_D_800409A4();

f32 sub_GAME_7F0A95C4(f32 param_1, f32 param_2, f32 param_3);

#endif


