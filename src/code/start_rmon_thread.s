# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches


.section .text, "ax"

.global start_rmon_thread
start_rmon_thread:
/* 001390 70000790 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 001394 70000794 AFBF001C */  sw    $ra, 0x1c($sp)
/* 001398 70000798 3C04803B */  lui   $a0, 0x803b
/* 00139C 7000079C 2484B410 */  addiu $a0, $a0, -0x4bf0
/* 0013A0 700007A0 0C0001BC */  jal   grow_stack
/* 0013A4 700007A4 24050300 */  addiu $a1, $zero, 0x300
/* 0013A8 700007A8 3C048006 */  lui   $a0, 0x8006
/* 0013AC 700007AC 3C067001 */  lui   $a2, %hi(rmon_entry)
/* 0013B0 700007B0 240E00FA */  addiu $t6, $zero, 0xfa
/* 0013B4 700007B4 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0013B8 700007B8 24C6CEA0 */  addiu $a2, $a2, %lo(rmon_entry)
/* 0013BC 700007BC 2484D2E0 */  addiu $a0, $a0, -0x2d20
/* 0013C0 700007C0 00002825 */  or    $a1, $zero, $zero
/* 0013C4 700007C4 00003825 */  or    $a3, $zero, $zero
/* 0013C8 700007C8 0C00350C */  jal   osCreateThread
/* 0013CC 700007CC AFA20010 */  sw    $v0, 0x10($sp)
/* 0013D0 700007D0 3C048006 */  lui   $a0, 0x8006
/* 0013D4 700007D4 0C003560 */  jal   osStartThread
/* 0013D8 700007D8 2484D2E0 */  addiu $a0, $a0, -0x2d20
/* 0013DC 700007DC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0013E0 700007E0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0013E4 700007E4 03E00008 */  jr    $ra
/* 0013E8 700007E8 00000000 */  nop   
# end start_rmon_thread
