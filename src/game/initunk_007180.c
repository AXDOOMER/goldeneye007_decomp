#include <ultra64.h>
#include <bondconstants.h>
#include <memp.h>
#include "initunk_007180.h"
#include "unk_0A1DA0.h"



void sub_GAME_7F007180(void)
{
    s32 i;
    s32 level = lvlGetCurrentStageToLoad();
    
    bufferentrycount_8007A160 = (0xC8 / getPlayerCount());
    if ((level == LEVELID_STREETS) || (level == LEVELID_DEPOT))
    {
        bufferentrycount_8007A160 = (bufferentrycount_8007A160 >> 1);
    }
    dword_CODE_bss_8007A164 = mempAllocBytesInBank(((bufferentrycount_8007A160 * 0x68) + 0xF) & ~0xF, 4U);
    for(i=0; i<bufferentrycount_8007A160; i++)
    {
        dword_CODE_bss_8007A164[i].field_0x0 = 0;
    }
    
    D_80040940 = 0;
}

