#include <ultra64.h>
#include <memp.h>
#include "player.h"
#include "unk_092E50.h"
#include "bondview.h"
#include "lvl.h"
#include "fog.h"
#include "bg.h"
#include "othermodemicrocode.h"
#include "fr.h"
#include "image_bank.h"

#define SKYABS(val) (val >= 0.0f ? (val) : -(val))

// bss
s32 copyof_stagenum;

s32 dword_CODE_bss_80079E94;
Mtxf dword_CODE_bss_80079E98;
u32 dword_CODE_bss_80079ED8;

struct player *g_playerPointers[4];
struct player_data g_playerPlayerData[4];

/**
 * Address 0x8007a0b0.
 */
struct player *g_CurrentPlayer;
struct player_data *g_playerPerm;

s32 player_num;
s32 random_byte;
PLAYER_ID array_PLAYER_IDs[4];
//s32 dword_CODE_bss_8007A0C4;
//s32 dword_CODE_bss_8007A0C8;
//s32 dword_CODE_bss_8007A0CC;

void sub_GAME_7F093880(f32 offset_x, f32 offset_y, coord3d* out) {
    Mtxf* player_mtxf;
    coord2d coords;
    f32 screen_top;

    player_mtxf = currentPlayerGetMatrix10D4();
    coords.x = getPlayer_c_screenleft() + offset_x;
    screen_top = getPlayer_c_screentop();
    coords.y = fogGetCurrentEnvironmentp()->WaterConcavity + (offset_y + screen_top);
    sub_GAME_7F077EEC(&coords, out, 100.0f);
    matrix_4x4_rotate_vector_in_place(player_mtxf, out->f);
}



#ifdef NONMATCHING
bool sub_GAME_7F0938FC(coord3d *arg0, coord3d *arg1, f32 *arg2) {
    f32 sp24;
    f32 sp2C;
    s32 temp_s1;
    f32 temp_f12;
    f32 temp_f2;
    f32 temp_f12_2;
    f32 phi_f12;
    f32 phi_f16;
    f32 phi_f2;
    f32 phi_return;

    // Node 0
    temp_s1 = bondviewGetCurrentPlayersPosition();
    temp_f12 = ((arg0->unk4 + arg0->unk4) / sqrtf((((arg0->unk8 * arg0->unk8) + (*arg0 * *arg0)) + D_80057520), *arg0));
    phi_f12 = temp_f12;
    if (1.0f < temp_f12)
    {
        // Node 1
        phi_f12 = 1.0f;
    }
    // Node 2
    *arg2 = (f32) (1.0f - phi_f12);
    if (0.0f == arg0->unk4)
    {
        // Node 3
        phi_f16 = D_80057524;
    }
    else
    {
        // Node 4
        phi_f16 = arg0->unk4;
    }
    // Node 5
    phi_return = 0.0f;
    if (0.0f < phi_f16)
    {
        // Node 6
        sp24 = (f32) phi_f16;
        temp_f2 = ((fogGetCurrentEnvironmentp(phi_f12, 1.0f)->unkC - temp_s1->unk4) / phi_f16);
        sp2C = temp_f2;
        temp_f12_2 = (sqrtf(((arg0->unk8 * arg0->unk8) + (*arg0 * *arg0)), *arg0) * temp_f2);
        phi_f2 = temp_f2;
        if (D_80057528 < temp_f12_2)
        {
            // Node 7
            phi_f2 = (temp_f2 * (D_80057528 / temp_f12_2));
        }
        // Node 8
        *arg1 = (f32) ((*arg0 * phi_f2) + *temp_s1);
        arg1->unk4 = (f32) (temp_s1->unk4 + (phi_f2 * phi_f16));
        arg1->unk8 = (f32) ((arg0->unk8 * phi_f2) + temp_s1->unk8);
        phi_return = 1.401298464324817e-45f;
    }
    // Node 9
    return phi_return;
}
#else
bool sub_GAME_7F0938FC(coord3d *arg0, coord3d *arg1, f32 *arg2);
GLOBAL_ASM(
.late_rodata
glabel D_80057520
.word 0x38d1b717 /*0.000099999997*/
glabel D_80057524
.word 0x3c23d70a /*0.0099999998*/
glabel D_80057528
.word 0x48927c00 /*300000.0*/
.text
glabel sub_GAME_7F0938FC
/* 0C842C 7F0938FC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C8430 7F093900 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C8434 7F093904 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C8438 7F093908 00808025 */  move  $s0, $a0
/* 0C843C 7F09390C AFB10018 */  sw    $s1, 0x18($sp)
/* 0C8440 7F093910 AFA5003C */  sw    $a1, 0x3c($sp)
/* 0C8444 7F093914 0FC227F5 */  jal   bondviewGetCurrentPlayersPosition
/* 0C8448 7F093918 AFA60040 */   sw    $a2, 0x40($sp)
/* 0C844C 7F09391C C6000008 */  lwc1  $f0, 8($s0)
/* 0C8450 7F093920 C60E0000 */  lwc1  $f14, ($s0)
/* 0C8454 7F093924 3C018005 */  lui   $at, %hi(D_80057520)
/* 0C8458 7F093928 46000102 */  mul.s $f4, $f0, $f0
/* 0C845C 7F09392C C42A7520 */  lwc1  $f10, %lo(D_80057520)($at)
/* 0C8460 7F093930 00408825 */  move  $s1, $v0
/* 0C8464 7F093934 460E7182 */  mul.s $f6, $f14, $f14
/* 0C8468 7F093938 46062200 */  add.s $f8, $f4, $f6
/* 0C846C 7F09393C 0C007DF8 */  jal   sqrtf
/* 0C8470 7F093940 460A4300 */   add.s $f12, $f8, $f10
/* 0C8474 7F093944 C6020004 */  lwc1  $f2, 4($s0)
/* 0C8478 7F093948 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C847C 7F09394C 44817000 */  mtc1  $at, $f14
/* 0C8480 7F093950 46021100 */  add.s $f4, $f2, $f2
/* 0C8484 7F093954 3C018005 */  lui   $at, %hi(D_80057524)
/* 0C8488 7F093958 00001025 */  move  $v0, $zero
/* 0C848C 7F09395C 46002303 */  div.s $f12, $f4, $f0
/* 0C8490 7F093960 460C703C */  c.lt.s $f14, $f12
/* 0C8494 7F093964 00000000 */  nop
/* 0C8498 7F093968 45020003 */  bc1fl .L7F093978
/* 0C849C 7F09396C 460C7181 */   sub.s $f6, $f14, $f12
/* 0C84A0 7F093970 46007306 */  mov.s $f12, $f14
/* 0C84A4 7F093974 460C7181 */  sub.s $f6, $f14, $f12
.L7F093978:
/* 0C84A8 7F093978 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0C84AC 7F09397C 44800000 */  mtc1  $zero, $f0
/* 0C84B0 7F093980 E5C60000 */  swc1  $f6, ($t6)
/* 0C84B4 7F093984 C6020004 */  lwc1  $f2, 4($s0)
/* 0C84B8 7F093988 46020032 */  c.eq.s $f0, $f2
/* 0C84BC 7F09398C 00000000 */  nop
/* 0C84C0 7F093990 45020004 */  bc1fl .L7F0939A4
/* 0C84C4 7F093994 46001406 */   mov.s $f16, $f2
/* 0C84C8 7F093998 10000002 */  b     .L7F0939A4
/* 0C84CC 7F09399C C4307524 */   lwc1  $f16, %lo(D_80057524)($at)
/* 0C84D0 7F0939A0 46001406 */  mov.s $f16, $f2
.L7F0939A4:
/* 0C84D4 7F0939A4 4610003C */  c.lt.s $f0, $f16
/* 0C84D8 7F0939A8 00000000 */  nop
/* 0C84DC 7F0939AC 4500002D */  bc1f  .L7F093A64
/* 0C84E0 7F0939B0 00000000 */   nop
/* 0C84E4 7F0939B4 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C84E8 7F0939B8 E7B00024 */   swc1  $f16, 0x24($sp)
/* 0C84EC 7F0939BC C448000C */  lwc1  $f8, 0xc($v0)
/* 0C84F0 7F0939C0 C62A0004 */  lwc1  $f10, 4($s1)
/* 0C84F4 7F0939C4 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0C84F8 7F0939C8 C6000008 */  lwc1  $f0, 8($s0)
/* 0C84FC 7F0939CC 460A4101 */  sub.s $f4, $f8, $f10
/* 0C8500 7F0939D0 C60E0000 */  lwc1  $f14, ($s0)
/* 0C8504 7F0939D4 46000182 */  mul.s $f6, $f0, $f0
/* 0C8508 7F0939D8 00000000 */  nop
/* 0C850C 7F0939DC 460E7202 */  mul.s $f8, $f14, $f14
/* 0C8510 7F0939E0 46102083 */  div.s $f2, $f4, $f16
/* 0C8514 7F0939E4 46083300 */  add.s $f12, $f6, $f8
/* 0C8518 7F0939E8 0C007DF8 */  jal   sqrtf
/* 0C851C 7F0939EC E7A2002C */   swc1  $f2, 0x2c($sp)
/* 0C8520 7F0939F0 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 0C8524 7F0939F4 3C018005 */  lui   $at, %hi(D_80057528)
/* 0C8528 7F0939F8 C4327528 */  lwc1  $f18, %lo(D_80057528)($at)
/* 0C852C 7F0939FC 46020302 */  mul.s $f12, $f0, $f2
/* 0C8530 7F093A00 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0C8534 7F093A04 460C903C */  c.lt.s $f18, $f12
/* 0C8538 7F093A08 00000000 */  nop
/* 0C853C 7F093A0C 45020005 */  bc1fl .L7F093A24
/* 0C8540 7F093A10 C6040000 */   lwc1  $f4, ($s0)
/* 0C8544 7F093A14 460C9283 */  div.s $f10, $f18, $f12
/* 0C8548 7F093A18 460A1082 */  mul.s $f2, $f2, $f10
/* 0C854C 7F093A1C 00000000 */  nop
/* 0C8550 7F093A20 C6040000 */  lwc1  $f4, ($s0)
.L7F093A24:
/* 0C8554 7F093A24 C6280000 */  lwc1  $f8, ($s1)
/* 0C8558 7F093A28 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C855C 7F093A2C 46022182 */  mul.s $f6, $f4, $f2
/* 0C8560 7F093A30 24020001 */  li    $v0, 1
/* 0C8564 7F093A34 46083280 */  add.s $f10, $f6, $f8
/* 0C8568 7F093A38 46101182 */  mul.s $f6, $f2, $f16
/* 0C856C 7F093A3C E46A0000 */  swc1  $f10, ($v1)
/* 0C8570 7F093A40 C6240004 */  lwc1  $f4, 4($s1)
/* 0C8574 7F093A44 46062200 */  add.s $f8, $f4, $f6
/* 0C8578 7F093A48 E4680004 */  swc1  $f8, 4($v1)
/* 0C857C 7F093A4C C60A0008 */  lwc1  $f10, 8($s0)
/* 0C8580 7F093A50 C6260008 */  lwc1  $f6, 8($s1)
/* 0C8584 7F093A54 46025102 */  mul.s $f4, $f10, $f2
/* 0C8588 7F093A58 46062200 */  add.s $f8, $f4, $f6
/* 0C858C 7F093A5C 10000001 */  b     .L7F093A64
/* 0C8590 7F093A60 E4680008 */   swc1  $f8, 8($v1)
.L7F093A64:
/* 0C8594 7F093A64 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C8598 7F093A68 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C859C 7F093A6C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C85A0 7F093A70 03E00008 */  jr    $ra
/* 0C85A4 7F093A74 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif


bool sub_GAME_7F093A78(coord3d *arg0, coord3d *arg1, f32 *arg2)
{
    coord3d *campos = bondviewGetCurrentPlayersPosition();
    f32 f12 = -2.0f * arg0->y / sqrtf(arg0->f[0] * arg0->f[0] + arg0->f[2] * arg0->f[2] + 0.0001f);
    f32 sp2c;
    f32 f12_2;
    f32 sp24;
    u32 stack[2];

    if (f12 > 1.0f)
    {
        f12 = 1.0f;
    }

    *arg2 = 1.0f - f12;

    if (arg0->y == 0.0f)
    {
        sp24 = -0.01f;
    }
    else
    {
        sp24 = arg0->y;
    }

    if (sp24 < 0.0f)
    {
        sp2c = (fogGetCurrentEnvironmentp()->WaterRepeat - campos->y) / sp24;
        f12_2 = sqrtf(arg0->f[0] * arg0->f[0] + arg0->f[2] * arg0->f[2]) * sp2c;

        if (f12_2 > 300000)
        {
            sp2c *= 300000 / f12_2;
        }

        arg1->x = campos->x + sp2c * arg0->f[0];
        arg1->y = campos->y + sp2c * sp24;
        arg1->z = campos->z + sp2c * arg0->f[2];

        return TRUE;
    }

    return FALSE;
}


void sub_GAME_7F093BFC(coord3d *arg0, coord3d* arg1, coord3d* out) 
{
    f32 temp_f0;

    temp_f0 = arg0->y / (arg0->y - arg1->y);
    out->x = ((arg1->x - arg0->x) * temp_f0) + arg0->x;
    out->y = 0.0f;
    out->z = ((arg1->z - arg0->z) * temp_f0) + arg0->z;
}

f32 sub_GAME_7F093C48(f32 a, f32 b, f32 c)
{
    if (a < b)
    {
        return b;
    }
    if (c < a)
    {
        return c;
    }
    return a;
}



f32 addpoint5tofloat(f32 arg0) {
    return (f32) (s32) (arg0 + 0.5f);
}





#ifdef NONMATCHING
void sub_GAME_7F093CB0(SkyRelated18 *arg0, f32 arg1) {

}
#else
void sub_GAME_7F093CB0(SkyRelated18 *arg0, f32 arg1);
GLOBAL_ASM(
.text
glabel sub_GAME_7F093CB0
/* 0C87E0 7F093CB0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C87E4 7F093CB4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C87E8 7F093CB8 AFA40030 */  sw    $a0, 0x30($sp)
/* 0C87EC 7F093CBC 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C87F0 7F093CC0 AFA50034 */   sw    $a1, 0x34($sp)
/* 0C87F4 7F093CC4 904E0008 */  lbu   $t6, 8($v0)
/* 0C87F8 7F093CC8 448E2000 */  mtc1  $t6, $f4
/* 0C87FC 7F093CCC 05C10005 */  bgez  $t6, .L7F093CE4
/* 0C8800 7F093CD0 468021A0 */   cvt.s.w $f6, $f4
/* 0C8804 7F093CD4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8808 7F093CD8 44814000 */  mtc1  $at, $f8
/* 0C880C 7F093CDC 00000000 */  nop
/* 0C8810 7F093CE0 46083180 */  add.s $f6, $f6, $f8
.L7F093CE4:
/* 0C8814 7F093CE4 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8818 7F093CE8 E7A6002C */   swc1  $f6, 0x2c($sp)
/* 0C881C 7F093CEC 904F0009 */  lbu   $t7, 9($v0)
/* 0C8820 7F093CF0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8824 7F093CF4 448F5000 */  mtc1  $t7, $f10
/* 0C8828 7F093CF8 05E10004 */  bgez  $t7, .L7F093D0C
/* 0C882C 7F093CFC 46805420 */   cvt.s.w $f16, $f10
/* 0C8830 7F093D00 44819000 */  mtc1  $at, $f18
/* 0C8834 7F093D04 00000000 */  nop
/* 0C8838 7F093D08 46128400 */  add.s $f16, $f16, $f18
.L7F093D0C:
/* 0C883C 7F093D0C 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8840 7F093D10 E7B00028 */   swc1  $f16, 0x28($sp)
/* 0C8844 7F093D14 9058000A */  lbu   $t8, 0xa($v0)
/* 0C8848 7F093D18 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C884C 7F093D1C 44982000 */  mtc1  $t8, $f4
/* 0C8850 7F093D20 07010004 */  bgez  $t8, .L7F093D34
/* 0C8854 7F093D24 46802220 */   cvt.s.w $f8, $f4
/* 0C8858 7F093D28 44813000 */  mtc1  $at, $f6
/* 0C885C 7F093D2C 00000000 */  nop
/* 0C8860 7F093D30 46064200 */  add.s $f8, $f8, $f6
.L7F093D34:
/* 0C8864 7F093D34 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8868 7F093D38 E7A80024 */   swc1  $f8, 0x24($sp)
/* 0C886C 7F093D3C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8870 7F093D40 44811000 */  mtc1  $at, $f2
/* 0C8874 7F093D44 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8878 7F093D48 44818000 */  mtc1  $at, $f16
/* 0C887C 7F093D4C C7AC002C */  lwc1  $f12, 0x2c($sp)
/* 0C8880 7F093D50 C4520014 */  lwc1  $f18, 0x14($v0)
/* 0C8884 7F093D54 C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 0C8888 7F093D58 46106103 */  div.s $f4, $f12, $f16
/* 0C888C 7F093D5C 24080001 */  li    $t0, 1
/* 0C8890 7F093D60 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8894 7F093D64 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C8898 7F093D68 460A1001 */  sub.s $f0, $f2, $f10
/* 0C889C 7F093D6C 46041181 */  sub.s $f6, $f2, $f4
/* 0C88A0 7F093D70 46069202 */  mul.s $f8, $f18, $f6
/* 0C88A4 7F093D74 00000000 */  nop
/* 0C88A8 7F093D78 46004282 */  mul.s $f10, $f8, $f0
/* 0C88AC 7F093D7C 460C5400 */  add.s $f16, $f10, $f12
/* 0C88B0 7F093D80 4459F800 */  cfc1  $t9, $31
/* 0C88B4 7F093D84 44C8F800 */  ctc1  $t0, $31
/* 0C88B8 7F093D88 00000000 */  nop
/* 0C88BC 7F093D8C 46008124 */  cvt.w.s $f4, $f16
/* 0C88C0 7F093D90 4448F800 */  cfc1  $t0, $31
/* 0C88C4 7F093D94 00000000 */  nop
/* 0C88C8 7F093D98 31080078 */  andi  $t0, $t0, 0x78
/* 0C88CC 7F093D9C 11000012 */  beqz  $t0, .L7F093DE8
/* 0C88D0 7F093DA0 00000000 */   nop
/* 0C88D4 7F093DA4 44812000 */  mtc1  $at, $f4
/* 0C88D8 7F093DA8 24080001 */  li    $t0, 1
/* 0C88DC 7F093DAC 46048101 */  sub.s $f4, $f16, $f4
/* 0C88E0 7F093DB0 44C8F800 */  ctc1  $t0, $31
/* 0C88E4 7F093DB4 00000000 */  nop
/* 0C88E8 7F093DB8 46002124 */  cvt.w.s $f4, $f4
/* 0C88EC 7F093DBC 4448F800 */  cfc1  $t0, $31
/* 0C88F0 7F093DC0 00000000 */  nop
/* 0C88F4 7F093DC4 31080078 */  andi  $t0, $t0, 0x78
/* 0C88F8 7F093DC8 15000005 */  bnez  $t0, .L7F093DE0
/* 0C88FC 7F093DCC 00000000 */   nop
/* 0C8900 7F093DD0 44082000 */  mfc1  $t0, $f4
/* 0C8904 7F093DD4 3C018000 */  lui   $at, 0x8000
/* 0C8908 7F093DD8 10000007 */  b     .L7F093DF8
/* 0C890C 7F093DDC 01014025 */   or    $t0, $t0, $at
.L7F093DE0:
/* 0C8910 7F093DE0 10000005 */  b     .L7F093DF8
/* 0C8914 7F093DE4 2408FFFF */   li    $t0, -1
.L7F093DE8:
/* 0C8918 7F093DE8 44082000 */  mfc1  $t0, $f4
/* 0C891C 7F093DEC 00000000 */  nop
/* 0C8920 7F093DF0 0500FFFB */  bltz  $t0, .L7F093DE0
/* 0C8924 7F093DF4 00000000 */   nop
.L7F093DF8:
/* 0C8928 7F093DF8 44D9F800 */  ctc1  $t9, $31
/* 0C892C 7F093DFC A1280014 */  sb    $t0, 0x14($t1)
/* 0C8930 7F093E00 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8934 7F093E04 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 0C8938 7F093E08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C893C 7F093E0C 44819000 */  mtc1  $at, $f18
/* 0C8940 7F093E10 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8944 7F093E14 44813000 */  mtc1  $at, $f6
/* 0C8948 7F093E18 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0C894C 7F093E1C C4500018 */  lwc1  $f16, 0x18($v0)
/* 0C8950 7F093E20 240B0001 */  li    $t3, 1
/* 0C8954 7F093E24 46060203 */  div.s $f8, $f0, $f6
/* 0C8958 7F093E28 C7A6001C */  lwc1  $f6, 0x1c($sp)
/* 0C895C 7F093E2C 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8960 7F093E30 8FAC0030 */  lw    $t4, 0x30($sp)
/* 0C8964 7F093E34 46089281 */  sub.s $f10, $f18, $f8
/* 0C8968 7F093E38 460A8102 */  mul.s $f4, $f16, $f10
/* 0C896C 7F093E3C 00000000 */  nop
/* 0C8970 7F093E40 46062482 */  mul.s $f18, $f4, $f6
/* 0C8974 7F093E44 46009200 */  add.s $f8, $f18, $f0
/* 0C8978 7F093E48 444AF800 */  cfc1  $t2, $31
/* 0C897C 7F093E4C 44CBF800 */  ctc1  $t3, $31
/* 0C8980 7F093E50 00000000 */  nop
/* 0C8984 7F093E54 46004424 */  cvt.w.s $f16, $f8
/* 0C8988 7F093E58 444BF800 */  cfc1  $t3, $31
/* 0C898C 7F093E5C 00000000 */  nop
/* 0C8990 7F093E60 316B0078 */  andi  $t3, $t3, 0x78
/* 0C8994 7F093E64 11600012 */  beqz  $t3, .L7F093EB0
/* 0C8998 7F093E68 00000000 */   nop
/* 0C899C 7F093E6C 44818000 */  mtc1  $at, $f16
/* 0C89A0 7F093E70 240B0001 */  li    $t3, 1
/* 0C89A4 7F093E74 46104401 */  sub.s $f16, $f8, $f16
/* 0C89A8 7F093E78 44CBF800 */  ctc1  $t3, $31
/* 0C89AC 7F093E7C 00000000 */  nop
/* 0C89B0 7F093E80 46008424 */  cvt.w.s $f16, $f16
/* 0C89B4 7F093E84 444BF800 */  cfc1  $t3, $31
/* 0C89B8 7F093E88 00000000 */  nop
/* 0C89BC 7F093E8C 316B0078 */  andi  $t3, $t3, 0x78
/* 0C89C0 7F093E90 15600005 */  bnez  $t3, .L7F093EA8
/* 0C89C4 7F093E94 00000000 */   nop
/* 0C89C8 7F093E98 440B8000 */  mfc1  $t3, $f16
/* 0C89CC 7F093E9C 3C018000 */  lui   $at, 0x8000
/* 0C89D0 7F093EA0 10000007 */  b     .L7F093EC0
/* 0C89D4 7F093EA4 01615825 */   or    $t3, $t3, $at
.L7F093EA8:
/* 0C89D8 7F093EA8 10000005 */  b     .L7F093EC0
/* 0C89DC 7F093EAC 240BFFFF */   li    $t3, -1
.L7F093EB0:
/* 0C89E0 7F093EB0 440B8000 */  mfc1  $t3, $f16
/* 0C89E4 7F093EB4 00000000 */  nop
/* 0C89E8 7F093EB8 0560FFFB */  bltz  $t3, .L7F093EA8
/* 0C89EC 7F093EBC 00000000 */   nop
.L7F093EC0:
/* 0C89F0 7F093EC0 44CAF800 */  ctc1  $t2, $31
/* 0C89F4 7F093EC4 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C89F8 7F093EC8 A18B0015 */   sb    $t3, 0x15($t4)
/* 0C89FC 7F093ECC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8A00 7F093ED0 44815000 */  mtc1  $at, $f10
/* 0C8A04 7F093ED4 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8A08 7F093ED8 44812000 */  mtc1  $at, $f4
/* 0C8A0C 7F093EDC C7A00024 */  lwc1  $f0, 0x24($sp)
/* 0C8A10 7F093EE0 C448001C */  lwc1  $f8, 0x1c($v0)
/* 0C8A14 7F093EE4 240E0001 */  li    $t6, 1
/* 0C8A18 7F093EE8 46040183 */  div.s $f6, $f0, $f4
/* 0C8A1C 7F093EEC C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 0C8A20 7F093EF0 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8A24 7F093EF4 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0C8A28 7F093EF8 241800FF */  li    $t8, 255
/* 0C8A2C 7F093EFC 46065481 */  sub.s $f18, $f10, $f6
/* 0C8A30 7F093F00 46124402 */  mul.s $f16, $f8, $f18
/* 0C8A34 7F093F04 00000000 */  nop
/* 0C8A38 7F093F08 46048282 */  mul.s $f10, $f16, $f4
/* 0C8A3C 7F093F0C 46005180 */  add.s $f6, $f10, $f0
/* 0C8A40 7F093F10 444DF800 */  cfc1  $t5, $31
/* 0C8A44 7F093F14 44CEF800 */  ctc1  $t6, $31
/* 0C8A48 7F093F18 00000000 */  nop
/* 0C8A4C 7F093F1C 46003224 */  cvt.w.s $f8, $f6
/* 0C8A50 7F093F20 444EF800 */  cfc1  $t6, $31
/* 0C8A54 7F093F24 00000000 */  nop
/* 0C8A58 7F093F28 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8A5C 7F093F2C 11C00012 */  beqz  $t6, .L7F093F78
/* 0C8A60 7F093F30 00000000 */   nop
/* 0C8A64 7F093F34 44814000 */  mtc1  $at, $f8
/* 0C8A68 7F093F38 240E0001 */  li    $t6, 1
/* 0C8A6C 7F093F3C 46083201 */  sub.s $f8, $f6, $f8
/* 0C8A70 7F093F40 44CEF800 */  ctc1  $t6, $31
/* 0C8A74 7F093F44 00000000 */  nop
/* 0C8A78 7F093F48 46004224 */  cvt.w.s $f8, $f8
/* 0C8A7C 7F093F4C 444EF800 */  cfc1  $t6, $31
/* 0C8A80 7F093F50 00000000 */  nop
/* 0C8A84 7F093F54 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8A88 7F093F58 15C00005 */  bnez  $t6, .L7F093F70
/* 0C8A8C 7F093F5C 00000000 */   nop
/* 0C8A90 7F093F60 440E4000 */  mfc1  $t6, $f8
/* 0C8A94 7F093F64 3C018000 */  lui   $at, 0x8000
/* 0C8A98 7F093F68 10000007 */  b     .L7F093F88
/* 0C8A9C 7F093F6C 01C17025 */   or    $t6, $t6, $at
.L7F093F70:
/* 0C8AA0 7F093F70 10000005 */  b     .L7F093F88
/* 0C8AA4 7F093F74 240EFFFF */   li    $t6, -1
.L7F093F78:
/* 0C8AA8 7F093F78 440E4000 */  mfc1  $t6, $f8
/* 0C8AAC 7F093F7C 00000000 */  nop
/* 0C8AB0 7F093F80 05C0FFFB */  bltz  $t6, .L7F093F70
/* 0C8AB4 7F093F84 00000000 */   nop
.L7F093F88:
/* 0C8AB8 7F093F88 A1EE0016 */  sb    $t6, 0x16($t7)
/* 0C8ABC 7F093F8C A1F80017 */  sb    $t8, 0x17($t7)
/* 0C8AC0 7F093F90 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C8AC4 7F093F94 44CDF800 */  ctc1  $t5, $31
/* 0C8AC8 7F093F98 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C8ACC 7F093F9C 03E00008 */  jr    $ra
/* 0C8AD0 7F093FA0 00000000 */   nop
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F093FA4(SkyRelated18 *arg0, f32 arg1) {

}
#else
void sub_GAME_7F093FA4(SkyRelated18 *arg0, f32 arg1);
GLOBAL_ASM(
.text
glabel sub_GAME_7F093FA4
/* 0C8AD4 7F093FA4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C8AD8 7F093FA8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C8ADC 7F093FAC AFA40030 */  sw    $a0, 0x30($sp)
/* 0C8AE0 7F093FB0 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8AE4 7F093FB4 AFA50034 */   sw    $a1, 0x34($sp)
/* 0C8AE8 7F093FB8 904E0008 */  lbu   $t6, 8($v0)
/* 0C8AEC 7F093FBC 448E2000 */  mtc1  $t6, $f4
/* 0C8AF0 7F093FC0 05C10005 */  bgez  $t6, .L7F093FD8
/* 0C8AF4 7F093FC4 468021A0 */   cvt.s.w $f6, $f4
/* 0C8AF8 7F093FC8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8AFC 7F093FCC 44814000 */  mtc1  $at, $f8
/* 0C8B00 7F093FD0 00000000 */  nop
/* 0C8B04 7F093FD4 46083180 */  add.s $f6, $f6, $f8
.L7F093FD8:
/* 0C8B08 7F093FD8 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8B0C 7F093FDC E7A6002C */   swc1  $f6, 0x2c($sp)
/* 0C8B10 7F093FE0 904F0009 */  lbu   $t7, 9($v0)
/* 0C8B14 7F093FE4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8B18 7F093FE8 448F5000 */  mtc1  $t7, $f10
/* 0C8B1C 7F093FEC 05E10004 */  bgez  $t7, .L7F094000
/* 0C8B20 7F093FF0 46805420 */   cvt.s.w $f16, $f10
/* 0C8B24 7F093FF4 44819000 */  mtc1  $at, $f18
/* 0C8B28 7F093FF8 00000000 */  nop
/* 0C8B2C 7F093FFC 46128400 */  add.s $f16, $f16, $f18
.L7F094000:
/* 0C8B30 7F094000 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8B34 7F094004 E7B00028 */   swc1  $f16, 0x28($sp)
/* 0C8B38 7F094008 9058000A */  lbu   $t8, 0xa($v0)
/* 0C8B3C 7F09400C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C8B40 7F094010 44982000 */  mtc1  $t8, $f4
/* 0C8B44 7F094014 07010004 */  bgez  $t8, .L7F094028
/* 0C8B48 7F094018 46802220 */   cvt.s.w $f8, $f4
/* 0C8B4C 7F09401C 44813000 */  mtc1  $at, $f6
/* 0C8B50 7F094020 00000000 */  nop
/* 0C8B54 7F094024 46064200 */  add.s $f8, $f8, $f6
.L7F094028:
/* 0C8B58 7F094028 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8B5C 7F09402C E7A80024 */   swc1  $f8, 0x24($sp)
/* 0C8B60 7F094030 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8B64 7F094034 44811000 */  mtc1  $at, $f2
/* 0C8B68 7F094038 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8B6C 7F09403C 44818000 */  mtc1  $at, $f16
/* 0C8B70 7F094040 C7AC002C */  lwc1  $f12, 0x2c($sp)
/* 0C8B74 7F094044 C452002C */  lwc1  $f18, 0x2c($v0)
/* 0C8B78 7F094048 C7AA0034 */  lwc1  $f10, 0x34($sp)
/* 0C8B7C 7F09404C 46106103 */  div.s $f4, $f12, $f16
/* 0C8B80 7F094050 24080001 */  li    $t0, 1
/* 0C8B84 7F094054 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8B88 7F094058 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C8B8C 7F09405C 460A1001 */  sub.s $f0, $f2, $f10
/* 0C8B90 7F094060 46041181 */  sub.s $f6, $f2, $f4
/* 0C8B94 7F094064 46069202 */  mul.s $f8, $f18, $f6
/* 0C8B98 7F094068 00000000 */  nop
/* 0C8B9C 7F09406C 46004282 */  mul.s $f10, $f8, $f0
/* 0C8BA0 7F094070 460C5400 */  add.s $f16, $f10, $f12
/* 0C8BA4 7F094074 4459F800 */  cfc1  $t9, $31
/* 0C8BA8 7F094078 44C8F800 */  ctc1  $t0, $31
/* 0C8BAC 7F09407C 00000000 */  nop
/* 0C8BB0 7F094080 46008124 */  cvt.w.s $f4, $f16
/* 0C8BB4 7F094084 4448F800 */  cfc1  $t0, $31
/* 0C8BB8 7F094088 00000000 */  nop
/* 0C8BBC 7F09408C 31080078 */  andi  $t0, $t0, 0x78
/* 0C8BC0 7F094090 11000012 */  beqz  $t0, .L7F0940DC
/* 0C8BC4 7F094094 00000000 */   nop
/* 0C8BC8 7F094098 44812000 */  mtc1  $at, $f4
/* 0C8BCC 7F09409C 24080001 */  li    $t0, 1
/* 0C8BD0 7F0940A0 46048101 */  sub.s $f4, $f16, $f4
/* 0C8BD4 7F0940A4 44C8F800 */  ctc1  $t0, $31
/* 0C8BD8 7F0940A8 00000000 */  nop
/* 0C8BDC 7F0940AC 46002124 */  cvt.w.s $f4, $f4
/* 0C8BE0 7F0940B0 4448F800 */  cfc1  $t0, $31
/* 0C8BE4 7F0940B4 00000000 */  nop
/* 0C8BE8 7F0940B8 31080078 */  andi  $t0, $t0, 0x78
/* 0C8BEC 7F0940BC 15000005 */  bnez  $t0, .L7F0940D4
/* 0C8BF0 7F0940C0 00000000 */   nop
/* 0C8BF4 7F0940C4 44082000 */  mfc1  $t0, $f4
/* 0C8BF8 7F0940C8 3C018000 */  lui   $at, 0x8000
/* 0C8BFC 7F0940CC 10000007 */  b     .L7F0940EC
/* 0C8C00 7F0940D0 01014025 */   or    $t0, $t0, $at
.L7F0940D4:
/* 0C8C04 7F0940D4 10000005 */  b     .L7F0940EC
/* 0C8C08 7F0940D8 2408FFFF */   li    $t0, -1
.L7F0940DC:
/* 0C8C0C 7F0940DC 44082000 */  mfc1  $t0, $f4
/* 0C8C10 7F0940E0 00000000 */  nop
/* 0C8C14 7F0940E4 0500FFFB */  bltz  $t0, .L7F0940D4
/* 0C8C18 7F0940E8 00000000 */   nop
.L7F0940EC:
/* 0C8C1C 7F0940EC 44D9F800 */  ctc1  $t9, $31
/* 0C8C20 7F0940F0 A1280014 */  sb    $t0, 0x14($t1)
/* 0C8C24 7F0940F4 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8C28 7F0940F8 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 0C8C2C 7F0940FC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8C30 7F094100 44819000 */  mtc1  $at, $f18
/* 0C8C34 7F094104 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8C38 7F094108 44813000 */  mtc1  $at, $f6
/* 0C8C3C 7F09410C C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0C8C40 7F094110 C4500030 */  lwc1  $f16, 0x30($v0)
/* 0C8C44 7F094114 240B0001 */  li    $t3, 1
/* 0C8C48 7F094118 46060203 */  div.s $f8, $f0, $f6
/* 0C8C4C 7F09411C C7A6001C */  lwc1  $f6, 0x1c($sp)
/* 0C8C50 7F094120 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8C54 7F094124 8FAC0030 */  lw    $t4, 0x30($sp)
/* 0C8C58 7F094128 46089281 */  sub.s $f10, $f18, $f8
/* 0C8C5C 7F09412C 460A8102 */  mul.s $f4, $f16, $f10
/* 0C8C60 7F094130 00000000 */  nop
/* 0C8C64 7F094134 46062482 */  mul.s $f18, $f4, $f6
/* 0C8C68 7F094138 46009200 */  add.s $f8, $f18, $f0
/* 0C8C6C 7F09413C 444AF800 */  cfc1  $t2, $31
/* 0C8C70 7F094140 44CBF800 */  ctc1  $t3, $31
/* 0C8C74 7F094144 00000000 */  nop
/* 0C8C78 7F094148 46004424 */  cvt.w.s $f16, $f8
/* 0C8C7C 7F09414C 444BF800 */  cfc1  $t3, $31
/* 0C8C80 7F094150 00000000 */  nop
/* 0C8C84 7F094154 316B0078 */  andi  $t3, $t3, 0x78
/* 0C8C88 7F094158 11600012 */  beqz  $t3, .L7F0941A4
/* 0C8C8C 7F09415C 00000000 */   nop
/* 0C8C90 7F094160 44818000 */  mtc1  $at, $f16
/* 0C8C94 7F094164 240B0001 */  li    $t3, 1
/* 0C8C98 7F094168 46104401 */  sub.s $f16, $f8, $f16
/* 0C8C9C 7F09416C 44CBF800 */  ctc1  $t3, $31
/* 0C8CA0 7F094170 00000000 */  nop
/* 0C8CA4 7F094174 46008424 */  cvt.w.s $f16, $f16
/* 0C8CA8 7F094178 444BF800 */  cfc1  $t3, $31
/* 0C8CAC 7F09417C 00000000 */  nop
/* 0C8CB0 7F094180 316B0078 */  andi  $t3, $t3, 0x78
/* 0C8CB4 7F094184 15600005 */  bnez  $t3, .L7F09419C
/* 0C8CB8 7F094188 00000000 */   nop
/* 0C8CBC 7F09418C 440B8000 */  mfc1  $t3, $f16
/* 0C8CC0 7F094190 3C018000 */  lui   $at, 0x8000
/* 0C8CC4 7F094194 10000007 */  b     .L7F0941B4
/* 0C8CC8 7F094198 01615825 */   or    $t3, $t3, $at
.L7F09419C:
/* 0C8CCC 7F09419C 10000005 */  b     .L7F0941B4
/* 0C8CD0 7F0941A0 240BFFFF */   li    $t3, -1
.L7F0941A4:
/* 0C8CD4 7F0941A4 440B8000 */  mfc1  $t3, $f16
/* 0C8CD8 7F0941A8 00000000 */  nop
/* 0C8CDC 7F0941AC 0560FFFB */  bltz  $t3, .L7F09419C
/* 0C8CE0 7F0941B0 00000000 */   nop
.L7F0941B4:
/* 0C8CE4 7F0941B4 44CAF800 */  ctc1  $t2, $31
/* 0C8CE8 7F0941B8 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8CEC 7F0941BC A18B0015 */   sb    $t3, 0x15($t4)
/* 0C8CF0 7F0941C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C8CF4 7F0941C4 44815000 */  mtc1  $at, $f10
/* 0C8CF8 7F0941C8 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0C8CFC 7F0941CC 44812000 */  mtc1  $at, $f4
/* 0C8D00 7F0941D0 C7A00024 */  lwc1  $f0, 0x24($sp)
/* 0C8D04 7F0941D4 C4480034 */  lwc1  $f8, 0x34($v0)
/* 0C8D08 7F0941D8 240E0001 */  li    $t6, 1
/* 0C8D0C 7F0941DC 46040183 */  div.s $f6, $f0, $f4
/* 0C8D10 7F0941E0 C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 0C8D14 7F0941E4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0C8D18 7F0941E8 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0C8D1C 7F0941EC 241800FF */  li    $t8, 255
/* 0C8D20 7F0941F0 46065481 */  sub.s $f18, $f10, $f6
/* 0C8D24 7F0941F4 46124402 */  mul.s $f16, $f8, $f18
/* 0C8D28 7F0941F8 00000000 */  nop
/* 0C8D2C 7F0941FC 46048282 */  mul.s $f10, $f16, $f4
/* 0C8D30 7F094200 46005180 */  add.s $f6, $f10, $f0
/* 0C8D34 7F094204 444DF800 */  cfc1  $t5, $31
/* 0C8D38 7F094208 44CEF800 */  ctc1  $t6, $31
/* 0C8D3C 7F09420C 00000000 */  nop
/* 0C8D40 7F094210 46003224 */  cvt.w.s $f8, $f6
/* 0C8D44 7F094214 444EF800 */  cfc1  $t6, $31
/* 0C8D48 7F094218 00000000 */  nop
/* 0C8D4C 7F09421C 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8D50 7F094220 11C00012 */  beqz  $t6, .L7F09426C
/* 0C8D54 7F094224 00000000 */   nop
/* 0C8D58 7F094228 44814000 */  mtc1  $at, $f8
/* 0C8D5C 7F09422C 240E0001 */  li    $t6, 1
/* 0C8D60 7F094230 46083201 */  sub.s $f8, $f6, $f8
/* 0C8D64 7F094234 44CEF800 */  ctc1  $t6, $31
/* 0C8D68 7F094238 00000000 */  nop
/* 0C8D6C 7F09423C 46004224 */  cvt.w.s $f8, $f8
/* 0C8D70 7F094240 444EF800 */  cfc1  $t6, $31
/* 0C8D74 7F094244 00000000 */  nop
/* 0C8D78 7F094248 31CE0078 */  andi  $t6, $t6, 0x78
/* 0C8D7C 7F09424C 15C00005 */  bnez  $t6, .L7F094264
/* 0C8D80 7F094250 00000000 */   nop
/* 0C8D84 7F094254 440E4000 */  mfc1  $t6, $f8
/* 0C8D88 7F094258 3C018000 */  lui   $at, 0x8000
/* 0C8D8C 7F09425C 10000007 */  b     .L7F09427C
/* 0C8D90 7F094260 01C17025 */   or    $t6, $t6, $at
.L7F094264:
/* 0C8D94 7F094264 10000005 */  b     .L7F09427C
/* 0C8D98 7F094268 240EFFFF */   li    $t6, -1
.L7F09426C:
/* 0C8D9C 7F09426C 440E4000 */  mfc1  $t6, $f8
/* 0C8DA0 7F094270 00000000 */  nop
/* 0C8DA4 7F094274 05C0FFFB */  bltz  $t6, .L7F094264
/* 0C8DA8 7F094278 00000000 */   nop
.L7F09427C:
/* 0C8DAC 7F09427C A1EE0016 */  sb    $t6, 0x16($t7)
/* 0C8DB0 7F094280 A1F80017 */  sb    $t8, 0x17($t7)
/* 0C8DB4 7F094284 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C8DB8 7F094288 44CDF800 */  ctc1  $t5, $31
/* 0C8DBC 7F09428C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C8DC0 7F094290 03E00008 */  jr    $ra
/* 0C8DC4 7F094294 00000000 */   nop
)
#endif


u32 sub_GAME_7F094298(f32 arg0)
{
    u32 result;

    if (arg0 > 32767.9f) { arg0 = 32767.9f; }
    if (arg0 < -32767.9f) { arg0 = -32767.9f; }

    if (arg0 < 0)
    {
        result = arg0 * -65536;
        result = -result;
    }
    else
    {
        result = 65536 * arg0;
    }

    return result;
}


void store_stagenum_to_copyof_stagenum(s32 stagenum) {
  copyof_stagenum = stagenum;
}


void sub_GAME_7F094438(void)
{
    #if defined(VERSION_EU)
    g_SkyCloudOffset += g_GlobalTimerDelta;
    #else
    g_SkyCloudOffset += g_ClockTimer;
    #endif
    if ( g_SkyCloudOffset > 4096.0f)
    {
        g_SkyCloudOffset -= 4096.0f;
    }
}

Gfx *skyRender(Gfx *gdl)
{
    coord3d sp6a4;
    coord3d sp698;
    coord3d sp68c;
    coord3d sp680;
    coord3d sp674;
    coord3d sp668;
    coord3d sp65c;
    coord3d sp650;
    coord3d sp644;
    coord3d sp638;
    coord3d sp62c;
    coord3d sp620;
    coord3d sp614;
    coord3d sp608;
    coord3d sp5fc;
    coord3d sp5f0;
    coord3d sp5e4;
    coord3d sp5d8;
    coord3d sp5cc;
    coord3d sp5c0;
    coord3d sp5b4;
    coord3d sp5a8;
    coord3d sp59c;
    coord3d sp590;
    f32 sp58c;
    f32 sp588;
    f32 sp584;
    f32 sp580;
    f32 sp57c;
    f32 sp578;
    f32 sp574;
    f32 sp570;
    f32 sp56c;
    f32 sp568;
    f32 sp564;
    f32 sp560;
    f32 sp55c;
    f32 sp558;
    f32 sp554;
    f32 sp550;
    f32 sp54c;
    f32 sp548;
    s32 s1;
    s32 j;
    s32 k;
    s32 sp538;
    s32 sp534;
    s32 sp530;
    s32 sp52c;
    SkyRelated18 sp4b4[5];
    SkyRelated18 sp43c[5];
    f32 tmp;
    f32 scale;
    bool sp430;
    struct CurrentEnvironmentRecord *env;

    scale = get_room_data_float1() / 30.0f;
    sp430 = FALSE;
    env = fogGetCurrentEnvironmentp();

    if (!fogGetCurrentEnvironmentp()->Clouds)
    {
        if (getPlayerCount() == 1)
        {
            gDPSetCycleType(gdl++, G_CYC_FILL);

            gdl = viSetFillColor(gdl, env->Red, env->Green, env->Blue);

            gDPFillRectangle(gdl++, viGetViewLeft(), viGetViewTop(),
                    viGetViewLeft() + viGetViewWidth() - 1,
                    viGetViewTop() + viGetViewHeight() - 1);

            gDPPipeSync(gdl++);
            return gdl;
        }

        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_FILL);

        gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);

        gDPFillRectangle(gdl++,
                g_CurrentPlayer->viewleft, g_CurrentPlayer->viewtop,
                (g_CurrentPlayer->viewleft + g_CurrentPlayer->viewx) - 1,
                (g_CurrentPlayer->viewtop + g_CurrentPlayer->viewy) - 1);

        gDPPipeSync(gdl++);
        return gdl;
    }

    gdl = viSetFillColor(gdl, env->Red, env->Green, env->Blue);

    if (&sp6a4);

    sub_GAME_7F093880(0.0f, 0.0f, &sp6a4);
    sub_GAME_7F093880(getPlayer_c_screenwidth() - 0.1f, 0.0f, &sp698);
    sub_GAME_7F093880(0.0f, getPlayer_c_screenheight() - 0.1f, &sp68c);
    sub_GAME_7F093880(getPlayer_c_screenwidth() - 0.1f, getPlayer_c_screenheight() - 0.1f, &sp680);

    sp538 = sub_GAME_7F0938FC(&sp6a4, &sp644, &sp58c);
    sp534 = sub_GAME_7F0938FC(&sp698, &sp638, &sp588);
    sp530 = sub_GAME_7F0938FC(&sp68c, &sp62c, &sp584);
    sp52c = sub_GAME_7F0938FC(&sp680, &sp620, &sp580);

    sub_GAME_7F093A78(&sp6a4, &sp5e4, &sp56c);
    sub_GAME_7F093A78(&sp698, &sp5d8, &sp568);
    sub_GAME_7F093A78(&sp68c, &sp5cc, &sp564);
    sub_GAME_7F093A78(&sp680, &sp5c0, &sp560);

    if (sp538 != sp530)
    {
        sp54c = getPlayer_c_screentop() + getPlayer_c_screenheight() * (sp6a4.f[1] / (sp6a4.f[1] - sp68c.f[1]));

        sub_GAME_7F093880(0.0f, sp54c, &sp65c);
        sub_GAME_7F093BFC(&sp6a4, &sp68c, &sp65c);
        sub_GAME_7F0938FC(&sp65c, &sp5fc, &sp574);
        sub_GAME_7F093A78(&sp65c, &sp59c, &sp554);
    }
    else
    {
        sp54c = 0.0f;
    }

    if (sp534 != sp52c)
    {
        sp548 = getPlayer_c_screentop() + getPlayer_c_screenheight() * (sp698.f[1] / (sp698.f[1] - sp680.f[1]));

        sub_GAME_7F093880(getPlayer_c_screenwidth() - 0.1f, sp548, &sp650);
        sub_GAME_7F093BFC(&sp698, &sp680, &sp650);
        sub_GAME_7F0938FC(&sp650, &sp5f0, &sp570);
        sub_GAME_7F093A78(&sp650, &sp590, &sp550);
    }
    else
    {
        sp548 = 0.0f;
    }

    if (sp538 != sp534)
    {
        sub_GAME_7F093880(getPlayer_c_screenleft() + getPlayer_c_screenwidth() * (sp6a4.f[1] / (sp6a4.f[1] - sp698.f[1])), 0.0f, &sp674);
        sub_GAME_7F093BFC(&sp6a4, &sp698, &sp674);
        sub_GAME_7F0938FC(&sp674, &sp614, &sp57c);
        sub_GAME_7F093A78(&sp674, &sp5b4, &sp55c);
    }

    if (sp530 != sp52c)
    {
        tmp = getPlayer_c_screenleft() + getPlayer_c_screenwidth() * (sp68c.f[1] / (sp68c.f[1] - sp680.f[1]));

        sub_GAME_7F093880(tmp, getPlayer_c_screenheight() - 0.1f, &sp668);
        sub_GAME_7F093BFC(&sp68c, &sp680, &sp668);
        sub_GAME_7F0938FC(&sp668, &sp608, &sp578);
        sub_GAME_7F093A78(&sp668, &sp5a8, &sp558);
    }

    switch ((sp538 << 3) | (sp534 << 2) | (sp530 << 1) | sp52c)
    {
        case 15:
            s1 = 0;
            break;

        case 0:
            s1 = 4;
            sp43c[0].unk00 = sp5e4.f[0] * scale;
            sp43c[0].unk04 = sp5e4.f[1] * scale;
            sp43c[0].unk08 = sp5e4.f[2] * scale;
            sp43c[1].unk00 = sp5d8.f[0] * scale;
            sp43c[1].unk04 = sp5d8.f[1] * scale;
            sp43c[1].unk08 = sp5d8.f[2] * scale;
            sp43c[2].unk00 = sp5cc.f[0] * scale;
            sp43c[2].unk04 = sp5cc.f[1] * scale;
            sp43c[2].unk08 = sp5cc.f[2] * scale;
            sp43c[3].unk00 = sp5c0.f[0] * scale;
            sp43c[3].unk04 = sp5c0.f[1] * scale;
            sp43c[3].unk08 = sp5c0.f[2] * scale;
            sp43c[0].unk0c = sp5e4.f[0];
            sp43c[0].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5d8.f[0];
            sp43c[1].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5cc.f[0];
            sp43c[2].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp5c0.f[0];
            sp43c[3].unk10 = sp5c0.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp56c);
            sub_GAME_7F093FA4(&sp43c[1], sp568);
            sub_GAME_7F093FA4(&sp43c[2], sp564);
            sub_GAME_7F093FA4(&sp43c[3], sp560);
            break;

        case 3:
            s1 = 4;
            sp43c[0].unk00 = sp5e4.f[0] * scale;
            sp43c[0].unk04 = sp5e4.f[1] * scale;
            sp43c[0].unk08 = sp5e4.f[2] * scale;
            sp43c[1].unk00 = sp5d8.f[0] * scale;
            sp43c[1].unk04 = sp5d8.f[1] * scale;
            sp43c[1].unk08 = sp5d8.f[2] * scale;
            sp43c[2].unk00 = sp59c.f[0] * scale;
            sp43c[2].unk04 = sp59c.f[1] * scale;
            sp43c[2].unk08 = sp59c.f[2] * scale;
            sp43c[3].unk00 = sp590.f[0] * scale;
            sp43c[3].unk04 = sp590.f[1] * scale;
            sp43c[3].unk08 = sp590.f[2] * scale;
            sp43c[0].unk0c = sp5e4.f[0];
            sp43c[0].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5d8.f[0];
            sp43c[1].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp59c.f[0];
            sp43c[2].unk10 = sp59c.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp590.f[0];
            sp43c[3].unk10 = sp590.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp56c);
            sub_GAME_7F093FA4(&sp43c[1], sp568);
            sub_GAME_7F093FA4(&sp43c[2], sp554);
            sub_GAME_7F093FA4(&sp43c[3], sp550);
            break;

        case 12:
            s1 = 4;
            sp430 = TRUE;
            sp43c[0].unk00 = sp5c0.f[0] * scale;
            sp43c[0].unk04 = sp5c0.f[1] * scale;
            sp43c[0].unk08 = sp5c0.f[2] * scale;
            sp43c[1].unk00 = sp5cc.f[0] * scale;
            sp43c[1].unk04 = sp5cc.f[1] * scale;
            sp43c[1].unk08 = sp5cc.f[2] * scale;
            sp43c[2].unk00 = sp590.f[0] * scale;
            sp43c[2].unk04 = sp590.f[1] * scale;
            sp43c[2].unk08 = sp590.f[2] * scale;
            sp43c[3].unk00 = sp59c.f[0] * scale;
            sp43c[3].unk04 = sp59c.f[1] * scale;
            sp43c[3].unk08 = sp59c.f[2] * scale;
            sp43c[0].unk0c = sp5c0.f[0];
            sp43c[0].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5cc.f[0];
            sp43c[1].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp590.f[0];
            sp43c[2].unk10 = sp590.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp59c.f[0];
            sp43c[3].unk10 = sp59c.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp560);
            sub_GAME_7F093FA4(&sp43c[1], sp564);
            sub_GAME_7F093FA4(&sp43c[2], sp550);
            sub_GAME_7F093FA4(&sp43c[3], sp554);
            break;

        case 10:
            s1 = 4;
            sp43c[0].unk00 = sp5d8.f[0] * scale;
            sp43c[0].unk04 = sp5d8.f[1] * scale;
            sp43c[0].unk08 = sp5d8.f[2] * scale;
            sp43c[1].unk00 = sp5c0.f[0] * scale;
            sp43c[1].unk04 = sp5c0.f[1] * scale;
            sp43c[1].unk08 = sp5c0.f[2] * scale;
            sp43c[2].unk00 = sp5b4.f[0] * scale;
            sp43c[2].unk04 = sp5b4.f[1] * scale;
            sp43c[2].unk08 = sp5b4.f[2] * scale;
            sp43c[3].unk00 = sp5a8.f[0] * scale;
            sp43c[3].unk04 = sp5a8.f[1] * scale;
            sp43c[3].unk08 = sp5a8.f[2] * scale;
            sp43c[0].unk0c = sp5d8.f[0];
            sp43c[0].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5c0.f[0];
            sp43c[1].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5b4.f[0];
            sp43c[2].unk10 = sp5b4.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp5a8.f[0];
            sp43c[3].unk10 = sp5a8.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp568);
            sub_GAME_7F093FA4(&sp43c[1], sp560);
            sub_GAME_7F093FA4(&sp43c[2], sp55c);
            sub_GAME_7F093FA4(&sp43c[3], sp558);
            break;

        case 5:
            s1 = 4;
            sp43c[0].unk00 = sp5cc.f[0] * scale;
            sp43c[0].unk04 = sp5cc.f[1] * scale;
            sp43c[0].unk08 = sp5cc.f[2] * scale;
            sp43c[1].unk00 = sp5e4.f[0] * scale;
            sp43c[1].unk04 = sp5e4.f[1] * scale;
            sp43c[1].unk08 = sp5e4.f[2] * scale;
            sp43c[2].unk00 = sp5a8.f[0] * scale;
            sp43c[2].unk04 = sp5a8.f[1] * scale;
            sp43c[2].unk08 = sp5a8.f[2] * scale;
            sp43c[3].unk00 = sp5b4.f[0] * scale;
            sp43c[3].unk04 = sp5b4.f[1] * scale;
            sp43c[3].unk08 = sp5b4.f[2] * scale;
            sp43c[0].unk0c = sp5cc.f[0];
            sp43c[0].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5e4.f[0];
            sp43c[1].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5a8.f[0];
            sp43c[2].unk10 = sp5a8.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp5b4.f[0];
            sp43c[3].unk10 = sp5b4.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp564);
            sub_GAME_7F093FA4(&sp43c[1], sp56c);
            sub_GAME_7F093FA4(&sp43c[2], sp558);
            sub_GAME_7F093FA4(&sp43c[3], sp55c);
            break;

        case 14:
            s1 = 3;
            sp43c[0].unk00 = sp5c0.f[0] * scale;
            sp43c[0].unk04 = sp5c0.f[1] * scale;
            sp43c[0].unk08 = sp5c0.f[2] * scale;
            sp43c[1].unk00 = sp5a8.f[0] * scale;
            sp43c[1].unk04 = sp5a8.f[1] * scale;
            sp43c[1].unk08 = sp5a8.f[2] * scale;
            sp43c[2].unk00 = sp590.f[0] * scale;
            sp43c[2].unk04 = sp590.f[1] * scale;
            sp43c[2].unk08 = sp590.f[2] * scale;
            sp43c[0].unk0c = sp5c0.f[0];
            sp43c[0].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5a8.f[0];
            sp43c[1].unk10 = sp5a8.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp590.f[0];
            sp43c[2].unk10 = sp590.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp560);
            sub_GAME_7F093FA4(&sp43c[1], sp558);
            sub_GAME_7F093FA4(&sp43c[2], sp550);
            break;

        case 13:
            s1 = 3;
            sp43c[0].unk00 = sp5cc.f[0] * scale;
            sp43c[0].unk04 = sp5cc.f[1] * scale;
            sp43c[0].unk08 = sp5cc.f[2] * scale;
            sp43c[1].unk00 = sp59c.f[0] * scale;
            sp43c[1].unk04 = sp59c.f[1] * scale;
            sp43c[1].unk08 = sp59c.f[2] * scale;
            sp43c[2].unk00 = sp5a8.f[0] * scale;
            sp43c[2].unk04 = sp5a8.f[1] * scale;
            sp43c[2].unk08 = sp5a8.f[2] * scale;
            sp43c[0].unk0c = sp5cc.f[0];
            sp43c[0].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp59c.f[0];
            sp43c[1].unk10 = sp59c.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5a8.f[0];
            sp43c[2].unk10 = sp5a8.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp564);
            sub_GAME_7F093FA4(&sp43c[1], sp554);
            sub_GAME_7F093FA4(&sp43c[2], sp558);
            break;

        case 11:
            s1 = 3;
            sp43c[0].unk00 = sp5d8.f[0] * scale;
            sp43c[0].unk04 = sp5d8.f[1] * scale;
            sp43c[0].unk08 = sp5d8.f[2] * scale;
            sp43c[1].unk00 = sp590.f[0] * scale;
            sp43c[1].unk04 = sp590.f[1] * scale;
            sp43c[1].unk08 = sp590.f[2] * scale;
            sp43c[2].unk00 = sp5b4.f[0] * scale;
            sp43c[2].unk04 = sp5b4.f[1] * scale;
            sp43c[2].unk08 = sp5b4.f[2] * scale;
            sp43c[0].unk0c = sp5d8.f[0];
            sp43c[0].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp590.f[0];
            sp43c[1].unk10 = sp590.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5b4.f[0];
            sp43c[2].unk10 = sp5b4.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp568);
            sub_GAME_7F093FA4(&sp43c[1], sp550);
            sub_GAME_7F093FA4(&sp43c[2], sp55c);
            break;

        case 7:
            s1 = 3;
            sp43c[0].unk00 = sp5e4.f[0] * scale;
            sp43c[0].unk04 = sp5e4.f[1] * scale;
            sp43c[0].unk08 = sp5e4.f[2] * scale;
            sp43c[1].unk00 = sp5b4.f[0] * scale;
            sp43c[1].unk04 = sp5b4.f[1] * scale;
            sp43c[1].unk08 = sp5b4.f[2] * scale;
            sp43c[2].unk00 = sp59c.f[0] * scale;
            sp43c[2].unk04 = sp59c.f[1] * scale;
            sp43c[2].unk08 = sp59c.f[2] * scale;
            sp43c[0].unk0c = sp5e4.f[0];
            sp43c[0].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5b4.f[0];
            sp43c[1].unk10 = sp5b4.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp59c.f[0];
            sp43c[2].unk10 = sp59c.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp56c);
            sub_GAME_7F093FA4(&sp43c[1], sp55c);
            sub_GAME_7F093FA4(&sp43c[2], sp554);
            break;

        case 1:
            s1 = 5;
            sp43c[0].unk00 = sp5cc.f[0] * scale;
            sp43c[0].unk04 = sp5cc.f[1] * scale;
            sp43c[0].unk08 = sp5cc.f[2] * scale;
            sp43c[1].unk00 = sp5e4.f[0] * scale;
            sp43c[1].unk04 = sp5e4.f[1] * scale;
            sp43c[1].unk08 = sp5e4.f[2] * scale;
            sp43c[2].unk00 = sp5d8.f[0] * scale;
            sp43c[2].unk04 = sp5d8.f[1] * scale;
            sp43c[2].unk08 = sp5d8.f[2] * scale;
            sp43c[3].unk00 = sp590.f[0] * scale;
            sp43c[3].unk04 = sp590.f[1] * scale;
            sp43c[3].unk08 = sp590.f[2] * scale;
            sp43c[4].unk00 = sp5a8.f[0] * scale;
            sp43c[4].unk04 = sp5a8.f[1] * scale;
            sp43c[4].unk08 = sp5a8.f[2] * scale;
            sp43c[0].unk0c = sp5cc.f[0];
            sp43c[0].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5e4.f[0];
            sp43c[1].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5d8.f[0];
            sp43c[2].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp590.f[0];
            sp43c[3].unk10 = sp590.f[2] + g_SkyCloudOffset;
            sp43c[4].unk0c = sp5a8.f[0];
            sp43c[4].unk10 = sp5a8.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp564);
            sub_GAME_7F093FA4(&sp43c[1], sp56c);
            sub_GAME_7F093FA4(&sp43c[2], sp568);
            sub_GAME_7F093FA4(&sp43c[3], sp550);
            sub_GAME_7F093FA4(&sp43c[4], sp558);
            break;

        case 2:
            s1 = 5;
            sp43c[0].unk00 = sp5e4.f[0] * scale;
            sp43c[0].unk04 = sp5e4.f[1] * scale;
            sp43c[0].unk08 = sp5e4.f[2] * scale;
            sp43c[1].unk00 = sp5d8.f[0] * scale;
            sp43c[1].unk04 = sp5d8.f[1] * scale;
            sp43c[1].unk08 = sp5d8.f[2] * scale;
            sp43c[2].unk00 = sp5c0.f[0] * scale;
            sp43c[2].unk04 = sp5c0.f[1] * scale;
            sp43c[2].unk08 = sp5c0.f[2] * scale;
            sp43c[3].unk00 = sp5a8.f[0] * scale;
            sp43c[3].unk04 = sp5a8.f[1] * scale;
            sp43c[3].unk08 = sp5a8.f[2] * scale;
            sp43c[4].unk00 = sp59c.f[0] * scale;
            sp43c[4].unk04 = sp59c.f[1] * scale;
            sp43c[4].unk08 = sp59c.f[2] * scale;
            sp43c[0].unk0c = sp5e4.f[0];
            sp43c[0].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5d8.f[0];
            sp43c[1].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5c0.f[0];
            sp43c[2].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp5a8.f[0];
            sp43c[3].unk10 = sp5a8.f[2] + g_SkyCloudOffset;
            sp43c[4].unk0c = sp59c.f[0];
            sp43c[4].unk10 = sp59c.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp56c);
            sub_GAME_7F093FA4(&sp43c[1], sp568);
            sub_GAME_7F093FA4(&sp43c[2], sp560);
            sub_GAME_7F093FA4(&sp43c[3], sp558);
            sub_GAME_7F093FA4(&sp43c[4], sp554);
            break;

        case 4:
            s1 = 5;
            sp43c[0].unk00 = sp5c0.f[0] * scale;
            sp43c[0].unk04 = sp5c0.f[1] * scale;
            sp43c[0].unk08 = sp5c0.f[2] * scale;
            sp43c[1].unk00 = sp5cc.f[0] * scale;
            sp43c[1].unk04 = sp5cc.f[1] * scale;
            sp43c[1].unk08 = sp5cc.f[2] * scale;
            sp43c[2].unk00 = sp5e4.f[0] * scale;
            sp43c[2].unk04 = sp5e4.f[1] * scale;
            sp43c[2].unk08 = sp5e4.f[2] * scale;
            sp43c[3].unk00 = sp5b4.f[0] * scale;
            sp43c[3].unk04 = sp5b4.f[1] * scale;
            sp43c[3].unk08 = sp5b4.f[2] * scale;
            sp43c[4].unk00 = sp590.f[0] * scale;
            sp43c[4].unk04 = sp590.f[1] * scale;
            sp43c[4].unk08 = sp590.f[2] * scale;
            sp43c[0].unk0c = sp5c0.f[0];
            sp43c[0].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5cc.f[0];
            sp43c[1].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5e4.f[0];
            sp43c[2].unk10 = sp5e4.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp5b4.f[0];
            sp43c[3].unk10 = sp5b4.f[2] + g_SkyCloudOffset;
            sp43c[4].unk0c = sp590.f[0];
            sp43c[4].unk10 = sp590.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp560);
            sub_GAME_7F093FA4(&sp43c[1], sp564);
            sub_GAME_7F093FA4(&sp43c[2], sp56c);
            sub_GAME_7F093FA4(&sp43c[3], sp55c);
            sub_GAME_7F093FA4(&sp43c[4], sp550);
            break;

        case 8:
            s1 = 5;
            sp43c[0].unk00 = sp5d8.f[0] * scale;
            sp43c[0].unk04 = sp5d8.f[1] * scale;
            sp43c[0].unk08 = sp5d8.f[2] * scale;
            sp43c[1].unk00 = sp5c0.f[0] * scale;
            sp43c[1].unk04 = sp5c0.f[1] * scale;
            sp43c[1].unk08 = sp5c0.f[2] * scale;
            sp43c[2].unk00 = sp5cc.f[0] * scale;
            sp43c[2].unk04 = sp5cc.f[1] * scale;
            sp43c[2].unk08 = sp5cc.f[2] * scale;
            sp43c[3].unk00 = sp59c.f[0] * scale;
            sp43c[3].unk04 = sp59c.f[1] * scale;
            sp43c[3].unk08 = sp59c.f[2] * scale;
            sp43c[4].unk00 = sp5b4.f[0] * scale;
            sp43c[4].unk04 = sp5b4.f[1] * scale;
            sp43c[4].unk08 = sp5b4.f[2] * scale;
            sp43c[0].unk0c = sp5d8.f[0];
            sp43c[0].unk10 = sp5d8.f[2] + g_SkyCloudOffset;
            sp43c[1].unk0c = sp5c0.f[0];
            sp43c[1].unk10 = sp5c0.f[2] + g_SkyCloudOffset;
            sp43c[2].unk0c = sp5cc.f[0];
            sp43c[2].unk10 = sp5cc.f[2] + g_SkyCloudOffset;
            sp43c[3].unk0c = sp59c.f[0];
            sp43c[3].unk10 = sp59c.f[2] + g_SkyCloudOffset;
            sp43c[4].unk0c = sp5b4.f[0];
            sp43c[4].unk10 = sp5b4.f[2] + g_SkyCloudOffset;

            sub_GAME_7F093FA4(&sp43c[0], sp568);
            sub_GAME_7F093FA4(&sp43c[1], sp560);
            sub_GAME_7F093FA4(&sp43c[2], sp564);
            sub_GAME_7F093FA4(&sp43c[3], sp554);
            sub_GAME_7F093FA4(&sp43c[4], sp55c);
            break;

        default:
            return gdl;
    }

    if (s1 > 0)
    {
        Mtxf sp3cc;
        Mtxf sp38c;
        SkyRelated38 sp274[5];
        s32 i;
        s32 unused[3];

        matrix_4x4_multiply(currentPlayerGetProjectionMatrixF(), currentPlayerGetMatrix10CC(), &sp3cc);
        guScaleF(dword_CODE_bss_80079E98.m, 1.0f / scale, 1.0f / scale, 1.0f / scale);
        matrix_4x4_multiply(&sp3cc, &dword_CODE_bss_80079E98, &sp38c);

        for (i = 0; i < s1; i++)
        {
            sub_GAME_7F097388(&sp43c[i], &sp38c, 130, 65535.0f, 65535.0f, &sp274[i]);

            sp274[i].unk28 = sub_GAME_7F093C48(sp274[i].unk28, getPlayer_c_screenleft() * 4.0f, (getPlayer_c_screenleft() + getPlayer_c_screenwidth()) * 4.0f - 1.0f);
            sp274[i].unk2c = sub_GAME_7F093C48(sp274[i].unk2c, getPlayer_c_screentop() * 4.0f, (getPlayer_c_screentop() + getPlayer_c_screenheight()) * 4.0f - 1.0f);

            if (sp274[i].unk2c > getPlayer_c_screentop() * 4.0f + 4.0f
                    && sp274[i].unk2c < (getPlayer_c_screentop() + getPlayer_c_screenheight()) * 4.0f - 4.0f)
            {
                sp274[i].unk2c -= 4.0f;
            }
        }

        if (!fogGetCurrentEnvironmentp()->IsWater)
        {
            f32 f14 = 1279.0f;
            f32 f2 = 0.0f;
            f32 f16 = 959.0f;
            f32 f12 = 0.0f;

            for (j = 0; j < s1; j++)
            {
                if (sp274[j].unk28 < f14) { f14 = sp274[j].unk28; }
                if (sp274[j].unk28 > f2) { f2 = sp274[j].unk28; }

                if (sp274[j].unk2c < f16) { f16 = sp274[j].unk2c; }
                if (sp274[j].unk2c > f12) { f12 = sp274[j].unk2c; }
            }

            gDPPipeSync(gdl++);
            gDPSetCycleType(gdl++, G_CYC_FILL);
            gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetTexturePersp(gdl++, G_TP_NONE);
            gDPFillRectangle(gdl++, (s32)(f14 * 0.25f), (s32)(f16 * 0.25f), (s32)(f2 * 0.25f), (s32)(f12 * 0.25f));
            gDPPipeSync(gdl++);
            gDPSetTexturePersp(gdl++, G_TP_PERSP);
        }
        else
        {
            gDPPipeSync(gdl++);

            likely_generate_DL_for_image_declaration(&gdl, &skywaterimages[fogGetCurrentEnvironmentp()->WaterImageId], 1, 0, 2);
            gdl = sub_GAME_7F09343C(gdl, 0); // ???
            gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

            if (s1 == 4)
            {
                gdl = sub_GAME_7F097818(gdl, &sp274[0], &sp274[1], &sp274[3], 130.0f, TRUE);

                if (sp430)
                {
                    sp274[0].unk2c++;
                    sp274[1].unk2c++;
                    sp274[2].unk2c++;
                    sp274[3].unk2c++;
                }

                gdl = sub_GAME_7F097818(gdl, &sp274[3], &sp274[2], &sp274[0], 130.0f, TRUE);
            }
            else if (s1 == 5)
            {
                gdl = sub_GAME_7F097818(gdl, &sp274[0], &sp274[1], &sp274[2], 130.0f, TRUE);
                gdl = sub_GAME_7F097818(gdl, &sp274[0], &sp274[2], &sp274[3], 130.0f, TRUE);
                gdl = sub_GAME_7F097818(gdl, &sp274[0], &sp274[3], &sp274[4], 130.0f, TRUE);
            }
            else if (s1 == 3)
            {
                gdl = sub_GAME_7F097818(gdl, &sp274[0], &sp274[1], &sp274[2], 130.0f, TRUE);
            }
        }
    }

    switch ((sp538 << 3) | (sp534 << 2) | (sp530 << 1) | sp52c)
    {
        case 0:
            return gdl;

        case 15:
            s1 = 4;
            sp4b4[0].unk00 = sp644.f[0] * scale;
            sp4b4[0].unk04 = sp644.f[1] * scale;
            sp4b4[0].unk08 = sp644.f[2] * scale;
            sp4b4[1].unk00 = sp638.f[0] * scale;
            sp4b4[1].unk04 = sp638.f[1] * scale;
            sp4b4[1].unk08 = sp638.f[2] * scale;
            sp4b4[2].unk00 = sp62c.f[0] * scale;
            sp4b4[2].unk04 = sp62c.f[1] * scale;
            sp4b4[2].unk08 = sp62c.f[2] * scale;
            sp4b4[3].unk00 = sp620.f[0] * scale;
            sp4b4[3].unk04 = sp620.f[1] * scale;
            sp4b4[3].unk08 = sp620.f[2] * scale;
            sp4b4[0].unk0c = sp644.f[0] * 0.1f;
            sp4b4[0].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp638.f[0] * 0.1f;
            sp4b4[1].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp62c.f[0] * 0.1f;
            sp4b4[2].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp620.f[0] * 0.1f;
            sp4b4[3].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp58c);
            sub_GAME_7F093CB0(&sp4b4[1], sp588);
            sub_GAME_7F093CB0(&sp4b4[2], sp584);
            sub_GAME_7F093CB0(&sp4b4[3], sp580);
            break;

        case 12:
            s1 = 4;
            sp4b4[0].unk00 = sp644.f[0] * scale;
            sp4b4[0].unk04 = sp644.f[1] * scale;
            sp4b4[0].unk08 = sp644.f[2] * scale;
            sp4b4[1].unk00 = sp638.f[0] * scale;
            sp4b4[1].unk04 = sp638.f[1] * scale;
            sp4b4[1].unk08 = sp638.f[2] * scale;
            sp4b4[2].unk00 = sp5fc.f[0] * scale;
            sp4b4[2].unk04 = sp5fc.f[1] * scale;
            sp4b4[2].unk08 = sp5fc.f[2] * scale;
            sp4b4[3].unk00 = sp5f0.f[0] * scale;
            sp4b4[3].unk04 = sp5f0.f[1] * scale;
            sp4b4[3].unk08 = sp5f0.f[2] * scale;
            sp4b4[0].unk0c = sp644.f[0] * 0.1f;
            sp4b4[0].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp638.f[0] * 0.1f;
            sp4b4[1].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp5fc.f[0] * 0.1f;
            sp4b4[2].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp5f0.f[0] * 0.1f;
            sp4b4[3].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp58c);
            sub_GAME_7F093CB0(&sp4b4[1], sp588);
            sub_GAME_7F093CB0(&sp4b4[2], sp574);
            sub_GAME_7F093CB0(&sp4b4[3], sp570);
            break;

        case 3:
            s1 = 4;
            sp4b4[0].unk00 = sp620.f[0] * scale;
            sp4b4[0].unk04 = sp620.f[1] * scale;
            sp4b4[0].unk08 = sp620.f[2] * scale;
            sp4b4[1].unk00 = sp62c.f[0] * scale;
            sp4b4[1].unk04 = sp62c.f[1] * scale;
            sp4b4[1].unk08 = sp62c.f[2] * scale;
            sp4b4[2].unk00 = sp5f0.f[0] * scale;
            sp4b4[2].unk04 = sp5f0.f[1] * scale;
            sp4b4[2].unk08 = sp5f0.f[2] * scale;
            sp4b4[3].unk00 = sp5fc.f[0] * scale;
            sp4b4[3].unk04 = sp5fc.f[1] * scale;
            sp4b4[3].unk08 = sp5fc.f[2] * scale;
            sp4b4[0].unk0c = sp620.f[0] * 0.1f;
            sp4b4[0].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp62c.f[0] * 0.1f;
            sp4b4[1].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp5f0.f[0] * 0.1f;
            sp4b4[2].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp5fc.f[0] * 0.1f;
            sp4b4[3].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp580);
            sub_GAME_7F093CB0(&sp4b4[1], sp584);
            sub_GAME_7F093CB0(&sp4b4[2], sp570);
            sub_GAME_7F093CB0(&sp4b4[3], sp574);
            break;

        case 5:
            s1 = 4;
            sp4b4[0].unk00 = sp638.f[0] * scale;
            sp4b4[0].unk04 = sp638.f[1] * scale;
            sp4b4[0].unk08 = sp638.f[2] * scale;
            sp4b4[1].unk00 = sp620.f[0] * scale;
            sp4b4[1].unk04 = sp620.f[1] * scale;
            sp4b4[1].unk08 = sp620.f[2] * scale;
            sp4b4[2].unk00 = sp614.f[0] * scale;
            sp4b4[2].unk04 = sp614.f[1] * scale;
            sp4b4[2].unk08 = sp614.f[2] * scale;
            sp4b4[3].unk00 = sp608.f[0] * scale;
            sp4b4[3].unk04 = sp608.f[1] * scale;
            sp4b4[3].unk08 = sp608.f[2] * scale;
            sp4b4[0].unk0c = sp638.f[0] * 0.1f;
            sp4b4[0].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp620.f[0] * 0.1f;
            sp4b4[1].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp614.f[0] * 0.1f;
            sp4b4[2].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp608.f[0] * 0.1f;
            sp4b4[3].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp588);
            sub_GAME_7F093CB0(&sp4b4[1], sp580);
            sub_GAME_7F093CB0(&sp4b4[2], sp57c);
            sub_GAME_7F093CB0(&sp4b4[3], sp578);
            break;

        case 10:
            s1 = 4;
            sp4b4[0].unk00 = sp62c.f[0] * scale;
            sp4b4[0].unk04 = sp62c.f[1] * scale;
            sp4b4[0].unk08 = sp62c.f[2] * scale;
            sp4b4[1].unk00 = sp644.f[0] * scale;
            sp4b4[1].unk04 = sp644.f[1] * scale;
            sp4b4[1].unk08 = sp644.f[2] * scale;
            sp4b4[2].unk00 = sp608.f[0] * scale;
            sp4b4[2].unk04 = sp608.f[1] * scale;
            sp4b4[2].unk08 = sp608.f[2] * scale;
            sp4b4[3].unk00 = sp614.f[0] * scale;
            sp4b4[3].unk04 = sp614.f[1] * scale;
            sp4b4[3].unk08 = sp614.f[2] * scale;
            sp4b4[0].unk0c = sp62c.f[0] * 0.1f;
            sp4b4[0].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp644.f[0] * 0.1f;
            sp4b4[1].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp608.f[0] * 0.1f;
            sp4b4[2].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp614.f[0] * 0.1f;
            sp4b4[3].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp584);
            sub_GAME_7F093CB0(&sp4b4[1], sp58c);
            sub_GAME_7F093CB0(&sp4b4[2], sp578);
            sub_GAME_7F093CB0(&sp4b4[3], sp57c);
            break;

        case 1:
            s1 = 3;
            sp4b4[0].unk00 = sp620.f[0] * scale;
            sp4b4[0].unk04 = sp620.f[1] * scale;
            sp4b4[0].unk08 = sp620.f[2] * scale;
            sp4b4[1].unk00 = sp608.f[0] * scale;
            sp4b4[1].unk04 = sp608.f[1] * scale;
            sp4b4[1].unk08 = sp608.f[2] * scale;
            sp4b4[2].unk00 = sp5f0.f[0] * scale;
            sp4b4[2].unk04 = sp5f0.f[1] * scale;
            sp4b4[2].unk08 = sp5f0.f[2] * scale;
            sp4b4[0].unk0c = sp620.f[0] * 0.1f;
            sp4b4[0].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp608.f[0] * 0.1f;
            sp4b4[1].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp5f0.f[0] * 0.1f;
            sp4b4[2].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp580);
            sub_GAME_7F093CB0(&sp4b4[1], sp578);
            sub_GAME_7F093CB0(&sp4b4[2], sp570);
            break;

        case 2:
            s1 = 3;
            sp4b4[0].unk00 = sp62c.f[0] * scale;
            sp4b4[0].unk04 = sp62c.f[1] * scale;
            sp4b4[0].unk08 = sp62c.f[2] * scale;
            sp4b4[1].unk00 = sp5fc.f[0] * scale;
            sp4b4[1].unk04 = sp5fc.f[1] * scale;
            sp4b4[1].unk08 = sp5fc.f[2] * scale;
            sp4b4[2].unk00 = sp608.f[0] * scale;
            sp4b4[2].unk04 = sp608.f[1] * scale;
            sp4b4[2].unk08 = sp608.f[2] * scale;
            sp4b4[0].unk0c = sp62c.f[0] * 0.1f;
            sp4b4[0].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp5fc.f[0] * 0.1f;
            sp4b4[1].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp608.f[0] * 0.1f;
            sp4b4[2].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp584);
            sub_GAME_7F093CB0(&sp4b4[1], sp574);
            sub_GAME_7F093CB0(&sp4b4[2], sp578);
            break;

        case 4:
            s1 = 3;
            sp4b4[0].unk00 = sp638.f[0] * scale;
            sp4b4[0].unk04 = sp638.f[1] * scale;
            sp4b4[0].unk08 = sp638.f[2] * scale;
            sp4b4[1].unk00 = sp5f0.f[0] * scale;
            sp4b4[1].unk04 = sp5f0.f[1] * scale;
            sp4b4[1].unk08 = sp5f0.f[2] * scale;
            sp4b4[2].unk00 = sp614.f[0] * scale;
            sp4b4[2].unk04 = sp614.f[1] * scale;
            sp4b4[2].unk08 = sp614.f[2] * scale;
            sp4b4[0].unk0c = sp638.f[0] * 0.1f;
            sp4b4[0].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp5f0.f[0] * 0.1f;
            sp4b4[1].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp614.f[0] * 0.1f;
            sp4b4[2].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp588);
            sub_GAME_7F093CB0(&sp4b4[1], sp570);
            sub_GAME_7F093CB0(&sp4b4[2], sp57c);
            break;

        case 8:
            s1 = 3;
            sp4b4[0].unk00 = sp644.f[0] * scale;
            sp4b4[0].unk04 = sp644.f[1] * scale;
            sp4b4[0].unk08 = sp644.f[2] * scale;
            sp4b4[1].unk00 = sp614.f[0] * scale;
            sp4b4[1].unk04 = sp614.f[1] * scale;
            sp4b4[1].unk08 = sp614.f[2] * scale;
            sp4b4[2].unk00 = sp5fc.f[0] * scale;
            sp4b4[2].unk04 = sp5fc.f[1] * scale;
            sp4b4[2].unk08 = sp5fc.f[2] * scale;
            sp4b4[0].unk0c = sp644.f[0] * 0.1f;
            sp4b4[0].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp614.f[0] * 0.1f;
            sp4b4[1].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp5fc.f[0] * 0.1f;
            sp4b4[2].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp58c);
            sub_GAME_7F093CB0(&sp4b4[1], sp57c);
            sub_GAME_7F093CB0(&sp4b4[2], sp574);
            break;

        case 14:
            s1 = 5;
            sp4b4[0].unk00 = sp62c.f[0] * scale;
            sp4b4[0].unk04 = sp62c.f[1] * scale;
            sp4b4[0].unk08 = sp62c.f[2] * scale;
            sp4b4[1].unk00 = sp644.f[0] * scale;
            sp4b4[1].unk04 = sp644.f[1] * scale;
            sp4b4[1].unk08 = sp644.f[2] * scale;
            sp4b4[2].unk00 = sp638.f[0] * scale;
            sp4b4[2].unk04 = sp638.f[1] * scale;
            sp4b4[2].unk08 = sp638.f[2] * scale;
            sp4b4[3].unk00 = sp5f0.f[0] * scale;
            sp4b4[3].unk04 = sp5f0.f[1] * scale;
            sp4b4[3].unk08 = sp5f0.f[2] * scale;
            sp4b4[4].unk00 = sp608.f[0] * scale;
            sp4b4[4].unk04 = sp608.f[1] * scale;
            sp4b4[4].unk08 = sp608.f[2] * scale;
            sp4b4[0].unk0c = sp62c.f[0] * 0.1f;
            sp4b4[0].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp644.f[0] * 0.1f;
            sp4b4[1].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp638.f[0] * 0.1f;
            sp4b4[2].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp5f0.f[0] * 0.1f;
            sp4b4[3].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[4].unk0c = sp608.f[0] * 0.1f;
            sp4b4[4].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp584);
            sub_GAME_7F093CB0(&sp4b4[1], sp58c);
            sub_GAME_7F093CB0(&sp4b4[2], sp588);
            sub_GAME_7F093CB0(&sp4b4[3], sp570);
            sub_GAME_7F093CB0(&sp4b4[4], sp578);
            break;

        case 13:
            s1 = 5;
            sp4b4[0].unk00 = sp644.f[0] * scale;
            sp4b4[0].unk04 = sp644.f[1] * scale;
            sp4b4[0].unk08 = sp644.f[2] * scale;
            sp4b4[1].unk00 = sp638.f[0] * scale;
            sp4b4[1].unk04 = sp638.f[1] * scale;
            sp4b4[1].unk08 = sp638.f[2] * scale;
            sp4b4[2].unk00 = sp620.f[0] * scale;
            sp4b4[2].unk04 = sp620.f[1] * scale;
            sp4b4[2].unk08 = sp620.f[2] * scale;
            sp4b4[3].unk00 = sp608.f[0] * scale;
            sp4b4[3].unk04 = sp608.f[1] * scale;
            sp4b4[3].unk08 = sp608.f[2] * scale;
            sp4b4[4].unk00 = sp5fc.f[0] * scale;
            sp4b4[4].unk04 = sp5fc.f[1] * scale;
            sp4b4[4].unk08 = sp5fc.f[2] * scale;
            sp4b4[0].unk0c = sp644.f[0] * 0.1f;
            sp4b4[0].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp638.f[0] * 0.1f;
            sp4b4[1].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp620.f[0] * 0.1f;
            sp4b4[2].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp608.f[0] * 0.1f;
            sp4b4[3].unk10 = sp608.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[4].unk0c = sp5fc.f[0] * 0.1f;
            sp4b4[4].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp58c);
            sub_GAME_7F093CB0(&sp4b4[1], sp588);
            sub_GAME_7F093CB0(&sp4b4[2], sp580);
            sub_GAME_7F093CB0(&sp4b4[3], sp578);
            sub_GAME_7F093CB0(&sp4b4[4], sp574);
            break;

        case 11:
            s1 = 5;
            sp4b4[0].unk00 = sp620.f[0] * scale;
            sp4b4[0].unk04 = sp620.f[1] * scale;
            sp4b4[0].unk08 = sp620.f[2] * scale;
            sp4b4[1].unk00 = sp62c.f[0] * scale;
            sp4b4[1].unk04 = sp62c.f[1] * scale;
            sp4b4[1].unk08 = sp62c.f[2] * scale;
            sp4b4[2].unk00 = sp644.f[0] * scale;
            sp4b4[2].unk04 = sp644.f[1] * scale;
            sp4b4[2].unk08 = sp644.f[2] * scale;
            sp4b4[3].unk00 = sp614.f[0] * scale;
            sp4b4[3].unk04 = sp614.f[1] * scale;
            sp4b4[3].unk08 = sp614.f[2] * scale;
            sp4b4[4].unk00 = sp5f0.f[0] * scale;
            sp4b4[4].unk04 = sp5f0.f[1] * scale;
            sp4b4[4].unk08 = sp5f0.f[2] * scale;
            sp4b4[0].unk0c = sp620.f[0] * 0.1f;
            sp4b4[0].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp62c.f[0] * 0.1f;
            sp4b4[1].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp644.f[0] * 0.1f;
            sp4b4[2].unk10 = sp644.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp614.f[0] * 0.1f;
            sp4b4[3].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[4].unk0c = sp5f0.f[0] * 0.1f;
            sp4b4[4].unk10 = sp5f0.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp580);
            sub_GAME_7F093CB0(&sp4b4[1], sp584);
            sub_GAME_7F093CB0(&sp4b4[2], sp58c);
            sub_GAME_7F093CB0(&sp4b4[3], sp57c);
            sub_GAME_7F093CB0(&sp4b4[4], sp570);
            break;

        case 7:
            s1 = 5;
            sp4b4[0].unk00 = sp638.f[0] * scale;
            sp4b4[0].unk04 = sp638.f[1] * scale;
            sp4b4[0].unk08 = sp638.f[2] * scale;
            sp4b4[1].unk00 = sp620.f[0] * scale;
            sp4b4[1].unk04 = sp620.f[1] * scale;
            sp4b4[1].unk08 = sp620.f[2] * scale;
            sp4b4[2].unk00 = sp62c.f[0] * scale;
            sp4b4[2].unk04 = sp62c.f[1] * scale;
            sp4b4[2].unk08 = sp62c.f[2] * scale;
            sp4b4[3].unk00 = sp5fc.f[0] * scale;
            sp4b4[3].unk04 = sp5fc.f[1] * scale;
            sp4b4[3].unk08 = sp5fc.f[2] * scale;
            sp4b4[4].unk00 = sp614.f[0] * scale;
            sp4b4[4].unk04 = sp614.f[1] * scale;
            sp4b4[4].unk08 = sp614.f[2] * scale;
            sp4b4[0].unk0c = sp638.f[0] * 0.1f;
            sp4b4[0].unk10 = sp638.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[1].unk0c = sp620.f[0] * 0.1f;
            sp4b4[1].unk10 = sp620.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[2].unk0c = sp62c.f[0] * 0.1f;
            sp4b4[2].unk10 = sp62c.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[3].unk0c = sp5fc.f[0] * 0.1f;
            sp4b4[3].unk10 = sp5fc.f[2] * 0.1f + g_SkyCloudOffset;
            sp4b4[4].unk0c = sp614.f[0] * 0.1f;
            sp4b4[4].unk10 = sp614.f[2] * 0.1f + g_SkyCloudOffset;

            sub_GAME_7F093CB0(&sp4b4[0], sp588);
            sub_GAME_7F093CB0(&sp4b4[1], sp580);
            sub_GAME_7F093CB0(&sp4b4[2], sp584);
            sub_GAME_7F093CB0(&sp4b4[3], sp574);
            sub_GAME_7F093CB0(&sp4b4[4], sp57c);
            break;

        default:
            return gdl;
    }

    gDPPipeSync(gdl++);

    likely_generate_DL_for_image_declaration(&gdl, &skywaterimages[fogGetCurrentEnvironmentp()->SkyImageId], 1, 0, 2);

    if (1);

    gDPSetEnvColor(gdl++, fogGetCurrentEnvironmentp()->Red, fogGetCurrentEnvironmentp()->Green, fogGetCurrentEnvironmentp()->Blue, 0xff);
    gDPSetCombineLERP(gdl++,
            SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, SHADE,
            SHADE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, SHADE);

    {
        Mtxf sp1ec;
        Mtxf sp1ac;
        SkyRelated38 sp94[5];
        s32 i;
        s32 stack[2];

        matrix_4x4_multiply(currentPlayerGetProjectionMatrixF(), currentPlayerGetMatrix10CC(), &sp1ec);
        guScaleF(dword_CODE_bss_80079E98.m, 1.0f / scale, 1.0f / scale, 1.0f / scale);
        matrix_4x4_multiply(&sp1ec, &dword_CODE_bss_80079E98, &sp1ac);

        for (i = 0; i < s1; i++)
        {
            sub_GAME_7F097388(&sp4b4[i], &sp1ac, 130, 65535.0f, 65535.0f, &sp94[i]);

            sp94[i].unk28 = sub_GAME_7F093C48(sp94[i].unk28, getPlayer_c_screenleft() * 4.0f, (getPlayer_c_screenleft() + getPlayer_c_screenwidth()) * 4.0f - 1.0f);
            sp94[i].unk2c = sub_GAME_7F093C48(sp94[i].unk2c, getPlayer_c_screentop() * 4.0f, (getPlayer_c_screentop() + getPlayer_c_screenheight()) * 4.0f - 1.0f);
        }

        if (s1 == 4)
        {
            if (((sp538 << 3) | (sp534 << 2) | (sp530 << 1) | sp52c) == 12)
            {
                if (sp548 < sp54c)
                {
                    if (sp94[3].unk2c >= sp94[1].unk2c + 4.0f)
                    {
                        sp94[0].unk28 = getPlayer_c_screenleft() * 4.0f;
                        sp94[0].unk2c = getPlayer_c_screentop() * 4.0f;
                        sp94[1].unk28 = (getPlayer_c_screenleft() + getPlayer_c_screenwidth()) * 4.0f - 1.0f;
                        sp94[1].unk2c = getPlayer_c_screentop() * 4.0f;
                        sp94[2].unk28 = getPlayer_c_screenleft() * 4.0f;
                        sp94[3].unk28 = (getPlayer_c_screenleft() + getPlayer_c_screenwidth()) * 4.0f - 1.0f;

                        gdl = sub_GAME_7F098A2C(gdl, &sp94[0], &sp94[1], &sp94[2], &sp94[3], 130.0f);
                    }
                    else
                    {
                        gdl = sub_GAME_7F097818(gdl, &sp94[0], &sp94[1], &sp94[2], 130.0f, TRUE);
                    }
                }
                else if (sp94[2].unk2c >= sp94[0].unk2c + 4.0f)
                {
                    sp94[0].unk28 = getPlayer_c_screenleft() * 4.0f;
                    sp94[0].unk2c = getPlayer_c_screentop() * 4.0f;
                    sp94[1].unk28 = (getPlayer_c_screenleft() + getPlayer_c_screenwidth()) * 4.0f - 1.0f;
                    sp94[1].unk2c = getPlayer_c_screentop() * 4.0f;
                    sp94[2].unk28 = getPlayer_c_screenleft() * 4.0f;
                    sp94[3].unk28 = (getPlayer_c_screenleft() + getPlayer_c_screenwidth()) * 4.0f - 1.0f;

                    gdl = sub_GAME_7F098A2C(gdl, &sp94[1], &sp94[0], &sp94[3], &sp94[2], 130.0f);
                }
                else
                {
                    gdl = sub_GAME_7F097818(gdl, &sp94[1], &sp94[0], &sp94[3], 130.0f, TRUE);
                }
            }
            else
            {
                gdl = sub_GAME_7F097818(gdl, &sp94[0], &sp94[1], &sp94[3], 130.0f, TRUE);
                gdl = sub_GAME_7F097818(gdl, &sp94[3], &sp94[2], &sp94[0], 130.0f, TRUE);
            }
        }
        else if (s1 == 5)
        {
            gdl = sub_GAME_7F097818(gdl, &sp94[0], &sp94[1], &sp94[2], 130.0f, TRUE);
            gdl = sub_GAME_7F097818(gdl, &sp94[0], &sp94[2], &sp94[3], 130.0f, TRUE);
            gdl = sub_GAME_7F097818(gdl, &sp94[0], &sp94[3], &sp94[4], 130.0f, TRUE);
        }
        else if (s1 == 3)
        {
            gdl = sub_GAME_7F097818(gdl, &sp94[0], &sp94[1], &sp94[2], 130.0f, TRUE);
        }
    }

    return gdl;
}


