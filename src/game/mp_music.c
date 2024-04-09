#include <ultra64.h>
#include <music.h>
#include "music_0D2720.h"
#include "watch.h"
#include "mp_music.h"

#ifdef VERSION_EU
#define MP_MUSIC_FRAMERATE 50
#else
#define MP_MUSIC_FRAMERATE 60
#endif

// bss
//CODE.bss:8008C600
s32 stageMusicID;
//CODE.bss:8008C604
s32 dword_CODE_bss_8008C604;

//CODE.bss:8008C608
s32 music_slot_active_0;
//CODE.bss:8008C60C
s32 music_slot_active_1;
//CODE.bss:8008C610
s32 music_slot_active_2;
//CODE.bss:8008C614
s32 music_slot_active_3;

//CODE.bss:8008C618
s32 music_slot_minutes_0;
//CODE.bss:8008C61C
s32 music_slot_minutes_1;
//CODE.bss:8008C620
s32 music_slot_minutes_2;
//CODE.bss:8008C624
s32 music_slot_minutes_3;

//CODE.bss:8008C628
s32 music_slot_seconds_0;
//CODE.bss:8008C62C
s32 music_slot_seconds_1;
//CODE.bss:8008C630
s32 music_slot_seconds_2;
//CODE.bss:8008C634
s32 music_slot_seconds_3;


// data
//D:800484C0
s32 mission_state = MISSION_STATE_0;



u16 sub_GAME_7F0C0BF0(void) {
    get_mTrack2Vol();
}

u16 sub_GAME_7F0C0C10(void) {
    return call_sndGetSfxSlotFirstNaturalVolume();
}


MISSION_STATE_ID get_mission_state(void) {
    return mission_state;
}






void set_missionstate(MISSION_STATE_ID arg0)
{
    s32 old_mission_state = mission_state;
    
    mission_state = arg0;
    
    switch (old_mission_state)
    {
        case MISSION_STATE_0:
        switch (arg0)
        {
#if defined(VERSION_US)
            case MISSION_STATE_0:
                return;
            case MISSION_STATE_1:
                musicTrack1ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack1Fade = 0;
                musicTrack1Play(getmusictrack_or_randomtrack(stageMusicID));
                return;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                break;
            case MISSION_STATE_4: // switch 2
                musicTrack1ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack1Fade = 0;
                musicTrack1Play(getmusictrack_or_randomtrack(stageMusicID));
                musicTrack3ApplySeqpVol(sub_GAME_7F0C0C10());
                g_musicXTrack3Fade = 0;
                musicTrack3Play(musicGetBgTrackForStage(stageMusicID));
                return;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                break;
#endif
            
#if defined(VERSION_JP) || defined(VERSION_EU)
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1: // switch 2
                musicTrack1ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack1Fade = 0;
                musicTrack1Play(getmusictrack_or_randomtrack(stageMusicID));
                return;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                break;
            case MISSION_STATE_4:
                musicTrack1ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack1Fade = 0;
                musicTrack1Play(getmusictrack_or_randomtrack(stageMusicID));
                musicTrack3ApplySeqpVol(sub_GAME_7F0C0C10());
                g_musicXTrack3Fade = 0;
                musicTrack3Play(musicGetBgTrackForStage(stageMusicID));
                return;
                break;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                break;
#endif
        }
        
        case MISSION_STATE_1:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                break;
            case MISSION_STATE_2:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(musicGetXTrackForStage(stageMusicID));
                musicTrack1FadeOut(0.5f);
                return;
            case MISSION_STATE_3:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x18);
                musicTrack1FadeOut(0.5f);
                return;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                musicTrack1FadeOut(0.02f);
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x3A);
                return;
        }
        
        case MISSION_STATE_2:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                musicTrack1FadeIn(0.5f, sub_GAME_7F0C0BF0());
                musicTrack2FadeOut(0.5f);
                return;
            case MISSION_STATE_2:
                return;
            case MISSION_STATE_3:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x18);
                return;
            case MISSION_STATE_4:
                break;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                break;
        }
        
        case MISSION_STATE_3:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                musicTrack1FadeIn(1.0f, sub_GAME_7F0C0BF0());
                musicTrack2FadeOut(1.0f);
                return;
            case MISSION_STATE_2:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(musicGetXTrackForStage(stageMusicID));
                return;
            case MISSION_STATE_3:
                break;
            case MISSION_STATE_4:
                musicTrack1FadeIn(1.0f, sub_GAME_7F0C0BF0());
                musicTrack3FadeIn(1.0f, sub_GAME_7F0C0C10());
                musicTrack2FadeOut(1.0f);
                return;
            case MISSION_STATE_5:
                musicTrack3FadeIn(1.0f, sub_GAME_7F0C0C10());
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(musicGetXTrackForStage(stageMusicID));
                return;
            case MISSION_STATE_6:
                break;
        }
        
        case MISSION_STATE_4:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                break;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x18);
                musicTrack1FadeOut(0.5f);
                musicTrack3FadeOut(0.5f);
                return;
            case MISSION_STATE_4:
                break;
            case MISSION_STATE_5:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(musicGetXTrackForStage(stageMusicID));
                musicTrack1FadeOut(0.5f);
                return;
            case MISSION_STATE_6:
                break;
        }
        
        case MISSION_STATE_5:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                break;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x18);
                musicTrack3FadeOut(0.5f);
                return;
            case MISSION_STATE_4:
                musicTrack1FadeIn(0.5f, sub_GAME_7F0C0BF0());
                musicTrack2FadeOut(0.5f);
                return;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                break;
        }
        
        case MISSION_STATE_6:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                musicTrack1FadeIn(2.0f, sub_GAME_7F0C0BF0());
                musicTrack2FadeOut(2.0f);
                return;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                break;
            case MISSION_STATE_4:
                break;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x3A);
                return;
        }

        default:
        break;
    }
    
    while(1)
    {
        // error
    }
}




void sub_GAME_7F0C11FC(s32 stagenum)
{
    musicTrack1Stop();
    musicTrack2Stop();
    musicTrack3Stop();
    mission_state = MISSION_STATE_0;
    stageMusicID = stagenum;
    if (musicGetBgTrackForStage(stageMusicID) < 0) {
        set_missionstate(MISSION_STATE_1);
    }
    else {
        set_missionstate(MISSION_STATE_4);
    }
    return;
}

void set_missionstate_zero(void)
{
  set_missionstate(MISSION_STATE_0);
}

void sub_GAME_7F0C1288(void)
{
  if (musicGetBgTrackForStage(stageMusicID) < 0)
  {
    set_missionstate(MISSION_STATE_2);
  }
  else
  {
    set_missionstate(MISSION_STATE_5);
  }
}

void sub_GAME_7F0C12CC(void)
{
  if (musicGetBgTrackForStage(stageMusicID) < 0)
  {
    set_missionstate(MISSION_STATE_1);
  }
  else
  {
    set_missionstate(MISSION_STATE_4);
  }
}

void sub_GAME_7F0C1310(void)
{
  dword_CODE_bss_8008C604 = mission_state;
  set_missionstate(MISSION_STATE_3);
}

void sub_GAME_7F0C1340(void)
{
  set_missionstate(dword_CODE_bss_8008C604);
}

void sub_GAME_7F0C1364(void)
{
  music_slot_active_0 = 0;
  music_slot_minutes_0 = 0;
  music_slot_seconds_0 = 0;
  music_slot_active_1 = 0;
  music_slot_minutes_1 = 0;
  music_slot_seconds_1 = 0;
  music_slot_active_2 = 0;
  music_slot_minutes_2 = 0;
  music_slot_seconds_2 = 0;
  music_slot_active_3 = 0;
  music_slot_minutes_3 = 0;
  music_slot_seconds_3 = 0;
}






