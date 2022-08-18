#include <ultra64.h>
#include <memp.h>
#include <fr.h>
#include <random.h>
#include "player.h"
#include "unk_092E50.h"
#include "bondview.h"
#include "lvl.h"
#include "player_2.h"


//newfile per EU

void default_player_perspective_and_height(void)
{
  float value  = 1.0f;

  if (0) { }

  g_playerPlayerData[0].player_perspective_height = value;
  g_playerPlayerData[0].handicap = value;
  g_playerPlayerData[1].player_perspective_height = value;
  g_playerPlayerData[1].handicap = value;
  g_playerPlayerData[2].player_perspective_height = value;
  g_playerPlayerData[2].handicap = value;
  g_playerPlayerData[3].player_perspective_height = value;
  g_playerPlayerData[3].handicap = value;
}

void reset_play_data_ptrs(void) 
{
    g_playerPointers[0] = 0;
    g_playerPointers[1] = 0;
    g_playerPointers[2] = 0;
    g_playerPointers[3] = 0;
    g_CurrentPlayer = 0;
    g_playerPerm = 0;
    player_num = 0;
    random_byte = 0;
    array_PLAYER_IDs[0] = 0;
    array_PLAYER_IDs[1] = 1;
    array_PLAYER_IDs[2] = 2;
    array_PLAYER_IDs[3] = 3;
}

void init_player_data_ptrs_construct_viewports(s32 playercount)
{
    s32 i;

    g_playerPointers[0] = NULL;
    g_playerPointers[1] = NULL;
    g_playerPointers[2] = NULL;
    g_playerPointers[3] = NULL;
    random_byte = (s32) (randomGetNext() & 0xFF);
    if (playercount > 0)
    {
        for (i = 0; i < playercount; i++)
        {
            initBONDdataforPlayer(i);
        }
        set_cur_player(0);
        return;
    }
    initBONDdataforPlayer(0);
    set_cur_player(0);
    set_cur_player_screen_size(viGetViewWidth(), viGetViewHeight());
    set_cur_player_viewport_size(viGetViewLeft(), viGetViewTop());
}

s32 getPlayerCount(void)
{
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (g_playerPointers[i] != NULL) {
            count++;
        }
    }
    return count;
}

#if defined(VERSION_EU)
GLOBAL_ASM(
.late_rodata
glabel D_80057610
.word 0xc3652ee0 /*-229.18311*/
glabel D_80057614
.word 0x4106ae1e
glabel D_80057618
.word 0x3f6aa64c
glabel D_8005761C
.word 0x413fd8b4
glabel D_80057620
.word 0x3f666666 /*0.89999998*/
glabel D_80057624
.word 0xc0490fdb /*-3.1415927*/
glabel D_80057628
.word 0x3f969697
.text
glabel initBONDdataforPlayer
/* 0CC3EC 7F0999FC 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 0CC3F0 7F099A00 3C0F8004 */  lui   $t7, %hi(D_8003FD94+0xC) # $t7, 0x8004
/* 0CC3F4 7F099A04 25EF99F0 */  addiu $t7, %lo(D_8003FD94+0xC) # addiu $t7, $t7, -0x6610
/* 0CC3F8 7F099A08 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CC3FC 7F099A0C AFA403D0 */  sw    $a0, 0x3d0($sp)
/* 0CC400 7F099A10 25EB03A8 */  addiu $t3, $t7, 0x3a8
/* 0CC404 7F099A14 27AE0024 */  addiu $t6, $sp, 0x24
.L7F099A18:
/* 0CC408 7F099A18 8DE10000 */  lw    $at, ($t7)
/* 0CC40C 7F099A1C 25EF000C */  addiu $t7, $t7, 0xc
/* 0CC410 7F099A20 25CE000C */  addiu $t6, $t6, 0xc
/* 0CC414 7F099A24 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 0CC418 7F099A28 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CC41C 7F099A2C ADC1FFF8 */  sw    $at, -8($t6)
/* 0CC420 7F099A30 8DE1FFFC */  lw    $at, -4($t7)
/* 0CC424 7F099A34 15EBFFF8 */  bne   $t7, $t3, .L7F099A18
/* 0CC428 7F099A38 ADC1FFFC */   sw    $at, -4($t6)
/* 0CC42C 7F099A3C 24042A70 */  li    $a0, 10864
/* 0CC430 7F099A40 0C0022E0 */  jal   mempAllocBytesInBank
/* 0CC434 7F099A44 24050004 */   li    $a1, 4
/* 0CC438 7F099A48 8FAC03D0 */  lw    $t4, 0x3d0($sp)
/* 0CC43C 7F099A4C 3C198007 */  lui   $t9, %hi(g_playerPointers) # $t9, 0x8007
/* 0CC440 7F099A50 273989F0 */  addiu $t9, %lo(g_playerPointers) # addiu $t9, $t9, -0x7610
/* 0CC444 7F099A54 000C6880 */  sll   $t5, $t4, 2
/* 0CC448 7F099A58 01B91821 */  addu  $v1, $t5, $t9
/* 0CC44C 7F099A5C AC620000 */  sw    $v0, ($v1)
/* 0CC450 7F099A60 AC400000 */  sw    $zero, ($v0)
/* 0CC454 7F099A64 44800000 */  mtc1  $zero, $f0
/* 0CC458 7F099A68 8C780000 */  lw    $t8, ($v1)
/* 0CC45C 7F099A6C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CC460 7F099A70 44811000 */  mtc1  $at, $f2
/* 0CC464 7F099A74 E7000004 */  swc1  $f0, 4($t8)
/* 0CC468 7F099A78 8C6B0000 */  lw    $t3, ($v1)
/* 0CC46C 7F099A7C 24040002 */  li    $a0, 2
/* 0CC470 7F099A80 24080001 */  li    $t0, 1
/* 0CC474 7F099A84 E5600008 */  swc1  $f0, 8($t3)
/* 0CC478 7F099A88 8C6F0000 */  lw    $t7, ($v1)
/* 0CC47C 7F099A8C 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CC480 7F099A90 44816000 */  mtc1  $at, $f12
/* 0CC484 7F099A94 E5E0000C */  swc1  $f0, 0xc($t7)
/* 0CC488 7F099A98 8C6E0000 */  lw    $t6, ($v1)
/* 0CC48C 7F099A9C 2409FFFF */  li    $t1, -1
/* 0CC490 7F099AA0 3C01C080 */  li    $at, 0xC0800000 # -4.000000
/* 0CC494 7F099AA4 E5C00010 */  swc1  $f0, 0x10($t6)
/* 0CC498 7F099AA8 8C6C0000 */  lw    $t4, ($v1)
/* 0CC49C 7F099AAC 44812000 */  mtc1  $at, $f4
/* 0CC4A0 7F099AB0 3C018005 */  lui   $at, %hi(D_80057610)
/* 0CC4A4 7F099AB4 E5800014 */  swc1  $f0, 0x14($t4)
/* 0CC4A8 7F099AB8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC4AC 7F099ABC 240200FF */  li    $v0, 255
/* 0CC4B0 7F099AC0 27AA0024 */  addiu $t2, $sp, 0x24
/* 0CC4B4 7F099AC4 E5A20018 */  swc1  $f2, 0x18($t5)
/* 0CC4B8 7F099AC8 8C790000 */  lw    $t9, ($v1)
/* 0CC4BC 7F099ACC E720001C */  swc1  $f0, 0x1c($t9)
/* 0CC4C0 7F099AD0 8C780000 */  lw    $t8, ($v1)
/* 0CC4C4 7F099AD4 E7020020 */  swc1  $f2, 0x20($t8)
/* 0CC4C8 7F099AD8 8C6B0000 */  lw    $t3, ($v1)
/* 0CC4CC 7F099ADC E5600024 */  swc1  $f0, 0x24($t3)
/* 0CC4D0 7F099AE0 8C6F0000 */  lw    $t7, ($v1)
/* 0CC4D4 7F099AE4 E5E00028 */  swc1  $f0, 0x28($t7)
/* 0CC4D8 7F099AE8 8C6E0000 */  lw    $t6, ($v1)
/* 0CC4DC 7F099AEC E5C0002C */  swc1  $f0, 0x2c($t6)
/* 0CC4E0 7F099AF0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC4E4 7F099AF4 E5800030 */  swc1  $f0, 0x30($t4)
/* 0CC4E8 7F099AF8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC4EC 7F099AFC ADA00034 */  sw    $zero, 0x34($t5)
/* 0CC4F0 7F099B00 8C790000 */  lw    $t9, ($v1)
/* 0CC4F4 7F099B04 E7200038 */  swc1  $f0, 0x38($t9)
/* 0CC4F8 7F099B08 8C780000 */  lw    $t8, ($v1)
/* 0CC4FC 7F099B0C E700003C */  swc1  $f0, 0x3c($t8)
/* 0CC500 7F099B10 8C6B0000 */  lw    $t3, ($v1)
/* 0CC504 7F099B14 E5600040 */  swc1  $f0, 0x40($t3)
/* 0CC508 7F099B18 8C6F0000 */  lw    $t7, ($v1)
/* 0CC50C 7F099B1C E5E00044 */  swc1  $f0, 0x44($t7)
/* 0CC510 7F099B20 8C6E0000 */  lw    $t6, ($v1)
/* 0CC514 7F099B24 E5C00048 */  swc1  $f0, 0x48($t6)
/* 0CC518 7F099B28 8C6C0000 */  lw    $t4, ($v1)
/* 0CC51C 7F099B2C E580004C */  swc1  $f0, 0x4c($t4)
/* 0CC520 7F099B30 8C6D0000 */  lw    $t5, ($v1)
/* 0CC524 7F099B34 E5A00050 */  swc1  $f0, 0x50($t5)
/* 0CC528 7F099B38 8C790000 */  lw    $t9, ($v1)
/* 0CC52C 7F099B3C E7200054 */  swc1  $f0, 0x54($t9)
/* 0CC530 7F099B40 8C780000 */  lw    $t8, ($v1)
/* 0CC534 7F099B44 E7000058 */  swc1  $f0, 0x58($t8)
/* 0CC538 7F099B48 8C6B0000 */  lw    $t3, ($v1)
/* 0CC53C 7F099B4C E560006C */  swc1  $f0, 0x6c($t3)
/* 0CC540 7F099B50 8C6F0000 */  lw    $t7, ($v1)
/* 0CC544 7F099B54 E5E00070 */  swc1  $f0, 0x70($t7)
/* 0CC548 7F099B58 8C6E0000 */  lw    $t6, ($v1)
/* 0CC54C 7F099B5C E5C00074 */  swc1  $f0, 0x74($t6)
/* 0CC550 7F099B60 8C6C0000 */  lw    $t4, ($v1)
/* 0CC554 7F099B64 E5800078 */  swc1  $f0, 0x78($t4)
/* 0CC558 7F099B68 8C6D0000 */  lw    $t5, ($v1)
/* 0CC55C 7F099B6C E5A0007C */  swc1  $f0, 0x7c($t5)
/* 0CC560 7F099B70 8C790000 */  lw    $t9, ($v1)
/* 0CC564 7F099B74 E7200080 */  swc1  $f0, 0x80($t9)
/* 0CC568 7F099B78 8C780000 */  lw    $t8, ($v1)
/* 0CC56C 7F099B7C E7000084 */  swc1  $f0, 0x84($t8)
/* 0CC570 7F099B80 8C6B0000 */  lw    $t3, ($v1)
/* 0CC574 7F099B84 E5600088 */  swc1  $f0, 0x88($t3)
/* 0CC578 7F099B88 8C6F0000 */  lw    $t7, ($v1)
/* 0CC57C 7F099B8C ADE0008C */  sw    $zero, 0x8c($t7)
/* 0CC580 7F099B90 8C6E0000 */  lw    $t6, ($v1)
/* 0CC584 7F099B94 E5C00090 */  swc1  $f0, 0x90($t6)
/* 0CC588 7F099B98 8C6C0000 */  lw    $t4, ($v1)
/* 0CC58C 7F099B9C AD800094 */  sw    $zero, 0x94($t4)
/* 0CC590 7F099BA0 8C6D0000 */  lw    $t5, ($v1)
/* 0CC594 7F099BA4 E5A00098 */  swc1  $f0, 0x98($t5)
/* 0CC598 7F099BA8 8C790000 */  lw    $t9, ($v1)
/* 0CC59C 7F099BAC E720126C */  swc1  $f0, 0x126c($t9)
/* 0CC5A0 7F099BB0 8C780000 */  lw    $t8, ($v1)
/* 0CC5A4 7F099BB4 E7001270 */  swc1  $f0, 0x1270($t8)
/* 0CC5A8 7F099BB8 8C6B0000 */  lw    $t3, ($v1)
/* 0CC5AC 7F099BBC E5601274 */  swc1  $f0, 0x1274($t3)
/* 0CC5B0 7F099BC0 8C6F0000 */  lw    $t7, ($v1)
/* 0CC5B4 7F099BC4 ADE4009C */  sw    $a0, 0x9c($t7)
/* 0CC5B8 7F099BC8 8C6E0000 */  lw    $t6, ($v1)
/* 0CC5BC 7F099BCC ADC429F4 */  sw    $a0, 0x29f4($t6)
/* 0CC5C0 7F099BD0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC5C4 7F099BD4 E58000A0 */  swc1  $f0, 0xa0($t4)
/* 0CC5C8 7F099BD8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC5CC 7F099BDC E5A000A4 */  swc1  $f0, 0xa4($t5)
/* 0CC5D0 7F099BE0 8C790000 */  lw    $t9, ($v1)
/* 0CC5D4 7F099BE4 AF2000A8 */  sw    $zero, 0xa8($t9)
/* 0CC5D8 7F099BE8 8C780000 */  lw    $t8, ($v1)
/* 0CC5DC 7F099BEC AF0800AC */  sw    $t0, 0xac($t8)
/* 0CC5E0 7F099BF0 8C6B0000 */  lw    $t3, ($v1)
/* 0CC5E4 7F099BF4 AD6000D0 */  sw    $zero, 0xd0($t3)
/* 0CC5E8 7F099BF8 8C6F0000 */  lw    $t7, ($v1)
/* 0CC5EC 7F099BFC ADE000D4 */  sw    $zero, 0xd4($t7)
/* 0CC5F0 7F099C00 8C6E0000 */  lw    $t6, ($v1)
/* 0CC5F4 7F099C04 ADC000D8 */  sw    $zero, 0xd8($t6)
/* 0CC5F8 7F099C08 8C6C0000 */  lw    $t4, ($v1)
/* 0CC5FC 7F099C0C E58200DC */  swc1  $f2, 0xdc($t4)
/* 0CC600 7F099C10 8C6D0000 */  lw    $t5, ($v1)
/* 0CC604 7F099C14 E5A000E0 */  swc1  $f0, 0xe0($t5)
/* 0CC608 7F099C18 8C790000 */  lw    $t9, ($v1)
/* 0CC60C 7F099C1C E72200E4 */  swc1  $f2, 0xe4($t9)
/* 0CC610 7F099C20 8C780000 */  lw    $t8, ($v1)
/* 0CC614 7F099C24 E70000E8 */  swc1  $f0, 0xe8($t8)
/* 0CC618 7F099C28 8C6B0000 */  lw    $t3, ($v1)
/* 0CC61C 7F099C2C E56200EC */  swc1  $f2, 0xec($t3)
/* 0CC620 7F099C30 8C6F0000 */  lw    $t7, ($v1)
/* 0CC624 7F099C34 E5E000F0 */  swc1  $f0, 0xf0($t7)
/* 0CC628 7F099C38 8C6E0000 */  lw    $t6, ($v1)
/* 0CC62C 7F099C3C E5CC00F4 */  swc1  $f12, 0xf4($t6)
/* 0CC630 7F099C40 8C6C0000 */  lw    $t4, ($v1)
/* 0CC634 7F099C44 E58C00F8 */  swc1  $f12, 0xf8($t4)
/* 0CC638 7F099C48 8C6D0000 */  lw    $t5, ($v1)
/* 0CC63C 7F099C4C ADA00104 */  sw    $zero, 0x104($t5)
/* 0CC640 7F099C50 8C790000 */  lw    $t9, ($v1)
/* 0CC644 7F099C54 AF200108 */  sw    $zero, 0x108($t9)
/* 0CC648 7F099C58 8C780000 */  lw    $t8, ($v1)
/* 0CC64C 7F099C5C AF00010C */  sw    $zero, 0x10c($t8)
/* 0CC650 7F099C60 8C6B0000 */  lw    $t3, ($v1)
/* 0CC654 7F099C64 AD600110 */  sw    $zero, 0x110($t3)
/* 0CC658 7F099C68 8C6F0000 */  lw    $t7, ($v1)
/* 0CC65C 7F099C6C ADE80114 */  sw    $t0, 0x114($t7)
/* 0CC660 7F099C70 8C6E0000 */  lw    $t6, ($v1)
/* 0CC664 7F099C74 ADC80118 */  sw    $t0, 0x118($t6)
/* 0CC668 7F099C78 8C6C0000 */  lw    $t4, ($v1)
/* 0CC66C 7F099C7C AD80011C */  sw    $zero, 0x11c($t4)
/* 0CC670 7F099C80 8C6D0000 */  lw    $t5, ($v1)
/* 0CC674 7F099C84 ADA80120 */  sw    $t0, 0x120($t5)
/* 0CC678 7F099C88 8C790000 */  lw    $t9, ($v1)
/* 0CC67C 7F099C8C AF200124 */  sw    $zero, 0x124($t9)
/* 0CC680 7F099C90 8C780000 */  lw    $t8, ($v1)
/* 0CC684 7F099C94 AF080128 */  sw    $t0, 0x128($t8)
/* 0CC688 7F099C98 8C6B0000 */  lw    $t3, ($v1)
/* 0CC68C 7F099C9C E560012C */  swc1  $f0, 0x12c($t3)
/* 0CC690 7F099CA0 8C6F0000 */  lw    $t7, ($v1)
/* 0CC694 7F099CA4 ADE00130 */  sw    $zero, 0x130($t7)
/* 0CC698 7F099CA8 8C6E0000 */  lw    $t6, ($v1)
/* 0CC69C 7F099CAC ADC90134 */  sw    $t1, 0x134($t6)
/* 0CC6A0 7F099CB0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC6A4 7F099CB4 AD880138 */  sw    $t0, 0x138($t4)
/* 0CC6A8 7F099CB8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC6AC 7F099CBC E5A0013C */  swc1  $f0, 0x13c($t5)
/* 0CC6B0 7F099CC0 8C790000 */  lw    $t9, ($v1)
/* 0CC6B4 7F099CC4 AF200140 */  sw    $zero, 0x140($t9)
/* 0CC6B8 7F099CC8 8C780000 */  lw    $t8, ($v1)
/* 0CC6BC 7F099CCC AF090144 */  sw    $t1, 0x144($t8)
/* 0CC6C0 7F099CD0 8C6B0000 */  lw    $t3, ($v1)
/* 0CC6C4 7F099CD4 E5600148 */  swc1  $f0, 0x148($t3)
/* 0CC6C8 7F099CD8 8C6F0000 */  lw    $t7, ($v1)
/* 0CC6CC 7F099CDC E5E0014C */  swc1  $f0, 0x14c($t7)
/* 0CC6D0 7F099CE0 8C6E0000 */  lw    $t6, ($v1)
/* 0CC6D4 7F099CE4 E5C20150 */  swc1  $f2, 0x150($t6)
/* 0CC6D8 7F099CE8 8C6C0000 */  lw    $t4, ($v1)
/* 0CC6DC 7F099CEC E5800154 */  swc1  $f0, 0x154($t4)
/* 0CC6E0 7F099CF0 8C6D0000 */  lw    $t5, ($v1)
/* 0CC6E4 7F099CF4 E5A40158 */  swc1  $f4, 0x158($t5)
/* 0CC6E8 7F099CF8 8C790000 */  lw    $t9, ($v1)
/* 0CC6EC 7F099CFC C426CCD0 */  lwc1  $f6, %lo(D_80057610)($at)
/* 0CC6F0 7F099D00 3C01C1C8 */  li    $at, 0xC1C80000 # -25.000000
/* 0CC6F4 7F099D04 44814000 */  mtc1  $at, $f8
/* 0CC6F8 7F099D08 E726015C */  swc1  $f6, 0x15c($t9)
/* 0CC6FC 7F099D0C 8C780000 */  lw    $t8, ($v1)
/* 0CC700 7F099D10 3C018005 */  lui   $at, %hi(D_80057614) # $at, 0x8005
/* 0CC704 7F099D14 E7000160 */  swc1  $f0, 0x160($t8)
/* 0CC708 7F099D18 8C6B0000 */  lw    $t3, ($v1)
/* 0CC70C 7F099D1C E5620164 */  swc1  $f2, 0x164($t3)
/* 0CC710 7F099D20 8C6F0000 */  lw    $t7, ($v1)
/* 0CC714 7F099D24 E5E00168 */  swc1  $f0, 0x168($t7)
/* 0CC718 7F099D28 8C6E0000 */  lw    $t6, ($v1)
/* 0CC71C 7F099D2C E5C0016C */  swc1  $f0, 0x16c($t6)
/* 0CC720 7F099D30 8C6C0000 */  lw    $t4, ($v1)
/* 0CC724 7F099D34 E5800170 */  swc1  $f0, 0x170($t4)
/* 0CC728 7F099D38 8C6D0000 */  lw    $t5, ($v1)
/* 0CC72C 7F099D3C E5A00174 */  swc1  $f0, 0x174($t5)
/* 0CC730 7F099D40 8C790000 */  lw    $t9, ($v1)
/* 0CC734 7F099D44 E7202A44 */  swc1  $f0, 0x2a44($t9)
/* 0CC738 7F099D48 8C780000 */  lw    $t8, ($v1)
/* 0CC73C 7F099D4C E7020178 */  swc1  $f2, 0x178($t8)
/* 0CC740 7F099D50 8C6B0000 */  lw    $t3, ($v1)
/* 0CC744 7F099D54 E5600180 */  swc1  $f0, 0x180($t3)
/* 0CC748 7F099D58 8C6F0000 */  lw    $t7, ($v1)
/* 0CC74C 7F099D5C E5E00184 */  swc1  $f0, 0x184($t7)
/* 0CC750 7F099D60 8C6E0000 */  lw    $t6, ($v1)
/* 0CC754 7F099D64 E5C00188 */  swc1  $f0, 0x188($t6)
/* 0CC758 7F099D68 8C6C0000 */  lw    $t4, ($v1)
/* 0CC75C 7F099D6C E58C018C */  swc1  $f12, 0x18c($t4)
/* 0CC760 7F099D70 8C6D0000 */  lw    $t5, ($v1)
/* 0CC764 7F099D74 E5AC0190 */  swc1  $f12, 0x190($t5)
/* 0CC768 7F099D78 8C790000 */  lw    $t9, ($v1)
/* 0CC76C 7F099D7C E7200194 */  swc1  $f0, 0x194($t9)
/* 0CC770 7F099D80 8C780000 */  lw    $t8, ($v1)
/* 0CC774 7F099D84 E7000198 */  swc1  $f0, 0x198($t8)
/* 0CC778 7F099D88 8C6B0000 */  lw    $t3, ($v1)
/* 0CC77C 7F099D8C E560019C */  swc1  $f0, 0x19c($t3)
/* 0CC780 7F099D90 8C6F0000 */  lw    $t7, ($v1)
/* 0CC784 7F099D94 ADE001A0 */  sw    $zero, 0x1a0($t7)
/* 0CC788 7F099D98 8C6E0000 */  lw    $t6, ($v1)
/* 0CC78C 7F099D9C ADC001C0 */  sw    $zero, 0x1c0($t6)
/* 0CC790 7F099DA0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC794 7F099DA4 AD8001C4 */  sw    $zero, 0x1c4($t4)
/* 0CC798 7F099DA8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC79C 7F099DAC ADA001C8 */  sw    $zero, 0x1c8($t5)
/* 0CC7A0 7F099DB0 8C790000 */  lw    $t9, ($v1)
/* 0CC7A4 7F099DB4 AF2801CC */  sw    $t0, 0x1cc($t9)
/* 0CC7A8 7F099DB8 8C780000 */  lw    $t8, ($v1)
/* 0CC7AC 7F099DBC AF0001D0 */  sw    $zero, 0x1d0($t8)
/* 0CC7B0 7F099DC0 8C6B0000 */  lw    $t3, ($v1)
/* 0CC7B4 7F099DC4 E56001D4 */  swc1  $f0, 0x1d4($t3)
/* 0CC7B8 7F099DC8 8C6F0000 */  lw    $t7, ($v1)
/* 0CC7BC 7F099DCC E5E001D8 */  swc1  $f0, 0x1d8($t7)
/* 0CC7C0 7F099DD0 8C6E0000 */  lw    $t6, ($v1)
/* 0CC7C4 7F099DD4 E5C801DC */  swc1  $f8, 0x1dc($t6)
/* 0CC7C8 7F099DD8 8C6C0000 */  lw    $t4, ($v1)
/* 0CC7CC 7F099DDC E58001E0 */  swc1  $f0, 0x1e0($t4)
/* 0CC7D0 7F099DE0 8C6D0000 */  lw    $t5, ($v1)
/* 0CC7D4 7F099DE4 E5A201E4 */  swc1  $f2, 0x1e4($t5)
/* 0CC7D8 7F099DE8 8C790000 */  lw    $t9, ($v1)
/* 0CC7DC 7F099DEC E72001E8 */  swc1  $f0, 0x1e8($t9)
/* 0CC7E0 7F099DF0 8C780000 */  lw    $t8, ($v1)
/* 0CC7E4 7F099DF4 E70001EC */  swc1  $f0, 0x1ec($t8)
/* 0CC7E8 7F099DF8 8C6B0000 */  lw    $t3, ($v1)
/* 0CC7EC 7F099DFC E56001F0 */  swc1  $f0, 0x1f0($t3)
/* 0CC7F0 7F099E00 8C6F0000 */  lw    $t7, ($v1)
/* 0CC7F4 7F099E04 E5E201F4 */  swc1  $f2, 0x1f4($t7)
/* 0CC7F8 7F099E08 8C6E0000 */  lw    $t6, ($v1)
/* 0CC7FC 7F099E0C ADC00200 */  sw    $zero, 0x200($t6)
/* 0CC800 7F099E10 8C6C0000 */  lw    $t4, ($v1)
/* 0CC804 7F099E14 E5800204 */  swc1  $f0, 0x204($t4)
/* 0CC808 7F099E18 8C6D0000 */  lw    $t5, ($v1)
/* 0CC80C 7F099E1C E5A00208 */  swc1  $f0, 0x208($t5)
/* 0CC810 7F099E20 8C790000 */  lw    $t9, ($v1)
/* 0CC814 7F099E24 E720020C */  swc1  $f0, 0x20c($t9)
/* 0CC818 7F099E28 8C780000 */  lw    $t8, ($v1)
/* 0CC81C 7F099E2C E7000210 */  swc1  $f0, 0x210($t8)
/* 0CC820 7F099E30 8C6B0000 */  lw    $t3, ($v1)
/* 0CC824 7F099E34 E5600214 */  swc1  $f0, 0x214($t3)
/* 0CC828 7F099E38 8C6F0000 */  lw    $t7, ($v1)
/* 0CC82C 7F099E3C ADE00218 */  sw    $zero, 0x218($t7)
/* 0CC830 7F099E40 8C6E0000 */  lw    $t6, ($v1)
/* 0CC834 7F099E44 ADC8021C */  sw    $t0, 0x21c($t6)
/* 0CC838 7F099E48 8C6C0000 */  lw    $t4, ($v1)
/* 0CC83C 7F099E4C AD800220 */  sw    $zero, 0x220($t4)
/* 0CC840 7F099E50 8C6D0000 */  lw    $t5, ($v1)
/* 0CC844 7F099E54 E5A00224 */  swc1  $f0, 0x224($t5)
/* 0CC848 7F099E58 8C790000 */  lw    $t9, ($v1)
/* 0CC84C 7F099E5C A72003B4 */  sh    $zero, 0x3b4($t9)
/* 0CC850 7F099E60 8C780000 */  lw    $t8, ($v1)
/* 0CC854 7F099E64 A70003B6 */  sh    $zero, 0x3b6($t8)
/* 0CC858 7F099E68 8C6B0000 */  lw    $t3, ($v1)
/* 0CC85C 7F099E6C E56003B8 */  swc1  $f0, 0x3b8($t3)
/* 0CC860 7F099E70 8C6F0000 */  lw    $t7, ($v1)
/* 0CC864 7F099E74 E5E003BC */  swc1  $f0, 0x3bc($t7)
/* 0CC868 7F099E78 8C6E0000 */  lw    $t6, ($v1)
/* 0CC86C 7F099E7C C42ACCD4 */  lwc1  $f10, %lo(D_80057614)($at)
/* 0CC870 7F099E80 E5CA03C0 */  swc1  $f10, 0x3c0($t6)
/* 0CC874 7F099E84 8C6C0000 */  lw    $t4, ($v1)
/* 0CC878 7F099E88 E58003C4 */  swc1  $f0, 0x3c4($t4)
/* 0CC87C 7F099E8C 8C6D0000 */  lw    $t5, ($v1)
/* 0CC880 7F099E90 E5A003C8 */  swc1  $f0, 0x3c8($t5)
/* 0CC884 7F099E94 8C790000 */  lw    $t9, ($v1)
/* 0CC888 7F099E98 E72203CC */  swc1  $f2, 0x3cc($t9)
/* 0CC88C 7F099E9C 8C780000 */  lw    $t8, ($v1)
/* 0CC890 7F099EA0 AF0203D0 */  sw    $v0, 0x3d0($t8)
/* 0CC894 7F099EA4 8C6B0000 */  lw    $t3, ($v1)
/* 0CC898 7F099EA8 AD6203D4 */  sw    $v0, 0x3d4($t3)
/* 0CC89C 7F099EAC 8C6F0000 */  lw    $t7, ($v1)
/* 0CC8A0 7F099EB0 3C018005 */  lui   $at, %hi(D_80057618) # $at, 0x8005
/* 0CC8A4 7F099EB4 24070020 */  li    $a3, 32
/* 0CC8A8 7F099EB8 ADE203D8 */  sw    $v0, 0x3d8($t7)
/* 0CC8AC 7F099EBC 8C6E0000 */  lw    $t6, ($v1)
/* 0CC8B0 7F099EC0 240601FF */  li    $a2, 511
/* 0CC8B4 7F099EC4 24050220 */  li    $a1, 544
/* 0CC8B8 7F099EC8 E5C003DC */  swc1  $f0, 0x3dc($t6)
/* 0CC8BC 7F099ECC 8C6C0000 */  lw    $t4, ($v1)
/* 0CC8C0 7F099ED0 E58C03E0 */  swc1  $f12, 0x3e0($t4)
/* 0CC8C4 7F099ED4 8C6D0000 */  lw    $t5, ($v1)
/* 0CC8C8 7F099ED8 E5AC03E4 */  swc1  $f12, 0x3e4($t5)
/* 0CC8CC 7F099EDC 8C790000 */  lw    $t9, ($v1)
/* 0CC8D0 7F099EE0 AF2203E8 */  sw    $v0, 0x3e8($t9)
/* 0CC8D4 7F099EE4 8C780000 */  lw    $t8, ($v1)
/* 0CC8D8 7F099EE8 AF0203EC */  sw    $v0, 0x3ec($t8)
/* 0CC8DC 7F099EEC 8C6B0000 */  lw    $t3, ($v1)
/* 0CC8E0 7F099EF0 AD6203F0 */  sw    $v0, 0x3f0($t3)
/* 0CC8E4 7F099EF4 8C6F0000 */  lw    $t7, ($v1)
/* 0CC8E8 7F099EF8 ADE203F4 */  sw    $v0, 0x3f4($t7)
/* 0CC8EC 7F099EFC 8C6E0000 */  lw    $t6, ($v1)
/* 0CC8F0 7F099F00 ADC203F8 */  sw    $v0, 0x3f8($t6)
/* 0CC8F4 7F099F04 8C6C0000 */  lw    $t4, ($v1)
/* 0CC8F8 7F099F08 AD8203FC */  sw    $v0, 0x3fc($t4)
/* 0CC8FC 7F099F0C 8C6D0000 */  lw    $t5, ($v1)
/* 0CC900 7F099F10 00001025 */  move  $v0, $zero
/* 0CC904 7F099F14 E5A00400 */  swc1  $f0, 0x400($t5)
/* 0CC908 7F099F18 8C790000 */  lw    $t9, ($v1)
/* 0CC90C 7F099F1C E7200404 */  swc1  $f0, 0x404($t9)
/* 0CC910 7F099F20 8C780000 */  lw    $t8, ($v1)
/* 0CC914 7F099F24 AF00041C */  sw    $zero, 0x41c($t8)
/* 0CC918 7F099F28 8C6B0000 */  lw    $t3, ($v1)
/* 0CC91C 7F099F2C AD680420 */  sw    $t0, 0x420($t3)
/* 0CC920 7F099F30 8C6F0000 */  lw    $t7, ($v1)
/* 0CC924 7F099F34 ADE00424 */  sw    $zero, 0x424($t7)
/* 0CC928 7F099F38 8C6E0000 */  lw    $t6, ($v1)
/* 0CC92C 7F099F3C ADC00428 */  sw    $zero, 0x428($t6)
/* 0CC930 7F099F40 8C6C0000 */  lw    $t4, ($v1)
/* 0CC934 7F099F44 AD84042C */  sw    $a0, 0x42c($t4)
/* 0CC938 7F099F48 8C6D0000 */  lw    $t5, ($v1)
/* 0CC93C 7F099F4C 24040280 */  li    $a0, 640
/* 0CC940 7F099F50 ADA00430 */  sw    $zero, 0x430($t5)
/* 0CC944 7F099F54 8C790000 */  lw    $t9, ($v1)
/* 0CC948 7F099F58 AF2804DC */  sw    $t0, 0x4dc($t9)
/* 0CC94C 7F099F5C 8C780000 */  lw    $t8, ($v1)
/* 0CC950 7F099F60 AF0804E0 */  sw    $t0, 0x4e0($t8)
/* 0CC954 7F099F64 8C6B0000 */  lw    $t3, ($v1)
/* 0CC958 7F099F68 AD6804E4 */  sw    $t0, 0x4e4($t3)
/* 0CC95C 7F099F6C 8C6F0000 */  lw    $t7, ($v1)
/* 0CC960 7F099F70 ADE004E8 */  sw    $zero, 0x4e8($t7)
/* 0CC964 7F099F74 8C6E0000 */  lw    $t6, ($v1)
/* 0CC968 7F099F78 C432CCD8 */  lwc1  $f18, %lo(D_80057618)($at)
/* 0CC96C 7F099F7C 3C018005 */  lui   $at, %hi(D_8005761C) # $at, 0x8005
/* 0CC970 7F099F80 E5D204EC */  swc1  $f18, 0x4ec($t6)
/* 0CC974 7F099F84 8C6C0000 */  lw    $t4, ($v1)
/* 0CC978 7F099F88 AD8004F0 */  sw    $zero, 0x4f0($t4)
/* 0CC97C 7F099F8C 8C6D0000 */  lw    $t5, ($v1)
/* 0CC980 7F099F90 E5A204F4 */  swc1  $f2, 0x4f4($t5)
/* 0CC984 7F099F94 8C790000 */  lw    $t9, ($v1)
/* 0CC988 7F099F98 E72204F8 */  swc1  $f2, 0x4f8($t9)
/* 0CC98C 7F099F9C 8C780000 */  lw    $t8, ($v1)
/* 0CC990 7F099FA0 E70004FC */  swc1  $f0, 0x4fc($t8)
/* 0CC994 7F099FA4 8C6B0000 */  lw    $t3, ($v1)
/* 0CC998 7F099FA8 E5600500 */  swc1  $f0, 0x500($t3)
/* 0CC99C 7F099FAC 8C6F0000 */  lw    $t7, ($v1)
/* 0CC9A0 7F099FB0 E5E00504 */  swc1  $f0, 0x504($t7)
/* 0CC9A4 7F099FB4 8C6E0000 */  lw    $t6, ($v1)
/* 0CC9A8 7F099FB8 C42CCCDC */  lwc1  $f12, %lo(D_8005761C)($at)
/* 0CC9AC 7F099FBC E5C00508 */  swc1  $f0, 0x508($t6)
/* 0CC9B0 7F099FC0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC9B4 7F099FC4 E580050C */  swc1  $f0, 0x50c($t4)
/* 0CC9B8 7F099FC8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC9BC 7F099FCC E5A20510 */  swc1  $f2, 0x510($t5)
/* 0CC9C0 7F099FD0 8C790000 */  lw    $t9, ($v1)
/* 0CC9C4 7F099FD4 E7200514 */  swc1  $f0, 0x514($t9)
/* 0CC9C8 7F099FD8 8C780000 */  lw    $t8, ($v1)
/* 0CC9CC 7F099FDC E7020518 */  swc1  $f2, 0x518($t8)
/* 0CC9D0 7F099FE0 8C6B0000 */  lw    $t3, ($v1)
/* 0CC9D4 7F099FE4 E560051C */  swc1  $f0, 0x51c($t3)
/* 0CC9D8 7F099FE8 8C6F0000 */  lw    $t7, ($v1)
/* 0CC9DC 7F099FEC E5E00520 */  swc1  $f0, 0x520($t7)
/* 0CC9E0 7F099FF0 8C6E0000 */  lw    $t6, ($v1)
/* 0CC9E4 7F099FF4 E5C00524 */  swc1  $f0, 0x524($t6)
/* 0CC9E8 7F099FF8 8C6C0000 */  lw    $t4, ($v1)
/* 0CC9EC 7F099FFC E5800528 */  swc1  $f0, 0x528($t4)
/* 0CC9F0 7F09A000 8C6D0000 */  lw    $t5, ($v1)
/* 0CC9F4 7F09A004 E5A0052C */  swc1  $f0, 0x52c($t5)
/* 0CC9F8 7F09A008 8C790000 */  lw    $t9, ($v1)
/* 0CC9FC 7F09A00C E7200530 */  swc1  $f0, 0x530($t9)
/* 0CCA00 7F09A010 8C780000 */  lw    $t8, ($v1)
/* 0CCA04 7F09A014 E70C0534 */  swc1  $f12, 0x534($t8)
/* 0CCA08 7F09A018 8C6B0000 */  lw    $t3, ($v1)
/* 0CCA0C 7F09A01C E5600538 */  swc1  $f0, 0x538($t3)
/* 0CCA10 7F09A020 8C6F0000 */  lw    $t7, ($v1)
/* 0CCA14 7F09A024 E5EC053C */  swc1  $f12, 0x53c($t7)
/* 0CCA18 7F09A028 8C6E0000 */  lw    $t6, ($v1)
/* 0CCA1C 7F09A02C E5C00540 */  swc1  $f0, 0x540($t6)
/* 0CCA20 7F09A030 8C6C0000 */  lw    $t4, ($v1)
/* 0CCA24 7F09A034 E5800544 */  swc1  $f0, 0x544($t4)
/* 0CCA28 7F09A038 8C6D0000 */  lw    $t5, ($v1)
/* 0CCA2C 7F09A03C E5A00548 */  swc1  $f0, 0x548($t5)
/* 0CCA30 7F09A040 8C790000 */  lw    $t9, ($v1)
/* 0CCA34 7F09A044 E720054C */  swc1  $f0, 0x54c($t9)
/* 0CCA38 7F09A048 8C780000 */  lw    $t8, ($v1)
/* 0CCA3C 7F09A04C E7000550 */  swc1  $f0, 0x550($t8)
/* 0CCA40 7F09A050 8C6B0000 */  lw    $t3, ($v1)
/* 0CCA44 7F09A054 E5600554 */  swc1  $f0, 0x554($t3)
/* 0CCA48 7F09A058 8C6F0000 */  lw    $t7, ($v1)
/* 0CCA4C 7F09A05C E5E00558 */  swc1  $f0, 0x558($t7)
/* 0CCA50 7F09A060 8C6E0000 */  lw    $t6, ($v1)
/* 0CCA54 7F09A064 E5C0055C */  swc1  $f0, 0x55c($t6)
/* 0CCA58 7F09A068 8C6C0000 */  lw    $t4, ($v1)
/* 0CCA5C 7F09A06C E5800560 */  swc1  $f0, 0x560($t4)
/* 0CCA60 7F09A070 8C6D0000 */  lw    $t5, ($v1)
/* 0CCA64 7F09A074 E5A00564 */  swc1  $f0, 0x564($t5)
/* 0CCA68 7F09A078 8C790000 */  lw    $t9, ($v1)
/* 0CCA6C 7F09A07C E7200568 */  swc1  $f0, 0x568($t9)
/* 0CCA70 7F09A080 8C780000 */  lw    $t8, ($v1)
/* 0CCA74 7F09A084 E702056C */  swc1  $f2, 0x56c($t8)
/* 0CCA78 7F09A088 8C6B0000 */  lw    $t3, ($v1)
/* 0CCA7C 7F09A08C E5600570 */  swc1  $f0, 0x570($t3)
/* 0CCA80 7F09A090 8C6F0000 */  lw    $t7, ($v1)
/* 0CCA84 7F09A094 E5E00574 */  swc1  $f0, 0x574($t7)
/* 0CCA88 7F09A098 8C6E0000 */  lw    $t6, ($v1)
/* 0CCA8C 7F09A09C E5C20578 */  swc1  $f2, 0x578($t6)
/* 0CCA90 7F09A0A0 8C6C0000 */  lw    $t4, ($v1)
/* 0CCA94 7F09A0A4 E580057C */  swc1  $f0, 0x57c($t4)
/* 0CCA98 7F09A0A8 8C6D0000 */  lw    $t5, ($v1)
/* 0CCA9C 7F09A0AC E5A20580 */  swc1  $f2, 0x580($t5)
/* 0CCAA0 7F09A0B0 8C790000 */  lw    $t9, ($v1)
/* 0CCAA4 7F09A0B4 E7200584 */  swc1  $f0, 0x584($t9)
/* 0CCAA8 7F09A0B8 8C780000 */  lw    $t8, ($v1)
/* 0CCAAC 7F09A0BC E7000588 */  swc1  $f0, 0x588($t8)
/* 0CCAB0 7F09A0C0 8C6B0000 */  lw    $t3, ($v1)
/* 0CCAB4 7F09A0C4 E562058C */  swc1  $f2, 0x58c($t3)
/* 0CCAB8 7F09A0C8 8C6F0000 */  lw    $t7, ($v1)
/* 0CCABC 7F09A0CC E5E00590 */  swc1  $f0, 0x590($t7)
/* 0CCAC0 7F09A0D0 8C6E0000 */  lw    $t6, ($v1)
/* 0CCAC4 7F09A0D4 ADC00594 */  sw    $zero, 0x594($t6)
.L7F09A0D8:
/* 0CCAC8 7F09A0D8 8C6C0000 */  lw    $t4, ($v1)
/* 0CCACC 7F09A0DC 01826821 */  addu  $t5, $t4, $v0
/* 0CCAD0 7F09A0E0 A5A407D0 */  sh    $a0, 0x7d0($t5)
/* 0CCAD4 7F09A0E4 8C790000 */  lw    $t9, ($v1)
/* 0CCAD8 7F09A0E8 0322C021 */  addu  $t8, $t9, $v0
/* 0CCADC 7F09A0EC A70507D2 */  sh    $a1, 0x7d2($t8)
/* 0CCAE0 7F09A0F0 8C6B0000 */  lw    $t3, ($v1)
/* 0CCAE4 7F09A0F4 01627821 */  addu  $t7, $t3, $v0
/* 0CCAE8 7F09A0F8 A5E607D4 */  sh    $a2, 0x7d4($t7)
/* 0CCAEC 7F09A0FC 8C6E0000 */  lw    $t6, ($v1)
/* 0CCAF0 7F09A100 01C26021 */  addu  $t4, $t6, $v0
/* 0CCAF4 7F09A104 A58007D6 */  sh    $zero, 0x7d6($t4)
/* 0CCAF8 7F09A108 8C6D0000 */  lw    $t5, ($v1)
/* 0CCAFC 7F09A10C 01A2C821 */  addu  $t9, $t5, $v0
/* 0CCB00 7F09A110 A72407D8 */  sh    $a0, 0x7d8($t9)
/* 0CCB04 7F09A114 8C780000 */  lw    $t8, ($v1)
/* 0CCB08 7F09A118 03025821 */  addu  $t3, $t8, $v0
/* 0CCB0C 7F09A11C A56507DA */  sh    $a1, 0x7da($t3)
/* 0CCB10 7F09A120 8C6F0000 */  lw    $t7, ($v1)
/* 0CCB14 7F09A124 01E27021 */  addu  $t6, $t7, $v0
/* 0CCB18 7F09A128 A5C607DC */  sh    $a2, 0x7dc($t6)
/* 0CCB1C 7F09A12C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCB20 7F09A130 01826821 */  addu  $t5, $t4, $v0
/* 0CCB24 7F09A134 24420010 */  addiu $v0, $v0, 0x10
/* 0CCB28 7F09A138 1447FFE7 */  bne   $v0, $a3, .L7F09A0D8
/* 0CCB2C 7F09A13C A5A007DE */   sh    $zero, 0x7de($t5)
/* 0CCB30 7F09A140 8C790000 */  lw    $t9, ($v1)
/* 0CCB34 7F09A144 24020064 */  li    $v0, 100
/* 0CCB38 7F09A148 A72207F0 */  sh    $v0, 0x7f0($t9)
/* 0CCB3C 7F09A14C 8C780000 */  lw    $t8, ($v1)
/* 0CCB40 7F09A150 A70207F2 */  sh    $v0, 0x7f2($t8)
/* 0CCB44 7F09A154 8C6B0000 */  lw    $t3, ($v1)
/* 0CCB48 7F09A158 A56007F4 */  sh    $zero, 0x7f4($t3)
/* 0CCB4C 7F09A15C 8C6F0000 */  lw    $t7, ($v1)
/* 0CCB50 7F09A160 A5E007F6 */  sh    $zero, 0x7f6($t7)
/* 0CCB54 7F09A164 8C6E0000 */  lw    $t6, ($v1)
/* 0CCB58 7F09A168 ADC007F8 */  sw    $zero, 0x7f8($t6)
/* 0CCB5C 7F09A16C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCB60 7F09A170 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 0CCB64 7F09A174 8C6D0000 */  lw    $t5, ($v1)
/* 0CCB68 7F09A178 ADA00800 */  sw    $zero, 0x800($t5)
/* 0CCB6C 7F09A17C 8C790000 */  lw    $t9, ($v1)
/* 0CCB70 7F09A180 AF200804 */  sw    $zero, 0x804($t9)
/* 0CCB74 7F09A184 8C780000 */  lw    $t8, ($v1)
/* 0CCB78 7F09A188 AF092A3C */  sw    $t1, 0x2a3c($t8)
/* 0CCB7C 7F09A18C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCB80 7F09A190 0140C025 */  move  $t8, $t2
/* 0CCB84 7F09A194 AD692A40 */  sw    $t1, 0x2a40($t3)
/* 0CCB88 7F09A198 8C6F0000 */  lw    $t7, ($v1)
/* 0CCB8C 7F09A19C 254B03A8 */  addiu $t3, $t2, 0x3a8
/* 0CCB90 7F09A1A0 ADE02A48 */  sw    $zero, 0x2a48($t7)
/* 0CCB94 7F09A1A4 8C6E0000 */  lw    $t6, ($v1)
/* 0CCB98 7F09A1A8 01407825 */  move  $t7, $t2
/* 0CCB9C 7F09A1AC ADC02A4C */  sw    $zero, 0x2a4c($t6)
/* 0CCBA0 7F09A1B0 8C6C0000 */  lw    $t4, ($v1)
/* 0CCBA4 7F09A1B4 AD800808 */  sw    $zero, 0x808($t4)
/* 0CCBA8 7F09A1B8 8C6D0000 */  lw    $t5, ($v1)
/* 0CCBAC 7F09A1BC ADA0080C */  sw    $zero, 0x80c($t5)
/* 0CCBB0 7F09A1C0 8C790000 */  lw    $t9, ($v1)
.L7F09A1C4:
/* 0CCBB4 7F09A1C4 8DE10000 */  lw    $at, ($t7)
/* 0CCBB8 7F09A1C8 25EF000C */  addiu $t7, $t7, 0xc
/* 0CCBBC 7F09A1CC 2739000C */  addiu $t9, $t9, 0xc
/* 0CCBC0 7F09A1D0 AF21085C */  sw    $at, 0x85c($t9)
/* 0CCBC4 7F09A1D4 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CCBC8 7F09A1D8 AF210860 */  sw    $at, 0x860($t9)
/* 0CCBCC 7F09A1DC 8DE1FFFC */  lw    $at, -4($t7)
/* 0CCBD0 7F09A1E0 15EBFFF8 */  bne   $t7, $t3, .L7F09A1C4
/* 0CCBD4 7F09A1E4 AF210864 */   sw    $at, 0x864($t9)
/* 0CCBD8 7F09A1E8 8C6E0000 */  lw    $t6, ($v1)
/* 0CCBDC 7F09A1EC 254D03A8 */  addiu $t5, $t2, 0x3a8
.L7F09A1F0:
/* 0CCBE0 7F09A1F0 8F010000 */  lw    $at, ($t8)
/* 0CCBE4 7F09A1F4 2718000C */  addiu $t8, $t8, 0xc
/* 0CCBE8 7F09A1F8 25CE000C */  addiu $t6, $t6, 0xc
/* 0CCBEC 7F09A1FC ADC10C04 */  sw    $at, 0xc04($t6)
/* 0CCBF0 7F09A200 8F01FFF8 */  lw    $at, -8($t8)
/* 0CCBF4 7F09A204 ADC10C08 */  sw    $at, 0xc08($t6)
/* 0CCBF8 7F09A208 8F01FFFC */  lw    $at, -4($t8)
/* 0CCBFC 7F09A20C 170DFFF8 */  bne   $t8, $t5, .L7F09A1F0
/* 0CCC00 7F09A210 ADC10C0C */   sw    $at, 0xc0c($t6)
/* 0CCC04 7F09A214 8C6B0000 */  lw    $t3, ($v1)
/* 0CCC08 7F09A218 3C018005 */  lui   $at, %hi(D_80057620) # $at, 0x8005
/* 0CCC0C 7F09A21C 240200FF */  li    $v0, 255
/* 0CCC10 7F09A220 E5620FB8 */  swc1  $f2, 0xfb8($t3)
/* 0CCC14 7F09A224 8C6F0000 */  lw    $t7, ($v1)
/* 0CCC18 7F09A228 24040007 */  li    $a0, 7
/* 0CCC1C 7F09A22C E5E20FBC */  swc1  $f2, 0xfbc($t7)
/* 0CCC20 7F09A230 8C790000 */  lw    $t9, ($v1)
/* 0CCC24 7F09A234 AF200FC0 */  sw    $zero, 0xfc0($t9)
/* 0CCC28 7F09A238 8C6C0000 */  lw    $t4, ($v1)
/* 0CCC2C 7F09A23C AD800FC4 */  sw    $zero, 0xfc4($t4)
/* 0CCC30 7F09A240 8C6D0000 */  lw    $t5, ($v1)
/* 0CCC34 7F09A244 C42CCCE0 */  lwc1  $f12, %lo(D_80057620)($at)
/* 0CCC38 7F09A248 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0CCC3C 7F09A24C ADA00FC8 */  sw    $zero, 0xfc8($t5)
/* 0CCC40 7F09A250 8C780000 */  lw    $t8, ($v1)
/* 0CCC44 7F09A254 AF000FCC */  sw    $zero, 0xfcc($t8)
/* 0CCC48 7F09A258 8C6E0000 */  lw    $t6, ($v1)
/* 0CCC4C 7F09A25C ADC00FD0 */  sw    $zero, 0xfd0($t6)
/* 0CCC50 7F09A260 8C6B0000 */  lw    $t3, ($v1)
/* 0CCC54 7F09A264 A1620FD4 */  sb    $v0, 0xfd4($t3)
/* 0CCC58 7F09A268 8C6F0000 */  lw    $t7, ($v1)
/* 0CCC5C 7F09A26C A1E20FD5 */  sb    $v0, 0xfd5($t7)
/* 0CCC60 7F09A270 8C790000 */  lw    $t9, ($v1)
/* 0CCC64 7F09A274 A3220FD6 */  sb    $v0, 0xfd6($t9)
/* 0CCC68 7F09A278 8C6C0000 */  lw    $t4, ($v1)
/* 0CCC6C 7F09A27C 3C028007 */  lui   $v0, %hi(random_byte) # $v0, 0x8007
/* 0CCC70 7F09A280 24428BCC */  addiu $v0, %lo(random_byte) # addiu $v0, $v0, -0x7434
/* 0CCC74 7F09A284 A1800FD7 */  sb    $zero, 0xfd7($t4)
/* 0CCC78 7F09A288 8C6D0000 */  lw    $t5, ($v1)
/* 0CCC7C 7F09A28C ADA80FD8 */  sw    $t0, 0xfd8($t5)
/* 0CCC80 7F09A290 8C780000 */  lw    $t8, ($v1)
/* 0CCC84 7F09A294 AF000FDC */  sw    $zero, 0xfdc($t8)
/* 0CCC88 7F09A298 8C6E0000 */  lw    $t6, ($v1)
/* 0CCC8C 7F09A29C E5C00FE0 */  swc1  $f0, 0xfe0($t6)
/* 0CCC90 7F09A2A0 8C6B0000 */  lw    $t3, ($v1)
/* 0CCC94 7F09A2A4 E5600FE4 */  swc1  $f0, 0xfe4($t3)
/* 0CCC98 7F09A2A8 8C6F0000 */  lw    $t7, ($v1)
/* 0CCC9C 7F09A2AC E5E00FE8 */  swc1  $f0, 0xfe8($t7)
/* 0CCCA0 7F09A2B0 8C790000 */  lw    $t9, ($v1)
/* 0CCCA4 7F09A2B4 E7200FEC */  swc1  $f0, 0xfec($t9)
/* 0CCCA8 7F09A2B8 8C6C0000 */  lw    $t4, ($v1)
/* 0CCCAC 7F09A2BC E58C0FF0 */  swc1  $f12, 0xff0($t4)
/* 0CCCB0 7F09A2C0 8C6D0000 */  lw    $t5, ($v1)
/* 0CCCB4 7F09A2C4 E5A00FF4 */  swc1  $f0, 0xff4($t5)
/* 0CCCB8 7F09A2C8 8C780000 */  lw    $t8, ($v1)
/* 0CCCBC 7F09A2CC E7000FF8 */  swc1  $f0, 0xff8($t8)
/* 0CCCC0 7F09A2D0 8C6E0000 */  lw    $t6, ($v1)
/* 0CCCC4 7F09A2D4 E5C00FFC */  swc1  $f0, 0xffc($t6)
/* 0CCCC8 7F09A2D8 8C6B0000 */  lw    $t3, ($v1)
/* 0CCCCC 7F09A2DC E5601000 */  swc1  $f0, 0x1000($t3)
/* 0CCCD0 7F09A2E0 8C6F0000 */  lw    $t7, ($v1)
/* 0CCCD4 7F09A2E4 E5EC1004 */  swc1  $f12, 0x1004($t7)
/* 0CCCD8 7F09A2E8 44816000 */  mtc1  $at, $f12
/* 0CCCDC 7F09A2EC 8C790000 */  lw    $t9, ($v1)
/* 0CCCE0 7F09A2F0 3C0143A0 */  li    $at, 0x43A00000 # 320.000000
/* 0CCCE4 7F09A2F4 44817000 */  mtc1  $at, $f14
/* 0CCCE8 7F09A2F8 3C014388 */  li    $at, 0x43880000 # 272.000000
/* 0CCCEC 7F09A2FC 44818000 */  mtc1  $at, $f16
/* 0CCCF0 7F09A300 E7201008 */  swc1  $f0, 0x1008($t9)
/* 0CCCF4 7F09A304 3C018005 */  lui   $at, %hi(D_80057624) # $at, 0x8005
/* 0CCCF8 7F09A308 C424CCE4 */  lwc1  $f4, %lo(D_80057624)($at)
/* 0CCCFC 7F09A30C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCD00 7F09A310 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0CCD04 7F09A314 44813000 */  mtc1  $at, $f6
/* 0CCD08 7F09A318 E584100C */  swc1  $f4, 0x100c($t4)
/* 0CCD0C 7F09A31C 8C6D0000 */  lw    $t5, ($v1)
/* 0CCD10 7F09A320 3C014238 */  li    $at, 0x42380000 # 46.000000
/* 0CCD14 7F09A324 44814000 */  mtc1  $at, $f8
/* 0CCD18 7F09A328 E5A01010 */  swc1  $f0, 0x1010($t5)
/* 0CCD1C 7F09A32C 8C780000 */  lw    $t8, ($v1)
/* 0CCD20 7F09A330 3C014320 */  li    $at, 0x43200000 # 160.000000
/* 0CCD24 7F09A334 44815000 */  mtc1  $at, $f10
/* 0CCD28 7F09A338 AF001054 */  sw    $zero, 0x1054($t8)
/* 0CCD2C 7F09A33C 8C6E0000 */  lw    $t6, ($v1)
/* 0CCD30 7F09A340 3C014308 */  li    $at, 0x43080000 # 136.000000
/* 0CCD34 7F09A344 44819000 */  mtc1  $at, $f18
/* 0CCD38 7F09A348 ADC01058 */  sw    $zero, 0x1058($t6)
/* 0CCD3C 7F09A34C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCD40 7F09A350 3C018005 */  lui   $at, %hi(D_80057628) # $at, 0x8005
/* 0CCD44 7F09A354 AD60105C */  sw    $zero, 0x105c($t3)
/* 0CCD48 7F09A358 8C6F0000 */  lw    $t7, ($v1)
/* 0CCD4C 7F09A35C E5E01064 */  swc1  $f0, 0x1064($t7)
/* 0CCD50 7F09A360 8C790000 */  lw    $t9, ($v1)
/* 0CCD54 7F09A364 E7201068 */  swc1  $f0, 0x1068($t9)
/* 0CCD58 7F09A368 8C6C0000 */  lw    $t4, ($v1)
/* 0CCD5C 7F09A36C E580106C */  swc1  $f0, 0x106c($t4)
/* 0CCD60 7F09A370 8C6D0000 */  lw    $t5, ($v1)
/* 0CCD64 7F09A374 ADA01070 */  sw    $zero, 0x1070($t5)
/* 0CCD68 7F09A378 8C780000 */  lw    $t8, ($v1)
/* 0CCD6C 7F09A37C E7001074 */  swc1  $f0, 0x1074($t8)
/* 0CCD70 7F09A380 8C6E0000 */  lw    $t6, ($v1)
/* 0CCD74 7F09A384 E5C01078 */  swc1  $f0, 0x1078($t6)
/* 0CCD78 7F09A388 8C6B0000 */  lw    $t3, ($v1)
/* 0CCD7C 7F09A38C E56C107C */  swc1  $f12, 0x107c($t3)
/* 0CCD80 7F09A390 8C6F0000 */  lw    $t7, ($v1)
/* 0CCD84 7F09A394 E5EC1080 */  swc1  $f12, 0x1080($t7)
/* 0CCD88 7F09A398 8C790000 */  lw    $t9, ($v1)
/* 0CCD8C 7F09A39C AF291084 */  sw    $t1, 0x1084($t9)
/* 0CCD90 7F09A3A0 8C6C0000 */  lw    $t4, ($v1)
/* 0CCD94 7F09A3A4 E58E1088 */  swc1  $f14, 0x1088($t4)
/* 0CCD98 7F09A3A8 8C6D0000 */  lw    $t5, ($v1)
/* 0CCD9C 7F09A3AC E5B0108C */  swc1  $f16, 0x108c($t5)
/* 0CCDA0 7F09A3B0 8C780000 */  lw    $t8, ($v1)
/* 0CCDA4 7F09A3B4 E7001090 */  swc1  $f0, 0x1090($t8)
/* 0CCDA8 7F09A3B8 8C6E0000 */  lw    $t6, ($v1)
/* 0CCDAC 7F09A3BC E5C01094 */  swc1  $f0, 0x1094($t6)
/* 0CCDB0 7F09A3C0 8C6B0000 */  lw    $t3, ($v1)
/* 0CCDB4 7F09A3C4 E5661098 */  swc1  $f6, 0x1098($t3)
/* 0CCDB8 7F09A3C8 8C6F0000 */  lw    $t7, ($v1)
/* 0CCDBC 7F09A3CC E5E8109C */  swc1  $f8, 0x109c($t7)
/* 0CCDC0 7F09A3D0 8C790000 */  lw    $t9, ($v1)
/* 0CCDC4 7F09A3D4 E72210A0 */  swc1  $f2, 0x10a0($t9)
/* 0CCDC8 7F09A3D8 8C6C0000 */  lw    $t4, ($v1)
/* 0CCDCC 7F09A3DC E58A10A4 */  swc1  $f10, 0x10a4($t4)
/* 0CCDD0 7F09A3E0 8C6D0000 */  lw    $t5, ($v1)
/* 0CCDD4 7F09A3E4 E5B210A8 */  swc1  $f18, 0x10a8($t5)
/* 0CCDD8 7F09A3E8 8C780000 */  lw    $t8, ($v1)
/* 0CCDDC 7F09A3EC E70210AC */  swc1  $f2, 0x10ac($t8)
/* 0CCDE0 7F09A3F0 8C6E0000 */  lw    $t6, ($v1)
/* 0CCDE4 7F09A3F4 E5C210B0 */  swc1  $f2, 0x10b0($t6)
/* 0CCDE8 7F09A3F8 8C6B0000 */  lw    $t3, ($v1)
/* 0CCDEC 7F09A3FC E56210B4 */  swc1  $f2, 0x10b4($t3)
/* 0CCDF0 7F09A400 8C6F0000 */  lw    $t7, ($v1)
/* 0CCDF4 7F09A404 E5E210B8 */  swc1  $f2, 0x10b8($t7)
/* 0CCDF8 7F09A408 8C790000 */  lw    $t9, ($v1)
/* 0CCDFC 7F09A40C AF2010BC */  sw    $zero, 0x10bc($t9)
/* 0CCE00 7F09A410 8C6C0000 */  lw    $t4, ($v1)
/* 0CCE04 7F09A414 AD8010C0 */  sw    $zero, 0x10c0($t4)
/* 0CCE08 7F09A418 8C6D0000 */  lw    $t5, ($v1)
/* 0CCE0C 7F09A41C ADA010C4 */  sw    $zero, 0x10c4($t5)
/* 0CCE10 7F09A420 8C780000 */  lw    $t8, ($v1)
/* 0CCE14 7F09A424 AF0010C8 */  sw    $zero, 0x10c8($t8)
/* 0CCE18 7F09A428 8C6E0000 */  lw    $t6, ($v1)
/* 0CCE1C 7F09A42C ADC010CC */  sw    $zero, 0x10cc($t6)
/* 0CCE20 7F09A430 8C6B0000 */  lw    $t3, ($v1)
/* 0CCE24 7F09A434 AD6010D0 */  sw    $zero, 0x10d0($t3)
/* 0CCE28 7F09A438 8C6F0000 */  lw    $t7, ($v1)
/* 0CCE2C 7F09A43C ADE010D4 */  sw    $zero, 0x10d4($t7)
/* 0CCE30 7F09A440 8C790000 */  lw    $t9, ($v1)
/* 0CCE34 7F09A444 AF2010D8 */  sw    $zero, 0x10d8($t9)
/* 0CCE38 7F09A448 8C6C0000 */  lw    $t4, ($v1)
/* 0CCE3C 7F09A44C 3C190001 */  lui   $t9, 1
/* 0CCE40 7F09A450 AD8010DC */  sw    $zero, 0x10dc($t4)
/* 0CCE44 7F09A454 8C6D0000 */  lw    $t5, ($v1)
/* 0CCE48 7F09A458 ADA010E0 */  sw    $zero, 0x10e0($t5)
/* 0CCE4C 7F09A45C 8C780000 */  lw    $t8, ($v1)
/* 0CCE50 7F09A460 AF0010E4 */  sw    $zero, 0x10e4($t8)
/* 0CCE54 7F09A464 8C6E0000 */  lw    $t6, ($v1)
/* 0CCE58 7F09A468 E5C210E8 */  swc1  $f2, 0x10e8($t6)
/* 0CCE5C 7F09A46C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCE60 7F09A470 E56210EC */  swc1  $f2, 0x10ec($t3)
/* 0CCE64 7F09A474 8C6F0000 */  lw    $t7, ($v1)
/* 0CCE68 7F09A478 E5E210F0 */  swc1  $f2, 0x10f0($t7)
/* 0CCE6C 7F09A47C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCE70 7F09A480 AD9910F4 */  sw    $t9, 0x10f4($t4)
/* 0CCE74 7F09A484 8C6D0000 */  lw    $t5, ($v1)
/* 0CCE78 7F09A488 E5A01110 */  swc1  $f0, 0x1110($t5)
/* 0CCE7C 7F09A48C 8C780000 */  lw    $t8, ($v1)
/* 0CCE80 7F09A490 E7001114 */  swc1  $f0, 0x1114($t8)
/* 0CCE84 7F09A494 8C6E0000 */  lw    $t6, ($v1)
/* 0CCE88 7F09A498 E5CE1118 */  swc1  $f14, 0x1118($t6)
/* 0CCE8C 7F09A49C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCE90 7F09A4A0 E570111C */  swc1  $f16, 0x111c($t3)
/* 0CCE94 7F09A4A4 8C6F0000 */  lw    $t7, ($v1)
/* 0CCE98 7F09A4A8 ADE01120 */  sw    $zero, 0x1120($t7)
/* 0CCE9C 7F09A4AC 8C790000 */  lw    $t9, ($v1)
/* 0CCEA0 7F09A4B0 AF2011A8 */  sw    $zero, 0x11a8($t9)
/* 0CCEA4 7F09A4B4 8C6C0000 */  lw    $t4, ($v1)
/* 0CCEA8 7F09A4B8 AD8011AC */  sw    $zero, 0x11ac($t4)
/* 0CCEAC 7F09A4BC 8C6D0000 */  lw    $t5, ($v1)
/* 0CCEB0 7F09A4C0 ADA011B0 */  sw    $zero, 0x11b0($t5)
/* 0CCEB4 7F09A4C4 8C780000 */  lw    $t8, ($v1)
/* 0CCEB8 7F09A4C8 E70011B4 */  swc1  $f0, 0x11b4($t8)
/* 0CCEBC 7F09A4CC 8C6E0000 */  lw    $t6, ($v1)
/* 0CCEC0 7F09A4D0 E5C011B8 */  swc1  $f0, 0x11b8($t6)
/* 0CCEC4 7F09A4D4 8C6B0000 */  lw    $t3, ($v1)
/* 0CCEC8 7F09A4D8 E56C11BC */  swc1  $f12, 0x11bc($t3)
/* 0CCECC 7F09A4DC 8C6F0000 */  lw    $t7, ($v1)
/* 0CCED0 7F09A4E0 E5EC11C0 */  swc1  $f12, 0x11c0($t7)
/* 0CCED4 7F09A4E4 8C790000 */  lw    $t9, ($v1)
/* 0CCED8 7F09A4E8 E72C11C4 */  swc1  $f12, 0x11c4($t9)
/* 0CCEDC 7F09A4EC 8C6C0000 */  lw    $t4, ($v1)
/* 0CCEE0 7F09A4F0 E58C11C8 */  swc1  $f12, 0x11c8($t4)
/* 0CCEE4 7F09A4F4 8C6D0000 */  lw    $t5, ($v1)
/* 0CCEE8 7F09A4F8 C424CCE8 */  lwc1  $f4, %lo(D_80057628)($at)
/* 0CCEEC 7F09A4FC 3C018003 */  lui   $at, %hi(g_VisibleToGuardsFlag) # $at, 0x8003
/* 0CCEF0 7F09A500 E5A411CC */  swc1  $f4, 0x11cc($t5)
/* 0CCEF4 7F09A504 8C780000 */  lw    $t8, ($v1)
/* 0CCEF8 7F09A508 AF0011D0 */  sw    $zero, 0x11d0($t8)
/* 0CCEFC 7F09A50C 8C6E0000 */  lw    $t6, ($v1)
/* 0CCF00 7F09A510 ADC911D4 */  sw    $t1, 0x11d4($t6)
/* 0CCF04 7F09A514 8C6B0000 */  lw    $t3, ($v1)
/* 0CCF08 7F09A518 AD6011D8 */  sw    $zero, 0x11d8($t3)
/* 0CCF0C 7F09A51C 8C6F0000 */  lw    $t7, ($v1)
/* 0CCF10 7F09A520 ADE011DC */  sw    $zero, 0x11dc($t7)
/* 0CCF14 7F09A524 8C790000 */  lw    $t9, ($v1)
/* 0CCF18 7F09A528 AF2011E0 */  sw    $zero, 0x11e0($t9)
/* 0CCF1C 7F09A52C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCF20 7F09A530 AD8011E4 */  sw    $zero, 0x11e4($t4)
/* 0CCF24 7F09A534 8C6D0000 */  lw    $t5, ($v1)
/* 0CCF28 7F09A538 ADA011E8 */  sw    $zero, 0x11e8($t5)
/* 0CCF2C 7F09A53C 8C780000 */  lw    $t8, ($v1)
/* 0CCF30 7F09A540 AF0011EC */  sw    $zero, 0x11ec($t8)
/* 0CCF34 7F09A544 8C6E0000 */  lw    $t6, ($v1)
/* 0CCF38 7F09A548 E5C01278 */  swc1  $f0, 0x1278($t6)
/* 0CCF3C 7F09A54C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCF40 7F09A550 AD60127C */  sw    $zero, 0x127c($t3)
/* 0CCF44 7F09A554 8C6F0000 */  lw    $t7, ($v1)
/* 0CCF48 7F09A558 E5E01280 */  swc1  $f0, 0x1280($t7)
/* 0CCF4C 7F09A55C 8C790000 */  lw    $t9, ($v1)
/* 0CCF50 7F09A560 A32012AE */  sb    $zero, 0x12ae($t9)
/* 0CCF54 7F09A564 8C6C0000 */  lw    $t4, ($v1)
/* 0CCF58 7F09A568 AD8429B0 */  sw    $a0, 0x29b0($t4)
/* 0CCF5C 7F09A56C 8C6D0000 */  lw    $t5, ($v1)
/* 0CCF60 7F09A570 E5A229B4 */  swc1  $f2, 0x29b4($t5)
/* 0CCF64 7F09A574 8C780000 */  lw    $t8, ($v1)
/* 0CCF68 7F09A578 E70029B8 */  swc1  $f0, 0x29b8($t8)
/* 0CCF6C 7F09A57C 8C6E0000 */  lw    $t6, ($v1)
/* 0CCF70 7F09A580 ADC029BC */  sw    $zero, 0x29bc($t6)
/* 0CCF74 7F09A584 8C6B0000 */  lw    $t3, ($v1)
/* 0CCF78 7F09A588 AD6429CC */  sw    $a0, 0x29cc($t3)
/* 0CCF7C 7F09A58C 8C6F0000 */  lw    $t7, ($v1)
/* 0CCF80 7F09A590 ADE029D0 */  sw    $zero, 0x29d0($t7)
/* 0CCF84 7F09A594 8C6C0000 */  lw    $t4, ($v1)
/* 0CCF88 7F09A598 8C590000 */  lw    $t9, ($v0)
/* 0CCF8C 7F09A59C AD9929D8 */  sw    $t9, 0x29d8($t4)
/* 0CCF90 7F09A5A0 8C4D0000 */  lw    $t5, ($v0)
/* 0CCF94 7F09A5A4 8C6E0000 */  lw    $t6, ($v1)
/* 0CCF98 7F09A5A8 25B80001 */  addiu $t8, $t5, 1
/* 0CCF9C 7F09A5AC AC580000 */  sw    $t8, ($v0)
/* 0CCFA0 7F09A5B0 ADC929DC */  sw    $t1, 0x29dc($t6)
/* 0CCFA4 7F09A5B4 8C6B0000 */  lw    $t3, ($v1)
/* 0CCFA8 7F09A5B8 AD6929E0 */  sw    $t1, 0x29e0($t3)
/* 0CCFAC 7F09A5BC 8C6F0000 */  lw    $t7, ($v1)
/* 0CCFB0 7F09A5C0 ADE929E4 */  sw    $t1, 0x29e4($t7)
/* 0CCFB4 7F09A5C4 8C790000 */  lw    $t9, ($v1)
/* 0CCFB8 7F09A5C8 AF2929E8 */  sw    $t1, 0x29e8($t9)
/* 0CCFBC 7F09A5CC 8C6C0000 */  lw    $t4, ($v1)
/* 0CCFC0 7F09A5D0 AD8029F8 */  sw    $zero, 0x29f8($t4)
/* 0CCFC4 7F09A5D4 8C6D0000 */  lw    $t5, ($v1)
/* 0CCFC8 7F09A5D8 ADA02A28 */  sw    $zero, 0x2a28($t5)
/* 0CCFCC 7F09A5DC 8C780000 */  lw    $t8, ($v1)
/* 0CCFD0 7F09A5E0 AF002A2C */  sw    $zero, 0x2a2c($t8)
/* 0CCFD4 7F09A5E4 8C6E0000 */  lw    $t6, ($v1)
/* 0CCFD8 7F09A5E8 ADC82A30 */  sw    $t0, 0x2a30($t6)
/* 0CCFDC 7F09A5EC 8C6B0000 */  lw    $t3, ($v1)
/* 0CCFE0 7F09A5F0 E5622A34 */  swc1  $f2, 0x2a34($t3)
/* 0CCFE4 7F09A5F4 8C6F0000 */  lw    $t7, ($v1)
/* 0CCFE8 7F09A5F8 E5E22A38 */  swc1  $f2, 0x2a38($t7)
/* 0CCFEC 7F09A5FC 8C790000 */  lw    $t9, ($v1)
/* 0CCFF0 7F09A600 AF202A50 */  sw    $zero, 0x2a50($t9)
/* 0CCFF4 7F09A604 8C6C0000 */  lw    $t4, ($v1)
/* 0CCFF8 7F09A608 AD802A54 */  sw    $zero, 0x2a54($t4)
/* 0CCFFC 7F09A60C 8C6D0000 */  lw    $t5, ($v1)
/* 0CD000 7F09A610 E5A02A58 */  swc1  $f0, 0x2a58($t5)
/* 0CD004 7F09A614 8C780000 */  lw    $t8, ($v1)
/* 0CD008 7F09A618 AF002A5C */  sw    $zero, 0x2a5c($t8)
/* 0CD00C 7F09A61C 8C6E0000 */  lw    $t6, ($v1)
/* 0CD010 7F09A620 ADC82A60 */  sw    $t0, 0x2a60($t6)
/* 0CD014 7F09A624 8C6B0000 */  lw    $t3, ($v1)
/* 0CD018 7F09A628 AD602A64 */  sw    $zero, 0x2a64($t3)
/* 0CD01C 7F09A62C 8C6F0000 */  lw    $t7, ($v1)
/* 0CD020 7F09A630 ADE02A68 */  sw    $zero, 0x2a68($t7)
/* 0CD024 7F09A634 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CD028 7F09A638 AC281A14 */  sw    $t0, %lo(g_VisibleToGuardsFlag)($at)
/* 0CD02C 7F09A63C 3C018003 */  lui   $at, %hi(obj_collision_flag) # $at, 0x8003
/* 0CD030 7F09A640 AC281A18 */  sw    $t0, %lo(obj_collision_flag)($at)
/* 0CD034 7F09A644 03E00008 */  jr    $ra
/* 0CD038 7F09A648 27BD03D0 */   addiu $sp, $sp, 0x3d0
)
#else if defined(VERSION_US) || defined(VERSION_JP)

