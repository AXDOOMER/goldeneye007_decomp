#include <ultra64.h>
#include <bondtypes.h>
#include "unk_091080.h"
#include "bondview.h"
#include "player_2.h"
#include "gun.h"
#include "math.h"
#include "fr.h"

// bss
//CODE.bss:80079E20
s32 dword_CODE_bss_80079E20;


// data
//D:80037010
s32 D_80037010 = 0;

// 0x80037014
coord3d stanbondx = {0.0f,0.0f,0.0f};

coord3d D_80037020 = {0.0f,0.0f,-1.0f};

//D:8003702C
coord3d D_8003702C = {0.0f,1.0f,0.0f};

//D:80037038
f32 angle_80037038 = 0.0f;
//D:8003703C
f32 D_8003703C = 1.0f;
//D:80037040
f32 D_80037040 = 0.0f;
//D:80037044
f32 angle_80037044 = 0.0f;
//D:80037048
f32 D_80037048 = 1.0f;
//D:8003704C
f32 D_8003704C = 0.0f;

/***
 * NTSC address 0x7F091080.
*/
void sub_GAME_7F091080(s8 arg0, s8 arg1, u16 arg2)
{
    f32 var_f2;
    s32 temp_v0;

    static f32 D_80037050 = 1.0f;
    static u16 buttons_80037054 = 0;

    var_f2 = 1.0f;
    
    if (arg0 < -3)
    {
        arg0 += 3;
    }
    else if (arg0 > 3)
    {
        arg0 -= 3;
    }
    else
    {
        arg0 = 0;
    }
    
    if (arg1 < -3)
    {
        arg1 += 3;
    }
    else if (arg1 > 3)
    {
        arg1 -= 3;
    }
    else
    {
        arg1 = 0;
    }

    if (!(arg2 & 0x30))
    {
        if (arg2 & 0x2000)
        {
            var_f2 /= 5.0f;
        }
        
        temp_v0 = arg2 & ~buttons_80037054;
        
        if (temp_v0 & 0x8000)
        {
            D_80037050 *= 2.0f;
        }
        
        if (temp_v0 & 0x4000)
        {
            D_80037050 *= 0.5f;
        }
        
        stanbondx.f[0] += ((f32) arg1 * D_80037040 * var_f2 * D_80037050);
        stanbondx.f[2] += (-(f32) arg1 * D_8003703C * var_f2 * D_80037050);
        
        if (arg2 & 0x202)
        {
            stanbondx.f[0] -= (20.0f * D_8003703C * var_f2 * D_80037050);
            stanbondx.f[2] -= (20.0f * D_80037040 * var_f2 * D_80037050);
        }
        
        if (arg2 & 0x101)
        {
            stanbondx.f[0] += (20.0f * D_8003703C * var_f2 * D_80037050);
            stanbondx.f[2] += (20.0f * D_80037040 * var_f2 * D_80037050);
        }
        
        angle_80037038 += (f32) arg0 * var_f2 * 0.125f;
        
        if (arg2 & 0x800)
        {
            angle_80037044 -= 2.0f * var_f2;
        }
        
        if (arg2 & 0x400)
        {
            angle_80037044 += 2.0f * var_f2;
        }
        
        if (arg2 & 8)
        {
            stanbondx.f[1] += (20.0f * var_f2 * D_80037050);
        }
        
        if (arg2 & 4)
        {
            stanbondx.f[1] -= (20.0f * var_f2 * D_80037050);
        }
    }

    while (angle_80037038 < 0.0f)
    {
        angle_80037038 += 360.0f;            
    }

    while (angle_80037038 >= 360.0f)
    {
        angle_80037038 -= 360.0f;
    }

    while (angle_80037044 < 0.0f)
    {
        angle_80037044 += 360.0f;
    }

    while (angle_80037044 >= 360.0f)
    {
        angle_80037044 -= 360.0f;            
    }

    D_8003703C = cosf(angle_80037038 * DegToRad(1));
    D_80037040 = sinf(angle_80037038 * DegToRad(1));
    D_80037048 = cosf(angle_80037044 * DegToRad(1));
    D_8003704C = sinf(angle_80037044 * DegToRad(1));
    
    D_80037020.f[1] = (f32) D_8003704C;
    D_80037020.f[0] = (f32) (D_80037048 * D_80037040);
    D_80037020.f[2] = (f32) (-D_80037048 * D_8003703C);
    
    D_8003702C.f[1] = (f32) D_80037048;
    D_8003702C.f[0] = (f32) (-D_8003704C * D_80037040);
    D_8003702C.f[2] = (f32) (D_8003704C * D_8003703C);
    
    buttons_80037054 = arg2;
    
    set_cur_player_fovy(FOV_Y_F);
    
    dword_CODE_bss_80079E20++;
    if (dword_CODE_bss_80079E20 == 1)
    {
        remove_item_in_hand(GUNRIGHT);
        remove_item_in_hand(GUNLEFT);
        
        return;
    }
    
    if (dword_CODE_bss_80079E20 == 4)
    {
        solo_char_load();
    }
}


//D:80037058
f32 D_80037058 = 1.0f;
//D:8003705C
f32 D_8003705C = 1.0f;
//D:80037060
coord3d D_80037060 = {0.0f,0.0f,0.0f};


/*
* Address: 0x7F091580
*/
Gfx * sub_GAME_7F091580(Gfx * arg0) {
    sub_GAME_7F0876C4(&stanbondx, &D_80037020, &D_8003702C);
    return arg0;
}


/*
* Address: 0x7F0915BC
*/
void sub_GAME_7F0915BC(float scale)
{
  float fVar1;
  
  fVar1 = D_80037058 / scale;
  D_80037058 = scale;
  stanbondx.x = stanbondx.x * fVar1;
  stanbondx.y = stanbondx.y * fVar1;
  stanbondx.z = stanbondx.z * fVar1;
  D_8003705C = 1.0f / scale;
}


/*
* Address: 0x7f091618
*/
void handle_debug_intropos(void)
{
    coord3d* pos; //needed to be declared but not used to match
    f32 x;

    bondviewGetCurrentPlayersPosition();  //normally would return a coord3d pos but not here
    x = M_TAU_F -  get_curplay_horizontal_rotation_in_degrees();
    cosf(x);
    sinf(x);
    cosf(x);
    sinf(x);
}


/*
* Address: 0x7f09166c
*/
void debugSetWorldPos(void)
{
    sqrtf((stanbondx.x - D_80037060.x) * (stanbondx.x - D_80037060.x) +
          (stanbondx.y - D_80037060.y) * (stanbondx.y - D_80037060.y) +
          (stanbondx.z - D_80037060.z) * (stanbondx.z - D_80037060.z));

    D_80037060.x = stanbondx.x;
    D_80037060.y = stanbondx.y;
    D_80037060.z = stanbondx.z;
}

/*
* Address: 0x7F0916F4
*/
void sub_GAME_7F0916F4(void)
{
    coord3d *pos;
    
    pos = bondviewGetCurrentPlayersPosition();
    stanbondx.x = pos->x;
    stanbondx.y = pos->y;
    stanbondx.z = pos->z;
    dword_CODE_bss_80079E20 = 0;
}



