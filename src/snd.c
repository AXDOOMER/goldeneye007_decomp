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

#define MIN_RATIO	0.0001

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
        s16             vol;
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
        u8              mix;
    } fx;

    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s16 unkA;
        s16 unkC;
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
s16 D_800243F4 = 0;
s8 bootswitch_sound = 0;
f32 F32_800243FC = 1.0;

// forward declarations
ALMicroTime sndPlayerVoiceHandler(void *node);
void sfx_c_70008948(ALSoundState *state);
void sfx_c_700089C4(ALSoundState *state);
void sfx_c_70007E80(ALSndPlayer *sndp, ALEvent *event);
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
                sfx_c_70007E80(sndp, (ALEvent *)&sndp->nextEvent);
                break;
        }

        sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
        
    } while (sndp->nextDelta == 0);

    sndp->curTime += sndp->nextDelta;

    return sndp->nextDelta;
}






/**
 * 8A80    70007E80
 *     ???
 *     accepts: A0=???, A1=???
 *     uses TLB pointer table at 80029160
 *     70007FBC    entry 0
 *     70008388    entry 1
 *     7000847C    entry 3
 *     700084F0    entry F
 *     700085C8    entry 7
 *     700088D4    default: entries 2,4,5,6,8,9,A,B,C,D,E
 */

void sfx_c_70007E80(ALSndPlayer *sndp, ALEvent *event)
{
    ALVoiceConfig vc; // sp 0xc8 = 200

    u32 stack_bump_4; // maybe 196
    ALKeyMap    *keyMap; // maybe 192
    ALSndpEvent *event_ptr; // maybe 188

    ALVoice             *voice = NULL; // maybe 184
    ALSound             *snd = NULL; // maybe 180
    ALPan               pan; // maybe 176
    //f32                 pitch; // maybe 172
    ALSndpEvent         evt; // maybe 156
    ALMicroTime         delta = 0; // maybe 152

    s16                 vol = 0; // maybe 148
    
    s32                 tmp = 0; // maybe 140


    ALSoundState        *state = NULL; // maybe 136
    s32                 vtmp = 0; // sp 0x90 = 144;

    //u8 temp_u8 = 0; // maybe 132
    ALSoundState        *tstate = 0; // maybe 128
    
    s32 allocVoiceSuccess = 0; // sp 0x7C = 124;

    u16 msgtype;
    s32 unk;
    s32 done = 0;

    s32 allocVoiceOk_rename_me = 0;
    ALSoundState *loopCheckVar = NULL;

    ALSndpEvent playVoiceAllocEvent; // sp 0x5c = 92


    event_ptr = (ALSndpEvent *)event;
    msgtype = event_ptr->unsignedType;
    evt.unsignedType = event_ptr->unsignedType;

    unk = event_ptr->align_size.unk8;
    evt.common.state = event_ptr->common.state;

    evt.unk_u_2.unk8 = event_ptr->unk_u_2.unk8;

    snd = evt.common.state->sound;

    if (snd == NULL)
    {
        return;
    }

    while (!done)
    {
        state = event_ptr->common.state;
        snd   = state->sound;
        keyMap = snd->keyMap;

        if (!snd)
        {
            s16 sp72;
            s16 sp70;

            sfx_c_70008AF0(&sp72, &sp70);
            return;
        }

        switch (msgtype)
        {
            // case 0 (or 1?)
            case (AL_SNDP_PLAY_EVT):
            {
                if ((state->stateFlags.bbbb.unk3f == AL_UNKOWN_5) || (state->stateFlags.bbbb.unk3f == AL_UNKOWN_4))
                {
                    vc.fxBus      = 0;            /* effect buss 0 */
                    vc.priority   = state->unk36;
                    vc.unityPitch = 0;
                    voice = &state->voice;

                    allocVoiceOk_rename_me = ((s32) D_800243F4 >= sndp->maxSounds);

                    if ((allocVoiceOk_rename_me == 0) || ((state->stateFlags.bbbb.unk3e & 0x10) != 0))
                    {
                        allocVoiceSuccess = alSynAllocVoice(sndp->drvr, voice, &vc);
                    }

                    if(voice)
                    {
#ifdef DEBUG
#endif
                    }

                    if (allocVoiceSuccess == 0)
                    {
                        if (((state->stateFlags.bbbb.unk3e & 0x12) != 0) || (state->unk38 > 0))
                        {
                            state->stateFlags.bbbb.unk3f = AL_UNKOWN_4;
                            state->unk38 = (s32) (state->unk38 - 1);
                            alEvtqPostEvent(&sndp->evtq, (ALEvent*)event_ptr, 0x8235);

                            return;
                        }
                        
                        if (allocVoiceOk_rename_me)
                        {
                            tstate = (ALSoundState*)D_800243E4.node.prev;
                            do
                            {
                                if (
                                    ((tstate->stateFlags.bbbb.unk3e & 0x12) == 0)
                                    && ((tstate->stateFlags.bbbb.unk3e & 4) != 0)
                                    && (tstate->stateFlags.bbbb.unk3f != AL_UNKOWN_3))
                                {
                                    playVoiceAllocEvent.unsignedType = AL_SNDP_END_EVT;
                                    playVoiceAllocEvent.common.state = tstate;
                                    tstate->stateFlags.bbbb.unk3f = AL_UNKOWN_3;
                                    allocVoiceOk_rename_me = 0;
                                    loopCheckVar = tstate;
                                    
                                    delta = 1000;
                                    alEvtqPostEvent(&sndp->evtq, &playVoiceAllocEvent, delta);
                                    
                                    tstate = loopCheckVar;
                                    vtmp = 0;
                                    delta = 1000;
                                    voice = &tstate->voice;
                                    alSynSetVol(sndp->drvr, (ALEvent *)voice, vtmp, delta);
                                }

                                // nonmatching: something goes here?
                            }
                            while (allocVoiceOk_rename_me != 0 && (tstate = (ALSoundState *)loopCheckVar->link.prev) != NULL);

                            if (tstate == NULL)
                            {
                                state->unk38 = 2;
                                alEvtqPostEvent(&sndp->evtq, (ALEvent*)event_ptr, 1000 + 1);
                                return;
                            }

                            sfx_c_70008948(state);
                            return;
                        }
                        
                        sfx_c_70008948(state);
                        return;
                    }

                    state->stateFlags.halfbytebyte.unk3e |= 4;
                    alSynStartVoice(sndp->drvr, voice, snd->wavetable);

                    state->stateFlags.bbbb.unk3f = AL_PLAYING;
                    D_800243F4++;

                    vtmp = 
                        (
                            (s32) (
                                D_80063BA4[keyMap->keyMin & 0x3F]
                                * (
                                    (s32) (snd->envelope->attackVolume * state->vol * snd->sampleVolume)
                                    / (AL_VOL_FULL * AL_VOL_FULL)
                                )
                            )
                        / 0x7FFF);

                    delta = (s32) (((f32) snd->envelope->releaseTime / state->pitch_2c) / state->vol);

                    //vtmp = ((s32) (*(D_80063BA4 + ((temp_s6->unk2 & 0x3F) * 2)) * ((s32) (temp_v0_5->unkC * temp_s1->unk34 * temp_s2->unkD) / 0x3F01)) / 0x7FFF) - 1;
                    //delta = (s32) (((f32) temp_v0_5->unk0 / temp_s1->unk2C) / temp_s1->unk28);
                    
                    vtmp = MIN(vtmp - 1, 0);

                    alSynSetVol(sndp->drvr, voice, 0, 0);
                    alSynSetVol(sndp->drvr, voice, vtmp, delta);
                    
                    vtmp = state->stateFlags.bbbb.unk3c - AL_PAN_CENTER + snd->samplePan;
                    pan = (ALPan) MIN(MAX(vtmp, AL_PAN_LEFT), AL_PAN_RIGHT);

                    alSynSetPan(sndp->drvr, voice, pan);
                    alSynSetPitch(sndp->drvr, voice, state->pitch_2c * state->pitch_28);

                    vtmp   = (state->stateFlags.bbbb.unk3d + (keyMap->keyMax & 0xf)) * 8;
                    vtmp = MIN(AL_VOL_FULL, MAX(AL_DEFAULT_FXMIX, vtmp));
                    alSynSetFXMix(sndp->drvr, voice, (u8)vtmp);

                    evt.common.type     = AL_SNDP_DECAY_EVT;
                    evt.common.state    = state;
                    delta = (ALMicroTime) ((snd->envelope->attackTime / state->pitch_2c) / state->pitch_28);
                    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
                }
                else
                {
                    return;
                }
            }
            break;
            
            // case 0x400
            case (AL_SNDP_UNKNOWN_10_EVT):
                // fallthrough to AL_SNDP_STOP_EVT

            // case 1 (or 2?)
            case (AL_SNDP_STOP_EVT):
            {
                if ((state->stateFlags.bbbb.unk3e & AL_STOPPING) != 0)
                {
                    if ((state->stateFlags.bbbb.unk3f != AL_UNKOWN_5) && (state->stateFlags.bbbb.unk3f != AL_UNKOWN_4))
                    {
                        sfx_c_70008A30(&sndp->evtq, state, AL_SNDP_DECAY_EVT); // _removeEvents?
                        delta = (s32) (((f32) snd->envelope->releaseTime / state->pitch_2c) / state->pitch_28);
                        alSynSetVol(sndp->drvr, &state->voice.table, 0, delta);
                        if (delta != 0)
                        {
                            evt.common.type = AL_SNDP_END_EVT;
                            evt.common.state = state;
                            alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
                            state->stateFlags.bbbb.unk3e = AL_STOPPING;
                        }
                        else
                        {
                            sfx_c_70008948(state);
                        }
                    }
                    else
                    {
                        sfx_c_70008948(state);
                    }
                }
            }
            break;
            
            // case 3 (or 4?)
            case (AL_SNDP_PAN_EVT):
            {
                state->unk36 = event_ptr->pan.pan;
                if (state->stateFlags.bbbb.unk3c == AL_PLAYING)
                {
                    tmp   = state->unk36 - AL_PAN_CENTER + snd->samplePan;
                    tmp   = MAX(tmp, AL_PAN_LEFT);
                    pan   = (ALPan) MIN(tmp, AL_PAN_RIGHT);
                    alSynSetPan(sndp->drvr, &state->voice, pan);
                }

                //////////////////////////////////////////////////////////////////////
                // sndplayer.c
                //

                // state->pan = event->pan.pan;
                // if (state->state == AL_PLAYING && snd){
                //     tmp   = state->pan - AL_PAN_CENTER + snd->samplePan;
                //     tmp   = MAX(tmp, AL_PAN_LEFT);
                //     pan   = (ALPan) MIN(tmp, AL_PAN_RIGHT);
                //     alSynSetPan(sndp->drvr, &state->voice, pan);
                // }
            }
            break;
            
            // case 7 (or 8?)
            case (AL_SNDP_VOL_EVT):
            {
                state->vol = event_ptr->vol.vol;
                if (state->stateFlags.bbbb.unk3c == AL_PLAYING && snd)
                {
                    vtmp = ((s32) (D_80063BA4[snd->keyMap->keyMin & 0x3F] * ((s32) (snd->envelope->decayVolume * state->vol * snd->sampleVolume) / 0x3F01)) / 0x7FFF) - 1;
                    
                    if (vtmp < 0)
                    {
                        vtmp = 0;
                    }

                    alSynSetVol(sndp->drvr, &state->voice.table, (s16) vtmp, 1000);
                }

                //////////////////////////////////////////////////////////////////////
                // sndplayer.c
                //
                
                // state->vol = event->vol.vol;
                // if (state->state == AL_PLAYING && snd)
                // {
                //     vtmp  = snd->envelope->decayVolume * state->vol/AL_VOL_FULL;            
                //     alSynSetVol(sndp->drvr, &state->voice, (s16) vtmp, 1000);
                // }
            }
            break;
            
            // case 15 (or 16?)
            case (AL_SNDP_PITCH_EVT):
            {
                state->pitch_2c = event_ptr->pitch.pitch;
                if (state->stateFlags.bbbb.unk3c == AL_PLAYING)
                {
                    alSynSetPitch(sndp->drvr, &state->voice, state->pitch_2c * state->unk38);
                    if ((state->stateFlags.bbbb.unk3e & 0x20) != 0)
                    {
                        sfx_c_700089C4(state);
                    }
                }

                //////////////////////////////////////////////////////////////////////
                // sndplayer.c
                //
                
                // /* Limit the pitch to a practical value even though we only need */
                // /* to limit it to a non-zero number to avoid divide by zero. */
                // if ((state->pitch = event->pitch.pitch) < MIN_RATIO)
                // {
                //     state->pitch = MIN_RATIO;
                // }
            
                // if (state->state == AL_PLAYING) {
                //     alSynSetPitch(sndp->drvr, &state->voice, state->pitch);
                // }
            }
            break;

            // case 0x20
            // handled in sndPlayerVoiceHandler
            // // // case (AL_SNDP_API_EVT):
            
            // case 0x40
            case (AL_SNDP_DECAY_EVT):
            {
                if ((state->stateFlags.halfbytebyte.unk3e & 2) == 0)
                    {
                        vtmp = ((s32) (D_80063BA4[snd->keyMap->keyMin & 0x3F] * ((s32) (snd->envelope->decayVolume * state->vol * snd->sampleVolume) / 0x3F01)) / 0x7FFF) - 1;
                        if (vtmp < 0)
                        {
                            vtmp = 0;
                        }
                        delta = (s32) (((f32) snd->envelope->releaseTime / state->unk38) / state->vol);
                        alSynSetVol(sndp->drvr, &state->voice, (s16) vtmp, delta);

                        evt.common.type        = 2; // should be AL_SNDP_STOP_EVT ?
                        evt.common.state       = state;
                        alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);

                        if ((state->stateFlags.halfbytebyte.unk3e & 0x20) != 0)
                        {
                            sfx_c_700089C4(state);
                        }
                    }

                //////////////////////////////////////////////////////////////////////
                // sndplayer.c
                //
                
                // if (snd->envelope->decayTime != -1)
                // {
                //     vtmp = snd->envelope->decayVolume * state->vol/AL_VOL_FULL;            
                //     //delta = (ALMicroTime) _DivS32ByF32 (snd->envelope->decayTime, state->pitch);
                //     delta = (ALMicroTime) (snd->envelope->decayTime / state->pitch);
                //     alSynSetVol(sndp->drvr, &state->voice, (s16) vtmp, delta);

                //     evt.common.type        = AL_SNDP_STOP_EVT;
                //     evt.common.state       = state;
                //     alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
                // }
            }
            break;
            
            // case 0x80
            case (AL_SNDP_END_EVT):
            {
                sfx_c_70008948(state);
                
                //////////////////////////////////////////////////////////////////////
                // sndplayer.c
                //
                
                // /* note: this code is repeated in AL_SNDP_STOP_EVT */
                // alSynStopVoice(sndp->drvr, &state->voice);
                // alSynFreeVoice(sndp->drvr, &state->voice);
                // _removeEvents(&sndp->evtq, state);
                // state->state = AL_STOPPED;
            }
            break;
            
            // case 0x100
            case (AL_SNDP_FX_EVT):
            {
                state->unk37 = event_ptr->fx.mix;
                if (state->stateFlags.bbbb.unk3c == AL_PLAYING)
                {
                    vtmp   = state->unk37 + snd->keyMap->keyMin * 8;
                    vtmp   = MIN(0, vtmp);
                    vtmp   = MAX(vtmp, AL_VOL_FULL);
                    alSynSetFXMix(sndp->drvr, &state->voice, (u8)vtmp);
                }

                //////////////////////////////////////////////////////////////////////
                // sndplayer.c
                //
                
                // state->fxMix = event->fx.mix;
                // if (state->state == AL_PLAYING)
                // {
                //     alSynSetFXMix(sndp->drvr, &state->voice, state->fxMix);
                // }
            }
            break;
            
            // case 0x200
            case (AL_SNDP_UNKNOWN_09_EVT):
            {
                if ((state->stateFlags.halfbytebyte.unk3e & 0x10) != 0)
                {
                    play_sfx_a1(&event_ptr->unk_u_1.unkC, event_ptr->unk_u_1.unkA, &state->state);
                }
            }
            break;
            
            // case 0x800
            case (AL_SNDP_UNKNOWN_11_EVT):
            {
                if (state->stateFlags.bbbb.unk3c == AL_PLAYING)
                {
                    vtmp = ((s32) (D_80063BA4[snd->keyMap->keyMin & 0x3F] * ((s32) (snd->envelope->decayVolume * state->vol * snd->sampleVolume) / 0x3F01)) / 0x7FFF) - 1;
                    if (vtmp < 0)
                    {
                        vtmp = 0;
                    }

                    delta = (s32) (((f32) snd->envelope->releaseTime / state->pitch_2c) / state->vol);
                    alSynSetVol(sndp->drvr, &state->voice, (s16) vtmp, delta);
                }
            }
            break;
            
            // case 0x1000
            case (AL_SNDP_UNKNOWN_12_EVT):
            {
                // nothing?
            }
            break;

            default:
            break;
        }

        event = event_ptr->common.state->link.next;
        if (event == NULL)
        {
            done = 1;
        }
        else
        {
            msgtype = event_ptr->msg.type;
        }
    }
}

/**
 * 9548    70008948
 */
void sfx_c_70008948(ALSoundState *state)
{
    if (state->stateFlags.halfbytebyte.unk3e & 4)
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

    alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0x8235);
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
 *     accepts: A0=sound data offset?, A1=sample address?
 * 
 * @param arg0 unused.
 * @param a1 Immediately cast to (ALSound *).
 */
ALSoundState *sfx_c_70008B70(struct ALBankAlt_s *arg0, ALSound* a1)
{
    s32 decayTimeFlag;
    ALKeyMap *keymap = a1->keyMap;
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

        decayTimeFlag = (a1->envelope->decayTime == -1);
        state->unk36 = decayTimeFlag + 0x40;

        state->stateFlags.halfbytebyte.unk3f = AL_UNKOWN_5;
        state->unk38 = 2;
        state->sound = a1;
        state->pitch_2c = 1.0f;
        state->stateFlags.halfbytebyte.unk3e = (keymap->keyMax & (u8)0xf0);
        state->state = NULL;
        
        if ((state->stateFlags.halfbytebyte.unk3e & 0x20) != 0)
        {
            state->pitch_28 = alCents2Ratio(((keymap->keyBase * 100) + -0x1770));
        }
        else
        {
            state->pitch_28 = alCents2Ratio((((keymap->keyBase * 100) + keymap->detune) + -0x1770));
        }

        if (decayTimeFlag)
        {
            state->stateFlags.halfbytebyte.unk3e |= 2;
        }

        state->stateFlags.bbbb.unk3d = (u8)0;
        state->stateFlags.bbbb.unk3c = (u8)0x40;
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

    if ((state->stateFlags.halfbytebyte.unk3e & 4) != 0)
    {
        D_800243F4--;
    }

    state->stateFlags.halfbytebyte.unk3f = (u8)0;

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
        state->unk36 = arg1;
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
        return state->stateFlags.halfbytebyte.unk3f;
    }

    return 0;
}

