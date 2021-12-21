#ifndef _UNK_08DBB0_H_
#define _UNK_08DBB0_H_
#include "ultra64.h"

#include "bondtypes.h"

struct init_bond_anim_unk {
    u32 anim_id;
    f32 unk04;
    f32 unk08;
    f32 unk0C;

    f32 unk10;
    f32 unk14;
};

extern struct init_bond_anim_unk g_BondMoveAnimationSetup[];

s32 sub_GAME_7F08F4F0(struct path_table_alt *, struct path_table_alt *, struct path_table_alt ** arr, s32 arr_len);
struct path_table_alt * sub_GAME_7F08FB90(struct path_table_alt *, struct path_table_alt *);
void currentPlayerToggle5BC();
void currentPlayerUpdateIdleHeadRoll();
void sub_GAME_7F08E240(f32 arg0, f32 arg1);
void sub_GAME_7F08E8BC(f32 arg0);

#endif
