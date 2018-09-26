#ifndef _BOOT_H_
#define _BOOT_H_
#include <ultra64.h>

static u32 get_cdata_vaddr_start(void);
static u32 get_rodata_rom_start(void);
static u32 get_rodata_rom_end(void);
static u32 getRareZipASMRomstart(void);
static u32 getRareZipASMRomend(void);
static u32 jump_decompressfile(void);

#endif
