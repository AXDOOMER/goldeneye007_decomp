#include "ultra64.h"
#include "game/indy_commands.h"

// data
//D:8004EAC0
s32 D_8004EAC0 = 0;
//D:8004EAC4
s32 indy_status = 0x103;
//D:8004EAC8
s32 indy_ready = 0;
//D:8004EACC
s32 D_8004EACC = 0x0;
//D:8004EAD0
s32 D_8004EAD0 = 0x0;



void indy_buffer_read_command(u8 *buffer,u32 size)
{
    int i;

    for (i = 0; i != 100000; i += 4) { }

    rmon7000CEC0(buffer, size);

    for (i = 0; i != 100000; i += 1) { }
}


void indy_buffer_write_command(u8 *buffer,u32 size)
{
  int i;
  
    for (i = 0; i != 100000; i += 4){}

    rmon7000CEB8(buffer, size);

    for (i = 0; i != 100000; i += 1){}
}





#ifdef NONMATCHING
void postindyresourcecommand(indy_resource_entry *param_1,u32 param_2)
{

}
#else
GLOBAL_ASM(
.text
glabel postindyresourcecommand
/* 104D50 7F0D0220 27BDFAC0 */  addiu $sp, $sp, -0x540
/* 104D54 7F0D0224 27A20040 */  addiu $v0, $sp, 0x40
/* 104D58 7F0D0228 308F0007 */  andi  $t7, $a0, 7
/* 104D5C 7F0D022C AFBF0014 */  sw    $ra, 0x14($sp)
/* 104D60 7F0D0230 AFA40540 */  sw    $a0, 0x540($sp)
/* 104D64 7F0D0234 00A03025 */  move  $a2, $a1
/* 104D68 7F0D0238 00401825 */  move  $v1, $v0
/* 104D6C 7F0D023C 11E0002B */  beqz  $t7, .L7F0D02EC
/* 104D70 7F0D0240 00403825 */   move  $a3, $v0
/* 104D74 7F0D0244 2CA10501 */  sltiu $at, $a1, 0x501
/* 104D78 7F0D0248 14200003 */  bnez  $at, .L7F0D0258
/* 104D7C 7F0D024C 30580007 */   andi  $t8, $v0, 7
/* 104D80 7F0D0250 1000003D */  b     .L7F0D0348
/* 104D84 7F0D0254 00001025 */   move  $v0, $zero
.L7F0D0258:
/* 104D88 7F0D0258 13000003 */  beqz  $t8, .L7F0D0268
/* 104D8C 7F0D025C 3C088005 */   lui   $t0, %hi(indy_status) 
/* 104D90 7F0D0260 27A70044 */  addiu $a3, $sp, 0x44
/* 104D94 7F0D0264 00E01825 */  move  $v1, $a3
.L7F0D0268:
/* 104D98 7F0D0268 00662021 */  addu  $a0, $v1, $a2
/* 104D9C 7F0D026C 0064082B */  sltu  $at, $v1, $a0
/* 104DA0 7F0D0270 10200007 */  beqz  $at, .L7F0D0290
/* 104DA4 7F0D0274 8FA20540 */   lw    $v0, 0x540($sp)
.L7F0D0278:
/* 104DA8 7F0D0278 90590000 */  lbu   $t9, ($v0)
/* 104DAC 7F0D027C 24630001 */  addiu $v1, $v1, 1
/* 104DB0 7F0D0280 0064082B */  sltu  $at, $v1, $a0
/* 104DB4 7F0D0284 24420001 */  addiu $v0, $v0, 1
/* 104DB8 7F0D0288 1420FFFB */  bnez  $at, .L7F0D0278
/* 104DBC 7F0D028C A079FFFF */   sb    $t9, -1($v1)
.L7F0D0290:
/* 104DC0 7F0D0290 8D08EAC4 */  lw    $t0, %lo(indy_status)($t0)
/* 104DC4 7F0D0294 24C50003 */  addiu $a1, $a2, 3
/* 104DC8 7F0D0298 2401FFFC */  li    $at, -4
/* 104DCC 7F0D029C 31090020 */  andi  $t1, $t0, 0x20
/* 104DD0 7F0D02A0 1120000D */  beqz  $t1, .L7F0D02D8
/* 104DD4 7F0D02A4 00A15024 */   and   $t2, $a1, $at
/* 104DD8 7F0D02A8 10C0000B */  beqz  $a2, .L7F0D02D8
/* 104DDC 7F0D02AC 00001025 */   move  $v0, $zero
/* 104DE0 7F0D02B0 30C40003 */  andi  $a0, $a2, 3
/* 104DE4 7F0D02B4 10800005 */  beqz  $a0, .L7F0D02CC
/* 104DE8 7F0D02B8 00801825 */   move  $v1, $a0
/* 104DEC 7F0D02BC 24420001 */  addiu $v0, $v0, 1
.L7F0D02C0:
/* 104DF0 7F0D02C0 5462FFFF */  bnel  $v1, $v0, .L7F0D02C0
/* 104DF4 7F0D02C4 24420001 */   addiu $v0, $v0, 1
/* 104DF8 7F0D02C8 10460003 */  beq   $v0, $a2, .L7F0D02D8
.L7F0D02CC:
/* 104DFC 7F0D02CC 24420004 */   addiu $v0, $v0, 4
.L7F0D02D0:
/* 104E00 7F0D02D0 5446FFFF */  bnel  $v0, $a2, .L7F0D02D0
/* 104E04 7F0D02D4 24420004 */   addiu $v0, $v0, 4
.L7F0D02D8:
/* 104E08 7F0D02D8 00E02025 */  move  $a0, $a3
/* 104E0C 7F0D02DC 0FC34074 */  jal   indy_buffer_write_command
/* 104E10 7F0D02E0 01402825 */   move  $a1, $t2
/* 104E14 7F0D02E4 10000018 */  b     .L7F0D0348
/* 104E18 7F0D02E8 24020001 */   li    $v0, 1
.L7F0D02EC:
/* 104E1C 7F0D02EC 3C0B8005 */  lui   $t3, %hi(indy_status) 
/* 104E20 7F0D02F0 8D6BEAC4 */  lw    $t3, %lo(indy_status)($t3)
/* 104E24 7F0D02F4 24C50003 */  addiu $a1, $a2, 3
/* 104E28 7F0D02F8 2401FFFC */  li    $at, -4
/* 104E2C 7F0D02FC 316C0020 */  andi  $t4, $t3, 0x20
/* 104E30 7F0D0300 1180000D */  beqz  $t4, .L7F0D0338
/* 104E34 7F0D0304 00A16824 */   and   $t5, $a1, $at
/* 104E38 7F0D0308 10C0000B */  beqz  $a2, .L7F0D0338
/* 104E3C 7F0D030C 00001025 */   move  $v0, $zero
/* 104E40 7F0D0310 30C40003 */  andi  $a0, $a2, 3
/* 104E44 7F0D0314 10800005 */  beqz  $a0, .L7F0D032C
/* 104E48 7F0D0318 00801825 */   move  $v1, $a0
/* 104E4C 7F0D031C 24420001 */  addiu $v0, $v0, 1
.L7F0D0320:
/* 104E50 7F0D0320 5462FFFF */  bnel  $v1, $v0, .L7F0D0320
/* 104E54 7F0D0324 24420001 */   addiu $v0, $v0, 1
/* 104E58 7F0D0328 10460003 */  beq   $v0, $a2, .L7F0D0338
.L7F0D032C:
/* 104E5C 7F0D032C 24420004 */   addiu $v0, $v0, 4
.L7F0D0330:
/* 104E60 7F0D0330 5446FFFF */  bnel  $v0, $a2, .L7F0D0330
/* 104E64 7F0D0334 24420004 */   addiu $v0, $v0, 4
.L7F0D0338:
/* 104E68 7F0D0338 8FA40540 */  lw    $a0, 0x540($sp)
/* 104E6C 7F0D033C 0FC34074 */  jal   indy_buffer_write_command
/* 104E70 7F0D0340 01A02825 */   move  $a1, $t5
/* 104E74 7F0D0344 24020001 */  li    $v0, 1
.L7F0D0348:
/* 104E78 7F0D0348 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104E7C 7F0D034C 27BD0540 */  addiu $sp, $sp, 0x540
/* 104E80 7F0D0350 03E00008 */  jr    $ra
/* 104E84 7F0D0354 00000000 */   nop   
)
#endif






