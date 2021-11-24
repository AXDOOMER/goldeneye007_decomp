#include "ultra64.h"

Gfx fontDL_0x000[] = { 
    0xB6000000, 0x001F3204, //gsDPClearGeometryMode(G_SHADE |  G_SHADING_SMOOTH |  G_CULL_FRONT |  G_CULL_BACK |  G_FOG |  G_LIGHTING |  frmTexture_GEN |  frmTexture_GEN_LINEAR );
    0xBB000000, 0x00000000, //gsSPTexture(0x0000, 0x0000, 1, 0, 0),
    0xB7000000, 0x00000204, //gsDPSetGeometryMode(G_SHADE |  G_SHADING_SMOOTH ),
    gsSPEndDisplayList(),
    };

Gfx fontDL_0x020[] = { 
    0xB6000000, 0x001F3204, //gsDPClearGeometryMode(G_SHADE |  G_SHADING_SMOOTH |  G_CULL_FRONT |  G_CULL_BACK |  G_FOG |  G_LIGHTING |  frmTexture_GEN |  frmTexture_GEN_LINEAR ),
    0xBB000000, 0x00000000, //gsSPTexture(0x0000, 0x0000, 1, 0, 0),
    0xB7000000, 0x00000205, //gsDPSetGeometryMode(G_ZBUFFER |  G_SHADE |  G_SHADING_SMOOTH ),
    gsSPEndDisplayList(),
};

Gfx fontDL_0x040[] = { 
    gsDPSetCycleType(G_CYC_1CYCLE),
    0xBA001701, 0x00800000,//gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineLERP(0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE,  0, 0, 0, SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare( G_AC_NONE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_MAGICSQ),
    0xE7000000, 0x00000000, //gsDPLoadSync(),
    gsSPEndDisplayList(),
};
