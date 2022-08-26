#include <ultra64.h>
#include "lightfixture.h"
#include "bg.h"
#include <bondconstants.h>
#include <assets/image_externs.h>

#define LIGHTFIXTURE_TABLE_MAX 0x64
#define BSS_80082B18_MAX 0x200

// bss
//CODE.bss:80082660
s_lightfixture light_fixture_table[LIGHTFIXTURE_TABLE_MAX];
//CODE.bss:80082B10
s16 cur_entry_lightfixture_table;
//CODE.bss:80082B12
s16 index_of_cur_entry_lightfixture_table;
//CODE.bss:80082B14                     .align 3
//CODE.bss:80082B18
struct bondstruct_unk_80082B18 word_CODE_bss_80082B18[BSS_80082B18_MAX];
//CODE.bss:80083318
s32 dword_CODE_bss_80083318;

// data
//D:80046030
s32 D_80046030 = 0; 

s32 D_80046034[] = {0, 0, 0, 0, 0, 0, 0};


void init_lightfixture_tables(void)
{
    s32 i;

    for (i = 0; i < LIGHTFIXTURE_TABLE_MAX; i++)
    {
        light_fixture_table[i].index = 0;
    }

    for (i = 0; i < BSS_80082B18_MAX; i++)
    {
        word_CODE_bss_80082B18[i].unk00 = 0;
    }

    D_80046030 = 0;
}


s32 get_index_of_current_entry_in_init_lightfixture_table(void)
{
    s32 i;

    for (i = 0; i != LIGHTFIXTURE_TABLE_MAX; i++)
    {
        if (light_fixture_table[i].index == 0)
        {
            return i;
        }
    }
    return LIGHTFIXTURE_TABLE_MAX;
}


void add_entry_to_init_lightfixture_table(Gfx *DL)
{
  cur_entry_lightfixture_table = get_index_of_current_entry_in_init_lightfixture_table();
  if (cur_entry_lightfixture_table != 100) {
    light_fixture_table[cur_entry_lightfixture_table].index = index_of_cur_entry_lightfixture_table;
    light_fixture_table[cur_entry_lightfixture_table].ptr_start_pertinent_DL = DL;
  }
}


void save_ptrDL_enpoint_to_current_init_lightfixture_table(Gfx *param_1)
{
  if (cur_entry_lightfixture_table != 100) {
    light_fixture_table[cur_entry_lightfixture_table].ptr_end_pertinent_DL = param_1;
  }
}


s32 check_if_imageID_is_light(s32 imageID)
{
    if ((imageID == IMAGE_WALL_LAMP)     ||
        (imageID == IMAGE_203_LIGHT)     ||
        (imageID == IMAGE_205_LIGHT)     ||
        (imageID == IMAGE_252_LIGHT)     ||
        (imageID == IMAGE_PANEL_LAMP)    ||
        (imageID == IMAGE_255_LIGHT)     ||
        (imageID == IMAGE_256_LIGHT)     ||
        (imageID == IMAGE_HANGING_LAMP)  ||
        (imageID == IMAGE_NEON_LAMP)     ||
        (imageID == IMAGE_LINEAR_LAMP))
    {
        // Will darken when shot
        return 1;
    } 
    else
    {
        return 0;
    }
}


Vtx * return_ptr_vertex_of_entry_room(Gfx * gfx, s32 arg1)
{
    Vtx * ret;

    while (gfx->dma.cmd != G_VTX ){ gfx--; }

    ret = gfx->dma.addr;

    // weird memory checking, not sure what's going on here
    if (((s32) ret & 0xFF000000) == 0x0E000000) {
        ret = (s32)array_room_info[arg1].ptr_point_index + ((s32) ret & 0xFFFFFF);
    }

    return ret;
}


void sub_GAME_7F0BB6F4(Gfx* gfx, u32 type, s32* idx1, s32* idx2, s32* idx3)
{
    switch (type) {
        case 0:
            *idx1 = (s32) gfx->tri.tri.v[0] / 10;
            *idx2 = (s32) gfx->tri.tri.v[1] / 10;
            *idx3 = (s32) gfx->tri.tri.v[2] / 10;
            break;
        // unsure of how to cleanly access the below versions
        case 1:
            *idx1 = ((u32*)gfx)[1] & 0xF;
            *idx2 = ((((u8*)gfx)[7]) & 0xFFFFFFFFu) >> 4;
            *idx3 = ((s32*)gfx)[0] & 0xF;
            break;
        case 2:
            *idx1 = ((u8*)gfx)[6] & 0xF;
            *idx2 = ((((u16*)gfx)[3]) & 0xFFFFFFFFu) >> 0xC;
            *idx3 = ((((u8*)gfx)[3]) & 0xFFFFFFFFu) >> 4;
            break;
        case 3:
            *idx1 = ((u16*)gfx)[2] & 0xF;
            *idx2 = ((((u8*)gfx)[5]) & 0xFFFFFFFFu) >> 4;
            *idx3 = ((u8*)gfx)[2] & 0xF;
            break;
        case 4:
            *idx1 = ((u8*)gfx)[4] & 0xF;
            *idx2 = ((u32*)gfx)[1] >> 0x1C;
            *idx3 = ((((u16*)gfx)[1]) & 0xFFFFFFFFu) >> 0xC;
            break;
    }
}


void sub_GAME_7F0BB874(Gfx * gfx, u32 arg1, s32 arg2, Vtx * arg3, Vtx * arg4, Vtx * arg5)
{
    s32 idx1;
    s32 idx2;
    s32 idx3;
    Vtx * vertices;

    sub_GAME_7F0BB6F4(gfx, arg1, &idx1, &idx2, &idx3);
    vertices = return_ptr_vertex_of_entry_room(gfx, arg2);

    arg3->v.ob[0] = (s16) vertices[idx1].v.ob[0];
    arg3->v.ob[1] = (s16) vertices[idx1].v.ob[1];
    arg3->v.ob[2] = (s16) vertices[idx1].v.ob[2];

    arg4->v.ob[0] = (s16) vertices[idx2].v.ob[0];
    arg4->v.ob[1] = (s16) vertices[idx2].v.ob[1];
    arg4->v.ob[2] = (s16) vertices[idx2].v.ob[2];

    arg5->v.ob[0] = (s16) vertices[idx3].v.ob[0];
    arg5->v.ob[1] = (s16) vertices[idx3].v.ob[1];
    arg5->v.ob[2] = (s16) vertices[idx3].v.ob[2];
}


