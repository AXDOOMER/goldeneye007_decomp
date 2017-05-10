base $80000400
scope boot {
start:;scope start {
//Start inits bss then jumps to establishrootTLB
 define address(t0)
 define sizeleft(t1)
 define jumptarget(t2)

 //set {address} to bss_start and {sizeleft} to bss_size
 lui {address}, ((seg_bss_start>>16)+1) //+1 is due to sign extension 
 lui {sizeleft}, (seg_bss_size>>16)
 addiu {address}, {address}, seg_bss_start
 ori {sizeleft}, {sizeleft}, seg_bss_size

 clearmem:;scope {
  //blanks mem at {address} for {sizeleft}
  addi {sizeleft}, {sizeleft}, -8
  sw $0, 0({address})
  sw $0, 4({address})
  bnez {sizeleft}, clearmem
  addi {address}, {address}, 8 //delayslot
 }

 //sets {jumptarget} to establishrootTLB
 lui {jumptarget}, (establishrootTLB>>16)
 lui sp, ((sp_rmon>>16)+1) //+1 is due to sign extension
 addiu {jumptarget}, {jumptarget}, establishrootTLB

 //then jumps setting sp to address of sp_rom via delayslot
 jr {jumptarget} //jr establishrootTLB
 addiu sp, sp, sp_rmon //delayslot
 nop; nop; nop;
 nop; nop; nop;


 establishrootTLB:;scope {
  define index(v0)
  define entrylo0(v1)
  define entrylo1(a0)
  define entryhi({entrylo1}) //re-use {entrylo1} as {entryhi}
  define entryhi_flags(a1)
  define entrylo0_flags(a2)
  define entrylo1_flags(a3)
  define pagemask(t0)
  define jumptarget(t2)

  //TODO: define labels for flags
  addiu	{index}, $0, $0001
  addiu	{entrylo0}, $0, $0000
  addiu	{entrylo1}, $0, $0000
  lui	{entryhi_flags}, $7000
  addiu	{entrylo0_flags}, $0, $001F
  addiu	{entrylo1_flags}, $0, $0001

  lui	{pagemask}, (PM_4M >> 16)
  ori	{pagemask}, {pagemask}, PM_4M  //PM_4M = 0x7fe000
  mtc0	{index}, Index //COP0 Index = 1

  srl	{entrylo0}, {entrylo0}, 0xC
  sll	{entrylo0}, {entrylo0}, 0x6
  addu	{entrylo0}, {entrylo0}, {entrylo0_flags} //v1=a2
  mtc0	{entrylo0}, EntryLo0 //COP0 EntryLo0 = 1F: global, valid, dirty, cacheable noncoherent, even page#, map 00000000

  srl	{entrylo1}, {entrylo1}, 0xC
  sll	{entrylo1}, {entrylo1}, 0x6
  addu	{entrylo1}, {entrylo1}, {entrylo1_flags} //a0=a3
  mtc0	{entrylo1}, EntryLo1 //COP0 EntryLo1 = 1: global

  srl	{entryhi}, {entryhi_flags}, 0xD
  sll	{entryhi}, {entryhi}, 0xD //a0=a1
  mtc0	{entryhi}, EntryHi //COP0 EntryHi = 70000000: address space 0, VPN 70000
  mtc0	{pagemask}, PageMask //COP0 PageMask= 007FE000: mask for 2000byte entries up to 4MB
  nop
  tlbwi

  lui	{jumptarget}, (init >> 16)
  addiu	{jumptarget}, {jumptarget}, init
  jr	{jumptarget} //jr init
  nop
 }
}
}
