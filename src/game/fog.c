#include "ultra64.h"

#include "bondtypes.h"
#include "bondconstants.h"
#include "fr.h"
#include "game/bg.h"
#include "game/bondview.h"
#include "game/fog.h"

struct pervasiveness {
    f32 unk00;
    f32 unk04;
    u32 unk08;
    u32 unk0c;
    f32 unk10;
    f32 unk14;
};

// bss
//CODE.bss:800825C0
s32 g_FogSkyIsEnabled;
//CODE.bss:800825C4
f32 *ptr_nearfog_enviroment_values;
//CODE.bss:800825C8

struct pervasiveness buffer_far_pervasiveness;
// //CODE.bss:800825CC
// s32 far_fog;
// //CODE.bss:800825D0
// s32 D_800825D0;
// //CODE.bss:800825D4
// s32 D_800825D4;
// //CODE.bss:800825D8
// s32 flt_CODE_bss_800825D8;
// //CODE.bss:800825DC
// s32 flt_CODE_bss_800825DC;

//CODE.bss:800825E0
f32 buffer_far_ambiant;
//CODE.bss:800825E4
f32 bg_dif_light;
//CODE.bss:800825E8
struct fog_element *env_table_hit;
//CODE.bss:800825EC
struct fog_element * env_table_match_start;
//CODE.bss:800825F0
struct fog_element * env_table_match_end;
//CODE.bss:800825F4
s32 D_800825F4;


// data
//D:80044DC0
s32 D_80044DC0 = 0;
//D:80044DC4
f32 g_FogNearFogValue = 3.4028235e38;
//D:80044DC8
f32 near_fog_times_intensity = 0.0;
//D:80044DCC

struct fog_loaded ptr_current_data = { 
    0x384, // s32 dif_in_light;
    0x3e8, // u32 far_ambiantlight;
    0,     // u8  red;
    0,     // u8  green;
    0,     // u8  blue;
    0,     // u8  clouds;
    0.0f,  // f32 cloudrepeat;
    0,     // s16 skyimageid;
    0.0f,  // f32 cloudred;
    0.0f,  // f32 cloudgreen;
    0.0f,  // f32 cloudblue;
    0,     // u8  iswater;
    0.0f,  // f32 waterrepeat;
    0,     // s16 waterimageid;
    0.0f,  // f32 waterred;
    0.0f,  // f32 watergreen;
    0.0f,  // f32 waterblue;
    0.0f,  // f32 waterconcavity;
    0,
    0
};

