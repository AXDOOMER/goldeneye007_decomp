//FIXME my c code is modtly copy/paste from mips_to_c
#include "ultra64.h"
#include "bondgame.h"
#include "ramrom.h"
#include "deb.h"

/* bss */
char dword_CODE_bss_80060890[0x400];
char thread_video_manager_debugthread[0x6B0];
char tlbStack[0x2300];
OSMesgQueue tlbMesgQ;
u32 tlbMesgBuf;
OSThread *ptr_tlbthread_maybe;
u32 dword_CODE_bss_80063660;
u32 *current_indy_read_buf_resourceID;
u32 *ptr_indy_read_buf_string1;
u32 *ptr_indy_read_buf_string2;
char indy_read_buffer[0x60];


/* data */
u32 D_800232E0[] = {0, 0};
u32 debug_notice_list[] = {0, 0, 0, 0};
u32 debug_notice_list_data[] = {&dword_CODE_bss_80060890, 0};






#ifdef NONMATCHING
void *return_match_in_debug_notice_list(s32 arg0)
{
    void *temp_s0;
    void *phi_s0;

    phi_s0 = debug_notice_list;
    if (debug_notice_list != 0)
    {
loop_1:
        if (something_with_strings_0(phi_s0->unk8, arg0) == 0)
        {
            return phi_s0;
        }
        temp_s0 = phi_s0->unk0;
        phi_s0 = temp_s0;
        if (temp_s0 != 0)
        {
            goto loop_1;
        }
    }
    return NULL;
}
#else
GLOBAL_ASM(
.text
glabel return_match_in_debug_notice_list
/* 005920 70004D20 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 005924 70004D24 AFB00014 */  sw    $s0, 0x14($sp)
/* 005928 70004D28 3C108002 */  lui   $s0, %hi(debug_notice_list) # $s0, 0x8002
/* 00592C 70004D2C 8E1032E8 */  lw    $s0, %lo(debug_notice_list)($s0)
/* 005930 70004D30 AFB10018 */  sw    $s1, 0x18($sp)
/* 005934 70004D34 00808825 */  move  $s1, $a0
/* 005938 70004D38 1200000B */  beqz  $s0, .L70004D68
/* 00593C 70004D3C AFBF001C */   sw    $ra, 0x1c($sp)
/* 005940 70004D40 8E040008 */  lw    $a0, 8($s0)
.L70004D44:
/* 005944 70004D44 0C002A13 */  jal   something_with_strings_0
/* 005948 70004D48 02202825 */   move  $a1, $s1
/* 00594C 70004D4C 54400004 */  bnezl $v0, .L70004D60
/* 005950 70004D50 8E100000 */   lw    $s0, ($s0)
/* 005954 70004D54 10000005 */  b     .L70004D6C
/* 005958 70004D58 02001025 */   move  $v0, $s0
/* 00595C 70004D5C 8E100000 */  lw    $s0, ($s0)
.L70004D60:
/* 005960 70004D60 5600FFF8 */  bnezl $s0, .L70004D44
/* 005964 70004D64 8E040008 */   lw    $a0, 8($s0)
.L70004D68:
/* 005968 70004D68 00001025 */  move  $v0, $zero
.L70004D6C:
/* 00596C 70004D6C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 005970 70004D70 8FB00014 */  lw    $s0, 0x14($sp)
/* 005974 70004D74 8FB10018 */  lw    $s1, 0x18($sp)
/* 005978 70004D78 03E00008 */  jr    $ra
/* 00597C 70004D7C 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif

#ifdef NONMATCHING
u32 get_entry_of_size_in_debug_notice_list(s32 arg0)
{
    u32 temp_v0;

    temp_v0 = (debug_notice_list_data + arg0);
    if (&thread_video_manager_debugthread >= temp_v0)
    {
        debug_notice_list_data = temp_v0;
        return debug_notice_list_data;
    }
    debug_notice_list_data = (u32) (temp_v0 - arg0);
    return allocate_bytes_in_bank(6);
}
#else
GLOBAL_ASM(
.text
glabel get_entry_of_size_in_debug_notice_list
/* 005980 70004D80 3C028002 */  lui   $v0, %hi(debug_notice_list_data) # $v0, 0x8002
/* 005984 70004D84 8C4232F8 */  lw    $v0, %lo(debug_notice_list_data)($v0)
/* 005988 70004D88 3C0E8006 */  lui   $t6, %hi(thread_video_manager_debugthread) # $t6, 0x8006
/* 00598C 70004D8C 25CE0C90 */  addiu $t6, %lo(thread_video_manager_debugthread) # addiu $t6, $t6, 0xc90
/* 005990 70004D90 00401825 */  move  $v1, $v0
/* 005994 70004D94 00441021 */  addu  $v0, $v0, $a0
/* 005998 70004D98 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00599C 70004D9C 01C2082B */  sltu  $at, $t6, $v0
/* 0059A0 70004DA0 10200008 */  beqz  $at, .L70004DC4
/* 0059A4 70004DA4 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0059A8 70004DA8 00441023 */  subu  $v0, $v0, $a0
/* 0059AC 70004DAC 3C018002 */  lui   $at, %hi(debug_notice_list_data) # $at, 0x8002
/* 0059B0 70004DB0 AC2232F8 */  sw    $v0, %lo(debug_notice_list_data)($at)
/* 0059B4 70004DB4 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0059B8 70004DB8 24050006 */   li    $a1, 6
/* 0059BC 70004DBC 10000005 */  b     .L70004DD4
/* 0059C0 70004DC0 8FBF0014 */   lw    $ra, 0x14($sp)
.L70004DC4:
/* 0059C4 70004DC4 3C018002 */  lui   $at, %hi(debug_notice_list_data) # $at, 0x8002
/* 0059C8 70004DC8 AC2232F8 */  sw    $v0, %lo(debug_notice_list_data)($at)
/* 0059CC 70004DCC 00601025 */  move  $v0, $v1
/* 0059D0 70004DD0 8FBF0014 */  lw    $ra, 0x14($sp)
.L70004DD4:
/* 0059D4 70004DD4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0059D8 70004DD8 03E00008 */  jr    $ra
/* 0059DC 70004DDC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void add_new_entry_to_debug_notice_list(s32 arg0, s32 arg1)
{
    ? temp_ret;

    temp_ret = get_entry_of_size_in_debug_notice_list(0x10);
    *temp_ret = (s32) debug_notice_list;
    temp_ret->unk4 = arg1;
    temp_ret->unk8 = arg0;
    debug_notice_list = temp_ret;
}
#else
GLOBAL_ASM(
.text
glabel add_new_entry_to_debug_notice_list
/* 0059E0 70004DE0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0059E4 70004DE4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0059E8 70004DE8 AFA40018 */  sw    $a0, 0x18($sp)
/* 0059EC 70004DEC AFA5001C */  sw    $a1, 0x1c($sp)
/* 0059F0 70004DF0 0C001360 */  jal   get_entry_of_size_in_debug_notice_list
/* 0059F4 70004DF4 24040010 */   li    $a0, 16
/* 0059F8 70004DF8 3C038002 */  lui   $v1, %hi(debug_notice_list) # $v1, 0x8002
/* 0059FC 70004DFC 246332E8 */  addiu $v1, %lo(debug_notice_list) # addiu $v1, $v1, 0x32e8
/* 005A00 70004E00 8C6E0000 */  lw    $t6, ($v1)
/* 005A04 70004E04 AC4E0000 */  sw    $t6, ($v0)
/* 005A08 70004E08 8FAF001C */  lw    $t7, 0x1c($sp)
/* 005A0C 70004E0C AC4F0004 */  sw    $t7, 4($v0)
/* 005A10 70004E10 8FB80018 */  lw    $t8, 0x18($sp)
/* 005A14 70004E14 AC580008 */  sw    $t8, 8($v0)
/* 005A18 70004E18 8FBF0014 */  lw    $ra, 0x14($sp)
/* 005A1C 70004E1C AC620000 */  sw    $v0, ($v1)
/* 005A20 70004E20 27BD0018 */  addiu $sp, $sp, 0x18
/* 005A24 70004E24 03E00008 */  jr    $ra
/* 005A28 70004E28 00000000 */   nop   
)
#endif





void add_debug_notice_deb_c_debug(void) {
    get_ptr_debug_notice_list_entry(&D_800232E0, "deb_c_debug");
    init_tlb();
}






#ifdef NONMATCHING
void get_ptr_debug_notice_list_entry(s32 arg0, s32 arg1)
{
    if (return_match_in_debug_notice_list(arg1) == 0)
    {
        add_new_entry_to_debug_notice_list(arg1, arg0);
    }
}
#else
GLOBAL_ASM(
.text
glabel get_ptr_debug_notice_list_entry
/* 005A60 70004E60 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 005A64 70004E64 AFBF0014 */  sw    $ra, 0x14($sp)
/* 005A68 70004E68 AFA40018 */  sw    $a0, 0x18($sp)
/* 005A6C 70004E6C AFA5001C */  sw    $a1, 0x1c($sp)
/* 005A70 70004E70 0C001348 */  jal   return_match_in_debug_notice_list
/* 005A74 70004E74 00A02025 */   move  $a0, $a1
/* 005A78 70004E78 14400003 */  bnez  $v0, .L70004E88
/* 005A7C 70004E7C 8FA4001C */   lw    $a0, 0x1c($sp)
/* 005A80 70004E80 0C001378 */  jal   add_new_entry_to_debug_notice_list
/* 005A84 70004E84 8FA50018 */   lw    $a1, 0x18($sp)
.L70004E88:
/* 005A88 70004E88 8FBF0014 */  lw    $ra, 0x14($sp)
/* 005A8C 70004E8C 27BD0018 */  addiu $sp, $sp, 0x18
/* 005A90 70004E90 03E00008 */  jr    $ra
/* 005A94 70004E94 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void *scan_debug_notice_list_till_NULL(void)
{
    void *temp_v0;
    void *phi_v0;

    phi_v0 = debug_notice_list;
    if (debug_notice_list != 0)
    {
loop_1:
        temp_v0 = *phi_v0;
        phi_v0 = temp_v0;
        if (temp_v0 != 0)
        {
            goto loop_1;
        }
    }
    return debug_notice_list;
}
#else
GLOBAL_ASM(
.text
glabel scan_debug_notice_list_till_NULL
/* 005A98 70004E98 3C028002 */  lui   $v0, %hi(debug_notice_list) # $v0, 0x8002
/* 005A9C 70004E9C 8C4232E8 */  lw    $v0, %lo(debug_notice_list)($v0)
/* 005AA0 70004EA0 10400004 */  beqz  $v0, .L70004EB4
/* 005AA4 70004EA4 00000000 */   nop   
/* 005AA8 70004EA8 8C420000 */  lw    $v0, ($v0)
.L70004EAC:
/* 005AAC 70004EAC 5440FFFF */  bnezl $v0, .L70004EAC
/* 005AB0 70004EB0 8C420000 */   lw    $v0, ($v0)
.L70004EB4:
/* 005AB4 70004EB4 03E00008 */  jr    $ra
/* 005AB8 70004EB8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void debug_stubbed_70004EBC(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_stubbed
/* 005ABC 70004EBC 03E00008 */  jr    $ra
/* 005AC0 70004EC0 00000000 */   nop   
)
#endif




