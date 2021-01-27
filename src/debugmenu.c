#include "ultra64.h"
#include "debugmenu.h"
#include "vi.h"
#include "game/dyn.h"

u32 image_resource[] = {  
         0,  0x227A00,  0x7A348B,  0x223434,  0x115811,  0x696900,         0,    0x9C00,
    0x4600,  0x460000,    0x4600,         0,         0,         0,         0,      0x46,
  0x229C11,  0x346900,  0x229C11,  0x699C11,    0x5834,  0xADAD34,  0x118B34,  0x9CAD7A,
  0x229C11,  0x229C11,         0,         0,         0,         0,         0,  0x113411,
         0,  0x46CE00,  0xAD58DE,  0x466969,  0x9C9C69,  0x8B8B00,  0x469C00,  0x22CE00,
  0x583400,  0x345800,  0x7ACE69,    0x5800,         0,         0,         0,    0x3446,
  0x8B007A,  0x588B00,  0x8B008B,  0x22007A,  0x119C69,  0x8B0000,  0x9C1100,  0x22008B,
  0x8B007A,  0x8B007A,         0,         0,  0x225869,         0,0x69582200,  0x9C698B,
         0,  0x46CE00,  0x222258,  0xDEEF7A,  0xAD1111,  0x69EF9C,  0x8B0000,  0x460000,
  0x8B0000,    0x8B00,  0x58CE34,    0x8B00,         0,         0,         0,    0x8B00,
  0x8B008B,    0x8B00,  0x11007A,  0x118B46,  0x58467A,  0xCEAD22,  0x9C8B00,    0x117A,
  0x698B46,  0x8B00AD,  0x34AD00,  0x34AD00,0x228B4600,0x8B8B8B8B,  0x468B22,  0x11008B,
         0,    0x7A00,         0,  0x9C9C00,  0x118B34,0x22ADBD46,  0x8B8B34,         0,
  0x8B0000,    0x8B00,  0x7A2269,0x22ADEF9C,         0,0x22ADADAD,         0,  0x226900,
  0x8B008B,    0x8B00,    0x7A00,    0x117A,  0x9C347A,      0x8B,  0xCE117A,    0x2269,
  0x8B227A,  0x229C8B,    0x1100,    0x1100,0xAD580000,0x34343434,    0x58AD,    0xBD34,
         0,  0x112200,         0,0x22DEDE22,  0xCE5858,  0x46468B,  0x8BAD00,         0,
  0x8B0000,    0x8B00,         0,    0x8B00,    0x3400,         0,    0x2200,  0x691100,
  0x8B008B,    0x8B00,  0x691158,  0x11008B,  0x7A9CAD,0x1122008B,  0x8B008B,    0x8B00,
  0x8B008B,    0x227A,    0x2200,    0x2200,0x228B4600,0x8B8B8B8B,  0x468B22,    0x6900,
         0,  0x228B00,         0,  0x8B8B00,  0x34BD00,  0x119C46,  0x7A6969,         0,
  0x583400,  0x345800,         0,    0x5800,  0x11FF00,         0,  0x228B00,  0x8B0000,
  0x349C22,  0x8BCE69,0x22BDAD8B,  0x7A9C11,    0x8B8B,0x118B9C11,  0x349C22,    0x5800,
  0x349C11,  0x588B11,  0x228B00,  0x69AD00,  0x225869,         0,0x69582200,    0xBD00,
         0,         0,         0,  0x464600,    0x4600,         0,         0,         0,
    0x4600,  0x460000,         0,         0,  0x583400,         0,         0,0x58340000,
         0,         0,         0,         0,         0,         0,         0,         0,
         0,         0,         0,  0x8B0000,         0,         0,         0,         0,
  0x229C11,  0x221100,0x11223400,    0x3411,0x11342200,  0x343422,  0x343422,    0x2222,
  0x220022,  0x342222,    0x3434,  0x341122,0x22341100,0x11110022,0x22221134,    0x2200,
  0x343411,    0x3400,  0x343411,  0x113411,  0x343434,0x11341134,0x11220034,0x34220034,
0x11340022,0x11220034,  0x223422,    0x8B34,  0x460000,  0x587A00,    0x5800,         0,
0x348B008B,  0x69BD00,0x11DE7A58,  0xAD69DE,0x22CE7A9C,0x11CE7AAD,0x11CE7AAD,  0xAD7ADE,
0x22CE00CE,  0x69CE58,    0x8BCE,0x22CE22CE,0x46CE4600,0x7ABD00FF,0x58FF46CE,  0xAD7A9C,
0x11CE7A7A,  0xAD7A8B,0x22CE7A7A,0x118B7ABD,0x469CCECE,0x8B8B34CE,0x8B8B00BD,0xBD8B22BD,
0x58CE00CE,0x22BD00CE,  0xBD7AAD,    0x8B00,  0x7A1100,    0x8B00,  0x694658,         0,
0x468B7ABD,  0x588B22,  0x8B008B,0x46460011,  0x8B007A,0x118B3458,  0x8B3458,0x46460011,
  0x8B008B,    0x8B00,    0x117A,  0x8B7A11,  0x8B0000,0x589C58BD,0x11AD698B,0x4646007A,
0x118B007A,0x5846007A,0x118B007A,0x46580011,0x34228B46,0x6934008B,  0x7A008B,0x58348B7A,
0x11696946,  0x695846,  0x113458,    0x8B00,  0x116900,    0x8B00,  0x110011,         0,
0x468B8B9C,  0x9C228B,  0xDEAD7A,0x58340000,  0x8B007A,0x11DEAD00,  0xDEAD00,0x583400AD,
0x46DEADBD,    0x8B00,0x3411117A,  0xDEAD00,  0x8B0000,0x5846AD7A,0x118B8B8B,0x5834007A,
0x11DEAD34,0x5834007A,0x11DEDE46,  0x58AD34,    0x8B00,0x5834008B,  0x8B117A,  0xBDDE8B,
  0x22AD00,  0x11BD00,  0x226900,    0x8B00,    0x8B00,    0x8B00,         0,         0,
0x348B348B,0x469C8BAD,  0x8B007A,0x347A0058,  0x8B009C,  0x8B008B,  0x8B0000,0x228B007A,
  0x8B008B,    0x8B00,0x46462269,  0x8B117A,  0x8B007A,0x6934347A,0x118B34DE,0x118B009C,
  0x8B0000,0x228B009C,  0x8B117A,0x3434008B,    0x8B00,0x4646008B,  0x22CE00,  0xADBD8B,
  0x8B007A,    0x8B00,  0x8B0058,    0x8B00,    0x3446,    0x8B00,         0,         0,
  0x697A9C,0x7A9C00BD,0x69CEAD58,  0x58AD58,0x22BDAD34,0x22CEAD8B,0x22BD2200,  0x58AD58,
0x22AD00CE,  0x8BBD7A,  0x7A7A00,0x22BD228B,0x69BDADBD,0x8B9C00BD,0x69CE227A,  0x58AD34,
0x22CE6900,  0x9CEF69,0x22BD2258,0x7A9C9C22,  0x46CE34,  0x7AAD11,    0x5800,  0x580058,
0x22AD00CE,  0x58BD34,  0xAD9C9C,    0x8B00,      0x8B,    0x8B00,         0,0x22222222,
    0x2211,         0,         0,         0,         0,         0,         0,         0,
         0,         0,         0,         0,         0,         0,         0,         0,
         0,  0x58588B,         0,         0,         0,         0,         0,         0,
         0,         0,         0,    0xCE34,      0x7A,0x1158AD00,         0,0x7A7A7A7A,
  0x693400,         0,0x22690000,         0,      0x8B,         0,    0x589C,0x11000000,
0x22690000,    0x1100,    0x1100,0x22690000,  0x8B7A00,         0,         0,         0,
         0,         0,         0,         0,         0,         0,         0,         0,
         0,         0,         0,    0x4646,    0x4600,  0x464600,         0,         0,
  0x46AD00,         0,  0x8B0000,         0,      0x8B,         0,  0x116900,         0,
  0x8B0000,    0x6900,    0x6900,  0x8B0000,    0x8B00,         0,         0,         0,
         0,         0,         0,         0,  0x226900,         0,         0,         0,
         0,         0,         0,    0x8B00,    0x8B00,    0x8B00,         0,         0,
    0x5800,  0x8B9C34,  0xCEAD69,  0x7AAD9C,  0x8BADBD,  0x7AAD34,  0x9CDE7A,  0x8B9CCE,
0x11CEAD69,  0x589C00,  0x8BAD69,  0x8BAD69,    0x8B00,0x7AAD9C9C,0x22CEAD69,  0x7AAD34,
0x22CEAD69,  0x8B9CDE,0x22DE9C69,  0x7AAD9C,  0x9CDE7A,0x118B00AD,0x11CE00DE,0x34CE00DE,
0x22CE34AD,0x22CE00DE,  0xBD9CAD,    0x8B00,    0x8B00,    0x8B00,0x229C347A,         0,
         0,  0x9CAD7A,  0x8B007A,0x69340034,0x4634009C,0x46CE9CBD,  0x226900,0x4646008B,
  0x8B008B,    0x8B00,      0x7A,  0xDE7A00,    0x8B00,0x46468B69,0x119C008B,0x4646008B,
  0x8B0069,0x5846008B,  0x8B0000,  0x8B7A58,  0x226900,  0x8B008B,  0x7A117A,  0x8B8B8B,
  0x58BD00,  0x8B008B,  0x464646,  0x467A00,    0x8B00,    0x8B46,0x7A349C22,         0,
         0,0x4634227A,  0x9C007A,0x58460022,0x4646009C,0x34460034,  0x226900,0x3446009C,
  0x8B008B,    0x8B00,      0x7A,  0x8B6911,    0x8B00,0x46468B69,0x118B008B,0x3458008B,
  0xAD0069,0x584600AD,  0x8B0000,  0x69348B,  0x226911,  0x8B009C,  0x11DE00,  0xADBD8B,
  0x699C11,  0x469C34,  0x225858,    0x8B00,    0x8B00,    0x8B00,         0,         0,
         0,0x119C8BCE,0x22ADAD58,  0x7A9C46,  0x69ADAD,0x1169AD46,  0x8BBD7A,  0x69ADAD,
0x22AD00BD,0x118BCE69,      0x7A,0x227A34CE,  0x8BBD7A,0x7A699C46,0x69BD00CE,  0x7A9C22,
  0xBD9C58,  0x69ADAD,0x22CE9C34,  0x8BAD58,    0x9C8B,  0x699CAD,0x11005800,  0x580069,
0x11BD349C,    0x9C00,  0xADAD9C,    0x8B00,    0x8B00,    0x8B00,         0,         0,
         0,         0,         0,         0,         0,         0,         0,      0x8B,
         0,         0,    0x4646,         0,         0,         0,         0,         0,
  0x8B0000,      0x8B,         0,         0,         0,         0,         0,         0,
         0,  0x226900,         0,    0x8B46,    0x8B00,  0x467A00,         0,         0 
};

s32 debug_menu_x_pos_offset = 5;
s32 debug_menu_y_pos_offset = 1;
s32 debug_menu_x_text_pos = 0x18;
s32 debug_menu_y_text_pos = 0x10;

Gfx stdout_display_list[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetColorDither(G_CD_DISABLE),
    0xB900031D,0x500A4240, //gsDPSetRenderMode(G_RM_VISCVG, G_RM_VISCVG2), //(CLR_MEM A_IN CLR_IN 1.0 CLR_MEM A_IN CLR_IN 1.0) FULL OPA AA=0 Z_CMP=0 Z_UPD=0 IM_RD=1 CLR_ON_CVG=0 CVG_X_ALPHA=0 ALPHA_CVG_SEL=0 FORCE_BL=1
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,  PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,  PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,  PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetAlphaCompare( G_AC_NONE),
    gsDPSetTextureImage(G_IM_FMT_IA,  G_IM_SIZ_16b, 1, &image_resource),
    gsDPSetTile(G_IM_FMT_IA,  G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPLoadSync(),
    gsDPLoadBlock(7, 0, 0, 1343, 128),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 16, 0, 0, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0),
    gsDPSetTileSize(0, 0, 0, 508, 80),
    gsDPLoadSync(),
    gsSPEndDisplayList(),
};

