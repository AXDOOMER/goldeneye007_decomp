#include "ultra64.h"
#include "game/gamefile.h"
#include "gamefile2.h"
#include "bondconstants.h"
#include "joy.h"
#include "player.h"
#include "watch.h"

s32 sub_GAME_7F01D6C0(void) {
  return joyGamePakProbe();
}




void reset_ramrom_folder_to_default(void)
{
    struct save_data new_save;

    new_save = D_8002C520;
    saves[5] = new_save;
}



void sub_GAME_7F01D758(struct save_data *save)
{
    if (sub_GAME_7F01D6C0() != 0)
    {
        sub_GAME_7F09B600(&save->completion_bitflags, &save->times[14], save);
        joyGamePakLongWrite(0, save, 0x20);
    }
}

void sub_GAME_7F01D7A0(struct save_data *save)
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



void reset_folder_to_default(struct save_data *save)
{
    struct save_data new_save;

    new_save = D_8002C580;
    *save = new_save;
    sub_GAME_7F01D7A0(save);
}


u32 get_foldernum_of_eeprom(struct save_data *eeprom)
{
  return eeprom->completion_bitflags & 7;
}

void set_eeprom_to_folder_num(struct save_data *eeprom, u32 folder) {
    eeprom->completion_bitflags = eeprom->completion_bitflags & 0xFFF8;

    eeprom->completion_bitflags = eeprom->completion_bitflags | folder & 7;
}


u32 set_eeprom_flag_0x18(struct save_data *folder)
{
  return (folder->completion_bitflags & 0x18) >> 3;
}

void reset_eeprom_flag_0x18(struct save_data *folder, s32 arg1) {
    folder->completion_bitflags = folder->completion_bitflags & 0xFFE7;

    folder->completion_bitflags = (folder->completion_bitflags | ((arg1 * 8) & 0x18));
}


u32 get_selected_bond(struct save_data *folder)
{
  return (folder->completion_bitflags & 0x60) >> 5;
}




void set_selected_bond(struct save_data *folder, s32 arg1) {
    folder->completion_bitflags = folder->completion_bitflags & 0xFF9F;

    folder->completion_bitflags = (folder->completion_bitflags | ((arg1 << 5) & 0x60));
}





u32 check_if_eeprom_flag_set_0x80(struct save_data *folder)
{
  return ((folder->completion_bitflags & 0x80) != 0);
}


void toggle_eeprom_flag_set_0x80(struct save_data *folder,u32 mode)
{
  if (mode != 0) {
    folder->completion_bitflags = folder->completion_bitflags | 0x80;
    return;
  }
  folder->completion_bitflags = folder->completion_bitflags & 0xff7f;
  return;
}




s32 get_eeprom_stage_complete_time_for_difficulty(struct save_data* save, LEVEL_SOLO_SEQUENCE stagenum, DIFFICULTY difficulty)
{
    s32 offset;
    LEVEL_SOLO_SEQUENCE max_level;
    u32 return_value;

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

        switch(7 - (offset & 7)) //bitmask
        {
            case 7: //no offset
                // first 10 bits 8 + 2                    1111 1111                                      1100 0000
                return_value = ((save->times[(offset >> 3)] & 0xFF) << 2) | ((save->times[(offset >> 3) + 1] & 0xc0) >> 6);
                break;
            case 5: //offset 2
                // next 10 bits 6 + 4                     0011 1111                                      1111 0000
                return_value =  ((save->times[(offset >> 3)] & 0x3f) << 4) | ((save->times[(offset >> 3) + 1] & 0xf0) >> 4);
                break;
            case 3: //offset 4
                // next 10 bits 4 + 6                     0000 1111                                      1111 1100
                return_value =  ((save->times[(offset >> 3)] & 0xf) << 6) | ((save->times[(offset >> 3) + 1] & 0xfc) >> 2);
                break;
            case 1: //offset 6
                // next 10 bits 2 + 8                     0000 0011                                      1111 1111
                return_value = ((save->times[(offset >> 3)] & 0x3)  << 8) | ((save->times[(offset >> 3) + 1] & 0xFFF));
                break;
            default:
                return_value = 0; // shouldnt reach
        }

        return return_value;
    }

    return 0;
}



#ifdef NONMATCHING
void sub_GAME_7F01DAE4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01DAE4
/* 052614 7F01DAE4 04A0005C */  bltz  $a1, .L7F01DC58
/* 052618 7F01DAE8 28A10014 */   slti  $at, $a1, 0x14
/* 05261C 7F01DAEC 1020005A */  beqz  $at, .L7F01DC58
/* 052620 7F01DAF0 00000000 */   nop
/* 052624 7F01DAF4 04C00058 */  bltz  $a2, .L7F01DC58
/* 052628 7F01DAF8 28C10003 */   slti  $at, $a2, 3
/* 05262C 7F01DAFC 10200056 */  beqz  $at, .L7F01DC58
/* 052630 7F01DB00 24080007 */   li    $t0, 7
/* 052634 7F01DB04 14E00003 */  bnez  $a3, .L7F01DB14
/* 052638 7F01DB08 00067080 */   sll   $t6, $a2, 2
/* 05263C 7F01DB0C 10000005 */  b     .L7F01DB24
/* 052640 7F01DB10 2407004F */   li    $a3, 79
.L7F01DB14:
/* 052644 7F01DB14 28E10400 */  slti  $at, $a3, 0x400
/* 052648 7F01DB18 54200003 */  bnezl $at, .L7F01DB28
/* 05264C 7F01DB1C 01C67021 */   addu  $t6, $t6, $a2
/* 052650 7F01DB20 240703FF */  li    $a3, 1023
.L7F01DB24:
/* 052654 7F01DB24 01C67021 */  addu  $t6, $t6, $a2
.L7F01DB28:
/* 052658 7F01DB28 000E7080 */  sll   $t6, $t6, 2
/* 05265C 7F01DB2C 01C51021 */  addu  $v0, $t6, $a1
/* 052660 7F01DB30 00027880 */  sll   $t7, $v0, 2
/* 052664 7F01DB34 01E27821 */  addu  $t7, $t7, $v0
/* 052668 7F01DB38 000F7840 */  sll   $t7, $t7, 1
/* 05266C 7F01DB3C 31F80007 */  andi  $t8, $t7, 7
/* 052670 7F01DB40 01181823 */  subu  $v1, $t0, $t8
/* 052674 7F01DB44 24010001 */  li    $at, 1
/* 052678 7F01DB48 10610035 */  beq   $v1, $at, .L7F01DC20
/* 05267C 7F01DB4C 01E01025 */   move  $v0, $t7
/* 052680 7F01DB50 24010003 */  li    $at, 3
/* 052684 7F01DB54 10610023 */  beq   $v1, $at, .L7F01DBE4
/* 052688 7F01DB58 0002C0C3 */   sra   $t8, $v0, 3
/* 05268C 7F01DB5C 24010005 */  li    $at, 5
/* 052690 7F01DB60 10610011 */  beq   $v1, $at, .L7F01DBA8
/* 052694 7F01DB64 000260C3 */   sra   $t4, $v0, 3
/* 052698 7F01DB68 1468003B */  bne   $v1, $t0, .L7F01DC58
/* 05269C 7F01DB6C 000FC8C3 */   sra   $t9, $t7, 3
/* 0526A0 7F01DB70 00991821 */  addu  $v1, $a0, $t9
/* 0526A4 7F01DB74 90690012 */  lbu   $t1, 0x12($v1)
/* 0526A8 7F01DB78 906B0013 */  lbu   $t3, 0x13($v1)
/* 0526AC 7F01DB7C 00077883 */  sra   $t7, $a3, 2
/* 0526B0 7F01DB80 312DFF00 */  andi  $t5, $t1, 0xff00
/* 0526B4 7F01DB84 3179FF3F */  andi  $t9, $t3, 0xff3f
/* 0526B8 7F01DB88 00075180 */  sll   $t2, $a3, 6
/* 0526BC 7F01DB8C A06D0012 */  sb    $t5, 0x12($v1)
/* 0526C0 7F01DB90 A0790013 */  sb    $t9, 0x13($v1)
/* 0526C4 7F01DB94 01AFC025 */  or    $t8, $t5, $t7
/* 0526C8 7F01DB98 032A5825 */  or    $t3, $t9, $t2
/* 0526CC 7F01DB9C A0780012 */  sb    $t8, 0x12($v1)
/* 0526D0 7F01DBA0 03E00008 */  jr    $ra
/* 0526D4 7F01DBA4 A06B0013 */   sb    $t3, 0x13($v1)

.L7F01DBA8:
/* 0526D8 7F01DBA8 008C1821 */  addu  $v1, $a0, $t4
/* 0526DC 7F01DBAC 906E0012 */  lbu   $t6, 0x12($v1)
/* 0526E0 7F01DBB0 906F0013 */  lbu   $t7, 0x13($v1)
/* 0526E4 7F01DBB4 0007C903 */  sra   $t9, $a3, 4
/* 0526E8 7F01DBB8 31C9FFC0 */  andi  $t1, $t6, 0xffc0
/* 0526EC 7F01DBBC 31ECFF0F */  andi  $t4, $t7, 0xff0f
/* 0526F0 7F01DBC0 332A003F */  andi  $t2, $t9, 0x3f
/* 0526F4 7F01DBC4 00076900 */  sll   $t5, $a3, 4
/* 0526F8 7F01DBC8 A0690012 */  sb    $t1, 0x12($v1)
/* 0526FC 7F01DBCC A06C0013 */  sb    $t4, 0x13($v1)
/* 052700 7F01DBD0 012A5825 */  or    $t3, $t1, $t2
/* 052704 7F01DBD4 018D7825 */  or    $t7, $t4, $t5
/* 052708 7F01DBD8 A06B0012 */  sb    $t3, 0x12($v1)
/* 05270C 7F01DBDC 03E00008 */  jr    $ra
/* 052710 7F01DBE0 A06F0013 */   sb    $t7, 0x13($v1)

.L7F01DBE4:
/* 052714 7F01DBE4 00981821 */  addu  $v1, $a0, $t8
/* 052718 7F01DBE8 90790012 */  lbu   $t9, 0x12($v1)
/* 05271C 7F01DBEC 906A0013 */  lbu   $t2, 0x13($v1)
/* 052720 7F01DBF0 00076183 */  sra   $t4, $a3, 6
/* 052724 7F01DBF4 332EFFF0 */  andi  $t6, $t9, 0xfff0
/* 052728 7F01DBF8 3158FF03 */  andi  $t8, $t2, 0xff03
/* 05272C 7F01DBFC 318D000F */  andi  $t5, $t4, 0xf
/* 052730 7F01DC00 00074880 */  sll   $t1, $a3, 2
/* 052734 7F01DC04 A06E0012 */  sb    $t6, 0x12($v1)
/* 052738 7F01DC08 A0780013 */  sb    $t8, 0x13($v1)
/* 05273C 7F01DC0C 01CD7825 */  or    $t7, $t6, $t5
/* 052740 7F01DC10 03095025 */  or    $t2, $t8, $t1
/* 052744 7F01DC14 A06F0012 */  sb    $t7, 0x12($v1)
/* 052748 7F01DC18 03E00008 */  jr    $ra
/* 05274C 7F01DC1C A06A0013 */   sb    $t2, 0x13($v1)

.L7F01DC20:
/* 052750 7F01DC20 000258C3 */  sra   $t3, $v0, 3
/* 052754 7F01DC24 008B1821 */  addu  $v1, $a0, $t3
/* 052758 7F01DC28 906C0012 */  lbu   $t4, 0x12($v1)
/* 05275C 7F01DC2C 906D0013 */  lbu   $t5, 0x13($v1)
/* 052760 7F01DC30 0007C203 */  sra   $t8, $a3, 8
/* 052764 7F01DC34 3199FFFC */  andi  $t9, $t4, 0xfffc
/* 052768 7F01DC38 31ABFF00 */  andi  $t3, $t5, 0xff00
/* 05276C 7F01DC3C 33090003 */  andi  $t1, $t8, 3
/* 052770 7F01DC40 A0790012 */  sb    $t9, 0x12($v1)
/* 052774 7F01DC44 A06B0013 */  sb    $t3, 0x13($v1)
/* 052778 7F01DC48 03295025 */  or    $t2, $t9, $t1
/* 05277C 7F01DC4C 01677025 */  or    $t6, $t3, $a3
/* 052780 7F01DC50 A06A0012 */  sb    $t2, 0x12($v1)
/* 052784 7F01DC54 A06E0013 */  sb    $t6, 0x13($v1)
.L7F01DC58:
/* 052788 7F01DC58 03E00008 */  jr    $ra
/* 05278C 7F01DC5C 00000000 */   nop
)
#endif



s32 get_eeprom_stage_completed_for_difficulty(struct save_data *folder, s32 levelid, DIFFICULTY difficulty) {

    if ((levelid >= 0) && (levelid < 0x14) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007)) {
        return get_eeprom_stage_complete_time_for_difficulty(folder, levelid, difficulty) != 0;
    }

    return 0;
}



void sub_GAME_7F01DCB0(struct save_data *folder, s32 levelid, DIFFICULTY difficulty, s32 arg4) {
    s32 temp_v0;

    if ((levelid >= 0) && (levelid < 0x14) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007)) {

        temp_v0 = get_eeprom_stage_complete_time_for_difficulty(folder, levelid, difficulty);

        if ((temp_v0 == 0) || (arg4 < temp_v0)) {
            sub_GAME_7F01DAE4(folder, levelid, difficulty, arg4);
        }
    }
}

s32 check_if_cheat_unlocked(struct save_data *save, s32 cheat)
{
    s32 bits;

    if (cheat >= 0 && cheat < 0x14)
    {
        bits = save->unlocked_cheats_1 | save->unlocked_cheats_3 << 0x18 | save->unlocked_cheats_3 << 0x10 | save->unlocked_cheats_2 << 8;
        return ((1 << cheat) & bits) != 0;
    }

    return FALSE;
}

void sub_GAME_7F01DD74(struct save_data *save, s32 cheat)
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

struct save_data *getEEPROMforFoldernum(u32 foldernum)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (check_if_eeprom_flag_set_0x80(&saves[i]) == 0 &&
                get_foldernum_of_eeprom(&saves[i]) == foldernum) {
            return &saves[i];
        }
    }

    if (foldernum == RAMROM_FOLDERNUM) {
        return &saves[5];
    }

    return NULL;
}

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



#ifdef NONMATCHING
void sub_GAME_7F01DEB4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01DEB4
/* 0529E4 7F01DEB4 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0529E8 7F01DEB8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0529EC 7F01DEBC AFB00018 */  sw    $s0, 0x18($sp)
/* 0529F0 7F01DEC0 0FC07794 */  jal   check_if_eeprom_flag_set_0x80_any_folder
/* 0529F4 7F01DEC4 AFA40088 */   sw    $a0, 0x88($sp)
/* 0529F8 7F01DEC8 0440002C */  bltz  $v0, .L7F01DF7C
/* 0529FC 7F01DECC 00401825 */   move  $v1, $v0
/* 052A00 7F01DED0 3C0E8003 */  lui   $t6, %hi(D_8002C5E0)
/* 052A04 7F01DED4 27A20024 */  addiu $v0, $sp, 0x24
/* 052A08 7F01DED8 25CEC5E0 */  addiu $t6, %lo(D_8002C5E0) # addiu $t6, $t6, -0x3a20
/* 052A0C 7F01DEDC 25D80060 */  addiu $t8, $t6, 0x60
/* 052A10 7F01DEE0 0040C825 */  move  $t9, $v0
.L7F01DEE4:
/* 052A14 7F01DEE4 8DC10000 */  lw    $at, ($t6)
/* 052A18 7F01DEE8 25CE000C */  addiu $t6, $t6, 0xc
/* 052A1C 7F01DEEC 2739000C */  addiu $t9, $t9, 0xc
/* 052A20 7F01DEF0 AF21FFF4 */  sw    $at, -0xc($t9)
/* 052A24 7F01DEF4 8DC1FFF8 */  lw    $at, -8($t6)
/* 052A28 7F01DEF8 AF21FFF8 */  sw    $at, -8($t9)
/* 052A2C 7F01DEFC 8DC1FFFC */  lw    $at, -4($t6)
/* 052A30 7F01DF00 15D8FFF8 */  bne   $t6, $t8, .L7F01DEE4
/* 052A34 7F01DF04 AF21FFFC */   sw    $at, -4($t9)
/* 052A38 7F01DF08 00034080 */  sll   $t0, $v1, 2
/* 052A3C 7F01DF0C 01034023 */  subu  $t0, $t0, $v1
/* 052A40 7F01DF10 3C098007 */  lui   $t1, %hi(saves)
/* 052A44 7F01DF14 25299920 */  addiu $t1, %lo(saves) # addiu $t1, $t1, -0x66e0
/* 052A48 7F01DF18 00084140 */  sll   $t0, $t0, 5
/* 052A4C 7F01DF1C 01098021 */  addu  $s0, $t0, $t1
/* 052A50 7F01DF20 02006825 */  move  $t5, $s0
/* 052A54 7F01DF24 00406025 */  move  $t4, $v0
/* 052A58 7F01DF28 244B0060 */  addiu $t3, $v0, 0x60
.L7F01DF2C:
/* 052A5C 7F01DF2C 8D810000 */  lw    $at, ($t4)
/* 052A60 7F01DF30 258C000C */  addiu $t4, $t4, 0xc
/* 052A64 7F01DF34 25AD000C */  addiu $t5, $t5, 0xc
/* 052A68 7F01DF38 ADA1FFF4 */  sw    $at, -0xc($t5)
/* 052A6C 7F01DF3C 8D81FFF8 */  lw    $at, -8($t4)
/* 052A70 7F01DF40 ADA1FFF8 */  sw    $at, -8($t5)
/* 052A74 7F01DF44 8D81FFFC */  lw    $at, -4($t4)
/* 052A78 7F01DF48 158BFFF8 */  bne   $t4, $t3, .L7F01DF2C
/* 052A7C 7F01DF4C ADA1FFFC */   sw    $at, -4($t5)
/* 052A80 7F01DF50 02002025 */  move  $a0, $s0
/* 052A84 7F01DF54 0FC07636 */  jal   set_eeprom_to_folder_num
/* 052A88 7F01DF58 8FA50088 */   lw    $a1, 0x88($sp)
/* 052A8C 7F01DF5C 02002025 */  move  $a0, $s0
/* 052A90 7F01DF60 0FC07659 */  jal   toggle_eeprom_flag_set_0x80
/* 052A94 7F01DF64 00002825 */   move  $a1, $zero
/* 052A98 7F01DF68 02002025 */  move  $a0, $s0
/* 052A9C 7F01DF6C 0FC0764D */  jal   set_selected_bond
/* 052AA0 7F01DF70 8FA50088 */   lw    $a1, 0x88($sp)
/* 052AA4 7F01DF74 0FC075E8 */  jal   sub_GAME_7F01D7A0
/* 052AA8 7F01DF78 02002025 */   move  $a0, $s0
.L7F01DF7C:
/* 052AAC 7F01DF7C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 052AB0 7F01DF80 8FB00018 */  lw    $s0, 0x18($sp)
/* 052AB4 7F01DF84 27BD0088 */  addiu $sp, $sp, 0x88
/* 052AB8 7F01DF88 03E00008 */  jr    $ra
/* 052ABC 7F01DF8C 00000000 */   nop
)
#endif



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



s32 check_if_valid_folder_num(s32 folder)
{
    if ((folder >= 0) && (folder < 4))
    {
        return 1;
    }
    if (folder == 100)
    {
        return 1;
    }
    return 0;
}



#ifdef NONMATCHING
s32 isStageUnlockedAtDifficulty(int foldernum,STAGENUM stageid,DIFFICULTY difficulty) {

}
#else
GLOBAL_ASM(
.text
glabel isStageUnlockedAtDifficulty
/* 052DF0 7F01E2C0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 052DF4 7F01E2C4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 052DF8 7F01E2C8 AFB50028 */  sw    $s5, 0x28($sp)
/* 052DFC 7F01E2CC AFB30020 */  sw    $s3, 0x20($sp)
/* 052E00 7F01E2D0 AFB00014 */  sw    $s0, 0x14($sp)
/* 052E04 7F01E2D4 00808025 */  move  $s0, $a0
/* 052E08 7F01E2D8 00A09825 */  move  $s3, $a1
/* 052E0C 7F01E2DC 00C0A825 */  move  $s5, $a2
/* 052E10 7F01E2E0 AFB40024 */  sw    $s4, 0x24($sp)
/* 052E14 7F01E2E4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 052E18 7F01E2E8 0FC078A3 */  jal   check_if_valid_folder_num
/* 052E1C 7F01E2EC AFB10018 */   sw    $s1, 0x18($sp)
/* 052E20 7F01E2F0 5040007B */  beql  $v0, $zero, .L7F01E4E0
/* 052E24 7F01E2F4 00001025 */   move  $v0, $zero
/* 052E28 7F01E2F8 06600078 */  bltz  $s3, .L7F01E4DC
/* 052E2C 7F01E2FC 2A610014 */   slti  $at, $s3, 0x14
/* 052E30 7F01E300 50200077 */  beql  $at, $zero, .L7F01E4E0
/* 052E34 7F01E304 00001025 */   move  $v0, $zero
/* 052E38 7F01E308 06A00074 */  bltz  $s5, .L7F01E4DC
/* 052E3C 7F01E30C 2AA10004 */   slti  $at, $s5, 4
/* 052E40 7F01E310 50200073 */  beql  $at, $zero, .L7F01E4E0
/* 052E44 7F01E314 00001025 */   move  $v0, $zero
/* 052E48 7F01E318 0FC07771 */  jal   getEEPROMforFoldernum
/* 052E4C 7F01E31C 02002025 */   move  $a0, $s0
/* 052E50 7F01E320 1040005C */  beqz  $v0, .L7F01E494
/* 052E54 7F01E324 00409025 */   move  $s2, $v0
/* 052E58 7F01E328 00402025 */  move  $a0, $v0
/* 052E5C 7F01E32C 02602825 */  move  $a1, $s3
/* 052E60 7F01E330 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052E64 7F01E334 02A03025 */   move  $a2, $s5
/* 052E68 7F01E338 10400003 */  beqz  $v0, .L7F01E348
/* 052E6C 7F01E33C 24010012 */   li    $at, 18
/* 052E70 7F01E340 10000067 */  b     .L7F01E4E0
/* 052E74 7F01E344 24020003 */   li    $v0, 3
.L7F01E348:
/* 052E78 7F01E348 56610003 */  bnel  $s3, $at, .L7F01E358
/* 052E7C 7F01E34C 24010013 */   li    $at, 19
/* 052E80 7F01E350 1AA00005 */  blez  $s5, .L7F01E368
/* 052E84 7F01E354 24010013 */   li    $at, 19
.L7F01E358:
/* 052E88 7F01E358 16610005 */  bne   $s3, $at, .L7F01E370
/* 052E8C 7F01E35C 2AA10002 */   slti  $at, $s5, 2
/* 052E90 7F01E360 50200004 */  beql  $at, $zero, .L7F01E374
/* 052E94 7F01E364 2AA10004 */   slti  $at, $s5, 4
.L7F01E368:
/* 052E98 7F01E368 1000005D */  b     .L7F01E4E0
/* 052E9C 7F01E36C 00001025 */   move  $v0, $zero
.L7F01E370:
/* 052EA0 7F01E370 2AA10004 */  slti  $at, $s5, 4
.L7F01E374:
/* 052EA4 7F01E374 10200014 */  beqz  $at, .L7F01E3C8
/* 052EA8 7F01E378 02A08825 */   move  $s1, $s5
/* 052EAC 7F01E37C 24140004 */  li    $s4, 4
.L7F01E380:
/* 052EB0 7F01E380 1A60000A */  blez  $s3, .L7F01E3AC
/* 052EB4 7F01E384 00008025 */   move  $s0, $zero
/* 052EB8 7F01E388 02402025 */  move  $a0, $s2
.L7F01E38C:
/* 052EBC 7F01E38C 02002825 */  move  $a1, $s0
/* 052EC0 7F01E390 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052EC4 7F01E394 02203025 */   move  $a2, $s1
/* 052EC8 7F01E398 50400005 */  beql  $v0, $zero, .L7F01E3B0
/* 052ECC 7F01E39C 0213082A */   slt   $at, $s0, $s3
/* 052ED0 7F01E3A0 26100001 */  addiu $s0, $s0, 1
/* 052ED4 7F01E3A4 5613FFF9 */  bnel  $s0, $s3, .L7F01E38C
/* 052ED8 7F01E3A8 02402025 */   move  $a0, $s2
.L7F01E3AC:
/* 052EDC 7F01E3AC 0213082A */  slt   $at, $s0, $s3
.L7F01E3B0:
/* 052EE0 7F01E3B0 14200003 */  bnez  $at, .L7F01E3C0
/* 052EE4 7F01E3B4 26310001 */   addiu $s1, $s1, 1
/* 052EE8 7F01E3B8 10000049 */  b     .L7F01E4E0
/* 052EEC 7F01E3BC 24020001 */   li    $v0, 1
.L7F01E3C0:
/* 052EF0 7F01E3C0 1634FFEF */  bne   $s1, $s4, .L7F01E380
/* 052EF4 7F01E3C4 00000000 */   nop
.L7F01E3C8:
/* 052EF8 7F01E3C8 2AA10003 */  slti  $at, $s5, 3
/* 052EFC 7F01E3CC 10200011 */  beqz  $at, .L7F01E414
/* 052F00 7F01E3D0 24140004 */   li    $s4, 4
/* 052F04 7F01E3D4 2A610012 */  slti  $at, $s3, 0x12
/* 052F08 7F01E3D8 1020000E */  beqz  $at, .L7F01E414
/* 052F0C 7F01E3DC 2AA10004 */   slti  $at, $s5, 4
/* 052F10 7F01E3E0 1020000C */  beqz  $at, .L7F01E414
/* 052F14 7F01E3E4 02A08825 */   move  $s1, $s5
/* 052F18 7F01E3E8 2670FFFF */  addiu $s0, $s3, -1
/* 052F1C 7F01E3EC 02402025 */  move  $a0, $s2
.L7F01E3F0:
/* 052F20 7F01E3F0 02002825 */  move  $a1, $s0
/* 052F24 7F01E3F4 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052F28 7F01E3F8 02203025 */   move  $a2, $s1
/* 052F2C 7F01E3FC 10400003 */  beqz  $v0, .L7F01E40C
/* 052F30 7F01E400 26310001 */   addiu $s1, $s1, 1
/* 052F34 7F01E404 10000036 */  b     .L7F01E4E0
/* 052F38 7F01E408 24020001 */   li    $v0, 1
.L7F01E40C:
/* 052F3C 7F01E40C 5634FFF8 */  bnel  $s1, $s4, .L7F01E3F0
/* 052F40 7F01E410 02402025 */   move  $a0, $s2
.L7F01E414:
/* 052F44 7F01E414 2AA10003 */  slti  $at, $s5, 3
/* 052F48 7F01E418 1020001E */  beqz  $at, .L7F01E494
/* 052F4C 7F01E41C 00008825 */   move  $s1, $zero
/* 052F50 7F01E420 02402025 */  move  $a0, $s2
.L7F01E424:
/* 052F54 7F01E424 02202825 */  move  $a1, $s1
/* 052F58 7F01E428 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052F5C 7F01E42C 00003025 */   move  $a2, $zero
/* 052F60 7F01E430 50400006 */  beql  $v0, $zero, .L7F01E44C
/* 052F64 7F01E434 2A210012 */   slti  $at, $s1, 0x12
/* 052F68 7F01E438 26310001 */  addiu $s1, $s1, 1
/* 052F6C 7F01E43C 2A210012 */  slti  $at, $s1, 0x12
/* 052F70 7F01E440 5420FFF8 */  bnezl $at, .L7F01E424
/* 052F74 7F01E444 02402025 */   move  $a0, $s2
/* 052F78 7F01E448 2A210012 */  slti  $at, $s1, 0x12
.L7F01E44C:
/* 052F7C 7F01E44C 14200011 */  bnez  $at, .L7F01E494
/* 052F80 7F01E450 00000000 */   nop
/* 052F84 7F01E454 1AA0000A */  blez  $s5, .L7F01E480
/* 052F88 7F01E458 00008825 */   move  $s1, $zero
/* 052F8C 7F01E45C 02402025 */  move  $a0, $s2
.L7F01E460:
/* 052F90 7F01E460 02602825 */  move  $a1, $s3
/* 052F94 7F01E464 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052F98 7F01E468 02203025 */   move  $a2, $s1
/* 052F9C 7F01E46C 50400005 */  beql  $v0, $zero, .L7F01E484
/* 052FA0 7F01E470 0235082A */   slt   $at, $s1, $s5
/* 052FA4 7F01E474 26310001 */  addiu $s1, $s1, 1
/* 052FA8 7F01E478 5635FFF9 */  bnel  $s1, $s5, .L7F01E460
/* 052FAC 7F01E47C 02402025 */   move  $a0, $s2
.L7F01E480:
/* 052FB0 7F01E480 0235082A */  slt   $at, $s1, $s5
.L7F01E484:
/* 052FB4 7F01E484 14200003 */  bnez  $at, .L7F01E494
/* 052FB8 7F01E488 00000000 */   nop
/* 052FBC 7F01E48C 10000014 */  b     .L7F01E4E0
/* 052FC0 7F01E490 24020001 */   li    $v0, 1
.L7F01E494:
/* 052FC4 7F01E494 16600003 */  bnez  $s3, .L7F01E4A4
/* 052FC8 7F01E498 00000000 */   nop
/* 052FCC 7F01E49C 10000010 */  b     .L7F01E4E0
/* 052FD0 7F01E4A0 24020001 */   li    $v0, 1
.L7F01E4A4:
/* 052FD4 7F01E4A4 0FC24400 */  jal   get_debug_enable_agent_levels_flag
/* 052FD8 7F01E4A8 00000000 */   nop
/* 052FDC 7F01E4AC 10400005 */  beqz  $v0, .L7F01E4C4
/* 052FE0 7F01E4B0 00000000 */   nop
/* 052FE4 7F01E4B4 16A00003 */  bnez  $s5, .L7F01E4C4
/* 052FE8 7F01E4B8 00000000 */   nop
/* 052FEC 7F01E4BC 10000008 */  b     .L7F01E4E0
/* 052FF0 7F01E4C0 24020001 */   li    $v0, 1
.L7F01E4C4:
/* 052FF4 7F01E4C4 0FC24403 */  jal   get_debug_enable_all_levels_flag
/* 052FF8 7F01E4C8 00000000 */   nop
/* 052FFC 7F01E4CC 50400004 */  beql  $v0, $zero, .L7F01E4E0
/* 053000 7F01E4D0 00001025 */   move  $v0, $zero
/* 053004 7F01E4D4 10000002 */  b     .L7F01E4E0
/* 053008 7F01E4D8 24020001 */   li    $v0, 1
.L7F01E4DC:
/* 05300C 7F01E4DC 00001025 */  move  $v0, $zero
.L7F01E4E0:
/* 053010 7F01E4E0 8FBF002C */  lw    $ra, 0x2c($sp)
/* 053014 7F01E4E4 8FB00014 */  lw    $s0, 0x14($sp)
/* 053018 7F01E4E8 8FB10018 */  lw    $s1, 0x18($sp)
/* 05301C 7F01E4EC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 053020 7F01E4F0 8FB30020 */  lw    $s3, 0x20($sp)
/* 053024 7F01E4F4 8FB40024 */  lw    $s4, 0x24($sp)
/* 053028 7F01E4F8 8FB50028 */  lw    $s5, 0x28($sp)
/* 05302C 7F01E4FC 03E00008 */  jr    $ra
/* 053030 7F01E500 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01E504(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01E504
/* 053034 7F01E504 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 053038 7F01E508 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05303C 7F01E50C AFA40028 */  sw    $a0, 0x28($sp)
/* 053040 7F01E510 AFA5002C */  sw    $a1, 0x2c($sp)
/* 053044 7F01E514 0FC07794 */  jal   check_if_eeprom_flag_set_0x80_any_folder
/* 053048 7F01E518 AFA00020 */   sw    $zero, 0x20($sp)
/* 05304C 7F01E51C 04400032 */  bltz  $v0, .L7F01E5E8
/* 053050 7F01E520 00401825 */   move  $v1, $v0
/* 053054 7F01E524 8FB9002C */  lw    $t9, 0x2c($sp)
/* 053058 7F01E528 00027080 */  sll   $t6, $v0, 2
/* 05305C 7F01E52C 01C27023 */  subu  $t6, $t6, $v0
/* 053060 7F01E530 3C0F8007 */  lui   $t7, %hi(saves)
/* 053064 7F01E534 25EF9920 */  addiu $t7, %lo(saves) # addiu $t7, $t7, -0x66e0
/* 053068 7F01E538 000E7140 */  sll   $t6, $t6, 5
/* 05306C 7F01E53C 01CFC021 */  addu  $t8, $t6, $t7
/* 053070 7F01E540 27290060 */  addiu $t1, $t9, 0x60
.L7F01E544:
/* 053074 7F01E544 8F210000 */  lw    $at, ($t9)
/* 053078 7F01E548 2739000C */  addiu $t9, $t9, 0xc
/* 05307C 7F01E54C 2718000C */  addiu $t8, $t8, 0xc
/* 053080 7F01E550 AF01FFF4 */  sw    $at, -0xc($t8)
/* 053084 7F01E554 8F21FFF8 */  lw    $at, -8($t9)
/* 053088 7F01E558 AF01FFF8 */  sw    $at, -8($t8)
/* 05308C 7F01E55C 8F21FFFC */  lw    $at, -4($t9)
/* 053090 7F01E560 1729FFF8 */  bne   $t9, $t1, .L7F01E544
/* 053094 7F01E564 AF01FFFC */   sw    $at, -4($t8)
/* 053098 7F01E568 8FAA0028 */  lw    $t2, 0x28($sp)
/* 05309C 7F01E56C 1140000B */  beqz  $t2, .L7F01E59C
/* 0530A0 7F01E570 01402025 */   move  $a0, $t2
/* 0530A4 7F01E574 0FC0763D */  jal   set_eeprom_flag_0x18
/* 0530A8 7F01E578 AFA30024 */   sw    $v1, 0x24($sp)
/* 0530AC 7F01E57C 244B0001 */  addiu $t3, $v0, 1
/* 0530B0 7F01E580 8FA30024 */  lw    $v1, 0x24($sp)
/* 0530B4 7F01E584 05610004 */  bgez  $t3, .L7F01E598
/* 0530B8 7F01E588 316C0003 */   andi  $t4, $t3, 3
/* 0530BC 7F01E58C 11800002 */  beqz  $t4, .L7F01E598
/* 0530C0 7F01E590 00000000 */   nop
/* 0530C4 7F01E594 258CFFFC */  addiu $t4, $t4, -4
.L7F01E598:
/* 0530C8 7F01E598 AFAC0020 */  sw    $t4, 0x20($sp)
.L7F01E59C:
/* 0530CC 7F01E59C 00036880 */  sll   $t5, $v1, 2
/* 0530D0 7F01E5A0 01A36823 */  subu  $t5, $t5, $v1
/* 0530D4 7F01E5A4 3C0E8007 */  lui   $t6, %hi(saves)
/* 0530D8 7F01E5A8 25CE9920 */  addiu $t6, %lo(saves) # addiu $t6, $t6, -0x66e0
/* 0530DC 7F01E5AC 000D6940 */  sll   $t5, $t5, 5
/* 0530E0 7F01E5B0 01AE2021 */  addu  $a0, $t5, $t6
/* 0530E4 7F01E5B4 AFA4001C */  sw    $a0, 0x1c($sp)
/* 0530E8 7F01E5B8 0FC07659 */  jal   toggle_eeprom_flag_set_0x80
/* 0530EC 7F01E5BC 00002825 */   move  $a1, $zero
/* 0530F0 7F01E5C0 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0530F4 7F01E5C4 0FC07641 */  jal   reset_eeprom_flag_0x18
/* 0530F8 7F01E5C8 8FA50020 */   lw    $a1, 0x20($sp)
/* 0530FC 7F01E5CC 0FC075E8 */  jal   sub_GAME_7F01D7A0
/* 053100 7F01E5D0 8FA4001C */   lw    $a0, 0x1c($sp)
/* 053104 7F01E5D4 8FAF0028 */  lw    $t7, 0x28($sp)
/* 053108 7F01E5D8 51E00004 */  beql  $t7, $zero, .L7F01E5EC
/* 05310C 7F01E5DC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 053110 7F01E5E0 0FC07610 */  jal   reset_folder_to_default
/* 053114 7F01E5E4 01E02025 */   move  $a0, $t7
.L7F01E5E8:
/* 053118 7F01E5E8 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01E5EC:
/* 05311C 7F01E5EC 27BD0028 */  addiu $sp, $sp, 0x28
/* 053120 7F01E5F0 03E00008 */  jr    $ra
/* 053124 7F01E5F4 00000000 */   nop
)
#endif



#ifdef NONMATCHING
void unlock_stage_in_folder_on_difficulty(void) {

}
#else
GLOBAL_ASM(
.text
glabel unlock_stage_in_folder_on_difficulty
/* 053128 7F01E5F8 27BDFF68 */  addiu $sp, $sp, -0x98
/* 05312C 7F01E5FC AFB50028 */  sw    $s5, 0x28($sp)
/* 053130 7F01E600 AFB40024 */  sw    $s4, 0x24($sp)
/* 053134 7F01E604 AFB2001C */  sw    $s2, 0x1c($sp)
/* 053138 7F01E608 AFB00014 */  sw    $s0, 0x14($sp)
/* 05313C 7F01E60C 00808025 */  move  $s0, $a0
/* 053140 7F01E610 00A09025 */  move  $s2, $a1
/* 053144 7F01E614 00C0A025 */  move  $s4, $a2
/* 053148 7F01E618 00E0A825 */  move  $s5, $a3
/* 05314C 7F01E61C AFBF002C */  sw    $ra, 0x2c($sp)
/* 053150 7F01E620 AFB30020 */  sw    $s3, 0x20($sp)
/* 053154 7F01E624 04800045 */  bltz  $a0, .L7F01E73C
/* 053158 7F01E628 AFB10018 */   sw    $s1, 0x18($sp)
/* 05315C 7F01E62C 28810004 */  slti  $at, $a0, 4
/* 053160 7F01E630 50200043 */  beql  $at, $zero, .L7F01E740
/* 053164 7F01E634 8FBF002C */   lw    $ra, 0x2c($sp)
/* 053168 7F01E638 04A00040 */  bltz  $a1, .L7F01E73C
/* 05316C 7F01E63C 28A10014 */   slti  $at, $a1, 0x14
/* 053170 7F01E640 5020003F */  beql  $at, $zero, .L7F01E740
/* 053174 7F01E644 8FBF002C */   lw    $ra, 0x2c($sp)
/* 053178 7F01E648 04C0003C */  bltz  $a2, .L7F01E73C
/* 05317C 7F01E64C 28C10004 */   slti  $at, $a2, 4
/* 053180 7F01E650 1020003A */  beqz  $at, .L7F01E73C
/* 053184 7F01E654 27B10038 */   addiu $s1, $sp, 0x38
/* 053188 7F01E658 3C0E8003 */  lui   $t6, %hi(D_8002C640+0x20)
/* 05318C 7F01E65C 25CEC660 */  addiu $t6, %lo(D_8002C640+0x20) # addiu $t6, $t6, -0x39a0
/* 053190 7F01E660 25D80060 */  addiu $t8, $t6, 0x60
/* 053194 7F01E664 0220C825 */  move  $t9, $s1
.L7F01E668:
/* 053198 7F01E668 8DC10000 */  lw    $at, ($t6)
/* 05319C 7F01E66C 25CE000C */  addiu $t6, $t6, 0xc
/* 0531A0 7F01E670 2739000C */  addiu $t9, $t9, 0xc
/* 0531A4 7F01E674 AF21FFF4 */  sw    $at, -0xc($t9)
/* 0531A8 7F01E678 8DC1FFF8 */  lw    $at, -8($t6)
/* 0531AC 7F01E67C AF21FFF8 */  sw    $at, -8($t9)
/* 0531B0 7F01E680 8DC1FFFC */  lw    $at, -4($t6)
/* 0531B4 7F01E684 15D8FFF8 */  bne   $t6, $t8, .L7F01E668
/* 0531B8 7F01E688 AF21FFFC */   sw    $at, -4($t9)
/* 0531BC 7F01E68C 0FC07771 */  jal   getEEPROMforFoldernum
/* 0531C0 7F01E690 02002025 */   move  $a0, $s0
/* 0531C4 7F01E694 1040000F */  beqz  $v0, .L7F01E6D4
/* 0531C8 7F01E698 AFA20034 */   sw    $v0, 0x34($sp)
/* 0531CC 7F01E69C 00405025 */  move  $t2, $v0
/* 0531D0 7F01E6A0 02205825 */  move  $t3, $s1
/* 0531D4 7F01E6A4 24490060 */  addiu $t1, $v0, 0x60
.L7F01E6A8:
/* 0531D8 7F01E6A8 8D410000 */  lw    $at, ($t2)
/* 0531DC 7F01E6AC 254A000C */  addiu $t2, $t2, 0xc
/* 0531E0 7F01E6B0 256B000C */  addiu $t3, $t3, 0xc
/* 0531E4 7F01E6B4 AD61FFF4 */  sw    $at, -0xc($t3)
/* 0531E8 7F01E6B8 8D41FFF8 */  lw    $at, -8($t2)
/* 0531EC 7F01E6BC AD61FFF8 */  sw    $at, -8($t3)
/* 0531F0 7F01E6C0 8D41FFFC */  lw    $at, -4($t2)
/* 0531F4 7F01E6C4 1549FFF8 */  bne   $t2, $t1, .L7F01E6A8
/* 0531F8 7F01E6C8 AD61FFFC */   sw    $at, -4($t3)
/* 0531FC 7F01E6CC 10000004 */  b     .L7F01E6E0
/* 053200 7F01E6D0 00000000 */   nop
.L7F01E6D4:
/* 053204 7F01E6D4 02202025 */  move  $a0, $s1
/* 053208 7F01E6D8 0FC07636 */  jal   set_eeprom_to_folder_num
/* 05320C 7F01E6DC 02002825 */   move  $a1, $s0
.L7F01E6E0:
/* 053210 7F01E6E0 06800013 */  bltz  $s4, .L7F01E730
/* 053214 7F01E6E4 02808025 */   move  $s0, $s4
/* 053218 7F01E6E8 3C1305F5 */  lui   $s3, (0x05F5E0FF >> 16) # lui $s3, 0x5f5
/* 05321C 7F01E6EC 3673E0FF */  ori   $s3, (0x05F5E0FF & 0xFFFF) # ori $s3, $s3, 0xe0ff
.L7F01E6F0:
/* 053220 7F01E6F0 16140008 */  bne   $s0, $s4, .L7F01E714
/* 053224 7F01E6F4 02202025 */   move  $a0, $s1
/* 053228 7F01E6F8 02202025 */  move  $a0, $s1
/* 05322C 7F01E6FC 02402825 */  move  $a1, $s2
/* 053230 7F01E700 02003025 */  move  $a2, $s0
/* 053234 7F01E704 0FC0772C */  jal   sub_GAME_7F01DCB0
/* 053238 7F01E708 02A03825 */   move  $a3, $s5
/* 05323C 7F01E70C 10000006 */  b     .L7F01E728
/* 053240 7F01E710 2610FFFF */   addiu $s0, $s0, -1
.L7F01E714:
/* 053244 7F01E714 02402825 */  move  $a1, $s2
/* 053248 7F01E718 02003025 */  move  $a2, $s0
/* 05324C 7F01E71C 0FC0772C */  jal   sub_GAME_7F01DCB0
/* 053250 7F01E720 02603825 */   move  $a3, $s3
/* 053254 7F01E724 2610FFFF */  addiu $s0, $s0, -1
.L7F01E728:
/* 053258 7F01E728 0601FFF1 */  bgez  $s0, .L7F01E6F0
/* 05325C 7F01E72C 00000000 */   nop
.L7F01E730:
/* 053260 7F01E730 8FA40034 */  lw    $a0, 0x34($sp)
/* 053264 7F01E734 0FC07941 */  jal   sub_GAME_7F01E504
/* 053268 7F01E738 02202825 */   move  $a1, $s1
.L7F01E73C:
/* 05326C 7F01E73C 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F01E740:
/* 053270 7F01E740 8FB00014 */  lw    $s0, 0x14($sp)
/* 053274 7F01E744 8FB10018 */  lw    $s1, 0x18($sp)
/* 053278 7F01E748 8FB2001C */  lw    $s2, 0x1c($sp)
/* 05327C 7F01E74C 8FB30020 */  lw    $s3, 0x20($sp)
/* 053280 7F01E750 8FB40024 */  lw    $s4, 0x24($sp)
/* 053284 7F01E754 8FB50028 */  lw    $s5, 0x28($sp)
/* 053288 7F01E758 03E00008 */  jr    $ra
/* 05328C 7F01E75C 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif



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



void get_highest_stage_difficulty_completed_in_folder(s32 foldernum, LEVEL_SOLO_SEQUENCE *stage, DIFFICULTY *difficulty)
{
    struct save_data *folder;
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



s32 get_highest_stage_unlocked_in_folder(s32 foldernum) {
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

u32 get_highest_stage_unlocked_any_folder(void) {
    u32 isfound;
    int folder;
    u32 isunlocked;

    isunlocked = 0;
    folder = 0;
    while (folder != 4) {
        isfound = get_highest_stage_unlocked_in_folder(folder);
        folder += 1;
        if ((int)isunlocked < (int)isfound) {
            isunlocked = isfound;
        }
    };
    return isunlocked;
}

s32 check_cradle_completed_in_folder(s32 foldernum)
{
    return (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_CRADLE, 0) == 3) ||
            (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_CRADLE, 1) == 3) ||
            (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_CRADLE, 2) == 3);
}

s32 check_aztec_completed_in_folder_secret_00(s32 foldernum) {
    return (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_AZTEC, 1) == 3) ||
            (isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_AZTEC, 2) == 3);
}

s32 check_egypt_completed_in_folder_00(int foldernum)
{
    return isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_EGYPT, DIFFICULTY_00) == 3;
}

u32 check_cradle_completed_any_folder(void) {
    u32 completed;
    int folder;

    folder = 0;
    while (folder != 4) {
        completed = check_cradle_completed_in_folder(folder);
        folder += 1;
        if (completed != FALSE) {
            return TRUE;
        }
    };
    return FALSE;
}


u32 check_aztec_completed_any_folder_secret_00(void) {
    u32 completed;
    int folder;

    folder = 0;
    while (folder != 4) {
        completed = check_aztec_completed_in_folder_secret_00(folder);
        folder += 1;
        if (completed != FALSE) {
            return TRUE;
        }
    };
    return FALSE;
}


u32 check_egypt_completed_any_folder_00(void) {
    u32 completed;
    int folder;

    folder = 0;
    while (folder != 4) {
        completed = check_egypt_completed_in_folder_00(folder);
        folder += 1;
        if (completed != FALSE) {
            return TRUE;
        }
    };
    return FALSE;
}


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

void set_selected_bond_to_folder(s32 folder, s32 bond) {
    if (folder < 0 || folder > 3)
    {
        return;
    }

    save_selected_bond[folder] = 0;
}

void sub_GAME_7F01EBF4(u32 unused) {
    return;
}

void sub_GAME_7F01EBFC(u32 unused) {
    return;
}




void delete_eeprom_folder(s32 foldernum)
{
    struct save_data *save;
    LEVEL_SOLO_SEQUENCE stage;
    DIFFICULTY difficulty;
    struct save_data new_save;

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


void sub_GAME_7F01ED10(u32 foldernum)
{
    struct save_data *save;
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

void sub_GAME_7F01EDA0(s32 foldernum)
{
    struct save_data* save;
    LEVEL_SOLO_SEQUENCE stage;
    DIFFICULTY difficulty;
    s32 other;
    struct save_data new_save;
    struct save_data* temp_s2;

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



void update_eeprom_to_current_solo_watch_settings(struct save_data *save)
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

void get_screen_ratio_settings_for_mpgame_from_folder(u32 foldernum)
{
    struct save_data *save;
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



void delete_update_eeprom_file(s32 foldernum)
{
    struct save_data *save;
    struct save_data stack100;
    struct save_data stack196;

    if (foldernum >= 0 && foldernum < 4)
    {
        save = getEEPROMforFoldernum(foldernum);

        *(&stack100) = *(&D_8002C7E0);

        if (save != 0) {
            *(&stack100) = *save;
        } else {
            set_eeprom_to_folder_num(&stack100, foldernum);
        }

        *(&stack196) = *(&stack100);

        update_eeprom_to_current_solo_watch_settings(&stack196);

        if (_bcmp(&stack196, &stack100, 0x60) != 0) {
            sub_GAME_7F01E504(save, &stack196);
        }
    }
}



void copy_eeprom_to_stack_set_folder_num(s32 foldernum)
{
    struct save_data *save;
    struct save_data new_save;

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



#ifdef NONMATCHING
void copy_eeprom_from_to(void) {

}
#else
GLOBAL_ASM(
.text
glabel copy_eeprom_from_to
/* 053EC4 7F01F394 27BDFF80 */  addiu $sp, $sp, -0x80
/* 053EC8 7F01F398 AFBF0014 */  sw    $ra, 0x14($sp)
/* 053ECC 7F01F39C 0FC07771 */  jal   getEEPROMforFoldernum
/* 053ED0 7F01F3A0 AFA50084 */   sw    $a1, 0x84($sp)
/* 053ED4 7F01F3A4 1040000F */  beqz  $v0, .L7F01F3E4
/* 053ED8 7F01F3A8 8FA30084 */   lw    $v1, 0x84($sp)
/* 053EDC 7F01F3AC 0040C025 */  move  $t8, $v0
/* 053EE0 7F01F3B0 0060C825 */  move  $t9, $v1
/* 053EE4 7F01F3B4 244F0060 */  addiu $t7, $v0, 0x60
.L7F01F3B8:
/* 053EE8 7F01F3B8 8F010000 */  lw    $at, ($t8)
/* 053EEC 7F01F3BC 2718000C */  addiu $t8, $t8, 0xc
/* 053EF0 7F01F3C0 2739000C */  addiu $t9, $t9, 0xc
/* 053EF4 7F01F3C4 AF21FFF4 */  sw    $at, -0xc($t9)
/* 053EF8 7F01F3C8 8F01FFF8 */  lw    $at, -8($t8)
/* 053EFC 7F01F3CC AF21FFF8 */  sw    $at, -8($t9)
/* 053F00 7F01F3D0 8F01FFFC */  lw    $at, -4($t8)
/* 053F04 7F01F3D4 170FFFF8 */  bne   $t8, $t7, .L7F01F3B8
/* 053F08 7F01F3D8 AF21FFFC */   sw    $at, -4($t9)
/* 053F0C 7F01F3DC 1000001C */  b     .L7F01F450
/* 053F10 7F01F3E0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F01F3E4:
/* 053F14 7F01F3E4 3C088003 */  lui   $t0, %hi(blank_eeprom)
/* 053F18 7F01F3E8 27A2001C */  addiu $v0, $sp, 0x1c
/* 053F1C 7F01F3EC 2508C8A0 */  addiu $t0, %lo(blank_eeprom) # addiu $t0, $t0, -0x3760
/* 053F20 7F01F3F0 250A0060 */  addiu $t2, $t0, 0x60
/* 053F24 7F01F3F4 00405825 */  move  $t3, $v0
.L7F01F3F8:
/* 053F28 7F01F3F8 8D010000 */  lw    $at, ($t0)
/* 053F2C 7F01F3FC 2508000C */  addiu $t0, $t0, 0xc
/* 053F30 7F01F400 256B000C */  addiu $t3, $t3, 0xc
/* 053F34 7F01F404 AD61FFF4 */  sw    $at, -0xc($t3)
/* 053F38 7F01F408 8D01FFF8 */  lw    $at, -8($t0)
/* 053F3C 7F01F40C AD61FFF8 */  sw    $at, -8($t3)
/* 053F40 7F01F410 8D01FFFC */  lw    $at, -4($t0)
/* 053F44 7F01F414 150AFFF8 */  bne   $t0, $t2, .L7F01F3F8
/* 053F48 7F01F418 AD61FFFC */   sw    $at, -4($t3)
/* 053F4C 7F01F41C 00407025 */  move  $t6, $v0
/* 053F50 7F01F420 00607825 */  move  $t7, $v1
/* 053F54 7F01F424 244D0060 */  addiu $t5, $v0, 0x60
.L7F01F428:
/* 053F58 7F01F428 8DC10000 */  lw    $at, ($t6)
/* 053F5C 7F01F42C 25CE000C */  addiu $t6, $t6, 0xc
/* 053F60 7F01F430 25EF000C */  addiu $t7, $t7, 0xc
/* 053F64 7F01F434 ADE1FFF4 */  sw    $at, -0xc($t7)
/* 053F68 7F01F438 8DC1FFF8 */  lw    $at, -8($t6)
/* 053F6C 7F01F43C ADE1FFF8 */  sw    $at, -8($t7)
/* 053F70 7F01F440 8DC1FFFC */  lw    $at, -4($t6)
/* 053F74 7F01F444 15CDFFF8 */  bne   $t6, $t5, .L7F01F428
/* 053F78 7F01F448 ADE1FFFC */   sw    $at, -4($t7)
/* 053F7C 7F01F44C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01F450:
/* 053F80 7F01F450 27BD0080 */  addiu $sp, $sp, 0x80
/* 053F84 7F01F454 03E00008 */  jr    $ra
/* 053F88 7F01F458 00000000 */   nop
)
#endif


void copy_demo_eeprom_to_ramrom_folder(u32 foldernum, struct save_data *save)
{
    if (foldernum == RAMROM_FOLDERNUM)
    {
        saves[5] = *save;
    }
}

s32 check_for_007_mode_unlocked(u32 foldernum)
{
    LEVEL_SOLO_SEQUENCE stage;
    struct save_data* folder;

    folder = getEEPROMforFoldernum(foldernum);
    if (folder != NULL)
    {
        if ((folder->flag_007 & 1) != 0)
        {
            return TRUE;
        }
        for (stage = SP_LEVEL_DAM; stage < SP_LEVEL_MAX; stage++)
        {
            if (get_eeprom_stage_completed_for_difficulty(folder, stage, DIFFICULTY_00) == 0)
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
