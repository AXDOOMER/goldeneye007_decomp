#include "ultra64.h"


// data
//D:80032430
s32 D_80032430 = 1;
//D:80032434
s32 D_80032434 = 2;


// rodata

typedef u16 vec3u[3];
typedef f32 vec3f[3];
typedef f32 mat44f[4][4];
typedef f32 quatf[4]; // w, x, y, z

float acosf(float);

#define M_PI 3.1415927f
#define HALF2RAD(x) (x * (M_PI / 32768.0f))

void quaternion_set_rotation_around_xyz(vec3u angles, quatf q) {
    f32 cos_x = cosf(HALF2RAD(angles[0]) * 0.5f);
    f32 sin_x = sinf(HALF2RAD(angles[0]) * 0.5f);
    f32 cos_y = cosf(HALF2RAD(angles[1]) * 0.5f);
    f32 sin_y = sinf(HALF2RAD(angles[1]) * 0.5f);
    f32 cos_z = cosf(HALF2RAD(angles[2]) * 0.5f);
    f32 sin_z = sinf(HALF2RAD(angles[2]) * 0.5f);
    f32 cos_x_cos_y = cos_x * cos_y;
    f32 cos_x_sin_y = cos_x * sin_y;
    f32 sin_x_cos_y = sin_x * cos_y;
    f32 sin_x_sin_y = sin_x * sin_y;
    q[0] = ((cos_x_cos_y * cos_z) + (sin_x_sin_y * sin_z));
    q[1] = ((sin_x_cos_y * cos_z) - (cos_x_sin_y * sin_z));
    q[2] = ((cos_x_sin_y * cos_z) + (sin_x_cos_y * sin_z));
    q[3] = ((cos_x_cos_y * sin_z) - (sin_x_sin_y * cos_z));
}

void quaternion_set_rotation_around_xyzf(vec3f angles, quatf q) {
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

void quaternion_set_rotation_around_x(f32 angle, quatf q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = sinf(angle * 0.5f);
    q[2] = 0.0f;
    q[3] = 0.0f;
}

void quaternion_set_rotation_around_y(f32 angle, quatf q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = 0.0f;
    q[2] = sinf(angle * 0.5f);
    q[3] = 0.0f;
}

void quaternion_set_rotation_around_z(f32 angle, quatf q) {
    q[0] = cosf(angle * 0.5f);
    q[1] = 0.0f;
    q[2] = 0.0f;
    q[3] = sinf(angle * 0.5f);
}

#ifdef NONMATCHING
void quaternion_to_matrix(quatf q, mat44f matrix) {
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

void quaternion_to_matrix(quatf q, mat44f matrix);

void matrix_4x4_set_position_and_rotation(vec3f position, quatf rotation, mat44f matrix) {
    quaternion_to_matrix(rotation, matrix);
    matrix[3][0] = position[0];
    matrix[3][1] = position[1];
    matrix[3][2] = position[2];
}

void quaternion_slerp(quatf q1, quatf q2, f32 t, quatf result);

#ifdef NONMATCHING
void quaternion_slerp(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80053744
.word 0xbf7fff58 /*-0.99998999*/
glabel D_80053748
.word 0x3f7fff58 /*0.99998999*/
.text
glabel quaternion_slerp
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

void sub_GAME_7F05BC68(quatf q, f32 t, quatf result) {
    f32 phi_f12 = q[0];
    f32 phi_f16 = 1.0f;
    f32 temp_f0_2;
    f32 test2;
    f32 temp_f4;
    f32 sp20;
    f32 temp_f2;
    f32 test;
    if (q[0] < 0.0f) {
        phi_f12 = -phi_f12;
        phi_f16 = -phi_f16;
    }
    if (phi_f12 < -0.99998999f) {
        result[0] = (q[0] * t) - ((1.0f - t) * phi_f16);
        result[1] = (q[1] * t);
        result[2] = (q[2] * t);
        result[3] = (q[3] * t);
        return;
    }
    if (phi_f12 <= 0.99998999f) {
        temp_f0_2 = acosf(phi_f12);
        test2 = t * temp_f0_2;
        temp_f4 = (1.0f - t) * temp_f0_2;
        sp20 = sinf(temp_f0_2);
        temp_f2 = sinf(test2) / sp20;
        test = sinf(temp_f4) / sp20;
        result[0] = (q[0] * temp_f2) + (test * phi_f16);
        result[1] = (q[1] * temp_f2);
        result[2] = (q[2] * temp_f2);
        result[3] = (q[3] * temp_f2);
    } else {
        result[0] = (q[0] * t) + ((1.0f - t) * phi_f16);
        result[1] = (q[1] * t);
        result[2] = (q[2] * t);
        result[3] = (q[3] * t);
    }
}

void quaternion_ensure_shortest_path(quatf q1, quatf q2) {
    f32 dot = (q1[0] * q2[0]) + (q1[1] * q2[1]) + (q1[2] * q2[2]) + (q1[3] * q2[3]);
    if (dot < 0.0f) {
        q2[0] = -q2[0];
        q2[1] = -q2[1];
        q2[2] = -q2[2];
        q2[3] = -q2[3];
    }
}

void quaternion_multiply(quatf lhs, quatf rhs, quatf result) {
    result[0] = (lhs[0] * rhs[0]) - (lhs[1] * rhs[1]) - (lhs[2] * rhs[2]) - (lhs[3] * rhs[3]);
    result[1] = (lhs[0] * rhs[1]) + (rhs[0] * lhs[1]) + (lhs[2] * rhs[3]) - (lhs[3] * rhs[2]);
    result[2] = (lhs[0] * rhs[2]) + (rhs[0] * lhs[2]) + (lhs[3] * rhs[1]) - (lhs[1] * rhs[3]);
    result[3] = (lhs[0] * rhs[3]) + (rhs[0] * lhs[3]) + (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]);
}

void quaternion_multiply_in_place(quatf lhs, quatf rhs) {
    quatf result;
    quaternion_multiply(lhs, rhs, result);
    rhs[0] = result[0];
    rhs[1] = result[1];
    rhs[2] = result[2];
    rhs[3] = result[3];
}

void sub_GAME_7F05BFD4(quatf arg0, quatf arg1) {
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
void sub_GAME_7F05C068(quatf arg0, quatf arg1) {
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

void sub_GAME_7F05C138(quatf arg0, quatf arg1, quatf arg2, quatf result) {
    quatf conjugate;
    quatf sp50;
    quatf sp40;
    quatf sp30;
    quatf sp20;
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

void sub_GAME_7F05C250(quatf q1, quatf q2, quatf q3, quatf q4, f32 t, quatf result) {
    quatf q5;
    quatf q6;
    f32 t2 = (t + t) * (1.0f - t);
    quaternion_ensure_shortest_path(q1, q4);
    quaternion_slerp(q1, q4, t, q5);
    quaternion_ensure_shortest_path(q2, q3);
    quaternion_slerp(q2, q3, t, q6);
    quaternion_ensure_shortest_path(q5, q6);
    quaternion_slerp(q5, q6, t2, result);
}

void sub_GAME_7F05C2F0(quatf q1, quatf q2, quatf q3, quatf q4, f32 t, quatf result) {
    quatf q5;
    quatf q6;
    sub_GAME_7F05C138(q1, q2, q3, q5);
    sub_GAME_7F05C138(q2, q3, q4, q6);
    sub_GAME_7F05C250(q2, q5, q6, q3, t, result);
}
