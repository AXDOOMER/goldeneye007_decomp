#ifndef _MEMA_H_
#define _MEMA_H_

#include "ultra64.h"

typedef struct allocation {
    s32 addr;
    u32 size;
} allocation;

void memaSwap(allocation *a,allocation *b);
void memaMerge(allocation *a, allocation *b);
s32 memaSortMergeEntries(allocation *allocations);
void memaSortMergeAllEntries(void);
allocation *memaFindOpening(allocation *allocations);
void memaAllocRoomBuffer(s32 addr, s32 size);
void memaInitDebugNoticeList(void);
void mempInitMallocTable(s32 buffer, s32 size);
void mem_related_calls_sort_merge_entries(void);
s32 mem_related_something_find_first(u32 arg0);
s32 mem_related_something_find_first_0(s32 arg0, u32 arg1);
void mem_related_model_room_buffers_0(u32 addr,u32 size) ;
void mem_related_allocated_table_related(void);
f32 mem_related_something_first_related(void);
void generate_list_alloc_mem(void);
void memaGenerateListsBeforeAfterMerge(void);
void mem_related_something_first_related_0(void *arg0);
u32 mem_related_0(void);
u32 mem_related_1(u32 addr,u32 length,u32 maxsize);
    
#endif
