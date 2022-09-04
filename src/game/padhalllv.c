#include <ultra64.h>
#include "padhalllv.h"
#include "bondtypes.h"
#include "chrai.h"
#include "random.h"

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


/**
 * For each group number in the given list assign value to their
 * dist if their dist has no value (ie. is negative).
 */
void sub_GAME_7F08EDB4(s32 *groupnums, s32 value)
{
    waygroup *groups = g_CurrentSetup.waypointgroups;

    while (*groupnums >= 0)
    {
        waygroup *group = &groups[*groupnums];

        if (group->dist < 0)
        {
            group->dist = value;
        }

        groupnums++;
    }
}


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

    while (waypoint->padID >= 0)
    {
        waypoint->dist = -1;
        waypoint++;
    }
}


waypoint *sub_GAME_7F08F6B0(s32 *pointnums, s32 arg1)
{
	s32 len = 0;
	s32 randomindex;
	s32 i;

	while (pointnums[len] >= 0)
    {
		len++;
	}

	// This is effectively randomly dividing the pointnums list into two,
	// then checking the upper portion before the lower portion. Both loops
	// have the same logic so this seems unusual, but there is reason to do
	// this if they want the returned waypoint to be any random waypoint that
	// meets the arg1 criteria, with equal weighting.

	randomindex = randomGetNext() % len;

	for (i = randomindex; i < len; i++)
    {
		waypoint *point = &g_CurrentSetup.pathwaypoints[pointnums[i]];

		if (point->dist == arg1)
        {
			return point;
		}
	}

	for (i = 0; i < randomindex; i++)
    {
		waypoint *point = &g_CurrentSetup.pathwaypoints[pointnums[i]];

		if (point->dist == arg1)
        {
			return point;
		}
	}

	return NULL;
}


waygroup *sub_GAME_7F08F908(s32 *groupnums, s32 arg1)
{
    s32 len = 0;
    s32 randomindex;
    s32 i;

    while (groupnums[len] >= 0)
    {
        len++;
    }

    // Similar to the above function, return a random waygroup
    // which matches the arg1 criteria.
    randomindex = randomGetNext() % len;

    for (i = randomindex; i < len; i++)
    {
        waygroup *group = &g_CurrentSetup.waypointgroups[groupnums[i]];

        if (group->dist == arg1)
        {
            return group;
        }
    }

    for (i = 0; i < randomindex; i++)
    {
        waygroup *group = &g_CurrentSetup.waypointgroups[groupnums[i]];

        if (group->dist == arg1)
        {
            return group;
        }
    }

    return NULL;
}


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