void initBONDdataforPlayer(s32 player_num)
{
    s32 i;
    struct hand default_hand;
    s32 one;

    default_hand = *((struct hand*)&D_8003FDA0);
#if defined(VERSION_US) || defined(VERSION_JP)
    g_playerPointers[player_num] = mempAllocBytesInBank(0x2A80U, 4U);
#elif defined(VERSION_EU)
    g_playerPointers[player_num] = mempAllocBytesInBank(0x2A70U, 4U);
#endif

    g_playerPointers[player_num]->unknown = 0;
    g_playerPointers[player_num]->pos.x = 0.0f;
    g_playerPointers[player_num]->pos.y = 0.0f;
    g_playerPointers[player_num]->pos.z = 0.0f;
    g_playerPointers[player_num]->pos2.x = 0.0f;
    g_playerPointers[player_num]->pos2.y = 0.0f;
    g_playerPointers[player_num]->pos2.z = 1.0f;
    g_playerPointers[player_num]->offset.x = 0.0f;
    g_playerPointers[player_num]->offset.y = 1.0f;
    g_playerPointers[player_num]->offset.z = 0.0f;
    g_playerPointers[player_num]->pos3.x = 0.0f;
    g_playerPointers[player_num]->pos3.y = 0.0f;
    g_playerPointers[player_num]->pos3.z = 0.0f;
    g_playerPointers[player_num]->room_pointer = NULL;
    g_playerPointers[player_num]->current_model_pos.x = 0.0f;
    g_playerPointers[player_num]->current_model_pos.y = 0.0f;
    g_playerPointers[player_num]->current_model_pos.z = 0.0f;
    g_playerPointers[player_num]->previous_model_pos.x = 0.0f;
    g_playerPointers[player_num]->previous_model_pos.y = 0.0f;
    g_playerPointers[player_num]->previous_model_pos.z = 0.0f;
    g_playerPointers[player_num]->current_room_pos.x = 0.0f;
    g_playerPointers[player_num]->current_room_pos.y = 0.0f;
    g_playerPointers[player_num]->current_room_pos.z = 0.0f;
    g_playerPointers[player_num]->field_6C = 0.0f;
    g_playerPointers[player_num]->field_70 = 0.0f;
    g_playerPointers[player_num]->stanHeight = 0.0f;
    g_playerPointers[player_num]->field_78 = 0.0f;
    g_playerPointers[player_num]->field_7C = 0.0f;
    g_playerPointers[player_num]->field_80 = 0.0f;
    g_playerPointers[player_num]->field_84 = 0.0f;
    g_playerPointers[player_num]->field_88 = 0.0f;
    g_playerPointers[player_num]->field_8C = 0;
    g_playerPointers[player_num]->field_90 = 0.0f;
    g_playerPointers[player_num]->field_94 = 0;
    g_playerPointers[player_num]->field_98 = 0.0f;
    g_playerPointers[player_num]->swaytarget = 0.0f;
    g_playerPointers[player_num]->field_1278 = 0.0f;
    g_playerPointers[player_num]->field_127C = 0.0f;
    g_playerPointers[player_num]->crouchpos = 2;
    g_playerPointers[player_num]->autocrouchpos = 2;
    g_playerPointers[player_num]->ducking_height_offset = 0.0f;
    g_playerPointers[player_num]->field_A4 = 0.0f;
    g_playerPointers[player_num]->prop = NULL;
    g_playerPointers[player_num]->field_AC = 1;
    g_playerPointers[player_num]->field_D0 = 0;
    g_playerPointers[player_num]->ptr_char_objectinstance = NULL;
    g_playerPointers[player_num]->bonddead = 0;
    g_playerPointers[player_num]->bondhealth = 1.0f;
    g_playerPointers[player_num]->bondarmour = 0.0f;
    g_playerPointers[player_num]->oldhealth = 1.0f;
    g_playerPointers[player_num]->oldarmour = 0.0f;
    g_playerPointers[player_num]->apparenthealth = 1.0f;
    g_playerPointers[player_num]->apparentarmour = 0.0f;
    g_playerPointers[player_num]->damageshowtime = -1;
    g_playerPointers[player_num]->healthshowtime = -1;
    g_playerPointers[player_num]->field_104 = 0;
    g_playerPointers[player_num]->field_108 = 0;
    g_playerPointers[player_num]->field_10C = 0;
    g_playerPointers[player_num]->movecentrerelease = 0;
    g_playerPointers[player_num]->lookaheadcentreenabled = 1;
    g_playerPointers[player_num]->automovecentreenabled = 1;
    g_playerPointers[player_num]->fastmovecentreenabled = 0;
    g_playerPointers[player_num]->automovecentre = 1;
    g_playerPointers[player_num]->insightaimmode = 0;
    g_playerPointers[player_num]->autoyaimenabled = 1;
    g_playerPointers[player_num]->autoaimy = 0.0f;
    g_playerPointers[player_num]->autoyaimtime = 0;
    g_playerPointers[player_num]->autoyaimtime60 = -1;
    g_playerPointers[player_num]->autoxaimenabled = 1;
    g_playerPointers[player_num]->autoaimx = 0.0f;
    g_playerPointers[player_num]->autoxaimtime = 0;
    g_playerPointers[player_num]->autoxaimtime60 = -1;
    g_playerPointers[player_num]->vv_theta = 0.0f;
    g_playerPointers[player_num]->speedtheta = 0.0f;
    g_playerPointers[player_num]->vv_costheta = 1.0f;
    g_playerPointers[player_num]->vv_sintheta = 0.0f;
    g_playerPointers[player_num]->vv_verta = -4.0f;
    g_playerPointers[player_num]->vv_verta360 = -229.1831f;
    g_playerPointers[player_num]->speedverta = 0.0f;
    g_playerPointers[player_num]->vv_cosverta = 1.0f;
    g_playerPointers[player_num]->vv_sinverta = 0.0f;
    g_playerPointers[player_num]->speedsideways = 0.0f;
    g_playerPointers[player_num]->speedstrafe = 0.0f;
    g_playerPointers[player_num]->speedforwards = 0.0f;
    g_playerPointers[player_num]->field_2A4C = 0.0f;
    g_playerPointers[player_num]->speedboost = 1.0f;
    g_playerPointers[player_num]->bondshotspeed.x = 0.0f;
    g_playerPointers[player_num]->bondshotspeed.y = 0.0f;
    g_playerPointers[player_num]->bondshotspeed.z = 0.0f;
    g_playerPointers[player_num]->bondfadetime60 = -1.0f;
    g_playerPointers[player_num]->bondfadetimemax60 = -1.0f;
    g_playerPointers[player_num]->bondfadefracold = 0.0f;
    g_playerPointers[player_num]->bondfadefracnew = 0.0f;
    g_playerPointers[player_num]->bondbreathing = 0.0f;
    g_playerPointers[player_num]->field_1A0 = 0;
    g_playerPointers[player_num]->watch_pause_time = 0;
    g_playerPointers[player_num]->field_1C4 = 0;
    g_playerPointers[player_num]->watch_animation_state = 0;
    g_playerPointers[player_num]->outside_watch_menu = 1;
    g_playerPointers[player_num]->open_close_solo_watch_menu = 0;
    g_playerPointers[player_num]->field_1D4 = 0.0f;
    g_playerPointers[player_num]->field_1D8 = 0.0f;
    g_playerPointers[player_num]->pause_watch_position = -25;
    g_playerPointers[player_num]->field_1E0 = 0.0f;
    g_playerPointers[player_num]->field_1E4 = 1.0f;
    g_playerPointers[player_num]->field_1E8 = 0.0f;
    g_playerPointers[player_num]->field_1EC = 0.0f;
    g_playerPointers[player_num]->field_1F0 = 0.0f;
    g_playerPointers[player_num]->field_1F4 = 1.0f;
    g_playerPointers[player_num]->pausing_flag = 0;
    g_playerPointers[player_num]->pause_starting_angle = 0.0f;
    g_playerPointers[player_num]->pause_related = 0.0f;
    g_playerPointers[player_num]->pause_target_angle = 0.0f;
    g_playerPointers[player_num]->field_210 = 0.0f;
    g_playerPointers[player_num]->field_214 = 0.0f;
    g_playerPointers[player_num]->field_218 = 0;
    g_playerPointers[player_num]->field_21C = 1;
    g_playerPointers[player_num]->step_in_view_watch_animation = 0;
    g_playerPointers[player_num]->pause_animation_counter = 0.0f;
    g_playerPointers[player_num]->buttons_pressed = 0;
    g_playerPointers[player_num]->field_3B6 = 0;
    g_playerPointers[player_num]->field_3B8.x = 0.0f;
    g_playerPointers[player_num]->field_3B8.y = 0.0f;
    g_playerPointers[player_num]->field_3B8.z = 9.999998f;
    g_playerPointers[player_num]->field_3C4 = 0.0f;
    g_playerPointers[player_num]->field_3C8 = 0.0f;
    g_playerPointers[player_num]->field_3CC = 1.0f;
    g_playerPointers[player_num]->colourscreenred = 0xFF;
    g_playerPointers[player_num]->colourscreengreen = 0xFF;
    g_playerPointers[player_num]->colourscreenblue = 0xFF;
    g_playerPointers[player_num]->colourscreenfrac = 0.0f;
    g_playerPointers[player_num]->colourfadetime60 = -1.0f;
    g_playerPointers[player_num]->colourfadetimemax60 = -1.0f;
    g_playerPointers[player_num]->colourfaderedold = 0xFF;
    g_playerPointers[player_num]->colourfaderednew = 0xFF;
    g_playerPointers[player_num]->colourfadegreenold = 0xFF;
    g_playerPointers[player_num]->colourfadegreennew = 0xFF;
    g_playerPointers[player_num]->colourfadeblueold = 0xFF;
    g_playerPointers[player_num]->colourfadebluenew = 0xFF;
    g_playerPointers[player_num]->colourfadefracold = 0.0f;
    g_playerPointers[player_num]->colourfadefracnew = 0.0f;
    g_playerPointers[player_num]->bondtype = 0;
    g_playerPointers[player_num]->startnewbonddie = 1;
    g_playerPointers[player_num]->redbloodfinished = 0;
    g_playerPointers[player_num]->deathanimfinished = 0;
    g_playerPointers[player_num]->field_42c = 2;
    g_playerPointers[player_num]->controldef = 0;
    g_playerPointers[player_num]->resetheadpos = 1;
    g_playerPointers[player_num]->resetheadrot = 1;
    g_playerPointers[player_num]->resetheadtick = 1;
    g_playerPointers[player_num]->headanim = 0;
    g_playerPointers[player_num]->headdamp = 0.93f;
    g_playerPointers[player_num]->headwalkingtime60 = 0;
    g_playerPointers[player_num]->headamplitude = 1.0f;
    g_playerPointers[player_num]->sideamplitude = 1.0f;
    g_playerPointers[player_num]->headpos[0] = 0.0f;
    g_playerPointers[player_num]->headpos[1] = 0.0f;
    g_playerPointers[player_num]->headpos[2] = 0.0f;
    g_playerPointers[player_num]->headlook[0] = 0.0f;
    g_playerPointers[player_num]->headlook[1] = 0.0f;
    g_playerPointers[player_num]->headlook[2] = 1.0f;
    g_playerPointers[player_num]->headup[0] = 0.0f;
    g_playerPointers[player_num]->headup[1] = 1.0f;
    g_playerPointers[player_num]->headup[2] = 0.0f;
    g_playerPointers[player_num]->headpossum[0] = 0.0f;
    g_playerPointers[player_num]->headpossum[1] = 0.0f;
    g_playerPointers[player_num]->headpossum[2] = 0.0f;
    g_playerPointers[player_num]->headlooksum[0] = 0.0f;
    g_playerPointers[player_num]->headlooksum[1] = 0.0f;
    g_playerPointers[player_num]->headlooksum[2] = 14.285716f;
    g_playerPointers[player_num]->headupsum[0] = 0.0f;
    g_playerPointers[player_num]->headupsum[1] = 14.285716f;
    g_playerPointers[player_num]->headupsum[2] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset[0] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset[1] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset[2] = 0.0f;
    g_playerPointers[player_num]->standheight = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.x = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.y = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.z = 0.0f;
    g_playerPointers[player_num]->standfrac = 0.0f;
    g_playerPointers[player_num]->standlook[0][0] = 0.0f;
    g_playerPointers[player_num]->standlook[0][1] = 0.0f;
    g_playerPointers[player_num]->standlook[0][2] = 1.0f;
    g_playerPointers[player_num]->standlook[1][0] = 0.0f;
    g_playerPointers[player_num]->standlook[1][1] = 0.0f;
    g_playerPointers[player_num]->standlook[1][2] = 1.0f;
    g_playerPointers[player_num]->standup[0][0] = 0.0f;
    g_playerPointers[player_num]->standup[0][1] = 1.0f;
    g_playerPointers[player_num]->standup[0][2] = 0.0f;
    g_playerPointers[player_num]->standup[1][0] = 0.0f;
    g_playerPointers[player_num]->standup[1][1] = 1.0f;
    g_playerPointers[player_num]->standup[1][2] = 0.0f;
    g_playerPointers[player_num]->standcnt = 0;

    for (i = 0; i < 2; i++)
    {
        g_playerPointers[player_num]->viewports[i].vp.vscale[0] = 0x280;
        g_playerPointers[player_num]->viewports[i].vp.vscale[1] = 0x1E0;
        g_playerPointers[player_num]->viewports[i].vp.vscale[2] = 0x1FF;
        g_playerPointers[player_num]->viewports[i].vp.vscale[3] = 0;
        g_playerPointers[player_num]->viewports[i].vp.vtrans[0] = 0x280;
        g_playerPointers[player_num]->viewports[i].vp.vtrans[1] = 0x1E0;
        g_playerPointers[player_num]->viewports[i].vp.vtrans[2] = 0x1FF;
        g_playerPointers[player_num]->viewports[i].vp.vtrans[3] = 0;
    }

    g_playerPointers[player_num]->viewx = 0x64;
    g_playerPointers[player_num]->viewy = 0x64;
    g_playerPointers[player_num]->viewleft = 0;
    g_playerPointers[player_num]->viewtop = 0;
    g_playerPointers[player_num]->hand_invisible[0] = 0;
    g_playerPointers[player_num]->hand_invisible[1] = 0;
    g_playerPointers[player_num]->hand_item[0] = 0;
    g_playerPointers[player_num]->hand_item[1] = 0;
    g_playerPointers[player_num]->field_2A44[0] = -1;
    g_playerPointers[player_num]->field_2A44[1] = -1;
    g_playerPointers[player_num]->lock_hand_model[0] = 0;
    g_playerPointers[player_num]->lock_hand_model[1] = 0;
    g_playerPointers[player_num]->ptr_hand_weapon_buffer[0] = NULL;
    g_playerPointers[player_num]->ptr_hand_weapon_buffer[1] = NULL;

    g_playerPointers[player_num]->hands[0] = default_hand;
    g_playerPointers[player_num]->hands[1] = default_hand;

    g_playerPointers[player_num]->gunposamplitude = 1.0f;
    g_playerPointers[player_num]->gunxamplitude = 1.0f;
    g_playerPointers[player_num]->field_FC8 = 0;
    g_playerPointers[player_num]->field_FCC = 0;
    g_playerPointers[player_num]->field_FD0 = 0;
    g_playerPointers[player_num]->z_trigger_timer = 0;
    g_playerPointers[player_num]->field_FD8 = 0;
    g_playerPointers[player_num]->field_FDC = 0xFF;
    g_playerPointers[player_num]->field_FDD = 0xFF;
    g_playerPointers[player_num]->field_FDE = 0xFF;
    g_playerPointers[player_num]->field_FDF = 0;
    g_playerPointers[player_num]->resetshadecol = 1;
    g_playerPointers[player_num]->field_FE4 = 0;
    g_playerPointers[player_num]->crosshair_angle.x = 0.0f;
    g_playerPointers[player_num]->crosshair_angle.y = 0.0f;
    g_playerPointers[player_num]->crosshair_x_pos = 0.0f;
    g_playerPointers[player_num]->crosshair_y_pos = 0.0f;
    g_playerPointers[player_num]->guncrossdamp = 0.9f;
    g_playerPointers[player_num]->field_FFC.x = 0.0f;
    g_playerPointers[player_num]->field_FFC.y = 0.0f;
    g_playerPointers[player_num]->gun_azimuth_angle = 0.0f;
    g_playerPointers[player_num]->gun_azimuth_turning = 0.0f;
    g_playerPointers[player_num]->gunaimdamp = 0.9f;
    g_playerPointers[player_num]->field_1010.x = 0.0f;
    g_playerPointers[player_num]->field_1010.y = -3.1415927f;
    g_playerPointers[player_num]->field_1010.z = 0.0f;
    g_playerPointers[player_num]->last_z_trigger_timer = 0;
    g_playerPointers[player_num]->copiedgoldeneye = 0;
    g_playerPointers[player_num]->ammodispflags = 0;
    g_playerPointers[player_num]->field_106C = 0.0f;
    g_playerPointers[player_num]->field_1070 = 0.0f;
    g_playerPointers[player_num]->field_1074 = 0.0f;
    g_playerPointers[player_num]->field_1078 = 0;

    g_playerPointers[player_num]->field_107C = 0.0f;
    g_playerPointers[player_num]->field_1080 = 0.0f;
    g_playerPointers[player_num]->sniper_zoom = 60.0f;
    g_playerPointers[player_num]->camera_zoom = 60.0f;
    g_playerPointers[player_num]->field_108C = -1;
    g_playerPointers[player_num]->c_screenwidth = 320.0f;
    g_playerPointers[player_num]->c_screenheight = 240.0f;
    g_playerPointers[player_num]->c_screenleft = 0.0f;
    g_playerPointers[player_num]->c_screentop = 0.0f;
    g_playerPointers[player_num]->c_perspnear = 10.0f;
    g_playerPointers[player_num]->c_perspfovy = 46.0f;
    g_playerPointers[player_num]->c_perspaspect = 1.0f;
    g_playerPointers[player_num]->c_halfwidth = 160.0f;
    g_playerPointers[player_num]->c_halfheight = 120.0f;
    g_playerPointers[player_num]->c_scalex = 1.0f;
    g_playerPointers[player_num]->c_scaley = 1.0f;
    g_playerPointers[player_num]->c_recipscalex = 1.0f;
    g_playerPointers[player_num]->c_recipscaley = 1.0f;
    g_playerPointers[player_num]->field_10C4 = NULL;
    g_playerPointers[player_num]->field_10C8 = NULL;
    g_playerPointers[player_num]->field_10CC = NULL;
    g_playerPointers[player_num]->field_10D0 = 0;
    g_playerPointers[player_num]->field_10D4 = NULL;
    g_playerPointers[player_num]->projmatrix = NULL;
    g_playerPointers[player_num]->projmatrixf = NULL;
    g_playerPointers[player_num]->field_10E0 = 0;
    g_playerPointers[player_num]->field_10E4 = 0;
    g_playerPointers[player_num]->field_10E8 = NULL;
    g_playerPointers[player_num]->field_10EC = NULL;
    g_playerPointers[player_num]->c_scalelod60 = 1.0f;
    g_playerPointers[player_num]->c_scalelod = 1.0f;
    g_playerPointers[player_num]->c_lodscalez = 1.0f;
    g_playerPointers[player_num]->c_lodscalezu32 = 0x10000;
    g_playerPointers[player_num]->screenxminf = 0.0f;
    g_playerPointers[player_num]->screenyminf = 0.0f;
    g_playerPointers[player_num]->screenxmaxf = 320.0f;
    g_playerPointers[player_num]->screenymaxf = 240.0f;
    g_playerPointers[player_num]->gunsightmode = 0;
    g_playerPointers[player_num]->bloodImgBufPtrArray[0] = NULL;
    g_playerPointers[player_num]->bloodImgBufPtrArray[1] = NULL;
    g_playerPointers[player_num]->bloodImgIdx = 0;
    g_playerPointers[player_num]->zoomintime = 0.0f;
    g_playerPointers[player_num]->zoomintimemax = 0.0f;
    g_playerPointers[player_num]->zoominfovy = 60.0f;
    g_playerPointers[player_num]->zoominfovyold = 60.0f;
    g_playerPointers[player_num]->zoominfovynew = 60.0f;
    g_playerPointers[player_num]->fovy = 60.0f;
    g_playerPointers[player_num]->aspect = 1.3333334f;
    g_playerPointers[player_num]->hudmessoff = 0;
    g_playerPointers[player_num]->bondmesscnt = -1;
    g_playerPointers[player_num]->ptr_inventory_first_in_cycle = NULL;
    g_playerPointers[player_num]->p_itemcur = NULL;
    g_playerPointers[player_num]->equipmaxitems = 0;
    g_playerPointers[player_num]->equipallguns = 0;
    one = 1;
    g_playerPointers[player_num]->equipcuritem = 0;
    g_playerPointers[player_num]->textoverrides = NULL;
    g_playerPointers[player_num]->field_1280 = 0.0f;
    g_playerPointers[player_num]->players_cur_animation = 0;
    g_playerPointers[player_num]->field_1288 = 0.0f;
    g_playerPointers[player_num]->bondinvincible = 0;
    g_playerPointers[player_num]->field_29B8 = 7;
    g_playerPointers[player_num]->field_29BC = 1.0f;
    g_playerPointers[player_num]->field_29C0 = 0.0f;
    g_playerPointers[player_num]->mpmenuon = 0;
    g_playerPointers[player_num]->damagetype = 7;
    g_playerPointers[player_num]->deathcount = 0;
    g_playerPointers[player_num]->field_29E0 = random_byte++;
    g_playerPointers[player_num]->last_kill_time[0] = -1;
    g_playerPointers[player_num]->last_kill_time[1] = -1;
    g_playerPointers[player_num]->last_kill_time[2] = -1;
    g_playerPointers[player_num]->last_kill_time[3] = -1;
    g_playerPointers[player_num]->healthdisplaytime = 0;
    g_playerPointers[player_num]->field_2A30 = 0;
    g_playerPointers[player_num]->field_2A34 = 0;
    g_playerPointers[player_num]->cur_item_weapon_getname = 1;
    g_playerPointers[player_num]->actual_health = 1.0f;
    g_playerPointers[player_num]->actual_armor = 1.0f;
    g_playerPointers[player_num]->cur_player_control_type_0 = 0;
    g_playerPointers[player_num]->cur_player_control_type_1 = 0;
    g_playerPointers[player_num]->cur_player_control_type_2 = 0.0f;
    g_playerPointers[player_num]->neg_vspacing_for_control_type_entry = 0;
    g_playerPointers[player_num]->has_set_control_type_data = one;
    g_playerPointers[player_num]->field_2A6C = 0;
    g_playerPointers[player_num]->field_2A70 = NULL;

    g_VisibleToGuardsFlag = 1;
    obj_collision_flag = 1;
}
#endif


