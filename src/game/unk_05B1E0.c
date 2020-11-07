#include "ultra64.h"


// data
//D:80032430
s32 D_80032430 = 1;
//D:80032434
s32 D_80032434 = 2;


// rodata

typedef f32 Quaternion[4]; // w, x, y, z
typedef f32 mat44[4][4];
typedef f32 vec3[3];

#ifdef NONMATCHING
void sub_GAME_7F05B1E0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80053740
.word 0x38c90fdb /*0.000095873802*/
glabel D_80053744
.word 0xbf7fff58 /*-0.99998999*/
.text
glabel sub_GAME_7F05B1E0
/* 08FD10 7F05B1E0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 08FD14 7F05B1E4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 08FD18 7F05B1E8 AFB00028 */  sw    $s0, 0x28($sp)
/* 08FD1C 7F05B1EC F7B60020 */  sdc1  $f22, 0x20($sp)
/* 08FD20 7F05B1F0 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 08FD24 7F05B1F4 AFA5004C */  sw    $a1, 0x4c($sp)
/* 08FD28 7F05B1F8 948E0000 */  lhu   $t6, ($a0)
/* 08FD2C 7F05B1FC 3C018005 */  lui   $at, %hi(D_80053740)
/* 08FD30 7F05B200 C4343740 */  lwc1  $f20, %lo(D_80053740)($at)
/* 08FD34 7F05B204 448E2000 */  mtc1  $t6, $f4
/* 08FD38 7F05B208 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 08FD3C 7F05B20C 4481B000 */  mtc1  $at, $f22
/* 08FD40 7F05B210 00808025 */  move  $s0, $a0
/* 08FD44 7F05B214 05C10005 */  bgez  $t6, .L7F05B22C
/* 08FD48 7F05B218 468021A0 */   cvt.s.w $f6, $f4
/* 08FD4C 7F05B21C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08FD50 7F05B220 44814000 */  mtc1  $at, $f8
/* 08FD54 7F05B224 00000000 */  nop   
/* 08FD58 7F05B228 46083180 */  add.s $f6, $f6, $f8
.L7F05B22C:
/* 08FD5C 7F05B22C 46143282 */  mul.s $f10, $f6, $f20
/* 08FD60 7F05B230 00000000 */  nop   
/* 08FD64 7F05B234 46165302 */  mul.s $f12, $f10, $f22
/* 08FD68 7F05B238 0FC15FA8 */  jal   cosf
/* 08FD6C 7F05B23C 00000000 */   nop   
/* 08FD70 7F05B240 E7A00044 */  swc1  $f0, 0x44($sp)
/* 08FD74 7F05B244 960F0000 */  lhu   $t7, ($s0)
/* 08FD78 7F05B248 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08FD7C 7F05B24C 448F2000 */  mtc1  $t7, $f4
/* 08FD80 7F05B250 05E10004 */  bgez  $t7, .L7F05B264
/* 08FD84 7F05B254 46802220 */   cvt.s.w $f8, $f4
/* 08FD88 7F05B258 44813000 */  mtc1  $at, $f6
/* 08FD8C 7F05B25C 00000000 */  nop   
/* 08FD90 7F05B260 46064200 */  add.s $f8, $f8, $f6
.L7F05B264:
/* 08FD94 7F05B264 46144282 */  mul.s $f10, $f8, $f20
/* 08FD98 7F05B268 00000000 */  nop   
/* 08FD9C 7F05B26C 46165302 */  mul.s $f12, $f10, $f22
/* 08FDA0 7F05B270 0FC15FAB */  jal   sinf
/* 08FDA4 7F05B274 00000000 */   nop   
/* 08FDA8 7F05B278 E7A00040 */  swc1  $f0, 0x40($sp)
/* 08FDAC 7F05B27C 96180002 */  lhu   $t8, 2($s0)
/* 08FDB0 7F05B280 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08FDB4 7F05B284 44982000 */  mtc1  $t8, $f4
/* 08FDB8 7F05B288 07010004 */  bgez  $t8, .L7F05B29C
/* 08FDBC 7F05B28C 468021A0 */   cvt.s.w $f6, $f4
/* 08FDC0 7F05B290 44814000 */  mtc1  $at, $f8
/* 08FDC4 7F05B294 00000000 */  nop   
/* 08FDC8 7F05B298 46083180 */  add.s $f6, $f6, $f8
.L7F05B29C:
/* 08FDCC 7F05B29C 46143282 */  mul.s $f10, $f6, $f20
/* 08FDD0 7F05B2A0 00000000 */  nop   
/* 08FDD4 7F05B2A4 46165302 */  mul.s $f12, $f10, $f22
/* 08FDD8 7F05B2A8 0FC15FA8 */  jal   cosf
/* 08FDDC 7F05B2AC 00000000 */   nop   
/* 08FDE0 7F05B2B0 E7A0003C */  swc1  $f0, 0x3c($sp)
/* 08FDE4 7F05B2B4 96190002 */  lhu   $t9, 2($s0)
/* 08FDE8 7F05B2B8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08FDEC 7F05B2BC 44992000 */  mtc1  $t9, $f4
/* 08FDF0 7F05B2C0 07210004 */  bgez  $t9, .L7F05B2D4
/* 08FDF4 7F05B2C4 46802220 */   cvt.s.w $f8, $f4
/* 08FDF8 7F05B2C8 44813000 */  mtc1  $at, $f6
/* 08FDFC 7F05B2CC 00000000 */  nop   
/* 08FE00 7F05B2D0 46064200 */  add.s $f8, $f8, $f6
.L7F05B2D4:
/* 08FE04 7F05B2D4 46144282 */  mul.s $f10, $f8, $f20
/* 08FE08 7F05B2D8 00000000 */  nop   
/* 08FE0C 7F05B2DC 46165302 */  mul.s $f12, $f10, $f22
/* 08FE10 7F05B2E0 0FC15FAB */  jal   sinf
/* 08FE14 7F05B2E4 00000000 */   nop   
/* 08FE18 7F05B2E8 E7A00038 */  swc1  $f0, 0x38($sp)
/* 08FE1C 7F05B2EC 96080004 */  lhu   $t0, 4($s0)
/* 08FE20 7F05B2F0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08FE24 7F05B2F4 44882000 */  mtc1  $t0, $f4
/* 08FE28 7F05B2F8 05010004 */  bgez  $t0, .L7F05B30C
/* 08FE2C 7F05B2FC 468021A0 */   cvt.s.w $f6, $f4
/* 08FE30 7F05B300 44814000 */  mtc1  $at, $f8
/* 08FE34 7F05B304 00000000 */  nop   
/* 08FE38 7F05B308 46083180 */  add.s $f6, $f6, $f8
.L7F05B30C:
/* 08FE3C 7F05B30C 46143282 */  mul.s $f10, $f6, $f20
/* 08FE40 7F05B310 00000000 */  nop   
/* 08FE44 7F05B314 46165302 */  mul.s $f12, $f10, $f22
/* 08FE48 7F05B318 0FC15FA8 */  jal   cosf
/* 08FE4C 7F05B31C 00000000 */   nop   
/* 08FE50 7F05B320 96090004 */  lhu   $t1, 4($s0)
/* 08FE54 7F05B324 46000486 */  mov.s $f18, $f0
/* 08FE58 7F05B328 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08FE5C 7F05B32C 44892000 */  mtc1  $t1, $f4
/* 08FE60 7F05B330 05210004 */  bgez  $t1, .L7F05B344
/* 08FE64 7F05B334 46802220 */   cvt.s.w $f8, $f4
/* 08FE68 7F05B338 44813000 */  mtc1  $at, $f6
/* 08FE6C 7F05B33C 00000000 */  nop   
/* 08FE70 7F05B340 46064200 */  add.s $f8, $f8, $f6
.L7F05B344:
/* 08FE74 7F05B344 46144282 */  mul.s $f10, $f8, $f20
/* 08FE78 7F05B348 E7B20034 */  swc1  $f18, 0x34($sp)
/* 08FE7C 7F05B34C 46165302 */  mul.s $f12, $f10, $f22
/* 08FE80 7F05B350 0FC15FAB */  jal   sinf
/* 08FE84 7F05B354 00000000 */   nop   
/* 08FE88 7F05B358 C7B6003C */  lwc1  $f22, 0x3c($sp)
/* 08FE8C 7F05B35C C7A40044 */  lwc1  $f4, 0x44($sp)
/* 08FE90 7F05B360 C7B40040 */  lwc1  $f20, 0x40($sp)
/* 08FE94 7F05B364 C7A60038 */  lwc1  $f6, 0x38($sp)
/* 08FE98 7F05B368 46162082 */  mul.s $f2, $f4, $f22
/* 08FE9C 7F05B36C C7B20034 */  lwc1  $f18, 0x34($sp)
/* 08FEA0 7F05B370 8FA2004C */  lw    $v0, 0x4c($sp)
/* 08FEA4 7F05B374 4606A402 */  mul.s $f16, $f20, $f6
/* 08FEA8 7F05B378 00000000 */  nop   
/* 08FEAC 7F05B37C 46121202 */  mul.s $f8, $f2, $f18
/* 08FEB0 7F05B380 00000000 */  nop   
/* 08FEB4 7F05B384 46008282 */  mul.s $f10, $f16, $f0
/* 08FEB8 7F05B388 460A4100 */  add.s $f4, $f8, $f10
/* 08FEBC 7F05B38C 4616A382 */  mul.s $f14, $f20, $f22
/* 08FEC0 7F05B390 E4440000 */  swc1  $f4, ($v0)
/* 08FEC4 7F05B394 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 08FEC8 7F05B398 C7A60044 */  lwc1  $f6, 0x44($sp)
/* 08FECC 7F05B39C 46083302 */  mul.s $f12, $f6, $f8
/* 08FED0 7F05B3A0 00000000 */  nop   
/* 08FED4 7F05B3A4 46127282 */  mul.s $f10, $f14, $f18
/* 08FED8 7F05B3A8 00000000 */  nop   
/* 08FEDC 7F05B3AC 46006102 */  mul.s $f4, $f12, $f0
/* 08FEE0 7F05B3B0 46045181 */  sub.s $f6, $f10, $f4
/* 08FEE4 7F05B3B4 46126202 */  mul.s $f8, $f12, $f18
/* 08FEE8 7F05B3B8 00000000 */  nop   
/* 08FEEC 7F05B3BC 46007282 */  mul.s $f10, $f14, $f0
/* 08FEF0 7F05B3C0 E4460004 */  swc1  $f6, 4($v0)
/* 08FEF4 7F05B3C4 46001182 */  mul.s $f6, $f2, $f0
/* 08FEF8 7F05B3C8 460A4100 */  add.s $f4, $f8, $f10
/* 08FEFC 7F05B3CC 46128202 */  mul.s $f8, $f16, $f18
/* 08FF00 7F05B3D0 E4440008 */  swc1  $f4, 8($v0)
/* 08FF04 7F05B3D4 46083281 */  sub.s $f10, $f6, $f8
/* 08FF08 7F05B3D8 E44A000C */  swc1  $f10, 0xc($v0)
/* 08FF0C 7F05B3DC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 08FF10 7F05B3E0 8FB00028 */  lw    $s0, 0x28($sp)
/* 08FF14 7F05B3E4 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 08FF18 7F05B3E8 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 08FF1C 7F05B3EC 03E00008 */  jr    $ra
/* 08FF20 7F05B3F0 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif

void quaternion_set_rotation_around_xyz(vec3 angles, Quaternion q) {
    f32 cos_x = cosf(angles[0] * 0.5f);
    f32 sin_x = sinf(angles[0] * 0.5f);
    f32 cos_y = cosf(angles[1] * 0.5f);
    f32 sin_y = sinf(angles[1] * 0.5f);
    f32 cos_z = cosf(angles[2] * 0.5f);
    f32 sin_z = sinf(angles[2] * 0.5f);
    f32 cos_x_cos_y = cos_x * cos_y;
    f32 cos_x_sin_y = cos_x * sin_y;
    f32 sin_x_cos_y = sin_x * cos_y;
    f32 sin_x_sin_y = sin_x * sin_y;
    q[0] = (cos_x_cos_y * cos_z) + (sin_x_sin_y * sin_z);
    q[1] = (sin_x_cos_y * cos_z) - (cos_x_sin_y * sin_z);
    q[2] = (cos_x_sin_y * cos_z) + (sin_x_cos_y * sin_z);
    q[3] = (cos_x_cos_y * sin_z) - (sin_x_sin_y * cos_z);
}

void quaternion_set_rotation_around_x(f32 angle, Quaternion q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = sinf(angle * 0.5f);
    q[2] = 0.0f;
    q[3] = 0.0f;
}

void quaternion_set_rotation_around_y(f32 angle, Quaternion q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = 0.0f;
    q[2] = sinf(angle * 0.5f);
    q[3] = 0.0f;
}

void quaternion_set_rotation_around_z(f32 angle, Quaternion q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = 0.0f;
    q[2] = 0.0f;
    q[3] = sinf(angle * 0.5f);
}

#ifdef NONMATCHING
typedef f32 mat44[4][4];

void quaternion_to_matrix(Quaternion q, mat44 matrix) {
    f32 temp_f6 = 2.0f / ((q[0] * q[0]) + (q[1] * q[1]) + (q[2] * q[2]) +  (q[3] * q[3]));
    f32 temp_f18 = q[1] * temp_f6;
    f32 temp_f16 = q[2] * temp_f6;
    f32 temp_f14 = q[3] * temp_f6;
    f32 sp34 = q[0] * temp_f18;
    f32 sp30 = q[0] * temp_f16;
    f32 sp2C = q[0] * temp_f14;
    matrix[0][0] = (1.0f - (q[2] * temp_f16 + q[3] * temp_f14));
    matrix[0][1] = (q[1] * temp_f16 + sp2C);
    matrix[0][2] = (q[1] * temp_f14 - sp30);
    matrix[0][3] = 0.0f;
    matrix[1][0] = (q[1] * temp_f16 - sp2C);
    matrix[1][1] = (1.0f - (q[1] * temp_f18 + q[3] * temp_f14));
    matrix[1][2] = (q[2] * temp_f14 + sp34);
    matrix[1][3] = 0.0f;
    matrix[2][0] = (q[1] * temp_f14 + sp30);
    matrix[2][1] = (q[2] * temp_f14 - sp34);
    matrix[2][2] = (1.0f - (q[1] * temp_f18 + q[2] * temp_f16));
    matrix[2][3] = 0.0f;
    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}
#else
GLOBAL_ASM(
.text
glabel quaternion_to_matrix
/* 090158 7F05B628 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 09015C 7F05B62C F7B40008 */  sdc1  $f20, 8($sp)
/* 090160 7F05B630 C4940000 */  lwc1  $f20, ($a0)
/* 090164 7F05B634 C4800004 */  lwc1  $f0, 4($a0)
/* 090168 7F05B638 C4820008 */  lwc1  $f2, 8($a0)
/* 09016C 7F05B63C 4614A102 */  mul.s $f4, $f20, $f20
/* 090170 7F05B640 C48C000C */  lwc1  $f12, 0xc($a0)
/* 090174 7F05B644 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 090178 7F05B648 46000182 */  mul.s $f6, $f0, $f0
/* 09017C 7F05B64C 46062200 */  add.s $f8, $f4, $f6
/* 090180 7F05B650 46021282 */  mul.s $f10, $f2, $f2
/* 090184 7F05B654 460A4100 */  add.s $f4, $f8, $f10
/* 090188 7F05B658 460C6182 */  mul.s $f6, $f12, $f12
/* 09018C 7F05B65C 44815000 */  mtc1  $at, $f10
/* 090190 7F05B660 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 090194 7F05B664 46043200 */  add.s $f8, $f6, $f4
/* 090198 7F05B668 46085183 */  div.s $f6, $f10, $f8
/* 09019C 7F05B66C 46060482 */  mul.s $f18, $f0, $f6
/* 0901A0 7F05B670 E7A60044 */  swc1  $f6, 0x44($sp)
/* 0901A4 7F05B674 46061402 */  mul.s $f16, $f2, $f6
/* 0901A8 7F05B678 00000000 */  nop   
/* 0901AC 7F05B67C 46066382 */  mul.s $f14, $f12, $f6
/* 0901B0 7F05B680 00000000 */  nop   
/* 0901B4 7F05B684 4612A102 */  mul.s $f4, $f20, $f18
/* 0901B8 7F05B688 00000000 */  nop   
/* 0901BC 7F05B68C 4610A282 */  mul.s $f10, $f20, $f16
/* 0901C0 7F05B690 00000000 */  nop   
/* 0901C4 7F05B694 460EA202 */  mul.s $f8, $f20, $f14
/* 0901C8 7F05B698 E7A40034 */  swc1  $f4, 0x34($sp)
/* 0901CC 7F05B69C 46120182 */  mul.s $f6, $f0, $f18
/* 0901D0 7F05B6A0 E7AA0030 */  swc1  $f10, 0x30($sp)
/* 0901D4 7F05B6A4 46100102 */  mul.s $f4, $f0, $f16
/* 0901D8 7F05B6A8 E7A8002C */  swc1  $f8, 0x2c($sp)
/* 0901DC 7F05B6AC 460E0282 */  mul.s $f10, $f0, $f14
/* 0901E0 7F05B6B0 E7A60028 */  swc1  $f6, 0x28($sp)
/* 0901E4 7F05B6B4 44800000 */  mtc1  $zero, $f0
/* 0901E8 7F05B6B8 46101202 */  mul.s $f8, $f2, $f16
/* 0901EC 7F05B6BC E7A40024 */  swc1  $f4, 0x24($sp)
/* 0901F0 7F05B6C0 44818000 */  mtc1  $at, $f16
/* 0901F4 7F05B6C4 460E1182 */  mul.s $f6, $f2, $f14
/* 0901F8 7F05B6C8 E7AA0020 */  swc1  $f10, 0x20($sp)
/* 0901FC 7F05B6CC 460E6102 */  mul.s $f4, $f12, $f14
/* 090200 7F05B6D0 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 090204 7F05B6D4 C7AA001C */  lwc1  $f10, 0x1c($sp)
/* 090208 7F05B6D8 E7A60018 */  swc1  $f6, 0x18($sp)
/* 09020C 7F05B6DC E7A40014 */  swc1  $f4, 0x14($sp)
/* 090210 7F05B6E0 C7A80014 */  lwc1  $f8, 0x14($sp)
/* 090214 7F05B6E4 44812000 */  mtc1  $at, $f4
/* 090218 7F05B6E8 46085180 */  add.s $f6, $f10, $f8
/* 09021C 7F05B6EC 46062281 */  sub.s $f10, $f4, $f6
/* 090220 7F05B6F0 E4AA0000 */  swc1  $f10, ($a1)
/* 090224 7F05B6F4 C7A4002C */  lwc1  $f4, 0x2c($sp)
/* 090228 7F05B6F8 C7A80024 */  lwc1  $f8, 0x24($sp)
/* 09022C 7F05B6FC 46044180 */  add.s $f6, $f8, $f4
/* 090230 7F05B700 E4A60004 */  swc1  $f6, 4($a1)
/* 090234 7F05B704 C7A80030 */  lwc1  $f8, 0x30($sp)
/* 090238 7F05B708 C7AA0020 */  lwc1  $f10, 0x20($sp)
/* 09023C 7F05B70C 46085101 */  sub.s $f4, $f10, $f8
/* 090240 7F05B710 E4A40008 */  swc1  $f4, 8($a1)
/* 090244 7F05B714 C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 090248 7F05B718 C7A60024 */  lwc1  $f6, 0x24($sp)
/* 09024C 7F05B71C C7AE0018 */  lwc1  $f14, 0x18($sp)
/* 090250 7F05B720 C7AC0028 */  lwc1  $f12, 0x28($sp)
/* 090254 7F05B724 460A3201 */  sub.s $f8, $f6, $f10
/* 090258 7F05B728 C7A20034 */  lwc1  $f2, 0x34($sp)
/* 09025C 7F05B72C E4A80010 */  swc1  $f8, 0x10($a1)
/* 090260 7F05B730 C7A40014 */  lwc1  $f4, 0x14($sp)
/* 090264 7F05B734 46027200 */  add.s $f8, $f14, $f2
/* 090268 7F05B738 46046180 */  add.s $f6, $f12, $f4
/* 09026C 7F05B73C E4A80018 */  swc1  $f8, 0x18($a1)
/* 090270 7F05B740 46027201 */  sub.s $f8, $f14, $f2
/* 090274 7F05B744 46068281 */  sub.s $f10, $f16, $f6
/* 090278 7F05B748 E4AA0014 */  swc1  $f10, 0x14($a1)
/* 09027C 7F05B74C C7A60030 */  lwc1  $f6, 0x30($sp)
/* 090280 7F05B750 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 090284 7F05B754 E4A80024 */  swc1  $f8, 0x24($a1)
/* 090288 7F05B758 46062280 */  add.s $f10, $f4, $f6
/* 09028C 7F05B75C E4AA0020 */  swc1  $f10, 0x20($a1)
/* 090290 7F05B760 C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 090294 7F05B764 E4A00030 */  swc1  $f0, 0x30($a1)
/* 090298 7F05B768 E4A00034 */  swc1  $f0, 0x34($a1)
/* 09029C 7F05B76C 46046180 */  add.s $f6, $f12, $f4
/* 0902A0 7F05B770 E4A00038 */  swc1  $f0, 0x38($a1)
/* 0902A4 7F05B774 E4A0000C */  swc1  $f0, 0xc($a1)
/* 0902A8 7F05B778 E4A0001C */  swc1  $f0, 0x1c($a1)
/* 0902AC 7F05B77C 46068281 */  sub.s $f10, $f16, $f6
/* 0902B0 7F05B780 E4A0002C */  swc1  $f0, 0x2c($a1)
/* 0902B4 7F05B784 E4B0003C */  swc1  $f16, 0x3c($a1)
/* 0902B8 7F05B788 E4AA0028 */  swc1  $f10, 0x28($a1)
/* 0902BC 7F05B78C D7B40008 */  ldc1  $f20, 8($sp)
/* 0902C0 7F05B790 03E00008 */  jr    $ra
/* 0902C4 7F05B794 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05B798(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05B798
/* 0902C8 7F05B798 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0902CC 7F05B79C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0902D0 7F05B7A0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0902D4 7F05B7A4 C4860014 */  lwc1  $f6, 0x14($a0)
/* 0902D8 7F05B7A8 C4840000 */  lwc1  $f4, ($a0)
/* 0902DC 7F05B7AC C48A0028 */  lwc1  $f10, 0x28($a0)
/* 0902E0 7F05B7B0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0902E4 7F05B7B4 46062200 */  add.s $f8, $f4, $f6
/* 0902E8 7F05B7B8 44811000 */  mtc1  $at, $f2
/* 0902EC 7F05B7BC 44809000 */  mtc1  $zero, $f18
/* 0902F0 7F05B7C0 3C0E8003 */  lui   $t6, %hi(D_80032430) 
/* 0902F4 7F05B7C4 46085400 */  add.s $f16, $f10, $f8
/* 0902F8 7F05B7C8 00A08025 */  move  $s0, $a1
/* 0902FC 7F05B7CC 25CE2430 */  addiu $t6, %lo(D_80032430) # addiu $t6, $t6, 0x2430
/* 090300 7F05B7D0 46028300 */  add.s $f12, $f16, $f2
/* 090304 7F05B7D4 460C903C */  c.lt.s $f18, $f12
/* 090308 7F05B7D8 00000000 */  nop   
/* 09030C 7F05B7DC 4502001A */  bc1fl .L7F05B848
/* 090310 7F05B7E0 8DC10000 */   lw    $at, ($t6)
/* 090314 7F05B7E4 0C007DF8 */  jal   sqrtf
/* 090318 7F05B7E8 AFA40060 */   sw    $a0, 0x60($sp)
/* 09031C 7F05B7EC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 090320 7F05B7F0 44816000 */  mtc1  $at, $f12
/* 090324 7F05B7F4 8FA40060 */  lw    $a0, 0x60($sp)
/* 090328 7F05B7F8 46006083 */  div.s $f2, $f12, $f0
/* 09032C 7F05B7FC 460C0102 */  mul.s $f4, $f0, $f12
/* 090330 7F05B800 E6040000 */  swc1  $f4, ($s0)
/* 090334 7F05B804 C48A0024 */  lwc1  $f10, 0x24($a0)
/* 090338 7F05B808 C4860018 */  lwc1  $f6, 0x18($a0)
/* 09033C 7F05B80C 460A3201 */  sub.s $f8, $f6, $f10
/* 090340 7F05B810 46024402 */  mul.s $f16, $f8, $f2
/* 090344 7F05B814 E6100004 */  swc1  $f16, 4($s0)
/* 090348 7F05B818 C4840008 */  lwc1  $f4, 8($a0)
/* 09034C 7F05B81C C4920020 */  lwc1  $f18, 0x20($a0)
/* 090350 7F05B820 46049181 */  sub.s $f6, $f18, $f4
/* 090354 7F05B824 46023282 */  mul.s $f10, $f6, $f2
/* 090358 7F05B828 E60A0008 */  swc1  $f10, 8($s0)
/* 09035C 7F05B82C C4900010 */  lwc1  $f16, 0x10($a0)
/* 090360 7F05B830 C4880004 */  lwc1  $f8, 4($a0)
/* 090364 7F05B834 46104481 */  sub.s $f18, $f8, $f16
/* 090368 7F05B838 46029102 */  mul.s $f4, $f18, $f2
/* 09036C 7F05B83C 10000058 */  b     .L7F05B9A0
/* 090370 7F05B840 E604000C */   swc1  $f4, 0xc($s0)
/* 090374 7F05B844 8DC10000 */  lw    $at, ($t6)
.L7F05B848:
/* 090378 7F05B848 27AB0040 */  addiu $t3, $sp, 0x40
/* 09037C 7F05B84C 00002825 */  move  $a1, $zero
/* 090380 7F05B850 AD610000 */  sw    $at, ($t3)
/* 090384 7F05B854 8DD80004 */  lw    $t8, 4($t6)
/* 090388 7F05B858 AD780004 */  sw    $t8, 4($t3)
/* 09038C 7F05B85C 8DC10008 */  lw    $at, 8($t6)
/* 090390 7F05B860 AD610008 */  sw    $at, 8($t3)
/* 090394 7F05B864 C48A0014 */  lwc1  $f10, 0x14($a0)
/* 090398 7F05B868 C4860000 */  lwc1  $f6, ($a0)
/* 09039C 7F05B86C 460A303C */  c.lt.s $f6, $f10
/* 0903A0 7F05B870 00000000 */  nop   
/* 0903A4 7F05B874 45020003 */  bc1fl .L7F05B884
/* 0903A8 7F05B878 0005C900 */   sll   $t9, $a1, 4
/* 0903AC 7F05B87C 24050001 */  li    $a1, 1
/* 0903B0 7F05B880 0005C900 */  sll   $t9, $a1, 4
.L7F05B884:
/* 0903B4 7F05B884 00991821 */  addu  $v1, $a0, $t9
/* 0903B8 7F05B888 00051080 */  sll   $v0, $a1, 2
/* 0903BC 7F05B88C 00626021 */  addu  $t4, $v1, $v0
/* 0903C0 7F05B890 C5800000 */  lwc1  $f0, ($t4)
/* 0903C4 7F05B894 C4880028 */  lwc1  $f8, 0x28($a0)
/* 0903C8 7F05B898 4608003C */  c.lt.s $f0, $f8
/* 0903CC 7F05B89C 00000000 */  nop   
/* 0903D0 7F05B8A0 45020005 */  bc1fl .L7F05B8B8
/* 0903D4 7F05B8A4 01626821 */   addu  $t5, $t3, $v0
/* 0903D8 7F05B8A8 24830020 */  addiu $v1, $a0, 0x20
/* 0903DC 7F05B8AC C4600008 */  lwc1  $f0, 8($v1)
/* 0903E0 7F05B8B0 24020008 */  li    $v0, 8
/* 0903E4 7F05B8B4 01626821 */  addu  $t5, $t3, $v0
.L7F05B8B8:
/* 0903E8 7F05B8B8 8DA50000 */  lw    $a1, ($t5)
/* 0903EC 7F05B8BC 00053880 */  sll   $a3, $a1, 2
/* 0903F0 7F05B8C0 01677821 */  addu  $t7, $t3, $a3
/* 0903F4 7F05B8C4 00057100 */  sll   $t6, $a1, 4
/* 0903F8 7F05B8C8 8DE60000 */  lw    $a2, ($t7)
/* 0903FC 7F05B8CC 008E4821 */  addu  $t1, $a0, $t6
/* 090400 7F05B8D0 0127C821 */  addu  $t9, $t1, $a3
/* 090404 7F05B8D4 C7300000 */  lwc1  $f16, ($t9)
/* 090408 7F05B8D8 0006C100 */  sll   $t8, $a2, 4
/* 09040C 7F05B8DC 00985021 */  addu  $t2, $a0, $t8
/* 090410 7F05B8E0 00064080 */  sll   $t0, $a2, 2
/* 090414 7F05B8E4 46100481 */  sub.s $f18, $f0, $f16
/* 090418 7F05B8E8 01486021 */  addu  $t4, $t2, $t0
/* 09041C 7F05B8EC C5840000 */  lwc1  $f4, ($t4)
/* 090420 7F05B8F0 AFAA0024 */  sw    $t2, 0x24($sp)
/* 090424 7F05B8F4 AFA90028 */  sw    $t1, 0x28($sp)
/* 090428 7F05B8F8 46049181 */  sub.s $f6, $f18, $f4
/* 09042C 7F05B8FC AFA80020 */  sw    $t0, 0x20($sp)
/* 090430 7F05B900 AFA7002C */  sw    $a3, 0x2c($sp)
/* 090434 7F05B904 AFA30038 */  sw    $v1, 0x38($sp)
/* 090438 7F05B908 46023300 */  add.s $f12, $f6, $f2
/* 09043C 7F05B90C 0C007DF8 */  jal   sqrtf
/* 090440 7F05B910 AFA20034 */   sw    $v0, 0x34($sp)
/* 090444 7F05B914 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 090448 7F05B918 44816000 */  mtc1  $at, $f12
/* 09044C 7F05B91C 8FA20034 */  lw    $v0, 0x34($sp)
/* 090450 7F05B920 8FA7002C */  lw    $a3, 0x2c($sp)
/* 090454 7F05B924 46006083 */  div.s $f2, $f12, $f0
/* 090458 7F05B928 8FA80020 */  lw    $t0, 0x20($sp)
/* 09045C 7F05B92C 8FA90028 */  lw    $t1, 0x28($sp)
/* 090460 7F05B930 8FAA0024 */  lw    $t2, 0x24($sp)
/* 090464 7F05B934 460C0282 */  mul.s $f10, $f0, $f12
/* 090468 7F05B938 8FA30038 */  lw    $v1, 0x38($sp)
/* 09046C 7F05B93C 02026821 */  addu  $t5, $s0, $v0
/* 090470 7F05B940 01287821 */  addu  $t7, $t1, $t0
/* 090474 7F05B944 01477021 */  addu  $t6, $t2, $a3
/* 090478 7F05B948 0122C021 */  addu  $t8, $t1, $v0
/* 09047C 7F05B94C 0067C821 */  addu  $t9, $v1, $a3
/* 090480 7F05B950 E5AA0004 */  swc1  $f10, 4($t5)
/* 090484 7F05B954 C5E80000 */  lwc1  $f8, ($t7)
/* 090488 7F05B958 C5D00000 */  lwc1  $f16, ($t6)
/* 09048C 7F05B95C 02076021 */  addu  $t4, $s0, $a3
/* 090490 7F05B960 01426821 */  addu  $t5, $t2, $v0
/* 090494 7F05B964 00687821 */  addu  $t7, $v1, $t0
/* 090498 7F05B968 02087021 */  addu  $t6, $s0, $t0
/* 09049C 7F05B96C 46104481 */  sub.s $f18, $f8, $f16
/* 0904A0 7F05B970 46029102 */  mul.s $f4, $f18, $f2
/* 0904A4 7F05B974 E6040000 */  swc1  $f4, ($s0)
/* 0904A8 7F05B978 C72A0000 */  lwc1  $f10, ($t9)
/* 0904AC 7F05B97C C7060000 */  lwc1  $f6, ($t8)
/* 0904B0 7F05B980 460A3200 */  add.s $f8, $f6, $f10
/* 0904B4 7F05B984 46024402 */  mul.s $f16, $f8, $f2
/* 0904B8 7F05B988 E5900004 */  swc1  $f16, 4($t4)
/* 0904BC 7F05B98C C5E40000 */  lwc1  $f4, ($t7)
/* 0904C0 7F05B990 C5B20000 */  lwc1  $f18, ($t5)
/* 0904C4 7F05B994 46049180 */  add.s $f6, $f18, $f4
/* 0904C8 7F05B998 46023282 */  mul.s $f10, $f6, $f2
/* 0904CC 7F05B99C E5CA0004 */  swc1  $f10, 4($t6)
.L7F05B9A0:
/* 0904D0 7F05B9A0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0904D4 7F05B9A4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0904D8 7F05B9A8 27BD0060 */  addiu $sp, $sp, 0x60
/* 0904DC 7F05B9AC 03E00008 */  jr    $ra
/* 0904E0 7F05B9B0 00000000 */   nop   
)
#endif

void quaternion_to_matrix(Quaternion q, mat44 matrix);

void matrix_4x4_set_position_and_rotation(vec3 position, Quaternion rotation, mat44 matrix) {
    quaternion_to_matrix(rotation, matrix);
    matrix[3][0] = position[0];
    matrix[3][1] = position[1];
    matrix[3][2] = position[2];
}

#ifdef NONMATCHING
void sub_GAME_7F05BA08(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80053748
.word 0x3f7fff58 /*0.99998999*/
glabel D_8005374C
.word 0xbf7fff58 /*-0.99998999*/
.text
glabel sub_GAME_7F05BA08
/* 090538 7F05BA08 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 09053C 7F05BA0C AFBF0014 */  sw    $ra, 0x14($sp)
/* 090540 7F05BA10 C4A60004 */  lwc1  $f6, 4($a1)
/* 090544 7F05BA14 C4840004 */  lwc1  $f4, 4($a0)
/* 090548 7F05BA18 C4B00000 */  lwc1  $f16, ($a1)
/* 09054C 7F05BA1C C4820000 */  lwc1  $f2, ($a0)
/* 090550 7F05BA20 46062202 */  mul.s $f8, $f4, $f6
/* 090554 7F05BA24 C4A60008 */  lwc1  $f6, 8($a1)
/* 090558 7F05BA28 C4840008 */  lwc1  $f4, 8($a0)
/* 09055C 7F05BA2C 46101282 */  mul.s $f10, $f2, $f16
/* 090560 7F05BA30 3C018005 */  lui   $at, %hi(D_80053744)
/* 090564 7F05BA34 44867000 */  mtc1  $a2, $f14
/* 090568 7F05BA38 46085480 */  add.s $f18, $f10, $f8
/* 09056C 7F05BA3C 46062282 */  mul.s $f10, $f4, $f6
/* 090570 7F05BA40 C486000C */  lwc1  $f6, 0xc($a0)
/* 090574 7F05BA44 C4A4000C */  lwc1  $f4, 0xc($a1)
/* 090578 7F05BA48 460A9200 */  add.s $f8, $f18, $f10
/* 09057C 7F05BA4C 46062482 */  mul.s $f18, $f4, $f6
/* 090580 7F05BA50 C42A3744 */  lwc1  $f10, %lo(D_80053744)($at)
/* 090584 7F05BA54 3C018005 */  lui    $at, %hi(D_80053748)
/* 090588 7F05BA58 46089300 */  add.s $f12, $f18, $f8
/* 09058C 7F05BA5C 460A603C */  c.lt.s $f12, $f10
/* 090590 7F05BA60 00000000 */  nop   
/* 090594 7F05BA64 45000020 */  bc1f  .L7F05BAE8
/* 090598 7F05BA68 00000000 */   nop   
/* 09059C 7F05BA6C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0905A0 7F05BA70 44812000 */  mtc1  $at, $f4
/* 0905A4 7F05BA74 00000000 */  nop   
/* 0905A8 7F05BA78 460E2001 */  sub.s $f0, $f4, $f14
/* 0905AC 7F05BA7C 46020182 */  mul.s $f6, $f0, $f2
/* 0905B0 7F05BA80 00000000 */  nop   
/* 0905B4 7F05BA84 460E8482 */  mul.s $f18, $f16, $f14
/* 0905B8 7F05BA88 46123201 */  sub.s $f8, $f6, $f18
/* 0905BC 7F05BA8C E4E80000 */  swc1  $f8, ($a3)
/* 0905C0 7F05BA90 C48A0004 */  lwc1  $f10, 4($a0)
/* 0905C4 7F05BA94 C4A60004 */  lwc1  $f6, 4($a1)
/* 0905C8 7F05BA98 460A0102 */  mul.s $f4, $f0, $f10
/* 0905CC 7F05BA9C 00000000 */  nop   
/* 0905D0 7F05BAA0 460E3482 */  mul.s $f18, $f6, $f14
/* 0905D4 7F05BAA4 46122201 */  sub.s $f8, $f4, $f18
/* 0905D8 7F05BAA8 E4E80004 */  swc1  $f8, 4($a3)
/* 0905DC 7F05BAAC C48A0008 */  lwc1  $f10, 8($a0)
/* 0905E0 7F05BAB0 C4A40008 */  lwc1  $f4, 8($a1)
/* 0905E4 7F05BAB4 460A0182 */  mul.s $f6, $f0, $f10
/* 0905E8 7F05BAB8 00000000 */  nop   
/* 0905EC 7F05BABC 460E2482 */  mul.s $f18, $f4, $f14
/* 0905F0 7F05BAC0 46123201 */  sub.s $f8, $f6, $f18
/* 0905F4 7F05BAC4 E4E80008 */  swc1  $f8, 8($a3)
/* 0905F8 7F05BAC8 C48A000C */  lwc1  $f10, 0xc($a0)
/* 0905FC 7F05BACC C4A6000C */  lwc1  $f6, 0xc($a1)
/* 090600 7F05BAD0 460A0102 */  mul.s $f4, $f0, $f10
/* 090604 7F05BAD4 00000000 */  nop   
/* 090608 7F05BAD8 460E3482 */  mul.s $f18, $f6, $f14
/* 09060C 7F05BADC 46122201 */  sub.s $f8, $f4, $f18
/* 090610 7F05BAE0 1000005D */  b     .L7F05BC58
/* 090614 7F05BAE4 E4E8000C */   swc1  $f8, 0xc($a3)
.L7F05BAE8:
/* 090618 7F05BAE8 C42A3748 */  lwc1  $f10, %lo(D_80053748)($at)
/* 09061C 7F05BAEC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 090620 7F05BAF0 460A603E */  c.le.s $f12, $f10
/* 090624 7F05BAF4 00000000 */  nop   
/* 090628 7F05BAF8 4502003D */  bc1fl .L7F05BBF0
/* 09062C 7F05BAFC 44812000 */   mtc1  $at, $f4
/* 090630 7F05BB00 AFA40030 */  sw    $a0, 0x30($sp)
/* 090634 7F05BB04 AFA50034 */  sw    $a1, 0x34($sp)
/* 090638 7F05BB08 AFA7003C */  sw    $a3, 0x3c($sp)
/* 09063C 7F05BB0C 0FC16B2C */  jal   acosf
/* 090640 7F05BB10 E7AE0038 */   swc1  $f14, 0x38($sp)
/* 090644 7F05BB14 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 090648 7F05BB18 C7AE0038 */  lwc1  $f14, 0x38($sp)
/* 09064C 7F05BB1C 44813000 */  mtc1  $at, $f6
/* 090650 7F05BB20 46000306 */  mov.s $f12, $f0
/* 090654 7F05BB24 460E3101 */  sub.s $f4, $f6, $f14
/* 090658 7F05BB28 46002482 */  mul.s $f18, $f4, $f0
/* 09065C 7F05BB2C 00000000 */  nop   
/* 090660 7F05BB30 46007202 */  mul.s $f8, $f14, $f0
/* 090664 7F05BB34 E7B20024 */  swc1  $f18, 0x24($sp)
/* 090668 7F05BB38 0FC15FAB */  jal   sinf
/* 09066C 7F05BB3C E7A80020 */   swc1  $f8, 0x20($sp)
/* 090670 7F05BB40 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 090674 7F05BB44 0FC15FAB */  jal   sinf
/* 090678 7F05BB48 C7AC0024 */   lwc1  $f12, 0x24($sp)
/* 09067C 7F05BB4C C7AA001C */  lwc1  $f10, 0x1c($sp)
/* 090680 7F05BB50 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 090684 7F05BB54 460A0383 */  div.s $f14, $f0, $f10
/* 090688 7F05BB58 0FC15FAB */  jal   sinf
/* 09068C 7F05BB5C E7AE0018 */   swc1  $f14, 0x18($sp)
/* 090690 7F05BB60 C7A6001C */  lwc1  $f6, 0x1c($sp)
/* 090694 7F05BB64 8FA50034 */  lw    $a1, 0x34($sp)
/* 090698 7F05BB68 8FA40030 */  lw    $a0, 0x30($sp)
/* 09069C 7F05BB6C 46060083 */  div.s $f2, $f0, $f6
/* 0906A0 7F05BB70 C4A40000 */  lwc1  $f4, ($a1)
/* 0906A4 7F05BB74 C7AE0018 */  lwc1  $f14, 0x18($sp)
/* 0906A8 7F05BB78 C4880000 */  lwc1  $f8, ($a0)
/* 0906AC 7F05BB7C 8FA7003C */  lw    $a3, 0x3c($sp)
/* 0906B0 7F05BB80 46022482 */  mul.s $f18, $f4, $f2
/* 0906B4 7F05BB84 00000000 */  nop   
/* 0906B8 7F05BB88 46087282 */  mul.s $f10, $f14, $f8
/* 0906BC 7F05BB8C 460A9180 */  add.s $f6, $f18, $f10
/* 0906C0 7F05BB90 E4E60000 */  swc1  $f6, ($a3)
/* 0906C4 7F05BB94 C4A40004 */  lwc1  $f4, 4($a1)
/* 0906C8 7F05BB98 C4920004 */  lwc1  $f18, 4($a0)
/* 0906CC 7F05BB9C 46022202 */  mul.s $f8, $f4, $f2
/* 0906D0 7F05BBA0 00000000 */  nop   
/* 0906D4 7F05BBA4 46127282 */  mul.s $f10, $f14, $f18
/* 0906D8 7F05BBA8 460A4180 */  add.s $f6, $f8, $f10
/* 0906DC 7F05BBAC E4E60004 */  swc1  $f6, 4($a3)
/* 0906E0 7F05BBB0 C4A40008 */  lwc1  $f4, 8($a1)
/* 0906E4 7F05BBB4 C4880008 */  lwc1  $f8, 8($a0)
/* 0906E8 7F05BBB8 46022482 */  mul.s $f18, $f4, $f2
/* 0906EC 7F05BBBC 00000000 */  nop   
/* 0906F0 7F05BBC0 46087282 */  mul.s $f10, $f14, $f8
/* 0906F4 7F05BBC4 460A9180 */  add.s $f6, $f18, $f10
/* 0906F8 7F05BBC8 E4E60008 */  swc1  $f6, 8($a3)
/* 0906FC 7F05BBCC C4A4000C */  lwc1  $f4, 0xc($a1)
/* 090700 7F05BBD0 C492000C */  lwc1  $f18, 0xc($a0)
/* 090704 7F05BBD4 46022202 */  mul.s $f8, $f4, $f2
/* 090708 7F05BBD8 00000000 */  nop   
/* 09070C 7F05BBDC 46127282 */  mul.s $f10, $f14, $f18
/* 090710 7F05BBE0 460A4180 */  add.s $f6, $f8, $f10
/* 090714 7F05BBE4 1000001C */  b     .L7F05BC58
/* 090718 7F05BBE8 E4E6000C */   swc1  $f6, 0xc($a3)
/* 09071C 7F05BBEC 44812000 */  mtc1  $at, $f4
.L7F05BBF0:
/* 090720 7F05BBF0 460E8482 */  mul.s $f18, $f16, $f14
/* 090724 7F05BBF4 460E2001 */  sub.s $f0, $f4, $f14
/* 090728 7F05BBF8 46020202 */  mul.s $f8, $f0, $f2
/* 09072C 7F05BBFC 46089280 */  add.s $f10, $f18, $f8
/* 090730 7F05BC00 E4EA0000 */  swc1  $f10, ($a3)
/* 090734 7F05BC04 C4A60004 */  lwc1  $f6, 4($a1)
/* 090738 7F05BC08 C4920004 */  lwc1  $f18, 4($a0)
/* 09073C 7F05BC0C 460E3102 */  mul.s $f4, $f6, $f14
/* 090740 7F05BC10 00000000 */  nop   
/* 090744 7F05BC14 46120202 */  mul.s $f8, $f0, $f18
/* 090748 7F05BC18 46082280 */  add.s $f10, $f4, $f8
/* 09074C 7F05BC1C E4EA0004 */  swc1  $f10, 4($a3)
/* 090750 7F05BC20 C4A60008 */  lwc1  $f6, 8($a1)
/* 090754 7F05BC24 C4840008 */  lwc1  $f4, 8($a0)
/* 090758 7F05BC28 460E3482 */  mul.s $f18, $f6, $f14
/* 09075C 7F05BC2C 00000000 */  nop   
/* 090760 7F05BC30 46040202 */  mul.s $f8, $f0, $f4
/* 090764 7F05BC34 46089280 */  add.s $f10, $f18, $f8
/* 090768 7F05BC38 E4EA0008 */  swc1  $f10, 8($a3)
/* 09076C 7F05BC3C C4A6000C */  lwc1  $f6, 0xc($a1)
/* 090770 7F05BC40 C492000C */  lwc1  $f18, 0xc($a0)
/* 090774 7F05BC44 460E3102 */  mul.s $f4, $f6, $f14
/* 090778 7F05BC48 00000000 */  nop   
/* 09077C 7F05BC4C 46120202 */  mul.s $f8, $f0, $f18
/* 090780 7F05BC50 46082280 */  add.s $f10, $f4, $f8
/* 090784 7F05BC54 E4EA000C */  swc1  $f10, 0xc($a3)
.L7F05BC58:
/* 090788 7F05BC58 8FBF0014 */  lw    $ra, 0x14($sp)
/* 09078C 7F05BC5C 27BD0030 */  addiu $sp, $sp, 0x30
/* 090790 7F05BC60 03E00008 */  jr    $ra
/* 090794 7F05BC64 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F05BC68(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80053750
.word 0x3f7fff58 /*0.99998999*/
.text
glabel sub_GAME_7F05BC68
/* 090798 7F05BC68 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 09079C 7F05BC6C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0907A0 7F05BC70 C4800000 */  lwc1  $f0, ($a0)
/* 0907A4 7F05BC74 44802000 */  mtc1  $zero, $f4
/* 0907A8 7F05BC78 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0907AC 7F05BC7C 44811000 */  mtc1  $at, $f2
/* 0907B0 7F05BC80 4604003C */  c.lt.s $f0, $f4
/* 0907B4 7F05BC84 44857000 */  mtc1  $a1, $f14
/* 0907B8 7F05BC88 3C018005 */  lui   $at, %hi(D_8005374C)
/* 0907BC 7F05BC8C 46000306 */  mov.s $f12, $f0
/* 0907C0 7F05BC90 45000003 */  bc1f  .L7F05BCA0
/* 0907C4 7F05BC94 46001406 */   mov.s $f16, $f2
/* 0907C8 7F05BC98 46006307 */  neg.s $f12, $f12
/* 0907CC 7F05BC9C 46001407 */  neg.s $f16, $f2
.L7F05BCA0:
/* 0907D0 7F05BCA0 C426374C */  lwc1  $f6, %lo(D_8005374C)($at)
/* 0907D4 7F05BCA4 3C018005 */  lui   $at, %hi(D_80053750)
/* 0907D8 7F05BCA8 4606603C */  c.lt.s $f12, $f6
/* 0907DC 7F05BCAC 00000000 */  nop   
/* 0907E0 7F05BCB0 45000011 */  bc1f  .L7F05BCF8
/* 0907E4 7F05BCB4 00000000 */   nop   
/* 0907E8 7F05BCB8 460E1281 */  sub.s $f10, $f2, $f14
/* 0907EC 7F05BCBC 460E0202 */  mul.s $f8, $f0, $f14
/* 0907F0 7F05BCC0 00000000 */  nop   
/* 0907F4 7F05BCC4 46105482 */  mul.s $f18, $f10, $f16
/* 0907F8 7F05BCC8 46124101 */  sub.s $f4, $f8, $f18
/* 0907FC 7F05BCCC E4C40000 */  swc1  $f4, ($a2)
/* 090800 7F05BCD0 C4860004 */  lwc1  $f6, 4($a0)
/* 090804 7F05BCD4 460E3282 */  mul.s $f10, $f6, $f14
/* 090808 7F05BCD8 E4CA0004 */  swc1  $f10, 4($a2)
/* 09080C 7F05BCDC C4880008 */  lwc1  $f8, 8($a0)
/* 090810 7F05BCE0 460E4482 */  mul.s $f18, $f8, $f14
/* 090814 7F05BCE4 E4D20008 */  swc1  $f18, 8($a2)
/* 090818 7F05BCE8 C484000C */  lwc1  $f4, 0xc($a0)
/* 09081C 7F05BCEC 460E2182 */  mul.s $f6, $f4, $f14
/* 090820 7F05BCF0 10000043 */  b     .L7F05BE00
/* 090824 7F05BCF4 E4C6000C */   swc1  $f6, 0xc($a2)
.L7F05BCF8:
/* 090828 7F05BCF8 C42A3750 */  lwc1  $f10, %lo(D_80053750)($at)
/* 09082C 7F05BCFC 460A603E */  c.le.s $f12, $f10
/* 090830 7F05BD00 00000000 */  nop   
/* 090834 7F05BD04 45020030 */  bc1fl .L7F05BDC8
/* 090838 7F05BD08 460E1201 */   sub.s $f8, $f2, $f14
/* 09083C 7F05BD0C AFA40038 */  sw    $a0, 0x38($sp)
/* 090840 7F05BD10 AFA60040 */  sw    $a2, 0x40($sp)
/* 090844 7F05BD14 E7AE003C */  swc1  $f14, 0x3c($sp)
/* 090848 7F05BD18 0FC16B2C */  jal   acosf
/* 09084C 7F05BD1C E7B00030 */   swc1  $f16, 0x30($sp)
/* 090850 7F05BD20 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 090854 7F05BD24 44811000 */  mtc1  $at, $f2
/* 090858 7F05BD28 C7AE003C */  lwc1  $f14, 0x3c($sp)
/* 09085C 7F05BD2C 46000306 */  mov.s $f12, $f0
/* 090860 7F05BD30 460E1481 */  sub.s $f18, $f2, $f14
/* 090864 7F05BD34 46007202 */  mul.s $f8, $f14, $f0
/* 090868 7F05BD38 00000000 */  nop   
/* 09086C 7F05BD3C 46009102 */  mul.s $f4, $f18, $f0
/* 090870 7F05BD40 E7A80028 */  swc1  $f8, 0x28($sp)
/* 090874 7F05BD44 0FC15FAB */  jal   sinf
/* 090878 7F05BD48 E7A40024 */   swc1  $f4, 0x24($sp)
/* 09087C 7F05BD4C E7A00020 */  swc1  $f0, 0x20($sp)
/* 090880 7F05BD50 0FC15FAB */  jal   sinf
/* 090884 7F05BD54 C7AC0028 */   lwc1  $f12, 0x28($sp)
/* 090888 7F05BD58 C7A60020 */  lwc1  $f6, 0x20($sp)
/* 09088C 7F05BD5C C7AC0024 */  lwc1  $f12, 0x24($sp)
/* 090890 7F05BD60 46060083 */  div.s $f2, $f0, $f6
/* 090894 7F05BD64 0FC15FAB */  jal   sinf
/* 090898 7F05BD68 E7A2001C */   swc1  $f2, 0x1c($sp)
/* 09089C 7F05BD6C C7B20020 */  lwc1  $f18, 0x20($sp)
/* 0908A0 7F05BD70 8FA40038 */  lw    $a0, 0x38($sp)
/* 0908A4 7F05BD74 C7A2001C */  lwc1  $f2, 0x1c($sp)
/* 0908A8 7F05BD78 46120103 */  div.s $f4, $f0, $f18
/* 0908AC 7F05BD7C C48A0000 */  lwc1  $f10, ($a0)
/* 0908B0 7F05BD80 C7B00030 */  lwc1  $f16, 0x30($sp)
/* 0908B4 7F05BD84 8FA60040 */  lw    $a2, 0x40($sp)
/* 0908B8 7F05BD88 46025202 */  mul.s $f8, $f10, $f2
/* 0908BC 7F05BD8C 00000000 */  nop   
/* 0908C0 7F05BD90 46102182 */  mul.s $f6, $f4, $f16
/* 0908C4 7F05BD94 46064280 */  add.s $f10, $f8, $f6
/* 0908C8 7F05BD98 E4CA0000 */  swc1  $f10, ($a2)
/* 0908CC 7F05BD9C C4920004 */  lwc1  $f18, 4($a0)
/* 0908D0 7F05BDA0 46029102 */  mul.s $f4, $f18, $f2
/* 0908D4 7F05BDA4 E4C40004 */  swc1  $f4, 4($a2)
/* 0908D8 7F05BDA8 C4880008 */  lwc1  $f8, 8($a0)
/* 0908DC 7F05BDAC 46024182 */  mul.s $f6, $f8, $f2
/* 0908E0 7F05BDB0 E4C60008 */  swc1  $f6, 8($a2)
/* 0908E4 7F05BDB4 C48A000C */  lwc1  $f10, 0xc($a0)
/* 0908E8 7F05BDB8 46025482 */  mul.s $f18, $f10, $f2
/* 0908EC 7F05BDBC 10000010 */  b     .L7F05BE00
/* 0908F0 7F05BDC0 E4D2000C */   swc1  $f18, 0xc($a2)
/* 0908F4 7F05BDC4 460E1201 */  sub.s $f8, $f2, $f14
.L7F05BDC8:
/* 0908F8 7F05BDC8 460E0102 */  mul.s $f4, $f0, $f14
/* 0908FC 7F05BDCC 00000000 */  nop   
/* 090900 7F05BDD0 46104182 */  mul.s $f6, $f8, $f16
/* 090904 7F05BDD4 46062280 */  add.s $f10, $f4, $f6
/* 090908 7F05BDD8 E4CA0000 */  swc1  $f10, ($a2)
/* 09090C 7F05BDDC C4920004 */  lwc1  $f18, 4($a0)
/* 090910 7F05BDE0 460E9202 */  mul.s $f8, $f18, $f14
/* 090914 7F05BDE4 E4C80004 */  swc1  $f8, 4($a2)
/* 090918 7F05BDE8 C4840008 */  lwc1  $f4, 8($a0)
/* 09091C 7F05BDEC 460E2182 */  mul.s $f6, $f4, $f14
/* 090920 7F05BDF0 E4C60008 */  swc1  $f6, 8($a2)
/* 090924 7F05BDF4 C48A000C */  lwc1  $f10, 0xc($a0)
/* 090928 7F05BDF8 460E5482 */  mul.s $f18, $f10, $f14
/* 09092C 7F05BDFC E4D2000C */  swc1  $f18, 0xc($a2)
.L7F05BE00:
/* 090930 7F05BE00 8FBF0014 */  lw    $ra, 0x14($sp)
/* 090934 7F05BE04 27BD0038 */  addiu $sp, $sp, 0x38
/* 090938 7F05BE08 03E00008 */  jr    $ra
/* 09093C 7F05BE0C 00000000 */   nop   
)
#endif

