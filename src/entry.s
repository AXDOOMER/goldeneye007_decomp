# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"
.equ _BSS_START, 0x8005d2e0
.equ _BSS_END, 0x8008e360
.set _BSS_SIZE, (_BSS_END-_BSS_START)
/*
here we setup and clear bss, then jump to establish root tlb
*/
.global entry
entry:
/* 001000 80000400 3C088006 */  lui   $t0, %hi(_BSS_START)+1
/* 001004 80000404 3C090003 */  lui   $t1, %hi(_BSS_SIZE)
/* 001008 80000408 2508D2E0 */  addiu $t0, $t0, %lo(_BSS_START)
/* 00100C 8000040C 35291080 */  ori   $t1, $t1, %lo(_BSS_SIZE)
.Lentry_10:
/* 001010 80000410 2129FFF8 */  addi  $t1, $t1, -8
/* 001014 80000414 AD000000 */  sw    $zero, 0($t0)
/* 001018 80000418 AD000004 */  sw    $zero, 4($t0)
/* 00101C 8000041C 1520FFFC */  bnez  $t1, .Lentry_10
/* 001020 80000420 21080008 */  addi  $t0, $t0, 8
/* 001024 80000424 3C0A8000 */  lui   $t2, %hi(establishrootTLB)
/* 001028 80000428 3C1D803B */  lui   $sp, 0x803b
/* 00102C 8000042C 254A0450 */  addiu $t2, $t2, %lo(establishrootTLB)
/* 001030 80000430 01400008 */  jr    $t2
/* 001034 80000434 27BDB410 */  addiu $sp, $sp, -0x4bf0 #set stack to 0x803AB410 (sp_rmon)
# end entry

# alignment
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000
.word 0x00000000, 0x00000000

/*
here we set tlb and jump to init
*/
.global establishrootTLB
establishrootTLB:
/* 001050 80000450 24020001 */  addiu $v0, $zero, 1
/* 001054 80000454 24030000 */  addiu $v1, $zero, 0
/* 001058 80000458 24040000 */  addiu $a0, $zero, 0
/* 00105C 8000045C 3C057000 */  lui   $a1, 0x7000
/* 001060 80000460 2406001F */  addiu $a2, $zero, 0x1f
/* 001064 80000464 24070001 */  addiu $a3, $zero, 1
/* 001068 80000468 3C08007F */  lui   $t0, 0x7f
/* 00106C 8000046C 3508E000 */  ori   $t0, $t0, 0xe000
/* 001070 80000470 40820000 */  mtc0  $v0, $0
/* 001074 80000474 00031B02 */  srl   $v1, $v1, 0xc
/* 001078 80000478 00031980 */  sll   $v1, $v1, 6
/* 00107C 8000047C 00661821 */  addu  $v1, $v1, $a2
/* 001080 80000480 40831000 */  mtc0  $v1, $2
/* 001084 80000484 00042302 */  srl   $a0, $a0, 0xc
/* 001088 80000488 00042180 */  sll   $a0, $a0, 6
/* 00108C 8000048C 00872021 */  addu  $a0, $a0, $a3
/* 001090 80000490 40841800 */  mtc0  $a0, $3
/* 001094 80000494 00052342 */  srl   $a0, $a1, 0xd
/* 001098 80000498 00042340 */  sll   $a0, $a0, 0xd
/* 00109C 8000049C 40845000 */  mtc0  $a0, $10
/* 0010A0 800004A0 40882800 */  mtc0  $t0, $5
/* 0010A4 800004A4 00000000 */  nop   
/* 0010A8 800004A8 42000002 */  tlbwi 
/* 0010AC 800004AC 3C0A7000 */  lui   $t2, %hi(init)
/* 0010B0 800004B0 254A0510 */  addiu $t2, $t2, %lo(init)
/* 0010B4 800004B4 01400008 */  jr    $t2
/* 0010B8 800004B8 00000000 */  nop   
# end establishrootTLB