void set_cur_player(s32 playernum)
{
    player_num = playernum;
    g_CurrentPlayer = g_playerPointers[playernum];
    g_playerPerm = &g_playerPlayerData[playernum];
}


s32 get_cur_playernum(void) {
    return player_num;
}


s32 sub_GAME_7F09B15C( PropRecord* prop)
{
    s32 i;

    for(i = 0; i < getPlayerCount(); i++) {
        if (g_playerPointers[i]->prop == prop) {
           return i;
        }
    }

    return -1;
}


void set_cur_player_screen_size(u32 width, u32 height) {
    #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x25a,"Assertion failed: g_CurrentPlayer");
    }
    #endif
  g_CurrentPlayer->viewx = width;
  g_CurrentPlayer->viewy = height;
}

void set_cur_player_viewport_size(u32 ulx, u32 uly) {
        #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x262,"Assertion failed: g_CurrentPlayer");
    }
    #endif
  g_CurrentPlayer->viewleft = ulx;
  g_CurrentPlayer->viewtop = uly;
}

void set_cur_player_fovy(f32 fovy) {
            #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x26a,"Assertion failed: g_CurrentPlayer");
    }
    #endif
    g_CurrentPlayer->fovy = fovy;
}

void set_cur_player_aspect(f32 aspect) {
    #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x271,"Assertion failed: g_CurrentPlayer");
    }
    #endif
    g_CurrentPlayer->aspect = aspect;
}

