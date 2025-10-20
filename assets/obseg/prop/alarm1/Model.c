/*
source object data:
# Created by SubDrag and the GoldenEye Setup Editor V4.3
mtllib Object0000.mtl
#joint 0
#jointposition 962.500000 2015.016724 -36.117146
g Room02_primary
usemtl m0
vt 0.199219 0.151367 0.0
vt 0.818359 0.151367 0.0
vt 0.818359 0.873047 0.0
v 875.500000 1808.016724 -0.117146
#joint 0
#vjoint 1
#vcolor 254.000000 254.000000 254.000000 255.000000
v 1050.500000 1808.016724 -0.117146
#joint 0
#vjoint 2
v 1050.500000 2100.016602 -0.117146
#joint 0
#vjoint 3
f 1/1 2/2 3/3
#fvcolorindex 1 1 1 
vt 0.199219 0.151367 0.0
vt 0.818359 0.873047 0.0
vt 0.199219 0.873047 0.0
v 875.500000 2100.016602 -0.117146
#joint 0
#vjoint 4
f 1/4 3/5 4/6
#fvcolorindex 1 1 1 
vt 0.818359 0.151367 0.0
vt 1.024414 0.007812 0.0
vt 1.024414 1.017578 0.0
v 1108.500000 1750.016724 -72.117142
#joint 0
#vjoint 5
v 1108.500000 2158.016602 -72.117142
#joint 0
#vjoint 6
f 2/7 5/8 6/9
#fvcolorindex 1 1 1 
vt 0.818359 0.151367 0.0
vt 1.024414 1.017578 0.0
vt 0.818359 0.873047 0.0
f 2/10 6/11 3/12
#fvcolorindex 1 1 1 
vt 0.199219 0.151367 0.0
vt -0.006836 0.007812 0.0
vt 1.024414 0.007812 0.0
v 816.500000 1750.016724 -72.117142
#joint 0
#vjoint 7
f 1/13 7/14 5/15
#fvcolorindex 1 1 1 
vt 0.199219 0.151367 0.0
vt 1.024414 0.007812 0.0
vt 0.818359 0.151367 0.0
f 1/16 5/17 2/18
#fvcolorindex 1 1 1 
vt 0.199219 0.873047 0.0
vt -0.006836 1.017578 0.0
vt -0.006836 0.007812 0.0
v 816.500000 2158.016602 -72.117142
#joint 0
#vjoint 8
f 4/19 8/20 7/21
#fvcolorindex 1 1 1 
vt 0.199219 0.873047 0.0
vt -0.006836 0.007812 0.0
vt 0.199219 0.151367 0.0
f 4/22 7/23 1/24
#fvcolorindex 1 1 1 
vt 0.818359 0.873047 0.0
vt 1.024414 1.017578 0.0
vt -0.006836 1.017578 0.0
f 3/25 6/26 8/27
#fvcolorindex 1 1 1 
vt 0.818359 0.873047 0.0
vt -0.006836 1.017578 0.0
vt 0.199219 0.873047 0.0
f 3/28 8/29 4/30
#fvcolorindex 1 1 1 
g Room02_secondary
usemtl m1
vt 2.000000 0.000000 0.0
vt 2.000000 1.000000 0.0
vt 0.000000 1.000000 0.0
v 1108.500000 2128.016602 -34.117146
#joint 0
#vjoint 9
v 1108.500000 2280.016602 -34.117146
#joint 0
#vjoint 10
v 816.500000 2280.016602 -34.117146
#joint 0
#vjoint 11
f 9/31 10/32 11/33
#fvcolorindex 1 1 1 
vt 2.000000 0.000000 0.0
vt 0.000000 1.000000 0.0
vt 0.000000 0.000000 0.0
v 816.500000 2128.016602 -34.117146
#joint 0
#vjoint 12
f 9/34 11/35 12/36
#fvcolorindex 1 1 1 

*/
/*
Object0000.mtl
newmtl m0
Ka 0 0 0
illum 0
Ns 64
d 1.000000
map_Kd tempImgEd001D.bmp

newmtl m1
Ka 0 0 0
illum 0
Ns 64
d 1.000000
map_Kd tempImgEd001F.bmp


*/

#include <bondtypes.h>
#include "assets/image_externs.h"

#define TEXTURECOUNT 2

#define VERTEXGROUPCOUNT0 12
#define COLLISIONVERTEXCOUNT0 12

extern ModelRoData_GroupRecord GroupRecord_0x060;
extern ModelRoData_BoundingBoxRecord BoundingBoxRecord_0x07c;
extern Vertex Vertex_ARRAY_0x098[VERTEXGROUPCOUNT0];
extern Vertex Collision_Vertex_ARRAY_0x158[COLLISIONVERTEXCOUNT0];
extern s16 POINT_USAGE_ARRAY_0x218[VERTEXGROUPCOUNT0];
extern ModelRoData_DisplayList_CollisionRecord DLCollisionRecord_0x230[];
extern Gfx GFX_ARRAY_PRIMARY_0x250[];
extern Gfx GFX_ARRAY_SECONDARY_0x2B0[];