void quaternion_ensure_shortest_path(Quaternion q1, Quaternion q2) {
    f32 dot = (q1[0] * q2[0]) + (q1[1] * q2[1]) + (q1[2] * q2[2]) + (q1[3] * q2[3]);
    if (dot < 0.0f) {
        q2[0] = -q2[0];
        q2[1] = -q2[1];
        q2[2] = -q2[2];
        q2[3] = -q2[3];
    }
}

void quaternion_multiply(Quaternion lhs, Quaternion rhs, Quaternion result) {
    result[0] = (lhs[0] * rhs[0]) - (lhs[1] * rhs[1]) - (lhs[2] * rhs[2]) - (lhs[3] * rhs[3]);
    result[1] = (lhs[0] * rhs[1]) + (rhs[0] * lhs[1]) + (lhs[2] * rhs[3]) - (lhs[3] * rhs[2]);
    result[2] = (lhs[0] * rhs[2]) + (rhs[0] * lhs[2]) + (lhs[3] * rhs[1]) - (lhs[1] * rhs[3]);
    result[3] = (lhs[0] * rhs[3]) + (rhs[0] * lhs[3]) + (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]);
}

void quaternion_multiply_in_place(Quaternion lhs, Quaternion rhs) {
    Quaternion result;
    quaternion_multiply(lhs, rhs, result);
    rhs[0] = result[0];
    rhs[1] = result[1];
    rhs[2] = result[2];
    rhs[3] = result[3];
}