f32 get_cur_player_fovy(void) {
    #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x278,"Assertion failed: g_CurrentPlayer");
    }
    #endif
    return g_CurrentPlayer->fovy;
}






#ifdef NONMATCHING
void sub_GAME_7F09B244(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005762C*/
glabel jpt_weapon_multi
.word weapon_multi_none
.word weapon_multi_none
.word weapon_multi_hunting_knife
.word weapon_multi_throwing_knife
.word weapon_multi_pp7
.word weapon_multi_pp7_silent
.word weapon_multi_dd44
.word weapon_multi_klobb
.word weapon_multi_kf7
.word weapon_multi_zmg
.word weapon_multi_d5k
.word weapon_multi_d5k_silent
.word weapon_multi_phantom
.word weapon_multi_ar33
.word weapon_multi_rcp90
.word weapon_multi_shotgun
.word weapon_multi_auto_shot
.word weapon_multi_sniper
.word weapon_multi_cougar
.word weapon_multi_goldengun
.word weapon_multi_pp7_special1
.word weapon_multi_pp7_special2
.word weapon_multi_moonraker
/*.word weapon_multi_none*/
/*.word weapon_multi_grenade_laun*/
/*.word weapon_multi_rocket_launch*/
/*.word weapon_multi_hand*/
/*.word weapon_multi_timed*/
/*.word weapon_multi_prox*/
/*.word weapon_multi_remote*/
/*.word weapon_multi_none*/
/*.word weapon_multi_none*/

.text
glabel sub_GAME_7F09B244
/* 0CFD74 7F09B244 28810020 */  slti  $at, $a0, 0x20
/* 0CFD78 7F09B248 14200006 */  bnez  $at, .L7F09B264
/* 0CFD7C 7F09B24C 2403FFFF */   li    $v1, -1
/* 0CFD80 7F09B250 24010058 */  li    $at, 88
/* 0CFD84 7F09B254 50810042 */  beql  $a0, $at, .L7F09B360
/* 0CFD88 7F09B258 2403014D */   li    $v1, 333
/* 0CFD8C 7F09B25C 03E00008 */  jr    $ra
/* 0CFD90 7F09B260 00601025 */   move  $v0, $v1

.L7F09B264:
/* 0CFD94 7F09B264 2C810020 */  sltiu $at, $a0, 0x20
/* 0CFD98 7F09B268 1020003D */  beqz  $at, .L7F09B360
/* 0CFD9C 7F09B26C 00047080 */   sll   $t6, $a0, 2
/* 0CFDA0 7F09B270 3C018005 */  lui   $at, %hi(jpt_weapon_multi)
/* 0CFDA4 7F09B274 002E0821 */  addu  $at, $at, $t6
/* 0CFDA8 7F09B278 8C2E762C */  lw    $t6, %lo(jpt_weapon_multi)($at)
/* 0CFDAC 7F09B27C 01C00008 */  jr    $t6
/* 0CFDB0 7F09B280 00000000 */   nop
weapon_multi_hunting_knife:
/* 0CFDB4 7F09B284 03E00008 */  jr    $ra
/* 0CFDB8 7F09B288 240200BA */   li    $v0, 186

weapon_multi_pp7:
/* 0CFDBC 7F09B28C 03E00008 */  jr    $ra
/* 0CFDC0 7F09B290 240200BF */   li    $v0, 191

weapon_multi_klobb:
/* 0CFDC4 7F09B294 03E00008 */  jr    $ra
/* 0CFDC8 7F09B298 240200C1 */   li    $v0, 193

weapon_multi_kf7:
/* 0CFDCC 7F09B29C 03E00008 */  jr    $ra
/* 0CFDD0 7F09B2A0 240200B8 */   li    $v0, 184

weapon_multi_zmg:
/* 0CFDD4 7F09B2A4 03E00008 */  jr    $ra
/* 0CFDD8 7F09B2A8 240200C3 */   li    $v0, 195

weapon_multi_d5k:
/* 0CFDDC 7F09B2AC 03E00008 */  jr    $ra
/* 0CFDE0 7F09B2B0 240200BD */   li    $v0, 189

weapon_multi_phantom:
/* 0CFDE4 7F09B2B4 03E00008 */  jr    $ra
/* 0CFDE8 7F09B2B8 240200C2 */   li    $v0, 194

weapon_multi_ar33:
/* 0CFDEC 7F09B2BC 03E00008 */  jr    $ra
/* 0CFDF0 7F09B2C0 240200BC */   li    $v0, 188

weapon_multi_rcp90:
/* 0CFDF4 7F09B2C4 03E00008 */  jr    $ra
/* 0CFDF8 7F09B2C8 240200C5 */   li    $v0, 197

weapon_multi_shotgun:
/* 0CFDFC 7F09B2CC 03E00008 */  jr    $ra
/* 0CFE00 7F09B2D0 240200C0 */   li    $v0, 192

weapon_multi_grenade_laun:
/* 0CFE04 7F09B2D4 03E00008 */  jr    $ra
/* 0CFE08 7F09B2D8 240200B9 */   li    $v0, 185

weapon_multi_hand:
/* 0CFE0C 7F09B2DC 03E00008 */  jr    $ra
/* 0CFE10 7F09B2E0 240200C4 */   li    $v0, 196

weapon_multi_remote:
/* 0CFE14 7F09B2E4 03E00008 */  jr    $ra
/* 0CFE18 7F09B2E8 240200C7 */   li    $v0, 199

weapon_multi_prox:
/* 0CFE1C 7F09B2EC 03E00008 */  jr    $ra
/* 0CFE20 7F09B2F0 240200C8 */   li    $v0, 200

weapon_multi_timed:
/* 0CFE24 7F09B2F4 03E00008 */  jr    $ra
/* 0CFE28 7F09B2F8 240200C9 */   li    $v0, 201

weapon_multi_cougar:
/* 0CFE2C 7F09B2FC 03E00008 */  jr    $ra
/* 0CFE30 7F09B300 240200BE */   li    $v0, 190

weapon_multi_moonraker:
/* 0CFE34 7F09B304 03E00008 */  jr    $ra
/* 0CFE38 7F09B308 240200BB */   li    $v0, 187

weapon_multi_sniper:
/* 0CFE3C 7F09B30C 03E00008 */  jr    $ra
/* 0CFE40 7F09B310 240200D2 */   li    $v0, 210

weapon_multi_d5k_silent:
/* 0CFE44 7F09B314 03E00008 */  jr    $ra
/* 0CFE48 7F09B318 240200CE */   li    $v0, 206

weapon_multi_dd44:
/* 0CFE4C 7F09B31C 03E00008 */  jr    $ra
/* 0CFE50 7F09B320 240200CD */   li    $v0, 205

weapon_multi_pp7_silent:
/* 0CFE54 7F09B324 03E00008 */  jr    $ra
/* 0CFE58 7F09B328 240200CC */   li    $v0, 204

weapon_multi_throwing_knife:
/* 0CFE5C 7F09B32C 03E00008 */  jr    $ra
/* 0CFE60 7F09B330 240200D1 */   li    $v0, 209

weapon_multi_auto_shot:
/* 0CFE64 7F09B334 03E00008 */  jr    $ra
/* 0CFE68 7F09B338 240200CF */   li    $v0, 207

weapon_multi_rocket_launch:
/* 0CFE6C 7F09B33C 03E00008 */  jr    $ra
/* 0CFE70 7F09B340 240200D3 */   li    $v0, 211

weapon_multi_goldengun:
/* 0CFE74 7F09B344 03E00008 */  jr    $ra
/* 0CFE78 7F09B348 240200D0 */   li    $v0, 208

weapon_multi_pp7_special1:
/* 0CFE7C 7F09B34C 03E00008 */  jr    $ra
/* 0CFE80 7F09B350 240200BF */   li    $v0, 191

weapon_multi_pp7_special2:
/* 0CFE84 7F09B354 03E00008 */  jr    $ra
/* 0CFE88 7F09B358 240200BF */   li    $v0, 191

/* 0CFE8C 7F09B35C 2403014D */  li    $v1, 333
weapon_multi_none:
.L7F09B360:
/* 0CFE90 7F09B360 03E00008 */  jr    $ra
/* 0CFE94 7F09B364 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09B368(s32 arg0) {
    // Node 0
    return chrSetWeaponFlag4(g_CurrentPlayer->unkA8->unk4, arg0);
}

#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word weapon_multi_none
.word weapon_multi_grenade_laun
.word weapon_multi_rocket_launch
/*.word weapon_multi_hand*/
/*.word weapon_multi_timed*/
/*.word weapon_multi_prox*/
/*.word weapon_multi_remote*/
/*.word weapon_multi_none*/
/*.word weapon_multi_none*/
.text
glabel sub_GAME_7F09B368
/* 0CFE98 7F09B368 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0CFE9C 7F09B36C 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0CFEA0 7F09B370 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0CFEA4 7F09B374 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CFEA8 7F09B378 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0CFEAC 7F09B37C 00802825 */  move  $a1, $a0
/* 0CFEB0 7F09B380 0FC1487A */  jal   chrSetWeaponFlag4
/* 0CFEB4 7F09B384 8DE40004 */   lw    $a0, 4($t7)
/* 0CFEB8 7F09B388 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CFEBC 7F09B38C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0CFEC0 7F09B390 03E00008 */  jr    $ra
/* 0CFEC4 7F09B394 00000000 */   nop
)
#endif





