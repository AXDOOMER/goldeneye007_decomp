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
s32 D_80037010 = 0; //unused

// 0x80037014
coord3d stanbondpos = {0.0f,0.0f,0.0f};

coord3d stanbondforward = {0.0f,0.0f,-1.0f};

//D:8003702C
coord3d stanbondup = {0.0f,1.0f,0.0f};

//D:80037038
f32 stanbondhorzangle = 0.0f;
//D:8003703C
f32 stanbondhorzcos = 1.0f;
//D:80037040
f32 stanbondhorzsin = 0.0f;
//D:80037044
f32 stanbondvertangle = 0.0f;
//D:80037048
f32 stanbondvertcos = 1.0f;
//D:8003704C
f32 stanbondvertsin = 0.0f;

/***
 * NTSC address 0x7F091080.
*/
void debugMoveView(s8 joyX, s8 joyY, u16 joyBtns)
{
    f32 speedModifier;
    s32 temp_v0;

    static f32 movementSpeed = 1.0f;
    static u16 previousButtons = 0;

    speedModifier = 1.0f;
    
    if (joyX < -3)
    {
        joyX += 3;
    }
    else if (joyX > 3)
    {
        joyX -= 3;
    }
    else
    {
        joyX = 0;
    }
    
    if (joyY < -3)
    {
        joyY += 3;
    }
    else if (joyY > 3)
    {
        joyY -= 3;
    }
    else
    {
        joyY = 0;
    }

    if (!(joyBtns & (R_TRIG|L_TRIG)))
    {
        if (joyBtns & Z_TRIG)
        {
            speedModifier /= 5.0f;
        }
        
        temp_v0 = joyBtns & ~previousButtons;
        
        if (temp_v0 & A_BUTTON)
        {
            movementSpeed *= 2.0f;
        }
        
        if (temp_v0 & B_BUTTON)
        {
            movementSpeed *= 0.5f;
        }
        
        stanbondpos.f[0] += ((f32) joyY * stanbondhorzsin * speedModifier * movementSpeed);
        stanbondpos.f[2] += (-(f32) joyY * stanbondhorzcos * speedModifier * movementSpeed);
        
        if (joyBtns & (L_CBUTTONS|L_JPAD))
        {
            stanbondpos.f[0] -= (20.0f * stanbondhorzcos * speedModifier * movementSpeed);
            stanbondpos.f[2] -= (20.0f * stanbondhorzsin * speedModifier * movementSpeed);
        }
        
        if (joyBtns & (R_CBUTTONS|R_JPAD))
        {
            stanbondpos.f[0] += (20.0f * stanbondhorzcos * speedModifier * movementSpeed);
            stanbondpos.f[2] += (20.0f * stanbondhorzsin * speedModifier * movementSpeed);
        }
        
        stanbondhorzangle += (f32) joyX * speedModifier * 0.125f;
        
        if (joyBtns & U_JPAD)
        {
            stanbondvertangle -= 2.0f * speedModifier;
        }
        
        if (joyBtns & D_JPAD)
        {
            stanbondvertangle += 2.0f * speedModifier;
        }
        
        if (joyBtns & U_CBUTTONS)
        {
            stanbondpos.f[1] += (20.0f * speedModifier * movementSpeed);
        }
        
        if (joyBtns & D_CBUTTONS)
        {
            stanbondpos.f[1] -= (20.0f * speedModifier * movementSpeed);
        }
    }

    while (stanbondhorzangle < 0.0f)
    {
        stanbondhorzangle += 360.0f;            
    }

    while (stanbondhorzangle >= 360.0f)
    {
        stanbondhorzangle -= 360.0f;
    }

    while (stanbondvertangle < 0.0f)
    {
        stanbondvertangle += 360.0f;
    }

    while (stanbondvertangle >= 360.0f)
    {
        stanbondvertangle -= 360.0f;            
    }

    stanbondhorzcos = cosf(stanbondhorzangle * DegToRad(1));
    stanbondhorzsin = sinf(stanbondhorzangle * DegToRad(1));
    stanbondvertcos = cosf(stanbondvertangle * DegToRad(1));
    stanbondvertsin = sinf(stanbondvertangle * DegToRad(1));
    
    stanbondforward.f[1] = (f32) stanbondvertsin;
    stanbondforward.f[0] = (f32) (stanbondvertcos * stanbondhorzsin);
    stanbondforward.f[2] = (f32) (-stanbondvertcos * stanbondhorzcos);
    
    stanbondup.f[1] = (f32) stanbondvertcos;
    stanbondup.f[0] = (f32) (-stanbondvertsin * stanbondhorzsin);
    stanbondup.f[2] = (f32) (stanbondvertsin * stanbondhorzcos);
    
    previousButtons = joyBtns;
    
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
f32 stanbondScale = 1.0f;
//D:8003705C
f32 stanbondInverseScale = 1.0f;
//D:80037060
coord3d stanbondPrevPos = {0.0f,0.0f,0.0f};


/*
* Address: 0x7F091580
*/
Gfx * sub_GAME_7F091580(Gfx * arg0) {
    sub_GAME_7F0876C4(&stanbondpos, &stanbondforward, &stanbondup);
    return arg0;
}


/*
* Address: 0x7F0915BC
*/
void sub_GAME_7F0915BC(float scale)
{
  float scaleFactor;
  
  scaleFactor = stanbondScale / scale;
  stanbondScale = scale;
  stanbondpos.x = stanbondpos.x * scaleFactor;
  stanbondpos.y = stanbondpos.y * scaleFactor;
  stanbondpos.z = stanbondpos.z * scaleFactor;
  stanbondInverseScale = 1.0f / scale;
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
    sqrtf((stanbondpos.x - stanbondPrevPos.x) * (stanbondpos.x - stanbondPrevPos.x) +
          (stanbondpos.y - stanbondPrevPos.y) * (stanbondpos.y - stanbondPrevPos.y) +
          (stanbondpos.z - stanbondPrevPos.z) * (stanbondpos.z - stanbondPrevPos.z));

    stanbondPrevPos.x = stanbondpos.x;
    stanbondPrevPos.y = stanbondpos.y;
    stanbondPrevPos.z = stanbondpos.z;
}

/*
* Address: 0x7F0916F4
*/
void resetStanbondPosToPlayerPos(void)
{
    coord3d *pos;
    
    pos = bondviewGetCurrentPlayersPosition();
    stanbondpos.x = pos->x;
    stanbondpos.y = pos->y;
    stanbondpos.z = pos->z;
    dword_CODE_bss_80079E20 = 0;
}



