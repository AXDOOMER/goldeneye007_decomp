#ifndef _WATCH_H_
#define _WATCH_H_
#include "ultra64.h"
#include "bondconstants.h"

typedef enum WATCH_INDEX {
    WATCH_INDEX_MISSION_STATUS = 0,
    WATCH_INDEX_INVENTORY,
    WATCH_INDEX_CONTROL_OPTIONS,
    WATCH_INDEX_GAME_OPTIONS,
    WATCH_INDEX_MISSION_BRIEFING
} WATCH_INDEX;

typedef enum WATCH_CONTROLLER_OPTIONS_INDEX {
    CONTROLLER_OPTIONS_INDEX_STYLE = 0,
    CONTROLLER_OPTIONS_INDEX_INPUTS
} WATCH_CONTROLLER_OPTIONS_INDEX;

typedef enum WATCH_GAME_OPTIONS_INDEX {
    GAME_OPTIONS_INDEX_MUSIC = 0,
    GAME_OPTIONS_INDEX_FX,
    GAME_OPTIONS_INDEX_LOOK_UPDOWN,
    GAME_OPTIONS_INDEX_AUTO_AIM,
    GAME_OPTIONS_INDEX_AIM_CONTROL,
    GAME_OPTIONS_INDEX_SIGHT_ONSCREEN,
    GAME_OPTIONS_INDEX_LOOK_AHEAD,
    GAME_OPTIONS_INDEX_AMMO_ONSCREEN,
    GAME_OPTIONS_INDEX_SCREEN_SIZE,
    GAME_OPTIONS_INDEX_RATIO
} WATCH_GAME_OPTIONS_INDEX;

typedef enum WATCH_BRIEF_INDEX {
    BRIEF_INDEX_BACKGROUND = 0,
    BRIEF_INDEX_M,
    BRIEF_INDEX_Q,
    BRIEF_INDEX_MONEYPENNY,
    BRIEF_INDEX_OBJECTIVES
} WATCH_BRIEF_INDEX;

struct game_options {
    u16 text[4];
    u32 current_value;
};

extern struct game_options game_options_entries[];

void reset_controller_options_index();

void reset_game_options_index();

void zero_D_800409A4();

void draw_selected_page_rectangle(s32 watch_screen_index, s32 arg2);

f32 sub_GAME_7F0A6A2C(f32 arg0);

f32 sub_GAME_7F0A95C4(f32 param_1, f32 param_2, f32 param_3);

SCREEN_RATIO_OPTION get_screen_ratio();

void set_screen_ratio(SCREEN_RATIO_OPTION ratio_option);

s32 cur_player_get_autoaim(void);
u32 cur_player_get_lookahead(void);
void cur_player_set_autoaim(u32 param_1);
int cur_player_get_control_type(void);
u32 cur_player_get_sight_onscreen_control();
u32 cur_player_get_ammo_onscreen_setting(void);
u32 cur_player_get_aim_control(void);
u32 cur_player_get_screen_setting(void);
u16 call_sndGetSfxSlotFirstNaturalVolume(void);
u32 get_cur_player_look_vertical_inverted(void);
u16 get_mTrack2Vol(void);
void set_mTrack2Vol(u16 param_1);
void sub_GAME_7F0A91A0(u16 arg0);
void cur_player_set_control_type(int type);
void init_watch_at_start_of_stage(int a);

Gfx *draw_watch_game_options_page(Gfx *gdl, s32 param_2);
Gfx *draw_watch_control_options_page(Gfx *gdl, s32 param_2);

Gfx *unused_draw_watch_inventory_page(Gfx *gdl, s32 param_2);

#endif


