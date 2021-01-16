#ifndef _JOY_H_
#define _JOY_H_

#include "ultra64.h"

void joySystemInit(void);
s8 joyGetControllerCount(void);
u16 joyGetButtonsPressedThisFrame(s8 arg0, u16 arg1);
void controller_check_for_rumble_maybe(void);
s8 joyGetStickX(s8 contpadnum);
s8 joyGetStickY(s8 contpadnum);
u16 joyGetButtons(s8 contpadnum, u16 mask);
u16 joyGetButtonsPressedThisFrame(s8 contpadnum, u16 mask);
s32 joyGetStickXInRange(s8 contpadnum, s32 rangemin, s32 rangemax);
s32 joyGetStickYInRange(s8 contpadnum, s32 rangemin, s32 rangemax);

#endif
