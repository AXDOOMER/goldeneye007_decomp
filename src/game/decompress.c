#include "ultra64.h"

/* bss
CODE.bss:8008D350     dword_CODE_bss_8008D350:.space 4         # DATA XREF: decompressdatao
CODE.bss:8008D350                                              # decompressdata+8w
CODE.bss:8008D350                                              # decompressdata+4Cr
CODE.bss:8008D350                                              # decompressdata+6Cr
CODE.bss:8008D350                                              # decompressdata+70r
CODE.bss:8008D350                                              # decompressdata+7Cw
CODE.bss:8008D350                                              # sub_CODE_7F0CE894+Cr
CODE.bss:8008D350                                              # sub_CODE_7F0CEEF0+80o
CODE.bss:8008D350                                              # zlib_decompressor_type0+50r
CODE.bss:8008D350                                              # zlib_decompressor_type0+9Cr
CODE.bss:8008D350                                              # zlib_decompressor_type0+FCr
CODE.bss:8008D350                                              # zlib_decompressor_type2+30r
CODE.bss:8008D350                                              # zlib_decompressor_type2+84r
CODE.bss:8008D350                                              # zlib_decompressor_type2+D4r
CODE.bss:8008D350                                              # zlib_decompressor_type2+138r
CODE.bss:8008D350                                              # zlib_decompressor_type2+25Cr
CODE.bss:8008D350                                              # zlib_decompressor_type2+2E4r
CODE.bss:8008D350                                              # zlib_decompressor_type2+36Cr
CODE.bss:8008D350                                              # zlib_decompressor_type2+3ECr
CODE.bss:8008D350                                              # select_zlib_decompression_routine+34r
CODE.bss:8008D350                                              # select_zlib_decompression_routine+80r
CODE.bss:8008D354     dword_CODE_bss_8008D354:.space 4         # DATA XREF: decompressdata+Cw
CODE.bss:8008D354                                              # sub_CODE_7F0CEEF0+84o
CODE.bss:8008D354                                              # zlib_decompressor_type0+E4o
CODE.bss:8008D358     dword_CODE_bss_8008D358:.space 4         # DATA XREF: decompressdata+8Cw
CODE.bss:8008D358                                              # sub_CODE_7F0CE894+4r
CODE.bss:8008D358                                              # sub_CODE_7F0CEEF0+88o
CODE.bss:8008D358                                              # zlib_decompressor_type0+48o
CODE.bss:8008D358                                              # zlib_decompressor_type0+90o
CODE.bss:8008D358                                              # zlib_decompressor_type2+28o
CODE.bss:8008D358                                              # zlib_decompressor_type2+74o
CODE.bss:8008D358                                              # zlib_decompressor_type2+224o
CODE.bss:8008D358                                              # select_zlib_decompression_routine+2Co
CODE.bss:8008D358                                              # select_zlib_decompression_routine+70o
CODE.bss:8008D358                                              # loop_to_decompress_entire_file+80o
CODE.bss:8008D35C     dword_CODE_bss_8008D35C:.space 4         # DATA XREF: decompressdata+80w
CODE.bss:8008D35C                                              # decompressdata+94r
CODE.bss:8008D35C                                              # sub_CODE_7F0CEEF0+74r
CODE.bss:8008D35C                                              # sub_CODE_7F0CEEF0:loc_CODE_7F0CF340w
CODE.bss:8008D35C                                              # zlib_decompressor_type0+24o
CODE.bss:8008D35C                                              # zlib_decompressor_type0+38r
CODE.bss:8008D35C                                              # loop_to_decompress_entire_file+10w
CODE.bss:8008D360     dword_CODE_bss_8008D360:.space 4         # DATA XREF: decompressdata+20w
CODE.bss:8008D360                                              # sub_CODE_7F0CE8B0+314o
CODE.bss:8008D364     dword_CODE_bss_8008D364:.space 4         # DATA XREF: sub_CODE_7F0CEEF0+6Cr
CODE.bss:8008D364                                              # sub_CODE_7F0CEEF0+458w
CODE.bss:8008D364                                              # zlib_decompressor_type0+Co
CODE.bss:8008D364                                              # zlib_decompressor_type0+18r
CODE.bss:8008D364                                              # zlib_decompressor_type2+20r
CODE.bss:8008D364                                              # zlib_decompressor_type2+470w
CODE.bss:8008D364                                              # select_zlib_decompression_routine+Co
CODE.bss:8008D364                                              # select_zlib_decompression_routine+24r
CODE.bss:8008D364                                              # loop_to_decompress_entire_file+34w
CODE.bss:8008D368     dword_CODE_bss_8008D368:.space 4         # DATA XREF: sub_CODE_7F0CEEF0+70r
CODE.bss:8008D368                                              # sub_CODE_7F0CEEF0+464w
CODE.bss:8008D368                                              # zlib_decompressor_type0o
CODE.bss:8008D368                                              # zlib_decompressor_type0+8r
CODE.bss:8008D368                                              # zlib_decompressor_type2r
CODE.bss:8008D368                                              # zlib_decompressor_type2+48Cw
CODE.bss:8008D368                                              # select_zlib_decompression_routineo
CODE.bss:8008D368                                              # select_zlib_decompression_routine+8r
CODE.bss:8008D368                                              # loop_to_decompress_entire_file+14o
CODE.bss:8008D368                                              # loop_to_decompress_entire_file+24w
CODE.bss:8008D36C     dword_CODE_bss_8008D36C:.space 4         # DATA XREF: sub_CODE_7F0CE8B0+30Co
CODE.bss:8008D36C                                              # loop_to_decompress_entire_file+3Co
CODE.bss:8008D36C                                              # loop_to_decompress_entire_file+44w
*/

