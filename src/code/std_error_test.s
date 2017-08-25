# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

.global set_stderr_activated
set_stderr_activated:
/* 001570 70000970 3C018002 */  lui   $at, %hi(stderr.activated)
/* 001574 70000974 03E00008 */  jr    $ra
/* 001578 70000978 AC243098 */  sw    $a0, %lo(stderr.activated)($at) # $a0, 0x3098($at)
# end set_stderr_activated

.global set_stderr_enable
set_stderr_enable:
/* 00157C 7000097C 3C018002 */  lui   $at, %hi(stderr.enable)
/* 001580 70000980 03E00008 */  jr    $ra
/* 001584 70000984 AC243094 */  sw    $a0, %lo(stderr.enable)($at) # $a0, 0x3094($at)
# end set_stderr_enable

.global set_stderr_permitted
set_stderr_permitted:
/* 001588 70000988 3C018002 */  lui   $at, %hi(stderr.permitted)
/* 00158C 7000098C 03E00008 */  jr    $ra
/* 001590 70000990 AC24309C */  sw    $a0, %lo(stderr.permitted)($at) # $a0, 0x309c($at)
# end set_stderr_permitted

.global set_user_compare
set_user_compare:
/* 001594 70000994 3C018002 */  lui   $at, %hi(user.compare)
/* 001598 70000998 03E00008 */  jr    $ra
/* 00159C 7000099C AC2430A0 */  sw    $a0, %lo(user.compare)($at) # $a0, 0x30a0($at)
# end set_user_compare

.global testtodisplaystderrandupdatecount
testtodisplaystderrandupdatecount:
/* 0015A0 700009A0 3C0E8002 */  lui   $t6, %hi(stderr.permitted)
/* 0015A4 700009A4 8DCE309C */  lw    $t6, %lo(stderr.permitted)($t6)
/* 0015A8 700009A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0015AC 700009AC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0015B0 700009B0 11C00003 */  beqz  $t6, .Ltesttodisplaystderrandupdatecount_20
/* 0015B4 700009B4 3C0F8002 */  lui   $t7, %hi(stderr.activated)
/* 0015B8 700009B8 8DEF3098 */  lw    $t7, %lo(stderr.activated)($t7)
/* 0015BC 700009BC 15E00004 */  bnez  $t7, .Ltesttodisplaystderrandupdatecount_30
.Ltesttodisplaystderrandupdatecount_20:
/* 0015C0 700009C0 3C188002 */  lui   $t8, %hi(stderr.enable)
/* 0015C4 700009C4 8F183094 */  lw    $t8, %lo(stderr.enable)($t8)
/* 0015C8 700009C8 53000008 */  beql  $t8, $zero, .Ltesttodisplaystderrandupdatecount_4C
/* 0015CC 700009CC 8FBF0014 */  lw    $ra, 0x14($sp)
.Ltesttodisplaystderrandupdatecount_30:
/* 0015D0 700009D0 0C001674 */  jal   proc_700059D0
/* 0015D4 700009D4 00000000 */  nop   
/* 0015D8 700009D8 0C003638 */  jal   osGetCount
/* 0015DC 700009DC 00000000 */  nop   
/* 0015E0 700009E0 3C018002 */  lui   $at, %hi(currentcount)
/* 0015E4 700009E4 AC2230A4 */  sw    $v0, %lo(currentcount)($at) # $v0, 0x30a4($at)
/* 0015E8 700009E8 8FBF0014 */  lw    $ra, 0x14($sp)
.Ltesttodisplaystderrandupdatecount_4C:
/* 0015EC 700009EC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0015F0 700009F0 03E00008 */  jr    $ra
/* 0015F4 700009F4 00000000 */  nop   
# end testtodisplaystderrandupdatecount

.global testtodisplaystderrorevery16thframe
testtodisplaystderrorevery16thframe:
/* 0015F8 700009F8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0015FC 700009FC 308E000F */  andi  $t6, $a0, 0xf
/* 001600 70000A00 15C0001D */  bnez  $t6, .Ltesttodisplaystderrorevery16thframe_80
/* 001604 70000A04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 001608 70000A08 3C0F8002 */  lui   $t7, %hi(stderr.permitted)
/* 00160C 70000A0C 8DEF309C */  lw    $t7, %lo(stderr.permitted)($t7)
/* 001610 70000A10 3C188002 */  lui   $t8, %hi(stderr.activated)
/* 001614 70000A14 3C198002 */  lui   $t9, %hi(stderr.enable)
/* 001618 70000A18 11E00004 */  beqz  $t7, .Ltesttodisplaystderrorevery16thframe_34
/* 00161C 70000A1C 00000000 */  nop   
/* 001620 70000A20 8F183098 */  lw    $t8, %lo(stderr.activated)($t8)
/* 001624 70000A24 17000004 */  bnez  $t8, .Ltesttodisplaystderrorevery16thframe_40
/* 001628 70000A28 00000000 */  nop   
.Ltesttodisplaystderrorevery16thframe_34:
/* 00162C 70000A2C 8F393094 */  lw    $t9, %lo(stderr.enable)($t9)
/* 001630 70000A30 53200012 */  beql  $t9, $zero, .Ltesttodisplaystderrorevery16thframe_84
/* 001634 70000A34 8FBF0014 */  lw    $ra, 0x14($sp)
.Ltesttodisplaystderrorevery16thframe_40:
/* 001638 70000A38 0C003638 */  jal   osGetCount
/* 00163C 70000A3C 00000000 */  nop   
/* 001640 70000A40 3C098002 */  lui   $t1, %hi(currentcount)
/* 001644 70000A44 8D2930A4 */  lw    $t1, %lo(currentcount)($t1)
/* 001648 70000A48 3C088002 */  lui   $t0, %hi(user.compare)
/* 00164C 70000A4C 8D0830A0 */  lw    $t0, %lo(user.compare)($t0)
/* 001650 70000A50 00495023 */  subu  $t2, $v0, $t1
/* 001654 70000A54 3C04803B */  lui   $a0, 0x803b
/* 001658 70000A58 010A082B */  sltu  $at, $t0, $t2
/* 00165C 70000A5C 50200007 */  beql  $at, $zero, .Ltesttodisplaystderrorevery16thframe_84
/* 001660 70000A60 8FBF0014 */  lw    $ra, 0x14($sp)
/* 001664 70000A64 0C001674 */  jal   proc_700059D0
/* 001668 70000A68 24845000 */  addiu $a0, $a0, 0x5000
/* 00166C 70000A6C 3C04803E */  lui   $a0, 0x803e
/* 001670 70000A70 0C001674 */  jal   proc_700059D0
/* 001674 70000A74 2484A800 */  addiu $a0, $a0, -0x5800
.Ltesttodisplaystderrorevery16thframe_80:
/* 001678 70000A78 8FBF0014 */  lw    $ra, 0x14($sp)
.Ltesttodisplaystderrorevery16thframe_84:
/* 00167C 70000A7C 27BD0018 */  addiu $sp, $sp, 0x18
/* 001680 70000A80 03E00008 */  jr    $ra
/* 001684 70000A84 00000000 */  nop   
# end testtodisplaystderrorevery16thframe


.section .data

stderr.enable:
#referenced by set_stderr_enable, testtodisplaystderrandupdatecount, testtodisplaystderrorevery16thframe
.word 0x00000000

stderr.activated:
#referenced by set_stderr_activated, testtodisplaystderrandupdatecount, testtodisplaystderrorevery16thframe
.word 0x00000000

stderr.permitted:
#referenced by set_stderr_permitted, testtodisplaystderrandupdatecount, testtodisplaystderrorevery16thframe
.word 0x00000000

user.compare:
#referenced by set_user_compare, testtodisplaystderrorevery16thframe
.word 0x02AEA540

currentcount:
#referenced by testtodisplaystderrandupdatecount, testtodisplaystderrorevery16thframe, storecurrentcount
.word 0x00000000


