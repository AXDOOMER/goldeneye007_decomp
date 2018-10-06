#ifndef _BOND_H_
#define _BOND_H_

extern u32 *_codeSegmentVaddrStart;
extern u32 *_codeSegmentVaddrEnd;
extern u32 *_codeSegmentRomStart;
extern u32 *_codeSegmentRomEnd;

extern u32 *_cdataSegmentVaddrStart;
extern u32 *_cdataSegmentVaddrEnd;
extern u32 *_cdataSegmentRomStart;
extern u32 *_cdataSegmentRomEnd;

extern u32 *_rarezipSegmentVaddrStart;
extern u32 *_rarezipSegmentVaddrEnd;
extern u32 *_rarezipSegmentRomStart;
extern u32 *_rarezipSegmentRomEnd;

extern u32 *_gameSegmentVaddrStart;
extern u32 *_gameSegmentVaddrEnd;
extern u32 *_gameSegmentRomStart;
extern u32 *_gameSegmentRomEnd;


extern u8 sp_boot[];
extern u8 sp_rmon[];
extern u8 sp_idle[];
extern u8 sp_shed[];
extern u8 sp_main[];
extern u8 sp_audi[];
extern u8 sp_debug[];

#endif