typedef struct {
    u8 unk0;
    u8 unk1;
} charandindex_t;
charandindex_t stdout_debug_menu_screen_buffer[80][35] = {0};
Gfx stdout_primary_color_table[32] = {0};
Gfx stdout_environment_color_table[32] = {0};

s32 g_CurrentColorIndex = 0;
char *string_formatting[] = {
"\x1B[31m\x1B[40m", "\x1B[37m\x1B[40m",
"\x1B[32m\x1B[40m", "\x1B[33m\x1B[40m",
"\x1B[34m\x1B[40m", "\x1B[35m\x1B[40m",
"\x1B[36m\x1B[40m", "\x1B[37m\x1B[44m",
"\x1B[31m\x1B[44m", "\x1B[32m\x1B[44m",
"\x1B[33m\x1B[44m", "\x1B[30m\x1B[44m",
"\x1B[35m\x1B[44m", "\x1B[36m\x1B[44m",
"\x1B[37m\x1B[41m", "\x1B[30m\x1B[41m",
"\x1B[32m\x1B[41m", "\x1B[33m\x1B[41m",
"\x1B[34m\x1B[41m", "\x1B[35m\x1B[41m",
"\x1B[36m\x1B[41m", "\x1B[37m\x1B[45m",
"\x1B[31m\x1B[45m", "\x1B[32m\x1B[45m",
"\x1B[33m\x1B[45m", "\x1B[34m\x1B[45m",
"\x1B[30m\x1B[45m", "\x1B[36m\x1B[45m",
"\x1B[37m\x1B[42m", "\x1B[31m\x1B[42m",
"\x1B[30m\x1B[42m", "\x1B[33m\x1B[42m"};



Gfx end_displaylist_command[] = {
	gsSPEndDisplayList()
};
u64 blank_C0_command =0xC000000000000000;
Gfx stdout_primary_color = {0xFA000000, 0xFFFFFF00};
Gfx debug_text_bg_color = {0xFB000000, 0x0};
u32 D_800268B8 = 0xFF;





u32 dummied_function_7000AD80(s32 arg0, s32 arg1)
{
    return 0;
}


u32 dummied_function_7000AD90(s32 arg0, s32 arg1)
{
    return 0;
}


void null_function_7000ADA0(void)
{
//empty
}


void debugmenuInit_REMOVED(void)
{
//empty
}


void debug_text_related_2(void)
{
    blank_debug_buffer_chars();
}

void display_text_to_coord(s32 x, s32 y, unsigned char c) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if ((stdout_primary_color.words.w1 == stdout_primary_color_table[i].words.w1) &&
            (debug_text_bg_color.words.w1 == stdout_environment_color_table[i].words.w1)) {
            goto end;
        }
    }
    stdout_primary_color_table[g_CurrentColorIndex] = stdout_primary_color;
    stdout_environment_color_table[g_CurrentColorIndex] = debug_text_bg_color;
    g_CurrentColorIndex = (g_CurrentColorIndex + 1) % 32;
    i = g_CurrentColorIndex;
end:
    stdout_debug_menu_screen_buffer[x][y].unk0 = c;
    stdout_debug_menu_screen_buffer[x][y].unk1 = i;
}

