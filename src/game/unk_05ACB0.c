#include "ultra64.h"


// rodata

#ifdef NONMATCHING
// s16 acos(s16);
// One extra mov.s instruction after 0x08F854
// f32 acosf(f32 cosinef) {
//     s16 cosines;
//     s16 angles;
//     f32 anglef;
//     if (1.0f <= cosinef) {
//         cosines = 0x7FFF;
//     } else if (cosinef <= -1.0f) {
//         cosines = -0x7FFF;
//     } else {
//         cosines = (cosinef * 32767.0f);
//     }
//     angles = acos(cosines);
//     anglef = angles;
//     if (angles < 0) {
//         anglef += 4294967296.0f;
//     }
//     return (anglef * 3.1415927f) / 65535.0f;
// }
#else
GLOBAL_ASM(
.late_rodata
glabel D_80053720
.word 0x46fffe00 /*32767.0*/
glabel D_80053724
.word 0x40490fdb /*3.1415927*/
glabel D_80053728
.word 0x477fff00 /*65535.0*/
.text
glabel acosf
/* 08F7E0 7F05ACB0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08F7E4 7F05ACB4 44812000 */  mtc1  $at, $f4
/* 08F7E8 7F05ACB8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08F7EC 7F05ACBC AFBF0014 */  sw    $ra, 0x14($sp)
/* 08F7F0 7F05ACC0 460C203E */  c.le.s $f4, $f12
/* 08F7F4 7F05ACC4 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 08F7F8 7F05ACC8 45020004 */  bc1fl .L7F05ACDC
/* 08F7FC 7F05ACCC 44813000 */   mtc1  $at, $f6
/* 08F800 7F05ACD0 10000010 */  b     .L7F05AD14
/* 08F804 7F05ACD4 24047FFF */   li    $a0, 32767
/* 08F808 7F05ACD8 44813000 */  mtc1  $at, $f6
.L7F05ACDC:
/* 08F80C 7F05ACDC 3C018005 */  lui   $at, %hi(D_80053720)
/* 08F810 7F05ACE0 4606603E */  c.le.s $f12, $f6
/* 08F814 7F05ACE4 00000000 */  nop   
/* 08F818 7F05ACE8 45000003 */  bc1f  .L7F05ACF8
/* 08F81C 7F05ACEC 00000000 */   nop   
/* 08F820 7F05ACF0 10000008 */  b     .L7F05AD14
/* 08F824 7F05ACF4 24048001 */   li    $a0, -32767
.L7F05ACF8:
/* 08F828 7F05ACF8 C4283720 */  lwc1  $f8, %lo(D_80053720)($at)
/* 08F82C 7F05ACFC 46086282 */  mul.s $f10, $f12, $f8
/* 08F830 7F05AD00 4600540D */  trunc.w.s $f16, $f10
/* 08F834 7F05AD04 44048000 */  mfc1  $a0, $f16
/* 08F838 7F05AD08 00000000 */  nop   
/* 08F83C 7F05AD0C 00047C00 */  sll   $t7, $a0, 0x10
/* 08F840 7F05AD10 000F2403 */  sra   $a0, $t7, 0x10
.L7F05AD14:
/* 08F844 7F05AD14 0FC16AFC */  jal   acos
/* 08F848 7F05AD18 00000000 */   nop   
/* 08F84C 7F05AD1C 44829000 */  mtc1  $v0, $f18
/* 08F850 7F05AD20 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 08F854 7F05AD24 04410004 */  bgez  $v0, .L7F05AD38
/* 08F858 7F05AD28 46809120 */   cvt.s.w $f4, $f18
/* 08F85C 7F05AD2C 44813000 */  mtc1  $at, $f6
/* 08F860 7F05AD30 00000000 */  nop   
/* 08F864 7F05AD34 46062100 */  add.s $f4, $f4, $f6
.L7F05AD38:
/* 08F868 7F05AD38 3C018005 */  lui   $at, %hi(D_80053724)
/* 08F86C 7F05AD3C C4283724 */  lwc1  $f8, %lo(D_80053724)($at)
/* 08F870 7F05AD40 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08F874 7F05AD44 3C018005 */  lui   $at, %hi(D_80053728)
/* 08F878 7F05AD48 46082282 */  mul.s $f10, $f4, $f8
/* 08F87C 7F05AD4C C4303728 */  lwc1  $f16, %lo(D_80053728)($at)
/* 08F880 7F05AD50 27BD0018 */  addiu $sp, $sp, 0x18
/* 08F884 7F05AD54 03E00008 */  jr    $ra
/* 08F888 7F05AD58 46105003 */   div.s $f0, $f10, $f16
)
#endif

f32 asinf(f32 sinef) {
    s16 sines;
    if (1.0f <= sinef) {
        sines = (u16)0x7FFF;
    } else if (sinef <= -1.0f) {
        sines = (u16)-0x7FFF;
    } else {
        sines = (s16) (s32) (sinef * 32767.0f);
    }
    return ((f32)asin(sines) * 3.1415927f) / 65535.0f;
}
