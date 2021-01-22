#ifndef _ULTRA64_LIBAUDIO_H_
#define _ULTRA64_LIBAUDIO_H_

#include "abi.h"

/***********************************************************************
 * Audio Library global routines
 ***********************************************************************/
typedef struct ALLink_s {
    struct ALLink_s      *next;
    struct ALLink_s      *prev;
} ALLink;

typedef s32 (*ALDMAproc)(s32 addr, s32 len, void *state);
typedef ALDMAproc (*ALDMANew)(void *state);

#define AL_FX_NONE      0
#define AL_FX_SMALLROOM 1
#define AL_FX_BIGROOM   2
#define AL_FX_CHORUS    3
#define AL_FX_FLANGE    4
#define AL_FX_ECHO      5
#define AL_FX_CUSTOM    6

typedef u8 ALFxId;

typedef struct {
    u8 *base;
    u8 *current;
    s32 len;
    s32 count;
} ALHeap;

typedef struct {
    s32 maxVVoices; /* obsolete */
    s32 maxPVoices;
    s32 maxUpdates;
    s32 maxFXbusses;
    void *dmaproc;
    ALHeap *heap;
    s32 outputRate;
    ALFxId fxType;
    s32 *params;
} ALSynConfig;

/***********************************************************************
 * Sequence Files
 ***********************************************************************/

typedef struct
{
    u8 *offset;
    s32 len;
#ifdef VERSION_SH
    s8 magic[2]; // tbl: 0x0204, otherwise: 0x0203

    // for ctl (else zeros):
    union {
        // unused, just for clarification (big endian)
        struct {
            u8 bank;
            u8 ff;
            u8 numInstruments;
            u8 numDrums;
        } as_u8;

        // used
        struct {
            s16 bankAndFf;
            s16 numInstrumentsAndDrums;
        } as_s16;
    } ctl;
#endif
} ALSeqData;

typedef struct
{
#ifndef VERSION_SH
    s16 revision;
#endif
    s16 seqCount;
#ifdef VERSION_SH
    s16 unk2;
    u8 *data;
    s32 pad[2];
#endif
    ALSeqData seqArray[1];
} ALSeqFile;

void alSeqFileNew(ALSeqFile *f, u8 *base);

#endif