#ifdef NONMATCHING
void debug_removed(s32 arg0, s32 arg1, s32 arg2) {

}
#else
GLOBAL_ASM(
.text
glabel debug_removed
/* 005AC4 70004EC4 AFA40000 */  sw    $a0, ($sp)
/* 005AC8 70004EC8 AFA50004 */  sw    $a1, 4($sp)
/* 005ACC 70004ECC 03E00008 */  jr    $ra
/* 005AD0 70004ED0 AFA60008 */   sw    $a2, 8($sp)
/* 005AD4 70004ED4 00000000 */  nop
/* 005AD8 70004ED8 00000000 */  nop
/* 005ADC 70004EDC 00000000 */  nop
)
#endif




#ifdef NONMATCHING
void init_tlb(void) {
    set_video_buffer_pointers();
    osCreateMesgQueue(&tlbMesgQ, &tlbMesgBuf, 1);
    osCreateThread(&thread_video_manager_debugthread, 5, &thread5_tlb, 0, &tlbStack, 0x28);
    osStartThread(&thread_video_manager_debugthread);
}
#else
GLOBAL_ASM(
.text
glabel init_tlb
/* 005AE0 70004EE0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 005AE4 70004EE4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 005AE8 70004EE8 0C001669 */  jal   set_video_buffer_pointers
/* 005AEC 70004EEC 00000000 */   nop   
/* 005AF0 70004EF0 3C048006 */  lui   $a0, %hi(tlbMesgQ) # $a0, 0x8006
/* 005AF4 70004EF4 3C058006 */  lui   $a1, %hi(tlbMesgBuf) # $a1, 0x8006
/* 005AF8 70004EF8 24A53658 */  addiu $a1, %lo(tlbMesgBuf) # addiu $a1, $a1, 0x3658
/* 005AFC 70004EFC 24843640 */  addiu $a0, %lo(tlbMesgQ) # addiu $a0, $a0, 0x3640
/* 005B00 70004F00 0C0035B4 */  jal   osCreateMesgQueue
/* 005B04 70004F04 24060001 */   li    $a2, 1
/* 005B08 70004F08 3C0E8006 */  lui   $t6, %hi(tlbStack) # $t6, 0x8006
/* 005B0C 70004F0C 25CE1340 */  addiu $t6, %lo(tlbStack) # addiu $t6, $t6, 0x1340
/* 005B10 70004F10 3C048006 */  lui   $a0, %hi(thread_video_manager_debugthread) # $a0, 0x8006
/* 005B14 70004F14 3C067000 */  lui   $a2, %hi(thread5_tlb) # $a2, 0x7000
/* 005B18 70004F18 240F0028 */  li    $t7, 40
/* 005B1C 70004F1C AFAF0014 */  sw    $t7, 0x14($sp)
/* 005B20 70004F20 24C64F54 */  addiu $a2, %lo(thread5_tlb) # addiu $a2, $a2, 0x4f54
/* 005B24 70004F24 24840C90 */  addiu $a0, %lo(thread_video_manager_debugthread) # addiu $a0, $a0, 0xc90
/* 005B28 70004F28 AFAE0010 */  sw    $t6, 0x10($sp)
/* 005B2C 70004F2C 24050005 */  li    $a1, 5
/* 005B30 70004F30 0C00350C */  jal   osCreateThread
/* 005B34 70004F34 00003825 */   move  $a3, $zero
/* 005B38 70004F38 3C048006 */  lui   $a0, %hi(thread_video_manager_debugthread) # $a0, 0x8006
/* 005B3C 70004F3C 0C003560 */  jal   osStartThread
/* 005B40 70004F40 24840C90 */   addiu $a0, %lo(thread_video_manager_debugthread) # addiu $a0, $a0, 0xc90
/* 005B44 70004F44 8FBF001C */  lw    $ra, 0x1c($sp)
/* 005B48 70004F48 27BD0020 */  addiu $sp, $sp, 0x20
/* 005B4C 70004F4C 03E00008 */  jr    $ra
/* 005B50 70004F50 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void thread5_tlb(void) {

}
#else
GLOBAL_ASM(
.text
glabel thread5_tlb
/* 005B54 70004F54 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 005B58 70004F58 AFB70030 */  sw    $s7, 0x30($sp)
/* 005B5C 70004F5C 3C178006 */  lui   $s7, %hi(tlbMesgQ) # $s7, 0x8006
/* 005B60 70004F60 26F73640 */  addiu $s7, %lo(tlbMesgQ) # addiu $s7, $s7, 0x3640
/* 005B64 70004F64 AFBF0034 */  sw    $ra, 0x34($sp)
/* 005B68 70004F68 AFA40040 */  sw    $a0, 0x40($sp)
/* 005B6C 70004F6C AFB6002C */  sw    $s6, 0x2c($sp)
/* 005B70 70004F70 AFB50028 */  sw    $s5, 0x28($sp)
/* 005B74 70004F74 AFB40024 */  sw    $s4, 0x24($sp)
/* 005B78 70004F78 AFB30020 */  sw    $s3, 0x20($sp)
/* 005B7C 70004F7C AFB2001C */  sw    $s2, 0x1c($sp)
/* 005B80 70004F80 AFB10018 */  sw    $s1, 0x18($sp)
/* 005B84 70004F84 AFB00014 */  sw    $s0, 0x14($sp)
/* 005B88 70004F88 AFA0003C */  sw    $zero, 0x3c($sp)
/* 005B8C 70004F8C 2404000C */  li    $a0, 12
/* 005B90 70004F90 02E02825 */  move  $a1, $s7
/* 005B94 70004F94 0C003714 */  jal   osSetEventMesg
/* 005B98 70004F98 24060010 */   li    $a2, 16
/* 005B9C 70004F9C 3C018006 */  lui   $at, %hi(dword_CODE_bss_80063660) # $at, 0x8006
/* 005BA0 70004FA0 3C168002 */  lui   $s6, %hi(__osRunQueue) # $s6, 0x8002
/* 005BA4 70004FA4 AC203660 */  sw    $zero, %lo(dword_CODE_bss_80063660)($at)
/* 005BA8 70004FA8 26D67728 */  addiu $s6, %lo(__osRunQueue) # addiu $s6, $s6, 0x7728
/* 005BAC 70004FAC 2415000A */  li    $s5, 10
/* 005BB0 70004FB0 3C14FFC0 */  lui   $s4, 0xffc0
/* 005BB4 70004FB4 3C137F00 */  lui   $s3, 0x7f00
/* 005BB8 70004FB8 24120008 */  li    $s2, 8
/* 005BBC 70004FBC 27B1003C */  addiu $s1, $sp, 0x3c
.L70004FC0:
/* 005BC0 70004FC0 02E02025 */  move  $a0, $s7
.L70004FC4:
/* 005BC4 70004FC4 02202825 */  move  $a1, $s1
/* 005BC8 70004FC8 0C003774 */  jal   osRecvMesg
/* 005BCC 70004FCC 24060001 */   li    $a2, 1
/* 005BD0 70004FD0 0C00374C */  jal   osSetIntMask
/* 005BD4 70004FD4 24040001 */   li    $a0, 1
/* 005BD8 70004FD8 0C004060 */  jal   ultra_70010180
/* 005BDC 70004FDC 00408025 */   move  $s0, $v0
/* 005BE0 70004FE0 3C018006 */  lui   $at, %hi(ptr_tlbthread_maybe) # $at, 0x8006
/* 005BE4 70004FE4 1040FFF6 */  beqz  $v0, .L70004FC0
/* 005BE8 70004FE8 AC22365C */   sw    $v0, %lo(ptr_tlbthread_maybe)($at)
/* 005BEC 70004FEC 8C4E0120 */  lw    $t6, 0x120($v0)
/* 005BF0 70004FF0 3C088006 */  lui   $t0, %hi(ptr_tlbthread_maybe) # $t0, 0x8006
/* 005BF4 70004FF4 31CF007C */  andi  $t7, $t6, 0x7c
/* 005BF8 70004FF8 164F0018 */  bne   $s2, $t7, .L7000505C
/* 005BFC 70004FFC 00000000 */   nop   
/* 005C00 70005000 8C580124 */  lw    $t8, 0x124($v0)
/* 005C04 70005004 0314C824 */  and   $t9, $t8, $s4
/* 005C08 70005008 16790014 */  bne   $s3, $t9, .L7000505C
/* 005C0C 7000500C 00000000 */   nop   
/* 005C10 70005010 8D08365C */  lw    $t0, %lo(ptr_tlbthread_maybe)($t0)
/* 005C14 70005014 0C000676 */  jal   translate_load_rom_from_TLBaddress
/* 005C18 70005018 8D040124 */   lw    $a0, 0x124($t0)
/* 005C1C 7000501C 3C098006 */  lui   $t1, %hi(ptr_tlbthread_maybe) # $t1, 0x8006
/* 005C20 70005020 8D29365C */  lw    $t1, %lo(ptr_tlbthread_maybe)($t1)
/* 005C24 70005024 3C0A8006 */  lui   $t2, %hi(ptr_tlbthread_maybe) # $t2, 0x8006
/* 005C28 70005028 3C058006 */  lui   $a1, %hi(ptr_tlbthread_maybe) # $a1, 0x8006
/* 005C2C 7000502C A5350010 */  sh    $s5, 0x10($t1)
/* 005C30 70005030 8D4A365C */  lw    $t2, %lo(ptr_tlbthread_maybe)($t2)
/* 005C34 70005034 02C02025 */  move  $a0, $s6
/* 005C38 70005038 A5400012 */  sh    $zero, 0x12($t2)
/* 005C3C 7000503C 0C00422B */  jal   __osEnqueueThread
/* 005C40 70005040 8CA5365C */   lw    $a1, %lo(ptr_tlbthread_maybe)($a1)
/* 005C44 70005044 0C00374C */  jal   osSetIntMask
/* 005C48 70005048 02002025 */   move  $a0, $s0
/* 005C4C 7000504C 0C0042B4 */  jal   osYieldThread
/* 005C50 70005050 00000000 */   nop   
/* 005C54 70005054 1000FFDB */  b     .L70004FC4
/* 005C58 70005058 02E02025 */   move  $a0, $s7
.L7000505C:
/* 005C5C 7000505C 0C00374C */  jal   osSetIntMask
/* 005C60 70005060 02002025 */   move  $a0, $s0
.L70005064:
/* 005C64 70005064 1000FFFF */  b     .L70005064
/* 005C68 70005068 00000000 */   nop   
/* 005C6C 7000506C 00000000 */  nop   
/* 005C70 70005070 00000000 */  nop   
/* 005C74 70005074 00000000 */  nop   
/* 005C78 70005078 00000000 */  nop   
/* 005C7C 7000507C 00000000 */  nop   
/* 005C80 70005080 8FBF0034 */  lw    $ra, 0x34($sp)
/* 005C84 70005084 8FB00014 */  lw    $s0, 0x14($sp)
/* 005C88 70005088 8FB10018 */  lw    $s1, 0x18($sp)
/* 005C8C 7000508C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 005C90 70005090 8FB30020 */  lw    $s3, 0x20($sp)
/* 005C94 70005094 8FB40024 */  lw    $s4, 0x24($sp)
/* 005C98 70005098 8FB50028 */  lw    $s5, 0x28($sp)
/* 005C9C 7000509C 8FB6002C */  lw    $s6, 0x2c($sp)
/* 005CA0 700050A0 8FB70030 */  lw    $s7, 0x30($sp)
/* 005CA4 700050A4 03E00008 */  jr    $ra
/* 005CA8 700050A8 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

#ifdef NONMATCHING
void debug_related_8(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_related_8
/* 005CAC 700050AC 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 005CB0 700050B0 AFA40010 */  sw    $a0, 0x10($sp)
/* 005CB4 700050B4 AFB1000C */  sw    $s1, 0xc($sp)
/* 005CB8 700050B8 AFB00008 */  sw    $s0, 8($sp)
/* 005CBC 700050BC 00C01825 */  move  $v1, $a2
/* 005CC0 700050C0 00001025 */  move  $v0, $zero
/* 005CC4 700050C4 00004025 */  move  $t0, $zero
/* 005CC8 700050C8 24040020 */  li    $a0, 32
/* 005CCC 700050CC 00004825 */  move  $t1, $zero
/* 005CD0 700050D0 00E05025 */  move  $t2, $a3
.L700050D4:
/* 005CD4 700050D4 25290004 */  addiu $t1, $t1, 4
/* 005CD8 700050D8 AD400000 */  sw    $zero, ($t2)
/* 005CDC 700050DC AD400004 */  sw    $zero, 4($t2)
/* 005CE0 700050E0 AD400008 */  sw    $zero, 8($t2)
/* 005CE4 700050E4 AD40000C */  sw    $zero, 0xc($t2)
/* 005CE8 700050E8 1524FFFA */  bne   $t1, $a0, .L700050D4
/* 005CEC 700050EC 254A0010 */   addiu $t2, $t2, 0x10
/* 005CF0 700050F0 8FA40010 */  lw    $a0, 0x10($sp)
/* 005CF4 700050F4 3C1103E0 */  lui   $s1, (0x03E00008 >> 16) # lui $s1, 0x3e0
/* 005CF8 700050F8 36310008 */  ori   $s1, (0x03E00008 & 0xFFFF) # ori $s1, $s1, 8
/* 005CFC 700050FC 0085082B */  sltu  $at, $a0, $a1
/* 005D00 70005100 1420002D */  bnez  $at, .L700051B8
/* 005D04 70005104 2410001F */   li    $s0, 31
/* 005D08 70005108 3C0DFFE0 */  lui   $t5, 0xffe0
/* 005D0C 7000510C 3C0CAFA0 */  lui   $t4, 0xafa0
/* 005D10 70005110 3C0BFFFF */  lui   $t3, 0xffff
/* 005D14 70005114 3C0A27BD */  lui   $t2, 0x27bd
/* 005D18 70005118 8C890000 */  lw    $t1, ($a0)
.L7000511C:
/* 005D1C 7000511C 2484FFFC */  addiu $a0, $a0, -4
/* 005D20 70005120 0085082B */  sltu  $at, $a0, $a1
/* 005D24 70005124 012B7824 */  and   $t7, $t1, $t3
/* 005D28 70005128 154F000B */  bne   $t2, $t7, .L70005158
/* 005D2C 7000512C 012DC024 */   and   $t8, $t1, $t5
/* 005D30 70005130 0009C400 */  sll   $t8, $t1, 0x10
/* 005D34 70005134 0018CC03 */  sra   $t9, $t8, 0x10
/* 005D38 70005138 1F20001F */  bgtz  $t9, .L700051B8
/* 005D3C 7000513C 24020001 */   li    $v0, 1
/* 005D40 70005140 00197083 */  sra   $t6, $t9, 2
/* 005D44 70005144 000E7880 */  sll   $t7, $t6, 2
/* 005D48 70005148 11000019 */  beqz  $t0, .L700051B0
/* 005D4C 7000514C 006F1823 */   subu  $v1, $v1, $t7
/* 005D50 70005150 10000019 */  b     .L700051B8
/* 005D54 70005154 00000000 */   nop   
.L70005158:
/* 005D58 70005158 15980013 */  bne   $t4, $t8, .L700051A8
/* 005D5C 7000515C 00093402 */   srl   $a2, $t1, 0x10
/* 005D60 70005160 30D9001F */  andi  $t9, $a2, 0x1f
/* 005D64 70005164 00097C00 */  sll   $t7, $t1, 0x10
/* 005D68 70005168 000FC403 */  sra   $t8, $t7, 0x10
/* 005D6C 7000516C 03203025 */  move  $a2, $t9
/* 005D70 70005170 0018C883 */  sra   $t9, $t8, 2
/* 005D74 70005174 00197080 */  sll   $t6, $t9, 2
/* 005D78 70005178 0006C080 */  sll   $t8, $a2, 2
/* 005D7C 7000517C 00F8C821 */  addu  $t9, $a3, $t8
/* 005D80 70005180 01C37821 */  addu  $t7, $t6, $v1
/* 005D84 70005184 16060002 */  bne   $s0, $a2, .L70005190
/* 005D88 70005188 AF2F0000 */   sw    $t7, ($t9)
/* 005D8C 7000518C 24080001 */  li    $t0, 1
.L70005190:
/* 005D90 70005190 10400007 */  beqz  $v0, .L700051B0
/* 005D94 70005194 00000000 */   nop   
/* 005D98 70005198 11000005 */  beqz  $t0, .L700051B0
/* 005D9C 7000519C 00000000 */   nop   
/* 005DA0 700051A0 10000005 */  b     .L700051B8
/* 005DA4 700051A4 00000000 */   nop   
.L700051A8:
/* 005DA8 700051A8 11310003 */  beq   $t1, $s1, .L700051B8
/* 005DAC 700051AC 00000000 */   nop   
.L700051B0:
/* 005DB0 700051B0 5020FFDA */  beql  $at, $zero, .L7000511C
/* 005DB4 700051B4 8C890000 */   lw    $t1, ($a0)
.L700051B8:
/* 005DB8 700051B8 10400005 */  beqz  $v0, .L700051D0
/* 005DBC 700051BC 8FB00008 */   lw    $s0, 8($sp)
/* 005DC0 700051C0 51000004 */  beql  $t0, $zero, .L700051D4
/* 005DC4 700051C4 00001025 */   move  $v0, $zero
/* 005DC8 700051C8 10000002 */  b     .L700051D4
/* 005DCC 700051CC 00601025 */   move  $v0, $v1
.L700051D0:
/* 005DD0 700051D0 00001025 */  move  $v0, $zero
.L700051D4:
/* 005DD4 700051D4 8FB1000C */  lw    $s1, 0xc($sp)
/* 005DD8 700051D8 03E00008 */  jr    $ra
/* 005DDC 700051DC 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif

#ifdef NONMATCHING
void was_opcode_In_70000450_70020D90(u32 arg0)
{
    if ((arg0 & 3) == 0)
    {
        if (arg0 >= &_codeSegmentStart)
        {
            if (&_codeSegmentEnd >= arg0)
            {
                if ((arg0->unk-8 & 0xfc00003c) == 9)
                {
                    return 1;
                }
                if ((arg0->unk-8 & 0xfc000000) == 0xc000000)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel was_opcode_In_70000450_70020D90
/* 005DE0 700051E0 308E0003 */  andi  $t6, $a0, 3
/* 005DE4 700051E4 15C00019 */  bnez  $t6, .L7000524C
/* 005DE8 700051E8 3C0F7000 */   lui   $t7, %hi(_codeSegmentStart) # $t7, 0x7000
/* 005DEC 700051EC 25EF0450 */  addiu $t7, %lo(_codeSegmentStart) # addiu $t7, $t7, 0x450
/* 005DF0 700051F0 008F082B */  sltu  $at, $a0, $t7
/* 005DF4 700051F4 14200015 */  bnez  $at, .L7000524C
/* 005DF8 700051F8 3C187002 */   lui   $t8, %hi(_codeSegmentEnd) # $t8, 0x7002
/* 005DFC 700051FC 27180D90 */  addiu $t8, %lo(_codeSegmentEnd) # addiu $t8, $t8, 0xd90
/* 005E00 70005200 0304082B */  sltu  $at, $t8, $a0
/* 005E04 70005204 54200012 */  bnezl $at, .L70005250
/* 005E08 70005208 00001025 */   move  $v0, $zero
/* 005E0C 7000520C 8C82FFF8 */  lw    $v0, -8($a0)
/* 005E10 70005210 3C01FC00 */  lui   $at, (0xFC00003C >> 16) # lui $at, 0xfc00
/* 005E14 70005214 3421003C */  ori   $at, (0xFC00003C & 0xFFFF) # ori $at, $at, 0x3c
/* 005E18 70005218 0041C824 */  and   $t9, $v0, $at
/* 005E1C 7000521C 24010009 */  li    $at, 9
/* 005E20 70005220 57210004 */  bnel  $t9, $at, .L70005234
/* 005E24 70005224 3C01FC00 */   lui   $at, 0xfc00
/* 005E28 70005228 03E00008 */  jr    $ra
/* 005E2C 7000522C 24020001 */   li    $v0, 1

/* 005E30 70005230 3C01FC00 */  lui   $at, 0xfc00
.L70005234:
/* 005E34 70005234 00414024 */  and   $t0, $v0, $at
/* 005E38 70005238 3C010C00 */  lui   $at, 0xc00
/* 005E3C 7000523C 55010004 */  bnel  $t0, $at, .L70005250
/* 005E40 70005240 00001025 */   move  $v0, $zero
/* 005E44 70005244 03E00008 */  jr    $ra
/* 005E48 70005248 24020001 */   li    $v0, 1

.L7000524C:
/* 005E4C 7000524C 00001025 */  move  $v0, $zero
.L70005250:
/* 005E50 70005250 03E00008 */  jr    $ra
/* 005E54 70005254 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 return_strlen(void *arg0)
{
    s32 temp_v1;
    s32 phi_v1;
    void *phi_a0;
    s32 phi_v1_2;

    phi_v1 = 0;
    phi_a0 = (arg0 + 1);
    phi_v1_2 = 0;
    if (*arg0 != 0)
    {
loop_1:
        temp_v1 = (phi_v1 + 1);
        phi_v1_2 = temp_v1;
        if (temp_v1 < 0x100)
        {
            phi_v1 = temp_v1;
            phi_a0 = (phi_a0 + 1);
            phi_v1_2 = temp_v1;
            if (*phi_a0 != 0)
            {
                goto loop_1;
            }
        }
    }
    return phi_v1_2;
}
#else
GLOBAL_ASM(
.text
glabel return_strlen
/* 005E58 70005258 90820000 */  lbu   $v0, ($a0)
/* 005E5C 7000525C 00001825 */  move  $v1, $zero
/* 005E60 70005260 24840001 */  addiu $a0, $a0, 1
/* 005E64 70005264 10400009 */  beqz  $v0, .L7000528C
/* 005E68 70005268 00000000 */   nop   
/* 005E6C 7000526C 24630001 */  addiu $v1, $v1, 1
.L70005270:
/* 005E70 70005270 28610100 */  slti  $at, $v1, 0x100
/* 005E74 70005274 10200005 */  beqz  $at, .L7000528C
/* 005E78 70005278 00000000 */   nop   
/* 005E7C 7000527C 90820000 */  lbu   $v0, ($a0)
/* 005E80 70005280 24840001 */  addiu $a0, $a0, 1
/* 005E84 70005284 5440FFFA */  bnezl $v0, .L70005270
/* 005E88 70005288 24630001 */   addiu $v1, $v1, 1
.L7000528C:
/* 005E8C 7000528C 03E00008 */  jr    $ra
/* 005E90 70005290 00601025 */   move  $v0, $v1
)
#endif