void sub_GAME_7F097388(SkyRelated18 *arg0, Mtxf *arg1, u16 arg2, f32 arg3, f32 arg4, SkyRelated38 *arg5)
{
    f32 sp68[4];
    f32 sp64;
    f32 sp60;
    f32 f22;
    f32 f0;
    f32 sp48[4];
    f32 sp38[4];
    f32 mult;

    mult = arg2 / 65536.0f;

    sp68[0] = (arg0->unk00 * arg1->m[0][0] + arg0->unk04 * arg1->m[1][0] + arg0->unk08 * arg1->m[2][0]) + arg1->m[3][0];
    sp68[1] = (arg0->unk00 * arg1->m[0][1] + arg0->unk04 * arg1->m[1][1] + arg0->unk08 * arg1->m[2][1]) + arg1->m[3][1];
    sp68[2] = (arg0->unk00 * arg1->m[0][2] + arg0->unk04 * arg1->m[1][2] + arg0->unk08 * arg1->m[2][2]) + arg1->m[3][2];
    sp68[3] = (arg0->unk00 * arg1->m[0][3] + arg0->unk04 * arg1->m[1][3] + arg0->unk08 * arg1->m[2][3]) + arg1->m[3][3];

    sp60 = arg0->unk0c * (arg3 / 65536.0f);
    sp64 = arg0->unk10 * (arg4 / 65536.0f);

    if (sp68[3] == 0.0f)
    {
        f22 = 32767.0f;
    }
    else
    {
        f22 = 1.0f / (sp68[3] * mult);
    }

    f0 = f22;
    if (f0 < 0.0f) { f0 = 32767.0f; }

    sp48[0] = sp68[0] * f0 * mult;
    sp48[1] = sp68[1] * f0 * mult;
    sp48[2] = sp68[2] * f0 * mult;
    sp48[3] = sp68[3] * f0 * mult;

    sp38[0] = sp48[0] * (getPlayer_c_screenwidth() * 2) + (getPlayer_c_screenwidth() * 2 + getPlayer_c_screenleft() * 4);
    sp38[1] = -sp48[1] * (getPlayer_c_screenheight() * 2) + (getPlayer_c_screenheight() * 2 + getPlayer_c_screentop() * 4);

    sp38[2] = sp48[2] * 511.0f + 511.0f;
    sp38[3] = sp48[3] * 0 + 0;

    sp38[0] = sub_GAME_7F093C48(sp38[0], -4090.0f, 4090.0f);
    sp38[1] = sub_GAME_7F093C48(sp38[1], -4090.0f, 4090.0f);
    sp38[2] = sub_GAME_7F093C48(sp38[2], 0.0f, 32767.0f);
    sp38[3] = sub_GAME_7F093C48(sp38[3], 0.0f, 32767.0f);

    arg5->unk00 = sp68[0];
    arg5->unk04 = sp68[1];
    arg5->unk08 = sp68[2];
    arg5->unk0c = sp68[3];
    arg5->unk20 = sp60;
    arg5->unk24 = sp64;
    arg5->unk28 = sp38[0];
    arg5->unk2c = sp38[1] - fogGetCurrentEnvironmentp()->WaterConcavity * 4.0f;
    arg5->unk30 = sp38[2];
    arg5->unk34 = f22;

    arg5->r = arg0->r;
    arg5->g = arg0->g;
    arg5->b = arg0->b;
    arg5->a = arg0->a;
}


