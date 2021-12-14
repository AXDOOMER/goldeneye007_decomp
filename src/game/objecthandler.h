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
void getsuboffset(struct Model *, struct coord3d *);
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
struct Model *get_aircraft_obj_instance_controller(struct ModelFileHeader *);
void sub_GAME_7F06C3B4(struct Model *, s32, struct  ModelFileHeader *);

// tentative signature
void setpartoffset(Model *, ModelNode *, struct coord3d *);

// tentative signature
void setsuboffset(Model *arg0, struct coord3d *arg1);

// tentative signature
struct PropRecord *actor_draws_weapon_with_model(struct ChrRecord *arg0, s32 arg1, s32 item_id, s32 flags);

// tentative signature
Mtxf* sub_GAME_7F06C660(struct Model *arg0, struct ModelNode *arg1, s32 arg2);

// called with struct ChrRecord->field_20
void sub_GAME_7F06B248(void *arg0);
void drawjointlist(struct unk_joint_list *arg0, void* arg1);
void sub_GAME_7F073FC8(s32);

#ifndef VERSION_EU
void return_null(void);
#endif

#endif
