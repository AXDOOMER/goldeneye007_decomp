#include "ultra64.h"
#include "game/bond.h"

void cleanupSFXRelated(void) {
    // Node 0
    if (SFX_80036458 != 0)
    {
        // Node 1
        if (sfxGetArg0Unk3F(SFX_80036458) != 0)
        {
            // Node 2
            sfxSetArg0Unk3EPostEvent(SFX_80036458);
        }
    }
    // Node 3
    if (SFX_8003645C != 0)
    {
        // Node 4
        if (sfxGetArg0Unk3F(SFX_8003645C) != 0)
        {
            // Node 5
            sfxSetArg0Unk3EPostEvent(SFX_8003645C);
        }
    }
    // Node 6
    return;
}