#ifndef _LOADOBJECTMODEL_H_
#define _LOADOBJECTMODEL_H_
#include <ultra64.h>

s32 sizepropdef(PropDefHeaderRecord *pdef);

void sub_GAME_7F056CA0(ObjectRecord *);
s32 sub_GAME_7F056850(PadRecord *arg0, StandTile *arg1, f32 arg2, PadRecord *arg3, StandTile **arg4);
ObjectRecord *sub_GAME_7F056A88(s32 index);
s32           check_if_object_type_has_been_loaded(struct object_standard *arg0);
#endif
