#ifndef _TEXTRELATED_H_
#define _TEXTRELATED_H_
#include <ultra64.h>
#include "bondtypes.h"

enum TEXT_ORIENTATION {
    ROT_NORMAL = 0,
    ROT_90CW
};

extern s32 ptrFontBankGothic;
extern s32 ptrFontBankGothicChars;
extern s32 ptrFontZurichBold;
extern s32 ptrFontZurichBoldChars;

void textrelatedInit_REMOVED(void);
void load_font_tables(void);


Gfx * microcode_constructor_related_to_menus(Gfx *gdl, s32 ulx, s32 uly, s32 lrx, s32 lry, u32 color);
void textMeasure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight);

Gfx *microcode_constructor(Gfx *gdl);
Gfx *textRender(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *chars, struct font *font, u32 colour, s32 width, s32 height, u32 arg9, s32 lineheight);
Gfx *textRenderGlow(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *chars, struct font *font, u32 colour, u32 colour2, s32 width, s32 height, s32 arg10, s32 lineheight);

Gfx *combiner_bayer_lod_perspective(Gfx *gdl);
void setTextSpacingInverted(s32 spacing);
void setTextWordWrap(s32 flag);
void sub_GAME_7F0AEB64(s32 wrapwidth, char *src, char *dst, struct fontchar *chars, struct font *font);
void setTextOverlapCorrection(s32 flag);

Gfx* draw_blackbox_to_screen(Gfx *glist, s32 *ulx, s32 *uly, s32 *lrx, s32 *lry);

#endif
