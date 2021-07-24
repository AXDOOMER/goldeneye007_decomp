#ifndef _CHROBJHANDLER_H_
#define _CHROBJHANDLER_H_

#include "ultra64.h"

extern s32 D_80030B00;

void chrobjApplySpeed(f32 *distDone, f32 maxDist, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed);

#endif
