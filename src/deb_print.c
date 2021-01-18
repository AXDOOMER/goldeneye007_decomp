#include "ultra64.h"
#include "deb_print.h"
#include "bondgame.h"
#include "video.h"

/**
 * @file deb_print.c
 * This file contains the stderr manager. 
 */

//im just padding
u32 D_80023300 = 0;


struct debug_processor_error_entry debug_processor_error_table[] = { 
{0x80000000, 0x80000000, "BD"},
{0x8000, 0x8000, "IP8"},
{0x4000, 0x4000, "IP7"},
{0x2000, 0x2000, "IP6"},
{0x1000, 0x1000, "IP5"},
{0x800, 0x800, "IP4"},
{0x400, 0x400, "IP3"},
{0x200, 0x200, "IP2"},
{0x100, 0x100, "IP1"},
{0x7C, 0, "Int"},
{0x7C, 4, "TLBmod"},
{0x7C, 8, "TLBload"},
{0x7C, 0xC, "TLBstore"},
{0x7C, 0x10, "Address error on load or instruction fetch"},
{0x7C, 0x14, "Address error on store"},
{0x7C, 0x18, "Bus error exception on instruction fetch"},
{0x7C, 0x1C, "Bus error exception on data reference"},
{0x7C, 0x20, "Syscall"},
{0x7C, 0x24, "Brk"},
{0x7C, 0x28, "Reserved instruction"},
{0x7C, 0x2C, "Cop unusable"},
{0x7C, 0x30, "Overflow"},
{0x7C, 0x34, "Trap"},
{0x7C, 0x38, "Virtual coherency exception on intruction fetch"},
{0x7C, 0x3C, "Fp exception"},
{0x7C, 0x5C, "Watchpoint"},
{0x7C, 0x7C, "Virtual coherency exception on data reference"},
{0, 0, ""},
{0x80000000, 0x80000000, "CU3"},
{0x40000000, 0x40000000, "CU2"},
{0x20000000, 0x20000000, "CU1"},
{0x10000000, 0x10000000, "CU0"},
{0x8000000, 0x8000000, "RP"},
{0x4000000, 0x4000000, "FR"},
{0x2000000, 0x2000000, "RE"},
{0x400000, 0x400000, "BEV"},
{0x200000, 0x200000, "TS"},
{0x100000, 0x100000, "SR"},
{0x40000, 0x40000, "CH"},
{0x20000, 0x20000, "CE"},
{0x10000, 0x10000, "DE"},
{0x8000, 0x8000, "IM8"},
{0x4000, 0x4000, "IM7"},
{0x2000, 0x2000, "IM6"},
{0x1000, 0x1000, "IM5"},
{0x800, 0x800, "IM4"},
{0x400, 0x400, "IM3"},
{0x200, 0x200, "IM2"},
{0x100, 0x100, "IM1"},
{0x80, 0x80, "KX"},
{0x40, 0x40, "SX"},
{0x20, 0x20, "UX"},
{0x18, 0x10, "USR"},
{0x18, 8, "SUP"},
{0x18, 0, "KER"},
{4, 4, "ERL"},
{2, 2, "EXL"},
{1, 1, "IE"},
{0, 0, ""},
{0x1000000, 0x1000000, "FS"},
{0x800000, 0x800000, "C"},
{0x20000, 0x20000, "Unimplemented"},
{0x10000, 0x10000, "Invalid op"},
{0x8000, 0x8000, "/ by 0.0"},
{0x4000, 0x4000, "Overflow"},
{0x2000, 0x2000, "Underflow"},
{0x1000, 0x1000, "Inexact op"},
{0x800, 0x800, "EV"},
{0x400, 0x400, "EZ"},
{0x200, 0x200, "EO"},
{0x100, 0x100, "EU"},
{0x80, 0x80, "EI"},
{0x40, 0x40, "FV"},
{0x20, 0x20, "FZ"},
{0x10, 0x10, "FO"},
{8, 8, "FU"},
{4, 4, "FI"},
{3, 0, "RN"},
{3, 1, "RZ"},
{3, 2, "RP"},
{3, 3, "RM"},
{0, 0, ""} };

void *stack_ptrs_1[] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};
void *stack_ptrs_2[] = {&sp_idle, &sp_shed, &sp_main, &sp_audi, &sp_debug};
void *stack_ptrs_3[] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};

unsigned char stderr_buffer[32][71] = {0};
s32 D_80023FF8 = 0; // x
s32 D_80023FFC = 0; // y


//split more here likely
u32 std_error_font_bitcode[] = {
0x00000000, 0x22220200, 0x55000000,  0x5F5F500, 0x27427200,
0x05124500, 0x34255300, 0x22000000, 0x24444420, 0x42222240,
0x06F6F600,   0x272000,      0x240,    0x70000,      0x200,
0x11224480, 0x25555200, 0x26222700, 0x25125700, 0x61211600,
0x33557300, 0x64611600, 0x24655200, 0x71112200, 0x25755200,
0x25531600,   0x200200,   0x200640,  0x1242100,   0x707000,
 0x4212400,  0x7120200, 0x25FF5700,  0x2557D00,  0x6575E00,
 0x7445300,  0x7555600,  0x7565700,  0x7564400,  0x7C95700,
 0x5575500,  0x7222700,  0x3111600,  0x5665500,  0x4445F00,
 0xDFF9D00,  0xF777D00,  0x7DD5700,  0x7564600,  0x7995770,
 0x7565500,  0x7461E00,  0x7222200,  0xD999600,  0xD552200,
 0xDF77500,  0xD625500,  0x5622600,  0x7125700, 0x32222230,
0x44222110, 0x62222260, 0x25000000,      0x700, 0x42200000,
  0x67D700, 0x44755700,   0x788600, 0x117DD700,   0x6FC700,
0x32722700,   0x7DD730, 0x44755500,  0x2622700,  0x2711130,
0x44766500, 0x62222700,   0xFFFF00,   0x755D00,   0x6DD600,
  0x755740,   0x799710,   0x744600,   0x775700,  0x2722300,
  0x555700,   0x552200,   0x577500,   0x562500,   0x552220,
  0x703700, 0x12242210,  0x2222220, 0x42212240,   0x5A0000 };

u16 *ptr_videobuffer1 = NULL;
u16 *ptr_videobuffer2 = NULL;

u32 padding_80024184[4] = {0};

void write_char_to_pos_stderr(s32 x, s32 y, unsigned char c) {
    if ((c == '\t') || (c == '\n')) {
        c = '\0';
    }
    if (((c > '\0') && (c < ' ')) || (c >= 0x7F)) {
        c = '?';
    }
    if (((x >= 0) && (x <= 71)) && ((y >= 0) && (y <= 31))) {
        stderr_buffer[y][x] = c;
    }
}

/**
 * 62BC	700056BC
 *     write char A0 to stderr
 *     accepts: A0=char
 */
#ifdef NONMATCHING
void __osRdbSend(unsigned char c) {
    if (c) {
        if (c == '\t') {
            do {
                __osRdbSend(' ');
            } while (D_80023FF8 & 7);
        } else if (c == '\n') {
            D_80023FFC++;
            D_80023FF8 = 0;
        }
        if (D_80023FFC >= 31) {
            scroll_stderr_oneline(D_80023FFC - 30);
            D_80023FFC = 30;
        }
        if (c != '\n') {
            write_char_to_pos_stderr(D_80023FF8, D_80023FFC, c);
            D_80023FF8++;
            if (D_80023FF8 >= 71) {
                D_80023FF8 = 0;
                D_80023FFC++;
            }
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel __osRdbSend
/* 0062BC 700056BC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0062C0 700056C0 308600FF */  andi  $a2, $a0, 0xff
/* 0062C4 700056C4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0062C8 700056C8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0062CC 700056CC AFA40028 */  sw    $a0, 0x28($sp)
/* 0062D0 700056D0 10C00039 */  beqz  $a2, .L700057B8
/* 0062D4 700056D4 00C01025 */   move  $v0, $a2
/* 0062D8 700056D8 24010009 */  li    $at, 9
/* 0062DC 700056DC 14C1000A */  bne   $a2, $at, .L70005708
/* 0062E0 700056E0 3C108002 */   lui   $s0, %hi(stderr_buffer + 0x8E0)
/* 0062E4 700056E4 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
.L700056E8:
/* 0062E8 700056E8 0C0015AF */  jal   __osRdbSend
/* 0062EC 700056EC 24040020 */   li    $a0, 32
/* 0062F0 700056F0 8E0E0000 */  lw    $t6, ($s0)
/* 0062F4 700056F4 31CF0007 */  andi  $t7, $t6, 7
/* 0062F8 700056F8 15E0FFFB */  bnez  $t7, .L700056E8
/* 0062FC 700056FC 00000000 */   nop   
/* 006300 70005700 1000002E */  b     .L700057BC
/* 006304 70005704 8FBF001C */   lw    $ra, 0x1c($sp)
.L70005708:
/* 006308 70005708 2401000A */  li    $at, 10
/* 00630C 7000570C 14410008 */  bne   $v0, $at, .L70005730
/* 006310 70005710 3C038002 */   lui   $v1, %hi(stderr_buffer + 0x8E4)
/* 006314 70005714 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006318 70005718 8C780000 */  lw    $t8, ($v1)
/* 00631C 7000571C 3C108002 */  lui   $s0, %hi(stderr_buffer + 0x8E0)
/* 006320 70005720 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
/* 006324 70005724 27190001 */  addiu $t9, $t8, 1
/* 006328 70005728 AC790000 */  sw    $t9, ($v1)
/* 00632C 7000572C AE000000 */  sw    $zero, ($s0)
.L70005730:
/* 006330 70005730 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4)
/* 006334 70005734 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006338 70005738 8C650000 */  lw    $a1, ($v1)
/* 00633C 7000573C 3C108002 */  lui   $s0, %hi(stderr_buffer + 0x8E0)
/* 006340 70005740 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
/* 006344 70005744 28A1001F */  slti  $at, $a1, 0x1f
/* 006348 70005748 1420000A */  bnez  $at, .L70005774
/* 00634C 7000574C 24A4FFE2 */   addiu $a0, $a1, -0x1e
/* 006350 70005750 AFA20024 */  sw    $v0, 0x24($sp)
/* 006354 70005754 0C0015F3 */  jal   scroll_stderr_oneline
/* 006358 70005758 A3A6002B */   sb    $a2, 0x2b($sp)
/* 00635C 7000575C 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4)
/* 006360 70005760 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006364 70005764 2408001E */  li    $t0, 30
/* 006368 70005768 8FA20024 */  lw    $v0, 0x24($sp)
/* 00636C 7000576C 93A6002B */  lbu   $a2, 0x2b($sp)
/* 006370 70005770 AC680000 */  sw    $t0, ($v1)
.L70005774:
/* 006374 70005774 2401000A */  li    $at, 10
/* 006378 70005778 50410010 */  beql  $v0, $at, .L700057BC
/* 00637C 7000577C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 006380 70005780 8E040000 */  lw    $a0, ($s0)
/* 006384 70005784 0C00158C */  jal   write_char_to_pos_stderr
/* 006388 70005788 8C650000 */   lw    $a1, ($v1)
/* 00638C 7000578C 8E090000 */  lw    $t1, ($s0)
/* 006390 70005790 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4)
/* 006394 70005794 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006398 70005798 252A0001 */  addiu $t2, $t1, 1
/* 00639C 7000579C 29410047 */  slti  $at, $t2, 0x47
/* 0063A0 700057A0 14200005 */  bnez  $at, .L700057B8
/* 0063A4 700057A4 AE0A0000 */   sw    $t2, ($s0)
/* 0063A8 700057A8 8C6C0000 */  lw    $t4, ($v1)
/* 0063AC 700057AC AE000000 */  sw    $zero, ($s0)
/* 0063B0 700057B0 258D0001 */  addiu $t5, $t4, 1
/* 0063B4 700057B4 AC6D0000 */  sw    $t5, ($v1)
.L700057B8:
/* 0063B8 700057B8 8FBF001C */  lw    $ra, 0x1c($sp)
.L700057BC:
/* 0063BC 700057BC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0063C0 700057C0 27BD0028 */  addiu $sp, $sp, 0x28
/* 0063C4 700057C4 03E00008 */  jr    $ra
/* 0063C8 700057C8 00000000 */   nop   
)
#endif

void scroll_stderr_oneline(s32 count) {
    s32 y;
    s32 x;
    while (count-- > 0) {
        for (y = 0; y < 31; y++) {
            for (x = 0; x < 71; x++) {
                stderr_buffer[y][x] = stderr_buffer[y + 1][x];
            }
        }
    }
}

/**
 * 645C	7000585C
 *     print char A2 to stderr screen position (A0,A1) in video buffer 1
 *     accepts: A0=xpos, A1=ypos, A2=char
 */
#ifdef NONMATCHING
void print_to_vidbuff1(s32 x, s32 y, unsigned char c) {
    s32 i;
    s32 j;
    s16 totalwidth = viGetX();
    u16 *ptr;
    u32 bitcode;
    if (c == '\0') {
        c = ' ';
    }
    if ((c >= ' ') && (c < 0x7F)) {
        ptr = &ptr_videobuffer1[(y * totalwidth) + x];
        bitcode = std_error_font_bitcode[c - ' '];
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 4; j++) {
                *ptr++ = (bitcode & 0x80000000) ? GPACK_RGBA5551(255, 255, 255, 1) :  GPACK_RGBA5551(0, 0, 0, 1);
                bitcode <<= 1;
            }
            ptr += totalwidth;
            ptr -= 4;
        }
    }
}
#else
void print_to_vidbuff1(s32 x, s32 y, unsigned char c);
GLOBAL_ASM(
.text
glabel print_to_vidbuff1
/* 00645C 7000585C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006460 70005860 AFBF0014 */  sw    $ra, 0x14($sp)
/* 006464 70005864 AFA40018 */  sw    $a0, 0x18($sp)
/* 006468 70005868 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00646C 7000586C 0C001107 */  jal   viGetX
/* 006470 70005870 AFA60020 */   sw    $a2, 0x20($sp)
/* 006474 70005874 93A50023 */  lbu   $a1, 0x23($sp)
/* 006478 70005878 54A00003 */  bnezl $a1, .L70005888
/* 00647C 7000587C 28A10020 */   slti  $at, $a1, 0x20
/* 006480 70005880 24050020 */  li    $a1, 32
/* 006484 70005884 28A10020 */  slti  $at, $a1, 0x20
.L70005888:
/* 006488 70005888 1420003A */  bnez  $at, .L70005974
/* 00648C 7000588C 28A1007F */   slti  $at, $a1, 0x7f
/* 006490 70005890 10200038 */  beqz  $at, .L70005974
/* 006494 70005894 8FAE0018 */   lw    $t6, 0x18($sp)
/* 006498 70005898 8FAB001C */  lw    $t3, 0x1c($sp)
/* 00649C 7000589C 3C188002 */  lui   $t8, %hi(ptr_videobuffer1) 
/* 0064A0 700058A0 8F18417C */  lw    $t8, %lo(ptr_videobuffer1)($t8)
/* 0064A4 700058A4 01620019 */  multu $t3, $v0
/* 0064A8 700058A8 000E7840 */  sll   $t7, $t6, 1
/* 0064AC 700058AC 00057080 */  sll   $t6, $a1, 2
/* 0064B0 700058B0 3C048002 */  lui   $a0, %hi(stderr_buffer+0x868)
/* 0064B4 700058B4 008E2021 */  addu  $a0, $a0, $t6
/* 0064B8 700058B8 01F8C821 */  addu  $t9, $t7, $t8
/* 0064BC 700058BC 8C843F80 */  lw    $a0, %lo(stderr_buffer+0x868)($a0)
/* 0064C0 700058C0 3C058000 */  lui   $a1, 0x8000
/* 0064C4 700058C4 00004025 */  move  $t0, $zero
/* 0064C8 700058C8 00024840 */  sll   $t1, $v0, 1
/* 0064CC 700058CC 00006012 */  mflo  $t4
/* 0064D0 700058D0 000C6840 */  sll   $t5, $t4, 1
/* 0064D4 700058D4 032D1821 */  addu  $v1, $t9, $t5
/* 0064D8 700058D8 240A0007 */  li    $t2, 7
/* 0064DC 700058DC 24070001 */  li    $a3, 1
/* 0064E0 700058E0 3406FFFF */  li    $a2, 65535
.L700058E4:
/* 0064E4 700058E4 00857824 */  and   $t7, $a0, $a1
/* 0064E8 700058E8 11E00003 */  beqz  $t7, .L700058F8
/* 0064EC 700058EC 0004C040 */   sll   $t8, $a0, 1
/* 0064F0 700058F0 10000002 */  b     .L700058FC
/* 0064F4 700058F4 A4660000 */   sh    $a2, ($v1)
.L700058F8:
/* 0064F8 700058F8 A4670000 */  sh    $a3, ($v1)
.L700058FC:
/* 0064FC 700058FC 03055824 */  and   $t3, $t8, $a1
/* 006500 70005900 24630002 */  addiu $v1, $v1, 2
/* 006504 70005904 11600003 */  beqz  $t3, .L70005914
/* 006508 70005908 03002025 */   move  $a0, $t8
/* 00650C 7000590C 10000002 */  b     .L70005918
/* 006510 70005910 A4660000 */   sh    $a2, ($v1)
.L70005914:
/* 006514 70005914 A4670000 */  sh    $a3, ($v1)
.L70005918:
/* 006518 70005918 00046040 */  sll   $t4, $a0, 1
/* 00651C 7000591C 0185C824 */  and   $t9, $t4, $a1
/* 006520 70005920 01802025 */  move  $a0, $t4
/* 006524 70005924 13200003 */  beqz  $t9, .L70005934
/* 006528 70005928 24630002 */   addiu $v1, $v1, 2
/* 00652C 7000592C 10000002 */  b     .L70005938
/* 006530 70005930 A4660000 */   sh    $a2, ($v1)
.L70005934:
/* 006534 70005934 A4670000 */  sh    $a3, ($v1)
.L70005938:
/* 006538 70005938 00046840 */  sll   $t5, $a0, 1
/* 00653C 7000593C 01A57024 */  and   $t6, $t5, $a1
/* 006540 70005940 01A02025 */  move  $a0, $t5
/* 006544 70005944 11C00003 */  beqz  $t6, .L70005954
/* 006548 70005948 24630002 */   addiu $v1, $v1, 2
/* 00654C 7000594C 10000002 */  b     .L70005958
/* 006550 70005950 A4660000 */   sh    $a2, ($v1)
.L70005954:
/* 006554 70005954 A4670000 */  sh    $a3, ($v1)
.L70005958:
/* 006558 70005958 24630002 */  addiu $v1, $v1, 2
/* 00655C 7000595C 25080001 */  addiu $t0, $t0, 1
/* 006560 70005960 00047840 */  sll   $t7, $a0, 1
/* 006564 70005964 00691821 */  addu  $v1, $v1, $t1
/* 006568 70005968 01E02025 */  move  $a0, $t7
/* 00656C 7000596C 150AFFDD */  bne   $t0, $t2, .L700058E4
/* 006570 70005970 2463FFF8 */   addiu $v1, $v1, -8
.L70005974:
/* 006574 70005974 8FBF0014 */  lw    $ra, 0x14($sp)
/* 006578 70005978 27BD0018 */  addiu $sp, $sp, 0x18
/* 00657C 7000597C 03E00008 */  jr    $ra
/* 006580 70005980 00000000 */   nop   
)
#endif




