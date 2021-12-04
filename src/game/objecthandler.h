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
void sub_GAME_7F06FF18(struct object_standard *, f32, f32);
void set_obj_instance_controller_scale(struct Model*, f32);
void getsuboffset(s32, struct coord3d *);
void sub_GAME_7F070AEC(struct object_standard *, s32, s32);
void subcalcpos(struct object_standard *);

void objecthandlerAnimationRelated7F06FCA8(struct Model *, struct ModelAnimation *, s32, f32, f32, f32);
void sub_GAME_7F06FDCC(struct Model *, f32, f32);
void sub_GAME_7F06FDE8(struct Model *, f32);
void sub_GAME_7F06CE84(struct Model *, f32);

void *extract_id_from_object_structure_microcode(Model *Objinst, ModelNode *root);
f32 getsubroty(Model *objinst);
void setsubroty(Model *objinst, f32 radHeading);
void sub_GAME_7F06FC4C(struct Model *, u8 *, s32, f32, f32, f32, s32);
f32 objecthandlerGetModelField28(struct Model *model);

struct ModelAnimation * objecthandlerGetModelAnim(struct Model *);
f32 sub_GAME_7F06F618(struct Model*);
s32 sub_GAME_7F06F5B4(Model *);
f32 sub_GAME_7F06F5C4(Model *);
s32 sub_GAME_7F06FE4C(Model *, f32, f32);
f32 sub_GAME_7F06F610(struct Model *);
s32 sub_GAME_7F06FE90(Model *arg0, f32 arg1, f32 arg2);
f32 getinstsize(Model *arg0);

void load_object_into_memory(struct ModelFileHeader *header,char *name);
void load_object_into_memory_unused_maybe(struct ModelFileHeader *header,int *recallstring,int *targetloc,int sizeleft);
void set_objuse_flag_compute_grp_nums_set_obj_loaded(struct ModelFileHeader *objheader);

// tentative signature
Mtxf* sub_GAME_7F06C660(struct Model *arg0, struct ModelNode *arg1, s32 arg2);

#ifndef VERSION_EU
void return_null(void);
#endif

#endif
