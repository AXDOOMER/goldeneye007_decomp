#ifndef _BOOT_H_
#define _BOOT_H_
#include <ultra64.h>

u32 *get_cdata_vaddr_start(void);
u32 *get_rodata_rom_start(void);
u32 *get_rodata_rom_end(void);
u32 *getRareZipASMRomstart(void);
u32 *getRareZipASMRomend(void);
u32 jump_decompressfile(u32 source, u32 target, u32 buffer);

#endif
