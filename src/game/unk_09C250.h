#ifndef _UNK_09C250_H_
#define _UNK_09C250_H_
#include "ultra64.h"
#include "bondtypes.h"

extern struct PropRecord *ptr_smoke_buf;
extern struct PropRecord *ptr_explosion_buf;
extern s32 numExplosionEntries;
extern f32 D_80040178;
extern char dword_CODE_bss_8007A100[];

void sub_GAME_7F09FD3C(void);
Gfx * sub_GAME_7F0A0034(Gfx *arg0);

#endif
