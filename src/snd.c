#include "ultra64.h"
#include "PR/libaudio.h"
#include "music.h"
#include "snd.h"


/**
 * @file snd.c
 * This file contains code to deal with snd.
 */


// TODO: move to snd.h, identify D_80063BA4 and D_80063BA8 then name this.
#define SFX_HEAP_B_SIZE   7

/**
 * Based on \n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndp.h
 * ALSndpEvent
 */
typedef union ALSndpEvent_u {

    // Added to match target, this might not be in the original ...
    // offset 0
    u16 unsignedType;

    // offset 0
    ALEvent             msg;

    struct {
        // offset 0
        s16             type;
        // offset 4
        ALSoundState    *state;
    } common;
    
    struct {
        s16             type;
        ALSoundState    *state;
        s32             vol;
    } vol;
    
    struct {
        s16             type;
        ALSoundState    *state;
        f32             pitch;
    } pitch;
    
    struct {
        s16             type;
        ALSoundState    *state;
        ALPan           pan;
    } pan;
    
    struct {
        s16             type;
        ALSoundState    *state;
        s32           pan32;
    } pan32;
    
    struct {
        s16             type;
        ALSoundState    *state;
        u8              mix;
    } fx;
    
    struct {
        s16             type;
        ALSoundState    *state;
        s32             mix32;
    } fx32;

    struct {
        u16 type;
        ALSoundState *state;
        s32 soundIndex;
        struct ALBankAlt_s *soundBank;
    } playSfx;

    struct {
        s32 unk0;
        s32 unk4;
        s16 unk8;
        s16 unkA;
        s32 unkC;
    } unk_u_1;

    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 *unkC;
    } unk_u_2;

    struct {
        s16 type;
        ALSoundState *state;
        s32 val;
    } unk_u_3;

    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
    } align_size;
    
} ALSndpEvent;

union ALSndpSmallEvent_u {
    struct {
        u16 unsignedType;
        ALSoundState *state;
    } msg;

    union {
        s32 unk0;
        s32 unk4;
    } align_size;
};

s32 sfx_unused = 0;

// 800243E4
struct D_800243E4_s {
    // address 800243E4 and 800243E8
    ALLink node;
    // address 800243EC
    struct ALSoundState_s *g_sndPlayerSoundStatePtr;
};

struct D_800243E4_s D_800243E4 = {{0,0},NULL};

ALSndPlayer *g_sndPlayerPtr = &g_sndPlayer;

/**
 * Current number of allocated voices, via alSynAllocVoice
 */
s16 D_800243F4 = 0;

s8 bootswitch_sound = 0;
f32 F32_800243FC = 1.0;

// forward declarations
ALMicroTime sndPlayerVoiceHandler(void *node);
void sfx_c_70008948(ALSoundState *state);
void sfx_c_700089C4(ALSoundState *state);
void sfx_c_70007E80(ALSndPlayer *sndp, ALSndpEvent *event);
void sfx_c_70008A30(ALEventQueue *evtq, ALSoundState *state, u16 eventType);

void sfx_c_70008D04(ALSoundState *state);

void sfx_c_70009284(u8 arg0, u16 arg1);
u16 sfx_c_70009264(u8 arg0);
s32 sfx_c_70008AF0(s16 *allocListCount, s16 *freeListCount);
ALSoundState *sfx_c_70008B70(struct ALBankAlt_s *arg0, ALSound* a1);

// end forward declarations

/**
 * 8720    70007B20
 * 
 * Mostly identical to n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndplayer.c
 * method alSndpNew.
 */
void sndNewPlayerInit(ALSeqpSfxConfig *sfxSeqpConfig)
{
    u8 *ptr;
    struct ALSoundState_s *sState;
    ALEvent evt;
    u32 i;

    /*
     * Init member variables
     */
    g_sndPlayerPtr->maxSounds = sfxSeqpConfig->maybeMaxSounds;
    g_sndPlayerPtr->target = 0;
    g_sndPlayerPtr->frameTime = AL_USEC_PER_FRAME_30FPS;
    sState = alHeapAlloc(sfxSeqpConfig->heap, 1, sfxSeqpConfig->maybeSndStateCount * sizeof(struct ALSoundState_s));
    g_sndPlayerPtr->sndState = sState;

    /*
     * init the event queue
     */
    ptr = alHeapAlloc(sfxSeqpConfig->heap, 1, sfxSeqpConfig->maxEvents * sizeof(ALEventListItem));
    alEvtqNew(&g_sndPlayerPtr->evtq, (ALEventListItem *)ptr, sfxSeqpConfig->maxEvents);

    D_800243E4.g_sndPlayerSoundStatePtr = g_sndPlayerPtr->sndState;

    for(i = 1; i < sfxSeqpConfig->maybeSndStateCount; i++)
    {
        // The compiler says this reassignment matters ...
        sState = (struct ALSoundState_s*)g_sndPlayerPtr->sndState;

        // this works because `ALLink node` is at offset zero.
        alLink((ALLink*)(&sState[i]), (ALLink*)(&sState[i]-1));
    }

    D_80063BA4 = alHeapAlloc(sfxSeqpConfig->heap, sizeof(s16), SFX_HEAP_B_SIZE);
    D_80063BA8 = alHeapAlloc(sfxSeqpConfig->heap, sizeof(s16), SFX_HEAP_B_SIZE);

    for(i = 0; i < SFX_HEAP_B_SIZE; i++)
    {
        D_80063BA8[i] = \
            D_80063BA4[i] = (s16)0x7FFF;
    }

    /*
     * add ourselves to the driver
     */
    g_sndPlayerPtr->drvr = &alGlobals->drvr;
    g_sndPlayerPtr->node.next = NULL;
    g_sndPlayerPtr->node.handler = &sndPlayerVoiceHandler;
    g_sndPlayerPtr->node.clientData = g_sndPlayerPtr;
    alSynAddPlayer(g_sndPlayerPtr->drvr, &g_sndPlayerPtr->node);

    /*
     * Start responding to API events
     */
    evt.type = AL_SNDP_API_EVT;
    alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, g_sndPlayerPtr->frameTime);
    g_sndPlayerPtr->nextDelta = alEvtqNextEvent(&g_sndPlayerPtr->evtq, &g_sndPlayerPtr->nextEvent);
}

/**
 * 89DC    70007DDC
 * 
 * Almost identical to \n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndplayer.c
 * method ALMicroTime _sndpVoiceHandler(void *node).
 */
ALMicroTime sndPlayerVoiceHandler(void *node)
{
    ALSndPlayer *sndp = (ALSndPlayer *) node;
    ALSndpEvent evt;

    do
    {
        switch (sndp->nextEvent.type)
        {
            case (AL_SNDP_API_EVT):
                // Had trouble matching against target until adding the "unsignedType"
                // field in the union.
                evt.unsignedType = (s16)AL_SNDP_API_EVT;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, sndp->frameTime);
                break;

            default:
                sfx_c_70007E80(sndp, (ALSndpEvent *)&sndp->nextEvent);
                break;
        }

        sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
        
    } while (sndp->nextDelta == 0);

    sndp->curTime += sndp->nextDelta;

    return sndp->nextDelta;
}






/**
 * 8A80    70007E80
 * 
 * Draws inspiration from n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndplayer.c
 * 
 * decomp notes:
 * - all floating point registers match
 * - there's a few places with temp variables and MIN,MAX macros, stuffing it all into one
 *   line generally causes increase of +2 lines to match, but the temp registers seem
 *   to get more shifted. I don't know if that's an improvement.
 */

