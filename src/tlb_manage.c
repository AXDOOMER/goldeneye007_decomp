#include "ultra64.h"
#include "ramrom.h"
#include "tlb_manage.h"
#include "tlb_random.h"
#include "PR/os_cache.h"

/**
 * @file tlb_manage.c
 * This file contains tlb management code. 
 * 
 * In particular, it:
 *   - 
 *   - 
 *   - 
 */

s32 maybe_cur_TLB_entries = 0;
u32 tlb_segment_num = 0;

struct s_tlbmanage_table_entry TLB_managment_table[128];
struct s_tlbmapping_table_entry TLB_manager_mapping_table[90];
u32 TLB_manager_mapping_table_end;
 u8 (*ptr_TLBallocatedblock) [0x2000];

extern u8 *_gameSegmentRomStart;
extern u8 *_tlbbufSegmentStart;
extern u8 *sp_boot;

void establish_TLB_buffer_management_table(void) {
    s32 i;
    for (i = 0; i < 128; i++) {
        TLB_managment_table[i].context_value = 1;
        TLB_managment_table[i].pagenum = 0;
    }
    for (i = 0; i < 90; i++) {
        TLB_manager_mapping_table[i].entry1 = 0;
        TLB_manager_mapping_table[i].entry0 = 1;
    }
    ptr_TLBallocatedblock = ((u32)&sp_boot & ~0x1FFF) + 0xFFF4C000;
    TLB_manager_mapping_table_end = ((u32)&TLB_managment_table) + 0xFFC08000;
}

void mp_tlb_related(void)
{
    s32 *t = &maybe_cur_TLB_entries;

    if (maybe_cur_TLB_entries < 51)
    {
        if (maybe_cur_TLB_entries < 26)
        {
            s32 t3 = *t;
            if (t3)
            {
                // removed
            }
        }
    }

    maybe_cur_TLB_entries = 0;
}


/**
 * 24C0    700018C0
 * searches TLB index for an entry matching A0
 *    V0=index of match or 80000000 if not found
 *    accepts: A0=TLB pointer
 */
s32 return_TLB_index_for_entry(int entry) {
    s32 index = 0;
    while (index != 0x20) {
        if (__osGetTLBHi(index) == entry) {
            return index;
        }
        index++;
    };
    return -0x80000000;
}

/**
 *  2520    70001920
 * find and remove TLB entry A0
 *    accepts: A0=TLB pointer
 *    redirects to 700018C0, 7000D3D0
 */
void find_remove_TLB_entry(u32 entry) {
    s32 index = return_TLB_index_for_entry(entry);

    if ((index & 0x80000000))
        return;

    osUnmapTLB(index);
}

/**
 * 2554    70001954
 * remove index A0 TLB entry from table at 8005E3F0
 *    table format:
 *        0x0    1 if dirty
 *        0x1    chunk # (7F000000 | chunk<<D)
 */
void remove_TLB_entry_from_table(s32 index) {
    s32 ret;

    if (TLB_manager_mapping_table[index].entry0 == 0)
    {
        ret = return_TLB_index_for_entry((TLB_manager_mapping_table[index].entry1 << 13) | 0x7F000000);

        if (!(ret & 0x80000000))
        {
            osUnmapTLB(ret);
        }

        TLB_managment_table[TLB_manager_mapping_table[index].entry1].context_value = 1;
        TLB_manager_mapping_table[index].entry0 = 1;
    }
}

/**
 * 25D8    700019D8
 * loads ROM range for 7F- TLB entries
 */
void translate_load_rom_from_TLBaddress(u32 address)
{
    u32 unused_0[1];
    u32 var1;
    u32 var2;
    u32 var4;
    u32 unused_1[1];
    u32 addr_copy;
    u32 var5; // sp 52
    u32 unused_2[1];
    u32 unused_3[1];

    addr_copy = address & 0x7FFFE000;
    maybe_cur_TLB_entries++;
    find_remove_TLB_entry(addr_copy);
    tlb_segment_num = tlbRandomGetNext() % 90;
    var4 = tlb_segment_num;
    remove_TLB_entry_from_table(var4);
    
    var1 = addr_copy & 0xFFE000;
    var5 = &(*ptr_TLBallocatedblock)[var4 << 13];

    romCopy(var5, ((u32)&_gameSegmentRomStart) + var1, 0x2000);

    osInvalICache((void *)0x40000000, 0x40000000);
    osInvalICache((void *)0x80000000, 0x10000000);
    var2 = var1 >> 13;
    TLB_managment_table[var2].pagenum = var4;
    TLB_managment_table[var2].context_value = ((osVirtualToPhysical(var5) >> 0xC) << 6) | 0x1F;
    TLB_manager_mapping_table[var4].entry0 = 0;
    TLB_manager_mapping_table[var4].entry1 = var2;
}

/**
 * 26F8    70001AF8
 * V0=p->TLB memory, or alternately end of free memory [8005E4A8]
 */
u8 * return_ptr_TLBallocatedblock(void)
{
    return ptr_TLBallocatedblock;
}