void sub_GAME_7F0BB978(s32 arg0)
{
    Vtx * vertices;
    s32 i;
    struct bondstruct_unk_80082B18* unk;


    vertices = array_room_info[arg0].ptr_point_index;

    for (i = 0; i < BSS_80082B18_MAX; i++)
    {
        unk = &word_CODE_bss_80082B18[i];

        if (arg0 != unk->unk00) { continue; }

        vertices[unk->unk02].v.cn[0] >>= 2;
        vertices[unk->unk02].v.cn[1] >>= 2;
        vertices[unk->unk02].v.cn[2] >>= 2;
        vertices[unk->unk02].v.cn[3] >>= 2;
    }
}


void sub_GAME_7F0BBA20(Vtx * vertices, s32 arg1)
{
    s32 room_index;

    if (sub_GAME_7F0BBADC(vertices, arg1) != 0) { return; }

    // weird memory stuff going on here
    room_index = ((u32)vertices - (u32)array_room_info[arg1].ptr_point_index) >> 4;

    word_CODE_bss_80082B18[D_80046030].unk00 = (u16) arg1;
    word_CODE_bss_80082B18[D_80046030].unk02 = room_index;

    vertices->v.cn[0] >>= 2;
    vertices->v.cn[1] >>= 2;
    vertices->v.cn[2] >>= 2;
    vertices->v.cn[3] >>= 2;

    D_80046030++;

    if (D_80046030 >= 0x200)
    {
        D_80046030 = 0;
    }
}


s32 sub_GAME_7F0BBADC(Vtx * vertices, s32 arg1)
{
    u32 value;
    s32 i;

    // weird memory stuff going on here
    value = ((u32)vertices - (u32)array_room_info[arg1].ptr_point_index) >> 4;

    for (i = 0; i < BSS_80082B18_MAX; i++)
    {
        if ((arg1 == word_CODE_bss_80082B18[i].unk00) && ((s32)value == word_CODE_bss_80082B18[i].unk02))
        {
            return 1;
        }
    }

    return 0;
}


void sub_GAME_7F0BBBA8(Gfx *gfx, u32 arg1, s32 arg2)
{
    Vtx * vertices_2;
    s32 idx1;
    s32 idx2;
    s32 idx3;
    Vtx * vertices;

    sub_GAME_7F0BB6F4(gfx, arg1, &idx1, &idx2, &idx3);
    vertices = return_ptr_vertex_of_entry_room(gfx, arg2);

    sub_GAME_7F0BBA20(&vertices[idx1], arg2);
    sub_GAME_7F0BBA20(&vertices[idx2], arg2);

    vertices_2 = &vertices[idx3];
    sub_GAME_7F0BBA20(vertices_2, arg2);
}


s32 sub_GAME_7F0BBC30(Gfx * gfx, u32 arg1, s32 arg2)
{
    s32 out3;
    s32 idx1;
    s32 idx2;
    s32 idx3;
    Vtx * vertices;
    s32 out2;
    s32 out1;

    sub_GAME_7F0BB6F4(gfx, arg1, &idx1, &idx2, &idx3);
    vertices = return_ptr_vertex_of_entry_room(gfx, arg2);
    out1 = sub_GAME_7F0BBADC(&vertices[idx2], arg2);
    out2 = sub_GAME_7F0BBADC(&vertices[idx1], arg2);
    out3 = sub_GAME_7F0BBADC(&vertices[idx3], arg2);
    return out3 + out2 + out1;
}


s32 sub_GAME_7F0BBCCC(Vtx * vertices, s32 arg1)
{
    s32 var_s0;
    s32 var_s1;
    s32 i;
    s32 var_s2;
    Vtx * vertices2;

    i = 0;
    do
    {
        if (arg1 == word_CODE_bss_80082B18[i].unk00)
        {
            vertices2 = &array_room_info[arg1].ptr_point_index[word_CODE_bss_80082B18[i].unk02];

            var_s0 = vertices2->v.ob[0] - vertices->v.ob[0];
            var_s1 = vertices2->v.ob[1] - vertices->v.ob[1];
            var_s2 = vertices2->v.ob[2] - vertices->v.ob[2];

            if (var_s0 < 0) { var_s0 = -var_s0; }
            if (var_s1 < 0) { var_s1 = -var_s1; }
            if (var_s2 < 0) { var_s2 = -var_s2; }

            if ((var_s0 + var_s1 + var_s2) < (s32) (get_room_data_float1() * 100.0f))
            {
                return 1;
            }
        }
    } while (++i < BSS_80082B18_MAX);

    return 0;
}


