#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "ultra64.h"

#define BODY_Jungle_Commando 0x0
#define BODY_St_Petersburg_Guard 0x1
#define BODY_Russian_Soldier 0x2
#define BODY_Russian_Infantry 0x3
#define BODY_Janus_Special_Forces 0x4
#define BODY_Tuxedo 0x5
#define BODY_Boris 0x6
#define BODY_Ourumov 0x7
#define BODY_Trevelyan_Janus 0x8
#define BODY_Trevelyan_006 0x9
#define BODY_Valentin_ 0xA
#define BODY_Xenia 0xB
#define BODY_Baron_Samedi 0xC
#define BODY_Jaws 0xD
#define BODY_Mayday 0xE
#define BODY_Oddjob 0xF
#define BODY_Natalya_Skirt 0x10
#define BODY_Janus_Marine 0x11
#define BODY_Russian_Commandant 0x12
#define BODY_Siberian_Guard_1_Mishkin 0x13
#define BODY_Naval_Officer 0x14
#define BODY_Siberian_Special_Forces 0x15
#define BODY_Special_Operations_Uniform 0x16
#define BODY_Formal_Wear 0x17
#define BODY_Jungle_Fatigues 0x18
#define BODY_Parka 0x19
#define BODY_Unused_Female 0x1A
#define BODY_Rosika 0x1B
#define BODY_Scientist_2_Female 0x1C
#define BODY_Civilian_1_Female 0x1D
#define BODY_Unused_Male_1 0x1E
#define BODY_Unused_Male_2 0x1F
#define BODY_Civilian_4 0x20
#define BODY_Civilian_2 0x21
#define BODY_Civilian_3 0x22
#define BODY_Scientist_1_Male 0x23
#define BODY_Helicopter_Pilot 0x24
#define BODY_Siberian_Guard_2 0x25
#define BODY_Arctic_Commando 0x26
#define BODY_Moonraker_Elite_1_Male 0x27
#define BODY_Moonraker_Elite_2_Female 0x28
#define BODY_Left_Suit_Hand_Floating_Arm 0x29
#define BODY_Male_Karl 0x2A
#define BODY_Male_Alan 0x2B
#define BODY_Male_Pete 0x2C
#define BODY_Male_Martin 0x2D
#define BODY_Male_Mark 0x2E
#define BODY_Male_Duncan 0x2F
#define BODY_Male_Shaun 0x30
#define BODY_Male_Dwayne 0x31
#define BODY_Male_B 0x32
#define BODY_Male_Dave_Dr_Doak 0x33
#define BODY_Male_Grant 0x34
#define BODY_Male_Des 0x35
#define BODY_Male_Chris 0x36
#define BODY_Male_Lee 0x37
#define BODY_Male_Neil 0x38
#define BODY_Male_Jim 0x39
#define BODY_Male_Robin 0x3A
#define BODY_Male_Steve_H 0x3B
#define BODY_Male_Terrorist 0x3C
#define BODY_Male_Biker 0x3D
#define BODY_Male_Graeme 0x3E
#define BODY_Male_Steve_Ellis 0x3F
#define BODY_Male_Joel 0x40
#define BODY_Male_Scott 0x41
#define BODY_Male_Joe_Altered 0x42
#define BODY_Male_Ken 0x43
#define BODY_Male_Joe 0x44
#define BODY_Male_Mishkin 0x45
#define BODY_Female_Sally 0x46
#define BODY_Female_Marion_Rosika 0x47
#define BODY_Female_Mandy 0x48
#define BODY_Female_Vivien 0x49
#define BODY_Male_Pierce_Bond_1 0x4A
#define BODY_Male_Pierce_Bond_2 0x4B
#define BODY_Male_Pierce_Bond_3 0x4C
#define BODY_Male_Pierce_Bond_Parka 0x4D
#define BODY_Male_Pierce_Bond_Tuxedo 0x4E
#define BODY_Natalya_Jungle_Fatigues 0x4F

#define HEAD_Male_Karl 0x2A
#define HEAD_Male_Alan 0x2B
#define HEAD_Male_Pete 0x2C
#define HEAD_Male_Martin 0x2D
#define HEAD_Male_Mark 0x2E
#define HEAD_Male_Duncan 0x2F
#define HEAD_Male_Shaun 0x30
#define HEAD_Male_Dwayne 0x31
#define HEAD_Male_B 0x32
#define HEAD_Male_Dave_Dr_Doak 0x33
#define HEAD_Male_Grant 0x34
#define HEAD_Male_Des 0x35
#define HEAD_Male_Chris 0x36
#define HEAD_Male_Lee 0x37
#define HEAD_Male_Neil 0x38
#define HEAD_Male_Jim 0x39
#define HEAD_Male_Robin 0x3A
#define HEAD_Male_Steve_H 0x3B
#define HEAD_Male_Terrorist 0x3C
#define HEAD_Male_Biker 0x3D
#define HEAD_Male_Graeme 0x3E
#define HEAD_Male_Steve_Ellis 0x3F
#define HEAD_Male_Joel 0x40
#define HEAD_Male_Scott 0x41
#define HEAD_Male_Joe_Altered 0x42
#define HEAD_Male_Ken 0x43
#define HEAD_Male_Joe 0x44
#define HEAD_Male_Mishkin 0x45
#define HEAD_Female_Sally 0x46
#define HEAD_Female_Marion_Rosika 0x47
#define HEAD_Female_Mandy 0x48
#define HEAD_Female_Vivien 0x49
#define HEAD_Male_Pierce_Bond_1 0x4A
#define HEAD_Male_Pierce_Bond_2 0x4B
#define HEAD_Male_Pierce_Bond_3 0x4C
#define HEAD_Male_Pierce_Bond_Parka 0x4D
#define HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT 0x4E
#define HEAD_Natalya_Jungle_Fatigues 0x4F

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
  s32 anonymous_0;
  s32 anonymous_1;
  f32 anonymous_2;
  f32 anonymous_3;
  s32 anonymous_4;
  f32 anonymous_5;
  f32 anonymous_6;
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
  u32 *explosion_death_animation;
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

#endif
