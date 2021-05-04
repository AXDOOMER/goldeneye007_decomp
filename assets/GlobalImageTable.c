#include "ultra64.h"
#include "bondconstants.h"
#include "bondtypes.h"
#include "PR/gbi.h"
#include "assets/image_externs.h"

Gfx globalDL_0x000[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    
    //gsDPSetCombineMode(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0xABCD083A),
    0xFD700000, 0xABCD083A,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList()
};

Gfx globalDL_0x078[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    
    //gsDPSetCombineMode(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0xABCD0824),
    0xFD700000, 0xABCD0824,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),

    //gsDPSetCombineMode(G_IMG_FMT_RGBA,  G_IM_SIZ_16b, 0, 0xABCD0825),
    0xFD100000, 0xABCD0825,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x120[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),

    //gsDPSetCombineMode(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0xABCD0828),
    0xFD700000, 0xABCD0828,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),

    //gsDPSetCombineMode(G_IMG_FMT_RGBA,  G_IM_SIZ_16b, 0, 0xABCD0829),
    0xFD100000, 0xABCD0829,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),

    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x1c8[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD0832,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD0833,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x270[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD0834,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD0835,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x318[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD0836,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD0837,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x3c0[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD0838,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD0839,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x468[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD083A,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD083B,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x510[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD083C,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD083D,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x5b8[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD083E,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD083F,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x660[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD0840,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD0841,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x708[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD0826,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD0827,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x7b0[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD082A,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD082B,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x858[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD082C,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD082D,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x900[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD082E,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD082F,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0x9a8[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0,  TEXEL0, 0, TEXEL1, 0,  COMBINED, 0, SHADE, 0,  COMBINED, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD0830,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1567, 293),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 7, 0, 0, 0, G_TX_WRAP, 6, 0, G_TX_WRAP, 6, 0),
    gsDPSetTileSize(0, 0, 0, 220, 220),
    0xFD100000, 0xABCD0831,
    gsDPSetTile(G_IM_FMT_RGBA,  G_IM_SIZ_16b, 0, 392, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 223, 512),
    0xF5100988, 0x01090A42,
    gsDPSetTileSize(1, 0, 0, 220, 220),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx globalDL_0xa50[] = { 
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0,  TEXEL0, 0, SHADE, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, 0, 1),
    0xFD700000, 0xABCD03F7,
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 511, 512),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP, 5, 0, G_TX_WRAP, 5, 0),
    gsDPSetTileSize(0, 0, 0, 124, 124),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPEndDisplayList(),
};

sImageTableEntry s_genericimage[] = { 
    {_image2136_ID, 0x36, 0x36, 3, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_impactimages[] = { 
    {_image2168_ID, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2169_ID, 0x40, 0x20, 7, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2170_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    { _image206_ID, 0x40, 0x20, 7, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2168_ID, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2168_ID, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2168_ID, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2171_ID, 0x20, 0x20, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2172_ID, 0x20, 0x20, 0, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image1475_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2173_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image1476_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2174_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2175_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image1478_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image1479_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2170_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2168_ID, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2168_ID, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2168_ID, 0x30, 0x30, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_explosion_smokeimages[] = { 
    {_image2176_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2177_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2178_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2179_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2180_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2181_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_scattered_explosions[] = { 
    {_image2182_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2183_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2184_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2185_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2186_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_flareimage1[] = { 
    {_image2229_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_flareimage2[] = { 
    {_image2230_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_flareimage3[] = { 
    {_image2128_ID, 0x10, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_flareimage4[] = { 
    {_image2135_ID, 0x10, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_flareimage5[] = { 
    {_image2134_ID, 0x20, 0x20, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_ammo9mmimage[] = { 
    {_image2231_ID, 5, 0xC, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_rifleammoimage[] = { 
    {_image2232_ID, 5, 0x1C, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_shotgunammoimage[] = { 
    {_image2167_ID, 6, 0x14, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_knifeammoimage[] = { 
    {_image2166_ID, 6, 0x18, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_glammoimage[] = { 
    {_image2165_ID, 8, 0x15, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_CLAMP, 0}
};

sImageTableEntry s_rocketammoimage[] = { 
    {_image2161_ID, 7, 0x16, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_genericmineammoimage[] = { 
    {_image2162_ID, 0xE, 0xE, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_grenadeammoimage[] = { 
    {_image2163_ID, 0xE, 0x12, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_magnumammoimage[] = { 
    {_image2164_ID, 5, 0xF, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_goldengunammoimage[] = { 
    {_image2233_ID, 5, 0xC, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_remotemineammoimage[] = { 
    {_image2234_ID, 0xE, 0xE, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_timedmineammoimage[] = { 
    {_image2238_ID, 0xE, 0xE, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_proxmineammoimage[] = { 
    {_image2235_ID, 0xE, 0xE, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_tankammoimage[] = { 
    {_image2464_ID, 7, 0x16, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_crosshairimage[] = { 
    {_image2236_ID, 0x20, 0x20, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_betacrosshairimage[] = { 
    {_image2237_ID, 0x20, 0x20, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_glassoverlayimage[] = { 
    {_image658_ID, 0x20, 1, 6, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image654_ID, 0x36, 0x36, 3, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_monitorimages[] = { 
    {_image2187_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2188_ID, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2189_ID, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2190_ID, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2191_ID, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2192_ID, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2193_ID, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2194_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2195_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2196_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2197_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image1185_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2198_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2199_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image1186_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image1187_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2200_ID, 0x10, 0x10, 5, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image582_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image583_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image584_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2201_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2202_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2203_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2204_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image581_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2205_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2206_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2227_ID, 0x40, 0x40, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2223_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2224_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2225_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2226_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2219_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2220_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2221_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2222_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2218_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2207_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2208_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2209_ID, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2210_ID, 0x20, 0x20, 6, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2211_ID, 0x20, 0x20, 6, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2212_ID, 0x20, 0x20, 6, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2213_ID, 0x20, 0x20, 6, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2214_ID, 0x80, 0x30, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_CLAMP, 0},
    {_image2215_ID, 0x10, 0x10, 5, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2216_ID, 0x10, 0x10, 5, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2217_ID, 0x10, 0x10, 5, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image2263_ID, 0x36, 0x36, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image837_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_skywaterimages[] = { 
    {_image2228_ID, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image1508_ID, 0x40, 0x40, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {_image1509_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_mainfolderimages[] = { 
    {IMAGE_COPYICON, 0x20, 0x1C, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_CLAMP, 0},
    {IMAGE_DELICON, 0x20, 0x1C, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_CLAMP, 0},
    {IMAGE_SELECTFILE, 0x7A, 0x12, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_X, 0xF, 0xF, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_CHECK, 0x14, 0x14, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2631_ID, 0x10, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_mpradarimages[] = { 
    {_image200_ID, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_mpcharselimages[] = { 
    {_image2602_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2603_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2604_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2605_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2610_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2611_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2612_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2613_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2614_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2615_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2616_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2617_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2606_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2607_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2608_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2609_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2632_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2633_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2634_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2635_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2636_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2637_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2638_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2639_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2640_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2641_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2642_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2643_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2644_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2645_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2646_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2647_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2648_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2649_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2650_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2651_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2652_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2653_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2654_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2655_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2656_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2657_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2658_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2659_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2660_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2661_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2662_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2663_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2664_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2665_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2666_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2667_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2668_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2669_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2670_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2671_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2682_ID, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2683_ID, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2684_ID, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2685_ID, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2694_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2693_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2691_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2692_ID, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_mpstageselimages[] = { 
    {_image2592_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2582_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2578_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2585_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2580_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2590_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2587_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2596_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2583_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2581_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2584_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2586_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2686_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2687_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2688_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2689_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {_image2695_ID, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

