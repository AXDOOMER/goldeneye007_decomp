#ifndef _MEMP_H_
#define _MEMP_H_

#include "ultra64.h"

typedef struct s_mempBANK {
    s32 bankstart;
    s32 nextentry;
    s32 bankend;
    s32 data2;
} s_mempBANK;

typedef struct s_mempMVALS {
    u32 var1;
    u32 var2;
    u32 var3;
    u32 var4;
    u32 var5;
    u32 var6;
    u32 var7;
    u32 var8;
} s_mempMVALS;

typedef struct s_mempMEMSTARTS {
    s32 bank1start;
    s32 bank2start;
    s32 bank3start;
    s32 bank4start;
    s32 bank5start;
    s32 bank6start;
    s32 bank7start;
} s_mempMEMSTARTS;

void mempInitDebugNoticeList(void);
void mempCheckMemflagTokens(int bstart,int bsize);
void mempSetBankStarts(s_mempMVALS *banks);
u32 mempAllocBytesInBank(u32 bytes,u8 bank);
u32 mempAddEntryOfSizeToBank(u8* ptrdata,u32 size,u8 bank);
void nulled_mempLoopAllMemBanks(void);
s32 mempGetBankSizeLeft(u8 bank);
u32 mempAllocPackedBytesInBank(u32 param_1);
void mempResetBank(u8 bank);
void mempNullNextEntryInBank(u8 bank);

#endif
