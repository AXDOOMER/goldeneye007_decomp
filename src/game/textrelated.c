#include <ultra64.h>
#include <memp.h>
#include "textrelated.h"
#include "bondtypes.h"
#include "game/lvl_text.h"

#define SPACE_WIDTH 5

#define M_COLOR_R(x) (u8)(x >> 0x18)
#define M_COLOR_G(x) (u8)(x >> 0x10)
#define M_COLOR_B(x) (u8)(x >> 0x08)
#define M_COLOR_A(x) (u8)(x >> 0x00)


// data
s32 D_80040E80 = 0;
s32 text_spacing = 0;
s32 text_orientation = 0;
s32 text_wordwrap = 0;
s32 overlap_correction = -1;
s32 text_bilevel_filter = FALSE;
s32 text_x = 0;
s32 text_y = 0;
s32 text_s = 0;
s32 text_t = 0;
s32 D_80040EA8 = 0;
struct font * ptrFontBankGothic = NULL;
struct fontchar * ptrFontBankGothicChars = NULL;
struct font * ptrFontZurichBold = NULL;
struct fontchar * ptrFontZurichBoldChars = NULL;

u16 D_80040EBC[] = {
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff
};
u32 D_80040EDC = 0;
u32 D_80040EE0 = 0;

u32 D_80040EE4[] = {
    0x55555555, 0x55555555,
    0xAAAAAAAA, 0xAAAAAAAA,
    0xFFFFFFFF, 0xFFFFFFFF
};

struct fontchar D_80040EFC = {0, 0, 12, 11};

struct fontchar D_80040F14 = {0, 0, 12, 11};


// forward declarations

Gfx *construct_fontchar_microcode(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10);
Gfx *sub_GAME_7F0AE45C(Gfx *gdl, s32 x, s32 y, struct fontchar *curchar, s32 savedx, s32 savedy, s32 width, s32 height);
Gfx *sub_GAME_7F0ADDAC(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, 
                       struct fontchar *prevchar, struct font *font, s32 savedx, s32 savedy, 
                       u32 color, u32 color2, s32 width, s32 height, 
                       s32 arg12);

// -------------------------------------------------------------------------------------------------

void textrelatedInit_REMOVED(void /*, char* asset */)
{
    #ifdef DEBUG
    if (asset == 0)
    {
        osSyncPrintf("\n--- ASSERTION FAULT - %s - %s, line %d\n\n", "textInitText: NULL void* asset", ".\\text.cpp", 0x38 );
    }
    #endif
}

void setTextSpacingInverted(s32 spacing) {
    text_spacing = -spacing;
}

void setTextOrientation(s32 orientation) {
    text_orientation = orientation;
}

void setTextWordWrap(s32 flag) {
    text_wordwrap = flag;
}

void setTextOverlapCorrection(s32 flag) {
    overlap_correction = flag;
}



extern u8 _fontbankgothicSegmentEnd;
extern u8 _fontbankgothicSegmentRomStart;
extern u8 _fontzurichboldSegmentEnd;
extern u8 _fontzurichboldSegmentRomStart;
extern u8 _fontzurichboldSegmentStart;
extern u8 _fontbankgothicSegmentStart;

void load_font_tables(void)
{
    u32 len;
	s32 i;
    
    text_spacing = 0;
    text_orientation = 0;
    text_wordwrap = 0;
    overlap_correction = -1;
    text_bilevel_filter = 0;
    text_x = 0;
    text_y = 0;
    text_s = 0;
    text_t = 0;

    len = (romptr_t)&_fontbankgothicSegmentEnd - (romptr_t)&_fontbankgothicSegmentStart;
	ptrFontBankGothic = (struct font *)mempAllocBytesInBank(len, MEMPOOL_STAGE);
	ptrFontBankGothicChars = ptrFontBankGothic->chars;

	romCopy(ptrFontBankGothic, (void *) &_fontbankgothicSegmentRomStart, len);

    // Convert pointers
	for (i = 0; i < 94; i++) {
		ptrFontBankGothicChars[i].pixeldata += (uintptr_t)ptrFontBankGothic;
	}

    len = (romptr_t)&_fontzurichboldSegmentEnd - (romptr_t)&_fontzurichboldSegmentStart;
	ptrFontZurichBold = (struct font *)mempAllocBytesInBank(len, MEMPOOL_STAGE);
	ptrFontZurichBoldChars = ptrFontZurichBold->chars;

	romCopy(ptrFontZurichBold, (void *) &_fontzurichboldSegmentRomStart, len);

    // Convert pointers
	for (i = 0; i < 94; i++) {
		ptrFontZurichBoldChars[i].pixeldata += (uintptr_t)ptrFontZurichBold;
	}
}


