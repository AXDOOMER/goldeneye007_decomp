base $80000400
Start:
 lui t0, ((bss_start >> 16) + 1)
 lui t1, ((bss_end - bss_start) >> 16)
 addiu t0, t0, bss_start
 ori t1, t1, (bss_end - bss_start)

looptillclear:
 addi t1, t1, -8
 sw $0, 0(t0)
 sw $0, 4(t0)
 bnez t1, looptillclear
 addi t0, t0, $0008

 lui t2, (establishrootTLB >> 16)
 lui sp, ((sp_rmon >> 16) + 1) // 
 addiu t2, t2, establishrootTLB
 jr t2 //jr establishrootTLB
 addiu sp, sp, sp_rmon
 nop; nop; nop; nop; nop; nop;

establishrootTLB:
 addiu	v0, r0, $0001
 addiu	v1, r0, $0000
 addiu	a0, r0, $0000
 lui	a1, $7000
 addiu	a2, r0, $001F
 addiu	a3, r0, $0001
 lui	t0, (OS_PM_4M >> 16)
 ori	t0, t0, OS_PM_4M
 mtc0	v0, Index //COP0 Index = 1
 srl	v1,v1,0xC
 sll	v1,v1,0x6
 addu	v1,v1,a2 //v1=a2
 mtc0	v1,EntryLo0 //COP0 EntryLo0 = 1F: global, valid, dirty, cacheable noncoherent, even page#, map 00000000
 srl	a0,a0,0xC
 sll	a0,a0,0x6
 addu	a0,a0,a3 //a0=a3
 mtc0	a0,EntryLo1 //COP0 EntryLo1 = 1: global
 srl	a0,a1,0xD
 sll	a0,a0,0xD //a0=a1
 mtc0	a0,EntryHi //COP0 EntryHi = 70000000: address space 0, VPN 70000
 mtc0	t0,PageMask //COP0 PageMask= 007FE000: mask for 2000byte entries up to 4MB
 nop
 tlbwi

 lui	t2, (init >> 16)
 addiu	t2, t2, init
 jr	t2 //jr init
 nop

base $700004BC
set_rodata_vaddr:
lui v0, (rodata_start >> 16)
jr ra
addiu v0, v0, rodata_start

set_rodata_rom_start:
lui v0, (rodata_rom_start >> 16)
jr ra
addiu v0, v0, rodata_rom_start //v0=21990

set_rodata_rom_end:
lui v0, (rodata_rom_end >> 16)
jr ra
addiu v0, v0, rodata_rom_end //v0=33590

setRareZip_start:
lui v0, (rarezip_rom_start >> 16)
jr ra
addiu v0, v0, rarezip_rom_start //v0=33590

setRareZip_end:
lui v0, (rarezip_rom_end >> 16)
jr ra
addiu v0, v0, rarezip_rom_end //v0=34B30

redirecttodecompressfile:
//accepts: a0=p->source, a1=p->target, a2=p->buffer
lui a3,(decompressfile >> 16)
addiu a3, a3, decompressfile
jr a3

nop; nop; nop;

init:
//decompress main compressed block, initialize memory, TLB and its interrupts,
// then execute main game thread
addiu sp, sp, $FFC0
sw ra, $0024(sp)
sw s1, $0020(sp)
jal set_rodata_vaddr //v0=80020D90: target address for main compressed block (21990)
sw s0, $001C(sp)

jal set_rodata_rom_start //v0=21990: ROM address of main compressed block
or s0, v0, r0 //s0=v0: 80020D90

jal set_rodata_rom_end //v0=33590: ROM endpoint of main compressed block
sw v0, $0034(sp) //sp+34= main.pos

lw t6, $0034(sp)
jal setRareZip_start
subu s1, v0, t6 //s1=v0-t6: compressed size of main compressed block

jal setRareZip_end
sw v0, $0028(sp) //sp+28= RareZip.pos

lw t7, $0028(sp)
lui t2, (RareZip_vaddr >> 16)	 //t2=70200000: target vaddress for RareZip
or a1, s0, r0 //a1=s0: target address for main.bin
subu t8, v0, t7 //t8=v0-t7: RareZip.sz = RareZip.end - RareZip.pos
addu a0, s1, t8 //a0=s1+t8: main.cmp_sz + RareZip.sz
addiu v1, a0, -1 //v1= total size - 1
bltz v1, do_decompress //skip if nothing to copy
lui a2, (decompression_buffer >> 16)	 //a2=80300000: buffer for decompression tables
lui t9, (RareZip_vaddr >> 16)
subu a0, t9, s1 //a0=70200000 - main.cmp_sz: vaddr for main
addu v0, s0, v1 //v0=s0+v1: target address + total size

loop:	
//loop to copy from source to virtual target instead of mapping...
lbu t0, $0000(v0)
addu t1, a0, v1
addiu v1, v1, $FFFF
addiu v0, v0, $FFFF
bgez v1, loop
sb t0, $0000(t1)

do_decompress:
//decompress main compressed block
jal redirecttodecompressfile //redirect to 7020141C: decompress a0 to a1// a2=buffer
subu a0, t2, s1 //a0=p->source: RareZip.vaddr - main.cmp_sz
//70000594:
lui t3, (rarezip_rom_start >> 16)
lui t4, $0000
addiu t4, t4, $1050 //t4=1050
addiu t3, t3, rarezip_rom_start //t3=33590: ROM address of 70200000 RareZip ASM [33590-34B30 ROM]
lui at, $000F
ori at, at, $FFB1 //at=FFFB1
subu v0, t3, t4 //v0=33590 - 1050: 32550
slt at, v0, at
bnez at, init_memory_tlb //branch if 32550 < FFFB1, which it always will be...
lui at, $FFF0
//700005BC:	on failure, presumes 64bit mapping, which would place exception handler at 100400, not 400
ori at, at, $0050 //at= -FFFB0
lui a1, $0010
lui a2, $7010
addiu a2, a2, $0400 //a2=70100400
addiu a1, a1, $1000 //a1=101000
addu a3, v0, at //a3= difference - FFFB0

jal osPiRawStartDma //read (a0) a3 bytes from ROM a1 to a2
or a0, r0, r0 //a0=0 (read)

jal $7000D070 //v0=PI status
nop

andi t5, v0, $0001
beqz t5, init_memory_tlb //branch if ready
nop

wait_pi_ready:
// wait until PI ready
jal $7000D070 //v0=PI status
nop
andi t6, v0, 0001
bnez t6, wait_pi_ready
nop

init_memory_tlb:
// initialize memory and TLB
jal $7000D080 //initialize PIF, interrupt handlers, C0- and 7F- TLB segments, init NMIbuffer if cold run, init 64DD if present
nop

jal $70001BB0 //sets #hardwired TLB entries to 2
nop

lui s0, $8000
lui v0, (tlb_entries >> 16)
lui a0, $8000
addiu v0, v0, tlb_entries //v0= 70001B60
or v1, s0, r0 //v1=s0: 80000000
ori a0, a0, $0080 //a0=80000080

copy_TLB_InvalidHit_handler:
// copy TLB InvalidHit handler to 80000080
lw t7, $0000(v0)
addiu v1, v1, $0010
addiu v0, v0, $0010
sw t7, $FFF0(v1)
lw t8, $FFF4(v0)
sw t8, $FFF4(v1)
lw t9, $FFF8(v0)
sw t9, $FFF8(v1)
lw t0, $FFFC(v0)
bne v1,a0,copy_TLB_InvalidHit_handler
sw t0, $FFFC(v1)

//70000658:
jal osWritebackDCacheAll //set Cache index writeback invalidate for 2000 bytes at 80000000
nop
or a0, s0, r0 //a0=s0: 80000000
jal osInvalICache //invalidate Cache for a1 bytes at a0
addiu a1, r0, $4000 //a1=4000
addiu s0, r0, $0002
addiu s1, r0, $0020

init_TLB_indicie_2_to_20:	
//init all TLB indices from 2-20
jal osUnmapTLB //remove TLB index a0
or a0, s0, r0 //a0=s0
addiu s0, s0, $0001 //s0++
bne s0, s1, init_TLB_indicie_2_to_20 //loop 15 times
nop

//70000688:	enable all but underflow in FPU
jal __osGetFpcCsr //v0= COP1 Control
nop

jal __osSetFpcCsr //v0=COP1 Control, replacing with a0
ori a0, v0, $0E80 //a0= v0 | E80: enable all but underflow

//70000698:
lui a0, ((sp_main >>16) +1)
addiu a0, a0, sp_main 

jal stack_init //v0= new stack pointer
ori a1, r0, $8000 //a1=8000

//700006A8:	generate main game thread
lui s0, ((mainthread >> 16) + 1)
addiu s0, s0, mainthread //s0= 8005D640
lui a2, (main >> 16)
addiu t4, r0, $000A
sw t4, $0014(sp) //sp+14= A
addiu a2, a2, main //a2= 7000089C: main game loop
or a0, s0, r0 //a0=s0: 8005D640: p->thread
addiu a1, r0, 0003 //a1=3
or a3, r0, r0 //a3=0
jal osCreateThread //initialize thread entry at a0 with values
sw v0, $0010(sp) //sp+10= stack pointer
jal osStartThread //insert thread and execute if no thread currently running
or a0, s0, r0 //a0=s0: 8005D640: p->table
lw ra, $0024(sp)
lw s0, $001C(sp)
lw s1, $0020(sp)
jr ra
addiu sp, sp, $0040

stack_init:
addu v0, a0, a1
jr ra
addiu v0, -8

base $700006FC
BOOT_700006FC:
addiu t6, $0, 0x1
lui at, 0x8002
sw t6, 0x3044 ( at )
lui at, 0x8002
lui t7, 0x1000
jr ra
sw t7, 0x3048 ( at )



base $70000718
function_70000718:
//0x70000718 -- 0x70000737
sw a0, 0x0 (sp)
b $7000071C //infinite loop
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0
jr ra
sll $0, $0, 0x0

base $70000738
makebootthread:
//0x70000738 -- 0x7000078f
addiu sp, sp, 0xffffffe0
sw ra, 0x1c (sp)
lui a0, 0x803b
addiu a0, a0, 0xffffb710
jal 0x700006f0 //(function_700006f0)
addiu a1, $0, 0x40
lui a0, 0x8006
lui a2, 0x7000
addiu a2, a2, 0x718
addiu a0, a0, 0xffffd490
addiu a1, $0, 0x1
or a3, $0, $0
sw v0, 0x10 (sp)
jal 0x7000d430 //(function_7000d430)
sw $0, 0x14 (sp)
lui a0, 0x8006
jal 0x7000d580 //(function_7000d580)
addiu a0, a0, 0xffffd490
lw ra, 0x1c (sp)
addiu sp, sp, 0x20
jr ra
sll $0, $0, 0x0

base $70000790
indiboard_thread:
//0x70000790 -- 0x700007eb
addiu sp, sp, 0xffffffe0
sw ra, 0x1c (sp)
lui a0, 0x803b
addiu a0, a0, 0xffffb410
jal 0x700006f0 //(function_700006f0)
addiu a1, $0, 0x300
lui a0, 0x8006
lui a2, 0x7001
addiu t6, $0, 0xfa
sw t6, 0x14 (sp)
addiu a2, a2, 0xffffcea0
addiu a0, a0, 0xffffd2e0
or a1, $0, $0
or a3, $0, $0
jal 0x7000d430 //(function_7000d430)
sw v0, 0x10 (sp)
lui a0, 0x8006
jal 0x7000d580 //(function_7000d580)
addiu a0, a0, 0xffffd2e0
lw ra, 0x1c (sp)
addiu sp, sp, 0x20
jr ra
sll $0, $0, 0x0

base $700007ec
function_700007ec:
//0x700007ec -- 0x7000089b
addiu sp, sp, 0xffffffe8
sw ra, 0x14 (sp)
lui a0, 0x8006
lui a1, 0x8006
addiu a1, a1, 0xffffd9b8
addiu a0, a0, 0xffffd9a0
jal 0x7000d6d0 //(function_7000d6d0)
addiu a2, $0, 0x20
lui t6, 0x8000
lw t6, 0x300 (t6)
addiu at, $0, 0x2
lui a0, 0x8006
bne t6, at, 0x70000848 //(function_700007ec+0x5c)
addiu a0, a0, 0xffffda40
lui a0, 0x8006
lui a1, 0x8006
addiu a1, a1, 0xffffd7f0
addiu a0, a0, 0xffffda40
addiu a2, $0, 0x1e
jal 0x70000aac //(scheduler)
addiu a3, $0, 0x1
beq $0, $0, 0x7000085c //(function_700007ec+0x70)
sll $0, $0, 0x0
lui a1, 0x8006
addiu a1, a1, 0xffffd7f0
addiu a2, $0, 0x2
jal 0x70000aac //(scheduler)
addiu a3, $0, 0x1
lui a0, 0x8006
lui a1, 0x8006
lui a2, 0x8006
addiu a2, a2, 0xffffd9a0
addiu a1, a1, 0xffffdb18
addiu a0, a0, 0xffffda40
jal 0x70000c14 //(function_70000c14)
or a3, $0, $0
lui a0, 0x8006
jal 0x70000cf8 //(function_70000cf8)
addiu a0, a0, 0xffffda40
lw ra, 0x14 (sp)
lui at, 0x8006
sw v0, 0xffffda38 (at)
jr ra
addiu sp, sp, 0x18

base $7000089c
main:
//0x7000089c -- 0x70000907
addiu sp, sp, 0xffffffe8
sw ra, 0x14 (sp)
jal 0x70000738 //(makebootthread)
sw a0, 0x18 (sp)
jal 0x7000ad30 //(function_7000ad30)
sll $0, $0, 0x0
jal 0x7000acf0 //(function_7000acf0)
sll $0, $0, 0x0
jal 0x70000790 //(indiboard_thread)
sll $0, $0, 0x0
jal 0x7000a5c0 //(function_7000a5c0)
sll $0, $0, 0x0
beql v0, r0, 0x700008E0 //(main+0x44)
or a0, $0, $0
jal 0x7000d740 //(function_7000d740)
or a0, $0, $0
or a0, $0, $0
jal 0x7000d800 //(function_7000d800)
addiu a1, $0, 0xa
jal 0x700007ec //(function_700007ec)
sll $0, $0, 0x0
jal 0x7000601c //(function_7000601c)
sll $0, $0, 0x0
lw ra, 0x14 (sp)
addiu sp, sp, 0x18
jr ra
sll $0, $0, 0x0

base $70000908
setuplastentryofdebughandler:
//0x70000908 -- 0x7000096f
addiu sp, sp, 0xffffffc0
lui t6, 0x8002
addiu v1, sp, 0x8
addiu t6, t6, 0x304c
addiu t9, t6, 0x30
or t0, v1, $0
lw at, 0x0 (t6)
addiu t6, t6, 0xc
addiu t0, t0, 0xc
sw at, 0xfffffff4 (t0)
lw at, 0xfffffff8 (t6)
sw at, 0xfffffff8 (t0)
lw at, 0xfffffffc (t6)
bne t6, t9, 0x70000920 //(setuplastentryofdebughandler+0x18)
sw at, 0xfffffffc (t0)
lw at, 0x0 (t6)
or v0, v1, $0
sw at, 0x0 (t0)
lw t9, 0x4 (t6)
sw t9, 0x4 (t0)
lw t1, 0x8 (v0)
addiu v0, v0, 0x8
bnel t1, r0, 0x7000095c //(setuplastentryofdebughandler+0x54)
lw t1, 0x8 (v0)
jr ra
addiu sp, sp, 0x40

base $70000970
stderr.activated:
//0x70000970 -- 0x7000097b
lui at, 0x8002
jr ra
sw a0, 0x3098 (at)

base $7000097c
stderr.enable:
//0x7000097c -- 0x70000987
lui at, 0x8002
jr ra
sw a0, 0x3094 (at)

base $70000988
stderr.permitted:
//0x70000988 -- 0x70000993
lui at, 0x8002
jr ra
sw a0, 0x309c (at)

base $70000994
user.compare:
//0x70000994 -- 0x7000099f
lui at, 0x8002
jr ra
sw a0, 0x30a0 (at)

base $700009a0
testtodisplaystderrandupdatecount:
//0x700009a0 -- 0x700009f7
lui t6, 0x8002
lw t6, 0x309c (t6)
addiu sp, sp, 0xffffffe8
sw ra, 0x14 (sp)
beq t6, r0, 0x700009c0 //(testtodisplaystderrandupdatecount+0x20)
lui t7, 0x8002
lw t7, 0x3098 (t7)
bne t7, r0, 0x700009d0 //(testtodisplaystderrandupdatecount+0x30)
lui t8, 0x8002
lw t8, 0x3094 (t8)
beql t8, r0, 0x700009ec //(testtodisplaystderrandupdatecount+0x4c)
lw ra, 0x14 (sp)
jal 0x700059d0 //(function_700059d0)
sll $0, $0, 0x0
jal 0x7000d8e0 //(function_7000d8e0)
sll $0, $0, 0x0
lui at, 0x8002
sw v0, 0x30a4 (at)
lw ra, 0x14 (sp)
addiu sp, sp, 0x18
jr ra
sll $0, $0, 0x0

base $700009f8
testtodisplaystderrorevery16thframe:
//0x700009f8 -- 0x70000a87
addiu sp, sp, 0xffffffe8
andi t6, a0, 0xf
bne t6, r0, 0x70000a78 //(testtodisplaystderrorevery16thframe+0x80)
sw ra, 0x14 (sp)
lui t7, 0x8002
lw t7, 0x309c (t7)
lui t8, 0x8002
lui t9, 0x8002
beq t7, r0, 0x70000a2c //(testtodisplaystderrorevery16thframe+0x34)
sll $0, $0, 0x0
lw t8, 0x3098 (t8)
bne t8, r0, 0x70000a38 //(testtodisplaystderrorevery16thframe+0x40)
sll $0, $0, 0x0
lw t9, 0x3094 (t9)
beql t9, r0, 0x70000a7c //(testtodisplaystderrorevery16thframe+0x84)
lw ra, 0x14 (sp)
jal 0x7000d8e0 //(function_7000d8e0)
sll $0, $0, 0x0
lui t1, 0x8002
lw t1, 0x30a4 (t1)
lui t0, 0x8002
lw t0, 0x30a0 (t0)
subu t2, v0, t1
lui a0, 0x803b
sltu at, t0, t2
beql at, r0, 0x70000a7c //(testtodisplaystderrorevery16thframe+0x84)
lw ra, 0x14 (sp)
jal 0x700059d0 //(function_700059d0)
addiu a0, a0, 0x5000
lui a0, 0x803e
jal 0x700059d0 //(function_700059d0)
addiu a0, a0, 0xffffa800
lw ra, 0x14 (sp)
addiu sp, sp, 0x18
jr ra
sll $0, $0, 0x0

base $70000a88
storecurrentcountto800230a4:
//0x70000a88 -- 0x70000aab
addiu sp, sp, 0xffffffe8
sw ra, 0x14 (sp)
jal 0x7000d8e0 //(function_7000d8e0)
sll $0, $0, 0x0
lw ra, 0x14 (sp)
lui at, 0x8002
sw v0, 0x30a4 (at)
jr ra
addiu sp, sp, 0x18

base $70000aac
scheduler:
//0x70000aac -- 0x70000c13
addiu sp, sp, 0xffffffd8
sw ra, 0x24 (sp)
sw s1, 0x20 (sp)
sw s0, 0x1c (sp)
sw a1, 0x2c (sp)
sw a2, 0x30 (sp)
sw a3, 0x34 (sp)
addiu t6, $0, 0x1
addiu t7, $0, 0x5
sw $0, 0xc8 (a0)
sw $0, 0xcc (a0)
sw $0, 0xb4 (a0)
sw $0, 0xd0 (a0)
sw $0, 0xb8 (a0)
sw $0, 0xbc (a0)
sw $0, 0xc0 (a0)
sw $0, 0xc4 (a0)
sh t6, 0x0 (a0)
sh t7, 0x20 (a0)
lw t8, 0x2c (sp)
or s0, a0, $0
addiu s1, a0, 0x40
sw t8, 0xb0 (a0)
or a0, s1, $0
addiu a1, s0, 0x58
jal 0x7000d6d0 //(function_7000d6d0)
addiu a2, $0, 0x8
addiu a0, s0, 0x78
addiu a1, s0, 0x90
jal 0x7000d6d0 //(function_7000d6d0)
addiu a2, $0, 0x8
jal 0x7000d8f0 //(function_7000d8f0)
addiu a0, $0, 0xfe
lbu t9, 0x33 (sp)
lui t1, 0x8002
lui v1, 0x8006
sll t0, t9, 0x2
addu t0, t0, t9
sll t0, t0, 0x4
addiu t1, t1, 0x69c0
addiu v1, v1, 0x87c
addu t2, t0, t1
sw t2, 0x0 (v1)
lw t3, 0x1c (t2)
lui at, 0x8006
addiu a0, $0, 0x4
sw t3, 0x880 (at)
lw t4, 0x30 (t2)
lui at, 0x8006
or a1, s1, $0
sw t4, 0x884 (at)
lw t5, 0x44 (t2)
lui at, 0x8006
addiu a2, $0, 0x29b
jal 0x7000dc50 //(function_7000dc50)
sw t5, 0x888 (at)
addiu a0, $0, 0x9
or a1, s1, $0
jal 0x7000dc50 //(function_7000dc50)
addiu a2, $0, 0x29c
addiu a0, $0, 0xe
or a1, s1, $0
jal 0x7000dc50 //(function_7000dc50)
addiu a2, $0, 0x29d
or a0, s1, $0
addiu a1, $0, 0x29a
jal 0x7000dcc0 //(function_7000dcc0)
lw a2, 0x34 (sp)
jal 0x70000a88 //(storecurrentcountto800230a4)
sll $0, $0, 0x0
lui a0, 0x803b
addiu a0, a0, 0xffffb750
jal 0x700006f0 //(function_700006f0)
addiu a1, $0, 0x200
lw a0, 0xb0 (s0)
lui a2, 0x7000
addiu t6, $0, 0x1e
sw t6, 0x14 (sp)
addiu a2, a2, 0xd00
sw v0, 0x10 (sp)
addiu a1, $0, 0x2
jal 0x7000d430 //(function_7000d430)
or a3, s0, $0
jal 0x7000d580 //(function_7000d580)
lw a0, 0xb0 (s0)
lw ra, 0x24 (sp)
lw s0, 0x1c (sp)
lw s1, 0x20 (sp)
jr ra
addiu sp, sp, 0x28

base $70000c14
function_70000c14:
//0x70000c14 -- 0x70000c6f
addiu sp, sp, 0xffffffe8
sw ra, 0x14 (sp)
sw a0, 0x18 (sp)
sw a2, 0x20 (sp)
sw a3, 0x24 (sp)
addiu a0, $0, 0x1
jal 0x7000dd30 //(function_7000dd30)
sw a1, 0x1c (sp)
lw a1, 0x1c (sp)
lw t6, 0x20 (sp)
lw v1, 0x18 (sp)
or a0, v0, $0
sw t6, 0x4 (a1)
lw t7, 0x24 (sp)
sw t7, 0x8 (a1)
lw t8, 0xb4 (v1)
sw t8, 0x0 (a1)
jal 0x7000dd30 //(function_7000dd30)
sw a1, 0xb4 (v1)
lw ra, 0x14 (sp)
addiu sp, sp, 0x18
jr ra
sll $0, $0, 0x0

base $70000c70
function_70000c70:
//0x70000c70 -- 0x70000cf7
addiu sp, sp, 0xffffffe0
sw ra, 0x14 (sp)
sw a0, 0x20 (sp)
lw v1, 0xb4 (a0)
sw $0, 0x18 (sp)
sw a1, 0x24 (sp)
addiu a0, $0, 0x1
jal 0x7000dd30 //(function_7000dd30)
sw v1, 0x1c (sp)
lw v1, 0x1c (sp)
lw a1, 0x24 (sp)
lw a2, 0x18 (sp)
beq v1, r0, 0x70000ce0 //(function_70000c70+0x70)
or a0, v0, $0
bnel v1, a1, 0x70000cd4 //(function_70000c70+0x64)
or a2, v1, $0
beq a2, r0, 0x70000cc4 //(function_70000c70+0x54)
lw t9, 0x20 (sp)
lw t7, 0x0 (a1)
beq $0, $0, 0x70000ce0 //(function_70000c70+0x70)
sw t7, 0x0 (a2)
lw t8, 0x0 (a1)
beq $0, $0, 0x70000ce0 //(function_70000c70+0x70)
sw t8, 0xb4 (t9)
or a2, v1, $0
lw v1, 0x0 (v1)
bne v1, r0, 0x70000ca8 //(function_70000c70+0x38)
sll $0, $0, 0x0
jal 0x7000dd30 //(function_7000dd30)
sll $0, $0, 0x0
lw ra, 0x14 (sp)
addiu sp, sp, 0x20
jr ra
sll $0, $0, 0x0

base $70000cf8
function_70000cf8:
//0x70000cf8 -- 0x70000cff
jr ra
addiu v0, a0, 0x78

base $70000d00
function_70000d00:
//0x70000d00 -- 0x70000eb3
addiu sp, sp, 0xffffffb0
sw s5, 0x28 (sp)
sw s4, 0x24 (sp)
sw s3, 0x20 (sp)
sw s2, 0x1c (sp)
sw s0, 0x14 (sp)
or s2, a0, $0
sw ra, 0x2c (sp)
sw s1, 0x18 (sp)
sw $0, 0x4c (sp)
or s0, $0, $0
addiu s3, a0, 0x40
addiu s4, sp, 0x4c
addiu s5, $0, 0x29a
or a0, s3, $0
or a1, s4, $0
jal 0x7000ddd0 //(function_7000ddd0)
addiu a2, $0, 0x1
lw t6, 0x4c (sp)
addiu at, $0, 0x29b
beq t6, s5, 0x70000d78 //(function_70000d00+0x78)
sll $0, $0, 0x0
beq t6, at, 0x70000d88 //(function_70000d00+0x88)
addiu at, $0, 0x29c
beq t6, at, 0x70000d98 //(function_70000d00+0x98)
addiu at, $0, 0x29d
beq t6, at, 0x70000da8 //(function_70000d00+0xa8)
sll $0, $0, 0x0
beq $0, $0, 0x70000de0 //(function_70000d00+0xe0)
sll $0, $0, 0x0
jal 0x70000eb4 //(function_70000eb4)
or a0, s2, $0
beq $0, $0, 0x70000de0 //(function_70000d00+0xe0)
sll $0, $0, 0x0
jal 0x70001014 //(function_70001014)
or a0, s2, $0
beq $0, $0, 0x70000de0 //(function_70000d00+0xe0)
sll $0, $0, 0x0
jal 0x70001128 //(function_70001128)
or a0, s2, $0
beq $0, $0, 0x70000de0 //(function_70000d00+0xe0)
sll $0, $0, 0x0
jal 0x7000c8dc //(function_7000c8dc)
sll $0, $0, 0x0
lw s0, 0xb4 (s2)
addiu s1, s2, 0x20
beql s0, r0, 0x70000de0 //(function_70000d00+0xe0)
addiu s0, $0, 0x1
lw a0, 0x4 (s0)
or a1, s1, $0
jal 0x7000df10 //(function_7000df10)
or a2, $0, $0
lw s0, 0x0 (s0)
bnel s0, r0, 0x70000dc4 //(function_70000d00+0xc4)
lw a0, 0x4 (s0)
addiu s0, $0, 0x1
beql s0, $0, 0x70000d3c
or a0, s3, $0
lui t7, 0x8000
lw t7, 0x300 (t7)
addiu at, $0, 0x2
lui a0, 0x8002
bne t7, at, 0x70000e14 //(function_70000d00+0x114)
sll $0, $0, 0x0
lui a0, 0x8002
jal 0x7000e060 //(function_7000e060)
addiu a0, a0, 0x7320
beq $0, $0, 0x70000e20 //(function_70000d00+0x120)
lui at, 0x3f80
jal 0x7000e060 //(function_7000e060)
addiu a0, a0, 0x6a60
lui at, 0x3f80
mtc1 at, f12
jal 0x7000e0d0 //(function_7000e0d0)
sll $0, $0, 0x0
lui at, 0x3f80
mtc1 at, f12
jal 0x7000e200 //(function_7000e200)
sll $0, $0, 0x0
jal 0x7000e260 //(function_7000e260)
or a0, $0, $0
jal 0x7000e2d0 //(function_7000e2d0)
addiu a0, $0, 0x1
or a0, s3, $0
or a1, s4, $0
jal 0x7000ddd0 //(function_7000ddd0)
addiu a2, $0, 0x1
lw t8, 0x4c (sp)
bnel t8, s5, 0x70000e50 //(function_70000d00+0x150)
or a0, s3, $0
jal 0x7000bd88 //(function_7000bd88)
sll $0, $0, 0x0
beq $0, $0, 0x70000e50 //(function_70000d00+0x150)
or a0, s3, $0
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0
lw ra, 0x2c (sp)
lw s0, 0x14 (sp)
lw s1, 0x18 (sp)
lw s2, 0x1c (sp)
lw s3, 0x20 (sp)
lw s4, 0x24 (sp)
lw s5, 0x28 (sp)
jr ra
addiu sp, sp, 0x50

base $70000eb4
function_70000eb4:
//0x70000eb4 -- 0x70001013
addiu sp, sp, 0xffffffc0
sw ra, 0x24 (sp)
sw s1, 0x18 (sp)
or s1, a0, $0
sw s3, 0x20 (sp)
sw s2, 0x1c (sp)
sw s0, 0x14 (sp)
sw $0, 0x3c (sp)
sw $0, 0x30 (sp)
jal 0x700027a4 //(function_700027a4)
sw $0, 0x2c (sp)
lw t6, 0xd0 (s1)
addiu t7, t6, 0x1
jal 0x700031a0 //(function_700031a0)
sw t7, 0xd0 (s1)
jal 0x7000bd88 //(function_7000bd88)
sll $0, $0, 0x0
jal 0x70007914 //(function_70007914)
sll $0, $0, 0x0
addiu s3, sp, 0x3c
addiu s2, s1, 0x78
or a0, s2, $0
or a1, s3, $0
jal 0x7000ddd0 //(function_7000ddd0)
or a2, $0, $0
addiu s0, $0, 0xffffffff
beq v0, s0, 0x70000f44 //(function_70000eb4+0x90)
or a0, s1, $0
jal 0x700013d8 //(function_700013d8)
lw a1, 0x3c (sp)
or a0, s2, $0
or a1, s3, $0
jal 0x7000ddd0 //(function_7000ddd0)
or a2, $0, $0
bnel v0, s0, 0x70000f24 //(function_70000eb4+0x70)
or a0, s1, $0
lw t8, 0xd4 (s1)
or a0, s1, $0
addiu a1, sp, 0x30
beql t8, r0, 0x70000f78 //(function_70000eb4+0xc4)
lw t0, 0xc8 (s1)
lw t9, 0xc8 (s1)
beql t9, r0, 0x70000f78 //(function_70000eb4+0xc4)
lw t0, 0xc8 (s1)
jal 0x70001560 //(function_70001560)
or a0, s1, $0
beq $0, $0, 0x70000fb0 //(function_70000eb4+0xfc)
lw s0, 0xb4 (s1)
lw t0, 0xc8 (s1)
lw t3, 0xcc (s1)
addiu a2, sp, 0x2c
sltiu t1, t0, 0x1
sll t2, t1, 0x1
sltiu t4, t3, 0x1
or s0, t2, t4
jal 0x7000159c //(function_7000159c)
or a3, s0, $0
beq v0, s0, 0x70000fac //(function_70000eb4+0xf8)
or a0, s1, $0
lw a1, 0x30 (sp)
jal 0x70001440 //(dpc_fill)
lw a2, 0x2c (sp)
lw s0, 0xb4 (s1)
beq s0, r0, 0x70000ff0 //(function_70000eb4+0x13c)
sll $0, $0, 0x0
lw t5, 0x8 (s0)
or a1, s1, $0
or a2, $0, $0
beq t5, r0, 0x70000fdc //(function_70000eb4+0x128)
sll $0, $0, 0x0
lw t6, 0xd0 (s1)
andi t7, t6, 0x1
bnel t7, r0, 0x70000fe8 //(function_70000eb4+0x134)
lw s0, 0x0 (s0)
jal 0x7000df10 //(function_7000df10)
lw a0, 0x4 (s0)
lw s0, 0x0 (s0)
bnel s0, r0, 0x70000fbc //(function_70000eb4+0x108)
lw t5, 0x8 (s0)
jal 0x700009f8 //(testtodisplaystderrorevery16thframe)
lw a0, 0xd0 (s1)
lw ra, 0x24 (sp)
lw s0, 0x14 (sp)
lw s1, 0x18 (sp)
lw s2, 0x1c (sp)
lw s3, 0x20 (sp)
jr ra
addiu sp, sp, 0x40

base $70001014
function_70001014:
//0x70001014 -- 0x7000111b
addiu sp, sp, 0xffffffd0
sw ra, 0x1c (sp)
sw s0, 0x18 (sp)
sw $0, 0x28 (sp)
sw $0, 0x24 (sp)
lw a1, 0xc8 (a0)
or s0, a0, $0
sw $0, 0xc8 (a0)
lui a0, 0x1
ori a0, a0, 0x1
jal 0x70002854 //(function_70002854)
sw a1, 0x2c (sp)
lw a1, 0x2c (sp)
lw t6, 0x4 (a1)
addiu a0, a1, 0x10
andi t7, t6, 0x10
beql t7, r0, 0x700010ac //(function_70001014+0x98)
lw t4, 0x4 (a1)
jal 0x7000e340 //(function_7000e340)
sw a1, 0x2c (sp)
beq v0, r0, 0x700010a8 //(function_70001014+0x94)
lw a1, 0x2c (sp)
lw t8, 0x4 (a1)
lw t0, 0x8 (a1)
addiu at, $0, 0x3
ori t9, t8, 0x20
andi t1, t0, 0x7
bne t1, at, 0x700010c0 //(function_70001014+0xac)
sw t9, 0x4 (a1)
lw t2, 0xbc (s0)
sw t2, 0x0 (a1)
lw t3, 0xc4 (s0)
sw a1, 0xbc (s0)
bnel t3, r0, 0x700010c4 //(function_70001014+0xb0)
lw t6, 0xc8 (s0)
beq $0, $0, 0x700010c0 //(function_70001014+0xac)
sw a1, 0xc4 (s0)
lw t4, 0x4 (a1)
addiu at, $0, 0xfffffffd
or a0, s0, $0
and t5, t4, at
jal 0x70001230 //(function_70001230)
sw t5, 0x4 (a1)
lw t6, 0xc8 (s0)
lw t9, 0xcc (s0)
or a0, s0, $0
sltiu t7, t6, 0x1
sll t8, t7, 0x1
sltiu t0, t9, 0x1
or a3, t8, t0
sw a3, 0x20 (sp)
addiu a1, sp, 0x28
jal 0x7000159c //(function_7000159c)
addiu a2, sp, 0x24
lw a3, 0x20 (sp)
or a0, s0, $0
lw a1, 0x28 (sp)
beql v0, a3, 0x7000110c //(function_70001014+0xf8)
lw ra, 0x1c (sp)
jal 0x70001440 //(dpc_fill)
lw a2, 0x24 (sp)
lw ra, 0x1c (sp)
lw s0, 0x18 (sp)
addiu sp, sp, 0x30
jr ra
sll $0, $0, 0x0

base $7000111c
setcountertarget:
//0x7000111c -- 0x70001127
lui v0, 0x8006
jr ra
addiu v0, v0, 0xffffdb30

base $70001128
function_70001128:
//0x70001128 -- 0x700011df
addiu sp, sp, 0xffffffd0
sw ra, 0x1c (sp)
sw s0, 0x18 (sp)
sw $0, 0x28 (sp)
sw $0, 0x24 (sp)
lw t6, 0xcc (a0)
or s0, a0, $0
lui a0, 0x1
beql t6, r0, 0x700011d0 //(function_70001128+0xa8)
lw ra, 0x1c (sp)
jal 0x70002854 //(function_70002854)
ori a0, a0, 0x2
lui a0, 0x8006
jal 0x7000e3c0 //(function_7000e3c0)
addiu a0, a0, 0xffffdb30
lw a1, 0xcc (s0)
sw $0, 0xcc (s0)
addiu at, $0, 0xfffffffe
lw t7, 0x4 (a1)
or a0, s0, $0
and t8, t7, at
jal 0x70001230 //(function_70001230)
sw t8, 0x4 (a1)
lw t9, 0xc8 (s0)
lw t2, 0xcc (s0)
or a0, s0, $0
sltiu t0, t9, 0x1
sll t1, t0, 0x1
sltiu t3, t2, 0x1
or a3, t1, t3
sw a3, 0x20 (sp)
addiu a1, sp, 0x28
jal 0x7000159c //(function_7000159c)
addiu a2, sp, 0x24
lw a3, 0x20 (sp)
or a0, s0, $0
lw a1, 0x28 (sp)
beql v0, a3, 0x700011d0 //(function_70001128+0xa8)
lw ra, 0x1c (sp)
jal 0x70001440 //(dpc_fill)
lw a2, 0x24 (sp)
lw ra, 0x1c (sp)
lw s0, 0x18 (sp)
addiu sp, sp, 0x30
jr ra
sll $0, $0, 0x0

base $700011e0
function_700011e0:
//0x700011e0 -- 0x7000122f
addiu sp, sp, 0xffffffd8
sw ra, 0x14 (sp)
beq a0, r0, 0x7000121c //(function_700011e0+0x3c)
sw a0, 0x28 (sp)
jal 0x7000e410 //(function_7000e410)
sll $0, $0, 0x0
jal 0x7000e450 //(function_7000e450)
sw v0, 0x1c (sp)
lw t7, 0x1c (sp)
beq v0, t7, 0x70001214 //(function_700011e0+0x34)
sll $0, $0, 0x0
beq $0, $0, 0x70001220 //(function_700011e0+0x40)
or v0, $0, $0
beq $0, $0, 0x70001220 //(function_700011e0+0x40)
lw v0, 0x28 (sp)
or v0, $0, $0
lw ra, 0x14 (sp)
addiu sp, sp, 0x28
jr ra
sll $0, $0, 0x0

base $70001230
function_70001230:
//0x70001230 -- 0x700013d7
addiu sp, sp, 0xffffffe0
sw ra, 0x1c (sp)
sw s0, 0x18 (sp)
sw a0, 0x20 (sp)
lw t6, 0x4 (a1)
or s0, a1, $0
addiu a2, $0, 0x1
andi t7, t6, 0x3
bne t7, r0, 0x700013c4 //(function_70001230+0x194)
or v0, $0, $0
lw a0, 0x50 (a1)
jal 0x7000df10 //(function_7000df10)
lw a1, 0x54 (a1)
lw t8, 0x10 (s0)
addiu at, $0, 0x1
bne t8, at, 0x700013bc //(function_70001230+0x18c)
sll $0, $0, 0x0
lw v0, 0x8 (s0)
andi t9, v0, 0x40
beq t9, r0, 0x700013bc //(function_70001230+0x18c)
andi t0, v0, 0x20
beq t0, r0, 0x700013bc //(function_70001230+0x18c)
lui t1, 0x8002
lw t1, 0x30cc (t1)
beq t1, r0, 0x700012a8 //(function_70001230+0x78)
sll $0, $0, 0x0
jal 0x7000e2d0 //(function_7000e2d0)
or a0, $0, $0
lui at, 0x8002
sw $0, 0x30cc (at)
lui v1, 0x8002
lw v1, 0x30b0 (v1)
lui t3, 0x8002
lui a0, 0x8
sll t2, v1, 0x2
addu t3, t3, t2
lw t3, 0x30c4 (t3)
or v1, t2, $0
beq t3, r0, 0x70001358 //(function_70001230+0x128)
sll $0, $0, 0x0
jal 0x7000dd30 //(function_7000dd30)
ori a0, a0, 0x401
lui v1, 0x8002
lw v1, 0x30b0 (v1)
lui t7, 0x8006
addiu t7, t7, 0xffffdb40
sll t6, v1, 0x2
addu t6, t6, v1
sll t6, t6, 0x4
lui t5, 0x8006
sll t4, v1, 0x2
addu t5, t5, t4
addu t8, t6, t7
addiu t1, t8, 0x48
lw t5, 0xffffdbe0 (t5)
lw at, 0x0 (t8)
addiu t8, t8, 0xc
addiu t5, t5, 0xc
sw at, 0xfffffff4 (t5)
lw at, 0xfffffff8 (t8)
sw at, 0xfffffff8 (t5)
lw at, 0xfffffffc (t8)
bne t8, t1, 0x7000130c //(function_70001230+0xdc)
sw at, 0xfffffffc (t5)
lw at, 0x0 (t8)
or a0, v0, $0
sw at, 0x0 (t5)
lw t1, 0x4 (t8)
jal 0x7000dd30 //(function_7000dd30)
sw t1, 0x4 (t5)
lui v1, 0x8002
lw v1, 0x30b0 (v1)
sll t2, v1, 0x2
or v1, t2, $0
lui at, 0x8002
addu at, at, v1
jal 0x7000e0d0 //(function_7000e0d0)
lwc1 f12, 0x30b4 (at)
lui t3, 0x8002
lw t3, 0x30b0 (t3)
lui at, 0x8002
sll t4, t3, 0x2
addu at, at, t4
jal 0x7000e200 //(function_7000e200)
lwc1 f12, 0x30bc (at)
lui t6, 0x8002
lw t6, 0x30b0 (t6)
lui at, 0x8002
addiu t7, t6, 0x1
bgez t7, 0x700013a8 //(function_70001230+0x178)
andi t0, t7, 0x1
beq t0, r0, 0x700013a8 //(function_70001230+0x178)
sll $0, $0, 0x0
addiu t0, t0, 0xfffffffe
sw t0, 0x30b0 (at)
jal 0x700009a0 //(testtodisplaystderrandupdatecount)
lw a0, 0xc (s0)
jal 0x7000e490 //(function_7000e490)
lw a0, 0xc (s0)
beq $0, $0, 0x700013c4 //(function_70001230+0x194)
addiu v0, $0, 0x1
lw ra, 0x1c (sp)
lw s0, 0x18 (sp)
addiu sp, sp, 0x20
jr ra
sll $0, $0, 0x0

base $700013d8
function_700013d8:
//0x700013d8 -- 0x7000143f
lw v0, 0x10 (a1)
addiu at, $0, 0x2
addiu t6, $0, 0x1
bnel v0, at, 0x70001414 //(function_700013d8+0x3c)
lw v0, 0xc4 (a0)
lw v0, 0xc0 (a0)
beql v0, r0, 0x70001404 //(function_700013d8+0x2c)
sw a1, 0xb8 (a0)
beq $0, $0, 0x70001404 //(function_700013d8+0x2c)
sw a1, 0x0 (v0)
sw a1, 0xb8 (a0)
sw a1, 0xc0 (a0)
beq $0, $0, 0x7000142c //(function_700013d8+0x54)
sw t6, 0xd4 (a0)
lw v0, 0xc4 (a0)
beql v0, r0, 0x70001428 //(function_700013d8+0x50)
sw a1, 0xbc (a0)
beq $0, $0, 0x70001428 //(function_700013d8+0x50)
sw a1, 0x0 (v0)
sw a1, 0xbc (a0)
sw a1, 0xc4 (a0)
lw t7, 0x8 (a1)
sw $0, 0x0 (a1)
andi t8, t7, 0x3
jr ra
sw t8, 0x4 (a1)

base $70001440
dpc_fill:
//0x70001440 -- 0x7000155f
addiu sp, sp, 0xffffffd8
sw s1, 0x18 (sp)
sw s0, 0x14 (sp)
or s0, a1, $0
or s1, a2, $0
sw ra, 0x1c (sp)
beq a1, r0, 0x7000150c //(dpc_fill+0xcc)
sw a0, 0x28 (sp)
lw v0, 0x10 (a1)
addiu at, $0, 0x2
bnel v0, at, 0x70001480 //(dpc_fill+0x40)
addiu at, $0, 0x2
jal 0x7000d320 //(osWritebackDCacheAll)
sll $0, $0, 0x0
lw v0, 0x10 (s0)
addiu at, $0, 0x2
beql v0, at, 0x700014a8 //(dpc_fill+0x68)
addiu at, $0, 0x2
lw t6, 0x4 (s0)
andi t7, t6, 0x10
bnel t7, r0, 0x700014a8 //(dpc_fill+0x68)
addiu at, $0, 0x2
jal 0x7000e4e0 //(function_7000e4e0)
addiu a0, $0, 0x3c0
lw v0, 0x10 (s0)
addiu at, $0, 0x2
bne v0, at, 0x700014c4 //(dpc_fill+0x84)
lui a0, 0x4
lui a0, 0x3
jal 0x70002854 //(function_70002854)
ori a0, a0, 0x1
beq $0, $0, 0x700014dc //(dpc_fill+0x9c)
lw t8, 0x4 (s0)
jal 0x70002854 //(function_70002854)
ori a0, a0, 0x1
lui a0, 0x2
jal 0x70002854 //(function_70002854)
ori a0, a0, 0x2
lw t8, 0x4 (s0)
addiu at, $0, 0xffffffcf
addiu a0, s0, 0x10
and t9, t8, at
sw t9, 0x4 (s0)
jal 0x7000e60c //(function_7000e60c)
sw a0, 0x20 (sp)
jal 0x7000e76c //(function_7000e76c)
lw a0, 0x20 (sp)
lw t0, 0x28 (sp)
bne s0, s1, 0x7000150c //(dpc_fill+0xcc)
sw s0, 0xc8 (t0)
sw s1, 0xcc (t0)
beql s1, r0, 0x70001550 //(dpc_fill+0x110)
lw ra, 0x1c (sp)
beql s1, s0, 0x70001550 //(dpc_fill+0x110)
lw ra, 0x1c (sp)
lw t1, 0x3c (s1)
lw a0, 0x38 (s1)
lw a2, 0x0 (t1)
jal 0x7000e7b0 //(function_7000e7b0)
lw a3, 0x4 (t1)
addiu t2, $0, 0x1
lui at, 0x8002
lw t3, 0x28 (sp)
sw t2, 0x30a8 (at)
lui at, 0x8002
sw $0, 0x30ac (at)
sw s1, 0xcc (t3)
lw ra, 0x1c (sp)
lw s0, 0x14 (sp)
lw s1, 0x18 (sp)
jr ra
addiu sp, sp, 0x28

base $70001560
function_70001560:
//0x70001560 -- 0x7000159b
addiu sp, sp, 0xffffffe8
sw ra, 0x14 (sp)
lw v0, 0xc8 (a0)
addiu at, $0, 0x1
lw t6, 0x10 (v0)
bnel t6, at, 0x70001590 //(function_70001560+0x30)
lw ra, 0x14 (sp)
lw t7, 0x4 (v0)
ori t8, t7, 0x10
jal 0x7000e860 //(function_7000e860)
sw t8, 0x4 (v0)
lw ra, 0x14 (sp)
addiu sp, sp, 0x18
jr ra
sll $0, $0, 0x0

base $7000159c
function_7000159c:
//0x7000159c -- 0x7000177f
addiu sp, sp, 0xffffffd8
sw s1, 0x18 (sp)
or s1, a0, $0
sw ra, 0x1c (sp)
sw s0, 0x14 (sp)
addiu t0, $0, 0xfffffffd
lw t6, 0xd4 (s1)
or v1, a3, $0
lw s0, 0xbc (s1)
beq t6, r0, 0x7000161c //(function_7000159c+0x80)
lw v0, 0xb8 (s1)
andi t7, a3, 0x2
beql t7, r0, 0x70001620 //(function_7000159c+0x84)
or a0, s0, $0
beql s0, r0, 0x700015fc //(function_7000159c+0x60)
sw v0, 0x0 (a1)
lw t8, 0x8 (s0)
and v1, a3, t0
andi t9, t8, 0x10
beql t9, r0, 0x700015fc //(function_7000159c+0x60)
sw v0, 0x0 (a1)
beq $0, $0, 0x70001758 //(function_7000159c+0x1bc)
sw s0, 0x0 (a1)
sw v0, 0x0 (a1)
lw t2, 0xb8 (s1)
sw $0, 0xd4 (s1)
and v1, a3, t0
lw t3, 0x0 (t2)
bne t3, r0, 0x70001758 //(function_7000159c+0x1bc)
sw t3, 0xb8 (s1)
beq $0, $0, 0x70001758 //(function_7000159c+0x1bc)
sw $0, 0xc0 (s1)
or a0, s0, $0
sw v1, 0x24 (sp)
sw a1, 0x2c (sp)
sw a2, 0x30 (sp)
jal 0x700011e0 //(function_700011e0)
sw a3, 0x34 (sp)
lw v1, 0x24 (sp)
lw a1, 0x2c (sp)
lw a2, 0x30 (sp)
lw a3, 0x34 (sp)
addiu t0, $0, 0xfffffffd
beq v0, r0, 0x70001758 //(function_7000159c+0x1bc)
addiu t1, $0, 0xfffffffe
lw t5, 0x8 (s0)
andi t6, t5, 0x7
addiu t7, t6, 0xffffffff
sltiu at, t7, 0x7
beq at, r0, 0x70001758 //(function_7000159c+0x1bc)
sll t7, t7, 0x2
lui at, 0x8003
addu at, at, t7
lw t7, 0xffff8400 (at)
jr t7
sll $0, $0, 0x0
lw t8, 0x4 (s0)
andi t2, a3, 0x2
addiu at, $0, 0x3
andi t9, t8, 0x20
beq t9, r0, 0x700016d4 //(function_7000159c+0x138)
sll $0, $0, 0x0
beq t2, r0, 0x70001758 //(function_7000159c+0x1bc)
sll $0, $0, 0x0
sw s0, 0x0 (a1)
lw t3, 0x4 (s0)
and v1, a3, t0
andi t4, t3, 0x1
beql t4, r0, 0x700016c0 //(function_7000159c+0x124)
lw t5, 0xbc (s1)
sw s0, 0x0 (a2)
and v1, v1, t1
lw t5, 0xbc (s1)
lw t6, 0x0 (t5)
bne t6, r0, 0x70001758 //(function_7000159c+0x1bc)
sw t6, 0xbc (s1)
beq $0, $0, 0x70001758 //(function_7000159c+0x1bc)
sw $0, 0xc4 (s1)
bne a3, at, 0x70001758 //(function_7000159c+0x1bc)
sll $0, $0, 0x0
sw s0, 0x0 (a2)
sw s0, 0x0 (a1)
lw t8, 0xbc (s1)
addiu at, $0, 0xfffffffc
and v1, a3, at
lw t9, 0x0 (t8)
bne t9, r0, 0x70001758 //(function_7000159c+0x1bc)
sw t9, 0xbc (s1)
beq $0, $0, 0x70001758 //(function_7000159c+0x1bc)
sw $0, 0xc4 (s1)
lw v0, 0x4 (s0)
andi t4, a3, 0x2
andi t3, v0, 0x2
beq t3, r0, 0x7000172c //(function_7000159c+0x190)
andi t5, v0, 0x1
beq t4, r0, 0x70001758 //(function_7000159c+0x1bc)
sll $0, $0, 0x0
sw s0, 0x0 (a1)
beq $0, $0, 0x70001758 //(function_7000159c+0x1bc)
and v1, a3, t0
beq t5, r0, 0x70001758 //(function_7000159c+0x1bc)
andi t6, a3, 0x1
beq t6, r0, 0x70001758 //(function_7000159c+0x1bc)
sll $0, $0, 0x0
sw s0, 0x0 (a2)
lw t7, 0xbc (s1)
and v1, a3, t1
lw t8, 0x0 (t7)
bne t8, r0, 0x70001758 //(function_7000159c+0x1bc)
sw t8, 0xbc (s1)
sw $0, 0xc4 (s1)
beql v1, a3, 0x7000176c //(function_7000159c+0x1d0)
lw ra, 0x1c (sp)
beq $0, $0, 0x700015b4 //(function_7000159c+0x18)
or a3, v1, $0
lw ra, 0x1c (sp)
lw s0, 0x14 (sp)
lw s1, 0x18 (sp)
addiu sp, sp, 0x28
jr ra
or v0, v1, $0

base $70001780
function_70001780:
//0x70001780 -- 0x700017d7
mfc0 t0, EntryHi
addiu t1, $0, 0x0
mtc0 t1, Index
mtc0 $0, PageMask
addiu t2, $0, 0x17
lui t1, 0xc000
mtc0 t1, EntryHi
lui t1, 0x8000
srl t3, t1, 0x6
or t3, t3, t2
mtc0 t3, EntryLo0 
addiu t1, $0, 0x1
mtc0 t1, EntryLo1
sll $0, $0, 0x0
tlbwi
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0
mtc0 t0, EntryHi
jr ra
sll $0, $0, 0x0

base $700017d8
function_700017d8:
//0x700017d8 -- 0x700017df
sll $0, $0, 0x0
sll $0, $0, 0x0

base $700017e0
function_700017e0:
//0x700017e0 -- 0x70001897
lui v1, 0x8006
lui v0, 0x8006
addiu v0, v0, 0xffffe3f0
addiu v1, v1, 0xffffdbf0
addiu a0, $0, 0x1
addiu v1, v1, 0x10
sltu at, v1, v0
sw a0, 0xfffffff0 (v1)
bne at, r0, 0x700017f4 //(function_700017e0+0x14)
sw $0, 0xfffffff4 (v1)
lui at, 0x8006
lui v1, 0x8006
lui v0, 0x8006
addiu v0, v0, 0xffffe4a4
addiu v1, v1, 0xffffe3f4
sb $0, 0xffffe3f1 (at)
sb a0, 0xffffe3f0 (at)
sb $0, 0xffffe3f3 (at)
sb a0, 0xffffe3f2 (at)
addiu v1, v1, 0x8
sb $0, 0xfffffffb (v1)
sb a0, 0xfffffffa (v1)
sb $0, 0xfffffffd (v1)
sb a0, 0xfffffffc (v1)
sb $0, 0xffffffff (v1)
sb a0, 0xfffffffe (v1)
sb $0, 0xfffffff9 (v1)
bne v1, v0, 0x7000182c //(function_700017e0+0x4c)
sb a0, 0xfffffff8 (v1)
lui t6, 0x803b
addiu t6, t6, 0xffffb400
addiu at, $0, 0xffffe000
and t7, t6, at
lui at, 0xfff4
ori at, at, 0xc000
addu t8, t7, at
lui at, 0x8006
sw t8, 0xffffe4a8 (at)
lui at, 0xffc0
lui t9, 0x8006
addiu t9, t9, 0xffffdbf0
ori at, at, 0x8000
addu t0, t9, at
lui at, 0x8006
jr ra
sw t0, 0xffffe4a4 (at)

base $70001898
function_70001898:
//0x70001898 -- 0x700018bf
lui v1, 0x8002
addiu v1, v1, 0x30d0
lw v0, 0x0 (v1)
slti at, v0, 0x33
beq at, r0, 0x700018b8 //(function_70001898+0x20)
slti at, v0, 0x1a
beq at, r0, 0x700018b8 //(function_70001898+0x20)
sll $0, $0, 0x0
jr ra
sw $0, 0x0 (v1)

base $700018c0
function_700018c0:
//0x700018c0 -- 0x7000191f
addiu sp, sp, 0xffffffd8
sw s2, 0x20 (sp)
sw s1, 0x1c (sp)
sw s0, 0x18 (sp)
or s1, a0, $0
sw ra, 0x24 (sp)
or s0, $0, $0
addiu s2, $0, 0x20
jal 0x7000e880 //(function_7000e880)
or a0, s0, $0
bnel v0, s1, 0x700018fc //(function_700018c0+0x3c)
addiu s0, s0, 0x1
beq $0, $0, 0x70001908 //(function_700018c0+0x48)
or v0, s0, $0
addiu s0, s0, 0x1
bne s0, s2, 0x700018e0 //(function_700018c0+0x20)
sll $0, $0, 0x0
lui v0, 0x8000
lw ra, 0x24 (sp)
lw s0, 0x18 (sp)
lw s1, 0x1c (sp)
lw s2, 0x20 (sp)
jr ra
addiu sp, sp, 0x28

base $70001920
function_70001920:
//0x70001920 -- 0x70001953
addiu sp, sp, 0xffffffe8
sw ra, 0x14 (sp)
jal 0x700018c0 //(function_700018c0)
sll $0, $0, 0x0
sll t6, v0, 0x0
bltz t6, 0x70001944 //(function_70001920+0x24)
or a0, v0, $0
jal 0x7000d3d0 //(function_7000d3d0)
sll $0, $0, 0x0
lw ra, 0x14 (sp)
addiu sp, sp, 0x18
jr ra
sll $0, $0, 0x0

base $70001954
function_70001954:
//0x70001954 -- 0x700019d7
lui t7, 0x8006
addiu t7, t7, 0xffffe3f0
sll t6, a0, 0x1
addu v1, t6, t7
lbu t8, 0x0 (v1)
addiu sp, sp, 0xffffffe0
sw ra, 0x14 (sp)
bnel t8, r0, 0x700019cc //(function_70001954+0x78)
lw ra, 0x14 (sp)
lbu a0, 0x1 (v1)
lui at, 0x7f00
sw v1, 0x18 (sp)
sll t9, a0, 0xd
jal 0x700018c0 //(function_700018c0)
or a0, t9, at
sll t1, v0, 0x0
lw v1, 0x18 (sp)
bltz t1, 0x700019ac //(function_70001954+0x58)
or a0, v0, $0
jal 0x7000d3d0 //(function_7000d3d0)
sw v1, 0x18 (sp)
lw v1, 0x18 (sp)
lbu t2, 0x1 (v1)
lui at, 0x8006
addiu v0, $0, 0x1
sll t3, t2, 0x4
addu at, at, t3
sw v0, 0xffffdbf0 (at)
sb v0, 0x0 (v1)
lw ra, 0x14 (sp)
addiu sp, sp, 0x20
jr ra
sll $0, $0, 0x0

base $700019d8
function_700019d8:
//0x700019d8 -- 0x70001af7
lui v0, 0x8002
addiu v0, v0, 0x30d0
lw t6, 0x0 (v0)
lui at, 0x7fff
addiu sp, sp, 0xffffffb0
ori at, at, 0xe000
sw ra, 0x1c (sp)
and a0, a0, at
addiu t7, t6, 0x1
sw s0, 0x18 (sp)
sw t7, 0x0 (v0)
jal 0x70001920 //(function_70001920)
sw a0, 0x28 (sp)
jal 0x70001b10 //(function_70001b10)
sll $0, $0, 0x0
addiu at, $0, 0x5a
divu v0, at
mfhi a0
lui v1, 0x8002
addiu v1, v1, 0x30d4
sw a0, 0x0 (v1)
jal 0x70001954 //(function_70001954)
or s0, a0, $0
lw v0, 0x28 (sp)
lui t9, 0x8006
lw t9, 0xffffe4a8 (t9)
lui at, 0xff
ori at, at, 0xe000
sll t0, s0, 0xd
lui t2, 0x3
and t1, v0, at
addiu t2, t2, 0x4b30
addu a0, t9, t0
sw a0, 0x34 (sp)
addu a1, t1, t2
or v0, t1, $0
sw t1, 0x24 (sp)
jal 0x70005c1c //(function_70005c1c)
addiu a2, $0, 0x2000
lui a0, 0x4000
jal 0x7000d350 //(function_7000d350)
lui a1, 0x4000
lui a0, 0x8000
jal 0x7000d350 //(function_7000d350)
lui a1, 0x1000
lw a1, 0x24 (sp)
lui t5, 0x8006
addiu t5, t5, 0xffffdbf0
srl t3, a1, 0xd
sll t4, t3, 0x4
addu a2, t4, t5
sw s0, 0x4 (a2)
sw a2, 0x20 (sp)
sw t3, 0x28 (sp)
jal 0x7000e8b0 //(function_7000e8b0)
lw a0, 0x34 (sp)
lw ra, 0x1c (sp)
srl t6, v0, 0xc
sll t9, s0, 0x1
lui t0, 0x8006
lw a1, 0x28 (sp)
lw a2, 0x20 (sp)
sll t7, t6, 0x6
addiu t0, t0, 0xffffe3f0
ori t8, t7, 0x1f
addu v1, t9, t0
lw s0, 0x18 (sp)
sb $0, 0x0 (v1)
addiu sp, sp, 0x50
sb a1, 0x1 (v1)
jr ra
sw t8, 0x0 (a2)

base $70001af8
function_70001af8:
//0x70001af8 -- 0x70001b03
lui v0, 0x8006
jr ra
lw v0, 0xffffe4a8 (v0)

base $70001b04
function_70001b04:
//0x70001b04 -- 0x70001b0f
sll $0, $0, 0x0
sll $0, $0, 0x0
sll $0, $0, 0x0

base $70001B10
BOOT_70001B10:

insert boot_raw_to_tlb_entries, "boot.bin", (origin() - $1000), ($70001B60 - $70001B10)

base $70001B60
tlb_entries:
 dw $40802800
 dw $00000000
 dw $401A2000
 dw $3C1B8006
 dw $277BE4A4
 dw $8F7B0000
 dw $035BD021
 dw $8F5B0000
 dw $409B1000
 dw $00000000

base $70001B88
BOOT_70001B88:

base $70001BB0
BOOT_70001BB0:

base $70001BD0
BOOT_70001BD0:

base $70001C94
BOOT_70001C94:

base $70001C9C
BOOT_70001C9C:

base $70001CAC
BOOT_70001CAC:

base $70001CD4
BOOT_70001CD4:

base $70001CEC
BOOT_70001CEC:

base $70001D04
BOOT_70001D04:

base $70001D40
BOOT_70001D40:

base $70001D90
BOOT_70001D90:

base $70001D98
BOOT_70001D98:

base $70001DA8
BOOT_70001DA8:

base $70001E68
BOOT_70001E68:

base $70001ED8
BOOT_70001ED8:

base $70001F58
BOOT_70001F58:

base $70001F7C
BOOT_70001F7C:

base $7000200C
BOOT_7000200C:

base $70002044
BOOT_70002044:

base $7000215C
BOOT_7000215C:

base $7000219C
BOOT_7000219C:

base $700021CC
BOOT_700021CC:

base $700021D4
BOOT_700021D4:

base $700021F4
BOOT_700021F4:

base $70002200
BOOT_70002200:

base $70002244
BOOT_70002244:

base $70002288
BOOT_70002288:

base $700022D8
BOOT_700022D8:

base $700023E4
BOOT_700023E4:

base $70002414
BOOT_70002414:

base $70002418
BOOT_70002418:

base $70002424
BOOT_70002424:

base $7000245C
BOOT_7000245C:

base $7000249C
BOOT_7000249C:

base $700024A8
BOOT_700024A8:

base $700024C4
BOOT_700024C4:

base $700024D8
BOOT_700024D8:

base $70002518
BOOT_70002518:

base $7000253C
BOOT_7000253C:

base $70002544
BOOT_70002544:

base $700025C4
BOOT_700025C4:

base $700025C8
BOOT_700025C8:

base $700025D8
BOOT_700025D8:

base $70002608
BOOT_70002608:

base $70002610
BOOT_70002610:

base $70002654
BOOT_70002654:

base $70002674
BOOT_70002674:

base $70002690
BOOT_70002690:

base $700026BC
BOOT_700026BC:

base $700026E4
BOOT_700026E4:

base $700026EC
BOOT_700026EC:

base $700026F4
BOOT_700026F4:

base $70002730
BOOT_70002730:

base $70002778
BOOT_70002778:

base $700027A4
BOOT_700027A4:

base $700027D4
BOOT_700027D4:

base $700027F8
BOOT_700027F8:

base $70002810
BOOT_70002810:

base $70002838
BOOT_70002838:

base $70002854
BOOT_70002854:

base $700028B0
BOOT_700028B0:

base $700028D0
BOOT_700028D0:

base $700028D4
BOOT_700028D4:

base $7000293C
BOOT_7000293C:

base $70002958
BOOT_70002958:

base $70002990
BOOT_70002990:

base $700029B4
BOOT_700029B4:

base $700029C8
BOOT_700029C8:

base $70002A44
BOOT_70002A44:

base $70002A70
BOOT_70002A70:

base $70002AD8
BOOT_70002AD8:

base $70002AFC
BOOT_70002AFC:

base $70002B58
BOOT_70002B58:

base $70002B84
BOOT_70002B84:

base $70002BD0
BOOT_70002BD0:

base $70002BE4
BOOT_70002BE4:

base $70002BFC
BOOT_70002BFC:

base $70002C70
BOOT_70002C70:

base $70002C78
BOOT_70002C78:

base $70002C8C
BOOT_70002C8C:

base $70002CD8
BOOT_70002CD8:

base $70002D50
BOOT_70002D50:

base $70002DAC
BOOT_70002DAC:

base $70002DCC
BOOT_70002DCC:

base $70002E04
BOOT_70002E04:

base $70002E40
BOOT_70002E40:

base $70002E68
BOOT_70002E68:

base $70002E80
BOOT_70002E80:

base $70002ED4
BOOT_70002ED4:

base $70002EDC
BOOT_70002EDC:

base $70002EFC
BOOT_70002EFC:

base $70002F14
BOOT_70002F14:

base $70002F60
BOOT_70002F60:

base $70002F74
BOOT_70002F74:

base $70002F94
BOOT_70002F94:

base $70002F9C
BOOT_70002F9C:

base $70002FB8
BOOT_70002FB8:

base $70003024
BOOT_70003024:

base $70003060
BOOT_70003060:

base $70003124
BOOT_70003124:

base $70003150
BOOT_70003150:

base $70003190
BOOT_70003190:

base $700031A0
BOOT_700031A0:

base $700031D0
BOOT_700031D0:

base $70003270
BOOT_70003270:

base $70003298
BOOT_70003298:

base $700032EC
BOOT_700032EC:

base $70003308
BOOT_70003308:

base $70003348
BOOT_70003348:

base $70003380
BOOT_70003380:

base $7000338C
BOOT_7000338C:

base $700033C4
BOOT_700033C4:

base $700033EC
BOOT_700033EC:

base $70003424
BOOT_70003424:

base $70003430
BOOT_70003430:

base $70003464
BOOT_70003464:

base $700034A4
BOOT_700034A4:

base $700034D0
BOOT_700034D0:

base $700034DC
BOOT_700034DC:

base $7000350C
BOOT_7000350C:

base $7000352C
BOOT_7000352C:

base $70003580
BOOT_70003580:

base $70003604
BOOT_70003604:

base $7000363C
BOOT_7000363C:

base $7000365C
BOOT_7000365C:

base $70003694
BOOT_70003694:

base $700036CC
BOOT_700036CC:

base $70003704
BOOT_70003704:

base $7000372C
BOOT_7000372C:

base $70003760
BOOT_70003760:

base $700037B8
BOOT_700037B8:

base $700037D0
BOOT_700037D0:

base $700037F0
BOOT_700037F0:

base $70003808
BOOT_70003808:

base $7000383C
BOOT_7000383C:

base $70003854
BOOT_70003854:

base $70003874
BOOT_70003874:

base $7000388C
BOOT_7000388C:

base $700038C4
BOOT_700038C4:

base $700038DC
BOOT_700038DC:

base $700038FC
BOOT_700038FC:

base $70003914
BOOT_70003914:

base $70003948
BOOT_70003948:

base $70003960
BOOT_70003960:

base $70003984
BOOT_70003984:

base $7000399C
BOOT_7000399C:

base $700039C0
BOOT_700039C0:

base $700039D4
BOOT_700039D4:

base $700039EC
BOOT_700039EC:

base $70003A0C
BOOT_70003A0C:

base $70003A20
BOOT_70003A20:

base $70003A64
BOOT_70003A64:

base $70003A80
BOOT_70003A80:

base $70003B04
BOOT_70003B04:

base $70003B28
BOOT_70003B28:

base $70003B44
BOOT_70003B44:

base $70003B64
BOOT_70003B64:

base $70003B84
BOOT_70003B84:

base $70003BB0
BOOT_70003BB0:

base $70003C00
BOOT_70003C00:

base $70003C10
BOOT_70003C10:

base $70003C1C
setptr_video2buf:

base $70003C2C
BOOT_70003C2C:

base $70003C3C
BOOT_70003C3C:

base $70003C4C
BOOT_70003C4C:

base $70003C58
BOOT_70003C58:

base $70003D20
BOOT_70003D20:

base $70003E78
BOOT_70003E78:

base $70003E9C
BOOT_70003E9C:

base $70003EB4
BOOT_70003EB4:

base $70003EE8
BOOT_70003EE8:

base $70003EF8
BOOT_70003EF8:

base $70003F64
BOOT_70003F64:

base $7000409C
BOOT_7000409C:

base $700040B0
BOOT_700040B0:

base $7000416C
BOOT_7000416C:

base $70004260
BOOT_70004260:

base $700042F0
BOOT_700042F0:

base $7000436C
BOOT_7000436C:

base $70004370
BOOT_70004370:

base $70004384
BOOT_70004384:

base $70004390
BOOT_70004390:

base $7000439C
BOOT_7000439C:

base $700043A8
BOOT_700043A8:

base $700043B4
BOOT_700043B4:

base $700043D8
BOOT_700043D8:

base $700043E8
BOOT_700043E8:

base $700043F8
set_video2_text_clip_size:

base $7000441C
BOOT_7000441C:

base $7000442C
BOOT_7000442C:

base $7000443C
set_video2_width_height:

base $7000449C
BOOT_7000449C:

base $700044AC
BOOT_700044AC:

base $700044BC
set_video2_ulx_uly:

base $70004514
BOOT_70004514:

base $70004524
BOOT_70004524:

base $70004534
BOOT_70004534:

base $70004544
BOOT_70004544:

base $70004580
BOOT_70004580:

base $70004590
BOOT_70004590:

base $700045CC
BOOT_700045CC:

base $700045DC
BOOT_700045DC:

base $700045EC
BOOT_700045EC:

base $70004640
BOOT_70004640:

base $70004650
BOOT_70004650:

base $7000469C
BOOT_7000469C:

base $700046AC
BOOT_700046AC:

base $700046D0
BOOT_700046D0:

base $70004730
BOOT_70004730:

base $70004758
BOOT_70004758:

base $7000477C
BOOT_7000477C:

base $700047B8
BOOT_700047B8:

base $700048D4
BOOT_700048D4:

base $700048FC
BOOT_700048FC:

base $70004938
BOOT_70004938:

base $70004A60
BOOT_70004A60:

base $70004A84
BOOT_70004A84:

base $70004AC0
BOOT_70004AC0:

base $70004BB4
BOOT_70004BB4:

base $70004BDC
BOOT_70004BDC:

base $70004C18
BOOT_70004C18:

base $70004D18
BOOT_70004D18:

base $70004D20
BOOT_70004D20:

base $70004D44
BOOT_70004D44:

base $70004D60
BOOT_70004D60:

base $70004D68
BOOT_70004D68:

base $70004D6C
BOOT_70004D6C:

base $70004D80
BOOT_70004D80:

base $70004DC4
BOOT_70004DC4:

base $70004DD4
BOOT_70004DD4:

base $70004DE0
BOOT_70004DE0:

base $70004E2C
BOOT_70004E2C:

base $70004E60
BOOT_70004E60:

base $70004E88
BOOT_70004E88:

base $70004E98
BOOT_70004E98:

base $70004EAC
BOOT_70004EAC:

base $70004EB4
BOOT_70004EB4:

base $70004EBC
BOOT_70004EBC:

base $70004EC4
BOOT_70004EC4:

base $70004EE0
BOOT_70004EE0:

base $70004F54
BOOT_70004F54:

base $70004FC0
BOOT_70004FC0:

base $70004FC4
BOOT_70004FC4:

base $7000505C
BOOT_7000505C:

base $70005064
BOOT_70005064:

base $70005080
BOOT_70005080:

base $700050AC
BOOT_700050AC:

base $700050D4
BOOT_700050D4:

base $7000511C
BOOT_7000511C:

base $70005158
BOOT_70005158:

base $70005190
BOOT_70005190:

base $700051A8
BOOT_700051A8:

base $700051B0
BOOT_700051B0:

base $700051B8
BOOT_700051B8:

base $700051D0
BOOT_700051D0:

base $700051D4
BOOT_700051D4:

base $700051E0
BOOT_700051E0:

base $70005234
BOOT_70005234:

base $7000524C
BOOT_7000524C:

base $70005250
BOOT_70005250:

base $70005258
BOOT_70005258:

base $70005270
BOOT_70005270:

base $7000528C
BOOT_7000528C:

base $70005294
BOOT_70005294:

base $70005334
BOOT_70005334:

base $70005340
BOOT_70005340:

base $70005370
BOOT_70005370:

base $70005398
BOOT_70005398:

base $700053A0
BOOT_700053A0:

base $700053AC
BOOT_700053AC:

base $700053C8
BOOT_700053C8:

base $700053FC
BOOT_700053FC:

base $70005404
BOOT_70005404:

base $7000540C
BOOT_7000540C:

base $70005414
BOOT_70005414:

base $70005420
BOOT_70005420:

base $700054A0
BOOT_700054A0:

base $700054A8
BOOT_700054A8:

base $700054CC
BOOT_700054CC:

base $700054DC
BOOT_700054DC:

base $700054E4
BOOT_700054E4:

base $7000552C
BOOT_7000552C:

base $70005534
BOOT_70005534:

base $70005550
BOOT_70005550:

base $70005558
BOOT_70005558:

base $70005560
BOOT_70005560:

base $7000559C
BOOT_7000559C:

base $700055A4
BOOT_700055A4:

base $700055C8
BOOT_700055C8:

base $70005618
BOOT_70005618:

base $70005628
BOOT_70005628:

base $70005630
BOOT_70005630:

base $70005654
BOOT_70005654:

base $7000565C
BOOT_7000565C:

base $70005668
BOOT_70005668:

base $70005674
BOOT_70005674:

base $70005678
BOOT_70005678:

base $700056B4
BOOT_700056B4:

base $700056BC
BOOT_700056BC:

base $700056E8
BOOT_700056E8:

base $70005708
BOOT_70005708:

base $70005730
BOOT_70005730:

base $70005774
BOOT_70005774:

base $700057B8
BOOT_700057B8:

base $700057BC
BOOT_700057BC:

base $700057CC
BOOT_700057CC:

base $700057E4
BOOT_700057E4:

base $700057F0
BOOT_700057F0:

base $70005810
BOOT_70005810:

base $70005854
BOOT_70005854:

base $7000585C
BOOT_7000585C:

base $70005888
BOOT_70005888:

base $700058E4
BOOT_700058E4:

base $700058F8
BOOT_700058F8:

base $700058FC
BOOT_700058FC:

base $70005914
BOOT_70005914:

base $70005918
BOOT_70005918:

base $70005934
BOOT_70005934:

base $70005938
BOOT_70005938:

base $70005954
BOOT_70005954:

base $70005958
BOOT_70005958:

base $70005974
BOOT_70005974:

base $70005984
BOOT_70005984:

base $700059A4
BOOT_700059A4:

base $700059D0
BOOT_700059D0:

base $70005A2C
BOOT_70005A2C:

base $70005A5C
BOOT_70005A5C:

base $70005A9C
BOOT_70005A9C:

base $70005AC0
BOOT_70005AC0:

base $70005AD8
BOOT_70005AD8:

base $70005ADC
BOOT_70005ADC:

base $70005B10
BOOT_70005B10:

base $70005B18
BOOT_70005B18:

base $70005B44
BOOT_70005B44:

base $70005B50
BOOT_70005B50:

base $70005B60
BOOT_70005B60:

base $70005B90
BOOT_70005B90:

base $70005BF0
BOOT_70005BF0:

base $70005C1C
BOOT_70005C1C:

base $70005C44
BOOT_70005C44:

base $70005CA8
BOOT_70005CA8:

base $70005D08
BOOT_70005D08:

base $70005D20
BOOT_70005D20:

base $70005D30
BOOT_70005D30:

base $70005DDC
BOOT_70005DDC:

base $70005E68
BOOT_70005E68:

base $70005E7C
BOOT_70005E7C:

base $70005EA8
BOOT_70005EA8:

base $70005ED0
BOOT_70005ED0:

base $70005F10
BOOT_70005F10:

base $70005FF4
BOOT_70005FF4:

base $70006004
BOOT_70006004:

base $7000601C
BOOT_7000601C:

base $7000603C
BOOT_7000603C:

base $70006050
BOOT_70006050:

base $70006060
mainloop:

base $7000618C
BOOT_7000618C:

base $700063F4
BOOT_700063F4:

base $70006410
BOOT_70006410:

base $7000641C
BOOT_7000641C:

base $70006464
BOOT_70006464:

base $700064D8
BOOT_700064D8:

base $70006700
BOOT_70006700:

base $70006724
BOOT_70006724:

base $7000674C
BOOT_7000674C:

base $700067A8
BOOT_700067A8:

base $700067C0
BOOT_700067C0:

base $70006808
BOOT_70006808:

base $70006844
BOOT_70006844:

base $70006854
BOOT_70006854:

base $70006890
BOOT_70006890:

base $7000689C
BOOT_7000689C:

base $700068B4
BOOT_700068B4:

base $70006930
run_title_stage:

base $70006950
BOOT_70006950:

base $7000695C
get_stage_num:

base $70006968
BOOT_70006968:

base $700069A4
BOOT_700069A4:

base $700069B4
BOOT_700069B4:

base $700069C0
BOOT_700069C0:

base $700069F0
BOOT_700069F0:

base $70006A08
BOOT_70006A08:

base $70006A28
BOOT_70006A28:

base $70006A30
BOOT_70006A30:

base $70006A6C
BOOT_70006A6C:

base $70006C88
BOOT_70006C88:

base $70006CB4
BOOT_70006CB4:

base $70006E68
BOOT_70006E68:

base $70006E7C
BOOT_70006E7C:

base $70006EB4
BOOT_70006EB4:

base $70006ED4
BOOT_70006ED4:

base $70006EE4
BOOT_70006EE4:

base $70006F28
BOOT_70006F28:

base $70006FBC
BOOT_70006FBC:

base $70006FC0
BOOT_70006FC0:

base $70006FD0
BOOT_70006FD0:

base $70007018
BOOT_70007018:

base $70007020
BOOT_70007020:

base $70007030
BOOT_70007030:

base $7000703C
BOOT_7000703C:

base $700070A0
BOOT_700070A0:

base $700070E4
BOOT_700070E4:

base $700070F0
BOOT_700070F0:

base $700070F8
BOOT_700070F8:

base $70007158
BOOT_70007158:

base $70007168
BOOT_70007168:

base $700071B4
BOOT_700071B4:

base $700071BC
BOOT_700071BC:

base $700071F4
BOOT_700071F4:

base $70007204
BOOT_70007204:

base $7000723C
BOOT_7000723C:

base $7000725C
BOOT_7000725C:

base $7000726C
BOOT_7000726C:

base $700072B0
BOOT_700072B0:

base $70007344
BOOT_70007344:

base $70007348
BOOT_70007348:

base $70007358
BOOT_70007358:

base $700073A0
BOOT_700073A0:

base $700073A8
BOOT_700073A8:

base $700073B8
BOOT_700073B8:

base $700073C4
BOOT_700073C4:

base $70007428
BOOT_70007428:

base $7000746C
BOOT_7000746C:

base $70007478
BOOT_70007478:

base $70007480
BOOT_70007480:

base $700074E0
BOOT_700074E0:

base $700074F0
BOOT_700074F0:

base $7000753C
BOOT_7000753C:

base $70007544
BOOT_70007544:

base $7000757C
BOOT_7000757C:

base $7000758C
BOOT_7000758C:

base $700075C4
BOOT_700075C4:

base $700075E4
BOOT_700075E4:

base $700075F4
BOOT_700075F4:

base $70007638
BOOT_70007638:

base $700076CC
BOOT_700076CC:

base $700076D0
BOOT_700076D0:

base $700076E0
BOOT_700076E0:

base $70007728
BOOT_70007728:

base $70007730
BOOT_70007730:

base $70007740
BOOT_70007740:

base $7000774C
BOOT_7000774C:

base $700077B0
BOOT_700077B0:

base $700077F4
BOOT_700077F4:

base $70007800
BOOT_70007800:

base $70007808
BOOT_70007808:

base $70007868
BOOT_70007868:

base $70007878
BOOT_70007878:

base $700078C4
BOOT_700078C4:

base $700078CC
BOOT_700078CC:

base $70007904
BOOT_70007904:

base $70007914
BOOT_70007914:

base $700079B4
BOOT_700079B4:

base $700079C0
BOOT_700079C0:

base $70007A58
BOOT_70007A58:

base $70007A64
BOOT_70007A64:

base $70007AFC
BOOT_70007AFC:

base $70007B08
BOOT_70007B08:

base $70007B0C
BOOT_70007B0C:

base $70007B20
BOOT_70007B20:

base $70007BEC
BOOT_70007BEC:

base $70007C18
BOOT_70007C18:

base $70007DDC
BOOT_70007DDC:

base $70007E0C
BOOT_70007E0C:

base $70007E38
BOOT_70007E38:

base $70007E44
BOOT_70007E44:

base $70007E80
BOOT_70007E80:

base $70007ED0
BOOT_70007ED0:

base $70007EF4
BOOT_70007EF4:

base $70007F10
BOOT_70007F10:

base $70007F58
BOOT_70007F58:

base $70007F7C
BOOT_70007F7C:

base $70007F9C
BOOT_70007F9C:

base $70007FBC
BOOT_70007FBC:

base $70007FD8
BOOT_70007FD8:

base $70008018
BOOT_70008018:

base $7000802C
BOOT_7000802C:

base $70008054
BOOT_70008054:

base $7000807C
BOOT_7000807C:

base $70008098
BOOT_70008098:

base $700080F8
BOOT_700080F8:

base $70008108
BOOT_70008108:

base $7000812C
BOOT_7000812C:

base $7000813C
BOOT_7000813C:

base $7000814C
BOOT_7000814C:

base $70008230
BOOT_70008230:

base $70008284
BOOT_70008284:

base $700082A0
BOOT_700082A0:

base $700082A8
BOOT_700082A8:

base $700082F8
BOOT_700082F8:

base $700082FC
BOOT_700082FC:

base $70008310
BOOT_70008310:

base $70008320
BOOT_70008320:

base $70008324
BOOT_70008324:

base $70008388
BOOT_70008388:

base $7000838C
BOOT_7000838C:

base $700083A8
BOOT_700083A8:

base $700083D4
BOOT_700083D4:

base $70008444
BOOT_70008444:

base $7000844C
BOOT_7000844C:

base $70008454
BOOT_70008454:

base $70008460
BOOT_70008460:

base $70008464
BOOT_70008464:

base $70008474
BOOT_70008474:

base $7000847C
BOOT_7000847C:

base $700084B4
BOOT_700084B4:

base $700084D0
BOOT_700084D0:

base $700084D8
BOOT_700084D8:

base $700084E0
BOOT_700084E0:

base $700084F0
BOOT_700084F0:

base $70008538
BOOT_70008538:

base $7000853C
BOOT_7000853C:

base $7000854C
BOOT_7000854C:

base $70008580
BOOT_70008580:

base $70008584
BOOT_70008584:

base $70008598
BOOT_70008598:

base $700085A8
BOOT_700085A8:

base $700085AC
BOOT_700085AC:

base $700085B8
BOOT_700085B8:

base $700085C8
BOOT_700085C8:

base $7000866C
BOOT_7000866C:

base $70008680
BOOT_70008680:

base $70008690
BOOT_70008690:

base $70008748
BOOT_70008748:

base $70008764
BOOT_70008764:

base $70008770
BOOT_70008770:

base $7000880C
BOOT_7000880C:

base $70008884
BOOT_70008884:

base $70008890
BOOT_70008890:

base $700088A8
BOOT_700088A8:

base $700088CC
BOOT_700088CC:

base $700088D4
def_70007FB4:

base $700088D8
BOOT_700088D8:

base $700088F8
BOOT_700088F8:

base $700088FC
BOOT_700088FC:

base $7000891C
BOOT_7000891C:

base $70008948
BOOT_70008948:

base $70008994
BOOT_70008994:

base $700089C4
BOOT_700089C4:

base $70008A30
BOOT_70008A30:

base $70008A74
BOOT_70008A74:

base $70008AAC
BOOT_70008AAC:

base $70008AC0
BOOT_70008AC0:

base $70008AC8
BOOT_70008AC8:

base $70008AF0
BOOT_70008AF0:

base $70008B10
BOOT_70008B10:

base $70008B24
BOOT_70008B24:

base $70008B2C
BOOT_70008B2C:

base $70008B40
BOOT_70008B40:

base $70008B48
BOOT_70008B48:

base $70008B5C
BOOT_70008B5C:

base $70008B70
BOOT_70008B70:

base $70008BF4
BOOT_70008BF4:

base $70008C00
BOOT_70008C00:

base $70008C94
BOOT_70008C94:

base $70008CC8
BOOT_70008CC8:

base $70008CE0
BOOT_70008CE0:

base $70008CF0
BOOT_70008CF0:

base $70008D04
BOOT_70008D04:

base $70008D2C
BOOT_70008D2C:

base $70008D3C
BOOT_70008D3C:

base $70008D78
BOOT_70008D78:

base $70008D80
BOOT_70008D80:

base $70008DA8
BOOT_70008DA8:

base $70008DC8
BOOT_70008DC8:

base $70008DCC
BOOT_70008DCC:

base $70008DD8
BOOT_70008DD8:

base $70008DE8
BOOT_70008DE8:

base $70008DF0
BOOT_70008DF0:

base $70008E00
BOOT_70008E00:

base $70008E08
BOOT_70008E08:

base $70008E6C
BOOT_70008E6C:

base $70008E7C
BOOT_70008E7C:

base $70008E8C
BOOT_70008E8C:

base $70008F34
BOOT_70008F34:

base $70008F44
BOOT_70008F44:

base $70008F48
BOOT_70008F48:

base $70008F80
BOOT_70008F80:

base $70008FE0
BOOT_70008FE0:

base $70008FF0
BOOT_70008FF0:

base $70009020
BOOT_70009020:

base $7000905C
BOOT_7000905C:

base $7000906C
BOOT_7000906C:

base $700090C0
BOOT_700090C0:

base $700090F0
BOOT_700090F0:

base $700090FC
BOOT_700090FC:

base $70009124
BOOT_70009124:

base $70009134
BOOT_70009134:

base $70009144
BOOT_70009144:

base $70009154
BOOT_70009154:

base $70009164
BOOT_70009164:

base $70009174
BOOT_70009174:

base $70009184
BOOT_70009184:

base $700091B8
BOOT_700091B8:

base $700091C8
BOOT_700091C8:

base $700091E8
BOOT_700091E8:

base $70009204
BOOT_70009204:

base $70009238
BOOT_70009238:

base $70009254
BOOT_70009254:

base $70009264
BOOT_70009264:

base $70009284
BOOT_70009284:

base $700092E4
BOOT_700092E4:

base $7000931C
BOOT_7000931C:

base $7000935C
BOOT_7000935C:

base $70009364
BOOT_70009364:

base $70009380
BOOT_70009380:

base $700093AC
BOOT_700093AC:

base $70009450
BOOT_70009450:

base $70009488
BOOT_70009488:

base $700094C0
BOOT_700094C0:

base $700094EC
BOOT_700094EC:

base $700094FC
BOOT_700094FC:

base $70009514
BOOT_70009514:

base $7000958C
BOOT_7000958C:

base $700095B0
BOOT_700095B0:

base $700095F8
BOOT_700095F8:

base $70009638
BOOT_70009638:

base $70009720
allocate_viewport_bytes:

base $70009748
BOOT_70009748:

base $70009764
BOOT_70009764:

base $7000976C
BOOT_7000976C:

base $70009788
BOOT_70009788:

base $70009794
BOOT_70009794:

base $700097D4
BOOT_700097D4:

base $700097DC
BOOT_700097DC:

base $700097E8
BOOT_700097E8:

base $70009804
BOOT_70009804:

base $70009840
BOOT_70009840:

base $7000985C
BOOT_7000985C:

base $70009868
BOOT_70009868:

base $70009880
BOOT_70009880:

base $70009898
BOOT_70009898:

base $700098B4
BOOT_700098B4:

base $700098C0
BOOT_700098C0:

base $700098D0
BOOT_700098D0:

base $700098D8
BOOT_700098D8:

base $700098E0
BOOT_700098E0:

base $700098F0
BOOT_700098F0:

base $700098F4
BOOT_700098F4:

base $70009910
BOOT_70009910:

base $7000992C
BOOT_7000992C:

base $70009950
BOOT_70009950:

base $70009970
BOOT_70009970:

base $7000998C
BOOT_7000998C:

base $7000999C
reset_mem_bank_a0:

base $700099C4
BOOT_700099C4:

base $700099FC
BOOT_700099FC:

base $70009A10
BOOT_70009A10:

base $70009A34
BOOT_70009A34:

base $70009A50
BOOT_70009A50:

base $70009A8C
BOOT_70009A8C:

base $70009AB8
BOOT_70009AB8:

base $70009AE0
BOOT_70009AE0:

base $70009AE8
BOOT_70009AE8:

base $70009AF4
BOOT_70009AF4:

base $70009B18
BOOT_70009B18:

base $70009B3C
BOOT_70009B3C:

base $70009B50
BOOT_70009B50:

base $70009B60
BOOT_70009B60:

base $70009B8C
BOOT_70009B8C:

base $70009B94
BOOT_70009B94:

base $70009BB0
BOOT_70009BB0:

base $70009BD8
BOOT_70009BD8:

base $70009BFC
BOOT_70009BFC:

base $70009C10
BOOT_70009C10:

base $70009C30
BOOT_70009C30:

base $70009C48
BOOT_70009C48:

base $70009C54
BOOT_70009C54:

base $70009C58
BOOT_70009C58:

base $70009C74
BOOT_70009C74:

base $70009CD4
BOOT_70009CD4:

base $70009CEC
BOOT_70009CEC:

base $70009CFC
BOOT_70009CFC:

base $70009D0C
BOOT_70009D0C:

base $70009D24
BOOT_70009D24:

base $70009D30
BOOT_70009D30:

base $70009D50
BOOT_70009D50:

base $70009D6C
BOOT_70009D6C:

base $70009D98
reset_memtable_base_allocation:

base $70009DD8
BOOT_70009DD8:

base $70009E10
BOOT_70009E10:

base $70009E34
BOOT_70009E34:

base $70009E74
BOOT_70009E74:

base $70009EBC
BOOT_70009EBC:

base $70009EC4
BOOT_70009EC4:

base $70009EE8
BOOT_70009EE8:

base $70009EF8
BOOT_70009EF8:

base $70009F10
BOOT_70009F10:

base $70009F38
BOOT_70009F38:

base $70009F4C
BOOT_70009F4C:

base $70009F60
BOOT_70009F60:

base $70009F64
BOOT_70009F64:

base $70009F80
BOOT_70009F80:

base $70009F84
BOOT_70009F84:

base $70009FA8
BOOT_70009FA8:

base $70009FCC
BOOT_70009FCC:

base $70009FE8
BOOT_70009FE8:

base $70009FF4
BOOT_70009FF4:

base $7000A000
BOOT_7000A000:

base $7000A014
BOOT_7000A014:

base $7000A020
BOOT_7000A020:

base $7000A040
BOOT_7000A040:

base $7000A054
BOOT_7000A054:

base $7000A064
BOOT_7000A064:

base $7000A088
BOOT_7000A088:

base $7000A098
BOOT_7000A098:

base $7000A0A8
BOOT_7000A0A8:

base $7000A0BC
BOOT_7000A0BC:

base $7000A0DC
BOOT_7000A0DC:

base $7000A0F4
BOOT_7000A0F4:

base $7000A100
BOOT_7000A100:

base $7000A150
BOOT_7000A150:

base $7000A16C
BOOT_7000A16C:

base $7000A18C
BOOT_7000A18C:

base $7000A198
BOOT_7000A198:

base $7000A1B4
BOOT_7000A1B4:

base $7000A1B8
BOOT_7000A1B8:

base $7000A1C4
BOOT_7000A1C4:

base $7000A1DC
BOOT_7000A1DC:

base $7000A20C
BOOT_7000A20C:

base $7000A220
BOOT_7000A220:

base $7000A228
BOOT_7000A228:

base $7000A244
BOOT_7000A244:

base $7000A250
BOOT_7000A250:

base $7000A26C
BOOT_7000A26C:

base $7000A29C
BOOT_7000A29C:

base $7000A2C4
BOOT_7000A2C4:

base $7000A2F8
BOOT_7000A2F8:

base $7000A338
BOOT_7000A338:

base $7000A354
BOOT_7000A354:

base $7000A370
BOOT_7000A370:

base $7000A3A0
BOOT_7000A3A0:

base $7000A3B4
BOOT_7000A3B4:

base $7000A3C0
BOOT_7000A3C0:

base $7000A3D0
BOOT_7000A3D0:

base $7000A3D4
BOOT_7000A3D4:

base $7000A3DC
BOOT_7000A3DC:

base $7000A410
BOOT_7000A410:

base $7000A418
BOOT_7000A418:

base $7000A430
BOOT_7000A430:

base $7000A434
BOOT_7000A434:

base $7000A450
BOOT_7000A450:

base $7000A498
increment_random_num:

base $7000A4AC
BOOT_7000A4AC:

base $7000A4F0
BOOT_7000A4F0:

base $7000A524
BOOT_7000A524:

base $7000A530
BOOT_7000A530:

base $7000A544
BOOT_7000A544:

base $7000A56C
BOOT_7000A56C:

base $7000A57C
BOOT_7000A57C:

base $7000A584
BOOT_7000A584:

base $7000A58C
strtok:

base $7000A5C0
BOOT_7000A5C0:

base $7000A5F8
BOOT_7000A5F8:

base $7000A604
BOOT_7000A604:

base $7000A61C
BOOT_7000A61C:

base $7000A648
BOOT_7000A648:

base $7000A668
BOOT_7000A668:

base $7000A684
BOOT_7000A684:

base $7000A6A0
check_token:

base $7000A6F8
BOOT_7000A6F8:

base $7000A728
BOOT_7000A728:

base $7000A73C
BOOT_7000A73C:

base $7000A740
BOOT_7000A740:

base $7000A770
BOOT_7000A770:

base $7000A784
BOOT_7000A784:

base $7000A798
BOOT_7000A798:

base $7000A7A0
BOOT_7000A7A0:

base $7000A7B4
BOOT_7000A7B4:

base $7000A7D4
BOOT_7000A7D4:

base $7000A7D8
BOOT_7000A7D8:

base $7000A7E0
BOOT_7000A7E0:

base $7000A7F4
BOOT_7000A7F4:

base $7000A7FC
BOOT_7000A7FC:

base $7000A810
BOOT_7000A810:

base $7000A820
BOOT_7000A820:

base $7000A830
BOOT_7000A830:

base $7000A844
BOOT_7000A844:

base $7000A84C
BOOT_7000A84C:

base $7000A870
BOOT_7000A870:

base $7000A878
BOOT_7000A878:

base $7000A888
BOOT_7000A888:

base $7000A890
BOOT_7000A890:

base $7000A898
BOOT_7000A898:

base $7000A8AC
BOOT_7000A8AC:

base $7000A8D0
BOOT_7000A8D0:

base $7000A8D8
BOOT_7000A8D8:

base $7000A8E8
BOOT_7000A8E8:

base $7000A8F0
BOOT_7000A8F0:

base $7000A8F8
BOOT_7000A8F8:

base $7000A924
BOOT_7000A924:

base $7000A930
BOOT_7000A930:

base $7000A948
BOOT_7000A948:

base $7000A950
BOOT_7000A950:

base $7000A970
BOOT_7000A970:

base $7000A984
BOOT_7000A984:

base $7000A98C
BOOT_7000A98C:

base $7000A9D8
BOOT_7000A9D8:

base $7000A9E0
strtol:

base $7000AA20
BOOT_7000AA20:

base $7000AA28
BOOT_7000AA28:

base $7000AA40
BOOT_7000AA40:

base $7000AA54
BOOT_7000AA54:

base $7000AA74
BOOT_7000AA74:

base $7000AA90
BOOT_7000AA90:

base $7000AAC4
BOOT_7000AAC4:

base $7000AAF8
BOOT_7000AAF8:

base $7000AB00
BOOT_7000AB00:

base $7000AB1C
BOOT_7000AB1C:

base $7000AB40
BOOT_7000AB40:

base $7000AB64
BOOT_7000AB64:

base $7000AB88
BOOT_7000AB88:

base $7000ABB0
BOOT_7000ABB0:

base $7000ABB8
BOOT_7000ABB8:

base $7000ABC0
BOOT_7000ABC0:

base $7000ABD0
BOOT_7000ABD0:

base $7000ABE0
BOOT_7000ABE0:

base $7000ABE4
BOOT_7000ABE4:

base $7000AC00
BOOT_7000AC00:

base $7000AC14
BOOT_7000AC14:

base $7000AC24
BOOT_7000AC24:

base $7000AC30
BOOT_7000AC30:

base $7000AC44
BOOT_7000AC44:

base $7000AC70
BOOT_7000AC70:

base $7000AC94
sprintf:

base $7000ACD8
BOOT_7000ACD8:

base $7000ACF0
BOOT_7000ACF0:

base $7000AD30
BOOT_7000AD30:

base $7000AD38
BOOT_7000AD38:

base $7000AD80
BOOT_7000AD80:

base $7000AD90
BOOT_7000AD90:

base $7000ADA0
BOOT_7000ADA0:

base $7000ADA8
BOOT_7000ADA8:

base $7000ADB0
BOOT_7000ADB0:

base $7000ADD0
BOOT_7000ADD0:

base $7000AE08
BOOT_7000AE08:

base $7000AE30
BOOT_7000AE30:

base $7000AE9C
BOOT_7000AE9C:

base $7000AEA8
BOOT_7000AEA8:

base $7000AEDC
BOOT_7000AEDC:

base $7000AF00
BOOT_7000AF00:

base $7000AF28
BOOT_7000AF28:

base $7000AF2C
BOOT_7000AF2C:

base $7000AF84
BOOT_7000AF84:

base $7000AF98
BOOT_7000AF98:

base $7000AFBC
BOOT_7000AFBC:

base $7000AFD0
BOOT_7000AFD0:

base $7000AFF4
BOOT_7000AFF4:

base $7000AFFC
BOOT_7000AFFC:

base $7000B018
BOOT_7000B018:

base $7000B040
BOOT_7000B040:

base $7000B06C
BOOT_7000B06C:

base $7000B098
BOOT_7000B098:

base $7000B0C4
BOOT_7000B0C4:

base $7000B0E8
BOOT_7000B0E8:

base $7000B120
BOOT_7000B120:

base $7000B148
BOOT_7000B148:

base $7000B184
BOOT_7000B184:

base $7000B1B0
BOOT_7000B1B0:

base $7000B1B4
BOOT_7000B1B4:

base $7000B1C0
BOOT_7000B1C0:

base $7000B1D8
BOOT_7000B1D8:

base $7000B1E8
BOOT_7000B1E8:

base $7000B208
BOOT_7000B208:

base $7000B21C
BOOT_7000B21C:

base $7000B230
BOOT_7000B230:

base $7000B254
BOOT_7000B254:

base $7000B268
BOOT_7000B268:

base $7000B27C
BOOT_7000B27C:

base $7000B2C4
BOOT_7000B2C4:

base $7000B2D0
BOOT_7000B2D0:

base $7000B2F8
BOOT_7000B2F8:

base $7000B32C
BOOT_7000B32C:

base $7000B340
BOOT_7000B340:

base $7000B360
BOOT_7000B360:

base $7000B378
BOOT_7000B378:

base $7000B38C
BOOT_7000B38C:

base $7000B398
BOOT_7000B398:

base $7000B39C
BOOT_7000B39C:

base $7000B3D0
BOOT_7000B3D0:

base $7000B3E4
BOOT_7000B3E4:

base $7000B42C
BOOT_7000B42C:

base $7000B500
BOOT_7000B500:

base $7000B504
BOOT_7000B504:

base $7000B528
BOOT_7000B528:

base $7000B560
BOOT_7000B560:

base $7000B63C
BOOT_7000B63C:

base $7000B6AC
BOOT_7000B6AC:

base $7000B718
BOOT_7000B718:

base $7000B728
BOOT_7000B728:

base $7000B734
BOOT_7000B734:

base $7000B7D4
BOOT_7000B7D4:

base $7000B7F8
BOOT_7000B7F8:

base $7000B800
BOOT_7000B800:

base $7000B804
BOOT_7000B804:

base $7000B810
BOOT_7000B810:

base $7000B85C
BOOT_7000B85C:

base $7000B8AC
BOOT_7000B8AC:

base $7000B8C4
BOOT_7000B8C4:

base $7000B8D8
BOOT_7000B8D8:

base $7000B8EC
BOOT_7000B8EC:

base $7000B8F0
BOOT_7000B8F0:

base $7000B8F8
BOOT_7000B8F8:

base $7000B920
BOOT_7000B920:

base $7000B980
BOOT_7000B980:

base $7000B9A4
BOOT_7000B9A4:

base $7000B9B0
BOOT_7000B9B0:

base $7000B9B4
BOOT_7000B9B4:

base $7000B9CC
BOOT_7000B9CC:

base $7000B9F8
BOOT_7000B9F8:

base $7000BA20
BOOT_7000BA20:

base $7000BA38
BOOT_7000BA38:

base $7000BA48
BOOT_7000BA48:

base $7000BA58
BOOT_7000BA58:

base $7000BA68
BOOT_7000BA68:

base $7000BA70
BOOT_7000BA70:

base $7000BA7C
BOOT_7000BA7C:

base $7000BAC8
BOOT_7000BAC8:

base $7000BB10
BOOT_7000BB10:

base $7000BB20
BOOT_7000BB20:

base $7000BB38
BOOT_7000BB38:

base $7000BB44
BOOT_7000BB44:

base $7000BB60
BOOT_7000BB60:

base $7000BB74
BOOT_7000BB74:

base $7000BBA8
BOOT_7000BBA8:

base $7000BBBC
BOOT_7000BBBC:

base $7000BBC8
BOOT_7000BBC8:

base $7000BBE4
BOOT_7000BBE4:

base $7000BC1C
BOOT_7000BC1C:

base $7000BC34
BOOT_7000BC34:

base $7000BC38
BOOT_7000BC38:

base $7000BC84
BOOT_7000BC84:

base $7000BC9C
BOOT_7000BC9C:

base $7000BCCC
BOOT_7000BCCC:

base $7000BCE4
BOOT_7000BCE4:

base $7000BCEC
BOOT_7000BCEC:

base $7000BCF0
BOOT_7000BCF0:

base $7000BD0C
redirect_to_ramrom_replay_and_record_handlers_if_set:

base $7000BD48
BOOT_7000BD48:

base $7000BD7C
BOOT_7000BD7C:

base $7000BD88
BOOT_7000BD88:

base $7000BDD0
BOOT_7000BDD0:

base $7000BDFC
BOOT_7000BDFC:

base $7000BE58
BOOT_7000BE58:

base $7000BEC8
BOOT_7000BEC8:

base $7000BF38
BOOT_7000BF38:

base $7000BF50
BOOT_7000BF50:

base $7000BF8C
BOOT_7000BF8C:

base $7000BFB8
BOOT_7000BFB8:

base $7000BFC8
BOOT_7000BFC8:

base $7000BFCC
BOOT_7000BFCC:

base $7000BFDC
BOOT_7000BFDC:

base $7000C040
BOOT_7000C040:

base $7000C074
BOOT_7000C074:

base $7000C084
BOOT_7000C084:

base $7000C0B4
BOOT_7000C0B4:

base $7000C0C4
BOOT_7000C0C4:

base $7000C0DC
BOOT_7000C0DC:

base $7000C0E0
BOOT_7000C0E0:

base $7000C0EC
get_cur.controller_horz.stick.pos:

base $7000C144
BOOT_7000C144:

base $7000C174
BOOT_7000C174:

base $7000C1CC
BOOT_7000C1CC:

base $7000C1FC
get_cur.controller_vert.stick.pos:

base $7000C254
BOOT_7000C254:

base $7000C284
BOOT_7000C284:

base $7000C2DC
BOOT_7000C2DC:

base $7000C30C
get_controller_buttons_held:

base $7000C370
BOOT_7000C370:

base $7000C3AC
get_controller_buttons_pressed:

base $7000C410
BOOT_7000C410:

base $7000C430
BOOT_7000C430:

base $7000C440
BOOT_7000C440:

base $7000C470
BOOT_7000C470:

base $7000C48C
BOOT_7000C48C:

base $7000C4A4
BOOT_7000C4A4:

base $7000C4B4
BOOT_7000C4B4:

base $7000C4E8
BOOT_7000C4E8:

base $7000C4F4
BOOT_7000C4F4:

base $7000C528
BOOT_7000C528:

base $7000C55C
BOOT_7000C55C:

base $7000C568
BOOT_7000C568:

base $7000C59C
BOOT_7000C59C:

base $7000C5D0
BOOT_7000C5D0:

base $7000C5E0
BOOT_7000C5E0:

base $7000C60C
BOOT_7000C60C:

base $7000C640
BOOT_7000C640:

base $7000C650
BOOT_7000C650:

base $7000C67C
BOOT_7000C67C:

base $7000C6BC
BOOT_7000C6BC:

base $7000C6FC
BOOT_7000C6FC:

base $7000C728
BOOT_7000C728:

base $7000C734
BOOT_7000C734:

base $7000C76C
BOOT_7000C76C:

base $7000C778
BOOT_7000C778:

base $7000C7B0
BOOT_7000C7B0:

base $7000C7BC
BOOT_7000C7BC:

base $7000C7FC
BOOT_7000C7FC:

base $7000C808
BOOT_7000C808:

base $7000C848
BOOT_7000C848:

base $7000C854
BOOT_7000C854:

base $7000C8BC
BOOT_7000C8BC:

base $7000C8D4
BOOT_7000C8D4:

base $7000C8DC
reset_cont_rumble_detect:

base $7000C930
BOOT_7000C930:

base $7000C954
BOOT_7000C954:

base $7000C980
send_rumble_off_to_PIF:

base $7000CA18
BOOT_7000CA18:

base $7000CA28
BOOT_7000CA28:

base $7000CA2C
BOOT_7000CA2C:

base $7000CA30
BOOT_7000CA30:

base $7000CA90
BOOT_7000CA90:

base $7000CAAC
BOOT_7000CAAC:

base $7000CB44
BOOT_7000CB44:

base $7000CB54
BOOT_7000CB54:

base $7000CB58
BOOT_7000CB58:

base $7000CB5C
BOOT_7000CB5C:

base $7000CBC0
BOOT_7000CBC0:

base $7000CBDC
BOOT_7000CBDC:

base $7000CBFC
BOOT_7000CBFC:

base $7000CC70
BOOT_7000CC70:

base $7000CCA4
BOOT_7000CCA4:

base $7000CCB8
BOOT_7000CCB8:

base $7000CCD4
BOOT_7000CCD4:

base $7000CCDC
BOOT_7000CCDC:

base $7000CD38
BOOT_7000CD38:

base $7000CD64
BOOT_7000CD64:

base $7000CDB4
BOOT_7000CDB4:

base $7000CDC4
BOOT_7000CDC4:

base $7000CDE4
BOOT_7000CDE4:

base $7000CDF8
BOOT_7000CDF8:

base $7000CE10
BOOT_7000CE10:

base $7000CE8C
BOOT_7000CE8C:

base $7000CE90
BOOT_7000CE90:

base $7000CEA0
BOOT_7000CEA0:

base $7000CEA8
BOOT_7000CEA8:

base $7000CEB0
BOOT_7000CEB0:

base $7000CEB8
BOOT_7000CEB8:

base $7000CEC0
BOOT_7000CEC0:

base $7000CEC8
BOOT_7000CEC8:

base $7000CED0
BOOT_7000CED0:

base $7000CED8
BOOT_7000CED8:

base $7000CEE0
BOOT_7000CEE0:

base $7000CEE8
BOOT_7000CEE8:

base $7000CF14
BOOT_7000CF14:

base $7000CF28
BOOT_7000CF28:

base $7000CF44
BOOT_7000CF44:

include "../lib/libultra_rom.asm"
insert binarybootcode, "boot.bin", (origin() - $1000)