#ifdef NONMATCHING
s32 indy_file_get_address_subsequent_data(s32 arg0) {
    s32 sp18;
    s32 temp_v1;
    s32 phi_a0;

    // Node 0
    romCopy(&indy_read_buffer, arg0, 0x60);
    current_indy_read_buf_resourceID = (?32) indy_read_buffer;
    ptr_indy_read_buf_string1 = &indy_read_buffer;
    ptr_indy_read_buf_string2 = (s32) ((return_strlen(&indy_read_buffer) + ptr_indy_read_buf_string1) + 1);
    sp18 = return_strlen(ptr_indy_read_buf_string1);
    temp_v1 = (((return_strlen(ptr_indy_read_buf_string2) + arg0) + sp18) + 6);
    phi_a0 = temp_v1;
    if ((temp_v1 & 3) != 0)
    {
        // Node 1
        phi_a0 = ((temp_v1 | 3) + 1);
    }
    // Node 2
    return phi_a0;
}
#else
GLOBAL_ASM(
.text
glabel indy_file_get_address_subsequent_data
/* 005E94 70005294 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 005E98 70005298 AFA40020 */  sw    $a0, 0x20($sp)
/* 005E9C 7000529C AFBF0014 */  sw    $ra, 0x14($sp)
/* 005EA0 700052A0 3C048006 */  lui   $a0, %hi(indy_read_buffer) # $a0, 0x8006
/* 005EA4 700052A4 24843670 */  addiu $a0, %lo(indy_read_buffer) # addiu $a0, $a0, 0x3670
/* 005EA8 700052A8 8FA50020 */  lw    $a1, 0x20($sp)
/* 005EAC 700052AC 0C001707 */  jal   romCopy
/* 005EB0 700052B0 24060060 */   li    $a2, 96
/* 005EB4 700052B4 3C0E8006 */  lui   $t6, %hi(indy_read_buffer) # $t6, 0x8006
/* 005EB8 700052B8 8DCE3670 */  lw    $t6, %lo(indy_read_buffer)($t6)
/* 005EBC 700052BC 3C028006 */  lui   $v0, %hi(ptr_indy_read_buf_string1) # $v0, 0x8006
/* 005EC0 700052C0 3C018006 */  lui   $at, %hi(current_indy_read_buf_resourceID) # $at, 0x8006
/* 005EC4 700052C4 3C0F8006 */  lui   $t7, %hi(indy_read_buffer+4)
/* 005EC8 700052C8 24423668 */  addiu $v0, %lo(ptr_indy_read_buf_string1) # addiu $v0, $v0, 0x3668
/* 005ECC 700052CC 25E43674 */  addiu $a0, $t7, %lo(indy_read_buffer+4)
/* 005ED0 700052D0 AC2E3664 */  sw    $t6, %lo(current_indy_read_buf_resourceID)($at)
/* 005ED4 700052D4 0C001496 */  jal   return_strlen
/* 005ED8 700052D8 AC440000 */   sw    $a0, ($v0)
/* 005EDC 700052DC 3C048006 */  lui   $a0, %hi(ptr_indy_read_buf_string1) # $a0, 0x8006
/* 005EE0 700052E0 8C843668 */  lw    $a0, %lo(ptr_indy_read_buf_string1)($a0)
/* 005EE4 700052E4 3C018006 */  lui   $at, %hi(ptr_indy_read_buf_string2) # $at, 0x8006
/* 005EE8 700052E8 0044C021 */  addu  $t8, $v0, $a0
/* 005EEC 700052EC 27190001 */  addiu $t9, $t8, 1
/* 005EF0 700052F0 0C001496 */  jal   return_strlen
/* 005EF4 700052F4 AC39366C */   sw    $t9, %lo(ptr_indy_read_buf_string2)($at)
/* 005EF8 700052F8 3C048006 */  lui   $a0, %hi(ptr_indy_read_buf_string2) # $a0, 0x8006
/* 005EFC 700052FC 8C84366C */  lw    $a0, %lo(ptr_indy_read_buf_string2)($a0)
/* 005F00 70005300 0C001496 */  jal   return_strlen
/* 005F04 70005304 AFA20018 */   sw    $v0, 0x18($sp)
/* 005F08 70005308 8FA80020 */  lw    $t0, 0x20($sp)
/* 005F0C 7000530C 8FAA0018 */  lw    $t2, 0x18($sp)
/* 005F10 70005310 8FBF0014 */  lw    $ra, 0x14($sp)
/* 005F14 70005314 00484821 */  addu  $t1, $v0, $t0
/* 005F18 70005318 012A1821 */  addu  $v1, $t1, $t2
/* 005F1C 7000531C 24630006 */  addiu $v1, $v1, 6
/* 005F20 70005320 306B0003 */  andi  $t3, $v1, 3
/* 005F24 70005324 11600003 */  beqz  $t3, .L70005334
/* 005F28 70005328 00602025 */   move  $a0, $v1
/* 005F2C 7000532C 34640003 */  ori   $a0, $v1, 3
/* 005F30 70005330 24840001 */  addiu $a0, $a0, 1
.L70005334:
/* 005F34 70005334 00801025 */  move  $v0, $a0
/* 005F38 70005338 03E00008 */  jr    $ra
/* 005F3C 7000533C 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif




#ifdef NONMATCHING
void scan_load_resourceID_from_indy_read_buf(void) {

}
#else
GLOBAL_ASM(
.text
glabel scan_load_resourceID_from_indy_read_buf
/* 005F40 70005340 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 005F44 70005344 AFB30020 */  sw    $s3, 0x20($sp)
/* 005F48 70005348 AFB2001C */  sw    $s2, 0x1c($sp)
/* 005F4C 7000534C 3C0200E0 */  lui   $v0, 0xe0
/* 005F50 70005350 34530004 */  ori   $s3, $v0, 4
/* 005F54 70005354 AFB10018 */  sw    $s1, 0x18($sp)
/* 005F58 70005358 AFB00014 */  sw    $s0, 0x14($sp)
/* 005F5C 7000535C 3C128006 */  lui   $s2, %hi(current_indy_read_buf_resourceID) # $s2, 0x8006
/* 005F60 70005360 00808825 */  move  $s1, $a0
/* 005F64 70005364 AFBF0024 */  sw    $ra, 0x24($sp)
/* 005F68 70005368 02608025 */  move  $s0, $s3
/* 005F6C 7000536C 26523664 */  addiu $s2, %lo(current_indy_read_buf_resourceID) # addiu $s2, $s2, 0x3664
.L70005370:
/* 005F70 70005370 0C0014A5 */  jal   indy_file_get_address_subsequent_data
/* 005F74 70005374 02002025 */   move  $a0, $s0
/* 005F78 70005378 8E430000 */  lw    $v1, ($s2)
/* 005F7C 7000537C 0223082B */  sltu  $at, $s1, $v1
/* 005F80 70005380 14200007 */  bnez  $at, .L700053A0
/* 005F84 70005384 00000000 */   nop   
/* 005F88 70005388 14600003 */  bnez  $v1, .L70005398
/* 005F8C 7000538C 02009825 */   move  $s3, $s0
/* 005F90 70005390 10000006 */  b     .L700053AC
/* 005F94 70005394 00001025 */   move  $v0, $zero
.L70005398:
/* 005F98 70005398 1000FFF5 */  b     .L70005370
/* 005F9C 7000539C 00408025 */   move  $s0, $v0
.L700053A0:
/* 005FA0 700053A0 0C0014A5 */  jal   indy_file_get_address_subsequent_data
/* 005FA4 700053A4 02602025 */   move  $a0, $s3
/* 005FA8 700053A8 24020001 */  li    $v0, 1
.L700053AC:
/* 005FAC 700053AC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 005FB0 700053B0 8FB00014 */  lw    $s0, 0x14($sp)
/* 005FB4 700053B4 8FB10018 */  lw    $s1, 0x18($sp)
/* 005FB8 700053B8 8FB2001C */  lw    $s2, 0x1c($sp)
/* 005FBC 700053BC 8FB30020 */  lw    $s3, 0x20($sp)
/* 005FC0 700053C0 03E00008 */  jr    $ra
/* 005FC4 700053C4 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
s32 is_valid_indy_read_buf_resourceID(void)
{
    indy_file_get_address_subsequent_data(0xe00000);
    return ((u32) (current_indy_read_buf_resourceID ^ 0x826475be) < 1U);
}
#else
GLOBAL_ASM(
.text
glabel is_valid_indy_read_buf_resourceID
/* 005FC8 700053C8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 005FCC 700053CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 005FD0 700053D0 0C0014A5 */  jal   indy_file_get_address_subsequent_data
/* 005FD4 700053D4 3C0400E0 */   lui   $a0, 0xe0
/* 005FD8 700053D8 3C028006 */  lui   $v0, %hi(current_indy_read_buf_resourceID) # $v0, 0x8006
/* 005FDC 700053DC 8C423664 */  lw    $v0, %lo(current_indy_read_buf_resourceID)($v0)
/* 005FE0 700053E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 005FE4 700053E4 3C018264 */  lui   $at, (0x826475BE >> 16) # lui $at, 0x8264
/* 005FE8 700053E8 342175BE */  ori   $at, (0x826475BE & 0xFFFF) # ori $at, $at, 0x75be
/* 005FEC 700053EC 00417026 */  xor   $t6, $v0, $at
/* 005FF0 700053F0 2DC20001 */  sltiu $v0, $t6, 1
/* 005FF4 700053F4 03E00008 */  jr    $ra
/* 005FF8 700053F8 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif






#ifdef NONMATCHING
void debug_indy_stub(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_indy_stub
/* 005FFC 700053FC 03E00008 */  jr    $ra
/* 006000 70005400 00000000 */   nop   
)
#endif

