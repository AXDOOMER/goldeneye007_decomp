#ifndef _UNK_0A1DA0_H_
#define _UNK_0A1DA0_H_
#include "ultra64.h"

extern u32 D_80040960[];

extern u32 D_80040980;
extern u32 D_80040984;
extern u32 D_80040988;
extern u32 D_8004098C;
extern u32 D_80040990;
extern u32 watch_screen_index;
extern u32 controller_options_index;
extern u32 game_options_index;

void sub_GAME_7F0A47D4(void);
void sub_GAME_7F0A47FC(void);
void sub_GAME_7F0A28D4(void);
void sub_GAME_7F0A4528(Gfx *arg0, s32 arg1);
void sub_GAME_7F0A4824(Gfx *arg0, s32 arg1);
Gfx * sub_GAME_7F0A2C44(Gfx *arg0);

#endif
