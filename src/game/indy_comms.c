#include "ultra64.h"
#include "game/indy_commands.h"
#include "game/indy_comms.h"

s32 init_indy_if_not_ready(void) {
    if (indy_ready != 1)
    {
        indy_ready = 1;
        init_indy_if_ready();
    }
}

void nullsub_48(void) {
    return;
}

void init_indy_if_ready(void) {
    if (indy_ready)
    {
        post_indy__res_cmd_initialize_seq();
    }
}


void load_resource_on_indy(u8 *filename, u8 *targetloc)
{
    u8 response1 [8];
    u8 response2 [4];
    u32 size;
  
    if (indy_ready)
    {
        post_indyrescmd_req_filename_size(filename,0x400000);
        response_indyrescmd_1_8_2(response1,response2,(u32)&size,targetloc);
    }
    return;
}


void indy_send_capture_data(u8 *filename, u8 *data, u32 size)
{
    u8 auStack4 [4];
  
    if (indy_ready) 
    {
        post_indyrescmd_send_capture_data(filename, size, (struct indy_resource_entry *)data);
        response_indyrescmd_1_A_2(auStack4);
    }
    return;
}


void indy_load_ramrom_file(u8 *filename, u8 *target, s32 size)
{
    u32 uStack4;
    u32 uStack8;
    u32 uStack12;
  
    if (indy_ready)
    {
        post_indyrescmd_request_ramrom_file(filename,target,size);
        response_indyrescmd_1_10_2(&uStack4,&uStack8,&uStack12);
    }
    return;
}


void check_file_exported(u8 *filename, s32 size, u8 * data)
{
    u8 auStack4 [4];
  
    if (indy_ready)
    {
        post_indyrescmd_game_prof_sendfile(filename,data,size);
        response_indyrescmd_1_E_2(auStack4);
    }
  return;
}

#ifdef NONMATCHING
//0010 4BE0: 10 00 00 06 AF A0 00 1C
//instead of 
//0010 4BE0: 10 00 00 07 00 00 10 25

//0010 4BFC: 8F BF 00 14
//swappped with
//0010 4C00: 8F A2 00 1C


u8 * check_file_found_on_indy(u8 *name, s32 size)
{
    u8 *response;
  
    if (!indy_ready) {
        response = 0x0;
    } else {
        post_indyrescmd_game_printf_send(name);
        response_indyrescmd_1_6_2(&response,size);
    }
    return response;
}
#else
GLOBAL_ASM(
.text
glabel check_file_found_on_indy
/* 104BC8 7F0D0098 3C0E8005 */  lui   $t6, %hi(indy_ready) 
/* 104BCC 7F0D009C 8DCEEAC8 */  lw    $t6, %lo(indy_ready)($t6)
/* 104BD0 7F0D00A0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 104BD4 7F0D00A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104BD8 7F0D00A8 15C00003 */  bnez  $t6, .L7F0D00B8
/* 104BDC 7F0D00AC AFA50024 */   sw    $a1, 0x24($sp)
/* 104BE0 7F0D00B0 10000007 */  b     .L7F0D00D0
/* 104BE4 7F0D00B4 00001025 */   move  $v0, $zero
.L7F0D00B8:
/* 104BE8 7F0D00B8 0FC342C3 */  jal   post_indyrescmd_game_printf_send
/* 104BEC 7F0D00BC 00000000 */   nop   
/* 104BF0 7F0D00C0 27A4001C */  addiu $a0, $sp, 0x1c
/* 104BF4 7F0D00C4 0FC345EB */  jal   response_indyrescmd_1_6_2
/* 104BF8 7F0D00C8 8FA50024 */   lw    $a1, 0x24($sp)
/* 104BFC 7F0D00CC 8FA2001C */  lw    $v0, 0x1c($sp)
.L7F0D00D0:
/* 104C00 7F0D00D0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104C04 7F0D00D4 27BD0020 */  addiu $sp, $sp, 0x20
/* 104C08 7F0D00D8 03E00008 */  jr    $ra
/* 104C0C 7F0D00DC 00000000 */   nop   
)
#endif




#ifdef NONMATCHING

//0010 4C20: 15 C0 00 03 00 00 00 00  10 00 00 05 AF A0 00 1C
//instead of
//0010 4C20: 15 C0 00 03 00 00 00 00  10 00 00 06 00 00 10 25
u8 *send_command_string(u8 *cmdstr)
{
    u8 *local_4;
  
    if (!indy_ready) {
        local_4 = 0;
    }
    else {
        post_indyrescmd_1_B_2(cmdstr);
        response_indyrescmd_1_C_2(&local_4);
    }
    return local_4;
}
#else
GLOBAL_ASM(
.text
glabel send_command_string
/* 104C10 7F0D00E0 3C0E8005 */  lui   $t6, %hi(indy_ready) 
/* 104C14 7F0D00E4 8DCEEAC8 */  lw    $t6, %lo(indy_ready)($t6)
/* 104C18 7F0D00E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 104C1C 7F0D00EC AFBF0014 */  sw    $ra, 0x14($sp)
/* 104C20 7F0D00F0 15C00003 */  bnez  $t6, .L7F0D0100
/* 104C24 7F0D00F4 00000000 */   nop   
/* 104C28 7F0D00F8 10000006 */  b     .L7F0D0114
/* 104C2C 7F0D00FC 00001025 */   move  $v0, $zero
.L7F0D0100:
/* 104C30 7F0D0100 0FC3439D */  jal   post_indyrescmd_1_B_2
/* 104C34 7F0D0104 00000000 */   nop   
/* 104C38 7F0D0108 0FC34654 */  jal   response_indyrescmd_1_C_2
/* 104C3C 7F0D010C 27A4001C */   addiu $a0, $sp, 0x1c
/* 104C40 7F0D0110 8FA2001C */  lw    $v0, 0x1c($sp)
.L7F0D0114:
/* 104C44 7F0D0114 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104C48 7F0D0118 27BD0020 */  addiu $sp, $sp, 0x20
/* 104C4C 7F0D011C 03E00008 */  jr    $ra
/* 104C50 7F0D0120 00000000 */   nop   
)
#endif


void sub_GAME_7F0D0124(void) {
    if (indy_ready != 0)
    {
        rmon_debug_returns_neg_1();
    }
    return;
}

void send_indy_close_port_cmd(void) {
    send_command_string("sleep 5; /etc/killall ghost gload");
}




