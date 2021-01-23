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
typedef s32     ALMicroTime;

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
 * Synthesis driver stuff
 ***********************************************************************/
typedef ALMicroTime (*ALVoiceHandler)(void *);

typedef struct ALPlayer_s {
    struct ALPlayer_s   *next;
    void                *clientData;    /* storage for client callback  */
    ALVoiceHandler      handler;        /* voice handler for player     */
    ALMicroTime         callTime;       /* usec requested callback      */
    s32                 samplesLeft;    /* usec remaining to callback   */
} ALPlayer;

typedef struct {
    ALPlayer    *head;          /* client list head                     */
    ALLink      pFreeList;      /* list of free physical voices         */
    ALLink      pAllocList;     /* list of allocated physical voices    */
    ALLink      pLameList;      /* list of voices ready to be freed     */
    s32         paramSamples;
    s32         curSamples;     /* samples from start of game           */
    ALDMANew    dma;
    ALHeap      *heap;
    
    struct ALParam_s    *paramList;
    
    struct ALMainBus_s  *mainBus;
    struct ALAuxBus_s   *auxBus;        /* ptr to array of aux bus structs */
    struct ALFilter_s   *outputFilter;  /* last filter in the filter chain */

    s32                 numPVoices;
    s32                 maxAuxBusses;
    s32                 outputRate;     /* output sample rate */
    s32                 maxOutSamples;  /* Maximum samples rsp can generate
                                           at one time at output rate */
} ALSynth;

/***********************************************************************
 * Audio Library (AL) stuff
 ***********************************************************************/
typedef struct {
    ALSynth     drvr;
} ALGlobals;

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