/* rodata
D:8005BF80     dword_D_8005BF80:.word 0x11720000        # DATA XREF: decompressdata+24r
D:8005BF84     dword_D_8005BF84:.word 0x11720000        # DATA XREF: decompressdata+44r
D:8005BF88     dword_D_8005BF88:.word 0x11720000        # DATA XREF: decompressdata+54r
D:8005BF8C                     .word 0x11720000
D:8005BF90                     .word 0x11720000
D:8005BF94                     .word 0x11720000
D:8005BF98     dword_D_8005BF98:.word 0x11720000        # DATA XREF: decompressdata:loc_CODE_7F0CE854r
D:8005BF9C                     .word 0x11720000
D:8005BFA0                     .word 0x11720000
D:8005BFA4                     .word 0x11720000
D:8005BFA8                     .word 0
D:8005BFAC                     .word 0
*/



#ifdef NONMATCHING
void decompressdata(void) {

}
#else
GLOBAL_ASM(
.text
glabel decompressdata
/* 103320 7F0CE7F0 3C078009 */  lui   $a3, %hi(dword_CODE_bss_8008D350) # $a3, 0x8009
/* 103324 7F0CE7F4 24E7D350 */  addiu $a3, %lo(dword_CODE_bss_8008D350) # addiu $a3, $a3, -0x2cb0
/* 103328 7F0CE7F8 ACE40000 */  sw    $a0, ($a3)
/* 10332C 7F0CE7FC 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D354) # $at, 0x8009
/* 103330 7F0CE800 AC25D354 */  sw    $a1, %lo(dword_CODE_bss_8008D354)($at)
/* 103334 7F0CE804 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 103338 7F0CE808 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D360) # $at, 0x8009
/* 10333C 7F0CE80C AFBF0014 */  sw    $ra, 0x14($sp)
/* 103340 7F0CE810 AC26D360 */  sw    $a2, %lo(dword_CODE_bss_8008D360)($at)
/* 103344 7F0CE814 3C0E8006 */  lui   $t6, %hi(D_8005BF80) # $t6, 0x8006
/* 103348 7F0CE818 91CEBF80 */  lbu   $t6, %lo(D_8005BF80)($t6)
/* 10334C 7F0CE81C 90820000 */  lbu   $v0, ($a0)
/* 103350 7F0CE820 3C188006 */  lui   $t8, %hi(D_8005BF85) # $t8, 0x8006
/* 103354 7F0CE824 3C198006 */  lui   $t9, %hi(D_8005BF88) # $t9, 0x8006
/* 103358 7F0CE828 144E0005 */  bne   $v0, $t6, .L7F0CE840
/* 10335C 7F0CE82C 3C0A8006 */   lui   $t2, %hi(D_8005BF98) # $t2, 0x8006
/* 103360 7F0CE830 908F0001 */  lbu   $t7, 1($a0)
/* 103364 7F0CE834 9318BF85 */  lbu   $t8, %lo(D_8005BF85)($t8)
/* 103368 7F0CE838 51F8000A */  beql  $t7, $t8, .L7F0CE864
/* 10336C 7F0CE83C 8CEC0000 */   lw    $t4, ($a3)
.L7F0CE840:
/* 103370 7F0CE840 9083FFFF */  lbu   $v1, -1($a0)
/* 103374 7F0CE844 9339BF88 */  lbu   $t9, %lo(D_8005BF88)($t9)
/* 103378 7F0CE848 54790002 */  bnel  $v1, $t9, .L7F0CE854
/* 10337C 7F0CE84C 9089FFFE */   lbu   $t1, -2($a0)
/* 103380 7F0CE850 9089FFFE */  lbu   $t1, -2($a0)
.L7F0CE854:
/* 103384 7F0CE854 914ABF98 */  lbu   $t2, %lo(D_8005BF98)($t2)
/* 103388 7F0CE858 552A0002 */  bnel  $t1, $t2, .L7F0CE864
/* 10338C 7F0CE85C 8CEC0000 */   lw    $t4, ($a3)
/* 103390 7F0CE860 8CEC0000 */  lw    $t4, ($a3)
.L7F0CE864:
/* 103394 7F0CE864 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D35C) # $at, 0x8009
/* 103398 7F0CE868 258D0002 */  addiu $t5, $t4, 2
/* 10339C 7F0CE86C ACED0000 */  sw    $t5, ($a3)
/* 1033A0 7F0CE870 AC20D35C */  sw    $zero, %lo(dword_CODE_bss_8008D35C)($at)
/* 1033A4 7F0CE874 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D358) # $at, 0x8009
/* 1033A8 7F0CE878 0FC33F35 */  jal   loop_to_decompress_entire_file
/* 1033AC 7F0CE87C AC20D358 */   sw    $zero, %lo(dword_CODE_bss_8008D358)($at)
/* 1033B0 7F0CE880 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1033B4 7F0CE884 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D35C) # $v0, 0x8009
/* 1033B8 7F0CE888 8C42D35C */  lw    $v0, %lo(dword_CODE_bss_8008D35C)($v0)
/* 1033BC 7F0CE88C 03E00008 */  jr    $ra
/* 1033C0 7F0CE890 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CE894(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CE894
/* 1033C4 7F0CE894 3C0E8009 */  lui   $t6, %hi(dword_CODE_bss_8008D350) # $t6, 0x8009
/* 1033C8 7F0CE898 3C0F8009 */  lui   $t7, %hi(dword_CODE_bss_8008D358) # $t7, 0x8009
/* 1033CC 7F0CE89C 8DEFD358 */  lw    $t7, %lo(dword_CODE_bss_8008D358)($t7)
/* 1033D0 7F0CE8A0 8DCED350 */  lw    $t6, %lo(dword_CODE_bss_8008D350)($t6)
/* 1033D4 7F0CE8A4 03E00008 */  jr    $ra
/* 1033D8 7F0CE8A8 01CF1021 */   addu  $v0, $t6, $t7
)
#endif


