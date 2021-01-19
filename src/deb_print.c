#include "ultra64.h"
#include "deb_print.h"
#include "bondgame.h"
#include "video.h"
#include "PR/R4300.h"

// Padding
u32 D_80023300 = 0;

//The following regDesc's are similar to PR/Tools/Gload/Server.c 
/*
 * Cause Register
 */
static regDesc_t causeDesc[] = {
    {CAUSE_BD, CAUSE_BD, "BD"},
    /* Interrupt pending bits */
    {CAUSE_IP8, CAUSE_IP8, "IP8"},
    {CAUSE_IP7, CAUSE_IP7, "IP7"},
    {CAUSE_IP6, CAUSE_IP6, "IP6"},
    {CAUSE_IP5, CAUSE_IP5, "IP5"},
    {CAUSE_IP4, CAUSE_IP4, "IP4"},
    {CAUSE_IP3, CAUSE_IP3, "IP3"},
    {CAUSE_SW2, CAUSE_SW2, "IP2"},
    {CAUSE_SW1, CAUSE_SW1, "IP1"},
    /* Hardware exception codes */
    {CAUSE_EXCMASK, EXC_INT, "Int"},
    {CAUSE_EXCMASK, EXC_MOD, "TLBmod"},
    {CAUSE_EXCMASK, EXC_RMISS, "TLBload"},
    {CAUSE_EXCMASK, EXC_WMISS, "TLBstore"},
    {CAUSE_EXCMASK, EXC_RADE, "Address error on load or instruction fetch"},
    {CAUSE_EXCMASK, EXC_WADE, "Address error on store"},
    {CAUSE_EXCMASK, EXC_IBE, "Bus error exception on instruction fetch"},
    {CAUSE_EXCMASK, EXC_DBE, "Bus error exception on data reference"},
    {CAUSE_EXCMASK, EXC_SYSCALL, "Syscall"},
    {CAUSE_EXCMASK, EXC_BREAK, "Brk"},
    {CAUSE_EXCMASK, EXC_II, "Reserved instruction"},
    {CAUSE_EXCMASK, EXC_CPU, "Cop unusable"},
    {CAUSE_EXCMASK, EXC_OV, "Overflow"},
    {CAUSE_EXCMASK, EXC_TRAP, "Trap"},
    {CAUSE_EXCMASK,
     EXC_VCEI,
     "Virtual coherency exception on intruction fetch"},
    {CAUSE_EXCMASK, EXC_FPE, "Fp exception"},
    {CAUSE_EXCMASK, EXC_WATCH, "Watchpoint"},
    {CAUSE_EXCMASK, EXC_VCED, "Virtual coherency exception on data reference"},
    {0, 0, ""},
};

/*
 * Status register
 */
static regDesc_t srDesc[] = {
    {SR_CU3, SR_CU3, "CU3"},
    {SR_CU2, SR_CU2, "CU2"},
    {SR_CU1, SR_CU1, "CU1"},
    {SR_CU0, SR_CU0, "CU0"},
    {SR_RP, SR_RP, "RP"},
    {SR_FR, SR_FR, "FR"},
    {SR_RE, SR_RE, "RE"},
    {SR_BEV, SR_BEV, "BEV"},
    {SR_TS, SR_TS, "TS"},
    {SR_SR, SR_SR, "SR"},
    {SR_CH, SR_CH, "CH"},
    {SR_CE, SR_CE, "CE"},
    {SR_DE, SR_DE, "DE"},

    /*
     * Interrupt enable bits
     * (NOTE: bits set to 1 enable the corresponding level interrupt)
     */

    {SR_IBIT8, SR_IBIT8, "IM8"},
    {SR_IBIT7, SR_IBIT7, "IM7"},
    {SR_IBIT6, SR_IBIT6, "IM6"},
    {SR_IBIT5, SR_IBIT5, "IM5"},
    {SR_IBIT4, SR_IBIT4, "IM4"},
    {SR_IBIT3, SR_IBIT3, "IM3"},
    {SR_IBIT2, SR_IBIT2, "IM2"},
    {SR_IBIT1, SR_IBIT1, "IM1"},
    {SR_KX, SR_KX, "KX"},
    {SR_SX, SR_SX, "SX"},
    {SR_UX, SR_UX, "UX"},
    {SR_KSU_MASK, SR_KSU_USR, "USR"},
    {SR_KSU_MASK, SR_KSU_SUP, "SUP"},
    {SR_KSU_MASK, SR_KSU_KER, "KER"},
    {SR_ERL, SR_ERL, "ERL"},
    {SR_EXL, SR_EXL, "EXL"},
    {SR_IE, SR_IE, "IE"},
    {0, 0, ""}
};

/*
 * floating-point status register
 */
