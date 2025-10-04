#include <ultra64.h>
#include <memp.h>
#include "textrelated.h"
#include "bondtypes.h"
#include "game/lvl_text.h"

#define SPACE_WIDTH 5

#define M_COLOR_R(x) (u8)(x >> 0x18)
#define M_COLOR_G(x) (u8)(x >> 0x10)
#define M_COLOR_B(x) (u8)(x >> 0x08)
#define M_COLOR_A(x) (u8)(x >> 0x00)


// data
s32 D_80040E80 = 0;
s32 text_spacing = 0;
s32 text_orientation = 0;
s32 text_wordwrap = 0;
s32 overlap_correction = -1;
s32 text_bilevel_filter = FALSE;
s32 text_x = 0;
s32 text_y = 0;
s32 text_s = 0;
s32 text_t = 0;
s32 D_80040EA8 = 0;
s32 ptrFontBankGothic = 0;
s32 ptrFontBankGothicChars = 0;
s32 ptrFontZurichBold = 0;
s32 ptrFontZurichBoldChars = 0;

u16 D_80040EBC[] = {
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff,
    0x0000, 0x5555, 0xaaaa, 0xffff
};
u32 D_80040EDC = 0;
u32 D_80040EE0 = 0;

u32 D_80040EE4[] = {
    0x55555555, 0x55555555,
    0xAAAAAAAA, 0xAAAAAAAA,
    0xFFFFFFFF, 0xFFFFFFFF
};

struct fontchar D_80040EFC = {0, 0, 12, 11};

struct fontchar D_80040F14 = {0, 0, 12, 11};


// forward declarations

Gfx *construct_fontchar_microcode(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10);
Gfx *sub_GAME_7F0AE45C(Gfx *gdl, s32 x, s32 y, struct fontchar *curchar, s32 savedx, s32 savedy, s32 width, s32 height);
Gfx *sub_GAME_7F0ADDAC(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, 
                       struct fontchar *prevchar, struct font *font, s32 savedx, s32 savedy, 
                       u32 color, u32 color2, s32 width, s32 height, 
                       s32 arg12);

// -------------------------------------------------------------------------------------------------

void textrelatedInit_REMOVED(void /*, char* asset */)
{
    #ifdef DEBUG
    if (asset == 0)
    {
        osSyncPrintf("\n--- ASSERTION FAULT - %s - %s, line %d\n\n", "textInitText: NULL void* asset", ".\\text.cpp", 0x38 );
    }
    #endif
}

void setTextSpacingInverted(s32 spacing) {
    text_spacing = -spacing;
}

void setTextOrientation(s32 orientation) {
    text_orientation = orientation;
}

void setTextWordWrap(s32 flag) {
    text_wordwrap = flag;
}

void setTextOverlapCorrection(s32 flag) {
    overlap_correction = flag;
}






#ifdef NONMATCHING
void load_font_tables(void)
{
    s32 sp1C;
    s32 MACROSIZE;
    s32 MACROSIZE;
    s32 temp_ret;
    s32 temp_ret_2;
    s32 i_next;
    s32 temp_v1_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    s32 i;
    s32 phi_v1_2;

    text_spacing = 0;
    text_orientation = 0;
    text_wordwrap = 0;
    overlap_correction = -1;
    text_bilevel_filter = 0;
    text_x = 0;
    text_y = 0;
    text_s = 0;
    MACROSIZE = 0x24b0 - 0;
    text_t = 0;
    ptrFontBankGothic      = mempAllocBytesInBank(MACROSIZE, MEMPOOL_STAGE);
    ptrFontBankGothicChars = (s32) (ptrFontBankGothic + 0x2a4);
    romCopy(&ptrFontBankGothic, &_fontbankgothicSegmentRomStart, MACROSIZE);
    i = 0;
loop_1:
    temp_v0 = ptrFontBankGothicChars + i;
    i_next = i + 0x18;
    temp_v0->unk14 = (s32) (temp_v0->unk14 + ptrFontBankGothic);
    i = i_next;
    if (i_next < 0x8d0)
    {
        goto loop_1;
    }
    MACROSIZE = 0x3540 - 0;
    ptrFontZurichBold      = mempAllocBytesInBank(MACROSIZE, MEMPOOL_STAGE);
    ptrFontZurichBoldChars = (s32) (ptrFontZurichBold + 0x2a4);
    romCopy(&ptrFontZurichBold, &_fontzurichboldSegmentRomStart, MACROSIZE);
    ptrFontZurichBoldChars->unk14 = (s32) (ptrFontZurichBoldChars->unk14 + ptrFontZurichBold);
    ptrFontZurichBoldChars->unk2C = (s32) (ptrFontZurichBoldChars->unk2C + ptrFontZurichBold);
    phi_v1_2 = 0x30;
loop_3:
    temp_v0_2 = ptrFontZurichBoldChars + phi_v1_2;
    temp_v0_2->unk14 = (s32) (temp_v0_2->unk14 + ptrFontZurichBold);
    temp_v0_3 = ptrFontZurichBoldChars + phi_v1_2;
    temp_v0_3->unk2C = (s32) (temp_v0_3->unk2C + ptrFontZurichBold);
    temp_v0_4 = ptrFontZurichBoldChars + phi_v1_2;
    temp_v0_4->unk44 = (s32) (temp_v0_4->unk44 + ptrFontZurichBold);
    temp_v0_5 = ptrFontZurichBoldChars + phi_v1_2;
    temp_v1_2 = phi_v1_2 + 0x60;
    temp_v0_5->unk5C = (s32) (temp_v0_5->unk5C + ptrFontZurichBold);
    phi_v1_2 = temp_v1_2;
    if (temp_v1_2 != 0x8d0)
    {
        goto loop_3;
    }
}
#else
GLOBAL_ASM(
.text
glabel load_font_tables
/* 0E16DC 7F0ACBAC 3C018004 */  lui   $at, %hi(text_spacing)
/* 0E16E0 7F0ACBB0 AC200E84 */  sw    $zero, %lo(text_spacing)($at)
/* 0E16E4 7F0ACBB4 3C018004 */  lui   $at, %hi(text_orientation)
/* 0E16E8 7F0ACBB8 AC200E88 */  sw    $zero, %lo(text_orientation)($at)
/* 0E16EC 7F0ACBBC 3C018004 */  lui   $at, %hi(text_wordwrap)
/* 0E16F0 7F0ACBC0 AC200E8C */  sw    $zero, %lo(text_wordwrap)($at)
/* 0E16F4 7F0ACBC4 3C018004 */  lui   $at, %hi(overlap_correction)
/* 0E16F8 7F0ACBC8 240EFFFF */  li    $t6, -1
/* 0E16FC 7F0ACBCC AC2E0E90 */  sw    $t6, %lo(overlap_correction)($at)
/* 0E1700 7F0ACBD0 3C018004 */  lui   $at, %hi(text_bilevel_filter)
/* 0E1704 7F0ACBD4 AC200E94 */  sw    $zero, %lo(text_bilevel_filter)($at)
/* 0E1708 7F0ACBD8 3C018004 */  lui   $at, %hi(text_x)
/* 0E170C 7F0ACBDC AC200E98 */  sw    $zero, %lo(text_x)($at)
/* 0E1710 7F0ACBE0 3C018004 */  lui   $at, %hi(text_y)
/* 0E1714 7F0ACBE4 AC200E9C */  sw    $zero, %lo(text_y)($at)
/* 0E1718 7F0ACBE8 3C018004 */  lui   $at, %hi(text_s)
/* 0E171C 7F0ACBEC 3C0F0000 */  lui   $t7, %hi(0x000024B0) # $t7, 0
/* 0E1720 7F0ACBF0 3C180000 */  lui   $t8, 0
/* 0E1724 7F0ACBF4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0E1728 7F0ACBF8 AC200EA0 */  sw    $zero, %lo(text_s)($at)
/* 0E172C 7F0ACBFC 27180000 */  addiu $t8, $t8, 0
/* 0E1730 7F0ACC00 25EF24B0 */  addiu $t7, %lo(0x000024B0) # addiu $t7, $t7, 0x24b0
/* 0E1734 7F0ACC04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E1738 7F0ACC08 3C018004 */  lui   $at, %hi(text_t)
/* 0E173C 7F0ACC0C 01F83023 */  subu  $a2, $t7, $t8
/* 0E1740 7F0ACC10 AC200EA4 */  sw    $zero, %lo(text_t)($at)
/* 0E1744 7F0ACC14 00C02025 */  move  $a0, $a2
/* 0E1748 7F0ACC18 AFA6001C */  sw    $a2, 0x1c($sp)
/* 0E174C 7F0ACC1C 0C0025C8 */  jal   mempAllocBytesInBank
/* 0E1750 7F0ACC20 24050004 */   li    $a1, 4
/* 0E1754 7F0ACC24 3C078004 */  lui   $a3, %hi(ptrFontBankGothic)
/* 0E1758 7F0ACC28 3C088004 */  lui   $t0, %hi(ptrFontBankGothicChars)
/* 0E175C 7F0ACC2C 25080EB0 */  addiu $t0, %lo(ptrFontBankGothicChars) # addiu $t0, $t0, 0xeb0
/* 0E1760 7F0ACC30 24E70EAC */  addiu $a3, %lo(ptrFontBankGothic) # addiu $a3, $a3, 0xeac
/* 0E1764 7F0ACC34 245902A4 */  addiu $t9, $v0, 0x2a4
/* 0E1768 7F0ACC38 3C05002E */  lui   $a1, %hi(_fontbankgothicSegmentRomStart) # $a1, 0x2e
/* 0E176C 7F0ACC3C ACE20000 */  sw    $v0, ($a3)
/* 0E1770 7F0ACC40 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0E1774 7F0ACC44 AD190000 */  sw    $t9, ($t0)
/* 0E1778 7F0ACC48 00402025 */  move  $a0, $v0
/* 0E177C 7F0ACC4C 0C001707 */  jal   romCopy
/* 0E1780 7F0ACC50 24A563F0 */   addiu $a1, %lo(_fontbankgothicSegmentRomStart) # addiu $a1, $a1, 0x63f0
/* 0E1784 7F0ACC54 3C078004 */  lui   $a3, %hi(ptrFontBankGothic)
/* 0E1788 7F0ACC58 3C088004 */  lui   $t0, %hi(ptrFontBankGothicChars)
/* 0E178C 7F0ACC5C 25080EB0 */  addiu $t0, %lo(ptrFontBankGothicChars) # addiu $t0, $t0, 0xeb0
/* 0E1790 7F0ACC60 24E70EAC */  addiu $a3, %lo(ptrFontBankGothic) # addiu $a3, $a3, 0xeac
/* 0E1794 7F0ACC64 00001825 */  move  $v1, $zero
.L7F0ACC68:
/* 0E1798 7F0ACC68 8D090000 */  lw    $t1, ($t0)
/* 0E179C 7F0ACC6C 8CEB0000 */  lw    $t3, ($a3)
/* 0E17A0 7F0ACC70 01231021 */  addu  $v0, $t1, $v1
/* 0E17A4 7F0ACC74 8C4A0014 */  lw    $t2, 0x14($v0)
/* 0E17A8 7F0ACC78 24630018 */  addiu $v1, $v1, 0x18
/* 0E17AC 7F0ACC7C 286108D0 */  slti  $at, $v1, 0x8d0
/* 0E17B0 7F0ACC80 014B6021 */  addu  $t4, $t2, $t3
/* 0E17B4 7F0ACC84 1420FFF8 */  bnez  $at, .L7F0ACC68
/* 0E17B8 7F0ACC88 AC4C0014 */   sw    $t4, 0x14($v0)
/* 0E17BC 7F0ACC8C 3C0D0000 */  lui   $t5, %hi(0x00003540) # $t5, 0
/* 0E17C0 7F0ACC90 3C0E0000 */  lui   $t6, 0
/* 0E17C4 7F0ACC94 25CE0000 */  addiu $t6, $t6, 0
/* 0E17C8 7F0ACC98 25AD3540 */  addiu $t5, %lo(0x00003540) # addiu $t5, $t5, 0x3540
/* 0E17CC 7F0ACC9C 01AE3023 */  subu  $a2, $t5, $t6
/* 0E17D0 7F0ACCA0 00C02025 */  move  $a0, $a2
/* 0E17D4 7F0ACCA4 AFA6001C */  sw    $a2, 0x1c($sp)
/* 0E17D8 7F0ACCA8 0C0025C8 */  jal   mempAllocBytesInBank
/* 0E17DC 7F0ACCAC 24050004 */   li    $a1, 4
/* 0E17E0 7F0ACCB0 3C078004 */  lui   $a3, %hi(ptrFontZurichBold)
/* 0E17E4 7F0ACCB4 3C088004 */  lui   $t0, %hi(ptrFontZurichBoldChars)
/* 0E17E8 7F0ACCB8 25080EB8 */  addiu $t0, %lo(ptrFontZurichBoldChars) # addiu $t0, $t0, 0xeb8
/* 0E17EC 7F0ACCBC 24E70EB4 */  addiu $a3, %lo(ptrFontZurichBold) # addiu $a3, $a3, 0xeb4
/* 0E17F0 7F0ACCC0 244F02A4 */  addiu $t7, $v0, 0x2a4
/* 0E17F4 7F0ACCC4 3C05002F */  lui   $a1, %hi(_fontzurichboldSegmentRomStart) # $a1, 0x2f
/* 0E17F8 7F0ACCC8 ACE20000 */  sw    $v0, ($a3)
/* 0E17FC 7F0ACCCC 8FA6001C */  lw    $a2, 0x1c($sp)
/* 0E1800 7F0ACCD0 AD0F0000 */  sw    $t7, ($t0)
/* 0E1804 7F0ACCD4 00402025 */  move  $a0, $v0
/* 0E1808 7F0ACCD8 0C001707 */  jal   romCopy
/* 0E180C 7F0ACCDC 24A588A0 */   addiu $a1, %lo(_fontzurichboldSegmentRomStart) # addiu $a1, $a1, -0x7760
/* 0E1810 7F0ACCE0 3C088004 */  lui   $t0, %hi(ptrFontZurichBoldChars)
/* 0E1814 7F0ACCE4 25080EB8 */  addiu $t0, %lo(ptrFontZurichBoldChars) # addiu $t0, $t0, 0xeb8
/* 0E1818 7F0ACCE8 8D020000 */  lw    $v0, ($t0)
/* 0E181C 7F0ACCEC 3C078004 */  lui   $a3, %hi(ptrFontZurichBold)
/* 0E1820 7F0ACCF0 24E70EB4 */  addiu $a3, %lo(ptrFontZurichBold) # addiu $a3, $a3, 0xeb4
/* 0E1824 7F0ACCF4 8CF90000 */  lw    $t9, ($a3)
/* 0E1828 7F0ACCF8 8C580014 */  lw    $t8, 0x14($v0)
/* 0E182C 7F0ACCFC 24030030 */  li    $v1, 48
/* 0E1830 7F0ACD00 240408D0 */  li    $a0, 2256
/* 0E1834 7F0ACD04 03194821 */  addu  $t1, $t8, $t9
/* 0E1838 7F0ACD08 AC490014 */  sw    $t1, 0x14($v0)
/* 0E183C 7F0ACD0C 8D020000 */  lw    $v0, ($t0)
/* 0E1840 7F0ACD10 8CEB0000 */  lw    $t3, ($a3)
/* 0E1844 7F0ACD14 8C4A002C */  lw    $t2, 0x2c($v0)
/* 0E1848 7F0ACD18 014B6021 */  addu  $t4, $t2, $t3
/* 0E184C 7F0ACD1C AC4C002C */  sw    $t4, 0x2c($v0)
.L7F0ACD20:
/* 0E1850 7F0ACD20 8D0D0000 */  lw    $t5, ($t0)
/* 0E1854 7F0ACD24 8CEF0000 */  lw    $t7, ($a3)
/* 0E1858 7F0ACD28 01A31021 */  addu  $v0, $t5, $v1
/* 0E185C 7F0ACD2C 8C4E0014 */  lw    $t6, 0x14($v0)
/* 0E1860 7F0ACD30 01CFC021 */  addu  $t8, $t6, $t7
/* 0E1864 7F0ACD34 AC580014 */  sw    $t8, 0x14($v0)
/* 0E1868 7F0ACD38 8D190000 */  lw    $t9, ($t0)
/* 0E186C 7F0ACD3C 8CEA0000 */  lw    $t2, ($a3)
/* 0E1870 7F0ACD40 03231021 */  addu  $v0, $t9, $v1
/* 0E1874 7F0ACD44 8C49002C */  lw    $t1, 0x2c($v0)
/* 0E1878 7F0ACD48 012A5821 */  addu  $t3, $t1, $t2
/* 0E187C 7F0ACD4C AC4B002C */  sw    $t3, 0x2c($v0)
/* 0E1880 7F0ACD50 8D0C0000 */  lw    $t4, ($t0)
/* 0E1884 7F0ACD54 8CEE0000 */  lw    $t6, ($a3)
/* 0E1888 7F0ACD58 01831021 */  addu  $v0, $t4, $v1
/* 0E188C 7F0ACD5C 8C4D0044 */  lw    $t5, 0x44($v0)
/* 0E1890 7F0ACD60 01AE7821 */  addu  $t7, $t5, $t6
/* 0E1894 7F0ACD64 AC4F0044 */  sw    $t7, 0x44($v0)
/* 0E1898 7F0ACD68 8D180000 */  lw    $t8, ($t0)
/* 0E189C 7F0ACD6C 8CE90000 */  lw    $t1, ($a3)
/* 0E18A0 7F0ACD70 03031021 */  addu  $v0, $t8, $v1
/* 0E18A4 7F0ACD74 8C59005C */  lw    $t9, 0x5c($v0)
/* 0E18A8 7F0ACD78 24630060 */  addiu $v1, $v1, 0x60
/* 0E18AC 7F0ACD7C 03295021 */  addu  $t2, $t9, $t1
/* 0E18B0 7F0ACD80 1464FFE7 */  bne   $v1, $a0, .L7F0ACD20
/* 0E18B4 7F0ACD84 AC4A005C */   sw    $t2, 0x5c($v0)
/* 0E18B8 7F0ACD88 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E18BC 7F0ACD8C 27BD0028 */  addiu $sp, $sp, 0x28
/* 0E18C0 7F0ACD90 03E00008 */  jr    $ra
/* 0E18C4 7F0ACD94 00000000 */   nop
)
#endif

Gfx *microcode_constructor(Gfx *gdl) //fontGfxSetup
{
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);

	if (text_bilevel_filter) {
		gDPSetTextureFilter(gdl++, G_TF_AVERAGE);
	} else {
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
	}

	return gdl;
}

Gfx *combiner_bayer_lod_perspective(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureLOD(gdl++, G_TL_LOD);

	return gdl;
}

Gfx* draw_blackbox_to_screen(Gfx *glist, s32 *ulx, s32 *uly, s32 *lrx, s32 *lry)
{
    gDPSetRenderMode(glist++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(glist++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(glist++, 0, 0, 0x00, 0x00, 0x00, 0x00);
    gDPFillRectangle(glist++, *ulx, *uly, *lrx, *lry);
    gDPSetRenderMode(glist++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(glist++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    
    return glist;
}




Gfx * microcode_constructor_related_to_menus(Gfx *gdl, s32 ulx, s32 uly, s32 lrx, s32 lry, u32 color)
{
    u32 r = (u8)(color >> 0x18);
    u32 g = (u8)(color >> 0x10);
    u32 b = (u8)(color >> 0x8);
    u32 a = (u8)(color >> 0);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gdl++, 0, 0, r, g, b, a);
    gDPFillRectangle(gdl++, ulx, uly, lrx, lry);
    gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    return gdl;
}



// perfect dark: textRenderChar
// see also perfect dark: Gfx *text0f15568c(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
// 		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10)
// see also perfect dark: Gfx *text0f156a24
// see also perfect dark: Gfx *textRenderChar
Gfx *construct_fontchar_microcode(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10)
{
    s32 stack;
    s32 stack2;
	s32 tmp;
    s32 sp90;

	sp90 = *y + arg10;
	tmp = font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex] + text_spacing;
    *x -= (tmp - 1);

    if (text_orientation || (*x > 0 && *x <= viGetX() && sp90 + curchar->baseline <= viGetY()))
    {
        if (savedx + width >= *x
				&& savedy + height >= curchar->baseline + sp90
				&& *x >= savedx
				&& curchar->baseline + sp90 + curchar->height >= savedy)
        {
            if (curchar->index < 0x80)
            {
                gDPSetTextureLUT(gdl++, G_TT_NONE);

                /*
                gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, curchar->pixeldata);
                gDPSetTile(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gdl++);
                gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, (curchar->unkc * curchar->height), 0);
                gDPPipeSync(gdl++);                
                gDPSetTile(gdl++,G_IM_FMT_I,G_IM_SIZ_8b,0,0,G_TX_RENDERTILE,0,G_TX_NOMIRROR | G_TX_WRAP,G_TX_NOMASK,G_TX_NOLOD,G_TX_NOMIRROR | G_TX_WRAP,G_TX_NOMASK,G_TX_NOLOD);
                gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, (curchar->unkc - 1) << 2, (curchar->height - 1) << 2);
                */
                gDPLoadTextureBlock(gdl++, curchar->pixeldata, G_IM_FMT_I, G_IM_SIZ_8b, ((curchar->width + 7) & 0xF8), curchar->height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, 0, 0);
            }
            else
            {
                gDPPipeSync(gdl++);
                gDPSetTextureLUT(gdl++, G_TT_IA16);

                if (D_80040EA8)
                {
                    D_80040EA8 = 0;
                    
                    // FD100000 --------: gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(D_80040EBC));
                    // E8000000 00000000: gDPTileSync(gdl++);
                    // F5000100 07000000: gDPSetTile(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                    // E6000000 00000000: gDPLoadSync(gdl++);
                    // F0000000 0703C000: gDPLoadTLUTCmd(gdl++, G_TX_LOADTILE, 15);
                    // E7000000 00000000: gDPPipeSync(gdl++);
                    gDPLoadTLUT_pal16(gdl++, 0, osVirtualToPhysical(D_80040EBC));

                    gDPLoadTLUT_pal16(gdl++, 1, osVirtualToPhysical(&D_80040EDC));
                }

                // FD500000 00000000: gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, 0x00000000);
                // F5500000 07000000: gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                // E6000000 00000000: gDPLoadSync(gdl++);
                // F3000000 07000000: gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 0, 0);
                // E7000000 00000000: gDPPipeSync(gdl++);
                // F5400200 00080000: gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                // F2000000 0003C000: gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, qu102(15), 0);
                //
                // is this a call to gDPLoadTextureBlock ???
                
                gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1,  osVirtualToPhysical((void *) curchar->pixeldata));
                gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gdl++);
                gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, (curchar->height << 2) - 1, 0x800);
                gDPPipeSync(gdl++);
                gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, (curchar->index & 1), G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, 2, 0, 0);
                gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x3c, (curchar->height - 1) << 2);
            }

            if ((*x + curchar->width) <= savedx + width)
            {
				if (savedy <= curchar->baseline + sp90)
                {
					if (curchar->baseline + sp90 + curchar->height <= savedy + height)
                    {
                        if (text_orientation)
                        {
                            // E5000000 --------:
                            // B4000000 --------:
                            // B3000000 0400FC00:
                            gSPTextureRectangleFlip(gdl++,
                                /* xl */ (((sp90 - curchar->baseline) - curchar->height) * 4) + text_y,
                                /* yl */ ((*x * 4) + text_x),
                                /* xh */ ((sp90 - curchar->baseline) * 4) + text_y,
                                /* yh */ ((*x + curchar->width) * 4) + text_x ,
                                /* tile */  G_TX_RENDERTILE,
                                /* s */ text_t,
                                /* t */ ((curchar->height - 1) << 5) + text_s,
                                /* dsdx */ 0x400,
                                /* dsdy */ 0xfc00);
                        }
                        else
                        {
                            // E4000000 --------:
                            // B4000000 --------:
                            // B3000000 04000400:
                            gSPTextureRectangle(gdl++,
                                /* xl */ ((*x * 4) + text_x),
                                /* yl */ ((sp90 + curchar->baseline) * 4) + text_y,
                                /* xh */ ((*x + curchar->width) * 4) + text_x ,
                                /* yh */ ((curchar->baseline + sp90 + curchar->height) * 4) + text_y,
                                /* tile */  G_TX_RENDERTILE,
                                /* s */ text_s,
                                /* t */ text_t,
                                /* dsdx */ 0x400,
                                /* dsdy */ 0x400);
                        }

                    }
                    else if (curchar->baseline + sp90 <= savedy + height)
                    {
                        // E4000000 --------:
                        // B4000000 --------:
                        // B3000000 04000400:
                        gSPTextureRectangle(gdl++,
                            /* xl */ ((*x * 4) + text_x),
                            /* yl */ ((sp90 + curchar->baseline) * 4) + text_y,
                            /* xh */ ((*x + curchar->width) * 4) + text_x ,
                            /* yh */ savedy + height + text_y,
                            /* tile */  G_TX_RENDERTILE,
                            /* s */ text_s,
                            /* t */ text_t,
                            /* dsdx */ 0x400,
                            /* dsdy */ 0x400);
                    }
                }
                else
                {
                    if (curchar->baseline + sp90 + curchar->height >= savedy)
                    {
                        // E4000000 --------:
                        // B4000000 --------:
                        // B3000000 04000400:
                        gSPTextureRectangle(gdl++,
                            /* xl */ ((*x * 4) + text_x),
                            /* yl */ (savedy * 4) + text_y,
                            /* xh */ ((*x + curchar->width) * 4) + text_x ,
                            /* yh */ ((curchar->baseline + sp90 + curchar->height) * 4) + text_y,
                            /* tile */  G_TX_RENDERTILE,
                            /* s */ text_s,
                            /* t */ (((savedy - sp90) - curchar->baseline) << 5) + text_t,
                            /* dsdx */ 0x400,
                            /* dsdy */ 0x400);
                    }
                }
            }
        }
    }
    
    *x += curchar->width;
    return gdl;

}




// perfect dark: textRender
Gfx *textRender(Gfx *gdl, s32 *x, s32 *y, char *text,
                struct fontchar *chars, struct font *font, u32 colour,
                s32 width, s32 height, u32 arg9, s32 lineheight)
{
    s32 savedx;
	s32 savedy;
    s32 prevchar;
    s32 stack = 1;
    s32 stack2;
    s32 stack3;
    s32 stack4;
    //s32 stack5;
    
    D_80040EA8 = 1;

    savedx = *x;
	savedy = *y;
    prevchar = 'H';

	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	if (j_text_trigger != 0 && lineheight < 14) {
		lineheight = 14;
	}

    stack = colour; // ????????????
    gDPSetPrimColor(gdl++, 0, 0, M_COLOR_R(colour), M_COLOR_G(colour), M_COLOR_B(colour), M_COLOR_A(colour));
    
    while (*text != '\0')
    {
		if (*text == ' ') {
			*x += 5;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			prevchar = 'H';

            if ((overlap_correction >= 0) && (savedx == *x))
            {
                *y += overlap_correction;
            }
            else
            {
                *y += lineheight;
            }
            
			text++;
			*x = savedx;
		} else if (*text < 0x80) {
			gdl = construct_fontchar_microcode(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21], font, savedx, savedy, width, height, arg9);
			prevchar = *text;
			text++;
		} else {
			u16 codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
			struct fontchar sp74 = D_80040EFC;

			if (codepoint & 0x2000) {
				sp74.width = 15;
				sp74.height = 16;
			}

            // perfect dark: 0x3c8
#if defined(VERSION_EU) || defined(VERSION_JP)
            if ((codepoint & 0x1fff) >= 0x3c8)
#else
			if ((codepoint & 0x1fff) >= 0x3c7)
#endif
            {
				codepoint = 2;
			}

			sp74.index = codepoint + 0x80;
			sp74.pixeldata = (void *)langGetJpnCharPixels(codepoint);

			gdl = construct_fontchar_microcode(gdl, x, y, &sp74, &sp74, font, savedx, savedy, width, height, arg9);

			text += 2;
		}
	}

    
    return gdl;
}



Gfx *sub_GAME_7F0ADDAC(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, 
                       /*sp70*/ struct fontchar *prevchar, struct font *font, s32 savedx, s32 savedy, 
                       /*sp80*/u32 color, u32 color2, s32 width, s32 height, 
                       /*sp90*/ s32 arg12)
{
    s32 var_s1;
    s32 var_s0;
    s32 tmp;
    s32 sp50;
    s32 tmpx;
    s32 tmpy;
    u32 tmpcolor;

    sp50 = *y + arg12;

    tmp = font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex] + text_spacing;
    *x -= (tmp - 1);

    if (*x > 0
            && *x <= viGetX()
            && sp50 + curchar->baseline <= viGetY()
            && *x <= savedx + width
            && sp50 + curchar->baseline <= savedy + height
            && *x >= savedx
            && sp50 + curchar->baseline + curchar->height >= savedy) {
        if (curchar->index < 0x80) {
            gDPSetTextureLUT(gdl++, G_TT_NONE);
            gDPLoadTextureBlock(gdl++, curchar->pixeldata, G_IM_FMT_I, G_IM_SIZ_8b, ((curchar->width + 7) & 0xF8), curchar->height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, 0, 0);
        } else {
            gDPPipeSync(gdl++);
            gDPSetTextureLUT(gdl++, G_TT_IA16);

            if (D_80040EA8) {
                D_80040EA8 = 0;

                gDPLoadTLUT_pal16(gdl++, 0, osVirtualToPhysical(&D_80040EBC));
                gDPLoadTLUT_pal16(gdl++, 1, osVirtualToPhysical(&D_80040EDC));
            }

            gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1,  osVirtualToPhysical((void *) curchar->pixeldata));
            gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPLoadSync(gdl++);
            gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, (curchar->height << 2) - 1, 0x800);
            gDPPipeSync(gdl++);
            gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, (curchar->index & 1), G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, 2, 0, 0);
            gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x3c, (curchar->height - 1) << 2);
        }

        tmpcolor = color2;
        gDPSetPrimColor(gdl++, 0, 0, M_COLOR_R(tmpcolor), M_COLOR_G(tmpcolor), M_COLOR_B(tmpcolor), M_COLOR_A(tmpcolor));

        for (var_s1 = -1; var_s1 < 2; var_s1++) {
            for (var_s0 = -1; var_s0 < 2; var_s0++) {
                tmpx = *x + var_s1;
                tmpy = sp50 + var_s0;

                if (var_s1 != 0 || var_s0 != 0) {
                    gdl = sub_GAME_7F0AE45C(gdl, tmpx, tmpy, curchar, savedx, savedy, width, height);
                }
            }
        }

        tmpx = *x;
        tmpy = sp50;
        tmpcolor = color;
        gDPSetPrimColor(gdl++, 0, 0, M_COLOR_R(tmpcolor), M_COLOR_G(tmpcolor), M_COLOR_B(tmpcolor), M_COLOR_A(tmpcolor));
        gdl = sub_GAME_7F0AE45C(gdl, tmpx, tmpy, curchar, savedx, savedy, width, height);
    }

    *x += curchar->width;

    return gdl;
}



