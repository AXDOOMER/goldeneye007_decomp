#ifndef _ACTIONBLOCK_H_
#define _ACTIONBLOCK_H_
#include "ultra64.h"

struct sfx_register_struct {
    u32 field_0x0;
    u32 field_0x4;
    u32 field_0x8;
    u32 field_0xc;
    u32 field_0x10;
    u32 field_0x14;
};

extern u32 D_800312A0[];
extern u32 D_800312B4[];
extern u32 D_800312C8[];
extern u32 D_800312F4[];
extern u32 D_80031310[];

extern u32 monitor_animation_microcode[];
extern u32 dword_D_80031F00[];
extern u32 dword_D_80031F44[];

void stop_alarm(void);

void sub_GAME_7F055EF8(void);

#endif
