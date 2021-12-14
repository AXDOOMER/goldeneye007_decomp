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
    //u8 a;
    f32 fg_rotrate;
    s16 propagated_clouds;
    //u16 field_0x16;
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

typedef struct s_impacttype{
    f32 width;
    f32 height;
    u8 apptype;
    u8 unk1;
    u8 unk2;
} s_impacttype;

struct scorch_unk {
    s16 roomid;
    s16 unk02;
    u32 unk04;
    u32 unk08;
    u32 unk0C;

    u32 unk10;
    u32 unk14;
    u32 vertex_list[4];
    //u32 unk1C;

    //u32 unk20;
    //u32 unk24;
    u32 unk28;
    u32 unk2C;

    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;

    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;

    u32 unk50;
    u32 unk54;
};

extern struct PropRecord *ptr_smoke_buf;
extern struct PropRecord *ptr_explosion_buf;
extern s32 numExplosionEntries;
extern f32 D_80040178;
extern char dword_CODE_bss_8007A100[];
extern struct scorch_unk *ptr_scorch_buf;



void sub_GAME_7F09FD3C(void);
Gfx * sub_GAME_7F0A0034(Gfx *arg0);
Gfx * sub_GAME_7F0A1D78(Gfx *arg0);
Gfx *sub_GAME_7F0A0AB4(Gfx *arg0);
Gfx *unk09c250RenderPropExplosion(PropRecord *arg0, Gfx *arg1);
Gfx *unk09c250RenderPropSmoke(PropRecord *arg0, Gfx *arg1);


Gfx *sub_GAME_7F0A1A94(Gfx *arg0, struct PropRecord *arg1, s32 arg2);

#endif
