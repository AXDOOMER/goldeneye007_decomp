#include <ultra64.h>
#include <memp.h>
#include "player.h"
#include "unk_092E50.h"
#include "bondview.h"
#include "lvl.h"
#include "fog.h"

#define SKYABS(val) (val >= 0.0f ? (val) : -(val))

// bss
s32 copyof_stagenum;

s32 dword_CODE_bss_80079E94;
char dword_CODE_bss_80079E98[0x48];

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
f32 sub_GAME_7F0938FC(void *arg0, void *arg1, void *arg2) {
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





#ifdef NONMATCHING
f32 sub_GAME_7F093A78(void *arg0, void *arg1, void *arg2) {
    f32 sp24;
    f32 sp2C;
    s32 temp_s1;
    f32 temp_f2_2;
    f32 temp_f2;
    f32 temp_f12;
    f32 phi_f2;
    f32 phi_f16;
    f32 phi_f2_2;
    f32 phi_return;

    // Node 0
    temp_s1 = bondviewGetCurrentPlayersPosition();
    temp_f2_2 = ((-2.0f * arg0->unk4) / sqrtf((((arg0->unk8 * arg0->unk8) + (*arg0 * *arg0)) + D_8005752C), *arg0));
    phi_f2 = temp_f2_2;
    if (1.0f < temp_f2_2)
    {
        // Node 1
        phi_f2 = 1.0f;
    }
    // Node 2
    *arg2 = (f32) (1.0f - phi_f2);
    if (0.0f == arg0->unk4)
    {
        // Node 3
        phi_f16 = D_80057530;
    }
    else
    {
        // Node 4
        phi_f16 = arg0->unk4;
    }
    // Node 5
    phi_return = arg0->unk4;
    if (phi_f16 < 0.0f)
    {
        // Node 6
        sp24 = (f32) phi_f16;
        temp_f2 = ((fogGetCurrentEnvironmentp(1.0f, 0.0f)->unk24 - temp_s1->unk4) / phi_f16);
        sp2C = temp_f2;
        temp_f12 = (sqrtf(((arg0->unk8 * arg0->unk8) + (*arg0 * *arg0)), *arg0) * temp_f2);
        phi_f2_2 = temp_f2;
        if (D_80057534 < temp_f12)
        {
            // Node 7
            phi_f2_2 = (temp_f2 * (D_80057534 / temp_f12));
        }
        // Node 8
        *arg1 = (f32) ((*arg0 * phi_f2_2) + *temp_s1);
        arg1->unk4 = (f32) (temp_s1->unk4 + (phi_f2_2 * phi_f16));
        arg1->unk8 = (f32) ((arg0->unk8 * phi_f2_2) + temp_s1->unk8);
        phi_return = 1.401298464324817e-45f;
    }
    // Node 9
    return phi_return;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005752C
.word 0x38d1b717 /*0.000099999997*/
glabel D_80057530
.word 0xbc23d70a /*-0.01*/
glabel D_80057534
.word 0x48927c00 /*300000.0*/
.text
glabel sub_GAME_7F093A78
/* 0C85A8 7F093A78 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C85AC 7F093A7C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C85B0 7F093A80 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C85B4 7F093A84 00808025 */  move  $s0, $a0
/* 0C85B8 7F093A88 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C85BC 7F093A8C AFA5003C */  sw    $a1, 0x3c($sp)
/* 0C85C0 7F093A90 0FC227F5 */  jal   bondviewGetCurrentPlayersPosition
/* 0C85C4 7F093A94 AFA60040 */   sw    $a2, 0x40($sp)
/* 0C85C8 7F093A98 C6000008 */  lwc1  $f0, 8($s0)
/* 0C85CC 7F093A9C C60E0000 */  lwc1  $f14, ($s0)
/* 0C85D0 7F093AA0 3C018005 */  lui   $at, %hi(D_8005752C)
/* 0C85D4 7F093AA4 46000102 */  mul.s $f4, $f0, $f0
/* 0C85D8 7F093AA8 C42A752C */  lwc1  $f10, %lo(D_8005752C)($at)
/* 0C85DC 7F093AAC 00408825 */  move  $s1, $v0
/* 0C85E0 7F093AB0 460E7182 */  mul.s $f6, $f14, $f14
/* 0C85E4 7F093AB4 46062200 */  add.s $f8, $f4, $f6
/* 0C85E8 7F093AB8 0C007DF8 */  jal   sqrtf
/* 0C85EC 7F093ABC 460A4300 */   add.s $f12, $f8, $f10
/* 0C85F0 7F093AC0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C85F4 7F093AC4 44816000 */  mtc1  $at, $f12
/* 0C85F8 7F093AC8 3C01C000 */  li    $at, 0xC0000000 # -2.000000
/* 0C85FC 7F093ACC 44812000 */  mtc1  $at, $f4
/* 0C8600 7F093AD0 C6060004 */  lwc1  $f6, 4($s0)
/* 0C8604 7F093AD4 3C018005 */  lui   $at, %hi(D_80057530)
/* 0C8608 7F093AD8 00001025 */  move  $v0, $zero
/* 0C860C 7F093ADC 46062202 */  mul.s $f8, $f4, $f6
/* 0C8610 7F093AE0 46004083 */  div.s $f2, $f8, $f0
/* 0C8614 7F093AE4 4602603C */  c.lt.s $f12, $f2
/* 0C8618 7F093AE8 00000000 */  nop
/* 0C861C 7F093AEC 45020003 */  bc1fl .L7F093AFC
/* 0C8620 7F093AF0 46026281 */   sub.s $f10, $f12, $f2
/* 0C8624 7F093AF4 46006086 */  mov.s $f2, $f12
/* 0C8628 7F093AF8 46026281 */  sub.s $f10, $f12, $f2
.L7F093AFC:
/* 0C862C 7F093AFC 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0C8630 7F093B00 44807000 */  mtc1  $zero, $f14
/* 0C8634 7F093B04 E5CA0000 */  swc1  $f10, ($t6)
/* 0C8638 7F093B08 C6000004 */  lwc1  $f0, 4($s0)
/* 0C863C 7F093B0C 46007032 */  c.eq.s $f14, $f0
/* 0C8640 7F093B10 00000000 */  nop
/* 0C8644 7F093B14 45020004 */  bc1fl .L7F093B28
/* 0C8648 7F093B18 46000406 */   mov.s $f16, $f0
/* 0C864C 7F093B1C 10000002 */  b     .L7F093B28
/* 0C8650 7F093B20 C4307530 */   lwc1  $f16, %lo(D_80057530)($at)
/* 0C8654 7F093B24 46000406 */  mov.s $f16, $f0
.L7F093B28:
/* 0C8658 7F093B28 460E803C */  c.lt.s $f16, $f14
/* 0C865C 7F093B2C 00000000 */  nop
/* 0C8660 7F093B30 4500002D */  bc1f  .L7F093BE8
/* 0C8664 7F093B34 00000000 */   nop
/* 0C8668 7F093B38 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C866C 7F093B3C E7B00024 */   swc1  $f16, 0x24($sp)
/* 0C8670 7F093B40 C4440024 */  lwc1  $f4, 0x24($v0)
/* 0C8674 7F093B44 C6260004 */  lwc1  $f6, 4($s1)
/* 0C8678 7F093B48 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0C867C 7F093B4C C6000008 */  lwc1  $f0, 8($s0)
/* 0C8680 7F093B50 46062201 */  sub.s $f8, $f4, $f6
/* 0C8684 7F093B54 C60E0000 */  lwc1  $f14, ($s0)
/* 0C8688 7F093B58 46000282 */  mul.s $f10, $f0, $f0
/* 0C868C 7F093B5C 00000000 */  nop
/* 0C8690 7F093B60 460E7102 */  mul.s $f4, $f14, $f14
/* 0C8694 7F093B64 46104083 */  div.s $f2, $f8, $f16
/* 0C8698 7F093B68 46045300 */  add.s $f12, $f10, $f4
/* 0C869C 7F093B6C 0C007DF8 */  jal   sqrtf
/* 0C86A0 7F093B70 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 0C86A4 7F093B74 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 0C86A8 7F093B78 3C018005 */  lui   $at, %hi(D_80057534)
/* 0C86AC 7F093B7C C4327534 */  lwc1  $f18, %lo(D_80057534)($at)
/* 0C86B0 7F093B80 46020302 */  mul.s $f12, $f0, $f2
/* 0C86B4 7F093B84 C7B00024 */  lwc1  $f16, 0x24($sp)
/* 0C86B8 7F093B88 460C903C */  c.lt.s $f18, $f12
/* 0C86BC 7F093B8C 00000000 */  nop
/* 0C86C0 7F093B90 45020005 */  bc1fl .L7F093BA8
/* 0C86C4 7F093B94 C6080000 */   lwc1  $f8, ($s0)
/* 0C86C8 7F093B98 460C9183 */  div.s $f6, $f18, $f12
/* 0C86CC 7F093B9C 46061082 */  mul.s $f2, $f2, $f6
/* 0C86D0 7F093BA0 00000000 */  nop
/* 0C86D4 7F093BA4 C6080000 */  lwc1  $f8, ($s0)
.L7F093BA8:
/* 0C86D8 7F093BA8 C6240000 */  lwc1  $f4, ($s1)
/* 0C86DC 7F093BAC 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C86E0 7F093BB0 46024282 */  mul.s $f10, $f8, $f2
/* 0C86E4 7F093BB4 24020001 */  li    $v0, 1
/* 0C86E8 7F093BB8 46045180 */  add.s $f6, $f10, $f4
/* 0C86EC 7F093BBC 46101282 */  mul.s $f10, $f2, $f16
/* 0C86F0 7F093BC0 E4660000 */  swc1  $f6, ($v1)
/* 0C86F4 7F093BC4 C6280004 */  lwc1  $f8, 4($s1)
/* 0C86F8 7F093BC8 460A4100 */  add.s $f4, $f8, $f10
/* 0C86FC 7F093BCC E4640004 */  swc1  $f4, 4($v1)
/* 0C8700 7F093BD0 C6060008 */  lwc1  $f6, 8($s0)
/* 0C8704 7F093BD4 C62A0008 */  lwc1  $f10, 8($s1)
/* 0C8708 7F093BD8 46023202 */  mul.s $f8, $f6, $f2
/* 0C870C 7F093BDC 460A4100 */  add.s $f4, $f8, $f10
/* 0C8710 7F093BE0 10000001 */  b     .L7F093BE8
/* 0C8714 7F093BE4 E4640008 */   swc1  $f4, 8($v1)
.L7F093BE8:
/* 0C8718 7F093BE8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C871C 7F093BEC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C8720 7F093BF0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C8724 7F093BF4 03E00008 */  jr    $ra
/* 0C8728 7F093BF8 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif



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
void sub_GAME_7F093CB0(void) {

}
#else
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
void sub_GAME_7F093FA4(void) {

}
#else
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
    D_8003FD94[0] = (g_GlobalTimerDelta + D_8003FD94[0]);
    #else
    D_8003FD94[0] = (g_ClockTimer + D_8003FD94[0]);
    #endif
    if ( D_8003FD94[0] > 4096.0f)
    {
        D_8003FD94[0] -= 4096.0f;
    }
}




#ifdef NONMATCHING
void sub_GAME_7F094488(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80057540
.word 0x3dcccccd /*0.1*/
/*D:80057544*/
glabel jpt_80057544
.word .L7F094A48
.word .L7F095284
.word .L7F0953CC
.word .L7F094B4C
.word .L7F095514
.word .L7F094E60
.word .L7F0957A4
.word .L7F0951BC
.word .L7F09565C
.word .L7F0957A4
.word .L7F094D5C
.word .L7F0950F4
.word .L7F094C50
.word .L7F09502C
.word .L7F094F64
.word .L7F094A40

glabel D_80057584
.word 0x477fff00 /*65535.0*/
glabel D_80057588
.word 0x449fe000 /*1279.0*/
glabel D_8005758C
.word 0x446fc000 /*959.0*/

/*D:80057590*/
glabel jpt_80057590
.word .L7F095E14
.word .L7F09643C
.word .L7F09652C
.word .L7F096094
.word .L7F09661C
.word .L7F0961CC
.word .L7F096E20
.word .L7F096C98
.word .L7F09670C
.word .L7F096E20
.word .L7F096304
.word .L7F096B10
.word .L7F095F58
.word .L7F096984
.word .L7F0967FC
.word .L7F095E1C

glabel D_800575D0
.word 0x477fff00 /*65535.0*/
glabel D_800575D4
.word 0x46fffe00 /*32767.0*/
glabel D_800575D8
.word 0x46fffe00 /*32767.0*/
glabel D_800575DC
.word 0x43ff8000 /*511.0*/
glabel D_800575E0
.word 0xc57fa000 /*-4090.0*/
glabel D_800575E4
.word 0xc57fa000 /*-4090.0*/
.text
glabel sub_GAME_7F094488
/* 0C8FB8 7F094488 27BDF950 */  addiu $sp, $sp, -0x6b0
/* 0C8FBC 7F09448C AFBF004C */  sw    $ra, 0x4c($sp)
/* 0C8FC0 7F094490 AFB10048 */  sw    $s1, 0x48($sp)
/* 0C8FC4 7F094494 AFB00044 */  sw    $s0, 0x44($sp)
/* 0C8FC8 7F094498 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0C8FCC 7F09449C F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0C8FD0 7F0944A0 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0C8FD4 7F0944A4 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0C8FD8 7F0944A8 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0C8FDC 7F0944AC 0FC2D20F */  jal   get_room_data_float1
/* 0C8FE0 7F0944B0 AFA406B0 */   sw    $a0, 0x6b0($sp)
/* 0C8FE4 7F0944B4 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 0C8FE8 7F0944B8 44812000 */  mtc1  $at, $f4
/* 0C8FEC 7F0944BC AFA00430 */  sw    $zero, 0x430($sp)
/* 0C8FF0 7F0944C0 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8FF4 7F0944C4 46040603 */   div.s $f24, $f0, $f4
/* 0C8FF8 7F0944C8 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0C8FFC 7F0944CC 00408025 */   move  $s0, $v0
/* 0C9000 7F0944D0 904E000B */  lbu   $t6, 0xb($v0)
/* 0C9004 7F0944D4 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0C9008 7F0944D8 55C0007B */  bnezl $t6, .L7F0946C8
/* 0C900C 7F0944DC 92050008 */   lbu   $a1, 8($s0)
/* 0C9010 7F0944E0 0FC26919 */  jal   getPlayerCount
/* 0C9014 7F0944E4 00000000 */   nop
/* 0C9018 7F0944E8 24010001 */  li    $at, 1
/* 0C901C 7F0944EC 1441003B */  bne   $v0, $at, .L7F0945DC
/* 0C9020 7F0944F0 3C088008 */   lui   $t0, %hi(g_CurrentPlayer)
/* 0C9024 7F0944F4 8FAF06B0 */  lw    $t7, 0x6b0($sp)
/* 0C9028 7F0944F8 3C19BA00 */  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
/* 0C902C 7F0944FC 37391402 */  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
/* 0C9030 7F094500 25F80008 */  addiu $t8, $t7, 8
/* 0C9034 7F094504 AFB806B0 */  sw    $t8, 0x6b0($sp)
/* 0C9038 7F094508 3C0A0030 */  lui   $t2, 0x30
/* 0C903C 7F09450C ADEA0004 */  sw    $t2, 4($t7)
/* 0C9040 7F094510 ADF90000 */  sw    $t9, ($t7)
/* 0C9044 7F094514 9207000A */  lbu   $a3, 0xa($s0)
/* 0C9048 7F094518 92060009 */  lbu   $a2, 9($s0)
/* 0C904C 7F09451C 92050008 */  lbu   $a1, 8($s0)
/* 0C9050 7F094520 0C0011B4 */  jal   viSetFillColor
/* 0C9054 7F094524 8FA406B0 */   lw    $a0, 0x6b0($sp)
/* 0C9058 7F094528 244B0008 */  addiu $t3, $v0, 8
/* 0C905C 7F09452C AFAB06B0 */  sw    $t3, 0x6b0($sp)
/* 0C9060 7F094530 0C001127 */  jal   viGetViewWidth
/* 0C9064 7F094534 00408825 */   move  $s1, $v0
/* 0C9068 7F094538 0C001145 */  jal   viGetViewLeft
/* 0C906C 7F09453C A7A2007A */   sh    $v0, 0x7a($sp)
/* 0C9070 7F094540 0C001149 */  jal   viGetViewTop
/* 0C9074 7F094544 A7A2007C */   sh    $v0, 0x7c($sp)
/* 0C9078 7F094548 00028400 */  sll   $s0, $v0, 0x10
/* 0C907C 7F09454C 00106403 */  sra   $t4, $s0, 0x10
/* 0C9080 7F094550 0C00112B */  jal   viGetViewHeight
/* 0C9084 7F094554 01808025 */   move  $s0, $t4
/* 0C9088 7F094558 87AD007C */  lh    $t5, 0x7c($sp)
/* 0C908C 7F09455C 87AE007A */  lh    $t6, 0x7a($sp)
/* 0C9090 7F094560 00505821 */  addu  $t3, $v0, $s0
/* 0C9094 7F094564 256CFFFF */  addiu $t4, $t3, -1
/* 0C9098 7F094568 01AE7821 */  addu  $t7, $t5, $t6
/* 0C909C 7F09456C 25F8FFFF */  addiu $t8, $t7, -1
/* 0C90A0 7F094570 318D03FF */  andi  $t5, $t4, 0x3ff
/* 0C90A4 7F094574 000D7080 */  sll   $t6, $t5, 2
/* 0C90A8 7F094578 331903FF */  andi  $t9, $t8, 0x3ff
/* 0C90AC 7F09457C 3C01F600 */  lui   $at, 0xf600
/* 0C90B0 7F094580 01C17825 */  or    $t7, $t6, $at
/* 0C90B4 7F094584 00195380 */  sll   $t2, $t9, 0xe
/* 0C90B8 7F094588 01EAC025 */  or    $t8, $t7, $t2
/* 0C90BC 7F09458C 0C001145 */  jal   viGetViewLeft
/* 0C90C0 7F094590 AE380000 */   sw    $t8, ($s1)
/* 0C90C4 7F094594 00028400 */  sll   $s0, $v0, 0x10
/* 0C90C8 7F094598 0010CC03 */  sra   $t9, $s0, 0x10
/* 0C90CC 7F09459C 0C001149 */  jal   viGetViewTop
/* 0C90D0 7F0945A0 03208025 */   move  $s0, $t9
/* 0C90D4 7F0945A4 304B03FF */  andi  $t3, $v0, 0x3ff
/* 0C90D8 7F0945A8 320D03FF */  andi  $t5, $s0, 0x3ff
/* 0C90DC 7F0945AC 000D7380 */  sll   $t6, $t5, 0xe
/* 0C90E0 7F0945B0 000B6080 */  sll   $t4, $t3, 2
/* 0C90E4 7F0945B4 018E7825 */  or    $t7, $t4, $t6
/* 0C90E8 7F0945B8 AE2F0004 */  sw    $t7, 4($s1)
/* 0C90EC 7F0945BC 8FAA06B0 */  lw    $t2, 0x6b0($sp)
/* 0C90F0 7F0945C0 3C19E700 */  lui   $t9, 0xe700
/* 0C90F4 7F0945C4 25580008 */  addiu $t8, $t2, 8
/* 0C90F8 7F0945C8 AFB806B0 */  sw    $t8, 0x6b0($sp)
/* 0C90FC 7F0945CC AD400004 */  sw    $zero, 4($t2)
/* 0C9100 7F0945D0 AD590000 */  sw    $t9, ($t2)
/* 0C9104 7F0945D4 10000B62 */  b     .L7F097360
/* 0C9108 7F0945D8 8FA206B0 */   lw    $v0, 0x6b0($sp)
.L7F0945DC:
/* 0C910C 7F0945DC 8FAB06B0 */  lw    $t3, 0x6b0($sp)
/* 0C9110 7F0945E0 3C09E700 */  lui   $t1, 0xe700
/* 0C9114 7F0945E4 3C0FBA00 */  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
/* 0C9118 7F0945E8 256D0008 */  addiu $t5, $t3, 8
/* 0C911C 7F0945EC AFAD06B0 */  sw    $t5, 0x6b0($sp)
/* 0C9120 7F0945F0 AD600004 */  sw    $zero, 4($t3)
/* 0C9124 7F0945F4 AD690000 */  sw    $t1, ($t3)
/* 0C9128 7F0945F8 8FAC06B0 */  lw    $t4, 0x6b0($sp)
/* 0C912C 7F0945FC 35EF1402 */  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
/* 0C9130 7F094600 3C0A0030 */  lui   $t2, 0x30
/* 0C9134 7F094604 258E0008 */  addiu $t6, $t4, 8
/* 0C9138 7F094608 AFAE06B0 */  sw    $t6, 0x6b0($sp)
/* 0C913C 7F09460C AD8A0004 */  sw    $t2, 4($t4)
/* 0C9140 7F094610 AD8F0000 */  sw    $t7, ($t4)
/* 0C9144 7F094614 8FB806B0 */  lw    $t8, 0x6b0($sp)
/* 0C9148 7F094618 3C0BB900 */  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900
/* 0C914C 7F09461C 356B031D */  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d
/* 0C9150 7F094620 27190008 */  addiu $t9, $t8, 8
/* 0C9154 7F094624 AFB906B0 */  sw    $t9, 0x6b0($sp)
/* 0C9158 7F094628 AF000004 */  sw    $zero, 4($t8)
/* 0C915C 7F09462C AF0B0000 */  sw    $t3, ($t8)
/* 0C9160 7F094630 8FA606B0 */  lw    $a2, 0x6b0($sp)
/* 0C9164 7F094634 2508A0B0 */  addiu $t0, %lo(g_CurrentPlayer) # addiu $t0, $t0, -0x5f50
/* 0C9168 7F094638 8D020000 */  lw    $v0, ($t0)
/* 0C916C 7F09463C 24CC0008 */  addiu $t4, $a2, 8
/* 0C9170 7F094640 AFAC06B0 */  sw    $t4, 0x6b0($sp)
/* 0C9174 7F094644 844E07F4 */  lh    $t6, 0x7f4($v0)
/* 0C9178 7F094648 844F07F0 */  lh    $t7, 0x7f0($v0)
/* 0C917C 7F09464C 844C07F6 */  lh    $t4, 0x7f6($v0)
/* 0C9180 7F094650 3C01F600 */  lui   $at, 0xf600
/* 0C9184 7F094654 01CF5021 */  addu  $t2, $t6, $t7
/* 0C9188 7F094658 844E07F2 */  lh    $t6, 0x7f2($v0)
/* 0C918C 7F09465C 2558FFFF */  addiu $t8, $t2, -1
/* 0C9190 7F094660 331903FF */  andi  $t9, $t8, 0x3ff
/* 0C9194 7F094664 018E7821 */  addu  $t7, $t4, $t6
/* 0C9198 7F094668 25EAFFFF */  addiu $t2, $t7, -1
/* 0C919C 7F09466C 00195B80 */  sll   $t3, $t9, 0xe
/* 0C91A0 7F094670 315803FF */  andi  $t8, $t2, 0x3ff
/* 0C91A4 7F094674 0018C880 */  sll   $t9, $t8, 2
/* 0C91A8 7F094678 01616825 */  or    $t5, $t3, $at
/* 0C91AC 7F09467C 01B95825 */  or    $t3, $t5, $t9
/* 0C91B0 7F094680 ACCB0000 */  sw    $t3, ($a2)
/* 0C91B4 7F094684 8D020000 */  lw    $v0, ($t0)
/* 0C91B8 7F094688 844C07F4 */  lh    $t4, 0x7f4($v0)
/* 0C91BC 7F09468C 844A07F6 */  lh    $t2, 0x7f6($v0)
/* 0C91C0 7F094690 318E03FF */  andi  $t6, $t4, 0x3ff
/* 0C91C4 7F094694 315803FF */  andi  $t8, $t2, 0x3ff
/* 0C91C8 7F094698 00186880 */  sll   $t5, $t8, 2
/* 0C91CC 7F09469C 000E7B80 */  sll   $t7, $t6, 0xe
/* 0C91D0 7F0946A0 01EDC825 */  or    $t9, $t7, $t5
/* 0C91D4 7F0946A4 ACD90004 */  sw    $t9, 4($a2)
/* 0C91D8 7F0946A8 8FAB06B0 */  lw    $t3, 0x6b0($sp)
/* 0C91DC 7F0946AC 256C0008 */  addiu $t4, $t3, 8
/* 0C91E0 7F0946B0 AFAC06B0 */  sw    $t4, 0x6b0($sp)
/* 0C91E4 7F0946B4 AD600004 */  sw    $zero, 4($t3)
/* 0C91E8 7F0946B8 AD690000 */  sw    $t1, ($t3)
/* 0C91EC 7F0946BC 10000B28 */  b     .L7F097360
/* 0C91F0 7F0946C0 8FA206B0 */   lw    $v0, 0x6b0($sp)
/* 0C91F4 7F0946C4 92050008 */  lbu   $a1, 8($s0)
.L7F0946C8:
/* 0C91F8 7F0946C8 92060009 */  lbu   $a2, 9($s0)
/* 0C91FC 7F0946CC 0C0011B4 */  jal   viSetFillColor
/* 0C9200 7F0946D0 9207000A */   lbu   $a3, 0xa($s0)
/* 0C9204 7F0946D4 44806000 */  mtc1  $zero, $f12
/* 0C9208 7F0946D8 27B106A4 */  addiu $s1, $sp, 0x6a4
/* 0C920C 7F0946DC AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0C9210 7F0946E0 02203025 */  move  $a2, $s1
/* 0C9214 7F0946E4 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9218 7F0946E8 46006386 */   mov.s $f14, $f12
/* 0C921C 7F0946EC 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C9220 7F0946F0 00000000 */   nop
/* 0C9224 7F0946F4 3C018005 */  lui   $at, %hi(D_80057540)
/* 0C9228 7F0946F8 C43C7540 */  lwc1  $f28, %lo(D_80057540)($at)
/* 0C922C 7F0946FC 44807000 */  mtc1  $zero, $f14
/* 0C9230 7F094700 27A60698 */  addiu $a2, $sp, 0x698
/* 0C9234 7F094704 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9238 7F094708 461C0301 */   sub.s $f12, $f0, $f28
/* 0C923C 7F09470C 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C9240 7F094710 00000000 */   nop
/* 0C9244 7F094714 44806000 */  mtc1  $zero, $f12
/* 0C9248 7F094718 461C0381 */  sub.s $f14, $f0, $f28
/* 0C924C 7F09471C 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9250 7F094720 27A6068C */   addiu $a2, $sp, 0x68c
/* 0C9254 7F094724 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C9258 7F094728 00000000 */   nop
/* 0C925C 7F09472C 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C9260 7F094730 46000586 */   mov.s $f22, $f0
/* 0C9264 7F094734 461CB301 */  sub.s $f12, $f22, $f28
/* 0C9268 7F094738 27A60680 */  addiu $a2, $sp, 0x680
/* 0C926C 7F09473C 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9270 7F094740 461C0381 */   sub.s $f14, $f0, $f28
/* 0C9274 7F094744 02202025 */  move  $a0, $s1
/* 0C9278 7F094748 27A50644 */  addiu $a1, $sp, 0x644
/* 0C927C 7F09474C 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9280 7F094750 27A6058C */   addiu $a2, $sp, 0x58c
/* 0C9284 7F094754 AFA20538 */  sw    $v0, 0x538($sp)
/* 0C9288 7F094758 27A40698 */  addiu $a0, $sp, 0x698
/* 0C928C 7F09475C 27A50638 */  addiu $a1, $sp, 0x638
/* 0C9290 7F094760 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9294 7F094764 27A60588 */   addiu $a2, $sp, 0x588
/* 0C9298 7F094768 AFA20534 */  sw    $v0, 0x534($sp)
/* 0C929C 7F09476C 27A4068C */  addiu $a0, $sp, 0x68c
/* 0C92A0 7F094770 27A5062C */  addiu $a1, $sp, 0x62c
/* 0C92A4 7F094774 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C92A8 7F094778 27A60584 */   addiu $a2, $sp, 0x584
/* 0C92AC 7F09477C AFA20530 */  sw    $v0, 0x530($sp)
/* 0C92B0 7F094780 27A40680 */  addiu $a0, $sp, 0x680
/* 0C92B4 7F094784 27A50620 */  addiu $a1, $sp, 0x620
/* 0C92B8 7F094788 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C92BC 7F09478C 27A60580 */   addiu $a2, $sp, 0x580
/* 0C92C0 7F094790 AFA2052C */  sw    $v0, 0x52c($sp)
/* 0C92C4 7F094794 02202025 */  move  $a0, $s1
/* 0C92C8 7F094798 27A505E4 */  addiu $a1, $sp, 0x5e4
/* 0C92CC 7F09479C 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C92D0 7F0947A0 27A6056C */   addiu $a2, $sp, 0x56c
/* 0C92D4 7F0947A4 27A40698 */  addiu $a0, $sp, 0x698
/* 0C92D8 7F0947A8 27A505D8 */  addiu $a1, $sp, 0x5d8
/* 0C92DC 7F0947AC 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C92E0 7F0947B0 27A60568 */   addiu $a2, $sp, 0x568
/* 0C92E4 7F0947B4 27A4068C */  addiu $a0, $sp, 0x68c
/* 0C92E8 7F0947B8 27A505CC */  addiu $a1, $sp, 0x5cc
/* 0C92EC 7F0947BC 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C92F0 7F0947C0 27A60564 */   addiu $a2, $sp, 0x564
/* 0C92F4 7F0947C4 27A40680 */  addiu $a0, $sp, 0x680
/* 0C92F8 7F0947C8 27A505C0 */  addiu $a1, $sp, 0x5c0
/* 0C92FC 7F0947CC 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C9300 7F0947D0 27A60560 */   addiu $a2, $sp, 0x560
/* 0C9304 7F0947D4 8FAE0538 */  lw    $t6, 0x538($sp)
/* 0C9308 7F0947D8 8FAA0530 */  lw    $t2, 0x530($sp)
/* 0C930C 7F0947DC 51CA001F */  beql  $t6, $t2, .L7F09485C
/* 0C9310 7F0947E0 44802000 */   mtc1  $zero, $f4
/* 0C9314 7F0947E4 0FC1E135 */  jal   getPlayer_c_screentop
/* 0C9318 7F0947E8 00000000 */   nop
/* 0C931C 7F0947EC 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C9320 7F0947F0 46000586 */   mov.s $f22, $f0
/* 0C9324 7F0947F4 C7A206A8 */  lwc1  $f2, 0x6a8($sp)
/* 0C9328 7F0947F8 C7B00690 */  lwc1  $f16, 0x690($sp)
/* 0C932C 7F0947FC 27B0065C */  addiu $s0, $sp, 0x65c
/* 0C9330 7F094800 44806000 */  mtc1  $zero, $f12
/* 0C9334 7F094804 46101181 */  sub.s $f6, $f2, $f16
/* 0C9338 7F094808 02003025 */  move  $a2, $s0
/* 0C933C 7F09480C 46061203 */  div.s $f8, $f2, $f6
/* 0C9340 7F094810 46004282 */  mul.s $f10, $f8, $f0
/* 0C9344 7F094814 46165380 */  add.s $f14, $f10, $f22
/* 0C9348 7F094818 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C934C 7F09481C E7AE054C */   swc1  $f14, 0x54c($sp)
/* 0C9350 7F094820 02202025 */  move  $a0, $s1
/* 0C9354 7F094824 27A5068C */  addiu $a1, $sp, 0x68c
/* 0C9358 7F094828 0FC24EFF */  jal   sub_GAME_7F093BFC
/* 0C935C 7F09482C 02003025 */   move  $a2, $s0
/* 0C9360 7F094830 02002025 */  move  $a0, $s0
/* 0C9364 7F094834 27A505FC */  addiu $a1, $sp, 0x5fc
/* 0C9368 7F094838 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C936C 7F09483C 27A60574 */   addiu $a2, $sp, 0x574
/* 0C9370 7F094840 02002025 */  move  $a0, $s0
/* 0C9374 7F094844 27A5059C */  addiu $a1, $sp, 0x59c
/* 0C9378 7F094848 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C937C 7F09484C 27A60554 */   addiu $a2, $sp, 0x554
/* 0C9380 7F094850 10000005 */  b     .L7F094868
/* 0C9384 7F094854 8FB80534 */   lw    $t8, 0x534($sp)
/* 0C9388 7F094858 44802000 */  mtc1  $zero, $f4
.L7F09485C:
/* 0C938C 7F09485C 00000000 */  nop
/* 0C9390 7F094860 E7A4054C */  swc1  $f4, 0x54c($sp)
/* 0C9394 7F094864 8FB80534 */  lw    $t8, 0x534($sp)
.L7F094868:
/* 0C9398 7F094868 8FAF052C */  lw    $t7, 0x52c($sp)
/* 0C939C 7F09486C 530F0021 */  beql  $t8, $t7, .L7F0948F4
/* 0C93A0 7F094870 44804000 */   mtc1  $zero, $f8
/* 0C93A4 7F094874 0FC1E135 */  jal   getPlayer_c_screentop
/* 0C93A8 7F094878 00000000 */   nop
/* 0C93AC 7F09487C 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C93B0 7F094880 46000586 */   mov.s $f22, $f0
/* 0C93B4 7F094884 C7B0069C */  lwc1  $f16, 0x69c($sp)
/* 0C93B8 7F094888 C7A60684 */  lwc1  $f6, 0x684($sp)
/* 0C93BC 7F09488C 46068201 */  sub.s $f8, $f16, $f6
/* 0C93C0 7F094890 46088283 */  div.s $f10, $f16, $f8
/* 0C93C4 7F094894 46005102 */  mul.s $f4, $f10, $f0
/* 0C93C8 7F094898 46162180 */  add.s $f6, $f4, $f22
/* 0C93CC 7F09489C 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C93D0 7F0948A0 E7A60548 */   swc1  $f6, 0x548($sp)
/* 0C93D4 7F0948A4 27B00650 */  addiu $s0, $sp, 0x650
/* 0C93D8 7F0948A8 02003025 */  move  $a2, $s0
/* 0C93DC 7F0948AC 461C0301 */  sub.s $f12, $f0, $f28
/* 0C93E0 7F0948B0 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C93E4 7F0948B4 C7AE0548 */   lwc1  $f14, 0x548($sp)
/* 0C93E8 7F0948B8 27A40698 */  addiu $a0, $sp, 0x698
/* 0C93EC 7F0948BC 27A50680 */  addiu $a1, $sp, 0x680
/* 0C93F0 7F0948C0 0FC24EFF */  jal   sub_GAME_7F093BFC
/* 0C93F4 7F0948C4 02003025 */   move  $a2, $s0
/* 0C93F8 7F0948C8 02002025 */  move  $a0, $s0
/* 0C93FC 7F0948CC 27A505F0 */  addiu $a1, $sp, 0x5f0
/* 0C9400 7F0948D0 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9404 7F0948D4 27A60570 */   addiu $a2, $sp, 0x570
/* 0C9408 7F0948D8 02002025 */  move  $a0, $s0
/* 0C940C 7F0948DC 27A50590 */  addiu $a1, $sp, 0x590
/* 0C9410 7F0948E0 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C9414 7F0948E4 27A60550 */   addiu $a2, $sp, 0x550
/* 0C9418 7F0948E8 10000005 */  b     .L7F094900
/* 0C941C 7F0948EC 8FAD0538 */   lw    $t5, 0x538($sp)
/* 0C9420 7F0948F0 44804000 */  mtc1  $zero, $f8
.L7F0948F4:
/* 0C9424 7F0948F4 00000000 */  nop
/* 0C9428 7F0948F8 E7A80548 */  swc1  $f8, 0x548($sp)
/* 0C942C 7F0948FC 8FAD0538 */  lw    $t5, 0x538($sp)
.L7F094900:
/* 0C9430 7F094900 8FB90534 */  lw    $t9, 0x534($sp)
/* 0C9434 7F094904 51B9001C */  beql  $t5, $t9, .L7F094978
/* 0C9438 7F094908 8FAB0530 */   lw    $t3, 0x530($sp)
/* 0C943C 7F09490C 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0C9440 7F094910 00000000 */   nop
/* 0C9444 7F094914 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C9448 7F094918 46000586 */   mov.s $f22, $f0
/* 0C944C 7F09491C C7A206A8 */  lwc1  $f2, 0x6a8($sp)
/* 0C9450 7F094920 C7B0069C */  lwc1  $f16, 0x69c($sp)
/* 0C9454 7F094924 27B00674 */  addiu $s0, $sp, 0x674
/* 0C9458 7F094928 44807000 */  mtc1  $zero, $f14
/* 0C945C 7F09492C 46101281 */  sub.s $f10, $f2, $f16
/* 0C9460 7F094930 02003025 */  move  $a2, $s0
/* 0C9464 7F094934 460A1103 */  div.s $f4, $f2, $f10
/* 0C9468 7F094938 46002182 */  mul.s $f6, $f4, $f0
/* 0C946C 7F09493C 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C9470 7F094940 46163300 */   add.s $f12, $f6, $f22
/* 0C9474 7F094944 02202025 */  move  $a0, $s1
/* 0C9478 7F094948 27A50698 */  addiu $a1, $sp, 0x698
/* 0C947C 7F09494C 0FC24EFF */  jal   sub_GAME_7F093BFC
/* 0C9480 7F094950 02003025 */   move  $a2, $s0
/* 0C9484 7F094954 02002025 */  move  $a0, $s0
/* 0C9488 7F094958 27A50614 */  addiu $a1, $sp, 0x614
/* 0C948C 7F09495C 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9490 7F094960 27A6057C */   addiu $a2, $sp, 0x57c
/* 0C9494 7F094964 02002025 */  move  $a0, $s0
/* 0C9498 7F094968 27A505B4 */  addiu $a1, $sp, 0x5b4
/* 0C949C 7F09496C 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C94A0 7F094970 27A6055C */   addiu $a2, $sp, 0x55c
/* 0C94A4 7F094974 8FAB0530 */  lw    $t3, 0x530($sp)
.L7F094978:
/* 0C94A8 7F094978 8FAC052C */  lw    $t4, 0x52c($sp)
/* 0C94AC 7F09497C 516C001E */  beql  $t3, $t4, .L7F0949F8
/* 0C94B0 7F094980 8FAE0538 */   lw    $t6, 0x538($sp)
/* 0C94B4 7F094984 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0C94B8 7F094988 00000000 */   nop
/* 0C94BC 7F09498C 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0C94C0 7F094990 46000586 */   mov.s $f22, $f0
/* 0C94C4 7F094994 C7B00690 */  lwc1  $f16, 0x690($sp)
/* 0C94C8 7F094998 C7A80684 */  lwc1  $f8, 0x684($sp)
/* 0C94CC 7F09499C 46088281 */  sub.s $f10, $f16, $f8
/* 0C94D0 7F0949A0 460A8103 */  div.s $f4, $f16, $f10
/* 0C94D4 7F0949A4 46002182 */  mul.s $f6, $f4, $f0
/* 0C94D8 7F0949A8 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0C94DC 7F0949AC 46163500 */   add.s $f20, $f6, $f22
/* 0C94E0 7F0949B0 27B00668 */  addiu $s0, $sp, 0x668
/* 0C94E4 7F0949B4 02003025 */  move  $a2, $s0
/* 0C94E8 7F0949B8 4600A306 */  mov.s $f12, $f20
/* 0C94EC 7F0949BC 0FC24E20 */  jal   sub_GAME_7F093880
/* 0C94F0 7F0949C0 461C0381 */   sub.s $f14, $f0, $f28
/* 0C94F4 7F0949C4 27A4068C */  addiu $a0, $sp, 0x68c
/* 0C94F8 7F0949C8 27A50680 */  addiu $a1, $sp, 0x680
/* 0C94FC 7F0949CC 0FC24EFF */  jal   sub_GAME_7F093BFC
/* 0C9500 7F0949D0 02003025 */   move  $a2, $s0
/* 0C9504 7F0949D4 02002025 */  move  $a0, $s0
/* 0C9508 7F0949D8 27A50608 */  addiu $a1, $sp, 0x608
/* 0C950C 7F0949DC 0FC24E3F */  jal   sub_GAME_7F0938FC
/* 0C9510 7F0949E0 27A60578 */   addiu $a2, $sp, 0x578
/* 0C9514 7F0949E4 02002025 */  move  $a0, $s0
/* 0C9518 7F0949E8 27A505A8 */  addiu $a1, $sp, 0x5a8
/* 0C951C 7F0949EC 0FC24E9E */  jal   sub_GAME_7F093A78
/* 0C9520 7F0949F0 27A60558 */   addiu $a2, $sp, 0x558
/* 0C9524 7F0949F4 8FAE0538 */  lw    $t6, 0x538($sp)
.L7F0949F8:
/* 0C9528 7F0949F8 8FB80534 */  lw    $t8, 0x534($sp)
/* 0C952C 7F0949FC 8FB90530 */  lw    $t9, 0x530($sp)
/* 0C9530 7F094A00 000E50C0 */  sll   $t2, $t6, 3
/* 0C9534 7F094A04 8FAE052C */  lw    $t6, 0x52c($sp)
/* 0C9538 7F094A08 00187880 */  sll   $t7, $t8, 2
/* 0C953C 7F094A0C 014F6825 */  or    $t5, $t2, $t7
/* 0C9540 7F094A10 00195840 */  sll   $t3, $t9, 1
/* 0C9544 7F094A14 01AB6025 */  or    $t4, $t5, $t3
/* 0C9548 7F094A18 018EC025 */  or    $t8, $t4, $t6
/* 0C954C 7F094A1C 2F010010 */  sltiu $at, $t8, 0x10
/* 0C9550 7F094A20 10200360 */  beqz  $at, .L7F0957A4
/* 0C9554 7F094A24 AFB8005C */   sw    $t8, 0x5c($sp)
/* 0C9558 7F094A28 00185080 */  sll   $t2, $t8, 2
/* 0C955C 7F094A2C 3C018005 */  lui   $at, %hi(jpt_80057544)
/* 0C9560 7F094A30 002A0821 */  addu  $at, $at, $t2
/* 0C9564 7F094A34 8C2A7544 */  lw    $t2, %lo(jpt_80057544)($at)
.L7F094A38:
/* 0C9568 7F094A38 01400008 */  jr    $t2
/* 0C956C 7F094A3C 00000000 */   nop
.L7F094A40:
/* 0C9570 7F094A40 1000035A */  b     .L7F0957AC
/* 0C9574 7F094A44 00008825 */   move  $s1, $zero
.L7F094A48:
/* 0C9578 7F094A48 C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C957C 7F094A4C C7AA05E8 */  lwc1  $f10, 0x5e8($sp)
/* 0C9580 7F094A50 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C9584 7F094A54 46181202 */  mul.s $f8, $f2, $f24
/* 0C9588 7F094A58 C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C958C 7F094A5C C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9590 7F094A60 46185102 */  mul.s $f4, $f10, $f24
/* 0C9594 7F094A64 C7AA05DC */  lwc1  $f10, 0x5dc($sp)
/* 0C9598 7F094A68 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C959C 7F094A6C 46186182 */  mul.s $f6, $f12, $f24
/* 0C95A0 7F094A70 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C95A4 7F094A74 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C95A8 7F094A78 46187202 */  mul.s $f8, $f14, $f24
/* 0C95AC 7F094A7C E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C95B0 7F094A80 C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0C95B4 7F094A84 46185102 */  mul.s $f4, $f10, $f24
/* 0C95B8 7F094A88 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C95BC 7F094A8C C7AA05D0 */  lwc1  $f10, 0x5d0($sp)
/* 0C95C0 7F094A90 46188182 */  mul.s $f6, $f16, $f24
/* 0C95C4 7F094A94 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C95C8 7F094A98 C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0C95CC 7F094A9C 46189202 */  mul.s $f8, $f18, $f24
/* 0C95D0 7F094AA0 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C95D4 7F094AA4 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C95D8 7F094AA8 46185102 */  mul.s $f4, $f10, $f24
/* 0C95DC 7F094AAC E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C95E0 7F094AB0 C7AA05C4 */  lwc1  $f10, 0x5c4($sp)
/* 0C95E4 7F094AB4 4618A182 */  mul.s $f6, $f20, $f24
/* 0C95E8 7F094AB8 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C95EC 7F094ABC C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C95F0 7F094AC0 4618B202 */  mul.s $f8, $f22, $f24
/* 0C95F4 7F094AC4 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C95F8 7F094AC8 24110004 */  li    $s1, 4
/* 0C95FC 7F094ACC 46185102 */  mul.s $f4, $f10, $f24
/* 0C9600 7F094AD0 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9604 7F094AD4 46008280 */  add.s $f10, $f16, $f0
/* 0C9608 7F094AD8 4618D182 */  mul.s $f6, $f26, $f24
/* 0C960C 7F094ADC E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9610 7F094AE0 46006200 */  add.s $f8, $f12, $f0
/* 0C9614 7F094AE4 E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C9618 7F094AE8 E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C961C 7F094AEC 4600A100 */  add.s $f4, $f20, $f0
/* 0C9620 7F094AF0 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9624 7F094AF4 E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C9628 7F094AF8 4600D180 */  add.s $f6, $f26, $f0
/* 0C962C 7F094AFC E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9630 7F094B00 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9634 7F094B04 8FA5056C */  lw    $a1, 0x56c($sp)
/* 0C9638 7F094B08 E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C963C 7F094B0C E7A20448 */  swc1  $f2, 0x448($sp)
/* 0C9640 7F094B10 E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0C9644 7F094B14 E7B20478 */  swc1  $f18, 0x478($sp)
/* 0C9648 7F094B18 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C964C 7F094B1C E7B60490 */   swc1  $f22, 0x490($sp)
/* 0C9650 7F094B20 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9654 7F094B24 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9658 7F094B28 8FA50568 */   lw    $a1, 0x568($sp)
/* 0C965C 7F094B2C 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9660 7F094B30 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9664 7F094B34 8FA50564 */   lw    $a1, 0x564($sp)
/* 0C9668 7F094B38 27A40484 */  addiu $a0, $sp, 0x484
/* 0C966C 7F094B3C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9670 7F094B40 8FA50560 */   lw    $a1, 0x560($sp)
/* 0C9674 7F094B44 10000319 */  b     .L7F0957AC
/* 0C9678 7F094B48 00000000 */   nop
.L7F094B4C:
/* 0C967C 7F094B4C C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C9680 7F094B50 C7AA05E8 */  lwc1  $f10, 0x5e8($sp)
/* 0C9684 7F094B54 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C9688 7F094B58 46181202 */  mul.s $f8, $f2, $f24
/* 0C968C 7F094B5C C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C9690 7F094B60 C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9694 7F094B64 46185102 */  mul.s $f4, $f10, $f24
/* 0C9698 7F094B68 C7AA05DC */  lwc1  $f10, 0x5dc($sp)
/* 0C969C 7F094B6C C7B2059C */  lwc1  $f18, 0x59c($sp)
/* 0C96A0 7F094B70 46186182 */  mul.s $f6, $f12, $f24
/* 0C96A4 7F094B74 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C96A8 7F094B78 C7B405A4 */  lwc1  $f20, 0x5a4($sp)
/* 0C96AC 7F094B7C 46187202 */  mul.s $f8, $f14, $f24
/* 0C96B0 7F094B80 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C96B4 7F094B84 C7B60590 */  lwc1  $f22, 0x590($sp)
/* 0C96B8 7F094B88 46185102 */  mul.s $f4, $f10, $f24
/* 0C96BC 7F094B8C E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C96C0 7F094B90 C7AA05A0 */  lwc1  $f10, 0x5a0($sp)
/* 0C96C4 7F094B94 46188182 */  mul.s $f6, $f16, $f24
/* 0C96C8 7F094B98 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C96CC 7F094B9C C7BA0598 */  lwc1  $f26, 0x598($sp)
/* 0C96D0 7F094BA0 46189202 */  mul.s $f8, $f18, $f24
/* 0C96D4 7F094BA4 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C96D8 7F094BA8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C96DC 7F094BAC 46185102 */  mul.s $f4, $f10, $f24
/* 0C96E0 7F094BB0 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C96E4 7F094BB4 C7AA0594 */  lwc1  $f10, 0x594($sp)
/* 0C96E8 7F094BB8 4618A182 */  mul.s $f6, $f20, $f24
/* 0C96EC 7F094BBC E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C96F0 7F094BC0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C96F4 7F094BC4 4618B202 */  mul.s $f8, $f22, $f24
/* 0C96F8 7F094BC8 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C96FC 7F094BCC 24110004 */  li    $s1, 4
/* 0C9700 7F094BD0 46185102 */  mul.s $f4, $f10, $f24
/* 0C9704 7F094BD4 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9708 7F094BD8 46008280 */  add.s $f10, $f16, $f0
/* 0C970C 7F094BDC 4618D182 */  mul.s $f6, $f26, $f24
/* 0C9710 7F094BE0 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9714 7F094BE4 46006200 */  add.s $f8, $f12, $f0
/* 0C9718 7F094BE8 E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C971C 7F094BEC E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9720 7F094BF0 4600A100 */  add.s $f4, $f20, $f0
/* 0C9724 7F094BF4 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9728 7F094BF8 E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C972C 7F094BFC 4600D180 */  add.s $f6, $f26, $f0
/* 0C9730 7F094C00 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9734 7F094C04 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9738 7F094C08 8FA5056C */  lw    $a1, 0x56c($sp)
/* 0C973C 7F094C0C E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C9740 7F094C10 E7A20448 */  swc1  $f2, 0x448($sp)
/* 0C9744 7F094C14 E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0C9748 7F094C18 E7B20478 */  swc1  $f18, 0x478($sp)
/* 0C974C 7F094C1C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9750 7F094C20 E7B60490 */   swc1  $f22, 0x490($sp)
/* 0C9754 7F094C24 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9758 7F094C28 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C975C 7F094C2C 8FA50568 */   lw    $a1, 0x568($sp)
/* 0C9760 7F094C30 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9764 7F094C34 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9768 7F094C38 8FA50554 */   lw    $a1, 0x554($sp)
/* 0C976C 7F094C3C 27A40484 */  addiu $a0, $sp, 0x484
/* 0C9770 7F094C40 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9774 7F094C44 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9778 7F094C48 100002D8 */  b     .L7F0957AC
/* 0C977C 7F094C4C 00000000 */   nop
.L7F094C50:
/* 0C9780 7F094C50 C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0C9784 7F094C54 C7AA05C4 */  lwc1  $f10, 0x5c4($sp)
/* 0C9788 7F094C58 C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0C978C 7F094C5C 4618B202 */  mul.s $f8, $f22, $f24
/* 0C9790 7F094C60 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C9794 7F094C64 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C9798 7F094C68 46185102 */  mul.s $f4, $f10, $f24
/* 0C979C 7F094C6C C7AA05D0 */  lwc1  $f10, 0x5d0($sp)
/* 0C97A0 7F094C70 C7AE0590 */  lwc1  $f14, 0x590($sp)
/* 0C97A4 7F094C74 4618D182 */  mul.s $f6, $f26, $f24
/* 0C97A8 7F094C78 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C97AC 7F094C7C C7B00598 */  lwc1  $f16, 0x598($sp)
/* 0C97B0 7F094C80 46189202 */  mul.s $f8, $f18, $f24
/* 0C97B4 7F094C84 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C97B8 7F094C88 C7A2059C */  lwc1  $f2, 0x59c($sp)
/* 0C97BC 7F094C8C 46185102 */  mul.s $f4, $f10, $f24
/* 0C97C0 7F094C90 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C97C4 7F094C94 C7AA0594 */  lwc1  $f10, 0x594($sp)
/* 0C97C8 7F094C98 4618A182 */  mul.s $f6, $f20, $f24
/* 0C97CC 7F094C9C E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C97D0 7F094CA0 C7AC05A4 */  lwc1  $f12, 0x5a4($sp)
/* 0C97D4 7F094CA4 46187202 */  mul.s $f8, $f14, $f24
/* 0C97D8 7F094CA8 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C97DC 7F094CAC 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C97E0 7F094CB0 46185102 */  mul.s $f4, $f10, $f24
/* 0C97E4 7F094CB4 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C97E8 7F094CB8 C7AA05A0 */  lwc1  $f10, 0x5a0($sp)
/* 0C97EC 7F094CBC 46188182 */  mul.s $f6, $f16, $f24
/* 0C97F0 7F094CC0 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C97F4 7F094CC4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C97F8 7F094CC8 46181202 */  mul.s $f8, $f2, $f24
/* 0C97FC 7F094CCC E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C9800 7F094CD0 240F0001 */  li    $t7, 1
/* 0C9804 7F094CD4 46185102 */  mul.s $f4, $f10, $f24
/* 0C9808 7F094CD8 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C980C 7F094CDC 4600A280 */  add.s $f10, $f20, $f0
/* 0C9810 7F094CE0 46186182 */  mul.s $f6, $f12, $f24
/* 0C9814 7F094CE4 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9818 7F094CE8 4600D200 */  add.s $f8, $f26, $f0
/* 0C981C 7F094CEC 24110004 */  li    $s1, 4
/* 0C9820 7F094CF0 E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9824 7F094CF4 46008100 */  add.s $f4, $f16, $f0
/* 0C9828 7F094CF8 AFAF0430 */  sw    $t7, 0x430($sp)
/* 0C982C 7F094CFC E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C9830 7F094D00 46006180 */  add.s $f6, $f12, $f0
/* 0C9834 7F094D04 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9838 7F094D08 E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C983C 7F094D0C E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9840 7F094D10 E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C9844 7F094D14 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9848 7F094D18 8FA50560 */  lw    $a1, 0x560($sp)
/* 0C984C 7F094D1C E7B60448 */  swc1  $f22, 0x448($sp)
/* 0C9850 7F094D20 E7B20460 */  swc1  $f18, 0x460($sp)
/* 0C9854 7F094D24 E7AE0478 */  swc1  $f14, 0x478($sp)
/* 0C9858 7F094D28 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C985C 7F094D2C E7A20490 */   swc1  $f2, 0x490($sp)
/* 0C9860 7F094D30 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9864 7F094D34 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9868 7F094D38 8FA50564 */   lw    $a1, 0x564($sp)
/* 0C986C 7F094D3C 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9870 7F094D40 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9874 7F094D44 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9878 7F094D48 27A40484 */  addiu $a0, $sp, 0x484
/* 0C987C 7F094D4C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9880 7F094D50 8FA50554 */   lw    $a1, 0x554($sp)
/* 0C9884 7F094D54 10000295 */  b     .L7F0957AC
/* 0C9888 7F094D58 00000000 */   nop
.L7F094D5C:
/* 0C988C 7F094D5C C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C9890 7F094D60 C7AA05DC */  lwc1  $f10, 0x5dc($sp)
/* 0C9894 7F094D64 C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9898 7F094D68 46187202 */  mul.s $f8, $f14, $f24
/* 0C989C 7F094D6C C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0C98A0 7F094D70 C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0C98A4 7F094D74 46185102 */  mul.s $f4, $f10, $f24
/* 0C98A8 7F094D78 C7AA05C4 */  lwc1  $f10, 0x5c4($sp)
/* 0C98AC 7F094D7C C7A205B4 */  lwc1  $f2, 0x5b4($sp)
/* 0C98B0 7F094D80 46188182 */  mul.s $f6, $f16, $f24
/* 0C98B4 7F094D84 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C98B8 7F094D88 C7AC05BC */  lwc1  $f12, 0x5bc($sp)
/* 0C98BC 7F094D8C 4618B202 */  mul.s $f8, $f22, $f24
/* 0C98C0 7F094D90 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C98C4 7F094D94 C7B205A8 */  lwc1  $f18, 0x5a8($sp)
/* 0C98C8 7F094D98 46185102 */  mul.s $f4, $f10, $f24
/* 0C98CC 7F094D9C E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C98D0 7F094DA0 C7AA05B8 */  lwc1  $f10, 0x5b8($sp)
/* 0C98D4 7F094DA4 4618D182 */  mul.s $f6, $f26, $f24
/* 0C98D8 7F094DA8 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C98DC 7F094DAC C7B405B0 */  lwc1  $f20, 0x5b0($sp)
/* 0C98E0 7F094DB0 46181202 */  mul.s $f8, $f2, $f24
/* 0C98E4 7F094DB4 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C98E8 7F094DB8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C98EC 7F094DBC 46185102 */  mul.s $f4, $f10, $f24
/* 0C98F0 7F094DC0 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C98F4 7F094DC4 C7AA05AC */  lwc1  $f10, 0x5ac($sp)
/* 0C98F8 7F094DC8 46186182 */  mul.s $f6, $f12, $f24
/* 0C98FC 7F094DCC E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C9900 7F094DD0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9904 7F094DD4 46189202 */  mul.s $f8, $f18, $f24
/* 0C9908 7F094DD8 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C990C 7F094DDC 24110004 */  li    $s1, 4
/* 0C9910 7F094DE0 46185102 */  mul.s $f4, $f10, $f24
/* 0C9914 7F094DE4 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9918 7F094DE8 4600D280 */  add.s $f10, $f26, $f0
/* 0C991C 7F094DEC 4618A182 */  mul.s $f6, $f20, $f24
/* 0C9920 7F094DF0 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9924 7F094DF4 46008200 */  add.s $f8, $f16, $f0
/* 0C9928 7F094DF8 E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C992C 7F094DFC E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9930 7F094E00 46006100 */  add.s $f4, $f12, $f0
/* 0C9934 7F094E04 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9938 7F094E08 E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C993C 7F094E0C 4600A180 */  add.s $f6, $f20, $f0
/* 0C9940 7F094E10 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9944 7F094E14 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9948 7F094E18 8FA50568 */  lw    $a1, 0x568($sp)
/* 0C994C 7F094E1C E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C9950 7F094E20 E7AE0448 */  swc1  $f14, 0x448($sp)
/* 0C9954 7F094E24 E7B60460 */  swc1  $f22, 0x460($sp)
/* 0C9958 7F094E28 E7A20478 */  swc1  $f2, 0x478($sp)
/* 0C995C 7F094E2C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9960 7F094E30 E7B20490 */   swc1  $f18, 0x490($sp)
/* 0C9964 7F094E34 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9968 7F094E38 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C996C 7F094E3C 8FA50560 */   lw    $a1, 0x560($sp)
/* 0C9970 7F094E40 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9974 7F094E44 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9978 7F094E48 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0C997C 7F094E4C 27A40484 */  addiu $a0, $sp, 0x484
/* 0C9980 7F094E50 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9984 7F094E54 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9988 7F094E58 10000254 */  b     .L7F0957AC
/* 0C998C 7F094E5C 00000000 */   nop
.L7F094E60:
/* 0C9990 7F094E60 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C9994 7F094E64 C7AA05D0 */  lwc1  $f10, 0x5d0($sp)
/* 0C9998 7F094E68 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C999C 7F094E6C 46189202 */  mul.s $f8, $f18, $f24
/* 0C99A0 7F094E70 C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C99A4 7F094E74 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C99A8 7F094E78 46185102 */  mul.s $f4, $f10, $f24
/* 0C99AC 7F094E7C C7AA05E8 */  lwc1  $f10, 0x5e8($sp)
/* 0C99B0 7F094E80 C7B605A8 */  lwc1  $f22, 0x5a8($sp)
/* 0C99B4 7F094E84 4618A182 */  mul.s $f6, $f20, $f24
/* 0C99B8 7F094E88 E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C99BC 7F094E8C C7BA05B0 */  lwc1  $f26, 0x5b0($sp)
/* 0C99C0 7F094E90 46181202 */  mul.s $f8, $f2, $f24
/* 0C99C4 7F094E94 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C99C8 7F094E98 C7AE05B4 */  lwc1  $f14, 0x5b4($sp)
/* 0C99CC 7F094E9C 46185102 */  mul.s $f4, $f10, $f24
/* 0C99D0 7F094EA0 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C99D4 7F094EA4 C7AA05AC */  lwc1  $f10, 0x5ac($sp)
/* 0C99D8 7F094EA8 46186182 */  mul.s $f6, $f12, $f24
/* 0C99DC 7F094EAC E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C99E0 7F094EB0 C7B005BC */  lwc1  $f16, 0x5bc($sp)
/* 0C99E4 7F094EB4 4618B202 */  mul.s $f8, $f22, $f24
/* 0C99E8 7F094EB8 E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C99EC 7F094EBC 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C99F0 7F094EC0 46185102 */  mul.s $f4, $f10, $f24
/* 0C99F4 7F094EC4 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C99F8 7F094EC8 C7AA05B8 */  lwc1  $f10, 0x5b8($sp)
/* 0C99FC 7F094ECC 4618D182 */  mul.s $f6, $f26, $f24
/* 0C9A00 7F094ED0 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C9A04 7F094ED4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9A08 7F094ED8 46187202 */  mul.s $f8, $f14, $f24
/* 0C9A0C 7F094EDC E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C9A10 7F094EE0 24110004 */  li    $s1, 4
/* 0C9A14 7F094EE4 46185102 */  mul.s $f4, $f10, $f24
/* 0C9A18 7F094EE8 E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9A1C 7F094EEC 46006280 */  add.s $f10, $f12, $f0
/* 0C9A20 7F094EF0 46188182 */  mul.s $f6, $f16, $f24
/* 0C9A24 7F094EF4 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9A28 7F094EF8 4600A200 */  add.s $f8, $f20, $f0
/* 0C9A2C 7F094EFC E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C9A30 7F094F00 E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9A34 7F094F04 4600D100 */  add.s $f4, $f26, $f0
/* 0C9A38 7F094F08 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9A3C 7F094F0C E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C9A40 7F094F10 46008180 */  add.s $f6, $f16, $f0
/* 0C9A44 7F094F14 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9A48 7F094F18 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9A4C 7F094F1C 8FA50564 */  lw    $a1, 0x564($sp)
/* 0C9A50 7F094F20 E7A60494 */  swc1  $f6, 0x494($sp)
/* 0C9A54 7F094F24 E7B20448 */  swc1  $f18, 0x448($sp)
/* 0C9A58 7F094F28 E7A20460 */  swc1  $f2, 0x460($sp)
/* 0C9A5C 7F094F2C E7B60478 */  swc1  $f22, 0x478($sp)
/* 0C9A60 7F094F30 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9A64 7F094F34 E7AE0490 */   swc1  $f14, 0x490($sp)
/* 0C9A68 7F094F38 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9A6C 7F094F3C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9A70 7F094F40 8FA5056C */   lw    $a1, 0x56c($sp)
/* 0C9A74 7F094F44 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9A78 7F094F48 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9A7C 7F094F4C 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9A80 7F094F50 27A40484 */  addiu $a0, $sp, 0x484
/* 0C9A84 7F094F54 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9A88 7F094F58 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0C9A8C 7F094F5C 10000213 */  b     .L7F0957AC
/* 0C9A90 7F094F60 00000000 */   nop
.L7F094F64:
/* 0C9A94 7F094F64 C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0C9A98 7F094F68 C7AA05C4 */  lwc1  $f10, 0x5c4($sp)
/* 0C9A9C 7F094F6C C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0C9AA0 7F094F70 4618B202 */  mul.s $f8, $f22, $f24
/* 0C9AA4 7F094F74 C7AE05A8 */  lwc1  $f14, 0x5a8($sp)
/* 0C9AA8 7F094F78 C7B005B0 */  lwc1  $f16, 0x5b0($sp)
/* 0C9AAC 7F094F7C 46185102 */  mul.s $f4, $f10, $f24
/* 0C9AB0 7F094F80 C7AA05AC */  lwc1  $f10, 0x5ac($sp)
/* 0C9AB4 7F094F84 C7A20590 */  lwc1  $f2, 0x590($sp)
/* 0C9AB8 7F094F88 4618D182 */  mul.s $f6, $f26, $f24
/* 0C9ABC 7F094F8C E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C9AC0 7F094F90 C7AC0598 */  lwc1  $f12, 0x598($sp)
/* 0C9AC4 7F094F94 46187202 */  mul.s $f8, $f14, $f24
/* 0C9AC8 7F094F98 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C9ACC 7F094F9C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9AD0 7F094FA0 46185102 */  mul.s $f4, $f10, $f24
/* 0C9AD4 7F094FA4 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C9AD8 7F094FA8 C7AA0594 */  lwc1  $f10, 0x594($sp)
/* 0C9ADC 7F094FAC 46188182 */  mul.s $f6, $f16, $f24
/* 0C9AE0 7F094FB0 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C9AE4 7F094FB4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9AE8 7F094FB8 46181202 */  mul.s $f8, $f2, $f24
/* 0C9AEC 7F094FBC E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C9AF0 7F094FC0 24110003 */  li    $s1, 3
/* 0C9AF4 7F094FC4 46185102 */  mul.s $f4, $f10, $f24
/* 0C9AF8 7F094FC8 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C9AFC 7F094FCC 46008280 */  add.s $f10, $f16, $f0
/* 0C9B00 7F094FD0 46186182 */  mul.s $f6, $f12, $f24
/* 0C9B04 7F094FD4 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C9B08 7F094FD8 4600D200 */  add.s $f8, $f26, $f0
/* 0C9B0C 7F094FDC E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0C9B10 7F094FE0 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C9B14 7F094FE4 46006100 */  add.s $f4, $f12, $f0
/* 0C9B18 7F094FE8 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0C9B1C 7F094FEC E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9B20 7F094FF0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9B24 7F094FF4 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0C9B28 7F094FF8 8FA50560 */  lw    $a1, 0x560($sp)
/* 0C9B2C 7F094FFC E7B60448 */  swc1  $f22, 0x448($sp)
/* 0C9B30 7F095000 E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0C9B34 7F095004 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9B38 7F095008 E7A20478 */   swc1  $f2, 0x478($sp)
/* 0C9B3C 7F09500C 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9B40 7F095010 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9B44 7F095014 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9B48 7F095018 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9B4C 7F09501C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9B50 7F095020 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9B54 7F095024 100001E1 */  b     .L7F0957AC
/* 0C9B58 7F095028 00000000 */   nop
.L7F09502C:
/* 0C9B5C 7F09502C C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C9B60 7F095030 C7A805D0 */  lwc1  $f8, 0x5d0($sp)
/* 0C9B64 7F095034 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C9B68 7F095038 46189182 */  mul.s $f6, $f18, $f24
/* 0C9B6C 7F09503C C7A2059C */  lwc1  $f2, 0x59c($sp)
/* 0C9B70 7F095040 C7AC05A4 */  lwc1  $f12, 0x5a4($sp)
/* 0C9B74 7F095044 46184282 */  mul.s $f10, $f8, $f24
/* 0C9B78 7F095048 C7A805A0 */  lwc1  $f8, 0x5a0($sp)
/* 0C9B7C 7F09504C C7AE05A8 */  lwc1  $f14, 0x5a8($sp)
/* 0C9B80 7F095050 4618A102 */  mul.s $f4, $f20, $f24
/* 0C9B84 7F095054 E7A6043C */  swc1  $f6, 0x43c($sp)
/* 0C9B88 7F095058 C7B005B0 */  lwc1  $f16, 0x5b0($sp)
/* 0C9B8C 7F09505C 46181182 */  mul.s $f6, $f2, $f24
/* 0C9B90 7F095060 E7AA0440 */  swc1  $f10, 0x440($sp)
/* 0C9B94 7F095064 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9B98 7F095068 46184282 */  mul.s $f10, $f8, $f24
/* 0C9B9C 7F09506C E7A40444 */  swc1  $f4, 0x444($sp)
/* 0C9BA0 7F095070 C7A805AC */  lwc1  $f8, 0x5ac($sp)
/* 0C9BA4 7F095074 46186102 */  mul.s $f4, $f12, $f24
/* 0C9BA8 7F095078 E7A60454 */  swc1  $f6, 0x454($sp)
/* 0C9BAC 7F09507C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9BB0 7F095080 46187182 */  mul.s $f6, $f14, $f24
/* 0C9BB4 7F095084 E7AA0458 */  swc1  $f10, 0x458($sp)
/* 0C9BB8 7F095088 24110003 */  li    $s1, 3
/* 0C9BBC 7F09508C 46184282 */  mul.s $f10, $f8, $f24
/* 0C9BC0 7F095090 E7A4045C */  swc1  $f4, 0x45c($sp)
/* 0C9BC4 7F095094 46006200 */  add.s $f8, $f12, $f0
/* 0C9BC8 7F095098 46188102 */  mul.s $f4, $f16, $f24
/* 0C9BCC 7F09509C E7A6046C */  swc1  $f6, 0x46c($sp)
/* 0C9BD0 7F0950A0 4600A180 */  add.s $f6, $f20, $f0
/* 0C9BD4 7F0950A4 E7A80464 */  swc1  $f8, 0x464($sp)
/* 0C9BD8 7F0950A8 E7AA0470 */  swc1  $f10, 0x470($sp)
/* 0C9BDC 7F0950AC 46008280 */  add.s $f10, $f16, $f0
/* 0C9BE0 7F0950B0 E7A6044C */  swc1  $f6, 0x44c($sp)
/* 0C9BE4 7F0950B4 E7A40474 */  swc1  $f4, 0x474($sp)
/* 0C9BE8 7F0950B8 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9BEC 7F0950BC E7AA047C */  swc1  $f10, 0x47c($sp)
/* 0C9BF0 7F0950C0 8FA50564 */  lw    $a1, 0x564($sp)
/* 0C9BF4 7F0950C4 E7B20448 */  swc1  $f18, 0x448($sp)
/* 0C9BF8 7F0950C8 E7A20460 */  swc1  $f2, 0x460($sp)
/* 0C9BFC 7F0950CC 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9C00 7F0950D0 E7AE0478 */   swc1  $f14, 0x478($sp)
/* 0C9C04 7F0950D4 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9C08 7F0950D8 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9C0C 7F0950DC 8FA50554 */   lw    $a1, 0x554($sp)
/* 0C9C10 7F0950E0 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9C14 7F0950E4 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9C18 7F0950E8 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9C1C 7F0950EC 100001AF */  b     .L7F0957AC
/* 0C9C20 7F0950F0 00000000 */   nop
.L7F0950F4:
/* 0C9C24 7F0950F4 C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C9C28 7F0950F8 C7A605DC */  lwc1  $f6, 0x5dc($sp)
/* 0C9C2C 7F0950FC C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9C30 7F095100 46187102 */  mul.s $f4, $f14, $f24
/* 0C9C34 7F095104 C7B20590 */  lwc1  $f18, 0x590($sp)
/* 0C9C38 7F095108 C7B40598 */  lwc1  $f20, 0x598($sp)
/* 0C9C3C 7F09510C 46183202 */  mul.s $f8, $f6, $f24
/* 0C9C40 7F095110 C7A60594 */  lwc1  $f6, 0x594($sp)
/* 0C9C44 7F095114 C7A205B4 */  lwc1  $f2, 0x5b4($sp)
/* 0C9C48 7F095118 46188282 */  mul.s $f10, $f16, $f24
/* 0C9C4C 7F09511C E7A4043C */  swc1  $f4, 0x43c($sp)
/* 0C9C50 7F095120 C7AC05BC */  lwc1  $f12, 0x5bc($sp)
/* 0C9C54 7F095124 46189102 */  mul.s $f4, $f18, $f24
/* 0C9C58 7F095128 E7A80440 */  swc1  $f8, 0x440($sp)
/* 0C9C5C 7F09512C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9C60 7F095130 46183202 */  mul.s $f8, $f6, $f24
/* 0C9C64 7F095134 E7AA0444 */  swc1  $f10, 0x444($sp)
/* 0C9C68 7F095138 C7A605B8 */  lwc1  $f6, 0x5b8($sp)
/* 0C9C6C 7F09513C 4618A282 */  mul.s $f10, $f20, $f24
/* 0C9C70 7F095140 E7A40454 */  swc1  $f4, 0x454($sp)
/* 0C9C74 7F095144 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9C78 7F095148 46181102 */  mul.s $f4, $f2, $f24
/* 0C9C7C 7F09514C E7A80458 */  swc1  $f8, 0x458($sp)
/* 0C9C80 7F095150 24110003 */  li    $s1, 3
/* 0C9C84 7F095154 46183202 */  mul.s $f8, $f6, $f24
/* 0C9C88 7F095158 E7AA045C */  swc1  $f10, 0x45c($sp)
/* 0C9C8C 7F09515C 4600A180 */  add.s $f6, $f20, $f0
/* 0C9C90 7F095160 46186282 */  mul.s $f10, $f12, $f24
/* 0C9C94 7F095164 E7A4046C */  swc1  $f4, 0x46c($sp)
/* 0C9C98 7F095168 46008100 */  add.s $f4, $f16, $f0
/* 0C9C9C 7F09516C E7A60464 */  swc1  $f6, 0x464($sp)
/* 0C9CA0 7F095170 E7A80470 */  swc1  $f8, 0x470($sp)
/* 0C9CA4 7F095174 46006200 */  add.s $f8, $f12, $f0
/* 0C9CA8 7F095178 E7A4044C */  swc1  $f4, 0x44c($sp)
/* 0C9CAC 7F09517C E7AA0474 */  swc1  $f10, 0x474($sp)
/* 0C9CB0 7F095180 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9CB4 7F095184 E7A8047C */  swc1  $f8, 0x47c($sp)
/* 0C9CB8 7F095188 8FA50568 */  lw    $a1, 0x568($sp)
/* 0C9CBC 7F09518C E7AE0448 */  swc1  $f14, 0x448($sp)
/* 0C9CC0 7F095190 E7B20460 */  swc1  $f18, 0x460($sp)
/* 0C9CC4 7F095194 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9CC8 7F095198 E7A20478 */   swc1  $f2, 0x478($sp)
/* 0C9CCC 7F09519C 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9CD0 7F0951A0 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9CD4 7F0951A4 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9CD8 7F0951A8 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9CDC 7F0951AC 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9CE0 7F0951B0 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0C9CE4 7F0951B4 1000017D */  b     .L7F0957AC
/* 0C9CE8 7F0951B8 00000000 */   nop
.L7F0951BC:
/* 0C9CEC 7F0951BC C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C9CF0 7F0951C0 C7A405E8 */  lwc1  $f4, 0x5e8($sp)
/* 0C9CF4 7F0951C4 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C9CF8 7F0951C8 46181282 */  mul.s $f10, $f2, $f24
/* 0C9CFC 7F0951CC C7AE05B4 */  lwc1  $f14, 0x5b4($sp)
/* 0C9D00 7F0951D0 C7B005BC */  lwc1  $f16, 0x5bc($sp)
/* 0C9D04 7F0951D4 46182182 */  mul.s $f6, $f4, $f24
/* 0C9D08 7F0951D8 C7A405B8 */  lwc1  $f4, 0x5b8($sp)
/* 0C9D0C 7F0951DC C7B2059C */  lwc1  $f18, 0x59c($sp)
/* 0C9D10 7F0951E0 46186202 */  mul.s $f8, $f12, $f24
/* 0C9D14 7F0951E4 E7AA043C */  swc1  $f10, 0x43c($sp)
/* 0C9D18 7F0951E8 C7B405A4 */  lwc1  $f20, 0x5a4($sp)
/* 0C9D1C 7F0951EC 46187282 */  mul.s $f10, $f14, $f24
/* 0C9D20 7F0951F0 E7A60440 */  swc1  $f6, 0x440($sp)
/* 0C9D24 7F0951F4 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9D28 7F0951F8 46182182 */  mul.s $f6, $f4, $f24
/* 0C9D2C 7F0951FC E7A80444 */  swc1  $f8, 0x444($sp)
/* 0C9D30 7F095200 C7A405A0 */  lwc1  $f4, 0x5a0($sp)
/* 0C9D34 7F095204 46188202 */  mul.s $f8, $f16, $f24
/* 0C9D38 7F095208 E7AA0454 */  swc1  $f10, 0x454($sp)
/* 0C9D3C 7F09520C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9D40 7F095210 46189282 */  mul.s $f10, $f18, $f24
/* 0C9D44 7F095214 E7A60458 */  swc1  $f6, 0x458($sp)
/* 0C9D48 7F095218 24110003 */  li    $s1, 3
/* 0C9D4C 7F09521C 46182182 */  mul.s $f6, $f4, $f24
/* 0C9D50 7F095220 E7A8045C */  swc1  $f8, 0x45c($sp)
/* 0C9D54 7F095224 46008100 */  add.s $f4, $f16, $f0
/* 0C9D58 7F095228 4618A202 */  mul.s $f8, $f20, $f24
/* 0C9D5C 7F09522C E7AA046C */  swc1  $f10, 0x46c($sp)
/* 0C9D60 7F095230 46006280 */  add.s $f10, $f12, $f0
/* 0C9D64 7F095234 E7A40464 */  swc1  $f4, 0x464($sp)
/* 0C9D68 7F095238 E7A60470 */  swc1  $f6, 0x470($sp)
/* 0C9D6C 7F09523C 4600A180 */  add.s $f6, $f20, $f0
/* 0C9D70 7F095240 E7AA044C */  swc1  $f10, 0x44c($sp)
/* 0C9D74 7F095244 E7A80474 */  swc1  $f8, 0x474($sp)
/* 0C9D78 7F095248 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9D7C 7F09524C E7A6047C */  swc1  $f6, 0x47c($sp)
/* 0C9D80 7F095250 8FA5056C */  lw    $a1, 0x56c($sp)
/* 0C9D84 7F095254 E7A20448 */  swc1  $f2, 0x448($sp)
/* 0C9D88 7F095258 E7AE0460 */  swc1  $f14, 0x460($sp)
/* 0C9D8C 7F09525C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9D90 7F095260 E7B20478 */   swc1  $f18, 0x478($sp)
/* 0C9D94 7F095264 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9D98 7F095268 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9D9C 7F09526C 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0C9DA0 7F095270 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9DA4 7F095274 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9DA8 7F095278 8FA50554 */   lw    $a1, 0x554($sp)
/* 0C9DAC 7F09527C 1000014B */  b     .L7F0957AC
/* 0C9DB0 7F095280 00000000 */   nop
.L7F095284:
/* 0C9DB4 7F095284 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0C9DB8 7F095288 C7AA05D0 */  lwc1  $f10, 0x5d0($sp)
/* 0C9DBC 7F09528C C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0C9DC0 7F095290 46189202 */  mul.s $f8, $f18, $f24
/* 0C9DC4 7F095294 C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0C9DC8 7F095298 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0C9DCC 7F09529C 46185102 */  mul.s $f4, $f10, $f24
/* 0C9DD0 7F0952A0 C7AA05E8 */  lwc1  $f10, 0x5e8($sp)
/* 0C9DD4 7F0952A4 C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0C9DD8 7F0952A8 4618A182 */  mul.s $f6, $f20, $f24
/* 0C9DDC 7F0952AC E7A8043C */  swc1  $f8, 0x43c($sp)
/* 0C9DE0 7F0952B0 C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9DE4 7F0952B4 46181202 */  mul.s $f8, $f2, $f24
/* 0C9DE8 7F0952B8 E7A40440 */  swc1  $f4, 0x440($sp)
/* 0C9DEC 7F0952BC C7B60590 */  lwc1  $f22, 0x590($sp)
/* 0C9DF0 7F0952C0 46185102 */  mul.s $f4, $f10, $f24
/* 0C9DF4 7F0952C4 E7A60444 */  swc1  $f6, 0x444($sp)
/* 0C9DF8 7F0952C8 C7AA05DC */  lwc1  $f10, 0x5dc($sp)
/* 0C9DFC 7F0952CC 46186182 */  mul.s $f6, $f12, $f24
/* 0C9E00 7F0952D0 E7A80454 */  swc1  $f8, 0x454($sp)
/* 0C9E04 7F0952D4 C7BA0598 */  lwc1  $f26, 0x598($sp)
/* 0C9E08 7F0952D8 46187202 */  mul.s $f8, $f14, $f24
/* 0C9E0C 7F0952DC E7A40458 */  swc1  $f4, 0x458($sp)
/* 0C9E10 7F0952E0 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9E14 7F0952E4 46185102 */  mul.s $f4, $f10, $f24
/* 0C9E18 7F0952E8 E7A6045C */  swc1  $f6, 0x45c($sp)
/* 0C9E1C 7F0952EC C7AA0594 */  lwc1  $f10, 0x594($sp)
/* 0C9E20 7F0952F0 46188182 */  mul.s $f6, $f16, $f24
/* 0C9E24 7F0952F4 E7A8046C */  swc1  $f8, 0x46c($sp)
/* 0C9E28 7F0952F8 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0C9E2C 7F0952FC 4618B202 */  mul.s $f8, $f22, $f24
/* 0C9E30 7F095300 E7A40470 */  swc1  $f4, 0x470($sp)
/* 0C9E34 7F095304 24110005 */  li    $s1, 5
/* 0C9E38 7F095308 46185102 */  mul.s $f4, $f10, $f24
/* 0C9E3C 7F09530C E7A60474 */  swc1  $f6, 0x474($sp)
/* 0C9E40 7F095310 27A4043C */  addiu $a0, $sp, 0x43c
/* 0C9E44 7F095314 4618D182 */  mul.s $f6, $f26, $f24
/* 0C9E48 7F095318 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9E4C 7F09531C C7A805A8 */  lwc1  $f8, 0x5a8($sp)
/* 0C9E50 7F095320 8FA50564 */  lw    $a1, 0x564($sp)
/* 0C9E54 7F095324 E7A40488 */  swc1  $f4, 0x488($sp)
/* 0C9E58 7F095328 46184282 */  mul.s $f10, $f8, $f24
/* 0C9E5C 7F09532C C7A405AC */  lwc1  $f4, 0x5ac($sp)
/* 0C9E60 7F095330 E7A6048C */  swc1  $f6, 0x48c($sp)
/* 0C9E64 7F095334 C7A805B0 */  lwc1  $f8, 0x5b0($sp)
/* 0C9E68 7F095338 46182182 */  mul.s $f6, $f4, $f24
/* 0C9E6C 7F09533C 4600A100 */  add.s $f4, $f20, $f0
/* 0C9E70 7F095340 E7B20448 */  swc1  $f18, 0x448($sp)
/* 0C9E74 7F095344 E7AA049C */  swc1  $f10, 0x49c($sp)
/* 0C9E78 7F095348 46184282 */  mul.s $f10, $f8, $f24
/* 0C9E7C 7F09534C 46008200 */  add.s $f8, $f16, $f0
/* 0C9E80 7F095350 E7A4044C */  swc1  $f4, 0x44c($sp)
/* 0C9E84 7F095354 E7A604A0 */  swc1  $f6, 0x4a0($sp)
/* 0C9E88 7F095358 C7A405A8 */  lwc1  $f4, 0x5a8($sp)
/* 0C9E8C 7F09535C 46006180 */  add.s $f6, $f12, $f0
/* 0C9E90 7F095360 E7A8047C */  swc1  $f8, 0x47c($sp)
/* 0C9E94 7F095364 E7AA04A4 */  swc1  $f10, 0x4a4($sp)
/* 0C9E98 7F095368 4600D280 */  add.s $f10, $f26, $f0
/* 0C9E9C 7F09536C E7A60464 */  swc1  $f6, 0x464($sp)
/* 0C9EA0 7F095370 C7A605B0 */  lwc1  $f6, 0x5b0($sp)
/* 0C9EA4 7F095374 E7A20460 */  swc1  $f2, 0x460($sp)
/* 0C9EA8 7F095378 E7AA0494 */  swc1  $f10, 0x494($sp)
/* 0C9EAC 7F09537C 46003200 */  add.s $f8, $f6, $f0
/* 0C9EB0 7F095380 E7AE0478 */  swc1  $f14, 0x478($sp)
/* 0C9EB4 7F095384 E7B60490 */  swc1  $f22, 0x490($sp)
/* 0C9EB8 7F095388 E7A404A8 */  swc1  $f4, 0x4a8($sp)
/* 0C9EBC 7F09538C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9EC0 7F095390 E7A804AC */   swc1  $f8, 0x4ac($sp)
/* 0C9EC4 7F095394 27A40454 */  addiu $a0, $sp, 0x454
/* 0C9EC8 7F095398 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9ECC 7F09539C 8FA5056C */   lw    $a1, 0x56c($sp)
/* 0C9ED0 7F0953A0 27A4046C */  addiu $a0, $sp, 0x46c
/* 0C9ED4 7F0953A4 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9ED8 7F0953A8 8FA50568 */   lw    $a1, 0x568($sp)
/* 0C9EDC 7F0953AC 27A40484 */  addiu $a0, $sp, 0x484
/* 0C9EE0 7F0953B0 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9EE4 7F0953B4 8FA50550 */   lw    $a1, 0x550($sp)
/* 0C9EE8 7F0953B8 27A4049C */  addiu $a0, $sp, 0x49c
/* 0C9EEC 7F0953BC 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0C9EF0 7F0953C0 8FA50558 */   lw    $a1, 0x558($sp)
/* 0C9EF4 7F0953C4 100000F9 */  b     .L7F0957AC
/* 0C9EF8 7F0953C8 00000000 */   nop
.L7F0953CC:
/* 0C9EFC 7F0953CC C7BA05E4 */  lwc1  $f26, 0x5e4($sp)
/* 0C9F00 7F0953D0 C7B605EC */  lwc1  $f22, 0x5ec($sp)
/* 0C9F04 7F0953D4 C7B405D8 */  lwc1  $f20, 0x5d8($sp)
/* 0C9F08 7F0953D8 4618D482 */  mul.s $f18, $f26, $f24
/* 0C9F0C 7F0953DC C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0C9F10 7F0953E0 C7AE05C0 */  lwc1  $f14, 0x5c0($sp)
/* 0C9F14 7F0953E4 4618B302 */  mul.s $f12, $f22, $f24
/* 0C9F18 7F0953E8 C7AA059C */  lwc1  $f10, 0x59c($sp)
/* 0C9F1C 7F0953EC C7A805E8 */  lwc1  $f8, 0x5e8($sp)
/* 0C9F20 7F0953F0 4618A182 */  mul.s $f6, $f20, $f24
/* 0C9F24 7F0953F4 C7A405C8 */  lwc1  $f4, 0x5c8($sp)
/* 0C9F28 7F0953F8 C7A205A4 */  lwc1  $f2, 0x5a4($sp)
/* 0C9F2C 7F0953FC 46184202 */  mul.s $f8, $f8, $f24
/* 0C9F30 7F095400 C7A005DC */  lwc1  $f0, 0x5dc($sp)
/* 0C9F34 7F095404 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0C9F38 7F095408 E7B2043C */  swc1  $f18, 0x43c($sp)
/* 0C9F3C 7F09540C 46180002 */  mul.s $f0, $f0, $f24
/* 0C9F40 7F095410 C7B205C4 */  lwc1  $f18, 0x5c4($sp)
/* 0C9F44 7F095414 E7AC0444 */  swc1  $f12, 0x444($sp)
/* 0C9F48 7F095418 46188302 */  mul.s $f12, $f16, $f24
/* 0C9F4C 7F09541C E7A80440 */  swc1  $f8, 0x440($sp)
/* 0C9F50 7F095420 C7A805A8 */  lwc1  $f8, 0x5a8($sp)
/* 0C9F54 7F095424 46189482 */  mul.s $f18, $f18, $f24
/* 0C9F58 7F095428 E7A60454 */  swc1  $f6, 0x454($sp)
/* 0C9F5C 7F09542C C7A605AC */  lwc1  $f6, 0x5ac($sp)
/* 0C9F60 7F095430 46184202 */  mul.s $f8, $f8, $f24
/* 0C9F64 7F095434 E7A00458 */  swc1  $f0, 0x458($sp)
/* 0C9F68 7F095438 C7A005B0 */  lwc1  $f0, 0x5b0($sp)
/* 0C9F6C 7F09543C 24110005 */  li    $s1, 5
/* 0C9F70 7F095440 E7AC045C */  swc1  $f12, 0x45c($sp)
/* 0C9F74 7F095444 46187302 */  mul.s $f12, $f14, $f24
/* 0C9F78 7F095448 E7B20470 */  swc1  $f18, 0x470($sp)
/* 0C9F7C 7F09544C C7B205A0 */  lwc1  $f18, 0x5a0($sp)
/* 0C9F80 7F095450 46180002 */  mul.s $f0, $f0, $f24
/* 0C9F84 7F095454 E7A80484 */  swc1  $f8, 0x484($sp)
/* 0C9F88 7F095458 C428FD94 */  lwc1  $f8, %lo(D_8003FD94)($at)
/* 0C9F8C 7F09545C 46189482 */  mul.s $f18, $f18, $f24
/* 0C9F90 7F095460 E7AC046C */  swc1  $f12, 0x46c($sp)
/* 0C9F94 7F095464 46082300 */  add.s $f12, $f4, $f8
/* 0C9F98 7F095468 46182102 */  mul.s $f4, $f4, $f24
/* 0C9F9C 7F09546C E7A0048C */  swc1  $f0, 0x48c($sp)
/* 0C9FA0 7F095470 46081000 */  add.s $f0, $f2, $f8
/* 0C9FA4 7F095474 46183182 */  mul.s $f6, $f6, $f24
/* 0C9FA8 7F095478 E7B204A0 */  swc1  $f18, 0x4a0($sp)
/* 0C9FAC 7F09547C 46088400 */  add.s $f16, $f16, $f8
/* 0C9FB0 7F095480 46181082 */  mul.s $f2, $f2, $f24
/* 0C9FB4 7F095484 C7B205B0 */  lwc1  $f18, 0x5b0($sp)
/* 0C9FB8 7F095488 E7A40474 */  swc1  $f4, 0x474($sp)
/* 0C9FBC 7F09548C 46185102 */  mul.s $f4, $f10, $f24
/* 0C9FC0 7F095490 E7A60488 */  swc1  $f6, 0x488($sp)
/* 0C9FC4 7F095494 4608B580 */  add.s $f22, $f22, $f8
/* 0C9FC8 7F095498 C7A605A8 */  lwc1  $f6, 0x5a8($sp)
/* 0C9FCC 7F09549C E7A204A4 */  swc1  $f2, 0x4a4($sp)
/* 0C9FD0 7F0954A0 46089200 */  add.s $f8, $f18, $f8
/* 0C9FD4 7F0954A4 E7BA0448 */  swc1  $f26, 0x448($sp)
/* 0C9FD8 7F0954A8 E7A4049C */  swc1  $f4, 0x49c($sp)
/* 0C9FDC 7F0954AC E7B6044C */  swc1  $f22, 0x44c($sp)
/* 0C9FE0 7F0954B0 E7B40460 */  swc1  $f20, 0x460($sp)
/* 0C9FE4 7F0954B4 E7B00464 */  swc1  $f16, 0x464($sp)
/* 0C9FE8 7F0954B8 E7AE0478 */  swc1  $f14, 0x478($sp)
/* 0C9FEC 7F0954BC E7AC047C */  swc1  $f12, 0x47c($sp)
/* 0C9FF0 7F0954C0 E7A60490 */  swc1  $f6, 0x490($sp)
/* 0C9FF4 7F0954C4 E7A80494 */  swc1  $f8, 0x494($sp)
/* 0C9FF8 7F0954C8 E7AA04A8 */  swc1  $f10, 0x4a8($sp)
/* 0C9FFC 7F0954CC E7A004AC */  swc1  $f0, 0x4ac($sp)
/* 0CA000 7F0954D0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0CA004 7F0954D4 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA008 7F0954D8 8FA5056C */   lw    $a1, 0x56c($sp)
/* 0CA00C 7F0954DC 27A40454 */  addiu $a0, $sp, 0x454
/* 0CA010 7F0954E0 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA014 7F0954E4 8FA50568 */   lw    $a1, 0x568($sp)
/* 0CA018 7F0954E8 27A4046C */  addiu $a0, $sp, 0x46c
/* 0CA01C 7F0954EC 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA020 7F0954F0 8FA50560 */   lw    $a1, 0x560($sp)
/* 0CA024 7F0954F4 27A40484 */  addiu $a0, $sp, 0x484
/* 0CA028 7F0954F8 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA02C 7F0954FC 8FA50558 */   lw    $a1, 0x558($sp)
/* 0CA030 7F095500 27A4049C */  addiu $a0, $sp, 0x49c
/* 0CA034 7F095504 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA038 7F095508 8FA50554 */   lw    $a1, 0x554($sp)
/* 0CA03C 7F09550C 100000A7 */  b     .L7F0957AC
/* 0CA040 7F095510 00000000 */   nop
.L7F095514:
/* 0CA044 7F095514 C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0CA048 7F095518 C7A605C4 */  lwc1  $f6, 0x5c4($sp)
/* 0CA04C 7F09551C C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0CA050 7F095520 4618B102 */  mul.s $f4, $f22, $f24
/* 0CA054 7F095524 C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0CA058 7F095528 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0CA05C 7F09552C 46183202 */  mul.s $f8, $f6, $f24
/* 0CA060 7F095530 C7A605D0 */  lwc1  $f6, 0x5d0($sp)
/* 0CA064 7F095534 C7A205E4 */  lwc1  $f2, 0x5e4($sp)
/* 0CA068 7F095538 4618D282 */  mul.s $f10, $f26, $f24
/* 0CA06C 7F09553C E7A4043C */  swc1  $f4, 0x43c($sp)
/* 0CA070 7F095540 C7AC05EC */  lwc1  $f12, 0x5ec($sp)
/* 0CA074 7F095544 46189102 */  mul.s $f4, $f18, $f24
/* 0CA078 7F095548 E7A80440 */  swc1  $f8, 0x440($sp)
/* 0CA07C 7F09554C C7AE05B4 */  lwc1  $f14, 0x5b4($sp)
/* 0CA080 7F095550 46183202 */  mul.s $f8, $f6, $f24
/* 0CA084 7F095554 E7AA0444 */  swc1  $f10, 0x444($sp)
/* 0CA088 7F095558 C7A605E8 */  lwc1  $f6, 0x5e8($sp)
/* 0CA08C 7F09555C 4618A282 */  mul.s $f10, $f20, $f24
/* 0CA090 7F095560 E7A40454 */  swc1  $f4, 0x454($sp)
/* 0CA094 7F095564 C7B005BC */  lwc1  $f16, 0x5bc($sp)
/* 0CA098 7F095568 46181102 */  mul.s $f4, $f2, $f24
/* 0CA09C 7F09556C E7A80458 */  swc1  $f8, 0x458($sp)
/* 0CA0A0 7F095570 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CA0A4 7F095574 46183202 */  mul.s $f8, $f6, $f24
/* 0CA0A8 7F095578 E7AA045C */  swc1  $f10, 0x45c($sp)
/* 0CA0AC 7F09557C C7A605B8 */  lwc1  $f6, 0x5b8($sp)
/* 0CA0B0 7F095580 46186282 */  mul.s $f10, $f12, $f24
/* 0CA0B4 7F095584 E7A4046C */  swc1  $f4, 0x46c($sp)
/* 0CA0B8 7F095588 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CA0BC 7F09558C 46187102 */  mul.s $f4, $f14, $f24
/* 0CA0C0 7F095590 E7A80470 */  swc1  $f8, 0x470($sp)
/* 0CA0C4 7F095594 24110005 */  li    $s1, 5
/* 0CA0C8 7F095598 46183202 */  mul.s $f8, $f6, $f24
/* 0CA0CC 7F09559C E7AA0474 */  swc1  $f10, 0x474($sp)
/* 0CA0D0 7F0955A0 27A4043C */  addiu $a0, $sp, 0x43c
/* 0CA0D4 7F0955A4 46188282 */  mul.s $f10, $f16, $f24
/* 0CA0D8 7F0955A8 E7A40484 */  swc1  $f4, 0x484($sp)
/* 0CA0DC 7F0955AC C7A40590 */  lwc1  $f4, 0x590($sp)
/* 0CA0E0 7F0955B0 8FA50560 */  lw    $a1, 0x560($sp)
/* 0CA0E4 7F0955B4 E7A80488 */  swc1  $f8, 0x488($sp)
/* 0CA0E8 7F0955B8 46182182 */  mul.s $f6, $f4, $f24
/* 0CA0EC 7F0955BC C7A80594 */  lwc1  $f8, 0x594($sp)
/* 0CA0F0 7F0955C0 E7AA048C */  swc1  $f10, 0x48c($sp)
/* 0CA0F4 7F0955C4 C7A40598 */  lwc1  $f4, 0x598($sp)
/* 0CA0F8 7F0955C8 46184282 */  mul.s $f10, $f8, $f24
/* 0CA0FC 7F0955CC 4600D200 */  add.s $f8, $f26, $f0
/* 0CA100 7F0955D0 E7B60448 */  swc1  $f22, 0x448($sp)
/* 0CA104 7F0955D4 E7A6049C */  swc1  $f6, 0x49c($sp)
/* 0CA108 7F0955D8 46182182 */  mul.s $f6, $f4, $f24
/* 0CA10C 7F0955DC 46006100 */  add.s $f4, $f12, $f0
/* 0CA110 7F0955E0 E7A8044C */  swc1  $f8, 0x44c($sp)
/* 0CA114 7F0955E4 E7AA04A0 */  swc1  $f10, 0x4a0($sp)
/* 0CA118 7F0955E8 C7A80590 */  lwc1  $f8, 0x590($sp)
/* 0CA11C 7F0955EC 4600A280 */  add.s $f10, $f20, $f0
/* 0CA120 7F0955F0 E7A4047C */  swc1  $f4, 0x47c($sp)
/* 0CA124 7F0955F4 E7A604A4 */  swc1  $f6, 0x4a4($sp)
/* 0CA128 7F0955F8 46008180 */  add.s $f6, $f16, $f0
/* 0CA12C 7F0955FC E7AA0464 */  swc1  $f10, 0x464($sp)
/* 0CA130 7F095600 C7AA0598 */  lwc1  $f10, 0x598($sp)
/* 0CA134 7F095604 E7B20460 */  swc1  $f18, 0x460($sp)
/* 0CA138 7F095608 E7A60494 */  swc1  $f6, 0x494($sp)
/* 0CA13C 7F09560C 46005100 */  add.s $f4, $f10, $f0
/* 0CA140 7F095610 E7A20478 */  swc1  $f2, 0x478($sp)
/* 0CA144 7F095614 E7AE0490 */  swc1  $f14, 0x490($sp)
/* 0CA148 7F095618 E7A804A8 */  swc1  $f8, 0x4a8($sp)
/* 0CA14C 7F09561C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA150 7F095620 E7A404AC */   swc1  $f4, 0x4ac($sp)
/* 0CA154 7F095624 27A40454 */  addiu $a0, $sp, 0x454
/* 0CA158 7F095628 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA15C 7F09562C 8FA50564 */   lw    $a1, 0x564($sp)
/* 0CA160 7F095630 27A4046C */  addiu $a0, $sp, 0x46c
/* 0CA164 7F095634 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA168 7F095638 8FA5056C */   lw    $a1, 0x56c($sp)
/* 0CA16C 7F09563C 27A40484 */  addiu $a0, $sp, 0x484
/* 0CA170 7F095640 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA174 7F095644 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0CA178 7F095648 27A4049C */  addiu $a0, $sp, 0x49c
/* 0CA17C 7F09564C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA180 7F095650 8FA50550 */   lw    $a1, 0x550($sp)
/* 0CA184 7F095654 10000055 */  b     .L7F0957AC
/* 0CA188 7F095658 00000000 */   nop
.L7F09565C:
/* 0CA18C 7F09565C C7AE05D8 */  lwc1  $f14, 0x5d8($sp)
/* 0CA190 7F095660 C7A805DC */  lwc1  $f8, 0x5dc($sp)
/* 0CA194 7F095664 C7B005E0 */  lwc1  $f16, 0x5e0($sp)
/* 0CA198 7F095668 46187182 */  mul.s $f6, $f14, $f24
/* 0CA19C 7F09566C C7B605C0 */  lwc1  $f22, 0x5c0($sp)
/* 0CA1A0 7F095670 C7BA05C8 */  lwc1  $f26, 0x5c8($sp)
/* 0CA1A4 7F095674 46184282 */  mul.s $f10, $f8, $f24
/* 0CA1A8 7F095678 C7A805C4 */  lwc1  $f8, 0x5c4($sp)
/* 0CA1AC 7F09567C C7B205CC */  lwc1  $f18, 0x5cc($sp)
/* 0CA1B0 7F095680 46188102 */  mul.s $f4, $f16, $f24
/* 0CA1B4 7F095684 E7A6043C */  swc1  $f6, 0x43c($sp)
/* 0CA1B8 7F095688 C7B405D4 */  lwc1  $f20, 0x5d4($sp)
/* 0CA1BC 7F09568C 4618B182 */  mul.s $f6, $f22, $f24
/* 0CA1C0 7F095690 E7AA0440 */  swc1  $f10, 0x440($sp)
/* 0CA1C4 7F095694 C7A2059C */  lwc1  $f2, 0x59c($sp)
/* 0CA1C8 7F095698 46184282 */  mul.s $f10, $f8, $f24
/* 0CA1CC 7F09569C E7A40444 */  swc1  $f4, 0x444($sp)
/* 0CA1D0 7F0956A0 C7A805D0 */  lwc1  $f8, 0x5d0($sp)
/* 0CA1D4 7F0956A4 4618D102 */  mul.s $f4, $f26, $f24
/* 0CA1D8 7F0956A8 E7A60454 */  swc1  $f6, 0x454($sp)
/* 0CA1DC 7F0956AC C7AC05A4 */  lwc1  $f12, 0x5a4($sp)
/* 0CA1E0 7F0956B0 46189182 */  mul.s $f6, $f18, $f24
/* 0CA1E4 7F0956B4 E7AA0458 */  swc1  $f10, 0x458($sp)
/* 0CA1E8 7F0956B8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CA1EC 7F0956BC 46184282 */  mul.s $f10, $f8, $f24
/* 0CA1F0 7F0956C0 E7A4045C */  swc1  $f4, 0x45c($sp)
/* 0CA1F4 7F0956C4 C7A805A0 */  lwc1  $f8, 0x5a0($sp)
/* 0CA1F8 7F0956C8 4618A102 */  mul.s $f4, $f20, $f24
/* 0CA1FC 7F0956CC E7A6046C */  swc1  $f6, 0x46c($sp)
/* 0CA200 7F0956D0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CA204 7F0956D4 46181182 */  mul.s $f6, $f2, $f24
/* 0CA208 7F0956D8 E7AA0470 */  swc1  $f10, 0x470($sp)
/* 0CA20C 7F0956DC 24110005 */  li    $s1, 5
/* 0CA210 7F0956E0 46184282 */  mul.s $f10, $f8, $f24
/* 0CA214 7F0956E4 E7A40474 */  swc1  $f4, 0x474($sp)
/* 0CA218 7F0956E8 27A4043C */  addiu $a0, $sp, 0x43c
/* 0CA21C 7F0956EC 46186102 */  mul.s $f4, $f12, $f24
/* 0CA220 7F0956F0 E7A60484 */  swc1  $f6, 0x484($sp)
/* 0CA224 7F0956F4 C7A605B4 */  lwc1  $f6, 0x5b4($sp)
/* 0CA228 7F0956F8 8FA50568 */  lw    $a1, 0x568($sp)
/* 0CA22C 7F0956FC E7AA0488 */  swc1  $f10, 0x488($sp)
/* 0CA230 7F095700 46183202 */  mul.s $f8, $f6, $f24
/* 0CA234 7F095704 C7AA05B8 */  lwc1  $f10, 0x5b8($sp)
/* 0CA238 7F095708 E7A4048C */  swc1  $f4, 0x48c($sp)
/* 0CA23C 7F09570C C7A605BC */  lwc1  $f6, 0x5bc($sp)
/* 0CA240 7F095710 46185102 */  mul.s $f4, $f10, $f24
/* 0CA244 7F095714 46008280 */  add.s $f10, $f16, $f0
/* 0CA248 7F095718 E7AE0448 */  swc1  $f14, 0x448($sp)
/* 0CA24C 7F09571C E7A8049C */  swc1  $f8, 0x49c($sp)
/* 0CA250 7F095720 46183202 */  mul.s $f8, $f6, $f24
/* 0CA254 7F095724 4600A180 */  add.s $f6, $f20, $f0
/* 0CA258 7F095728 E7AA044C */  swc1  $f10, 0x44c($sp)
/* 0CA25C 7F09572C E7A404A0 */  swc1  $f4, 0x4a0($sp)
/* 0CA260 7F095730 C7AA05B4 */  lwc1  $f10, 0x5b4($sp)
/* 0CA264 7F095734 4600D100 */  add.s $f4, $f26, $f0
/* 0CA268 7F095738 E7A6047C */  swc1  $f6, 0x47c($sp)
/* 0CA26C 7F09573C E7A804A4 */  swc1  $f8, 0x4a4($sp)
/* 0CA270 7F095740 46006200 */  add.s $f8, $f12, $f0
/* 0CA274 7F095744 E7A40464 */  swc1  $f4, 0x464($sp)
/* 0CA278 7F095748 C7A405BC */  lwc1  $f4, 0x5bc($sp)
/* 0CA27C 7F09574C E7B60460 */  swc1  $f22, 0x460($sp)
/* 0CA280 7F095750 E7A80494 */  swc1  $f8, 0x494($sp)
/* 0CA284 7F095754 46002180 */  add.s $f6, $f4, $f0
/* 0CA288 7F095758 E7B20478 */  swc1  $f18, 0x478($sp)
/* 0CA28C 7F09575C E7A20490 */  swc1  $f2, 0x490($sp)
/* 0CA290 7F095760 E7AA04A8 */  swc1  $f10, 0x4a8($sp)
/* 0CA294 7F095764 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA298 7F095768 E7A604AC */   swc1  $f6, 0x4ac($sp)
/* 0CA29C 7F09576C 27A40454 */  addiu $a0, $sp, 0x454
/* 0CA2A0 7F095770 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA2A4 7F095774 8FA50560 */   lw    $a1, 0x560($sp)
/* 0CA2A8 7F095778 27A4046C */  addiu $a0, $sp, 0x46c
/* 0CA2AC 7F09577C 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA2B0 7F095780 8FA50564 */   lw    $a1, 0x564($sp)
/* 0CA2B4 7F095784 27A40484 */  addiu $a0, $sp, 0x484
/* 0CA2B8 7F095788 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA2BC 7F09578C 8FA50554 */   lw    $a1, 0x554($sp)
/* 0CA2C0 7F095790 27A4049C */  addiu $a0, $sp, 0x49c
/* 0CA2C4 7F095794 0FC24FE9 */  jal   sub_GAME_7F093FA4
/* 0CA2C8 7F095798 8FA5055C */   lw    $a1, 0x55c($sp)
/* 0CA2CC 7F09579C 10000003 */  b     .L7F0957AC
/* 0CA2D0 7F0957A0 00000000 */   nop
def_7F094A38:
.L7F0957A4:
/* 0CA2D4 7F0957A4 100006EE */  b     .L7F097360
/* 0CA2D8 7F0957A8 8FA206B0 */   lw    $v0, 0x6b0($sp)
.L7F0957AC:
/* 0CA2DC 7F0957AC 5A20018E */  blezl $s1, .L7F095DE8
/* 0CA2E0 7F0957B0 8FAA005C */   lw    $t2, 0x5c($sp)
/* 0CA2E4 7F0957B4 0FC1E0F9 */  jal   currentPlayerGetProjectionMatrixF
/* 0CA2E8 7F0957B8 00000000 */   nop
/* 0CA2EC 7F0957BC 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0CA2F0 7F0957C0 00408025 */   move  $s0, $v0
/* 0CA2F4 7F0957C4 02002025 */  move  $a0, $s0
/* 0CA2F8 7F0957C8 00402825 */  move  $a1, $v0
/* 0CA2FC 7F0957CC 0FC16032 */  jal   matrix_4x4_multiply
/* 0CA300 7F0957D0 27A603CC */   addiu $a2, $sp, 0x3cc
/* 0CA304 7F0957D4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA308 7F0957D8 44814000 */  mtc1  $at, $f8
/* 0CA30C 7F0957DC 3C048008 */  lui   $a0, %hi(dword_CODE_bss_80079E98)
/* 0CA310 7F0957E0 24849E98 */  addiu $a0, %lo(dword_CODE_bss_80079E98) # addiu $a0, $a0, -0x6168
/* 0CA314 7F0957E4 46184003 */  div.s $f0, $f8, $f24
/* 0CA318 7F0957E8 44050000 */  mfc1  $a1, $f0
/* 0CA31C 7F0957EC 44060000 */  mfc1  $a2, $f0
/* 0CA320 7F0957F0 44070000 */  mfc1  $a3, $f0
/* 0CA324 7F0957F4 0C005BA4 */  jal   guScaleF
/* 0CA328 7F0957F8 00000000 */   nop
/* 0CA32C 7F0957FC 3C058008 */  lui   $a1, %hi(dword_CODE_bss_80079E98)
/* 0CA330 7F095800 24A59E98 */  addiu $a1, %lo(dword_CODE_bss_80079E98) # addiu $a1, $a1, -0x6168
/* 0CA334 7F095804 27A403CC */  addiu $a0, $sp, 0x3cc
/* 0CA338 7F095808 0FC16032 */  jal   matrix_4x4_multiply
/* 0CA33C 7F09580C 27A6038C */   addiu $a2, $sp, 0x38c
/* 0CA340 7F095810 1A20004E */  blez  $s1, .L7F09594C
/* 0CA344 7F095814 AFA00270 */   sw    $zero, 0x270($sp)
/* 0CA348 7F095818 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CA34C 7F09581C 27A4043C */  addiu $a0, $sp, 0x43c
/* 0CA350 7F095820 4481D000 */  mtc1  $at, $f26
/* 0CA354 7F095824 AFA40058 */  sw    $a0, 0x58($sp)
/* 0CA358 7F095828 27B00274 */  addiu $s0, $sp, 0x274
.L7F09582C:
/* 0CA35C 7F09582C 3C018005 */  lui   $at, %hi(D_80057584)
/* 0CA360 7F095830 C4207584 */  lwc1  $f0, %lo(D_80057584)($at)
/* 0CA364 7F095834 8FA40058 */  lw    $a0, 0x58($sp)
/* 0CA368 7F095838 27A5038C */  addiu $a1, $sp, 0x38c
/* 0CA36C 7F09583C 44070000 */  mfc1  $a3, $f0
/* 0CA370 7F095840 24060082 */  li    $a2, 130
/* 0CA374 7F095844 AFB00014 */  sw    $s0, 0x14($sp)
/* 0CA378 7F095848 0FC25CE2 */  jal   sub_GAME_7F097388
/* 0CA37C 7F09584C E7A00010 */   swc1  $f0, 0x10($sp)
/* 0CA380 7F095850 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CA384 7F095854 00000000 */   nop
/* 0CA388 7F095858 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CA38C 7F09585C 46000506 */   mov.s $f20, $f0
/* 0CA390 7F095860 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CA394 7F095864 46000586 */   mov.s $f22, $f0
/* 0CA398 7F095868 46160280 */  add.s $f10, $f0, $f22
/* 0CA39C 7F09586C 461AA382 */  mul.s $f14, $f20, $f26
/* 0CA3A0 7F095870 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA3A4 7F095874 44813000 */  mtc1  $at, $f6
/* 0CA3A8 7F095878 461A5102 */  mul.s $f4, $f10, $f26
/* 0CA3AC 7F09587C C60C0028 */  lwc1  $f12, 0x28($s0)
/* 0CA3B0 7F095880 46062201 */  sub.s $f8, $f4, $f6
/* 0CA3B4 7F095884 44064000 */  mfc1  $a2, $f8
/* 0CA3B8 7F095888 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CA3BC 7F09588C 00000000 */   nop
/* 0CA3C0 7F095890 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CA3C4 7F095894 E6000028 */   swc1  $f0, 0x28($s0)
/* 0CA3C8 7F095898 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CA3CC 7F09589C 46000506 */   mov.s $f20, $f0
/* 0CA3D0 7F0958A0 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CA3D4 7F0958A4 46000586 */   mov.s $f22, $f0
/* 0CA3D8 7F0958A8 46160280 */  add.s $f10, $f0, $f22
/* 0CA3DC 7F0958AC 461AA382 */  mul.s $f14, $f20, $f26
/* 0CA3E0 7F0958B0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA3E4 7F0958B4 44813000 */  mtc1  $at, $f6
/* 0CA3E8 7F0958B8 461A5102 */  mul.s $f4, $f10, $f26
/* 0CA3EC 7F0958BC C60C002C */  lwc1  $f12, 0x2c($s0)
/* 0CA3F0 7F0958C0 46062201 */  sub.s $f8, $f4, $f6
/* 0CA3F4 7F0958C4 44064000 */  mfc1  $a2, $f8
/* 0CA3F8 7F0958C8 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CA3FC 7F0958CC 00000000 */   nop
/* 0CA400 7F0958D0 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CA404 7F0958D4 E600002C */   swc1  $f0, 0x2c($s0)
/* 0CA408 7F0958D8 461A0282 */  mul.s $f10, $f0, $f26
/* 0CA40C 7F0958DC C606002C */  lwc1  $f6, 0x2c($s0)
/* 0CA410 7F0958E0 461A5100 */  add.s $f4, $f10, $f26
/* 0CA414 7F0958E4 4606203C */  c.lt.s $f4, $f6
/* 0CA418 7F0958E8 00000000 */  nop
/* 0CA41C 7F0958EC 45020010 */  bc1fl .L7F095930
/* 0CA420 7F0958F0 8FB90058 */   lw    $t9, 0x58($sp)
/* 0CA424 7F0958F4 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CA428 7F0958F8 00000000 */   nop
/* 0CA42C 7F0958FC 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CA430 7F095900 46000506 */   mov.s $f20, $f0
/* 0CA434 7F095904 46140200 */  add.s $f8, $f0, $f20
/* 0CA438 7F095908 C602002C */  lwc1  $f2, 0x2c($s0)
/* 0CA43C 7F09590C 461A4282 */  mul.s $f10, $f8, $f26
/* 0CA440 7F095910 461A5101 */  sub.s $f4, $f10, $f26
/* 0CA444 7F095914 4604103C */  c.lt.s $f2, $f4
/* 0CA448 7F095918 00000000 */  nop
/* 0CA44C 7F09591C 45020004 */  bc1fl .L7F095930
/* 0CA450 7F095920 8FB90058 */   lw    $t9, 0x58($sp)
/* 0CA454 7F095924 461A1181 */  sub.s $f6, $f2, $f26
/* 0CA458 7F095928 E606002C */  swc1  $f6, 0x2c($s0)
/* 0CA45C 7F09592C 8FB90058 */  lw    $t9, 0x58($sp)
.L7F095930:
/* 0CA460 7F095930 8FA20270 */  lw    $v0, 0x270($sp)
/* 0CA464 7F095934 26100038 */  addiu $s0, $s0, 0x38
/* 0CA468 7F095938 272D0018 */  addiu $t5, $t9, 0x18
/* 0CA46C 7F09593C 24420001 */  addiu $v0, $v0, 1
/* 0CA470 7F095940 AFA20270 */  sw    $v0, 0x270($sp)
/* 0CA474 7F095944 1451FFB9 */  bne   $v0, $s1, .L7F09582C
/* 0CA478 7F095948 AFAD0058 */   sw    $t5, 0x58($sp)
.L7F09594C:
/* 0CA47C 7F09594C 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0CA480 7F095950 00000000 */   nop
/* 0CA484 7F095954 904B0020 */  lbu   $t3, 0x20($v0)
/* 0CA488 7F095958 8FAE06B0 */  lw    $t6, 0x6b0($sp)
/* 0CA48C 7F09595C 3C0FE700 */  lui   $t7, 0xe700
/* 0CA490 7F095960 156000A6 */  bnez  $t3, .L7F095BFC
/* 0CA494 7F095964 25CA0008 */   addiu $t2, $t6, 8
/* 0CA498 7F095968 3C018005 */  lui   $at, %hi(D_80057588)
/* 0CA49C 7F09596C C4327588 */  lwc1  $f18, %lo(D_80057588)($at)
/* 0CA4A0 7F095970 3C018005 */  lui   $at, %hi(D_8005758C)
/* 0CA4A4 7F095974 C434758C */  lwc1  $f20, %lo(D_8005758C)($at)
/* 0CA4A8 7F095978 44808000 */  mtc1  $zero, $f16
/* 0CA4AC 7F09597C 00001825 */  move  $v1, $zero
/* 0CA4B0 7F095980 46009086 */  mov.s $f2, $f18
/* 0CA4B4 7F095984 4600A386 */  mov.s $f14, $f20
/* 0CA4B8 7F095988 1A200054 */  blez  $s1, .L7F095ADC
/* 0CA4BC 7F09598C 46008306 */   mov.s $f12, $f16
/* 0CA4C0 7F095990 32220001 */  andi  $v0, $s1, 1
/* 0CA4C4 7F095994 10400019 */  beqz  $v0, .L7F0959FC
/* 0CA4C8 7F095998 C7A0029C */   lwc1  $f0, 0x29c($sp)
/* 0CA4CC 7F09599C 4612003C */  c.lt.s $f0, $f18
/* 0CA4D0 7F0959A0 44804000 */  mtc1  $zero, $f8
/* 0CA4D4 7F0959A4 44805000 */  mtc1  $zero, $f10
/* 0CA4D8 7F0959A8 24030001 */  li    $v1, 1
/* 0CA4DC 7F0959AC 45020003 */  bc1fl .L7F0959BC
/* 0CA4E0 7F0959B0 4600403C */   c.lt.s $f8, $f0
/* 0CA4E4 7F0959B4 46000086 */  mov.s $f2, $f0
/* 0CA4E8 7F0959B8 4600403C */  c.lt.s $f8, $f0
.L7F0959BC:
/* 0CA4EC 7F0959BC 00000000 */  nop
/* 0CA4F0 7F0959C0 45020003 */  bc1fl .L7F0959D0
/* 0CA4F4 7F0959C4 C7A002A0 */   lwc1  $f0, 0x2a0($sp)
/* 0CA4F8 7F0959C8 46000306 */  mov.s $f12, $f0
/* 0CA4FC 7F0959CC C7A002A0 */  lwc1  $f0, 0x2a0($sp)
.L7F0959D0:
/* 0CA500 7F0959D0 4614003C */  c.lt.s $f0, $f20
/* 0CA504 7F0959D4 00000000 */  nop
/* 0CA508 7F0959D8 45020003 */  bc1fl .L7F0959E8
/* 0CA50C 7F0959DC 4600503C */   c.lt.s $f10, $f0
/* 0CA510 7F0959E0 46000386 */  mov.s $f14, $f0
/* 0CA514 7F0959E4 4600503C */  c.lt.s $f10, $f0
.L7F0959E8:
/* 0CA518 7F0959E8 00000000 */  nop
/* 0CA51C 7F0959EC 45000002 */  bc1f  .L7F0959F8
/* 0CA520 7F0959F0 00000000 */   nop
/* 0CA524 7F0959F4 46000406 */  mov.s $f16, $f0
.L7F0959F8:
/* 0CA528 7F0959F8 10710038 */  beq   $v1, $s1, .L7F095ADC
.L7F0959FC:
/* 0CA52C 7F0959FC 000360C0 */   sll   $t4, $v1, 3
/* 0CA530 7F095A00 0011C0C0 */  sll   $t8, $s1, 3
/* 0CA534 7F095A04 0311C023 */  subu  $t8, $t8, $s1
/* 0CA538 7F095A08 01836023 */  subu  $t4, $t4, $v1
/* 0CA53C 7F095A0C 27AE0274 */  addiu $t6, $sp, 0x274
/* 0CA540 7F095A10 000C60C0 */  sll   $t4, $t4, 3
/* 0CA544 7F095A14 0018C0C0 */  sll   $t8, $t8, 3
/* 0CA548 7F095A18 030E2021 */  addu  $a0, $t8, $t6
/* 0CA54C 7F095A1C 018E1021 */  addu  $v0, $t4, $t6
/* 0CA550 7F095A20 C4400028 */  lwc1  $f0, 0x28($v0)
.L7F095A24:
/* 0CA554 7F095A24 4602003C */  c.lt.s $f0, $f2
/* 0CA558 7F095A28 00000000 */  nop
/* 0CA55C 7F095A2C 45020003 */  bc1fl .L7F095A3C
/* 0CA560 7F095A30 4600603C */   c.lt.s $f12, $f0
/* 0CA564 7F095A34 46000086 */  mov.s $f2, $f0
/* 0CA568 7F095A38 4600603C */  c.lt.s $f12, $f0
.L7F095A3C:
/* 0CA56C 7F095A3C 00000000 */  nop
/* 0CA570 7F095A40 45020003 */  bc1fl .L7F095A50
/* 0CA574 7F095A44 C440002C */   lwc1  $f0, 0x2c($v0)
/* 0CA578 7F095A48 46000306 */  mov.s $f12, $f0
/* 0CA57C 7F095A4C C440002C */  lwc1  $f0, 0x2c($v0)
.L7F095A50:
/* 0CA580 7F095A50 460E003C */  c.lt.s $f0, $f14
/* 0CA584 7F095A54 00000000 */  nop
/* 0CA588 7F095A58 45020003 */  bc1fl .L7F095A68
/* 0CA58C 7F095A5C 4600803C */   c.lt.s $f16, $f0
/* 0CA590 7F095A60 46000386 */  mov.s $f14, $f0
/* 0CA594 7F095A64 4600803C */  c.lt.s $f16, $f0
.L7F095A68:
/* 0CA598 7F095A68 00000000 */  nop
/* 0CA59C 7F095A6C 45020003 */  bc1fl .L7F095A7C
/* 0CA5A0 7F095A70 C4400060 */   lwc1  $f0, 0x60($v0)
/* 0CA5A4 7F095A74 46000406 */  mov.s $f16, $f0
/* 0CA5A8 7F095A78 C4400060 */  lwc1  $f0, 0x60($v0)
.L7F095A7C:
/* 0CA5AC 7F095A7C 4602003C */  c.lt.s $f0, $f2
/* 0CA5B0 7F095A80 00000000 */  nop
/* 0CA5B4 7F095A84 45020003 */  bc1fl .L7F095A94
/* 0CA5B8 7F095A88 4600603C */   c.lt.s $f12, $f0
/* 0CA5BC 7F095A8C 46000086 */  mov.s $f2, $f0
/* 0CA5C0 7F095A90 4600603C */  c.lt.s $f12, $f0
.L7F095A94:
/* 0CA5C4 7F095A94 00000000 */  nop
/* 0CA5C8 7F095A98 45020003 */  bc1fl .L7F095AA8
/* 0CA5CC 7F095A9C C4400064 */   lwc1  $f0, 0x64($v0)
/* 0CA5D0 7F095AA0 46000306 */  mov.s $f12, $f0
/* 0CA5D4 7F095AA4 C4400064 */  lwc1  $f0, 0x64($v0)
.L7F095AA8:
/* 0CA5D8 7F095AA8 24420070 */  addiu $v0, $v0, 0x70
/* 0CA5DC 7F095AAC 460E003C */  c.lt.s $f0, $f14
/* 0CA5E0 7F095AB0 00000000 */  nop
/* 0CA5E4 7F095AB4 45020003 */  bc1fl .L7F095AC4
/* 0CA5E8 7F095AB8 4600803C */   c.lt.s $f16, $f0
/* 0CA5EC 7F095ABC 46000386 */  mov.s $f14, $f0
/* 0CA5F0 7F095AC0 4600803C */  c.lt.s $f16, $f0
.L7F095AC4:
/* 0CA5F4 7F095AC4 00000000 */  nop
/* 0CA5F8 7F095AC8 45000002 */  bc1f  .L7F095AD4
/* 0CA5FC 7F095ACC 00000000 */   nop
/* 0CA600 7F095AD0 46000406 */  mov.s $f16, $f0
.L7F095AD4:
/* 0CA604 7F095AD4 5444FFD3 */  bnel  $v0, $a0, .L7F095A24
/* 0CA608 7F095AD8 C4400028 */   lwc1  $f0, 0x28($v0)
.L7F095ADC:
/* 0CA60C 7F095ADC 8FAA06B0 */  lw    $t2, 0x6b0($sp)
/* 0CA610 7F095AE0 3C19E700 */  lui   $t9, 0xe700
/* 0CA614 7F095AE4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0CA618 7F095AE8 254F0008 */  addiu $t7, $t2, 8
/* 0CA61C 7F095AEC AFAF06B0 */  sw    $t7, 0x6b0($sp)
/* 0CA620 7F095AF0 AD400004 */  sw    $zero, 4($t2)
/* 0CA624 7F095AF4 AD590000 */  sw    $t9, ($t2)
/* 0CA628 7F095AF8 8FAD06B0 */  lw    $t5, 0x6b0($sp)
/* 0CA62C 7F095AFC 44810000 */  mtc1  $at, $f0
/* 0CA630 7F095B00 3C0CBA00 */  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
/* 0CA634 7F095B04 25AB0008 */  addiu $t3, $t5, 8
/* 0CA638 7F095B08 AFAB06B0 */  sw    $t3, 0x6b0($sp)
/* 0CA63C 7F095B0C 358C1402 */  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
/* 0CA640 7F095B10 3C180030 */  lui   $t8, 0x30
/* 0CA644 7F095B14 46006102 */  mul.s $f4, $f12, $f0
/* 0CA648 7F095B18 ADB80004 */  sw    $t8, 4($t5)
/* 0CA64C 7F095B1C ADAC0000 */  sw    $t4, ($t5)
/* 0CA650 7F095B20 8FAE06B0 */  lw    $t6, 0x6b0($sp)
/* 0CA654 7F095B24 46008202 */  mul.s $f8, $f16, $f0
/* 0CA658 7F095B28 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 0CA65C 7F095B2C 25CA0008 */  addiu $t2, $t6, 8
/* 0CA660 7F095B30 AFAA06B0 */  sw    $t2, 0x6b0($sp)
/* 0CA664 7F095B34 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0CA668 7F095B38 ADCF0000 */  sw    $t7, ($t6)
/* 0CA66C 7F095B3C ADC00004 */  sw    $zero, 4($t6)
/* 0CA670 7F095B40 4600218D */  trunc.w.s $f6, $f4
/* 0CA674 7F095B44 8FB906B0 */  lw    $t9, 0x6b0($sp)
/* 0CA678 7F095B48 46001102 */  mul.s $f4, $f2, $f0
/* 0CA67C 7F095B4C 4600428D */  trunc.w.s $f10, $f8
/* 0CA680 7F095B50 272D0008 */  addiu $t5, $t9, 8
/* 0CA684 7F095B54 46007202 */  mul.s $f8, $f14, $f0
/* 0CA688 7F095B58 3C07BA00 */  lui   $a3, (0xBA001301 >> 16) # lui $a3, 0xba00
/* 0CA68C 7F095B5C AFAD06B0 */  sw    $t5, 0x6b0($sp)
/* 0CA690 7F095B60 34E71301 */  ori   $a3, (0xBA001301 & 0xFFFF) # ori $a3, $a3, 0x1301
/* 0CA694 7F095B64 AF270000 */  sw    $a3, ($t9)
/* 0CA698 7F095B68 AF200004 */  sw    $zero, 4($t9)
/* 0CA69C 7F095B6C 8FA606B0 */  lw    $a2, 0x6b0($sp)
/* 0CA6A0 7F095B70 440E3000 */  mfc1  $t6, $f6
/* 0CA6A4 7F095B74 440B5000 */  mfc1  $t3, $f10
/* 0CA6A8 7F095B78 24CC0008 */  addiu $t4, $a2, 8
/* 0CA6AC 7F095B7C 31CA03FF */  andi  $t2, $t6, 0x3ff
/* 0CA6B0 7F095B80 4600428D */  trunc.w.s $f10, $f8
/* 0CA6B4 7F095B84 000A7B80 */  sll   $t7, $t2, 0xe
/* 0CA6B8 7F095B88 AFAC06B0 */  sw    $t4, 0x6b0($sp)
/* 0CA6BC 7F095B8C 4600218D */  trunc.w.s $f6, $f4
/* 0CA6C0 7F095B90 3C01F600 */  lui   $at, 0xf600
/* 0CA6C4 7F095B94 01E1C825 */  or    $t9, $t7, $at
/* 0CA6C8 7F095B98 316C03FF */  andi  $t4, $t3, 0x3ff
/* 0CA6CC 7F095B9C 000CC080 */  sll   $t8, $t4, 2
/* 0CA6D0 7F095BA0 03387025 */  or    $t6, $t9, $t8
/* 0CA6D4 7F095BA4 44195000 */  mfc1  $t9, $f10
/* 0CA6D8 7F095BA8 440F3000 */  mfc1  $t7, $f6
/* 0CA6DC 7F095BAC ACCE0000 */  sw    $t6, ($a2)
/* 0CA6E0 7F095BB0 333803FF */  andi  $t8, $t9, 0x3ff
/* 0CA6E4 7F095BB4 31ED03FF */  andi  $t5, $t7, 0x3ff
/* 0CA6E8 7F095BB8 000D5B80 */  sll   $t3, $t5, 0xe
/* 0CA6EC 7F095BBC 00187080 */  sll   $t6, $t8, 2
/* 0CA6F0 7F095BC0 016E5025 */  or    $t2, $t3, $t6
/* 0CA6F4 7F095BC4 ACCA0004 */  sw    $t2, 4($a2)
/* 0CA6F8 7F095BC8 8FAF06B0 */  lw    $t7, 0x6b0($sp)
/* 0CA6FC 7F095BCC 3C0CE700 */  lui   $t4, 0xe700
/* 0CA700 7F095BD0 3C0B0008 */  lui   $t3, 8
/* 0CA704 7F095BD4 25ED0008 */  addiu $t5, $t7, 8
/* 0CA708 7F095BD8 AFAD06B0 */  sw    $t5, 0x6b0($sp)
/* 0CA70C 7F095BDC ADE00004 */  sw    $zero, 4($t7)
/* 0CA710 7F095BE0 ADEC0000 */  sw    $t4, ($t7)
/* 0CA714 7F095BE4 8FB906B0 */  lw    $t9, 0x6b0($sp)
/* 0CA718 7F095BE8 27380008 */  addiu $t8, $t9, 8
/* 0CA71C 7F095BEC AFB806B0 */  sw    $t8, 0x6b0($sp)
/* 0CA720 7F095BF0 AF2B0004 */  sw    $t3, 4($t9)
/* 0CA724 7F095BF4 1000007B */  b     .L7F095DE4
/* 0CA728 7F095BF8 AF270000 */   sw    $a3, ($t9)
.L7F095BFC:
/* 0CA72C 7F095BFC AFAA06B0 */  sw    $t2, 0x6b0($sp)
/* 0CA730 7F095C00 ADC00004 */  sw    $zero, 4($t6)
/* 0CA734 7F095C04 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0CA738 7F095C08 ADCF0000 */   sw    $t7, ($t6)
/* 0CA73C 7F095C0C 844D0028 */  lh    $t5, 0x28($v0)
/* 0CA740 7F095C10 3C198009 */  lui   $t9, %hi(skywaterimages)
/* 0CA744 7F095C14 8F39D124 */  lw    $t9, %lo(skywaterimages)($t9)
/* 0CA748 7F095C18 000D6080 */  sll   $t4, $t5, 2
/* 0CA74C 7F095C1C 018D6023 */  subu  $t4, $t4, $t5
/* 0CA750 7F095C20 000C6080 */  sll   $t4, $t4, 2
/* 0CA754 7F095C24 24180002 */  li    $t8, 2
/* 0CA758 7F095C28 AFB80010 */  sw    $t8, 0x10($sp)
/* 0CA75C 7F095C2C 27A406B0 */  addiu $a0, $sp, 0x6b0
/* 0CA760 7F095C30 24060001 */  li    $a2, 1
/* 0CA764 7F095C34 00003825 */  move  $a3, $zero
/* 0CA768 7F095C38 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0CA76C 7F095C3C 01992821 */   addu  $a1, $t4, $t9
/* 0CA770 7F095C40 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CA774 7F095C44 0FC24D0F */  jal   sub_GAME_7F09343C
/* 0CA778 7F095C48 00002825 */   move  $a1, $zero
/* 0CA77C 7F095C4C 244B0008 */  addiu $t3, $v0, 8
/* 0CA780 7F095C50 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 0CA784 7F095C54 3C0A0F0A */  lui   $t2, (0x0F0A4000 >> 16) # lui $t2, 0xf0a
/* 0CA788 7F095C58 354A4000 */  ori   $t2, (0x0F0A4000 & 0xFFFF) # ori $t2, $t2, 0x4000
/* 0CA78C 7F095C5C 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 0CA790 7F095C60 AFAB06B0 */  sw    $t3, 0x6b0($sp)
/* 0CA794 7F095C64 24010004 */  li    $at, 4
/* 0CA798 7F095C68 AC4A0004 */  sw    $t2, 4($v0)
/* 0CA79C 7F095C6C 1621002A */  bne   $s1, $at, .L7F095D18
/* 0CA7A0 7F095C70 AC4E0000 */   sw    $t6, ($v0)
/* 0CA7A4 7F095C74 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA7A8 7F095C78 44812000 */  mtc1  $at, $f4
/* 0CA7AC 7F095C7C 27B00274 */  addiu $s0, $sp, 0x274
/* 0CA7B0 7F095C80 27B1031C */  addiu $s1, $sp, 0x31c
/* 0CA7B4 7F095C84 240F0001 */  li    $t7, 1
/* 0CA7B8 7F095C88 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0CA7BC 7F095C8C 02203825 */  move  $a3, $s1
/* 0CA7C0 7F095C90 02002825 */  move  $a1, $s0
/* 0CA7C4 7F095C94 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CA7C8 7F095C98 27A602AC */  addiu $a2, $sp, 0x2ac
/* 0CA7CC 7F095C9C 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA7D0 7F095CA0 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0CA7D4 7F095CA4 8FAD0430 */  lw    $t5, 0x430($sp)
/* 0CA7D8 7F095CA8 00402025 */  move  $a0, $v0
/* 0CA7DC 7F095CAC 02202825 */  move  $a1, $s1
/* 0CA7E0 7F095CB0 11A0000F */  beqz  $t5, .L7F095CF0
/* 0CA7E4 7F095CB4 27A602E4 */   addiu $a2, $sp, 0x2e4
/* 0CA7E8 7F095CB8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA7EC 7F095CBC 44811000 */  mtc1  $at, $f2
/* 0CA7F0 7F095CC0 C7A602D8 */  lwc1  $f6, 0x2d8($sp)
/* 0CA7F4 7F095CC4 C7A002A0 */  lwc1  $f0, 0x2a0($sp)
/* 0CA7F8 7F095CC8 C7AA0310 */  lwc1  $f10, 0x310($sp)
/* 0CA7FC 7F095CCC 46023200 */  add.s $f8, $f6, $f2
/* 0CA800 7F095CD0 C7A60348 */  lwc1  $f6, 0x348($sp)
/* 0CA804 7F095CD4 46020000 */  add.s $f0, $f0, $f2
/* 0CA808 7F095CD8 E7A802D8 */  swc1  $f8, 0x2d8($sp)
/* 0CA80C 7F095CDC 46025100 */  add.s $f4, $f10, $f2
/* 0CA810 7F095CE0 E7A002A0 */  swc1  $f0, 0x2a0($sp)
/* 0CA814 7F095CE4 46023200 */  add.s $f8, $f6, $f2
/* 0CA818 7F095CE8 E7A40310 */  swc1  $f4, 0x310($sp)
/* 0CA81C 7F095CEC E7A80348 */  swc1  $f8, 0x348($sp)
.L7F095CF0:
/* 0CA820 7F095CF0 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA824 7F095CF4 44815000 */  mtc1  $at, $f10
/* 0CA828 7F095CF8 240C0001 */  li    $t4, 1
/* 0CA82C 7F095CFC AFAC0014 */  sw    $t4, 0x14($sp)
/* 0CA830 7F095D00 02003825 */  move  $a3, $s0
/* 0CA834 7F095D04 AFA406B0 */  sw    $a0, 0x6b0($sp)
/* 0CA838 7F095D08 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA83C 7F095D0C E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0CA840 7F095D10 10000034 */  b     .L7F095DE4
/* 0CA844 7F095D14 AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F095D18:
/* 0CA848 7F095D18 24010005 */  li    $at, 5
/* 0CA84C 7F095D1C 16210024 */  bne   $s1, $at, .L7F095DB0
/* 0CA850 7F095D20 27B00274 */   addiu $s0, $sp, 0x274
/* 0CA854 7F095D24 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA858 7F095D28 44812000 */  mtc1  $at, $f4
/* 0CA85C 7F095D2C 24190001 */  li    $t9, 1
/* 0CA860 7F095D30 AFB90014 */  sw    $t9, 0x14($sp)
/* 0CA864 7F095D34 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CA868 7F095D38 02002825 */  move  $a1, $s0
/* 0CA86C 7F095D3C 27A602AC */  addiu $a2, $sp, 0x2ac
/* 0CA870 7F095D40 27A702E4 */  addiu $a3, $sp, 0x2e4
/* 0CA874 7F095D44 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA878 7F095D48 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0CA87C 7F095D4C 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA880 7F095D50 44813000 */  mtc1  $at, $f6
/* 0CA884 7F095D54 27B1031C */  addiu $s1, $sp, 0x31c
/* 0CA888 7F095D58 24180001 */  li    $t8, 1
/* 0CA88C 7F095D5C AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CA890 7F095D60 AFB80014 */  sw    $t8, 0x14($sp)
/* 0CA894 7F095D64 02203825 */  move  $a3, $s1
/* 0CA898 7F095D68 00402025 */  move  $a0, $v0
/* 0CA89C 7F095D6C 02002825 */  move  $a1, $s0
/* 0CA8A0 7F095D70 27A602E4 */  addiu $a2, $sp, 0x2e4
/* 0CA8A4 7F095D74 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA8A8 7F095D78 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0CA8AC 7F095D7C 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA8B0 7F095D80 44814000 */  mtc1  $at, $f8
/* 0CA8B4 7F095D84 240B0001 */  li    $t3, 1
/* 0CA8B8 7F095D88 AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CA8BC 7F095D8C AFAB0014 */  sw    $t3, 0x14($sp)
/* 0CA8C0 7F095D90 00402025 */  move  $a0, $v0
/* 0CA8C4 7F095D94 02002825 */  move  $a1, $s0
/* 0CA8C8 7F095D98 02203025 */  move  $a2, $s1
/* 0CA8CC 7F095D9C 27A70354 */  addiu $a3, $sp, 0x354
/* 0CA8D0 7F095DA0 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA8D4 7F095DA4 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0CA8D8 7F095DA8 1000000E */  b     .L7F095DE4
/* 0CA8DC 7F095DAC AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F095DB0:
/* 0CA8E0 7F095DB0 24010003 */  li    $at, 3
/* 0CA8E4 7F095DB4 1621000B */  bne   $s1, $at, .L7F095DE4
/* 0CA8E8 7F095DB8 27A50274 */   addiu $a1, $sp, 0x274
/* 0CA8EC 7F095DBC 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CA8F0 7F095DC0 44815000 */  mtc1  $at, $f10
/* 0CA8F4 7F095DC4 240E0001 */  li    $t6, 1
/* 0CA8F8 7F095DC8 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0CA8FC 7F095DCC 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CA900 7F095DD0 27A602AC */  addiu $a2, $sp, 0x2ac
/* 0CA904 7F095DD4 27A702E4 */  addiu $a3, $sp, 0x2e4
/* 0CA908 7F095DD8 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CA90C 7F095DDC E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0CA910 7F095DE0 AFA206B0 */  sw    $v0, 0x6b0($sp)
.L7F095DE4:
/* 0CA914 7F095DE4 8FAA005C */  lw    $t2, 0x5c($sp)
.L7F095DE8:
/* 0CA918 7F095DE8 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CA91C 7F095DEC 4481D000 */  mtc1  $at, $f26
/* 0CA920 7F095DF0 2D410010 */  sltiu $at, $t2, 0x10
/* 0CA924 7F095DF4 1020040A */  beqz  $at, .L7F096E20
/* 0CA928 7F095DF8 8FA306B0 */   lw    $v1, 0x6b0($sp)
/* 0CA92C 7F095DFC 000A5080 */  sll   $t2, $t2, 2
/* 0CA930 7F095E00 3C018005 */  lui   $at, %hi(jpt_80057590)
/* 0CA934 7F095E04 002A0821 */  addu  $at, $at, $t2
/* 0CA938 7F095E08 8C2A7590 */  lw    $t2, %lo(jpt_80057590)($at)
.L7F095E0C:
/* 0CA93C 7F095E0C 01400008 */  jr    $t2
/* 0CA940 7F095E10 00000000 */   nop
.L7F095E14:
/* 0CA944 7F095E14 10000552 */  b     .L7F097360
/* 0CA948 7F095E18 00601025 */   move  $v0, $v1
.L7F095E1C:
/* 0CA94C 7F095E1C C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CA950 7F095E20 C7A60648 */  lwc1  $f6, 0x648($sp)
/* 0CA954 7F095E24 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CA958 7F095E28 46181102 */  mul.s $f4, $f2, $f24
/* 0CA95C 7F095E2C C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CA960 7F095E30 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CA964 7F095E34 46183202 */  mul.s $f8, $f6, $f24
/* 0CA968 7F095E38 C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CA96C 7F095E3C C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CA970 7F095E40 46186282 */  mul.s $f10, $f12, $f24
/* 0CA974 7F095E44 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CA978 7F095E48 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CA97C 7F095E4C 46187102 */  mul.s $f4, $f14, $f24
/* 0CA980 7F095E50 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CA984 7F095E54 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CA988 7F095E58 46183202 */  mul.s $f8, $f6, $f24
/* 0CA98C 7F095E5C E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CA990 7F095E60 C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CA994 7F095E64 46188282 */  mul.s $f10, $f16, $f24
/* 0CA998 7F095E68 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CA99C 7F095E6C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CA9A0 7F095E70 46189102 */  mul.s $f4, $f18, $f24
/* 0CA9A4 7F095E74 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CA9A8 7F095E78 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CA9AC 7F095E7C 46183202 */  mul.s $f8, $f6, $f24
/* 0CA9B0 7F095E80 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CA9B4 7F095E84 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CA9B8 7F095E88 4618A282 */  mul.s $f10, $f20, $f24
/* 0CA9BC 7F095E8C E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CA9C0 7F095E90 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CA9C4 7F095E94 4618B102 */  mul.s $f4, $f22, $f24
/* 0CA9C8 7F095E98 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CA9CC 7F095E9C 24110004 */  li    $s1, 4
/* 0CA9D0 7F095EA0 46183202 */  mul.s $f8, $f6, $f24
/* 0CA9D4 7F095EA4 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CA9D8 7F095EA8 C7AA0628 */  lwc1  $f10, 0x628($sp)
/* 0CA9DC 7F095EAC 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CA9E0 7F095EB0 E7A404FC */  swc1  $f4, 0x4fc($sp)
/* 0CA9E4 7F095EB4 46185102 */  mul.s $f4, $f10, $f24
/* 0CA9E8 7F095EB8 8FA5058C */  lw    $a1, 0x58c($sp)
/* 0CA9EC 7F095EBC E7A80500 */  swc1  $f8, 0x500($sp)
/* 0CA9F0 7F095EC0 461C1182 */  mul.s $f6, $f2, $f28
/* 0CA9F4 7F095EC4 00000000 */  nop
/* 0CA9F8 7F095EC8 461C6202 */  mul.s $f8, $f12, $f28
/* 0CA9FC 7F095ECC E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CAA00 7F095ED0 461C7102 */  mul.s $f4, $f14, $f28
/* 0CAA04 7F095ED4 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CAA08 7F095ED8 461C8182 */  mul.s $f6, $f16, $f28
/* 0CAA0C 7F095EDC 46004280 */  add.s $f10, $f8, $f0
/* 0CAA10 7F095EE0 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CAA14 7F095EE4 E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CAA18 7F095EE8 461C9282 */  mul.s $f10, $f18, $f28
/* 0CAA1C 7F095EEC 46003200 */  add.s $f8, $f6, $f0
/* 0CAA20 7F095EF0 461CA102 */  mul.s $f4, $f20, $f28
/* 0CAA24 7F095EF4 E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CAA28 7F095EF8 461CB202 */  mul.s $f8, $f22, $f28
/* 0CAA2C 7F095EFC E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CAA30 7F095F00 C7AA0628 */  lwc1  $f10, 0x628($sp)
/* 0CAA34 7F095F04 46002180 */  add.s $f6, $f4, $f0
/* 0CAA38 7F095F08 461C5102 */  mul.s $f4, $f10, $f28
/* 0CAA3C 7F095F0C E7A80508 */  swc1  $f8, 0x508($sp)
/* 0CAA40 7F095F10 44814000 */  mtc1  $at, $f8
/* 0CAA44 7F095F14 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 0CAA48 7F095F18 46184283 */  div.s $f10, $f8, $f24
/* 0CAA4C 7F095F1C 46002180 */  add.s $f6, $f4, $f0
/* 0CAA50 7F095F20 E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CAA54 7F095F24 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAA58 7F095F28 E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CAA5C 7F095F2C 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CAA60 7F095F30 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAA64 7F095F34 8FA50588 */   lw    $a1, 0x588($sp)
/* 0CAA68 7F095F38 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CAA6C 7F095F3C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAA70 7F095F40 8FA50584 */   lw    $a1, 0x584($sp)
/* 0CAA74 7F095F44 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CAA78 7F095F48 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAA7C 7F095F4C 8FA50580 */   lw    $a1, 0x580($sp)
/* 0CAA80 7F095F50 100003B6 */  b     .L7F096E2C
/* 0CAA84 7F095F54 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F095F58:
/* 0CAA88 7F095F58 C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CAA8C 7F095F5C C7A60648 */  lwc1  $f6, 0x648($sp)
/* 0CAA90 7F095F60 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CAA94 7F095F64 46181102 */  mul.s $f4, $f2, $f24
/* 0CAA98 7F095F68 C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CAA9C 7F095F6C C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CAAA0 7F095F70 46183202 */  mul.s $f8, $f6, $f24
/* 0CAAA4 7F095F74 C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CAAA8 7F095F78 C7B205FC */  lwc1  $f18, 0x5fc($sp)
/* 0CAAAC 7F095F7C 46186282 */  mul.s $f10, $f12, $f24
/* 0CAAB0 7F095F80 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CAAB4 7F095F84 C7B40604 */  lwc1  $f20, 0x604($sp)
/* 0CAAB8 7F095F88 46187102 */  mul.s $f4, $f14, $f24
/* 0CAABC 7F095F8C E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CAAC0 7F095F90 C7B605F0 */  lwc1  $f22, 0x5f0($sp)
/* 0CAAC4 7F095F94 46183202 */  mul.s $f8, $f6, $f24
/* 0CAAC8 7F095F98 E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAACC 7F095F9C C7A60600 */  lwc1  $f6, 0x600($sp)
/* 0CAAD0 7F095FA0 46188282 */  mul.s $f10, $f16, $f24
/* 0CAAD4 7F095FA4 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAAD8 7F095FA8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAADC 7F095FAC 46189102 */  mul.s $f4, $f18, $f24
/* 0CAAE0 7F095FB0 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAAE4 7F095FB4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAAE8 7F095FB8 46183202 */  mul.s $f8, $f6, $f24
/* 0CAAEC 7F095FBC E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAAF0 7F095FC0 C7A605F4 */  lwc1  $f6, 0x5f4($sp)
/* 0CAAF4 7F095FC4 4618A282 */  mul.s $f10, $f20, $f24
/* 0CAAF8 7F095FC8 E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAAFC 7F095FCC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAB00 7F095FD0 4618B102 */  mul.s $f4, $f22, $f24
/* 0CAB04 7F095FD4 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAB08 7F095FD8 24110004 */  li    $s1, 4
/* 0CAB0C 7F095FDC 46183202 */  mul.s $f8, $f6, $f24
/* 0CAB10 7F095FE0 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CAB14 7F095FE4 C7AA05F8 */  lwc1  $f10, 0x5f8($sp)
/* 0CAB18 7F095FE8 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAB1C 7F095FEC E7A404FC */  swc1  $f4, 0x4fc($sp)
/* 0CAB20 7F095FF0 46185102 */  mul.s $f4, $f10, $f24
/* 0CAB24 7F095FF4 8FA5058C */  lw    $a1, 0x58c($sp)
/* 0CAB28 7F095FF8 E7A80500 */  swc1  $f8, 0x500($sp)
/* 0CAB2C 7F095FFC 461C1182 */  mul.s $f6, $f2, $f28
/* 0CAB30 7F096000 00000000 */  nop
/* 0CAB34 7F096004 461C6202 */  mul.s $f8, $f12, $f28
/* 0CAB38 7F096008 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CAB3C 7F09600C 461C7102 */  mul.s $f4, $f14, $f28
/* 0CAB40 7F096010 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CAB44 7F096014 461C8182 */  mul.s $f6, $f16, $f28
/* 0CAB48 7F096018 46004280 */  add.s $f10, $f8, $f0
/* 0CAB4C 7F09601C E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CAB50 7F096020 E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CAB54 7F096024 461C9282 */  mul.s $f10, $f18, $f28
/* 0CAB58 7F096028 46003200 */  add.s $f8, $f6, $f0
/* 0CAB5C 7F09602C 461CA102 */  mul.s $f4, $f20, $f28
/* 0CAB60 7F096030 E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CAB64 7F096034 461CB202 */  mul.s $f8, $f22, $f28
/* 0CAB68 7F096038 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CAB6C 7F09603C C7AA05F8 */  lwc1  $f10, 0x5f8($sp)
/* 0CAB70 7F096040 46002180 */  add.s $f6, $f4, $f0
/* 0CAB74 7F096044 461C5102 */  mul.s $f4, $f10, $f28
/* 0CAB78 7F096048 E7A80508 */  swc1  $f8, 0x508($sp)
/* 0CAB7C 7F09604C 44814000 */  mtc1  $at, $f8
/* 0CAB80 7F096050 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 0CAB84 7F096054 46184283 */  div.s $f10, $f8, $f24
/* 0CAB88 7F096058 46002180 */  add.s $f6, $f4, $f0
/* 0CAB8C 7F09605C E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CAB90 7F096060 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAB94 7F096064 E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CAB98 7F096068 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CAB9C 7F09606C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CABA0 7F096070 8FA50588 */   lw    $a1, 0x588($sp)
/* 0CABA4 7F096074 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CABA8 7F096078 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CABAC 7F09607C 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CABB0 7F096080 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CABB4 7F096084 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CABB8 7F096088 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CABBC 7F09608C 10000367 */  b     .L7F096E2C
/* 0CABC0 7F096090 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096094:
/* 0CABC4 7F096094 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CABC8 7F096098 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CABCC 7F09609C C7A20628 */  lwc1  $f2, 0x628($sp)
/* 0CABD0 7F0960A0 4618B102 */  mul.s $f4, $f22, $f24
/* 0CABD4 7F0960A4 C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CABD8 7F0960A8 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CABDC 7F0960AC 46183202 */  mul.s $f8, $f6, $f24
/* 0CABE0 7F0960B0 C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CABE4 7F0960B4 C7B005F0 */  lwc1  $f16, 0x5f0($sp)
/* 0CABE8 7F0960B8 46181282 */  mul.s $f10, $f2, $f24
/* 0CABEC 7F0960BC E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CABF0 7F0960C0 C7AC05FC */  lwc1  $f12, 0x5fc($sp)
/* 0CABF4 7F0960C4 46189102 */  mul.s $f4, $f18, $f24
/* 0CABF8 7F0960C8 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CABFC 7F0960CC C7AE0604 */  lwc1  $f14, 0x604($sp)
/* 0CAC00 7F0960D0 46183202 */  mul.s $f8, $f6, $f24
/* 0CAC04 7F0960D4 E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAC08 7F0960D8 C7A605F4 */  lwc1  $f6, 0x5f4($sp)
/* 0CAC0C 7F0960DC 4618A282 */  mul.s $f10, $f20, $f24
/* 0CAC10 7F0960E0 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAC14 7F0960E4 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAC18 7F0960E8 46188102 */  mul.s $f4, $f16, $f24
/* 0CAC1C 7F0960EC E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAC20 7F0960F0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAC24 7F0960F4 46183202 */  mul.s $f8, $f6, $f24
/* 0CAC28 7F0960F8 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAC2C 7F0960FC C7AA05F8 */  lwc1  $f10, 0x5f8($sp)
/* 0CAC30 7F096100 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAC34 7F096104 E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAC38 7F096108 46185102 */  mul.s $f4, $f10, $f24
/* 0CAC3C 7F09610C 24110004 */  li    $s1, 4
/* 0CAC40 7F096110 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAC44 7F096114 46186182 */  mul.s $f6, $f12, $f24
/* 0CAC48 7F096118 C7A80600 */  lwc1  $f8, 0x600($sp)
/* 0CAC4C 7F09611C 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAC50 7F096120 8FA50580 */  lw    $a1, 0x580($sp)
/* 0CAC54 7F096124 46184282 */  mul.s $f10, $f8, $f24
/* 0CAC58 7F096128 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CAC5C 7F09612C 46187102 */  mul.s $f4, $f14, $f24
/* 0CAC60 7F096130 E7A604FC */  swc1  $f6, 0x4fc($sp)
/* 0CAC64 7F096134 461CB182 */  mul.s $f6, $f22, $f28
/* 0CAC68 7F096138 E7AA0500 */  swc1  $f10, 0x500($sp)
/* 0CAC6C 7F09613C 461C1202 */  mul.s $f8, $f2, $f28
/* 0CAC70 7F096140 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CAC74 7F096144 461C9102 */  mul.s $f4, $f18, $f28
/* 0CAC78 7F096148 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CAC7C 7F09614C 461CA182 */  mul.s $f6, $f20, $f28
/* 0CAC80 7F096150 46004280 */  add.s $f10, $f8, $f0
/* 0CAC84 7F096154 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CAC88 7F096158 C7A405F8 */  lwc1  $f4, 0x5f8($sp)
/* 0CAC8C 7F09615C E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CAC90 7F096160 461C8282 */  mul.s $f10, $f16, $f28
/* 0CAC94 7F096164 46003200 */  add.s $f8, $f6, $f0
/* 0CAC98 7F096168 461C2182 */  mul.s $f6, $f4, $f28
/* 0CAC9C 7F09616C E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CACA0 7F096170 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CACA4 7F096174 461C6282 */  mul.s $f10, $f12, $f28
/* 0CACA8 7F096178 46003200 */  add.s $f8, $f6, $f0
/* 0CACAC 7F09617C 461C7102 */  mul.s $f4, $f14, $f28
/* 0CACB0 7F096180 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CACB4 7F096184 44814000 */  mtc1  $at, $f8
/* 0CACB8 7F096188 E7AA0508 */  swc1  $f10, 0x508($sp)
/* 0CACBC 7F09618C 46184283 */  div.s $f10, $f8, $f24
/* 0CACC0 7F096190 46002180 */  add.s $f6, $f4, $f0
/* 0CACC4 7F096194 E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CACC8 7F096198 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CACCC 7F09619C E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CACD0 7F0961A0 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CACD4 7F0961A4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CACD8 7F0961A8 8FA50584 */   lw    $a1, 0x584($sp)
/* 0CACDC 7F0961AC 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CACE0 7F0961B0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CACE4 7F0961B4 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CACE8 7F0961B8 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CACEC 7F0961BC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CACF0 7F0961C0 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CACF4 7F0961C4 10000319 */  b     .L7F096E2C
/* 0CACF8 7F0961C8 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F0961CC:
/* 0CACFC 7F0961CC C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CAD00 7F0961D0 C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CAD04 7F0961D4 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CAD08 7F0961D8 46187102 */  mul.s $f4, $f14, $f24
/* 0CAD0C 7F0961DC C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CAD10 7F0961E0 C7A20628 */  lwc1  $f2, 0x628($sp)
/* 0CAD14 7F0961E4 46183202 */  mul.s $f8, $f6, $f24
/* 0CAD18 7F0961E8 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CAD1C 7F0961EC C7B40614 */  lwc1  $f20, 0x614($sp)
/* 0CAD20 7F0961F0 46188282 */  mul.s $f10, $f16, $f24
/* 0CAD24 7F0961F4 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CAD28 7F0961F8 C7AC0608 */  lwc1  $f12, 0x608($sp)
/* 0CAD2C 7F0961FC 4618B102 */  mul.s $f4, $f22, $f24
/* 0CAD30 7F096200 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CAD34 7F096204 C7B20610 */  lwc1  $f18, 0x610($sp)
/* 0CAD38 7F096208 46183202 */  mul.s $f8, $f6, $f24
/* 0CAD3C 7F09620C E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAD40 7F096210 C7A60618 */  lwc1  $f6, 0x618($sp)
/* 0CAD44 7F096214 46181282 */  mul.s $f10, $f2, $f24
/* 0CAD48 7F096218 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAD4C 7F09621C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAD50 7F096220 4618A102 */  mul.s $f4, $f20, $f24
/* 0CAD54 7F096224 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAD58 7F096228 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAD5C 7F09622C 46183202 */  mul.s $f8, $f6, $f24
/* 0CAD60 7F096230 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAD64 7F096234 C7AA061C */  lwc1  $f10, 0x61c($sp)
/* 0CAD68 7F096238 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAD6C 7F09623C E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAD70 7F096240 46185102 */  mul.s $f4, $f10, $f24
/* 0CAD74 7F096244 24110004 */  li    $s1, 4
/* 0CAD78 7F096248 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAD7C 7F09624C 46186182 */  mul.s $f6, $f12, $f24
/* 0CAD80 7F096250 C7A8060C */  lwc1  $f8, 0x60c($sp)
/* 0CAD84 7F096254 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAD88 7F096258 8FA50588 */  lw    $a1, 0x588($sp)
/* 0CAD8C 7F09625C 46184282 */  mul.s $f10, $f8, $f24
/* 0CAD90 7F096260 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CAD94 7F096264 46189102 */  mul.s $f4, $f18, $f24
/* 0CAD98 7F096268 E7A604FC */  swc1  $f6, 0x4fc($sp)
/* 0CAD9C 7F09626C 461C7182 */  mul.s $f6, $f14, $f28
/* 0CADA0 7F096270 E7AA0500 */  swc1  $f10, 0x500($sp)
/* 0CADA4 7F096274 461C8202 */  mul.s $f8, $f16, $f28
/* 0CADA8 7F096278 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CADAC 7F09627C 461CB102 */  mul.s $f4, $f22, $f28
/* 0CADB0 7F096280 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CADB4 7F096284 461C1182 */  mul.s $f6, $f2, $f28
/* 0CADB8 7F096288 46004280 */  add.s $f10, $f8, $f0
/* 0CADBC 7F09628C E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CADC0 7F096290 C7A4061C */  lwc1  $f4, 0x61c($sp)
/* 0CADC4 7F096294 E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CADC8 7F096298 461CA282 */  mul.s $f10, $f20, $f28
/* 0CADCC 7F09629C 46003200 */  add.s $f8, $f6, $f0
/* 0CADD0 7F0962A0 461C2182 */  mul.s $f6, $f4, $f28
/* 0CADD4 7F0962A4 E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CADD8 7F0962A8 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CADDC 7F0962AC 461C6282 */  mul.s $f10, $f12, $f28
/* 0CADE0 7F0962B0 46003200 */  add.s $f8, $f6, $f0
/* 0CADE4 7F0962B4 461C9102 */  mul.s $f4, $f18, $f28
/* 0CADE8 7F0962B8 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CADEC 7F0962BC 44814000 */  mtc1  $at, $f8
/* 0CADF0 7F0962C0 E7AA0508 */  swc1  $f10, 0x508($sp)
/* 0CADF4 7F0962C4 46184283 */  div.s $f10, $f8, $f24
/* 0CADF8 7F0962C8 46002180 */  add.s $f6, $f4, $f0
/* 0CADFC 7F0962CC E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CAE00 7F0962D0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAE04 7F0962D4 E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CAE08 7F0962D8 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CAE0C 7F0962DC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAE10 7F0962E0 8FA50580 */   lw    $a1, 0x580($sp)
/* 0CAE14 7F0962E4 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CAE18 7F0962E8 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAE1C 7F0962EC 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CAE20 7F0962F0 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CAE24 7F0962F4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAE28 7F0962F8 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CAE2C 7F0962FC 100002CB */  b     .L7F096E2C
/* 0CAE30 7F096300 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096304:
/* 0CAE34 7F096304 C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CAE38 7F096308 C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CAE3C 7F09630C C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CAE40 7F096310 46189102 */  mul.s $f4, $f18, $f24
/* 0CAE44 7F096314 C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CAE48 7F096318 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CAE4C 7F09631C 46183202 */  mul.s $f8, $f6, $f24
/* 0CAE50 7F096320 C7A60648 */  lwc1  $f6, 0x648($sp)
/* 0CAE54 7F096324 C7B60608 */  lwc1  $f22, 0x608($sp)
/* 0CAE58 7F096328 4618A282 */  mul.s $f10, $f20, $f24
/* 0CAE5C 7F09632C E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CAE60 7F096330 C7AE0614 */  lwc1  $f14, 0x614($sp)
/* 0CAE64 7F096334 46181102 */  mul.s $f4, $f2, $f24
/* 0CAE68 7F096338 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CAE6C 7F09633C C7B0061C */  lwc1  $f16, 0x61c($sp)
/* 0CAE70 7F096340 46183202 */  mul.s $f8, $f6, $f24
/* 0CAE74 7F096344 E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAE78 7F096348 C7A6060C */  lwc1  $f6, 0x60c($sp)
/* 0CAE7C 7F09634C 46186282 */  mul.s $f10, $f12, $f24
/* 0CAE80 7F096350 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAE84 7F096354 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAE88 7F096358 4618B102 */  mul.s $f4, $f22, $f24
/* 0CAE8C 7F09635C E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAE90 7F096360 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAE94 7F096364 46183202 */  mul.s $f8, $f6, $f24
/* 0CAE98 7F096368 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAE9C 7F09636C C7AA0610 */  lwc1  $f10, 0x610($sp)
/* 0CAEA0 7F096370 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAEA4 7F096374 E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAEA8 7F096378 46185102 */  mul.s $f4, $f10, $f24
/* 0CAEAC 7F09637C 24110004 */  li    $s1, 4
/* 0CAEB0 7F096380 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAEB4 7F096384 46187182 */  mul.s $f6, $f14, $f24
/* 0CAEB8 7F096388 C7A80618 */  lwc1  $f8, 0x618($sp)
/* 0CAEBC 7F09638C 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAEC0 7F096390 8FA50584 */  lw    $a1, 0x584($sp)
/* 0CAEC4 7F096394 46184282 */  mul.s $f10, $f8, $f24
/* 0CAEC8 7F096398 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CAECC 7F09639C 46188102 */  mul.s $f4, $f16, $f24
/* 0CAED0 7F0963A0 E7A604FC */  swc1  $f6, 0x4fc($sp)
/* 0CAED4 7F0963A4 461C9182 */  mul.s $f6, $f18, $f28
/* 0CAED8 7F0963A8 E7AA0500 */  swc1  $f10, 0x500($sp)
/* 0CAEDC 7F0963AC 461CA202 */  mul.s $f8, $f20, $f28
/* 0CAEE0 7F0963B0 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CAEE4 7F0963B4 461C1102 */  mul.s $f4, $f2, $f28
/* 0CAEE8 7F0963B8 E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CAEEC 7F0963BC 461C6182 */  mul.s $f6, $f12, $f28
/* 0CAEF0 7F0963C0 46004280 */  add.s $f10, $f8, $f0
/* 0CAEF4 7F0963C4 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CAEF8 7F0963C8 C7A40610 */  lwc1  $f4, 0x610($sp)
/* 0CAEFC 7F0963CC E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CAF00 7F0963D0 461CB282 */  mul.s $f10, $f22, $f28
/* 0CAF04 7F0963D4 46003200 */  add.s $f8, $f6, $f0
/* 0CAF08 7F0963D8 461C2182 */  mul.s $f6, $f4, $f28
/* 0CAF0C 7F0963DC E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CAF10 7F0963E0 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CAF14 7F0963E4 461C7282 */  mul.s $f10, $f14, $f28
/* 0CAF18 7F0963E8 46003200 */  add.s $f8, $f6, $f0
/* 0CAF1C 7F0963EC 461C8102 */  mul.s $f4, $f16, $f28
/* 0CAF20 7F0963F0 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CAF24 7F0963F4 44814000 */  mtc1  $at, $f8
/* 0CAF28 7F0963F8 E7AA0508 */  swc1  $f10, 0x508($sp)
/* 0CAF2C 7F0963FC 46184283 */  div.s $f10, $f8, $f24
/* 0CAF30 7F096400 46002180 */  add.s $f6, $f4, $f0
/* 0CAF34 7F096404 E7A6050C */  swc1  $f6, 0x50c($sp)
/* 0CAF38 7F096408 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAF3C 7F09640C E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CAF40 7F096410 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CAF44 7F096414 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAF48 7F096418 8FA5058C */   lw    $a1, 0x58c($sp)
/* 0CAF4C 7F09641C 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CAF50 7F096420 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAF54 7F096424 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CAF58 7F096428 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CAF5C 7F09642C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CAF60 7F096430 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CAF64 7F096434 1000027D */  b     .L7F096E2C
/* 0CAF68 7F096438 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F09643C:
/* 0CAF6C 7F09643C C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CAF70 7F096440 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CAF74 7F096444 C7A20628 */  lwc1  $f2, 0x628($sp)
/* 0CAF78 7F096448 4618B102 */  mul.s $f4, $f22, $f24
/* 0CAF7C 7F09644C C7AE0608 */  lwc1  $f14, 0x608($sp)
/* 0CAF80 7F096450 C7B20610 */  lwc1  $f18, 0x610($sp)
/* 0CAF84 7F096454 46183202 */  mul.s $f8, $f6, $f24
/* 0CAF88 7F096458 C7A6060C */  lwc1  $f6, 0x60c($sp)
/* 0CAF8C 7F09645C C7B005F0 */  lwc1  $f16, 0x5f0($sp)
/* 0CAF90 7F096460 46181282 */  mul.s $f10, $f2, $f24
/* 0CAF94 7F096464 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CAF98 7F096468 C7AC05F8 */  lwc1  $f12, 0x5f8($sp)
/* 0CAF9C 7F09646C 46187102 */  mul.s $f4, $f14, $f24
/* 0CAFA0 7F096470 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CAFA4 7F096474 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CAFA8 7F096478 46183202 */  mul.s $f8, $f6, $f24
/* 0CAFAC 7F09647C E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CAFB0 7F096480 C7A605F4 */  lwc1  $f6, 0x5f4($sp)
/* 0CAFB4 7F096484 46189282 */  mul.s $f10, $f18, $f24
/* 0CAFB8 7F096488 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CAFBC 7F09648C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CAFC0 7F096490 46188102 */  mul.s $f4, $f16, $f24
/* 0CAFC4 7F096494 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CAFC8 7F096498 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CAFCC 7F09649C 46183202 */  mul.s $f8, $f6, $f24
/* 0CAFD0 7F0964A0 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CAFD4 7F0964A4 24110003 */  li    $s1, 3
/* 0CAFD8 7F0964A8 46186282 */  mul.s $f10, $f12, $f24
/* 0CAFDC 7F0964AC E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CAFE0 7F0964B0 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CAFE4 7F0964B4 461CB102 */  mul.s $f4, $f22, $f28
/* 0CAFE8 7F0964B8 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CAFEC 7F0964BC 8FA50580 */  lw    $a1, 0x580($sp)
/* 0CAFF0 7F0964C0 461C1182 */  mul.s $f6, $f2, $f28
/* 0CAFF4 7F0964C4 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CAFF8 7F0964C8 461C7282 */  mul.s $f10, $f14, $f28
/* 0CAFFC 7F0964CC E7A404C0 */  swc1  $f4, 0x4c0($sp)
/* 0CB000 7F0964D0 461C9102 */  mul.s $f4, $f18, $f28
/* 0CB004 7F0964D4 46003200 */  add.s $f8, $f6, $f0
/* 0CB008 7F0964D8 E7AA04D8 */  swc1  $f10, 0x4d8($sp)
/* 0CB00C 7F0964DC E7A804C4 */  swc1  $f8, 0x4c4($sp)
/* 0CB010 7F0964E0 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB014 7F0964E4 46002180 */  add.s $f6, $f4, $f0
/* 0CB018 7F0964E8 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB01C 7F0964EC E7A604DC */  swc1  $f6, 0x4dc($sp)
/* 0CB020 7F0964F0 44813000 */  mtc1  $at, $f6
/* 0CB024 7F0964F4 E7A804F0 */  swc1  $f8, 0x4f0($sp)
/* 0CB028 7F0964F8 46183203 */  div.s $f8, $f6, $f24
/* 0CB02C 7F0964FC 46005100 */  add.s $f4, $f10, $f0
/* 0CB030 7F096500 E7A404F4 */  swc1  $f4, 0x4f4($sp)
/* 0CB034 7F096504 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB038 7F096508 E7A80058 */   swc1  $f8, 0x58($sp)
/* 0CB03C 7F09650C 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB040 7F096510 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB044 7F096514 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CB048 7F096518 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB04C 7F09651C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB050 7F096520 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CB054 7F096524 10000241 */  b     .L7F096E2C
/* 0CB058 7F096528 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F09652C:
/* 0CB05C 7F09652C C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CB060 7F096530 C7A40630 */  lwc1  $f4, 0x630($sp)
/* 0CB064 7F096534 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CB068 7F096538 46189282 */  mul.s $f10, $f18, $f24
/* 0CB06C 7F09653C C7AC05FC */  lwc1  $f12, 0x5fc($sp)
/* 0CB070 7F096540 C7AE0604 */  lwc1  $f14, 0x604($sp)
/* 0CB074 7F096544 46182182 */  mul.s $f6, $f4, $f24
/* 0CB078 7F096548 C7A40600 */  lwc1  $f4, 0x600($sp)
/* 0CB07C 7F09654C C7A20608 */  lwc1  $f2, 0x608($sp)
/* 0CB080 7F096550 4618A202 */  mul.s $f8, $f20, $f24
/* 0CB084 7F096554 E7AA04B4 */  swc1  $f10, 0x4b4($sp)
/* 0CB088 7F096558 C7B00610 */  lwc1  $f16, 0x610($sp)
/* 0CB08C 7F09655C 46186282 */  mul.s $f10, $f12, $f24
/* 0CB090 7F096560 E7A604B8 */  swc1  $f6, 0x4b8($sp)
/* 0CB094 7F096564 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB098 7F096568 46182182 */  mul.s $f6, $f4, $f24
/* 0CB09C 7F09656C E7A804BC */  swc1  $f8, 0x4bc($sp)
/* 0CB0A0 7F096570 C7A4060C */  lwc1  $f4, 0x60c($sp)
/* 0CB0A4 7F096574 46187202 */  mul.s $f8, $f14, $f24
/* 0CB0A8 7F096578 E7AA04CC */  swc1  $f10, 0x4cc($sp)
/* 0CB0AC 7F09657C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB0B0 7F096580 46181282 */  mul.s $f10, $f2, $f24
/* 0CB0B4 7F096584 E7A604D0 */  swc1  $f6, 0x4d0($sp)
/* 0CB0B8 7F096588 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB0BC 7F09658C 46182182 */  mul.s $f6, $f4, $f24
/* 0CB0C0 7F096590 E7A804D4 */  swc1  $f8, 0x4d4($sp)
/* 0CB0C4 7F096594 24110003 */  li    $s1, 3
/* 0CB0C8 7F096598 46188202 */  mul.s $f8, $f16, $f24
/* 0CB0CC 7F09659C E7AA04E4 */  swc1  $f10, 0x4e4($sp)
/* 0CB0D0 7F0965A0 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB0D4 7F0965A4 461C9282 */  mul.s $f10, $f18, $f28
/* 0CB0D8 7F0965A8 E7A604E8 */  swc1  $f6, 0x4e8($sp)
/* 0CB0DC 7F0965AC 8FA50584 */  lw    $a1, 0x584($sp)
/* 0CB0E0 7F0965B0 461CA102 */  mul.s $f4, $f20, $f28
/* 0CB0E4 7F0965B4 E7A804EC */  swc1  $f8, 0x4ec($sp)
/* 0CB0E8 7F0965B8 461C6202 */  mul.s $f8, $f12, $f28
/* 0CB0EC 7F0965BC E7AA04C0 */  swc1  $f10, 0x4c0($sp)
/* 0CB0F0 7F0965C0 461C7282 */  mul.s $f10, $f14, $f28
/* 0CB0F4 7F0965C4 46002180 */  add.s $f6, $f4, $f0
/* 0CB0F8 7F0965C8 E7A804D8 */  swc1  $f8, 0x4d8($sp)
/* 0CB0FC 7F0965CC E7A604C4 */  swc1  $f6, 0x4c4($sp)
/* 0CB100 7F0965D0 461C1182 */  mul.s $f6, $f2, $f28
/* 0CB104 7F0965D4 46005100 */  add.s $f4, $f10, $f0
/* 0CB108 7F0965D8 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB10C 7F0965DC E7A404DC */  swc1  $f4, 0x4dc($sp)
/* 0CB110 7F0965E0 44812000 */  mtc1  $at, $f4
/* 0CB114 7F0965E4 E7A604F0 */  swc1  $f6, 0x4f0($sp)
/* 0CB118 7F0965E8 46182183 */  div.s $f6, $f4, $f24
/* 0CB11C 7F0965EC 46004280 */  add.s $f10, $f8, $f0
/* 0CB120 7F0965F0 E7AA04F4 */  swc1  $f10, 0x4f4($sp)
/* 0CB124 7F0965F4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB128 7F0965F8 E7A60058 */   swc1  $f6, 0x58($sp)
/* 0CB12C 7F0965FC 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB130 7F096600 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB134 7F096604 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CB138 7F096608 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB13C 7F09660C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB140 7F096610 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CB144 7F096614 10000205 */  b     .L7F096E2C
/* 0CB148 7F096618 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F09661C:
/* 0CB14C 7F09661C C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CB150 7F096620 C7AA063C */  lwc1  $f10, 0x63c($sp)
/* 0CB154 7F096624 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CB158 7F096628 46187202 */  mul.s $f8, $f14, $f24
/* 0CB15C 7F09662C C7A205F0 */  lwc1  $f2, 0x5f0($sp)
/* 0CB160 7F096630 C7AC05F8 */  lwc1  $f12, 0x5f8($sp)
/* 0CB164 7F096634 46185102 */  mul.s $f4, $f10, $f24
/* 0CB168 7F096638 C7AA05F4 */  lwc1  $f10, 0x5f4($sp)
/* 0CB16C 7F09663C C7B40614 */  lwc1  $f20, 0x614($sp)
/* 0CB170 7F096640 46188182 */  mul.s $f6, $f16, $f24
/* 0CB174 7F096644 E7A804B4 */  swc1  $f8, 0x4b4($sp)
/* 0CB178 7F096648 C7B2061C */  lwc1  $f18, 0x61c($sp)
/* 0CB17C 7F09664C 46181202 */  mul.s $f8, $f2, $f24
/* 0CB180 7F096650 E7A404B8 */  swc1  $f4, 0x4b8($sp)
/* 0CB184 7F096654 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB188 7F096658 46185102 */  mul.s $f4, $f10, $f24
/* 0CB18C 7F09665C E7A604BC */  swc1  $f6, 0x4bc($sp)
/* 0CB190 7F096660 C7AA0618 */  lwc1  $f10, 0x618($sp)
/* 0CB194 7F096664 46186182 */  mul.s $f6, $f12, $f24
/* 0CB198 7F096668 E7A804CC */  swc1  $f8, 0x4cc($sp)
/* 0CB19C 7F09666C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB1A0 7F096670 4618A202 */  mul.s $f8, $f20, $f24
/* 0CB1A4 7F096674 E7A404D0 */  swc1  $f4, 0x4d0($sp)
/* 0CB1A8 7F096678 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB1AC 7F09667C 46185102 */  mul.s $f4, $f10, $f24
/* 0CB1B0 7F096680 E7A604D4 */  swc1  $f6, 0x4d4($sp)
/* 0CB1B4 7F096684 24110003 */  li    $s1, 3
/* 0CB1B8 7F096688 46189182 */  mul.s $f6, $f18, $f24
/* 0CB1BC 7F09668C E7A804E4 */  swc1  $f8, 0x4e4($sp)
/* 0CB1C0 7F096690 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB1C4 7F096694 461C7202 */  mul.s $f8, $f14, $f28
/* 0CB1C8 7F096698 E7A404E8 */  swc1  $f4, 0x4e8($sp)
/* 0CB1CC 7F09669C 8FA50588 */  lw    $a1, 0x588($sp)
/* 0CB1D0 7F0966A0 461C8282 */  mul.s $f10, $f16, $f28
/* 0CB1D4 7F0966A4 E7A604EC */  swc1  $f6, 0x4ec($sp)
/* 0CB1D8 7F0966A8 461C1182 */  mul.s $f6, $f2, $f28
/* 0CB1DC 7F0966AC E7A804C0 */  swc1  $f8, 0x4c0($sp)
/* 0CB1E0 7F0966B0 461C6202 */  mul.s $f8, $f12, $f28
/* 0CB1E4 7F0966B4 46005100 */  add.s $f4, $f10, $f0
/* 0CB1E8 7F0966B8 E7A604D8 */  swc1  $f6, 0x4d8($sp)
/* 0CB1EC 7F0966BC E7A404C4 */  swc1  $f4, 0x4c4($sp)
/* 0CB1F0 7F0966C0 461CA102 */  mul.s $f4, $f20, $f28
/* 0CB1F4 7F0966C4 46004280 */  add.s $f10, $f8, $f0
/* 0CB1F8 7F0966C8 461C9182 */  mul.s $f6, $f18, $f28
/* 0CB1FC 7F0966CC E7AA04DC */  swc1  $f10, 0x4dc($sp)
/* 0CB200 7F0966D0 44815000 */  mtc1  $at, $f10
/* 0CB204 7F0966D4 E7A404F0 */  swc1  $f4, 0x4f0($sp)
/* 0CB208 7F0966D8 46185103 */  div.s $f4, $f10, $f24
/* 0CB20C 7F0966DC 46003200 */  add.s $f8, $f6, $f0
/* 0CB210 7F0966E0 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CB214 7F0966E4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB218 7F0966E8 E7A40058 */   swc1  $f4, 0x58($sp)
/* 0CB21C 7F0966EC 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB220 7F0966F0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB224 7F0966F4 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CB228 7F0966F8 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB22C 7F0966FC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB230 7F096700 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CB234 7F096704 100001C9 */  b     .L7F096E2C
/* 0CB238 7F096708 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F09670C:
/* 0CB23C 7F09670C C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CB240 7F096710 C7A80648 */  lwc1  $f8, 0x648($sp)
/* 0CB244 7F096714 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CB248 7F096718 46181182 */  mul.s $f6, $f2, $f24
/* 0CB24C 7F09671C C7B20614 */  lwc1  $f18, 0x614($sp)
/* 0CB250 7F096720 C7B4061C */  lwc1  $f20, 0x61c($sp)
/* 0CB254 7F096724 46184282 */  mul.s $f10, $f8, $f24
/* 0CB258 7F096728 C7A80618 */  lwc1  $f8, 0x618($sp)
/* 0CB25C 7F09672C C7AE05FC */  lwc1  $f14, 0x5fc($sp)
/* 0CB260 7F096730 46186102 */  mul.s $f4, $f12, $f24
/* 0CB264 7F096734 E7A604B4 */  swc1  $f6, 0x4b4($sp)
/* 0CB268 7F096738 C7B00604 */  lwc1  $f16, 0x604($sp)
/* 0CB26C 7F09673C 46189182 */  mul.s $f6, $f18, $f24
/* 0CB270 7F096740 E7AA04B8 */  swc1  $f10, 0x4b8($sp)
/* 0CB274 7F096744 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB278 7F096748 46184282 */  mul.s $f10, $f8, $f24
/* 0CB27C 7F09674C E7A404BC */  swc1  $f4, 0x4bc($sp)
/* 0CB280 7F096750 C7A80600 */  lwc1  $f8, 0x600($sp)
/* 0CB284 7F096754 4618A102 */  mul.s $f4, $f20, $f24
/* 0CB288 7F096758 E7A604CC */  swc1  $f6, 0x4cc($sp)
/* 0CB28C 7F09675C C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB290 7F096760 46187182 */  mul.s $f6, $f14, $f24
/* 0CB294 7F096764 E7AA04D0 */  swc1  $f10, 0x4d0($sp)
/* 0CB298 7F096768 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB29C 7F09676C 46184282 */  mul.s $f10, $f8, $f24
/* 0CB2A0 7F096770 E7A404D4 */  swc1  $f4, 0x4d4($sp)
/* 0CB2A4 7F096774 24110003 */  li    $s1, 3
/* 0CB2A8 7F096778 46188102 */  mul.s $f4, $f16, $f24
/* 0CB2AC 7F09677C E7A604E4 */  swc1  $f6, 0x4e4($sp)
/* 0CB2B0 7F096780 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB2B4 7F096784 461C1182 */  mul.s $f6, $f2, $f28
/* 0CB2B8 7F096788 E7AA04E8 */  swc1  $f10, 0x4e8($sp)
/* 0CB2BC 7F09678C 8FA5058C */  lw    $a1, 0x58c($sp)
/* 0CB2C0 7F096790 461C6202 */  mul.s $f8, $f12, $f28
/* 0CB2C4 7F096794 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CB2C8 7F096798 461C9102 */  mul.s $f4, $f18, $f28
/* 0CB2CC 7F09679C E7A604C0 */  swc1  $f6, 0x4c0($sp)
/* 0CB2D0 7F0967A0 461CA182 */  mul.s $f6, $f20, $f28
/* 0CB2D4 7F0967A4 46004280 */  add.s $f10, $f8, $f0
/* 0CB2D8 7F0967A8 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CB2DC 7F0967AC E7AA04C4 */  swc1  $f10, 0x4c4($sp)
/* 0CB2E0 7F0967B0 461C7282 */  mul.s $f10, $f14, $f28
/* 0CB2E4 7F0967B4 46003200 */  add.s $f8, $f6, $f0
/* 0CB2E8 7F0967B8 461C8102 */  mul.s $f4, $f16, $f28
/* 0CB2EC 7F0967BC E7A804DC */  swc1  $f8, 0x4dc($sp)
/* 0CB2F0 7F0967C0 44814000 */  mtc1  $at, $f8
/* 0CB2F4 7F0967C4 E7AA04F0 */  swc1  $f10, 0x4f0($sp)
/* 0CB2F8 7F0967C8 46184283 */  div.s $f10, $f8, $f24
/* 0CB2FC 7F0967CC 46002180 */  add.s $f6, $f4, $f0
/* 0CB300 7F0967D0 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 0CB304 7F0967D4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB308 7F0967D8 E7AA0058 */   swc1  $f10, 0x58($sp)
/* 0CB30C 7F0967DC 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB310 7F0967E0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB314 7F0967E4 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CB318 7F0967E8 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB31C 7F0967EC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB320 7F0967F0 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CB324 7F0967F4 1000018D */  b     .L7F096E2C
/* 0CB328 7F0967F8 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F0967FC:
/* 0CB32C 7F0967FC C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CB330 7F096800 C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CB334 7F096804 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CB338 7F096808 46189102 */  mul.s $f4, $f18, $f24
/* 0CB33C 7F09680C C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CB340 7F096810 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CB344 7F096814 46183202 */  mul.s $f8, $f6, $f24
/* 0CB348 7F096818 C7A60648 */  lwc1  $f6, 0x648($sp)
/* 0CB34C 7F09681C C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CB350 7F096820 4618A282 */  mul.s $f10, $f20, $f24
/* 0CB354 7F096824 E7A404B4 */  swc1  $f4, 0x4b4($sp)
/* 0CB358 7F096828 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CB35C 7F09682C 46181102 */  mul.s $f4, $f2, $f24
/* 0CB360 7F096830 E7A804B8 */  swc1  $f8, 0x4b8($sp)
/* 0CB364 7F096834 C7B605F0 */  lwc1  $f22, 0x5f0($sp)
/* 0CB368 7F096838 46183202 */  mul.s $f8, $f6, $f24
/* 0CB36C 7F09683C E7AA04BC */  swc1  $f10, 0x4bc($sp)
/* 0CB370 7F096840 C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CB374 7F096844 46186282 */  mul.s $f10, $f12, $f24
/* 0CB378 7F096848 E7A404CC */  swc1  $f4, 0x4cc($sp)
/* 0CB37C 7F09684C 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB380 7F096850 46187102 */  mul.s $f4, $f14, $f24
/* 0CB384 7F096854 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CB388 7F096858 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB38C 7F09685C 46183202 */  mul.s $f8, $f6, $f24
/* 0CB390 7F096860 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CB394 7F096864 C7A605F4 */  lwc1  $f6, 0x5f4($sp)
/* 0CB398 7F096868 46188282 */  mul.s $f10, $f16, $f24
/* 0CB39C 7F09686C E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CB3A0 7F096870 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB3A4 7F096874 4618B102 */  mul.s $f4, $f22, $f24
/* 0CB3A8 7F096878 E7A804E8 */  swc1  $f8, 0x4e8($sp)
/* 0CB3AC 7F09687C 24110005 */  li    $s1, 5
/* 0CB3B0 7F096880 46183202 */  mul.s $f8, $f6, $f24
/* 0CB3B4 7F096884 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CB3B8 7F096888 C7AA05F8 */  lwc1  $f10, 0x5f8($sp)
/* 0CB3BC 7F09688C C7A60608 */  lwc1  $f6, 0x608($sp)
/* 0CB3C0 7F096890 E7A404FC */  swc1  $f4, 0x4fc($sp)
/* 0CB3C4 7F096894 46185102 */  mul.s $f4, $f10, $f24
/* 0CB3C8 7F096898 C7AA060C */  lwc1  $f10, 0x60c($sp)
/* 0CB3CC 7F09689C E7A80500 */  swc1  $f8, 0x500($sp)
/* 0CB3D0 7F0968A0 46183202 */  mul.s $f8, $f6, $f24
/* 0CB3D4 7F0968A4 C7A60610 */  lwc1  $f6, 0x610($sp)
/* 0CB3D8 7F0968A8 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB3DC 7F0968AC 8FA50584 */  lw    $a1, 0x584($sp)
/* 0CB3E0 7F0968B0 E7A40504 */  swc1  $f4, 0x504($sp)
/* 0CB3E4 7F0968B4 46185102 */  mul.s $f4, $f10, $f24
/* 0CB3E8 7F0968B8 E7A80514 */  swc1  $f8, 0x514($sp)
/* 0CB3EC 7F0968BC 46183202 */  mul.s $f8, $f6, $f24
/* 0CB3F0 7F0968C0 00000000 */  nop
/* 0CB3F4 7F0968C4 461C9282 */  mul.s $f10, $f18, $f28
/* 0CB3F8 7F0968C8 E7A40518 */  swc1  $f4, 0x518($sp)
/* 0CB3FC 7F0968CC 461CA102 */  mul.s $f4, $f20, $f28
/* 0CB400 7F0968D0 E7A8051C */  swc1  $f8, 0x51c($sp)
/* 0CB404 7F0968D4 461C1202 */  mul.s $f8, $f2, $f28
/* 0CB408 7F0968D8 E7AA04C0 */  swc1  $f10, 0x4c0($sp)
/* 0CB40C 7F0968DC 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB410 7F0968E0 46002180 */  add.s $f6, $f4, $f0
/* 0CB414 7F0968E4 E7A804D8 */  swc1  $f8, 0x4d8($sp)
/* 0CB418 7F0968E8 E7A604C4 */  swc1  $f6, 0x4c4($sp)
/* 0CB41C 7F0968EC 461C7182 */  mul.s $f6, $f14, $f28
/* 0CB420 7F0968F0 46005100 */  add.s $f4, $f10, $f0
/* 0CB424 7F0968F4 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB428 7F0968F8 E7A404DC */  swc1  $f4, 0x4dc($sp)
/* 0CB42C 7F0968FC 461CB102 */  mul.s $f4, $f22, $f28
/* 0CB430 7F096900 E7A604F0 */  swc1  $f6, 0x4f0($sp)
/* 0CB434 7F096904 C7A605F8 */  lwc1  $f6, 0x5f8($sp)
/* 0CB438 7F096908 46004280 */  add.s $f10, $f8, $f0
/* 0CB43C 7F09690C 461C3202 */  mul.s $f8, $f6, $f28
/* 0CB440 7F096910 E7A40508 */  swc1  $f4, 0x508($sp)
/* 0CB444 7F096914 C7A40608 */  lwc1  $f4, 0x608($sp)
/* 0CB448 7F096918 E7AA04F4 */  swc1  $f10, 0x4f4($sp)
/* 0CB44C 7F09691C 461C2182 */  mul.s $f6, $f4, $f28
/* 0CB450 7F096920 46004280 */  add.s $f10, $f8, $f0
/* 0CB454 7F096924 C7A80610 */  lwc1  $f8, 0x610($sp)
/* 0CB458 7F096928 E7AA050C */  swc1  $f10, 0x50c($sp)
/* 0CB45C 7F09692C E7A60520 */  swc1  $f6, 0x520($sp)
/* 0CB460 7F096930 44813000 */  mtc1  $at, $f6
/* 0CB464 7F096934 461C4282 */  mul.s $f10, $f8, $f28
/* 0CB468 7F096938 46183203 */  div.s $f8, $f6, $f24
/* 0CB46C 7F09693C 46005100 */  add.s $f4, $f10, $f0
/* 0CB470 7F096940 E7A40524 */  swc1  $f4, 0x524($sp)
/* 0CB474 7F096944 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB478 7F096948 E7A80058 */   swc1  $f8, 0x58($sp)
/* 0CB47C 7F09694C 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB480 7F096950 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB484 7F096954 8FA5058C */   lw    $a1, 0x58c($sp)
/* 0CB488 7F096958 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB48C 7F09695C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB490 7F096960 8FA50588 */   lw    $a1, 0x588($sp)
/* 0CB494 7F096964 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CB498 7F096968 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB49C 7F09696C 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CB4A0 7F096970 27A40514 */  addiu $a0, $sp, 0x514
/* 0CB4A4 7F096974 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB4A8 7F096978 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CB4AC 7F09697C 1000012B */  b     .L7F096E2C
/* 0CB4B0 7F096980 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096984:
/* 0CB4B4 7F096984 C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CB4B8 7F096988 C7A40648 */  lwc1  $f4, 0x648($sp)
/* 0CB4BC 7F09698C C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CB4C0 7F096990 46181282 */  mul.s $f10, $f2, $f24
/* 0CB4C4 7F096994 C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CB4C8 7F096998 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CB4CC 7F09699C 46182182 */  mul.s $f6, $f4, $f24
/* 0CB4D0 7F0969A0 C7A4063C */  lwc1  $f4, 0x63c($sp)
/* 0CB4D4 7F0969A4 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CB4D8 7F0969A8 46186202 */  mul.s $f8, $f12, $f24
/* 0CB4DC 7F0969AC E7AA04B4 */  swc1  $f10, 0x4b4($sp)
/* 0CB4E0 7F0969B0 C7B205FC */  lwc1  $f18, 0x5fc($sp)
/* 0CB4E4 7F0969B4 46187282 */  mul.s $f10, $f14, $f24
/* 0CB4E8 7F0969B8 E7A604B8 */  swc1  $f6, 0x4b8($sp)
/* 0CB4EC 7F0969BC C7B40604 */  lwc1  $f20, 0x604($sp)
/* 0CB4F0 7F0969C0 46182182 */  mul.s $f6, $f4, $f24
/* 0CB4F4 7F0969C4 E7A804BC */  swc1  $f8, 0x4bc($sp)
/* 0CB4F8 7F0969C8 C7A40624 */  lwc1  $f4, 0x624($sp)
/* 0CB4FC 7F0969CC 46188202 */  mul.s $f8, $f16, $f24
/* 0CB500 7F0969D0 E7AA04CC */  swc1  $f10, 0x4cc($sp)
/* 0CB504 7F0969D4 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB508 7F0969D8 4618B282 */  mul.s $f10, $f22, $f24
/* 0CB50C 7F0969DC E7A604D0 */  swc1  $f6, 0x4d0($sp)
/* 0CB510 7F0969E0 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB514 7F0969E4 46182182 */  mul.s $f6, $f4, $f24
/* 0CB518 7F0969E8 E7A804D4 */  swc1  $f8, 0x4d4($sp)
/* 0CB51C 7F0969EC C7A80628 */  lwc1  $f8, 0x628($sp)
/* 0CB520 7F0969F0 C7A40608 */  lwc1  $f4, 0x608($sp)
/* 0CB524 7F0969F4 E7AA04E4 */  swc1  $f10, 0x4e4($sp)
/* 0CB528 7F0969F8 46184282 */  mul.s $f10, $f8, $f24
/* 0CB52C 7F0969FC C7A8060C */  lwc1  $f8, 0x60c($sp)
/* 0CB530 7F096A00 E7A604E8 */  swc1  $f6, 0x4e8($sp)
/* 0CB534 7F096A04 46182182 */  mul.s $f6, $f4, $f24
/* 0CB538 7F096A08 C7A40610 */  lwc1  $f4, 0x610($sp)
/* 0CB53C 7F096A0C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB540 7F096A10 24110005 */  li    $s1, 5
/* 0CB544 7F096A14 E7AA04EC */  swc1  $f10, 0x4ec($sp)
/* 0CB548 7F096A18 46184282 */  mul.s $f10, $f8, $f24
/* 0CB54C 7F096A1C 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB550 7F096A20 E7A604FC */  swc1  $f6, 0x4fc($sp)
/* 0CB554 7F096A24 46182182 */  mul.s $f6, $f4, $f24
/* 0CB558 7F096A28 8FA5058C */  lw    $a1, 0x58c($sp)
/* 0CB55C 7F096A2C 46189202 */  mul.s $f8, $f18, $f24
/* 0CB560 7F096A30 E7AA0500 */  swc1  $f10, 0x500($sp)
/* 0CB564 7F096A34 C7AA0600 */  lwc1  $f10, 0x600($sp)
/* 0CB568 7F096A38 E7A60504 */  swc1  $f6, 0x504($sp)
/* 0CB56C 7F096A3C 46185102 */  mul.s $f4, $f10, $f24
/* 0CB570 7F096A40 E7A80514 */  swc1  $f8, 0x514($sp)
/* 0CB574 7F096A44 4618A182 */  mul.s $f6, $f20, $f24
/* 0CB578 7F096A48 00000000 */  nop
/* 0CB57C 7F096A4C 461C1202 */  mul.s $f8, $f2, $f28
/* 0CB580 7F096A50 E7A40518 */  swc1  $f4, 0x518($sp)
/* 0CB584 7F096A54 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB588 7F096A58 E7A6051C */  swc1  $f6, 0x51c($sp)
/* 0CB58C 7F096A5C 461C7182 */  mul.s $f6, $f14, $f28
/* 0CB590 7F096A60 E7A804C0 */  swc1  $f8, 0x4c0($sp)
/* 0CB594 7F096A64 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB598 7F096A68 46005100 */  add.s $f4, $f10, $f0
/* 0CB59C 7F096A6C E7A604D8 */  swc1  $f6, 0x4d8($sp)
/* 0CB5A0 7F096A70 C7A60628 */  lwc1  $f6, 0x628($sp)
/* 0CB5A4 7F096A74 E7A404C4 */  swc1  $f4, 0x4c4($sp)
/* 0CB5A8 7F096A78 461CB102 */  mul.s $f4, $f22, $f28
/* 0CB5AC 7F096A7C 46004280 */  add.s $f10, $f8, $f0
/* 0CB5B0 7F096A80 461C3202 */  mul.s $f8, $f6, $f28
/* 0CB5B4 7F096A84 E7AA04DC */  swc1  $f10, 0x4dc($sp)
/* 0CB5B8 7F096A88 E7A404F0 */  swc1  $f4, 0x4f0($sp)
/* 0CB5BC 7F096A8C C7A40608 */  lwc1  $f4, 0x608($sp)
/* 0CB5C0 7F096A90 46004280 */  add.s $f10, $f8, $f0
/* 0CB5C4 7F096A94 461C2182 */  mul.s $f6, $f4, $f28
/* 0CB5C8 7F096A98 C7A80610 */  lwc1  $f8, 0x610($sp)
/* 0CB5CC 7F096A9C E7AA04F4 */  swc1  $f10, 0x4f4($sp)
/* 0CB5D0 7F096AA0 461C4282 */  mul.s $f10, $f8, $f28
/* 0CB5D4 7F096AA4 E7A60508 */  swc1  $f6, 0x508($sp)
/* 0CB5D8 7F096AA8 461C9182 */  mul.s $f6, $f18, $f28
/* 0CB5DC 7F096AAC 46005100 */  add.s $f4, $f10, $f0
/* 0CB5E0 7F096AB0 461CA202 */  mul.s $f8, $f20, $f28
/* 0CB5E4 7F096AB4 E7A60520 */  swc1  $f6, 0x520($sp)
/* 0CB5E8 7F096AB8 E7A4050C */  swc1  $f4, 0x50c($sp)
/* 0CB5EC 7F096ABC 44812000 */  mtc1  $at, $f4
/* 0CB5F0 7F096AC0 00000000 */  nop
/* 0CB5F4 7F096AC4 46182183 */  div.s $f6, $f4, $f24
/* 0CB5F8 7F096AC8 46004280 */  add.s $f10, $f8, $f0
/* 0CB5FC 7F096ACC E7AA0524 */  swc1  $f10, 0x524($sp)
/* 0CB600 7F096AD0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB604 7F096AD4 E7A60058 */   swc1  $f6, 0x58($sp)
/* 0CB608 7F096AD8 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB60C 7F096ADC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB610 7F096AE0 8FA50588 */   lw    $a1, 0x588($sp)
/* 0CB614 7F096AE4 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB618 7F096AE8 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB61C 7F096AEC 8FA50580 */   lw    $a1, 0x580($sp)
/* 0CB620 7F096AF0 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CB624 7F096AF4 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB628 7F096AF8 8FA50578 */   lw    $a1, 0x578($sp)
/* 0CB62C 7F096AFC 27A40514 */  addiu $a0, $sp, 0x514
/* 0CB630 7F096B00 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB634 7F096B04 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CB638 7F096B08 100000C8 */  b     .L7F096E2C
/* 0CB63C 7F096B0C 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096B10:
/* 0CB640 7F096B10 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CB644 7F096B14 C7AA0624 */  lwc1  $f10, 0x624($sp)
/* 0CB648 7F096B18 C7A60628 */  lwc1  $f6, 0x628($sp)
/* 0CB64C 7F096B1C 4618B202 */  mul.s $f8, $f22, $f24
/* 0CB650 7F096B20 C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CB654 7F096B24 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CB658 7F096B28 46185102 */  mul.s $f4, $f10, $f24
/* 0CB65C 7F096B2C C7A20644 */  lwc1  $f2, 0x644($sp)
/* 0CB660 7F096B30 C7AC064C */  lwc1  $f12, 0x64c($sp)
/* 0CB664 7F096B34 C7AE0614 */  lwc1  $f14, 0x614($sp)
/* 0CB668 7F096B38 E7A804B4 */  swc1  $f8, 0x4b4($sp)
/* 0CB66C 7F096B3C 46183202 */  mul.s $f8, $f6, $f24
/* 0CB670 7F096B40 C7B0061C */  lwc1  $f16, 0x61c($sp)
/* 0CB674 7F096B44 E7A404B8 */  swc1  $f4, 0x4b8($sp)
/* 0CB678 7F096B48 46189282 */  mul.s $f10, $f18, $f24
/* 0CB67C 7F096B4C C7A40630 */  lwc1  $f4, 0x630($sp)
/* 0CB680 7F096B50 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB684 7F096B54 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB688 7F096B58 E7A804BC */  swc1  $f8, 0x4bc($sp)
/* 0CB68C 7F096B5C 46182202 */  mul.s $f8, $f4, $f24
/* 0CB690 7F096B60 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB694 7F096B64 E7AA04CC */  swc1  $f10, 0x4cc($sp)
/* 0CB698 7F096B68 4618A282 */  mul.s $f10, $f20, $f24
/* 0CB69C 7F096B6C 24110005 */  li    $s1, 5
/* 0CB6A0 7F096B70 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB6A4 7F096B74 46181102 */  mul.s $f4, $f2, $f24
/* 0CB6A8 7F096B78 E7A804D0 */  swc1  $f8, 0x4d0($sp)
/* 0CB6AC 7F096B7C C7A80648 */  lwc1  $f8, 0x648($sp)
/* 0CB6B0 7F096B80 8FA50580 */  lw    $a1, 0x580($sp)
/* 0CB6B4 7F096B84 E7AA04D4 */  swc1  $f10, 0x4d4($sp)
/* 0CB6B8 7F096B88 46184282 */  mul.s $f10, $f8, $f24
/* 0CB6BC 7F096B8C E7A404E4 */  swc1  $f4, 0x4e4($sp)
/* 0CB6C0 7F096B90 46186102 */  mul.s $f4, $f12, $f24
/* 0CB6C4 7F096B94 E7AA04E8 */  swc1  $f10, 0x4e8($sp)
/* 0CB6C8 7F096B98 46187202 */  mul.s $f8, $f14, $f24
/* 0CB6CC 7F096B9C C7AA0618 */  lwc1  $f10, 0x618($sp)
/* 0CB6D0 7F096BA0 E7A404EC */  swc1  $f4, 0x4ec($sp)
/* 0CB6D4 7F096BA4 46185102 */  mul.s $f4, $f10, $f24
/* 0CB6D8 7F096BA8 C7AA05F0 */  lwc1  $f10, 0x5f0($sp)
/* 0CB6DC 7F096BAC E7A804FC */  swc1  $f8, 0x4fc($sp)
/* 0CB6E0 7F096BB0 46188202 */  mul.s $f8, $f16, $f24
/* 0CB6E4 7F096BB4 E7A40500 */  swc1  $f4, 0x500($sp)
/* 0CB6E8 7F096BB8 46185102 */  mul.s $f4, $f10, $f24
/* 0CB6EC 7F096BBC E7A80504 */  swc1  $f8, 0x504($sp)
/* 0CB6F0 7F096BC0 C7A805F4 */  lwc1  $f8, 0x5f4($sp)
/* 0CB6F4 7F096BC4 46184282 */  mul.s $f10, $f8, $f24
/* 0CB6F8 7F096BC8 E7A40514 */  swc1  $f4, 0x514($sp)
/* 0CB6FC 7F096BCC C7A405F8 */  lwc1  $f4, 0x5f8($sp)
/* 0CB700 7F096BD0 46182202 */  mul.s $f8, $f4, $f24
/* 0CB704 7F096BD4 E7AA0518 */  swc1  $f10, 0x518($sp)
/* 0CB708 7F096BD8 461CB282 */  mul.s $f10, $f22, $f28
/* 0CB70C 7F096BDC 00000000 */  nop
/* 0CB710 7F096BE0 461C3102 */  mul.s $f4, $f6, $f28
/* 0CB714 7F096BE4 E7A8051C */  swc1  $f8, 0x51c($sp)
/* 0CB718 7F096BE8 E7AA04C0 */  swc1  $f10, 0x4c0($sp)
/* 0CB71C 7F096BEC 461C9282 */  mul.s $f10, $f18, $f28
/* 0CB720 7F096BF0 46002200 */  add.s $f8, $f4, $f0
/* 0CB724 7F096BF4 461CA182 */  mul.s $f6, $f20, $f28
/* 0CB728 7F096BF8 E7A804C4 */  swc1  $f8, 0x4c4($sp)
/* 0CB72C 7F096BFC 461C1202 */  mul.s $f8, $f2, $f28
/* 0CB730 7F096C00 E7AA04D8 */  swc1  $f10, 0x4d8($sp)
/* 0CB734 7F096C04 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB738 7F096C08 46003100 */  add.s $f4, $f6, $f0
/* 0CB73C 7F096C0C E7A804F0 */  swc1  $f8, 0x4f0($sp)
/* 0CB740 7F096C10 E7A404DC */  swc1  $f4, 0x4dc($sp)
/* 0CB744 7F096C14 461C7102 */  mul.s $f4, $f14, $f28
/* 0CB748 7F096C18 46005180 */  add.s $f6, $f10, $f0
/* 0CB74C 7F096C1C 461C8202 */  mul.s $f8, $f16, $f28
/* 0CB750 7F096C20 E7A604F4 */  swc1  $f6, 0x4f4($sp)
/* 0CB754 7F096C24 C7A605F0 */  lwc1  $f6, 0x5f0($sp)
/* 0CB758 7F096C28 E7A40508 */  swc1  $f4, 0x508($sp)
/* 0CB75C 7F096C2C 461C3102 */  mul.s $f4, $f6, $f28
/* 0CB760 7F096C30 46004280 */  add.s $f10, $f8, $f0
/* 0CB764 7F096C34 C7A805F8 */  lwc1  $f8, 0x5f8($sp)
/* 0CB768 7F096C38 E7AA050C */  swc1  $f10, 0x50c($sp)
/* 0CB76C 7F096C3C 461C4282 */  mul.s $f10, $f8, $f28
/* 0CB770 7F096C40 E7A40520 */  swc1  $f4, 0x520($sp)
/* 0CB774 7F096C44 44812000 */  mtc1  $at, $f4
/* 0CB778 7F096C48 00000000 */  nop
/* 0CB77C 7F096C4C 46182203 */  div.s $f8, $f4, $f24
/* 0CB780 7F096C50 46005180 */  add.s $f6, $f10, $f0
/* 0CB784 7F096C54 E7A60524 */  swc1  $f6, 0x524($sp)
/* 0CB788 7F096C58 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB78C 7F096C5C E7A80058 */   swc1  $f8, 0x58($sp)
/* 0CB790 7F096C60 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB794 7F096C64 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB798 7F096C68 8FA50584 */   lw    $a1, 0x584($sp)
/* 0CB79C 7F096C6C 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB7A0 7F096C70 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB7A4 7F096C74 8FA5058C */   lw    $a1, 0x58c($sp)
/* 0CB7A8 7F096C78 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CB7AC 7F096C7C 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB7B0 7F096C80 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CB7B4 7F096C84 27A40514 */  addiu $a0, $sp, 0x514
/* 0CB7B8 7F096C88 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB7BC 7F096C8C 8FA50570 */   lw    $a1, 0x570($sp)
/* 0CB7C0 7F096C90 10000066 */  b     .L7F096E2C
/* 0CB7C4 7F096C94 8FAF06B0 */   lw    $t7, 0x6b0($sp)
.L7F096C98:
/* 0CB7C8 7F096C98 C7AE0638 */  lwc1  $f14, 0x638($sp)
/* 0CB7CC 7F096C9C C7A6063C */  lwc1  $f6, 0x63c($sp)
/* 0CB7D0 7F096CA0 C7B00640 */  lwc1  $f16, 0x640($sp)
/* 0CB7D4 7F096CA4 46187282 */  mul.s $f10, $f14, $f24
/* 0CB7D8 7F096CA8 C7B60620 */  lwc1  $f22, 0x620($sp)
/* 0CB7DC 7F096CAC C7A20628 */  lwc1  $f2, 0x628($sp)
/* 0CB7E0 7F096CB0 46183102 */  mul.s $f4, $f6, $f24
/* 0CB7E4 7F096CB4 C7A60624 */  lwc1  $f6, 0x624($sp)
/* 0CB7E8 7F096CB8 C7B2062C */  lwc1  $f18, 0x62c($sp)
/* 0CB7EC 7F096CBC 46188202 */  mul.s $f8, $f16, $f24
/* 0CB7F0 7F096CC0 E7AA04B4 */  swc1  $f10, 0x4b4($sp)
/* 0CB7F4 7F096CC4 C7B40634 */  lwc1  $f20, 0x634($sp)
/* 0CB7F8 7F096CC8 4618B282 */  mul.s $f10, $f22, $f24
/* 0CB7FC 7F096CCC E7A404B8 */  swc1  $f4, 0x4b8($sp)
/* 0CB800 7F096CD0 C7AC05FC */  lwc1  $f12, 0x5fc($sp)
/* 0CB804 7F096CD4 46183102 */  mul.s $f4, $f6, $f24
/* 0CB808 7F096CD8 E7A804BC */  swc1  $f8, 0x4bc($sp)
/* 0CB80C 7F096CDC C7A60630 */  lwc1  $f6, 0x630($sp)
/* 0CB810 7F096CE0 46181202 */  mul.s $f8, $f2, $f24
/* 0CB814 7F096CE4 E7AA04CC */  swc1  $f10, 0x4cc($sp)
/* 0CB818 7F096CE8 3C018004 */  lui   $at, %hi(D_8003FD94)
/* 0CB81C 7F096CEC 46189282 */  mul.s $f10, $f18, $f24
/* 0CB820 7F096CF0 E7A404D0 */  swc1  $f4, 0x4d0($sp)
/* 0CB824 7F096CF4 C420FD94 */  lwc1  $f0, %lo(D_8003FD94)($at)
/* 0CB828 7F096CF8 46183102 */  mul.s $f4, $f6, $f24
/* 0CB82C 7F096CFC E7A804D4 */  swc1  $f8, 0x4d4($sp)
/* 0CB830 7F096D00 C7A60600 */  lwc1  $f6, 0x600($sp)
/* 0CB834 7F096D04 4618A202 */  mul.s $f8, $f20, $f24
/* 0CB838 7F096D08 E7AA04E4 */  swc1  $f10, 0x4e4($sp)
/* 0CB83C 7F096D0C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CB840 7F096D10 46186282 */  mul.s $f10, $f12, $f24
/* 0CB844 7F096D14 E7A404E8 */  swc1  $f4, 0x4e8($sp)
/* 0CB848 7F096D18 24110005 */  li    $s1, 5
/* 0CB84C 7F096D1C 46183102 */  mul.s $f4, $f6, $f24
/* 0CB850 7F096D20 E7A804EC */  swc1  $f8, 0x4ec($sp)
/* 0CB854 7F096D24 C7A80604 */  lwc1  $f8, 0x604($sp)
/* 0CB858 7F096D28 C7A60614 */  lwc1  $f6, 0x614($sp)
/* 0CB85C 7F096D2C E7AA04FC */  swc1  $f10, 0x4fc($sp)
/* 0CB860 7F096D30 46184282 */  mul.s $f10, $f8, $f24
/* 0CB864 7F096D34 C7A80618 */  lwc1  $f8, 0x618($sp)
/* 0CB868 7F096D38 E7A40500 */  swc1  $f4, 0x500($sp)
/* 0CB86C 7F096D3C 46183102 */  mul.s $f4, $f6, $f24
/* 0CB870 7F096D40 C7A6061C */  lwc1  $f6, 0x61c($sp)
/* 0CB874 7F096D44 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CB878 7F096D48 8FA50588 */  lw    $a1, 0x588($sp)
/* 0CB87C 7F096D4C E7AA0504 */  swc1  $f10, 0x504($sp)
/* 0CB880 7F096D50 46184282 */  mul.s $f10, $f8, $f24
/* 0CB884 7F096D54 E7A40514 */  swc1  $f4, 0x514($sp)
/* 0CB888 7F096D58 46183102 */  mul.s $f4, $f6, $f24
/* 0CB88C 7F096D5C 00000000 */  nop
/* 0CB890 7F096D60 461C7202 */  mul.s $f8, $f14, $f28
/* 0CB894 7F096D64 E7AA0518 */  swc1  $f10, 0x518($sp)
/* 0CB898 7F096D68 461C8282 */  mul.s $f10, $f16, $f28
/* 0CB89C 7F096D6C E7A4051C */  swc1  $f4, 0x51c($sp)
/* 0CB8A0 7F096D70 461CB102 */  mul.s $f4, $f22, $f28
/* 0CB8A4 7F096D74 E7A804C0 */  swc1  $f8, 0x4c0($sp)
/* 0CB8A8 7F096D78 461C1202 */  mul.s $f8, $f2, $f28
/* 0CB8AC 7F096D7C 46005180 */  add.s $f6, $f10, $f0
/* 0CB8B0 7F096D80 E7A404D8 */  swc1  $f4, 0x4d8($sp)
/* 0CB8B4 7F096D84 E7A604C4 */  swc1  $f6, 0x4c4($sp)
/* 0CB8B8 7F096D88 461C9182 */  mul.s $f6, $f18, $f28
/* 0CB8BC 7F096D8C 46004280 */  add.s $f10, $f8, $f0
/* 0CB8C0 7F096D90 461CA102 */  mul.s $f4, $f20, $f28
/* 0CB8C4 7F096D94 E7AA04DC */  swc1  $f10, 0x4dc($sp)
/* 0CB8C8 7F096D98 461C6282 */  mul.s $f10, $f12, $f28
/* 0CB8CC 7F096D9C E7A604F0 */  swc1  $f6, 0x4f0($sp)
/* 0CB8D0 7F096DA0 C7A60604 */  lwc1  $f6, 0x604($sp)
/* 0CB8D4 7F096DA4 46002200 */  add.s $f8, $f4, $f0
/* 0CB8D8 7F096DA8 461C3102 */  mul.s $f4, $f6, $f28
/* 0CB8DC 7F096DAC E7AA0508 */  swc1  $f10, 0x508($sp)
/* 0CB8E0 7F096DB0 C7AA0614 */  lwc1  $f10, 0x614($sp)
/* 0CB8E4 7F096DB4 E7A804F4 */  swc1  $f8, 0x4f4($sp)
/* 0CB8E8 7F096DB8 461C5182 */  mul.s $f6, $f10, $f28
/* 0CB8EC 7F096DBC 46002200 */  add.s $f8, $f4, $f0
/* 0CB8F0 7F096DC0 C7A4061C */  lwc1  $f4, 0x61c($sp)
/* 0CB8F4 7F096DC4 E7A8050C */  swc1  $f8, 0x50c($sp)
/* 0CB8F8 7F096DC8 E7A60520 */  swc1  $f6, 0x520($sp)
/* 0CB8FC 7F096DCC 44813000 */  mtc1  $at, $f6
/* 0CB900 7F096DD0 461C2202 */  mul.s $f8, $f4, $f28
/* 0CB904 7F096DD4 46183103 */  div.s $f4, $f6, $f24
/* 0CB908 7F096DD8 46004280 */  add.s $f10, $f8, $f0
/* 0CB90C 7F096DDC E7AA0524 */  swc1  $f10, 0x524($sp)
/* 0CB910 7F096DE0 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB914 7F096DE4 E7A40058 */   swc1  $f4, 0x58($sp)
/* 0CB918 7F096DE8 27A404CC */  addiu $a0, $sp, 0x4cc
/* 0CB91C 7F096DEC 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB920 7F096DF0 8FA50580 */   lw    $a1, 0x580($sp)
/* 0CB924 7F096DF4 27A404E4 */  addiu $a0, $sp, 0x4e4
/* 0CB928 7F096DF8 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB92C 7F096DFC 8FA50584 */   lw    $a1, 0x584($sp)
/* 0CB930 7F096E00 27A404FC */  addiu $a0, $sp, 0x4fc
/* 0CB934 7F096E04 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB938 7F096E08 8FA50574 */   lw    $a1, 0x574($sp)
/* 0CB93C 7F096E0C 27A40514 */  addiu $a0, $sp, 0x514
/* 0CB940 7F096E10 0FC24F2C */  jal   sub_GAME_7F093CB0
/* 0CB944 7F096E14 8FA5057C */   lw    $a1, 0x57c($sp)
/* 0CB948 7F096E18 10000004 */  b     .L7F096E2C
/* 0CB94C 7F096E1C 8FAF06B0 */   lw    $t7, 0x6b0($sp)
def_7F095E0C:
.L7F096E20:
/* 0CB950 7F096E20 1000014F */  b     .L7F097360
/* 0CB954 7F096E24 00601025 */   move  $v0, $v1
/* 0CB958 7F096E28 8FAF06B0 */  lw    $t7, 0x6b0($sp)
.L7F096E2C:
/* 0CB95C 7F096E2C 3C0CE700 */  lui   $t4, 0xe700
/* 0CB960 7F096E30 25ED0008 */  addiu $t5, $t7, 8
/* 0CB964 7F096E34 AFAD06B0 */  sw    $t5, 0x6b0($sp)
/* 0CB968 7F096E38 ADE00004 */  sw    $zero, 4($t7)
/* 0CB96C 7F096E3C 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0CB970 7F096E40 ADEC0000 */   sw    $t4, ($t7)
/* 0CB974 7F096E44 84590010 */  lh    $t9, 0x10($v0)
/* 0CB978 7F096E48 3C0B8009 */  lui   $t3, %hi(skywaterimages)
/* 0CB97C 7F096E4C 8D6BD124 */  lw    $t3, %lo(skywaterimages)($t3)
/* 0CB980 7F096E50 0019C080 */  sll   $t8, $t9, 2
/* 0CB984 7F096E54 0319C023 */  subu  $t8, $t8, $t9
/* 0CB988 7F096E58 0018C080 */  sll   $t8, $t8, 2
/* 0CB98C 7F096E5C 240E0002 */  li    $t6, 2
/* 0CB990 7F096E60 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0CB994 7F096E64 27A406B0 */  addiu $a0, $sp, 0x6b0
/* 0CB998 7F096E68 24060001 */  li    $a2, 1
/* 0CB99C 7F096E6C 00003825 */  move  $a3, $zero
/* 0CB9A0 7F096E70 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0CB9A4 7F096E74 030B2821 */   addu  $a1, $t8, $t3
/* 0CB9A8 7F096E78 8FAA06B0 */  lw    $t2, 0x6b0($sp)
/* 0CB9AC 7F096E7C 3C0DFB00 */  lui   $t5, 0xfb00
/* 0CB9B0 7F096E80 254F0008 */  addiu $t7, $t2, 8
/* 0CB9B4 7F096E84 AFAF06B0 */  sw    $t7, 0x6b0($sp)
/* 0CB9B8 7F096E88 AD4D0000 */  sw    $t5, ($t2)
/* 0CB9BC 7F096E8C 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0CB9C0 7F096E90 AFAA0228 */   sw    $t2, 0x228($sp)
/* 0CB9C4 7F096E94 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0CB9C8 7F096E98 00408025 */   move  $s0, $v0
/* 0CB9CC 7F096E9C 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0CB9D0 7F096EA0 AFA2006C */   sw    $v0, 0x6c($sp)
/* 0CB9D4 7F096EA4 8FAB006C */  lw    $t3, 0x6c($sp)
/* 0CB9D8 7F096EA8 9059000A */  lbu   $t9, 0xa($v0)
/* 0CB9DC 7F096EAC 916A0008 */  lbu   $t2, 8($t3)
/* 0CB9E0 7F096EB0 0019C200 */  sll   $t8, $t9, 8
/* 0CB9E4 7F096EB4 92190009 */  lbu   $t9, 9($s0)
/* 0CB9E8 7F096EB8 000A7E00 */  sll   $t7, $t2, 0x18
/* 0CB9EC 7F096EBC 030F6825 */  or    $t5, $t8, $t7
/* 0CB9F0 7F096EC0 8FB80228 */  lw    $t8, 0x228($sp)
/* 0CB9F4 7F096EC4 00195C00 */  sll   $t3, $t9, 0x10
/* 0CB9F8 7F096EC8 01AB7025 */  or    $t6, $t5, $t3
/* 0CB9FC 7F096ECC 35CA00FF */  ori   $t2, $t6, 0xff
/* 0CBA00 7F096ED0 AF0A0004 */  sw    $t2, 4($t8)
/* 0CBA04 7F096ED4 8FAF06B0 */  lw    $t7, 0x6b0($sp)
/* 0CBA08 7F096ED8 3C0D55FE */  lui   $t5, (0x55FEF97C >> 16) # lui $t5, 0x55fe
/* 0CBA0C 7F096EDC 3C19FC40 */  lui   $t9, (0xFC40FE81 >> 16) # lui $t9, 0xfc40
/* 0CBA10 7F096EE0 25EC0008 */  addiu $t4, $t7, 8
/* 0CBA14 7F096EE4 AFAC06B0 */  sw    $t4, 0x6b0($sp)
/* 0CBA18 7F096EE8 3739FE81 */  ori   $t9, (0xFC40FE81 & 0xFFFF) # ori $t9, $t9, 0xfe81
/* 0CBA1C 7F096EEC 35ADF97C */  ori   $t5, (0x55FEF97C & 0xFFFF) # ori $t5, $t5, 0xf97c
/* 0CBA20 7F096EF0 ADED0004 */  sw    $t5, 4($t7)
/* 0CBA24 7F096EF4 0FC1E0F9 */  jal   currentPlayerGetProjectionMatrixF
/* 0CBA28 7F096EF8 ADF90000 */   sw    $t9, ($t7)
/* 0CBA2C 7F096EFC 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0CBA30 7F096F00 00408025 */   move  $s0, $v0
/* 0CBA34 7F096F04 02002025 */  move  $a0, $s0
/* 0CBA38 7F096F08 00402825 */  move  $a1, $v0
/* 0CBA3C 7F096F0C 0FC16032 */  jal   matrix_4x4_multiply
/* 0CBA40 7F096F10 27A601E4 */   addiu $a2, $sp, 0x1e4
/* 0CBA44 7F096F14 C7A80058 */  lwc1  $f8, 0x58($sp)
/* 0CBA48 7F096F18 3C048008 */  lui   $a0, %hi(dword_CODE_bss_80079E98)
/* 0CBA4C 7F096F1C 24849E98 */  addiu $a0, %lo(dword_CODE_bss_80079E98) # addiu $a0, $a0, -0x6168
/* 0CBA50 7F096F20 44054000 */  mfc1  $a1, $f8
/* 0CBA54 7F096F24 44064000 */  mfc1  $a2, $f8
/* 0CBA58 7F096F28 44074000 */  mfc1  $a3, $f8
/* 0CBA5C 7F096F2C 0C005BA4 */  jal   guScaleF
/* 0CBA60 7F096F30 00000000 */   nop
/* 0CBA64 7F096F34 3C058008 */  lui   $a1, %hi(dword_CODE_bss_80079E98)
/* 0CBA68 7F096F38 24A59E98 */  addiu $a1, %lo(dword_CODE_bss_80079E98) # addiu $a1, $a1, -0x6168
/* 0CBA6C 7F096F3C 27A401E4 */  addiu $a0, $sp, 0x1e4
/* 0CBA70 7F096F40 0FC16032 */  jal   matrix_4x4_multiply
/* 0CBA74 7F096F44 27A601A4 */   addiu $a2, $sp, 0x1a4
/* 0CBA78 7F096F48 1A200036 */  blez  $s1, .L7F097024
/* 0CBA7C 7F096F4C AFA00088 */   sw    $zero, 0x88($sp)
/* 0CBA80 7F096F50 27A404B4 */  addiu $a0, $sp, 0x4b4
/* 0CBA84 7F096F54 AFA40058 */  sw    $a0, 0x58($sp)
/* 0CBA88 7F096F58 27B0008C */  addiu $s0, $sp, 0x8c
.L7F096F5C:
/* 0CBA8C 7F096F5C 3C018005 */  lui   $at, %hi(D_800575D0)
/* 0CBA90 7F096F60 C42075D0 */  lwc1  $f0, %lo(D_800575D0)($at)
/* 0CBA94 7F096F64 8FA40058 */  lw    $a0, 0x58($sp)
/* 0CBA98 7F096F68 27A501A4 */  addiu $a1, $sp, 0x1a4
/* 0CBA9C 7F096F6C 44070000 */  mfc1  $a3, $f0
/* 0CBAA0 7F096F70 24060082 */  li    $a2, 130
/* 0CBAA4 7F096F74 AFB00014 */  sw    $s0, 0x14($sp)
/* 0CBAA8 7F096F78 0FC25CE2 */  jal   sub_GAME_7F097388
/* 0CBAAC 7F096F7C E7A00010 */   swc1  $f0, 0x10($sp)
/* 0CBAB0 7F096F80 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBAB4 7F096F84 00000000 */   nop
/* 0CBAB8 7F096F88 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBABC 7F096F8C 46000506 */   mov.s $f20, $f0
/* 0CBAC0 7F096F90 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBAC4 7F096F94 46000586 */   mov.s $f22, $f0
/* 0CBAC8 7F096F98 46160280 */  add.s $f10, $f0, $f22
/* 0CBACC 7F096F9C 461AA382 */  mul.s $f14, $f20, $f26
/* 0CBAD0 7F096FA0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBAD4 7F096FA4 44812000 */  mtc1  $at, $f4
/* 0CBAD8 7F096FA8 461A5182 */  mul.s $f6, $f10, $f26
/* 0CBADC 7F096FAC C60C0028 */  lwc1  $f12, 0x28($s0)
/* 0CBAE0 7F096FB0 46043201 */  sub.s $f8, $f6, $f4
/* 0CBAE4 7F096FB4 44064000 */  mfc1  $a2, $f8
/* 0CBAE8 7F096FB8 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CBAEC 7F096FBC 00000000 */   nop
/* 0CBAF0 7F096FC0 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBAF4 7F096FC4 E6000028 */   swc1  $f0, 0x28($s0)
/* 0CBAF8 7F096FC8 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBAFC 7F096FCC 46000506 */   mov.s $f20, $f0
/* 0CBB00 7F096FD0 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CBB04 7F096FD4 46000586 */   mov.s $f22, $f0
/* 0CBB08 7F096FD8 46160280 */  add.s $f10, $f0, $f22
/* 0CBB0C 7F096FDC 461AA382 */  mul.s $f14, $f20, $f26
/* 0CBB10 7F096FE0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBB14 7F096FE4 44812000 */  mtc1  $at, $f4
/* 0CBB18 7F096FE8 461A5182 */  mul.s $f6, $f10, $f26
/* 0CBB1C 7F096FEC C60C002C */  lwc1  $f12, 0x2c($s0)
/* 0CBB20 7F096FF0 46043201 */  sub.s $f8, $f6, $f4
/* 0CBB24 7F096FF4 44064000 */  mfc1  $a2, $f8
/* 0CBB28 7F096FF8 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CBB2C 7F096FFC 00000000 */   nop
/* 0CBB30 7F097000 8FA20088 */  lw    $v0, 0x88($sp)
/* 0CBB34 7F097004 E600002C */  swc1  $f0, 0x2c($s0)
/* 0CBB38 7F097008 8FAB0058 */  lw    $t3, 0x58($sp)
/* 0CBB3C 7F09700C 24420001 */  addiu $v0, $v0, 1
/* 0CBB40 7F097010 AFA20088 */  sw    $v0, 0x88($sp)
/* 0CBB44 7F097014 256E0018 */  addiu $t6, $t3, 0x18
/* 0CBB48 7F097018 AFAE0058 */  sw    $t6, 0x58($sp)
/* 0CBB4C 7F09701C 1451FFCF */  bne   $v0, $s1, .L7F096F5C
/* 0CBB50 7F097020 26100038 */   addiu $s0, $s0, 0x38
.L7F097024:
/* 0CBB54 7F097024 24010004 */  li    $at, 4
/* 0CBB58 7F097028 16210099 */  bne   $s1, $at, .L7F097290
/* 0CBB5C 7F09702C 8FAA005C */   lw    $t2, 0x5c($sp)
/* 0CBB60 7F097030 2401000C */  li    $at, 12
/* 0CBB64 7F097034 1541007E */  bne   $t2, $at, .L7F097230
/* 0CBB68 7F097038 27B0008C */   addiu $s0, $sp, 0x8c
/* 0CBB6C 7F09703C C7AA0548 */  lwc1  $f10, 0x548($sp)
/* 0CBB70 7F097040 C7A6054C */  lwc1  $f6, 0x54c($sp)
/* 0CBB74 7F097044 C7A800F0 */  lwc1  $f8, 0xf0($sp)
/* 0CBB78 7F097048 4606503C */  c.lt.s $f10, $f6
/* 0CBB7C 7F09704C C7AA00B8 */  lwc1  $f10, 0xb8($sp)
/* 0CBB80 7F097050 4502003D */  bc1fl .L7F097148
/* 0CBB84 7F097054 461A5180 */   add.s $f6, $f10, $f26
/* 0CBB88 7F097058 461A4280 */  add.s $f10, $f8, $f26
/* 0CBB8C 7F09705C C7A40160 */  lwc1  $f4, 0x160($sp)
/* 0CBB90 7F097060 27A5008C */  addiu $a1, $sp, 0x8c
/* 0CBB94 7F097064 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBB98 7F097068 4604503E */  c.le.s $f10, $f4
/* 0CBB9C 7F09706C 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBBA0 7F097070 27A700FC */  addiu $a3, $sp, 0xfc
/* 0CBBA4 7F097074 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBBA8 7F097078 4500002C */  bc1f  .L7F09712C
/* 0CBBAC 7F09707C 24180001 */   li    $t8, 1
/* 0CBBB0 7F097080 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBBB4 7F097084 00000000 */   nop
/* 0CBBB8 7F097088 461A0182 */  mul.s $f6, $f0, $f26
/* 0CBBBC 7F09708C 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBBC0 7F097090 E7A600B4 */   swc1  $f6, 0xb4($sp)
/* 0CBBC4 7F097094 461A0202 */  mul.s $f8, $f0, $f26
/* 0CBBC8 7F097098 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBBCC 7F09709C E7A800B8 */   swc1  $f8, 0xb8($sp)
/* 0CBBD0 7F0970A0 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBBD4 7F0970A4 46000506 */   mov.s $f20, $f0
/* 0CBBD8 7F0970A8 46140100 */  add.s $f4, $f0, $f20
/* 0CBBDC 7F0970AC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBBE0 7F0970B0 44813000 */  mtc1  $at, $f6
/* 0CBBE4 7F0970B4 461A2282 */  mul.s $f10, $f4, $f26
/* 0CBBE8 7F0970B8 46065201 */  sub.s $f8, $f10, $f6
/* 0CBBEC 7F0970BC 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBBF0 7F0970C0 E7A800EC */   swc1  $f8, 0xec($sp)
/* 0CBBF4 7F0970C4 461A0102 */  mul.s $f4, $f0, $f26
/* 0CBBF8 7F0970C8 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBBFC 7F0970CC E7A400F0 */   swc1  $f4, 0xf0($sp)
/* 0CBC00 7F0970D0 461A0282 */  mul.s $f10, $f0, $f26
/* 0CBC04 7F0970D4 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBC08 7F0970D8 E7AA0124 */   swc1  $f10, 0x124($sp)
/* 0CBC0C 7F0970DC 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBC10 7F0970E0 46000506 */   mov.s $f20, $f0
/* 0CBC14 7F0970E4 46140180 */  add.s $f6, $f0, $f20
/* 0CBC18 7F0970E8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBC1C 7F0970EC 44812000 */  mtc1  $at, $f4
/* 0CBC20 7F0970F0 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBC24 7F0970F4 461A3202 */  mul.s $f8, $f6, $f26
/* 0CBC28 7F0970F8 44813000 */  mtc1  $at, $f6
/* 0CBC2C 7F0970FC 27B10134 */  addiu $s1, $sp, 0x134
/* 0CBC30 7F097100 27A5008C */  addiu $a1, $sp, 0x8c
/* 0CBC34 7F097104 AFB10010 */  sw    $s1, 0x10($sp)
/* 0CBC38 7F097108 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBC3C 7F09710C 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBC40 7F097110 46044281 */  sub.s $f10, $f8, $f4
/* 0CBC44 7F097114 27A700FC */  addiu $a3, $sp, 0xfc
/* 0CBC48 7F097118 E7A60014 */  swc1  $f6, 0x14($sp)
/* 0CBC4C 7F09711C 0FC2628B */  jal   sub_GAME_7F098A2C
/* 0CBC50 7F097120 E7AA015C */   swc1  $f10, 0x15c($sp)
/* 0CBC54 7F097124 1000008D */  b     .L7F09735C
/* 0CBC58 7F097128 AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F09712C:
/* 0CBC5C 7F09712C 44814000 */  mtc1  $at, $f8
/* 0CBC60 7F097130 AFB80014 */  sw    $t8, 0x14($sp)
/* 0CBC64 7F097134 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBC68 7F097138 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0CBC6C 7F09713C 10000087 */  b     .L7F09735C
/* 0CBC70 7F097140 AFA206B0 */   sw    $v0, 0x6b0($sp)
/* 0CBC74 7F097144 461A5180 */  add.s $f6, $f10, $f26
.L7F097148:
/* 0CBC78 7F097148 C7A40128 */  lwc1  $f4, 0x128($sp)
/* 0CBC7C 7F09714C 27A6008C */  addiu $a2, $sp, 0x8c
/* 0CBC80 7F097150 27A70134 */  addiu $a3, $sp, 0x134
/* 0CBC84 7F097154 4604303E */  c.le.s $f6, $f4
/* 0CBC88 7F097158 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBC8C 7F09715C 27A500C4 */  addiu $a1, $sp, 0xc4
/* 0CBC90 7F097160 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBC94 7F097164 4500002C */  bc1f  .L7F097218
/* 0CBC98 7F097168 240C0001 */   li    $t4, 1
/* 0CBC9C 7F09716C 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBCA0 7F097170 00000000 */   nop
/* 0CBCA4 7F097174 461A0202 */  mul.s $f8, $f0, $f26
/* 0CBCA8 7F097178 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBCAC 7F09717C E7A800B4 */   swc1  $f8, 0xb4($sp)
/* 0CBCB0 7F097180 461A0282 */  mul.s $f10, $f0, $f26
/* 0CBCB4 7F097184 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBCB8 7F097188 E7AA00B8 */   swc1  $f10, 0xb8($sp)
/* 0CBCBC 7F09718C 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBCC0 7F097190 46000506 */   mov.s $f20, $f0
/* 0CBCC4 7F097194 46140100 */  add.s $f4, $f0, $f20
/* 0CBCC8 7F097198 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBCCC 7F09719C 44814000 */  mtc1  $at, $f8
/* 0CBCD0 7F0971A0 461A2182 */  mul.s $f6, $f4, $f26
/* 0CBCD4 7F0971A4 46083281 */  sub.s $f10, $f6, $f8
/* 0CBCD8 7F0971A8 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CBCDC 7F0971AC E7AA00EC */   swc1  $f10, 0xec($sp)
/* 0CBCE0 7F0971B0 461A0102 */  mul.s $f4, $f0, $f26
/* 0CBCE4 7F0971B4 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBCE8 7F0971B8 E7A400F0 */   swc1  $f4, 0xf0($sp)
/* 0CBCEC 7F0971BC 461A0182 */  mul.s $f6, $f0, $f26
/* 0CBCF0 7F0971C0 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CBCF4 7F0971C4 E7A60124 */   swc1  $f6, 0x124($sp)
/* 0CBCF8 7F0971C8 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CBCFC 7F0971CC 46000506 */   mov.s $f20, $f0
/* 0CBD00 7F0971D0 46140200 */  add.s $f8, $f0, $f20
/* 0CBD04 7F0971D4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CBD08 7F0971D8 44812000 */  mtc1  $at, $f4
/* 0CBD0C 7F0971DC 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBD10 7F0971E0 461A4282 */  mul.s $f10, $f8, $f26
/* 0CBD14 7F0971E4 44814000 */  mtc1  $at, $f8
/* 0CBD18 7F0971E8 27AF00FC */  addiu $t7, $sp, 0xfc
/* 0CBD1C 7F0971EC 27A6008C */  addiu $a2, $sp, 0x8c
/* 0CBD20 7F0971F0 27A70134 */  addiu $a3, $sp, 0x134
/* 0CBD24 7F0971F4 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0CBD28 7F0971F8 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBD2C 7F0971FC 46045181 */  sub.s $f6, $f10, $f4
/* 0CBD30 7F097200 27A500C4 */  addiu $a1, $sp, 0xc4
/* 0CBD34 7F097204 E7A80014 */  swc1  $f8, 0x14($sp)
/* 0CBD38 7F097208 0FC2628B */  jal   sub_GAME_7F098A2C
/* 0CBD3C 7F09720C E7A6015C */   swc1  $f6, 0x15c($sp)
/* 0CBD40 7F097210 10000052 */  b     .L7F09735C
/* 0CBD44 7F097214 AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F097218:
/* 0CBD48 7F097218 44815000 */  mtc1  $at, $f10
/* 0CBD4C 7F09721C AFAC0014 */  sw    $t4, 0x14($sp)
/* 0CBD50 7F097220 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBD54 7F097224 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0CBD58 7F097228 1000004C */  b     .L7F09735C
/* 0CBD5C 7F09722C AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F097230:
/* 0CBD60 7F097230 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBD64 7F097234 44812000 */  mtc1  $at, $f4
/* 0CBD68 7F097238 27B10134 */  addiu $s1, $sp, 0x134
/* 0CBD6C 7F09723C 24190001 */  li    $t9, 1
/* 0CBD70 7F097240 AFB90014 */  sw    $t9, 0x14($sp)
/* 0CBD74 7F097244 02203825 */  move  $a3, $s1
/* 0CBD78 7F097248 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBD7C 7F09724C 02002825 */  move  $a1, $s0
/* 0CBD80 7F097250 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBD84 7F097254 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBD88 7F097258 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0CBD8C 7F09725C 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBD90 7F097260 44813000 */  mtc1  $at, $f6
/* 0CBD94 7F097264 240D0001 */  li    $t5, 1
/* 0CBD98 7F097268 AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CBD9C 7F09726C AFAD0014 */  sw    $t5, 0x14($sp)
/* 0CBDA0 7F097270 00402025 */  move  $a0, $v0
/* 0CBDA4 7F097274 02202825 */  move  $a1, $s1
/* 0CBDA8 7F097278 27A600FC */  addiu $a2, $sp, 0xfc
/* 0CBDAC 7F09727C 02003825 */  move  $a3, $s0
/* 0CBDB0 7F097280 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBDB4 7F097284 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0CBDB8 7F097288 10000034 */  b     .L7F09735C
/* 0CBDBC 7F09728C AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F097290:
/* 0CBDC0 7F097290 24010005 */  li    $at, 5
/* 0CBDC4 7F097294 16210024 */  bne   $s1, $at, .L7F097328
/* 0CBDC8 7F097298 27B0008C */   addiu $s0, $sp, 0x8c
/* 0CBDCC 7F09729C 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBDD0 7F0972A0 44814000 */  mtc1  $at, $f8
/* 0CBDD4 7F0972A4 240B0001 */  li    $t3, 1
/* 0CBDD8 7F0972A8 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0CBDDC 7F0972AC 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBDE0 7F0972B0 02002825 */  move  $a1, $s0
/* 0CBDE4 7F0972B4 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBDE8 7F0972B8 27A700FC */  addiu $a3, $sp, 0xfc
/* 0CBDEC 7F0972BC 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBDF0 7F0972C0 E7A80010 */   swc1  $f8, 0x10($sp)
/* 0CBDF4 7F0972C4 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBDF8 7F0972C8 44815000 */  mtc1  $at, $f10
/* 0CBDFC 7F0972CC 27B10134 */  addiu $s1, $sp, 0x134
/* 0CBE00 7F0972D0 240E0001 */  li    $t6, 1
/* 0CBE04 7F0972D4 AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CBE08 7F0972D8 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0CBE0C 7F0972DC 02203825 */  move  $a3, $s1
/* 0CBE10 7F0972E0 00402025 */  move  $a0, $v0
/* 0CBE14 7F0972E4 02002825 */  move  $a1, $s0
/* 0CBE18 7F0972E8 27A600FC */  addiu $a2, $sp, 0xfc
/* 0CBE1C 7F0972EC 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBE20 7F0972F0 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0CBE24 7F0972F4 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBE28 7F0972F8 44812000 */  mtc1  $at, $f4
/* 0CBE2C 7F0972FC 240A0001 */  li    $t2, 1
/* 0CBE30 7F097300 AFA206B0 */  sw    $v0, 0x6b0($sp)
/* 0CBE34 7F097304 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0CBE38 7F097308 00402025 */  move  $a0, $v0
/* 0CBE3C 7F09730C 02002825 */  move  $a1, $s0
/* 0CBE40 7F097310 02203025 */  move  $a2, $s1
/* 0CBE44 7F097314 27A7016C */  addiu $a3, $sp, 0x16c
/* 0CBE48 7F097318 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBE4C 7F09731C E7A40010 */   swc1  $f4, 0x10($sp)
/* 0CBE50 7F097320 1000000E */  b     .L7F09735C
/* 0CBE54 7F097324 AFA206B0 */   sw    $v0, 0x6b0($sp)
.L7F097328:
/* 0CBE58 7F097328 24010003 */  li    $at, 3
/* 0CBE5C 7F09732C 1621000B */  bne   $s1, $at, .L7F09735C
/* 0CBE60 7F097330 27A5008C */   addiu $a1, $sp, 0x8c
/* 0CBE64 7F097334 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0CBE68 7F097338 44813000 */  mtc1  $at, $f6
/* 0CBE6C 7F09733C 24180001 */  li    $t8, 1
/* 0CBE70 7F097340 AFB80014 */  sw    $t8, 0x14($sp)
/* 0CBE74 7F097344 8FA406B0 */  lw    $a0, 0x6b0($sp)
/* 0CBE78 7F097348 27A600C4 */  addiu $a2, $sp, 0xc4
/* 0CBE7C 7F09734C 27A700FC */  addiu $a3, $sp, 0xfc
/* 0CBE80 7F097350 0FC25E06 */  jal   sub_GAME_7F097818
/* 0CBE84 7F097354 E7A60010 */   swc1  $f6, 0x10($sp)
/* 0CBE88 7F097358 AFA206B0 */  sw    $v0, 0x6b0($sp)
.L7F09735C:
/* 0CBE8C 7F09735C 8FA206B0 */  lw    $v0, 0x6b0($sp)
.L7F097360:
/* 0CBE90 7F097360 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0CBE94 7F097364 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0CBE98 7F097368 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0CBE9C 7F09736C D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0CBEA0 7F097370 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0CBEA4 7F097374 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0CBEA8 7F097378 8FB00044 */  lw    $s0, 0x44($sp)
/* 0CBEAC 7F09737C 8FB10048 */  lw    $s1, 0x48($sp)
/* 0CBEB0 7F097380 03E00008 */  jr    $ra
/* 0CBEB4 7F097384 27BD06B0 */   addiu $sp, $sp, 0x6b0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F097388(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F097388
/* 0CBEB8 7F097388 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0CBEBC 7F09738C 30CEFFFF */  andi  $t6, $a2, 0xffff
/* 0CBEC0 7F097390 448E2000 */  mtc1  $t6, $f4
/* 0CBEC4 7F097394 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 0CBEC8 7F097398 44816000 */  mtc1  $at, $f12
/* 0CBECC 7F09739C AFB00020 */  sw    $s0, 0x20($sp)
/* 0CBED0 7F0973A0 44877000 */  mtc1  $a3, $f14
/* 0CBED4 7F0973A4 00808025 */  move  $s0, $a0
/* 0CBED8 7F0973A8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0CBEDC 7F0973AC F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0CBEE0 7F0973B0 AFA60080 */  sw    $a2, 0x80($sp)
/* 0CBEE4 7F0973B4 05C10005 */  bgez  $t6, .L7F0973CC
/* 0CBEE8 7F0973B8 468021A0 */   cvt.s.w $f6, $f4
/* 0CBEEC 7F0973BC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CBEF0 7F0973C0 44814000 */  mtc1  $at, $f8
/* 0CBEF4 7F0973C4 00000000 */  nop
/* 0CBEF8 7F0973C8 46083180 */  add.s $f6, $f6, $f8
.L7F0973CC:
/* 0CBEFC 7F0973CC C60A0000 */  lwc1  $f10, ($s0)
/* 0CBF00 7F0973D0 C4B20000 */  lwc1  $f18, ($a1)
/* 0CBF04 7F0973D4 460C3003 */  div.s $f0, $f6, $f12
/* 0CBF08 7F0973D8 C4A60010 */  lwc1  $f6, 0x10($a1)
/* 0CBF0C 7F0973DC C6080004 */  lwc1  $f8, 4($s0)
/* 0CBF10 7F0973E0 44808000 */  mtc1  $zero, $f16
/* 0CBF14 7F0973E4 46125102 */  mul.s $f4, $f10, $f18
/* 0CBF18 7F0973E8 00000000 */  nop
/* 0CBF1C 7F0973EC 46064282 */  mul.s $f10, $f8, $f6
/* 0CBF20 7F0973F0 C4A60020 */  lwc1  $f6, 0x20($a1)
/* 0CBF24 7F0973F4 C6080008 */  lwc1  $f8, 8($s0)
/* 0CBF28 7F0973F8 460A2480 */  add.s $f18, $f4, $f10
/* 0CBF2C 7F0973FC 46064102 */  mul.s $f4, $f8, $f6
/* 0CBF30 7F097400 C4A80030 */  lwc1  $f8, 0x30($a1)
/* 0CBF34 7F097404 46000086 */  mov.s $f2, $f0
/* 0CBF38 7F097408 46049280 */  add.s $f10, $f18, $f4
/* 0CBF3C 7F09740C 460A4180 */  add.s $f6, $f8, $f10
/* 0CBF40 7F097410 E7A60068 */  swc1  $f6, 0x68($sp)
/* 0CBF44 7F097414 C6120000 */  lwc1  $f18, ($s0)
/* 0CBF48 7F097418 C4A40004 */  lwc1  $f4, 4($a1)
/* 0CBF4C 7F09741C C60A0004 */  lwc1  $f10, 4($s0)
/* 0CBF50 7F097420 C4A60014 */  lwc1  $f6, 0x14($a1)
/* 0CBF54 7F097424 46049202 */  mul.s $f8, $f18, $f4
/* 0CBF58 7F097428 00000000 */  nop
/* 0CBF5C 7F09742C 46065482 */  mul.s $f18, $f10, $f6
/* 0CBF60 7F097430 C4A60024 */  lwc1  $f6, 0x24($a1)
/* 0CBF64 7F097434 C60A0008 */  lwc1  $f10, 8($s0)
/* 0CBF68 7F097438 46124100 */  add.s $f4, $f8, $f18
/* 0CBF6C 7F09743C 46065202 */  mul.s $f8, $f10, $f6
/* 0CBF70 7F097440 C4AA0034 */  lwc1  $f10, 0x34($a1)
/* 0CBF74 7F097444 46082480 */  add.s $f18, $f4, $f8
/* 0CBF78 7F097448 46125180 */  add.s $f6, $f10, $f18
/* 0CBF7C 7F09744C E7A6006C */  swc1  $f6, 0x6c($sp)
/* 0CBF80 7F097450 C6040000 */  lwc1  $f4, ($s0)
/* 0CBF84 7F097454 C4A80008 */  lwc1  $f8, 8($a1)
/* 0CBF88 7F097458 C6120004 */  lwc1  $f18, 4($s0)
/* 0CBF8C 7F09745C C4A60018 */  lwc1  $f6, 0x18($a1)
/* 0CBF90 7F097460 46082282 */  mul.s $f10, $f4, $f8
/* 0CBF94 7F097464 00000000 */  nop
/* 0CBF98 7F097468 46069102 */  mul.s $f4, $f18, $f6
/* 0CBF9C 7F09746C C4A60028 */  lwc1  $f6, 0x28($a1)
/* 0CBFA0 7F097470 C6120008 */  lwc1  $f18, 8($s0)
/* 0CBFA4 7F097474 46045200 */  add.s $f8, $f10, $f4
/* 0CBFA8 7F097478 46069282 */  mul.s $f10, $f18, $f6
/* 0CBFAC 7F09747C C4B20038 */  lwc1  $f18, 0x38($a1)
/* 0CBFB0 7F097480 460A4100 */  add.s $f4, $f8, $f10
/* 0CBFB4 7F097484 46049180 */  add.s $f6, $f18, $f4
/* 0CBFB8 7F097488 E7A60070 */  swc1  $f6, 0x70($sp)
/* 0CBFBC 7F09748C C4AA000C */  lwc1  $f10, 0xc($a1)
/* 0CBFC0 7F097490 C6080000 */  lwc1  $f8, ($s0)
/* 0CBFC4 7F097494 C4A6001C */  lwc1  $f6, 0x1c($a1)
/* 0CBFC8 7F097498 C6040004 */  lwc1  $f4, 4($s0)
/* 0CBFCC 7F09749C 460A4482 */  mul.s $f18, $f8, $f10
/* 0CBFD0 7F0974A0 00000000 */  nop
/* 0CBFD4 7F0974A4 46062202 */  mul.s $f8, $f4, $f6
/* 0CBFD8 7F0974A8 C4A6002C */  lwc1  $f6, 0x2c($a1)
/* 0CBFDC 7F0974AC C6040008 */  lwc1  $f4, 8($s0)
/* 0CBFE0 7F0974B0 46089280 */  add.s $f10, $f18, $f8
/* 0CBFE4 7F0974B4 46062482 */  mul.s $f18, $f4, $f6
/* 0CBFE8 7F0974B8 C4A4003C */  lwc1  $f4, 0x3c($a1)
/* 0CBFEC 7F0974BC 46125200 */  add.s $f8, $f10, $f18
/* 0CBFF0 7F0974C0 460C7483 */  div.s $f18, $f14, $f12
/* 0CBFF4 7F0974C4 46082180 */  add.s $f6, $f4, $f8
/* 0CBFF8 7F0974C8 E7A60074 */  swc1  $f6, 0x74($sp)
/* 0CBFFC 7F0974CC C60A000C */  lwc1  $f10, 0xc($s0)
/* 0CC000 7F0974D0 C7A60088 */  lwc1  $f6, 0x88($sp)
/* 0CC004 7F0974D4 46125102 */  mul.s $f4, $f10, $f18
/* 0CC008 7F0974D8 460C3283 */  div.s $f10, $f6, $f12
/* 0CC00C 7F0974DC E7A40060 */  swc1  $f4, 0x60($sp)
/* 0CC010 7F0974E0 C6080010 */  lwc1  $f8, 0x10($s0)
/* 0CC014 7F0974E4 C7A40074 */  lwc1  $f4, 0x74($sp)
/* 0CC018 7F0974E8 46048032 */  c.eq.s $f16, $f4
/* 0CC01C 7F0974EC 460A4482 */  mul.s $f18, $f8, $f10
/* 0CC020 7F0974F0 E7B20064 */  swc1  $f18, 0x64($sp)
/* 0CC024 7F0974F4 45000004 */  bc1f  .L7F097508
/* 0CC028 7F0974F8 C7B20068 */   lwc1  $f18, 0x68($sp)
/* 0CC02C 7F0974FC 3C018005 */  lui   $at, %hi(D_800575D4)
/* 0CC030 7F097500 10000006 */  b     .L7F09751C
/* 0CC034 7F097504 C43475D4 */   lwc1  $f20, %lo(D_800575D4)($at)
.L7F097508:
/* 0CC038 7F097508 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0CC03C 7F09750C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CC040 7F097510 44813000 */  mtc1  $at, $f6
/* 0CC044 7F097514 46004282 */  mul.s $f10, $f8, $f0
/* 0CC048 7F097518 460A3503 */  div.s $f20, $f6, $f10
.L7F09751C:
/* 0CC04C 7F09751C 4610A03C */  c.lt.s $f20, $f16
/* 0CC050 7F097520 4600A006 */  mov.s $f0, $f20
/* 0CC054 7F097524 45000002 */  bc1f  .L7F097530
/* 0CC058 7F097528 3C018005 */   lui   $at, %hi(D_800575D8)
/* 0CC05C 7F09752C C42075D8 */  lwc1  $f0, %lo(D_800575D8)($at)
.L7F097530:
/* 0CC060 7F097530 46009102 */  mul.s $f4, $f18, $f0
/* 0CC064 7F097534 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 0CC068 7F097538 46022202 */  mul.s $f8, $f4, $f2
/* 0CC06C 7F09753C C7A40070 */  lwc1  $f4, 0x70($sp)
/* 0CC070 7F097540 46003282 */  mul.s $f10, $f6, $f0
/* 0CC074 7F097544 E7A80048 */  swc1  $f8, 0x48($sp)
/* 0CC078 7F097548 46025482 */  mul.s $f18, $f10, $f2
/* 0CC07C 7F09754C C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 0CC080 7F097550 46002202 */  mul.s $f8, $f4, $f0
/* 0CC084 7F097554 E7B2004C */  swc1  $f18, 0x4c($sp)
/* 0CC088 7F097558 46024182 */  mul.s $f6, $f8, $f2
/* 0CC08C 7F09755C 00000000 */  nop
/* 0CC090 7F097560 46005482 */  mul.s $f18, $f10, $f0
/* 0CC094 7F097564 E7A60050 */  swc1  $f6, 0x50($sp)
/* 0CC098 7F097568 46029102 */  mul.s $f4, $f18, $f2
/* 0CC09C 7F09756C 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CC0A0 7F097570 E7A40054 */   swc1  $f4, 0x54($sp)
/* 0CC0A4 7F097574 0FC1E129 */  jal   getPlayer_c_screenwidth
/* 0CC0A8 7F097578 E7A0002C */   swc1  $f0, 0x2c($sp)
/* 0CC0AC 7F09757C 0FC1E131 */  jal   getPlayer_c_screenleft
/* 0CC0B0 7F097580 E7A00030 */   swc1  $f0, 0x30($sp)
/* 0CC0B4 7F097584 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0CC0B8 7F097588 44811000 */  mtc1  $at, $f2
/* 0CC0BC 7F09758C 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CC0C0 7F097590 44814000 */  mtc1  $at, $f8
/* 0CC0C4 7F097594 C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 0CC0C8 7F097598 46080182 */  mul.s $f6, $f0, $f8
/* 0CC0CC 7F09759C C7A80048 */  lwc1  $f8, 0x48($sp)
/* 0CC0D0 7F0975A0 46025482 */  mul.s $f18, $f10, $f2
/* 0CC0D4 7F0975A4 C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 0CC0D8 7F0975A8 46123100 */  add.s $f4, $f6, $f18
/* 0CC0DC 7F0975AC 46025182 */  mul.s $f6, $f10, $f2
/* 0CC0E0 7F0975B0 00000000 */  nop
/* 0CC0E4 7F0975B4 46064482 */  mul.s $f18, $f8, $f6
/* 0CC0E8 7F0975B8 46122280 */  add.s $f10, $f4, $f18
/* 0CC0EC 7F0975BC 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CC0F0 7F0975C0 E7AA0038 */   swc1  $f10, 0x38($sp)
/* 0CC0F4 7F0975C4 0FC1E12D */  jal   getPlayer_c_screenheight
/* 0CC0F8 7F0975C8 E7A0002C */   swc1  $f0, 0x2c($sp)
/* 0CC0FC 7F0975CC 0FC1E135 */  jal   getPlayer_c_screentop
/* 0CC100 7F0975D0 E7A00030 */   swc1  $f0, 0x30($sp)
/* 0CC104 7F0975D4 3C018005 */  lui   $at, %hi(D_800575DC)
/* 0CC108 7F0975D8 C42275DC */  lwc1  $f2, %lo(D_800575DC)($at)
/* 0CC10C 7F0975DC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0CC110 7F0975E0 44818000 */  mtc1  $at, $f16
/* 0CC114 7F0975E4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CC118 7F0975E8 44814000 */  mtc1  $at, $f8
/* 0CC11C 7F0975EC C7A40030 */  lwc1  $f4, 0x30($sp)
/* 0CC120 7F0975F0 3C018005 */  lui   $at, %hi(D_800575E0)
/* 0CC124 7F0975F4 46080182 */  mul.s $f6, $f0, $f8
/* 0CC128 7F0975F8 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 0CC12C 7F0975FC 3C06457F */  lui   $a2, (0x457FA000 >> 16) # lui $a2, 0x457f
/* 0CC130 7F097600 46102482 */  mul.s $f18, $f4, $f16
/* 0CC134 7F097604 46004107 */  neg.s $f4, $f8
/* 0CC138 7F097608 34C6A000 */  ori   $a2, (0x457FA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CC13C 7F09760C C42E75E0 */  lwc1  $f14, %lo(D_800575E0)($at)
/* 0CC140 7F097610 C7AC0038 */  lwc1  $f12, 0x38($sp)
/* 0CC144 7F097614 46123280 */  add.s $f10, $f6, $f18
/* 0CC148 7F097618 C7A6002C */  lwc1  $f6, 0x2c($sp)
/* 0CC14C 7F09761C 46103482 */  mul.s $f18, $f6, $f16
/* 0CC150 7F097620 00000000 */  nop
/* 0CC154 7F097624 46122202 */  mul.s $f8, $f4, $f18
/* 0CC158 7F097628 C7A40050 */  lwc1  $f4, 0x50($sp)
/* 0CC15C 7F09762C 46022482 */  mul.s $f18, $f4, $f2
/* 0CC160 7F097630 46085180 */  add.s $f6, $f10, $f8
/* 0CC164 7F097634 C7A80054 */  lwc1  $f8, 0x54($sp)
/* 0CC168 7F097638 46029280 */  add.s $f10, $f18, $f2
/* 0CC16C 7F09763C E7A6003C */  swc1  $f6, 0x3c($sp)
/* 0CC170 7F097640 44803000 */  mtc1  $zero, $f6
/* 0CC174 7F097644 E7AA0040 */  swc1  $f10, 0x40($sp)
/* 0CC178 7F097648 46064102 */  mul.s $f4, $f8, $f6
/* 0CC17C 7F09764C 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC180 7F097650 E7A40044 */   swc1  $f4, 0x44($sp)
/* 0CC184 7F097654 3C018005 */  lui   $at, %hi(D_800575E4)
/* 0CC188 7F097658 3C06457F */  lui   $a2, (0x457FA000 >> 16) # lui $a2, 0x457f
/* 0CC18C 7F09765C E7A00038 */  swc1  $f0, 0x38($sp)
/* 0CC190 7F097660 34C6A000 */  ori   $a2, (0x457FA000 & 0xFFFF) # ori $a2, $a2, 0xa000
/* 0CC194 7F097664 C42E75E4 */  lwc1  $f14, %lo(D_800575E4)($at)
/* 0CC198 7F097668 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC19C 7F09766C C7AC003C */   lwc1  $f12, 0x3c($sp)
/* 0CC1A0 7F097670 44807000 */  mtc1  $zero, $f14
/* 0CC1A4 7F097674 3C0646FF */  lui   $a2, (0x46FFFE00 >> 16) # lui $a2, 0x46ff
/* 0CC1A8 7F097678 E7A0003C */  swc1  $f0, 0x3c($sp)
/* 0CC1AC 7F09767C 34C6FE00 */  ori   $a2, (0x46FFFE00 & 0xFFFF) # ori $a2, $a2, 0xfe00
/* 0CC1B0 7F097680 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC1B4 7F097684 C7AC0040 */   lwc1  $f12, 0x40($sp)
/* 0CC1B8 7F097688 44807000 */  mtc1  $zero, $f14
/* 0CC1BC 7F09768C 3C0646FF */  lui   $a2, (0x46FFFE00 >> 16) # lui $a2, 0x46ff
/* 0CC1C0 7F097690 E7A00040 */  swc1  $f0, 0x40($sp)
/* 0CC1C4 7F097694 34C6FE00 */  ori   $a2, (0x46FFFE00 & 0xFFFF) # ori $a2, $a2, 0xfe00
/* 0CC1C8 7F097698 0FC24F12 */  jal   sub_GAME_7F093C48
/* 0CC1CC 7F09769C C7AC0044 */   lwc1  $f12, 0x44($sp)
/* 0CC1D0 7F0976A0 8FA3008C */  lw    $v1, 0x8c($sp)
/* 0CC1D4 7F0976A4 C7B20068 */  lwc1  $f18, 0x68($sp)
/* 0CC1D8 7F0976A8 E7A00044 */  swc1  $f0, 0x44($sp)
/* 0CC1DC 7F0976AC E4720000 */  swc1  $f18, ($v1)
/* 0CC1E0 7F0976B0 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 0CC1E4 7F0976B4 E46A0004 */  swc1  $f10, 4($v1)
/* 0CC1E8 7F0976B8 C7A80070 */  lwc1  $f8, 0x70($sp)
/* 0CC1EC 7F0976BC E4680008 */  swc1  $f8, 8($v1)
/* 0CC1F0 7F0976C0 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 0CC1F4 7F0976C4 E466000C */  swc1  $f6, 0xc($v1)
/* 0CC1F8 7F0976C8 C7A40060 */  lwc1  $f4, 0x60($sp)
/* 0CC1FC 7F0976CC E4640020 */  swc1  $f4, 0x20($v1)
/* 0CC200 7F0976D0 C7B20064 */  lwc1  $f18, 0x64($sp)
/* 0CC204 7F0976D4 E4720024 */  swc1  $f18, 0x24($v1)
/* 0CC208 7F0976D8 C7AA0038 */  lwc1  $f10, 0x38($sp)
/* 0CC20C 7F0976DC 0FC2E9CB */  jal   fogGetCurrentEnvironmentp
/* 0CC210 7F0976E0 E46A0028 */   swc1  $f10, 0x28($v1)
/* 0CC214 7F0976E4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0CC218 7F0976E8 44813000 */  mtc1  $at, $f6
/* 0CC21C 7F0976EC C4480038 */  lwc1  $f8, 0x38($v0)
/* 0CC220 7F0976F0 C7B2003C */  lwc1  $f18, 0x3c($sp)
/* 0CC224 7F0976F4 8FA3008C */  lw    $v1, 0x8c($sp)
/* 0CC228 7F0976F8 46064102 */  mul.s $f4, $f8, $f6
/* 0CC22C 7F0976FC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CC230 7F097700 46049281 */  sub.s $f10, $f18, $f4
/* 0CC234 7F097704 E46A002C */  swc1  $f10, 0x2c($v1)
/* 0CC238 7F097708 C7A80040 */  lwc1  $f8, 0x40($sp)
/* 0CC23C 7F09770C E4740034 */  swc1  $f20, 0x34($v1)
/* 0CC240 7F097710 E4680030 */  swc1  $f8, 0x30($v1)
/* 0CC244 7F097714 920F0014 */  lbu   $t7, 0x14($s0)
/* 0CC248 7F097718 448F3000 */  mtc1  $t7, $f6
/* 0CC24C 7F09771C 05E10004 */  bgez  $t7, .L7F097730
/* 0CC250 7F097720 468034A0 */   cvt.s.w $f18, $f6
/* 0CC254 7F097724 44812000 */  mtc1  $at, $f4
/* 0CC258 7F097728 00000000 */  nop
/* 0CC25C 7F09772C 46049480 */  add.s $f18, $f18, $f4
.L7F097730:
/* 0CC260 7F097730 E4720010 */  swc1  $f18, 0x10($v1)
/* 0CC264 7F097734 92180015 */  lbu   $t8, 0x15($s0)
/* 0CC268 7F097738 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CC26C 7F09773C 44985000 */  mtc1  $t8, $f10
/* 0CC270 7F097740 07010004 */  bgez  $t8, .L7F097754
/* 0CC274 7F097744 46805220 */   cvt.s.w $f8, $f10
/* 0CC278 7F097748 44813000 */  mtc1  $at, $f6
/* 0CC27C 7F09774C 00000000 */  nop
/* 0CC280 7F097750 46064200 */  add.s $f8, $f8, $f6
.L7F097754:
/* 0CC284 7F097754 E4680014 */  swc1  $f8, 0x14($v1)
/* 0CC288 7F097758 92190016 */  lbu   $t9, 0x16($s0)
/* 0CC28C 7F09775C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CC290 7F097760 44992000 */  mtc1  $t9, $f4
/* 0CC294 7F097764 07210004 */  bgez  $t9, .L7F097778
/* 0CC298 7F097768 468024A0 */   cvt.s.w $f18, $f4
/* 0CC29C 7F09776C 44815000 */  mtc1  $at, $f10
/* 0CC2A0 7F097770 00000000 */  nop
/* 0CC2A4 7F097774 460A9480 */  add.s $f18, $f18, $f10
.L7F097778:
/* 0CC2A8 7F097778 E4720018 */  swc1  $f18, 0x18($v1)
/* 0CC2AC 7F09777C 92080017 */  lbu   $t0, 0x17($s0)
/* 0CC2B0 7F097780 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0CC2B4 7F097784 44883000 */  mtc1  $t0, $f6
/* 0CC2B8 7F097788 05010004 */  bgez  $t0, .L7F09779C
/* 0CC2BC 7F09778C 46803220 */   cvt.s.w $f8, $f6
/* 0CC2C0 7F097790 44812000 */  mtc1  $at, $f4
/* 0CC2C4 7F097794 00000000 */  nop
/* 0CC2C8 7F097798 46044200 */  add.s $f8, $f8, $f4
.L7F09779C:
/* 0CC2CC 7F09779C E468001C */  swc1  $f8, 0x1c($v1)
/* 0CC2D0 7F0977A0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0CC2D4 7F0977A4 8FB00020 */  lw    $s0, 0x20($sp)
/* 0CC2D8 7F0977A8 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0CC2DC 7F0977AC 03E00008 */  jr    $ra
/* 0CC2E0 7F0977B0 27BD0078 */   addiu $sp, $sp, 0x78
)
#endif


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