#ifdef NONMATCHING
void reset_all_music_slots(void) {

}
#else
GLOBAL_ASM(
.text
glabel reset_all_music_slots
/* 0F5EF8 7F0C13C8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F5EFC 7F0C13CC 3C078009 */  lui   $a3, %hi(music_slot_active_0)
/* 0F5F00 7F0C13D0 3C048009 */  lui   $a0, %hi(music_slot_minutes_0)
/* 0F5F04 7F0C13D4 3C068005 */  lui   $a2, %hi(g_ClockTimer)
/* 0F5F08 7F0C13D8 3C098009 */  lui   $t1, %hi(music_slot_seconds_0)
/* 0F5F0C 7F0C13DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F5F10 7F0C13E0 00005025 */  move  $t2, $zero
/* 0F5F14 7F0C13E4 2529C628 */  addiu $t1, %lo(music_slot_seconds_0) # addiu $t1, $t1, -0x39d8
/* 0F5F18 7F0C13E8 8CC68374 */  lw    $a2, %lo(g_ClockTimer)($a2)
/* 0F5F1C 7F0C13EC 2484C618 */  addiu $a0, %lo(music_slot_minutes_0) # addiu $a0, $a0, -0x39e8
/* 0F5F20 7F0C13F0 24E7C608 */  addiu $a3, %lo(music_slot_active_0) # addiu $a3, $a3, -0x39f8
/* 0F5F24 7F0C13F4 00004025 */  move  $t0, $zero
.L7F0C13F8:
/* 0F5F28 7F0C13F8 8CE50000 */  lw    $a1, ($a3)
/* 0F5F2C 7F0C13FC 54A00005 */  bnezl $a1, .L7F0C1414
/* 0F5F30 7F0C1400 8C820000 */   lw    $v0, ($a0)
/* 0F5F34 7F0C1404 8C8E0000 */  lw    $t6, ($a0)
/* 0F5F38 7F0C1408 59C0001F */  blezl $t6, .L7F0C1488
/* 0F5F3C 7F0C140C 24840004 */   addiu $a0, $a0, 4
/* 0F5F40 7F0C1410 8C820000 */  lw    $v0, ($a0)
.L7F0C1414:
/* 0F5F44 7F0C1414 3C0F8009 */  lui   $t7, %hi(music_slot_seconds_0)
/* 0F5F48 7F0C1418 25EFC628 */  addiu $t7, %lo(music_slot_seconds_0) # addiu $t7, $t7, -0x39d8
/* 0F5F4C 7F0C141C 0046082A */  slt   $at, $v0, $a2
/* 0F5F50 7F0C1420 14200004 */  bnez  $at, .L7F0C1434
/* 0F5F54 7F0C1424 010F1821 */   addu  $v1, $t0, $t7
/* 0F5F58 7F0C1428 0046C023 */  subu  $t8, $v0, $a2
/* 0F5F5C 7F0C142C 10000002 */  b     .L7F0C1438
/* 0F5F60 7F0C1430 AC980000 */   sw    $t8, ($a0)
.L7F0C1434:
/* 0F5F64 7F0C1434 AC800000 */  sw    $zero, ($a0)
.L7F0C1438:
/* 0F5F68 7F0C1438 8C620000 */  lw    $v0, ($v1)
/* 0F5F6C 7F0C143C 10400011 */  beqz  $v0, .L7F0C1484
/* 0F5F70 7F0C1440 0046082A */   slt   $at, $v0, $a2
/* 0F5F74 7F0C1444 14200003 */  bnez  $at, .L7F0C1454
/* 0F5F78 7F0C1448 0046C823 */   subu  $t9, $v0, $a2
/* 0F5F7C 7F0C144C 10000002 */  b     .L7F0C1458
/* 0F5F80 7F0C1450 AC790000 */   sw    $t9, ($v1)
.L7F0C1454:
/* 0F5F84 7F0C1454 AC600000 */  sw    $zero, ($v1)
.L7F0C1458:
/* 0F5F88 7F0C1458 8C6B0000 */  lw    $t3, ($v1)
/* 0F5F8C 7F0C145C 51600009 */  beql  $t3, $zero, .L7F0C1484
/* 0F5F90 7F0C1460 ACE00000 */   sw    $zero, ($a3)
/* 0F5F94 7F0C1464 14A00004 */  bnez  $a1, .L7F0C1478
/* 0F5F98 7F0C1468 00000000 */   nop
/* 0F5F9C 7F0C146C 8C8C0000 */  lw    $t4, ($a0)
/* 0F5FA0 7F0C1470 51800005 */  beql  $t4, $zero, .L7F0C1488
/* 0F5FA4 7F0C1474 24840004 */   addiu $a0, $a0, 4
.L7F0C1478:
/* 0F5FA8 7F0C1478 10000002 */  b     .L7F0C1484
/* 0F5FAC 7F0C147C 240A0001 */   li    $t2, 1
/* 0F5FB0 7F0C1480 ACE00000 */  sw    $zero, ($a3)
.L7F0C1484:
/* 0F5FB4 7F0C1484 24840004 */  addiu $a0, $a0, 4
.L7F0C1488:
/* 0F5FB8 7F0C1488 25080004 */  addiu $t0, $t0, 4
/* 0F5FBC 7F0C148C 1489FFDA */  bne   $a0, $t1, .L7F0C13F8
/* 0F5FC0 7F0C1490 24E70004 */   addiu $a3, $a3, 4
/* 0F5FC4 7F0C1494 50C00016 */  beql  $a2, $zero, .L7F0C14F0
/* 0F5FC8 7F0C1498 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F5FCC 7F0C149C 0FC3030C */  jal   get_mission_state
/* 0F5FD0 7F0C14A0 AFAA0018 */   sw    $t2, 0x18($sp)
/* 0F5FD4 7F0C14A4 24010002 */  li    $at, 2
/* 0F5FD8 7F0C14A8 10410006 */  beq   $v0, $at, .L7F0C14C4
/* 0F5FDC 7F0C14AC 8FAA0018 */   lw    $t2, 0x18($sp)
/* 0F5FE0 7F0C14B0 0FC3030C */  jal   get_mission_state
/* 0F5FE4 7F0C14B4 AFAA0018 */   sw    $t2, 0x18($sp)
/* 0F5FE8 7F0C14B8 24010005 */  li    $at, 5
/* 0F5FEC 7F0C14BC 14410007 */  bne   $v0, $at, .L7F0C14DC
/* 0F5FF0 7F0C14C0 8FAA0018 */   lw    $t2, 0x18($sp)
.L7F0C14C4:
/* 0F5FF4 7F0C14C4 5540000A */  bnezl $t2, .L7F0C14F0
/* 0F5FF8 7F0C14C8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F5FFC 7F0C14CC 0FC304B3 */  jal   sub_GAME_7F0C12CC
/* 0F6000 7F0C14D0 00000000 */   nop
/* 0F6004 7F0C14D4 10000006 */  b     .L7F0C14F0
/* 0F6008 7F0C14D8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C14DC:
/* 0F600C 7F0C14DC 51400004 */  beql  $t2, $zero, .L7F0C14F0
/* 0F6010 7F0C14E0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6014 7F0C14E4 0FC304A2 */  jal   sub_GAME_7F0C1288
/* 0F6018 7F0C14E8 00000000 */   nop
/* 0F601C 7F0C14EC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C14F0:
/* 0F6020 7F0C14F0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F6024 7F0C14F4 03E00008 */  jr    $ra
/* 0F6028 7F0C14F8 00000000 */   nop
)
#endif






void musicPlaySlot(s32 slot, s32 min, s32 sec)
{
#ifdef DEBUG
    osSyncPrintf("ai_ifmusicqueueemptyjumpf : %s, State=%x (getlvleveltime60=%f)\n", MUSIC_TRACK_ToString[slot], (&music_slot_active_0)[slot], getlvleveltime60);
#endif
    if ((&music_slot_active_0)[slot] == FALSE)
    {
        (&music_slot_active_0)[slot] = TRUE;
        (&music_slot_minutes_0)[slot] = min * MP_MUSIC_FRAMERATE;
        (&music_slot_seconds_0)[slot] = sec * MP_MUSIC_FRAMERATE;
    }
}

void musicStopSlot(s32 slot)
{
    if (-1 < slot)
    {
        (&music_slot_active_0)[slot] = 0;
        return;
    }
    music_slot_active_0  = 0;
    music_slot_minutes_0 = 0;
    music_slot_seconds_0 = 0;
    music_slot_active_1  = 0;
    music_slot_minutes_1 = 0;
    music_slot_seconds_1 = 0;
    music_slot_active_2  = 0;
    music_slot_minutes_2 = 0;
    music_slot_seconds_2 = 0;
    music_slot_active_3  = 0;
    music_slot_minutes_3 = 0;
    music_slot_seconds_3 = 0;
}