#ifdef NONMATCHING
void debug_indy_stub_0(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_indy_stub_0
/* 006004 70005404 03E00008 */  jr    $ra
/* 006008 70005408 00000000 */   nop   
)
#endif

#ifdef NONMATCHING
void debug_indy_stub_1(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_indy_stub_1
/* 00600C 7000540C 03E00008 */  jr    $ra
/* 006010 70005410 00000000 */   nop   
)
#endif

#ifdef NONMATCHING
void return_indy_read_buf_resourceID(void) {

}
#else
GLOBAL_ASM(
.text
glabel return_indy_read_buf_resourceID
/* 006014 70005414 3C028006 */  lui   $v0, 0x8006
/* 006018 70005418 03E00008 */  jr    $ra
/* 00601C 7000541C 8C423664 */   lw    $v0, 0x3664($v0)
)
#endif

#ifdef NONMATCHING
s32 debug_sp_related_11(u32 arg0, u32 arg1)
{
    ? sp1C;
    ? sp8;
    s32 temp_v0;
    void *temp_t8;

    sp1C = (?32) stack_ptrs_1;
    sp1C.unk4 = (?32) stack_ptrs_1.unk4;
    sp1C.unk8 = (?32) stack_ptrs_1.unk8;
    sp1C.unkC = (?32) stack_ptrs_1.unkC;
    sp1C.unk10 = (?32) stack_ptrs_1.unk10;
    sp8 = (?32) stack_ptrs_2;
    sp8.unk4 = (?32) stack_ptrs_2.unk4;
    sp8.unk8 = (?32) stack_ptrs_2.unk8;
    sp8.unkC = (?32) stack_ptrs_2.unkC;
    sp8.unk10 = (?32) stack_ptrs_2.unk10;
    if (arg1 <= 0)
    {
        return 0;
    }
    temp_v0 = (arg1 * 4);
    if (arg1 >= 6U)
    {
        return 0;
    }
    temp_t8 = (&sp8 + temp_v0);
    if (arg0 < 0x80000000U)
    {
        return ((arg0 & 0xf0000000) | (*temp_t8 - *(&sp1C + temp_v0)));
    }
    return *temp_t8;
}
#else
GLOBAL_ASM(
.text
glabel debug_sp_related_11
/* 006020 70005420 3C0E8002 */  lui   $t6, %hi(stack_ptrs_1) # $t6, 0x8002
/* 006024 70005424 25CE36DC */  addiu $t6, %lo(stack_ptrs_1) # addiu $t6, $t6, 0x36dc
/* 006028 70005428 8DC10000 */  lw    $at, ($t6)
/* 00602C 7000542C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 006030 70005430 27A7001C */  addiu $a3, $sp, 0x1c
/* 006034 70005434 ACE10000 */  sw    $at, ($a3)
/* 006038 70005438 8DD90004 */  lw    $t9, 4($t6)
/* 00603C 7000543C 3C098002 */  lui   $t1, %hi(stack_ptrs_2) # $t1, 0x8002
/* 006040 70005440 252936F0 */  addiu $t1, %lo(stack_ptrs_2) # addiu $t1, $t1, 0x36f0
/* 006044 70005444 ACF90004 */  sw    $t9, 4($a3)
/* 006048 70005448 8DC10008 */  lw    $at, 8($t6)
/* 00604C 7000544C 27A80008 */  addiu $t0, $sp, 8
/* 006050 70005450 00803025 */  move  $a2, $a0
/* 006054 70005454 ACE10008 */  sw    $at, 8($a3)
/* 006058 70005458 8DD9000C */  lw    $t9, 0xc($t6)
/* 00605C 7000545C ACF9000C */  sw    $t9, 0xc($a3)
/* 006060 70005460 8DC10010 */  lw    $at, 0x10($t6)
/* 006064 70005464 ACE10010 */  sw    $at, 0x10($a3)
/* 006068 70005468 8D210000 */  lw    $at, ($t1)
/* 00606C 7000546C AD010000 */  sw    $at, ($t0)
/* 006070 70005470 8D2C0004 */  lw    $t4, 4($t1)
/* 006074 70005474 AD0C0004 */  sw    $t4, 4($t0)
/* 006078 70005478 8D210008 */  lw    $at, 8($t1)
/* 00607C 7000547C AD010008 */  sw    $at, 8($t0)
/* 006080 70005480 8D2C000C */  lw    $t4, 0xc($t1)
/* 006084 70005484 AD0C000C */  sw    $t4, 0xc($t0)
/* 006088 70005488 8D210010 */  lw    $at, 0x10($t1)
/* 00608C 7000548C 18A00004 */  blez  $a1, .L700054A0
/* 006090 70005490 AD010010 */   sw    $at, 0x10($t0)
/* 006094 70005494 2CA10006 */  sltiu $at, $a1, 6
/* 006098 70005498 14200003 */  bnez  $at, .L700054A8
/* 00609C 7000549C 00051080 */   sll   $v0, $a1, 2
.L700054A0:
/* 0060A0 700054A0 1000000E */  b     .L700054DC
/* 0060A4 700054A4 00001025 */   move  $v0, $zero
.L700054A8:
/* 0060A8 700054A8 3C018000 */  lui   $at, 0x8000
/* 0060AC 700054AC 00E26821 */  addu  $t5, $a3, $v0
/* 0060B0 700054B0 0102C021 */  addu  $t8, $t0, $v0
/* 0060B4 700054B4 00C1082B */  sltu  $at, $a2, $at
/* 0060B8 700054B8 8DA30000 */  lw    $v1, ($t5)
/* 0060BC 700054BC 14200003 */  bnez  $at, .L700054CC
/* 0060C0 700054C0 8F040000 */   lw    $a0, ($t8)
/* 0060C4 700054C4 10000005 */  b     .L700054DC
/* 0060C8 700054C8 00801025 */   move  $v0, $a0
.L700054CC:
/* 0060CC 700054CC 3C01F000 */  lui   $at, 0xf000
/* 0060D0 700054D0 00C17824 */  and   $t7, $a2, $at
/* 0060D4 700054D4 00837023 */  subu  $t6, $a0, $v1
/* 0060D8 700054D8 01EE1025 */  or    $v0, $t7, $t6
.L700054DC:
/* 0060DC 700054DC 03E00008 */  jr    $ra
/* 0060E0 700054E0 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif






#ifdef NONMATCHING
s32 debug_sp_related_12(u32 arg0, u32 arg1) {
    u32 sp4;

    // Node 0
    sp4 = (?32) stack_ptrs_3;
    sp4.unk4 = (?32) stack_ptrs_3.unk4;
    sp4.unk8 = (?32) stack_ptrs_3.unk8;
    sp4.unkC = (?32) stack_ptrs_3.unkC;
    sp4.unk10 = (?32) stack_ptrs_3.unk10;
    if (arg1 <= 0)
    {
        // Node 2
        return;
        // (possible return value: 0)
    }
    // Node 1
    if (arg1 >= 6U)
    {
        // Node 2
        return;
        // (possible return value: 0)
    }
    // Node 3
    if (arg0 >= 0x80000000U)
    {
        // Node 4
        return;
        // (possible return value: *(&sp4 + (arg1 * 4)))
    }
    // Node 5
    return;
    // (possible return value: (arg0 & 0xf0000000))
}
#else
GLOBAL_ASM(
.text
glabel debug_sp_related_12
/* 0060E4 700054E4 3C0E8002 */  lui   $t6, %hi(stack_ptrs_3) # $t6, 0x8002
/* 0060E8 700054E8 25CE3704 */  addiu $t6, %lo(stack_ptrs_3) # addiu $t6, $t6, 0x3704
/* 0060EC 700054EC 8DC10000 */  lw    $at, ($t6)
/* 0060F0 700054F0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0060F4 700054F4 27A20004 */  addiu $v0, $sp, 4
/* 0060F8 700054F8 AC410000 */  sw    $at, ($v0)
/* 0060FC 700054FC 8DD90004 */  lw    $t9, 4($t6)
/* 006100 70005500 AC590004 */  sw    $t9, 4($v0)
/* 006104 70005504 8DC10008 */  lw    $at, 8($t6)
/* 006108 70005508 AC410008 */  sw    $at, 8($v0)
/* 00610C 7000550C 8DD9000C */  lw    $t9, 0xc($t6)
/* 006110 70005510 AC59000C */  sw    $t9, 0xc($v0)
/* 006114 70005514 8DC10010 */  lw    $at, 0x10($t6)
/* 006118 70005518 18A00004 */  blez  $a1, .L7000552C
/* 00611C 7000551C AC410010 */   sw    $at, 0x10($v0)
/* 006120 70005520 2CA10006 */  sltiu $at, $a1, 6
/* 006124 70005524 14200003 */  bnez  $at, .L70005534
/* 006128 70005528 00054080 */   sll   $t0, $a1, 2
.L7000552C:
/* 00612C 7000552C 1000000A */  b     .L70005558
/* 006130 70005530 00001025 */   move  $v0, $zero
.L70005534:
/* 006134 70005534 3C018000 */  lui   $at, 0x8000
/* 006138 70005538 00484821 */  addu  $t1, $v0, $t0
/* 00613C 7000553C 0081082B */  sltu  $at, $a0, $at
/* 006140 70005540 14200003 */  bnez  $at, .L70005550
/* 006144 70005544 8D230000 */   lw    $v1, ($t1)
/* 006148 70005548 10000003 */  b     .L70005558
/* 00614C 7000554C 00601025 */   move  $v0, $v1
.L70005550:
/* 006150 70005550 3C01F000 */  lui   $at, 0xf000
/* 006154 70005554 00811024 */  and   $v0, $a0, $at
.L70005558:
/* 006158 70005558 03E00008 */  jr    $ra
/* 00615C 7000555C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif




#ifdef NONMATCHING
s32 _is_normal_single_precision_float(f32 arg0) {
    // Node 0
    if ((u32) (arg0 & 0x7fffff) >= 1U)
    {
        // Node 1
        if (0U < (u32) ((arg0 >> 0x17) & 0xff))
        {
            // Node 2
            return;
            // (possible return value: (0U < (u32) (((arg0 >> 0x17) & 0xff) ^ 0xff)))
        }
    }
    // (possible return value: ((u32) (arg0 & 0x7fffff) < 1U))
}
#else
GLOBAL_ASM(
.text
glabel _is_normal_single_precision_float
/* 006160 70005560 E7AC0000 */  swc1  $f12, ($sp)
/* 006164 70005564 8FA40000 */  lw    $a0, ($sp)
/* 006168 70005568 3C01007F */  lui   $at, (0x007FFFFF >> 16) # lui $at, 0x7f
/* 00616C 7000556C 3421FFFF */  ori   $at, (0x007FFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 006170 70005570 00811024 */  and   $v0, $a0, $at
/* 006174 70005574 2C4E0001 */  sltiu $t6, $v0, 1
/* 006178 70005578 15C00008 */  bnez  $t6, .L7000559C
/* 00617C 7000557C 01C01025 */   move  $v0, $t6
/* 006180 70005580 00041DC2 */  srl   $v1, $a0, 0x17
/* 006184 70005584 306F00FF */  andi  $t7, $v1, 0xff
/* 006188 70005588 000F102B */  sltu  $v0, $zero, $t7
/* 00618C 7000558C 10400003 */  beqz  $v0, .L7000559C
/* 006190 70005590 00000000 */   nop   
/* 006194 70005594 39E200FF */  xori  $v0, $t7, 0xff
/* 006198 70005598 0002102B */  sltu  $v0, $zero, $v0
.L7000559C:
/* 00619C 7000559C 03E00008 */  jr    $ra
/* 0061A0 700055A0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void is_normal_single_precision_float(s32 arg0, s32 arg1) {
    // Node 0
    _is_normal_single_precision_float(arg1);
    return;
    // (possible return value: _is_normal_single_precision_float(arg1))
}
#else
GLOBAL_ASM(
.text
glabel is_normal_single_precision_float
/* 0061A4 700055A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0061A8 700055A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0061AC 700055AC 44856000 */  mtc1  $a1, $f12
/* 0061B0 700055B0 0C001558 */  jal   _is_normal_single_precision_float
/* 0061B4 700055B4 AFA40018 */   sw    $a0, 0x18($sp)
/* 0061B8 700055B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0061BC 700055BC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0061C0 700055C0 03E00008 */  jr    $ra
/* 0061C4 700055C4 00000000 */   nop   
)
#endif






#ifdef NONMATCHING
void set_normality_of_single_precision_floats(s32 arg0, s32 arg1, ? arg2, ? arg3, s32 arg6, ? arg8, ? arg9, ? argA) {
    // Node 0
    is_normal_single_precision_float(arg1, arg1);
    is_normal_single_precision_float((arg6 + 2), arg8);
    is_normal_single_precision_float((arg6 + 4), arg9);
    is_normal_single_precision_float((arg6 + 6), argA);
    return;
    // (possible return value: is_normal_single_precision_float((arg6 + 6), argA))
}
#else
GLOBAL_ASM(
.text
glabel set_normality_of_single_precision_floats
/* 0061C8 700055C8 44856000 */  mtc1  $a1, $f12
/* 0061CC 700055CC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0061D0 700055D0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0061D4 700055D4 44056000 */  mfc1  $a1, $f12
/* 0061D8 700055D8 AFA40018 */  sw    $a0, 0x18($sp)
/* 0061DC 700055DC AFA60020 */  sw    $a2, 0x20($sp)
/* 0061E0 700055E0 0C001569 */  jal   is_normal_single_precision_float
/* 0061E4 700055E4 AFA70024 */   sw    $a3, 0x24($sp)
/* 0061E8 700055E8 8FA40018 */  lw    $a0, 0x18($sp)
/* 0061EC 700055EC 8FA50020 */  lw    $a1, 0x20($sp)
/* 0061F0 700055F0 0C001569 */  jal   is_normal_single_precision_float
/* 0061F4 700055F4 24840002 */   addiu $a0, $a0, 2
/* 0061F8 700055F8 8FA40018 */  lw    $a0, 0x18($sp)
/* 0061FC 700055FC 8FA50024 */  lw    $a1, 0x24($sp)
/* 006200 70005600 0C001569 */  jal   is_normal_single_precision_float
/* 006204 70005604 24840004 */   addiu $a0, $a0, 4
/* 006208 70005608 8FA40018 */  lw    $a0, 0x18($sp)
/* 00620C 7000560C 8FA50028 */  lw    $a1, 0x28($sp)
/* 006210 70005610 0C001569 */  jal   is_normal_single_precision_float
/* 006214 70005614 24840006 */   addiu $a0, $a0, 6
/* 006218 70005618 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00621C 7000561C 27BD0018 */  addiu $sp, $sp, 0x18
/* 006220 70005620 03E00008 */  jr    $ra
/* 006224 70005624 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void debug_indy_stub_2(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_indy_stub_2
/* 006228 70005628 03E00008 */  jr    $ra
/* 00622C 7000562C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void write_char_to_pos_stderr(void) {

}
#else
GLOBAL_ASM(
.text
glabel write_char_to_pos_stderr
/* 006230 70005630 30CE00FF */  andi  $t6, $a2, 0xff
/* 006234 70005634 AFA60008 */  sw    $a2, 8($sp)
/* 006238 70005638 24010009 */  li    $at, 9
/* 00623C 7000563C 01C03025 */  move  $a2, $t6
/* 006240 70005640 11C10004 */  beq   $t6, $at, .L70005654
/* 006244 70005644 01C01025 */   move  $v0, $t6
/* 006248 70005648 2401000A */  li    $at, 10
/* 00624C 7000564C 15C10003 */  bne   $t6, $at, .L7000565C
/* 006250 70005650 00000000 */   nop   
.L70005654:
/* 006254 70005654 00003025 */  move  $a2, $zero
/* 006258 70005658 00001025 */  move  $v0, $zero
.L7000565C:
/* 00625C 7000565C 18400002 */  blez  $v0, .L70005668
/* 006260 70005660 28410020 */   slti  $at, $v0, 0x20
/* 006264 70005664 14200003 */  bnez  $at, .L70005674
.L70005668:
/* 006268 70005668 2841007F */   slti  $at, $v0, 0x7f
/* 00626C 7000566C 14200002 */  bnez  $at, .L70005678
/* 006270 70005670 00000000 */   nop   
.L70005674:
/* 006274 70005674 2406003F */  li    $a2, 63
.L70005678:
/* 006278 70005678 0480000E */  bltz  $a0, .L700056B4
/* 00627C 7000567C 28810048 */   slti  $at, $a0, 0x48
/* 006280 70005680 1020000C */  beqz  $at, .L700056B4
/* 006284 70005684 00000000 */   nop   
/* 006288 70005688 04A0000A */  bltz  $a1, .L700056B4
/* 00628C 7000568C 28A10020 */   slti  $at, $a1, 0x20
/* 006290 70005690 10200008 */  beqz  $at, .L700056B4
/* 006294 70005694 000578C0 */   sll   $t7, $a1, 3
/* 006298 70005698 01E57821 */  addu  $t7, $t7, $a1
/* 00629C 7000569C 000F78C0 */  sll   $t7, $t7, 3
/* 0062A0 700056A0 01E57823 */  subu  $t7, $t7, $a1
/* 0062A4 700056A4 01E4C021 */  addu  $t8, $t7, $a0
/* 0062A8 700056A8 3C018002 */  lui   $at, 0x8002
/* 0062AC 700056AC 00380821 */  addu  $at, $at, $t8
/* 0062B0 700056B0 A0263718 */  sb    $a2, 0x3718($at)
.L700056B4:
/* 0062B4 700056B4 03E00008 */  jr    $ra
/* 0062B8 700056B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void __osRdbSend(void) {

}
#else
GLOBAL_ASM(
.text
glabel __osRdbSend
/* 0062BC 700056BC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0062C0 700056C0 308600FF */  andi  $a2, $a0, 0xff
/* 0062C4 700056C4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0062C8 700056C8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0062CC 700056CC AFA40028 */  sw    $a0, 0x28($sp)
/* 0062D0 700056D0 10C00039 */  beqz  $a2, .L700057B8
/* 0062D4 700056D4 00C01025 */   move  $v0, $a2
/* 0062D8 700056D8 24010009 */  li    $at, 9
/* 0062DC 700056DC 14C1000A */  bne   $a2, $at, .L70005708
/* 0062E0 700056E0 3C108002 */   lui   $s0, %hi(stderr_buffer + 0x8E0) # $s0, 0x8002
/* 0062E4 700056E4 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
.L700056E8:
/* 0062E8 700056E8 0C0015AF */  jal   __osRdbSend
/* 0062EC 700056EC 24040020 */   li    $a0, 32
/* 0062F0 700056F0 8E0E0000 */  lw    $t6, ($s0)
/* 0062F4 700056F4 31CF0007 */  andi  $t7, $t6, 7
/* 0062F8 700056F8 15E0FFFB */  bnez  $t7, .L700056E8
/* 0062FC 700056FC 00000000 */   nop   
/* 006300 70005700 1000002E */  b     .L700057BC
/* 006304 70005704 8FBF001C */   lw    $ra, 0x1c($sp)
.L70005708:
/* 006308 70005708 2401000A */  li    $at, 10
/* 00630C 7000570C 14410008 */  bne   $v0, $at, .L70005730
/* 006310 70005710 3C038002 */   lui   $v1, %hi(stderr_buffer + 0x8E4) # $v1, 0x8002
/* 006314 70005714 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006318 70005718 8C780000 */  lw    $t8, ($v1)
/* 00631C 7000571C 3C108002 */  lui   $s0, %hi(stderr_buffer + 0x8E0) # $s0, 0x8002
/* 006320 70005720 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
/* 006324 70005724 27190001 */  addiu $t9, $t8, 1
/* 006328 70005728 AC790000 */  sw    $t9, ($v1)
/* 00632C 7000572C AE000000 */  sw    $zero, ($s0)
.L70005730:
/* 006330 70005730 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4) # $v1, 0x8002
/* 006334 70005734 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006338 70005738 8C650000 */  lw    $a1, ($v1)
/* 00633C 7000573C 3C108002 */  lui   $s0, %hi(stderr_buffer + 0x8E0) # $s0, 0x8002
/* 006340 70005740 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
/* 006344 70005744 28A1001F */  slti  $at, $a1, 0x1f
/* 006348 70005748 1420000A */  bnez  $at, .L70005774
/* 00634C 7000574C 24A4FFE2 */   addiu $a0, $a1, -0x1e
/* 006350 70005750 AFA20024 */  sw    $v0, 0x24($sp)
/* 006354 70005754 0C0015F3 */  jal   scroll_stderr_oneline
/* 006358 70005758 A3A6002B */   sb    $a2, 0x2b($sp)
/* 00635C 7000575C 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4) # $v1, 0x8002
/* 006360 70005760 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006364 70005764 2408001E */  li    $t0, 30
/* 006368 70005768 8FA20024 */  lw    $v0, 0x24($sp)
/* 00636C 7000576C 93A6002B */  lbu   $a2, 0x2b($sp)
/* 006370 70005770 AC680000 */  sw    $t0, ($v1)
.L70005774:
/* 006374 70005774 2401000A */  li    $at, 10
/* 006378 70005778 50410010 */  beql  $v0, $at, .L700057BC
/* 00637C 7000577C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 006380 70005780 8E040000 */  lw    $a0, ($s0)
/* 006384 70005784 0C00158C */  jal   write_char_to_pos_stderr
/* 006388 70005788 8C650000 */   lw    $a1, ($v1)
/* 00638C 7000578C 8E090000 */  lw    $t1, ($s0)
/* 006390 70005790 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4) # $v1, 0x8002
/* 006394 70005794 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006398 70005798 252A0001 */  addiu $t2, $t1, 1
/* 00639C 7000579C 29410047 */  slti  $at, $t2, 0x47
/* 0063A0 700057A0 14200005 */  bnez  $at, .L700057B8
/* 0063A4 700057A4 AE0A0000 */   sw    $t2, ($s0)
/* 0063A8 700057A8 8C6C0000 */  lw    $t4, ($v1)
/* 0063AC 700057AC AE000000 */  sw    $zero, ($s0)
/* 0063B0 700057B0 258D0001 */  addiu $t5, $t4, 1
/* 0063B4 700057B4 AC6D0000 */  sw    $t5, ($v1)
.L700057B8:
/* 0063B8 700057B8 8FBF001C */  lw    $ra, 0x1c($sp)
.L700057BC:
/* 0063BC 700057BC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0063C0 700057C0 27BD0028 */  addiu $sp, $sp, 0x28
/* 0063C4 700057C4 03E00008 */  jr    $ra
/* 0063C8 700057C8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 scroll_stderr_oneline(s32 arg0) {
    void *temp_a1_2;
    void *temp_a1;

    // Node 0
    if (0 < arg0)
    {
        // Node 1
        // Node 2
        // Node 3
        temp_a1_2 = (&stderr_buffer + 3);
        stderr_buffer = (s8) stderr_buffer.unk47;
        stderr_buffer.unk1 = (s8) stderr_buffer.unk48;
        stderr_buffer.unk2 = (s8) stderr_buffer.unk49;
        // Node 4
        temp_a1 = (temp_a1_2 + 4);
        temp_a1->unk-3 = (s8) temp_a1_2->unk48;
        temp_a1->unk-2 = (s8) temp_a1_2->unk49;
        temp_a1->unk-1 = (s8) temp_a1_2->unk4A;
        temp_a1->unk-4 = (s8) temp_a1_2->unk47;
        if ((3 + 4) != 0x47)
        {
            goto loop_4;
        }
        // Node 5
        if ((&stderr_buffer + 0x47) != (stderr_buffer + 0x899))
        {
            goto loop_3;
        }
        // Node 6
        if (0 < (arg0 + -1))
        {
            goto loop_2;
        }
    }
    // (possible return value: (0 < arg0))
}
#else
GLOBAL_ASM(
.text
glabel scroll_stderr_oneline
/* 0063CC 700057CC 0004102A */  slt   $v0, $zero, $a0
/* 0063D0 700057D0 10400020 */  beqz  $v0, .L70005854
/* 0063D4 700057D4 2484FFFF */   addiu $a0, $a0, -1
/* 0063D8 700057D8 3C088002 */  lui   $t0, %hi(stderr_buffer + 0x899) # $t0, 0x8002
/* 0063DC 700057DC 25083FB1 */  addiu $t0, %lo(stderr_buffer + 0x899) # addiu $t0, $t0, 0x3fb1
/* 0063E0 700057E0 24070047 */  li    $a3, 71
.L700057E4:
/* 0063E4 700057E4 3C0E8002 */  lui   $t6, %hi(stderr_buffer)
/* 0063E8 700057E8 25C63718 */  addiu $a2, $t6, %lo(stderr_buffer)
/* 0063EC 700057EC 00C01825 */  move  $v1, $a2
.L700057F0:
/* 0063F0 700057F0 90CF0047 */  lbu   $t7, 0x47($a2)
/* 0063F4 700057F4 90D80048 */  lbu   $t8, 0x48($a2)
/* 0063F8 700057F8 90D90049 */  lbu   $t9, 0x49($a2)
/* 0063FC 700057FC 24020003 */  li    $v0, 3
/* 006400 70005800 24650003 */  addiu $a1, $v1, 3
/* 006404 70005804 A0CF0000 */  sb    $t7, ($a2)
/* 006408 70005808 A0D80001 */  sb    $t8, 1($a2)
/* 00640C 7000580C A0D90002 */  sb    $t9, 2($a2)
.L70005810:
/* 006410 70005810 90AA0048 */  lbu   $t2, 0x48($a1)
/* 006414 70005814 90AB0049 */  lbu   $t3, 0x49($a1)
/* 006418 70005818 90AC004A */  lbu   $t4, 0x4a($a1)
/* 00641C 7000581C 90A90047 */  lbu   $t1, 0x47($a1)
/* 006420 70005820 24420004 */  addiu $v0, $v0, 4
/* 006424 70005824 24A50004 */  addiu $a1, $a1, 4
/* 006428 70005828 A0AAFFFD */  sb    $t2, -3($a1)
/* 00642C 7000582C A0ABFFFE */  sb    $t3, -2($a1)
/* 006430 70005830 A0ACFFFF */  sb    $t4, -1($a1)
/* 006434 70005834 1447FFF6 */  bne   $v0, $a3, .L70005810
/* 006438 70005838 A0A9FFFC */   sb    $t1, -4($a1)
/* 00643C 7000583C 24C60047 */  addiu $a2, $a2, 0x47
/* 006440 70005840 14C8FFEB */  bne   $a2, $t0, .L700057F0
/* 006444 70005844 24630047 */   addiu $v1, $v1, 0x47
/* 006448 70005848 0004102A */  slt   $v0, $zero, $a0
/* 00644C 7000584C 1440FFE5 */  bnez  $v0, .L700057E4
/* 006450 70005850 2484FFFF */   addiu $a0, $a0, -1
.L70005854:
/* 006454 70005854 03E00008 */  jr    $ra
/* 006458 70005858 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void print_to_vidbuff1(s32 arg0, s32 arg1, ? arg2, s32 arg6, s32 arg7, s32 arg8) {
    s32 temp_at;
    void *temp_a0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;

    // Node 0
    if (arg8 == 0)
    {
        // Node 1
    }
    // Node 2
    temp_at = (arg8 < 0x7f);
    if (temp_at == 0)
    {
        // Node 3
        if (temp_at != 0)
        {
            // Node 4
            temp_a0 = (0x80020000 + (arg8 * 4));
            temp_v1 = (((arg6 * 2) + ptr_videobuffer1) + ((arg7 * get_video2_settings_txtClipW()) * 2));
            // Node 5
            if ((temp_a0->unk3F80 & 0x80000000) != 0)
            {
                // Node 6
                *temp_v1 = (u16)0xffff;
            }
            else
            {
                // Node 7
                *temp_v1 = (u16)1;
            }
            // Node 8
            temp_v1_2 = (temp_v1 + 2);
            if (((temp_a0->unk3F80 * 2) & 0x80000000) != 0)
            {
                // Node 9
                *temp_v1_2 = (u16)0xffff;
            }
            else
            {
                // Node 10
                *temp_v1_2 = (u16)1;
            }
            // Node 11
            temp_v1_3 = (temp_v1_2 + 2);
            if (((temp_a0->unk3F80 * 4) & 0x80000000) != 0)
            {
                // Node 12
                *temp_v1_3 = (u16)0xffff;
            }
            else
            {
                // Node 13
                *temp_v1_3 = (u16)1;
            }
            // Node 14
            temp_v1_4 = (temp_v1_3 + 2);
            if (((temp_a0->unk3F80 * 8) & 0x80000000) != 0)
            {
                // Node 15
                *temp_v1_4 = (u16)0xffff;
            }
            else
            {
                // Node 16
                *temp_v1_4 = (u16)1;
            }
            // Node 17
            if ((0 + 1) != 7)
            {
                goto loop_5;
            }
        }
    }
    // (possible return value: get_video2_settings_txtClipW())
}

#else
GLOBAL_ASM(
.text
glabel print_to_vidbuff1
/* 00645C 7000585C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006460 70005860 AFBF0014 */  sw    $ra, 0x14($sp)
/* 006464 70005864 AFA40018 */  sw    $a0, 0x18($sp)
/* 006468 70005868 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00646C 7000586C 0C001107 */  jal   get_video2_settings_txtClipW
/* 006470 70005870 AFA60020 */   sw    $a2, 0x20($sp)
/* 006474 70005874 93A50023 */  lbu   $a1, 0x23($sp)
/* 006478 70005878 54A00003 */  bnezl $a1, .L70005888
/* 00647C 7000587C 28A10020 */   slti  $at, $a1, 0x20
/* 006480 70005880 24050020 */  li    $a1, 32
/* 006484 70005884 28A10020 */  slti  $at, $a1, 0x20
.L70005888:
/* 006488 70005888 1420003A */  bnez  $at, .L70005974
/* 00648C 7000588C 28A1007F */   slti  $at, $a1, 0x7f
/* 006490 70005890 10200038 */  beqz  $at, .L70005974
/* 006494 70005894 8FAE0018 */   lw    $t6, 0x18($sp)
/* 006498 70005898 8FAB001C */  lw    $t3, 0x1c($sp)
/* 00649C 7000589C 3C188002 */  lui   $t8, %hi(ptr_videobuffer1) # $t8, 0x8002
/* 0064A0 700058A0 8F18417C */  lw    $t8, %lo(ptr_videobuffer1)($t8)
/* 0064A4 700058A4 01620019 */  multu $t3, $v0
/* 0064A8 700058A8 000E7840 */  sll   $t7, $t6, 1
/* 0064AC 700058AC 00057080 */  sll   $t6, $a1, 2
/* 0064B0 700058B0 3C048002 */  lui   $a0, 0x8002
/* 0064B4 700058B4 008E2021 */  addu  $a0, $a0, $t6
/* 0064B8 700058B8 01F8C821 */  addu  $t9, $t7, $t8
/* 0064BC 700058BC 8C843F80 */  lw    $a0, 0x3f80($a0)
/* 0064C0 700058C0 3C058000 */  lui   $a1, 0x8000
/* 0064C4 700058C4 00004025 */  move  $t0, $zero
/* 0064C8 700058C8 00024840 */  sll   $t1, $v0, 1
/* 0064CC 700058CC 00006012 */  mflo  $t4
/* 0064D0 700058D0 000C6840 */  sll   $t5, $t4, 1
/* 0064D4 700058D4 032D1821 */  addu  $v1, $t9, $t5
/* 0064D8 700058D8 240A0007 */  li    $t2, 7
/* 0064DC 700058DC 24070001 */  li    $a3, 1
/* 0064E0 700058E0 3406FFFF */  li    $a2, 65535
.L700058E4:
/* 0064E4 700058E4 00857824 */  and   $t7, $a0, $a1
/* 0064E8 700058E8 11E00003 */  beqz  $t7, .L700058F8
/* 0064EC 700058EC 0004C040 */   sll   $t8, $a0, 1
/* 0064F0 700058F0 10000002 */  b     .L700058FC
/* 0064F4 700058F4 A4660000 */   sh    $a2, ($v1)
.L700058F8:
/* 0064F8 700058F8 A4670000 */  sh    $a3, ($v1)
.L700058FC:
/* 0064FC 700058FC 03055824 */  and   $t3, $t8, $a1
/* 006500 70005900 24630002 */  addiu $v1, $v1, 2
/* 006504 70005904 11600003 */  beqz  $t3, .L70005914
/* 006508 70005908 03002025 */   move  $a0, $t8
/* 00650C 7000590C 10000002 */  b     .L70005918
/* 006510 70005910 A4660000 */   sh    $a2, ($v1)
.L70005914:
/* 006514 70005914 A4670000 */  sh    $a3, ($v1)
.L70005918:
/* 006518 70005918 00046040 */  sll   $t4, $a0, 1
/* 00651C 7000591C 0185C824 */  and   $t9, $t4, $a1
/* 006520 70005920 01802025 */  move  $a0, $t4
/* 006524 70005924 13200003 */  beqz  $t9, .L70005934
/* 006528 70005928 24630002 */   addiu $v1, $v1, 2
/* 00652C 7000592C 10000002 */  b     .L70005938
/* 006530 70005930 A4660000 */   sh    $a2, ($v1)
.L70005934:
/* 006534 70005934 A4670000 */  sh    $a3, ($v1)
.L70005938:
/* 006538 70005938 00046840 */  sll   $t5, $a0, 1
/* 00653C 7000593C 01A57024 */  and   $t6, $t5, $a1
/* 006540 70005940 01A02025 */  move  $a0, $t5
/* 006544 70005944 11C00003 */  beqz  $t6, .L70005954
/* 006548 70005948 24630002 */   addiu $v1, $v1, 2
/* 00654C 7000594C 10000002 */  b     .L70005958
/* 006550 70005950 A4660000 */   sh    $a2, ($v1)
.L70005954:
/* 006554 70005954 A4670000 */  sh    $a3, ($v1)
.L70005958:
/* 006558 70005958 24630002 */  addiu $v1, $v1, 2
/* 00655C 7000595C 25080001 */  addiu $t0, $t0, 1
/* 006560 70005960 00047840 */  sll   $t7, $a0, 1
/* 006564 70005964 00691821 */  addu  $v1, $v1, $t1
/* 006568 70005968 01E02025 */  move  $a0, $t7
/* 00656C 7000596C 150AFFDD */  bne   $t0, $t2, .L700058E4
/* 006570 70005970 2463FFF8 */   addiu $v1, $v1, -8
.L70005974:
/* 006574 70005974 8FBF0014 */  lw    $ra, 0x14($sp)
/* 006578 70005978 27BD0018 */  addiu $sp, $sp, 0x18
/* 00657C 7000597C 03E00008 */  jr    $ra
/* 006580 70005980 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void set_ptr_video_buffers(s32 arg0, s32 arg1) {
    ptr_videobuffer1 = (s32) (arg0 | 0xa0000000);
    ptr_videobuffer2 = (s32) (arg1 | 0xa0000000);
}

#else
GLOBAL_ASM(
.text
glabel set_ptr_video_buffers
/* 006584 70005984 3C02A000 */  lui   $v0, 0xa000
/* 006588 70005988 00827025 */  or    $t6, $a0, $v0
/* 00658C 7000598C 3C018002 */  lui   $at, %hi(ptr_videobuffer1) # $at, 0x8002
/* 006590 70005990 AC2E417C */  sw    $t6, %lo(ptr_videobuffer1)($at)
/* 006594 70005994 3C018002 */  lui   $at, %hi(ptr_videobuffer2)
/* 006598 70005998 00A27825 */  or    $t7, $a1, $v0
/* 00659C 7000599C 03E00008 */  jr    $ra
/* 0065A0 700059A0 AC2F4180 */   sw    $t7, %lo(ptr_videobuffer2)($at)
)
#endif






#ifdef NONMATCHING
void set_video_buffer_pointers(void) {
    set_ptr_video_buffers(&cfb_16_a, &cfb_16_b);
}
#else
GLOBAL_ASM(
.text
glabel set_video_buffer_pointers
/* 0065A4 700059A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0065A8 700059A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0065AC 700059AC 3C04803B */  lui   $a0, %hi(cfb_16_a) # $a0, 0x803b
/* 0065B0 700059B0 3C05803E */  lui   $a1, %hi(cfb_16_b) # $a1, 0x803e
/* 0065B4 700059B4 24A5A800 */  addiu $a1, %lo(cfb_16_b) # addiu $a1, $a1, -0x5800
/* 0065B8 700059B8 0C001661 */  jal   set_ptr_video_buffers
/* 0065BC 700059BC 24845000 */   addiu $a0, %lo(cfb_16_a) # addiu $a0, $a0, 0x5000
/* 0065C0 700059C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0065C4 700059C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0065C8 700059C8 03E00008 */  jr    $ra
/* 0065CC 700059CC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void write_stderr_to_buffer(void) {

}
#else
GLOBAL_ASM(
.text
glabel write_stderr_to_buffer
/* 0065D0 700059D0 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0065D4 700059D4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0065D8 700059D8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0065DC 700059DC 00808025 */  move  $s0, $a0
/* 0065E0 700059E0 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0065E4 700059E4 AFB70034 */  sw    $s7, 0x34($sp)
/* 0065E8 700059E8 AFB60030 */  sw    $s6, 0x30($sp)
/* 0065EC 700059EC AFB5002C */  sw    $s5, 0x2c($sp)
/* 0065F0 700059F0 AFB40028 */  sw    $s4, 0x28($sp)
/* 0065F4 700059F4 AFB30024 */  sw    $s3, 0x24($sp)
/* 0065F8 700059F8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0065FC 700059FC 0C001669 */  jal   set_video_buffer_pointers
/* 006600 70005A00 AFB1001C */   sw    $s1, 0x1c($sp)
/* 006604 70005A04 3C01A000 */  lui   $at, 0xa000
/* 006608 70005A08 02017025 */  or    $t6, $s0, $at
/* 00660C 70005A0C 3C018002 */  lui   $at, %hi(ptr_videobuffer1) # $at, 0x8002
/* 006610 70005A10 0C001107 */  jal   get_video2_settings_txtClipW
/* 006614 70005A14 AC2E417C */   sw    $t6, %lo(ptr_videobuffer1)($at)
/* 006618 70005A18 2450FFF3 */  addiu $s0, $v0, -0xd
/* 00661C 70005A1C 06010003 */  bgez  $s0, .L70005A2C
/* 006620 70005A20 00107883 */   sra   $t7, $s0, 2
/* 006624 70005A24 26010003 */  addiu $at, $s0, 3
/* 006628 70005A28 00017883 */  sra   $t7, $at, 2
.L70005A2C:
/* 00662C 70005A2C 0C00110B */  jal   get_video2_settings_txtClipH
/* 006630 70005A30 01E08025 */   move  $s0, $t7
/* 006634 70005A34 2443FFF6 */  addiu $v1, $v0, -0xa
/* 006638 70005A38 24010007 */  li    $at, 7
/* 00663C 70005A3C 0061001A */  div   $zero, $v1, $at
/* 006640 70005A40 00001812 */  mflo  $v1
/* 006644 70005A44 247EFFFF */  addiu $fp, $v1, -1
/* 006648 70005A48 1BC00023 */  blez  $fp, .L70005AD8
/* 00664C 70005A4C 0000A825 */   move  $s5, $zero
/* 006650 70005A50 2616FFFB */  addiu $s6, $s0, -5
/* 006654 70005A54 2417001F */  li    $s7, 31
/* 006658 70005A58 24140130 */  li    $s4, 304
.L70005A5C:
/* 00665C 70005A5C 1AC00018 */  blez  $s6, .L70005AC0
/* 006660 70005A60 00008080 */   sll   $s0, $zero, 2
/* 006664 70005A64 0015C8C0 */  sll   $t9, $s5, 3
/* 006668 70005A68 0335C821 */  addu  $t9, $t9, $s5
/* 00666C 70005A6C 0019C8C0 */  sll   $t9, $t9, 3
/* 006670 70005A70 001590C0 */  sll   $s2, $s5, 3
/* 006674 70005A74 3C098002 */  lui   $t1, %hi(stderr_buffer) # $t1, 0x8002
/* 006678 70005A78 25293718 */  addiu $t1, %lo(stderr_buffer) # addiu $t1, $t1, 0x3718
/* 00667C 70005A7C 02559023 */  subu  $s2, $s2, $s5
/* 006680 70005A80 0335C823 */  subu  $t9, $t9, $s5
/* 006684 70005A84 00169880 */  sll   $s3, $s6, 2
/* 006688 70005A88 26730014 */  addiu $s3, $s3, 0x14
/* 00668C 70005A8C 03298821 */  addu  $s1, $t9, $t1
/* 006690 70005A90 26520007 */  addiu $s2, $s2, 7
/* 006694 70005A94 26100014 */  addiu $s0, $s0, 0x14
/* 006698 70005A98 02002025 */  move  $a0, $s0
.L70005A9C:
/* 00669C 70005A9C 02402825 */  move  $a1, $s2
/* 0066A0 70005AA0 0C001617 */  jal   print_to_vidbuff1
/* 0066A4 70005AA4 92260000 */   lbu   $a2, ($s1)
/* 0066A8 70005AA8 26100004 */  addiu $s0, $s0, 4
/* 0066AC 70005AAC 0213082A */  slt   $at, $s0, $s3
/* 0066B0 70005AB0 10200003 */  beqz  $at, .L70005AC0
/* 0066B4 70005AB4 26310001 */   addiu $s1, $s1, 1
/* 0066B8 70005AB8 5614FFF8 */  bnel  $s0, $s4, .L70005A9C
/* 0066BC 70005ABC 02002025 */   move  $a0, $s0
.L70005AC0:
/* 0066C0 70005AC0 26B50001 */  addiu $s5, $s5, 1
/* 0066C4 70005AC4 02BE082A */  slt   $at, $s5, $fp
/* 0066C8 70005AC8 50200004 */  beql  $at, $zero, .L70005ADC
/* 0066CC 70005ACC 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0066D0 70005AD0 16B7FFE2 */  bne   $s5, $s7, .L70005A5C
/* 0066D4 70005AD4 00000000 */   nop   
.L70005AD8:
/* 0066D8 70005AD8 8FBF003C */  lw    $ra, 0x3c($sp)
.L70005ADC:
/* 0066DC 70005ADC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0066E0 70005AE0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0066E4 70005AE4 8FB20020 */  lw    $s2, 0x20($sp)
/* 0066E8 70005AE8 8FB30024 */  lw    $s3, 0x24($sp)
/* 0066EC 70005AEC 8FB40028 */  lw    $s4, 0x28($sp)
/* 0066F0 70005AF0 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0066F4 70005AF4 8FB60030 */  lw    $s6, 0x30($sp)
/* 0066F8 70005AF8 8FB70034 */  lw    $s7, 0x34($sp)
/* 0066FC 70005AFC 8FBE0038 */  lw    $fp, 0x38($sp)
/* 006700 70005B00 03E00008 */  jr    $ra
/* 006704 70005B04 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif
