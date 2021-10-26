#include "ultra64.h"
#include "bondconstants.h"
#include "debugmenu_handler.h"
#include "joy.h"
#include "player.h"
#include "watch.h"
#include "gamefile.h"
#include "gamefile2.h"

/**
 *
 *
 * @return s32
 */
s32 sub_GAME_7F01D6C0(void)
{
  return joyGamePakProbe();
}

/**
 * Resets the RamRom replay folder save
 *
 */
void reset_ramrom_folder_to_default(void)
{
    save_data new_save = D_8002C520;

    saves[5] = new_save;
}

/**
 *
 *
 * @param save
 */
void sub_GAME_7F01D758(save_data *save)
{
    if (sub_GAME_7F01D6C0() != 0)
    {
        sub_GAME_7F09B600(&save->completion_bitflags, &save->times[14], save);
        joyGamePakLongWrite(0, save, 0x20);
    }
}

/**
 *
 *
 * @param save
 */
void sub_GAME_7F01D7A0(save_data *save)
{
    if (save >= &saves[0] && save < &saves[5])
    {
        if (sub_GAME_7F01D6C0() != 0)
        {
            sub_GAME_7F09B600(&save->completion_bitflags, save + 1, save);
            joyGamePakLongWrite((((u32)((save - &saves[0]) * 0x60) >> 3) + 4), save, 0x60);
        }
    }
}

/**
 * reset save to default
 *
 * @param save
 */
void reset_folder_to_default(save_data *save)
{
    save_data new_save  = D_8002C580;

    *save = new_save;
    sub_GAME_7F01D7A0(save);
}

/**
 * Get the foldernum of eeprom save
 *
 * @param eeprom
 * @return u32
 */
u32 get_foldernum_of_eeprom(save_data *eeprom)
{
  return eeprom->completion_bitflags & 7;
}

/**
 * Clear then set save foldernumber flag
 *
 * @param eeprom
 * @param folder
 */
void set_eeprom_to_folder_num(save_data *eeprom, u32 folder)
{
    eeprom->completion_bitflags &= 0xFFF8;
    eeprom->completion_bitflags |= folder & 7;
}

/**
 * Set save flag 0x18
 *
 * @param folder
 * @return u32
 */
u32 set_eeprom_flag_0x18(save_data *folder)
{
  return (folder->completion_bitflags & 0x18) >> 3;
}

/**
 * Resets save flag 0x18
 *
 * @param folder
 * @param arg1
 */
void reset_eeprom_flag_0x18(save_data *folder, s32 arg1)
{
    folder->completion_bitflags &= 0xFFE7;
    folder->completion_bitflags |= ((arg1 * 8) & 0x18);
}

/**
 * Get the selected bond save flag
 *
 * @param folder
 * @return u32
 */
u32 get_selected_bond(save_data *folder)
{
  return (folder->completion_bitflags & 0x60) >> 5;
}

/**
 * Set the selected bond save flag
 *
 * @param folder
 * @param arg1
 */
void set_selected_bond(save_data *folder, s32 arg1)
{
    folder->completion_bitflags &= 0xFF9F;
    folder->completion_bitflags |= ((arg1 << 5) & 0x60);
}

/**
 * Check if save has flag 0x80
 *
 * @param folder
 * @return u32
 */
u32 check_if_eeprom_flag_set_0x80(save_data *folder)
{
  return ((folder->completion_bitflags & 0x80) != 0);
}

/**
 * Toggle save flag 0x80
 * possibly wear levelling
 *
 * @param folder: folder to enable or disable flag
 * @param set: Enable flag if TRUE, Disable flag if FALSE
 */
void toggle_eeprom_flag_set_0x80(save_data *folder, s32 enable)
{
    if (enable)
    {
        folder->completion_bitflags |= 0x80;
    }
    else
    {
        folder->completion_bitflags &= ~0x80;
    }
}

/**
 * Get completion time for stage at difficulty
 *
 * @param save
 * @param stagenum
 * @param difficulty
 * @return best time for stage at difficulty
 */
s32 gamefileGetStageDifficultyTime(save_data* save, LEVEL_SOLO_SEQUENCE stagenum, DIFFICULTY difficulty)
{
    s32 offset;
    LEVEL_SOLO_SEQUENCE max_level;
    u32 time;
    s32 index;

    max_level = SP_LEVEL_MAX;
    if ((stagenum >= SP_LEVEL_DAM) && (stagenum < SP_LEVEL_MAX ) && (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_MAX))
    {
        if (difficulty == DIFFICULTY_007)
        {
            if (check_for_007_mode_unlocked(get_foldernum_of_eeprom(save)))
            {
                return 0x3FF; //max time
            }
            return 0;
        }

        offset = ((difficulty * max_level) + stagenum) * 10; //startbit
        index = (offset >> 3);

        switch(7 - (offset & 7)) //bitmask
        {
            case 7: //no offset
                // first 10 bits 8 + 2                    1111 1111                                      1100 0000
                time = ((save->times[index] & 0xFF) << 2) | ((save->times[index + 1] & 0xc0) >> 6);
                break;
            case 5: //offset 2
                // next 10 bits 6 + 4                     0011 1111                                      1111 0000
                time =  ((save->times[index] & 0x3f) << 4) | ((save->times[index + 1] & 0xf0) >> 4);
                break;
            case 3: //offset 4
                // next 10 bits 4 + 6                     0000 1111                                      1111 1100
                time =  ((save->times[index] & 0xf) << 6) | ((save->times[index + 1] & 0xfc) >> 2);
                break;
            case 1: //offset 6
                // next 10 bits 2 + 8                     0000 0011                                      1111 1111
                time = ((save->times[index] & 0x3)  << 8) | ((save->times[index + 1] & 0xFFF));
                break;
            default:
                time = 0; // shouldnt reach
        }

        return time;
    }

    return 0;
}

/**
 * Set completion time for stage at difficulty
 *
 * @param save
 * @param stage
 * @param difficulty
 * @param newtime
 */
void gamefileSetDifficultyStageTime(save_data *save, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty, s32 newtime)
{
    s32 offset;
    s32 index;
    u32 max_level;

    max_level = SP_LEVEL_MAX;
    if ((stage >= 0) && (stage < SP_LEVEL_MAX ) && (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_007))
    {
        if (newtime == 0) {
            newtime = 0x4f;
        } else if (newtime > 0x3ff) {
            newtime = 0x3ff;
        }

        offset = ((difficulty * max_level) + stage) * 10; //startbit
        index = (offset >> 3);

        switch(7 - (offset & 7)) //bitmask
        {
            case 7: //no offset 4 8 12 etc
                save->times[index] &= 0xff00;
                save->times[index + 1] &= 0xff3f;
                save->times[index] |= (newtime >> 2) & 0xff;
                save->times[index + 1] |= (newtime << 6) & 0xc0;
                break;
            case 5: //first offset 5 9 13 etc
                save->times[index] &= 0xffc0;
                save->times[index + 1] &= 0xff0f;
                save->times[index] |= ((newtime >> 4) & 0x3f);
                save->times[index + 1] |= (newtime << 4) & 0xf0;
                break;
            case 3: //second offset 6 10 14 etc
                save->times[index] &= 0xfff0;
                save->times[index + 1] &= 0xff03;
                save->times[index] |= ((newtime >> 6) & 0xf);
                save->times[index + 1] |= (newtime << 2) & 0xfC;
                break;
            case 1: //third offset 7 11 15 etc
                save->times[index] &= 0xfffc;
                save->times[index + 1] &= 0xff00;
                save->times[index] |= ((newtime >> 8) & 3);
                save->times[index + 1] |= newtime & 0xfff;
                break;
        }
    }
}


