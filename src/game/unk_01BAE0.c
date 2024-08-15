#include <ultra64.h>
#include <assets/animationtable_data.h>
#include "bondtypes.h"
#include "image.h"
#include "math.h"
#include "objecthandler.h"
#include "ob.h"
#include "chr_b.h"
#include "initanitable.h"
#include "chrobjdata.h"

/*
* Address: 0x7F01BAE0
*/
void sub_GAME_7F01BAE0(struct s_display_list_something *var_s0, s32 arg1)
{
    s16 cosval;
    f32 temp_f20;
    s16 sinval;
    s32 var_s2;

    for (var_s2 = 0; var_s2 <= arg1; var_s2 += 2)
    {
        temp_f20 = ((f32) var_s2 * 3.1415927f) / (f32) arg1;

        sinval = sinf(temp_f20) * 64.0f;
        cosval = cosf(temp_f20) * -64.0f;
        
        var_s0->unk0 = sinval;
        var_s0->unk2 = cosval;
        
        var_s0->unk4 = 0;
        var_s0->unk6 = 0;
        var_s0->unk8 = 0;
        var_s0->unkA = 0;
        var_s0->unkC = 0xff;
        var_s0->unkD = 0xff;
        var_s0->unkE = 0xff;

        
        var_s0->unkC = (s8) (u32) (143.0f - (cosf(temp_f20) * -111.0f));
        var_s0->unkD = (s8) (u32) (143.0f - (cosf(temp_f20) * -111.0f));
        var_s0->unkE = (s8) (u32) (143.0f - (cosf(temp_f20) * -111.0f));
        var_s0->unkF = 0;

        var_s0++;

        if ((var_s2 != 0) && (var_s2 < arg1))
        {
            var_s0->unk0 = -sinval;
            var_s0->unk2 = cosval;
            
            var_s0->unk4 = 0;
            var_s0->unk6 = 0;
            var_s0->unk8 = 0;
            var_s0->unkA = 0;
            var_s0->unkC = 0xff;
            var_s0->unkD = 0xff;
            var_s0->unkE = 0xff;

            var_s0->unkC = (s8) (u32) (143.0f - (cosf(temp_f20) * -111.0f));
            var_s0->unkD = (s8) (u32) (143.0f - (cosf(temp_f20) * -111.0f));
            var_s0->unkE = (s8) (u32) (143.0f - (cosf(temp_f20) * -111.0f));
            var_s0->unkF = 0;
            
            var_s0++;
        }
    }
}


/*
* Address: 0x7F01BFF8
*/
Gfx *sub_GAME_7F01BFF8(Gfx *arg0, Vtx *arg1, s32 arg2)
{
    s8 j;
    
    do
    {
        j = ((arg2 >= 0x11) ? 0x10 : arg2);

        gSPVertex(arg0++, arg1, j, 0);

        arg1 += 14;

        j -= 3;
        
        do
        {
            gSP1Triangle(arg0++, j, j+1, j+2, 0);
        } while (--j >= 0);
        
        arg2 -= 14;        
    } while (arg2 >= 3);
    
    gSPEndDisplayList(arg0++);

    return arg0;
}