//D:80044E10
struct fog_element fog_tables[] = {
    {0x16, 15.0, 3500.0, 2000.0, 2500.0, 2000.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 8, 1, 5000.0, 0, 0, 170.0, 100.0, 40.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 30.0},
    {0x17, 10.0, 10000.0, 2500.0, 5000.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x18, 10.0, 3000.0, 2000.0, 3000.0, 500.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x19, 10.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 8, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 1, 0, 0.0, 255.0, 255.0, 25.0},
    {0x7D, 20.0, 15000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 8, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 1, 0, 0.0, 255.0, 255.0, 25.0},
    {0x1D, 10.0, 7500.0, 5000.0, 6000.0, 1000.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x10, 0x18, 0x20, 1, 5000.0, 0, 0, 225.0, 175.0, 100.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 25.0},
    {0x1E, 10.0, 3000.0, 1600.0, 2000.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 8, 1, 7500.0, 0, 0, 70.0, 199.0, 186.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 25.0},
    {0x1F, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x28, 0, 0, 1, 10000.0, 0, 0, 220.0, 0.0, 20.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x21, 5.0, 15000.0, 3333.0, 4444.0, 600.0, 0.0, 0x3E7, 0x3E3, 0x3E8, 0x10, 0x30, 0x60, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x3A5, 30.0, 15000.0, 3333.0, 4444.0, 600.0, 0.0, 0x3E7, 0x3E3, 0x3E8, 0x10, 0x30, 0x60, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x22, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3DE, 0x3E8, 0x10, 0x20, 0x10, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x86, 10.0, 1000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3DE, 0x3E8, 0x40, 0x80, 0x40, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x23, 10.0, 15000.0, 6000.0, 8000.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x10, 0x30, 0x40, 1, 5000.0, 0, 0, 25.0, 25.0, 25.0, 0, 0, 0, 0, -1000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x24, 2.0, 2500.0, 4444.0, 5555.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x60, 0x80, 1, 10000.0, 0, 0, 240.0, 120.0, 30.0, 0, 0, 0, 0, 0.0, 1, 0, 0.0, 255.0, 255.0, 7.0},
    {0x25, 10.0, 2500.0, 1500.0, 2500.0, 1000.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x20, 0, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x26, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x18, 0x28, 1, 10000.0, 0, 0, 160.0, 160.0, 190.0, 0, 0, 0, 0, -500.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x27, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E1, 0x3E8, 8, 0, 8, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -3000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x29, 10.0, 9500.0, 3333.0, 4444.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x80, 0xA0, 1, 5000.0, 0, 0, 255.0, 255.0, 0.0, 0, 0, 0, 0, -10000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x2B, 2.0, 2000.0, 2500.0, 3055.0, 750.0, 0.0, 0x3E7, 0x3BD, 0x3E8, 0x20, 0x10, 0x10, 1, 5000.0, 0, 0, 58.0, 17.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 20.0},
    {0x3AF, 2.0, 8000.0, 6000.0, 8000.0, 800.0, 0.0, 0x3E7, 0x3DF, 0x3E8, 0x20, 0x10, 0x10, 1, 5000.0, 0, 0, 58.0, 17.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x1B, 10.0, 10000.0, 1000.0, 15000.0, 750.0, 0.0, 0x3E7, 0x3E4, 0x41A, 0x10, 0, 0, 1, 5000.0, 0, 0, 58.0, 17.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xD1, 10.0, 2500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x80, 0x78, 0x70, 0, 0.0, 0, 0, 130.0, 120.0, 110.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x135, 10.0, 2000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x80, 0x78, 0x70, 0, 0.0, 0, 0, 130.0, 120.0, 110.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x199, 10.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x80, 0x78, 0x70, 0, 0.0, 0, 0, 130.0, 120.0, 110.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0xF1, 10.0, 7000.0, 3333.0, 4444.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x80, 0xA0, 1, 5000.0, 0, 0, 255.0, 255.0, 0.0, 0, 0, 0, 0, -10000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x155, 10.0, 5500.0, 3333.0, 4444.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x80, 0xA0, 1, 5000.0, 0, 0, 255.0, 255.0, 0.0, 0, 0, 0, 0, -10000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x1B9, 10.0, 4000.0, 3333.0, 4444.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x60, 0x80, 0xA0, 1, 5000.0, 0, 0, 255.0, 255.0, 0.0, 0, 0, 0, 0, -10000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xEE, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x18, 0x18, 1, 10000.0, 0, 0, 120.0, 120.0, 120.0, 0, 0, 0, 0, -500.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x152, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x18, 0x18, 1, 10000.0, 0, 0, 120.0, 120.0, 120.0, 0, 0, 0, 0, -500.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x1B6, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x18, 0x18, 1, 10000.0, 0, 0, 120.0, 120.0, 120.0, 0, 0, 0, 0, -500.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0xEF, 10.0, 7500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E1, 0x3E8, 8, 0, 8, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -3000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x153, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E1, 0x3E8, 8, 0, 8, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -3000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x1B7, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E1, 0x3E8, 8, 0, 8, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -3000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xC8, 10.0, 7500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x12C, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x190, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x28, 10.0, 20000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x50, 0x38, 1, 5000.0, 0, 0, 255.0, 108.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xF0, 10.0, 20000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x50, 0x38, 1, 5000.0, 0, 0, 255.0, 108.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x154, 10.0, 20000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x50, 0x38, 1, 5000.0, 0, 0, 255.0, 108.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0x1B8, 10.0, 20000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x18, 0x50, 0x38, 1, 5000.0, 0, 0, 255.0, 108.0, 0.0, 0, 0, 0, 0, -1000.0, 1, 0, 0.0, 255.0, 255.0, 0.0},
    {0xE7, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x28, 0, 0, 1, 10000.0, 0, 0, 220.0, 0.0, 20.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x14B, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x28, 0, 0, 1, 10000.0, 0, 0, 220.0, 0.0, 20.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x1AF, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x28, 0, 0, 1, 10000.0, 0, 0, 220.0, 0.0, 20.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x1C, 10.0, 15000.0, 3000.0, 4000.0, 600.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 1, 7500.0, 0, 0, 83.0, 72.0, 65.0, 0, 0, 0, 0, -5000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x80, 30.0, 15000.0, 3000.0, 4000.0, 600.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0, 0, 0, 1, 7500.0, 0, 0, 83.0, 72.0, 65.0, 0, 0, 0, 0, -5000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x20, 10.0, 20000.0, 3000.0, 4000.0, 600.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0x10, 0x30, 0x60, 1, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, -5000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x84, 10.0, 10000.0, 3000.0, 4000.0, 600.0, 0.0, 0x3E7, 0x3CC, 0x3E8, 0, 0, 0, 1, 7500.0, 0, 0, 83.0, 10.0, 10.0, 0, 0, 0, 0, -5000.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0}
};

