#ifndef _GBI_EXT_H_
#    define _GBI_EXT_H_
#include <PR/gbi.h>

/** 
 * This file should contain most of the extensions to gbi avoiding loosing 
 * changes should the OS ever be updated.
 */

/**
   These are some helper constants. Since they relate to nothing else except GBI
   macros, Ill place them here, to save reserving names that might be used
   elsewhere - though doubtfull.
 */
#define MASK_2 1
#define MASK_4 2
#define MASK_8 3
#define MASK_16 4
#define MASK_32 5
#define MASK_64 6
#define MASK_128 7
#define MASK_256 8
#define MASK_512 9
#define MASK_1024 10

/* Set the Texel Scale (0.0 - 1.0) for multiplying UV's eg, 0.5 * (31 << 6) = 31.0 */
#define CALC_TEXSCALE(scale) scale < 1.0f ? scale * 0x10000 : 0xffff

/* Set the Lower Right S Coordinate using texture width */
#define CALC_LRS(width, height, siz) ((((width) * (height) + siz##_INCR) >> siz##_SHIFT) - 1)

#define CALC_TILESIZE(texel)         ((texel)-1) << G_TEXTURE_IMAGE_FRAC



#ifdef TRI4_Ext
#    define G_TRI4 (G_IMMFIRST - 14)
#    define G_SETTEX 0xc0 /*   0 */
#endif

/* Fade Modes ... for GE? */
#define G_CC_MODULATEIFADE    TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT
#define G_CC_MODULATERGBFADE  G_CC_MODULATEIFADE
#define G_CC_MODULATEIFADEA   TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0
#define G_CC_MODULATEFADE     TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, TEXEL0, 0
#define G_CC_MODULATERGBFADEA G_CC_MODULATEIFADEA
#define G_CC_FADE             SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0
#define G_CC_FADEA            TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0
#define G_CC_DECALFADE        0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT
#define G_CC_DECALFADEA       0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0
#define G_CC_BLENDRGBFADEA    TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, ENVIRONMENT
#define G_CC_ADDRGBFADE       TEXEL0, 0, TEXEL0, SHADE, 0, 0, 0, ENVIRONMENT
#define G_CC_SHADEFADEA       0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT


/* Custom version of RM_AA_ZB_XLU_SURF with Z_UPD */
#define RM_CUSTOM_AA_ZB_XLU_SURF(clk) \
    RM_AA_ZB_XLU_SURF(clk) | Z_UPD



#define G_RM_CUSTOM_AA_ZB_XLU_SURF  RM_CUSTOM_AA_ZB_XLU_SURF(1)
#define G_RM_CUSTOM_AA_ZB_XLU_SURF2 RM_CUSTOM_AA_ZB_XLU_SURF(2)


#ifdef TRI4_Ext
/***
 ***  4 Triangles
 ***/

//cannot use 2tri with 4tri, so lets just make sure they are undefined so errors happen.
#    undef gSP2Triangles
#    undef gsSP2Triangles

#    define gSP4Triangles(pkt, v00, v01, v02, v10, v11, v12, v20, v21, v22, v30, v31, v32 ) \
            {                                                                  \
                Gfx *_g = (Gfx *)(pkt);                                        \
                                                                               \
                _g->words.w0 = (_SHIFTL(G_TRI4, 24, 8) |                       \
                                /*STUFF GOES HERE*/);    \
                _g->words.w1 = /*STUFF GOES HERE*/;      \
            }

#    define gsSP4Triangles(v00, v01, v02, v10, v11, v12, v20, v21, v22, v30, v31, v32) \
            {                                                              \
                {                                                          \
                    (_SHIFTL(G_TRI4, 24, 8) |                              \
                    /*STUFF GOES HERE*/),           \
                        /*STUFF GOES HERE*/          \
                }                                                          \
            }
#endif

/*
 * Texturing macro Overrides
 */

#define gsSPUseTexture()\
{                                 \
        {                             \
            (_SHIFTL(G_SETTEX, 24, 8) | \
             /*STUFF GOES HERE*/),    \
            /*STUFF GOES HERE*/       \
        }                             \
    }

#if 0 //Rare - so far - didnt seem to use this
#undef gDPLoadTextureBlock
/**
 Override of Load Texture Block without the PipeSync.
 Loads a Texture and sets its tile
 @param   timg: Address of the texture image. E.g. IMAGESEG(IMAGE_SMOKE_0)
 @param    fmt: Texture image format: E.g. G_IM_FMT_IA 
 @param    siz: Pixel component size: E.g. G_IM_SIZ_8b 
 @param  width: Texture image width
 @param height: Texture image height
 @param    pal: Location of palette for 4-bit color index texture (0 - 15)
 @param    cms: s-axis mirror, no-mirror, wrap, and clamp flags
 @param    cmt: t-axis mirror, no-mirror, wrap, and clamp flags
 @param  masks: s-axis mask (0 - 15 or G_TX_NOMASK)
 @param  maskt: t-axis mask (0 - 15 or G_TX_NOMASK)
 @param shifts: s-coordinate shift value or G_TX_NOLOD 
 @param shiftt: t-coordinate shift value or G_TX_NOLOD 
 */
#define gDPLoadTextureBlock(pkt, timg, fmt, siz, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt)                               \
    {                                                                                                                                      \
        gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg);                                                                           \
        gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);                            \
        gDPLoadSync(pkt);                                                                                                                  \
        gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width) * (height) + siz##_INCR) >> siz##_SHIFT) - 1, CALC_DXT(width, siz##_BYTES));      \
        gDPSetTile(pkt, fmt, siz, (((width)*siz##_LINE_BYTES) + 7) >> 3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); \
        gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)              \
    }

#undef gsDPLoadTextureBlock
/**
 Override of Load Texture Block (static) without the PipeSync.
 Loads a Texture and sets its tile
 @param   timg: Address of the texture image. E.g. IMAGESEG(IMAGE_SMOKE_0)
 @param    fmt: Texture image format: E.g. G_IM_FMT_IA 
 @param    siz: Pixel component size: E.g. G_IM_SIZ_8b 
 @param  width: Texture image width
 @param height: Texture image height
 @param    pal: Location of palette for 4-bit color index texture (0 - 15)
 @param    cms: s-axis mirror, no-mirror, wrap, and clamp flags
 @param    cmt: t-axis mirror, no-mirror, wrap, and clamp flags
 @param  masks: s-axis mask (0 - 15 or G_TX_NOMASK)
 @param  maskt: t-axis mask (0 - 15 or G_TX_NOMASK)
 @param shifts: s-coordinate shift value or G_TX_NOLOD 
 @param shiftt: t-coordinate shift value or G_TX_NOLOD 
 */
#define gsDPLoadTextureBlock(timg, fmt, siz, width, height, pal, cms, cmt, masks, maskt, shifts, shiftt)                             \
                                                                                                                                     \
    gsDPSetTextureImage(fmt, siz##_LOAD_BLOCK, 1, timg),                                                                             \
    gsDPSetTile(fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts),                              \
    gsDPLoadSync(),                                                                                                                  \
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width) * (height) + siz##_INCR) >> siz##_SHIFT) - 1, CALC_DXT(width, siz##_BYTES)),        \
    gsDPSetTile(fmt, siz, ((((width)*siz##_LINE_BYTES) + 7) >> 3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), \
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#endif
#endif
