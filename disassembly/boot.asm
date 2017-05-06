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
lui v0, $0002
jr ra
addiu v0, v0, $1990 //v0=21990

set_rodata_rom_end:
lui v0, $0003
jr ra
addiu v0, v0, $3590 //v0=33590

setRareZip_start:
lui v0, $0003
jr ra
addiu v0, v0, $3590 //v0=33590

setRareZip_end:
lui v0, $0003
jr ra
addiu v0, v0, $4B30 //v0=34B30

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
addiu v1, a0, $FFFF //v1= total size - 1
bltz v1, do_decompress //skip if nothing to copy
lui a2, (decompression_buffer >> 16)	 //a2=80300000: buffer for decompression tables
lui t9, $7020
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
lui t3, $0003
lui t4, $0000
addiu t4, t4, $1050 //t4=1050
addiu t3, t3, $3590 //t3=33590: ROM address of 70200000 RareZip ASM [33590-34B30 ROM]
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
lui s0, $8006
addiu s0, s0, $D640 //s0= 8005D640
lui a2, $7000
addiu t4, r0, $000A
sw t4, $0014(sp) //sp+14= A
addiu a2, a2, $089C //a2= 7000089C: main game loop
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

base $70001B60
tlb_entries:
// dw $40802800
// dw $00000000
// dw $401A2000
// dw $3C1B8006
// dw $277BE4A4
// dw $8F7B0000
// dw $035BD021
// dw $8F5B0000
// dw $409B1000
// dw $00000000

base $7000CF90    
osPiRawStartDma:

base $7000D320
osWritebackDCacheAll:

base $7000D350
osInvalICache:

base $7000D3D0
osUnmapTLB:

base $7000D410
__osGetFpcCsr:

base $7000D420
__osSetFpcCsr:

base $7000D430
osCreateThread:

base $7000D580
osStartThread:

base $70200000
RareZip_vaddr:

base $7020141C
decompressfile:

base $80020D90
rodata_start:

base $8005D2E0
rodata_end:
bss_start:

base $8008E360
bss_end:

base $80300000
decompression_buffer:

base $803AB400
sp_boot:

base $803AB410
sp_rmon:

base $803AB710
sp_idle:

base $803AB750
sp_shed:

base $803AB950
sp_main:

base $803B3950
sp_audi:
