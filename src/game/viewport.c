#include "ultra64.h"
#include "game/bond.h"

// bss
s32 viewport_img_width;
s32 viewport_img_height;


// data
s32 viewport_img = 0;


void remove_viewport_buffer(void) {
    viewport_img = 0;
}

#define ALIGN64(val) (((val) + 0x3F) & ~0x3F)
u32 mempAllocBytesInBank(u32 bytes,u8 bank);
u32 get_num_players(void);
void allocate_viewport_buffer(void) {
    if (resolution != 0) {
        viewport_img_width = 440;
        viewport_img_height = 330;
    } else {
        viewport_img_width = 320;
        if (get_num_players() == 1) {
            viewport_img_height = 240;
        } else {
            viewport_img_height = 120;
        }
    }
    viewport_img = mempAllocBytesInBank((viewport_img_width * viewport_img_height * 2) + 64, 4);
    viewport_img = ALIGN64(viewport_img);
}

void sub_GAME_7F0D2448(s32 vp_image, s32 vp_width, s32 vp_height) {
    viewport_img = vp_image;
    viewport_img_width = vp_width;
    viewport_img_height = vp_height;
}

void* sub_GAME_7F0D2464(Gfx *gdl) {
    s32 phi_a3;
    s32 test;
    if (viewport_img == 0) {
        allocate_viewport_buffer();
    }
    if (!(get_cur_playernum() < 2) || ((get_num_players() == 2) && (get_cur_playernum() == 1))) {
        phi_a3 = 0x12C00;
    } else {
        phi_a3 = 0;
    }
    test = (viewport_img - phi_a3);
    test = test & ~0x3F;
    gDPPipeSync(gdl++);
    gDPSetDepthImage(gdl++, test);
    return gdl;
}

#ifdef NONMATCHING
void sub_GAME_7F0D2518(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D2518
/* 107048 7F0D2518 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 10704C 7F0D251C AFB00018 */  sw    $s0, 0x18($sp)
/* 107050 7F0D2520 AFBF001C */  sw    $ra, 0x1c($sp)
/* 107054 7F0D2524 24900008 */  addiu $s0, $a0, 8
/* 107058 7F0D2528 3C0EE700 */  lui   $t6, 0xe700
/* 10705C 7F0D252C AC8E0000 */  sw    $t6, ($a0)
/* 107060 7F0D2530 AC800004 */  sw    $zero, 4($a0)
/* 107064 7F0D2534 02001825 */  move  $v1, $s0
/* 107068 7F0D2538 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 10706C 7F0D253C 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 107070 7F0D2540 AC6F0000 */  sw    $t7, ($v1)
/* 107074 7F0D2544 AC600004 */  sw    $zero, 4($v1)
/* 107078 7F0D2548 3C188009 */  lui   $t8, %hi(viewport_img_width) 
/* 10707C 7F0D254C 8F18E310 */  lw    $t8, %lo(viewport_img_width)($t8)
/* 107080 7F0D2550 26100008 */  addiu $s0, $s0, 8
/* 107084 7F0D2554 3C01FF10 */  lui   $at, 0xff10
/* 107088 7F0D2558 2719FFFF */  addiu $t9, $t8, -1
/* 10708C 7F0D255C 33280FFF */  andi  $t0, $t9, 0xfff
/* 107090 7F0D2560 01014825 */  or    $t1, $t0, $at
/* 107094 7F0D2564 02002825 */  move  $a1, $s0
/* 107098 7F0D2568 ACA90000 */  sw    $t1, ($a1)
/* 10709C 7F0D256C 3C0A8005 */  lui   $t2, %hi(viewport_img) 
/* 1070A0 7F0D2570 8D4AEB00 */  lw    $t2, %lo(viewport_img)($t2)
/* 1070A4 7F0D2574 26100008 */  addiu $s0, $s0, 8
/* 1070A8 7F0D2578 3C018000 */  lui   $at, 0x8000
/* 1070AC 7F0D257C 02003025 */  move  $a2, $s0
/* 1070B0 7F0D2580 01415821 */  addu  $t3, $t2, $at
/* 1070B4 7F0D2584 ACAB0004 */  sw    $t3, 4($a1)
/* 1070B8 7F0D2588 26100008 */  addiu $s0, $s0, 8
/* 1070BC 7F0D258C 3C0CBA00 */  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
/* 1070C0 7F0D2590 358C1402 */  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
/* 1070C4 7F0D2594 3C0D0030 */  lui   $t5, 0x30
/* 1070C8 7F0D2598 02003825 */  move  $a3, $s0
/* 1070CC 7F0D259C ACCD0004 */  sw    $t5, 4($a2)
/* 1070D0 7F0D25A0 ACCC0000 */  sw    $t4, ($a2)
/* 1070D4 7F0D25A4 3C0FFFFC */  lui   $t7, (0xFFFCFFFC >> 16) # lui $t7, 0xfffc
/* 1070D8 7F0D25A8 35EFFFFC */  ori   $t7, (0xFFFCFFFC & 0xFFFF) # ori $t7, $t7, 0xfffc
/* 1070DC 7F0D25AC 26100008 */  addiu $s0, $s0, 8
/* 1070E0 7F0D25B0 3C0EF700 */  lui   $t6, 0xf700
/* 1070E4 7F0D25B4 ACEE0000 */  sw    $t6, ($a3)
/* 1070E8 7F0D25B8 ACEF0004 */  sw    $t7, 4($a3)
/* 1070EC 7F0D25BC 02001025 */  move  $v0, $s0
/* 1070F0 7F0D25C0 3C18ED00 */  lui   $t8, 0xed00
/* 1070F4 7F0D25C4 AC580000 */  sw    $t8, ($v0)
/* 1070F8 7F0D25C8 AFA20030 */  sw    $v0, 0x30($sp)
/* 1070FC 7F0D25CC 0C001107 */  jal   get_video2_settings_txtClipW
/* 107100 7F0D25D0 26100008 */   addiu $s0, $s0, 8
/* 107104 7F0D25D4 0C00110B */  jal   get_video2_settings_txtClipH
/* 107108 7F0D25D8 A7A20026 */   sh    $v0, 0x26($sp)
/* 10710C 7F0D25DC 44822000 */  mtc1  $v0, $f4
/* 107110 7F0D25E0 87AA0026 */  lh    $t2, 0x26($sp)
/* 107114 7F0D25E4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 107118 7F0D25E8 468021A0 */  cvt.s.w $f6, $f4
/* 10711C 7F0D25EC 448A8000 */  mtc1  $t2, $f16
/* 107120 7F0D25F0 44810000 */  mtc1  $at, $f0
/* 107124 7F0D25F4 8FB80030 */  lw    $t8, 0x30($sp)
/* 107128 7F0D25F8 468084A0 */  cvt.s.w $f18, $f16
/* 10712C 7F0D25FC 46003202 */  mul.s $f8, $f6, $f0
/* 107130 7F0D2600 00000000 */  nop   
/* 107134 7F0D2604 46009102 */  mul.s $f4, $f18, $f0
/* 107138 7F0D2608 4600428D */  trunc.w.s $f10, $f8
/* 10713C 7F0D260C 4600218D */  trunc.w.s $f6, $f4
/* 107140 7F0D2610 44085000 */  mfc1  $t0, $f10
/* 107144 7F0D2614 440C3000 */  mfc1  $t4, $f6
/* 107148 7F0D2618 31090FFF */  andi  $t1, $t0, 0xfff
/* 10714C 7F0D261C 318D0FFF */  andi  $t5, $t4, 0xfff
/* 107150 7F0D2620 000D7300 */  sll   $t6, $t5, 0xc
/* 107154 7F0D2624 012E7825 */  or    $t7, $t1, $t6
/* 107158 7F0D2628 0FC26919 */  jal   get_num_players
/* 10715C 7F0D262C AF0F0004 */   sw    $t7, 4($t8)
/* 107160 7F0D2630 28410003 */  slti  $at, $v0, 3
/* 107164 7F0D2634 10200005 */  beqz  $at, .L7F0D264C
/* 107168 7F0D2638 00000000 */   nop   
/* 10716C 7F0D263C 0C001107 */  jal   get_video2_settings_txtClipW
/* 107170 7F0D2640 AFA0004C */   sw    $zero, 0x4c($sp)
/* 107174 7F0D2644 1000001B */  b     .L7F0D26B4
/* 107178 7F0D2648 2445FFFF */   addiu $a1, $v0, -1
.L7F0D264C:
/* 10717C 7F0D264C 0FC26C54 */  jal   get_cur_playernum
/* 107180 7F0D2650 00000000 */   nop   
/* 107184 7F0D2654 10400006 */  beqz  $v0, .L7F0D2670
/* 107188 7F0D2658 00000000 */   nop   
/* 10718C 7F0D265C 0FC26C54 */  jal   get_cur_playernum
/* 107190 7F0D2660 00000000 */   nop   
/* 107194 7F0D2664 24010002 */  li    $at, 2
/* 107198 7F0D2668 14410009 */  bne   $v0, $at, .L7F0D2690
/* 10719C 7F0D266C 00000000 */   nop   
.L7F0D2670:
/* 1071A0 7F0D2670 0C001107 */  jal   get_video2_settings_txtClipW
/* 1071A4 7F0D2674 AFA0004C */   sw    $zero, 0x4c($sp)
/* 1071A8 7F0D2678 04410003 */  bgez  $v0, .L7F0D2688
/* 1071AC 7F0D267C 00022843 */   sra   $a1, $v0, 1
/* 1071B0 7F0D2680 24410001 */  addiu $at, $v0, 1
/* 1071B4 7F0D2684 00012843 */  sra   $a1, $at, 1
.L7F0D2688:
/* 1071B8 7F0D2688 1000000A */  b     .L7F0D26B4
/* 1071BC 7F0D268C 24A5FFFF */   addiu $a1, $a1, -1
.L7F0D2690:
/* 1071C0 7F0D2690 0C001107 */  jal   get_video2_settings_txtClipW
/* 1071C4 7F0D2694 00000000 */   nop   
/* 1071C8 7F0D2698 04410003 */  bgez  $v0, .L7F0D26A8
/* 1071CC 7F0D269C 0002C843 */   sra   $t9, $v0, 1
/* 1071D0 7F0D26A0 24410001 */  addiu $at, $v0, 1
/* 1071D4 7F0D26A4 0001C843 */  sra   $t9, $at, 1
.L7F0D26A8:
/* 1071D8 7F0D26A8 0C001107 */  jal   get_video2_settings_txtClipW
/* 1071DC 7F0D26AC AFB9004C */   sw    $t9, 0x4c($sp)
/* 1071E0 7F0D26B0 2445FFFF */  addiu $a1, $v0, -1
.L7F0D26B4:
/* 1071E4 7F0D26B4 3C0C8009 */  lui   $t4, %hi(viewport_img_height) 
/* 1071E8 7F0D26B8 8D8CE314 */  lw    $t4, %lo(viewport_img_height)($t4)
/* 1071EC 7F0D26BC 30A803FF */  andi  $t0, $a1, 0x3ff
/* 1071F0 7F0D26C0 00085380 */  sll   $t2, $t0, 0xe
/* 1071F4 7F0D26C4 258DFFFF */  addiu $t5, $t4, -1
/* 1071F8 7F0D26C8 31A903FF */  andi  $t1, $t5, 0x3ff
/* 1071FC 7F0D26CC 3C01F600 */  lui   $at, 0xf600
/* 107200 7F0D26D0 01415825 */  or    $t3, $t2, $at
/* 107204 7F0D26D4 00097080 */  sll   $t6, $t1, 2
/* 107208 7F0D26D8 016E7825 */  or    $t7, $t3, $t6
/* 10720C 7F0D26DC 02001825 */  move  $v1, $s0
/* 107210 7F0D26E0 AC6F0000 */  sw    $t7, ($v1)
/* 107214 7F0D26E4 8FB8004C */  lw    $t8, 0x4c($sp)
/* 107218 7F0D26E8 26100008 */  addiu $s0, $s0, 8
/* 10721C 7F0D26EC 02002025 */  move  $a0, $s0
/* 107220 7F0D26F0 331903FF */  andi  $t9, $t8, 0x3ff
/* 107224 7F0D26F4 00194380 */  sll   $t0, $t9, 0xe
/* 107228 7F0D26F8 AC680004 */  sw    $t0, 4($v1)
/* 10722C 7F0D26FC 3C0AE700 */  lui   $t2, 0xe700
/* 107230 7F0D2700 AC8A0000 */  sw    $t2, ($a0)
/* 107234 7F0D2704 AC800004 */  sw    $zero, 4($a0)
/* 107238 7F0D2708 8FBF001C */  lw    $ra, 0x1c($sp)
/* 10723C 7F0D270C 26020008 */  addiu $v0, $s0, 8
/* 107240 7F0D2710 8FB00018 */  lw    $s0, 0x18($sp)
/* 107244 7F0D2714 03E00008 */  jr    $ra
/* 107248 7F0D2718 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif


