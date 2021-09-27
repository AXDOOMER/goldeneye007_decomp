#ifndef _CHROBJHANDLER_H_
#define _CHROBJHANDLER_H_

#include "ultra64.h"

extern s32 D_80030B00;
extern f32 F_80030B14;
extern f32 F_80030B18;
extern f32 F_80030B1C;
extern f32 F_80030B20;
extern f32 F_80030B24;
extern f32 solo_ammo_multiplier;

void chrobjApplySpeed(f32 *distDone, f32 maxDist, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed);

#endif
