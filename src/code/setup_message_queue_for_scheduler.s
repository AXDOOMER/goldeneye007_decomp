# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

.global setup_message_queue_for_scheduler
setup_message_queue_for_scheduler:
/* 0013EC 700007EC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0013F0 700007F0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0013F4 700007F4 3C048006 */  lui   $a0, 0x8006
/* 0013F8 700007F8 3C058006 */  lui   $a1, 0x8006
/* 0013FC 700007FC 24A5D9B8 */  addiu $a1, $a1, -0x2648
/* 001400 70000800 2484D9A0 */  addiu $a0, $a0, -0x2660
/* 001404 70000804 0C0035B4 */  jal   osCreateMesgQueue
/* 001408 70000808 24060020 */  addiu $a2, $zero, 0x20
/* 00140C 7000080C 3C0E8000 */  lui   $t6, 0x8000
/* 001410 70000810 8DCE0300 */  lw    $t6, 0x300($t6)
/* 001414 70000814 24010002 */  addiu $at, $zero, 2
/* 001418 70000818 3C048006 */  lui   $a0, 0x8006
/* 00141C 7000081C 15C1000A */  bne   $t6, $at, .Lsetup_message_queue_for_scheduler_5C
/* 001420 70000820 2484DA40 */  addiu $a0, $a0, -0x25c0
/* 001424 70000824 3C048006 */  lui   $a0, 0x8006
/* 001428 70000828 3C058006 */  lui   $a1, 0x8006
/* 00142C 7000082C 24A5D7F0 */  addiu $a1, $a1, -0x2810
/* 001430 70000830 2484DA40 */  addiu $a0, $a0, -0x25c0
/* 001434 70000834 2406001E */  addiu $a2, $zero, 0x1e
/* 001438 70000838 0C0002AB */  jal   scheduler
/* 00143C 7000083C 24070001 */  addiu $a3, $zero, 1
/* 001440 70000840 10000006 */  b     .Lsetup_message_queue_for_scheduler_70
/* 001444 70000844 00000000 */  nop   
.Lsetup_message_queue_for_scheduler_5C:
/* 001448 70000848 3C058006 */  lui   $a1, 0x8006
/* 00144C 7000084C 24A5D7F0 */  addiu $a1, $a1, -0x2810
/* 001450 70000850 24060002 */  addiu $a2, $zero, 2
/* 001454 70000854 0C0002AB */  jal   scheduler
/* 001458 70000858 24070001 */  addiu $a3, $zero, 1
.Lsetup_message_queue_for_scheduler_70:
/* 00145C 7000085C 3C048006 */  lui   $a0, 0x8006
/* 001460 70000860 3C058006 */  lui   $a1, 0x8006
/* 001464 70000864 3C068006 */  lui   $a2, 0x8006
/* 001468 70000868 24C6D9A0 */  addiu $a2, $a2, -0x2660
/* 00146C 7000086C 24A5DB18 */  addiu $a1, $a1, -0x24e8
/* 001470 70000870 2484DA40 */  addiu $a0, $a0, -0x25c0
/* 001474 70000874 0C000305 */  jal   proc_70000C14
/* 001478 70000878 00003825 */  or    $a3, $zero, $zero
/* 00147C 7000087C 3C048006 */  lui   $a0, 0x8006
/* 001480 70000880 0C00033E */  jal   proc_70000CF8
/* 001484 70000884 2484DA40 */  addiu $a0, $a0, -0x25c0
/* 001488 70000888 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00148C 7000088C 3C018006 */  lui   $at, 0x8006
/* 001490 70000890 AC22DA38 */  sw    $v0, %lo(0x8005DA38)($at) # $v0, -0x25c8($at)
/* 001494 70000894 03E00008 */  jr    $ra
/* 001498 70000898 27BD0018 */  addiu $sp, $sp, 0x18
# end setup_message_queue_for_scheduler

