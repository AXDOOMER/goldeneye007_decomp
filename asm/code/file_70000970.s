# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

set_stderr_activated:
/* 001570 70000970 3C018002 */  lui   $at, 0x8002
/* 001574 70000974 03E00008 */  jr    $ra
/* 001578 70000978 AC243098 */   sw    $a0, 0x3098($at)

set_stderr_enable:
/* 00157C 7000097C 3C018002 */  lui   $at, 0x8002
/* 001580 70000980 03E00008 */  jr    $ra
/* 001584 70000984 AC243094 */   sw    $a0, 0x3094($at)

set_stderr_permitted:
/* 001588 70000988 3C018002 */  lui   $at, 0x8002
/* 00158C 7000098C 03E00008 */  jr    $ra
/* 001590 70000990 AC24309C */   sw    $a0, 0x309c($at)

user_Compare:
/* 001594 70000994 3C018002 */  lui   $at, 0x8002
/* 001598 70000998 03E00008 */  jr    $ra
/* 00159C 7000099C AC2430A0 */   sw    $a0, 0x30a0($at)
