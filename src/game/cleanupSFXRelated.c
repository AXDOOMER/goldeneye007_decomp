#include "ultra64.h"
#include "game/bondview.h"
#include "include/PR/libaudio.h"

void cleanupSFXRelated(void) {
    if (SFX_80036458 != 0)
    {
        if (sndGetPlayingState(SFX_80036458) != AL_STOPPED)
        {
            sndDeactivate(SFX_80036458);
        }
    }

    if (SFX_8003645C != 0)
    {
        if (sndGetPlayingState(SFX_8003645C) != AL_STOPPED)
        {
            sndDeactivate(SFX_8003645C);
        }
    }

}