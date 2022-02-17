#ifndef _OBJECTHANDLER_
#define _OBJECTHANDLER_
#include <ultra64.h>
#include <bondtypes.h>

extern s32 D_80036084;
extern f32 D_80036088;
extern u32 D_80036250;
extern s32 D_80036410;
extern s32 D_80036414;
extern s32 D_80036418;
extern s32 D_8003641C;
extern s32 vtxallocator;

// arg0 unknown pointer
void sub_GAME_7F070090(void *arg0, f32 arg1, f32 arg2);
void sub_GAME_7F06FF18(Model *, f32, f32);
void set_obj_instance_controller_scale(Model*, f32);
void getsuboffset(Model *, coord3d *);
void sub_GAME_7F070AEC(Model *, s32, s32);
void subcalcpos(Model *);
 void      sub_GAME_7F06FDE8(Model *model, float endframe);

void objecthandlerAnimationRelated7F06FCA8(Model *, ModelAnimation *, s32, f32, f32, f32);
void sub_GAME_7F06FDCC(Model *, f32, f32);
void sub_GAME_7F06FDE8(Model *, f32);
void sub_GAME_7F06CE84(Model *, f32);

void *extract_id_from_object_structure_microcode(Model *Objinst, ModelNode *root);
f32 getsubroty(Model *objinst);
void setsubroty(Model *objinst, f32 radHeading);
void sub_GAME_7F06FC4C(Model *, u8 *, s32, f32, f32, f32, s32);
f32 objecthandlerGetModelField28(Model *model);

ModelAnimation * objecthandlerGetModelAnim(Model *);
f32 sub_GAME_7F06F618(Model*);
s32 sub_GAME_7F06F5B4(Model *);
f32 sub_GAME_7F06F5C4(Model *);
s32 sub_GAME_7F06FE4C(Model *, f32, f32);
f32 sub_GAME_7F06F610(Model *);
s32 sub_GAME_7F06FE90(Model *arg0, f32 arg1, f32 arg2);
f32 getinstsize(Model *arg0);

void load_object_into_memory(ModelFileHeader *header,char *name);
void load_object_into_memory_unused_maybe(ModelFileHeader *header,int *recallstring,int *targetloc,int sizeleft);
void set_objuse_flag_compute_grp_nums_set_obj_loaded(ModelFileHeader *objheader);
Model *get_aircraft_obj_instance_controller(ModelFileHeader *);
void sub_GAME_7F06C3B4(Model *, s32,  ModelFileHeader *);

// tentative signature
void setpartoffset(Model *, ModelNode *, coord3d *);

// tentative signature
void setsuboffset(Model *arg0, coord3d *arg1);

// tentative signature
PropRecord *chrGiveWeapon(ChrRecord *self, s32 PropID, ITEM_IDS ItemID, s32 flags);

// tentative signature
Mtxf* sub_GAME_7F06C660(Model *arg0, ModelNode *arg1, s32 arg2);

// called with struct ChrRecord->field_20
void sub_GAME_7F06B248(void *arg0);
void drawjointlist(struct unk_joint_list *arg0, void* arg1);
void sub_GAME_7F073FC8(s32);
void sub_GAME_7F0701D4(s32 arg0);
u32 sub_GAME_7F0701E0(void);

// arg0: unknown type. arg1: unknown type. arg5: unknown type, maybe struct.
void sub_GAME_7F06D2E4(s32, s32, ModelSkeleton*, void* anim, s32, s16*);

// arg2 unknown type.
void sub_GAME_7F075FAC(Model *, ModelFileHeader *, void *);
void sub_GAME_7F06FE3C(Model **, void (*)());
void subcalcmatrices(struct unk_joint_list *, Model *);
void instcalcmatrices(struct unk_joint_list *arg0, Model *arg1);

#ifndef VERSION_EU
void return_null(void);
#endif

#endif
