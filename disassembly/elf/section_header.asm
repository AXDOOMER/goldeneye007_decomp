//origin $00090A58

//constant E_SHNUM($17)
constant E_SHNUM($0C)
constant E_SHENTSIZE($28)

section_header_start: //0x00090A58
//section_header(name, type, flags, address, offset, size, link, info, addralign, entsize) 
//00
sh_null:
section_header(shstrtab_start, SHT_NULL, SHF_NONE, $00000000, $0, $0, SHN_UNDEF, $0, $0, $0)
//01
sh_boot:
section_header(name_boot, SHT_PROGBITS, (SHF_ALLOC | SHF_EXECINSTR), $80000460, program_boot_start, program_boot_end - program_boot_start, SHN_UNDEF, $0, $20, $0)
//02
sh_boot_bss:
section_header(name_boot_bss, SHT_NOBITS, (SHF_WRITE | SHF_ALLOC), $80012370, $65F30, $4A30, SHN_UNDEF, $0, $10, $0)
//03
sh_code:
section_header(name_code, SHT_PROGBITS, (SHF_ALLOC | SHF_EXECINSTR), $8001CE60, program_code_start, program_code_end - program_code_start, SHN_UNDEF, $0, $20, $0)
//04
sh_code_bss:
section_header(name_code_bss, SHT_NOBITS, (SHF_WRITE | SHF_ALLOC), $80157D90, $65F30, $B8C50, SHN_UNDEF, $0, $10, $0)

sh_cfb:
section_header(name_cfb, SHT_PROGBITS, (SHF_ALLOC | SHF_EXECINSTR), $80320000, program_cfb_start, $0, SHN_UNDEF, $0, $10, $0)

sh_cfb_bss:
section_header(name_cfb_bss, SHT_NOBITS, (SHF_WRITE | SHF_ALLOC), $80320000, program_cfb_start, $4B000, SHN_UNDEF, $0, $10, $0)

sh_rsp_cfb:
section_header(name_rsp_cfb, SHT_PROGBITS, (SHF_ALLOC | SHF_EXECINSTR), $02000000, program_rsp_cfb_start, $0, SHN_UNDEF, $0, $10, $0)

sh_rsp_cfb_bss:
section_header(name_cfb_bss, SHT_NOBITS, (SHF_WRITE | SHF_ALLOC), $02000000, program_rsp_cfb_start, $25800, SHN_UNDEF, $0, $10, $0)

sh_kbuffer:
section_header(name_kbuffer, SHT_PROGBITS, (SHF_ALLOC | SHF_EXECINSTR), $8036B000, program_kbuffer_start, $0, SHN_UNDEF, $0, $10, $0)

sh_kbuffer_bss:
section_header(name_kbuffer_bss, SHT_NOBITS, (SHF_WRITE | SHF_ALLOC), $8036B000, program_kbuffer_start, $12C00, SHN_UNDEF, $0, $10, $0)

sh_reginfo:
section_header(name_reginfo, SHT_DYNAMIC, SHF_ALLOC, $00000000, program_reginfo_start, $18, SHN_UNDEF, $0, $4, $1)

sh_debug:
//section_header(name_debug, SHT_PROGBITS, SHF_NONE, $00000000, $7B000, $6FAC, SHN_UNDEF, $0, $4, $0)

sh_debug_srcinfo:
//section_header(name_debug_srcinfo, (SHT_DEBUG | SHT_LOPROC), SHF_NONE, $00000000, $81FAC, $17C, SHN_UNDEF, $0, $1, $0)

sh_debug_aranges:
//section_header(name_debug_aranges, (SHT_DEBUG | SHT_LOPROC), SHF_NONE, $00000000, $82128, $2EC, SHN_UNDEF, $0, $1, $0)

sh_debug_pubnames:
//section_header(name_debug_pubnames, (SHT_DEBUG | SHT_LOPROC), SHF_NONE, $00000000, $82414, $5E2, SHN_UNDEF, $0, $1, $0)

sh_debug_sfnames:
//section_header(name_debug_sfnames, SHT_DEBUG, SHF_NONE, $00000000, $829F6, $1C5, SHN_UNDEF, $0, $1, $0)

sh_line:
//section_header(name_line, SHT_PROGBITS, SHF_NONE, $00000000, $82BBB, $3262, SHN_UNDEF, $0, $1, $0)

sh_comment:
//section_header(name_comment, SHT_PROGBITS, SHF_NONE, $00000000, $85E1D, $8C6, SHN_UNDEF, $0, $1, $0)

sh_mdebug:
//section_header(name_mdebug, (SHT_HASH | SHT_LOPROC), SHF_NONE, $00000000, $866E4, $A2A0, SHN_UNDEF, $0, $4, $1)
//14 (c)
sh_shstrtab:
section_header(name_shstrtab, SHT_STRTAB, SHF_NONE, $00000000, shstrtab_start, (shstrtab_end - shstrtab_start), SHN_UNDEF, $0, $1, $0)

sh_symtab:
//section_header(name_symtab, SHT_SYMTAB, SHF_NONE, $00000000, $90DA0, $4960, $14, $23C, $4, $10)

sh_strtab:
//section_header(name_strtab, SHT_STRTAB, SHF_NONE, $00000000, $95700, $3841, SHN_UNDEF, $0, $1, $0)

section_header_end:
