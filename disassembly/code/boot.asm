base origin()
seg_boot_rom_start:
include "boot/entry.asm"

base $700004BC
get_rodata_vaddr:;getaddresstoregister(seg_rodata_vaddr_start,v0)
get_rodata_rom_start:;getaddresstoregister(seg_rodata_rom_start,v0)
get_rodata_rom_end:;getaddresstoregister(seg_rodata_rom_end,v0)
getRareZip_start:;getaddresstoregister(seg_rarezip_rom_start,v0)
getRareZip_end:;getaddresstoregister(seg_rarezip_rom_end,v0)

jump_decompressfile:;jumpaddressviaregister(decompressfile,a3)

nop; nop; nop;


init:;scope {
 //decompress main compressed block, initialize memory, TLB and its interrupts,
 // then execute main game thread
 define returnval(v0)
 define totalsize(v1)
 define rodata_vaddr(s0)
 define rodata_rom_size(s1)
 define rarezip_vaddr(t2)
 define rodata_rom_start(t6)
 define rarezip_rom_start(t7)
 define rarezip_size(t8)

 addiu sp, sp, (sp_init - sp_rmon)//$FFC0 //sp_rmon - 0x40
 sw ra, {sp_init.sp_init_ra}(sp) //store old ra
 sw s1, {sp_init.sp_init_s1}(sp) //store old s1
 jal get_rodata_vaddr //v0=80020D90: target address for main compressed block (21990)
 sw s0, {sp_init.sp_init_s0}(sp) //store old s0

 jal get_rodata_rom_start //v0=21990: ROM address of main compressed block
 or {rodata_vaddr}, {returnval}, $0 //s0=v0: 80020D90

 jal get_rodata_rom_end //v0=33590: ROM endpoint of main compressed block
 sw {returnval}, {sp_init.rodata_pos}(sp) //sp+34= main.pos

 lw {rodata_rom_start}, {sp_init.rodata_pos}(sp)
 jal getRareZip_start
 subu {rodata_rom_size}, {returnval}, {rodata_rom_start} //s1=v0-t6: compressed size of main compressed block

 jal getRareZip_end
 sw {returnval}, {sp_init.rarezip_pos}(sp) //sp+28= RareZip.pos

 lw {rarezip_rom_start}, {sp_init.rarezip_pos}(sp)
 lui {rarezip_vaddr}, (seg_rarezip_vaddr_start >> 16)	 //t2=70200000: target vaddress for RareZip

 //decompressfile parameters
 //reuse register a0 {decompress_source} for {decompress_size} during setup
 define decompress_source(a0)
 define decompress_size({decompress_source})
 define decompress_target(a1)
 define decompress_buffer(a2)

 or {decompress_target}, {rodata_vaddr}, $0 //a1=s0: target address for main.bin
 subu {rarezip_size}, {returnval}, {rarezip_rom_start} //t8=v0-t7: RareZip.sz = RareZip.end - RareZip.pos
 addu {decompress_size}, {rodata_rom_size}, {rarezip_size} //a0=s1+t8: main.cmp_sz + RareZip.sz
 addiu {totalsize}, {decompress_size}, -1 //v1= total size - 1

 bltz {totalsize}, do_decompress //skip if nothing to copy
 lui {decompress_buffer}, (decompression_buffer >> 16)	 //a2=80300000: buffer for decompression tables

 lui t9, (seg_rarezip_vaddr_start >> 16)
 subu a0, t9, {rodata_rom_size} //a0=70200000 - main.cmp_sz: vaddr for main
 addu v0, {rodata_vaddr}, {totalsize} //v0=s0+v1: target address + total size

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

  //decompressfile accepts:
  //a0=p->source, a1=p->target, a2=p->buffer
  jal jump_decompressfile //call decompressfile{{decompress_source}, {decompress_target}, {decompress_buffer})
  subu {decompress_source}, {rarezip_vaddr}, {rodata_rom_size} //a0=p->source: RareZip.vaddr - main.cmp_sz

  //70000594:
  lui t3, (seg_rarezip_rom_start >> 16)
  lui t4, $0000
  addiu t4, t4, $1050 //t4=1050
  addiu t3, t3, seg_rarezip_rom_start //t3=33590: ROM address of 70200000 RareZip ASM [33590-34B30 ROM]
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
}

stack_init:
addu v0, a0, a1
jr ra
addiu v0, -8

base $700006FC
function_700006FC:
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
function_70001B10:

insert function_raw_to_tlb_entries, "boot.bin", (origin() - $1000), ($70001B60 - $70001B10)

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
function_70001B88:

base $70001BB0
function_70001BB0:

base $70001BD0
function_70001BD0:

base $70001C94
function_70001C94:

base $70001C9C
function_70001C9C:

base $70001CAC
function_70001CAC:

base $70001CD4
function_70001CD4:

base $70001CEC
function_70001CEC:

base $70001D04
function_70001D04:

base $70001D40
function_70001D40:

base $70001D90
function_70001D90:

base $70001D98
function_70001D98:

base $70001DA8
function_70001DA8:

base $70001E68
function_70001E68:

base $70001ED8
function_70001ED8:

base $70001F58
function_70001F58:

base $70001F7C
function_70001F7C:

base $7000200C
function_7000200C:

base $70002044
function_70002044:

base $7000215C
function_7000215C:

base $7000219C
function_7000219C:

base $700021CC
function_700021CC:

base $700021D4
function_700021D4:

base $700021F4
function_700021F4:

base $70002200
function_70002200:

base $70002244
function_70002244:

base $70002288
function_70002288:

base $700022D8
function_700022D8:

base $700023E4
function_700023E4:

base $70002414
function_70002414:

base $70002418
function_70002418:

base $70002424
function_70002424:

base $7000245C
function_7000245C:

base $7000249C
function_7000249C:

base $700024A8
function_700024A8:

base $700024C4
function_700024C4:

base $700024D8
function_700024D8:

base $70002518
function_70002518:

base $7000253C
function_7000253C:

base $70002544
function_70002544:

base $700025C4
function_700025C4:

base $700025C8
function_700025C8:

base $700025D8
function_700025D8:

base $70002608
function_70002608:

base $70002610
function_70002610:

base $70002654
function_70002654:

base $70002674
function_70002674:

base $70002690
function_70002690:

base $700026BC
function_700026BC:

base $700026E4
function_700026E4:

base $700026EC
function_700026EC:

base $700026F4
function_700026F4:

base $70002730
function_70002730:

base $70002778
function_70002778:

base $700027A4
function_700027A4:

base $700027D4
function_700027D4:

base $700027F8
function_700027F8:

base $70002810
function_70002810:

base $70002838
function_70002838:

base $70002854
function_70002854:

base $700028B0
function_700028B0:

base $700028D0
function_700028D0:

base $700028D4
function_700028D4:

base $7000293C
function_7000293C:

base $70002958
function_70002958:

base $70002990
function_70002990:

base $700029B4
function_700029B4:

base $700029C8
function_700029C8:

base $70002A44
function_70002A44:

base $70002A70
function_70002A70:

base $70002AD8
function_70002AD8:

base $70002AFC
function_70002AFC:

base $70002B58
function_70002B58:

base $70002B84
function_70002B84:

base $70002BD0
function_70002BD0:

base $70002BE4
function_70002BE4:

base $70002BFC
function_70002BFC:

base $70002C70
function_70002C70:

base $70002C78
function_70002C78:

base $70002C8C
function_70002C8C:

base $70002CD8
function_70002CD8:

base $70002D50
function_70002D50:

base $70002DAC
function_70002DAC:

base $70002DCC
function_70002DCC:

base $70002E04
function_70002E04:

base $70002E40
function_70002E40:

base $70002E68
function_70002E68:

base $70002E80
function_70002E80:

base $70002ED4
function_70002ED4:

base $70002EDC
function_70002EDC:

base $70002EFC
function_70002EFC:

base $70002F14
function_70002F14:

base $70002F60
function_70002F60:

base $70002F74
function_70002F74:

base $70002F94
function_70002F94:

base $70002F9C
function_70002F9C:

base $70002FB8
function_70002FB8:

base $70003024
function_70003024:

base $70003060
function_70003060:

base $70003124
function_70003124:

base $70003150
function_70003150:

base $70003190
function_70003190:

base $700031A0
function_700031A0:

base $700031D0
function_700031D0:

base $70003270
function_70003270:

base $70003298
function_70003298:

base $700032EC
function_700032EC:

base $70003308
function_70003308:

base $70003348
function_70003348:

base $70003380
function_70003380:

base $7000338C
function_7000338C:

base $700033C4
function_700033C4:

base $700033EC
function_700033EC:

base $70003424
function_70003424:

base $70003430
function_70003430:

base $70003464
function_70003464:

base $700034A4
function_700034A4:

base $700034D0
function_700034D0:

base $700034DC
function_700034DC:

base $7000350C
function_7000350C:

base $7000352C
function_7000352C:

base $70003580
function_70003580:

base $70003604
function_70003604:

base $7000363C
function_7000363C:

base $7000365C
function_7000365C:

base $70003694
function_70003694:

base $700036CC
function_700036CC:

base $70003704
function_70003704:

base $7000372C
function_7000372C:

base $70003760
function_70003760:

base $700037B8
function_700037B8:

base $700037D0
function_700037D0:

base $700037F0
function_700037F0:

base $70003808
function_70003808:

base $7000383C
function_7000383C:

base $70003854
function_70003854:

base $70003874
function_70003874:

base $7000388C
function_7000388C:

base $700038C4
function_700038C4:

base $700038DC
function_700038DC:

base $700038FC
function_700038FC:

base $70003914
function_70003914:

base $70003948
function_70003948:

base $70003960
function_70003960:

base $70003984
function_70003984:

base $7000399C
function_7000399C:

base $700039C0
function_700039C0:

base $700039D4
function_700039D4:

base $700039EC
function_700039EC:

base $70003A0C
function_70003A0C:

base $70003A20
function_70003A20:

base $70003A64
function_70003A64:

base $70003A80
function_70003A80:

base $70003B04
function_70003B04:

base $70003B28
function_70003B28:

base $70003B44
function_70003B44:

base $70003B64
function_70003B64:

base $70003B84
function_70003B84:

base $70003BB0
function_70003BB0:

base $70003C00
function_70003C00:

base $70003C10
function_70003C10:

base $70003C1C
setptr_video2buf:

base $70003C2C
function_70003C2C:

base $70003C3C
function_70003C3C:

base $70003C4C
function_70003C4C:

base $70003C58
function_70003C58:

base $70003D20
function_70003D20:

base $70003E78
function_70003E78:

base $70003E9C
function_70003E9C:

base $70003EB4
function_70003EB4:

base $70003EE8
function_70003EE8:

base $70003EF8
function_70003EF8:

base $70003F64
function_70003F64:

base $7000409C
function_7000409C:

base $700040B0
function_700040B0:

base $7000416C
function_7000416C:

base $70004260
function_70004260:

base $700042F0
function_700042F0:

base $7000436C
function_7000436C:

base $70004370
function_70004370:

base $70004384
function_70004384:

base $70004390
function_70004390:

base $7000439C
function_7000439C:

base $700043A8
function_700043A8:

base $700043B4
function_700043B4:

base $700043D8
function_700043D8:

base $700043E8
function_700043E8:

base $700043F8
set_video2_text_clip_size:

base $7000441C
function_7000441C:

base $7000442C
function_7000442C:

base $7000443C
set_video2_width_height:

base $7000449C
function_7000449C:

base $700044AC
function_700044AC:

base $700044BC
set_video2_ulx_uly:

base $70004514
function_70004514:

base $70004524
function_70004524:

base $70004534
function_70004534:

base $70004544
function_70004544:

base $70004580
function_70004580:

base $70004590
function_70004590:

base $700045CC
function_700045CC:

base $700045DC
function_700045DC:

base $700045EC
function_700045EC:

base $70004640
function_70004640:

base $70004650
function_70004650:

base $7000469C
function_7000469C:

base $700046AC
function_700046AC:

base $700046D0
function_700046D0:

base $70004730
function_70004730:

base $70004758
function_70004758:

base $7000477C
function_7000477C:

base $700047B8
function_700047B8:

base $700048D4
function_700048D4:

base $700048FC
function_700048FC:

base $70004938
function_70004938:

base $70004A60
function_70004A60:

base $70004A84
function_70004A84:

base $70004AC0
function_70004AC0:

base $70004BB4
function_70004BB4:

base $70004BDC
function_70004BDC:

base $70004C18
function_70004C18:

base $70004D18
function_70004D18:

base $70004D20
function_70004D20:

base $70004D44
function_70004D44:

base $70004D60
function_70004D60:

base $70004D68
function_70004D68:

base $70004D6C
function_70004D6C:

base $70004D80
function_70004D80:

base $70004DC4
function_70004DC4:

base $70004DD4
function_70004DD4:

base $70004DE0
function_70004DE0:

base $70004E2C
function_70004E2C:

base $70004E60
function_70004E60:

base $70004E88
function_70004E88:

base $70004E98
function_70004E98:

base $70004EAC
function_70004EAC:

base $70004EB4
function_70004EB4:

base $70004EBC
function_70004EBC:

base $70004EC4
function_70004EC4:

base $70004EE0
function_70004EE0:

base $70004F54
function_70004F54:

base $70004FC0
function_70004FC0:

base $70004FC4
function_70004FC4:

base $7000505C
function_7000505C:

base $70005064
function_70005064:

base $70005080
function_70005080:

base $700050AC
function_700050AC:

base $700050D4
function_700050D4:

base $7000511C
function_7000511C:

base $70005158
function_70005158:

base $70005190
function_70005190:

base $700051A8
function_700051A8:

base $700051B0
function_700051B0:

base $700051B8
function_700051B8:

base $700051D0
function_700051D0:

base $700051D4
function_700051D4:

base $700051E0
function_700051E0:

base $70005234
function_70005234:

base $7000524C
function_7000524C:

base $70005250
function_70005250:

base $70005258
function_70005258:

base $70005270
function_70005270:

base $7000528C
function_7000528C:

base $70005294
function_70005294:

base $70005334
function_70005334:

base $70005340
function_70005340:

base $70005370
function_70005370:

base $70005398
function_70005398:

base $700053A0
function_700053A0:

base $700053AC
function_700053AC:

base $700053C8
function_700053C8:

base $700053FC
function_700053FC:

base $70005404
function_70005404:

base $7000540C
function_7000540C:

base $70005414
function_70005414:

base $70005420
function_70005420:

base $700054A0
function_700054A0:

base $700054A8
function_700054A8:

base $700054CC
function_700054CC:

base $700054DC
function_700054DC:

base $700054E4
function_700054E4:

base $7000552C
function_7000552C:

base $70005534
function_70005534:

base $70005550
function_70005550:

base $70005558
function_70005558:

base $70005560
function_70005560:

base $7000559C
function_7000559C:

base $700055A4
function_700055A4:

base $700055C8
function_700055C8:

base $70005618
function_70005618:

base $70005628
function_70005628:

base $70005630
function_70005630:

base $70005654
function_70005654:

base $7000565C
function_7000565C:

base $70005668
function_70005668:

base $70005674
function_70005674:

base $70005678
function_70005678:

base $700056B4
function_700056B4:

base $700056BC
function_700056BC:

base $700056E8
function_700056E8:

base $70005708
function_70005708:

base $70005730
function_70005730:

base $70005774
function_70005774:

base $700057B8
function_700057B8:

base $700057BC
function_700057BC:

base $700057CC
function_700057CC:

base $700057E4
function_700057E4:

base $700057F0
function_700057F0:

base $70005810
function_70005810:

base $70005854
function_70005854:

base $7000585C
function_7000585C:

base $70005888
function_70005888:

base $700058E4
function_700058E4:

base $700058F8
function_700058F8:

base $700058FC
function_700058FC:

base $70005914
function_70005914:

base $70005918
function_70005918:

base $70005934
function_70005934:

base $70005938
function_70005938:

base $70005954
function_70005954:

base $70005958
function_70005958:

base $70005974
function_70005974:

base $70005984
function_70005984:

base $700059A4
function_700059A4:

base $700059D0
function_700059D0:

base $70005A2C
function_70005A2C:

base $70005A5C
function_70005A5C:

base $70005A9C
function_70005A9C:

base $70005AC0
function_70005AC0:

base $70005AD8
function_70005AD8:

base $70005ADC
function_70005ADC:

base $70005B10
function_70005B10:

base $70005B18
function_70005B18:

base $70005B44
function_70005B44:

base $70005B50
function_70005B50:

base $70005B60
function_70005B60:

base $70005B90
function_70005B90:

base $70005BF0
function_70005BF0:

base $70005C1C
function_70005C1C:

base $70005C44
function_70005C44:

base $70005CA8
function_70005CA8:

base $70005D08
function_70005D08:

base $70005D20
function_70005D20:

base $70005D30
function_70005D30:

base $70005DDC
function_70005DDC:

base $70005E68
function_70005E68:

base $70005E7C
function_70005E7C:

base $70005EA8
function_70005EA8:

base $70005ED0
function_70005ED0:

base $70005F10
function_70005F10:

base $70005FF4
function_70005FF4:

base $70006004
function_70006004:

base $7000601C
function_7000601C:

base $7000603C
function_7000603C:

base $70006050
function_70006050:

base $70006060
mainloop:

base $7000618C
function_7000618C:

base $700063F4
function_700063F4:

base $70006410
function_70006410:

base $7000641C
function_7000641C:

base $70006464
function_70006464:

base $700064D8
function_700064D8:

base $70006700
function_70006700:

base $70006724
function_70006724:

base $7000674C
function_7000674C:

base $700067A8
function_700067A8:

base $700067C0
function_700067C0:

base $70006808
function_70006808:

base $70006844
function_70006844:

base $70006854
function_70006854:

base $70006890
function_70006890:

base $7000689C
function_7000689C:

base $700068B4
function_700068B4:

base $70006930
run_title_stage:

base $70006950
function_70006950:

base $7000695C
get_stage_num:

base $70006968
function_70006968:

base $700069A4
function_700069A4:

base $700069B4
function_700069B4:

base $700069C0
function_700069C0:

base $700069F0
function_700069F0:

base $70006A08
function_70006A08:

base $70006A28
function_70006A28:

base $70006A30
function_70006A30:

base $70006A6C
function_70006A6C:

base $70006C88
function_70006C88:

base $70006CB4
function_70006CB4:

base $70006E68
function_70006E68:

base $70006E7C
function_70006E7C:

base $70006EB4
function_70006EB4:

base $70006ED4
function_70006ED4:

base $70006EE4
function_70006EE4:

base $70006F28
function_70006F28:

base $70006FBC
function_70006FBC:

base $70006FC0
function_70006FC0:

base $70006FD0
function_70006FD0:

base $70007018
function_70007018:

base $70007020
function_70007020:

base $70007030
function_70007030:

base $7000703C
function_7000703C:

base $700070A0
function_700070A0:

base $700070E4
function_700070E4:

base $700070F0
function_700070F0:

base $700070F8
function_700070F8:

base $70007158
function_70007158:

base $70007168
function_70007168:

base $700071B4
function_700071B4:

base $700071BC
function_700071BC:

base $700071F4
function_700071F4:

base $70007204
function_70007204:

base $7000723C
function_7000723C:

base $7000725C
function_7000725C:

base $7000726C
function_7000726C:

base $700072B0
function_700072B0:

base $70007344
function_70007344:

base $70007348
function_70007348:

base $70007358
function_70007358:

base $700073A0
function_700073A0:

base $700073A8
function_700073A8:

base $700073B8
function_700073B8:

base $700073C4
function_700073C4:

base $70007428
function_70007428:

base $7000746C
function_7000746C:

base $70007478
function_70007478:

base $70007480
function_70007480:

base $700074E0
function_700074E0:

base $700074F0
function_700074F0:

base $7000753C
function_7000753C:

base $70007544
function_70007544:

base $7000757C
function_7000757C:

base $7000758C
function_7000758C:

base $700075C4
function_700075C4:

base $700075E4
function_700075E4:

base $700075F4
function_700075F4:

base $70007638
function_70007638:

base $700076CC
function_700076CC:

base $700076D0
function_700076D0:

base $700076E0
function_700076E0:

base $70007728
function_70007728:

base $70007730
function_70007730:

base $70007740
function_70007740:

base $7000774C
function_7000774C:

base $700077B0
function_700077B0:

base $700077F4
function_700077F4:

base $70007800
function_70007800:

base $70007808
function_70007808:

base $70007868
function_70007868:

base $70007878
function_70007878:

base $700078C4
function_700078C4:

base $700078CC
function_700078CC:

base $70007904
function_70007904:

base $70007914
function_70007914:

base $700079B4
function_700079B4:

base $700079C0
function_700079C0:

base $70007A58
function_70007A58:

base $70007A64
function_70007A64:

base $70007AFC
function_70007AFC:

base $70007B08
function_70007B08:

base $70007B0C
function_70007B0C:

base $70007B20
function_70007B20:

base $70007BEC
function_70007BEC:

base $70007C18
function_70007C18:

base $70007DDC
function_70007DDC:

base $70007E0C
function_70007E0C:

base $70007E38
function_70007E38:

base $70007E44
function_70007E44:

base $70007E80
function_70007E80:

base $70007ED0
function_70007ED0:

base $70007EF4
function_70007EF4:

base $70007F10
function_70007F10:

base $70007F58
function_70007F58:

base $70007F7C
function_70007F7C:

base $70007F9C
function_70007F9C:

base $70007FBC
function_70007FBC:

base $70007FD8
function_70007FD8:

base $70008018
function_70008018:

base $7000802C
function_7000802C:

base $70008054
function_70008054:

base $7000807C
function_7000807C:

base $70008098
function_70008098:

base $700080F8
function_700080F8:

base $70008108
function_70008108:

base $7000812C
function_7000812C:

base $7000813C
function_7000813C:

base $7000814C
function_7000814C:

base $70008230
function_70008230:

base $70008284
function_70008284:

base $700082A0
function_700082A0:

base $700082A8
function_700082A8:

base $700082F8
function_700082F8:

base $700082FC
function_700082FC:

base $70008310
function_70008310:

base $70008320
function_70008320:

base $70008324
function_70008324:

base $70008388
function_70008388:

base $7000838C
function_7000838C:

base $700083A8
function_700083A8:

base $700083D4
function_700083D4:

base $70008444
function_70008444:

base $7000844C
function_7000844C:

base $70008454
function_70008454:

base $70008460
function_70008460:

base $70008464
function_70008464:

base $70008474
function_70008474:

base $7000847C
function_7000847C:

base $700084B4
function_700084B4:

base $700084D0
function_700084D0:

base $700084D8
function_700084D8:

base $700084E0
function_700084E0:

base $700084F0
function_700084F0:

base $70008538
function_70008538:

base $7000853C
function_7000853C:

base $7000854C
function_7000854C:

base $70008580
function_70008580:

base $70008584
function_70008584:

base $70008598
function_70008598:

base $700085A8
function_700085A8:

base $700085AC
function_700085AC:

base $700085B8
function_700085B8:

base $700085C8
function_700085C8:

base $7000866C
function_7000866C:

base $70008680
function_70008680:

base $70008690
function_70008690:

base $70008748
function_70008748:

base $70008764
function_70008764:

base $70008770
function_70008770:

base $7000880C
function_7000880C:

base $70008884
function_70008884:

base $70008890
function_70008890:

base $700088A8
function_700088A8:

base $700088CC
function_700088CC:

base $700088D4
def_70007FB4:

base $700088D8
function_700088D8:

base $700088F8
function_700088F8:

base $700088FC
function_700088FC:

base $7000891C
function_7000891C:

base $70008948
function_70008948:

base $70008994
function_70008994:

base $700089C4
function_700089C4:

base $70008A30
function_70008A30:

base $70008A74
function_70008A74:

base $70008AAC
function_70008AAC:

base $70008AC0
function_70008AC0:

base $70008AC8
function_70008AC8:

base $70008AF0
function_70008AF0:

base $70008B10
function_70008B10:

base $70008B24
function_70008B24:

base $70008B2C
function_70008B2C:

base $70008B40
function_70008B40:

base $70008B48
function_70008B48:

base $70008B5C
function_70008B5C:

base $70008B70
function_70008B70:

base $70008BF4
function_70008BF4:

base $70008C00
function_70008C00:

base $70008C94
function_70008C94:

base $70008CC8
function_70008CC8:

base $70008CE0
function_70008CE0:

base $70008CF0
function_70008CF0:

base $70008D04
function_70008D04:

base $70008D2C
function_70008D2C:

base $70008D3C
function_70008D3C:

base $70008D78
function_70008D78:

base $70008D80
function_70008D80:

base $70008DA8
function_70008DA8:

base $70008DC8
function_70008DC8:

base $70008DCC
function_70008DCC:

base $70008DD8
function_70008DD8:

base $70008DE8
function_70008DE8:

base $70008DF0
function_70008DF0:

base $70008E00
function_70008E00:

base $70008E08
function_70008E08:

base $70008E6C
function_70008E6C:

base $70008E7C
function_70008E7C:

base $70008E8C
function_70008E8C:

base $70008F34
function_70008F34:

base $70008F44
function_70008F44:

base $70008F48
function_70008F48:

base $70008F80
function_70008F80:

base $70008FE0
function_70008FE0:

base $70008FF0
function_70008FF0:

base $70009020
function_70009020:

base $7000905C
function_7000905C:

base $7000906C
function_7000906C:

base $700090C0
function_700090C0:

base $700090F0
function_700090F0:

base $700090FC
function_700090FC:

base $70009124
function_70009124:

base $70009134
function_70009134:

base $70009144
function_70009144:

base $70009154
function_70009154:

base $70009164
function_70009164:

base $70009174
function_70009174:

base $70009184
function_70009184:

base $700091B8
function_700091B8:

base $700091C8
function_700091C8:

base $700091E8
function_700091E8:

base $70009204
function_70009204:

base $70009238
function_70009238:

base $70009254
function_70009254:

base $70009264
function_70009264:

base $70009284
function_70009284:

base $700092E4
function_700092E4:

base $7000931C
function_7000931C:

base $7000935C
function_7000935C:

base $70009364
function_70009364:

base $70009380
function_70009380:

base $700093AC
function_700093AC:

base $70009450
function_70009450:

base $70009488
function_70009488:

base $700094C0
function_700094C0:

base $700094EC
function_700094EC:

base $700094FC
function_700094FC:

base $70009514
function_70009514:

base $7000958C
function_7000958C:

base $700095B0
function_700095B0:

base $700095F8
function_700095F8:

base $70009638
function_70009638:

base $70009720
allocate_viewport_bytes:

base $70009748
function_70009748:

base $70009764
function_70009764:

base $7000976C
function_7000976C:

base $70009788
function_70009788:

base $70009794
function_70009794:

base $700097D4
function_700097D4:

base $700097DC
function_700097DC:

base $700097E8
function_700097E8:

base $70009804
function_70009804:

base $70009840
function_70009840:

base $7000985C
function_7000985C:

base $70009868
function_70009868:

base $70009880
function_70009880:

base $70009898
function_70009898:

base $700098B4
function_700098B4:

base $700098C0
function_700098C0:

base $700098D0
function_700098D0:

base $700098D8
function_700098D8:

base $700098E0
function_700098E0:

base $700098F0
function_700098F0:

base $700098F4
function_700098F4:

base $70009910
function_70009910:

base $7000992C
function_7000992C:

base $70009950
function_70009950:

base $70009970
function_70009970:

base $7000998C
function_7000998C:

base $7000999C
reset_mem_bank_a0:

base $700099C4
function_700099C4:

base $700099FC
function_700099FC:

base $70009A10
function_70009A10:

base $70009A34
function_70009A34:

base $70009A50
function_70009A50:

base $70009A8C
function_70009A8C:

base $70009AB8
function_70009AB8:

base $70009AE0
function_70009AE0:

base $70009AE8
function_70009AE8:

base $70009AF4
function_70009AF4:

base $70009B18
function_70009B18:

base $70009B3C
function_70009B3C:

base $70009B50
function_70009B50:

base $70009B60
function_70009B60:

base $70009B8C
function_70009B8C:

base $70009B94
function_70009B94:

base $70009BB0
function_70009BB0:

base $70009BD8
function_70009BD8:

base $70009BFC
function_70009BFC:

base $70009C10
function_70009C10:

base $70009C30
function_70009C30:

base $70009C48
function_70009C48:

base $70009C54
function_70009C54:

base $70009C58
function_70009C58:

base $70009C74
function_70009C74:

base $70009CD4
function_70009CD4:

base $70009CEC
function_70009CEC:

base $70009CFC
function_70009CFC:

base $70009D0C
function_70009D0C:

base $70009D24
function_70009D24:

base $70009D30
function_70009D30:

base $70009D50
function_70009D50:

base $70009D6C
function_70009D6C:

base $70009D98
reset_memtable_base_allocation:

base $70009DD8
function_70009DD8:

base $70009E10
function_70009E10:

base $70009E34
function_70009E34:

base $70009E74
function_70009E74:

base $70009EBC
function_70009EBC:

base $70009EC4
function_70009EC4:

base $70009EE8
function_70009EE8:

base $70009EF8
function_70009EF8:

base $70009F10
function_70009F10:

base $70009F38
function_70009F38:

base $70009F4C
function_70009F4C:

base $70009F60
function_70009F60:

base $70009F64
function_70009F64:

base $70009F80
function_70009F80:

base $70009F84
function_70009F84:

base $70009FA8
function_70009FA8:

base $70009FCC
function_70009FCC:

base $70009FE8
function_70009FE8:

base $70009FF4
function_70009FF4:

base $7000A000
function_7000A000:

base $7000A014
function_7000A014:

base $7000A020
function_7000A020:

base $7000A040
function_7000A040:

base $7000A054
function_7000A054:

base $7000A064
function_7000A064:

base $7000A088
function_7000A088:

base $7000A098
function_7000A098:

base $7000A0A8
function_7000A0A8:

base $7000A0BC
function_7000A0BC:

base $7000A0DC
function_7000A0DC:

base $7000A0F4
function_7000A0F4:

base $7000A100
function_7000A100:

base $7000A150
function_7000A150:

base $7000A16C
function_7000A16C:

base $7000A18C
function_7000A18C:

base $7000A198
function_7000A198:

base $7000A1B4
function_7000A1B4:

base $7000A1B8
function_7000A1B8:

base $7000A1C4
function_7000A1C4:

base $7000A1DC
function_7000A1DC:

base $7000A20C
function_7000A20C:

base $7000A220
function_7000A220:

base $7000A228
function_7000A228:

base $7000A244
function_7000A244:

base $7000A250
function_7000A250:

base $7000A26C
function_7000A26C:

base $7000A29C
function_7000A29C:

base $7000A2C4
function_7000A2C4:

base $7000A2F8
function_7000A2F8:

base $7000A338
function_7000A338:

base $7000A354
function_7000A354:

base $7000A370
function_7000A370:

base $7000A3A0
function_7000A3A0:

base $7000A3B4
function_7000A3B4:

base $7000A3C0
function_7000A3C0:

base $7000A3D0
function_7000A3D0:

base $7000A3D4
function_7000A3D4:

base $7000A3DC
function_7000A3DC:

base $7000A410
function_7000A410:

base $7000A418
function_7000A418:

base $7000A430
function_7000A430:

base $7000A434
function_7000A434:

base $7000A450
function_7000A450:

base $7000A498
increment_random_num:

base $7000A4AC
function_7000A4AC:

base $7000A4F0
function_7000A4F0:

base $7000A524
function_7000A524:

base $7000A530
function_7000A530:

base $7000A544
function_7000A544:

base $7000A56C
function_7000A56C:

base $7000A57C
function_7000A57C:

base $7000A584
function_7000A584:

base $7000A58C
strtok:

base $7000A5C0
function_7000A5C0:

base $7000A5F8
function_7000A5F8:

base $7000A604
function_7000A604:

base $7000A61C
function_7000A61C:

base $7000A648
function_7000A648:

base $7000A668
function_7000A668:

base $7000A684
function_7000A684:

base $7000A6A0
check_token:

base $7000A6F8
function_7000A6F8:

base $7000A728
function_7000A728:

base $7000A73C
function_7000A73C:

base $7000A740
function_7000A740:

base $7000A770
function_7000A770:

base $7000A784
function_7000A784:

base $7000A798
function_7000A798:

base $7000A7A0
function_7000A7A0:

base $7000A7B4
function_7000A7B4:

base $7000A7D4
function_7000A7D4:

base $7000A7D8
function_7000A7D8:

base $7000A7E0
function_7000A7E0:

base $7000A7F4
function_7000A7F4:

base $7000A7FC
function_7000A7FC:

base $7000A810
function_7000A810:

base $7000A820
function_7000A820:

base $7000A830
function_7000A830:

base $7000A844
function_7000A844:

base $7000A84C
function_7000A84C:

base $7000A870
function_7000A870:

base $7000A878
function_7000A878:

base $7000A888
function_7000A888:

base $7000A890
function_7000A890:

base $7000A898
function_7000A898:

base $7000A8AC
function_7000A8AC:

base $7000A8D0
function_7000A8D0:

base $7000A8D8
function_7000A8D8:

base $7000A8E8
function_7000A8E8:

base $7000A8F0
function_7000A8F0:

base $7000A8F8
function_7000A8F8:

base $7000A924
function_7000A924:

base $7000A930
function_7000A930:

base $7000A948
function_7000A948:

base $7000A950
function_7000A950:

base $7000A970
function_7000A970:

base $7000A984
function_7000A984:

base $7000A98C
function_7000A98C:

base $7000A9D8
function_7000A9D8:

base $7000A9E0
strtol:

base $7000AA20
function_7000AA20:

base $7000AA28
function_7000AA28:

base $7000AA40
function_7000AA40:

base $7000AA54
function_7000AA54:

base $7000AA74
function_7000AA74:

base $7000AA90
function_7000AA90:

base $7000AAC4
function_7000AAC4:

base $7000AAF8
function_7000AAF8:

base $7000AB00
function_7000AB00:

base $7000AB1C
function_7000AB1C:

base $7000AB40
function_7000AB40:

base $7000AB64
function_7000AB64:

base $7000AB88
function_7000AB88:

base $7000ABB0
function_7000ABB0:

base $7000ABB8
function_7000ABB8:

base $7000ABC0
function_7000ABC0:

base $7000ABD0
function_7000ABD0:

base $7000ABE0
function_7000ABE0:

base $7000ABE4
function_7000ABE4:

base $7000AC00
function_7000AC00:

base $7000AC14
function_7000AC14:

base $7000AC24
function_7000AC24:

base $7000AC30
function_7000AC30:

base $7000AC44
function_7000AC44:

base $7000AC70
function_7000AC70:

base $7000AC94
sprintf:

base $7000ACD8
function_7000ACD8:

base $7000ACF0
function_7000ACF0:

base $7000AD30
function_7000AD30:

base $7000AD38
function_7000AD38:

base $7000AD80
function_7000AD80:

base $7000AD90
function_7000AD90:

base $7000ADA0
function_7000ADA0:

base $7000ADA8
function_7000ADA8:

base $7000ADB0
function_7000ADB0:

base $7000ADD0
function_7000ADD0:

base $7000AE08
function_7000AE08:

base $7000AE30
function_7000AE30:

base $7000AE9C
function_7000AE9C:

base $7000AEA8
function_7000AEA8:

base $7000AEDC
function_7000AEDC:

base $7000AF00
function_7000AF00:

base $7000AF28
function_7000AF28:

base $7000AF2C
function_7000AF2C:

base $7000AF84
function_7000AF84:

base $7000AF98
function_7000AF98:

base $7000AFBC
function_7000AFBC:

base $7000AFD0
function_7000AFD0:

base $7000AFF4
function_7000AFF4:

base $7000AFFC
function_7000AFFC:

base $7000B018
function_7000B018:

base $7000B040
function_7000B040:

base $7000B06C
function_7000B06C:

base $7000B098
function_7000B098:

base $7000B0C4
function_7000B0C4:

base $7000B0E8
function_7000B0E8:

base $7000B120
function_7000B120:

base $7000B148
function_7000B148:

base $7000B184
function_7000B184:

base $7000B1B0
function_7000B1B0:

base $7000B1B4
function_7000B1B4:

base $7000B1C0
function_7000B1C0:

base $7000B1D8
function_7000B1D8:

base $7000B1E8
function_7000B1E8:

base $7000B208
function_7000B208:

base $7000B21C
function_7000B21C:

base $7000B230
function_7000B230:

base $7000B254
function_7000B254:

base $7000B268
function_7000B268:

base $7000B27C
function_7000B27C:

base $7000B2C4
function_7000B2C4:

base $7000B2D0
function_7000B2D0:

base $7000B2F8
function_7000B2F8:

base $7000B32C
function_7000B32C:

base $7000B340
function_7000B340:

base $7000B360
function_7000B360:

base $7000B378
function_7000B378:

base $7000B38C
function_7000B38C:

base $7000B398
function_7000B398:

base $7000B39C
function_7000B39C:

base $7000B3D0
function_7000B3D0:

base $7000B3E4
function_7000B3E4:

base $7000B42C
function_7000B42C:

base $7000B500
function_7000B500:

base $7000B504
function_7000B504:

base $7000B528
function_7000B528:

base $7000B560
function_7000B560:

base $7000B63C
function_7000B63C:

base $7000B6AC
function_7000B6AC:

base $7000B718
function_7000B718:

base $7000B728
function_7000B728:

base $7000B734
function_7000B734:

base $7000B7D4
function_7000B7D4:

base $7000B7F8
function_7000B7F8:

base $7000B800
function_7000B800:

base $7000B804
function_7000B804:

base $7000B810
function_7000B810:

base $7000B85C
function_7000B85C:

base $7000B8AC
function_7000B8AC:

base $7000B8C4
function_7000B8C4:

base $7000B8D8
function_7000B8D8:

base $7000B8EC
function_7000B8EC:

base $7000B8F0
function_7000B8F0:

base $7000B8F8
function_7000B8F8:

base $7000B920
function_7000B920:

base $7000B980
function_7000B980:

base $7000B9A4
function_7000B9A4:

base $7000B9B0
function_7000B9B0:

base $7000B9B4
function_7000B9B4:

base $7000B9CC
function_7000B9CC:

base $7000B9F8
function_7000B9F8:

base $7000BA20
function_7000BA20:

base $7000BA38
function_7000BA38:

base $7000BA48
function_7000BA48:

base $7000BA58
function_7000BA58:

base $7000BA68
function_7000BA68:

base $7000BA70
function_7000BA70:

base $7000BA7C
function_7000BA7C:

base $7000BAC8
function_7000BAC8:

base $7000BB10
function_7000BB10:

base $7000BB20
function_7000BB20:

base $7000BB38
function_7000BB38:

base $7000BB44
function_7000BB44:

base $7000BB60
function_7000BB60:

base $7000BB74
function_7000BB74:

base $7000BBA8
function_7000BBA8:

base $7000BBBC
function_7000BBBC:

base $7000BBC8
function_7000BBC8:

base $7000BBE4
function_7000BBE4:

base $7000BC1C
function_7000BC1C:

base $7000BC34
function_7000BC34:

base $7000BC38
function_7000BC38:

base $7000BC84
function_7000BC84:

base $7000BC9C
function_7000BC9C:

base $7000BCCC
function_7000BCCC:

base $7000BCE4
function_7000BCE4:

base $7000BCEC
function_7000BCEC:

base $7000BCF0
function_7000BCF0:

base $7000BD0C
redirect_to_ramrom_replay_and_record_handlers_if_set:

base $7000BD48
function_7000BD48:

base $7000BD7C
function_7000BD7C:

base $7000BD88
function_7000BD88:

base $7000BDD0
function_7000BDD0:

base $7000BDFC
function_7000BDFC:

base $7000BE58
function_7000BE58:

base $7000BEC8
function_7000BEC8:

base $7000BF38
function_7000BF38:

base $7000BF50
function_7000BF50:

base $7000BF8C
function_7000BF8C:

base $7000BFB8
function_7000BFB8:

base $7000BFC8
function_7000BFC8:

base $7000BFCC
function_7000BFCC:

base $7000BFDC
function_7000BFDC:

base $7000C040
function_7000C040:

base $7000C074
function_7000C074:

base $7000C084
function_7000C084:

base $7000C0B4
function_7000C0B4:

base $7000C0C4
function_7000C0C4:

base $7000C0DC
function_7000C0DC:

base $7000C0E0
function_7000C0E0:

base $7000C0EC
get_cur.controller_horz.stick.pos:

base $7000C144
function_7000C144:

base $7000C174
function_7000C174:

base $7000C1CC
function_7000C1CC:

base $7000C1FC
get_cur.controller_vert.stick.pos:

base $7000C254
function_7000C254:

base $7000C284
function_7000C284:

base $7000C2DC
function_7000C2DC:

base $7000C30C
get_controller_buttons_held:

base $7000C370
function_7000C370:

base $7000C3AC
get_controller_buttons_pressed:

base $7000C410
function_7000C410:

base $7000C430
function_7000C430:

base $7000C440
function_7000C440:

base $7000C470
function_7000C470:

base $7000C48C
function_7000C48C:

base $7000C4A4
function_7000C4A4:

base $7000C4B4
function_7000C4B4:

base $7000C4E8
function_7000C4E8:

base $7000C4F4
function_7000C4F4:

base $7000C528
function_7000C528:

base $7000C55C
function_7000C55C:

base $7000C568
function_7000C568:

base $7000C59C
function_7000C59C:

base $7000C5D0
function_7000C5D0:

base $7000C5E0
function_7000C5E0:

base $7000C60C
function_7000C60C:

base $7000C640
function_7000C640:

base $7000C650
function_7000C650:

base $7000C67C
function_7000C67C:

base $7000C6BC
function_7000C6BC:

base $7000C6FC
function_7000C6FC:

base $7000C728
function_7000C728:

base $7000C734
function_7000C734:

base $7000C76C
function_7000C76C:

base $7000C778
function_7000C778:

base $7000C7B0
function_7000C7B0:

base $7000C7BC
function_7000C7BC:

base $7000C7FC
function_7000C7FC:

base $7000C808
function_7000C808:

base $7000C848
function_7000C848:

base $7000C854
function_7000C854:

base $7000C8BC
function_7000C8BC:

base $7000C8D4
function_7000C8D4:

base $7000C8DC
reset_cont_rumble_detect:

base $7000C930
function_7000C930:

base $7000C954
function_7000C954:

base $7000C980
send_rumble_off_to_PIF:

base $7000CA18
function_7000CA18:

base $7000CA28
function_7000CA28:

base $7000CA2C
function_7000CA2C:

base $7000CA30
function_7000CA30:

base $7000CA90
function_7000CA90:

base $7000CAAC
function_7000CAAC:

base $7000CB44
function_7000CB44:

base $7000CB54
function_7000CB54:

base $7000CB58
function_7000CB58:

base $7000CB5C
function_7000CB5C:

base $7000CBC0
function_7000CBC0:

base $7000CBDC
function_7000CBDC:

base $7000CBFC
function_7000CBFC:

base $7000CC70
function_7000CC70:

base $7000CCA4
function_7000CCA4:

base $7000CCB8
function_7000CCB8:

base $7000CCD4
function_7000CCD4:

base $7000CCDC
function_7000CCDC:

base $7000CD38
function_7000CD38:

base $7000CD64
function_7000CD64:

base $7000CDB4
function_7000CDB4:

base $7000CDC4
function_7000CDC4:

base $7000CDE4
function_7000CDE4:

base $7000CDF8
function_7000CDF8:

base $7000CE10
function_7000CE10:

base $7000CE8C
function_7000CE8C:

base $7000CE90
function_7000CE90:

base $7000CEA0
function_7000CEA0:

base $7000CEA8
function_7000CEA8:

base $7000CEB0
function_7000CEB0:

base $7000CEB8
function_7000CEB8:

base $7000CEC0
function_7000CEC0:

base $7000CEC8
function_7000CEC8:

base $7000CED0
function_7000CED0:

base $7000CED8
function_7000CED8:

base $7000CEE0
function_7000CEE0:

base $7000CEE8
function_7000CEE8:

base $7000CF14
function_7000CF14:

base $7000CF28
function_7000CF28:

base $7000CF44
function_7000CF44:

include "../lib/libultra_rom.asm"
insert binarybootcode, "boot.bin", (origin() - $1000)

base origin()
seg_boot_rom_end:

