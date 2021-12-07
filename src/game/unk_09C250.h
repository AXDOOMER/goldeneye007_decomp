#ifndef _UNK_09C250_H_
#define _UNK_09C250_H_
#include "ultra64.h"
#include "bondtypes.h"

typedef struct s_smoketype {
    s16 duration;
    s16 rateappear;
    s16 ratedissolve;
    s16 size;
    f32 bg_rotrate;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    f32 fg_rotrate;
    s16 propagated_clouds;
    u16 field_0x16;
} s_smoketype;

typedef struct s_explosiontype {
    f32 hrange;
    f32 vrange;
    f32 hchange;
    f32 vchange;
    f32 explosion_size;
    f32 explosion_range;
    f32 dmg_range;
    u16 duration;
    u16 propagationrate;
    f32 flareanimspeed;
    u16 numshrapnelbits;
    //u16 field_0x26;
    f32 shrapnel_size;
    f32 shrapnel_scatter_dist;
    f32 shrapnel_hvel;
    f32 shrapnel_vvel;
    u8 smoketype;
    u8 sndID;
    //u16 field_0x3a;
    f32 damage;
} s_explosiontype;

extern struct PropRecord *ptr_smoke_buf;
extern struct PropRecord *ptr_explosion_buf;
extern s32 numExplosionEntries;
extern f32 D_80040178;
extern char dword_CODE_bss_8007A100[];



void sub_GAME_7F09FD3C(void);
Gfx * sub_GAME_7F0A0034(Gfx *arg0);

#endif
