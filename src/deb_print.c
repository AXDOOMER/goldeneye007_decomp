#include "ultra64.h"
#include "deb_print.h"
#include "bondgame.h"
#include "video.h"

// Padding
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

// 71 x 32 character buffer (32th line is not drawn)
unsigned char stderr_buffer[32][71] = {0};

s32 D_80023FF8 = 0; // x
s32 D_80023FFC = 0; // y

// 4 x 7 bitmaps of ascii characters (0x20 - 0x7E), each padded to 32 bits
u32 std_error_font_bitcode[] = {
    0x00000000, 0x22220200, 0x55000000, 0x05F5F500, 0x27427200,     // ' ',  '!',  '\"', '#',  '$'
    0x05124500, 0x34255300, 0x22000000, 0x24444420, 0x42222240,     // '%',  '&',  '\'', '(',  ')'
    0x06F6F600, 0x00272000, 0x00000240, 0x00070000, 0x00000200,     // '*',  '+',  '´',  '-',  '.'
    0x11224480, 0x25555200, 0x26222700, 0x25125700, 0x61211600,     // '/',  '0',  '1',  '2',  '3'
    0x33557300, 0x64611600, 0x24655200, 0x71112200, 0x25755200,     // '4',  '5',  '6',  '7',  '8'
    0x25531600, 0x00200200, 0x00200640, 0x01242100, 0x00707000,     // '9',  ':',  ';',  '<',  '='
    0x04212400, 0x07120200, 0x25FF5700, 0x02557D00, 0x06575E00,     // '>',  '?',  '@',  'A',  'B'
    0x07445300, 0x07555600, 0x07565700, 0x07564400, 0x07C95700,     // 'C',  'D',  'E',  'F',  'G'
    0x05575500, 0x07222700, 0x03111600, 0x05665500, 0x04445F00,     // 'H',  'I',  'J',  'K',  'L'
    0x0DFF9D00, 0x0F777D00, 0x07DD5700, 0x07564600, 0x07995770,     // 'M',  'N',  'O',  'P',  'Q'
    0x07565500, 0x07461E00, 0x07222200, 0x0D999600, 0x0D552200,     // 'R',  'S',  'T',  'U',  'V'
    0x0DF77500, 0x0D625500, 0x05622600, 0x07125700, 0x32222230,     // 'W',  'X',  'Y',  'Z',  '['
    0x44222110, 0x62222260, 0x25000000, 0x00000700, 0x42200000,     // '\\', ']',  '^',  '_',  '`'
    0x0067D700, 0x44755700, 0x00788600, 0x117DD700, 0x006FC700,     // 'a',  'b',  'c',  'd',  'e'
    0x32722700, 0x007DD730, 0x44755500, 0x02622700, 0x02711130,     // 'f',  'g',  'h',  'i',  'j',
    0x44766500, 0x62222700, 0x00FFFF00, 0x00755D00, 0x006DD600,     // 'k',  'l',  'm',  'n',  'o'
    0x00755740, 0x00799710, 0x00744600, 0x00775700, 0x02722300,     // 'p',  'q',  'r',  's',  't'
    0x00555700, 0x00552200, 0x00577500, 0x00562500, 0x00552220,     // 'u',  'v',  'w',  'x',  'y'
    0x00703700, 0x12242210, 0x02222220, 0x42212240, 0x005A0000      // 'z',  '{',  '|',  '}',  '~'
};

u16 *ptr_videobuffer1 = NULL;
u16 *ptr_videobuffer2 = NULL;

// Padding
u32 D_80024184[4] = {0};

void write_char_to_pos_stderr(s32 x, s32 y, unsigned char c) {
    if ((c == '\t') || (c == '\n')) {
        c = '\0';
    }
    if ((c > '\0') && (c < ' ') || (c > '~')) {
        c = '?';
    }
    if (((x >= 0) && (x <= 71)) && ((y >= 0) && (y <= 31))) {
        stderr_buffer[y][x] = c;
    }
}

#ifdef NONMATCHING
void __osRdbSend(unsigned char c) {
    if (c) {
        if (c == '\t') {
            do {
                __osRdbSend(' ');
            } while (D_80023FF8 & 7);
        } else if (c == '\n') {
            D_80023FF8 = 0;
            D_80023FFC++;
        }        
        if (D_80023FFC > 30) {
            scroll_stderr_oneline(D_80023FFC - 30);
            D_80023FFC = 30;
        }
        if (c != '\n') {
            write_char_to_pos_stderr(D_80023FF8, D_80023FFC, c);
            D_80023FF8++;
            if (D_80023FF8 > 70) {
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

void print_to_vidbuff1(s32 x, s32 y, unsigned char c) {
    s32 bitmap_x;
    s32 bitmap_y;
    u32 bitmap;
    s16 screen_w = viGetX();
    u16 *ptr;
    if (c == '\0') {
        c = ' ';
    }
    if ((c >= ' ') && (c <= '~')) {
        ptr = (ptr_videobuffer1 + x + (y * screen_w));
        bitmap = std_error_font_bitcode[c - ' '];
        for (bitmap_y = 0; bitmap_y < 7; bitmap_y++) {
            for (bitmap_x = 0; bitmap_x < 4; bitmap_x++) {
                if (bitmap & (1 << 31)) {
                    *ptr = GPACK_RGBA5551(255, 255, 255, 1);
                } else {
                    *ptr = GPACK_RGBA5551(0, 0, 0, 1);
                }
                ptr++;
                bitmap <<= 1;
            }
            ptr += screen_w;
            ptr -= 4;
        }
    }
}

void set_ptr_video_buffers(u16 *buffer1, u16 *buffer2) {
    ptr_videobuffer1 = (u16*)((u32)buffer1 | 0xA0000000);
    ptr_videobuffer2 = (u16*)((u32)buffer2 | 0xA0000000);
}

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
    ptr_videobuffer1 = (u16*)((u32)buffer | 0xA0000000);
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
