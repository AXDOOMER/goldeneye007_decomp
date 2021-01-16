#ifndef _JOY_H_
#define _JOY_H_

#include "ultra64.h"
void joySystemInit(void);
s8 joyGetControllerCount(void);
u16 joyGetButtonsPressedThisFrame(s8 arg0, u16 arg1);
void controller_check_for_rumble_maybe(void);

#endif
