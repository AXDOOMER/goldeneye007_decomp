#include <ultra64.h>
#include "player.h"
#include "bg.h"
#include "unk_0BC530.h"
#include "matrixmath.h"

#ifdef VERSION_EU
#define AMT300 100
#else
#define AMT300 300 
#endif

// bss
/**
 * EU .bss 8007DC90
*/
u8 dword_CODE_bss_80083320[AMT300];

s32 dword_CODE_bss_80083450[AMT300];
s32 dword_CODE_bss_80083900[AMT300];
Mtx mtx_array_bss_80083DB0[AMT300];


/*
* Address: 0x7F0BC530
*/
void sub_GAME_7F0BC530(void) 
{
    int i;
      
    for (i=0; i<getPlayerCount(); i++)
    {
        g_playerPointers[i]->field_108C = -1;
    }

    for (i=0; i<AMT300; i++)
    {
      dword_CODE_bss_80083450[i] = -1;
      dword_CODE_bss_80083320[i] = 2;
      
      dword_CODE_bss_80083900[i] = -1;
      
      
    }

    for (i=0; i<getMaxNumRooms(); ++i)
    {
        array_room_info[i].field_36 = -1;
    }
}


/*
* Address: 0x7F0BC624
*/
void sub_GAME_7F0BC624(s32 param_1) {
  g_CurrentPlayer->field_108C = param_1;
}


/*
* Address: 0x7F0BC634
*/
void sub_GAME_7F0BC634(int param_1,int param_2)
{
    array_room_info[param_2].field_36 = param_1;
    dword_CODE_bss_80083450[param_1] = param_2;
}


/*
* Address: 0x7F0BC660
*/
void sub_GAME_7F0BC660(int param_1,int param_2)
{
    array_room_info[param_2].field_36 = -1;
    dword_CODE_bss_80083450[param_1] = -1;
}


/*
* Address: 0x7F0BC690
*/
void sub_GAME_7F0BC690(int index)
{
    if (dword_CODE_bss_80083450[index] != -1) {
        sub_GAME_7F0BC660(index,dword_CODE_bss_80083450[index]);
    }
    dword_CODE_bss_80083320[index] = 2;
    dword_CODE_bss_80083900[index] = -1;
}


/*
* Address: 0x7F0BC6F0
*/
s32 sub_GAME_7F0BC6F0(void)
{
    s32 i;

    for (i = 0; i<AMT300; i++)
    {
        if (((s32) dword_CODE_bss_80083320[i] >= 2) && (dword_CODE_bss_80083900[i] == -1))
        {
            return i;
        }
    }
    return 0;
}


/**
 * NTSC address 0x7F0BC7D4.
*/
void sub_GAME_7F0BC7D4(void)
{
    s32 i;

    for(i = 0; i<AMT300; ++i)
    {
        if (dword_CODE_bss_80083900[i] > -1)
        {
            dword_CODE_bss_80083320[i]++;
            
            if (dword_CODE_bss_80083320[i] >= 2)
            {
                sub_GAME_7F0BC690(i);
            }            
        } 
    }
}




/**
 * NTSC address 0x7F0BC85C.
*/
s32 sub_GAME_7F0BC85C(s32 arg0)
{
    s32 var_s0;
    Mtxf sp2C;

    var_s0 = array_room_info[arg0].field_36;
    
    if ((var_s0 == -1) || (g_CurrentPlayer->field_108C != dword_CODE_bss_80083900[var_s0]))
    {
        if (var_s0 != -1)
        {
            sub_GAME_7F0BC660(var_s0, arg0);
        }

        var_s0 = sub_GAME_7F0BC6F0();
        sub_GAME_7F0BC634(var_s0, arg0);
        
        dword_CODE_bss_80083320[var_s0] = 0;
    }
    else
    {
        dword_CODE_bss_80083320[var_s0] = 0;
        
        return var_s0;
    }

    dword_CODE_bss_80083900[var_s0] = g_CurrentPlayer->field_108C;

    matrix_4x4_set_identity(&sp2C);
    
    sp2C.m[0][0] = room_data_float2;
    sp2C.m[1][1] = room_data_float2;
    sp2C.m[2][2] = room_data_float2;
    
    sp2C.m[3][0] = (ptr_bgdata_room_fileposition_list[arg0].pos.f[0] * room_data_float2) - g_CurrentPlayer->current_model_pos.f[0];
    sp2C.m[3][1] = (ptr_bgdata_room_fileposition_list[arg0].pos.f[1] * room_data_float2) - g_CurrentPlayer->current_model_pos.f[1];
    sp2C.m[3][2] = (ptr_bgdata_room_fileposition_list[arg0].pos.f[2] * room_data_float2) - g_CurrentPlayer->current_model_pos.f[2];
    
    matrix_4x4_f32_to_s32(&sp2C, &mtx_array_bss_80083DB0[var_s0]);
    
    return var_s0;
}



/*
* Address: 0x7F0BC9C4
*/
Gfx * sub_GAME_7F0BC9C4(Gfx *DL,int index)
{
    s32 i;
    
    i = sub_GAME_7F0BC85C(index);
    gSPMatrix(DL++, &mtx_array_bss_80083DB0[i], G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
    return DL;
}


/*
* Address: 0x7f0bca14
*/
struct coord3d* getRoomIndexPOS(s32 index)
{
    return &ptr_bgdata_room_fileposition_list[index].pos;
}

/*
* Address: 0x7F0BCA34
*/
void sub_GAME_7F0BCA34(s32 index, coord3d *param_2)
{
    param_2->x = ptr_bgdata_room_fileposition_list[index].pos.x * room_data_float2;
    param_2->y = ptr_bgdata_room_fileposition_list[index].pos.y * room_data_float2;
    param_2->z = ptr_bgdata_room_fileposition_list[index].pos.z * room_data_float2;
}

