#ifndef _CHR_H_
#define _CHR_H_
#include "ultra64.h"
#include "bondgame.h"
#include "chrai.h"
#include "bondtypes.h"

#define EXPLOSION_ANIMATION_TABLE_LEN 8

struct struck_animation_table;

struct animation_something
{
    s32 id;
    s32 field_4;
    s32 field_8;
    f32 field_C;
    s32 field_10;
    s32 field_14;
    f32 field_18;
    
    struct struck_animation_table *field_1C;

    // maybe count of field_1C
    s32 field_20;

    struct struck_animation_table *field_24;

    // maybe count of field_24
    s32 field_28;
};

struct struck_animation_table
{
    void *anonymous_0; // This might be pointer to struct of ANIM_DATA_x
    s32 anonymous_1;
    f32 anonymous_2;
    f32 anonymous_3;
    s32 anonymous_4;
    f32 sfx1_timer_60;
    f32 sfx2_timer_60;
};

struct explosion_death_animation
{
    s32 anonymous_0;
    s32 anonymous_1;
    f32 anonymous_2;
    f32 anonymous_3;
    f32 anonymous_4;
    f32 anonymous_5;
    f32 anonymous_6;
};

struct explosion_anim_group_info
{
    s8 *table;
    s32 count;
};

struct weapon_firing_animation_table
{
    s32 anonymous_0;
    f32 anonymous_1;
    f32 anonymous_2;
    f32 anonymous_3;

    /**
     * Offset 0x10.
    */
    f32 anonymous_4;
    f32 anonymous_5;
    f32 anonymous_6;
    f32 anonymous_7;

    /**
     * Offset 0x20.
    */
    f32 anonymous_8;
    f32 anonymous_9;
    f32 anonymous_10;
    f32 anonymous_11;

    /**
     * Offset 0x30.
    */
    f32 anonymous_12;
    f32 anonymous_13;

    /**
     * Some kind of minimum. See chrlvUpdateAimendsideback.
     * Offset 0x38.
    */
    f32 anonymous_14;

    /**
     * Some kind of maximum. See chrlvUpdateAimendsideback.
     * Offset 0x3c.
    */
    f32 anonymous_15;

    /**
     * Offset 0x40.
    */
    f32 anonymous_16;
    f32 anonymous_17;
};

struct anim_group_info
{
    struct weapon_firing_animation_table (*table)[];
    s32 len;
};

extern s32 objectiveregisters1;
extern struct ChrRecord* g_ActiveChrs;
extern s32 g_ActiveChrsCount;

extern f32 g_AiAccuracyModifier;
extern f32 g_AiDamageModifier;
extern f32 g_AiHealthModifier;
extern f32 g_AiReactionSpeed;
extern s32 g_SeenBondRecentlyGuardCount;

extern struct animation_something D_8002C914[];

extern struct struck_animation_table D_8002CE54[];
extern struct struck_animation_table D_8002DF10[];
extern struct struck_animation_table D_8002CEE0[];
extern struct struck_animation_table D_8002DF64[];
extern struct struck_animation_table D_8002CF6C[];
extern struct struck_animation_table D_8002DFB8[];
extern struct struck_animation_table D_8002D014[];
extern struct struck_animation_table D_8002E028[];
extern struct struck_animation_table D_8002D0A0[];
extern struct struck_animation_table D_8002E07C[];
extern struct struck_animation_table D_8002D12C[];
extern struct struck_animation_table D_8002E0D0[];
extern struct struck_animation_table D_8002D1D4[];
extern struct struck_animation_table D_8002E140[];
extern struct struck_animation_table D_8002D3B0[];
extern struct struck_animation_table D_8002E23C[];
extern struct struck_animation_table D_8002D6DC[];
extern struct struck_animation_table D_8002E300[];
extern struct struck_animation_table D_8002D768[];
extern struct struck_animation_table D_8002E354[];
extern struct struck_animation_table D_8002D7F4[];
extern struct struck_animation_table D_8002E3A8[];
extern struct struck_animation_table D_8002D880[];
extern struct struck_animation_table D_8002E418[];
extern struct struck_animation_table D_8002D90C[];
extern struct struck_animation_table D_8002E46C[];
extern struct struck_animation_table D_8002D998[];
extern struct struck_animation_table D_8002E4C0[];
extern struct struck_animation_table D_8002DA24[];
extern struct struck_animation_table D_8002E530[];
extern struct struck_animation_table D_8002DCE0[];
extern struct struck_animation_table D_8002E5BC[];

extern struct struck_animation_table D_8002DEBC[];
extern struct animation_something D_8002CAA0;
extern struct animation_something D_8002CACC;
extern struct animation_something D_8002CB24;
extern struct animation_something D_8002CB50;

extern struct weapon_firing_animation_table rifle_firing_animation_group1[];
extern struct weapon_firing_animation_table rifle_firing_animation_group2[];
extern struct weapon_firing_animation_table rifle_firing_animation_group5[];
extern struct weapon_firing_animation_table rifle_firing_animation_group3[];
extern struct weapon_firing_animation_table rifle_firing_animation_group4[];
extern struct weapon_firing_animation_table pistol_firing_animation_group1[];
extern struct weapon_firing_animation_table pistol_firing_animation_group2[];
extern struct weapon_firing_animation_table pistol_firing_animation_group3[];
extern struct weapon_firing_animation_table pistol_firing_animation_group6[];
extern struct weapon_firing_animation_table pistol_firing_animation_group4[];
extern struct weapon_firing_animation_table pistol_firing_animation_group5[];
extern struct weapon_firing_animation_table doubles_firing_animation_group1[];
extern struct weapon_firing_animation_table doubles_firing_animation_group2[];
extern struct weapon_firing_animation_table doubles_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_groupA[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group3[];


extern struct weapon_firing_animation_table D_80030078[];
extern struct weapon_firing_animation_table D_80030660[];

extern struct anim_group_info *ptr_rifle_firing_animation_groups[];
extern struct anim_group_info *ptr_pistol_firing_animation_groups[];
extern struct anim_group_info *ptr_doubles_firing_animation_groups[];
extern struct anim_group_info *ptr_crouched_rifle_firing_animation_groups[];
extern struct anim_group_info *ptr_crouched_pistol_firing_animation_groups[];
extern struct anim_group_info *ptr_crouched_doubles_firing_animation_groups[];

extern f32 animation_rate;
extern s32 D_8002C904;
extern s32 g_AnimationTablePointerCountRelated;
extern s32 D_8002C90C;
extern s32 D_8002C910;

extern s32 D_8002CC58;
extern s32 show_patrols_flag;
extern s32 player1_guardID;
extern struct ChrRecord *ptr_guard_data;
extern s32 num_guards;
extern s32 D_8002CC6C[];
extern s32 D_8002CCA8;
extern s32 D_8002CCAC;
extern s32 D_8002CCB0;
extern s32 D_8002CCB4;
extern u8 D_8002CCB8[4];

extern f32 D_80030984;
extern f32 D_80030988;
extern f32 D_8003098C;
extern f32 D_80030990;
extern f32 D_80030994;
extern f32 D_80030998;
extern f32 D_8003099C;
extern f32 D_800309A0;
extern f32 D_800309A4;

extern struct point2d D_800309A8;
extern struct point2d D_800309B0;
extern struct point2d D_800309B8;
extern struct point2d D_800309C0;
extern struct point2d D_800309C8;
extern struct point2d D_800309D0;
extern struct point2d D_800309D8;
extern struct point2d D_800309E0;
extern struct point2d D_800309E8;
extern struct point2d D_800309F0;


extern u32 num_bodies;
extern u32 num_male_heads;
extern u32 num_female_heads;
extern s32 list_of_bodies[];
extern s32 random_male_heads[];
extern s32 random_female_heads[];
extern u32 current_random_body;
extern u32 current_random_male_head;
extern u32 current_random_female_head;

extern s32 female_guard_yelp_counter;
extern s16 female_guard_yelps[];
extern s32 male_guard_yelp_counter;
extern s16 male_guard_yelps[];

extern struct coord3d D_80030A44;
extern s16 metal_ricochet_SFX[3];

extern struct explosion_anim_group_info explosion_animation_table[];
extern struct explosion_death_animation D_8002E648[];

void sub_GAME_7F022EE0(s32 param_1);
void sub_GAME_7F022E24(s32 param_1);
void disable_sounds_attached_to_player_then_something(struct PropRecord* prop);
void chrPositionRelated7F020D94(struct ChrRecord *);
void set_or_unset_GUARDdata_flag(struct ChrRecord *guard,s32 param_2);
f32 get_animation_rate(void);
void animation_speed_related(f32);
struct PropRecord * init_GUARDdata_with_set_values(struct PropRecord *, struct Model *, struct coord3d *, f32 arg2, struct StandTile * arg3, s32 arg4);
struct PropRecord * replace_GUARDdata_with_actual_values(struct Model * arg0, struct coord3d * arg1, f32 arg2, struct StandTile * arg3, s32 arg4);
void chrSetHiddenToRandom(struct ChrRecord *arg0);
void  chrRemoved7F022E1C(f32 arg0);
void chrDecrementAnimationTablePointerCount(void);
void chrIncrementAnimationTablePointerCount(void);
void chrToggleD_8002C90C(void);
void chrCheckGuardsHeardSound(f32 arg0);
struct ChrRecord* chrGetGuardData(s32 index);
struct PropRecord *something_with_weaponpos_of_guarddata_hand(struct ChrRecord *arg0, HANDEDNESS arg1);
struct PropRecord *is_weapon_in_guarddata_hand(struct ChrRecord *ChrRecord, HANDEDNESS arg1);
void chrUpdateCollisionBounds(struct PropRecord *arg0, struct rect4f **arg1, s32 *arg2, f32 *y_out, f32 *ground);
void chrGetChrWidthHeight(struct PropRecord *arg0, f32 *width, f32 *height, f32 *always_20);
f32 chrGetChrGround(struct PropRecord *arg0);
void sub_GAME_7F021B20(struct ChrRecord *arg0);
s32 get_numguards(void);
Gfx *chrRenderProp(PropRecord *arg0, Gfx *arg1, s32 arg2);

//tentative signature
s32 sub_GAME_7F01FC10(Model *, struct coord3d *, struct coord3d *, f32 *);

#ifndef VERSION_US
s32 not_in_us_7F0209EC(s32 bodynum, s32 headnum);
#endif

#endif
