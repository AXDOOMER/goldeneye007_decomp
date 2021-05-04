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
    {IMAGE_MONITOR_BOND, 0x20, 0x20, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_LOCATION, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_BEGINARMING, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_TARGET, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_SEVERNAYA, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_BREAKTARGET, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_AIMER, 0x80, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_EARTH, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_DESKTOPBANG, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_HEATMAP, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_3DMATH, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_DESKTOPBARS, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_2DMATH, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_SATELLITE, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_DESKTOP, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_MONITOR_DESKTOPSTAGGERED, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0},
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
    {IMAGE_CLOUDS_GRAYSCALE, 0x40, 0x40, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_WATER_GRAYSCALE, 0x40, 0x40, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0},
    {IMAGE_WATER_BLUE, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_mainfolderimages[] = { 
    {IMAGE_COPYICON, 0x20, 0x1C, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_CLAMP, 0},
    {IMAGE_DELICON, 0x20, 0x1C, 0, G_IM_FMT_RGBA, G_IM_SIZ_32b, G_TX_WRAP, G_TX_CLAMP, 0},
    {IMAGE_SELECTFILE, 0x7A, 0x12, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_X, 0xF, 0xF, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_CHECK, 0x14, 0x14, 0, G_IM_FMT_IA, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_DOT, 0x10, 0x10, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_mpradarimages[] = { 
    {IMAGE_RUSTYDRUM_END, 0x20, 0x20, 6, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TX_WRAP, G_TX_WRAP, 0}
};

sImageTableEntry s_mpcharselimages[] = { 
    {IMAGE_BROSNAN_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BROSNAN_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BROSNAN_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BROSNAN_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MOORE_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MOORE_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MOORE_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MOORE_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_DALTON_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_DALTON_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_DALTON_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_DALTON_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_CONNERY_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_CONNERY_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_CONNERY_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_CONNERY_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BORIS_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BORIS_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BORIS_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BORIS_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_OURUMOV_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_OURUMOV_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_OURUMOV_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_OURUMOV_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_TREVELYAN_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_TREVELYAN_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_TREVELYAN_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_TREVELYAN_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_VALENTIN_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_VALENTIN_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_VALENTIN_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_VALENTIN_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_XENIA_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_XENIA_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_XENIA_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_XENIA_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_NATALYA_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_NATALYA_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_NATALYA_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_NATALYA_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BARON_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BARON_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BARON_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_BARON_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_JAWS_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_JAWS_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_JAWS_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_JAWS_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MAYDAY_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MAYDAY_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MAYDAY_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MAYDAY_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_ODDJOB_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_ODDJOB_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_ODDJOB_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_ODDJOB_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_RANDOM_UL, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_RANDOM_UR, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_RANDOM_LL, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_RANDOM_LR, 0x41, 0x43, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MISHKIN_UL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MISHKIN_UR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MISHKIN_LL, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MISHKIN_LR, 0x41, 0x41, 7, G_IM_FMT_I, G_IM_SIZ_4b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

sImageTableEntry s_mpstageselimages[] = { 
    {IMAGE_MP_BUNKER2, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_CAVERNS, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_ARCHIVES, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_DAM, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_FACILITY, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_RUNWAY, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_FRIGATE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_STATUE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_CRADLE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_AZTEC, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_EGYPT, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_DEPOT, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_TEMPLE, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_BASEMENT, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_COMPLEX, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_CAVES, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0},
    {IMAGE_MP_RANDOM, 0x44, 0x2C, 0, G_IM_FMT_I, G_IM_SIZ_8b, G_TX_CLAMP, G_TX_CLAMP, 0}
};

