#ifndef _MP_WEAPON_H_
#define _MP_WEAPON_H_
#include "ultra64.h"

struct s_mp_weapon_set
{
  s32 anonymous_0;
  s32 anonymous_1;
  f32 anonymous_2;
  s32 anonymous_3;
  s32 anonymous_4;
  s32 anonymous_5;
};

struct struct_8
{
  char anonymous_0;
  char field_1;
  char field_2;
  char field_3;
  struct s_mp_weapon_set * anonymous_1;
};

extern struct s_mp_weapon_set mp_weapon_set_slaps[];
extern struct s_mp_weapon_set mp_weapon_set_pistols[];
extern struct s_mp_weapon_set mp_weapon_set_knife[];
extern struct s_mp_weapon_set mp_weapon_set_auto[];
extern struct s_mp_weapon_set mp_weapon_set_power[];
extern struct s_mp_weapon_set mp_weapon_set_sniper[];
extern struct s_mp_weapon_set mp_weapon_set_grenade[];
extern struct s_mp_weapon_set mp_weapon_set_remote_m[];
extern struct s_mp_weapon_set mp_weapon_set_glaunch[];
extern struct s_mp_weapon_set mp_weapon_set_timed_m[];
extern struct s_mp_weapon_set mp_weapon_set_prox_m[];
extern struct s_mp_weapon_set mp_weapon_set_rockets[];
extern struct s_mp_weapon_set mp_weapon_set_lasers[];
extern struct s_mp_weapon_set mp_weapon_set_golden[];

void advance_mp_weapon_set_by_one_save_value(void);
struct struct_8 *get_ptr_current_mp_weapon_set_text_code(void);
struct s_mp_weapon_set * get_ptr_mp_weapon_set_data(void);
void set_mp_weapon_set(s32 arg0);
s32 get_mp_weapon_set(void);

#endif
