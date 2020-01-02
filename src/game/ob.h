#ifndef _OB_H_
#define _OB_H_
#include "ultra64.h"

struct resource_lookup_data_entry {
    u32 romsize;
    u32 temp_remaining;
    u32 temp_pc_size;
    u32 remaining;
    u8 loaded_bank;
    u8 unk_11;
    u16 reserved;
};

struct fileentry {
    s32 index;
    char *filename;
    void *size;
};

void something_mem_bank_a0(int);
void sub_GAME_7F0BD234(void);

#endif
