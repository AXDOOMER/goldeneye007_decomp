#include <ultra64.h>
#include "padhalllv.h"
#include "bondtypes.h"
#include "chrai.h"

//pd decomp has a filesplit here
//all ge versions align properly 


#ifdef NONMATCHING
void sub_GAME_7F08EBD0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EBD0
/* 0C3700 7F08EBD0 3C028007 */  lui   $v0, %hi(g_CurrentSetup+0)
/* 0C3704 7F08EBD4 8C425D00 */  lw    $v0, %lo(g_CurrentSetup+0)($v0)
/* 0C3708 7F08EBD8 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 0C370C 7F08EBDC F7B40008 */  sdc1  $f20, 8($sp)
/* 0C3710 7F08EBE0 AFA50014 */  sw    $a1, 0x14($sp)
/* 0C3714 7F08EBE4 00803825 */  move  $a3, $a0
/* 0C3718 7F08EBE8 10400024 */  beqz  $v0, .L7F08EC7C
/* 0C371C 7F08EBEC 00001825 */   move  $v1, $zero
/* 0C3720 7F08EBF0 8C4E0000 */  lw    $t6, ($v0)
/* 0C3724 7F08EBF4 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0C3728 7F08EBF8 44810000 */  mtc1  $at, $f0
/* 0C372C 7F08EBFC 05C0001F */  bltz  $t6, .L7F08EC7C
/* 0C3730 7F08EC00 00402025 */   move  $a0, $v0
/* 0C3734 7F08EC04 3C068007 */  lui   $a2, %hi(g_CurrentSetup+0x18)
/* 0C3738 7F08EC08 C4EC0008 */  lwc1  $f12, 8($a3)
/* 0C373C 7F08EC0C C4F00000 */  lwc1  $f16, ($a3)
/* 0C3740 7F08EC10 4480A000 */  mtc1  $zero, $f20
/* 0C3744 7F08EC14 2407002C */  li    $a3, 44
/* 0C3748 7F08EC18 8CC65D18 */  lw    $a2, %lo(g_CurrentSetup+0x18)($a2)
/* 0C374C 7F08EC1C 8C450000 */  lw    $a1, ($v0)
.L7F08EC20:
/* 0C3750 7F08EC20 00A70019 */  multu $a1, $a3
/* 0C3754 7F08EC24 4614003C */  c.lt.s $f0, $f20
/* 0C3758 7F08EC28 00007812 */  mflo  $t7
/* 0C375C 7F08EC2C 01E61021 */  addu  $v0, $t7, $a2
/* 0C3760 7F08EC30 C4440008 */  lwc1  $f4, 8($v0)
/* 0C3764 7F08EC34 C4460000 */  lwc1  $f6, ($v0)
/* 0C3768 7F08EC38 46046381 */  sub.s $f14, $f12, $f4
/* 0C376C 7F08EC3C 46068481 */  sub.s $f18, $f16, $f6
/* 0C3770 7F08EC40 460E7202 */  mul.s $f8, $f14, $f14
/* 0C3774 7F08EC44 00000000 */  nop   
/* 0C3778 7F08EC48 46129282 */  mul.s $f10, $f18, $f18
/* 0C377C 7F08EC4C 45010005 */  bc1t  .L7F08EC64
/* 0C3780 7F08EC50 460A4080 */   add.s $f2, $f8, $f10
/* 0C3784 7F08EC54 4600103C */  c.lt.s $f2, $f0
/* 0C3788 7F08EC58 00000000 */  nop   
/* 0C378C 7F08EC5C 45020004 */  bc1fl .L7F08EC70
/* 0C3790 7F08EC60 8C850010 */   lw    $a1, 0x10($a0)
.L7F08EC64:
/* 0C3794 7F08EC64 46001006 */  mov.s $f0, $f2
/* 0C3798 7F08EC68 00801825 */  move  $v1, $a0
/* 0C379C 7F08EC6C 8C850010 */  lw    $a1, 0x10($a0)
.L7F08EC70:
/* 0C37A0 7F08EC70 24840010 */  addiu $a0, $a0, 0x10
/* 0C37A4 7F08EC74 04A1FFEA */  bgez  $a1, .L7F08EC20
/* 0C37A8 7F08EC78 00000000 */   nop   
.L7F08EC7C:
/* 0C37AC 7F08EC7C D7B40008 */  ldc1  $f20, 8($sp)
/* 0C37B0 7F08EC80 27BD0010 */  addiu $sp, $sp, 0x10
/* 0C37B4 7F08EC84 03E00008 */  jr    $ra
/* 0C37B8 7F08EC88 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EC8C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EC8C
/* 0C37BC 7F08EC8C AFA50004 */  sw    $a1, 4($sp)
/* 0C37C0 7F08EC90 8CC20004 */  lw    $v0, 4($a2)
/* 0C37C4 7F08EC94 00803825 */  move  $a3, $a0
/* 0C37C8 7F08EC98 00C01825 */  move  $v1, $a2
/* 0C37CC 7F08EC9C 1040002E */  beqz  $v0, .L7F08ED58
/* 0C37D0 7F08ECA0 00000000 */   nop   
/* 0C37D4 7F08ECA4 8CCE0000 */  lw    $t6, ($a2)
/* 0C37D8 7F08ECA8 240A002C */  li    $t2, 44
/* 0C37DC 7F08ECAC 3C0B8007 */  lui   $t3, %hi(g_CurrentSetup+0) 
/* 0C37E0 7F08ECB0 01CA0019 */  multu $t6, $t2
/* 0C37E4 7F08ECB4 256B5D00 */  addiu $t3, %lo(g_CurrentSetup+0) # addiu $t3, $t3, 0x5d00
/* 0C37E8 7F08ECB8 8D650018 */  lw    $a1, 0x18($t3)
/* 0C37EC 7F08ECBC C4E20008 */  lwc1  $f2, 8($a3)
/* 0C37F0 7F08ECC0 C4EE0000 */  lwc1  $f14, ($a3)
/* 0C37F4 7F08ECC4 8C490000 */  lw    $t1, ($v0)
/* 0C37F8 7F08ECC8 8D680000 */  lw    $t0, ($t3)
/* 0C37FC 7F08ECCC 00007812 */  mflo  $t7
/* 0C3800 7F08ECD0 01E52021 */  addu  $a0, $t7, $a1
/* 0C3804 7F08ECD4 C4840008 */  lwc1  $f4, 8($a0)
/* 0C3808 7F08ECD8 C4860000 */  lwc1  $f6, ($a0)
/* 0C380C 7F08ECDC 46041301 */  sub.s $f12, $f2, $f4
/* 0C3810 7F08ECE0 46067401 */  sub.s $f16, $f14, $f6
/* 0C3814 7F08ECE4 460C6202 */  mul.s $f8, $f12, $f12
/* 0C3818 7F08ECE8 00000000 */  nop   
/* 0C381C 7F08ECEC 46108282 */  mul.s $f10, $f16, $f16
/* 0C3820 7F08ECF0 05200019 */  bltz  $t1, .L7F08ED58
/* 0C3824 7F08ECF4 460A4000 */   add.s $f0, $f8, $f10
/* 0C3828 7F08ECF8 0009C100 */  sll   $t8, $t1, 4
.L7F08ECFC:
/* 0C382C 7F08ECFC 03083021 */  addu  $a2, $t8, $t0
/* 0C3830 7F08ED00 8CD90000 */  lw    $t9, ($a2)
/* 0C3834 7F08ED04 032A0019 */  multu $t9, $t2
/* 0C3838 7F08ED08 00006012 */  mflo  $t4
/* 0C383C 7F08ED0C 01852021 */  addu  $a0, $t4, $a1
/* 0C3840 7F08ED10 C4840008 */  lwc1  $f4, 8($a0)
/* 0C3844 7F08ED14 C4860000 */  lwc1  $f6, ($a0)
/* 0C3848 7F08ED18 46041301 */  sub.s $f12, $f2, $f4
/* 0C384C 7F08ED1C 46067401 */  sub.s $f16, $f14, $f6
/* 0C3850 7F08ED20 460C6202 */  mul.s $f8, $f12, $f12
/* 0C3854 7F08ED24 00000000 */  nop   
/* 0C3858 7F08ED28 46108282 */  mul.s $f10, $f16, $f16
/* 0C385C 7F08ED2C 460A4480 */  add.s $f18, $f8, $f10
/* 0C3860 7F08ED30 4600903C */  c.lt.s $f18, $f0
/* 0C3864 7F08ED34 00000000 */  nop   
/* 0C3868 7F08ED38 45000003 */  bc1f  .L7F08ED48
/* 0C386C 7F08ED3C 00000000 */   nop   
/* 0C3870 7F08ED40 46009006 */  mov.s $f0, $f18
/* 0C3874 7F08ED44 00C01825 */  move  $v1, $a2
.L7F08ED48:
/* 0C3878 7F08ED48 8C490004 */  lw    $t1, 4($v0)
/* 0C387C 7F08ED4C 24420004 */  addiu $v0, $v0, 4
/* 0C3880 7F08ED50 0523FFEA */  bgezl $t1, .L7F08ECFC
/* 0C3884 7F08ED54 0009C100 */   sll   $t8, $t1, 4
.L7F08ED58:
/* 0C3888 7F08ED58 03E00008 */  jr    $ra
/* 0C388C 7F08ED5C 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
waygroup* sub_GAME_7F08ED60(s32 *groupnums, s32 value) {

}
#else
waygroup* sub_GAME_7F08ED60(s32 *groupnums, s32 value);
GLOBAL_ASM(
.text
glabel sub_GAME_7F08ED60
/* 0C3890 7F08ED60 8C830000 */  lw    $v1, ($a0)
/* 0C3894 7F08ED64 3C028007 */  lui   $v0, %hi(g_CurrentSetup+4)
/* 0C3898 7F08ED68 00A03025 */  move  $a2, $a1
/* 0C389C 7F08ED6C 0460000E */  bltz  $v1, .L7F08EDA8
/* 0C38A0 7F08ED70 8C425D04 */   lw    $v0, %lo(g_CurrentSetup+4)($v0)
/* 0C38A4 7F08ED74 2407000C */  li    $a3, 12
.L7F08ED78:
/* 0C38A8 7F08ED78 00670019 */  multu $v1, $a3
/* 0C38AC 7F08ED7C 00007012 */  mflo  $t6
/* 0C38B0 7F08ED80 01C22821 */  addu  $a1, $t6, $v0
/* 0C38B4 7F08ED84 8CAF0008 */  lw    $t7, 8($a1)
/* 0C38B8 7F08ED88 54CF0004 */  bnel  $a2, $t7, .L7F08ED9C
/* 0C38BC 7F08ED8C 8C830004 */   lw    $v1, 4($a0)
/* 0C38C0 7F08ED90 03E00008 */  jr    $ra
/* 0C38C4 7F08ED94 00A01025 */   move  $v0, $a1

/* 0C38C8 7F08ED98 8C830004 */  lw    $v1, 4($a0)
.L7F08ED9C:
/* 0C38CC 7F08ED9C 24840004 */  addiu $a0, $a0, 4
/* 0C38D0 7F08EDA0 0461FFF5 */  bgez  $v1, .L7F08ED78
/* 0C38D4 7F08EDA4 00000000 */   nop   
.L7F08EDA8:
/* 0C38D8 7F08EDA8 00001025 */  move  $v0, $zero
/* 0C38DC 7F08EDAC 03E00008 */  jr    $ra
/* 0C38E0 7F08EDB0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EDB4(s32 *groupnums, s32 value) {

}
#else
void sub_GAME_7F08EDB4(s32 *groupnums, s32 value);
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EDB4
/* 0C38E4 7F08EDB4 8C830000 */  lw    $v1, ($a0)
/* 0C38E8 7F08EDB8 3C028007 */  lui   $v0, %hi(g_CurrentSetup+4)
/* 0C38EC 7F08EDBC 00A03025 */  move  $a2, $a1
/* 0C38F0 7F08EDC0 0460000D */  bltz  $v1, .L7F08EDF8
/* 0C38F4 7F08EDC4 8C425D04 */   lw    $v0, %lo(g_CurrentSetup+4)($v0)
/* 0C38F8 7F08EDC8 2407000C */  li    $a3, 12
.L7F08EDCC:
/* 0C38FC 7F08EDCC 00670019 */  multu $v1, $a3
/* 0C3900 7F08EDD0 00007012 */  mflo  $t6
/* 0C3904 7F08EDD4 01C22821 */  addu  $a1, $t6, $v0
/* 0C3908 7F08EDD8 8CAF0008 */  lw    $t7, 8($a1)
/* 0C390C 7F08EDDC 05E30003 */  bgezl $t7, .L7F08EDEC
/* 0C3910 7F08EDE0 8C830004 */   lw    $v1, 4($a0)
/* 0C3914 7F08EDE4 ACA60008 */  sw    $a2, 8($a1)
/* 0C3918 7F08EDE8 8C830004 */  lw    $v1, 4($a0)
.L7F08EDEC:
/* 0C391C 7F08EDEC 24840004 */  addiu $a0, $a0, 4
/* 0C3920 7F08EDF0 0461FFF6 */  bgez  $v1, .L7F08EDCC
/* 0C3924 7F08EDF4 00000000 */   nop   
.L7F08EDF8:
/* 0C3928 7F08EDF8 03E00008 */  jr    $ra
/* 0C392C 7F08EDFC 00000000 */   nop   
)
#endif


/**
 * Iterate the given groups and find any with an dist matching arg1.
 * For all groups that match, iterate their neighbouring groups and set their
 * dist to arg1 + 1, but only if their they have no existing dist value.
 *
 * Return true if any matched.
 */
bool sub_GAME_7F08EE00(struct waygroup *group, s32 arg1)
{
    bool result = FALSE;

    while (group->neighbours)
    {
        if (group->dist == arg1)
        {
            result = TRUE;
            sub_GAME_7F08EDB4(group->neighbours, arg1 + 1);
        }

        group++;
    }

    return result;
}


bool sub_GAME_7F08EE70(struct waygroup *from, struct waygroup *to, struct waygroup *groups, s32 arg3)
{
    bool result = TRUE;
    struct waygroup *group;
    s32 i;

    for (group = groups; group->neighbours; group++)
    {
        group->dist = -1;
    }

    from->dist = 0;

    for (i = 0; (arg3 || to->dist < 0) && result; i++)
    {
        result = sub_GAME_7F08EE00(groups, i);
    }

    return result;
}


