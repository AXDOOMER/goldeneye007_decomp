#ifndef _CHROBJHANDLER_H_
#define _CHROBJHANDLER_H_

#include "ultra64.h"

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

void chrobjApplySpeed(f32 *distDone, f32 maxDist, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed);
Gfx * sub_GAME_7F049B58(Gfx *arg0);

#endif
