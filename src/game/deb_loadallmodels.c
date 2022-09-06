#include <ultra64.h>
#include <bondconstants.h>
#include <memp.h>
#include "chr.h"
#include "chr_b.h"
#include "deb_loadallmodels.h"
#include "loadobjectmodel.h"
#include "aicommands2.h"
#include "dyn.h"
#include "memp.h"

//i belong in a header, probably to another file

ChrRecord global_action_block_temp_buffer = { 0 };

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


void alloc_false_GUARDdata_to_exec_global_action(void)
{
    s32 i;
    s32 count;

    g_ActiveChrs = NULL;
    g_ActiveChrsCount = 0;

    if (!g_CurrentSetup.ailists) { return; }

    count = 0;

    // Count the number of background AI lists
    i = 0;
    while (g_CurrentSetup.ailists[i].ailist)
    {
        if (g_CurrentSetup.ailists[i].ID >= 0x1000)
        {
            g_ActiveChrsCount++;
        }

        i++;
    }

    if (g_ActiveChrsCount > 0)
    {
        ChrRecord tmp;

        // Allocate BG chrs
        g_ActiveChrs = mempAllocBytesInBank(ALIGN16_a(g_ActiveChrsCount * sizeof(ChrRecord)), MEMPOOL_STAGE);

        // Initialise BG chrs
        i = 0;
        while (g_CurrentSetup.ailists[i].ailist)
        {
            if (g_CurrentSetup.ailists[i].ID >= 0x1000)
            {
                tmp = global_action_block_temp_buffer;

                g_ActiveChrs[count] = tmp;

                g_ActiveChrs[count].chrnum = 0xFE;
                g_ActiveChrs[count].ailist = g_CurrentSetup.ailists[i].ailist;
                g_ActiveChrs[count].aioffset = 0;
                g_ActiveChrs[count].aireturnlist = -1;
                g_ActiveChrs[count].actiontype = ACT_NULL;
                count++;
            }

            i++;
        }
    }
}


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