#ifdef NONMATCHING
bool sub_GAME_7F08EF1C(waygroup *from, waygroup *to, waygroup *groups) {

}
#else
bool sub_GAME_7F08EF1C(waygroup *from, waygroup *to, waygroup *groups);
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EF1C
/* 0C3A4C 7F08EF1C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C3A50 7F08EF20 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C3A54 7F08EF24 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C3A58 7F08EF28 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C3A5C 7F08EF2C AFA50034 */  sw    $a1, 0x34($sp)
/* 0C3A60 7F08EF30 0FC23B9C */  jal   sub_GAME_7F08EE70
/* 0C3A64 7F08EF34 00003825 */   move  $a3, $zero
/* 0C3A68 7F08EF38 8FA50034 */  lw    $a1, 0x34($sp)
/* 0C3A6C 7F08EF3C 10400012 */  beqz  $v0, .L7F08EF88
/* 0C3A70 7F08EF40 AFA20024 */   sw    $v0, 0x24($sp)
/* 0C3A74 7F08EF44 8CB00008 */  lw    $s0, 8($a1)
/* 0C3A78 7F08EF48 00A08825 */  move  $s1, $a1
/* 0C3A7C 7F08EF4C 2610FFFF */  addiu $s0, $s0, -1
/* 0C3A80 7F08EF50 0602000B */  bltzl $s0, .L7F08EF80
/* 0C3A84 7F08EF54 8E380008 */   lw    $t8, 8($s1)
.L7F08EF58:
/* 0C3A88 7F08EF58 8E2E0008 */  lw    $t6, 8($s1)
/* 0C3A8C 7F08EF5C 8E240000 */  lw    $a0, ($s1)
/* 0C3A90 7F08EF60 02002825 */  move  $a1, $s0
/* 0C3A94 7F08EF64 25CF2710 */  addiu $t7, $t6, 0x2710
/* 0C3A98 7F08EF68 0FC23B58 */  jal   sub_GAME_7F08ED60
/* 0C3A9C 7F08EF6C AE2F0008 */   sw    $t7, 8($s1)
/* 0C3AA0 7F08EF70 2610FFFF */  addiu $s0, $s0, -1
/* 0C3AA4 7F08EF74 0601FFF8 */  bgez  $s0, .L7F08EF58
/* 0C3AA8 7F08EF78 00408825 */   move  $s1, $v0
/* 0C3AAC 7F08EF7C 8E380008 */  lw    $t8, 8($s1)
.L7F08EF80:
/* 0C3AB0 7F08EF80 27192710 */  addiu $t9, $t8, 0x2710
/* 0C3AB4 7F08EF84 AE390008 */  sw    $t9, 8($s1)
.L7F08EF88:
/* 0C3AB8 7F08EF88 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C3ABC 7F08EF8C 8FA20024 */  lw    $v0, 0x24($sp)
/* 0C3AC0 7F08EF90 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C3AC4 7F08EF94 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C3AC8 7F08EF98 03E00008 */  jr    $ra
/* 0C3ACC 7F08EF9C 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EFA0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EFA0
/* 0C3AD0 7F08EFA0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C3AD4 7F08EFA4 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C3AD8 7F08EFA8 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C3ADC 7F08EFAC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C3AE0 7F08EFB0 28E10002 */  slti  $at, $a3, 2
/* 0C3AE4 7F08EFB4 00E09825 */  move  $s3, $a3
/* 0C3AE8 7F08EFB8 00A0A025 */  move  $s4, $a1
/* 0C3AEC 7F08EFBC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C3AF0 7F08EFC0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C3AF4 7F08EFC4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C3AF8 7F08EFC8 AFA60038 */  sw    $a2, 0x38($sp)
/* 0C3AFC 7F08EFCC 14200022 */  bnez  $at, .L7F08F058
/* 0C3B00 7F08EFD0 00C08825 */   move  $s1, $a2
/* 0C3B04 7F08EFD4 3C068007 */  lui   $a2, %hi(g_CurrentSetup+4)
/* 0C3B08 7F08EFD8 8CC65D04 */  lw    $a2, %lo(g_CurrentSetup+4)($a2)
/* 0C3B0C 7F08EFDC 50C0001F */  beql  $a2, $zero, .L7F08F05C
/* 0C3B10 7F08EFE0 AE200000 */   sw    $zero, ($s1)
/* 0C3B14 7F08EFE4 0FC23BC7 */  jal   sub_GAME_7F08EF1C
/* 0C3B18 7F08EFE8 AFA40030 */   sw    $a0, 0x30($sp)
/* 0C3B1C 7F08EFEC 1040001A */  beqz  $v0, .L7F08F058
/* 0C3B20 7F08EFF0 8FA40030 */   lw    $a0, 0x30($sp)
/* 0C3B24 7F08EFF4 8FA20038 */  lw    $v0, 0x38($sp)
/* 0C3B28 7F08EFF8 00809025 */  move  $s2, $a0
/* 0C3B2C 7F08EFFC 2673270F */  addiu $s3, $s3, 0x270f
/* 0C3B30 7F08F000 AC440000 */  sw    $a0, ($v0)
/* 0C3B34 7F08F004 8E8E0008 */  lw    $t6, 8($s4)
/* 0C3B38 7F08F008 24102711 */  li    $s0, 10001
/* 0C3B3C 7F08F00C 24510004 */  addiu $s1, $v0, 4
/* 0C3B40 7F08F010 29C12711 */  slti  $at, $t6, 0x2711
/* 0C3B44 7F08F014 14200010 */  bnez  $at, .L7F08F058
/* 0C3B48 7F08F018 2A612712 */   slti  $at, $s3, 0x2712
/* 0C3B4C 7F08F01C 5420000F */  bnezl $at, .L7F08F05C
/* 0C3B50 7F08F020 AE200000 */   sw    $zero, ($s1)
/* 0C3B54 7F08F024 8E440000 */  lw    $a0, ($s2)
.L7F08F028:
/* 0C3B58 7F08F028 0FC23B58 */  jal   sub_GAME_7F08ED60
/* 0C3B5C 7F08F02C 02002825 */   move  $a1, $s0
/* 0C3B60 7F08F030 AE220000 */  sw    $v0, ($s1)
/* 0C3B64 7F08F034 8E8F0008 */  lw    $t7, 8($s4)
/* 0C3B68 7F08F038 26100001 */  addiu $s0, $s0, 1
/* 0C3B6C 7F08F03C 00409025 */  move  $s2, $v0
/* 0C3B70 7F08F040 01F0082A */  slt   $at, $t7, $s0
/* 0C3B74 7F08F044 14200004 */  bnez  $at, .L7F08F058
/* 0C3B78 7F08F048 26310004 */   addiu $s1, $s1, 4
/* 0C3B7C 7F08F04C 0213082A */  slt   $at, $s0, $s3
/* 0C3B80 7F08F050 5420FFF5 */  bnezl $at, .L7F08F028
/* 0C3B84 7F08F054 8E440000 */   lw    $a0, ($s2)
.L7F08F058:
/* 0C3B88 7F08F058 AE200000 */  sw    $zero, ($s1)
.L7F08F05C:
/* 0C3B8C 7F08F05C 8FB80038 */  lw    $t8, 0x38($sp)
/* 0C3B90 7F08F060 26310004 */  addiu $s1, $s1, 4
/* 0C3B94 7F08F064 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C3B98 7F08F068 02381023 */  subu  $v0, $s1, $t8
/* 0C3B9C 7F08F06C 0002C883 */  sra   $t9, $v0, 2
/* 0C3BA0 7F08F070 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C3BA4 7F08F074 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C3BA8 7F08F078 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C3BAC 7F08F07C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C3BB0 7F08F080 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C3BB4 7F08F084 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C3BB8 7F08F088 03E00008 */  jr    $ra
/* 0C3BBC 7F08F08C 03201025 */   move  $v0, $t9
)
#endif


waypoint *findPadWithDistAndSet(s32 *pointnums, s32 arg1, s32 groupnum)
{
    waypoint *points = g_CurrentSetup.pathwaypoints;

    while (*pointnums >= 0)
    {
        waypoint *point = &points[*pointnums];

        if (point->groupNum == groupnum && point->dist == arg1)
        {
            return point;
        }

        *pointnums++;
    }

    return NULL;
}


void sub_GAME_7F08F0E8(s32 *pointnums, s32 value, s32 groupnum)
{
    waypoint *waypoints = g_CurrentSetup.pathwaypoints;

    while (*pointnums >= 0)
    {
        waypoint *waypoint = &waypoints[*pointnums];

        if (waypoint->groupNum == groupnum && waypoint->dist < 0)
        {
            waypoint->dist = value;
        }

        *pointnums++;
    }
}


bool sub_GAME_7F08F138(s32 *pointnums, s32 arg1, s32 groupnum)
{
    bool result = FALSE;
    waypoint *points = g_CurrentSetup.pathwaypoints;

    while (*pointnums >= 0)
    {
        waypoint *point = &points[*pointnums];

        if (arg1 == point->dist && point->neighbours)
        {
            result = TRUE;
            sub_GAME_7F08F0E8(point->neighbours, arg1 + 1, groupnum);
        }

        pointnums++;
    }

    return result;
}


void do_BFS_withinPathSet(waypoint *from, waypoint *to, s32 arg2)
{
    waygroup *groups = g_CurrentSetup.waypointgroups;
    waypoint *points = g_CurrentSetup.pathwaypoints;
    waypoint *point;
    s32 *pointnums = groups[from->groupNum].waypoints;
    s32 i;
    bool more;

    while (*pointnums >= 0)
    {
        point = &points[*pointnums];
        point->dist = -1;
        pointnums++;
    }

    from->dist = 0;

    more = TRUE;

    for (i = 0; (arg2 || to->dist < 0) && more; i++)
    {
        more = sub_GAME_7F08F138(groups[from->groupNum].waypoints, i, from->groupNum);
    }
}


void sub_GAME_7F08F2CC(waypoint *from, waypoint *to)
{
    waypoint *curto;
    s32 value;

    do_BFS_withinPathSet(from, to, 0);

    value = to->dist - 1;
    curto = to;

    while (value >= 0)
    {
        curto->dist += 10000;
        curto = findPadWithDistAndSet(curto->neighbours, value, from->groupNum);

        value--;
    }

    curto->dist += 10000;
}


s32 sub_GAME_7F08F350(waypoint *from, waypoint *to, waypoint **arr, s32 arrlen)
{
    waypoint **arrptr = arr;
    waypoint *curfrom;
    s32 i;

    if (arrlen >= 2)
    {
        sub_GAME_7F08F2CC(from, to);

        *arr = from;
        arrptr++;

        curfrom = from;
        arrlen += 9999;
        i = 10001;

        while (i <= to->dist && i < arrlen)
        {
            curfrom = findPadWithDistAndSet(curfrom->neighbours, i, from->groupNum);
            *arrptr = curfrom;
            arrptr++;
            i++;
        }
    }

    *arrptr = NULL;
    arrptr++;

    return arrptr - arr;
}


#ifdef NONMATCHING
void sub_GAME_7F08F438(waygroup *groupa, waygroup *groupb, waypoint **pointa, waypoint **pointb) {

}
#else
void sub_GAME_7F08F438(waygroup *groupa, waygroup *groupb, waypoint **pointa, waypoint **pointb);
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F438
/* 0C3F68 7F08F438 27BDFFF8 */  addiu $sp, $sp, -8
/* 0C3F6C 7F08F43C AFB00004 */  sw    $s0, 4($sp)
/* 0C3F70 7F08F440 AFA60010 */  sw    $a2, 0x10($sp)
/* 0C3F74 7F08F444 AFA70014 */  sw    $a3, 0x14($sp)
/* 0C3F78 7F08F448 8C880004 */  lw    $t0, 4($a0)
/* 0C3F7C 7F08F44C 3C0A8007 */  lui   $t2, %hi(g_CurrentSetup+0) 
/* 0C3F80 7F08F450 254A5D00 */  addiu $t2, %lo(g_CurrentSetup+0) # addiu $t2, $t2, 0x5d00
/* 0C3F84 7F08F454 8D090000 */  lw    $t1, ($t0)
/* 0C3F88 7F08F458 00A08025 */  move  $s0, $a1
/* 0C3F8C 7F08F45C 8D420000 */  lw    $v0, ($t2)
/* 0C3F90 7F08F460 0520001C */  bltz  $t1, .L7F08F4D4
/* 0C3F94 7F08F464 8D430004 */   lw    $v1, 4($t2)
/* 0C3F98 7F08F468 240A000C */  li    $t2, 12
/* 0C3F9C 7F08F46C 00097100 */  sll   $t6, $t1, 4
.L7F08F470:
/* 0C3FA0 7F08F470 01C22021 */  addu  $a0, $t6, $v0
/* 0C3FA4 7F08F474 8C850004 */  lw    $a1, 4($a0)
/* 0C3FA8 7F08F478 8CA60000 */  lw    $a2, ($a1)
/* 0C3FAC 7F08F47C 04C00011 */  bltz  $a2, .L7F08F4C4
/* 0C3FB0 7F08F480 00067900 */   sll   $t7, $a2, 4
.L7F08F484:
/* 0C3FB4 7F08F484 01E23821 */  addu  $a3, $t7, $v0
/* 0C3FB8 7F08F488 8CF80008 */  lw    $t8, 8($a3)
/* 0C3FBC 7F08F48C 030A0019 */  multu $t8, $t2
/* 0C3FC0 7F08F490 0000C812 */  mflo  $t9
/* 0C3FC4 7F08F494 03235821 */  addu  $t3, $t9, $v1
/* 0C3FC8 7F08F498 560B0007 */  bnel  $s0, $t3, .L7F08F4B8
/* 0C3FCC 7F08F49C 8CA60004 */   lw    $a2, 4($a1)
/* 0C3FD0 7F08F4A0 8FAC0010 */  lw    $t4, 0x10($sp)
/* 0C3FD4 7F08F4A4 AD840000 */  sw    $a0, ($t4)
/* 0C3FD8 7F08F4A8 8FAD0014 */  lw    $t5, 0x14($sp)
/* 0C3FDC 7F08F4AC 1000000D */  b     .L7F08F4E4
/* 0C3FE0 7F08F4B0 ADA70000 */   sw    $a3, ($t5)
/* 0C3FE4 7F08F4B4 8CA60004 */  lw    $a2, 4($a1)
.L7F08F4B8:
/* 0C3FE8 7F08F4B8 24A50004 */  addiu $a1, $a1, 4
/* 0C3FEC 7F08F4BC 04C3FFF1 */  bgezl $a2, .L7F08F484
/* 0C3FF0 7F08F4C0 00067900 */   sll   $t7, $a2, 4
.L7F08F4C4:
/* 0C3FF4 7F08F4C4 8D090004 */  lw    $t1, 4($t0)
/* 0C3FF8 7F08F4C8 25080004 */  addiu $t0, $t0, 4
/* 0C3FFC 7F08F4CC 0523FFE8 */  bgezl $t1, .L7F08F470
/* 0C4000 7F08F4D0 00097100 */   sll   $t6, $t1, 4
.L7F08F4D4:
/* 0C4004 7F08F4D4 8FAE0014 */  lw    $t6, 0x14($sp)
/* 0C4008 7F08F4D8 ADC00000 */  sw    $zero, ($t6)
/* 0C400C 7F08F4DC 8FAF0010 */  lw    $t7, 0x10($sp)
/* 0C4010 7F08F4E0 ADE00000 */  sw    $zero, ($t7)
.L7F08F4E4:
/* 0C4014 7F08F4E4 8FB00004 */  lw    $s0, 4($sp)
/* 0C4018 7F08F4E8 03E00008 */  jr    $ra
/* 0C401C 7F08F4EC 27BD0008 */   addiu $sp, $sp, 8
)
#endif

/**
 * Find a route from frompoint to topoint. The arr argument will be populated
 * with pointers to the route's waypoints. If arr is not big enough then only
 * the first part of the route will be populated into the array.
 *
 * The return value is the number of elements populated into the array.
 */
s32 waypointFindRoute(waypoint *frompoint, waypoint *topoint, waypoint **arr, s32 arrlen)
{
    waypoint **arrptr = arr;
    waygroup *groups = g_CurrentSetup.waypointgroups;

    if (groups)
    {
        waygroup *fromgroup = &groups[frompoint->groupNum];
        waygroup *togroup = &groups[topoint->groupNum];

        if (sub_GAME_7F08EF1C(fromgroup, togroup, groups))
        {
            waypoint *curfrompoint = frompoint;
            waygroup *curfromgroup = fromgroup;
            s32 i;

            for (i = fromgroup->dist + 1; i <= togroup->dist && arrlen >= 2; i++)
            {
                s32 numwritten;
                waygroup *nextfromgroup = sub_GAME_7F08ED60(curfromgroup->neighbours, i);
                waypoint *tmppoint;
                waypoint *nextfrompoint;

                sub_GAME_7F08F438(curfromgroup, nextfromgroup, &tmppoint, &nextfrompoint);
                numwritten = sub_GAME_7F08F350(curfrompoint, tmppoint, arrptr, arrlen) - 1;

                arrlen -= numwritten;
                arrptr += numwritten;

                curfrompoint = nextfrompoint;
                curfromgroup = nextfromgroup;
            }

            arrptr += sub_GAME_7F08F350(curfrompoint, topoint, arrptr, arrlen) - 1;
        }
    }

    *arrptr = NULL;
    arrptr++;

    return arrptr - arr;
}


void resetWaypointDistances(void)
{
    waypoint * waypoint;
    waypoint = g_CurrentSetup.pathwaypoints;

    while(waypoint->padID >= 0)
    {
        waypoint->dist = -1;
        waypoint++;
    }
}


#ifdef NONMATCHING
waypoint *sub_GAME_7F08F6B0(s32 *pointnums, s32 arg1) {

}
#else
waypoint *sub_GAME_7F08F6B0(s32 *pointnums, s32 arg1);
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F6B0
/* 0C41E0 7F08F6B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C41E4 7F08F6B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C41E8 7F08F6B8 8C8E0000 */  lw    $t6, ($a0)
/* 0C41EC 7F08F6BC 00A03825 */  move  $a3, $a1
/* 0C41F0 7F08F6C0 00004825 */  move  $t1, $zero
/* 0C41F4 7F08F6C4 05C00006 */  bltz  $t6, .L7F08F6E0
/* 0C41F8 7F08F6C8 00801025 */   move  $v0, $a0
/* 0C41FC 7F08F6CC 8C4F0004 */  lw    $t7, 4($v0)
.L7F08F6D0:
/* 0C4200 7F08F6D0 25290001 */  addiu $t1, $t1, 1
/* 0C4204 7F08F6D4 24420004 */  addiu $v0, $v0, 4
/* 0C4208 7F08F6D8 05E3FFFD */  bgezl $t7, .L7F08F6D0
/* 0C420C 7F08F6DC 8C4F0004 */   lw    $t7, 4($v0)
.L7F08F6E0:
/* 0C4210 7F08F6E0 AFA40020 */  sw    $a0, 0x20($sp)
/* 0C4214 7F08F6E4 AFA70024 */  sw    $a3, 0x24($sp)
/* 0C4218 7F08F6E8 0C002914 */  jal   randomGetNext
/* 0C421C 7F08F6EC AFA9001C */   sw    $t1, 0x1c($sp)
/* 0C4220 7F08F6F0 8FA9001C */  lw    $t1, 0x1c($sp)
/* 0C4224 7F08F6F4 8FA70024 */  lw    $a3, 0x24($sp)
/* 0C4228 7F08F6F8 8FAC0020 */  lw    $t4, 0x20($sp)
/* 0C422C 7F08F6FC 0049001B */  divu  $zero, $v0, $t1
/* 0C4230 7F08F700 00005810 */  mfhi  $t3
/* 0C4234 7F08F704 0169082A */  slt   $at, $t3, $t1
/* 0C4238 7F08F708 15200002 */  bnez  $t1, .L7F08F714
/* 0C423C 7F08F70C 00000000 */   nop   
/* 0C4240 7F08F710 0007000D */  break 7
.L7F08F714:
/* 0C4244 7F08F714 01605025 */  move  $t2, $t3
/* 0C4248 7F08F718 1020003C */  beqz  $at, .L7F08F80C
/* 0C424C 7F08F71C 01603025 */   move  $a2, $t3
/* 0C4250 7F08F720 012B1823 */  subu  $v1, $t1, $t3
/* 0C4254 7F08F724 30780003 */  andi  $t8, $v1, 3
/* 0C4258 7F08F728 13000011 */  beqz  $t8, .L7F08F770
/* 0C425C 7F08F72C 030B4021 */   addu  $t0, $t8, $t3
/* 0C4260 7F08F730 0006C880 */  sll   $t9, $a2, 2
/* 0C4264 7F08F734 3C058007 */  lui   $a1, %hi(g_CurrentSetup+0)
/* 0C4268 7F08F738 8CA55D00 */  lw    $a1, %lo(g_CurrentSetup+0)($a1)
/* 0C426C 7F08F73C 01991021 */  addu  $v0, $t4, $t9
.L7F08F740:
/* 0C4270 7F08F740 8C4D0000 */  lw    $t5, ($v0)
/* 0C4274 7F08F744 24C60001 */  addiu $a2, $a2, 1
/* 0C4278 7F08F748 000D7100 */  sll   $t6, $t5, 4
/* 0C427C 7F08F74C 01C52021 */  addu  $a0, $t6, $a1
/* 0C4280 7F08F750 8C8F000C */  lw    $t7, 0xc($a0)
/* 0C4284 7F08F754 14EF0003 */  bne   $a3, $t7, .L7F08F764
/* 0C4288 7F08F758 00000000 */   nop   
/* 0C428C 7F08F75C 10000066 */  b     .L7F08F8F8
/* 0C4290 7F08F760 00801025 */   move  $v0, $a0
.L7F08F764:
/* 0C4294 7F08F764 1506FFF6 */  bne   $t0, $a2, .L7F08F740
/* 0C4298 7F08F768 24420004 */   addiu $v0, $v0, 4
/* 0C429C 7F08F76C 10C90027 */  beq   $a2, $t1, .L7F08F80C
.L7F08F770:
/* 0C42A0 7F08F770 0006C080 */   sll   $t8, $a2, 2
/* 0C42A4 7F08F774 3C058007 */  lui   $a1, %hi(g_CurrentSetup+0)
/* 0C42A8 7F08F778 8CA55D00 */  lw    $a1, %lo(g_CurrentSetup+0)($a1)
/* 0C42AC 7F08F77C 01981021 */  addu  $v0, $t4, $t8
.L7F08F780:
/* 0C42B0 7F08F780 8C590000 */  lw    $t9, ($v0)
/* 0C42B4 7F08F784 24C60004 */  addiu $a2, $a2, 4
/* 0C42B8 7F08F788 00196900 */  sll   $t5, $t9, 4
/* 0C42BC 7F08F78C 01A52021 */  addu  $a0, $t5, $a1
/* 0C42C0 7F08F790 8C8E000C */  lw    $t6, 0xc($a0)
/* 0C42C4 7F08F794 54EE0004 */  bnel  $a3, $t6, .L7F08F7A8
/* 0C42C8 7F08F798 8C4F0004 */   lw    $t7, 4($v0)
/* 0C42CC 7F08F79C 10000056 */  b     .L7F08F8F8
/* 0C42D0 7F08F7A0 00801025 */   move  $v0, $a0
/* 0C42D4 7F08F7A4 8C4F0004 */  lw    $t7, 4($v0)
.L7F08F7A8:
/* 0C42D8 7F08F7A8 000FC100 */  sll   $t8, $t7, 4
/* 0C42DC 7F08F7AC 03051821 */  addu  $v1, $t8, $a1
/* 0C42E0 7F08F7B0 8C79000C */  lw    $t9, 0xc($v1)
/* 0C42E4 7F08F7B4 54F90004 */  bnel  $a3, $t9, .L7F08F7C8
/* 0C42E8 7F08F7B8 8C4D0008 */   lw    $t5, 8($v0)
/* 0C42EC 7F08F7BC 1000004E */  b     .L7F08F8F8
/* 0C42F0 7F08F7C0 00601025 */   move  $v0, $v1
/* 0C42F4 7F08F7C4 8C4D0008 */  lw    $t5, 8($v0)
.L7F08F7C8:
/* 0C42F8 7F08F7C8 000D7100 */  sll   $t6, $t5, 4
/* 0C42FC 7F08F7CC 01C51821 */  addu  $v1, $t6, $a1
/* 0C4300 7F08F7D0 8C6F000C */  lw    $t7, 0xc($v1)
/* 0C4304 7F08F7D4 54EF0004 */  bnel  $a3, $t7, .L7F08F7E8
/* 0C4308 7F08F7D8 8C58000C */   lw    $t8, 0xc($v0)
/* 0C430C 7F08F7DC 10000046 */  b     .L7F08F8F8
/* 0C4310 7F08F7E0 00601025 */   move  $v0, $v1
/* 0C4314 7F08F7E4 8C58000C */  lw    $t8, 0xc($v0)
.L7F08F7E8:
/* 0C4318 7F08F7E8 0018C900 */  sll   $t9, $t8, 4
/* 0C431C 7F08F7EC 03251821 */  addu  $v1, $t9, $a1
/* 0C4320 7F08F7F0 8C6D000C */  lw    $t5, 0xc($v1)
/* 0C4324 7F08F7F4 14ED0003 */  bne   $a3, $t5, .L7F08F804
/* 0C4328 7F08F7F8 00000000 */   nop   
/* 0C432C 7F08F7FC 1000003E */  b     .L7F08F8F8
/* 0C4330 7F08F800 00601025 */   move  $v0, $v1
.L7F08F804:
/* 0C4334 7F08F804 14C9FFDE */  bne   $a2, $t1, .L7F08F780
/* 0C4338 7F08F808 24420010 */   addiu $v0, $v0, 0x10
.L7F08F80C:
/* 0C433C 7F08F80C 19600039 */  blez  $t3, .L7F08F8F4
/* 0C4340 7F08F810 00003025 */   move  $a2, $zero
/* 0C4344 7F08F814 3C058007 */  lui   $a1, %hi(g_CurrentSetup+0)
/* 0C4348 7F08F818 31630003 */  andi  $v1, $t3, 3
/* 0C434C 7F08F81C 10600010 */  beqz  $v1, .L7F08F860
/* 0C4350 7F08F820 8CA55D00 */   lw    $a1, %lo(g_CurrentSetup+0)($a1)
/* 0C4354 7F08F824 00007080 */  sll   $t6, $zero, 2
/* 0C4358 7F08F828 018E1021 */  addu  $v0, $t4, $t6
/* 0C435C 7F08F82C 00604025 */  move  $t0, $v1
.L7F08F830:
/* 0C4360 7F08F830 8C4F0000 */  lw    $t7, ($v0)
/* 0C4364 7F08F834 24C60001 */  addiu $a2, $a2, 1
/* 0C4368 7F08F838 000FC100 */  sll   $t8, $t7, 4
/* 0C436C 7F08F83C 03052021 */  addu  $a0, $t8, $a1
/* 0C4370 7F08F840 8C99000C */  lw    $t9, 0xc($a0)
/* 0C4374 7F08F844 14F90003 */  bne   $a3, $t9, .L7F08F854
/* 0C4378 7F08F848 00000000 */   nop   
/* 0C437C 7F08F84C 1000002A */  b     .L7F08F8F8
/* 0C4380 7F08F850 00801025 */   move  $v0, $a0
.L7F08F854:
/* 0C4384 7F08F854 1506FFF6 */  bne   $t0, $a2, .L7F08F830
/* 0C4388 7F08F858 24420004 */   addiu $v0, $v0, 4
/* 0C438C 7F08F85C 10CB0025 */  beq   $a2, $t3, .L7F08F8F4
.L7F08F860:
/* 0C4390 7F08F860 00066880 */   sll   $t5, $a2, 2
/* 0C4394 7F08F864 018D1021 */  addu  $v0, $t4, $t5
.L7F08F868:
/* 0C4398 7F08F868 8C4E0000 */  lw    $t6, ($v0)
/* 0C439C 7F08F86C 24C60004 */  addiu $a2, $a2, 4
/* 0C43A0 7F08F870 000E7900 */  sll   $t7, $t6, 4
/* 0C43A4 7F08F874 01E52021 */  addu  $a0, $t7, $a1
/* 0C43A8 7F08F878 8C98000C */  lw    $t8, 0xc($a0)
/* 0C43AC 7F08F87C 54F80004 */  bnel  $a3, $t8, .L7F08F890
/* 0C43B0 7F08F880 8C590004 */   lw    $t9, 4($v0)
/* 0C43B4 7F08F884 1000001C */  b     .L7F08F8F8
/* 0C43B8 7F08F888 00801025 */   move  $v0, $a0
/* 0C43BC 7F08F88C 8C590004 */  lw    $t9, 4($v0)
.L7F08F890:
/* 0C43C0 7F08F890 00196900 */  sll   $t5, $t9, 4
/* 0C43C4 7F08F894 01A51821 */  addu  $v1, $t5, $a1
/* 0C43C8 7F08F898 8C6E000C */  lw    $t6, 0xc($v1)
/* 0C43CC 7F08F89C 54EE0004 */  bnel  $a3, $t6, .L7F08F8B0
/* 0C43D0 7F08F8A0 8C4F0008 */   lw    $t7, 8($v0)
/* 0C43D4 7F08F8A4 10000014 */  b     .L7F08F8F8
/* 0C43D8 7F08F8A8 00601025 */   move  $v0, $v1
/* 0C43DC 7F08F8AC 8C4F0008 */  lw    $t7, 8($v0)
.L7F08F8B0:
/* 0C43E0 7F08F8B0 000FC100 */  sll   $t8, $t7, 4
/* 0C43E4 7F08F8B4 03051821 */  addu  $v1, $t8, $a1
/* 0C43E8 7F08F8B8 8C79000C */  lw    $t9, 0xc($v1)
/* 0C43EC 7F08F8BC 54F90004 */  bnel  $a3, $t9, .L7F08F8D0
/* 0C43F0 7F08F8C0 8C4D000C */   lw    $t5, 0xc($v0)
/* 0C43F4 7F08F8C4 1000000C */  b     .L7F08F8F8
/* 0C43F8 7F08F8C8 00601025 */   move  $v0, $v1
/* 0C43FC 7F08F8CC 8C4D000C */  lw    $t5, 0xc($v0)
.L7F08F8D0:
/* 0C4400 7F08F8D0 000D7100 */  sll   $t6, $t5, 4
/* 0C4404 7F08F8D4 01C51821 */  addu  $v1, $t6, $a1
/* 0C4408 7F08F8D8 8C6F000C */  lw    $t7, 0xc($v1)
/* 0C440C 7F08F8DC 14EF0003 */  bne   $a3, $t7, .L7F08F8EC
/* 0C4410 7F08F8E0 00000000 */   nop   
/* 0C4414 7F08F8E4 10000004 */  b     .L7F08F8F8
/* 0C4418 7F08F8E8 00601025 */   move  $v0, $v1
.L7F08F8EC:
/* 0C441C 7F08F8EC 14CAFFDE */  bne   $a2, $t2, .L7F08F868
/* 0C4420 7F08F8F0 24420010 */   addiu $v0, $v0, 0x10
.L7F08F8F4:
/* 0C4424 7F08F8F4 00001025 */  move  $v0, $zero
.L7F08F8F8:
/* 0C4428 7F08F8F8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C442C 7F08F8FC 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C4430 7F08F900 03E00008 */  jr    $ra
/* 0C4434 7F08F904 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
waygroup *sub_GAME_7F08F908(s32 *groupnums, s32 arg1) {

}
#else
waygroup *sub_GAME_7F08F908(s32 *groupnums, s32 arg1);
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F908
/* 0C4438 7F08F908 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C443C 7F08F90C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C4440 7F08F910 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C4444 7F08F914 8C8E0000 */  lw    $t6, ($a0)
/* 0C4448 7F08F918 00A08025 */  move  $s0, $a1
/* 0C444C 7F08F91C 00004825 */  move  $t1, $zero
/* 0C4450 7F08F920 05C00006 */  bltz  $t6, .L7F08F93C
/* 0C4454 7F08F924 00801025 */   move  $v0, $a0
/* 0C4458 7F08F928 8C4F0004 */  lw    $t7, 4($v0)
.L7F08F92C:
/* 0C445C 7F08F92C 25290001 */  addiu $t1, $t1, 1
/* 0C4460 7F08F930 24420004 */  addiu $v0, $v0, 4
/* 0C4464 7F08F934 05E3FFFD */  bgezl $t7, .L7F08F92C
/* 0C4468 7F08F938 8C4F0004 */   lw    $t7, 4($v0)
.L7F08F93C:
/* 0C446C 7F08F93C AFA40028 */  sw    $a0, 0x28($sp)
/* 0C4470 7F08F940 0C002914 */  jal   randomGetNext
/* 0C4474 7F08F944 AFA90024 */   sw    $t1, 0x24($sp)
/* 0C4478 7F08F948 8FA90024 */  lw    $t1, 0x24($sp)
/* 0C447C 7F08F94C 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0C4480 7F08F950 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C4484 7F08F954 0049001B */  divu  $zero, $v0, $t1
/* 0C4488 7F08F958 00005810 */  mfhi  $t3
/* 0C448C 7F08F95C 0169082A */  slt   $at, $t3, $t1
/* 0C4490 7F08F960 15200002 */  bnez  $t1, .L7F08F96C
/* 0C4494 7F08F964 00000000 */   nop   
/* 0C4498 7F08F968 0007000D */  break 7
.L7F08F96C:
/* 0C449C 7F08F96C 01605025 */  move  $t2, $t3
/* 0C44A0 7F08F970 10200043 */  beqz  $at, .L7F08FA80
/* 0C44A4 7F08F974 01603025 */   move  $a2, $t3
/* 0C44A8 7F08F978 012B1823 */  subu  $v1, $t1, $t3
/* 0C44AC 7F08F97C 30780003 */  andi  $t8, $v1, 3
/* 0C44B0 7F08F980 13000013 */  beqz  $t8, .L7F08F9D0
/* 0C44B4 7F08F984 030B4021 */   addu  $t0, $t8, $t3
/* 0C44B8 7F08F988 0006C880 */  sll   $t9, $a2, 2
/* 0C44BC 7F08F98C 3C058007 */  lui   $a1, %hi(g_CurrentSetup+4)
/* 0C44C0 7F08F990 8CA55D04 */  lw    $a1, %lo(g_CurrentSetup+4)($a1)
/* 0C44C4 7F08F994 01991021 */  addu  $v0, $t4, $t9
/* 0C44C8 7F08F998 2407000C */  li    $a3, 12
.L7F08F99C:
/* 0C44CC 7F08F99C 8C4D0000 */  lw    $t5, ($v0)
/* 0C44D0 7F08F9A0 24C60001 */  addiu $a2, $a2, 1
/* 0C44D4 7F08F9A4 01A70019 */  multu $t5, $a3
/* 0C44D8 7F08F9A8 00007012 */  mflo  $t6
/* 0C44DC 7F08F9AC 01C52021 */  addu  $a0, $t6, $a1
/* 0C44E0 7F08F9B0 8C8F0008 */  lw    $t7, 8($a0)
/* 0C44E4 7F08F9B4 160F0003 */  bne   $s0, $t7, .L7F08F9C4
/* 0C44E8 7F08F9B8 00000000 */   nop   
/* 0C44EC 7F08F9BC 10000071 */  b     .L7F08FB84
/* 0C44F0 7F08F9C0 00801025 */   move  $v0, $a0
.L7F08F9C4:
/* 0C44F4 7F08F9C4 1506FFF5 */  bne   $t0, $a2, .L7F08F99C
/* 0C44F8 7F08F9C8 24420004 */   addiu $v0, $v0, 4
/* 0C44FC 7F08F9CC 10C9002C */  beq   $a2, $t1, .L7F08FA80
.L7F08F9D0:
/* 0C4500 7F08F9D0 0006C080 */   sll   $t8, $a2, 2
/* 0C4504 7F08F9D4 3C058007 */  lui   $a1, %hi(g_CurrentSetup+4)
/* 0C4508 7F08F9D8 8CA55D04 */  lw    $a1, %lo(g_CurrentSetup+4)($a1)
/* 0C450C 7F08F9DC 01981021 */  addu  $v0, $t4, $t8
/* 0C4510 7F08F9E0 2407000C */  li    $a3, 12
.L7F08F9E4:
/* 0C4514 7F08F9E4 8C590000 */  lw    $t9, ($v0)
/* 0C4518 7F08F9E8 24C60004 */  addiu $a2, $a2, 4
/* 0C451C 7F08F9EC 03270019 */  multu $t9, $a3
/* 0C4520 7F08F9F0 00006812 */  mflo  $t5
/* 0C4524 7F08F9F4 01A52021 */  addu  $a0, $t5, $a1
/* 0C4528 7F08F9F8 8C8E0008 */  lw    $t6, 8($a0)
/* 0C452C 7F08F9FC 560E0004 */  bnel  $s0, $t6, .L7F08FA10
/* 0C4530 7F08FA00 8C4F0004 */   lw    $t7, 4($v0)
/* 0C4534 7F08FA04 1000005F */  b     .L7F08FB84
/* 0C4538 7F08FA08 00801025 */   move  $v0, $a0
/* 0C453C 7F08FA0C 8C4F0004 */  lw    $t7, 4($v0)
.L7F08FA10:
/* 0C4540 7F08FA10 01E70019 */  multu $t7, $a3
/* 0C4544 7F08FA14 0000C012 */  mflo  $t8
/* 0C4548 7F08FA18 03051821 */  addu  $v1, $t8, $a1
/* 0C454C 7F08FA1C 8C790008 */  lw    $t9, 8($v1)
/* 0C4550 7F08FA20 56190004 */  bnel  $s0, $t9, .L7F08FA34
/* 0C4554 7F08FA24 8C4D0008 */   lw    $t5, 8($v0)
/* 0C4558 7F08FA28 10000056 */  b     .L7F08FB84
/* 0C455C 7F08FA2C 00601025 */   move  $v0, $v1
/* 0C4560 7F08FA30 8C4D0008 */  lw    $t5, 8($v0)
.L7F08FA34:
/* 0C4564 7F08FA34 01A70019 */  multu $t5, $a3
/* 0C4568 7F08FA38 00007012 */  mflo  $t6
/* 0C456C 7F08FA3C 01C51821 */  addu  $v1, $t6, $a1
/* 0C4570 7F08FA40 8C6F0008 */  lw    $t7, 8($v1)
/* 0C4574 7F08FA44 560F0004 */  bnel  $s0, $t7, .L7F08FA58
/* 0C4578 7F08FA48 8C58000C */   lw    $t8, 0xc($v0)
/* 0C457C 7F08FA4C 1000004D */  b     .L7F08FB84
/* 0C4580 7F08FA50 00601025 */   move  $v0, $v1
/* 0C4584 7F08FA54 8C58000C */  lw    $t8, 0xc($v0)
.L7F08FA58:
/* 0C4588 7F08FA58 03070019 */  multu $t8, $a3
/* 0C458C 7F08FA5C 0000C812 */  mflo  $t9
/* 0C4590 7F08FA60 03251821 */  addu  $v1, $t9, $a1
/* 0C4594 7F08FA64 8C6D0008 */  lw    $t5, 8($v1)
/* 0C4598 7F08FA68 160D0003 */  bne   $s0, $t5, .L7F08FA78
/* 0C459C 7F08FA6C 00000000 */   nop   
/* 0C45A0 7F08FA70 10000044 */  b     .L7F08FB84
/* 0C45A4 7F08FA74 00601025 */   move  $v0, $v1
.L7F08FA78:
/* 0C45A8 7F08FA78 14C9FFDA */  bne   $a2, $t1, .L7F08F9E4
/* 0C45AC 7F08FA7C 24420010 */   addiu $v0, $v0, 0x10
.L7F08FA80:
/* 0C45B0 7F08FA80 2407000C */  li    $a3, 12
/* 0C45B4 7F08FA84 1960003E */  blez  $t3, .L7F08FB80
/* 0C45B8 7F08FA88 00003025 */   move  $a2, $zero
/* 0C45BC 7F08FA8C 3C058007 */  lui   $a1, %hi(g_CurrentSetup+4)
/* 0C45C0 7F08FA90 31630003 */  andi  $v1, $t3, 3
/* 0C45C4 7F08FA94 10600011 */  beqz  $v1, .L7F08FADC
/* 0C45C8 7F08FA98 8CA55D04 */   lw    $a1, %lo(g_CurrentSetup+4)($a1)
/* 0C45CC 7F08FA9C 00007080 */  sll   $t6, $zero, 2
/* 0C45D0 7F08FAA0 018E1021 */  addu  $v0, $t4, $t6
/* 0C45D4 7F08FAA4 00604025 */  move  $t0, $v1
.L7F08FAA8:
/* 0C45D8 7F08FAA8 8C4F0000 */  lw    $t7, ($v0)
/* 0C45DC 7F08FAAC 24C60001 */  addiu $a2, $a2, 1
/* 0C45E0 7F08FAB0 01E70019 */  multu $t7, $a3
/* 0C45E4 7F08FAB4 0000C012 */  mflo  $t8
/* 0C45E8 7F08FAB8 03052021 */  addu  $a0, $t8, $a1
/* 0C45EC 7F08FABC 8C990008 */  lw    $t9, 8($a0)
/* 0C45F0 7F08FAC0 16190003 */  bne   $s0, $t9, .L7F08FAD0
/* 0C45F4 7F08FAC4 00000000 */   nop   
/* 0C45F8 7F08FAC8 1000002E */  b     .L7F08FB84
/* 0C45FC 7F08FACC 00801025 */   move  $v0, $a0
.L7F08FAD0:
/* 0C4600 7F08FAD0 1506FFF5 */  bne   $t0, $a2, .L7F08FAA8
/* 0C4604 7F08FAD4 24420004 */   addiu $v0, $v0, 4
/* 0C4608 7F08FAD8 10CB0029 */  beq   $a2, $t3, .L7F08FB80
.L7F08FADC:
/* 0C460C 7F08FADC 00066880 */   sll   $t5, $a2, 2
/* 0C4610 7F08FAE0 018D1021 */  addu  $v0, $t4, $t5
.L7F08FAE4:
/* 0C4614 7F08FAE4 8C4E0000 */  lw    $t6, ($v0)
/* 0C4618 7F08FAE8 24C60004 */  addiu $a2, $a2, 4
/* 0C461C 7F08FAEC 01C70019 */  multu $t6, $a3
/* 0C4620 7F08FAF0 00007812 */  mflo  $t7
/* 0C4624 7F08FAF4 01E52021 */  addu  $a0, $t7, $a1
/* 0C4628 7F08FAF8 8C980008 */  lw    $t8, 8($a0)
/* 0C462C 7F08FAFC 56180004 */  bnel  $s0, $t8, .L7F08FB10
/* 0C4630 7F08FB00 8C590004 */   lw    $t9, 4($v0)
/* 0C4634 7F08FB04 1000001F */  b     .L7F08FB84
/* 0C4638 7F08FB08 00801025 */   move  $v0, $a0
/* 0C463C 7F08FB0C 8C590004 */  lw    $t9, 4($v0)
.L7F08FB10:
/* 0C4640 7F08FB10 03270019 */  multu $t9, $a3
/* 0C4644 7F08FB14 00006812 */  mflo  $t5
/* 0C4648 7F08FB18 01A51821 */  addu  $v1, $t5, $a1
/* 0C464C 7F08FB1C 8C6E0008 */  lw    $t6, 8($v1)
/* 0C4650 7F08FB20 560E0004 */  bnel  $s0, $t6, .L7F08FB34
/* 0C4654 7F08FB24 8C4F0008 */   lw    $t7, 8($v0)
/* 0C4658 7F08FB28 10000016 */  b     .L7F08FB84
/* 0C465C 7F08FB2C 00601025 */   move  $v0, $v1
/* 0C4660 7F08FB30 8C4F0008 */  lw    $t7, 8($v0)
.L7F08FB34:
/* 0C4664 7F08FB34 01E70019 */  multu $t7, $a3
/* 0C4668 7F08FB38 0000C012 */  mflo  $t8
/* 0C466C 7F08FB3C 03051821 */  addu  $v1, $t8, $a1
/* 0C4670 7F08FB40 8C790008 */  lw    $t9, 8($v1)
/* 0C4674 7F08FB44 56190004 */  bnel  $s0, $t9, .L7F08FB58
/* 0C4678 7F08FB48 8C4D000C */   lw    $t5, 0xc($v0)
/* 0C467C 7F08FB4C 1000000D */  b     .L7F08FB84
/* 0C4680 7F08FB50 00601025 */   move  $v0, $v1
/* 0C4684 7F08FB54 8C4D000C */  lw    $t5, 0xc($v0)
.L7F08FB58:
/* 0C4688 7F08FB58 01A70019 */  multu $t5, $a3
/* 0C468C 7F08FB5C 00007012 */  mflo  $t6
/* 0C4690 7F08FB60 01C51821 */  addu  $v1, $t6, $a1
/* 0C4694 7F08FB64 8C6F0008 */  lw    $t7, 8($v1)
/* 0C4698 7F08FB68 160F0003 */  bne   $s0, $t7, .L7F08FB78
/* 0C469C 7F08FB6C 00000000 */   nop   
/* 0C46A0 7F08FB70 10000004 */  b     .L7F08FB84
/* 0C46A4 7F08FB74 00601025 */   move  $v0, $v1
.L7F08FB78:
/* 0C46A8 7F08FB78 14CAFFDA */  bne   $a2, $t2, .L7F08FAE4
/* 0C46AC 7F08FB7C 24420010 */   addiu $v0, $v0, 0x10
.L7F08FB80:
/* 0C46B0 7F08FB80 00001025 */  move  $v0, $zero
.L7F08FB84:
/* 0C46B4 7F08FB84 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C46B8 7F08FB88 03E00008 */  jr    $ra
/* 0C46BC 7F08FB8C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif


waypoint *sub_GAME_7F08FB90(waypoint *pointa, waypoint *pointb)
{
    if (g_CurrentSetup.waypointgroups)
    {
        waygroup *groupa = &g_CurrentSetup.waypointgroups[pointa->groupNum];
        waygroup *groupb = &g_CurrentSetup.waypointgroups[pointb->groupNum];
        waypoint *result;
        s32 stack;

        if (groupa == groupb)
        {
            resetWaypointDistances();
            do_BFS_withinPathSet(pointb, pointa, 1);

            result = sub_GAME_7F08F6B0(pointa->neighbours, -1);

            if (result)
            {
                return result;
            }

            result = sub_GAME_7F08F6B0(pointa->neighbours, pointa->dist + 1);

            if (result)
            {
                return result;
            }
        }
        else
        {
            sub_GAME_7F08EE70(groupb, groupa, g_CurrentSetup.waypointgroups, 0);

            if (groupa->dist >= 0)
            {
                waygroup *tmpgroup = sub_GAME_7F08F908(groupa->neighbours, -1);

                if (tmpgroup)
                {
                    waypoint *sp48;
                    waypoint *sp44;
                    waypoint *arr[3];

                    sub_GAME_7F08F438(groupa, tmpgroup, &sp48, &sp44);

                    if (sp48 == pointa)
                    {
                        return sp44;
                    }

                    if (sub_GAME_7F08F350(pointa, sp48, arr, 3) >= 3)
                    {
                        return arr[1];
                    }
                }
                else
                {
                    waygroup *tmpgroup = sub_GAME_7F08ED60(groupa->neighbours, groupa->dist - 1);

                    if (tmpgroup)
                    {
                        waypoint *sp30;
                        waypoint *sp2c;

                        sub_GAME_7F08F438(groupa, tmpgroup, &sp30, &sp2c);
                        do_BFS_withinPathSet(sp30, pointa, 1);
                        result = findPadWithDistAndSet(pointa->neighbours, pointa->dist + 1, pointa->groupNum);

                        if (result)
                        {
                            return result;
                        }
                    }
                }
            }
        }
    }

    return NULL;
}


#ifdef NONMATCHING
void sub_GAME_7F08FD1C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08FD1C
/* 0C484C 7F08FD1C 3C088007 */  lui   $t0, %hi(g_CurrentSetup+0) 
/* 0C4850 7F08FD20 8D085D00 */  lw    $t0, %lo(g_CurrentSetup+0)($t0)
/* 0C4854 7F08FD24 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0C4858 7F08FD28 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C485C 7F08FD2C 5100002F */  beql  $t0, $zero, .L7F08FDEC
/* 0C4860 7F08FD30 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C4864 7F08FD34 8D0E0000 */  lw    $t6, ($t0)
/* 0C4868 7F08FD38 00001825 */  move  $v1, $zero
/* 0C486C 7F08FD3C 01001025 */  move  $v0, $t0
/* 0C4870 7F08FD40 05C20007 */  bltzl $t6, .L7F08FD60
/* 0C4874 7F08FD44 AFA300F0 */   sw    $v1, 0xf0($sp)
/* 0C4878 7F08FD48 8C4F0010 */  lw    $t7, 0x10($v0)
.L7F08FD4C:
/* 0C487C 7F08FD4C 24420010 */  addiu $v0, $v0, 0x10
/* 0C4880 7F08FD50 24630001 */  addiu $v1, $v1, 1
/* 0C4884 7F08FD54 05E3FFFD */  bgezl $t7, .L7F08FD4C
/* 0C4888 7F08FD58 8C4F0010 */   lw    $t7, 0x10($v0)
/* 0C488C 7F08FD5C AFA300F0 */  sw    $v1, 0xf0($sp)
.L7F08FD60:
/* 0C4890 7F08FD60 0C002914 */  jal   randomGetNext
/* 0C4894 7F08FD64 AFA800F4 */   sw    $t0, 0xf4($sp)
/* 0C4898 7F08FD68 8FA300F0 */  lw    $v1, 0xf0($sp)
/* 0C489C 7F08FD6C 8FA800F4 */  lw    $t0, 0xf4($sp)
/* 0C48A0 7F08FD70 0043001B */  divu  $zero, $v0, $v1
/* 0C48A4 7F08FD74 0000C010 */  mfhi  $t8
/* 0C48A8 7F08FD78 0018C900 */  sll   $t9, $t8, 4
/* 0C48AC 7F08FD7C 14600002 */  bnez  $v1, .L7F08FD88
/* 0C48B0 7F08FD80 00000000 */   nop   
/* 0C48B4 7F08FD84 0007000D */  break 7
.L7F08FD88:
/* 0C48B8 7F08FD88 03284821 */  addu  $t1, $t9, $t0
/* 0C48BC 7F08FD8C 0C002914 */  jal   randomGetNext
/* 0C48C0 7F08FD90 AFA900E8 */   sw    $t1, 0xe8($sp)
/* 0C48C4 7F08FD94 8FA300F0 */  lw    $v1, 0xf0($sp)
/* 0C48C8 7F08FD98 8FA800F4 */  lw    $t0, 0xf4($sp)
/* 0C48CC 7F08FD9C 8FA400E8 */  lw    $a0, 0xe8($sp)
/* 0C48D0 7F08FDA0 0043001B */  divu  $zero, $v0, $v1
/* 0C48D4 7F08FDA4 00005010 */  mfhi  $t2
/* 0C48D8 7F08FDA8 000A5900 */  sll   $t3, $t2, 4
/* 0C48DC 7F08FDAC 14600002 */  bnez  $v1, .L7F08FDB8
/* 0C48E0 7F08FDB0 00000000 */   nop   
/* 0C48E4 7F08FDB4 0007000D */  break 7
.L7F08FDB8:
/* 0C48E8 7F08FDB8 27A6001C */  addiu $a2, $sp, 0x1c
/* 0C48EC 7F08FDBC 24070032 */  li    $a3, 50
/* 0C48F0 7F08FDC0 0FC23D3C */  jal   waypointFindRoute
/* 0C48F4 7F08FDC4 01682821 */   addu  $a1, $t3, $t0
/* 0C48F8 7F08FDC8 10400007 */  beqz  $v0, .L7F08FDE8
/* 0C48FC 7F08FDCC 8FAC001C */   lw    $t4, 0x1c($sp)
/* 0C4900 7F08FDD0 11800005 */  beqz  $t4, .L7F08FDE8
/* 0C4904 7F08FDD4 27A2001C */   addiu $v0, $sp, 0x1c
/* 0C4908 7F08FDD8 8C4D0004 */  lw    $t5, 4($v0)
.L7F08FDDC:
/* 0C490C 7F08FDDC 24420004 */  addiu $v0, $v0, 4
/* 0C4910 7F08FDE0 55A0FFFE */  bnezl $t5, .L7F08FDDC
/* 0C4914 7F08FDE4 8C4D0004 */   lw    $t5, 4($v0)
.L7F08FDE8:
/* 0C4918 7F08FDE8 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08FDEC:
/* 0C491C 7F08FDEC 27BD00F8 */  addiu $sp, $sp, 0xf8
/* 0C4920 7F08FDF0 03E00008 */  jr    $ra
/* 0C4924 7F08FDF4 00000000 */   nop   
)
#endif