/**
 * Check if stage is completed at difficulty for save
 *
 * @param folder
 * @param levelid
 * @param difficulty
 * @return is stage at diffiuclty completed
 */
s32 get_eeprom_stage_completed_for_difficulty(save_data *folder, s32 levelid, DIFFICULTY difficulty) {

    if ((levelid >= 0) && (levelid < 0x14) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007)) {
        return gamefileGetStageDifficultyTime(folder, levelid, difficulty) != 0;
    }

    return 0;
}

/**
 *
 *
 * @param folder
 * @param levelid
 * @param difficulty
 * @param arg4
 */
void sub_GAME_7F01DCB0(save_data *folder, s32 levelid, DIFFICULTY difficulty, s32 arg4) {
    s32 temp_v0;

    if ((levelid >= 0) && (levelid < 0x14) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007)) {

        temp_v0 = gamefileGetStageDifficultyTime(folder, levelid, difficulty);

        if ((temp_v0 == 0) || (arg4 < temp_v0)) {
            gamefileSetDifficultyStageTime(folder, levelid, difficulty, arg4);
        }
    }
}

/**
 * Check if cheat is unlocked
 *
 * @param save
 * @param cheat
 * @return bool
 */
s32 check_if_cheat_unlocked(save_data *save, s32 cheat)
{
    s32 bits;

    if (cheat >= 0 && cheat < 0x14)
    {
        bits = save->unlocked_cheats_1 | save->unlocked_cheats_3 << 0x18 | save->unlocked_cheats_3 << 0x10 | save->unlocked_cheats_2 << 8;
        return ((1 << cheat) & bits) != 0;
    }

    return FALSE;
}

/**
 *
 *
 * @param save
 * @param cheat
 */
void sub_GAME_7F01DD74(save_data *save, s32 cheat)
{
    u32 i;
    u32 temp;

    if (cheat >= 0 && cheat < 0x14)
    {
        temp = 1 << (cheat);

        for(i = 0; temp > 0xff; i++)
        {
            temp = temp >> 8;
        }

        *(((u8 *)save + i + 0xe)) |= temp & 0xFFu;
    }
}

/**
 * Get save in foldernum slot
 *
 * @param foldernum
 * @return save_data*
 */
save_data *getEEPROMforFoldernum(u32 foldernum)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        if (check_if_eeprom_flag_set_0x80(&saves[i]) == 0 &&
                get_foldernum_of_eeprom(&saves[i]) == foldernum)
        {
            return &saves[i];
        }
    }

    if (foldernum == RAMROM_FOLDERNUM)
    {
        return &saves[5];
    }

    return NULL;
}

/**
 * See if any save has 0x80 flag
 *
 * @return s32
 */
s32 check_if_eeprom_flag_set_0x80_any_folder(void)
{
    s32 i;

    for(i = 0; i < 5; i++)
    {
        if (check_if_eeprom_flag_set_0x80(&saves[i]))
        {
            return i;
        }
    }

    return -1;
}

/**
 * Resets save with 0x80 flag
 * Maybe clearing for copy or wear level
 *
 * @param foldernum
 */
void sub_GAME_7F01DEB4(u32 foldernum)
{
    s32 folder_with_flag;
    save_data new_save;

    folder_with_flag = check_if_eeprom_flag_set_0x80_any_folder();

    if (folder_with_flag >= 0)
    {
        new_save = D_8002C5E0;
        saves[folder_with_flag] = new_save;

        set_eeprom_to_folder_num(&saves[folder_with_flag], foldernum);
        toggle_eeprom_flag_set_0x80(&saves[folder_with_flag], 0);
        set_selected_bond(&saves[folder_with_flag], foldernum);
        sub_GAME_7F01D7A0(&saves[folder_with_flag]);
    }
}