static regDesc_t fpcsrDesc[] = {
    {FPCSR_FS, FPCSR_FS, "FS"},
    {FPCSR_C, FPCSR_C, "C"},
    {FPCSR_CE, FPCSR_CE, "Unimplemented"},
    {FPCSR_CV, FPCSR_CV, "Invalid op"},
    {FPCSR_CZ, FPCSR_CZ, "/ by 0.0"},
    {FPCSR_CO, FPCSR_CO, "Overflow"},
    {FPCSR_CU, FPCSR_CU, "Underflow"},
    {FPCSR_CI, FPCSR_CI, "Inexact op"},
    {FPCSR_EV, FPCSR_EV, "EV"},
    {FPCSR_EZ, FPCSR_EZ, "EZ"},
    {FPCSR_EO, FPCSR_EO, "EO"},
    {FPCSR_EU, FPCSR_EU, "EU"},
    {FPCSR_EI, FPCSR_EI, "EI"},
    {FPCSR_FV, FPCSR_FV, "FV"},
    {FPCSR_FZ, FPCSR_FZ, "FZ"},
    {FPCSR_FO, FPCSR_FO, "FO"},
    {FPCSR_FU, FPCSR_FU, "FU"},
    {FPCSR_FI, FPCSR_FI, "FI"},
    {FPCSR_RM_MASK, FPCSR_RM_RN, "RN"},
    {FPCSR_RM_MASK, FPCSR_RM_RZ, "RZ"},
    {FPCSR_RM_MASK, FPCSR_RM_RP, "RP"},
    {FPCSR_RM_MASK, FPCSR_RM_RM, "RM"},
    {0, 0, ""}
};

void *g_StackPtrs1[] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};
void *g_StackPtrs2[] = {&sp_idle, &sp_shed, &sp_main, &sp_audi, &sp_debug};
void *g_StackPtrs3[] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};

// 71 x 32 text buffer (32th line is not drawn)
unsigned char g_DebugOutputTextBuffer[32][71] = {0};

s32 g_DebugOutputCurrentPosX = 0;
s32 g_DebugOutputCurrentPosY = 0;

