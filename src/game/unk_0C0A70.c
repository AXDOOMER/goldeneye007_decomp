#include "ultra64.h"
#include "game/unk_0C0A70.h"

// data
s32 D_80048490 = -1;
s32 D_80048494 = 0;

/**
 * Appears to be rendered framerate, or some kind of counter since the last frame update.
 */
s32 D_80048498 = 1;
#ifdef VERSION_JP
f32 jpD_800484CC = 1.0f;
f32 jpD_800484D0 = 1.0f;
#endif
s32 D_8004849C = -1;
s32 D_800484A0 = 0;
s32 D_800484A4 = 0;
s32 D_800484A8 = 0;
u32 copy_of_osgetcount_value_0 = 0;
u32 copy_of_osgetcount_value_1 = 0;
s32 D_800484B4 = 1;




void store_osgetcount(void)
{
    copy_of_osgetcount_value_1 = osGetCount();
    copy_of_osgetcount_value_0 = copy_of_osgetcount_value_1;
}




void sub_GAME_7F0C0AA0(s32 arg0)
{
    copy_of_osgetcount_value_0 = (s32) copy_of_osgetcount_value_1;
    copy_of_osgetcount_value_1 = osGetCount();

    D_80048490 = D_80048494;
    D_80048494 = (s32) (D_80048494 + arg0);
    D_80048498 = arg0;
    #ifdef VERSION_JP
    jpD_800484CC = (f32) arg0;
    jpD_800484D0 = (f32) jpD_800484CC;
    #endif
    D_8004849C = (s32) D_800484A0;
    D_800484A0 = (s32) (D_80048494 / 2);
    D_800484A4 = (s32) (D_80048494 & 1);
    D_800484A8 = (s32) (D_800484A0 - D_8004849C);
}



#ifdef NONMATCHING
void sub_GAME_7F0C0B4C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C0B4C
/* 0F567C 7F0C0B4C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F5680 7F0C0B50 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F5684 7F0C0B54 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F5688 7F0C0B58 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F568C 7F0C0B5C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F5690 7F0C0B60 3C108005 */  lui   $s0, %hi(D_800484B4)
/* 0F5694 7F0C0B64 3C118005 */  lui   $s1, %hi(copy_of_osgetcount_value_1)
/* 0F5698 7F0C0B68 3C120005 */  lui   $s2, (0x0005EB61 >> 16) # lui $s2, 5
/* 0F569C 7F0C0B6C 3C13000B */  lui   $s3, (0x000BD6C3 >> 16) # lui $s3, 0xb
/* 0F56A0 7F0C0B70 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F56A4 7F0C0B74 3673D6C3 */  ori   $s3, (0x000BD6C3 & 0xFFFF) # ori $s3, $s3, 0xd6c3
/* 0F56A8 7F0C0B78 3652EB61 */  ori   $s2, (0x0005EB61 & 0xFFFF) # ori $s2, $s2, 0xeb61
/* 0F56AC 7F0C0B7C 263184B0 */  addiu $s1, %lo(copy_of_osgetcount_value_1) # addiu $s1, $s1, -0x7b50
/* 0F56B0 7F0C0B80 261084B4 */  addiu $s0, %lo(D_800484B4) # addiu $s0, $s0, -0x7b4c
.L7F0C0B84:
/* 0F56B4 7F0C0B84 0C003638 */  jal   osGetCount
/* 0F56B8 7F0C0B88 00000000 */   nop   
/* 0F56BC 7F0C0B8C 8E2E0000 */  lw    $t6, ($s1)
/* 0F56C0 7F0C0B90 8E190000 */  lw    $t9, ($s0)
/* 0F56C4 7F0C0B94 004E7823 */  subu  $t7, $v0, $t6
/* 0F56C8 7F0C0B98 01F2C021 */  addu  $t8, $t7, $s2
/* 0F56CC 7F0C0B9C 0313001B */  divu  $zero, $t8, $s3
/* 0F56D0 7F0C0BA0 00002012 */  mflo  $a0
/* 0F56D4 7F0C0BA4 0099082B */  sltu  $at, $a0, $t9
/* 0F56D8 7F0C0BA8 16600002 */  bnez  $s3, .L7F0C0BB4
/* 0F56DC 7F0C0BAC 00000000 */   nop   
/* 0F56E0 7F0C0BB0 0007000D */  break 7
.L7F0C0BB4:
/* 0F56E4 7F0C0BB4 1420FFF3 */  bnez  $at, .L7F0C0B84
/* 0F56E8 7F0C0BB8 00000000 */   nop   
/* 0F56EC 7F0C0BBC 24080001 */  li    $t0, 1
/* 0F56F0 7F0C0BC0 0FC302A8 */  jal   sub_GAME_7F0C0AA0
/* 0F56F4 7F0C0BC4 AE080000 */   sw    $t0, ($s0)
/* 0F56F8 7F0C0BC8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F56FC 7F0C0BCC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F5700 7F0C0BD0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F5704 7F0C0BD4 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F5708 7F0C0BD8 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F570C 7F0C0BDC 03E00008 */  jr    $ra
/* 0F5710 7F0C0BE0 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





void sub_GAME_7F0C0BE4(s32 arg0) {
    D_800484B4 = arg0;
}

void sub_GAME_7F0C0BF0(void) {
    get_mTrack2Vol();
}



