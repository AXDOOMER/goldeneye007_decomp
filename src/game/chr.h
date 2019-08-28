#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "ultra64.h"
#include "bondgame.h"

struct animation_something
{
  s32 anonymous_0;
  s32 field_4;
  s32 field_8;
  f32 field_C;
  s32 field_10;
  s32 field_14;
  f32 field_18;
  struct struck_animation_table *field_1C;
  s32 field_20;
  struct struck_animation_table *field_24;
  s32 field_28;
};

struct struck_animation_table
{
  void *anonymous_0;
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

struct explosion_animation
{
  void *explosion_death_animation;
  s32 count;
};

struct weapon_firing_animation_table
{
  s32 anonymous_0;
  f32 anonymous_1;
  f32 anonymous_2;
  f32 anonymous_3;
  f32 anonymous_4;
  f32 anonymous_5;
  f32 anonymous_6;
  f32 anonymous_7;
  f32 anonymous_8;
  f32 anonymous_9;
  f32 anonymous_10;
  f32 anonymous_11;
  f32 anonymous_12;
  f32 anonymous_13;
  f32 anonymous_14;
  f32 anonymous_15;
  f32 anonymous_16;
  f32 anonymous_17;
};

typedef enum ACT_TYPE {
    ACT_INIT = 0,
    ACT_STAND,
    ACT_KNEEL,
    ACT_ANIM,
    ACT_DIE,
    ACT_DEAD,
    ACT_ARGH,
    ACT_PREARGH,
    ACT_ATTACK,
    ACT_ATTACKWALK,
    ACT_ATTACKROLL,
    ACT_SIDESTEP,
    ACT_JUMPOUT,
    ACT_RUNPOS,
    ACT_PATROL,
    ACT_GOPOS,
    ACT_SURRENDER,
    ACT_LOOKATTARGET,
    ACT_SURPRISED,
    ACT_STARTALARM,
    ACT_THROWGRENADE,
    ACT_TURNDIR,
    ACT_TEST,
    ACT_NULL
} ACT_TYPE;

typedef struct CHRdata CHRdata, *PCHRdata;

/* unfinished struct, WIP */
struct CHRdata {
    u16 chrnum;
    s8 accuracyrating;
    s8 speedrating;
    u8 firecountleft;
    u8 firecountright;
    s8 headnum;
    ACT_TYPE actiontype;
    s8 sleep;
    s8 invalidmove;
    s8 numclosearghs;
    s8 numarghs;
    u8 fadealpha;
    s8 arghrating;
    s8 aimendcount;
    s8 bodynum;
    /* 0x0010 */
    u8 grenadeprob;
    s8 flinchcnt;
    s16 hidden;
    s32 chrflags;
    void * pad;
    void * model;
    /* 0x0020 */
    void * field_20;
    f32 chrwidth;
    f32 chrheight;
    void * bondpos; /* HACK - reused as fadeout counter on death, checks if pointer at 7F02B774 */
    /* 0x0030 */
    int field_30;
    short field_34;
    char field_36;
    char field_37;
    char field_38;
    char field_39;
    char field_3A;
    char field_3B;
    int path_target_position;
    /* 0x0040 */
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    /* 0x0050 */
    int field_50;
    int field_54;
    char type_of_motion;
    char distance_counter_or_something;
    short distance_to_target;
    int field_5C;
    /* 0x0060 */
    int target_position;
    int field_64;
    int field_68;
    int field_6C;
    /* 0x0070 */
    int path_segment_coverage;
    int path_segment_length;
    int field_78;
    int field_7C;
    /* 0x0080 */
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    /* 0x0090 */
    int field_90;
    int segment_coverage;
    int segment_length;
    int field_9C;
    /* 0x00A0 */
    int field_A0;
    f32 sumground;
    f32 manground;
    f32 ground;
    /* 0x00B0 */
    f32 fallspeed[3];
    f32 prevpos[3];
    /* 0x00B8 */
    s32 lastwalk60;
    s32 lastmoveok60;
    /* 0x00D0 */
    f32 visionrange;
    s32 lastseetarget60;
    f32 lastvisibletarg[3];
    /* 0x00E4 */
    void * field_E4;
    s32 timeshooter;
    f32 hearingscale;
    /* 0x00F0 */
    s32 lastheartarget60;
    u8 shadecol[4];
    u8 nextcol[4];
    f32 damage;
    /* 0x0100 */
    f32 maxdamage;
    void * ailist;
    u16 aioffset;
    u16 aireturnlist;
    u8 flags;
    u8 flags2;
    u8 BITFIELD;
    u8 random;
    /* 0x0110 */
    s32 timer60;
    u16 padpreset1;
    u16 chrpreset1; /* ID FC */
    u16 chrseeshot; /* ID FA */
    u16 chrseedie; /* ID FB */
    /* 0x011C */
    f32 field_11C[2];
    f32 field_124[2];
    f32 field_12C[2];
    /* 0x0130 */
    int field_134;
    int field_138;
    f32 shotbondsum;
    /* 0x0140 */
    f32 aimuplshoulder;
    f32 aimuprshoulder;
    f32 aimupback;
    f32 aimsideback;
    /* 0x0150 */
    f32 aimendlshoulder;
    f32 aimendrshoulder;
    f32 aimendback;
    f32 aimendsideback;
    /* 0x0160 */
    int * handle_positiondata_right_gun;
    int * handle_positiondata_left_gun;
    int * ptr_SEbuffer1;
    int * ptr_SEbuffer2;
    /* 0x0170 */
    int * ptr_SEbuffer3;
    int * ptr_SEbuffer4;
    int field_178;
    int field_17C;
    /* 0x0180 */
    char field_180;
    char field_181;
    char field_182;
    char field_183;
    int field_184;
    int field_188;
    int field_18C;
    /* 0x0190 */
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    /* 0x01A0 */
    int field_1A0;
    int field_1A4;
    int field_1A8;
    char field_1AC;
    char field_1AD;
    char field_1AE;
    char field_1AF;
    /* 0x01B0 */
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    /* 0x01C0 */
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    /* 0x01D0 */
    int field_1D0;
    int field_1D4;
    int * handle_positiondata_hat;
};


extern struct animation_something D_8002C914;


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


extern struct weapon_firing_animation_table D_80030078;
extern struct weapon_firing_animation_table D_800300C0;
extern struct weapon_firing_animation_table D_80030108;
extern struct weapon_firing_animation_table D_80030150;
extern struct weapon_firing_animation_table D_80030198;
extern struct weapon_firing_animation_table D_800301E0;
extern struct weapon_firing_animation_table D_80030228;
extern struct weapon_firing_animation_table D_80030270;
extern struct weapon_firing_animation_table D_800302B8;
extern struct weapon_firing_animation_table D_80030300;
extern struct weapon_firing_animation_table D_80030348;
extern struct weapon_firing_animation_table D_80030390;
extern struct weapon_firing_animation_table D_800303D8;
extern struct weapon_firing_animation_table D_80030420;
extern struct weapon_firing_animation_table D_80030468;
extern struct weapon_firing_animation_table D_800304B0;
extern struct weapon_firing_animation_table D_800304F8;
extern struct weapon_firing_animation_table D_80030540;
extern struct weapon_firing_animation_table D_80030588;
extern struct weapon_firing_animation_table D_800305D0;
extern struct weapon_firing_animation_table D_80030618;
extern struct weapon_firing_animation_table D_80030660;
extern struct weapon_firing_animation_table D_800306A8;
extern struct weapon_firing_animation_table D_800306F0;
extern struct weapon_firing_animation_table D_80030738;
extern struct weapon_firing_animation_table D_80030780;
extern struct weapon_firing_animation_table D_800307C8;
extern struct weapon_firing_animation_table D_80030810;
extern struct weapon_firing_animation_table D_80030858;
extern struct weapon_firing_animation_table D_800308A0;
extern struct weapon_firing_animation_table D_800308E8;
extern struct weapon_firing_animation_table D_80030930;

extern f32 animation_rate;
extern s32 D_8002C904;
extern s32 D_8002C908;
extern s32 D_8002C90C;
extern s32 D_8002C910;

extern s32 D_8002CC58;
extern s32 show_patrols_flag;
extern s32 player1_guardID;
extern s32 ptr_guard_data;
extern s32 num_guards;
extern s32 D_8002CC6C[];
extern s32 D_8002CCA8;
extern s32 D_8002CCAC;
extern s32 D_8002CCB0;
extern s32 D_8002CCB4;
extern u8 D_8002CCB8;
extern s32 num_bodies;
extern s32 num_male_heads;
extern s32 num_female_heads;
extern s32 list_of_bodies[];
extern s32 random_male_heads[];
extern s32 random_female_heads[];
#endif
