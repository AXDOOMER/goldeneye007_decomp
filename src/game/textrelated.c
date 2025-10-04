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



s32 D_80040F14 = 0;
s32 D_80040F18 = 0;
s32 D_80040F1C = 0xC;
s32 D_80040F20 = 0xB;
s32 D_80040F24 = 0;
s32 D_80040F28 = 0;


// forward declarations

Gfx *construct_fontchar_microcode(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10);
Gfx *sub_GAME_7F0AE45C(Gfx *gdl, s32 x, s32 y, struct fontchar *curchar, s32 savedx, s32 savedy, s32 width, s32 height);

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




#ifdef NONMATCHING

// 94.59% https://decomp.me/scratch/YUnKm
Gfx *sub_GAME_7F0ADDAC(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, 
                       /*sp70*/ struct fontchar *prevchar, struct font *font, s32 savedx, s32 savedy, 
                       /*sp80*/u32 color, u32 color2, s32 width, s32 height, 
                       /*sp90*/ s32 arg12)
{
    s32 stack;
    s32 *stack2;
    s32 var_s1;
    s32 sp50;
	s32 tmp;
    s32 var_s0;

    sp50 = *y + arg12;

    tmp = font->kerning[prevchar->kerningindex * 13 + curchar->kerningindex] + text_spacing;
    *x -= (tmp - 1);
    
    if (*x > 0
        && *x <= viGetX()
        && sp50 + curchar->baseline <= viGetY())
    {
        if (savedx + width >= *x
            && savedy + height >= curchar->baseline + sp50
            && *x >= savedx
            && curchar->baseline + sp50 + curchar->height >= savedy)
        {
            if (curchar->index < 0x80)
            {
                // BA000E02 00000000: gDPSetTextureLUT(gdl++, G_TT_NONE);
                gDPSetTextureLUT(gdl++, G_TT_NONE);
                
                // FD900000 00000000: gDPSetTextureImage(gdl++, G_IM_FMT_I, G_IM_SIZ_16b, 1, 0x00000000);
                // F5900000 07000000: gDPSetTile...
                // E6000000 00000000: gDPLoadSync(gdl++);
                // F3000000 07000000: gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, 0, 0);
                // ...
                gDPLoadTextureBlock(gdl++, curchar->pixeldata, G_IM_FMT_I, G_IM_SIZ_8b, ((curchar->width + 7) & 0xF8), curchar->height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, 0, 0);
            }
            else
            {
                // E7000000 00000000: gDPPipeSync(gdl++);
                gDPPipeSync(gdl++);

                // BA000E02 0000C000: gDPSetTextureLUT(gdl++, G_TT_IA16);
                gDPSetTextureLUT(gdl++, G_TT_IA16);
                
                if (D_80040EA8)
                {
                    D_80040EA8 = 0;

                    gDPLoadTLUT_pal16(gdl++, 0, osVirtualToPhysical(&D_80040EBC));

                    gDPLoadTLUT_pal16(gdl++, 1, osVirtualToPhysical(&D_80040EDC));
                }

                //gDPLoadTextureBlock(gdl++, osVirtualToPhysical((void *) curchar->pixeldata), G_IM_FMT_I, G_IM_SIZ_8b, curchar->index, curchar->height, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, 0, 0);
                
                gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1,  osVirtualToPhysical((void *) curchar->pixeldata));
                gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gdl++);
                gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, (curchar->height << 2) - 1, 0x800);
                gDPPipeSync(gdl++);
                gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, (curchar->index & 1), G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, 2, 0, 0);
                gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x3c, (curchar->height - 1) << 2);
            }

            gDPSetPrimColor(gdl++, 0, 0, M_COLOR_R(color2), M_COLOR_G(color2), M_COLOR_B(color2), M_COLOR_A(color2));

/****
mips_to_c:

    var_s1 = -1;
    var_v1 = *x;
    do
    {
        var_s0 = -1;
loop_25:
        if ((var_s1 != 0) || (var_s0 != 0))
        {
            var_s3_4 = sub_GAME_7F0AE45C(var_s3_4, var_v1 + var_s1, sp50 + var_s0, curchar, savedx, savedy, width, height);
            var_v1 = *x;
        }
        var_s0 += 1;
        if (var_s0 != 2)
        {
            goto loop_25;
        }
        var_s1 += 1;
    } while (var_s1 != 2);
*/
            for (var_s1 = -1; var_s1 < 2; var_s1++)
            {
                for (var_s0 = -1; var_s0 < 2; var_s0++)
                {
                    if (var_s1 != 0 || var_s0 != 0)
                    {
                        gdl = sub_GAME_7F0AE45C(gdl, *x + var_s1, sp50 + var_s0, curchar, savedx, savedy, width, height);
                    }
                }
            }
            
            gDPSetPrimColor(gdl++, 0, 0, M_COLOR_R(color), M_COLOR_G(color), M_COLOR_B(color), M_COLOR_A(color));

            gdl = sub_GAME_7F0AE45C(gdl, *x, sp50, curchar, savedx, savedy, width, height);
        }
    }
    
    *x += curchar->width;
    
    return gdl;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0ADDAC
/* 0E28DC 7F0ADDAC 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0E28E0 7F0ADDB0 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0E28E4 7F0ADDB4 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0E28E8 7F0ADDB8 AFB70044 */  sw    $s7, 0x44($sp)
/* 0E28EC 7F0ADDBC AFB60040 */  sw    $s6, 0x40($sp)
/* 0E28F0 7F0ADDC0 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0E28F4 7F0ADDC4 AFB40038 */  sw    $s4, 0x38($sp)
/* 0E28F8 7F0ADDC8 AFB30034 */  sw    $s3, 0x34($sp)
/* 0E28FC 7F0ADDCC AFB20030 */  sw    $s2, 0x30($sp)
/* 0E2900 7F0ADDD0 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0E2904 7F0ADDD4 AFB00028 */  sw    $s0, 0x28($sp)
/* 0E2908 7F0ADDD8 8CCE0000 */  lw    $t6, ($a2)
/* 0E290C 7F0ADDDC 8FAF0090 */  lw    $t7, 0x90($sp)
/* 0E2910 7F0ADDE0 8FA90070 */  lw    $t1, 0x70($sp)
/* 0E2914 7F0ADDE4 8FB90074 */  lw    $t9, 0x74($sp)
/* 0E2918 7F0ADDE8 01CFC021 */  addu  $t8, $t6, $t7
/* 0E291C 7F0ADDEC AFB80050 */  sw    $t8, 0x50($sp)
/* 0E2920 7F0ADDF0 8D2A0010 */  lw    $t2, 0x10($t1)
/* 0E2924 7F0ADDF4 8CEE0010 */  lw    $t6, 0x10($a3)
/* 0E2928 7F0ADDF8 00809825 */  move  $s3, $a0
/* 0E292C 7F0ADDFC 000A5880 */  sll   $t3, $t2, 2
/* 0E2930 7F0ADE00 016A5823 */  subu  $t3, $t3, $t2
/* 0E2934 7F0ADE04 000B5880 */  sll   $t3, $t3, 2
/* 0E2938 7F0ADE08 016A5821 */  addu  $t3, $t3, $t2
/* 0E293C 7F0ADE0C 000B6080 */  sll   $t4, $t3, 2
/* 0E2940 7F0ADE10 032C6821 */  addu  $t5, $t9, $t4
/* 0E2944 7F0ADE14 000E7880 */  sll   $t7, $t6, 2
/* 0E2948 7F0ADE18 01AFC021 */  addu  $t8, $t5, $t7
/* 0E294C 7F0ADE1C 3C0A8004 */  lui   $t2, %hi(text_spacing)
/* 0E2950 7F0ADE20 8D4A0E84 */  lw    $t2, %lo(text_spacing)($t2)
/* 0E2954 7F0ADE24 8F090000 */  lw    $t1, ($t8)
/* 0E2958 7F0ADE28 8CAB0000 */  lw    $t3, ($a1)
/* 0E295C 7F0ADE2C 00E0F025 */  move  $fp, $a3
/* 0E2960 7F0ADE30 012A1021 */  addu  $v0, $t1, $t2
/* 0E2964 7F0ADE34 0162C823 */  subu  $t9, $t3, $v0
/* 0E2968 7F0ADE38 272C0001 */  addiu $t4, $t9, 1
/* 0E296C 7F0ADE3C ACAC0000 */  sw    $t4, ($a1)
/* 0E2970 7F0ADE40 AFA50064 */  sw    $a1, 0x64($sp)
/* 0E2974 7F0ADE44 8CAE0000 */  lw    $t6, ($a1)
/* 0E2978 7F0ADE48 59C00173 */  blezl $t6, .L7F0AE418
/* 0E297C 7F0ADE4C 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E2980 7F0ADE50 0C001107 */  jal   viGetX
/* 0E2984 7F0ADE54 AFA50064 */   sw    $a1, 0x64($sp)
/* 0E2988 7F0ADE58 8FAD0064 */  lw    $t5, 0x64($sp)
/* 0E298C 7F0ADE5C 8DAF0000 */  lw    $t7, ($t5)
/* 0E2990 7F0ADE60 004F082A */  slt   $at, $v0, $t7
/* 0E2994 7F0ADE64 5420016C */  bnezl $at, .L7F0AE418
/* 0E2998 7F0ADE68 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E299C 7F0ADE6C 0C00110B */  jal   viGetY
/* 0E29A0 7F0ADE70 00000000 */   nop
/* 0E29A4 7F0ADE74 8FB80050 */  lw    $t8, 0x50($sp)
/* 0E29A8 7F0ADE78 8FC90004 */  lw    $t1, 4($fp)
/* 0E29AC 7F0ADE7C 8FAA0064 */  lw    $t2, 0x64($sp)
/* 0E29B0 7F0ADE80 03092021 */  addu  $a0, $t8, $t1
/* 0E29B4 7F0ADE84 0044082A */  slt   $at, $v0, $a0
/* 0E29B8 7F0ADE88 54200163 */  bnezl $at, .L7F0AE418
/* 0E29BC 7F0ADE8C 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E29C0 7F0ADE90 8FB40078 */  lw    $s4, 0x78($sp)
/* 0E29C4 7F0ADE94 8FB60088 */  lw    $s6, 0x88($sp)
/* 0E29C8 7F0ADE98 8D430000 */  lw    $v1, ($t2)
/* 0E29CC 7F0ADE9C 8FB5007C */  lw    $s5, 0x7c($sp)
/* 0E29D0 7F0ADEA0 02965821 */  addu  $t3, $s4, $s6
/* 0E29D4 7F0ADEA4 0163082A */  slt   $at, $t3, $v1
/* 0E29D8 7F0ADEA8 1420015A */  bnez  $at, .L7F0AE414
/* 0E29DC 7F0ADEAC 8FB7008C */   lw    $s7, 0x8c($sp)
/* 0E29E0 7F0ADEB0 02B7C821 */  addu  $t9, $s5, $s7
/* 0E29E4 7F0ADEB4 0324082A */  slt   $at, $t9, $a0
/* 0E29E8 7F0ADEB8 14200156 */  bnez  $at, .L7F0AE414
/* 0E29EC 7F0ADEBC 0074082A */   slt   $at, $v1, $s4
/* 0E29F0 7F0ADEC0 54200155 */  bnezl $at, .L7F0AE418
/* 0E29F4 7F0ADEC4 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E29F8 7F0ADEC8 8FCC0008 */  lw    $t4, 8($fp)
/* 0E29FC 7F0ADECC 008C7021 */  addu  $t6, $a0, $t4
/* 0E2A00 7F0ADED0 01D5082A */  slt   $at, $t6, $s5
/* 0E2A04 7F0ADED4 54200150 */  bnezl $at, .L7F0AE418
/* 0E2A08 7F0ADED8 8FA50064 */   lw    $a1, 0x64($sp)
/* 0E2A0C 7F0ADEDC 8FCD0000 */  lw    $t5, ($fp)
/* 0E2A10 7F0ADEE0 3C058004 */  lui   $a1, %hi(D_80040EA8)
/* 0E2A14 7F0ADEE4 24A50EA8 */  addiu $a1, %lo(D_80040EA8) # addiu $a1, $a1, 0xea8
/* 0E2A18 7F0ADEE8 29A10080 */  slti  $at, $t5, 0x80
/* 0E2A1C 7F0ADEEC 1020006E */  beqz  $at, .L7F0AE0A8
/* 0E2A20 7F0ADEF0 3C11E700 */   lui   $s1, 0xe700
/* 0E2A24 7F0ADEF4 02601025 */  move  $v0, $s3
/* 0E2A28 7F0ADEF8 3C0FBA00 */  lui   $t7, (0xBA000E02 >> 16) # lui $t7, 0xba00
/* 0E2A2C 7F0ADEFC 35EF0E02 */  ori   $t7, (0xBA000E02 & 0xFFFF) # ori $t7, $t7, 0xe02
/* 0E2A30 7F0ADF00 26730008 */  addiu $s3, $s3, 8
/* 0E2A34 7F0ADF04 AC4F0000 */  sw    $t7, ($v0)
/* 0E2A38 7F0ADF08 AC400004 */  sw    $zero, 4($v0)
/* 0E2A3C 7F0ADF0C 02601825 */  move  $v1, $s3
/* 0E2A40 7F0ADF10 3C18FD90 */  lui   $t8, 0xfd90
/* 0E2A44 7F0ADF14 AC780000 */  sw    $t8, ($v1)
/* 0E2A48 7F0ADF18 8FC90014 */  lw    $t1, 0x14($fp)
/* 0E2A4C 7F0ADF1C 26730008 */  addiu $s3, $s3, 8
/* 0E2A50 7F0ADF20 02602025 */  move  $a0, $s3
/* 0E2A54 7F0ADF24 26730008 */  addiu $s3, $s3, 8
/* 0E2A58 7F0ADF28 AC690004 */  sw    $t1, 4($v1)
/* 0E2A5C 7F0ADF2C 3C120700 */  lui   $s2, 0x700
/* 0E2A60 7F0ADF30 02602825 */  move  $a1, $s3
/* 0E2A64 7F0ADF34 3C0AF590 */  lui   $t2, 0xf590
/* 0E2A68 7F0ADF38 AC8A0000 */  sw    $t2, ($a0)
/* 0E2A6C 7F0ADF3C AC920004 */  sw    $s2, 4($a0)
/* 0E2A70 7F0ADF40 26730008 */  addiu $s3, $s3, 8
/* 0E2A74 7F0ADF44 3C0BE600 */  lui   $t3, 0xe600
/* 0E2A78 7F0ADF48 ACAB0000 */  sw    $t3, ($a1)
/* 0E2A7C 7F0ADF4C 02604025 */  move  $t0, $s3
/* 0E2A80 7F0ADF50 ACA00004 */  sw    $zero, 4($a1)
/* 0E2A84 7F0ADF54 3C19F300 */  lui   $t9, 0xf300
/* 0E2A88 7F0ADF58 AD190000 */  sw    $t9, ($t0)
/* 0E2A8C 7F0ADF5C 8FC3000C */  lw    $v1, 0xc($fp)
/* 0E2A90 7F0ADF60 8FCE0008 */  lw    $t6, 8($fp)
/* 0E2A94 7F0ADF64 26730008 */  addiu $s3, $s3, 8
/* 0E2A98 7F0ADF68 24630007 */  addiu $v1, $v1, 7
/* 0E2A9C 7F0ADF6C 306C00F8 */  andi  $t4, $v1, 0xf8
/* 0E2AA0 7F0ADF70 018E0019 */  multu $t4, $t6
/* 0E2AA4 7F0ADF74 01801825 */  move  $v1, $t4
/* 0E2AA8 7F0ADF78 3C11E700 */  lui   $s1, 0xe700
/* 0E2AAC 7F0ADF7C 240607FF */  li    $a2, 2047
/* 0E2AB0 7F0ADF80 00001012 */  mflo  $v0
/* 0E2AB4 7F0ADF84 24420001 */  addiu $v0, $v0, 1
/* 0E2AB8 7F0ADF88 00026843 */  sra   $t5, $v0, 1
/* 0E2ABC 7F0ADF8C 25A2FFFF */  addiu $v0, $t5, -1
/* 0E2AC0 7F0ADF90 284107FF */  slti  $at, $v0, 0x7ff
/* 0E2AC4 7F0ADF94 10200003 */  beqz  $at, .L7F0ADFA4
/* 0E2AC8 7F0ADF98 00000000 */   nop
/* 0E2ACC 7F0ADF9C 10000001 */  b     .L7F0ADFA4
/* 0E2AD0 7F0ADFA0 00403025 */   move  $a2, $v0
.L7F0ADFA4:
/* 0E2AD4 7F0ADFA4 04610003 */  bgez  $v1, .L7F0ADFB4
/* 0E2AD8 7F0ADFA8 000310C3 */   sra   $v0, $v1, 3
/* 0E2ADC 7F0ADFAC 24610007 */  addiu $at, $v1, 7
/* 0E2AE0 7F0ADFB0 000110C3 */  sra   $v0, $at, 3
.L7F0ADFB4:
/* 0E2AE4 7F0ADFB4 1C400003 */  bgtz  $v0, .L7F0ADFC4
/* 0E2AE8 7F0ADFB8 30CB0FFF */   andi  $t3, $a2, 0xfff
/* 0E2AEC 7F0ADFBC 10000002 */  b     .L7F0ADFC8
/* 0E2AF0 7F0ADFC0 24070001 */   li    $a3, 1
.L7F0ADFC4:
/* 0E2AF4 7F0ADFC4 00403825 */  move  $a3, $v0
.L7F0ADFC8:
/* 0E2AF8 7F0ADFC8 1C400003 */  bgtz  $v0, .L7F0ADFD8
/* 0E2AFC 7F0ADFCC 24EF07FF */   addiu $t7, $a3, 0x7ff
/* 0E2B00 7F0ADFD0 10000002 */  b     .L7F0ADFDC
/* 0E2B04 7F0ADFD4 24050001 */   li    $a1, 1
.L7F0ADFD8:
/* 0E2B08 7F0ADFD8 00402825 */  move  $a1, $v0
.L7F0ADFDC:
/* 0E2B0C 7F0ADFDC 01E5001A */  div   $zero, $t7, $a1
/* 0E2B10 7F0ADFE0 0000C012 */  mflo  $t8
/* 0E2B14 7F0ADFE4 33090FFF */  andi  $t1, $t8, 0xfff
/* 0E2B18 7F0ADFE8 01325025 */  or    $t2, $t1, $s2
/* 0E2B1C 7F0ADFEC 000BCB00 */  sll   $t9, $t3, 0xc
/* 0E2B20 7F0ADFF0 01596025 */  or    $t4, $t2, $t9
/* 0E2B24 7F0ADFF4 AD0C0004 */  sw    $t4, 4($t0)
/* 0E2B28 7F0ADFF8 02601025 */  move  $v0, $s3
/* 0E2B2C 7F0ADFFC AC510000 */  sw    $s1, ($v0)
/* 0E2B30 7F0AE000 AC400004 */  sw    $zero, 4($v0)
/* 0E2B34 7F0AE004 8FCE000C */  lw    $t6, 0xc($fp)
/* 0E2B38 7F0AE008 14A00002 */  bnez  $a1, .L7F0AE014
/* 0E2B3C 7F0AE00C 00000000 */   nop
/* 0E2B40 7F0AE010 0007000D */  break 7
.L7F0AE014:
/* 0E2B44 7F0AE014 2401FFFF */  li    $at, -1
/* 0E2B48 7F0AE018 14A10004 */  bne   $a1, $at, .L7F0AE02C
/* 0E2B4C 7F0AE01C 3C018000 */   lui   $at, 0x8000
/* 0E2B50 7F0AE020 15E10002 */  bne   $t7, $at, .L7F0AE02C
/* 0E2B54 7F0AE024 00000000 */   nop
/* 0E2B58 7F0AE028 0006000D */  break 6
.L7F0AE02C:
/* 0E2B5C 7F0AE02C 25CD0007 */  addiu $t5, $t6, 7
/* 0E2B60 7F0AE030 31AF00F8 */  andi  $t7, $t5, 0xf8
/* 0E2B64 7F0AE034 25F80007 */  addiu $t8, $t7, 7
/* 0E2B68 7F0AE038 001848C3 */  sra   $t1, $t8, 3
/* 0E2B6C 7F0AE03C 26730008 */  addiu $s3, $s3, 8
/* 0E2B70 7F0AE040 02601825 */  move  $v1, $s3
/* 0E2B74 7F0AE044 312B01FF */  andi  $t3, $t1, 0x1ff
/* 0E2B78 7F0AE048 000B5240 */  sll   $t2, $t3, 9
/* 0E2B7C 7F0AE04C 3C01F588 */  lui   $at, 0xf588
/* 0E2B80 7F0AE050 0141C825 */  or    $t9, $t2, $at
/* 0E2B84 7F0AE054 26730008 */  addiu $s3, $s3, 8
/* 0E2B88 7F0AE058 02602025 */  move  $a0, $s3
/* 0E2B8C 7F0AE05C AC790000 */  sw    $t9, ($v1)
/* 0E2B90 7F0AE060 AC600004 */  sw    $zero, 4($v1)
/* 0E2B94 7F0AE064 3C0CF200 */  lui   $t4, 0xf200
/* 0E2B98 7F0AE068 AC8C0000 */  sw    $t4, ($a0)
/* 0E2B9C 7F0AE06C 8FCE000C */  lw    $t6, 0xc($fp)
/* 0E2BA0 7F0AE070 8FD90008 */  lw    $t9, 8($fp)
/* 0E2BA4 7F0AE074 26730008 */  addiu $s3, $s3, 8
/* 0E2BA8 7F0AE078 25CD0007 */  addiu $t5, $t6, 7
/* 0E2BAC 7F0AE07C 31AF00F8 */  andi  $t7, $t5, 0xf8
/* 0E2BB0 7F0AE080 25F8FFFF */  addiu $t8, $t7, -1
/* 0E2BB4 7F0AE084 00184880 */  sll   $t1, $t8, 2
/* 0E2BB8 7F0AE088 272CFFFF */  addiu $t4, $t9, -1
/* 0E2BBC 7F0AE08C 000C7080 */  sll   $t6, $t4, 2
/* 0E2BC0 7F0AE090 312B0FFF */  andi  $t3, $t1, 0xfff
/* 0E2BC4 7F0AE094 000B5300 */  sll   $t2, $t3, 0xc
/* 0E2BC8 7F0AE098 31CD0FFF */  andi  $t5, $t6, 0xfff
/* 0E2BCC 7F0AE09C 014D7825 */  or    $t7, $t2, $t5
/* 0E2BD0 7F0AE0A0 10000095 */  b     .L7F0AE2F8
/* 0E2BD4 7F0AE0A4 AC8F0004 */   sw    $t7, 4($a0)
.L7F0AE0A8:
/* 0E2BD8 7F0AE0A8 02601025 */  move  $v0, $s3
/* 0E2BDC 7F0AE0AC 26730008 */  addiu $s3, $s3, 8
/* 0E2BE0 7F0AE0B0 AC510000 */  sw    $s1, ($v0)
/* 0E2BE4 7F0AE0B4 AC400004 */  sw    $zero, 4($v0)
/* 0E2BE8 7F0AE0B8 02601825 */  move  $v1, $s3
/* 0E2BEC 7F0AE0BC 3C18BA00 */  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00
/* 0E2BF0 7F0AE0C0 37180E02 */  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02
/* 0E2BF4 7F0AE0C4 3409C000 */  li    $t1, 49152
/* 0E2BF8 7F0AE0C8 AC690004 */  sw    $t1, 4($v1)
/* 0E2BFC 7F0AE0CC AC780000 */  sw    $t8, ($v1)
/* 0E2C00 7F0AE0D0 8CAB0000 */  lw    $t3, ($a1)
/* 0E2C04 7F0AE0D4 26730008 */  addiu $s3, $s3, 8
/* 0E2C08 7F0AE0D8 02608025 */  move  $s0, $s3
/* 0E2C0C 7F0AE0DC 11600047 */  beqz  $t3, .L7F0AE1FC
/* 0E2C10 7F0AE0E0 3C19FD10 */   lui   $t9, 0xfd10
/* 0E2C14 7F0AE0E4 ACA00000 */  sw    $zero, ($a1)
/* 0E2C18 7F0AE0E8 3C048004 */  lui   $a0, %hi(D_80040EBC)
/* 0E2C1C 7F0AE0EC 24840EBC */  addiu $a0, %lo(D_80040EBC) # addiu $a0, $a0, 0xebc
/* 0E2C20 7F0AE0F0 AE190000 */  sw    $t9, ($s0)
/* 0E2C24 7F0AE0F4 0C003A2C */  jal   osVirtualToPhysical
/* 0E2C28 7F0AE0F8 26730008 */   addiu $s3, $s3, 8
/* 0E2C2C 7F0AE0FC 02601825 */  move  $v1, $s3
/* 0E2C30 7F0AE100 26730008 */  addiu $s3, $s3, 8
/* 0E2C34 7F0AE104 AE020004 */  sw    $v0, 4($s0)
/* 0E2C38 7F0AE108 02602025 */  move  $a0, $s3
/* 0E2C3C 7F0AE10C 3C0CE800 */  lui   $t4, 0xe800
/* 0E2C40 7F0AE110 AC6C0000 */  sw    $t4, ($v1)
/* 0E2C44 7F0AE114 AC600004 */  sw    $zero, 4($v1)
/* 0E2C48 7F0AE118 3C0EF500 */  lui   $t6, (0xF5000100 >> 16) # lui $t6, 0xf500
/* 0E2C4C 7F0AE11C 35CE0100 */  ori   $t6, (0xF5000100 & 0xFFFF) # ori $t6, $t6, 0x100
/* 0E2C50 7F0AE120 26730008 */  addiu $s3, $s3, 8
/* 0E2C54 7F0AE124 3C120700 */  lui   $s2, 0x700
/* 0E2C58 7F0AE128 AC920004 */  sw    $s2, 4($a0)
/* 0E2C5C 7F0AE12C 02602825 */  move  $a1, $s3
/* 0E2C60 7F0AE130 AC8E0000 */  sw    $t6, ($a0)
/* 0E2C64 7F0AE134 26730008 */  addiu $s3, $s3, 8
/* 0E2C68 7F0AE138 02603025 */  move  $a2, $s3
/* 0E2C6C 7F0AE13C 3C0AE600 */  lui   $t2, 0xe600
/* 0E2C70 7F0AE140 ACAA0000 */  sw    $t2, ($a1)
/* 0E2C74 7F0AE144 26730008 */  addiu $s3, $s3, 8
/* 0E2C78 7F0AE148 ACA00004 */  sw    $zero, 4($a1)
/* 0E2C7C 7F0AE14C 3C0F0703 */  lui   $t7, (0x0703C000 >> 16) # lui $t7, 0x703
/* 0E2C80 7F0AE150 35EFC000 */  ori   $t7, (0x0703C000 & 0xFFFF) # ori $t7, $t7, 0xc000
/* 0E2C84 7F0AE154 02603825 */  move  $a3, $s3
/* 0E2C88 7F0AE158 3C0DF000 */  lui   $t5, 0xf000
/* 0E2C8C 7F0AE15C ACCD0000 */  sw    $t5, ($a2)
/* 0E2C90 7F0AE160 ACCF0004 */  sw    $t7, 4($a2)
/* 0E2C94 7F0AE164 26730008 */  addiu $s3, $s3, 8
/* 0E2C98 7F0AE168 ACE00004 */  sw    $zero, 4($a3)
/* 0E2C9C 7F0AE16C ACF10000 */  sw    $s1, ($a3)
/* 0E2CA0 7F0AE170 02608025 */  move  $s0, $s3
/* 0E2CA4 7F0AE174 3C048004 */  lui   $a0, %hi(D_80040EDC)
/* 0E2CA8 7F0AE178 3C18FD10 */  lui   $t8, 0xfd10
/* 0E2CAC 7F0AE17C AE180000 */  sw    $t8, ($s0)
/* 0E2CB0 7F0AE180 24840EDC */  addiu $a0, %lo(D_80040EDC) # addiu $a0, $a0, 0xedc
/* 0E2CB4 7F0AE184 0C003A2C */  jal   osVirtualToPhysical
/* 0E2CB8 7F0AE188 26730008 */   addiu $s3, $s3, 8
/* 0E2CBC 7F0AE18C 02601825 */  move  $v1, $s3
/* 0E2CC0 7F0AE190 26730008 */  addiu $s3, $s3, 8
/* 0E2CC4 7F0AE194 AE020004 */  sw    $v0, 4($s0)
/* 0E2CC8 7F0AE198 02602025 */  move  $a0, $s3
/* 0E2CCC 7F0AE19C 3C09E800 */  lui   $t1, 0xe800
/* 0E2CD0 7F0AE1A0 AC690000 */  sw    $t1, ($v1)
/* 0E2CD4 7F0AE1A4 26730008 */  addiu $s3, $s3, 8
/* 0E2CD8 7F0AE1A8 AC600004 */  sw    $zero, 4($v1)
/* 0E2CDC 7F0AE1AC 3C0BF500 */  lui   $t3, (0xF5000110 >> 16) # lui $t3, 0xf500
/* 0E2CE0 7F0AE1B0 356B0110 */  ori   $t3, (0xF5000110 & 0xFFFF) # ori $t3, $t3, 0x110
/* 0E2CE4 7F0AE1B4 02602825 */  move  $a1, $s3
/* 0E2CE8 7F0AE1B8 26730008 */  addiu $s3, $s3, 8
/* 0E2CEC 7F0AE1BC AC8B0000 */  sw    $t3, ($a0)
/* 0E2CF0 7F0AE1C0 AC920004 */  sw    $s2, 4($a0)
/* 0E2CF4 7F0AE1C4 02603025 */  move  $a2, $s3
/* 0E2CF8 7F0AE1C8 3C19E600 */  lui   $t9, 0xe600
/* 0E2CFC 7F0AE1CC ACB90000 */  sw    $t9, ($a1)
/* 0E2D00 7F0AE1D0 26730008 */  addiu $s3, $s3, 8
/* 0E2D04 7F0AE1D4 ACA00004 */  sw    $zero, 4($a1)
/* 0E2D08 7F0AE1D8 3C0E0703 */  lui   $t6, (0x0703C000 >> 16) # lui $t6, 0x703
/* 0E2D0C 7F0AE1DC 35CEC000 */  ori   $t6, (0x0703C000 & 0xFFFF) # ori $t6, $t6, 0xc000
/* 0E2D10 7F0AE1E0 02603825 */  move  $a3, $s3
/* 0E2D14 7F0AE1E4 3C0CF000 */  lui   $t4, 0xf000
/* 0E2D18 7F0AE1E8 ACCC0000 */  sw    $t4, ($a2)
/* 0E2D1C 7F0AE1EC ACCE0004 */  sw    $t6, 4($a2)
/* 0E2D20 7F0AE1F0 ACE00004 */  sw    $zero, 4($a3)
/* 0E2D24 7F0AE1F4 ACF10000 */  sw    $s1, ($a3)
/* 0E2D28 7F0AE1F8 26730008 */  addiu $s3, $s3, 8
.L7F0AE1FC:
/* 0E2D2C 7F0AE1FC 02608025 */  move  $s0, $s3
/* 0E2D30 7F0AE200 3C0AFD50 */  lui   $t2, 0xfd50
/* 0E2D34 7F0AE204 AE0A0000 */  sw    $t2, ($s0)
/* 0E2D38 7F0AE208 3C120700 */  lui   $s2, 0x700
/* 0E2D3C 7F0AE20C 8FC40014 */  lw    $a0, 0x14($fp)
/* 0E2D40 7F0AE210 0C003A2C */  jal   osVirtualToPhysical
/* 0E2D44 7F0AE214 26730008 */   addiu $s3, $s3, 8
/* 0E2D48 7F0AE218 02601825 */  move  $v1, $s3
/* 0E2D4C 7F0AE21C AE020004 */  sw    $v0, 4($s0)
/* 0E2D50 7F0AE220 26730008 */  addiu $s3, $s3, 8
/* 0E2D54 7F0AE224 3C0DF550 */  lui   $t5, 0xf550
/* 0E2D58 7F0AE228 02602025 */  move  $a0, $s3
/* 0E2D5C 7F0AE22C AC6D0000 */  sw    $t5, ($v1)
/* 0E2D60 7F0AE230 AC720004 */  sw    $s2, 4($v1)
/* 0E2D64 7F0AE234 26730008 */  addiu $s3, $s3, 8
/* 0E2D68 7F0AE238 3C0FE600 */  lui   $t7, 0xe600
/* 0E2D6C 7F0AE23C AC8F0000 */  sw    $t7, ($a0)
/* 0E2D70 7F0AE240 AC800004 */  sw    $zero, 4($a0)
/* 0E2D74 7F0AE244 02603025 */  move  $a2, $s3
/* 0E2D78 7F0AE248 3C18F300 */  lui   $t8, 0xf300
/* 0E2D7C 7F0AE24C ACD80000 */  sw    $t8, ($a2)
/* 0E2D80 7F0AE250 8FC70008 */  lw    $a3, 8($fp)
/* 0E2D84 7F0AE254 26730008 */  addiu $s3, $s3, 8
/* 0E2D88 7F0AE258 02601025 */  move  $v0, $s3
/* 0E2D8C 7F0AE25C 00074880 */  sll   $t1, $a3, 2
/* 0E2D90 7F0AE260 2527FFFF */  addiu $a3, $t1, -1
/* 0E2D94 7F0AE264 28E107FF */  slti  $at, $a3, 0x7ff
/* 0E2D98 7F0AE268 10200003 */  beqz  $at, .L7F0AE278
/* 0E2D9C 7F0AE26C 26730008 */   addiu $s3, $s3, 8
/* 0E2DA0 7F0AE270 10000002 */  b     .L7F0AE27C
/* 0E2DA4 7F0AE274 00E02825 */   move  $a1, $a3
.L7F0AE278:
/* 0E2DA8 7F0AE278 240507FF */  li    $a1, 2047
.L7F0AE27C:
/* 0E2DAC 7F0AE27C 30AB0FFF */  andi  $t3, $a1, 0xfff
/* 0E2DB0 7F0AE280 000BCB00 */  sll   $t9, $t3, 0xc
/* 0E2DB4 7F0AE284 03326025 */  or    $t4, $t9, $s2
/* 0E2DB8 7F0AE288 358E0800 */  ori   $t6, $t4, 0x800
/* 0E2DBC 7F0AE28C ACCE0004 */  sw    $t6, 4($a2)
/* 0E2DC0 7F0AE290 3C0AF540 */  lui   $t2, (0xF5400200 >> 16) # lui $t2, 0xf540
/* 0E2DC4 7F0AE294 AC400004 */  sw    $zero, 4($v0)
/* 0E2DC8 7F0AE298 AC510000 */  sw    $s1, ($v0)
/* 0E2DCC 7F0AE29C 354A0200 */  ori   $t2, (0xF5400200 & 0xFFFF) # ori $t2, $t2, 0x200
/* 0E2DD0 7F0AE2A0 02601825 */  move  $v1, $s3
/* 0E2DD4 7F0AE2A4 AC6A0000 */  sw    $t2, ($v1)
/* 0E2DD8 7F0AE2A8 8FCF0000 */  lw    $t7, ($fp)
/* 0E2DDC 7F0AE2AC 3C010008 */  lui   $at, 8
/* 0E2DE0 7F0AE2B0 26730008 */  addiu $s3, $s3, 8
/* 0E2DE4 7F0AE2B4 31F80001 */  andi  $t8, $t7, 1
/* 0E2DE8 7F0AE2B8 00184D00 */  sll   $t1, $t8, 0x14
/* 0E2DEC 7F0AE2BC 01215825 */  or    $t3, $t1, $at
/* 0E2DF0 7F0AE2C0 35790200 */  ori   $t9, $t3, 0x200
/* 0E2DF4 7F0AE2C4 AC790004 */  sw    $t9, 4($v1)
/* 0E2DF8 7F0AE2C8 02602025 */  move  $a0, $s3
/* 0E2DFC 7F0AE2CC 3C0CF200 */  lui   $t4, 0xf200
/* 0E2E00 7F0AE2D0 AC8C0000 */  sw    $t4, ($a0)
/* 0E2E04 7F0AE2D4 8FCE0008 */  lw    $t6, 8($fp)
/* 0E2E08 7F0AE2D8 3C010003 */  lui   $at, (0x0003C000 >> 16) # lui $at, 3
/* 0E2E0C 7F0AE2DC 3421C000 */  ori   $at, (0x0003C000 & 0xFFFF) # ori $at, $at, 0xc000
/* 0E2E10 7F0AE2E0 25CAFFFF */  addiu $t2, $t6, -1
/* 0E2E14 7F0AE2E4 000A6880 */  sll   $t5, $t2, 2
/* 0E2E18 7F0AE2E8 31AF0FFF */  andi  $t7, $t5, 0xfff
/* 0E2E1C 7F0AE2EC 01E1C025 */  or    $t8, $t7, $at
/* 0E2E20 7F0AE2F0 AC980004 */  sw    $t8, 4($a0)
/* 0E2E24 7F0AE2F4 26730008 */  addiu $s3, $s3, 8
.L7F0AE2F8:
/* 0E2E28 7F0AE2F8 8FA20084 */  lw    $v0, 0x84($sp)
/* 0E2E2C 7F0AE2FC 02602025 */  move  $a0, $s3
/* 0E2E30 7F0AE300 3C09FA00 */  lui   $t1, 0xfa00
/* 0E2E34 7F0AE304 00026602 */  srl   $t4, $v0, 0x18
/* 0E2E38 7F0AE308 00026C02 */  srl   $t5, $v0, 0x10
/* 0E2E3C 7F0AE30C 31AF00FF */  andi  $t7, $t5, 0xff
/* 0E2E40 7F0AE310 000C7600 */  sll   $t6, $t4, 0x18
/* 0E2E44 7F0AE314 000FC400 */  sll   $t8, $t7, 0x10
/* 0E2E48 7F0AE318 AC890000 */  sw    $t1, ($a0)
/* 0E2E4C 7F0AE31C 0002CA02 */  srl   $t9, $v0, 8
/* 0E2E50 7F0AE320 332C00FF */  andi  $t4, $t9, 0xff
/* 0E2E54 7F0AE324 01D84825 */  or    $t1, $t6, $t8
/* 0E2E58 7F0AE328 000C5200 */  sll   $t2, $t4, 8
/* 0E2E5C 7F0AE32C 012A6825 */  or    $t5, $t1, $t2
/* 0E2E60 7F0AE330 304E00FF */  andi  $t6, $v0, 0xff
/* 0E2E64 7F0AE334 01AEC025 */  or    $t8, $t5, $t6
/* 0E2E68 7F0AE338 AC980004 */  sw    $t8, 4($a0)
/* 0E2E6C 7F0AE33C 8FAB0064 */  lw    $t3, 0x64($sp)
/* 0E2E70 7F0AE340 26730008 */  addiu $s3, $s3, 8
/* 0E2E74 7F0AE344 2411FFFF */  li    $s1, -1
/* 0E2E78 7F0AE348 24120002 */  li    $s2, 2
/* 0E2E7C 7F0AE34C 8D630000 */  lw    $v1, ($t3)
/* 0E2E80 7F0AE350 2410FFFF */  li    $s0, -1
.L7F0AE354:
/* 0E2E84 7F0AE354 16200003 */  bnez  $s1, .L7F0AE364
/* 0E2E88 7F0AE358 00712821 */   addu  $a1, $v1, $s1
/* 0E2E8C 7F0AE35C 5200000E */  beql  $s0, $zero, .L7F0AE398
/* 0E2E90 7F0AE360 26100001 */   addiu $s0, $s0, 1
.L7F0AE364:
/* 0E2E94 7F0AE364 8FB90050 */  lw    $t9, 0x50($sp)
/* 0E2E98 7F0AE368 02602025 */  move  $a0, $s3
/* 0E2E9C 7F0AE36C 03C03825 */  move  $a3, $fp
/* 0E2EA0 7F0AE370 AFB40010 */  sw    $s4, 0x10($sp)
/* 0E2EA4 7F0AE374 AFB50014 */  sw    $s5, 0x14($sp)
/* 0E2EA8 7F0AE378 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E2EAC 7F0AE37C AFB7001C */  sw    $s7, 0x1c($sp)
/* 0E2EB0 7F0AE380 0FC2B917 */  jal   sub_GAME_7F0AE45C
/* 0E2EB4 7F0AE384 03303021 */   addu  $a2, $t9, $s0
/* 0E2EB8 7F0AE388 8FAC0064 */  lw    $t4, 0x64($sp)
/* 0E2EBC 7F0AE38C 00409825 */  move  $s3, $v0
/* 0E2EC0 7F0AE390 8D830000 */  lw    $v1, ($t4)
/* 0E2EC4 7F0AE394 26100001 */  addiu $s0, $s0, 1
.L7F0AE398:
/* 0E2EC8 7F0AE398 1612FFEE */  bne   $s0, $s2, .L7F0AE354
/* 0E2ECC 7F0AE39C 00000000 */   nop
/* 0E2ED0 7F0AE3A0 26310001 */  addiu $s1, $s1, 1
/* 0E2ED4 7F0AE3A4 5632FFEB */  bnel  $s1, $s2, .L7F0AE354
/* 0E2ED8 7F0AE3A8 2410FFFF */   li    $s0, -1
/* 0E2EDC 7F0AE3AC 8FA20080 */  lw    $v0, 0x80($sp)
/* 0E2EE0 7F0AE3B0 3C09FA00 */  lui   $t1, 0xfa00
/* 0E2EE4 7F0AE3B4 AE690000 */  sw    $t1, ($s3)
/* 0E2EE8 7F0AE3B8 00026E02 */  srl   $t5, $v0, 0x18
/* 0E2EEC 7F0AE3BC 00025C02 */  srl   $t3, $v0, 0x10
/* 0E2EF0 7F0AE3C0 317900FF */  andi  $t9, $t3, 0xff
/* 0E2EF4 7F0AE3C4 000D7600 */  sll   $t6, $t5, 0x18
/* 0E2EF8 7F0AE3C8 00196400 */  sll   $t4, $t9, 0x10
/* 0E2EFC 7F0AE3CC 00027A02 */  srl   $t7, $v0, 8
/* 0E2F00 7F0AE3D0 31ED00FF */  andi  $t5, $t7, 0xff
/* 0E2F04 7F0AE3D4 01CC4825 */  or    $t1, $t6, $t4
/* 0E2F08 7F0AE3D8 000DC200 */  sll   $t8, $t5, 8
/* 0E2F0C 7F0AE3DC 01385825 */  or    $t3, $t1, $t8
/* 0E2F10 7F0AE3E0 304E00FF */  andi  $t6, $v0, 0xff
/* 0E2F14 7F0AE3E4 016E6025 */  or    $t4, $t3, $t6
/* 0E2F18 7F0AE3E8 AE6C0004 */  sw    $t4, 4($s3)
/* 0E2F1C 7F0AE3EC 00602825 */  move  $a1, $v1
/* 0E2F20 7F0AE3F0 26640008 */  addiu $a0, $s3, 8
/* 0E2F24 7F0AE3F4 AFB7001C */  sw    $s7, 0x1c($sp)
/* 0E2F28 7F0AE3F8 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E2F2C 7F0AE3FC AFB50014 */  sw    $s5, 0x14($sp)
/* 0E2F30 7F0AE400 AFB40010 */  sw    $s4, 0x10($sp)
/* 0E2F34 7F0AE404 8FA60050 */  lw    $a2, 0x50($sp)
/* 0E2F38 7F0AE408 0FC2B917 */  jal   sub_GAME_7F0AE45C
/* 0E2F3C 7F0AE40C 03C03825 */   move  $a3, $fp
/* 0E2F40 7F0AE410 00409825 */  move  $s3, $v0
.L7F0AE414:
/* 0E2F44 7F0AE414 8FA50064 */  lw    $a1, 0x64($sp)
.L7F0AE418:
/* 0E2F48 7F0AE418 8FCF000C */  lw    $t7, 0xc($fp)
/* 0E2F4C 7F0AE41C 02601025 */  move  $v0, $s3
/* 0E2F50 7F0AE420 8CAA0000 */  lw    $t2, ($a1)
/* 0E2F54 7F0AE424 014F6821 */  addu  $t5, $t2, $t7
/* 0E2F58 7F0AE428 ACAD0000 */  sw    $t5, ($a1)
/* 0E2F5C 7F0AE42C 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0E2F60 7F0AE430 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0E2F64 7F0AE434 8FB70044 */  lw    $s7, 0x44($sp)
/* 0E2F68 7F0AE438 8FB60040 */  lw    $s6, 0x40($sp)
/* 0E2F6C 7F0AE43C 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0E2F70 7F0AE440 8FB40038 */  lw    $s4, 0x38($sp)
/* 0E2F74 7F0AE444 8FB30034 */  lw    $s3, 0x34($sp)
/* 0E2F78 7F0AE448 8FB20030 */  lw    $s2, 0x30($sp)
/* 0E2F7C 7F0AE44C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0E2F80 7F0AE450 8FB00028 */  lw    $s0, 0x28($sp)
/* 0E2F84 7F0AE454 03E00008 */  jr    $ra
/* 0E2F88 7F0AE458 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif





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




#ifdef NONMATCHING
void textRenderGlow(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel textRenderGlow
/* 0E321C 7F0AE6EC 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0E3220 7F0AE6F0 240E0001 */  li    $t6, 1
/* 0E3224 7F0AE6F4 3C018004 */  lui   $at, %hi(D_80040EA8)
/* 0E3228 7F0AE6F8 8FB800C4 */  lw    $t8, 0xc4($sp)
/* 0E322C 7F0AE6FC AFBF0064 */  sw    $ra, 0x64($sp)
/* 0E3230 7F0AE700 AFBE0060 */  sw    $fp, 0x60($sp)
/* 0E3234 7F0AE704 AFB7005C */  sw    $s7, 0x5c($sp)
/* 0E3238 7F0AE708 AFB60058 */  sw    $s6, 0x58($sp)
/* 0E323C 7F0AE70C AFB50054 */  sw    $s5, 0x54($sp)
/* 0E3240 7F0AE710 AFB40050 */  sw    $s4, 0x50($sp)
/* 0E3244 7F0AE714 AFB3004C */  sw    $s3, 0x4c($sp)
/* 0E3248 7F0AE718 AFB20048 */  sw    $s2, 0x48($sp)
/* 0E324C 7F0AE71C AFB10044 */  sw    $s1, 0x44($sp)
/* 0E3250 7F0AE720 AFB00040 */  sw    $s0, 0x40($sp)
/* 0E3254 7F0AE724 AC2E0EA8 */  sw    $t6, %lo(D_80040EA8)($at)
/* 0E3258 7F0AE728 8CCF0000 */  lw    $t7, ($a2)
/* 0E325C 7F0AE72C 8CB60000 */  lw    $s6, ($a1)
/* 0E3260 7F0AE730 00E08025 */  move  $s0, $a3
/* 0E3264 7F0AE734 00A08825 */  move  $s1, $a1
/* 0E3268 7F0AE738 00C09825 */  move  $s3, $a2
/* 0E326C 7F0AE73C 0080A825 */  move  $s5, $a0
/* 0E3270 7F0AE740 24140048 */  li    $s4, 72
/* 0E3274 7F0AE744 17000006 */  bnez  $t8, .L7F0AE760
/* 0E3278 7F0AE748 AFAF0090 */   sw    $t7, 0x90($sp)
/* 0E327C 7F0AE74C 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0E3280 7F0AE750 8F28088C */  lw    $t0, 0x88c($t9)
/* 0E3284 7F0AE754 8F290890 */  lw    $t1, 0x890($t9)
/* 0E3288 7F0AE758 01095021 */  addu  $t2, $t0, $t1
/* 0E328C 7F0AE75C AFAA00C4 */  sw    $t2, 0xc4($sp)
.L7F0AE760:
/* 0E3290 7F0AE760 3C0B8005 */  lui   $t3, %hi(j_text_trigger)
/* 0E3294 7F0AE764 8D6B84D0 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0E3298 7F0AE768 8FAC00C4 */  lw    $t4, 0xc4($sp)
/* 0E329C 7F0AE76C 27B20074 */  addiu $s2, $sp, 0x74
/* 0E32A0 7F0AE770 11600004 */  beqz  $t3, .L7F0AE784
/* 0E32A4 7F0AE774 2981000E */   slti  $at, $t4, 0xe
/* 0E32A8 7F0AE778 10200002 */  beqz  $at, .L7F0AE784
/* 0E32AC 7F0AE77C 240D000E */   li    $t5, 14
/* 0E32B0 7F0AE780 AFAD00C4 */  sw    $t5, 0xc4($sp)
.L7F0AE784:
/* 0E32B4 7F0AE784 92020000 */  lbu   $v0, ($s0)
/* 0E32B8 7F0AE788 8FBE00B0 */  lw    $fp, 0xb0($sp)
/* 0E32BC 7F0AE78C 8FB700AC */  lw    $s7, 0xac($sp)
/* 0E32C0 7F0AE790 10400071 */  beqz  $v0, .L7F0AE958
/* 0E32C4 7F0AE794 24010020 */   li    $at, 32
.L7F0AE798:
/* 0E32C8 7F0AE798 54410008 */  bnel  $v0, $at, .L7F0AE7BC
/* 0E32CC 7F0AE79C 2401000A */   li    $at, 10
/* 0E32D0 7F0AE7A0 8E2E0000 */  lw    $t6, ($s1)
/* 0E32D4 7F0AE7A4 24140048 */  li    $s4, 72
/* 0E32D8 7F0AE7A8 26100001 */  addiu $s0, $s0, 1
/* 0E32DC 7F0AE7AC 25CF0005 */  addiu $t7, $t6, 5
/* 0E32E0 7F0AE7B0 10000066 */  b     .L7F0AE94C
/* 0E32E4 7F0AE7B4 AE2F0000 */   sw    $t7, ($s1)
/* 0E32E8 7F0AE7B8 2401000A */  li    $at, 10
.L7F0AE7BC:
/* 0E32EC 7F0AE7BC 5441000A */  bnel  $v0, $at, .L7F0AE7E8
/* 0E32F0 7F0AE7C0 28410080 */   slti  $at, $v0, 0x80
/* 0E32F4 7F0AE7C4 AE360000 */  sw    $s6, ($s1)
/* 0E32F8 7F0AE7C8 8E780000 */  lw    $t8, ($s3)
/* 0E32FC 7F0AE7CC 8FB900C4 */  lw    $t9, 0xc4($sp)
/* 0E3300 7F0AE7D0 24140048 */  li    $s4, 72
/* 0E3304 7F0AE7D4 26100001 */  addiu $s0, $s0, 1
/* 0E3308 7F0AE7D8 03194021 */  addu  $t0, $t8, $t9
/* 0E330C 7F0AE7DC 1000005B */  b     .L7F0AE94C
/* 0E3310 7F0AE7E0 AE680000 */   sw    $t0, ($s3)
/* 0E3314 7F0AE7E4 28410080 */  slti  $at, $v0, 0x80
.L7F0AE7E8:
/* 0E3318 7F0AE7E8 10200021 */  beqz  $at, .L7F0AE870
/* 0E331C 7F0AE7EC 3C0E8004 */   lui   $t6, %hi(D_80040F14)
/* 0E3320 7F0AE7F0 24030018 */  li    $v1, 24
/* 0E3324 7F0AE7F4 00430019 */  multu $v0, $v1
/* 0E3328 7F0AE7F8 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 0E332C 7F0AE7FC 8FAE0090 */  lw    $t6, 0x90($sp)
/* 0E3330 7F0AE800 8FAF00B4 */  lw    $t7, 0xb4($sp)
/* 0E3334 7F0AE804 8FB800B8 */  lw    $t8, 0xb8($sp)
/* 0E3338 7F0AE808 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0E333C 7F0AE80C 8FA800C0 */  lw    $t0, 0xc0($sp)
/* 0E3340 7F0AE810 02A02025 */  move  $a0, $s5
/* 0E3344 7F0AE814 02202825 */  move  $a1, $s1
/* 0E3348 7F0AE818 02603025 */  move  $a2, $s3
/* 0E334C 7F0AE81C 00004812 */  mflo  $t1
/* 0E3350 7F0AE820 012A3821 */  addu  $a3, $t1, $t2
/* 0E3354 7F0AE824 24E7FCE8 */  addiu $a3, $a3, -0x318
/* 0E3358 7F0AE828 02830019 */  multu $s4, $v1
/* 0E335C 7F0AE82C AFB70014 */  sw    $s7, 0x14($sp)
/* 0E3360 7F0AE830 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E3364 7F0AE834 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E3368 7F0AE838 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0E336C 7F0AE83C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0E3370 7F0AE840 AFB80028 */  sw    $t8, 0x28($sp)
/* 0E3374 7F0AE844 AFB9002C */  sw    $t9, 0x2c($sp)
/* 0E3378 7F0AE848 AFA80030 */  sw    $t0, 0x30($sp)
/* 0E337C 7F0AE84C 00005812 */  mflo  $t3
/* 0E3380 7F0AE850 016A6021 */  addu  $t4, $t3, $t2
/* 0E3384 7F0AE854 258DFCE8 */  addiu $t5, $t4, -0x318
/* 0E3388 7F0AE858 0FC2B76B */  jal   sub_GAME_7F0ADDAC
/* 0E338C 7F0AE85C AFAD0010 */   sw    $t5, 0x10($sp)
/* 0E3390 7F0AE860 0040A825 */  move  $s5, $v0
/* 0E3394 7F0AE864 92140000 */  lbu   $s4, ($s0)
/* 0E3398 7F0AE868 10000038 */  b     .L7F0AE94C
/* 0E339C 7F0AE86C 26100001 */   addiu $s0, $s0, 1
.L7F0AE870:
/* 0E33A0 7F0AE870 25CE0F14 */  addiu $t6, $t6, %lo(D_80040F14)
/* 0E33A4 7F0AE874 8DC10000 */  lw    $at, ($t6)
/* 0E33A8 7F0AE878 92090001 */  lbu   $t1, 1($s0)
/* 0E33AC 7F0AE87C 304A007F */  andi  $t2, $v0, 0x7f
/* 0E33B0 7F0AE880 AE410000 */  sw    $at, ($s2)
/* 0E33B4 7F0AE884 8DD80004 */  lw    $t8, 4($t6)
/* 0E33B8 7F0AE888 000A61C0 */  sll   $t4, $t2, 7
/* 0E33BC 7F0AE88C 312B007F */  andi  $t3, $t1, 0x7f
/* 0E33C0 7F0AE890 AE580004 */  sw    $t8, 4($s2)
/* 0E33C4 7F0AE894 8DC10008 */  lw    $at, 8($t6)
/* 0E33C8 7F0AE898 016C1825 */  or    $v1, $t3, $t4
/* 0E33CC 7F0AE89C 3064FFFF */  andi  $a0, $v1, 0xffff
/* 0E33D0 7F0AE8A0 AE410008 */  sw    $at, 8($s2)
/* 0E33D4 7F0AE8A4 8DD8000C */  lw    $t8, 0xc($t6)
/* 0E33D8 7F0AE8A8 30992000 */  andi  $t9, $a0, 0x2000
/* 0E33DC 7F0AE8AC 308A1FFF */  andi  $t2, $a0, 0x1fff
/* 0E33E0 7F0AE8B0 AE58000C */  sw    $t8, 0xc($s2)
/* 0E33E4 7F0AE8B4 8DC10010 */  lw    $at, 0x10($t6)
/* 0E33E8 7F0AE8B8 2408000F */  li    $t0, 15
/* 0E33EC 7F0AE8BC 24090010 */  li    $t1, 16
/* 0E33F0 7F0AE8C0 AE410010 */  sw    $at, 0x10($s2)
/* 0E33F4 7F0AE8C4 8DD80014 */  lw    $t8, 0x14($t6)
/* 0E33F8 7F0AE8C8 294103C7 */  slti  $at, $t2, 0x3c7
/* 0E33FC 7F0AE8CC 13200003 */  beqz  $t9, .L7F0AE8DC
/* 0E3400 7F0AE8D0 AE580014 */   sw    $t8, 0x14($s2)
/* 0E3404 7F0AE8D4 AFA80080 */  sw    $t0, 0x80($sp)
/* 0E3408 7F0AE8D8 AFA9007C */  sw    $t1, 0x7c($sp)
.L7F0AE8DC:
/* 0E340C 7F0AE8DC 54200003 */  bnezl $at, .L7F0AE8EC
/* 0E3410 7F0AE8E0 248B0080 */   addiu $t3, $a0, 0x80
/* 0E3414 7F0AE8E4 24040002 */  li    $a0, 2
/* 0E3418 7F0AE8E8 248B0080 */  addiu $t3, $a0, 0x80
.L7F0AE8EC:
/* 0E341C 7F0AE8EC 0FC3068C */  jal   langGetJpnCharPixels
/* 0E3420 7F0AE8F0 AFAB0074 */   sw    $t3, 0x74($sp)
/* 0E3424 7F0AE8F4 8FAC0090 */  lw    $t4, 0x90($sp)
/* 0E3428 7F0AE8F8 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0E342C 7F0AE8FC 8FAF00B8 */  lw    $t7, 0xb8($sp)
/* 0E3430 7F0AE900 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 0E3434 7F0AE904 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0E3438 7F0AE908 AFA20088 */  sw    $v0, 0x88($sp)
/* 0E343C 7F0AE90C 02A02025 */  move  $a0, $s5
/* 0E3440 7F0AE910 02202825 */  move  $a1, $s1
/* 0E3444 7F0AE914 02603025 */  move  $a2, $s3
/* 0E3448 7F0AE918 02403825 */  move  $a3, $s2
/* 0E344C 7F0AE91C AFB20010 */  sw    $s2, 0x10($sp)
/* 0E3450 7F0AE920 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E3454 7F0AE924 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E3458 7F0AE928 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E345C 7F0AE92C AFAC001C */  sw    $t4, 0x1c($sp)
/* 0E3460 7F0AE930 AFAD0024 */  sw    $t5, 0x24($sp)
/* 0E3464 7F0AE934 AFAF0028 */  sw    $t7, 0x28($sp)
/* 0E3468 7F0AE938 AFAE002C */  sw    $t6, 0x2c($sp)
/* 0E346C 7F0AE93C 0FC2B76B */  jal   sub_GAME_7F0ADDAC
/* 0E3470 7F0AE940 AFB80030 */   sw    $t8, 0x30($sp)
/* 0E3474 7F0AE944 0040A825 */  move  $s5, $v0
/* 0E3478 7F0AE948 26100002 */  addiu $s0, $s0, 2
.L7F0AE94C:
/* 0E347C 7F0AE94C 92020000 */  lbu   $v0, ($s0)
/* 0E3480 7F0AE950 5440FF91 */  bnezl $v0, .L7F0AE798
/* 0E3484 7F0AE954 24010020 */   li    $at, 32
.L7F0AE958:
/* 0E3488 7F0AE958 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0E348C 7F0AE95C 02A01025 */  move  $v0, $s5
/* 0E3490 7F0AE960 8FB50054 */  lw    $s5, 0x54($sp)
/* 0E3494 7F0AE964 8FB00040 */  lw    $s0, 0x40($sp)
/* 0E3498 7F0AE968 8FB10044 */  lw    $s1, 0x44($sp)
/* 0E349C 7F0AE96C 8FB20048 */  lw    $s2, 0x48($sp)
/* 0E34A0 7F0AE970 8FB3004C */  lw    $s3, 0x4c($sp)
/* 0E34A4 7F0AE974 8FB40050 */  lw    $s4, 0x50($sp)
/* 0E34A8 7F0AE978 8FB60058 */  lw    $s6, 0x58($sp)
/* 0E34AC 7F0AE97C 8FB7005C */  lw    $s7, 0x5c($sp)
/* 0E34B0 7F0AE980 8FBE0060 */  lw    $fp, 0x60($sp)
/* 0E34B4 7F0AE984 03E00008 */  jr    $ra
/* 0E34B8 7F0AE988 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif
#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel textRenderGlow
/* 0E321C 7F0AE6EC 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0E3220 7F0AE6F0 240E0001 */  li    $t6, 1
/* 0E3224 7F0AE6F4 3C018004 */  lui   $at, %hi(D_80040EA8)
/* 0E3228 7F0AE6F8 8FB800C4 */  lw    $t8, 0xc4($sp)
/* 0E322C 7F0AE6FC AFBF0064 */  sw    $ra, 0x64($sp)
/* 0E3230 7F0AE700 AFBE0060 */  sw    $fp, 0x60($sp)
/* 0E3234 7F0AE704 AFB7005C */  sw    $s7, 0x5c($sp)
/* 0E3238 7F0AE708 AFB60058 */  sw    $s6, 0x58($sp)
/* 0E323C 7F0AE70C AFB50054 */  sw    $s5, 0x54($sp)
/* 0E3240 7F0AE710 AFB40050 */  sw    $s4, 0x50($sp)
/* 0E3244 7F0AE714 AFB3004C */  sw    $s3, 0x4c($sp)
/* 0E3248 7F0AE718 AFB20048 */  sw    $s2, 0x48($sp)
/* 0E324C 7F0AE71C AFB10044 */  sw    $s1, 0x44($sp)
/* 0E3250 7F0AE720 AFB00040 */  sw    $s0, 0x40($sp)
/* 0E3254 7F0AE724 AC2E0EA8 */  sw    $t6, %lo(D_80040EA8)($at)
/* 0E3258 7F0AE728 8CCF0000 */  lw    $t7, ($a2)
/* 0E325C 7F0AE72C 8CB60000 */  lw    $s6, ($a1)
/* 0E3260 7F0AE730 00E08025 */  move  $s0, $a3
/* 0E3264 7F0AE734 00A08825 */  move  $s1, $a1
/* 0E3268 7F0AE738 00C09825 */  move  $s3, $a2
/* 0E326C 7F0AE73C 0080A825 */  move  $s5, $a0
/* 0E3270 7F0AE740 24140048 */  li    $s4, 72
/* 0E3274 7F0AE744 17000006 */  bnez  $t8, .L7F0AE760
/* 0E3278 7F0AE748 AFAF0090 */   sw    $t7, 0x90($sp)
/* 0E327C 7F0AE74C 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0E3280 7F0AE750 8F28088C */  lw    $t0, 0x88c($t9)
/* 0E3284 7F0AE754 8F290890 */  lw    $t1, 0x890($t9)
/* 0E3288 7F0AE758 01095021 */  addu  $t2, $t0, $t1
/* 0E328C 7F0AE75C AFAA00C4 */  sw    $t2, 0xc4($sp)
.L7F0AE760:
/* 0E3290 7F0AE760 3C0B8005 */  lui   $t3, %hi(j_text_trigger)
/* 0E3294 7F0AE764 8D6B84D0 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0E3298 7F0AE768 8FAC00C4 */  lw    $t4, 0xc4($sp)
/* 0E329C 7F0AE76C 27B20074 */  addiu $s2, $sp, 0x74
/* 0E32A0 7F0AE770 11600004 */  beqz  $t3, .L7F0AE784
/* 0E32A4 7F0AE774 2981000E */   slti  $at, $t4, 0xe
/* 0E32A8 7F0AE778 10200002 */  beqz  $at, .L7F0AE784
/* 0E32AC 7F0AE77C 240D000E */   li    $t5, 14
/* 0E32B0 7F0AE780 AFAD00C4 */  sw    $t5, 0xc4($sp)
.L7F0AE784:
/* 0E32B4 7F0AE784 92020000 */  lbu   $v0, ($s0)
/* 0E32B8 7F0AE788 8FBE00B0 */  lw    $fp, 0xb0($sp)
/* 0E32BC 7F0AE78C 8FB700AC */  lw    $s7, 0xac($sp)
/* 0E32C0 7F0AE790 10400071 */  beqz  $v0, .L7F0AE958
/* 0E32C4 7F0AE794 24010020 */   li    $at, 32
.L7F0AE798:
/* 0E32C8 7F0AE798 54410008 */  bnel  $v0, $at, .L7F0AE7BC
/* 0E32CC 7F0AE79C 2401000A */   li    $at, 10
/* 0E32D0 7F0AE7A0 8E2E0000 */  lw    $t6, ($s1)
/* 0E32D4 7F0AE7A4 24140048 */  li    $s4, 72
/* 0E32D8 7F0AE7A8 26100001 */  addiu $s0, $s0, 1
/* 0E32DC 7F0AE7AC 25CF0005 */  addiu $t7, $t6, 5
/* 0E32E0 7F0AE7B0 10000066 */  b     .L7F0AE94C
/* 0E32E4 7F0AE7B4 AE2F0000 */   sw    $t7, ($s1)
/* 0E32E8 7F0AE7B8 2401000A */  li    $at, 10
.L7F0AE7BC:
/* 0E32EC 7F0AE7BC 5441000A */  bnel  $v0, $at, .L7F0AE7E8
/* 0E32F0 7F0AE7C0 28410080 */   slti  $at, $v0, 0x80
/* 0E32F4 7F0AE7C4 AE360000 */  sw    $s6, ($s1)
/* 0E32F8 7F0AE7C8 8E780000 */  lw    $t8, ($s3)
/* 0E32FC 7F0AE7CC 8FB900C4 */  lw    $t9, 0xc4($sp)
/* 0E3300 7F0AE7D0 24140048 */  li    $s4, 72
/* 0E3304 7F0AE7D4 26100001 */  addiu $s0, $s0, 1
/* 0E3308 7F0AE7D8 03194021 */  addu  $t0, $t8, $t9
/* 0E330C 7F0AE7DC 1000005B */  b     .L7F0AE94C
/* 0E3310 7F0AE7E0 AE680000 */   sw    $t0, ($s3)
/* 0E3314 7F0AE7E4 28410080 */  slti  $at, $v0, 0x80
.L7F0AE7E8:
/* 0E3318 7F0AE7E8 10200021 */  beqz  $at, .L7F0AE870
/* 0E331C 7F0AE7EC 3C0E8004 */   lui   $t6, %hi(D_80040F14)
/* 0E3320 7F0AE7F0 24030018 */  li    $v1, 24
/* 0E3324 7F0AE7F4 00430019 */  multu $v0, $v1
/* 0E3328 7F0AE7F8 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 0E332C 7F0AE7FC 8FAE0090 */  lw    $t6, 0x90($sp)
/* 0E3330 7F0AE800 8FAF00B4 */  lw    $t7, 0xb4($sp)
/* 0E3334 7F0AE804 8FB800B8 */  lw    $t8, 0xb8($sp)
/* 0E3338 7F0AE808 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0E333C 7F0AE80C 8FA800C0 */  lw    $t0, 0xc0($sp)
/* 0E3340 7F0AE810 02A02025 */  move  $a0, $s5
/* 0E3344 7F0AE814 02202825 */  move  $a1, $s1
/* 0E3348 7F0AE818 02603025 */  move  $a2, $s3
/* 0E334C 7F0AE81C 00004812 */  mflo  $t1
/* 0E3350 7F0AE820 012A3821 */  addu  $a3, $t1, $t2
/* 0E3354 7F0AE824 24E7FCE8 */  addiu $a3, $a3, -0x318
/* 0E3358 7F0AE828 02830019 */  multu $s4, $v1
/* 0E335C 7F0AE82C AFB70014 */  sw    $s7, 0x14($sp)
/* 0E3360 7F0AE830 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E3364 7F0AE834 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E3368 7F0AE838 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0E336C 7F0AE83C AFAF0024 */  sw    $t7, 0x24($sp)
/* 0E3370 7F0AE840 AFB80028 */  sw    $t8, 0x28($sp)
/* 0E3374 7F0AE844 AFB9002C */  sw    $t9, 0x2c($sp)
/* 0E3378 7F0AE848 AFA80030 */  sw    $t0, 0x30($sp)
/* 0E337C 7F0AE84C 00005812 */  mflo  $t3
/* 0E3380 7F0AE850 016A6021 */  addu  $t4, $t3, $t2
/* 0E3384 7F0AE854 258DFCE8 */  addiu $t5, $t4, -0x318
/* 0E3388 7F0AE858 0FC2B76B */  jal   sub_GAME_7F0ADDAC
/* 0E338C 7F0AE85C AFAD0010 */   sw    $t5, 0x10($sp)
/* 0E3390 7F0AE860 0040A825 */  move  $s5, $v0
/* 0E3394 7F0AE864 92140000 */  lbu   $s4, ($s0)
/* 0E3398 7F0AE868 10000038 */  b     .L7F0AE94C
/* 0E339C 7F0AE86C 26100001 */   addiu $s0, $s0, 1
.L7F0AE870:
/* 0E33A0 7F0AE870 25CE0F14 */  addiu $t6, $t6, %lo(D_80040F14)
/* 0E33A4 7F0AE874 8DC10000 */  lw    $at, ($t6)
/* 0E33A8 7F0AE878 92090001 */  lbu   $t1, 1($s0)
/* 0E33AC 7F0AE87C 304A007F */  andi  $t2, $v0, 0x7f
/* 0E33B0 7F0AE880 AE410000 */  sw    $at, ($s2)
/* 0E33B4 7F0AE884 8DD80004 */  lw    $t8, 4($t6)
/* 0E33B8 7F0AE888 000A61C0 */  sll   $t4, $t2, 7
/* 0E33BC 7F0AE88C 312B007F */  andi  $t3, $t1, 0x7f
/* 0E33C0 7F0AE890 AE580004 */  sw    $t8, 4($s2)
/* 0E33C4 7F0AE894 8DC10008 */  lw    $at, 8($t6)
/* 0E33C8 7F0AE898 016C1825 */  or    $v1, $t3, $t4
/* 0E33CC 7F0AE89C 3064FFFF */  andi  $a0, $v1, 0xffff
/* 0E33D0 7F0AE8A0 AE410008 */  sw    $at, 8($s2)
/* 0E33D4 7F0AE8A4 8DD8000C */  lw    $t8, 0xc($t6)
/* 0E33D8 7F0AE8A8 30992000 */  andi  $t9, $a0, 0x2000
/* 0E33DC 7F0AE8AC 308A1FFF */  andi  $t2, $a0, 0x1fff
/* 0E33E0 7F0AE8B0 AE58000C */  sw    $t8, 0xc($s2)
/* 0E33E4 7F0AE8B4 8DC10010 */  lw    $at, 0x10($t6)
/* 0E33E8 7F0AE8B8 2408000F */  li    $t0, 15
/* 0E33EC 7F0AE8BC 24090010 */  li    $t1, 16
/* 0E33F0 7F0AE8C0 AE410010 */  sw    $at, 0x10($s2)
/* 0E33F4 7F0AE8C4 8DD80014 */  lw    $t8, 0x14($t6)
/* 0E33F8 7F0AE8C8 294103C7 */  slti  $at, $t2, 0x3c8
/* 0E33FC 7F0AE8CC 13200003 */  beqz  $t9, .L7F0AE8DC
/* 0E3400 7F0AE8D0 AE580014 */   sw    $t8, 0x14($s2)
/* 0E3404 7F0AE8D4 AFA80080 */  sw    $t0, 0x80($sp)
/* 0E3408 7F0AE8D8 AFA9007C */  sw    $t1, 0x7c($sp)
.L7F0AE8DC:
/* 0E340C 7F0AE8DC 54200003 */  bnezl $at, .L7F0AE8EC
/* 0E3410 7F0AE8E0 248B0080 */   addiu $t3, $a0, 0x80
/* 0E3414 7F0AE8E4 24040002 */  li    $a0, 2
/* 0E3418 7F0AE8E8 248B0080 */  addiu $t3, $a0, 0x80
.L7F0AE8EC:
/* 0E341C 7F0AE8EC 0FC3068C */  jal   langGetJpnCharPixels
/* 0E3420 7F0AE8F0 AFAB0074 */   sw    $t3, 0x74($sp)
/* 0E3424 7F0AE8F4 8FAC0090 */  lw    $t4, 0x90($sp)
/* 0E3428 7F0AE8F8 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0E342C 7F0AE8FC 8FAF00B8 */  lw    $t7, 0xb8($sp)
/* 0E3430 7F0AE900 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 0E3434 7F0AE904 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0E3438 7F0AE908 AFA20088 */  sw    $v0, 0x88($sp)
/* 0E343C 7F0AE90C 02A02025 */  move  $a0, $s5
/* 0E3440 7F0AE910 02202825 */  move  $a1, $s1
/* 0E3444 7F0AE914 02603025 */  move  $a2, $s3
/* 0E3448 7F0AE918 02403825 */  move  $a3, $s2
/* 0E344C 7F0AE91C AFB20010 */  sw    $s2, 0x10($sp)
/* 0E3450 7F0AE920 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E3454 7F0AE924 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E3458 7F0AE928 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E345C 7F0AE92C AFAC001C */  sw    $t4, 0x1c($sp)
/* 0E3460 7F0AE930 AFAD0024 */  sw    $t5, 0x24($sp)
/* 0E3464 7F0AE934 AFAF0028 */  sw    $t7, 0x28($sp)
/* 0E3468 7F0AE938 AFAE002C */  sw    $t6, 0x2c($sp)
/* 0E346C 7F0AE93C 0FC2B76B */  jal   sub_GAME_7F0ADDAC
/* 0E3470 7F0AE940 AFB80030 */   sw    $t8, 0x30($sp)
/* 0E3474 7F0AE944 0040A825 */  move  $s5, $v0
/* 0E3478 7F0AE948 26100002 */  addiu $s0, $s0, 2
.L7F0AE94C:
/* 0E347C 7F0AE94C 92020000 */  lbu   $v0, ($s0)
/* 0E3480 7F0AE950 5440FF91 */  bnezl $v0, .L7F0AE798
/* 0E3484 7F0AE954 24010020 */   li    $at, 32
.L7F0AE958:
/* 0E3488 7F0AE958 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0E348C 7F0AE95C 02A01025 */  move  $v0, $s5
/* 0E3490 7F0AE960 8FB50054 */  lw    $s5, 0x54($sp)
/* 0E3494 7F0AE964 8FB00040 */  lw    $s0, 0x40($sp)
/* 0E3498 7F0AE968 8FB10044 */  lw    $s1, 0x44($sp)
/* 0E349C 7F0AE96C 8FB20048 */  lw    $s2, 0x48($sp)
/* 0E34A0 7F0AE970 8FB3004C */  lw    $s3, 0x4c($sp)
/* 0E34A4 7F0AE974 8FB40050 */  lw    $s4, 0x50($sp)
/* 0E34A8 7F0AE978 8FB60058 */  lw    $s6, 0x58($sp)
/* 0E34AC 7F0AE97C 8FB7005C */  lw    $s7, 0x5c($sp)
/* 0E34B0 7F0AE980 8FBE0060 */  lw    $fp, 0x60($sp)
/* 0E34B4 7F0AE984 03E00008 */  jr    $ra
/* 0E34B8 7F0AE988 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel textRenderGlow
/* 0E039C 7F0AD9AC 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0E03A0 7F0AD9B0 240E0001 */  li    $t6, 1
/* 0E03A4 7F0AD9B4 3C018004 */  lui   $at, %hi(D_80040EA8) # $at, 0x8004
/* 0E03A8 7F0AD9B8 8FB800C4 */  lw    $t8, 0xc4($sp)
/* 0E03AC 7F0AD9BC AFBF0064 */  sw    $ra, 0x64($sp)
/* 0E03B0 7F0AD9C0 AFBE0060 */  sw    $fp, 0x60($sp)
/* 0E03B4 7F0AD9C4 AFB7005C */  sw    $s7, 0x5c($sp)
/* 0E03B8 7F0AD9C8 AFB60058 */  sw    $s6, 0x58($sp)
/* 0E03BC 7F0AD9CC AFB50054 */  sw    $s5, 0x54($sp)
/* 0E03C0 7F0AD9D0 AFB40050 */  sw    $s4, 0x50($sp)
/* 0E03C4 7F0AD9D4 AFB3004C */  sw    $s3, 0x4c($sp)
/* 0E03C8 7F0AD9D8 AFB20048 */  sw    $s2, 0x48($sp)
/* 0E03CC 7F0AD9DC AFB10044 */  sw    $s1, 0x44($sp)
/* 0E03D0 7F0AD9E0 AFB00040 */  sw    $s0, 0x40($sp)
/* 0E03D4 7F0AD9E4 AC2EAAF8 */  sw    $t6, %lo(D_80040EA8)($at)
/* 0E03D8 7F0AD9E8 8CCF0000 */  lw    $t7, ($a2)
/* 0E03DC 7F0AD9EC 8CB60000 */  lw    $s6, ($a1)
/* 0E03E0 7F0AD9F0 00E08025 */  move  $s0, $a3
/* 0E03E4 7F0AD9F4 00A08825 */  move  $s1, $a1
/* 0E03E8 7F0AD9F8 00C09825 */  move  $s3, $a2
/* 0E03EC 7F0AD9FC 0080A825 */  move  $s5, $a0
/* 0E03F0 7F0ADA00 24140048 */  li    $s4, 72
/* 0E03F4 7F0ADA04 17000006 */  bnez  $t8, .L7F0ADA20
/* 0E03F8 7F0ADA08 AFAF0090 */   sw    $t7, 0x90($sp)
/* 0E03FC 7F0ADA0C 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0E0400 7F0ADA10 8F28088C */  lw    $t0, 0x88c($t9)
/* 0E0404 7F0ADA14 8F290890 */  lw    $t1, 0x890($t9)
/* 0E0408 7F0ADA18 01095021 */  addu  $t2, $t0, $t1
/* 0E040C 7F0ADA1C AFAA00C4 */  sw    $t2, 0xc4($sp)
.L7F0ADA20:
/* 0E0410 7F0ADA20 3C0B8004 */  lui   $t3, %hi(j_text_trigger) # $t3, 0x8004
/* 0E0414 7F0ADA24 8D6B1150 */  lw    $t3, %lo(j_text_trigger)($t3)
/* 0E0418 7F0ADA28 8FAC00C4 */  lw    $t4, 0xc4($sp)
/* 0E041C 7F0ADA2C 27B20074 */  addiu $s2, $sp, 0x74
/* 0E0420 7F0ADA30 11600004 */  beqz  $t3, .L7F0ADA44
/* 0E0424 7F0ADA34 2981000E */   slti  $at, $t4, 0xe
/* 0E0428 7F0ADA38 10200002 */  beqz  $at, .L7F0ADA44
/* 0E042C 7F0ADA3C 240D000E */   li    $t5, 14
/* 0E0430 7F0ADA40 AFAD00C4 */  sw    $t5, 0xc4($sp)
.L7F0ADA44:
/* 0E0434 7F0ADA44 92020000 */  lbu   $v0, ($s0)
/* 0E0438 7F0ADA48 8FBE00B0 */  lw    $fp, 0xb0($sp)
/* 0E043C 7F0ADA4C 8FB700AC */  lw    $s7, 0xac($sp)
/* 0E0440 7F0ADA50 10400071 */  beqz  $v0, .L7F0ADC18
/* 0E0444 7F0ADA54 24010020 */   li    $at, 32
.L7F0ADA58:
/* 0E0448 7F0ADA58 54410008 */  bnel  $v0, $at, .L7F0ADA7C
/* 0E044C 7F0ADA5C 2401000A */   li    $at, 10
/* 0E0450 7F0ADA60 8E2E0000 */  lw    $t6, ($s1)
/* 0E0454 7F0ADA64 24140048 */  li    $s4, 72
/* 0E0458 7F0ADA68 26100001 */  addiu $s0, $s0, 1
/* 0E045C 7F0ADA6C 25CF0005 */  addiu $t7, $t6, 5
/* 0E0460 7F0ADA70 10000066 */  b     .L7F0ADC0C
/* 0E0464 7F0ADA74 AE2F0000 */   sw    $t7, ($s1)
/* 0E0468 7F0ADA78 2401000A */  li    $at, 10
.L7F0ADA7C:
/* 0E046C 7F0ADA7C 5441000A */  bnel  $v0, $at, .L7F0ADAA8
/* 0E0470 7F0ADA80 28410080 */   slti  $at, $v0, 0x80
/* 0E0474 7F0ADA84 AE360000 */  sw    $s6, ($s1)
/* 0E0478 7F0ADA88 8E780000 */  lw    $t8, ($s3)
/* 0E047C 7F0ADA8C 8FB900C4 */  lw    $t9, 0xc4($sp)
/* 0E0480 7F0ADA90 24140048 */  li    $s4, 72
/* 0E0484 7F0ADA94 26100001 */  addiu $s0, $s0, 1
/* 0E0488 7F0ADA98 03194021 */  addu  $t0, $t8, $t9
/* 0E048C 7F0ADA9C 1000005B */  b     .L7F0ADC0C
/* 0E0490 7F0ADAA0 AE680000 */   sw    $t0, ($s3)
/* 0E0494 7F0ADAA4 28410080 */  slti  $at, $v0, 0x80
.L7F0ADAA8:
/* 0E0498 7F0ADAA8 10200021 */  beqz  $at, .L7F0ADB30
/* 0E049C 7F0ADAAC 3C0E8004 */   lui   $t6, %hi(D_80040F14)
/* 0E04A0 7F0ADAB0 24030018 */  li    $v1, 24
/* 0E04A4 7F0ADAB4 00430019 */  multu $v0, $v1
/* 0E04A8 7F0ADAB8 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 0E04AC 7F0ADABC 8FAE0090 */  lw    $t6, 0x90($sp)
/* 0E04B0 7F0ADAC0 8FAF00B4 */  lw    $t7, 0xb4($sp)
/* 0E04B4 7F0ADAC4 8FB800B8 */  lw    $t8, 0xb8($sp)
/* 0E04B8 7F0ADAC8 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0E04BC 7F0ADACC 8FA800C0 */  lw    $t0, 0xc0($sp)
/* 0E04C0 7F0ADAD0 02A02025 */  move  $a0, $s5
/* 0E04C4 7F0ADAD4 02202825 */  move  $a1, $s1
/* 0E04C8 7F0ADAD8 02603025 */  move  $a2, $s3
/* 0E04CC 7F0ADADC 00004812 */  mflo  $t1
/* 0E04D0 7F0ADAE0 012A3821 */  addu  $a3, $t1, $t2
/* 0E04D4 7F0ADAE4 24E7FCE8 */  addiu $a3, $a3, -0x318
/* 0E04D8 7F0ADAE8 02830019 */  multu $s4, $v1
/* 0E04DC 7F0ADAEC AFB70014 */  sw    $s7, 0x14($sp)
/* 0E04E0 7F0ADAF0 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E04E4 7F0ADAF4 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E04E8 7F0ADAF8 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0E04EC 7F0ADAFC AFAF0024 */  sw    $t7, 0x24($sp)
/* 0E04F0 7F0ADB00 AFB80028 */  sw    $t8, 0x28($sp)
/* 0E04F4 7F0ADB04 AFB9002C */  sw    $t9, 0x2c($sp)
/* 0E04F8 7F0ADB08 AFA80030 */  sw    $t0, 0x30($sp)
/* 0E04FC 7F0ADB0C 00005812 */  mflo  $t3
/* 0E0500 7F0ADB10 016A6021 */  addu  $t4, $t3, $t2
/* 0E0504 7F0ADB14 258DFCE8 */  addiu $t5, $t4, -0x318
/* 0E0508 7F0ADB18 0FC2B41B */  jal   sub_GAME_7F0ADDAC
/* 0E050C 7F0ADB1C AFAD0010 */   sw    $t5, 0x10($sp)
/* 0E0510 7F0ADB20 0040A825 */  move  $s5, $v0
/* 0E0514 7F0ADB24 92140000 */  lbu   $s4, ($s0)
/* 0E0518 7F0ADB28 10000038 */  b     .L7F0ADC0C
/* 0E051C 7F0ADB2C 26100001 */   addiu $s0, $s0, 1
.L7F0ADB30:
/* 0E0520 7F0ADB30 25CEAB64 */  addiu $t6, $t6, %lo(D_80040F14)
/* 0E0524 7F0ADB34 8DC10000 */  lw    $at, ($t6)
/* 0E0528 7F0ADB38 92090001 */  lbu   $t1, 1($s0)
/* 0E052C 7F0ADB3C 304A007F */  andi  $t2, $v0, 0x7f
/* 0E0530 7F0ADB40 AE410000 */  sw    $at, ($s2)
/* 0E0534 7F0ADB44 8DD80004 */  lw    $t8, 4($t6)
/* 0E0538 7F0ADB48 000A61C0 */  sll   $t4, $t2, 7
/* 0E053C 7F0ADB4C 312B007F */  andi  $t3, $t1, 0x7f
/* 0E0540 7F0ADB50 AE580004 */  sw    $t8, 4($s2)
/* 0E0544 7F0ADB54 8DC10008 */  lw    $at, 8($t6)
/* 0E0548 7F0ADB58 016C1825 */  or    $v1, $t3, $t4
/* 0E054C 7F0ADB5C 3064FFFF */  andi  $a0, $v1, 0xffff
/* 0E0550 7F0ADB60 AE410008 */  sw    $at, 8($s2)
/* 0E0554 7F0ADB64 8DD8000C */  lw    $t8, 0xc($t6)
/* 0E0558 7F0ADB68 30992000 */  andi  $t9, $a0, 0x2000
/* 0E055C 7F0ADB6C 308A1FFF */  andi  $t2, $a0, 0x1fff
/* 0E0560 7F0ADB70 AE58000C */  sw    $t8, 0xc($s2)
/* 0E0564 7F0ADB74 8DC10010 */  lw    $at, 0x10($t6)
/* 0E0568 7F0ADB78 2408000F */  li    $t0, 15
/* 0E056C 7F0ADB7C 24090010 */  li    $t1, 16
/* 0E0570 7F0ADB80 AE410010 */  sw    $at, 0x10($s2)
/* 0E0574 7F0ADB84 8DD80014 */  lw    $t8, 0x14($t6)
/* 0E0578 7F0ADB88 294103C8 */  slti  $at, $t2, 0x3c8
/* 0E057C 7F0ADB8C 13200003 */  beqz  $t9, .L7F0ADB9C
/* 0E0580 7F0ADB90 AE580014 */   sw    $t8, 0x14($s2)
/* 0E0584 7F0ADB94 AFA80080 */  sw    $t0, 0x80($sp)
/* 0E0588 7F0ADB98 AFA9007C */  sw    $t1, 0x7c($sp)
.L7F0ADB9C:
/* 0E058C 7F0ADB9C 54200003 */  bnezl $at, .L7F0ADBAC
/* 0E0590 7F0ADBA0 248B0080 */   addiu $t3, $a0, 0x80
/* 0E0594 7F0ADBA4 24040002 */  li    $a0, 2
/* 0E0598 7F0ADBA8 248B0080 */  addiu $t3, $a0, 0x80
.L7F0ADBAC:
/* 0E059C 7F0ADBAC 0FC303C4 */  jal   langGetJpnCharPixels
/* 0E05A0 7F0ADBB0 AFAB0074 */   sw    $t3, 0x74($sp)
/* 0E05A4 7F0ADBB4 8FAC0090 */  lw    $t4, 0x90($sp)
/* 0E05A8 7F0ADBB8 8FAD00B4 */  lw    $t5, 0xb4($sp)
/* 0E05AC 7F0ADBBC 8FAF00B8 */  lw    $t7, 0xb8($sp)
/* 0E05B0 7F0ADBC0 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 0E05B4 7F0ADBC4 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0E05B8 7F0ADBC8 AFA20088 */  sw    $v0, 0x88($sp)
/* 0E05BC 7F0ADBCC 02A02025 */  move  $a0, $s5
/* 0E05C0 7F0ADBD0 02202825 */  move  $a1, $s1
/* 0E05C4 7F0ADBD4 02603025 */  move  $a2, $s3
/* 0E05C8 7F0ADBD8 02403825 */  move  $a3, $s2
/* 0E05CC 7F0ADBDC AFB20010 */  sw    $s2, 0x10($sp)
/* 0E05D0 7F0ADBE0 AFB70014 */  sw    $s7, 0x14($sp)
/* 0E05D4 7F0ADBE4 AFB60018 */  sw    $s6, 0x18($sp)
/* 0E05D8 7F0ADBE8 AFBE0020 */  sw    $fp, 0x20($sp)
/* 0E05DC 7F0ADBEC AFAC001C */  sw    $t4, 0x1c($sp)
/* 0E05E0 7F0ADBF0 AFAD0024 */  sw    $t5, 0x24($sp)
/* 0E05E4 7F0ADBF4 AFAF0028 */  sw    $t7, 0x28($sp)
/* 0E05E8 7F0ADBF8 AFAE002C */  sw    $t6, 0x2c($sp)
/* 0E05EC 7F0ADBFC 0FC2B41B */  jal   sub_GAME_7F0ADDAC
/* 0E05F0 7F0ADC00 AFB80030 */   sw    $t8, 0x30($sp)
/* 0E05F4 7F0ADC04 0040A825 */  move  $s5, $v0
/* 0E05F8 7F0ADC08 26100002 */  addiu $s0, $s0, 2
.L7F0ADC0C:
/* 0E05FC 7F0ADC0C 92020000 */  lbu   $v0, ($s0)
/* 0E0600 7F0ADC10 5440FF91 */  bnezl $v0, .L7F0ADA58
/* 0E0604 7F0ADC14 24010020 */   li    $at, 32
.L7F0ADC18:
/* 0E0608 7F0ADC18 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0E060C 7F0ADC1C 02A01025 */  move  $v0, $s5
/* 0E0610 7F0ADC20 8FB50054 */  lw    $s5, 0x54($sp)
/* 0E0614 7F0ADC24 8FB00040 */  lw    $s0, 0x40($sp)
/* 0E0618 7F0ADC28 8FB10044 */  lw    $s1, 0x44($sp)
/* 0E061C 7F0ADC2C 8FB20048 */  lw    $s2, 0x48($sp)
/* 0E0620 7F0ADC30 8FB3004C */  lw    $s3, 0x4c($sp)
/* 0E0624 7F0ADC34 8FB40050 */  lw    $s4, 0x50($sp)
/* 0E0628 7F0ADC38 8FB60058 */  lw    $s6, 0x58($sp)
/* 0E062C 7F0ADC3C 8FB7005C */  lw    $s7, 0x5c($sp)
/* 0E0630 7F0ADC40 8FBE0060 */  lw    $fp, 0x60($sp)
/* 0E0634 7F0ADC44 03E00008 */  jr    $ra
/* 0E0638 7F0ADC48 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif

#endif




#ifdef NONMATCHING
void textMeasure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight)
{
	unsigned char prevchar;
	unsigned char thischar;
	s32 longest;
	s32 tmp;

	prevchar = 'H';
	thischar = '\0';
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

	if (text)
    {
		while (*text != '\0')
        {
			if (*text == ' ')
            {
				// Space
				if (text[1] != '\n') {
					*textwidth += 5;
				}

				prevchar = 'H';
				text++;
			} else if (*text == '\n') {
				// Line break

				if (*textwidth > longest) {
					longest = *textwidth;
				}

				*textwidth = 0;
				*textheight += lineheight;
				text++;
			} else if (*text < 0x80)
            {
					// Normal single-byte character
					thischar = *text;
					tmp = font2->kerning[font1[prevchar - 0x21].kerningindex * 13 + font1[thischar - 0x21].kerningindex] + text_spacing - 1;
					*textwidth = font1[thischar - 0x21].width + *textwidth - tmp;

					prevchar = *text;
					text++;
            }
            else if ((s32) text < 0xC0)
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
    }
    if (*textwidth < longest)
    {
        *textwidth = longest;
    }
}
#else
GLOBAL_ASM(
.text
glabel textMeasure
/* 0E34BC 7F0AE98C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E34C0 7F0AE990 AFB00008 */  sw    $s0, 8($sp)
/* 0E34C4 7F0AE994 8FB0002C */  lw    $s0, 0x2c($sp)
/* 0E34C8 7F0AE998 AFB30014 */  sw    $s3, 0x14($sp)
/* 0E34CC 7F0AE99C AFB20010 */  sw    $s2, 0x10($sp)
/* 0E34D0 7F0AE9A0 AFB1000C */  sw    $s1, 0xc($sp)
/* 0E34D4 7F0AE9A4 AC800000 */  sw    $zero, ($a0)
/* 0E34D8 7F0AE9A8 24020048 */  li    $v0, 72
/* 0E34DC 7F0AE9AC 00004025 */  move  $t0, $zero
/* 0E34E0 7F0AE9B0 16000004 */  bnez  $s0, .L7F0AE9C4
/* 0E34E4 7F0AE9B4 ACA00000 */   sw    $zero, ($a1)
/* 0E34E8 7F0AE9B8 8CEE0890 */  lw    $t6, 0x890($a3)
/* 0E34EC 7F0AE9BC 8CEF088C */  lw    $t7, 0x88c($a3)
/* 0E34F0 7F0AE9C0 01CF8021 */  addu  $s0, $t6, $t7
.L7F0AE9C4:
/* 0E34F4 7F0AE9C4 3C188005 */  lui   $t8, %hi(j_text_trigger)
/* 0E34F8 7F0AE9C8 8F1884D0 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0E34FC 7F0AE9CC 3C138004 */  lui   $s3, %hi(text_spacing)
/* 0E3500 7F0AE9D0 2A01000E */  slti  $at, $s0, 0xe
/* 0E3504 7F0AE9D4 13000004 */  beqz  $t8, .L7F0AE9E8
/* 0E3508 7F0AE9D8 26730E84 */   addiu $s3, %lo(text_spacing) # addiu $s3, $s3, 0xe84
/* 0E350C 7F0AE9DC 50200003 */  beql  $at, $zero, .L7F0AE9EC
/* 0E3510 7F0AE9E0 90C90000 */   lbu   $t1, ($a2)
/* 0E3514 7F0AE9E4 2410000E */  li    $s0, 14
.L7F0AE9E8:
/* 0E3518 7F0AE9E8 90C90000 */  lbu   $t1, ($a2)
.L7F0AE9EC:
/* 0E351C 7F0AE9EC 2412000D */  li    $s2, 13
/* 0E3520 7F0AE9F0 24110018 */  li    $s1, 24
/* 0E3524 7F0AE9F4 11200050 */  beqz  $t1, .L7F0AEB38
/* 0E3528 7F0AE9F8 240D000A */   li    $t5, 10
/* 0E352C 7F0AE9FC 240C0020 */  li    $t4, 32
/* 0E3530 7F0AEA00 8FAA0028 */  lw    $t2, 0x28($sp)
.L7F0AEA04:
/* 0E3534 7F0AEA04 1589000A */  bne   $t4, $t1, .L7F0AEA30
/* 0E3538 7F0AEA08 00000000 */   nop
/* 0E353C 7F0AEA0C 90D90001 */  lbu   $t9, 1($a2)
/* 0E3540 7F0AEA10 24020048 */  li    $v0, 72
/* 0E3544 7F0AEA14 11B90004 */  beq   $t5, $t9, .L7F0AEA28
/* 0E3548 7F0AEA18 00000000 */   nop
/* 0E354C 7F0AEA1C 8CAE0000 */  lw    $t6, ($a1)
/* 0E3550 7F0AEA20 25CF0005 */  addiu $t7, $t6, 5
/* 0E3554 7F0AEA24 ACAF0000 */  sw    $t7, ($a1)
.L7F0AEA28:
/* 0E3558 7F0AEA28 10000040 */  b     .L7F0AEB2C
/* 0E355C 7F0AEA2C 24C60001 */   addiu $a2, $a2, 1
.L7F0AEA30:
/* 0E3560 7F0AEA30 15A9000C */  bne   $t5, $t1, .L7F0AEA64
/* 0E3564 7F0AEA34 29210080 */   slti  $at, $t1, 0x80
/* 0E3568 7F0AEA38 8CA30000 */  lw    $v1, ($a1)
/* 0E356C 7F0AEA3C 0103082A */  slt   $at, $t0, $v1
/* 0E3570 7F0AEA40 50200003 */  beql  $at, $zero, .L7F0AEA50
/* 0E3574 7F0AEA44 ACA00000 */   sw    $zero, ($a1)
/* 0E3578 7F0AEA48 00604025 */  move  $t0, $v1
/* 0E357C 7F0AEA4C ACA00000 */  sw    $zero, ($a1)
.L7F0AEA50:
/* 0E3580 7F0AEA50 8C980000 */  lw    $t8, ($a0)
/* 0E3584 7F0AEA54 24C60001 */  addiu $a2, $a2, 1
/* 0E3588 7F0AEA58 0310C821 */  addu  $t9, $t8, $s0
/* 0E358C 7F0AEA5C 10000033 */  b     .L7F0AEB2C
/* 0E3590 7F0AEA60 AC990000 */   sw    $t9, ($a0)
.L7F0AEA64:
/* 0E3594 7F0AEA64 5020001C */  beql  $at, $zero, .L7F0AEAD8
/* 0E3598 7F0AEA68 292100C0 */   slti  $at, $t1, 0xc0
/* 0E359C 7F0AEA6C 01310019 */  multu $t1, $s1
/* 0E35A0 7F0AEA70 24C60001 */  addiu $a2, $a2, 1
/* 0E35A4 7F0AEA74 00007012 */  mflo  $t6
/* 0E35A8 7F0AEA78 00EE5821 */  addu  $t3, $a3, $t6
/* 0E35AC 7F0AEA7C 8D6FFCF8 */  lw    $t7, -0x308($t3)
/* 0E35B0 7F0AEA80 00510019 */  multu $v0, $s1
/* 0E35B4 7F0AEA84 000FC080 */  sll   $t8, $t7, 2
/* 0E35B8 7F0AEA88 0158C821 */  addu  $t9, $t2, $t8
/* 0E35BC 7F0AEA8C 00007012 */  mflo  $t6
/* 0E35C0 7F0AEA90 00EE7821 */  addu  $t7, $a3, $t6
/* 0E35C4 7F0AEA94 8DF8FCF8 */  lw    $t8, -0x308($t7)
/* 0E35C8 7F0AEA98 03120019 */  multu $t8, $s2
/* 0E35CC 7F0AEA9C 00007012 */  mflo  $t6
/* 0E35D0 7F0AEAA0 000E7880 */  sll   $t7, $t6, 2
/* 0E35D4 7F0AEAA4 032FC021 */  addu  $t8, $t9, $t7
/* 0E35D8 7F0AEAA8 8F0E0000 */  lw    $t6, ($t8)
/* 0E35DC 7F0AEAAC 8E790000 */  lw    $t9, ($s3)
/* 0E35E0 7F0AEAB0 8D78FCF4 */  lw    $t8, -0x30c($t3)
/* 0E35E4 7F0AEAB4 8CAF0000 */  lw    $t7, ($a1)
/* 0E35E8 7F0AEAB8 01D91821 */  addu  $v1, $t6, $t9
/* 0E35EC 7F0AEABC 2463FFFF */  addiu $v1, $v1, -1
/* 0E35F0 7F0AEAC0 01F87021 */  addu  $t6, $t7, $t8
/* 0E35F4 7F0AEAC4 01C3C823 */  subu  $t9, $t6, $v1
/* 0E35F8 7F0AEAC8 ACB90000 */  sw    $t9, ($a1)
/* 0E35FC 7F0AEACC 10000017 */  b     .L7F0AEB2C
/* 0E3600 7F0AEAD0 90C2FFFF */   lbu   $v0, -1($a2)
/* 0E3604 7F0AEAD4 292100C0 */  slti  $at, $t1, 0xc0
.L7F0AEAD8:
/* 0E3608 7F0AEAD8 5020000C */  beql  $at, $zero, .L7F0AEB0C
/* 0E360C 7F0AEADC 8D580000 */   lw    $t8, ($t2)
/* 0E3610 7F0AEAE0 8D4F0000 */  lw    $t7, ($t2)
/* 0E3614 7F0AEAE4 8E780000 */  lw    $t8, ($s3)
/* 0E3618 7F0AEAE8 8CAE0000 */  lw    $t6, ($a1)
/* 0E361C 7F0AEAEC 24C60002 */  addiu $a2, $a2, 2
/* 0E3620 7F0AEAF0 01F81821 */  addu  $v1, $t7, $t8
/* 0E3624 7F0AEAF4 2463FFFF */  addiu $v1, $v1, -1
/* 0E3628 7F0AEAF8 01C3C823 */  subu  $t9, $t6, $v1
/* 0E362C 7F0AEAFC 272F000B */  addiu $t7, $t9, 0xb
/* 0E3630 7F0AEB00 1000000A */  b     .L7F0AEB2C
/* 0E3634 7F0AEB04 ACAF0000 */   sw    $t7, ($a1)
/* 0E3638 7F0AEB08 8D580000 */  lw    $t8, ($t2)
.L7F0AEB0C:
/* 0E363C 7F0AEB0C 8E6E0000 */  lw    $t6, ($s3)
/* 0E3640 7F0AEB10 8CB90000 */  lw    $t9, ($a1)
/* 0E3644 7F0AEB14 24C60002 */  addiu $a2, $a2, 2
/* 0E3648 7F0AEB18 030E1821 */  addu  $v1, $t8, $t6
/* 0E364C 7F0AEB1C 2463FFFF */  addiu $v1, $v1, -1
/* 0E3650 7F0AEB20 03237823 */  subu  $t7, $t9, $v1
/* 0E3654 7F0AEB24 25F8000F */  addiu $t8, $t7, 0xf
/* 0E3658 7F0AEB28 ACB80000 */  sw    $t8, ($a1)
.L7F0AEB2C:
/* 0E365C 7F0AEB2C 90C90000 */  lbu   $t1, ($a2)
/* 0E3660 7F0AEB30 1520FFB4 */  bnez  $t1, .L7F0AEA04
/* 0E3664 7F0AEB34 00000000 */   nop
.L7F0AEB38:
/* 0E3668 7F0AEB38 8CAE0000 */  lw    $t6, ($a1)
/* 0E366C 7F0AEB3C 01C8082A */  slt   $at, $t6, $t0
/* 0E3670 7F0AEB40 50200003 */  beql  $at, $zero, .L7F0AEB50
/* 0E3674 7F0AEB44 8FB00008 */   lw    $s0, 8($sp)
/* 0E3678 7F0AEB48 ACA80000 */  sw    $t0, ($a1)
/* 0E367C 7F0AEB4C 8FB00008 */  lw    $s0, 8($sp)
.L7F0AEB50:
/* 0E3680 7F0AEB50 8FB1000C */  lw    $s1, 0xc($sp)
/* 0E3684 7F0AEB54 8FB20010 */  lw    $s2, 0x10($sp)
/* 0E3688 7F0AEB58 8FB30014 */  lw    $s3, 0x14($sp)
/* 0E368C 7F0AEB5C 03E00008 */  jr    $ra
/* 0E3690 7F0AEB60 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif




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