//base address is 0x05000000
ModelFileTextures proptextures[TEXTURECOUNT] = 
{
    {IMAGE_BUZZERSWITCH, 32, 32, 0x06, 0x0, 0x02, 0x0, 0x0},
    {IMAGE_BELL, 32, 32, 0x06, 0x0, 0x02, 0x0, 0x0}
};

                        //  {                        opcode,                     data,           parent,  next,  prev,            child}
ModelNode ModelNode_0x018 = {        MODELNODE_OPCODE_GROUP,       &GroupRecord_0x060,             NULL,  NULL,  NULL, &ModelNode_0x030};
ModelNode ModelNode_0x030 = {         MODELNODE_OPCODE_BBOX, &BoundingBoxRecord_0x07c, &ModelNode_0x018,  NULL,  NULL, &ModelNode_0x048};
ModelNode ModelNode_0x048 = {  MODELNODE_OPCODE_DLCOLLISION, &DLCollisionRecord_0x230, &ModelNode_0x030,  NULL,  NULL,             NULL};

ModelRoData_GroupRecord GroupRecord_0x060 = 
{
    {962.5, 2015.0167, -36.117146}, //origin {x,y,z}
    0x0, //JointID
    0x0, //MatrixID0
    0xFFFF, //MatrixID1
    0xFFFF, //MatrixID2
    NULL, //ChildGroup
    304.6402 //BoundingVolumeRadius
};

ModelRoData_BoundingBoxRecord BoundingBoxRecord_0x07c = 
{
    0x1, 
    {-146.0, 146.0, -265.0, 265.0, -36.0, 36.0}
};

Vertex Vertex_ARRAY_0x098[VERTEXGROUPCOUNT0] = 
{ //{ {   x,    y,   z}, index,     s,     t, {   r,    g,    b,    a} }
    { { -87, -207,  36},   0x0,  0xCC,  0x9B, {0xFE, 0xFE, 0xFE, 0xFF} },
    { {  88, -207,  36},   0x0, 0x346,  0x9B, {0xFE, 0xFE, 0xFE, 0xFF} },
    { {  88,   55,  36},   0x0, 0x346, 0x37E, {0xFE, 0xFE, 0xFE, 0xFF} },
    { { -87,   55,  36},   0x0,  0xCC, 0x37E, {0xFE, 0xFE, 0xFE, 0xFF} },
    { { 146, -265, -36},   0x0, 0x419,   0x8, {0xFE, 0xFE, 0xFE, 0xFF} },
    { { 146,  143, -36},   0x0, 0x419, 0x412, {0xFE, 0xFE, 0xFE, 0xFF} },
    { {-146, -265, -36},   0x0,    -7,   0x8, {0xFE, 0xFE, 0xFE, 0xFF} },
    { {-146,  143, -36},   0x0,    -7, 0x412, {0xFE, 0xFE, 0xFE, 0xFF} },
    { { 146,  113,   2},   0x0, 0x800,   0x0, {0xFE, 0xFE, 0xFE, 0xFF} },
    { { 146,  265,   2},   0x0, 0x800, 0x400, {0xFE, 0xFE, 0xFE, 0xFF} },
    { {-146,  265,   2},   0x0,   0x0, 0x400, {0xFE, 0xFE, 0xFE, 0xFF} },
    { {-146,  113,   2},   0x0,   0x0,   0x0, {0xFE, 0xFE, 0xFE, 0xFF} },
};

Vertex Collision_Vertex_ARRAY_0x158[COLLISIONVERTEXCOUNT0] = 
{ //{ {   x,    y,   z}, index,     s,     t, {   r,    g,    b,    a} }
    { { -87, -207,  36},   0x0,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { {  88, -207,  36},   0x1,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { {  88,   85,  36},   0x2,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { { -87,   85,  36},   0x3,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { { 146, -265, -36},   0x4,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { { 146,  143, -36},   0x5,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { {-146, -265, -36},   0x6,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { {-146,  143, -36},   0x7,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { { 146,  113,   2},   0x8,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { { 146,  265,   2},   0x9,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { {-146,  265,   2},   0xA,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
    { {-146,  113,   2},   0xB,   0x0,   0x0, {0xFF, 0xFF,  0x0,  0x0} },
};

s16 POINT_USAGE_ARRAY_0x218[VERTEXGROUPCOUNT0] = 
{
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
};

ModelRoData_DisplayList_CollisionRecord DLCollisionRecord_0x230 = 
{
    GFX_ARRAY_PRIMARY_0x250, //primary
    GFX_ARRAY_SECONDARY_0x2B0, //secondary
    Vertex_ARRAY_0x098, VERTEXGROUPCOUNT0, //vertices,vcount 
    COLLISIONVERTEXCOUNT0, Collision_Vertex_ARRAY_0x158,  //ncolvtx,collision vertices
    POINT_USAGE_ARRAY_0x218, //point usage
    0x4, 0x0, //type, index
    0x0 //baseaddr
};

Gfx GFX_ARRAY_PRIMARY_0x250[] = 
{
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPTexture(0xFFFF, 0xFFFF, 6, 0, TRUE),
    gsDPLoadSync(),
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPTexture(0xFFFF, 0xFFFF, 6, 0, TRUE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

Gfx GFX_ARRAY_SECONDARY_0x2B0[] =
{
    gsDPLoadSync(),
    gsDPSetTextureLOD(G_TL_LOD),
    gsSPTexture(0xFFFF, 0xFFFF, 6, 0, TRUE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

