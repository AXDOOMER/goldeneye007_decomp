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




#ifdef NONMATCHING
void sub_GAME_7F0D1E98(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1E98
/* 1069C8 7F0D1E98 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 1069CC 7F0D1E9C 44810000 */  mtc1  $at, $f0
/* 1069D0 7F0D1EA0 3C018005 */  lui   $at, %hi(D_8004EAF4)
/* 1069D4 7F0D1EA4 C424EAF4 */  lwc1  $f4, %lo(D_8004EAF4)($at)
/* 1069D8 7F0D1EA8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1069DC 7F0D1EAC AFBF002C */  sw    $ra, 0x2c($sp)
/* 1069E0 7F0D1EB0 46002183 */  div.s $f6, $f4, $f0
/* 1069E4 7F0D1EB4 AFBE0028 */  sw    $fp, 0x28($sp)
/* 1069E8 7F0D1EB8 AFB70024 */  sw    $s7, 0x24($sp)
/* 1069EC 7F0D1EBC AFB60020 */  sw    $s6, 0x20($sp)
/* 1069F0 7F0D1EC0 AFB5001C */  sw    $s5, 0x1c($sp)
/* 1069F4 7F0D1EC4 AFB40018 */  sw    $s4, 0x18($sp)
/* 1069F8 7F0D1EC8 AFB30014 */  sw    $s3, 0x14($sp)
/* 1069FC 7F0D1ECC AFB20010 */  sw    $s2, 0x10($sp)
/* 106A00 7F0D1ED0 AFB1000C */  sw    $s1, 0xc($sp)
/* 106A04 7F0D1ED4 AFB00008 */  sw    $s0, 8($sp)
/* 106A08 7F0D1ED8 00801025 */  move  $v0, $a0
/* 106A0C 7F0D1EDC 3C0FF700 */  lui   $t7, 0xf700
/* 106A10 7F0D1EE0 AC4F0000 */  sw    $t7, ($v0)
/* 106A14 7F0D1EE4 000670C0 */  sll   $t6, $a2, 3
/* 106A18 7F0D1EE8 31CF07C0 */  andi  $t7, $t6, 0x7c0
/* 106A1C 7F0D1EEC 0005C200 */  sll   $t8, $a1, 8
/* 106A20 7F0D1EF0 3319F800 */  andi  $t9, $t8, 0xf800
/* 106A24 7F0D1EF4 032FC025 */  or    $t8, $t9, $t7
/* 106A28 7F0D1EF8 00077083 */  sra   $t6, $a3, 2
/* 106A2C 7F0D1EFC 31D9003E */  andi  $t9, $t6, 0x3e
/* 106A30 7F0D1F00 03191825 */  or    $v1, $t8, $t9
/* 106A34 7F0D1F04 346F0001 */  ori   $t7, $v1, 1
/* 106A38 7F0D1F08 000F7400 */  sll   $t6, $t7, 0x10
/* 106A3C 7F0D1F0C 4600320D */  trunc.w.s $f8, $f6
/* 106A40 7F0D1F10 01CFC025 */  or    $t8, $t6, $t7
/* 106A44 7F0D1F14 AC580004 */  sw    $t8, 4($v0)
/* 106A48 7F0D1F18 24840008 */  addiu $a0, $a0, 8
/* 106A4C 7F0D1F1C 44084000 */  mfc1  $t0, $f8
/* 106A50 7F0D1F20 00000000 */  nop   
/* 106A54 7F0D1F24 050200F2 */  bltzl $t0, .L7F0D22F0
/* 106A58 7F0D1F28 8FBF002C */   lw    $ra, 0x2c($sp)
/* 106A5C 7F0D1F2C 44805000 */  mtc1  $zero, $f10
/* 106A60 7F0D1F30 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106A64 7F0D1F34 44819000 */  mtc1  $at, $f18
/* 106A68 7F0D1F38 46805420 */  cvt.s.w $f16, $f10
/* 106A6C 7F0D1F3C 24180001 */  li    $t8, 1
/* 106A70 7F0D1F40 44985000 */  mtc1  $t8, $f10
/* 106A74 7F0D1F44 3C01F600 */  lui   $at, 0xf600
/* 106A78 7F0D1F48 24180002 */  li    $t8, 2
/* 106A7C 7F0D1F4C 000080C0 */  sll   $s0, $zero, 3
/* 106A80 7F0D1F50 46128102 */  mul.s $f4, $f16, $f18
/* 106A84 7F0D1F54 02008023 */  subu  $s0, $s0, $zero
/* 106A88 7F0D1F58 000848C0 */  sll   $t1, $t0, 3
/* 106A8C 7F0D1F5C 01284823 */  subu  $t1, $t1, $t0
/* 106A90 7F0D1F60 25290012 */  addiu $t1, $t1, 0x12
/* 106A94 7F0D1F64 26030015 */  addiu $v1, $s0, 0x15
/* 106A98 7F0D1F68 46805420 */  cvt.s.w $f16, $f10
/* 106A9C 7F0D1F6C 44985000 */  mtc1  $t8, $f10
/* 106AA0 7F0D1F70 26020012 */  addiu $v0, $s0, 0x12
/* 106AA4 7F0D1F74 241F0027 */  li    $ra, 39
/* 106AA8 7F0D1F78 241E000B */  li    $fp, 11
/* 106AAC 7F0D1F7C 46002183 */  div.s $f6, $f4, $f0
/* 106AB0 7F0D1F80 3C17F600 */  lui   $s7, 0xf600
/* 106AB4 7F0D1F84 4600320D */  trunc.w.s $f8, $f6
/* 106AB8 7F0D1F88 44054000 */  mfc1  $a1, $f8
/* 106ABC 7F0D1F8C 00000000 */  nop   
/* 106AC0 7F0D1F90 24A50032 */  addiu $a1, $a1, 0x32
/* 106AC4 7F0D1F94 30AF03FF */  andi  $t7, $a1, 0x3ff
/* 106AC8 7F0D1F98 000F2B80 */  sll   $a1, $t7, 0xe
/* 106ACC 7F0D1F9C 00A15025 */  or    $t2, $a1, $at
/* 106AD0 7F0D1FA0 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106AD4 7F0D1FA4 44819000 */  mtc1  $at, $f18
/* 106AD8 7F0D1FA8 3C01F600 */  lui   $at, 0xf600
/* 106ADC 7F0D1FAC 46128102 */  mul.s $f4, $f16, $f18
/* 106AE0 7F0D1FB0 46805420 */  cvt.s.w $f16, $f10
/* 106AE4 7F0D1FB4 46002183 */  div.s $f6, $f4, $f0
/* 106AE8 7F0D1FB8 4600320D */  trunc.w.s $f8, $f6
/* 106AEC 7F0D1FBC 44064000 */  mfc1  $a2, $f8
/* 106AF0 7F0D1FC0 00000000 */  nop   
/* 106AF4 7F0D1FC4 24C60032 */  addiu $a2, $a2, 0x32
/* 106AF8 7F0D1FC8 30CF03FF */  andi  $t7, $a2, 0x3ff
/* 106AFC 7F0D1FCC 000F3380 */  sll   $a2, $t7, 0xe
/* 106B00 7F0D1FD0 00C15825 */  or    $t3, $a2, $at
/* 106B04 7F0D1FD4 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106B08 7F0D1FD8 44819000 */  mtc1  $at, $f18
/* 106B0C 7F0D1FDC 3C01F600 */  lui   $at, 0xf600
/* 106B10 7F0D1FE0 46128102 */  mul.s $f4, $f16, $f18
/* 106B14 7F0D1FE4 46002183 */  div.s $f6, $f4, $f0
/* 106B18 7F0D1FE8 4600320D */  trunc.w.s $f8, $f6
/* 106B1C 7F0D1FEC 44074000 */  mfc1  $a3, $f8
/* 106B20 7F0D1FF0 00000000 */  nop   
/* 106B24 7F0D1FF4 24E70032 */  addiu $a3, $a3, 0x32
/* 106B28 7F0D1FF8 30EF03FF */  andi  $t7, $a3, 0x3ff
/* 106B2C 7F0D1FFC 000F3B80 */  sll   $a3, $t7, 0xe
/* 106B30 7F0D2000 00E16025 */  or    $t4, $a3, $at
/* 106B34 7F0D2004 3C01435B */  li    $at, 0x435B0000 # 219.000000
/* 106B38 7F0D2008 44811000 */  mtc1  $at, $f2
/* 106B3C 7F0D200C 00000000 */  nop   
/* 106B40 7F0D2010 00808025 */  move  $s0, $a0
.L7F0D2014:
/* 106B44 7F0D2014 307203FF */  andi  $s2, $v1, 0x3ff
/* 106B48 7F0D2018 305303FF */  andi  $s3, $v0, 0x3ff
/* 106B4C 7F0D201C 00137880 */  sll   $t7, $s3, 2
/* 106B50 7F0D2020 0012C080 */  sll   $t8, $s2, 2
/* 106B54 7F0D2024 0158C825 */  or    $t9, $t2, $t8
/* 106B58 7F0D2028 00AF7025 */  or    $t6, $a1, $t7
/* 106B5C 7F0D202C AE0E0004 */  sw    $t6, 4($s0)
/* 106B60 7F0D2030 AE190000 */  sw    $t9, ($s0)
/* 106B64 7F0D2034 24840008 */  addiu $a0, $a0, 8
/* 106B68 7F0D2038 00808025 */  move  $s0, $a0
/* 106B6C 7F0D203C 03009025 */  move  $s2, $t8
/* 106B70 7F0D2040 0178C025 */  or    $t8, $t3, $t8
/* 106B74 7F0D2044 00CFC825 */  or    $t9, $a2, $t7
/* 106B78 7F0D2048 AE190004 */  sw    $t9, 4($s0)
/* 106B7C 7F0D204C AE180000 */  sw    $t8, ($s0)
/* 106B80 7F0D2050 24840008 */  addiu $a0, $a0, 8
/* 106B84 7F0D2054 00808025 */  move  $s0, $a0
/* 106B88 7F0D2058 01E09825 */  move  $s3, $t7
/* 106B8C 7F0D205C 00F37025 */  or    $t6, $a3, $s3
/* 106B90 7F0D2060 01927825 */  or    $t7, $t4, $s2
/* 106B94 7F0D2064 AE0F0000 */  sw    $t7, ($s0)
/* 106B98 7F0D2068 AE0E0004 */  sw    $t6, 4($s0)
/* 106B9C 7F0D206C 24840008 */  addiu $a0, $a0, 8
/* 106BA0 7F0D2070 240D0003 */  li    $t5, 3
/* 106BA4 7F0D2074 448D7000 */  mtc1  $t5, $f14
/* 106BA8 7F0D2078 27DEFFFC */  addiu $fp, $fp, -4
/* 106BAC 7F0D207C 468073A0 */  cvt.s.w $f14, $f14
/* 106BB0 7F0D2080 46027382 */  mul.s $f14, $f14, $f2
/* 106BB4 7F0D2084 46007383 */  div.s $f14, $f14, $f0
/* 106BB8 7F0D2088 4600738D */  trunc.w.s $f14, $f14
/* 106BBC 7F0D208C 44117000 */  mfc1  $s1, $f14
/* 106BC0 7F0D2090 00000000 */  nop   
/* 106BC4 7F0D2094 26310032 */  addiu $s1, $s1, 0x32
/* 106BC8 7F0D2098 323903FF */  andi  $t9, $s1, 0x3ff
/* 106BCC 7F0D209C 00197B80 */  sll   $t7, $t9, 0xe
/* 106BD0 7F0D20A0 01F77025 */  or    $t6, $t7, $s7
/* 106BD4 7F0D20A4 01F3C825 */  or    $t9, $t7, $s3
/* 106BD8 7F0D20A8 25AF0001 */  addiu $t7, $t5, 1
/* 106BDC 7F0D20AC 448F7000 */  mtc1  $t7, $f14
/* 106BE0 7F0D20B0 00000000 */  nop   
/* 106BE4 7F0D20B4 468073A0 */  cvt.s.w $f14, $f14
/* 106BE8 7F0D20B8 46027482 */  mul.s $f18, $f14, $f2
/* 106BEC 7F0D20BC 51BE004D */  beql  $t5, $fp, .L7F0D21F4
/* 106BF0 7F0D20C0 46009403 */   div.s $f16, $f18, $f0
/* 106BF4 7F0D20C4 46009403 */  div.s $f16, $f18, $f0
.L7F0D20C8:
/* 106BF8 7F0D20C8 00808025 */  move  $s0, $a0
/* 106BFC 7F0D20CC 01D2C025 */  or    $t8, $t6, $s2
/* 106C00 7F0D20D0 AE180000 */  sw    $t8, ($s0)
/* 106C04 7F0D20D4 AE190004 */  sw    $t9, 4($s0)
/* 106C08 7F0D20D8 24840008 */  addiu $a0, $a0, 8
/* 106C0C 7F0D20DC 00808025 */  move  $s0, $a0
/* 106C10 7F0D20E0 24840008 */  addiu $a0, $a0, 8
/* 106C14 7F0D20E4 4600840D */  trunc.w.s $f16, $f16
/* 106C18 7F0D20E8 44148000 */  mfc1  $s4, $f16
/* 106C1C 7F0D20EC 00000000 */  nop   
/* 106C20 7F0D20F0 26940032 */  addiu $s4, $s4, 0x32
/* 106C24 7F0D20F4 329803FF */  andi  $t8, $s4, 0x3ff
/* 106C28 7F0D20F8 0018CB80 */  sll   $t9, $t8, 0xe
/* 106C2C 7F0D20FC 03377825 */  or    $t7, $t9, $s7
/* 106C30 7F0D2100 0333C025 */  or    $t8, $t9, $s3
/* 106C34 7F0D2104 25B90002 */  addiu $t9, $t5, 2
/* 106C38 7F0D2108 44998000 */  mtc1  $t9, $f16
/* 106C3C 7F0D210C 01F27025 */  or    $t6, $t7, $s2
/* 106C40 7F0D2110 AE0E0000 */  sw    $t6, ($s0)
/* 106C44 7F0D2114 46808420 */  cvt.s.w $f16, $f16
/* 106C48 7F0D2118 AE180004 */  sw    $t8, 4($s0)
/* 106C4C 7F0D211C 00808025 */  move  $s0, $a0
/* 106C50 7F0D2120 24840008 */  addiu $a0, $a0, 8
/* 106C54 7F0D2124 46028402 */  mul.s $f16, $f16, $f2
/* 106C58 7F0D2128 46008403 */  div.s $f16, $f16, $f0
/* 106C5C 7F0D212C 4600840D */  trunc.w.s $f16, $f16
/* 106C60 7F0D2130 44158000 */  mfc1  $s5, $f16
/* 106C64 7F0D2134 00000000 */  nop   
/* 106C68 7F0D2138 26B50032 */  addiu $s5, $s5, 0x32
/* 106C6C 7F0D213C 32AE03FF */  andi  $t6, $s5, 0x3ff
/* 106C70 7F0D2140 000EC380 */  sll   $t8, $t6, 0xe
/* 106C74 7F0D2144 0317C825 */  or    $t9, $t8, $s7
/* 106C78 7F0D2148 03137025 */  or    $t6, $t8, $s3
/* 106C7C 7F0D214C 25B80003 */  addiu $t8, $t5, 3
/* 106C80 7F0D2150 44988000 */  mtc1  $t8, $f16
/* 106C84 7F0D2154 25AD0004 */  addiu $t5, $t5, 4
/* 106C88 7F0D2158 448D7000 */  mtc1  $t5, $f14
/* 106C8C 7F0D215C 46808420 */  cvt.s.w $f16, $f16
/* 106C90 7F0D2160 03327825 */  or    $t7, $t9, $s2
/* 106C94 7F0D2164 AE0F0000 */  sw    $t7, ($s0)
/* 106C98 7F0D2168 AE0E0004 */  sw    $t6, 4($s0)
/* 106C9C 7F0D216C 00808025 */  move  $s0, $a0
/* 106CA0 7F0D2170 24840008 */  addiu $a0, $a0, 8
/* 106CA4 7F0D2174 46028402 */  mul.s $f16, $f16, $f2
/* 106CA8 7F0D2178 46008403 */  div.s $f16, $f16, $f0
/* 106CAC 7F0D217C 4600840D */  trunc.w.s $f16, $f16
/* 106CB0 7F0D2180 468073A0 */  cvt.s.w $f14, $f14
/* 106CB4 7F0D2184 44168000 */  mfc1  $s6, $f16
/* 106CB8 7F0D2188 00000000 */  nop   
/* 106CBC 7F0D218C 26D60032 */  addiu $s6, $s6, 0x32
/* 106CC0 7F0D2190 32CF03FF */  andi  $t7, $s6, 0x3ff
/* 106CC4 7F0D2194 46027382 */  mul.s $f14, $f14, $f2
/* 106CC8 7F0D2198 000F7380 */  sll   $t6, $t7, 0xe
/* 106CCC 7F0D219C 01D7C025 */  or    $t8, $t6, $s7
/* 106CD0 7F0D21A0 0312C825 */  or    $t9, $t8, $s2
/* 106CD4 7F0D21A4 AE190000 */  sw    $t9, ($s0)
/* 106CD8 7F0D21A8 01D37825 */  or    $t7, $t6, $s3
/* 106CDC 7F0D21AC AE0F0004 */  sw    $t7, 4($s0)
/* 106CE0 7F0D21B0 46007383 */  div.s $f14, $f14, $f0
/* 106CE4 7F0D21B4 4600738D */  trunc.w.s $f14, $f14
/* 106CE8 7F0D21B8 44117000 */  mfc1  $s1, $f14
/* 106CEC 7F0D21BC 00000000 */  nop   
/* 106CF0 7F0D21C0 26310032 */  addiu $s1, $s1, 0x32
/* 106CF4 7F0D21C4 323903FF */  andi  $t9, $s1, 0x3ff
/* 106CF8 7F0D21C8 00197B80 */  sll   $t7, $t9, 0xe
/* 106CFC 7F0D21CC 01F77025 */  or    $t6, $t7, $s7
/* 106D00 7F0D21D0 01F3C825 */  or    $t9, $t7, $s3
/* 106D04 7F0D21D4 25AF0001 */  addiu $t7, $t5, 1
/* 106D08 7F0D21D8 448F7000 */  mtc1  $t7, $f14
/* 106D0C 7F0D21DC 00000000 */  nop   
/* 106D10 7F0D21E0 468073A0 */  cvt.s.w $f14, $f14
/* 106D14 7F0D21E4 46027482 */  mul.s $f18, $f14, $f2
/* 106D18 7F0D21E8 55BEFFB7 */  bnel  $t5, $fp, .L7F0D20C8
/* 106D1C 7F0D21EC 46009403 */   div.s $f16, $f18, $f0
/* 106D20 7F0D21F0 46009403 */  div.s $f16, $f18, $f0
.L7F0D21F4:
/* 106D24 7F0D21F4 00808025 */  move  $s0, $a0
/* 106D28 7F0D21F8 01D2C025 */  or    $t8, $t6, $s2
/* 106D2C 7F0D21FC AE180000 */  sw    $t8, ($s0)
/* 106D30 7F0D2200 AE190004 */  sw    $t9, 4($s0)
/* 106D34 7F0D2204 24840008 */  addiu $a0, $a0, 8
/* 106D38 7F0D2208 00808025 */  move  $s0, $a0
/* 106D3C 7F0D220C 24840008 */  addiu $a0, $a0, 8
/* 106D40 7F0D2210 27DE0004 */  addiu $fp, $fp, 4
/* 106D44 7F0D2214 4600840D */  trunc.w.s $f16, $f16
/* 106D48 7F0D2218 44148000 */  mfc1  $s4, $f16
/* 106D4C 7F0D221C 00000000 */  nop   
/* 106D50 7F0D2220 26940032 */  addiu $s4, $s4, 0x32
/* 106D54 7F0D2224 329803FF */  andi  $t8, $s4, 0x3ff
/* 106D58 7F0D2228 0018CB80 */  sll   $t9, $t8, 0xe
/* 106D5C 7F0D222C 03377825 */  or    $t7, $t9, $s7
/* 106D60 7F0D2230 0333C025 */  or    $t8, $t9, $s3
/* 106D64 7F0D2234 25B90002 */  addiu $t9, $t5, 2
/* 106D68 7F0D2238 44998000 */  mtc1  $t9, $f16
/* 106D6C 7F0D223C 01F27025 */  or    $t6, $t7, $s2
/* 106D70 7F0D2240 AE0E0000 */  sw    $t6, ($s0)
/* 106D74 7F0D2244 46808420 */  cvt.s.w $f16, $f16
/* 106D78 7F0D2248 AE180004 */  sw    $t8, 4($s0)
/* 106D7C 7F0D224C 00808025 */  move  $s0, $a0
/* 106D80 7F0D2250 24840008 */  addiu $a0, $a0, 8
/* 106D84 7F0D2254 46028402 */  mul.s $f16, $f16, $f2
/* 106D88 7F0D2258 46008403 */  div.s $f16, $f16, $f0
/* 106D8C 7F0D225C 4600840D */  trunc.w.s $f16, $f16
/* 106D90 7F0D2260 44158000 */  mfc1  $s5, $f16
/* 106D94 7F0D2264 00000000 */  nop   
/* 106D98 7F0D2268 26B50032 */  addiu $s5, $s5, 0x32
/* 106D9C 7F0D226C 32AE03FF */  andi  $t6, $s5, 0x3ff
/* 106DA0 7F0D2270 000EC380 */  sll   $t8, $t6, 0xe
/* 106DA4 7F0D2274 0317C825 */  or    $t9, $t8, $s7
/* 106DA8 7F0D2278 03137025 */  or    $t6, $t8, $s3
/* 106DAC 7F0D227C 25B80003 */  addiu $t8, $t5, 3
/* 106DB0 7F0D2280 44988000 */  mtc1  $t8, $f16
/* 106DB4 7F0D2284 03327825 */  or    $t7, $t9, $s2
/* 106DB8 7F0D2288 AE0F0000 */  sw    $t7, ($s0)
/* 106DBC 7F0D228C 46808420 */  cvt.s.w $f16, $f16
/* 106DC0 7F0D2290 AE0E0004 */  sw    $t6, 4($s0)
/* 106DC4 7F0D2294 00808025 */  move  $s0, $a0
/* 106DC8 7F0D2298 24840008 */  addiu $a0, $a0, 8
/* 106DCC 7F0D229C 25AD0004 */  addiu $t5, $t5, 4
/* 106DD0 7F0D22A0 46028402 */  mul.s $f16, $f16, $f2
/* 106DD4 7F0D22A4 46008403 */  div.s $f16, $f16, $f0
/* 106DD8 7F0D22A8 4600840D */  trunc.w.s $f16, $f16
/* 106DDC 7F0D22AC 44168000 */  mfc1  $s6, $f16
/* 106DE0 7F0D22B0 00000000 */  nop   
/* 106DE4 7F0D22B4 26D60032 */  addiu $s6, $s6, 0x32
/* 106DE8 7F0D22B8 32CF03FF */  andi  $t7, $s6, 0x3ff
/* 106DEC 7F0D22BC 000F7380 */  sll   $t6, $t7, 0xe
/* 106DF0 7F0D22C0 01D7C025 */  or    $t8, $t6, $s7
/* 106DF4 7F0D22C4 0312C825 */  or    $t9, $t8, $s2
/* 106DF8 7F0D22C8 01D37825 */  or    $t7, $t6, $s3
/* 106DFC 7F0D22CC AE0F0004 */  sw    $t7, 4($s0)
/* 106E00 7F0D22D0 AE190000 */  sw    $t9, ($s0)
/* 106E04 7F0D22D4 24420007 */  addiu $v0, $v0, 7
/* 106E08 7F0D22D8 0122082A */  slt   $at, $t1, $v0
/* 106E0C 7F0D22DC 14200003 */  bnez  $at, .L7F0D22EC
/* 106E10 7F0D22E0 24630007 */   addiu $v1, $v1, 7
/* 106E14 7F0D22E4 545FFF4B */  bnel  $v0, $ra, .L7F0D2014
/* 106E18 7F0D22E8 00808025 */   move  $s0, $a0
.L7F0D22EC:
/* 106E1C 7F0D22EC 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F0D22F0:
/* 106E20 7F0D22F0 8FB00008 */  lw    $s0, 8($sp)
/* 106E24 7F0D22F4 8FB1000C */  lw    $s1, 0xc($sp)
/* 106E28 7F0D22F8 8FB20010 */  lw    $s2, 0x10($sp)
/* 106E2C 7F0D22FC 8FB30014 */  lw    $s3, 0x14($sp)
/* 106E30 7F0D2300 8FB40018 */  lw    $s4, 0x18($sp)
/* 106E34 7F0D2304 8FB5001C */  lw    $s5, 0x1c($sp)
/* 106E38 7F0D2308 8FB60020 */  lw    $s6, 0x20($sp)
/* 106E3C 7F0D230C 8FB70024 */  lw    $s7, 0x24($sp)
/* 106E40 7F0D2310 8FBE0028 */  lw    $fp, 0x28($sp)
/* 106E44 7F0D2314 27BD0030 */  addiu $sp, $sp, 0x30
/* 106E48 7F0D2318 03E00008 */  jr    $ra
/* 106E4C 7F0D231C 00801025 */   move  $v0, $a0
)
#endif





void sub_GAME_7F0D2320(void)
{
    s32 t;

    t = (s32) (D_8004EAF4 / 10.0f);
    t = (t * 10) + 10;
    
    D_8004EAF4 = t;
    D_8004EAF0 = D_8004EAF4;
}




