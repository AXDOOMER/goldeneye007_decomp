#ifndef _TEXTRELATED_H_
#define _TEXTRELATED_H_
#include <ultra64.h>

extern s32 ptrFirstFontTableSmall;
extern s32 ptrSecondFontTableSmall;
extern s32 ptrFirstFontTableLarge;
extern s32 ptrSecondFontTableLarge;

void textrelatedInit_REMOVED(void);
void load_font_tables(void);

Gfx * microcode_constructor_related_to_menus(Gfx *, s32, s32, s32, s32, s32);
void sub_GAME_7F0AE98C(s32 *y2, s32 *x2, u8 *text, s32 ptrSecondFontTableLarge, s32 ptrFirstFontTableLarge, s32 unk5);
#endif
