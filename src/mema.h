#ifndef _MEMA_H_
#define _MEMA_H_

#include "ultra64.h"


typedef struct s_mem_alloc_entry {
    s32 addr;
    s32 size;
} s_mem_alloc_entry;

typedef struct s_mem_alloc_table {
    struct s_mem_alloc_entry entries[0x200];
} s_mem_alloc_table;

extern struct s_mem_alloc_table ptr_table_allocated_mem_blocks;

void memaSwap(u8 *a,u8 *b);
void memaMerge(void *arg0, void *arg1);
u32 memaSortMergeEntries(struct s_mem_alloc_table *param_1);
void memaSortMergeAllEntries(void);
u32 mem_related(s32 arg0);
void memaAllocRoomBuffer(u32 addr,u32 size);
void something_with_mema_c_debug(void);

#endif
