.macro get_value name, value
.global get_\name
get_\name:
 lui   $v0, %hi(\value)
 jr    $ra
 addiu $v0, $v0, %lo(\value)
.endm

.macro jump_via_reg location, register=$a3
.global jump_\location
jump_\location:
 lui   \register, %hi(\location)
 addiu \register, \register, %lo(\location)
 jr    \register
 nop
.endm

.section .data

#referenced by proc_700006FC
unknown_init_val:
.word 0x00000002

#referenced by proc_700006FC
cart_hw_address:
.word 0x10000000

.section .data

.macro debug_handler_table_entry sp, string
 .word \sp
 .word \string
.endm

#referenced by setuplastentryofdebughandler
debug_handler_table:
 debug_handler_table_entry sp_boot, aBoot
 debug_handler_table_entry sp_rmon, aRmon
 debug_handler_table_entry sp_idle, aIdle
 debug_handler_table_entry sp_shed, aShed
 debug_handler_table_entry sp_main, aMain
 debug_handler_table_entry sp_audi, aAudi
debug_handler_table_end:

.word 0x00000000
.word 0x00000000
.word 0x00000000
.word 0x00000000
.word 0x00000000
.word 0x00000000



.section .rdata

aBoot: .asciiz "boot"
 .align 2

aRmon: .asciiz "rmon"
 .align 2

aIdle: .asciiz "idle"
 .align 2

aShed: .asciiz "shed"
 .align 2

aMain: .asciiz "main"
 .align 2

aAudi: .asciiz "audi"
 .align 2

.section .bss   
.global _BSS_START   
_BSS_START:    
/*.space 0x31080*/   
.comm rmonthread, 0x1B0 #0x8005D2E0
.comm idlethread, 0x1B0 #0x8005D490
.comm mainthread, 0x1B0 #0x8005D640
.comm shedthread, 0x1B0 #0x8005D7F0

.section .stack, "aw"
rarezip_buffer: .space 0xAB400
sp_boot: .space 0x10
sp_rmon: .space 0x300
sp_idle: .space 0x40
sp_shed: .space 0x200
sp_main: .space 0x8000
sp_audi: .space 0x1000
sp_debug: .space 0x6B0