struct fog_element2 fog_tables2[] = {
    {0xFFFFFFFF, 0, 0x10, 0x40, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0x1A, 0x10, 0x30, 0x60, 1, 3000.0, 0, 0, 230.0, 230.0, 230.0, 1, 0, 0, 0, -150.0, 2, 0, 255.0, 255.0, 150.0, 0.0},
    {0x36, 0x30, 0x40, 0x10, 0, 5000.0, 0, 0, 255.0, 255.0, 255.0, 0, 0, 0, 0, 0.0, 0, 0, 0.0, 0.0, 0.0, 0.0},
    {0}
};

// forward declarations

void copy_table1_env_to_current(struct fog_element *arg0);
void copy_table2_env_to_current(struct fog_element2 *arg0);

// end forward declarations



void sub_GAME_7F0BA720(s32 a, s32 b)
{
    return;
}


struct fog_loaded *get_ptr_currentdata(void)
{
    return &ptr_current_data;
}

f32 get_near_fog_value(void)
{
    return g_FogNearFogValue;
}

f32 square_near_fog_value(void)
{
    return g_FogNearFogValue * g_FogNearFogValue;
}






/**
 * Address 0x7F0BA758.
*/
void copy_table1_env_to_current(struct fog_element *arg0)
{
    f32 zrange[2]; // 48
    f32 pk0;
    f32 pk4;
    f32 temp_f0;
    f32 sp20; // 32
    f32 sp1C; // 28

    viSetZRange(arg0->blendmultiplier, arg0->farfog);
    viGetZRange(&zrange);

    temp_f0 = sub_GAME_7F0B4878();
    zrange[0] /= temp_f0;
    zrange[1] /= temp_f0;

    bg_dif_light = ((f32) arg0->dif_in_light / 1000.0f);
    buffer_far_ambiant = ((f32) arg0->far_ambiantlight / 1000.0f);

    g_FogNearFogValue = ((zrange[1] - zrange[0]) *  buffer_far_ambiant) + zrange[0];
    near_fog_times_intensity = ((zrange[1] - zrange[0]) * bg_dif_light) + zrange[0];

    buffer_far_pervasiveness.unk00 = (arg0->blendmultiplier / temp_f0);
    pk0 = buffer_far_pervasiveness.unk00;
    buffer_far_pervasiveness.unk04 = (arg0->farfog / temp_f0);
    pk4 = buffer_far_pervasiveness.unk04;

    // numerator is constant 128.0f
    sp20 = (256.0f * (0.5f -         0.0f)) / (buffer_far_ambiant - bg_dif_light);
    sp1C = (256.0f * (0.5f - bg_dif_light)) / (buffer_far_ambiant - bg_dif_light);

    buffer_far_pervasiveness.unk10 = ((pk4 * -sp20 * (pk0 + 1.0f)) / (pk4 - pk0)) / 255.0f;
    buffer_far_pervasiveness.unk14 = ((sp20 * (pk4 + 1.0f) / (pk4 - pk0)) + sp1C) / 255.0f;

    ptr_current_data.dif_in_light = (s32) arg0->dif_in_light;
    ptr_current_data.far_ambiantlight = arg0->far_ambiantlight;
    ptr_current_data.red = arg0->red;
    ptr_current_data.green = arg0->green;
    ptr_current_data.blue = arg0->blue;
    ptr_current_data.clouds = arg0->clouds;
    ptr_current_data.cloudrepeat = arg0->cloudrepeat;
    ptr_current_data.skyimageid = (s16) arg0->skyimageid;
    ptr_current_data.cloudred = arg0->cloudred;
    ptr_current_data.cloudgreen = arg0->cloudgreen;
    ptr_current_data.cloudblue = arg0->cloudblue;
    ptr_current_data.iswater = arg0->iswater;
    ptr_current_data.waterrepeat = arg0->waterrepeat;
    ptr_current_data.waterimageid = (s16) arg0->waterimageid;
    ptr_current_data.waterred = arg0->waterred;
    ptr_current_data.watergreen = arg0->watergreen;
    ptr_current_data.waterblue = arg0->waterblue;
    ptr_current_data.waterconcavity = arg0->waterconcavity;

    if (arg0->nearfog == 0.0f)
    {
        ptr_nearfog_enviroment_values = NULL;
    }
    else
    {
        ptr_nearfog_enviroment_values = &arg0->nearfog;
    }

    g_FogSkyIsEnabled = 1;
}




