#ifndef _BOOT_H_
#define _BOOT_H_
#include <ultra64.h>

u8 *get_csegmentSegmentStart(void);
u8 *get_cdataSegmentRomStart(void);
u8 *get_cdataSegmentRomEnd(void);
u8 *get_rarezipSegmentRomStart(void);
u8 *get_rarezipSegmentRomEnd(void);
u32 jump_decompressfile(u32 source, u32 target, u32 buffer);

#endif