u32 send2indyresourcecommands(struct indy_resource_entry * entry1, u32 size1, struct indy_resource_entry * entry2, u32 size2)
{
    postindyresourcecommand(entry1,size1);
    postindyresourcecommand(entry2,size2);
    return 1;
}


void post_type1_indyrescmd_sizenextcmd(s32 readsize,s32 writesize)
{
    struct indy_resource_entry cmd;

    cmd.resourceID = 0x9abf1623;
    cmd.type = 1;
    cmd.size = 0x14;
    cmd.readsize = readsize;
    cmd.writesize = writesize;
    postindyresourcecommand(&cmd,0x14);
}


void post_type2_indyrescmd_cmds_rdy_to_proc(s32 readsize,s32 writesize)
{
    struct indy_resource_entry cmd;

    cmd.resourceID = 0x9abf1623;
    cmd.type = 2;
    cmd.size = 0x14;
    cmd.readsize = readsize;
    cmd.writesize = writesize;
    postindyresourcecommand(&cmd,0x14);
}


void post_type0_indyrescmd_init(s32 readsize,s32 writesize)
{
    struct indy_resource_entry cmd;
    cmd.resourceID = 0x9abf1623;
    cmd.type = 0;
    cmd.size = 0x14;
    cmd.readsize = readsize;
    cmd.writesize = writesize;
    postindyresourcecommand(&cmd,0x14);
}