void debugMenuSetTextPOStoOffset(void)
{
    debug_menu_x_text_pos = debug_menu_x_pos_offset;
    debug_menu_y_text_pos = debug_menu_y_pos_offset;
}




void blank_debug_buffer_chars(void)
{
  int x;
  int y;
  
  for (y = 0; y < 35; y++)
  {
    for (x = 0; x < 80; x++)
    {
      display_text_to_coord(x,y,'\0');
    }
  }
  debugMenuSetTextPOStoOffset();
  null_function_7000ADA0();
  g_CurrentColorIndex = 0;
}

void stubbed_function_7000AF84(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    // Removed
}

#ifdef NONMATCHING
s32 something_debug_info_related(s32 height)
{
    s32 x;
    s32 y;
    s32 ret;
    for (y = 33; y > 0; y--) {
        s32 y2 = (y + height);
        if (y2 >= 0 && y2 < 35) {
            for (x = 0; x < 80; x++) {
                stubbed_function_7000AF84(x, y2, x, y);
            }
        } else {            
            for (x = 0; x < 80; x++) {
                display_text_to_coord(x, y, '\0');
            }
        }
        ret = y;
    }
    return ret;
}
#else
GLOBAL_ASM(
.text
glabel something_debug_info_related
/* 00BB98 7000AF98 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00BB9C 7000AF9C AFB30020 */  sw    $s3, 0x20($sp)
/* 00BBA0 7000AFA0 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00BBA4 7000AFA4 AFB10018 */  sw    $s1, 0x18($sp)
/* 00BBA8 7000AFA8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00BBAC 7000AFAC AFB00014 */  sw    $s0, 0x14($sp)
/* 00BBB0 7000AFB0 24110021 */  li    $s1, 33
/* 00BBB4 7000AFB4 24120050 */  li    $s2, 80
/* 00BBB8 7000AFB8 24930021 */  addiu $s3, $a0, 0x21
.L7000AFBC:
/* 00BBBC 7000AFBC 0660000D */  bltz  $s3, .L7000AFF4
/* 00BBC0 7000AFC0 2A610023 */   slti  $at, $s3, 0x23
/* 00BBC4 7000AFC4 1020000B */  beqz  $at, .L7000AFF4
/* 00BBC8 7000AFC8 00008025 */   move  $s0, $zero
/* 00BBCC 7000AFCC 02002025 */  move  $a0, $s0
.L7000AFD0:
/* 00BBD0 7000AFD0 02602825 */  move  $a1, $s3
/* 00BBD4 7000AFD4 02003025 */  move  $a2, $s0
/* 00BBD8 7000AFD8 0C002BE1 */  jal   stubbed_function_7000AF84
/* 00BBDC 7000AFDC 02203825 */   move  $a3, $s1
/* 00BBE0 7000AFE0 26100001 */  addiu $s0, $s0, 1
/* 00BBE4 7000AFE4 5612FFFA */  bnel  $s0, $s2, .L7000AFD0
/* 00BBE8 7000AFE8 02002025 */   move  $a0, $s0
/* 00BBEC 7000AFEC 1000000A */  b     .L7000B018
/* 00BBF0 7000AFF0 02201025 */   move  $v0, $s1
.L7000AFF4:
/* 00BBF4 7000AFF4 00008025 */  move  $s0, $zero
/* 00BBF8 7000AFF8 02002025 */  move  $a0, $s0
.L7000AFFC:
/* 00BBFC 7000AFFC 02202825 */  move  $a1, $s1
/* 00BC00 7000B000 0C002B74 */  jal   display_text_to_coord
/* 00BC04 7000B004 00003025 */   move  $a2, $zero
/* 00BC08 7000B008 26100001 */  addiu $s0, $s0, 1
/* 00BC0C 7000B00C 5612FFFB */  bnel  $s0, $s2, .L7000AFFC
/* 00BC10 7000B010 02002025 */   move  $a0, $s0
/* 00BC14 7000B014 02201025 */  move  $v0, $s1
.L7000B018:
/* 00BC18 7000B018 2673FFFF */  addiu $s3, $s3, -1
/* 00BC1C 7000B01C 1620FFE7 */  bnez  $s1, .L7000AFBC
/* 00BC20 7000B020 2631FFFF */   addiu $s1, $s1, -1
/* 00BC24 7000B024 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00BC28 7000B028 8FB00014 */  lw    $s0, 0x14($sp)
/* 00BC2C 7000B02C 8FB10018 */  lw    $s1, 0x18($sp)
/* 00BC30 7000B030 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00BC34 7000B034 8FB30020 */  lw    $s3, 0x20($sp)
/* 00BC38 7000B038 03E00008 */  jr    $ra
/* 00BC3C 7000B03C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

void set_final_debug_text_positions(s32 xadjust,s32 yadjust) {
    xadjust += debug_menu_x_pos_offset;
    yadjust += debug_menu_y_pos_offset;
    debug_menu_x_text_pos = xadjust;
    debug_menu_y_text_pos = yadjust;
}

void set_debug_text_color(s32 red,s32 blue,s32 green,s32 alpha)
{
  stdout_primary_color.words.w1 = red << 0x18 | blue << 0x10 | green << 8 | 0xffU - alpha;
}


void set_color_speedgraph(s32 red,s32 green,s32 blue,s32 alpha)
{
  debug_text_bg_color.words.w1 = red << 0x18 | green << 0x10 | blue << 8 | 0xffU - alpha;
}

void write_char_to_screen(unsigned char c) {
    s32 width = ((viGetX() - 13) / 4);
    s32 height = ((viGetY() - 10) / 7);
    if ((c == '\0') || ((c >= ' ') && (c <= '~'))) {
        display_text_to_coord(debug_menu_x_text_pos, debug_menu_y_text_pos, c);
    }
    debug_menu_x_text_pos++;
    if ((c == '\r') || (c == '\n') || (debug_menu_x_text_pos >= width)) {
        debug_menu_x_text_pos = debug_menu_x_pos_offset;        
        debug_menu_y_text_pos++;
        if (debug_menu_y_text_pos >= height) {
            debug_menu_y_text_pos = debug_menu_y_pos_offset;
        }
    }
}

void debug_printcharatpos(int x,int y, u8 character)
{
  set_final_debug_text_positions(x,y);
  write_char_to_screen(character);
}

void write_string_stdout(const unsigned char *str) {
    while (*str != '\0') {
        write_char_to_screen(*str++);
    }
}

void debug_text_related(s32 xadjust, s32 yadjust, const unsigned char *str) {  
    set_final_debug_text_positions(xadjust, yadjust);
    while (*str != '\0') {
        write_char_to_screen(*str++);
    }
}

#ifdef NONMATCHING
u32 get_random_value(void);
// Decent attempt but still lots of diffs
Gfx *read_screen_display_block_and_write_chars(Gfx *gdl) {
    s32 i;
    s32 j;
    s32 index = -1;
    Gfx *end;
    s32 size;
    s32 free;
    for (i = 0; i < 35; i++) {
        for (j = 0; j < 80; j++) {
            u8 var = stdout_debug_menu_screen_buffer[j][i].unk1;
            if (stdout_debug_menu_screen_buffer[j][i].unk0 != '\0') {
                if (var != index) {
                    end += 2;
                    index = var;
                }
                end += 3;
            }
        }
    }
    size = ((u8*)end - (u8*)gdl);
    free = dynGetFreeGfx(gdl);
    if (size <= 0) {
        return gdl;
    }
    free -= 2048;
    if (free <= 0) {
        D_800268B8 = 0;
    } else if (free < size) {
        D_800268B8 = ((free * 255) / size);
    } else {
        D_800268B8 = 256;
    }
    gSPDisplayList(gdl++, stdout_display_list);
    index = -1;
    for (i = 0; i < 35; i++) {
        for (j = 0; j < 80; j++) {
            charandindex_t *ptr = &stdout_debug_menu_screen_buffer[j][i];
            u32 var2 = ptr->unk0;
            u8 var1 = ptr->unk1;
            if (ptr->unk0 != '\0') {
                if (var1 != index) {
                    *(gdl++) = stdout_primary_color_table[var1];
                    *(gdl++) = stdout_environment_color_table[var1];
                    index = var1;
                }
                if ((get_random_value() & 0xFF)  < D_800268B8) {
                    if (dynGetFreeGfx(gdl) >= 1024) {
                        s32 s = ((var2 - 32) % 32);
                        s32 t = ((var2 - 32) / 32);
                        gSPTextureRectangle(gdl++, ((j * 4) * 4), ((i * 7) * 4), (((j + 1) * 4) * 4), (((i + 1) * 7) * 4), G_TX_RENDERTILE, ((s * 4) * 32), ((t * 7) * 32), (1 << 10), (1 << 10));
                    }
                }
            }
        }
    }
    return gdl;
}
#else
GLOBAL_ASM(
.text
glabel read_screen_display_block_and_write_chars
/* 00BE7C 7000B27C 27BDFF78 */  addiu $sp, $sp, -0x88
/* 00BE80 7000B280 AFB5002C */  sw    $s5, 0x2c($sp)
/* 00BE84 7000B284 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00BE88 7000B288 AFB00018 */  sw    $s0, 0x18($sp)
/* 00BE8C 7000B28C 3C078002 */  lui   $a3, %hi(stdout_primary_color_table)
/* 00BE90 7000B290 00808025 */  move  $s0, $a0
/* 00BE94 7000B294 AFBF003C */  sw    $ra, 0x3c($sp)
/* 00BE98 7000B298 AFBE0038 */  sw    $fp, 0x38($sp)
/* 00BE9C 7000B29C AFB70034 */  sw    $s7, 0x34($sp)
/* 00BEA0 7000B2A0 AFB60030 */  sw    $s6, 0x30($sp)
/* 00BEA4 7000B2A4 AFB40028 */  sw    $s4, 0x28($sp)
/* 00BEA8 7000B2A8 AFB30024 */  sw    $s3, 0x24($sp)
/* 00BEAC 7000B2AC AFB20020 */  sw    $s2, 0x20($sp)
/* 00BEB0 7000B2B0 00808825 */  move  $s1, $a0
/* 00BEB4 7000B2B4 2406FFFF */  li    $a2, -1
/* 00BEB8 7000B2B8 24E76610 */  addiu $a3, %lo(stdout_primary_color_table) # addiu $a3, $a3, 0x6610
/* 00BEBC 7000B2BC 0000A825 */  move  $s5, $zero
/* 00BEC0 7000B2C0 00004025 */  move  $t0, $zero
.L7000B2C4:
/* 00BEC4 7000B2C4 3C0E8002 */  lui   $t6, %hi(stdout_debug_menu_screen_buffer)
/* 00BEC8 7000B2C8 25C55030 */  addiu $a1, $t6, %lo(stdout_debug_menu_screen_buffer)
/* 00BECC 7000B2CC 01052021 */  addu  $a0, $t0, $a1
.L7000B2D0:
/* 00BED0 7000B2D0 90820000 */  lbu   $v0, ($a0)
/* 00BED4 7000B2D4 24A50046 */  addiu $a1, $a1, 0x46
/* 00BED8 7000B2D8 90830001 */  lbu   $v1, 1($a0)
/* 00BEDC 7000B2DC 10400006 */  beqz  $v0, .L7000B2F8
/* 00BEE0 7000B2E0 00000000 */   nop   
/* 00BEE4 7000B2E4 50660004 */  beql  $v1, $a2, .L7000B2F8
/* 00BEE8 7000B2E8 26310018 */   addiu $s1, $s1, 0x18
/* 00BEEC 7000B2EC 26310010 */  addiu $s1, $s1, 0x10
/* 00BEF0 7000B2F0 00603025 */  move  $a2, $v1
/* 00BEF4 7000B2F4 26310018 */  addiu $s1, $s1, 0x18
.L7000B2F8:
/* 00BEF8 7000B2F8 14A7FFF5 */  bne   $a1, $a3, .L7000B2D0
/* 00BEFC 7000B2FC 24840046 */   addiu $a0, $a0, 0x46
/* 00BF00 7000B300 25080002 */  addiu $t0, $t0, 2
/* 00BF04 7000B304 29010046 */  slti  $at, $t0, 0x46
/* 00BF08 7000B308 1420FFEE */  bnez  $at, .L7000B2C4
/* 00BF0C 7000B30C 00000000 */   nop   
/* 00BF10 7000B310 0FC2F5DF */  jal   dynGetFreeGfx
/* 00BF14 7000B314 02002025 */   move  $a0, $s0
/* 00BF18 7000B318 02302023 */  subu  $a0, $s1, $s0
/* 00BF1C 7000B31C 1C800003 */  bgtz  $a0, .L7000B32C
/* 00BF20 7000B320 2443F800 */   addiu $v1, $v0, -0x800
/* 00BF24 7000B324 10000080 */  b     .L7000B528
/* 00BF28 7000B328 02001025 */   move  $v0, $s0
.L7000B32C:
/* 00BF2C 7000B32C 1C600004 */  bgtz  $v1, .L7000B340
/* 00BF30 7000B330 2414FFFF */   li    $s4, -1
/* 00BF34 7000B334 3C018002 */  lui   $at, %hi(D_800268B8)
/* 00BF38 7000B338 10000017 */  b     .L7000B398
/* 00BF3C 7000B33C AC2068B8 */   sw    $zero, %lo(D_800268B8)($at)
.L7000B340:
/* 00BF40 7000B340 0064082A */  slt   $at, $v1, $a0
/* 00BF44 7000B344 10200011 */  beqz  $at, .L7000B38C
/* 00BF48 7000B348 00037A00 */   sll   $t7, $v1, 8
/* 00BF4C 7000B34C 01E37823 */  subu  $t7, $t7, $v1
/* 00BF50 7000B350 01E4001A */  div   $zero, $t7, $a0
/* 00BF54 7000B354 14800002 */  bnez  $a0, .L7000B360
/* 00BF58 7000B358 00000000 */   nop   
/* 00BF5C 7000B35C 0007000D */  break 7
.L7000B360:
/* 00BF60 7000B360 2401FFFF */  li    $at, -1
/* 00BF64 7000B364 14810004 */  bne   $a0, $at, .L7000B378
/* 00BF68 7000B368 3C018000 */   lui   $at, 0x8000
/* 00BF6C 7000B36C 15E10002 */  bne   $t7, $at, .L7000B378
/* 00BF70 7000B370 00000000 */   nop   
/* 00BF74 7000B374 0006000D */  break 6
.L7000B378:
/* 00BF78 7000B378 3C018002 */  lui   $at, %hi(D_800268B8)
/* 00BF7C 7000B37C 0000C012 */  mflo  $t8
/* 00BF80 7000B380 AC3868B8 */  sw    $t8, %lo(D_800268B8)($at)
/* 00BF84 7000B384 10000005 */  b     .L7000B39C
/* 00BF88 7000B388 02001025 */   move  $v0, $s0
.L7000B38C:
/* 00BF8C 7000B38C 24190100 */  li    $t9, 256
/* 00BF90 7000B390 3C018002 */  lui   $at, %hi(D_800268B8)
/* 00BF94 7000B394 AC3968B8 */  sw    $t9, %lo(D_800268B8)($at)
.L7000B398:
/* 00BF98 7000B398 02001025 */  move  $v0, $s0
.L7000B39C:
/* 00BF9C 7000B39C 3C0A8002 */  lui   $t2, %hi(stdout_display_list) 
/* 00BFA0 7000B3A0 254A4FB0 */  addiu $t2, %lo(stdout_display_list) # addiu $t2, $t2, 0x4fb0
/* 00BFA4 7000B3A4 3C090600 */  lui   $t1, 0x600
/* 00BFA8 7000B3A8 AC490000 */  sw    $t1, ($v0)
/* 00BFAC 7000B3AC AC4A0004 */  sw    $t2, 4($v0)
/* 00BFB0 7000B3B0 3C1E8002 */  lui   $fp, %hi(stdout_environment_color_table) 
/* 00BFB4 7000B3B4 3C178002 */  lui   $s7, %hi(stdout_primary_color_table) 
/* 00BFB8 7000B3B8 26100008 */  addiu $s0, $s0, 8
/* 00BFBC 7000B3BC 26F76610 */  addiu $s7, %lo(stdout_primary_color_table) # addiu $s7, $s7, 0x6610
/* 00BFC0 7000B3C0 27DE6710 */  addiu $fp, %lo(stdout_environment_color_table) # addiu $fp, $fp, 0x6710
/* 00BFC4 7000B3C4 AFA00040 */  sw    $zero, 0x40($sp)
/* 00BFC8 7000B3C8 0000A825 */  move  $s5, $zero
/* 00BFCC 7000B3CC 24160050 */  li    $s6, 80
.L7000B3D0:
/* 00BFD0 7000B3D0 8FAB0040 */  lw    $t3, 0x40($sp)
/* 00BFD4 7000B3D4 3C0C8002 */  lui   $t4, %hi(stdout_debug_menu_screen_buffer) 
/* 00BFD8 7000B3D8 258C5030 */  addiu $t4, %lo(stdout_debug_menu_screen_buffer) # addiu $t4, $t4, 0x5030
/* 00BFDC 7000B3DC 00008825 */  move  $s1, $zero
/* 00BFE0 7000B3E0 016C9021 */  addu  $s2, $t3, $t4
.L7000B3E4:
/* 00BFE4 7000B3E4 92530000 */  lbu   $s3, ($s2)
/* 00BFE8 7000B3E8 92430001 */  lbu   $v1, 1($s2)
/* 00BFEC 7000B3EC 52600045 */  beql  $s3, $zero, .L7000B504
/* 00BFF0 7000B3F0 26310001 */   addiu $s1, $s1, 1
/* 00BFF4 7000B3F4 1074000D */  beq   $v1, $s4, .L7000B42C
/* 00BFF8 7000B3F8 000310C0 */   sll   $v0, $v1, 3
/* 00BFFC 7000B3FC 02E26821 */  addu  $t5, $s7, $v0
/* 00C000 7000B400 8DA10000 */  lw    $at, ($t5)
/* 00C004 7000B404 03C2C021 */  addu  $t8, $fp, $v0
/* 00C008 7000B408 26100010 */  addiu $s0, $s0, 0x10
/* 00C00C 7000B40C AE01FFF0 */  sw    $at, -0x10($s0)
/* 00C010 7000B410 8DAF0004 */  lw    $t7, 4($t5)
/* 00C014 7000B414 0060A025 */  move  $s4, $v1
/* 00C018 7000B418 AE0FFFF4 */  sw    $t7, -0xc($s0)
/* 00C01C 7000B41C 8F010000 */  lw    $at, ($t8)
/* 00C020 7000B420 AE01FFF8 */  sw    $at, -8($s0)
/* 00C024 7000B424 8F090004 */  lw    $t1, 4($t8)
/* 00C028 7000B428 AE09FFFC */  sw    $t1, -4($s0)
.L7000B42C:
/* 00C02C 7000B42C 0C002914 */  jal   get_random_value
/* 00C030 7000B430 00000000 */   nop   
/* 00C034 7000B434 3C0B8002 */  lui   $t3, %hi(D_800268B8) 
/* 00C038 7000B438 8D6B68B8 */  lw    $t3, %lo(D_800268B8)($t3)
/* 00C03C 7000B43C 304A00FF */  andi  $t2, $v0, 0xff
/* 00C040 7000B440 014B082B */  sltu  $at, $t2, $t3
/* 00C044 7000B444 5020002F */  beql  $at, $zero, .L7000B504
/* 00C048 7000B448 26310001 */   addiu $s1, $s1, 1
/* 00C04C 7000B44C 0FC2F5DF */  jal   dynGetFreeGfx
/* 00C050 7000B450 02002025 */   move  $a0, $s0
/* 00C054 7000B454 28410400 */  slti  $at, $v0, 0x400
/* 00C058 7000B458 14200029 */  bnez  $at, .L7000B500
/* 00C05C 7000B45C 02001025 */   move  $v0, $s0
/* 00C060 7000B460 00111900 */  sll   $v1, $s1, 4
/* 00C064 7000B464 001520C0 */  sll   $a0, $s5, 3
/* 00C068 7000B468 00952023 */  subu  $a0, $a0, $s5
/* 00C06C 7000B46C 246C0010 */  addiu $t4, $v1, 0x10
/* 00C070 7000B470 318E0FFF */  andi  $t6, $t4, 0xfff
/* 00C074 7000B474 00042080 */  sll   $a0, $a0, 2
/* 00C078 7000B478 306A0FFF */  andi  $t2, $v1, 0xfff
/* 00C07C 7000B47C 000A5B00 */  sll   $t3, $t2, 0xc
/* 00C080 7000B480 000E6B00 */  sll   $t5, $t6, 0xc
/* 00C084 7000B484 2499001C */  addiu $t9, $a0, 0x1c
/* 00C088 7000B488 308C0FFF */  andi  $t4, $a0, 0xfff
/* 00C08C 7000B48C 3C01E400 */  lui   $at, 0xe400
/* 00C090 7000B490 2666FFE0 */  addiu $a2, $s3, -0x20
/* 00C094 7000B494 00065143 */  sra   $t2, $a2, 5
/* 00C098 7000B498 01A17825 */  or    $t7, $t5, $at
/* 00C09C 7000B49C 016C7025 */  or    $t6, $t3, $t4
/* 00C0A0 7000B4A0 33380FFF */  andi  $t8, $t9, 0xfff
/* 00C0A4 7000B4A4 01F84825 */  or    $t1, $t7, $t8
/* 00C0A8 7000B4A8 000A58C0 */  sll   $t3, $t2, 3
/* 00C0AC 7000B4AC 016A5823 */  subu  $t3, $t3, $t2
/* 00C0B0 7000B4B0 26100008 */  addiu $s0, $s0, 8
/* 00C0B4 7000B4B4 02002825 */  move  $a1, $s0
/* 00C0B8 7000B4B8 000B5940 */  sll   $t3, $t3, 5
/* 00C0BC 7000B4BC AC490000 */  sw    $t1, ($v0)
/* 00C0C0 7000B4C0 30D8001F */  andi  $t8, $a2, 0x1f
/* 00C0C4 7000B4C4 AC4E0004 */  sw    $t6, 4($v0)
/* 00C0C8 7000B4C8 00184DC0 */  sll   $t1, $t8, 0x17
/* 00C0CC 7000B4CC 316CFFFF */  andi  $t4, $t3, 0xffff
/* 00C0D0 7000B4D0 26100008 */  addiu $s0, $s0, 8
/* 00C0D4 7000B4D4 3C0DB400 */  lui   $t5, 0xb400
/* 00C0D8 7000B4D8 ACAD0000 */  sw    $t5, ($a1)
/* 00C0DC 7000B4DC 02003825 */  move  $a3, $s0
/* 00C0E0 7000B4E0 012C7025 */  or    $t6, $t1, $t4
/* 00C0E4 7000B4E4 ACAE0004 */  sw    $t6, 4($a1)
/* 00C0E8 7000B4E8 3C190400 */  lui   $t9, (0x04000400 >> 16) # lui $t9, 0x400
/* 00C0EC 7000B4EC 37390400 */  ori   $t9, (0x04000400 & 0xFFFF) # ori $t9, $t9, 0x400
/* 00C0F0 7000B4F0 3C0DB300 */  lui   $t5, 0xb300
/* 00C0F4 7000B4F4 ACED0000 */  sw    $t5, ($a3)
/* 00C0F8 7000B4F8 ACF90004 */  sw    $t9, 4($a3)
/* 00C0FC 7000B4FC 26100008 */  addiu $s0, $s0, 8
.L7000B500:
/* 00C100 7000B500 26310001 */  addiu $s1, $s1, 1
.L7000B504:
/* 00C104 7000B504 1636FFB7 */  bne   $s1, $s6, .L7000B3E4
/* 00C108 7000B508 26520046 */   addiu $s2, $s2, 0x46
/* 00C10C 7000B50C 8FAF0040 */  lw    $t7, 0x40($sp)
/* 00C110 7000B510 26B50001 */  addiu $s5, $s5, 1
/* 00C114 7000B514 24010023 */  li    $at, 35
/* 00C118 7000B518 25F80002 */  addiu $t8, $t7, 2
/* 00C11C 7000B51C 16A1FFAC */  bne   $s5, $at, .L7000B3D0
/* 00C120 7000B520 AFB80040 */   sw    $t8, 0x40($sp)
/* 00C124 7000B524 02001025 */  move  $v0, $s0
.L7000B528:
/* 00C128 7000B528 8FBF003C */  lw    $ra, 0x3c($sp)
/* 00C12C 7000B52C 8FB00018 */  lw    $s0, 0x18($sp)
/* 00C130 7000B530 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00C134 7000B534 8FB20020 */  lw    $s2, 0x20($sp)
/* 00C138 7000B538 8FB30024 */  lw    $s3, 0x24($sp)
/* 00C13C 7000B53C 8FB40028 */  lw    $s4, 0x28($sp)
/* 00C140 7000B540 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00C144 7000B544 8FB60030 */  lw    $s6, 0x30($sp)
/* 00C148 7000B548 8FB70034 */  lw    $s7, 0x34($sp)
/* 00C14C 7000B54C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 00C150 7000B550 03E00008 */  jr    $ra
/* 00C154 7000B554 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif
