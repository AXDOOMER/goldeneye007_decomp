# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

.macro get_value name, value
.global get_\name
get_\name:
 lui   $v0, %hi(\value)
 jr    $ra
 addiu $v0, $v0, %lo(\value)
.endm


/*
use macro get_value name value 
makes a function called
get_name returning value in $v0
*/
get_value rodata_vaddr _DATA_START
get_value rodata_rom_start Compressedrodata
get_value rodata_rom_end Compressedrodata_end
get_value RareZipASMRomstart 0x33590
get_value RareZipASMRomend 0x34b30


.macro jump_via_reg location, register=$a3
.global jump_\location
jump_\location:
 lui   \register, %hi(\location)
 addiu \register, \register, %lo(\location)
 jr    \register
 nop
.endm


/*
use macro jump_via_reg location register
makes a function called jump_location
which jumps using register for location
*/
jump_via_reg decompress.entry

# alignment
.word 0x00000000, 0x00000000

.global init
init:
/* 001110 70000510 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 001114 70000514 AFBF0024 */  sw    $ra, 0x24($sp)
/* 001118 70000518 AFB10020 */  sw    $s1, 0x20($sp)
/* 00111C 7000051C 0C00012F */  jal   get_rodata_vaddr
/* 001120 70000520 AFB0001C */  sw    $s0, 0x1c($sp) 
/* 001124 70000524 0C000132 */  jal   get_rodata_rom_start
/* 001128 70000528 00408025 */  or    $s0, $v0, $zero #store rodata_vaddr to $s0
/* 00112C 7000052C 0C000135 */  jal   get_rodata_rom_end
/* 001130 70000530 AFA20034 */  sw    $v0, 0x34($sp) 
/* 001134 70000534 8FAE0034 */  lw    $t6, 0x34($sp)
/* 001138 70000538 0C000138 */  jal   get_RareZipASMRomstart
/* 00113C 7000053C 004E8823 */  subu  $s1, $v0, $t6
/* 001140 70000540 0C00013B */  jal   get_RareZipASMRomend
/* 001144 70000544 AFA20028 */  sw    $v0, 0x28($sp)
/* 001148 70000548 8FAF0028 */  lw    $t7, 0x28($sp)
/* 00114C 7000054C 3C0A7020 */  lui   $t2, 0x7020
/* 001150 70000550 02002825 */  or    $a1, $s0, $zero
/* 001154 70000554 004FC023 */  subu  $t8, $v0, $t7
/* 001158 70000558 02382021 */  addu  $a0, $s1, $t8
/* 00115C 7000055C 2483FFFF */  addiu $v1, $a0, -1
/* 001160 70000560 0460000A */  bltz  $v1, .Linit_7C
/* 001164 70000564 3C068030 */  lui   $a2, 0x8030
/* 001168 70000568 3C197020 */  lui   $t9, 0x7020
/* 00116C 7000056C 03312023 */  subu  $a0, $t9, $s1
/* 001170 70000570 02031021 */  addu  $v0, $s0, $v1
.Linit_64:
/* 001174 70000574 90480000 */  lbu   $t0, ($v0)
/* 001178 70000578 00834821 */  addu  $t1, $a0, $v1
/* 00117C 7000057C 2463FFFF */  addiu $v1, $v1, -1
/* 001180 70000580 2442FFFF */  addiu $v0, $v0, -1
/* 001184 70000584 0461FFFB */  bgez  $v1, .Linit_64
/* 001188 70000588 A1280000 */  sb    $t0, ($t1)
.Linit_7C:
/* 00118C 7000058C 0C00013E */  jal   jump_decompress.entry
/* 001190 70000590 01512023 */  subu  $a0, $t2, $s1
/* 001194 70000594 3C0B0003 */  lui   $t3, 3
/* 001198 70000598 3C0C0000 */  lui   $t4, 0
/* 00119C 7000059C 258C1050 */  addiu $t4, $t4, 0x1050
/* 0011A0 700005A0 256B3590 */  addiu $t3, $t3, 0x3590
/* 0011A4 700005A4 3C01000F */  lui   $at, 0xf
/* 0011A8 700005A8 3421FFB1 */  ori   $at, $at, 0xffb1
/* 0011AC 700005AC 016C1023 */  subu  $v0, $t3, $t4
/* 0011B0 700005B0 0041082A */  slt   $at, $v0, $at
/* 0011B4 700005B4 14200013 */  bnez  $at, .Linit_F4
/* 0011B8 700005B8 3C01FFF0 */  lui   $at, 0xfff0
/* 0011BC 700005BC 34210050 */  ori   $at, $at, 0x50
/* 0011C0 700005C0 3C050010 */  lui   $a1, 0x10
/* 0011C4 700005C4 3C067010 */  lui   $a2, 0x7010
/* 0011C8 700005C8 24C60400 */  addiu $a2, $a2, 0x400
/* 0011CC 700005CC 24A51000 */  addiu $a1, $a1, 0x1000
/* 0011D0 700005D0 00413821 */  addu  $a3, $v0, $at
/* 0011D4 700005D4 0C0033E4 */  jal   osPiRawStartDma
/* 0011D8 700005D8 00002025 */  or    $a0, $zero, $zero
/* 0011DC 700005DC 0C00341C */  jal   osPiGetStatus
/* 0011E0 700005E0 00000000 */  nop   
/* 0011E4 700005E4 304D0001 */  andi  $t5, $v0, 1
/* 0011E8 700005E8 11A00006 */  beqz  $t5, .Linit_F4
/* 0011EC 700005EC 00000000 */  nop   
.Linit_E0:
/* 0011F0 700005F0 0C00341C */  jal   osPiGetStatus
/* 0011F4 700005F4 00000000 */  nop   
/* 0011F8 700005F8 304E0001 */  andi  $t6, $v0, 1
/* 0011FC 700005FC 15C0FFFC */  bnez  $t6, .Linit_E0
/* 001200 70000600 00000000 */  nop   
.Linit_F4:
/* 001204 70000604 0C003420 */  jal   osInitialize
/* 001208 70000608 00000000 */  nop   
/* 00120C 7000060C 0C0006EC */  jal   set_hardwire_TLB_to_2
/* 001210 70000610 00000000 */  nop   
/* 001214 70000614 3C108000 */  lui   $s0, 0x8000
/* 001218 70000618 3C027000 */  lui   $v0, 0x7000
/* 00121C 7000061C 3C048000 */  lui   $a0, 0x8000
/* 001220 70000620 24421B60 */  addiu $v0, $v0, 0x1b60
/* 001224 70000624 02001825 */  or    $v1, $s0, $zero
/* 001228 70000628 34840080 */  ori   $a0, $a0, 0x80
.Linit_11C:
/* 00122C 7000062C 8C4F0000 */  lw    $t7, ($v0)
/* 001230 70000630 24630010 */  addiu $v1, $v1, 0x10
/* 001234 70000634 24420010 */  addiu $v0, $v0, 0x10
/* 001238 70000638 AC6FFFF0 */  sw    $t7, -0x10($v1)
/* 00123C 7000063C 8C58FFF4 */  lw    $t8, -0xc($v0)
/* 001240 70000640 AC78FFF4 */  sw    $t8, -0xc($v1)
/* 001244 70000644 8C59FFF8 */  lw    $t9, -8($v0)
/* 001248 70000648 AC79FFF8 */  sw    $t9, -8($v1)
/* 00124C 7000064C 8C48FFFC */  lw    $t0, -4($v0)
/* 001250 70000650 1464FFF6 */  bne   $v1, $a0, .Linit_11C
/* 001254 70000654 AC68FFFC */  sw    $t0, -4($v1)
/* 001258 70000658 0C0034C8 */  jal   osWritebackDCacheAll
/* 00125C 7000065C 00000000 */  nop   
/* 001260 70000660 02002025 */  or    $a0, $s0, $zero
/* 001264 70000664 0C0034D4 */  jal   osInvalICache
/* 001268 70000668 24054000 */  addiu $a1, $zero, 0x4000
/* 00126C 7000066C 24100002 */  addiu $s0, $zero, 2
/* 001270 70000670 24110020 */  addiu $s1, $zero, 0x20
.Linit_164:
/* 001274 70000674 0C0034F4 */  jal   osUnmapTLB
/* 001278 70000678 02002025 */  or    $a0, $s0, $zero
/* 00127C 7000067C 26100001 */  addiu $s0, $s0, 1
/* 001280 70000680 1611FFFC */  bne   $s0, $s1, .Linit_164
/* 001284 70000684 00000000 */  nop   
/* 001288 70000688 0C003504 */  jal   __osGetFpcCsr
/* 00128C 7000068C 00000000 */  nop   
/* 001290 70000690 0C003508 */  jal   __osSetFpcCsr
/* 001294 70000694 34440E80 */  ori   $a0, $v0, 0xe80
/* 001298 70000698 3C04803B */  lui   $a0, 0x803b
/* 00129C 7000069C 2484B950 */  addiu $a0, $a0, -0x46b0
/* 0012A0 700006A0 0C0001BC */  jal   grow_stack
/* 0012A4 700006A4 34058000 */  ori   $a1, $zero, 0x8000
/* 0012A8 700006A8 3C108006 */  lui   $s0, 0x8006
/* 0012AC 700006AC 2610D640 */  addiu $s0, $s0, -0x29c0
/* 0012B0 700006B0 3C067000 */  lui   $a2, %hi(main_entry)
/* 0012B4 700006B4 240C000A */  addiu $t4, $zero, 0xa
/* 0012B8 700006B8 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0012BC 700006BC 24C6089C */  addiu $a2, $a2, %lo(main_entry)
/* 0012C0 700006C0 02002025 */  or    $a0, $s0, $zero
/* 0012C4 700006C4 24050003 */  addiu $a1, $zero, 3
/* 0012C8 700006C8 00003825 */  or    $a3, $zero, $zero
/* 0012CC 700006CC 0C00350C */  jal   osCreateThread
/* 0012D0 700006D0 AFA20010 */  sw    $v0, 0x10($sp)
/* 0012D4 700006D4 0C003560 */  jal   osStartThread
/* 0012D8 700006D8 02002025 */  or    $a0, $s0, $zero
/* 0012DC 700006DC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0012E0 700006E0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0012E4 700006E4 8FB10020 */  lw    $s1, 0x20($sp)
/* 0012E8 700006E8 03E00008 */  jr    $ra
/* 0012EC 700006EC 27BD0040 */  addiu $sp, $sp, 0x40
# end init

.section .data
.global _DATA_START
_DATA_START:
rspcode:
.incbin "bin/rspcode.bin"
rspcode_end:
