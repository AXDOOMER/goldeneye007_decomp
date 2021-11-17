#ifndef _OBJECTHANDLER_
#define _OBJECTHANDLER_
#include "ultra64.h"
#include "bondtypes.h"

extern s32 D_80036410;
extern s32 D_80036414;
extern s32 D_80036418;
extern s32 D_8003641C;
extern s32 D_80036084;
extern f32 D_80036088;
extern s32 vtxallocator;

// arg0 unknown pointer
void sub_GAME_7F070090(void *arg0, f32 arg1, f32 arg2);

// unsure of arg1 pointer type.
void objecthandlerAnimationRelated7F06FCA8(object_standard *, void*, s32, f32, f32, f32);

void sub_GAME_7F06FDCC(object_standard *, f32, f32);
void sub_GAME_7F06FDE8(object_standard *, f32);

void sub_GAME_7F06FF18(struct object_standard *, f32, f32);
void set_obj_instance_controller_scale(struct Model*, f32);
void getsuboffset(s32, struct float3 *);
void sub_GAME_7F070AEC(struct object_standard *, s32, s32);
void subcalcpos(struct object_standard *);

#endif
