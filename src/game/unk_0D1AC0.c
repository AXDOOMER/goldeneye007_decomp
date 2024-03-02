#include <ultra64.h>
#include "unk_0A1DA0.h"

// data
f32 D_8004EAF0 = 0.0f;
f32 D_8004EAF4 = 0.0f;

Gfx *sub_GAME_7F0D1BD0(Gfx *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx *sub_GAME_7F0D1E98(Gfx *arg0, s32 arg1, s32 arg2, s32 arg3);



Gfx * sub_GAME_7F0D1AC0(Gfx *DL)
{
    D_8004EAF0 = D_8004EAF4 = 0.0f;
    
    gDPSetTextureFilter(DL++, G_TF_POINT);
    gDPSetColorDither(DL++, G_CD_DISABLE);
    gSPClearGeometryMode(DL++, G_ZBUFFER );
    gDPPipeSync(DL++);
    gDPSetTexturePersp(DL++, G_TP_NONE);
    gDPSetCycleType(DL++, G_CYC_FILL);
    gDPSetRenderMode(DL++, G_RM_PASS, G_RM_OPA_SURF2);
    gDPPipelineMode(DL++, G_PM_1PRIMITIVE);
    return DL++;
}





Gfx *sub_GAME_7F0D1B94(Gfx *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    return sub_GAME_7F0D1BD0(arg0, arg1, arg2, arg3, arg4, 2, 1);
}





Gfx *sub_GAME_7F0D1BD0(Gfx *gdl, f32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    f32 temp_f2;
    s32 start;
    s32 upper;
    s32 var_t0;
    s32 var_v0;
    s32 var_t1;
    s32 temp_t3;
    s32 z1;
    s32 z2;
    
    if (arg1 > 0)
    {
        start = (s32) (D_8004EAF4 / 10.0f);
        
        temp_f2 = D_8004EAF4 + arg1;
        upper = (s32) ((temp_f2) / 10.0f);
        
        z1 = (s32) ((D_8004EAF4 * 219.0f) / 10.0f);
        z2 = (s32) (((temp_f2) * 219.0f) / 10.0f);
        
        gDPSetFillColor(gdl++, (GPACK_RGBA5551(arg2, arg3, arg4, 1) << 16) | GPACK_RGBA5551(arg2, arg3, arg4, 1));
                
        for (var_v0 = start; (upper >= var_v0) && (var_v0 < 3); var_v0++)
        {
            var_t0 = (var_v0 * 0xDB);
            var_t1 = (z1 - var_t0) + 0x32;
            temp_t3 = (z2 - var_t0) + 0x32;
            
            if (var_t1 < 0x32)
            {
                var_t1 = 0x32;
            }
            
            if (temp_t3 >= 0x10E)
            {
                temp_t3 = 0x10D;
            }

            if (temp_t3 >= var_t1)
            {
                gDPFillRectangle(gdl++, var_t1, (arg6 + (var_v0 * 7) + 0x12), temp_t3, (arg5 + arg6 + (var_v0 * 7) + 0x11));
            }

            var_t1 -= 0xDB;
        }

        D_8004EAF4 += arg1;        
    }
    
    return gdl;
}





void sub_GAME_7F0D1DCC(f32 arg0) {
    if (0.0f < arg0) {
        D_8004EAF4 = (f32) (D_8004EAF4 + arg0);
        return;
    }
}




/**
 * Unreferenced.
*/
Gfx *sub_GAME_7F0D1DFC(Gfx *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    return sub_GAME_7F0D1B94(arg0, (D_8004EAF0 + arg1) - D_8004EAF4, arg2, arg3, arg4);
}



/**
 * Unreferenced.
*/
Gfx *sub_GAME_7F0D1E44(Gfx *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    return sub_GAME_7F0D1BD0(arg0, (D_8004EAF0 + arg1) - D_8004EAF4, arg2, arg3, arg4, arg5, arg6);
}




Gfx *sub_GAME_7F0D1E98(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3)
{
    s32 temp_f8;
    s32 i;
    s32 j;
    
    temp_f8 = (s32) (D_8004EAF4 / 10.0f);

    gDPSetFillColor(gdl++, (GPACK_RGBA5551(arg1, arg2, arg3, 1) << 16) | GPACK_RGBA5551(arg1, arg2, arg3, 1));

    for (j = 0; temp_f8 >= j && j < 3; j++)
    {
        for (i = 0; i < 11; i++)
        {
            gDPFillRectangle(
                gdl++,
                (s32) (((f32) i * 219.0f) / 10.0f) + 50,
                j*7 + 0x12,
                (s32) (((f32) i * 219.0f) / 10.0f) + 50,
                j*7 + 0x15);
        }
    }
    
    return gdl;
}





void sub_GAME_7F0D2320(void)
{
    s32 t;

    t = (s32) (D_8004EAF4 / 10.0f);
    t = (t * 10) + 10;
    
    D_8004EAF4 = t;
    D_8004EAF0 = D_8004EAF4;
}




