# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

.global setuplastentryofdebughandler
setuplastentryofdebughandler:
/* 001508 70000908 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 00150C 7000090C 3C0E8002 */  lui   $t6, %hi(debug_handler_table)
/* 001510 70000910 27A30008 */  addiu $v1, $sp, 8
/* 001514 70000914 25CE304C */  addiu $t6, $t6, %lo(debug_handler_table)
/* 001518 70000918 25D90030 */  addiu $t9, $t6, (debug_handler_table_end-debug_handler_table)
/* 00151C 7000091C 00604025 */  or    $t0, $v1, $zero
.Lsetuplastentryofdebughandler_18:
/* 001520 70000920 8DC10000 */  lw    $at, ($t6)
/* 001524 70000924 25CE000C */  addiu $t6, $t6, 0xc
/* 001528 70000928 2508000C */  addiu $t0, $t0, 0xc
/* 00152C 7000092C AD01FFF4 */  sw    $at, -0xc($t0)
/* 001530 70000930 8DC1FFF8 */  lw    $at, -8($t6)
/* 001534 70000934 AD01FFF8 */  sw    $at, -8($t0)
/* 001538 70000938 8DC1FFFC */  lw    $at, -4($t6)
/* 00153C 7000093C 15D9FFF8 */  bne   $t6, $t9, .Lsetuplastentryofdebughandler_18
/* 001540 70000940 AD01FFFC */  sw    $at, -4($t0)
/* 001544 70000944 8DC10000 */  lw    $at, ($t6)
/* 001548 70000948 00601025 */  or    $v0, $v1, $zero
/* 00154C 7000094C AD010000 */  sw    $at, ($t0)
/* 001550 70000950 8DD90004 */  lw    $t9, 4($t6)
/* 001554 70000954 AD190004 */  sw    $t9, 4($t0)
/* 001558 70000958 8C490008 */  lw    $t1, 8($v0)
.Lsetuplastentryofdebughandler_54:
/* 00155C 7000095C 24420008 */  addiu $v0, $v0, 8
/* 001560 70000960 5520FFFE */  bnezl $t1, .Lsetuplastentryofdebughandler_54
/* 001564 70000964 8C490008 */  lw    $t1, 8($v0)
/* 001568 70000968 03E00008 */  jr    $ra
/* 00156C 7000096C 27BD0040 */  addiu $sp, $sp, 0x40
# end setuplastentryofdebughandler

.section .data

.macro debug_handler_table_entry sp, string
.word \sp
.word \string
.endm

#referenced by setuplastentryofdebughandler
debug_handler_table:
debug_handler_table_entry 0x803AB400, aBoot
debug_handler_table_entry 0x803AB410, aRmon
debug_handler_table_entry 0x803AB710, aIdle
debug_handler_table_entry 0x803AB750, aShed
debug_handler_table_entry 0x803AB950, aMain
debug_handler_table_entry 0x803B3950, aAudi
debug_handler_table_end:

.word 0x00000000
.word 0x00000000
.word 0x00000000
.word 0x00000000
.word 0x00000000
.word 0x00000000
