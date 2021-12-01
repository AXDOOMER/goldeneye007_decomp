#ifndef _CHROBJHANDLER_H_
#define _CHROBJHANDLER_H_

#include "ultra64.h"
#include "bondconstants.h"
#include "bondtypes.h"
#include "snd.h"

extern s32 D_80030B00;
extern f32 F_80030B14;
extern f32 F_80030B18;
extern f32 F_80030B1C;
extern f32 F_80030B20;
extern f32 F_80030B24;
extern f32 g_SoloAmmoMultiplier;

/**
 * @param arg0: entity pointer, maybe PropModel
 * @param arg1: maybe flags
 */
void sub_GAME_7F04F218(s32 arg0, s32 arg1);

void sub_GAME_7F041024(struct object_standard * arg0, s32 arg1);

void chrobjApplySpeed(f32 *openPosition, f32 maxFrac, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed);
void chrobjCallsApplySpeed(f32 *openPosition, f32 maxFrac, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed);
Gfx * sub_GAME_7F049B58(Gfx *arg0);
void set_color_shading_from_tile(struct PropRecord*, u8 *);
void sub_GAME_7F04BFD0(struct PropRecord *, s32);
void sub_GAME_7F053A10(ALSoundState *, struct coord3d *);
void start_alarm(void);
void sub_GAME_7F052574(PropRecord *, s32);
s32 sub_GAME_7F052604(PropRecord *);

object_standard *create_new_item_instance_of_model(PROPS propid, s32 arg1);
void maybe_detonate_object(struct ObjectRecord *arg0, f32 arg1, struct coord3d *arg2, ITEM_IDS item, s32 arg4);
void chrobjMaybeDetonateObjectIfFlags(ObjectRecord *arg0, f32 arg1, struct coord3d *arg2, ITEM_IDS item, s32 arg4);
void sub_GAME_7F03FDA8(PropRecord *);
void sub_GAME_7F03FE14(PropRecord *);
void sub_GAME_7F040484(ObjectRecord *);
void sub_GAME_7F040754(ObjectRecord *, struct coord3d *, Mtxf *, struct StandTile *);

#endif