Gfx *microcode_constructor(Gfx *gdl) //fontGfxSetup
{
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);

	if (text_bilevel_filter) {
		gDPSetTextureFilter(gdl++, G_TF_AVERAGE);
	} else {
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
	}

	return gdl;
}

Gfx *combiner_bayer_lod_perspective(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureLOD(gdl++, G_TL_LOD);

	return gdl;
}

Gfx* draw_blackbox_to_screen(Gfx *glist, s32 *ulx, s32 *uly, s32 *lrx, s32 *lry)
{
    gDPSetRenderMode(glist++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(glist++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(glist++, 0, 0, 0x00, 0x00, 0x00, 0x00);
    gDPFillRectangle(glist++, *ulx, *uly, *lrx, *lry);
    gDPSetRenderMode(glist++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(glist++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    
    return glist;
}




Gfx * microcode_constructor_related_to_menus(Gfx *gdl, s32 ulx, s32 uly, s32 lrx, s32 lry, u32 color)
{
    u32 r = (u8)(color >> 0x18);
    u32 g = (u8)(color >> 0x10);
    u32 b = (u8)(color >> 0x8);
    u32 a = (u8)(color >> 0);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gdl++, 0, 0, r, g, b, a);
    gDPFillRectangle(gdl++, ulx, uly, lrx, lry);
    gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    return gdl;
}



// perfect dark: textRenderChar
// see also perfect dark: Gfx *text0f15568c(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
// 		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10)
// see also perfect dark: Gfx *text0f156a24
// see also perfect dark: Gfx *textRenderChar
Gfx *construct_fontchar_microcode(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10)
{
    s32 stack;
    s32 stack2;
	s32 tmp;
    s32 sp90;

	sp90 = *y + arg10;
	tmp = font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex] + text_spacing;
    *x -= (tmp - 1);

    if (text_orientation || (*x > 0 && *x <= viGetX() && sp90 + curchar->baseline <= viGetY()))
    {
        if (savedx + width >= *x
				&& savedy + height >= curchar->baseline + sp90
				&& *x >= savedx
				&& curchar->baseline + sp90 + curchar->height >= savedy)
        {
            if (curchar->index < 0x80)
            {
                gDPSetTextureLUT(gdl++, G_TT_NONE);

                /*
                gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, curchar->pixeldata);
                gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gdl++);
                gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, (curchar->unkc * curchar->height), 0);
                gDPPipeSync(gdl++);                
                gDPSetTile(gdl++,G_IM_FMT_I,G_IM_SIZ_8b,0,0,G_TX_RENDERTILE,0,G_TX_NOMIRROR | G_TX_WRAP,G_TX_NOMASK,G_TX_NOLOD,G_TX_NOMIRROR | G_TX_WRAP,G_TX_NOMASK,G_TX_NOLOD);
                gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, (curchar->unkc - 1) << 2, (curchar->height - 1) << 2);
                */
                gDPLoadTextureBlock(gdl++, curchar->pixeldata, G_IM_FMT_I, G_IM_SIZ_8b, ((curchar->width + 7) & 0xF8), curchar->height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, 0, 0);
            }
            else
            {
                gDPPipeSync(gdl++);
                gDPSetTextureLUT(gdl++, G_TT_IA16);

                if (D_80040EA8)
                {
                    D_80040EA8 = 0;
                    
                    // FD100000 --------: gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(D_80040EBC));
                    // E8000000 00000000: gDPTileSync(gdl++);
                    // F5000100 07000000: gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                    // E6000000 00000000: gDPLoadSync(gdl++);
                    // F0000000 0703C000: gDPLoadTLUTCmd(gdl++, G_TX_LOADTILE, 15);
                    // E7000000 00000000: gDPPipeSync(gdl++);
                    gDPLoadTLUT_pal16(gdl++, 0, osVirtualToPhysical(D_80040EBC));

                    gDPLoadTLUT_pal16(gdl++, 1, osVirtualToPhysical(&D_80040EDC));
                }

                // FD500000 00000000: gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, 0x00000000);
                // F5500000 07000000: gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                // E6000000 00000000: gDPLoadSync(gdl++);
                // F3000000 07000000: gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 0, 0);
                // E7000000 00000000: gDPPipeSync(gdl++);
                // F5400200 00080000: gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                // F2000000 0003C000: gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, qu102(15), 0);
                //
                // is this a call to gDPLoadTextureBlock ???
                
                gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1,  osVirtualToPhysical((void *) curchar->pixeldata));
                gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gdl++);
                gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, (curchar->height << 2) - 1, 0x800);
                gDPPipeSync(gdl++);
                gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, (curchar->index & 1), G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, 2, 0, 0);
                gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x3c, (curchar->height - 1) << 2);
            }

            if ((*x + curchar->width) <= savedx + width)
            {
				if (savedy <= curchar->baseline + sp90)
                {
					if (curchar->baseline + sp90 + curchar->height <= savedy + height)
                    {
                        if (text_orientation)
                        {
                            // E5000000 --------:
                            // B4000000 --------:
                            // B3000000 0400FC00:
                            gSPTextureRectangleFlip(gdl++,
                                /* xl */ (((sp90 - curchar->baseline) - curchar->height) * 4) + text_y,
                                /* yl */ ((*x * 4) + text_x),
                                /* xh */ ((sp90 - curchar->baseline) * 4) + text_y,
                                /* yh */ ((*x + curchar->width) * 4) + text_x ,
                                /* tile */  G_TX_RENDERTILE,
                                /* s */ text_t,
                                /* t */ ((curchar->height - 1) << 5) + text_s,
                                /* dsdx */ 0x400,
                                /* dsdy */ 0xfc00);
                        }
                        else
                        {
                            // E4000000 --------:
                            // B4000000 --------:
                            // B3000000 04000400:
                            gSPTextureRectangle(gdl++,
                                /* xl */ ((*x * 4) + text_x),
                                /* yl */ ((sp90 + curchar->baseline) * 4) + text_y,
                                /* xh */ ((*x + curchar->width) * 4) + text_x ,
                                /* yh */ ((curchar->baseline + sp90 + curchar->height) * 4) + text_y,
                                /* tile */  G_TX_RENDERTILE,
                                /* s */ text_s,
                                /* t */ text_t,
                                /* dsdx */ 0x400,
                                /* dsdy */ 0x400);
                        }

                    }
                    else if (curchar->baseline + sp90 <= savedy + height)
                    {
                        // E4000000 --------:
                        // B4000000 --------:
                        // B3000000 04000400:
                        gSPTextureRectangle(gdl++,
                            /* xl */ ((*x * 4) + text_x),
                            /* yl */ ((sp90 + curchar->baseline) * 4) + text_y,
                            /* xh */ ((*x + curchar->width) * 4) + text_x ,
                            /* yh */ savedy + height + text_y,
                            /* tile */  G_TX_RENDERTILE,
                            /* s */ text_s,
                            /* t */ text_t,
                            /* dsdx */ 0x400,
                            /* dsdy */ 0x400);
                    }
                }
                else
                {
                    if (curchar->baseline + sp90 + curchar->height >= savedy)
                    {
                        // E4000000 --------:
                        // B4000000 --------:
                        // B3000000 04000400:
                        gSPTextureRectangle(gdl++,
                            /* xl */ ((*x * 4) + text_x),
                            /* yl */ (savedy * 4) + text_y,
                            /* xh */ ((*x + curchar->width) * 4) + text_x ,
                            /* yh */ ((curchar->baseline + sp90 + curchar->height) * 4) + text_y,
                            /* tile */  G_TX_RENDERTILE,
                            /* s */ text_s,
                            /* t */ (((savedy - sp90) - curchar->baseline) << 5) + text_t,
                            /* dsdx */ 0x400,
                            /* dsdy */ 0x400);
                    }
                }
            }
        }
    }
    
    *x += curchar->width;
    return gdl;

}




