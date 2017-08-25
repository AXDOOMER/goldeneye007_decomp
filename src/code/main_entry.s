# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

.global main_entry
main_entry:
/* 00149C 7000089C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0014A0 700008A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0014A4 700008A4 0C0001CE */  jal   start_idle_thread
/* 0014A8 700008A8 AFA40018 */  sw    $a0, 0x18($sp)
/* 0014AC 700008AC 0C002B4C */  jal   proc_7000AD30
/* 0014B0 700008B0 00000000 */  nop   
/* 0014B4 700008B4 0C002B3C */  jal   start_pi_manager
/* 0014B8 700008B8 00000000 */  nop   
/* 0014BC 700008BC 0C0001E4 */  jal   start_rmon_thread
/* 0014C0 700008C0 00000000 */  nop   
/* 0014C4 700008C4 0C002970 */  jal   check_boot_switches
/* 0014C8 700008C8 00000000 */  nop   
/* 0014CC 700008CC 50400004 */  beql  $v0, $zero, .Lmain_entry_44
/* 0014D0 700008D0 00002025 */  or    $a0, $zero, $zero
/* 0014D4 700008D4 0C0035D0 */  jal   osStopThread
/* 0014D8 700008D8 00002025 */  or    $a0, $zero, $zero
/* 0014DC 700008DC 00002025 */  or    $a0, $zero, $zero
.Lmain_entry_44:
/* 0014E0 700008E0 0C003600 */  jal   osSetThreadPri
/* 0014E4 700008E4 2405000A */  addiu $a1, $zero, 0xa
/* 0014E8 700008E8 0C0001FB */  jal   setup_message_queue_for_scheduler
/* 0014EC 700008EC 00000000 */  nop   
/* 0014F0 700008F0 0C001807 */  jal   setup_gamevalues_and_launchmainloop
/* 0014F4 700008F4 00000000 */  nop   
/* 0014F8 700008F8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0014FC 700008FC 27BD0018 */  addiu $sp, $sp, 0x18
/* 001500 70000900 03E00008 */  jr    $ra
/* 001504 70000904 00000000 */  nop   
# end main_entry