/**
 * 6584	70005984
 *     set pointers to video buffers 1 & 2 to A0 and A1, respectively
 *     sets values to uncached addresses
 *     A0 | A0000000 -> 8002417C
 *     A1 | A0000000 -> 80024180
 */

void set_ptr_video_buffers(s32 arg0, s32 arg1) {
    ptr_videobuffer1 = (arg0 | 0xA0000000);
    ptr_videobuffer2 = (arg1 | 0xA0000000);
}




/**
 * 65A4	700059A4
 *     set pointers to video buffers 1 & 2
 *     calls 70005984: A0=803B5000, A1=803DA800
 */
void set_video_buffer_pointers(void) {
    set_ptr_video_buffers(&cfb_16[0], &cfb_16[1]);
}

void write_stderr_to_buffer(u16 *buffer) {
    s32 screen_w;
    s32 screen_h;
    s32 output_w;
    s32 output_h;
    s32 x;
    s32 y;
    set_video_buffer_pointers();
    ptr_videobuffer1 = ((u32)buffer | 0xA0000000);
    screen_w = ((viGetX() - 13) / 4);
    screen_h = ((viGetY() - 10) / 7);
    output_w = screen_w - 5; // - margin_w
    output_h = screen_h - 1; // - margin_h
    for (y = 0; ((y < output_h) && (y < 31)); y++) {
        for (x = 0; ((x < output_w) && (x < 71)); x++) {
            print_to_vidbuff1(((x + 5) * 4), ((y + 1) * 7), stderr_buffer[y][x]);
        }
    }
}