#ifdef NONMATCHING
void sub_GAME_7F01DF90(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01DF90
/* 052AC0 7F01DF90 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 052AC4 7F01DF94 AFBF003C */  sw    $ra, 0x3c($sp)
/* 052AC8 7F01DF98 AFBE0038 */  sw    $fp, 0x38($sp)
/* 052ACC 7F01DF9C AFB70034 */  sw    $s7, 0x34($sp)
/* 052AD0 7F01DFA0 AFB60030 */  sw    $s6, 0x30($sp)
/* 052AD4 7F01DFA4 AFB5002C */  sw    $s5, 0x2c($sp)
/* 052AD8 7F01DFA8 AFB40028 */  sw    $s4, 0x28($sp)
/* 052ADC 7F01DFAC AFB30024 */  sw    $s3, 0x24($sp)
/* 052AE0 7F01DFB0 AFB20020 */  sw    $s2, 0x20($sp)
/* 052AE4 7F01DFB4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 052AE8 7F01DFB8 0FC075B0 */  jal   sub_GAME_7F01D6C0
/* 052AEC 7F01DFBC AFB00018 */   sw    $s0, 0x18($sp)
/* 052AF0 7F01DFC0 104000A6 */  beqz  $v0, .L7F01E25C
/* 052AF4 7F01DFC4 27B10094 */   addiu $s1, $sp, 0x94
/* 052AF8 7F01DFC8 24100001 */  li    $s0, 1
/* 052AFC 7F01DFCC 00002025 */  move  $a0, $zero
/* 052B00 7F01DFD0 02202825 */  move  $a1, $s1
/* 052B04 7F01DFD4 0C0031EF */  jal   joyGamePakLongRead
/* 052B08 7F01DFD8 24060020 */   li    $a2, 32
/* 052B0C 7F01DFDC 93AE009C */  lbu   $t6, 0x9c($sp)
/* 052B10 7F01DFE0 24010042 */  li    $at, 66
/* 052B14 7F01DFE4 27B5008C */  addiu $s5, $sp, 0x8c
/* 052B18 7F01DFE8 11C10002 */  beq   $t6, $at, .L7F01DFF4
/* 052B1C 7F01DFEC 27A4009C */   addiu $a0, $sp, 0x9c
/* 052B20 7F01DFF0 00008025 */  move  $s0, $zero
.L7F01DFF4:
/* 052B24 7F01DFF4 27A500B4 */  addiu $a1, $sp, 0xb4
/* 052B28 7F01DFF8 0FC26D80 */  jal   sub_GAME_7F09B600
/* 052B2C 7F01DFFC 02A03025 */   move  $a2, $s5
/* 052B30 7F01E000 8FAF008C */  lw    $t7, 0x8c($sp)
/* 052B34 7F01E004 8FB80094 */  lw    $t8, 0x94($sp)
/* 052B38 7F01E008 8FB90090 */  lw    $t9, 0x90($sp)
/* 052B3C 7F01E00C 8FA80098 */  lw    $t0, 0x98($sp)
/* 052B40 7F01E010 15F80003 */  bne   $t7, $t8, .L7F01E020
/* 052B44 7F01E014 3C098003 */   lui   $t1, %hi(D_8002C640)
/* 052B48 7F01E018 13280002 */  beq   $t9, $t0, .L7F01E024
/* 052B4C 7F01E01C 00000000 */   nop
.L7F01E020:
/* 052B50 7F01E020 00008025 */  move  $s0, $zero
.L7F01E024:
/* 052B54 7F01E024 16000023 */  bnez  $s0, .L7F01E0B4
/* 052B58 7F01E028 2529C640 */   addiu $t1, %lo(D_8002C640) # addiu $t1, $t1, -0x39c0
/* 052B5C 7F01E02C 8D210000 */  lw    $at, ($t1)
/* 052B60 7F01E030 27A20064 */  addiu $v0, $sp, 0x64
/* 052B64 7F01E034 02202025 */  move  $a0, $s1
/* 052B68 7F01E038 AC410000 */  sw    $at, ($v0)
/* 052B6C 7F01E03C 8D2B0004 */  lw    $t3, 4($t1)
/* 052B70 7F01E040 AC4B0004 */  sw    $t3, 4($v0)
/* 052B74 7F01E044 8D210008 */  lw    $at, 8($t1)
/* 052B78 7F01E048 8C4D0004 */  lw    $t5, 4($v0)
/* 052B7C 7F01E04C AC410008 */  sw    $at, 8($v0)
/* 052B80 7F01E050 8D2B000C */  lw    $t3, 0xc($t1)
/* 052B84 7F01E054 AC4B000C */  sw    $t3, 0xc($v0)
/* 052B88 7F01E058 8D210010 */  lw    $at, 0x10($t1)
/* 052B8C 7F01E05C AC410010 */  sw    $at, 0x10($v0)
/* 052B90 7F01E060 8D2B0014 */  lw    $t3, 0x14($t1)
/* 052B94 7F01E064 AC4B0014 */  sw    $t3, 0x14($v0)
/* 052B98 7F01E068 8D210018 */  lw    $at, 0x18($t1)
/* 052B9C 7F01E06C AC410018 */  sw    $at, 0x18($v0)
/* 052BA0 7F01E070 8C410000 */  lw    $at, ($v0)
/* 052BA4 7F01E074 8D2B001C */  lw    $t3, 0x1c($t1)
/* 052BA8 7F01E078 AE2D0004 */  sw    $t5, 4($s1)
/* 052BAC 7F01E07C AE210000 */  sw    $at, ($s1)
/* 052BB0 7F01E080 8C410008 */  lw    $at, 8($v0)
/* 052BB4 7F01E084 8C4D000C */  lw    $t5, 0xc($v0)
/* 052BB8 7F01E088 AC4B001C */  sw    $t3, 0x1c($v0)
/* 052BBC 7F01E08C AE210008 */  sw    $at, 8($s1)
/* 052BC0 7F01E090 8C410010 */  lw    $at, 0x10($v0)
/* 052BC4 7F01E094 AE2D000C */  sw    $t5, 0xc($s1)
/* 052BC8 7F01E098 8C4D0014 */  lw    $t5, 0x14($v0)
/* 052BCC 7F01E09C AE210010 */  sw    $at, 0x10($s1)
/* 052BD0 7F01E0A0 8C410018 */  lw    $at, 0x18($v0)
/* 052BD4 7F01E0A4 AE2B001C */  sw    $t3, 0x1c($s1)
/* 052BD8 7F01E0A8 AE2D0014 */  sw    $t5, 0x14($s1)
/* 052BDC 7F01E0AC 0FC075D6 */  jal   sub_GAME_7F01D758
/* 052BE0 7F01E0B0 AE210018 */   sw    $at, 0x18($s1)
.L7F01E0B4:
/* 052BE4 7F01E0B4 3C058007 */  lui   $a1, %hi(saves)
/* 052BE8 7F01E0B8 24A59920 */  addiu $a1, %lo(saves) # addiu $a1, $a1, -0x66e0
/* 052BEC 7F01E0BC 24040004 */  li    $a0, 4
/* 052BF0 7F01E0C0 0C0031EF */  jal   joyGamePakLongRead
/* 052BF4 7F01E0C4 240601E0 */   li    $a2, 480
/* 052BF8 7F01E0C8 3C108007 */  lui   $s0, %hi(saves)
/* 052BFC 7F01E0CC 3C138007 */  lui   $s3, %hi(saves)
/* 052C00 7F01E0D0 3C128007 */  lui   $s2, %hi(saves)
/* 052C04 7F01E0D4 3C148007 */  lui   $s4, %hi(dword_CODE_bss_80069B60)
/* 052C08 7F01E0D8 26949B60 */  addiu $s4, %lo(dword_CODE_bss_80069B60) # addiu $s4, $s4, -0x64a0
/* 052C0C 7F01E0DC 26529980 */  addiu $s2, %lo(saves+0x60) # addiu $s2, $s2, -0x6680
/* 052C10 7F01E0E0 26739928 */  addiu $s3, %lo(saves+8) # addiu $s3, $s3, -0x66d8
/* 052C14 7F01E0E4 26109920 */  addiu $s0, %lo(saves) # addiu $s0, $s0, -0x66e0
.L7F01E0E8:
/* 052C18 7F01E0E8 24110001 */  li    $s1, 1
/* 052C1C 7F01E0EC 02602025 */  move  $a0, $s3
/* 052C20 7F01E0F0 02402825 */  move  $a1, $s2
/* 052C24 7F01E0F4 0FC26D80 */  jal   sub_GAME_7F09B600
/* 052C28 7F01E0F8 02A03025 */   move  $a2, $s5
/* 052C2C 7F01E0FC 8FAE008C */  lw    $t6, 0x8c($sp)
/* 052C30 7F01E100 8E0F0000 */  lw    $t7, ($s0)
/* 052C34 7F01E104 8FB80090 */  lw    $t8, 0x90($sp)
/* 052C38 7F01E108 55CF0005 */  bnel  $t6, $t7, .L7F01E120
/* 052C3C 7F01E10C 00008825 */   move  $s1, $zero
/* 052C40 7F01E110 8E190004 */  lw    $t9, 4($s0)
/* 052C44 7F01E114 13190002 */  beq   $t8, $t9, .L7F01E120
/* 052C48 7F01E118 00000000 */   nop
/* 052C4C 7F01E11C 00008825 */  move  $s1, $zero
.L7F01E120:
/* 052C50 7F01E120 56200004 */  bnezl $s1, .L7F01E134
/* 052C54 7F01E124 26520060 */   addiu $s2, $s2, 0x60
/* 052C58 7F01E128 0FC07610 */  jal   reset_folder_to_default
/* 052C5C 7F01E12C 02002025 */   move  $a0, $s0
/* 052C60 7F01E130 26520060 */  addiu $s2, $s2, 0x60
.L7F01E134:
/* 052C64 7F01E134 26100060 */  addiu $s0, $s0, 0x60
/* 052C68 7F01E138 1654FFEB */  bne   $s2, $s4, .L7F01E0E8
/* 052C6C 7F01E13C 26730060 */   addiu $s3, $s3, 0x60
/* 052C70 7F01E140 0000B025 */  move  $s6, $zero
/* 052C74 7F01E144 241E0060 */  li    $fp, 96
/* 052C78 7F01E148 24170005 */  li    $s7, 5
.L7F01E14C:
/* 052C7C 7F01E14C 3C108007 */  lui   $s0, %hi(saves)
/* 052C80 7F01E150 2414FFFF */  li    $s4, -1
/* 052C84 7F01E154 2415FFFF */  li    $s5, -1
/* 052C88 7F01E158 26109920 */  addiu $s0, %lo(saves) # addiu $s0, $s0, -0x66e0
/* 052C8C 7F01E15C 00008825 */  move  $s1, $zero
.L7F01E160:
/* 052C90 7F01E160 0FC07655 */  jal   check_if_eeprom_flag_set_0x80
/* 052C94 7F01E164 02002025 */   move  $a0, $s0
/* 052C98 7F01E168 54400023 */  bnezl $v0, .L7F01E1F8
/* 052C9C 7F01E16C 26310001 */   addiu $s1, $s1, 1
/* 052CA0 7F01E170 0FC07632 */  jal   get_foldernum_of_eeprom
/* 052CA4 7F01E174 02002025 */   move  $a0, $s0
/* 052CA8 7F01E178 5456001F */  bnel  $v0, $s6, .L7F01E1F8
/* 052CAC 7F01E17C 26310001 */   addiu $s1, $s1, 1
/* 052CB0 7F01E180 06810006 */  bgez  $s4, .L7F01E19C
/* 052CB4 7F01E184 02002025 */   move  $a0, $s0
/* 052CB8 7F01E188 0220A025 */  move  $s4, $s1
/* 052CBC 7F01E18C 0FC0763D */  jal   set_eeprom_flag_0x18
/* 052CC0 7F01E190 02002025 */   move  $a0, $s0
/* 052CC4 7F01E194 10000017 */  b     .L7F01E1F4
/* 052CC8 7F01E198 0040A825 */   move  $s5, $v0
.L7F01E19C:
/* 052CCC 7F01E19C 26B30001 */  addiu $s3, $s5, 1
/* 052CD0 7F01E1A0 06610004 */  bgez  $s3, .L7F01E1B4
/* 052CD4 7F01E1A4 32680003 */   andi  $t0, $s3, 3
/* 052CD8 7F01E1A8 11000002 */  beqz  $t0, .L7F01E1B4
/* 052CDC 7F01E1AC 00000000 */   nop
/* 052CE0 7F01E1B0 2508FFFC */  addiu $t0, $t0, -4
.L7F01E1B4:
/* 052CE4 7F01E1B4 0FC0763D */  jal   set_eeprom_flag_0x18
/* 052CE8 7F01E1B8 01009825 */   move  $s3, $t0
/* 052CEC 7F01E1BC 1453000B */  bne   $v0, $s3, .L7F01E1EC
/* 052CF0 7F01E1C0 00409025 */   move  $s2, $v0
/* 052CF4 7F01E1C4 029E0019 */  multu $s4, $fp
/* 052CF8 7F01E1C8 3C098007 */  lui   $t1, %hi(saves)
/* 052CFC 7F01E1CC 25299920 */  addiu $t1, %lo(saves) # addiu $t1, $t1, -0x66e0
/* 052D00 7F01E1D0 00005012 */  mflo  $t2
/* 052D04 7F01E1D4 01492021 */  addu  $a0, $t2, $t1
/* 052D08 7F01E1D8 0FC07610 */  jal   reset_folder_to_default
/* 052D0C 7F01E1DC 00000000 */   nop
/* 052D10 7F01E1E0 0220A025 */  move  $s4, $s1
/* 052D14 7F01E1E4 10000003 */  b     .L7F01E1F4
/* 052D18 7F01E1E8 0240A825 */   move  $s5, $s2
.L7F01E1EC:
/* 052D1C 7F01E1EC 0FC07610 */  jal   reset_folder_to_default
/* 052D20 7F01E1F0 02002025 */   move  $a0, $s0
.L7F01E1F4:
/* 052D24 7F01E1F4 26310001 */  addiu $s1, $s1, 1
.L7F01E1F8:
/* 052D28 7F01E1F8 1637FFD9 */  bne   $s1, $s7, .L7F01E160
/* 052D2C 7F01E1FC 26100060 */   addiu $s0, $s0, 0x60
/* 052D30 7F01E200 06830004 */  bgezl $s4, .L7F01E214
/* 052D34 7F01E204 26D60001 */   addiu $s6, $s6, 1
/* 052D38 7F01E208 0FC077AD */  jal   sub_GAME_7F01DEB4
/* 052D3C 7F01E20C 02C02025 */   move  $a0, $s6
/* 052D40 7F01E210 26D60001 */  addiu $s6, $s6, 1
.L7F01E214:
/* 052D44 7F01E214 2AC10004 */  slti  $at, $s6, 4
/* 052D48 7F01E218 1420FFCC */  bnez  $at, .L7F01E14C
/* 052D4C 7F01E21C 00000000 */   nop
/* 052D50 7F01E220 0000B025 */  move  $s6, $zero
/* 052D54 7F01E224 24110004 */  li    $s1, 4
.L7F01E228:
/* 052D58 7F01E228 0FC07771 */  jal   getEEPROMforFoldernum
/* 052D5C 7F01E22C 02C02025 */   move  $a0, $s6
/* 052D60 7F01E230 10400007 */  beqz  $v0, .L7F01E250
/* 052D64 7F01E234 00402025 */   move  $a0, $v0
/* 052D68 7F01E238 3C0C8003 */  lui   $t4, %hi(save_selected_bond)
/* 052D6C 7F01E23C 258CC510 */  addiu $t4, %lo(save_selected_bond) # addiu $t4, $t4, -0x3af0
/* 052D70 7F01E240 00165880 */  sll   $t3, $s6, 2
/* 052D74 7F01E244 0FC07649 */  jal   get_selected_bond
/* 052D78 7F01E248 016C8021 */   addu  $s0, $t3, $t4
/* 052D7C 7F01E24C AE020000 */  sw    $v0, ($s0)
.L7F01E250:
/* 052D80 7F01E250 26D60001 */  addiu $s6, $s6, 1
/* 052D84 7F01E254 16D1FFF4 */  bne   $s6, $s1, .L7F01E228
/* 052D88 7F01E258 00000000 */   nop
.L7F01E25C:
/* 052D8C 7F01E25C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 052D90 7F01E260 8FB00018 */  lw    $s0, 0x18($sp)
/* 052D94 7F01E264 8FB1001C */  lw    $s1, 0x1c($sp)
/* 052D98 7F01E268 8FB20020 */  lw    $s2, 0x20($sp)
/* 052D9C 7F01E26C 8FB30024 */  lw    $s3, 0x24($sp)
/* 052DA0 7F01E270 8FB40028 */  lw    $s4, 0x28($sp)
/* 052DA4 7F01E274 8FB5002C */  lw    $s5, 0x2c($sp)
/* 052DA8 7F01E278 8FB60030 */  lw    $s6, 0x30($sp)
/* 052DAC 7F01E27C 8FB70034 */  lw    $s7, 0x34($sp)
/* 052DB0 7F01E280 8FBE0038 */  lw    $fp, 0x38($sp)
/* 052DB4 7F01E284 03E00008 */  jr    $ra
/* 052DB8 7F01E288 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif

/**
 * Validate foldernum
 *
 * @param folder
 * @return bool
 */
s32 check_if_valid_folder_num(s32 folder)
{
    if ((folder >= 0) && (folder < 4))
    {
        return TRUE;
    }
    if (folder == 100)
    {
        return TRUE;
    }
    return FALSE;
}

// wrapper func - uses save if found
// gamefileIsStageUnlockedAtDifficulty calls gamefileIsSavedStageUnlockedAtDifficulty
/**
 * wrapper func - uses save if found
 * gamefileIsStageUnlockedAtDifficulty calls gamefileIsSavedStageUnlockedAtDifficulty
 *
 * @param foldernum
 * @param stage
 * @param difficulty
 * @return s32
 */
s32 isStageUnlockedAtDifficulty(s32 foldernum, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty)
{
    save_data* save;
    s32 i;

    if ((check_if_valid_folder_num(foldernum)) &&
        (stage >= SP_LEVEL_DAM && stage < SP_LEVEL_MAX) &&
        (difficulty >= DIFFICULTY_AGENT && difficulty < DIFFICULTY_MAX))
    {
        save = getEEPROMforFoldernum(foldernum);

        if (save)
        {
            if (get_eeprom_stage_completed_for_difficulty(save, stage, difficulty))
            {
                return 3; //found on first try, we are last completed stage
            }

            if ((stage == SP_LEVEL_AZTEC && difficulty < DIFFICULTY_SECRET) ||
                (stage == SP_LEVEL_EGYPT && difficulty < DIFFICULTY_00))
            {
                return 0; //we cant possibly have a completed bonus stage below each set dificulty
            }

            //still cant find it, do a search (this is probably how a cheat can unlock stages without having to actualy do them all)
            for (i = difficulty; i < DIFFICULTY_MAX ; i++)
            {
                LEVEL_SOLO_SEQUENCE istage;
                for (istage = SP_LEVEL_DAM; istage < stage; istage++)
                {
                    if (!get_eeprom_stage_completed_for_difficulty(save, istage, i))
                    {
                        break;
                    }
                }
                //if the first uncomplete stage is not less than current
                if (stage <= istage)
                {
                    return 1;
                }
            }

            // if we still cant find it
            if ((difficulty < DIFFICULTY_007) && (stage < SP_LEVEL_AZTEC))
            {
                for (i = difficulty; i < DIFFICULTY_MAX; i++)
                {
                    if (get_eeprom_stage_completed_for_difficulty(save, stage - 1, i))
                    {
                        return 1;
                    }
                }
            }

            if (difficulty < DIFFICULTY_007)
            {
                for (i = SP_LEVEL_DAM; i < SP_LEVEL_AZTEC; i++)
                {
                    if (!get_eeprom_stage_completed_for_difficulty(save, i, DIFFICULTY_AGENT))
                    {
                        break;
                    }
                }
                //this cant actually fire an it?
                if (i >= SP_LEVEL_AZTEC)
                {
                    for (i = DIFFICULTY_AGENT; i < difficulty; i++)
                    {
                        if (!get_eeprom_stage_completed_for_difficulty(save, stage, i))
                        {
                            break;
                        }
                    }

                    if (difficulty <= i)
                    {
                        return 1;
                    }
                }
            }// difficulty < DIFFICULTY_007
        }// save

        // no save, current level is dam, its unlocked.
        if (stage == SP_LEVEL_DAM)
        {
            return 1;
        }

        // no save, cheat anabled, its unlocked.
        if (get_debug_enable_agent_levels_flag() && difficulty == DIFFICULTY_AGENT)
        {
            return 1;
        }

        // no save, cheat anabled, its unlocked. (basically a repeat of above)
        if (get_debug_enable_all_levels_flag())
        {
            return 1;
        }
    }
    // After all that the stage is not unlocked
    return 0;
}

/**
 *
 *
 * @param save1
 * @param save2
 */
void sub_GAME_7F01E504(save_data *save1, save_data *save2)
{
    s32 folder_with_flag;
    s32 otherfolder;

    otherfolder = 0;
    folder_with_flag = check_if_eeprom_flag_set_0x80_any_folder();

    if (folder_with_flag >= 0)
    {
        saves[folder_with_flag] = *save2;

        if (save1 != 0)
        {
            otherfolder = (s32)(set_eeprom_flag_0x18(save1) + 1) % 4;
        }

        toggle_eeprom_flag_set_0x80(&saves[folder_with_flag], 0);
        reset_eeprom_flag_0x18(&saves[folder_with_flag], otherfolder);
        sub_GAME_7F01D7A0(&saves[folder_with_flag]);

        if (save1 != 0)
        {
            reset_folder_to_default(save1);
        }
    }
}



void unlock_stage_in_folder_on_difficulty(s32 foldernum, LEVEL_SOLO_SEQUENCE stage, DIFFICULTY difficulty, s32 maxtime)
{
    save_data new_save;
    save_data *save;
    s32 i;

    if ((foldernum >= 0) && (foldernum < 4) &&
        (stage >= SP_LEVEL_DAM) && (stage < SP_LEVEL_MAX) &&
        (difficulty >= DIFFICULTY_AGENT) && (difficulty < DIFFICULTY_MAX))
    {
        new_save = D_8002C660;

        save = getEEPROMforFoldernum(foldernum);

        if (save != 0) {
            new_save = *save;
        } else {
            set_eeprom_to_folder_num(&new_save, foldernum);
        }

        for (i = difficulty; i >= DIFFICULTY_AGENT; i--)
        {
            if (i == difficulty)
            {
                sub_GAME_7F01DCB0(&new_save, stage, i, maxtime);
            }
            else
            {
                sub_GAME_7F01DCB0(&new_save, stage, i, 99999999);
            }
        }

        sub_GAME_7F01E504(&save->chksum1, &new_save);
    }
}



#ifdef NONMATCHING
void sub_GAME_7F01E760(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01E760
/* 053290 7F01E760 27BDFF80 */  addiu $sp, $sp, -0x80
/* 053294 7F01E764 AFBF0014 */  sw    $ra, 0x14($sp)
/* 053298 7F01E768 0480003E */  bltz  $a0, .L7F01E864
/* 05329C 7F01E76C 00803825 */   move  $a3, $a0
/* 0532A0 7F01E770 28810004 */  slti  $at, $a0, 4
/* 0532A4 7F01E774 5020003C */  beql  $at, $zero, .L7F01E868
/* 0532A8 7F01E778 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0532AC 7F01E77C 04A00039 */  bltz  $a1, .L7F01E864
/* 0532B0 7F01E780 28A10014 */   slti  $at, $a1, 0x14
/* 0532B4 7F01E784 50200038 */  beql  $at, $zero, .L7F01E868
/* 0532B8 7F01E788 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0532BC 7F01E78C AFA50084 */  sw    $a1, 0x84($sp)
/* 0532C0 7F01E790 0FC07771 */  jal   getEEPROMforFoldernum
/* 0532C4 7F01E794 AFA70080 */   sw    $a3, 0x80($sp)
/* 0532C8 7F01E798 8FA70080 */  lw    $a3, 0x80($sp)
/* 0532CC 7F01E79C 10400009 */  beqz  $v0, .L7F01E7C4
/* 0532D0 7F01E7A0 00403025 */   move  $a2, $v0
/* 0532D4 7F01E7A4 00402025 */  move  $a0, $v0
/* 0532D8 7F01E7A8 8FA50084 */  lw    $a1, 0x84($sp)
/* 0532DC 7F01E7AC AFA2007C */  sw    $v0, 0x7c($sp)
/* 0532E0 7F01E7B0 0FC07748 */  jal   check_if_cheat_unlocked
/* 0532E4 7F01E7B4 AFA70080 */   sw    $a3, 0x80($sp)
/* 0532E8 7F01E7B8 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0532EC 7F01E7BC 14400029 */  bnez  $v0, .L7F01E864
/* 0532F0 7F01E7C0 8FA70080 */   lw    $a3, 0x80($sp)
.L7F01E7C4:
/* 0532F4 7F01E7C4 3C0E8003 */  lui   $t6, %hi(D_8002C6C0)
/* 0532F8 7F01E7C8 27A4001C */  addiu $a0, $sp, 0x1c
/* 0532FC 7F01E7CC 25CEC6C0 */  addiu $t6, %lo(D_8002C6C0) # addiu $t6, $t6, -0x3940
/* 053300 7F01E7D0 25D80060 */  addiu $t8, $t6, 0x60
/* 053304 7F01E7D4 0080C825 */  move  $t9, $a0
.L7F01E7D8:
/* 053308 7F01E7D8 8DC10000 */  lw    $at, ($t6)
/* 05330C 7F01E7DC 25CE000C */  addiu $t6, $t6, 0xc
/* 053310 7F01E7E0 2739000C */  addiu $t9, $t9, 0xc
/* 053314 7F01E7E4 AF21FFF4 */  sw    $at, -0xc($t9)
/* 053318 7F01E7E8 8DC1FFF8 */  lw    $at, -8($t6)
/* 05331C 7F01E7EC AF21FFF8 */  sw    $at, -8($t9)
/* 053320 7F01E7F0 8DC1FFFC */  lw    $at, -4($t6)
/* 053324 7F01E7F4 15D8FFF8 */  bne   $t6, $t8, .L7F01E7D8
/* 053328 7F01E7F8 AF21FFFC */   sw    $at, -4($t9)
/* 05332C 7F01E7FC 10C0000F */  beqz  $a2, .L7F01E83C
/* 053330 7F01E800 00E02825 */   move  $a1, $a3
/* 053334 7F01E804 00C05025 */  move  $t2, $a2
/* 053338 7F01E808 00805825 */  move  $t3, $a0
/* 05333C 7F01E80C 24C90060 */  addiu $t1, $a2, 0x60
.L7F01E810:
/* 053340 7F01E810 8D410000 */  lw    $at, ($t2)
/* 053344 7F01E814 254A000C */  addiu $t2, $t2, 0xc
/* 053348 7F01E818 256B000C */  addiu $t3, $t3, 0xc
/* 05334C 7F01E81C AD61FFF4 */  sw    $at, -0xc($t3)
/* 053350 7F01E820 8D41FFF8 */  lw    $at, -8($t2)
/* 053354 7F01E824 AD61FFF8 */  sw    $at, -8($t3)
/* 053358 7F01E828 8D41FFFC */  lw    $at, -4($t2)
/* 05335C 7F01E82C 1549FFF8 */  bne   $t2, $t1, .L7F01E810
/* 053360 7F01E830 AD61FFFC */   sw    $at, -4($t3)
/* 053364 7F01E834 10000006 */  b     .L7F01E850
/* 053368 7F01E838 8FA50084 */   lw    $a1, 0x84($sp)
.L7F01E83C:
/* 05336C 7F01E83C 0FC07636 */  jal   set_eeprom_to_folder_num
/* 053370 7F01E840 AFA6007C */   sw    $a2, 0x7c($sp)
/* 053374 7F01E844 8FA6007C */  lw    $a2, 0x7c($sp)
/* 053378 7F01E848 27A4001C */  addiu $a0, $sp, 0x1c
/* 05337C 7F01E84C 8FA50084 */  lw    $a1, 0x84($sp)
.L7F01E850:
/* 053380 7F01E850 0FC0775D */  jal   sub_GAME_7F01DD74
/* 053384 7F01E854 AFA6007C */   sw    $a2, 0x7c($sp)
/* 053388 7F01E858 8FA4007C */  lw    $a0, 0x7c($sp)
/* 05338C 7F01E85C 0FC07941 */  jal   sub_GAME_7F01E504
/* 053390 7F01E860 27A5001C */   addiu $a1, $sp, 0x1c
.L7F01E864:
/* 053394 7F01E864 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01E868:
/* 053398 7F01E868 27BD0080 */  addiu $sp, $sp, 0x80
/* 05339C 7F01E86C 03E00008 */  jr    $ra
/* 0533A0 7F01E870 00000000 */   nop
)
#endif


/**
 * Get the highest stage and difficulty completed in folder
 *
 * @param foldernum
 * @param stage
 * @param difficulty
 */
void get_highest_stage_difficulty_completed_in_folder(s32 foldernum, LEVEL_SOLO_SEQUENCE *stage, DIFFICULTY *difficulty)
{
    save_data *folder;
    LEVEL_SOLO_SEQUENCE stageid;
    DIFFICULTY difficultyid;

    folder = getEEPROMforFoldernum(foldernum);

    if (folder != NULL)
    {
        for (difficultyid = DIFFICULTY_007; difficultyid >= 0; difficultyid--)
        {
            for (stageid = SP_LEVEL_EGYPT; stageid >= 0; stageid--)
            {
                if (get_eeprom_stage_completed_for_difficulty(folder, stageid, difficultyid))
                {
                    *stage = stageid;
                    *difficulty = difficultyid;
                    return;
                }
            }
        }
    }
    *stage = SP_LEVEL_DAM - 1;
    *difficulty = DIFFICULTY_MULTI;
}

/**
 * Get the highest stage unlocked in folder
 *
 * @param foldernum
 * @return s32
 */
s32 get_highest_stage_unlocked_in_folder(s32 foldernum)
{
    LEVEL_SOLO_SEQUENCE stageid;
    DIFFICULTY difficulty;

    if (getEEPROMforFoldernum(foldernum) != NULL)
    {
        for (stageid = SP_LEVEL_EGYPT; stageid >= 0; stageid--)
        {
            for (difficulty = DIFFICULTY_AGENT; difficulty < DIFFICULTY_MAX; difficulty++)
            {
                if (isStageUnlockedAtDifficulty(foldernum, stageid, difficulty))
                {
                    return stageid;
                }
            }
        }
    }
    return 0;
}

/**
 * Get the highest stage unlocked in any folder
 *
 * @return stageid
 */
u32 get_highest_stage_unlocked_any_folder(void)
{
    u32 isfound;
    int folder;
    u32 isunlocked;

    isunlocked = 0;
    folder = 0;
    while (folder != 4) {
        isfound = get_highest_stage_unlocked_in_folder(folder);
        folder += 1;
        if ((int)isunlocked < (int)isfound)
        {
            isunlocked = isfound;
        }
    };
    return isunlocked;
}

/**
 * Check if cradle has been completed at any difficulty
 *
 * @param foldernum
 * @return bool
 */
s32 check_cradle_completed_in_folder(s32 foldernum)
{
    return (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_CRADLE, DIFFICULTY_AGENT) == 3) ||
            (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_CRADLE, DIFFICULTY_SECRET) == 3) ||
            (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_CRADLE, DIFFICULTY_00) == 3);
}

/**
 * Check if aztec has been completed at secret or 00 difficulty
 *
 * @param foldernum
 * @return bool
 */
s32 check_aztec_completed_in_folder_secret_00(s32 foldernum)
{
    return (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_AZTEC, DIFFICULTY_SECRET) == 3) ||
            (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_AZTEC, DIFFICULTY_00) == 3);
}

/**
 * Check if egypt is completed at 00 difficulty
 *
 * @param foldernum
 * @return bool
 */
s32 check_egypt_completed_in_folder_00(int foldernum)
{
    return isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_EGYPT, DIFFICULTY_00) == 3;
}

/**
 * Check if cradle has been completed in any folder
 *
 * @return bool
 */
u32 check_cradle_completed_any_folder(void)
{
    u32 completed;
    int folder;

    folder = 0;
    while (folder != 4)
    {
        completed = check_cradle_completed_in_folder(folder);
        folder += 1;
        if (completed != FALSE)
        {
            return TRUE;
        }
    };
    return FALSE;
}

/**
 * Check if aztec has been completed in any folder at secret or 00 difficulty
 *
 * @return bool
 */
u32 check_aztec_completed_any_folder_secret_00(void)
{
    u32 completed;
    int folder;

    folder = 0;
    while (folder != 4)
    {
        completed = check_aztec_completed_in_folder_secret_00(folder);
        folder += 1;
        if (completed != FALSE)
        {
            return TRUE;
        }
    };
    return FALSE;
}

/**
 * Check if Egypt has been completed in any folder at secret or 00 difficulty
 *
 * @return bool
 */
u32 check_egypt_completed_any_folder_00(void)
{
    u32 completed;
    int folder;

    folder = 0;
    while (folder != 4)
    {
        completed = check_egypt_completed_in_folder_00(folder);
        folder += 1;
        if (completed != FALSE)
        {
            return TRUE;
        }
    };
    return FALSE;
}

/**
 * Unused
 *
 * @param folder
 * @return u8
 */
u8 removed_would_have_returned_bond_for_folder_num(u32 folder)
{
    #ifdef ALL_BONDS
    //likely code based on behavior
    if ((folder >= 0) && (folder < 4))
    {
        return save_selected_bond[folder];
    }
    #endif

    #ifndef ALL_BONDS
    return 0;
    #endif
}

/**
 * Set the selected bond to folder object
 *
 * @param folder
 * @param bond
 */
void set_selected_bond_to_folder(s32 folder, s32 bond)
{
    if (folder < 0 || folder > 3)
    {
        return;
    }

    save_selected_bond[folder] = 0;
}

/**
 *
 *
 * @param unused
 */
void sub_GAME_7F01EBF4(u32 unused)
{
    return;
}

/**
 *
 *
 * @param unused
 */
void sub_GAME_7F01EBFC(u32 unused)
{
    return;
}

/**
 * Delete save at foldernum
 *
 * @param foldernum
 */
void delete_eeprom_folder(s32 foldernum)
{
    save_data *save;
    LEVEL_SOLO_SEQUENCE stage;
    DIFFICULTY difficulty;
    save_data new_save;

    if (foldernum >= 0 && foldernum < 4)
    {
        save = getEEPROMforFoldernum(foldernum);
        if (save != 0)
        {
            get_highest_stage_difficulty_completed_in_folder(foldernum, &stage, &difficulty);
            if ((stage >= 0) && (difficulty >= 0))
            {
                new_save = D_8002C720;
                *save = new_save;
                set_eeprom_to_folder_num(save, foldernum);
                toggle_eeprom_flag_set_0x80(save, 0);
                set_selected_bond(save, foldernum);
                set_selected_bond_to_folder(foldernum, foldernum);
                sub_GAME_7F01D7A0(save);
            }
        }
    }
}

/**
 *
 *
 * Resetting times??
 * @param foldernum
 */
void sub_GAME_7F01ED10(u32 foldernum)
{
    save_data *save;
    LEVEL_SOLO_SEQUENCE stagenum;
    DIFFICULTY difficulty;

    save = getEEPROMforFoldernum(foldernum);

    for (stagenum = SP_LEVEL_DAM; stagenum < SP_LEVEL_MAX; stagenum++)
    {
        for(difficulty = DIFFICULTY_AGENT; difficulty < DIFFICULTY_007; difficulty++)
        {
            sub_GAME_7F01DCB0(save, stagenum, difficulty, 99999999);
        }
    }
}

/**
 * Copy save
 *
 * Copies selected save to the first free slot
 * if no free slot, do nothing
 * @param foldernum Current folder number
 */
void sub_GAME_7F01EDA0(s32 foldernum)
{
    save_data* save;
    LEVEL_SOLO_SEQUENCE stage;
    DIFFICULTY difficulty;
    s32 other;
    save_data new_save;
    save_data* temp_s2;

    if ((foldernum >= 0) && (foldernum < 4))
    {
        save = getEEPROMforFoldernum(foldernum);
        if (save != 0)
        {
            get_highest_stage_difficulty_completed_in_folder(foldernum, &stage, &difficulty);
            if (stage >= 0)
            {
                if (difficulty >= 0) {
                    for(other = 0;other != 4; other++)
                    {
                            if ((getEEPROMforFoldernum(other) == 0) ||
                                (get_highest_stage_difficulty_completed_in_folder(other, &stage, &difficulty),
                                (stage < 0) && (difficulty < 0)))
                            {
                                break;
                            }
                    }

                    if ((s32)other < 4)
                    {
                        new_save = D_8002C780;
                        temp_s2 = getEEPROMforFoldernum(other);
                        new_save = *save;
                        set_eeprom_to_folder_num(&new_save, other);
                        set_selected_bond_to_folder(other, removed_would_have_returned_bond_for_folder_num(foldernum));
                        sub_GAME_7F01E504(temp_s2, &new_save);
                    }
                }
            }
        }
    }
}

/**
 * @brief
 *
 * @param save
 */
void update_eeprom_to_current_solo_watch_settings(save_data *save)
{
    u32 temp;
    u16 bits;

    bits = 0;
    save->music_vol = get_mTrack2Vol() >> 7;
    save->sfx_vol = (call_sndGetSfxSlotFirstNaturalVolume() >> 7);

    if (get_cur_player_look_vertical_inverted() != 0)
    {
        bits = 1;
    }

    if (cur_player_get_autoaim() != 0)
    {
        bits |= 2;
    }

    if (cur_player_get_aim_control() != 0)
    {
        bits |= 4;
    }

    if (cur_player_get_sight_onscreen_control() != 0)
    {
        bits |= 8;
    }

    if (cur_player_get_lookahead() != 0)
    {
        bits |= 0x10;
    }

    if (cur_player_get_ammo_onscreen_setting() != 0)
    {
        bits |= 0x20;
    }

    if (cur_player_get_screen_setting() == 1)
    {
        bits |= 0x40;
    }
    else if (cur_player_get_screen_setting() == 2)
    {
        bits |= 0x800;
    }

    if (get_screen_ratio() != SCREEN_RATIO_NORMAL)
    {
        bits |= 0x80;
    }

    temp = ((u16) (cur_player_get_control_type() << 8)) & 0x700;
    save->options = bits | temp;
}

/**
 * Get the screen ratio settings for mpgame from folder
 *
 * @param foldernum
 */
void get_screen_ratio_settings_for_mpgame_from_folder(u32 foldernum)
{
    save_data *save;
    u16 padding;
    u16 options;

    save = getEEPROMforFoldernum(foldernum);
    if (save)
    {
        set_mTrack2Vol((save->music_vol << 7) | (save->music_vol >> 1));
        sub_GAME_7F0A91A0((save->sfx_vol << 7) | (save->sfx_vol >> 1));

        options = save->options;

        if (getPlayerCount() == 1)
        {
            cur_player_set_control_type(((s32) (options & 0x700) >> 8) & 0xFFFF);
        }
        else
        {
            cur_player_set_control_type(0);
        }

        set_cur_player_look_vertical_inverted((options & 1) != 0);
        cur_player_set_autoaim((options & 2) != 0);
        cur_player_set_aim_control((options & 4) != 0);
        cur_player_set_sight_onscreen_control((options & 8) != 0);
        cur_player_set_lookahead((options & 0x10) != 0);
        cur_player_set_ammo_onscreen_setting((options & 0x20) != 0);

        if (options & 0x800)
        {
            cur_player_set_screen_setting(2);
        }
        else if (options & 0x40)
        {
            cur_player_set_screen_setting(1);
        }
        else
        {
            cur_player_set_screen_setting(0);
        }

        set_screen_ratio((options & 0x80) != 0);
    }
}

/**
 * Delete
 *
 * @param foldernum
 */
void delete_update_eeprom_file(s32 foldernum)
{
    save_data *save;
    save_data save_to_copy;
    save_data new_save;

    if (foldernum >= 0 && foldernum < 4)
    {
        save = getEEPROMforFoldernum(foldernum);

        save_to_copy = D_8002C7E0;

        if (save != 0)
        {
            save_to_copy = *save;
        }
        else
        {
            set_eeprom_to_folder_num(&save_to_copy, foldernum);
        }

        new_save = save_to_copy;

        update_eeprom_to_current_solo_watch_settings(&new_save);

        if (_bcmp(&new_save, &save_to_copy, 0x60) != 0)
        {
            sub_GAME_7F01E504(save, &new_save);
        }
    }
}

/**
 *
 *
 * @param foldernum
 */
void copy_eeprom_to_stack_set_folder_num(s32 foldernum)
{
    save_data *save;
    save_data new_save;

    if (foldernum >= 0 && foldernum < 4)
    {
        save = getEEPROMforFoldernum(foldernum);
        new_save = D_8002C840;

        if (save != 0)
        {
            new_save = *save;
        }
        else
        {
            set_eeprom_to_folder_num(&new_save, foldernum);
        }

        if (save_selected_bond[foldernum] != get_selected_bond(&new_save))
        {
            set_selected_bond(&new_save, save_selected_bond[foldernum]);
            sub_GAME_7F01E504(save, &new_save);
        }
    }
}

/**
 * Copy save for foldernum to out_save
 *
 * @param foldernum
 * @param out_save
 */
void copy_eeprom_from_to(s32 foldernum, save_data *out_save)
{
    save_data *in_save;
    save_data new_save;

    in_save = getEEPROMforFoldernum(foldernum);

    if (in_save != 0)
    {
        *out_save = *in_save;
    }
    else
    {
        new_save = blank_eeprom;
        *out_save = new_save;
    }
}

/**
 * Copy save to RarRom replay save
 *
 * @param foldernum
 * @param save
 */
void copy_demo_eeprom_to_ramrom_folder(u32 foldernum, save_data *save)
{
    if (foldernum == RAMROM_FOLDERNUM)
    {
        saves[5] = *save;
    }
}

/**
 * Check is 007 mode is unlocked
 *
 * @param foldernum
 * @return bool
 */
s32 check_for_007_mode_unlocked(u32 foldernum)
{
    LEVEL_SOLO_SEQUENCE stage;
    save_data* folder;

    folder = getEEPROMforFoldernum(foldernum);

    if (folder != NULL)
    {
        if ((folder->flag_007 & 1))
        {
            return TRUE;
        }

        for (stage = SP_LEVEL_DAM; stage < SP_LEVEL_MAX; stage++)
        {
            if (!get_eeprom_stage_completed_for_difficulty(folder, stage, DIFFICULTY_00))
            {
                break;
            }
        }

        if (stage == SP_LEVEL_MAX)
        {
            return TRUE;
        }
    }

    return FALSE;
}