// perfect dark: textRender
Gfx *textRender(Gfx *gdl, s32 *x, s32 *y, char *text,
                struct fontchar *chars, struct font *font, u32 colour,
                s32 width, s32 height, u32 arg9, s32 lineheight)
{
    s32 savedx;
	s32 savedy;
    s32 prevchar;
    s32 stack = 1;
    s32 stack2;
    s32 stack3;
    s32 stack4;
    //s32 stack5;
    
    D_80040EA8 = 1;

    savedx = *x;
	savedy = *y;
    prevchar = 'H';

	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	if (j_text_trigger != 0 && lineheight < 14) {
		lineheight = 14;
	}

    stack = colour; // ????????????
    gDPSetPrimColor(gdl++, 0, 0, M_COLOR_R(colour), M_COLOR_G(colour), M_COLOR_B(colour), M_COLOR_A(colour));
    
    while (*text != '\0')
    {
		if (*text == ' ') {
			*x += 5;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			prevchar = 'H';

            if ((overlap_correction >= 0) && (savedx == *x))
            {
                *y += overlap_correction;
            }
            else
            {
                *y += lineheight;
            }
            
			text++;
			*x = savedx;
		} else if (*text < 0x80) {
			gdl = construct_fontchar_microcode(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21], font, savedx, savedy, width, height, arg9);
			prevchar = *text;
			text++;
		} else {
			u16 codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
			struct fontchar sp74 = D_80040EFC;

			if (codepoint & 0x2000) {
				sp74.width = 15;
				sp74.height = 16;
			}

            // perfect dark: 0x3c8
#if defined(VERSION_EU) || defined(VERSION_JP)
            if ((codepoint & 0x1fff) >= 0x3c8)
#else
			if ((codepoint & 0x1fff) >= 0x3c7)
#endif
            {
				codepoint = 2;
			}

			sp74.index = codepoint + 0x80;
			sp74.pixeldata = (void *)langGetJpnCharPixels(codepoint);

			gdl = construct_fontchar_microcode(gdl, x, y, &sp74, &sp74, font, savedx, savedy, width, height, arg9);

			text += 2;
		}
	}

    
    return gdl;
}



Gfx *sub_GAME_7F0ADDAC(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, 
                       /*sp70*/ struct fontchar *prevchar, struct font *font, s32 savedx, s32 savedy, 
                       /*sp80*/u32 color, u32 color2, s32 width, s32 height, 
                       /*sp90*/ s32 arg12)
{
    s32 var_s1;
    s32 var_s0;
    s32 tmp;
    s32 sp50;
    s32 tmpx;
    s32 tmpy;
    u32 tmpcolor;

    sp50 = *y + arg12;

    tmp = font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex] + text_spacing;
    *x -= (tmp - 1);

    if (*x > 0
            && *x <= viGetX()
            && sp50 + curchar->baseline <= viGetY()
            && *x <= savedx + width
            && sp50 + curchar->baseline <= savedy + height
            && *x >= savedx
            && sp50 + curchar->baseline + curchar->height >= savedy) {
        if (curchar->index < 0x80) {
            gDPSetTextureLUT(gdl++, G_TT_NONE);
            gDPLoadTextureBlock(gdl++, curchar->pixeldata, G_IM_FMT_I, G_IM_SIZ_8b, ((curchar->width + 7) & 0xF8), curchar->height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, 0, 0);
        } else {
            gDPPipeSync(gdl++);
            gDPSetTextureLUT(gdl++, G_TT_IA16);

            if (D_80040EA8) {
                D_80040EA8 = 0;

                gDPLoadTLUT_pal16(gdl++, 0, osVirtualToPhysical(&D_80040EBC));
                gDPLoadTLUT_pal16(gdl++, 1, osVirtualToPhysical(&D_80040EDC));
            }

            gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1,  osVirtualToPhysical((void *) curchar->pixeldata));
            gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync(gdl++);
            gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, (curchar->height << 2) - 1, 0x800);
            gDPPipeSync(gdl++);
            gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, (curchar->index & 1), G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, 2, 0, 0);
            gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x3c, (curchar->height - 1) << 2);
        }

        tmpcolor = color2;
        gDPSetPrimColor(gdl++, 0, 0, M_COLOR_R(tmpcolor), M_COLOR_G(tmpcolor), M_COLOR_B(tmpcolor), M_COLOR_A(tmpcolor));

        for (var_s1 = -1; var_s1 < 2; var_s1++) {
            for (var_s0 = -1; var_s0 < 2; var_s0++) {
                tmpx = *x + var_s1;
                tmpy = sp50 + var_s0;

                if (var_s1 != 0 || var_s0 != 0) {
                    gdl = sub_GAME_7F0AE45C(gdl, tmpx, tmpy, curchar, savedx, savedy, width, height);
                }
            }
        }

        tmpx = *x;
        tmpy = sp50;
        tmpcolor = color;
        gDPSetPrimColor(gdl++, 0, 0, M_COLOR_R(tmpcolor), M_COLOR_G(tmpcolor), M_COLOR_B(tmpcolor), M_COLOR_A(tmpcolor));
        gdl = sub_GAME_7F0AE45C(gdl, tmpx, tmpy, curchar, savedx, savedy, width, height);
    }

    *x += curchar->width;

    return gdl;
}



Gfx *sub_GAME_7F0AE45C(Gfx *gdl, s32 x, s32 y, struct fontchar *curchar, s32 savedx, s32 savedy, s32 width, s32 height)
{
    if (savedx + width >= curchar->width + x)
    {
        if (curchar->baseline + y >= savedy)
        {
            if (savedy + height >= curchar->baseline + y + curchar->height)
            {
                if (text_orientation)
                {
                    gSPTextureRectangleFlip(gdl++, ((y - curchar->baseline) - curchar->height) << 2, x << 2, (y - curchar->baseline) << 2, (x + curchar->width) << 2, G_TX_RENDERTILE, 0, (curchar->height - 1) << 5, 0x400, 0xFC00);
                }
                else
                {
                    gSPTextureRectangle(gdl++, x << 2, (y + curchar->baseline) << 2, (x + curchar->width << 2), (curchar->baseline + y + curchar->height) << 2, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
                }
            }
            else if (savedy + height >= curchar->baseline + y)
            {
                gSPTextureRectangle(gdl++, x << 2, (y + curchar->baseline) << 2, (x + curchar->width) << 2, (savedy + height << 2), G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
            }
        }
        else if (curchar->baseline + y + curchar->height >= savedy)
        {
            gSPTextureRectangle(gdl++, x << 2, savedy<< 2, (x + curchar->width) << 2, (curchar->baseline + y + curchar->height) << 2, G_TX_RENDERTILE, 0, ((savedy - curchar->baseline) - y) << 5, 0x400, 0x400);
        }
    }

    return gdl;
}




Gfx *textRenderGlow(Gfx *gdl, s32 *x, s32 *y, 
                    char *text, struct fontchar *chars, struct font *font, 
                    u32 colour, u32 colour2, s32 width, s32 height, 
                    s32 arg10, s32 lineheight)
{
    u16 codepoint;
	s32 savedy;
    s32 savedx;
    struct fontchar sp74;
    s32 prevchar;
    
    D_80040EA8 = 1;

    savedx = *x;
	savedy = *y;
    prevchar = 'H';

	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	if (j_text_trigger != 0 && lineheight < 14) {
		lineheight = 14;
	}
    
    while (*text != '\0')
    {
		if (*text == ' ') {
			*x += SPACE_WIDTH;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			prevchar = 'H';
			*x = savedx;
            *y += lineheight;
			text++;
		} else if (*text < 0x80) {
            gdl = sub_GAME_7F0ADDAC(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21], font, savedx, savedy, colour, colour2, width, height, arg10);
			prevchar = *text;
			text++;
		} else {
            codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
            sp74 = D_80040F14;

			if (codepoint & 0x2000) {
				sp74.width = 15;
				sp74.height = 16;
			}

#if defined(VERSION_EU) || defined(VERSION_JP)
            if ((codepoint & 0x1fff) >= 0x3c8)
#else
			if ((codepoint & 0x1fff) >= 0x3c7)
#endif
            {
				codepoint = 2;
			}

			sp74.index = codepoint + 0x80;
			sp74.pixeldata = (void *)langGetJpnCharPixels(codepoint);

            gdl = sub_GAME_7F0ADDAC(gdl, x, y, &sp74, &sp74, font, savedx, savedy, colour, colour2, width, height, arg10);

			text += 2;
		}
	}

    return gdl;
}




void textMeasure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight)
{
    char prevchar;
	s32 longest;
	s32 tmp;

	prevchar = 'H';
    tmp = 0;
	longest = 0;
	*textheight = 0;
	*textwidth = 0;

    if (lineheight == 0)
    {
		lineheight = font1['['].baseline + font1['['].height;
    }
    
    if ((j_text_trigger) && (lineheight < 14))
    {
        lineheight = 14;
    }

    while (*text != '\0')
    {
        if (*text == ' ')
        {
            // Space
            if (text[1] != '\n') {
                *textwidth += SPACE_WIDTH;
            }

            prevchar = 'H';
            text++;
        }
        else if (*text == '\n')
        {
            // Line break
            if (*textwidth > longest) {
                longest = *textwidth;
            }

            *textwidth = 0;
            *textheight += lineheight;
            text++;
        }
        else if (*text < 0x80)
        {
            // Normal single-byte character
            tmp = font2->kerning[font1[prevchar - 0x21].kerningindex * 13 + font1[*text - 0x21].kerningindex] + text_spacing - 1;
            *textwidth = font1[*text - 0x21].width + *textwidth - tmp;

            prevchar = *text;
            text++;
        }
        else if (*text < 0xC0)
        {
            // Multi-byte character
            tmp = font2->kerning[0] + text_spacing - 1;
            *textwidth = *textwidth - tmp + 11;
            text += 2;
        }
        else
        {
            // Multi-byte character
            tmp = font2->kerning[0] + text_spacing - 1;
            *textwidth = *textwidth - tmp + 15;
            text += 2;
        }
    };
    
    if (*textwidth < longest)
    {
        *textwidth = longest;
    }
}