float acosf(float);
float sinf(float);

void sub_GAME_7F05BFD4(Quaternion arg0, Quaternion arg1) {
    f32 angle = acosf(arg0[0]);
    f32 temp_f0_2 = sinf(angle);
    if (temp_f0_2 == 0.0f) {
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        arg1[3] = 0.0f;
        return;
    }
    arg1[0] = 0.0f;
    arg1[1] = (arg0[1] * (angle / temp_f0_2));
    arg1[2] = (arg0[2] * (angle / temp_f0_2));
    arg1[3] = (arg0[3] * (angle / temp_f0_2));
}

#ifdef NONMATCHING
// <    90c10:     e7ac0020        swc1    $f12,32(sp)
// <    90c14:     c7ac0020        lwc1    $f12,32(sp)
// ---
// >    90c10:     e7ac0024        swc1    $f12,36(sp)
// >    90c14:     c7ac0024        lwc1    $f12,36(sp)
void sub_GAME_7F05C068(Quaternion arg0, Quaternion arg1) {
    f32 temp_f0_2 = sqrtf((arg0[1] * arg0[1]) + (arg0[2] * arg0[2]) + (arg0[3] * arg0[3]));
    f32 temp_f2_2;
    f32 test;
    if (temp_f0_2 == 0.0f) {
        arg1[0] = 1.0f;
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        arg1[3] = 0.0f;
        return;
    }
    temp_f2_2 = sinf(temp_f0_2);
    test = temp_f2_2 / temp_f0_2;
    arg1[0] = cosf(temp_f0_2);
    arg1[1] = (arg0[1] * test);
    arg1[2] = (arg0[2] * test);
    arg1[3] = (arg0[3] * test);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05C068
/* 090B98 7F05C068 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 090B9C 7F05C06C AFBF0014 */  sw    $ra, 0x14($sp)
/* 090BA0 7F05C070 C4820004 */  lwc1  $f2, 4($a0)
/* 090BA4 7F05C074 C48E0008 */  lwc1  $f14, 8($a0)
/* 090BA8 7F05C078 C480000C */  lwc1  $f0, 0xc($a0)
/* 090BAC 7F05C07C 46021102 */  mul.s $f4, $f2, $f2
/* 090BB0 7F05C080 AFA5002C */  sw    $a1, 0x2c($sp)
/* 090BB4 7F05C084 AFA40028 */  sw    $a0, 0x28($sp)
/* 090BB8 7F05C088 460E7182 */  mul.s $f6, $f14, $f14
/* 090BBC 7F05C08C 46062200 */  add.s $f8, $f4, $f6
/* 090BC0 7F05C090 46000282 */  mul.s $f10, $f0, $f0
/* 090BC4 7F05C094 0C007DF8 */  jal   sqrtf
/* 090BC8 7F05C098 46085300 */   add.s $f12, $f10, $f8
/* 090BCC 7F05C09C 44801000 */  mtc1  $zero, $f2
/* 090BD0 7F05C0A0 8FA40028 */  lw    $a0, 0x28($sp)
/* 090BD4 7F05C0A4 8FA5002C */  lw    $a1, 0x2c($sp)
/* 090BD8 7F05C0A8 46020032 */  c.eq.s $f0, $f2
/* 090BDC 7F05C0AC 46000306 */  mov.s $f12, $f0
/* 090BE0 7F05C0B0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 090BE4 7F05C0B4 45020008 */  bc1fl .L7F05C0D8
/* 090BE8 7F05C0B8 AFA40028 */   sw    $a0, 0x28($sp)
/* 090BEC 7F05C0BC 44818000 */  mtc1  $at, $f16
/* 090BF0 7F05C0C0 E4A20004 */  swc1  $f2, 4($a1)
/* 090BF4 7F05C0C4 E4A20008 */  swc1  $f2, 8($a1)
/* 090BF8 7F05C0C8 E4A2000C */  swc1  $f2, 0xc($a1)
/* 090BFC 7F05C0CC 10000016 */  b     .L7F05C128
/* 090C00 7F05C0D0 E4B00000 */   swc1  $f16, ($a1)
/* 090C04 7F05C0D4 AFA40028 */  sw    $a0, 0x28($sp)
.L7F05C0D8:
/* 090C08 7F05C0D8 AFA5002C */  sw    $a1, 0x2c($sp)
/* 090C0C 7F05C0DC 0FC15FAB */  jal   sinf
/* 090C10 7F05C0E0 E7AC0020 */   swc1  $f12, 0x20($sp)
/* 090C14 7F05C0E4 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 090C18 7F05C0E8 460C0083 */  div.s $f2, $f0, $f12
/* 090C1C 7F05C0EC 0FC15FA8 */  jal   cosf
/* 090C20 7F05C0F0 E7A2001C */   swc1  $f2, 0x1c($sp)
/* 090C24 7F05C0F4 8FA5002C */  lw    $a1, 0x2c($sp)
/* 090C28 7F05C0F8 8FA40028 */  lw    $a0, 0x28($sp)
/* 090C2C 7F05C0FC C7A2001C */  lwc1  $f2, 0x1c($sp)
/* 090C30 7F05C100 E4A00000 */  swc1  $f0, ($a1)
/* 090C34 7F05C104 C4920004 */  lwc1  $f18, 4($a0)
/* 090C38 7F05C108 46029102 */  mul.s $f4, $f18, $f2
/* 090C3C 7F05C10C E4A40004 */  swc1  $f4, 4($a1)
/* 090C40 7F05C110 C4860008 */  lwc1  $f6, 8($a0)
/* 090C44 7F05C114 46023282 */  mul.s $f10, $f6, $f2
/* 090C48 7F05C118 E4AA0008 */  swc1  $f10, 8($a1)
/* 090C4C 7F05C11C C488000C */  lwc1  $f8, 0xc($a0)
/* 090C50 7F05C120 46024402 */  mul.s $f16, $f8, $f2
/* 090C54 7F05C124 E4B0000C */  swc1  $f16, 0xc($a1)
.L7F05C128:
/* 090C58 7F05C128 8FBF0014 */  lw    $ra, 0x14($sp)
/* 090C5C 7F05C12C 27BD0028 */  addiu $sp, $sp, 0x28
/* 090C60 7F05C130 03E00008 */  jr    $ra
/* 090C64 7F05C134 00000000 */   nop   
)
#endif

