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


void sub_GAME_7F0BC624(s32 param_1) {
  g_CurrentPlayer->field_108C = param_1;
}


void sub_GAME_7F0BC634(int param_1,int param_2)
{
    array_room_info[param_2].field_36 = param_1;
    dword_CODE_bss_80083450[param_1] = param_2;
}


void sub_GAME_7F0BC660(int param_1,int param_2)
{
    array_room_info[param_2].field_36 = -1;
    dword_CODE_bss_80083450[param_1] = -1;
}


void sub_GAME_7F0BC690(int index)
{
    if (dword_CODE_bss_80083450[index] != -1) {
        sub_GAME_7F0BC660(index,dword_CODE_bss_80083450[index]);
    }
    dword_CODE_bss_80083320[index] = 2;
    dword_CODE_bss_80083900[index] = -1;
}


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



#ifdef NONMATCHING
void sub_GAME_7F0BC7D4(void)
{
    s32 i;

    for(i = 0; i<AMT300; ++i)
    {
        if (dword_CODE_bss_80083900[i] > -1)
        {
            //needed to get close, still wrong temp usage, starts with t8 instead of t7
            dword_CODE_bss_80083320[i] = dword_CODE_bss_80083320[i];
            if ((dword_CODE_bss_80083320[i]+1 & 0xFF) > 1)
            {
                sub_GAME_7F0BC690(i);
            }
            
        } 
    }
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC7D4
/* 0F1304 7F0BC7D4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F1308 7F0BC7D8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F130C 7F0BC7DC AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1310 7F0BC7E0 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F1314 7F0BC7E4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1318 7F0BC7E8 3C118008 */  lui   $s1, %hi(dword_CODE_bss_80083900)
/* 0F131C 7F0BC7EC 3C128008 */  lui   $s2, %hi(dword_CODE_bss_80083320)
/* 0F1320 7F0BC7F0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F1324 7F0BC7F4 26523320 */  addiu $s2, %lo(dword_CODE_bss_80083320) # addiu $s2, $s2, 0x3320
/* 0F1328 7F0BC7F8 26313900 */  addiu $s1, %lo(dword_CODE_bss_80083900) # addiu $s1, $s1, 0x3900
/* 0F132C 7F0BC7FC 00008025 */  move  $s0, $zero
/* 0F1330 7F0BC800 2413012C */  li    $s3, 300
.L7F0BC804:
/* 0F1334 7F0BC804 8E2E0000 */  lw    $t6, ($s1)
/* 0F1338 7F0BC808 02501021 */  addu  $v0, $s2, $s0
/* 0F133C 7F0BC80C 05C2000A */  bltzl $t6, .L7F0BC838
/* 0F1340 7F0BC810 26100001 */   addiu $s0, $s0, 1
/* 0F1344 7F0BC814 904F0000 */  lbu   $t7, ($v0)
/* 0F1348 7F0BC818 25F80001 */  addiu $t8, $t7, 1
/* 0F134C 7F0BC81C 331900FF */  andi  $t9, $t8, 0xff
/* 0F1350 7F0BC820 2B210002 */  slti  $at, $t9, 2
/* 0F1354 7F0BC824 14200003 */  bnez  $at, .L7F0BC834
/* 0F1358 7F0BC828 A0580000 */   sb    $t8, ($v0)
/* 0F135C 7F0BC82C 0FC2F1A4 */  jal   sub_GAME_7F0BC690
/* 0F1360 7F0BC830 02002025 */   move  $a0, $s0
.L7F0BC834:
/* 0F1364 7F0BC834 26100001 */  addiu $s0, $s0, 1
.L7F0BC838:
/* 0F1368 7F0BC838 1613FFF2 */  bne   $s0, $s3, .L7F0BC804
/* 0F136C 7F0BC83C 26310004 */   addiu $s1, $s1, 4
/* 0F1370 7F0BC840 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F1374 7F0BC844 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1378 7F0BC848 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F137C 7F0BC84C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F1380 7F0BC850 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F1384 7F0BC854 03E00008 */  jr    $ra
/* 0F1388 7F0BC858 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BC7D4
/* 0EE5C4 7F0BBBD4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EE5C8 7F0BBBD8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0EE5CC 7F0BBBDC AFB10018 */  sw    $s1, 0x18($sp)
/* 0EE5D0 7F0BBBE0 AFB30020 */  sw    $s3, 0x20($sp)
/* 0EE5D4 7F0BBBE4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0EE5D8 7F0BBBE8 3C118007 */  lui   $s1, %hi(dword_CODE_bss_80083900) # $s1, 0x8007
/* 0EE5DC 7F0BBBEC 3C128007 */  lui   $s2, %hi(dword_CODE_bss_80083320) # $s2, 0x8007
/* 0EE5E0 7F0BBBF0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0EE5E4 7F0BBBF4 2652DC90 */  addiu $s2, %lo(dword_CODE_bss_80083320) # addiu $s2, $s2, -0x2370
/* 0EE5E8 7F0BBBF8 2631DE88 */  addiu $s1, %lo(dword_CODE_bss_80083900) # addiu $s1, $s1, -0x2178
/* 0EE5EC 7F0BBBFC 00008025 */  move  $s0, $zero
/* 0EE5F0 7F0BBC00 24130064 */  li    $s3, 100
.L7F0BBC04:
/* 0EE5F4 7F0BBC04 8E2E0000 */  lw    $t6, ($s1)
/* 0EE5F8 7F0BBC08 02501021 */  addu  $v0, $s2, $s0
/* 0EE5FC 7F0BBC0C 05C2000A */  bltzl $t6, .L7F0BBC38
/* 0EE600 7F0BBC10 26100001 */   addiu $s0, $s0, 1
/* 0EE604 7F0BBC14 904F0000 */  lbu   $t7, ($v0)
/* 0EE608 7F0BBC18 25F80001 */  addiu $t8, $t7, 1
/* 0EE60C 7F0BBC1C 331900FF */  andi  $t9, $t8, 0xff
/* 0EE610 7F0BBC20 2B210002 */  slti  $at, $t9, 2
/* 0EE614 7F0BBC24 14200003 */  bnez  $at, .L7F0BBC34
/* 0EE618 7F0BBC28 A0580000 */   sb    $t8, ($v0)
/* 0EE61C 7F0BBC2C 0FC2EEA4 */  jal   sub_GAME_7F0BC690
/* 0EE620 7F0BBC30 02002025 */   move  $a0, $s0
.L7F0BBC34:
/* 0EE624 7F0BBC34 26100001 */  addiu $s0, $s0, 1
.L7F0BBC38:
/* 0EE628 7F0BBC38 1613FFF2 */  bne   $s0, $s3, .L7F0BBC04
/* 0EE62C 7F0BBC3C 26310004 */   addiu $s1, $s1, 4
/* 0EE630 7F0BBC40 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0EE634 7F0BBC44 8FB00014 */  lw    $s0, 0x14($sp)
/* 0EE638 7F0BBC48 8FB10018 */  lw    $s1, 0x18($sp)
/* 0EE63C 7F0BBC4C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0EE640 7F0BBC50 8FB30020 */  lw    $s3, 0x20($sp)
/* 0EE644 7F0BBC54 03E00008 */  jr    $ra
/* 0EE648 7F0BBC58 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif
#endif




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




Gfx * sub_GAME_7F0BC9C4(Gfx *DL,int index)
{
    s32 i;
    
    i = sub_GAME_7F0BC85C(index);
    gSPMatrix(DL++, &mtx_array_bss_80083DB0[i], G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
    return DL;
}


s32 getRoomIndexPOS(s32 index)
{
    return &ptr_bgdata_room_fileposition_list[index].pos;
}


void sub_GAME_7F0BCA34(s32 index, coord3d *param_2)
{
    param_2->x = ptr_bgdata_room_fileposition_list[index].pos.x * room_data_float2;
    param_2->y = ptr_bgdata_room_fileposition_list[index].pos.y * room_data_float2;
    param_2->z = ptr_bgdata_room_fileposition_list[index].pos.z * room_data_float2;
}