void post_type3_indyrescmd(s32 rsize,s32 wsize,char *strptr)
{
    struct indy_resource_entry_type3 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 3;
    cmd.entry.size = 0x114;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,strptr, 256);
    cmd.strbuffer[255] = 0;
    postindyresourcecommand(&cmd.entry,0x114);
}


void post_type4_indyrescmd_data_recieved(s32 readsize,s32 writesize,s32 data)
{
    struct indy_resource_entry_type4 cmd;
    
    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 4;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    postindyresourcecommand(&cmd.entry,0x18);
}


void post_type5_indyrescmd_printfsend(s32 rsize,s32 wsize,char *name)
{
  struct indy_resource_entry_type3 cmd;
  
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 5;
  cmd.entry.size = 0x114;
  cmd.entry.readsize = rsize;
  cmd.entry.writesize = wsize;
  strncpy(cmd.strbuffer,name,0x100);
  cmd.strbuffer[255] = '\0';
  postindyresourcecommand(&cmd,0x114);
}


void post_type6_indyrescmd_printfrecieved(s32 readsize,s32 writesize,u32 data1,u32 data2)
{
    struct indy_resource_entry_type6 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 6;
    cmd.entry.size = 0x1c;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data1 = data1;
    cmd.data2 = data2;
    postindyresourcecommand(&cmd.entry,0x1c);
}


void post_type7_indyrescmd_log_send(u32 rsize,u32 wsize,u8 *filename,u32 size)
{
    struct indy_resource_entry_type7 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 7;
    cmd.entry.size = 0x118;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,filename,0x100);
    cmd.strbuffer[255] = '\0';
    cmd.size = size;
    postindyresourcecommand(&cmd,0x118);
}


void post_type8_indyrescmd_log_recieved(s32 rsize,s32 wsize,u32 data1,u32 data2,u32 cmd2size,struct indy_resource_entry_type8 *cmd2)
{
   struct indy_resource_entry_type8 cmd;
  
   cmd.entry.resourceID = 0x9abf1623;
   cmd.entry.type = 8;
  
   cmd.entry.size = (cmd2size +3 & ~3)+ 0x20;
   cmd.entry.readsize = rsize;
   cmd.entry.writesize = wsize;
  
   cmd.data1 = data1;
   cmd.size = cmd2size;
   cmd.data2 = data2;
   send2indyresourcecommands(&cmd,0x20,cmd2,cmd2size);
}


void post_type9_indyrescmd_app_command_ready(s32 rsize,s32 wsize,char *strptr,u32 size2,struct indy_resource_entry3 *cmd2)
{
  struct indy_resource_entry_type3 cmd;

  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 9;

  cmd.entry.size = (size2 + 3 & 0xfffffffc) + 0x114;
  cmd.entry.readsize = rsize;
  cmd.entry.writesize = wsize;

  strncpy(cmd.strbuffer,strptr,0x100);
  cmd.strbuffer[255] = '\0';
  send2indyresourcecommands(&cmd,0x114,cmd2,size2);
  
}


void post_typeA_indyrescmd_app_command_recieved(s32 readsize,s32 writesize,u32 data)
{
  struct indy_resource_entry_type4 cmd;
  
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 10;
  cmd.entry.size = 0x18;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;
  postindyresourcecommand(&cmd.entry,0x18);
}


void post_typeF_indyrescmd_fault_send(u32 rsize,u32 wsize,char *name,u32 filesize,u32 ptarget)
{
  struct indy_resource_entry_typeF cmd;
  
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 0xf;
  cmd.entry.size = 0x11c;
  cmd.entry.readsize = rsize;
  cmd.entry.writesize = wsize;
  strncpy(cmd.strbuffer,name,0x100);
  cmd.strbuffer[255] = '\0';
  cmd.size = filesize;
  cmd.hwaddress = ptarget;
  
  postindyresourcecommand(&cmd,0x11c);

}