/**
 * 9A08    70008E08
 *     sets sound effect; used by sound effect routines
 *     accepts: A0=p->SE buffer, A1=SE #, A2=p->data
 *          data:    0x0    4    p->SE entry
 *              0x4    4    target volume
 *              0x8    4    audible range (timer)
 *              0xC    4    initial volume
 *              0x10    4    p->preset emitting sound
 *              0x14    4    p->object emitting sound
 * 
 *  decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: yes
 * - identical registers: fail
 */
#ifdef NONMATCHING
ALSoundState *play_sfx_a1(struct ALBankAlt_s *arg0, s16 arg1, ALSoundState *arg2)
{
    // declarations
    
    // declaration order doesn't seem to matter for these.

    ALSoundState *state;
    ALSoundState *state_phi_s7;
    ALSound *sound;
    ALMicroTime delta_phi_s4;

    // declaration order matters:

    s16 sp6E; // 110(sp)
    // unused s16 108(sp)
    ALMicroTime sp68; // 104(sp)
    ALMicroTime delta_temp_s3; // 100(sp)
    
    // end declarations

    state_phi_s7 = NULL;
    sp6E = 0;
    delta_phi_s4 = 0;

    if(0); // debug?

    if (bootswitch_sound)
    {
        return NULL;
    }

    if (arg1 == 0)
    {
        return NULL;
    }

    do
    {
        ALKeyMap *keyMap;

        sound = (arg0->instArray[0]->soundArray[arg1]);
        state = sfx_c_70008B70(arg0, sound);

        if (state != NULL)
        {
            ALSndpEvent evt_play;

            g_sndPlayerPtr->target = (s32)state;
            evt_play.common.type = AL_SNDP_PLAY_EVT;
            evt_play.common.state = state;
            delta_temp_s3 = sound->keyMap->velocityMax * 0x8235;

            if ((state->stateFlags.bbbb.unk3e & 0x10) != 0)
            {
                state->stateFlags.bbbb.unk3e &= (~(s16)(0x10));
                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt_play, delta_phi_s4 + 1);
                sp68 = delta_temp_s3 + 1;
                sp6E = (s16)arg1;
            }
            else
            {
                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt_play, delta_temp_s3 + 1);
            }

            state_phi_s7 = state;
        }

        delta_phi_s4 += delta_temp_s3;

        keyMap = sound->keyMap;
        arg1 = (s16)((s32)keyMap->velocityMin + ((s32)(keyMap->keyMin & 0xC0) * 4));
    } while (arg1 != 0 && state != NULL);

    if (state_phi_s7 != NULL)
    {
        state_phi_s7->stateFlags.bbbb.unk3e |= 0x1;
        state_phi_s7->state = arg2;

        if (sp6E != 0)
        {
            ALSndpEvent evt_09;
    
            state_phi_s7->stateFlags.bbbb.unk3e |= 0x10;

            evt_09.common.type = AL_SNDP_UNKNOWN_09_EVT;
            evt_09.common.state = state_phi_s7;
            evt_09.align_size.unk8 = sp6E;
            evt_09.align_size.unkC = (s32)arg0;

            alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt_09, sp68);
        }
    }

    if (arg2 != NULL)
    {
        arg2->link.next = (void*)state_phi_s7;
    }

    return state_phi_s7;
}
#else
GLOBAL_ASM(
.text
glabel play_sfx_a1
/* 009A08 70008E08 27BDFF80 */  addiu $sp, $sp, -0x80
/* 009A0C 70008E0C 3C0F8002 */  lui   $t7, %hi(bootswitch_sound) 
/* 009A10 70008E10 81EF43F8 */  lb    $t7, %lo(bootswitch_sound)($t7)
/* 009A14 70008E14 AFB1001C */  sw    $s1, 0x1c($sp)
/* 009A18 70008E18 00058C00 */  sll   $s1, $a1, 0x10
/* 009A1C 70008E1C 00117403 */  sra   $t6, $s1, 0x10
/* 009A20 70008E20 AFBE0038 */  sw    $fp, 0x38($sp)
/* 009A24 70008E24 AFB70034 */  sw    $s7, 0x34($sp)
/* 009A28 70008E28 AFB40028 */  sw    $s4, 0x28($sp)
/* 009A2C 70008E2C 0080F025 */  move  $fp, $a0
/* 009A30 70008E30 01C08825 */  move  $s1, $t6
/* 009A34 70008E34 AFBF003C */  sw    $ra, 0x3c($sp)
/* 009A38 70008E38 AFB60030 */  sw    $s6, 0x30($sp)
/* 009A3C 70008E3C AFB5002C */  sw    $s5, 0x2c($sp)
/* 009A40 70008E40 AFB30024 */  sw    $s3, 0x24($sp)
/* 009A44 70008E44 AFB20020 */  sw    $s2, 0x20($sp)
/* 009A48 70008E48 AFB00018 */  sw    $s0, 0x18($sp)
/* 009A4C 70008E4C AFA50084 */  sw    $a1, 0x84($sp)
/* 009A50 70008E50 AFA60088 */  sw    $a2, 0x88($sp)
/* 009A54 70008E54 0000B825 */  move  $s7, $zero
/* 009A58 70008E58 A7A0006E */  sh    $zero, 0x6e($sp)
/* 009A5C 70008E5C 11E00003 */  beqz  $t7, .L70008E6C
/* 009A60 70008E60 0000A025 */   move  $s4, $zero
/* 009A64 70008E64 10000062 */  b     .L70008FF0
/* 009A68 70008E68 00001025 */   move  $v0, $zero
.L70008E6C:
/* 009A6C 70008E6C 16200003 */  bnez  $s1, .L70008E7C
/* 009A70 70008E70 27B60050 */   addiu $s6, $sp, 0x50
/* 009A74 70008E74 1000005E */  b     .L70008FF0
/* 009A78 70008E78 00001025 */   move  $v0, $zero
.L70008E7C:
/* 009A7C 70008E7C 3C158002 */  lui   $s5, %hi(g_sndPlayerPtr)
/* 009A80 70008E80 26B543F0 */  addiu $s5, %lo(g_sndPlayerPtr) # addiu $s5, $s5, 0x43f0
/* 009A84 70008E84 8FB30064 */  lw    $s3, 0x64($sp)
/* 009A88 70008E88 8FD8000C */  lw    $t8, 0xc($fp)
.L70008E8C:
/* 009A8C 70008E8C 0011C880 */  sll   $t9, $s1, 2
/* 009A90 70008E90 03C02025 */  move  $a0, $fp
/* 009A94 70008E94 03194021 */  addu  $t0, $t8, $t9
/* 009A98 70008E98 8D12000C */  lw    $s2, 0xc($t0)
/* 009A9C 70008E9C 0C0022DC */  jal   sfx_c_70008B70
/* 009AA0 70008EA0 02402825 */   move  $a1, $s2
/* 009AA4 70008EA4 10400028 */  beqz  $v0, .L70008F48
/* 009AA8 70008EA8 00408025 */   move  $s0, $v0
/* 009AAC 70008EAC 8EA90000 */  lw    $t1, ($s5)
/* 009AB0 70008EB0 240A0001 */  li    $t2, 1
/* 009AB4 70008EB4 02C02825 */  move  $a1, $s6
/* 009AB8 70008EB8 AD22003C */  sw    $v0, 0x3c($t1)
/* 009ABC 70008EBC A7AA0050 */  sh    $t2, 0x50($sp)
/* 009AC0 70008EC0 AFA20054 */  sw    $v0, 0x54($sp)
/* 009AC4 70008EC4 8E4B0004 */  lw    $t3, 4($s2)
/* 009AC8 70008EC8 904D003E */  lbu   $t5, 0x3e($v0)
/* 009ACC 70008ECC 91730001 */  lbu   $s3, 1($t3)
/* 009AD0 70008ED0 31AE0010 */  andi  $t6, $t5, 0x10
/* 009AD4 70008ED4 00136180 */  sll   $t4, $s3, 6
/* 009AD8 70008ED8 01936021 */  addu  $t4, $t4, $s3
/* 009ADC 70008EDC 000C60C0 */  sll   $t4, $t4, 3
/* 009AE0 70008EE0 01936021 */  addu  $t4, $t4, $s3
/* 009AE4 70008EE4 000C6080 */  sll   $t4, $t4, 2
/* 009AE8 70008EE8 01936023 */  subu  $t4, $t4, $s3
/* 009AEC 70008EEC 000C6080 */  sll   $t4, $t4, 2
/* 009AF0 70008EF0 01936021 */  addu  $t4, $t4, $s3
/* 009AF4 70008EF4 000C6080 */  sll   $t4, $t4, 2
/* 009AF8 70008EF8 01936021 */  addu  $t4, $t4, $s3
/* 009AFC 70008EFC 11C0000D */  beqz  $t6, .L70008F34
/* 009B00 70008F00 01809825 */   move  $s3, $t4
/* 009B04 70008F04 904F003E */  lbu   $t7, 0x3e($v0)
/* 009B08 70008F08 02C02825 */  move  $a1, $s6
/* 009B0C 70008F0C 26860001 */  addiu $a2, $s4, 1
/* 009B10 70008F10 31F8FFEF */  andi  $t8, $t7, 0xffef
/* 009B14 70008F14 A058003E */  sb    $t8, 0x3e($v0)
/* 009B18 70008F18 8EA40000 */  lw    $a0, ($s5)
/* 009B1C 70008F1C 0C004BBF */  jal   alEvtqPostEvent
/* 009B20 70008F20 24840014 */   addiu $a0, $a0, 0x14
/* 009B24 70008F24 26790001 */  addiu $t9, $s3, 1
/* 009B28 70008F28 AFB90068 */  sw    $t9, 0x68($sp)
/* 009B2C 70008F2C 10000005 */  b     .L70008F44
/* 009B30 70008F30 A7B1006E */   sh    $s1, 0x6e($sp)
.L70008F34:
/* 009B34 70008F34 8EA40000 */  lw    $a0, ($s5)
/* 009B38 70008F38 26660001 */  addiu $a2, $s3, 1
/* 009B3C 70008F3C 0C004BBF */  jal   alEvtqPostEvent
/* 009B40 70008F40 24840014 */   addiu $a0, $a0, 0x14
.L70008F44:
/* 009B44 70008F44 0200B825 */  move  $s7, $s0
.L70008F48:
/* 009B48 70008F48 8E420004 */  lw    $v0, 4($s2)
/* 009B4C 70008F4C 0293A021 */  addu  $s4, $s4, $s3
/* 009B50 70008F50 90490002 */  lbu   $t1, 2($v0)
/* 009B54 70008F54 90480000 */  lbu   $t0, ($v0)
/* 009B58 70008F58 312A00C0 */  andi  $t2, $t1, 0xc0
/* 009B5C 70008F5C 000A5880 */  sll   $t3, $t2, 2
/* 009B60 70008F60 010B8821 */  addu  $s1, $t0, $t3
/* 009B64 70008F64 00116400 */  sll   $t4, $s1, 0x10
/* 009B68 70008F68 000C8C03 */  sra   $s1, $t4, 0x10
/* 009B6C 70008F6C 12200004 */  beqz  $s1, .L70008F80
/* 009B70 70008F70 00000000 */   nop   
/* 009B74 70008F74 5600FFC5 */  bnezl $s0, .L70008E8C
/* 009B78 70008F78 8FD8000C */   lw    $t8, 0xc($fp)
/* 009B7C 70008F7C AFB30064 */  sw    $s3, 0x64($sp)
.L70008F80:
/* 009B80 70008F80 52E00017 */  beql  $s7, $zero, .L70008FE0
/* 009B84 70008F84 8FAC0088 */   lw    $t4, 0x88($sp)
/* 009B88 70008F88 92EE003E */  lbu   $t6, 0x3e($s7)
/* 009B8C 70008F8C 24080200 */  li    $t0, 512
/* 009B90 70008F90 27A50040 */  addiu $a1, $sp, 0x40
/* 009B94 70008F94 35CF0001 */  ori   $t7, $t6, 1
/* 009B98 70008F98 A2EF003E */  sb    $t7, 0x3e($s7)
/* 009B9C 70008F9C 8FB80088 */  lw    $t8, 0x88($sp)
/* 009BA0 70008FA0 35EA0010 */  ori   $t2, $t7, 0x10
/* 009BA4 70008FA4 AEF80030 */  sw    $t8, 0x30($s7)
/* 009BA8 70008FA8 87B9006E */  lh    $t9, 0x6e($sp)
/* 009BAC 70008FAC 5320000C */  beql  $t9, $zero, .L70008FE0
/* 009BB0 70008FB0 8FAC0088 */   lw    $t4, 0x88($sp)
/* 009BB4 70008FB4 A2EA003E */  sb    $t2, 0x3e($s7)
/* 009BB8 70008FB8 87AB006E */  lh    $t3, 0x6e($sp)
/* 009BBC 70008FBC 8EA40000 */  lw    $a0, ($s5)
/* 009BC0 70008FC0 A7A80040 */  sh    $t0, 0x40($sp)
/* 009BC4 70008FC4 AFB70044 */  sw    $s7, 0x44($sp)
/* 009BC8 70008FC8 AFBE004C */  sw    $fp, 0x4c($sp)
/* 009BCC 70008FCC 8FA60068 */  lw    $a2, 0x68($sp)
/* 009BD0 70008FD0 AFAB0048 */  sw    $t3, 0x48($sp)
/* 009BD4 70008FD4 0C004BBF */  jal   alEvtqPostEvent
/* 009BD8 70008FD8 24840014 */   addiu $a0, $a0, 0x14
/* 009BDC 70008FDC 8FAC0088 */  lw    $t4, 0x88($sp)
.L70008FE0:
/* 009BE0 70008FE0 02E01025 */  move  $v0, $s7
/* 009BE4 70008FE4 11800002 */  beqz  $t4, .L70008FF0
/* 009BE8 70008FE8 00000000 */   nop   
/* 009BEC 70008FEC AD970000 */  sw    $s7, ($t4)
.L70008FF0:
/* 009BF0 70008FF0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 009BF4 70008FF4 8FB00018 */  lw    $s0, 0x18($sp)
/* 009BF8 70008FF8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 009BFC 70008FFC 8FB20020 */  lw    $s2, 0x20($sp)
/* 009C00 70009000 8FB30024 */  lw    $s3, 0x24($sp)
/* 009C04 70009004 8FB40028 */  lw    $s4, 0x28($sp)
/* 009C08 70009008 8FB5002C */  lw    $s5, 0x2c($sp)
/* 009C0C 7000900C 8FB60030 */  lw    $s6, 0x30($sp)
/* 009C10 70009010 8FB70034 */  lw    $s7, 0x34($sp)
/* 009C14 70009014 8FBE0038 */  lw    $fp, 0x38($sp)
/* 009C18 70009018 03E00008 */  jr    $ra
/* 009C1C 7000901C 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif

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
        state->stateFlags.bbbb.unk3e = (s8) (state->stateFlags.bbbb.unk3e & (~(s16)(0x10)));

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

        if ((item->stateFlags.bbbb.unk3e & arg0) == arg0)
        {
            item->stateFlags.bbbb.unk3e = (s8) (item->stateFlags.bbbb.unk3e & (~(s16)(0x10)));
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
    evt.unk_u_1.unk8 = arg2;

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
                evt.common.type = AL_SNDP_UNKNOWN_11_EVT;
                evt.common.state = item;

                alEvtqPostEvent(&g_sndPlayerPtr->evtq, (ALEvent *)&evt, 0);
            }
        }

        item = (ALSoundState *)item->link.next;
    }
}
