#ifndef _LVL_H_
#define _LVL_H_
#include "ultra64.h"
#include "bondconstants.h"

struct ramrom_struct {
    u32 *address;
    u32 locked;
};

extern s32 D_800483C4;
extern s32 g_ClockTimer;
extern s32 g_GlobalTimer;
extern f32 g_GlobalTimerDelta;
extern u32 *ptr_jfont_DL;
extern s32 dword_CODE_bss_8008C264;
extern s32 dword_CODE_bss_8008C268;
extern s32 dword_CODE_bss_8008C26C;
extern char ramrom_data_target[0x380];
extern s32 record_slot_num;
extern s32 address_demo_loaded;
extern s32 dword_CODE_bss_8008C5F8;

void lvInitDebugNoticeList(void);
Gfx * lvRender(Gfx *);
void set_difficulty(s32 arg0);
void manage_mp_game(void);
void sub_GAME_7F0BF800(void);
void unload_stage_text_data(void);
DIFFICULTY get_current_difficulty(void);
void stage_load(s32 arg0);

void set_mp_time(s32 arg0);
void set_mp_point(s32 arg0);
void set_controls_locked_flag(s32 arg0);

#endif
