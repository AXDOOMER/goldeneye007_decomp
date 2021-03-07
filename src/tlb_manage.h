#ifndef _TLB_MANAGE_H_
#define _TLB_MANAGE_H_
#include "ultra64.h"

void tlbmanageEstablishManagementTable(void);
void tlbmanageResetCurrentEntriesCount(void);
void tlbmanageTranslateLoadRomFromTlbAddress(u32 address);
u8 * tlbmanageGetTlbAllocatedBlock(void);

#endif
