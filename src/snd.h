#ifndef _SND_H_
#define _SND_H_

#include "ultra64.h"
#include "PR/libaudio.h"

// based on n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndp.h
struct ALSoundState_s;
typedef struct ALSoundState_s {
    
    // Unmatched properties:
    /*
        //
        s16         priority;
    */

    // offset 0
    ALLink link;

    // offset 8
    ALSound *sound;

    // offset 0xc
    ALVoice voice;

    // current playback pitch ... ?
    // offset 0x28
    f32 pitch_28;

    // bendRatio?
    // offset 0x2c
    f32 pitch_2c;

    // play state for this sound
    // offset 0x30
    struct ALSoundState_s *state;

    // offset 0x34
    s16 vol;

    // priority?
    // // vc.priority   = state->unk36;
    u8 unk36;

    s8 unk37;
    s32 unk38;

    // offset 0x3c = 60
    // pan - 0 = left, 127 = right
    ALPan pan;

    // offset 0x3d = 61
    // wet/dry mix - 0 = dry, 127 = wet
    u8 fxMix;

    u8 unk3e; // state / flags?
    u8 unk3f; // state / flags?

} ALSoundState;

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

// begin Alternate defintion for ALInstrument

struct ALInstrumentAlt_s
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    ALSound *soundArray[1];
};

struct ALBankAlt_s
{
    s16 instCount; /* number of programs in this bank */
    u8 flags;
    u8 pad;
    s32 sampleRate;             /* e.g. 44100, 22050, etc...       */
    ALInstrument *percussion;   /* default percussion for GM       */
    struct ALInstrumentAlt_s *instArray[1]; /* ARRAY of instruments            */
};

// end Alternate defintion for ALInstrument

ALSoundState *play_sfx_a1(struct ALBankAlt_s *arg0, s16 arg1, ALSoundState *arg2);
void sndNewPlayerInit(ALSeqpSfxConfig *arg0);

extern s8 bootswitch_sound;


#endif
