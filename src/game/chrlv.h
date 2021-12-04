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
f32 chrlvDistToBond3D(struct ChrRecord *guardData);

void chrlvAlertGuardToPlayerPosition(struct ChrRecord *);
void chrlvIdleAnimationRelated7F023A94(struct ChrRecord *arg0, f32 arg1);
f32 chrGetAngleToBond(struct ChrRecord *arg0);
s32 check_if_actor_stationary(struct ChrRecord *);
s32 convertPadIf9000(struct ChrRecord *guardData,s32 padNo);
void chrlvLineLineIntersection(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *arg2, struct coord3d *arg3, struct coord3d *result);
void chrlvStanLineDirIntersection(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *result);
void chrlvStanPointPointIntersection(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *result);
bool handles_shot_actors(struct ChrRecord *self, s32 hitpart, struct coord3d *vector, s32 weaponid, bool isPlayer);
bool sub_GAME_7F0294BC(ChrRecord *self);
bool check_if_position_in_same_room(struct ChrRecord *self, struct coord3d *pos, struct StandTile *stan);
s32 chrlvSeenWithin600(ChrRecord *);
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
s32 sub_GAME_7F02D630(ChrRecord *arg0, HANDEDNESS hand, struct coord3d *arg2);
void chrlvTriggerFireWeapon(ChrRecord *arg0);
s32 chrlvGeometryRelated7F02FC34(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *arg2, f32 arg3);
s32 chrlvIsArrivingLaterallyAtPos(struct coord3d *prevpos, struct coord3d *curpos, struct coord3d *targetpos, f32 range);
void chrlvActionTick(ChrRecord *arg0);
void chrlvAllChrTick(void);
s32 chrlvSeenWithin600(ChrRecord *arg0);
s32 chrlvHearWithin600(ChrRecord *arg0);
ChrRecord *chrlvGetHandleForGuardId(ChrRecord *arg0, s32);
f32 chrGetAngleFromBond(ChrRecord *self);
f32 sub_GAME_7F032E48(ChrRecord *self, s32 padID);
bool check_if_room_for_preset_loaded(struct ChrRecord *self, s32 padnum);
f32 get_distance_between_actor_and_actorID(struct ChrRecord *self, s32 chrID);
f32 get_distance_between_actor_and_preset(ChrRecord *self, s32 padid);
void chrlvSetBitfieldFlags(ChrRecord *arg0, u8 arg1);
void chrlvClearBitfieldFlags(ChrRecord *arg0, u8 arg1);
void chrlvSetGuardBitfieldFlags(ChrRecord *arg0, s32 guard_id, u8 arg2);
void chrlvClearGuardBitfieldFlags(ChrRecord *arg0, s32 guard_id, u8 arg2);
s32 chrlvTestGuardBitfieldFlags(ChrRecord *arg0, s32 guard_id, u8 arg2);
void toggle_objective_bitflags(ChrRecord *arg0, s32 arg1);
void untoggle_objective_bitflags(ChrRecord *self, u32 flags);
bool check_if_objective_bitflags_set(ChrRecord *self, s32 flags);
bool check_if_actor_02_flag_set(ChrRecord *self);
bool check_if_able_to_then_surrender(ChrRecord *self);
bool sub_GAME_7F0333A0(ChrRecord *self);
void reset_and_start_loop_counter(ChrRecord *self);
f32 get_loop_counter_time_in_seconds(ChrRecord *self);
bool sub_GAME_7F0333F8(ChrRecord *self);
bool check_if_actor_invisible(ChrRecord *self);
bool chrGoToBond(ChrRecord *self, SPEED speed);
bool chrGoToChr(ChrRecord *self, s32 chrid, SPEED speed);
s8 get_times_actor_shot(ChrRecord *self);
s8 get_num_shots_near_actor(ChrRecord *self);
bool check_if_actor_FA_target_set(ChrRecord *self);
bool check_if_actor_FB_target_set(ChrRecord *self);
bool chraiStopAnimation(ChrRecord *self);
bool chrTrySurprisedOneHand(ChrRecord *self);
bool check_if_able_to_then_fawn_on_shoulder(ChrRecord *self);
bool check_if_able_to_then_look_flustered(ChrRecord *self);
bool check_if_able_to_then_kneel(struct ChrRecord *self);




#endif