void sfx_c_70007E80(ALSndPlayer *sndp, ALSndpEvent *event)
{
    // declarations

                                        //// 
                                        //// "..." means not explicitly referenced by stack offset
                                        ////
    ALVoiceConfig vc;                   // sp 0xc8; priority=200, fxBus=202, unityPitch=204
    ALSoundState *state;                // ...
    ALSoundState *tstate;               // ...
    s32 stack_size_3;                   // ...
    ALVoice *voicezzz;                     // ...
    s16 tmp;                            // ...
    s16 vol;                            // ...
    union ALSndpSmallEvent_u stopEvent; // sp 0xac = 172,176
    ALSndpEvent evt;                    // sp 0x9c; 156,160,164,168
    ALSound *snd;                       // ...
    ALKeyMap *keyMap;                   // ...
    s32 vtmp;                           // sp 0x90 = 144
    ALMicroTime delta;                  // ...
    s32 msgtype;                        // ...
    u8 aaa;
    ALPan pan;                          // ...
    s32 done_state;                     // sp 0x80 = 128
    s32 allocVoiceSuccess;              // sp 0x7c = 124
    ALSoundState *prevState;            // sp 0x78 = 120        
    ALSoundState *nextState;            // sp 0x74 = 116 ; could also be ALLink (with sp78)
    s16 sp72;                           // sp 0x72 = 114
    s16 sp70;                           // sp 0x70 = 112
    ALSoundState *loopCheckVar[1];      // sp 0x6c = 108
    s32 compare_result;                 // ...
    s32 stack_size_4;
    union ALSndpSmallEvent_u playAllocEvent;    // sp 0x5c = 92,96

    // done with declarations

    done_state = 1;
    allocVoiceSuccess = 0;
    nextState = NULL;
    // typo/mistake, prevState is unitialized.
    state = (void*)prevState;

    while (1)
    {
        if (nextState != NULL)
        {
            evt.common.state = state;
            evt.unsignedType = event->unsignedType;
            evt.unk_u_2.unk8 = event->unk_u_2.unk8;
            event = (ALSndpEvent *)&evt;
        }

        state = event->common.state;
        snd = state->sound;

        if (snd == NULL)
        {
            sfx_c_70008AF0(&sp72, &sp70);
            return;
        }

        keyMap = snd->keyMap;
        nextState = (ALSoundState *)state->link.next;

        switch (event->unsignedType)
        {
            case (AL_SNDP_PLAY_EVT):
            {
                if ((state->unk3f == AL_UNKOWN_5) || (state->unk3f == AL_UNKOWN_4))
                {
                    // comment copied from sndplayer: effect buss 0
                    vc.fxBus = 0;
                    vc.priority = state->priority;
                    vc.unityPitch = 0;
                    //voice = &state->voice;

                    compare_result = (D_800243F4 >= sndp->maxSounds);

                    if ((!compare_result) || (state->unk3e & 0x10))
                    {
                        allocVoiceSuccess = alSynAllocVoice(sndp->drvr, &state->voice, &vc);
                    }

                    if (!allocVoiceSuccess)
                    {
                        if ((state->unk3e & 0x12) || (state->unk38 > 0))
                        {
                            state->unk3f = AL_UNKOWN_4;
                            state->unk38--;
                            alEvtqPostEvent(&sndp->evtq, (ALEvent*)event, DELTA_33_MS);

                            return;
                        }
                        
                        if (compare_result)
                        {
                            tstate = (ALSoundState*)D_800243E4.node.prev;
                            do
                            {
                                if (
                                    ((tstate->unk3e & 0x12) == 0)
                                    && (tstate->unk3e & 4)
                                    && (tstate->unk3f != AL_UNKOWN_3))
                                {
                                    playAllocEvent.msg.unsignedType = AL_SNDP_END_EVT;
                                    playAllocEvent.msg.state = tstate;
                                    tstate->unk3f = AL_UNKOWN_3;
                                    compare_result = 0;
                                    loopCheckVar[0] = tstate;
                                    
                                    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&playAllocEvent, DELTA_1_MS);
                                    
                                    tstate = loopCheckVar[0];
                                    //voice = &tstate->voice;
                                    alSynSetVol(sndp->drvr, (ALVoice*)&tstate->voice, 0, DELTA_1_MS);

                                    tstate = loopCheckVar[0];
                                }

                                tstate = (ALSoundState *)tstate->link.prev;
                            }
                            while (compare_result != 0 && tstate != NULL);

                            if (compare_result == 0)
                            {
                                state->unk38 = 2;
                                alEvtqPostEvent(&sndp->evtq, (ALEvent*)event, DELTA_1_MS + 1);
                                return;
                            }

                            sfx_c_70008948(state);
                            return;
                        }
                        
                        sfx_c_70008948(state);
                        return;
                    }

                    state->unk3e |= 4;
                    alSynStartVoice(sndp->drvr, &state->voice, snd->wavetable);

                    state->unk3f = AL_PLAYING;
                    D_800243F4++;

                    delta = (ALMicroTime)((f32)snd->envelope->attackTime / state->pitch_2c / state->pitch_28);

                    tmp = D_80063BA4[keyMap->keyMin & 0x3f];
                    vol = state->vol;
                    vtmp = 
                        vol * (snd->envelope->attackVolume * snd->sampleVolume)
                        / (AL_VOL_FULL * AL_VOL_FULL)
                        * tmp
                        / 0x7fff;
                    vtmp = MAX(0, vtmp - 1);

                    // vtmp = MAX(0, (vol * (snd->envelope->attackVolume * snd->sampleVolume) 
                    //     / (AL_VOL_FULL * AL_VOL_FULL)
                    //     * tmp
                    //     / 0x7fff) - 1);
                    
                    alSynSetVol(sndp->drvr, &state->voice, 0, 0);
                    alSynSetVol(sndp->drvr, &state->voice, vtmp, delta);
                    
                    vtmp = state->pan - AL_PAN_CENTER + snd->samplePan;
                    pan = (ALPan) MIN(MAX(vtmp, AL_PAN_LEFT), AL_PAN_RIGHT);
                    //pan = (ALPan) MIN(MAX(state->pan - AL_PAN_CENTER + snd->samplePan, AL_PAN_LEFT), AL_PAN_RIGHT);

                    alSynSetPan(sndp->drvr, &state->voice, pan);
                    alSynSetPitch(sndp->drvr, &state->voice, state->pitch_2c * state->pitch_28);

                    vtmp = (state->fxMix + (keyMap->keyMax & 0xf)) * 8;
                    vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, vtmp));
                    //vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, (state->fxMix + (keyMap->keyMax & 0xf)) * 8));
                    alSynSetFXMix(sndp->drvr, &state->voice, vtmp);

                    stopEvent.msg.unsignedType = AL_SNDP_DECAY_EVT;
                    stopEvent.msg.state = state;
                    delta = (ALMicroTime)((f32)snd->envelope->attackTime / state->pitch_2c / state->pitch_28);
                    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&stopEvent, delta);
                }
                else
                {
                    return;
                }
            }
            break;
            
            case (AL_SNDP_UNKNOWN_10_EVT): // fallthrough
            case (AL_SNDP_UNKNOWN_12_EVT): // fallthrough
            case (AL_SNDP_STOP_EVT):
            {
                if (event->unsignedType != AL_SNDP_UNKNOWN_12_EVT
                    || (state->unk3e & 0x2)
                )
                {
                    switch (state->unk3f)
                    {
                        case (AL_PLAYING):
                        {
                            sfx_c_70008A30(&sndp->evtq, state, AL_SNDP_DECAY_EVT);

                            delta = (ALMicroTime)((f32)snd->envelope->releaseTime / state->pitch_28 / state->pitch_2c);
                            alSynSetVol(sndp->drvr, (ALVoice *)&state->voice, 0, delta);

                            if (delta)
                            {
                                stopEvent.msg.unsignedType = AL_SNDP_END_EVT;
                                stopEvent.msg.state = state;
                                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&stopEvent, delta);
                                state->unk3f = AL_STOPPING;
                            }
                            else
                            {
                                sfx_c_70008948(state);
                            }
                        }
                        break;

                        case (AL_UNKOWN_4): // fallthrough
                        case (AL_UNKOWN_5):
                        {
                            sfx_c_70008948(state);
                        }
                        break;

                        default:
                            // nothing to do
                        break;
                    }

                    if (event->unsignedType == AL_SNDP_STOP_EVT)
                    {
                        event->unsignedType = AL_SNDP_UNKNOWN_12_EVT;
                    }
                }
            }
            break;
            
            case (AL_SNDP_PAN_EVT):
            {
                state->pan = event->pan32.pan32;

                if (state->unk3f == AL_PLAYING)
                {
                    vtmp = state->pan - AL_PAN_CENTER + snd->samplePan;
                    pan = (ALPan) MIN(MAX(vtmp, AL_PAN_LEFT), AL_PAN_RIGHT);
                    //pan = (ALPan) MIN(MAX(state->pan - AL_PAN_CENTER + snd->samplePan, AL_PAN_LEFT), AL_PAN_RIGHT);

                    alSynSetPan(sndp->drvr, &state->voice, pan);
                }
            }
            break;
            
            case (AL_SNDP_PITCH_EVT):
            {
                state->pitch_2c = event->pitch.pitch;

                if (state->unk3f == AL_PLAYING)
                {
                    alSynSetPitch(sndp->drvr, &state->voice, state->pitch_2c * state->pitch_28);

                    if (state->unk3e & 0x20)
                    {
                        sfx_c_700089C4(state);
                    }
                }
            }
            break;
            
            case (AL_SNDP_FX_EVT):
            {
                state->fxMix = event->fx32.mix32;

                if (state->unk3f == AL_PLAYING)
                {
                    vtmp = (state->fxMix + (keyMap->keyMax & 0xf)) * 8;
                    vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, vtmp));
                    //vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, (state->fxMix + (keyMap->keyMax & 0xf)) * 8));

                    alSynSetFXMix(sndp->drvr, &state->voice, vtmp);
                }
            }
            break;
            
            case (AL_SNDP_VOL_EVT):
            {
                state->vol = event->vol.vol;
                if (state->unk3f == AL_PLAYING)
                {
                    tmp = D_80063BA4[keyMap->keyMin & 0x3f];
                    vol = state->vol;
                    vtmp = 
                        vol * (snd->envelope->decayVolume * snd->sampleVolume) 
                        / (AL_VOL_FULL * AL_VOL_FULL)
                        * tmp
                        / 0x7fff;
                    vtmp = MAX(0, vtmp - 1);
                    
                    // vtmp = MAX(0, (vol * (snd->envelope->decayVolume * snd->sampleVolume) 
                    //     / (AL_VOL_FULL * AL_VOL_FULL)
                    //     * tmp
                    //     / 0x7fff) - 1);

                    alSynSetVol(sndp->drvr, (ALVoice *)&state->voice, vtmp, DELTA_1_MS);
                }
            }
            break;

            // case 0x20 (AL_SNDP_API_EVT)
            // handled in sndPlayerVoiceHandler
            
            case (AL_SNDP_RELEASE_EVT):
            {
                if (state->unk3f == AL_PLAYING)
                {
                    delta = ((f32)snd->envelope->releaseTime / state->pitch_28 / state->pitch_2c);

                    tmp = D_80063BA4[keyMap->keyMin & 0x3f];
                    vol = state->vol;
                    vtmp = 
                        vol * (snd->envelope->decayVolume * snd->sampleVolume) 
                        / (AL_VOL_FULL * AL_VOL_FULL)
                        * tmp
                        / 0x7fff;
                    vtmp = MAX(0, vtmp - 1);
                    
                    // vtmp = MAX(0, (vol * (snd->envelope->decayVolume * snd->sampleVolume) 
                    //     / (AL_VOL_FULL * AL_VOL_FULL)
                    //     * tmp
                    //     / 0x7fff) - 1);

                    alSynSetVol(sndp->drvr, &state->voice, vtmp, delta);
                }
            }
            break;
            
            case (AL_SNDP_DECAY_EVT):
            {
                if ((state->unk3e & 2) == 0)
                {
                    tmp = D_80063BA4[keyMap->keyMin & 0x3f];
                    vol = state->vol;
                    vtmp = 
                        (vol * (snd->envelope->decayVolume * snd->sampleVolume) 
                        / (AL_VOL_FULL * AL_VOL_FULL))
                        * tmp
                        / 0x7fff;
                    
                    vtmp = MAX(0, vtmp - 1);

                    // can't seem to combine this volume computation into one line with the macro.

                    delta = (ALMicroTime)((f32)snd->envelope->decayTime / state->pitch_28 / state->pitch_2c);
                    alSynSetVol(sndp->drvr, &state->voice, vtmp, delta);

                    stopEvent.msg.unsignedType = AL_SNDP_STOP_EVT;
                    stopEvent.msg.state = state;
                    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&stopEvent, delta);

                    if ((state->unk3e & 0x20) != 0)
                    {
                        sfx_c_700089C4(state);
                    }
                }
            }
            break;
            
            case (AL_SNDP_END_EVT):
            {
                sfx_c_70008948(state);
            }
            break;
            
            case (AL_SNDP_PLAY_SFX_EVT):
            {
                if ((state->unk3e & 0x10) != 0)
                {
                    play_sfx_a1((struct ALBankAlt_s *)event->playSfx.soundBank, event->playSfx.soundIndex, state->state);
                }
            }
            break;
            
            default:
                // not supported
            break;
        }

        msgtype = event->unsignedType & 0x2d1;
        state = nextState;

        if (state == NULL || msgtype != 0)
        {
            // do nothing
        }
        else
        {
            done_state = 
                // best guess at cast to get offset 0x3e ...
                ((ALSoundState*)event)->unk3e & 0x1;
        }
            
        if (done_state || state == NULL)
        {
            break;
        }
        else if (msgtype == 0)
        {
            continue;
        }
        else
        {
            prevState = state;
            break;
        }
    }

    if (prevState)
    {
        // removed
    }
}

 

/**
 * 9548    70008948
 */
void sfx_c_70008948(ALSoundState *state)
{
    if (state->unk3e & 4)
    {
        alSynStopVoice(g_sndPlayerPtr->drvr, &state->voice);
        alSynFreeVoice(g_sndPlayerPtr->drvr, &state->voice);
    }

    sfx_c_70008D04(state);
    sfx_c_70008A30(&g_sndPlayerPtr->evtq, state, 0xffff);
}

/**
 * 95C4    700089C4
 */
void sfx_c_700089C4(ALSoundState *state)
{
    ALSndpEvent evt;
    f32 pitch;

    pitch = (f32) (alCents2Ratio(state->sound->keyMap->detune) * (f32)state->pitch_2c);
    evt.common.state = state;
    evt.msg.type = AL_SNDP_PITCH_EVT;
    evt.unk_u_3.val = *(s32*)&pitch;

    alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, DELTA_33_MS);
}

/**
 * 9630     70008A30
 * Based on (almost identical) the method
 * static void _removeEvents(ALEventQueue *evtq, ALSoundState *state)
 * from n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\sndplayer.c
 */
void sfx_c_70008A30(ALEventQueue *evtq, ALSoundState *state, u16 eventType)
{
    ALLink              *thisNode;
    ALLink              *nextNode;
    ALEventListItem     *thisItem;
    ALEventListItem     *nextItem;
    ALSndpEvent         *thisEvent;
    OSIntMask           mask;

    mask = osSetIntMask(OS_IM_NONE);

    thisNode = evtq->allocList.next;

    while(thisNode != NULL)
    {
	    nextNode = thisNode->next;
        thisItem = (ALEventListItem *)thisNode;
        nextItem = (ALEventListItem *)nextNode;
        thisEvent = (ALSndpEvent *)&thisItem->evt;

        if (thisEvent->common.state == state && (((u16)thisItem->evt.type & (u16)eventType) != 0))
        {
            if (nextItem != NULL)
            {
                nextItem->delta += thisItem->delta;
            }

            alUnlink(thisNode);
            alLink(thisNode, &evtq->freeList);
        }

	    thisNode = nextNode;
    }
    
    osSetIntMask(mask);
}

/**
 * 96F0     70008AF0
 * Has similarities to
 * void alEvtqPrintEvtQueue(ALEventQueue *evtq)
 * from n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\event.c
 * 
 * @param allocListCount Out param. Will contain the number of (next) nodes in the D_800243E4 allocList.
 * @param freeListCount Out param. Will contain the number of (next) nodes in the D_800243E4 freeList.
 * @return Number of (prev) nodes in the D_800243E4 freeList.
 */
s32 sfx_c_70008AF0(s16 *allocListCount, s16 *freeListCount)
{
    u16 counter1;
    u16 counter2;
    u16 returnCounter;

    ALEventQueue *evtq = (ALEventQueue *)&D_800243E4;

    ALLink *freeListNodeForward = evtq->freeList.next;
    ALLink *allocListNodeForward = evtq->allocList.next;
    ALLink *freeListNodeBackward = evtq->freeList.prev;

    for (counter1 = 0; freeListNodeForward != NULL; freeListNodeForward = freeListNodeForward->next)
    {
         counter1++;
    }

    for (counter2 = 0; allocListNodeForward != NULL; allocListNodeForward = allocListNodeForward->next)
    {
         counter2++;
    }

    for (returnCounter = 0; freeListNodeBackward != NULL; freeListNodeBackward = freeListNodeBackward->prev)
    {
         returnCounter++;
    }

    *allocListCount = (s16) counter2;
    *freeListCount = (s16) counter1;

    return returnCounter;
}

/**
 * 9770    70008B70
 * initializes soundstate to sound.
 *     accepts: A0=sound data offset?, A1=sample address?
 * 
 * @param soundBank unused.
 * @param sound sound to use.
 */
ALSoundState *sfx_c_70008B70(struct ALBankAlt_s *soundBank, ALSound* sound)
{
    s32 decayTimeFlag;
    ALKeyMap *keymap = sound->keyMap;
    ALSoundState *state = (ALSoundState *)D_800243E4.g_sndPlayerSoundStatePtr;
    OSIntMask mask;

    if (state != NULL)
    {
        mask = osSetIntMask(OS_IM_NONE);

        D_800243E4.g_sndPlayerSoundStatePtr = (void *)state->link.next;
        alUnlink(&state->link);

        if (D_800243E4.node.next != NULL)
        {
            state->link.next = (void *)D_800243E4.node.next;
            state->link.prev = NULL;
            D_800243E4.node.next->prev = (void *)state; // what?
            D_800243E4.node.next = (void *)state;
        }
        else
        {
            state->link.prev = NULL;
            state->link.next = NULL;
            D_800243E4.node.next = (void *)state;
            D_800243E4.node.prev = (void *)state;
        }

        osSetIntMask(mask);

        decayTimeFlag = (sound->envelope->decayTime == -1);
        state->priority = decayTimeFlag + 0x40;

        state->unk3f = AL_UNKOWN_5;
        state->unk38 = 2;
        state->sound = sound;
        state->pitch_2c = 1.0f;
        state->unk3e = (keymap->keyMax & (u8)0xf0);
        state->state = NULL;
        
        if ((state->unk3e & 0x20) != 0)
        {
            state->pitch_28 = alCents2Ratio(((keymap->keyBase * 100) + -0x1770));
        }
        else
        {
            state->pitch_28 = alCents2Ratio((((keymap->keyBase * 100) + keymap->detune) + -0x1770));
        }

        if (decayTimeFlag)
        {
            state->unk3e |= 2;
        }

        state->fxMix = (u8)AL_DEFAULT_FXMIX;
        state->pan = (u8)AL_PAN_CENTER;
        state->vol = (u16)0x7fff;
    }

    return state;
}


/**
 * 9904    70008D04
 * some kind of dispose/deallocate method.
 */
void sfx_c_70008D04(ALSoundState *state)
{
    if (state == (ALSoundState *)D_800243E4.node.next)
    {
        D_800243E4.node.next = state->link.next;
    }

    if (state == (ALSoundState *)D_800243E4.node.prev)
    {
        D_800243E4.node.prev = state->link.prev;
    }

    alUnlink(&state->link);

    if (D_800243E4.g_sndPlayerSoundStatePtr != NULL)
    {
        state->link.next = (void *)D_800243E4.g_sndPlayerSoundStatePtr;
        state->link.prev = NULL;
        D_800243E4.g_sndPlayerSoundStatePtr->link.prev = (void *)state;
        D_800243E4.g_sndPlayerSoundStatePtr = state;
    }
    else
    {
        state->link.prev = NULL;
        state->link.next = NULL;
        D_800243E4.g_sndPlayerSoundStatePtr = state;
    }

    if ((state->unk3e & 4) != 0)
    {
        D_800243F4--;
    }

    state->unk3f = AL_STOPPED;

    if (state->state != NULL)
    {
        if (state == (ALSoundState *)state->state->link.next)
        {
            state->state->link.next = NULL;
        }

        state->state = NULL;
    }
}

/**
 * 99D8    70008DD8
 *     A1->A0+0x36.  value is set in sound effect buffer?
 *     accepts: A0=p->SE buffer?, A1=value truncated to byte
 */
void sfx_c_70008DD8(ALSoundState *state, u8 arg1)
{
    if (state != NULL)
    {
        state->priority = arg1;
    }
}

/**
 * 99F0    70008DF0
 *     V0= TRUE if SE playing flag set [A0+0x3F]
 *     value is set only when sound defaults have been set
 *     accepts: A0=p->SE buffer
 */
u8 sfxGetArg0Unk3F(ALSoundState *state)
{
    if (state != NULL)
    {
        return state->unk3f;
    }

    return 0;
}

/**
 * 9A08    70008E08
 *     sets sound effect; used by sound effect routines
 * 
 * Old comments:
 * 
 *     accepts: A0=p->SE buffer, A1=SE #, A2=p->data
 *          data:    0x0    4    p->SE entry
 *              0x4    4    target volume
 *              0x8    4    audible range (timer)
 *              0xC    4    initial volume
 *              0x10    4    p->preset emitting sound
 *              0x14    4    p->object emitting sound
 * 
 * // end old comments.
 * 
 * @param soundBank sound bank
 * @param soundIndex index into sound bank: soundBank->instArray[0]->soundArray[soundIndex]
 * @param pendingState Optional pointer. If provided, its link.next pointer will be
 * to the newly created soundState.
 */
ALSoundState *play_sfx_a1(struct ALBankAlt_s *soundBank, s16 soundIndex, ALSoundState *pendingState)
{
    // declarations
    
    // declaration order doesn't seem to matter for these.

    ALMicroTime deltaTotal;
    ALSound *sound;
    ALSoundState *newState;
    ALSoundState *nextState;

    // declaration order matters:

    s16 eventSoundIndex;       // 110(sp)
    s16 unused_sp6c;           // 108(sp)
    ALMicroTime playSfxDelta;  // 104(sp)
    ALMicroTime deltaLoop; // 100(sp)
    
    // end declarations

    nextState = NULL;
    eventSoundIndex = 0;
    deltaTotal = 0;

    if(0); // debug?

    if (bootswitch_sound)
    {
        return NULL;
    }

    if (soundIndex == 0)
    {
        return NULL;
    }

    do
    {
        ALKeyMap *keyMap;

        sound = (soundBank->instArray[0]->soundArray[soundIndex]);

        newState = sfx_c_70008B70(soundBank, sound);

        if (newState != NULL)
        {
            ALSndpEvent playEvent;

            g_sndPlayerPtr->target = (s32)newState;
            playEvent.common.type = AL_SNDP_PLAY_EVT;
            playEvent.common.state = newState;
            deltaLoop = sound->keyMap->velocityMax * DELTA_33_MS;

            if (newState->unk3e & 0x10)
            {
                newState->unk3e &= (~(s16)(0x10));
                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&playEvent, deltaTotal + 1);
                playSfxDelta = deltaLoop + 1;
                eventSoundIndex = soundIndex;
            }
            else
            {
                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&playEvent, deltaLoop + 1);
            }

            nextState = newState;
        }

        deltaTotal += deltaLoop;

        keyMap = sound->keyMap;
        soundIndex = (s16)((s32)keyMap->velocityMin + ((s32)(keyMap->keyMin & 0xC0) * 4));
    } while (soundIndex != 0 && newState != NULL);

    if(!soundIndex)
    {
        // removed
    }

    if(!sound)
    {
        // removed
    }

    if (nextState != NULL)
    {
        nextState->unk3e |= 0x1;
        nextState->state = pendingState;

        if (eventSoundIndex != 0)
        {
            ALSndpEvent playSfxEvent;
    
            nextState->unk3e |= 0x10;

            playSfxEvent.playSfx.type = AL_SNDP_PLAY_SFX_EVT;
            playSfxEvent.playSfx.state = nextState;
            playSfxEvent.playSfx.soundIndex = eventSoundIndex; // types dont match
            playSfxEvent.playSfx.soundBank = soundBank;

            alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&playSfxEvent, playSfxDelta);
        }
    }

    if (pendingState != NULL)
    {
        pendingState->link.next = (void*)nextState;
    }

    return nextState;
}

/**
 * 9C20    70009020
 *     decativates sound effect
 *     accepts: A0=p->SE buffer
 */
void sfxDeactivate(ALSoundState *state)
{
    ALSndpEvent evt;

    evt.common.type = AL_SNDP_UNKNOWN_10_EVT;
    evt.common.state = state;

    if (state != NULL)
    {
        state->unk3e = (s8) (state->unk3e & (~(s16)(0x10)));

        alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
    }
}

/**
 * 9C6C    7000906C
 */
void sfx_c_7000906C(u8 arg0)
{
    OSIntMask mask;
    ALSndpEvent evt;
    ALSoundState *item;

    mask = osSetIntMask(OS_IM_NONE);

    item = (ALSoundState *)D_800243E4.node.next;
    while (item != NULL)
    {
        evt.common.type = AL_SNDP_UNKNOWN_10_EVT;
        evt.common.state = item;

        if ((item->unk3e & arg0) == arg0)
        {
            item->unk3e = (s8) (item->unk3e & (~(s16)(0x10)));
            alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
        }

        item = (ALSoundState *)item->link.next;
    }
    
    osSetIntMask(mask);
}

/**
 * 9D24    70009124
 *     redirect to 7000906C: A0=1
 */
void sfx_c_70009124(void)
{
    sfx_c_7000906C(1);
}

/**
 * 9D44    70009144
 *     redirect to 7000906C: A0=11
 */
void sfx_c_70009144(void)
{
    sfx_c_7000906C(0x11);
}

/**
 * 9D64    70009164
 *     redirect to 7000906C: A0=3
 */
void sfx_c_70009164(void)
{
    sfx_c_7000906C(3);
}

/**
 * 9D84    70009184
 */
void sfx_c_70009184(ALSoundState *state, s16 eventType, s32 arg2)
{
    ALSndpEvent evt;
    
    evt.common.type = eventType;
    evt.common.state = state;
    evt.unk_u_2.unk8 = arg2;

    if (state != NULL)
    {
        alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
    }
}

/**
 * 9DC8    700091C8
 *     redirect to 70009264: A0=0
 */
u16 sfx_c_700091C8(void)
{
    return sfx_c_70009264(0);
}

/**
 * 9DE8    700091E8
 */
void sfx_c_700091E8(u16 arg0)
{
    u8 i;

    for (i = 0; i < SFX_HEAP_B_SIZE; i++)
    {
        sfx_c_70009284(i, arg0);
    }
}

/**
 * 9E38    70009238
 */

void sfx_c_70009238(f32 arg0)
{
    F32_800243FC = arg0;
    sfx_c_700091E8(sfx_c_700091C8());
}

/**
 * 9E64    70009264
 *     V0= halfword A0 in table at [80063BA8]; fries T6,T7,T8,T9
 */
u16 sfx_c_70009264(u8 arg0)
{
    return D_80063BA8[arg0];
}

/**
 * 9E84    70009284
 */
void sfx_c_70009284(u8 arg0, u16 arg1)
{
    // Not sure if these are debug leftovers, or is the type `ALSndpEvent` wrong?
    u32 unused[2];

    ALSndpEvent evt;
    ALSoundState *item;

    item = (ALSoundState *)D_800243E4.node.next;
    
    D_80063BA8[arg0] = arg1;
    D_80063BA4[arg0] = (s16) ((f32) arg1 * F32_800243FC);

    while (item != NULL)
    {
        if (item->sound != NULL)
        {
            if ((item->sound->keyMap->keyMin & 0x3f) == arg0)
            {
                evt.common.type = AL_SNDP_RELEASE_EVT;
                evt.common.state = item;

                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
            }
        }

        item = (ALSoundState *)item->link.next;
    }
}