// perfect dark: void textWrap
void sub_GAME_7F0AEB64(s32 wrapwidth, char *src, char *dst, struct fontchar *chars, struct font *font)
{
	s32 curlinewidth = 0;
	bool itfits;
	s32 wordlen;
	s32 wordwidth;
	s32 wordheight = 0;
	s32 more = 1;
	s32 v1;
	s32 i;
	u32 stack;
	char curword[32];

    while (more == 1) {
		// Load the next word
		wordwidth = 0;
		wordlen = 0;
		v1 = 0;

        while (*src > ' ')
        {
            curword[wordlen] = *src;
			v1 += chars[*src - 0x21].width;
			src++;
			wordlen++;

            if (curword[wordlen - 1] >= 0x80)
            {
                curword[wordlen] = *src;
                v1 += chars[*src - 0x21].width;
                src++;
                wordlen++;
            }
        }
        
        curword[wordlen] = '\0';

        textMeasure(&wordheight, &wordwidth, curword, chars, font, 0);

        curlinewidth += wordwidth;

        if (curlinewidth <= wrapwidth) {
            itfits = 1;
        } else {
            itfits = 0;
        }

        if (*src == '\n')
        {
            // Write a new line and indent
			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < text_wordwrap; i++) {
					*dst = ' ';
					dst++;
				}
			}

			curlinewidth = 0;

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the original new line that was in src
			*dst = '\n';
			dst++;
        }
        else if (*src == ' ')
        {
            if (!itfits)
            {
				// Write a new line and indent
				*dst = '\n';
				dst++;

				for (i = 0; i < text_wordwrap; i++)
                {
					*dst = ' ';
					dst++;
				}

				curlinewidth = text_wordwrap * SPACE_WIDTH + wordwidth;
			}

			curlinewidth += SPACE_WIDTH;

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the trailing space
			*dst = ' ';
			dst++;
        }
        else if (*src == '\0')
        {
            more = 0;

			if (!itfits) {
				// Write a new line and indent
				*dst = '\n';
				dst++;

				for (i = 0; i < text_wordwrap; i++) {
					*dst = ' ';
					dst++;
				}
			}

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the null terminator
			*dst = '\0';
        }

        src++;
    }
}


void sub_GAME_7F0AEF0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    // (function likely stubbed)
}

u32 sub_GAME_7F0AEF20(u32 param_1,u32 param_2){
  return param_1;
}


