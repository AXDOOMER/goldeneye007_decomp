#ifndef _OB_H_
#define _OB_H_
#include "ultra64.h"

struct resource_lookup_data_entry {
    u32 rom_size;
    u32 pc_remaining;
    u32 pc_size;
    u32 rom_remaining;
    u8 loaded_bank;
    u8 unk_11;
    u16 reserved;
};

struct fileentry {
    s32 index;
    char *filename;
    u8 *hw_address;
};

void something_mem_bank_a0(int);
void sub_GAME_7F0BD234(void);

#endif