#ifdef NONMATCHING
// NOTE: i think the return value from
// something_with_generating_object is supposed
// to be returned here?
void sub_GAME_7F09B398(GUNHAND hand) {
    struct ChrRecord* temp_v0;
    ITEM_IDS weaponNum;
    s32 weaponIdMaybe;

    temp_v0 = g_CurrentPlayer->prop->chr;
    if (!temp_v0->handle_positiondata[hand]) {
        weaponNum = getCurrentPlayerWeaponId(hand);
        weaponIdMaybe = sub_GAME_7F09B244(weaponNum);
        if (weaponIdMaybe >= 0) {
            something_with_generating_object(temp_v0, weaponIdMaybe, weaponNum, hand == GUNRIGHT ? 0 : 0x10000000, 0, 0);
        }
    }
}
#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word weapon_multi_hand
.word weapon_multi_timed
.word weapon_multi_prox
.word weapon_multi_remote
.word weapon_multi_none
.word weapon_multi_none

.text
glabel sub_GAME_7F09B398
/* 0CFEC8 7F09B398 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0CFECC 7F09B39C 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0CFED0 7F09B3A0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0CFED4 7F09B3A4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0CFED8 7F09B3A8 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0CFEDC 7F09B3AC 00041880 */  sll   $v1, $a0, 2
/* 0CFEE0 7F09B3B0 8DE20004 */  lw    $v0, 4($t7)
/* 0CFEE4 7F09B3B4 0043C021 */  addu  $t8, $v0, $v1
/* 0CFEE8 7F09B3B8 8F190160 */  lw    $t9, 0x160($t8)
/* 0CFEEC 7F09B3BC 57200014 */  bnezl $t9, .L7F09B410
/* 0CFEF0 7F09B3C0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0CFEF4 7F09B3C4 AFA20034 */  sw    $v0, 0x34($sp)
/* 0CFEF8 7F09B3C8 0FC17674 */  jal   getCurrentPlayerWeaponId
/* 0CFEFC 7F09B3CC AFA30024 */   sw    $v1, 0x24($sp)
/* 0CFF00 7F09B3D0 AFA20030 */  sw    $v0, 0x30($sp)
/* 0CFF04 7F09B3D4 0FC26C91 */  jal   sub_GAME_7F09B244
/* 0CFF08 7F09B3D8 00402025 */   move  $a0, $v0
/* 0CFF0C 7F09B3DC 8FA30024 */  lw    $v1, 0x24($sp)
/* 0CFF10 7F09B3E0 0440000A */  bltz  $v0, .L7F09B40C
/* 0CFF14 7F09B3E4 00402825 */   move  $a1, $v0
/* 0CFF18 7F09B3E8 14600003 */  bnez  $v1, .L7F09B3F8
/* 0CFF1C 7F09B3EC 8FA40034 */   lw    $a0, 0x34($sp)
/* 0CFF20 7F09B3F0 10000002 */  b     .L7F09B3FC
/* 0CFF24 7F09B3F4 00003825 */   move  $a3, $zero
.L7F09B3F8:
/* 0CFF28 7F09B3F8 3C071000 */  lui   $a3, 0x1000
.L7F09B3FC:
/* 0CFF2C 7F09B3FC 8FA60030 */  lw    $a2, 0x30($sp)
/* 0CFF30 7F09B400 AFA00010 */  sw    $zero, 0x10($sp)
/* 0CFF34 7F09B404 0FC14885 */  jal   something_with_generating_object
/* 0CFF38 7F09B408 AFA00014 */   sw    $zero, 0x14($sp)
.L7F09B40C:
/* 0CFF3C 7F09B40C 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F09B410:
/* 0CFF40 7F09B410 27BD0038 */  addiu $sp, $sp, 0x38
/* 0CFF44 7F09B414 03E00008 */  jr    $ra
/* 0CFF48 7F09B418 00000000 */   nop
)
#endif





void shuffle_player_ids(void) {
    s32 i;
    u32 random;
    PLAYER_ID temp;

    for (i = 0; i < 4; i ++) {
        array_PLAYER_IDs[i] = i;
    }

    for (i = 0; i < 3; i ++) {
        random = randomGetNext();
        temp = array_PLAYER_IDs[i];
        array_PLAYER_IDs[i] = array_PLAYER_IDs[i + random % (4 - i)];
        array_PLAYER_IDs[i + random % (4 - i)] = temp;
    }
}





s32 sub_GAME_7F09B4D8(s32 current_player_num) {
    s32 i;
    s32 position = 0;

    for (i = 0; i < 4; i++) {
        if (current_player_num != array_PLAYER_IDs[i])
        {
            if (g_playerPointers[array_PLAYER_IDs[i]] != NULL)
            {
                position++;
            }
        }
        else
        {
            break;
        }
    }

    return position;
}






s32 get_nth_player_from_shuffled(PLAYER_ID id)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        if (g_playerPointers[array_PLAYER_IDs[i]] != NULL) {
            if (id == 0) {
               return array_PLAYER_IDs[i];
            }
            id--;
        }
    }

    return 0;
}

