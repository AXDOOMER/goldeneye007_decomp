#include <ultra64.h>
#include "ramrom.h"
#include "tlb_manage.h"
#include "tlb_random.h"
#include <PR/os.h>

/**
 * @file tlb_manage.c
 * This file contains tlb management code. 
 */


/**
 * N64 (MIPS 4300) has 32 TLB entries.
 */
#define CPU_ARCH_MAX_TLB_ENTRIES 32

/**
 * TLB Entry consists of 13 unused bits, 12 bits for mask, and upper 7 bits unused.
 */
#define VAL_TO_TLB_MASK(x) (x << 13)

/**
 * TLB Entry consists of 13 unused bits, 12 bits for mask, and upper 7 bits unused.
 */
#define TLB_MASK_TO_VAL(x) (x >> 13)

/**
 * Number of entries in the TLB Management table.
 */
#define MANAGEMENT_TABLE_COUNT  128

/**
 * Number of entries in the mapping table.
 */
#define MAPPING_TABLE_COUNT  90



/**
 * Chosen by fair dice roll.
 * Guaranteed to be random.
 */
#ifndef VERSION_EU
#define TLB_RANDOM_MOD 90
#else
#define TLB_RANDOM_MOD 93
#endif

struct TlbManageTableEntry
{
    u32 contextValue;
    s32 pagenum;
    s64 RESERVED;
};

struct TlbManageMap
{
    u8 entry0;
    u8 entry1;
};

s32 g_tlbmanageCurrentTlbEntries = 0;
u32 g_tlbmanageTlbSegmentNumber = 0;

struct TlbManageTableEntry g_tlbmanageMangementTable[MANAGEMENT_TABLE_COUNT];
struct TlbManageMap g_tlbmanageMappingTable[MAPPING_TABLE_COUNT];
u32 g_tlbmanageMappingTableEnd;
u8 (*g_tlbmanageTlbAllocatedBlock) [TLB_ALLOCATION_BLOCK_SIZE];

extern u8 *_gameSegmentRomStart;
extern u8 *sp_boot;

#ifndef VERSION_EU
void tlbmanageEstablishManagementTable(void)
{
    s32 i;
    for (i = 0; i < MANAGEMENT_TABLE_COUNT; i++)
    {
        g_tlbmanageMangementTable[i].contextValue = 1;
        g_tlbmanageMangementTable[i].pagenum = 0;
    }

    for (i = 0; i < MAPPING_TABLE_COUNT; i++)
    {
        g_tlbmanageMappingTable[i].entry1 = 0;
        g_tlbmanageMappingTable[i].entry0 = 1;
    }

    g_tlbmanageTlbAllocatedBlock = (u8(*)[TLB_ALLOCATION_BLOCK_SIZE]) (((u32)&sp_boot & ~0x1FFF) + 0xFFF4C000);
    g_tlbmanageMappingTableEnd = ((u32)&g_tlbmanageMangementTable) + 0xFFC08000;
}
#else
#ifdef NONMATCHING
void tlbmanageEstablishManagementTable(void)
{
    s32 i;
    for (i = 0; i < MANAGEMENT_TABLE_COUNT; i++)
    {
        g_tlbmanageMangementTable[i].contextValue = 1;
        g_tlbmanageMangementTable[i].pagenum = 0;
    }

    for (i = 0; i < MAPPING_TABLE_COUNT; i++)
    {
        g_tlbmanageMappingTable[i].entry1 = 0;
        g_tlbmanageMappingTable[i].entry0 = 1;
        //get rid of extra copy here from optimizations in EU

    g_tlbmanageTlbAllocatedBlock = (u8(*)[TLB_ALLOCATION_BLOCK_SIZE]) (((u32)&sp_boot & ~0x1FFF) + 0xFFF4C000);
    g_tlbmanageMappingTableEnd = ((u32)&g_tlbmanageMangementTable) + 0xFFC08000;
}
#else
GLOBAL_ASM(
.text
glabel tlbmanageEstablishManagementTable
/* 0023E0 700017E0 3C038006 */  lui   $v1, %hi(g_tlbmanageMangementTable)
/* 0023E4 700017E4 3C028006 */  lui   $v0, %hi(g_tlbmanageMappingTable)
/* 0023E8 700017E8 2442E3F0 */  addiu $v0, %lo(g_tlbmanageMappingTable) # addiu $v0, $v0, -0x1c10
/* 0023EC 700017EC 2463DBF0 */  addiu $v1, %lo(g_tlbmanageMangementTable) # addiu $v1, $v1, -0x2410
/* 0023F0 700017F0 24040001 */  li    $a0, 1
.L700017F4:
/* 0023F4 700017F4 24630010 */  addiu $v1, $v1, 0x10
/* 0023F8 700017F8 0062082B */  sltu  $at, $v1, $v0
/* 0023FC 700017FC AC64FFF0 */  sw    $a0, -0x10($v1)
/* 002400 70001800 1420FFFC */  bnez  $at, .L700017F4
/* 002404 70001804 AC60FFF4 */   sw    $zero, -0xc($v1)
/* 002408 70001808 3C018006 */  lui   $at, %hi(g_tlbmanageMappingTable + 2)
/* 00240C 7000180C 3C038006 */  lui   $v1, %hi(g_tlbmanageMappingTable + 4)
/* 002410 70001810 3C028006 */  lui   $v0, %hi(g_tlbmanageMappingTableEnd)
/* 002414 70001814 2442E4A4 */  addiu $v0, %lo(g_tlbmanageMappingTableEnd) # addiu $v0, $v0, -0x1b5c
/* 002418 70001818 2463E3F4 */  addiu $v1, %lo(g_tlbmanageMappingTable + 4) # addiu $v1, $v1, -0x1c0c
/* 00241C 7000181C A020E3F1 */  sb    $zero, %lo(g_tlbmanageMappingTable + 1)($at)
/* 002420 70001820 A024E3F0 */  sb    $a0, %lo(g_tlbmanageMappingTable)($at)
/* 002424 70001824 A020E3F3 */  sb    $zero, %lo(g_tlbmanageMappingTable + 3)($at)
/* 002428 70001828 A024E3F2 */  sb    $a0, %lo(g_tlbmanageMappingTable + 2)($at)
.L7000182C:
/* 00242C 7000182C 24630008 */  addiu $v1, $v1, 8
/* 002430 70001830 A060FFFB */  sb    $zero, -5($v1)
/* 002434 70001834 A064FFFA */  sb    $a0, -6($v1)
/* 002438 70001838 A060FFFD */  sb    $zero, -3($v1)
/* 00243C 7000183C A064FFFC */  sb    $a0, -4($v1)
/* 002440 70001840 A060FFFF */  sb    $zero, -1($v1)
/* 002444 70001844 A064FFFE */  sb    $a0, -2($v1)
/* 002448 70001848 A060FFF9 */  sb    $zero, -7($v1)

/* 002454 70001854 3C0E803B */  lui   $t6, %hi(sp_boot) # $t6, 0x803b
/* 002458 70001858 25CEB400 */  addiu $t6, %lo(sp_boot) # addiu $t6, $t6, -0x4c00
/* 00245C 7000185C 2401E000 */  li    $at, -8192
/* 002460 70001860 01C17824 */  and   $t7, $t6, $at
/* 002464 70001864 3C01FFF4 */  lui   $at, (0xFFF4C000 >> 16) # lui $at, 0xfff4
/* 002468 70001868 3421C000 */  ori   $at, (0xFFF4C000 & 0xFFFF) # ori $at, $at, 0xc000
/* 00246C 7000186C 01E1C021 */  addu  $t8, $t7, $at
/* 002470 70001870 3C018006 */  lui   $at, %hi(g_tlbmanageTlbAllocatedBlock)
/* 002474 70001874 AC38E4A8 */  sw    $t8, %lo(g_tlbmanageTlbAllocatedBlock)($at)
/* 002478 70001878 3C01FFC0 */  lui   $at, (0xFFC08000 >> 16) # lui $at, 0xffc0
/* 00247C 7000187C 3C198006 */  lui   $t9, %hi(g_tlbmanageMangementTable) 
/* 002480 70001880 2739DBF0 */  addiu $t9, %lo(g_tlbmanageMangementTable) # addiu $t9, $t9, -0x2410
/* 002484 70001884 34218000 */  ori   $at, (0xFFC08000 & 0xFFFF) # ori $at, $at, 0x8000
/* 002488 70001888 03214021 */  addu  $t0, $t9, $at
/* 00248C 7000188C 3C018006 */  lui   $at, %hi(g_tlbmanageMappingTableEnd)
/* 002490 70001890 03E00008 */  jr    $ra
/* 002494 70001894 AC28E4A4 */   sw    $t0, %lo(g_tlbmanageMappingTableEnd)($at)
)
#endif
#endif

/**
 * Sets g_tlbmanageCurrentTlbEntries to zero.
 */
void tlbmanageResetCurrentEntriesCount(void)
{
    s32 *t = &g_tlbmanageCurrentTlbEntries;

    if (g_tlbmanageCurrentTlbEntries < 51)
    {
        if (g_tlbmanageCurrentTlbEntries < 26)
        {
            s32 t3 = *t;
            if (t3)
            {
                // removed
            }
        }
    }

    g_tlbmanageCurrentTlbEntries = 0;
}


/**
 * 24C0    700018C0
 * searches TLB index for an entry matching A0
 *    V0=index of match or 80000000 if not found
 *    accepts: A0=TLB pointer
 */
s32 tlbmanageGetIndexForEntry(int entry)
{
    s32 index = 0;

    while (index != CPU_ARCH_MAX_TLB_ENTRIES)
    {
        if (__osGetTLBHi(index) == entry)
        {
            return index;
        }

        index++;
    }

    return -0x80000000;
}

/**
 *  2520    70001920
 * find and remove TLB entry A0
 *    accepts: A0=TLB pointer
 *    redirects to 700018C0, 7000D3D0
 */
void tlbmanageRemoveEntry(u32 entry)
{
    s32 index = tlbmanageGetIndexForEntry(entry);

    if (index & 0x80000000)
    {
        return;
    }

    osUnmapTLB(index);
}

/**
 * 2554    70001954
 * remove index A0 TLB entry from table at 8005E3F0
 *    table format:
 *        0x0    1 if dirty
 *        0x1    chunk # (7F000000 | chunk<<D)
 */
void tlbmanageRemoveEntryByIndex(s32 index)
{
    s32 ret;

    if (g_tlbmanageMappingTable[index].entry0 == 0)
    {
        ret = tlbmanageGetIndexForEntry(VAL_TO_TLB_MASK(g_tlbmanageMappingTable[index].entry1) | 0x7F000000);

        if (!(ret & 0x80000000))
        {
            osUnmapTLB(ret);
        }

        g_tlbmanageMangementTable[g_tlbmanageMappingTable[index].entry1].contextValue = 1;
        g_tlbmanageMappingTable[index].entry0 = 1;
    }
}

/**
 * 25D8    700019D8
 * loads ROM range for 7F- TLB entries
 */
void tlbmanageTranslateLoadRomFromTlbAddress(u32 address)
{
    u32 unused_0[1];
    u32 var1;
    u32 var2;
    u32 var4;
    u32 unused_1[1];
    u32 addr_copy;
    u8 *var5; // sp 52
    u32 unused_2[1];
    u32 unused_3[1];

    addr_copy = address & 0x7FFFE000;
    g_tlbmanageCurrentTlbEntries++;
    tlbmanageRemoveEntry(addr_copy);
    g_tlbmanageTlbSegmentNumber = tlbRandomGetNext() % TLB_RANDOM_MOD;
    var4 = g_tlbmanageTlbSegmentNumber;
    tlbmanageRemoveEntryByIndex(var4);
    
    // This is treated as a TLB mask a few lines later.
    // Some (some ...) documentation implies the mask should be 12 bits, but this is only 11 (losing highest bit).
    var1 = addr_copy & 0xFFE000;
    var5 = &(*g_tlbmanageTlbAllocatedBlock)[VAL_TO_TLB_MASK(var4)];

    romCopy(var5, (void*)(((u32)&_gameSegmentRomStart) + (u32)var1), TLB_ALLOCATION_BLOCK_SIZE);

    osInvalICache((void *)0x40000000, 0x40000000);
    osInvalICache((void *)0x80000000, 0x10000000);
    var2 = TLB_MASK_TO_VAL(var1);
    g_tlbmanageMangementTable[var2].pagenum = var4;

    // Gets physical address for "var5", then sets the lowest six bits to 0x1F
    g_tlbmanageMangementTable[var2].contextValue = ((osVirtualToPhysical(var5) >> 0xC) << 6) | 0x1F;
    g_tlbmanageMappingTable[var4].entry0 = 0;
    g_tlbmanageMappingTable[var4].entry1 = var2;
}

/**
 * 26F8    70001AF8
 * V0=p->TLB memory, or alternately end of free memory [8005E4A8]
 * Returns pointer to (an array of TLB blocksize).
 */
u8 (*tlbmanageGetTlbAllocatedBlock(void))[TLB_ALLOCATION_BLOCK_SIZE]
{
    return g_tlbmanageTlbAllocatedBlock;
}
