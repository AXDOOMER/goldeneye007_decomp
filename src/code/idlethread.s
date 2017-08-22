# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

.global idle_entry
idle_entry:
/* 001318 70000718 AFA40000 */  sw    $a0, ($sp)
.Lidle_entry_4:
/* 00131C 7000071C 1000FFFF */  b     .Lidle_entry_4
/* 001320 70000720 00000000 */  nop   
# end idle_entry

# alignment
.word 0x00000000, 0x00000000, 0x00000000

.global dummy_70000730
dummy_70000730:
/* 001330 70000730 03E00008 */  jr    $ra
/* 001334 70000734 00000000 */  nop   
# end dummy_70000730

.global start_idle_thread
start_idle_thread:
/* 001338 70000738 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00133C 7000073C AFBF001C */  sw    $ra, 0x1c($sp)
/* 001340 70000740 3C04803B */  lui   $a0, 0x803b
/* 001344 70000744 2484B710 */  addiu $a0, $a0, -0x48f0
/* 001348 70000748 0C0001BC */  jal   grow_stack
/* 00134C 7000074C 24050040 */  addiu $a1, $zero, 0x40
/* 001350 70000750 3C048006 */  lui   $a0, 0x8006
/* 001354 70000754 3C067000 */  lui   $a2, %hi(idle_entry)
/* 001358 70000758 24C60718 */  addiu $a2, $a2, %lo(idle_entry)
/* 00135C 7000075C 2484D490 */  addiu $a0, $a0, -0x2b70
/* 001360 70000760 24050001 */  addiu $a1, $zero, 1
/* 001364 70000764 00003825 */  or    $a3, $zero, $zero
/* 001368 70000768 AFA20010 */  sw    $v0, 0x10($sp)
/* 00136C 7000076C 0C00350C */  jal   osCreateThread
/* 001370 70000770 AFA00014 */  sw    $zero, 0x14($sp)
/* 001374 70000774 3C048006 */  lui   $a0, 0x8006
/* 001378 70000778 0C003560 */  jal   osStartThread
/* 00137C 7000077C 2484D490 */  addiu $a0, $a0, -0x2b70
/* 001380 70000780 8FBF001C */  lw    $ra, 0x1c($sp)
/* 001384 70000784 27BD0020 */  addiu $sp, $sp, 0x20
/* 001388 70000788 03E00008 */  jr    $ra
/* 00138C 7000078C 00000000 */  nop   
# end start_idle_thread