void post_type10_indyrescmd_fault_ack_by_host(s32 rsize,s32 wsize,u32 data1,u32 data2,u32 data3)
{
    struct indy_resource_entry_type10 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 0x10;
    cmd.entry.size = 0x20;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    cmd.data1 = data1;
    cmd.data2 = data2;
    cmd.data3 = data3;
    postindyresourcecommand(&cmd,0x20);
}


void post_typeD_indyrescmd_prof_send_filename(u32 rsize,u32 wsize,u8 *ptrstr,u32 size,u8 *hwaddress)
{
    struct indy_resource_entry_typeF cmd;
    
    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 0xd;
    cmd.entry.size = 0x11c;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    strncpy(cmd.strbuffer,ptrstr,0x100);
    cmd.strbuffer[255] = '\0';
    cmd.size = size;
    cmd.hwaddress = hwaddress;
    postindyresourcecommand(&cmd,0x11c);
}


void post_typeE_indyrescmd_prof_recv(s32 readsize,s32 writesize,u32 data)
{
    struct indy_resource_entry_type4 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 0xe;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    postindyresourcecommand(&cmd.entry,0x18);
}


void post_typeB_indyrescmd_host_prof_req(s32 rsize,s32 wsize,char *strptr)
{
    struct indy_resource_entry_typeB res;
    
    res.entry.resourceID = 0x9abf1623;
    res.entry.type = 0xb;
    res.entry.size = 0x414;
    res.entry.readsize = rsize;
    res.entry.writesize = wsize;
    strncpy(res.strbuffer,strptr,0x400);
    res.strbuffer[1023] = '\0';
    postindyresourcecommand(&res,0x414);
}


void post_typeC_indyrescmd_prof_send(s32 readsize,s32 writesize,u32 data)
{
    struct indy_resource_entry_type4 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 0xc;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    postindyresourcecommand(&cmd.entry,0x18);
}


void post_typeA_indyrescmd_app_data_recieved(s32 readsize,s32 writesize,u32 data)
{
    struct indy_resource_entry_type4 cmd;

    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 10;
    cmd.entry.size = 0x18;
    cmd.entry.readsize = readsize;
    cmd.entry.writesize = writesize;
    cmd.data = data;
    postindyresourcecommand(&cmd.entry,0x18);
}


u32 post_indy__res_cmd_initialize_seq(void)
{
    post_type1_indyrescmd_sizenextcmd(0x14,0x14);
    post_type0_indyrescmd_init(0x14,0x14);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_game_data_send(char *strptr)
{
    post_type1_indyrescmd_sizenextcmd(0x114,0x114);
    post_type3_indyrescmd(0x14,0x14,strptr);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_debug_data_recv(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_type4_indyrescmd_data_recieved(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_game_printf_send(char *strptr)
{
    post_type1_indyrescmd_sizenextcmd(0x114,0x114);
    post_type5_indyrescmd_printfsend(0x14,0x14,strptr);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_debug_printf_recv(u32 data1,u32 data2)
{
    post_type1_indyrescmd_sizenextcmd(0x1c,0x1c);
    post_type6_indyrescmd_printfrecieved(0x14,0x14,data1,data2);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_req_filename_size(u8 *filename,u32 size)
{
    post_type1_indyrescmd_sizenextcmd(0x118,0x118);
    post_type7_indyrescmd_log_send(0x14,0x14,filename,size);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_8_2(u32 data1,u32 data2,u32 size2,struct indy_resource_entry *cmd2)
{
    post_type1_indyrescmd_sizenextcmd((size2 + 3 & 0xfffffffc) + 0x20,0x20);
    post_type8_indyrescmd_log_recieved(0x14,0x14,data1,data2,size2,cmd2);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_send_capture_data(char *string, u32 size, struct indy_resource_entry *data)
{
    post_type1_indyrescmd_sizenextcmd((size + 3 & 0xfffffffc) + 0x114,0x114);
    post_type9_indyrescmd_app_command_ready(0x14,0x14,string,size,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_recv_capture_data_success(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_typeA_indyrescmd_app_command_recieved(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_request_ramrom_file(char *strptr,u32 ptarget,u32 filesize)
{
    post_type1_indyrescmd_sizenextcmd(0x11c,0x11c);
    post_typeF_indyrescmd_fault_send(0x14,0x14,strptr,filesize,ptarget);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_10_2(u32 param_1,u32 param_2,u32 param_3)
{
    post_type1_indyrescmd_sizenextcmd(0x20,0x20);
    post_type10_indyrescmd_fault_ack_by_host(0x14,0x14,param_1,param_2,param_3);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_game_prof_sendfile(char *strptr,u8 *phwaddr,u32 size)
{
    post_type1_indyrescmd_sizenextcmd(0x11c,0x11c);
    post_typeD_indyrescmd_prof_send_filename(0x14,0x14,strptr,size,phwaddr);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_host_prof_recv(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_typeE_indyrescmd_prof_recv(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_B_2(char *strptr)
{
    post_type1_indyrescmd_sizenextcmd(0x414,0x414);
    post_typeB_indyrescmd_host_prof_req(0x14,0x14,strptr);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_C_2(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_typeC_indyrescmd_prof_send(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}


u32 post_indyrescmd_1_A_2(u32 data)
{
    post_type1_indyrescmd_sizenextcmd(0x18,0x18);
    post_typeA_indyrescmd_app_data_recieved(0x14,0x14,data);
    post_type2_indyrescmd_cmds_rdy_to_proc(0,0);
    return 1;
}






#ifdef NONMATCHING
void post_indyrescmd_read_command(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indyrescmd_read_command
/* 105A7C 7F0D0F4C 27BDFBC0 */  addiu $sp, $sp, -0x440
/* 105A80 7F0D0F50 27A20040 */  addiu $v0, $sp, 0x40
/* 105A84 7F0D0F54 308F0007 */  andi  $t7, $a0, 7
/* 105A88 7F0D0F58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105A8C 7F0D0F5C AFA40440 */  sw    $a0, 0x440($sp)
/* 105A90 7F0D0F60 00A03025 */  move  $a2, $a1
/* 105A94 7F0D0F64 00401825 */  move  $v1, $v0
/* 105A98 7F0D0F68 11E00031 */  beqz  $t7, .L7F0D1030
/* 105A9C 7F0D0F6C 00403825 */   move  $a3, $v0
/* 105AA0 7F0D0F70 2CA10401 */  sltiu $at, $a1, 0x401
/* 105AA4 7F0D0F74 14200003 */  bnez  $at, .L7F0D0F84
/* 105AA8 7F0D0F78 30580007 */   andi  $t8, $v0, 7
/* 105AAC 7F0D0F7C 10000046 */  b     .L7F0D1098
/* 105AB0 7F0D0F80 00001025 */   move  $v0, $zero
.L7F0D0F84:
/* 105AB4 7F0D0F84 13000003 */  beqz  $t8, .L7F0D0F94
/* 105AB8 7F0D0F88 24C50003 */   addiu $a1, $a2, 3
/* 105ABC 7F0D0F8C 27A30044 */  addiu $v1, $sp, 0x44
/* 105AC0 7F0D0F90 00603825 */  move  $a3, $v1
.L7F0D0F94:
/* 105AC4 7F0D0F94 2401FFFC */  li    $at, -4
/* 105AC8 7F0D0F98 00A1C824 */  and   $t9, $a1, $at
/* 105ACC 7F0D0F9C 03202825 */  move  $a1, $t9
/* 105AD0 7F0D0FA0 00E02025 */  move  $a0, $a3
/* 105AD4 7F0D0FA4 AFA3003C */  sw    $v1, 0x3c($sp)
/* 105AD8 7F0D0FA8 0FC34060 */  jal   indy_buffer_read_command
/* 105ADC 7F0D0FAC AFA60444 */   sw    $a2, 0x444($sp)
/* 105AE0 7F0D0FB0 8FA3003C */  lw    $v1, 0x3c($sp)
/* 105AE4 7F0D0FB4 8FA60444 */  lw    $a2, 0x444($sp)
/* 105AE8 7F0D0FB8 8FA20440 */  lw    $v0, 0x440($sp)
/* 105AEC 7F0D0FBC 3C098005 */  lui   $t1, %hi(indy_status) 
/* 105AF0 7F0D0FC0 00662021 */  addu  $a0, $v1, $a2
/* 105AF4 7F0D0FC4 0064082B */  sltu  $at, $v1, $a0
/* 105AF8 7F0D0FC8 10200007 */  beqz  $at, .L7F0D0FE8
/* 105AFC 7F0D0FCC 00000000 */   nop   
.L7F0D0FD0:
/* 105B00 7F0D0FD0 90680000 */  lbu   $t0, ($v1)
/* 105B04 7F0D0FD4 24630001 */  addiu $v1, $v1, 1
/* 105B08 7F0D0FD8 0064082B */  sltu  $at, $v1, $a0
/* 105B0C 7F0D0FDC 24420001 */  addiu $v0, $v0, 1
/* 105B10 7F0D0FE0 1420FFFB */  bnez  $at, .L7F0D0FD0
/* 105B14 7F0D0FE4 A048FFFF */   sb    $t0, -1($v0)
.L7F0D0FE8:
/* 105B18 7F0D0FE8 8D29EAC4 */  lw    $t1, %lo(indy_status)($t1)
/* 105B1C 7F0D0FEC 312A0010 */  andi  $t2, $t1, 0x10
/* 105B20 7F0D0FF0 1140000D */  beqz  $t2, .L7F0D1028
/* 105B24 7F0D0FF4 00000000 */   nop   
/* 105B28 7F0D0FF8 10C0000B */  beqz  $a2, .L7F0D1028
/* 105B2C 7F0D0FFC 00001025 */   move  $v0, $zero
/* 105B30 7F0D1000 30C40003 */  andi  $a0, $a2, 3
/* 105B34 7F0D1004 10800005 */  beqz  $a0, .L7F0D101C
/* 105B38 7F0D1008 00801825 */   move  $v1, $a0
/* 105B3C 7F0D100C 24420001 */  addiu $v0, $v0, 1
.L7F0D1010:
/* 105B40 7F0D1010 5462FFFF */  bnel  $v1, $v0, .L7F0D1010
/* 105B44 7F0D1014 24420001 */   addiu $v0, $v0, 1
/* 105B48 7F0D1018 10460003 */  beq   $v0, $a2, .L7F0D1028
.L7F0D101C:
/* 105B4C 7F0D101C 24420004 */   addiu $v0, $v0, 4
.L7F0D1020:
/* 105B50 7F0D1020 5446FFFF */  bnel  $v0, $a2, .L7F0D1020
/* 105B54 7F0D1024 24420004 */   addiu $v0, $v0, 4
.L7F0D1028:
/* 105B58 7F0D1028 1000001B */  b     .L7F0D1098
/* 105B5C 7F0D102C 24020001 */   li    $v0, 1
.L7F0D1030:
/* 105B60 7F0D1030 24C50003 */  addiu $a1, $a2, 3
/* 105B64 7F0D1034 2401FFFC */  li    $at, -4
/* 105B68 7F0D1038 00A15824 */  and   $t3, $a1, $at
/* 105B6C 7F0D103C 01602825 */  move  $a1, $t3
/* 105B70 7F0D1040 8FA40440 */  lw    $a0, 0x440($sp)
/* 105B74 7F0D1044 0FC34060 */  jal   indy_buffer_read_command
/* 105B78 7F0D1048 AFA60444 */   sw    $a2, 0x444($sp)
/* 105B7C 7F0D104C 3C0C8005 */  lui   $t4, %hi(indy_status) 
/* 105B80 7F0D1050 8D8CEAC4 */  lw    $t4, %lo(indy_status)($t4)
/* 105B84 7F0D1054 8FA60444 */  lw    $a2, 0x444($sp)
/* 105B88 7F0D1058 318D0010 */  andi  $t5, $t4, 0x10
/* 105B8C 7F0D105C 51A0000E */  beql  $t5, $zero, .L7F0D1098
/* 105B90 7F0D1060 24020001 */   li    $v0, 1
/* 105B94 7F0D1064 10C0000B */  beqz  $a2, .L7F0D1094
/* 105B98 7F0D1068 00001025 */   move  $v0, $zero
/* 105B9C 7F0D106C 30C40003 */  andi  $a0, $a2, 3
/* 105BA0 7F0D1070 10800005 */  beqz  $a0, .L7F0D1088
/* 105BA4 7F0D1074 00801825 */   move  $v1, $a0
/* 105BA8 7F0D1078 24420001 */  addiu $v0, $v0, 1
.L7F0D107C:
/* 105BAC 7F0D107C 5462FFFF */  bnel  $v1, $v0, .L7F0D107C
/* 105BB0 7F0D1080 24420001 */   addiu $v0, $v0, 1
/* 105BB4 7F0D1084 10460003 */  beq   $v0, $a2, .L7F0D1094
.L7F0D1088:
/* 105BB8 7F0D1088 24420004 */   addiu $v0, $v0, 4
.L7F0D108C:
/* 105BBC 7F0D108C 5446FFFF */  bnel  $v0, $a2, .L7F0D108C
/* 105BC0 7F0D1090 24420004 */   addiu $v0, $v0, 4
.L7F0D1094:
/* 105BC4 7F0D1094 24020001 */  li    $v0, 1
.L7F0D1098:
/* 105BC8 7F0D1098 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105BCC 7F0D109C 27BD0440 */  addiu $sp, $sp, 0x440
/* 105BD0 7F0D10A0 03E00008 */  jr    $ra
/* 105BD4 7F0D10A4 00000000 */   nop   
)
#endif






u32 post_indyrescmd_read_2commands(u8 *buffer1,u32 size1,u8 *buffer2,u32 size2)
{
    indy_buffer_read_command(buffer1,size1 + 3 & 0xfffffffc);
    indy_buffer_read_command(buffer2,size2 + 3 & 0xfffffffc);
    return 1;
}


u32 post_indyrescmd_istype1_correctsize(s32 readsize, s32 writesize)
{
    struct indy_resource_entry cmd;
    u32 ret;

    post_indyrescmd_read_command(&cmd, 0x14);
    if (cmd.resourceID != 0x9ABF1623)
    {
        return 0U;
    }
    if (cmd.type != 1)
    {
        return 0U;
    }
    if (cmd.size != 0x14)
    {
        return 0U;
    }
    if ((readsize != 0) && (cmd.readsize != readsize))
    {
        return 0U;
    }
    if (cmd.writesize != writesize)
    {
        return 0U;
    }
    return 1;
}


s32 post_indyrescmd_istype2_correctvalue(s32 readsize, s32 writesize)
{
    struct indy_resource_entry cmd;

    post_indyrescmd_read_command(&cmd, 0x14);
    if (cmd.resourceID != 0x9ABF1623)
    {
        return 0;
    }
    if (cmd.type != 2)
    {
        return 0;
    }
    if (cmd.size != 0x14)
    {
        return 0;
    }
    if (cmd.readsize != readsize)
    {
        return 0;
    }
    if (cmd.writesize != writesize)
    {
        return 0;
    }
    return 1;
}



s32 post_indyrescmd_istype4_correctvalue(s32 readsize, s32 writesize, u32 *response)
{
    struct indy_resource_entry_type4 cmd;

    post_indyrescmd_read_command(&cmd, 0x18);
    if (cmd.entry.resourceID != 0x9ABF1623)
    {
        return 0;
    }
    if (cmd.entry.type != 4)
    {
        return 0;
    }
    if (cmd.entry.size != 0x18)
    {
        return 0;
    }
    if (cmd.entry.readsize != readsize)
    {
        return 0;
    }
    if (cmd.entry.writesize != writesize)
    {
        return 0;
    }
    *response = cmd.data;
    return 1;
}


s32 post_indyrescmd_istype6_correctvalue(s32 readsize, s32 writesize, u32 *response1, u32 *response2)
{
    struct indy_resource_entry_type6 cmd;

    post_indyrescmd_read_command(&cmd, 0x1C);
    if (cmd.entry.resourceID != 0x9ABF1623)
    {
        return 0;
    }
    if (cmd.entry.type != 6)
    {
        return 0;
    }
    if (cmd.entry.size != 0x1C)
    {
        return 0;
    }
    if (cmd.entry.readsize != readsize)
    {
        return 0;
    }
    if (cmd.entry.writesize != writesize)
    {
        return 0;
    }
    *response1 = cmd.data1;
    *response2 = cmd.data2;
    return 1;
}


s32 post_indyrescmd_istype8_correctvalue(s32 readsize, s32 writesize, u32 *response1, u32 *response2, u32 *childsize, u32 *child)
{
    struct indy_resource_entry_type8 cmd;

    post_indyrescmd_read_command(&cmd, 0x20);
    if (cmd.entry.resourceID != 0x9ABF1623)
    {
        return 0;
    }
    if (cmd.entry.type != 8)
    {
        return 0;
    }
    if (cmd.entry.size != (((cmd.size + 3) & ~3) + 0x20))
    {
        return 0;
    }
    if (cmd.entry.readsize != readsize)
    {
        return 0;
    }
    if (cmd.entry.writesize != writesize)
    {
        return 0;
    }
    *response1 = cmd.data1;
    *response2 = cmd.data2;
    *childsize = cmd.size;
    post_indyrescmd_read_command(child, (cmd.size + 3) & ~3);
    return 1;
}


s32 post_indyrescmd_istypeA_correctvalue(s32 readsize, s32 writesize, u32 *response)
{
    struct indy_resource_entry_type4 cmd;

    post_indyrescmd_read_command(&cmd, 0x18);
    if (cmd.entry.resourceID != 0x9ABF1623)
    {
        return 0;
    }
    if (cmd.entry.type != 0xA)
    {
        return 0;
    }
    if (cmd.entry.size != 0x18)
    {
        return 0;
    }
    if (cmd.entry.readsize != readsize)
    {
        return 0;
    }
    if (cmd.entry.writesize != writesize)
    {
        return 0;
    }
    *response = cmd.data;
    return 1;
}


s32 post_indyrescmd_istype10_correctvalue(s32 readsize, s32 writesize, u32 *data1, u32 *data2, u32 *data3)
{
    struct indy_resource_entry_type10 cmd;

    post_indyrescmd_read_command(&cmd, 0x20);
    if (cmd.entry.resourceID != 0x9ABF1623)
    {
        return 0;
    }
    if (cmd.entry.type != 0x10)
    {
        return 0;
    }
    if (cmd.entry.size != 0x20)
    {
        return 0;
    }
    if (cmd.entry.readsize != readsize)
    {
        return 0;
    }
    if (cmd.entry.writesize != writesize)
    {
        return 0;
    }
    *data1 = cmd.data1;
    *data2 = cmd.data2;
    *data3 = cmd.data3;
    return 1;
}


s32 post_indyrescmd_istypeE_correctvalue(s32 readsize, s32 writesize, u32 *response)
{
    struct indy_resource_entry_type4 cmd;

    post_indyrescmd_read_command(&cmd, 0x18);
    if (cmd.entry.resourceID != 0x9ABF1623)
    {
        return FALSE;
    }
    if (cmd.entry.type != 0xE)
    {
        return FALSE;
    }
    if (cmd.entry.size != 0x18)
    {
        return FALSE;
    }
    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }
    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }
    *response = cmd.data;
    return TRUE;
}


s32 post_indyrescmd_istypeC_correctvalue(s32 readsize, s32 writesize, u32 *response)
{
    struct indy_resource_entry_type4 cmd;

    post_indyrescmd_read_command(&cmd, 0x18);
    if (cmd.entry.resourceID != 0x9ABF1623)
    {
        return FALSE;
    }
    if (cmd.entry.type != 0xC)
    {
        return FALSE;
    }
    if (cmd.entry.size != 0x18)
    {
        return FALSE;
    }
    if (cmd.entry.readsize != readsize)
    {
        return FALSE;
    }
    if (cmd.entry.writesize != writesize)
    {
        return FALSE;
    }
    *response = cmd.data;
    return TRUE;
}


s32 response_indyrescmd_1_4_2(u8 *response)
{
    post_indyrescmd_istype1_correctsize(0x18,0x18);
    post_indyrescmd_istype4_correctvalue(0x14,0x14,response);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


s32 response_indyrescmd_1_6_2(u8 *response1,u8 *response2)
{
    post_indyrescmd_istype1_correctsize(0x1c,0x1c);
    post_indyrescmd_istype6_correctvalue(0x14,0x14,response1,response2);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


s32 response_indyrescmd_1_8_2(u8 *response1,u8 *response2,u32 childsize,u8 *child)
{
    post_indyrescmd_istype1_correctsize(0,0x20);
    post_indyrescmd_istype8_correctvalue(0x14,0x14,response1,response2,childsize,child);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


s32 response_indyrescmd_1_A_2(u8 *param_1)
{
    post_indyrescmd_istype1_correctsize(0x18,0x18);
    post_indyrescmd_istypeA_correctvalue(0x14,0x14,param_1);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


s32 response_indyrescmd_1_10_2(u32 *param_1,u32 *param_2,u32 *param_3)
{
    post_indyrescmd_istype1_correctsize(0x20,0x20);
    post_indyrescmd_istype10_correctvalue(0x14,0x14,param_1,param_2,param_3);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


s32 response_indyrescmd_1_E_2(u8 *response)
{
    post_indyrescmd_istype1_correctsize(0x18,0x18);
    post_indyrescmd_istypeE_correctvalue(0x14,0x14,response);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


s32 response_indyrescmd_1_C_2(u8 *response)
{
    post_indyrescmd_istype1_correctsize(0x18,0x18);
    post_indyrescmd_istypeC_correctvalue(0x14,0x14,response);
    post_indyrescmd_istype2_correctvalue(0,0);
    return 1;
}


s32 response_indyrescmd_curr_matches_expected(s32 readsize, s32 writesize)
{
    struct indy_resource_entry cmd;

    post_indyrescmd_read_command(&cmd, 0x14);
    if (cmd.resourceID != 0x9ABF1623)
    {
        return 0U;
    }
    if ((readsize != 0) && (cmd.readsize != readsize))
    {
        return 0U;
    }
    if ((writesize != 0) && (cmd.writesize != writesize))
    {
        return 0U;
    }
    return 1U;
}