bool sub_GAME_7F0977B4(SkyRelated38 *arg0, SkyRelated38 *arg1)
{
    f32 f0;
    f32 f1;

    f0 = arg0->unk28 - arg1->unk28;
    f1 = arg0->unk2c - arg1->unk2c;
    return sqrtf((f0 * f0) + (f1 * f1)) < 1.0f ? TRUE : FALSE;
}


Gfx *sub_GAME_7F097818(Gfx *gdl, SkyRelated38 *arg1, SkyRelated38 *arg2, SkyRelated38 *arg3, f32 arg4, bool textured)
{
    SkyRelated38 *sp484;
    SkyRelated38 *sp480;
    SkyRelated38 *sp47c;
    s32 i;
    f32 sp474;
    f32 sp470;
    f32 sp46c;
    f32 sp468;
    f32 sp464;
    f32 sp460;

    f32 sp45c[1];
    f32 sp458[1];
    f32 sp454[1];
    f32 sp450[1];
    f32 sp44c[1];
    f32 sp448[1];

    f32 sp444;
    f32 sp440;

    f32 sp43c[1];
    f32 sp438[1];
    f32 sp434[1];
    f32 sp430[1];
    f32 sp42c[1];
    f32 sp428[1];
    f32 sp424[1];
    f32 sp420[1];

    f32 sp41c;
    f32 sp418;
    f32 sp414;
    f32 sp410;
    f32 sp40c;
    f32 sp408;
    f32 sp404;
    f32 sp400;

    f32 sp3fc[1];
    f32 sp3f8[1];
    f32 sp3f4[1];
    f32 sp3f0[1];
    f32 sp3ec[1];
    f32 sp3e8[1];
    f32 sp3e4[1];
    f32 sp3e0[1];

    f32 sp3dc[1];
    f32 sp3d8[1];
    f32 sp3d4[1];
    f32 sp3d0[1];
    f32 sp3cc[1];
    f32 sp3c8[1];
    f32 sp3c4[1];
    f32 sp3c0[1];

    f32 sp3bc[1];
    f32 sp3b8[1];
    f32 sp3b4[1];
    f32 sp3b0[1];
    f32 sp3ac[1];
    f32 sp3a8[1];
    f32 sp3a4[1];
    f32 sp3a0[1];
    f32 sp39c[1];
    f32 sp398[1];
    f32 sp394[1];
    f32 sp390[1];
    f32 sp38c[1];
    f32 sp388[1];
    f32 sp384[1];
    f32 sp380[1];
    f32 sp37c;
    f32 sp378;
    f32 sp374[1];
    f32 sp370[1];
    f32 sp36c[1];
    f32 sp368;
    f32 sp364[1];
    f32 sp360[1];
    f32 sp35c[1];
    f32 sp358[1];
    f32 sp354[1];
    f32 sp350[1];
    f32 sp34c[1];
    f32 sp348[1];
    f32 sp344[1];
    f32 sp340[1];
    f32 sp33c[1];
    f32 sp338[1];
    f32 sp334[1];
    f32 sp330[1];
    f32 sp310[8];
    f32 sp2f0[8];
    f32 sp2d0[8];
    f32 sp2b0[8];
    f32 sp290[8];
    f32 sp270[8];
    f32 sp250[8];
    f32 sp230[8];
    f32 sp210[8];
    f32 f2;
    f32 sp208[1];
    f32 sp204[1];
    f32 sp200[1];
    u32 stack[4];
    f32 sp1d0[8];
    f32 sp1b0[8];
    u32 stack2;
    f32 sp1a8[1];
    f32 sp1a4[1];
    f32 sp1a0[1];
    SkyRelated38 *swap1;
    SkyRelated38 *swap2;
    SkyRelated38 *swap3;
    f32 sp190[1];
    u32 stack3;

    if (sub_GAME_7F0977B4(arg1, arg2) || sub_GAME_7F0977B4(arg2, arg3) || sub_GAME_7F0977B4(arg3, arg1))
    {
        return gdl;
    }

    sp378 = arg4 / 65536.0f;

    sp474 = arg2->unk28 - arg1->unk28;
    sp470 = arg2->unk2c - arg1->unk2c;
    sp46c = arg3->unk28 - arg1->unk28;
    sp468 = arg3->unk2c - arg1->unk2c;

    sp444 = ((sp46c * sp470) - (sp474 * sp468)) / 65536.0f;

    if (sp444 == 0.0f)
    {
        return gdl;
    }

    sp440 = 1.0f / sp444;

    sp484 = arg1;
    sp480 = arg2;
    sp47c = arg3;

    if (sp480->unk2c < sp484->unk2c)
    {
        swap1 = sp480;
        sp480 = sp484;
        sp484 = swap1;

        sp444 *= -1.0f;
        sp440 *= -1.0f;
    }

    if (sp47c->unk2c < sp480->unk2c)
    {
        swap2 = sp480;
        sp480 = sp47c;
        sp47c = swap2;

        sp444 *= -1.0f;
        sp440 *= -1.0f;
    }

    if (sp480->unk2c < sp484->unk2c)
    {
        swap3 = sp480;
        sp480 = sp484;
        sp484 = swap3;

        sp444 *= -1.0f;
        sp440 *= -1.0f;
    }

    sp420[0] = sp480->unk28 * 0.25f;
    sp424[0] = 0.0f;
    sp428[0] = sp484->unk28 * 0.25f;
    sp42c[0] = 0.0f;
    sp430[0] = sp484->unk28 * 0.25f;
    sp434[0] = 0.0f;
    sp43c[0] = 0.0f;
    sp438[0] = 0.0f;

    sp448[0] = sp47c->unk28;
    sp44c[0] = sp47c->unk2c;
    sp450[0] = sp480->unk28;
    sp454[0] = sp480->unk2c;
    sp458[0] = sp484->unk28;
    sp45c[0] = sp484->unk2c;

    sp474 = sp450[0] - sp458[0];
    sp470 = sp454[0] - sp45c[0];
    sp46c = sp448[0] - sp458[0];
    sp468 = sp44c[0] - sp45c[0];
    sp464 = sp448[0] - sp450[0];
    sp460 = sp44c[0] - sp454[0];

    sp3fc[0] = 0.0f;
    sp3f8[0] = 0.0f;
    sp3dc[0] = 0.0f;
    sp3d8[0] = 0.0f;
    sp3a0[0] = 0.0f;
    sp3a8[0] = 0.0f;
    sp3b0[0] = 0.0f;
    sp3bc[0] = 0.0f;
    sp3b8[0] = 0.0f;
    sp380[0] = 0.0f;
    sp388[0] = 0.0f;
    sp390[0] = 0.0f;
    sp39c[0] = 0.0f;
    sp398[0] = 0.0f;

    sp3e0[0] = sp464 / 4.0f;
    sp3e4[0] = sp460 / 4.0f;
    sp3e8[0] = sp474 / 4.0f;
    sp3ec[0] = sp470 / 4.0f;
    sp3f0[0] = sp46c / 4.0f;
    sp3f4[0] = sp468 / 4.0f;

    sp3c0[0] = sp464 * 4.0f;
    sp3c4[0] = sp460 * 4.0f;
    sp3c8[0] = sp474 * 4.0f;
    sp3cc[0] = sp470 * 4.0f;
    sp3d0[0] = sp46c * 4.0f;
    sp3d4[0] = sp468 * 4.0f;

    sp3a4[0] = 4.0f / sp460;
    sp3ac[0] = 4.0f / sp470;
    sp3b4[0] = 4.0f / sp468;

    sp384[0] = sp464 / sp460;
    sp38c[0] = sp474 / sp470;
    sp394[0] = sp46c / sp468;

    sp384[0] = sub_GAME_7F093C48(sp384[0], -1878.0f, 1877.0f);
    sp38c[0] = sub_GAME_7F093C48(sp38c[0], -1878.0f, 1877.0f);
    sp394[0] = sub_GAME_7F093C48(sp394[0], -1878.0f, 1877.0f);

    f2 = (sp484->unk2c * 0.25f);
    sp37c = f2 - (s32) f2;
    sp408 = sp428[0] - addpoint5tofloat(sp38c[0] * 8192.0f) * (1.0f / 8192.0f) * sp37c;
    sp410 = sp430[0] - addpoint5tofloat(sp394[0] * 8192.0f) * (1.0f / 8192.0f) * sp37c;

    gImmp1(gdl++, G_RDPHALF_1, (textured ? (G_TRI_SHADE_TXTR << 24) : (G_TRI_FILL << 24))
            | (sp444 < 0.0f ? 0x00800000 : 0)
            | (s32) sp47c->unk2c);
    gImmp1(gdl++, G_RDPHALF_CONT, (s32) sp480->unk2c << 16 | (s32) sp484->unk2c);

    gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(sp480->unk28 * 0.25f));
    gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(sp384[0]));

    gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(sp410));
    gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(sp394[0]));

    gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(sp408));
    gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(sp38c[0]));

    if (!textured)
    {
        return gdl;
    }

    sp36c[0] = sp484->unk0c * sp378;
    sp370[0] = sp480->unk0c * sp378;
    sp374[0] = sp47c->unk0c * sp378;

    sp368 = sp36c[0];

    if (sp370[0] < sp368) { sp368 = sp370[0]; }
    if (sp374[0] < sp368) { sp368 = sp374[0]; }

    sp368 *= 0.5f;

    sp35c[0] = sp484->unk34 * sp368;
    sp360[0] = sp480->unk34 * sp368;
    sp364[0] = sp47c->unk34 * sp368;

    sp338[0] = sp35c[0] * sp484->unk20;
    sp33c[0] = sp35c[0] * sp484->unk24;
    sp340[0] = sp35c[0] * 32767.0f;
    sp344[0] = sp360[0] * sp480->unk20;
    sp348[0] = sp360[0] * sp480->unk24;
    sp34c[0] = sp360[0] * 32767.0f;
    sp350[0] = sp364[0] * sp47c->unk20;
    sp354[0] = sp364[0] * sp47c->unk24;
    sp358[0] = sp364[0] * 32767.0f;

    sp330[0] = SKYABS(sp338[0]);
    sp334[0] = SKYABS(sp33c[0]);

    if (sp330[0] < SKYABS(sp344[0])) { sp330[0] = SKYABS(sp344[0]); }
    if (sp334[0] < SKYABS(sp348[0])) { sp334[0] = SKYABS(sp348[0]); }
    if (sp330[0] < SKYABS(sp350[0])) { sp330[0] = SKYABS(sp350[0]); }
    if (sp334[0] < SKYABS(sp354[0])) { sp334[0] = SKYABS(sp354[0]); }

    sp310[0] = sp484->r + 0.5f;
    sp310[1] = sp484->g + 0.5f;
    sp310[2] = sp484->b + 0.5f;
    sp310[3] = sp484->a + 0.5f;

    sp2f0[0] = sp480->r + 0.5f;
    sp2f0[1] = sp480->g + 0.5f;
    sp2f0[2] = sp480->b + 0.5f;
    sp2f0[3] = sp480->a + 0.5f;

    sp2d0[0] = sp47c->r + 0.5f;
    sp2d0[1] = sp47c->g + 0.5f;
    sp2d0[2] = sp47c->b + 0.5f;
    sp2d0[3] = sp47c->a + 0.5f;

    sp310[4] = sp338[0]; sp310[5] = sp33c[0]; sp310[6] = sp340[0];
    sp2f0[4] = sp344[0]; sp2f0[5] = sp348[0]; sp2f0[6] = sp34c[0];
    sp2d0[4] = sp350[0]; sp2d0[5] = sp354[0]; sp2d0[6] = sp358[0];

    sp310[7] = sp484->unk30;
    sp2f0[7] = sp480->unk30;
    sp2d0[7] = sp47c->unk30;

    for (i = 0; i < 8; i++)
    {
        sp2b0[i] = sp2f0[i] - sp310[i];
        sp290[i] = sp2d0[i] - sp310[i];
    }

    for (i = 0; i < 8; i++)
    {
        sp250[i] = (sp290[i] * sp3cc[0] - sp2b0[i] * sp3d4[0]) / 65536.0f;
        sp270[i] = (sp2b0[i] * sp3d0[0] - sp290[i] * sp3c8[0]) / 65536.0f;
        sp290[i] = sp250[i] * sp440;
        sp2b0[i] = sp270[i] * sp440;
        sp230[i] = sp2b0[i] + sp290[i] * sp394[0];
        sp210[i] = sp310[i] - sp230[i] * sp37c;
    }

    {
        u32 sp168;
        u32 sp164;
        u32 sp160;
        u32 sp15c;
        u32 sp158;
        u32 sp154;
        u32 sp150;
        u32 sp14c;
        u32 sp148;
        u32 sp144;
        u32 sp140;
        u32 sp13c;
        u32 sp138;
        u32 sp134;
        u32 sp130;
        u32 sp12c;

        sp168 = sub_GAME_7F094298(sp210[0]);
        sp164 = sub_GAME_7F094298(sp210[1]);
        sp160 = sub_GAME_7F094298(sp210[2]);
        sp15c = sub_GAME_7F094298(sp210[3]);

        sp158 = sub_GAME_7F094298(sp290[0]);
        sp154 = sub_GAME_7F094298(sp290[1]);
        sp150 = sub_GAME_7F094298(sp290[2]);
        sp14c = sub_GAME_7F094298(sp290[3]);

        sp138 = sub_GAME_7F094298(sp2b0[0]);
        sp134 = sub_GAME_7F094298(sp2b0[1]);
        sp130 = sub_GAME_7F094298(sp2b0[2]);
        sp12c = sub_GAME_7F094298(sp2b0[3]);

        sp148 = sub_GAME_7F094298(sp230[0]);
        sp144 = sub_GAME_7F094298(sp230[1]);
        sp140 = sub_GAME_7F094298(sp230[2]);
        sp13c = sub_GAME_7F094298(sp230[3]);

        gImmp1(gdl++, G_RDPHALF_1, (sp168 & 0xffff0000) | (sp164 & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (sp160 & 0xffff0000) | (sp15c & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (sp158 & 0xffff0000) | (sp154 & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (sp150 & 0xffff0000) | (sp14c & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (sp168 & 0x0000ffff) << 16 | (sp164 & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (sp160 & 0x0000ffff) << 16 | (sp15c & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (sp158 & 0x0000ffff) << 16 | (sp154 & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (sp150 & 0x0000ffff) << 16 | (sp14c & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (sp148 & 0xffff0000) | (sp144 & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (sp140 & 0xffff0000) | (sp13c & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (sp138 & 0xffff0000) | (sp134 & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (sp130 & 0xffff0000) | (sp12c & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (sp148 & 0x0000ffff) << 16 | (sp144 & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (sp140 & 0x0000ffff) << 16 | (sp13c & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (sp138 & 0x0000ffff) << 16 | (sp134 & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (sp130 & 0x0000ffff) << 16 | (sp12c & 0x0000ffff));
    }

    sp200[0] = sp330[0] / 32.0f;
    sp204[0] = sp334[0] / 32.0f;
    sp208[0] = sp368 / 32.0f;

    for (i = 0; i < 8; i++)
    {
        sp1d0[i] = SKYABS(sp290[i]) / 32.0f;
        sp1b0[i] = SKYABS(sp2b0[i]) / 32.0f;
    }

    sp1a0[0] = sp200[0] + (2 * sp1d0[4]) + sp1b0[4];
    sp1a4[0] = sp204[0] + (2 * sp1d0[5]) + sp1b0[5];
    sp1a8[0] = sp208[0] + (2 * sp1d0[6]) + sp1b0[6];

    if (sp1a0[0] < sp1a4[0]) { sp1a0[0] = sp1a4[0]; }
    if (sp1a0[0] < sp1a8[0]) { sp1a0[0] = sp1a8[0]; }

    sp1a0[0] /= 1024.0f;

    if (sp1a0[0] > 1.0f)
    {
        sp190[0] = 1.0f / sp1a0[0];
    }
    else
    {
        sp190[0] = 1.0f;
    }

    {
        u32 spe8;
        u32 spe4;
        u32 spe0;
        u32 spdc;
        u32 spd8;
        u32 spd4;
        u32 spd0;
        u32 spcc;
        u32 spc8;
        u32 spc4;
        u32 spc0;
        u32 spbc;
        u32 spb8;
        u32 spb4;
        u32 spb0;
        u32 spac;

        spe8 = sub_GAME_7F094298(sp210[4] * sp190[0]);
        spe4 = sub_GAME_7F094298(sp210[5] * sp190[0]);
        spe0 = sub_GAME_7F094298(sp210[6] * sp190[0]);
        spdc = 0;

        spd8 = sub_GAME_7F094298(sp290[4] * sp190[0]);
        spd4 = sub_GAME_7F094298(sp290[5] * sp190[0]);
        spd0 = sub_GAME_7F094298(sp290[6] * sp190[0]);
        spcc = 0;

        spb8 = sub_GAME_7F094298(sp2b0[4] * sp190[0]);
        spb4 = sub_GAME_7F094298(sp2b0[5] * sp190[0]);
        spb0 = sub_GAME_7F094298(sp2b0[6] * sp190[0]);
        spac = 0;

        spc8 = sub_GAME_7F094298(sp230[4] * sp190[0]);
        spc4 = sub_GAME_7F094298(sp230[5] * sp190[0]);
        spc0 = sub_GAME_7F094298(sp230[6] * sp190[0]);
        spbc = 0;

        gImmp1(gdl++, G_RDPHALF_1, (spe8 & 0xffff0000) | (spe4 & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (spe0 & 0xffff0000) | (spdc & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (spd8 & 0xffff0000) | (spd4 & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (spd0 & 0xffff0000) | (spcc & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (spe8 & 0x0000ffff) << 16 | (spe4 & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (spe0 & 0x0000ffff) << 16 | (spdc & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (spd8 & 0x0000ffff) << 16 | (spd4 & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (spd0 & 0x0000ffff) << 16 | (spcc & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (spc8 & 0xffff0000) | (spc4 & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (spc0 & 0xffff0000) | (spbc & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (spb8 & 0xffff0000) | (spb4 & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (spb0 & 0xffff0000) | (spac & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (spc8 & 0x0000ffff) << 16 | (spc4 & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (spc0 & 0x0000ffff) << 16 | (spbc & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (spb8 & 0x0000ffff) << 16 | (spb4 & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_2, (spb0 & 0x0000ffff) << 16 | (spac & 0x0000ffff));
    }

    return gdl;
}


Gfx *sub_GAME_7F098A2C(Gfx *gdl, SkyRelated38 *arg1, SkyRelated38 *arg2, SkyRelated38 *arg3, SkyRelated38 *arg4, f32 arg5)
{
    SkyRelated38 *sp4cc;
    SkyRelated38 *sp4c8;
    SkyRelated38 *sp4c4;
    s32 i;
    u32 stack;
    f32 sp4b8;
    f32 sp4b4;
    f32 sp4b0;
    f32 sp4ac;
    f32 sp4a8;
    f32 sp4a4;
    f32 sp4a0[1];
    f32 sp49c[1];
    f32 sp498[1];
    f32 sp494[1];
    f32 sp490[1];
    f32 sp48c[1];
    f32 sp488;
    f32 sp484;
    f32 sp480[1];
    f32 sp47c[1];
    f32 sp478[1];
    f32 sp474[1];
    f32 sp470[1];
    f32 sp46c[1];
    f32 sp468[1];
    f32 sp464[1];
    SkyRelated38 *swap1;
    SkyRelated38 *swap2;
    SkyRelated38 *swap3;
    f32 sp454[1];
    u32 stack07;
    f32 sp44c[1];
    u32 stack08;
    u32 stack09;
    f32 sp440[1];
    f32 sp43c[1];
    f32 sp438[1];
    f32 sp434[1];
    f32 sp430[1];
    f32 sp42c[1];
    f32 sp428[1];
    f32 sp424[1];
    f32 sp420[1];
    f32 sp41c[1];
    f32 sp418[1];
    f32 sp414[1];
    f32 sp410[1];
    f32 sp40c[1];
    f32 sp408[1];
    f32 sp404[1];
    f32 sp400[1];
    f32 sp3fc[1];
    f32 sp3f8[1];
    f32 sp3f4[1];
    f32 sp3f0[1];
    f32 sp3ec[1];
    f32 sp3e8[1];
    f32 sp3e4[1];
    f32 sp3e0[1];
    f32 sp3dc[1];
    f32 sp3d8[1];
    f32 sp3d4[1];
    f32 sp3d0[1];
    f32 sp3cc[1];
    f32 sp3c8[1];
    f32 sp3c4[1];
    f32 sp3c0;
    f32 sp3bc[1];
    f32 sp3b8[1];
    f32 sp3b4[1];
    f32 sp3b0[1];
    f32 sp3ac;
    f32 sp3a8[1];
    f32 sp3a4[1];
    f32 sp3a0[1];
    f32 sp39c[1];
    f32 sp398[1];
    f32 sp394[1];
    f32 sp390[1];
    f32 sp38c[1];
    f32 sp388[1];
    f32 sp384[1];
    f32 sp380[1];
    f32 sp37c[1];
    f32 sp378[1];
    f32 sp374[1];
    f32 sp370[1];
    f32 sp36c[1];
    f32 sp368[1];
    f32 sp364[1];
    f32 sp354[4];
    f32 sp334[8];
    f32 sp314[8];
    f32 sp2f4[8];
    f32 sp2d4[8];
    f32 sp2b4[8];
    f32 sp294[8];
    f32 sp274[8];
    f32 sp254[8];
    u32 stack10;
    u32 stack11;
    u32 stack12;
    u32 stack13;
    u32 stack00;
    f32 sp23c[1];
    f32 sp238[1];
    f32 sp234[1];
    f32 sp214[8];
    f32 sp1f4[8];
    u32 stack03;
    u32 stack04;
    u32 stack05;
    u32 stack06;
    u32 stack15;
    f32 sp1dc[1];
    f32 sp1d8[1];
    f32 sp1d4[1];
    u32 stack01;
    u32 stack02;
    u32 stack14;
    f32 sp1c4[1];
    u32 stack16;

    if (sub_GAME_7F0977B4(arg1, arg2)
            || sub_GAME_7F0977B4(arg2, arg3)
            || sub_GAME_7F0977B4(arg3, arg1)
            || sub_GAME_7F0977B4(arg4, arg1)
            || sub_GAME_7F0977B4(arg4, arg2)
            || sub_GAME_7F0977B4(arg4, arg3))
    {
        return gdl;
    }

    sp3c0 = arg5 / 65536.0f;

    sp4b8 = arg2->unk28 - arg1->unk28;
    sp4b4 = arg2->unk2c - arg1->unk2c;
    sp4b0 = arg3->unk28 - arg1->unk28;
    sp4ac = arg3->unk2c - arg1->unk2c;

    sp488 = ((sp4b0 * sp4b4) - (sp4b8 * sp4ac)) / 65536.0f;

    sp484 = 1.0f / sp488;

    sp4cc = arg1;
    sp4c8 = arg2;
    sp4c4 = arg3;

    if (sp4c8->unk2c < sp4cc->unk2c)
    {
        swap1 = sp4c8;
        sp4c8 = sp4cc;
        sp4cc = swap1;

        sp488 *= -1.0f;
        sp484 *= -1.0f;
    }

    if (sp4c4->unk2c < sp4c8->unk2c)
    {
        swap2 = sp4c8;
        sp4c8 = sp4c4;
        sp4c4 = swap2;

        sp488 *= -1.0f;
        sp484 *= -1.0f;
    }

    if (sp4c8->unk2c < sp4cc->unk2c)
    {
        swap3 = sp4c8;
        sp4c8 = sp4cc;
        sp4cc = swap3;

        sp488 *= -1.0f;
        sp484 *= -1.0f;
    }

    sp464[0] = sp4c8->unk28 * 0.25f;
    sp468[0] = 0.0f;
    sp46c[0] = sp4cc->unk28 * 0.25f;
    sp470[0] = 0.0f;
    sp474[0] = sp4cc->unk28 * 0.25f;
    sp478[0] = 0.0f;
    sp480[0] = 0.0f;
    sp47c[0] = 0.0f;

    sp48c[0] = sp4c4->unk28;
    sp490[0] = sp4c4->unk2c;
    sp494[0] = sp4c8->unk28;
    sp498[0] = sp4c8->unk2c;
    sp49c[0] = sp4cc->unk28;
    sp4a0[0] = sp4cc->unk2c;

    sp4b8 = sp494[0] - sp49c[0];
    sp4b4 = sp498[0] - sp4a0[0];
    sp4b0 = sp48c[0] - sp49c[0];
    sp4ac = sp490[0] - sp4a0[0];
    sp4a8 = sp48c[0] - sp494[0];
    sp4a4 = sp490[0] - sp498[0];

    sp440[0] = 0.0f;
    sp43c[0] = 0.0f;
    sp420[0] = 0.0f;
    sp41c[0] = 0.0f;
    sp3e4[0] = 0.0f;
    sp3ec[0] = 0.0f;
    sp3f4[0] = 0.0f;
    sp400[0] = 0.0f;
    sp3fc[0] = 0.0f;
    sp3c4[0] = 0.0f;
    sp3cc[0] = 0.0f;
    sp3d4[0] = 0.0f;
    sp3e0[0] = 0.0f;
    sp3dc[0] = 0.0f;

    sp424[0] = sp4a8 / 4.0f;
    sp428[0] = sp4a4 / 4.0f;
    sp42c[0] = sp4b8 / 4.0f;
    sp430[0] = sp4b4 / 4.0f;
    sp434[0] = sp4b0 / 4.0f;
    sp438[0] = sp4ac / 4.0f;

    sp404[0] = sp4a8 * 4.0f;
    sp408[0] = sp4a4 * 4.0f;
    sp40c[0] = sp4b8 * 4.0f;
    sp410[0] = sp4b4 * 4.0f;
    sp414[0] = sp4b0 * 4.0f;
    sp418[0] = sp4ac * 4.0f;

    sp3e8[0] = 4.0f / sp4a4;
    sp3f0[0] = 4.0f / sp4b4;
    sp3f8[0] = 4.0f / sp4ac;

    sp3c8[0] = sp4a8 / sp4a4;
    sp3d0[0] = sp4b8 / sp4b4;
    sp3d8[0] = sp4b0 / sp4ac;

    sp3c8[0] = sub_GAME_7F093C48(sp3c8[0], -1878.0f, 1877.0f);
    sp3d0[0] = sub_GAME_7F093C48(sp3d0[0], -1878.0f, 1877.0f);
    sp3d8[0] = sub_GAME_7F093C48(sp3d8[0], -1878.0f, 1877.0f);

    sp44c[0] = sp46c[0];
    sp454[0] = sp474[0];

    if (arg1->unk28 < arg2->unk28)
    {
        f32 sp1bc;

        if (arg3->unk2c - arg4->unk2c < 1.0f)
        {
            sp1bc = -1878.0f;
        }
        else
        {
            sp1bc = -(getPlayer_c_screenwidth() - 0.25f) / ((arg3->unk2c - arg4->unk2c) / 4.0f);
        }

        gImmp1(gdl++, G_RDPHALF_1, (G_TRI_SHADE_TXTR << 24) | 0x00800000 | (s32) arg3->unk2c);
        gImmp1(gdl++, G_RDPHALF_CONT, (s32) arg4->unk2c << 16 | (s32) arg1->unk2c);

        gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(getPlayer_c_screenleft() + getPlayer_c_screenwidth() - 0.25f));
        gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(sp1bc));

        gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(getPlayer_c_screenleft()));
        gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(0.0f));

        gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(getPlayer_c_screenleft() + getPlayer_c_screenwidth() - 0.25f));
        gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(0.0f));
    }
    else
    {
        f32 sp198;

        if (arg3->unk2c - arg4->unk2c < 1.0f)
        {
            sp198 = 1877.0f;
        }
        else
        {
            sp198 = (getPlayer_c_screenwidth() - 0.25f) / ((arg3->unk2c - arg4->unk2c) / 4.0f);
        }

        gImmp1(gdl++, G_RDPHALF_1, 0xce000000 | (s32) arg3->unk2c);
        gImmp1(gdl++, G_RDPHALF_CONT, (s32) arg4->unk2c << 16 | (s32) arg1->unk2c);

        gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(getPlayer_c_screenleft()));
        gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(sp198));

        gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(getPlayer_c_screenleft() + getPlayer_c_screenwidth() - 0.25f));
        gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(0.0f));

        gImmp1(gdl++, G_RDPHALF_1, sub_GAME_7F094298(getPlayer_c_screenleft()));
        gImmp1(gdl++, G_RDPHALF_CONT, sub_GAME_7F094298(0.0f));
    }

    sp3b0[0] = sp4cc->unk0c * sp3c0;
    sp3b4[0] = sp4c8->unk0c * sp3c0;
    sp3b8[0] = sp4c4->unk0c * sp3c0;
    sp3bc[0] = arg4->unk0c * sp3c0;

    sp3ac = sp3b0[0];

    if (sp3b4[0] < sp3ac) { sp3ac = sp3b4[0]; }
    if (sp3b8[0] < sp3ac) { sp3ac = sp3b8[0]; }
    if (sp3bc[0] < sp3ac) { sp3ac = sp3bc[0]; }

    sp3ac *= 0.5f;

    sp39c[0] = sp4cc->unk34 * sp3ac;
    sp3a0[0] = sp4c8->unk34 * sp3ac;
    sp3a4[0] = sp4c4->unk34 * sp3ac;
    sp3a8[0] = arg4->unk34 * sp3ac;

    sp36c[0] = sp39c[0] * sp4cc->unk20;
    sp370[0] = sp39c[0] * sp4cc->unk24;
    sp374[0] = sp39c[0] * 32767.0f;
    sp378[0] = sp3a0[0] * sp4c8->unk20;
    sp37c[0] = sp3a0[0] * sp4c8->unk24;
    sp380[0] = sp3a0[0] * 32767.0f;
    sp384[0] = sp3a4[0] * sp4c4->unk20;
    sp388[0] = sp3a4[0] * sp4c4->unk24;
    sp38c[0] = sp3a4[0] * 32767.0f;
    sp390[0] = sp3a8[0] * arg4->unk20;
    sp394[0] = sp3a8[0] * arg4->unk24;
    sp398[0] = sp3a8[0] * 32767.0f;

    sp364[0] = SKYABS(sp36c[0]);
    sp368[0] = SKYABS(sp370[0]);

    if (sp364[0] < SKYABS(sp378[0])) { sp364[0] = SKYABS(sp378[0]); }
    if (sp368[0] < SKYABS(sp37c[0])) { sp368[0] = SKYABS(sp37c[0]); }
    if (sp364[0] < SKYABS(sp384[0])) { sp364[0] = SKYABS(sp384[0]); }
    if (sp368[0] < SKYABS(sp388[0])) { sp368[0] = SKYABS(sp388[0]); }
    if (sp364[0] < SKYABS(sp390[0])) { sp364[0] = SKYABS(sp390[0]); }
    if (sp368[0] < SKYABS(sp394[0])) { sp368[0] = SKYABS(sp394[0]); }

    sp354[0] = sp36c[0]; sp354[1] = sp370[0]; sp354[2] = sp374[0];
    sp334[0] = sp378[0]; sp334[1] = sp37c[0]; sp334[2] = sp380[0];
    sp314[0] = sp384[0]; sp314[1] = sp388[0]; sp314[2] = sp38c[0];

    sp354[3] = sp4cc->unk30;
    sp334[3] = sp4c8->unk30;
    sp314[3] = sp4c4->unk30;

    for (i = 0; i < 4; i++)
    {
        sp2f4[i] = sp334[i] - sp354[i];
        sp2d4[i] = sp314[i] - sp354[i];
    }

    for (i = 0; i < 4; i++)
    {
        sp294[i] = ((sp2d4[i] * sp410[0]) - (sp2f4[i] * sp418[0])) / 65536.0f;
        sp2b4[i] = ((sp2f4[i] * sp414[0]) - (sp2d4[i] * sp40c[0])) / 65536.0f;
        sp2d4[i] = sp294[i] * sp484;
        sp2f4[i] = sp2b4[i] * sp484;
        sp274[i] = sp2b4[i] * sp484;
        sp254[i] = sp354[i];
    }

    {
        f32 mult = arg4->unk2c / arg3->unk2c;

        f32 sp170 = arg4->r + ((arg1->r - arg3->r) * mult);
        f32 sp16c = arg4->g + ((arg1->g - arg3->g) * mult);
        f32 sp168 = arg4->b + ((arg1->b - arg3->b) * mult);
        f32 sp164 = arg4->a + ((arg1->a - arg3->a) * mult);

        u32 sp160 = arg1->r * 65536.0f;
        u32 sp15c = arg1->g * 65536.0f;
        u32 sp158 = arg1->b * 65536.0f;
        u32 sp154 = arg1->a * 65536.0f;

        u32 sp150 = sub_GAME_7F094298((sp170 - arg1->r) / ((arg2->unk28 - arg1->unk28) * 0.25f));
        u32 sp14c = sub_GAME_7F094298((sp16c - arg1->g) / ((arg2->unk28 - arg1->unk28) * 0.25f));
        u32 sp148 = sub_GAME_7F094298((sp168 - arg1->b) / ((arg2->unk28 - arg1->unk28) * 0.25f));
        u32 sp144 = sub_GAME_7F094298((sp164 - arg1->a) / ((arg2->unk28 - arg1->unk28) * 0.25f));

        u32 sp140;
        u32 sp13c;
        u32 sp138;
        u32 sp134;
        u32 sp130;
        u32 sp12c;
        u32 sp128;
        u32 sp124;

        sp140 = sp130 = sub_GAME_7F094298((arg3->r - arg1->r) / ((arg3->unk2c - arg1->unk2c) * 0.25f));
        sp13c = sp12c = sub_GAME_7F094298((arg3->g - arg1->g) / ((arg3->unk2c - arg1->unk2c) * 0.25f));
        sp138 = sp128 = sub_GAME_7F094298((arg3->b - arg1->b) / ((arg3->unk2c - arg1->unk2c) * 0.25f));
        sp124 = sp134 = sub_GAME_7F094298((arg3->a - arg1->a) / ((arg3->unk2c - arg1->unk2c) * 0.25f));

        gImmp1(gdl++, G_RDPHALF_1, (sp160 & 0xffff0000) | (sp15c & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (sp158 & 0xffff0000) | (sp154 & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (sp150 & 0xffff0000) | (sp14c & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (sp148 & 0xffff0000) | (sp144 & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (sp160 & 0x0000ffff) << 16 | (sp15c & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (sp158 & 0x0000ffff) << 16 | (sp154 & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (sp150 & 0x0000ffff) << 16 | (sp14c & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (sp148 & 0x0000ffff) << 16 | (sp144 & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (sp140 & 0xffff0000) | (sp13c & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (sp138 & 0xffff0000) | (sp134 & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (sp130 & 0xffff0000) | (sp12c & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (sp128 & 0xffff0000) | (sp124 & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (sp140 & 0x0000ffff) << 16 | (sp13c & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (sp138 & 0x0000ffff) << 16 | (sp134 & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (sp130 & 0x0000ffff) << 16 | (sp12c & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (sp128 & 0x0000ffff) << 16 | (sp124 & 0x0000ffff));
    }

    sp234[0] = sp364[0] / 32.0f;
    sp238[0] = sp368[0] / 32.0f;
    sp23c[0] = sp3ac / 32.0f;

    for (i = 0; i < 4; i++)
    {
        sp214[i] = SKYABS(sp2d4[i]) / 32.0f;
        sp1f4[i] = SKYABS(sp2f4[i]) / 32.0f;
    }

    sp1d4[0] = sp234[0] + (2 * sp214[0]) + sp1f4[0];
    sp1d8[0] = sp238[0] + (2 * sp214[1]) + sp1f4[1];
    sp1dc[0] = sp23c[0] + (2 * sp214[2]) + sp1f4[2];

    if (sp1d4[0] < sp1d8[0]) { sp1d4[0] = sp1d8[0]; }
    if (sp1d4[0] < sp1dc[0]) { sp1d4[0] = sp1dc[0]; }

    sp1d4[0] *= (1.0f / 1024.0f);

    if (sp1d4[0] > 1.0f)
    {
        sp1c4[0] = 1.0f / sp1d4[0];
    }
    else
    {
        sp1c4[0] = 1.0f;
    }

    {
        u32 spe0;
        u32 spdc;
        u32 spd8;
        u32 spd4;
        u32 spd0;
        u32 spcc;
        u32 spc8;
        u32 spc4;
        u32 spc0;
        u32 spbc;
        u32 spb8;
        u32 spb4;
        u32 spb0;
        u32 spac;
        u32 spa8;
        u32 spa4;

        spe0 = sub_GAME_7F094298(sp254[0] * sp1c4[0]);
        spdc = sub_GAME_7F094298(sp254[1] * sp1c4[0]);
        spd8 = sub_GAME_7F094298(sp254[2] * sp1c4[0]);
        spd4 = sub_GAME_7F094298(sp254[3] * sp1c4[0]);

        spd0 = sub_GAME_7F094298(sp2d4[0] * sp1c4[0]);
        spcc = sub_GAME_7F094298(sp2d4[1] * sp1c4[0]);
        spc8 = sub_GAME_7F094298(sp2d4[2] * sp1c4[0]);
        spc4 = sub_GAME_7F094298(sp2d4[3] * sp1c4[0]);

        spb0 = sub_GAME_7F094298(sp2f4[0] * sp1c4[0]);
        spac = sub_GAME_7F094298(sp2f4[1] * sp1c4[0]);
        spa8 = sub_GAME_7F094298(sp2f4[2] * sp1c4[0]);
        spa4 = sub_GAME_7F094298(sp2f4[3] * sp1c4[0]);

        spc0 = sub_GAME_7F094298(sp274[0] * sp1c4[0]);
        spbc = sub_GAME_7F094298(sp274[1] * sp1c4[0]);
        spb8 = sub_GAME_7F094298(sp274[2] * sp1c4[0]);
        spb4 = sub_GAME_7F094298(sp274[3] * sp1c4[0]);

        gImmp1(gdl++, G_RDPHALF_1, (spe0 & 0xffff0000) | (spdc & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (spd8 & 0xffff0000) | (spd4 & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (spd0 & 0xffff0000) | (spcc & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (spc8 & 0xffff0000) | (spc4 & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (spe0 & 0x0000ffff) << 16 | (spdc & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (spd8 & 0x0000ffff) << 16 | (spd4 & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (spd0 & 0x0000ffff) << 16 | (spcc & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (spc8 & 0x0000ffff) << 16 | (spc4 & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (spc0 & 0xffff0000) | (spbc & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (spb8 & 0xffff0000) | (spb4 & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (spb0 & 0xffff0000) | (spac & 0xffff0000) >> 16);
        gImmp1(gdl++, G_RDPHALF_CONT, (spa8 & 0xffff0000) | (spa4 & 0xffff0000) >> 16);

        gImmp1(gdl++, G_RDPHALF_1, (spc0 & 0x0000ffff) << 16 | (spbc & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_CONT, (spb8 & 0x0000ffff) << 16 | (spb4 & 0x0000ffff));

        gImmp1(gdl++, G_RDPHALF_1, (spb0 & 0x0000ffff) << 16 | (spac & 0x0000ffff));
        gImmp1(gdl++, G_RDPHALF_2, (spa8 & 0x0000ffff) << 16 | (spa4 & 0x0000ffff));
    }

    return gdl;
}
