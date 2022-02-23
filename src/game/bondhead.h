#ifndef _UNK_08DBB0_H_
#define _UNK_08DBB0_H_
#include <ultra64.h>

#include <bondtypes.h>

struct init_bond_anim_unk {
    u32 anim_id;
    f32 unk04;
    f32 unk08;
    f32 unk0C;

    f32 unk10;
    f32 unk14;
};

extern struct init_bond_anim_unk g_BondMoveAnimationSetup[];

s32 sub_GAME_7F08F4F0(waypoint *, waypoint *, waypoint ** arr, s32 arr_len);
waypoint * sub_GAME_7F08FB90(waypoint *, waypoint *);
void currentPlayerToggle5BC();
void currentPlayerUpdateIdleHeadRoll();
void sub_GAME_7F08E240(f32 arg0, f32 arg1);
void sub_GAME_7F08E8BC(f32 arg0);
void sub_GAME_7F08EA48(struct ModelAnimation *arg0, s32 arg1, f32 arg2, f32 arg3);
void sub_GAME_7F08EAB8(f32 arg0);

#endif
