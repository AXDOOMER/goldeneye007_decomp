constant E_PHNUM($06)
constant E_PHENTSIZE($20)
//program_header( p_type, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_flags, p_align)

program_header_start:

ph_reginfo_start:
program_header(PT_LOAD, program_reginfo_start, $00000000, $00000000, $18, $18, PF_R, $10000)
ph_reginfo_end:

ph_rsp_cfb_start:
program_header(PT_LOAD, program_rsp_cfb_start, $02000000, $02000000, $0, $25800, (PF_X | PF_W | PF_R), $10000)
ph_rsp_cfb_end:

ph_boot_start:
program_header(PT_LOAD, program_boot_start, $80000460, $80000460, (program_boot_end - program_boot_start), $16940, (PF_X | PF_W | PF_R), $00010000)
ph_boot_end:

ph_code_start:
program_header(PT_LOAD, program_code_start, $8001CE60, $8001CE60, (program_code_end - program_code_start), $1F3B80, (PF_X | PF_W | PF_R), $00010000)
ph_code_end:

ph_cfb_start:
program_header(PT_LOAD, program_cfb_start, $80320000, $80320000, $0, $04B000, (PF_X | PF_W | PF_R), $00010000)
ph_cfb_end:

ph_kbuffer_start:
program_header(PT_LOAD, program_kbuffer_start, $8036B000, $8036B000, $0, $012C00, (PF_X | PF_W | PF_R), $00010000)
ph_kbuffer_end:

program_header_end:

