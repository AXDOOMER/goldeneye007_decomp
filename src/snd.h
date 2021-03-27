#ifndef _SND_H_
#define _SND_H_
#include "ultra64.h"
#include "PR/libaudio.h"

/**
 * This is a guess struct, used by music setup function call into snd.
 * The method call makes it seem like this should be ALSndpConfig,
 * but there's an extra field here.
 */
typedef struct ALSeqpSfxConfig_s {

    /**
     * (actual field is unknown)
     * Used to calculate size in call to alHeapAlloc for sndState,
     * this is the number of ALSndPlayer.sndState entries.
     * Offset 0.
     */
    s32 maybeSndStateCount;

    /**
     * max internal events to support
     * Offset 4.
     */
    s32 maxEvents;

    /**
     * (actual field is unknown)
     * ALSndPlayer.maxSounds will be assigned this value
     * Offset 8.
     */
    u32 maybeMaxSounds;

    /**
     * ptr to initialized heap
     * Offset 0xc.
     */
    ALHeap *heap;
} ALSeqpSfxConfig;

void play_sfx_a1 (void * buffer, short entry, void * data);
void sndNewPlayerInit(ALSeqpSfxConfig *arg0);

extern s8 bootswitch_sound;


#endif
