#include <ultra64.h>
#include <bondconstants.h>
#include <memp.h>
#include "chr.h"
#include "chr_b.h"
#include "deb_loadallmodels.h"
#include "loadobjectmodel.h"
#include "aicommands2.h"

//i belong in a header, probably to another file






u32 global_action_block_temp_buffer[119] = {0};

s32 weapon_models_for_weapon_load[] = {
    PROJECTILES_TYPE_KNIFE, PROJECTILES_TYPE_GRENADE, 
    PROJECTILES_TYPE_REMOTE_MINE, PROJECTILES_TYPE_PROX_MINE,
    PROJECTILES_TYPE_TIMED_MINE, PROJECTILES_TYPE_ROCKET_ROUND,
    PROJECTILES_TYPE_GLAUNCH_ROUND, 0xFFFFFFFF
};




void init_obj_register_difficulty_vals(void) {
    objectiveregisters1 = 0;
    g_AiAccuracyModifier = 1.0f;
    g_AiDamageModifier = 1.0f;
    g_AiHealthModifier = 1.0f;
    g_AiReactionSpeed = 1.0f;
    g_SeenBondRecentlyGuardCount = 0;
}



#ifdef NONMATCHING
void alloc_false_GUARDdata_to_exec_global_action(void) {

}
#else
GLOBAL_ASM(
.text
glabel alloc_false_GUARDdata_to_exec_global_action
/* 035B8C 7F00105C 3C0D8007 */  lui   $t5, %hi(g_CurrentSetup+0) 
/* 035B90 7F001060 25AD5D00 */  addiu $t5, %lo(g_CurrentSetup+0) # addiu $t5, $t5, 0x5d00
/* 035B94 7F001064 8DA50014 */  lw    $a1, 0x14($t5)
/* 035B98 7F001068 3C028003 */  lui   $v0, %hi(g_ActiveChrsCount)
/* 035B9C 7F00106C 3C068003 */  lui   $a2, %hi(g_ActiveChrs)
/* 035BA0 7F001070 24C6097C */  addiu $a2, %lo(g_ActiveChrs) # addiu $a2, $a2, 0x97c
/* 035BA4 7F001074 24420980 */  addiu $v0, %lo(g_ActiveChrsCount) # addiu $v0, $v0, 0x980
/* 035BA8 7F001078 27BDFDF8 */  addiu $sp, $sp, -0x208
/* 035BAC 7F00107C AFBF0014 */  sw    $ra, 0x14($sp)
/* 035BB0 7F001080 ACC00000 */  sw    $zero, ($a2)
/* 035BB4 7F001084 10A00070 */  beqz  $a1, .L7F001248
/* 035BB8 7F001088 AC400000 */   sw    $zero, ($v0)
/* 035BBC 7F00108C 8CAE0000 */  lw    $t6, ($a1)
/* 035BC0 7F001090 00A01825 */  move  $v1, $a1
/* 035BC4 7F001094 00003825 */  move  $a3, $zero
/* 035BC8 7F001098 11C0000C */  beqz  $t6, .L7F0010CC
/* 035BCC 7F00109C 24050004 */   li    $a1, 4
/* 035BD0 7F0010A0 8C6F0004 */  lw    $t7, 4($v1)
.L7F0010A4:
/* 035BD4 7F0010A4 29E11000 */  slti  $at, $t7, 0x1000
/* 035BD8 7F0010A8 54200005 */  bnezl $at, .L7F0010C0
/* 035BDC 7F0010AC 8C6E0008 */   lw    $t6, 8($v1)
/* 035BE0 7F0010B0 8C580000 */  lw    $t8, ($v0)
/* 035BE4 7F0010B4 27190001 */  addiu $t9, $t8, 1
/* 035BE8 7F0010B8 AC590000 */  sw    $t9, ($v0)
/* 035BEC 7F0010BC 8C6E0008 */  lw    $t6, 8($v1)
.L7F0010C0:
/* 035BF0 7F0010C0 24630008 */  addiu $v1, $v1, 8
/* 035BF4 7F0010C4 55C0FFF7 */  bnezl $t6, .L7F0010A4
/* 035BF8 7F0010C8 8C6F0004 */   lw    $t7, 4($v1)
.L7F0010CC:
/* 035BFC 7F0010CC 8C430000 */  lw    $v1, ($v0)
/* 035C00 7F0010D0 00004025 */  move  $t0, $zero
/* 035C04 7F0010D4 1860005C */  blez  $v1, .L7F001248
/* 035C08 7F0010D8 00032100 */   sll   $a0, $v1, 4
/* 035C0C 7F0010DC 00832023 */  subu  $a0, $a0, $v1
/* 035C10 7F0010E0 000420C0 */  sll   $a0, $a0, 3
/* 035C14 7F0010E4 00832023 */  subu  $a0, $a0, $v1
/* 035C18 7F0010E8 00042080 */  sll   $a0, $a0, 2
/* 035C1C 7F0010EC 2484000F */  addiu $a0, $a0, 0xf
/* 035C20 7F0010F0 348F000F */  ori   $t7, $a0, 0xf
/* 035C24 7F0010F4 39E4000F */  xori  $a0, $t7, 0xf
/* 035C28 7F0010F8 0C0025C8 */  jal   mempAllocBytesInBank
/* 035C2C 7F0010FC AFA70200 */   sw    $a3, 0x200($sp)
/* 035C30 7F001100 3C0D8007 */  lui   $t5, %hi(g_CurrentSetup+0) 
/* 035C34 7F001104 25AD5D00 */  addiu $t5, %lo(g_CurrentSetup+0) # addiu $t5, $t5, 0x5d00
/* 035C38 7F001108 8DA50014 */  lw    $a1, 0x14($t5)
/* 035C3C 7F00110C 3C068003 */  lui   $a2, %hi(g_ActiveChrs)
/* 035C40 7F001110 24C6097C */  addiu $a2, %lo(g_ActiveChrs) # addiu $a2, $a2, 0x97c
/* 035C44 7F001114 ACC20000 */  sw    $v0, ($a2)
/* 035C48 7F001118 8CB90000 */  lw    $t9, ($a1)
/* 035C4C 7F00111C 8FA70200 */  lw    $a3, 0x200($sp)
/* 035C50 7F001120 00002025 */  move  $a0, $zero
/* 035C54 7F001124 13200048 */  beqz  $t9, .L7F001248
/* 035C58 7F001128 00A01825 */   move  $v1, $a1
/* 035C5C 7F00112C 3C088003 */  lui   $t0, %hi(global_action_block_temp_buffer) 
/* 035C60 7F001130 2508A060 */  addiu $t0, %lo(global_action_block_temp_buffer) # addiu $t0, $t0, -0x5fa0
/* 035C64 7F001134 240C001A */  li    $t4, 26
/* 035C68 7F001138 240BFFFF */  li    $t3, -1
/* 035C6C 7F00113C 240A00FE */  li    $t2, 254
/* 035C70 7F001140 240901DC */  li    $t1, 476
/* 035C74 7F001144 27A50024 */  addiu $a1, $sp, 0x24
/* 035C78 7F001148 8C6E0004 */  lw    $t6, 4($v1)
.L7F00114C:
/* 035C7C 7F00114C 0100C825 */  move  $t9, $t0
/* 035C80 7F001150 251801D4 */  addiu $t8, $t0, 0x1d4
/* 035C84 7F001154 29C11000 */  slti  $at, $t6, 0x1000
/* 035C88 7F001158 14200036 */  bnez  $at, .L7F001234
/* 035C8C 7F00115C 00A07025 */   move  $t6, $a1
.L7F001160:
/* 035C90 7F001160 8F210000 */  lw    $at, ($t9)
/* 035C94 7F001164 2739000C */  addiu $t9, $t9, 0xc
/* 035C98 7F001168 25CE000C */  addiu $t6, $t6, 0xc
/* 035C9C 7F00116C ADC1FFF4 */  sw    $at, -0xc($t6)
/* 035CA0 7F001170 8F21FFF8 */  lw    $at, -8($t9)
/* 035CA4 7F001174 ADC1FFF8 */  sw    $at, -8($t6)
/* 035CA8 7F001178 8F21FFFC */  lw    $at, -4($t9)
/* 035CAC 7F00117C 1738FFF8 */  bne   $t9, $t8, .L7F001160
/* 035CB0 7F001180 ADC1FFFC */   sw    $at, -4($t6)
/* 035CB4 7F001184 00E90019 */  multu $a3, $t1
/* 035CB8 7F001188 8F210000 */  lw    $at, ($t9)
/* 035CBC 7F00118C ADC10000 */  sw    $at, ($t6)
/* 035CC0 7F001190 8F380004 */  lw    $t8, 4($t9)
/* 035CC4 7F001194 ADD80004 */  sw    $t8, 4($t6)
/* 035CC8 7F001198 8CCF0000 */  lw    $t7, ($a2)
/* 035CCC 7F00119C 00001012 */  mflo  $v0
/* 035CD0 7F0011A0 24AE01D4 */  addiu $t6, $a1, 0x1d4
/* 035CD4 7F0011A4 01E2C021 */  addu  $t8, $t7, $v0
/* 035CD8 7F0011A8 00A07825 */  move  $t7, $a1
.L7F0011AC:
/* 035CDC 7F0011AC 8DE10000 */  lw    $at, ($t7)
/* 035CE0 7F0011B0 25EF000C */  addiu $t7, $t7, 0xc
/* 035CE4 7F0011B4 2718000C */  addiu $t8, $t8, 0xc
/* 035CE8 7F0011B8 AF01FFF4 */  sw    $at, -0xc($t8)
/* 035CEC 7F0011BC 8DE1FFF8 */  lw    $at, -8($t7)
/* 035CF0 7F0011C0 AF01FFF8 */  sw    $at, -8($t8)
/* 035CF4 7F0011C4 8DE1FFFC */  lw    $at, -4($t7)
/* 035CF8 7F0011C8 15EEFFF8 */  bne   $t7, $t6, .L7F0011AC
/* 035CFC 7F0011CC AF01FFFC */   sw    $at, -4($t8)
/* 035D00 7F0011D0 8DE10000 */  lw    $at, ($t7)
/* 035D04 7F0011D4 24E70001 */  addiu $a3, $a3, 1
/* 035D08 7F0011D8 AF010000 */  sw    $at, ($t8)
/* 035D0C 7F0011DC 8DEE0004 */  lw    $t6, 4($t7)
/* 035D10 7F0011E0 AF0E0004 */  sw    $t6, 4($t8)
/* 035D14 7F0011E4 8CD90000 */  lw    $t9, ($a2)
/* 035D18 7F0011E8 03227021 */  addu  $t6, $t9, $v0
/* 035D1C 7F0011EC A5CA0000 */  sh    $t2, ($t6)
/* 035D20 7F0011F0 8DAF0014 */  lw    $t7, 0x14($t5)
/* 035D24 7F0011F4 8CCE0000 */  lw    $t6, ($a2)
/* 035D28 7F0011F8 01E4C021 */  addu  $t8, $t7, $a0
/* 035D2C 7F0011FC 8F190000 */  lw    $t9, ($t8)
/* 035D30 7F001200 01C27821 */  addu  $t7, $t6, $v0
/* 035D34 7F001204 ADF90104 */  sw    $t9, 0x104($t7)
/* 035D38 7F001208 8CD80000 */  lw    $t8, ($a2)
/* 035D3C 7F00120C 03027021 */  addu  $t6, $t8, $v0
/* 035D40 7F001210 A5C00108 */  sh    $zero, 0x108($t6)
/* 035D44 7F001214 8CD90000 */  lw    $t9, ($a2)
/* 035D48 7F001218 03227821 */  addu  $t7, $t9, $v0
/* 035D4C 7F00121C A5EB010A */  sh    $t3, 0x10a($t7)
/* 035D50 7F001220 8CD80000 */  lw    $t8, ($a2)
/* 035D54 7F001224 03027021 */  addu  $t6, $t8, $v0
/* 035D58 7F001228 A1CC0007 */  sb    $t4, 7($t6)
/* 035D5C 7F00122C 8DB90014 */  lw    $t9, 0x14($t5)
/* 035D60 7F001230 03241821 */  addu  $v1, $t9, $a0
.L7F001234:
/* 035D64 7F001234 8C6F0008 */  lw    $t7, 8($v1)
/* 035D68 7F001238 24840008 */  addiu $a0, $a0, 8
/* 035D6C 7F00123C 24630008 */  addiu $v1, $v1, 8
/* 035D70 7F001240 55E0FFC2 */  bnezl $t7, .L7F00114C
/* 035D74 7F001244 8C6E0004 */   lw    $t6, 4($v1)
.L7F001248:
/* 035D78 7F001248 8FBF0014 */  lw    $ra, 0x14($sp)
/* 035D7C 7F00124C 27BD0208 */  addiu $sp, $sp, 0x208
/* 035D80 7F001250 03E00008 */  jr    $ra
/* 035D84 7F001254 00000000 */   nop   
)
#endif


void debug_object_load_all_models(void)
{
    u8 *cmd = &g_CurrentSetup.ailists[0].ailist->cmd;
    s32 i = 0;
    u16 id;

    if (!cmd) { return; }

    do
    {
        while (TRUE)
        {
            if (cmd[0] == AI_EndList)
            {
                break;
            }

            switch (cmd[0])
            {
                case AI_TRYDroppingItem:
                    id = cmd[2] | (cmd[1] << 8);
                    if (modelLoad(id));
                    break;

                case AI_TRYSpawningChrAtPad:
                    load_body_head_if_not_loaded(cmd[1]);
                    if ((s8)cmd[2] >= 0 && load_body_head_if_not_loaded((s8)cmd[2]));
                    break;

                case AI_TRYSpawningChrNextToChr:
                    load_body_head_if_not_loaded(cmd[1]);
                    if ((s8)cmd[2] >= 0 && load_body_head_if_not_loaded((s8)cmd[2]));
                    break;

                case AI_TRYGiveMeItem:
                    modelLoad(cmd[2] | (cmd[1] << 8));
                    if (weaponLoadProjectileModels(cmd[3]));
                    break;

                case AI_TRYGiveMeHat:
                    modelLoad(cmd[2] | (cmd[1] << 8));
                    break;
            }

            cmd += chraiitemsize(cmd, 0);
        }

        i++;
        cmd = &g_CurrentSetup.ailists[i].ailist->cmd;
    } while (cmd);
}


#ifdef NONMATCHING
void debug_weapon_load_table(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_weapon_load_table
/* 035F3C 7F00140C 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 035F40 7F001410 3C0F8003 */  lui   $t7, %hi(weapon_models_for_weapon_load) 
/* 035F44 7F001414 AFBF001C */  sw    $ra, 0x1c($sp)
/* 035F48 7F001418 AFB00018 */  sw    $s0, 0x18($sp)
/* 035F4C 7F00141C 25EFA23C */  addiu $t7, %lo(weapon_models_for_weapon_load) # addiu $t7, $t7, -0x5dc4
/* 035F50 7F001420 8DE10000 */  lw    $at, ($t7)
/* 035F54 7F001424 8DE80004 */  lw    $t0, 4($t7)
/* 035F58 7F001428 27AE0030 */  addiu $t6, $sp, 0x30
/* 035F5C 7F00142C ADC10000 */  sw    $at, ($t6)
/* 035F60 7F001430 ADC80004 */  sw    $t0, 4($t6)
/* 035F64 7F001434 8DE8000C */  lw    $t0, 0xc($t7)
/* 035F68 7F001438 8DE10008 */  lw    $at, 8($t7)
/* 035F6C 7F00143C 27B00030 */  addiu $s0, $sp, 0x30
/* 035F70 7F001440 ADC8000C */  sw    $t0, 0xc($t6)
/* 035F74 7F001444 ADC10008 */  sw    $at, 8($t6)
/* 035F78 7F001448 8DE10010 */  lw    $at, 0x10($t7)
/* 035F7C 7F00144C 8DE80014 */  lw    $t0, 0x14($t7)
/* 035F80 7F001450 ADC10010 */  sw    $at, 0x10($t6)
/* 035F84 7F001454 ADC80014 */  sw    $t0, 0x14($t6)
/* 035F88 7F001458 8DE8001C */  lw    $t0, 0x1c($t7)
/* 035F8C 7F00145C 8DE10018 */  lw    $at, 0x18($t7)
/* 035F90 7F001460 ADC8001C */  sw    $t0, 0x1c($t6)
/* 035F94 7F001464 ADC10018 */  sw    $at, 0x18($t6)
/* 035F98 7F001468 8FA90030 */  lw    $t1, 0x30($sp)
/* 035F9C 7F00146C 05220009 */  bltzl $t1, .L7F001494
/* 035FA0 7F001470 8FBF001C */   lw    $ra, 0x1c($sp)
/* 035FA4 7F001474 8E040000 */  lw    $a0, ($s0)
.L7F001478:
/* 035FA8 7F001478 0FC15B0E */  jal   modelLoad
/* 035FAC 7F00147C 00000000 */   nop   
/* 035FB0 7F001480 8E040004 */  lw    $a0, 4($s0)
/* 035FB4 7F001484 26100004 */  addiu $s0, $s0, 4
/* 035FB8 7F001488 0481FFFB */  bgez  $a0, .L7F001478
/* 035FBC 7F00148C 00000000 */   nop   
/* 035FC0 7F001490 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F001494:
/* 035FC4 7F001494 8FB00018 */  lw    $s0, 0x18($sp)
/* 035FC8 7F001498 27BD0050 */  addiu $sp, $sp, 0x50
/* 035FCC 7F00149C 03E00008 */  jr    $ra
/* 035FD0 7F0014A0 00000000 */   nop
)
#endif