void sub_GAME_7F05C138(Quaternion arg0, Quaternion arg1, Quaternion arg2, Quaternion result) {
    Quaternion conjugate;
    Quaternion sp50;
    Quaternion sp40;
    Quaternion sp30;
    Quaternion sp20;
    conjugate[0] = arg1[0];
    conjugate[1] = -arg1[1];
    conjugate[2] = -arg1[2];
    conjugate[3] = -arg1[3];
    quaternion_multiply(conjugate, arg0, sp50);
    quaternion_multiply(conjugate, arg2, sp40);
    sub_GAME_7F05BFD4(sp50, sp30);
    sub_GAME_7F05BFD4(sp40, sp20);
    sp30[0] = -(sp30[0] + sp20[0]) * 0.25f;
    sp30[1] = -(sp30[1] + sp20[1]) * 0.25f;
    sp30[2] = -(sp30[2] + sp20[2]) * 0.25f;
    sp30[3] = -(sp30[3] + sp20[3]) * 0.25f;
    sub_GAME_7F05C068(sp30, sp50);
    quaternion_multiply(arg1, sp50, result);
}

#ifdef NONMATCHING
void sub_GAME_7F05BA08(Quaternion arg0, Quaternion arg1, f32 arg2, Quaternion arg3);

// <    90dfc:     8fa70054        lw      a3,84(sp)
// ---
// >    90dfc:     8fa7004c        lw      a3,76(sp)
void sub_GAME_7F05C250(Quaternion arg0, Quaternion arg1, Quaternion arg2, Quaternion arg3, f32 arg4) {
    Quaternion sp30;
    Quaternion sp20;
    f32 test = (arg4 + arg4) * (1.0f - arg4);
    quaternion_ensure_shortest_path(arg0, arg3);
    sub_GAME_7F05BA08(arg0, arg3, arg4, sp30);
    quaternion_ensure_shortest_path(arg1, arg2);
    sub_GAME_7F05BA08(arg1, arg2, arg4, sp20);
    quaternion_ensure_shortest_path(sp30, sp20);
    sub_GAME_7F05BA08(sp30, sp20, test, arg3);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F05C250
/* 090D80 7F05C250 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 090D84 7F05C254 AFBF0014 */  sw    $ra, 0x14($sp)
/* 090D88 7F05C258 AFA50044 */  sw    $a1, 0x44($sp)
/* 090D8C 7F05C25C AFA40040 */  sw    $a0, 0x40($sp)
/* 090D90 7F05C260 AFA60048 */  sw    $a2, 0x48($sp)
/* 090D94 7F05C264 AFA7004C */  sw    $a3, 0x4c($sp)
/* 090D98 7F05C268 0FC16F84 */  jal   quaternion_ensure_shortest_path
/* 090D9C 7F05C26C 00E02825 */   move  $a1, $a3
/* 090DA0 7F05C270 8FA40040 */  lw    $a0, 0x40($sp)
/* 090DA4 7F05C274 8FA5004C */  lw    $a1, 0x4c($sp)
/* 090DA8 7F05C278 8FA60050 */  lw    $a2, 0x50($sp)
/* 090DAC 7F05C27C 0FC16E82 */  jal   sub_GAME_7F05BA08
/* 090DB0 7F05C280 27A70030 */   addiu $a3, $sp, 0x30
/* 090DB4 7F05C284 8FA40044 */  lw    $a0, 0x44($sp)
/* 090DB8 7F05C288 0FC16F84 */  jal   quaternion_ensure_shortest_path
/* 090DBC 7F05C28C 8FA50048 */   lw    $a1, 0x48($sp)
/* 090DC0 7F05C290 8FA40044 */  lw    $a0, 0x44($sp)
/* 090DC4 7F05C294 8FA50048 */  lw    $a1, 0x48($sp)
/* 090DC8 7F05C298 8FA60050 */  lw    $a2, 0x50($sp)
/* 090DCC 7F05C29C 0FC16E82 */  jal   sub_GAME_7F05BA08
/* 090DD0 7F05C2A0 27A70020 */   addiu $a3, $sp, 0x20
/* 090DD4 7F05C2A4 27A40030 */  addiu $a0, $sp, 0x30
/* 090DD8 7F05C2A8 0FC16F84 */  jal   quaternion_ensure_shortest_path
/* 090DDC 7F05C2AC 27A50020 */   addiu $a1, $sp, 0x20
/* 090DE0 7F05C2B0 C7A00050 */  lwc1  $f0, 0x50($sp)
/* 090DE4 7F05C2B4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 090DE8 7F05C2B8 44813000 */  mtc1  $at, $f6
/* 090DEC 7F05C2BC 46000100 */  add.s $f4, $f0, $f0
/* 090DF0 7F05C2C0 27A40030 */  addiu $a0, $sp, 0x30
/* 090DF4 7F05C2C4 27A50020 */  addiu $a1, $sp, 0x20
/* 090DF8 7F05C2C8 46003201 */  sub.s $f8, $f6, $f0
/* 090DFC 7F05C2CC 8FA70054 */  lw    $a3, 0x54($sp)
/* 090E00 7F05C2D0 46082282 */  mul.s $f10, $f4, $f8
/* 090E04 7F05C2D4 44065000 */  mfc1  $a2, $f10
/* 090E08 7F05C2D8 0FC16E82 */  jal   sub_GAME_7F05BA08
/* 090E0C 7F05C2DC 00000000 */   nop   
/* 090E10 7F05C2E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 090E14 7F05C2E4 27BD0040 */  addiu $sp, $sp, 0x40
/* 090E18 7F05C2E8 03E00008 */  jr    $ra
/* 090E1C 7F05C2EC 00000000 */   nop   
)
#endif

void sub_GAME_7F05C250(Quaternion arg0, Quaternion arg1, Quaternion arg2, Quaternion arg3, f32 arg4, s32 arg5);

void sub_GAME_7F05C2F0(Quaternion arg0, Quaternion arg1, Quaternion arg2, Quaternion arg3, f32 arg4, s32 arg5) {
    Quaternion sp30;
    Quaternion sp20;
    sub_GAME_7F05C138(arg0, arg1, arg2, sp30);
    sub_GAME_7F05C138(arg1, arg2, arg3, sp20);
    sub_GAME_7F05C250(arg1, sp30, sp20, arg2, arg4, arg5);
}
