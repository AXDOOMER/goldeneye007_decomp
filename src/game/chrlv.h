#ifndef _CHR2_H_
#define _CHR2_H_
#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"





s32 load_body_head_if_not_loaded(s32 model);

Model * makeonebody(int body,int head, ModelFileHeader *bodyheader,ModelFileHeader *headheader, int sunglasses,Model *model);

Model * setup_chr_instance(int body,int head, ModelFileHeader *body_header, ModelFileHeader *head_header,int sunglasses);

Model * retrieve_header_for_body_and_head(s32 body, s32 head, u32 bitflags);

s32 get_current_random_body(void);

s32 select_psuedorandom_heads(s32 id);

s32 get_random_head(s32 id);
f32 distToBond3D(struct ChrRecord *guardData);

void chrlvAlertGuardToPlayerPosition(struct ChrRecord *);
void chrlvIdleAnimationRelated7F023A94(struct ChrRecord *arg0, f32 arg1);
f32 sub_GAME_7F032C4C(struct ChrRecord *arg0);
s32 check_if_actor_stationary(struct ChrRecord *);
s32 convertPadIf9000(struct ChrRecord *guardData,s32 padNo);
void chrlvLineLineIntersection(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *arg2, struct coord3d *arg3, struct coord3d *result);
void chrlvStanLineDirIntersection(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *result);
void chrlvStanPointPointIntersection(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *result);
bool handles_shot_actors(struct ChrRecord *self, s32 hitpart, struct coord3d *vector, s32 weaponid, bool isPlayer);
bool sub_GAME_7F0294BC(ChrRecord *self);
bool check_if_position_in_same_room(struct ChrRecord *self, struct coord3d *pos, struct StandTile *stan);
s32 sub_GAME_7F032B68(ChrRecord *);
s32 chrIsDead(struct ChrRecord *chr);
bool actor_steps_sideways(ChrRecord *self);
bool actor_hops_sideways(ChrRecord *self);
bool actor_jogs_sideways(ChrRecord *self);
bool actor_walks_and_fires(ChrRecord *self);
bool actor_runs_and_fires(ChrRecord *self);
bool actor_rolls_fires_crouched(ChrRecord *self);
bool actor_aim_at_actor(ChrRecord *self, s32 a, s32 b);
bool actor_kneel_aim_at_actor(ChrRecord *self, s32 targettype, s32 targetid);
bool check_set_actor_standing_still(ChrRecord *self, s32 faceentitytype, s32 faceentityid);
bool actor_moves_to_preset_at_speed(ChrRecord *self, s32 padid, SPEED speed);
bool if_actor_able_set_on_path(ChrRecord *self, s32 pathid);
f32 chrlvGetSubrotySideback(ChrRecord *arg0);
f32 chrlvGetAimLimitAngle(f32 arg0);
void chrlvUpdateAimendbackShoulders(ChrRecord *arg0, void *arg1, s32 same, s32 swap, f32 next);
void sub_GAME_7F02D118(ChrRecord *arg0, s32 hand, s32 arg2);


#endif
