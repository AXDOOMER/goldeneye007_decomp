#include "ultra64.h"
#include "game/unk_093880.h"
#include "game/bondinv.h"

void sub_GAME_7F0061F0(void) {
    s32 i;
  
    pPlayer->equipallguns = 0;
    
    for (i = 0; i != 10; i++) {
        pPlayer->gunheldarr[i].totaltime = -1;
    }
}

void alloc_additional_item_slots(s32 additionalentries) {
  pPlayer->equipmaxitems = additionalentries + 0x1e;
  pPlayer->p_itemcur = mempAllocBytesInBank((pPlayer->equipmaxitems * 0x14 + 0xfU | 0xf) ^ 0xf,'\x04');
  reinit_inventory();
}
