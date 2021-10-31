#ifndef _FILE2_H_
#define _FILE2_H_
#include "ultra64.h"

#define RAMROM_FOLDERNUM 0x64

u8 fileGetBondForFolder(u32 folder);
void fileValidateSaves();

#endif