// 4 x 7 bitmaps of ascii characters (0x20 - 0x7E), each padded to 32 bits
u32 g_DebugOutputBitmaps[] = {
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

u16 *g_DebugOutputVideoBuffer1 = NULL;
u16 *g_DebugOutputVideoBuffer2 = NULL;

// Padding
u32 D_80024184[4] = {0};

void deboutWriteCharAtPos(s32 x, s32 y, unsigned char c) {
    if ((c == '\t') || (c == '\n')) {
        c = '\0';
    }
    if ((c > '\0') && (c < ' ') || (c > '~')) {
        c = '?';
    }
    if (((x >= 0) && (x <= 71)) && ((y >= 0) && (y <= 31))) {
        g_DebugOutputTextBuffer[y][x] = c;
    }
}

#ifdef NONMATCHING
void deboutWriteChar(unsigned char c) {
    if (c) {
        if (c == '\t') {
            do {
                deboutWriteChar(' ');
            } while (g_DebugOutputCurrentPosX & 7);
        } else if (c == '\n') {
            g_DebugOutputCurrentPosX = 0;
            g_DebugOutputCurrentPosY++;
        }        
        if (g_DebugOutputCurrentPosY > 30) {
            deboutScrollUp(g_DebugOutputCurrentPosY - 30);
            g_DebugOutputCurrentPosY = 30;
        }
        if (c != '\n') {
            deboutWriteCharAtPos(g_DebugOutputCurrentPosX, g_DebugOutputCurrentPosY, c);
            g_DebugOutputCurrentPosX++;
            if (g_DebugOutputCurrentPosX > 70) {
                g_DebugOutputCurrentPosX = 0;
                g_DebugOutputCurrentPosY++;
            }
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel deboutWriteChar
/* 0062BC 700056BC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0062C0 700056C0 308600FF */  andi  $a2, $a0, 0xff
/* 0062C4 700056C4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0062C8 700056C8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0062CC 700056CC AFA40028 */  sw    $a0, 0x28($sp)
/* 0062D0 700056D0 10C00039 */  beqz  $a2, .L700057B8
/* 0062D4 700056D4 00C01025 */   move  $v0, $a2
/* 0062D8 700056D8 24010009 */  li    $at, 9
/* 0062DC 700056DC 14C1000A */  bne   $a2, $at, .L70005708
/* 0062E0 700056E0 3C108002 */   lui   $s0, %hi(g_DebugOutputTextBuffer + 0x8E0)
/* 0062E4 700056E4 26103FF8 */  addiu $s0, %lo(g_DebugOutputTextBuffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
.L700056E8:
/* 0062E8 700056E8 0C0015AF */  jal   deboutWriteChar
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
/* 006310 70005710 3C038002 */   lui   $v1, %hi(g_DebugOutputTextBuffer + 0x8E4)
/* 006314 70005714 24633FFC */  addiu $v1, %lo(g_DebugOutputTextBuffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006318 70005718 8C780000 */  lw    $t8, ($v1)
/* 00631C 7000571C 3C108002 */  lui   $s0, %hi(g_DebugOutputTextBuffer + 0x8E0)
/* 006320 70005720 26103FF8 */  addiu $s0, %lo(g_DebugOutputTextBuffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
/* 006324 70005724 27190001 */  addiu $t9, $t8, 1
/* 006328 70005728 AC790000 */  sw    $t9, ($v1)
/* 00632C 7000572C AE000000 */  sw    $zero, ($s0)
.L70005730:
/* 006330 70005730 3C038002 */  lui   $v1, %hi(g_DebugOutputTextBuffer + 0x8E4)
/* 006334 70005734 24633FFC */  addiu $v1, %lo(g_DebugOutputTextBuffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006338 70005738 8C650000 */  lw    $a1, ($v1)
/* 00633C 7000573C 3C108002 */  lui   $s0, %hi(g_DebugOutputTextBuffer + 0x8E0)
/* 006340 70005740 26103FF8 */  addiu $s0, %lo(g_DebugOutputTextBuffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
/* 006344 70005744 28A1001F */  slti  $at, $a1, 0x1f
/* 006348 70005748 1420000A */  bnez  $at, .L70005774
/* 00634C 7000574C 24A4FFE2 */   addiu $a0, $a1, -0x1e
/* 006350 70005750 AFA20024 */  sw    $v0, 0x24($sp)
/* 006354 70005754 0C0015F3 */  jal   deboutScrollUp
/* 006358 70005758 A3A6002B */   sb    $a2, 0x2b($sp)
/* 00635C 7000575C 3C038002 */  lui   $v1, %hi(g_DebugOutputTextBuffer + 0x8E4)
/* 006360 70005760 24633FFC */  addiu $v1, %lo(g_DebugOutputTextBuffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006364 70005764 2408001E */  li    $t0, 30
/* 006368 70005768 8FA20024 */  lw    $v0, 0x24($sp)
/* 00636C 7000576C 93A6002B */  lbu   $a2, 0x2b($sp)
/* 006370 70005770 AC680000 */  sw    $t0, ($v1)
.L70005774:
/* 006374 70005774 2401000A */  li    $at, 10
/* 006378 70005778 50410010 */  beql  $v0, $at, .L700057BC
/* 00637C 7000577C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 006380 70005780 8E040000 */  lw    $a0, ($s0)
/* 006384 70005784 0C00158C */  jal   deboutWriteCharAtPos
/* 006388 70005788 8C650000 */   lw    $a1, ($v1)
/* 00638C 7000578C 8E090000 */  lw    $t1, ($s0)
/* 006390 70005790 3C038002 */  lui   $v1, %hi(g_DebugOutputTextBuffer + 0x8E4)
/* 006394 70005794 24633FFC */  addiu $v1, %lo(g_DebugOutputTextBuffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
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

void deboutScrollUp(s32 numlines) {
    s32 y;
    s32 x;
    while (numlines-- > 0) {
        for (y = 0; y < 31; y++) {
            for (x = 0; x < 71; x++) {
                g_DebugOutputTextBuffer[y][x] = g_DebugOutputTextBuffer[y + 1][x];
            }
        }
    }
}

void deboutDrawChar(s32 x, s32 y, unsigned char c) {
    s32 bitmap_x;
    s32 bitmap_y;
    u32 bitmap;
    s16 screen_w = viGetX();
    u16 *ptr;
    if (c == '\0') {
        c = ' ';
    }
    if ((c >= ' ') && (c <= '~')) {
        ptr = (g_DebugOutputVideoBuffer1 + x + (y * screen_w));
        bitmap = g_DebugOutputBitmaps[c - ' '];
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

void deboutSetBuffers(u16 *buffer1, u16 *buffer2) {
    g_DebugOutputVideoBuffer1 = K0_TO_K1(buffer1);
    g_DebugOutputVideoBuffer2 = K0_TO_K1(buffer2);
}

void deboutInitBuffers(void) {
    deboutSetBuffers(&cfb_16[0], &cfb_16[1]);
}

void deboutDrawToBuffer(u16 *buffer) {
    s32 screen_w;
    s32 screen_h;
    s32 output_w;
    s32 output_h;
    s32 x;
    s32 y;
    deboutInitBuffers();
    g_DebugOutputVideoBuffer1 = K0_TO_K1(buffer);
    screen_w = ((viGetX() - 13) / 4);
    screen_h = ((viGetY() - 10) / 7);
    output_w = screen_w - 5; // - margin_w
    output_h = screen_h - 1; // - margin_h
    for (y = 0; ((y < output_h) && (y < 31)); y++) {
        for (x = 0; ((x < output_w) && (x < 71)); x++) {
            deboutDrawChar(((x + 5) * 4), ((y + 1) * 7), g_DebugOutputTextBuffer[y][x]);
        }
    }
}
