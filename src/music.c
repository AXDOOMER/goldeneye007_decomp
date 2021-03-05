#include "ultra64.h"
#include "include/PR/libaudio.h"
#include "inflate/inflate.h"
#include "audi.h"
#include "bondconstants.h"
#include "decompress.h"
#include "dyn.h"
#include "memp.h"
#include "ramrom.h"
#include "snd.h"

/**
 * @file music.c
 * This file contains code to handle music.
 */

/**
 * Counting definitions for music in this file, there
 * are 63 distinct entries. This exlcudes the "NONE" music
 * and control sequence entries.
 */
#define NUM_MUSIC_TRACKS  63

/**
 * Similar to NUM_MUSIC_TRACKS, but also counts "NONE" track
 * and control sequeence.
 */
#define MAX_NUM_MUSIC_TRACKS_W_NONE  (NUM_MUSIC_TRACKS + 2)

#define MUSIC_ALLOCATION_BYTES   0x2E000
#define MUSIC_MEMP_BANK                6

/**
 * The number of bytes allocated in the method call (alHeapDBAlloc) is close to num*size.
 * This is always set to one in this file...
 */
#define MUSIC_HEAP_NUMBER              1

#define MUSIC_SYN_CONFIG_MAX_P_VOICES 0x18
#define MUSIC_SYN_CONFIG_MAX_UPDATES  0x80

#define MUSIC_SEQ_CONFIG_MAX_VOICES    0x10
#define MUSIC_SEQ_CONFIG_MAX_EVENTS    0x40
#define MUSIC_SEQ_CONFIG_MAX_CHANNELS    16

#define MUSIC_SFX_SEQ_CONFIG_MAX_VOICES 0x40
#define MUSIC_SFX_SEQ_CONFIG_MAX_EVENTS 0x40
#define MUSIC_SFX_SEQ_CONFIG_CHANNEL       8

#define TRACK_1_DATA_SEQ_SIZE_BYTES   6344
#define TRACK_2_DATA_SEQ_SIZE_BYTES   2000
#define TRACK_3_DATA_SEQ_SIZE_BYTES   4000

struct audio_struct_a {
    u16 unk0;
    u16 unk2;
    u8 *unk4;
};

struct music_struct_b {
    u8 data[8438];
    u8 *unk_0;
};

s32 music_unused = 0;
s32 music1_track_num = 0;

// rename, should be volume.
u16 music1len = 0x7FFF;
s32 music2_track_num = 0;

// rename, should be volume.
u16 music2len = 0x7FFF;
s32 music3_track_num = 0;

// rename, should be volume.
u16 music3len = 0x7FFF;
s32 music1_playing = 0;
s32 music2_playing = 0;
s32 music3_playing = 0;

s16 music_tempo_array[MAX_NUM_MUSIC_TRACKS_W_NONE] = {
    /**
     * Index 0, M_NONE.
     */
    0x6665,

    /**
     * Index 1, M_SHORT_SOLO_DEATH.
     */
    0x7332,
    
    /**
     * Index 2, M_INTRO.
     */
    0x7332,
    
    /**
     * Index 3, M_TRAIN.
     */
    0x7998,
    
    /**
     * Index 4, M_DEPOT.
     */
    0x7332,
    
    /**
     * Index 5, M_MPTHEME.
     */
    0x5998,
    
    /**
     * Index 6, M_CITADEL.
     */
    0x6665,
    
    /**
     * Index 7, M_FACILITY.
     */
    0x6665,
    
    /**
     * Index 8, M_CONTROL.
     */
    0x6665,
    
    /**
     * Index 9, M_DAM.
     */
    0x6665,
    
    /**
     * Index 10, M_FRIGATE.
     */
    0x7332,
    
    /**
     * Index 11, M_ARCHIVES.
     */
    0x6665,
    
    /**
     * Index 12, M_SILO.
     */
    0x7332,
    
    /**
     * Index 13, M_MPTHEME2.
     */
    0x6665,
    
    /**
     * Index 14, M_STREETS.
     */
    0x6665,
    
    /**
     * Index 15, M_BUNKER1.
     */
    0x7332,
    
    /**
     * Index 16, M_BUNKER2.
     */
    0x7332,
    
    /**
     * Index 17, M_STATUE.
     */
    0x6665,
    
    /**
     * Index 18, M_ELEVATOR_CONTROL.
     */
    0x3FFF,
    
    /**
     * Index 19, M_CRADLE.
     */
    0x6665,
    
    /**
     * Index 20, M_UNK.
     */
    0x6665,
    
    /**
     * Index 21, M_ELEVATOR_WC.
     */
    0x3FFF,
    
    /**
     * Index 22, M_EGYPTIAN.
     */
    0x6665,
    
    /**
     * Index 23, M_FOLDERS.
     */
    0x6665,
    
    /**
     * Index 24, M_WATCH.
     */
    0x6665,
    
    /**
     * Index 25, M_AZTEC.
     */
    0x6665,
    
    /**
     * Index 26, M_WATERCAVERNS.
     */
    0x6665,
    
    /**
     * Index 27, M_DEATHSOLO.
     */
    0x7998,
    
    /**
     * Index 28, M_SURFACE2.
     */
    0x6665,
    
    /**
     * Index 29, M_TRAINX.
     */
    0x5998,
    
    /**
     * Index 30, M_UNK2.
     */
    0x6665,
    
    /**
     * Index 31, M_FACILITYX.
     */
    0x6665,
    
    /**
     * Index 32, M_DEPOTX.
     */
    0x6665,
    
    /**
     * Index 33, M_CONTROLX.
     */
    0x6665,
    
    /**
     * Index 34, M_WATERCAVERNSX.
     */
    0x6665,
    
    /**
     * Index 35, M_DAMX.
     */
    0x6665,
    
    /**
     * Index 36, M_FRIGATEX.
     */
    0x6665,
    
    /**
     * Index 37, M_ARCHIVESX.
     */
    0x5998,
    
    /**
     * Index 38, M_SILOX.
     */
    0x6665,
    
    /**
     * Index 39, M_EGYPTIANX.
     */
    0x3332,
    
    /**
     * Index 40, M_STREETSX.
     */
    0x6665,
    
    /**
     * Index 41, M_BUNKER1X.
     */
    0x7332,
    
    /**
     * Index 42, M_BUNKER2X.
     */
    0x7332,
    
    /**
     * Index 43, M_JUNGLEX.
     */
    0x5998,
    
    /**
     * Index 44, M_INTROSWOOSH.
     */
    0x7332,
    
    /**
     * Index 45, M_STATUEX.
     */
    0x6665,
    
    /**
     * Index 46, M_AZTECX.
     */
    0x6665,
    
    /**
     * Index 47, M_EGYPTX.
     */
    0x6665,
    
    /**
     * Index 48, M_CRADLEX.
     */
    0x6665,
    
    /**
     * Index 49, M_CUBA.
     */
    0x6665,
    
    /**
     * Index 50, M_RUNWAY.
     */
    0x6665,
    
    /**
     * Index 51, M_RUNWAYPLANE.
     */
    0x6665,
    
    /**
     * Index 52, M_MPTHEME3.
     */
    0x6CCB,
    
    /**
     * Index 53, M_WIND.
     */
    0x6665,
    
    /**
     * Index 54, M_GUITARGLISS.
     */
    0x6665,
    
    /**
     * Index 55, M_JUNGLE.
     */
    0x6665,
    
    /**
     * Index 56, M_RUNWAYX.
     */
    0x6665,
    
    /**
     * Index 57, M_SURFACE1.
     */
    0x6665,
    
    /**
     * Index 58, M_MPDEATH.
     */
    0x6665,
    
    /**
     * Index 59, M_SURFACE2X.
     */
    0x6665,
    
    /**
     * Index 60, M_SURFACE2END.
     */
    0x7332,
    
    /**
     * Index 61, M_STATUEPART.
     */
    0x6665,
    
    /**
     * Index 62, M_END_SOMETHING.
     */
    0x7332,
    
    /**
     * Index 63, unknown / unused / removed.
     */
    0x7998,

    /**
     * Index 64, control sequence. (some loops check for 0xffff).
     */
    0xFFFF
};


/*not sure why this is called hp, maybe for heap? */
ALHeap hp;
ALBank *ptr_sfx_buf;
ALBank *D_80063724;
ALCSPlayer *seqp_1;
ALCSPlayer *seqp_2;
ALCSPlayer *seqp_3;
ALSeqFile *ptr_musicdatatable;

/**
 * Something about starting offset of track data (maybe).
 */
u16 D_80063738[NUM_MUSIC_TRACKS + 1];

/**
 * Something about music track size (in bytes).
 */
u16 D_800637B8[NUM_MUSIC_TRACKS];

s16 D_80063836;

/**
* Compact sequence data pointer, track 1.
*/
u8 *D_80063838;

/**
* Compact sequence data pointer, track 2.
*/
u8 *D_8006383C;

/**
* Compact sequence data pointer, track 3.
*/
u8 *D_80063840;
u16 musicTrack1_length;
u16 D_80063846;
u16 D_80063848;
s16 music1_length;
s16 music2_length;
s16 music3_length;
s32 music1_rate;
s32 music2_rate;
s32 music3_rate;
s32 D_8006385C;

/**
 *  compact sequence, track 1
 */
ALCSeq D_80063860;

/**
 *  compact sequence, track 2
 */
ALCSeq D_80063958;

/**
 *  compact sequence, track 3
 */
ALCSeq D_80063A50;

s32 D_80063B58;
s32 D_80063B54;

char D_80063B50[0x54];
s32 D_80063BA4;
s32 D_80063BA8;

extern u32 _sfxtblSegmentRomStart;
extern u32 _sfxctlSegmentRomStart;
extern u32 _instrumentstblSegmentRomStart;
extern u32 _instrumentsctlSegmentRomStart;
extern u32 _musicsampletblSegmentRomStart;

// forward declarations

void musicTrack1Stop();
u16 musicTrack1Length();
void musicTrack1Vol(u16 arg0);
void musicTrack2Stop();
u16 musicTrack2Length();
void musicTrack2Vol(u16 arg0);
void musicTrack3Stop();
u16 get_music3len();
void musicTrack3Vol(u16 arg0);


// done with forward declarations

/**
 * 75F0	700069F0
 */
void audio_related(struct audio_struct_a *arg0, u32 romOffset)
{
    s32 count;
    struct audio_struct_a *p;

    for (count = 0, p = arg0; count < arg0->unk0; count++, p++)
    {
        p->unk4 = p->unk4 + romOffset;
    }
}

/**
 * 7630	70006A30
 *     loads sound and music banks into memory segment 6
 * 
 * Seems to be roughly based on n64devkit\ultra\usr\src\pr\demos_old\nnsample2\audio.c
 */
void setupaudio(void)
{
    // guess at struct.
    ALSeqpSfxConfig sfxSeqpConfig; // sp 216-228
    ALBankFile *sfxBank; // sp 212
    u32 ui;
    ALBankFile *instrumentBank; // sp 204

    // This type/cast is not correct, but this is how it matches.
    s32 tblSegmentRomStartAddress = (s32)&_musicsampletblSegmentRomStart; // ??

    ALSynConfig synconfig; // sp 164-192
    ALSeqpConfig track1SeqpConfig; // sp 136-160
    ALSeqpConfig track2SeqpConfig; // sp 108-132
    ALSeqpConfig track3SeqpConfig; // sp 80-104
    u8 *mempAddress;
    u8 *p;
    u16 d;
    u32 tblSegmentSize; // sp 64
    u32 size; // sp56;
    
    if (bootswitch_sound)
    {
        return;
    }

    p = (u8 *)mempAllocBytesInBank(MUSIC_ALLOCATION_BYTES, MUSIC_MEMP_BANK);

    mempAddress = p;
    do
    {
        *p++ = 0;
    } while (p < mempAddress + MUSIC_ALLOCATION_BYTES);

    alHeapInit(&hp, mempAddress, MUSIC_ALLOCATION_BYTES);

    if (1)
    {
        size = (u32)&_sfxtblSegmentRomStart - (u32)&_sfxctlSegmentRomStart;

        sfxBank = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, size);
        romCopy(sfxBank, &_sfxctlSegmentRomStart, size);
        alBnkfNew(sfxBank, (u8 *)&_sfxtblSegmentRomStart);
        ptr_sfx_buf = sfxBank->bankArray[0];
    }

    if (1)
    {
        size = (u32)&_instrumentstblSegmentRomStart - (u32)&_instrumentsctlSegmentRomStart;

        instrumentBank = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, size);
        romCopy(instrumentBank, &_instrumentsctlSegmentRomStart, size);
        alBnkfNew(instrumentBank, (u8 *)&_instrumentstblSegmentRomStart);
        D_80063724 = instrumentBank->bankArray[0];
    }

    // this area based on auReadSeqFileHeader

    size = 0x10;
    ptr_musicdatatable = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, size);
    romCopy(ptr_musicdatatable, (void *)tblSegmentRomStartAddress, size);

    tblSegmentSize = (sizeof(struct audio_struct_a) * ptr_musicdatatable->seqCount) + 4;
    ptr_musicdatatable = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, tblSegmentSize);
    romCopy(ptr_musicdatatable, (void *)tblSegmentRomStartAddress, ALIGN16_a(tblSegmentSize));

    audio_related(ptr_musicdatatable, (u32)&_musicsampletblSegmentRomStart);
    
    size = TRACK_1_DATA_SEQ_SIZE_BYTES;
    D_80063838 = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, size);

    size = TRACK_2_DATA_SEQ_SIZE_BYTES + TRACK_3_DATA_SEQ_SIZE_BYTES;
    D_8006383C = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, size);
    
    D_80063840 = (u8*)D_8006383C + TRACK_2_DATA_SEQ_SIZE_BYTES;

    for (ui = 0; ui < NUM_MUSIC_TRACKS; ui++)
    {
        D_80063738[ui] = ptr_musicdatatable->seqArray[ui].len;
        D_800637B8[ui] = ptr_musicdatatable->seqArray[ui].offset;

        if (D_80063738[ui] & 1)
        {
            D_80063738[ui]++;
        }
    }

    synconfig.maxVVoices = 0;
    synconfig.maxPVoices = MUSIC_SYN_CONFIG_MAX_P_VOICES;
    synconfig.maxUpdates = MUSIC_SYN_CONFIG_MAX_UPDATES;
    // synconfig.maxFXbusses, not set.
    synconfig.dmaproc = 0;
    synconfig.fxType = AL_FX_CUSTOM;
    synconfig.outputRate = 0;
    synconfig.heap = &hp;
    // synconfig.params, not set.

    amCreateAudioManager(&synconfig);

    track1SeqpConfig.maxVoices = MUSIC_SEQ_CONFIG_MAX_VOICES;
    track1SeqpConfig.maxEvents = MUSIC_SEQ_CONFIG_MAX_EVENTS;
    track1SeqpConfig.maxChannels = MUSIC_SEQ_CONFIG_MAX_CHANNELS;
    track1SeqpConfig.heap = &hp;
    track1SeqpConfig.initOsc = NULL;
    track1SeqpConfig.updateOsc = NULL;
    track1SeqpConfig.stopOsc = NULL;

    track2SeqpConfig.maxVoices = MUSIC_SEQ_CONFIG_MAX_VOICES;
    track2SeqpConfig.maxEvents = MUSIC_SEQ_CONFIG_MAX_EVENTS;
    track2SeqpConfig.maxChannels = MUSIC_SEQ_CONFIG_MAX_CHANNELS;
    track2SeqpConfig.heap = &hp;
    track2SeqpConfig.initOsc = NULL;
    track2SeqpConfig.updateOsc = NULL;
    track2SeqpConfig.stopOsc = NULL;

    track3SeqpConfig.maxVoices = MUSIC_SEQ_CONFIG_MAX_VOICES;
    track3SeqpConfig.maxEvents = MUSIC_SEQ_CONFIG_MAX_EVENTS;
    track3SeqpConfig.maxChannels = MUSIC_SEQ_CONFIG_MAX_CHANNELS;
    track3SeqpConfig.heap = &hp;
    track3SeqpConfig.initOsc = NULL;
    track3SeqpConfig.updateOsc = NULL;
    track3SeqpConfig.stopOsc = NULL;

    size = sizeof(ALCSPlayer); // 0x7C
    seqp_1 = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, size);
    seqp_2 = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, size);
    seqp_3 = alHeapAlloc(&hp, MUSIC_HEAP_NUMBER, size);

    // Typo / mistake, the following calls to alSeqpSetBank should actually
    // be to alCSPSetBank.
    alCSPNew(seqp_1, &track1SeqpConfig);
    alSeqpSetBank((ALSeqPlayer *)seqp_1, D_80063724);
    alCSPNew(seqp_2, &track2SeqpConfig);
    alSeqpSetBank((ALSeqPlayer *)seqp_2, D_80063724);
    alCSPNew(seqp_3, &track3SeqpConfig);
    alSeqpSetBank((ALSeqPlayer *)seqp_3, D_80063724);

    sfxSeqpConfig.maxEvents = MUSIC_SFX_SEQ_CONFIG_MAX_EVENTS;
    sfxSeqpConfig.maxVoices = MUSIC_SFX_SEQ_CONFIG_MAX_VOICES;
    sfxSeqpConfig.channelWord = MUSIC_SFX_SEQ_CONFIG_CHANNEL;
    sfxSeqpConfig.heap = &hp;
    
    sfx_c_70007B20(&sfxSeqpConfig);
    amStartAudioThread();
}


/**
 * 7A7C	70006E7C
 *     play first music track A0
 */
void musicTrack1Play(s32 arg0)
{
    u32 trackSizeBytes;
    struct music_struct_b thing;
    u8 *temp_a0;
    void *romAddress;
    u32 t3;
    struct huft sp34;

    if (bootswitch_sound)
    {
        return;
    }

    if (music1_track_num)
    {
        musicTrack1Stop();
    }

    music1_track_num = arg0;

    while (alCSPGetState(seqp_1))
        ;

    romAddress = ptr_musicdatatable->seqArray[music1_track_num].address;

    if (romAddress < (void*)0x10000U)
    {
        musicTrack1Play(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(D_80063738[music1_track_num]) + (NUM_MUSIC_TRACKS + 1);
    trackSizeBytes = ALIGN16_a(D_800637B8[music1_track_num]);
    thing.unk_0 = D_80063838;
    temp_a0 = (u8*)((t3 + (s32)thing.unk_0) - trackSizeBytes);

    romCopy(temp_a0, romAddress, trackSizeBytes);
    
    decompressdata(temp_a0, thing.unk_0, &sp34);
    alCSeqNew(&D_80063860, D_80063838);
    alCSPSetSeq(seqp_1, &D_80063860);
    musicTrack1Vol(musicTrack1Length());
    alCSPPlay(seqp_1);
}


/**
 * 7BD0	70006FD0
 *     stop playing first music track
 */
void musicTrack1Stop(void)
{
    if (bootswitch_sound)
    {
        return;
    }

    music1_playing = 0;

    if (music1_track_num != 0)
    {
        if (alCSPGetState(seqp_1) == 1)
        {
            alCSPStop(seqp_1);
        }
    }

    music1_track_num = 0;
}

/**
 * 7C30	70007030
 *     V0= [80024338]
 */



// rename, should be volume
u16 musicTrack1Length(void)
{
    return music1len;
}






/**
 * 7C3C	7000703C
 *     ??? - sets something for currently running music track...
 *     accepts: A0=value
 * 
 * There's only one other relevant place in the code base that has a SRL by 0xf,
 * it matches __vsVol in n64devkit\ultra\usr\src\pr\libsrc\libultra\audio\seqplayer.c
 * but it's hard to say if it's related here or not.
 */
void musicTrack1Vol(u16 arg0)
{
    u32 t1 = arg0;

    music1len = (u16)t1;

    t1 *= music_tempo_array[music1_track_num];
    t1 >>= 15;

    alCSPSetVol(seqp_1, t1);
}







/**
 * 7CA0	700070A0
 */
void musicTrack1Tempo(void)
{
    s32 i;
    
    music_tempo_array[music1_track_num] = musicTrack1Length();

    for (i = 0; music_tempo_array[i] >= 0; i++)
    {
        // removed;
    }
}



/**
 * 7CF8	700070F8
 */
void music_related_1(f32 rate)
{
    if (music1_playing >= 0)
    {
        musicTrack1_length = musicTrack1Length();
        music1_length = 0;
        music1_rate = (s32) (rate * 60.0f);
        music1_playing = -1;
    }
}






/**
 * 7D68	70007168
 */
void music_related_3(f32 rate, u16 length)
{
    if (music1_playing <= 0)
    {
        alCSPPlay(seqp_1);

        if (length == 0xffff)
        {
            music1_length = musicTrack1_length;
        }
        else
        {
            music1_length = length;
        }

        musicTrack1_length = 0;
        music1_rate = (s32) (rate * 60.0f);
        music1_playing = 1;
    }
}






/**
 * 7E04	70007204
 */
void musicTrack2Play(s32 arg0)
{
    u32 trackSizeBytes;
    struct music_struct_b thing;
    u8 *temp_a0;
    void *romAddress;
    u32 t3;
    struct huft sp34;

    if (bootswitch_sound)
    {
        return;
    }

    if (music2_track_num)
    {
        musicTrack2Stop();
    }

    music2_track_num = arg0;

    while (alCSPGetState(seqp_2))
        ;

    romAddress = ptr_musicdatatable->seqArray[music2_track_num].address;

    if (romAddress < (void*)0x10000U)
    {
        musicTrack2Play(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(D_80063738[music2_track_num]) + (NUM_MUSIC_TRACKS + 1);
    trackSizeBytes = ALIGN16_a(D_800637B8[music2_track_num]);
    thing.unk_0 = D_8006383C;
    temp_a0 = (u8*)((t3 + (s32)thing.unk_0) - trackSizeBytes);

    romCopy(temp_a0, romAddress, trackSizeBytes);
    
    decompressdata(temp_a0, thing.unk_0, &sp34);
    alCSeqNew(&D_80063958, D_8006383C);
    alCSPSetSeq(seqp_2, &D_80063958);
    musicTrack2Vol(musicTrack2Length());
    alCSPPlay(seqp_2);
}


/**
 * 7F58	70007358
 */
void musicTrack2Stop(void)
{
    if (bootswitch_sound)
    {
        return;
    }

    music2_playing = 0;

    if (music2_track_num != 0)
    {
        if (alCSPGetState(seqp_2) == 1)
        {
            alCSPStop(seqp_2);
        }
    }

    music2_track_num = 0;
}







/**
 * 7FB8	700073B8
 *     V0= [80024340]
 */

// rename, should be volume
u16 musicTrack2Length(void)
{
    return music2len;
}







/**
 * 7FC4	700073C4
 * 
 * See comments on musicTrack1Vol
 */
void musicTrack2Vol(u16 arg0)
{
    u32 t1 = arg0;

    music2len = (u16)t1;

    t1 *= music_tempo_array[music2_track_num];
    t1 >>= 15;

    alCSPSetVol(seqp_2, t1);
}






/**
 * 8028	70007428
 */
void musicTrack2Tempo(void)
{
    s32 i;
    
    music_tempo_array[music2_track_num] = musicTrack2Length();

    for (i = 0; music_tempo_array[i] >= 0; i++)
    {
        // removed;
    }
}


/**
 * 8080	70007480
 */
void music_related_6(f32 rate)
{
    if (music2_playing >= 0)
    {
        D_80063846 = musicTrack2Length();
        music2_length = 0;
        music2_rate = (s32) (rate * 60.0f);
        music2_playing = -1;
    }
}







/**
 * 80F0	700074F0
 */
void music_related_8(f32 rate, u16 length)
{
    if (music2_playing <= 0)
    {
        alCSPPlay(seqp_2);

        if (length == 0xffff)
        {
            music2_length = D_80063846;
        }
        else
        {
            music2_length = length;
        }

        D_80063846 = 0;
        music2_rate = (s32) (rate * 60.0f);
        music2_playing = 1;
    }
}




/**
 * 818C	7000758C
 */
void music_related_3rd_block(s32 arg0)
{
    u32 trackSizeBytes;
    struct music_struct_b thing;
    u8 *temp_a0;
    void *romAddress;
    u32 t3;
    struct huft sp34;

    if (bootswitch_sound)
    {
        return;
    }

    if (music3_track_num)
    {
        musicTrack3Stop();
    }

    music3_track_num = arg0;

    while (alCSPGetState(seqp_3))
        ;

    romAddress = ptr_musicdatatable->seqArray[music3_track_num].address;

    if (romAddress < (void*)0x10000U)
    {
        music_related_3rd_block(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(D_80063738[music3_track_num]) + (NUM_MUSIC_TRACKS + 1);
    trackSizeBytes = ALIGN16_a(D_800637B8[music3_track_num]);
    thing.unk_0 = D_80063840;
    temp_a0 = (u8*)((t3 + (s32)thing.unk_0) - trackSizeBytes);

    romCopy(temp_a0, romAddress, trackSizeBytes);
    
    decompressdata(temp_a0, thing.unk_0, &sp34);
    alCSeqNew(&D_80063A50, D_80063840);
    alCSPSetSeq(seqp_3, &D_80063A50);
    musicTrack3Vol(get_music3len());
    alCSPPlay(seqp_3);
}


/**
 * 82E0	700076E0
 */
void musicTrack3Stop(void)
{
    if (bootswitch_sound)
    {
        return;
    }

    music3_playing = 0;

    if (music3_track_num != 0)
    {
        if (alCSPGetState(seqp_3) == 1)
        {
            alCSPStop(seqp_3);
        }
    }

    music3_track_num = 0;
}







/**
 * 8340	70007740
 *     V0= 7FFF [80024348]
 */

// rename, should be volume, and should match the other naming convention
u16 get_music3len(void)
{
    return music3len;
}







/**
 * 834C	7000774C
 * 
 * See comments on musicTrack1Vol.
 */
void musicTrack3Vol(u16 arg0)
{
    u32 t1 = arg0;

    music3len = (u16)t1;

    t1 *= music_tempo_array[music3_track_num];
    t1 >>= 15;

    alCSPSetVol(seqp_3, t1);
}








/**
 * 83B0	700077B0
 */




// rename, should be musicTrack3Tempo
void music_related_10(void)
{
    s32 i;
    
    music_tempo_array[music3_track_num] = get_music3len();

    for (i = 0; music_tempo_array[i] >= 0; i++)
    {
        // removed;
    }
}



/**
 * 8408	70007808
 */
void music_related_11(f32 rate)
{
    if (music3_playing >= 0)
    {
        D_80063848 = get_music3len();
        music3_length = 0;
        music3_rate = (s32) (rate * 60.0f);
        music3_playing = -1;
    }
}





/**
 * 8478	70007878
 */
void music_related_13(f32 rate, u16 length)
{
    if (music3_playing <= 0)
    {
        alCSPPlay(seqp_3);

        if (length == 0xffff)
        {
            music3_length = D_80063848;
        }
        else
        {
            music3_length = length;
        }

        D_80063848 = 0;
        music3_rate = (s32) (rate * 60.0f);
        music3_playing = 1;
    }
}





/**
 * 8514	70007914
 */
void music_related_15(void)
{
    if (music1_playing)
    {
        u16 t0;
        s32 t1;
        
        t0 = musicTrack1Length();
        t1 = (u16)music1_length - t0;
        t0 += (s32) ((f32) t1 / (f32) music1_rate);

        musicTrack1Vol(t0);
        music1_rate--;

        if (music1_rate <= 0)
        {
            if (t0 == 0)
            {
                alCSPStop(seqp_1);
            }

            music1_rate = 0;
            music1_playing = 0;
        }
    }

    if (music2_playing)
    {
        u16 t0;
        s32 t1;

        t0 = musicTrack2Length();
        t1 = (u16)music2_length - t0;
        t0 += (s32) ((f32) t1 / (f32) music2_rate);

        musicTrack2Vol(t0);
        music2_rate--;

        if (music2_rate <= 0)
        {
            if (t0 == 0)
            {
                alCSPStop(seqp_2);
            }

            music2_rate = 0;
            music2_playing = 0;
        }
    }

    if (music3_playing)
    {
        u16 t0;
        s32 t1;
        
        t0 = get_music3len();
        t1 = (u16)music3_length - t0;
        t0 += (s32) ((f32) t1 / (f32) music3_rate);

        musicTrack3Vol(t0);
        music3_rate--;

        if (music3_rate <= 0)
        {
            if (t0 == 0)
            {
                alCSPStop(seqp_3);
            }

            music3_rate = 0;
            music3_playing = 0;
        }
    }
}




