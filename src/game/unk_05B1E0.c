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

void quaternion_to_matrix(quatf q, mat44f matrix) {
    f32 temp_f6 = 2.0f / ((q[0] * q[0]) + (q[1] * q[1]) + (q[2] * q[2]) +  (q[3] * q[3]));
    f32 temp_f18 = q[1] * temp_f6;
    f32 temp_f16 = q[2] * temp_f6;
    f32 temp_f14 = q[3] * temp_f6;
    f32 sp34 = q[0] * temp_f18;
    f32 sp30 = q[0] * temp_f16;
    f32 sp2C = q[0] * temp_f14;
    f32 sp28 = q[1] * temp_f18;
    f32 sp24 = q[1] * temp_f16;
    f32 sp20 = q[1] * temp_f14;
    f32 sp1C = q[2] * temp_f16;
    f32 sp18 = q[2] * temp_f14;
    f32 sp14 = q[3] * temp_f14;
    matrix[0][0] = (1.0f - (sp1C + sp14));
    matrix[0][1] = (sp24 + sp2C);
    matrix[0][2] = (sp20 - sp30);
    matrix[1][0] = (sp24 - sp2C);
    matrix[1][1] = (1.0f - (sp28 + sp14));
    matrix[1][2] = (sp18 + sp34);
    matrix[2][0] = (sp20 + sp30);
    matrix[2][1] = (sp18 - sp34);
    matrix[2][2] = (1.0f - (sp28 + sp1C));
    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[0][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}

#ifdef NONMATCHING
//s32 D_80032430[] = {1, 2, 0};

void quaternion_from_matrix(mat44f arg0, quatf arg1) {
    f32 trace = arg0[0][0] + arg0[1][1] + arg0[2][2] + 1.0f;
    f32 var1;
    f32 var2;
    f32 var5;
    s32 i;
    s32 indices[3];
    s32 j;
    s32 k;
    if (0.0f < trace) {
        var1 = sqrtf(trace);
        var2 = 0.5f / var1;
        arg1[0] = var1 * 0.5f;
        arg1[1] = (arg0[1][2] - arg0[2][1]) * var2;
        arg1[2] = (arg0[2][0] - arg0[0][2]) * var2;
        arg1[3] = (arg0[0][1] - arg0[1][0]) * var2;
        return;
    }    
    indices[0] = D_80032430[0]; 
    indices[1] = D_80032430[1];
    indices[2] = D_80032430[2];
    i = 0;
    if (arg0[0][0] < arg0[1][1])
    {
        i = 1;
    }
    var5 = arg0[i][i];
    if (var5 < arg0[2][2])
    {
        i = 2;
    }
    var5 = arg0[i][i];
    j = indices[i];
    k = indices[j];
    var1 = sqrtf(var5 - arg0[j][j] - arg0[k][k] + 1.0f);
    var2 = 0.5f / var1;
    arg1[i + 1] = var1 * 0.5f;
    arg1[    0] = (arg0[j][k] - arg0[k][j]) * var2;
    arg1[j + 1] = (arg0[i][j] + arg0[j][i]) * var2;
    arg1[k + 1] = (arg0[i][k] + arg0[k][i]) * var2;
}
#else
GLOBAL_ASM(
.text
glabel quaternion_from_matrix
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

void matrix_4x4_set_position_and_rotation(vec3f position, quatf rotation, mat44f matrix) {
    quaternion_to_matrix(rotation, matrix);
    matrix[3][0] = position[0];
    matrix[3][1] = position[1];
    matrix[3][2] = position[2];
}

#define EPSILON 0.00001001f

void quaternion_slerp(quatf q1, quatf q2, f32 t, quatf result) {
    f32 dot = (q1[0] * q2[0]) + (q1[1] * q2[1]) + (q1[2] * q2[2]) + (q1[3] * q2[3]);
    f32 theta;
    f32 theta_q1;
    f32 theta_q2;
    f32 sine;
    f32 coeff_q1;
    f32 coeff_q2;
    if (dot < (-1.0f + EPSILON)) {
        result[0] = ((1.0f - t) * q1[0]) - (q2[0] * t);
        result[1] = ((1.0f - t) * q1[1]) - (q2[1] * t);
        result[2] = ((1.0f - t) * q1[2]) - (q2[2] * t);
        result[3] = ((1.0f - t) * q1[3]) - (q2[3] * t);
        return;
    }
    if (dot <= (1.0f - EPSILON)) {
        theta = acosf(dot);
        theta_q1 = (1.0f - t) * theta;
        theta_q2 = t * theta;
        sine = sinf(theta);
        coeff_q1 = sinf(theta_q1) / sine;
        coeff_q2 = sinf(theta_q2) / sine;
        result[0] = (coeff_q1 * q1[0]) + (q2[0] * coeff_q2);
        result[1] = (coeff_q1 * q1[1]) + (q2[1] * coeff_q2);
        result[2] = (coeff_q1 * q1[2]) + (q2[2] * coeff_q2);
        result[3] = (coeff_q1 * q1[3]) + (q2[3] * coeff_q2);
        return;
    }
    result[0] = ((1.0f - t) * q1[0]) + (q2[0] * t);
    result[1] = ((1.0f - t) * q1[1]) + (q2[1] * t);
    result[2] = ((1.0f - t) * q1[2]) + (q2[2] * t);
    result[3] = ((1.0f - t) * q1[3]) + (q2[3] * t);
}

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

void sub_GAME_7F05BFD4(quatf q1, quatf q2) {
    f32 angle = acosf(q1[0]);
    f32 sine = sinf(angle);
    if (sine == 0.0f) {
        q2[0] = 0.0f;
        q2[1] = 0.0f;
        q2[2] = 0.0f;
        q2[3] = 0.0f;
        return;
    }
    q2[0] = 0.0f;
    q2[1] = (q1[1] * (angle / sine));
    q2[2] = (q1[2] * (angle / sine));
    q2[3] = (q1[3] * (angle / sine));
}

void sub_GAME_7F05C068(quatf q1, quatf q2) {
    f32 sine;
    f32 angle = sqrtf((q1[1] * q1[1]) + (q1[2] * q1[2]) + (q1[3] * q1[3]));
    f32 unknown;
    if (angle == 0.0f) {
        q2[0] = 1.0f;
        q2[1] = 0.0f;
        q2[2] = 0.0f;
        q2[3] = 0.0f;
        return;
    }
    sine = sinf(angle);
    unknown = sine / angle;
    q2[0] = cosf(angle);
    q2[1] = (q1[1] * unknown);
    q2[2] = (q1[2] * unknown);
    q2[3] = (q1[3] * unknown);
}

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
