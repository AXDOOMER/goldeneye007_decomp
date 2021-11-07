#ifndef _MP_WATCH_H_
#define _MP_WATCH_H_
#include "ultra64.h"

typedef enum TEXTCOLORS {
    GREEN_NORMAL=0,
    GREEN_HIGHLIGHT,
    RED_NORMAL,
    RED_HIGHLIGHT,
    BLUE_NORMAL,
    BLUE_HIGHLIGHT
} TEXTCOLORS;

s32 sub_GAME_7F0C2024(int param_1, int param_2, int param_3, int param_4, int param_5);

s32 sub_GAME_7F0C2114(int param_1, int param_2, int param_3, int param_4, int param_5);

void mpwatchUnpauseGame(void);
Gfx *display_text_for_playerdata_on_MP_menu(Gfx *gdl, s32 x, s32 y, u16* arg3, TEXTCOLORS text_color);

s32 checkGamePaused(void);

void sub_GAME_7F0C2530(int arg0);
void get_points_for_mp_player(int arg0);
void mpwatchSetStopPlayFlag(void);

#endif