#ifdef NONMATCHING
void sub_GAME_7F0BBE0C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BBE0C
/* 0F093C 7F0BBE0C 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0F0940 7F0BBE10 AFB20044 */  sw    $s2, 0x44($sp)
/* 0F0944 7F0BBE14 AFB10040 */  sw    $s1, 0x40($sp)
/* 0F0948 7F0BBE18 AFB0003C */  sw    $s0, 0x3c($sp)
/* 0F094C 7F0BBE1C 3C128008 */  lui   $s2, %hi(light_fixture_table)
/* 0F0950 7F0BBE20 3C028008 */  lui   $v0, %hi(cur_entry_lightfixture_table)
/* 0F0954 7F0BBE24 00808025 */  move  $s0, $a0
/* 0F0958 7F0BBE28 00A08825 */  move  $s1, $a1
/* 0F095C 7F0BBE2C AFBF005C */  sw    $ra, 0x5c($sp)
/* 0F0960 7F0BBE30 AFB70058 */  sw    $s7, 0x58($sp)
/* 0F0964 7F0BBE34 AFB60054 */  sw    $s6, 0x54($sp)
/* 0F0968 7F0BBE38 AFB50050 */  sw    $s5, 0x50($sp)
/* 0F096C 7F0BBE3C AFB4004C */  sw    $s4, 0x4c($sp)
/* 0F0970 7F0BBE40 AFB30048 */  sw    $s3, 0x48($sp)
/* 0F0974 7F0BBE44 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0F0978 7F0BBE48 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0F097C 7F0BBE4C F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0F0980 7F0BBE50 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0F0984 7F0BBE54 00C03825 */  move  $a3, $a2
/* 0F0988 7F0BBE58 24422B10 */  addiu $v0, %lo(cur_entry_lightfixture_table) # addiu $v0, $v0, 0x2b10
/* 0F098C 7F0BBE5C 26522660 */  addiu $s2, %lo(light_fixture_table) # addiu $s2, $s2, 0x2660
/* 0F0990 7F0BBE60 86460000 */  lh    $a2, ($s2)
.L7F0BBE64:
/* 0F0994 7F0BBE64 54E60186 */  bnel  $a3, $a2, .L7F0BC480
/* 0F0998 7F0BBE68 2652000C */   addiu $s2, $s2, 0xc
/* 0F099C 7F0BBE6C 8E4E0004 */  lw    $t6, 4($s2)
/* 0F09A0 7F0BBE70 020E082B */  sltu  $at, $s0, $t6
/* 0F09A4 7F0BBE74 54200182 */  bnezl $at, .L7F0BC480
/* 0F09A8 7F0BBE78 2652000C */   addiu $s2, $s2, 0xc
/* 0F09AC 7F0BBE7C 8E4F0008 */  lw    $t7, 8($s2)
/* 0F09B0 7F0BBE80 020F082B */  sltu  $at, $s0, $t7
/* 0F09B4 7F0BBE84 1020017D */  beqz  $at, .L7F0BC47C
/* 0F09B8 7F0BBE88 02002025 */   move  $a0, $s0
/* 0F09BC 7F0BBE8C 0FC2EF0C */  jal   sub_GAME_7F0BBC30
/* 0F09C0 7F0BBE90 02202825 */   move  $a1, $s1
/* 0F09C4 7F0BBE94 1440017C */  bnez  $v0, .L7F0BC488
/* 0F09C8 7F0BBE98 02002025 */   move  $a0, $s0
/* 0F09CC 7F0BBE9C 02202825 */  move  $a1, $s1
/* 0F09D0 7F0BBEA0 0FC2EEEA */  jal   sub_GAME_7F0BBBA8
/* 0F09D4 7F0BBEA4 86460000 */   lh    $a2, ($s2)
/* 0F09D8 7F0BBEA8 27B800E8 */  addiu $t8, $sp, 0xe8
/* 0F09DC 7F0BBEAC 27B900E0 */  addiu $t9, $sp, 0xe0
/* 0F09E0 7F0BBEB0 AFB90014 */  sw    $t9, 0x14($sp)
/* 0F09E4 7F0BBEB4 AFB80010 */  sw    $t8, 0x10($sp)
/* 0F09E8 7F0BBEB8 02002025 */  move  $a0, $s0
/* 0F09EC 7F0BBEBC 02202825 */  move  $a1, $s1
/* 0F09F0 7F0BBEC0 86460000 */  lh    $a2, ($s2)
/* 0F09F4 7F0BBEC4 0FC2EE1D */  jal   sub_GAME_7F0BB874
/* 0F09F8 7F0BBEC8 27A700F0 */   addiu $a3, $sp, 0xf0
/* 0F09FC 7F0BBECC 87A200F0 */  lh    $v0, 0xf0($sp)
/* 0F0A00 7F0BBED0 87A500E8 */  lh    $a1, 0xe8($sp)
/* 0F0A04 7F0BBED4 87A600E0 */  lh    $a2, 0xe0($sp)
/* 0F0A08 7F0BBED8 87A300F2 */  lh    $v1, 0xf2($sp)
/* 0F0A0C 7F0BBEDC 00458023 */  subu  $s0, $v0, $a1
/* 0F0A10 7F0BBEE0 00105C00 */  sll   $t3, $s0, 0x10
/* 0F0A14 7F0BBEE4 000B8403 */  sra   $s0, $t3, 0x10
/* 0F0A18 7F0BBEE8 02100019 */  multu $s0, $s0
/* 0F0A1C 7F0BBEEC 87A700EA */  lh    $a3, 0xea($sp)
/* 0F0A20 7F0BBEF0 0046A023 */  subu  $s4, $v0, $a2
/* 0F0A24 7F0BBEF4 00146C00 */  sll   $t5, $s4, 0x10
/* 0F0A28 7F0BBEF8 000DA403 */  sra   $s4, $t5, 0x10
/* 0F0A2C 7F0BBEFC 00678823 */  subu  $s1, $v1, $a3
/* 0F0A30 7F0BBF00 0011CC00 */  sll   $t9, $s1, 0x10
/* 0F0A34 7F0BBF04 00198C03 */  sra   $s1, $t9, 0x10
/* 0F0A38 7F0BBF08 87A800E2 */  lh    $t0, 0xe2($sp)
/* 0F0A3C 7F0BBF0C 87A400F4 */  lh    $a0, 0xf4($sp)
/* 0F0A40 7F0BBF10 00006812 */  mflo  $t5
/* 0F0A44 7F0BBF14 87A900EC */  lh    $t1, 0xec($sp)
/* 0F0A48 7F0BBF18 00A6B823 */  subu  $s7, $a1, $a2
/* 0F0A4C 7F0BBF1C 02310019 */  multu $s1, $s1
/* 0F0A50 7F0BBF20 00E87023 */  subu  $t6, $a3, $t0
/* 0F0A54 7F0BBF24 00177C00 */  sll   $t7, $s7, 0x10
/* 0F0A58 7F0BBF28 A7AE00B4 */  sh    $t6, 0xb4($sp)
/* 0F0A5C 7F0BBF2C 000FBC03 */  sra   $s7, $t7, 0x10
/* 0F0A60 7F0BBF30 00899823 */  subu  $s3, $a0, $t1
/* 0F0A64 7F0BBF34 00137C00 */  sll   $t7, $s3, 0x10
/* 0F0A68 7F0BBF38 000F9C03 */  sra   $s3, $t7, 0x10
/* 0F0A6C 7F0BBF3C 87AA00E4 */  lh    $t2, 0xe4($sp)
/* 0F0A70 7F0BBF40 0068A823 */  subu  $s5, $v1, $t0
/* 0F0A74 7F0BBF44 00007012 */  mflo  $t6
/* 0F0A78 7F0BBF48 008AB023 */  subu  $s6, $a0, $t2
/* 0F0A7C 7F0BBF4C 0016CC00 */  sll   $t9, $s6, 0x10
/* 0F0A80 7F0BBF50 02730019 */  multu $s3, $s3
/* 0F0A84 7F0BBF54 0019B403 */  sra   $s6, $t9, 0x10
/* 0F0A88 7F0BBF58 01AE7821 */  addu  $t7, $t5, $t6
/* 0F0A8C 7F0BBF5C 00156400 */  sll   $t4, $s5, 0x10
/* 0F0A90 7F0BBF60 000CAC03 */  sra   $s5, $t4, 0x10
/* 0F0A94 7F0BBF64 012A6023 */  subu  $t4, $t1, $t2
/* 0F0A98 7F0BBF68 A7AC00AE */  sh    $t4, 0xae($sp)
/* 0F0A9C 7F0BBF6C 0000C012 */  mflo  $t8
/* 0F0AA0 7F0BBF70 01F8C821 */  addu  $t9, $t7, $t8
/* 0F0AA4 7F0BBF74 44992000 */  mtc1  $t9, $f4
/* 0F0AA8 7F0BBF78 0C007DF8 */  jal   sqrtf
/* 0F0AAC 7F0BBF7C 46802320 */   cvt.s.w $f12, $f4
/* 0F0AB0 7F0BBF80 0FC2D20C */  jal   get_room_data_float2
/* 0F0AB4 7F0BBF84 46000506 */   mov.s $f20, $f0
/* 0F0AB8 7F0BBF88 02940019 */  multu $s4, $s4
/* 0F0ABC 7F0BBF8C 46140182 */  mul.s $f6, $f0, $f20
/* 0F0AC0 7F0BBF90 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0F0AC4 7F0BBF94 4481D000 */  mtc1  $at, $f26
/* 0F0AC8 7F0BBF98 00000000 */  nop   
/* 0F0ACC 7F0BBF9C 4606D203 */  div.s $f8, $f26, $f6
/* 0F0AD0 7F0BBFA0 00005812 */  mflo  $t3
/* 0F0AD4 7F0BBFA4 00000000 */  nop   
/* 0F0AD8 7F0BBFA8 00000000 */  nop   
/* 0F0ADC 7F0BBFAC 02B50019 */  multu $s5, $s5
/* 0F0AE0 7F0BBFB0 00006012 */  mflo  $t4
/* 0F0AE4 7F0BBFB4 016C6821 */  addu  $t5, $t3, $t4
/* 0F0AE8 7F0BBFB8 00000000 */  nop   
/* 0F0AEC 7F0BBFBC 02D60019 */  multu $s6, $s6
/* 0F0AF0 7F0BBFC0 E7A800A8 */  swc1  $f8, 0xa8($sp)
/* 0F0AF4 7F0BBFC4 00007012 */  mflo  $t6
/* 0F0AF8 7F0BBFC8 01AE7821 */  addu  $t7, $t5, $t6
/* 0F0AFC 7F0BBFCC 448F5000 */  mtc1  $t7, $f10
/* 0F0B00 7F0BBFD0 0C007DF8 */  jal   sqrtf
/* 0F0B04 7F0BBFD4 46805320 */   cvt.s.w $f12, $f10
/* 0F0B08 7F0BBFD8 0FC2D20C */  jal   get_room_data_float2
/* 0F0B0C 7F0BBFDC 46000506 */   mov.s $f20, $f0
/* 0F0B10 7F0BBFE0 02F70019 */  multu $s7, $s7
/* 0F0B14 7F0BBFE4 87A200B4 */  lh    $v0, 0xb4($sp)
/* 0F0B18 7F0BBFE8 46140402 */  mul.s $f16, $f0, $f20
/* 0F0B1C 7F0BBFEC 87A300AE */  lh    $v1, 0xae($sp)
/* 0F0B20 7F0BBFF0 4610D483 */  div.s $f18, $f26, $f16
/* 0F0B24 7F0BBFF4 0000C012 */  mflo  $t8
/* 0F0B28 7F0BBFF8 00000000 */  nop   
/* 0F0B2C 7F0BBFFC 00000000 */  nop   
/* 0F0B30 7F0BC000 00420019 */  multu $v0, $v0
/* 0F0B34 7F0BC004 0000C812 */  mflo  $t9
/* 0F0B38 7F0BC008 03195821 */  addu  $t3, $t8, $t9
/* 0F0B3C 7F0BC00C 00000000 */  nop   
/* 0F0B40 7F0BC010 00630019 */  multu $v1, $v1
/* 0F0B44 7F0BC014 E7B200A4 */  swc1  $f18, 0xa4($sp)
/* 0F0B48 7F0BC018 00006012 */  mflo  $t4
/* 0F0B4C 7F0BC01C 016C6821 */  addu  $t5, $t3, $t4
/* 0F0B50 7F0BC020 448D2000 */  mtc1  $t5, $f4
/* 0F0B54 7F0BC024 0C007DF8 */  jal   sqrtf
/* 0F0B58 7F0BC028 46802320 */   cvt.s.w $f12, $f4
/* 0F0B5C 7F0BC02C 0FC2D20C */  jal   get_room_data_float2
/* 0F0B60 7F0BC030 46000506 */   mov.s $f20, $f0
/* 0F0B64 7F0BC034 46140182 */  mul.s $f6, $f0, $f20
/* 0F0B68 7F0BC038 86440000 */  lh    $a0, ($s2)
/* 0F0B6C 7F0BC03C 27A50094 */  addiu $a1, $sp, 0x94
/* 0F0B70 7F0BC040 4606D203 */  div.s $f8, $f26, $f6
/* 0F0B74 7F0BC044 0FC2F28D */  jal   sub_GAME_7F0BCA34
/* 0F0B78 7F0BC048 E7A800A0 */   swc1  $f8, 0xa0($sp)
/* 0F0B7C 7F0BC04C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F0B80 7F0BC050 4481C000 */  mtc1  $at, $f24
/* 0F0B84 7F0BC054 4480B000 */  mtc1  $zero, $f22
/* 0F0B88 7F0BC058 00000000 */  nop   
/* 0F0B8C 7F0BC05C 4618B03C */  c.lt.s $f22, $f24
/* 0F0B90 7F0BC060 4600B506 */  mov.s $f20, $f22
/* 0F0B94 7F0BC064 45020039 */  bc1fl .L7F0BC14C
/* 0F0B98 7F0BC068 4618B03C */   c.lt.s $f22, $f24
/* 0F0B9C 7F0BC06C 44905000 */  mtc1  $s0, $f10
/* 0F0BA0 7F0BC070 44919000 */  mtc1  $s1, $f18
/* 0F0BA4 7F0BC074 44933000 */  mtc1  $s3, $f6
/* 0F0BA8 7F0BC078 46805420 */  cvt.s.w $f16, $f10
/* 0F0BAC 7F0BC07C 27B00088 */  addiu $s0, $sp, 0x88
/* 0F0BB0 7F0BC080 46809120 */  cvt.s.w $f4, $f18
/* 0F0BB4 7F0BC084 E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0F0BB8 7F0BC088 46803220 */  cvt.s.w $f8, $f6
/* 0F0BBC 7F0BC08C E7A40068 */  swc1  $f4, 0x68($sp)
/* 0F0BC0 7F0BC090 E7A80064 */  swc1  $f8, 0x64($sp)
.L7F0BC094:
/* 0F0BC4 7F0BC094 0FC2D20C */  jal   get_room_data_float2
/* 0F0BC8 7F0BC098 00000000 */   nop   
/* 0F0BCC 7F0BC09C 87A500E8 */  lh    $a1, 0xe8($sp)
/* 0F0BD0 7F0BC0A0 C7B2006C */  lwc1  $f18, 0x6c($sp)
/* 0F0BD4 7F0BC0A4 44855000 */  mtc1  $a1, $f10
/* 0F0BD8 7F0BC0A8 46149102 */  mul.s $f4, $f18, $f20
/* 0F0BDC 7F0BC0AC 46805420 */  cvt.s.w $f16, $f10
/* 0F0BE0 7F0BC0B0 C7AA0094 */  lwc1  $f10, 0x94($sp)
/* 0F0BE4 7F0BC0B4 46048180 */  add.s $f6, $f16, $f4
/* 0F0BE8 7F0BC0B8 46003202 */  mul.s $f8, $f6, $f0
/* 0F0BEC 7F0BC0BC 46085480 */  add.s $f18, $f10, $f8
/* 0F0BF0 7F0BC0C0 0FC2D20C */  jal   get_room_data_float2
/* 0F0BF4 7F0BC0C4 E7B20088 */   swc1  $f18, 0x88($sp)
/* 0F0BF8 7F0BC0C8 87A700EA */  lh    $a3, 0xea($sp)
/* 0F0BFC 7F0BC0CC C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0F0C00 7F0BC0D0 44878000 */  mtc1  $a3, $f16
/* 0F0C04 7F0BC0D4 46143282 */  mul.s $f10, $f6, $f20
/* 0F0C08 7F0BC0D8 46808120 */  cvt.s.w $f4, $f16
/* 0F0C0C 7F0BC0DC C7B00098 */  lwc1  $f16, 0x98($sp)
/* 0F0C10 7F0BC0E0 460A2200 */  add.s $f8, $f4, $f10
/* 0F0C14 7F0BC0E4 46004482 */  mul.s $f18, $f8, $f0
/* 0F0C18 7F0BC0E8 46128180 */  add.s $f6, $f16, $f18
/* 0F0C1C 7F0BC0EC 0FC2D20C */  jal   get_room_data_float2
/* 0F0C20 7F0BC0F0 E7A6008C */   swc1  $f6, 0x8c($sp)
/* 0F0C24 7F0BC0F4 87A900EC */  lh    $t1, 0xec($sp)
/* 0F0C28 7F0BC0F8 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 0F0C2C 7F0BC0FC 4405B000 */  mfc1  $a1, $f22
/* 0F0C30 7F0BC100 44892000 */  mtc1  $t1, $f4
/* 0F0C34 7F0BC104 46144402 */  mul.s $f16, $f8, $f20
/* 0F0C38 7F0BC108 4406D000 */  mfc1  $a2, $f26
/* 0F0C3C 7F0BC10C 02002025 */  move  $a0, $s0
/* 0F0C40 7F0BC110 468022A0 */  cvt.s.w $f10, $f4
/* 0F0C44 7F0BC114 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0F0C48 7F0BC118 46105480 */  add.s $f18, $f10, $f16
/* 0F0C4C 7F0BC11C 46009182 */  mul.s $f6, $f18, $f0
/* 0F0C50 7F0BC120 46062200 */  add.s $f8, $f4, $f6
/* 0F0C54 7F0BC124 0FC28858 */  jal   sub_GAME_7F0A2160
/* 0F0C58 7F0BC128 E7A80090 */   swc1  $f8, 0x90($sp)
/* 0F0C5C 7F0BC12C C7AA00A8 */  lwc1  $f10, 0xa8($sp)
/* 0F0C60 7F0BC130 460AA500 */  add.s $f20, $f20, $f10
/* 0F0C64 7F0BC134 4618A03C */  c.lt.s $f20, $f24
/* 0F0C68 7F0BC138 00000000 */  nop   
/* 0F0C6C 7F0BC13C 4501FFD5 */  bc1t  .L7F0BC094
/* 0F0C70 7F0BC140 00000000 */   nop   
/* 0F0C74 7F0BC144 4600B506 */  mov.s $f20, $f22
/* 0F0C78 7F0BC148 4618B03C */  c.lt.s $f22, $f24
.L7F0BC14C:
/* 0F0C7C 7F0BC14C 27B00088 */  addiu $s0, $sp, 0x88
/* 0F0C80 7F0BC150 45020038 */  bc1fl .L7F0BC234
/* 0F0C84 7F0BC154 4618B03C */   c.lt.s $f22, $f24
/* 0F0C88 7F0BC158 44948000 */  mtc1  $s4, $f16
/* 0F0C8C 7F0BC15C 44952000 */  mtc1  $s5, $f4
/* 0F0C90 7F0BC160 44964000 */  mtc1  $s6, $f8
/* 0F0C94 7F0BC164 468084A0 */  cvt.s.w $f18, $f16
/* 0F0C98 7F0BC168 468021A0 */  cvt.s.w $f6, $f4
/* 0F0C9C 7F0BC16C E7B2006C */  swc1  $f18, 0x6c($sp)
/* 0F0CA0 7F0BC170 468042A0 */  cvt.s.w $f10, $f8
/* 0F0CA4 7F0BC174 E7A60068 */  swc1  $f6, 0x68($sp)
/* 0F0CA8 7F0BC178 E7AA0064 */  swc1  $f10, 0x64($sp)
.L7F0BC17C:
/* 0F0CAC 7F0BC17C 0FC2D20C */  jal   get_room_data_float2
/* 0F0CB0 7F0BC180 00000000 */   nop   
/* 0F0CB4 7F0BC184 87A600E0 */  lh    $a2, 0xe0($sp)
/* 0F0CB8 7F0BC188 C7A4006C */  lwc1  $f4, 0x6c($sp)
/* 0F0CBC 7F0BC18C 44868000 */  mtc1  $a2, $f16
/* 0F0CC0 7F0BC190 46142182 */  mul.s $f6, $f4, $f20
/* 0F0CC4 7F0BC194 468084A0 */  cvt.s.w $f18, $f16
/* 0F0CC8 7F0BC198 C7B00094 */  lwc1  $f16, 0x94($sp)
/* 0F0CCC 7F0BC19C 46069200 */  add.s $f8, $f18, $f6
/* 0F0CD0 7F0BC1A0 46004282 */  mul.s $f10, $f8, $f0
/* 0F0CD4 7F0BC1A4 460A8100 */  add.s $f4, $f16, $f10
/* 0F0CD8 7F0BC1A8 0FC2D20C */  jal   get_room_data_float2
/* 0F0CDC 7F0BC1AC E7A40088 */   swc1  $f4, 0x88($sp)
/* 0F0CE0 7F0BC1B0 87A800E2 */  lh    $t0, 0xe2($sp)
/* 0F0CE4 7F0BC1B4 C7A80068 */  lwc1  $f8, 0x68($sp)
/* 0F0CE8 7F0BC1B8 44889000 */  mtc1  $t0, $f18
/* 0F0CEC 7F0BC1BC 46144402 */  mul.s $f16, $f8, $f20
/* 0F0CF0 7F0BC1C0 468091A0 */  cvt.s.w $f6, $f18
/* 0F0CF4 7F0BC1C4 C7B20098 */  lwc1  $f18, 0x98($sp)
/* 0F0CF8 7F0BC1C8 46103280 */  add.s $f10, $f6, $f16
/* 0F0CFC 7F0BC1CC 46005102 */  mul.s $f4, $f10, $f0
/* 0F0D00 7F0BC1D0 46049200 */  add.s $f8, $f18, $f4
/* 0F0D04 7F0BC1D4 0FC2D20C */  jal   get_room_data_float2
/* 0F0D08 7F0BC1D8 E7A8008C */   swc1  $f8, 0x8c($sp)
/* 0F0D0C 7F0BC1DC 87AA00E4 */  lh    $t2, 0xe4($sp)
/* 0F0D10 7F0BC1E0 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0F0D14 7F0BC1E4 4405B000 */  mfc1  $a1, $f22
/* 0F0D18 7F0BC1E8 448A3000 */  mtc1  $t2, $f6
/* 0F0D1C 7F0BC1EC 46145482 */  mul.s $f18, $f10, $f20
/* 0F0D20 7F0BC1F0 4406D000 */  mfc1  $a2, $f26
/* 0F0D24 7F0BC1F4 02002025 */  move  $a0, $s0
/* 0F0D28 7F0BC1F8 46803420 */  cvt.s.w $f16, $f6
/* 0F0D2C 7F0BC1FC C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 0F0D30 7F0BC200 46128100 */  add.s $f4, $f16, $f18
/* 0F0D34 7F0BC204 46002202 */  mul.s $f8, $f4, $f0
/* 0F0D38 7F0BC208 46083280 */  add.s $f10, $f6, $f8
/* 0F0D3C 7F0BC20C 0FC28858 */  jal   sub_GAME_7F0A2160
/* 0F0D40 7F0BC210 E7AA0090 */   swc1  $f10, 0x90($sp)
/* 0F0D44 7F0BC214 C7B000A4 */  lwc1  $f16, 0xa4($sp)
/* 0F0D48 7F0BC218 4610A500 */  add.s $f20, $f20, $f16
/* 0F0D4C 7F0BC21C 4618A03C */  c.lt.s $f20, $f24
/* 0F0D50 7F0BC220 00000000 */  nop   
/* 0F0D54 7F0BC224 4501FFD5 */  bc1t  .L7F0BC17C
/* 0F0D58 7F0BC228 00000000 */   nop   
/* 0F0D5C 7F0BC22C 4600B506 */  mov.s $f20, $f22
/* 0F0D60 7F0BC230 4618B03C */  c.lt.s $f22, $f24
.L7F0BC234:
/* 0F0D64 7F0BC234 00000000 */  nop   
/* 0F0D68 7F0BC238 45020039 */  bc1fl .L7F0BC320
/* 0F0D6C 7F0BC23C 8E530004 */   lw    $s3, 4($s2)
/* 0F0D70 7F0BC240 87AE00B4 */  lh    $t6, 0xb4($sp)
/* 0F0D74 7F0BC244 87AF00AE */  lh    $t7, 0xae($sp)
/* 0F0D78 7F0BC248 44979000 */  mtc1  $s7, $f18
/* 0F0D7C 7F0BC24C 448E3000 */  mtc1  $t6, $f6
/* 0F0D80 7F0BC250 448F5000 */  mtc1  $t7, $f10
/* 0F0D84 7F0BC254 46809120 */  cvt.s.w $f4, $f18
/* 0F0D88 7F0BC258 46803220 */  cvt.s.w $f8, $f6
/* 0F0D8C 7F0BC25C E7A4006C */  swc1  $f4, 0x6c($sp)
/* 0F0D90 7F0BC260 46805420 */  cvt.s.w $f16, $f10
/* 0F0D94 7F0BC264 E7A80068 */  swc1  $f8, 0x68($sp)
/* 0F0D98 7F0BC268 E7B00064 */  swc1  $f16, 0x64($sp)
.L7F0BC26C:
/* 0F0D9C 7F0BC26C 0FC2D20C */  jal   get_room_data_float2
/* 0F0DA0 7F0BC270 00000000 */   nop   
/* 0F0DA4 7F0BC274 87A600E0 */  lh    $a2, 0xe0($sp)
/* 0F0DA8 7F0BC278 C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 0F0DAC 7F0BC27C 44869000 */  mtc1  $a2, $f18
/* 0F0DB0 7F0BC280 46143202 */  mul.s $f8, $f6, $f20
/* 0F0DB4 7F0BC284 46809120 */  cvt.s.w $f4, $f18
/* 0F0DB8 7F0BC288 C7B20094 */  lwc1  $f18, 0x94($sp)
/* 0F0DBC 7F0BC28C 46082280 */  add.s $f10, $f4, $f8
/* 0F0DC0 7F0BC290 46005402 */  mul.s $f16, $f10, $f0
/* 0F0DC4 7F0BC294 46109180 */  add.s $f6, $f18, $f16
/* 0F0DC8 7F0BC298 0FC2D20C */  jal   get_room_data_float2
/* 0F0DCC 7F0BC29C E7A60088 */   swc1  $f6, 0x88($sp)
/* 0F0DD0 7F0BC2A0 87A800E2 */  lh    $t0, 0xe2($sp)
/* 0F0DD4 7F0BC2A4 C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 0F0DD8 7F0BC2A8 44882000 */  mtc1  $t0, $f4
/* 0F0DDC 7F0BC2AC 46145482 */  mul.s $f18, $f10, $f20
/* 0F0DE0 7F0BC2B0 46802220 */  cvt.s.w $f8, $f4
/* 0F0DE4 7F0BC2B4 C7A40098 */  lwc1  $f4, 0x98($sp)
/* 0F0DE8 7F0BC2B8 46124400 */  add.s $f16, $f8, $f18
/* 0F0DEC 7F0BC2BC 46008182 */  mul.s $f6, $f16, $f0
/* 0F0DF0 7F0BC2C0 46062280 */  add.s $f10, $f4, $f6
/* 0F0DF4 7F0BC2C4 0FC2D20C */  jal   get_room_data_float2
/* 0F0DF8 7F0BC2C8 E7AA008C */   swc1  $f10, 0x8c($sp)
/* 0F0DFC 7F0BC2CC 87AA00E4 */  lh    $t2, 0xe4($sp)
/* 0F0E00 7F0BC2D0 C7B00064 */  lwc1  $f16, 0x64($sp)
/* 0F0E04 7F0BC2D4 4405B000 */  mfc1  $a1, $f22
/* 0F0E08 7F0BC2D8 448A4000 */  mtc1  $t2, $f8
/* 0F0E0C 7F0BC2DC 46148102 */  mul.s $f4, $f16, $f20
/* 0F0E10 7F0BC2E0 4406D000 */  mfc1  $a2, $f26
/* 0F0E14 7F0BC2E4 02002025 */  move  $a0, $s0
/* 0F0E18 7F0BC2E8 468044A0 */  cvt.s.w $f18, $f8
/* 0F0E1C 7F0BC2EC C7A8009C */  lwc1  $f8, 0x9c($sp)
/* 0F0E20 7F0BC2F0 46049180 */  add.s $f6, $f18, $f4
/* 0F0E24 7F0BC2F4 46003282 */  mul.s $f10, $f6, $f0
/* 0F0E28 7F0BC2F8 460A4400 */  add.s $f16, $f8, $f10
/* 0F0E2C 7F0BC2FC 0FC28858 */  jal   sub_GAME_7F0A2160
/* 0F0E30 7F0BC300 E7B00090 */   swc1  $f16, 0x90($sp)
/* 0F0E34 7F0BC304 C7B200A0 */  lwc1  $f18, 0xa0($sp)
/* 0F0E38 7F0BC308 4612A500 */  add.s $f20, $f20, $f18
/* 0F0E3C 7F0BC30C 4618A03C */  c.lt.s $f20, $f24
/* 0F0E40 7F0BC310 00000000 */  nop   
/* 0F0E44 7F0BC314 4501FFD5 */  bc1t  .L7F0BC26C
/* 0F0E48 7F0BC318 00000000 */   nop   
/* 0F0E4C 7F0BC31C 8E530004 */  lw    $s3, 4($s2)
.L7F0BC320:
/* 0F0E50 7F0BC320 8E430008 */  lw    $v1, 8($s2)
/* 0F0E54 7F0BC324 24170004 */  li    $s7, 4
/* 0F0E58 7F0BC328 27B600C8 */  addiu $s6, $sp, 0xc8
/* 0F0E5C 7F0BC32C 0263082B */  sltu  $at, $s3, $v1
/* 0F0E60 7F0BC330 10200055 */  beqz  $at, .L7F0BC488
/* 0F0E64 7F0BC334 27B500D0 */   addiu $s5, $sp, 0xd0
/* 0F0E68 7F0BC338 27B400D8 */  addiu $s4, $sp, 0xd8
/* 0F0E6C 7F0BC33C 82620000 */  lb    $v0, ($s3)
.L7F0BC340:
/* 0F0E70 7F0BC340 2401FFBF */  li    $at, -65
/* 0F0E74 7F0BC344 00008025 */  move  $s0, $zero
/* 0F0E78 7F0BC348 14410020 */  bne   $v0, $at, .L7F0BC3CC
/* 0F0E7C 7F0BC34C 02602025 */   move  $a0, $s3
/* 0F0E80 7F0BC350 00002825 */  move  $a1, $zero
/* 0F0E84 7F0BC354 86460000 */  lh    $a2, ($s2)
/* 0F0E88 7F0BC358 02803825 */  move  $a3, $s4
/* 0F0E8C 7F0BC35C AFB50010 */  sw    $s5, 0x10($sp)
/* 0F0E90 7F0BC360 0FC2EE1D */  jal   sub_GAME_7F0BB874
/* 0F0E94 7F0BC364 AFB60014 */   sw    $s6, 0x14($sp)
/* 0F0E98 7F0BC368 02802025 */  move  $a0, $s4
/* 0F0E9C 7F0BC36C 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0EA0 7F0BC370 86450000 */   lh    $a1, ($s2)
/* 0F0EA4 7F0BC374 10400003 */  beqz  $v0, .L7F0BC384
/* 0F0EA8 7F0BC378 02A02025 */   move  $a0, $s5
/* 0F0EAC 7F0BC37C 1000000C */  b     .L7F0BC3B0
/* 0F0EB0 7F0BC380 24100001 */   li    $s0, 1
.L7F0BC384:
/* 0F0EB4 7F0BC384 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0EB8 7F0BC388 86450000 */   lh    $a1, ($s2)
/* 0F0EBC 7F0BC38C 10400003 */  beqz  $v0, .L7F0BC39C
/* 0F0EC0 7F0BC390 02C02025 */   move  $a0, $s6
/* 0F0EC4 7F0BC394 10000006 */  b     .L7F0BC3B0
/* 0F0EC8 7F0BC398 24100001 */   li    $s0, 1
.L7F0BC39C:
/* 0F0ECC 7F0BC39C 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0ED0 7F0BC3A0 86450000 */   lh    $a1, ($s2)
/* 0F0ED4 7F0BC3A4 10400002 */  beqz  $v0, .L7F0BC3B0
/* 0F0ED8 7F0BC3A8 00000000 */   nop   
/* 0F0EDC 7F0BC3AC 24100001 */  li    $s0, 1
.L7F0BC3B0:
/* 0F0EE0 7F0BC3B0 12000004 */  beqz  $s0, .L7F0BC3C4
/* 0F0EE4 7F0BC3B4 02602025 */   move  $a0, $s3
/* 0F0EE8 7F0BC3B8 00002825 */  move  $a1, $zero
/* 0F0EEC 7F0BC3BC 0FC2EEEA */  jal   sub_GAME_7F0BBBA8
/* 0F0EF0 7F0BC3C0 86460000 */   lh    $a2, ($s2)
.L7F0BC3C4:
/* 0F0EF4 7F0BC3C4 10000027 */  b     .L7F0BC464
/* 0F0EF8 7F0BC3C8 8E430008 */   lw    $v1, 8($s2)
.L7F0BC3CC:
/* 0F0EFC 7F0BC3CC 2401FFB1 */  li    $at, -79
/* 0F0F00 7F0BC3D0 14410024 */  bne   $v0, $at, .L7F0BC464
/* 0F0F04 7F0BC3D4 00001025 */   move  $v0, $zero
.L7F0BC3D8:
/* 0F0F08 7F0BC3D8 24510001 */  addiu $s1, $v0, 1
/* 0F0F0C 7F0BC3DC 00008025 */  move  $s0, $zero
/* 0F0F10 7F0BC3E0 02202825 */  move  $a1, $s1
/* 0F0F14 7F0BC3E4 02602025 */  move  $a0, $s3
/* 0F0F18 7F0BC3E8 86460000 */  lh    $a2, ($s2)
/* 0F0F1C 7F0BC3EC 02803825 */  move  $a3, $s4
/* 0F0F20 7F0BC3F0 AFB50010 */  sw    $s5, 0x10($sp)
/* 0F0F24 7F0BC3F4 0FC2EE1D */  jal   sub_GAME_7F0BB874
/* 0F0F28 7F0BC3F8 AFB60014 */   sw    $s6, 0x14($sp)
/* 0F0F2C 7F0BC3FC 02802025 */  move  $a0, $s4
/* 0F0F30 7F0BC400 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0F34 7F0BC404 86450000 */   lh    $a1, ($s2)
/* 0F0F38 7F0BC408 10400003 */  beqz  $v0, .L7F0BC418
/* 0F0F3C 7F0BC40C 02A02025 */   move  $a0, $s5
/* 0F0F40 7F0BC410 1000000C */  b     .L7F0BC444
/* 0F0F44 7F0BC414 24100001 */   li    $s0, 1
.L7F0BC418:
/* 0F0F48 7F0BC418 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0F4C 7F0BC41C 86450000 */   lh    $a1, ($s2)
/* 0F0F50 7F0BC420 10400003 */  beqz  $v0, .L7F0BC430
/* 0F0F54 7F0BC424 02C02025 */   move  $a0, $s6
/* 0F0F58 7F0BC428 10000006 */  b     .L7F0BC444
/* 0F0F5C 7F0BC42C 24100001 */   li    $s0, 1
.L7F0BC430:
/* 0F0F60 7F0BC430 0FC2EF33 */  jal   sub_GAME_7F0BBCCC
/* 0F0F64 7F0BC434 86450000 */   lh    $a1, ($s2)
/* 0F0F68 7F0BC438 10400002 */  beqz  $v0, .L7F0BC444
/* 0F0F6C 7F0BC43C 00000000 */   nop   
/* 0F0F70 7F0BC440 24100001 */  li    $s0, 1
.L7F0BC444:
/* 0F0F74 7F0BC444 12000004 */  beqz  $s0, .L7F0BC458
/* 0F0F78 7F0BC448 02602025 */   move  $a0, $s3
/* 0F0F7C 7F0BC44C 02202825 */  move  $a1, $s1
/* 0F0F80 7F0BC450 0FC2EEEA */  jal   sub_GAME_7F0BBBA8
/* 0F0F84 7F0BC454 86460000 */   lh    $a2, ($s2)
.L7F0BC458:
/* 0F0F88 7F0BC458 1637FFDF */  bne   $s1, $s7, .L7F0BC3D8
/* 0F0F8C 7F0BC45C 02201025 */   move  $v0, $s1
/* 0F0F90 7F0BC460 8E430008 */  lw    $v1, 8($s2)
.L7F0BC464:
/* 0F0F94 7F0BC464 26730008 */  addiu $s3, $s3, 8
/* 0F0F98 7F0BC468 0263082B */  sltu  $at, $s3, $v1
/* 0F0F9C 7F0BC46C 5420FFB4 */  bnezl $at, .L7F0BC340
/* 0F0FA0 7F0BC470 82620000 */   lb    $v0, ($s3)
/* 0F0FA4 7F0BC474 10000005 */  b     .L7F0BC48C
/* 0F0FA8 7F0BC478 8FBF005C */   lw    $ra, 0x5c($sp)
.L7F0BC47C:
/* 0F0FAC 7F0BC47C 2652000C */  addiu $s2, $s2, 0xc
.L7F0BC480:
/* 0F0FB0 7F0BC480 5642FE78 */  bnel  $s2, $v0, .L7F0BBE64
/* 0F0FB4 7F0BC484 86460000 */   lh    $a2, ($s2)
.L7F0BC488:
/* 0F0FB8 7F0BC488 8FBF005C */  lw    $ra, 0x5c($sp)
.L7F0BC48C:
/* 0F0FBC 7F0BC48C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0F0FC0 7F0BC490 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0F0FC4 7F0BC494 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0F0FC8 7F0BC498 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0F0FCC 7F0BC49C 8FB0003C */  lw    $s0, 0x3c($sp)
/* 0F0FD0 7F0BC4A0 8FB10040 */  lw    $s1, 0x40($sp)
/* 0F0FD4 7F0BC4A4 8FB20044 */  lw    $s2, 0x44($sp)
/* 0F0FD8 7F0BC4A8 8FB30048 */  lw    $s3, 0x48($sp)
/* 0F0FDC 7F0BC4AC 8FB4004C */  lw    $s4, 0x4c($sp)
/* 0F0FE0 7F0BC4B0 8FB50050 */  lw    $s5, 0x50($sp)
/* 0F0FE4 7F0BC4B4 8FB60054 */  lw    $s6, 0x54($sp)
/* 0F0FE8 7F0BC4B8 8FB70058 */  lw    $s7, 0x58($sp)
/* 0F0FEC 7F0BC4BC 03E00008 */  jr    $ra
/* 0F0FF0 7F0BC4C0 27BD00F8 */   addiu $sp, $sp, 0xf8
)
#endif


void sub_GAME_7F0BC4C4(s32 arg0)
{
    s32 i;
    for (i = 0; i < LIGHTFIXTURE_TABLE_MAX; i++)
    {
        if (arg0 == light_fixture_table[i].index)
        {
            light_fixture_table[i].index = 0;
        }
    }
    index_of_cur_entry_lightfixture_table = arg0;
}

