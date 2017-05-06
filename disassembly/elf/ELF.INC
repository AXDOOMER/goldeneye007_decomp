constant ET_NONE($0)
constant ET_REL($1)
constant ET_EXEC($2)
constant ET_DYN($3)
constant ET_CORE($4)
constant ET_LOPROC($ff00)
constant ET_HIPROC($ffff)

constant EM_NONE($0)
constant EM_M32($1)
constant EM_SPARC($2)
constant EM_386($3)
constant EM_68K($4)
constant EM_88K($5)
constant EM_860($7)
constant EM_MIPS($8)

constant EV_NONE($0)
constant EV_CURRENT($1)

macro program_header( p_type, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_flags, p_align) {
dw {p_type} //type
dw {p_offset} //offset
dw {p_vaddr} //size
dw {p_paddr} 
dw {p_filesz}
dw {p_memsz}
dw {p_flags}
dw {p_align}
}

constant PT_NULL($0)
constant PT_LOAD($1)
constant PT_DYNAMIC($2)
constant PT_INTERP($3)
constant PT_NOTE($4)
constant PT_SHLIB($5)
constant PT_PHDR($6)
constant PT_TLS($7)
constant PT_LOOS($60000000)
constant PT_HIOS($6fffffff)
constant PT_LOPROC($70000000)
constant PT_HIPROC($7fffffff)

constant PF_X($1)
constant PF_W($2)
constant PF_R($4)
constant PF_MASKOS($0ff00000)
constant PF_MASKPROC($f0000000)

macro section_header(name, type, flags, address, offset, size, link, info, addralign, entsize) {
dw {name} - shstrtab_start //name_offset
dw {type} //type
dw {flags} //flags
dw {address} //address
dw {offset} //offset
dw {size} //size
dw {link} 
dw {info}
dw {addralign}
dw {entsize}
}

constant SHT_NULL($0)
constant SHT_PROGBITS($1)
constant SHT_SYMTAB($2)
constant SHT_STRTAB($3)
constant SHT_RELA($4)
constant SHT_HASH($5)
constant SHT_DYNAMIC($6)
constant SHT_NOTE($7)
constant SHT_NOBITS($8)
constant SHT_REL($9)
constant SHT_SHLIB($10)
constant SHT_DYNSYM($11)
constant SHT_DEBUG($1E)
constant SHT_LOPROC($70000000)
constant SHT_HIPROC($7fffffff)
constant SHT_LOUSER($80000000)
constant SHT_HIUSER($ffffffff)

constant SHF_NONE($0)
constant SHF_WRITE($1)
constant SHF_ALLOC($2)
constant SHF_EXECINSTR($4)
constant SHF_MASKPROC($F0000000)

constant SHN_UNDEF($0)
