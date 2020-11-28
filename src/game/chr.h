#ifndef _CHR_H_
#define _CHR_H_
#include "ultra64.h"
#include "bondgame.h"
#include "chrai.h"
#include "structs.h"

enum EGuardAction { // u8
  ChasingBond=15,
  Ducking=2,
  Dying=4,
  Fading=5,
  FleeingBriefly=13,
  Idle=3,
  Injured=6,
  LookingAround=18,
  NoneMaybe=0,
  RollOrRunShooting=10,
  Shooting=8,
  Sidehopping=12,
  Sidestepping=11,
  Standing=1,
  Surrendering=16,
  ThrowingGrenade=20,
  TriggeringAlarm=19,
  UNKNOWN=7,
  UNKNOWN2=17,
  WalkShooting=9,
  WalkingPath=14
};

typedef enum EGuardChaseStage { // u8
  after_6_retries=2,
  chooseNewTarget=0,
  routeIsGood=4,
  routeWasGoodPlotAdjustment=5,
  tryPlotRouteAroundClearToFinalDest=1,
  tryPlotRouteAroundNotClearToFinalDest=3
} EGuardChaseStage;

struct guardChaseData {
  enum EGuardChaseStage motionStage;
  s8 failCount;
  u8 normal_target_set; // bool
  u8 crit_target_set; // bool
  struct float3 targetPosition;
  struct float3 tilePntA;
  struct float3 tilePntB;
  s32 chaseTimer;
  struct float3 critical_local_target;

  // ! Should be larger iirc - eat more values from GuardData if needs be
};

struct GuardData {
  u16 id;
  u8 UNKNOWN_0x2;
  u8 UNKNOWN_0x3;
  u8 UNKNOWN_0x4;
  u8 UNKNOWN_0x5;
  u8 UNKNOWN_0x6;
  u8 current_action;  // enum EGuardAction
  u8 delayUntilUpdate;
  u8 UNKNOWN_0x9;
  u8 UNKNOWN_0xa;
  u8 UNKNOWN_0xb;
  u8 UNKNOWN_0xc;
  u8 UNKNOWN_0xd;
  u8 UNKNOWN_0xe;
  u8 UNKNOWN_0xf;
  u8 UNKNOWN_0x10;
  u8 UNKNOWN_0x11;
  u16 flags2;
  u8 UNKNOWN_0x14;
  u8 UNKNOWN_0x15;
  u8 UNKNOWN_0x16;
  u8 UNKNOWN_0x17;
  struct PositionData * position_data;
  void* modelDataPtr;
  u8 UNKNOWN_0x20;
  u8 UNKNOWN_0x21;
  u8 UNKNOWN_0x22;
  u8 UNKNOWN_0x23;
  float collision_radius;
  float collision_height; // union with fadeout timer
  struct float3 bond_position;
  struct StandTile * target_tile;
  struct Pad * ultimate_target_pad;
  void * pathStack[6];
  u8 UNKNOWN_0x58;
  u8 turningStageOrSetting;
  short UNKNOWN_0x5a;
  struct guardChaseData guard_chase_data;
  u8 UNKNOWN_0x94;
  u8 UNKNOWN_0x95;
  u8 UNKNOWN_0x96;
  u8 UNKNOWN_0x97;
  u8 UNKNOWN_0x98;
  u8 UNKNOWN_0x99;
  u8 UNKNOWN_0x9a;
  u8 UNKNOWN_0x9b;
  int anotherTimer;
  float turningSpeed;
  u8 UNKNOWN_0xa4;
  u8 UNKNOWN_0xa5;
  u8 UNKNOWN_0xa6;
  u8 UNKNOWN_0xa7;
  u8 UNKNOWN_0xa8;
  u8 UNKNOWN_0xa9;
  u8 UNKNOWN_0xaa;
  u8 UNKNOWN_0xab;
  float min_collision_y;
  u8 UNKNOWN_0xb0;
  u8 UNKNOWN_0xb1;
  u8 UNKNOWN_0xb2;
  u8 UNKNOWN_0xb3;
  u8 UNKNOWN_0xb4;
  u8 UNKNOWN_0xb5;
  u8 UNKNOWN_0xb6;
  u8 UNKNOWN_0xb7;
  u8 UNKNOWN_0xb8;
  u8 UNKNOWN_0xb9;
  u8 UNKNOWN_0xba;
  u8 UNKNOWN_0xbb;
  u8 UNKNOWN_0xbc;
  u8 UNKNOWN_0xbd;
  u8 UNKNOWN_0xbe;
  u8 UNKNOWN_0xbf;
  u8 UNKNOWN_0xc0;
  u8 UNKNOWN_0xc1;
  u8 UNKNOWN_0xc2;
  u8 UNKNOWN_0xc3;
  u8 UNKNOWN_0xc4;
  u8 UNKNOWN_0xc5;
  u8 UNKNOWN_0xc6;
  u8 UNKNOWN_0xc7;
  u32 passedFrames;
  u8 UNKNOWN_0xcc;
  u8 UNKNOWN_0xcd;
  u8 UNKNOWN_0xce;
  u8 UNKNOWN_0xcf;
  u8 UNKNOWN_0xd0;
  u8 UNKNOWN_0xd1;
  u8 UNKNOWN_0xd2;
  u8 UNKNOWN_0xd3;
  u8 UNKNOWN_0xd4;
  u8 UNKNOWN_0xd5;
  u8 UNKNOWN_0xd6;
  u8 UNKNOWN_0xd7;
  u8 UNKNOWN_0xd8;
  u8 UNKNOWN_0xd9;
  u8 UNKNOWN_0xda;
  u8 UNKNOWN_0xdb;
  u8 UNKNOWN_0xdc;
  u8 UNKNOWN_0xdd;
  u8 UNKNOWN_0xde;
  u8 UNKNOWN_0xdf;
  u8 UNKNOWN_0xe0;
  u8 UNKNOWN_0xe1;
  u8 UNKNOWN_0xe2;
  u8 UNKNOWN_0xe3;
  u8 UNKNOWN_0xe4;
  u8 UNKNOWN_0xe5;
  u8 UNKNOWN_0xe6;
  u8 UNKNOWN_0xe7;
  u8 UNKNOWN_0xe8; //lastSeenBondTime, u32?
  u8 UNKNOWN_0xe9;
  u8 UNKNOWN_0xea;
  u8 UNKNOWN_0xeb;
  u8 UNKNOWN_0xec;
  u8 UNKNOWN_0xed;
  u8 UNKNOWN_0xee;
  u8 UNKNOWN_0xef;
  u8 UNKNOWN_0xf0;
  u8 UNKNOWN_0xf1;
  u8 UNKNOWN_0xf2;
  u8 UNKNOWN_0xf3;
  u8 UNKNOWN_0xf4;
  u8 UNKNOWN_0xf5;
  u8 UNKNOWN_0xf6;
  u8 UNKNOWN_0xf7;
  u8 UNKNOWN_0xf8;
  u8 UNKNOWN_0xf9;
  u8 UNKNOWN_0xfa;
  u8 UNKNOWN_0xfb;
  u8 UNKNOWN_0xfc;
  u8 UNKNOWN_0xfd;
  u8 UNKNOWN_0xfe;
  u8 UNKNOWN_0xff;
  u8 UNKNOWN_0x100;
  u8 UNKNOWN_0x101;
  u8 UNKNOWN_0x102;
  u8 UNKNOWN_0x103;
  u8 UNKNOWN_0x104;
  u8 UNKNOWN_0x105;
  u8 UNKNOWN_0x106;
  u8 UNKNOWN_0x107;
  u8 UNKNOWN_0x108;
  u8 UNKNOWN_0x109;
  u8 UNKNOWN_0x10a;
  u8 UNKNOWN_0x10b;
  u8 UNKNOWN_0x10c;
  u8 UNKNOWN_0x10d;
  u8 UNKNOWN_0x10e;
  u8 UNKNOWN_0x10f;
  int timer;
  u8 UNKNOWN_0x114;
  u8 UNKNOWN_0x115;
  u8 UNKNOWN_0x116;
  u8 UNKNOWN_0x117;
  u8 UNKNOWN_0x118;
  u8 UNKNOWN_0x119;
  u8 UNKNOWN_0x11a;
  u8 UNKNOWN_0x11b;
  struct float2 collision_points[4];
  u8 UNKNOWN_0x13c;
  u8 UNKNOWN_0x13d;
  u8 UNKNOWN_0x13e;
  u8 UNKNOWN_0x13f;
  u8 UNKNOWN_0x140;
  u8 UNKNOWN_0x141;
  u8 UNKNOWN_0x142;
  u8 UNKNOWN_0x143;
  u8 UNKNOWN_0x144;
  u8 UNKNOWN_0x145;
  u8 UNKNOWN_0x146;
  u8 UNKNOWN_0x147;
  u8 UNKNOWN_0x148;
  u8 UNKNOWN_0x149;
  u8 UNKNOWN_0x14a;
  u8 UNKNOWN_0x14b;
  u8 UNKNOWN_0x14c;
  u8 UNKNOWN_0x14d;
  u8 UNKNOWN_0x14e;
  u8 UNKNOWN_0x14f;
  float UNKNOWN_0x150;
  float UNKNOWN_0x154;
  float UNKNOWN_0x158;
  float UNKNOWN_0x15c;
  u8 UNKNOWN_0x160;
  u8 UNKNOWN_0x161;
  u8 UNKNOWN_0x162;
  u8 UNKNOWN_0x163;
  u8 UNKNOWN_0x164;
  u8 UNKNOWN_0x165;
  u8 UNKNOWN_0x166;
  u8 UNKNOWN_0x167;
  u8 UNKNOWN_0x168;
  u8 UNKNOWN_0x169;
  u8 UNKNOWN_0x16a;
  u8 UNKNOWN_0x16b;
  u8 UNKNOWN_0x16c;
  u8 UNKNOWN_0x16d;
  u8 UNKNOWN_0x16e;
  u8 UNKNOWN_0x16f;
  u8 UNKNOWN_0x170;
  u8 UNKNOWN_0x171;
  u8 UNKNOWN_0x172;
  u8 UNKNOWN_0x173;
  u8 UNKNOWN_0x174;
  u8 UNKNOWN_0x175;
  u8 UNKNOWN_0x176;
  u8 UNKNOWN_0x177;
  u8 UNKNOWN_0x178;
  u8 UNKNOWN_0x179;
  u8 UNKNOWN_0x17a;
  u8 UNKNOWN_0x17b;
  u8 UNKNOWN_0x17c;
  u8 UNKNOWN_0x17d;
  u8 UNKNOWN_0x17e;
  u8 UNKNOWN_0x17f;
  u8 UNKNOWN_0x180;
  u8 UNKNOWN_0x181;
  u8 UNKNOWN_0x182;
  u8 UNKNOWN_0x183;
  u8 UNKNOWN_0x184;
  u8 UNKNOWN_0x185;
  u8 UNKNOWN_0x186;
  u8 UNKNOWN_0x187;
  u8 UNKNOWN_0x188;
  u8 UNKNOWN_0x189;
  u8 UNKNOWN_0x18a;
  u8 UNKNOWN_0x18b;
  u8 UNKNOWN_0x18c;
  u8 UNKNOWN_0x18d;
  u8 UNKNOWN_0x18e;
  u8 UNKNOWN_0x18f;
  u8 UNKNOWN_0x190;
  u8 UNKNOWN_0x191;
  u8 UNKNOWN_0x192;
  u8 UNKNOWN_0x193;
  u8 UNKNOWN_0x194;
  u8 UNKNOWN_0x195;
  u8 UNKNOWN_0x196;
  u8 UNKNOWN_0x197;
  u8 UNKNOWN_0x198;
  u8 UNKNOWN_0x199;
  u8 UNKNOWN_0x19a;
  u8 UNKNOWN_0x19b;
  u8 UNKNOWN_0x19c;
  u8 UNKNOWN_0x19d;
  u8 UNKNOWN_0x19e;
  u8 UNKNOWN_0x19f;
  u8 UNKNOWN_0x1a0;
  u8 UNKNOWN_0x1a1;
  u8 UNKNOWN_0x1a2;
  u8 UNKNOWN_0x1a3;
  u8 UNKNOWN_0x1a4;
  u8 UNKNOWN_0x1a5;
  u8 UNKNOWN_0x1a6;
  u8 UNKNOWN_0x1a7;
  u8 UNKNOWN_0x1a8;
  u8 UNKNOWN_0x1a9;
  u8 UNKNOWN_0x1aa;
  u8 UNKNOWN_0x1ab;
  u8 UNKNOWN_0x1ac;
  u8 UNKNOWN_0x1ad;
  u8 UNKNOWN_0x1ae;
  u8 UNKNOWN_0x1af;
  u8 UNKNOWN_0x1b0;
  u8 UNKNOWN_0x1b1;
  u8 UNKNOWN_0x1b2;
  u8 UNKNOWN_0x1b3;
  u8 UNKNOWN_0x1b4;
  u8 UNKNOWN_0x1b5;
  u8 UNKNOWN_0x1b6;
  u8 UNKNOWN_0x1b7;
  u8 UNKNOWN_0x1b8;
  u8 UNKNOWN_0x1b9;
  u8 UNKNOWN_0x1ba;
  u8 UNKNOWN_0x1bb;
  u8 UNKNOWN_0x1bc;
  u8 UNKNOWN_0x1bd;
  u8 UNKNOWN_0x1be;
  u8 UNKNOWN_0x1bf;
  u8 UNKNOWN_0x1c0;
  u8 UNKNOWN_0x1c1;
  u8 UNKNOWN_0x1c2;
  u8 UNKNOWN_0x1c3;
  u8 UNKNOWN_0x1c4;
  u8 UNKNOWN_0x1c5;
  u8 UNKNOWN_0x1c6;
  u8 UNKNOWN_0x1c7;
  u8 UNKNOWN_0x1c8;
  u8 UNKNOWN_0x1c9;
  u8 UNKNOWN_0x1ca;
  u8 UNKNOWN_0x1cb;
  u8 UNKNOWN_0x1cc;
  u8 UNKNOWN_0x1cd;
  u8 UNKNOWN_0x1ce;
  u8 UNKNOWN_0x1cf;
  u8 UNKNOWN_0x1d0;
  u8 UNKNOWN_0x1d1;
  u8 UNKNOWN_0x1d2;
  u8 UNKNOWN_0x1d3;
  u8 UNKNOWN_0x1d4;
  u8 UNKNOWN_0x1d5;
  u8 UNKNOWN_0x1d6;
  u8 UNKNOWN_0x1d7;
  u8 UNKNOWN_0x1d8;
  u8 UNKNOWN_0x1d9;
  u8 UNKNOWN_0x1da;
  u8 UNKNOWN_0x1db;
};

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