Gfx *sub_GAME_7F0AE45C(Gfx *gdl, s32 x, s32 y, struct fontchar *curchar, s32 savedx, s32 savedy, s32 width, s32 height)
{
    if (savedx + width >= curchar->width + x)
    {
        if (curchar->baseline + y >= savedy)
        {
            if (savedy + height >= curchar->baseline + y + curchar->height)
            {
                if (text_orientation)
                {
                    gSPTextureRectangleFlip(gdl++, ((y - curchar->baseline) - curchar->height) << 2, x << 2, (y - curchar->baseline) << 2, (x + curchar->width) << 2, G_TX_RENDERTILE, 0, (curchar->height - 1) << 5, 0x400, 0xFC00);
                }
                else
                {
                    gSPTextureRectangle(gdl++, x << 2, (y + curchar->baseline) << 2, (x + curchar->width << 2), (curchar->baseline + y + curchar->height) << 2, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
                }
            }
            else if (savedy + height >= curchar->baseline + y)
            {
                gSPTextureRectangle(gdl++, x << 2, (y + curchar->baseline) << 2, (x + curchar->width) << 2, (savedy + height << 2), G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
            }
        }
        else if (curchar->baseline + y + curchar->height >= savedy)
        {
            gSPTextureRectangle(gdl++, x << 2, savedy<< 2, (x + curchar->width) << 2, (curchar->baseline + y + curchar->height) << 2, G_TX_RENDERTILE, 0, ((savedy - curchar->baseline) - y) << 5, 0x400, 0x400);
        }
    }

    return gdl;
}




Gfx *textRenderGlow(Gfx *gdl, s32 *x, s32 *y, 
                    char *text, struct fontchar *chars, struct font *font, 
                    u32 colour, u32 colour2, s32 width, s32 height, 
                    s32 arg10, s32 lineheight)
{
    u16 codepoint;
	s32 savedy;
    s32 savedx;
    struct fontchar sp74;
    s32 prevchar;
    
    D_80040EA8 = 1;

    savedx = *x;
	savedy = *y;
    prevchar = 'H';

	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	if (j_text_trigger != 0 && lineheight < 14) {
		lineheight = 14;
	}
    
    while (*text != '\0')
    {
		if (*text == ' ') {
			*x += SPACE_WIDTH;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			prevchar = 'H';
			*x = savedx;
            *y += lineheight;
			text++;
		} else if (*text < 0x80) {
            gdl = sub_GAME_7F0ADDAC(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21], font, savedx, savedy, colour, colour2, width, height, arg10);
			prevchar = *text;
			text++;
		} else {
            codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
            sp74 = D_80040F14;

			if (codepoint & 0x2000) {
				sp74.width = 15;
				sp74.height = 16;
			}

#if defined(VERSION_EU) || defined(VERSION_JP)
            if ((codepoint & 0x1fff) >= 0x3c8)
#else
			if ((codepoint & 0x1fff) >= 0x3c7)
#endif
            {
				codepoint = 2;
			}

			sp74.index = codepoint + 0x80;
			sp74.pixeldata = (void *)langGetJpnCharPixels(codepoint);

            gdl = sub_GAME_7F0ADDAC(gdl, x, y, &sp74, &sp74, font, savedx, savedy, colour, colour2, width, height, arg10);

			text += 2;
		}
	}

    return gdl;
}




void textMeasure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight)
{
    char prevchar;
	s32 longest;
	s32 tmp;

	prevchar = 'H';
    tmp = 0;
	longest = 0;
	*textheight = 0;
	*textwidth = 0;

    if (lineheight == 0)
    {
		lineheight = font1['['].baseline + font1['['].height;
    }
    
    if ((j_text_trigger) && (lineheight < 14))
    {
        lineheight = 14;
    }

    while (*text != '\0')
    {
        if (*text == ' ')
        {
            // Space
            if (text[1] != '\n') {
                *textwidth += SPACE_WIDTH;
            }

            prevchar = 'H';
            text++;
        }
        else if (*text == '\n')
        {
            // Line break
            if (*textwidth > longest) {
                longest = *textwidth;
            }

            *textwidth = 0;
            *textheight += lineheight;
            text++;
        }
        else if (*text < 0x80)
        {
            // Normal single-byte character
            tmp = font2->kerning[font1[prevchar - 0x21].kerningindex * 13 + font1[*text - 0x21].kerningindex] + text_spacing - 1;
            *textwidth = font1[*text - 0x21].width + *textwidth - tmp;

            prevchar = *text;
            text++;
        }
        else if (*text < 0xC0)
        {
            // Multi-byte character
            tmp = font2->kerning[0] + text_spacing - 1;
            *textwidth = *textwidth - tmp + 11;
            text += 2;
        }
        else
        {
            // Multi-byte character
            tmp = font2->kerning[0] + text_spacing - 1;
            *textwidth = *textwidth - tmp + 15;
            text += 2;
        }
    };
    
    if (*textwidth < longest)
    {
        *textwidth = longest;
    }
}



// perfect dark: void textWrap
void sub_GAME_7F0AEB64(s32 wrapwidth, char *src, char *dst, struct fontchar *chars, struct font *font)
{
	s32 curlinewidth = 0;
	bool itfits;
	s32 wordlen;
	s32 wordwidth;
	s32 wordheight = 0;
	s32 more = 1;
	s32 v1;
	s32 i;
	u32 stack;
	char curword[32];

    while (more == 1) {
		// Load the next word
		wordwidth = 0;
		wordlen = 0;
		v1 = 0;

        while (*src > ' ')
        {
            curword[wordlen] = *src;
			v1 += chars[*src - 0x21].width;
			src++;
			wordlen++;

            if (curword[wordlen - 1] >= 0x80)
            {
                curword[wordlen] = *src;
                v1 += chars[*src - 0x21].width;
                src++;
                wordlen++;
            }
        }
        
        curword[wordlen] = '\0';

        textMeasure(&wordheight, &wordwidth, curword, chars, font, 0);

        curlinewidth += wordwidth;

        if (curlinewidth <= wrapwidth) {
            itfits = 1;
        } else {
            itfits = 0;
        }

        if (*src == '\n')
        {
            // Write a new line and indent
			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < text_wordwrap; i++) {
					*dst = ' ';
					dst++;
				}
			}

			curlinewidth = 0;

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the original new line that was in src
			*dst = '\n';
			dst++;
        }
        else if (*src == ' ')
        {
            if (!itfits)
            {
				// Write a new line and indent
				*dst = '\n';
				dst++;

				for (i = 0; i < text_wordwrap; i++)
                {
					*dst = ' ';
					dst++;
				}

				curlinewidth = text_wordwrap * SPACE_WIDTH + wordwidth;
			}

			curlinewidth += SPACE_WIDTH;

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the trailing space
			*dst = ' ';
			dst++;
        }
        else if (*src == '\0')
        {
            more = 0;

			if (!itfits) {
				// Write a new line and indent
				*dst = '\n';
				dst++;

				for (i = 0; i < text_wordwrap; i++) {
					*dst = ' ';
					dst++;
				}
			}

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the null terminator
			*dst = '\0';
        }

        src++;
    }
}


void sub_GAME_7F0AEF0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    // (function likely stubbed)
}

u32 sub_GAME_7F0AEF20(u32 param_1,u32 param_2){
  return param_1;
}


