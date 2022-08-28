#include <ultra64.h>
#include "image.h"
#include <assets/image_externs.h>
#include <PR/R4300.h>
#include "ramrom.h"

// bss
//8008C720
struct texturething *ptr_texture_alloc_start;
//8008C724
s32 ptr_texture_alloc_end;
//8008C728
s32 ptr_next_available_space;
//8008C72C
s32 ptr_last_entry_facemapping;
//8008C730
s32 word_CODE_bss_8008C730[0x258];
//8008D090
s32 dword_CODE_bss_8008D090;
//8008D094
s32 imageid;


// data
//D:80049170
u32 bytes = 0x6DDD0;
//D:80049174
u32 D_80049174 = 0;

//D:80049178 #1	#bytes in pixel data for image
s32 g_TexFormatNumChannels[] = 
{
    4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1
};
//D:800491AC #2	1=alphagrab.  Grabs 1 bit of alpha data for each pixel
s32 g_TexFormatHas1BitAlpha[] = 
{
    0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0
};
//D:800491E0 #3	#bits in 'samples', *2	-1=bitmask
s32 g_TexFormatChannelSizes[] = 
{
    0x100, 0x20, 0x100, 0x20, 0x100, 0x10, 8, 0x100, 0x10, 0x100, 0x10, 0x100, 0x10
};
//D:80049214 #4	bitcount for pixel data
s32 g_TexFormatBitsPerPixel[] = 
{
     0x20, 0x10, 0x18, 0xF, 0x10, 8, 4, 8, 4, 0x10, 0x10, 0x10, 0x10, 
};
//D:80049248 #5	N64 image types (0=color, 1=YUV, 2=indexed, 3=IA, 4=I)
s32 g_TexFormatGbiMappings[] = 
{
    G_IM_FMT_RGBA, G_IM_FMT_RGBA, G_IM_FMT_RGBA, G_IM_FMT_RGBA,	
    G_IM_FMT_IA, G_IM_FMT_IA, G_IM_FMT_IA, 
    G_IM_FMT_I, G_IM_FMT_I, 
    G_IM_FMT_CI, G_IM_FMT_CI, G_IM_FMT_CI, G_IM_FMT_CI,
};
//D:8004927C #6	N64 pixel sizes (0=4bit, 1=8bit, 2=16bit, 3=32bit)
s32 g_TexFormatDepths[] = 
{
	G_IM_SIZ_32b,
    G_IM_SIZ_16b,
	G_IM_SIZ_32b,
	G_IM_SIZ_16b,
	G_IM_SIZ_16b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
	G_IM_SIZ_8b,
	G_IM_SIZ_4b,
};
//D:800492B0 #7	imageflip values for indexed types
s32 g_TexFormatLutModes[] = {
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_NONE,
	G_TT_RGBA16,
	G_TT_RGBA16,
	G_TT_IA16,
	G_TT_IA16,
};
//D:800492e4
s32 D_800492E4[] = 
{
    0, 0, 0, 0, 0, 0, 0
};
#define IMAGE(NAME, SZ, HS, HT, F3, F4, F5, F6) \
    {HS, HT, SZ, F3, F4, F5, F6 },

//D:80049300
//need way to calculate size at compile time from external data
struct image_entry g_Textures[] = {
    #include <assets/images.def>
    {HIT_DEFAULT, HIT_DEFAULT,0xFFFF,0,0,0,0}
};
#undef IMAGE


void nullsub_41(s32 arg0) {
    if (arg0);
}






#ifdef NONMATCHING
void texInflateZlib(void) {

}
#else
GLOBAL_ASM(
.text
glabel texInflateZlib
/* 0FB188 7F0C6658 27BDD458 */  addiu $sp, $sp, -0x2ba8
/* 0FB18C 7F0C665C AFBF004C */  sw    $ra, 0x4c($sp)
/* 0FB190 7F0C6660 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0FB194 7F0C6664 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0FB198 7F0C6668 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0FB19C 7F0C666C AFB70044 */  sw    $s7, 0x44($sp)
/* 0FB1A0 7F0C6670 AFB60040 */  sw    $s6, 0x40($sp)
/* 0FB1A4 7F0C6674 AFB40038 */  sw    $s4, 0x38($sp)
/* 0FB1A8 7F0C6678 AFB30034 */  sw    $s3, 0x34($sp)
/* 0FB1AC 7F0C667C AFB20030 */  sw    $s2, 0x30($sp)
/* 0FB1B0 7F0C6680 AFB00028 */  sw    $s0, 0x28($sp)
/* 0FB1B4 7F0C6684 AFA52BAC */  sw    $a1, 0x2bac($sp)
/* 0FB1B8 7F0C6688 AFA62BB0 */  sw    $a2, 0x2bb0($sp)
/* 0FB1BC 7F0C668C AFA72BB4 */  sw    $a3, 0x2bb4($sp)
/* 0FB1C0 7F0C6690 00008825 */  move  $s1, $zero
/* 0FB1C4 7F0C6694 0FC32FC4 */  jal   texSetBitstring
/* 0FB1C8 7F0C6698 0000A825 */   move  $s5, $zero
/* 0FB1CC 7F0C669C 8FA62BB0 */  lw    $a2, 0x2bb0($sp)
/* 0FB1D0 7F0C66A0 8FA72BB4 */  lw    $a3, 0x2bb4($sp)
/* 0FB1D4 7F0C66A4 00004025 */  move  $t0, $zero
/* 0FB1D8 7F0C66A8 50C00006 */  beql  $a2, $zero, .L7F0C66C4
/* 0FB1DC 7F0C66AC 240E0001 */   li    $t6, 1
/* 0FB1E0 7F0C66B0 50E00004 */  beql  $a3, $zero, .L7F0C66C4
/* 0FB1E4 7F0C66B4 240E0001 */   li    $t6, 1
/* 0FB1E8 7F0C66B8 10000004 */  b     .L7F0C66CC
/* 0FB1EC 7F0C66BC AFA72B9C */   sw    $a3, 0x2b9c($sp)
/* 0FB1F0 7F0C66C0 240E0001 */  li    $t6, 1
.L7F0C66C4:
/* 0FB1F4 7F0C66C4 8FA72BB4 */  lw    $a3, 0x2bb4($sp)
/* 0FB1F8 7F0C66C8 AFAE2B9C */  sw    $t6, 0x2b9c($sp)
.L7F0C66CC:
/* 0FB1FC 7F0C66CC 8FBE2BB8 */  lw    $fp, 0x2bb8($sp)
/* 0FB200 7F0C66D0 0007C940 */  sll   $t9, $a3, 5
/* 0FB204 7F0C66D4 00066940 */  sll   $t5, $a2, 5
/* 0FB208 7F0C66D8 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB20C 7F0C66DC 31AE0020 */  andi  $t6, $t5, 0x20
/* 0FB210 7F0C66E0 3C058009 */  lui   $a1, %hi(dword_CODE_bss_8008D090)
/* 0FB214 7F0C66E4 9069000B */  lbu   $t1, 0xb($v1)
/* 0FB218 7F0C66E8 312AFF1F */  andi  $t2, $t1, 0xff1f
/* 0FB21C 7F0C66EC 032A5825 */  or    $t3, $t9, $t2
/* 0FB220 7F0C66F0 A06B000B */  sb    $t3, 0xb($v1)
/* 0FB224 7F0C66F4 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB228 7F0C66F8 906F000C */  lbu   $t7, 0xc($v1)
/* 0FB22C 7F0C66FC 31F8FFDF */  andi  $t8, $t7, 0xffdf
/* 0FB230 7F0C6700 01D84825 */  or    $t1, $t6, $t8
/* 0FB234 7F0C6704 10C00015 */  beqz  $a2, .L7F0C675C
/* 0FB238 7F0C6708 A069000C */   sb    $t1, 0xc($v1)
/* 0FB23C 7F0C670C 8CA5D090 */  lw    $a1, %lo(dword_CODE_bss_8008D090)($a1)
/* 0FB240 7F0C6710 24150001 */  li    $s5, 1
/* 0FB244 7F0C6714 18A00011 */  blez  $a1, .L7F0C675C
/* 0FB248 7F0C6718 00000000 */   nop   
/* 0FB24C 7F0C671C 8FD9000C */  lw    $t9, 0xc($fp)
/* 0FB250 7F0C6720 3C0B8009 */  lui   $t3, %hi(word_CODE_bss_8008C730)
/* 0FB254 7F0C6724 2562C730 */  addiu $v0, $t3, %lo(word_CODE_bss_8008C730)
/* 0FB258 7F0C6728 8F230000 */  lw    $v1, ($t9)
/* 0FB25C 7F0C672C 00056100 */  sll   $t4, $a1, 4
/* 0FB260 7F0C6730 01822021 */  addu  $a0, $t4, $v0
/* 0FB264 7F0C6734 00035502 */  srl   $t2, $v1, 0x14
/* 0FB268 7F0C6738 01401825 */  move  $v1, $t2
/* 0FB26C 7F0C673C 844D0000 */  lh    $t5, ($v0)
.L7F0C6740:
/* 0FB270 7F0C6740 24420010 */  addiu $v0, $v0, 0x10
/* 0FB274 7F0C6744 0044082B */  sltu  $at, $v0, $a0
/* 0FB278 7F0C6748 146D0002 */  bne   $v1, $t5, .L7F0C6754
/* 0FB27C 7F0C674C 00000000 */   nop   
/* 0FB280 7F0C6750 0000A825 */  move  $s5, $zero
.L7F0C6754:
/* 0FB284 7F0C6754 5420FFFA */  bnezl $at, .L7F0C6740
/* 0FB288 7F0C6758 844D0000 */   lh    $t5, ($v0)
.L7F0C675C:
/* 0FB28C 7F0C675C 0FC32FCB */  jal   texReadBits
/* 0FB290 7F0C6760 24040008 */   li    $a0, 8
/* 0FB294 7F0C6764 AFA22B94 */  sw    $v0, 0x2b94($sp)
/* 0FB298 7F0C6768 0FC32FCB */  jal   texReadBits
/* 0FB29C 7F0C676C 24040008 */   li    $a0, 8
/* 0FB2A0 7F0C6770 24430001 */  addiu $v1, $v0, 1
/* 0FB2A4 7F0C6774 1860000D */  blez  $v1, .L7F0C67AC
/* 0FB2A8 7F0C6778 AFA32B78 */   sw    $v1, 0x2b78($sp)
/* 0FB2AC 7F0C677C 8FAE2B78 */  lw    $t6, 0x2b78($sp)
/* 0FB2B0 7F0C6780 27A30070 */  addiu $v1, $sp, 0x70
/* 0FB2B4 7F0C6784 000EC040 */  sll   $t8, $t6, 1
/* 0FB2B8 7F0C6788 03038021 */  addu  $s0, $t8, $v1
.L7F0C678C:
/* 0FB2BC 7F0C678C 24040010 */  li    $a0, 16
/* 0FB2C0 7F0C6790 0FC32FCB */  jal   texReadBits
/* 0FB2C4 7F0C6794 AFA3005C */   sw    $v1, 0x5c($sp)
/* 0FB2C8 7F0C6798 8FA3005C */  lw    $v1, 0x5c($sp)
/* 0FB2CC 7F0C679C 24630002 */  addiu $v1, $v1, 2
/* 0FB2D0 7F0C67A0 0070082B */  sltu  $at, $v1, $s0
/* 0FB2D4 7F0C67A4 1420FFF9 */  bnez  $at, .L7F0C678C
/* 0FB2D8 7F0C67A8 A462FFFE */   sh    $v0, -2($v1)
.L7F0C67AC:
/* 0FB2DC 7F0C67AC 8FA92B9C */  lw    $t1, 0x2b9c($sp)
/* 0FB2E0 7F0C67B0 3C178005 */  lui   $s7, %hi(g_TexFormatGbiMappings) 
/* 0FB2E4 7F0C67B4 26F79248 */  addiu $s7, %lo(g_TexFormatGbiMappings) # addiu $s7, $s7, -0x6db8
/* 0FB2E8 7F0C67B8 19200064 */  blez  $t1, .L7F0C694C
/* 0FB2EC 7F0C67BC 00009825 */   move  $s3, $zero
/* 0FB2F0 7F0C67C0 27B42370 */  addiu $s4, $sp, 0x2370
.L7F0C67C4:
/* 0FB2F4 7F0C67C4 0FC32FCB */  jal   texReadBits
/* 0FB2F8 7F0C67C8 24040008 */   li    $a0, 8
/* 0FB2FC 7F0C67CC 0040B025 */  move  $s6, $v0
/* 0FB300 7F0C67D0 0FC32FCB */  jal   texReadBits
/* 0FB304 7F0C67D4 24040008 */   li    $a0, 8
/* 0FB308 7F0C67D8 16600029 */  bnez  $s3, .L7F0C6880
/* 0FB30C 7F0C67DC AFA22B84 */   sw    $v0, 0x2b84($sp)
/* 0FB310 7F0C67E0 8FD9000C */  lw    $t9, 0xc($fp)
/* 0FB314 7F0C67E4 A3360008 */  sb    $s6, 8($t9)
/* 0FB318 7F0C67E8 8FCA000C */  lw    $t2, 0xc($fp)
/* 0FB31C 7F0C67EC A1420009 */  sb    $v0, 9($t2)
/* 0FB320 7F0C67F0 8FAC2B78 */  lw    $t4, 0x2b78($sp)
/* 0FB324 7F0C67F4 8FCD000C */  lw    $t5, 0xc($fp)
/* 0FB328 7F0C67F8 258BFFFF */  addiu $t3, $t4, -1
/* 0FB32C 7F0C67FC A1AB000A */  sb    $t3, 0xa($t5)
/* 0FB330 7F0C6800 8FA42B94 */  lw    $a0, 0x2b94($sp)
/* 0FB334 7F0C6804 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB338 7F0C6808 00047080 */  sll   $t6, $a0, 2
/* 0FB33C 7F0C680C 02EEC021 */  addu  $t8, $s7, $t6
/* 0FB340 7F0C6810 8F090000 */  lw    $t1, ($t8)
/* 0FB344 7F0C6814 906C000B */  lbu   $t4, 0xb($v1)
/* 0FB348 7F0C6818 01C02025 */  move  $a0, $t6
/* 0FB34C 7F0C681C 0009C880 */  sll   $t9, $t1, 2
/* 0FB350 7F0C6820 332A001C */  andi  $t2, $t9, 0x1c
/* 0FB354 7F0C6824 318BFFE3 */  andi  $t3, $t4, 0xffe3
/* 0FB358 7F0C6828 014B6825 */  or    $t5, $t2, $t3
/* 0FB35C 7F0C682C A06D000B */  sb    $t5, 0xb($v1)
/* 0FB360 7F0C6830 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB364 7F0C6834 3C0E8005 */  lui   $t6, %hi(g_TexFormatDepths)
/* 0FB368 7F0C6838 01C47021 */  addu  $t6, $t6, $a0
/* 0FB36C 7F0C683C 8DD8927C */  lw    $t8, %lo(g_TexFormatDepths)($t6)
/* 0FB370 7F0C6840 9069000B */  lbu   $t1, 0xb($v1)
/* 0FB374 7F0C6844 3C0A8005 */  lui   $t2, %hi(g_TexFormatLutModes)
/* 0FB378 7F0C6848 330F0003 */  andi  $t7, $t8, 3
/* 0FB37C 7F0C684C 3139FFFC */  andi  $t9, $t1, 0xfffc
/* 0FB380 7F0C6850 01F96025 */  or    $t4, $t7, $t9
/* 0FB384 7F0C6854 A06C000B */  sb    $t4, 0xb($v1)
/* 0FB388 7F0C6858 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB38C 7F0C685C 01445021 */  addu  $t2, $t2, $a0
/* 0FB390 7F0C6860 8D4A92B0 */  lw    $t2, %lo(g_TexFormatLutModes)($t2)
/* 0FB394 7F0C6864 9069000C */  lbu   $t1, 0xc($v1)
/* 0FB398 7F0C6868 000A6B83 */  sra   $t5, $t2, 0xe
/* 0FB39C 7F0C686C 000DC180 */  sll   $t8, $t5, 6
/* 0FB3A0 7F0C6870 312FFF3F */  andi  $t7, $t1, 0xff3f
/* 0FB3A4 7F0C6874 030FC825 */  or    $t9, $t8, $t7
/* 0FB3A8 7F0C6878 1000000B */  b     .L7F0C68A8
/* 0FB3AC 7F0C687C A079000C */   sb    $t9, 0xc($v1)
.L7F0C6880:
/* 0FB3B0 7F0C6880 12A00009 */  beqz  $s5, .L7F0C68A8
/* 0FB3B4 7F0C6884 3C0C8009 */   lui   $t4, %hi(dword_CODE_bss_8008D090) 
/* 0FB3B8 7F0C6888 8D8CD090 */  lw    $t4, %lo(dword_CODE_bss_8008D090)($t4)
/* 0FB3BC 7F0C688C 3C0D8009 */  lui   $t5, %hi(word_CODE_bss_8008C730) 
/* 0FB3C0 7F0C6890 25ADC730 */  addiu $t5, %lo(word_CODE_bss_8008C730) # addiu $t5, $t5, -0x38d0
/* 0FB3C4 7F0C6894 000C5100 */  sll   $t2, $t4, 4
/* 0FB3C8 7F0C6898 01535821 */  addu  $t3, $t2, $s3
/* 0FB3CC 7F0C689C 016D1821 */  addu  $v1, $t3, $t5
/* 0FB3D0 7F0C68A0 A0760001 */  sb    $s6, 1($v1)
/* 0FB3D4 7F0C68A4 A0620008 */  sb    $v0, 8($v1)
.L7F0C68A8:
/* 0FB3D8 7F0C68A8 02C20019 */  multu $s6, $v0
/* 0FB3DC 7F0C68AC 3C048009 */  lui   $a0, %hi(img_curpos)
/* 0FB3E0 7F0C68B0 02802825 */  move  $a1, $s4
/* 0FB3E4 7F0C68B4 27A60270 */  addiu $a2, $sp, 0x270
/* 0FB3E8 7F0C68B8 00007012 */  mflo  $t6
/* 0FB3EC 7F0C68BC 29C11001 */  slti  $at, $t6, 0x1001
/* 0FB3F0 7F0C68C0 14200003 */  bnez  $at, .L7F0C68D0
/* 0FB3F4 7F0C68C4 00000000 */   nop   
/* 0FB3F8 7F0C68C8 100000B3 */  b     .L7F0C6B98
/* 0FB3FC 7F0C68CC 00001025 */   move  $v0, $zero
.L7F0C68D0:
/* 0FB400 7F0C68D0 0FC339FC */  jal   decompressdata
/* 0FB404 7F0C68D4 8C84D0A0 */   lw    $a0, %lo(img_curpos)($a0)
/* 0FB408 7F0C68D8 8FA92BAC */  lw    $t1, 0x2bac($sp)
/* 0FB40C 7F0C68DC 02802025 */  move  $a0, $s4
/* 0FB410 7F0C68E0 02C02825 */  move  $a1, $s6
/* 0FB414 7F0C68E4 01318021 */  addu  $s0, $t1, $s1
/* 0FB418 7F0C68E8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB41C 7F0C68EC 8FA62B84 */  lw    $a2, 0x2b84($sp)
/* 0FB420 7F0C68F0 0FC31AF2 */  jal   texAlignIndices
/* 0FB424 7F0C68F4 8FA72B94 */   lw    $a3, 0x2b94($sp)
/* 0FB428 7F0C68F8 0FC33A25 */  jal   rzipGetSomething
/* 0FB42C 7F0C68FC 00409025 */   move  $s2, $v0
/* 0FB430 7F0C6900 0FC32FC4 */  jal   texSetBitstring
/* 0FB434 7F0C6904 00402025 */   move  $a0, $v0
/* 0FB438 7F0C6908 8FB82BB0 */  lw    $t8, 0x2bb0($sp)
/* 0FB43C 7F0C690C 24010001 */  li    $at, 1
/* 0FB440 7F0C6910 8FAF2BB4 */  lw    $t7, 0x2bb4($sp)
/* 0FB444 7F0C6914 57010008 */  bnel  $t8, $at, .L7F0C6938
/* 0FB448 7F0C6918 8FB92B9C */   lw    $t9, 0x2b9c($sp)
/* 0FB44C 7F0C691C 19E00005 */  blez  $t7, .L7F0C6934
/* 0FB450 7F0C6920 02002025 */   move  $a0, $s0
/* 0FB454 7F0C6924 02C02825 */  move  $a1, $s6
/* 0FB458 7F0C6928 8FA62B84 */  lw    $a2, 0x2b84($sp)
/* 0FB45C 7F0C692C 0FC32D9F */  jal   texSwapAltRowBytes
/* 0FB460 7F0C6930 8FA72B94 */   lw    $a3, 0x2b94($sp)
.L7F0C6934:
/* 0FB464 7F0C6934 8FB92B9C */  lw    $t9, 0x2b9c($sp)
.L7F0C6938:
/* 0FB468 7F0C6938 26730001 */  addiu $s3, $s3, 1
/* 0FB46C 7F0C693C 02328821 */  addu  $s1, $s1, $s2
/* 0FB470 7F0C6940 1679FFA0 */  bne   $s3, $t9, .L7F0C67C4
/* 0FB474 7F0C6944 00000000 */   nop   
/* 0FB478 7F0C6948 AFB62B88 */  sw    $s6, 0x2b88($sp)
.L7F0C694C:
/* 0FB47C 7F0C694C 8FB62B88 */  lw    $s6, 0x2b88($sp)
/* 0FB480 7F0C6950 12A00010 */  beqz  $s5, .L7F0C6994
/* 0FB484 7F0C6954 00004025 */   move  $t0, $zero
/* 0FB488 7F0C6958 8FCC000C */  lw    $t4, 0xc($fp)
/* 0FB48C 7F0C695C 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D090)
/* 0FB490 7F0C6960 2442D090 */  addiu $v0, %lo(dword_CODE_bss_8008D090) # addiu $v0, $v0, -0x2f70
/* 0FB494 7F0C6964 8C450000 */  lw    $a1, ($v0)
/* 0FB498 7F0C6968 8D8A0000 */  lw    $t2, ($t4)
/* 0FB49C 7F0C696C 3C018009 */  lui   $at, %hi(word_CODE_bss_8008C730)
/* 0FB4A0 7F0C6970 00056900 */  sll   $t5, $a1, 4
/* 0FB4A4 7F0C6974 002D0821 */  addu  $at, $at, $t5
/* 0FB4A8 7F0C6978 000A5D02 */  srl   $t3, $t2, 0x14
/* 0FB4AC 7F0C697C A42BC730 */  sh    $t3, %lo(word_CODE_bss_8008C730)($at)
/* 0FB4B0 7F0C6980 24AE0001 */  addiu $t6, $a1, 1
/* 0FB4B4 7F0C6984 29C10096 */  slti  $at, $t6, 0x96
/* 0FB4B8 7F0C6988 14200002 */  bnez  $at, .L7F0C6994
/* 0FB4BC 7F0C698C AC4E0000 */   sw    $t6, ($v0)
/* 0FB4C0 7F0C6990 AC400000 */  sw    $zero, ($v0)
.L7F0C6994:
/* 0FB4C4 7F0C6994 8FB82BB0 */  lw    $t8, 0x2bb0($sp)
/* 0FB4C8 7F0C6998 8FAF2BB4 */  lw    $t7, 0x2bb4($sp)
/* 0FB4CC 7F0C699C 17000046 */  bnez  $t8, .L7F0C6AB8
/* 0FB4D0 7F0C69A0 29F90002 */   slti  $t9, $t7, 2
/* 0FB4D4 7F0C69A4 3B390001 */  xori  $t9, $t9, 1
/* 0FB4D8 7F0C69A8 1320003A */  beqz  $t9, .L7F0C6A94
/* 0FB4DC 7F0C69AC 8FAE2BB4 */   lw    $t6, 0x2bb4($sp)
/* 0FB4E0 7F0C69B0 8FB72BAC */  lw    $s7, 0x2bac($sp)
/* 0FB4E4 7F0C69B4 02C0A025 */  move  $s4, $s6
/* 0FB4E8 7F0C69B8 8FB52B84 */  lw    $s5, 0x2b84($sp)
/* 0FB4EC 7F0C69BC 24130001 */  li    $s3, 1
/* 0FB4F0 7F0C69C0 1320002C */  beqz  $t9, .L7F0C6A74
/* 0FB4F4 7F0C69C4 02F18021 */   addu  $s0, $s7, $s1
/* 0FB4F8 7F0C69C8 27B60070 */  addiu $s6, $sp, 0x70
.L7F0C69CC:
/* 0FB4FC 7F0C69CC 8FAA2B94 */  lw    $t2, 0x2b94($sp)
/* 0FB500 7F0C69D0 8FAB2B78 */  lw    $t3, 0x2b78($sp)
/* 0FB504 7F0C69D4 02E02025 */  move  $a0, $s7
/* 0FB508 7F0C69D8 02002825 */  move  $a1, $s0
/* 0FB50C 7F0C69DC 02803025 */  move  $a2, $s4
/* 0FB510 7F0C69E0 02A03825 */  move  $a3, $s5
/* 0FB514 7F0C69E4 AFB60014 */  sw    $s6, 0x14($sp)
/* 0FB518 7F0C69E8 AFA82BA4 */  sw    $t0, 0x2ba4($sp)
/* 0FB51C 7F0C69EC AFAA0010 */  sw    $t2, 0x10($sp)
/* 0FB520 7F0C69F0 0FC31B1C */  jal   sub_GAME_7F0C6C70
/* 0FB524 7F0C69F4 AFAB0018 */   sw    $t3, 0x18($sp)
/* 0FB528 7F0C69F8 02226821 */  addu  $t5, $s1, $v0
/* 0FB52C 7F0C69FC 29A10801 */  slti  $at, $t5, 0x801
/* 0FB530 7F0C6A00 8FA82BA4 */  lw    $t0, 0x2ba4($sp)
/* 0FB534 7F0C6A04 14200008 */  bnez  $at, .L7F0C6A28
/* 0FB538 7F0C6A08 00409025 */   move  $s2, $v0
/* 0FB53C 7F0C6A0C 8FC3000C */  lw    $v1, 0xc($fp)
/* 0FB540 7F0C6A10 0013C140 */  sll   $t8, $s3, 5
/* 0FB544 7F0C6A14 906F000B */  lbu   $t7, 0xb($v1)
/* 0FB548 7F0C6A18 31ECFF1F */  andi  $t4, $t7, 0xff1f
/* 0FB54C 7F0C6A1C 030CC825 */  or    $t9, $t8, $t4
/* 0FB550 7F0C6A20 10000014 */  b     .L7F0C6A74
/* 0FB554 7F0C6A24 A079000B */   sb    $t9, 0xb($v1)
.L7F0C6A28:
/* 0FB558 7F0C6A28 02E02025 */  move  $a0, $s7
/* 0FB55C 7F0C6A2C 02802825 */  move  $a1, $s4
/* 0FB560 7F0C6A30 02A03025 */  move  $a2, $s5
/* 0FB564 7F0C6A34 8FA72B94 */  lw    $a3, 0x2b94($sp)
/* 0FB568 7F0C6A38 0FC32D9F */  jal   texSwapAltRowBytes
/* 0FB56C 7F0C6A3C AFA82BA4 */   sw    $t0, 0x2ba4($sp)
/* 0FB570 7F0C6A40 8FAD2BB4 */  lw    $t5, 0x2bb4($sp)
/* 0FB574 7F0C6A44 26940001 */  addiu $s4, $s4, 1
/* 0FB578 7F0C6A48 26B50001 */  addiu $s5, $s5, 1
/* 0FB57C 7F0C6A4C 26730001 */  addiu $s3, $s3, 1
/* 0FB580 7F0C6A50 00145043 */  sra   $t2, $s4, 1
/* 0FB584 7F0C6A54 00155843 */  sra   $t3, $s5, 1
/* 0FB588 7F0C6A58 0200B825 */  move  $s7, $s0
/* 0FB58C 7F0C6A5C 8FA82BA4 */  lw    $t0, 0x2ba4($sp)
/* 0FB590 7F0C6A60 02328821 */  addu  $s1, $s1, $s2
/* 0FB594 7F0C6A64 0140A025 */  move  $s4, $t2
/* 0FB598 7F0C6A68 0160A825 */  move  $s5, $t3
/* 0FB59C 7F0C6A6C 166DFFD7 */  bne   $s3, $t5, .L7F0C69CC
/* 0FB5A0 7F0C6A70 02128021 */   addu  $s0, $s0, $s2
.L7F0C6A74:
/* 0FB5A4 7F0C6A74 02E02025 */  move  $a0, $s7
/* 0FB5A8 7F0C6A78 02802825 */  move  $a1, $s4
/* 0FB5AC 7F0C6A7C 02A03025 */  move  $a2, $s5
/* 0FB5B0 7F0C6A80 8FA72B94 */  lw    $a3, 0x2b94($sp)
/* 0FB5B4 7F0C6A84 0FC32D9F */  jal   texSwapAltRowBytes
/* 0FB5B8 7F0C6A88 AFA82BA4 */   sw    $t0, 0x2ba4($sp)
/* 0FB5BC 7F0C6A8C 1000000A */  b     .L7F0C6AB8
/* 0FB5C0 7F0C6A90 8FA82BA4 */   lw    $t0, 0x2ba4($sp)
.L7F0C6A94:
/* 0FB5C4 7F0C6A94 24010001 */  li    $at, 1
/* 0FB5C8 7F0C6A98 15C10007 */  bne   $t6, $at, .L7F0C6AB8
/* 0FB5CC 7F0C6A9C 8FA42BAC */   lw    $a0, 0x2bac($sp)
/* 0FB5D0 7F0C6AA0 02C02825 */  move  $a1, $s6
/* 0FB5D4 7F0C6AA4 8FA62B84 */  lw    $a2, 0x2b84($sp)
/* 0FB5D8 7F0C6AA8 8FA72B94 */  lw    $a3, 0x2b94($sp)
/* 0FB5DC 7F0C6AAC 0FC32D9F */  jal   texSwapAltRowBytes
/* 0FB5E0 7F0C6AB0 AFA82BA4 */   sw    $t0, 0x2ba4($sp)
/* 0FB5E4 7F0C6AB4 8FA82BA4 */  lw    $t0, 0x2ba4($sp)
.L7F0C6AB8:
/* 0FB5E8 7F0C6AB8 8FA92B78 */  lw    $t1, 0x2b78($sp)
/* 0FB5EC 7F0C6ABC 8FAF2BAC */  lw    $t7, 0x2bac($sp)
/* 0FB5F0 7F0C6AC0 2401FFF8 */  li    $at, -8
/* 0FB5F4 7F0C6AC4 19200032 */  blez  $t1, .L7F0C6B90
/* 0FB5F8 7F0C6AC8 31240003 */   andi  $a0, $t1, 3
/* 0FB5FC 7F0C6ACC 10800012 */  beqz  $a0, .L7F0C6B18
/* 0FB600 7F0C6AD0 01F18021 */   addu  $s0, $t7, $s1
/* 0FB604 7F0C6AD4 0008C040 */  sll   $t8, $t0, 1
/* 0FB608 7F0C6AD8 27AC0070 */  addiu $t4, $sp, 0x70
/* 0FB60C 7F0C6ADC 030C1821 */  addu  $v1, $t8, $t4
/* 0FB610 7F0C6AE0 00801025 */  move  $v0, $a0
.L7F0C6AE4:
/* 0FB614 7F0C6AE4 94790000 */  lhu   $t9, ($v1)
/* 0FB618 7F0C6AE8 25080001 */  addiu $t0, $t0, 1
/* 0FB61C 7F0C6AEC 26310002 */  addiu $s1, $s1, 2
/* 0FB620 7F0C6AF0 00195203 */  sra   $t2, $t9, 8
/* 0FB624 7F0C6AF4 A20A0000 */  sb    $t2, ($s0)
/* 0FB628 7F0C6AF8 946D0000 */  lhu   $t5, ($v1)
/* 0FB62C 7F0C6AFC 26100002 */  addiu $s0, $s0, 2
/* 0FB630 7F0C6B00 24630002 */  addiu $v1, $v1, 2
/* 0FB634 7F0C6B04 1448FFF7 */  bne   $v0, $t0, .L7F0C6AE4
/* 0FB638 7F0C6B08 A20DFFFF */   sb    $t5, -1($s0)
/* 0FB63C 7F0C6B0C 8FAE2B78 */  lw    $t6, 0x2b78($sp)
/* 0FB640 7F0C6B10 510E0020 */  beql  $t0, $t6, .L7F0C6B94
/* 0FB644 7F0C6B14 26310007 */   addiu $s1, $s1, 7
.L7F0C6B18:
/* 0FB648 7F0C6B18 8FB82B78 */  lw    $t8, 0x2b78($sp)
/* 0FB64C 7F0C6B1C 27A90070 */  addiu $t1, $sp, 0x70
/* 0FB650 7F0C6B20 00087840 */  sll   $t7, $t0, 1
/* 0FB654 7F0C6B24 00186040 */  sll   $t4, $t8, 1
/* 0FB658 7F0C6B28 01891021 */  addu  $v0, $t4, $t1
/* 0FB65C 7F0C6B2C 01E91821 */  addu  $v1, $t7, $t1
.L7F0C6B30:
/* 0FB660 7F0C6B30 94790000 */  lhu   $t9, ($v1)
/* 0FB664 7F0C6B34 24630008 */  addiu $v1, $v1, 8
/* 0FB668 7F0C6B38 26310008 */  addiu $s1, $s1, 8
/* 0FB66C 7F0C6B3C 00195203 */  sra   $t2, $t9, 8
/* 0FB670 7F0C6B40 A20A0000 */  sb    $t2, ($s0)
/* 0FB674 7F0C6B44 946DFFF8 */  lhu   $t5, -8($v1)
/* 0FB678 7F0C6B48 26100008 */  addiu $s0, $s0, 8
/* 0FB67C 7F0C6B4C A20DFFF9 */  sb    $t5, -7($s0)
/* 0FB680 7F0C6B50 946EFFFA */  lhu   $t6, -6($v1)
/* 0FB684 7F0C6B54 000E7A03 */  sra   $t7, $t6, 8
/* 0FB688 7F0C6B58 A20FFFFA */  sb    $t7, -6($s0)
/* 0FB68C 7F0C6B5C 946CFFFA */  lhu   $t4, -6($v1)
/* 0FB690 7F0C6B60 A20CFFFB */  sb    $t4, -5($s0)
/* 0FB694 7F0C6B64 9469FFFC */  lhu   $t1, -4($v1)
/* 0FB698 7F0C6B68 0009CA03 */  sra   $t9, $t1, 8
/* 0FB69C 7F0C6B6C A219FFFC */  sb    $t9, -4($s0)
/* 0FB6A0 7F0C6B70 946BFFFC */  lhu   $t3, -4($v1)
/* 0FB6A4 7F0C6B74 A20BFFFD */  sb    $t3, -3($s0)
/* 0FB6A8 7F0C6B78 946DFFFE */  lhu   $t5, -2($v1)
/* 0FB6AC 7F0C6B7C 000D7203 */  sra   $t6, $t5, 8
/* 0FB6B0 7F0C6B80 A20EFFFE */  sb    $t6, -2($s0)
/* 0FB6B4 7F0C6B84 9478FFFE */  lhu   $t8, -2($v1)
/* 0FB6B8 7F0C6B88 1462FFE9 */  bne   $v1, $v0, .L7F0C6B30
/* 0FB6BC 7F0C6B8C A218FFFF */   sb    $t8, -1($s0)
.L7F0C6B90:
/* 0FB6C0 7F0C6B90 26310007 */  addiu $s1, $s1, 7
.L7F0C6B94:
/* 0FB6C4 7F0C6B94 02211024 */  and   $v0, $s1, $at
.L7F0C6B98:
/* 0FB6C8 7F0C6B98 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0FB6CC 7F0C6B9C 8FB00028 */  lw    $s0, 0x28($sp)
/* 0FB6D0 7F0C6BA0 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0FB6D4 7F0C6BA4 8FB20030 */  lw    $s2, 0x30($sp)
/* 0FB6D8 7F0C6BA8 8FB30034 */  lw    $s3, 0x34($sp)
/* 0FB6DC 7F0C6BAC 8FB40038 */  lw    $s4, 0x38($sp)
/* 0FB6E0 7F0C6BB0 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0FB6E4 7F0C6BB4 8FB60040 */  lw    $s6, 0x40($sp)
/* 0FB6E8 7F0C6BB8 8FB70044 */  lw    $s7, 0x44($sp)
/* 0FB6EC 7F0C6BBC 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0FB6F0 7F0C6BC0 03E00008 */  jr    $ra
/* 0FB6F4 7F0C6BC4 27BD2BA8 */   addiu $sp, $sp, 0x2ba8
)
#endif





#ifdef NONMATCHING
/* pd version
s32 texAlignIndices(u8 *src, s32 width, s32 height, s32 format, u8 *dst)
{
	u8 *outptr = dst;
	s32 x;
	s32 y;
	s32 indicesperbyte;

	if (format == TEXFORMAT_RGBA16_CI8 || format == TEXFORMAT_IA16_CI8) {
		indicesperbyte = 1;
	} else if (format == TEXFORMAT_RGBA16_CI4 || format == TEXFORMAT_0C) {
		indicesperbyte = 2;
	}

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x += indicesperbyte) {
			*outptr = *src;
			outptr++;
			src++;
		}

		outptr = (u8 *)(((u32)outptr + 7) & ~7);
	}

	return outptr - dst;
}
//*/


//uses extra a0 for copy 
//fb744:    li      v0,2                            r fb744:    li      a0,2
//                                                  > fb748:    move    v0,a0
s32 texAlignIndices(u8 *src, s32 width, s32 height, s32 format, u8 *dst, s32 indicesperbyte)
{
    
    //s32 indicesperbyte;
	
	s32 x;
	s32 y;
    u8 *outptr = dst;
	s32 unused;
    indicesperbyte = (format == TEXFORMAT_RGBA16_CI8 || format == TEXFORMAT_IA16_CI8) ? 1 : (format == TEXFORMAT_RGBA16_CI4 || format == TEXFORMAT_0C) ? 2:unused;
	//if (format == TEXFORMAT_RGBA16_CI8 || format == TEXFORMAT_IA16_CI8) {
	//	indicesperbyte = 1;
	//} else if (format == TEXFORMAT_RGBA16_CI4 || format == TEXFORMAT_0C) {
	//	indicesperbyte = 2;
	//}

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x += indicesperbyte) {
			*outptr = *src;
			outptr++;
			src++;
		}

		outptr = (u8 *)(((u32)outptr + 7) & ~7);
	}

	return outptr - dst;
}


#else
GLOBAL_ASM(
.text
glabel texAlignIndices
/* 0FB6F8 7F0C6BC8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB6FC 7F0C6BCC AFB1000C */  sw    $s1, 0xc($sp)
/* 0FB700 7F0C6BD0 AFB00008 */  sw    $s0, 8($sp)
/* 0FB704 7F0C6BD4 24010009 */  li    $at, 9
/* 0FB708 7F0C6BD8 00A08025 */  move  $s0, $a1
/* 0FB70C 7F0C6BDC 00808825 */  move  $s1, $a0
/* 0FB710 7F0C6BE0 10E10004 */  beq   $a3, $at, .L7F0C6BF4
/* 0FB714 7F0C6BE4 8FA30030 */   lw    $v1, 0x30($sp)
/* 0FB718 7F0C6BE8 2401000B */  li    $at, 11
/* 0FB71C 7F0C6BEC 54E10004 */  bnel  $a3, $at, .L7F0C6C00
/* 0FB720 7F0C6BF0 2401000A */   li    $at, 10
.L7F0C6BF4:
/* 0FB724 7F0C6BF4 10000008 */  b     .L7F0C6C18
/* 0FB728 7F0C6BF8 24020001 */   li    $v0, 1
/* 0FB72C 7F0C6BFC 2401000A */  li    $at, 10
.L7F0C6C00:
/* 0FB730 7F0C6C00 10E10003 */  beq   $a3, $at, .L7F0C6C10
/* 0FB734 7F0C6C04 2401000C */   li    $at, 12
/* 0FB738 7F0C6C08 14E10003 */  bne   $a3, $at, .L7F0C6C18
/* 0FB73C 7F0C6C0C 8FA20010 */   lw    $v0, 0x10($sp)
.L7F0C6C10:
/* 0FB740 7F0C6C10 10000001 */  b     .L7F0C6C18
/* 0FB744 7F0C6C14 24020002 */   li    $v0, 2
.L7F0C6C18:
/* 0FB748 7F0C6C18 18C0000F */  blez  $a2, .L7F0C6C58
/* 0FB74C 7F0C6C1C 00002025 */   move  $a0, $zero
/* 0FB750 7F0C6C20 2407FFF8 */  li    $a3, -8
.L7F0C6C24:
/* 0FB754 7F0C6C24 1A000008 */  blez  $s0, .L7F0C6C48
/* 0FB758 7F0C6C28 00002825 */   move  $a1, $zero
.L7F0C6C2C:
/* 0FB75C 7F0C6C2C 922E0000 */  lbu   $t6, ($s1)
/* 0FB760 7F0C6C30 00A22821 */  addu  $a1, $a1, $v0
/* 0FB764 7F0C6C34 00B0082A */  slt   $at, $a1, $s0
/* 0FB768 7F0C6C38 24630001 */  addiu $v1, $v1, 1
/* 0FB76C 7F0C6C3C 26310001 */  addiu $s1, $s1, 1
/* 0FB770 7F0C6C40 1420FFFA */  bnez  $at, .L7F0C6C2C
/* 0FB774 7F0C6C44 A06EFFFF */   sb    $t6, -1($v1)
.L7F0C6C48:
/* 0FB778 7F0C6C48 24840001 */  addiu $a0, $a0, 1
/* 0FB77C 7F0C6C4C 246F0007 */  addiu $t7, $v1, 7
/* 0FB780 7F0C6C50 1486FFF4 */  bne   $a0, $a2, .L7F0C6C24
/* 0FB784 7F0C6C54 01E71824 */   and   $v1, $t7, $a3
.L7F0C6C58:
/* 0FB788 7F0C6C58 8FB80030 */  lw    $t8, 0x30($sp)
/* 0FB78C 7F0C6C5C 8FB00008 */  lw    $s0, 8($sp)
/* 0FB790 7F0C6C60 8FB1000C */  lw    $s1, 0xc($sp)
/* 0FB794 7F0C6C64 27BD0020 */  addiu $sp, $sp, 0x20
/* 0FB798 7F0C6C68 03E00008 */  jr    $ra
/* 0FB79C 7F0C6C6C 00781023 */   subu  $v0, $v1, $t8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C6C70(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C6C70
/* 0FB7A0 7F0C6C70 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 0FB7A4 7F0C6C74 AFB00020 */  sw    $s0, 0x20($sp)
/* 0FB7A8 7F0C6C78 8FB000B8 */  lw    $s0, 0xb8($sp)
/* 0FB7AC 7F0C6C7C 24EF0001 */  addiu $t7, $a3, 1
/* 0FB7B0 7F0C6C80 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0FB7B4 7F0C6C84 AFB50034 */  sw    $s5, 0x34($sp)
/* 0FB7B8 7F0C6C88 24020009 */  li    $v0, 9
/* 0FB7BC 7F0C6C8C 000FC043 */  sra   $t8, $t7, 1
/* 0FB7C0 7F0C6C90 00C0F025 */  move  $fp, $a2
/* 0FB7C4 7F0C6C94 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0FB7C8 7F0C6C98 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0FB7CC 7F0C6C9C AFB60038 */  sw    $s6, 0x38($sp)
/* 0FB7D0 7F0C6CA0 AFB40030 */  sw    $s4, 0x30($sp)
/* 0FB7D4 7F0C6CA4 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0FB7D8 7F0C6CA8 AFB20028 */  sw    $s2, 0x28($sp)
/* 0FB7DC 7F0C6CAC AFB10024 */  sw    $s1, 0x24($sp)
/* 0FB7E0 7F0C6CB0 AFA700B4 */  sw    $a3, 0xb4($sp)
/* 0FB7E4 7F0C6CB4 AFA50074 */  sw    $a1, 0x74($sp)
/* 0FB7E8 7F0C6CB8 0080A825 */  move  $s5, $a0
/* 0FB7EC 7F0C6CBC AFB80060 */  sw    $t8, 0x60($sp)
/* 0FB7F0 7F0C6CC0 1202000B */  beq   $s0, $v0, .L7F0C6CF0
/* 0FB7F4 7F0C6CC4 AFB80094 */   sw    $t8, 0x94($sp)
/* 0FB7F8 7F0C6CC8 2401000A */  li    $at, 10
/* 0FB7FC 7F0C6CCC 12010011 */  beq   $s0, $at, .L7F0C6D14
/* 0FB800 7F0C6CD0 27CF0001 */   addiu $t7, $fp, 1
/* 0FB804 7F0C6CD4 2401000B */  li    $at, 11
/* 0FB808 7F0C6CD8 12010005 */  beq   $s0, $at, .L7F0C6CF0
/* 0FB80C 7F0C6CDC 2401000C */   li    $at, 12
/* 0FB810 7F0C6CE0 5201000D */  beql  $s0, $at, .L7F0C6D18
/* 0FB814 7F0C6CE4 000FC043 */   sra   $t8, $t7, 1
/* 0FB818 7F0C6CE8 10000011 */  b     .L7F0C6D30
/* 0FB81C 7F0C6CEC 00000000 */   nop   
.L7F0C6CF0:
/* 0FB820 7F0C6CF0 27D90001 */  addiu $t9, $fp, 1
/* 0FB824 7F0C6CF4 00195043 */  sra   $t2, $t9, 1
/* 0FB828 7F0C6CF8 254B0007 */  addiu $t3, $t2, 7
/* 0FB82C 7F0C6CFC 27CD0007 */  addiu $t5, $fp, 7
/* 0FB830 7F0C6D00 316C0FF8 */  andi  $t4, $t3, 0xff8
/* 0FB834 7F0C6D04 31AE0FF8 */  andi  $t6, $t5, 0xff8
/* 0FB838 7F0C6D08 AFAC0098 */  sw    $t4, 0x98($sp)
/* 0FB83C 7F0C6D0C 10000008 */  b     .L7F0C6D30
/* 0FB840 7F0C6D10 AFAE009C */   sw    $t6, 0x9c($sp)
.L7F0C6D14:
/* 0FB844 7F0C6D14 000FC043 */  sra   $t8, $t7, 1
.L7F0C6D18:
/* 0FB848 7F0C6D18 2719000F */  addiu $t9, $t8, 0xf
/* 0FB84C 7F0C6D1C 27CB000F */  addiu $t3, $fp, 0xf
/* 0FB850 7F0C6D20 332A0FF0 */  andi  $t2, $t9, 0xff0
/* 0FB854 7F0C6D24 316C0FF0 */  andi  $t4, $t3, 0xff0
/* 0FB858 7F0C6D28 AFAA0098 */  sw    $t2, 0x98($sp)
/* 0FB85C 7F0C6D2C AFAC009C */  sw    $t4, 0x9c($sp)
.L7F0C6D30:
/* 0FB860 7F0C6D30 12020009 */  beq   $s0, $v0, .L7F0C6D58
/* 0FB864 7F0C6D34 2401000A */   li    $at, 10
/* 0FB868 7F0C6D38 120100ED */  beq   $s0, $at, .L7F0C70F0
/* 0FB86C 7F0C6D3C 2401000B */   li    $at, 11
/* 0FB870 7F0C6D40 12010086 */  beq   $s0, $at, .L7F0C6F5C
/* 0FB874 7F0C6D44 2401000C */   li    $at, 12
/* 0FB878 7F0C6D48 120101D9 */  beq   $s0, $at, .L7F0C74B0
/* 0FB87C 7F0C6D4C 00001025 */   move  $v0, $zero
/* 0FB880 7F0C6D50 1000028A */  b     .L7F0C777C
/* 0FB884 7F0C6D54 00000000 */   nop   
.L7F0C6D58:
/* 0FB888 7F0C6D58 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0FB88C 7F0C6D5C 8FAE009C */  lw    $t6, 0x9c($sp)
/* 0FB890 7F0C6D60 AFA000A0 */  sw    $zero, 0xa0($sp)
/* 0FB894 7F0C6D64 19A00077 */  blez  $t5, .L7F0C6F44
/* 0FB898 7F0C6D68 000E7840 */   sll   $t7, $t6, 1
/* 0FB89C 7F0C6D6C AFAF0050 */  sw    $t7, 0x50($sp)
/* 0FB8A0 7F0C6D70 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 0FB8A4 7F0C6D74 8FB300BC */  lw    $s3, 0xbc($sp)
.L7F0C6D78:
/* 0FB8A8 7F0C6D78 8FB900A0 */  lw    $t9, 0xa0($sp)
/* 0FB8AC 7F0C6D7C 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0FB8B0 7F0C6D80 00008825 */  move  $s1, $zero
/* 0FB8B4 7F0C6D84 272A0001 */  addiu $t2, $t9, 1
/* 0FB8B8 7F0C6D88 0158082A */  slt   $at, $t2, $t8
/* 0FB8BC 7F0C6D8C 10200003 */  beqz  $at, .L7F0C6D9C
/* 0FB8C0 7F0C6D90 8FAB009C */   lw    $t3, 0x9c($sp)
/* 0FB8C4 7F0C6D94 10000002 */  b     .L7F0C6DA0
/* 0FB8C8 7F0C6D98 8FB6009C */   lw    $s6, 0x9c($sp)
.L7F0C6D9C:
/* 0FB8CC 7F0C6D9C 0000B025 */  move  $s6, $zero
.L7F0C6DA0:
/* 0FB8D0 7F0C6DA0 1960005C */  blez  $t3, .L7F0C6F14
/* 0FB8D4 7F0C6DA4 02A09025 */   move  $s2, $s5
/* 0FB8D8 7F0C6DA8 02D5A021 */  addu  $s4, $s6, $s5
/* 0FB8DC 7F0C6DAC 26220001 */  addiu $v0, $s1, 1
.L7F0C6DB0:
/* 0FB8E0 7F0C6DB0 005E082A */  slt   $at, $v0, $fp
/* 0FB8E4 7F0C6DB4 10200003 */  beqz  $at, .L7F0C6DC4
/* 0FB8E8 7F0C6DB8 02602025 */   move  $a0, $s3
/* 0FB8EC 7F0C6DBC 10000002 */  b     .L7F0C6DC8
/* 0FB8F0 7F0C6DC0 00401825 */   move  $v1, $v0
.L7F0C6DC4:
/* 0FB8F4 7F0C6DC4 02201825 */  move  $v1, $s1
.L7F0C6DC8:
/* 0FB8F8 7F0C6DC8 924C0000 */  lbu   $t4, ($s2)
/* 0FB8FC 7F0C6DCC 02A37821 */  addu  $t7, $s5, $v1
/* 0FB900 7F0C6DD0 91F90000 */  lbu   $t9, ($t7)
/* 0FB904 7F0C6DD4 000C6840 */  sll   $t5, $t4, 1
/* 0FB908 7F0C6DD8 026D7021 */  addu  $t6, $s3, $t5
/* 0FB90C 7F0C6DDC 85D00000 */  lh    $s0, ($t6)
/* 0FB910 7F0C6DE0 02C37021 */  addu  $t6, $s6, $v1
/* 0FB914 7F0C6DE4 928B0000 */  lbu   $t3, ($s4)
/* 0FB918 7F0C6DE8 01D57821 */  addu  $t7, $t6, $s5
/* 0FB91C 7F0C6DEC 0019C040 */  sll   $t8, $t9, 1
/* 0FB920 7F0C6DF0 91F90000 */  lbu   $t9, ($t7)
/* 0FB924 7F0C6DF4 02785021 */  addu  $t2, $s3, $t8
/* 0FB928 7F0C6DF8 85480000 */  lh    $t0, ($t2)
/* 0FB92C 7F0C6DFC 000B6040 */  sll   $t4, $t3, 1
/* 0FB930 7F0C6E00 026C6821 */  addu  $t5, $s3, $t4
/* 0FB934 7F0C6E04 0019C040 */  sll   $t8, $t9, 1
/* 0FB938 7F0C6E08 85A90000 */  lh    $t1, ($t5)
/* 0FB93C 7F0C6E0C 02785021 */  addu  $t2, $s3, $t8
/* 0FB940 7F0C6E10 85420000 */  lh    $v0, ($t2)
/* 0FB944 7F0C6E14 00105AC3 */  sra   $t3, $s0, 0xb
/* 0FB948 7F0C6E18 316C001F */  andi  $t4, $t3, 0x1f
/* 0FB94C 7F0C6E1C 00086AC3 */  sra   $t5, $t0, 0xb
/* 0FB950 7F0C6E20 31AE001F */  andi  $t6, $t5, 0x1f
/* 0FB954 7F0C6E24 0009CAC3 */  sra   $t9, $t1, 0xb
/* 0FB958 7F0C6E28 3338001F */  andi  $t8, $t9, 0x1f
/* 0FB95C 7F0C6E2C 018E7821 */  addu  $t7, $t4, $t6
/* 0FB960 7F0C6E30 00025AC3 */  sra   $t3, $v0, 0xb
/* 0FB964 7F0C6E34 316D001F */  andi  $t5, $t3, 0x1f
/* 0FB968 7F0C6E38 01F85021 */  addu  $t2, $t7, $t8
/* 0FB96C 7F0C6E3C 014D3021 */  addu  $a2, $t2, $t5
/* 0FB970 7F0C6E40 0010C983 */  sra   $t9, $s0, 6
/* 0FB974 7F0C6E44 332F001F */  andi  $t7, $t9, 0x1f
/* 0FB978 7F0C6E48 00066083 */  sra   $t4, $a2, 2
/* 0FB97C 7F0C6E4C 0008C183 */  sra   $t8, $t0, 6
/* 0FB980 7F0C6E50 330B001F */  andi  $t3, $t8, 0x1f
/* 0FB984 7F0C6E54 3186001F */  andi  $a2, $t4, 0x1f
/* 0FB988 7F0C6E58 00096983 */  sra   $t5, $t1, 6
/* 0FB98C 7F0C6E5C 31AC001F */  andi  $t4, $t5, 0x1f
/* 0FB990 7F0C6E60 01EB5021 */  addu  $t2, $t7, $t3
/* 0FB994 7F0C6E64 0002C983 */  sra   $t9, $v0, 6
/* 0FB998 7F0C6E68 3338001F */  andi  $t8, $t9, 0x1f
/* 0FB99C 7F0C6E6C 014C7021 */  addu  $t6, $t2, $t4
/* 0FB9A0 7F0C6E70 01D83821 */  addu  $a3, $t6, $t8
/* 0FB9A4 7F0C6E74 00106843 */  sra   $t5, $s0, 1
/* 0FB9A8 7F0C6E78 31AA001F */  andi  $t2, $t5, 0x1f
/* 0FB9AC 7F0C6E7C 00077883 */  sra   $t7, $a3, 2
/* 0FB9B0 7F0C6E80 00086043 */  sra   $t4, $t0, 1
/* 0FB9B4 7F0C6E84 3199001F */  andi  $t9, $t4, 0x1f
/* 0FB9B8 7F0C6E88 31E7001F */  andi  $a3, $t7, 0x1f
/* 0FB9BC 7F0C6E8C 0009C043 */  sra   $t8, $t1, 1
/* 0FB9C0 7F0C6E90 330F001F */  andi  $t7, $t8, 0x1f
/* 0FB9C4 7F0C6E94 01597021 */  addu  $t6, $t2, $t9
/* 0FB9C8 7F0C6E98 00026843 */  sra   $t5, $v0, 1
/* 0FB9CC 7F0C6E9C 31AC001F */  andi  $t4, $t5, 0x1f
/* 0FB9D0 7F0C6EA0 01CF5821 */  addu  $t3, $t6, $t7
/* 0FB9D4 7F0C6EA4 016C5021 */  addu  $t2, $t3, $t4
/* 0FB9D8 7F0C6EA8 000AC883 */  sra   $t9, $t2, 2
/* 0FB9DC 7F0C6EAC 320E0001 */  andi  $t6, $s0, 1
/* 0FB9E0 7F0C6EB0 310F0001 */  andi  $t7, $t0, 1
/* 0FB9E4 7F0C6EB4 01CF6821 */  addu  $t5, $t6, $t7
/* 0FB9E8 7F0C6EB8 3338001F */  andi  $t8, $t9, 0x1f
/* 0FB9EC 7F0C6EBC 312B0001 */  andi  $t3, $t1, 1
/* 0FB9F0 7F0C6EC0 01AB6021 */  addu  $t4, $t5, $t3
/* 0FB9F4 7F0C6EC4 304A0001 */  andi  $t2, $v0, 1
/* 0FB9F8 7F0C6EC8 018AC821 */  addu  $t9, $t4, $t2
/* 0FB9FC 7F0C6ECC AFB80010 */  sw    $t8, 0x10($sp)
/* 0FBA00 7F0C6ED0 27380002 */  addiu $t8, $t9, 2
/* 0FBA04 7F0C6ED4 00187083 */  sra   $t6, $t8, 2
/* 0FBA08 7F0C6ED8 31CF0001 */  andi  $t7, $t6, 1
/* 0FBA0C 7F0C6EDC AFAF0014 */  sw    $t7, 0x14($sp)
/* 0FBA10 7F0C6EE0 0FC31DEB */  jal   sub_GAME_7F0C77AC
/* 0FBA14 7F0C6EE4 02E02825 */   move  $a1, $s7
/* 0FBA18 7F0C6EE8 8FAD0074 */  lw    $t5, 0x74($sp)
/* 0FBA1C 7F0C6EEC 00115843 */  sra   $t3, $s1, 1
/* 0FBA20 7F0C6EF0 26310002 */  addiu $s1, $s1, 2
/* 0FBA24 7F0C6EF4 01AB6021 */  addu  $t4, $t5, $t3
/* 0FBA28 7F0C6EF8 A1820000 */  sb    $v0, ($t4)
/* 0FBA2C 7F0C6EFC 8FAA009C */  lw    $t2, 0x9c($sp)
/* 0FBA30 7F0C6F00 26520002 */  addiu $s2, $s2, 2
/* 0FBA34 7F0C6F04 26940002 */  addiu $s4, $s4, 2
/* 0FBA38 7F0C6F08 022A082A */  slt   $at, $s1, $t2
/* 0FBA3C 7F0C6F0C 5420FFA8 */  bnezl $at, .L7F0C6DB0
/* 0FBA40 7F0C6F10 26220001 */   addiu $v0, $s1, 1
.L7F0C6F14:
/* 0FBA44 7F0C6F14 8FAD00A0 */  lw    $t5, 0xa0($sp)
/* 0FBA48 7F0C6F18 8FAC00B4 */  lw    $t4, 0xb4($sp)
/* 0FBA4C 7F0C6F1C 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FBA50 7F0C6F20 8FB80098 */  lw    $t8, 0x98($sp)
/* 0FBA54 7F0C6F24 8FAF0050 */  lw    $t7, 0x50($sp)
/* 0FBA58 7F0C6F28 25AB0002 */  addiu $t3, $t5, 2
/* 0FBA5C 7F0C6F2C 016C082A */  slt   $at, $t3, $t4
/* 0FBA60 7F0C6F30 03387021 */  addu  $t6, $t9, $t8
/* 0FBA64 7F0C6F34 AFAB00A0 */  sw    $t3, 0xa0($sp)
/* 0FBA68 7F0C6F38 AFAE0074 */  sw    $t6, 0x74($sp)
/* 0FBA6C 7F0C6F3C 1420FF8E */  bnez  $at, .L7F0C6D78
/* 0FBA70 7F0C6F40 02AFA821 */   addu  $s5, $s5, $t7
.L7F0C6F44:
/* 0FBA74 7F0C6F44 8FAA0060 */  lw    $t2, 0x60($sp)
/* 0FBA78 7F0C6F48 8FB90098 */  lw    $t9, 0x98($sp)
/* 0FBA7C 7F0C6F4C 01590019 */  multu $t2, $t9
/* 0FBA80 7F0C6F50 00001012 */  mflo  $v0
/* 0FBA84 7F0C6F54 1000020A */  b     .L7F0C7780
/* 0FBA88 7F0C6F58 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F0C6F5C:
/* 0FBA8C 7F0C6F5C 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0FBA90 7F0C6F60 8FAE009C */  lw    $t6, 0x9c($sp)
/* 0FBA94 7F0C6F64 AFA000A0 */  sw    $zero, 0xa0($sp)
/* 0FBA98 7F0C6F68 1B00005B */  blez  $t8, .L7F0C70D8
/* 0FBA9C 7F0C6F6C 000E7840 */   sll   $t7, $t6, 1
/* 0FBAA0 7F0C6F70 AFAF0050 */  sw    $t7, 0x50($sp)
/* 0FBAA4 7F0C6F74 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 0FBAA8 7F0C6F78 8FB300BC */  lw    $s3, 0xbc($sp)
.L7F0C6F7C:
/* 0FBAAC 7F0C6F7C 8FAB00A0 */  lw    $t3, 0xa0($sp)
/* 0FBAB0 7F0C6F80 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0FBAB4 7F0C6F84 00008825 */  move  $s1, $zero
/* 0FBAB8 7F0C6F88 256C0001 */  addiu $t4, $t3, 1
/* 0FBABC 7F0C6F8C 018D082A */  slt   $at, $t4, $t5
/* 0FBAC0 7F0C6F90 10200003 */  beqz  $at, .L7F0C6FA0
/* 0FBAC4 7F0C6F94 8FAA009C */   lw    $t2, 0x9c($sp)
/* 0FBAC8 7F0C6F98 10000002 */  b     .L7F0C6FA4
/* 0FBACC 7F0C6F9C 8FB6009C */   lw    $s6, 0x9c($sp)
.L7F0C6FA0:
/* 0FBAD0 7F0C6FA0 0000B025 */  move  $s6, $zero
.L7F0C6FA4:
/* 0FBAD4 7F0C6FA4 19400040 */  blez  $t2, .L7F0C70A8
/* 0FBAD8 7F0C6FA8 02A09025 */   move  $s2, $s5
/* 0FBADC 7F0C6FAC 02D5A021 */  addu  $s4, $s6, $s5
/* 0FBAE0 7F0C6FB0 26220001 */  addiu $v0, $s1, 1
.L7F0C6FB4:
/* 0FBAE4 7F0C6FB4 005E082A */  slt   $at, $v0, $fp
/* 0FBAE8 7F0C6FB8 10200003 */  beqz  $at, .L7F0C6FC8
/* 0FBAEC 7F0C6FBC 02602025 */   move  $a0, $s3
/* 0FBAF0 7F0C6FC0 10000002 */  b     .L7F0C6FCC
/* 0FBAF4 7F0C6FC4 00401825 */   move  $v1, $v0
.L7F0C6FC8:
/* 0FBAF8 7F0C6FC8 02201825 */  move  $v1, $s1
.L7F0C6FCC:
/* 0FBAFC 7F0C6FCC 92590000 */  lbu   $t9, ($s2)
/* 0FBB00 7F0C6FD0 02A37821 */  addu  $t7, $s5, $v1
/* 0FBB04 7F0C6FD4 91EB0000 */  lbu   $t3, ($t7)
/* 0FBB08 7F0C6FD8 0019C040 */  sll   $t8, $t9, 1
/* 0FBB0C 7F0C6FDC 02787021 */  addu  $t6, $s3, $t8
/* 0FBB10 7F0C6FE0 85D00000 */  lh    $s0, ($t6)
/* 0FBB14 7F0C6FE4 928A0000 */  lbu   $t2, ($s4)
/* 0FBB18 7F0C6FE8 02C37021 */  addu  $t6, $s6, $v1
/* 0FBB1C 7F0C6FEC 01D57821 */  addu  $t7, $t6, $s5
/* 0FBB20 7F0C6FF0 000B6840 */  sll   $t5, $t3, 1
/* 0FBB24 7F0C6FF4 91EB0000 */  lbu   $t3, ($t7)
/* 0FBB28 7F0C6FF8 026D6021 */  addu  $t4, $s3, $t5
/* 0FBB2C 7F0C6FFC 000AC840 */  sll   $t9, $t2, 1
/* 0FBB30 7F0C7000 85880000 */  lh    $t0, ($t4)
/* 0FBB34 7F0C7004 0279C021 */  addu  $t8, $s3, $t9
/* 0FBB38 7F0C7008 87090000 */  lh    $t1, ($t8)
/* 0FBB3C 7F0C700C 000B6840 */  sll   $t5, $t3, 1
/* 0FBB40 7F0C7010 026D6021 */  addu  $t4, $s3, $t5
/* 0FBB44 7F0C7014 85820000 */  lh    $v0, ($t4)
/* 0FBB48 7F0C7018 00105203 */  sra   $t2, $s0, 8
/* 0FBB4C 7F0C701C 0008C203 */  sra   $t8, $t0, 8
/* 0FBB50 7F0C7020 330E00FF */  andi  $t6, $t8, 0xff
/* 0FBB54 7F0C7024 315900FF */  andi  $t9, $t2, 0xff
/* 0FBB58 7F0C7028 00095A03 */  sra   $t3, $t1, 8
/* 0FBB5C 7F0C702C 316D00FF */  andi  $t5, $t3, 0xff
/* 0FBB60 7F0C7030 032E7821 */  addu  $t7, $t9, $t6
/* 0FBB64 7F0C7034 01ED6021 */  addu  $t4, $t7, $t5
/* 0FBB68 7F0C7038 00025203 */  sra   $t2, $v0, 8
/* 0FBB6C 7F0C703C 315800FF */  andi  $t8, $t2, 0xff
/* 0FBB70 7F0C7040 01983021 */  addu  $a2, $t4, $t8
/* 0FBB74 7F0C7044 320B00FF */  andi  $t3, $s0, 0xff
/* 0FBB78 7F0C7048 310F00FF */  andi  $t7, $t0, 0xff
/* 0FBB7C 7F0C704C 016F6821 */  addu  $t5, $t3, $t7
/* 0FBB80 7F0C7050 312A00FF */  andi  $t2, $t1, 0xff
/* 0FBB84 7F0C7054 01AA6021 */  addu  $t4, $t5, $t2
/* 0FBB88 7F0C7058 305800FF */  andi  $t8, $v0, 0xff
/* 0FBB8C 7F0C705C 01983821 */  addu  $a3, $t4, $t8
/* 0FBB90 7F0C7060 0006C883 */  sra   $t9, $a2, 2
/* 0FBB94 7F0C7064 332600FF */  andi  $a2, $t9, 0xff
/* 0FBB98 7F0C7068 24E70001 */  addiu $a3, $a3, 1
/* 0FBB9C 7F0C706C 0007C883 */  sra   $t9, $a3, 2
/* 0FBBA0 7F0C7070 332700FF */  andi  $a3, $t9, 0xff
/* 0FBBA4 7F0C7074 0FC31EF6 */  jal   sub_GAME_7F0C7BD8
/* 0FBBA8 7F0C7078 02E02825 */   move  $a1, $s7
/* 0FBBAC 7F0C707C 8FAB0074 */  lw    $t3, 0x74($sp)
/* 0FBBB0 7F0C7080 00117843 */  sra   $t7, $s1, 1
/* 0FBBB4 7F0C7084 26310002 */  addiu $s1, $s1, 2
/* 0FBBB8 7F0C7088 016F6821 */  addu  $t5, $t3, $t7
/* 0FBBBC 7F0C708C A1A20000 */  sb    $v0, ($t5)
/* 0FBBC0 7F0C7090 8FAA009C */  lw    $t2, 0x9c($sp)
/* 0FBBC4 7F0C7094 26520002 */  addiu $s2, $s2, 2
/* 0FBBC8 7F0C7098 26940002 */  addiu $s4, $s4, 2
/* 0FBBCC 7F0C709C 022A082A */  slt   $at, $s1, $t2
/* 0FBBD0 7F0C70A0 5420FFC4 */  bnezl $at, .L7F0C6FB4
/* 0FBBD4 7F0C70A4 26220001 */   addiu $v0, $s1, 1
.L7F0C70A8:
/* 0FBBD8 7F0C70A8 8FAB00A0 */  lw    $t3, 0xa0($sp)
/* 0FBBDC 7F0C70AC 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0FBBE0 7F0C70B0 8FAC0074 */  lw    $t4, 0x74($sp)
/* 0FBBE4 7F0C70B4 8FB80098 */  lw    $t8, 0x98($sp)
/* 0FBBE8 7F0C70B8 8FAE0050 */  lw    $t6, 0x50($sp)
/* 0FBBEC 7F0C70BC 256F0002 */  addiu $t7, $t3, 2
/* 0FBBF0 7F0C70C0 01ED082A */  slt   $at, $t7, $t5
/* 0FBBF4 7F0C70C4 0198C821 */  addu  $t9, $t4, $t8
/* 0FBBF8 7F0C70C8 AFAF00A0 */  sw    $t7, 0xa0($sp)
/* 0FBBFC 7F0C70CC AFB90074 */  sw    $t9, 0x74($sp)
/* 0FBC00 7F0C70D0 1420FFAA */  bnez  $at, .L7F0C6F7C
/* 0FBC04 7F0C70D4 02AEA821 */   addu  $s5, $s5, $t6
.L7F0C70D8:
/* 0FBC08 7F0C70D8 8FAA0060 */  lw    $t2, 0x60($sp)
/* 0FBC0C 7F0C70DC 8FAC0098 */  lw    $t4, 0x98($sp)
/* 0FBC10 7F0C70E0 014C0019 */  multu $t2, $t4
/* 0FBC14 7F0C70E4 00001012 */  mflo  $v0
/* 0FBC18 7F0C70E8 100001A5 */  b     .L7F0C7780
/* 0FBC1C 7F0C70EC 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F0C70F0:
/* 0FBC20 7F0C70F0 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0FBC24 7F0C70F4 8FB90098 */  lw    $t9, 0x98($sp)
/* 0FBC28 7F0C70F8 AFA000A0 */  sw    $zero, 0xa0($sp)
/* 0FBC2C 7F0C70FC 1B0000E5 */  blez  $t8, .L7F0C7494
/* 0FBC30 7F0C7100 00197043 */   sra   $t6, $t9, 1
/* 0FBC34 7F0C7104 AFAE004C */  sw    $t6, 0x4c($sp)
/* 0FBC38 7F0C7108 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 0FBC3C 7F0C710C 8FB300BC */  lw    $s3, 0xbc($sp)
.L7F0C7110:
/* 0FBC40 7F0C7110 8FAF00A0 */  lw    $t7, 0xa0($sp)
/* 0FBC44 7F0C7114 8FAB00B4 */  lw    $t3, 0xb4($sp)
/* 0FBC48 7F0C7118 00008825 */  move  $s1, $zero
/* 0FBC4C 7F0C711C 25ED0001 */  addiu $t5, $t7, 1
/* 0FBC50 7F0C7120 01AB082A */  slt   $at, $t5, $t3
/* 0FBC54 7F0C7124 10200005 */  beqz  $at, .L7F0C713C
/* 0FBC58 7F0C7128 8FAC009C */   lw    $t4, 0x9c($sp)
/* 0FBC5C 7F0C712C 8FB6009C */  lw    $s6, 0x9c($sp)
/* 0FBC60 7F0C7130 00165043 */  sra   $t2, $s6, 1
/* 0FBC64 7F0C7134 10000002 */  b     .L7F0C7140
/* 0FBC68 7F0C7138 0140B025 */   move  $s6, $t2
.L7F0C713C:
/* 0FBC6C 7F0C713C 0000B025 */  move  $s6, $zero
.L7F0C7140:
/* 0FBC70 7F0C7140 198000C8 */  blez  $t4, .L7F0C7464
/* 0FBC74 7F0C7144 02B6A021 */   addu  $s4, $s5, $s6
/* 0FBC78 7F0C7148 00112843 */  sra   $a1, $s1, 1
.L7F0C714C:
/* 0FBC7C 7F0C714C 00B5C021 */  addu  $t8, $a1, $s5
/* 0FBC80 7F0C7150 93020000 */  lbu   $v0, ($t8)
/* 0FBC84 7F0C7154 262D0001 */  addiu $t5, $s1, 1
/* 0FBC88 7F0C7158 01BE202A */  slt   $a0, $t5, $fp
/* 0FBC8C 7F0C715C 0002C903 */  sra   $t9, $v0, 4
/* 0FBC90 7F0C7160 332E000F */  andi  $t6, $t9, 0xf
/* 0FBC94 7F0C7164 000E7840 */  sll   $t7, $t6, 1
/* 0FBC98 7F0C7168 026F5821 */  addu  $t3, $s3, $t7
/* 0FBC9C 7F0C716C 10800003 */  beqz  $a0, .L7F0C717C
/* 0FBCA0 7F0C7170 85700000 */   lh    $s0, ($t3)
/* 0FBCA4 7F0C7174 10000002 */  b     .L7F0C7180
/* 0FBCA8 7F0C7178 00001825 */   move  $v1, $zero
.L7F0C717C:
/* 0FBCAC 7F0C717C 24030004 */  li    $v1, 4
.L7F0C7180:
/* 0FBCB0 7F0C7180 00B67021 */  addu  $t6, $a1, $s6
/* 0FBCB4 7F0C7184 01D57821 */  addu  $t7, $t6, $s5
/* 0FBCB8 7F0C7188 91EB0000 */  lbu   $t3, ($t7)
/* 0FBCBC 7F0C718C 00625007 */  srav  $t2, $v0, $v1
/* 0FBCC0 7F0C7190 314C000F */  andi  $t4, $t2, 0xf
/* 0FBCC4 7F0C7194 000CC040 */  sll   $t8, $t4, 1
/* 0FBCC8 7F0C7198 000B6903 */  sra   $t5, $t3, 4
/* 0FBCCC 7F0C719C 31AA000F */  andi  $t2, $t5, 0xf
/* 0FBCD0 7F0C71A0 0278C821 */  addu  $t9, $s3, $t8
/* 0FBCD4 7F0C71A4 000A6040 */  sll   $t4, $t2, 1
/* 0FBCD8 7F0C71A8 026CC021 */  addu  $t8, $s3, $t4
/* 0FBCDC 7F0C71AC 87280000 */  lh    $t0, ($t9)
/* 0FBCE0 7F0C71B0 10800003 */  beqz  $a0, .L7F0C71C0
/* 0FBCE4 7F0C71B4 87090000 */   lh    $t1, ($t8)
/* 0FBCE8 7F0C71B8 10000002 */  b     .L7F0C71C4
/* 0FBCEC 7F0C71BC 00001825 */   move  $v1, $zero
.L7F0C71C0:
/* 0FBCF0 7F0C71C0 24030004 */  li    $v1, 4
.L7F0C71C4:
/* 0FBCF4 7F0C71C4 0285C821 */  addu  $t9, $s4, $a1
/* 0FBCF8 7F0C71C8 932E0000 */  lbu   $t6, ($t9)
/* 0FBCFC 7F0C71CC 001062C3 */  sra   $t4, $s0, 0xb
/* 0FBD00 7F0C71D0 3198001F */  andi  $t8, $t4, 0x1f
/* 0FBD04 7F0C71D4 006E7807 */  srav  $t7, $t6, $v1
/* 0FBD08 7F0C71D8 31EB000F */  andi  $t3, $t7, 0xf
/* 0FBD0C 7F0C71DC 000B6840 */  sll   $t5, $t3, 1
/* 0FBD10 7F0C71E0 026D5021 */  addu  $t2, $s3, $t5
/* 0FBD14 7F0C71E4 85420000 */  lh    $v0, ($t2)
/* 0FBD18 7F0C71E8 0008CAC3 */  sra   $t9, $t0, 0xb
/* 0FBD1C 7F0C71EC 332E001F */  andi  $t6, $t9, 0x1f
/* 0FBD20 7F0C71F0 00095AC3 */  sra   $t3, $t1, 0xb
/* 0FBD24 7F0C71F4 316D001F */  andi  $t5, $t3, 0x1f
/* 0FBD28 7F0C71F8 030E7821 */  addu  $t7, $t8, $t6
/* 0FBD2C 7F0C71FC 000262C3 */  sra   $t4, $v0, 0xb
/* 0FBD30 7F0C7200 3199001F */  andi  $t9, $t4, 0x1f
/* 0FBD34 7F0C7204 01ED5021 */  addu  $t2, $t7, $t5
/* 0FBD38 7F0C7208 01593021 */  addu  $a2, $t2, $t9
/* 0FBD3C 7F0C720C 00105983 */  sra   $t3, $s0, 6
/* 0FBD40 7F0C7210 316F001F */  andi  $t7, $t3, 0x1f
/* 0FBD44 7F0C7214 0006C083 */  sra   $t8, $a2, 2
/* 0FBD48 7F0C7218 00086983 */  sra   $t5, $t0, 6
/* 0FBD4C 7F0C721C 31AC001F */  andi  $t4, $t5, 0x1f
/* 0FBD50 7F0C7220 3306001F */  andi  $a2, $t8, 0x1f
/* 0FBD54 7F0C7224 0009C983 */  sra   $t9, $t1, 6
/* 0FBD58 7F0C7228 3338001F */  andi  $t8, $t9, 0x1f
/* 0FBD5C 7F0C722C 01EC5021 */  addu  $t2, $t7, $t4
/* 0FBD60 7F0C7230 00025983 */  sra   $t3, $v0, 6
/* 0FBD64 7F0C7234 316D001F */  andi  $t5, $t3, 0x1f
/* 0FBD68 7F0C7238 01587021 */  addu  $t6, $t2, $t8
/* 0FBD6C 7F0C723C 01CD3821 */  addu  $a3, $t6, $t5
/* 0FBD70 7F0C7240 0010C843 */  sra   $t9, $s0, 1
/* 0FBD74 7F0C7244 332A001F */  andi  $t2, $t9, 0x1f
/* 0FBD78 7F0C7248 00077883 */  sra   $t7, $a3, 2
/* 0FBD7C 7F0C724C 0008C043 */  sra   $t8, $t0, 1
/* 0FBD80 7F0C7250 330B001F */  andi  $t3, $t8, 0x1f
/* 0FBD84 7F0C7254 31E7001F */  andi  $a3, $t7, 0x1f
/* 0FBD88 7F0C7258 00096843 */  sra   $t5, $t1, 1
/* 0FBD8C 7F0C725C 31AF001F */  andi  $t7, $t5, 0x1f
/* 0FBD90 7F0C7260 014B7021 */  addu  $t6, $t2, $t3
/* 0FBD94 7F0C7264 0002C843 */  sra   $t9, $v0, 1
/* 0FBD98 7F0C7268 3338001F */  andi  $t8, $t9, 0x1f
/* 0FBD9C 7F0C726C 01CF6021 */  addu  $t4, $t6, $t7
/* 0FBDA0 7F0C7270 01985021 */  addu  $t2, $t4, $t8
/* 0FBDA4 7F0C7274 000A5883 */  sra   $t3, $t2, 2
/* 0FBDA8 7F0C7278 310F0001 */  andi  $t7, $t0, 1
/* 0FBDAC 7F0C727C 320E0001 */  andi  $t6, $s0, 1
/* 0FBDB0 7F0C7280 01CFC821 */  addu  $t9, $t6, $t7
/* 0FBDB4 7F0C7284 316D001F */  andi  $t5, $t3, 0x1f
/* 0FBDB8 7F0C7288 312C0001 */  andi  $t4, $t1, 1
/* 0FBDBC 7F0C728C 032CC021 */  addu  $t8, $t9, $t4
/* 0FBDC0 7F0C7290 304A0001 */  andi  $t2, $v0, 1
/* 0FBDC4 7F0C7294 030A5821 */  addu  $t3, $t8, $t2
/* 0FBDC8 7F0C7298 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0FBDCC 7F0C729C 256D0002 */  addiu $t5, $t3, 2
/* 0FBDD0 7F0C72A0 000D7083 */  sra   $t6, $t5, 2
/* 0FBDD4 7F0C72A4 31CF0001 */  andi  $t7, $t6, 1
/* 0FBDD8 7F0C72A8 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0FBDDC 7F0C72AC 02E02825 */  move  $a1, $s7
/* 0FBDE0 7F0C72B0 0FC31DEB */  jal   sub_GAME_7F0C77AC
/* 0FBDE4 7F0C72B4 02602025 */   move  $a0, $s3
/* 0FBDE8 7F0C72B8 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FBDEC 7F0C72BC 00116083 */  sra   $t4, $s1, 2
/* 0FBDF0 7F0C72C0 26260002 */  addiu $a2, $s1, 2
/* 0FBDF4 7F0C72C4 00025100 */  sll   $t2, $v0, 4
/* 0FBDF8 7F0C72C8 00065843 */  sra   $t3, $a2, 1
/* 0FBDFC 7F0C72CC 032C9021 */  addu  $s2, $t9, $t4
/* 0FBE00 7F0C72D0 A24A0000 */  sb    $t2, ($s2)
/* 0FBE04 7F0C72D4 01756821 */  addu  $t5, $t3, $s5
/* 0FBE08 7F0C72D8 91A40000 */  lbu   $a0, ($t5)
/* 0FBE0C 7F0C72DC 26380003 */  addiu $t8, $s1, 3
/* 0FBE10 7F0C72E0 031E282A */  slt   $a1, $t8, $fp
/* 0FBE14 7F0C72E4 00047103 */  sra   $t6, $a0, 4
/* 0FBE18 7F0C72E8 31CF000F */  andi  $t7, $t6, 0xf
/* 0FBE1C 7F0C72EC 000FC840 */  sll   $t9, $t7, 1
/* 0FBE20 7F0C72F0 02796021 */  addu  $t4, $s3, $t9
/* 0FBE24 7F0C72F4 85900000 */  lh    $s0, ($t4)
/* 0FBE28 7F0C72F8 10A00003 */  beqz  $a1, .L7F0C7308
/* 0FBE2C 7F0C72FC 01603025 */   move  $a2, $t3
/* 0FBE30 7F0C7300 10000002 */  b     .L7F0C730C
/* 0FBE34 7F0C7304 00001825 */   move  $v1, $zero
.L7F0C7308:
/* 0FBE38 7F0C7308 24030004 */  li    $v1, 4
.L7F0C730C:
/* 0FBE3C 7F0C730C 00D67821 */  addu  $t7, $a2, $s6
/* 0FBE40 7F0C7310 01F5C821 */  addu  $t9, $t7, $s5
/* 0FBE44 7F0C7314 932C0000 */  lbu   $t4, ($t9)
/* 0FBE48 7F0C7318 00645007 */  srav  $t2, $a0, $v1
/* 0FBE4C 7F0C731C 314B000F */  andi  $t3, $t2, 0xf
/* 0FBE50 7F0C7320 000B6840 */  sll   $t5, $t3, 1
/* 0FBE54 7F0C7324 000CC103 */  sra   $t8, $t4, 4
/* 0FBE58 7F0C7328 330A000F */  andi  $t2, $t8, 0xf
/* 0FBE5C 7F0C732C 026D7021 */  addu  $t6, $s3, $t5
/* 0FBE60 7F0C7330 000A5840 */  sll   $t3, $t2, 1
/* 0FBE64 7F0C7334 026B6821 */  addu  $t5, $s3, $t3
/* 0FBE68 7F0C7338 85C80000 */  lh    $t0, ($t6)
/* 0FBE6C 7F0C733C 10A00003 */  beqz  $a1, .L7F0C734C
/* 0FBE70 7F0C7340 85A90000 */   lh    $t1, ($t5)
/* 0FBE74 7F0C7344 10000002 */  b     .L7F0C7350
/* 0FBE78 7F0C7348 00001825 */   move  $v1, $zero
.L7F0C734C:
/* 0FBE7C 7F0C734C 24030004 */  li    $v1, 4
.L7F0C7350:
/* 0FBE80 7F0C7350 02867021 */  addu  $t6, $s4, $a2
/* 0FBE84 7F0C7354 91CF0000 */  lbu   $t7, ($t6)
/* 0FBE88 7F0C7358 00105AC3 */  sra   $t3, $s0, 0xb
/* 0FBE8C 7F0C735C 316D001F */  andi  $t5, $t3, 0x1f
/* 0FBE90 7F0C7360 006FC807 */  srav  $t9, $t7, $v1
/* 0FBE94 7F0C7364 332C000F */  andi  $t4, $t9, 0xf
/* 0FBE98 7F0C7368 000CC040 */  sll   $t8, $t4, 1
/* 0FBE9C 7F0C736C 02785021 */  addu  $t2, $s3, $t8
/* 0FBEA0 7F0C7370 85420000 */  lh    $v0, ($t2)
/* 0FBEA4 7F0C7374 000872C3 */  sra   $t6, $t0, 0xb
/* 0FBEA8 7F0C7378 31CF001F */  andi  $t7, $t6, 0x1f
/* 0FBEAC 7F0C737C 000962C3 */  sra   $t4, $t1, 0xb
/* 0FBEB0 7F0C7380 3198001F */  andi  $t8, $t4, 0x1f
/* 0FBEB4 7F0C7384 01AFC821 */  addu  $t9, $t5, $t7
/* 0FBEB8 7F0C7388 00025AC3 */  sra   $t3, $v0, 0xb
/* 0FBEBC 7F0C738C 316E001F */  andi  $t6, $t3, 0x1f
/* 0FBEC0 7F0C7390 03385021 */  addu  $t2, $t9, $t8
/* 0FBEC4 7F0C7394 014E3021 */  addu  $a2, $t2, $t6
/* 0FBEC8 7F0C7398 00106183 */  sra   $t4, $s0, 6
/* 0FBECC 7F0C739C 3199001F */  andi  $t9, $t4, 0x1f
/* 0FBED0 7F0C73A0 00066883 */  sra   $t5, $a2, 2
/* 0FBED4 7F0C73A4 0008C183 */  sra   $t8, $t0, 6
/* 0FBED8 7F0C73A8 330B001F */  andi  $t3, $t8, 0x1f
/* 0FBEDC 7F0C73AC 31A6001F */  andi  $a2, $t5, 0x1f
/* 0FBEE0 7F0C73B0 00097183 */  sra   $t6, $t1, 6
/* 0FBEE4 7F0C73B4 31CD001F */  andi  $t5, $t6, 0x1f
/* 0FBEE8 7F0C73B8 032B5021 */  addu  $t2, $t9, $t3
/* 0FBEEC 7F0C73BC 00026183 */  sra   $t4, $v0, 6
/* 0FBEF0 7F0C73C0 3198001F */  andi  $t8, $t4, 0x1f
/* 0FBEF4 7F0C73C4 014D7821 */  addu  $t7, $t2, $t5
/* 0FBEF8 7F0C73C8 01F83821 */  addu  $a3, $t7, $t8
/* 0FBEFC 7F0C73CC 00107043 */  sra   $t6, $s0, 1
/* 0FBF00 7F0C73D0 31CA001F */  andi  $t2, $t6, 0x1f
/* 0FBF04 7F0C73D4 0007C883 */  sra   $t9, $a3, 2
/* 0FBF08 7F0C73D8 00086843 */  sra   $t5, $t0, 1
/* 0FBF0C 7F0C73DC 31AC001F */  andi  $t4, $t5, 0x1f
/* 0FBF10 7F0C73E0 3327001F */  andi  $a3, $t9, 0x1f
/* 0FBF14 7F0C73E4 0009C043 */  sra   $t8, $t1, 1
/* 0FBF18 7F0C73E8 3319001F */  andi  $t9, $t8, 0x1f
/* 0FBF1C 7F0C73EC 014C7821 */  addu  $t7, $t2, $t4
/* 0FBF20 7F0C73F0 00027043 */  sra   $t6, $v0, 1
/* 0FBF24 7F0C73F4 31CD001F */  andi  $t5, $t6, 0x1f
/* 0FBF28 7F0C73F8 01F95821 */  addu  $t3, $t7, $t9
/* 0FBF2C 7F0C73FC 016D5021 */  addu  $t2, $t3, $t5
/* 0FBF30 7F0C7400 000A6083 */  sra   $t4, $t2, 2
/* 0FBF34 7F0C7404 31190001 */  andi  $t9, $t0, 1
/* 0FBF38 7F0C7408 320F0001 */  andi  $t7, $s0, 1
/* 0FBF3C 7F0C740C 01F97021 */  addu  $t6, $t7, $t9
/* 0FBF40 7F0C7410 3198001F */  andi  $t8, $t4, 0x1f
/* 0FBF44 7F0C7414 312B0001 */  andi  $t3, $t1, 1
/* 0FBF48 7F0C7418 01CB6821 */  addu  $t5, $t6, $t3
/* 0FBF4C 7F0C741C 304A0001 */  andi  $t2, $v0, 1
/* 0FBF50 7F0C7420 01AA6021 */  addu  $t4, $t5, $t2
/* 0FBF54 7F0C7424 AFB80010 */  sw    $t8, 0x10($sp)
/* 0FBF58 7F0C7428 25980002 */  addiu $t8, $t4, 2
/* 0FBF5C 7F0C742C 00187883 */  sra   $t7, $t8, 2
/* 0FBF60 7F0C7430 31F90001 */  andi  $t9, $t7, 1
/* 0FBF64 7F0C7434 AFB90014 */  sw    $t9, 0x14($sp)
/* 0FBF68 7F0C7438 02602025 */  move  $a0, $s3
/* 0FBF6C 7F0C743C 0FC31DEB */  jal   sub_GAME_7F0C77AC
/* 0FBF70 7F0C7440 02E02825 */   move  $a1, $s7
/* 0FBF74 7F0C7444 924E0000 */  lbu   $t6, ($s2)
/* 0FBF78 7F0C7448 26310004 */  addiu $s1, $s1, 4
/* 0FBF7C 7F0C744C 01C26825 */  or    $t5, $t6, $v0
/* 0FBF80 7F0C7450 A24D0000 */  sb    $t5, ($s2)
/* 0FBF84 7F0C7454 8FAA009C */  lw    $t2, 0x9c($sp)
/* 0FBF88 7F0C7458 022A082A */  slt   $at, $s1, $t2
/* 0FBF8C 7F0C745C 5420FF3B */  bnezl $at, .L7F0C714C
/* 0FBF90 7F0C7460 00112843 */   sra   $a1, $s1, 1
.L7F0C7464:
/* 0FBF94 7F0C7464 8FAE00A0 */  lw    $t6, 0xa0($sp)
/* 0FBF98 7F0C7468 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0FBF9C 7F0C746C 8FAC0074 */  lw    $t4, 0x74($sp)
/* 0FBFA0 7F0C7470 8FB8004C */  lw    $t8, 0x4c($sp)
/* 0FBFA4 7F0C7474 8FB9009C */  lw    $t9, 0x9c($sp)
/* 0FBFA8 7F0C7478 25CB0002 */  addiu $t3, $t6, 2
/* 0FBFAC 7F0C747C 016D082A */  slt   $at, $t3, $t5
/* 0FBFB0 7F0C7480 01987821 */  addu  $t7, $t4, $t8
/* 0FBFB4 7F0C7484 AFAB00A0 */  sw    $t3, 0xa0($sp)
/* 0FBFB8 7F0C7488 AFAF0074 */  sw    $t7, 0x74($sp)
/* 0FBFBC 7F0C748C 1420FF20 */  bnez  $at, .L7F0C7110
/* 0FBFC0 7F0C7490 02B9A821 */   addu  $s5, $s5, $t9
.L7F0C7494:
/* 0FBFC4 7F0C7494 8FAA0098 */  lw    $t2, 0x98($sp)
/* 0FBFC8 7F0C7498 8FB80094 */  lw    $t8, 0x94($sp)
/* 0FBFCC 7F0C749C 000A6043 */  sra   $t4, $t2, 1
/* 0FBFD0 7F0C74A0 01980019 */  multu $t4, $t8
/* 0FBFD4 7F0C74A4 00001012 */  mflo  $v0
/* 0FBFD8 7F0C74A8 100000B5 */  b     .L7F0C7780
/* 0FBFDC 7F0C74AC 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F0C74B0:
/* 0FBFE0 7F0C74B0 8FAF00B4 */  lw    $t7, 0xb4($sp)
/* 0FBFE4 7F0C74B4 8FB90098 */  lw    $t9, 0x98($sp)
/* 0FBFE8 7F0C74B8 AFA000A0 */  sw    $zero, 0xa0($sp)
/* 0FBFEC 7F0C74BC 19E000A8 */  blez  $t7, .L7F0C7760
/* 0FBFF0 7F0C74C0 00197043 */   sra   $t6, $t9, 1
/* 0FBFF4 7F0C74C4 AFAE004C */  sw    $t6, 0x4c($sp)
/* 0FBFF8 7F0C74C8 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 0FBFFC 7F0C74CC 8FB300BC */  lw    $s3, 0xbc($sp)
.L7F0C74D0:
/* 0FC000 7F0C74D0 8FAD00A0 */  lw    $t5, 0xa0($sp)
/* 0FC004 7F0C74D4 8FAB00B4 */  lw    $t3, 0xb4($sp)
/* 0FC008 7F0C74D8 00008825 */  move  $s1, $zero
/* 0FC00C 7F0C74DC 25AA0001 */  addiu $t2, $t5, 1
/* 0FC010 7F0C74E0 014B082A */  slt   $at, $t2, $t3
/* 0FC014 7F0C74E4 10200005 */  beqz  $at, .L7F0C74FC
/* 0FC018 7F0C74E8 8FB8009C */   lw    $t8, 0x9c($sp)
/* 0FC01C 7F0C74EC 8FB6009C */  lw    $s6, 0x9c($sp)
/* 0FC020 7F0C74F0 00166043 */  sra   $t4, $s6, 1
/* 0FC024 7F0C74F4 10000002 */  b     .L7F0C7500
/* 0FC028 7F0C74F8 0180B025 */   move  $s6, $t4
.L7F0C74FC:
/* 0FC02C 7F0C74FC 0000B025 */  move  $s6, $zero
.L7F0C7500:
/* 0FC030 7F0C7500 1B00008B */  blez  $t8, .L7F0C7730
/* 0FC034 7F0C7504 00112843 */   sra   $a1, $s1, 1
.L7F0C7508:
/* 0FC038 7F0C7508 00B57821 */  addu  $t7, $a1, $s5
/* 0FC03C 7F0C750C 91E20000 */  lbu   $v0, ($t7)
/* 0FC040 7F0C7510 262A0001 */  addiu $t2, $s1, 1
/* 0FC044 7F0C7514 015E202A */  slt   $a0, $t2, $fp
/* 0FC048 7F0C7518 0002C903 */  sra   $t9, $v0, 4
/* 0FC04C 7F0C751C 332E000F */  andi  $t6, $t9, 0xf
/* 0FC050 7F0C7520 000E6840 */  sll   $t5, $t6, 1
/* 0FC054 7F0C7524 026D5821 */  addu  $t3, $s3, $t5
/* 0FC058 7F0C7528 00826007 */  srav  $t4, $v0, $a0
/* 0FC05C 7F0C752C 11800003 */  beqz  $t4, .L7F0C753C
/* 0FC060 7F0C7530 85700000 */   lh    $s0, ($t3)
/* 0FC064 7F0C7534 10000002 */  b     .L7F0C7540
/* 0FC068 7F0C7538 00001825 */   move  $v1, $zero
.L7F0C753C:
/* 0FC06C 7F0C753C 24030004 */  li    $v1, 4
.L7F0C7540:
/* 0FC070 7F0C7540 00B67021 */  addu  $t6, $a1, $s6
/* 0FC074 7F0C7544 01D56821 */  addu  $t5, $t6, $s5
/* 0FC078 7F0C7548 91A20000 */  lbu   $v0, ($t5)
/* 0FC07C 7F0C754C 3078000F */  andi  $t8, $v1, 0xf
/* 0FC080 7F0C7550 00187840 */  sll   $t7, $t8, 1
/* 0FC084 7F0C7554 00025903 */  sra   $t3, $v0, 4
/* 0FC088 7F0C7558 316A000F */  andi  $t2, $t3, 0xf
/* 0FC08C 7F0C755C 026FC821 */  addu  $t9, $s3, $t7
/* 0FC090 7F0C7560 000A6040 */  sll   $t4, $t2, 1
/* 0FC094 7F0C7564 026CC021 */  addu  $t8, $s3, $t4
/* 0FC098 7F0C7568 00827807 */  srav  $t7, $v0, $a0
/* 0FC09C 7F0C756C 87280000 */  lh    $t0, ($t9)
/* 0FC0A0 7F0C7570 11E00003 */  beqz  $t7, .L7F0C7580
/* 0FC0A4 7F0C7574 87090000 */   lh    $t1, ($t8)
/* 0FC0A8 7F0C7578 10000002 */  b     .L7F0C7584
/* 0FC0AC 7F0C757C 00001825 */   move  $v1, $zero
.L7F0C7580:
/* 0FC0B0 7F0C7580 24030004 */  li    $v1, 4
.L7F0C7584:
/* 0FC0B4 7F0C7584 3079000F */  andi  $t9, $v1, 0xf
/* 0FC0B8 7F0C7588 00197040 */  sll   $t6, $t9, 1
/* 0FC0BC 7F0C758C 026E6821 */  addu  $t5, $s3, $t6
/* 0FC0C0 7F0C7590 85A20000 */  lh    $v0, ($t5)
/* 0FC0C4 7F0C7594 00105A03 */  sra   $t3, $s0, 8
/* 0FC0C8 7F0C7598 00086203 */  sra   $t4, $t0, 8
/* 0FC0CC 7F0C759C 319800FF */  andi  $t8, $t4, 0xff
/* 0FC0D0 7F0C75A0 316A00FF */  andi  $t2, $t3, 0xff
/* 0FC0D4 7F0C75A4 0009CA03 */  sra   $t9, $t1, 8
/* 0FC0D8 7F0C75A8 332E00FF */  andi  $t6, $t9, 0xff
/* 0FC0DC 7F0C75AC 01587821 */  addu  $t7, $t2, $t8
/* 0FC0E0 7F0C75B0 01EE6821 */  addu  $t5, $t7, $t6
/* 0FC0E4 7F0C75B4 00025A03 */  sra   $t3, $v0, 8
/* 0FC0E8 7F0C75B8 316C00FF */  andi  $t4, $t3, 0xff
/* 0FC0EC 7F0C75BC 01AC3021 */  addu  $a2, $t5, $t4
/* 0FC0F0 7F0C75C0 310F00FF */  andi  $t7, $t0, 0xff
/* 0FC0F4 7F0C75C4 321900FF */  andi  $t9, $s0, 0xff
/* 0FC0F8 7F0C75C8 032F7021 */  addu  $t6, $t9, $t7
/* 0FC0FC 7F0C75CC 312B00FF */  andi  $t3, $t1, 0xff
/* 0FC100 7F0C75D0 01CB6821 */  addu  $t5, $t6, $t3
/* 0FC104 7F0C75D4 304C00FF */  andi  $t4, $v0, 0xff
/* 0FC108 7F0C75D8 01AC3821 */  addu  $a3, $t5, $t4
/* 0FC10C 7F0C75DC 00065083 */  sra   $t2, $a2, 2
/* 0FC110 7F0C75E0 314600FF */  andi  $a2, $t2, 0xff
/* 0FC114 7F0C75E4 24E70001 */  addiu $a3, $a3, 1
/* 0FC118 7F0C75E8 00075083 */  sra   $t2, $a3, 2
/* 0FC11C 7F0C75EC 314700FF */  andi  $a3, $t2, 0xff
/* 0FC120 7F0C75F0 02602025 */  move  $a0, $s3
/* 0FC124 7F0C75F4 0FC31EF6 */  jal   sub_GAME_7F0C7BD8
/* 0FC128 7F0C75F8 02E02825 */   move  $a1, $s7
/* 0FC12C 7F0C75FC 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FC130 7F0C7600 00117883 */  sra   $t7, $s1, 2
/* 0FC134 7F0C7604 26260002 */  addiu $a2, $s1, 2
/* 0FC138 7F0C7608 00025900 */  sll   $t3, $v0, 4
/* 0FC13C 7F0C760C 00066843 */  sra   $t5, $a2, 1
/* 0FC140 7F0C7610 032F9021 */  addu  $s2, $t9, $t7
/* 0FC144 7F0C7614 A24B0000 */  sb    $t3, ($s2)
/* 0FC148 7F0C7618 01B56021 */  addu  $t4, $t5, $s5
/* 0FC14C 7F0C761C 91840000 */  lbu   $a0, ($t4)
/* 0FC150 7F0C7620 262E0003 */  addiu $t6, $s1, 3
/* 0FC154 7F0C7624 01DE282A */  slt   $a1, $t6, $fp
/* 0FC158 7F0C7628 00045103 */  sra   $t2, $a0, 4
/* 0FC15C 7F0C762C 3158000F */  andi  $t8, $t2, 0xf
/* 0FC160 7F0C7630 0018C840 */  sll   $t9, $t8, 1
/* 0FC164 7F0C7634 02797821 */  addu  $t7, $s3, $t9
/* 0FC168 7F0C7638 00A45807 */  srav  $t3, $a0, $a1
/* 0FC16C 7F0C763C 85F00000 */  lh    $s0, ($t7)
/* 0FC170 7F0C7640 11600003 */  beqz  $t3, .L7F0C7650
/* 0FC174 7F0C7644 01A03025 */   move  $a2, $t5
/* 0FC178 7F0C7648 10000002 */  b     .L7F0C7654
/* 0FC17C 7F0C764C 00001825 */   move  $v1, $zero
.L7F0C7650:
/* 0FC180 7F0C7650 24030004 */  li    $v1, 4
.L7F0C7654:
/* 0FC184 7F0C7654 00D6C021 */  addu  $t8, $a2, $s6
/* 0FC188 7F0C7658 0315C821 */  addu  $t9, $t8, $s5
/* 0FC18C 7F0C765C 93220000 */  lbu   $v0, ($t9)
/* 0FC190 7F0C7660 306D000F */  andi  $t5, $v1, 0xf
/* 0FC194 7F0C7664 000D6040 */  sll   $t4, $t5, 1
/* 0FC198 7F0C7668 00027903 */  sra   $t7, $v0, 4
/* 0FC19C 7F0C766C 31EE000F */  andi  $t6, $t7, 0xf
/* 0FC1A0 7F0C7670 026C5021 */  addu  $t2, $s3, $t4
/* 0FC1A4 7F0C7674 000E5840 */  sll   $t3, $t6, 1
/* 0FC1A8 7F0C7678 026B6821 */  addu  $t5, $s3, $t3
/* 0FC1AC 7F0C767C 00A26007 */  srav  $t4, $v0, $a1
/* 0FC1B0 7F0C7680 85480000 */  lh    $t0, ($t2)
/* 0FC1B4 7F0C7684 11800003 */  beqz  $t4, .L7F0C7694
/* 0FC1B8 7F0C7688 85A90000 */   lh    $t1, ($t5)
/* 0FC1BC 7F0C768C 10000002 */  b     .L7F0C7698
/* 0FC1C0 7F0C7690 00001825 */   move  $v1, $zero
.L7F0C7694:
/* 0FC1C4 7F0C7694 24030004 */  li    $v1, 4
.L7F0C7698:
/* 0FC1C8 7F0C7698 306A000F */  andi  $t2, $v1, 0xf
/* 0FC1CC 7F0C769C 000AC040 */  sll   $t8, $t2, 1
/* 0FC1D0 7F0C76A0 0278C821 */  addu  $t9, $s3, $t8
/* 0FC1D4 7F0C76A4 87220000 */  lh    $v0, ($t9)
/* 0FC1D8 7F0C76A8 00107A03 */  sra   $t7, $s0, 8
/* 0FC1DC 7F0C76AC 00085A03 */  sra   $t3, $t0, 8
/* 0FC1E0 7F0C76B0 316D00FF */  andi  $t5, $t3, 0xff
/* 0FC1E4 7F0C76B4 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FC1E8 7F0C76B8 00095203 */  sra   $t2, $t1, 8
/* 0FC1EC 7F0C76BC 315800FF */  andi  $t8, $t2, 0xff
/* 0FC1F0 7F0C76C0 01CD6021 */  addu  $t4, $t6, $t5
/* 0FC1F4 7F0C76C4 0198C821 */  addu  $t9, $t4, $t8
/* 0FC1F8 7F0C76C8 00027A03 */  sra   $t7, $v0, 8
/* 0FC1FC 7F0C76CC 31EB00FF */  andi  $t3, $t7, 0xff
/* 0FC200 7F0C76D0 032B3021 */  addu  $a2, $t9, $t3
/* 0FC204 7F0C76D4 310C00FF */  andi  $t4, $t0, 0xff
/* 0FC208 7F0C76D8 320A00FF */  andi  $t2, $s0, 0xff
/* 0FC20C 7F0C76DC 014CC021 */  addu  $t8, $t2, $t4
/* 0FC210 7F0C76E0 312F00FF */  andi  $t7, $t1, 0xff
/* 0FC214 7F0C76E4 030FC821 */  addu  $t9, $t8, $t7
/* 0FC218 7F0C76E8 304B00FF */  andi  $t3, $v0, 0xff
/* 0FC21C 7F0C76EC 032B3821 */  addu  $a3, $t9, $t3
/* 0FC220 7F0C76F0 00067083 */  sra   $t6, $a2, 2
/* 0FC224 7F0C76F4 31C600FF */  andi  $a2, $t6, 0xff
/* 0FC228 7F0C76F8 24E70001 */  addiu $a3, $a3, 1
/* 0FC22C 7F0C76FC 00077083 */  sra   $t6, $a3, 2
/* 0FC230 7F0C7700 31C700FF */  andi  $a3, $t6, 0xff
/* 0FC234 7F0C7704 02602025 */  move  $a0, $s3
/* 0FC238 7F0C7708 0FC31EF6 */  jal   sub_GAME_7F0C7BD8
/* 0FC23C 7F0C770C 02E02825 */   move  $a1, $s7
/* 0FC240 7F0C7710 924A0000 */  lbu   $t2, ($s2)
/* 0FC244 7F0C7714 26310004 */  addiu $s1, $s1, 4
/* 0FC248 7F0C7718 0142C025 */  or    $t8, $t2, $v0
/* 0FC24C 7F0C771C A2580000 */  sb    $t8, ($s2)
/* 0FC250 7F0C7720 8FAF009C */  lw    $t7, 0x9c($sp)
/* 0FC254 7F0C7724 022F082A */  slt   $at, $s1, $t7
/* 0FC258 7F0C7728 5420FF77 */  bnezl $at, .L7F0C7508
/* 0FC25C 7F0C772C 00112843 */   sra   $a1, $s1, 1
.L7F0C7730:
/* 0FC260 7F0C7730 8FAA00A0 */  lw    $t2, 0xa0($sp)
/* 0FC264 7F0C7734 8FB800B4 */  lw    $t8, 0xb4($sp)
/* 0FC268 7F0C7738 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FC26C 7F0C773C 8FAB004C */  lw    $t3, 0x4c($sp)
/* 0FC270 7F0C7740 8FAD009C */  lw    $t5, 0x9c($sp)
/* 0FC274 7F0C7744 254C0002 */  addiu $t4, $t2, 2
/* 0FC278 7F0C7748 0198082A */  slt   $at, $t4, $t8
/* 0FC27C 7F0C774C 032B7021 */  addu  $t6, $t9, $t3
/* 0FC280 7F0C7750 AFAC00A0 */  sw    $t4, 0xa0($sp)
/* 0FC284 7F0C7754 AFAE0074 */  sw    $t6, 0x74($sp)
/* 0FC288 7F0C7758 1420FF5D */  bnez  $at, .L7F0C74D0
/* 0FC28C 7F0C775C 02ADA821 */   addu  $s5, $s5, $t5
.L7F0C7760:
/* 0FC290 7F0C7760 8FAF0098 */  lw    $t7, 0x98($sp)
/* 0FC294 7F0C7764 8FAB0094 */  lw    $t3, 0x94($sp)
/* 0FC298 7F0C7768 000FC843 */  sra   $t9, $t7, 1
/* 0FC29C 7F0C776C 032B0019 */  multu $t9, $t3
/* 0FC2A0 7F0C7770 00001012 */  mflo  $v0
/* 0FC2A4 7F0C7774 10000002 */  b     .L7F0C7780
/* 0FC2A8 7F0C7778 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F0C777C:
/* 0FC2AC 7F0C777C 8FBF0044 */  lw    $ra, 0x44($sp)
.L7F0C7780:
/* 0FC2B0 7F0C7780 8FB00020 */  lw    $s0, 0x20($sp)
/* 0FC2B4 7F0C7784 8FB10024 */  lw    $s1, 0x24($sp)
/* 0FC2B8 7F0C7788 8FB20028 */  lw    $s2, 0x28($sp)
/* 0FC2BC 7F0C778C 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0FC2C0 7F0C7790 8FB40030 */  lw    $s4, 0x30($sp)
/* 0FC2C4 7F0C7794 8FB50034 */  lw    $s5, 0x34($sp)
/* 0FC2C8 7F0C7798 8FB60038 */  lw    $s6, 0x38($sp)
/* 0FC2CC 7F0C779C 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0FC2D0 7F0C77A0 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0FC2D4 7F0C77A4 03E00008 */  jr    $ra
/* 0FC2D8 7F0C77A8 27BD00A8 */   addiu $sp, $sp, 0xa8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C77AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C77AC
/* 0FC2DC 7F0C77AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FC2E0 7F0C77B0 AFB2000C */  sw    $s2, 0xc($sp)
/* 0FC2E4 7F0C77B4 AFB10008 */  sw    $s1, 8($sp)
/* 0FC2E8 7F0C77B8 AFB00004 */  sw    $s0, 4($sp)
/* 0FC2EC 7F0C77BC 00C08025 */  move  $s0, $a2
/* 0FC2F0 7F0C77C0 00E08825 */  move  $s1, $a3
/* 0FC2F4 7F0C77C4 00809025 */  move  $s2, $a0
/* 0FC2F8 7F0C77C8 AFB40014 */  sw    $s4, 0x14($sp)
/* 0FC2FC 7F0C77CC AFB30010 */  sw    $s3, 0x10($sp)
/* 0FC300 7F0C77D0 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0FC304 7F0C77D4 18A0003F */  blez  $a1, .L7F0C78D4
/* 0FC308 7F0C77D8 00001825 */   move  $v1, $zero
/* 0FC30C 7F0C77DC 30A60003 */  andi  $a2, $a1, 3
/* 0FC310 7F0C77E0 10C00018 */  beqz  $a2, .L7F0C7844
/* 0FC314 7F0C77E4 8FA90028 */   lw    $t1, 0x28($sp)
/* 0FC318 7F0C77E8 00007840 */  sll   $t7, $zero, 1
/* 0FC31C 7F0C77EC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC320 7F0C77F0 024F1021 */  addu  $v0, $s2, $t7
/* 0FC324 7F0C77F4 0010C2C0 */  sll   $t8, $s0, 0xb
/* 0FC328 7F0C77F8 0007C980 */  sll   $t9, $a3, 6
/* 0FC32C 7F0C77FC 03197025 */  or    $t6, $t8, $t9
/* 0FC330 7F0C7800 00097840 */  sll   $t7, $t1, 1
/* 0FC334 7F0C7804 01CFC025 */  or    $t8, $t6, $t7
/* 0FC338 7F0C7808 030A2825 */  or    $a1, $t8, $t2
/* 0FC33C 7F0C780C 30B9FFFF */  andi  $t9, $a1, 0xffff
/* 0FC340 7F0C7810 03202825 */  move  $a1, $t9
/* 0FC344 7F0C7814 00C02025 */  move  $a0, $a2
.L7F0C7818:
/* 0FC348 7F0C7818 944E0000 */  lhu   $t6, ($v0)
/* 0FC34C 7F0C781C 54AE0004 */  bnel  $a1, $t6, .L7F0C7830
/* 0FC350 7F0C7820 24630001 */   addiu $v1, $v1, 1
/* 0FC354 7F0C7824 100000E5 */  b     .L7F0C7BBC
/* 0FC358 7F0C7828 00601025 */   move  $v0, $v1
/* 0FC35C 7F0C782C 24630001 */  addiu $v1, $v1, 1
.L7F0C7830:
/* 0FC360 7F0C7830 1483FFF9 */  bne   $a0, $v1, .L7F0C7818
/* 0FC364 7F0C7834 24420002 */   addiu $v0, $v0, 2
/* 0FC368 7F0C7838 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0FC36C 7F0C783C 506F0026 */  beql  $v1, $t7, .L7F0C78D8
/* 0FC370 7F0C7840 8FA6001C */   lw    $a2, 0x1c($sp)
.L7F0C7844:
/* 0FC374 7F0C7844 8FA90028 */  lw    $t1, 0x28($sp)
/* 0FC378 7F0C7848 0003C040 */  sll   $t8, $v1, 1
/* 0FC37C 7F0C784C 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC380 7F0C7850 02581021 */  addu  $v0, $s2, $t8
/* 0FC384 7F0C7854 0010CAC0 */  sll   $t9, $s0, 0xb
/* 0FC388 7F0C7858 00117180 */  sll   $t6, $s1, 6
/* 0FC38C 7F0C785C 032E7825 */  or    $t7, $t9, $t6
/* 0FC390 7F0C7860 0009C040 */  sll   $t8, $t1, 1
/* 0FC394 7F0C7864 01F8C825 */  or    $t9, $t7, $t8
/* 0FC398 7F0C7868 032A2825 */  or    $a1, $t9, $t2
/* 0FC39C 7F0C786C 30AEFFFF */  andi  $t6, $a1, 0xffff
/* 0FC3A0 7F0C7870 01C02825 */  move  $a1, $t6
.L7F0C7874:
/* 0FC3A4 7F0C7874 944F0000 */  lhu   $t7, ($v0)
/* 0FC3A8 7F0C7878 54AF0004 */  bnel  $a1, $t7, .L7F0C788C
/* 0FC3AC 7F0C787C 94580002 */   lhu   $t8, 2($v0)
/* 0FC3B0 7F0C7880 100000CE */  b     .L7F0C7BBC
/* 0FC3B4 7F0C7884 00601025 */   move  $v0, $v1
/* 0FC3B8 7F0C7888 94580002 */  lhu   $t8, 2($v0)
.L7F0C788C:
/* 0FC3BC 7F0C788C 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0FC3C0 7F0C7890 54B80004 */  bnel  $a1, $t8, .L7F0C78A4
/* 0FC3C4 7F0C7894 94590004 */   lhu   $t9, 4($v0)
/* 0FC3C8 7F0C7898 100000C8 */  b     .L7F0C7BBC
/* 0FC3CC 7F0C789C 24620001 */   addiu $v0, $v1, 1
/* 0FC3D0 7F0C78A0 94590004 */  lhu   $t9, 4($v0)
.L7F0C78A4:
/* 0FC3D4 7F0C78A4 54B90004 */  bnel  $a1, $t9, .L7F0C78B8
/* 0FC3D8 7F0C78A8 944E0006 */   lhu   $t6, 6($v0)
/* 0FC3DC 7F0C78AC 100000C3 */  b     .L7F0C7BBC
/* 0FC3E0 7F0C78B0 24620002 */   addiu $v0, $v1, 2
/* 0FC3E4 7F0C78B4 944E0006 */  lhu   $t6, 6($v0)
.L7F0C78B8:
/* 0FC3E8 7F0C78B8 54AE0004 */  bnel  $a1, $t6, .L7F0C78CC
/* 0FC3EC 7F0C78BC 24630004 */   addiu $v1, $v1, 4
/* 0FC3F0 7F0C78C0 100000BE */  b     .L7F0C7BBC
/* 0FC3F4 7F0C78C4 24620003 */   addiu $v0, $v1, 3
/* 0FC3F8 7F0C78C8 24630004 */  addiu $v1, $v1, 4
.L7F0C78CC:
/* 0FC3FC 7F0C78CC 146FFFE9 */  bne   $v1, $t7, .L7F0C7874
/* 0FC400 7F0C78D0 24420008 */   addiu $v0, $v0, 8
.L7F0C78D4:
/* 0FC404 7F0C78D4 8FA6001C */  lw    $a2, 0x1c($sp)
.L7F0C78D8:
/* 0FC408 7F0C78D8 8FA90028 */  lw    $t1, 0x28($sp)
/* 0FC40C 7F0C78DC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0FC410 7F0C78E0 24C6FFFF */  addiu $a2, $a2, -1
/* 0FC414 7F0C78E4 28C10002 */  slti  $at, $a2, 2
/* 0FC418 7F0C78E8 00002825 */  move  $a1, $zero
/* 0FC41C 7F0C78EC 1420003A */  bnez  $at, .L7F0C79D8
/* 0FC420 7F0C78F0 00C03825 */   move  $a3, $a2
/* 0FC424 7F0C78F4 02100019 */  multu $s0, $s0
/* 0FC428 7F0C78F8 0000C012 */  mflo  $t8
/* 0FC42C 7F0C78FC 00000000 */  nop   
/* 0FC430 7F0C7900 00000000 */  nop   
/* 0FC434 7F0C7904 02310019 */  multu $s1, $s1
/* 0FC438 7F0C7908 0000C812 */  mflo  $t9
/* 0FC43C 7F0C790C 03197021 */  addu  $t6, $t8, $t9
/* 0FC440 7F0C7910 000AC900 */  sll   $t9, $t2, 4
/* 0FC444 7F0C7914 01290019 */  multu $t1, $t1
/* 0FC448 7F0C7918 032AC823 */  subu  $t9, $t9, $t2
/* 0FC44C 7F0C791C 0019C980 */  sll   $t9, $t9, 6
/* 0FC450 7F0C7920 032AC821 */  addu  $t9, $t9, $t2
/* 0FC454 7F0C7924 00007812 */  mflo  $t7
/* 0FC458 7F0C7928 01CFC021 */  addu  $t8, $t6, $t7
/* 0FC45C 7F0C792C 03194021 */  addu  $t0, $t8, $t9
/* 0FC460 7F0C7930 00E55821 */  addu  $t3, $a3, $a1
.L7F0C7934:
/* 0FC464 7F0C7934 000B2043 */  sra   $a0, $t3, 1
/* 0FC468 7F0C7938 00047840 */  sll   $t7, $a0, 1
/* 0FC46C 7F0C793C 024FC021 */  addu  $t8, $s2, $t7
/* 0FC470 7F0C7940 97030000 */  lhu   $v1, ($t8)
/* 0FC474 7F0C7944 000362C3 */  sra   $t4, $v1, 0xb
/* 0FC478 7F0C7948 3199001F */  andi  $t9, $t4, 0x1f
/* 0FC47C 7F0C794C 03390019 */  multu $t9, $t9
/* 0FC480 7F0C7950 00036983 */  sra   $t5, $v1, 6
/* 0FC484 7F0C7954 31AE001F */  andi  $t6, $t5, 0x1f
/* 0FC488 7F0C7958 00039843 */  sra   $s3, $v1, 1
/* 0FC48C 7F0C795C 326F001F */  andi  $t7, $s3, 0x1f
/* 0FC490 7F0C7960 0000C012 */  mflo  $t8
/* 0FC494 7F0C7964 00000000 */  nop   
/* 0FC498 7F0C7968 00000000 */  nop   
/* 0FC49C 7F0C796C 01CE0019 */  multu $t6, $t6
/* 0FC4A0 7F0C7970 0000C812 */  mflo  $t9
/* 0FC4A4 7F0C7974 03197021 */  addu  $t6, $t8, $t9
/* 0FC4A8 7F0C7978 30790001 */  andi  $t9, $v1, 1
/* 0FC4AC 7F0C797C 01EF0019 */  multu $t7, $t7
/* 0FC4B0 7F0C7980 00007812 */  mflo  $t7
/* 0FC4B4 7F0C7984 01CFC021 */  addu  $t8, $t6, $t7
/* 0FC4B8 7F0C7988 00197100 */  sll   $t6, $t9, 4
/* 0FC4BC 7F0C798C 01D97023 */  subu  $t6, $t6, $t9
/* 0FC4C0 7F0C7990 000E7180 */  sll   $t6, $t6, 6
/* 0FC4C4 7F0C7994 01D97021 */  addu  $t6, $t6, $t9
/* 0FC4C8 7F0C7998 030EA021 */  addu  $s4, $t8, $t6
/* 0FC4CC 7F0C799C 0288082A */  slt   $at, $s4, $t0
/* 0FC4D0 7F0C79A0 50200004 */  beql  $at, $zero, .L7F0C79B4
/* 0FC4D4 7F0C79A4 0114082A */   slt   $at, $t0, $s4
/* 0FC4D8 7F0C79A8 10000007 */  b     .L7F0C79C8
/* 0FC4DC 7F0C79AC 00802825 */   move  $a1, $a0
/* 0FC4E0 7F0C79B0 0114082A */  slt   $at, $t0, $s4
.L7F0C79B4:
/* 0FC4E4 7F0C79B4 10200003 */  beqz  $at, .L7F0C79C4
/* 0FC4E8 7F0C79B8 00803825 */   move  $a3, $a0
/* 0FC4EC 7F0C79BC 10000002 */  b     .L7F0C79C8
/* 0FC4F0 7F0C79C0 00803825 */   move  $a3, $a0
.L7F0C79C4:
/* 0FC4F4 7F0C79C4 00802825 */  move  $a1, $a0
.L7F0C79C8:
/* 0FC4F8 7F0C79C8 00E57823 */  subu  $t7, $a3, $a1
/* 0FC4FC 7F0C79CC 29E10002 */  slti  $at, $t7, 2
/* 0FC500 7F0C79D0 5020FFD8 */  beql  $at, $zero, .L7F0C7934
/* 0FC504 7F0C79D4 00E55821 */   addu  $t3, $a3, $a1
.L7F0C79D8:
/* 0FC508 7F0C79D8 24E5FFFC */  addiu $a1, $a3, -4
/* 0FC50C 7F0C79DC 04A10002 */  bgez  $a1, .L7F0C79E8
/* 0FC510 7F0C79E0 8FB9001C */   lw    $t9, 0x1c($sp)
/* 0FC514 7F0C79E4 00002825 */  move  $a1, $zero
.L7F0C79E8:
/* 0FC518 7F0C79E8 24E70004 */  addiu $a3, $a3, 4
/* 0FC51C 7F0C79EC 00F9082A */  slt   $at, $a3, $t9
/* 0FC520 7F0C79F0 14200002 */  bnez  $at, .L7F0C79FC
/* 0FC524 7F0C79F4 3C14000F */   lui   $s4, (0x000F423F >> 16) # lui $s4, 0xf
/* 0FC528 7F0C79F8 00C03825 */  move  $a3, $a2
.L7F0C79FC:
/* 0FC52C 7F0C79FC 3694423F */  ori   $s4, (0x000F423F & 0xFFFF) # ori $s4, $s4, 0x423f
/* 0FC530 7F0C7A00 00E5082A */  slt   $at, $a3, $a1
/* 0FC534 7F0C7A04 00004025 */  move  $t0, $zero
/* 0FC538 7F0C7A08 02803025 */  move  $a2, $s4
/* 0FC53C 7F0C7A0C 1420006A */  bnez  $at, .L7F0C7BB8
/* 0FC540 7F0C7A10 00A02025 */   move  $a0, $a1
/* 0FC544 7F0C7A14 00E51023 */  subu  $v0, $a3, $a1
/* 0FC548 7F0C7A18 24420001 */  addiu $v0, $v0, 1
/* 0FC54C 7F0C7A1C 30580001 */  andi  $t8, $v0, 1
/* 0FC550 7F0C7A20 13000023 */  beqz  $t8, .L7F0C7AB0
/* 0FC554 7F0C7A24 00057040 */   sll   $t6, $a1, 1
/* 0FC558 7F0C7A28 024E7821 */  addu  $t7, $s2, $t6
/* 0FC55C 7F0C7A2C 95E20000 */  lhu   $v0, ($t7)
/* 0FC560 7F0C7A30 24A40001 */  addiu $a0, $a1, 1
/* 0FC564 7F0C7A34 240303C1 */  li    $v1, 961
/* 0FC568 7F0C7A38 30590001 */  andi  $t9, $v0, 1
/* 0FC56C 7F0C7A3C 15590003 */  bne   $t2, $t9, .L7F0C7A4C
/* 0FC570 7F0C7A40 0002C2C3 */   sra   $t8, $v0, 0xb
/* 0FC574 7F0C7A44 10000001 */  b     .L7F0C7A4C
/* 0FC578 7F0C7A48 00001825 */   move  $v1, $zero
.L7F0C7A4C:
/* 0FC57C 7F0C7A4C 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC580 7F0C7A50 01D05823 */  subu  $t3, $t6, $s0
/* 0FC584 7F0C7A54 016B0019 */  multu $t3, $t3
/* 0FC588 7F0C7A58 00027983 */  sra   $t7, $v0, 6
/* 0FC58C 7F0C7A5C 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC590 7F0C7A60 03316023 */  subu  $t4, $t9, $s1
/* 0FC594 7F0C7A64 0002C043 */  sra   $t8, $v0, 1
/* 0FC598 7F0C7A68 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC59C 7F0C7A6C 01C96823 */  subu  $t5, $t6, $t1
/* 0FC5A0 7F0C7A70 00007812 */  mflo  $t7
/* 0FC5A4 7F0C7A74 006FC821 */  addu  $t9, $v1, $t7
/* 0FC5A8 7F0C7A78 00000000 */  nop   
/* 0FC5AC 7F0C7A7C 018C0019 */  multu $t4, $t4
/* 0FC5B0 7F0C7A80 0000C012 */  mflo  $t8
/* 0FC5B4 7F0C7A84 03387021 */  addu  $t6, $t9, $t8
/* 0FC5B8 7F0C7A88 24F90001 */  addiu $t9, $a3, 1
/* 0FC5BC 7F0C7A8C 01AD0019 */  multu $t5, $t5
/* 0FC5C0 7F0C7A90 00007812 */  mflo  $t7
/* 0FC5C4 7F0C7A94 01CF9821 */  addu  $s3, $t6, $t7
/* 0FC5C8 7F0C7A98 0274082A */  slt   $at, $s3, $s4
/* 0FC5CC 7F0C7A9C 10200003 */  beqz  $at, .L7F0C7AAC
/* 0FC5D0 7F0C7AA0 00000000 */   nop   
/* 0FC5D4 7F0C7AA4 00A04025 */  move  $t0, $a1
/* 0FC5D8 7F0C7AA8 02603025 */  move  $a2, $s3
.L7F0C7AAC:
/* 0FC5DC 7F0C7AAC 13240042 */  beq   $t9, $a0, .L7F0C7BB8
.L7F0C7AB0:
/* 0FC5E0 7F0C7AB0 0004C040 */   sll   $t8, $a0, 1
/* 0FC5E4 7F0C7AB4 02582821 */  addu  $a1, $s2, $t8
.L7F0C7AB8:
/* 0FC5E8 7F0C7AB8 94A20000 */  lhu   $v0, ($a1)
/* 0FC5EC 7F0C7ABC 240303C1 */  li    $v1, 961
/* 0FC5F0 7F0C7AC0 304E0001 */  andi  $t6, $v0, 1
/* 0FC5F4 7F0C7AC4 154E0003 */  bne   $t2, $t6, .L7F0C7AD4
/* 0FC5F8 7F0C7AC8 00027AC3 */   sra   $t7, $v0, 0xb
/* 0FC5FC 7F0C7ACC 10000001 */  b     .L7F0C7AD4
/* 0FC600 7F0C7AD0 00001825 */   move  $v1, $zero
.L7F0C7AD4:
/* 0FC604 7F0C7AD4 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC608 7F0C7AD8 03306023 */  subu  $t4, $t9, $s0
/* 0FC60C 7F0C7ADC 018C0019 */  multu $t4, $t4
/* 0FC610 7F0C7AE0 0002C183 */  sra   $t8, $v0, 6
/* 0FC614 7F0C7AE4 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC618 7F0C7AE8 01D16823 */  subu  $t5, $t6, $s1
/* 0FC61C 7F0C7AEC 00027843 */  sra   $t7, $v0, 1
/* 0FC620 7F0C7AF0 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC624 7F0C7AF4 03299023 */  subu  $s2, $t9, $t1
/* 0FC628 7F0C7AF8 0000C012 */  mflo  $t8
/* 0FC62C 7F0C7AFC 00787021 */  addu  $t6, $v1, $t8
/* 0FC630 7F0C7B00 240303C1 */  li    $v1, 961
/* 0FC634 7F0C7B04 01AD0019 */  multu $t5, $t5
/* 0FC638 7F0C7B08 00007812 */  mflo  $t7
/* 0FC63C 7F0C7B0C 01CFC821 */  addu  $t9, $t6, $t7
/* 0FC640 7F0C7B10 00000000 */  nop   
/* 0FC644 7F0C7B14 02520019 */  multu $s2, $s2
/* 0FC648 7F0C7B18 0000C012 */  mflo  $t8
/* 0FC64C 7F0C7B1C 03389821 */  addu  $s3, $t9, $t8
/* 0FC650 7F0C7B20 0266082A */  slt   $at, $s3, $a2
/* 0FC654 7F0C7B24 50200004 */  beql  $at, $zero, .L7F0C7B38
/* 0FC658 7F0C7B28 94A20002 */   lhu   $v0, 2($a1)
/* 0FC65C 7F0C7B2C 00804025 */  move  $t0, $a0
/* 0FC660 7F0C7B30 02603025 */  move  $a2, $s3
/* 0FC664 7F0C7B34 94A20002 */  lhu   $v0, 2($a1)
.L7F0C7B38:
/* 0FC668 7F0C7B38 304E0001 */  andi  $t6, $v0, 1
/* 0FC66C 7F0C7B3C 154E0003 */  bne   $t2, $t6, .L7F0C7B4C
/* 0FC670 7F0C7B40 00027AC3 */   sra   $t7, $v0, 0xb
/* 0FC674 7F0C7B44 10000001 */  b     .L7F0C7B4C
/* 0FC678 7F0C7B48 00001825 */   move  $v1, $zero
.L7F0C7B4C:
/* 0FC67C 7F0C7B4C 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC680 7F0C7B50 03305823 */  subu  $t3, $t9, $s0
/* 0FC684 7F0C7B54 016B0019 */  multu $t3, $t3
/* 0FC688 7F0C7B58 0002C183 */  sra   $t8, $v0, 6
/* 0FC68C 7F0C7B5C 330E001F */  andi  $t6, $t8, 0x1f
/* 0FC690 7F0C7B60 01D16023 */  subu  $t4, $t6, $s1
/* 0FC694 7F0C7B64 00027843 */  sra   $t7, $v0, 1
/* 0FC698 7F0C7B68 31F9001F */  andi  $t9, $t7, 0x1f
/* 0FC69C 7F0C7B6C 03296823 */  subu  $t5, $t9, $t1
/* 0FC6A0 7F0C7B70 0000C012 */  mflo  $t8
/* 0FC6A4 7F0C7B74 00787021 */  addu  $t6, $v1, $t8
/* 0FC6A8 7F0C7B78 00000000 */  nop   
/* 0FC6AC 7F0C7B7C 018C0019 */  multu $t4, $t4
/* 0FC6B0 7F0C7B80 00007812 */  mflo  $t7
/* 0FC6B4 7F0C7B84 01CFC821 */  addu  $t9, $t6, $t7
/* 0FC6B8 7F0C7B88 24EE0001 */  addiu $t6, $a3, 1
/* 0FC6BC 7F0C7B8C 01AD0019 */  multu $t5, $t5
/* 0FC6C0 7F0C7B90 0000C012 */  mflo  $t8
/* 0FC6C4 7F0C7B94 03389021 */  addu  $s2, $t9, $t8
/* 0FC6C8 7F0C7B98 0246082A */  slt   $at, $s2, $a2
/* 0FC6CC 7F0C7B9C 50200004 */  beql  $at, $zero, .L7F0C7BB0
/* 0FC6D0 7F0C7BA0 24840002 */   addiu $a0, $a0, 2
/* 0FC6D4 7F0C7BA4 24880001 */  addiu $t0, $a0, 1
/* 0FC6D8 7F0C7BA8 02403025 */  move  $a2, $s2
/* 0FC6DC 7F0C7BAC 24840002 */  addiu $a0, $a0, 2
.L7F0C7BB0:
/* 0FC6E0 7F0C7BB0 15C4FFC1 */  bne   $t6, $a0, .L7F0C7AB8
/* 0FC6E4 7F0C7BB4 24A50004 */   addiu $a1, $a1, 4
.L7F0C7BB8:
/* 0FC6E8 7F0C7BB8 01001025 */  move  $v0, $t0
.L7F0C7BBC:
/* 0FC6EC 7F0C7BBC 8FB00004 */  lw    $s0, 4($sp)
/* 0FC6F0 7F0C7BC0 8FB10008 */  lw    $s1, 8($sp)
/* 0FC6F4 7F0C7BC4 8FB2000C */  lw    $s2, 0xc($sp)
/* 0FC6F8 7F0C7BC8 8FB30010 */  lw    $s3, 0x10($sp)
/* 0FC6FC 7F0C7BCC 8FB40014 */  lw    $s4, 0x14($sp)
/* 0FC700 7F0C7BD0 03E00008 */  jr    $ra
/* 0FC704 7F0C7BD4 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C7BD8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C7BD8
/* 0FC708 7F0C7BD8 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 0FC70C 7F0C7BDC AFB1000C */  sw    $s1, 0xc($sp)
/* 0FC710 7F0C7BE0 AFB00008 */  sw    $s0, 8($sp)
/* 0FC714 7F0C7BE4 18A00030 */  blez  $a1, .L7F0C7CA8
/* 0FC718 7F0C7BE8 00001825 */   move  $v1, $zero
/* 0FC71C 7F0C7BEC 30AA0003 */  andi  $t2, $a1, 3
/* 0FC720 7F0C7BF0 11400010 */  beqz  $t2, .L7F0C7C34
/* 0FC724 7F0C7BF4 01404025 */   move  $t0, $t2
/* 0FC728 7F0C7BF8 00067A00 */  sll   $t7, $a2, 8
/* 0FC72C 7F0C7BFC 01E74825 */  or    $t1, $t7, $a3
/* 0FC730 7F0C7C00 3138FFFF */  andi  $t8, $t1, 0xffff
/* 0FC734 7F0C7C04 00007040 */  sll   $t6, $zero, 1
/* 0FC738 7F0C7C08 008E1021 */  addu  $v0, $a0, $t6
/* 0FC73C 7F0C7C0C 03004825 */  move  $t1, $t8
.L7F0C7C10:
/* 0FC740 7F0C7C10 94590000 */  lhu   $t9, ($v0)
/* 0FC744 7F0C7C14 55390004 */  bnel  $t1, $t9, .L7F0C7C28
/* 0FC748 7F0C7C18 24630001 */   addiu $v1, $v1, 1
/* 0FC74C 7F0C7C1C 10000073 */  b     .L7F0C7DEC
/* 0FC750 7F0C7C20 00601025 */   move  $v0, $v1
/* 0FC754 7F0C7C24 24630001 */  addiu $v1, $v1, 1
.L7F0C7C28:
/* 0FC758 7F0C7C28 1503FFF9 */  bne   $t0, $v1, .L7F0C7C10
/* 0FC75C 7F0C7C2C 24420002 */   addiu $v0, $v0, 2
/* 0FC760 7F0C7C30 1065001D */  beq   $v1, $a1, .L7F0C7CA8
.L7F0C7C34:
/* 0FC764 7F0C7C34 00067A00 */   sll   $t7, $a2, 8
/* 0FC768 7F0C7C38 01E74825 */  or    $t1, $t7, $a3
/* 0FC76C 7F0C7C3C 3138FFFF */  andi  $t8, $t1, 0xffff
/* 0FC770 7F0C7C40 00037040 */  sll   $t6, $v1, 1
/* 0FC774 7F0C7C44 008E1021 */  addu  $v0, $a0, $t6
/* 0FC778 7F0C7C48 03004825 */  move  $t1, $t8
.L7F0C7C4C:
/* 0FC77C 7F0C7C4C 94590000 */  lhu   $t9, ($v0)
/* 0FC780 7F0C7C50 55390004 */  bnel  $t1, $t9, .L7F0C7C64
/* 0FC784 7F0C7C54 944E0002 */   lhu   $t6, 2($v0)
/* 0FC788 7F0C7C58 10000064 */  b     .L7F0C7DEC
/* 0FC78C 7F0C7C5C 00601025 */   move  $v0, $v1
/* 0FC790 7F0C7C60 944E0002 */  lhu   $t6, 2($v0)
.L7F0C7C64:
/* 0FC794 7F0C7C64 552E0004 */  bnel  $t1, $t6, .L7F0C7C78
/* 0FC798 7F0C7C68 944F0004 */   lhu   $t7, 4($v0)
/* 0FC79C 7F0C7C6C 1000005F */  b     .L7F0C7DEC
/* 0FC7A0 7F0C7C70 24620001 */   addiu $v0, $v1, 1
/* 0FC7A4 7F0C7C74 944F0004 */  lhu   $t7, 4($v0)
.L7F0C7C78:
/* 0FC7A8 7F0C7C78 552F0004 */  bnel  $t1, $t7, .L7F0C7C8C
/* 0FC7AC 7F0C7C7C 94580006 */   lhu   $t8, 6($v0)
/* 0FC7B0 7F0C7C80 1000005A */  b     .L7F0C7DEC
/* 0FC7B4 7F0C7C84 24620002 */   addiu $v0, $v1, 2
/* 0FC7B8 7F0C7C88 94580006 */  lhu   $t8, 6($v0)
.L7F0C7C8C:
/* 0FC7BC 7F0C7C8C 55380004 */  bnel  $t1, $t8, .L7F0C7CA0
/* 0FC7C0 7F0C7C90 24630004 */   addiu $v1, $v1, 4
/* 0FC7C4 7F0C7C94 10000055 */  b     .L7F0C7DEC
/* 0FC7C8 7F0C7C98 24620003 */   addiu $v0, $v1, 3
/* 0FC7CC 7F0C7C9C 24630004 */  addiu $v1, $v1, 4
.L7F0C7CA0:
/* 0FC7D0 7F0C7CA0 1465FFEA */  bne   $v1, $a1, .L7F0C7C4C
/* 0FC7D4 7F0C7CA4 24420008 */   addiu $v0, $v0, 8
.L7F0C7CA8:
/* 0FC7D8 7F0C7CA8 24A8FFFF */  addiu $t0, $a1, -1
/* 0FC7DC 7F0C7CAC 29010002 */  slti  $at, $t0, 2
/* 0FC7E0 7F0C7CB0 00001025 */  move  $v0, $zero
/* 0FC7E4 7F0C7CB4 14200027 */  bnez  $at, .L7F0C7D54
/* 0FC7E8 7F0C7CB8 01001825 */   move  $v1, $t0
/* 0FC7EC 7F0C7CBC 00C60019 */  multu $a2, $a2
/* 0FC7F0 7F0C7CC0 0000C812 */  mflo  $t9
/* 0FC7F4 7F0C7CC4 00000000 */  nop   
/* 0FC7F8 7F0C7CC8 00000000 */  nop   
/* 0FC7FC 7F0C7CCC 00E70019 */  multu $a3, $a3
/* 0FC800 7F0C7CD0 00007012 */  mflo  $t6
/* 0FC804 7F0C7CD4 032E4821 */  addu  $t1, $t9, $t6
/* 0FC808 7F0C7CD8 00000000 */  nop   
/* 0FC80C 7F0C7CDC 00625821 */  addu  $t3, $v1, $v0
.L7F0C7CE0:
/* 0FC810 7F0C7CE0 000B5043 */  sra   $t2, $t3, 1
/* 0FC814 7F0C7CE4 000AC040 */  sll   $t8, $t2, 1
/* 0FC818 7F0C7CE8 0098C821 */  addu  $t9, $a0, $t8
/* 0FC81C 7F0C7CEC 972C0000 */  lhu   $t4, ($t9)
/* 0FC820 7F0C7CF0 000C6A03 */  sra   $t5, $t4, 8
/* 0FC824 7F0C7CF4 31AE00FF */  andi  $t6, $t5, 0xff
/* 0FC828 7F0C7CF8 01CE0019 */  multu $t6, $t6
/* 0FC82C 7F0C7CFC 319000FF */  andi  $s0, $t4, 0xff
/* 0FC830 7F0C7D00 00007812 */  mflo  $t7
/* 0FC834 7F0C7D04 00000000 */  nop   
/* 0FC838 7F0C7D08 00000000 */  nop   
/* 0FC83C 7F0C7D0C 02100019 */  multu $s0, $s0
/* 0FC840 7F0C7D10 0000C012 */  mflo  $t8
/* 0FC844 7F0C7D14 01F88821 */  addu  $s1, $t7, $t8
/* 0FC848 7F0C7D18 0229082A */  slt   $at, $s1, $t1
/* 0FC84C 7F0C7D1C 50200004 */  beql  $at, $zero, .L7F0C7D30
/* 0FC850 7F0C7D20 0131082A */   slt   $at, $t1, $s1
/* 0FC854 7F0C7D24 10000007 */  b     .L7F0C7D44
/* 0FC858 7F0C7D28 01401025 */   move  $v0, $t2
/* 0FC85C 7F0C7D2C 0131082A */  slt   $at, $t1, $s1
.L7F0C7D30:
/* 0FC860 7F0C7D30 10200003 */  beqz  $at, .L7F0C7D40
/* 0FC864 7F0C7D34 01401825 */   move  $v1, $t2
/* 0FC868 7F0C7D38 10000002 */  b     .L7F0C7D44
/* 0FC86C 7F0C7D3C 01401825 */   move  $v1, $t2
.L7F0C7D40:
/* 0FC870 7F0C7D40 01401025 */  move  $v0, $t2
.L7F0C7D44:
/* 0FC874 7F0C7D44 0062C823 */  subu  $t9, $v1, $v0
/* 0FC878 7F0C7D48 2B210002 */  slti  $at, $t9, 2
/* 0FC87C 7F0C7D4C 5020FFE4 */  beql  $at, $zero, .L7F0C7CE0
/* 0FC880 7F0C7D50 00625821 */   addu  $t3, $v1, $v0
.L7F0C7D54:
/* 0FC884 7F0C7D54 2462FFFC */  addiu $v0, $v1, -4
/* 0FC888 7F0C7D58 04410002 */  bgez  $v0, .L7F0C7D64
/* 0FC88C 7F0C7D5C 24630004 */   addiu $v1, $v1, 4
/* 0FC890 7F0C7D60 00001025 */  move  $v0, $zero
.L7F0C7D64:
/* 0FC894 7F0C7D64 0065082A */  slt   $at, $v1, $a1
/* 0FC898 7F0C7D68 14200002 */  bnez  $at, .L7F0C7D74
/* 0FC89C 7F0C7D6C 00002825 */   move  $a1, $zero
/* 0FC8A0 7F0C7D70 01001825 */  move  $v1, $t0
.L7F0C7D74:
/* 0FC8A4 7F0C7D74 3C08000F */  lui   $t0, (0x000F423F >> 16) # lui $t0, 0xf
/* 0FC8A8 7F0C7D78 0062082A */  slt   $at, $v1, $v0
/* 0FC8AC 7F0C7D7C 3508423F */  ori   $t0, (0x000F423F & 0xFFFF) # ori $t0, $t0, 0x423f
/* 0FC8B0 7F0C7D80 14200019 */  bnez  $at, .L7F0C7DE8
/* 0FC8B4 7F0C7D84 00405025 */   move  $t2, $v0
/* 0FC8B8 7F0C7D88 00027040 */  sll   $t6, $v0, 1
/* 0FC8BC 7F0C7D8C 008E1021 */  addu  $v0, $a0, $t6
/* 0FC8C0 7F0C7D90 246B0001 */  addiu $t3, $v1, 1
.L7F0C7D94:
/* 0FC8C4 7F0C7D94 944C0000 */  lhu   $t4, ($v0)
/* 0FC8C8 7F0C7D98 000C7A03 */  sra   $t7, $t4, 8
/* 0FC8CC 7F0C7D9C 31F800FF */  andi  $t8, $t7, 0xff
/* 0FC8D0 7F0C7DA0 03061823 */  subu  $v1, $t8, $a2
/* 0FC8D4 7F0C7DA4 00630019 */  multu $v1, $v1
/* 0FC8D8 7F0C7DA8 319900FF */  andi  $t9, $t4, 0xff
/* 0FC8DC 7F0C7DAC 03272023 */  subu  $a0, $t9, $a3
/* 0FC8E0 7F0C7DB0 00007012 */  mflo  $t6
/* 0FC8E4 7F0C7DB4 00000000 */  nop   
/* 0FC8E8 7F0C7DB8 00000000 */  nop   
/* 0FC8EC 7F0C7DBC 00840019 */  multu $a0, $a0
/* 0FC8F0 7F0C7DC0 00007812 */  mflo  $t7
/* 0FC8F4 7F0C7DC4 01CF4821 */  addu  $t1, $t6, $t7
/* 0FC8F8 7F0C7DC8 0128082A */  slt   $at, $t1, $t0
/* 0FC8FC 7F0C7DCC 50200004 */  beql  $at, $zero, .L7F0C7DE0
/* 0FC900 7F0C7DD0 254A0001 */   addiu $t2, $t2, 1
/* 0FC904 7F0C7DD4 01402825 */  move  $a1, $t2
/* 0FC908 7F0C7DD8 01204025 */  move  $t0, $t1
/* 0FC90C 7F0C7DDC 254A0001 */  addiu $t2, $t2, 1
.L7F0C7DE0:
/* 0FC910 7F0C7DE0 156AFFEC */  bne   $t3, $t2, .L7F0C7D94
/* 0FC914 7F0C7DE4 24420002 */   addiu $v0, $v0, 2
.L7F0C7DE8:
/* 0FC918 7F0C7DE8 00A01025 */  move  $v0, $a1
.L7F0C7DEC:
/* 0FC91C 7F0C7DEC 8FB00008 */  lw    $s0, 8($sp)
/* 0FC920 7F0C7DF0 8FB1000C */  lw    $s1, 0xc($sp)
/* 0FC924 7F0C7DF4 03E00008 */  jr    $ra
/* 0FC928 7F0C7DF8 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif





#ifdef NONMATCHING
void texInflateNonZlib(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BD30*/
glabel jpt_8005BD30
.word huffman_type0_1
.word huffman_type0_1
.word huffman_type2
.word huffman_type3
.word huffman_type4
.word huffman_type5
.word huffman_type6
.word huffman_type7
.word huffman_type8
.word huffman_type9
.text
glabel texInflateNonZlib
/* 0FC92C 7F0C7DFC 27BDCF58 */  addiu $sp, $sp, -0x30a8
/* 0FC930 7F0C7E00 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0FC934 7F0C7E04 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0FC938 7F0C7E08 AFB70044 */  sw    $s7, 0x44($sp)
/* 0FC93C 7F0C7E0C AFB60040 */  sw    $s6, 0x40($sp)
/* 0FC940 7F0C7E10 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0FC944 7F0C7E14 AFB40038 */  sw    $s4, 0x38($sp)
/* 0FC948 7F0C7E18 AFB30034 */  sw    $s3, 0x34($sp)
/* 0FC94C 7F0C7E1C AFB20030 */  sw    $s2, 0x30($sp)
/* 0FC950 7F0C7E20 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0FC954 7F0C7E24 AFB00028 */  sw    $s0, 0x28($sp)
/* 0FC958 7F0C7E28 AFA530AC */  sw    $a1, 0x30ac($sp)
/* 0FC95C 7F0C7E2C AFA630B0 */  sw    $a2, 0x30b0($sp)
/* 0FC960 7F0C7E30 AFA730B4 */  sw    $a3, 0x30b4($sp)
/* 0FC964 7F0C7E34 AFA00088 */  sw    $zero, 0x88($sp)
/* 0FC968 7F0C7E38 0FC32FC4 */  jal   texSetBitstring
/* 0FC96C 7F0C7E3C AFA00070 */   sw    $zero, 0x70($sp)
/* 0FC970 7F0C7E40 8FA930B0 */  lw    $t1, 0x30b0($sp)
/* 0FC974 7F0C7E44 8FAA30B4 */  lw    $t2, 0x30b4($sp)
/* 0FC978 7F0C7E48 240E0001 */  li    $t6, 1
/* 0FC97C 7F0C7E4C 11200005 */  beqz  $t1, .L7F0C7E64
/* 0FC980 7F0C7E50 3C088009 */   lui   $t0, %hi(dword_CODE_bss_8008D090) 
/* 0FC984 7F0C7E54 51400004 */  beql  $t2, $zero, .L7F0C7E68
/* 0FC988 7F0C7E58 8FAA30B4 */   lw    $t2, 0x30b4($sp)
/* 0FC98C 7F0C7E5C 10000003 */  b     .L7F0C7E6C
/* 0FC990 7F0C7E60 AFAA009C */   sw    $t2, 0x9c($sp)
.L7F0C7E64:
/* 0FC994 7F0C7E64 8FAA30B4 */  lw    $t2, 0x30b4($sp)
.L7F0C7E68:
/* 0FC998 7F0C7E68 AFAE009C */  sw    $t6, 0x9c($sp)
.L7F0C7E6C:
/* 0FC99C 7F0C7E6C 8FA730B8 */  lw    $a3, 0x30b8($sp)
/* 0FC9A0 7F0C7E70 000AC940 */  sll   $t9, $t2, 5
/* 0FC9A4 7F0C7E74 00097940 */  sll   $t7, $t1, 5
/* 0FC9A8 7F0C7E78 8CE3000C */  lw    $v1, 0xc($a3)
/* 0FC9AC 7F0C7E7C 31F80020 */  andi  $t8, $t7, 0x20
/* 0FC9B0 7F0C7E80 2508D090 */  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
/* 0FC9B4 7F0C7E84 906B000B */  lbu   $t3, 0xb($v1)
/* 0FC9B8 7F0C7E88 316CFF1F */  andi  $t4, $t3, 0xff1f
/* 0FC9BC 7F0C7E8C 032C6825 */  or    $t5, $t9, $t4
/* 0FC9C0 7F0C7E90 A06D000B */  sb    $t5, 0xb($v1)
/* 0FC9C4 7F0C7E94 8CE3000C */  lw    $v1, 0xc($a3)
/* 0FC9C8 7F0C7E98 906B000C */  lbu   $t3, 0xc($v1)
/* 0FC9CC 7F0C7E9C 3179FFDF */  andi  $t9, $t3, 0xffdf
/* 0FC9D0 7F0C7EA0 03196025 */  or    $t4, $t8, $t9
/* 0FC9D4 7F0C7EA4 11200017 */  beqz  $t1, .L7F0C7F04
/* 0FC9D8 7F0C7EA8 A06C000C */   sb    $t4, 0xc($v1)
/* 0FC9DC 7F0C7EAC 8D050000 */  lw    $a1, ($t0)
/* 0FC9E0 7F0C7EB0 24060001 */  li    $a2, 1
/* 0FC9E4 7F0C7EB4 AFA60070 */  sw    $a2, 0x70($sp)
/* 0FC9E8 7F0C7EB8 58A00013 */  blezl $a1, .L7F0C7F08
/* 0FC9EC 7F0C7EBC 8FB9009C */   lw    $t9, 0x9c($sp)
/* 0FC9F0 7F0C7EC0 8CED000C */  lw    $t5, 0xc($a3)
/* 0FC9F4 7F0C7EC4 3C0F8009 */  lui   $t7, %hi(word_CODE_bss_8008C730)
/* 0FC9F8 7F0C7EC8 25E2C730 */  addiu $v0, $t7, %lo(word_CODE_bss_8008C730)
/* 0FC9FC 7F0C7ECC 8DA30000 */  lw    $v1, ($t5)
/* 0FCA00 7F0C7ED0 00055900 */  sll   $t3, $a1, 4
/* 0FCA04 7F0C7ED4 01622021 */  addu  $a0, $t3, $v0
/* 0FCA08 7F0C7ED8 00037502 */  srl   $t6, $v1, 0x14
/* 0FCA0C 7F0C7EDC 01C01825 */  move  $v1, $t6
/* 0FCA10 7F0C7EE0 84580000 */  lh    $t8, ($v0)
.L7F0C7EE4:
/* 0FCA14 7F0C7EE4 24420010 */  addiu $v0, $v0, 0x10
/* 0FCA18 7F0C7EE8 0044082B */  sltu  $at, $v0, $a0
/* 0FCA1C 7F0C7EEC 14780002 */  bne   $v1, $t8, .L7F0C7EF8
/* 0FCA20 7F0C7EF0 00000000 */   nop   
/* 0FCA24 7F0C7EF4 00003025 */  move  $a2, $zero
.L7F0C7EF8:
/* 0FCA28 7F0C7EF8 5420FFFA */  bnezl $at, .L7F0C7EE4
/* 0FCA2C 7F0C7EFC 84580000 */   lh    $t8, ($v0)
/* 0FCA30 7F0C7F00 AFA60070 */  sw    $a2, 0x70($sp)
.L7F0C7F04:
/* 0FCA34 7F0C7F04 8FB9009C */  lw    $t9, 0x9c($sp)
.L7F0C7F08:
/* 0FCA38 7F0C7F08 3C088009 */  lui   $t0, %hi(dword_CODE_bss_8008D090) 
/* 0FCA3C 7F0C7F0C 2508D090 */  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
/* 0FCA40 7F0C7F10 8FA60070 */  lw    $a2, 0x70($sp)
/* 0FCA44 7F0C7F14 1B2001BA */  blez  $t9, .L7F0C8600
/* 0FCA48 7F0C7F18 AFA000A0 */   sw    $zero, 0xa0($sp)
/* 0FCA4C 7F0C7F1C AFA60070 */  sw    $a2, 0x70($sp)
/* 0FCA50 7F0C7F20 27BE10A8 */  addiu $fp, $sp, 0x10a8
.L7F0C7F24:
/* 0FCA54 7F0C7F24 0FC32FCB */  jal   texReadBits
/* 0FCA58 7F0C7F28 24040004 */   li    $a0, 4
/* 0FCA5C 7F0C7F2C AFA20080 */  sw    $v0, 0x80($sp)
/* 0FCA60 7F0C7F30 0FC32FCB */  jal   texReadBits
/* 0FCA64 7F0C7F34 24040008 */   li    $a0, 8
/* 0FCA68 7F0C7F38 0040B025 */  move  $s6, $v0
/* 0FCA6C 7F0C7F3C 0FC32FCB */  jal   texReadBits
/* 0FCA70 7F0C7F40 24040008 */   li    $a0, 8
/* 0FCA74 7F0C7F44 0040B825 */  move  $s7, $v0
/* 0FCA78 7F0C7F48 0FC32FCB */  jal   texReadBits
/* 0FCA7C 7F0C7F4C 24040004 */   li    $a0, 4
/* 0FCA80 7F0C7F50 8FA500A0 */  lw    $a1, 0xa0($sp)
/* 0FCA84 7F0C7F54 8FA430B8 */  lw    $a0, 0x30b8($sp)
/* 0FCA88 7F0C7F58 8FAB0070 */  lw    $t3, 0x70($sp)
/* 0FCA8C 7F0C7F5C 14A00026 */  bnez  $a1, .L7F0C7FF8
/* 0FCA90 7F0C7F60 00000000 */   nop   
/* 0FCA94 7F0C7F64 8C8C000C */  lw    $t4, 0xc($a0)
/* 0FCA98 7F0C7F68 3C0B8005 */  lui   $t3, %hi(g_TexFormatGbiMappings)
/* 0FCA9C 7F0C7F6C A1960008 */  sb    $s6, 8($t4)
/* 0FCAA0 7F0C7F70 8C8D000C */  lw    $t5, 0xc($a0)
/* 0FCAA4 7F0C7F74 A1B70009 */  sb    $s7, 9($t5)
/* 0FCAA8 7F0C7F78 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCAAC 7F0C7F7C 8C83000C */  lw    $v1, 0xc($a0)
/* 0FCAB0 7F0C7F80 00147080 */  sll   $t6, $s4, 2
/* 0FCAB4 7F0C7F84 016E5821 */  addu  $t3, $t3, $t6
/* 0FCAB8 7F0C7F88 8D6F9248 */  lw    $t7, %lo(g_TexFormatGbiMappings)($t3)
/* 0FCABC 7F0C7F8C 906C000B */  lbu   $t4, 0xb($v1)
/* 0FCAC0 7F0C7F90 01C0A025 */  move  $s4, $t6
/* 0FCAC4 7F0C7F94 000FC080 */  sll   $t8, $t7, 2
/* 0FCAC8 7F0C7F98 3319001C */  andi  $t9, $t8, 0x1c
/* 0FCACC 7F0C7F9C 318DFFE3 */  andi  $t5, $t4, 0xffe3
/* 0FCAD0 7F0C7FA0 032D7025 */  or    $t6, $t9, $t5
/* 0FCAD4 7F0C7FA4 A06E000B */  sb    $t6, 0xb($v1)
/* 0FCAD8 7F0C7FA8 8C83000C */  lw    $v1, 0xc($a0)
/* 0FCADC 7F0C7FAC 3C0B8005 */  lui   $t3, %hi(g_TexFormatDepths)
/* 0FCAE0 7F0C7FB0 01745821 */  addu  $t3, $t3, $s4
/* 0FCAE4 7F0C7FB4 8D6F927C */  lw    $t7, %lo(g_TexFormatDepths)($t3)
/* 0FCAE8 7F0C7FB8 906C000B */  lbu   $t4, 0xb($v1)
/* 0FCAEC 7F0C7FBC 3C0E8005 */  lui   $t6, %hi(g_TexFormatLutModes)
/* 0FCAF0 7F0C7FC0 31F80003 */  andi  $t8, $t7, 3
/* 0FCAF4 7F0C7FC4 3199FFFC */  andi  $t9, $t4, 0xfffc
/* 0FCAF8 7F0C7FC8 03196825 */  or    $t5, $t8, $t9
/* 0FCAFC 7F0C7FCC A06D000B */  sb    $t5, 0xb($v1)
/* 0FCB00 7F0C7FD0 8C83000C */  lw    $v1, 0xc($a0)
/* 0FCB04 7F0C7FD4 01D47021 */  addu  $t6, $t6, $s4
/* 0FCB08 7F0C7FD8 8DCE92B0 */  lw    $t6, %lo(g_TexFormatLutModes)($t6)
/* 0FCB0C 7F0C7FDC 9079000C */  lbu   $t9, 0xc($v1)
/* 0FCB10 7F0C7FE0 000E7B83 */  sra   $t7, $t6, 0xe
/* 0FCB14 7F0C7FE4 000FC180 */  sll   $t8, $t7, 6
/* 0FCB18 7F0C7FE8 332DFF3F */  andi  $t5, $t9, 0xff3f
/* 0FCB1C 7F0C7FEC 030D7025 */  or    $t6, $t8, $t5
/* 0FCB20 7F0C7FF0 1000000B */  b     .L7F0C8020
/* 0FCB24 7F0C7FF4 A06E000C */   sb    $t6, 0xc($v1)
.L7F0C7FF8:
/* 0FCB28 7F0C7FF8 11600009 */  beqz  $t3, .L7F0C8020
/* 0FCB2C 7F0C7FFC 3C0F8009 */   lui   $t7, %hi(dword_CODE_bss_8008D090) 
/* 0FCB30 7F0C8000 8DEFD090 */  lw    $t7, %lo(dword_CODE_bss_8008D090)($t7)
/* 0FCB34 7F0C8004 3C188009 */  lui   $t8, %hi(word_CODE_bss_8008C730) 
/* 0FCB38 7F0C8008 2718C730 */  addiu $t8, %lo(word_CODE_bss_8008C730) # addiu $t8, $t8, -0x38d0
/* 0FCB3C 7F0C800C 000F6100 */  sll   $t4, $t7, 4
/* 0FCB40 7F0C8010 0185C821 */  addu  $t9, $t4, $a1
/* 0FCB44 7F0C8014 03381821 */  addu  $v1, $t9, $t8
/* 0FCB48 7F0C8018 A0760001 */  sb    $s6, 1($v1)
/* 0FCB4C 7F0C801C A0770008 */  sb    $s7, 8($v1)
.L7F0C8020:
/* 0FCB50 7F0C8020 02D70019 */  multu $s6, $s7
/* 0FCB54 7F0C8024 00026880 */  sll   $t5, $v0, 2
/* 0FCB58 7F0C8028 0000A812 */  mflo  $s5
/* 0FCB5C 7F0C802C 2AA12001 */  slti  $at, $s5, 0x2001
/* 0FCB60 7F0C8030 54200004 */  bnezl $at, .L7F0C8044
/* 0FCB64 7F0C8034 2C41000A */   sltiu $at, $v0, 0xa
/* 0FCB68 7F0C8038 100001BA */  b     .L7F0C8724
/* 0FCB6C 7F0C803C 00001025 */   move  $v0, $zero
/* 0FCB70 7F0C8040 2C41000A */  sltiu $at, $v0, 0xa
.L7F0C8044:
/* 0FCB74 7F0C8044 1020013B */  beqz  $at, .L7F0C8534
/* 0FCB78 7F0C8048 3C018006 */   lui   $at, %hi(jpt_8005BD30)
/* 0FCB7C 7F0C804C 002D0821 */  addu  $at, $at, $t5
/* 0FCB80 7F0C8050 8C2DBD30 */  lw    $t5, %lo(jpt_8005BD30)($at)
/* 0FCB84 7F0C8054 01A00008 */  jr    $t5
/* 0FCB88 7F0C8058 00000000 */   nop   
huffman_type0_1:
/* 0FCB8C 7F0C805C 8FAE30AC */  lw    $t6, 0x30ac($sp)
/* 0FCB90 7F0C8060 8FAB0088 */  lw    $t3, 0x88($sp)
/* 0FCB94 7F0C8064 02C02825 */  move  $a1, $s6
/* 0FCB98 7F0C8068 02E03025 */  move  $a2, $s7
/* 0FCB9C 7F0C806C 01CB8021 */  addu  $s0, $t6, $t3
/* 0FCBA0 7F0C8070 02002025 */  move  $a0, $s0
/* 0FCBA4 7F0C8074 0FC326A7 */  jal   texReadUncompressed
/* 0FCBA8 7F0C8078 8FA70080 */   lw    $a3, 0x80($sp)
/* 0FCBAC 7F0C807C 10000137 */  b     .L7F0C855C
/* 0FCBB0 7F0C8080 00408825 */   move  $s1, $v0
huffman_type2:
/* 0FCBB4 7F0C8084 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCBB8 7F0C8088 3C0C8005 */  lui   $t4, %hi(g_TexFormatNumChannels)
/* 0FCBBC 7F0C808C 3C068005 */  lui   $a2, %hi(g_TexFormatChannelSizes)
/* 0FCBC0 7F0C8090 00147880 */  sll   $t7, $s4, 2
/* 0FCBC4 7F0C8094 018F6021 */  addu  $t4, $t4, $t7
/* 0FCBC8 7F0C8098 8D8C9178 */  lw    $t4, %lo(g_TexFormatNumChannels)($t4)
/* 0FCBCC 7F0C809C 00CF3021 */  addu  $a2, $a2, $t7
/* 0FCBD0 7F0C80A0 8CC691E0 */  lw    $a2, %lo(g_TexFormatChannelSizes)($a2)
/* 0FCBD4 7F0C80A4 01960019 */  multu $t4, $s6
/* 0FCBD8 7F0C80A8 01E0A025 */  move  $s4, $t7
/* 0FCBDC 7F0C80AC 03C02025 */  move  $a0, $fp
/* 0FCBE0 7F0C80B0 0000C812 */  mflo  $t9
/* 0FCBE4 7F0C80B4 00000000 */  nop   
/* 0FCBE8 7F0C80B8 00000000 */  nop   
/* 0FCBEC 7F0C80BC 03370019 */  multu $t9, $s7
/* 0FCBF0 7F0C80C0 00002812 */  mflo  $a1
/* 0FCBF4 7F0C80C4 0FC32474 */  jal   texInflateHuffman
/* 0FCBF8 7F0C80C8 00000000 */   nop   
/* 0FCBFC 7F0C80CC 3C188005 */  lui   $t8, %hi(g_TexFormatNumChannels+52)
/* 0FCC00 7F0C80D0 0314C021 */  addu  $t8, $t8, $s4
/* 0FCC04 7F0C80D4 8F1891AC */  lw    $t8, %lo(g_TexFormatNumChannels+52)($t8)
/* 0FCC08 7F0C80D8 00156880 */  sll   $t5, $s5, 2
/* 0FCC0C 7F0C80DC 01B56823 */  subu  $t5, $t5, $s5
/* 0FCC10 7F0C80E0 13000003 */  beqz  $t8, .L7F0C80F0
/* 0FCC14 7F0C80E4 03CD2021 */   addu  $a0, $fp, $t5
/* 0FCC18 7F0C80E8 0FC32692 */  jal   texReadAlphaBits
/* 0FCC1C 7F0C80EC 02A02825 */   move  $a1, $s5
.L7F0C80F0:
/* 0FCC20 7F0C80F0 8FAE30AC */  lw    $t6, 0x30ac($sp)
/* 0FCC24 7F0C80F4 8FAB0088 */  lw    $t3, 0x88($sp)
/* 0FCC28 7F0C80F8 8FAF0080 */  lw    $t7, 0x80($sp)
/* 0FCC2C 7F0C80FC 03C02025 */  move  $a0, $fp
/* 0FCC30 7F0C8100 01CB8021 */  addu  $s0, $t6, $t3
/* 0FCC34 7F0C8104 02003825 */  move  $a3, $s0
/* 0FCC38 7F0C8108 02C02825 */  move  $a1, $s6
/* 0FCC3C 7F0C810C 02E03025 */  move  $a2, $s7
/* 0FCC40 7F0C8110 0FC32769 */  jal   texChannelsToPixels
/* 0FCC44 7F0C8114 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FCC48 7F0C8118 10000110 */  b     .L7F0C855C
/* 0FCC4C 7F0C811C 00408825 */   move  $s1, $v0
huffman_type3:
/* 0FCC50 7F0C8120 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCC54 7F0C8124 3C198005 */  lui   $t9, %hi(g_TexFormatNumChannels) 
/* 0FCC58 7F0C8128 27399178 */  addiu $t9, %lo(g_TexFormatNumChannels) # addiu $t9, $t9, -0x6e88
/* 0FCC5C 7F0C812C 00146080 */  sll   $t4, $s4, 2
/* 0FCC60 7F0C8130 01999821 */  addu  $s3, $t4, $t9
/* 0FCC64 7F0C8134 8E780000 */  lw    $t8, ($s3)
/* 0FCC68 7F0C8138 0180A025 */  move  $s4, $t4
/* 0FCC6C 7F0C813C 00008825 */  move  $s1, $zero
/* 0FCC70 7F0C8140 1B000010 */  blez  $t8, .L7F0C8184
/* 0FCC74 7F0C8144 3C0D8005 */   lui   $t5, %hi(g_TexFormatChannelSizes) 
/* 0FCC78 7F0C8148 25AD91E0 */  addiu $t5, %lo(g_TexFormatChannelSizes) # addiu $t5, $t5, -0x6e20
/* 0FCC7C 7F0C814C 018D9021 */  addu  $s2, $t4, $t5
/* 0FCC80 7F0C8150 03C08025 */  move  $s0, $fp
/* 0FCC84 7F0C8154 02002025 */  move  $a0, $s0
.L7F0C8158:
/* 0FCC88 7F0C8158 02A02825 */  move  $a1, $s5
/* 0FCC8C 7F0C815C 0FC32474 */  jal   texInflateHuffman
/* 0FCC90 7F0C8160 8E460000 */   lw    $a2, ($s2)
/* 0FCC94 7F0C8164 02D70019 */  multu $s6, $s7
/* 0FCC98 7F0C8168 8E6B0000 */  lw    $t3, ($s3)
/* 0FCC9C 7F0C816C 26310001 */  addiu $s1, $s1, 1
/* 0FCCA0 7F0C8170 022B082A */  slt   $at, $s1, $t3
/* 0FCCA4 7F0C8174 00007012 */  mflo  $t6
/* 0FCCA8 7F0C8178 020E8021 */  addu  $s0, $s0, $t6
/* 0FCCAC 7F0C817C 5420FFF6 */  bnezl $at, .L7F0C8158
/* 0FCCB0 7F0C8180 02002025 */   move  $a0, $s0
.L7F0C8184:
/* 0FCCB4 7F0C8184 3C0F8005 */  lui   $t7, %hi(g_TexFormatNumChannels+52)
/* 0FCCB8 7F0C8188 01F47821 */  addu  $t7, $t7, $s4
/* 0FCCBC 7F0C818C 8DEF91AC */  lw    $t7, %lo(g_TexFormatNumChannels+52)($t7)
/* 0FCCC0 7F0C8190 00156080 */  sll   $t4, $s5, 2
/* 0FCCC4 7F0C8194 01956023 */  subu  $t4, $t4, $s5
/* 0FCCC8 7F0C8198 11E00003 */  beqz  $t7, .L7F0C81A8
/* 0FCCCC 7F0C819C 03CC2021 */   addu  $a0, $fp, $t4
/* 0FCCD0 7F0C81A0 0FC32692 */  jal   texReadAlphaBits
/* 0FCCD4 7F0C81A4 02A02825 */   move  $a1, $s5
.L7F0C81A8:
/* 0FCCD8 7F0C81A8 8FB930AC */  lw    $t9, 0x30ac($sp)
/* 0FCCDC 7F0C81AC 8FB80088 */  lw    $t8, 0x88($sp)
/* 0FCCE0 7F0C81B0 8FAD0080 */  lw    $t5, 0x80($sp)
/* 0FCCE4 7F0C81B4 03C02025 */  move  $a0, $fp
/* 0FCCE8 7F0C81B8 03388021 */  addu  $s0, $t9, $t8
/* 0FCCEC 7F0C81BC 02003825 */  move  $a3, $s0
/* 0FCCF0 7F0C81C0 02C02825 */  move  $a1, $s6
/* 0FCCF4 7F0C81C4 02E03025 */  move  $a2, $s7
/* 0FCCF8 7F0C81C8 0FC32769 */  jal   texChannelsToPixels
/* 0FCCFC 7F0C81CC AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FCD00 7F0C81D0 100000E2 */  b     .L7F0C855C
/* 0FCD04 7F0C81D4 00408825 */   move  $s1, $v0
huffman_type4:
/* 0FCD08 7F0C81D8 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCD0C 7F0C81DC 3C0B8005 */  lui   $t3, %hi(g_TexFormatNumChannels)
/* 0FCD10 7F0C81E0 03C02025 */  move  $a0, $fp
/* 0FCD14 7F0C81E4 00147080 */  sll   $t6, $s4, 2
/* 0FCD18 7F0C81E8 016E5821 */  addu  $t3, $t3, $t6
/* 0FCD1C 7F0C81EC 8D6B9178 */  lw    $t3, %lo(g_TexFormatNumChannels)($t3)
/* 0FCD20 7F0C81F0 01C0A025 */  move  $s4, $t6
/* 0FCD24 7F0C81F4 01760019 */  multu $t3, $s6
/* 0FCD28 7F0C81F8 00007812 */  mflo  $t7
/* 0FCD2C 7F0C81FC 00000000 */  nop   
/* 0FCD30 7F0C8200 00000000 */  nop   
/* 0FCD34 7F0C8204 01F70019 */  multu $t7, $s7
/* 0FCD38 7F0C8208 00002812 */  mflo  $a1
/* 0FCD3C 7F0C820C 0FC325AF */  jal   texInflateRle
/* 0FCD40 7F0C8210 00000000 */   nop   
/* 0FCD44 7F0C8214 3C0C8005 */  lui   $t4, %hi(g_TexFormatNumChannels+52)
/* 0FCD48 7F0C8218 01946021 */  addu  $t4, $t4, $s4
/* 0FCD4C 7F0C821C 8D8C91AC */  lw    $t4, %lo(g_TexFormatNumChannels+52)($t4)
/* 0FCD50 7F0C8220 0015C880 */  sll   $t9, $s5, 2
/* 0FCD54 7F0C8224 0335C823 */  subu  $t9, $t9, $s5
/* 0FCD58 7F0C8228 11800003 */  beqz  $t4, .L7F0C8238
/* 0FCD5C 7F0C822C 03D92021 */   addu  $a0, $fp, $t9
/* 0FCD60 7F0C8230 0FC32692 */  jal   texReadAlphaBits
/* 0FCD64 7F0C8234 02A02825 */   move  $a1, $s5
.L7F0C8238:
/* 0FCD68 7F0C8238 8FB830AC */  lw    $t8, 0x30ac($sp)
/* 0FCD6C 7F0C823C 8FAD0088 */  lw    $t5, 0x88($sp)
/* 0FCD70 7F0C8240 8FAE0080 */  lw    $t6, 0x80($sp)
/* 0FCD74 7F0C8244 03C02025 */  move  $a0, $fp
/* 0FCD78 7F0C8248 030D8021 */  addu  $s0, $t8, $t5
/* 0FCD7C 7F0C824C 02003825 */  move  $a3, $s0
/* 0FCD80 7F0C8250 02C02825 */  move  $a1, $s6
/* 0FCD84 7F0C8254 02E03025 */  move  $a2, $s7
/* 0FCD88 7F0C8258 0FC32769 */  jal   texChannelsToPixels
/* 0FCD8C 7F0C825C AFAE0010 */   sw    $t6, 0x10($sp)
/* 0FCD90 7F0C8260 100000BE */  b     .L7F0C855C
/* 0FCD94 7F0C8264 00408825 */   move  $s1, $v0
huffman_type5:
/* 0FCD98 7F0C8268 8FAB0080 */  lw    $t3, 0x80($sp)
/* 0FCD9C 7F0C826C 3C058005 */  lui   $a1, %hi(g_TexFormatChannelSizes+52)
/* 0FCDA0 7F0C8270 27A400A8 */  addiu $a0, $sp, 0xa8
/* 0FCDA4 7F0C8274 000B7880 */  sll   $t7, $t3, 2
/* 0FCDA8 7F0C8278 00AF2821 */  addu  $a1, $a1, $t7
/* 0FCDAC 7F0C827C 0FC32648 */  jal   texBuildLookup
/* 0FCDB0 7F0C8280 8CA59214 */   lw    $a1, %lo(g_TexFormatChannelSizes+52)($a1)
/* 0FCDB4 7F0C8284 8FAC30AC */  lw    $t4, 0x30ac($sp)
/* 0FCDB8 7F0C8288 8FB90088 */  lw    $t9, 0x88($sp)
/* 0FCDBC 7F0C828C 8FB80080 */  lw    $t8, 0x80($sp)
/* 0FCDC0 7F0C8290 02C02025 */  move  $a0, $s6
/* 0FCDC4 7F0C8294 01998021 */  addu  $s0, $t4, $t9
/* 0FCDC8 7F0C8298 02003025 */  move  $a2, $s0
/* 0FCDCC 7F0C829C 02E02825 */  move  $a1, $s7
/* 0FCDD0 7F0C82A0 27A700A8 */  addiu $a3, $sp, 0xa8
/* 0FCDD4 7F0C82A4 AFA20010 */  sw    $v0, 0x10($sp)
/* 0FCDD8 7F0C82A8 0FC32A24 */  jal   texInflateLookup
/* 0FCDDC 7F0C82AC AFB80014 */   sw    $t8, 0x14($sp)
/* 0FCDE0 7F0C82B0 100000AA */  b     .L7F0C855C
/* 0FCDE4 7F0C82B4 00408825 */   move  $s1, $v0
huffman_type6:
/* 0FCDE8 7F0C82B8 8FAD0080 */  lw    $t5, 0x80($sp)
/* 0FCDEC 7F0C82BC 3C058005 */  lui   $a1, %hi(g_TexFormatChannelSizes+52)
/* 0FCDF0 7F0C82C0 27A400A8 */  addiu $a0, $sp, 0xa8
/* 0FCDF4 7F0C82C4 000D7080 */  sll   $t6, $t5, 2
/* 0FCDF8 7F0C82C8 00AE2821 */  addu  $a1, $a1, $t6
/* 0FCDFC 7F0C82CC 0FC32648 */  jal   texBuildLookup
/* 0FCE00 7F0C82D0 8CA59214 */   lw    $a1, %lo(g_TexFormatChannelSizes+52)($a1)
/* 0FCE04 7F0C82D4 00408825 */  move  $s1, $v0
/* 0FCE08 7F0C82D8 03C02025 */  move  $a0, $fp
/* 0FCE0C 7F0C82DC 02A02825 */  move  $a1, $s5
/* 0FCE10 7F0C82E0 0FC32474 */  jal   texInflateHuffman
/* 0FCE14 7F0C82E4 00403025 */   move  $a2, $v0
/* 0FCE18 7F0C82E8 8FAB30AC */  lw    $t3, 0x30ac($sp)
/* 0FCE1C 7F0C82EC 8FAF0088 */  lw    $t7, 0x88($sp)
/* 0FCE20 7F0C82F0 8FB90080 */  lw    $t9, 0x80($sp)
/* 0FCE24 7F0C82F4 27AC00A8 */  addiu $t4, $sp, 0xa8
/* 0FCE28 7F0C82F8 016F8021 */  addu  $s0, $t3, $t7
/* 0FCE2C 7F0C82FC 02003825 */  move  $a3, $s0
/* 0FCE30 7F0C8300 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0FCE34 7F0C8304 03C02025 */  move  $a0, $fp
/* 0FCE38 7F0C8308 02C02825 */  move  $a1, $s6
/* 0FCE3C 7F0C830C 02E03025 */  move  $a2, $s7
/* 0FCE40 7F0C8310 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FCE44 7F0C8314 0FC32B16 */  jal   texInflateLookupFromBuffer
/* 0FCE48 7F0C8318 AFB90018 */   sw    $t9, 0x18($sp)
/* 0FCE4C 7F0C831C 1000008F */  b     .L7F0C855C
/* 0FCE50 7F0C8320 00408825 */   move  $s1, $v0
huffman_type7:
/* 0FCE54 7F0C8324 8FB80080 */  lw    $t8, 0x80($sp)
/* 0FCE58 7F0C8328 3C058005 */  lui   $a1, %hi(g_TexFormatChannelSizes+52)
/* 0FCE5C 7F0C832C 27A400A8 */  addiu $a0, $sp, 0xa8
/* 0FCE60 7F0C8330 00186880 */  sll   $t5, $t8, 2
/* 0FCE64 7F0C8334 00AD2821 */  addu  $a1, $a1, $t5
/* 0FCE68 7F0C8338 0FC32648 */  jal   texBuildLookup
/* 0FCE6C 7F0C833C 8CA59214 */   lw    $a1, %lo(g_TexFormatChannelSizes+52)($a1)
/* 0FCE70 7F0C8340 00408825 */  move  $s1, $v0
/* 0FCE74 7F0C8344 03C02025 */  move  $a0, $fp
/* 0FCE78 7F0C8348 0FC325AF */  jal   texInflateRle
/* 0FCE7C 7F0C834C 02A02825 */   move  $a1, $s5
/* 0FCE80 7F0C8350 8FAE30AC */  lw    $t6, 0x30ac($sp)
/* 0FCE84 7F0C8354 8FAB0088 */  lw    $t3, 0x88($sp)
/* 0FCE88 7F0C8358 8FAC0080 */  lw    $t4, 0x80($sp)
/* 0FCE8C 7F0C835C 27AF00A8 */  addiu $t7, $sp, 0xa8
/* 0FCE90 7F0C8360 01CB8021 */  addu  $s0, $t6, $t3
/* 0FCE94 7F0C8364 02003825 */  move  $a3, $s0
/* 0FCE98 7F0C8368 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0FCE9C 7F0C836C 03C02025 */  move  $a0, $fp
/* 0FCEA0 7F0C8370 02C02825 */  move  $a1, $s6
/* 0FCEA4 7F0C8374 02E03025 */  move  $a2, $s7
/* 0FCEA8 7F0C8378 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FCEAC 7F0C837C 0FC32B16 */  jal   texInflateLookupFromBuffer
/* 0FCEB0 7F0C8380 AFAC0018 */   sw    $t4, 0x18($sp)
/* 0FCEB4 7F0C8384 10000075 */  b     .L7F0C855C
/* 0FCEB8 7F0C8388 00408825 */   move  $s1, $v0
huffman_type8:
/* 0FCEBC 7F0C838C 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCEC0 7F0C8390 24040003 */  li    $a0, 3
/* 0FCEC4 7F0C8394 0014C880 */  sll   $t9, $s4, 2
/* 0FCEC8 7F0C8398 0FC32FCB */  jal   texReadBits
/* 0FCECC 7F0C839C 0320A025 */   move  $s4, $t9
/* 0FCED0 7F0C83A0 3C188005 */  lui   $t8, %hi(g_TexFormatNumChannels) 
/* 0FCED4 7F0C83A4 27189178 */  addiu $t8, %lo(g_TexFormatNumChannels) # addiu $t8, $t8, -0x6e88
/* 0FCED8 7F0C83A8 02989821 */  addu  $s3, $s4, $t8
/* 0FCEDC 7F0C83AC 8E6D0000 */  lw    $t5, ($s3)
/* 0FCEE0 7F0C83B0 3C0B8005 */  lui   $t3, %hi(g_TexFormatChannelSizes) 
/* 0FCEE4 7F0C83B4 256B91E0 */  addiu $t3, %lo(g_TexFormatChannelSizes) # addiu $t3, $t3, -0x6e20
/* 0FCEE8 7F0C83B8 01B60019 */  multu $t5, $s6
/* 0FCEEC 7F0C83BC 028B9021 */  addu  $s2, $s4, $t3
/* 0FCEF0 7F0C83C0 00408025 */  move  $s0, $v0
/* 0FCEF4 7F0C83C4 8E460000 */  lw    $a2, ($s2)
/* 0FCEF8 7F0C83C8 03C02025 */  move  $a0, $fp
/* 0FCEFC 7F0C83CC 00007012 */  mflo  $t6
/* 0FCF00 7F0C83D0 00000000 */  nop   
/* 0FCF04 7F0C83D4 00000000 */  nop   
/* 0FCF08 7F0C83D8 01D70019 */  multu $t6, $s7
/* 0FCF0C 7F0C83DC 00002812 */  mflo  $a1
/* 0FCF10 7F0C83E0 0FC32474 */  jal   texInflateHuffman
/* 0FCF14 7F0C83E4 00000000 */   nop   
/* 0FCF18 7F0C83E8 8E6F0000 */  lw    $t7, ($s3)
/* 0FCF1C 7F0C83EC 8E4C0000 */  lw    $t4, ($s2)
/* 0FCF20 7F0C83F0 03C02025 */  move  $a0, $fp
/* 0FCF24 7F0C83F4 01F70019 */  multu $t7, $s7
/* 0FCF28 7F0C83F8 02C02825 */  move  $a1, $s6
/* 0FCF2C 7F0C83FC 02003825 */  move  $a3, $s0
/* 0FCF30 7F0C8400 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0FCF34 7F0C8404 00003012 */  mflo  $a2
/* 0FCF38 7F0C8408 0FC32DF8 */  jal   texBlur
/* 0FCF3C 7F0C840C 00000000 */   nop   
/* 0FCF40 7F0C8410 3C198005 */  lui   $t9, %hi(g_TexFormatNumChannels+52)
/* 0FCF44 7F0C8414 0334C821 */  addu  $t9, $t9, $s4
/* 0FCF48 7F0C8418 8F3991AC */  lw    $t9, %lo(g_TexFormatNumChannels+52)($t9)
/* 0FCF4C 7F0C841C 0015C080 */  sll   $t8, $s5, 2
/* 0FCF50 7F0C8420 0315C023 */  subu  $t8, $t8, $s5
/* 0FCF54 7F0C8424 13200003 */  beqz  $t9, .L7F0C8434
/* 0FCF58 7F0C8428 03D82021 */   addu  $a0, $fp, $t8
/* 0FCF5C 7F0C842C 0FC32692 */  jal   texReadAlphaBits
/* 0FCF60 7F0C8430 02A02825 */   move  $a1, $s5
.L7F0C8434:
/* 0FCF64 7F0C8434 8FAD30AC */  lw    $t5, 0x30ac($sp)
/* 0FCF68 7F0C8438 8FAE0088 */  lw    $t6, 0x88($sp)
/* 0FCF6C 7F0C843C 8FAB0080 */  lw    $t3, 0x80($sp)
/* 0FCF70 7F0C8440 03C02025 */  move  $a0, $fp
/* 0FCF74 7F0C8444 01AE8021 */  addu  $s0, $t5, $t6
/* 0FCF78 7F0C8448 02003825 */  move  $a3, $s0
/* 0FCF7C 7F0C844C 02C02825 */  move  $a1, $s6
/* 0FCF80 7F0C8450 02E03025 */  move  $a2, $s7
/* 0FCF84 7F0C8454 0FC32769 */  jal   texChannelsToPixels
/* 0FCF88 7F0C8458 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0FCF8C 7F0C845C 1000003F */  b     .L7F0C855C
/* 0FCF90 7F0C8460 00408825 */   move  $s1, $v0
huffman_type9:
/* 0FCF94 7F0C8464 8FB40080 */  lw    $s4, 0x80($sp)
/* 0FCF98 7F0C8468 24040003 */  li    $a0, 3
/* 0FCF9C 7F0C846C 00147880 */  sll   $t7, $s4, 2
/* 0FCFA0 7F0C8470 0FC32FCB */  jal   texReadBits
/* 0FCFA4 7F0C8474 01E0A025 */   move  $s4, $t7
/* 0FCFA8 7F0C8478 3C0C8005 */  lui   $t4, %hi(g_TexFormatNumChannels) 
/* 0FCFAC 7F0C847C 258C9178 */  addiu $t4, %lo(g_TexFormatNumChannels) # addiu $t4, $t4, -0x6e88
/* 0FCFB0 7F0C8480 028C9821 */  addu  $s3, $s4, $t4
/* 0FCFB4 7F0C8484 8E790000 */  lw    $t9, ($s3)
/* 0FCFB8 7F0C8488 00408025 */  move  $s0, $v0
/* 0FCFBC 7F0C848C 03C02025 */  move  $a0, $fp
/* 0FCFC0 7F0C8490 03360019 */  multu $t9, $s6
/* 0FCFC4 7F0C8494 0000C012 */  mflo  $t8
/* 0FCFC8 7F0C8498 00000000 */  nop   
/* 0FCFCC 7F0C849C 00000000 */  nop   
/* 0FCFD0 7F0C84A0 03170019 */  multu $t8, $s7
/* 0FCFD4 7F0C84A4 00002812 */  mflo  $a1
/* 0FCFD8 7F0C84A8 0FC325AF */  jal   texInflateRle
/* 0FCFDC 7F0C84AC 00000000 */   nop   
/* 0FCFE0 7F0C84B0 8E6D0000 */  lw    $t5, ($s3)
/* 0FCFE4 7F0C84B4 3C0E8005 */  lui   $t6, %hi(g_TexFormatChannelSizes)
/* 0FCFE8 7F0C84B8 01D47021 */  addu  $t6, $t6, $s4
/* 0FCFEC 7F0C84BC 01B70019 */  multu $t5, $s7
/* 0FCFF0 7F0C84C0 8DCE91E0 */  lw    $t6, %lo(g_TexFormatChannelSizes)($t6)
/* 0FCFF4 7F0C84C4 03C02025 */  move  $a0, $fp
/* 0FCFF8 7F0C84C8 02C02825 */  move  $a1, $s6
/* 0FCFFC 7F0C84CC 02003825 */  move  $a3, $s0
/* 0FD000 7F0C84D0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0FD004 7F0C84D4 00003012 */  mflo  $a2
/* 0FD008 7F0C84D8 0FC32DF8 */  jal   texBlur
/* 0FD00C 7F0C84DC 00000000 */   nop   
/* 0FD010 7F0C84E0 3C0B8005 */  lui   $t3, %hi(g_TexFormatNumChannels+52)
/* 0FD014 7F0C84E4 01745821 */  addu  $t3, $t3, $s4
/* 0FD018 7F0C84E8 8D6B91AC */  lw    $t3, %lo(g_TexFormatNumChannels+52)($t3)
/* 0FD01C 7F0C84EC 00157880 */  sll   $t7, $s5, 2
/* 0FD020 7F0C84F0 01F57823 */  subu  $t7, $t7, $s5
/* 0FD024 7F0C84F4 11600003 */  beqz  $t3, .L7F0C8504
/* 0FD028 7F0C84F8 03CF2021 */   addu  $a0, $fp, $t7
/* 0FD02C 7F0C84FC 0FC32692 */  jal   texReadAlphaBits
/* 0FD030 7F0C8500 02A02825 */   move  $a1, $s5
.L7F0C8504:
/* 0FD034 7F0C8504 8FAC30AC */  lw    $t4, 0x30ac($sp)
/* 0FD038 7F0C8508 8FB90088 */  lw    $t9, 0x88($sp)
/* 0FD03C 7F0C850C 8FB80080 */  lw    $t8, 0x80($sp)
/* 0FD040 7F0C8510 03C02025 */  move  $a0, $fp
/* 0FD044 7F0C8514 01998021 */  addu  $s0, $t4, $t9
/* 0FD048 7F0C8518 02003825 */  move  $a3, $s0
/* 0FD04C 7F0C851C 02C02825 */  move  $a1, $s6
/* 0FD050 7F0C8520 02E03025 */  move  $a2, $s7
/* 0FD054 7F0C8524 0FC32769 */  jal   texChannelsToPixels
/* 0FD058 7F0C8528 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FD05C 7F0C852C 1000000B */  b     .L7F0C855C
/* 0FD060 7F0C8530 00408825 */   move  $s1, $v0
def_7F0C8054:
.L7F0C8534:
/* 0FD064 7F0C8534 3C0D8009 */  lui   $t5, %hi(dword_CODE_bss_8008D090) 
/* 0FD068 7F0C8538 8DADD090 */  lw    $t5, %lo(dword_CODE_bss_8008D090)($t5)
/* 0FD06C 7F0C853C 3C0F8009 */  lui   $t7, %hi(word_CODE_bss_8008C730) 
/* 0FD070 7F0C8540 25EFC730 */  addiu $t7, %lo(word_CODE_bss_8008C730) # addiu $t7, $t7, -0x38d0
/* 0FD074 7F0C8544 000D7100 */  sll   $t6, $t5, 4
/* 0FD078 7F0C8548 01CF1821 */  addu  $v1, $t6, $t7
/* 0FD07C 7F0C854C A0760001 */  sb    $s6, 1($v1)
/* 0FD080 7F0C8550 A0770008 */  sb    $s7, 8($v1)
.L7F0C8554:
/* 0FD084 7F0C8554 1000FFFF */  b     .L7F0C8554
/* 0FD088 7F0C8558 00000000 */   nop   
.L7F0C855C:
/* 0FD08C 7F0C855C 8FAC30B0 */  lw    $t4, 0x30b0($sp)
/* 0FD090 7F0C8560 24010001 */  li    $at, 1
/* 0FD094 7F0C8564 8FB930B4 */  lw    $t9, 0x30b4($sp)
/* 0FD098 7F0C8568 15810007 */  bne   $t4, $at, .L7F0C8588
/* 0FD09C 7F0C856C 00000000 */   nop   
/* 0FD0A0 7F0C8570 1B200005 */  blez  $t9, .L7F0C8588
/* 0FD0A4 7F0C8574 02002025 */   move  $a0, $s0
/* 0FD0A8 7F0C8578 02C02825 */  move  $a1, $s6
/* 0FD0AC 7F0C857C 02E03025 */  move  $a2, $s7
/* 0FD0B0 7F0C8580 0FC32D9F */  jal   texSwapAltRowBytes
/* 0FD0B4 7F0C8584 8FA70080 */   lw    $a3, 0x80($sp)
.L7F0C8588:
/* 0FD0B8 7F0C8588 3C028009 */  lui   $v0, %hi(img_bitcount)
/* 0FD0BC 7F0C858C 8FAD0088 */  lw    $t5, 0x88($sp)
/* 0FD0C0 7F0C8590 2442D0A8 */  addiu $v0, %lo(img_bitcount) # addiu $v0, $v0, -0x2f58
/* 0FD0C4 7F0C8594 8C4B0000 */  lw    $t3, ($v0)
/* 0FD0C8 7F0C8598 26310007 */  addiu $s1, $s1, 7
/* 0FD0CC 7F0C859C 2401FFF8 */  li    $at, -8
/* 0FD0D0 7F0C85A0 0221C024 */  and   $t8, $s1, $at
/* 0FD0D4 7F0C85A4 01B87021 */  addu  $t6, $t5, $t8
/* 0FD0D8 7F0C85A8 15600007 */  bnez  $t3, .L7F0C85C8
/* 0FD0DC 7F0C85AC AFAE0088 */   sw    $t6, 0x88($sp)
/* 0FD0E0 7F0C85B0 3C0F8009 */  lui   $t7, %hi(img_curpos) 
/* 0FD0E4 7F0C85B4 8DEFD0A0 */  lw    $t7, %lo(img_curpos)($t7)
/* 0FD0E8 7F0C85B8 3C018009 */  lui   $at, %hi(img_curpos)
/* 0FD0EC 7F0C85BC 25EC0001 */  addiu $t4, $t7, 1
/* 0FD0F0 7F0C85C0 10000002 */  b     .L7F0C85CC
/* 0FD0F4 7F0C85C4 AC2CD0A0 */   sw    $t4, %lo(img_curpos)($at)
.L7F0C85C8:
/* 0FD0F8 7F0C85C8 AC400000 */  sw    $zero, ($v0)
.L7F0C85CC:
/* 0FD0FC 7F0C85CC 8FB900A0 */  lw    $t9, 0xa0($sp)
/* 0FD100 7F0C85D0 8FAD009C */  lw    $t5, 0x9c($sp)
/* 0FD104 7F0C85D4 27380001 */  addiu $t8, $t9, 1
/* 0FD108 7F0C85D8 170DFE52 */  bne   $t8, $t5, .L7F0C7F24
/* 0FD10C 7F0C85DC AFB800A0 */   sw    $t8, 0xa0($sp)
/* 0FD110 7F0C85E0 3C088009 */  lui   $t0, %hi(dword_CODE_bss_8008D090) 
/* 0FD114 7F0C85E4 2508D090 */  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
/* 0FD118 7F0C85E8 AFB60098 */  sw    $s6, 0x98($sp)
/* 0FD11C 7F0C85EC AFB70094 */  sw    $s7, 0x94($sp)
/* 0FD120 7F0C85F0 8FAA30B4 */  lw    $t2, 0x30b4($sp)
/* 0FD124 7F0C85F4 8FA930B0 */  lw    $t1, 0x30b0($sp)
/* 0FD128 7F0C85F8 8FA730B8 */  lw    $a3, 0x30b8($sp)
/* 0FD12C 7F0C85FC 8FA60070 */  lw    $a2, 0x70($sp)
.L7F0C8600:
/* 0FD130 7F0C8600 8FB60098 */  lw    $s6, 0x98($sp)
/* 0FD134 7F0C8604 10C0000E */  beqz  $a2, .L7F0C8640
/* 0FD138 7F0C8608 8FB70094 */   lw    $s7, 0x94($sp)
/* 0FD13C 7F0C860C 8CEE000C */  lw    $t6, 0xc($a3)
/* 0FD140 7F0C8610 8D050000 */  lw    $a1, ($t0)
/* 0FD144 7F0C8614 3C018009 */  lui   $at, %hi(word_CODE_bss_8008C730)
/* 0FD148 7F0C8618 8DCB0000 */  lw    $t3, ($t6)
/* 0FD14C 7F0C861C 00056100 */  sll   $t4, $a1, 4
/* 0FD150 7F0C8620 002C0821 */  addu  $at, $at, $t4
/* 0FD154 7F0C8624 000B7D02 */  srl   $t7, $t3, 0x14
/* 0FD158 7F0C8628 A42FC730 */  sh    $t7, %lo(word_CODE_bss_8008C730)($at)
/* 0FD15C 7F0C862C 24B90001 */  addiu $t9, $a1, 1
/* 0FD160 7F0C8630 2B210096 */  slti  $at, $t9, 0x96
/* 0FD164 7F0C8634 14200002 */  bnez  $at, .L7F0C8640
/* 0FD168 7F0C8638 AD190000 */   sw    $t9, ($t0)
/* 0FD16C 7F0C863C AD000000 */  sw    $zero, ($t0)
.L7F0C8640:
/* 0FD170 7F0C8640 15200037 */  bnez  $t1, .L7F0C8720
/* 0FD174 7F0C8644 29410002 */   slti  $at, $t2, 2
/* 0FD178 7F0C8648 1420002E */  bnez  $at, .L7F0C8704
/* 0FD17C 7F0C864C 8FB430AC */   lw    $s4, 0x30ac($sp)
/* 0FD180 7F0C8650 8FAB30B4 */  lw    $t3, 0x30b4($sp)
/* 0FD184 7F0C8654 8FAD0088 */  lw    $t5, 0x88($sp)
/* 0FD188 7F0C8658 240E0001 */  li    $t6, 1
/* 0FD18C 7F0C865C 29610002 */  slti  $at, $t3, 2
/* 0FD190 7F0C8660 02C09025 */  move  $s2, $s6
/* 0FD194 7F0C8664 02E09825 */  move  $s3, $s7
/* 0FD198 7F0C8668 AFAE00A0 */  sw    $t6, 0xa0($sp)
/* 0FD19C 7F0C866C 1420001E */  bnez  $at, .L7F0C86E8
/* 0FD1A0 7F0C8670 028D8021 */   addu  $s0, $s4, $t5
.L7F0C8674:
/* 0FD1A4 7F0C8674 8FAF0080 */  lw    $t7, 0x80($sp)
/* 0FD1A8 7F0C8678 02802025 */  move  $a0, $s4
/* 0FD1AC 7F0C867C 02002825 */  move  $a1, $s0
/* 0FD1B0 7F0C8680 02403025 */  move  $a2, $s2
/* 0FD1B4 7F0C8684 02603825 */  move  $a3, $s3
/* 0FD1B8 7F0C8688 0FC321D5 */  jal   image_decompresion_related
/* 0FD1BC 7F0C868C AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FD1C0 7F0C8690 00408825 */  move  $s1, $v0
/* 0FD1C4 7F0C8694 02802025 */  move  $a0, $s4
/* 0FD1C8 7F0C8698 02402825 */  move  $a1, $s2
/* 0FD1CC 7F0C869C 02603025 */  move  $a2, $s3
/* 0FD1D0 7F0C86A0 0FC32D9F */  jal   texSwapAltRowBytes
/* 0FD1D4 7F0C86A4 8FA70080 */   lw    $a3, 0x80($sp)
/* 0FD1D8 7F0C86A8 8FAE00A0 */  lw    $t6, 0xa0($sp)
/* 0FD1DC 7F0C86AC 8FAC0088 */  lw    $t4, 0x88($sp)
/* 0FD1E0 7F0C86B0 8FAF30B4 */  lw    $t7, 0x30b4($sp)
/* 0FD1E4 7F0C86B4 26520001 */  addiu $s2, $s2, 1
/* 0FD1E8 7F0C86B8 26730001 */  addiu $s3, $s3, 1
/* 0FD1EC 7F0C86BC 0012C043 */  sra   $t8, $s2, 1
/* 0FD1F0 7F0C86C0 00136843 */  sra   $t5, $s3, 1
/* 0FD1F4 7F0C86C4 0200A025 */  move  $s4, $s0
/* 0FD1F8 7F0C86C8 25CB0001 */  addiu $t3, $t6, 1
/* 0FD1FC 7F0C86CC 0191C821 */  addu  $t9, $t4, $s1
/* 0FD200 7F0C86D0 AFAB00A0 */  sw    $t3, 0xa0($sp)
/* 0FD204 7F0C86D4 AFB90088 */  sw    $t9, 0x88($sp)
/* 0FD208 7F0C86D8 03009025 */  move  $s2, $t8
/* 0FD20C 7F0C86DC 01A09825 */  move  $s3, $t5
/* 0FD210 7F0C86E0 156FFFE4 */  bne   $t3, $t7, .L7F0C8674
/* 0FD214 7F0C86E4 02118021 */   addu  $s0, $s0, $s1
.L7F0C86E8:
/* 0FD218 7F0C86E8 02802025 */  move  $a0, $s4
/* 0FD21C 7F0C86EC 02402825 */  move  $a1, $s2
/* 0FD220 7F0C86F0 02603025 */  move  $a2, $s3
/* 0FD224 7F0C86F4 0FC32D9F */  jal   texSwapAltRowBytes
/* 0FD228 7F0C86F8 8FA70080 */   lw    $a3, 0x80($sp)
/* 0FD22C 7F0C86FC 10000009 */  b     .L7F0C8724
/* 0FD230 7F0C8700 8FA20088 */   lw    $v0, 0x88($sp)
.L7F0C8704:
/* 0FD234 7F0C8704 24010001 */  li    $at, 1
/* 0FD238 7F0C8708 15410005 */  bne   $t2, $at, .L7F0C8720
/* 0FD23C 7F0C870C 8FA430AC */   lw    $a0, 0x30ac($sp)
/* 0FD240 7F0C8710 02C02825 */  move  $a1, $s6
/* 0FD244 7F0C8714 02E03025 */  move  $a2, $s7
/* 0FD248 7F0C8718 0FC32D9F */  jal   texSwapAltRowBytes
/* 0FD24C 7F0C871C 8FA70080 */   lw    $a3, 0x80($sp)
.L7F0C8720:
/* 0FD250 7F0C8720 8FA20088 */  lw    $v0, 0x88($sp)
.L7F0C8724:
/* 0FD254 7F0C8724 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0FD258 7F0C8728 8FB00028 */  lw    $s0, 0x28($sp)
/* 0FD25C 7F0C872C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0FD260 7F0C8730 8FB20030 */  lw    $s2, 0x30($sp)
/* 0FD264 7F0C8734 8FB30034 */  lw    $s3, 0x34($sp)
/* 0FD268 7F0C8738 8FB40038 */  lw    $s4, 0x38($sp)
/* 0FD26C 7F0C873C 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0FD270 7F0C8740 8FB60040 */  lw    $s6, 0x40($sp)
/* 0FD274 7F0C8744 8FB70044 */  lw    $s7, 0x44($sp)
/* 0FD278 7F0C8748 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0FD27C 7F0C874C 03E00008 */  jr    $ra
/* 0FD280 7F0C8750 27BD30A8 */   addiu $sp, $sp, 0x30a8
)
#endif





#ifdef NONMATCHING
void image_decompresion_related(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BD58*/
glabel jpt_8005BD58
.word .L7F0C87CC
.word .L7F0C87F0
.word .L7F0C87CC
.word .L7F0C87F0
.word .L7F0C87F0
.word .L7F0C8814
.word .L7F0C8838
.word .L7F0C8814
.word .L7F0C8838

/*D:8005BD7C*/
glabel jpt_8005BD7C
.word .L7F0C887C
.word .L7F0C8A2C
.word .L7F0C887C
.word .L7F0C8A2C
.word .L7F0C8BE0
.word .L7F0C8D1C
.word .L7F0C8F00
.word .L7F0C8E34
.word .L7F0C9090
.text
glabel image_decompresion_related
/* 0FD284 7F0C8754 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0FD288 7F0C8758 8FA200C8 */  lw    $v0, 0xc8($sp)
/* 0FD28C 7F0C875C 24F90001 */  addiu $t9, $a3, 1
/* 0FD290 7F0C8760 AFB70020 */  sw    $s7, 0x20($sp)
/* 0FD294 7F0C8764 AFB6001C */  sw    $s6, 0x1c($sp)
/* 0FD298 7F0C8768 AFB50018 */  sw    $s5, 0x18($sp)
/* 0FD29C 7F0C876C AFB40014 */  sw    $s4, 0x14($sp)
/* 0FD2A0 7F0C8770 AFB10008 */  sw    $s1, 8($sp)
/* 0FD2A4 7F0C8774 AFB00004 */  sw    $s0, 4($sp)
/* 0FD2A8 7F0C8778 00196043 */  sra   $t4, $t9, 1
/* 0FD2AC 7F0C877C 2C410009 */  sltiu $at, $v0, 9
/* 0FD2B0 7F0C8780 00C0A825 */  move  $s5, $a2
/* 0FD2B4 7F0C8784 00E0B825 */  move  $s7, $a3
/* 0FD2B8 7F0C8788 AFBE0024 */  sw    $fp, 0x24($sp)
/* 0FD2BC 7F0C878C AFB30010 */  sw    $s3, 0x10($sp)
/* 0FD2C0 7F0C8790 AFB2000C */  sw    $s2, 0xc($sp)
/* 0FD2C4 7F0C8794 00A04825 */  move  $t1, $a1
/* 0FD2C8 7F0C8798 00A0B025 */  move  $s6, $a1
/* 0FD2CC 7F0C879C 00A08825 */  move  $s1, $a1
/* 0FD2D0 7F0C87A0 00801825 */  move  $v1, $a0
/* 0FD2D4 7F0C87A4 0080A025 */  move  $s4, $a0
/* 0FD2D8 7F0C87A8 00808025 */  move  $s0, $a0
/* 0FD2DC 7F0C87AC 1020002A */  beqz  $at, .L7F0C8858
/* 0FD2E0 7F0C87B0 AFAC004C */   sw    $t4, 0x4c($sp)
/* 0FD2E4 7F0C87B4 0002C080 */  sll   $t8, $v0, 2
/* 0FD2E8 7F0C87B8 3C018006 */  lui   $at, %hi(jpt_8005BD58)
/* 0FD2EC 7F0C87BC 00380821 */  addu  $at, $at, $t8
/* 0FD2F0 7F0C87C0 8C38BD58 */  lw    $t8, %lo(jpt_8005BD58)($at)
/* 0FD2F4 7F0C87C4 03000008 */  jr    $t8
/* 0FD2F8 7F0C87C8 00000000 */   nop   
.L7F0C87CC:
/* 0FD2FC 7F0C87CC 26AE0001 */  addiu $t6, $s5, 1
/* 0FD300 7F0C87D0 000EC843 */  sra   $t9, $t6, 1
/* 0FD304 7F0C87D4 272F0003 */  addiu $t7, $t9, 3
/* 0FD308 7F0C87D8 26B20003 */  addiu $s2, $s5, 3
/* 0FD30C 7F0C87DC 31F80FFC */  andi  $t8, $t7, 0xffc
/* 0FD310 7F0C87E0 324E0FFC */  andi  $t6, $s2, 0xffc
/* 0FD314 7F0C87E4 AFB800A8 */  sw    $t8, 0xa8($sp)
/* 0FD318 7F0C87E8 1000001B */  b     .L7F0C8858
/* 0FD31C 7F0C87EC AFAE00AC */   sw    $t6, 0xac($sp)
.L7F0C87F0:
/* 0FD320 7F0C87F0 26B90001 */  addiu $t9, $s5, 1
/* 0FD324 7F0C87F4 00197843 */  sra   $t7, $t9, 1
/* 0FD328 7F0C87F8 25F80003 */  addiu $t8, $t7, 3
/* 0FD32C 7F0C87FC 26B20003 */  addiu $s2, $s5, 3
/* 0FD330 7F0C8800 330E0FFC */  andi  $t6, $t8, 0xffc
/* 0FD334 7F0C8804 32590FFC */  andi  $t9, $s2, 0xffc
/* 0FD338 7F0C8808 AFAE00A8 */  sw    $t6, 0xa8($sp)
/* 0FD33C 7F0C880C 10000012 */  b     .L7F0C8858
/* 0FD340 7F0C8810 AFB900AC */   sw    $t9, 0xac($sp)
.L7F0C8814:
/* 0FD344 7F0C8814 26AF0001 */  addiu $t7, $s5, 1
/* 0FD348 7F0C8818 000FC043 */  sra   $t8, $t7, 1
/* 0FD34C 7F0C881C 270E0007 */  addiu $t6, $t8, 7
/* 0FD350 7F0C8820 26B20007 */  addiu $s2, $s5, 7
/* 0FD354 7F0C8824 31D90FF8 */  andi  $t9, $t6, 0xff8
/* 0FD358 7F0C8828 324F0FF8 */  andi  $t7, $s2, 0xff8
/* 0FD35C 7F0C882C AFB900A8 */  sw    $t9, 0xa8($sp)
/* 0FD360 7F0C8830 10000009 */  b     .L7F0C8858
/* 0FD364 7F0C8834 AFAF00AC */   sw    $t7, 0xac($sp)
.L7F0C8838:
/* 0FD368 7F0C8838 26B80001 */  addiu $t8, $s5, 1
/* 0FD36C 7F0C883C 00187043 */  sra   $t6, $t8, 1
/* 0FD370 7F0C8840 25D9000F */  addiu $t9, $t6, 0xf
/* 0FD374 7F0C8844 26B2000F */  addiu $s2, $s5, 0xf
/* 0FD378 7F0C8848 332F0FF0 */  andi  $t7, $t9, 0xff0
/* 0FD37C 7F0C884C 32580FF0 */  andi  $t8, $s2, 0xff0
/* 0FD380 7F0C8850 AFAF00A8 */  sw    $t7, 0xa8($sp)
/* 0FD384 7F0C8854 AFB800AC */  sw    $t8, 0xac($sp)
def_7F0C87C4:
.L7F0C8858:
/* 0FD388 7F0C8858 2C410009 */  sltiu $at, $v0, 9
/* 0FD38C 7F0C885C 10200250 */  beqz  $at, .L7F0C91A0
/* 0FD390 7F0C8860 8FB200AC */   lw    $s2, 0xac($sp)
/* 0FD394 7F0C8864 00027080 */  sll   $t6, $v0, 2
/* 0FD398 7F0C8868 3C018006 */  lui   $at, %hi(jpt_8005BD7C)
/* 0FD39C 7F0C886C 002E0821 */  addu  $at, $at, $t6
/* 0FD3A0 7F0C8870 8C2EBD7C */  lw    $t6, %lo(jpt_8005BD7C)($at)
/* 0FD3A4 7F0C8874 01C00008 */  jr    $t6
/* 0FD3A8 7F0C8878 00000000 */   nop   
.L7F0C887C:
/* 0FD3AC 7F0C887C 1AE00064 */  blez  $s7, .L7F0C8A10
/* 0FD3B0 7F0C8880 0000F025 */   move  $fp, $zero
/* 0FD3B4 7F0C8884 8FA400A8 */  lw    $a0, 0xa8($sp)
/* 0FD3B8 7F0C8888 02402825 */  move  $a1, $s2
/* 0FD3BC 7F0C888C 000578C0 */  sll   $t7, $a1, 3
/* 0FD3C0 7F0C8890 0004C880 */  sll   $t9, $a0, 2
/* 0FD3C4 7F0C8894 03202025 */  move  $a0, $t9
/* 0FD3C8 7F0C8898 01E02825 */  move  $a1, $t7
.L7F0C889C:
/* 0FD3CC 7F0C889C 27D80001 */  addiu $t8, $fp, 1
/* 0FD3D0 7F0C88A0 0317082A */  slt   $at, $t8, $s7
/* 0FD3D4 7F0C88A4 10200003 */  beqz  $at, .L7F0C88B4
/* 0FD3D8 7F0C88A8 00004025 */   move  $t0, $zero
/* 0FD3DC 7F0C88AC 10000002 */  b     .L7F0C88B8
/* 0FD3E0 7F0C88B0 02409825 */   move  $s3, $s2
.L7F0C88B4:
/* 0FD3E4 7F0C88B4 00009825 */  move  $s3, $zero
.L7F0C88B8:
/* 0FD3E8 7F0C88B8 1A400051 */  blez  $s2, .L7F0C8A00
/* 0FD3EC 7F0C88BC 27DE0002 */   addiu $fp, $fp, 2
/* 0FD3F0 7F0C88C0 00137080 */  sll   $t6, $s3, 2
/* 0FD3F4 7F0C88C4 006E6821 */  addu  $t5, $v1, $t6
/* 0FD3F8 7F0C88C8 01A08025 */  move  $s0, $t5
/* 0FD3FC 7F0C88CC 00603025 */  move  $a2, $v1
.L7F0C88D0:
/* 0FD400 7F0C88D0 25020001 */  addiu $v0, $t0, 1
/* 0FD404 7F0C88D4 0055082A */  slt   $at, $v0, $s5
/* 0FD408 7F0C88D8 10200003 */  beqz  $at, .L7F0C88E8
/* 0FD40C 7F0C88DC 01003825 */   move  $a3, $t0
/* 0FD410 7F0C88E0 10000001 */  b     .L7F0C88E8
/* 0FD414 7F0C88E4 00403825 */   move  $a3, $v0
.L7F0C88E8:
/* 0FD418 7F0C88E8 00075880 */  sll   $t3, $a3, 2
/* 0FD41C 7F0C88EC 006BC821 */  addu  $t9, $v1, $t3
/* 0FD420 7F0C88F0 8F2A0000 */  lw    $t2, ($t9)
/* 0FD424 7F0C88F4 8CC20000 */  lw    $v0, ($a2)
/* 0FD428 7F0C88F8 01AB7821 */  addu  $t7, $t5, $t3
/* 0FD42C 7F0C88FC 8E0C0000 */  lw    $t4, ($s0)
/* 0FD430 7F0C8900 8DF10000 */  lw    $s1, ($t7)
/* 0FD434 7F0C8904 000ACE02 */  srl   $t9, $t2, 0x18
/* 0FD438 7F0C8908 332F00FF */  andi  $t7, $t9, 0xff
/* 0FD43C 7F0C890C 0002C602 */  srl   $t8, $v0, 0x18
/* 0FD440 7F0C8910 330E00FF */  andi  $t6, $t8, 0xff
/* 0FD444 7F0C8914 01CFC021 */  addu  $t8, $t6, $t7
/* 0FD448 7F0C8918 000CCE02 */  srl   $t9, $t4, 0x18
/* 0FD44C 7F0C891C 332E00FF */  andi  $t6, $t9, 0xff
/* 0FD450 7F0C8920 030E7821 */  addu  $t7, $t8, $t6
/* 0FD454 7F0C8924 0011CE02 */  srl   $t9, $s1, 0x18
/* 0FD458 7F0C8928 333800FF */  andi  $t8, $t9, 0xff
/* 0FD45C 7F0C892C 01F87021 */  addu  $t6, $t7, $t8
/* 0FD460 7F0C8930 000E7882 */  srl   $t7, $t6, 2
/* 0FD464 7F0C8934 000FC600 */  sll   $t8, $t7, 0x18
/* 0FD468 7F0C8938 00027402 */  srl   $t6, $v0, 0x10
/* 0FD46C 7F0C893C 31D900FF */  andi  $t9, $t6, 0xff
/* 0FD470 7F0C8940 000A7C02 */  srl   $t7, $t2, 0x10
/* 0FD474 7F0C8944 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD478 7F0C8948 032E7821 */  addu  $t7, $t9, $t6
/* 0FD47C 7F0C894C 000CCC02 */  srl   $t9, $t4, 0x10
/* 0FD480 7F0C8950 332E00FF */  andi  $t6, $t9, 0xff
/* 0FD484 7F0C8954 01EEC821 */  addu  $t9, $t7, $t6
/* 0FD488 7F0C8958 00117C02 */  srl   $t7, $s1, 0x10
/* 0FD48C 7F0C895C 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD490 7F0C8960 032E7821 */  addu  $t7, $t9, $t6
/* 0FD494 7F0C8964 000FC882 */  srl   $t9, $t7, 2
/* 0FD498 7F0C8968 332E00FF */  andi  $t6, $t9, 0xff
/* 0FD49C 7F0C896C 000E7C00 */  sll   $t7, $t6, 0x10
/* 0FD4A0 7F0C8970 030FC825 */  or    $t9, $t8, $t7
/* 0FD4A4 7F0C8974 00027202 */  srl   $t6, $v0, 8
/* 0FD4A8 7F0C8978 31D800FF */  andi  $t8, $t6, 0xff
/* 0FD4AC 7F0C897C 000A7A02 */  srl   $t7, $t2, 8
/* 0FD4B0 7F0C8980 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD4B4 7F0C8984 030E7821 */  addu  $t7, $t8, $t6
/* 0FD4B8 7F0C8988 000CC202 */  srl   $t8, $t4, 8
/* 0FD4BC 7F0C898C 330E00FF */  andi  $t6, $t8, 0xff
/* 0FD4C0 7F0C8990 01EEC021 */  addu  $t8, $t7, $t6
/* 0FD4C4 7F0C8994 00117A02 */  srl   $t7, $s1, 8
/* 0FD4C8 7F0C8998 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD4CC 7F0C899C 030E7821 */  addu  $t7, $t8, $t6
/* 0FD4D0 7F0C89A0 000FC082 */  srl   $t8, $t7, 2
/* 0FD4D4 7F0C89A4 330E00FF */  andi  $t6, $t8, 0xff
/* 0FD4D8 7F0C89A8 000E7A00 */  sll   $t7, $t6, 8
/* 0FD4DC 7F0C89AC 032FC025 */  or    $t8, $t9, $t7
/* 0FD4E0 7F0C89B0 315900FF */  andi  $t9, $t2, 0xff
/* 0FD4E4 7F0C89B4 304E00FF */  andi  $t6, $v0, 0xff
/* 0FD4E8 7F0C89B8 01D97821 */  addu  $t7, $t6, $t9
/* 0FD4EC 7F0C89BC 318E00FF */  andi  $t6, $t4, 0xff
/* 0FD4F0 7F0C89C0 01EEC821 */  addu  $t9, $t7, $t6
/* 0FD4F4 7F0C89C4 322F00FF */  andi  $t7, $s1, 0xff
/* 0FD4F8 7F0C89C8 032F7021 */  addu  $t6, $t9, $t7
/* 0FD4FC 7F0C89CC 25D90001 */  addiu $t9, $t6, 1
/* 0FD500 7F0C89D0 00197882 */  srl   $t7, $t9, 2
/* 0FD504 7F0C89D4 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD508 7F0C89D8 00087843 */  sra   $t7, $t0, 1
/* 0FD50C 7F0C89DC 030EC825 */  or    $t9, $t8, $t6
/* 0FD510 7F0C89E0 25080002 */  addiu $t0, $t0, 2
/* 0FD514 7F0C89E4 000FC080 */  sll   $t8, $t7, 2
/* 0FD518 7F0C89E8 0112082A */  slt   $at, $t0, $s2
/* 0FD51C 7F0C89EC 01387021 */  addu  $t6, $t1, $t8
/* 0FD520 7F0C89F0 24C60008 */  addiu $a2, $a2, 8
/* 0FD524 7F0C89F4 26100008 */  addiu $s0, $s0, 8
/* 0FD528 7F0C89F8 1420FFB5 */  bnez  $at, .L7F0C88D0
/* 0FD52C 7F0C89FC ADD90000 */   sw    $t9, ($t6)
.L7F0C8A00:
/* 0FD530 7F0C8A00 03D7082A */  slt   $at, $fp, $s7
/* 0FD534 7F0C8A04 01244821 */  addu  $t1, $t1, $a0
/* 0FD538 7F0C8A08 1420FFA4 */  bnez  $at, .L7F0C889C
/* 0FD53C 7F0C8A0C 00651821 */   addu  $v1, $v1, $a1
.L7F0C8A10:
/* 0FD540 7F0C8A10 8FAF004C */  lw    $t7, 0x4c($sp)
/* 0FD544 7F0C8A14 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FD548 7F0C8A18 01F80019 */  multu $t7, $t8
/* 0FD54C 7F0C8A1C 00001012 */  mflo  $v0
/* 0FD550 7F0C8A20 0002C880 */  sll   $t9, $v0, 2
/* 0FD554 7F0C8A24 100001DF */  b     .L7F0C91A4
/* 0FD558 7F0C8A28 03201025 */   move  $v0, $t9
.L7F0C8A2C:
/* 0FD55C 7F0C8A2C 1AE00065 */  blez  $s7, .L7F0C8BC4
/* 0FD560 7F0C8A30 0000F025 */   move  $fp, $zero
/* 0FD564 7F0C8A34 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FD568 7F0C8A38 0012C880 */  sll   $t9, $s2, 2
/* 0FD56C 7F0C8A3C AFB90034 */  sw    $t9, 0x34($sp)
/* 0FD570 7F0C8A40 000E7840 */  sll   $t7, $t6, 1
/* 0FD574 7F0C8A44 AFAF0038 */  sw    $t7, 0x38($sp)
.L7F0C8A48:
/* 0FD578 7F0C8A48 27CE0001 */  addiu $t6, $fp, 1
/* 0FD57C 7F0C8A4C 01D7082A */  slt   $at, $t6, $s7
/* 0FD580 7F0C8A50 10200003 */  beqz  $at, .L7F0C8A60
/* 0FD584 7F0C8A54 00004025 */   move  $t0, $zero
/* 0FD588 7F0C8A58 10000002 */  b     .L7F0C8A64
/* 0FD58C 7F0C8A5C 02409825 */   move  $s3, $s2
.L7F0C8A60:
/* 0FD590 7F0C8A60 00009825 */  move  $s3, $zero
.L7F0C8A64:
/* 0FD594 7F0C8A64 1A400051 */  blez  $s2, .L7F0C8BAC
/* 0FD598 7F0C8A68 27DE0002 */   addiu $fp, $fp, 2
/* 0FD59C 7F0C8A6C 00137840 */  sll   $t7, $s3, 1
/* 0FD5A0 7F0C8A70 028F8821 */  addu  $s1, $s4, $t7
/* 0FD5A4 7F0C8A74 02208025 */  move  $s0, $s1
/* 0FD5A8 7F0C8A78 02806825 */  move  $t5, $s4
.L7F0C8A7C:
/* 0FD5AC 7F0C8A7C 25020001 */  addiu $v0, $t0, 1
/* 0FD5B0 7F0C8A80 0055082A */  slt   $at, $v0, $s5
/* 0FD5B4 7F0C8A84 10200003 */  beqz  $at, .L7F0C8A94
/* 0FD5B8 7F0C8A88 01003825 */   move  $a3, $t0
/* 0FD5BC 7F0C8A8C 10000001 */  b     .L7F0C8A94
/* 0FD5C0 7F0C8A90 00403825 */   move  $a3, $v0
.L7F0C8A94:
/* 0FD5C4 7F0C8A94 00073040 */  sll   $a2, $a3, 1
/* 0FD5C8 7F0C8A98 0286C021 */  addu  $t8, $s4, $a2
/* 0FD5CC 7F0C8A9C 970A0000 */  lhu   $t2, ($t8)
/* 0FD5D0 7F0C8AA0 95A90000 */  lhu   $t1, ($t5)
/* 0FD5D4 7F0C8AA4 0226C821 */  addu  $t9, $s1, $a2
/* 0FD5D8 7F0C8AA8 960B0000 */  lhu   $t3, ($s0)
/* 0FD5DC 7F0C8AAC 972C0000 */  lhu   $t4, ($t9)
/* 0FD5E0 7F0C8AB0 000AC2C3 */  sra   $t8, $t2, 0xb
/* 0FD5E4 7F0C8AB4 3319001F */  andi  $t9, $t8, 0x1f
/* 0FD5E8 7F0C8AB8 000972C3 */  sra   $t6, $t1, 0xb
/* 0FD5EC 7F0C8ABC 31CF001F */  andi  $t7, $t6, 0x1f
/* 0FD5F0 7F0C8AC0 01F97021 */  addu  $t6, $t7, $t9
/* 0FD5F4 7F0C8AC4 000BC2C3 */  sra   $t8, $t3, 0xb
/* 0FD5F8 7F0C8AC8 330F001F */  andi  $t7, $t8, 0x1f
/* 0FD5FC 7F0C8ACC 01CFC821 */  addu  $t9, $t6, $t7
/* 0FD600 7F0C8AD0 000CC2C3 */  sra   $t8, $t4, 0xb
/* 0FD604 7F0C8AD4 330E001F */  andi  $t6, $t8, 0x1f
/* 0FD608 7F0C8AD8 032E7821 */  addu  $t7, $t9, $t6
/* 0FD60C 7F0C8ADC 000FC883 */  sra   $t9, $t7, 2
/* 0FD610 7F0C8AE0 001972C0 */  sll   $t6, $t9, 0xb
/* 0FD614 7F0C8AE4 00097983 */  sra   $t7, $t1, 6
/* 0FD618 7F0C8AE8 31F8001F */  andi  $t8, $t7, 0x1f
/* 0FD61C 7F0C8AEC 000AC983 */  sra   $t9, $t2, 6
/* 0FD620 7F0C8AF0 332F001F */  andi  $t7, $t9, 0x1f
/* 0FD624 7F0C8AF4 030FC821 */  addu  $t9, $t8, $t7
/* 0FD628 7F0C8AF8 000BC183 */  sra   $t8, $t3, 6
/* 0FD62C 7F0C8AFC 330F001F */  andi  $t7, $t8, 0x1f
/* 0FD630 7F0C8B00 032FC021 */  addu  $t8, $t9, $t7
/* 0FD634 7F0C8B04 000CC983 */  sra   $t9, $t4, 6
/* 0FD638 7F0C8B08 332F001F */  andi  $t7, $t9, 0x1f
/* 0FD63C 7F0C8B0C 030FC821 */  addu  $t9, $t8, $t7
/* 0FD640 7F0C8B10 0019C083 */  sra   $t8, $t9, 2
/* 0FD644 7F0C8B14 330F001F */  andi  $t7, $t8, 0x1f
/* 0FD648 7F0C8B18 000FC980 */  sll   $t9, $t7, 6
/* 0FD64C 7F0C8B1C 01D9C025 */  or    $t8, $t6, $t9
/* 0FD650 7F0C8B20 00097843 */  sra   $t7, $t1, 1
/* 0FD654 7F0C8B24 31EE001F */  andi  $t6, $t7, 0x1f
/* 0FD658 7F0C8B28 000AC843 */  sra   $t9, $t2, 1
/* 0FD65C 7F0C8B2C 332F001F */  andi  $t7, $t9, 0x1f
/* 0FD660 7F0C8B30 01CFC821 */  addu  $t9, $t6, $t7
/* 0FD664 7F0C8B34 000B7043 */  sra   $t6, $t3, 1
/* 0FD668 7F0C8B38 31CF001F */  andi  $t7, $t6, 0x1f
/* 0FD66C 7F0C8B3C 032F7021 */  addu  $t6, $t9, $t7
/* 0FD670 7F0C8B40 000CC843 */  sra   $t9, $t4, 1
/* 0FD674 7F0C8B44 332F001F */  andi  $t7, $t9, 0x1f
/* 0FD678 7F0C8B48 01CFC821 */  addu  $t9, $t6, $t7
/* 0FD67C 7F0C8B4C 00197083 */  sra   $t6, $t9, 2
/* 0FD680 7F0C8B50 31CF001F */  andi  $t7, $t6, 0x1f
/* 0FD684 7F0C8B54 000FC840 */  sll   $t9, $t7, 1
/* 0FD688 7F0C8B58 03197025 */  or    $t6, $t8, $t9
/* 0FD68C 7F0C8B5C 31580001 */  andi  $t8, $t2, 1
/* 0FD690 7F0C8B60 312F0001 */  andi  $t7, $t1, 1
/* 0FD694 7F0C8B64 01F8C821 */  addu  $t9, $t7, $t8
/* 0FD698 7F0C8B68 316F0001 */  andi  $t7, $t3, 1
/* 0FD69C 7F0C8B6C 032FC021 */  addu  $t8, $t9, $t7
/* 0FD6A0 7F0C8B70 31990001 */  andi  $t9, $t4, 1
/* 0FD6A4 7F0C8B74 03197821 */  addu  $t7, $t8, $t9
/* 0FD6A8 7F0C8B78 25F80002 */  addiu $t8, $t7, 2
/* 0FD6AC 7F0C8B7C 0018C883 */  sra   $t9, $t8, 2
/* 0FD6B0 7F0C8B80 332F0001 */  andi  $t7, $t9, 1
/* 0FD6B4 7F0C8B84 0008C843 */  sra   $t9, $t0, 1
/* 0FD6B8 7F0C8B88 01CFC025 */  or    $t8, $t6, $t7
/* 0FD6BC 7F0C8B8C 25080002 */  addiu $t0, $t0, 2
/* 0FD6C0 7F0C8B90 00197040 */  sll   $t6, $t9, 1
/* 0FD6C4 7F0C8B94 0112082A */  slt   $at, $t0, $s2
/* 0FD6C8 7F0C8B98 02CE7821 */  addu  $t7, $s6, $t6
/* 0FD6CC 7F0C8B9C 25AD0004 */  addiu $t5, $t5, 4
/* 0FD6D0 7F0C8BA0 26100004 */  addiu $s0, $s0, 4
/* 0FD6D4 7F0C8BA4 1420FFB5 */  bnez  $at, .L7F0C8A7C
/* 0FD6D8 7F0C8BA8 A5F80000 */   sh    $t8, ($t7)
.L7F0C8BAC:
/* 0FD6DC 7F0C8BAC 8FB90038 */  lw    $t9, 0x38($sp)
/* 0FD6E0 7F0C8BB0 8FAE0034 */  lw    $t6, 0x34($sp)
/* 0FD6E4 7F0C8BB4 03D7082A */  slt   $at, $fp, $s7
/* 0FD6E8 7F0C8BB8 02D9B021 */  addu  $s6, $s6, $t9
/* 0FD6EC 7F0C8BBC 1420FFA2 */  bnez  $at, .L7F0C8A48
/* 0FD6F0 7F0C8BC0 028EA021 */   addu  $s4, $s4, $t6
.L7F0C8BC4:
/* 0FD6F4 7F0C8BC4 8FB8004C */  lw    $t8, 0x4c($sp)
/* 0FD6F8 7F0C8BC8 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FD6FC 7F0C8BCC 030F0019 */  multu $t8, $t7
/* 0FD700 7F0C8BD0 00001012 */  mflo  $v0
/* 0FD704 7F0C8BD4 0002C840 */  sll   $t9, $v0, 1
/* 0FD708 7F0C8BD8 10000172 */  b     .L7F0C91A4
/* 0FD70C 7F0C8BDC 03201025 */   move  $v0, $t9
.L7F0C8BE0:
/* 0FD710 7F0C8BE0 1AE00047 */  blez  $s7, .L7F0C8D00
/* 0FD714 7F0C8BE4 0000F025 */   move  $fp, $zero
/* 0FD718 7F0C8BE8 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FD71C 7F0C8BEC 0012C880 */  sll   $t9, $s2, 2
/* 0FD720 7F0C8BF0 AFB90034 */  sw    $t9, 0x34($sp)
/* 0FD724 7F0C8BF4 000EC040 */  sll   $t8, $t6, 1
/* 0FD728 7F0C8BF8 AFB80038 */  sw    $t8, 0x38($sp)
.L7F0C8BFC:
/* 0FD72C 7F0C8BFC 27CE0001 */  addiu $t6, $fp, 1
/* 0FD730 7F0C8C00 01D7082A */  slt   $at, $t6, $s7
/* 0FD734 7F0C8C04 10200003 */  beqz  $at, .L7F0C8C14
/* 0FD738 7F0C8C08 00004025 */   move  $t0, $zero
/* 0FD73C 7F0C8C0C 10000002 */  b     .L7F0C8C18
/* 0FD740 7F0C8C10 02409825 */   move  $s3, $s2
.L7F0C8C14:
/* 0FD744 7F0C8C14 00009825 */  move  $s3, $zero
.L7F0C8C18:
/* 0FD748 7F0C8C18 1A400033 */  blez  $s2, .L7F0C8CE8
/* 0FD74C 7F0C8C1C 27DE0002 */   addiu $fp, $fp, 2
/* 0FD750 7F0C8C20 0013C040 */  sll   $t8, $s3, 1
/* 0FD754 7F0C8C24 02988821 */  addu  $s1, $s4, $t8
/* 0FD758 7F0C8C28 02208025 */  move  $s0, $s1
/* 0FD75C 7F0C8C2C 02806825 */  move  $t5, $s4
.L7F0C8C30:
/* 0FD760 7F0C8C30 25020001 */  addiu $v0, $t0, 1
/* 0FD764 7F0C8C34 0055082A */  slt   $at, $v0, $s5
/* 0FD768 7F0C8C38 10200003 */  beqz  $at, .L7F0C8C48
/* 0FD76C 7F0C8C3C 01003825 */   move  $a3, $t0
/* 0FD770 7F0C8C40 10000001 */  b     .L7F0C8C48
/* 0FD774 7F0C8C44 00403825 */   move  $a3, $v0
.L7F0C8C48:
/* 0FD778 7F0C8C48 00073040 */  sll   $a2, $a3, 1
/* 0FD77C 7F0C8C4C 02867821 */  addu  $t7, $s4, $a2
/* 0FD780 7F0C8C50 95EA0000 */  lhu   $t2, ($t7)
/* 0FD784 7F0C8C54 95A90000 */  lhu   $t1, ($t5)
/* 0FD788 7F0C8C58 0226C821 */  addu  $t9, $s1, $a2
/* 0FD78C 7F0C8C5C 960B0000 */  lhu   $t3, ($s0)
/* 0FD790 7F0C8C60 972C0000 */  lhu   $t4, ($t9)
/* 0FD794 7F0C8C64 000A7A03 */  sra   $t7, $t2, 8
/* 0FD798 7F0C8C68 31F900FF */  andi  $t9, $t7, 0xff
/* 0FD79C 7F0C8C6C 00097203 */  sra   $t6, $t1, 8
/* 0FD7A0 7F0C8C70 31D800FF */  andi  $t8, $t6, 0xff
/* 0FD7A4 7F0C8C74 03197021 */  addu  $t6, $t8, $t9
/* 0FD7A8 7F0C8C78 000B7A03 */  sra   $t7, $t3, 8
/* 0FD7AC 7F0C8C7C 31F800FF */  andi  $t8, $t7, 0xff
/* 0FD7B0 7F0C8C80 01D8C821 */  addu  $t9, $t6, $t8
/* 0FD7B4 7F0C8C84 000C7A03 */  sra   $t7, $t4, 8
/* 0FD7B8 7F0C8C88 31EE00FF */  andi  $t6, $t7, 0xff
/* 0FD7BC 7F0C8C8C 032EC021 */  addu  $t8, $t9, $t6
/* 0FD7C0 7F0C8C90 0018C883 */  sra   $t9, $t8, 2
/* 0FD7C4 7F0C8C94 00197200 */  sll   $t6, $t9, 8
/* 0FD7C8 7F0C8C98 314F00FF */  andi  $t7, $t2, 0xff
/* 0FD7CC 7F0C8C9C 313800FF */  andi  $t8, $t1, 0xff
/* 0FD7D0 7F0C8CA0 030FC821 */  addu  $t9, $t8, $t7
/* 0FD7D4 7F0C8CA4 317800FF */  andi  $t8, $t3, 0xff
/* 0FD7D8 7F0C8CA8 03387821 */  addu  $t7, $t9, $t8
/* 0FD7DC 7F0C8CAC 319900FF */  andi  $t9, $t4, 0xff
/* 0FD7E0 7F0C8CB0 01F9C021 */  addu  $t8, $t7, $t9
/* 0FD7E4 7F0C8CB4 270F0001 */  addiu $t7, $t8, 1
/* 0FD7E8 7F0C8CB8 000FC883 */  sra   $t9, $t7, 2
/* 0FD7EC 7F0C8CBC 333800FF */  andi  $t8, $t9, 0xff
/* 0FD7F0 7F0C8CC0 0008C843 */  sra   $t9, $t0, 1
/* 0FD7F4 7F0C8CC4 01D87825 */  or    $t7, $t6, $t8
/* 0FD7F8 7F0C8CC8 25080002 */  addiu $t0, $t0, 2
/* 0FD7FC 7F0C8CCC 00197040 */  sll   $t6, $t9, 1
/* 0FD800 7F0C8CD0 0112082A */  slt   $at, $t0, $s2
/* 0FD804 7F0C8CD4 02CEC021 */  addu  $t8, $s6, $t6
/* 0FD808 7F0C8CD8 25AD0004 */  addiu $t5, $t5, 4
/* 0FD80C 7F0C8CDC 26100004 */  addiu $s0, $s0, 4
/* 0FD810 7F0C8CE0 1420FFD3 */  bnez  $at, .L7F0C8C30
/* 0FD814 7F0C8CE4 A70F0000 */   sh    $t7, ($t8)
.L7F0C8CE8:
/* 0FD818 7F0C8CE8 8FB90038 */  lw    $t9, 0x38($sp)
/* 0FD81C 7F0C8CEC 8FAE0034 */  lw    $t6, 0x34($sp)
/* 0FD820 7F0C8CF0 03D7082A */  slt   $at, $fp, $s7
/* 0FD824 7F0C8CF4 02D9B021 */  addu  $s6, $s6, $t9
/* 0FD828 7F0C8CF8 1420FFC0 */  bnez  $at, .L7F0C8BFC
/* 0FD82C 7F0C8CFC 028EA021 */   addu  $s4, $s4, $t6
.L7F0C8D00:
/* 0FD830 7F0C8D00 8FAF004C */  lw    $t7, 0x4c($sp)
/* 0FD834 7F0C8D04 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FD838 7F0C8D08 01F80019 */  multu $t7, $t8
/* 0FD83C 7F0C8D0C 00001012 */  mflo  $v0
/* 0FD840 7F0C8D10 0002C840 */  sll   $t9, $v0, 1
/* 0FD844 7F0C8D14 10000123 */  b     .L7F0C91A4
/* 0FD848 7F0C8D18 03201025 */   move  $v0, $t9
.L7F0C8D1C:
/* 0FD84C 7F0C8D1C 1AE0003F */  blez  $s7, .L7F0C8E1C
/* 0FD850 7F0C8D20 0000F025 */   move  $fp, $zero
/* 0FD854 7F0C8D24 0012A040 */  sll   $s4, $s2, 1
.L7F0C8D28:
/* 0FD858 7F0C8D28 27CE0001 */  addiu $t6, $fp, 1
/* 0FD85C 7F0C8D2C 01D7082A */  slt   $at, $t6, $s7
/* 0FD860 7F0C8D30 10200003 */  beqz  $at, .L7F0C8D40
/* 0FD864 7F0C8D34 00004025 */   move  $t0, $zero
/* 0FD868 7F0C8D38 10000002 */  b     .L7F0C8D44
/* 0FD86C 7F0C8D3C 02409825 */   move  $s3, $s2
.L7F0C8D40:
/* 0FD870 7F0C8D40 00009825 */  move  $s3, $zero
.L7F0C8D44:
/* 0FD874 7F0C8D44 1A400030 */  blez  $s2, .L7F0C8E08
/* 0FD878 7F0C8D48 27DE0002 */   addiu $fp, $fp, 2
/* 0FD87C 7F0C8D4C 02006025 */  move  $t4, $s0
/* 0FD880 7F0C8D50 02706821 */  addu  $t5, $s3, $s0
.L7F0C8D54:
/* 0FD884 7F0C8D54 25020001 */  addiu $v0, $t0, 1
/* 0FD888 7F0C8D58 0055082A */  slt   $at, $v0, $s5
/* 0FD88C 7F0C8D5C 10200003 */  beqz  $at, .L7F0C8D6C
/* 0FD890 7F0C8D60 01003825 */   move  $a3, $t0
/* 0FD894 7F0C8D64 10000001 */  b     .L7F0C8D6C
/* 0FD898 7F0C8D68 00403825 */   move  $a3, $v0
.L7F0C8D6C:
/* 0FD89C 7F0C8D6C 02077821 */  addu  $t7, $s0, $a3
/* 0FD8A0 7F0C8D70 91E90000 */  lbu   $t1, ($t7)
/* 0FD8A4 7F0C8D74 0267C021 */  addu  $t8, $s3, $a3
/* 0FD8A8 7F0C8D78 918B0000 */  lbu   $t3, ($t4)
/* 0FD8AC 7F0C8D7C 0310C821 */  addu  $t9, $t8, $s0
/* 0FD8B0 7F0C8D80 91AA0000 */  lbu   $t2, ($t5)
/* 0FD8B4 7F0C8D84 93260000 */  lbu   $a2, ($t9)
/* 0FD8B8 7F0C8D88 0009C103 */  sra   $t8, $t1, 4
/* 0FD8BC 7F0C8D8C 3319000F */  andi  $t9, $t8, 0xf
/* 0FD8C0 7F0C8D90 000B7103 */  sra   $t6, $t3, 4
/* 0FD8C4 7F0C8D94 31CF000F */  andi  $t7, $t6, 0xf
/* 0FD8C8 7F0C8D98 01F97021 */  addu  $t6, $t7, $t9
/* 0FD8CC 7F0C8D9C 000AC103 */  sra   $t8, $t2, 4
/* 0FD8D0 7F0C8DA0 330F000F */  andi  $t7, $t8, 0xf
/* 0FD8D4 7F0C8DA4 01CFC821 */  addu  $t9, $t6, $t7
/* 0FD8D8 7F0C8DA8 0006C103 */  sra   $t8, $a2, 4
/* 0FD8DC 7F0C8DAC 330E000F */  andi  $t6, $t8, 0xf
/* 0FD8E0 7F0C8DB0 032E7821 */  addu  $t7, $t9, $t6
/* 0FD8E4 7F0C8DB4 000FC080 */  sll   $t8, $t7, 2
/* 0FD8E8 7F0C8DB8 331900F0 */  andi  $t9, $t8, 0xf0
/* 0FD8EC 7F0C8DBC 312F000F */  andi  $t7, $t1, 0xf
/* 0FD8F0 7F0C8DC0 316E000F */  andi  $t6, $t3, 0xf
/* 0FD8F4 7F0C8DC4 01CFC021 */  addu  $t8, $t6, $t7
/* 0FD8F8 7F0C8DC8 314E000F */  andi  $t6, $t2, 0xf
/* 0FD8FC 7F0C8DCC 030E7821 */  addu  $t7, $t8, $t6
/* 0FD900 7F0C8DD0 30D8000F */  andi  $t8, $a2, 0xf
/* 0FD904 7F0C8DD4 01F87021 */  addu  $t6, $t7, $t8
/* 0FD908 7F0C8DD8 25CF0001 */  addiu $t7, $t6, 1
/* 0FD90C 7F0C8DDC 000FC083 */  sra   $t8, $t7, 2
/* 0FD910 7F0C8DE0 330E000F */  andi  $t6, $t8, 0xf
/* 0FD914 7F0C8DE4 0008C043 */  sra   $t8, $t0, 1
/* 0FD918 7F0C8DE8 25080002 */  addiu $t0, $t0, 2
/* 0FD91C 7F0C8DEC 032E7825 */  or    $t7, $t9, $t6
/* 0FD920 7F0C8DF0 0112082A */  slt   $at, $t0, $s2
/* 0FD924 7F0C8DF4 0238C821 */  addu  $t9, $s1, $t8
/* 0FD928 7F0C8DF8 258C0002 */  addiu $t4, $t4, 2
/* 0FD92C 7F0C8DFC 25AD0002 */  addiu $t5, $t5, 2
/* 0FD930 7F0C8E00 1420FFD4 */  bnez  $at, .L7F0C8D54
/* 0FD934 7F0C8E04 A32F0000 */   sb    $t7, ($t9)
.L7F0C8E08:
/* 0FD938 7F0C8E08 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FD93C 7F0C8E0C 03D7082A */  slt   $at, $fp, $s7
/* 0FD940 7F0C8E10 02148021 */  addu  $s0, $s0, $s4
/* 0FD944 7F0C8E14 1420FFC4 */  bnez  $at, .L7F0C8D28
/* 0FD948 7F0C8E18 022E8821 */   addu  $s1, $s1, $t6
.L7F0C8E1C:
/* 0FD94C 7F0C8E1C 8FB8004C */  lw    $t8, 0x4c($sp)
/* 0FD950 7F0C8E20 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FD954 7F0C8E24 030F0019 */  multu $t8, $t7
/* 0FD958 7F0C8E28 00001012 */  mflo  $v0
/* 0FD95C 7F0C8E2C 100000DE */  b     .L7F0C91A8
/* 0FD960 7F0C8E30 8FB00004 */   lw    $s0, 4($sp)
.L7F0C8E34:
/* 0FD964 7F0C8E34 1AE0002C */  blez  $s7, .L7F0C8EE8
/* 0FD968 7F0C8E38 0000F025 */   move  $fp, $zero
/* 0FD96C 7F0C8E3C 0012A040 */  sll   $s4, $s2, 1
.L7F0C8E40:
/* 0FD970 7F0C8E40 27D90001 */  addiu $t9, $fp, 1
/* 0FD974 7F0C8E44 0337082A */  slt   $at, $t9, $s7
/* 0FD978 7F0C8E48 10200003 */  beqz  $at, .L7F0C8E58
/* 0FD97C 7F0C8E4C 00004025 */   move  $t0, $zero
/* 0FD980 7F0C8E50 10000002 */  b     .L7F0C8E5C
/* 0FD984 7F0C8E54 02409825 */   move  $s3, $s2
.L7F0C8E58:
/* 0FD988 7F0C8E58 00009825 */  move  $s3, $zero
.L7F0C8E5C:
/* 0FD98C 7F0C8E5C 1A40001D */  blez  $s2, .L7F0C8ED4
/* 0FD990 7F0C8E60 27DE0002 */   addiu $fp, $fp, 2
/* 0FD994 7F0C8E64 02006025 */  move  $t4, $s0
/* 0FD998 7F0C8E68 02706821 */  addu  $t5, $s3, $s0
.L7F0C8E6C:
/* 0FD99C 7F0C8E6C 25020001 */  addiu $v0, $t0, 1
/* 0FD9A0 7F0C8E70 0055082A */  slt   $at, $v0, $s5
/* 0FD9A4 7F0C8E74 10200003 */  beqz  $at, .L7F0C8E84
/* 0FD9A8 7F0C8E78 01003825 */   move  $a3, $t0
/* 0FD9AC 7F0C8E7C 10000001 */  b     .L7F0C8E84
/* 0FD9B0 7F0C8E80 00403825 */   move  $a3, $v0
.L7F0C8E84:
/* 0FD9B4 7F0C8E84 02077021 */  addu  $t6, $s0, $a3
/* 0FD9B8 7F0C8E88 918B0000 */  lbu   $t3, ($t4)
/* 0FD9BC 7F0C8E8C 91C90000 */  lbu   $t1, ($t6)
/* 0FD9C0 7F0C8E90 0267C021 */  addu  $t8, $s3, $a3
/* 0FD9C4 7F0C8E94 91AA0000 */  lbu   $t2, ($t5)
/* 0FD9C8 7F0C8E98 03107821 */  addu  $t7, $t8, $s0
/* 0FD9CC 7F0C8E9C 91E60000 */  lbu   $a2, ($t7)
/* 0FD9D0 7F0C8EA0 0169C821 */  addu  $t9, $t3, $t1
/* 0FD9D4 7F0C8EA4 032A7021 */  addu  $t6, $t9, $t2
/* 0FD9D8 7F0C8EA8 01C6C021 */  addu  $t8, $t6, $a2
/* 0FD9DC 7F0C8EAC 270F0001 */  addiu $t7, $t8, 1
/* 0FD9E0 7F0C8EB0 0008C043 */  sra   $t8, $t0, 1
/* 0FD9E4 7F0C8EB4 25080002 */  addiu $t0, $t0, 2
/* 0FD9E8 7F0C8EB8 000F7083 */  sra   $t6, $t7, 2
/* 0FD9EC 7F0C8EBC 0112082A */  slt   $at, $t0, $s2
/* 0FD9F0 7F0C8EC0 02387821 */  addu  $t7, $s1, $t8
/* 0FD9F4 7F0C8EC4 258C0002 */  addiu $t4, $t4, 2
/* 0FD9F8 7F0C8EC8 25AD0002 */  addiu $t5, $t5, 2
/* 0FD9FC 7F0C8ECC 1420FFE7 */  bnez  $at, .L7F0C8E6C
/* 0FDA00 7F0C8ED0 A1EE0000 */   sb    $t6, ($t7)
.L7F0C8ED4:
/* 0FDA04 7F0C8ED4 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0FDA08 7F0C8ED8 03D7082A */  slt   $at, $fp, $s7
/* 0FDA0C 7F0C8EDC 02148021 */  addu  $s0, $s0, $s4
/* 0FDA10 7F0C8EE0 1420FFD7 */  bnez  $at, .L7F0C8E40
/* 0FDA14 7F0C8EE4 02398821 */   addu  $s1, $s1, $t9
.L7F0C8EE8:
/* 0FDA18 7F0C8EE8 8FB8004C */  lw    $t8, 0x4c($sp)
/* 0FDA1C 7F0C8EEC 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FDA20 7F0C8EF0 030E0019 */  multu $t8, $t6
/* 0FDA24 7F0C8EF4 00001012 */  mflo  $v0
/* 0FDA28 7F0C8EF8 100000AB */  b     .L7F0C91A8
/* 0FDA2C 7F0C8EFC 8FB00004 */   lw    $s0, 4($sp)
.L7F0C8F00:
/* 0FDA30 7F0C8F00 1AE0005D */  blez  $s7, .L7F0C9078
/* 0FDA34 7F0C8F04 0000F025 */   move  $fp, $zero
/* 0FDA38 7F0C8F08 8FB400A8 */  lw    $s4, 0xa8($sp)
/* 0FDA3C 7F0C8F0C 00147843 */  sra   $t7, $s4, 1
/* 0FDA40 7F0C8F10 01E0A025 */  move  $s4, $t7
.L7F0C8F14:
/* 0FDA44 7F0C8F14 1A400053 */  blez  $s2, .L7F0C9064
/* 0FDA48 7F0C8F18 00004025 */   move  $t0, $zero
/* 0FDA4C 7F0C8F1C 27C70001 */  addiu $a3, $fp, 1
.L7F0C8F20:
/* 0FDA50 7F0C8F20 00086843 */  sra   $t5, $t0, 1
/* 0FDA54 7F0C8F24 01B01021 */  addu  $v0, $t5, $s0
/* 0FDA58 7F0C8F28 00F7082A */  slt   $at, $a3, $s7
/* 0FDA5C 7F0C8F2C 10200003 */  beqz  $at, .L7F0C8F3C
/* 0FDA60 7F0C8F30 904B0000 */   lbu   $t3, ($v0)
/* 0FDA64 7F0C8F34 10000002 */  b     .L7F0C8F40
/* 0FDA68 7F0C8F38 00129843 */   sra   $s3, $s2, 1
.L7F0C8F3C:
/* 0FDA6C 7F0C8F3C 00009825 */  move  $s3, $zero
.L7F0C8F40:
/* 0FDA70 7F0C8F40 026DC821 */  addu  $t9, $s3, $t5
/* 0FDA74 7F0C8F44 0330C021 */  addu  $t8, $t9, $s0
/* 0FDA78 7F0C8F48 00F7082A */  slt   $at, $a3, $s7
/* 0FDA7C 7F0C8F4C 93090000 */  lbu   $t1, ($t8)
/* 0FDA80 7F0C8F50 10200003 */  beqz  $at, .L7F0C8F60
/* 0FDA84 7F0C8F54 904A0001 */   lbu   $t2, 1($v0)
/* 0FDA88 7F0C8F58 10000002 */  b     .L7F0C8F64
/* 0FDA8C 7F0C8F5C 00129843 */   sra   $s3, $s2, 1
.L7F0C8F60:
/* 0FDA90 7F0C8F60 00009825 */  move  $s3, $zero
.L7F0C8F64:
/* 0FDA94 7F0C8F64 026D7021 */  addu  $t6, $s3, $t5
/* 0FDA98 7F0C8F68 01D07821 */  addu  $t7, $t6, $s0
/* 0FDA9C 7F0C8F6C 91E60001 */  lbu   $a2, 1($t7)
/* 0FDAA0 7F0C8F70 000B7043 */  sra   $t6, $t3, 1
/* 0FDAA4 7F0C8F74 31CF0007 */  andi  $t7, $t6, 7
/* 0FDAA8 7F0C8F78 000BC943 */  sra   $t9, $t3, 5
/* 0FDAAC 7F0C8F7C 33380007 */  andi  $t8, $t9, 7
/* 0FDAB0 7F0C8F80 030FC821 */  addu  $t9, $t8, $t7
/* 0FDAB4 7F0C8F84 00097143 */  sra   $t6, $t1, 5
/* 0FDAB8 7F0C8F88 31D80007 */  andi  $t8, $t6, 7
/* 0FDABC 7F0C8F8C 03387821 */  addu  $t7, $t9, $t8
/* 0FDAC0 7F0C8F90 00097043 */  sra   $t6, $t1, 1
/* 0FDAC4 7F0C8F94 31D90007 */  andi  $t9, $t6, 7
/* 0FDAC8 7F0C8F98 01F9C021 */  addu  $t8, $t7, $t9
/* 0FDACC 7F0C8F9C 001870C0 */  sll   $t6, $t8, 3
/* 0FDAD0 7F0C8FA0 31CF00E0 */  andi  $t7, $t6, 0xe0
/* 0FDAD4 7F0C8FA4 000AC943 */  sra   $t9, $t2, 5
/* 0FDAD8 7F0C8FA8 33380007 */  andi  $t8, $t9, 7
/* 0FDADC 7F0C8FAC 000A7043 */  sra   $t6, $t2, 1
/* 0FDAE0 7F0C8FB0 31D90007 */  andi  $t9, $t6, 7
/* 0FDAE4 7F0C8FB4 03197021 */  addu  $t6, $t8, $t9
/* 0FDAE8 7F0C8FB8 0006C143 */  sra   $t8, $a2, 5
/* 0FDAEC 7F0C8FBC 33190007 */  andi  $t9, $t8, 7
/* 0FDAF0 7F0C8FC0 01D9C021 */  addu  $t8, $t6, $t9
/* 0FDAF4 7F0C8FC4 00067043 */  sra   $t6, $a2, 1
/* 0FDAF8 7F0C8FC8 31D90007 */  andi  $t9, $t6, 7
/* 0FDAFC 7F0C8FCC 03197021 */  addu  $t6, $t8, $t9
/* 0FDB00 7F0C8FD0 000EC043 */  sra   $t8, $t6, 1
/* 0FDB04 7F0C8FD4 3319000E */  andi  $t9, $t8, 0xe
/* 0FDB08 7F0C8FD8 01F97025 */  or    $t6, $t7, $t9
/* 0FDB0C 7F0C8FDC 000BC103 */  sra   $t8, $t3, 4
/* 0FDB10 7F0C8FE0 330F0001 */  andi  $t7, $t8, 1
/* 0FDB14 7F0C8FE4 31790001 */  andi  $t9, $t3, 1
/* 0FDB18 7F0C8FE8 01F9C021 */  addu  $t8, $t7, $t9
/* 0FDB1C 7F0C8FEC 00097903 */  sra   $t7, $t1, 4
/* 0FDB20 7F0C8FF0 31F90001 */  andi  $t9, $t7, 1
/* 0FDB24 7F0C8FF4 03197821 */  addu  $t7, $t8, $t9
/* 0FDB28 7F0C8FF8 31380001 */  andi  $t8, $t1, 1
/* 0FDB2C 7F0C8FFC 01F8C821 */  addu  $t9, $t7, $t8
/* 0FDB30 7F0C9000 272F0001 */  addiu $t7, $t9, 1
/* 0FDB34 7F0C9004 000FC080 */  sll   $t8, $t7, 2
/* 0FDB38 7F0C9008 33190010 */  andi  $t9, $t8, 0x10
/* 0FDB3C 7F0C900C 000A7903 */  sra   $t7, $t2, 4
/* 0FDB40 7F0C9010 31F80001 */  andi  $t8, $t7, 1
/* 0FDB44 7F0C9014 314F0001 */  andi  $t7, $t2, 1
/* 0FDB48 7F0C9018 030FC021 */  addu  $t8, $t8, $t7
/* 0FDB4C 7F0C901C AFAE0028 */  sw    $t6, 0x28($sp)
/* 0FDB50 7F0C9020 00067903 */  sra   $t7, $a2, 4
/* 0FDB54 7F0C9024 31EE0001 */  andi  $t6, $t7, 1
/* 0FDB58 7F0C9028 030E7021 */  addu  $t6, $t8, $t6
/* 0FDB5C 7F0C902C 30D80001 */  andi  $t8, $a2, 1
/* 0FDB60 7F0C9030 01D87821 */  addu  $t7, $t6, $t8
/* 0FDB64 7F0C9034 25EE0001 */  addiu $t6, $t7, 1
/* 0FDB68 7F0C9038 000EC083 */  sra   $t8, $t6, 2
/* 0FDB6C 7F0C903C 330F0001 */  andi  $t7, $t8, 1
/* 0FDB70 7F0C9040 8FB80028 */  lw    $t8, 0x28($sp)
/* 0FDB74 7F0C9044 032F7025 */  or    $t6, $t9, $t7
/* 0FDB78 7F0C9048 00087883 */  sra   $t7, $t0, 2
/* 0FDB7C 7F0C904C 25080004 */  addiu $t0, $t0, 4
/* 0FDB80 7F0C9050 030EC825 */  or    $t9, $t8, $t6
/* 0FDB84 7F0C9054 0112082A */  slt   $at, $t0, $s2
/* 0FDB88 7F0C9058 022FC021 */  addu  $t8, $s1, $t7
/* 0FDB8C 7F0C905C 1420FFB0 */  bnez  $at, .L7F0C8F20
/* 0FDB90 7F0C9060 A3190000 */   sb    $t9, ($t8)
.L7F0C9064:
/* 0FDB94 7F0C9064 27DE0002 */  addiu $fp, $fp, 2
/* 0FDB98 7F0C9068 03D7082A */  slt   $at, $fp, $s7
/* 0FDB9C 7F0C906C 02348821 */  addu  $s1, $s1, $s4
/* 0FDBA0 7F0C9070 1420FFA8 */  bnez  $at, .L7F0C8F14
/* 0FDBA4 7F0C9074 02128021 */   addu  $s0, $s0, $s2
.L7F0C9078:
/* 0FDBA8 7F0C9078 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FDBAC 7F0C907C 000E7843 */  sra   $t7, $t6, 1
/* 0FDBB0 7F0C9080 01EC0019 */  multu $t7, $t4
/* 0FDBB4 7F0C9084 00001012 */  mflo  $v0
/* 0FDBB8 7F0C9088 10000047 */  b     .L7F0C91A8
/* 0FDBBC 7F0C908C 8FB00004 */   lw    $s0, 4($sp)
.L7F0C9090:
/* 0FDBC0 7F0C9090 1AE0003D */  blez  $s7, .L7F0C9188
/* 0FDBC4 7F0C9094 0000F025 */   move  $fp, $zero
/* 0FDBC8 7F0C9098 8FB400A8 */  lw    $s4, 0xa8($sp)
/* 0FDBCC 7F0C909C 0014C843 */  sra   $t9, $s4, 1
/* 0FDBD0 7F0C90A0 0320A025 */  move  $s4, $t9
.L7F0C90A4:
/* 0FDBD4 7F0C90A4 1A400033 */  blez  $s2, .L7F0C9174
/* 0FDBD8 7F0C90A8 00004025 */   move  $t0, $zero
/* 0FDBDC 7F0C90AC 27C70001 */  addiu $a3, $fp, 1
.L7F0C90B0:
/* 0FDBE0 7F0C90B0 00086843 */  sra   $t5, $t0, 1
/* 0FDBE4 7F0C90B4 01B01021 */  addu  $v0, $t5, $s0
/* 0FDBE8 7F0C90B8 00F7082A */  slt   $at, $a3, $s7
/* 0FDBEC 7F0C90BC 10200003 */  beqz  $at, .L7F0C90CC
/* 0FDBF0 7F0C90C0 904B0000 */   lbu   $t3, ($v0)
/* 0FDBF4 7F0C90C4 10000002 */  b     .L7F0C90D0
/* 0FDBF8 7F0C90C8 00129843 */   sra   $s3, $s2, 1
.L7F0C90CC:
/* 0FDBFC 7F0C90CC 00009825 */  move  $s3, $zero
.L7F0C90D0:
/* 0FDC00 7F0C90D0 026DC021 */  addu  $t8, $s3, $t5
/* 0FDC04 7F0C90D4 03107021 */  addu  $t6, $t8, $s0
/* 0FDC08 7F0C90D8 00F7082A */  slt   $at, $a3, $s7
/* 0FDC0C 7F0C90DC 91C90000 */  lbu   $t1, ($t6)
/* 0FDC10 7F0C90E0 10200003 */  beqz  $at, .L7F0C90F0
/* 0FDC14 7F0C90E4 904A0001 */   lbu   $t2, 1($v0)
/* 0FDC18 7F0C90E8 10000002 */  b     .L7F0C90F4
/* 0FDC1C 7F0C90EC 00129843 */   sra   $s3, $s2, 1
.L7F0C90F0:
/* 0FDC20 7F0C90F0 00009825 */  move  $s3, $zero
.L7F0C90F4:
/* 0FDC24 7F0C90F4 026D7821 */  addu  $t7, $s3, $t5
/* 0FDC28 7F0C90F8 01F0C821 */  addu  $t9, $t7, $s0
/* 0FDC2C 7F0C90FC 000BC103 */  sra   $t8, $t3, 4
/* 0FDC30 7F0C9100 330E000F */  andi  $t6, $t8, 0xf
/* 0FDC34 7F0C9104 93260001 */  lbu   $a2, 1($t9)
/* 0FDC38 7F0C9108 316F000F */  andi  $t7, $t3, 0xf
/* 0FDC3C 7F0C910C 01CFC821 */  addu  $t9, $t6, $t7
/* 0FDC40 7F0C9110 0009C103 */  sra   $t8, $t1, 4
/* 0FDC44 7F0C9114 330E000F */  andi  $t6, $t8, 0xf
/* 0FDC48 7F0C9118 032E7821 */  addu  $t7, $t9, $t6
/* 0FDC4C 7F0C911C 3138000F */  andi  $t8, $t1, 0xf
/* 0FDC50 7F0C9120 01F8C821 */  addu  $t9, $t7, $t8
/* 0FDC54 7F0C9124 00197080 */  sll   $t6, $t9, 2
/* 0FDC58 7F0C9128 31CF00F0 */  andi  $t7, $t6, 0xf0
/* 0FDC5C 7F0C912C 000AC103 */  sra   $t8, $t2, 4
/* 0FDC60 7F0C9130 3319000F */  andi  $t9, $t8, 0xf
/* 0FDC64 7F0C9134 314E000F */  andi  $t6, $t2, 0xf
/* 0FDC68 7F0C9138 032EC021 */  addu  $t8, $t9, $t6
/* 0FDC6C 7F0C913C 0006C903 */  sra   $t9, $a2, 4
/* 0FDC70 7F0C9140 332E000F */  andi  $t6, $t9, 0xf
/* 0FDC74 7F0C9144 030EC821 */  addu  $t9, $t8, $t6
/* 0FDC78 7F0C9148 30D8000F */  andi  $t8, $a2, 0xf
/* 0FDC7C 7F0C914C 03387021 */  addu  $t6, $t9, $t8
/* 0FDC80 7F0C9150 000EC883 */  sra   $t9, $t6, 2
/* 0FDC84 7F0C9154 3338000F */  andi  $t8, $t9, 0xf
/* 0FDC88 7F0C9158 0008C883 */  sra   $t9, $t0, 2
/* 0FDC8C 7F0C915C 25080004 */  addiu $t0, $t0, 4
/* 0FDC90 7F0C9160 01F87025 */  or    $t6, $t7, $t8
/* 0FDC94 7F0C9164 0112082A */  slt   $at, $t0, $s2
/* 0FDC98 7F0C9168 02397821 */  addu  $t7, $s1, $t9
/* 0FDC9C 7F0C916C 1420FFD0 */  bnez  $at, .L7F0C90B0
/* 0FDCA0 7F0C9170 A1EE0000 */   sb    $t6, ($t7)
.L7F0C9174:
/* 0FDCA4 7F0C9174 27DE0002 */  addiu $fp, $fp, 2
/* 0FDCA8 7F0C9178 03D7082A */  slt   $at, $fp, $s7
/* 0FDCAC 7F0C917C 02348821 */  addu  $s1, $s1, $s4
/* 0FDCB0 7F0C9180 1420FFC8 */  bnez  $at, .L7F0C90A4
/* 0FDCB4 7F0C9184 02128021 */   addu  $s0, $s0, $s2
.L7F0C9188:
/* 0FDCB8 7F0C9188 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FDCBC 7F0C918C 0018C843 */  sra   $t9, $t8, 1
/* 0FDCC0 7F0C9190 032C0019 */  multu $t9, $t4
/* 0FDCC4 7F0C9194 00001012 */  mflo  $v0
/* 0FDCC8 7F0C9198 10000003 */  b     .L7F0C91A8
/* 0FDCCC 7F0C919C 8FB00004 */   lw    $s0, 4($sp)
def_7F0C8874:
.L7F0C91A0:
/* 0FDCD0 7F0C91A0 00001025 */  move  $v0, $zero
.L7F0C91A4:
/* 0FDCD4 7F0C91A4 8FB00004 */  lw    $s0, 4($sp)
.L7F0C91A8:
/* 0FDCD8 7F0C91A8 8FB10008 */  lw    $s1, 8($sp)
/* 0FDCDC 7F0C91AC 8FB2000C */  lw    $s2, 0xc($sp)
/* 0FDCE0 7F0C91B0 8FB30010 */  lw    $s3, 0x10($sp)
/* 0FDCE4 7F0C91B4 8FB40014 */  lw    $s4, 0x14($sp)
/* 0FDCE8 7F0C91B8 8FB50018 */  lw    $s5, 0x18($sp)
/* 0FDCEC 7F0C91BC 8FB6001C */  lw    $s6, 0x1c($sp)
/* 0FDCF0 7F0C91C0 8FB70020 */  lw    $s7, 0x20($sp)
/* 0FDCF4 7F0C91C4 8FBE0024 */  lw    $fp, 0x24($sp)
/* 0FDCF8 7F0C91C8 03E00008 */  jr    $ra
/* 0FDCFC 7F0C91CC 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif






/**
 * Inflate Huffman data.
 *
 * This function operates on single channels rather than whole colours.
 * For example, for an RGBA32 image this function may be called once for each
 * channel with chansize = 256. This means the resulting data is in the format
 * RRR...GGG...BBB...AAA..., and the caller must convert it into a proper pixel
 * format.
 *
 * A typical Huffman implementation stores a tree, where each node contains
 * the lookup value and its frequency (number of uses). However, Rare's
 * implementation only stores a list of frequencies. It uses the chansize
 * to know how many values there are.
 */
void texInflateHuffman(u8 *dst, s32 numiterations, s32 chansize)
{
	u16 frequencies[2048];
	s16 nodes[2048][2];
	s32 i;
	s32 rootindex;
	s32 sum;
	u16 minfreq1;
	u16 minfreq2;
	s32 minindex1; // 5c
	s32 minindex2; // 58
	s32  done = 0;

	// Read the frequencies list
	for (i = 0; i < chansize; i++) {
		frequencies[i] = texReadBits(8);
	}

	// Initialise the tree
	for (i = 0; i < 2048; i++) {
		nodes[i][0] = -1;
		nodes[i][1] = -1;
	}

	// Find the two smallest frequencies
	minfreq1 = 9999;
	minfreq2 = 9999;

	for (i = 0; i < chansize; i++) {
		if (frequencies[i] < minfreq1) {
			if (minfreq2 < minfreq1) {
				minfreq1 = frequencies[i];
				minindex1 = i;
			} else {
				minfreq2 = frequencies[i];
				minindex2 = i;
			}
		} else if (frequencies[i] < minfreq2) {
			minfreq2 = frequencies[i];
			minindex2 = i;
		}
	}

	// Build the tree.
	// For each node in tree, a branch value < 10000 means this branch
	// leads to another node, and the value is the target node's index.
	// A branch value >= 10000 means the branch is a leaf node,
	// and the value is the channel value + 10000.
	while (!done) {
		sum = frequencies[minindex1] + frequencies[minindex2];

		if (sum == 0) {
			sum = 1;
		}

		frequencies[minindex1] = 9999;
		frequencies[minindex2] = 9999;

		if (nodes[minindex1][0] < 0 && nodes[minindex1][1] < 0) {
			nodes[minindex1][0] = minindex1 + 10000;
			rootindex = minindex1;
			frequencies[minindex1] = sum;

			if (nodes[minindex2][0] < 0 && nodes[minindex2][1] < 0) {
				nodes[minindex1][1] = minindex2 + 10000;
			} else {
				nodes[minindex1][1] = minindex2;
			}
		} else if (nodes[minindex2][0] < 0 && nodes[minindex2][1] < 0) {
			nodes[minindex2][0] = minindex2 + 10000;
			rootindex = minindex2;
			frequencies[minindex2] = sum;

			if (nodes[minindex1][0] < 0 && nodes[minindex1][1] < 0) {
				nodes[minindex2][1] = minindex1 + 10000;
			} else {
				nodes[minindex2][1] = minindex1;
			}
		} else {
			for (rootindex = 0; nodes[rootindex][0] >= 0 || nodes[rootindex][1] >= 0 || frequencies[rootindex] < 9999; rootindex++);

			frequencies[rootindex] = sum;
			nodes[rootindex][0] = minindex1;
			nodes[rootindex][1] = minindex2;
		}

		// Find the two smallest frequencies again for the next iteration
		minfreq1 = 9999;
		minfreq2 = 9999;

		for (i = 0; i < chansize; i++) {
			if (frequencies[i] < minfreq1) {
				if (minfreq1 > minfreq2) {
					minfreq1 = frequencies[i];
					minindex1 = i;
				} else {
					minfreq2 = frequencies[i];
					minindex2 = i;
				}
			} else if (frequencies[i] < minfreq2) {
				minfreq2 = frequencies[i];
				minindex2 = i;
			}
		}

		if (minfreq1 == 9999 || minfreq2 == 9999) {
			done = 1;
		}
	}

	// Read bits off the bitstring, traverse the tree
	// and write the channel values to dst
	for (i = 0; i < numiterations; i++) {
		s32 indexorvalue = rootindex;

		while (indexorvalue < 10000) {
			indexorvalue = nodes[indexorvalue][texReadBits(1)];
		}

		if (chansize <= 256) {
			dst[i] = indexorvalue - 10000;
		} else {
			u16 *tmp = (u16 *)dst;
			tmp[i] = indexorvalue - 10000;
		}
	}
}




/**
 * Inflate runlength-encoded data.
 *
 * This data consists of a 10 bit header followed by a list of directives,
 * where each directive can either be a literal block or a repeat (run) of
 * blocks within a sliding window.
 *
 * The header format is:
 *
 * 3 bits btfieldsize: The size in bits of the backtrack distance fields
 * 3 bits rlfieldsize: The size in bits of the runlen fields
 * 4 bits blocksize: The size in bits of each block of data
 *
 * In the data, the first bit is 0 if it's a literal block or 1 if it's a run.
 *
 * For literal blocks, the next <blocksize> bits should be read and appended to
 * the output stream.
 *
 * For runs, the next <btfieldsize> bits are the backtrack length (in blocks)
 * plus one, and the next <rlfieldsize> bits are the run length (in blocks)
 * minus a calculated fudge value.
 *
 * The fudge value is calculated based on the field sizes. For small runs it is
 * more space efficient to use multiple literal directives rather than a run
 * directive. Because of this, smaller runs are not used and the run lengths
 * in the data can be offset accordingly - this offset is the fudge value.
 *
 * Every run must be followed by a literal block without the 1-bit marker.
 * The algorithm does not support back to back runs.
 */
void texInflateRle(u8 *dst, s32 blockstotal)
{
	s32 btfieldsize = texReadBits(3);
	s32 rlfieldsize = texReadBits(3);
	s32 blocksize = texReadBits(4);
	s32 cost;
	s32 fudge;
	s32 blocksdone;
	s32 i;

	// Calculate the fudge value
	cost = btfieldsize + rlfieldsize + blocksize + 1;
	fudge = 0;

	while (cost > 0) {
		cost = cost - blocksize - 1;
		fudge++;
	}

	blocksdone = 0;

	while (blocksdone < blockstotal) {
		if (texReadBits(1) == 0) {
			// Found a literal directive
			if (blocksize <= 8) {
				dst[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			} else {
				u16 *tmp = (u16 *)dst;
				tmp[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			}
		} else {
			// Found a run directive
			s32 startblockindex = blocksdone - texReadBits(btfieldsize) - 1;
			s32 runnumblocks = texReadBits(rlfieldsize) + fudge;

			if (blocksize <= 8) {
				for (i = startblockindex; i < startblockindex + runnumblocks; i++) {
					dst[blocksdone] = dst[i];
					blocksdone++;
				}

				// The next instruction must be a literal
				dst[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			} else {
				u16 *tmp = (u16 *)dst;

				for (i = startblockindex; i < startblockindex + runnumblocks; i++) {
					tmp[blocksdone] = tmp[i];
					blocksdone++;
				}

				// The next instruction must be a literal
				tmp[blocksdone] = texReadBits(blocksize);
				blocksdone++;
			}
		}
	}
}




/**
 * Populate a lookup table by reading it out of the bit string.
 *
 * The first 11 bits denote the number of colours in the lookup table.
 * The data following this is a list of colours, where each colour is sized
 * according to the texture's format.
 *
 * This function does NOT work with pixel formats of 8 bits or less.
 */
s32 texBuildLookup(s8 *lookup, s32 bitsperpixel)
{
    s32 numcolors = texReadBits(11);
    s32 i;
    
    if (bitsperpixel <= 16)
    {
        u16 *image = (u16*)lookup;
        for (i = 0; i < numcolors; i++)
        {
            image[i] = texReadBits(bitsperpixel);
        }
    }
    else if (bitsperpixel <= 24)
    {
        u32 *image = (u32*)lookup;
        for (i = 0; i < numcolors; i++)
        {
            image[i] = texReadBits(bitsperpixel);
        }
    }
    else
    {
        u32 *image = (u32*)lookup;
        for (i = 0; i < numcolors; i++)
        {
            image[i] = texReadBits(24) << 8 | texReadBits(bitsperpixel - 24);
        }
    }
    return numcolors;
}






s32 texGetBitSize(s32 decimal)
{
	s32 count = 0;

	decimal--;

	while (decimal > 0) {
		decimal >>= 1;
		count++;
	}

	return count;
}



void texReadAlphaBits(u8 *image,s32 count)
{
  int i;
  
    for(i = 0; i < count; i++)
    {
          image[i] = texReadBits(1);
    }
}



/**
 * Read pixel data from the bitstream and write to dst,
 * ensuring each row is aligned according to the pixel format.
 *
 * Return the number of output bytes.
 */
s32 texReadUncompressed(u8 *dst, s32 width, s32 height, s32 format)
{
	u32 *dst32 = (u32 *)(((u32)dst + 0xf) & ~0xf);
	u16 *dst16 = (u16 *)(((u32)dst + 7) & ~7);
	u8 *dst8 = (u8 *)(((u32)dst + 7) & ~7);
	s32 x;
	s32 y;

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = texReadBits(16) << 16;
				dst32[x] |= texReadBits(16);
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = texReadBits(24) << 8 | 0xff;
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = texReadBits(16);
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = texReadBits(15) << 1 | 1;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst8[x] = texReadBits(8);
			}

			dst8 += (width + 7) & 0xff8;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				dst8[x >> 1] = texReadBits(8);
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}


s32 texChannelsToPixels(u8 *src, s32 width, s32 height, u8 *dst, s32 format)
{
    u32 *dst32;
    u16 *dst16;
    u8 *dst8;
    s32 x;
    s32 y;
    s32 pos;
    s32 mult;
    s32 rgb_width;

    dst32 = (u32 *)dst;
    dst16 = (u16 *)dst;
    dst8  = (u8 *)dst;

    pos = 0;
    mult = width * height;
    rgb_width = (width + 3) & 0xffc;

    switch (format)
    {
        case TEXFORMAT_RGBA32:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst32[x] = src[pos] << 24 | src[pos + mult] << 16 | src[pos + mult * 2] << 8 | src[pos + mult * 3];
                    pos++;
                }

                dst32 += rgb_width;
            }

            return (rgb_width) * height * 4;

        case TEXFORMAT_RGB24:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst32[x] = src[pos] << 24 | src[pos + mult] << 16 | src[pos + mult * 2] << 8 | 0xff;
                    pos++;
                }

                dst32 += rgb_width;
            }

            return (rgb_width) * height * 4;

        case TEXFORMAT_RGBA16:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst16[x] = src[pos] << 11 | src[pos + mult] << 6 | src[pos + mult * 2] << 1 | src[pos + mult * 3];
                    pos++;
                }

                dst16 += rgb_width;
            }

            return (rgb_width) * height * 2;

        case TEXFORMAT_IA16:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst16[x] = src[pos] << 8 | src[pos + mult];
                    pos++;
                }

                dst16 += rgb_width;
            }

            return (rgb_width) * height * 2;

        case TEXFORMAT_RGB15:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst16[x] = src[pos] << 11 | src[pos + mult] << 6 | src[pos + mult * 2] << 1 | 1;
                    pos++;
                }

                dst16 += rgb_width;
            }

            return (rgb_width) * height * 2;

        case TEXFORMAT_IA8:
            for (y = 0; y < height; y++)
            {
                if ((width + 7) & 0xff8);

                for (x = 0; x < width; x++)
                {
                    dst8[x] = src[pos] << 4 | src[pos + mult];
                    pos++;
                }

                dst8 += (width + 7) & 0xff8;
            }

            return ((width + 7) & 0xff8) * height;

        case TEXFORMAT_I8:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x++)
                {
                    dst8[x] = src[pos];
                    pos++;
                }

                dst8 += (width + 7) & 0xff8;
            }

            return ((width + 7) & 0xff8) * height;

        case TEXFORMAT_IA4:
            for (y = 0; y < height; y++)
            {
                if ((width + 15) & 0xff0);

                for (x = 0; x < width; x += 2)
                {
                    dst8[x >> 1] = src[pos] << 5 | src[pos + mult * 3] << 4 | src[pos + 1] << 1 | src[pos + mult * 3 + 1];
                    pos += 2;
                }

                if (width & 1) { pos--; }

                dst8 += (width + 15) & 0xff0;
            }

            return (((width + 15) & 0xff0) >> 1) * height;

        case TEXFORMAT_I4:
            for (y = 0; y < height; y++)
            {
                for (x = 0; x < width; x += 2)
                {
                    dst8[x >> 1] = src[pos] << 4 | src[pos + 1];
                    pos += 2;
                }

                if (width & 1) { pos--; }

                dst8 += ((width + 15) & 0xff0) >> 1;
            }

            return (((width + 15) & 0xff0) >> 1) * height;
    }

    return 0;
}


/**
 * Inflate a texture using the provided lookup table.
 *
 * The lookup table is a bitstring of colours in the pixel format described by
 * the format argument. The number of colours in the lookup table is given by
 * the numcolours argument.
 *
 * The data in the global source bitstring is expected to be a tightly packed
 * list of indices into the lookup table. The number of bits for each index
 * is calculated based on the number of colours in the lookup table. For
 * example, if the lookup table contains 8 colours then the indices will be 0-7,
 * which requires 3 bits per index.
 *
 * Return the number of bytes written to dst.
 */
s32 texInflateLookup(s32 width, s32 height, u8 *dst, u8 *lookup, s32 numcolours, s32 format)
{
	u32 *lookup32 = (u32 *)lookup;
	u16 *lookup16 = (u16 *)lookup;
	u32 *dst32 = (u32 *)dst;
	u16 *dst16 = (u16 *)dst;
	u8 *dst8 = (u8 *)dst;
	s32 x;
	s32 y;
	s32 bitspercolour = texGetBitSize(numcolours);

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = lookup32[texReadBits(bitspercolour)];
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst32[x] = lookup32[texReadBits(bitspercolour)] << 8;
			}

			dst32 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = lookup16[texReadBits(bitspercolour)];
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst16[x] = lookup16[texReadBits(bitspercolour)] << 1 | 1;
			}

			dst16 += (width + 3) & 0xffc;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				dst8[x] = lookup16[texReadBits(bitspercolour)];
			}

			dst8 += (width + 7) & 0xff8;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				dst8[x >> 1] = lookup16[texReadBits(bitspercolour)] << 4;

				if (x + 1 < width) {
					dst8[x >> 1] |= lookup[(texReadBits(bitspercolour) * 2) + 1];
				}
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}





#ifdef NONMATCHING
/**
 * Like texInflateLookup, but the indices are provided in the src argument
 * as u8s or u16s rather than read from the global bitstring as tightly packed
 * bits.
 *
 * Whether u8s or u16s are expected depends on whether the number of colours
 * in the lookup table. If there are more than 256 colours then it must use
 * u16s, otherwise it expects u8s.
 */
s32 texInflateLookupFromBuffer(u8 *src, s32 width, s32 height, u8 *dst, u8 *lookup, s32 numcolours, s32 format)
{
	s32 x;
	s32 y;
	u32 *lookup32 = (u32 *)lookup;
	u16 *lookup16 = (u16 *)lookup;
	u8 *src8;
	u16 *src16;
	u32 *dst32 = (u32 *)dst;
	u16 *dst16 = (u16 *)dst;
	u8 *dst8 = (u8 *)dst;

	if (numcolours <= 256) {
		src8 = (u8 *)src;
	} else {
		src16 = (u16 *)src;
	}

	switch (format) {
	case TEXFORMAT_RGBA32:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst32[x] = lookup32[src8[x]];
				} else {
					dst32[x] = lookup32[src16[x]];
				}
			}

			dst32 += (width + 3) & 0xffc;
			src8 += width;
			src16 += width;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGB24:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst32[x] = lookup32[src8[x]] << 8 | 0xff;
				} else {
					dst32[x] = lookup32[src16[x]] << 8 | 0xff;
				}
			}

			dst32 += (width + 3) & 0xffc;
			src8 += width;
			src16 += width;
		}

		return ((width + 3) & 0xffc) * height * 4;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_IA16:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst16[x] = lookup16[src8[x]];
				} else {
					dst16[x] = lookup16[src16[x]];
				}
			}

			dst16 += (width + 3) & 0xffc;
			src8 += width;
			src16 += width;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_RGB15:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst16[x] = lookup16[src8[x]] << 1 | 1;
				} else {
					dst16[x] = lookup16[src16[x]] << 1 | 1;
				}
			}

			dst16 += (width + 3) & 0xffc;
			src8 += width;
			src16 += width;
		}

		return ((width + 3) & 0xffc) * height * 2;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
		for (y = 0; y < height; y++) {
			if ((width + 7) & 0xff8);

			for (x = 0; x < width; x++) {
				if (numcolours <= 256) {
					dst8[x] = lookup16[src8[x]];
				} else {
					dst8[x] = lookup16[src16[x]];
				}
			}

			dst8 += (width + 7) & 0xff8;
			src8 += width;
			src16 += width;
		}

		return ((width + 7) & 0xff8) * height;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
		for (y = 0; y < height; y++) {
			for (x = 0; x < width; x += 2) {
				if (numcolours <= 256) {
					dst8[x >> 1] = lookup16[src8[x]] << 4 | lookup16[src8[x + 1]];
				} else {
					dst8[x >> 1] = lookup16[src16[x]] << 4 | lookup16[src16[x + 1]];
				}
			}

			dst8 += ((width + 15) & 0xff0) >> 1;
			src8 += width;
			src16 += width;
		}

		return (((width + 15) & 0xff0) >> 1) * height;
	}

	return 0;
}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BE0C*/
glabel jpt_8005BE0C
.word .L7F0CACC4
.word .L7F0CB0AC
.word .L7F0CAE90
.word .L7F0CB26C
.word .L7F0CB0AC
.word .L7F0CB3C4
.word .L7F0CB584
.word .L7F0CB3C4
.word .L7F0CB584
.text
glabel texInflateLookupFromBuffer
/* 0FF788 7F0CAC58 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0FF78C 7F0CAC5C AFB00004 */  sw    $s0, 4($sp)
/* 0FF790 7F0CAC60 8FB0003C */  lw    $s0, 0x3c($sp)
/* 0FF794 7F0CAC64 AFB2000C */  sw    $s2, 0xc($sp)
/* 0FF798 7F0CAC68 AFB10008 */  sw    $s1, 8($sp)
/* 0FF79C 7F0CAC6C 2A010101 */  slti  $at, $s0, 0x101
/* 0FF7A0 7F0CAC70 00A08825 */  move  $s1, $a1
/* 0FF7A4 7F0CAC74 00C09025 */  move  $s2, $a2
/* 0FF7A8 7F0CAC78 AFA40028 */  sw    $a0, 0x28($sp)
/* 0FF7AC 7F0CAC7C 00E04825 */  move  $t1, $a3
/* 0FF7B0 7F0CAC80 00E05025 */  move  $t2, $a3
/* 0FF7B4 7F0CAC84 10200003 */  beqz  $at, .L7F0CAC94
/* 0FF7B8 7F0CAC88 00E05825 */   move  $t3, $a3
/* 0FF7BC 7F0CAC8C 10000003 */  b     .L7F0CAC9C
/* 0FF7C0 7F0CAC90 8FA50010 */   lw    $a1, 0x10($sp)
.L7F0CAC94:
/* 0FF7C4 7F0CAC94 8FA50028 */  lw    $a1, 0x28($sp)
/* 0FF7C8 7F0CAC98 8FA40014 */  lw    $a0, 0x14($sp)
.L7F0CAC9C:
/* 0FF7CC 7F0CAC9C 8FAE0040 */  lw    $t6, 0x40($sp)
/* 0FF7D0 7F0CACA0 00001025 */  move  $v0, $zero
/* 0FF7D4 7F0CACA4 2DC10009 */  sltiu $at, $t6, 9
/* 0FF7D8 7F0CACA8 1020026F */  beqz  $at, .L7F0CB668
/* 0FF7DC 7F0CACAC 000E7080 */   sll   $t6, $t6, 2
/* 0FF7E0 7F0CACB0 3C018006 */  lui   $at, %hi(jpt_8005BE0C)
/* 0FF7E4 7F0CACB4 002E0821 */  addu  $at, $at, $t6
/* 0FF7E8 7F0CACB8 8C2EBE0C */  lw    $t6, %lo(jpt_8005BE0C)($at)
/* 0FF7EC 7F0CACBC 01C00008 */  jr    $t6
/* 0FF7F0 7F0CACC0 00000000 */   nop   
.L7F0CACC4:
/* 0FF7F4 7F0CACC4 1A40006B */  blez  $s2, .L7F0CAE74
/* 0FF7F8 7F0CACC8 00003825 */   move  $a3, $zero
/* 0FF7FC 7F0CACCC 262C0003 */  addiu $t4, $s1, 3
/* 0FF800 7F0CACD0 318F0FFC */  andi  $t7, $t4, 0xffc
/* 0FF804 7F0CACD4 000F6080 */  sll   $t4, $t7, 2
/* 0FF808 7F0CACD8 00114040 */  sll   $t0, $s1, 1
/* 0FF80C 7F0CACDC 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CACE0:
/* 0FF810 7F0CACE0 1A20005F */  blez  $s1, .L7F0CAE60
/* 0FF814 7F0CACE4 00001025 */   move  $v0, $zero
/* 0FF818 7F0CACE8 32260003 */  andi  $a2, $s1, 3
/* 0FF81C 7F0CACEC 10C00017 */  beqz  $a2, .L7F0CAD4C
/* 0FF820 7F0CACF0 00C05825 */   move  $t3, $a2
/* 0FF824 7F0CACF4 0000C880 */  sll   $t9, $zero, 2
/* 0FF828 7F0CACF8 01395021 */  addu  $t2, $t1, $t9
.L7F0CACFC:
/* 0FF82C 7F0CACFC 2A010101 */  slti  $at, $s0, 0x101
/* 0FF830 7F0CAD00 10200008 */  beqz  $at, .L7F0CAD24
/* 0FF834 7F0CAD04 00027840 */   sll   $t7, $v0, 1
/* 0FF838 7F0CAD08 00827021 */  addu  $t6, $a0, $v0
/* 0FF83C 7F0CAD0C 91CF0000 */  lbu   $t7, ($t6)
/* 0FF840 7F0CAD10 000FC080 */  sll   $t8, $t7, 2
/* 0FF844 7F0CAD14 0078C821 */  addu  $t9, $v1, $t8
/* 0FF848 7F0CAD18 8F2E0000 */  lw    $t6, ($t9)
/* 0FF84C 7F0CAD1C 10000007 */  b     .L7F0CAD3C
/* 0FF850 7F0CAD20 AD4E0000 */   sw    $t6, ($t2)
.L7F0CAD24:
/* 0FF854 7F0CAD24 00AFC021 */  addu  $t8, $a1, $t7
/* 0FF858 7F0CAD28 97190000 */  lhu   $t9, ($t8)
/* 0FF85C 7F0CAD2C 00197080 */  sll   $t6, $t9, 2
/* 0FF860 7F0CAD30 006E7821 */  addu  $t7, $v1, $t6
/* 0FF864 7F0CAD34 8DF80000 */  lw    $t8, ($t7)
/* 0FF868 7F0CAD38 AD580000 */  sw    $t8, ($t2)
.L7F0CAD3C:
/* 0FF86C 7F0CAD3C 24420001 */  addiu $v0, $v0, 1
/* 0FF870 7F0CAD40 1562FFEE */  bne   $t3, $v0, .L7F0CACFC
/* 0FF874 7F0CAD44 254A0004 */   addiu $t2, $t2, 4
/* 0FF878 7F0CAD48 10510045 */  beq   $v0, $s1, .L7F0CAE60
.L7F0CAD4C:
/* 0FF87C 7F0CAD4C 0002C880 */   sll   $t9, $v0, 2
/* 0FF880 7F0CAD50 01395021 */  addu  $t2, $t1, $t9
.L7F0CAD54:
/* 0FF884 7F0CAD54 2A010101 */  slti  $at, $s0, 0x101
/* 0FF888 7F0CAD58 10200008 */  beqz  $at, .L7F0CAD7C
/* 0FF88C 7F0CAD5C 00027840 */   sll   $t7, $v0, 1
/* 0FF890 7F0CAD60 00827021 */  addu  $t6, $a0, $v0
/* 0FF894 7F0CAD64 91CF0000 */  lbu   $t7, ($t6)
/* 0FF898 7F0CAD68 000FC080 */  sll   $t8, $t7, 2
/* 0FF89C 7F0CAD6C 0078C821 */  addu  $t9, $v1, $t8
/* 0FF8A0 7F0CAD70 8F2E0000 */  lw    $t6, ($t9)
/* 0FF8A4 7F0CAD74 10000007 */  b     .L7F0CAD94
/* 0FF8A8 7F0CAD78 AD4E0000 */   sw    $t6, ($t2)
.L7F0CAD7C:
/* 0FF8AC 7F0CAD7C 00AFC021 */  addu  $t8, $a1, $t7
/* 0FF8B0 7F0CAD80 97190000 */  lhu   $t9, ($t8)
/* 0FF8B4 7F0CAD84 00197080 */  sll   $t6, $t9, 2
/* 0FF8B8 7F0CAD88 006E7821 */  addu  $t7, $v1, $t6
/* 0FF8BC 7F0CAD8C 8DF80000 */  lw    $t8, ($t7)
/* 0FF8C0 7F0CAD90 AD580000 */  sw    $t8, ($t2)
.L7F0CAD94:
/* 0FF8C4 7F0CAD94 2A010101 */  slti  $at, $s0, 0x101
/* 0FF8C8 7F0CAD98 10200008 */  beqz  $at, .L7F0CADBC
/* 0FF8CC 7F0CAD9C 00027040 */   sll   $t6, $v0, 1
/* 0FF8D0 7F0CADA0 0082C821 */  addu  $t9, $a0, $v0
/* 0FF8D4 7F0CADA4 932E0001 */  lbu   $t6, 1($t9)
/* 0FF8D8 7F0CADA8 000E7880 */  sll   $t7, $t6, 2
/* 0FF8DC 7F0CADAC 006FC021 */  addu  $t8, $v1, $t7
/* 0FF8E0 7F0CADB0 8F190000 */  lw    $t9, ($t8)
/* 0FF8E4 7F0CADB4 10000007 */  b     .L7F0CADD4
/* 0FF8E8 7F0CADB8 AD590004 */   sw    $t9, 4($t2)
.L7F0CADBC:
/* 0FF8EC 7F0CADBC 00AE7821 */  addu  $t7, $a1, $t6
/* 0FF8F0 7F0CADC0 95F80002 */  lhu   $t8, 2($t7)
/* 0FF8F4 7F0CADC4 0018C880 */  sll   $t9, $t8, 2
/* 0FF8F8 7F0CADC8 00797021 */  addu  $t6, $v1, $t9
/* 0FF8FC 7F0CADCC 8DCF0000 */  lw    $t7, ($t6)
/* 0FF900 7F0CADD0 AD4F0004 */  sw    $t7, 4($t2)
.L7F0CADD4:
/* 0FF904 7F0CADD4 2A010101 */  slti  $at, $s0, 0x101
/* 0FF908 7F0CADD8 10200008 */  beqz  $at, .L7F0CADFC
/* 0FF90C 7F0CADDC 0002C840 */   sll   $t9, $v0, 1
/* 0FF910 7F0CADE0 0082C021 */  addu  $t8, $a0, $v0
/* 0FF914 7F0CADE4 93190002 */  lbu   $t9, 2($t8)
/* 0FF918 7F0CADE8 00197080 */  sll   $t6, $t9, 2
/* 0FF91C 7F0CADEC 006E7821 */  addu  $t7, $v1, $t6
/* 0FF920 7F0CADF0 8DF80000 */  lw    $t8, ($t7)
/* 0FF924 7F0CADF4 10000007 */  b     .L7F0CAE14
/* 0FF928 7F0CADF8 AD580008 */   sw    $t8, 8($t2)
.L7F0CADFC:
/* 0FF92C 7F0CADFC 00B97021 */  addu  $t6, $a1, $t9
/* 0FF930 7F0CAE00 95CF0004 */  lhu   $t7, 4($t6)
/* 0FF934 7F0CAE04 000FC080 */  sll   $t8, $t7, 2
/* 0FF938 7F0CAE08 0078C821 */  addu  $t9, $v1, $t8
/* 0FF93C 7F0CAE0C 8F2E0000 */  lw    $t6, ($t9)
/* 0FF940 7F0CAE10 AD4E0008 */  sw    $t6, 8($t2)
.L7F0CAE14:
/* 0FF944 7F0CAE14 2A010101 */  slti  $at, $s0, 0x101
/* 0FF948 7F0CAE18 10200008 */  beqz  $at, .L7F0CAE3C
/* 0FF94C 7F0CAE1C 0002C040 */   sll   $t8, $v0, 1
/* 0FF950 7F0CAE20 00827821 */  addu  $t7, $a0, $v0
/* 0FF954 7F0CAE24 91F80003 */  lbu   $t8, 3($t7)
/* 0FF958 7F0CAE28 0018C880 */  sll   $t9, $t8, 2
/* 0FF95C 7F0CAE2C 00797021 */  addu  $t6, $v1, $t9
/* 0FF960 7F0CAE30 8DCF0000 */  lw    $t7, ($t6)
/* 0FF964 7F0CAE34 10000007 */  b     .L7F0CAE54
/* 0FF968 7F0CAE38 AD4F000C */   sw    $t7, 0xc($t2)
.L7F0CAE3C:
/* 0FF96C 7F0CAE3C 00B8C821 */  addu  $t9, $a1, $t8
/* 0FF970 7F0CAE40 972E0006 */  lhu   $t6, 6($t9)
/* 0FF974 7F0CAE44 000E7880 */  sll   $t7, $t6, 2
/* 0FF978 7F0CAE48 006FC021 */  addu  $t8, $v1, $t7
/* 0FF97C 7F0CAE4C 8F190000 */  lw    $t9, ($t8)
/* 0FF980 7F0CAE50 AD59000C */  sw    $t9, 0xc($t2)
.L7F0CAE54:
/* 0FF984 7F0CAE54 24420004 */  addiu $v0, $v0, 4
/* 0FF988 7F0CAE58 1451FFBE */  bne   $v0, $s1, .L7F0CAD54
/* 0FF98C 7F0CAE5C 254A0010 */   addiu $t2, $t2, 0x10
.L7F0CAE60:
/* 0FF990 7F0CAE60 24E70001 */  addiu $a3, $a3, 1
/* 0FF994 7F0CAE64 012C4821 */  addu  $t1, $t1, $t4
/* 0FF998 7F0CAE68 00912021 */  addu  $a0, $a0, $s1
/* 0FF99C 7F0CAE6C 14F2FF9C */  bne   $a3, $s2, .L7F0CACE0
/* 0FF9A0 7F0CAE70 00A82821 */   addu  $a1, $a1, $t0
.L7F0CAE74:
/* 0FF9A4 7F0CAE74 262E0003 */  addiu $t6, $s1, 3
/* 0FF9A8 7F0CAE78 31CF0FFC */  andi  $t7, $t6, 0xffc
/* 0FF9AC 7F0CAE7C 01F20019 */  multu $t7, $s2
/* 0FF9B0 7F0CAE80 00001012 */  mflo  $v0
/* 0FF9B4 7F0CAE84 0002C080 */  sll   $t8, $v0, 2
/* 0FF9B8 7F0CAE88 100001F7 */  b     .L7F0CB668
/* 0FF9BC 7F0CAE8C 03001025 */   move  $v0, $t8
.L7F0CAE90:
/* 0FF9C0 7F0CAE90 1A40007F */  blez  $s2, .L7F0CB090
/* 0FF9C4 7F0CAE94 00003825 */   move  $a3, $zero
/* 0FF9C8 7F0CAE98 262C0003 */  addiu $t4, $s1, 3
/* 0FF9CC 7F0CAE9C 31990FFC */  andi  $t9, $t4, 0xffc
/* 0FF9D0 7F0CAEA0 00196080 */  sll   $t4, $t9, 2
/* 0FF9D4 7F0CAEA4 00114040 */  sll   $t0, $s1, 1
/* 0FF9D8 7F0CAEA8 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CAEAC:
/* 0FF9DC 7F0CAEAC 1A200073 */  blez  $s1, .L7F0CB07C
/* 0FF9E0 7F0CAEB0 00001025 */   move  $v0, $zero
/* 0FF9E4 7F0CAEB4 32260003 */  andi  $a2, $s1, 3
/* 0FF9E8 7F0CAEB8 10C0001B */  beqz  $a2, .L7F0CAF28
/* 0FF9EC 7F0CAEBC 00C05825 */   move  $t3, $a2
/* 0FF9F0 7F0CAEC0 00007880 */  sll   $t7, $zero, 2
/* 0FF9F4 7F0CAEC4 012F5021 */  addu  $t2, $t1, $t7
.L7F0CAEC8:
/* 0FF9F8 7F0CAEC8 2A010101 */  slti  $at, $s0, 0x101
/* 0FF9FC 7F0CAECC 1020000A */  beqz  $at, .L7F0CAEF8
/* 0FFA00 7F0CAED0 00027840 */   sll   $t7, $v0, 1
/* 0FFA04 7F0CAED4 0082C021 */  addu  $t8, $a0, $v0
/* 0FFA08 7F0CAED8 93190000 */  lbu   $t9, ($t8)
/* 0FFA0C 7F0CAEDC 00197080 */  sll   $t6, $t9, 2
/* 0FFA10 7F0CAEE0 006E7821 */  addu  $t7, $v1, $t6
/* 0FFA14 7F0CAEE4 8DF80000 */  lw    $t8, ($t7)
/* 0FFA18 7F0CAEE8 0018CA00 */  sll   $t9, $t8, 8
/* 0FFA1C 7F0CAEEC 372E00FF */  ori   $t6, $t9, 0xff
/* 0FFA20 7F0CAEF0 10000009 */  b     .L7F0CAF18
/* 0FFA24 7F0CAEF4 AD4E0000 */   sw    $t6, ($t2)
.L7F0CAEF8:
/* 0FFA28 7F0CAEF8 00AFC021 */  addu  $t8, $a1, $t7
/* 0FFA2C 7F0CAEFC 97190000 */  lhu   $t9, ($t8)
/* 0FFA30 7F0CAF00 00197080 */  sll   $t6, $t9, 2
/* 0FFA34 7F0CAF04 006E7821 */  addu  $t7, $v1, $t6
/* 0FFA38 7F0CAF08 8DF80000 */  lw    $t8, ($t7)
/* 0FFA3C 7F0CAF0C 0018CA00 */  sll   $t9, $t8, 8
/* 0FFA40 7F0CAF10 372E00FF */  ori   $t6, $t9, 0xff
/* 0FFA44 7F0CAF14 AD4E0000 */  sw    $t6, ($t2)
.L7F0CAF18:
/* 0FFA48 7F0CAF18 24420001 */  addiu $v0, $v0, 1
/* 0FFA4C 7F0CAF1C 1562FFEA */  bne   $t3, $v0, .L7F0CAEC8
/* 0FFA50 7F0CAF20 254A0004 */   addiu $t2, $t2, 4
/* 0FFA54 7F0CAF24 10510055 */  beq   $v0, $s1, .L7F0CB07C
.L7F0CAF28:
/* 0FFA58 7F0CAF28 00027880 */   sll   $t7, $v0, 2
/* 0FFA5C 7F0CAF2C 012F5021 */  addu  $t2, $t1, $t7
.L7F0CAF30:
/* 0FFA60 7F0CAF30 2A010101 */  slti  $at, $s0, 0x101
/* 0FFA64 7F0CAF34 1020000A */  beqz  $at, .L7F0CAF60
/* 0FFA68 7F0CAF38 00027840 */   sll   $t7, $v0, 1
/* 0FFA6C 7F0CAF3C 0082C021 */  addu  $t8, $a0, $v0
/* 0FFA70 7F0CAF40 93190000 */  lbu   $t9, ($t8)
/* 0FFA74 7F0CAF44 00197080 */  sll   $t6, $t9, 2
/* 0FFA78 7F0CAF48 006E7821 */  addu  $t7, $v1, $t6
/* 0FFA7C 7F0CAF4C 8DF80000 */  lw    $t8, ($t7)
/* 0FFA80 7F0CAF50 0018CA00 */  sll   $t9, $t8, 8
/* 0FFA84 7F0CAF54 372E00FF */  ori   $t6, $t9, 0xff
/* 0FFA88 7F0CAF58 10000009 */  b     .L7F0CAF80
/* 0FFA8C 7F0CAF5C AD4E0000 */   sw    $t6, ($t2)
.L7F0CAF60:
/* 0FFA90 7F0CAF60 00AFC021 */  addu  $t8, $a1, $t7
/* 0FFA94 7F0CAF64 97190000 */  lhu   $t9, ($t8)
/* 0FFA98 7F0CAF68 00197080 */  sll   $t6, $t9, 2
/* 0FFA9C 7F0CAF6C 006E7821 */  addu  $t7, $v1, $t6
/* 0FFAA0 7F0CAF70 8DF80000 */  lw    $t8, ($t7)
/* 0FFAA4 7F0CAF74 0018CA00 */  sll   $t9, $t8, 8
/* 0FFAA8 7F0CAF78 372E00FF */  ori   $t6, $t9, 0xff
/* 0FFAAC 7F0CAF7C AD4E0000 */  sw    $t6, ($t2)
.L7F0CAF80:
/* 0FFAB0 7F0CAF80 2A010101 */  slti  $at, $s0, 0x101
/* 0FFAB4 7F0CAF84 1020000A */  beqz  $at, .L7F0CAFB0
/* 0FFAB8 7F0CAF88 00027040 */   sll   $t6, $v0, 1
/* 0FFABC 7F0CAF8C 00827821 */  addu  $t7, $a0, $v0
/* 0FFAC0 7F0CAF90 91F80001 */  lbu   $t8, 1($t7)
/* 0FFAC4 7F0CAF94 0018C880 */  sll   $t9, $t8, 2
/* 0FFAC8 7F0CAF98 00797021 */  addu  $t6, $v1, $t9
/* 0FFACC 7F0CAF9C 8DCF0000 */  lw    $t7, ($t6)
/* 0FFAD0 7F0CAFA0 000FC200 */  sll   $t8, $t7, 8
/* 0FFAD4 7F0CAFA4 371900FF */  ori   $t9, $t8, 0xff
/* 0FFAD8 7F0CAFA8 10000009 */  b     .L7F0CAFD0
/* 0FFADC 7F0CAFAC AD590004 */   sw    $t9, 4($t2)
.L7F0CAFB0:
/* 0FFAE0 7F0CAFB0 00AE7821 */  addu  $t7, $a1, $t6
/* 0FFAE4 7F0CAFB4 95F80002 */  lhu   $t8, 2($t7)
/* 0FFAE8 7F0CAFB8 0018C880 */  sll   $t9, $t8, 2
/* 0FFAEC 7F0CAFBC 00797021 */  addu  $t6, $v1, $t9
/* 0FFAF0 7F0CAFC0 8DCF0000 */  lw    $t7, ($t6)
/* 0FFAF4 7F0CAFC4 000FC200 */  sll   $t8, $t7, 8
/* 0FFAF8 7F0CAFC8 371900FF */  ori   $t9, $t8, 0xff
/* 0FFAFC 7F0CAFCC AD590004 */  sw    $t9, 4($t2)
.L7F0CAFD0:
/* 0FFB00 7F0CAFD0 2A010101 */  slti  $at, $s0, 0x101
/* 0FFB04 7F0CAFD4 1020000A */  beqz  $at, .L7F0CB000
/* 0FFB08 7F0CAFD8 0002C840 */   sll   $t9, $v0, 1
/* 0FFB0C 7F0CAFDC 00827021 */  addu  $t6, $a0, $v0
/* 0FFB10 7F0CAFE0 91CF0002 */  lbu   $t7, 2($t6)
/* 0FFB14 7F0CAFE4 000FC080 */  sll   $t8, $t7, 2
/* 0FFB18 7F0CAFE8 0078C821 */  addu  $t9, $v1, $t8
/* 0FFB1C 7F0CAFEC 8F2E0000 */  lw    $t6, ($t9)
/* 0FFB20 7F0CAFF0 000E7A00 */  sll   $t7, $t6, 8
/* 0FFB24 7F0CAFF4 35F800FF */  ori   $t8, $t7, 0xff
/* 0FFB28 7F0CAFF8 10000009 */  b     .L7F0CB020
/* 0FFB2C 7F0CAFFC AD580008 */   sw    $t8, 8($t2)
.L7F0CB000:
/* 0FFB30 7F0CB000 00B97021 */  addu  $t6, $a1, $t9
/* 0FFB34 7F0CB004 95CF0004 */  lhu   $t7, 4($t6)
/* 0FFB38 7F0CB008 000FC080 */  sll   $t8, $t7, 2
/* 0FFB3C 7F0CB00C 0078C821 */  addu  $t9, $v1, $t8
/* 0FFB40 7F0CB010 8F2E0000 */  lw    $t6, ($t9)
/* 0FFB44 7F0CB014 000E7A00 */  sll   $t7, $t6, 8
/* 0FFB48 7F0CB018 35F800FF */  ori   $t8, $t7, 0xff
/* 0FFB4C 7F0CB01C AD580008 */  sw    $t8, 8($t2)
.L7F0CB020:
/* 0FFB50 7F0CB020 2A010101 */  slti  $at, $s0, 0x101
/* 0FFB54 7F0CB024 1020000A */  beqz  $at, .L7F0CB050
/* 0FFB58 7F0CB028 0002C040 */   sll   $t8, $v0, 1
/* 0FFB5C 7F0CB02C 0082C821 */  addu  $t9, $a0, $v0
/* 0FFB60 7F0CB030 932E0003 */  lbu   $t6, 3($t9)
/* 0FFB64 7F0CB034 000E7880 */  sll   $t7, $t6, 2
/* 0FFB68 7F0CB038 006FC021 */  addu  $t8, $v1, $t7
/* 0FFB6C 7F0CB03C 8F190000 */  lw    $t9, ($t8)
/* 0FFB70 7F0CB040 00197200 */  sll   $t6, $t9, 8
/* 0FFB74 7F0CB044 35CF00FF */  ori   $t7, $t6, 0xff
/* 0FFB78 7F0CB048 10000009 */  b     .L7F0CB070
/* 0FFB7C 7F0CB04C AD4F000C */   sw    $t7, 0xc($t2)
.L7F0CB050:
/* 0FFB80 7F0CB050 00B8C821 */  addu  $t9, $a1, $t8
/* 0FFB84 7F0CB054 972E0006 */  lhu   $t6, 6($t9)
/* 0FFB88 7F0CB058 000E7880 */  sll   $t7, $t6, 2
/* 0FFB8C 7F0CB05C 006FC021 */  addu  $t8, $v1, $t7
/* 0FFB90 7F0CB060 8F190000 */  lw    $t9, ($t8)
/* 0FFB94 7F0CB064 00197200 */  sll   $t6, $t9, 8
/* 0FFB98 7F0CB068 35CF00FF */  ori   $t7, $t6, 0xff
/* 0FFB9C 7F0CB06C AD4F000C */  sw    $t7, 0xc($t2)
.L7F0CB070:
/* 0FFBA0 7F0CB070 24420004 */  addiu $v0, $v0, 4
/* 0FFBA4 7F0CB074 1451FFAE */  bne   $v0, $s1, .L7F0CAF30
/* 0FFBA8 7F0CB078 254A0010 */   addiu $t2, $t2, 0x10
.L7F0CB07C:
/* 0FFBAC 7F0CB07C 24E70001 */  addiu $a3, $a3, 1
/* 0FFBB0 7F0CB080 012C4821 */  addu  $t1, $t1, $t4
/* 0FFBB4 7F0CB084 00912021 */  addu  $a0, $a0, $s1
/* 0FFBB8 7F0CB088 14F2FF88 */  bne   $a3, $s2, .L7F0CAEAC
/* 0FFBBC 7F0CB08C 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB090:
/* 0FFBC0 7F0CB090 26380003 */  addiu $t8, $s1, 3
/* 0FFBC4 7F0CB094 33190FFC */  andi  $t9, $t8, 0xffc
/* 0FFBC8 7F0CB098 03320019 */  multu $t9, $s2
/* 0FFBCC 7F0CB09C 00001012 */  mflo  $v0
/* 0FFBD0 7F0CB0A0 00027080 */  sll   $t6, $v0, 2
/* 0FFBD4 7F0CB0A4 10000170 */  b     .L7F0CB668
/* 0FFBD8 7F0CB0A8 01C01025 */   move  $v0, $t6
.L7F0CB0AC:
/* 0FFBDC 7F0CB0AC 1A400068 */  blez  $s2, .L7F0CB250
/* 0FFBE0 7F0CB0B0 00003825 */   move  $a3, $zero
/* 0FFBE4 7F0CB0B4 262D0003 */  addiu $t5, $s1, 3
/* 0FFBE8 7F0CB0B8 31AF0FFC */  andi  $t7, $t5, 0xffc
/* 0FFBEC 7F0CB0BC 000F6840 */  sll   $t5, $t7, 1
/* 0FFBF0 7F0CB0C0 00114040 */  sll   $t0, $s1, 1
/* 0FFBF4 7F0CB0C4 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CB0C8:
/* 0FFBF8 7F0CB0C8 1A20005C */  blez  $s1, .L7F0CB23C
/* 0FFBFC 7F0CB0CC 00001025 */   move  $v0, $zero
/* 0FFC00 7F0CB0D0 32260003 */  andi  $a2, $s1, 3
/* 0FFC04 7F0CB0D4 10C00017 */  beqz  $a2, .L7F0CB134
/* 0FFC08 7F0CB0D8 00C06025 */   move  $t4, $a2
/* 0FFC0C 7F0CB0DC 00004840 */  sll   $t1, $zero, 1
/* 0FFC10 7F0CB0E0 01495821 */  addu  $t3, $t2, $t1
.L7F0CB0E4:
/* 0FFC14 7F0CB0E4 2A010101 */  slti  $at, $s0, 0x101
/* 0FFC18 7F0CB0E8 10200008 */  beqz  $at, .L7F0CB10C
/* 0FFC1C 7F0CB0EC 00A97021 */   addu  $t6, $a1, $t1
/* 0FFC20 7F0CB0F0 0082C821 */  addu  $t9, $a0, $v0
/* 0FFC24 7F0CB0F4 932E0000 */  lbu   $t6, ($t9)
/* 0FFC28 7F0CB0F8 000E7840 */  sll   $t7, $t6, 1
/* 0FFC2C 7F0CB0FC 006FC021 */  addu  $t8, $v1, $t7
/* 0FFC30 7F0CB100 97190000 */  lhu   $t9, ($t8)
/* 0FFC34 7F0CB104 10000006 */  b     .L7F0CB120
/* 0FFC38 7F0CB108 A5790000 */   sh    $t9, ($t3)
.L7F0CB10C:
/* 0FFC3C 7F0CB10C 95CF0000 */  lhu   $t7, ($t6)
/* 0FFC40 7F0CB110 000FC040 */  sll   $t8, $t7, 1
/* 0FFC44 7F0CB114 0078C821 */  addu  $t9, $v1, $t8
/* 0FFC48 7F0CB118 972E0000 */  lhu   $t6, ($t9)
/* 0FFC4C 7F0CB11C A56E0000 */  sh    $t6, ($t3)
.L7F0CB120:
/* 0FFC50 7F0CB120 24420001 */  addiu $v0, $v0, 1
/* 0FFC54 7F0CB124 25290002 */  addiu $t1, $t1, 2
/* 0FFC58 7F0CB128 1582FFEE */  bne   $t4, $v0, .L7F0CB0E4
/* 0FFC5C 7F0CB12C 256B0002 */   addiu $t3, $t3, 2
/* 0FFC60 7F0CB130 10510042 */  beq   $v0, $s1, .L7F0CB23C
.L7F0CB134:
/* 0FFC64 7F0CB134 00024840 */   sll   $t1, $v0, 1
/* 0FFC68 7F0CB138 01495821 */  addu  $t3, $t2, $t1
.L7F0CB13C:
/* 0FFC6C 7F0CB13C 2A010101 */  slti  $at, $s0, 0x101
/* 0FFC70 7F0CB140 10200008 */  beqz  $at, .L7F0CB164
/* 0FFC74 7F0CB144 00A9C021 */   addu  $t8, $a1, $t1
/* 0FFC78 7F0CB148 00827821 */  addu  $t7, $a0, $v0
/* 0FFC7C 7F0CB14C 91F80000 */  lbu   $t8, ($t7)
/* 0FFC80 7F0CB150 0018C840 */  sll   $t9, $t8, 1
/* 0FFC84 7F0CB154 00797021 */  addu  $t6, $v1, $t9
/* 0FFC88 7F0CB158 95CF0000 */  lhu   $t7, ($t6)
/* 0FFC8C 7F0CB15C 10000006 */  b     .L7F0CB178
/* 0FFC90 7F0CB160 A56F0000 */   sh    $t7, ($t3)
.L7F0CB164:
/* 0FFC94 7F0CB164 97190000 */  lhu   $t9, ($t8)
/* 0FFC98 7F0CB168 00197040 */  sll   $t6, $t9, 1
/* 0FFC9C 7F0CB16C 006E7821 */  addu  $t7, $v1, $t6
/* 0FFCA0 7F0CB170 95F80000 */  lhu   $t8, ($t7)
/* 0FFCA4 7F0CB174 A5780000 */  sh    $t8, ($t3)
.L7F0CB178:
/* 0FFCA8 7F0CB178 2A010101 */  slti  $at, $s0, 0x101
/* 0FFCAC 7F0CB17C 10200008 */  beqz  $at, .L7F0CB1A0
/* 0FFCB0 7F0CB180 00A97021 */   addu  $t6, $a1, $t1
/* 0FFCB4 7F0CB184 0082C821 */  addu  $t9, $a0, $v0
/* 0FFCB8 7F0CB188 932E0001 */  lbu   $t6, 1($t9)
/* 0FFCBC 7F0CB18C 000E7840 */  sll   $t7, $t6, 1
/* 0FFCC0 7F0CB190 006FC021 */  addu  $t8, $v1, $t7
/* 0FFCC4 7F0CB194 97190000 */  lhu   $t9, ($t8)
/* 0FFCC8 7F0CB198 10000006 */  b     .L7F0CB1B4
/* 0FFCCC 7F0CB19C A5790002 */   sh    $t9, 2($t3)
.L7F0CB1A0:
/* 0FFCD0 7F0CB1A0 95CF0002 */  lhu   $t7, 2($t6)
/* 0FFCD4 7F0CB1A4 000FC040 */  sll   $t8, $t7, 1
/* 0FFCD8 7F0CB1A8 0078C821 */  addu  $t9, $v1, $t8
/* 0FFCDC 7F0CB1AC 972E0000 */  lhu   $t6, ($t9)
/* 0FFCE0 7F0CB1B0 A56E0002 */  sh    $t6, 2($t3)
.L7F0CB1B4:
/* 0FFCE4 7F0CB1B4 2A010101 */  slti  $at, $s0, 0x101
/* 0FFCE8 7F0CB1B8 10200008 */  beqz  $at, .L7F0CB1DC
/* 0FFCEC 7F0CB1BC 00A9C021 */   addu  $t8, $a1, $t1
/* 0FFCF0 7F0CB1C0 00827821 */  addu  $t7, $a0, $v0
/* 0FFCF4 7F0CB1C4 91F80002 */  lbu   $t8, 2($t7)
/* 0FFCF8 7F0CB1C8 0018C840 */  sll   $t9, $t8, 1
/* 0FFCFC 7F0CB1CC 00797021 */  addu  $t6, $v1, $t9
/* 0FFD00 7F0CB1D0 95CF0000 */  lhu   $t7, ($t6)
/* 0FFD04 7F0CB1D4 10000006 */  b     .L7F0CB1F0
/* 0FFD08 7F0CB1D8 A56F0004 */   sh    $t7, 4($t3)
.L7F0CB1DC:
/* 0FFD0C 7F0CB1DC 97190004 */  lhu   $t9, 4($t8)
/* 0FFD10 7F0CB1E0 00197040 */  sll   $t6, $t9, 1
/* 0FFD14 7F0CB1E4 006E7821 */  addu  $t7, $v1, $t6
/* 0FFD18 7F0CB1E8 95F80000 */  lhu   $t8, ($t7)
/* 0FFD1C 7F0CB1EC A5780004 */  sh    $t8, 4($t3)
.L7F0CB1F0:
/* 0FFD20 7F0CB1F0 2A010101 */  slti  $at, $s0, 0x101
/* 0FFD24 7F0CB1F4 10200008 */  beqz  $at, .L7F0CB218
/* 0FFD28 7F0CB1F8 00A97021 */   addu  $t6, $a1, $t1
/* 0FFD2C 7F0CB1FC 0082C821 */  addu  $t9, $a0, $v0
/* 0FFD30 7F0CB200 932E0003 */  lbu   $t6, 3($t9)
/* 0FFD34 7F0CB204 000E7840 */  sll   $t7, $t6, 1
/* 0FFD38 7F0CB208 006FC021 */  addu  $t8, $v1, $t7
/* 0FFD3C 7F0CB20C 97190000 */  lhu   $t9, ($t8)
/* 0FFD40 7F0CB210 10000006 */  b     .L7F0CB22C
/* 0FFD44 7F0CB214 A5790006 */   sh    $t9, 6($t3)
.L7F0CB218:
/* 0FFD48 7F0CB218 95CF0006 */  lhu   $t7, 6($t6)
/* 0FFD4C 7F0CB21C 000FC040 */  sll   $t8, $t7, 1
/* 0FFD50 7F0CB220 0078C821 */  addu  $t9, $v1, $t8
/* 0FFD54 7F0CB224 972E0000 */  lhu   $t6, ($t9)
/* 0FFD58 7F0CB228 A56E0006 */  sh    $t6, 6($t3)
.L7F0CB22C:
/* 0FFD5C 7F0CB22C 24420004 */  addiu $v0, $v0, 4
/* 0FFD60 7F0CB230 25290008 */  addiu $t1, $t1, 8
/* 0FFD64 7F0CB234 1451FFC1 */  bne   $v0, $s1, .L7F0CB13C
/* 0FFD68 7F0CB238 256B0008 */   addiu $t3, $t3, 8
.L7F0CB23C:
/* 0FFD6C 7F0CB23C 24E70001 */  addiu $a3, $a3, 1
/* 0FFD70 7F0CB240 014D5021 */  addu  $t2, $t2, $t5
/* 0FFD74 7F0CB244 00912021 */  addu  $a0, $a0, $s1
/* 0FFD78 7F0CB248 14F2FF9F */  bne   $a3, $s2, .L7F0CB0C8
/* 0FFD7C 7F0CB24C 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB250:
/* 0FFD80 7F0CB250 262F0003 */  addiu $t7, $s1, 3
/* 0FFD84 7F0CB254 31F80FFC */  andi  $t8, $t7, 0xffc
/* 0FFD88 7F0CB258 03120019 */  multu $t8, $s2
/* 0FFD8C 7F0CB25C 00001012 */  mflo  $v0
/* 0FFD90 7F0CB260 0002C840 */  sll   $t9, $v0, 1
/* 0FFD94 7F0CB264 10000100 */  b     .L7F0CB668
/* 0FFD98 7F0CB268 03201025 */   move  $v0, $t9
.L7F0CB26C:
/* 0FFD9C 7F0CB26C 1A40004E */  blez  $s2, .L7F0CB3A8
/* 0FFDA0 7F0CB270 00003825 */   move  $a3, $zero
/* 0FFDA4 7F0CB274 262D0003 */  addiu $t5, $s1, 3
/* 0FFDA8 7F0CB278 31AE0FFC */  andi  $t6, $t5, 0xffc
/* 0FFDAC 7F0CB27C 000E6840 */  sll   $t5, $t6, 1
/* 0FFDB0 7F0CB280 00114040 */  sll   $t0, $s1, 1
/* 0FFDB4 7F0CB284 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CB288:
/* 0FFDB8 7F0CB288 1A200042 */  blez  $s1, .L7F0CB394
/* 0FFDBC 7F0CB28C 00001025 */   move  $v0, $zero
/* 0FFDC0 7F0CB290 32260001 */  andi  $a2, $s1, 1
/* 0FFDC4 7F0CB294 10C00013 */  beqz  $a2, .L7F0CB2E4
/* 0FFDC8 7F0CB298 2A010101 */   slti  $at, $s0, 0x101
/* 0FFDCC 7F0CB29C 10200009 */  beqz  $at, .L7F0CB2C4
/* 0FFDD0 7F0CB2A0 24020001 */   li    $v0, 1
/* 0FFDD4 7F0CB2A4 90980000 */  lbu   $t8, ($a0)
/* 0FFDD8 7F0CB2A8 0018C840 */  sll   $t9, $t8, 1
/* 0FFDDC 7F0CB2AC 00797021 */  addu  $t6, $v1, $t9
/* 0FFDE0 7F0CB2B0 95CF0000 */  lhu   $t7, ($t6)
/* 0FFDE4 7F0CB2B4 000FC040 */  sll   $t8, $t7, 1
/* 0FFDE8 7F0CB2B8 37190001 */  ori   $t9, $t8, 1
/* 0FFDEC 7F0CB2BC 10000008 */  b     .L7F0CB2E0
/* 0FFDF0 7F0CB2C0 A5590000 */   sh    $t9, ($t2)
.L7F0CB2C4:
/* 0FFDF4 7F0CB2C4 94AE0000 */  lhu   $t6, ($a1)
/* 0FFDF8 7F0CB2C8 000E7840 */  sll   $t7, $t6, 1
/* 0FFDFC 7F0CB2CC 006FC021 */  addu  $t8, $v1, $t7
/* 0FFE00 7F0CB2D0 97190000 */  lhu   $t9, ($t8)
/* 0FFE04 7F0CB2D4 00197040 */  sll   $t6, $t9, 1
/* 0FFE08 7F0CB2D8 35CF0001 */  ori   $t7, $t6, 1
/* 0FFE0C 7F0CB2DC A54F0000 */  sh    $t7, ($t2)
.L7F0CB2E0:
/* 0FFE10 7F0CB2E0 1051002C */  beq   $v0, $s1, .L7F0CB394
.L7F0CB2E4:
/* 0FFE14 7F0CB2E4 00024840 */   sll   $t1, $v0, 1
/* 0FFE18 7F0CB2E8 01495821 */  addu  $t3, $t2, $t1
.L7F0CB2EC:
/* 0FFE1C 7F0CB2EC 2A010101 */  slti  $at, $s0, 0x101
/* 0FFE20 7F0CB2F0 1020000A */  beqz  $at, .L7F0CB31C
/* 0FFE24 7F0CB2F4 00A97821 */   addu  $t7, $a1, $t1
/* 0FFE28 7F0CB2F8 0082C021 */  addu  $t8, $a0, $v0
/* 0FFE2C 7F0CB2FC 93190000 */  lbu   $t9, ($t8)
/* 0FFE30 7F0CB300 00197040 */  sll   $t6, $t9, 1
/* 0FFE34 7F0CB304 006E7821 */  addu  $t7, $v1, $t6
/* 0FFE38 7F0CB308 95F80000 */  lhu   $t8, ($t7)
/* 0FFE3C 7F0CB30C 0018C840 */  sll   $t9, $t8, 1
/* 0FFE40 7F0CB310 372E0001 */  ori   $t6, $t9, 1
/* 0FFE44 7F0CB314 10000008 */  b     .L7F0CB338
/* 0FFE48 7F0CB318 A56E0000 */   sh    $t6, ($t3)
.L7F0CB31C:
/* 0FFE4C 7F0CB31C 95F80000 */  lhu   $t8, ($t7)
/* 0FFE50 7F0CB320 0018C840 */  sll   $t9, $t8, 1
/* 0FFE54 7F0CB324 00797021 */  addu  $t6, $v1, $t9
/* 0FFE58 7F0CB328 95CF0000 */  lhu   $t7, ($t6)
/* 0FFE5C 7F0CB32C 000FC040 */  sll   $t8, $t7, 1
/* 0FFE60 7F0CB330 37190001 */  ori   $t9, $t8, 1
/* 0FFE64 7F0CB334 A5790000 */  sh    $t9, ($t3)
.L7F0CB338:
/* 0FFE68 7F0CB338 2A010101 */  slti  $at, $s0, 0x101
/* 0FFE6C 7F0CB33C 1020000A */  beqz  $at, .L7F0CB368
/* 0FFE70 7F0CB340 00A9C821 */   addu  $t9, $a1, $t1
/* 0FFE74 7F0CB344 00827021 */  addu  $t6, $a0, $v0
/* 0FFE78 7F0CB348 91CF0001 */  lbu   $t7, 1($t6)
/* 0FFE7C 7F0CB34C 000FC040 */  sll   $t8, $t7, 1
/* 0FFE80 7F0CB350 0078C821 */  addu  $t9, $v1, $t8
/* 0FFE84 7F0CB354 972E0000 */  lhu   $t6, ($t9)
/* 0FFE88 7F0CB358 000E7840 */  sll   $t7, $t6, 1
/* 0FFE8C 7F0CB35C 35F80001 */  ori   $t8, $t7, 1
/* 0FFE90 7F0CB360 10000008 */  b     .L7F0CB384
/* 0FFE94 7F0CB364 A5780002 */   sh    $t8, 2($t3)
.L7F0CB368:
/* 0FFE98 7F0CB368 972E0002 */  lhu   $t6, 2($t9)
/* 0FFE9C 7F0CB36C 000E7840 */  sll   $t7, $t6, 1
/* 0FFEA0 7F0CB370 006FC021 */  addu  $t8, $v1, $t7
/* 0FFEA4 7F0CB374 97190000 */  lhu   $t9, ($t8)
/* 0FFEA8 7F0CB378 00197040 */  sll   $t6, $t9, 1
/* 0FFEAC 7F0CB37C 35CF0001 */  ori   $t7, $t6, 1
/* 0FFEB0 7F0CB380 A56F0002 */  sh    $t7, 2($t3)
.L7F0CB384:
/* 0FFEB4 7F0CB384 24420002 */  addiu $v0, $v0, 2
/* 0FFEB8 7F0CB388 25290004 */  addiu $t1, $t1, 4
/* 0FFEBC 7F0CB38C 1451FFD7 */  bne   $v0, $s1, .L7F0CB2EC
/* 0FFEC0 7F0CB390 256B0004 */   addiu $t3, $t3, 4
.L7F0CB394:
/* 0FFEC4 7F0CB394 24E70001 */  addiu $a3, $a3, 1
/* 0FFEC8 7F0CB398 014D5021 */  addu  $t2, $t2, $t5
/* 0FFECC 7F0CB39C 00912021 */  addu  $a0, $a0, $s1
/* 0FFED0 7F0CB3A0 14F2FFB9 */  bne   $a3, $s2, .L7F0CB288
/* 0FFED4 7F0CB3A4 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB3A8:
/* 0FFED8 7F0CB3A8 26380003 */  addiu $t8, $s1, 3
/* 0FFEDC 7F0CB3AC 33190FFC */  andi  $t9, $t8, 0xffc
/* 0FFEE0 7F0CB3B0 03320019 */  multu $t9, $s2
/* 0FFEE4 7F0CB3B4 00001012 */  mflo  $v0
/* 0FFEE8 7F0CB3B8 00027040 */  sll   $t6, $v0, 1
/* 0FFEEC 7F0CB3BC 100000AA */  b     .L7F0CB668
/* 0FFEF0 7F0CB3C0 01C01025 */   move  $v0, $t6
.L7F0CB3C4:
/* 0FFEF4 7F0CB3C4 1A400069 */  blez  $s2, .L7F0CB56C
/* 0FFEF8 7F0CB3C8 00003825 */   move  $a3, $zero
/* 0FFEFC 7F0CB3CC 26290007 */  addiu $t1, $s1, 7
/* 0FFF00 7F0CB3D0 312F0FF8 */  andi  $t7, $t1, 0xff8
/* 0FFF04 7F0CB3D4 01E04825 */  move  $t1, $t7
/* 0FFF08 7F0CB3D8 00114040 */  sll   $t0, $s1, 1
/* 0FFF0C 7F0CB3DC 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CB3E0:
/* 0FFF10 7F0CB3E0 1A20005D */  blez  $s1, .L7F0CB558
/* 0FFF14 7F0CB3E4 00001025 */   move  $v0, $zero
/* 0FFF18 7F0CB3E8 32260003 */  andi  $a2, $s1, 3
/* 0FFF1C 7F0CB3EC 10C00016 */  beqz  $a2, .L7F0CB448
/* 0FFF20 7F0CB3F0 00C06025 */   move  $t4, $a2
/* 0FFF24 7F0CB3F4 01605021 */  addu  $t2, $t3, $zero
.L7F0CB3F8:
/* 0FFF28 7F0CB3F8 2A010101 */  slti  $at, $s0, 0x101
/* 0FFF2C 7F0CB3FC 10200008 */  beqz  $at, .L7F0CB420
/* 0FFF30 7F0CB400 0002C840 */   sll   $t9, $v0, 1
/* 0FFF34 7F0CB404 0082C021 */  addu  $t8, $a0, $v0
/* 0FFF38 7F0CB408 93190000 */  lbu   $t9, ($t8)
/* 0FFF3C 7F0CB40C 00197040 */  sll   $t6, $t9, 1
/* 0FFF40 7F0CB410 006E7821 */  addu  $t7, $v1, $t6
/* 0FFF44 7F0CB414 95F80000 */  lhu   $t8, ($t7)
/* 0FFF48 7F0CB418 10000007 */  b     .L7F0CB438
/* 0FFF4C 7F0CB41C A1580000 */   sb    $t8, ($t2)
.L7F0CB420:
/* 0FFF50 7F0CB420 00B97021 */  addu  $t6, $a1, $t9
/* 0FFF54 7F0CB424 95CF0000 */  lhu   $t7, ($t6)
/* 0FFF58 7F0CB428 000FC040 */  sll   $t8, $t7, 1
/* 0FFF5C 7F0CB42C 0078C821 */  addu  $t9, $v1, $t8
/* 0FFF60 7F0CB430 972E0000 */  lhu   $t6, ($t9)
/* 0FFF64 7F0CB434 A14E0000 */  sb    $t6, ($t2)
.L7F0CB438:
/* 0FFF68 7F0CB438 24420001 */  addiu $v0, $v0, 1
/* 0FFF6C 7F0CB43C 1582FFEE */  bne   $t4, $v0, .L7F0CB3F8
/* 0FFF70 7F0CB440 254A0001 */   addiu $t2, $t2, 1
/* 0FFF74 7F0CB444 10510044 */  beq   $v0, $s1, .L7F0CB558
.L7F0CB448:
/* 0FFF78 7F0CB448 01625021 */   addu  $t2, $t3, $v0
.L7F0CB44C:
/* 0FFF7C 7F0CB44C 2A010101 */  slti  $at, $s0, 0x101
/* 0FFF80 7F0CB450 10200008 */  beqz  $at, .L7F0CB474
/* 0FFF84 7F0CB454 0002C040 */   sll   $t8, $v0, 1
/* 0FFF88 7F0CB458 00827821 */  addu  $t7, $a0, $v0
/* 0FFF8C 7F0CB45C 91F80000 */  lbu   $t8, ($t7)
/* 0FFF90 7F0CB460 0018C840 */  sll   $t9, $t8, 1
/* 0FFF94 7F0CB464 00797021 */  addu  $t6, $v1, $t9
/* 0FFF98 7F0CB468 95CF0000 */  lhu   $t7, ($t6)
/* 0FFF9C 7F0CB46C 10000007 */  b     .L7F0CB48C
/* 0FFFA0 7F0CB470 A14F0000 */   sb    $t7, ($t2)
.L7F0CB474:
/* 0FFFA4 7F0CB474 00B8C821 */  addu  $t9, $a1, $t8
/* 0FFFA8 7F0CB478 972E0000 */  lhu   $t6, ($t9)
/* 0FFFAC 7F0CB47C 000E7840 */  sll   $t7, $t6, 1
/* 0FFFB0 7F0CB480 006FC021 */  addu  $t8, $v1, $t7
/* 0FFFB4 7F0CB484 97190000 */  lhu   $t9, ($t8)
/* 0FFFB8 7F0CB488 A1590000 */  sb    $t9, ($t2)
.L7F0CB48C:
/* 0FFFBC 7F0CB48C 2A010101 */  slti  $at, $s0, 0x101
/* 0FFFC0 7F0CB490 10200008 */  beqz  $at, .L7F0CB4B4
/* 0FFFC4 7F0CB494 00027840 */   sll   $t7, $v0, 1
/* 0FFFC8 7F0CB498 00827021 */  addu  $t6, $a0, $v0
/* 0FFFCC 7F0CB49C 91CF0001 */  lbu   $t7, 1($t6)
/* 0FFFD0 7F0CB4A0 000FC040 */  sll   $t8, $t7, 1
/* 0FFFD4 7F0CB4A4 0078C821 */  addu  $t9, $v1, $t8
/* 0FFFD8 7F0CB4A8 972E0000 */  lhu   $t6, ($t9)
/* 0FFFDC 7F0CB4AC 10000007 */  b     .L7F0CB4CC
/* 0FFFE0 7F0CB4B0 A14E0001 */   sb    $t6, 1($t2)
.L7F0CB4B4:
/* 0FFFE4 7F0CB4B4 00AFC021 */  addu  $t8, $a1, $t7
/* 0FFFE8 7F0CB4B8 97190002 */  lhu   $t9, 2($t8)
/* 0FFFEC 7F0CB4BC 00197040 */  sll   $t6, $t9, 1
/* 0FFFF0 7F0CB4C0 006E7821 */  addu  $t7, $v1, $t6
/* 0FFFF4 7F0CB4C4 95F80000 */  lhu   $t8, ($t7)
/* 0FFFF8 7F0CB4C8 A1580001 */  sb    $t8, 1($t2)
.L7F0CB4CC:
/* 0FFFFC 7F0CB4CC 2A010101 */  slti  $at, $s0, 0x101
/* 100000 7F0CB4D0 10200008 */  beqz  $at, .L7F0CB4F4
/* 100004 7F0CB4D4 00027040 */   sll   $t6, $v0, 1
/* 100008 7F0CB4D8 0082C821 */  addu  $t9, $a0, $v0
/* 10000C 7F0CB4DC 932E0002 */  lbu   $t6, 2($t9)
/* 100010 7F0CB4E0 000E7840 */  sll   $t7, $t6, 1
/* 100014 7F0CB4E4 006FC021 */  addu  $t8, $v1, $t7
/* 100018 7F0CB4E8 97190000 */  lhu   $t9, ($t8)
/* 10001C 7F0CB4EC 10000007 */  b     .L7F0CB50C
/* 100020 7F0CB4F0 A1590002 */   sb    $t9, 2($t2)
.L7F0CB4F4:
/* 100024 7F0CB4F4 00AE7821 */  addu  $t7, $a1, $t6
/* 100028 7F0CB4F8 95F80004 */  lhu   $t8, 4($t7)
/* 10002C 7F0CB4FC 0018C840 */  sll   $t9, $t8, 1
/* 100030 7F0CB500 00797021 */  addu  $t6, $v1, $t9
/* 100034 7F0CB504 95CF0000 */  lhu   $t7, ($t6)
/* 100038 7F0CB508 A14F0002 */  sb    $t7, 2($t2)
.L7F0CB50C:
/* 10003C 7F0CB50C 2A010101 */  slti  $at, $s0, 0x101
/* 100040 7F0CB510 10200008 */  beqz  $at, .L7F0CB534
/* 100044 7F0CB514 0002C840 */   sll   $t9, $v0, 1
/* 100048 7F0CB518 0082C021 */  addu  $t8, $a0, $v0
/* 10004C 7F0CB51C 93190003 */  lbu   $t9, 3($t8)
/* 100050 7F0CB520 00197040 */  sll   $t6, $t9, 1
/* 100054 7F0CB524 006E7821 */  addu  $t7, $v1, $t6
/* 100058 7F0CB528 95F80000 */  lhu   $t8, ($t7)
/* 10005C 7F0CB52C 10000007 */  b     .L7F0CB54C
/* 100060 7F0CB530 A1580003 */   sb    $t8, 3($t2)
.L7F0CB534:
/* 100064 7F0CB534 00B97021 */  addu  $t6, $a1, $t9
/* 100068 7F0CB538 95CF0006 */  lhu   $t7, 6($t6)
/* 10006C 7F0CB53C 000FC040 */  sll   $t8, $t7, 1
/* 100070 7F0CB540 0078C821 */  addu  $t9, $v1, $t8
/* 100074 7F0CB544 972E0000 */  lhu   $t6, ($t9)
/* 100078 7F0CB548 A14E0003 */  sb    $t6, 3($t2)
.L7F0CB54C:
/* 10007C 7F0CB54C 24420004 */  addiu $v0, $v0, 4
/* 100080 7F0CB550 1451FFBE */  bne   $v0, $s1, .L7F0CB44C
/* 100084 7F0CB554 254A0004 */   addiu $t2, $t2, 4
.L7F0CB558:
/* 100088 7F0CB558 24E70001 */  addiu $a3, $a3, 1
/* 10008C 7F0CB55C 01695821 */  addu  $t3, $t3, $t1
/* 100090 7F0CB560 00912021 */  addu  $a0, $a0, $s1
/* 100094 7F0CB564 14F2FF9E */  bne   $a3, $s2, .L7F0CB3E0
/* 100098 7F0CB568 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB56C:
/* 10009C 7F0CB56C 262F0007 */  addiu $t7, $s1, 7
/* 1000A0 7F0CB570 31F80FF8 */  andi  $t8, $t7, 0xff8
/* 1000A4 7F0CB574 03120019 */  multu $t8, $s2
/* 1000A8 7F0CB578 00001012 */  mflo  $v0
/* 1000AC 7F0CB57C 1000003B */  b     .L7F0CB66C
/* 1000B0 7F0CB580 8FB00004 */   lw    $s0, 4($sp)
.L7F0CB584:
/* 1000B4 7F0CB584 1A400031 */  blez  $s2, .L7F0CB64C
/* 1000B8 7F0CB588 00003825 */   move  $a3, $zero
/* 1000BC 7F0CB58C 2629000F */  addiu $t1, $s1, 0xf
/* 1000C0 7F0CB590 31390FF0 */  andi  $t9, $t1, 0xff0
/* 1000C4 7F0CB594 00194843 */  sra   $t1, $t9, 1
/* 1000C8 7F0CB598 00114040 */  sll   $t0, $s1, 1
/* 1000CC 7F0CB59C 8FA30038 */  lw    $v1, 0x38($sp)
.L7F0CB5A0:
/* 1000D0 7F0CB5A0 1A200025 */  blez  $s1, .L7F0CB638
/* 1000D4 7F0CB5A4 00001025 */   move  $v0, $zero
/* 1000D8 7F0CB5A8 2A010101 */  slti  $at, $s0, 0x101
.L7F0CB5AC:
/* 1000DC 7F0CB5AC 10200010 */  beqz  $at, .L7F0CB5F0
/* 1000E0 7F0CB5B0 0002C040 */   sll   $t8, $v0, 1
/* 1000E4 7F0CB5B4 00443021 */  addu  $a2, $v0, $a0
/* 1000E8 7F0CB5B8 90CF0001 */  lbu   $t7, 1($a2)
/* 1000EC 7F0CB5BC 000FC040 */  sll   $t8, $t7, 1
/* 1000F0 7F0CB5C0 90CF0000 */  lbu   $t7, ($a2)
/* 1000F4 7F0CB5C4 0078C821 */  addu  $t9, $v1, $t8
/* 1000F8 7F0CB5C8 972E0000 */  lhu   $t6, ($t9)
/* 1000FC 7F0CB5CC 000FC040 */  sll   $t8, $t7, 1
/* 100100 7F0CB5D0 0078C821 */  addu  $t9, $v1, $t8
/* 100104 7F0CB5D4 972F0000 */  lhu   $t7, ($t9)
/* 100108 7F0CB5D8 000FC100 */  sll   $t8, $t7, 4
/* 10010C 7F0CB5DC 00027843 */  sra   $t7, $v0, 1
/* 100110 7F0CB5E0 01D8C825 */  or    $t9, $t6, $t8
/* 100114 7F0CB5E4 016F7021 */  addu  $t6, $t3, $t7
/* 100118 7F0CB5E8 1000000F */  b     .L7F0CB628
/* 10011C 7F0CB5EC A1D90000 */   sb    $t9, ($t6)
.L7F0CB5F0:
/* 100120 7F0CB5F0 00B83021 */  addu  $a2, $a1, $t8
/* 100124 7F0CB5F4 94CF0002 */  lhu   $t7, 2($a2)
/* 100128 7F0CB5F8 000FC840 */  sll   $t9, $t7, 1
/* 10012C 7F0CB5FC 94CF0000 */  lhu   $t7, ($a2)
/* 100130 7F0CB600 00797021 */  addu  $t6, $v1, $t9
/* 100134 7F0CB604 95D80000 */  lhu   $t8, ($t6)
/* 100138 7F0CB608 000FC840 */  sll   $t9, $t7, 1
/* 10013C 7F0CB60C 00797021 */  addu  $t6, $v1, $t9
/* 100140 7F0CB610 95CF0000 */  lhu   $t7, ($t6)
/* 100144 7F0CB614 000FC900 */  sll   $t9, $t7, 4
/* 100148 7F0CB618 00027843 */  sra   $t7, $v0, 1
/* 10014C 7F0CB61C 03197025 */  or    $t6, $t8, $t9
/* 100150 7F0CB620 016FC021 */  addu  $t8, $t3, $t7
/* 100154 7F0CB624 A30E0000 */  sb    $t6, ($t8)
.L7F0CB628:
/* 100158 7F0CB628 24420002 */  addiu $v0, $v0, 2
/* 10015C 7F0CB62C 0051082A */  slt   $at, $v0, $s1
/* 100160 7F0CB630 5420FFDE */  bnezl $at, .L7F0CB5AC
/* 100164 7F0CB634 2A010101 */   slti  $at, $s0, 0x101
.L7F0CB638:
/* 100168 7F0CB638 24E70001 */  addiu $a3, $a3, 1
/* 10016C 7F0CB63C 01695821 */  addu  $t3, $t3, $t1
/* 100170 7F0CB640 00912021 */  addu  $a0, $a0, $s1
/* 100174 7F0CB644 14F2FFD6 */  bne   $a3, $s2, .L7F0CB5A0
/* 100178 7F0CB648 00A82821 */   addu  $a1, $a1, $t0
.L7F0CB64C:
/* 10017C 7F0CB64C 2639000F */  addiu $t9, $s1, 0xf
/* 100180 7F0CB650 332F0FF0 */  andi  $t7, $t9, 0xff0
/* 100184 7F0CB654 000F7043 */  sra   $t6, $t7, 1
/* 100188 7F0CB658 01D20019 */  multu $t6, $s2
/* 10018C 7F0CB65C 00001012 */  mflo  $v0
/* 100190 7F0CB660 10000002 */  b     .L7F0CB66C
/* 100194 7F0CB664 8FB00004 */   lw    $s0, 4($sp)
def_7F0CACBC:
.L7F0CB668:
/* 100198 7F0CB668 8FB00004 */  lw    $s0, 4($sp)
.L7F0CB66C:
/* 10019C 7F0CB66C 8FB10008 */  lw    $s1, 8($sp)
/* 1001A0 7F0CB670 8FB2000C */  lw    $s2, 0xc($sp)
/* 1001A4 7F0CB674 03E00008 */  jr    $ra
/* 1001A8 7F0CB678 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





/**
 * For every second row, swap the bytes within that row.
 *
 * For textures with 32-bit colour values (in GBI format), swap every pair
 * within each word. For all other textures, swap every byte within each pair.
 */
void texSwapAltRowBytes(u8 *dst, s32 width, s32 height, s32 format)
{
	s32 x;
	s32 y;
	s32 alignedwidth;
	u32 *row = (u32 *)dst;
	s32 tmp;

	switch (format) {
	case TEXFORMAT_RGBA32:
	case TEXFORMAT_RGB24:
		alignedwidth = (width + 3) & 0xffc;
		break;
	case TEXFORMAT_RGBA16:
	case TEXFORMAT_RGB15:
	case TEXFORMAT_IA16:
		alignedwidth = ((width + 3) & 0xffc) >> 1;
		break;
	case TEXFORMAT_IA8:
	case TEXFORMAT_I8:
	case TEXFORMAT_RGBA16_CI8:
	case TEXFORMAT_IA16_CI8:
		alignedwidth = ((width + 7) & 0xff8) >> 2;
		break;
	case TEXFORMAT_IA4:
	case TEXFORMAT_I4:
	case TEXFORMAT_RGBA16_CI4:
	case TEXFORMAT_0C:
		alignedwidth = ((width + 0xf) & 0xff0) >> 3;
		break;
	}

	row += alignedwidth;

	if (format == TEXFORMAT_RGBA32 || format == TEXFORMAT_RGB24) {
		for (y = 1; y < height; y += 2) {
			for (x = 0; x < alignedwidth; x += 4) {
				tmp = row[x + 0];
				row[x + 0] = row[x + 2];
				row[x + 2] = tmp;

				tmp = row[x + 1];
				row[x + 1] = row[x + 3];
				row[x + 3] = tmp;
			}

			row += alignedwidth * 2;
		}
	} else {
		for (y = 1; y < height; y += 2) {
			for (x = 0; x < alignedwidth; x += 2) {
				tmp = row[x + 0];
				row[x + 0] = row[x + 1];
				row[x + 1] = tmp;
			}

			row += alignedwidth * 2;
		}
	}
}






/**
 * Blur the pixels in the image with the surrounding pixels.
 */
void texBlur(u8 *pixels, s32 width, s32 height, s32 method, s32 chansize)
{
	s32 x;
	s32 y;

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			s32 cur = pixels[y * width + x] + chansize * 2;
			s32 left = x > 0 ? pixels[y * width + x - 1] : 0;
			s32 above = y > 0 ? pixels[(y - 1) * width + x] : 0;
			s32 aboveleft = x > 0 && y > 0 ? pixels[(y - 1) * width + x - 1] : 0;

			switch (method) {
			case 0:
				pixels[y * width + x] = (cur + left) % chansize;
				break;
			case 1:
				pixels[y * width + x] = (cur + above) % chansize;
				break;
			case 2:
				pixels[y * width + x] = (cur + aboveleft) % chansize;
				break;
			case 3:
				pixels[y * width + x] = (cur + (left + above - aboveleft)) % chansize;
				break;
			case 4:
				pixels[y * width + x] = (cur + ((above - aboveleft) / 2 + left)) % chansize;
				break;
			case 5:
				pixels[y * width + x] = (cur + ((left - aboveleft) / 2 + above)) % chansize;
				break;
			case 6:
				pixels[y * width + x] = (cur + ((left + above) / 2)) % chansize;
				break;
			}
		}
	}
}





#ifdef NONMATCHING
void sub_GAME_7F0CBAF4(struct texturething *arg0, u8 *arg1, s32 arg2)
{
	arg0->unk00 = (struct texloadthing *)arg1;
	arg0->unk04 = (struct texloadthing *)(arg1 + arg2);
	arg0->unk08 = (struct texloadthing *)arg1;
	arg0->unk0c = (struct texloadthing *)((s32)arg1 + arg2);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CBAF4
/* 100624 7F0CBAF4 00A61021 */  addu  $v0, $a1, $a2
/* 100628 7F0CBAF8 AC850000 */  sw    $a1, ($a0)
/* 10062C 7F0CBAFC AC820004 */  sw    $v0, 4($a0)
/* 100630 7F0CBB00 AC850008 */  sw    $a1, 8($a0)
/* 100634 7F0CBB04 03E00008 */  jr    $ra
/* 100638 7F0CBB08 AC82000C */   sw    $v0, 0xc($a0)
)
#endif





#ifdef NONMATCHING
struct texloadthing *sub_GAME_7F0CBB0C(s32 texturenum, struct texturething *arg1)
{
	struct texloadthing *end;
	struct texloadthing *cur;
	s32 i;

	if (arg1 == NULL) {
		arg1 = &ptr_texture_alloc_start;
	}

	if (arg1 == ptr_texture_alloc_start) {
		cur = arg1->unk04;

		while (cur) {
			if (cur->texturenum == texturenum) {
				return cur;
			}

			if (!cur->unk0c_04) {
				return NULL;
			}

			cur = (struct texloadthing *)PHYS_TO_K0(cur->unk0c_04);
		}

		return NULL;
	}

	end = arg1->unk04;
	cur = arg1->unk0c;

	while (cur < end) {
		if (cur->texturenum == texturenum) {
			return cur;
		}

		cur++;
	}

	return NULL;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CBB0C
/* 10063C 7F0CBB0C 54A00004 */  bnezl $a1, .L7F0CBB20
/* 100640 7F0CBB10 8CA20004 */   lw    $v0, 4($a1)
/* 100644 7F0CBB14 3C058009 */  lui   $a1, %hi(ptr_texture_alloc_start)
/* 100648 7F0CBB18 24A5C720 */  addiu $a1, %lo(ptr_texture_alloc_start) # addiu $a1, $a1, -0x38e0
/* 10064C 7F0CBB1C 8CA20004 */  lw    $v0, 4($a1)
.L7F0CBB20:
/* 100650 7F0CBB20 8CA3000C */  lw    $v1, 0xc($a1)
/* 100654 7F0CBB24 0062082B */  sltu  $at, $v1, $v0
/* 100658 7F0CBB28 5020000C */  beql  $at, $zero, .L7F0CBB5C
/* 10065C 7F0CBB2C 00001025 */   move  $v0, $zero
/* 100660 7F0CBB30 8C6E0000 */  lw    $t6, ($v1)
.L7F0CBB34:
/* 100664 7F0CBB34 000E7D02 */  srl   $t7, $t6, 0x14
/* 100668 7F0CBB38 548F0004 */  bnel  $a0, $t7, .L7F0CBB4C
/* 10066C 7F0CBB3C 24630010 */   addiu $v1, $v1, 0x10
/* 100670 7F0CBB40 03E00008 */  jr    $ra
/* 100674 7F0CBB44 00601025 */   move  $v0, $v1

/* 100678 7F0CBB48 24630010 */  addiu $v1, $v1, 0x10
.L7F0CBB4C:
/* 10067C 7F0CBB4C 0062082B */  sltu  $at, $v1, $v0
/* 100680 7F0CBB50 5420FFF8 */  bnezl $at, .L7F0CBB34
/* 100684 7F0CBB54 8C6E0000 */   lw    $t6, ($v1)
/* 100688 7F0CBB58 00001025 */  move  $v0, $zero
.L7F0CBB5C:
/* 10068C 7F0CBB5C 03E00008 */  jr    $ra
/* 100690 7F0CBB60 00000000 */   nop   
)
#endif






s32 texFreeBytesInBuffer(struct texturething *arg0)
{
	return (u32)arg0->unk0c - (u32)arg0->unk08;
}





#ifdef NONMATCHING
void texLoadFromDisplayList(Gfx *gdl, struct texturething *arg1, s32 arg2)
{
	u8 *bytes = (u8 *)gdl;

	while (bytes[0] != (u8)G_ENDDL) {
		// Look for GBI sequence: fd...... abcd....
		if (bytes[0] == G_SETTIMG && bytes[4] == 0xab && bytes[5] == 0xcd) {
			texLoad((u32 *)((s32)bytes + 4), arg1, arg2);
		}

		bytes += 8;
	}
}
#else
GLOBAL_ASM(
.text
glabel texLoadFromDisplayList
/* 1006A4 7F0CBB74 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1006A8 7F0CBB78 AFBF002C */  sw    $ra, 0x2c($sp)
/* 1006AC 7F0CBB7C AFB50028 */  sw    $s5, 0x28($sp)
/* 1006B0 7F0CBB80 AFB40024 */  sw    $s4, 0x24($sp)
/* 1006B4 7F0CBB84 AFB30020 */  sw    $s3, 0x20($sp)
/* 1006B8 7F0CBB88 AFB2001C */  sw    $s2, 0x1c($sp)
/* 1006BC 7F0CBB8C AFB10018 */  sw    $s1, 0x18($sp)
/* 1006C0 7F0CBB90 AFB00014 */  sw    $s0, 0x14($sp)
/* 1006C4 7F0CBB94 908E0000 */  lbu   $t6, ($a0)
/* 1006C8 7F0CBB98 241200B8 */  li    $s2, 184
/* 1006CC 7F0CBB9C 00A08825 */  move  $s1, $a1
/* 1006D0 7F0CBBA0 124E0014 */  beq   $s2, $t6, .L7F0CBBF4
/* 1006D4 7F0CBBA4 00808025 */   move  $s0, $a0
/* 1006D8 7F0CBBA8 90820000 */  lbu   $v0, ($a0)
/* 1006DC 7F0CBBAC 241500CD */  li    $s5, 205
/* 1006E0 7F0CBBB0 241400AB */  li    $s4, 171
/* 1006E4 7F0CBBB4 241300FD */  li    $s3, 253
.L7F0CBBB8:
/* 1006E8 7F0CBBB8 5662000B */  bnel  $s3, $v0, .L7F0CBBE8
/* 1006EC 7F0CBBBC 92020008 */   lbu   $v0, 8($s0)
/* 1006F0 7F0CBBC0 920F0004 */  lbu   $t7, 4($s0)
/* 1006F4 7F0CBBC4 568F0008 */  bnel  $s4, $t7, .L7F0CBBE8
/* 1006F8 7F0CBBC8 92020008 */   lbu   $v0, 8($s0)
/* 1006FC 7F0CBBCC 92180005 */  lbu   $t8, 5($s0)
/* 100700 7F0CBBD0 26040004 */  addiu $a0, $s0, 4
/* 100704 7F0CBBD4 56B80004 */  bnel  $s5, $t8, .L7F0CBBE8
/* 100708 7F0CBBD8 92020008 */   lbu   $v0, 8($s0)
/* 10070C 7F0CBBDC 0FC32F06 */  jal   texLoad
/* 100710 7F0CBBE0 02202825 */   move  $a1, $s1
/* 100714 7F0CBBE4 92020008 */  lbu   $v0, 8($s0)
.L7F0CBBE8:
/* 100718 7F0CBBE8 26100008 */  addiu $s0, $s0, 8
/* 10071C 7F0CBBEC 1642FFF2 */  bne   $s2, $v0, .L7F0CBBB8
/* 100720 7F0CBBF0 00000000 */   nop   
.L7F0CBBF4:
/* 100724 7F0CBBF4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 100728 7F0CBBF8 8FB00014 */  lw    $s0, 0x14($sp)
/* 10072C 7F0CBBFC 8FB10018 */  lw    $s1, 0x18($sp)
/* 100730 7F0CBC00 8FB2001C */  lw    $s2, 0x1c($sp)
/* 100734 7F0CBC04 8FB30020 */  lw    $s3, 0x20($sp)
/* 100738 7F0CBC08 8FB40024 */  lw    $s4, 0x24($sp)
/* 10073C 7F0CBC0C 8FB50028 */  lw    $s5, 0x28($sp)
/* 100740 7F0CBC10 03E00008 */  jr    $ra
/* 100744 7F0CBC14 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
extern u8 _imagesSegmentRomStart;
void texLoad(u32 *ptr, struct texturething *arg1)
{
	//u8 sp14b0[0x1400];
	u8 *sp14ac_ptr;
	s32 sp14a8;
	s32 sp14a4_iszlib;
	s32 sp14a0_lod;
	struct texloadthing *ptVar3;
	//u32 freebytes;
	//u32 stack;
	//struct texloadthing *sp1490;
	//u32 stack2;
	//u8 sp148b_usingsharedstruct;
	//s8 sp48[5187];
	s32 image_load_address;
	s32 sp38;
	//struct texloadthing *sp34;
	//s32 sp30;
	u8 imagebuffer[4010];

	//sp148b_usingsharedstruct = 0;

	if (arg1 == NULL) {
		arg1 = &ptr_texture_alloc_start;
	}

	//if (arg1 == &ptr_texture_alloc_start) {
	//	sp148b_usingsharedstruct = 1;
	//}

	//if ((*ptr & 0xffff0000) == 0 || (*ptr & 0xffff0000) == 0xabcd0000) {
	imageid = *ptr & 0xffff;

	ptVar3 = sub_GAME_7F0CBB0C(imageid, arg1);

	if (ptVar3 == NULL /*&& imageid < NUM_TEXTURES//*/) {
		*imagebuffer = (u8)(((u32)imagebuffer + 0xf) >> 4 << 4);

		//if (imagebuffer);

		osWritebackDCacheAll();
		osInvalDCache(imagebuffer, 0x2000);

		//if (g_Textures[imageid].dataoffset == g_Textures[imageid + 1].dataoffset) {
		//	return;
		//}

		image_load_address = g_Textures[imageid].dataoffset;

		romCopy(imagebuffer,
				(u32)&_imagesSegmentRomStart + (image_load_address & ~7),
				(((g_Textures[imageid + 1].dataoffset - image_load_address) + 0x1f) >> 4) * 0x10);

		//if (sp148b_usingsharedstruct);
		sp14ac_ptr = imagebuffer + (image_load_address & 7);
		sp14a8 = (*sp14ac_ptr & 0x80) >> 7;
		sp14a4_iszlib = (*sp14ac_ptr & 0x40) >> 6;
		sp14a0_lod = *sp14ac_ptr & 0x3f;

		//if (sp14a0_lod > 5) {
		//	sp14a0_lod = 5;
		//}

		sp14ac_ptr++;

		//if (sp148b_usingsharedstruct) {
		//	freebytes = mempGetPoolFree(MEMPOOL_STAGE, MEMBANK_ONBOARD) + mempGetPoolFree(MEMPOOL_STAGE, MEMBANK_EXPANSION);
		//} else {
				//freebytes = texFreeBytesInBuffer(arg1);
		//}

		if ((sp14a4_iszlib == 0 && texFreeBytesInBuffer(arg1) < 4300) || (sp14a4_iszlib != 0 && texFreeBytesInBuffer(arg1) < 2600)) {
			*ptr = osVirtualToPhysical(arg1->unk00);
			return;
		}

		//if (sp148b_usingsharedstruct) {
		//	sp1490 = arg1->unk0c;
		//	arg1->unk0c = (struct texloadthing *)((((u32)sp48 + 0xf) >> 4 << 4) + 0x10);
		//	arg1->unk08 = arg1->unk0c + 1;
        //
		//	while (sp1490) {
		//		if (sp1490->unk0c_04 == 0) {
		//			break;
		//		}
        //
		//		sp1490 = (struct texloadthing *)PHYS_TO_K0(sp1490->unk0c_04);
		//	}
		//}

		*(s16 *)(arg1->unk08) = imageid;
		arg1->unk08 = (void *)((u32)arg1->unk08 + 8);
		ptVar3 = (struct texloadthing *)(arg1->unk0c - 1);
		arg1->unk0c = ptVar3;
		ptVar3->texturenum = imageid;
		ptVar3->unk04 = arg1->unk08;
		ptVar3->unk0c_03 = 0;

		if (sp14a4_iszlib) {
			sp38 = texInflateZlib(sp14ac_ptr, (u32 *)arg1->unk08, sp14a8, sp14a0_lod, arg1/*, arg2//*/);
		} else {
			sp38 = texInflateNonZlib(sp14ac_ptr, (u32 *)arg1->unk08, sp14a8, sp14a0_lod, arg1/*, arg2//*/);
			}

		//if (sp148b_usingsharedstruct) {
		//	sp34 = mempAllocFromRight(ALIGN16(sp38 + 0x20), MEMPOOL_STAGE);
		//	arg1->unk0c = sp34;
		//
		//	bcopy(ptVar3, sp34, 0x10);
		//
		//	ptVar3 = sp34;
		//	sp34++;
		//
		//	bcopy((void *)((u32)arg1->unk08 - 8), sp34, sp38 + 8);
		//
		//	arg1->unk0c->unk04 = (void *)((u32)sp34 + 8);
		//	arg1->unk0c->unk0c_04 = 0;
		//
		//	if (sp1490 != NULL) {
		//		sp1490->unk0c_04 = (u32)arg1->unk0c & 0xffffff;
		//	} else {
		//		arg1->unk04 = arg1->unk0c;
		//	}
		//
		//	arg1->unk00 = arg1->unk0c;
		//}

		arg1->unk08 = (void *)((u32)arg1->unk08 + sp38);

		//if (!sp148b_usingsharedstruct) {
		texFreeBytesInBuffer(arg1);
		//}
		
	}

	*ptr = osVirtualToPhysical(ptVar3->unk04);
}
#else
GLOBAL_ASM(
.text
glabel texLoad
/* 100748 7F0CBC18 27BDF008 */  addiu $sp, $sp, -0xff8
/* 10074C 7F0CBC1C AFB00020 */  sw    $s0, 0x20($sp)
/* 100750 7F0CBC20 00A08025 */  move  $s0, $a1
/* 100754 7F0CBC24 AFBF0024 */  sw    $ra, 0x24($sp)
/* 100758 7F0CBC28 14A00003 */  bnez  $a1, .L7F0CBC38
/* 10075C 7F0CBC2C AFA40FF8 */   sw    $a0, 0xff8($sp)
/* 100760 7F0CBC30 3C108009 */  lui   $s0, %hi(ptr_texture_alloc_start)
/* 100764 7F0CBC34 2610C720 */  addiu $s0, %lo(ptr_texture_alloc_start) # addiu $s0, $s0, -0x38e0
.L7F0CBC38:
/* 100768 7F0CBC38 8FAE0FF8 */  lw    $t6, 0xff8($sp)
/* 10076C 7F0CBC3C 3C028009 */  lui   $v0, %hi(imageid)
/* 100770 7F0CBC40 2442D094 */  addiu $v0, %lo(imageid) # addiu $v0, $v0, -0x2f6c
/* 100774 7F0CBC44 8DCF0000 */  lw    $t7, ($t6)
/* 100778 7F0CBC48 02002825 */  move  $a1, $s0
/* 10077C 7F0CBC4C 31E4FFFF */  andi  $a0, $t7, 0xffff
/* 100780 7F0CBC50 0FC32EC3 */  jal   sub_GAME_7F0CBB0C
/* 100784 7F0CBC54 AC440000 */   sw    $a0, ($v0)
/* 100788 7F0CBC58 14400074 */  bnez  $v0, .L7F0CBE2C
/* 10078C 7F0CBC5C 00401825 */   move  $v1, $v0
/* 100790 7F0CBC60 27A30067 */  addiu $v1, $sp, 0x67
/* 100794 7F0CBC64 0003C902 */  srl   $t9, $v1, 4
/* 100798 7F0CBC68 00194100 */  sll   $t0, $t9, 4
/* 10079C 7F0CBC6C 0C0034C8 */  jal   osWritebackDCacheAll
/* 1007A0 7F0CBC70 AFA8002C */   sw    $t0, 0x2c($sp)
/* 1007A4 7F0CBC74 8FA4002C */  lw    $a0, 0x2c($sp)
/* 1007A8 7F0CBC78 0C0042C8 */  jal   osInvalDCache
/* 1007AC 7F0CBC7C 24052000 */   li    $a1, 8192
/* 1007B0 7F0CBC80 3C098009 */  lui   $t1, %hi(imageid) 
/* 1007B4 7F0CBC84 8D29D094 */  lw    $t1, %lo(imageid)($t1)
/* 1007B8 7F0CBC88 3C0B8005 */  lui   $t3, %hi(g_Textures) 
/* 1007BC 7F0CBC8C 256B9300 */  addiu $t3, %lo(g_Textures) # addiu $t3, $t3, -0x6d00
/* 1007C0 7F0CBC90 000950C0 */  sll   $t2, $t1, 3
/* 1007C4 7F0CBC94 014B1021 */  addu  $v0, $t2, $t3
/* 1007C8 7F0CBC98 8C430000 */  lw    $v1, ($v0)
/* 1007CC 7F0CBC9C 8C470008 */  lw    $a3, 8($v0)
/* 1007D0 7F0CBCA0 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 1007D4 7F0CBCA4 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 1007D8 7F0CBCA8 00616024 */  and   $t4, $v1, $at
/* 1007DC 7F0CBCAC 00E16824 */  and   $t5, $a3, $at
/* 1007E0 7F0CBCB0 01AC3023 */  subu  $a2, $t5, $t4
/* 1007E4 7F0CBCB4 24C6001F */  addiu $a2, $a2, 0x1f
/* 1007E8 7F0CBCB8 2401FFF8 */  li    $at, -8
/* 1007EC 7F0CBCBC 3C0F008F */  lui   $t7, %hi(_imagesSegmentRomStart) # $t7, 0x8f
/* 1007F0 7F0CBCC0 25EF7DF0 */  addiu $t7, %lo(_imagesSegmentRomStart) # addiu $t7, $t7, 0x7df0
/* 1007F4 7F0CBCC4 01817024 */  and   $t6, $t4, $at
/* 1007F8 7F0CBCC8 0006C102 */  srl   $t8, $a2, 4
/* 1007FC 7F0CBCCC 00183100 */  sll   $a2, $t8, 4
/* 100800 7F0CBCD0 01CF2821 */  addu  $a1, $t6, $t7
/* 100804 7F0CBCD4 AFAC003C */  sw    $t4, 0x3c($sp)
/* 100808 7F0CBCD8 0C001707 */  jal   romCopy
/* 10080C 7F0CBCDC 8FA4002C */   lw    $a0, 0x2c($sp)
/* 100810 7F0CBCE0 8FA3003C */  lw    $v1, 0x3c($sp)
/* 100814 7F0CBCE4 8FA8002C */  lw    $t0, 0x2c($sp)
/* 100818 7F0CBCE8 02002025 */  move  $a0, $s0
/* 10081C 7F0CBCEC 30690007 */  andi  $t1, $v1, 7
/* 100820 7F0CBCF0 01095021 */  addu  $t2, $t0, $t1
/* 100824 7F0CBCF4 AFAA0054 */  sw    $t2, 0x54($sp)
/* 100828 7F0CBCF8 91420000 */  lbu   $v0, ($t2)
/* 10082C 7F0CBCFC 254D0001 */  addiu $t5, $t2, 1
/* 100830 7F0CBD00 AFAD0054 */  sw    $t5, 0x54($sp)
/* 100834 7F0CBD04 30460080 */  andi  $a2, $v0, 0x80
/* 100838 7F0CBD08 30450040 */  andi  $a1, $v0, 0x40
/* 10083C 7F0CBD0C 000659C3 */  sra   $t3, $a2, 7
/* 100840 7F0CBD10 00056183 */  sra   $t4, $a1, 6
/* 100844 7F0CBD14 01603025 */  move  $a2, $t3
/* 100848 7F0CBD18 01802825 */  move  $a1, $t4
/* 10084C 7F0CBD1C 1580000A */  bnez  $t4, .L7F0CBD48
/* 100850 7F0CBD20 3047003F */   andi  $a3, $v0, 0x3f
/* 100854 7F0CBD24 AFAC004C */  sw    $t4, 0x4c($sp)
/* 100858 7F0CBD28 AFAB0050 */  sw    $t3, 0x50($sp)
/* 10085C 7F0CBD2C 0FC32ED9 */  jal   texFreeBytesInBuffer
/* 100860 7F0CBD30 AFA70048 */   sw    $a3, 0x48($sp)
/* 100864 7F0CBD34 284110CC */  slti  $at, $v0, 0x10cc
/* 100868 7F0CBD38 8FA5004C */  lw    $a1, 0x4c($sp)
/* 10086C 7F0CBD3C 8FA60050 */  lw    $a2, 0x50($sp)
/* 100870 7F0CBD40 1420000C */  bnez  $at, .L7F0CBD74
/* 100874 7F0CBD44 8FA70048 */   lw    $a3, 0x48($sp)
.L7F0CBD48:
/* 100878 7F0CBD48 10A0000F */  beqz  $a1, .L7F0CBD88
/* 10087C 7F0CBD4C 02002025 */   move  $a0, $s0
/* 100880 7F0CBD50 AFA5004C */  sw    $a1, 0x4c($sp)
/* 100884 7F0CBD54 AFA60050 */  sw    $a2, 0x50($sp)
/* 100888 7F0CBD58 0FC32ED9 */  jal   texFreeBytesInBuffer
/* 10088C 7F0CBD5C AFA70048 */   sw    $a3, 0x48($sp)
/* 100890 7F0CBD60 28410A28 */  slti  $at, $v0, 0xa28
/* 100894 7F0CBD64 8FA5004C */  lw    $a1, 0x4c($sp)
/* 100898 7F0CBD68 8FA60050 */  lw    $a2, 0x50($sp)
/* 10089C 7F0CBD6C 10200006 */  beqz  $at, .L7F0CBD88
/* 1008A0 7F0CBD70 8FA70048 */   lw    $a3, 0x48($sp)
.L7F0CBD74:
/* 1008A4 7F0CBD74 0C003A2C */  jal   osVirtualToPhysical
/* 1008A8 7F0CBD78 8E040000 */   lw    $a0, ($s0)
/* 1008AC 7F0CBD7C 8FAE0FF8 */  lw    $t6, 0xff8($sp)
/* 1008B0 7F0CBD80 1000002E */  b     .L7F0CBE3C
/* 1008B4 7F0CBD84 ADC20000 */   sw    $v0, ($t6)
.L7F0CBD88:
/* 1008B8 7F0CBD88 3C0F8009 */  lui   $t7, %hi(imageid) 
/* 1008BC 7F0CBD8C 8E020008 */  lw    $v0, 8($s0)
/* 1008C0 7F0CBD90 8DEFD094 */  lw    $t7, %lo(imageid)($t7)
/* 1008C4 7F0CBD94 3C0B8009 */  lui   $t3, %hi(imageid) 
/* 1008C8 7F0CBD98 A44F0000 */  sh    $t7, ($v0)
/* 1008CC 7F0CBD9C 8E180008 */  lw    $t8, 8($s0)
/* 1008D0 7F0CBDA0 8E08000C */  lw    $t0, 0xc($s0)
/* 1008D4 7F0CBDA4 27190008 */  addiu $t9, $t8, 8
/* 1008D8 7F0CBDA8 2509FFF0 */  addiu $t1, $t0, -0x10
/* 1008DC 7F0CBDAC AE190008 */  sw    $t9, 8($s0)
/* 1008E0 7F0CBDB0 AE09000C */  sw    $t1, 0xc($s0)
/* 1008E4 7F0CBDB4 952E0000 */  lhu   $t6, ($t1)
/* 1008E8 7F0CBDB8 8D6CD094 */  lw    $t4, %lo(imageid)($t3)
/* 1008EC 7F0CBDBC 01201825 */  move  $v1, $t1
/* 1008F0 7F0CBDC0 31CF000F */  andi  $t7, $t6, 0xf
/* 1008F4 7F0CBDC4 000C6900 */  sll   $t5, $t4, 4
/* 1008F8 7F0CBDC8 01AFC025 */  or    $t8, $t5, $t7
/* 1008FC 7F0CBDCC A5380000 */  sh    $t8, ($t1)
/* 100900 7F0CBDD0 8E190008 */  lw    $t9, 8($s0)
/* 100904 7F0CBDD4 10A00008 */  beqz  $a1, .L7F0CBDF8
/* 100908 7F0CBDD8 AD390004 */   sw    $t9, 4($t1)
/* 10090C 7F0CBDDC 8E050008 */  lw    $a1, 8($s0)
/* 100910 7F0CBDE0 AFA90044 */  sw    $t1, 0x44($sp)
/* 100914 7F0CBDE4 AFB00010 */  sw    $s0, 0x10($sp)
/* 100918 7F0CBDE8 0FC31996 */  jal   texInflateZlib
/* 10091C 7F0CBDEC 8FA40054 */   lw    $a0, 0x54($sp)
/* 100920 7F0CBDF0 10000007 */  b     .L7F0CBE10
/* 100924 7F0CBDF4 8FA30044 */   lw    $v1, 0x44($sp)
.L7F0CBDF8:
/* 100928 7F0CBDF8 8E050008 */  lw    $a1, 8($s0)
/* 10092C 7F0CBDFC AFA30044 */  sw    $v1, 0x44($sp)
/* 100930 7F0CBE00 AFB00010 */  sw    $s0, 0x10($sp)
/* 100934 7F0CBE04 0FC31F7F */  jal   texInflateNonZlib
/* 100938 7F0CBE08 8FA40054 */   lw    $a0, 0x54($sp)
/* 10093C 7F0CBE0C 8FA30044 */  lw    $v1, 0x44($sp)
.L7F0CBE10:
/* 100940 7F0CBE10 8E080008 */  lw    $t0, 8($s0)
/* 100944 7F0CBE14 02002025 */  move  $a0, $s0
/* 100948 7F0CBE18 01024821 */  addu  $t1, $t0, $v0
/* 10094C 7F0CBE1C AE090008 */  sw    $t1, 8($s0)
/* 100950 7F0CBE20 0FC32ED9 */  jal   texFreeBytesInBuffer
/* 100954 7F0CBE24 AFA30044 */   sw    $v1, 0x44($sp)
/* 100958 7F0CBE28 8FA30044 */  lw    $v1, 0x44($sp)
.L7F0CBE2C:
/* 10095C 7F0CBE2C 0C003A2C */  jal   osVirtualToPhysical
/* 100960 7F0CBE30 8C640004 */   lw    $a0, 4($v1)
/* 100964 7F0CBE34 8FAB0FF8 */  lw    $t3, 0xff8($sp)
/* 100968 7F0CBE38 AD620000 */  sw    $v0, ($t3)
.L7F0CBE3C:
/* 10096C 7F0CBE3C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 100970 7F0CBE40 8FB00020 */  lw    $s0, 0x20($sp)
/* 100974 7F0CBE44 27BD0FF8 */  addiu $sp, $sp, 0xff8
/* 100978 7F0CBE48 03E00008 */  jr    $ra
/* 10097C 7F0CBE4C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CBE50(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CBE50
/* 100980 7F0CBE50 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 100984 7F0CBE54 AFBF002C */  sw    $ra, 0x2c($sp)
/* 100988 7F0CBE58 AFB50028 */  sw    $s5, 0x28($sp)
/* 10098C 7F0CBE5C AFB40024 */  sw    $s4, 0x24($sp)
/* 100990 7F0CBE60 AFB30020 */  sw    $s3, 0x20($sp)
/* 100994 7F0CBE64 AFB2001C */  sw    $s2, 0x1c($sp)
/* 100998 7F0CBE68 AFB10018 */  sw    $s1, 0x18($sp)
/* 10099C 7F0CBE6C AFB00014 */  sw    $s0, 0x14($sp)
/* 1009A0 7F0CBE70 84820016 */  lh    $v0, 0x16($a0)
/* 1009A4 7F0CBE74 0080A025 */  move  $s4, $a0
/* 1009A8 7F0CBE78 00A0A825 */  move  $s5, $a1
/* 1009AC 7F0CBE7C 8C930018 */  lw    $s3, 0x18($a0)
/* 1009B0 7F0CBE80 18400010 */  blez  $v0, .L7F0CBEC4
/* 1009B4 7F0CBE84 00009025 */   move  $s2, $zero
/* 1009B8 7F0CBE88 00008025 */  move  $s0, $zero
/* 1009BC 7F0CBE8C 02608825 */  move  $s1, $s3
.L7F0CBE90:
/* 1009C0 7F0CBE90 8E2E0000 */  lw    $t6, ($s1)
/* 1009C4 7F0CBE94 02132021 */  addu  $a0, $s0, $s3
/* 1009C8 7F0CBE98 29C10BB9 */  slti  $at, $t6, 0xbb9
/* 1009CC 7F0CBE9C 50200005 */  beql  $at, $zero, .L7F0CBEB4
/* 1009D0 7F0CBEA0 26520001 */   addiu $s2, $s2, 1
/* 1009D4 7F0CBEA4 0FC32F06 */  jal   texLoad
/* 1009D8 7F0CBEA8 02A02825 */   move  $a1, $s5
/* 1009DC 7F0CBEAC 86820016 */  lh    $v0, 0x16($s4)
/* 1009E0 7F0CBEB0 26520001 */  addiu $s2, $s2, 1
.L7F0CBEB4:
/* 1009E4 7F0CBEB4 0242082A */  slt   $at, $s2, $v0
/* 1009E8 7F0CBEB8 2610000C */  addiu $s0, $s0, 0xc
/* 1009EC 7F0CBEBC 1420FFF4 */  bnez  $at, .L7F0CBE90
/* 1009F0 7F0CBEC0 2631000C */   addiu $s1, $s1, 0xc
.L7F0CBEC4:
/* 1009F4 7F0CBEC4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 1009F8 7F0CBEC8 8FB00014 */  lw    $s0, 0x14($sp)
/* 1009FC 7F0CBECC 8FB10018 */  lw    $s1, 0x18($sp)
/* 100A00 7F0CBED0 8FB2001C */  lw    $s2, 0x1c($sp)
/* 100A04 7F0CBED4 8FB30020 */  lw    $s3, 0x20($sp)
/* 100A08 7F0CBED8 8FB40024 */  lw    $s4, 0x24($sp)
/* 100A0C 7F0CBEDC 8FB50028 */  lw    $s5, 0x28($sp)
/* 100A10 7F0CBEE0 03E00008 */  jr    $ra
/* 100A14 7F0CBEE4 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void calls_load_image_to_buffer(uint *image,uint *buffer)
{
    texLoad(&image,buffer);
}
#else
GLOBAL_ASM(
.text
glabel calls_load_image_to_buffer
/* 100A18 7F0CBEE8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 100A1C 7F0CBEEC AFBF0014 */  sw    $ra, 0x14($sp)
/* 100A20 7F0CBEF0 AFA4001C */  sw    $a0, 0x1c($sp)
/* 100A24 7F0CBEF4 0FC32F06 */  jal   texLoad
/* 100A28 7F0CBEF8 27A4001C */   addiu $a0, $sp, 0x1c
/* 100A2C 7F0CBEFC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 100A30 7F0CBF00 27BD0020 */  addiu $sp, $sp, 0x20
/* 100A34 7F0CBF04 03E00008 */  jr    $ra
/* 100A38 7F0CBF08 00000000 */   nop   
)
#endif