/**
 * Address 0x7F0BA9D0.
*/
void copy_table2_env_to_current(struct fog_element2 *arg0)
{
    ptr_current_data.red = arg0->red;
    ptr_current_data.green = arg0->green;
    ptr_current_data.blue = arg0->blue;
    ptr_current_data.clouds = arg0->clouds;
    ptr_current_data.cloudrepeat = arg0->cloudrepeat;
    ptr_current_data.skyimageid = arg0->skyimageid;
    ptr_current_data.cloudred = arg0->cloudred;
    ptr_current_data.cloudgreen = arg0->cloudgreen;
    ptr_current_data.cloudblue = arg0->cloudblue;
    ptr_current_data.iswater = arg0->iswater;
    ptr_current_data.waterrepeat = arg0->waterrepeat;
    ptr_current_data.waterimageid = arg0->waterimageid;
    ptr_current_data.waterred = arg0->waterred;
    ptr_current_data.watergreen = arg0->watergreen;
    ptr_current_data.waterblue = arg0->waterblue;
    ptr_current_data.waterconcavity = arg0->waterconcavity;
}






void sub_GAME_7F0BAA5C(s32 a)
{
    return;
}






/**
 * Address 0x7F0BAA64.
*/
void load_enviroment(s32 level_id, s32 arg1)
{
    struct fog_element *phi_v1;
    struct fog_element2 *phi_v2;
    struct fog_element2 *sp1C;
    s32 num_players;

    sp1C = NULL;

    num_players = getPlayerCount();
    
    if (num_players == 1)
    {
        num_players = 0;
    }

    g_FogNearFogValue = 3.4028235e38f;
    near_fog_times_intensity = 0.0f;

    if (arg1)
    {
        for (phi_v1 = &fog_tables[0]; phi_v1->stageID != 0; phi_v1++)
        {
            if (phi_v1->stageID == (level_id + 900))
            {
                env_table_hit = phi_v1;
                env_table_match_start = phi_v1;
                env_table_match_end = phi_v1 + 1;

                copy_table1_env_to_current(env_table_hit);

                return;
            }
        }
    }
    
    for (phi_v1 = &fog_tables[0]; phi_v1->stageID != 0; phi_v1++)
    {
        if (phi_v1->stageID == (level_id + (num_players * 100)))
        {
            env_table_hit = phi_v1;
            env_table_match_start = phi_v1;
            env_table_match_end = phi_v1 + 1;

            copy_table1_env_to_current(env_table_hit);

            return;
        }
    }

    if(1)
    {
        // removed
    }

    if (num_players >= 2)
    {
        for (phi_v1 = &fog_tables[0]; phi_v1->stageID != 0; phi_v1++)
        {
            if (phi_v1->stageID == (num_players * 100))
            {
                env_table_hit = phi_v1;
                env_table_match_start = phi_v1;
                env_table_match_end = phi_v1 + 1;

                copy_table1_env_to_current(env_table_hit);

                return;
            }
        }
    }

    viSetZRange(15.0f, 10000.0f);
    g_FogSkyIsEnabled = 0;

    for (phi_v2 = fog_tables2; phi_v2->stageID != 0; phi_v2++)
    {
        if (phi_v2->stageID == level_id)
        {
            sp1C = phi_v2;

            if(1)
            {
                // removed.
                // break or return maybe?
            }
        }
    }

    if (sp1C == NULL)
    {
        sp1C = &fog_tables2[0];
    }

    copy_table2_env_to_current(sp1C);
    env_table_hit = NULL;
}




/**
 * Address 0x7F0BACA8.
*/
void switch_to_solosky2(f32 arg0)
{
    static struct fog_element dword_CODE_bss_800825F8;

    dword_CODE_bss_800825F8 = *env_table_match_start;

    dword_CODE_bss_800825F8.blendmultiplier = 
        env_table_match_start->blendmultiplier
        + (arg0 * (env_table_match_end->blendmultiplier - env_table_match_start->blendmultiplier));

    dword_CODE_bss_800825F8.farfog = 
        env_table_match_start->farfog
        + (arg0 * (env_table_match_end->farfog - env_table_match_start->farfog));

    dword_CODE_bss_800825F8.dif_in_light = 
        (f32)env_table_match_start->dif_in_light
        + (arg0 * ((f32)env_table_match_end->dif_in_light - (f32)env_table_match_start->dif_in_light));

    dword_CODE_bss_800825F8.far_ambiantlight = 
        (f32)env_table_match_start->far_ambiantlight
        + (arg0 * ((f32)env_table_match_end->far_ambiantlight - (f32)env_table_match_start->far_ambiantlight));
    
    dword_CODE_bss_800825F8.red = 
        (f32)env_table_match_start->red
        + (arg0 * ((f32)env_table_match_end->red - (f32)env_table_match_start->red));

    dword_CODE_bss_800825F8.green = 
        (f32)env_table_match_start->green
        + (arg0 * ((f32)env_table_match_end->green - (f32)env_table_match_start->green));

    dword_CODE_bss_800825F8.blue = 
        (f32)env_table_match_start->blue
        + (arg0 * ((f32)env_table_match_end->blue - (f32)env_table_match_start->blue));

    dword_CODE_bss_800825F8.red &= 0xf8;
    dword_CODE_bss_800825F8.green &= 0xf8;
    dword_CODE_bss_800825F8.blue &= 0xf8;

    copy_table1_env_to_current(&dword_CODE_bss_800825F8);
}




/**
 * @param gdl:
 * @param arg1: not used?
 * 
 * Address 0x7F0BB070.
*/
Gfx *sub_GAME_7F0BB070(Gfx *gdl, s32 arg1)
{
    if (g_FogSkyIsEnabled == 0)
    {
        return gdl;
    }

    // note: both branches are exactly the same.
    // maybe one has debug code?
    if (arg1)
    {
        gDPSetFogColor(gdl++, ptr_current_data.red, ptr_current_data.green, ptr_current_data.blue, 0xff);
        gSPFogPosition(gdl++, ptr_current_data.dif_in_light, ptr_current_data.far_ambiantlight);
    }
    else
    {
        gDPSetFogColor(gdl++, ptr_current_data.red, ptr_current_data.green, ptr_current_data.blue, 0xff);
        gSPFogPosition(gdl++, ptr_current_data.dif_in_light, ptr_current_data.far_ambiantlight);
    }

    gSPSetGeometryMode(gdl++, G_FOG);
    gDPSetAlphaDither(gdl++, G_AD_NOISE);

    return gdl;
}





#ifdef NONMATCHING

void sub_GAME_7F0BB298(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BB298
/* 0EFDC8 7F0BB298 3C0E8008 */  lui   $t6, %hi(g_FogSkyIsEnabled) 
/* 0EFDCC 7F0BB29C 8DCE25C0 */  lw    $t6, %lo(g_FogSkyIsEnabled)($t6)
/* 0EFDD0 7F0BB2A0 24820008 */  addiu $v0, $a0, 8
/* 0EFDD4 7F0BB2A4 3C0FB600 */  lui   $t7, 0xb600
/* 0EFDD8 7F0BB2A8 15C00003 */  bnez  $t6, .L7F0BB2B8
/* 0EFDDC 7F0BB2AC 3C180001 */   lui   $t8, 1
/* 0EFDE0 7F0BB2B0 03E00008 */  jr    $ra
/* 0EFDE4 7F0BB2B4 00801025 */   move  $v0, $a0

.L7F0BB2B8:
/* 0EFDE8 7F0BB2B8 AC8F0000 */  sw    $t7, ($a0)
/* 0EFDEC 7F0BB2BC AC980004 */  sw    $t8, 4($a0)
/* 0EFDF0 7F0BB2C0 03E00008 */  jr    $ra
/* 0EFDF4 7F0BB2C4 00000000 */   nop   
)
#endif





/**
 * Address 0x7F0BB2C8.
*/
s32 fogPositionIsVisibleThroughFog(struct coord3d *pos, f32 range)
{
    struct coord3d sp24;
    f32 ff;
    struct coord3d *player_pos;
    Mtxf *player_mtx;

    if (g_FogSkyIsEnabled == 0)
    {
        return 1;
    }

    player_pos = bondviewGetCurrentPlayersPosition();
    player_mtx = currentPlayerGetMatrix10CC();

    sp24.f[0] = pos->f[0] - player_pos->f[0];
    sp24.f[1] = pos->f[1] - player_pos->f[1];
    sp24.f[2] = pos->f[2] - player_pos->f[2];

    ff = (((sp24.f[0] * player_mtx->m[0][0]) + (sp24.f[1] * player_mtx->m[0][1]) + (sp24.f[2] * player_mtx->m[0][2])));

    if (ff > (g_FogNearFogValue + range))
    {
        return 0;
    }

    return 1;
}





// no change
u32 return_nearfog_values(void)
{
    return ptr_nearfog_enviroment_values;
}






#ifdef NONMATCHING

void if_sky_present_convert_values(void) {

}
#else
GLOBAL_ASM(
.text
glabel if_sky_present_convert_values
/* 0EFED4 7F0BB3A4 3C0E8008 */  lui   $t6, %hi(g_FogSkyIsEnabled) 
/* 0EFED8 7F0BB3A8 8DCE25C0 */  lw    $t6, %lo(g_FogSkyIsEnabled)($t6)
/* 0EFEDC 7F0BB3AC 55C00004 */  bnezl $t6, .L7F0BB3C0
/* 0EFEE0 7F0BB3B0 44801000 */   mtc1  $zero, $f2
/* 0EFEE4 7F0BB3B4 03E00008 */  jr    $ra
/* 0EFEE8 7F0BB3B8 24020002 */   li    $v0, 2

/* 0EFEEC 7F0BB3BC 44801000 */  mtc1  $zero, $f2
.L7F0BB3C0:
/* 0EFEF0 7F0BB3C0 C4840018 */  lwc1  $f4, 0x18($a0)
/* 0EFEF4 7F0BB3C4 3C028004 */  lui   $v0, %hi(ptr_current_data)
/* 0EFEF8 7F0BB3C8 24424DCC */  addiu $v0, %lo(ptr_current_data) # addiu $v0, $v0, 0x4dcc
/* 0EFEFC 7F0BB3CC 4602203C */  c.lt.s $f4, $f2
/* 0EFF00 7F0BB3D0 3C038008 */  lui   $v1, %hi(buffer_far_pervasiveness)
/* 0EFF04 7F0BB3D4 45020004 */  bc1fl .L7F0BB3E8
/* 0EFF08 7F0BB3D8 904F0008 */   lbu   $t7, 8($v0)
/* 0EFF0C 7F0BB3DC 03E00008 */  jr    $ra
/* 0EFF10 7F0BB3E0 24020002 */   li    $v0, 2

/* 0EFF14 7F0BB3E4 904F0008 */  lbu   $t7, 8($v0)
.L7F0BB3E8:
/* 0EFF18 7F0BB3E8 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0EFF1C 7F0BB3EC 44816000 */  mtc1  $at, $f12
/* 0EFF20 7F0BB3F0 448F3000 */  mtc1  $t7, $f6
/* 0EFF24 7F0BB3F4 246325C8 */  addiu $v1, $v1, %lo(buffer_far_pervasiveness)
/* 0EFF28 7F0BB3F8 05E10005 */  bgez  $t7, .L7F0BB410
/* 0EFF2C 7F0BB3FC 46803220 */   cvt.s.w $f8, $f6
/* 0EFF30 7F0BB400 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EFF34 7F0BB404 44815000 */  mtc1  $at, $f10
/* 0EFF38 7F0BB408 00000000 */  nop   
/* 0EFF3C 7F0BB40C 460A4200 */  add.s $f8, $f8, $f10
.L7F0BB410:
/* 0EFF40 7F0BB410 460C4403 */  div.s $f16, $f8, $f12
/* 0EFF44 7F0BB414 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EFF48 7F0BB418 E4B00000 */  swc1  $f16, ($a1)
/* 0EFF4C 7F0BB41C 90580009 */  lbu   $t8, 9($v0)
/* 0EFF50 7F0BB420 44989000 */  mtc1  $t8, $f18
/* 0EFF54 7F0BB424 07010004 */  bgez  $t8, .L7F0BB438
/* 0EFF58 7F0BB428 46809120 */   cvt.s.w $f4, $f18
/* 0EFF5C 7F0BB42C 44813000 */  mtc1  $at, $f6
/* 0EFF60 7F0BB430 00000000 */  nop   
/* 0EFF64 7F0BB434 46062100 */  add.s $f4, $f4, $f6
.L7F0BB438:
/* 0EFF68 7F0BB438 460C2283 */  div.s $f10, $f4, $f12
/* 0EFF6C 7F0BB43C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EFF70 7F0BB440 E4AA0004 */  swc1  $f10, 4($a1)
/* 0EFF74 7F0BB444 9059000A */  lbu   $t9, 0xa($v0)
/* 0EFF78 7F0BB448 44994000 */  mtc1  $t9, $f8
/* 0EFF7C 7F0BB44C 07210004 */  bgez  $t9, .L7F0BB460
/* 0EFF80 7F0BB450 46804420 */   cvt.s.w $f16, $f8
/* 0EFF84 7F0BB454 44819000 */  mtc1  $at, $f18
/* 0EFF88 7F0BB458 00000000 */  nop   
/* 0EFF8C 7F0BB45C 46128400 */  add.s $f16, $f16, $f18
.L7F0BB460:
/* 0EFF90 7F0BB460 460C8183 */  div.s $f6, $f16, $f12
/* 0EFF94 7F0BB464 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EFF98 7F0BB468 E4A60008 */  swc1  $f6, 8($a1)
/* 0EFF9C 7F0BB46C C48A0018 */  lwc1  $f10, 0x18($a0)
/* 0EFFA0 7F0BB470 C4640010 */  lwc1  $f4, 0x10($v1)
/* 0EFFA4 7F0BB474 C4720014 */  lwc1  $f18, 0x14($v1)
/* 0EFFA8 7F0BB478 460A2203 */  div.s $f8, $f4, $f10
/* 0EFFAC 7F0BB47C 46124400 */  add.s $f16, $f8, $f18
/* 0EFFB0 7F0BB480 E4B0000C */  swc1  $f16, 0xc($a1)
/* 0EFFB4 7F0BB484 C4A0000C */  lwc1  $f0, 0xc($a1)
/* 0EFFB8 7F0BB488 4602003C */  c.lt.s $f0, $f2
/* 0EFFBC 7F0BB48C 00000000 */  nop   
/* 0EFFC0 7F0BB490 45020004 */  bc1fl .L7F0BB4A4
/* 0EFFC4 7F0BB494 44813000 */   mtc1  $at, $f6
/* 0EFFC8 7F0BB498 03E00008 */  jr    $ra
/* 0EFFCC 7F0BB49C 24020002 */   li    $v0, 2

/* 0EFFD0 7F0BB4A0 44813000 */  mtc1  $at, $f6
.L7F0BB4A4:
/* 0EFFD4 7F0BB4A4 24020001 */  li    $v0, 1
/* 0EFFD8 7F0BB4A8 4600303C */  c.lt.s $f6, $f0
/* 0EFFDC 7F0BB4AC 00000000 */  nop   
/* 0EFFE0 7F0BB4B0 45000003 */  bc1f  .L7F0BB4C0
/* 0EFFE4 7F0BB4B4 00000000 */   nop   
/* 0EFFE8 7F0BB4B8 03E00008 */  jr    $ra
/* 0EFFEC 7F0BB4BC 00001025 */   move  $v0, $zero

.L7F0BB4C0:
/* 0EFFF0 7F0BB4C0 03E00008 */  jr    $ra
/* 0EFFF4 7F0BB4C4 00000000 */   nop   
)
#endif



