#ifndef _GBI_EXT_H_
#    define _GBI_EXT_H_
#include <PR/gbi.h>

/** 
 * This file should contain most of the extensions to gbi avoiding loosing 
 * changes should the OS ever be updated.
 */

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
#    define gSP2Triangles(pkt, v00, v01, v02, v10, v11, v12, v20, v21, v22, v30, v31, v32 ) \
            {                                                                  \
                Gfx *_g = (Gfx *)(pkt);                                        \
                                                                               \
                _g->words.w0 = (_SHIFTL(G_TRI4, 24, 8) |                       \
                                /*STUFF GOES HERE*/);    \
                _g->words.w1 = /*STUFF GOES HERE*/;      \
            }

#    define gsSP2Triangles(v00, v01, v02, v10, v11, v12, v20, v21, v22, v30, v31, v32) \
            {                                                              \
                {                                                          \
                    (_SHIFTL(G_TRI4, 24, 8) |                              \
                    /*STUFF GOES HERE*/),           \
                        /*STUFF GOES HERE*/          \
                }                                                          \
            }
#endif

#define gsSPUseTexture()\
{                                 \
        {                             \
            (_SHIFTL(G_SETTEX, 24, 8) | \
             /*STUFF GOES HERE*/),    \
            /*STUFF GOES HERE*/       \
        }                             \
    }

#endif
