#include "ultra64.h"
#include "memp.h"
#include "game/unk_093880.h"
#include "game/bondinv.h"

void reinit_gunheld_totaltime(void) {
    s32 i;
  
    currentplayer->equipallguns = FALSE;
    
    for (i = 0; i != 10; i++) {
        currentplayer->gunheldarr[i].totaltime = -1;
    }
}

void alloc_additional_item_slots(s32 additionalentries) {
  currentplayer->equipmaxitems = additionalentries + 0x1e;
  currentplayer->p_itemcur = mempAllocBytesInBank((currentplayer->equipmaxitems * 0x14 + 0xfU | 0xf) ^ 0xf,'\x04');
  reinit_inventory();
}
