#include "ultra64.h"
#include "ramrom.h"
#include "snd.h"
#include "include/PR/libaudio.h"
#include "inflate/inflate.h"
#include "decompress.h"
#include "dyn.h"
#include "bondconstants.h"

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


struct music_struct_c {
    s32 unk0;
    void *unk4;
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
u32 hp[4];
u32 *ptr_sfx_buf;
s32 D_80063724;
ALCSPlayer *seqp_1;
ALCSPlayer *seqp_2;
ALCSPlayer *seqp_3;
struct music_struct_c *ptr_musicdatatable;

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

struct audio_struct_a {
    u16 unk0;
    u16 unk2;
    s32 unk4;
};

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
void audio_related(struct audio_struct_a *arg0, u32 arg1)
{
    s32 count;
    struct audio_struct_a *p;

    for (count = 0, p = arg0; count < arg0->unk0; count++, p++)
    {
        p->unk4 += arg1;
    }
}

/**
 * 7630	70006A30
 *     loads sound and music banks into memory segment 6
 */
#ifdef NONMATCHING
void setupaudio(void)
{
    s32 sp38;
    s32 sp40;
    ?32 sp50;
    ?32 sp54;
    s8 sp58;
    ?32 sp60;
    ?32 sp64;
    ?32 sp68;
    ?32 sp6C;
    ?32 sp70;
    s8 sp74;
    ?32 sp7C;
    ?32 sp80;
    ?32 sp84;
    ?32 sp88;
    ?32 sp8C;
    s8 sp90;
    ?32 sp98;
    ?32 sp9C;
    ?32 spA0;
    ?32 spA4;
    ?32 spA8;
    ?32 spAC;
    ?32 spB4;
    ?32 spBC;
    s8 spC0;
    s32 spCC;
    s32 spD4;
    ?32 spD8;
    ?32 spDC;
    ?32 spE0;
    ? temp_ret;
    u32 temp_v1;
    s32 temp_v0;
    ? temp_ret_2;
    s32 temp_v0_2;
    ? temp_ret_3;
    ? temp_ret_4;
    s32 temp_v1_2;
    ? temp_ret_5;
    ? temp_ret_6;
    s16 temp_t4;
    void *temp_a0;
    void *temp_a1;
    s32 temp_v0_3;
    u32 phi_v1;
    void *phi_a0;
    void *phi_v1_2;
    void *phi_a1;

    // Node 0
    if (bootswitch_sound == 0)
    {
        // Node 1
        temp_ret = mempAllocBytesInBank(0x2e000, 6);
        phi_v1 = temp_ret;
loop_2:
        // Node 2
        temp_v1 = (phi_v1 + 1);
        temp_v1->unk-1 = (u8)0;
        phi_v1 = temp_v1;
        if (temp_v1 < (u32) (temp_ret + 0x2e000))
        {
            goto loop_2;
        }
        // Node 3
        alHeapInit(&hp, temp_ret, 0x2e000);
        temp_v0 = (&_sfxtblSegmentRomStart - &_sfxctlSegmentRomStart);
        sp38 = temp_v0;
        temp_ret_2 = alHeapDBAlloc(0, 0, &hp, 1, temp_v0);
        spD4 = temp_ret_2;
        romCopy(temp_ret_2, &_sfxctlSegmentRomStart, sp38);
        alBnkfNew(spD4, &_sfxtblSegmentRomStart);
        temp_v0_2 = (&_instrumentstblSegmentRomStart - &_instrumentsctlSegmentRomStart);
        sp38 = temp_v0_2;
        ptr_sfx_buf = (?32) spD4->unk4;
        temp_ret_3 = alHeapDBAlloc(0, 0, &hp, 1, temp_v0_2);
        spCC = temp_ret_3;
        romCopy(temp_ret_3, &_instrumentsctlSegmentRomStart, sp38);
        alBnkfNew(spCC, &_instrumentstblSegmentRomStart);
        D_80063724 = (?32) spCC->unk4;
        temp_ret_4 = alHeapDBAlloc(0, 0, &hp, 1, 0x10);
        ptr_musicdatatable = temp_ret_4;
        romCopy(temp_ret_4, &_musicsampletblSegmentRomStart, 0x10);
        temp_v1_2 = ((*ptr_musicdatatable * 8) + 4);
        sp40 = temp_v1_2;
        temp_ret_5 = alHeapDBAlloc(0, 0, &hp, 1, temp_v1_2);
        ptr_musicdatatable = temp_ret_5;
        romCopy(temp_ret_5, sp38, (((temp_v1_2 + 0xf) | 0xf) ^ 0xf), &ptr_musicdatatable);
        audio_related(ptr_musicdatatable, &_musicsampletblSegmentRomStart);
        D_80063838 = alHeapDBAlloc(0, 0, &hp, 1, 0x18c8);
        temp_ret_6 = alHeapDBAlloc(0, 0, &hp, 1, 0x1770);
        D_8006383C = temp_ret_6;
        D_80063840 = (s32) (temp_ret_6 + 0x7d0);
        phi_a0 = (void *) ptr_musicdatatable;
        phi_v1_2 = &D_80063738;
        phi_a1 = &D_800637B8;
loop_4:
        // Node 4
        temp_t4 = phi_a0->unk8;
        temp_a0 = (phi_a0 + 8);
        temp_a1 = (phi_a1 + 2);
        *phi_v1_2 = temp_t4;
        temp_v0_3 = (temp_t4 & 0xffff);
        temp_a1->unk-2 = (s16) temp_a0->unk2;
        if ((temp_v0_3 & 1) != 0)
        {
            // Node 5
            *phi_v1_2 = (s16) (temp_v0_3 + 1);
        }
        // Node 6
        phi_a0 = temp_a0;
        phi_v1_2 = (phi_v1_2 + 2);
        phi_a1 = temp_a1;
        if (temp_a1 != &D_80063836)
        {
            goto loop_4;
        }
        // Node 7
        spA4 = 0;
        spA8 = 0x18;
        spAC = 0x80;
        spB4 = 0;
        spC0 = (u8)6;
        spBC = 0;
        amCreateAudioManager(&spA4, temp_a1, &D_80063836, &D_8006383C);
        
        sp88 = 0x10;
        sp8C = 0x40;
        sp90 = (u8)0x10;
        sp98 = 0;
        sp9C = 0;
        spA0 = 0;

        sp6C = 0x10;
        sp70 = 0x40;
        sp74 = (u8)0x10;
        sp7C = 0;
        sp80 = 0;
        sp84 = 0;

        sp50 = 0x10;
        sp54 = 0x40;
        sp58 = (u8)0x10;
        sp60 = 0;
        sp64 = 0;
        sp68 = 0;
        seqp_1 = alHeapDBAlloc(0, 0, &hp, 1, 0x7c);
        seqp_2 = alHeapDBAlloc(0, 0, &hp, 1, 0x7c);
        seqp_3 = alHeapDBAlloc(0, 0, &hp, 1, 0x7c);
        alCSPNew(seqp_1, &sp88);
        alSeqpSetBank(seqp_1, D_80063724);
        alCSPNew(seqp_2, &sp6C);
        alSeqpSetBank(seqp_2, D_80063724);
        alCSPNew(seqp_3, &sp50);
        alSeqpSetBank(seqp_3, D_80063724);
        spDC = 0x40;
        spD8 = 0x40;
        spE0 = 8;
        sfx_c_70007B20(&spD8);
        amStartAudioThread();
    }
    // Node 8
    return;
}
#else
GLOBAL_ASM(
.text
glabel setupaudio
/* 007630 70006A30 3C0E8002 */  lui   $t6, %hi(bootswitch_sound) 
/* 007634 70006A34 81CE43F8 */  lb    $t6, %lo(bootswitch_sound)($t6)
/* 007638 70006A38 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 00763C 70006A3C AFBF0024 */  sw    $ra, 0x24($sp)
/* 007640 70006A40 15C00109 */  bnez  $t6, .L70006E68
/* 007644 70006A44 AFB00020 */   sw    $s0, 0x20($sp)
/* 007648 70006A48 3C040002 */  lui   $a0, (0x0002E000 >> 16) # lui $a0, 2
/* 00764C 70006A4C 3484E000 */  ori   $a0, (0x0002E000 & 0xFFFF) # ori $a0, $a0, 0xe000
/* 007650 70006A50 0C0025C8 */  jal   mempAllocBytesInBank
/* 007654 70006A54 24050006 */   li    $a1, 6
/* 007658 70006A58 3C010002 */  lui   $at, (0x0002E000 >> 16) # lui $at, 2
/* 00765C 70006A5C 3421E000 */  ori   $at, (0x0002E000 & 0xFFFF) # ori $at, $at, 0xe000
/* 007660 70006A60 00401825 */  move  $v1, $v0
/* 007664 70006A64 00402825 */  move  $a1, $v0
/* 007668 70006A68 00412021 */  addu  $a0, $v0, $at
.L70006A6C:
/* 00766C 70006A6C 24630001 */  addiu $v1, $v1, 1
/* 007670 70006A70 0064082B */  sltu  $at, $v1, $a0
/* 007674 70006A74 1420FFFD */  bnez  $at, .L70006A6C
/* 007678 70006A78 A060FFFF */   sb    $zero, -1($v1)
/* 00767C 70006A7C 3C108006 */  lui   $s0, %hi(hp)
/* 007680 70006A80 26103710 */  addiu $s0, %lo(hp) # addiu $s0, $s0, 0x3710
/* 007684 70006A84 3C060002 */  lui   $a2, (0x0002E000 >> 16) # lui $a2, 2
/* 007688 70006A88 34C6E000 */  ori   $a2, (0x0002E000 & 0xFFFF) # ori $a2, $a2, 0xe000
/* 00768C 70006A8C 0C00434C */  jal   alHeapInit
/* 007690 70006A90 02002025 */   move  $a0, $s0
/* 007694 70006A94 3C0F002F */  lui   $t7, %hi(_sfxtblSegmentRomStart) # $t7, 0x2f
/* 007698 70006A98 3C18002F */  lui   $t8, %hi(_sfxctlSegmentRomStart) # $t8, 0x2f
/* 00769C 70006A9C 2718BDE0 */  addiu $t8, %lo(_sfxctlSegmentRomStart) # addiu $t8, $t8, -0x4220
/* 0076A0 70006AA0 25EF19A0 */  addiu $t7, %lo(_sfxtblSegmentRomStart) # addiu $t7, $t7, 0x19a0
/* 0076A4 70006AA4 01F81023 */  subu  $v0, $t7, $t8
/* 0076A8 70006AA8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0076AC 70006AAC AFA20038 */  sw    $v0, 0x38($sp)
/* 0076B0 70006AB0 00002025 */  move  $a0, $zero
/* 0076B4 70006AB4 00002825 */  move  $a1, $zero
/* 0076B8 70006AB8 02003025 */  move  $a2, $s0
/* 0076BC 70006ABC 0C003AD4 */  jal   alHeapDBAlloc
/* 0076C0 70006AC0 24070001 */   li    $a3, 1
/* 0076C4 70006AC4 3C05002F */  lui   $a1, %hi(_sfxctlSegmentRomStart) # $a1, 0x2f
/* 0076C8 70006AC8 AFA200D4 */  sw    $v0, 0xd4($sp)
/* 0076CC 70006ACC 24A5BDE0 */  addiu $a1, %lo(_sfxctlSegmentRomStart) # addiu $a1, $a1, -0x4220
/* 0076D0 70006AD0 00402025 */  move  $a0, $v0
/* 0076D4 70006AD4 0C001707 */  jal   romCopy
/* 0076D8 70006AD8 8FA60038 */   lw    $a2, 0x38($sp)
/* 0076DC 70006ADC 3C05002F */  lui   $a1, %hi(_sfxtblSegmentRomStart) # $a1, 0x2f
/* 0076E0 70006AE0 24A519A0 */  addiu $a1, %lo(_sfxtblSegmentRomStart) # addiu $a1, $a1, 0x19a0
/* 0076E4 70006AE4 0C00439D */  jal   alBnkfNew
/* 0076E8 70006AE8 8FA400D4 */   lw    $a0, 0xd4($sp)
/* 0076EC 70006AEC 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0076F0 70006AF0 3C09003C */  lui   $t1, %hi(_instrumentstblSegmentRomStart) # $t1, 0x3c
/* 0076F4 70006AF4 3C0A003B */  lui   $t2, %hi(_instrumentsctlSegmentRomStart) # $t2, 0x3b
/* 0076F8 70006AF8 8F280004 */  lw    $t0, 4($t9)
/* 0076FC 70006AFC 254A4450 */  addiu $t2, %lo(_instrumentsctlSegmentRomStart) # addiu $t2, $t2, 0x4450
/* 007700 70006B00 252987F0 */  addiu $t1, %lo(_instrumentstblSegmentRomStart) # addiu $t1, $t1, -0x7810
/* 007704 70006B04 3C018006 */  lui   $at, %hi(ptr_sfx_buf)
/* 007708 70006B08 012A1023 */  subu  $v0, $t1, $t2
/* 00770C 70006B0C AFA20010 */  sw    $v0, 0x10($sp)
/* 007710 70006B10 AFA20038 */  sw    $v0, 0x38($sp)
/* 007714 70006B14 00002025 */  move  $a0, $zero
/* 007718 70006B18 00002825 */  move  $a1, $zero
/* 00771C 70006B1C 02003025 */  move  $a2, $s0
/* 007720 70006B20 24070001 */  li    $a3, 1
/* 007724 70006B24 0C003AD4 */  jal   alHeapDBAlloc
/* 007728 70006B28 AC283720 */   sw    $t0, %lo(ptr_sfx_buf)($at)
/* 00772C 70006B2C 3C05003B */  lui   $a1, %hi(_instrumentsctlSegmentRomStart) # $a1, 0x3b
/* 007730 70006B30 AFA200CC */  sw    $v0, 0xcc($sp)
/* 007734 70006B34 24A54450 */  addiu $a1, %lo(_instrumentsctlSegmentRomStart) # addiu $a1, $a1, 0x4450
/* 007738 70006B38 00402025 */  move  $a0, $v0
/* 00773C 70006B3C 0C001707 */  jal   romCopy
/* 007740 70006B40 8FA60038 */   lw    $a2, 0x38($sp)
/* 007744 70006B44 3C05003C */  lui   $a1, %hi(_instrumentstblSegmentRomStart) # $a1, 0x3c
/* 007748 70006B48 24A587F0 */  addiu $a1, %lo(_instrumentstblSegmentRomStart) # addiu $a1, $a1, -0x7810
/* 00774C 70006B4C 0C00439D */  jal   alBnkfNew
/* 007750 70006B50 8FA400CC */   lw    $a0, 0xcc($sp)
/* 007754 70006B54 8FAB00CC */  lw    $t3, 0xcc($sp)
/* 007758 70006B58 3C018006 */  lui   $at, %hi(D_80063724)
/* 00775C 70006B5C 240D0010 */  li    $t5, 16
/* 007760 70006B60 8D6C0004 */  lw    $t4, 4($t3)
/* 007764 70006B64 AFAD0010 */  sw    $t5, 0x10($sp)
/* 007768 70006B68 00002025 */  move  $a0, $zero
/* 00776C 70006B6C 00002825 */  move  $a1, $zero
/* 007770 70006B70 02003025 */  move  $a2, $s0
/* 007774 70006B74 24070001 */  li    $a3, 1
/* 007778 70006B78 0C003AD4 */  jal   alHeapDBAlloc
/* 00777C 70006B7C AC2C3724 */   sw    $t4, %lo(D_80063724)($at)
/* 007780 70006B80 3C038006 */  lui   $v1, %hi(ptr_musicdatatable)
/* 007784 70006B84 3C050042 */  lui   $a1, %hi(_musicsampletblSegmentRomStart) # $a1, 0x42
/* 007788 70006B88 24633734 */  addiu $v1, %lo(ptr_musicdatatable) # addiu $v1, $v1, 0x3734
/* 00778C 70006B8C 24A59790 */  addiu $a1, %lo(_musicsampletblSegmentRomStart) # addiu $a1, $a1, -0x6870
/* 007790 70006B90 AC620000 */  sw    $v0, ($v1)
/* 007794 70006B94 AFA50038 */  sw    $a1, 0x38($sp)
/* 007798 70006B98 00402025 */  move  $a0, $v0
/* 00779C 70006B9C 0C001707 */  jal   romCopy
/* 0077A0 70006BA0 24060010 */   li    $a2, 16
/* 0077A4 70006BA4 3C0E8006 */  lui   $t6, %hi(ptr_musicdatatable) 
/* 0077A8 70006BA8 8DCE3734 */  lw    $t6, %lo(ptr_musicdatatable)($t6)
/* 0077AC 70006BAC 00002025 */  move  $a0, $zero
/* 0077B0 70006BB0 00002825 */  move  $a1, $zero
/* 0077B4 70006BB4 95C30000 */  lhu   $v1, ($t6)
/* 0077B8 70006BB8 02003025 */  move  $a2, $s0
/* 0077BC 70006BBC 24070001 */  li    $a3, 1
/* 0077C0 70006BC0 000378C0 */  sll   $t7, $v1, 3
/* 0077C4 70006BC4 25E30004 */  addiu $v1, $t7, 4
/* 0077C8 70006BC8 AFA30010 */  sw    $v1, 0x10($sp)
/* 0077CC 70006BCC 0C003AD4 */  jal   alHeapDBAlloc
/* 0077D0 70006BD0 AFA30040 */   sw    $v1, 0x40($sp)
/* 0077D4 70006BD4 8FA30040 */  lw    $v1, 0x40($sp)
/* 0077D8 70006BD8 3C078006 */  lui   $a3, %hi(ptr_musicdatatable)
/* 0077DC 70006BDC 24E73734 */  addiu $a3, %lo(ptr_musicdatatable) # addiu $a3, $a3, 0x3734
/* 0077E0 70006BE0 2466000F */  addiu $a2, $v1, 0xf
/* 0077E4 70006BE4 34D8000F */  ori   $t8, $a2, 0xf
/* 0077E8 70006BE8 ACE20000 */  sw    $v0, ($a3)
/* 0077EC 70006BEC 3B06000F */  xori  $a2, $t8, 0xf
/* 0077F0 70006BF0 00402025 */  move  $a0, $v0
/* 0077F4 70006BF4 0C001707 */  jal   romCopy
/* 0077F8 70006BF8 8FA50038 */   lw    $a1, 0x38($sp)
/* 0077FC 70006BFC 3C048006 */  lui   $a0, %hi(ptr_musicdatatable)
/* 007800 70006C00 3C050042 */  lui   $a1, %hi(_musicsampletblSegmentRomStart) # $a1, 0x42
/* 007804 70006C04 24A59790 */  addiu $a1, %lo(_musicsampletblSegmentRomStart) # addiu $a1, $a1, -0x6870
/* 007808 70006C08 0C001A7C */  jal   audio_related
/* 00780C 70006C0C 8C843734 */   lw    $a0, %lo(ptr_musicdatatable)($a0)
/* 007810 70006C10 240818C8 */  li    $t0, 6344
/* 007814 70006C14 AFA80010 */  sw    $t0, 0x10($sp)
/* 007818 70006C18 00002025 */  move  $a0, $zero
/* 00781C 70006C1C 00002825 */  move  $a1, $zero
/* 007820 70006C20 02003025 */  move  $a2, $s0
/* 007824 70006C24 0C003AD4 */  jal   alHeapDBAlloc
/* 007828 70006C28 24070001 */   li    $a3, 1
/* 00782C 70006C2C 3C018006 */  lui   $at, %hi(D_80063838)
/* 007830 70006C30 24091770 */  li    $t1, 6000
/* 007834 70006C34 AC223838 */  sw    $v0, %lo(D_80063838)($at)
/* 007838 70006C38 AFA90010 */  sw    $t1, 0x10($sp)
/* 00783C 70006C3C 00002025 */  move  $a0, $zero
/* 007840 70006C40 00002825 */  move  $a1, $zero
/* 007844 70006C44 02003025 */  move  $a2, $s0
/* 007848 70006C48 0C003AD4 */  jal   alHeapDBAlloc
/* 00784C 70006C4C 24070001 */   li    $a3, 1
/* 007850 70006C50 3C078006 */  lui   $a3, %hi(D_8006383C)
/* 007854 70006C54 24E7383C */  addiu $a3, %lo(D_8006383C) # addiu $a3, $a3, 0x383c
/* 007858 70006C58 ACE20000 */  sw    $v0, ($a3)
/* 00785C 70006C5C 244B07D0 */  addiu $t3, $v0, 0x7d0
/* 007860 70006C60 3C018006 */  lui   $at, %hi(D_80063840)
/* 007864 70006C64 3C038006 */  lui   $v1, %hi(D_80063738)
/* 007868 70006C68 3C048006 */  lui   $a0, %hi(ptr_musicdatatable)
/* 00786C 70006C6C 3C058006 */  lui   $a1, %hi(D_800637B8)
/* 007870 70006C70 3C068006 */  lui   $a2, %hi(D_80063836)
/* 007874 70006C74 AC2B3840 */  sw    $t3, %lo(D_80063840)($at)
/* 007878 70006C78 24C63836 */  addiu $a2, %lo(D_80063836) # addiu $a2, $a2, 0x3836
/* 00787C 70006C7C 24A537B8 */  addiu $a1, %lo(D_800637B8) # addiu $a1, $a1, 0x37b8
/* 007880 70006C80 8C843734 */  lw    $a0, %lo(ptr_musicdatatable)($a0)
/* 007884 70006C84 24633738 */  addiu $v1, %lo(D_80063738) # addiu $v1, $v1, 0x3738
.L70006C88:
/* 007888 70006C88 948C0008 */  lhu   $t4, 8($a0)
/* 00788C 70006C8C 24840008 */  addiu $a0, $a0, 8
/* 007890 70006C90 24A50002 */  addiu $a1, $a1, 2
/* 007894 70006C94 A46C0000 */  sh    $t4, ($v1)
/* 007898 70006C98 948D0002 */  lhu   $t5, 2($a0)
/* 00789C 70006C9C 3182FFFF */  andi  $v0, $t4, 0xffff
/* 0078A0 70006CA0 304E0001 */  andi  $t6, $v0, 1
/* 0078A4 70006CA4 11C00003 */  beqz  $t6, .L70006CB4
/* 0078A8 70006CA8 A4ADFFFE */   sh    $t5, -2($a1)
/* 0078AC 70006CAC 244F0001 */  addiu $t7, $v0, 1
/* 0078B0 70006CB0 A46F0000 */  sh    $t7, ($v1)
.L70006CB4:
/* 0078B4 70006CB4 14A6FFF4 */  bne   $a1, $a2, .L70006C88
/* 0078B8 70006CB8 24630002 */   addiu $v1, $v1, 2
/* 0078BC 70006CBC 24180018 */  li    $t8, 24
/* 0078C0 70006CC0 24190080 */  li    $t9, 128
/* 0078C4 70006CC4 24080006 */  li    $t0, 6
/* 0078C8 70006CC8 AFA000A4 */  sw    $zero, 0xa4($sp)
/* 0078CC 70006CCC AFB800A8 */  sw    $t8, 0xa8($sp)
/* 0078D0 70006CD0 AFB900AC */  sw    $t9, 0xac($sp)
/* 0078D4 70006CD4 AFA000B4 */  sw    $zero, 0xb4($sp)
/* 0078D8 70006CD8 A3A800C0 */  sb    $t0, 0xc0($sp)
/* 0078DC 70006CDC AFA000BC */  sw    $zero, 0xbc($sp)
/* 0078E0 70006CE0 AFB000B8 */  sw    $s0, 0xb8($sp)
/* 0078E4 70006CE4 0C0006F4 */  jal   amCreateAudioManager
/* 0078E8 70006CE8 27A400A4 */   addiu $a0, $sp, 0xa4
/* 0078EC 70006CEC 24090010 */  li    $t1, 16
/* 0078F0 70006CF0 240A0040 */  li    $t2, 64
/* 0078F4 70006CF4 240B0010 */  li    $t3, 16
/* 0078F8 70006CF8 240C0010 */  li    $t4, 16
/* 0078FC 70006CFC 240D0040 */  li    $t5, 64
/* 007900 70006D00 240E0010 */  li    $t6, 16
/* 007904 70006D04 240F0010 */  li    $t7, 16
/* 007908 70006D08 24180040 */  li    $t8, 64
/* 00790C 70006D0C 24190010 */  li    $t9, 16
/* 007910 70006D10 2408007C */  li    $t0, 124
/* 007914 70006D14 AFA90088 */  sw    $t1, 0x88($sp)
/* 007918 70006D18 AFAA008C */  sw    $t2, 0x8c($sp)
/* 00791C 70006D1C A3AB0090 */  sb    $t3, 0x90($sp)
/* 007920 70006D20 AFB00094 */  sw    $s0, 0x94($sp)
/* 007924 70006D24 AFA00098 */  sw    $zero, 0x98($sp)
/* 007928 70006D28 AFA0009C */  sw    $zero, 0x9c($sp)
/* 00792C 70006D2C AFA000A0 */  sw    $zero, 0xa0($sp)
/* 007930 70006D30 AFAC006C */  sw    $t4, 0x6c($sp)
/* 007934 70006D34 AFAD0070 */  sw    $t5, 0x70($sp)
/* 007938 70006D38 A3AE0074 */  sb    $t6, 0x74($sp)
/* 00793C 70006D3C AFB00078 */  sw    $s0, 0x78($sp)
/* 007940 70006D40 AFA0007C */  sw    $zero, 0x7c($sp)
/* 007944 70006D44 AFA00080 */  sw    $zero, 0x80($sp)
/* 007948 70006D48 AFA00084 */  sw    $zero, 0x84($sp)
/* 00794C 70006D4C AFAF0050 */  sw    $t7, 0x50($sp)
/* 007950 70006D50 AFB80054 */  sw    $t8, 0x54($sp)
/* 007954 70006D54 A3B90058 */  sb    $t9, 0x58($sp)
/* 007958 70006D58 AFB0005C */  sw    $s0, 0x5c($sp)
/* 00795C 70006D5C AFA00060 */  sw    $zero, 0x60($sp)
/* 007960 70006D60 AFA00064 */  sw    $zero, 0x64($sp)
/* 007964 70006D64 AFA00068 */  sw    $zero, 0x68($sp)
/* 007968 70006D68 AFA80010 */  sw    $t0, 0x10($sp)
/* 00796C 70006D6C 00002025 */  move  $a0, $zero
/* 007970 70006D70 00002825 */  move  $a1, $zero
/* 007974 70006D74 02003025 */  move  $a2, $s0
/* 007978 70006D78 0C003AD4 */  jal   alHeapDBAlloc
/* 00797C 70006D7C 24070001 */   li    $a3, 1
/* 007980 70006D80 3C018006 */  lui   $at, %hi(seqp_1)
/* 007984 70006D84 2409007C */  li    $t1, 124
/* 007988 70006D88 AC223728 */  sw    $v0, %lo(seqp_1)($at)
/* 00798C 70006D8C AFA90010 */  sw    $t1, 0x10($sp)
/* 007990 70006D90 00002025 */  move  $a0, $zero
/* 007994 70006D94 00002825 */  move  $a1, $zero
/* 007998 70006D98 02003025 */  move  $a2, $s0
/* 00799C 70006D9C 0C003AD4 */  jal   alHeapDBAlloc
/* 0079A0 70006DA0 24070001 */   li    $a3, 1
/* 0079A4 70006DA4 3C018006 */  lui   $at, %hi(seqp_2)
/* 0079A8 70006DA8 240A007C */  li    $t2, 124
/* 0079AC 70006DAC AC22372C */  sw    $v0, %lo(seqp_2)($at)
/* 0079B0 70006DB0 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0079B4 70006DB4 00002025 */  move  $a0, $zero
/* 0079B8 70006DB8 00002825 */  move  $a1, $zero
/* 0079BC 70006DBC 02003025 */  move  $a2, $s0
/* 0079C0 70006DC0 0C003AD4 */  jal   alHeapDBAlloc
/* 0079C4 70006DC4 24070001 */   li    $a3, 1
/* 0079C8 70006DC8 3C018006 */  lui   $at, %hi(seqp_3)
/* 0079CC 70006DCC 3C048006 */  lui   $a0, %hi(seqp_1)
/* 0079D0 70006DD0 AC223730 */  sw    $v0, %lo(seqp_3)($at)
/* 0079D4 70006DD4 8C843728 */  lw    $a0, %lo(seqp_1)($a0)
/* 0079D8 70006DD8 0C004820 */  jal   alCSPNew
/* 0079DC 70006DDC 27A50088 */   addiu $a1, $sp, 0x88
/* 0079E0 70006DE0 3C048006 */  lui   $a0, %hi(seqp_1)
/* 0079E4 70006DE4 3C058006 */  lui   $a1, %hi(D_80063724)
/* 0079E8 70006DE8 8CA53724 */  lw    $a1, %lo(D_80063724)($a1)
/* 0079EC 70006DEC 0C00487C */  jal   alSeqpSetBank
/* 0079F0 70006DF0 8C843728 */   lw    $a0, %lo(seqp_1)($a0)
/* 0079F4 70006DF4 3C048006 */  lui   $a0, %hi(seqp_2)
/* 0079F8 70006DF8 8C84372C */  lw    $a0, %lo(seqp_2)($a0)
/* 0079FC 70006DFC 0C004820 */  jal   alCSPNew
/* 007A00 70006E00 27A5006C */   addiu $a1, $sp, 0x6c
/* 007A04 70006E04 3C048006 */  lui   $a0, %hi(seqp_2)
/* 007A08 70006E08 3C058006 */  lui   $a1, %hi(D_80063724)
/* 007A0C 70006E0C 8CA53724 */  lw    $a1, %lo(D_80063724)($a1)
/* 007A10 70006E10 0C00487C */  jal   alSeqpSetBank
/* 007A14 70006E14 8C84372C */   lw    $a0, %lo(seqp_2)($a0)
/* 007A18 70006E18 3C048006 */  lui   $a0, %hi(seqp_3)
/* 007A1C 70006E1C 8C843730 */  lw    $a0, %lo(seqp_3)($a0)
/* 007A20 70006E20 0C004820 */  jal   alCSPNew
/* 007A24 70006E24 27A50050 */   addiu $a1, $sp, 0x50
/* 007A28 70006E28 3C048006 */  lui   $a0, %hi(seqp_3)
/* 007A2C 70006E2C 3C058006 */  lui   $a1, %hi(D_80063724)
/* 007A30 70006E30 8CA53724 */  lw    $a1, %lo(D_80063724)($a1)
/* 007A34 70006E34 0C00487C */  jal   alSeqpSetBank
/* 007A38 70006E38 8C843730 */   lw    $a0, %lo(seqp_3)($a0)
/* 007A3C 70006E3C 240B0040 */  li    $t3, 64
/* 007A40 70006E40 240C0040 */  li    $t4, 64
/* 007A44 70006E44 240D0008 */  li    $t5, 8
/* 007A48 70006E48 AFAB00DC */  sw    $t3, 0xdc($sp)
/* 007A4C 70006E4C AFAC00D8 */  sw    $t4, 0xd8($sp)
/* 007A50 70006E50 AFAD00E0 */  sw    $t5, 0xe0($sp)
/* 007A54 70006E54 AFB000E4 */  sw    $s0, 0xe4($sp)
/* 007A58 70006E58 0C001EC8 */  jal   sfx_c_70007B20
/* 007A5C 70006E5C 27A400D8 */   addiu $a0, $sp, 0xd8
/* 007A60 70006E60 0C0007D6 */  jal   amStartAudioThread
/* 007A64 70006E64 00000000 */   nop   
.L70006E68:
/* 007A68 70006E68 8FBF0024 */  lw    $ra, 0x24($sp)
/* 007A6C 70006E6C 8FB00020 */  lw    $s0, 0x20($sp)
/* 007A70 70006E70 27BD00E8 */  addiu $sp, $sp, 0xe8
/* 007A74 70006E74 03E00008 */  jr    $ra
/* 007A78 70006E78 00000000 */   nop   
)
#endif


struct music_struct_b {
    u8 data[8438];
    u8 *unk_0;
};

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
    u8 *t3;
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

    romAddress = ptr_musicdatatable[music1_track_num].unk4;

    if (romAddress < (void*)0x10000U)
    {
        musicTrack1Play(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(D_80063738[music1_track_num]) + (NUM_MUSIC_TRACKS + 1);
    trackSizeBytes = ALIGN16_a(D_800637B8[music1_track_num]);
    thing.unk_0 = D_80063838;
    temp_a0 = (t3 + (s32)thing.unk_0) - trackSizeBytes;

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
    u8 *t3;
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

    romAddress = ptr_musicdatatable[music2_track_num].unk4;

    if (romAddress < (void*)0x10000U)
    {
        musicTrack2Play(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(D_80063738[music2_track_num]) + (NUM_MUSIC_TRACKS + 1);
    trackSizeBytes = ALIGN16_a(D_800637B8[music2_track_num]);
    thing.unk_0 = D_8006383C;
    temp_a0 = (t3 + (s32)thing.unk_0) - trackSizeBytes;

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
    u8 *t3;
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

    romAddress = ptr_musicdatatable[music3_track_num].unk4;

    if (romAddress < (void*)0x10000U)
    {
        music_related_3rd_block(M_SHORT_SOLO_DEATH);

        return;
    }

    t3 = ALIGN16_a(D_80063738[music3_track_num]) + (NUM_MUSIC_TRACKS + 1);
    trackSizeBytes = ALIGN16_a(D_800637B8[music3_track_num]);
    thing.unk_0 = D_80063840;
    temp_a0 = (t3 + (s32)thing.unk_0) - trackSizeBytes;

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




