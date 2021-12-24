#ifndef _LOADOBJECTMODEL_H_
#define _LOADOBJECTMODEL_H_
#include "ultra64.h"

u32 sizepropdef(u8 * object);

void sub_GAME_7F056CA0(ObjectRecord *);
s32 sub_GAME_7F056850(struct pad *arg0, StandTile *arg1, f32 arg2, struct pad *arg3, StandTile **arg4);

#endif
