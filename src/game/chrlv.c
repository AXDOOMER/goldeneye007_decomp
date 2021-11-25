#include "ultra64.h"
#include "bondaicommands.h"
#include "bondgame.h"
#include "bondconstants.h"
#include "chrlv.h"
#include "include/math.h"
#include "music.h"
#include "random.h"
#include "game/bg.h"
#include "game/bondview.h"
#include "game/chr.h"
#include "game/chrai.h"
#include "game/chrobjhandler.h"
#include "game/file.h"
#include "game/fog.h"
#include "game/front.h"
#include "game/gun.h"
#include "game/initanitable.h"
#include "game/lvl.h"
#include "game/math_asinfacosf.h"
#include "game/math_atan2f.h"
#include "game/objecthandler.h"
#include "game/player.h"
#include "game/player_2.h"
#include "game/stan.h"
#include "game/unk_08DBB0.h"

// forward declarations

u32 check_if_item_held_like_pistol(struct PropRecord *arg0);
void chrlvIdleAnimationRelated(struct ChrRecord *arg0, f32 arg1);
f32 chrlvGetGuard007SpeedRating(struct ChrRecord *arg0, f32 min, f32 max);
s32 chrlvGetGuard007SpeedRatingInt(struct ChrRecord *arg0, s32 arg1);
f32 chrlvGetGuard007ArghRating(struct ChrRecord *arg0, f32 min, f32 max);
void chrlvKneelingAnimationRelated(struct ChrRecord *arg0);
void chrlvIdleAnimationRelated7F023E14(struct ChrRecord *arg0, f32 arg1);
void chrlvKneelingAnimationRelated7F023E48(struct ChrRecord *arg0);
void chrlvActorKneel(struct ChrRecord *arg0);
void chrlvPerformAnimationForActor(struct ChrRecord *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5);
void chrlvExtendLeftHandAnimationRelated(struct ChrRecord *arg0);
void chrlvThrowGrenadeAnimationRelated(struct ChrRecord *arg0, s32 arg1, s32 arg2, s32 arg3);
void chrlvSpotBondAnimationRelated(struct ChrRecord *arg0, f32 arg1);
void chrlvActorShuffleFeet(struct ChrRecord *arg0);
void chrlvSurrenderAnimationRelated(struct ChrRecord *arg0);
void chrlvActorLookFlustered(struct ChrRecord *arg0);
void chrlvActorThrowWeaponSurrender(struct ChrRecord *arg0);
void chrlvActorFadeAway(struct ChrRecord *arg0);
void chrlvSideStepAnimationRelated(struct ChrRecord *arg0, s32 arg1);
void chrlvFireJumpToSideAnimationRelated(struct ChrRecord *arg0, s32 arg1);
void chrlvDeathStaggerAnimationRelated(struct ChrRecord *arg0);
void chrlvAttackActionRelated(struct ChrRecord *arg0);
f32 chrlvDistanceToChrRelated(ChrRecord *arg0, s32 arg1, s32 arg2);
f32 get_distance_actor_to_position(ChrRecord *arg0, struct coord3d *arg1);
f32 chrlvPathingCollisionRelated(PropRecord *arg0, f32 arg1, f32 arg2, s32 objFlags, f32 unkHeight, f32 unkA);
f32 chrlvPathingCollisionRelated7F0264B0(PropRecord *arg0, f32 arg1, f32 arg2);
void triggered_on_shot_hit(struct ChrRecord *arg0, struct coord3d *arg1, f32 arg2, s32 req_animation_id, ITEM_IDS item);
s32 chrlvAttackAnimationRelated7F026F30(struct ChrRecord *arg0, f32 *result);
s32 chrlvStanRoomRelated(ChrRecord *arg0, struct coord3d *arg1, StandTile *tile);
f32 chrlvModelScaleAnimationRelated(struct ChrRecord *arg0);
void chrlvActGoposRelated(struct ChrRecord *arg0, struct coord3d *arg1, struct StandTile **arg2);
s32 chrlvMovementTargetRelated(ChrRecord *arg0);
struct path_table_alt *get_ptrpreset_in_table_matching_tile(struct StandTile* arg0);
s32 check_if_any_path_preset_lies_on_tile(struct StandTile* arg0);
f32 chrlvPadPresetRelated(struct coord3d *arg0, struct path_table_alt *arg1);
struct path_table_alt *chrlvStanPathRelated(struct coord3d *arg0, StandTile *arg1);
s32 chrlvStanRoomRelatedPad(ChrRecord *arg0, struct pad *arg1);
void play_sound_for_shot_actor(ChrRecord *);
void sub_GAME_7F025560(ChrRecord *arg0, s32 arg1, s32 arg2);
struct coord3d *sub_GAME_7F032C78(ChrRecord *arg0, s32 arg1, s32 arg2, struct StandTile *arg3);
void sub_GAME_7F02D184(struct ChrRecord *arg0);
void sub_GAME_7F0281F4(struct ChrRecord *arg0);
s32 plot_course_for_actor(ChrRecord *arg0, struct act_gopos *arg1, struct StandTile *stan, s32 arg3);
void chrlvPlotCourseRelated(struct ChrRecord *arg0);
void chrlvActGoposSetTargetPosRelated(ChrRecord *arg0);
void chrlvActGoposIncCurIndex(struct ChrRecord *arg0);
void play_hit_soundeffect_and_proper_volume(struct ChrRecord *arg0);
void get_sound_at_range(ChrRecord *arg0, s32 arg1, s32 arg2);
void chrlvSetGoposSegDistTotal(struct ChrRecord *arg0, struct waydata *arg1, struct coord3d *arg2);
s32 sub_GAME_7F02B800(ChrRecord *, s32);
s32 chrlvCall7F02982C(PropRecord *arg0, struct coord3d *arg1, f32 arg2);
void chrlvSurrenderAnimationRelated7F02B638(struct ChrRecord *arg0);
void chrlvWalkingAnimationRelated(ChrRecord *arg0);
void setSeenBondTimeToNow(struct ChrRecord *guardData);
s32 chrlvAttackRelated7F0292A8(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2);
s32 chrlvMaybeSameRoom(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2);
s32 chrlvCurrentPlayerCall7F0B0E24(ChrRecord *arg0);
s32 chrlvCall7F0B0E24WithChrWidthHeight(PropRecord *arg0, struct coord3d *arg1, struct coord3d *arg2);
void chrlvSetTargetToPlayer(ChrRecord *arg0);
s32 sub_GAME_7F032B68(ChrRecord *);
s32 sub_GAME_7F029D70(ChrRecord *self);
void chrlvNormDistanceToPlayer(ChrRecord *arg0, s32 arg1, struct coord3d *arg2);
s32 sub_GAME_7F02A0EC(ChrRecord *arg0, s32 arg1, f32 arg2);
void chrlvModelRotyRelated(ChrRecord *arg0, s32 arg1, struct coord3d *arg2);
s32 chrIsNotDeadOrShot(struct ChrRecord *chr);

// move to chrobjecthandler.h


// end forward declarations


s32 load_body_head_if_not_loaded(s32 model)
{
    if (c_item_entries[model].header->RootNode == 0)
    {
        load_object_into_memory(c_item_entries[model].header, c_item_entries[model].filename);
        return 1;
    }
    return 0;
}




#ifdef NONMATCHING
Model * makeonebody(int body,int head,ModelFileHeader *bodyheader,ModelFileHeader *headheader, int sunglasses,Model *model)
{
  //uint cheatcheck;
  undefined4 *id;
  float pov;
  ModelNode *node;
  float scale;
  
  pov = c_item_entries[body].pov;
  scale = c_item_entries[body].scale * 0.1;
  node = 0x0;
  if (cheatCheckIfOn(CHEAT_DKMODE) != 0) {
    scale = scale * 0.8;
  }
  if (bodyheader->RootNode == 0x0) {
    load_object_into_memory(bodyheader,c_item_entries[body].name);
  }
  set_objuse_flag_compute_grp_nums_set_obj_loaded(bodyheader);
  if (((c_item_entries[body].HasHead == '\0') && (-1 < head)) &&
     (node = bodyheader->Switches[4], node != 0x0)) {
    if (headheader->RootNode == 0x0) {
      load_object_into_memory(headheader,c_item_entries[head].name);
      //sprintf("makeonebody: no head attachment for body number %d!\n",lVar3);
    }
    set_objuse_flag_compute_grp_nums_set_obj_loaded(headheader);
    bodyheader->numRecords = bodyheader->numRecords + headheader->numRecords;
  }
  if (model == 0x0) {
    model = get_aircraft_obj_instance_controller(bodyheader);
  }
  //
  //        if (*&pMStack0000003c->field_0x2 < pMStack00000024->numRecords) {
  //        assertPrint_8291E690
  //                  (".\\ported\\chrlv.cpp",0xc4,
  //                   "Assertion failed: chrsub->inst.savesize>=bodyobj->savesize");
  //        }
  //
  //
  if (model != 0x0) {
    set_obj_instance_controller_scale(model,scale);
    proc_7F06CE84(model,pov);
    if ((headheader != 0x0) && (c_item_entries[body].HasHead == '\0')) {
      bodyheader->numRecords = bodyheader->numRecords - headheader->numRecords;
      proc_7F06C3B4(model,node,headheader);
      if ((sunglasses == 0) && ((0 < headheader->numSwitches && (*headheader->Switches != 0x0)))) {
        id = extract_id_from_object_structure_microcode(model,*headheader->Switches);
        *id = 0;
      }
    }
  }
  return model;
}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80051D90
.word 0x3dccccce /*0.10000001*/
glabel D_80051D94
.word 0x3f4ccccd /*0.80000001*/
glabel D_80051D98
.word 0x0
glabel D_80051D9C
.word 0x0
.text
glabel makeonebody
/* 057E18 7F0232E8 00047880 */  sll   $t7, $a0, 2
/* 057E1C 7F0232EC 01E47821 */  addu  $t7, $t7, $a0
/* 057E20 7F0232F0 3C188004 */  lui   $t8, %hi(c_item_entries) 
/* 057E24 7F0232F4 2718DE10 */  addiu $t8, %lo(c_item_entries) # addiu $t8, $t8, -0x21f0
/* 057E28 7F0232F8 000F7880 */  sll   $t7, $t7, 2
/* 057E2C 7F0232FC 01F81021 */  addu  $v0, $t7, $t8
/* 057E30 7F023300 3C018005 */  lui   $at, %hi(D_80051D90)
/* 057E34 7F023304 C4261D90 */  lwc1  $f6, %lo(D_80051D90)($at)
/* 057E38 7F023308 C4440008 */  lwc1  $f4, 8($v0)
/* 057E3C 7F02330C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 057E40 7F023310 C44A000C */  lwc1  $f10, 0xc($v0)
/* 057E44 7F023314 46062202 */  mul.s $f8, $f4, $f6
/* 057E48 7F023318 AFBF001C */  sw    $ra, 0x1c($sp)
/* 057E4C 7F02331C AFB10018 */  sw    $s1, 0x18($sp)
/* 057E50 7F023320 AFB00014 */  sw    $s0, 0x14($sp)
/* 057E54 7F023324 AFA40038 */  sw    $a0, 0x38($sp)
/* 057E58 7F023328 00C08025 */  move  $s0, $a2
/* 057E5C 7F02332C 00E08825 */  move  $s1, $a3
/* 057E60 7F023330 AFA5003C */  sw    $a1, 0x3c($sp)
/* 057E64 7F023334 E7A80034 */  swc1  $f8, 0x34($sp)
/* 057E68 7F023338 AFA0002C */  sw    $zero, 0x2c($sp)
/* 057E6C 7F02333C 2404000C */  li    $a0, 12
/* 057E70 7F023340 AFA20024 */  sw    $v0, 0x24($sp)
/* 057E74 7F023344 0FC249EF */  jal   cheatCheckIfOn
/* 057E78 7F023348 E7AA0030 */   swc1  $f10, 0x30($sp)
/* 057E7C 7F02334C 10400005 */  beqz  $v0, .L7F023364
/* 057E80 7F023350 C7B00034 */   lwc1  $f16, 0x34($sp)
/* 057E84 7F023354 3C018005 */  lui   $at, %hi(D_80051D94)
/* 057E88 7F023358 C4321D94 */  lwc1  $f18, %lo(D_80051D94)($at)
/* 057E8C 7F02335C 46128102 */  mul.s $f4, $f16, $f18
/* 057E90 7F023360 E7A40034 */  swc1  $f4, 0x34($sp)
.L7F023364:
/* 057E94 7F023364 8E190000 */  lw    $t9, ($s0)
/* 057E98 7F023368 8FA80024 */  lw    $t0, 0x24($sp)
/* 057E9C 7F02336C 17200003 */  bnez  $t9, .L7F02337C
/* 057EA0 7F023370 02002025 */   move  $a0, $s0
/* 057EA4 7F023374 0FC1D953 */  jal   load_object_into_memory
/* 057EA8 7F023378 8D050004 */   lw    $a1, 4($t0)
.L7F02337C:
/* 057EAC 7F02337C 0FC1D73D */  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
/* 057EB0 7F023380 02002025 */   move  $a0, $s0
/* 057EB4 7F023384 8FA90024 */  lw    $t1, 0x24($sp)
/* 057EB8 7F023388 8FA2003C */  lw    $v0, 0x3c($sp)
/* 057EBC 7F02338C 912A0011 */  lbu   $t2, 0x11($t1)
/* 057EC0 7F023390 55400018 */  bnezl $t2, .L7F0233F4
/* 057EC4 7F023394 8FA9004C */   lw    $t1, 0x4c($sp)
/* 057EC8 7F023398 04420016 */  bltzl $v0, .L7F0233F4
/* 057ECC 7F02339C 8FA9004C */   lw    $t1, 0x4c($sp)
/* 057ED0 7F0233A0 8E0B0008 */  lw    $t3, 8($s0)
/* 057ED4 7F0233A4 8D6C0010 */  lw    $t4, 0x10($t3)
/* 057ED8 7F0233A8 11800011 */  beqz  $t4, .L7F0233F0
/* 057EDC 7F0233AC AFAC002C */   sw    $t4, 0x2c($sp)
/* 057EE0 7F0233B0 8E2E0000 */  lw    $t6, ($s1)
/* 057EE4 7F0233B4 00027880 */  sll   $t7, $v0, 2
/* 057EE8 7F0233B8 01E27821 */  addu  $t7, $t7, $v0
/* 057EEC 7F0233BC 15C00006 */  bnez  $t6, .L7F0233D8
/* 057EF0 7F0233C0 02202025 */   move  $a0, $s1
/* 057EF4 7F0233C4 000F7880 */  sll   $t7, $t7, 2
/* 057EF8 7F0233C8 3C058004 */  lui   $a1, %hi(c_item_entries+4)
/* 057EFC 7F0233CC 00AF2821 */  addu  $a1, $a1, $t7
/* 057F00 7F0233D0 0FC1D953 */  jal   load_object_into_memory
/* 057F04 7F0233D4 8CA5DE14 */   lw    $a1, %lo(c_item_entries+4)($a1)
.L7F0233D8:
/* 057F08 7F0233D8 0FC1D73D */  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
/* 057F0C 7F0233DC 02202025 */   move  $a0, $s1
/* 057F10 7F0233E0 86180014 */  lh    $t8, 0x14($s0)
/* 057F14 7F0233E4 86390014 */  lh    $t9, 0x14($s1)
/* 057F18 7F0233E8 03194021 */  addu  $t0, $t8, $t9
/* 057F1C 7F0233EC A6080014 */  sh    $t0, 0x14($s0)
.L7F0233F0:
/* 057F20 7F0233F0 8FA9004C */  lw    $t1, 0x4c($sp)
.L7F0233F4:
/* 057F24 7F0233F4 55200005 */  bnezl $t1, .L7F02340C
/* 057F28 7F0233F8 8FAA004C */   lw    $t2, 0x4c($sp)
/* 057F2C 7F0233FC 0FC1B08F */  jal   get_aircraft_obj_instance_controller
/* 057F30 7F023400 02002025 */   move  $a0, $s0
/* 057F34 7F023404 AFA2004C */  sw    $v0, 0x4c($sp)
/* 057F38 7F023408 8FAA004C */  lw    $t2, 0x4c($sp)
.L7F02340C:
/* 057F3C 7F02340C 11400020 */  beqz  $t2, .L7F023490
/* 057F40 7F023410 01402025 */   move  $a0, $t2
/* 057F44 7F023414 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 057F48 7F023418 8FA50034 */   lw    $a1, 0x34($sp)
/* 057F4C 7F02341C 8FA4004C */  lw    $a0, 0x4c($sp)
/* 057F50 7F023420 0FC1B3A1 */  jal   sub_GAME_7F06CE84
/* 057F54 7F023424 8FA50030 */   lw    $a1, 0x30($sp)
/* 057F58 7F023428 12200019 */  beqz  $s1, .L7F023490
/* 057F5C 7F02342C 8FAB0024 */   lw    $t3, 0x24($sp)
/* 057F60 7F023430 916C0011 */  lbu   $t4, 0x11($t3)
/* 057F64 7F023434 55800017 */  bnezl $t4, .L7F023494
/* 057F68 7F023438 8FBF001C */   lw    $ra, 0x1c($sp)
/* 057F6C 7F02343C 860D0014 */  lh    $t5, 0x14($s0)
/* 057F70 7F023440 862E0014 */  lh    $t6, 0x14($s1)
/* 057F74 7F023444 02203025 */  move  $a2, $s1
/* 057F78 7F023448 01AE7823 */  subu  $t7, $t5, $t6
/* 057F7C 7F02344C A60F0014 */  sh    $t7, 0x14($s0)
/* 057F80 7F023450 8FA5002C */  lw    $a1, 0x2c($sp)
/* 057F84 7F023454 0FC1B0ED */  jal   sub_GAME_7F06C3B4
/* 057F88 7F023458 8FA4004C */   lw    $a0, 0x4c($sp)
/* 057F8C 7F02345C 8FB80048 */  lw    $t8, 0x48($sp)
/* 057F90 7F023460 5700000C */  bnezl $t8, .L7F023494
/* 057F94 7F023464 8FBF001C */   lw    $ra, 0x1c($sp)
/* 057F98 7F023468 8639000C */  lh    $t9, 0xc($s1)
/* 057F9C 7F02346C 5B200009 */  blezl $t9, .L7F023494
/* 057FA0 7F023470 8FBF001C */   lw    $ra, 0x1c($sp)
/* 057FA4 7F023474 8E280008 */  lw    $t0, 8($s1)
/* 057FA8 7F023478 8D050000 */  lw    $a1, ($t0)
/* 057FAC 7F02347C 50A00005 */  beql  $a1, $zero, .L7F023494
/* 057FB0 7F023480 8FBF001C */   lw    $ra, 0x1c($sp)
/* 057FB4 7F023484 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 057FB8 7F023488 8FA4004C */   lw    $a0, 0x4c($sp)
/* 057FBC 7F02348C AC400000 */  sw    $zero, ($v0)
.L7F023490:
/* 057FC0 7F023490 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F023494:
/* 057FC4 7F023494 8FA2004C */  lw    $v0, 0x4c($sp)
/* 057FC8 7F023498 8FB00014 */  lw    $s0, 0x14($sp)
/* 057FCC 7F02349C 8FB10018 */  lw    $s1, 0x18($sp)
/* 057FD0 7F0234A0 03E00008 */  jr    $ra
/* 057FD4 7F0234A4 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

#ifndef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80051D90
.word 0x3dccccce /*0.10000001*/
glabel D_80051D94
.word 0x3f4ccccd /*0.80000001*/
glabel D_80051D98
.word 0x0
glabel D_80051D9C
.word 0x0
.text
glabel makeonebody
/* 058148 7F0235D8 00047880 */  sll   $t7, $a0, 2
/* 05814C 7F0235DC 01E47821 */  addu  $t7, $t7, $a0
/* 058150 7F0235E0 3C188004 */  lui   $t8, %hi(c_item_entries) # $t8, 0x8004
/* 058154 7F0235E4 2718DE40 */  addiu $t8, %lo(c_item_entries) # addiu $t8, $t8, -0x21c0
/* 058158 7F0235E8 000F7880 */  sll   $t7, $t7, 2
/* 05815C 7F0235EC 01F81021 */  addu  $v0, $t7, $t8
/* 058160 7F0235F0 3C018005 */  lui   $at, %hi(D_80051D90) # $at, 0x8005
/* 058164 7F0235F4 C4261DC0 */  lwc1  $f6, %lo(D_80051D90)($at)
/* 058168 7F0235F8 C4440008 */  lwc1  $f4, 8($v0)
/* 05816C 7F0235FC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 058170 7F023600 C44A000C */  lwc1  $f10, 0xc($v0)
/* 058174 7F023604 46062202 */  mul.s $f8, $f4, $f6
/* 058178 7F023608 AFBF001C */  sw    $ra, 0x1c($sp)
/* 05817C 7F02360C AFB10018 */  sw    $s1, 0x18($sp)
/* 058180 7F023610 AFB00014 */  sw    $s0, 0x14($sp)
/* 058184 7F023614 AFA40038 */  sw    $a0, 0x38($sp)
/* 058188 7F023618 00C08025 */  move  $s0, $a2
/* 05818C 7F02361C 00E08825 */  move  $s1, $a3
/* 058190 7F023620 AFA5003C */  sw    $a1, 0x3c($sp)
/* 058194 7F023624 E7A80034 */  swc1  $f8, 0x34($sp)
/* 058198 7F023628 AFA0002C */  sw    $zero, 0x2c($sp)
/* 05819C 7F02362C 2404000C */  li    $a0, 12
/* 0581A0 7F023630 AFA20024 */  sw    $v0, 0x24($sp)
/* 0581A4 7F023634 0FC24CCF */  jal   cheatCheckIfOn
/* 0581A8 7F023638 E7AA0030 */   swc1  $f10, 0x30($sp)
/* 0581AC 7F02363C 10400009 */  beqz  $v0, .Ljp7F023664
/* 0581B0 7F023640 8FA40038 */   lw    $a0, 0x38($sp)
/* 0581B4 7F023644 0FC0827B */  jal   not_in_us_7F0209EC
/* 0581B8 7F023648 8FA5003C */   lw    $a1, 0x3c($sp)
/* 0581BC 7F02364C 10400005 */  beqz  $v0, .Ljp7F023664
/* 0581C0 7F023650 C7B00034 */   lwc1  $f16, 0x34($sp)
/* 0581C4 7F023654 3C018005 */  lui   $at, %hi(D_80051D94) # $at, 0x8005
/* 0581C8 7F023658 C4321DC4 */  lwc1  $f18, %lo(D_80051D94)($at)
/* 0581CC 7F02365C 46128102 */  mul.s $f4, $f16, $f18
/* 0581D0 7F023660 E7A40034 */  swc1  $f4, 0x34($sp)
.Ljp7F023664:
/* 0581D4 7F023664 8E190000 */  lw    $t9, ($s0)
/* 0581D8 7F023668 8FA80024 */  lw    $t0, 0x24($sp)
/* 0581DC 7F02366C 17200003 */  bnez  $t9, .Ljp7F02367C
/* 0581E0 7F023670 02002025 */   move  $a0, $s0
/* 0581E4 7F023674 0FC1DACF */  jal   load_object_into_memory
/* 0581E8 7F023678 8D050004 */   lw    $a1, 4($t0)
.Ljp7F02367C:
/* 0581EC 7F02367C 0FC1D8B9 */  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
/* 0581F0 7F023680 02002025 */   move  $a0, $s0
/* 0581F4 7F023684 8FA90024 */  lw    $t1, 0x24($sp)
/* 0581F8 7F023688 8FAB003C */  lw    $t3, 0x3c($sp)
/* 0581FC 7F02368C 912A0011 */  lbu   $t2, 0x11($t1)
/* 058200 7F023690 55400018 */  bnezl $t2, .Ljp7F0236F4
/* 058204 7F023694 8FAA004C */   lw    $t2, 0x4c($sp)
/* 058208 7F023698 05620016 */  bltzl $t3, .Ljp7F0236F4
/* 05820C 7F02369C 8FAA004C */   lw    $t2, 0x4c($sp)
/* 058210 7F0236A0 8E0C0008 */  lw    $t4, 8($s0)
/* 058214 7F0236A4 8D8D0010 */  lw    $t5, 0x10($t4)
/* 058218 7F0236A8 11A00011 */  beqz  $t5, .Ljp7F0236F0
/* 05821C 7F0236AC AFAD002C */   sw    $t5, 0x2c($sp)
/* 058220 7F0236B0 8E2F0000 */  lw    $t7, ($s1)
/* 058224 7F0236B4 000BC080 */  sll   $t8, $t3, 2
/* 058228 7F0236B8 030BC021 */  addu  $t8, $t8, $t3
/* 05822C 7F0236BC 15E00006 */  bnez  $t7, .Ljp7F0236D8
/* 058230 7F0236C0 02202025 */   move  $a0, $s1
/* 058234 7F0236C4 0018C080 */  sll   $t8, $t8, 2
/* 058238 7F0236C8 3C058004 */  lui   $a1, %hi(c_item_entries+4)
/* 05823C 7F0236CC 00B82821 */  addu  $a1, $a1, $t8
/* 058240 7F0236D0 0FC1DACF */  jal   load_object_into_memory
/* 058244 7F0236D4 8CA5DE44 */   lw    $a1, %lo(c_item_entries+4)($a1)
.Ljp7F0236D8:
/* 058248 7F0236D8 0FC1D8B9 */  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
/* 05824C 7F0236DC 02202025 */   move  $a0, $s1
/* 058250 7F0236E0 86190014 */  lh    $t9, 0x14($s0)
/* 058254 7F0236E4 86280014 */  lh    $t0, 0x14($s1)
/* 058258 7F0236E8 03284821 */  addu  $t1, $t9, $t0
/* 05825C 7F0236EC A6090014 */  sh    $t1, 0x14($s0)
.Ljp7F0236F0:
/* 058260 7F0236F0 8FAA004C */  lw    $t2, 0x4c($sp)
.Ljp7F0236F4:
/* 058264 7F0236F4 55400005 */  bnezl $t2, .Ljp7F02370C
/* 058268 7F0236F8 8FAC004C */   lw    $t4, 0x4c($sp)
/* 05826C 7F0236FC 0FC1B20B */  jal   get_aircraft_obj_instance_controller
/* 058270 7F023700 02002025 */   move  $a0, $s0
/* 058274 7F023704 AFA2004C */  sw    $v0, 0x4c($sp)
/* 058278 7F023708 8FAC004C */  lw    $t4, 0x4c($sp)
.Ljp7F02370C:
/* 05827C 7F02370C 11800020 */  beqz  $t4, .Ljp7F023790
/* 058280 7F023710 01802025 */   move  $a0, $t4
/* 058284 7F023714 0FC1B51A */  jal   set_obj_instance_controller_scale
/* 058288 7F023718 8FA50034 */   lw    $a1, 0x34($sp)
/* 05828C 7F02371C 8FA4004C */  lw    $a0, 0x4c($sp)
/* 058290 7F023720 0FC1B51D */  jal   sub_GAME_7F06CE84
/* 058294 7F023724 8FA50030 */   lw    $a1, 0x30($sp)
/* 058298 7F023728 12200019 */  beqz  $s1, .Ljp7F023790
/* 05829C 7F02372C 8FAD0024 */   lw    $t5, 0x24($sp)
/* 0582A0 7F023730 91AE0011 */  lbu   $t6, 0x11($t5)
/* 0582A4 7F023734 55C00017 */  bnezl $t6, .Ljp7F023794
/* 0582A8 7F023738 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0582AC 7F02373C 860F0014 */  lh    $t7, 0x14($s0)
/* 0582B0 7F023740 862B0014 */  lh    $t3, 0x14($s1)
/* 0582B4 7F023744 02203025 */  move  $a2, $s1
/* 0582B8 7F023748 01EBC023 */  subu  $t8, $t7, $t3
/* 0582BC 7F02374C A6180014 */  sh    $t8, 0x14($s0)
/* 0582C0 7F023750 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0582C4 7F023754 0FC1B269 */  jal   sub_GAME_7F06C3B4
/* 0582C8 7F023758 8FA4004C */   lw    $a0, 0x4c($sp)
/* 0582CC 7F02375C 8FB90048 */  lw    $t9, 0x48($sp)
/* 0582D0 7F023760 5720000C */  bnezl $t9, .Ljp7F023794
/* 0582D4 7F023764 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0582D8 7F023768 8628000C */  lh    $t0, 0xc($s1)
/* 0582DC 7F02376C 59000009 */  blezl $t0, .Ljp7F023794
/* 0582E0 7F023770 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0582E4 7F023774 8E290008 */  lw    $t1, 8($s1)
/* 0582E8 7F023778 8D250000 */  lw    $a1, ($t1)
/* 0582EC 7F02377C 50A00005 */  beql  $a1, $zero, .Ljp7F023794
/* 0582F0 7F023780 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0582F4 7F023784 0FC1B363 */  jal   extract_id_from_object_structure_microcode
/* 0582F8 7F023788 8FA4004C */   lw    $a0, 0x4c($sp)
/* 0582FC 7F02378C AC400000 */  sw    $zero, ($v0)
.Ljp7F023790:
/* 058300 7F023790 8FBF001C */  lw    $ra, 0x1c($sp)
.Ljp7F023794:
/* 058304 7F023794 8FA2004C */  lw    $v0, 0x4c($sp)
/* 058308 7F023798 8FB00014 */  lw    $s0, 0x14($sp)
/* 05830C 7F02379C 8FB10018 */  lw    $s1, 0x18($sp)
/* 058310 7F0237A0 03E00008 */  jr    $ra
/* 058314 7F0237A4 27BD0038 */   addiu $sp, $sp, 0x38
    
)
#endif



#endif

Model * setup_chr_instance(int body,int head,ModelFileHeader *body_header, ModelFileHeader *head_header,int sunglasses)
{
  return makeonebody(body,head,body_header,head_header,sunglasses,0x0);
}




/**
 * Address 0x7F0234D0.
 */
Model * retrieve_header_for_body_and_head(s32 body, s32 head, u32 bitflags)
{
    ModelFileHeader *body_header;
    ModelFileHeader *head_header;
    s32 sunglasses;
   
    body_header = c_item_entries[body].header;
    head_header = NULL;
    
    sunglasses = 0;

    if ((bitflags & 1))
    {
        sunglasses = 1;
    }
    else if ((bitflags & 2))
    {
        sunglasses = (randomGetNext() & 1) == 0;
    }
    
    if ((head >= 0) && (c_item_entries[body].hasHead == 0))
    {
        head_header = c_item_entries[head].header;
    }
    
    return setup_chr_instance(body, head, body_header, head_header, sunglasses);
}



s32 get_current_random_body(void)

{
  return list_of_bodies[current_random_body];
}




/**
 * Address 0x7F0235AC.
 */
s32 select_psuedorandom_heads(s32 id)
{
    s32 ret;

    if (c_item_entries[id].isMale)
    {
        ret = randomGetNext() & 3;
        ret = ((s32)current_random_male_head + ret) % (s32)num_male_heads;
        ret = random_male_heads[ret];
    }
    else
    {
        ret = random_female_heads[current_random_female_head];
    }

    return ret;
}



s32 get_random_head(s32 id)
{
    return (c_item_entries[id].isMale ? random_male_heads[randomGetNext() % num_male_heads] : random_female_heads[randomGetNext() % num_female_heads]);
}



#ifdef NONMATCHING
void expand_09_characters(void) {

}
#else
GLOBAL_ASM(
.text
glabel expand_09_characters
/* 05823C 7F02370C 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 058240 7F023710 AFBF0024 */  sw    $ra, 0x24($sp)
/* 058244 7F023714 AFB00020 */  sw    $s0, 0x20($sp)
/* 058248 7F023718 AFA40060 */  sw    $a0, 0x60($sp)
/* 05824C 7F02371C AFA60068 */  sw    $a2, 0x68($sp)
/* 058250 7F023720 94AE0006 */  lhu   $t6, 6($a1)
/* 058254 7F023724 3C188007 */  lui   $t8, %hi(ptr_0xxxpresets) 
/* 058258 7F023728 8F185D18 */  lw    $t8, %lo(ptr_0xxxpresets)($t8)
/* 05825C 7F02372C 000E7880 */  sll   $t7, $t6, 2
/* 058260 7F023730 01EE7823 */  subu  $t7, $t7, $t6
/* 058264 7F023734 000F7880 */  sll   $t7, $t7, 2
/* 058268 7F023738 01EE7823 */  subu  $t7, $t7, $t6
/* 05826C 7F02373C 000F7880 */  sll   $t7, $t7, 2
/* 058270 7F023740 00A08025 */  move  $s0, $a1
/* 058274 7F023744 01F82021 */  addu  $a0, $t7, $t8
/* 058278 7F023748 8C850028 */  lw    $a1, 0x28($a0)
/* 05827C 7F02374C 27B90054 */  addiu $t9, $sp, 0x54
/* 058280 7F023750 AFB90010 */  sw    $t9, 0x10($sp)
/* 058284 7F023754 AFA4005C */  sw    $a0, 0x5c($sp)
/* 058288 7F023758 3C0641A0 */  lui   $a2, 0x41a0
/* 05828C 7F02375C 0FC15A14 */  jal   sub_GAME_7F056850
/* 058290 7F023760 27A70048 */   addiu $a3, $sp, 0x48
/* 058294 7F023764 10400065 */  beqz  $v0, .L7F0238FC
/* 058298 7F023768 2408FFFF */   li    $t0, -1
/* 05829C 7F02376C AFA80030 */  sw    $t0, 0x30($sp)
/* 0582A0 7F023770 96020008 */  lhu   $v0, 8($s0)
/* 0582A4 7F023774 3401FFFF */  li    $at, 65535
/* 0582A8 7F023778 54410006 */  bnel  $v0, $at, .L7F023794
/* 0582AC 7F02377C AFA20034 */   sw    $v0, 0x34($sp)
/* 0582B0 7F023780 0FC08D64 */  jal   get_current_random_body
/* 0582B4 7F023784 00000000 */   nop   
/* 0582B8 7F023788 10000002 */  b     .L7F023794
/* 0582BC 7F02378C AFA20034 */   sw    $v0, 0x34($sp)
/* 0582C0 7F023790 AFA20034 */  sw    $v0, 0x34($sp)
.L7F023794:
/* 0582C4 7F023794 8FA90034 */  lw    $t1, 0x34($sp)
/* 0582C8 7F023798 3C0B8004 */  lui   $t3, %hi(c_item_entries+17)
/* 0582CC 7F02379C 00095080 */  sll   $t2, $t1, 2
/* 0582D0 7F0237A0 01495021 */  addu  $t2, $t2, $t1
/* 0582D4 7F0237A4 000A5080 */  sll   $t2, $t2, 2
/* 0582D8 7F0237A8 016A5821 */  addu  $t3, $t3, $t2
/* 0582DC 7F0237AC 916BDE21 */  lbu   $t3, %lo(c_item_entries+17)($t3)
/* 0582E0 7F0237B0 5560000A */  bnezl $t3, .L7F0237DC
/* 0582E4 7F0237B4 8FA40034 */   lw    $a0, 0x34($sp)
/* 0582E8 7F0237B8 86020016 */  lh    $v0, 0x16($s0)
/* 0582EC 7F0237BC 04400003 */  bltz  $v0, .L7F0237CC
/* 0582F0 7F0237C0 00000000 */   nop   
/* 0582F4 7F0237C4 10000004 */  b     .L7F0237D8
/* 0582F8 7F0237C8 AFA20030 */   sw    $v0, 0x30($sp)
.L7F0237CC:
/* 0582FC 7F0237CC 0FC08D6B */  jal   select_psuedorandom_heads
/* 058300 7F0237D0 8FA40034 */   lw    $a0, 0x34($sp)
/* 058304 7F0237D4 AFA20030 */  sw    $v0, 0x30($sp)
.L7F0237D8:
/* 058308 7F0237D8 8FA40034 */  lw    $a0, 0x34($sp)
.L7F0237DC:
/* 05830C 7F0237DC 8FA50030 */  lw    $a1, 0x30($sp)
/* 058310 7F0237E0 0FC08D34 */  jal   retrieve_header_for_body_and_head
/* 058314 7F0237E4 96060014 */   lhu   $a2, 0x14($s0)
/* 058318 7F0237E8 10400044 */  beqz  $v0, .L7F0238FC
/* 05831C 7F0237EC AFA20038 */   sw    $v0, 0x38($sp)
/* 058320 7F0237F0 8FA2005C */  lw    $v0, 0x5c($sp)
/* 058324 7F0237F4 C44C0018 */  lwc1  $f12, 0x18($v0)
/* 058328 7F0237F8 0FC16A8C */  jal   atan2f
/* 05832C 7F0237FC C44E0020 */   lwc1  $f14, 0x20($v0)
/* 058330 7F023800 E7A0003C */  swc1  $f0, 0x3c($sp)
/* 058334 7F023804 0FC0D4E6 */  jal   LoadNext_PrevActionBlock
/* 058338 7F023808 9604000A */   lhu   $a0, 0xa($s0)
/* 05833C 7F02380C 8FA40038 */  lw    $a0, 0x38($sp)
/* 058340 7F023810 27A50048 */  addiu $a1, $sp, 0x48
/* 058344 7F023814 8FA6003C */  lw    $a2, 0x3c($sp)
/* 058348 7F023818 8FA70054 */  lw    $a3, 0x54($sp)
/* 05834C 7F02381C 0FC080EE */  jal   replace_GUARDdata_with_actual_values
/* 058350 7F023820 AFA20010 */   sw    $v0, 0x10($sp)
/* 058354 7F023824 10400035 */  beqz  $v0, .L7F0238FC
/* 058358 7F023828 00402025 */   move  $a0, $v0
/* 05835C 7F02382C 0FC0E929 */  jal   set_current_objposdata_plus_0x28
/* 058360 7F023830 AFA20044 */   sw    $v0, 0x44($sp)
/* 058364 7F023834 0FC0E901 */  jal   set_stateflag_0x04_for_posdata
/* 058368 7F023838 8FA40044 */   lw    $a0, 0x44($sp)
/* 05836C 7F02383C 8FAC0044 */  lw    $t4, 0x44($sp)
/* 058370 7F023840 960D0004 */  lhu   $t5, 4($s0)
/* 058374 7F023844 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 058378 7F023848 8D820004 */  lw    $v0, 4($t4)
/* 05837C 7F02384C A44D0000 */  sh    $t5, ($v0)
/* 058380 7F023850 960E0010 */  lhu   $t6, 0x10($s0)
/* 058384 7F023854 448E2000 */  mtc1  $t6, $f4
/* 058388 7F023858 05C10004 */  bgez  $t6, .L7F02386C
/* 05838C 7F02385C 468021A0 */   cvt.s.w $f6, $f4
/* 058390 7F023860 44814000 */  mtc1  $at, $f8
/* 058394 7F023864 00000000 */  nop   
/* 058398 7F023868 46083180 */  add.s $f6, $f6, $f8
.L7F02386C:
/* 05839C 7F02386C 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0583A0 7F023870 44815000 */  mtc1  $at, $f10
/* 0583A4 7F023874 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0583A8 7F023878 460A3403 */  div.s $f16, $f6, $f10
/* 0583AC 7F02387C E45000EC */  swc1  $f16, 0xec($v0)
/* 0583B0 7F023880 960F0012 */  lhu   $t7, 0x12($s0)
/* 0583B4 7F023884 448F9000 */  mtc1  $t7, $f18
/* 0583B8 7F023888 05E10004 */  bgez  $t7, .L7F02389C
/* 0583BC 7F02388C 46809120 */   cvt.s.w $f4, $f18
/* 0583C0 7F023890 44814000 */  mtc1  $at, $f8
/* 0583C4 7F023894 00000000 */  nop   
/* 0583C8 7F023898 46082100 */  add.s $f4, $f4, $f8
.L7F02389C:
/* 0583CC 7F02389C E44400D0 */  swc1  $f4, 0xd0($v0)
/* 0583D0 7F0238A0 9618000C */  lhu   $t8, 0xc($s0)
/* 0583D4 7F0238A4 A4580114 */  sh    $t8, 0x114($v0)
/* 0583D8 7F0238A8 9619000E */  lhu   $t9, 0xe($s0)
/* 0583DC 7F0238AC A4590116 */  sh    $t9, 0x116($v0)
/* 0583E0 7F0238B0 8FA80030 */  lw    $t0, 0x30($sp)
/* 0583E4 7F0238B4 A0480006 */  sb    $t0, 6($v0)
/* 0583E8 7F0238B8 8FA90034 */  lw    $t1, 0x34($sp)
/* 0583EC 7F0238BC A049000F */  sb    $t1, 0xf($v0)
/* 0583F0 7F0238C0 96030014 */  lhu   $v1, 0x14($s0)
/* 0583F4 7F0238C4 306A0004 */  andi  $t2, $v1, 4
/* 0583F8 7F0238C8 51400006 */  beql  $t2, $zero, .L7F0238E4
/* 0583FC 7F0238CC 306D0008 */   andi  $t5, $v1, 8
/* 058400 7F0238D0 8C4B0014 */  lw    $t3, 0x14($v0)
/* 058404 7F0238D4 356C0002 */  ori   $t4, $t3, 2
/* 058408 7F0238D8 AC4C0014 */  sw    $t4, 0x14($v0)
/* 05840C 7F0238DC 96030014 */  lhu   $v1, 0x14($s0)
/* 058410 7F0238E0 306D0008 */  andi  $t5, $v1, 8
.L7F0238E4:
/* 058414 7F0238E4 51A00005 */  beql  $t5, $zero, .L7F0238FC
/* 058418 7F0238E8 AE020018 */   sw    $v0, 0x18($s0)
/* 05841C 7F0238EC 8C4E0014 */  lw    $t6, 0x14($v0)
/* 058420 7F0238F0 35CF0010 */  ori   $t7, $t6, 0x10
/* 058424 7F0238F4 AC4F0014 */  sw    $t7, 0x14($v0)
/* 058428 7F0238F8 AE020018 */  sw    $v0, 0x18($s0)
.L7F0238FC:
/* 05842C 7F0238FC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 058430 7F023900 8FB00020 */  lw    $s0, 0x20($sp)
/* 058434 7F023904 27BD0060 */  addiu $sp, $sp, 0x60
/* 058438 7F023908 03E00008 */  jr    $ra
/* 05843C 7F02390C 00000000 */   nop   
)
#endif



/**
 * Address 0x7F023910.
 */
u32 check_if_item_held_like_pistol(struct PropRecord *arg0)
{
    if (arg0 != NULL)
    {
        struct ChrRecord *v = (struct ChrRecord*)arg0->voidp;

        return bondwalkItemCheckBitflags(v->act_bytes.padding[84], 0x100U);
    }

    return 0U;
}



/**
 * Address 0x7F023948.
 */
void chrlvIdleAnimationRelated(struct ChrRecord *arg0, f32 arg1)
{
    struct PropRecord *left;
    struct PropRecord *right;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    if (
        ((left != NULL) && (right != NULL))
        || ((left == NULL) && (right == NULL))
        || (check_if_item_held_like_pistol(left) != 0)
        || (check_if_item_held_like_pistol(right) != 0))
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_idle_unarmed], randomGetNext() & 1, 0, 0.25f, arg1);
        sub_GAME_7F06FDCC(arg0->model, 0, 16.0f);
    }
    else if ((right != NULL) || (left != NULL))
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_idle], left != NULL, 0, 0.25f, arg1);
        sub_GAME_7F06FDCC(arg0->model, 0, 16.0f);
        sub_GAME_7F06FDE8(arg0->model, 120.0f);
    }

    return;
}



/**
 * Address 0x7F023A94 (VERSION_US).
 * Address 0x7F023D94 (other)
 */
void chrlvIdleAnimationRelated7F023A94(struct ChrRecord *arg0, f32 arg1)
{
    f32 f2;

    sub_GAME_7F02D184(arg0);
    arg0->actiontype = ACT_STAND;

    arg0->act_stand.unk02c = 0;
    arg0->act_stand.face_entitytype = 0;
    arg0->act_stand.face_entityid = 0;
    arg0->act_stand.unk038 = 0;
    arg0->act_stand.unk03c = 2;
    arg0->act_stand.unk040 = 0;
    arg0->act_stand.unk044 = (randomGetNext() % 0x78U) + 0xB4;

    f2 = arg1;

    if (arg0->model->unka4 != 1.0f)
    {
#if defined(VERSION_JP) || defined(VERSION_EU)
        f2 *= (1.0f / arg0->model->unka4);
#else
        f2 = arg1 / arg0->model->unka4;
#endif
    }

    if (f2 > 127.0f)
    {
        f2 = 127.0f;
    }

    arg0->sleep = (s8) (s32) f2;
    chrlvIdleAnimationRelated(arg0, arg1);
}


/**
 * @param arg0: guard
 * @param min: min reaction speed range
 * @param max: max reaction speed range
 * Address 0x7F023B5C.
 */
f32 chrlvGetGuard007SpeedRating(struct ChrRecord *arg0, f32 min, f32 max)
{
    f32 ret;

    ret = (f32) arg0->speedrating;
    ret = (get_007_reaction_speed() * (100.0f - ret)) + ret;
    return ((ret * (max - min)) / 100.0f) + min;
}



/**
 * @param arg0: guard
 * @param scale: scale factor
 * Address 0x7F023BC0.
 */
s32 chrlvGetGuard007SpeedRatingInt(struct ChrRecord *arg0, s32 scale)
{
    s32 ret;

    ret = (s32) arg0->speedrating;
    ret = (s32)(get_007_reaction_speed() * (f32)(100 - ret)) + ret;
    return ((100 - ret) * scale) / 100;
}




/**
 * @param arg0: guard
 * @param min: min argh speed range
 * @param max: max argh speed range
 * Address 0x7F023C54.
 */
f32 chrlvGetGuard007ArghRating(struct ChrRecord *arg0, f32 min, f32 max)
{
    f32 ret;

    ret = (f32) arg0->arghrating;
    ret = (get_007_reaction_speed() * (100.0f - ret)) + ret;
    return ((ret * (max - min)) / 100.0f) + min;
}




/**
 * Address 0x7F023CB8.
 */
void chrlvKneelingAnimationRelated(struct ChrRecord *arg0)
{
    if (arg0->actiontype == ACT_KNEEL)
    {
        sub_GAME_7F02D184(arg0);

        arg0->actiontype = ACT_STAND;
        arg0->act_stand.unk02c = 1;
        arg0->act_stand.face_entitytype = 0;
        arg0->act_stand.face_entityid = 0;
        arg0->act_stand.unk038 = 0;
        arg0->act_stand.unk03c = 2;
        arg0->act_stand.unk040 = 0;
        arg0->act_stand.unk044 = (randomGetNext() % 0x78U) + 0xB4;
        arg0->sleep = 0;

        if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ANIM_DATA_fire_kneel_forward_one_handed_weapon_slow + (s32)&ptr_animation_table->data)
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, (s32)&ANIM_DATA_fire_kneel_forward_one_handed_weapon_slow + (s32)&ptr_animation_table->data, (s32) arg0->model->unk24, 109.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
            sub_GAME_7F06FDE8(arg0->model, 140.0f);
        }
        else
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_kneel_left_leg], (s32) arg0->model->unk24, 120.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
            sub_GAME_7F06FDE8(arg0->model, 151.0f);
        }

        return;
    }

    chrlvIdleAnimationRelated7F023A94(arg0, 16.0f);
}



/**
 * Address 0x7F023E14.
 */
void chrlvIdleAnimationRelated7F023E14(struct ChrRecord *arg0, f32 arg1)
{
    chrlvIdleAnimationRelated7F023A94(arg0, arg1);
    arg0->act_stand.unk040 = 1;
}




/**
 * Address 0x7F023E48.
 */
void chrlvKneelingAnimationRelated7F023E48(struct ChrRecord *arg0)
{
    chrlvKneelingAnimationRelated(arg0);
    arg0->act_stand.unk040 = 1;
}





/**
 * Address 0x7F023E74.
 */
void chrlvActorKneel(struct ChrRecord *arg0)
{
    struct PropRecord *left;
    struct PropRecord *right;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);
    sub_GAME_7F02D184(arg0);
    
    if (((left != NULL) && (right != NULL))
        || ((left == NULL) && (right == NULL))
        || (check_if_item_held_like_pistol(left) != 0)
        || (check_if_item_held_like_pistol(right) != 0))
    {
        s32 r = randomGetNext() & 1;
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_fire_kneel_forward_one_handed_weapon_slow], r, 0.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
        sub_GAME_7F06FDE8(arg0->model, 28.0f);
    }
    else if ((right != NULL) || (left != NULL))
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_fire_kneel_left_leg], left != NULL, 0.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
        sub_GAME_7F06FDE8(arg0->model, 27.0f);
    }

    arg0->actiontype = ACT_KNEEL;
    arg0->sleep = 0;
}



/**
 * Address 0x7F023FE4.
 */
void chrlvPerformAnimationForActor(struct ChrRecord *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5)
{
    f32 farg2 = (f32)arg2;
    f32 phi_f0;

    phi_f0 = 0.5f;
    if ((arg4 & 0x80) != 0)
    {
        phi_f0 = -0.5f;
    }

    sub_GAME_7F02D184(arg0);
    objecthandlerAnimationRelated7F06FCA8(arg0->model, (void *) animation_table_ptrs1[arg1], (arg4 & 1) != 0, farg2, phi_f0, (f32)arg5);

    if (arg3 >= 0)
    {
        sub_GAME_7F06FDE8(arg0->model, (f32)arg3);
    }

    if ((arg4 & 0x20) != 0)
    {
        sub_GAME_7F06CE84(arg0->model, arg0->model->unkb8 * 4.0f);
    }

    arg0->chrflags &= 0xFDFFFFFF;
    arg0->actiontype = ACT_ANIM;

    arg0->act_anim.unk02c = (arg4 & 2) != 0;
    arg0->act_anim.unk030 = (arg4 & 4) != 0;
    arg0->act_anim.unk034 = (arg4 & 8) != 0;
    arg0->act_anim.unk038 = (arg4 & 0x10) != 0;
    arg0->act_anim.unk03c = (arg4 & 0x40) != 0;

    if (arg0->act_anim.unk038 != 0)
    {
        arg0->sleep = (s8) arg5;
    }
    else
    {
        arg0->sleep = 0;
    }
}



/**
 * Extend left hand = ACT_STARTALARM.
 * 
 * Address 0x7F024150.
 */
void chrlvExtendLeftHandAnimationRelated(struct ChrRecord *arg0)
{
    struct PropRecord *left;
    struct PropRecord *right;
    s32 phi_a2;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    phi_a2 = 0;
    if ((left != NULL) && (right == NULL))
    {
        phi_a2 = 1;
    }
    else if (((left != NULL) && (right != NULL)) || ((left == NULL) && (right == NULL)))
    {
        phi_a2 = randomGetNext() & 1;
    }

    sub_GAME_7F02D184(arg0);

    arg0->actiontype = ACT_STARTALARM;
    arg0->sleep = 0;

    objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_extending_left_hand], phi_a2, 40.0f, 1.0f, 16.0f);
    sub_GAME_7F06FDE8(arg0->model, 82.0f);
}



/**
 * Address 0x7F024238.
 */
void chrlvThrowGrenadeAnimationRelated(struct ChrRecord *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    sub_GAME_7F02D184(arg0);

    arg0->actiontype = ACT_THROWGRENADE;
    arg0->sleep = 0;

    if (arg3 != 0)
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_throw_grenade], arg2 != 0, 0.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
    }
    else
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_throw_grenade], arg2 != 0, 84.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
    }

    sub_GAME_7F06FDE8(arg0->model, 193.0f);
}




/**
 * Addres 0x7F024334.
 */
void chrlvSpotBondAnimationRelated(struct ChrRecord *arg0, f32 arg1)
{
    struct PropRecord *left;
    struct PropRecord *right;
    s32 sp2C;
    f32 objarg4;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    sp2C = 0;
    if ((left != NULL) && (right == NULL))
    {
        sp2C = 1;
    }
    else if (((left != NULL) && (right != NULL)) || ((left == NULL) && (right == NULL)))
    {
        sp2C = randomGetNext() & 1;
    }

    objarg4 = chrlvGetGuard007SpeedRating(arg0, 0.6f, 0.96000004f); // 0.96000004 is different from 0.96
    objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_spotting_bond], sp2C, 10.0f, objarg4, arg1);
    sub_GAME_7F06FDE8(arg0->model, 52.0f);
}




/**
 * Address 0x7F024418.
 */
void chrlvActorShuffleFeet(struct ChrRecord *arg0)
{
    f32 temp_f0;

    temp_f0 = sub_GAME_7F032C4C(arg0);

    if ((temp_f0 < 0.17453294f) || (temp_f0 > 6.1086526f))
    {
        chrlvSpotBondAnimationRelated(arg0, 16.0f);
        sub_GAME_7F02D184(arg0);
        arg0->actiontype = ACT_SURPRISED;
        arg0->sleep = 0;

        return;
    }

    if (check_if_actor_stationary(arg0) == 0)
    {
        chrlvKneelingAnimationRelated(arg0);
    }
}



/**
 * Address 0x7F0244AC.
 */
void chrlvSurrenderAnimationRelated(struct ChrRecord *arg0)
{
    sub_GAME_7F02D184(arg0);
    arg0->actiontype = ACT_SURPRISED;
    arg0->sleep = 0;
    objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed], randomGetNext() & 1, 0.0f, chrlvGetGuard007SpeedRating(arg0, 0.35f, 0.56f), 16.0f);
    sub_GAME_7F06FDE8(arg0->model, 7.0f);
}



/**
 * Address 0x7F024548.
 */
void chrlvActorLookFlustered(struct ChrRecord *arg0)
{
    u32 sp2C;

    sp2C = randomGetNext() % 3U;

    sub_GAME_7F02D184(arg0);

    arg0->actiontype = ACT_SURPRISED;
    arg0->sleep = 0;
    objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_look_around], randomGetNext() & 1, 17.0f, 0.6f, 16.0f);

    if (sp2C == 0)
    {
        sub_GAME_7F06FDE8(arg0->model, chrlvGetGuard007SpeedRating(arg0, 38.0f, 8.0f));
    }
    else if (sp2C == 1)
    {
        sub_GAME_7F06FDE8(arg0->model, chrlvGetGuard007SpeedRating(arg0, 66.0f, 8.0f));
    }
    else
    {
        sub_GAME_7F06FDE8(arg0->model, chrlvGetGuard007SpeedRating(arg0, 96.0f, 8.0f));
    }
}




/**
 * Address 0x7F024648.
 */
void chrlvActorThrowWeaponSurrender(struct ChrRecord *arg0)
{
    struct PropRecord *left;
    struct PropRecord *right;

    if (arg0->actiontype != ACT_SURRENDER)
    {
        left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
        right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

        sub_GAME_7F02D184(arg0);

        arg0->actiontype = ACT_SURRENDER;

        if ((right != NULL) || (left != NULL))
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed_drop_weapon], randomGetNext() & 1, 0.0f, 0.5f, 16.0f);
            sub_GAME_7F06FDCC(arg0->model, 40.0f, 16.0f);

            arg0->sleep = 0x10;

            if (left != 0)
            {
                sub_GAME_7F04BFD0(left, 2);
            }
            if (right != 0)
            {
                sub_GAME_7F04BFD0(right, 2);
            }

            arg0->hidden |= 1;
        }
        else
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed], randomGetNext() & 1, 0.0f, 0.5f, 16.0f);
            sub_GAME_7F06FDCC(arg0->model, 30.0f, 16.0f);

            arg0->sleep = 0x10;
        }

        sub_GAME_7F021B20(arg0);
    }
}



/**
 * Address 0x7F0247B8.
 */
void chrlvActorFadeAway(struct ChrRecord *arg0)
{
    if (arg0->actiontype != ACT_DEAD)
    {
        sub_GAME_7F02D184(arg0);
        arg0->actiontype = ACT_DEAD;
        arg0->act_dead.allowfade = -1;
        arg0->sleep = 0;
    }
}



/**
 * Address 0x7F024800.
 */
void chrlvSideStepAnimationRelated(struct ChrRecord *arg0, s32 arg1)
{
    struct PropRecord *left;
    struct PropRecord *right;
    s32 sp2C;
    s32 phi_v1;

    left = something_with_weaponpos_of_guarddata_hand(arg0, 1);
    right = something_with_weaponpos_of_guarddata_hand(arg0, 0);
    sp2C = 0;
    phi_v1 = 0;

    if ((left != NULL) && (right != NULL))
    {
        sp2C = randomGetNext() & 1;
        phi_v1 = randomGetNext() & 1;
    }
    else if (check_if_item_held_like_pistol(left) == 0)
    {
        if ((check_if_item_held_like_pistol(right) == 0) && ((left != NULL) || (right != NULL)))
        {
            sp2C = left != 0;
            phi_v1 = randomGetNext() & 1;
        }
    }

    sub_GAME_7F02D184(arg0);

    arg0->actiontype = ACT_SIDESTEP;
    arg0->sleep = 0;

    if (phi_v1 == 0)
    {
        if (arg1 != 0)
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_side_step_left], 0, 5.0f, chrlvGetGuard007SpeedRating(arg0, 0.55f, 0.88000005f), 16.0f);
            sub_GAME_7F06FDE8(arg0->model, 27.0f);
        }
        else
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_side_step_left], 1, 5.0f, chrlvGetGuard007SpeedRating(arg0, 0.55f, 0.88000005f), 16.0f);
            sub_GAME_7F06FDE8(arg0->model, 27.0f);
        }

        return;
    }

    if (((arg1 != 0) && (sp2C == 0)) || ((arg1 == 0) && (sp2C != 0)))
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_slide_left], sp2C, 5.0f, chrlvGetGuard007SpeedRating(arg0, 0.7f, 1.12f), 16.0f);
        sub_GAME_7F06FDE8(arg0->model, 34.0f);

    }
    else
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_slide_right], sp2C, 5.0f, chrlvGetGuard007SpeedRating(arg0, 0.7f, 1.12f), 16.0f);
        sub_GAME_7F06FDE8(arg0->model, 32.0f);
    }

    return;
}



/**
 * Address 0x7F024A84.
 */
void chrlvFireJumpToSideAnimationRelated(struct ChrRecord *arg0, s32 arg1)
{
    struct PropRecord *left;
    struct PropRecord *right;
    s32 sp2C;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, 0);

    sp2C = 0;

    if ((left != NULL) && (right == NULL))
    {
        sp2C = 1;
    }
    else if (
        ((left != NULL) && (right != NULL))
        || ((left == NULL) && (right == NULL))
        || (check_if_item_held_like_pistol(left) != 0)
        || (check_if_item_held_like_pistol(right) != 0))
    {
        sp2C = randomGetNext() & 1;
    }

    sub_GAME_7F02D184(arg0);

    arg0->actiontype = ACT_JUMPOUT;
    arg0->sleep = 0;

    if (((arg1 != 0) && (sp2C == 0)) || ((arg1 == 0) && (sp2C != 0)))
    {
        if ((randomGetNext() & 1) != 0)
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_fire_jump_to_side_left], sp2C, 5.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
            sub_GAME_7F06FDE8(arg0->model, 49.0f);
        }
        else
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_fire_jump_to_side_right], sp2C, 130.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
            sub_GAME_7F06FDE8(arg0->model, 173.0f);
        }

        return;
    }

    if ((randomGetNext() & 1) != 0)
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_fire_jump_to_side_right], sp2C, 20.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
        sub_GAME_7F06FDE8(arg0->model, 63.0f);
    }
    else
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_fire_jump_to_side_left], sp2C, 91.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
        sub_GAME_7F06FDE8(arg0->model, 136.0f);
    }

    return;
}




#ifdef NONMATCHING
/**
 * Address 0x7F024CF8.
 * 
 *  decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * notes: stack should be ordered correctly. looks like a `NULL != left` is in the wrong spot?
 */
void sub_GAME_7F024CF8(ChrRecord *arg0, struct coord3d *arg1)
{
    f32 dx;
    f32 dz;
    s32 phi_a2;
    f32 sq;
    struct PropRecord *left;
    struct PropRecord *right;
    s32 sp2C;

    dx = arg0->prop->pos.f[0] - arg1->f[0];
    dz = arg0->prop->pos.f[2] - arg1->f[2];
    sq = sqrtf((dx * dx) + (dz * dz));
    
    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    sp2C = 1;

    if (((left != NULL) && (right != NULL)) || ((left == NULL) && (right == NULL)))
    {
        sp2C = 0;
        phi_a2 = randomGetNext() & 1;
    }
    else
    {
        if ((check_if_item_held_like_pistol(left)) || (check_if_item_held_like_pistol(right)))
        {
            sp2C = 0;
        }

        phi_a2 = NULL != left;
    }

    sub_GAME_7F02D184(arg0);

    arg0->actiontype = ACT_RUNPOS;
    arg0->act_runpos.pos.f[0] = arg1->f[0];
    arg0->act_runpos.pos.f[1] = arg1->f[1];
    arg0->act_runpos.pos.f[2] = arg1->f[2];
    arg0->sleep = 0;
    arg0->act_runpos.unk040 = 0;
    arg0->act_runpos.unk038 = 30.0f;

    if (sp2C)
    {
        arg0->act_runpos.unk03c = (s32) (sq / (D_80030988 * 0.5f));
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_running], phi_a2, 0, 0.5f, 16.0f);
    }
    else
    {
        arg0->act_runpos.unk03c = (s32) (sq / (D_80030994 * 0.5f));
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon], phi_a2, 0, 0.5f, 16.0f);
    }
}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.text
glabel sub_GAME_7F024CF8
/* 059828 7F024CF8 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 05982C 7F024CFC AFBF0024 */  sw    $ra, 0x24($sp)
/* 059830 7F024D00 AFB00020 */  sw    $s0, 0x20($sp)
/* 059834 7F024D04 8C820018 */  lw    $v0, 0x18($a0)
/* 059838 7F024D08 C4A60000 */  lwc1  $f6, ($a1)
/* 05983C 7F024D0C C4AA0008 */  lwc1  $f10, 8($a1)
/* 059840 7F024D10 C4440008 */  lwc1  $f4, 8($v0)
/* 059844 7F024D14 C4480010 */  lwc1  $f8, 0x10($v0)
/* 059848 7F024D18 00808025 */  move  $s0, $a0
/* 05984C 7F024D1C 46062001 */  sub.s $f0, $f4, $f6
/* 059850 7F024D20 AFA5004C */  sw    $a1, 0x4c($sp)
/* 059854 7F024D24 460A4081 */  sub.s $f2, $f8, $f10
/* 059858 7F024D28 46000402 */  mul.s $f16, $f0, $f0
/* 05985C 7F024D2C 00000000 */  nop   
/* 059860 7F024D30 46021482 */  mul.s $f18, $f2, $f2
/* 059864 7F024D34 0C007DF8 */  jal   sqrtf
/* 059868 7F024D38 46128300 */   add.s $f12, $f16, $f18
/* 05986C 7F024D3C E7A00038 */  swc1  $f0, 0x38($sp)
/* 059870 7F024D40 02002025 */  move  $a0, $s0
/* 059874 7F024D44 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 059878 7F024D48 24050001 */   li    $a1, 1
/* 05987C 7F024D4C 02002025 */  move  $a0, $s0
/* 059880 7F024D50 00002825 */  move  $a1, $zero
/* 059884 7F024D54 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 059888 7F024D58 AFA20034 */   sw    $v0, 0x34($sp)
/* 05988C 7F024D5C 8FA70034 */  lw    $a3, 0x34($sp)
/* 059890 7F024D60 240E0001 */  li    $t6, 1
/* 059894 7F024D64 00402825 */  move  $a1, $v0
/* 059898 7F024D68 10E00003 */  beqz  $a3, .L7F024D78
/* 05989C 7F024D6C AFAE002C */   sw    $t6, 0x2c($sp)
/* 0598A0 7F024D70 14400005 */  bnez  $v0, .L7F024D88
/* 0598A4 7F024D74 00000000 */   nop   
.L7F024D78:
/* 0598A8 7F024D78 14E00007 */  bnez  $a3, .L7F024D98
/* 0598AC 7F024D7C 00E02025 */   move  $a0, $a3
/* 0598B0 7F024D80 54400006 */  bnezl $v0, .L7F024D9C
/* 0598B4 7F024D84 AFA50030 */   sw    $a1, 0x30($sp)
.L7F024D88:
/* 0598B8 7F024D88 0C002914 */  jal   randomGetNext
/* 0598BC 7F024D8C AFA0002C */   sw    $zero, 0x2c($sp)
/* 0598C0 7F024D90 10000010 */  b     .L7F024DD4
/* 0598C4 7F024D94 30460001 */   andi  $a2, $v0, 1
.L7F024D98:
/* 0598C8 7F024D98 AFA50030 */  sw    $a1, 0x30($sp)
.L7F024D9C:
/* 0598CC 7F024D9C 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 0598D0 7F024DA0 AFA70034 */   sw    $a3, 0x34($sp)
/* 0598D4 7F024DA4 8FA50030 */  lw    $a1, 0x30($sp)
/* 0598D8 7F024DA8 14400006 */  bnez  $v0, .L7F024DC4
/* 0598DC 7F024DAC 8FA70034 */   lw    $a3, 0x34($sp)
/* 0598E0 7F024DB0 00A02025 */  move  $a0, $a1
/* 0598E4 7F024DB4 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 0598E8 7F024DB8 AFA70034 */   sw    $a3, 0x34($sp)
/* 0598EC 7F024DBC 10400004 */  beqz  $v0, .L7F024DD0
/* 0598F0 7F024DC0 8FA70034 */   lw    $a3, 0x34($sp)
.L7F024DC4:
/* 0598F4 7F024DC4 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0598F8 7F024DC8 10000002 */  b     .L7F024DD4
/* 0598FC 7F024DCC 0007302B */   sltu  $a2, $zero, $a3
.L7F024DD0:
/* 059900 7F024DD0 0007302B */  sltu  $a2, $zero, $a3
.L7F024DD4:
/* 059904 7F024DD4 02002025 */  move  $a0, $s0
/* 059908 7F024DD8 0FC0B461 */  jal   sub_GAME_7F02D184
/* 05990C 7F024DDC AFA60028 */   sw    $a2, 0x28($sp)
/* 059910 7F024DE0 8FA2004C */  lw    $v0, 0x4c($sp)
/* 059914 7F024DE4 8FA60028 */  lw    $a2, 0x28($sp)
/* 059918 7F024DE8 240F000D */  li    $t7, 13
/* 05991C 7F024DEC A20F0007 */  sb    $t7, 7($s0)
/* 059920 7F024DF0 C4440000 */  lwc1  $f4, ($v0)
/* 059924 7F024DF4 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 059928 7F024DF8 44800000 */  mtc1  $zero, $f0
/* 05992C 7F024DFC E604002C */  swc1  $f4, 0x2c($s0)
/* 059930 7F024E00 C4460004 */  lwc1  $f6, 4($v0)
/* 059934 7F024E04 44815000 */  mtc1  $at, $f10
/* 059938 7F024E08 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 05993C 7F024E0C E6060030 */  swc1  $f6, 0x30($s0)
/* 059940 7F024E10 C4480008 */  lwc1  $f8, 8($v0)
/* 059944 7F024E14 A2000008 */  sb    $zero, 8($s0)
/* 059948 7F024E18 E6000040 */  swc1  $f0, 0x40($s0)
/* 05994C 7F024E1C E60A0038 */  swc1  $f10, 0x38($s0)
/* 059950 7F024E20 E6080034 */  swc1  $f8, 0x34($s0)
/* 059954 7F024E24 8FB8002C */  lw    $t8, 0x2c($sp)
/* 059958 7F024E28 5300001B */  beql  $t8, $zero, .L7F024E98
/* 05995C 7F024E2C 44811000 */   mtc1  $at, $f2
/* 059960 7F024E30 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 059964 7F024E34 44811000 */  mtc1  $at, $f2
/* 059968 7F024E38 3C018003 */  lui    $at, %hi(D_80030988) # -0.000000
/* 05996C 7F024E3C C4320988 */  lwc1  $f18, %lo(D_80030988)($at)
/* 059970 7F024E40 C7B00038 */  lwc1  $f16, 0x38($sp)
/* 059974 7F024E44 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 059978 7F024E48 46029102 */  mul.s $f4, $f18, $f2
/* 05997C 7F024E4C 3C098007 */  lui   $t1, %hi(ptr_animation_table) 
/* 059980 7F024E50 44815000 */  mtc1  $at, $f10
/* 059984 7F024E54 3C0A0000 */  lui   $t2, %hi(0x000040D4) # $t2, 0
/* 059988 7F024E58 254A40D4 */  addiu $t2, %lo(0x000040D4) # addiu $t2, $t2, 0x40d4
/* 05998C 7F024E5C 8E04001C */  lw    $a0, 0x1c($s0)
/* 059990 7F024E60 44070000 */  mfc1  $a3, $f0
/* 059994 7F024E64 46048183 */  div.s $f6, $f16, $f4
/* 059998 7F024E68 4600320D */  trunc.w.s $f8, $f6
/* 05999C 7F024E6C 44084000 */  mfc1  $t0, $f8
/* 0599A0 7F024E70 00000000 */  nop   
/* 0599A4 7F024E74 AE08003C */  sw    $t0, 0x3c($s0)
/* 0599A8 7F024E78 8D299538 */  lw    $t1, %lo(ptr_animation_table)($t1)
/* 0599AC 7F024E7C E7A20010 */  swc1  $f2, 0x10($sp)
/* 0599B0 7F024E80 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 0599B4 7F024E84 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 0599B8 7F024E88 012A2821 */   addu  $a1, $t1, $t2
/* 0599BC 7F024E8C 10000018 */  b     .L7F024EF0
/* 0599C0 7F024E90 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0599C4 7F024E94 44811000 */  mtc1  $at, $f2
.L7F024E98:
/* 0599C8 7F024E98 3C018003 */  lui   $at, %hi(D_80030994)
/* 0599CC 7F024E9C C4300994 */  lwc1  $f16, %lo(D_80030994)($at)
/* 0599D0 7F024EA0 C7B20038 */  lwc1  $f18, 0x38($sp)
/* 0599D4 7F024EA4 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0599D8 7F024EA8 46028102 */  mul.s $f4, $f16, $f2
/* 0599DC 7F024EAC 3C0D8007 */  lui   $t5, %hi(ptr_animation_table) 
/* 0599E0 7F024EB0 44815000 */  mtc1  $at, $f10
/* 0599E4 7F024EB4 3C0E0000 */  lui   $t6, %hi(0x0000777C) # $t6, 0
/* 0599E8 7F024EB8 25CE777C */  addiu $t6, %lo(0x0000777C) # addiu $t6, $t6, 0x777c
/* 0599EC 7F024EBC 8E04001C */  lw    $a0, 0x1c($s0)
/* 0599F0 7F024EC0 44070000 */  mfc1  $a3, $f0
/* 0599F4 7F024EC4 46049183 */  div.s $f6, $f18, $f4
/* 0599F8 7F024EC8 4600320D */  trunc.w.s $f8, $f6
/* 0599FC 7F024ECC 440C4000 */  mfc1  $t4, $f8
/* 059A00 7F024ED0 00000000 */  nop   
/* 059A04 7F024ED4 AE0C003C */  sw    $t4, 0x3c($s0)
/* 059A08 7F024ED8 8DAD9538 */  lw    $t5, %lo(ptr_animation_table)($t5)
/* 059A0C 7F024EDC E7A20010 */  swc1  $f2, 0x10($sp)
/* 059A10 7F024EE0 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 059A14 7F024EE4 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 059A18 7F024EE8 01AE2821 */   addu  $a1, $t5, $t6
/* 059A1C 7F024EEC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F024EF0:
/* 059A20 7F024EF0 8FB00020 */  lw    $s0, 0x20($sp)
/* 059A24 7F024EF4 27BD0048 */  addiu $sp, $sp, 0x48
/* 059A28 7F024EF8 03E00008 */  jr    $ra
/* 059A2C 7F024EFC 00000000 */   nop   
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel sub_GAME_7F024CF8
/* 0576D0 7F024CE0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0576D4 7F024CE4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0576D8 7F024CE8 AFB00020 */  sw    $s0, 0x20($sp)
/* 0576DC 7F024CEC 8C820018 */  lw    $v0, 0x18($a0)
/* 0576E0 7F024CF0 C4A60000 */  lwc1  $f6, ($a1)
/* 0576E4 7F024CF4 C4AA0008 */  lwc1  $f10, 8($a1)
/* 0576E8 7F024CF8 C4440008 */  lwc1  $f4, 8($v0)
/* 0576EC 7F024CFC C4480010 */  lwc1  $f8, 0x10($v0)
/* 0576F0 7F024D00 00808025 */  move  $s0, $a0
/* 0576F4 7F024D04 46062001 */  sub.s $f0, $f4, $f6
/* 0576F8 7F024D08 AFA5004C */  sw    $a1, 0x4c($sp)
/* 0576FC 7F024D0C 460A4081 */  sub.s $f2, $f8, $f10
/* 057700 7F024D10 46000402 */  mul.s $f16, $f0, $f0
/* 057704 7F024D14 00000000 */  nop   
/* 057708 7F024D18 46021482 */  mul.s $f18, $f2, $f2
/* 05770C 7F024D1C 0C007614 */  jal   sqrtf
/* 057710 7F024D20 46128300 */   add.s $f12, $f16, $f18
/* 057714 7F024D24 E7A00038 */  swc1  $f0, 0x38($sp)
/* 057718 7F024D28 02002025 */  move  $a0, $s0
/* 05771C 7F024D2C 0FC08BFD */  jal   something_with_weaponpos_of_guarddata_hand
/* 057720 7F024D30 24050001 */   li    $a1, 1
/* 057724 7F024D34 02002025 */  move  $a0, $s0
/* 057728 7F024D38 00002825 */  move  $a1, $zero
/* 05772C 7F024D3C 0FC08BFD */  jal   something_with_weaponpos_of_guarddata_hand
/* 057730 7F024D40 AFA20034 */   sw    $v0, 0x34($sp)
/* 057734 7F024D44 8FA70034 */  lw    $a3, 0x34($sp)
/* 057738 7F024D48 240E0001 */  li    $t6, 1
/* 05773C 7F024D4C 00402825 */  move  $a1, $v0
/* 057740 7F024D50 10E00003 */  beqz  $a3, .L7F024D60
/* 057744 7F024D54 AFAE002C */   sw    $t6, 0x2c($sp)
/* 057748 7F024D58 14400005 */  bnez  $v0, .L7F024D70
/* 05774C 7F024D5C 00000000 */   nop   
.L7F024D60:
/* 057750 7F024D60 14E00007 */  bnez  $a3, .L7F024D80
/* 057754 7F024D64 00E02025 */   move  $a0, $a3
/* 057758 7F024D68 54400006 */  bnezl $v0, .L7F024D84
/* 05775C 7F024D6C AFA50030 */   sw    $a1, 0x30($sp)
.L7F024D70:
/* 057760 7F024D70 0C00262C */  jal   randomGetNext
/* 057764 7F024D74 AFA0002C */   sw    $zero, 0x2c($sp)
/* 057768 7F024D78 10000010 */  b     .L7F024DBC
/* 05776C 7F024D7C 30460001 */   andi  $a2, $v0, 1
.L7F024D80:
/* 057770 7F024D80 AFA50030 */  sw    $a1, 0x30($sp)
.L7F024D84:
/* 057774 7F024D84 0FC08E3C */  jal   check_if_item_held_like_pistol
/* 057778 7F024D88 AFA70034 */   sw    $a3, 0x34($sp)
/* 05777C 7F024D8C 8FA50030 */  lw    $a1, 0x30($sp)
/* 057780 7F024D90 14400006 */  bnez  $v0, .L7F024DAC
/* 057784 7F024D94 8FA70034 */   lw    $a3, 0x34($sp)
/* 057788 7F024D98 00A02025 */  move  $a0, $a1
/* 05778C 7F024D9C 0FC08E3C */  jal   check_if_item_held_like_pistol
/* 057790 7F024DA0 AFA70034 */   sw    $a3, 0x34($sp)
/* 057794 7F024DA4 10400004 */  beqz  $v0, .L7F024DB8
/* 057798 7F024DA8 8FA70034 */   lw    $a3, 0x34($sp)
.L7F024DAC:
/* 05779C 7F024DAC AFA0002C */  sw    $zero, 0x2c($sp)
/* 0577A0 7F024DB0 10000002 */  b     .L7F024DBC
/* 0577A4 7F024DB4 0007302B */   sltu  $a2, $zero, $a3
.L7F024DB8:
/* 0577A8 7F024DB8 0007302B */  sltu  $a2, $zero, $a3
.L7F024DBC:
/* 0577AC 7F024DBC 02002025 */  move  $a0, $s0
/* 0577B0 7F024DC0 0FC0B46E */  jal   sub_GAME_7F02D184
/* 0577B4 7F024DC4 AFA60028 */   sw    $a2, 0x28($sp)
/* 0577B8 7F024DC8 8FA2004C */  lw    $v0, 0x4c($sp)
/* 0577BC 7F024DCC 8FA60028 */  lw    $a2, 0x28($sp)
/* 0577C0 7F024DD0 240F000D */  li    $t7, 13
/* 0577C4 7F024DD4 A20F0007 */  sb    $t7, 7($s0)
/* 0577C8 7F024DD8 C4440000 */  lwc1  $f4, ($v0)
/* 0577CC 7F024DDC 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 0577D0 7F024DE0 44800000 */  mtc1  $zero, $f0
/* 0577D4 7F024DE4 E604002C */  swc1  $f4, 0x2c($s0)
/* 0577D8 7F024DE8 C4460004 */  lwc1  $f6, 4($v0)
/* 0577DC 7F024DEC 44815000 */  mtc1  $at, $f10
/* 0577E0 7F024DF0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0577E4 7F024DF4 E6060030 */  swc1  $f6, 0x30($s0)
/* 0577E8 7F024DF8 C4480008 */  lwc1  $f8, 8($v0)
/* 0577EC 7F024DFC A2000008 */  sb    $zero, 8($s0)
/* 0577F0 7F024E00 E6000040 */  swc1  $f0, 0x40($s0)
/* 0577F4 7F024E04 E60A0038 */  swc1  $f10, 0x38($s0)
/* 0577F8 7F024E08 E6080034 */  swc1  $f8, 0x34($s0)
/* 0577FC 7F024E0C 8FB8002C */  lw    $t8, 0x2c($sp)
/* 057800 7F024E10 53000021 */  beql  $t8, $zero, .L7F024E98
/* 057804 7F024E14 44811000 */   mtc1  $at, $f2
/* 057808 7F024E18 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 05780C 7F024E1C 44811000 */  mtc1  $at, $f2
/* 057810 7F024E20 3C018003 */  lui    $at, %hi(D_80030988) # -0.000000
/* 057814 7F024E24 C432BED8 */  lwc1  $f18, %lo(D_80030988)($at)
/* 057818 7F024E28 C7B00038 */  lwc1  $f16, 0x38($sp)
/* 05781C 7F024E2C 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 057820 7F024E30 46029102 */  mul.s $f4, $f18, $f2
/* 057824 7F024E34 44814000 */  mtc1  $at, $f8
/* 057828 7F024E38 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 05782C 7F024E3C 44819000 */  mtc1  $at, $f18
/* 057830 7F024E40 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 057834 7F024E44 3C098006 */  lui   $t1, %hi(ptr_animation_table) # $t1, 0x8006
/* 057838 7F024E48 3C0A0000 */  lui   $t2, %hi(0x000040D4) # $t2, 0
/* 05783C 7F024E4C 46048183 */  div.s $f6, $f16, $f4
/* 057840 7F024E50 254A40D4 */  addiu $t2, %lo(0x000040D4) # addiu $t2, $t2, 0x40d4
/* 057844 7F024E54 8E04001C */  lw    $a0, 0x1c($s0)
/* 057848 7F024E58 44070000 */  mfc1  $a3, $f0
/* 05784C 7F024E5C 46083282 */  mul.s $f10, $f6, $f8
/* 057850 7F024E60 44813000 */  mtc1  $at, $f6
/* 057854 7F024E64 46125403 */  div.s $f16, $f10, $f18
/* 057858 7F024E68 4600810D */  trunc.w.s $f4, $f16
/* 05785C 7F024E6C 44082000 */  mfc1  $t0, $f4
/* 057860 7F024E70 00000000 */  nop   
/* 057864 7F024E74 AE08003C */  sw    $t0, 0x3c($s0)
/* 057868 7F024E78 8D298478 */  lw    $t1, %lo(ptr_animation_table)($t1)
/* 05786C 7F024E7C E7A20010 */  swc1  $f2, 0x10($sp)
/* 057870 7F024E80 E7A60014 */  swc1  $f6, 0x14($sp)
/* 057874 7F024E84 0FC1BF92 */  jal   objecthandlerAnimationRelated7F06FCA8
/* 057878 7F024E88 012A2821 */   addu  $a1, $t1, $t2
/* 05787C 7F024E8C 1000001E */  b     .L7F024F08
/* 057880 7F024E90 8FBF0024 */   lw    $ra, 0x24($sp)
/* 057884 7F024E94 44811000 */  mtc1  $at, $f2
.L7F024E98:
/* 057888 7F024E98 3C018003 */  lui   $at, %hi(D_80030994) # $at, 0x8003
/* 05788C 7F024E9C C42ABEE4 */  lwc1  $f10, %lo(D_80030994)($at)
/* 057890 7F024EA0 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 057894 7F024EA4 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 057898 7F024EA8 46025482 */  mul.s $f18, $f10, $f2
/* 05789C 7F024EAC 44812000 */  mtc1  $at, $f4
/* 0578A0 7F024EB0 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0578A4 7F024EB4 44815000 */  mtc1  $at, $f10
/* 0578A8 7F024EB8 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0578AC 7F024EBC 3C0D8006 */  lui   $t5, %hi(ptr_animation_table) # $t5, 0x8006
/* 0578B0 7F024EC0 3C0E0000 */  lui   $t6, %hi(0x0000777C) # $t6, 0
/* 0578B4 7F024EC4 46124403 */  div.s $f16, $f8, $f18
/* 0578B8 7F024EC8 25CE777C */  addiu $t6, %lo(0x0000777C) # addiu $t6, $t6, 0x777c
/* 0578BC 7F024ECC 8E04001C */  lw    $a0, 0x1c($s0)
/* 0578C0 7F024ED0 44070000 */  mfc1  $a3, $f0
/* 0578C4 7F024ED4 46048182 */  mul.s $f6, $f16, $f4
/* 0578C8 7F024ED8 44818000 */  mtc1  $at, $f16
/* 0578CC 7F024EDC 460A3203 */  div.s $f8, $f6, $f10
/* 0578D0 7F024EE0 4600448D */  trunc.w.s $f18, $f8
/* 0578D4 7F024EE4 440C9000 */  mfc1  $t4, $f18
/* 0578D8 7F024EE8 00000000 */  nop   
/* 0578DC 7F024EEC AE0C003C */  sw    $t4, 0x3c($s0)
/* 0578E0 7F024EF0 8DAD8478 */  lw    $t5, %lo(ptr_animation_table)($t5)
/* 0578E4 7F024EF4 E7A20010 */  swc1  $f2, 0x10($sp)
/* 0578E8 7F024EF8 E7B00014 */  swc1  $f16, 0x14($sp)
/* 0578EC 7F024EFC 0FC1BF92 */  jal   objecthandlerAnimationRelated7F06FCA8
/* 0578F0 7F024F00 01AE2821 */   addu  $a1, $t5, $t6
/* 0578F4 7F024F04 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F024F08:
/* 0578F8 7F024F08 8FB00020 */  lw    $s0, 0x20($sp)
/* 0578FC 7F024F0C 27BD0048 */  addiu $sp, $sp, 0x48
/* 057900 7F024F10 03E00008 */  jr    $ra
/* 057904 7F024F14 00000000 */   nop   
)
#endif
#endif


void chrlvDeathStaggerAnimationRelated(struct ChrRecord *arg0)
{
    sub_GAME_7F02D184(arg0);
    arg0->actiontype = ACT_TEST;
    arg0->sleep = 0;
    objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_death_stagger_back_to_wall], 0, 10.0f, 0.5f, 16.0f);
    sub_GAME_7F06FDCC(arg0->model, 10.0f, 16.0f);
    sub_GAME_7F06FDE8(arg0->model, 40.0f);
}




/**
 * Called from actor_fire_or_aim_at_target_update, where action type is ACT_ATTACK.
 * 
 * Address 0x7F024F8C.
 */
void chrlvAttackActionRelated(struct ChrRecord *arg0)
{
    struct Model* model = arg0->model;
    f32 *f = arg0->act_attack.unk02c;

    if ((arg0->act_attack.attacktype & 0x20) != 0)
    {
        if ((f[8] >= 0.0f) && (f[8] < f[6]))
        {
            sub_GAME_7F06FDE8(model, f[8]);
        }
        else
        {
            sub_GAME_7F06FDE8(model, f[6]);
        }
    }
    else if (arg0->act_attack.unk036 != 0)
    {
        if (f[8] >= 0.0f)
        {
            sub_GAME_7F06FDE8(model, f[8]);
        }
        else
        {
            sub_GAME_7F06FDE8(model, f[6]);
        }
    }
    else if (f[8] >= 0.0f)
    {
        sub_GAME_7F06FDE8(model, f[8]);
    }
    else if (f[5] >= 0.0f)
    {
        sub_GAME_7F06FDE8(model, f[5]);
    }
    else
    {
        sub_GAME_7F06FDE8(model, -1.0f);
    }
}



/**
 * Address 0x7F0250BC.
 */
f32 chrlvDistanceToChrRelated(ChrRecord *arg0, s32 arg1, s32 arg2)
{
    f32 ret;
    s32 out_unused;

    if ((arg1 & 2) != 0)
    {
        return 0.0f;
    }

    if ((arg1 & 0x10) != 0)
    {
        ret = ((f32) arg2 * M_2PI_F) / M_U16_MAX_VALUE_F;

        ret -= getsubroty(arg0->model);

        if (ret < 0.0f)
        {
            ret += M_2PI_F;
        }

        return ret;
    }

    return get_distance_actor_to_position(arg0, (struct coord3d *)sub_GAME_7F032C78(arg0, arg1, arg2, &out_unused));
}



#ifdef NONMATCHING
void sub_GAME_7F02516C(void) {
 /**
  * @param arg0:
  * @param arg1: address of array of firing animations (example: ptr_pistol_firing_animation_groups)
  * @param arg2:
  * @param arg3: s32 array, seems to only have 2-4 elements? (not sure...)
  */
 // tenative signature: void sub_GAME_7F02516C(ChrRecord *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4, s32 arg5, s32 arg6)
 // mostly setting a bunch of the struct act_* properties, unsure of type
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051DB4
.word 0x40c90fdb /*6.2831855*/
glabel D_80051DB8
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02516C
/* 059C9C 7F02516C 27BDFF70 */  addiu $sp, $sp, -0x90
/* 059CA0 7F025170 AFBF003C */  sw    $ra, 0x3c($sp)
/* 059CA4 7F025174 AFB70038 */  sw    $s7, 0x38($sp)
/* 059CA8 7F025178 AFB60034 */  sw    $s6, 0x34($sp)
/* 059CAC 7F02517C AFB50030 */  sw    $s5, 0x30($sp)
/* 059CB0 7F025180 AFB4002C */  sw    $s4, 0x2c($sp)
/* 059CB4 7F025184 AFB30028 */  sw    $s3, 0x28($sp)
/* 059CB8 7F025188 AFB20024 */  sw    $s2, 0x24($sp)
/* 059CBC 7F02518C AFB10020 */  sw    $s1, 0x20($sp)
/* 059CC0 7F025190 AFB0001C */  sw    $s0, 0x1c($sp)
/* 059CC4 7F025194 AFA60098 */  sw    $a2, 0x98($sp)
/* 059CC8 7F025198 AFA7009C */  sw    $a3, 0x9c($sp)
/* 059CCC 7F02519C 8C8E001C */  lw    $t6, 0x1c($a0)
/* 059CD0 7F0251A0 3C188003 */  lui   $t8, %hi(D_800309A8) 
/* 059CD4 7F0251A4 271809A8 */  addiu $t8, %lo(D_800309A8) # addiu $t8, $t8, 0x9a8
/* 059CD8 7F0251A8 AFAE008C */  sw    $t6, 0x8c($sp)
/* 059CDC 7F0251AC 8F0A0004 */  lw    $t2, 4($t8)
/* 059CE0 7F0251B0 8F010000 */  lw    $at, ($t8)
/* 059CE4 7F0251B4 27AF0060 */  addiu $t7, $sp, 0x60
/* 059CE8 7F0251B8 3C0C8003 */  lui   $t4, %hi(D_800309B0) 
/* 059CEC 7F0251BC 258C09B0 */  addiu $t4, %lo(D_800309B0) # addiu $t4, $t4, 0x9b0
/* 059CF0 7F0251C0 ADEA0004 */  sw    $t2, 4($t7)
/* 059CF4 7F0251C4 ADE10000 */  sw    $at, ($t7)
/* 059CF8 7F0251C8 8D890004 */  lw    $t1, 4($t4)
/* 059CFC 7F0251CC 8D810000 */  lw    $at, ($t4)
/* 059D00 7F0251D0 27AB0058 */  addiu $t3, $sp, 0x58
/* 059D04 7F0251D4 24190008 */  li    $t9, 8
/* 059D08 7F0251D8 AD690004 */  sw    $t1, 4($t3)
/* 059D0C 7F0251DC AD610000 */  sw    $at, ($t3)
/* 059D10 7F0251E0 00A08825 */  move  $s1, $a1
/* 059D14 7F0251E4 A0990007 */  sb    $t9, 7($a0)
/* 059D18 7F0251E8 0080A025 */  move  $s4, $a0
/* 059D1C 7F0251EC 24160001 */  li    $s6, 1
/* 059D20 7F0251F0 0000B825 */  move  $s7, $zero
/* 059D24 7F0251F4 8FA600A4 */  lw    $a2, 0xa4($sp)
/* 059D28 7F0251F8 0FC0942F */  jal   chrlvDistanceToChrRelated
/* 059D2C 7F0251FC 8FA500A0 */   lw    $a1, 0xa0($sp)
/* 059D30 7F025200 8FAF0098 */  lw    $t7, 0x98($sp)
/* 059D34 7F025204 3C018005 */  lui   $at, %hi(D_80051DB8)
/* 059D38 7F025208 11E0000F */  beqz  $t7, .L7F025248
/* 059D3C 7F02520C 00000000 */   nop   
/* 059D40 7F025210 3C018005 */  lui   $at, %hi(D_80051DB4)
/* 059D44 7F025214 C4221DB4 */  lwc1  $f2, %lo(D_80051DB4)($at)
/* 059D48 7F025218 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 059D4C 7F02521C 44813000 */  mtc1  $at, $f6
/* 059D50 7F025220 46001101 */  sub.s $f4, $f2, $f0
/* 059D54 7F025224 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 059D58 7F025228 44818000 */  mtc1  $at, $f16
/* 059D5C 7F02522C 46062202 */  mul.s $f8, $f4, $f6
/* 059D60 7F025230 46024283 */  div.s $f10, $f8, $f2
/* 059D64 7F025234 46105480 */  add.s $f18, $f10, $f16
/* 059D68 7F025238 4600910D */  trunc.w.s $f4, $f18
/* 059D6C 7F02523C 44102000 */  mfc1  $s0, $f4
/* 059D70 7F025240 1000000D */  b     .L7F025278
/* 059D74 7F025244 2A010020 */   slti  $at, $s0, 0x20
.L7F025248:
/* 059D78 7F025248 C4221DB8 */  lwc1  $f2, %lo(D_80051DB8)($at)
/* 059D7C 7F02524C 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 059D80 7F025250 44813000 */  mtc1  $at, $f6
/* 059D84 7F025254 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 059D88 7F025258 44818000 */  mtc1  $at, $f16
/* 059D8C 7F02525C 46060202 */  mul.s $f8, $f0, $f6
/* 059D90 7F025260 46024283 */  div.s $f10, $f8, $f2
/* 059D94 7F025264 46105480 */  add.s $f18, $f10, $f16
/* 059D98 7F025268 4600910D */  trunc.w.s $f4, $f18
/* 059D9C 7F02526C 44102000 */  mfc1  $s0, $f4
/* 059DA0 7F025270 00000000 */  nop   
/* 059DA4 7F025274 2A010020 */  slti  $at, $s0, 0x20
.L7F025278:
/* 059DA8 7F025278 14200002 */  bnez  $at, .L7F025284
/* 059DAC 7F02527C 00000000 */   nop   
/* 059DB0 7F025280 00008025 */  move  $s0, $zero
.L7F025284:
/* 059DB4 7F025284 0C002914 */  jal   randomGetNext
/* 059DB8 7F025288 00000000 */   nop   
/* 059DBC 7F02528C 00107080 */  sll   $t6, $s0, 2
/* 059DC0 7F025290 022E6821 */  addu  $t5, $s1, $t6
/* 059DC4 7F025294 8DA30000 */  lw    $v1, ($t5)
/* 059DC8 7F025298 24080048 */  li    $t0, 72
/* 059DCC 7F02529C 8E8C0014 */  lw    $t4, 0x14($s4)
/* 059DD0 7F0252A0 8C650004 */  lw    $a1, 4($v1)
/* 059DD4 7F0252A4 8C660000 */  lw    $a2, ($v1)
/* 059DD8 7F0252A8 31890020 */  andi  $t1, $t4, 0x20
/* 059DDC 7F0252AC 0045001B */  divu  $zero, $v0, $a1
/* 059DE0 7F0252B0 00002010 */  mfhi  $a0
/* 059DE4 7F0252B4 3C198007 */  lui   $t9, %hi(ptr_animation_table) 
/* 059DE8 7F0252B8 14A00002 */  bnez  $a1, .L7F0252C4
/* 059DEC 7F0252BC 00000000 */   nop   
/* 059DF0 7F0252C0 0007000D */  break 7
.L7F0252C4:
/* 059DF4 7F0252C4 00880019 */  multu $a0, $t0
/* 059DF8 7F0252C8 3C0F0000 */  lui   $t7, %hi(0x00000318) # $t7, 0
/* 059DFC 7F0252CC 00008825 */  move  $s1, $zero
/* 059E00 7F0252D0 00009025 */  move  $s2, $zero
/* 059E04 7F0252D4 8FB3009C */  lw    $s3, 0x9c($sp)
/* 059E08 7F0252D8 24150001 */  li    $s5, 1
/* 059E0C 7F0252DC 00005812 */  mflo  $t3
/* 059E10 7F0252E0 00CB3821 */  addu  $a3, $a2, $t3
/* 059E14 7F0252E4 51200017 */  beql  $t1, $zero, .L7F025344
/* 059E18 7F0252E8 AFA70080 */   sw    $a3, 0x80($sp)
/* 059E1C 7F0252EC 8F399538 */  lw    $t9, %lo(ptr_animation_table)($t9)
/* 059E20 7F0252F0 8CEA0000 */  lw    $t2, ($a3)
/* 059E24 7F0252F4 25EF0318 */  addiu $t7, %lo(0x00000318) # addiu $t7, $t7, 0x318
/* 059E28 7F0252F8 032FC021 */  addu  $t8, $t9, $t7
/* 059E2C 7F0252FC 170A0010 */  bne   $t8, $t2, .L7F025340
/* 059E30 7F025300 248E0001 */   addiu $t6, $a0, 1
/* 059E34 7F025304 01C5001A */  div   $zero, $t6, $a1
/* 059E38 7F025308 00006810 */  mfhi  $t5
/* 059E3C 7F02530C 14A00002 */  bnez  $a1, .L7F025318
/* 059E40 7F025310 00000000 */   nop   
/* 059E44 7F025314 0007000D */  break 7
.L7F025318:
/* 059E48 7F025318 2401FFFF */  li    $at, -1
/* 059E4C 7F02531C 14A10004 */  bne   $a1, $at, .L7F025330
/* 059E50 7F025320 3C018000 */   lui   $at, 0x8000
/* 059E54 7F025324 15C10002 */  bne   $t6, $at, .L7F025330
/* 059E58 7F025328 00000000 */   nop   
/* 059E5C 7F02532C 0006000D */  break 6
.L7F025330:
/* 059E60 7F025330 01A80019 */  multu $t5, $t0
/* 059E64 7F025334 00005812 */  mflo  $t3
/* 059E68 7F025338 01663821 */  addu  $a3, $t3, $a2
/* 059E6C 7F02533C 00000000 */  nop   
.L7F025340:
/* 059E70 7F025340 AFA70080 */  sw    $a3, 0x80($sp)
.L7F025344:
/* 059E74 7F025344 8E6C0000 */  lw    $t4, ($s3)
/* 059E78 7F025348 02802025 */  move  $a0, $s4
/* 059E7C 7F02534C 5180001A */  beql  $t4, $zero, .L7F0253B8
/* 059E80 7F025350 26310001 */   addiu $s1, $s1, 1
/* 059E84 7F025354 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 059E88 7F025358 02202825 */   move  $a1, $s1
/* 059E8C 7F02535C 8C500004 */  lw    $s0, 4($v0)
/* 059E90 7F025360 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 059E94 7F025364 82040080 */   lb    $a0, 0x80($s0)
/* 059E98 7F025368 04410008 */  bgez  $v0, .L7F02538C
/* 059E9C 7F02536C 03B24821 */   addu  $t1, $sp, $s2
/* 059EA0 7F025370 AD350060 */  sw    $s5, 0x60($t1)
/* 059EA4 7F025374 82020080 */  lb    $v0, 0x80($s0)
/* 059EA8 7F025378 24010016 */  li    $at, 22
/* 059EAC 7F02537C 54410007 */  bnel  $v0, $at, .L7F02539C
/* 059EB0 7F025380 24010019 */   li    $at, 25
/* 059EB4 7F025384 10000004 */  b     .L7F025398
/* 059EB8 7F025388 0000B025 */   move  $s6, $zero
.L7F02538C:
/* 059EBC 7F02538C 0000B025 */  move  $s6, $zero
/* 059EC0 7F025390 02A0B825 */  move  $s7, $s5
/* 059EC4 7F025394 82020080 */  lb    $v0, 0x80($s0)
.L7F025398:
/* 059EC8 7F025398 24010019 */  li    $at, 25
.L7F02539C:
/* 059ECC 7F02539C 10410004 */  beq   $v0, $at, .L7F0253B0
/* 059ED0 7F0253A0 03B2C821 */   addu  $t9, $sp, $s2
/* 059ED4 7F0253A4 24010018 */  li    $at, 24
/* 059ED8 7F0253A8 54410003 */  bnel  $v0, $at, .L7F0253B8
/* 059EDC 7F0253AC 26310001 */   addiu $s1, $s1, 1
.L7F0253B0:
/* 059EE0 7F0253B0 AF350058 */  sw    $s5, 0x58($t9)
/* 059EE4 7F0253B4 26310001 */  addiu $s1, $s1, 1
.L7F0253B8:
/* 059EE8 7F0253B8 24010002 */  li    $at, 2
/* 059EEC 7F0253BC 26520004 */  addiu $s2, $s2, 4
/* 059EF0 7F0253C0 1621FFE0 */  bne   $s1, $at, .L7F025344
/* 059EF4 7F0253C4 26730004 */   addiu $s3, $s3, 4
/* 059EF8 7F0253C8 A2950030 */  sb    $s5, 0x30($s4)
/* 059EFC 7F0253CC 8FAF0080 */  lw    $t7, 0x80($sp)
/* 059F00 7F0253D0 A2800031 */  sb    $zero, 0x31($s4)
/* 059F04 7F0253D4 0C002914 */  jal   randomGetNext
/* 059F08 7F0253D8 AE8F002C */   sw    $t7, 0x2c($s4)
/* 059F0C 7F0253DC 30580001 */  andi  $t8, $v0, 1
/* 059F10 7F0253E0 A2980032 */  sb    $t8, 0x32($s4)
/* 059F14 7F0253E4 8FAA009C */  lw    $t2, 0x9c($sp)
/* 059F18 7F0253E8 8D4E0004 */  lw    $t6, 4($t2)
/* 059F1C 7F0253EC A28E0039 */  sb    $t6, 0x39($s4)
/* 059F20 7F0253F0 8FAD009C */  lw    $t5, 0x9c($sp)
/* 059F24 7F0253F4 8DAB0000 */  lw    $t3, ($t5)
/* 059F28 7F0253F8 A28B0038 */  sb    $t3, 0x38($s4)
/* 059F2C 7F0253FC 8FAC0064 */  lw    $t4, 0x64($sp)
/* 059F30 7F025400 A28C003B */  sb    $t4, 0x3b($s4)
/* 059F34 7F025404 8FA90060 */  lw    $t1, 0x60($sp)
/* 059F38 7F025408 A289003A */  sb    $t1, 0x3a($s4)
/* 059F3C 7F02540C 8FB9005C */  lw    $t9, 0x5c($sp)
/* 059F40 7F025410 A299003D */  sb    $t9, 0x3d($s4)
/* 059F44 7F025414 8FAF0058 */  lw    $t7, 0x58($sp)
/* 059F48 7F025418 A2960036 */  sb    $s6, 0x36($s4)
/* 059F4C 7F02541C A2970037 */  sb    $s7, 0x37($s4)
/* 059F50 7F025420 AE800040 */  sw    $zero, 0x40($s4)
/* 059F54 7F025424 A2800033 */  sb    $zero, 0x33($s4)
/* 059F58 7F025428 A28F003C */  sb    $t7, 0x3c($s4)
/* 059F5C 7F02542C 8FB8005C */  lw    $t8, 0x5c($sp)
/* 059F60 7F025430 8FAA0058 */  lw    $t2, 0x58($sp)
/* 059F64 7F025434 8FAE005C */  lw    $t6, 0x5c($sp)
/* 059F68 7F025438 17000003 */  bnez  $t8, .L7F025448
/* 059F6C 7F02543C 00000000 */   nop   
/* 059F70 7F025440 11400009 */  beqz  $t2, .L7F025468
/* 059F74 7F025444 8FAC00A0 */   lw    $t4, 0xa0($sp)
.L7F025448:
/* 059F78 7F025448 11C00005 */  beqz  $t6, .L7F025460
/* 059F7C 7F02544C 8FAD0058 */   lw    $t5, 0x58($sp)
/* 059F80 7F025450 11A00003 */  beqz  $t5, .L7F025460
/* 059F84 7F025454 240B0002 */   li    $t3, 2
/* 059F88 7F025458 1000001B */  b     .L7F0254C8
/* 059F8C 7F02545C A28B0034 */   sb    $t3, 0x34($s4)
.L7F025460:
/* 059F90 7F025460 10000019 */  b     .L7F0254C8
/* 059F94 7F025464 A2950034 */   sb    $s5, 0x34($s4)
.L7F025468:
/* 059F98 7F025468 31890080 */  andi  $t1, $t4, 0x80
/* 059F9C 7F02546C 11200003 */  beqz  $t1, .L7F02547C
/* 059FA0 7F025470 00000000 */   nop   
/* 059FA4 7F025474 10000006 */  b     .L7F025490
/* 059FA8 7F025478 A2950034 */   sb    $s5, 0x34($s4)
.L7F02547C:
/* 059FAC 7F02547C 0C002914 */  jal   randomGetNext
/* 059FB0 7F025480 00000000 */   nop   
/* 059FB4 7F025484 30590003 */  andi  $t9, $v0, 3
/* 059FB8 7F025488 272F0002 */  addiu $t7, $t9, 2
/* 059FBC 7F02548C A28F0034 */  sb    $t7, 0x34($s4)
.L7F025490:
/* 059FC0 7F025490 8FB8009C */  lw    $t8, 0x9c($sp)
/* 059FC4 7F025494 8F0A0000 */  lw    $t2, ($t8)
/* 059FC8 7F025498 5140000C */  beql  $t2, $zero, .L7F0254CC
/* 059FCC 7F02549C 8FB900A0 */   lw    $t9, 0xa0($sp)
/* 059FD0 7F0254A0 8F0E0004 */  lw    $t6, 4($t8)
/* 059FD4 7F0254A4 51C00009 */  beql  $t6, $zero, .L7F0254CC
/* 059FD8 7F0254A8 8FB900A0 */   lw    $t9, 0xa0($sp)
/* 059FDC 7F0254AC 0C002914 */  jal   randomGetNext
/* 059FE0 7F0254B0 00000000 */   nop   
/* 059FE4 7F0254B4 828D0034 */  lb    $t5, 0x34($s4)
/* 059FE8 7F0254B8 304B0003 */  andi  $t3, $v0, 3
/* 059FEC 7F0254BC 01AB6021 */  addu  $t4, $t5, $t3
/* 059FF0 7F0254C0 25890002 */  addiu $t1, $t4, 2
/* 059FF4 7F0254C4 A2890034 */  sb    $t1, 0x34($s4)
.L7F0254C8:
/* 059FF8 7F0254C8 8FB900A0 */  lw    $t9, 0xa0($sp)
.L7F0254CC:
/* 059FFC 7F0254CC 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 05A000 7F0254D0 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 05A004 7F0254D4 AE99004C */  sw    $t9, 0x4c($s4)
/* 05A008 7F0254D8 8FAF00A4 */  lw    $t7, 0xa4($sp)
/* 05A00C 7F0254DC 02802025 */  move  $a0, $s4
/* 05A010 7F0254E0 3C053F00 */  lui   $a1, 0x3f00
/* 05A014 7F0254E4 AE8F0050 */  sw    $t7, 0x50($s4)
/* 05A018 7F0254E8 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 05A01C 7F0254EC AE800058 */  sw    $zero, 0x58($s4)
/* 05A020 7F0254F0 AE800044 */  sw    $zero, 0x44($s4)
/* 05A024 7F0254F4 AE800048 */  sw    $zero, 0x48($s4)
/* 05A028 7F0254F8 A2800008 */  sb    $zero, 8($s4)
/* 05A02C 7F0254FC 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 05A030 7F025500 AE8A0054 */   sw    $t2, 0x54($s4)
/* 05A034 7F025504 8FA20080 */  lw    $v0, 0x80($sp)
/* 05A038 7F025508 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 05A03C 7F02550C 44813000 */  mtc1  $at, $f6
/* 05A040 7F025510 8C450000 */  lw    $a1, ($v0)
/* 05A044 7F025514 8C470010 */  lw    $a3, 0x10($v0)
/* 05A048 7F025518 E7A00010 */  swc1  $f0, 0x10($sp)
/* 05A04C 7F02551C 8FA4008C */  lw    $a0, 0x8c($sp)
/* 05A050 7F025520 8FA60098 */  lw    $a2, 0x98($sp)
/* 05A054 7F025524 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 05A058 7F025528 E7A60014 */   swc1  $f6, 0x14($sp)
/* 05A05C 7F02552C 0FC093E3 */  jal   chrlvAttackActionRelated
/* 05A060 7F025530 02802025 */   move  $a0, $s4
/* 05A064 7F025534 8FBF003C */  lw    $ra, 0x3c($sp)
/* 05A068 7F025538 8FB0001C */  lw    $s0, 0x1c($sp)
/* 05A06C 7F02553C 8FB10020 */  lw    $s1, 0x20($sp)
/* 05A070 7F025540 8FB20024 */  lw    $s2, 0x24($sp)
/* 05A074 7F025544 8FB30028 */  lw    $s3, 0x28($sp)
/* 05A078 7F025548 8FB4002C */  lw    $s4, 0x2c($sp)
/* 05A07C 7F02554C 8FB50030 */  lw    $s5, 0x30($sp)
/* 05A080 7F025550 8FB60034 */  lw    $s6, 0x34($sp)
/* 05A084 7F025554 8FB70038 */  lw    $s7, 0x38($sp)
/* 05A088 7F025558 03E00008 */  jr    $ra
/* 05A08C 7F02555C 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F025560(ChrRecord *arg0, s32 arg1, s32 arg2)
{
    PropRecord *left;
    PropRecord *right;
    s32 sp[4];
    s32 animation_pointer;
    s32 last_arg2;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    // this is probably a struct copy
    sp[0] = D_800309B8;
    sp[1] = D_800309BC;

    if ((left != NULL) && (right != NULL))
    {
        left = is_weapon_in_guarddata_hand(arg0, LEFT_HAND);
        right = is_weapon_in_guarddata_hand(arg0, RIGHT_HAND);

        last_arg2 = right == NULL;
        animation_pointer = (s32) ptr_pistol_firing_animation_groups;

        if ((left != NULL) && (right != NULL))
        {
            sp[2] = randomGetNext() & 1;

            if ((randomGetNext() % 3U) == 0)
            {
                sp[1] = sp[2];
                sp[0] = sp[2] == 0;
                animation_pointer = (s32) ptr_pistol_firing_animation_groups;
            }
            else
            {
                sp[1] = last_arg2;
                sp[0] = last_arg2;
                animation_pointer = (s32) ptr_doubles_firing_animation_groups;
            }
        }
        else
        {
            sp[1] = last_arg2;
            sp[0] = last_arg2 == 0;
        }
    }
    else
    {
        if ((check_if_item_held_like_pistol(left) != 0) || (check_if_item_held_like_pistol(right) != 0))
        {
            last_arg2 = left != NULL;
            sp[1] = last_arg2;
            sp[0] = last_arg2 == 0;
            animation_pointer = (s32) ptr_pistol_firing_animation_groups;
        }
        else
        {
            last_arg2 = left != NULL;
            sp[1] = last_arg2;
            sp[0] = last_arg2 == 0;
            animation_pointer = (s32) ptr_rifle_firing_animation_groups;
        }
    }

    sub_GAME_7F02516C(arg0, animation_pointer, last_arg2, &sp, arg1, arg2, 1);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F025560
/* 05A090 7F025560 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 05A094 7F025564 AFBF0024 */  sw    $ra, 0x24($sp)
/* 05A098 7F025568 AFA50054 */  sw    $a1, 0x54($sp)
/* 05A09C 7F02556C AFA40050 */  sw    $a0, 0x50($sp)
/* 05A0A0 7F025570 AFA60058 */  sw    $a2, 0x58($sp)
/* 05A0A4 7F025574 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A0A8 7F025578 24050001 */   li    $a1, 1
/* 05A0AC 7F02557C AFA2004C */  sw    $v0, 0x4c($sp)
/* 05A0B0 7F025580 8FA40050 */  lw    $a0, 0x50($sp)
/* 05A0B4 7F025584 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A0B8 7F025588 00002825 */   move  $a1, $zero
/* 05A0BC 7F02558C 3C0F8003 */  lui   $t7, %hi(D_800309B8) 
/* 05A0C0 7F025590 25EF09B8 */  addiu $t7, %lo(D_800309B8) # addiu $t7, $t7, 0x9b8
/* 05A0C4 7F025594 8FA4004C */  lw    $a0, 0x4c($sp)
/* 05A0C8 7F025598 8DE10000 */  lw    $at, ($t7)
/* 05A0CC 7F02559C 8DE80004 */  lw    $t0, 4($t7)
/* 05A0D0 7F0255A0 27AE0038 */  addiu $t6, $sp, 0x38
/* 05A0D4 7F0255A4 00402825 */  move  $a1, $v0
/* 05A0D8 7F0255A8 ADC10000 */  sw    $at, ($t6)
/* 05A0DC 7F0255AC 1080002C */  beqz  $a0, .L7F025660
/* 05A0E0 7F0255B0 ADC80004 */   sw    $t0, 4($t6)
/* 05A0E4 7F0255B4 1040002A */  beqz  $v0, .L7F025660
/* 05A0E8 7F0255B8 00000000 */   nop   
/* 05A0EC 7F0255BC 8FA40050 */  lw    $a0, 0x50($sp)
/* 05A0F0 7F0255C0 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05A0F4 7F0255C4 24050001 */   li    $a1, 1
/* 05A0F8 7F0255C8 AFA20034 */  sw    $v0, 0x34($sp)
/* 05A0FC 7F0255CC 8FA40050 */  lw    $a0, 0x50($sp)
/* 05A100 7F0255D0 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05A104 7F0255D4 00002825 */   move  $a1, $zero
/* 05A108 7F0255D8 8FA90034 */  lw    $t1, 0x34($sp)
/* 05A10C 7F0255DC 3C058003 */  lui   $a1, %hi(ptr_pistol_firing_animation_groups)
/* 05A110 7F0255E0 2C460001 */  sltiu $a2, $v0, 1
/* 05A114 7F0255E4 1120001A */  beqz  $t1, .L7F025650
/* 05A118 7F0255E8 24A5F408 */   addiu $a1, %lo(ptr_pistol_firing_animation_groups) # addiu $a1, $a1, -0xbf8
/* 05A11C 7F0255EC 50400019 */  beql  $v0, $zero, .L7F025654
/* 05A120 7F0255F0 2CD90001 */   sltiu $t9, $a2, 1
/* 05A124 7F0255F4 0C002914 */  jal   randomGetNext
/* 05A128 7F0255F8 00000000 */   nop   
/* 05A12C 7F0255FC 30460001 */  andi  $a2, $v0, 1
/* 05A130 7F025600 0C002914 */  jal   randomGetNext
/* 05A134 7F025604 AFA60044 */   sw    $a2, 0x44($sp)
/* 05A138 7F025608 24010003 */  li    $at, 3
/* 05A13C 7F02560C 0041001B */  divu  $zero, $v0, $at
/* 05A140 7F025610 00005010 */  mfhi  $t2
/* 05A144 7F025614 8FA60044 */  lw    $a2, 0x44($sp)
/* 05A148 7F025618 15400007 */  bnez  $t2, .L7F025638
/* 05A14C 7F02561C 3C058003 */   lui   $a1, %hi(ptr_doubles_firing_animation_groups)
/* 05A150 7F025620 3C058003 */  lui   $a1, %hi(ptr_pistol_firing_animation_groups)
/* 05A154 7F025624 2CCB0001 */  sltiu $t3, $a2, 1
/* 05A158 7F025628 24A5F408 */  addiu $a1, %lo(ptr_pistol_firing_animation_groups) # addiu $a1, $a1, -0xbf8
/* 05A15C 7F02562C AFA6003C */  sw    $a2, 0x3c($sp)
/* 05A160 7F025630 10000022 */  b     .L7F0256BC
/* 05A164 7F025634 AFAB0038 */   sw    $t3, 0x38($sp)
.L7F025638:
/* 05A168 7F025638 240C0001 */  li    $t4, 1
/* 05A16C 7F02563C 240D0001 */  li    $t5, 1
/* 05A170 7F025640 24A5F6E0 */  addiu $a1, $a1, %lo(ptr_doubles_firing_animation_groups)
/* 05A174 7F025644 AFAC003C */  sw    $t4, 0x3c($sp)
/* 05A178 7F025648 1000001C */  b     .L7F0256BC
/* 05A17C 7F02564C AFAD0038 */   sw    $t5, 0x38($sp)
.L7F025650:
/* 05A180 7F025650 2CD90001 */  sltiu $t9, $a2, 1
.L7F025654:
/* 05A184 7F025654 AFA6003C */  sw    $a2, 0x3c($sp)
/* 05A188 7F025658 10000018 */  b     .L7F0256BC
/* 05A18C 7F02565C AFB90038 */   sw    $t9, 0x38($sp)
.L7F025660:
/* 05A190 7F025660 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05A194 7F025664 AFA50048 */   sw    $a1, 0x48($sp)
/* 05A198 7F025668 14400005 */  bnez  $v0, .L7F025680
/* 05A19C 7F02566C 8FA50048 */   lw    $a1, 0x48($sp)
/* 05A1A0 7F025670 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05A1A4 7F025674 00A02025 */   move  $a0, $a1
/* 05A1A8 7F025678 5040000A */  beql  $v0, $zero, .L7F0256A4
/* 05A1AC 7F02567C 8FA2004C */   lw    $v0, 0x4c($sp)
.L7F025680:
/* 05A1B0 7F025680 8FA2004C */  lw    $v0, 0x4c($sp)
/* 05A1B4 7F025684 3C058003 */  lui   $a1, %hi(ptr_pistol_firing_animation_groups)
/* 05A1B8 7F025688 24A5F408 */  addiu $a1, %lo(ptr_pistol_firing_animation_groups) # addiu $a1, $a1, -0xbf8
/* 05A1BC 7F02568C 0002302B */  sltu  $a2, $zero, $v0
/* 05A1C0 7F025690 2CCE0001 */  sltiu $t6, $a2, 1
/* 05A1C4 7F025694 AFA6003C */  sw    $a2, 0x3c($sp)
/* 05A1C8 7F025698 10000008 */  b     .L7F0256BC
/* 05A1CC 7F02569C AFAE0038 */   sw    $t6, 0x38($sp)
/* 05A1D0 7F0256A0 8FA2004C */  lw    $v0, 0x4c($sp)
.L7F0256A4:
/* 05A1D4 7F0256A4 3C058003 */  lui   $a1, %hi(ptr_rifle_firing_animation_groups)
/* 05A1D8 7F0256A8 24A5ED28 */  addiu $a1, %lo(ptr_rifle_firing_animation_groups) # addiu $a1, $a1, -0x12d8
/* 05A1DC 7F0256AC 0002302B */  sltu  $a2, $zero, $v0
/* 05A1E0 7F0256B0 2CC80001 */  sltiu $t0, $a2, 1
/* 05A1E4 7F0256B4 AFA6003C */  sw    $a2, 0x3c($sp)
/* 05A1E8 7F0256B8 AFA80038 */  sw    $t0, 0x38($sp)
.L7F0256BC:
/* 05A1EC 7F0256BC 8FA90054 */  lw    $t1, 0x54($sp)
/* 05A1F0 7F0256C0 8FAA0058 */  lw    $t2, 0x58($sp)
/* 05A1F4 7F0256C4 240B0001 */  li    $t3, 1
/* 05A1F8 7F0256C8 AFAB0018 */  sw    $t3, 0x18($sp)
/* 05A1FC 7F0256CC 8FA40050 */  lw    $a0, 0x50($sp)
/* 05A200 7F0256D0 27A70038 */  addiu $a3, $sp, 0x38
/* 05A204 7F0256D4 AFA90010 */  sw    $t1, 0x10($sp)
/* 05A208 7F0256D8 0FC0945B */  jal   sub_GAME_7F02516C
/* 05A20C 7F0256DC AFAA0014 */   sw    $t2, 0x14($sp)
/* 05A210 7F0256E0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 05A214 7F0256E4 27BD0050 */  addiu $sp, $sp, 0x50
/* 05A218 7F0256E8 03E00008 */  jr    $ra
/* 05A21C 7F0256EC 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0256F0(void) {
// very similar to sub_GAME_7F025560.
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0256F0
/* 05A220 7F0256F0 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 05A224 7F0256F4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 05A228 7F0256F8 AFA50054 */  sw    $a1, 0x54($sp)
/* 05A22C 7F0256FC AFA40050 */  sw    $a0, 0x50($sp)
/* 05A230 7F025700 AFA60058 */  sw    $a2, 0x58($sp)
/* 05A234 7F025704 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A238 7F025708 24050001 */   li    $a1, 1
/* 05A23C 7F02570C AFA2004C */  sw    $v0, 0x4c($sp)
/* 05A240 7F025710 8FA40050 */  lw    $a0, 0x50($sp)
/* 05A244 7F025714 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A248 7F025718 00002825 */   move  $a1, $zero
/* 05A24C 7F02571C 3C0F8003 */  lui   $t7, %hi(D_800309C0) 
/* 05A250 7F025720 25EF09C0 */  addiu $t7, %lo(D_800309C0) # addiu $t7, $t7, 0x9c0
/* 05A254 7F025724 8FA4004C */  lw    $a0, 0x4c($sp)
/* 05A258 7F025728 8DE10000 */  lw    $at, ($t7)
/* 05A25C 7F02572C 8DE80004 */  lw    $t0, 4($t7)
/* 05A260 7F025730 27AE0038 */  addiu $t6, $sp, 0x38
/* 05A264 7F025734 00402825 */  move  $a1, $v0
/* 05A268 7F025738 ADC10000 */  sw    $at, ($t6)
/* 05A26C 7F02573C 1080002C */  beqz  $a0, .L7F0257F0
/* 05A270 7F025740 ADC80004 */   sw    $t0, 4($t6)
/* 05A274 7F025744 1040002A */  beqz  $v0, .L7F0257F0
/* 05A278 7F025748 00000000 */   nop   
/* 05A27C 7F02574C 8FA40050 */  lw    $a0, 0x50($sp)
/* 05A280 7F025750 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05A284 7F025754 24050001 */   li    $a1, 1
/* 05A288 7F025758 AFA20034 */  sw    $v0, 0x34($sp)
/* 05A28C 7F02575C 8FA40050 */  lw    $a0, 0x50($sp)
/* 05A290 7F025760 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05A294 7F025764 00002825 */   move  $a1, $zero
/* 05A298 7F025768 8FA90034 */  lw    $t1, 0x34($sp)
/* 05A29C 7F02576C 3C058003 */  lui   $a1, %hi(ptr_crouched_pistol_firing_animation_groups)
/* 05A2A0 7F025770 2C460001 */  sltiu $a2, $v0, 1
/* 05A2A4 7F025774 1120001A */  beqz  $t1, .L7F0257E0
/* 05A2A8 7F025778 24A5FCD8 */   addiu $a1, %lo(ptr_crouched_pistol_firing_animation_groups) # addiu $a1, $a1, -0x328
/* 05A2AC 7F02577C 50400019 */  beql  $v0, $zero, .L7F0257E4
/* 05A2B0 7F025780 2CD90001 */   sltiu $t9, $a2, 1
/* 05A2B4 7F025784 0C002914 */  jal   randomGetNext
/* 05A2B8 7F025788 00000000 */   nop   
/* 05A2BC 7F02578C 30460001 */  andi  $a2, $v0, 1
/* 05A2C0 7F025790 0C002914 */  jal   randomGetNext
/* 05A2C4 7F025794 AFA60044 */   sw    $a2, 0x44($sp)
/* 05A2C8 7F025798 24010003 */  li    $at, 3
/* 05A2CC 7F02579C 0041001B */  divu  $zero, $v0, $at
/* 05A2D0 7F0257A0 00005010 */  mfhi  $t2
/* 05A2D4 7F0257A4 8FA60044 */  lw    $a2, 0x44($sp)
/* 05A2D8 7F0257A8 15400007 */  bnez  $t2, .L7F0257C8
/* 05A2DC 7F0257AC 3C058003 */   lui   $a1, %hi(ptr_crouched_doubles_firing_animation_groups)
/* 05A2E0 7F0257B0 3C058003 */  lui   $a1, %hi(ptr_crouched_pistol_firing_animation_groups)
/* 05A2E4 7F0257B4 2CCB0001 */  sltiu $t3, $a2, 1
/* 05A2E8 7F0257B8 24A5FCD8 */  addiu $a1, %lo(ptr_crouched_pistol_firing_animation_groups) # addiu $a1, $a1, -0x328
/* 05A2EC 7F0257BC AFA6003C */  sw    $a2, 0x3c($sp)
/* 05A2F0 7F0257C0 10000022 */  b     .L7F02584C
/* 05A2F4 7F0257C4 AFAB0038 */   sw    $t3, 0x38($sp)
.L7F0257C8:
/* 05A2F8 7F0257C8 240C0001 */  li    $t4, 1
/* 05A2FC 7F0257CC 240D0001 */  li    $t5, 1
/* 05A300 7F0257D0 24A5FFF8 */  addiu $a1, $a1, %lo(ptr_crouched_doubles_firing_animation_groups)
/* 05A304 7F0257D4 AFAC003C */  sw    $t4, 0x3c($sp)
/* 05A308 7F0257D8 1000001C */  b     .L7F02584C
/* 05A30C 7F0257DC AFAD0038 */   sw    $t5, 0x38($sp)
.L7F0257E0:
/* 05A310 7F0257E0 2CD90001 */  sltiu $t9, $a2, 1
.L7F0257E4:
/* 05A314 7F0257E4 AFA6003C */  sw    $a2, 0x3c($sp)
/* 05A318 7F0257E8 10000018 */  b     .L7F02584C
/* 05A31C 7F0257EC AFB90038 */   sw    $t9, 0x38($sp)
.L7F0257F0:
/* 05A320 7F0257F0 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05A324 7F0257F4 AFA50048 */   sw    $a1, 0x48($sp)
/* 05A328 7F0257F8 14400005 */  bnez  $v0, .L7F025810
/* 05A32C 7F0257FC 8FA50048 */   lw    $a1, 0x48($sp)
/* 05A330 7F025800 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05A334 7F025804 00A02025 */   move  $a0, $a1
/* 05A338 7F025808 5040000A */  beql  $v0, $zero, .L7F025834
/* 05A33C 7F02580C 8FA2004C */   lw    $v0, 0x4c($sp)
.L7F025810:
/* 05A340 7F025810 8FA2004C */  lw    $v0, 0x4c($sp)
/* 05A344 7F025814 3C058003 */  lui   $a1, %hi(ptr_crouched_pistol_firing_animation_groups)
/* 05A348 7F025818 24A5FCD8 */  addiu $a1, %lo(ptr_crouched_pistol_firing_animation_groups) # addiu $a1, $a1, -0x328
/* 05A34C 7F02581C 0002302B */  sltu  $a2, $zero, $v0
/* 05A350 7F025820 2CCE0001 */  sltiu $t6, $a2, 1
/* 05A354 7F025824 AFA6003C */  sw    $a2, 0x3c($sp)
/* 05A358 7F025828 10000008 */  b     .L7F02584C
/* 05A35C 7F02582C AFAE0038 */   sw    $t6, 0x38($sp)
/* 05A360 7F025830 8FA2004C */  lw    $v0, 0x4c($sp)
.L7F025834:
/* 05A364 7F025834 3C058003 */  lui   $a1, %hi(ptr_crouched_rifle_firing_animation_groups)
/* 05A368 7F025838 24A5F970 */  addiu $a1, %lo(ptr_crouched_rifle_firing_animation_groups) # addiu $a1, $a1, -0x690
/* 05A36C 7F02583C 0002302B */  sltu  $a2, $zero, $v0
/* 05A370 7F025840 2CC80001 */  sltiu $t0, $a2, 1
/* 05A374 7F025844 AFA6003C */  sw    $a2, 0x3c($sp)
/* 05A378 7F025848 AFA80038 */  sw    $t0, 0x38($sp)
.L7F02584C:
/* 05A37C 7F02584C 8FA90054 */  lw    $t1, 0x54($sp)
/* 05A380 7F025850 8FAA0058 */  lw    $t2, 0x58($sp)
/* 05A384 7F025854 8FA40050 */  lw    $a0, 0x50($sp)
/* 05A388 7F025858 27A70038 */  addiu $a3, $sp, 0x38
/* 05A38C 7F02585C AFA00018 */  sw    $zero, 0x18($sp)
/* 05A390 7F025860 AFA90010 */  sw    $t1, 0x10($sp)
/* 05A394 7F025864 0FC0945B */  jal   sub_GAME_7F02516C
/* 05A398 7F025868 AFAA0014 */   sw    $t2, 0x14($sp)
/* 05A39C 7F02586C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 05A3A0 7F025870 27BD0050 */  addiu $sp, $sp, 0x50
/* 05A3A4 7F025874 03E00008 */  jr    $ra
/* 05A3A8 7F025878 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02587C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02587C
/* 05A3AC 7F02587C 27BDFF78 */  addiu $sp, $sp, -0x88
/* 05A3B0 7F025880 AFB20024 */  sw    $s2, 0x24($sp)
/* 05A3B4 7F025884 00A09025 */  move  $s2, $a1
/* 05A3B8 7F025888 AFBF0034 */  sw    $ra, 0x34($sp)
/* 05A3BC 7F02588C AFB50030 */  sw    $s5, 0x30($sp)
/* 05A3C0 7F025890 0080A825 */  move  $s5, $a0
/* 05A3C4 7F025894 AFB4002C */  sw    $s4, 0x2c($sp)
/* 05A3C8 7F025898 AFB30028 */  sw    $s3, 0x28($sp)
/* 05A3CC 7F02589C AFB10020 */  sw    $s1, 0x20($sp)
/* 05A3D0 7F0258A0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 05A3D4 7F0258A4 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A3D8 7F0258A8 24050001 */   li    $a1, 1
/* 05A3DC 7F0258AC 00408025 */  move  $s0, $v0
/* 05A3E0 7F0258B0 02A02025 */  move  $a0, $s5
/* 05A3E4 7F0258B4 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A3E8 7F0258B8 00002825 */   move  $a1, $zero
/* 05A3EC 7F0258BC 3C0F8003 */  lui   $t7, %hi(D_800309C8) 
/* 05A3F0 7F0258C0 25EF09C8 */  addiu $t7, %lo(D_800309C8) # addiu $t7, $t7, 0x9c8
/* 05A3F4 7F0258C4 8DE10000 */  lw    $at, ($t7)
/* 05A3F8 7F0258C8 8DE80004 */  lw    $t0, 4($t7)
/* 05A3FC 7F0258CC 27AE0070 */  addiu $t6, $sp, 0x70
/* 05A400 7F0258D0 3C0A8003 */  lui   $t2, %hi(D_800309D0) 
/* 05A404 7F0258D4 254A09D0 */  addiu $t2, %lo(D_800309D0) # addiu $t2, $t2, 0x9d0
/* 05A408 7F0258D8 ADC10000 */  sw    $at, ($t6)
/* 05A40C 7F0258DC ADC80004 */  sw    $t0, 4($t6)
/* 05A410 7F0258E0 8D4D0004 */  lw    $t5, 4($t2)
/* 05A414 7F0258E4 8D410000 */  lw    $at, ($t2)
/* 05A418 7F0258E8 27A90068 */  addiu $t1, $sp, 0x68
/* 05A41C 7F0258EC 3C188003 */  lui   $t8, %hi(D_800309D8) 
/* 05A420 7F0258F0 271809D8 */  addiu $t8, %lo(D_800309D8) # addiu $t8, $t8, 0x9d8
/* 05A424 7F0258F4 AD2D0004 */  sw    $t5, 4($t1)
/* 05A428 7F0258F8 AD210000 */  sw    $at, ($t1)
/* 05A42C 7F0258FC 8F080004 */  lw    $t0, 4($t8)
/* 05A430 7F025900 8F010000 */  lw    $at, ($t8)
/* 05A434 7F025904 27B90060 */  addiu $t9, $sp, 0x60
/* 05A438 7F025908 00408825 */  move  $s1, $v0
/* 05A43C 7F02590C AF280004 */  sw    $t0, 4($t9)
/* 05A440 7F025910 12000045 */  beqz  $s0, .L7F025A28
/* 05A444 7F025914 AF210000 */   sw    $at, ($t9)
/* 05A448 7F025918 10400043 */  beqz  $v0, .L7F025A28
/* 05A44C 7F02591C 02A02025 */   move  $a0, $s5
/* 05A450 7F025920 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05A454 7F025924 24050001 */   li    $a1, 1
/* 05A458 7F025928 00408025 */  move  $s0, $v0
/* 05A45C 7F02592C 02A02025 */  move  $a0, $s5
/* 05A460 7F025930 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05A464 7F025934 00002825 */   move  $a1, $zero
/* 05A468 7F025938 1200000D */  beqz  $s0, .L7F025970
/* 05A46C 7F02593C 00001825 */   move  $v1, $zero
/* 05A470 7F025940 5040000C */  beql  $v0, $zero, .L7F025974
/* 05A474 7F025944 2C4B0001 */   sltiu $t3, $v0, 1
/* 05A478 7F025948 0C002914 */  jal   randomGetNext
/* 05A47C 7F02594C 00000000 */   nop   
/* 05A480 7F025950 304C0001 */  andi  $t4, $v0, 1
/* 05A484 7F025954 0C002914 */  jal   randomGetNext
/* 05A488 7F025958 AFAC0078 */   sw    $t4, 0x78($sp)
/* 05A48C 7F02595C 24010003 */  li    $at, 3
/* 05A490 7F025960 0041001B */  divu  $zero, $v0, $at
/* 05A494 7F025964 00001810 */  mfhi  $v1
/* 05A498 7F025968 10000003 */  b     .L7F025978
/* 05A49C 7F02596C 00000000 */   nop   
.L7F025970:
/* 05A4A0 7F025970 2C4B0001 */  sltiu $t3, $v0, 1
.L7F025974:
/* 05A4A4 7F025974 AFAB0078 */  sw    $t3, 0x78($sp)
.L7F025978:
/* 05A4A8 7F025978 14600013 */  bnez  $v1, .L7F0259C8
/* 05A4AC 7F02597C 24140001 */   li    $s4, 1
/* 05A4B0 7F025980 12400005 */  beqz  $s2, .L7F025998
/* 05A4B4 7F025984 3C0A8003 */   lui   $t2, %hi(D_800306F0) 
/* 05A4B8 7F025988 3C098003 */  lui   $t1, %hi(D_80030738) 
/* 05A4BC 7F02598C 25290738 */  addiu $t1, %lo(D_80030738) # addiu $t1, $t1, 0x738
/* 05A4C0 7F025990 10000003 */  b     .L7F0259A0
/* 05A4C4 7F025994 AFA90084 */   sw    $t1, 0x84($sp)
.L7F025998:
/* 05A4C8 7F025998 254A06F0 */  addiu $t2, %lo(D_800306F0) # addiu $t2, $t2, 0x6f0
/* 05A4CC 7F02599C AFAA0084 */  sw    $t2, 0x84($sp)
.L7F0259A0:
/* 05A4D0 7F0259A0 8FAD0078 */  lw    $t5, 0x78($sp)
/* 05A4D4 7F0259A4 240F0001 */  li    $t7, 1
/* 05A4D8 7F0259A8 24020001 */  li    $v0, 1
/* 05A4DC 7F0259AC 11A00003 */  beqz  $t5, .L7F0259BC
/* 05A4E0 7F0259B0 24140001 */   li    $s4, 1
/* 05A4E4 7F0259B4 10000048 */  b     .L7F025AD8
/* 05A4E8 7F0259B8 AFAF0074 */   sw    $t7, 0x74($sp)
.L7F0259BC:
/* 05A4EC 7F0259BC AFA20070 */  sw    $v0, 0x70($sp)
/* 05A4F0 7F0259C0 10000045 */  b     .L7F025AD8
/* 05A4F4 7F0259C4 24140001 */   li    $s4, 1
.L7F0259C8:
/* 05A4F8 7F0259C8 1474000C */  bne   $v1, $s4, .L7F0259FC
/* 05A4FC 7F0259CC 00000000 */   nop   
/* 05A500 7F0259D0 12400005 */  beqz  $s2, .L7F0259E8
/* 05A504 7F0259D4 3C198003 */   lui   $t9, %hi(D_80030780) 
/* 05A508 7F0259D8 3C0E8003 */  lui   $t6, %hi(D_800307C8) 
/* 05A50C 7F0259DC 25CE07C8 */  addiu $t6, %lo(D_800307C8) # addiu $t6, $t6, 0x7c8
/* 05A510 7F0259E0 10000003 */  b     .L7F0259F0
/* 05A514 7F0259E4 AFAE0084 */   sw    $t6, 0x84($sp)
.L7F0259E8:
/* 05A518 7F0259E8 27390780 */  addiu $t9, %lo(D_80030780) # addiu $t9, $t9, 0x780
/* 05A51C 7F0259EC AFB90084 */  sw    $t9, 0x84($sp)
.L7F0259F0:
/* 05A520 7F0259F0 AFB40074 */  sw    $s4, 0x74($sp)
/* 05A524 7F0259F4 10000038 */  b     .L7F025AD8
/* 05A528 7F0259F8 AFB40070 */   sw    $s4, 0x70($sp)
.L7F0259FC:
/* 05A52C 7F0259FC 12400005 */  beqz  $s2, .L7F025A14
/* 05A530 7F025A00 3C088003 */   lui   $t0, %hi(D_80030810) 
/* 05A534 7F025A04 3C188003 */  lui   $t8, %hi(D_80030858) 
/* 05A538 7F025A08 27180858 */  addiu $t8, %lo(D_80030858) # addiu $t8, $t8, 0x858
/* 05A53C 7F025A0C 10000003 */  b     .L7F025A1C
/* 05A540 7F025A10 AFB80084 */   sw    $t8, 0x84($sp)
.L7F025A14:
/* 05A544 7F025A14 25080810 */  addiu $t0, %lo(D_80030810) # addiu $t0, $t0, 0x810
/* 05A548 7F025A18 AFA80084 */  sw    $t0, 0x84($sp)
.L7F025A1C:
/* 05A54C 7F025A1C AFB40074 */  sw    $s4, 0x74($sp)
/* 05A550 7F025A20 1000002D */  b     .L7F025AD8
/* 05A554 7F025A24 AFB40070 */   sw    $s4, 0x70($sp)
.L7F025A28:
/* 05A558 7F025A28 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05A55C 7F025A2C 02002025 */   move  $a0, $s0
/* 05A560 7F025A30 54400005 */  bnezl $v0, .L7F025A48
/* 05A564 7F025A34 0010102B */   sltu  $v0, $zero, $s0
/* 05A568 7F025A38 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05A56C 7F025A3C 02202025 */   move  $a0, $s1
/* 05A570 7F025A40 10400013 */  beqz  $v0, .L7F025A90
/* 05A574 7F025A44 0010102B */   sltu  $v0, $zero, $s0
.L7F025A48:
/* 05A578 7F025A48 12400005 */  beqz  $s2, .L7F025A60
/* 05A57C 7F025A4C AFA20078 */   sw    $v0, 0x78($sp)
/* 05A580 7F025A50 3C0C8003 */  lui   $t4, %hi(D_80030738) 
/* 05A584 7F025A54 258C0738 */  addiu $t4, %lo(D_80030738) # addiu $t4, $t4, 0x738
/* 05A588 7F025A58 10000004 */  b     .L7F025A6C
/* 05A58C 7F025A5C AFAC0084 */   sw    $t4, 0x84($sp)
.L7F025A60:
/* 05A590 7F025A60 3C0B8003 */  lui   $t3, %hi(D_800306F0) 
/* 05A594 7F025A64 256B06F0 */  addiu $t3, %lo(D_800306F0) # addiu $t3, $t3, 0x6f0
/* 05A598 7F025A68 AFAB0084 */  sw    $t3, 0x84($sp)
.L7F025A6C:
/* 05A59C 7F025A6C 10400004 */  beqz  $v0, .L7F025A80
/* 05A5A0 7F025A70 24090001 */   li    $t1, 1
/* 05A5A4 7F025A74 AFA90074 */  sw    $t1, 0x74($sp)
/* 05A5A8 7F025A78 10000017 */  b     .L7F025AD8
/* 05A5AC 7F025A7C 24140001 */   li    $s4, 1
.L7F025A80:
/* 05A5B0 7F025A80 24020001 */  li    $v0, 1
/* 05A5B4 7F025A84 AFA20070 */  sw    $v0, 0x70($sp)
/* 05A5B8 7F025A88 10000013 */  b     .L7F025AD8
/* 05A5BC 7F025A8C 24140001 */   li    $s4, 1
.L7F025A90:
/* 05A5C0 7F025A90 0010102B */  sltu  $v0, $zero, $s0
/* 05A5C4 7F025A94 12400005 */  beqz  $s2, .L7F025AAC
/* 05A5C8 7F025A98 AFA20078 */   sw    $v0, 0x78($sp)
/* 05A5CC 7F025A9C 3C0A8003 */  lui   $t2, %hi(D_800306A8) 
/* 05A5D0 7F025AA0 254A06A8 */  addiu $t2, %lo(D_800306A8) # addiu $t2, $t2, 0x6a8
/* 05A5D4 7F025AA4 10000004 */  b     .L7F025AB8
/* 05A5D8 7F025AA8 AFAA0084 */   sw    $t2, 0x84($sp)
.L7F025AAC:
/* 05A5DC 7F025AAC 3C0D8003 */  lui   $t5, %hi(D_80030660) 
/* 05A5E0 7F025AB0 25AD0660 */  addiu $t5, %lo(D_80030660) # addiu $t5, $t5, 0x660
/* 05A5E4 7F025AB4 AFAD0084 */  sw    $t5, 0x84($sp)
.L7F025AB8:
/* 05A5E8 7F025AB8 10400005 */  beqz  $v0, .L7F025AD0
/* 05A5EC 7F025ABC 24140001 */   li    $s4, 1
/* 05A5F0 7F025AC0 240F0001 */  li    $t7, 1
/* 05A5F4 7F025AC4 AFAF0074 */  sw    $t7, 0x74($sp)
/* 05A5F8 7F025AC8 10000003 */  b     .L7F025AD8
/* 05A5FC 7F025ACC 24140001 */   li    $s4, 1
.L7F025AD0:
/* 05A600 7F025AD0 24020001 */  li    $v0, 1
/* 05A604 7F025AD4 AFA20070 */  sw    $v0, 0x70($sp)
.L7F025AD8:
/* 05A608 7F025AD8 00008825 */  move  $s1, $zero
/* 05A60C 7F025ADC 00009025 */  move  $s2, $zero
/* 05A610 7F025AE0 27B30070 */  addiu $s3, $sp, 0x70
.L7F025AE4:
/* 05A614 7F025AE4 8E6E0000 */  lw    $t6, ($s3)
/* 05A618 7F025AE8 02A02025 */  move  $a0, $s5
/* 05A61C 7F025AEC 51C00012 */  beql  $t6, $zero, .L7F025B38
/* 05A620 7F025AF0 26310001 */   addiu $s1, $s1, 1
/* 05A624 7F025AF4 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A628 7F025AF8 02202825 */   move  $a1, $s1
/* 05A62C 7F025AFC 8C500004 */  lw    $s0, 4($v0)
/* 05A630 7F025B00 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 05A634 7F025B04 82040080 */   lb    $a0, 0x80($s0)
/* 05A638 7F025B08 04410002 */  bgez  $v0, .L7F025B14
/* 05A63C 7F025B0C 03B2C821 */   addu  $t9, $sp, $s2
/* 05A640 7F025B10 AF340068 */  sw    $s4, 0x68($t9)
.L7F025B14:
/* 05A644 7F025B14 82020080 */  lb    $v0, 0x80($s0)
/* 05A648 7F025B18 24010019 */  li    $at, 25
/* 05A64C 7F025B1C 03B2C021 */  addu  $t8, $sp, $s2
/* 05A650 7F025B20 10410003 */  beq   $v0, $at, .L7F025B30
/* 05A654 7F025B24 24010018 */   li    $at, 24
/* 05A658 7F025B28 54410003 */  bnel  $v0, $at, .L7F025B38
/* 05A65C 7F025B2C 26310001 */   addiu $s1, $s1, 1
.L7F025B30:
/* 05A660 7F025B30 AF140060 */  sw    $s4, 0x60($t8)
/* 05A664 7F025B34 26310001 */  addiu $s1, $s1, 1
.L7F025B38:
/* 05A668 7F025B38 24010002 */  li    $at, 2
/* 05A66C 7F025B3C 26520004 */  addiu $s2, $s2, 4
/* 05A670 7F025B40 1621FFE8 */  bne   $s1, $at, .L7F025AE4
/* 05A674 7F025B44 26730004 */   addiu $s3, $s3, 4
/* 05A678 7F025B48 24080009 */  li    $t0, 9
/* 05A67C 7F025B4C A2A80007 */  sb    $t0, 7($s5)
/* 05A680 7F025B50 0C002914 */  jal   randomGetNext
/* 05A684 7F025B54 AEA00030 */   sw    $zero, 0x30($s5)
/* 05A688 7F025B58 3C0143C8 */  li    $at, 0x43C80000 # 400.000000
/* 05A68C 7F025B5C 44812000 */  mtc1  $at, $f4
/* 05A690 7F025B60 3C018003 */  lui   $at, %hi(g_AiReactionSpeed)
/* 05A694 7F025B64 C426CE4C */  lwc1  $f6, %lo(g_AiReactionSpeed)($at)
/* 05A698 7F025B68 AEA00038 */  sw    $zero, 0x38($s5)
/* 05A69C 7F025B6C 46062202 */  mul.s $f8, $f4, $f6
/* 05A6A0 7F025B70 4600428D */  trunc.w.s $f10, $f8
/* 05A6A4 7F025B74 440B5000 */  mfc1  $t3, $f10
/* 05A6A8 7F025B78 00000000 */  nop   
/* 05A6AC 7F025B7C 004B001B */  divu  $zero, $v0, $t3
/* 05A6B0 7F025B80 00004810 */  mfhi  $t1
/* 05A6B4 7F025B84 252A0078 */  addiu $t2, $t1, 0x78
/* 05A6B8 7F025B88 AEAA0034 */  sw    $t2, 0x34($s5)
/* 05A6BC 7F025B8C 8FAD0084 */  lw    $t5, 0x84($sp)
/* 05A6C0 7F025B90 15600002 */  bnez  $t3, .L7F025B9C
/* 05A6C4 7F025B94 00000000 */   nop   
/* 05A6C8 7F025B98 0007000D */  break 7
.L7F025B9C:
/* 05A6CC 7F025B9C AEA00040 */  sw    $zero, 0x40($s5)
/* 05A6D0 7F025BA0 0C002914 */  jal   randomGetNext
/* 05A6D4 7F025BA4 AEAD003C */   sw    $t5, 0x3c($s5)
/* 05A6D8 7F025BA8 304F0001 */  andi  $t7, $v0, 1
/* 05A6DC 7F025BAC AEAF0044 */  sw    $t7, 0x44($s5)
/* 05A6E0 7F025BB0 8FAE0074 */  lw    $t6, 0x74($sp)
/* 05A6E4 7F025BB4 44808000 */  mtc1  $zero, $f16
/* 05A6E8 7F025BB8 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 05A6EC 7F025BBC A2AE0049 */  sb    $t6, 0x49($s5)
/* 05A6F0 7F025BC0 8FB90070 */  lw    $t9, 0x70($sp)
/* 05A6F4 7F025BC4 44819000 */  mtc1  $at, $f18
/* 05A6F8 7F025BC8 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 05A6FC 7F025BCC A2B90048 */  sb    $t9, 0x48($s5)
/* 05A700 7F025BD0 8FB8006C */  lw    $t8, 0x6c($sp)
/* 05A704 7F025BD4 44812000 */  mtc1  $at, $f4
/* 05A708 7F025BD8 8EA4001C */  lw    $a0, 0x1c($s5)
/* 05A70C 7F025BDC A2B8004B */  sb    $t8, 0x4b($s5)
/* 05A710 7F025BE0 8FA80068 */  lw    $t0, 0x68($sp)
/* 05A714 7F025BE4 A2A8004A */  sb    $t0, 0x4a($s5)
/* 05A718 7F025BE8 8FAC0064 */  lw    $t4, 0x64($sp)
/* 05A71C 7F025BEC A2AC004D */  sb    $t4, 0x4d($s5)
/* 05A720 7F025BF0 8FAB0060 */  lw    $t3, 0x60($sp)
/* 05A724 7F025BF4 A2A00008 */  sb    $zero, 8($s5)
/* 05A728 7F025BF8 E6B00054 */  swc1  $f16, 0x54($s5)
/* 05A72C 7F025BFC A2AB004C */  sb    $t3, 0x4c($s5)
/* 05A730 7F025C00 8FA90084 */  lw    $t1, 0x84($sp)
/* 05A734 7F025C04 8FA60078 */  lw    $a2, 0x78($sp)
/* 05A738 7F025C08 8D250000 */  lw    $a1, ($t1)
/* 05A73C 7F025C0C 8D270010 */  lw    $a3, 0x10($t1)
/* 05A740 7F025C10 E7B20010 */  swc1  $f18, 0x10($sp)
/* 05A744 7F025C14 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 05A748 7F025C18 E7A40014 */   swc1  $f4, 0x14($sp)
/* 05A74C 7F025C1C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 05A750 7F025C20 8FB0001C */  lw    $s0, 0x1c($sp)
/* 05A754 7F025C24 8FB10020 */  lw    $s1, 0x20($sp)
/* 05A758 7F025C28 8FB20024 */  lw    $s2, 0x24($sp)
/* 05A75C 7F025C2C 8FB30028 */  lw    $s3, 0x28($sp)
/* 05A760 7F025C30 8FB4002C */  lw    $s4, 0x2c($sp)
/* 05A764 7F025C34 8FB50030 */  lw    $s5, 0x30($sp)
/* 05A768 7F025C38 03E00008 */  jr    $ra
/* 05A76C 7F025C3C 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F025C40(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F025C40
/* 05A770 7F025C40 27BDFF70 */  addiu $sp, $sp, -0x90
/* 05A774 7F025C44 AFBF002C */  sw    $ra, 0x2c($sp)
/* 05A778 7F025C48 AFB30028 */  sw    $s3, 0x28($sp)
/* 05A77C 7F025C4C AFB20024 */  sw    $s2, 0x24($sp)
/* 05A780 7F025C50 AFB10020 */  sw    $s1, 0x20($sp)
/* 05A784 7F025C54 AFB0001C */  sw    $s0, 0x1c($sp)
/* 05A788 7F025C58 AFA50094 */  sw    $a1, 0x94($sp)
/* 05A78C 7F025C5C 8C8E001C */  lw    $t6, 0x1c($a0)
/* 05A790 7F025C60 00809025 */  move  $s2, $a0
/* 05A794 7F025C64 24050001 */  li    $a1, 1
/* 05A798 7F025C68 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A79C 7F025C6C AFAE008C */   sw    $t6, 0x8c($sp)
/* 05A7A0 7F025C70 00408025 */  move  $s0, $v0
/* 05A7A4 7F025C74 02402025 */  move  $a0, $s2
/* 05A7A8 7F025C78 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A7AC 7F025C7C 00002825 */   move  $a1, $zero
/* 05A7B0 7F025C80 3C188003 */  lui   $t8, %hi(D_800309E0) 
/* 05A7B4 7F025C84 AFA00078 */  sw    $zero, 0x78($sp)
/* 05A7B8 7F025C88 271809E0 */  addiu $t8, %lo(D_800309E0) # addiu $t8, $t8, 0x9e0
/* 05A7BC 7F025C8C 8F010000 */  lw    $at, ($t8)
/* 05A7C0 7F025C90 8F090004 */  lw    $t1, 4($t8)
/* 05A7C4 7F025C94 27AF0064 */  addiu $t7, $sp, 0x64
/* 05A7C8 7F025C98 3C0B8003 */  lui   $t3, %hi(D_800309E8) 
/* 05A7CC 7F025C9C ADE10000 */  sw    $at, ($t7)
/* 05A7D0 7F025CA0 ADE90004 */  sw    $t1, 4($t7)
/* 05A7D4 7F025CA4 AFA0005C */  sw    $zero, 0x5c($sp)
/* 05A7D8 7F025CA8 256B09E8 */  addiu $t3, %lo(D_800309E8) # addiu $t3, $t3, 0x9e8
/* 05A7DC 7F025CAC 8D610000 */  lw    $at, ($t3)
/* 05A7E0 7F025CB0 8D6E0004 */  lw    $t6, 4($t3)
/* 05A7E4 7F025CB4 27AA0054 */  addiu $t2, $sp, 0x54
/* 05A7E8 7F025CB8 3C198003 */  lui   $t9, %hi(D_800309F0) 
/* 05A7EC 7F025CBC 273909F0 */  addiu $t9, %lo(D_800309F0) # addiu $t9, $t9, 0x9f0
/* 05A7F0 7F025CC0 AD410000 */  sw    $at, ($t2)
/* 05A7F4 7F025CC4 AD4E0004 */  sw    $t6, 4($t2)
/* 05A7F8 7F025CC8 8F290004 */  lw    $t1, 4($t9)
/* 05A7FC 7F025CCC 8F210000 */  lw    $at, ($t9)
/* 05A800 7F025CD0 27A8004C */  addiu $t0, $sp, 0x4c
/* 05A804 7F025CD4 00408825 */  move  $s1, $v0
/* 05A808 7F025CD8 24130001 */  li    $s3, 1
/* 05A80C 7F025CDC AD090004 */  sw    $t1, 4($t0)
/* 05A810 7F025CE0 12000029 */  beqz  $s0, .L7F025D88
/* 05A814 7F025CE4 AD010000 */   sw    $at, ($t0)
/* 05A818 7F025CE8 10400027 */  beqz  $v0, .L7F025D88
/* 05A81C 7F025CEC 02402025 */   move  $a0, $s2
/* 05A820 7F025CF0 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05A824 7F025CF4 24050001 */   li    $a1, 1
/* 05A828 7F025CF8 00408025 */  move  $s0, $v0
/* 05A82C 7F025CFC 02402025 */  move  $a0, $s2
/* 05A830 7F025D00 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05A834 7F025D04 00002825 */   move  $a1, $zero
/* 05A838 7F025D08 12000018 */  beqz  $s0, .L7F025D6C
/* 05A83C 7F025D0C 2C430001 */   sltiu $v1, $v0, 1
/* 05A840 7F025D10 50400017 */  beql  $v0, $zero, .L7F025D70
/* 05A844 7F025D14 24080001 */   li    $t0, 1
/* 05A848 7F025D18 0C002914 */  jal   randomGetNext
/* 05A84C 7F025D1C 00000000 */   nop   
/* 05A850 7F025D20 304D0001 */  andi  $t5, $v0, 1
/* 05A854 7F025D24 240C0001 */  li    $t4, 1
/* 05A858 7F025D28 AFAD007C */  sw    $t5, 0x7c($sp)
/* 05A85C 7F025D2C 0C002914 */  jal   randomGetNext
/* 05A860 7F025D30 AFAC0078 */   sw    $t4, 0x78($sp)
/* 05A864 7F025D34 24010003 */  li    $at, 3
/* 05A868 7F025D38 0041001B */  divu  $zero, $v0, $at
/* 05A86C 7F025D3C 00005010 */  mfhi  $t2
/* 05A870 7F025D40 24180001 */  li    $t8, 1
/* 05A874 7F025D44 15400006 */  bnez  $t2, .L7F025D60
/* 05A878 7F025D48 240F0001 */   li    $t7, 1
/* 05A87C 7F025D4C 8FAB007C */  lw    $t3, 0x7c($sp)
/* 05A880 7F025D50 2D6E0001 */  sltiu $t6, $t3, 1
/* 05A884 7F025D54 AFAE0064 */  sw    $t6, 0x64($sp)
/* 05A888 7F025D58 1000001F */  b     .L7F025DD8
/* 05A88C 7F025D5C AFAB0068 */   sw    $t3, 0x68($sp)
.L7F025D60:
/* 05A890 7F025D60 AFB80068 */  sw    $t8, 0x68($sp)
/* 05A894 7F025D64 1000001C */  b     .L7F025DD8
/* 05A898 7F025D68 AFAF0064 */   sw    $t7, 0x64($sp)
.L7F025D6C:
/* 05A89C 7F025D6C 24080001 */  li    $t0, 1
.L7F025D70:
/* 05A8A0 7F025D70 2C790001 */  sltiu $t9, $v1, 1
/* 05A8A4 7F025D74 AFA3007C */  sw    $v1, 0x7c($sp)
/* 05A8A8 7F025D78 AFA80078 */  sw    $t0, 0x78($sp)
/* 05A8AC 7F025D7C AFA30068 */  sw    $v1, 0x68($sp)
/* 05A8B0 7F025D80 10000015 */  b     .L7F025DD8
/* 05A8B4 7F025D84 AFB90064 */   sw    $t9, 0x64($sp)
.L7F025D88:
/* 05A8B8 7F025D88 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05A8BC 7F025D8C 02002025 */   move  $a0, $s0
/* 05A8C0 7F025D90 54400005 */  bnezl $v0, .L7F025DA8
/* 05A8C4 7F025D94 0010102B */   sltu  $v0, $zero, $s0
/* 05A8C8 7F025D98 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05A8CC 7F025D9C 02202025 */   move  $a0, $s1
/* 05A8D0 7F025DA0 10400008 */  beqz  $v0, .L7F025DC4
/* 05A8D4 7F025DA4 0010102B */   sltu  $v0, $zero, $s0
.L7F025DA8:
/* 05A8D8 7F025DA8 24090001 */  li    $t1, 1
/* 05A8DC 7F025DAC 2C4D0001 */  sltiu $t5, $v0, 1
/* 05A8E0 7F025DB0 AFA2007C */  sw    $v0, 0x7c($sp)
/* 05A8E4 7F025DB4 AFA90078 */  sw    $t1, 0x78($sp)
/* 05A8E8 7F025DB8 AFA20068 */  sw    $v0, 0x68($sp)
/* 05A8EC 7F025DBC 10000006 */  b     .L7F025DD8
/* 05A8F0 7F025DC0 AFAD0064 */   sw    $t5, 0x64($sp)
.L7F025DC4:
/* 05A8F4 7F025DC4 0010102B */  sltu  $v0, $zero, $s0
/* 05A8F8 7F025DC8 2C4C0001 */  sltiu $t4, $v0, 1
/* 05A8FC 7F025DCC AFA2007C */  sw    $v0, 0x7c($sp)
/* 05A900 7F025DD0 AFA20068 */  sw    $v0, 0x68($sp)
/* 05A904 7F025DD4 AFAC0064 */  sw    $t4, 0x64($sp)
.L7F025DD8:
/* 05A908 7F025DD8 8FA20094 */  lw    $v0, 0x94($sp)
/* 05A90C 7F025DDC 8FAA007C */  lw    $t2, 0x7c($sp)
/* 05A910 7F025DE0 10400003 */  beqz  $v0, .L7F025DF0
/* 05A914 7F025DE4 00000000 */   nop   
/* 05A918 7F025DE8 11400005 */  beqz  $t2, .L7F025E00
/* 05A91C 7F025DEC 00000000 */   nop   
.L7F025DF0:
/* 05A920 7F025DF0 1440000F */  bnez  $v0, .L7F025E30
/* 05A924 7F025DF4 8FAB007C */   lw    $t3, 0x7c($sp)
/* 05A928 7F025DF8 1160000D */  beqz  $t3, .L7F025E30
/* 05A92C 7F025DFC 00000000 */   nop   
.L7F025E00:
/* 05A930 7F025E00 0C002914 */  jal   randomGetNext
/* 05A934 7F025E04 00000000 */   nop   
/* 05A938 7F025E08 304E0001 */  andi  $t6, $v0, 1
/* 05A93C 7F025E0C 11C00005 */  beqz  $t6, .L7F025E24
/* 05A940 7F025E10 3C0F8003 */   lui   $t7, %hi(D_80030108) 
/* 05A944 7F025E14 3C188003 */  lui   $t8, %hi(D_80030078) 
/* 05A948 7F025E18 27180078 */  addiu $t8, %lo(D_80030078) # addiu $t8, $t8, 0x78
/* 05A94C 7F025E1C 1000000F */  b     .L7F025E5C
/* 05A950 7F025E20 AFB80088 */   sw    $t8, 0x88($sp)
.L7F025E24:
/* 05A954 7F025E24 25EF0108 */  addiu $t7, %lo(D_80030108) # addiu $t7, $t7, 0x108
/* 05A958 7F025E28 1000000C */  b     .L7F025E5C
/* 05A95C 7F025E2C AFAF0088 */   sw    $t7, 0x88($sp)
.L7F025E30:
/* 05A960 7F025E30 0C002914 */  jal   randomGetNext
/* 05A964 7F025E34 00000000 */   nop   
/* 05A968 7F025E38 30480001 */  andi  $t0, $v0, 1
/* 05A96C 7F025E3C 11000005 */  beqz  $t0, .L7F025E54
/* 05A970 7F025E40 3C098003 */   lui   $t1, %hi(D_80030150) 
/* 05A974 7F025E44 3C198003 */  lui   $t9, %hi(D_800300C0) 
/* 05A978 7F025E48 273900C0 */  addiu $t9, %lo(D_800300C0) # addiu $t9, $t9, 0xc0
/* 05A97C 7F025E4C 10000003 */  b     .L7F025E5C
/* 05A980 7F025E50 AFB90088 */   sw    $t9, 0x88($sp)
.L7F025E54:
/* 05A984 7F025E54 25290150 */  addiu $t1, %lo(D_80030150) # addiu $t1, $t1, 0x150
/* 05A988 7F025E58 AFA90088 */  sw    $t1, 0x88($sp)
.L7F025E5C:
/* 05A98C 7F025E5C 8FAD0078 */  lw    $t5, 0x78($sp)
/* 05A990 7F025E60 00008025 */  move  $s0, $zero
/* 05A994 7F025E64 00003025 */  move  $a2, $zero
/* 05A998 7F025E68 11A00004 */  beqz  $t5, .L7F025E7C
/* 05A99C 7F025E6C 27A70064 */   addiu $a3, $sp, 0x64
/* 05A9A0 7F025E70 8FAC0088 */  lw    $t4, 0x88($sp)
/* 05A9A4 7F025E74 258A0120 */  addiu $t2, $t4, 0x120
/* 05A9A8 7F025E78 AFAA0088 */  sw    $t2, 0x88($sp)
.L7F025E7C:
/* 05A9AC 7F025E7C 24110001 */  li    $s1, 1
.L7F025E80:
/* 05A9B0 7F025E80 8CEB0000 */  lw    $t3, ($a3)
/* 05A9B4 7F025E84 02402025 */  move  $a0, $s2
/* 05A9B8 7F025E88 02002825 */  move  $a1, $s0
/* 05A9BC 7F025E8C 5160001F */  beql  $t3, $zero, .L7F025F0C
/* 05A9C0 7F025E90 26100001 */   addiu $s0, $s0, 1
/* 05A9C4 7F025E94 AFA60038 */  sw    $a2, 0x38($sp)
/* 05A9C8 7F025E98 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05A9CC 7F025E9C AFA70034 */   sw    $a3, 0x34($sp)
/* 05A9D0 7F025EA0 8C430004 */  lw    $v1, 4($v0)
/* 05A9D4 7F025EA4 80640080 */  lb    $a0, 0x80($v1)
/* 05A9D8 7F025EA8 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 05A9DC 7F025EAC AFA30070 */   sw    $v1, 0x70($sp)
/* 05A9E0 7F025EB0 8FA30070 */  lw    $v1, 0x70($sp)
/* 05A9E4 7F025EB4 8FA60038 */  lw    $a2, 0x38($sp)
/* 05A9E8 7F025EB8 04410009 */  bgez  $v0, .L7F025EE0
/* 05A9EC 7F025EBC 8FA70034 */   lw    $a3, 0x34($sp)
/* 05A9F0 7F025EC0 03A67021 */  addu  $t6, $sp, $a2
/* 05A9F4 7F025EC4 ADD10054 */  sw    $s1, 0x54($t6)
/* 05A9F8 7F025EC8 80620080 */  lb    $v0, 0x80($v1)
/* 05A9FC 7F025ECC 24010016 */  li    $at, 22
/* 05AA00 7F025ED0 54410007 */  bnel  $v0, $at, .L7F025EF0
/* 05AA04 7F025ED4 24010019 */   li    $at, 25
/* 05AA08 7F025ED8 10000004 */  b     .L7F025EEC
/* 05AA0C 7F025EDC 00009825 */   move  $s3, $zero
.L7F025EE0:
/* 05AA10 7F025EE0 AFB1005C */  sw    $s1, 0x5c($sp)
/* 05AA14 7F025EE4 00009825 */  move  $s3, $zero
/* 05AA18 7F025EE8 80620080 */  lb    $v0, 0x80($v1)
.L7F025EEC:
/* 05AA1C 7F025EEC 24010019 */  li    $at, 25
.L7F025EF0:
/* 05AA20 7F025EF0 10410004 */  beq   $v0, $at, .L7F025F04
/* 05AA24 7F025EF4 03A6C021 */   addu  $t8, $sp, $a2
/* 05AA28 7F025EF8 24010018 */  li    $at, 24
/* 05AA2C 7F025EFC 54410003 */  bnel  $v0, $at, .L7F025F0C
/* 05AA30 7F025F00 26100001 */   addiu $s0, $s0, 1
.L7F025F04:
/* 05AA34 7F025F04 AF11004C */  sw    $s1, 0x4c($t8)
/* 05AA38 7F025F08 26100001 */  addiu $s0, $s0, 1
.L7F025F0C:
/* 05AA3C 7F025F0C 24010002 */  li    $at, 2
/* 05AA40 7F025F10 24C60004 */  addiu $a2, $a2, 4
/* 05AA44 7F025F14 1601FFDA */  bne   $s0, $at, .L7F025E80
/* 05AA48 7F025F18 24E70004 */   addiu $a3, $a3, 4
/* 05AA4C 7F025F1C 240F000A */  li    $t7, 10
/* 05AA50 7F025F20 A24F0007 */  sb    $t7, 7($s2)
/* 05AA54 7F025F24 8FA80088 */  lw    $t0, 0x88($sp)
/* 05AA58 7F025F28 A2400031 */  sb    $zero, 0x31($s2)
/* 05AA5C 7F025F2C 0C002914 */  jal   randomGetNext
/* 05AA60 7F025F30 AE48002C */   sw    $t0, 0x2c($s2)
/* 05AA64 7F025F34 30590001 */  andi  $t9, $v0, 1
/* 05AA68 7F025F38 A2590032 */  sb    $t9, 0x32($s2)
/* 05AA6C 7F025F3C 8FA90068 */  lw    $t1, 0x68($sp)
/* 05AA70 7F025F40 A2490039 */  sb    $t1, 0x39($s2)
/* 05AA74 7F025F44 8FAD0064 */  lw    $t5, 0x64($sp)
/* 05AA78 7F025F48 A24D0038 */  sb    $t5, 0x38($s2)
/* 05AA7C 7F025F4C 8FAC0058 */  lw    $t4, 0x58($sp)
/* 05AA80 7F025F50 A24C003B */  sb    $t4, 0x3b($s2)
/* 05AA84 7F025F54 8FAA0054 */  lw    $t2, 0x54($sp)
/* 05AA88 7F025F58 A24A003A */  sb    $t2, 0x3a($s2)
/* 05AA8C 7F025F5C 8FAB0050 */  lw    $t3, 0x50($sp)
/* 05AA90 7F025F60 A24B003D */  sb    $t3, 0x3d($s2)
/* 05AA94 7F025F64 8FAE004C */  lw    $t6, 0x4c($sp)
/* 05AA98 7F025F68 A2530036 */  sb    $s3, 0x36($s2)
/* 05AA9C 7F025F6C A24E003C */  sb    $t6, 0x3c($s2)
/* 05AAA0 7F025F70 8FB8005C */  lw    $t8, 0x5c($sp)
/* 05AAA4 7F025F74 A2580037 */  sb    $t8, 0x37($s2)
/* 05AAA8 7F025F78 8FAF0078 */  lw    $t7, 0x78($sp)
/* 05AAAC 7F025F7C AE400040 */  sw    $zero, 0x40($s2)
/* 05AAB0 7F025F80 A2400033 */  sb    $zero, 0x33($s2)
/* 05AAB4 7F025F84 A2510030 */  sb    $s1, 0x30($s2)
/* 05AAB8 7F025F88 A24F0035 */  sb    $t7, 0x35($s2)
/* 05AABC 7F025F8C 8FA80050 */  lw    $t0, 0x50($sp)
/* 05AAC0 7F025F90 8FB9004C */  lw    $t9, 0x4c($sp)
/* 05AAC4 7F025F94 8FA90050 */  lw    $t1, 0x50($sp)
/* 05AAC8 7F025F98 15000003 */  bnez  $t0, .L7F025FA8
/* 05AACC 7F025F9C 00000000 */   nop   
/* 05AAD0 7F025FA0 13200009 */  beqz  $t9, .L7F025FC8
/* 05AAD4 7F025FA4 00000000 */   nop   
.L7F025FA8:
/* 05AAD8 7F025FA8 11200005 */  beqz  $t1, .L7F025FC0
/* 05AADC 7F025FAC 8FAD004C */   lw    $t5, 0x4c($sp)
/* 05AAE0 7F025FB0 11A00003 */  beqz  $t5, .L7F025FC0
/* 05AAE4 7F025FB4 240C0002 */   li    $t4, 2
/* 05AAE8 7F025FB8 10000015 */  b     .L7F026010
/* 05AAEC 7F025FBC A24C0034 */   sb    $t4, 0x34($s2)
.L7F025FC0:
/* 05AAF0 7F025FC0 10000013 */  b     .L7F026010
/* 05AAF4 7F025FC4 A2510034 */   sb    $s1, 0x34($s2)
.L7F025FC8:
/* 05AAF8 7F025FC8 0C002914 */  jal   randomGetNext
/* 05AAFC 7F025FCC 00000000 */   nop   
/* 05AB00 7F025FD0 304A0003 */  andi  $t2, $v0, 3
/* 05AB04 7F025FD4 254B0002 */  addiu $t3, $t2, 2
/* 05AB08 7F025FD8 A24B0034 */  sb    $t3, 0x34($s2)
/* 05AB0C 7F025FDC 8FAE0064 */  lw    $t6, 0x64($sp)
/* 05AB10 7F025FE0 8FB80068 */  lw    $t8, 0x68($sp)
/* 05AB14 7F025FE4 51C0000B */  beql  $t6, $zero, .L7F026014
/* 05AB18 7F025FE8 3C063F4C */   lui   $a2, 0x3f4c
/* 05AB1C 7F025FEC 53000009 */  beql  $t8, $zero, .L7F026014
/* 05AB20 7F025FF0 3C063F4C */   lui   $a2, 0x3f4c
/* 05AB24 7F025FF4 0C002914 */  jal   randomGetNext
/* 05AB28 7F025FF8 00000000 */   nop   
/* 05AB2C 7F025FFC 824F0034 */  lb    $t7, 0x34($s2)
/* 05AB30 7F026000 30480003 */  andi  $t0, $v0, 3
/* 05AB34 7F026004 01E8C821 */  addu  $t9, $t7, $t0
/* 05AB38 7F026008 27290002 */  addiu $t1, $t9, 2
/* 05AB3C 7F02600C A2490034 */  sb    $t1, 0x34($s2)
.L7F026010:
/* 05AB40 7F026010 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
.L7F026014:
/* 05AB44 7F026014 AE51004C */  sw    $s1, 0x4c($s2)
/* 05AB48 7F026018 AE400050 */  sw    $zero, 0x50($s2)
/* 05AB4C 7F02601C AE510054 */  sw    $s1, 0x54($s2)
/* 05AB50 7F026020 AE400058 */  sw    $zero, 0x58($s2)
/* 05AB54 7F026024 AE400044 */  sw    $zero, 0x44($s2)
/* 05AB58 7F026028 AE400048 */  sw    $zero, 0x48($s2)
/* 05AB5C 7F02602C A2400008 */  sb    $zero, 8($s2)
/* 05AB60 7F026030 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 05AB64 7F026034 02402025 */  move  $a0, $s2
/* 05AB68 7F026038 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 05AB6C 7F02603C 3C053F00 */   lui   $a1, 0x3f00
/* 05AB70 7F026040 8FAD0088 */  lw    $t5, 0x88($sp)
/* 05AB74 7F026044 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 05AB78 7F026048 44812000 */  mtc1  $at, $f4
/* 05AB7C 7F02604C 8DA50000 */  lw    $a1, ($t5)
/* 05AB80 7F026050 8DA70010 */  lw    $a3, 0x10($t5)
/* 05AB84 7F026054 E7A00010 */  swc1  $f0, 0x10($sp)
/* 05AB88 7F026058 8FA4008C */  lw    $a0, 0x8c($sp)
/* 05AB8C 7F02605C 8FA6007C */  lw    $a2, 0x7c($sp)
/* 05AB90 7F026060 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 05AB94 7F026064 E7A40014 */   swc1  $f4, 0x14($sp)
/* 05AB98 7F026068 8FAC0078 */  lw    $t4, 0x78($sp)
/* 05AB9C 7F02606C 5580002A */  bnezl $t4, .L7F026118
/* 05ABA0 7F026070 8FBF002C */   lw    $ra, 0x2c($sp)
/* 05ABA4 7F026074 12600013 */  beqz  $s3, .L7F0260C4
/* 05ABA8 7F026078 8FAE0088 */   lw    $t6, 0x88($sp)
/* 05ABAC 7F02607C 8FAA0088 */  lw    $t2, 0x88($sp)
/* 05ABB0 7F026080 44801000 */  mtc1  $zero, $f2
/* 05ABB4 7F026084 8FAB0088 */  lw    $t3, 0x88($sp)
/* 05ABB8 7F026088 C5400024 */  lwc1  $f0, 0x24($t2)
/* 05ABBC 7F02608C 4600103E */  c.le.s $f2, $f0
/* 05ABC0 7F026090 00000000 */  nop   
/* 05ABC4 7F026094 45020007 */  bc1fl .L7F0260B4
/* 05ABC8 7F026098 8FA4008C */   lw    $a0, 0x8c($sp)
/* 05ABCC 7F02609C 44050000 */  mfc1  $a1, $f0
/* 05ABD0 7F0260A0 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 05ABD4 7F0260A4 8FA4008C */   lw    $a0, 0x8c($sp)
/* 05ABD8 7F0260A8 1000001B */  b     .L7F026118
/* 05ABDC 7F0260AC 8FBF002C */   lw    $ra, 0x2c($sp)
/* 05ABE0 7F0260B0 8FA4008C */  lw    $a0, 0x8c($sp)
.L7F0260B4:
/* 05ABE4 7F0260B4 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 05ABE8 7F0260B8 8D65001C */   lw    $a1, 0x1c($t3)
/* 05ABEC 7F0260BC 10000016 */  b     .L7F026118
/* 05ABF0 7F0260C0 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F0260C4:
/* 05ABF4 7F0260C4 44801000 */  mtc1  $zero, $f2
/* 05ABF8 7F0260C8 C5C00020 */  lwc1  $f0, 0x20($t6)
/* 05ABFC 7F0260CC 8FB80088 */  lw    $t8, 0x88($sp)
/* 05AC00 7F0260D0 4600103E */  c.le.s $f2, $f0
/* 05AC04 7F0260D4 00000000 */  nop   
/* 05AC08 7F0260D8 45020007 */  bc1fl .L7F0260F8
/* 05AC0C 7F0260DC C7000014 */   lwc1  $f0, 0x14($t8)
/* 05AC10 7F0260E0 44050000 */  mfc1  $a1, $f0
/* 05AC14 7F0260E4 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 05AC18 7F0260E8 8FA4008C */   lw    $a0, 0x8c($sp)
/* 05AC1C 7F0260EC 1000000A */  b     .L7F026118
/* 05AC20 7F0260F0 8FBF002C */   lw    $ra, 0x2c($sp)
/* 05AC24 7F0260F4 C7000014 */  lwc1  $f0, 0x14($t8)
.L7F0260F8:
/* 05AC28 7F0260F8 4600103E */  c.le.s $f2, $f0
/* 05AC2C 7F0260FC 00000000 */  nop   
/* 05AC30 7F026100 45020005 */  bc1fl .L7F026118
/* 05AC34 7F026104 8FBF002C */   lw    $ra, 0x2c($sp)
/* 05AC38 7F026108 44050000 */  mfc1  $a1, $f0
/* 05AC3C 7F02610C 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 05AC40 7F026110 8FA4008C */   lw    $a0, 0x8c($sp)
/* 05AC44 7F026114 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F026118:
/* 05AC48 7F026118 8FB0001C */  lw    $s0, 0x1c($sp)
/* 05AC4C 7F02611C 8FB10020 */  lw    $s1, 0x20($sp)
/* 05AC50 7F026120 8FB20024 */  lw    $s2, 0x24($sp)
/* 05AC54 7F026124 8FB30028 */  lw    $s3, 0x28($sp)
/* 05AC58 7F026128 03E00008 */  jr    $ra
/* 05AC5C 7F02612C 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif



/**
 * Line-line intersection, where arg0 and arg1 are two points on line1, and arg2 and arg3 are a point and a direction of line2.
 * 3d coord/vector are passed as arguments, but only the 2d (x,z) values are used to find the intersection.
 * 
 * @param line1_p1: first point to describe line1
 * @param line1_p2: second point to describe line1
 * @param line2_p3: first point to describe line2
 * @param dir: vector giving direction of line2
 * @param result: contains result
 * 
 * Address 0x7F026130.
 */
void chrlvLineLineIntersection(struct coord3d *line1_p1, struct coord3d *line1_p2, struct coord3d *line2_p3, struct coord3d *dir, struct coord3d *result)
{
    /*
     * Line1 = P1 + u * (P2 - P1) 
     * Line2 = P3 + v * D
     * 
     * Intersection is where Line1==Line2, or:
     *     P1 + u * (P2 - P1) = P3 + v * D
     * 
     * u and v are unknown.
     * 
     * Isolate u:
     * 
     * u = (P3 + v*D - P1) / (P2 - P1)
     */
    f32 denom;

    // solve for v. (much algebra follows, not shown)
    
    denom = (dir->f[2] * (line1_p2->f[0] - line1_p1->f[0])) - (dir->f[0] * (line1_p2->f[2] - line1_p1->f[2]));

    if (denom != 0.0f)
    {
        f32 v = (
            ((line1_p1->f[2] - line2_p3->f[2]) * (line1_p2->f[0] - line1_p1->f[0])) 
            + ((line2_p3->f[0] - line1_p1->f[0]) * (line1_p2->f[2] - line1_p1->f[2]))
        ) / denom;

        // v is known, denom is non-zero, plug back into equation for Line2 = P3 + v * D

        result->f[0] = line2_p3->f[0] + (dir->f[0] * v);
        result->f[1] = line2_p3->f[1] + (dir->f[1] * v);
        result->f[2] = line2_p3->f[2] + (dir->f[2] * v);
    }
    else if ((dir->f[0] == 0.0f) && (dir->f[2] == 0.0f))
    {
        // else, denominator is zero, but direction is also zero, so assume Line 2 point as result
        result->f[0] = line2_p3->f[0];
        result->f[1] = line2_p3->f[1];
        result->f[2] = line2_p3->f[2];
    }
    else
    {
        // all other cases, fallback to Line 1 first point
        result->f[0] = line1_p1->f[0];
        result->f[1] = line1_p1->f[1];
        result->f[2] = line1_p1->f[2];
    }
}



/**
 * Line-line intersection.
 * The first two points are retrieved from getCollisionEdge_maybe.
 * The arguments to the method supply the other line, described by a point and direction.
 * 
 * 3d coord/vector are passed as arguments, but only the 2d (x,z) values are used to find the intersection.
 * 
 * @param line2_p3: first point to describe line2
 * @param dir: vector giving direction of line2
 * @param result: out parameter, contains result.
 * 
 * Address 0x7F02624C.
 */
void chrlvStanLineDirIntersection(struct coord3d *line2_p3, struct coord3d *dir, struct coord3d *result)
{
    struct coord3d sp2C;
    struct coord3d sp20;

    getCollisionEdge_maybe((struct float3 *) &sp2C, (struct float3 *) &sp20);
    chrlvLineLineIntersection(&sp2C, &sp20, line2_p3, dir, result);
}



/**
 * @param arg0:
 * @param arg1:
 * @param result: out parameter, contains result.
 * 
 * Address 0x7F026298.
 */
void chrlvStanPointPointIntersection(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *result)
{
    struct coord3d sp2C;
    struct coord3d sp20;
    f32 v;

    getCollisionEdge_maybe((struct float3 *) &sp2C, (struct float3 *) &sp20);

    // see comments in chrlvLineLineIntersection

    v = ((arg1->f[0] * (sp2C.f[2] - arg0->f[2])) - (arg1->f[2] * (sp2C.f[0] - arg0->f[0]))) 
        / ((arg1->f[2] * (sp20.f[0] - sp2C.f[0])) - (arg1->f[0] * (sp20.f[2] - sp2C.f[2])));

    result->f[0] = sp2C.f[0] + ((sp20.f[0] - sp2C.f[0]) * v);
    result->f[1] = sp2C.f[1] + ((sp20.f[1] - sp2C.f[1]) * v);
    result->f[2] = sp2C.f[2] + ((sp20.f[2] - sp2C.f[2]) * v);
}




/**
 * Address 0x7F026364.
 */
f32 chrlvPathingCollisionRelated(PropRecord *arg0, f32 arg1, f32 arg2, s32 objFlags, f32 unkHeight, f32 unkA)
{
    struct coord3d sp5C; // sp92
    f32 dest_x; // sp88
    f32 dest_z; // sp84
    StandTile *stan; // sp80
    ChrRecord *chr; // sp76
    f32 ret;
    struct coord3d sp3C;

    stan = arg0->stan;
    chr = arg0->chr;

    sp5C.f[0] = sinf(arg1);
    sp5C.f[1] = 0.0f;
    sp5C.f[2] = cosf(arg1);
    dest_x = arg0->pos.f[0] + (sp5C.f[0] * arg2);
    dest_z = arg0->pos.f[2] + (sp5C.f[2] * arg2);

    set_or_unset_GUARDdata_flag(chr, 0);
    sub_GAME_7F0B1CC4();

    if (sub_GAME_7F0B0E24(&stan, arg0->pos.f[0], arg0->pos.f[2], dest_x, dest_z, objFlags, unkHeight, unkA, 0.0f, 1.0f) != 0)
    {
        ret = arg2;
    }
    else
    {
        chrlvStanLineDirIntersection(&arg0->pos, &sp5C, &sp3C);
        dest_x = sp3C.f[0] - arg0->pos.f[0];
        dest_z = sp3C.f[2] - arg0->pos.f[2];
        ret = sqrtf((dest_x * dest_x) + (dest_z * dest_z));
    }

    set_or_unset_GUARDdata_flag(chr, 1);

    return ret;
}




/**
 * Address 0x7F0264B0.
*/
f32 chrlvPathingCollisionRelated7F0264B0(PropRecord *arg0, f32 arg1, f32 arg2)
{
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    chrGetChrWidthHeight(arg0, &sp24, &sp2C, &sp28);
    return chrlvPathingCollisionRelated(arg0, arg1, arg2, 0x1F, sp2C, sp28);
}




/**
 * @param arg0:
 * @param arg1:
 * @param arg2:
 * @param req_animation_id: Lookup by id property in D_8002C914
 * @param item: argument to bondwalkItemGetForceOfImpact
 * 
 * Address 0x7F026508.
 */
void triggered_on_shot_hit(struct ChrRecord *arg0, struct coord3d *arg1, f32 arg2, s32 req_animation_id, ITEM_IDS item)
{
    // stack offset in decimal

    s32 flag9c; // 156(sp)
    struct PropRecord *prop; // 152
    struct Model *model; // 148
    s32 another_flag; // 144
    f32 impact_force; // ?
    s32 animation_something_index; // 136
    s32 flag1; // 132
    u8 *sp80 = NULL; // ?
    struct animation_something *something_ani = NULL; // ?
    f32 fa;
    f32 fb;
    f32 f_under; // 112(sp)
    f32 f_over; // 108(sp)
    f32 ft;
    struct struck_animation_table *struck_ani; // 100
    s32 i;

    flag9c = 1;
    prop = arg0->prop;
    model = arg0->model;
    another_flag = 0;
    animation_something_index = 0;

    if ((arg0->prop->type != PROP_TYPE_VIEWER) || (getPlayerCount() < 2))
    {
        flag1 = (arg0->actiontype == ACT_ARGH) && (g_GlobalTimer == arg0->act_argh.unk030);

        for (i=0; D_8002C914[i].id != -1; i++)
        {
            if (req_animation_id == D_8002C914[i].id)
            {
                animation_something_index = i;

                break;
            }
        }

        if (arg0->damage >= arg0->maxdamage)
        {
            if (((arg2 < 1.5707964f) || (arg2 > 4.712389f)) && ((randomGetNext() % (u32)0x14) == 0))
            {
                ft = getsubroty(model) + M_PI_F;

                fa = ft + 0.17453294f;
                f_under = ft - 0.17453294f;

                if (fa >= M_2PI_F)
                {
                    fa -= M_2PI_F;
                }

                if (f_under >= M_2PI_F)
                {
                    f_under -= M_2PI_F;
                }

                f_over = chrlvPathingCollisionRelated7F0264B0(prop, fa, 150.0f);
                f_under = chrlvPathingCollisionRelated7F0264B0(prop, f_under, 150.0f);

                if ((f_over < 150.0f) && (f_under < 150.0f))
                {
                    ft = f_over - f_under;
                    if ((ft < 10.0f) && (ft > -10.0f))
                    {
                        struck_ani = &D_8002DEBC[randomGetNext() & 1];

                        sub_GAME_7F02D184(arg0);
                        arg0->actiontype = ACT_DIE;
                        arg0->act_die.notifychrindex = 0;
                        arg0->act_die.thudframe1 = struck_ani->sfx1_timer_60;
                        arg0->act_die.thudframe2 = struck_ani->sfx2_timer_60;
                        arg0->sleep = 0;
                        arg0->act_die.timeextra = 0.0f;

                        sub_GAME_7F06FC4C(model, (void*)struck_ani->anonymous_0, struck_ani->anonymous_1, 0.0f, struck_ani->anonymous_3, 16.0f, flag1 == 0);

                        if (struck_ani->anonymous_2 >= 0.0f)
                        {
                            sub_GAME_7F06FDE8(model, struck_ani->anonymous_2);
                        }

                        // Note: PD sets the chrwidth to 10 when a guard dies slumped against an object or wall
                        arg0->chrwidth = 10.0f;

                        another_flag = 1;
                    }
                }
            }

            if (another_flag == 0)
            {
                if ((D_8002C914[animation_something_index].field_1C != NULL) && (D_8002C914[animation_something_index].field_20 > 0))
                {
                    struct struck_animation_table *struck_anib; // sp(92)
                    s32 tr;

                    if (0)
                    {
                        // removed
                    }
                    
                    another_flag = 1;

                    tr = (randomGetNext() % (u32)D_8002C914[animation_something_index].field_20);
                    struck_anib = &D_8002C914[animation_something_index].field_1C[tr];
                    sub_GAME_7F02D184(arg0);

                    arg0->actiontype = ACT_DIE;
                    arg0->act_die.notifychrindex = 0;
                    arg0->act_die.thudframe1 = struck_anib->sfx1_timer_60;
                    arg0->act_die.thudframe2 = struck_anib->sfx2_timer_60;
                    arg0->sleep = 0;
                    arg0->act_die.timeextra = 0.0f;

                    sub_GAME_7F06FC4C(model, (void*)struck_anib->anonymous_0, struck_anib->anonymous_1, 0.0f, struck_anib->anonymous_3, 16.0f, flag1 == 0);

                    if ((s32)struck_anib->anonymous_0 == ((s32)&ptr_animation_table->data[(s32)&ANIM_DATA_death_neck]) && ((randomGetNext() % (u32)0x64) != 0))
                    {
                        sub_GAME_7F06FDE8(model, 241.0f);
                    }
                    else if (struck_anib->anonymous_2 >= 0.0f)
                    {
                        sub_GAME_7F06FDE8(model, struck_anib->anonymous_2);
                    }

                    impact_force = bondwalkItemGetForceOfImpact(item);

                    if ((impact_force <= 0.0f) && ((arg0->chrflags & IMPACT_ALWAYS) != 0))
                    {
                        impact_force = 6.0f;
                    }

                    if ((struck_anib->anonymous_4 != 0) && (impact_force > 0.0f))
                    {
                        arg0->act_die.elapseextra = 0.0f;
                        arg0->act_die.timeextra = ((impact_force * 90.0f) / 6.0f);
                        arg0->act_die.extraspeed.f[0] = (arg1->f[0] * impact_force);
                        arg0->act_die.extraspeed.f[1] = (arg1->f[1] * impact_force);
                        arg0->act_die.extraspeed.f[2] = (arg1->f[2] * impact_force);
                    }
                }
            }

            sub_GAME_7F021B20(arg0);
            increment_num_kills_display_text_in_MP();
            
            if (arg0->chrflags & COUNT_DEATH_AS_CIVILIAN)
            {
                inc_cur_civilian_casualties();
            }
        }
        else
        {
            if ((req_animation_id == 7) && (arg2 > 2.3561945f) && (arg2 < 3.926991f) && ((u32) (randomGetNext() % (u32)5) < 2U))
            {
                u32 sp54 = randomGetNext() % (u32)5;
                sub_GAME_7F02D184(arg0);
                arg0->actiontype = ACT_ARGH;
                arg0->act_argh.notifychrindex = 0;
                arg0->act_argh.unk030 = g_GlobalTimer;
                arg0->sleep = 0;

                if ((randomGetNext() & 1) != 0)
                {
                    sp80 = &ptr_animation_table->data[(s32)&ANIM_DATA_hit_butt_long];
                    sub_GAME_7F06FC4C(model, sp80, randomGetNext() & 1, 10.f, 0.5f, 16.0f, flag1 == 0);

                    if (sp54 < 2U)
                    {
                        sub_GAME_7F06FDE8(model, chrlvGetGuard007ArghRating(arg0, 34.0f, 8.0f));
                    }
                    else if (sp54 < 4U)
                    {
                        sub_GAME_7F06FDE8(model, chrlvGetGuard007ArghRating(arg0, 71.0f, 8.0f));
                    }
                    else
                    {
                        sub_GAME_7F06FDE8(model, chrlvGetGuard007ArghRating(arg0, (f32) (((u16*)sp80)[2] - 1), 8.0f));
                    }
                }
                else
                {
                    sp80 = &ptr_animation_table->data[(s32)&ANIM_DATA_hit_butt_short];
                    sub_GAME_7F06FC4C(model, sp80, randomGetNext() & 1, 0.0f, 0.5f, 16.0f, flag1 == 0);
                    
                    if (sp54 < 2U)
                    {
                        sub_GAME_7F06FDE8(model, chrlvGetGuard007ArghRating(arg0, 37.0f, 8.0f));
                    }
                    else if (sp54 < 4U)
                    {
                        sub_GAME_7F06FDE8(model, chrlvGetGuard007ArghRating(arg0, 70.0f, 8.0f));
                    }
                    else
                    {
                        sub_GAME_7F06FDE8(model, chrlvGetGuard007ArghRating(arg0, (f32) (((u16*)sp80)[2] - 1), 8.0f));
                    }
                }
                
                another_flag = 1;
            }

            if (another_flag == 0)
            {
                if ((D_8002C914[animation_something_index].field_24 != NULL) && (D_8002C914[animation_something_index].field_28 > 0))
                {
                    struct PropRecord *temp_left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND); // 80(sp)
                    struct PropRecord *temp_right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);
                    s32 tr;
                    struct struck_animation_table *struck_ani; // 68(sp)
                    s32 ff = flag1 == 0; // 52(sp) ??

                    another_flag = 1;
                    something_ani = &D_8002C914[animation_something_index];
                    
                    if (((s32)&D_8002C914[9] == (s32)something_ani) && (temp_left != NULL))
                    {
                        animation_something_index = 10;
                    }
                    else if (((s32)&D_8002C914[12] == (s32)something_ani) && (temp_right != NULL))
                    {
                        animation_something_index = 13;
                    }
                    
                    something_ani = &D_8002C914[animation_something_index];
                    tr = (randomGetNext() % (u32) something_ani->field_28);
                    struck_ani = &something_ani->field_24[tr];

                    sub_GAME_7F02D184(arg0);
                    
                    arg0->actiontype = ACT_ARGH;
                    arg0->act_argh.notifychrindex = 0;
                    arg0->act_argh.unk030 = g_GlobalTimer;
                    arg0->sleep = 0;

                    sub_GAME_7F06FC4C(model, (void*)struck_ani->anonymous_0, struck_ani->anonymous_1, 0.0f, struck_ani->anonymous_3, 16.0f, ff);

                    if (struck_ani->anonymous_2 >= 0.0f)
                    {
                        sub_GAME_7F06FDE8(model, chrlvGetGuard007ArghRating(arg0, struck_ani->anonymous_2, 8.0f));
                    }
                    else
                    {
                        sub_GAME_7F06FDE8(model, chrlvGetGuard007ArghRating(arg0, (f32)((s32)((u16*)struck_ani->anonymous_0)[2] - (s32)1), 8.0f));
                    }
                }
            }

            flag9c = 0;
        }

        if (flag9c && another_flag)
        {
            if ((arg0->weapons_held[RIGHT_HAND] != NULL) && ((arg0->weapons_held[RIGHT_HAND]->obj->flags & 0x2000) == 0))
            {
                sub_GAME_7F04BFD0(arg0->weapons_held[RIGHT_HAND], 1);
                arg0->hidden |= 1;
            }

            if ((arg0->weapons_held[LEFT_HAND] != NULL) && ((arg0->weapons_held[LEFT_HAND]->obj->flags & 0x2000) == 0))
            {
                sub_GAME_7F04BFD0(arg0->weapons_held[LEFT_HAND], 1);
                arg0->hidden |= 1;
            }
        }
    }
}


/**
 * @param arg0:
 * @param result: out parameter, will contain result
 * @returns status indicating if result is set
 * 
 * Address 0x7F026F30.
*/
s32 chrlvAttackAnimationRelated7F026F30(struct ChrRecord *arg0, f32 *result)
{
    s32 flag;
    f32 out_val;

    flag = 0;

    if (arg0->actiontype == ACT_ATTACKROLL)
    {
        if (arg0->act_attackroll.unk035 != 0)
        {
            if (
                (arg0->act_attackroll.animfloats == &D_80030198)
                || (arg0->act_attackroll.animfloats == &D_800301E0)
                || (arg0->act_attackroll.animfloats == &D_80030228)
                || (arg0->act_attackroll.animfloats == &D_80030270))
            {
                out_val = arg0->act_attackroll.animfloats->anonymous_1 - 8.0f;

                if (arg0->act_attackroll.animfloats->anonymous_5 < arg0->act_attackroll.animfloats->anonymous_1)
                {
                    out_val = arg0->act_attackroll.animfloats->anonymous_5;
                }

                if (objecthandlerGetModelField28(arg0->model) < out_val)
                {
                    *result = out_val;
                    flag = 1;
                }
            }
        }
        else
        {
            out_val = arg0->act_attackroll.animfloats->anonymous_1 - 8.0f;
            if (objecthandlerGetModelField28(arg0->model) < out_val)
            {
                *result = out_val;
                flag = 1;
            }
        }
    }
    else if (arg0->actiontype == ACT_PREARGH)
    {
        // typo/mistake, return without setting *result
        flag = 1;
    }

    return flag;
}




#ifdef NONMATCHING

/**
 * Address 0x7F027060.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * notes: mystery section, seems to be missing something mips_to_c can't see.
 * male_guard_yelp_counter, female_guard_yelp_counter are static, need to be moved from chr.c
 * Also need to remove female_guard_yelps, male_guard_yelps from chr.c once this matches.
*/
void play_sound_for_shot_actor(ChrRecord *arg0)
{
    ALSoundState * sndstate = NULL;
    s32 male = 0;

    static s32 male_guard_yelp_counter = 0;
    static s32 female_guard_yelp_counter = 0;

    if ((arg0->prop->type != PROP_TYPE_VIEWER) || (g_playerPointers[sub_GAME_7F09B15C(arg0->prop)]->bonddead == 0))
    {
        /*
        * decomp issue: mystery section.
        * what is going on right here?
        * arg0 = 104(sp), why is it only loaded six times instead of seven?
        */
        if (arg0->prop->type == PROP_TYPE_VIEWER)
        {
            if (getPlayerCount() == 1)
            {
                if (c_item_entries[arg0->bodynum].isMale != 0)
                {
                    male = 1;
                }
            }
            else
            {
                if (get_player_mp_char_gender(sub_GAME_7F09B15C(arg0->prop)) != 0)
                {
                    male = 1;
                }
            }
        }
        else if (c_item_entries[arg0->bodynum].isMale != 0)
        {
            male = 1;
        }

        if (male != 0)
        {
            //s16 sounds[26] = male_guard_yelps;
            s16 sounds[] = {
                0x86,  0x87,  0x88,  0x89,  0x8A,  0x8B,  0x8C,  0x8D,  0x8E,  0x8F,
                0x90,  0x91,  0x92,  0x93,  0x94,  0x95,  0x96,  0x97,  0x98,  0x99,
                0x9A,  0x9B,  0x9C,  0x9D,  0x9E
            };

            sndstate = sndPlaySfx(g_musicSfxBufferPtr, sounds[male_guard_yelp_counter], NULL);

            male_guard_yelp_counter++;
            if (male_guard_yelp_counter >= 25)
            {
                male_guard_yelp_counter = 0;
            }
        }
        else
        {
            //s16 sounds[4] = female_guard_yelps;
            s16 sounds[] = {
                0xD,   0xE,   0xF
            };

            sndstate = sndPlaySfx(g_musicSfxBufferPtr, sounds[female_guard_yelp_counter], NULL);

            female_guard_yelp_counter++;
            if (female_guard_yelp_counter >= 3)
            {
                female_guard_yelp_counter = 0;
            }
        }

        sub_GAME_7F053A10(sndstate, &arg0->prop->pos);
    }
}
#else
GLOBAL_ASM(
.text
glabel play_sound_for_shot_actor
/* 05BB90 7F027060 27BDFF98 */  addiu $sp, $sp, -0x68
/* 05BB94 7F027064 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05BB98 7F027068 AFA40068 */  sw    $a0, 0x68($sp)
/* 05BB9C 7F02706C 8C850018 */  lw    $a1, 0x18($a0)
/* 05BBA0 7F027070 24010006 */  li    $at, 6
/* 05BBA4 7F027074 00001825 */  move  $v1, $zero
/* 05BBA8 7F027078 90AF0000 */  lbu   $t7, ($a1)
/* 05BBAC 7F02707C 00A02025 */  move  $a0, $a1
/* 05BBB0 7F027080 55E1000C */  bnel  $t7, $at, .L7F0270B4
/* 05BBB4 7F027084 8FA90068 */   lw    $t1, 0x68($sp)
/* 05BBB8 7F027088 0FC26C57 */  jal   sub_GAME_7F09B15C
/* 05BBBC 7F02708C AFA00060 */   sw    $zero, 0x60($sp)
/* 05BBC0 7F027090 0002C080 */  sll   $t8, $v0, 2
/* 05BBC4 7F027094 3C198008 */  lui   $t9, %hi(g_playerPointers)
/* 05BBC8 7F027098 0338C821 */  addu  $t9, $t9, $t8
/* 05BBCC 7F02709C 8F399EE0 */  lw    $t9, %lo(g_playerPointers)($t9)
/* 05BBD0 7F0270A0 8FA30060 */  lw    $v1, 0x60($sp)
/* 05BBD4 7F0270A4 8F2800D8 */  lw    $t0, 0xd8($t9)
/* 05BBD8 7F0270A8 55000071 */  bnezl $t0, .L7F027270
/* 05BBDC 7F0270AC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 05BBE0 7F0270B0 8FA90068 */  lw    $t1, 0x68($sp)
.L7F0270B4:
/* 05BBE4 7F0270B4 24010006 */  li    $at, 6
/* 05BBE8 7F0270B8 8FB90068 */  lw    $t9, 0x68($sp)
/* 05BBEC 7F0270BC 8D2A0018 */  lw    $t2, 0x18($t1)
/* 05BBF0 7F0270C0 914B0000 */  lbu   $t3, ($t2)
/* 05BBF4 7F0270C4 5561001D */  bnel  $t3, $at, .L7F02713C
/* 05BBF8 7F0270C8 8328000F */   lb    $t0, 0xf($t9)
/* 05BBFC 7F0270CC 0FC26919 */  jal   getPlayerCount
/* 05BC00 7F0270D0 AFA30060 */   sw    $v1, 0x60($sp)
/* 05BC04 7F0270D4 24010001 */  li    $at, 1
/* 05BC08 7F0270D8 1441000D */  bne   $v0, $at, .L7F027110
/* 05BC0C 7F0270DC 8FA30060 */   lw    $v1, 0x60($sp)
/* 05BC10 7F0270E0 8FAC0068 */  lw    $t4, 0x68($sp)
/* 05BC14 7F0270E4 3C0F8004 */  lui   $t7, %hi(c_item_entries+16)
/* 05BC18 7F0270E8 818D000F */  lb    $t5, 0xf($t4)
/* 05BC1C 7F0270EC 000D7080 */  sll   $t6, $t5, 2
/* 05BC20 7F0270F0 01CD7021 */  addu  $t6, $t6, $t5
/* 05BC24 7F0270F4 000E7080 */  sll   $t6, $t6, 2
/* 05BC28 7F0270F8 01EE7821 */  addu  $t7, $t7, $t6
/* 05BC2C 7F0270FC 91EFDE20 */  lbu   $t7, %lo(c_item_entries+16)($t7)
/* 05BC30 7F027100 11E00017 */  beqz  $t7, .L7F027160
/* 05BC34 7F027104 00000000 */   nop   
/* 05BC38 7F027108 10000015 */  b     .L7F027160
/* 05BC3C 7F02710C 24030001 */   li    $v1, 1
.L7F027110:
/* 05BC40 7F027110 8FB80068 */  lw    $t8, 0x68($sp)
/* 05BC44 7F027114 8F040018 */  lw    $a0, 0x18($t8)
/* 05BC48 7F027118 0FC26C57 */  jal   sub_GAME_7F09B15C
/* 05BC4C 7F02711C AFA30060 */   sw    $v1, 0x60($sp)
/* 05BC50 7F027120 0FC040C3 */  jal   get_player_mp_char_gender
/* 05BC54 7F027124 00402025 */   move  $a0, $v0
/* 05BC58 7F027128 1040000D */  beqz  $v0, .L7F027160
/* 05BC5C 7F02712C 8FA30060 */   lw    $v1, 0x60($sp)
/* 05BC60 7F027130 1000000B */  b     .L7F027160
/* 05BC64 7F027134 24030001 */   li    $v1, 1
/* 05BC68 7F027138 8328000F */  lb    $t0, 0xf($t9)
.L7F02713C:
/* 05BC6C 7F02713C 3C0A8004 */  lui   $t2, %hi(c_item_entries+16)
/* 05BC70 7F027140 00084880 */  sll   $t1, $t0, 2
/* 05BC74 7F027144 01284821 */  addu  $t1, $t1, $t0
/* 05BC78 7F027148 00094880 */  sll   $t1, $t1, 2
/* 05BC7C 7F02714C 01495021 */  addu  $t2, $t2, $t1
/* 05BC80 7F027150 914ADE20 */  lbu   $t2, %lo(c_item_entries+16)($t2)
/* 05BC84 7F027154 11400002 */  beqz  $t2, .L7F027160
/* 05BC88 7F027158 00000000 */   nop   
/* 05BC8C 7F02715C 24030001 */  li    $v1, 1
.L7F027160:
/* 05BC90 7F027160 10600025 */  beqz  $v1, .L7F0271F8
/* 05BC94 7F027164 3C088003 */   lui   $t0, %hi(female_guard_yelps) 
/* 05BC98 7F027168 3C0B8003 */  lui   $t3, %hi(male_guard_yelps) 
/* 05BC9C 7F02716C 27A20028 */  addiu $v0, $sp, 0x28
/* 05BCA0 7F027170 256B09F8 */  addiu $t3, %lo(male_guard_yelps) # addiu $t3, $t3, 0x9f8
/* 05BCA4 7F027174 256D0030 */  addiu $t5, $t3, 0x30
/* 05BCA8 7F027178 00407025 */  move  $t6, $v0
.L7F02717C:
/* 05BCAC 7F02717C 8D610000 */  lw    $at, ($t3)
/* 05BCB0 7F027180 256B000C */  addiu $t3, $t3, 0xc
/* 05BCB4 7F027184 25CE000C */  addiu $t6, $t6, 0xc
/* 05BCB8 7F027188 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 05BCBC 7F02718C 8D61FFF8 */  lw    $at, -8($t3)
/* 05BCC0 7F027190 ADC1FFF8 */  sw    $at, -8($t6)
/* 05BCC4 7F027194 8D61FFFC */  lw    $at, -4($t3)
/* 05BCC8 7F027198 156DFFF8 */  bne   $t3, $t5, .L7F02717C
/* 05BCCC 7F02719C ADC1FFFC */   sw    $at, -4($t6)
/* 05BCD0 7F0271A0 95610000 */  lhu   $at, ($t3)
/* 05BCD4 7F0271A4 3C0F8003 */  lui   $t7, %hi(male_guard_yelp_counter) 
/* 05BCD8 7F0271A8 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 05BCDC 7F0271AC A5C10000 */  sh    $at, ($t6)
/* 05BCE0 7F0271B0 8DEF0A34 */  lw    $t7, %lo(male_guard_yelp_counter)($t7)
/* 05BCE4 7F0271B4 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 05BCE8 7F0271B8 00003025 */  move  $a2, $zero
/* 05BCEC 7F0271BC 000FC040 */  sll   $t8, $t7, 1
/* 05BCF0 7F0271C0 0058C821 */  addu  $t9, $v0, $t8
/* 05BCF4 7F0271C4 0C002382 */  jal   sndPlaySfx
/* 05BCF8 7F0271C8 87250000 */   lh    $a1, ($t9)
/* 05BCFC 7F0271CC 3C038003 */  lui   $v1, %hi(male_guard_yelp_counter)
/* 05BD00 7F0271D0 8C630A34 */  lw    $v1, %lo(male_guard_yelp_counter)($v1)
/* 05BD04 7F0271D4 3C018003 */  lui   $at, %hi(male_guard_yelp_counter)
/* 05BD08 7F0271D8 00402025 */  move  $a0, $v0
/* 05BD0C 7F0271DC 24630001 */  addiu $v1, $v1, 1
/* 05BD10 7F0271E0 AC230A34 */  sw    $v1, %lo(male_guard_yelp_counter)($at)
/* 05BD14 7F0271E4 28610019 */  slti  $at, $v1, 0x19
/* 05BD18 7F0271E8 1420001C */  bnez  $at, .L7F02725C
/* 05BD1C 7F0271EC 3C018003 */   lui   $at, %hi(male_guard_yelp_counter)
/* 05BD20 7F0271F0 1000001A */  b     .L7F02725C
/* 05BD24 7F0271F4 AC200A34 */   sw    $zero, %lo(male_guard_yelp_counter)($at)
.L7F0271F8:
/* 05BD28 7F0271F8 25080A2C */  addiu $t0, %lo(female_guard_yelps) # addiu $t0, $t0, 0xa2c
/* 05BD2C 7F0271FC 8D010000 */  lw    $at, ($t0)
/* 05BD30 7F027200 27A20020 */  addiu $v0, $sp, 0x20
/* 05BD34 7F027204 3C0D8003 */  lui   $t5, %hi(female_guard_yelp_counter) 
/* 05BD38 7F027208 AC410000 */  sw    $at, ($v0)
/* 05BD3C 7F02720C 95010004 */  lhu   $at, 4($t0)
/* 05BD40 7F027210 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 05BD44 7F027214 00003025 */  move  $a2, $zero
/* 05BD48 7F027218 A4410004 */  sh    $at, 4($v0)
/* 05BD4C 7F02721C 8DAD0A38 */  lw    $t5, %lo(female_guard_yelp_counter)($t5)
/* 05BD50 7F027220 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 05BD54 7F027224 000D5840 */  sll   $t3, $t5, 1
/* 05BD58 7F027228 004B7021 */  addu  $t6, $v0, $t3
/* 05BD5C 7F02722C 0C002382 */  jal   sndPlaySfx
/* 05BD60 7F027230 85C50000 */   lh    $a1, ($t6)
/* 05BD64 7F027234 3C038003 */  lui   $v1, %hi(female_guard_yelp_counter)
/* 05BD68 7F027238 8C630A38 */  lw    $v1, %lo(female_guard_yelp_counter)($v1)
/* 05BD6C 7F02723C 3C018003 */  lui   $at, %hi(female_guard_yelp_counter)
/* 05BD70 7F027240 00402025 */  move  $a0, $v0
/* 05BD74 7F027244 24630001 */  addiu $v1, $v1, 1
/* 05BD78 7F027248 AC230A38 */  sw    $v1, %lo(female_guard_yelp_counter)($at)
/* 05BD7C 7F02724C 28610003 */  slti  $at, $v1, 3
/* 05BD80 7F027250 14200002 */  bnez  $at, .L7F02725C
/* 05BD84 7F027254 3C018003 */   lui   $at, %hi(female_guard_yelp_counter)
/* 05BD88 7F027258 AC200A38 */  sw    $zero, %lo(female_guard_yelp_counter)($at)
.L7F02725C:
/* 05BD8C 7F02725C 8FAF0068 */  lw    $t7, 0x68($sp)
/* 05BD90 7F027260 8DE50018 */  lw    $a1, 0x18($t7)
/* 05BD94 7F027264 0FC14E84 */  jal   sub_GAME_7F053A10
/* 05BD98 7F027268 24A50008 */   addiu $a1, $a1, 8
/* 05BD9C 7F02726C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F027270:
/* 05BDA0 7F027270 27BD0068 */  addiu $sp, $sp, 0x68
/* 05BDA4 7F027274 03E00008 */  jr    $ra
/* 05BDA8 7F027278 00000000 */   nop   
)
#endif



/**
 * Address 0x7F02727C.
*/
bool handles_shot_actors(struct ChrRecord *self, s32 hitpart, struct coord3d *vector, s32 weaponid, bool isPlayer)
{
    s32 hattype;                     //sp78
    PropRecord *myprop = self->prop; //sp60
    s32 padd;

    // Handle hat shots.
    if (hitpart == HIT_HAT && self->handle_positiondata_hat)
    {
        hattype = get_hat_model(self->handle_positiondata_hat);

        if (hattype == HATTYPE_MOON) //moon - count as head hit
        {
            hitpart = HIT_HEAD;
        }
        else if (hattype != HATTYPE_HELMATE) //normal hats - knock off
        {
            sub_GAME_7F04BFD0(self->handle_positiondata_hat, 4); //propobjSetDropped
            self->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;           //drop hat
        }
        else //steel helmate - ricochet
        {
            s16 mrs[3] = metal_ricochet_SFX;
            ALSoundState * p = sndPlaySfx(g_musicSfxBufferPtr, mrs[randomGetNext() % 3U], NULL);
            sub_GAME_7F053A10(p, &self->prop->pos);
        }
    }

    // Handle incrementing player shot count
    if (isPlayer && hitpart)
    {
        switch (hitpart)
        {
            case HIT_HEAD:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOTREGION_HEAD);
                break;
            }
            case HIT_GUN:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOTREGION_GUN);
                break;
            }
            case HIT_HAT:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOTREGION_HAT);
                break;
            }
            case HIT_CHEST:
            case HIT_PELVIS:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOTREGION_BODY);
                break;
            }
            default:
            {
                inc_curplayer_hitcount_with_weapon(weaponid, SHOTREGION_LIMB);
                break;
            }
        }
    }

    self->numarghs++;
    self->chrflags |= CHRFLAG_WAS_HIT;

    // If the chr is invincible, make them flinch then we're done
    if (self->chrflags & CHRFLAG_INVINCIBLE)
    {
        chrSetHiddenToRandom(self); //chrFlinchBody
        return FALSE;
    }

    // If chr is dying or already dead then we're done
    if ((self->actiontype != ACT_DIE) && (self->actiontype != ACT_DEAD))
    {
        struct coord3d vec;                                             //sp44
        f32 angle;                                                      //sp40
        f32 damageToCause; //sp3c
        s32 playerNum;                                                  //sp38

        damageToCause = bondwalkItemGetDestructionAmount(weaponid);

        if (isPlayer && (getPlayerCount() == 1))
        {
            damageToCause *= g_AiHealthModifier;
        }

        vec.x = myprop->pos.x - vector->x;
        vec.y = myprop->pos.y - vector->y;
        vec.z = myprop->pos.z - vector->z;
        angle = get_distance_actor_to_position(self, &vec); //chrGetAngleToPos

        if (hitpart == HIT_GENERAL)
        {
            // Halve the damage because it's doubled for torso below
            hitpart = HIT_CHEST;
            damageToCause *= 0.5f;
        }
        else if (hitpart == HIT_GENERALHALF)
        {
            // Likewise, quarter it here so it becomes half below
            hitpart = HIT_CHEST;
            damageToCause *= 0.25f;
        }

        if (weaponid == ITEM_FIST)
        {
            if ((self->actiontype != ACT_STAND) &&
                (self->actiontype != ACT_PATROL) &&
                (self->actiontype != ACT_SURRENDER) &&
                (self->actiontype != ACT_ANIM) &&
                ((self->actiontype != ACT_GOPOS) || self->act_gopos.unk59))
            {
                // Punching and pistol whipping is less effective from the front
                if ((angle < 1.0471976f) || (angle > 5.2359877f))
                {
                    damageToCause *= 0.125f;
                }
                else if ((angle < 2.0943952f) || (angle > 4.1887903f))
                {
                    damageToCause *= 0.25f;
                }
                else
                {
                    damageToCause *= 0.5f;
                }
            }
        }

        // Apply damage multipliers based on which body parts were hit,
        // and flinch head if shot in the head - PD Only
        if (hitpart == HIT_HEAD)
        {
            damageToCause *= 4.0f;
        }
        else if (hitpart == HIT_CHEST)
        {
            damageToCause *= 2.0f;
        }
        else if (hitpart == HIT_GUN)
        {
            damageToCause = 0.0f;
        }
        else if (hitpart == HIT_HAT)
        {
            damageToCause = 0.0f;
        }

        if (self->prop->type == PROP_TYPE_VIEWER)
        {
            playerNum = get_cur_playernum();
            set_cur_player(sub_GAME_7F09B15C(self->prop));
            record_damage_kills(damageToCause * 0.125f, vector->x, vector->z, playerNum, 1);
            set_cur_player(playerNum);
        }
        else
        {
            self->chrflags |= CHRFLAG_WAS_DAMAGED;
#    ifdef XBLA
            if (!cheatIsActive(76))
#    endif
                self->damage += damageToCause;

            if (self->damage < 0.0f)
            {
                f32 endframe = -1.0f; //sp34
                if (!chrlvAttackAnimationRelated7F026F30(self, &endframe))
                {
                    chrSetHiddenToRandom(self);
                    return FALSE;
                }
            }
        }

        if (hitpart != HIT_HAT)
        {
            // Cancel current animation and prepare for argh
            f32 endframe2 = -1.0f; //sp30
            play_sound_for_shot_actor(self);

            if (chrlvAttackAnimationRelated7F026F30(self, &endframe2)) //chrIsAnimPreventingArgh
            {
                if (endframe2 >= 0.0f)
                {
                    sub_GAME_7F06FDE8(self->model, endframe2); //modelSetAnimEndFrame
                }

                self->actiontype         = ACT_PREARGH;
                self->act_preargh.pos.x  = vector->x;
                self->act_preargh.pos.y  = vector->y;
                self->act_preargh.pos.z  = vector->z;
                self->act_preargh.unk038 = angle;
                self->act_preargh.unk03c = hitpart;
                self->act_preargh.unk040 = weaponid;
                self->sleep              = 0;
            }
            else
            {
                triggered_on_shot_hit(self, vector, angle, hitpart, weaponid);
            }
        }
    }

    return TRUE;
}




#ifdef NONMATCHING
void sub_GAME_7F027804(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051DEC
.word 0x40c90fdb /*6.2831855*/
glabel D_80051DF0
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F027804
/* 05C334 7F027804 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 05C338 7F027808 AFBF0024 */  sw    $ra, 0x24($sp)
/* 05C33C 7F02780C AFB00020 */  sw    $s0, 0x20($sp)
/* 05C340 7F027810 AFA60060 */  sw    $a2, 0x60($sp)
/* 05C344 7F027814 AFA70064 */  sw    $a3, 0x64($sp)
/* 05C348 7F027818 80830007 */  lb    $v1, 7($a0)
/* 05C34C 7F02781C 24010005 */  li    $at, 5
/* 05C350 7F027820 00808025 */  move  $s0, $a0
/* 05C354 7F027824 8C86001C */  lw    $a2, 0x1c($a0)
/* 05C358 7F027828 10610004 */  beq   $v1, $at, .L7F02783C
/* 05C35C 7F02782C 8C820018 */   lw    $v0, 0x18($a0)
/* 05C360 7F027830 24010004 */  li    $at, 4
/* 05C364 7F027834 54610004 */  bnel  $v1, $at, .L7F027848
/* 05C368 7F027838 8E0E0014 */   lw    $t6, 0x14($s0)
.L7F02783C:
/* 05C36C 7F02783C 100000E8 */  b     .L7F027BE0
/* 05C370 7F027840 00001025 */   move  $v0, $zero
/* 05C374 7F027844 8E0E0014 */  lw    $t6, 0x14($s0)
.L7F027848:
/* 05C378 7F027848 3C010020 */  lui   $at, 0x20
/* 05C37C 7F02784C 01C11825 */  or    $v1, $t6, $at
/* 05C380 7F027850 30780010 */  andi  $t8, $v1, 0x10
/* 05C384 7F027854 13000003 */  beqz  $t8, .L7F027864
/* 05C388 7F027858 AE030014 */   sw    $v1, 0x14($s0)
/* 05C38C 7F02785C 100000E0 */  b     .L7F027BE0
/* 05C390 7F027860 00001025 */   move  $v0, $zero
.L7F027864:
/* 05C394 7F027864 8219000B */  lb    $t9, 0xb($s0)
/* 05C398 7F027868 C60400FC */  lwc1  $f4, 0xfc($s0)
/* 05C39C 7F02786C 44805000 */  mtc1  $zero, $f10
/* 05C3A0 7F027870 27280001 */  addiu $t0, $t9, 1
/* 05C3A4 7F027874 A208000B */  sb    $t0, 0xb($s0)
/* 05C3A8 7F027878 C7A60060 */  lwc1  $f6, 0x60($sp)
/* 05C3AC 7F02787C 34690100 */  ori   $t1, $v1, 0x100
/* 05C3B0 7F027880 AE090014 */  sw    $t1, 0x14($s0)
/* 05C3B4 7F027884 46062200 */  add.s $f8, $f4, $f6
/* 05C3B8 7F027888 E60800FC */  swc1  $f8, 0xfc($s0)
/* 05C3BC 7F02788C C60400FC */  lwc1  $f4, 0xfc($s0)
/* 05C3C0 7F027890 4604503C */  c.lt.s $f10, $f4
/* 05C3C4 7F027894 00000000 */  nop   
/* 05C3C8 7F027898 450200D1 */  bc1fl .L7F027BE0
/* 05C3CC 7F02789C 00001025 */   move  $v0, $zero
/* 05C3D0 7F0278A0 C6060100 */  lwc1  $f6, 0x100($s0)
/* 05C3D4 7F0278A4 00C02025 */  move  $a0, $a2
/* 05C3D8 7F0278A8 E60600FC */  swc1  $f6, 0xfc($s0)
/* 05C3DC 7F0278AC AFA60054 */  sw    $a2, 0x54($sp)
/* 05C3E0 7F0278B0 AFA5005C */  sw    $a1, 0x5c($sp)
/* 05C3E4 7F0278B4 0FC1B320 */  jal   getsubroty
/* 05C3E8 7F0278B8 AFA20050 */   sw    $v0, 0x50($sp)
/* 05C3EC 7F0278BC 8FA20050 */  lw    $v0, 0x50($sp)
/* 05C3F0 7F0278C0 8FA5005C */  lw    $a1, 0x5c($sp)
/* 05C3F4 7F0278C4 E7A0004C */  swc1  $f0, 0x4c($sp)
/* 05C3F8 7F0278C8 C4440010 */  lwc1  $f4, 0x10($v0)
/* 05C3FC 7F0278CC C4480008 */  lwc1  $f8, 8($v0)
/* 05C400 7F0278D0 C4A60008 */  lwc1  $f6, 8($a1)
/* 05C404 7F0278D4 C4AA0000 */  lwc1  $f10, ($a1)
/* 05C408 7F0278D8 46062381 */  sub.s $f14, $f4, $f6
/* 05C40C 7F0278DC 0FC16A8C */  jal   atan2f
/* 05C410 7F0278E0 460A4301 */   sub.s $f12, $f8, $f10
/* 05C414 7F0278E4 8FA20050 */  lw    $v0, 0x50($sp)
/* 05C418 7F0278E8 8FA5005C */  lw    $a1, 0x5c($sp)
/* 05C41C 7F0278EC 44801000 */  mtc1  $zero, $f2
/* 05C420 7F0278F0 C4480008 */  lwc1  $f8, 8($v0)
/* 05C424 7F0278F4 C4AA0000 */  lwc1  $f10, ($a1)
/* 05C428 7F0278F8 46000406 */  mov.s $f16, $f0
/* 05C42C 7F0278FC 460A4101 */  sub.s $f4, $f8, $f10
/* 05C430 7F027900 E7A4002C */  swc1  $f4, 0x2c($sp)
/* 05C434 7F027904 C446000C */  lwc1  $f6, 0xc($v0)
/* 05C438 7F027908 C4A80004 */  lwc1  $f8, 4($a1)
/* 05C43C 7F02790C 46083281 */  sub.s $f10, $f6, $f8
/* 05C440 7F027910 E7AA0030 */  swc1  $f10, 0x30($sp)
/* 05C444 7F027914 C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 05C448 7F027918 C4440010 */  lwc1  $f4, 0x10($v0)
/* 05C44C 7F02791C C4A60008 */  lwc1  $f6, 8($a1)
/* 05C450 7F027920 460A1032 */  c.eq.s $f2, $f10
/* 05C454 7F027924 46062201 */  sub.s $f8, $f4, $f6
/* 05C458 7F027928 4500000E */  bc1f  .L7F027964
/* 05C45C 7F02792C E7A80034 */   swc1  $f8, 0x34($sp)
/* 05C460 7F027930 C7AE0030 */  lwc1  $f14, 0x30($sp)
/* 05C464 7F027934 C7B20034 */  lwc1  $f18, 0x34($sp)
/* 05C468 7F027938 460E1032 */  c.eq.s $f2, $f14
/* 05C46C 7F02793C 00000000 */  nop   
/* 05C470 7F027940 45020009 */  bc1fl .L7F027968
/* 05C474 7F027944 C7A0002C */   lwc1  $f0, 0x2c($sp)
/* 05C478 7F027948 46121032 */  c.eq.s $f2, $f18
/* 05C47C 7F02794C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 05C480 7F027950 45020005 */  bc1fl .L7F027968
/* 05C484 7F027954 C7A0002C */   lwc1  $f0, 0x2c($sp)
/* 05C488 7F027958 44819000 */  mtc1  $at, $f18
/* 05C48C 7F02795C 00000000 */  nop   
/* 05C490 7F027960 E7B20034 */  swc1  $f18, 0x34($sp)
.L7F027964:
/* 05C494 7F027964 C7A0002C */  lwc1  $f0, 0x2c($sp)
.L7F027968:
/* 05C498 7F027968 C7AE0030 */  lwc1  $f14, 0x30($sp)
/* 05C49C 7F02796C C7B20034 */  lwc1  $f18, 0x34($sp)
/* 05C4A0 7F027970 46000102 */  mul.s $f4, $f0, $f0
/* 05C4A4 7F027974 E7B00048 */  swc1  $f16, 0x48($sp)
/* 05C4A8 7F027978 460E7182 */  mul.s $f6, $f14, $f14
/* 05C4AC 7F02797C 46062200 */  add.s $f8, $f4, $f6
/* 05C4B0 7F027980 46129282 */  mul.s $f10, $f18, $f18
/* 05C4B4 7F027984 0C007DF8 */  jal   sqrtf
/* 05C4B8 7F027988 46085300 */   add.s $f12, $f10, $f8
/* 05C4BC 7F02798C 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 05C4C0 7F027990 44812000 */  mtc1  $at, $f4
/* 05C4C4 7F027994 C7A60060 */  lwc1  $f6, 0x60($sp)
/* 05C4C8 7F027998 C7A8002C */  lwc1  $f8, 0x2c($sp)
/* 05C4CC 7F02799C C7B00048 */  lwc1  $f16, 0x48($sp)
/* 05C4D0 7F0279A0 46062282 */  mul.s $f10, $f4, $f6
/* 05C4D4 7F0279A4 C7A60030 */  lwc1  $f6, 0x30($sp)
/* 05C4D8 7F0279A8 C7B2004C */  lwc1  $f18, 0x4c($sp)
/* 05C4DC 7F0279AC 4612803C */  c.lt.s $f16, $f18
/* 05C4E0 7F0279B0 46005083 */  div.s $f2, $f10, $f0
/* 05C4E4 7F0279B4 46128381 */  sub.s $f14, $f16, $f18
/* 05C4E8 7F0279B8 46007306 */  mov.s $f12, $f14
/* 05C4EC 7F0279BC 46024102 */  mul.s $f4, $f8, $f2
/* 05C4F0 7F0279C0 C7A80034 */  lwc1  $f8, 0x34($sp)
/* 05C4F4 7F0279C4 46023282 */  mul.s $f10, $f6, $f2
/* 05C4F8 7F0279C8 00000000 */  nop   
/* 05C4FC 7F0279CC 46024182 */  mul.s $f6, $f8, $f2
/* 05C500 7F0279D0 E7A4002C */  swc1  $f4, 0x2c($sp)
/* 05C504 7F0279D4 E7AA0030 */  swc1  $f10, 0x30($sp)
/* 05C508 7F0279D8 E7A60034 */  swc1  $f6, 0x34($sp)
/* 05C50C 7F0279DC E60400B0 */  swc1  $f4, 0xb0($s0)
/* 05C510 7F0279E0 C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 05C514 7F0279E4 E60A00B4 */  swc1  $f10, 0xb4($s0)
/* 05C518 7F0279E8 C7A80034 */  lwc1  $f8, 0x34($sp)
/* 05C51C 7F0279EC 45000004 */  bc1f  .L7F027A00
/* 05C520 7F0279F0 E60800B8 */   swc1  $f8, 0xb8($s0)
/* 05C524 7F0279F4 3C018005 */  lui   $at, %hi(D_80051DEC)
/* 05C528 7F0279F8 C4261DEC */  lwc1  $f6, %lo(D_80051DEC)($at)
/* 05C52C 7F0279FC 46067300 */  add.s $f12, $f14, $f6
.L7F027A00:
/* 05C530 7F027A00 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 05C534 7F027A04 44812000 */  mtc1  $at, $f4
/* 05C538 7F027A08 3C018005 */  lui   $at, %hi(D_80051DF0)
/* 05C53C 7F027A0C C4281DF0 */  lwc1  $f8, %lo(D_80051DF0)($at)
/* 05C540 7F027A10 46046282 */  mul.s $f10, $f12, $f4
/* 05C544 7F027A14 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 05C548 7F027A18 44812000 */  mtc1  $at, $f4
/* 05C54C 7F027A1C 46085183 */  div.s $f6, $f10, $f8
/* 05C550 7F027A20 46043280 */  add.s $f10, $f6, $f4
/* 05C554 7F027A24 4600520D */  trunc.w.s $f8, $f10
/* 05C558 7F027A28 44074000 */  mfc1  $a3, $f8
/* 05C55C 7F027A2C 00000000 */  nop   
/* 05C560 7F027A30 28E10008 */  slti  $at, $a3, 8
/* 05C564 7F027A34 14200002 */  bnez  $at, .L7F027A40
/* 05C568 7F027A38 00000000 */   nop   
/* 05C56C 7F027A3C 00003825 */  move  $a3, $zero
.L7F027A40:
/* 05C570 7F027A40 0C002914 */  jal   randomGetNext
/* 05C574 7F027A44 AFA70040 */   sw    $a3, 0x40($sp)
/* 05C578 7F027A48 8FA70040 */  lw    $a3, 0x40($sp)
/* 05C57C 7F027A4C 3C0C8003 */  lui   $t4, %hi(explosion_animation_table) 
/* 05C580 7F027A50 258CE960 */  addiu $t4, %lo(explosion_animation_table) # addiu $t4, $t4, -0x16a0
/* 05C584 7F027A54 000758C0 */  sll   $t3, $a3, 3
/* 05C588 7F027A58 016C2821 */  addu  $a1, $t3, $t4
/* 05C58C 7F027A5C 8CAD0004 */  lw    $t5, 4($a1)
/* 05C590 7F027A60 8CAE0000 */  lw    $t6, ($a1)
/* 05C594 7F027A64 3C088003 */  lui   $t0, %hi(D_8002E648) 
/* 05C598 7F027A68 004D001B */  divu  $zero, $v0, $t5
/* 05C59C 7F027A6C 00003010 */  mfhi  $a2
/* 05C5A0 7F027A70 01C67821 */  addu  $t7, $t6, $a2
/* 05C5A4 7F027A74 81F80000 */  lb    $t8, ($t7)
/* 05C5A8 7F027A78 2508E648 */  addiu $t0, %lo(D_8002E648) # addiu $t0, $t0, -0x19b8
/* 05C5AC 7F027A7C 15A00002 */  bnez  $t5, .L7F027A88
/* 05C5B0 7F027A80 00000000 */   nop   
/* 05C5B4 7F027A84 0007000D */  break 7
.L7F027A88:
/* 05C5B8 7F027A88 0018C8C0 */  sll   $t9, $t8, 3
/* 05C5BC 7F027A8C 0338C823 */  subu  $t9, $t9, $t8
/* 05C5C0 7F027A90 0019C880 */  sll   $t9, $t9, 2
/* 05C5C4 7F027A94 03281821 */  addu  $v1, $t9, $t0
/* 05C5C8 7F027A98 AFA30038 */  sw    $v1, 0x38($sp)
/* 05C5CC 7F027A9C 0FC0B461 */  jal   sub_GAME_7F02D184
/* 05C5D0 7F027AA0 02002025 */   move  $a0, $s0
/* 05C5D4 7F027AA4 8FA30038 */  lw    $v1, 0x38($sp)
/* 05C5D8 7F027AA8 24090004 */  li    $t1, 4
/* 05C5DC 7F027AAC A2090007 */  sb    $t1, 7($s0)
/* 05C5E0 7F027AB0 AE00002C */  sw    $zero, 0x2c($s0)
/* 05C5E4 7F027AB4 C4660014 */  lwc1  $f6, 0x14($v1)
/* 05C5E8 7F027AB8 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 05C5EC 7F027ABC 44812000 */  mtc1  $at, $f4
/* 05C5F0 7F027AC0 44805000 */  mtc1  $zero, $f10
/* 05C5F4 7F027AC4 E6060030 */  swc1  $f6, 0x30($s0)
/* 05C5F8 7F027AC8 A2000008 */  sb    $zero, 8($s0)
/* 05C5FC 7F027ACC E6040034 */  swc1  $f4, 0x34($s0)
/* 05C600 7F027AD0 E60A0038 */  swc1  $f10, 0x38($s0)
/* 05C604 7F027AD4 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 05C608 7F027AD8 3C0B8007 */  lui   $t3, %hi(ptr_animation_table) 
/* 05C60C 7F027ADC 8D6B9538 */  lw    $t3, %lo(ptr_animation_table)($t3)
/* 05C610 7F027AE0 44813000 */  mtc1  $at, $f6
/* 05C614 7F027AE4 C4680008 */  lwc1  $f8, 8($v1)
/* 05C618 7F027AE8 8C6A0000 */  lw    $t2, ($v1)
/* 05C61C 7F027AEC 8C67000C */  lw    $a3, 0xc($v1)
/* 05C620 7F027AF0 8C660004 */  lw    $a2, 4($v1)
/* 05C624 7F027AF4 8FA40054 */  lw    $a0, 0x54($sp)
/* 05C628 7F027AF8 E7A60014 */  swc1  $f6, 0x14($sp)
/* 05C62C 7F027AFC E7A80010 */  swc1  $f8, 0x10($sp)
/* 05C630 7F027B00 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 05C634 7F027B04 014B2821 */   addu  $a1, $t2, $t3
/* 05C638 7F027B08 8FA30038 */  lw    $v1, 0x38($sp)
/* 05C63C 7F027B0C 44802000 */  mtc1  $zero, $f4
/* 05C640 7F027B10 C4600018 */  lwc1  $f0, 0x18($v1)
/* 05C644 7F027B14 4600203E */  c.le.s $f4, $f0
/* 05C648 7F027B18 00000000 */  nop   
/* 05C64C 7F027B1C 45020005 */  bc1fl .L7F027B34
/* 05C650 7F027B20 8FAC0064 */   lw    $t4, 0x64($sp)
/* 05C654 7F027B24 44050000 */  mfc1  $a1, $f0
/* 05C658 7F027B28 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 05C65C 7F027B2C 8FA40054 */   lw    $a0, 0x54($sp)
/* 05C660 7F027B30 8FAC0064 */  lw    $t4, 0x64($sp)
.L7F027B34:
/* 05C664 7F027B34 11800003 */  beqz  $t4, .L7F027B44
/* 05C668 7F027B38 00000000 */   nop   
/* 05C66C 7F027B3C 0FC09C18 */  jal   play_sound_for_shot_actor
/* 05C670 7F027B40 02002025 */   move  $a0, $s0
.L7F027B44:
/* 05C674 7F027B44 0FC086C8 */  jal   sub_GAME_7F021B20
/* 05C678 7F027B48 02002025 */   move  $a0, $s0
/* 05C67C 7F027B4C 0FC1A9E0 */  jal   increment_num_kills_display_text_in_MP
/* 05C680 7F027B50 00000000 */   nop   
/* 05C684 7F027B54 8E0D0014 */  lw    $t5, 0x14($s0)
/* 05C688 7F027B58 000D72C0 */  sll   $t6, $t5, 0xb
/* 05C68C 7F027B5C 05C30004 */  bgezl $t6, .L7F027B70
/* 05C690 7F027B60 8E040160 */   lw    $a0, 0x160($s0)
/* 05C694 7F027B64 0FC1A9D6 */  jal   inc_cur_civilian_casualties
/* 05C698 7F027B68 00000000 */   nop   
/* 05C69C 7F027B6C 8E040160 */  lw    $a0, 0x160($s0)
.L7F027B70:
/* 05C6A0 7F027B70 5080000C */  beql  $a0, $zero, .L7F027BA4
/* 05C6A4 7F027B74 8E040164 */   lw    $a0, 0x164($s0)
/* 05C6A8 7F027B78 8C8F0004 */  lw    $t7, 4($a0)
/* 05C6AC 7F027B7C 8DF80008 */  lw    $t8, 8($t7)
/* 05C6B0 7F027B80 33192000 */  andi  $t9, $t8, 0x2000
/* 05C6B4 7F027B84 57200007 */  bnezl $t9, .L7F027BA4
/* 05C6B8 7F027B88 8E040164 */   lw    $a0, 0x164($s0)
/* 05C6BC 7F027B8C 0FC12FF4 */  jal   sub_GAME_7F04BFD0
/* 05C6C0 7F027B90 24050001 */   li    $a1, 1
/* 05C6C4 7F027B94 96080012 */  lhu   $t0, 0x12($s0)
/* 05C6C8 7F027B98 35090001 */  ori   $t1, $t0, 1
/* 05C6CC 7F027B9C A6090012 */  sh    $t1, 0x12($s0)
/* 05C6D0 7F027BA0 8E040164 */  lw    $a0, 0x164($s0)
.L7F027BA4:
/* 05C6D4 7F027BA4 1080000B */  beqz  $a0, .L7F027BD4
/* 05C6D8 7F027BA8 00000000 */   nop   
/* 05C6DC 7F027BAC 8C8A0004 */  lw    $t2, 4($a0)
/* 05C6E0 7F027BB0 8D4B0008 */  lw    $t3, 8($t2)
/* 05C6E4 7F027BB4 316C2000 */  andi  $t4, $t3, 0x2000
/* 05C6E8 7F027BB8 15800006 */  bnez  $t4, .L7F027BD4
/* 05C6EC 7F027BBC 00000000 */   nop   
/* 05C6F0 7F027BC0 0FC12FF4 */  jal   sub_GAME_7F04BFD0
/* 05C6F4 7F027BC4 24050001 */   li    $a1, 1
/* 05C6F8 7F027BC8 960D0012 */  lhu   $t5, 0x12($s0)
/* 05C6FC 7F027BCC 35AE0001 */  ori   $t6, $t5, 1
/* 05C700 7F027BD0 A60E0012 */  sh    $t6, 0x12($s0)
.L7F027BD4:
/* 05C704 7F027BD4 10000002 */  b     .L7F027BE0
/* 05C708 7F027BD8 24020001 */   li    $v0, 1
/* 05C70C 7F027BDC 00001025 */  move  $v0, $zero
.L7F027BE0:
/* 05C710 7F027BE0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 05C714 7F027BE4 8FB00020 */  lw    $s0, 0x20($sp)
/* 05C718 7F027BE8 27BD0058 */  addiu $sp, $sp, 0x58
/* 05C71C 7F027BEC 03E00008 */  jr    $ra
/* 05C720 7F027BF0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
/**
 * Address 0x7F027BF4.
*/
struct path_table_alt *get_ptrpreset_in_table_matching_tile(struct StandTile* arg0)
{
    struct path_table_alt *path;
    struct pad *preset;

    if (ptr_setup_path_tbl != NULL)
    {
        for (path = ptr_setup_path_tbl; path->id >= 0; path++)
        {
            preset = &((struct pad *)ptr_0xxxpresets)[path->id];

            if (preset->stan == arg0)
            {
                return path;
            }
        }
    }

    return NULL;
}
#else
GLOBAL_ASM(
.text
glabel get_ptrpreset_in_table_matching_tile
/* 05C724 7F027BF4 3C028007 */  lui   $v0, %hi(ptr_setup_path_tbl)
/* 05C728 7F027BF8 8C425D00 */  lw    $v0, %lo(ptr_setup_path_tbl)($v0)
/* 05C72C 7F027BFC 00803025 */  move  $a2, $a0
/* 05C730 7F027C00 50400015 */  beql  $v0, $zero, .L7F027C58
/* 05C734 7F027C04 00001025 */   move  $v0, $zero
/* 05C738 7F027C08 8C4E0000 */  lw    $t6, ($v0)
/* 05C73C 7F027C0C 00401825 */  move  $v1, $v0
/* 05C740 7F027C10 3C058007 */  lui   $a1, %hi(ptr_0xxxpresets)
/* 05C744 7F027C14 05C0000F */  bltz  $t6, .L7F027C54
/* 05C748 7F027C18 2407002C */   li    $a3, 44
/* 05C74C 7F027C1C 8C440000 */  lw    $a0, ($v0)
/* 05C750 7F027C20 8CA55D18 */  lw    $a1, %lo(ptr_0xxxpresets)($a1)
.L7F027C24:
/* 05C754 7F027C24 00870019 */  multu $a0, $a3
/* 05C758 7F027C28 00007812 */  mflo  $t7
/* 05C75C 7F027C2C 01E51021 */  addu  $v0, $t7, $a1
/* 05C760 7F027C30 8C580028 */  lw    $t8, 0x28($v0)
/* 05C764 7F027C34 54D80004 */  bnel  $a2, $t8, .L7F027C48
/* 05C768 7F027C38 8C640010 */   lw    $a0, 0x10($v1)
/* 05C76C 7F027C3C 03E00008 */  jr    $ra
/* 05C770 7F027C40 00601025 */   move  $v0, $v1

/* 05C774 7F027C44 8C640010 */  lw    $a0, 0x10($v1)
.L7F027C48:
/* 05C778 7F027C48 24630010 */  addiu $v1, $v1, 0x10
/* 05C77C 7F027C4C 0481FFF5 */  bgez  $a0, .L7F027C24
/* 05C780 7F027C50 00000000 */   nop   
.L7F027C54:
/* 05C784 7F027C54 00001025 */  move  $v0, $zero
.L7F027C58:
/* 05C788 7F027C58 03E00008 */  jr    $ra
/* 05C78C 7F027C5C 00000000 */   nop   
)
#endif



/**
 * Address 0x7F027C60.
*/
s32 check_if_any_path_preset_lies_on_tile(struct StandTile* arg0)
{
    return get_ptrpreset_in_table_matching_tile(arg0) != NULL;
}


/**
 * 100% match, unsure of argument types.
 * Addresss 0x7F027C84.
*/
f32 chrlvPadPresetRelated(struct coord3d *arg0, struct path_table_alt *arg1)
{
    f32 temp_f12;
    f32 temp_f2;
    struct pad *temp_v0;

    temp_v0 = &ptr_0xxxpresets[arg1->id];
    temp_f2 = temp_v0->pos.f[0] - arg0->f[0];
    temp_f12 = temp_v0->pos.f[2] - arg0->f[2];
    return (temp_f2 * temp_f2) + (temp_f12 * temp_f12);
}



/**
 * Address 0x7F027CD4.
*/
struct path_table_alt *chrlvStanPathRelated(struct coord3d *arg0, StandTile *arg1)
{
    StandTile *tile = NULL;
    f32 temp_f20;
    struct path_table_alt *ret = NULL;
    struct path_table_alt *wayp = NULL;
    s32 *n = NULL;
    
    tile = sub_GAME_7F0B2718(arg1, check_if_any_path_preset_lies_on_tile);
    if (tile != NULL)
    {
        ret = get_ptrpreset_in_table_matching_tile(tile);
        
        if (ret != NULL)
        {
            temp_f20 = chrlvPadPresetRelated(arg0, ret);

            for (n = ret->neighbours; *n >= 0; n++)
            {
                wayp = &ptr_setup_path_tbl[*n];
                
                if (chrlvPadPresetRelated(arg0, wayp) < temp_f20)
                {
                    ret = wayp;
                }
            }
        }
    }

    return ret;
}




/**
 * Address 0x7F027DB0.
*/
s32 chrlvStanRoomRelated(ChrRecord *arg0, struct coord3d *arg1, StandTile *tile)
{

#define BUFFER_SIZE_7F027DB0 0x14

    s32 sp48[BUFFER_SIZE_7F027DB0];
    PropRecord *prop;
    s32 tile_something;
    s32 i;

    prop = arg0->prop;
    tile_something = sub_GAME_7F0B0D0C(prop->stan, prop->pos.x, prop->pos.f[2], &tile, arg1->f[0], arg1->f[2], &sp48[0], BUFFER_SIZE_7F027DB0);

    if (tile_something > 0 && tile_something < BUFFER_SIZE_7F027DB0)
    {
        for (i=0; i<tile_something; i++)
        {
            if (getROOMID_Bitflags(sp48[i]) != 0)
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }

    return 1;
}



/**
 * Address 0x7F027E70.
*/
s32 chrlvStanRoomRelatedPad(ChrRecord *arg0, struct pad *arg1)
{
    return chrlvStanRoomRelated(arg0, &arg1->pos, arg1->stan);
}




/**
 * Address 0x7F027E90.
*/
void chrlvSetGoposSegDistTotal(struct ChrRecord *arg0, struct waydata *arg1, struct coord3d *arg2)
{
    PropRecord *prop;
    f32 dx;
    f32 dz;
    f32 sp18;

    prop = arg0->prop;
    dx = arg2->f[0] - prop->pos.f[0];
    dz = arg2->f[2] - prop->pos.f[2];

    sp18 = atan2f(dx, dz);

    arg1->mode = 6;
    arg1->segdistdone = 0.0f;
    arg1->segdisttotal = sqrtf((dx * dx) + (dz * dz));

    setsubroty(arg0->model, sp18);
}


/**
 * @param arg0:
 * @param target_point: out paramter, will contain target position
 * @param target_stan: out parameter, will contain pointer to target stan
 * 
 * Address 0x7F027F20.
*/
void chrlvActGoposRelated(struct ChrRecord *arg0, struct coord3d *target_point, struct StandTile **target_stan)
{
    struct waypoint *temp_v0;
    struct pad *temp_v1;

    temp_v0 = arg0->act_gopos.waypoints[arg0->act_gopos.curindex];

    if (temp_v0 != 0)
    {
        temp_v1 = &ptr_0xxxpresets[temp_v0->PadID];

        target_point->f[0] = temp_v1->pos.f[0];
        target_point->f[1] = temp_v1->pos.f[1];
        target_point->f[2] = temp_v1->pos.f[2];

        *target_stan = temp_v1->stan;
    }
    else
    {
        target_point->f[0] = arg0->act_gopos.targetpos.f[0];
        target_point->f[1] = arg0->act_gopos.targetpos.f[1];
        target_point->f[2] = arg0->act_gopos.targetpos.f[2];

        *target_stan = arg0->act_gopos.target;
    }
}



/**
 * Address 0x7F027FA8.
*/
f32 chrlvModelScaleAnimationRelated(struct ChrRecord *arg0)
{
    f32 scale_factor = D_80030984;

    if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_sprinting])
    {
        scale_factor = D_8003098C;
    }
    else if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running])
    {
        scale_factor = D_80030988;
    }
    else if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ANIM_DATA_sprinting_one_handed_weapon + (s32)&ptr_animation_table->data[0])
    {
        scale_factor = D_80030998;
    }
    else if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon])
    {
        scale_factor = D_80030994;
    }
    else if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_unarmed])
    {
        scale_factor = D_80030990;
    }
    // typo/mistake, `ANIM_DATA_sprinting_one_handed_weapon` is duplicate of above.
    // compiler swaps addition order when reading this from the stack, unlike addresses only seen once (seen once means not saved to stack).
    else if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ANIM_DATA_sprinting_one_handed_weapon + (s32)&ptr_animation_table->data[0])
    {
        scale_factor = D_800309A4;
    }
    else if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running_female])
    {
        scale_factor = D_800309A0;
    }
    else if ((s32)sub_GAME_7F06F5AC(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_female])
    {
        scale_factor = D_8003099C;
    }

    return arg0->model->scale * scale_factor * 9.999999f;
}





/**
 * Address 0x7F028144.
*/
s32 chrlvMovementTargetRelated(ChrRecord *arg0)
{
    f32 dx;
    f32 dz;
    PropRecord *temp_v0;
    struct coord3d sp20; // sp32
    StandTile *sp1C; // 28
    f32 sp18; // 24

    sp18 = sub_GAME_7F06F618(arg0->model);
    chrlvActGoposRelated(arg0, &sp20, &sp1C);
    temp_v0 = arg0->prop;
    dx = sp20.f[0] - temp_v0->pos.f[0];
    dz = sp20.f[2] - temp_v0->pos.f[2];

    if (dx < 0.0f)
    {
        dx = -dx;
    }

    if (dz < 0.0f)
    {
        dz = -dz;
    }

    return (s32) ((dx + dz) / (chrlvModelScaleAnimationRelated(arg0) * sp18));
}



/**
 * Address 0x7F0281F4.
*/
void sub_GAME_7F0281F4(struct ChrRecord *arg0)
{
    arg0->act_gopos.unk5a = 0;
}


/* VERSION_US, VERSION_JP */
#ifndef VERSION_EU
/**
 * Address 0x7F0281FC (US,JP)
 * Address 0x7F028214 (VERSION_EU)
*/
void chrlvPlotCourseRelated(struct ChrRecord *arg0)
{
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;

    if (arg0->act_gopos.waydata.mode != 6)
    {
        temp_v0 = arg0->act_gopos.unk5a;

        if (temp_v0 == 0)
        {
#ifndef VERSION_EU
            temp_a1 = (chrlvMovementTargetRelated(arg0) * 2) + 300;
#else
            temp_a1 = ((chrlvMovementTargetRelated(arg0) * 100) + 15000) / 60;
#endif

            if (temp_a1 >= 0x10000)
            {
                temp_a1 = (u16)-1;
            }

            arg0->act_gopos.unk5a = (s16)temp_a1;

            return;
        }

        temp_v1 = (u16)g_ClockTimer;

        if (temp_v1 >= temp_v0)
        {
            plot_course_for_actor(arg0, &arg0->act_gopos, arg0->act_gopos.target, arg0->act_gopos.unk59);
            
            return;
        }

        arg0->act_gopos.unk5a = (u16) (temp_v0 - temp_v1);
    }
}
#else
/* VERSION_EU */

#ifdef NONMATCHING
// implemented above, but untested
#else

GLOBAL_ASM(
.text
glabel chrlvPlotCourseRelated
/* 05AC04 7F028214 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 05AC08 7F028218 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05AC0C 7F02821C 808E005C */  lb    $t6, 0x5c($a0)
/* 05AC10 7F028220 24010006 */  li    $at, 6
/* 05AC14 7F028224 51C10023 */  beql  $t6, $at, .L7F0282B4
/* 05AC18 7F028228 8FBF0014 */   lw    $ra, 0x14($sp)
/* 05AC1C 7F02822C 9482005A */  lhu   $v0, 0x5a($a0)
/* 05AC20 7F028230 3C038004 */  lui   $v1, %hi(g_ClockTimer+2)
/* 05AC24 7F028234 14400013 */  bnez  $v0, .L7F028284
/* 05AC28 7F028238 00000000 */   nop   
/* 05AC2C 7F02823C 0FC0A057 */  jal   chrlvMovementTargetRelated
/* 05AC30 7F028240 AFA40018 */   sw    $a0, 0x18($sp)
/* 05AC34 7F028244 00021880 */  sll   $v1, $v0, 2
/* 05AC38 7F028248 00621823 */  subu  $v1, $v1, $v0
/* 05AC3C 7F02824C 000318C0 */  sll   $v1, $v1, 3
/* 05AC40 7F028250 00621821 */  addu  $v1, $v1, $v0
/* 05AC44 7F028254 00031880 */  sll   $v1, $v1, 2
/* 05AC48 7F028258 24633A98 */  addiu $v1, $v1, 0x3a98
/* 05AC4C 7F02825C 2401003C */  li    $at, 60
/* 05AC50 7F028260 0061001A */  div   $zero, $v1, $at
/* 05AC54 7F028264 00002812 */  mflo  $a1
/* 05AC58 7F028268 3C010001 */  lui   $at, 1
/* 05AC5C 7F02826C 00A1082A */  slt   $at, $a1, $at
/* 05AC60 7F028270 14200002 */  bnez  $at, .L7F02827C
/* 05AC64 7F028274 8FA40018 */   lw    $a0, 0x18($sp)
/* 05AC68 7F028278 3405FFFF */  li    $a1, 65535
.L7F02827C:
/* 05AC6C 7F02827C 1000000C */  b     .L7F0282B0
/* 05AC70 7F028280 A485005A */   sh    $a1, 0x5a($a0)
.L7F028284:
/* 05AC74 7F028284 94630FF6 */  lhu   $v1, %lo(g_ClockTimer+2)($v1)
/* 05AC78 7F028288 2485002C */  addiu $a1, $a0, 0x2c
/* 05AC7C 7F02828C 0062082A */  slt   $at, $v1, $v0
/* 05AC80 7F028290 14200006 */  bnez  $at, .L7F0282AC
/* 05AC84 7F028294 0043C023 */   subu  $t8, $v0, $v1
/* 05AC88 7F028298 8C860038 */  lw    $a2, 0x38($a0)
/* 05AC8C 7F02829C 0FC0A384 */  jal   plot_course_for_actor
/* 05AC90 7F0282A0 90870059 */   lbu   $a3, 0x59($a0)
/* 05AC94 7F0282A4 10000003 */  b     .L7F0282B4
/* 05AC98 7F0282A8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0282AC:
/* 05AC9C 7F0282AC A498005A */  sh    $t8, 0x5a($a0)
.L7F0282B0:
/* 05ACA0 7F0282B0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0282B4:
/* 05ACA4 7F0282B4 27BD0018 */  addiu $sp, $sp, 0x18
/* 05ACA8 7F0282B8 03E00008 */  jr    $ra
/* 05ACAC 7F0282BC 00000000 */   nop   
)
#endif
#endif



/**
 * Address 0x7F02828C.
*/
void chrlvActGoposSetTargetPosRelated(ChrRecord *arg0)
{
    struct coord3d sp1C;
    StandTile *sp18;

    chrlvActGoposRelated(arg0, (struct coord3d *) &sp1C, &sp18);

    arg0->act_gopos.waydata.mode = 0;
    arg0->act_gopos.waydata.unk01 = 0;
    arg0->act_gopos.waydata.unk02 = 0;

    arg0->act_gopos.waydata.pos.f[0] = sp1C.f[0];
    arg0->act_gopos.waydata.pos.f[1] = sp1C.f[1];
    arg0->act_gopos.waydata.pos.f[2] = sp1C.f[2];

    sub_GAME_7F0281F4(arg0);
}



/**
 * Address 0x7F0282E0.
*/
void chrlvActGoposIncCurIndex(struct ChrRecord *arg0)
{
    if (arg0->act_gopos.curindex < 3)
    {
        arg0->act_gopos.curindex++;
    }
    else
    {
        struct path_table_alt * p = arg0->act_gopos.waypoints[arg0->act_gopos.curindex];

        arg0->act_gopos.curindex = 1;

        sub_GAME_7F08F4F0(p, arg0->act_gopos.target_path, &arg0->act_gopos.waypoints, MAX_CHRWAYPOINTS);
    }

    chrlvActGoposSetTargetPosRelated(arg0);
}



#ifdef NONMATCHING
void sub_GAME_7F028348(void) {
// param arg0: unknown. If this is chrrecord, need to know action type. doesn't look like gopos.
// param arg1: out parameter, integral type
// param arg2: integral type
// tentative signature: s32 sub_GAME_7F028348(void *arg0, s32 *arg1, s32 arg2)
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F028348
/* 05CE78 7F028348 8C830030 */  lw    $v1, 0x30($a0)
/* 05CE7C 7F02834C 04C10004 */  bgez  $a2, .L7F028360
/* 05CE80 7F028350 8CA70000 */   lw    $a3, ($a1)
/* 05CE84 7F028354 2CEE0001 */  sltiu $t6, $a3, 1
/* 05CE88 7F028358 01C03825 */  move  $a3, $t6
/* 05CE8C 7F02835C 00063023 */  negu  $a2, $a2
.L7F028360:
/* 05CE90 7F028360 58C00024 */  blezl $a2, .L7F0283F4
/* 05CE94 7F028364 ACA70000 */   sw    $a3, ($a1)
.L7F028368:
/* 05CE98 7F028368 10E00012 */  beqz  $a3, .L7F0283B4
/* 05CE9C 7F02836C 24C6FFFF */   addiu $a2, $a2, -1
/* 05CEA0 7F028370 8C82002C */  lw    $v0, 0x2c($a0)
/* 05CEA4 7F028374 24630001 */  addiu $v1, $v1, 1
/* 05CEA8 7F028378 0003C080 */  sll   $t8, $v1, 2
/* 05CEAC 7F02837C 8C4F0000 */  lw    $t7, ($v0)
/* 05CEB0 7F028380 01F8C821 */  addu  $t9, $t7, $t8
/* 05CEB4 7F028384 8F280000 */  lw    $t0, ($t9)
/* 05CEB8 7F028388 05010017 */  bgez  $t0, .L7F0283E8
/* 05CEBC 7F02838C 00000000 */   nop   
/* 05CEC0 7F028390 90490005 */  lbu   $t1, 5($v0)
/* 05CEC4 7F028394 2463FFFE */  addiu $v1, $v1, -2
/* 05CEC8 7F028398 312A0001 */  andi  $t2, $t1, 1
/* 05CECC 7F02839C 11400003 */  beqz  $t2, .L7F0283AC
/* 05CED0 7F0283A0 00000000 */   nop   
/* 05CED4 7F0283A4 10000010 */  b     .L7F0283E8
/* 05CED8 7F0283A8 00001825 */   move  $v1, $zero
.L7F0283AC:
/* 05CEDC 7F0283AC 1000000E */  b     .L7F0283E8
/* 05CEE0 7F0283B0 00003825 */   move  $a3, $zero
.L7F0283B4:
/* 05CEE4 7F0283B4 2463FFFF */  addiu $v1, $v1, -1
/* 05CEE8 7F0283B8 0461000B */  bgez  $v1, .L7F0283E8
/* 05CEEC 7F0283BC 00000000 */   nop   
/* 05CEF0 7F0283C0 8C82002C */  lw    $v0, 0x2c($a0)
/* 05CEF4 7F0283C4 24030001 */  li    $v1, 1
/* 05CEF8 7F0283C8 904B0005 */  lbu   $t3, 5($v0)
/* 05CEFC 7F0283CC 316C0001 */  andi  $t4, $t3, 1
/* 05CF00 7F0283D0 51800005 */  beql  $t4, $zero, .L7F0283E8
/* 05CF04 7F0283D4 24070001 */   li    $a3, 1
/* 05CF08 7F0283D8 94430006 */  lhu   $v1, 6($v0)
/* 05CF0C 7F0283DC 10000002 */  b     .L7F0283E8
/* 05CF10 7F0283E0 2463FFFF */   addiu $v1, $v1, -1
/* 05CF14 7F0283E4 24070001 */  li    $a3, 1
.L7F0283E8:
/* 05CF18 7F0283E8 1CC0FFDF */  bgtz  $a2, .L7F028368
/* 05CF1C 7F0283EC 00000000 */   nop   
/* 05CF20 7F0283F0 ACA70000 */  sw    $a3, ($a1)
.L7F0283F4:
/* 05CF24 7F0283F4 03E00008 */  jr    $ra
/* 05CF28 7F0283F8 00601025 */   move  $v0, $v1
)
#endif



#ifdef NONMATCHING
// s32 sub_GAME_7F028348(void *arg0, s32 *arg1, s32 arg2);

s32 sub_GAME_7F0283FC(struct ChrRecord *arg0, s32 arg1)
{
    // act_patrol ???

    s32 sp20;
    s32 *temp_a1;

    temp_a1 = &sp20;
    sp20 = arg0->unk34;

    // struct path_table_alt * ptr_setup_path_tbl

    return (ptr_setup_path_tbl.unk0[*(*arg0->unk2C + (sub_GAME_7F028348(temp_a1, arg1) * 4))].id * 0x2C) + ptr_setup_path_tbl.unk18;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0283FC
/* 05CF2C 7F0283FC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 05CF30 7F028400 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05CF34 7F028404 8C8E0034 */  lw    $t6, 0x34($a0)
/* 05CF38 7F028408 00A03025 */  move  $a2, $a1
/* 05CF3C 7F02840C 27A50020 */  addiu $a1, $sp, 0x20
/* 05CF40 7F028410 AFA40028 */  sw    $a0, 0x28($sp)
/* 05CF44 7F028414 0FC0A0D2 */  jal   sub_GAME_7F028348
/* 05CF48 7F028418 AFAE0020 */   sw    $t6, 0x20($sp)
/* 05CF4C 7F02841C 8FA70028 */  lw    $a3, 0x28($sp)
/* 05CF50 7F028420 0002C880 */  sll   $t9, $v0, 2
/* 05CF54 7F028424 3C058007 */  lui   $a1, %hi(ptr_setup_path_tbl)
/* 05CF58 7F028428 8CEF002C */  lw    $t7, 0x2c($a3)
/* 05CF5C 7F02842C 24A55D00 */  addiu $a1, %lo(ptr_setup_path_tbl) # addiu $a1, $a1, 0x5d00
/* 05CF60 7F028430 8CAA0000 */  lw    $t2, ($a1)
/* 05CF64 7F028434 8DF80000 */  lw    $t8, ($t7)
/* 05CF68 7F028438 8FBF0014 */  lw    $ra, 0x14($sp)
/* 05CF6C 7F02843C 8CAD0018 */  lw    $t5, 0x18($a1)
/* 05CF70 7F028440 03191821 */  addu  $v1, $t8, $t9
/* 05CF74 7F028444 8C680000 */  lw    $t0, ($v1)
/* 05CF78 7F028448 00084900 */  sll   $t1, $t0, 4
/* 05CF7C 7F02844C 012A2021 */  addu  $a0, $t1, $t2
/* 05CF80 7F028450 8C8B0000 */  lw    $t3, ($a0)
/* 05CF84 7F028454 27BD0028 */  addiu $sp, $sp, 0x28
/* 05CF88 7F028458 000B6080 */  sll   $t4, $t3, 2
/* 05CF8C 7F02845C 018B6023 */  subu  $t4, $t4, $t3
/* 05CF90 7F028460 000C6080 */  sll   $t4, $t4, 2
/* 05CF94 7F028464 018B6023 */  subu  $t4, $t4, $t3
/* 05CF98 7F028468 000C6080 */  sll   $t4, $t4, 2
/* 05CF9C 7F02846C 03E00008 */  jr    $ra
/* 05CFA0 7F028470 018D1021 */   addu  $v0, $t4, $t5
)
#endif



/**
 * Unknown return type.
 * 
 * Address 0x7F028474.
*/
void * sub_GAME_7F028474(struct ChrRecord *arg0)
{
    return sub_GAME_7F0283FC(arg0, 0);
}


/**
 * Address 0x7F028494.
*/
void sub_GAME_7F028494(struct ChrRecord *arg0)
{
    struct coord3d *temp_v0; // or maybe struct pad.

    temp_v0 = sub_GAME_7F028474(arg0);
    arg0->act_patrol.waydata.mode = 0;
    arg0->act_patrol.waydata.unk01 = 0;
    arg0->act_patrol.waydata.unk02 = 0;
    arg0->act_patrol.waydata.pos.f[0] = temp_v0->f[0];
    arg0->act_patrol.waydata.pos.f[1] = temp_v0->f[1];
    arg0->act_patrol.waydata.pos.f[2] = temp_v0->f[2];
}




/**
 * Address 0x7F0284DC.
*/
void sub_GAME_7F0284DC(struct ChrRecord *arg0)
{
    arg0->act_patrol.nextstep = sub_GAME_7F028348(arg0, &arg0->act_patrol.forward, 1);
    sub_GAME_7F028494(arg0);
}



#ifdef NONMATCHING
void sub_GAME_7F028510(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F028510
/* 05D040 7F028510 27BDFF90 */  addiu $sp, $sp, -0x70
/* 05D044 7F028514 AFBF0034 */  sw    $ra, 0x34($sp)
/* 05D048 7F028518 AFB60030 */  sw    $s6, 0x30($sp)
/* 05D04C 7F02851C AFB5002C */  sw    $s5, 0x2c($sp)
/* 05D050 7F028520 AFB40028 */  sw    $s4, 0x28($sp)
/* 05D054 7F028524 AFB30024 */  sw    $s3, 0x24($sp)
/* 05D058 7F028528 AFB20020 */  sw    $s2, 0x20($sp)
/* 05D05C 7F02852C AFB1001C */  sw    $s1, 0x1c($sp)
/* 05D060 7F028530 AFB00018 */  sw    $s0, 0x18($sp)
/* 05D064 7F028534 90AE0003 */  lbu   $t6, 3($a1)
/* 05D068 7F028538 00808825 */  move  $s1, $a0
/* 05D06C 7F02853C 240FFFFF */  li    $t7, -1
/* 05D070 7F028540 AFAF0054 */  sw    $t7, 0x54($sp)
/* 05D074 7F028544 27A40050 */  addiu $a0, $sp, 0x50
/* 05D078 7F028548 0FC0F8FF */  jal   sub_GAME_7F03E3FC
/* 05D07C 7F02854C AFAE0050 */   sw    $t6, 0x50($sp)
/* 05D080 7F028550 3C108007 */  lui   $s0, %hi(ptr_list_object_lookup_indices)
/* 05D084 7F028554 8E109C30 */  lw    $s0, %lo(ptr_list_object_lookup_indices)($s0)
/* 05D088 7F028558 3C138007 */  lui   $s3, %hi(pos_data_entry)
/* 05D08C 7F02855C 26739C38 */  addiu $s3, %lo(pos_data_entry) # addiu $s3, $s3, -0x63c8
/* 05D090 7F028560 86020000 */  lh    $v0, ($s0)
/* 05D094 7F028564 27B60040 */  addiu $s6, $sp, 0x40
/* 05D098 7F028568 27B50044 */  addiu $s5, $sp, 0x44
/* 05D09C 7F02856C 04400019 */  bltz  $v0, .L7F0285D4
/* 05D0A0 7F028570 24140001 */   li    $s4, 1
/* 05D0A4 7F028574 24120034 */  li    $s2, 52
.L7F028578:
/* 05D0A8 7F028578 00520019 */  multu $v0, $s2
/* 05D0AC 7F02857C 02A02825 */  move  $a1, $s5
/* 05D0B0 7F028580 0000C012 */  mflo  $t8
/* 05D0B4 7F028584 03132021 */  addu  $a0, $t8, $s3
/* 05D0B8 7F028588 90990000 */  lbu   $t9, ($a0)
/* 05D0BC 7F02858C 5699000E */  bnel  $s4, $t9, .L7F0285C8
/* 05D0C0 7F028590 86020002 */   lh    $v0, 2($s0)
/* 05D0C4 7F028594 0FC0F32C */  jal   sub_GAME_7F03CCB0
/* 05D0C8 7F028598 02C03025 */   move  $a2, $s6
/* 05D0CC 7F02859C 8FA60040 */  lw    $a2, 0x40($sp)
/* 05D0D0 7F0285A0 02202025 */  move  $a0, $s1
/* 05D0D4 7F0285A4 58C00008 */  blezl $a2, .L7F0285C8
/* 05D0D8 7F0285A8 86020002 */   lh    $v0, 2($s0)
/* 05D0DC 7F0285AC 0FC0F336 */  jal   sub_GAME_7F03CCD8
/* 05D0E0 7F0285B0 8FA50044 */   lw    $a1, 0x44($sp)
/* 05D0E4 7F0285B4 50400004 */  beql  $v0, $zero, .L7F0285C8
/* 05D0E8 7F0285B8 86020002 */   lh    $v0, 2($s0)
/* 05D0EC 7F0285BC 10000006 */  b     .L7F0285D8
/* 05D0F0 7F0285C0 00001025 */   move  $v0, $zero
/* 05D0F4 7F0285C4 86020002 */  lh    $v0, 2($s0)
.L7F0285C8:
/* 05D0F8 7F0285C8 26100002 */  addiu $s0, $s0, 2
/* 05D0FC 7F0285CC 0441FFEA */  bgez  $v0, .L7F028578
/* 05D100 7F0285D0 00000000 */   nop   
.L7F0285D4:
/* 05D104 7F0285D4 24020001 */  li    $v0, 1
.L7F0285D8:
/* 05D108 7F0285D8 8FBF0034 */  lw    $ra, 0x34($sp)
/* 05D10C 7F0285DC 8FB00018 */  lw    $s0, 0x18($sp)
/* 05D110 7F0285E0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 05D114 7F0285E4 8FB20020 */  lw    $s2, 0x20($sp)
/* 05D118 7F0285E8 8FB30024 */  lw    $s3, 0x24($sp)
/* 05D11C 7F0285EC 8FB40028 */  lw    $s4, 0x28($sp)
/* 05D120 7F0285F0 8FB5002C */  lw    $s5, 0x2c($sp)
/* 05D124 7F0285F4 8FB60030 */  lw    $s6, 0x30($sp)
/* 05D128 7F0285F8 03E00008 */  jr    $ra
/* 05D12C 7F0285FC 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F028600(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F028600
/* 05D130 7F028600 27BDFF98 */  addiu $sp, $sp, -0x68
/* 05D134 7F028604 AFBF002C */  sw    $ra, 0x2c($sp)
/* 05D138 7F028608 AFB00028 */  sw    $s0, 0x28($sp)
/* 05D13C 7F02860C AFA5006C */  sw    $a1, 0x6c($sp)
/* 05D140 7F028610 AFA60070 */  sw    $a2, 0x70($sp)
/* 05D144 7F028614 AFA70074 */  sw    $a3, 0x74($sp)
/* 05D148 7F028618 A0800009 */  sb    $zero, 9($a0)
/* 05D14C 7F02861C 3C0E8005 */  lui   $t6, %hi(g_GlobalTimer) 
/* 05D150 7F028620 8DCE837C */  lw    $t6, %lo(g_GlobalTimer)($t6)
/* 05D154 7F028624 00808025 */  move  $s0, $a0
/* 05D158 7F028628 AC8E00CC */  sw    $t6, 0xcc($a0)
/* 05D15C 7F02862C 0FC1BD86 */  jal   sub_GAME_7F06F618
/* 05D160 7F028630 8C84001C */   lw    $a0, 0x1c($a0)
/* 05D164 7F028634 C7A40070 */  lwc1  $f4, 0x70($sp)
/* 05D168 7F028638 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 05D16C 7F02863C C4288378 */  lwc1  $f8, %lo(g_GlobalTimerDelta)($at)
/* 05D170 7F028640 46002182 */  mul.s $f6, $f4, $f0
/* 05D174 7F028644 8FA2006C */  lw    $v0, 0x6c($sp)
/* 05D178 7F028648 02002025 */  move  $a0, $s0
/* 05D17C 7F02864C C4500038 */  lwc1  $f16, 0x38($v0)
/* 05D180 7F028650 46083282 */  mul.s $f10, $f6, $f8
/* 05D184 7F028654 C446003C */  lwc1  $f6, 0x3c($v0)
/* 05D188 7F028658 460A8480 */  add.s $f18, $f16, $f10
/* 05D18C 7F02865C E4520038 */  swc1  $f18, 0x38($v0)
/* 05D190 7F028660 C4440038 */  lwc1  $f4, 0x38($v0)
/* 05D194 7F028664 4604303E */  c.le.s $f6, $f4
/* 05D198 7F028668 00000000 */  nop   
/* 05D19C 7F02866C 45020085 */  bc1fl .L7F028884
/* 05D1A0 7F028670 8FBF002C */   lw    $ra, 0x2c($sp)
/* 05D1A4 7F028674 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 05D1A8 7F028678 00002825 */   move  $a1, $zero
/* 05D1AC 7F02867C 8FA20074 */  lw    $v0, 0x74($sp)
/* 05D1B0 7F028680 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 05D1B4 7F028684 44818000 */  mtc1  $at, $f16
/* 05D1B8 7F028688 44804000 */  mtc1  $zero, $f8
/* 05D1BC 7F02868C 8E070024 */  lw    $a3, 0x24($s0)
/* 05D1C0 7F028690 8C450000 */  lw    $a1, ($v0)
/* 05D1C4 7F028694 8C460008 */  lw    $a2, 8($v0)
/* 05D1C8 7F028698 240F001F */  li    $t7, 31
/* 05D1CC 7F02869C AFAF0010 */  sw    $t7, 0x10($sp)
/* 05D1D0 7F0286A0 27A40078 */  addiu $a0, $sp, 0x78
/* 05D1D4 7F0286A4 E7B00018 */  swc1  $f16, 0x18($sp)
/* 05D1D8 7F0286A8 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 05D1DC 7F0286AC E7A80014 */   swc1  $f8, 0x14($sp)
/* 05D1E0 7F0286B0 0441005D */  bgez  $v0, .L7F028828
/* 05D1E4 7F0286B4 8FA60074 */   lw    $a2, 0x74($sp)
/* 05D1E8 7F0286B8 00C02025 */  move  $a0, $a2
/* 05D1EC 7F0286BC 0FC0A144 */  jal   sub_GAME_7F028510
/* 05D1F0 7F0286C0 8FA50078 */   lw    $a1, 0x78($sp)
/* 05D1F4 7F0286C4 10400058 */  beqz  $v0, .L7F028828
/* 05D1F8 7F0286C8 8FA60074 */   lw    $a2, 0x74($sp)
/* 05D1FC 7F0286CC 8E030018 */  lw    $v1, 0x18($s0)
/* 05D200 7F0286D0 8FB80078 */  lw    $t8, 0x78($sp)
/* 05D204 7F0286D4 00C02825 */  move  $a1, $a2
/* 05D208 7F0286D8 AC780014 */  sw    $t8, 0x14($v1)
/* 05D20C 7F0286DC C4CA0000 */  lwc1  $f10, ($a2)
/* 05D210 7F0286E0 E46A0008 */  swc1  $f10, 8($v1)
/* 05D214 7F0286E4 C4D20004 */  lwc1  $f18, 4($a2)
/* 05D218 7F0286E8 E472000C */  swc1  $f18, 0xc($v1)
/* 05D21C 7F0286EC C4C40008 */  lwc1  $f4, 8($a2)
/* 05D220 7F0286F0 E4640010 */  swc1  $f4, 0x10($v1)
/* 05D224 7F0286F4 8E190014 */  lw    $t9, 0x14($s0)
/* 05D228 7F0286F8 8E04001C */  lw    $a0, 0x1c($s0)
/* 05D22C 7F0286FC 37280001 */  ori   $t0, $t9, 1
/* 05D230 7F028700 AE080014 */  sw    $t0, 0x14($s0)
/* 05D234 7F028704 0FC1B303 */  jal   setsuboffset
/* 05D238 7F028708 AFA30064 */   sw    $v1, 0x64($sp)
/* 05D23C 7F02870C 8FA30064 */  lw    $v1, 0x64($sp)
/* 05D240 7F028710 8E04001C */  lw    $a0, 0x1c($s0)
/* 05D244 7F028714 260700AC */  addiu $a3, $s0, 0xac
/* 05D248 7F028718 24650008 */  addiu $a1, $v1, 8
/* 05D24C 7F02871C 0FC07F04 */  jal   sub_GAME_7F01FC10
/* 05D250 7F028720 00A03025 */   move  $a2, $a1
/* 05D254 7F028724 0FC08365 */  jal   chrPositionRelated7F020D94
/* 05D258 7F028728 02002025 */   move  $a0, $s0
/* 05D25C 7F02872C 82020007 */  lb    $v0, 7($s0)
/* 05D260 7F028730 2401000E */  li    $at, 14
/* 05D264 7F028734 8FA30064 */  lw    $v1, 0x64($sp)
/* 05D268 7F028738 5441000C */  bnel  $v0, $at, .L7F02876C
/* 05D26C 7F02873C 2401000F */   li    $at, 15
/* 05D270 7F028740 0FC0A137 */  jal   sub_GAME_7F0284DC
/* 05D274 7F028744 02002025 */   move  $a0, $s0
/* 05D278 7F028748 0FC0A11D */  jal   sub_GAME_7F028474
/* 05D27C 7F02874C 02002025 */   move  $a0, $s0
/* 05D280 7F028750 02002025 */  move  $a0, $s0
/* 05D284 7F028754 8FA5006C */  lw    $a1, 0x6c($sp)
/* 05D288 7F028758 0FC09FA4 */  jal   chrlvSetGoposSegDistTotal
/* 05D28C 7F02875C 00403025 */   move  $a2, $v0
/* 05D290 7F028760 10000045 */  b     .L7F028878
/* 05D294 7F028764 02002025 */   move  $a0, $s0
/* 05D298 7F028768 2401000F */  li    $at, 15
.L7F02876C:
/* 05D29C 7F02876C 54410042 */  bnel  $v0, $at, .L7F028878
/* 05D2A0 7F028770 02002025 */   move  $a0, $s0
/* 05D2A4 7F028774 92020058 */  lbu   $v0, 0x58($s0)
/* 05D2A8 7F028778 00024880 */  sll   $t1, $v0, 2
/* 05D2AC 7F02877C 02095021 */  addu  $t2, $s0, $t1
/* 05D2B0 7F028780 8D4B0040 */  lw    $t3, 0x40($t2)
/* 05D2B4 7F028784 1560001C */  bnez  $t3, .L7F0287F8
/* 05D2B8 7F028788 00000000 */   nop   
/* 05D2BC 7F02878C 18400016 */  blez  $v0, .L7F0287E8
/* 05D2C0 7F028790 00026080 */   sll   $t4, $v0, 2
/* 05D2C4 7F028794 020C6821 */  addu  $t5, $s0, $t4
/* 05D2C8 7F028798 8DA4003C */  lw    $a0, 0x3c($t5)
/* 05D2CC 7F02879C 3C188007 */  lui   $t8, %hi(ptr_0xxxpresets) 
/* 05D2D0 7F0287A0 8F185D18 */  lw    $t8, %lo(ptr_0xxxpresets)($t8)
/* 05D2D4 7F0287A4 8C8E0000 */  lw    $t6, ($a0)
/* 05D2D8 7F0287A8 C4660008 */  lwc1  $f6, 8($v1)
/* 05D2DC 7F0287AC C4700010 */  lwc1  $f16, 0x10($v1)
/* 05D2E0 7F0287B0 000E7880 */  sll   $t7, $t6, 2
/* 05D2E4 7F0287B4 01EE7823 */  subu  $t7, $t7, $t6
/* 05D2E8 7F0287B8 000F7880 */  sll   $t7, $t7, 2
/* 05D2EC 7F0287BC 01EE7823 */  subu  $t7, $t7, $t6
/* 05D2F0 7F0287C0 000F7880 */  sll   $t7, $t7, 2
/* 05D2F4 7F0287C4 01F81021 */  addu  $v0, $t7, $t8
/* 05D2F8 7F0287C8 C4480000 */  lwc1  $f8, ($v0)
/* 05D2FC 7F0287CC C44A0008 */  lwc1  $f10, 8($v0)
/* 05D300 7F0287D0 46083301 */  sub.s $f12, $f6, $f8
/* 05D304 7F0287D4 0FC16A8C */  jal   atan2f
/* 05D308 7F0287D8 460A8381 */   sub.s $f14, $f16, $f10
/* 05D30C 7F0287DC 44050000 */  mfc1  $a1, $f0
/* 05D310 7F0287E0 0FC1B34F */  jal   setsubroty
/* 05D314 7F0287E4 8E04001C */   lw    $a0, 0x1c($s0)
.L7F0287E8:
/* 05D318 7F0287E8 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 05D31C 7F0287EC 02002025 */   move  $a0, $s0
/* 05D320 7F0287F0 10000021 */  b     .L7F028878
/* 05D324 7F0287F4 02002025 */   move  $a0, $s0
.L7F0287F8:
/* 05D328 7F0287F8 0FC0A0B8 */  jal   chrlvActGoposIncCurIndex
/* 05D32C 7F0287FC 02002025 */   move  $a0, $s0
/* 05D330 7F028800 02002025 */  move  $a0, $s0
/* 05D334 7F028804 27A50040 */  addiu $a1, $sp, 0x40
/* 05D338 7F028808 0FC09FC8 */  jal   chrlvActGoposRelated
/* 05D33C 7F02880C 27A6003C */   addiu $a2, $sp, 0x3c
/* 05D340 7F028810 02002025 */  move  $a0, $s0
/* 05D344 7F028814 8FA5006C */  lw    $a1, 0x6c($sp)
/* 05D348 7F028818 0FC09FA4 */  jal   chrlvSetGoposSegDistTotal
/* 05D34C 7F02881C 27A60040 */   addiu $a2, $sp, 0x40
/* 05D350 7F028820 10000015 */  b     .L7F028878
/* 05D354 7F028824 02002025 */   move  $a0, $s0
.L7F028828:
/* 05D358 7F028828 8FA2006C */  lw    $v0, 0x6c($sp)
/* 05D35C 7F02882C 2401000E */  li    $at, 14
/* 05D360 7F028830 3C088005 */  lui   $t0, %hi(g_GlobalTimer) 
/* 05D364 7F028834 C452003C */  lwc1  $f18, 0x3c($v0)
/* 05D368 7F028838 3C098005 */  lui   $t1, %hi(g_GlobalTimer) 
/* 05D36C 7F02883C E4520038 */  swc1  $f18, 0x38($v0)
/* 05D370 7F028840 82190007 */  lb    $t9, 7($s0)
/* 05D374 7F028844 17210007 */  bne   $t9, $at, .L7F028864
/* 05D378 7F028848 00000000 */   nop   
/* 05D37C 7F02884C 8D08837C */  lw    $t0, %lo(g_GlobalTimer)($t0)
/* 05D380 7F028850 02002025 */  move  $a0, $s0
/* 05D384 7F028854 0FC0A125 */  jal   sub_GAME_7F028494
/* 05D388 7F028858 AE080078 */   sw    $t0, 0x78($s0)
/* 05D38C 7F02885C 10000006 */  b     .L7F028878
/* 05D390 7F028860 02002025 */   move  $a0, $s0
.L7F028864:
/* 05D394 7F028864 8D29837C */  lw    $t1, %lo(g_GlobalTimer)($t1)
/* 05D398 7F028868 02002025 */  move  $a0, $s0
/* 05D39C 7F02886C 0FC0A0A3 */  jal   chrlvActGoposSetTargetPosRelated
/* 05D3A0 7F028870 AE09009C */   sw    $t1, 0x9c($s0)
/* 05D3A4 7F028874 02002025 */  move  $a0, $s0
.L7F028878:
/* 05D3A8 7F028878 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 05D3AC 7F02887C 24050001 */   li    $a1, 1
/* 05D3B0 7F028880 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F028884:
/* 05D3B4 7F028884 8FB00028 */  lw    $s0, 0x28($sp)
/* 05D3B8 7F028888 27BD0068 */  addiu $sp, $sp, 0x68
/* 05D3BC 7F02888C 03E00008 */  jr    $ra
/* 05D3C0 7F028890 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F028894(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F028894
/* 05D3C4 7F028894 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 05D3C8 7F028898 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05D3CC 7F02889C 80820007 */  lb    $v0, 7($a0)
/* 05D3D0 7F0288A0 2401000E */  li    $at, 14
/* 05D3D4 7F0288A4 00A03825 */  move  $a3, $a1
/* 05D3D8 7F0288A8 5441002F */  bnel  $v0, $at, .L7F028968
/* 05D3DC 7F0288AC 2401000F */   li    $at, 15
/* 05D3E0 7F0288B0 808E0038 */  lb    $t6, 0x38($a0)
/* 05D3E4 7F0288B4 24010006 */  li    $at, 6
/* 05D3E8 7F0288B8 55C1002B */  bnel  $t6, $at, .L7F028968
/* 05D3EC 7F0288BC 2401000F */   li    $at, 15
/* 05D3F0 7F0288C0 AFA40040 */  sw    $a0, 0x40($sp)
/* 05D3F4 7F0288C4 0FC0A11D */  jal   sub_GAME_7F028474
/* 05D3F8 7F0288C8 AFA50044 */   sw    $a1, 0x44($sp)
/* 05D3FC 7F0288CC 8FA40040 */  lw    $a0, 0x40($sp)
/* 05D400 7F0288D0 8FA70044 */  lw    $a3, 0x44($sp)
/* 05D404 7F0288D4 C4900070 */  lwc1  $f16, 0x70($a0)
/* 05D408 7F0288D8 C4920074 */  lwc1  $f18, 0x74($a0)
/* 05D40C 7F0288DC 4610903E */  c.le.s $f18, $f16
/* 05D410 7F0288E0 00000000 */  nop   
/* 05D414 7F0288E4 45020009 */  bc1fl .L7F02890C
/* 05D418 7F0288E8 46128003 */   div.s $f0, $f16, $f18
/* 05D41C 7F0288EC C4440000 */  lwc1  $f4, ($v0)
/* 05D420 7F0288F0 E4E40000 */  swc1  $f4, ($a3)
/* 05D424 7F0288F4 C4460004 */  lwc1  $f6, 4($v0)
/* 05D428 7F0288F8 E4E60004 */  swc1  $f6, 4($a3)
/* 05D42C 7F0288FC C4480008 */  lwc1  $f8, 8($v0)
/* 05D430 7F028900 10000052 */  b     .L7F028A4C
/* 05D434 7F028904 E4E80008 */   swc1  $f8, 8($a3)
/* 05D438 7F028908 46128003 */  div.s $f0, $f16, $f18
.L7F02890C:
/* 05D43C 7F02890C 8C8F0018 */  lw    $t7, 0x18($a0)
/* 05D440 7F028910 C44A0000 */  lwc1  $f10, ($v0)
/* 05D444 7F028914 C5E20008 */  lwc1  $f2, 8($t7)
/* 05D448 7F028918 46025101 */  sub.s $f4, $f10, $f2
/* 05D44C 7F02891C 46002182 */  mul.s $f6, $f4, $f0
/* 05D450 7F028920 46023200 */  add.s $f8, $f6, $f2
/* 05D454 7F028924 E4E80000 */  swc1  $f8, ($a3)
/* 05D458 7F028928 8C980018 */  lw    $t8, 0x18($a0)
/* 05D45C 7F02892C C44A0004 */  lwc1  $f10, 4($v0)
/* 05D460 7F028930 C70C000C */  lwc1  $f12, 0xc($t8)
/* 05D464 7F028934 460C5101 */  sub.s $f4, $f10, $f12
/* 05D468 7F028938 46002182 */  mul.s $f6, $f4, $f0
/* 05D46C 7F02893C 460C3200 */  add.s $f8, $f6, $f12
/* 05D470 7F028940 E4E80004 */  swc1  $f8, 4($a3)
/* 05D474 7F028944 8C990018 */  lw    $t9, 0x18($a0)
/* 05D478 7F028948 C44A0008 */  lwc1  $f10, 8($v0)
/* 05D47C 7F02894C C72E0010 */  lwc1  $f14, 0x10($t9)
/* 05D480 7F028950 460E5101 */  sub.s $f4, $f10, $f14
/* 05D484 7F028954 46002182 */  mul.s $f6, $f4, $f0
/* 05D488 7F028958 460E3200 */  add.s $f8, $f6, $f14
/* 05D48C 7F02895C 1000003B */  b     .L7F028A4C
/* 05D490 7F028960 E4E80008 */   swc1  $f8, 8($a3)
/* 05D494 7F028964 2401000F */  li    $at, 15
.L7F028968:
/* 05D498 7F028968 54410030 */  bnel  $v0, $at, .L7F028A2C
/* 05D49C 7F02896C 8C8C0018 */   lw    $t4, 0x18($a0)
/* 05D4A0 7F028970 8088005C */  lb    $t0, 0x5c($a0)
/* 05D4A4 7F028974 24010006 */  li    $at, 6
/* 05D4A8 7F028978 27A5002C */  addiu $a1, $sp, 0x2c
/* 05D4AC 7F02897C 1501002A */  bne   $t0, $at, .L7F028A28
/* 05D4B0 7F028980 27A60028 */   addiu $a2, $sp, 0x28
/* 05D4B4 7F028984 AFA40040 */  sw    $a0, 0x40($sp)
/* 05D4B8 7F028988 0FC09FC8 */  jal   chrlvActGoposRelated
/* 05D4BC 7F02898C AFA70044 */   sw    $a3, 0x44($sp)
/* 05D4C0 7F028990 8FA40040 */  lw    $a0, 0x40($sp)
/* 05D4C4 7F028994 8FA70044 */  lw    $a3, 0x44($sp)
/* 05D4C8 7F028998 C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 05D4CC 7F02899C C4900094 */  lwc1  $f16, 0x94($a0)
/* 05D4D0 7F0289A0 C4920098 */  lwc1  $f18, 0x98($a0)
/* 05D4D4 7F0289A4 4610903E */  c.le.s $f18, $f16
/* 05D4D8 7F0289A8 00000000 */  nop   
/* 05D4DC 7F0289AC 45020008 */  bc1fl .L7F0289D0
/* 05D4E0 7F0289B0 46128003 */   div.s $f0, $f16, $f18
/* 05D4E4 7F0289B4 E4EA0000 */  swc1  $f10, ($a3)
/* 05D4E8 7F0289B8 C7A40030 */  lwc1  $f4, 0x30($sp)
/* 05D4EC 7F0289BC E4E40004 */  swc1  $f4, 4($a3)
/* 05D4F0 7F0289C0 C7A60034 */  lwc1  $f6, 0x34($sp)
/* 05D4F4 7F0289C4 10000021 */  b     .L7F028A4C
/* 05D4F8 7F0289C8 E4E60008 */   swc1  $f6, 8($a3)
/* 05D4FC 7F0289CC 46128003 */  div.s $f0, $f16, $f18
.L7F0289D0:
/* 05D500 7F0289D0 8C890018 */  lw    $t1, 0x18($a0)
/* 05D504 7F0289D4 C7A8002C */  lwc1  $f8, 0x2c($sp)
/* 05D508 7F0289D8 C5220008 */  lwc1  $f2, 8($t1)
/* 05D50C 7F0289DC 46024281 */  sub.s $f10, $f8, $f2
/* 05D510 7F0289E0 46005102 */  mul.s $f4, $f10, $f0
/* 05D514 7F0289E4 46022180 */  add.s $f6, $f4, $f2
/* 05D518 7F0289E8 E4E60000 */  swc1  $f6, ($a3)
/* 05D51C 7F0289EC 8C8A0018 */  lw    $t2, 0x18($a0)
/* 05D520 7F0289F0 C7A80030 */  lwc1  $f8, 0x30($sp)
/* 05D524 7F0289F4 C54C000C */  lwc1  $f12, 0xc($t2)
/* 05D528 7F0289F8 460C4281 */  sub.s $f10, $f8, $f12
/* 05D52C 7F0289FC 46005102 */  mul.s $f4, $f10, $f0
/* 05D530 7F028A00 460C2180 */  add.s $f6, $f4, $f12
/* 05D534 7F028A04 E4E60004 */  swc1  $f6, 4($a3)
/* 05D538 7F028A08 8C8B0018 */  lw    $t3, 0x18($a0)
/* 05D53C 7F028A0C C7A80034 */  lwc1  $f8, 0x34($sp)
/* 05D540 7F028A10 C56E0010 */  lwc1  $f14, 0x10($t3)
/* 05D544 7F028A14 460E4281 */  sub.s $f10, $f8, $f14
/* 05D548 7F028A18 46005102 */  mul.s $f4, $f10, $f0
/* 05D54C 7F028A1C 460E2180 */  add.s $f6, $f4, $f14
/* 05D550 7F028A20 1000000A */  b     .L7F028A4C
/* 05D554 7F028A24 E4E60008 */   swc1  $f6, 8($a3)
.L7F028A28:
/* 05D558 7F028A28 8C8C0018 */  lw    $t4, 0x18($a0)
.L7F028A2C:
/* 05D55C 7F028A2C C5880008 */  lwc1  $f8, 8($t4)
/* 05D560 7F028A30 E4E80000 */  swc1  $f8, ($a3)
/* 05D564 7F028A34 8C8D0018 */  lw    $t5, 0x18($a0)
/* 05D568 7F028A38 C5AA000C */  lwc1  $f10, 0xc($t5)
/* 05D56C 7F028A3C E4EA0004 */  swc1  $f10, 4($a3)
/* 05D570 7F028A40 8C8E0018 */  lw    $t6, 0x18($a0)
/* 05D574 7F028A44 C5C40010 */  lwc1  $f4, 0x10($t6)
/* 05D578 7F028A48 E4E40008 */  swc1  $f4, 8($a3)
.L7F028A4C:
/* 05D57C 7F028A4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 05D580 7F028A50 27BD0040 */  addiu $sp, $sp, 0x40
/* 05D584 7F028A54 03E00008 */  jr    $ra
/* 05D588 7F028A58 00000000 */   nop   
)
#endif



/**
 * @param arg0:
 * @param arg1: sprinting animation when 2, running animation when 1, otherwise walking animation
 * @param arg2:
 * 
 * Address 0x7F028A5C.
*/
void get_sound_at_range(ChrRecord *arg0, s32 arg1, s32 arg2)
{
    struct PropRecord *left;
    struct PropRecord *right;
    s32 ani_arg;
    s32 flag;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    if (((left != NULL) && (right != NULL)) || ((left == NULL) && (right == NULL)))
    {
        flag = 0;
        ani_arg = randomGetNext() & 1;
    }
    else
    {
        s32 t;
        if (check_if_item_held_like_pistol(left) || check_if_item_held_like_pistol(right))
        {
            t = 0;
            flag = t;
            ani_arg = (s32)left != 0;
        }
        else
        {
            t = 1;
            flag = t;
            ani_arg = (s32)left != 0;
        }
    }

    if (flag != 0)
    {
        if (arg1 == 2)
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_sprinting], ani_arg, 0.0f, 0.5f, 16.0f);
        }
        else if (arg1 == 1)
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_running], ani_arg, 0.0f, 0.5f, 16.0f);
        }
        else
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_walking], ani_arg, 0.0f, 0.5f, 16.0f);
        }

        return;
    }

    if (arg2)
    {
        if (arg1 == 2)
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_sprinting_one_handed_weapon], ani_arg, 0.0f, 0.5f, 16.0f);
        }
        else if (arg1 == 1)
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon], ani_arg, 0.0f, 0.5f, 16.0f);
        }
        else
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_walking_unarmed], ani_arg, 0.0f, 0.5f, 16.0f);
        }

        return;
    }

    if (arg1 == 2)
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_sprinting_one_handed_weapon], ani_arg, 0.0f, 0.5f, 16.0f);
    }
    else if (arg1 == 1)
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_running_female], ani_arg, 0.0f, 0.5f, 16.0f);
    }
    else
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_walking_female], ani_arg, 0.0f, 0.5f, 16.0f);
    }

    return;
}



/**
 * Address 0x7F028DA0.
*/
void play_hit_soundeffect_and_proper_volume(struct ChrRecord *arg0)
{
    get_sound_at_range(arg0, arg0->act_ubytes.padding[45], c_item_entries[arg0->bodynum].isMale);
}




/**
 * Address 0x7F028DDC.
*/
s32 plot_course_for_actor(ChrRecord *arg0, struct act_gopos *arg1, struct StandTile *stan, s32 arg3)
{
    PropRecord *prop; //sp 100
    struct path_table_alt *prop_path; // sp96
    struct path_table_alt *target_path; // sp92
    struct path_table_alt *sp44[MAX_CHRWAYPOINTS];
    s32 i;
    struct coord3d sp34;
    struct StandTile *sp30;
    s32 phi_v0;

    prop = arg0->prop;

    phi_v0 = (arg0->actiontype == ACT_GOPOS) && (arg0->act_gopos.unk59 == (u8)arg3);

    prop_path = chrlvStanPathRelated(&prop->pos, prop->stan);
    target_path = chrlvStanPathRelated(&arg1->targetpos, stan);

    if ((prop_path != NULL) 
        && (target_path != NULL) 
        && !(sub_GAME_7F08F4F0(prop_path, target_path, &sp44, MAX_CHRWAYPOINTS) < 2)
    )
    {
        sub_GAME_7F02D184(arg0);

        arg0->actiontype = ACT_GOPOS;

        arg0->act_gopos.targetpos.f[0] = arg1->targetpos.x;
        arg0->act_gopos.targetpos.f[1] = arg1->targetpos.f[1];
        arg0->act_gopos.targetpos.f[2] = arg1->targetpos.f[2];
        arg0->act_gopos.target = stan;
        arg0->act_gopos.target_path = target_path;
        arg0->act_gopos.curindex = 0;
        arg0->act_gopos.unk59 = arg3;
        arg0->act_gopos.unka0 = 0.0f;
        arg0->act_gopos.waydata.age = (s32) (randomGetNext() % 100U);
        arg0->act_gopos.waydata.unk03 = 0;
        arg0->act_gopos.unk9c = -1;

        for (i=0; i<MAX_CHRWAYPOINTS; i++)
        {
            arg0->act_gopos.waypoints[i] = sp44[i];
        }

        chrlvActGoposSetTargetPosRelated(arg0);
        arg0->sleep = 0;

        if (phi_v0 == 0)
        {
            play_hit_soundeffect_and_proper_volume(arg0);
        }

        chrlvActGoposRelated(arg0, &sp34, &sp30);

        if (((prop->flags & 2) == 0) && (chrlvStanRoomRelated(arg0, &sp34, sp30) != 0))
        {
            chrlvSetGoposSegDistTotal(arg0, &arg0->act_gopos.waydata, &sp34);
        }

        return 1;
    }

    return 0;
}




/**
 * Address 0x7F028FAC.
*/
void chrlvWalkingAnimationRelated(ChrRecord *arg0)
{
    PropRecord *left;
    PropRecord *right;
    s32 ani_arg;
    s32 flag;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    if (((left != NULL) && (right != NULL)) || ((left == NULL)) && (right == NULL))
    {
        flag = 0;
        ani_arg = randomGetNext() & 1;
    }
    else
    {
        s32 t;
        if (check_if_item_held_like_pistol(left) || check_if_item_held_like_pistol(right))
        {
            t = 0;
            flag = t;
            ani_arg = (s32)left != 0;
        }
        else
        {
            t = 1;
            flag = t;
            ani_arg = (s32)left != 0;
        }
    }

    if (flag != 0)
    {
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_walking], ani_arg, 0.0f, 0.5f, 16.0f);
    }
    else
    {
        f32 tf = (0.5f * D_80030984) / D_80030990;
        objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_walking_unarmed], ani_arg, 0.0f, tf, 16.0f);
    }

    return;
}




#ifdef NONMATCHING

// arg1 is probably a struct
void set_actor_on_path(ChrRecord *self, s32 **pathid)
{
    struct pad * pad;
    s32 next_step = -1;
    struct PropRecord *prop = self->prop;
    s32 count = 0;
    s32 *arr = *pathid;

    // decomp problem area: can't seem to get arr[count] to dereference the correct number of times.
    for ( ; arr[count] >= 0; count++)
    {
        s32 aa;

        aa = ptr_setup_path_tbl[arr[count]].id;
        pad = &ptr_0xxxpresets[aa];

        if ((pad->stan != NULL) && (prop->stan == pad->stan))
        {
            f32 dx = pad->pos.f[0] - prop->pos.f[0];
            f32 dz = pad->pos.f[2] - prop->pos.f[2];

            if (((((dx * dx) + (dz * dz)) < 10000.0f)))
            {
                next_step = count;
                break;
            }
        }
    }
    // end problem area.

    if (next_step < 0)
    {
        next_step = 0;
    }

    sub_GAME_7F02D184(self);
    self->actiontype = ACT_PATROL;
    self->act_patrol.path = pathid;

    self->act_patrol.nextstep = next_step;
    self->act_patrol.forward = TRUE;

    self->act_patrol.waydata.age = randomGetNext() % 0x64U;
    self->act_patrol.waydata.unk03 = 0;
    self->act_init.padding[0x13] = -1;

    self->act_patrol.unk7c = 0.0f;
    sub_GAME_7F028494(self);
    self->sleep = 0;
    chrlvWalkingAnimationRelated(self);
    pad = sub_GAME_7F028474(self);

    if ((self->prop->flags & 2) == 0)
    {
        if (chrlvStanRoomRelatedPad(self, pad) != 0)
        {
            chrlvSetGoposSegDistTotal(self, &self->act_patrol.waydata, &pad->pos);
        }
    }
}

#else
GLOBAL_ASM(
.late_rodata
glabel D_80051DF8
.word 0x461c4000 /*10000.0*/
.text
glabel set_actor_on_path
/* 05DC28 7F0290F8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 05DC2C 7F0290FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 05DC30 7F029100 AFB00018 */  sw    $s0, 0x18($sp)
/* 05DC34 7F029104 AFA5002C */  sw    $a1, 0x2c($sp)
/* 05DC38 7F029108 8CA80000 */  lw    $t0, ($a1)
/* 05DC3C 7F02910C 00808025 */  move  $s0, $a0
/* 05DC40 7F029110 240CFFFF */  li    $t4, -1
/* 05DC44 7F029114 8D0F0000 */  lw    $t7, ($t0)
/* 05DC48 7F029118 8C870018 */  lw    $a3, 0x18($a0)
/* 05DC4C 7F02911C 00003025 */  move  $a2, $zero
/* 05DC50 7F029120 05E0002C */  bltz  $t7, .L7F0291D4
/* 05DC54 7F029124 3C098007 */   lui   $t1, %hi(ptr_setup_path_tbl) 
/* 05DC58 7F029128 3C0A8007 */  lui   $t2, %hi(ptr_0xxxpresets) 
/* 05DC5C 7F02912C 3C018005 */  lui   $at, %hi(D_80051DF8)
/* 05DC60 7F029130 C42C1DF8 */  lwc1  $f12, %lo(D_80051DF8)($at)
/* 05DC64 7F029134 8D4A5D18 */  lw    $t2, %lo(ptr_0xxxpresets)($t2)
/* 05DC68 7F029138 8D295D00 */  lw    $t1, %lo(ptr_setup_path_tbl)($t1)
/* 05DC6C 7F02913C 240B002C */  li    $t3, 44
/* 05DC70 7F029140 0006C080 */  sll   $t8, $a2, 2
.L7F029144:
/* 05DC74 7F029144 01181021 */  addu  $v0, $t0, $t8
/* 05DC78 7F029148 8C590000 */  lw    $t9, ($v0)
/* 05DC7C 7F02914C 00196900 */  sll   $t5, $t9, 4
/* 05DC80 7F029150 01A91821 */  addu  $v1, $t5, $t1
/* 05DC84 7F029154 8C6E0000 */  lw    $t6, ($v1)
/* 05DC88 7F029158 01CB0019 */  multu $t6, $t3
/* 05DC8C 7F02915C 00007812 */  mflo  $t7
/* 05DC90 7F029160 01EA2021 */  addu  $a0, $t7, $t2
/* 05DC94 7F029164 8C850028 */  lw    $a1, 0x28($a0)
/* 05DC98 7F029168 50A00015 */  beql  $a1, $zero, .L7F0291C0
/* 05DC9C 7F02916C 24C60001 */   addiu $a2, $a2, 1
/* 05DCA0 7F029170 8CF80014 */  lw    $t8, 0x14($a3)
/* 05DCA4 7F029174 57050012 */  bnel  $t8, $a1, .L7F0291C0
/* 05DCA8 7F029178 24C60001 */   addiu $a2, $a2, 1
/* 05DCAC 7F02917C C4840000 */  lwc1  $f4, ($a0)
/* 05DCB0 7F029180 C4E60008 */  lwc1  $f6, 8($a3)
/* 05DCB4 7F029184 C4880008 */  lwc1  $f8, 8($a0)
/* 05DCB8 7F029188 C4EA0010 */  lwc1  $f10, 0x10($a3)
/* 05DCBC 7F02918C 46062001 */  sub.s $f0, $f4, $f6
/* 05DCC0 7F029190 460A4081 */  sub.s $f2, $f8, $f10
/* 05DCC4 7F029194 46000402 */  mul.s $f16, $f0, $f0
/* 05DCC8 7F029198 00000000 */  nop   
/* 05DCCC 7F02919C 46021482 */  mul.s $f18, $f2, $f2
/* 05DCD0 7F0291A0 46128100 */  add.s $f4, $f16, $f18
/* 05DCD4 7F0291A4 460C203C */  c.lt.s $f4, $f12
/* 05DCD8 7F0291A8 00000000 */  nop   
/* 05DCDC 7F0291AC 45000003 */  bc1f  .L7F0291BC
/* 05DCE0 7F0291B0 00000000 */   nop   
/* 05DCE4 7F0291B4 10000007 */  b     .L7F0291D4
/* 05DCE8 7F0291B8 00C06025 */   move  $t4, $a2
.L7F0291BC:
/* 05DCEC 7F0291BC 24C60001 */  addiu $a2, $a2, 1
.L7F0291C0:
/* 05DCF0 7F0291C0 0006C880 */  sll   $t9, $a2, 2
/* 05DCF4 7F0291C4 01196821 */  addu  $t5, $t0, $t9
/* 05DCF8 7F0291C8 8DAE0000 */  lw    $t6, ($t5)
/* 05DCFC 7F0291CC 05C3FFDD */  bgezl $t6, .L7F029144
/* 05DD00 7F0291D0 0006C080 */   sll   $t8, $a2, 2
.L7F0291D4:
/* 05DD04 7F0291D4 05810002 */  bgez  $t4, .L7F0291E0
/* 05DD08 7F0291D8 02002025 */   move  $a0, $s0
/* 05DD0C 7F0291DC 00006025 */  move  $t4, $zero
.L7F0291E0:
/* 05DD10 7F0291E0 0FC0B461 */  jal   sub_GAME_7F02D184
/* 05DD14 7F0291E4 AFAC0020 */   sw    $t4, 0x20($sp)
/* 05DD18 7F0291E8 8FAC0020 */  lw    $t4, 0x20($sp)
/* 05DD1C 7F0291EC 240F000E */  li    $t7, 14
/* 05DD20 7F0291F0 A20F0007 */  sb    $t7, 7($s0)
/* 05DD24 7F0291F4 8FB8002C */  lw    $t8, 0x2c($sp)
/* 05DD28 7F0291F8 24190001 */  li    $t9, 1
/* 05DD2C 7F0291FC AE190034 */  sw    $t9, 0x34($s0)
/* 05DD30 7F029200 AE0C0030 */  sw    $t4, 0x30($s0)
/* 05DD34 7F029204 0C002914 */  jal   randomGetNext
/* 05DD38 7F029208 AE18002C */   sw    $t8, 0x2c($s0)
/* 05DD3C 7F02920C 24010064 */  li    $at, 100
/* 05DD40 7F029210 0041001B */  divu  $zero, $v0, $at
/* 05DD44 7F029214 44803000 */  mtc1  $zero, $f6
/* 05DD48 7F029218 00006810 */  mfhi  $t5
/* 05DD4C 7F02921C 240EFFFF */  li    $t6, -1
/* 05DD50 7F029220 AE0D0060 */  sw    $t5, 0x60($s0)
/* 05DD54 7F029224 A200003B */  sb    $zero, 0x3b($s0)
/* 05DD58 7F029228 AE0E0078 */  sw    $t6, 0x78($s0)
/* 05DD5C 7F02922C 02002025 */  move  $a0, $s0
/* 05DD60 7F029230 0FC0A125 */  jal   sub_GAME_7F028494
/* 05DD64 7F029234 E606007C */   swc1  $f6, 0x7c($s0)
/* 05DD68 7F029238 A2000008 */  sb    $zero, 8($s0)
/* 05DD6C 7F02923C 0FC0A3EB */  jal   chrlvWalkingAnimationRelated
/* 05DD70 7F029240 02002025 */   move  $a0, $s0
/* 05DD74 7F029244 0FC0A11D */  jal   sub_GAME_7F028474
/* 05DD78 7F029248 02002025 */   move  $a0, $s0
/* 05DD7C 7F02924C 8E0F0018 */  lw    $t7, 0x18($s0)
/* 05DD80 7F029250 02002025 */  move  $a0, $s0
/* 05DD84 7F029254 00402825 */  move  $a1, $v0
/* 05DD88 7F029258 91F80001 */  lbu   $t8, 1($t7)
/* 05DD8C 7F02925C 33190002 */  andi  $t9, $t8, 2
/* 05DD90 7F029260 57200009 */  bnezl $t9, .L7F029288
/* 05DD94 7F029264 8FBF001C */   lw    $ra, 0x1c($sp)
/* 05DD98 7F029268 0FC09F9C */  jal   chrlvStanRoomRelatedPad
/* 05DD9C 7F02926C AFA20024 */   sw    $v0, 0x24($sp)
/* 05DDA0 7F029270 10400004 */  beqz  $v0, .L7F029284
/* 05DDA4 7F029274 8FA60024 */   lw    $a2, 0x24($sp)
/* 05DDA8 7F029278 02002025 */  move  $a0, $s0
/* 05DDAC 7F02927C 0FC09FA4 */  jal   chrlvSetGoposSegDistTotal
/* 05DDB0 7F029280 26050038 */   addiu $a1, $s0, 0x38
.L7F029284:
/* 05DDB4 7F029284 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F029288:
/* 05DDB8 7F029288 8FB00018 */  lw    $s0, 0x18($sp)
/* 05DDBC 7F02928C 27BD0028 */  addiu $sp, $sp, 0x28
/* 05DDC0 7F029290 03E00008 */  jr    $ra
/* 05DDC4 7F029294 00000000 */   nop   
)
#endif



void setSeenBondTimeToNow(struct ChrRecord *guardData)
{
  guardData->seen_bond_time = g_GlobalTimer;
  return;
}



/**
 * Address 0x7F0292A8.
*/
s32 chrlvAttackRelated7F0292A8(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2)
{
    s32 ret;
    s32 flags;
    StandTile *stan;
    StandTile *sp40;
    struct coord3d *sp3C;

    ret = 0;
    flags = 1;

    if (arg0->actiontype == ACT_ATTACK)
    {
        flags = arg0->act_attack.attacktype;
    }

    if ((flags & 2) != 0)
    {
        ret = 1;
    }
    else
    {
        stan = arg2;
        sp3C = sub_GAME_7F032C78(arg0, flags, arg0->act_attack.entityid, &sp40);
        set_or_unset_GUARDdata_flag(arg0, 0);

        if ((flags & 1) != 0)
        {
            bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 0);
            
            if (bondviewGetVisibleToGuardsFlag() != 0)
            {
                if ((sub_GAME_7F0B0E24(&stan, arg1->x, arg1->f[2], sp3C->x, sp3C->f[2], 0x11B, arg1->f[1], arg1->f[1], sp3C->f[1], sp3C->f[1]) != 0) && (stan == sp40))
                {
                    setSeenBondTimeToNow(arg0);
                    ret = 1;
                }
            }

            bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 1);
        }
        else if ((flags & 4) != 0)
        {
            if ((sub_GAME_7F0B0E24(&stan, arg1->x, arg1->f[2], sp3C->x, sp3C->f[2], 0x117, arg1->f[1], arg1->f[1], sp3C->f[1], sp3C->f[1]) != 0) && (stan == sp40))
            {
                ret = 1;
            }
        }
        else if ((flags & 8) != 0)
        {
            if ((sub_GAME_7F0B0E24(&stan, arg1->x, arg1->f[2], sp3C->x, sp3C->f[2], 0x11F, arg1->f[1], arg1->f[1], sp3C->f[1], sp3C->f[1]) != 0) && (stan == sp40))
            {
                ret = 1;
            }
        }

        set_or_unset_GUARDdata_flag(arg0, 1);
    }

    return ret;
}




/**
 * Address 0x7F0294BC.
*/
bool sub_GAME_7F0294BC(ChrRecord *self)
{
    bool pass = FALSE;
    PropRecord *myprop;
    PropRecord *bondprop;
    StandTile *mystan;
    f32 myheight;

    if (bondviewGetVisibleToGuardsFlag())
    {
        myprop   = self->prop;
        bondprop = get_curplayer_positiondata();
        myheight = self->chrheight - 20.0f;

        set_or_unset_GUARDdata_flag(self, FALSE);
        bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 0);

        mystan = myprop->stan;

        if (sub_GAME_7F0B0E24(&mystan, myprop->pos.x, myprop->pos.z, bondprop->pos.x, bondprop->pos.z, 0x11B, myheight, myheight, 0.0f, 1.0f) && (mystan == bondprop->stan))
        {
            setSeenBondTimeToNow(self);
            pass = TRUE;
        }

        set_or_unset_GUARDdata_flag(self, TRUE);
        bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 1);
    }

    return pass;
}




/**
 * Address 0x7F0295D0.
*/
bool check_if_position_in_same_room(struct ChrRecord *self, struct coord3d *pos, struct StandTile *stan)
{
    PropRecord *myprop = self->prop;
    StandTile *propstan;
    f32 myheight = self->chrheight - 20.0f;
    bool pass    = FALSE;

    set_or_unset_GUARDdata_flag(self, 0);

    propstan = myprop->stan;

    if (sub_GAME_7F0B0E24(&propstan, myprop->pos.x, myprop->pos.z, pos->x, pos->z, 0x113, myheight, myheight, 0.0f, 1.0f) && (propstan == stan))
    {
        pass = TRUE;
    }

    set_or_unset_GUARDdata_flag(self, 1);

    return pass;
}



/**
 * Address 0x7F02969C.
*/
s32 chrlvMaybeSameRoom(struct ChrRecord *arg0, struct coord3d *arg1, struct StandTile *arg2)
{
    f32 atan;
    f32 roty;
    f32 df;

    roty = getsubroty(arg0->model);
    atan = atan2f(arg1->f[0] - arg0->prop->pos.f[0], arg1->f[2] - arg0->prop->pos.f[2]);
    df = atan - roty;

    if (atan < roty)
    {
        df += M_2PI_F;
    }

    if ((df < M_100_DEG_IN_RAD) || (df > M_260_DEG_IN_RAD))
    {
        return check_if_position_in_same_room(arg0, arg1, arg2);
    }

    return 0;
}




/**
 * Address 0x7F029760.
*/
s32 chrlvCurrentPlayerCall7F0B0E24(ChrRecord *arg0)
{
    PropRecord *sp3C;
    PropRecord *bond_prop;
    StandTile *bond_stan;
    s32 ret;

    sp3C = arg0->prop;
    bond_prop = get_curplayer_positiondata();
    ret = 0;

    bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 0);

    bond_stan = bond_prop->stan;
    
    if ((sub_GAME_7F0B0E24(
            &bond_stan,
            bond_prop->pos.f[0],
            bond_prop->pos.f[2],
            sp3C->pos.f[0],
            sp3C->pos.f[2],
            0x13,
            bond_prop->pos.f[1],
            bond_prop->pos.f[1],
            0.0f,
            1.0f) != 0)
        && (bond_stan == sp3C->stan))
    {
        ret = 1;
    }

    bondviewUpdateGuardTankFlagsRelated(g_CurrentPlayer->prop, 1);

    return ret;
}




/**
 * Address 0x7F02982C.
*/
s32 chrlvCall7F0B0E24WithChrWidthHeight(PropRecord *arg0, struct coord3d *arg1, struct coord3d *arg2)
{
    ChrRecord *sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    StandTile *stan;
    f32 chrx;
    f32 chrz;
    s32 ret; // sp92
    f32 sp58; // sp88
    f32 sp54; // sp84
    f32 sp50; // sp80

    sp7C = arg0->chr;
    chrx = arg2->f[0] * sp7C->chrwidth * 1.2f;
    chrz = arg2->f[2] * sp7C->chrwidth * 1.2f;
    ret = 0;

    chrGetChrWidthHeight(arg0, &sp50, &sp58, &sp54);
    set_or_unset_GUARDdata_flag(sp7C, 0);

    sp78 = arg0->pos.f[0] + chrz;
    sp74 = arg0->pos.f[2] - chrx;
    sp70 = arg1->f[0] + chrz + chrx;
    sp6C = (arg1->f[2] - chrx) + chrz;

    stan = arg0->stan;

    if (
        (sub_GAME_7F0B0E24(&stan, arg0->pos.f[0], arg0->pos.f[2], sp78, sp74, 0x1F, sp58, sp54, 0.0f, 1.0f) != 0)
        && (sub_GAME_7F0B0E24(&stan, sp78, sp74, sp70, sp6C, 0x1F, sp58, sp54, 0.0f, 1.0f) != 0)
        )
    {
        sp78 = arg0->pos.f[0] - chrz;
        sp74 = arg0->pos.f[2] + chrx;
        sp70 = (arg1->f[0] - chrz) + chrx;
        sp6C = arg1->f[2] + chrx + chrz;

        // why is this getting set again?
        stan = arg0->stan;

        if (
            (sub_GAME_7F0B0E24(&stan, arg0->pos.f[0], arg0->pos.f[2], sp78, sp74, 0x1F, sp58, sp54, 0.0f, 1.0f) != 0)
            && (sub_GAME_7F0B0E24(&stan, sp78, sp74, sp70, sp6C, 0x1F, sp58, sp54, 0.0f, 1.0f) != 0)
            )
        {
            ret = 1;
        }
    }

    set_or_unset_GUARDdata_flag(sp7C, 1);

    return ret;
}




/**
 * Addres 0x7F029A94.
*/
s32 chrlvCall7F02982C(PropRecord *arg0, struct coord3d *arg1, f32 arg2)
{
    struct coord3d sp1C;

    sp1C.f[0] = arg0->pos.f[0] + (arg1->f[0] * arg2);
    sp1C.f[1] = arg0->pos.f[1];
    sp1C.f[2] = arg0->pos.f[2] + (arg1->f[2] * arg2);

    return chrlvCall7F0B0E24WithChrWidthHeight(arg0, &sp1C, arg1);
}



/**
 * Unreferenced.
 * 
 * Address 0x7F029AF0.
*/
s32 chrlvCall7F0B0E24Normalized(PropRecord *arg0, struct coord3d *arg1)
{
    struct coord3d sp24;
    f32 temp_f2;

    sp24.f[0] = arg1->f[0] - arg0->pos.f[0];
    sp24.f[1] = 0.0f;
    sp24.f[2] = arg1->f[2] - arg0->pos.f[2];

    if ((sp24.f[0] == 0.0f) && (sp24.f[2] == 0.0f))
    {
        return 1;
    }

    temp_f2 = 1.0f / sqrtf((sp24.f[0] * sp24.f[0]) + (sp24.f[2] * sp24.f[2]));

    sp24.f[0] *= temp_f2;
    sp24.f[2] *= temp_f2;

    return chrlvCall7F0B0E24WithChrWidthHeight(arg0, arg1, &sp24);
}




/**
 * Same as chrlvAlertGuardToPlayerPosition, except without setting `hidden` flag 0x2.
 * 
 * Address 0x7F029BB0.
*/
void chrlvSetTargetToPlayer(ChrRecord *arg0)
{
    PropRecord *temp_v0;

    temp_v0 = get_curplayer_positiondata();
    arg0->lastseetarget60 = g_GlobalTimer;
    arg0->lastknowntargetpos.f[0] = temp_v0->pos.f[0];
    arg0->lastknowntargetpos.f[1] = temp_v0->pos.f[1];
    arg0->lastknowntargetpos.f[2] = temp_v0->pos.f[2];
    arg0->targetTile = temp_v0->stan;
}




/**
 * See also chrlvSetTargetToPlayer.
 * 
 * Address 0x7F029C00.
 */
void chrlvAlertGuardToPlayerPosition(struct ChrRecord *arg0)
{
    struct PropRecord *temp_v0;

    temp_v0 = get_curplayer_positiondata();
    arg0->hidden |= 2;
    arg0->lastheartarget60 = g_GlobalTimer;
    arg0->lastknowntargetpos.f[0] = temp_v0->pos.x;
    arg0->lastknowntargetpos.f[1] = temp_v0->pos.y;
    arg0->lastknowntargetpos.f[2] = temp_v0->pos.z;
    arg0->targetTile = temp_v0->stan;
}


/**
 * Address 0x7F029C5C.
*/
bool check_if_actor_stationary(ChrRecord *self)
{
    if ((self->actiontype == ACT_STAND) && !self->act_stand.unk02c && !self->act_stand.unk038)
    {
        return TRUE;
    }
    else if (self->actiontype == ACT_ANIM)
    {
        if (self->act_anim.unk034 ||
            ((sub_GAME_7F06F610(self->model) >= 0.0f) && objecthandlerGetModelField28(self->model) >= (sub_GAME_7F06F5C4(self->model))) ||
            ((sub_GAME_7F06F610(self->model) < 0.0f) && (objecthandlerGetModelField28(self->model) <= 0.0f)))
        {
            return TRUE;
        }
    }
    else if (self->actiontype == ACT_PATROL)
    {
        return TRUE;
    }

    return FALSE;
}




/**
 * Address 0x7F029D70.
*/
s32 sub_GAME_7F029D70(ChrRecord *self)
{
    PropRecord *myprop; // sp84
    PropRecord *bondprop; // sp80
    f32 rrr;
    f32 vec2rd;
    f32 myRadDirection; // sp68
    struct coord3d vec; // sp64 = x, sp60 = y, sp56 = z
    f32 atn;
    f32 radChangeToFaceBond; // sp48?
    s32 pass; // sp44
    u32 rt;
    s32 distance;

    myprop               = self->prop;
    bondprop             = get_curplayer_positiondata();
    myRadDirection       = getsubroty(self->model);
    // note: x and z get swapped
    vec.z                = bondprop->pos.x - myprop->pos.x;
    vec.y                = bondprop->pos.y - myprop->pos.y;
    vec.x                = bondprop->pos.z - myprop->pos.z;

    atn = atan2f(vec.z, vec.x);

    pass = 0;
    rrr = atn - myRadDirection;
    radChangeToFaceBond = rrr;
    if (atn < myRadDirection)
    {
        radChangeToFaceBond = rrr + M_TAU;
    }

    if (sub_GAME_7F032B68(self))
    {
        pass = 1;
    }
    else
    {
        vec2rd = (vec.z * vec.z) + (vec.y * vec.y) + (vec.x * vec.x);

        if (
            /*within 220 degrees of forward and within range*/
            (
                (vec2rd < (self->visionrange * self->visionrange * 100.0f * 100.0f))
                && ((radChangeToFaceBond < M_110_DEG_IN_RAD) || (radChangeToFaceBond > M_250_DEG_IN_RAD))
            )
            ||
            /*or within clamped minimum of 200*/
            (
                (vec2rd < (200 * 200))
                && ((radChangeToFaceBond < M_110_DEG_IN_RAD) || (radChangeToFaceBond > M_250_DEG_IN_RAD))
            )
        )
        {
            if (vec2rd < square_near_fog_value())
            {
                distance = (s32)((sqrtf(vec2rd) * 30.0f) / 16000.0f);

                //Not facing bond
                if ((radChangeToFaceBond > M_45_DEG_IN_RAD) && (radChangeToFaceBond < M_315_DEG_IN_RAD))
                {
                    f32 f0 = radChangeToFaceBond;
                    if (radChangeToFaceBond > M_PI_F)
                    {
                        //confine/wrap to half
                        f0 = M_TAU - radChangeToFaceBond;
                    }

                    f0 -= M_45_DEG_IN_RAD;

                    distance *= (s32)((f0 * 24.0f) / M_TAU) + 1;
                }

                distance = chrlvGetGuard007SpeedRatingInt(self, distance) + 1;
                pass = ((u32)randomGetNext() % (u32)distance) == 0;
            }
        }
    }

    if (pass)
    {
        pass = sub_GAME_7F0294BC(self);
    }

    if (pass)
    {
        chrlvSetTargetToPlayer(self);
    }

    return pass;
}



/**
 * @param arg0:
 * @param arg1: flag. If set result is (dz, -dx), otherwise (-dz, dx).
 * @param arg2: Out parameter. Contains result coordinat.
 * 
 * Address 0x7F02A044.
*/
void chrlvNormDistanceToPlayer(ChrRecord *arg0, s32 arg1, struct coord3d *arg2)
{
    PropRecord *prop;
    f32 norm;
    f32 dx;
    f32 dz;
    PropRecord *player_prop;

    prop = arg0->prop;
    player_prop = get_curplayer_positiondata();
    dx = player_prop->pos.f[0] - prop->pos.f[0];
    dz = player_prop->pos.f[2] - prop->pos.f[2];

    norm = sqrtf((dx * dx) + (dz * dz));

    dx = dx / norm;
    dz = dz / norm;

    if (arg1 != 0)
    {
        arg2->f[1] = 0;
        arg2->f[0] = dz;
        arg2->f[2] = -(dx);
    }
    else
    {
        arg2->f[2] = dx;
        arg2->f[0] = -(dz);
        arg2->f[1] = 0;
    }
}




/**
 * @see sub_GAME_7F02A1E8
 * Address 0x7F02A0EC.
*/
s32 sub_GAME_7F02A0EC(ChrRecord *arg0, s32 arg1, f32 arg2)
{
    PropRecord *prop;
    struct coord3d sp28;
    struct coord3d sp1C;

    prop = arg0->prop;
    chrlvNormDistanceToPlayer(arg0, arg1, &sp28);

    sp1C.f[0] = prop->pos.f[0] + (sp28.f[0] * arg2);
    sp1C.f[1] = prop->pos.f[1];
    sp1C.f[2] = prop->pos.f[2] + (sp28.f[2] * arg2);

    return chrlvCall7F0B0E24WithChrWidthHeight(prop, &sp1C, &sp28);
}




/**
 * @param arg0:
 * @param arg1: flag. If set result is (cos, -sin), otherwise (-cos, sin).
 * @param arg2: out parameter, contains coordinate result.
 * 
 * Address 0x7F02A15C.
*/
void chrlvModelRotyRelated(ChrRecord *arg0, s32 arg1, struct coord3d *arg2)
{
    f32 temp_f12;

    temp_f12 = getsubroty(arg0->model);

    if (arg1 != 0)
    {
        arg2->f[0] = cosf(temp_f12);
        arg2->f[1] = 0.0f;
        arg2->f[2] = -sinf(temp_f12);
    }
    else
    {
        arg2->f[0] = -cosf(temp_f12);
        arg2->f[1] = 0.0f;
        arg2->f[2] = sinf(temp_f12);
    }
}




/**
 * @see sub_GAME_7F02A0EC
 * 
 * Address 0x7F02A1E8.
*/
s32 sub_GAME_7F02A1E8(ChrRecord *arg0, s32 arg1, f32 arg2)
{
    PropRecord *prop;
    struct coord3d sp28;
    struct coord3d sp1C;

    prop = arg0->prop;
    chrlvModelRotyRelated(arg0, arg1, &sp28);

    sp1C.f[0] = prop->pos.f[0] + (sp28.f[0] * arg2);
    sp1C.f[1] = prop->pos.f[1];
    sp1C.f[2] = prop->pos.f[2] + (sp28.f[2] * arg2);

    return chrlvCall7F0B0E24WithChrWidthHeight(prop, &sp1C, &sp28);
}




s32 chrIsNotDeadOrShot(struct ChrRecord *chr)
{
    s8 currentaction = chr->actiontype;

    if ((currentaction == ACT_DIE) || (currentaction == ACT_DEAD) || (currentaction == ACT_PREARGH) 
        || (currentaction == ACT_ARGH) && !(chr->chrflags & CHRFLAG_00000200))
    {
        return 0;
    }

    return 1;
}



s32 chrIsDead(struct ChrRecord *chr)
{
    s8 currentaction = chr->actiontype;

    return ((currentaction == ACT_DIE) || (currentaction == ACT_DEAD));
}



/**
 * Address 0x7F02A2C8.
*/
bool actor_steps_sideways(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;
    int pad1; //needed for stack size - check debug rom
    f32 myRadDirection;
    int pad2; //needed for stack size
    f32 myRadDirectionToBond;
    f32 radChangeToFaceBond;
    bool HopOtherDirection; //needed for stack size
    bool HopDirection;
    f32 myNormalizedRadToBond;

    if (chrIsNotDeadOrShot(self))
    {
        myprop                = self->prop;
        bondprop              = get_curplayer_positiondata();
        myRadDirection        = getsubroty(self->model);
        myRadDirectionToBond  = atan2f(bondprop->pos.x - myprop->pos.x, bondprop->pos.z - myprop->pos.z);
        radChangeToFaceBond   = myRadDirectionToBond - myRadDirection;
        myNormalizedRadToBond = radChangeToFaceBond;

        if (myRadDirectionToBond < myRadDirection) //avoid negative radians
        {
            myNormalizedRadToBond = radChangeToFaceBond + M_TAU;
        }

        if ((myNormalizedRadToBond < M_45_DEG_IN_RAD)                                             /*0-45*/
            || (myNormalizedRadToBond > M_315_DEG_IN_RAD)                                          /*-45-0*/
            || ((myNormalizedRadToBond > M_135_DEG_IN_RAD) && (myNormalizedRadToBond < M_225_DEG_IN_RAD)) /*135-225*/
        )
        {
            HopDirection = (randomGetNext() & 1) == 0;         //Hop Left or Right
            if (sub_GAME_7F02A1E8(self, HopDirection, 100.0f)) //able to step dir?
            {
                chrlvSideStepAnimationRelated(self, HopDirection);
                return TRUE;
            }

            HopOtherDirection = HopDirection == 0;

            if (sub_GAME_7F02A1E8(self, HopOtherDirection, 100.0f)) //able to step other dir?
            {
                chrlvSideStepAnimationRelated(self, HopOtherDirection);
                return TRUE;
            }
        }
    }

    return FALSE; //unable to hop
}



#ifdef NONMATCHING
void actor_hops_sideways(void) {
// ai branch
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E4C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E50
.word 0x3f490fdb /*0.78539819*/
glabel D_80051E54
.word 0x40afede0 /*5.4977875*/
glabel D_80051E58
.word 0x4016cbe4 /*2.3561945*/
glabel D_80051E5C
.word 0x407b53d2 /*3.926991*/
.text
glabel actor_hops_sideways
/* 05EF58 7F02A428 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 05EF5C 7F02A42C AFBF001C */  sw    $ra, 0x1c($sp)
/* 05EF60 7F02A430 AFB00018 */  sw    $s0, 0x18($sp)
/* 05EF64 7F02A434 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05EF68 7F02A438 00808025 */   move  $s0, $a0
/* 05EF6C 7F02A43C 5040004D */  beql  $v0, $zero, .L7F02A574
/* 05EF70 7F02A440 00001025 */   move  $v0, $zero
/* 05EF74 7F02A444 8E0E0018 */  lw    $t6, 0x18($s0)
/* 05EF78 7F02A448 0FC225E6 */  jal   get_curplayer_positiondata
/* 05EF7C 7F02A44C AFAE004C */   sw    $t6, 0x4c($sp)
/* 05EF80 7F02A450 8E04001C */  lw    $a0, 0x1c($s0)
/* 05EF84 7F02A454 0FC1B320 */  jal   getsubroty
/* 05EF88 7F02A458 AFA20048 */   sw    $v0, 0x48($sp)
/* 05EF8C 7F02A45C 8FA2004C */  lw    $v0, 0x4c($sp)
/* 05EF90 7F02A460 8FA30048 */  lw    $v1, 0x48($sp)
/* 05EF94 7F02A464 C4460008 */  lwc1  $f6, 8($v0)
/* 05EF98 7F02A468 C44A0010 */  lwc1  $f10, 0x10($v0)
/* 05EF9C 7F02A46C C4640008 */  lwc1  $f4, 8($v1)
/* 05EFA0 7F02A470 C4680010 */  lwc1  $f8, 0x10($v1)
/* 05EFA4 7F02A474 E7A00040 */  swc1  $f0, 0x40($sp)
/* 05EFA8 7F02A478 46062301 */  sub.s $f12, $f4, $f6
/* 05EFAC 7F02A47C 0FC16A8C */  jal   atan2f
/* 05EFB0 7F02A480 460A4381 */   sub.s $f14, $f8, $f10
/* 05EFB4 7F02A484 C7B00040 */  lwc1  $f16, 0x40($sp)
/* 05EFB8 7F02A488 3C018005 */  lui   $at, %hi(D_80051E4C)
/* 05EFBC 7F02A48C 4610003C */  c.lt.s $f0, $f16
/* 05EFC0 7F02A490 46100301 */  sub.s $f12, $f0, $f16
/* 05EFC4 7F02A494 45000003 */  bc1f  .L7F02A4A4
/* 05EFC8 7F02A498 46006086 */   mov.s $f2, $f12
/* 05EFCC 7F02A49C C4321E4C */  lwc1  $f18, %lo(D_80051E4C)($at)
/* 05EFD0 7F02A4A0 46126080 */  add.s $f2, $f12, $f18
.L7F02A4A4:
/* 05EFD4 7F02A4A4 3C018005 */  lui   $at, %hi(D_80051E50)
/* 05EFD8 7F02A4A8 C4241E50 */  lwc1  $f4, %lo(D_80051E50)($at)
/* 05EFDC 7F02A4AC 3C018005 */  lui   $at, %hi(D_80051E54)
/* 05EFE0 7F02A4B0 4604103C */  c.lt.s $f2, $f4
/* 05EFE4 7F02A4B4 00000000 */  nop   
/* 05EFE8 7F02A4B8 45010012 */  bc1t  .L7F02A504
/* 05EFEC 7F02A4BC 00000000 */   nop   
/* 05EFF0 7F02A4C0 C4261E54 */  lwc1  $f6, %lo(D_80051E54)($at)
/* 05EFF4 7F02A4C4 3C018005 */  lui   $at, %hi(D_80051E58)
/* 05EFF8 7F02A4C8 4602303C */  c.lt.s $f6, $f2
/* 05EFFC 7F02A4CC 00000000 */  nop   
/* 05F000 7F02A4D0 4501000C */  bc1t  .L7F02A504
/* 05F004 7F02A4D4 00000000 */   nop   
/* 05F008 7F02A4D8 C4281E58 */  lwc1  $f8, %lo(D_80051E58)($at)
/* 05F00C 7F02A4DC 3C018005 */  lui   $at, %hi(D_80051E5C)
/* 05F010 7F02A4E0 4602403C */  c.lt.s $f8, $f2
/* 05F014 7F02A4E4 00000000 */  nop   
/* 05F018 7F02A4E8 45020022 */  bc1fl .L7F02A574
/* 05F01C 7F02A4EC 00001025 */   move  $v0, $zero
/* 05F020 7F02A4F0 C42A1E5C */  lwc1  $f10, %lo(D_80051E5C)($at)
/* 05F024 7F02A4F4 460A103C */  c.lt.s $f2, $f10
/* 05F028 7F02A4F8 00000000 */  nop   
/* 05F02C 7F02A4FC 4502001D */  bc1fl .L7F02A574
/* 05F030 7F02A500 00001025 */   move  $v0, $zero
.L7F02A504:
/* 05F034 7F02A504 0C002914 */  jal   randomGetNext
/* 05F038 7F02A508 00000000 */   nop   
/* 05F03C 7F02A50C 30450001 */  andi  $a1, $v0, 1
/* 05F040 7F02A510 2CAF0001 */  sltiu $t7, $a1, 1
/* 05F044 7F02A514 01E02825 */  move  $a1, $t7
/* 05F048 7F02A518 AFAF002C */  sw    $t7, 0x2c($sp)
/* 05F04C 7F02A51C 02002025 */  move  $a0, $s0
/* 05F050 7F02A520 0FC0A87A */  jal   sub_GAME_7F02A1E8
/* 05F054 7F02A524 3C064348 */   lui   $a2, 0x4348
/* 05F058 7F02A528 10400006 */  beqz  $v0, .L7F02A544
/* 05F05C 7F02A52C 8FA7002C */   lw    $a3, 0x2c($sp)
/* 05F060 7F02A530 02002025 */  move  $a0, $s0
/* 05F064 7F02A534 0FC092A1 */  jal   chrlvFireJumpToSideAnimationRelated
/* 05F068 7F02A538 00E02825 */   move  $a1, $a3
/* 05F06C 7F02A53C 1000000D */  b     .L7F02A574
/* 05F070 7F02A540 24020001 */   li    $v0, 1
.L7F02A544:
/* 05F074 7F02A544 2CE50001 */  sltiu $a1, $a3, 1
/* 05F078 7F02A548 AFA50024 */  sw    $a1, 0x24($sp)
/* 05F07C 7F02A54C 02002025 */  move  $a0, $s0
/* 05F080 7F02A550 0FC0A87A */  jal   sub_GAME_7F02A1E8
/* 05F084 7F02A554 3C064348 */   lui   $a2, 0x4348
/* 05F088 7F02A558 10400005 */  beqz  $v0, .L7F02A570
/* 05F08C 7F02A55C 8FA50024 */   lw    $a1, 0x24($sp)
/* 05F090 7F02A560 0FC092A1 */  jal   chrlvFireJumpToSideAnimationRelated
/* 05F094 7F02A564 02002025 */   move  $a0, $s0
/* 05F098 7F02A568 10000002 */  b     .L7F02A574
/* 05F09C 7F02A56C 24020001 */   li    $v0, 1
.L7F02A570:
/* 05F0A0 7F02A570 00001025 */  move  $v0, $zero
.L7F02A574:
/* 05F0A4 7F02A574 8FBF001C */  lw    $ra, 0x1c($sp)
/* 05F0A8 7F02A578 8FB00018 */  lw    $s0, 0x18($sp)
/* 05F0AC 7F02A57C 27BD0050 */  addiu $sp, $sp, 0x50
/* 05F0B0 7F02A580 03E00008 */  jr    $ra
/* 05F0B4 7F02A584 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void actor_runs_sideways(void) {
// ai branch actor_jogs_sideways
}
#else
GLOBAL_ASM(
.text
glabel actor_runs_sideways
/* 05F0B8 7F02A588 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 05F0BC 7F02A58C AFBF0024 */  sw    $ra, 0x24($sp)
/* 05F0C0 7F02A590 AFB10020 */  sw    $s1, 0x20($sp)
/* 05F0C4 7F02A594 00808825 */  move  $s1, $a0
/* 05F0C8 7F02A598 AFB0001C */  sw    $s0, 0x1c($sp)
/* 05F0CC 7F02A59C 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F0D0 7F02A5A0 F7B40010 */   sdc1  $f20, 0x10($sp)
/* 05F0D4 7F02A5A4 10400050 */  beqz  $v0, .L7F02A6E8
/* 05F0D8 7F02A5A8 3C0E8005 */   lui   $t6, %hi(g_GlobalTimer) 
/* 05F0DC 7F02A5AC 8DCE837C */  lw    $t6, %lo(g_GlobalTimer)($t6)
/* 05F0E0 7F02A5B0 8E2F00C8 */  lw    $t7, 0xc8($s1)
/* 05F0E4 7F02A5B4 01CFC023 */  subu  $t8, $t6, $t7
/* 05F0E8 7F02A5B8 2B0100B5 */  slti  $at, $t8, 0xb5
/* 05F0EC 7F02A5BC 5420004B */  bnezl $at, .L7F02A6EC
/* 05F0F0 7F02A5C0 00001025 */   move  $v0, $zero
/* 05F0F4 7F02A5C4 0C002914 */  jal   randomGetNext
/* 05F0F8 7F02A5C8 8E300018 */   lw    $s0, 0x18($s1)
/* 05F0FC 7F02A5CC 44822000 */  mtc1  $v0, $f4
/* 05F100 7F02A5D0 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 05F104 7F02A5D4 44810000 */  mtc1  $at, $f0
/* 05F108 7F02A5D8 04410005 */  bgez  $v0, .L7F02A5F0
/* 05F10C 7F02A5DC 468021A0 */   cvt.s.w $f6, $f4
/* 05F110 7F02A5E0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 05F114 7F02A5E4 44814000 */  mtc1  $at, $f8
/* 05F118 7F02A5E8 00000000 */  nop   
/* 05F11C 7F02A5EC 46083180 */  add.s $f6, $f6, $f8
.L7F02A5F0:
/* 05F120 7F02A5F0 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 05F124 7F02A5F4 44815000 */  mtc1  $at, $f10
/* 05F128 7F02A5F8 00000000 */  nop   
/* 05F12C 7F02A5FC 460A3402 */  mul.s $f16, $f6, $f10
/* 05F130 7F02A600 00000000 */  nop   
/* 05F134 7F02A604 46008482 */  mul.s $f18, $f16, $f0
/* 05F138 7F02A608 0C002914 */  jal   randomGetNext
/* 05F13C 7F02A60C 46009500 */   add.s $f20, $f18, $f0
/* 05F140 7F02A610 30450001 */  andi  $a1, $v0, 1
/* 05F144 7F02A614 2CB90001 */  sltiu $t9, $a1, 1
/* 05F148 7F02A618 03202825 */  move  $a1, $t9
/* 05F14C 7F02A61C 02202025 */  move  $a0, $s1
/* 05F150 7F02A620 0FC0A811 */  jal   chrlvNormDistanceToPlayer
/* 05F154 7F02A624 27A6003C */   addiu $a2, $sp, 0x3c
/* 05F158 7F02A628 C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 05F15C 7F02A62C C6060008 */  lwc1  $f6, 8($s0)
/* 05F160 7F02A630 C7B20044 */  lwc1  $f18, 0x44($sp)
/* 05F164 7F02A634 46142202 */  mul.s $f8, $f4, $f20
/* 05F168 7F02A638 02002025 */  move  $a0, $s0
/* 05F16C 7F02A63C 27A50030 */  addiu $a1, $sp, 0x30
/* 05F170 7F02A640 46149102 */  mul.s $f4, $f18, $f20
/* 05F174 7F02A644 27A6003C */  addiu $a2, $sp, 0x3c
/* 05F178 7F02A648 46064280 */  add.s $f10, $f8, $f6
/* 05F17C 7F02A64C E7AA0030 */  swc1  $f10, 0x30($sp)
/* 05F180 7F02A650 C610000C */  lwc1  $f16, 0xc($s0)
/* 05F184 7F02A654 E7B00034 */  swc1  $f16, 0x34($sp)
/* 05F188 7F02A658 C6080010 */  lwc1  $f8, 0x10($s0)
/* 05F18C 7F02A65C 46082180 */  add.s $f6, $f4, $f8
/* 05F190 7F02A660 0FC0A60B */  jal   chrlvCall7F0B0E24WithChrWidthHeight
/* 05F194 7F02A664 E7A60038 */   swc1  $f6, 0x38($sp)
/* 05F198 7F02A668 10400006 */  beqz  $v0, .L7F02A684
/* 05F19C 7F02A66C C7AA003C */   lwc1  $f10, 0x3c($sp)
/* 05F1A0 7F02A670 02202025 */  move  $a0, $s1
/* 05F1A4 7F02A674 0FC0933E */  jal   sub_GAME_7F024CF8
/* 05F1A8 7F02A678 27A50030 */   addiu $a1, $sp, 0x30
/* 05F1AC 7F02A67C 1000001B */  b     .L7F02A6EC
/* 05F1B0 7F02A680 24020001 */   li    $v0, 1
.L7F02A684:
/* 05F1B4 7F02A684 C7B20044 */  lwc1  $f18, 0x44($sp)
/* 05F1B8 7F02A688 46005407 */  neg.s $f16, $f10
/* 05F1BC 7F02A68C 02002025 */  move  $a0, $s0
/* 05F1C0 7F02A690 46148202 */  mul.s $f8, $f16, $f20
/* 05F1C4 7F02A694 46009107 */  neg.s $f4, $f18
/* 05F1C8 7F02A698 E7B0003C */  swc1  $f16, 0x3c($sp)
/* 05F1CC 7F02A69C E7A40044 */  swc1  $f4, 0x44($sp)
/* 05F1D0 7F02A6A0 C6060008 */  lwc1  $f6, 8($s0)
/* 05F1D4 7F02A6A4 46142402 */  mul.s $f16, $f4, $f20
/* 05F1D8 7F02A6A8 27A50030 */  addiu $a1, $sp, 0x30
/* 05F1DC 7F02A6AC 46064280 */  add.s $f10, $f8, $f6
/* 05F1E0 7F02A6B0 27A6003C */  addiu $a2, $sp, 0x3c
/* 05F1E4 7F02A6B4 E7AA0030 */  swc1  $f10, 0x30($sp)
/* 05F1E8 7F02A6B8 C612000C */  lwc1  $f18, 0xc($s0)
/* 05F1EC 7F02A6BC E7B20034 */  swc1  $f18, 0x34($sp)
/* 05F1F0 7F02A6C0 C6080010 */  lwc1  $f8, 0x10($s0)
/* 05F1F4 7F02A6C4 46088180 */  add.s $f6, $f16, $f8
/* 05F1F8 7F02A6C8 0FC0A60B */  jal   chrlvCall7F0B0E24WithChrWidthHeight
/* 05F1FC 7F02A6CC E7A60038 */   swc1  $f6, 0x38($sp)
/* 05F200 7F02A6D0 10400005 */  beqz  $v0, .L7F02A6E8
/* 05F204 7F02A6D4 02202025 */   move  $a0, $s1
/* 05F208 7F02A6D8 0FC0933E */  jal   sub_GAME_7F024CF8
/* 05F20C 7F02A6DC 27A50030 */   addiu $a1, $sp, 0x30
/* 05F210 7F02A6E0 10000002 */  b     .L7F02A6EC
/* 05F214 7F02A6E4 24020001 */   li    $v0, 1
.L7F02A6E8:
/* 05F218 7F02A6E8 00001025 */  move  $v0, $zero
.L7F02A6EC:
/* 05F21C 7F02A6EC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 05F220 7F02A6F0 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 05F224 7F02A6F4 8FB0001C */  lw    $s0, 0x1c($sp)
/* 05F228 7F02A6F8 8FB10020 */  lw    $s1, 0x20($sp)
/* 05F22C 7F02A6FC 03E00008 */  jr    $ra
/* 05F230 7F02A700 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif



#ifdef NONMATCHING
void actor_walks_and_fires(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E60
.word 0x49742400 /*1000000.0*/
.text
glabel actor_walks_and_fires
/* 05F234 7F02A704 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 05F238 7F02A708 AFBF001C */  sw    $ra, 0x1c($sp)
/* 05F23C 7F02A70C AFB00018 */  sw    $s0, 0x18($sp)
/* 05F240 7F02A710 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F244 7F02A714 00808025 */   move  $s0, $a0
/* 05F248 7F02A718 50400032 */  beql  $v0, $zero, .L7F02A7E4
/* 05F24C 7F02A71C 00001025 */   move  $v0, $zero
/* 05F250 7F02A720 8E0E0018 */  lw    $t6, 0x18($s0)
/* 05F254 7F02A724 0FC225E6 */  jal   get_curplayer_positiondata
/* 05F258 7F02A728 AFAE0024 */   sw    $t6, 0x24($sp)
/* 05F25C 7F02A72C 02002025 */  move  $a0, $s0
/* 05F260 7F02A730 00002825 */  move  $a1, $zero
/* 05F264 7F02A734 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F268 7F02A738 AFA20020 */   sw    $v0, 0x20($sp)
/* 05F26C 7F02A73C 14400007 */  bnez  $v0, .L7F02A75C
/* 05F270 7F02A740 8FA30020 */   lw    $v1, 0x20($sp)
/* 05F274 7F02A744 02002025 */  move  $a0, $s0
/* 05F278 7F02A748 24050001 */  li    $a1, 1
/* 05F27C 7F02A74C 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F280 7F02A750 AFA30020 */   sw    $v1, 0x20($sp)
/* 05F284 7F02A754 10400022 */  beqz  $v0, .L7F02A7E0
/* 05F288 7F02A758 8FA30020 */   lw    $v1, 0x20($sp)
.L7F02A75C:
/* 05F28C 7F02A75C 3C0F8005 */  lui   $t7, %hi(g_GlobalTimer) 
/* 05F290 7F02A760 8DEF837C */  lw    $t7, %lo(g_GlobalTimer)($t7)
/* 05F294 7F02A764 8E1800C8 */  lw    $t8, 0xc8($s0)
/* 05F298 7F02A768 8FA20024 */  lw    $v0, 0x24($sp)
/* 05F29C 7F02A76C 01F8C823 */  subu  $t9, $t7, $t8
/* 05F2A0 7F02A770 2B2100B5 */  slti  $at, $t9, 0xb5
/* 05F2A4 7F02A774 5420001B */  bnezl $at, .L7F02A7E4
/* 05F2A8 7F02A778 00001025 */   move  $v0, $zero
/* 05F2AC 7F02A77C C4640008 */  lwc1  $f4, 8($v1)
/* 05F2B0 7F02A780 C4460008 */  lwc1  $f6, 8($v0)
/* 05F2B4 7F02A784 C468000C */  lwc1  $f8, 0xc($v1)
/* 05F2B8 7F02A788 C44A000C */  lwc1  $f10, 0xc($v0)
/* 05F2BC 7F02A78C 46062001 */  sub.s $f0, $f4, $f6
/* 05F2C0 7F02A790 C4700010 */  lwc1  $f16, 0x10($v1)
/* 05F2C4 7F02A794 C4520010 */  lwc1  $f18, 0x10($v0)
/* 05F2C8 7F02A798 460A4081 */  sub.s $f2, $f8, $f10
/* 05F2CC 7F02A79C 46000102 */  mul.s $f4, $f0, $f0
/* 05F2D0 7F02A7A0 3C018005 */  lui   $at, %hi(D_80051E60)
/* 05F2D4 7F02A7A4 46128301 */  sub.s $f12, $f16, $f18
/* 05F2D8 7F02A7A8 46021182 */  mul.s $f6, $f2, $f2
/* 05F2DC 7F02A7AC C4321E60 */  lwc1  $f18, %lo(D_80051E60)($at)
/* 05F2E0 7F02A7B0 02002025 */  move  $a0, $s0
/* 05F2E4 7F02A7B4 460C6282 */  mul.s $f10, $f12, $f12
/* 05F2E8 7F02A7B8 46062200 */  add.s $f8, $f4, $f6
/* 05F2EC 7F02A7BC 460A4400 */  add.s $f16, $f8, $f10
/* 05F2F0 7F02A7C0 4610903E */  c.le.s $f18, $f16
/* 05F2F4 7F02A7C4 00000000 */  nop   
/* 05F2F8 7F02A7C8 45020006 */  bc1fl .L7F02A7E4
/* 05F2FC 7F02A7CC 00001025 */   move  $v0, $zero
/* 05F300 7F02A7D0 0FC0961F */  jal   sub_GAME_7F02587C
/* 05F304 7F02A7D4 00002825 */   move  $a1, $zero
/* 05F308 7F02A7D8 10000002 */  b     .L7F02A7E4
/* 05F30C 7F02A7DC 24020001 */   li    $v0, 1
.L7F02A7E0:
/* 05F310 7F02A7E0 00001025 */  move  $v0, $zero
.L7F02A7E4:
/* 05F314 7F02A7E4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 05F318 7F02A7E8 8FB00018 */  lw    $s0, 0x18($sp)
/* 05F31C 7F02A7EC 27BD0028 */  addiu $sp, $sp, 0x28
/* 05F320 7F02A7F0 03E00008 */  jr    $ra
/* 05F324 7F02A7F4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void actor_runs_and_fires(void) {
// ai branch
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E64
.word 0x49742400 /*1000000.0*/
.text
glabel actor_runs_and_fires
/* 05F328 7F02A7F8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 05F32C 7F02A7FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 05F330 7F02A800 AFB00018 */  sw    $s0, 0x18($sp)
/* 05F334 7F02A804 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F338 7F02A808 00808025 */   move  $s0, $a0
/* 05F33C 7F02A80C 50400032 */  beql  $v0, $zero, .L7F02A8D8
/* 05F340 7F02A810 00001025 */   move  $v0, $zero
/* 05F344 7F02A814 8E0E0018 */  lw    $t6, 0x18($s0)
/* 05F348 7F02A818 0FC225E6 */  jal   get_curplayer_positiondata
/* 05F34C 7F02A81C AFAE0024 */   sw    $t6, 0x24($sp)
/* 05F350 7F02A820 02002025 */  move  $a0, $s0
/* 05F354 7F02A824 00002825 */  move  $a1, $zero
/* 05F358 7F02A828 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F35C 7F02A82C AFA20020 */   sw    $v0, 0x20($sp)
/* 05F360 7F02A830 14400007 */  bnez  $v0, .L7F02A850
/* 05F364 7F02A834 8FA30020 */   lw    $v1, 0x20($sp)
/* 05F368 7F02A838 02002025 */  move  $a0, $s0
/* 05F36C 7F02A83C 24050001 */  li    $a1, 1
/* 05F370 7F02A840 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F374 7F02A844 AFA30020 */   sw    $v1, 0x20($sp)
/* 05F378 7F02A848 10400022 */  beqz  $v0, .L7F02A8D4
/* 05F37C 7F02A84C 8FA30020 */   lw    $v1, 0x20($sp)
.L7F02A850:
/* 05F380 7F02A850 3C0F8005 */  lui   $t7, %hi(g_GlobalTimer) 
/* 05F384 7F02A854 8DEF837C */  lw    $t7, %lo(g_GlobalTimer)($t7)
/* 05F388 7F02A858 8E1800C8 */  lw    $t8, 0xc8($s0)
/* 05F38C 7F02A85C 8FA20024 */  lw    $v0, 0x24($sp)
/* 05F390 7F02A860 01F8C823 */  subu  $t9, $t7, $t8
/* 05F394 7F02A864 2B2100B5 */  slti  $at, $t9, 0xb5
/* 05F398 7F02A868 5420001B */  bnezl $at, .L7F02A8D8
/* 05F39C 7F02A86C 00001025 */   move  $v0, $zero
/* 05F3A0 7F02A870 C4640008 */  lwc1  $f4, 8($v1)
/* 05F3A4 7F02A874 C4460008 */  lwc1  $f6, 8($v0)
/* 05F3A8 7F02A878 C468000C */  lwc1  $f8, 0xc($v1)
/* 05F3AC 7F02A87C C44A000C */  lwc1  $f10, 0xc($v0)
/* 05F3B0 7F02A880 46062001 */  sub.s $f0, $f4, $f6
/* 05F3B4 7F02A884 C4700010 */  lwc1  $f16, 0x10($v1)
/* 05F3B8 7F02A888 C4520010 */  lwc1  $f18, 0x10($v0)
/* 05F3BC 7F02A88C 460A4081 */  sub.s $f2, $f8, $f10
/* 05F3C0 7F02A890 46000102 */  mul.s $f4, $f0, $f0
/* 05F3C4 7F02A894 3C018005 */  lui   $at, %hi(D_80051E64)
/* 05F3C8 7F02A898 46128301 */  sub.s $f12, $f16, $f18
/* 05F3CC 7F02A89C 46021182 */  mul.s $f6, $f2, $f2
/* 05F3D0 7F02A8A0 C4321E64 */  lwc1  $f18, %lo(D_80051E64)($at)
/* 05F3D4 7F02A8A4 02002025 */  move  $a0, $s0
/* 05F3D8 7F02A8A8 460C6282 */  mul.s $f10, $f12, $f12
/* 05F3DC 7F02A8AC 46062200 */  add.s $f8, $f4, $f6
/* 05F3E0 7F02A8B0 460A4400 */  add.s $f16, $f8, $f10
/* 05F3E4 7F02A8B4 4610903E */  c.le.s $f18, $f16
/* 05F3E8 7F02A8B8 00000000 */  nop   
/* 05F3EC 7F02A8BC 45020006 */  bc1fl .L7F02A8D8
/* 05F3F0 7F02A8C0 00001025 */   move  $v0, $zero
/* 05F3F4 7F02A8C4 0FC0961F */  jal   sub_GAME_7F02587C
/* 05F3F8 7F02A8C8 24050001 */   li    $a1, 1
/* 05F3FC 7F02A8CC 10000002 */  b     .L7F02A8D8
/* 05F400 7F02A8D0 24020001 */   li    $v0, 1
.L7F02A8D4:
/* 05F404 7F02A8D4 00001025 */  move  $v0, $zero
.L7F02A8D8:
/* 05F408 7F02A8D8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 05F40C 7F02A8DC 8FB00018 */  lw    $s0, 0x18($sp)
/* 05F410 7F02A8E0 27BD0028 */  addiu $sp, $sp, 0x28
/* 05F414 7F02A8E4 03E00008 */  jr    $ra
/* 05F418 7F02A8E8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void actor_rolls_fires_crouched(void) {
// ai branch
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E68
.word 0x471c4000 /*40000.0*/
.text
glabel actor_rolls_fires_crouched
/* 05F41C 7F02A8EC 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 05F420 7F02A8F0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 05F424 7F02A8F4 AFB00018 */  sw    $s0, 0x18($sp)
/* 05F428 7F02A8F8 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F42C 7F02A8FC 00808025 */   move  $s0, $a0
/* 05F430 7F02A900 50400041 */  beql  $v0, $zero, .L7F02AA08
/* 05F434 7F02A904 00001025 */   move  $v0, $zero
/* 05F438 7F02A908 8E0E0018 */  lw    $t6, 0x18($s0)
/* 05F43C 7F02A90C 0FC225E6 */  jal   get_curplayer_positiondata
/* 05F440 7F02A910 AFAE0044 */   sw    $t6, 0x44($sp)
/* 05F444 7F02A914 02002025 */  move  $a0, $s0
/* 05F448 7F02A918 00002825 */  move  $a1, $zero
/* 05F44C 7F02A91C 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F450 7F02A920 AFA20040 */   sw    $v0, 0x40($sp)
/* 05F454 7F02A924 14400007 */  bnez  $v0, .L7F02A944
/* 05F458 7F02A928 8FA30040 */   lw    $v1, 0x40($sp)
/* 05F45C 7F02A92C 02002025 */  move  $a0, $s0
/* 05F460 7F02A930 24050001 */  li    $a1, 1
/* 05F464 7F02A934 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F468 7F02A938 AFA30040 */   sw    $v1, 0x40($sp)
/* 05F46C 7F02A93C 10400031 */  beqz  $v0, .L7F02AA04
/* 05F470 7F02A940 8FA30040 */   lw    $v1, 0x40($sp)
.L7F02A944:
/* 05F474 7F02A944 8FA20044 */  lw    $v0, 0x44($sp)
/* 05F478 7F02A948 C4640008 */  lwc1  $f4, 8($v1)
/* 05F47C 7F02A94C C468000C */  lwc1  $f8, 0xc($v1)
/* 05F480 7F02A950 C4460008 */  lwc1  $f6, 8($v0)
/* 05F484 7F02A954 C44A000C */  lwc1  $f10, 0xc($v0)
/* 05F488 7F02A958 C4700010 */  lwc1  $f16, 0x10($v1)
/* 05F48C 7F02A95C 46062001 */  sub.s $f0, $f4, $f6
/* 05F490 7F02A960 C4520010 */  lwc1  $f18, 0x10($v0)
/* 05F494 7F02A964 3C018005 */  lui   $at, %hi(D_80051E68)
/* 05F498 7F02A968 460A4081 */  sub.s $f2, $f8, $f10
/* 05F49C 7F02A96C 46000102 */  mul.s $f4, $f0, $f0
/* 05F4A0 7F02A970 46128301 */  sub.s $f12, $f16, $f18
/* 05F4A4 7F02A974 46021182 */  mul.s $f6, $f2, $f2
/* 05F4A8 7F02A978 C4321E68 */  lwc1  $f18, %lo(D_80051E68)($at)
/* 05F4AC 7F02A97C 460C6282 */  mul.s $f10, $f12, $f12
/* 05F4B0 7F02A980 46062200 */  add.s $f8, $f4, $f6
/* 05F4B4 7F02A984 460A4400 */  add.s $f16, $f8, $f10
/* 05F4B8 7F02A988 4610903E */  c.le.s $f18, $f16
/* 05F4BC 7F02A98C 00000000 */  nop   
/* 05F4C0 7F02A990 4502001D */  bc1fl .L7F02AA08
/* 05F4C4 7F02A994 00001025 */   move  $v0, $zero
/* 05F4C8 7F02A998 0C002914 */  jal   randomGetNext
/* 05F4CC 7F02A99C 00000000 */   nop   
/* 05F4D0 7F02A9A0 30450001 */  andi  $a1, $v0, 1
/* 05F4D4 7F02A9A4 2CAF0001 */  sltiu $t7, $a1, 1
/* 05F4D8 7F02A9A8 01E02825 */  move  $a1, $t7
/* 05F4DC 7F02A9AC AFAF002C */  sw    $t7, 0x2c($sp)
/* 05F4E0 7F02A9B0 02002025 */  move  $a0, $s0
/* 05F4E4 7F02A9B4 0FC0A83B */  jal   sub_GAME_7F02A0EC
/* 05F4E8 7F02A9B8 3C064348 */   lui   $a2, 0x4348
/* 05F4EC 7F02A9BC 10400006 */  beqz  $v0, .L7F02A9D8
/* 05F4F0 7F02A9C0 8FA7002C */   lw    $a3, 0x2c($sp)
/* 05F4F4 7F02A9C4 02002025 */  move  $a0, $s0
/* 05F4F8 7F02A9C8 0FC09710 */  jal   sub_GAME_7F025C40
/* 05F4FC 7F02A9CC 00E02825 */   move  $a1, $a3
/* 05F500 7F02A9D0 1000000D */  b     .L7F02AA08
/* 05F504 7F02A9D4 24020001 */   li    $v0, 1
.L7F02A9D8:
/* 05F508 7F02A9D8 2CE50001 */  sltiu $a1, $a3, 1
/* 05F50C 7F02A9DC AFA50024 */  sw    $a1, 0x24($sp)
/* 05F510 7F02A9E0 02002025 */  move  $a0, $s0
/* 05F514 7F02A9E4 0FC0A83B */  jal   sub_GAME_7F02A0EC
/* 05F518 7F02A9E8 3C064348 */   lui   $a2, 0x4348
/* 05F51C 7F02A9EC 10400005 */  beqz  $v0, .L7F02AA04
/* 05F520 7F02A9F0 8FA50024 */   lw    $a1, 0x24($sp)
/* 05F524 7F02A9F4 0FC09710 */  jal   sub_GAME_7F025C40
/* 05F528 7F02A9F8 02002025 */   move  $a0, $s0
/* 05F52C 7F02A9FC 10000002 */  b     .L7F02AA08
/* 05F530 7F02AA00 24020001 */   li    $v0, 1
.L7F02AA04:
/* 05F534 7F02AA04 00001025 */  move  $v0, $zero
.L7F02AA08:
/* 05F538 7F02AA08 8FBF001C */  lw    $ra, 0x1c($sp)
/* 05F53C 7F02AA0C 8FB00018 */  lw    $s0, 0x18($sp)
/* 05F540 7F02AA10 27BD0048 */  addiu $sp, $sp, 0x48
/* 05F544 7F02AA14 03E00008 */  jr    $ra
/* 05F548 7F02AA18 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void actor_aim_at_actor(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel actor_aim_at_actor
/* 05F54C 7F02AA1C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 05F550 7F02AA20 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05F554 7F02AA24 AFA40018 */  sw    $a0, 0x18($sp)
/* 05F558 7F02AA28 AFA5001C */  sw    $a1, 0x1c($sp)
/* 05F55C 7F02AA2C 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F560 7F02AA30 AFA60020 */   sw    $a2, 0x20($sp)
/* 05F564 7F02AA34 1040000F */  beqz  $v0, .L7F02AA74
/* 05F568 7F02AA38 8FA40018 */   lw    $a0, 0x18($sp)
/* 05F56C 7F02AA3C 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F570 7F02AA40 00002825 */   move  $a1, $zero
/* 05F574 7F02AA44 14400005 */  bnez  $v0, .L7F02AA5C
/* 05F578 7F02AA48 8FA40018 */   lw    $a0, 0x18($sp)
/* 05F57C 7F02AA4C 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F580 7F02AA50 24050001 */   li    $a1, 1
/* 05F584 7F02AA54 50400008 */  beql  $v0, $zero, .L7F02AA78
/* 05F588 7F02AA58 00001025 */   move  $v0, $zero
.L7F02AA5C:
/* 05F58C 7F02AA5C 8FA40018 */  lw    $a0, 0x18($sp)
/* 05F590 7F02AA60 8FA5001C */  lw    $a1, 0x1c($sp)
/* 05F594 7F02AA64 0FC09558 */  jal   sub_GAME_7F025560
/* 05F598 7F02AA68 8FA60020 */   lw    $a2, 0x20($sp)
/* 05F59C 7F02AA6C 10000002 */  b     .L7F02AA78
/* 05F5A0 7F02AA70 24020001 */   li    $v0, 1
.L7F02AA74:
/* 05F5A4 7F02AA74 00001025 */  move  $v0, $zero
.L7F02AA78:
/* 05F5A8 7F02AA78 8FBF0014 */  lw    $ra, 0x14($sp)
/* 05F5AC 7F02AA7C 27BD0018 */  addiu $sp, $sp, 0x18
/* 05F5B0 7F02AA80 03E00008 */  jr    $ra
/* 05F5B4 7F02AA84 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void actor_kneel_aim_at_actor(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel actor_kneel_aim_at_actor
/* 05F5B8 7F02AA88 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 05F5BC 7F02AA8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 05F5C0 7F02AA90 AFA40018 */  sw    $a0, 0x18($sp)
/* 05F5C4 7F02AA94 AFA5001C */  sw    $a1, 0x1c($sp)
/* 05F5C8 7F02AA98 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F5CC 7F02AA9C AFA60020 */   sw    $a2, 0x20($sp)
/* 05F5D0 7F02AAA0 1040000F */  beqz  $v0, .L7F02AAE0
/* 05F5D4 7F02AAA4 8FA40018 */   lw    $a0, 0x18($sp)
/* 05F5D8 7F02AAA8 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F5DC 7F02AAAC 00002825 */   move  $a1, $zero
/* 05F5E0 7F02AAB0 14400005 */  bnez  $v0, .L7F02AAC8
/* 05F5E4 7F02AAB4 8FA40018 */   lw    $a0, 0x18($sp)
/* 05F5E8 7F02AAB8 0FC08C0F */  jal   is_weapon_in_guarddata_hand
/* 05F5EC 7F02AABC 24050001 */   li    $a1, 1
/* 05F5F0 7F02AAC0 50400008 */  beql  $v0, $zero, .L7F02AAE4
/* 05F5F4 7F02AAC4 00001025 */   move  $v0, $zero
.L7F02AAC8:
/* 05F5F8 7F02AAC8 8FA40018 */  lw    $a0, 0x18($sp)
/* 05F5FC 7F02AACC 8FA5001C */  lw    $a1, 0x1c($sp)
/* 05F600 7F02AAD0 0FC095BC */  jal   sub_GAME_7F0256F0
/* 05F604 7F02AAD4 8FA60020 */   lw    $a2, 0x20($sp)
/* 05F608 7F02AAD8 10000002 */  b     .L7F02AAE4
/* 05F60C 7F02AADC 24020001 */   li    $v0, 1
.L7F02AAE0:
/* 05F610 7F02AAE0 00001025 */  move  $v0, $zero
.L7F02AAE4:
/* 05F614 7F02AAE4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 05F618 7F02AAE8 27BD0018 */  addiu $sp, $sp, 0x18
/* 05F61C 7F02AAEC 03E00008 */  jr    $ra
/* 05F620 7F02AAF0 00000000 */   nop   
)
#endif



int actor_fire_or_aim_at_target_update(struct ChrRecord *chr, u32 newflag, u32 newtarget)
{
    if(chr->actiontype == ACT_ATTACK)
    {
        if((chr->act_attack.attacktype & (TARGET_AIM_ONLY | TARGET_DONTTURN)) != 0)
        {
            chr->act_attack.attacktype = newflag;
            chr->act_attack.entityid = newtarget;
            chrlvAttackActionRelated(chr);
            return 1;
        }
    }

    return 0;
}



#ifdef NONMATCHING
void check_set_actor_standing_still(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel check_set_actor_standing_still
/* 05F674 7F02AB44 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 05F678 7F02AB48 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05F67C 7F02AB4C AFA5001C */  sw    $a1, 0x1c($sp)
/* 05F680 7F02AB50 AFA60020 */  sw    $a2, 0x20($sp)
/* 05F684 7F02AB54 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F688 7F02AB58 AFA40018 */   sw    $a0, 0x18($sp)
/* 05F68C 7F02AB5C 10400010 */  beqz  $v0, .L7F02ABA0
/* 05F690 7F02AB60 8FA40018 */   lw    $a0, 0x18($sp)
/* 05F694 7F02AB64 808E0007 */  lb    $t6, 7($a0)
/* 05F698 7F02AB68 24010001 */  li    $at, 1
/* 05F69C 7F02AB6C 51C10005 */  beql  $t6, $at, .L7F02AB84
/* 05F6A0 7F02AB70 8FAF001C */   lw    $t7, 0x1c($sp)
/* 05F6A4 7F02AB74 0FC08F2E */  jal   chrlvKneelingAnimationRelated
/* 05F6A8 7F02AB78 AFA40018 */   sw    $a0, 0x18($sp)
/* 05F6AC 7F02AB7C 8FA40018 */  lw    $a0, 0x18($sp)
/* 05F6B0 7F02AB80 8FAF001C */  lw    $t7, 0x1c($sp)
.L7F02AB84:
/* 05F6B4 7F02AB84 24020001 */  li    $v0, 1
/* 05F6B8 7F02AB88 AC8F0030 */  sw    $t7, 0x30($a0)
/* 05F6BC 7F02AB8C 8FB80020 */  lw    $t8, 0x20($sp)
/* 05F6C0 7F02AB90 AC800038 */  sw    $zero, 0x38($a0)
/* 05F6C4 7F02AB94 AC800040 */  sw    $zero, 0x40($a0)
/* 05F6C8 7F02AB98 10000002 */  b     .L7F02ABA4
/* 05F6CC 7F02AB9C AC980034 */   sw    $t8, 0x34($a0)
.L7F02ABA0:
/* 05F6D0 7F02ABA0 00001025 */  move  $v0, $zero
.L7F02ABA4:
/* 05F6D4 7F02ABA4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 05F6D8 7F02ABA8 27BD0018 */  addiu $sp, $sp, 0x18
/* 05F6DC 7F02ABAC 03E00008 */  jr    $ra
/* 05F6E0 7F02ABB0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void actor_moves_to_preset_at_speed(void) {
// ai branch
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E6C
.word 0x3f8ccccd /*1.1*/
.text
glabel actor_moves_to_preset_at_speed
/* 05F6E4 7F02ABB4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 05F6E8 7F02ABB8 AFB10020 */  sw    $s1, 0x20($sp)
/* 05F6EC 7F02ABBC AFB0001C */  sw    $s0, 0x1c($sp)
/* 05F6F0 7F02ABC0 00A08025 */  move  $s0, $a1
/* 05F6F4 7F02ABC4 00808825 */  move  $s1, $a0
/* 05F6F8 7F02ABC8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 05F6FC 7F02ABCC 04A0005B */  bltz  $a1, .L7F02AD3C
/* 05F700 7F02ABD0 AFA60048 */   sw    $a2, 0x48($sp)
/* 05F704 7F02ABD4 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F708 7F02ABD8 00000000 */   nop   
/* 05F70C 7F02ABDC 10400057 */  beqz  $v0, .L7F02AD3C
/* 05F710 7F02ABE0 3C0E8003 */   lui   $t6, %hi(setting_007_5) 
/* 05F714 7F02ABE4 8DCECE50 */  lw    $t6, %lo(setting_007_5)($t6)
/* 05F718 7F02ABE8 02202025 */  move  $a0, $s1
/* 05F71C 7F02ABEC 29C1000A */  slti  $at, $t6, 0xa
/* 05F720 7F02ABF0 50200053 */  beql  $at, $zero, .L7F02AD40
/* 05F724 7F02ABF4 00001025 */   move  $v0, $zero
/* 05F728 7F02ABF8 0FC0CBE5 */  jal   convertPadIf9000
/* 05F72C 7F02ABFC 02002825 */   move  $a1, $s0
/* 05F730 7F02AC00 28412710 */  slti  $at, $v0, 0x2710
/* 05F734 7F02AC04 1020000A */  beqz  $at, .L7F02AC30
/* 05F738 7F02AC08 0002C900 */   sll   $t9, $v0, 4
/* 05F73C 7F02AC0C 00027880 */  sll   $t7, $v0, 2
/* 05F740 7F02AC10 01E27823 */  subu  $t7, $t7, $v0
/* 05F744 7F02AC14 000F7880 */  sll   $t7, $t7, 2
/* 05F748 7F02AC18 3C188007 */  lui   $t8, %hi(ptr_0xxxpresets) 
/* 05F74C 7F02AC1C 8F185D18 */  lw    $t8, %lo(ptr_0xxxpresets)($t8)
/* 05F750 7F02AC20 01E27823 */  subu  $t7, $t7, $v0
/* 05F754 7F02AC24 000F7880 */  sll   $t7, $t7, 2
/* 05F758 7F02AC28 10000009 */  b     .L7F02AC50
/* 05F75C 7F02AC2C 01F88021 */   addu  $s0, $t7, $t8
.L7F02AC30:
/* 05F760 7F02AC30 3C088007 */  lui   $t0, %hi(ptr_2xxxpresets) 
/* 05F764 7F02AC34 8D085D1C */  lw    $t0, %lo(ptr_2xxxpresets)($t0)
/* 05F768 7F02AC38 0322C821 */  addu  $t9, $t9, $v0
/* 05F76C 7F02AC3C 0019C880 */  sll   $t9, $t9, 2
/* 05F770 7F02AC40 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 05F774 7F02AC44 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 05F778 7F02AC48 03288021 */  addu  $s0, $t9, $t0
/* 05F77C 7F02AC4C 02018021 */  addu  $s0, $s0, $at
.L7F02AC50:
/* 05F780 7F02AC50 8E090028 */  lw    $t1, 0x28($s0)
/* 05F784 7F02AC54 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 05F788 7F02AC58 11200038 */  beqz  $t1, .L7F02AD3C
/* 05F78C 7F02AC5C AFA90028 */   sw    $t1, 0x28($sp)
/* 05F790 7F02AC60 C6040010 */  lwc1  $f4, 0x10($s0)
/* 05F794 7F02AC64 44813000 */  mtc1  $at, $f6
/* 05F798 7F02AC68 3C018005 */  lui   $at, %hi(D_80051E6C)
/* 05F79C 7F02AC6C 02202025 */  move  $a0, $s1
/* 05F7A0 7F02AC70 4606203C */  c.lt.s $f4, $f6
/* 05F7A4 7F02AC74 02002825 */  move  $a1, $s0
/* 05F7A8 7F02AC78 8FA60028 */  lw    $a2, 0x28($sp)
/* 05F7AC 7F02AC7C 45000029 */  bc1f  .L7F02AD24
/* 05F7B0 7F02AC80 00000000 */   nop   
/* 05F7B4 7F02AC84 AFA90038 */  sw    $t1, 0x38($sp)
/* 05F7B8 7F02AC88 C4201E6C */  lwc1  $f0, %lo(D_80051E6C)($at)
/* 05F7BC 7F02AC8C C62A0024 */  lwc1  $f10, 0x24($s1)
/* 05F7C0 7F02AC90 C608000C */  lwc1  $f8, 0xc($s0)
/* 05F7C4 7F02AC94 C6040000 */  lwc1  $f4, ($s0)
/* 05F7C8 7F02AC98 46005402 */  mul.s $f16, $f10, $f0
/* 05F7CC 7F02AC9C 27A40038 */  addiu $a0, $sp, 0x38
/* 05F7D0 7F02ACA0 46104482 */  mul.s $f18, $f8, $f16
/* 05F7D4 7F02ACA4 46049180 */  add.s $f6, $f18, $f4
/* 05F7D8 7F02ACA8 E7A6002C */  swc1  $f6, 0x2c($sp)
/* 05F7DC 7F02ACAC C6280024 */  lwc1  $f8, 0x24($s1)
/* 05F7E0 7F02ACB0 C60A0010 */  lwc1  $f10, 0x10($s0)
/* 05F7E4 7F02ACB4 C6040004 */  lwc1  $f4, 4($s0)
/* 05F7E8 7F02ACB8 46004402 */  mul.s $f16, $f8, $f0
/* 05F7EC 7F02ACBC 44073000 */  mfc1  $a3, $f6
/* 05F7F0 7F02ACC0 46105482 */  mul.s $f18, $f10, $f16
/* 05F7F4 7F02ACC4 46049200 */  add.s $f8, $f18, $f4
/* 05F7F8 7F02ACC8 E7A80030 */  swc1  $f8, 0x30($sp)
/* 05F7FC 7F02ACCC C6300024 */  lwc1  $f16, 0x24($s1)
/* 05F800 7F02ACD0 C60A0014 */  lwc1  $f10, 0x14($s0)
/* 05F804 7F02ACD4 C6080008 */  lwc1  $f8, 8($s0)
/* 05F808 7F02ACD8 46008482 */  mul.s $f18, $f16, $f0
/* 05F80C 7F02ACDC 00000000 */  nop   
/* 05F810 7F02ACE0 46125102 */  mul.s $f4, $f10, $f18
/* 05F814 7F02ACE4 46082400 */  add.s $f16, $f4, $f8
/* 05F818 7F02ACE8 E7B00034 */  swc1  $f16, 0x34($sp)
/* 05F81C 7F02ACEC 8E060008 */  lw    $a2, 8($s0)
/* 05F820 7F02ACF0 8E050000 */  lw    $a1, ($s0)
/* 05F824 7F02ACF4 0FC2C2F9 */  jal   walkTilesBetweenPoints_NoCallback
/* 05F828 7F02ACF8 E7B00010 */   swc1  $f16, 0x10($sp)
/* 05F82C 7F02ACFC 1040000F */  beqz  $v0, .L7F02AD3C
/* 05F830 7F02AD00 02202025 */   move  $a0, $s1
/* 05F834 7F02AD04 27A5002C */  addiu $a1, $sp, 0x2c
/* 05F838 7F02AD08 8FA60038 */  lw    $a2, 0x38($sp)
/* 05F83C 7F02AD0C 0FC0A377 */  jal   plot_course_for_actor
/* 05F840 7F02AD10 8FA70048 */   lw    $a3, 0x48($sp)
/* 05F844 7F02AD14 5040000A */  beql  $v0, $zero, .L7F02AD40
/* 05F848 7F02AD18 00001025 */   move  $v0, $zero
/* 05F84C 7F02AD1C 10000008 */  b     .L7F02AD40
/* 05F850 7F02AD20 24020001 */   li    $v0, 1
.L7F02AD24:
/* 05F854 7F02AD24 0FC0A377 */  jal   plot_course_for_actor
/* 05F858 7F02AD28 8FA70048 */   lw    $a3, 0x48($sp)
/* 05F85C 7F02AD2C 50400004 */  beql  $v0, $zero, .L7F02AD40
/* 05F860 7F02AD30 00001025 */   move  $v0, $zero
/* 05F864 7F02AD34 10000002 */  b     .L7F02AD40
/* 05F868 7F02AD38 24020001 */   li    $v0, 1
.L7F02AD3C:
/* 05F86C 7F02AD3C 00001025 */  move  $v0, $zero
.L7F02AD40:
/* 05F870 7F02AD40 8FBF0024 */  lw    $ra, 0x24($sp)
/* 05F874 7F02AD44 8FB0001C */  lw    $s0, 0x1c($sp)
/* 05F878 7F02AD48 8FB10020 */  lw    $s1, 0x20($sp)
/* 05F87C 7F02AD4C 03E00008 */  jr    $ra
/* 05F880 7F02AD50 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif



#ifdef NONMATCHING
void if_actor_able_set_on_path(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel if_actor_able_set_on_path
/* 05F884 7F02AD54 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 05F888 7F02AD58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05F88C 7F02AD5C 10A00009 */  beqz  $a1, .L7F02AD84
/* 05F890 7F02AD60 AFA40018 */   sw    $a0, 0x18($sp)
/* 05F894 7F02AD64 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 05F898 7F02AD68 AFA5001C */   sw    $a1, 0x1c($sp)
/* 05F89C 7F02AD6C 10400005 */  beqz  $v0, .L7F02AD84
/* 05F8A0 7F02AD70 8FA5001C */   lw    $a1, 0x1c($sp)
/* 05F8A4 7F02AD74 0FC0A43E */  jal   set_actor_on_path
/* 05F8A8 7F02AD78 8FA40018 */   lw    $a0, 0x18($sp)
/* 05F8AC 7F02AD7C 10000002 */  b     .L7F02AD88
/* 05F8B0 7F02AD80 24020001 */   li    $v0, 1
.L7F02AD84:
/* 05F8B4 7F02AD84 00001025 */  move  $v0, $zero
.L7F02AD88:
/* 05F8B8 7F02AD88 8FBF0014 */  lw    $ra, 0x14($sp)
/* 05F8BC 7F02AD8C 27BD0018 */  addiu $sp, $sp, 0x18
/* 05F8C0 7F02AD90 03E00008 */  jr    $ra
/* 05F8C4 7F02AD94 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02AD98(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E70
.word 0x3eb2b8c3 /*0.34906587*/
glabel D_80051E74
.word 0x40bde44f /*5.9341197*/
glabel D_80051E78
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E7C
.word 0x3f490fdb /*0.78539819*/
glabel D_80051E80
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E84
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E88
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E8C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02AD98
/* 05F8C8 7F02AD98 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 05F8CC 7F02AD9C AFBF0024 */  sw    $ra, 0x24($sp)
/* 05F8D0 7F02ADA0 AFB00020 */  sw    $s0, 0x20($sp)
/* 05F8D4 7F02ADA4 808E0008 */  lb    $t6, 8($a0)
/* 05F8D8 7F02ADA8 00808025 */  move  $s0, $a0
/* 05F8DC 7F02ADAC 5DC001C8 */  bgtzl $t6, .L7F02B4D0
/* 05F8E0 7F02ADB0 8FBF0024 */   lw    $ra, 0x24($sp)
/* 05F8E4 7F02ADB4 8C8F002C */  lw    $t7, 0x2c($a0)
/* 05F8E8 7F02ADB8 51E00012 */  beql  $t7, $zero, .L7F02AE04
/* 05F8EC 7F02ADBC 8E050030 */   lw    $a1, 0x30($s0)
/* 05F8F0 7F02ADC0 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 05F8F4 7F02ADC4 8C84001C */   lw    $a0, 0x1c($a0)
/* 05F8F8 7F02ADC8 E7A0003C */  swc1  $f0, 0x3c($sp)
/* 05F8FC 7F02ADCC 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 05F900 7F02ADD0 8E04001C */   lw    $a0, 0x1c($s0)
/* 05F904 7F02ADD4 C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 05F908 7F02ADD8 02002025 */  move  $a0, $s0
/* 05F90C 7F02ADDC 4604003E */  c.le.s $f0, $f4
/* 05F910 7F02ADE0 00000000 */  nop   
/* 05F914 7F02ADE4 45000004 */  bc1f  .L7F02ADF8
/* 05F918 7F02ADE8 00000000 */   nop   
/* 05F91C 7F02ADEC 0FC08E52 */  jal   chrlvIdleAnimationRelated
/* 05F920 7F02ADF0 3C054100 */   lui   $a1, 0x4100
/* 05F924 7F02ADF4 AE00002C */  sw    $zero, 0x2c($s0)
.L7F02ADF8:
/* 05F928 7F02ADF8 100001B4 */  b     .L7F02B4CC
/* 05F92C 7F02ADFC A2000008 */   sb    $zero, 8($s0)
/* 05F930 7F02AE00 8E050030 */  lw    $a1, 0x30($s0)
.L7F02AE04:
/* 05F934 7F02AE04 18A00095 */  blez  $a1, .L7F02B05C
/* 05F938 7F02AE08 00000000 */   nop   
/* 05F93C 7F02AE0C 8E180038 */  lw    $t8, 0x38($s0)
/* 05F940 7F02AE10 02002025 */  move  $a0, $s0
/* 05F944 7F02AE14 1300001C */  beqz  $t8, .L7F02AE88
/* 05F948 7F02AE18 00000000 */   nop   
/* 05F94C 7F02AE1C 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 05F950 7F02AE20 8E04001C */   lw    $a0, 0x1c($s0)
/* 05F954 7F02AE24 94590004 */  lhu   $t9, 4($v0)
/* 05F958 7F02AE28 44804000 */  mtc1  $zero, $f8
/* 05F95C 7F02AE2C 8E05003C */  lw    $a1, 0x3c($s0)
/* 05F960 7F02AE30 272CFFFF */  addiu $t4, $t9, -1
/* 05F964 7F02AE34 448C3000 */  mtc1  $t4, $f6
/* 05F968 7F02AE38 02002025 */  move  $a0, $s0
/* 05F96C 7F02AE3C 3C073F80 */  lui   $a3, 0x3f80
/* 05F970 7F02AE40 46803020 */  cvt.s.w $f0, $f6
/* 05F974 7F02AE44 E7A80010 */  swc1  $f8, 0x10($sp)
/* 05F978 7F02AE48 44060000 */  mfc1  $a2, $f0
/* 05F97C 7F02AE4C 0FC0B0AC */  jal   sub_GAME_7F02C2B0
/* 05F980 7F02AE50 00000000 */   nop   
/* 05F984 7F02AE54 24030001 */  li    $v1, 1
/* 05F988 7F02AE58 1043007E */  beq   $v0, $v1, .L7F02B054
/* 05F98C 7F02AE5C AE02003C */   sw    $v0, 0x3c($s0)
/* 05F990 7F02AE60 02002025 */  move  $a0, $s0
/* 05F994 7F02AE64 0FC08E52 */  jal   chrlvIdleAnimationRelated
/* 05F998 7F02AE68 3C054100 */   lui   $a1, 0x4100
/* 05F99C 7F02AE6C 8E0D0030 */  lw    $t5, 0x30($s0)
/* 05F9A0 7F02AE70 AE000038 */  sw    $zero, 0x38($s0)
/* 05F9A4 7F02AE74 31AE0010 */  andi  $t6, $t5, 0x10
/* 05F9A8 7F02AE78 11C00076 */  beqz  $t6, .L7F02B054
/* 05F9AC 7F02AE7C 00000000 */   nop   
/* 05F9B0 7F02AE80 10000074 */  b     .L7F02B054
/* 05F9B4 7F02AE84 AE000030 */   sw    $zero, 0x30($s0)
.L7F02AE88:
/* 05F9B8 7F02AE88 0FC0942F */  jal   chrlvDistanceToChrRelated
/* 05F9BC 7F02AE8C 8E060034 */   lw    $a2, 0x34($s0)
/* 05F9C0 7F02AE90 3C018005 */  lui   $at, %hi(D_80051E70)
/* 05F9C4 7F02AE94 C42A1E70 */  lwc1  $f10, %lo(D_80051E70)($at)
/* 05F9C8 7F02AE98 3C018005 */  lui   $at, %hi(D_80051E74)
/* 05F9CC 7F02AE9C 4600503C */  c.lt.s $f10, $f0
/* 05F9D0 7F02AEA0 00000000 */  nop   
/* 05F9D4 7F02AEA4 45020067 */  bc1fl .L7F02B044
/* 05F9D8 7F02AEA8 8E180030 */   lw    $t8, 0x30($s0)
/* 05F9DC 7F02AEAC C4301E74 */  lwc1  $f16, %lo(D_80051E74)($at)
/* 05F9E0 7F02AEB0 02002025 */  move  $a0, $s0
/* 05F9E4 7F02AEB4 4610003C */  c.lt.s $f0, $f16
/* 05F9E8 7F02AEB8 00000000 */  nop   
/* 05F9EC 7F02AEBC 45020061 */  bc1fl .L7F02B044
/* 05F9F0 7F02AEC0 8E180030 */   lw    $t8, 0x30($s0)
/* 05F9F4 7F02AEC4 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05F9F8 7F02AEC8 24050001 */   li    $a1, 1
/* 05F9FC 7F02AECC AFA200A0 */  sw    $v0, 0xa0($sp)
/* 05FA00 7F02AED0 02002025 */  move  $a0, $s0
/* 05FA04 7F02AED4 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 05FA08 7F02AED8 00002825 */   move  $a1, $zero
/* 05FA0C 7F02AEDC 8FA400A0 */  lw    $a0, 0xa0($sp)
/* 05FA10 7F02AEE0 24030001 */  li    $v1, 1
/* 05FA14 7F02AEE4 AFA2009C */  sw    $v0, 0x9c($sp)
/* 05FA18 7F02AEE8 AE030038 */  sw    $v1, 0x38($s0)
/* 05FA1C 7F02AEEC 10800003 */  beqz  $a0, .L7F02AEFC
/* 05FA20 7F02AEF0 AE03003C */   sw    $v1, 0x3c($s0)
/* 05FA24 7F02AEF4 1440000D */  bnez  $v0, .L7F02AF2C
/* 05FA28 7F02AEF8 00000000 */   nop   
.L7F02AEFC:
/* 05FA2C 7F02AEFC 14800003 */  bnez  $a0, .L7F02AF0C
/* 05FA30 7F02AF00 00000000 */   nop   
/* 05FA34 7F02AF04 10400009 */  beqz  $v0, .L7F02AF2C
/* 05FA38 7F02AF08 00000000 */   nop   
.L7F02AF0C:
/* 05FA3C 7F02AF0C 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05FA40 7F02AF10 00000000 */   nop   
/* 05FA44 7F02AF14 14400005 */  bnez  $v0, .L7F02AF2C
/* 05FA48 7F02AF18 00000000 */   nop   
/* 05FA4C 7F02AF1C 0FC08E44 */  jal   check_if_item_held_like_pistol
/* 05FA50 7F02AF20 8FA4009C */   lw    $a0, 0x9c($sp)
/* 05FA54 7F02AF24 10400022 */  beqz  $v0, .L7F02AFB0
/* 05FA58 7F02AF28 8FAE009C */   lw    $t6, 0x9c($sp)
.L7F02AF2C:
/* 05FA5C 7F02AF2C 0C002914 */  jal   randomGetNext
/* 05FA60 7F02AF30 00000000 */   nop   
/* 05FA64 7F02AF34 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 05FA68 7F02AF38 44819000 */  mtc1  $at, $f18
/* 05FA6C 7F02AF3C 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 05FA70 7F02AF40 3C0F8007 */  lui   $t7, %hi(ptr_animation_table) 
/* 05FA74 7F02AF44 8DEF9538 */  lw    $t7, %lo(ptr_animation_table)($t7)
/* 05FA78 7F02AF48 44812000 */  mtc1  $at, $f4
/* 05FA7C 7F02AF4C 8E04001C */  lw    $a0, 0x1c($s0)
/* 05FA80 7F02AF50 3C030001 */  lui   $v1, %hi(0x00008204) # $v1, 1
/* 05FA84 7F02AF54 24638204 */  addiu $v1, %lo(0x00008204) # addiu $v1, $v1, -0x7dfc
/* 05FA88 7F02AF58 AFA30034 */  sw    $v1, 0x34($sp)
/* 05FA8C 7F02AF5C 30460001 */  andi  $a2, $v0, 1
/* 05FA90 7F02AF60 24070000 */  li    $a3, 0
/* 05FA94 7F02AF64 E7B20010 */  swc1  $f18, 0x10($sp)
/* 05FA98 7F02AF68 006F2821 */  addu  $a1, $v1, $t7
/* 05FA9C 7F02AF6C 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 05FAA0 7F02AF70 E7A40014 */   swc1  $f4, 0x14($sp)
/* 05FAA4 7F02AF74 3C188007 */  lui   $t8, %hi(ptr_animation_table) 
/* 05FAA8 7F02AF78 8FA30034 */  lw    $v1, 0x34($sp)
/* 05FAAC 7F02AF7C 8F189538 */  lw    $t8, %lo(ptr_animation_table)($t8)
/* 05FAB0 7F02AF80 8E04001C */  lw    $a0, 0x1c($s0)
/* 05FAB4 7F02AF84 0078C821 */  addu  $t9, $v1, $t8
/* 05FAB8 7F02AF88 972C0004 */  lhu   $t4, 4($t9)
/* 05FABC 7F02AF8C 258DFFFF */  addiu $t5, $t4, -1
/* 05FAC0 7F02AF90 448D3000 */  mtc1  $t5, $f6
/* 05FAC4 7F02AF94 00000000 */  nop   
/* 05FAC8 7F02AF98 468031A0 */  cvt.s.w $f6, $f6
/* 05FACC 7F02AF9C 44053000 */  mfc1  $a1, $f6
/* 05FAD0 7F02AFA0 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 05FAD4 7F02AFA4 00000000 */   nop   
/* 05FAD8 7F02AFA8 1000002A */  b     .L7F02B054
/* 05FADC 7F02AFAC 00000000 */   nop   
.L7F02AFB0:
/* 05FAE0 7F02AFB0 15C00002 */  bnez  $t6, .L7F02AFBC
/* 05FAE4 7F02AFB4 8FAF00A0 */   lw    $t7, 0xa0($sp)
/* 05FAE8 7F02AFB8 11E00026 */  beqz  $t7, .L7F02B054
.L7F02AFBC:
/* 05FAEC 7F02AFBC 3C013F00 */   li    $at, 0x3F000000 # 0.500000
/* 05FAF0 7F02AFC0 44814000 */  mtc1  $at, $f8
/* 05FAF4 7F02AFC4 8FA600A0 */  lw    $a2, 0xa0($sp)
/* 05FAF8 7F02AFC8 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 05FAFC 7F02AFCC 3C188007 */  lui   $t8, %hi(ptr_animation_table) 
/* 05FB00 7F02AFD0 8F189538 */  lw    $t8, %lo(ptr_animation_table)($t8)
/* 05FB04 7F02AFD4 44815000 */  mtc1  $at, $f10
/* 05FB08 7F02AFD8 8E04001C */  lw    $a0, 0x1c($s0)
/* 05FB0C 7F02AFDC 3C020000 */  lui   $v0, %hi(0x00004018) # $v0, 0
/* 05FB10 7F02AFE0 24424018 */  addiu $v0, %lo(0x00004018) # addiu $v0, $v0, 0x4018
/* 05FB14 7F02AFE4 0006C82B */  sltu  $t9, $zero, $a2
/* 05FB18 7F02AFE8 03203025 */  move  $a2, $t9
/* 05FB1C 7F02AFEC AFA20034 */  sw    $v0, 0x34($sp)
/* 05FB20 7F02AFF0 24070000 */  li    $a3, 0
/* 05FB24 7F02AFF4 E7A80010 */  swc1  $f8, 0x10($sp)
/* 05FB28 7F02AFF8 00582821 */  addu  $a1, $v0, $t8
/* 05FB2C 7F02AFFC 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 05FB30 7F02B000 E7AA0014 */   swc1  $f10, 0x14($sp)
/* 05FB34 7F02B004 3C0C8007 */  lui   $t4, %hi(ptr_animation_table) 
/* 05FB38 7F02B008 8FA20034 */  lw    $v0, 0x34($sp)
/* 05FB3C 7F02B00C 8D8C9538 */  lw    $t4, %lo(ptr_animation_table)($t4)
/* 05FB40 7F02B010 8E04001C */  lw    $a0, 0x1c($s0)
/* 05FB44 7F02B014 004C6821 */  addu  $t5, $v0, $t4
/* 05FB48 7F02B018 95AE0004 */  lhu   $t6, 4($t5)
/* 05FB4C 7F02B01C 25CFFFFF */  addiu $t7, $t6, -1
/* 05FB50 7F02B020 448F8000 */  mtc1  $t7, $f16
/* 05FB54 7F02B024 00000000 */  nop   
/* 05FB58 7F02B028 46808420 */  cvt.s.w $f16, $f16
/* 05FB5C 7F02B02C 44058000 */  mfc1  $a1, $f16
/* 05FB60 7F02B030 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 05FB64 7F02B034 00000000 */   nop   
/* 05FB68 7F02B038 10000006 */  b     .L7F02B054
/* 05FB6C 7F02B03C 00000000 */   nop   
/* 05FB70 7F02B040 8E180030 */  lw    $t8, 0x30($s0)
.L7F02B044:
/* 05FB74 7F02B044 33190010 */  andi  $t9, $t8, 0x10
/* 05FB78 7F02B048 13200002 */  beqz  $t9, .L7F02B054
/* 05FB7C 7F02B04C 00000000 */   nop   
/* 05FB80 7F02B050 AE000030 */  sw    $zero, 0x30($s0)
.L7F02B054:
/* 05FB84 7F02B054 1000011D */  b     .L7F02B4CC
/* 05FB88 7F02B058 A2000008 */   sb    $zero, 8($s0)
.L7F02B05C:
/* 05FB8C 7F02B05C 0C002914 */  jal   randomGetNext
/* 05FB90 7F02B060 00000000 */   nop   
/* 05FB94 7F02B064 24010005 */  li    $at, 5
/* 05FB98 7F02B068 0041001B */  divu  $zero, $v0, $at
/* 05FB9C 7F02B06C 8E0E0040 */  lw    $t6, 0x40($s0)
/* 05FBA0 7F02B070 00006010 */  mfhi  $t4
/* 05FBA4 7F02B074 258D000E */  addiu $t5, $t4, 0xe
/* 05FBA8 7F02B078 11C00114 */  beqz  $t6, .L7F02B4CC
/* 05FBAC 7F02B07C A20D0008 */   sb    $t5, 8($s0)
/* 05FBB0 7F02B080 8E0F0014 */  lw    $t7, 0x14($s0)
/* 05FBB4 7F02B084 31F80080 */  andi  $t8, $t7, 0x80
/* 05FBB8 7F02B088 53000004 */  beql  $t8, $zero, .L7F02B09C
/* 05FBBC 7F02B08C 8E190044 */   lw    $t9, 0x44($s0)
/* 05FBC0 7F02B090 1000010E */  b     .L7F02B4CC
/* 05FBC4 7F02B094 AE000040 */   sw    $zero, 0x40($s0)
/* 05FBC8 7F02B098 8E190044 */  lw    $t9, 0x44($s0)
.L7F02B09C:
/* 05FBCC 7F02B09C 820C0008 */  lb    $t4, 8($s0)
/* 05FBD0 7F02B0A0 032C6823 */  subu  $t5, $t9, $t4
/* 05FBD4 7F02B0A4 05A10109 */  bgez  $t5, .L7F02B4CC
/* 05FBD8 7F02B0A8 AE0D0044 */   sw    $t5, 0x44($s0)
/* 05FBDC 7F02B0AC 0FC1B320 */  jal   getsubroty
/* 05FBE0 7F02B0B0 8E04001C */   lw    $a0, 0x1c($s0)
/* 05FBE4 7F02B0B4 3C018005 */  lui   $at, %hi(D_80051E78)
/* 05FBE8 7F02B0B8 E7A00070 */  swc1  $f0, 0x70($sp)
/* 05FBEC 7F02B0BC 46000086 */  mov.s $f2, $f0
/* 05FBF0 7F02B0C0 C42C1E78 */  lwc1  $f12, %lo(D_80051E78)($at)
/* 05FBF4 7F02B0C4 27A20074 */  addiu $v0, $sp, 0x74
.L7F02B0C8:
/* 05FBF8 7F02B0C8 3C018005 */  lui   $at, %hi(D_80051E7C)
/* 05FBFC 7F02B0CC C4321E7C */  lwc1  $f18, %lo(D_80051E7C)($at)
/* 05FC00 7F02B0D0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 05FC04 7F02B0D4 44813000 */  mtc1  $at, $f6
/* 05FC08 7F02B0D8 46121080 */  add.s $f2, $f2, $f18
/* 05FC0C 7F02B0DC 44802000 */  mtc1  $zero, $f4
/* 05FC10 7F02B0E0 3C06447A */  lui   $a2, %hi(0x447A0001) # $a2, 0x447a
/* 05FC14 7F02B0E4 00003825 */  move  $a3, $zero
/* 05FC18 7F02B0E8 4602603E */  c.le.s $f12, $f2
/* 05FC1C 7F02B0EC 00000000 */  nop   
/* 05FC20 7F02B0F0 45020003 */  bc1fl .L7F02B100
/* 05FC24 7F02B0F4 8E040018 */   lw    $a0, 0x18($s0)
/* 05FC28 7F02B0F8 460C1081 */  sub.s $f2, $f2, $f12
/* 05FC2C 7F02B0FC 8E040018 */  lw    $a0, 0x18($s0)
.L7F02B100:
/* 05FC30 7F02B100 44051000 */  mfc1  $a1, $f2
/* 05FC34 7F02B104 E7A2006C */  swc1  $f2, 0x6c($sp)
/* 05FC38 7F02B108 AFA20034 */  sw    $v0, 0x34($sp)
/* 05FC3C 7F02B10C E7A60014 */  swc1  $f6, 0x14($sp)
/* 05FC40 7F02B110 0FC098D9 */  jal   chrlvPathingCollisionRelated
/* 05FC44 7F02B114 E7A40010 */   swc1  $f4, 0x10($sp)
/* 05FC48 7F02B118 8FA20034 */  lw    $v0, 0x34($sp)
/* 05FC4C 7F02B11C 3C018005 */  lui   $at, %hi(D_80051E80)
/* 05FC50 7F02B120 27AF0094 */  addiu $t7, $sp, 0x94
/* 05FC54 7F02B124 C42C1E80 */  lwc1  $f12, %lo(D_80051E80)($at)
/* 05FC58 7F02B128 24420004 */  addiu $v0, $v0, 4
/* 05FC5C 7F02B12C 004F082B */  sltu  $at, $v0, $t7
/* 05FC60 7F02B130 C7A2006C */  lwc1  $f2, 0x6c($sp)
/* 05FC64 7F02B134 1420FFE4 */  bnez  $at, .L7F02B0C8
/* 05FC68 7F02B138 E440FFFC */   swc1  $f0, -4($v0)
/* 05FC6C 7F02B13C 00003025 */  move  $a2, $zero
/* 05FC70 7F02B140 27AA0044 */  addiu $t2, $sp, 0x44
.L7F02B144:
/* 05FC74 7F02B144 AD460000 */  sw    $a2, ($t2)
/* 05FC78 7F02B148 24C60001 */  addiu $a2, %lo(0x447A0001) # addiu $a2, $a2, 1
/* 05FC7C 7F02B14C 28C10008 */  slti  $at, $a2, 8
/* 05FC80 7F02B150 1420FFFC */  bnez  $at, .L7F02B144
/* 05FC84 7F02B154 254A0004 */   addiu $t2, $t2, 4
/* 05FC88 7F02B158 00003025 */  move  $a2, $zero
/* 05FC8C 7F02B15C 27AA0044 */  addiu $t2, $sp, 0x44
/* 05FC90 7F02B160 27A80044 */  addiu $t0, $sp, 0x44
/* 05FC94 7F02B164 24070008 */  li    $a3, 8
/* 05FC98 7F02B168 27A40074 */  addiu $a0, $sp, 0x74
.L7F02B16C:
/* 05FC9C 7F02B16C 24CB0001 */  addiu $t3, $a2, 1
/* 05FCA0 7F02B170 29610008 */  slti  $at, $t3, 8
/* 05FCA4 7F02B174 00C02825 */  move  $a1, $a2
/* 05FCA8 7F02B178 1020005B */  beqz  $at, .L7F02B2E8
/* 05FCAC 7F02B17C 01601025 */   move  $v0, $t3
/* 05FCB0 7F02B180 00EB4823 */  subu  $t1, $a3, $t3
/* 05FCB4 7F02B184 31380003 */  andi  $t8, $t1, 3
/* 05FCB8 7F02B188 13000016 */  beqz  $t8, .L7F02B1E4
/* 05FCBC 7F02B18C 030B3021 */   addu  $a2, $t8, $t3
/* 05FCC0 7F02B190 0002C880 */  sll   $t9, $v0, 2
/* 05FCC4 7F02B194 01191821 */  addu  $v1, $t0, $t9
.L7F02B198:
/* 05FCC8 7F02B198 8C6C0000 */  lw    $t4, ($v1)
/* 05FCCC 7F02B19C 00057880 */  sll   $t7, $a1, 2
/* 05FCD0 7F02B1A0 010FC021 */  addu  $t8, $t0, $t7
/* 05FCD4 7F02B1A4 8F190000 */  lw    $t9, ($t8)
/* 05FCD8 7F02B1A8 000C6880 */  sll   $t5, $t4, 2
/* 05FCDC 7F02B1AC 008D7021 */  addu  $t6, $a0, $t5
/* 05FCE0 7F02B1B0 00196080 */  sll   $t4, $t9, 2
/* 05FCE4 7F02B1B4 008C6821 */  addu  $t5, $a0, $t4
/* 05FCE8 7F02B1B8 C5AA0000 */  lwc1  $f10, ($t5)
/* 05FCEC 7F02B1BC C5C80000 */  lwc1  $f8, ($t6)
/* 05FCF0 7F02B1C0 460A403C */  c.lt.s $f8, $f10
/* 05FCF4 7F02B1C4 00000000 */  nop   
/* 05FCF8 7F02B1C8 45020003 */  bc1fl .L7F02B1D8
/* 05FCFC 7F02B1CC 24420001 */   addiu $v0, $v0, 1
/* 05FD00 7F02B1D0 00402825 */  move  $a1, $v0
/* 05FD04 7F02B1D4 24420001 */  addiu $v0, $v0, 1
.L7F02B1D8:
/* 05FD08 7F02B1D8 14C2FFEF */  bne   $a2, $v0, .L7F02B198
/* 05FD0C 7F02B1DC 24630004 */   addiu $v1, $v1, 4
/* 05FD10 7F02B1E0 10470041 */  beq   $v0, $a3, .L7F02B2E8
.L7F02B1E4:
/* 05FD14 7F02B1E4 00027080 */   sll   $t6, $v0, 2
/* 05FD18 7F02B1E8 010E1821 */  addu  $v1, $t0, $t6
.L7F02B1EC:
/* 05FD1C 7F02B1EC 00057880 */  sll   $t7, $a1, 2
/* 05FD20 7F02B1F0 010FC021 */  addu  $t8, $t0, $t7
/* 05FD24 7F02B1F4 8F190000 */  lw    $t9, ($t8)
/* 05FD28 7F02B1F8 8C6E0000 */  lw    $t6, ($v1)
/* 05FD2C 7F02B1FC 00196080 */  sll   $t4, $t9, 2
/* 05FD30 7F02B200 000E7880 */  sll   $t7, $t6, 2
/* 05FD34 7F02B204 008FC021 */  addu  $t8, $a0, $t7
/* 05FD38 7F02B208 008C6821 */  addu  $t5, $a0, $t4
/* 05FD3C 7F02B20C C5A00000 */  lwc1  $f0, ($t5)
/* 05FD40 7F02B210 C7100000 */  lwc1  $f16, ($t8)
/* 05FD44 7F02B214 0002C880 */  sll   $t9, $v0, 2
/* 05FD48 7F02B218 01196021 */  addu  $t4, $t0, $t9
/* 05FD4C 7F02B21C 4600803C */  c.lt.s $f16, $f0
/* 05FD50 7F02B220 00000000 */  nop   
/* 05FD54 7F02B224 45020007 */  bc1fl .L7F02B244
/* 05FD58 7F02B228 8C780004 */   lw    $t8, 4($v1)
/* 05FD5C 7F02B22C 8D8D0000 */  lw    $t5, ($t4)
/* 05FD60 7F02B230 00402825 */  move  $a1, $v0
/* 05FD64 7F02B234 000D7080 */  sll   $t6, $t5, 2
/* 05FD68 7F02B238 008E7821 */  addu  $t7, $a0, $t6
/* 05FD6C 7F02B23C C5E00000 */  lwc1  $f0, ($t7)
/* 05FD70 7F02B240 8C780004 */  lw    $t8, 4($v1)
.L7F02B244:
/* 05FD74 7F02B244 0018C880 */  sll   $t9, $t8, 2
/* 05FD78 7F02B248 00996021 */  addu  $t4, $a0, $t9
/* 05FD7C 7F02B24C C5920000 */  lwc1  $f18, ($t4)
/* 05FD80 7F02B250 4600903C */  c.lt.s $f18, $f0
/* 05FD84 7F02B254 00000000 */  nop   
/* 05FD88 7F02B258 45020009 */  bc1fl .L7F02B280
/* 05FD8C 7F02B25C 8C6C0008 */   lw    $t4, 8($v1)
/* 05FD90 7F02B260 24450001 */  addiu $a1, $v0, 1
/* 05FD94 7F02B264 00056880 */  sll   $t5, $a1, 2
/* 05FD98 7F02B268 010D7021 */  addu  $t6, $t0, $t5
/* 05FD9C 7F02B26C 8DCF0000 */  lw    $t7, ($t6)
/* 05FDA0 7F02B270 000FC080 */  sll   $t8, $t7, 2
/* 05FDA4 7F02B274 0098C821 */  addu  $t9, $a0, $t8
/* 05FDA8 7F02B278 C7200000 */  lwc1  $f0, ($t9)
/* 05FDAC 7F02B27C 8C6C0008 */  lw    $t4, 8($v1)
.L7F02B280:
/* 05FDB0 7F02B280 000C6880 */  sll   $t5, $t4, 2
/* 05FDB4 7F02B284 008D7021 */  addu  $t6, $a0, $t5
/* 05FDB8 7F02B288 C5C40000 */  lwc1  $f4, ($t6)
/* 05FDBC 7F02B28C 4600203C */  c.lt.s $f4, $f0
/* 05FDC0 7F02B290 00000000 */  nop   
/* 05FDC4 7F02B294 45020009 */  bc1fl .L7F02B2BC
/* 05FDC8 7F02B298 8C6E000C */   lw    $t6, 0xc($v1)
/* 05FDCC 7F02B29C 24450002 */  addiu $a1, $v0, 2
/* 05FDD0 7F02B2A0 00057880 */  sll   $t7, $a1, 2
/* 05FDD4 7F02B2A4 010FC021 */  addu  $t8, $t0, $t7
/* 05FDD8 7F02B2A8 8F190000 */  lw    $t9, ($t8)
/* 05FDDC 7F02B2AC 00196080 */  sll   $t4, $t9, 2
/* 05FDE0 7F02B2B0 008C6821 */  addu  $t5, $a0, $t4
/* 05FDE4 7F02B2B4 C5A00000 */  lwc1  $f0, ($t5)
/* 05FDE8 7F02B2B8 8C6E000C */  lw    $t6, 0xc($v1)
.L7F02B2BC:
/* 05FDEC 7F02B2BC 000E7880 */  sll   $t7, $t6, 2
/* 05FDF0 7F02B2C0 008FC021 */  addu  $t8, $a0, $t7
/* 05FDF4 7F02B2C4 C7060000 */  lwc1  $f6, ($t8)
/* 05FDF8 7F02B2C8 4600303C */  c.lt.s $f6, $f0
/* 05FDFC 7F02B2CC 00000000 */  nop   
/* 05FE00 7F02B2D0 45020003 */  bc1fl .L7F02B2E0
/* 05FE04 7F02B2D4 24420004 */   addiu $v0, $v0, 4
/* 05FE08 7F02B2D8 24450003 */  addiu $a1, $v0, 3
/* 05FE0C 7F02B2DC 24420004 */  addiu $v0, $v0, 4
.L7F02B2E0:
/* 05FE10 7F02B2E0 1447FFC2 */  bne   $v0, $a3, .L7F02B1EC
/* 05FE14 7F02B2E4 24630010 */   addiu $v1, $v1, 0x10
.L7F02B2E8:
/* 05FE18 7F02B2E8 0005C880 */  sll   $t9, $a1, 2
/* 05FE1C 7F02B2EC 01191821 */  addu  $v1, $t0, $t9
/* 05FE20 7F02B2F0 8C6C0000 */  lw    $t4, ($v1)
/* 05FE24 7F02B2F4 8D420000 */  lw    $v0, ($t2)
/* 05FE28 7F02B2F8 29610007 */  slti  $at, $t3, 7
/* 05FE2C 7F02B2FC AD4C0000 */  sw    $t4, ($t2)
/* 05FE30 7F02B300 01603025 */  move  $a2, $t3
/* 05FE34 7F02B304 254A0004 */  addiu $t2, $t2, 4
/* 05FE38 7F02B308 1420FF98 */  bnez  $at, .L7F02B16C
/* 05FE3C 7F02B30C AC620000 */   sw    $v0, ($v1)
/* 05FE40 7F02B310 3C0143F5 */  li    $at, 0x43F50000 # 490.000000
/* 05FE44 7F02B314 44815000 */  mtc1  $at, $f10
/* 05FE48 7F02B318 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 05FE4C 7F02B31C 8FA60054 */  lw    $a2, 0x54($sp)
/* 05FE50 7F02B320 2405FFFF */  li    $a1, -1
/* 05FE54 7F02B324 460A403C */  c.lt.s $f8, $f10
/* 05FE58 7F02B328 00066880 */  sll   $t5, $a2, 2
/* 05FE5C 7F02B32C 008D7021 */  addu  $t6, $a0, $t5
/* 05FE60 7F02B330 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 05FE64 7F02B334 45000046 */  bc1f  .L7F02B450
/* 05FE68 7F02B338 00000000 */   nop   
/* 05FE6C 7F02B33C C5D00000 */  lwc1  $f16, ($t6)
/* 05FE70 7F02B340 44819000 */  mtc1  $at, $f18
/* 05FE74 7F02B344 8FA20044 */  lw    $v0, 0x44($sp)
/* 05FE78 7F02B348 4612803C */  c.lt.s $f16, $f18
/* 05FE7C 7F02B34C 00000000 */  nop   
/* 05FE80 7F02B350 45000003 */  bc1f  .L7F02B360
/* 05FE84 7F02B354 00000000 */   nop   
/* 05FE88 7F02B358 1000003D */  b     .L7F02B450
/* 05FE8C 7F02B35C 24050007 */   li    $a1, 7
.L7F02B360:
/* 05FE90 7F02B360 10400005 */  beqz  $v0, .L7F02B378
/* 05FE94 7F02B364 8FAF0048 */   lw    $t7, 0x48($sp)
/* 05FE98 7F02B368 11E00003 */  beqz  $t7, .L7F02B378
/* 05FE9C 7F02B36C 8FB8004C */   lw    $t8, 0x4c($sp)
/* 05FEA0 7F02B370 17000022 */  bnez  $t8, .L7F02B3FC
/* 05FEA4 7F02B374 24030001 */   li    $v1, 1
.L7F02B378:
/* 05FEA8 7F02B378 8FB90050 */  lw    $t9, 0x50($sp)
/* 05FEAC 7F02B37C 24030004 */  li    $v1, 4
/* 05FEB0 7F02B380 10790003 */  beq   $v1, $t9, .L7F02B390
/* 05FEB4 7F02B384 00000000 */   nop   
/* 05FEB8 7F02B388 14660012 */  bne   $v1, $a2, .L7F02B3D4
/* 05FEBC 7F02B38C 00000000 */   nop   
.L7F02B390:
/* 05FEC0 7F02B390 0C002914 */  jal   randomGetNext
/* 05FEC4 7F02B394 00000000 */   nop   
/* 05FEC8 7F02B398 3C018005 */  lui   $at, %hi(D_80051E84)
/* 05FECC 7F02B39C C42C1E84 */  lwc1  $f12, %lo(D_80051E84)($at)
/* 05FED0 7F02B3A0 24010003 */  li    $at, 3
/* 05FED4 7F02B3A4 0041001B */  divu  $zero, $v0, $at
/* 05FED8 7F02B3A8 00006010 */  mfhi  $t4
/* 05FEDC 7F02B3AC 24030004 */  li    $v1, 4
/* 05FEE0 7F02B3B0 15800008 */  bnez  $t4, .L7F02B3D4
/* 05FEE4 7F02B3B4 27A80044 */   addiu $t0, $sp, 0x44
/* 05FEE8 7F02B3B8 8FAD0050 */  lw    $t5, 0x50($sp)
/* 05FEEC 7F02B3BC 146D0003 */  bne   $v1, $t5, .L7F02B3CC
/* 05FEF0 7F02B3C0 00000000 */   nop   
/* 05FEF4 7F02B3C4 10000022 */  b     .L7F02B450
/* 05FEF8 7F02B3C8 24050003 */   li    $a1, 3
.L7F02B3CC:
/* 05FEFC 7F02B3CC 10000020 */  b     .L7F02B450
/* 05FF00 7F02B3D0 24050004 */   li    $a1, 4
.L7F02B3D4:
/* 05FF04 7F02B3D4 0C002914 */  jal   randomGetNext
/* 05FF08 7F02B3D8 00000000 */   nop   
/* 05FF0C 7F02B3DC 3C018005 */  lui   $at, %hi(D_80051E88)
/* 05FF10 7F02B3E0 C42C1E88 */  lwc1  $f12, %lo(D_80051E88)($at)
/* 05FF14 7F02B3E4 24010003 */  li    $at, 3
/* 05FF18 7F02B3E8 0041001B */  divu  $zero, $v0, $at
/* 05FF1C 7F02B3EC 00002810 */  mfhi  $a1
/* 05FF20 7F02B3F0 24A50005 */  addiu $a1, $a1, 5
/* 05FF24 7F02B3F4 10000016 */  b     .L7F02B450
/* 05FF28 7F02B3F8 27A80044 */   addiu $t0, $sp, 0x44
.L7F02B3FC:
/* 05FF2C 7F02B3FC 10620003 */  beq   $v1, $v0, .L7F02B40C
/* 05FF30 7F02B400 24010007 */   li    $at, 7
/* 05FF34 7F02B404 14410012 */  bne   $v0, $at, .L7F02B450
/* 05FF38 7F02B408 00000000 */   nop   
.L7F02B40C:
/* 05FF3C 7F02B40C 8FAE0058 */  lw    $t6, 0x58($sp)
/* 05FF40 7F02B410 8FAF005C */  lw    $t7, 0x5c($sp)
/* 05FF44 7F02B414 11C0000E */  beqz  $t6, .L7F02B450
/* 05FF48 7F02B418 00000000 */   nop   
/* 05FF4C 7F02B41C 11E0000C */  beqz  $t7, .L7F02B450
/* 05FF50 7F02B420 8FB80060 */   lw    $t8, 0x60($sp)
/* 05FF54 7F02B424 1300000A */  beqz  $t8, .L7F02B450
/* 05FF58 7F02B428 00000000 */   nop   
/* 05FF5C 7F02B42C 0C002914 */  jal   randomGetNext
/* 05FF60 7F02B430 00000000 */   nop   
/* 05FF64 7F02B434 3C018005 */  lui   $at, %hi(D_80051E8C)
/* 05FF68 7F02B438 C42C1E8C */  lwc1  $f12, %lo(D_80051E8C)($at)
/* 05FF6C 7F02B43C 24010003 */  li    $at, 3
/* 05FF70 7F02B440 0041001B */  divu  $zero, $v0, $at
/* 05FF74 7F02B444 00002810 */  mfhi  $a1
/* 05FF78 7F02B448 24A50005 */  addiu $a1, $a1, 5
/* 05FF7C 7F02B44C 27A80044 */  addiu $t0, $sp, 0x44
.L7F02B450:
/* 05FF80 7F02B450 04A0001D */  bltz  $a1, .L7F02B4C8
/* 05FF84 7F02B454 0005C880 */   sll   $t9, $a1, 2
/* 05FF88 7F02B458 01196021 */  addu  $t4, $t0, $t9
/* 05FF8C 7F02B45C 8D860000 */  lw    $a2, ($t4)
/* 05FF90 7F02B460 3C013E00 */  li    $at, 0x3E000000 # 0.125000
/* 05FF94 7F02B464 44815000 */  mtc1  $at, $f10
/* 05FF98 7F02B468 44862000 */  mtc1  $a2, $f4
/* 05FF9C 7F02B46C C7B20070 */  lwc1  $f18, 0x70($sp)
/* 05FFA0 7F02B470 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 05FFA4 7F02B474 468021A0 */  cvt.s.w $f6, $f4
/* 05FFA8 7F02B478 44812000 */  mtc1  $at, $f4
/* 05FFAC 7F02B47C 460C3202 */  mul.s $f8, $f6, $f12
/* 05FFB0 7F02B480 00000000 */  nop   
/* 05FFB4 7F02B484 460A4402 */  mul.s $f16, $f8, $f10
/* 05FFB8 7F02B488 46128000 */  add.s $f0, $f16, $f18
/* 05FFBC 7F02B48C 4600603E */  c.le.s $f12, $f0
/* 05FFC0 7F02B490 46000086 */  mov.s $f2, $f0
/* 05FFC4 7F02B494 45000002 */  bc1f  .L7F02B4A0
/* 05FFC8 7F02B498 00000000 */   nop   
/* 05FFCC 7F02B49C 460C0081 */  sub.s $f2, $f0, $f12
.L7F02B4A0:
/* 05FFD0 7F02B4A0 46041182 */  mul.s $f6, $f2, $f4
/* 05FFD4 7F02B4A4 02002025 */  move  $a0, $s0
/* 05FFD8 7F02B4A8 24050010 */  li    $a1, 16
/* 05FFDC 7F02B4AC 460C3203 */  div.s $f8, $f6, $f12
/* 05FFE0 7F02B4B0 4600428D */  trunc.w.s $f10, $f8
/* 05FFE4 7F02B4B4 44065000 */  mfc1  $a2, $f10
/* 05FFE8 7F02B4B8 0FC0AAD1 */  jal   check_set_actor_standing_still
/* 05FFEC 7F02B4BC 00000000 */   nop   
/* 05FFF0 7F02B4C0 10000003 */  b     .L7F02B4D0
/* 05FFF4 7F02B4C4 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F02B4C8:
/* 05FFF8 7F02B4C8 AE000040 */  sw    $zero, 0x40($s0)
.L7F02B4CC:
/* 05FFFC 7F02B4CC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F02B4D0:
/* 060000 7F02B4D0 8FB00020 */  lw    $s0, 0x20($sp)
/* 060004 7F02B4D4 27BD00B0 */  addiu $sp, $sp, 0xb0
/* 060008 7F02B4D8 03E00008 */  jr    $ra
/* 06000C 7F02B4DC 00000000 */   nop   
)
#endif



void actor_reset_sleep(struct ChrRecord *actor) {
    actor->sleep = 0;
}



#ifdef NONMATCHING
void sub_GAME_7F02B4E8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02B4E8
/* 060018 7F02B4E8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 06001C 7F02B4EC AFBF001C */  sw    $ra, 0x1c($sp)
/* 060020 7F02B4F0 AFB00018 */  sw    $s0, 0x18($sp)
/* 060024 7F02B4F4 8C8E0030 */  lw    $t6, 0x30($a0)
/* 060028 7F02B4F8 00808025 */  move  $s0, $a0
/* 06002C 7F02B4FC 15C0000D */  bnez  $t6, .L7F02B534
/* 060030 7F02B500 00000000 */   nop   
/* 060034 7F02B504 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 060038 7F02B508 8C84001C */   lw    $a0, 0x1c($a0)
/* 06003C 7F02B50C E7A00020 */  swc1  $f0, 0x20($sp)
/* 060040 7F02B510 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 060044 7F02B514 8E04001C */   lw    $a0, 0x1c($s0)
/* 060048 7F02B518 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 06004C 7F02B51C 4604003E */  c.le.s $f0, $f4
/* 060050 7F02B520 00000000 */  nop   
/* 060054 7F02B524 45000003 */  bc1f  .L7F02B534
/* 060058 7F02B528 00000000 */   nop   
/* 06005C 7F02B52C 0FC08F2E */  jal   chrlvKneelingAnimationRelated
/* 060060 7F02B530 02002025 */   move  $a0, $s0
.L7F02B534:
/* 060064 7F02B534 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 060068 7F02B538 8E04001C */   lw    $a0, 0x1c($s0)
/* 06006C 7F02B53C 3C0F8007 */  lui   $t7, %hi(ptr_animation_table) 
/* 060070 7F02B540 8DEF9538 */  lw    $t7, %lo(ptr_animation_table)($t7)
/* 060074 7F02B544 3C180001 */  lui   $t8, %hi(0x0000B9A8) # $t8, 1
/* 060078 7F02B548 2718B9A8 */  addiu $t8, %lo(0x0000B9A8) # addiu $t8, $t8, -0x4658
/* 06007C 7F02B54C 01F8C821 */  addu  $t9, $t7, $t8
/* 060080 7F02B550 54590028 */  bnel  $v0, $t9, .L7F02B5F4
/* 060084 7F02B554 820E0008 */   lb    $t6, 8($s0)
/* 060088 7F02B558 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 06008C 7F02B55C 8E04001C */   lw    $a0, 0x1c($s0)
/* 060090 7F02B560 3C014228 */  li    $at, 0x42280000 # 42.000000
/* 060094 7F02B564 44813000 */  mtc1  $at, $f6
/* 060098 7F02B568 00000000 */  nop   
/* 06009C 7F02B56C 4600303E */  c.le.s $f6, $f0
/* 0600A0 7F02B570 00000000 */  nop   
/* 0600A4 7F02B574 4502001F */  bc1fl .L7F02B5F4
/* 0600A8 7F02B578 820E0008 */   lb    $t6, 8($s0)
/* 0600AC 7F02B57C 8E080014 */  lw    $t0, 0x14($s0)
/* 0600B0 7F02B580 3C0A8005 */  lui   $t2, %hi(D_80048380) 
/* 0600B4 7F02B584 00084980 */  sll   $t1, $t0, 6
/* 0600B8 7F02B588 0522001A */  bltzl $t1, .L7F02B5F4
/* 0600BC 7F02B58C 820E0008 */   lb    $t6, 8($s0)
/* 0600C0 7F02B590 8D4A8380 */  lw    $t2, %lo(D_80048380)($t2)
/* 0600C4 7F02B594 314B0001 */  andi  $t3, $t2, 1
/* 0600C8 7F02B598 55600012 */  bnezl $t3, .L7F02B5E4
/* 0600CC 7F02B59C 8E0C0014 */   lw    $t4, 0x14($s0)
/* 0600D0 7F02B5A0 0FC0CB79 */  jal   distToBond3D
/* 0600D4 7F02B5A4 02002025 */   move  $a0, $s0
/* 0600D8 7F02B5A8 3C014448 */  li    $at, 0x44480000 # 800.000000
/* 0600DC 7F02B5AC 44814000 */  mtc1  $at, $f8
/* 0600E0 7F02B5B0 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0600E4 7F02B5B4 24050101 */  li    $a1, 257
/* 0600E8 7F02B5B8 4608003C */  c.lt.s $f0, $f8
/* 0600EC 7F02B5BC 00003025 */  move  $a2, $zero
/* 0600F0 7F02B5C0 45020008 */  bc1fl .L7F02B5E4
/* 0600F4 7F02B5C4 8E0C0014 */   lw    $t4, 0x14($s0)
/* 0600F8 7F02B5C8 0C002382 */  jal   sndPlaySfx
/* 0600FC 7F02B5CC 8C843720 */   lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 060100 7F02B5D0 8E050018 */  lw    $a1, 0x18($s0)
/* 060104 7F02B5D4 00402025 */  move  $a0, $v0
/* 060108 7F02B5D8 0FC14E84 */  jal   sub_GAME_7F053A10
/* 06010C 7F02B5DC 24A50008 */   addiu $a1, $a1, 8
/* 060110 7F02B5E0 8E0C0014 */  lw    $t4, 0x14($s0)
.L7F02B5E4:
/* 060114 7F02B5E4 3C010200 */  lui   $at, 0x200
/* 060118 7F02B5E8 01816825 */  or    $t5, $t4, $at
/* 06011C 7F02B5EC AE0D0014 */  sw    $t5, 0x14($s0)
/* 060120 7F02B5F0 820E0008 */  lb    $t6, 8($s0)
.L7F02B5F4:
/* 060124 7F02B5F4 5DC0000C */  bgtzl $t6, .L7F02B628
/* 060128 7F02B5F8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 06012C 7F02B5FC 8E0F0038 */  lw    $t7, 0x38($s0)
/* 060130 7F02B600 51E00009 */  beql  $t7, $zero, .L7F02B628
/* 060134 7F02B604 8FBF001C */   lw    $ra, 0x1c($sp)
/* 060138 7F02B608 0C002914 */  jal   randomGetNext
/* 06013C 7F02B60C 00000000 */   nop   
/* 060140 7F02B610 24010005 */  li    $at, 5
/* 060144 7F02B614 0041001B */  divu  $zero, $v0, $at
/* 060148 7F02B618 0000C010 */  mfhi  $t8
/* 06014C 7F02B61C 2719000E */  addiu $t9, $t8, 0xe
/* 060150 7F02B620 A2190008 */  sb    $t9, 8($s0)
/* 060154 7F02B624 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F02B628:
/* 060158 7F02B628 8FB00018 */  lw    $s0, 0x18($sp)
/* 06015C 7F02B62C 27BD0028 */  addiu $sp, $sp, 0x28
/* 060160 7F02B630 03E00008 */  jr    $ra
/* 060164 7F02B634 00000000 */   nop   
)
#endif



/**
 * Address 0x7F02B638.
*/
void chrlvSurrenderAnimationRelated7F02B638(struct ChrRecord *arg0)
{
    Model *model;

    if ((s32) arg0->sleep <= 0)
    {
        model = arg0->model;
        arg0->sleep = 0x10;

        if ((sub_GAME_7F06F5AC(model) == &ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed_drop_weapon]) && (objecthandlerGetModelField28(model) >= 80.0f))
        {
            struct coord3d sp30 = D_80030A44;

            f32 t = getsubroty(model);

            sp30.f[0] = -sinf(t);
            sp30.f[2] = -cosf(t);

            if (chrlvCall7F02982C(arg0->prop, &sp30, 20.0f) == 0)
            {
                objecthandlerAnimationRelated7F06FCA8(arg0->model, &ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed], randomGetNext() & 1, 30.0f, 0.5f, 16.0f);
                sub_GAME_7F06FDCC(arg0->model, 30.0f, 16.0f);
            }
        }
    }
}



#ifdef NONMATCHING
void manage_guard_fade(void) {

}
#else
GLOBAL_ASM(
.text
glabel manage_guard_fade
/* 0602A4 7F02B774 8C82002C */  lw    $v0, 0x2c($a0)
/* 0602A8 7F02B778 3C0E8005 */  lui   $t6, %hi(g_ClockTimer) 
/* 0602AC 7F02B77C 0442001E */  bltzl $v0, .L7F02B7F8
/* 0602B0 7F02B780 AC80002C */   sw    $zero, 0x2c($a0)
/* 0602B4 7F02B784 8DCE8374 */  lw    $t6, %lo(g_ClockTimer)($t6)
/* 0602B8 7F02B788 2403005A */  li    $v1, 90
/* 0602BC 7F02B78C 004E7821 */  addu  $t7, $v0, $t6
/* 0602C0 7F02B790 29E1005A */  slti  $at, $t7, 0x5a
/* 0602C4 7F02B794 AC8F002C */  sw    $t7, 0x2c($a0)
/* 0602C8 7F02B798 14200005 */  bnez  $at, .L7F02B7B0
/* 0602CC 7F02B79C 01E01025 */   move  $v0, $t7
/* 0602D0 7F02B7A0 94980012 */  lhu   $t8, 0x12($a0)
/* 0602D4 7F02B7A4 37190020 */  ori   $t9, $t8, 0x20
/* 0602D8 7F02B7A8 03E00008 */  jr    $ra
/* 0602DC 7F02B7AC A4990012 */   sh    $t9, 0x12($a0)

.L7F02B7B0:
/* 0602E0 7F02B7B0 00624023 */  subu  $t0, $v1, $v0
/* 0602E4 7F02B7B4 00084A00 */  sll   $t1, $t0, 8
/* 0602E8 7F02B7B8 01284823 */  subu  $t1, $t1, $t0
/* 0602EC 7F02B7BC 0123001A */  div   $zero, $t1, $v1
/* 0602F0 7F02B7C0 00005012 */  mflo  $t2
/* 0602F4 7F02B7C4 A08A000C */  sb    $t2, 0xc($a0)
/* 0602F8 7F02B7C8 14600002 */  bnez  $v1, .L7F02B7D4
/* 0602FC 7F02B7CC 00000000 */   nop   
/* 060300 7F02B7D0 0007000D */  break 7
.L7F02B7D4:
/* 060304 7F02B7D4 2401FFFF */  li    $at, -1
/* 060308 7F02B7D8 14610004 */  bne   $v1, $at, .L7F02B7EC
/* 06030C 7F02B7DC 3C018000 */   lui   $at, 0x8000
/* 060310 7F02B7E0 15210002 */  bne   $t1, $at, .L7F02B7EC
/* 060314 7F02B7E4 00000000 */   nop   
/* 060318 7F02B7E8 0006000D */  break 6
.L7F02B7EC:
/* 06031C 7F02B7EC 03E00008 */  jr    $ra
/* 060320 7F02B7F0 00000000 */   nop   

/* 060324 7F02B7F4 AC80002C */  sw    $zero, 0x2c($a0)
.L7F02B7F8:
/* 060328 7F02B7F8 03E00008 */  jr    $ra
/* 06032C 7F02B7FC 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02B800(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E90
.word 0x4a742400 /*4000000.0*/
.text
glabel sub_GAME_7F02B800
/* 060330 7F02B800 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 060334 7F02B804 AFBF003C */  sw    $ra, 0x3c($sp)
/* 060338 7F02B808 AFB70038 */  sw    $s7, 0x38($sp)
/* 06033C 7F02B80C AFB4002C */  sw    $s4, 0x2c($sp)
/* 060340 7F02B810 AFB30028 */  sw    $s3, 0x28($sp)
/* 060344 7F02B814 AFB20024 */  sw    $s2, 0x24($sp)
/* 060348 7F02B818 0080A025 */  move  $s4, $a0
/* 06034C 7F02B81C 00A0B825 */  move  $s7, $a1
/* 060350 7F02B820 AFB60034 */  sw    $s6, 0x34($sp)
/* 060354 7F02B824 AFB50030 */  sw    $s5, 0x30($sp)
/* 060358 7F02B828 AFB10020 */  sw    $s1, 0x20($sp)
/* 06035C 7F02B82C AFB0001C */  sw    $s0, 0x1c($sp)
/* 060360 7F02B830 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 060364 7F02B834 00009825 */  move  $s3, $zero
/* 060368 7F02B838 0FC07D4C */  jal   get_numguards
/* 06036C 7F02B83C 00009025 */   move  $s2, $zero
/* 060370 7F02B840 82830007 */  lb    $v1, 7($s4)
/* 060374 7F02B844 24010006 */  li    $at, 6
/* 060378 7F02B848 0040B025 */  move  $s6, $v0
/* 06037C 7F02B84C 14610003 */  bne   $v1, $at, .L7F02B85C
/* 060380 7F02B850 3C158003 */   lui   $s5, %hi(ptr_guard_data)
/* 060384 7F02B854 10000005 */  b     .L7F02B86C
/* 060388 7F02B858 8E93002C */   lw    $s3, 0x2c($s4)
.L7F02B85C:
/* 06038C 7F02B85C 24010004 */  li    $at, 4
/* 060390 7F02B860 54610003 */  bnel  $v1, $at, .L7F02B870
/* 060394 7F02B864 0262082A */   slt   $at, $s3, $v0
/* 060398 7F02B868 8E93002C */  lw    $s3, 0x2c($s4)
.L7F02B86C:
/* 06039C 7F02B86C 0262082A */  slt   $at, $s3, $v0
.L7F02B870:
/* 0603A0 7F02B870 10200036 */  beqz  $at, .L7F02B94C
/* 0603A4 7F02B874 00138900 */   sll   $s1, $s3, 4
/* 0603A8 7F02B878 02338823 */  subu  $s1, $s1, $s3
/* 0603AC 7F02B87C 001188C0 */  sll   $s1, $s1, 3
/* 0603B0 7F02B880 02338823 */  subu  $s1, $s1, $s3
/* 0603B4 7F02B884 3C018005 */  lui   $at, %hi(D_80051E90)
/* 0603B8 7F02B888 C4341E90 */  lwc1  $f20, %lo(D_80051E90)($at)
/* 0603BC 7F02B88C 00118880 */  sll   $s1, $s1, 2
/* 0603C0 7F02B890 26B5CC64 */  addiu $s5, %lo(ptr_guard_data) # addiu $s5, $s5, -0x339c
/* 0603C4 7F02B894 8EAE0000 */  lw    $t6, ($s5)
.L7F02B898:
/* 0603C8 7F02B898 022E8021 */  addu  $s0, $s1, $t6
/* 0603CC 7F02B89C 8E0F001C */  lw    $t7, 0x1c($s0)
/* 0603D0 7F02B8A0 51E00024 */  beql  $t7, $zero, .L7F02B934
/* 0603D4 7F02B8A4 26730001 */   addiu $s3, $s3, 1
/* 0603D8 7F02B8A8 8E020018 */  lw    $v0, 0x18($s0)
/* 0603DC 7F02B8AC 8E830018 */  lw    $v1, 0x18($s4)
/* 0603E0 7F02B8B0 02002025 */  move  $a0, $s0
/* 0603E4 7F02B8B4 C4440008 */  lwc1  $f4, 8($v0)
/* 0603E8 7F02B8B8 C4660008 */  lwc1  $f6, 8($v1)
/* 0603EC 7F02B8BC C448000C */  lwc1  $f8, 0xc($v0)
/* 0603F0 7F02B8C0 C46A000C */  lwc1  $f10, 0xc($v1)
/* 0603F4 7F02B8C4 46062001 */  sub.s $f0, $f4, $f6
/* 0603F8 7F02B8C8 C4500010 */  lwc1  $f16, 0x10($v0)
/* 0603FC 7F02B8CC C4720010 */  lwc1  $f18, 0x10($v1)
/* 060400 7F02B8D0 460A4081 */  sub.s $f2, $f8, $f10
/* 060404 7F02B8D4 46000102 */  mul.s $f4, $f0, $f0
/* 060408 7F02B8D8 24650008 */  addiu $a1, $v1, 8
/* 06040C 7F02B8DC 46128301 */  sub.s $f12, $f16, $f18
/* 060410 7F02B8E0 46021182 */  mul.s $f6, $f2, $f2
/* 060414 7F02B8E4 46062200 */  add.s $f8, $f4, $f6
/* 060418 7F02B8E8 460C6282 */  mul.s $f10, $f12, $f12
/* 06041C 7F02B8EC 460A4400 */  add.s $f16, $f8, $f10
/* 060420 7F02B8F0 4614803C */  c.lt.s $f16, $f20
/* 060424 7F02B8F4 00000000 */  nop   
/* 060428 7F02B8F8 4502000E */  bc1fl .L7F02B934
/* 06042C 7F02B8FC 26730001 */   addiu $s3, $s3, 1
/* 060430 7F02B900 26520001 */  addiu $s2, $s2, 1
/* 060434 7F02B904 0FC0A5A7 */  jal   chrlvMaybeSameRoom
/* 060438 7F02B908 8C660014 */   lw    $a2, 0x14($v1)
/* 06043C 7F02B90C 50400009 */  beql  $v0, $zero, .L7F02B934
/* 060440 7F02B910 26730001 */   addiu $s3, $s3, 1
/* 060444 7F02B914 56E00005 */  bnezl $s7, .L7F02B92C
/* 060448 7F02B918 86990000 */   lh    $t9, ($s4)
/* 06044C 7F02B91C 86980000 */  lh    $t8, ($s4)
/* 060450 7F02B920 10000003 */  b     .L7F02B930
/* 060454 7F02B924 A6180118 */   sh    $t8, 0x118($s0)
/* 060458 7F02B928 86990000 */  lh    $t9, ($s4)
.L7F02B92C:
/* 06045C 7F02B92C A619011A */  sh    $t9, 0x11a($s0)
.L7F02B930:
/* 060460 7F02B930 26730001 */  addiu $s3, $s3, 1
.L7F02B934:
/* 060464 7F02B934 0276082A */  slt   $at, $s3, $s6
/* 060468 7F02B938 10200004 */  beqz  $at, .L7F02B94C
/* 06046C 7F02B93C 263101DC */   addiu $s1, $s1, 0x1dc
/* 060470 7F02B940 2A410004 */  slti  $at, $s2, 4
/* 060474 7F02B944 5420FFD4 */  bnezl $at, .L7F02B898
/* 060478 7F02B948 8EAE0000 */   lw    $t6, ($s5)
.L7F02B94C:
/* 06047C 7F02B94C 82830007 */  lb    $v1, 7($s4)
/* 060480 7F02B950 24010006 */  li    $at, 6
/* 060484 7F02B954 54610004 */  bnel  $v1, $at, .L7F02B968
/* 060488 7F02B958 24010004 */   li    $at, 4
/* 06048C 7F02B95C 10000005 */  b     .L7F02B974
/* 060490 7F02B960 AE93002C */   sw    $s3, 0x2c($s4)
/* 060494 7F02B964 24010004 */  li    $at, 4
.L7F02B968:
/* 060498 7F02B968 54610003 */  bnel  $v1, $at, .L7F02B978
/* 06049C 7F02B96C 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0604A0 7F02B970 AE93002C */  sw    $s3, 0x2c($s4)
.L7F02B974:
/* 0604A4 7F02B974 8FBF003C */  lw    $ra, 0x3c($sp)
.L7F02B978:
/* 0604A8 7F02B978 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0604AC 7F02B97C 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0604B0 7F02B980 8FB10020 */  lw    $s1, 0x20($sp)
/* 0604B4 7F02B984 8FB20024 */  lw    $s2, 0x24($sp)
/* 0604B8 7F02B988 8FB30028 */  lw    $s3, 0x28($sp)
/* 0604BC 7F02B98C 8FB4002C */  lw    $s4, 0x2c($sp)
/* 0604C0 7F02B990 8FB50030 */  lw    $s5, 0x30($sp)
/* 0604C4 7F02B994 8FB60034 */  lw    $s6, 0x34($sp)
/* 0604C8 7F02B998 8FB70038 */  lw    $s7, 0x38($sp)
/* 0604CC 7F02B99C 03E00008 */  jr    $ra
/* 0604D0 7F02B9A0 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif



/**
 * Address 0x7F02B9A4.
 * PD: void chrTickDie(struct chrdata *chr).
*/
void guard_body_hit_sfx(ChrRecord *arg0)
{
    Model *model = arg0->model;

    ALSoundState * p;

    s16 body_hit_SFX[] = {0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85};

    static s32 thud_index = 0;

    if ((arg0->act_die.thudframe1 >= 0.0f) && (arg0->act_die.thudframe1 <= objecthandlerGetModelField28(model)))
    {
        p = sndPlaySfx(g_musicSfxBufferPtr, body_hit_SFX[thud_index], NULL);

        sub_GAME_7F053A10(p, &arg0->prop->pos);

        thud_index++;
        if (thud_index >= 0xB)
        {
            thud_index = 0;
        }

        arg0->act_die.thudframe1 = -1.0f;
    }

    if ((arg0->act_die.thudframe2 >= 0.0f) && (arg0->act_die.thudframe2 <= objecthandlerGetModelField28(model)))
    {
        p = sndPlaySfx(g_musicSfxBufferPtr, body_hit_SFX[thud_index], NULL);

        sub_GAME_7F053A10(p, &arg0->prop->pos);

        thud_index++;
        if (thud_index >= 0xB)
        {
            thud_index = 0;
        }

        arg0->act_die.thudframe2 = -1.0f;
    }

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        if ((s32)sub_GAME_7F06F5AC(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_death_left_leg])
        {
            objecthandlerAnimationRelated7F06FCA8(
                model,
                (void*)((s32)&ANIM_DATA_jump_backwards + (s32)&ptr_animation_table->data),
                sub_GAME_7F06F5B4(model) == 0,
                50.0f,
                0.3f,
                (((u16*)((s32)&ANIM_DATA_jump_backwards + (s32)&ptr_animation_table->data))[2] - 1.0f) - 50.0f);

            sub_GAME_7F06FE4C(model, 0.5f, (((u16*)((s32)&ANIM_DATA_jump_backwards + (s32)&ptr_animation_table->data))[2] - 1.0f) - 50.0f);

            return;
        }

        chrlvActorFadeAway(arg0);
    }

    sub_GAME_7F02B800(arg0, 1);
}




#ifdef NONMATCHING
void sub_GAME_7F02BC80(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BC80
/* 0607B0 7F02BC80 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0607B4 7F02BC84 AFB00018 */  sw    $s0, 0x18($sp)
/* 0607B8 7F02BC88 00808025 */  move  $s0, $a0
/* 0607BC 7F02BC8C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0607C0 7F02BC90 8C84001C */  lw    $a0, 0x1c($a0)
/* 0607C4 7F02BC94 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 0607C8 7F02BC98 AFA40024 */   sw    $a0, 0x24($sp)
/* 0607CC 7F02BC9C E7A00020 */  swc1  $f0, 0x20($sp)
/* 0607D0 7F02BCA0 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 0607D4 7F02BCA4 8FA40024 */   lw    $a0, 0x24($sp)
/* 0607D8 7F02BCA8 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0607DC 7F02BCAC 4604003E */  c.le.s $f0, $f4
/* 0607E0 7F02BCB0 00000000 */  nop   
/* 0607E4 7F02BCB4 45020013 */  bc1fl .L7F02BD04
/* 0607E8 7F02BCB8 02002025 */   move  $a0, $s0
/* 0607EC 7F02BCBC 0FC0A6EC */  jal   chrlvSetTargetToPlayer
/* 0607F0 7F02BCC0 02002025 */   move  $a0, $s0
/* 0607F4 7F02BCC4 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 0607F8 7F02BCC8 8FA40024 */   lw    $a0, 0x24($sp)
/* 0607FC 7F02BCCC 3C0E8007 */  lui   $t6, %hi(ptr_animation_table) 
/* 060800 7F02BCD0 8DCE9538 */  lw    $t6, %lo(ptr_animation_table)($t6)
/* 060804 7F02BCD4 3C0F0000 */  lui   $t7, %hi(0x0000540C) # $t7, 0
/* 060808 7F02BCD8 25EF540C */  addiu $t7, %lo(0x0000540C) # addiu $t7, $t7, 0x540c
/* 06080C 7F02BCDC 01CFC021 */  addu  $t8, $t6, $t7
/* 060810 7F02BCE0 14580005 */  bne   $v0, $t8, .L7F02BCF8
/* 060814 7F02BCE4 02002025 */   move  $a0, $s0
/* 060818 7F02BCE8 0FC08F85 */  jal   chrlvIdleAnimationRelated7F023E14
/* 06081C 7F02BCEC 3C0541D0 */   lui   $a1, 0x41d0
/* 060820 7F02BCF0 10000004 */  b     .L7F02BD04
/* 060824 7F02BCF4 02002025 */   move  $a0, $s0
.L7F02BCF8:
/* 060828 7F02BCF8 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 06082C 7F02BCFC 02002025 */   move  $a0, $s0
/* 060830 7F02BD00 02002025 */  move  $a0, $s0
.L7F02BD04:
/* 060834 7F02BD04 0FC0AE00 */  jal   sub_GAME_7F02B800
/* 060838 7F02BD08 00002825 */   move  $a1, $zero
/* 06083C 7F02BD0C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 060840 7F02BD10 8FB00018 */  lw    $s0, 0x18($sp)
/* 060844 7F02BD14 27BD0028 */  addiu $sp, $sp, 0x28
/* 060848 7F02BD18 03E00008 */  jr    $ra
/* 06084C 7F02BD1C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02BD20(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BD20
/* 060850 7F02BD20 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 060854 7F02BD24 AFB00020 */  sw    $s0, 0x20($sp)
/* 060858 7F02BD28 00808025 */  move  $s0, $a0
/* 06085C 7F02BD2C AFBF0024 */  sw    $ra, 0x24($sp)
/* 060860 7F02BD30 8C84001C */  lw    $a0, 0x1c($a0)
/* 060864 7F02BD34 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 060868 7F02BD38 AFA4003C */   sw    $a0, 0x3c($sp)
/* 06086C 7F02BD3C 8FA4003C */  lw    $a0, 0x3c($sp)
/* 060870 7F02BD40 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 060874 7F02BD44 E7A0002C */   swc1  $f0, 0x2c($sp)
/* 060878 7F02BD48 C7A4002C */  lwc1  $f4, 0x2c($sp)
/* 06087C 7F02BD4C 4604003E */  c.le.s $f0, $f4
/* 060880 7F02BD50 00000000 */  nop   
/* 060884 7F02BD54 4502000F */  bc1fl .L7F02BD94
/* 060888 7F02BD58 8FBF0024 */   lw    $ra, 0x24($sp)
/* 06088C 7F02BD5C C606002C */  lwc1  $f6, 0x2c($s0)
/* 060890 7F02BD60 02002025 */  move  $a0, $s0
/* 060894 7F02BD64 27A50030 */  addiu $a1, $sp, 0x30
/* 060898 7F02BD68 E7A60030 */  swc1  $f6, 0x30($sp)
/* 06089C 7F02BD6C C6080030 */  lwc1  $f8, 0x30($s0)
/* 0608A0 7F02BD70 E7A80034 */  swc1  $f8, 0x34($sp)
/* 0608A4 7F02BD74 C60A0034 */  lwc1  $f10, 0x34($s0)
/* 0608A8 7F02BD78 E7AA0038 */  swc1  $f10, 0x38($sp)
/* 0608AC 7F02BD7C 8E0E0040 */  lw    $t6, 0x40($s0)
/* 0608B0 7F02BD80 8E07003C */  lw    $a3, 0x3c($s0)
/* 0608B4 7F02BD84 8E060038 */  lw    $a2, 0x38($s0)
/* 0608B8 7F02BD88 0FC09942 */  jal   triggered_on_shot_hit
/* 0608BC 7F02BD8C AFAE0010 */   sw    $t6, 0x10($sp)
/* 0608C0 7F02BD90 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F02BD94:
/* 0608C4 7F02BD94 8FB00020 */  lw    $s0, 0x20($sp)
/* 0608C8 7F02BD98 27BD0040 */  addiu $sp, $sp, 0x40
/* 0608CC 7F02BD9C 03E00008 */  jr    $ra
/* 0608D0 7F02BDA0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02BDA4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BDA4
/* 0608D4 7F02BDA4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0608D8 7F02BDA8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0608DC 7F02BDAC AFA40020 */  sw    $a0, 0x20($sp)
/* 0608E0 7F02BDB0 8C84001C */  lw    $a0, 0x1c($a0)
/* 0608E4 7F02BDB4 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 0608E8 7F02BDB8 AFA4001C */   sw    $a0, 0x1c($sp)
/* 0608EC 7F02BDBC 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0608F0 7F02BDC0 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 0608F4 7F02BDC4 E7A00018 */   swc1  $f0, 0x18($sp)
/* 0608F8 7F02BDC8 C7A40018 */  lwc1  $f4, 0x18($sp)
/* 0608FC 7F02BDCC 4604003E */  c.le.s $f0, $f4
/* 060900 7F02BDD0 00000000 */  nop   
/* 060904 7F02BDD4 45020007 */  bc1fl .L7F02BDF4
/* 060908 7F02BDD8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 06090C 7F02BDDC 0FC0A6EC */  jal   chrlvSetTargetToPlayer
/* 060910 7F02BDE0 8FA40020 */   lw    $a0, 0x20($sp)
/* 060914 7F02BDE4 8FA40020 */  lw    $a0, 0x20($sp)
/* 060918 7F02BDE8 0FC08F85 */  jal   chrlvIdleAnimationRelated7F023E14
/* 06091C 7F02BDEC 3C054120 */   lui   $a1, 0x4120
/* 060920 7F02BDF0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02BDF4:
/* 060924 7F02BDF4 27BD0020 */  addiu $sp, $sp, 0x20
/* 060928 7F02BDF8 03E00008 */  jr    $ra
/* 06092C 7F02BDFC 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02BE00(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BE00
/* 060930 7F02BE00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 060934 7F02BE04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 060938 7F02BE08 AFA40020 */  sw    $a0, 0x20($sp)
/* 06093C 7F02BE0C 8C84001C */  lw    $a0, 0x1c($a0)
/* 060940 7F02BE10 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 060944 7F02BE14 AFA4001C */   sw    $a0, 0x1c($sp)
/* 060948 7F02BE18 8FA4001C */  lw    $a0, 0x1c($sp)
/* 06094C 7F02BE1C 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 060950 7F02BE20 E7A00018 */   swc1  $f0, 0x18($sp)
/* 060954 7F02BE24 C7A40018 */  lwc1  $f4, 0x18($sp)
/* 060958 7F02BE28 4604003E */  c.le.s $f0, $f4
/* 06095C 7F02BE2C 00000000 */  nop   
/* 060960 7F02BE30 45020006 */  bc1fl .L7F02BE4C
/* 060964 7F02BE34 8FBF0014 */   lw    $ra, 0x14($sp)
/* 060968 7F02BE38 0FC0A6EC */  jal   chrlvSetTargetToPlayer
/* 06096C 7F02BE3C 8FA40020 */   lw    $a0, 0x20($sp)
/* 060970 7F02BE40 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 060974 7F02BE44 8FA40020 */   lw    $a0, 0x20($sp)
/* 060978 7F02BE48 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02BE4C:
/* 06097C 7F02BE4C 27BD0020 */  addiu $sp, $sp, 0x20
/* 060980 7F02BE50 03E00008 */  jr    $ra
/* 060984 7F02BE54 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02BE58(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BE58
/* 060988 7F02BE58 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 06098C 7F02BE5C AFBF0014 */  sw    $ra, 0x14($sp)
/* 060990 7F02BE60 AFA40020 */  sw    $a0, 0x20($sp)
/* 060994 7F02BE64 8C84001C */  lw    $a0, 0x1c($a0)
/* 060998 7F02BE68 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 06099C 7F02BE6C AFA4001C */   sw    $a0, 0x1c($sp)
/* 0609A0 7F02BE70 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0609A4 7F02BE74 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 0609A8 7F02BE78 E7A00018 */   swc1  $f0, 0x18($sp)
/* 0609AC 7F02BE7C C7A40018 */  lwc1  $f4, 0x18($sp)
/* 0609B0 7F02BE80 4604003E */  c.le.s $f0, $f4
/* 0609B4 7F02BE84 00000000 */  nop   
/* 0609B8 7F02BE88 45020004 */  bc1fl .L7F02BE9C
/* 0609BC 7F02BE8C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0609C0 7F02BE90 0FC08F2E */  jal   chrlvKneelingAnimationRelated
/* 0609C4 7F02BE94 8FA40020 */   lw    $a0, 0x20($sp)
/* 0609C8 7F02BE98 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02BE9C:
/* 0609CC 7F02BE9C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0609D0 7F02BEA0 03E00008 */  jr    $ra
/* 0609D4 7F02BEA4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02BEA8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BEA8
/* 0609D8 7F02BEA8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0609DC 7F02BEAC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0609E0 7F02BEB0 AFA40020 */  sw    $a0, 0x20($sp)
/* 0609E4 7F02BEB4 8C84001C */  lw    $a0, 0x1c($a0)
/* 0609E8 7F02BEB8 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 0609EC 7F02BEBC AFA4001C */   sw    $a0, 0x1c($sp)
/* 0609F0 7F02BEC0 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0609F4 7F02BEC4 44812000 */  mtc1  $at, $f4
/* 0609F8 7F02BEC8 00000000 */  nop   
/* 0609FC 7F02BECC 4600203E */  c.le.s $f4, $f0
/* 060A00 7F02BED0 00000000 */  nop   
/* 060A04 7F02BED4 45000003 */  bc1f  .L7F02BEE4
/* 060A08 7F02BED8 00000000 */   nop   
/* 060A0C 7F02BEDC 0FC15772 */  jal   start_alarm
/* 060A10 7F02BEE0 00000000 */   nop   
.L7F02BEE4:
/* 060A14 7F02BEE4 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 060A18 7F02BEE8 8FA4001C */   lw    $a0, 0x1c($sp)
/* 060A1C 7F02BEEC E7A00018 */  swc1  $f0, 0x18($sp)
/* 060A20 7F02BEF0 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 060A24 7F02BEF4 8FA4001C */   lw    $a0, 0x1c($sp)
/* 060A28 7F02BEF8 C7A60018 */  lwc1  $f6, 0x18($sp)
/* 060A2C 7F02BEFC 4606003E */  c.le.s $f0, $f6
/* 060A30 7F02BF00 00000000 */  nop   
/* 060A34 7F02BF04 45020004 */  bc1fl .L7F02BF18
/* 060A38 7F02BF08 8FBF0014 */   lw    $ra, 0x14($sp)
/* 060A3C 7F02BF0C 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 060A40 7F02BF10 8FA40020 */   lw    $a0, 0x20($sp)
/* 060A44 7F02BF14 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02BF18:
/* 060A48 7F02BF18 27BD0020 */  addiu $sp, $sp, 0x20
/* 060A4C 7F02BF1C 03E00008 */  jr    $ra
/* 060A50 7F02BF20 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02BF24(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BF24
/* 060A54 7F02BF24 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 060A58 7F02BF28 AFBF001C */  sw    $ra, 0x1c($sp)
/* 060A5C 7F02BF2C AFB00018 */  sw    $s0, 0x18($sp)
/* 060A60 7F02BF30 AFA40028 */  sw    $a0, 0x28($sp)
/* 060A64 7F02BF34 8C90001C */  lw    $s0, 0x1c($a0)
/* 060A68 7F02BF38 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 060A6C 7F02BF3C 02002025 */   move  $a0, $s0
/* 060A70 7F02BF40 E7A00020 */  swc1  $f0, 0x20($sp)
/* 060A74 7F02BF44 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 060A78 7F02BF48 02002025 */   move  $a0, $s0
/* 060A7C 7F02BF4C C7A40020 */  lwc1  $f4, 0x20($sp)
/* 060A80 7F02BF50 4604003E */  c.le.s $f0, $f4
/* 060A84 7F02BF54 00000000 */  nop   
/* 060A88 7F02BF58 4502001E */  bc1fl .L7F02BFD4
/* 060A8C 7F02BF5C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 060A90 7F02BF60 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 060A94 7F02BF64 02002025 */   move  $a0, $s0
/* 060A98 7F02BF68 3C0F8007 */  lui   $t7, %hi(ptr_animation_table) 
/* 060A9C 7F02BF6C 8DEF9538 */  lw    $t7, %lo(ptr_animation_table)($t7)
/* 060AA0 7F02BF70 3C180000 */  lui   $t8, %hi(0x00004384) # $t8, 0
/* 060AA4 7F02BF74 27184384 */  addiu $t8, %lo(0x00004384) # addiu $t8, $t8, 0x4384
/* 060AA8 7F02BF78 01F8C821 */  addu  $t9, $t7, $t8
/* 060AAC 7F02BF7C 14590005 */  bne   $v0, $t9, .L7F02BF94
/* 060AB0 7F02BF80 8FA40028 */   lw    $a0, 0x28($sp)
/* 060AB4 7F02BF84 0FC08F85 */  jal   chrlvIdleAnimationRelated7F023E14
/* 060AB8 7F02BF88 3C0541D0 */   lui   $a1, 0x41d0
/* 060ABC 7F02BF8C 10000011 */  b     .L7F02BFD4
/* 060AC0 7F02BF90 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F02BF94:
/* 060AC4 7F02BF94 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 060AC8 7F02BF98 02002025 */   move  $a0, $s0
/* 060ACC 7F02BF9C 3C088007 */  lui   $t0, %hi(ptr_animation_table) 
/* 060AD0 7F02BFA0 8D089538 */  lw    $t0, %lo(ptr_animation_table)($t0)
/* 060AD4 7F02BFA4 3C090000 */  lui   $t1, %hi(0x00005D10) # $t1, 0
/* 060AD8 7F02BFA8 25295D10 */  addiu $t1, %lo(0x00005D10) # addiu $t1, $t1, 0x5d10
/* 060ADC 7F02BFAC 01095021 */  addu  $t2, $t0, $t1
/* 060AE0 7F02BFB0 144A0005 */  bne   $v0, $t2, .L7F02BFC8
/* 060AE4 7F02BFB4 8FA40028 */   lw    $a0, 0x28($sp)
/* 060AE8 7F02BFB8 0FC08F85 */  jal   chrlvIdleAnimationRelated7F023E14
/* 060AEC 7F02BFBC 3C0541D0 */   lui   $a1, 0x41d0
/* 060AF0 7F02BFC0 10000004 */  b     .L7F02BFD4
/* 060AF4 7F02BFC4 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F02BFC8:
/* 060AF8 7F02BFC8 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 060AFC 7F02BFCC 8FA40028 */   lw    $a0, 0x28($sp)
/* 060B00 7F02BFD0 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F02BFD4:
/* 060B04 7F02BFD4 8FB00018 */  lw    $s0, 0x18($sp)
/* 060B08 7F02BFD8 27BD0028 */  addiu $sp, $sp, 0x28
/* 060B0C 7F02BFDC 03E00008 */  jr    $ra
/* 060B10 7F02BFE0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02BFE4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02BFE4
/* 060B14 7F02BFE4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 060B18 7F02BFE8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 060B1C 7F02BFEC AFB00018 */  sw    $s0, 0x18($sp)
/* 060B20 7F02BFF0 00808025 */  move  $s0, $a0
/* 060B24 7F02BFF4 AFA50044 */  sw    $a1, 0x44($sp)
/* 060B28 7F02BFF8 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 060B2C 7F02BFFC AFA60048 */   sw    $a2, 0x48($sp)
/* 060B30 7F02C000 8C430004 */  lw    $v1, 4($v0)
/* 060B34 7F02C004 80640080 */  lb    $a0, 0x80($v1)
/* 060B38 7F02C008 AFA00034 */  sw    $zero, 0x34($sp)
/* 060B3C 7F02C00C 0FC177FC */  jal   bondwalkItemGetSoundTriggerRate
/* 060B40 7F02C010 AFA30038 */   sw    $v1, 0x38($sp)
/* 060B44 7F02C014 8FA30038 */  lw    $v1, 0x38($sp)
/* 060B48 7F02C018 A3A20033 */  sb    $v0, 0x33($sp)
/* 060B4C 7F02C01C 0FC17805 */  jal   bondwalkItemGetSound
/* 060B50 7F02C020 80640080 */   lb    $a0, 0x80($v1)
/* 060B54 7F02C024 8FAE0048 */  lw    $t6, 0x48($sp)
/* 060B58 7F02C028 8FA50034 */  lw    $a1, 0x34($sp)
/* 060B5C 7F02C02C A7A20030 */  sh    $v0, 0x30($sp)
/* 060B60 7F02C030 11C00012 */  beqz  $t6, .L7F02C07C
/* 060B64 7F02C034 93AF0033 */   lbu   $t7, 0x33($sp)
/* 060B68 7F02C038 59E00010 */  blezl $t7, .L7F02C07C
/* 060B6C 7F02C03C 24050001 */   li    $a1, 1
/* 060B70 7F02C040 96180012 */  lhu   $t8, 0x12($s0)
/* 060B74 7F02C044 8FA80044 */  lw    $t0, 0x44($sp)
/* 060B78 7F02C048 3C0C8005 */  lui   $t4, %hi(g_GlobalTimer) 
/* 060B7C 7F02C04C 33190080 */  andi  $t9, $t8, 0x80
/* 060B80 7F02C050 1720000A */  bnez  $t9, .L7F02C07C
/* 060B84 7F02C054 00084880 */   sll   $t1, $t0, 2
/* 060B88 7F02C058 02095021 */  addu  $t2, $s0, $t1
/* 060B8C 7F02C05C 8D4B0178 */  lw    $t3, 0x178($t2)
/* 060B90 7F02C060 8D8C837C */  lw    $t4, %lo(g_GlobalTimer)($t4)
/* 060B94 7F02C064 016C082A */  slt   $at, $t3, $t4
/* 060B98 7F02C068 10200004 */  beqz  $at, .L7F02C07C
/* 060B9C 7F02C06C 00000000 */   nop   
/* 060BA0 7F02C070 10000002 */  b     .L7F02C07C
/* 060BA4 7F02C074 24050001 */   li    $a1, 1
/* 060BA8 7F02C078 24050001 */  li    $a1, 1
.L7F02C07C:
/* 060BAC 7F02C07C 10A0003F */  beqz  $a1, .L7F02C17C
/* 060BB0 7F02C080 8FAD0044 */   lw    $t5, 0x44($sp)
/* 060BB4 7F02C084 000D70C0 */  sll   $t6, $t5, 3
/* 060BB8 7F02C088 020E1821 */  addu  $v1, $s0, $t6
/* 060BBC 7F02C08C 8C640168 */  lw    $a0, 0x168($v1)
/* 060BC0 7F02C090 5080000A */  beql  $a0, $zero, .L7F02C0BC
/* 060BC4 7F02C094 8C64016C */   lw    $a0, 0x16c($v1)
/* 060BC8 7F02C098 0C00237C */  jal   sndGetPlayingState
/* 060BCC 7F02C09C AFA30028 */   sw    $v1, 0x28($sp)
/* 060BD0 7F02C0A0 10400005 */  beqz  $v0, .L7F02C0B8
/* 060BD4 7F02C0A4 8FA30028 */   lw    $v1, 0x28($sp)
/* 060BD8 7F02C0A8 8C640168 */  lw    $a0, 0x168($v1)
/* 060BDC 7F02C0AC 0C002408 */  jal   sndDeactivate
/* 060BE0 7F02C0B0 AFA30028 */   sw    $v1, 0x28($sp)
/* 060BE4 7F02C0B4 8FA30028 */  lw    $v1, 0x28($sp)
.L7F02C0B8:
/* 060BE8 7F02C0B8 8C64016C */  lw    $a0, 0x16c($v1)
.L7F02C0BC:
/* 060BEC 7F02C0BC 5080000A */  beql  $a0, $zero, .L7F02C0E8
/* 060BF0 7F02C0C0 97AF0030 */   lhu   $t7, 0x30($sp)
/* 060BF4 7F02C0C4 0C00237C */  jal   sndGetPlayingState
/* 060BF8 7F02C0C8 AFA30028 */   sw    $v1, 0x28($sp)
/* 060BFC 7F02C0CC 10400005 */  beqz  $v0, .L7F02C0E4
/* 060C00 7F02C0D0 8FA30028 */   lw    $v1, 0x28($sp)
/* 060C04 7F02C0D4 8C64016C */  lw    $a0, 0x16c($v1)
/* 060C08 7F02C0D8 0C002408 */  jal   sndDeactivate
/* 060C0C 7F02C0DC AFA30028 */   sw    $v1, 0x28($sp)
/* 060C10 7F02C0E0 8FA30028 */  lw    $v1, 0x28($sp)
.L7F02C0E4:
/* 060C14 7F02C0E4 97AF0030 */  lhu   $t7, 0x30($sp)
.L7F02C0E8:
/* 060C18 7F02C0E8 51E00025 */  beql  $t7, $zero, .L7F02C180
/* 060C1C 7F02C0EC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 060C20 7F02C0F0 8C780168 */  lw    $t8, 0x168($v1)
/* 060C24 7F02C0F4 00003025 */  move  $a2, $zero
/* 060C28 7F02C0F8 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 060C2C 7F02C0FC 17000003 */  bnez  $t8, .L7F02C10C
/* 060C30 7F02C100 87A50030 */   lh    $a1, 0x30($sp)
/* 060C34 7F02C104 10000005 */  b     .L7F02C11C
/* 060C38 7F02C108 24660168 */   addiu $a2, $v1, 0x168
.L7F02C10C:
/* 060C3C 7F02C10C 8C79016C */  lw    $t9, 0x16c($v1)
/* 060C40 7F02C110 17200002 */  bnez  $t9, .L7F02C11C
/* 060C44 7F02C114 00000000 */   nop   
/* 060C48 7F02C118 2466016C */  addiu $a2, $v1, 0x16c
.L7F02C11C:
/* 060C4C 7F02C11C 10C00017 */  beqz  $a2, .L7F02C17C
/* 060C50 7F02C120 93A80033 */   lbu   $t0, 0x33($sp)
/* 060C54 7F02C124 8FA90044 */  lw    $t1, 0x44($sp)
/* 060C58 7F02C128 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 060C5C 7F02C12C AFA80028 */  sw    $t0, 0x28($sp)
/* 060C60 7F02C130 00095080 */  sll   $t2, $t1, 2
/* 060C64 7F02C134 020A5821 */  addu  $t3, $s0, $t2
/* 060C68 7F02C138 AFAB0024 */  sw    $t3, 0x24($sp)
/* 060C6C 7F02C13C 0C002382 */  jal   sndPlaySfx
/* 060C70 7F02C140 AFA6002C */   sw    $a2, 0x2c($sp)
/* 060C74 7F02C144 8FA6002C */  lw    $a2, 0x2c($sp)
/* 060C78 7F02C148 8E050018 */  lw    $a1, 0x18($s0)
/* 060C7C 7F02C14C 8CC40000 */  lw    $a0, ($a2)
/* 060C80 7F02C150 0FC14E84 */  jal   sub_GAME_7F053A10
/* 060C84 7F02C154 24A50008 */   addiu $a1, $a1, 8
/* 060C88 7F02C158 3C0C8005 */  lui   $t4, %hi(g_GlobalTimer) 
/* 060C8C 7F02C15C 8D8C837C */  lw    $t4, %lo(g_GlobalTimer)($t4)
/* 060C90 7F02C160 8FAD0028 */  lw    $t5, 0x28($sp)
/* 060C94 7F02C164 8FAF0024 */  lw    $t7, 0x24($sp)
/* 060C98 7F02C168 018D7021 */  addu  $t6, $t4, $t5
/* 060C9C 7F02C16C ADEE0178 */  sw    $t6, 0x178($t7)
/* 060CA0 7F02C170 96180012 */  lhu   $t8, 0x12($s0)
/* 060CA4 7F02C174 37190080 */  ori   $t9, $t8, 0x80
/* 060CA8 7F02C178 A6190012 */  sh    $t9, 0x12($s0)
.L7F02C17C:
/* 060CAC 7F02C17C 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F02C180:
/* 060CB0 7F02C180 8FB00018 */  lw    $s0, 0x18($sp)
/* 060CB4 7F02C184 27BD0040 */  addiu $sp, $sp, 0x40
/* 060CB8 7F02C188 03E00008 */  jr    $ra
/* 060CBC 7F02C18C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02C190(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E98
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02C190
/* 060CC0 7F02C190 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 060CC4 7F02C194 AFBF0014 */  sw    $ra, 0x14($sp)
/* 060CC8 7F02C198 00802825 */  move  $a1, $a0
/* 060CCC 7F02C19C 8C84001C */  lw    $a0, 0x1c($a0)
/* 060CD0 7F02C1A0 0FC1B320 */  jal   getsubroty
/* 060CD4 7F02C1A4 AFA50018 */   sw    $a1, 0x18($sp)
/* 060CD8 7F02C1A8 8FA50018 */  lw    $a1, 0x18($sp)
/* 060CDC 7F02C1AC 3C018005 */  lui   $at, %hi(D_80051E98)
/* 060CE0 7F02C1B0 C42E1E98 */  lwc1  $f14, %lo(D_80051E98)($at)
/* 060CE4 7F02C1B4 C4A4014C */  lwc1  $f4, 0x14c($a1)
/* 060CE8 7F02C1B8 44808000 */  mtc1  $zero, $f16
/* 060CEC 7F02C1BC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 060CF0 7F02C1C0 46040080 */  add.s $f2, $f0, $f4
/* 060CF4 7F02C1C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 060CF8 7F02C1C8 46008306 */  mov.s $f12, $f16
/* 060CFC 7F02C1CC 4602703E */  c.le.s $f14, $f2
/* 060D00 7F02C1D0 00000000 */  nop   
/* 060D04 7F02C1D4 45020004 */  bc1fl .L7F02C1E8
/* 060D08 7F02C1D8 4610103C */   c.lt.s $f2, $f16
/* 060D0C 7F02C1DC 10000006 */  b     .L7F02C1F8
/* 060D10 7F02C1E0 460E1081 */   sub.s $f2, $f2, $f14
/* 060D14 7F02C1E4 4610103C */  c.lt.s $f2, $f16
.L7F02C1E8:
/* 060D18 7F02C1E8 00000000 */  nop   
/* 060D1C 7F02C1EC 45020003 */  bc1fl .L7F02C1FC
/* 060D20 7F02C1F0 80A20007 */   lb    $v0, 7($a1)
/* 060D24 7F02C1F4 460E1080 */  add.s $f2, $f2, $f14
.L7F02C1F8:
/* 060D28 7F02C1F8 80A20007 */  lb    $v0, 7($a1)
.L7F02C1FC:
/* 060D2C 7F02C1FC 24010008 */  li    $at, 8
/* 060D30 7F02C200 10410003 */  beq   $v0, $at, .L7F02C210
/* 060D34 7F02C204 2401000A */   li    $at, 10
/* 060D38 7F02C208 54410005 */  bnel  $v0, $at, .L7F02C220
/* 060D3C 7F02C20C 24010019 */   li    $at, 25
.L7F02C210:
/* 060D40 7F02C210 8CAE002C */  lw    $t6, 0x2c($a1)
/* 060D44 7F02C214 10000008 */  b     .L7F02C238
/* 060D48 7F02C218 C5CC000C */   lwc1  $f12, 0xc($t6)
/* 060D4C 7F02C21C 24010019 */  li    $at, 25
.L7F02C220:
/* 060D50 7F02C220 54410006 */  bnel  $v0, $at, .L7F02C23C
/* 060D54 7F02C224 46106032 */   c.eq.s $f12, $f16
/* 060D58 7F02C228 8CA2002C */  lw    $v0, 0x2c($a1)
/* 060D5C 7F02C22C 50400003 */  beql  $v0, $zero, .L7F02C23C
/* 060D60 7F02C230 46106032 */   c.eq.s $f12, $f16
/* 060D64 7F02C234 C44C000C */  lwc1  $f12, 0xc($v0)
.L7F02C238:
/* 060D68 7F02C238 46106032 */  c.eq.s $f12, $f16
.L7F02C23C:
/* 060D6C 7F02C23C 00000000 */  nop   
/* 060D70 7F02C240 4501000C */  bc1t  .L7F02C274
/* 060D74 7F02C244 00000000 */   nop   
/* 060D78 7F02C248 8CAF001C */  lw    $t7, 0x1c($a1)
/* 060D7C 7F02C24C 81F80024 */  lb    $t8, 0x24($t7)
/* 060D80 7F02C250 53000003 */  beql  $t8, $zero, .L7F02C260
/* 060D84 7F02C254 460C1080 */   add.s $f2, $f2, $f12
/* 060D88 7F02C258 460C7301 */  sub.s $f12, $f14, $f12
/* 060D8C 7F02C25C 460C1080 */  add.s $f2, $f2, $f12
.L7F02C260:
/* 060D90 7F02C260 4602703E */  c.le.s $f14, $f2
/* 060D94 7F02C264 00000000 */  nop   
/* 060D98 7F02C268 45000002 */  bc1f  .L7F02C274
/* 060D9C 7F02C26C 00000000 */   nop   
/* 060DA0 7F02C270 460E1081 */  sub.s $f2, $f2, $f14
.L7F02C274:
/* 060DA4 7F02C274 03E00008 */  jr    $ra
/* 060DA8 7F02C278 46001006 */   mov.s $f0, $f2
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02C27C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051E9C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02C27C
/* 060DAC 7F02C27C C4840144 */  lwc1  $f4, 0x144($a0)
/* 060DB0 7F02C280 C4860148 */  lwc1  $f6, 0x148($a0)
/* 060DB4 7F02C284 44804000 */  mtc1  $zero, $f8
/* 060DB8 7F02C288 3C018005 */  lui   $at, %hi(D_80051E9C)
/* 060DBC 7F02C28C 46062080 */  add.s $f2, $f4, $f6
/* 060DC0 7F02C290 4608103C */  c.lt.s $f2, $f8
/* 060DC4 7F02C294 00000000 */  nop   
/* 060DC8 7F02C298 45000003 */  bc1f  .L7F02C2A8
/* 060DCC 7F02C29C 00000000 */   nop   
/* 060DD0 7F02C2A0 C42A1E9C */  lwc1  $f10, %lo(D_80051E9C)($at)
/* 060DD4 7F02C2A4 460A1080 */  add.s $f2, $f2, $f10
.L7F02C2A8:
/* 060DD8 7F02C2A8 03E00008 */  jr    $ra
/* 060DDC 7F02C2AC 46001006 */   mov.s $f0, $f2
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02C2B0(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80051EA0
.word 0x3d80adfd /*0.062831856*/
glabel D_80051EA4
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EA8
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EAC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F02C2B0
/* 060DE0 7F02C2B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 060DE4 7F02C2B4 AFA7003C */  sw    $a3, 0x3c($sp)
/* 060DE8 7F02C2B8 24010002 */  li    $at, 2
/* 060DEC 7F02C2BC 00803825 */  move  $a3, $a0
/* 060DF0 7F02C2C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 060DF4 7F02C2C4 AFA40030 */  sw    $a0, 0x30($sp)
/* 060DF8 7F02C2C8 AFA50034 */  sw    $a1, 0x34($sp)
/* 060DFC 7F02C2CC 10A10077 */  beq   $a1, $at, .L7F02C4AC
/* 060E00 7F02C2D0 AFA60038 */   sw    $a2, 0x38($sp)
/* 060E04 7F02C2D4 8C84001C */  lw    $a0, 0x1c($a0)
/* 060E08 7F02C2D8 AFA70030 */  sw    $a3, 0x30($sp)
/* 060E0C 7F02C2DC 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 060E10 7F02C2E0 AFA4002C */   sw    $a0, 0x2c($sp)
/* 060E14 7F02C2E4 E7A00028 */  swc1  $f0, 0x28($sp)
/* 060E18 7F02C2E8 0FC1B320 */  jal   getsubroty
/* 060E1C 7F02C2EC 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060E20 7F02C2F0 3C018005 */  lui   $at, %hi(D_80051EA0)
/* 060E24 7F02C2F4 C4241EA0 */  lwc1  $f4, %lo(D_80051EA0)($at)
/* 060E28 7F02C2F8 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 060E2C 7F02C2FC 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 060E30 7F02C300 C42A8378 */  lwc1  $f10, %lo(g_GlobalTimerDelta)($at)
/* 060E34 7F02C304 46062202 */  mul.s $f8, $f4, $f6
/* 060E38 7F02C308 8FAF002C */  lw    $t7, 0x2c($sp)
/* 060E3C 7F02C30C 8FA70030 */  lw    $a3, 0x30($sp)
/* 060E40 7F02C310 24010008 */  li    $at, 8
/* 060E44 7F02C314 C5E400A4 */  lwc1  $f4, 0xa4($t7)
/* 060E48 7F02C318 80E20007 */  lb    $v0, 7($a3)
/* 060E4C 7F02C31C 46000306 */  mov.s $f12, $f0
/* 060E50 7F02C320 460A4482 */  mul.s $f18, $f8, $f10
/* 060E54 7F02C324 00E02025 */  move  $a0, $a3
/* 060E58 7F02C328 46049382 */  mul.s $f14, $f18, $f4
/* 060E5C 7F02C32C 5441000A */  bnel  $v0, $at, .L7F02C358
/* 060E60 7F02C330 24010001 */   li    $at, 1
/* 060E64 7F02C334 8CE5004C */  lw    $a1, 0x4c($a3)
/* 060E68 7F02C338 8CE60050 */  lw    $a2, 0x50($a3)
/* 060E6C 7F02C33C E7AE0018 */  swc1  $f14, 0x18($sp)
/* 060E70 7F02C340 0FC0942F */  jal   chrlvDistanceToChrRelated
/* 060E74 7F02C344 E7AC0020 */   swc1  $f12, 0x20($sp)
/* 060E78 7F02C348 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060E7C 7F02C34C 10000015 */  b     .L7F02C3A4
/* 060E80 7F02C350 C7AE0018 */   lwc1  $f14, 0x18($sp)
/* 060E84 7F02C354 24010001 */  li    $at, 1
.L7F02C358:
/* 060E88 7F02C358 14410009 */  bne   $v0, $at, .L7F02C380
/* 060E8C 7F02C35C 00E02025 */   move  $a0, $a3
/* 060E90 7F02C360 8CE50030 */  lw    $a1, 0x30($a3)
/* 060E94 7F02C364 8CE60034 */  lw    $a2, 0x34($a3)
/* 060E98 7F02C368 E7AE0018 */  swc1  $f14, 0x18($sp)
/* 060E9C 7F02C36C 0FC0942F */  jal   chrlvDistanceToChrRelated
/* 060EA0 7F02C370 E7AC0020 */   swc1  $f12, 0x20($sp)
/* 060EA4 7F02C374 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060EA8 7F02C378 1000000A */  b     .L7F02C3A4
/* 060EAC 7F02C37C C7AE0018 */   lwc1  $f14, 0x18($sp)
.L7F02C380:
/* 060EB0 7F02C380 AFA70030 */  sw    $a3, 0x30($sp)
/* 060EB4 7F02C384 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 060EB8 7F02C388 0FC225E6 */  jal   get_curplayer_positiondata
/* 060EBC 7F02C38C E7AE0018 */   swc1  $f14, 0x18($sp)
/* 060EC0 7F02C390 8FA40030 */  lw    $a0, 0x30($sp)
/* 060EC4 7F02C394 0FC0CAF6 */  jal   get_distance_actor_to_position
/* 060EC8 7F02C398 24450008 */   addiu $a1, $v0, 8
/* 060ECC 7F02C39C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060ED0 7F02C3A0 C7AE0018 */  lwc1  $f14, 0x18($sp)
.L7F02C3A4:
/* 060ED4 7F02C3A4 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 060ED8 7F02C3A8 44808000 */  mtc1  $zero, $f16
/* 060EDC 7F02C3AC 3C018005 */  lui   $at, %hi(D_80051EA4)
/* 060EE0 7F02C3B0 46060081 */  sub.s $f2, $f0, $f6
/* 060EE4 7F02C3B4 4610103C */  c.lt.s $f2, $f16
/* 060EE8 7F02C3B8 00000000 */  nop   
/* 060EEC 7F02C3BC 45020004 */  bc1fl .L7F02C3D0
/* 060EF0 7F02C3C0 460E103C */   c.lt.s $f2, $f14
/* 060EF4 7F02C3C4 C4201EA4 */  lwc1  $f0, %lo(D_80051EA4)($at)
/* 060EF8 7F02C3C8 46001080 */  add.s $f2, $f2, $f0
/* 060EFC 7F02C3CC 460E103C */  c.lt.s $f2, $f14
.L7F02C3D0:
/* 060F00 7F02C3D0 3C018005 */  lui   $at, %hi(D_80051EA8)
/* 060F04 7F02C3D4 C4201EA8 */  lwc1  $f0, %lo(D_80051EA8)($at)
/* 060F08 7F02C3D8 45030008 */  bc1tl .L7F02C3FC
/* 060F0C 7F02C3DC 46026300 */   add.s $f12, $f12, $f2
/* 060F10 7F02C3E0 460E0201 */  sub.s $f8, $f0, $f14
/* 060F14 7F02C3E4 3C018005 */  lui   $at, %hi(D_80051EAC)
/* 060F18 7F02C3E8 4602403C */  c.lt.s $f8, $f2
/* 060F1C 7F02C3EC 00000000 */  nop   
/* 060F20 7F02C3F0 4500000D */  bc1f  .L7F02C428
/* 060F24 7F02C3F4 00000000 */   nop   
/* 060F28 7F02C3F8 46026300 */  add.s $f12, $f12, $f2
.L7F02C3FC:
/* 060F2C 7F02C3FC 460C003E */  c.le.s $f0, $f12
/* 060F30 7F02C400 00000000 */  nop   
/* 060F34 7F02C404 45020003 */  bc1fl .L7F02C414
/* 060F38 7F02C408 44056000 */   mfc1  $a1, $f12
/* 060F3C 7F02C40C 46006301 */  sub.s $f12, $f12, $f0
/* 060F40 7F02C410 44056000 */  mfc1  $a1, $f12
.L7F02C414:
/* 060F44 7F02C414 0FC1B34F */  jal   setsubroty
/* 060F48 7F02C418 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060F4C 7F02C41C 24180003 */  li    $t8, 3
/* 060F50 7F02C420 1000001A */  b     .L7F02C48C
/* 060F54 7F02C424 AFB80034 */   sw    $t8, 0x34($sp)
.L7F02C428:
/* 060F58 7F02C428 C42A1EAC */  lwc1  $f10, %lo(D_80051EAC)($at)
/* 060F5C 7F02C42C 460A103C */  c.lt.s $f2, $f10
/* 060F60 7F02C430 00000000 */  nop   
/* 060F64 7F02C434 4502000D */  bc1fl .L7F02C46C
/* 060F68 7F02C438 460E6301 */   sub.s $f12, $f12, $f14
/* 060F6C 7F02C43C 460E6300 */  add.s $f12, $f12, $f14
/* 060F70 7F02C440 460C003E */  c.le.s $f0, $f12
/* 060F74 7F02C444 00000000 */  nop   
/* 060F78 7F02C448 45020003 */  bc1fl .L7F02C458
/* 060F7C 7F02C44C 44056000 */   mfc1  $a1, $f12
/* 060F80 7F02C450 46006301 */  sub.s $f12, $f12, $f0
/* 060F84 7F02C454 44056000 */  mfc1  $a1, $f12
.L7F02C458:
/* 060F88 7F02C458 0FC1B34F */  jal   setsubroty
/* 060F8C 7F02C45C 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060F90 7F02C460 1000000B */  b     .L7F02C490
/* 060F94 7F02C464 C7B20028 */   lwc1  $f18, 0x28($sp)
/* 060F98 7F02C468 460E6301 */  sub.s $f12, $f12, $f14
.L7F02C46C:
/* 060F9C 7F02C46C 4610603C */  c.lt.s $f12, $f16
/* 060FA0 7F02C470 00000000 */  nop   
/* 060FA4 7F02C474 45020003 */  bc1fl .L7F02C484
/* 060FA8 7F02C478 44056000 */   mfc1  $a1, $f12
/* 060FAC 7F02C47C 46006300 */  add.s $f12, $f12, $f0
/* 060FB0 7F02C480 44056000 */  mfc1  $a1, $f12
.L7F02C484:
/* 060FB4 7F02C484 0FC1B34F */  jal   setsubroty
/* 060FB8 7F02C488 8FA4002C */   lw    $a0, 0x2c($sp)
.L7F02C48C:
/* 060FBC 7F02C48C C7B20028 */  lwc1  $f18, 0x28($sp)
.L7F02C490:
/* 060FC0 7F02C490 C7A40038 */  lwc1  $f4, 0x38($sp)
/* 060FC4 7F02C494 24190002 */  li    $t9, 2
/* 060FC8 7F02C498 4612203E */  c.le.s $f4, $f18
/* 060FCC 7F02C49C 00000000 */  nop   
/* 060FD0 7F02C4A0 45020003 */  bc1fl .L7F02C4B0
/* 060FD4 7F02C4A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 060FD8 7F02C4A8 AFB90034 */  sw    $t9, 0x34($sp)
.L7F02C4AC:
/* 060FDC 7F02C4AC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02C4B0:
/* 060FE0 7F02C4B0 8FA20034 */  lw    $v0, 0x34($sp)
/* 060FE4 7F02C4B4 27BD0030 */  addiu $sp, $sp, 0x30
/* 060FE8 7F02C4B8 03E00008 */  jr    $ra
/* 060FEC 7F02C4BC 00000000 */   nop   
)
#endif
#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_80051EA0
.word 0x3d80adfd /*0.062831856*/
glabel D_80051EA4
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EA8
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EAC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F02C2B0
/* 060DE0 7F02C2B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 060DE4 7F02C2B4 AFA7003C */  sw    $a3, 0x3c($sp)
/* 060DE8 7F02C2B8 24010002 */  li    $at, 2
/* 060DEC 7F02C2BC 00803825 */  move  $a3, $a0
/* 060DF0 7F02C2C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 060DF4 7F02C2C4 AFA40030 */  sw    $a0, 0x30($sp)
/* 060DF8 7F02C2C8 AFA50034 */  sw    $a1, 0x34($sp)
/* 060DFC 7F02C2CC 10A10077 */  beq   $a1, $at, .L7F02C4AC
/* 060E00 7F02C2D0 AFA60038 */   sw    $a2, 0x38($sp)
/* 060E04 7F02C2D4 8C84001C */  lw    $a0, 0x1c($a0)
/* 060E08 7F02C2D8 AFA70030 */  sw    $a3, 0x30($sp)
/* 060E0C 7F02C2DC 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 060E10 7F02C2E0 AFA4002C */   sw    $a0, 0x2c($sp)
/* 060E14 7F02C2E4 E7A00028 */  swc1  $f0, 0x28($sp)
/* 060E18 7F02C2E8 0FC1B320 */  jal   getsubroty
/* 060E1C 7F02C2EC 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060E20 7F02C2F0 3C018005 */  lui   $at, %hi(D_80051EA0)
/* 060E24 7F02C2F4 C4241EA0 */  lwc1  $f4, %lo(D_80051EA0)($at)
/* 060E28 7F02C2F8 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 060E2C 7F02C2FC 3C018005 */  lui   $at, %hi(g_JP_GlobalTimerDelta)
/* 060E30 7F02C300 C42A8378 */  lwc1  $f10, %lo(g_JP_GlobalTimerDelta)($at)
/* 060E34 7F02C304 46062202 */  mul.s $f8, $f4, $f6
/* 060E38 7F02C308 8FAF002C */  lw    $t7, 0x2c($sp)
/* 060E3C 7F02C30C 8FA70030 */  lw    $a3, 0x30($sp)
/* 060E40 7F02C310 24010008 */  li    $at, 8
/* 060E44 7F02C314 C5E400A4 */  lwc1  $f4, 0xa4($t7)
/* 060E48 7F02C318 80E20007 */  lb    $v0, 7($a3)
/* 060E4C 7F02C31C 46000306 */  mov.s $f12, $f0
/* 060E50 7F02C320 460A4482 */  mul.s $f18, $f8, $f10
/* 060E54 7F02C324 00E02025 */  move  $a0, $a3
/* 060E58 7F02C328 46049382 */  mul.s $f14, $f18, $f4
/* 060E5C 7F02C32C 5441000A */  bnel  $v0, $at, .L7F02C358
/* 060E60 7F02C330 24010001 */   li    $at, 1
/* 060E64 7F02C334 8CE5004C */  lw    $a1, 0x4c($a3)
/* 060E68 7F02C338 8CE60050 */  lw    $a2, 0x50($a3)
/* 060E6C 7F02C33C E7AE0018 */  swc1  $f14, 0x18($sp)
/* 060E70 7F02C340 0FC0942F */  jal   chrlvDistanceToChrRelated
/* 060E74 7F02C344 E7AC0020 */   swc1  $f12, 0x20($sp)
/* 060E78 7F02C348 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060E7C 7F02C34C 10000015 */  b     .L7F02C3A4
/* 060E80 7F02C350 C7AE0018 */   lwc1  $f14, 0x18($sp)
/* 060E84 7F02C354 24010001 */  li    $at, 1
.L7F02C358:
/* 060E88 7F02C358 14410009 */  bne   $v0, $at, .L7F02C380
/* 060E8C 7F02C35C 00E02025 */   move  $a0, $a3
/* 060E90 7F02C360 8CE50030 */  lw    $a1, 0x30($a3)
/* 060E94 7F02C364 8CE60034 */  lw    $a2, 0x34($a3)
/* 060E98 7F02C368 E7AE0018 */  swc1  $f14, 0x18($sp)
/* 060E9C 7F02C36C 0FC0942F */  jal   chrlvDistanceToChrRelated
/* 060EA0 7F02C370 E7AC0020 */   swc1  $f12, 0x20($sp)
/* 060EA4 7F02C374 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060EA8 7F02C378 1000000A */  b     .L7F02C3A4
/* 060EAC 7F02C37C C7AE0018 */   lwc1  $f14, 0x18($sp)
.L7F02C380:
/* 060EB0 7F02C380 AFA70030 */  sw    $a3, 0x30($sp)
/* 060EB4 7F02C384 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 060EB8 7F02C388 0FC225E6 */  jal   get_curplayer_positiondata
/* 060EBC 7F02C38C E7AE0018 */   swc1  $f14, 0x18($sp)
/* 060EC0 7F02C390 8FA40030 */  lw    $a0, 0x30($sp)
/* 060EC4 7F02C394 0FC0CAF6 */  jal   get_distance_actor_to_position
/* 060EC8 7F02C398 24450008 */   addiu $a1, $v0, 8
/* 060ECC 7F02C39C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060ED0 7F02C3A0 C7AE0018 */  lwc1  $f14, 0x18($sp)
.L7F02C3A4:
/* 060ED4 7F02C3A4 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 060ED8 7F02C3A8 44808000 */  mtc1  $zero, $f16
/* 060EDC 7F02C3AC 3C018005 */  lui   $at, %hi(D_80051EA4)
/* 060EE0 7F02C3B0 46060081 */  sub.s $f2, $f0, $f6
/* 060EE4 7F02C3B4 4610103C */  c.lt.s $f2, $f16
/* 060EE8 7F02C3B8 00000000 */  nop   
/* 060EEC 7F02C3BC 45020004 */  bc1fl .L7F02C3D0
/* 060EF0 7F02C3C0 460E103C */   c.lt.s $f2, $f14
/* 060EF4 7F02C3C4 C4201EA4 */  lwc1  $f0, %lo(D_80051EA4)($at)
/* 060EF8 7F02C3C8 46001080 */  add.s $f2, $f2, $f0
/* 060EFC 7F02C3CC 460E103C */  c.lt.s $f2, $f14
.L7F02C3D0:
/* 060F00 7F02C3D0 3C018005 */  lui   $at, %hi(D_80051EA8)
/* 060F04 7F02C3D4 C4201EA8 */  lwc1  $f0, %lo(D_80051EA8)($at)
/* 060F08 7F02C3D8 45030008 */  bc1tl .L7F02C3FC
/* 060F0C 7F02C3DC 46026300 */   add.s $f12, $f12, $f2
/* 060F10 7F02C3E0 460E0201 */  sub.s $f8, $f0, $f14
/* 060F14 7F02C3E4 3C018005 */  lui   $at, %hi(D_80051EAC)
/* 060F18 7F02C3E8 4602403C */  c.lt.s $f8, $f2
/* 060F1C 7F02C3EC 00000000 */  nop   
/* 060F20 7F02C3F0 4500000D */  bc1f  .L7F02C428
/* 060F24 7F02C3F4 00000000 */   nop   
/* 060F28 7F02C3F8 46026300 */  add.s $f12, $f12, $f2
.L7F02C3FC:
/* 060F2C 7F02C3FC 460C003E */  c.le.s $f0, $f12
/* 060F30 7F02C400 00000000 */  nop   
/* 060F34 7F02C404 45020003 */  bc1fl .L7F02C414
/* 060F38 7F02C408 44056000 */   mfc1  $a1, $f12
/* 060F3C 7F02C40C 46006301 */  sub.s $f12, $f12, $f0
/* 060F40 7F02C410 44056000 */  mfc1  $a1, $f12
.L7F02C414:
/* 060F44 7F02C414 0FC1B34F */  jal   setsubroty
/* 060F48 7F02C418 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060F4C 7F02C41C 24180003 */  li    $t8, 3
/* 060F50 7F02C420 1000001A */  b     .L7F02C48C
/* 060F54 7F02C424 AFB80034 */   sw    $t8, 0x34($sp)
.L7F02C428:
/* 060F58 7F02C428 C42A1EAC */  lwc1  $f10, %lo(D_80051EAC)($at)
/* 060F5C 7F02C42C 460A103C */  c.lt.s $f2, $f10
/* 060F60 7F02C430 00000000 */  nop   
/* 060F64 7F02C434 4502000D */  bc1fl .L7F02C46C
/* 060F68 7F02C438 460E6301 */   sub.s $f12, $f12, $f14
/* 060F6C 7F02C43C 460E6300 */  add.s $f12, $f12, $f14
/* 060F70 7F02C440 460C003E */  c.le.s $f0, $f12
/* 060F74 7F02C444 00000000 */  nop   
/* 060F78 7F02C448 45020003 */  bc1fl .L7F02C458
/* 060F7C 7F02C44C 44056000 */   mfc1  $a1, $f12
/* 060F80 7F02C450 46006301 */  sub.s $f12, $f12, $f0
/* 060F84 7F02C454 44056000 */  mfc1  $a1, $f12
.L7F02C458:
/* 060F88 7F02C458 0FC1B34F */  jal   setsubroty
/* 060F8C 7F02C45C 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060F90 7F02C460 1000000B */  b     .L7F02C490
/* 060F94 7F02C464 C7B20028 */   lwc1  $f18, 0x28($sp)
/* 060F98 7F02C468 460E6301 */  sub.s $f12, $f12, $f14
.L7F02C46C:
/* 060F9C 7F02C46C 4610603C */  c.lt.s $f12, $f16
/* 060FA0 7F02C470 00000000 */  nop   
/* 060FA4 7F02C474 45020003 */  bc1fl .L7F02C484
/* 060FA8 7F02C478 44056000 */   mfc1  $a1, $f12
/* 060FAC 7F02C47C 46006300 */  add.s $f12, $f12, $f0
/* 060FB0 7F02C480 44056000 */  mfc1  $a1, $f12
.L7F02C484:
/* 060FB4 7F02C484 0FC1B34F */  jal   setsubroty
/* 060FB8 7F02C488 8FA4002C */   lw    $a0, 0x2c($sp)
.L7F02C48C:
/* 060FBC 7F02C48C C7B20028 */  lwc1  $f18, 0x28($sp)
.L7F02C490:
/* 060FC0 7F02C490 C7A40038 */  lwc1  $f4, 0x38($sp)
/* 060FC4 7F02C494 24190002 */  li    $t9, 2
/* 060FC8 7F02C498 4612203E */  c.le.s $f4, $f18
/* 060FCC 7F02C49C 00000000 */  nop   
/* 060FD0 7F02C4A0 45020003 */  bc1fl .L7F02C4B0
/* 060FD4 7F02C4A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 060FD8 7F02C4A8 AFB90034 */  sw    $t9, 0x34($sp)
.L7F02C4AC:
/* 060FDC 7F02C4AC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02C4B0:
/* 060FE0 7F02C4B0 8FA20034 */  lw    $v0, 0x34($sp)
/* 060FE4 7F02C4B4 27BD0030 */  addiu $sp, $sp, 0x30
/* 060FE8 7F02C4B8 03E00008 */  jr    $ra
/* 060FEC 7F02C4BC 00000000 */   nop   
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80051EA0
.word 0x3d80adfd /*0.062831856*/
glabel D_80051EA4
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EA8
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EAC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F02C2B0
/* 060DE0 7F02C2B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 060DE4 7F02C2B4 AFA7003C */  sw    $a3, 0x3c($sp)
/* 060DE8 7F02C2B8 24010002 */  li    $at, 2
/* 060DEC 7F02C2BC 00803825 */  move  $a3, $a0
/* 060DF0 7F02C2C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 060DF4 7F02C2C4 AFA40030 */  sw    $a0, 0x30($sp)
/* 060DF8 7F02C2C8 AFA50034 */  sw    $a1, 0x34($sp)
/* 060DFC 7F02C2CC 10A10077 */  beq   $a1, $at, .L7F02C4AC
/* 060E00 7F02C2D0 AFA60038 */   sw    $a2, 0x38($sp)
/* 060E04 7F02C2D4 8C84001C */  lw    $a0, 0x1c($a0)
/* 060E08 7F02C2D8 AFA70030 */  sw    $a3, 0x30($sp)
/* 060E0C 7F02C2DC 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 060E10 7F02C2E0 AFA4002C */   sw    $a0, 0x2c($sp)
/* 060E14 7F02C2E4 E7A00028 */  swc1  $f0, 0x28($sp)
/* 060E18 7F02C2E8 0FC1B320 */  jal   getsubroty
/* 060E1C 7F02C2EC 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060E20 7F02C2F0 3C018005 */  lui   $at, %hi(D_80051EA0)
/* 060E24 7F02C2F4 C4241EA0 */  lwc1  $f4, %lo(D_80051EA0)($at)
/* 060E28 7F02C2F8 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 060E2C 7F02C2FC 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 060E30 7F02C300 C42A8378 */  lwc1  $f10, %lo(g_GlobalTimerDelta)($at)
/* 060E34 7F02C304 46062202 */  mul.s $f8, $f4, $f6
/* 060E38 7F02C308 8FAF002C */  lw    $t7, 0x2c($sp)
/* 060E3C 7F02C30C 8FA70030 */  lw    $a3, 0x30($sp)
/* 060E40 7F02C310 24010008 */  li    $at, 8
/* 060E44 7F02C314 C5E400A4 */  lwc1  $f4, 0xa4($t7)
/* 060E48 7F02C318 80E20007 */  lb    $v0, 7($a3)
/* 060E4C 7F02C31C 46000306 */  mov.s $f12, $f0
/* 060E50 7F02C320 460A4482 */  mul.s $f18, $f8, $f10
/* 060E54 7F02C324 00E02025 */  move  $a0, $a3
/* 060E58 7F02C328 46049382 */  mul.s $f14, $f18, $f4
/* 060E5C 7F02C32C 5441000A */  bnel  $v0, $at, .L7F02C358
/* 060E60 7F02C330 24010001 */   li    $at, 1
/* 060E64 7F02C334 8CE5004C */  lw    $a1, 0x4c($a3)
/* 060E68 7F02C338 8CE60050 */  lw    $a2, 0x50($a3)
/* 060E6C 7F02C33C E7AE0018 */  swc1  $f14, 0x18($sp)
/* 060E70 7F02C340 0FC0942F */  jal   chrlvDistanceToChrRelated
/* 060E74 7F02C344 E7AC0020 */   swc1  $f12, 0x20($sp)
/* 060E78 7F02C348 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060E7C 7F02C34C 10000015 */  b     .L7F02C3A4
/* 060E80 7F02C350 C7AE0018 */   lwc1  $f14, 0x18($sp)
/* 060E84 7F02C354 24010001 */  li    $at, 1
.L7F02C358:
/* 060E88 7F02C358 14410009 */  bne   $v0, $at, .L7F02C380
/* 060E8C 7F02C35C 00E02025 */   move  $a0, $a3
/* 060E90 7F02C360 8CE50030 */  lw    $a1, 0x30($a3)
/* 060E94 7F02C364 8CE60034 */  lw    $a2, 0x34($a3)
/* 060E98 7F02C368 E7AE0018 */  swc1  $f14, 0x18($sp)
/* 060E9C 7F02C36C 0FC0942F */  jal   chrlvDistanceToChrRelated
/* 060EA0 7F02C370 E7AC0020 */   swc1  $f12, 0x20($sp)
/* 060EA4 7F02C374 C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060EA8 7F02C378 1000000A */  b     .L7F02C3A4
/* 060EAC 7F02C37C C7AE0018 */   lwc1  $f14, 0x18($sp)
.L7F02C380:
/* 060EB0 7F02C380 AFA70030 */  sw    $a3, 0x30($sp)
/* 060EB4 7F02C384 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 060EB8 7F02C388 0FC225E6 */  jal   get_curplayer_positiondata
/* 060EBC 7F02C38C E7AE0018 */   swc1  $f14, 0x18($sp)
/* 060EC0 7F02C390 8FA40030 */  lw    $a0, 0x30($sp)
/* 060EC4 7F02C394 0FC0CAF6 */  jal   get_distance_actor_to_position
/* 060EC8 7F02C398 24450008 */   addiu $a1, $v0, 8
/* 060ECC 7F02C39C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 060ED0 7F02C3A0 C7AE0018 */  lwc1  $f14, 0x18($sp)
.L7F02C3A4:
/* 060ED4 7F02C3A4 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 060ED8 7F02C3A8 44808000 */  mtc1  $zero, $f16
/* 060EDC 7F02C3AC 3C018005 */  lui   $at, %hi(D_80051EA4)
/* 060EE0 7F02C3B0 46060081 */  sub.s $f2, $f0, $f6
/* 060EE4 7F02C3B4 4610103C */  c.lt.s $f2, $f16
/* 060EE8 7F02C3B8 00000000 */  nop   
/* 060EEC 7F02C3BC 45020004 */  bc1fl .L7F02C3D0
/* 060EF0 7F02C3C0 460E103C */   c.lt.s $f2, $f14
/* 060EF4 7F02C3C4 C4201EA4 */  lwc1  $f0, %lo(D_80051EA4)($at)
/* 060EF8 7F02C3C8 46001080 */  add.s $f2, $f2, $f0
/* 060EFC 7F02C3CC 460E103C */  c.lt.s $f2, $f14
.L7F02C3D0:
/* 060F00 7F02C3D0 3C018005 */  lui   $at, %hi(D_80051EA8)
/* 060F04 7F02C3D4 C4201EA8 */  lwc1  $f0, %lo(D_80051EA8)($at)
/* 060F08 7F02C3D8 45030008 */  bc1tl .L7F02C3FC
/* 060F0C 7F02C3DC 46026300 */   add.s $f12, $f12, $f2
/* 060F10 7F02C3E0 460E0201 */  sub.s $f8, $f0, $f14
/* 060F14 7F02C3E4 3C018005 */  lui   $at, %hi(D_80051EAC)
/* 060F18 7F02C3E8 4602403C */  c.lt.s $f8, $f2
/* 060F1C 7F02C3EC 00000000 */  nop   
/* 060F20 7F02C3F0 4500000D */  bc1f  .L7F02C428
/* 060F24 7F02C3F4 00000000 */   nop   
/* 060F28 7F02C3F8 46026300 */  add.s $f12, $f12, $f2
.L7F02C3FC:
/* 060F2C 7F02C3FC 460C003E */  c.le.s $f0, $f12
/* 060F30 7F02C400 00000000 */  nop   
/* 060F34 7F02C404 45020003 */  bc1fl .L7F02C414
/* 060F38 7F02C408 44056000 */   mfc1  $a1, $f12
/* 060F3C 7F02C40C 46006301 */  sub.s $f12, $f12, $f0
/* 060F40 7F02C410 44056000 */  mfc1  $a1, $f12
.L7F02C414:
/* 060F44 7F02C414 0FC1B34F */  jal   setsubroty
/* 060F48 7F02C418 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060F4C 7F02C41C 24180003 */  li    $t8, 3
/* 060F50 7F02C420 1000001A */  b     .L7F02C48C
/* 060F54 7F02C424 AFB80034 */   sw    $t8, 0x34($sp)
.L7F02C428:
/* 060F58 7F02C428 C42A1EAC */  lwc1  $f10, %lo(D_80051EAC)($at)
/* 060F5C 7F02C42C 460A103C */  c.lt.s $f2, $f10
/* 060F60 7F02C430 00000000 */  nop   
/* 060F64 7F02C434 4502000D */  bc1fl .L7F02C46C
/* 060F68 7F02C438 460E6301 */   sub.s $f12, $f12, $f14
/* 060F6C 7F02C43C 460E6300 */  add.s $f12, $f12, $f14
/* 060F70 7F02C440 460C003E */  c.le.s $f0, $f12
/* 060F74 7F02C444 00000000 */  nop   
/* 060F78 7F02C448 45020003 */  bc1fl .L7F02C458
/* 060F7C 7F02C44C 44056000 */   mfc1  $a1, $f12
/* 060F80 7F02C450 46006301 */  sub.s $f12, $f12, $f0
/* 060F84 7F02C454 44056000 */  mfc1  $a1, $f12
.L7F02C458:
/* 060F88 7F02C458 0FC1B34F */  jal   setsubroty
/* 060F8C 7F02C45C 8FA4002C */   lw    $a0, 0x2c($sp)
/* 060F90 7F02C460 1000000B */  b     .L7F02C490
/* 060F94 7F02C464 C7B20028 */   lwc1  $f18, 0x28($sp)
/* 060F98 7F02C468 460E6301 */  sub.s $f12, $f12, $f14
.L7F02C46C:
/* 060F9C 7F02C46C 4610603C */  c.lt.s $f12, $f16
/* 060FA0 7F02C470 00000000 */  nop   
/* 060FA4 7F02C474 45020003 */  bc1fl .L7F02C484
/* 060FA8 7F02C478 44056000 */   mfc1  $a1, $f12
/* 060FAC 7F02C47C 46006300 */  add.s $f12, $f12, $f0
/* 060FB0 7F02C480 44056000 */  mfc1  $a1, $f12
.L7F02C484:
/* 060FB4 7F02C484 0FC1B34F */  jal   setsubroty
/* 060FB8 7F02C488 8FA4002C */   lw    $a0, 0x2c($sp)
.L7F02C48C:
/* 060FBC 7F02C48C C7B20028 */  lwc1  $f18, 0x28($sp)
.L7F02C490:
/* 060FC0 7F02C490 C7A40038 */  lwc1  $f4, 0x38($sp)
/* 060FC4 7F02C494 24190002 */  li    $t9, 2
/* 060FC8 7F02C498 4612203E */  c.le.s $f4, $f18
/* 060FCC 7F02C49C 00000000 */  nop   
/* 060FD0 7F02C4A0 45020003 */  bc1fl .L7F02C4B0
/* 060FD4 7F02C4A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 060FD8 7F02C4A8 AFB90034 */  sw    $t9, 0x34($sp)
.L7F02C4AC:
/* 060FDC 7F02C4AC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02C4B0:
/* 060FE0 7F02C4B0 8FA20034 */  lw    $v0, 0x34($sp)
/* 060FE4 7F02C4B4 27BD0030 */  addiu $sp, $sp, 0x30
/* 060FE8 7F02C4B8 03E00008 */  jr    $ra
/* 060FEC 7F02C4BC 00000000 */   nop   
)
#endif


#endif


#ifdef NONMATCHING
void sub_GAME_7F02C4C0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051EB0
.word 0x481c4000 /*160000.0*/
glabel D_80051EB4
.word 0x3dcccccd /*0.1*/
glabel D_80051EB8
.word 0x3f0ccccd /*0.55000001*/
glabel D_80051EBC
.word 0x3dcccccd /*0.1*/
glabel D_80051EC0
.word 0x3e19999a /*0.15000001*/
glabel D_80051EC4
.word 0x3dcccccd /*0.1*/
glabel D_80051EC8
.word 0x3d4ccccd /*0.050000001*/
glabel D_80051ECC
.word 0x3ccccccd /*0.025*/
glabel D_80051ED0
.word 0x49742400 /*1000000.0*/
glabel D_80051ED4
.word 0x3dcccccd /*0.1*/
glabel D_80051ED8
.word 0x3d4ccccd /*0.050000001*/
glabel D_80051EDC
.word 0x3f0ccccd /*0.55000001*/
glabel D_80051EE0
.word 0x3d4ccccd /*0.050000001*/
glabel D_80051EE4
.word 0x3dcccccd /*0.1*/
glabel D_80051EE8
.word 0x3f0ccccd /*0.55000001*/
glabel D_80051EEC
.word 0x3dcccccd /*0.1*/
glabel D_80051EF0
.word 0x3e19999a /*0.15000001*/
glabel D_80051EF4
.word 0x3dcccccd /*0.1*/
glabel D_80051EF8
.word 0x3d4ccccd /*0.050000001*/
glabel D_80051EFC
.word 0x40490fdb /*3.1415927*/
glabel D_80051F00
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F04
.word 0x49742400 /*1000000.0*/
glabel D_80051F08
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F0C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F10
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F14
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F18
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F1C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F20
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F24
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F28
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F02C4C0
/* 060FF0 7F02C4C0 27BDFE98 */  addiu $sp, $sp, -0x168
/* 060FF4 7F02C4C4 44808000 */  mtc1  $zero, $f16
/* 060FF8 7F02C4C8 240E0001 */  li    $t6, 1
/* 060FFC 7F02C4CC AFBF001C */  sw    $ra, 0x1c($sp)
/* 061000 7F02C4D0 AFA5016C */  sw    $a1, 0x16c($sp)
/* 061004 7F02C4D4 AFA60170 */  sw    $a2, 0x170($sp)
/* 061008 7F02C4D8 AFA70174 */  sw    $a3, 0x174($sp)
/* 06100C 7F02C4DC AFAE0154 */  sw    $t6, 0x154($sp)
/* 061010 7F02C4E0 E7B00164 */  swc1  $f16, 0x164($sp)
/* 061014 7F02C4E4 80820007 */  lb    $v0, 7($a0)
/* 061018 7F02C4E8 24010008 */  li    $at, 8
/* 06101C 7F02C4EC 24080001 */  li    $t0, 1
/* 061020 7F02C4F0 14410004 */  bne   $v0, $at, .L7F02C504
/* 061024 7F02C4F4 00001825 */   move  $v1, $zero
/* 061028 7F02C4F8 8C88004C */  lw    $t0, 0x4c($a0)
/* 06102C 7F02C4FC 10000006 */  b     .L7F02C518
/* 061030 7F02C500 8C830050 */   lw    $v1, 0x50($a0)
.L7F02C504:
/* 061034 7F02C504 24010001 */  li    $at, 1
/* 061038 7F02C508 54410004 */  bnel  $v0, $at, .L7F02C51C
/* 06103C 7F02C50C 310F0002 */   andi  $t7, $t0, 2
/* 061040 7F02C510 8C880030 */  lw    $t0, 0x30($a0)
/* 061044 7F02C514 8C830034 */  lw    $v1, 0x34($a0)
.L7F02C518:
/* 061048 7F02C518 310F0002 */  andi  $t7, $t0, 2
.L7F02C51C:
/* 06104C 7F02C51C 15E002B8 */  bnez  $t7, .L7F02D000
/* 061050 7F02C520 AFA40168 */   sw    $a0, 0x168($sp)
/* 061054 7F02C524 AFA30158 */  sw    $v1, 0x158($sp)
/* 061058 7F02C528 AFA40168 */  sw    $a0, 0x168($sp)
/* 06105C 7F02C52C AFA8015C */  sw    $t0, 0x15c($sp)
/* 061060 7F02C530 0FC225E6 */  jal   get_curplayer_positiondata
/* 061064 7F02C534 E7B00160 */   swc1  $f16, 0x160($sp)
/* 061068 7F02C538 8FA60168 */  lw    $a2, 0x168($sp)
/* 06106C 7F02C53C 24590008 */  addiu $t9, $v0, 8
/* 061070 7F02C540 8FAA015C */  lw    $t2, 0x15c($sp)
/* 061074 7F02C544 8CD80018 */  lw    $t8, 0x18($a2)
/* 061078 7F02C548 AFB90134 */  sw    $t9, 0x134($sp)
/* 06107C 7F02C54C 314B0001 */  andi  $t3, $t2, 1
/* 061080 7F02C550 AFB8013C */  sw    $t8, 0x13c($sp)
/* 061084 7F02C554 C4440008 */  lwc1  $f4, 8($v0)
/* 061088 7F02C558 C7060008 */  lwc1  $f6, 8($t8)
/* 06108C 7F02C55C C7B00160 */  lwc1  $f16, 0x160($sp)
/* 061090 7F02C560 240E0001 */  li    $t6, 1
/* 061094 7F02C564 46062201 */  sub.s $f8, $f4, $f6
/* 061098 7F02C568 314C0040 */  andi  $t4, $t2, 0x40
/* 06109C 7F02C56C E7A80150 */  swc1  $f8, 0x150($sp)
/* 0610A0 7F02C570 C44A000C */  lwc1  $f10, 0xc($v0)
/* 0610A4 7F02C574 C712000C */  lwc1  $f18, 0xc($t8)
/* 0610A8 7F02C578 46125101 */  sub.s $f4, $f10, $f18
/* 0610AC 7F02C57C C7B20150 */  lwc1  $f18, 0x150($sp)
/* 0610B0 7F02C580 E7A4014C */  swc1  $f4, 0x14c($sp)
/* 0610B4 7F02C584 C4460010 */  lwc1  $f6, 0x10($v0)
/* 0610B8 7F02C588 C7080010 */  lwc1  $f8, 0x10($t8)
/* 0610BC 7F02C58C 46129102 */  mul.s $f4, $f18, $f18
/* 0610C0 7F02C590 AFAB0028 */  sw    $t3, 0x28($sp)
/* 0610C4 7F02C594 46083281 */  sub.s $f10, $f6, $f8
/* 0610C8 7F02C598 C7A6014C */  lwc1  $f6, 0x14c($sp)
/* 0610CC 7F02C59C 46063202 */  mul.s $f8, $f6, $f6
/* 0610D0 7F02C5A0 E7AA0148 */  swc1  $f10, 0x148($sp)
/* 0610D4 7F02C5A4 C7B20148 */  lwc1  $f18, 0x148($sp)
/* 0610D8 7F02C5A8 46129182 */  mul.s $f6, $f18, $f18
/* 0610DC 7F02C5AC 46082280 */  add.s $f10, $f4, $f8
/* 0610E0 7F02C5B0 46065080 */  add.s $f2, $f10, $f6
/* 0610E4 7F02C5B4 1160000E */  beqz  $t3, .L7F02C5F0
/* 0610E8 7F02C5B8 E7A20144 */   swc1  $f2, 0x144($sp)
/* 0610EC 7F02C5BC 11800004 */  beqz  $t4, .L7F02C5D0
/* 0610F0 7F02C5C0 00C02025 */   move  $a0, $a2
/* 0610F4 7F02C5C4 240D0001 */  li    $t5, 1
/* 0610F8 7F02C5C8 1000000A */  b     .L7F02C5F4
/* 0610FC 7F02C5CC AFAD0138 */   sw    $t5, 0x138($sp)
.L7F02C5D0:
/* 061100 7F02C5D0 E7A2002C */  swc1  $f2, 0x2c($sp)
/* 061104 7F02C5D4 0FC0A52F */  jal   sub_GAME_7F0294BC
/* 061108 7F02C5D8 E7B00160 */   swc1  $f16, 0x160($sp)
/* 06110C 7F02C5DC C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 061110 7F02C5E0 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 061114 7F02C5E4 AFA20138 */  sw    $v0, 0x138($sp)
/* 061118 7F02C5E8 10000002 */  b     .L7F02C5F4
/* 06111C 7F02C5EC 8FA60168 */   lw    $a2, 0x168($sp)
.L7F02C5F0:
/* 061120 7F02C5F0 AFAE0138 */  sw    $t6, 0x138($sp)
.L7F02C5F4:
/* 061124 7F02C5F4 8FAF0028 */  lw    $t7, 0x28($sp)
/* 061128 7F02C5F8 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 06112C 7F02C5FC 27A50120 */  addiu $a1, $sp, 0x120
/* 061130 7F02C600 51E00137 */  beql  $t7, $zero, .L7F02CAE0
/* 061134 7F02C604 8CC4001C */   lw    $a0, 0x1c($a2)
/* 061138 7F02C608 8C84A0B0 */  lw    $a0, %lo(g_CurrentPlayer)($a0)
/* 06113C 7F02C60C E7A2002C */  swc1  $f2, 0x2c($sp)
/* 061140 7F02C610 0FC225E0 */  jal   bondviewGetPlayerDuckingHeightRelated
/* 061144 7F02C614 E7B00160 */   swc1  $f16, 0x160($sp)
/* 061148 7F02C618 8FB80168 */  lw    $t8, 0x168($sp)
/* 06114C 7F02C61C E7A00130 */  swc1  $f0, 0x130($sp)
/* 061150 7F02C620 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 061154 7F02C624 8F190014 */  lw    $t9, 0x14($t8)
/* 061158 7F02C628 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 06115C 7F02C62C 3C018005 */  lui   $at, %hi(D_80051EB0)
/* 061160 7F02C630 33290020 */  andi  $t1, $t9, 0x20
/* 061164 7F02C634 11200085 */  beqz  $t1, .L7F02C84C
/* 061168 7F02C638 00000000 */   nop   
/* 06116C 7F02C63C 3C018005 */  lui   $at, %hi(D_80051EB0)
/* 061170 7F02C640 C4241EB0 */  lwc1  $f4, %lo(D_80051EB0)($at)
/* 061174 7F02C644 8FAA0134 */  lw    $t2, 0x134($sp)
/* 061178 7F02C648 4604103C */  c.lt.s $f2, $f4
/* 06117C 7F02C64C 00000000 */  nop   
/* 061180 7F02C650 45000063 */  bc1f  .L7F02C7E0
/* 061184 7F02C654 00000000 */   nop   
/* 061188 7F02C658 46000200 */  add.s $f8, $f0, $f0
/* 06118C 7F02C65C C54C0004 */  lwc1  $f12, 4($t2)
/* 061190 7F02C660 8FAB013C */  lw    $t3, 0x13c($sp)
/* 061194 7F02C664 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 061198 7F02C668 46086481 */  sub.s $f18, $f12, $f8
/* 06119C 7F02C66C C562000C */  lwc1  $f2, 0xc($t3)
/* 0611A0 7F02C670 4612103C */  c.lt.s $f2, $f18
/* 0611A4 7F02C674 00000000 */  nop   
/* 0611A8 7F02C678 4502001D */  bc1fl .L7F02C6F0
/* 0611AC 7F02C67C 44812000 */   mtc1  $at, $f4
/* 0611B0 7F02C680 0C002914 */  jal   randomGetNext
/* 0611B4 7F02C684 E7B00160 */   swc1  $f16, 0x160($sp)
/* 0611B8 7F02C688 44825000 */  mtc1  $v0, $f10
/* 0611BC 7F02C68C C7B00160 */  lwc1  $f16, 0x160($sp)
/* 0611C0 7F02C690 04410005 */  bgez  $v0, .L7F02C6A8
/* 0611C4 7F02C694 468051A0 */   cvt.s.w $f6, $f10
/* 0611C8 7F02C698 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0611CC 7F02C69C 44812000 */  mtc1  $at, $f4
/* 0611D0 7F02C6A0 00000000 */  nop   
/* 0611D4 7F02C6A4 46043180 */  add.s $f6, $f6, $f4
.L7F02C6A8:
/* 0611D8 7F02C6A8 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0611DC 7F02C6AC 44814000 */  mtc1  $at, $f8
/* 0611E0 7F02C6B0 3C018005 */  lui   $at, %hi(D_80051EB4)
/* 0611E4 7F02C6B4 C42A1EB4 */  lwc1  $f10, %lo(D_80051EB4)($at)
/* 0611E8 7F02C6B8 46083482 */  mul.s $f18, $f6, $f8
/* 0611EC 7F02C6BC C7A60178 */  lwc1  $f6, 0x178($sp)
/* 0611F0 7F02C6C0 3C018005 */  lui    $at, %hi(D_80051EB8)
/* 0611F4 7F02C6C4 46125102 */  mul.s $f4, $f10, $f18
/* 0611F8 7F02C6C8 C42A1EB8 */  lwc1  $f10, %lo(D_80051EB8)($at)
/* 0611FC 7F02C6CC 46062202 */  mul.s $f8, $f4, $f6
/* 061200 7F02C6D0 C7A40130 */  lwc1  $f4, 0x130($sp)
/* 061204 7F02C6D4 46085480 */  add.s $f18, $f10, $f8
/* 061208 7F02C6D8 C7AA014C */  lwc1  $f10, 0x14c($sp)
/* 06120C 7F02C6DC 46122182 */  mul.s $f6, $f4, $f18
/* 061210 7F02C6E0 46065201 */  sub.s $f8, $f10, $f6
/* 061214 7F02C6E4 10000113 */  b     .L7F02CB34
/* 061218 7F02C6E8 E7A8014C */   swc1  $f8, 0x14c($sp)
/* 06121C 7F02C6EC 44812000 */  mtc1  $at, $f4
.L7F02C6F0:
/* 061220 7F02C6F0 00000000 */  nop   
/* 061224 7F02C6F4 46040482 */  mul.s $f18, $f0, $f4
/* 061228 7F02C6F8 46126281 */  sub.s $f10, $f12, $f18
/* 06122C 7F02C6FC 4602503C */  c.lt.s $f10, $f2
/* 061230 7F02C700 00000000 */  nop   
/* 061234 7F02C704 4500001C */  bc1f  .L7F02C778
/* 061238 7F02C708 00000000 */   nop   
/* 06123C 7F02C70C 0C002914 */  jal   randomGetNext
/* 061240 7F02C710 E7B00160 */   swc1  $f16, 0x160($sp)
/* 061244 7F02C714 44823000 */  mtc1  $v0, $f6
/* 061248 7F02C718 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 06124C 7F02C71C 04410005 */  bgez  $v0, .L7F02C734
/* 061250 7F02C720 46803220 */   cvt.s.w $f8, $f6
/* 061254 7F02C724 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 061258 7F02C728 44812000 */  mtc1  $at, $f4
/* 06125C 7F02C72C 00000000 */  nop   
/* 061260 7F02C730 46044200 */  add.s $f8, $f8, $f4
.L7F02C734:
/* 061264 7F02C734 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 061268 7F02C738 44819000 */  mtc1  $at, $f18
/* 06126C 7F02C73C 3C018005 */  lui   $at, %hi(D_80051EBC)
/* 061270 7F02C740 C4261EBC */  lwc1  $f6, %lo(D_80051EBC)($at)
/* 061274 7F02C744 46124282 */  mul.s $f10, $f8, $f18
/* 061278 7F02C748 C7A80178 */  lwc1  $f8, 0x178($sp)
/* 06127C 7F02C74C 3C018005 */  lui   $at, %hi(D_80051EC0)
/* 061280 7F02C750 460A3102 */  mul.s $f4, $f6, $f10
/* 061284 7F02C754 C4261EC0 */  lwc1  $f6, %lo(D_80051EC0)($at)
/* 061288 7F02C758 46082482 */  mul.s $f18, $f4, $f8
/* 06128C 7F02C75C C7A40130 */  lwc1  $f4, 0x130($sp)
/* 061290 7F02C760 46123280 */  add.s $f10, $f6, $f18
/* 061294 7F02C764 C7A6014C */  lwc1  $f6, 0x14c($sp)
/* 061298 7F02C768 460A2202 */  mul.s $f8, $f4, $f10
/* 06129C 7F02C76C 46083481 */  sub.s $f18, $f6, $f8
/* 0612A0 7F02C770 100000F0 */  b     .L7F02CB34
/* 0612A4 7F02C774 E7B2014C */   swc1  $f18, 0x14c($sp)
.L7F02C778:
/* 0612A8 7F02C778 0C002914 */  jal   randomGetNext
/* 0612AC 7F02C77C E7B00160 */   swc1  $f16, 0x160($sp)
/* 0612B0 7F02C780 44822000 */  mtc1  $v0, $f4
/* 0612B4 7F02C784 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 0612B8 7F02C788 04410005 */  bgez  $v0, .L7F02C7A0
/* 0612BC 7F02C78C 468022A0 */   cvt.s.w $f10, $f4
/* 0612C0 7F02C790 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0612C4 7F02C794 44813000 */  mtc1  $at, $f6
/* 0612C8 7F02C798 00000000 */  nop   
/* 0612CC 7F02C79C 46065280 */  add.s $f10, $f10, $f6
.L7F02C7A0:
/* 0612D0 7F02C7A0 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0612D4 7F02C7A4 44814000 */  mtc1  $at, $f8
/* 0612D8 7F02C7A8 3C018005 */  lui   $at, %hi(D_80051EC4)
/* 0612DC 7F02C7AC C4241EC4 */  lwc1  $f4, %lo(D_80051EC4)($at)
/* 0612E0 7F02C7B0 46085482 */  mul.s $f18, $f10, $f8
/* 0612E4 7F02C7B4 C7AA0178 */  lwc1  $f10, 0x178($sp)
/* 0612E8 7F02C7B8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0612EC 7F02C7BC 46049182 */  mul.s $f6, $f18, $f4
/* 0612F0 7F02C7C0 44819000 */  mtc1  $at, $f18
/* 0612F4 7F02C7C4 3C014220 */  li    $at, 0x42200000 # 40.000000
/* 0612F8 7F02C7C8 460A3202 */  mul.s $f8, $f6, $f10
/* 0612FC 7F02C7CC 44813000 */  mtc1  $at, $f6
/* 061300 7F02C7D0 46124100 */  add.s $f4, $f8, $f18
/* 061304 7F02C7D4 46062282 */  mul.s $f10, $f4, $f6
/* 061308 7F02C7D8 100000D6 */  b     .L7F02CB34
/* 06130C 7F02C7DC E7AA014C */   swc1  $f10, 0x14c($sp)
.L7F02C7E0:
/* 061310 7F02C7E0 0C002914 */  jal   randomGetNext
/* 061314 7F02C7E4 E7B00160 */   swc1  $f16, 0x160($sp)
/* 061318 7F02C7E8 44824000 */  mtc1  $v0, $f8
/* 06131C 7F02C7EC C7B00160 */  lwc1  $f16, 0x160($sp)
/* 061320 7F02C7F0 04410005 */  bgez  $v0, .L7F02C808
/* 061324 7F02C7F4 468044A0 */   cvt.s.w $f18, $f8
/* 061328 7F02C7F8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 06132C 7F02C7FC 44812000 */  mtc1  $at, $f4
/* 061330 7F02C800 00000000 */  nop   
/* 061334 7F02C804 46049480 */  add.s $f18, $f18, $f4
.L7F02C808:
/* 061338 7F02C808 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 06133C 7F02C80C 44813000 */  mtc1  $at, $f6
/* 061340 7F02C810 3C018005 */  lui   $at, %hi(D_80051EC8)
/* 061344 7F02C814 C4281EC8 */  lwc1  $f8, %lo(D_80051EC8)($at)
/* 061348 7F02C818 46069282 */  mul.s $f10, $f18, $f6
/* 06134C 7F02C81C C7B20178 */  lwc1  $f18, 0x178($sp)
/* 061350 7F02C820 3C018005 */  lui   $at, %hi(D_80051ED0)
/* 061354 7F02C824 460A4102 */  mul.s $f4, $f8, $f10
/* 061358 7F02C828 C4281ECC */  lwc1  $f8, %lo(D_80051ECC)($at)
/* 06135C 7F02C82C 46122182 */  mul.s $f6, $f4, $f18
/* 061360 7F02C830 C7A40130 */  lwc1  $f4, 0x130($sp)
/* 061364 7F02C834 46064281 */  sub.s $f10, $f8, $f6
/* 061368 7F02C838 C7A8014C */  lwc1  $f8, 0x14c($sp)
/* 06136C 7F02C83C 460A2482 */  mul.s $f18, $f4, $f10
/* 061370 7F02C840 46124180 */  add.s $f6, $f8, $f18
/* 061374 7F02C844 100000BB */  b     .L7F02CB34
/* 061378 7F02C848 E7A6014C */   swc1  $f6, 0x14c($sp)
.L7F02C84C:
/* 06137C 7F02C84C C4241ED0 */  lwc1  $f4, %lo(D_80051ED0)($at)
/* 061380 7F02C850 8FAE0134 */  lw    $t6, 0x134($sp)
/* 061384 7F02C854 4602203C */  c.lt.s $f4, $f2
/* 061388 7F02C858 00000000 */  nop   
/* 06138C 7F02C85C 45020040 */  bc1fl .L7F02C960
/* 061390 7F02C860 C5CC0004 */   lwc1  $f12, 4($t6)
/* 061394 7F02C864 0C002914 */  jal   randomGetNext
/* 061398 7F02C868 E7B00160 */   swc1  $f16, 0x160($sp)
/* 06139C 7F02C86C 24010003 */  li    $at, 3
/* 0613A0 7F02C870 0041001B */  divu  $zero, $v0, $at
/* 0613A4 7F02C874 00006010 */  mfhi  $t4
/* 0613A8 7F02C878 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 0613AC 7F02C87C 1580001C */  bnez  $t4, .L7F02C8F0
/* 0613B0 7F02C880 00000000 */   nop   
/* 0613B4 7F02C884 0C002914 */  jal   randomGetNext
/* 0613B8 7F02C888 E7B00160 */   swc1  $f16, 0x160($sp)
/* 0613BC 7F02C88C 44825000 */  mtc1  $v0, $f10
/* 0613C0 7F02C890 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 0613C4 7F02C894 04410005 */  bgez  $v0, .L7F02C8AC
/* 0613C8 7F02C898 46805220 */   cvt.s.w $f8, $f10
/* 0613CC 7F02C89C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0613D0 7F02C8A0 44819000 */  mtc1  $at, $f18
/* 0613D4 7F02C8A4 00000000 */  nop   
/* 0613D8 7F02C8A8 46124200 */  add.s $f8, $f8, $f18
.L7F02C8AC:
/* 0613DC 7F02C8AC 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0613E0 7F02C8B0 44813000 */  mtc1  $at, $f6
/* 0613E4 7F02C8B4 3C018005 */  lui   $at, %hi(D_80051ED4)
/* 0613E8 7F02C8B8 C42A1ED4 */  lwc1  $f10, %lo(D_80051ED4)($at)
/* 0613EC 7F02C8BC 46064102 */  mul.s $f4, $f8, $f6
/* 0613F0 7F02C8C0 C7A80178 */  lwc1  $f8, 0x178($sp)
/* 0613F4 7F02C8C4 3C018005 */  lui   $at, %hi(D_80051ED8)
/* 0613F8 7F02C8C8 46045482 */  mul.s $f18, $f10, $f4
/* 0613FC 7F02C8CC C42A1ED8 */  lwc1  $f10, %lo(D_80051ED8)($at)
/* 061400 7F02C8D0 46089182 */  mul.s $f6, $f18, $f8
/* 061404 7F02C8D4 C7B20130 */  lwc1  $f18, 0x130($sp)
/* 061408 7F02C8D8 46065100 */  add.s $f4, $f10, $f6
/* 06140C 7F02C8DC C7AA014C */  lwc1  $f10, 0x14c($sp)
/* 061410 7F02C8E0 46049202 */  mul.s $f8, $f18, $f4
/* 061414 7F02C8E4 46085180 */  add.s $f6, $f10, $f8
/* 061418 7F02C8E8 10000092 */  b     .L7F02CB34
/* 06141C 7F02C8EC E7A6014C */   swc1  $f6, 0x14c($sp)
.L7F02C8F0:
/* 061420 7F02C8F0 0C002914 */  jal   randomGetNext
/* 061424 7F02C8F4 E7B00160 */   swc1  $f16, 0x160($sp)
/* 061428 7F02C8F8 44829000 */  mtc1  $v0, $f18
/* 06142C 7F02C8FC C7B00160 */  lwc1  $f16, 0x160($sp)
/* 061430 7F02C900 04410005 */  bgez  $v0, .L7F02C918
/* 061434 7F02C904 46809120 */   cvt.s.w $f4, $f18
/* 061438 7F02C908 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 06143C 7F02C90C 44815000 */  mtc1  $at, $f10
/* 061440 7F02C910 00000000 */  nop   
/* 061444 7F02C914 460A2100 */  add.s $f4, $f4, $f10
.L7F02C918:
/* 061448 7F02C918 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 06144C 7F02C91C 44814000 */  mtc1  $at, $f8
/* 061450 7F02C920 3C018005 */  lui   $at, %hi(D_80051EDC)
/* 061454 7F02C924 C4321EDC */  lwc1  $f18, %lo(D_80051EDC)($at)
/* 061458 7F02C928 46082182 */  mul.s $f6, $f4, $f8
/* 06145C 7F02C92C C7A40178 */  lwc1  $f4, 0x178($sp)
/* 061460 7F02C930 3C018005 */  lui   $at, %hi(D_80051EE0)
/* 061464 7F02C934 46069282 */  mul.s $f10, $f18, $f6
/* 061468 7F02C938 C4321EE0 */  lwc1  $f18, %lo(D_80051EE0)($at)
/* 06146C 7F02C93C 46045202 */  mul.s $f8, $f10, $f4
/* 061470 7F02C940 C7AA0130 */  lwc1  $f10, 0x130($sp)
/* 061474 7F02C944 46089180 */  add.s $f6, $f18, $f8
/* 061478 7F02C948 C7B2014C */  lwc1  $f18, 0x14c($sp)
/* 06147C 7F02C94C 46065102 */  mul.s $f4, $f10, $f6
/* 061480 7F02C950 46049201 */  sub.s $f8, $f18, $f4
/* 061484 7F02C954 10000077 */  b     .L7F02CB34
/* 061488 7F02C958 E7A8014C */   swc1  $f8, 0x14c($sp)
/* 06148C 7F02C95C C5CC0004 */  lwc1  $f12, 4($t6)
.L7F02C960:
/* 061490 7F02C960 8FAD013C */  lw    $t5, 0x13c($sp)
/* 061494 7F02C964 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 061498 7F02C968 46006281 */  sub.s $f10, $f12, $f0
/* 06149C 7F02C96C C5A2000C */  lwc1  $f2, 0xc($t5)
/* 0614A0 7F02C970 460A103C */  c.lt.s $f2, $f10
/* 0614A4 7F02C974 00000000 */  nop   
/* 0614A8 7F02C978 4502001D */  bc1fl .L7F02C9F0
/* 0614AC 7F02C97C 44812000 */   mtc1  $at, $f4
/* 0614B0 7F02C980 0C002914 */  jal   randomGetNext
/* 0614B4 7F02C984 E7B00160 */   swc1  $f16, 0x160($sp)
/* 0614B8 7F02C988 44823000 */  mtc1  $v0, $f6
/* 0614BC 7F02C98C C7B00160 */  lwc1  $f16, 0x160($sp)
/* 0614C0 7F02C990 04410005 */  bgez  $v0, .L7F02C9A8
/* 0614C4 7F02C994 468034A0 */   cvt.s.w $f18, $f6
/* 0614C8 7F02C998 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0614CC 7F02C99C 44812000 */  mtc1  $at, $f4
/* 0614D0 7F02C9A0 00000000 */  nop   
/* 0614D4 7F02C9A4 46049480 */  add.s $f18, $f18, $f4
.L7F02C9A8:
/* 0614D8 7F02C9A8 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0614DC 7F02C9AC 44814000 */  mtc1  $at, $f8
/* 0614E0 7F02C9B0 3C018005 */  lui   $at, %hi(D_80051EE4)
/* 0614E4 7F02C9B4 C4261EE4 */  lwc1  $f6, %lo(D_80051EE4)($at)
/* 0614E8 7F02C9B8 46089282 */  mul.s $f10, $f18, $f8
/* 0614EC 7F02C9BC C7B20178 */  lwc1  $f18, 0x178($sp)
/* 0614F0 7F02C9C0 3C018005 */  lui    $at, %hi(D_80051EE8)
/* 0614F4 7F02C9C4 460A3102 */  mul.s $f4, $f6, $f10
/* 0614F8 7F02C9C8 C4261EE8 */  lwc1  $f6, %lo(D_80051EE8)($at)
/* 0614FC 7F02C9CC 46122202 */  mul.s $f8, $f4, $f18
/* 061500 7F02C9D0 C7A40130 */  lwc1  $f4, 0x130($sp)
/* 061504 7F02C9D4 46083280 */  add.s $f10, $f6, $f8
/* 061508 7F02C9D8 C7A6014C */  lwc1  $f6, 0x14c($sp)
/* 06150C 7F02C9DC 460A2482 */  mul.s $f18, $f4, $f10
/* 061510 7F02C9E0 46123201 */  sub.s $f8, $f6, $f18
/* 061514 7F02C9E4 10000053 */  b     .L7F02CB34
/* 061518 7F02C9E8 E7A8014C */   swc1  $f8, 0x14c($sp)
/* 06151C 7F02C9EC 44812000 */  mtc1  $at, $f4
.L7F02C9F0:
/* 061520 7F02C9F0 00000000 */  nop   
/* 061524 7F02C9F4 46040282 */  mul.s $f10, $f0, $f4
/* 061528 7F02C9F8 460A6181 */  sub.s $f6, $f12, $f10
/* 06152C 7F02C9FC 4602303C */  c.lt.s $f6, $f2
/* 061530 7F02CA00 00000000 */  nop   
/* 061534 7F02CA04 4500001C */  bc1f  .L7F02CA78
/* 061538 7F02CA08 00000000 */   nop   
/* 06153C 7F02CA0C 0C002914 */  jal   randomGetNext
/* 061540 7F02CA10 E7B00160 */   swc1  $f16, 0x160($sp)
/* 061544 7F02CA14 44829000 */  mtc1  $v0, $f18
/* 061548 7F02CA18 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 06154C 7F02CA1C 04410005 */  bgez  $v0, .L7F02CA34
/* 061550 7F02CA20 46809220 */   cvt.s.w $f8, $f18
/* 061554 7F02CA24 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 061558 7F02CA28 44812000 */  mtc1  $at, $f4
/* 06155C 7F02CA2C 00000000 */  nop   
/* 061560 7F02CA30 46044200 */  add.s $f8, $f8, $f4
.L7F02CA34:
/* 061564 7F02CA34 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 061568 7F02CA38 44815000 */  mtc1  $at, $f10
/* 06156C 7F02CA3C 3C018005 */  lui   $at, %hi(D_80051EEC)
/* 061570 7F02CA40 C4321EEC */  lwc1  $f18, %lo(D_80051EEC)($at)
/* 061574 7F02CA44 460A4182 */  mul.s $f6, $f8, $f10
/* 061578 7F02CA48 C7A80178 */  lwc1  $f8, 0x178($sp)
/* 06157C 7F02CA4C 3C018005 */  lui   $at, %hi(D_80051EF0)
/* 061580 7F02CA50 46069102 */  mul.s $f4, $f18, $f6
/* 061584 7F02CA54 C4321EF0 */  lwc1  $f18, %lo(D_80051EF0)($at)
/* 061588 7F02CA58 46082282 */  mul.s $f10, $f4, $f8
/* 06158C 7F02CA5C C7A40130 */  lwc1  $f4, 0x130($sp)
/* 061590 7F02CA60 460A9180 */  add.s $f6, $f18, $f10
/* 061594 7F02CA64 C7B2014C */  lwc1  $f18, 0x14c($sp)
/* 061598 7F02CA68 46062202 */  mul.s $f8, $f4, $f6
/* 06159C 7F02CA6C 46089281 */  sub.s $f10, $f18, $f8
/* 0615A0 7F02CA70 10000030 */  b     .L7F02CB34
/* 0615A4 7F02CA74 E7AA014C */   swc1  $f10, 0x14c($sp)
.L7F02CA78:
/* 0615A8 7F02CA78 0C002914 */  jal   randomGetNext
/* 0615AC 7F02CA7C E7B00160 */   swc1  $f16, 0x160($sp)
/* 0615B0 7F02CA80 44822000 */  mtc1  $v0, $f4
/* 0615B4 7F02CA84 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 0615B8 7F02CA88 04410005 */  bgez  $v0, .L7F02CAA0
/* 0615BC 7F02CA8C 468021A0 */   cvt.s.w $f6, $f4
/* 0615C0 7F02CA90 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0615C4 7F02CA94 44819000 */  mtc1  $at, $f18
/* 0615C8 7F02CA98 00000000 */  nop   
/* 0615CC 7F02CA9C 46123180 */  add.s $f6, $f6, $f18
.L7F02CAA0:
/* 0615D0 7F02CAA0 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0615D4 7F02CAA4 44814000 */  mtc1  $at, $f8
/* 0615D8 7F02CAA8 3C018005 */  lui   $at, %hi(D_80051EF4)
/* 0615DC 7F02CAAC C4241EF4 */  lwc1  $f4, %lo(D_80051EF4)($at)
/* 0615E0 7F02CAB0 46083282 */  mul.s $f10, $f6, $f8
/* 0615E4 7F02CAB4 C7A60178 */  lwc1  $f6, 0x178($sp)
/* 0615E8 7F02CAB8 3C018005 */  lui   $at, %hi(D_80051EF8)
/* 0615EC 7F02CABC 46045482 */  mul.s $f18, $f10, $f4
/* 0615F0 7F02CAC0 C42A1EF8 */  lwc1  $f10, %lo(D_80051EF8)($at)
/* 0615F4 7F02CAC4 46069202 */  mul.s $f8, $f18, $f6
/* 0615F8 7F02CAC8 C7B20130 */  lwc1  $f18, 0x130($sp)
/* 0615FC 7F02CACC 460A4101 */  sub.s $f4, $f8, $f10
/* 061600 7F02CAD0 46122182 */  mul.s $f6, $f4, $f18
/* 061604 7F02CAD4 10000017 */  b     .L7F02CB34
/* 061608 7F02CAD8 E7A6014C */   swc1  $f6, 0x14c($sp)
/* 06160C 7F02CADC 8CC4001C */  lw    $a0, 0x1c($a2)
.L7F02CAE0:
/* 061610 7F02CAE0 0FC1B2E6 */  jal   getsuboffset
/* 061614 7F02CAE4 E7B00160 */   swc1  $f16, 0x160($sp)
/* 061618 7F02CAE8 8FA40168 */  lw    $a0, 0x168($sp)
/* 06161C 7F02CAEC 8FA5015C */  lw    $a1, 0x15c($sp)
/* 061620 7F02CAF0 8FA60158 */  lw    $a2, 0x158($sp)
/* 061624 7F02CAF4 0FC0CB1E */  jal   sub_GAME_7F032C78
/* 061628 7F02CAF8 27A7012C */   addiu $a3, $sp, 0x12c
/* 06162C 7F02CAFC AFA20134 */  sw    $v0, 0x134($sp)
/* 061630 7F02CB00 C4480000 */  lwc1  $f8, ($v0)
/* 061634 7F02CB04 C7AA0120 */  lwc1  $f10, 0x120($sp)
/* 061638 7F02CB08 C7A60124 */  lwc1  $f6, 0x124($sp)
/* 06163C 7F02CB0C C7B00160 */  lwc1  $f16, 0x160($sp)
/* 061640 7F02CB10 460A4101 */  sub.s $f4, $f8, $f10
/* 061644 7F02CB14 E7A40150 */  swc1  $f4, 0x150($sp)
/* 061648 7F02CB18 C4520004 */  lwc1  $f18, 4($v0)
/* 06164C 7F02CB1C C7A40128 */  lwc1  $f4, 0x128($sp)
/* 061650 7F02CB20 46069201 */  sub.s $f8, $f18, $f6
/* 061654 7F02CB24 E7A8014C */  swc1  $f8, 0x14c($sp)
/* 061658 7F02CB28 C44A0008 */  lwc1  $f10, 8($v0)
/* 06165C 7F02CB2C 46045481 */  sub.s $f18, $f10, $f4
/* 061660 7F02CB30 E7B20148 */  swc1  $f18, 0x148($sp)
.L7F02CB34:
/* 061664 7F02CB34 8FAF015C */  lw    $t7, 0x15c($sp)
/* 061668 7F02CB38 C7A60150 */  lwc1  $f6, 0x150($sp)
/* 06166C 7F02CB3C C7AA0148 */  lwc1  $f10, 0x148($sp)
/* 061670 7F02CB40 31F80100 */  andi  $t8, $t7, 0x100
/* 061674 7F02CB44 57000015 */  bnezl $t8, .L7F02CB9C
/* 061678 7F02CB48 8FB90138 */   lw    $t9, 0x138($sp)
/* 06167C 7F02CB4C 46063202 */  mul.s $f8, $f6, $f6
/* 061680 7F02CB50 E7B00160 */  swc1  $f16, 0x160($sp)
/* 061684 7F02CB54 460A5102 */  mul.s $f4, $f10, $f10
/* 061688 7F02CB58 0C007DF8 */  jal   sqrtf
/* 06168C 7F02CB5C 46044300 */   add.s $f12, $f8, $f4
/* 061690 7F02CB60 C7AC014C */  lwc1  $f12, 0x14c($sp)
/* 061694 7F02CB64 0FC16A8C */  jal   atan2f
/* 061698 7F02CB68 46000386 */   mov.s $f14, $f0
/* 06169C 7F02CB6C 3C018005 */  lui   $at, %hi(D_80051EFC)
/* 0616A0 7F02CB70 C4321EFC */  lwc1  $f18, %lo(D_80051EFC)($at)
/* 0616A4 7F02CB74 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 0616A8 7F02CB78 E7A00164 */  swc1  $f0, 0x164($sp)
/* 0616AC 7F02CB7C 4600903E */  c.le.s $f18, $f0
/* 0616B0 7F02CB80 3C018005 */  lui   $at, %hi(D_80051F00)
/* 0616B4 7F02CB84 45020005 */  bc1fl .L7F02CB9C
/* 0616B8 7F02CB88 8FB90138 */   lw    $t9, 0x138($sp)
/* 0616BC 7F02CB8C C4261F00 */  lwc1  $f6, %lo(D_80051F00)($at)
/* 0616C0 7F02CB90 46060281 */  sub.s $f10, $f0, $f6
/* 0616C4 7F02CB94 E7AA0164 */  swc1  $f10, 0x164($sp)
/* 0616C8 7F02CB98 8FB90138 */  lw    $t9, 0x138($sp)
.L7F02CB9C:
/* 0616CC 7F02CB9C 53200119 */  beql  $t9, $zero, .L7F02D004
/* 0616D0 7F02CBA0 C7A60164 */   lwc1  $f6, 0x164($sp)
/* 0616D4 7F02CBA4 0FC0B064 */  jal   sub_GAME_7F02C190
/* 0616D8 7F02CBA8 8FA40168 */   lw    $a0, 0x168($sp)
/* 0616DC 7F02CBAC 8FA90174 */  lw    $t1, 0x174($sp)
/* 0616E0 7F02CBB0 E7A00118 */  swc1  $f0, 0x118($sp)
/* 0616E4 7F02CBB4 00002825 */  move  $a1, $zero
/* 0616E8 7F02CBB8 11200005 */  beqz  $t1, .L7F02CBD0
/* 0616EC 7F02CBBC 8FA40168 */   lw    $a0, 0x168($sp)
/* 0616F0 7F02CBC0 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 0616F4 7F02CBC4 8FA40168 */   lw    $a0, 0x168($sp)
/* 0616F8 7F02CBC8 10000003 */  b     .L7F02CBD8
/* 0616FC 7F02CBCC 00000000 */   nop   
.L7F02CBD0:
/* 061700 7F02CBD0 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 061704 7F02CBD4 24050001 */   li    $a1, 1
.L7F02CBD8:
/* 061708 7F02CBD8 50400075 */  beql  $v0, $zero, .L7F02CDB0
/* 06170C 7F02CBDC C7AC0150 */   lwc1  $f12, 0x150($sp)
/* 061710 7F02CBE0 904B0001 */  lbu   $t3, 1($v0)
/* 061714 7F02CBE4 C7A80144 */  lwc1  $f8, 0x144($sp)
/* 061718 7F02CBE8 3C018005 */  lui   $at, %hi(D_80051F04)
/* 06171C 7F02CBEC 316A0002 */  andi  $t2, $t3, 2
/* 061720 7F02CBF0 5140006F */  beql  $t2, $zero, .L7F02CDB0
/* 061724 7F02CBF4 C7AC0150 */   lwc1  $f12, 0x150($sp)
/* 061728 7F02CBF8 C4241F04 */  lwc1  $f4, %lo(D_80051F04)($at)
/* 06172C 7F02CBFC 4604403C */  c.lt.s $f8, $f4
/* 061730 7F02CC00 00000000 */  nop   
/* 061734 7F02CC04 4502006A */  bc1fl .L7F02CDB0
/* 061738 7F02CC08 C7AC0150 */   lwc1  $f12, 0x150($sp)
/* 06173C 7F02CC0C 8C430004 */  lw    $v1, 4($v0)
/* 061740 7F02CC10 00002025 */  move  $a0, $zero
/* 061744 7F02CC14 00003025 */  move  $a2, $zero
/* 061748 7F02CC18 8C670014 */  lw    $a3, 0x14($v1)
/* 06174C 7F02CC1C 8CEC0008 */  lw    $t4, 8($a3)
/* 061750 7F02CC20 8D850008 */  lw    $a1, 8($t4)
/* 061754 7F02CC24 8CAD0000 */  lw    $t5, ($a1)
/* 061758 7F02CC28 11A00025 */  beqz  $t5, .L7F02CCC0
/* 06175C 7F02CC2C AFAD0024 */   sw    $t5, 0x24($sp)
/* 061760 7F02CC30 00E02025 */  move  $a0, $a3
/* 061764 7F02CC34 01A02825 */  move  $a1, $t5
/* 061768 7F02CC38 0FC1B198 */  jal   sub_GAME_7F06C660
/* 06176C 7F02CC3C AFA70110 */   sw    $a3, 0x110($sp)
/* 061770 7F02CC40 8FA70110 */  lw    $a3, 0x110($sp)
/* 061774 7F02CC44 00402025 */  move  $a0, $v0
/* 061778 7F02CC48 27A500BC */  addiu $a1, $sp, 0xbc
/* 06177C 7F02CC4C 8CEF0008 */  lw    $t7, 8($a3)
/* 061780 7F02CC50 8DF80008 */  lw    $t8, 8($t7)
/* 061784 7F02CC54 8F190000 */  lw    $t9, ($t8)
/* 061788 7F02CC58 8F290004 */  lw    $t1, 4($t9)
/* 06178C 7F02CC5C 0FC1639E */  jal   sub_GAME_7F058E78
/* 061790 7F02CC60 AFA900B8 */   sw    $t1, 0xb8($sp)
/* 061794 7F02CC64 0FC1E115 */  jal   currentPlayerGetMatrix10EC
/* 061798 7F02CC68 00000000 */   nop   
/* 06179C 7F02CC6C 00402025 */  move  $a0, $v0
/* 0617A0 7F02CC70 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0617A4 7F02CC74 27A500BC */   addiu $a1, $sp, 0xbc
/* 0617A8 7F02CC78 8FA200B8 */  lw    $v0, 0xb8($sp)
/* 0617AC 7F02CC7C 27A400BC */  addiu $a0, $sp, 0xbc
/* 0617B0 7F02CC80 27A500AC */  addiu $a1, $sp, 0xac
/* 0617B4 7F02CC84 C4520000 */  lwc1  $f18, ($v0)
/* 0617B8 7F02CC88 E7B200AC */  swc1  $f18, 0xac($sp)
/* 0617BC 7F02CC8C C4460004 */  lwc1  $f6, 4($v0)
/* 0617C0 7F02CC90 E7A600B0 */  swc1  $f6, 0xb0($sp)
/* 0617C4 7F02CC94 C44A0008 */  lwc1  $f10, 8($v0)
/* 0617C8 7F02CC98 0FC1611D */  jal   matrix_4x4_transform_vector_in_place
/* 0617CC 7F02CC9C E7AA00B4 */   swc1  $f10, 0xb4($sp)
/* 0617D0 7F02CCA0 C7A800AC */  lwc1  $f8, 0xac($sp)
/* 0617D4 7F02CCA4 C7A400B0 */  lwc1  $f4, 0xb0($sp)
/* 0617D8 7F02CCA8 C7B200B4 */  lwc1  $f18, 0xb4($sp)
/* 0617DC 7F02CCAC 24040001 */  li    $a0, 1
/* 0617E0 7F02CCB0 E7A80104 */  swc1  $f8, 0x104($sp)
/* 0617E4 7F02CCB4 E7A40108 */  swc1  $f4, 0x108($sp)
/* 0617E8 7F02CCB8 10000017 */  b     .L7F02CD18
/* 0617EC 7F02CCBC E7B2010C */   swc1  $f18, 0x10c($sp)
.L7F02CCC0:
/* 0617F0 7F02CCC0 8CAB0004 */  lw    $t3, 4($a1)
/* 0617F4 7F02CCC4 00003025 */  move  $a2, $zero
/* 0617F8 7F02CCC8 11600013 */  beqz  $t3, .L7F02CD18
/* 0617FC 7F02CCCC AFAB0024 */   sw    $t3, 0x24($sp)
/* 061800 7F02CCD0 00E02025 */  move  $a0, $a3
/* 061804 7F02CCD4 0FC1B198 */  jal   sub_GAME_7F06C660
/* 061808 7F02CCD8 01602825 */   move  $a1, $t3
/* 06180C 7F02CCDC 00402025 */  move  $a0, $v0
/* 061810 7F02CCE0 0FC1639E */  jal   sub_GAME_7F058E78
/* 061814 7F02CCE4 27A50068 */   addiu $a1, $sp, 0x68
/* 061818 7F02CCE8 0FC1E115 */  jal   currentPlayerGetMatrix10EC
/* 06181C 7F02CCEC 00000000 */   nop   
/* 061820 7F02CCF0 00402025 */  move  $a0, $v0
/* 061824 7F02CCF4 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 061828 7F02CCF8 27A50068 */   addiu $a1, $sp, 0x68
/* 06182C 7F02CCFC C7A60098 */  lwc1  $f6, 0x98($sp)
/* 061830 7F02CD00 C7AA009C */  lwc1  $f10, 0x9c($sp)
/* 061834 7F02CD04 C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 061838 7F02CD08 24040001 */  li    $a0, 1
/* 06183C 7F02CD0C E7A60104 */  swc1  $f6, 0x104($sp)
/* 061840 7F02CD10 E7AA0108 */  swc1  $f10, 0x108($sp)
/* 061844 7F02CD14 E7A8010C */  swc1  $f8, 0x10c($sp)
.L7F02CD18:
/* 061848 7F02CD18 50800025 */  beql  $a0, $zero, .L7F02CDB0
/* 06184C 7F02CD1C C7AC0150 */   lwc1  $f12, 0x150($sp)
/* 061850 7F02CD20 0FC15FAB */  jal   sinf
/* 061854 7F02CD24 C7AC0118 */   lwc1  $f12, 0x118($sp)
/* 061858 7F02CD28 44802000 */  mtc1  $zero, $f4
/* 06185C 7F02CD2C E7A00050 */  swc1  $f0, 0x50($sp)
/* 061860 7F02CD30 C7AC0118 */  lwc1  $f12, 0x118($sp)
/* 061864 7F02CD34 0FC15FA8 */  jal   cosf
/* 061868 7F02CD38 E7A40054 */   swc1  $f4, 0x54($sp)
/* 06186C 7F02CD3C 8FAC013C */  lw    $t4, 0x13c($sp)
/* 061870 7F02CD40 E7A00058 */  swc1  $f0, 0x58($sp)
/* 061874 7F02CD44 C7A60148 */  lwc1  $f6, 0x148($sp)
/* 061878 7F02CD48 C5920008 */  lwc1  $f18, 8($t4)
/* 06187C 7F02CD4C 27AD005C */  addiu $t5, $sp, 0x5c
/* 061880 7F02CD50 27A50044 */  addiu $a1, $sp, 0x44
/* 061884 7F02CD54 46069281 */  sub.s $f10, $f18, $f6
/* 061888 7F02CD58 C7B20150 */  lwc1  $f18, 0x150($sp)
/* 06188C 7F02CD5C 27A60104 */  addiu $a2, $sp, 0x104
/* 061890 7F02CD60 27A70050 */  addiu $a3, $sp, 0x50
/* 061894 7F02CD64 E7AA0044 */  swc1  $f10, 0x44($sp)
/* 061898 7F02CD68 C588000C */  lwc1  $f8, 0xc($t4)
/* 06189C 7F02CD6C 25840008 */  addiu $a0, $t4, 8
/* 0618A0 7F02CD70 E7A80048 */  swc1  $f8, 0x48($sp)
/* 0618A4 7F02CD74 C5840010 */  lwc1  $f4, 0x10($t4)
/* 0618A8 7F02CD78 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0618AC 7F02CD7C 46122180 */  add.s $f6, $f4, $f18
/* 0618B0 7F02CD80 0FC0984C */  jal   chrlvLineLineIntersection
/* 0618B4 7F02CD84 E7A6004C */   swc1  $f6, 0x4c($sp)
/* 0618B8 7F02CD88 8FAE0134 */  lw    $t6, 0x134($sp)
/* 0618BC 7F02CD8C C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 0618C0 7F02CD90 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 0618C4 7F02CD94 C5CA0000 */  lwc1  $f10, ($t6)
/* 0618C8 7F02CD98 46085101 */  sub.s $f4, $f10, $f8
/* 0618CC 7F02CD9C E7A40150 */  swc1  $f4, 0x150($sp)
/* 0618D0 7F02CDA0 C5D20008 */  lwc1  $f18, 8($t6)
/* 0618D4 7F02CDA4 46069281 */  sub.s $f10, $f18, $f6
/* 0618D8 7F02CDA8 E7AA0148 */  swc1  $f10, 0x148($sp)
/* 0618DC 7F02CDAC C7AC0150 */  lwc1  $f12, 0x150($sp)
.L7F02CDB0:
/* 0618E0 7F02CDB0 0FC16A8C */  jal   atan2f
/* 0618E4 7F02CDB4 C7AE0148 */   lwc1  $f14, 0x148($sp)
/* 0618E8 7F02CDB8 C7A80118 */  lwc1  $f8, 0x118($sp)
/* 0618EC 7F02CDBC 3C018005 */  lui   $at, %hi(D_80051F08)
/* 0618F0 7F02CDC0 8FAF0168 */  lw    $t7, 0x168($sp)
/* 0618F4 7F02CDC4 4608003C */  c.lt.s $f0, $f8
/* 0618F8 7F02CDC8 46080081 */  sub.s $f2, $f0, $f8
/* 0618FC 7F02CDCC 45000003 */  bc1f  .L7F02CDDC
/* 061900 7F02CDD0 46001406 */   mov.s $f16, $f2
/* 061904 7F02CDD4 C4241F08 */  lwc1  $f4, %lo(D_80051F08)($at)
/* 061908 7F02CDD8 46041400 */  add.s $f16, $f2, $f4
.L7F02CDDC:
/* 06190C 7F02CDDC 8DE4001C */  lw    $a0, 0x1c($t7)
/* 061910 7F02CDE0 8C980008 */  lw    $t8, 8($a0)
/* 061914 7F02CDE4 8F050000 */  lw    $a1, ($t8)
/* 061918 7F02CDE8 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 06191C 7F02CDEC E7B00160 */   swc1  $f16, 0x160($sp)
/* 061920 7F02CDF0 44801000 */  mtc1  $zero, $f2
/* 061924 7F02CDF4 C440005C */  lwc1  $f0, 0x5c($v0)
/* 061928 7F02CDF8 8FA9015C */  lw    $t1, 0x15c($sp)
/* 06192C 7F02CDFC C7B00160 */  lwc1  $f16, 0x160($sp)
/* 061930 7F02CE00 4600103C */  c.lt.s $f2, $f0
/* 061934 7F02CE04 8FB90028 */  lw    $t9, 0x28($sp)
/* 061938 7F02CE08 312B0060 */  andi  $t3, $t1, 0x60
/* 06193C 7F02CE0C 45000012 */  bc1f  .L7F02CE58
/* 061940 7F02CE10 00000000 */   nop   
/* 061944 7F02CE14 C4520058 */  lwc1  $f18, 0x58($v0)
/* 061948 7F02CE18 3C018005 */  lui   $at, %hi(D_80051F0C)
/* 06194C 7F02CE1C 46120182 */  mul.s $f6, $f0, $f18
/* 061950 7F02CE20 46068401 */  sub.s $f16, $f16, $f6
/* 061954 7F02CE24 4602803C */  c.lt.s $f16, $f2
/* 061958 7F02CE28 00000000 */  nop   
/* 06195C 7F02CE2C 45000003 */  bc1f  .L7F02CE3C
/* 061960 7F02CE30 00000000 */   nop   
/* 061964 7F02CE34 C4201F0C */  lwc1  $f0, %lo(D_80051F0C)($at)
/* 061968 7F02CE38 46008400 */  add.s $f16, $f16, $f0
.L7F02CE3C:
/* 06196C 7F02CE3C 3C018005 */  lui   $at, %hi(D_80051F10)
/* 061970 7F02CE40 C4201F10 */  lwc1  $f0, %lo(D_80051F10)($at)
/* 061974 7F02CE44 4610003E */  c.le.s $f0, $f16
/* 061978 7F02CE48 00000000 */  nop   
/* 06197C 7F02CE4C 45000002 */  bc1f  .L7F02CE58
/* 061980 7F02CE50 00000000 */   nop   
/* 061984 7F02CE54 46008401 */  sub.s $f16, $f16, $f0
.L7F02CE58:
/* 061988 7F02CE58 3C018005 */  lui   $at, %hi(D_80051F14)
/* 06198C 7F02CE5C 13200035 */  beqz  $t9, .L7F02CF34
/* 061990 7F02CE60 C4201F14 */   lwc1  $f0, %lo(D_80051F14)($at)
/* 061994 7F02CE64 15600033 */  bnez  $t3, .L7F02CF34
/* 061998 7F02CE68 3C0A8005 */   lui   $t2, %hi(g_GlobalTimer) 
/* 06199C 7F02CE6C 8D4A837C */  lw    $t2, %lo(g_GlobalTimer)($t2)
/* 0619A0 7F02CE70 8FAC0168 */  lw    $t4, 0x168($sp)
/* 0619A4 7F02CE74 2401003C */  li    $at, 60
/* 0619A8 7F02CE78 448A5000 */  mtc1  $t2, $f10
/* 0619AC 7F02CE7C 8D8D001C */  lw    $t5, 0x1c($t4)
/* 0619B0 7F02CE80 85980000 */  lh    $t8, ($t4)
/* 0619B4 7F02CE84 46805220 */  cvt.s.w $f8, $f10
/* 0619B8 7F02CE88 C5A400A4 */  lwc1  $f4, 0xa4($t5)
/* 0619BC 7F02CE8C E7B00160 */  swc1  $f16, 0x160($sp)
/* 0619C0 7F02CE90 46044482 */  mul.s $f18, $f8, $f4
/* 0619C4 7F02CE94 4600918D */  trunc.w.s $f6, $f18
/* 0619C8 7F02CE98 440F3000 */  mfc1  $t7, $f6
/* 0619CC 7F02CE9C 00000000 */  nop   
/* 0619D0 7F02CEA0 01F8C821 */  addu  $t9, $t7, $t8
/* 0619D4 7F02CEA4 0321001A */  div   $zero, $t9, $at
/* 0619D8 7F02CEA8 00004810 */  mfhi  $t1
/* 0619DC 7F02CEAC 44895000 */  mtc1  $t1, $f10
/* 0619E0 7F02CEB0 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0619E4 7F02CEB4 44819000 */  mtc1  $at, $f18
/* 0619E8 7F02CEB8 46805220 */  cvt.s.w $f8, $f10
/* 0619EC 7F02CEBC 46004102 */  mul.s $f4, $f8, $f0
/* 0619F0 7F02CEC0 0FC15FAB */  jal   sinf
/* 0619F4 7F02CEC4 46122303 */   div.s $f12, $f4, $f18
/* 0619F8 7F02CEC8 E7A00030 */  swc1  $f0, 0x30($sp)
/* 0619FC 7F02CECC 0FC0B491 */  jal   sub_GAME_7F02D244
/* 061A00 7F02CED0 C7AC0144 */   lwc1  $f12, 0x144($sp)
/* 061A04 7F02CED4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 061A08 7F02CED8 44813000 */  mtc1  $at, $f6
/* 061A0C 7F02CEDC C7A80030 */  lwc1  $f8, 0x30($sp)
/* 061A10 7F02CEE0 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 061A14 7F02CEE4 46060282 */  mul.s $f10, $f0, $f6
/* 061A18 7F02CEE8 44809000 */  mtc1  $zero, $f18
/* 061A1C 7F02CEEC 3C018005 */  lui   $at, %hi(D_80051F18)
/* 061A20 7F02CEF0 46085102 */  mul.s $f4, $f10, $f8
/* 061A24 7F02CEF4 46048400 */  add.s $f16, $f16, $f4
/* 061A28 7F02CEF8 4612803C */  c.lt.s $f16, $f18
/* 061A2C 7F02CEFC 00000000 */  nop   
/* 061A30 7F02CF00 45000003 */  bc1f  .L7F02CF10
/* 061A34 7F02CF04 00000000 */   nop   
/* 061A38 7F02CF08 C4261F18 */  lwc1  $f6, %lo(D_80051F18)($at)
/* 061A3C 7F02CF0C 46068400 */  add.s $f16, $f16, $f6
.L7F02CF10:
/* 061A40 7F02CF10 3C018005 */  lui   $at, %hi(D_80051F1C)
/* 061A44 7F02CF14 C42A1F1C */  lwc1  $f10, %lo(D_80051F1C)($at)
/* 061A48 7F02CF18 3C018005 */  lui   $at, %hi(D_80051F20)
/* 061A4C 7F02CF1C 4610503E */  c.le.s $f10, $f16
/* 061A50 7F02CF20 00000000 */  nop   
/* 061A54 7F02CF24 45000003 */  bc1f  .L7F02CF34
/* 061A58 7F02CF28 00000000 */   nop   
/* 061A5C 7F02CF2C C4281F20 */  lwc1  $f8, %lo(D_80051F20)($at)
/* 061A60 7F02CF30 46088401 */  sub.s $f16, $f16, $f8
.L7F02CF34:
/* 061A64 7F02CF34 3C018005 */  lui   $at, %hi(D_80051F24)
/* 061A68 7F02CF38 C4201F24 */  lwc1  $f0, %lo(D_80051F24)($at)
/* 061A6C 7F02CF3C 3C018005 */  lui   $at, %hi(D_80051F28)
/* 061A70 7F02CF40 C4241F28 */  lwc1  $f4, %lo(D_80051F28)($at)
/* 061A74 7F02CF44 8FAB0168 */  lw    $t3, 0x168($sp)
/* 061A78 7F02CF48 8FA2016C */  lw    $v0, 0x16c($sp)
/* 061A7C 7F02CF4C 4610203E */  c.le.s $f4, $f16
/* 061A80 7F02CF50 00000000 */  nop   
/* 061A84 7F02CF54 45020003 */  bc1fl .L7F02CF64
/* 061A88 7F02CF58 8D6A001C */   lw    $t2, 0x1c($t3)
/* 061A8C 7F02CF5C 46008401 */  sub.s $f16, $f16, $f0
/* 061A90 7F02CF60 8D6A001C */  lw    $t2, 0x1c($t3)
.L7F02CF64:
/* 061A94 7F02CF64 C572014C */  lwc1  $f18, 0x14c($t3)
/* 061A98 7F02CF68 814D0024 */  lb    $t5, 0x24($t2)
/* 061A9C 7F02CF6C 46128400 */  add.s $f16, $f16, $f18
/* 061AA0 7F02CF70 51A00015 */  beql  $t5, $zero, .L7F02CFC8
/* 061AA4 7F02CF74 C4400038 */   lwc1  $f0, 0x38($v0)
/* 061AA8 7F02CF78 8FA2016C */  lw    $v0, 0x16c($sp)
/* 061AAC 7F02CF7C C4400038 */  lwc1  $f0, 0x38($v0)
/* 061AB0 7F02CF80 46000007 */  neg.s $f0, $f0
/* 061AB4 7F02CF84 4600803C */  c.lt.s $f16, $f0
/* 061AB8 7F02CF88 00000000 */  nop   
/* 061ABC 7F02CF8C 45020005 */  bc1fl .L7F02CFA4
/* 061AC0 7F02CF90 C440003C */   lwc1  $f0, 0x3c($v0)
/* 061AC4 7F02CF94 46000406 */  mov.s $f16, $f0
/* 061AC8 7F02CF98 10000019 */  b     .L7F02D000
/* 061ACC 7F02CF9C AFA00154 */   sw    $zero, 0x154($sp)
/* 061AD0 7F02CFA0 C440003C */  lwc1  $f0, 0x3c($v0)
.L7F02CFA4:
/* 061AD4 7F02CFA4 46000007 */  neg.s $f0, $f0
/* 061AD8 7F02CFA8 4610003C */  c.lt.s $f0, $f16
/* 061ADC 7F02CFAC 00000000 */  nop   
/* 061AE0 7F02CFB0 45020014 */  bc1fl .L7F02D004
/* 061AE4 7F02CFB4 C7A60164 */   lwc1  $f6, 0x164($sp)
/* 061AE8 7F02CFB8 46000406 */  mov.s $f16, $f0
/* 061AEC 7F02CFBC 10000010 */  b     .L7F02D000
/* 061AF0 7F02CFC0 AFA00154 */   sw    $zero, 0x154($sp)
/* 061AF4 7F02CFC4 C4400038 */  lwc1  $f0, 0x38($v0)
.L7F02CFC8:
/* 061AF8 7F02CFC8 4610003C */  c.lt.s $f0, $f16
/* 061AFC 7F02CFCC 00000000 */  nop   
/* 061B00 7F02CFD0 45020005 */  bc1fl .L7F02CFE8
/* 061B04 7F02CFD4 C440003C */   lwc1  $f0, 0x3c($v0)
/* 061B08 7F02CFD8 46000406 */  mov.s $f16, $f0
/* 061B0C 7F02CFDC 10000008 */  b     .L7F02D000
/* 061B10 7F02CFE0 AFA00154 */   sw    $zero, 0x154($sp)
/* 061B14 7F02CFE4 C440003C */  lwc1  $f0, 0x3c($v0)
.L7F02CFE8:
/* 061B18 7F02CFE8 4600803C */  c.lt.s $f16, $f0
/* 061B1C 7F02CFEC 00000000 */  nop   
/* 061B20 7F02CFF0 45020004 */  bc1fl .L7F02D004
/* 061B24 7F02CFF4 C7A60164 */   lwc1  $f6, 0x164($sp)
/* 061B28 7F02CFF8 46000406 */  mov.s $f16, $f0
/* 061B2C 7F02CFFC AFA00154 */  sw    $zero, 0x154($sp)
.L7F02D000:
/* 061B30 7F02D000 C7A60164 */  lwc1  $f6, 0x164($sp)
.L7F02D004:
/* 061B34 7F02D004 8FA40168 */  lw    $a0, 0x168($sp)
/* 061B38 7F02D008 8FA5016C */  lw    $a1, 0x16c($sp)
/* 061B3C 7F02D00C 8FA60170 */  lw    $a2, 0x170($sp)
/* 061B40 7F02D010 8FA70174 */  lw    $a3, 0x174($sp)
/* 061B44 7F02D014 E7B00160 */  swc1  $f16, 0x160($sp)
/* 061B48 7F02D018 0FC0B412 */  jal   sub_GAME_7F02D048
/* 061B4C 7F02D01C E7A60010 */   swc1  $f6, 0x10($sp)
/* 061B50 7F02D020 8FAE0168 */  lw    $t6, 0x168($sp)
/* 061B54 7F02D024 C7B00160 */  lwc1  $f16, 0x160($sp)
/* 061B58 7F02D028 240C000A */  li    $t4, 10
/* 061B5C 7F02D02C A1CC000E */  sb    $t4, 0xe($t6)
/* 061B60 7F02D030 E5D0015C */  swc1  $f16, 0x15c($t6)
/* 061B64 7F02D034 8FBF001C */  lw    $ra, 0x1c($sp)
/* 061B68 7F02D038 8FA20154 */  lw    $v0, 0x154($sp)
/* 061B6C 7F02D03C 27BD0168 */  addiu $sp, $sp, 0x168
/* 061B70 7F02D040 03E00008 */  jr    $ra
/* 061B74 7F02D044 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D048(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02D048
/* 061B78 7F02D048 44808000 */  mtc1  $zero, $f16
/* 061B7C 7F02D04C C7AE0010 */  lwc1  $f14, 0x10($sp)
/* 061B80 7F02D050 46008006 */  mov.s $f0, $f16
/* 061B84 7F02D054 46008086 */  mov.s $f2, $f16
/* 061B88 7F02D058 10A0001B */  beqz  $a1, .L7F02D0C8
/* 061B8C 7F02D05C 46007306 */   mov.s $f12, $f14
/* 061B90 7F02D060 C4A00030 */  lwc1  $f0, 0x30($a1)
/* 061B94 7F02D064 460E003C */  c.lt.s $f0, $f14
/* 061B98 7F02D068 00000000 */  nop   
/* 061B9C 7F02D06C 45020005 */  bc1fl .L7F02D084
/* 061BA0 7F02D070 C4A00034 */   lwc1  $f0, 0x34($a1)
/* 061BA4 7F02D074 46007081 */  sub.s $f2, $f14, $f0
/* 061BA8 7F02D078 10000008 */  b     .L7F02D09C
/* 061BAC 7F02D07C 46000306 */   mov.s $f12, $f0
/* 061BB0 7F02D080 C4A00034 */  lwc1  $f0, 0x34($a1)
.L7F02D084:
/* 061BB4 7F02D084 4600703C */  c.lt.s $f14, $f0
/* 061BB8 7F02D088 00000000 */  nop   
/* 061BBC 7F02D08C 45020004 */  bc1fl .L7F02D0A0
/* 061BC0 7F02D090 460C803C */   c.lt.s $f16, $f12
/* 061BC4 7F02D094 46007081 */  sub.s $f2, $f14, $f0
/* 061BC8 7F02D098 46000306 */  mov.s $f12, $f0
.L7F02D09C:
/* 061BCC 7F02D09C 460C803C */  c.lt.s $f16, $f12
.L7F02D0A0:
/* 061BD0 7F02D0A0 00000000 */  nop   
/* 061BD4 7F02D0A4 45020006 */  bc1fl .L7F02D0C0
/* 061BD8 7F02D0A8 C4A60044 */   lwc1  $f6, 0x44($a1)
/* 061BDC 7F02D0AC C4A40040 */  lwc1  $f4, 0x40($a1)
/* 061BE0 7F02D0B0 460C2002 */  mul.s $f0, $f4, $f12
/* 061BE4 7F02D0B4 10000004 */  b     .L7F02D0C8
/* 061BE8 7F02D0B8 00000000 */   nop   
/* 061BEC 7F02D0BC C4A60044 */  lwc1  $f6, 0x44($a1)
.L7F02D0C0:
/* 061BF0 7F02D0C0 460C3002 */  mul.s $f0, $f6, $f12
/* 061BF4 7F02D0C4 00000000 */  nop   
.L7F02D0C8:
/* 061BF8 7F02D0C8 50E00008 */  beql  $a3, $zero, .L7F02D0EC
/* 061BFC 7F02D0CC E4800154 */   swc1  $f0, 0x154($a0)
/* 061C00 7F02D0D0 10C00003 */  beqz  $a2, .L7F02D0E0
/* 061C04 7F02D0D4 E48C0154 */   swc1  $f12, 0x154($a0)
/* 061C08 7F02D0D8 10000005 */  b     .L7F02D0F0
/* 061C0C 7F02D0DC E48C0150 */   swc1  $f12, 0x150($a0)
.L7F02D0E0:
/* 061C10 7F02D0E0 10000003 */  b     .L7F02D0F0
/* 061C14 7F02D0E4 E4800150 */   swc1  $f0, 0x150($a0)
/* 061C18 7F02D0E8 E4800154 */  swc1  $f0, 0x154($a0)
.L7F02D0EC:
/* 061C1C 7F02D0EC E48C0150 */  swc1  $f12, 0x150($a0)
.L7F02D0F0:
/* 061C20 7F02D0F0 03E00008 */  jr    $ra
/* 061C24 7F02D0F4 E4820158 */   swc1  $f2, 0x158($a0)
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D0F8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02D0F8
/* 061C28 7F02D0F8 44800000 */  mtc1  $zero, $f0
/* 061C2C 7F02D0FC 240E000A */  li    $t6, 10
/* 061C30 7F02D100 A08E000E */  sb    $t6, 0xe($a0)
/* 061C34 7F02D104 E4800154 */  swc1  $f0, 0x154($a0)
/* 061C38 7F02D108 E4800150 */  swc1  $f0, 0x150($a0)
/* 061C3C 7F02D10C E4800158 */  swc1  $f0, 0x158($a0)
/* 061C40 7F02D110 03E00008 */  jr    $ra
/* 061C44 7F02D114 E480015C */   swc1  $f0, 0x15c($a0)
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D118(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02D118
/* 061C48 7F02D118 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 061C4C 7F02D11C AFBF0014 */  sw    $ra, 0x14($sp)
/* 061C50 7F02D120 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 061C54 7F02D124 AFA60020 */   sw    $a2, 0x20($sp)
/* 061C58 7F02D128 10400003 */  beqz  $v0, .L7F02D138
/* 061C5C 7F02D12C 00402025 */   move  $a0, $v0
/* 061C60 7F02D130 0FC1495D */  jal   sub_GAME_7F052574
/* 061C64 7F02D134 8FA50020 */   lw    $a1, 0x20($sp)
.L7F02D138:
/* 061C68 7F02D138 8FBF0014 */  lw    $ra, 0x14($sp)
/* 061C6C 7F02D13C 27BD0018 */  addiu $sp, $sp, 0x18
/* 061C70 7F02D140 03E00008 */  jr    $ra
/* 061C74 7F02D144 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D148(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02D148
/* 061C78 7F02D148 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 061C7C 7F02D14C AFBF0014 */  sw    $ra, 0x14($sp)
/* 061C80 7F02D150 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 061C84 7F02D154 00000000 */   nop   
/* 061C88 7F02D158 10400005 */  beqz  $v0, .L7F02D170
/* 061C8C 7F02D15C 00402025 */   move  $a0, $v0
/* 061C90 7F02D160 0FC14981 */  jal   sub_GAME_7F052604
/* 061C94 7F02D164 00000000 */   nop   
/* 061C98 7F02D168 10000003 */  b     .L7F02D178
/* 061C9C 7F02D16C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F02D170:
/* 061CA0 7F02D170 00001025 */  move  $v0, $zero
/* 061CA4 7F02D174 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02D178:
/* 061CA8 7F02D178 27BD0018 */  addiu $sp, $sp, 0x18
/* 061CAC 7F02D17C 03E00008 */  jr    $ra
/* 061CB0 7F02D180 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D184(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02D184
/* 061CB4 7F02D184 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 061CB8 7F02D188 AFBF0014 */  sw    $ra, 0x14($sp)
/* 061CBC 7F02D18C AFA40018 */  sw    $a0, 0x18($sp)
/* 061CC0 7F02D190 00002825 */  move  $a1, $zero
/* 061CC4 7F02D194 0FC0B446 */  jal   sub_GAME_7F02D118
/* 061CC8 7F02D198 00003025 */   move  $a2, $zero
/* 061CCC 7F02D19C 8FA40018 */  lw    $a0, 0x18($sp)
/* 061CD0 7F02D1A0 24050001 */  li    $a1, 1
/* 061CD4 7F02D1A4 0FC0B446 */  jal   sub_GAME_7F02D118
/* 061CD8 7F02D1A8 00003025 */   move  $a2, $zero
/* 061CDC 7F02D1AC 0FC0B43E */  jal   sub_GAME_7F02D0F8
/* 061CE0 7F02D1B0 8FA40018 */   lw    $a0, 0x18($sp)
/* 061CE4 7F02D1B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 061CE8 7F02D1B8 27BD0018 */  addiu $sp, $sp, 0x18
/* 061CEC 7F02D1BC 03E00008 */  jr    $ra
/* 061CF0 7F02D1C0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D1C4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02D1C4
/* 061CF4 7F02D1C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 061CF8 7F02D1C8 10C0000C */  beqz  $a2, .L7F02D1FC
/* 061CFC 7F02D1CC AFBF0014 */   sw    $ra, 0x14($sp)
/* 061D00 7F02D1D0 24010001 */  li    $at, 1
/* 061D04 7F02D1D4 54A10006 */  bnel  $a1, $at, .L7F02D1F0
/* 061D08 7F02D1D8 94980012 */   lhu   $t8, 0x12($a0)
/* 061D0C 7F02D1DC 948E0012 */  lhu   $t6, 0x12($a0)
/* 061D10 7F02D1E0 35CF0004 */  ori   $t7, $t6, 4
/* 061D14 7F02D1E4 1000000F */  b     .L7F02D224
/* 061D18 7F02D1E8 A48F0012 */   sh    $t7, 0x12($a0)
/* 061D1C 7F02D1EC 94980012 */  lhu   $t8, 0x12($a0)
.L7F02D1F0:
/* 061D20 7F02D1F0 37190008 */  ori   $t9, $t8, 8
/* 061D24 7F02D1F4 1000000B */  b     .L7F02D224
/* 061D28 7F02D1F8 A4990012 */   sh    $t9, 0x12($a0)
.L7F02D1FC:
/* 061D2C 7F02D1FC 24010001 */  li    $at, 1
/* 061D30 7F02D200 54A10006 */  bnel  $a1, $at, .L7F02D21C
/* 061D34 7F02D204 948A0012 */   lhu   $t2, 0x12($a0)
/* 061D38 7F02D208 94880012 */  lhu   $t0, 0x12($a0)
/* 061D3C 7F02D20C 3109FFFB */  andi  $t1, $t0, 0xfffb
/* 061D40 7F02D210 10000004 */  b     .L7F02D224
/* 061D44 7F02D214 A4890012 */   sh    $t1, 0x12($a0)
/* 061D48 7F02D218 948A0012 */  lhu   $t2, 0x12($a0)
.L7F02D21C:
/* 061D4C 7F02D21C 314BFFF7 */  andi  $t3, $t2, 0xfff7
/* 061D50 7F02D220 A48B0012 */  sh    $t3, 0x12($a0)
.L7F02D224:
/* 061D54 7F02D224 54C00004 */  bnezl $a2, .L7F02D238
/* 061D58 7F02D228 8FBF0014 */   lw    $ra, 0x14($sp)
/* 061D5C 7F02D22C 0FC0B446 */  jal   sub_GAME_7F02D118
/* 061D60 7F02D230 00003025 */   move  $a2, $zero
/* 061D64 7F02D234 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02D238:
/* 061D68 7F02D238 27BD0018 */  addiu $sp, $sp, 0x18
/* 061D6C 7F02D23C 03E00008 */  jr    $ra
/* 061D70 7F02D240 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D244(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051F2C
.word 0x4a1c4000 /*2560000.0*/
glabel D_80051F30
.word 0x3c99a5b7 /*0.018755777*/
glabel D_80051F34
.word 0x491c4000 /*640000.0*/
glabel D_80051F38
.word 0x3d1a1b7b /*0.037623864*/
glabel D_80051F3C
.word 0x481c4000 /*160000.0*/
glabel D_80051F40
.word 0x3d9930a7 /*0.074799828*/
glabel D_80051F44
.word 0x471c4000 /*40000.0*/
glabel D_80051F48
.word 0x3e1930a7 /*0.14959966*/
glabel D_80051F4C
.word 0x3e80adfd /*0.25132743*/
.text
glabel sub_GAME_7F02D244
/* 061D74 7F02D244 3C018005 */  lui   $at, %hi(D_80051F2C)
/* 061D78 7F02D248 C4241F2C */  lwc1  $f4, %lo(D_80051F2C)($at)
/* 061D7C 7F02D24C 3C018005 */  lui   $at, %hi(D_80051F34)
/* 061D80 7F02D250 460C203C */  c.lt.s $f4, $f12
/* 061D84 7F02D254 00000000 */  nop   
/* 061D88 7F02D258 45000004 */  bc1f  .L7F02D26C
/* 061D8C 7F02D25C 00000000 */   nop   
/* 061D90 7F02D260 3C018005 */  lui   $at, %hi(D_80051F30)
/* 061D94 7F02D264 03E00008 */  jr    $ra
/* 061D98 7F02D268 C4201F30 */   lwc1  $f0, %lo(D_80051F30)($at)

.L7F02D26C:
/* 061D9C 7F02D26C C4261F34 */  lwc1  $f6, %lo(D_80051F34)($at)
/* 061DA0 7F02D270 3C018005 */  lui   $at, %hi(D_80051F3C)
/* 061DA4 7F02D274 460C303C */  c.lt.s $f6, $f12
/* 061DA8 7F02D278 00000000 */  nop   
/* 061DAC 7F02D27C 45000004 */  bc1f  .L7F02D290
/* 061DB0 7F02D280 00000000 */   nop   
/* 061DB4 7F02D284 3C018005 */  lui   $at, %hi(D_80051F38)
/* 061DB8 7F02D288 03E00008 */  jr    $ra
/* 061DBC 7F02D28C C4201F38 */   lwc1  $f0, %lo(D_80051F38)($at)

.L7F02D290:
/* 061DC0 7F02D290 C4281F3C */  lwc1  $f8, %lo(D_80051F3C)($at)
/* 061DC4 7F02D294 3C018005 */  lui   $at, %hi(D_80051F44)
/* 061DC8 7F02D298 460C403C */  c.lt.s $f8, $f12
/* 061DCC 7F02D29C 00000000 */  nop   
/* 061DD0 7F02D2A0 45000004 */  bc1f  .L7F02D2B4
/* 061DD4 7F02D2A4 00000000 */   nop   
/* 061DD8 7F02D2A8 3C018005 */  lui   $at, %hi(D_80051F40)
/* 061DDC 7F02D2AC 03E00008 */  jr    $ra
/* 061DE0 7F02D2B0 C4201F40 */   lwc1  $f0, %lo(D_80051F40)($at)

.L7F02D2B4:
/* 061DE4 7F02D2B4 C42A1F44 */  lwc1  $f10, %lo(D_80051F44)($at)
/* 061DE8 7F02D2B8 3C018005 */  lui   $at, %hi(D_80051F4C)
/* 061DEC 7F02D2BC 460C503C */  c.lt.s $f10, $f12
/* 061DF0 7F02D2C0 00000000 */  nop   
/* 061DF4 7F02D2C4 45000004 */  bc1f  .L7F02D2D8
/* 061DF8 7F02D2C8 00000000 */   nop   
/* 061DFC 7F02D2CC 3C018005 */  lui   $at, %hi(D_80051F48)
/* 061E00 7F02D2D0 03E00008 */  jr    $ra
/* 061E04 7F02D2D4 C4201F48 */   lwc1  $f0, %lo(D_80051F48)($at)

.L7F02D2D8:
/* 061E08 7F02D2D8 C4201F4C */  lwc1  $f0, %lo(D_80051F4C)($at)
/* 061E0C 7F02D2DC 03E00008 */  jr    $ra
/* 061E10 7F02D2E0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D2E4(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80051F50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F54
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F58
.word 0x3e23d70a /*0.16*/
glabel D_80051F5C
.word 0x41200419 /*10.001*/
.text
glabel sub_GAME_7F02D2E4
/* 061E14 7F02D2E4 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 061E18 7F02D2E8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 061E1C 7F02D2EC AFA40060 */  sw    $a0, 0x60($sp)
/* 061E20 7F02D2F0 AFA50064 */  sw    $a1, 0x64($sp)
/* 061E24 7F02D2F4 AFA60068 */  sw    $a2, 0x68($sp)
/* 061E28 7F02D2F8 0FC225E6 */  jal   get_curplayer_positiondata
/* 061E2C 7F02D2FC AFA7006C */   sw    $a3, 0x6c($sp)
/* 061E30 7F02D300 8FAE0060 */  lw    $t6, 0x60($sp)
/* 061E34 7F02D304 C4440008 */  lwc1  $f4, 8($v0)
/* 061E38 7F02D308 C448000C */  lwc1  $f8, 0xc($v0)
/* 061E3C 7F02D30C 8DC30018 */  lw    $v1, 0x18($t6)
/* 061E40 7F02D310 C4660008 */  lwc1  $f6, 8($v1)
/* 061E44 7F02D314 C46A000C */  lwc1  $f10, 0xc($v1)
/* 061E48 7F02D318 46062301 */  sub.s $f12, $f4, $f6
/* 061E4C 7F02D31C 460A4101 */  sub.s $f4, $f8, $f10
/* 061E50 7F02D320 E7A40050 */  swc1  $f4, 0x50($sp)
/* 061E54 7F02D324 C4460010 */  lwc1  $f6, 0x10($v0)
/* 061E58 7F02D328 C4680010 */  lwc1  $f8, 0x10($v1)
/* 061E5C 7F02D32C E7AC0054 */  swc1  $f12, 0x54($sp)
/* 061E60 7F02D330 46083381 */  sub.s $f14, $f6, $f8
/* 061E64 7F02D334 0FC16A8C */  jal   atan2f
/* 061E68 7F02D338 E7AE004C */   swc1  $f14, 0x4c($sp)
/* 061E6C 7F02D33C E7A00048 */  swc1  $f0, 0x48($sp)
/* 061E70 7F02D340 0FC0B064 */  jal   sub_GAME_7F02C190
/* 061E74 7F02D344 8FA40060 */   lw    $a0, 0x60($sp)
/* 061E78 7F02D348 C7B00054 */  lwc1  $f16, 0x54($sp)
/* 061E7C 7F02D34C C7B20050 */  lwc1  $f18, 0x50($sp)
/* 061E80 7F02D350 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 061E84 7F02D354 46108102 */  mul.s $f4, $f16, $f16
/* 061E88 7F02D358 C7AE004C */  lwc1  $f14, 0x4c($sp)
/* 061E8C 7F02D35C 46005081 */  sub.s $f2, $f10, $f0
/* 061E90 7F02D360 46129182 */  mul.s $f6, $f18, $f18
/* 061E94 7F02D364 E7A00044 */  swc1  $f0, 0x44($sp)
/* 061E98 7F02D368 460E7282 */  mul.s $f10, $f14, $f14
/* 061E9C 7F02D36C E7A20040 */  swc1  $f2, 0x40($sp)
/* 061EA0 7F02D370 46062200 */  add.s $f8, $f4, $f6
/* 061EA4 7F02D374 460A4300 */  add.s $f12, $f8, $f10
/* 061EA8 7F02D378 0FC0B491 */  jal   sub_GAME_7F02D244
/* 061EAC 7F02D37C E7AC001C */   swc1  $f12, 0x1c($sp)
/* 061EB0 7F02D380 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 061EB4 7F02D384 44802000 */  mtc1  $zero, $f4
/* 061EB8 7F02D388 3C018005 */  lui   $at, %hi(D_80051F50)
/* 061EBC 7F02D38C 8FAF0064 */  lw    $t7, 0x64($sp)
/* 061EC0 7F02D390 4604103C */  c.lt.s $f2, $f4
/* 061EC4 7F02D394 00000000 */  nop   
/* 061EC8 7F02D398 45020004 */  bc1fl .L7F02D3AC
/* 061ECC 7F02D39C 4600103C */   c.lt.s $f2, $f0
/* 061ED0 7F02D3A0 C4261F50 */  lwc1  $f6, %lo(D_80051F50)($at)
/* 061ED4 7F02D3A4 46061080 */  add.s $f2, $f2, $f6
/* 061ED8 7F02D3A8 4600103C */  c.lt.s $f2, $f0
.L7F02D3AC:
/* 061EDC 7F02D3AC 00001025 */  move  $v0, $zero
/* 061EE0 7F02D3B0 3C018005 */  lui   $at, %hi(D_80051F54)
/* 061EE4 7F02D3B4 45000002 */  bc1f  .L7F02D3C0
/* 061EE8 7F02D3B8 00000000 */   nop   
/* 061EEC 7F02D3BC 24020001 */  li    $v0, 1
.L7F02D3C0:
/* 061EF0 7F02D3C0 14400009 */  bnez  $v0, .L7F02D3E8
/* 061EF4 7F02D3C4 00401825 */   move  $v1, $v0
/* 061EF8 7F02D3C8 C4281F54 */  lwc1  $f8, %lo(D_80051F54)($at)
/* 061EFC 7F02D3CC 00001825 */  move  $v1, $zero
/* 061F00 7F02D3D0 46004281 */  sub.s $f10, $f8, $f0
/* 061F04 7F02D3D4 4602503C */  c.lt.s $f10, $f2
/* 061F08 7F02D3D8 00000000 */  nop   
/* 061F0C 7F02D3DC 45020003 */  bc1fl .L7F02D3EC
/* 061F10 7F02D3E0 ADE30000 */   sw    $v1, ($t7)
/* 061F14 7F02D3E4 24030001 */  li    $v1, 1
.L7F02D3E8:
/* 061F18 7F02D3E8 ADE30000 */  sw    $v1, ($t7)
.L7F02D3EC:
/* 061F1C 7F02D3EC 8FB80068 */  lw    $t8, 0x68($sp)
/* 061F20 7F02D3F0 AF000000 */  sw    $zero, ($t8)
/* 061F24 7F02D3F4 0FC227A9 */  jal   bondviewGetIfCurrentPlayerDamageShowTime
/* 061F28 7F02D3F8 AFA30024 */   sw    $v1, 0x24($sp)
/* 061F2C 7F02D3FC 14400088 */  bnez  $v0, .L7F02D620
/* 061F30 7F02D400 8FA30024 */   lw    $v1, 0x24($sp)
/* 061F34 7F02D404 50600087 */  beql  $v1, $zero, .L7F02D624
/* 061F38 7F02D408 8FBF0014 */   lw    $ra, 0x14($sp)
/* 061F3C 7F02D40C 0C007DF8 */  jal   sqrtf
/* 061F40 7F02D410 C7AC001C */   lwc1  $f12, 0x1c($sp)
/* 061F44 7F02D414 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 061F48 7F02D418 44816000 */  mtc1  $at, $f12
/* 061F4C 7F02D41C 3C018005 */  lui   $at, %hi(D_80051F58)
/* 061F50 7F02D420 C4241F58 */  lwc1  $f4, %lo(D_80051F58)($at)
/* 061F54 7F02D424 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 061F58 7F02D428 4600603C */  c.lt.s $f12, $f0
/* 061F5C 7F02D42C C4268378 */  lwc1  $f6, %lo(g_GlobalTimerDelta)($at)
/* 061F60 7F02D430 8FB90060 */  lw    $t9, 0x60($sp)
/* 061F64 7F02D434 46062082 */  mul.s $f2, $f4, $f6
/* 061F68 7F02D438 45020005 */  bc1fl .L7F02D450
/* 061F6C 7F02D43C 83220002 */   lb    $v0, 2($t9)
/* 061F70 7F02D440 46006203 */  div.s $f8, $f12, $f0
/* 061F74 7F02D444 46081082 */  mul.s $f2, $f2, $f8
/* 061F78 7F02D448 00000000 */  nop   
/* 061F7C 7F02D44C 83220002 */  lb    $v0, 2($t9)
.L7F02D450:
/* 061F80 7F02D450 1840000C */  blez  $v0, .L7F02D484
/* 061F84 7F02D454 00000000 */   nop   
/* 061F88 7F02D458 44825000 */  mtc1  $v0, $f10
/* 061F8C 7F02D45C 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 061F90 7F02D460 44813000 */  mtc1  $at, $f6
/* 061F94 7F02D464 46805120 */  cvt.s.w $f4, $f10
/* 061F98 7F02D468 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 061F9C 7F02D46C 44815000 */  mtc1  $at, $f10
/* 061FA0 7F02D470 46062203 */  div.s $f8, $f4, $f6
/* 061FA4 7F02D474 46085100 */  add.s $f4, $f10, $f8
/* 061FA8 7F02D478 46041082 */  mul.s $f2, $f2, $f4
/* 061FAC 7F02D47C 1000000F */  b     .L7F02D4BC
/* 061FB0 7F02D480 00000000 */   nop   
.L7F02D484:
/* 061FB4 7F02D484 0441000D */  bgez  $v0, .L7F02D4BC
/* 061FB8 7F02D488 2841FF9D */   slti  $at, $v0, -0x63
/* 061FBC 7F02D48C 10200004 */  beqz  $at, .L7F02D4A0
/* 061FC0 7F02D490 24480064 */   addiu $t0, $v0, 0x64
/* 061FC4 7F02D494 44801000 */  mtc1  $zero, $f2
/* 061FC8 7F02D498 10000008 */  b     .L7F02D4BC
/* 061FCC 7F02D49C 00000000 */   nop   
.L7F02D4A0:
/* 061FD0 7F02D4A0 44883000 */  mtc1  $t0, $f6
/* 061FD4 7F02D4A4 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 061FD8 7F02D4A8 44814000 */  mtc1  $at, $f8
/* 061FDC 7F02D4AC 468032A0 */  cvt.s.w $f10, $f6
/* 061FE0 7F02D4B0 46085103 */  div.s $f4, $f10, $f8
/* 061FE4 7F02D4B4 46041082 */  mul.s $f2, $f2, $f4
/* 061FE8 7F02D4B8 00000000 */  nop   
.L7F02D4BC:
/* 061FEC 7F02D4BC 0FC074D8 */  jal   get_007_accuracy_mod
/* 061FF0 7F02D4C0 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 061FF4 7F02D4C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 061FF8 7F02D4C8 44813000 */  mtc1  $at, $f6
/* 061FFC 7F02D4CC C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 062000 7F02D4D0 4606003E */  c.le.s $f0, $f6
/* 062004 7F02D4D4 00000000 */  nop   
/* 062008 7F02D4D8 45000007 */  bc1f  .L7F02D4F8
/* 06200C 7F02D4DC 00000000 */   nop   
/* 062010 7F02D4E0 0FC074D8 */  jal   get_007_accuracy_mod
/* 062014 7F02D4E4 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 062018 7F02D4E8 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 06201C 7F02D4EC 46001082 */  mul.s $f2, $f2, $f0
/* 062020 7F02D4F0 1000000C */  b     .L7F02D524
/* 062024 7F02D4F4 00000000 */   nop   
.L7F02D4F8:
/* 062028 7F02D4F8 0FC074D8 */  jal   get_007_accuracy_mod
/* 06202C 7F02D4FC E7A2002C */   swc1  $f2, 0x2c($sp)
/* 062030 7F02D500 3C014110 */  li    $at, 0x41100000 # 9.000000
/* 062034 7F02D504 44815000 */  mtc1  $at, $f10
/* 062038 7F02D508 3C018005 */  lui   $at, %hi(D_80051F5C)
/* 06203C 7F02D50C C4281F5C */  lwc1  $f8, %lo(D_80051F5C)($at)
/* 062040 7F02D510 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 062044 7F02D514 46004101 */  sub.s $f4, $f8, $f0
/* 062048 7F02D518 46045183 */  div.s $f6, $f10, $f4
/* 06204C 7F02D51C 46061082 */  mul.s $f2, $f2, $f6
/* 062050 7F02D520 00000000 */  nop   
.L7F02D524:
/* 062054 7F02D524 3C018003 */  lui   $at, %hi(g_AiAccuracyModifier)
/* 062058 7F02D528 C428CE40 */  lwc1  $f8, %lo(g_AiAccuracyModifier)($at)
/* 06205C 7F02D52C 8FA4006C */  lw    $a0, 0x6c($sp)
/* 062060 7F02D530 46081082 */  mul.s $f2, $f2, $f8
/* 062064 7F02D534 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 062068 7F02D538 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 06206C 7F02D53C 1C400002 */  bgtz  $v0, .L7F02D548
/* 062070 7F02D540 C7A2002C */   lwc1  $f2, 0x2c($sp)
/* 062074 7F02D544 46021080 */  add.s $f2, $f2, $f2
.L7F02D548:
/* 062078 7F02D548 8FA4006C */  lw    $a0, 0x6c($sp)
/* 06207C 7F02D54C 2401000F */  li    $at, 15
/* 062080 7F02D550 8FA20060 */  lw    $v0, 0x60($sp)
/* 062084 7F02D554 10810003 */  beq   $a0, $at, .L7F02D564
/* 062088 7F02D558 24010010 */   li    $at, 16
/* 06208C 7F02D55C 54810003 */  bnel  $a0, $at, .L7F02D56C
/* 062090 7F02D560 C44A013C */   lwc1  $f10, 0x13c($v0)
.L7F02D564:
/* 062094 7F02D564 46021080 */  add.s $f2, $f2, $f2
/* 062098 7F02D568 C44A013C */  lwc1  $f10, 0x13c($v0)
.L7F02D56C:
/* 06209C 7F02D56C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0620A0 7F02D570 44814000 */  mtc1  $at, $f8
/* 0620A4 7F02D574 46025100 */  add.s $f4, $f10, $f2
/* 0620A8 7F02D578 E444013C */  swc1  $f4, 0x13c($v0)
/* 0620AC 7F02D57C C446013C */  lwc1  $f6, 0x13c($v0)
/* 0620B0 7F02D580 4606403E */  c.le.s $f8, $f6
/* 0620B4 7F02D584 00000000 */  nop   
/* 0620B8 7F02D588 45020026 */  bc1fl .L7F02D624
/* 0620BC 7F02D58C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0620C0 7F02D590 0FC177E1 */  jal   bondwalkItemGetDestructionAmount
/* 0620C4 7F02D594 00000000 */   nop   
/* 0620C8 7F02D598 0FC074C9 */  jal   get_007_damage_mod
/* 0620CC 7F02D59C E7A00020 */   swc1  $f0, 0x20($sp)
/* 0620D0 7F02D5A0 3C013E00 */  li    $at, 0x3E000000 # 0.125000
/* 0620D4 7F02D5A4 44815000 */  mtc1  $at, $f10
/* 0620D8 7F02D5A8 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0620DC 7F02D5AC 3C018003 */  lui   $at, %hi(g_AiDamageModifier)
/* 0620E0 7F02D5B0 C428CE44 */  lwc1  $f8, %lo(g_AiDamageModifier)($at)
/* 0620E4 7F02D5B4 46045182 */  mul.s $f6, $f10, $f4
/* 0620E8 7F02D5B8 8FA9006C */  lw    $t1, 0x6c($sp)
/* 0620EC 7F02D5BC 2401000F */  li    $at, 15
/* 0620F0 7F02D5C0 C7AE0044 */  lwc1  $f14, 0x44($sp)
/* 0620F4 7F02D5C4 2406FFFF */  li    $a2, -1
/* 0620F8 7F02D5C8 46083282 */  mul.s $f10, $f6, $f8
/* 0620FC 7F02D5CC 00000000 */  nop   
/* 062100 7F02D5D0 460A0302 */  mul.s $f12, $f0, $f10
/* 062104 7F02D5D4 11210003 */  beq   $t1, $at, .L7F02D5E4
/* 062108 7F02D5D8 00000000 */   nop   
/* 06210C 7F02D5DC 24010010 */  li    $at, 16
/* 062110 7F02D5E0 15210005 */  bne   $t1, $at, .L7F02D5F8
.L7F02D5E4:
/* 062114 7F02D5E4 3C014040 */   li    $at, 0x40400000 # 3.000000
/* 062118 7F02D5E8 44812000 */  mtc1  $at, $f4
/* 06211C 7F02D5EC 00000000 */  nop   
/* 062120 7F02D5F0 46046302 */  mul.s $f12, $f12, $f4
/* 062124 7F02D5F4 00000000 */  nop   
.L7F02D5F8:
/* 062128 7F02D5F8 0FC22793 */  jal   bondviewCallRecordDamageKills
/* 06212C 7F02D5FC 24070001 */   li    $a3, 1
/* 062130 7F02D600 44803000 */  mtc1  $zero, $f6
/* 062134 7F02D604 8FAA0060 */  lw    $t2, 0x60($sp)
/* 062138 7F02D608 0FC227A9 */  jal   bondviewGetIfCurrentPlayerDamageShowTime
/* 06213C 7F02D60C E546013C */   swc1  $f6, 0x13c($t2)
/* 062140 7F02D610 10400003 */  beqz  $v0, .L7F02D620
/* 062144 7F02D614 8FAC0068 */   lw    $t4, 0x68($sp)
/* 062148 7F02D618 240B0001 */  li    $t3, 1
/* 06214C 7F02D61C AD8B0000 */  sw    $t3, ($t4)
.L7F02D620:
/* 062150 7F02D620 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02D624:
/* 062154 7F02D624 27BD0060 */  addiu $sp, $sp, 0x60
/* 062158 7F02D628 03E00008 */  jr    $ra
/* 06215C 7F02D62C 00000000 */   nop   
)
#endif
#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_80051F50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F54
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F58
.word 0x3e23d70a /*0.16*/
glabel D_80051F5C
.word 0x41200419 /*10.001*/
.text
glabel sub_GAME_7F02D2E4
/* 061E14 7F02D2E4 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 061E18 7F02D2E8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 061E1C 7F02D2EC AFA40060 */  sw    $a0, 0x60($sp)
/* 061E20 7F02D2F0 AFA50064 */  sw    $a1, 0x64($sp)
/* 061E24 7F02D2F4 AFA60068 */  sw    $a2, 0x68($sp)
/* 061E28 7F02D2F8 0FC225E6 */  jal   get_curplayer_positiondata
/* 061E2C 7F02D2FC AFA7006C */   sw    $a3, 0x6c($sp)
/* 061E30 7F02D300 8FAE0060 */  lw    $t6, 0x60($sp)
/* 061E34 7F02D304 C4440008 */  lwc1  $f4, 8($v0)
/* 061E38 7F02D308 C448000C */  lwc1  $f8, 0xc($v0)
/* 061E3C 7F02D30C 8DC30018 */  lw    $v1, 0x18($t6)
/* 061E40 7F02D310 C4660008 */  lwc1  $f6, 8($v1)
/* 061E44 7F02D314 C46A000C */  lwc1  $f10, 0xc($v1)
/* 061E48 7F02D318 46062301 */  sub.s $f12, $f4, $f6
/* 061E4C 7F02D31C 460A4101 */  sub.s $f4, $f8, $f10
/* 061E50 7F02D320 E7A40050 */  swc1  $f4, 0x50($sp)
/* 061E54 7F02D324 C4460010 */  lwc1  $f6, 0x10($v0)
/* 061E58 7F02D328 C4680010 */  lwc1  $f8, 0x10($v1)
/* 061E5C 7F02D32C E7AC0054 */  swc1  $f12, 0x54($sp)
/* 061E60 7F02D330 46083381 */  sub.s $f14, $f6, $f8
/* 061E64 7F02D334 0FC16A8C */  jal   atan2f
/* 061E68 7F02D338 E7AE004C */   swc1  $f14, 0x4c($sp)
/* 061E6C 7F02D33C E7A00048 */  swc1  $f0, 0x48($sp)
/* 061E70 7F02D340 0FC0B064 */  jal   sub_GAME_7F02C190
/* 061E74 7F02D344 8FA40060 */   lw    $a0, 0x60($sp)
/* 061E78 7F02D348 C7B00054 */  lwc1  $f16, 0x54($sp)
/* 061E7C 7F02D34C C7B20050 */  lwc1  $f18, 0x50($sp)
/* 061E80 7F02D350 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 061E84 7F02D354 46108102 */  mul.s $f4, $f16, $f16
/* 061E88 7F02D358 C7AE004C */  lwc1  $f14, 0x4c($sp)
/* 061E8C 7F02D35C 46005081 */  sub.s $f2, $f10, $f0
/* 061E90 7F02D360 46129182 */  mul.s $f6, $f18, $f18
/* 061E94 7F02D364 E7A00044 */  swc1  $f0, 0x44($sp)
/* 061E98 7F02D368 460E7282 */  mul.s $f10, $f14, $f14
/* 061E9C 7F02D36C E7A20040 */  swc1  $f2, 0x40($sp)
/* 061EA0 7F02D370 46062200 */  add.s $f8, $f4, $f6
/* 061EA4 7F02D374 460A4300 */  add.s $f12, $f8, $f10
/* 061EA8 7F02D378 0FC0B491 */  jal   sub_GAME_7F02D244
/* 061EAC 7F02D37C E7AC001C */   swc1  $f12, 0x1c($sp)
/* 061EB0 7F02D380 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 061EB4 7F02D384 44802000 */  mtc1  $zero, $f4
/* 061EB8 7F02D388 3C018005 */  lui   $at, %hi(D_80051F50)
/* 061EBC 7F02D38C 8FAF0064 */  lw    $t7, 0x64($sp)
/* 061EC0 7F02D390 4604103C */  c.lt.s $f2, $f4
/* 061EC4 7F02D394 00000000 */  nop   
/* 061EC8 7F02D398 45020004 */  bc1fl .L7F02D3AC
/* 061ECC 7F02D39C 4600103C */   c.lt.s $f2, $f0
/* 061ED0 7F02D3A0 C4261F50 */  lwc1  $f6, %lo(D_80051F50)($at)
/* 061ED4 7F02D3A4 46061080 */  add.s $f2, $f2, $f6
/* 061ED8 7F02D3A8 4600103C */  c.lt.s $f2, $f0
.L7F02D3AC:
/* 061EDC 7F02D3AC 00001025 */  move  $v0, $zero
/* 061EE0 7F02D3B0 3C018005 */  lui   $at, %hi(D_80051F54)
/* 061EE4 7F02D3B4 45000002 */  bc1f  .L7F02D3C0
/* 061EE8 7F02D3B8 00000000 */   nop   
/* 061EEC 7F02D3BC 24020001 */  li    $v0, 1
.L7F02D3C0:
/* 061EF0 7F02D3C0 14400009 */  bnez  $v0, .L7F02D3E8
/* 061EF4 7F02D3C4 00401825 */   move  $v1, $v0
/* 061EF8 7F02D3C8 C4281F54 */  lwc1  $f8, %lo(D_80051F54)($at)
/* 061EFC 7F02D3CC 00001825 */  move  $v1, $zero
/* 061F00 7F02D3D0 46004281 */  sub.s $f10, $f8, $f0
/* 061F04 7F02D3D4 4602503C */  c.lt.s $f10, $f2
/* 061F08 7F02D3D8 00000000 */  nop   
/* 061F0C 7F02D3DC 45020003 */  bc1fl .L7F02D3EC
/* 061F10 7F02D3E0 ADE30000 */   sw    $v1, ($t7)
/* 061F14 7F02D3E4 24030001 */  li    $v1, 1
.L7F02D3E8:
/* 061F18 7F02D3E8 ADE30000 */  sw    $v1, ($t7)
.L7F02D3EC:
/* 061F1C 7F02D3EC 8FB80068 */  lw    $t8, 0x68($sp)
/* 061F20 7F02D3F0 AF000000 */  sw    $zero, ($t8)
/* 061F24 7F02D3F4 0FC227A9 */  jal   bondviewGetIfCurrentPlayerDamageShowTime
/* 061F28 7F02D3F8 AFA30024 */   sw    $v1, 0x24($sp)
/* 061F2C 7F02D3FC 14400088 */  bnez  $v0, .L7F02D620
/* 061F30 7F02D400 8FA30024 */   lw    $v1, 0x24($sp)
/* 061F34 7F02D404 50600087 */  beql  $v1, $zero, .L7F02D624
/* 061F38 7F02D408 8FBF0014 */   lw    $ra, 0x14($sp)
/* 061F3C 7F02D40C 0C007DF8 */  jal   sqrtf
/* 061F40 7F02D410 C7AC001C */   lwc1  $f12, 0x1c($sp)
/* 061F44 7F02D414 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 061F48 7F02D418 44816000 */  mtc1  $at, $f12
/* 061F4C 7F02D41C 3C018005 */  lui   $at, %hi(D_80051F58)
/* 061F50 7F02D420 C4241F58 */  lwc1  $f4, %lo(D_80051F58)($at)
/* 061F54 7F02D424 3C018005 */  lui   $at, %hi(g_JP_GlobalTimerDelta)
/* 061F58 7F02D428 4600603C */  c.lt.s $f12, $f0
/* 061F5C 7F02D42C C4268378 */  lwc1  $f6, %lo(g_JP_GlobalTimerDelta)($at)
/* 061F60 7F02D430 8FB90060 */  lw    $t9, 0x60($sp)
/* 061F64 7F02D434 46062082 */  mul.s $f2, $f4, $f6
/* 061F68 7F02D438 45020005 */  bc1fl .L7F02D450
/* 061F6C 7F02D43C 83220002 */   lb    $v0, 2($t9)
/* 061F70 7F02D440 46006203 */  div.s $f8, $f12, $f0
/* 061F74 7F02D444 46081082 */  mul.s $f2, $f2, $f8
/* 061F78 7F02D448 00000000 */  nop   
/* 061F7C 7F02D44C 83220002 */  lb    $v0, 2($t9)
.L7F02D450:
/* 061F80 7F02D450 1840000C */  blez  $v0, .L7F02D484
/* 061F84 7F02D454 00000000 */   nop   
/* 061F88 7F02D458 44825000 */  mtc1  $v0, $f10
/* 061F8C 7F02D45C 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 061F90 7F02D460 44813000 */  mtc1  $at, $f6
/* 061F94 7F02D464 46805120 */  cvt.s.w $f4, $f10
/* 061F98 7F02D468 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 061F9C 7F02D46C 44815000 */  mtc1  $at, $f10
/* 061FA0 7F02D470 46062203 */  div.s $f8, $f4, $f6
/* 061FA4 7F02D474 46085100 */  add.s $f4, $f10, $f8
/* 061FA8 7F02D478 46041082 */  mul.s $f2, $f2, $f4
/* 061FAC 7F02D47C 1000000F */  b     .L7F02D4BC
/* 061FB0 7F02D480 00000000 */   nop   
.L7F02D484:
/* 061FB4 7F02D484 0441000D */  bgez  $v0, .L7F02D4BC
/* 061FB8 7F02D488 2841FF9D */   slti  $at, $v0, -0x63
/* 061FBC 7F02D48C 10200004 */  beqz  $at, .L7F02D4A0
/* 061FC0 7F02D490 24480064 */   addiu $t0, $v0, 0x64
/* 061FC4 7F02D494 44801000 */  mtc1  $zero, $f2
/* 061FC8 7F02D498 10000008 */  b     .L7F02D4BC
/* 061FCC 7F02D49C 00000000 */   nop   
.L7F02D4A0:
/* 061FD0 7F02D4A0 44883000 */  mtc1  $t0, $f6
/* 061FD4 7F02D4A4 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 061FD8 7F02D4A8 44814000 */  mtc1  $at, $f8
/* 061FDC 7F02D4AC 468032A0 */  cvt.s.w $f10, $f6
/* 061FE0 7F02D4B0 46085103 */  div.s $f4, $f10, $f8
/* 061FE4 7F02D4B4 46041082 */  mul.s $f2, $f2, $f4
/* 061FE8 7F02D4B8 00000000 */  nop   
.L7F02D4BC:
/* 061FEC 7F02D4BC 0FC074D8 */  jal   get_007_accuracy_mod
/* 061FF0 7F02D4C0 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 061FF4 7F02D4C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 061FF8 7F02D4C8 44813000 */  mtc1  $at, $f6
/* 061FFC 7F02D4CC C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 062000 7F02D4D0 4606003E */  c.le.s $f0, $f6
/* 062004 7F02D4D4 00000000 */  nop   
/* 062008 7F02D4D8 45000007 */  bc1f  .L7F02D4F8
/* 06200C 7F02D4DC 00000000 */   nop   
/* 062010 7F02D4E0 0FC074D8 */  jal   get_007_accuracy_mod
/* 062014 7F02D4E4 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 062018 7F02D4E8 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 06201C 7F02D4EC 46001082 */  mul.s $f2, $f2, $f0
/* 062020 7F02D4F0 1000000C */  b     .L7F02D524
/* 062024 7F02D4F4 00000000 */   nop   
.L7F02D4F8:
/* 062028 7F02D4F8 0FC074D8 */  jal   get_007_accuracy_mod
/* 06202C 7F02D4FC E7A2002C */   swc1  $f2, 0x2c($sp)
/* 062030 7F02D500 3C014110 */  li    $at, 0x41100000 # 9.000000
/* 062034 7F02D504 44815000 */  mtc1  $at, $f10
/* 062038 7F02D508 3C018005 */  lui   $at, %hi(D_80051F5C)
/* 06203C 7F02D50C C4281F5C */  lwc1  $f8, %lo(D_80051F5C)($at)
/* 062040 7F02D510 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 062044 7F02D514 46004101 */  sub.s $f4, $f8, $f0
/* 062048 7F02D518 46045183 */  div.s $f6, $f10, $f4
/* 06204C 7F02D51C 46061082 */  mul.s $f2, $f2, $f6
/* 062050 7F02D520 00000000 */  nop   
.L7F02D524:
/* 062054 7F02D524 3C018003 */  lui   $at, %hi(g_AiAccuracyModifier)
/* 062058 7F02D528 C428CE40 */  lwc1  $f8, %lo(g_AiAccuracyModifier)($at)
/* 06205C 7F02D52C 8FA4006C */  lw    $a0, 0x6c($sp)
/* 062060 7F02D530 46081082 */  mul.s $f2, $f2, $f8
/* 062064 7F02D534 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 062068 7F02D538 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 06206C 7F02D53C 1C400002 */  bgtz  $v0, .L7F02D548
/* 062070 7F02D540 C7A2002C */   lwc1  $f2, 0x2c($sp)
/* 062074 7F02D544 46021080 */  add.s $f2, $f2, $f2
.L7F02D548:
/* 062078 7F02D548 8FA4006C */  lw    $a0, 0x6c($sp)
/* 06207C 7F02D54C 2401000F */  li    $at, 15
/* 062080 7F02D550 8FA20060 */  lw    $v0, 0x60($sp)
/* 062084 7F02D554 10810003 */  beq   $a0, $at, .L7F02D564
/* 062088 7F02D558 24010010 */   li    $at, 16
/* 06208C 7F02D55C 54810003 */  bnel  $a0, $at, .L7F02D56C
/* 062090 7F02D560 C44A013C */   lwc1  $f10, 0x13c($v0)
.L7F02D564:
/* 062094 7F02D564 46021080 */  add.s $f2, $f2, $f2
/* 062098 7F02D568 C44A013C */  lwc1  $f10, 0x13c($v0)
.L7F02D56C:
/* 06209C 7F02D56C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0620A0 7F02D570 44814000 */  mtc1  $at, $f8
/* 0620A4 7F02D574 46025100 */  add.s $f4, $f10, $f2
/* 0620A8 7F02D578 E444013C */  swc1  $f4, 0x13c($v0)
/* 0620AC 7F02D57C C446013C */  lwc1  $f6, 0x13c($v0)
/* 0620B0 7F02D580 4606403E */  c.le.s $f8, $f6
/* 0620B4 7F02D584 00000000 */  nop   
/* 0620B8 7F02D588 45020026 */  bc1fl .L7F02D624
/* 0620BC 7F02D58C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0620C0 7F02D590 0FC177E1 */  jal   bondwalkItemGetDestructionAmount
/* 0620C4 7F02D594 00000000 */   nop   
/* 0620C8 7F02D598 0FC074C9 */  jal   get_007_damage_mod
/* 0620CC 7F02D59C E7A00020 */   swc1  $f0, 0x20($sp)
/* 0620D0 7F02D5A0 3C013E00 */  li    $at, 0x3E000000 # 0.125000
/* 0620D4 7F02D5A4 44815000 */  mtc1  $at, $f10
/* 0620D8 7F02D5A8 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0620DC 7F02D5AC 3C018003 */  lui   $at, %hi(g_AiDamageModifier)
/* 0620E0 7F02D5B0 C428CE44 */  lwc1  $f8, %lo(g_AiDamageModifier)($at)
/* 0620E4 7F02D5B4 46045182 */  mul.s $f6, $f10, $f4
/* 0620E8 7F02D5B8 8FA9006C */  lw    $t1, 0x6c($sp)
/* 0620EC 7F02D5BC 2401000F */  li    $at, 15
/* 0620F0 7F02D5C0 C7AE0044 */  lwc1  $f14, 0x44($sp)
/* 0620F4 7F02D5C4 2406FFFF */  li    $a2, -1
/* 0620F8 7F02D5C8 46083282 */  mul.s $f10, $f6, $f8
/* 0620FC 7F02D5CC 00000000 */  nop   
/* 062100 7F02D5D0 460A0302 */  mul.s $f12, $f0, $f10
/* 062104 7F02D5D4 11210003 */  beq   $t1, $at, .L7F02D5E4
/* 062108 7F02D5D8 00000000 */   nop   
/* 06210C 7F02D5DC 24010010 */  li    $at, 16
/* 062110 7F02D5E0 15210005 */  bne   $t1, $at, .L7F02D5F8
.L7F02D5E4:
/* 062114 7F02D5E4 3C014040 */   li    $at, 0x40400000 # 3.000000
/* 062118 7F02D5E8 44812000 */  mtc1  $at, $f4
/* 06211C 7F02D5EC 00000000 */  nop   
/* 062120 7F02D5F0 46046302 */  mul.s $f12, $f12, $f4
/* 062124 7F02D5F4 00000000 */  nop   
.L7F02D5F8:
/* 062128 7F02D5F8 0FC22793 */  jal   bondviewCallRecordDamageKills
/* 06212C 7F02D5FC 24070001 */   li    $a3, 1
/* 062130 7F02D600 44803000 */  mtc1  $zero, $f6
/* 062134 7F02D604 8FAA0060 */  lw    $t2, 0x60($sp)
/* 062138 7F02D608 0FC227A9 */  jal   bondviewGetIfCurrentPlayerDamageShowTime
/* 06213C 7F02D60C E546013C */   swc1  $f6, 0x13c($t2)
/* 062140 7F02D610 10400003 */  beqz  $v0, .L7F02D620
/* 062144 7F02D614 8FAC0068 */   lw    $t4, 0x68($sp)
/* 062148 7F02D618 240B0001 */  li    $t3, 1
/* 06214C 7F02D61C AD8B0000 */  sw    $t3, ($t4)
.L7F02D620:
/* 062150 7F02D620 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02D624:
/* 062154 7F02D624 27BD0060 */  addiu $sp, $sp, 0x60
/* 062158 7F02D628 03E00008 */  jr    $ra
/* 06215C 7F02D62C 00000000 */   nop   
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80051F50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F54
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F58
.word 0x3e23d70a /*0.16*/
glabel D_80051F5C
.word 0x41200419 /*10.001*/
.text
glabel sub_GAME_7F02D2E4
/* 061E14 7F02D2E4 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 061E18 7F02D2E8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 061E1C 7F02D2EC AFA40060 */  sw    $a0, 0x60($sp)
/* 061E20 7F02D2F0 AFA50064 */  sw    $a1, 0x64($sp)
/* 061E24 7F02D2F4 AFA60068 */  sw    $a2, 0x68($sp)
/* 061E28 7F02D2F8 0FC225E6 */  jal   get_curplayer_positiondata
/* 061E2C 7F02D2FC AFA7006C */   sw    $a3, 0x6c($sp)
/* 061E30 7F02D300 8FAE0060 */  lw    $t6, 0x60($sp)
/* 061E34 7F02D304 C4440008 */  lwc1  $f4, 8($v0)
/* 061E38 7F02D308 C448000C */  lwc1  $f8, 0xc($v0)
/* 061E3C 7F02D30C 8DC30018 */  lw    $v1, 0x18($t6)
/* 061E40 7F02D310 C4660008 */  lwc1  $f6, 8($v1)
/* 061E44 7F02D314 C46A000C */  lwc1  $f10, 0xc($v1)
/* 061E48 7F02D318 46062301 */  sub.s $f12, $f4, $f6
/* 061E4C 7F02D31C 460A4101 */  sub.s $f4, $f8, $f10
/* 061E50 7F02D320 E7A40050 */  swc1  $f4, 0x50($sp)
/* 061E54 7F02D324 C4460010 */  lwc1  $f6, 0x10($v0)
/* 061E58 7F02D328 C4680010 */  lwc1  $f8, 0x10($v1)
/* 061E5C 7F02D32C E7AC0054 */  swc1  $f12, 0x54($sp)
/* 061E60 7F02D330 46083381 */  sub.s $f14, $f6, $f8
/* 061E64 7F02D334 0FC16A8C */  jal   atan2f
/* 061E68 7F02D338 E7AE004C */   swc1  $f14, 0x4c($sp)
/* 061E6C 7F02D33C E7A00048 */  swc1  $f0, 0x48($sp)
/* 061E70 7F02D340 0FC0B064 */  jal   sub_GAME_7F02C190
/* 061E74 7F02D344 8FA40060 */   lw    $a0, 0x60($sp)
/* 061E78 7F02D348 C7B00054 */  lwc1  $f16, 0x54($sp)
/* 061E7C 7F02D34C C7B20050 */  lwc1  $f18, 0x50($sp)
/* 061E80 7F02D350 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 061E84 7F02D354 46108102 */  mul.s $f4, $f16, $f16
/* 061E88 7F02D358 C7AE004C */  lwc1  $f14, 0x4c($sp)
/* 061E8C 7F02D35C 46005081 */  sub.s $f2, $f10, $f0
/* 061E90 7F02D360 46129182 */  mul.s $f6, $f18, $f18
/* 061E94 7F02D364 E7A00044 */  swc1  $f0, 0x44($sp)
/* 061E98 7F02D368 460E7282 */  mul.s $f10, $f14, $f14
/* 061E9C 7F02D36C E7A20040 */  swc1  $f2, 0x40($sp)
/* 061EA0 7F02D370 46062200 */  add.s $f8, $f4, $f6
/* 061EA4 7F02D374 460A4300 */  add.s $f12, $f8, $f10
/* 061EA8 7F02D378 0FC0B491 */  jal   sub_GAME_7F02D244
/* 061EAC 7F02D37C E7AC001C */   swc1  $f12, 0x1c($sp)
/* 061EB0 7F02D380 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 061EB4 7F02D384 44802000 */  mtc1  $zero, $f4
/* 061EB8 7F02D388 3C018005 */  lui   $at, %hi(D_80051F50)
/* 061EBC 7F02D38C 8FAF0064 */  lw    $t7, 0x64($sp)
/* 061EC0 7F02D390 4604103C */  c.lt.s $f2, $f4
/* 061EC4 7F02D394 00000000 */  nop   
/* 061EC8 7F02D398 45020004 */  bc1fl .L7F02D3AC
/* 061ECC 7F02D39C 4600103C */   c.lt.s $f2, $f0
/* 061ED0 7F02D3A0 C4261F50 */  lwc1  $f6, %lo(D_80051F50)($at)
/* 061ED4 7F02D3A4 46061080 */  add.s $f2, $f2, $f6
/* 061ED8 7F02D3A8 4600103C */  c.lt.s $f2, $f0
.L7F02D3AC:
/* 061EDC 7F02D3AC 00001025 */  move  $v0, $zero
/* 061EE0 7F02D3B0 3C018005 */  lui   $at, %hi(D_80051F54)
/* 061EE4 7F02D3B4 45000002 */  bc1f  .L7F02D3C0
/* 061EE8 7F02D3B8 00000000 */   nop   
/* 061EEC 7F02D3BC 24020001 */  li    $v0, 1
.L7F02D3C0:
/* 061EF0 7F02D3C0 14400009 */  bnez  $v0, .L7F02D3E8
/* 061EF4 7F02D3C4 00401825 */   move  $v1, $v0
/* 061EF8 7F02D3C8 C4281F54 */  lwc1  $f8, %lo(D_80051F54)($at)
/* 061EFC 7F02D3CC 00001825 */  move  $v1, $zero
/* 061F00 7F02D3D0 46004281 */  sub.s $f10, $f8, $f0
/* 061F04 7F02D3D4 4602503C */  c.lt.s $f10, $f2
/* 061F08 7F02D3D8 00000000 */  nop   
/* 061F0C 7F02D3DC 45020003 */  bc1fl .L7F02D3EC
/* 061F10 7F02D3E0 ADE30000 */   sw    $v1, ($t7)
/* 061F14 7F02D3E4 24030001 */  li    $v1, 1
.L7F02D3E8:
/* 061F18 7F02D3E8 ADE30000 */  sw    $v1, ($t7)
.L7F02D3EC:
/* 061F1C 7F02D3EC 8FB80068 */  lw    $t8, 0x68($sp)
/* 061F20 7F02D3F0 AF000000 */  sw    $zero, ($t8)
/* 061F24 7F02D3F4 0FC227A9 */  jal   bondviewGetIfCurrentPlayerDamageShowTime
/* 061F28 7F02D3F8 AFA30024 */   sw    $v1, 0x24($sp)
/* 061F2C 7F02D3FC 14400088 */  bnez  $v0, .L7F02D620
/* 061F30 7F02D400 8FA30024 */   lw    $v1, 0x24($sp)
/* 061F34 7F02D404 50600087 */  beql  $v1, $zero, .L7F02D624
/* 061F38 7F02D408 8FBF0014 */   lw    $ra, 0x14($sp)
/* 061F3C 7F02D40C 0C007DF8 */  jal   sqrtf
/* 061F40 7F02D410 C7AC001C */   lwc1  $f12, 0x1c($sp)
/* 061F44 7F02D414 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 061F48 7F02D418 44816000 */  mtc1  $at, $f12
/* 061F4C 7F02D41C 3C018005 */  lui   $at, %hi(D_80051F58)
/* 061F50 7F02D420 C4241F58 */  lwc1  $f4, %lo(D_80051F58)($at)
/* 061F54 7F02D424 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 061F58 7F02D428 4600603C */  c.lt.s $f12, $f0
/* 061F5C 7F02D42C C4268378 */  lwc1  $f6, %lo(g_GlobalTimerDelta)($at)
/* 061F60 7F02D430 8FB90060 */  lw    $t9, 0x60($sp)
/* 061F64 7F02D434 46062082 */  mul.s $f2, $f4, $f6
/* 061F68 7F02D438 45020005 */  bc1fl .L7F02D450
/* 061F6C 7F02D43C 83220002 */   lb    $v0, 2($t9)
/* 061F70 7F02D440 46006203 */  div.s $f8, $f12, $f0
/* 061F74 7F02D444 46081082 */  mul.s $f2, $f2, $f8
/* 061F78 7F02D448 00000000 */  nop   
/* 061F7C 7F02D44C 83220002 */  lb    $v0, 2($t9)
.L7F02D450:
/* 061F80 7F02D450 1840000C */  blez  $v0, .L7F02D484
/* 061F84 7F02D454 00000000 */   nop   
/* 061F88 7F02D458 44825000 */  mtc1  $v0, $f10
/* 061F8C 7F02D45C 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 061F90 7F02D460 44813000 */  mtc1  $at, $f6
/* 061F94 7F02D464 46805120 */  cvt.s.w $f4, $f10
/* 061F98 7F02D468 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 061F9C 7F02D46C 44815000 */  mtc1  $at, $f10
/* 061FA0 7F02D470 46062203 */  div.s $f8, $f4, $f6
/* 061FA4 7F02D474 46085100 */  add.s $f4, $f10, $f8
/* 061FA8 7F02D478 46041082 */  mul.s $f2, $f2, $f4
/* 061FAC 7F02D47C 1000000F */  b     .L7F02D4BC
/* 061FB0 7F02D480 00000000 */   nop   
.L7F02D484:
/* 061FB4 7F02D484 0441000D */  bgez  $v0, .L7F02D4BC
/* 061FB8 7F02D488 2841FF9D */   slti  $at, $v0, -0x63
/* 061FBC 7F02D48C 10200004 */  beqz  $at, .L7F02D4A0
/* 061FC0 7F02D490 24480064 */   addiu $t0, $v0, 0x64
/* 061FC4 7F02D494 44801000 */  mtc1  $zero, $f2
/* 061FC8 7F02D498 10000008 */  b     .L7F02D4BC
/* 061FCC 7F02D49C 00000000 */   nop   
.L7F02D4A0:
/* 061FD0 7F02D4A0 44883000 */  mtc1  $t0, $f6
/* 061FD4 7F02D4A4 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 061FD8 7F02D4A8 44814000 */  mtc1  $at, $f8
/* 061FDC 7F02D4AC 468032A0 */  cvt.s.w $f10, $f6
/* 061FE0 7F02D4B0 46085103 */  div.s $f4, $f10, $f8
/* 061FE4 7F02D4B4 46041082 */  mul.s $f2, $f2, $f4
/* 061FE8 7F02D4B8 00000000 */  nop   
.L7F02D4BC:
/* 061FEC 7F02D4BC 0FC074D8 */  jal   get_007_accuracy_mod
/* 061FF0 7F02D4C0 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 061FF4 7F02D4C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 061FF8 7F02D4C8 44813000 */  mtc1  $at, $f6
/* 061FFC 7F02D4CC C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 062000 7F02D4D0 4606003E */  c.le.s $f0, $f6
/* 062004 7F02D4D4 00000000 */  nop   
/* 062008 7F02D4D8 45000007 */  bc1f  .L7F02D4F8
/* 06200C 7F02D4DC 00000000 */   nop   
/* 062010 7F02D4E0 0FC074D8 */  jal   get_007_accuracy_mod
/* 062014 7F02D4E4 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 062018 7F02D4E8 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 06201C 7F02D4EC 46001082 */  mul.s $f2, $f2, $f0
/* 062020 7F02D4F0 1000000C */  b     .L7F02D524
/* 062024 7F02D4F4 00000000 */   nop   
.L7F02D4F8:
/* 062028 7F02D4F8 0FC074D8 */  jal   get_007_accuracy_mod
/* 06202C 7F02D4FC E7A2002C */   swc1  $f2, 0x2c($sp)
/* 062030 7F02D500 3C014110 */  li    $at, 0x41100000 # 9.000000
/* 062034 7F02D504 44815000 */  mtc1  $at, $f10
/* 062038 7F02D508 3C018005 */  lui   $at, %hi(D_80051F5C)
/* 06203C 7F02D50C C4281F5C */  lwc1  $f8, %lo(D_80051F5C)($at)
/* 062040 7F02D510 C7A2002C */  lwc1  $f2, 0x2c($sp)
/* 062044 7F02D514 46004101 */  sub.s $f4, $f8, $f0
/* 062048 7F02D518 46045183 */  div.s $f6, $f10, $f4
/* 06204C 7F02D51C 46061082 */  mul.s $f2, $f2, $f6
/* 062050 7F02D520 00000000 */  nop   
.L7F02D524:
/* 062054 7F02D524 3C018003 */  lui   $at, %hi(g_AiAccuracyModifier)
/* 062058 7F02D528 C428CE40 */  lwc1  $f8, %lo(g_AiAccuracyModifier)($at)
/* 06205C 7F02D52C 8FA4006C */  lw    $a0, 0x6c($sp)
/* 062060 7F02D530 46081082 */  mul.s $f2, $f2, $f8
/* 062064 7F02D534 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 062068 7F02D538 E7A2002C */   swc1  $f2, 0x2c($sp)
/* 06206C 7F02D53C 1C400002 */  bgtz  $v0, .L7F02D548
/* 062070 7F02D540 C7A2002C */   lwc1  $f2, 0x2c($sp)
/* 062074 7F02D544 46021080 */  add.s $f2, $f2, $f2
.L7F02D548:
/* 062078 7F02D548 8FA4006C */  lw    $a0, 0x6c($sp)
/* 06207C 7F02D54C 2401000F */  li    $at, 15
/* 062080 7F02D550 8FA20060 */  lw    $v0, 0x60($sp)
/* 062084 7F02D554 10810003 */  beq   $a0, $at, .L7F02D564
/* 062088 7F02D558 24010010 */   li    $at, 16
/* 06208C 7F02D55C 54810003 */  bnel  $a0, $at, .L7F02D56C
/* 062090 7F02D560 C44A013C */   lwc1  $f10, 0x13c($v0)
.L7F02D564:
/* 062094 7F02D564 46021080 */  add.s $f2, $f2, $f2
/* 062098 7F02D568 C44A013C */  lwc1  $f10, 0x13c($v0)
.L7F02D56C:
/* 06209C 7F02D56C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0620A0 7F02D570 44814000 */  mtc1  $at, $f8
/* 0620A4 7F02D574 46025100 */  add.s $f4, $f10, $f2
/* 0620A8 7F02D578 E444013C */  swc1  $f4, 0x13c($v0)
/* 0620AC 7F02D57C C446013C */  lwc1  $f6, 0x13c($v0)
/* 0620B0 7F02D580 4606403E */  c.le.s $f8, $f6
/* 0620B4 7F02D584 00000000 */  nop   
/* 0620B8 7F02D588 45020026 */  bc1fl .L7F02D624
/* 0620BC 7F02D58C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0620C0 7F02D590 0FC177E1 */  jal   bondwalkItemGetDestructionAmount
/* 0620C4 7F02D594 00000000 */   nop   
/* 0620C8 7F02D598 0FC074C9 */  jal   get_007_damage_mod
/* 0620CC 7F02D59C E7A00020 */   swc1  $f0, 0x20($sp)
/* 0620D0 7F02D5A0 3C013E00 */  li    $at, 0x3E000000 # 0.125000
/* 0620D4 7F02D5A4 44815000 */  mtc1  $at, $f10
/* 0620D8 7F02D5A8 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0620DC 7F02D5AC 3C018003 */  lui   $at, %hi(g_AiDamageModifier)
/* 0620E0 7F02D5B0 C428CE44 */  lwc1  $f8, %lo(g_AiDamageModifier)($at)
/* 0620E4 7F02D5B4 46045182 */  mul.s $f6, $f10, $f4
/* 0620E8 7F02D5B8 8FA9006C */  lw    $t1, 0x6c($sp)
/* 0620EC 7F02D5BC 2401000F */  li    $at, 15
/* 0620F0 7F02D5C0 C7AE0044 */  lwc1  $f14, 0x44($sp)
/* 0620F4 7F02D5C4 2406FFFF */  li    $a2, -1
/* 0620F8 7F02D5C8 46083282 */  mul.s $f10, $f6, $f8
/* 0620FC 7F02D5CC 00000000 */  nop   
/* 062100 7F02D5D0 460A0302 */  mul.s $f12, $f0, $f10
/* 062104 7F02D5D4 11210003 */  beq   $t1, $at, .L7F02D5E4
/* 062108 7F02D5D8 00000000 */   nop   
/* 06210C 7F02D5DC 24010010 */  li    $at, 16
/* 062110 7F02D5E0 15210005 */  bne   $t1, $at, .L7F02D5F8
.L7F02D5E4:
/* 062114 7F02D5E4 3C014040 */   li    $at, 0x40400000 # 3.000000
/* 062118 7F02D5E8 44812000 */  mtc1  $at, $f4
/* 06211C 7F02D5EC 00000000 */  nop   
/* 062120 7F02D5F0 46046302 */  mul.s $f12, $f12, $f4
/* 062124 7F02D5F4 00000000 */  nop   
.L7F02D5F8:
/* 062128 7F02D5F8 0FC22793 */  jal   bondviewCallRecordDamageKills
/* 06212C 7F02D5FC 24070001 */   li    $a3, 1
/* 062130 7F02D600 44803000 */  mtc1  $zero, $f6
/* 062134 7F02D604 8FAA0060 */  lw    $t2, 0x60($sp)
/* 062138 7F02D608 0FC227A9 */  jal   bondviewGetIfCurrentPlayerDamageShowTime
/* 06213C 7F02D60C E546013C */   swc1  $f6, 0x13c($t2)
/* 062140 7F02D610 10400003 */  beqz  $v0, .L7F02D620
/* 062144 7F02D614 8FAC0068 */   lw    $t4, 0x68($sp)
/* 062148 7F02D618 240B0001 */  li    $t3, 1
/* 06214C 7F02D61C AD8B0000 */  sw    $t3, ($t4)
.L7F02D620:
/* 062150 7F02D620 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F02D624:
/* 062154 7F02D624 27BD0060 */  addiu $sp, $sp, 0x60
/* 062158 7F02D628 03E00008 */  jr    $ra
/* 06215C 7F02D62C 00000000 */   nop   
)
#endif

#endif


#ifdef NONMATCHING
void sub_GAME_7F02D630(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02D630
/* 062160 7F02D630 27BDFF38 */  addiu $sp, $sp, -0xc8
/* 062164 7F02D634 AFBF001C */  sw    $ra, 0x1c($sp)
/* 062168 7F02D638 AFB00018 */  sw    $s0, 0x18($sp)
/* 06216C 7F02D63C 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 062170 7F02D640 00C08025 */   move  $s0, $a2
/* 062174 7F02D644 10400036 */  beqz  $v0, .L7F02D720
/* 062178 7F02D648 00003025 */   move  $a2, $zero
/* 06217C 7F02D64C 904E0001 */  lbu   $t6, 1($v0)
/* 062180 7F02D650 8C430004 */  lw    $v1, 4($v0)
/* 062184 7F02D654 31CF0002 */  andi  $t7, $t6, 2
/* 062188 7F02D658 11E00031 */  beqz  $t7, .L7F02D720
/* 06218C 7F02D65C 8C640014 */   lw    $a0, 0x14($v1)
/* 062190 7F02D660 8C980008 */  lw    $t8, 8($a0)
/* 062194 7F02D664 8F020008 */  lw    $v0, 8($t8)
/* 062198 7F02D668 8C450000 */  lw    $a1, ($v0)
/* 06219C 7F02D66C 50A0001B */  beql  $a1, $zero, .L7F02D6DC
/* 0621A0 7F02D670 8C450004 */   lw    $a1, 4($v0)
/* 0621A4 7F02D674 00003025 */  move  $a2, $zero
/* 0621A8 7F02D678 0FC1B198 */  jal   sub_GAME_7F06C660
/* 0621AC 7F02D67C AFA400BC */   sw    $a0, 0xbc($sp)
/* 0621B0 7F02D680 8FA400BC */  lw    $a0, 0xbc($sp)
/* 0621B4 7F02D684 AFA200B4 */  sw    $v0, 0xb4($sp)
/* 0621B8 7F02D688 8C990008 */  lw    $t9, 8($a0)
/* 0621BC 7F02D68C 8F280008 */  lw    $t0, 8($t9)
/* 0621C0 7F02D690 8D090000 */  lw    $t1, ($t0)
/* 0621C4 7F02D694 8D230004 */  lw    $v1, 4($t1)
/* 0621C8 7F02D698 C4640000 */  lwc1  $f4, ($v1)
/* 0621CC 7F02D69C E6040000 */  swc1  $f4, ($s0)
/* 0621D0 7F02D6A0 C4660004 */  lwc1  $f6, 4($v1)
/* 0621D4 7F02D6A4 E6060004 */  swc1  $f6, 4($s0)
/* 0621D8 7F02D6A8 C4680008 */  lwc1  $f8, 8($v1)
/* 0621DC 7F02D6AC 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 0621E0 7F02D6B0 E6080008 */   swc1  $f8, 8($s0)
/* 0621E4 7F02D6B4 00402025 */  move  $a0, $v0
/* 0621E8 7F02D6B8 8FA500B4 */  lw    $a1, 0xb4($sp)
/* 0621EC 7F02D6BC 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 0621F0 7F02D6C0 27A60074 */   addiu $a2, $sp, 0x74
/* 0621F4 7F02D6C4 27A40074 */  addiu $a0, $sp, 0x74
/* 0621F8 7F02D6C8 0FC1611D */  jal   matrix_4x4_transform_vector_in_place
/* 0621FC 7F02D6CC 02002825 */   move  $a1, $s0
/* 062200 7F02D6D0 10000013 */  b     .L7F02D720
/* 062204 7F02D6D4 24060001 */   li    $a2, 1
/* 062208 7F02D6D8 8C450004 */  lw    $a1, 4($v0)
.L7F02D6DC:
/* 06220C 7F02D6DC 50A00011 */  beql  $a1, $zero, .L7F02D724
/* 062210 7F02D6E0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 062214 7F02D6E4 0FC1B198 */  jal   sub_GAME_7F06C660
/* 062218 7F02D6E8 00003025 */   move  $a2, $zero
/* 06221C 7F02D6EC 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 062220 7F02D6F0 AFA2006C */   sw    $v0, 0x6c($sp)
/* 062224 7F02D6F4 00402025 */  move  $a0, $v0
/* 062228 7F02D6F8 8FA5006C */  lw    $a1, 0x6c($sp)
/* 06222C 7F02D6FC 0FC16063 */  jal   matrix_4x4_multiply_homogeneous
/* 062230 7F02D700 27A6002C */   addiu $a2, $sp, 0x2c
/* 062234 7F02D704 C7AA005C */  lwc1  $f10, 0x5c($sp)
/* 062238 7F02D708 24060001 */  li    $a2, 1
/* 06223C 7F02D70C E60A0000 */  swc1  $f10, ($s0)
/* 062240 7F02D710 C7B00060 */  lwc1  $f16, 0x60($sp)
/* 062244 7F02D714 E6100004 */  swc1  $f16, 4($s0)
/* 062248 7F02D718 C7B20064 */  lwc1  $f18, 0x64($sp)
/* 06224C 7F02D71C E6120008 */  swc1  $f18, 8($s0)
.L7F02D720:
/* 062250 7F02D720 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F02D724:
/* 062254 7F02D724 8FB00018 */  lw    $s0, 0x18($sp)
/* 062258 7F02D728 27BD00C8 */  addiu $sp, $sp, 0xc8
/* 06225C 7F02D72C 03E00008 */  jr    $ra
/* 062260 7F02D730 00C01025 */   move  $v0, $a2
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02D734(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051F60
.word 0x481c4000 /*160000.0*/
glabel D_80051F64
.word 0x3f8e38e3 /*1.111111*/
glabel D_80051F68
.word 0x481c4000 /*160000.0*/
glabel D_80051F6C
.word 0x42055555 /*33.333332*/
glabel D_80051F70
.word 0x3e99999a /*0.30000001*/
glabel D_80051F74
.word 0x3e088888 /*0.13333333*/
glabel D_80051F78
.word 0x461c4000 /*10000.0*/
glabel jpt_80051F7C
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_no_projectile
 .word weapon_guard_fires_bullet_no_projectile
 .word weapon_guard_fires_bullet_no_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
.text
glabel sub_GAME_7F02D734
/* 062264 7F02D734 27BDFD78 */  addiu $sp, $sp, -0x288
/* 062268 7F02D738 AFBF002C */  sw    $ra, 0x2c($sp)
/* 06226C 7F02D73C AFA5028C */  sw    $a1, 0x28c($sp)
/* 062270 7F02D740 8C8E0018 */  lw    $t6, 0x18($a0)
/* 062274 7F02D744 AFA40288 */  sw    $a0, 0x288($sp)
/* 062278 7F02D748 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 06227C 7F02D74C AFAE0284 */   sw    $t6, 0x284($sp)
/* 062280 7F02D750 504002C3 */  beql  $v0, $zero, .L7F02E260
/* 062284 7F02D754 8FBF002C */   lw    $ra, 0x2c($sp)
/* 062288 7F02D758 AFA0027C */  sw    $zero, 0x27c($sp)
/* 06228C 7F02D75C AFA00278 */  sw    $zero, 0x278($sp)
/* 062290 7F02D760 8C4F0004 */  lw    $t7, 4($v0)
/* 062294 7F02D764 0FC225E6 */  jal   get_curplayer_positiondata
/* 062298 7F02D768 AFAF0274 */   sw    $t7, 0x274($sp)
/* 06229C 7F02D76C 8FA50288 */  lw    $a1, 0x288($sp)
/* 0622A0 7F02D770 AFA20270 */  sw    $v0, 0x270($sp)
/* 0622A4 7F02D774 24010008 */  li    $at, 8
/* 0622A8 7F02D778 80B80007 */  lb    $t8, 7($a1)
/* 0622AC 7F02D77C 24030001 */  li    $v1, 1
/* 0622B0 7F02D780 3C0A8005 */  lui   $t2, %hi(g_GlobalTimer) 
/* 0622B4 7F02D784 57010003 */  bnel  $t8, $at, .L7F02D794
/* 0622B8 7F02D788 30790001 */   andi  $t9, $v1, 1
/* 0622BC 7F02D78C 8CA3004C */  lw    $v1, 0x4c($a1)
/* 0622C0 7F02D790 30790001 */  andi  $t9, $v1, 1
.L7F02D794:
/* 0622C4 7F02D794 1320000C */  beqz  $t9, .L7F02D7C8
/* 0622C8 7F02D798 AFB90044 */   sw    $t9, 0x44($sp)
/* 0622CC 7F02D79C 8D4A837C */  lw    $t2, %lo(g_GlobalTimer)($t2)
/* 0622D0 7F02D7A0 8CA900E8 */  lw    $t1, 0xe8($a1)
/* 0622D4 7F02D7A4 8FAC0274 */  lw    $t4, 0x274($sp)
/* 0622D8 7F02D7A8 254BFF88 */  addiu $t3, $t2, -0x78
/* 0622DC 7F02D7AC 012B082A */  slt   $at, $t1, $t3
/* 0622E0 7F02D7B0 50200006 */  beql  $at, $zero, .L7F02D7CC
/* 0622E4 7F02D7B4 8FAD028C */   lw    $t5, 0x28c($sp)
/* 0622E8 7F02D7B8 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 0622EC 7F02D7BC 81840080 */   lb    $a0, 0x80($t4)
/* 0622F0 7F02D7C0 044102A2 */  bgez  $v0, .L7F02E24C
/* 0622F4 7F02D7C4 8FA50288 */   lw    $a1, 0x288($sp)
.L7F02D7C8:
/* 0622F8 7F02D7C8 8FAD028C */  lw    $t5, 0x28c($sp)
.L7F02D7CC:
/* 0622FC 7F02D7CC AFA00268 */  sw    $zero, 0x268($sp)
/* 062300 7F02D7D0 AFA00264 */  sw    $zero, 0x264($sp)
/* 062304 7F02D7D4 00AD1021 */  addu  $v0, $a1, $t5
/* 062308 7F02D7D8 904E0004 */  lbu   $t6, 4($v0)
/* 06230C 7F02D7DC 25CF0001 */  addiu $t7, $t6, 1
/* 062310 7F02D7E0 A04F0004 */  sb    $t7, 4($v0)
/* 062314 7F02D7E4 8FB80274 */  lw    $t8, 0x274($sp)
/* 062318 7F02D7E8 83040080 */  lb    $a0, 0x80($t8)
/* 06231C 7F02D7EC 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 062320 7F02D7F0 AFA20040 */   sw    $v0, 0x40($sp)
/* 062324 7F02D7F4 04410006 */  bgez  $v0, .L7F02D810
/* 062328 7F02D7F8 8FAA0274 */   lw    $t2, 0x274($sp)
/* 06232C 7F02D7FC 24190001 */  li    $t9, 1
/* 062330 7F02D800 24080001 */  li    $t0, 1
/* 062334 7F02D804 AFB90268 */  sw    $t9, 0x268($sp)
/* 062338 7F02D808 10000031 */  b     .L7F02D8D0
/* 06233C 7F02D80C AFA80264 */   sw    $t0, 0x264($sp)
.L7F02D810:
/* 062340 7F02D810 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 062344 7F02D814 81440080 */   lb    $a0, 0x80($t2)
/* 062348 7F02D818 8FA90040 */  lw    $t1, 0x40($sp)
/* 06234C 7F02D81C 240D0001 */  li    $t5, 1
/* 062350 7F02D820 912B0004 */  lbu   $t3, 4($t1)
/* 062354 7F02D824 0162001A */  div   $zero, $t3, $v0
/* 062358 7F02D828 00006010 */  mfhi  $t4
/* 06235C 7F02D82C 14400002 */  bnez  $v0, .L7F02D838
/* 062360 7F02D830 00000000 */   nop   
/* 062364 7F02D834 0007000D */  break 7
.L7F02D838:
/* 062368 7F02D838 2401FFFF */  li    $at, -1
/* 06236C 7F02D83C 14410004 */  bne   $v0, $at, .L7F02D850
/* 062370 7F02D840 3C018000 */   lui   $at, 0x8000
/* 062374 7F02D844 15610002 */  bne   $t3, $at, .L7F02D850
/* 062378 7F02D848 00000000 */   nop   
/* 06237C 7F02D84C 0006000D */  break 6
.L7F02D850:
/* 062380 7F02D850 5580001E */  bnezl $t4, .L7F02D8CC
/* 062384 7F02D854 240C0001 */   li    $t4, 1
/* 062388 7F02D858 8FAE0274 */  lw    $t6, 0x274($sp)
/* 06238C 7F02D85C AFAD0268 */  sw    $t5, 0x268($sp)
/* 062390 7F02D860 0FC177F3 */  jal   bondwalkItemGetAutomaticFiringRate
/* 062394 7F02D864 81C40080 */   lb    $a0, 0x80($t6)
/* 062398 7F02D868 8FAF0040 */  lw    $t7, 0x40($sp)
/* 06239C 7F02D86C 0002C840 */  sll   $t9, $v0, 1
/* 0623A0 7F02D870 8FAA0274 */  lw    $t2, 0x274($sp)
/* 0623A4 7F02D874 91F80004 */  lbu   $t8, 4($t7)
/* 0623A8 7F02D878 240B0001 */  li    $t3, 1
/* 0623AC 7F02D87C 0319001A */  div   $zero, $t8, $t9
/* 0623B0 7F02D880 17200002 */  bnez  $t9, .L7F02D88C
/* 0623B4 7F02D884 00000000 */   nop   
/* 0623B8 7F02D888 0007000D */  break 7
.L7F02D88C:
/* 0623BC 7F02D88C 2401FFFF */  li    $at, -1
/* 0623C0 7F02D890 17210004 */  bne   $t9, $at, .L7F02D8A4
/* 0623C4 7F02D894 3C018000 */   lui   $at, 0x8000
/* 0623C8 7F02D898 17010002 */  bne   $t8, $at, .L7F02D8A4
/* 0623CC 7F02D89C 00000000 */   nop   
/* 0623D0 7F02D8A0 0006000D */  break 6
.L7F02D8A4:
/* 0623D4 7F02D8A4 00004010 */  mfhi  $t0
/* 0623D8 7F02D8A8 24010016 */  li    $at, 22
/* 0623DC 7F02D8AC 11000004 */  beqz  $t0, .L7F02D8C0
/* 0623E0 7F02D8B0 00000000 */   nop   
/* 0623E4 7F02D8B4 81490080 */  lb    $t1, 0x80($t2)
/* 0623E8 7F02D8B8 55210006 */  bnel  $t1, $at, .L7F02D8D4
/* 0623EC 7F02D8BC 8FAD0268 */   lw    $t5, 0x268($sp)
.L7F02D8C0:
/* 0623F0 7F02D8C0 10000003 */  b     .L7F02D8D0
/* 0623F4 7F02D8C4 AFAB0264 */   sw    $t3, 0x264($sp)
/* 0623F8 7F02D8C8 240C0001 */  li    $t4, 1
.L7F02D8CC:
/* 0623FC 7F02D8CC AFAC0278 */  sw    $t4, 0x278($sp)
.L7F02D8D0:
/* 062400 7F02D8D0 8FAD0268 */  lw    $t5, 0x268($sp)
.L7F02D8D4:
/* 062404 7F02D8D4 51A00254 */  beql  $t5, $zero, .L7F02E228
/* 062408 7F02D8D8 8FA2027C */   lw    $v0, 0x27c($sp)
/* 06240C 7F02D8DC AFA00254 */  sw    $zero, 0x254($sp)
/* 062410 7F02D8E0 0FC0B064 */  jal   sub_GAME_7F02C190
/* 062414 7F02D8E4 8FA40288 */   lw    $a0, 0x288($sp)
/* 062418 7F02D8E8 E7A00250 */  swc1  $f0, 0x250($sp)
/* 06241C 7F02D8EC 0FC0B09F */  jal   sub_GAME_7F02C27C
/* 062420 7F02D8F0 8FA40288 */   lw    $a0, 0x288($sp)
/* 062424 7F02D8F4 8FAE0284 */  lw    $t6, 0x284($sp)
/* 062428 7F02D8F8 E7A0024C */  swc1  $f0, 0x24c($sp)
/* 06242C 7F02D8FC 24180001 */  li    $t8, 1
/* 062430 7F02D900 8DCF0014 */  lw    $t7, 0x14($t6)
/* 062434 7F02D904 AFB8027C */  sw    $t8, 0x27c($sp)
/* 062438 7F02D908 8FA40288 */  lw    $a0, 0x288($sp)
/* 06243C 7F02D90C 8FA5028C */  lw    $a1, 0x28c($sp)
/* 062440 7F02D910 27A60240 */  addiu $a2, $sp, 0x240
/* 062444 7F02D914 0FC0B58C */  jal   sub_GAME_7F02D630
/* 062448 7F02D918 AFAF023C */   sw    $t7, 0x23c($sp)
/* 06244C 7F02D91C 54400032 */  bnezl $v0, .L7F02D9E8
/* 062450 7F02D920 8FA80284 */   lw    $t0, 0x284($sp)
/* 062454 7F02D924 8FA20284 */  lw    $v0, 0x284($sp)
/* 062458 7F02D928 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 06245C 7F02D92C 44814000 */  mtc1  $at, $f8
/* 062460 7F02D930 C4440008 */  lwc1  $f4, 8($v0)
/* 062464 7F02D934 8FB9028C */  lw    $t9, 0x28c($sp)
/* 062468 7F02D938 24010001 */  li    $at, 1
/* 06246C 7F02D93C E7A40240 */  swc1  $f4, 0x240($sp)
/* 062470 7F02D940 C446000C */  lwc1  $f6, 0xc($v0)
/* 062474 7F02D944 46083280 */  add.s $f10, $f6, $f8
/* 062478 7F02D948 E7AA0244 */  swc1  $f10, 0x244($sp)
/* 06247C 7F02D94C C4440010 */  lwc1  $f4, 0x10($v0)
/* 062480 7F02D950 17210013 */  bne   $t9, $at, .L7F02D9A0
/* 062484 7F02D954 E7A40248 */   swc1  $f4, 0x248($sp)
/* 062488 7F02D958 0FC15FA8 */  jal   cosf
/* 06248C 7F02D95C C7AC0250 */   lwc1  $f12, 0x250($sp)
/* 062490 7F02D960 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 062494 7F02D964 44814000 */  mtc1  $at, $f8
/* 062498 7F02D968 C7A60240 */  lwc1  $f6, 0x240($sp)
/* 06249C 7F02D96C C7AC0250 */  lwc1  $f12, 0x250($sp)
/* 0624A0 7F02D970 46080282 */  mul.s $f10, $f0, $f8
/* 0624A4 7F02D974 460A3100 */  add.s $f4, $f6, $f10
/* 0624A8 7F02D978 0FC15FAB */  jal   sinf
/* 0624AC 7F02D97C E7A40240 */   swc1  $f4, 0x240($sp)
/* 0624B0 7F02D980 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0624B4 7F02D984 44813000 */  mtc1  $at, $f6
/* 0624B8 7F02D988 46000207 */  neg.s $f8, $f0
/* 0624BC 7F02D98C C7A40248 */  lwc1  $f4, 0x248($sp)
/* 0624C0 7F02D990 46064282 */  mul.s $f10, $f8, $f6
/* 0624C4 7F02D994 460A2200 */  add.s $f8, $f4, $f10
/* 0624C8 7F02D998 10000012 */  b     .L7F02D9E4
/* 0624CC 7F02D99C E7A80248 */   swc1  $f8, 0x248($sp)
.L7F02D9A0:
/* 0624D0 7F02D9A0 0FC15FA8 */  jal   cosf
/* 0624D4 7F02D9A4 C7AC0250 */   lwc1  $f12, 0x250($sp)
/* 0624D8 7F02D9A8 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0624DC 7F02D9AC 44812000 */  mtc1  $at, $f4
/* 0624E0 7F02D9B0 46000187 */  neg.s $f6, $f0
/* 0624E4 7F02D9B4 C7A80240 */  lwc1  $f8, 0x240($sp)
/* 0624E8 7F02D9B8 46043282 */  mul.s $f10, $f6, $f4
/* 0624EC 7F02D9BC C7AC0250 */  lwc1  $f12, 0x250($sp)
/* 0624F0 7F02D9C0 460A4180 */  add.s $f6, $f8, $f10
/* 0624F4 7F02D9C4 0FC15FAB */  jal   sinf
/* 0624F8 7F02D9C8 E7A60240 */   swc1  $f6, 0x240($sp)
/* 0624FC 7F02D9CC 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 062500 7F02D9D0 44814000 */  mtc1  $at, $f8
/* 062504 7F02D9D4 C7A40248 */  lwc1  $f4, 0x248($sp)
/* 062508 7F02D9D8 46080282 */  mul.s $f10, $f0, $f8
/* 06250C 7F02D9DC 460A2180 */  add.s $f6, $f4, $f10
/* 062510 7F02D9E0 E7A60248 */  swc1  $f6, 0x248($sp)
.L7F02D9E4:
/* 062514 7F02D9E4 8FA80284 */  lw    $t0, 0x284($sp)
.L7F02D9E8:
/* 062518 7F02D9E8 C7A80248 */  lwc1  $f8, 0x248($sp)
/* 06251C 7F02D9EC 8FA90288 */  lw    $t1, 0x288($sp)
/* 062520 7F02D9F0 8D050008 */  lw    $a1, 8($t0)
/* 062524 7F02D9F4 8D060010 */  lw    $a2, 0x10($t0)
/* 062528 7F02D9F8 240A0002 */  li    $t2, 2
/* 06252C 7F02D9FC AFAA0014 */  sw    $t2, 0x14($sp)
/* 062530 7F02DA00 E7A80010 */  swc1  $f8, 0x10($sp)
/* 062534 7F02DA04 C7A40244 */  lwc1  $f4, 0x244($sp)
/* 062538 7F02DA08 C52A00AC */  lwc1  $f10, 0xac($t1)
/* 06253C 7F02DA0C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 062540 7F02DA10 44814000 */  mtc1  $at, $f8
/* 062544 7F02DA14 460A2001 */  sub.s $f0, $f4, $f10
/* 062548 7F02DA18 44803000 */  mtc1  $zero, $f6
/* 06254C 7F02DA1C 27A4023C */  addiu $a0, $sp, 0x23c
/* 062550 7F02DA20 8FA70240 */  lw    $a3, 0x240($sp)
/* 062554 7F02DA24 E7A00018 */  swc1  $f0, 0x18($sp)
/* 062558 7F02DA28 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 06255C 7F02DA2C E7A80024 */  swc1  $f8, 0x24($sp)
/* 062560 7F02DA30 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 062564 7F02DA34 E7A60020 */   swc1  $f6, 0x20($sp)
/* 062568 7F02DA38 10400003 */  beqz  $v0, .L7F02DA48
/* 06256C 7F02DA3C 8FAB023C */   lw    $t3, 0x23c($sp)
/* 062570 7F02DA40 10000006 */  b     .L7F02DA5C
/* 062574 7F02DA44 AFAB0238 */   sw    $t3, 0x238($sp)
.L7F02DA48:
/* 062578 7F02DA48 8FA20040 */  lw    $v0, 0x40($sp)
/* 06257C 7F02DA4C 904C0004 */  lbu   $t4, 4($v0)
/* 062580 7F02DA50 258DFFFF */  addiu $t5, $t4, -1
/* 062584 7F02DA54 A04D0004 */  sb    $t5, 4($v0)
/* 062588 7F02DA58 AFA0027C */  sw    $zero, 0x27c($sp)
.L7F02DA5C:
/* 06258C 7F02DA5C 8FAE027C */  lw    $t6, 0x27c($sp)
/* 062590 7F02DA60 240F0001 */  li    $t7, 1
/* 062594 7F02DA64 27A50240 */  addiu $a1, $sp, 0x240
/* 062598 7F02DA68 51C001EF */  beql  $t6, $zero, .L7F02E228
/* 06259C 7F02DA6C 8FA2027C */   lw    $v0, 0x27c($sp)
/* 0625A0 7F02DA70 AFA00234 */  sw    $zero, 0x234($sp)
/* 0625A4 7F02DA74 AFA00230 */  sw    $zero, 0x230($sp)
/* 0625A8 7F02DA78 AFAF022C */  sw    $t7, 0x22c($sp)
/* 0625AC 7F02DA7C 8FA40288 */  lw    $a0, 0x288($sp)
/* 0625B0 7F02DA80 0FC0A4AA */  jal   chrlvAttackRelated7F0292A8
/* 0625B4 7F02DA84 8FA60238 */   lw    $a2, 0x238($sp)
/* 0625B8 7F02DA88 AFA2021C */  sw    $v0, 0x21c($sp)
/* 0625BC 7F02DA8C 0FC15FA8 */  jal   cosf
/* 0625C0 7F02DA90 C7AC024C */   lwc1  $f12, 0x24c($sp)
/* 0625C4 7F02DA94 E7A0004C */  swc1  $f0, 0x4c($sp)
/* 0625C8 7F02DA98 0FC15FAB */  jal   sinf
/* 0625CC 7F02DA9C C7AC0250 */   lwc1  $f12, 0x250($sp)
/* 0625D0 7F02DAA0 C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 0625D4 7F02DAA4 C7AC024C */  lwc1  $f12, 0x24c($sp)
/* 0625D8 7F02DAA8 46040282 */  mul.s $f10, $f0, $f4
/* 0625DC 7F02DAAC 0FC15FAB */  jal   sinf
/* 0625E0 7F02DAB0 E7AA0220 */   swc1  $f10, 0x220($sp)
/* 0625E4 7F02DAB4 E7A00224 */  swc1  $f0, 0x224($sp)
/* 0625E8 7F02DAB8 0FC15FA8 */  jal   cosf
/* 0625EC 7F02DABC C7AC024C */   lwc1  $f12, 0x24c($sp)
/* 0625F0 7F02DAC0 E7A0004C */  swc1  $f0, 0x4c($sp)
/* 0625F4 7F02DAC4 0FC15FA8 */  jal   cosf
/* 0625F8 7F02DAC8 C7AC0250 */   lwc1  $f12, 0x250($sp)
/* 0625FC 7F02DACC C7A6004C */  lwc1  $f6, 0x4c($sp)
/* 062600 7F02DAD0 3C014780 */  li    $at, 0x47800000 # 65536.000000
/* 062604 7F02DAD4 44811000 */  mtc1  $at, $f2
/* 062608 7F02DAD8 46060482 */  mul.s $f18, $f0, $f6
/* 06260C 7F02DADC C7A80220 */  lwc1  $f8, 0x220($sp)
/* 062610 7F02DAE0 C7AA0240 */  lwc1  $f10, 0x240($sp)
/* 062614 7F02DAE4 C7AC0244 */  lwc1  $f12, 0x244($sp)
/* 062618 7F02DAE8 46024102 */  mul.s $f4, $f8, $f2
/* 06261C 7F02DAEC C7A80224 */  lwc1  $f8, 0x224($sp)
/* 062620 7F02DAF0 8FA40288 */  lw    $a0, 0x288($sp)
/* 062624 7F02DAF4 E7B20228 */  swc1  $f18, 0x228($sp)
/* 062628 7F02DAF8 00002825 */  move  $a1, $zero
/* 06262C 7F02DAFC 460A2180 */  add.s $f6, $f4, $f10
/* 062630 7F02DB00 46024102 */  mul.s $f4, $f8, $f2
/* 062634 7F02DB04 00000000 */  nop   
/* 062638 7F02DB08 46029282 */  mul.s $f10, $f18, $f2
/* 06263C 7F02DB0C E7A60258 */  swc1  $f6, 0x258($sp)
/* 062640 7F02DB10 C7A60248 */  lwc1  $f6, 0x248($sp)
/* 062644 7F02DB14 460C2380 */  add.s $f14, $f4, $f12
/* 062648 7F02DB18 46065200 */  add.s $f8, $f10, $f6
/* 06264C 7F02DB1C E7AE025C */  swc1  $f14, 0x25c($sp)
/* 062650 7F02DB20 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 062654 7F02DB24 E7A80260 */   swc1  $f8, 0x260($sp)
/* 062658 7F02DB28 0FC2C731 */  jal   sub_GAME_7F0B1CC4
/* 06265C 7F02DB2C 00000000 */   nop   
/* 062660 7F02DB30 C7AC0244 */  lwc1  $f12, 0x244($sp)
/* 062664 7F02DB34 C7AE025C */  lwc1  $f14, 0x25c($sp)
/* 062668 7F02DB38 8FB80238 */  lw    $t8, 0x238($sp)
/* 06266C 7F02DB3C C7A40260 */  lwc1  $f4, 0x260($sp)
/* 062670 7F02DB40 2419001B */  li    $t9, 27
/* 062674 7F02DB44 AFB90014 */  sw    $t9, 0x14($sp)
/* 062678 7F02DB48 27A4023C */  addiu $a0, $sp, 0x23c
/* 06267C 7F02DB4C 8FA50240 */  lw    $a1, 0x240($sp)
/* 062680 7F02DB50 8FA60248 */  lw    $a2, 0x248($sp)
/* 062684 7F02DB54 8FA70258 */  lw    $a3, 0x258($sp)
/* 062688 7F02DB58 E7AC0018 */  swc1  $f12, 0x18($sp)
/* 06268C 7F02DB5C E7AC001C */  swc1  $f12, 0x1c($sp)
/* 062690 7F02DB60 E7AE0020 */  swc1  $f14, 0x20($sp)
/* 062694 7F02DB64 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 062698 7F02DB68 AFB8023C */  sw    $t8, 0x23c($sp)
/* 06269C 7F02DB6C 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 0626A0 7F02DB70 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0626A4 7F02DB74 14400017 */  bnez  $v0, .L7F02DBD4
/* 0626A8 7F02DB78 27A40240 */   addiu $a0, $sp, 0x240
/* 0626AC 7F02DB7C 27A50220 */  addiu $a1, $sp, 0x220
/* 0626B0 7F02DB80 0FC09893 */  jal   chrlvStanLineDirIntersection
/* 0626B4 7F02DB84 27A60258 */   addiu $a2, $sp, 0x258
/* 0626B8 7F02DB88 3C0141D0 */  li    $at, 0x41D00000 # 26.000000
/* 0626BC 7F02DB8C 44810000 */  mtc1  $at, $f0
/* 0626C0 7F02DB90 C7A60220 */  lwc1  $f6, 0x220($sp)
/* 0626C4 7F02DB94 C7AA0258 */  lwc1  $f10, 0x258($sp)
/* 0626C8 7F02DB98 C7B20228 */  lwc1  $f18, 0x228($sp)
/* 0626CC 7F02DB9C 46060202 */  mul.s $f8, $f0, $f6
/* 0626D0 7F02DBA0 C7A60224 */  lwc1  $f6, 0x224($sp)
/* 0626D4 7F02DBA4 C7AE025C */  lwc1  $f14, 0x25c($sp)
/* 0626D8 7F02DBA8 8FA8023C */  lw    $t0, 0x23c($sp)
/* 0626DC 7F02DBAC AFA80254 */  sw    $t0, 0x254($sp)
/* 0626E0 7F02DBB0 46085101 */  sub.s $f4, $f10, $f8
/* 0626E4 7F02DBB4 46060282 */  mul.s $f10, $f0, $f6
/* 0626E8 7F02DBB8 C7A80260 */  lwc1  $f8, 0x260($sp)
/* 0626EC 7F02DBBC E7A40258 */  swc1  $f4, 0x258($sp)
/* 0626F0 7F02DBC0 46120102 */  mul.s $f4, $f0, $f18
/* 0626F4 7F02DBC4 460A7381 */  sub.s $f14, $f14, $f10
/* 0626F8 7F02DBC8 46044181 */  sub.s $f6, $f8, $f4
/* 0626FC 7F02DBCC E7AE025C */  swc1  $f14, 0x25c($sp)
/* 062700 7F02DBD0 E7A60260 */  swc1  $f6, 0x260($sp)
.L7F02DBD4:
/* 062704 7F02DBD4 8FA40288 */  lw    $a0, 0x288($sp)
/* 062708 7F02DBD8 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 06270C 7F02DBDC 24050001 */   li    $a1, 1
/* 062710 7F02DBE0 C7AA0258 */  lwc1  $f10, 0x258($sp)
/* 062714 7F02DBE4 C7A80240 */  lwc1  $f8, 0x240($sp)
/* 062718 7F02DBE8 C7A4025C */  lwc1  $f4, 0x25c($sp)
/* 06271C 7F02DBEC C7A60244 */  lwc1  $f6, 0x244($sp)
/* 062720 7F02DBF0 46085081 */  sub.s $f2, $f10, $f8
/* 062724 7F02DBF4 C7A80248 */  lwc1  $f8, 0x248($sp)
/* 062728 7F02DBF8 C7AA0260 */  lwc1  $f10, 0x260($sp)
/* 06272C 7F02DBFC 46062381 */  sub.s $f14, $f4, $f6
/* 062730 7F02DC00 46021102 */  mul.s $f4, $f2, $f2
/* 062734 7F02DC04 8FAA0274 */  lw    $t2, 0x274($sp)
/* 062738 7F02DC08 46085481 */  sub.s $f18, $f10, $f8
/* 06273C 7F02DC0C 460E7182 */  mul.s $f6, $f14, $f14
/* 062740 7F02DC10 24010019 */  li    $at, 25
/* 062744 7F02DC14 46129202 */  mul.s $f8, $f18, $f18
/* 062748 7F02DC18 46062280 */  add.s $f10, $f4, $f6
/* 06274C 7F02DC1C 46085100 */  add.s $f4, $f10, $f8
/* 062750 7F02DC20 E7A4020C */  swc1  $f4, 0x20c($sp)
/* 062754 7F02DC24 81470080 */  lb    $a3, 0x80($t2)
/* 062758 7F02DC28 54E1006F */  bnel  $a3, $at, .L7F02DDE8
/* 06275C 7F02DC2C 24010018 */   li    $at, 24
/* 062760 7F02DC30 46021282 */  mul.s $f10, $f2, $f2
/* 062764 7F02DC34 3C018005 */  lui   $at, %hi(D_80051F60)
/* 062768 7F02DC38 C4261F60 */  lwc1  $f6, %lo(D_80051F60)($at)
/* 06276C 7F02DC3C 460E7202 */  mul.s $f8, $f14, $f14
/* 062770 7F02DC40 240400CA */  li    $a0, 202
/* 062774 7F02DC44 46085100 */  add.s $f4, $f10, $f8
/* 062778 7F02DC48 46129282 */  mul.s $f10, $f18, $f18
/* 06277C 7F02DC4C 460A2200 */  add.s $f8, $f4, $f10
/* 062780 7F02DC50 4608303C */  c.lt.s $f6, $f8
/* 062784 7F02DC54 00000000 */  nop   
/* 062788 7F02DC58 45000060 */  bc1f  .L7F02DDDC
/* 06278C 7F02DC5C 00000000 */   nop   
/* 062790 7F02DC60 0FC1481B */  jal   create_new_item_instance_of_model
/* 062794 7F02DC64 24050056 */   li    $a1, 86
/* 062798 7F02DC68 1040016E */  beqz  $v0, .L7F02E224
/* 06279C 7F02DC6C AFA20208 */   sw    $v0, 0x208($sp)
/* 0627A0 7F02DC70 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 0627A4 7F02DC74 27A401C8 */   addiu $a0, $sp, 0x1c8
/* 0627A8 7F02DC78 C7AC024C */  lwc1  $f12, 0x24c($sp)
/* 0627AC 7F02DC7C 0FC1615C */  jal   matrix_4x4_set_rotation_around_x
/* 0627B0 7F02DC80 27A5016C */   addiu $a1, $sp, 0x16c
/* 0627B4 7F02DC84 C7AC0250 */  lwc1  $f12, 0x250($sp)
/* 0627B8 7F02DC88 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 0627BC 7F02DC8C 27A5012C */   addiu $a1, $sp, 0x12c
/* 0627C0 7F02DC90 27A4012C */  addiu $a0, $sp, 0x12c
/* 0627C4 7F02DC94 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0627C8 7F02DC98 27A5016C */   addiu $a1, $sp, 0x16c
/* 0627CC 7F02DC9C 3C018005 */  lui   $at, %hi(D_80051F64)
/* 0627D0 7F02DCA0 C4221F64 */  lwc1  $f2, %lo(D_80051F64)($at)
/* 0627D4 7F02DCA4 C7A40220 */  lwc1  $f4, 0x220($sp)
/* 0627D8 7F02DCA8 C7AA0224 */  lwc1  $f10, 0x224($sp)
/* 0627DC 7F02DCAC C7B20228 */  lwc1  $f18, 0x228($sp)
/* 0627E0 7F02DCB0 46022302 */  mul.s $f12, $f4, $f2
/* 0627E4 7F02DCB4 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 0627E8 7F02DCB8 C4208378 */  lwc1  $f0, %lo(g_GlobalTimerDelta)($at)
/* 0627EC 7F02DCBC 46025382 */  mul.s $f14, $f10, $f2
/* 0627F0 7F02DCC0 8FAC0284 */  lw    $t4, 0x284($sp)
/* 0627F4 7F02DCC4 27A901BC */  addiu $t1, $sp, 0x1bc
/* 0627F8 7F02DCC8 46029402 */  mul.s $f16, $f18, $f2
/* 0627FC 7F02DCCC 27AB01C8 */  addiu $t3, $sp, 0x1c8
/* 062800 7F02DCD0 AFAB0014 */  sw    $t3, 0x14($sp)
/* 062804 7F02DCD4 46006182 */  mul.s $f6, $f12, $f0
/* 062808 7F02DCD8 AFA90010 */  sw    $t1, 0x10($sp)
/* 06280C 7F02DCDC E7AE01B0 */  swc1  $f14, 0x1b0($sp)
/* 062810 7F02DCE0 46007202 */  mul.s $f8, $f14, $f0
/* 062814 7F02DCE4 E7B001B4 */  swc1  $f16, 0x1b4($sp)
/* 062818 7F02DCE8 E7AC01AC */  swc1  $f12, 0x1ac($sp)
/* 06281C 7F02DCEC 46008102 */  mul.s $f4, $f16, $f0
/* 062820 7F02DCF0 E7A601BC */  swc1  $f6, 0x1bc($sp)
/* 062824 7F02DCF4 8FA40208 */  lw    $a0, 0x208($sp)
/* 062828 7F02DCF8 27A50240 */  addiu $a1, $sp, 0x240
/* 06282C 7F02DCFC E7A801C0 */  swc1  $f8, 0x1c0($sp)
/* 062830 7F02DD00 8FA60238 */  lw    $a2, 0x238($sp)
/* 062834 7F02DD04 27A7016C */  addiu $a3, $sp, 0x16c
/* 062838 7F02DD08 E7A401C4 */  swc1  $f4, 0x1c4($sp)
/* 06283C 7F02DD0C 0FC17AC3 */  jal   sub_GAME_7F05EB0C
/* 062840 7F02DD10 AFAC0018 */   sw    $t4, 0x18($sp)
/* 062844 7F02DD14 8FA30208 */  lw    $v1, 0x208($sp)
/* 062848 7F02DD18 8C6D0064 */  lw    $t5, 0x64($v1)
/* 06284C 7F02DD1C 31AE0080 */  andi  $t6, $t5, 0x80
/* 062850 7F02DD20 51C00141 */  beql  $t6, $zero, .L7F02E228
/* 062854 7F02DD24 8FA2027C */   lw    $v0, 0x27c($sp)
/* 062858 7F02DD28 8C62006C */  lw    $v0, 0x6c($v1)
/* 06285C 7F02DD2C 2419FFFF */  li    $t9, -1
/* 062860 7F02DD30 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 062864 7F02DD34 8C4F0000 */  lw    $t7, ($v0)
/* 062868 7F02DD38 24050001 */  li    $a1, 1
/* 06286C 7F02DD3C 35F80080 */  ori   $t8, $t7, 0x80
/* 062870 7F02DD40 AC580000 */  sw    $t8, ($v0)
/* 062874 7F02DD44 8C62006C */  lw    $v0, 0x6c($v1)
/* 062878 7F02DD48 A4790082 */  sh    $t9, 0x82($v1)
/* 06287C 7F02DD4C 8C480000 */  lw    $t0, ($v0)
/* 062880 7F02DD50 350A0020 */  ori   $t2, $t0, 0x20
/* 062884 7F02DD54 AC4A0000 */  sw    $t2, ($v0)
/* 062888 7F02DD58 8C69006C */  lw    $t1, 0x6c($v1)
/* 06288C 7F02DD5C C46A005C */  lwc1  $f10, 0x5c($v1)
/* 062890 7F02DD60 E52A00B0 */  swc1  $f10, 0xb0($t1)
/* 062894 7F02DD64 8C62006C */  lw    $v0, 0x6c($v1)
/* 062898 7F02DD68 C4460008 */  lwc1  $f6, 8($v0)
/* 06289C 7F02DD6C E44600B4 */  swc1  $f6, 0xb4($v0)
/* 0628A0 7F02DD70 8C6B006C */  lw    $t3, 0x6c($v1)
/* 0628A4 7F02DD74 C7A801AC */  lwc1  $f8, 0x1ac($sp)
/* 0628A8 7F02DD78 E5680010 */  swc1  $f8, 0x10($t3)
/* 0628AC 7F02DD7C 8C6C006C */  lw    $t4, 0x6c($v1)
/* 0628B0 7F02DD80 C7A401B0 */  lwc1  $f4, 0x1b0($sp)
/* 0628B4 7F02DD84 E5840014 */  swc1  $f4, 0x14($t4)
/* 0628B8 7F02DD88 8C6D006C */  lw    $t5, 0x6c($v1)
/* 0628BC 7F02DD8C C7AA01B4 */  lwc1  $f10, 0x1b4($sp)
/* 0628C0 7F02DD90 E5AA0018 */  swc1  $f10, 0x18($t5)
/* 0628C4 7F02DD94 8C62006C */  lw    $v0, 0x6c($v1)
/* 0628C8 7F02DD98 8C4E0098 */  lw    $t6, 0x98($v0)
/* 0628CC 7F02DD9C 24460098 */  addiu $a2, $v0, 0x98
/* 0628D0 7F02DDA0 55C00006 */  bnezl $t6, .L7F02DDBC
/* 0628D4 7F02DDA4 8C4F009C */   lw    $t7, 0x9c($v0)
/* 0628D8 7F02DDA8 0C002382 */  jal   sndPlaySfx
/* 0628DC 7F02DDAC 8C843720 */   lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0628E0 7F02DDB0 1000011D */  b     .L7F02E228
/* 0628E4 7F02DDB4 8FA2027C */   lw    $v0, 0x27c($sp)
/* 0628E8 7F02DDB8 8C4F009C */  lw    $t7, 0x9c($v0)
.L7F02DDBC:
/* 0628EC 7F02DDBC 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0628F0 7F02DDC0 24050001 */  li    $a1, 1
/* 0628F4 7F02DDC4 15E00117 */  bnez  $t7, .L7F02E224
/* 0628F8 7F02DDC8 2446009C */   addiu $a2, $v0, 0x9c
/* 0628FC 7F02DDCC 0C002382 */  jal   sndPlaySfx
/* 062900 7F02DDD0 8C843720 */   lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 062904 7F02DDD4 10000114 */  b     .L7F02E228
/* 062908 7F02DDD8 8FA2027C */   lw    $v0, 0x27c($sp)
.L7F02DDDC:
/* 06290C 7F02DDDC 10000111 */  b     .L7F02E224
/* 062910 7F02DDE0 AFA0027C */   sw    $zero, 0x27c($sp)
/* 062914 7F02DDE4 24010018 */  li    $at, 24
.L7F02DDE8:
/* 062918 7F02DDE8 14E10048 */  bne   $a3, $at, .L7F02DF0C
/* 06291C 7F02DDEC 8FB80044 */   lw    $t8, 0x44($sp)
/* 062920 7F02DDF0 46021202 */  mul.s $f8, $f2, $f2
/* 062924 7F02DDF4 3C018005 */  lui   $at, %hi(D_80051F68)
/* 062928 7F02DDF8 C4261F68 */  lwc1  $f6, %lo(D_80051F68)($at)
/* 06292C 7F02DDFC 460E7102 */  mul.s $f4, $f14, $f14
/* 062930 7F02DE00 240400CB */  li    $a0, 203
/* 062934 7F02DE04 46044280 */  add.s $f10, $f8, $f4
/* 062938 7F02DE08 46129202 */  mul.s $f8, $f18, $f18
/* 06293C 7F02DE0C 46085100 */  add.s $f4, $f10, $f8
/* 062940 7F02DE10 4604303C */  c.lt.s $f6, $f4
/* 062944 7F02DE14 00000000 */  nop   
/* 062948 7F02DE18 4500003A */  bc1f  .L7F02DF04
/* 06294C 7F02DE1C 00000000 */   nop   
/* 062950 7F02DE20 0FC1481B */  jal   create_new_item_instance_of_model
/* 062954 7F02DE24 24050057 */   li    $a1, 87
/* 062958 7F02DE28 104000FE */  beqz  $v0, .L7F02E224
/* 06295C 7F02DE2C AFA20128 */   sw    $v0, 0x128($sp)
/* 062960 7F02DE30 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 062964 7F02DE34 27A400E8 */   addiu $a0, $sp, 0xe8
/* 062968 7F02DE38 3C018005 */  lui   $at, %hi(D_80051F6C)
/* 06296C 7F02DE3C C4201F6C */  lwc1  $f0, %lo(D_80051F6C)($at)
/* 062970 7F02DE40 C7AA0220 */  lwc1  $f10, 0x220($sp)
/* 062974 7F02DE44 C7A60224 */  lwc1  $f6, 0x224($sp)
/* 062978 7F02DE48 C7B20228 */  lwc1  $f18, 0x228($sp)
/* 06297C 7F02DE4C 46005202 */  mul.s $f8, $f10, $f0
/* 062980 7F02DE50 C7AC024C */  lwc1  $f12, 0x24c($sp)
/* 062984 7F02DE54 27A5009C */  addiu $a1, $sp, 0x9c
/* 062988 7F02DE58 46003102 */  mul.s $f4, $f6, $f0
/* 06298C 7F02DE5C 00000000 */  nop   
/* 062990 7F02DE60 46009282 */  mul.s $f10, $f18, $f0
/* 062994 7F02DE64 E7A800DC */  swc1  $f8, 0xdc($sp)
/* 062998 7F02DE68 E7A400E0 */  swc1  $f4, 0xe0($sp)
/* 06299C 7F02DE6C 0FC1615C */  jal   matrix_4x4_set_rotation_around_x
/* 0629A0 7F02DE70 E7AA00E4 */   swc1  $f10, 0xe4($sp)
/* 0629A4 7F02DE74 C7AC0250 */  lwc1  $f12, 0x250($sp)
/* 0629A8 7F02DE78 0FC1617F */  jal   matrix_4x4_set_rotation_around_y
/* 0629AC 7F02DE7C 27A5005C */   addiu $a1, $sp, 0x5c
/* 0629B0 7F02DE80 27A4005C */  addiu $a0, $sp, 0x5c
/* 0629B4 7F02DE84 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0629B8 7F02DE88 27A5009C */   addiu $a1, $sp, 0x9c
/* 0629BC 7F02DE8C 8FA40128 */  lw    $a0, 0x128($sp)
/* 0629C0 7F02DE90 241800B4 */  li    $t8, 180
/* 0629C4 7F02DE94 27B900DC */  addiu $t9, $sp, 0xdc
/* 0629C8 7F02DE98 A4980082 */  sh    $t8, 0x82($a0)
/* 0629CC 7F02DE9C 8FAA0284 */  lw    $t2, 0x284($sp)
/* 0629D0 7F02DEA0 27A800E8 */  addiu $t0, $sp, 0xe8
/* 0629D4 7F02DEA4 AFA80014 */  sw    $t0, 0x14($sp)
/* 0629D8 7F02DEA8 AFB90010 */  sw    $t9, 0x10($sp)
/* 0629DC 7F02DEAC 8FA60238 */  lw    $a2, 0x238($sp)
/* 0629E0 7F02DEB0 27A50240 */  addiu $a1, $sp, 0x240
/* 0629E4 7F02DEB4 27A7009C */  addiu $a3, $sp, 0x9c
/* 0629E8 7F02DEB8 0FC17AC3 */  jal   sub_GAME_7F05EB0C
/* 0629EC 7F02DEBC AFAA0018 */   sw    $t2, 0x18($sp)
/* 0629F0 7F02DEC0 8FA20128 */  lw    $v0, 0x128($sp)
/* 0629F4 7F02DEC4 3C018005 */  lui   $at, %hi(D_80051F70)
/* 0629F8 7F02DEC8 8C490064 */  lw    $t1, 0x64($v0)
/* 0629FC 7F02DECC 312B0080 */  andi  $t3, $t1, 0x80
/* 062A00 7F02DED0 516000D5 */  beql  $t3, $zero, .L7F02E228
/* 062A04 7F02DED4 8FA2027C */   lw    $v0, 0x27c($sp)
/* 062A08 7F02DED8 C4281F70 */  lwc1  $f8, %lo(D_80051F70)($at)
/* 062A0C 7F02DEDC 8C4C006C */  lw    $t4, 0x6c($v0)
/* 062A10 7F02DEE0 3C018005 */  lui   $at, %hi(D_80051F74)
/* 062A14 7F02DEE4 240E003C */  li    $t6, 60
/* 062A18 7F02DEE8 E588008C */  swc1  $f8, 0x8c($t4)
/* 062A1C 7F02DEEC 8C4D006C */  lw    $t5, 0x6c($v0)
/* 062A20 7F02DEF0 C4261F74 */  lwc1  $f6, %lo(D_80051F74)($at)
/* 062A24 7F02DEF4 E5A60094 */  swc1  $f6, 0x94($t5)
/* 062A28 7F02DEF8 8C4F006C */  lw    $t7, 0x6c($v0)
/* 062A2C 7F02DEFC 100000C9 */  b     .L7F02E224
/* 062A30 7F02DF00 ADEE00BC */   sw    $t6, 0xbc($t7)
.L7F02DF04:
/* 062A34 7F02DF04 100000C7 */  b     .L7F02E224
/* 062A38 7F02DF08 AFA0027C */   sw    $zero, 0x27c($sp)
.L7F02DF0C:
/* 062A3C 7F02DF0C 13000036 */  beqz  $t8, .L7F02DFE8
/* 062A40 7F02DF10 8FB9021C */   lw    $t9, 0x21c($sp)
/* 062A44 7F02DF14 13200034 */  beqz  $t9, .L7F02DFE8
/* 062A48 7F02DF18 3C014170 */   li    $at, 0x41700000 # 15.000000
/* 062A4C 7F02DF1C 8FA80270 */  lw    $t0, 0x270($sp)
/* 062A50 7F02DF20 C7AA0240 */  lwc1  $f10, 0x240($sp)
/* 062A54 7F02DF24 44811000 */  mtc1  $at, $f2
/* 062A58 7F02DF28 C5040008 */  lwc1  $f4, 8($t0)
/* 062A5C 7F02DF2C C7A60220 */  lwc1  $f6, 0x220($sp)
/* 062A60 7F02DF30 8FA40288 */  lw    $a0, 0x288($sp)
/* 062A64 7F02DF34 460A2201 */  sub.s $f8, $f4, $f10
/* 062A68 7F02DF38 46023102 */  mul.s $f4, $f6, $f2
/* 062A6C 7F02DF3C C7A60244 */  lwc1  $f6, 0x244($sp)
/* 062A70 7F02DF40 C50A000C */  lwc1  $f10, 0xc($t0)
/* 062A74 7F02DF44 27A50234 */  addiu $a1, $sp, 0x234
/* 062A78 7F02DF48 46044001 */  sub.s $f0, $f8, $f4
/* 062A7C 7F02DF4C C7A40224 */  lwc1  $f4, 0x224($sp)
/* 062A80 7F02DF50 46065201 */  sub.s $f8, $f10, $f6
/* 062A84 7F02DF54 46022282 */  mul.s $f10, $f4, $f2
/* 062A88 7F02DF58 C7A40248 */  lwc1  $f4, 0x248($sp)
/* 062A8C 7F02DF5C C5060010 */  lwc1  $f6, 0x10($t0)
/* 062A90 7F02DF60 460A4301 */  sub.s $f12, $f8, $f10
/* 062A94 7F02DF64 C7AA0228 */  lwc1  $f10, 0x228($sp)
/* 062A98 7F02DF68 46043201 */  sub.s $f8, $f6, $f4
/* 062A9C 7F02DF6C 46025182 */  mul.s $f6, $f10, $f2
/* 062AA0 7F02DF70 C7A4020C */  lwc1  $f4, 0x20c($sp)
/* 062AA4 7F02DF74 46000282 */  mul.s $f10, $f0, $f0
/* 062AA8 7F02DF78 46064401 */  sub.s $f16, $f8, $f6
/* 062AAC 7F02DF7C 460C6202 */  mul.s $f8, $f12, $f12
/* 062AB0 7F02DF80 46085180 */  add.s $f6, $f10, $f8
/* 062AB4 7F02DF84 46108282 */  mul.s $f10, $f16, $f16
/* 062AB8 7F02DF88 460A3200 */  add.s $f8, $f6, $f10
/* 062ABC 7F02DF8C 4604403E */  c.le.s $f8, $f4
/* 062AC0 7F02DF90 00000000 */  nop   
/* 062AC4 7F02DF94 45020020 */  bc1fl .L7F02E018
/* 062AC8 7F02DF98 8FA80230 */   lw    $t0, 0x230($sp)
/* 062ACC 7F02DF9C 0FC0B4B9 */  jal   sub_GAME_7F02D2E4
/* 062AD0 7F02DFA0 27A60230 */   addiu $a2, $sp, 0x230
/* 062AD4 7F02DFA4 8FAA0230 */  lw    $t2, 0x230($sp)
/* 062AD8 7F02DFA8 8FAB0234 */  lw    $t3, 0x234($sp)
/* 062ADC 7F02DFAC 8FAC0288 */  lw    $t4, 0x288($sp)
/* 062AE0 7F02DFB0 2D490001 */  sltiu $t1, $t2, 1
/* 062AE4 7F02DFB4 11600017 */  beqz  $t3, .L7F02E014
/* 062AE8 7F02DFB8 AFA9022C */   sw    $t1, 0x22c($sp)
/* 062AEC 7F02DFBC 81820007 */  lb    $v0, 7($t4)
/* 062AF0 7F02DFC0 24010008 */  li    $at, 8
/* 062AF4 7F02DFC4 3C0D8005 */  lui   $t5, %hi(g_GlobalTimer) 
/* 062AF8 7F02DFC8 10410004 */  beq   $v0, $at, .L7F02DFDC
/* 062AFC 7F02DFCC 8FAE0288 */   lw    $t6, 0x288($sp)
/* 062B00 7F02DFD0 2401000A */  li    $at, 10
/* 062B04 7F02DFD4 54410010 */  bnel  $v0, $at, .L7F02E018
/* 062B08 7F02DFD8 8FA80230 */   lw    $t0, 0x230($sp)
.L7F02DFDC:
/* 062B0C 7F02DFDC 8DAD837C */  lw    $t5, %lo(g_GlobalTimer)($t5)
/* 062B10 7F02DFE0 1000000C */  b     .L7F02E014
/* 062B14 7F02DFE4 ADCD0048 */   sw    $t5, 0x48($t6)
.L7F02DFE8:
/* 062B18 7F02DFE8 8FAF0288 */  lw    $t7, 0x288($sp)
/* 062B1C 7F02DFEC 24010008 */  li    $at, 8
/* 062B20 7F02DFF0 3C188005 */  lui   $t8, %hi(g_GlobalTimer) 
/* 062B24 7F02DFF4 81E20007 */  lb    $v0, 7($t7)
/* 062B28 7F02DFF8 8FB90288 */  lw    $t9, 0x288($sp)
/* 062B2C 7F02DFFC 10410003 */  beq   $v0, $at, .L7F02E00C
/* 062B30 7F02E000 2401000A */   li    $at, 10
/* 062B34 7F02E004 54410004 */  bnel  $v0, $at, .L7F02E018
/* 062B38 7F02E008 8FA80230 */   lw    $t0, 0x230($sp)
.L7F02E00C:
/* 062B3C 7F02E00C 8F18837C */  lw    $t8, %lo(g_GlobalTimer)($t8)
/* 062B40 7F02E010 AF380048 */  sw    $t8, 0x48($t9)
.L7F02E014:
/* 062B44 7F02E014 8FA80230 */  lw    $t0, 0x230($sp)
.L7F02E018:
/* 062B48 7F02E018 8FA50270 */  lw    $a1, 0x270($sp)
/* 062B4C 7F02E01C 3C038008 */  lui   $v1, %hi(stanSavedColl_posData)
/* 062B50 7F02E020 1100000F */  beqz  $t0, .L7F02E060
/* 062B54 7F02E024 00000000 */   nop   
/* 062B58 7F02E028 C4A60008 */  lwc1  $f6, 8($a1)
/* 062B5C 7F02E02C 8FAB0274 */  lw    $t3, 0x274($sp)
/* 062B60 7F02E030 2406FFFF */  li    $a2, -1
/* 062B64 7F02E034 E7A60258 */  swc1  $f6, 0x258($sp)
/* 062B68 7F02E038 C4AA000C */  lwc1  $f10, 0xc($a1)
/* 062B6C 7F02E03C E7AA025C */  swc1  $f10, 0x25c($sp)
/* 062B70 7F02E040 C4A40010 */  lwc1  $f4, 0x10($a1)
/* 062B74 7F02E044 E7A40260 */  swc1  $f4, 0x260($sp)
/* 062B78 7F02E048 8CA90014 */  lw    $t1, 0x14($a1)
/* 062B7C 7F02E04C AFA90254 */  sw    $t1, 0x254($sp)
/* 062B80 7F02E050 0FC19107 */  jal   recall_joy2_hits_edit_detail_edit_flag
/* 062B84 7F02E054 81640080 */   lb    $a0, 0x80($t3)
/* 062B88 7F02E058 10000012 */  b     .L7F02E0A4
/* 062B8C 7F02E05C 8FAC022C */   lw    $t4, 0x22c($sp)
.L7F02E060:
/* 062B90 7F02E060 8C63BA04 */  lw    $v1, %lo(stanSavedColl_posData)($v1)
/* 062B94 7F02E064 C7A8020C */  lwc1  $f8, 0x20c($sp)
/* 062B98 7F02E068 10600006 */  beqz  $v1, .L7F02E084
/* 062B9C 7F02E06C 00000000 */   nop   
/* 062BA0 7F02E070 90620000 */  lbu   $v0, ($v1)
/* 062BA4 7F02E074 24010003 */  li    $at, 3
/* 062BA8 7F02E078 10410009 */  beq   $v0, $at, .L7F02E0A0
/* 062BAC 7F02E07C 24010006 */   li    $at, 6
/* 062BB0 7F02E080 10410007 */  beq   $v0, $at, .L7F02E0A0
.L7F02E084:
/* 062BB4 7F02E084 3C018005 */   lui   $at, %hi(D_80051F78)
/* 062BB8 7F02E088 C4261F78 */  lwc1  $f6, %lo(D_80051F78)($at)
/* 062BBC 7F02E08C 4606403C */  c.lt.s $f8, $f6
/* 062BC0 7F02E090 00000000 */  nop   
/* 062BC4 7F02E094 45020003 */  bc1fl .L7F02E0A4
/* 062BC8 7F02E098 8FAC022C */   lw    $t4, 0x22c($sp)
/* 062BCC 7F02E09C AFA0022C */  sw    $zero, 0x22c($sp)
.L7F02E0A0:
/* 062BD0 7F02E0A0 8FAC022C */  lw    $t4, 0x22c($sp)
.L7F02E0A4:
/* 062BD4 7F02E0A4 8FAD0254 */  lw    $t5, 0x254($sp)
/* 062BD8 7F02E0A8 5180003D */  beql  $t4, $zero, .L7F02E1A0
/* 062BDC 7F02E0AC 8FAC0264 */   lw    $t4, 0x264($sp)
/* 062BE0 7F02E0B0 11A00005 */  beqz  $t5, .L7F02E0C8
/* 062BE4 7F02E0B4 27A40258 */   addiu $a0, $sp, 0x258
/* 062BE8 7F02E0B8 24050001 */  li    $a1, 1
/* 062BEC 7F02E0BC 3C0641D0 */  lui   $a2, 0x41d0
/* 062BF0 7F02E0C0 0FC28F87 */  jal   sub_GAME_7F0A3E1C
/* 062BF4 7F02E0C4 91A70003 */   lbu   $a3, 3($t5)
.L7F02E0C8:
/* 062BF8 7F02E0C8 3C058008 */  lui   $a1, %hi(stanSavedColl_posData)
/* 062BFC 7F02E0CC 8CA5BA04 */  lw    $a1, %lo(stanSavedColl_posData)($a1)
/* 062C00 7F02E0D0 8FAE0274 */  lw    $t6, 0x274($sp)
/* 062C04 7F02E0D4 2406FFFF */  li    $a2, -1
/* 062C08 7F02E0D8 10A0002D */  beqz  $a1, .L7F02E190
/* 062C0C 7F02E0DC 81C70080 */   lb    $a3, 0x80($t6)
/* 062C10 7F02E0E0 00E02025 */  move  $a0, $a3
/* 062C14 7F02E0E4 0FC19107 */  jal   recall_joy2_hits_edit_detail_edit_flag
/* 062C18 7F02E0E8 2406FFFF */   li    $a2, -1
/* 062C1C 7F02E0EC 3C038008 */  lui   $v1, %hi(stanSavedColl_posData)
/* 062C20 7F02E0F0 8C63BA04 */  lw    $v1, %lo(stanSavedColl_posData)($v1)
/* 062C24 7F02E0F4 24010003 */  li    $at, 3
/* 062C28 7F02E0F8 8FAF0288 */  lw    $t7, 0x288($sp)
/* 062C2C 7F02E0FC 90620000 */  lbu   $v0, ($v1)
/* 062C30 7F02E100 5441000F */  bnel  $v0, $at, .L7F02E140
/* 062C34 7F02E104 24010001 */   li    $at, 1
/* 062C38 7F02E108 8DF80014 */  lw    $t8, 0x14($t7)
/* 062C3C 7F02E10C 2405000F */  li    $a1, 15
/* 062C40 7F02E110 8FA80274 */  lw    $t0, 0x274($sp)
/* 062C44 7F02E114 33190040 */  andi  $t9, $t8, 0x40
/* 062C48 7F02E118 53200021 */  beql  $t9, $zero, .L7F02E1A0
/* 062C4C 7F02E11C 8FAC0264 */   lw    $t4, 0x264($sp)
/* 062C50 7F02E120 8C640004 */  lw    $a0, 4($v1)
/* 062C54 7F02E124 81070080 */  lb    $a3, 0x80($t0)
/* 062C58 7F02E128 AFA00010 */  sw    $zero, 0x10($sp)
/* 062C5C 7F02E12C 0FC09C9F */  jal   handles_shot_actors
/* 062C60 7F02E130 27A60220 */   addiu $a2, $sp, 0x220
/* 062C64 7F02E134 1000001A */  b     .L7F02E1A0
/* 062C68 7F02E138 8FAC0264 */   lw    $t4, 0x264($sp)
/* 062C6C 7F02E13C 24010001 */  li    $at, 1
.L7F02E140:
/* 062C70 7F02E140 10410004 */  beq   $v0, $at, .L7F02E154
/* 062C74 7F02E144 8FA90274 */   lw    $t1, 0x274($sp)
/* 062C78 7F02E148 24010004 */  li    $at, 4
/* 062C7C 7F02E14C 54410014 */  bnel  $v0, $at, .L7F02E1A0
/* 062C80 7F02E150 8FAC0264 */   lw    $t4, 0x264($sp)
.L7F02E154:
/* 062C84 7F02E154 0FC177E1 */  jal   bondwalkItemGetDestructionAmount
/* 062C88 7F02E158 81240080 */   lb    $a0, 0x80($t1)
/* 062C8C 7F02E15C 0FC26C54 */  jal   get_cur_playernum
/* 062C90 7F02E160 E7A0004C */   swc1  $f0, 0x4c($sp)
/* 062C94 7F02E164 3C0B8008 */  lui   $t3, %hi(stanSavedColl_posData) 
/* 062C98 7F02E168 8D6BBA04 */  lw    $t3, %lo(stanSavedColl_posData)($t3)
/* 062C9C 7F02E16C 8FAA0274 */  lw    $t2, 0x274($sp)
/* 062CA0 7F02E170 8FA5004C */  lw    $a1, 0x4c($sp)
/* 062CA4 7F02E174 8D640004 */  lw    $a0, 4($t3)
/* 062CA8 7F02E178 81470080 */  lb    $a3, 0x80($t2)
/* 062CAC 7F02E17C AFA20010 */  sw    $v0, 0x10($sp)
/* 062CB0 7F02E180 0FC13833 */  jal   sub_GAME_7F04E0CC
/* 062CB4 7F02E184 27A60258 */   addiu $a2, $sp, 0x258
/* 062CB8 7F02E188 10000005 */  b     .L7F02E1A0
/* 062CBC 7F02E18C 8FAC0264 */   lw    $t4, 0x264($sp)
.L7F02E190:
/* 062CC0 7F02E190 00E02025 */  move  $a0, $a3
/* 062CC4 7F02E194 0FC191DD */  jal   recall_joy2_hits_edit_flag
/* 062CC8 7F02E198 27A50258 */   addiu $a1, $sp, 0x258
/* 062CCC 7F02E19C 8FAC0264 */  lw    $t4, 0x264($sp)
.L7F02E1A0:
/* 062CD0 7F02E1A0 8FAD0274 */  lw    $t5, 0x274($sp)
/* 062CD4 7F02E1A4 51800010 */  beql  $t4, $zero, .L7F02E1E8
/* 062CD8 7F02E1A8 8FB90264 */   lw    $t9, 0x264($sp)
/* 062CDC 7F02E1AC 81AE0080 */  lb    $t6, 0x80($t5)
/* 062CE0 7F02E1B0 25CFFFFC */  addiu $t7, $t6, -4
/* 062CE4 7F02E1B4 2DE10013 */  sltiu $at, $t7, 0x13
/* 062CE8 7F02E1B8 10200009 */  beqz  $at, .L7F02E1E0
/* 062CEC 7F02E1BC 000F7880 */   sll   $t7, $t7, 2
/* 062CF0 7F02E1C0 3C018005 */  lui   $at, %hi(jpt_80051F7C)
/* 062CF4 7F02E1C4 002F0821 */  addu  $at, $at, $t7
/* 062CF8 7F02E1C8 8C2F1F7C */  lw    $t7, %lo(jpt_80051F7C)($at)
/* 062CFC 7F02E1CC 01E00008 */  jr    $t7
/* 062D00 7F02E1D0 00000000 */   nop   
weapon_guard_fires_bullet_projectile:
/* 062D04 7F02E1D4 24180001 */  li    $t8, 1
/* 062D08 7F02E1D8 10000002 */  b     .L7F02E1E4
/* 062D0C 7F02E1DC AFB80264 */   sw    $t8, 0x264($sp)
weapon_guard_fires_bullet_no_projectile:
.L7F02E1E0:
/* 062D10 7F02E1E0 AFA00264 */  sw    $zero, 0x264($sp)
.L7F02E1E4:
/* 062D14 7F02E1E4 8FB90264 */  lw    $t9, 0x264($sp)
.L7F02E1E8:
/* 062D18 7F02E1E8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 062D1C 7F02E1EC 8FA80288 */  lw    $t0, 0x288($sp)
/* 062D20 7F02E1F0 1320000C */  beqz  $t9, .L7F02E224
/* 062D24 7F02E1F4 00095880 */   sll   $t3, $t1, 2
/* 062D28 7F02E1F8 01695823 */  subu  $t3, $t3, $t1
/* 062D2C 7F02E1FC 000B5880 */  sll   $t3, $t3, 2
/* 062D30 7F02E200 01695823 */  subu  $t3, $t3, $t1
/* 062D34 7F02E204 8FAA0274 */  lw    $t2, 0x274($sp)
/* 062D38 7F02E208 000B5880 */  sll   $t3, $t3, 2
/* 062D3C 7F02E20C 010B2021 */  addu  $a0, $t0, $t3
/* 062D40 7F02E210 24840180 */  addiu $a0, $a0, 0x180
/* 062D44 7F02E214 27A60240 */  addiu $a2, $sp, 0x240
/* 062D48 7F02E218 27A70258 */  addiu $a3, $sp, 0x258
/* 062D4C 7F02E21C 0FC18652 */  jal   sub_GAME_7F061948
/* 062D50 7F02E220 81450080 */   lb    $a1, 0x80($t2)
.L7F02E224:
/* 062D54 7F02E224 8FA2027C */  lw    $v0, 0x27c($sp)
.L7F02E228:
/* 062D58 7F02E228 8FA40288 */  lw    $a0, 0x288($sp)
/* 062D5C 7F02E22C 0002302B */  sltu  $a2, $zero, $v0
/* 062D60 7F02E230 14C00004 */  bnez  $a2, .L7F02E244
/* 062D64 7F02E234 00000000 */   nop   
/* 062D68 7F02E238 8FA60278 */  lw    $a2, 0x278($sp)
/* 062D6C 7F02E23C 0006682B */  sltu  $t5, $zero, $a2
/* 062D70 7F02E240 01A03025 */  move  $a2, $t5
.L7F02E244:
/* 062D74 7F02E244 0FC0AFF9 */  jal   sub_GAME_7F02BFE4
/* 062D78 7F02E248 8FA5028C */   lw    $a1, 0x28c($sp)
.L7F02E24C:
/* 062D7C 7F02E24C 8FA40288 */  lw    $a0, 0x288($sp)
/* 062D80 7F02E250 8FA5028C */  lw    $a1, 0x28c($sp)
/* 062D84 7F02E254 0FC0B446 */  jal   sub_GAME_7F02D118
/* 062D88 7F02E258 8FA6027C */   lw    $a2, 0x27c($sp)
/* 062D8C 7F02E25C 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F02E260:
/* 062D90 7F02E260 27BD0288 */  addiu $sp, $sp, 0x288
/* 062D94 7F02E264 03E00008 */  jr    $ra
/* 062D98 7F02E268 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02E26C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02E26C
/* 062D9C 7F02E26C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 062DA0 7F02E270 AFBF0014 */  sw    $ra, 0x14($sp)
/* 062DA4 7F02E274 948E0012 */  lhu   $t6, 0x12($a0)
/* 062DA8 7F02E278 00002825 */  move  $a1, $zero
/* 062DAC 7F02E27C 31CFFF7F */  andi  $t7, $t6, 0xff7f
/* 062DB0 7F02E280 31E2FFFF */  andi  $v0, $t7, 0xffff
/* 062DB4 7F02E284 30580008 */  andi  $t8, $v0, 8
/* 062DB8 7F02E288 13000008 */  beqz  $t8, .L7F02E2AC
/* 062DBC 7F02E28C A48F0012 */   sh    $t7, 0x12($a0)
/* 062DC0 7F02E290 0FC0B5CD */  jal   sub_GAME_7F02D734
/* 062DC4 7F02E294 AFA40018 */   sw    $a0, 0x18($sp)
/* 062DC8 7F02E298 8FA40018 */  lw    $a0, 0x18($sp)
/* 062DCC 7F02E29C 94990012 */  lhu   $t9, 0x12($a0)
/* 062DD0 7F02E2A0 3328FFF7 */  andi  $t0, $t9, 0xfff7
/* 062DD4 7F02E2A4 3102FFFF */  andi  $v0, $t0, 0xffff
/* 062DD8 7F02E2A8 A4880012 */  sh    $t0, 0x12($a0)
.L7F02E2AC:
/* 062DDC 7F02E2AC 30490004 */  andi  $t1, $v0, 4
/* 062DE0 7F02E2B0 11200007 */  beqz  $t1, .L7F02E2D0
/* 062DE4 7F02E2B4 24050001 */   li    $a1, 1
/* 062DE8 7F02E2B8 0FC0B5CD */  jal   sub_GAME_7F02D734
/* 062DEC 7F02E2BC AFA40018 */   sw    $a0, 0x18($sp)
/* 062DF0 7F02E2C0 8FA40018 */  lw    $a0, 0x18($sp)
/* 062DF4 7F02E2C4 948A0012 */  lhu   $t2, 0x12($a0)
/* 062DF8 7F02E2C8 314BFFFB */  andi  $t3, $t2, 0xfffb
/* 062DFC 7F02E2CC A48B0012 */  sh    $t3, 0x12($a0)
.L7F02E2D0:
/* 062E00 7F02E2D0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 062E04 7F02E2D4 27BD0018 */  addiu $sp, $sp, 0x18
/* 062E08 7F02E2D8 03E00008 */  jr    $ra
/* 062E0C 7F02E2DC 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02E2E0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02E2E0
/* 062E10 7F02E2E0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 062E14 7F02E2E4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 062E18 7F02E2E8 8C82002C */  lw    $v0, 0x2c($a0)
/* 062E1C 7F02E2EC 3C0E8003 */  lui   $t6, %hi(D_80030108) 
/* 062E20 7F02E2F0 25CE0108 */  addiu $t6, %lo(D_80030108) # addiu $t6, $t6, 0x108
/* 062E24 7F02E2F4 11C20004 */  beq   $t6, $v0, .L7F02E308
/* 062E28 7F02E2F8 3C0F8003 */   lui   $t7, %hi(D_80030150) 
/* 062E2C 7F02E2FC 25EF0150 */  addiu $t7, %lo(D_80030150) # addiu $t7, $t7, 0x150
/* 062E30 7F02E300 55E20029 */  bnel  $t7, $v0, .L7F02E3A8
/* 062E34 7F02E304 00001025 */   move  $v0, $zero
.L7F02E308:
/* 062E38 7F02E308 8C82001C */  lw    $v0, 0x1c($a0)
/* 062E3C 7F02E30C 3C088003 */  lui   $t0, %hi(D_800300C0) 
/* 062E40 7F02E310 24190002 */  li    $t9, 2
/* 062E44 7F02E314 80580024 */  lb    $t8, 0x24($v0)
/* 062E48 7F02E318 250800C0 */  addiu $t0, %lo(D_800300C0) # addiu $t0, $t0, 0xc0
/* 062E4C 7F02E31C 3C053F33 */  lui   $a1, (0x3F333333 >> 16) # lui $a1, 0x3f33
/* 062E50 7F02E320 AFB80024 */  sw    $t8, 0x24($sp)
/* 062E54 7F02E324 A0990030 */  sb    $t9, 0x30($a0)
/* 062E58 7F02E328 AC88002C */  sw    $t0, 0x2c($a0)
/* 062E5C 7F02E32C A0800008 */  sb    $zero, 8($a0)
/* 062E60 7F02E330 3C063F8F */  lui   $a2, (0x3F8F5C29 >> 16) # lui $a2, 0x3f8f
/* 062E64 7F02E334 34C65C29 */  ori   $a2, (0x3F8F5C29 & 0xFFFF) # ori $a2, $a2, 0x5c29
/* 062E68 7F02E338 34A53333 */  ori   $a1, (0x3F333333 & 0xFFFF) # ori $a1, $a1, 0x3333
/* 062E6C 7F02E33C 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 062E70 7F02E340 AFA2002C */   sw    $v0, 0x2c($sp)
/* 062E74 7F02E344 3C0141B0 */  li    $at, 0x41B00000 # 22.000000
/* 062E78 7F02E348 44812000 */  mtc1  $at, $f4
/* 062E7C 7F02E34C 3C058003 */  lui   $a1, %hi(D_800300C0)
/* 062E80 7F02E350 3C078003 */  lui   $a3, %hi(D_800300C0+0x1C)
/* 062E84 7F02E354 8CE700DC */  lw    $a3, %lo(D_800300C0+0x1C)($a3)
/* 062E88 7F02E358 8CA500C0 */  lw    $a1, %lo(D_800300C0)($a1)
/* 062E8C 7F02E35C 8FA4002C */  lw    $a0, 0x2c($sp)
/* 062E90 7F02E360 8FA60024 */  lw    $a2, 0x24($sp)
/* 062E94 7F02E364 E7A00010 */  swc1  $f0, 0x10($sp)
/* 062E98 7F02E368 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 062E9C 7F02E36C E7A40014 */   swc1  $f4, 0x14($sp)
/* 062EA0 7F02E370 3C018003 */  lui   $at, %hi(D_800300C0+0x14)
/* 062EA4 7F02E374 C42000D4 */  lwc1  $f0, %lo(D_800300C0+0x14)($at)
/* 062EA8 7F02E378 44803000 */  mtc1  $zero, $f6
/* 062EAC 7F02E37C 00000000 */  nop   
/* 062EB0 7F02E380 4600303E */  c.le.s $f6, $f0
/* 062EB4 7F02E384 00000000 */  nop   
/* 062EB8 7F02E388 45000004 */  bc1f  .L7F02E39C
/* 062EBC 7F02E38C 00000000 */   nop   
/* 062EC0 7F02E390 44050000 */  mfc1  $a1, $f0
/* 062EC4 7F02E394 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 062EC8 7F02E398 8FA4002C */   lw    $a0, 0x2c($sp)
.L7F02E39C:
/* 062ECC 7F02E39C 10000002 */  b     .L7F02E3A8
/* 062ED0 7F02E3A0 24020001 */   li    $v0, 1
/* 062ED4 7F02E3A4 00001025 */  move  $v0, $zero
.L7F02E3A8:
/* 062ED8 7F02E3A8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 062EDC 7F02E3AC 27BD0030 */  addiu $sp, $sp, 0x30
/* 062EE0 7F02E3B0 03E00008 */  jr    $ra
/* 062EE4 7F02E3B4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02E3B8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02E3B8
/* 062EE8 7F02E3B8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 062EEC 7F02E3BC AFBF0024 */  sw    $ra, 0x24($sp)
/* 062EF0 7F02E3C0 AFB10020 */  sw    $s1, 0x20($sp)
/* 062EF4 7F02E3C4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 062EF8 7F02E3C8 8C8E002C */  lw    $t6, 0x2c($a0)
/* 062EFC 7F02E3CC 44802000 */  mtc1  $zero, $f4
/* 062F00 7F02E3D0 00808825 */  move  $s1, $a0
/* 062F04 7F02E3D4 C5C60024 */  lwc1  $f6, 0x24($t6)
/* 062F08 7F02E3D8 8C90001C */  lw    $s0, 0x1c($a0)
/* 062F0C 7F02E3DC 4606203C */  c.lt.s $f4, $f6
/* 062F10 7F02E3E0 00000000 */  nop   
/* 062F14 7F02E3E4 45000015 */  bc1f  .L7F02E43C
/* 062F18 7F02E3E8 00000000 */   nop   
/* 062F1C 7F02E3EC 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 062F20 7F02E3F0 02002025 */   move  $a0, $s0
/* 062F24 7F02E3F4 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 062F28 7F02E3F8 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 062F2C 7F02E3FC AFA2002C */  sw    $v0, 0x2c($sp)
/* 062F30 7F02E400 02202025 */  move  $a0, $s1
/* 062F34 7F02E404 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 062F38 7F02E408 3C053F00 */   lui   $a1, 0x3f00
/* 062F3C 7F02E40C 8E2F002C */  lw    $t7, 0x2c($s1)
/* 062F40 7F02E410 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 062F44 7F02E414 44814000 */  mtc1  $at, $f8
/* 062F48 7F02E418 82060024 */  lb    $a2, 0x24($s0)
/* 062F4C 7F02E41C 8DE70024 */  lw    $a3, 0x24($t7)
/* 062F50 7F02E420 E7A00010 */  swc1  $f0, 0x10($sp)
/* 062F54 7F02E424 02002025 */  move  $a0, $s0
/* 062F58 7F02E428 8FA5002C */  lw    $a1, 0x2c($sp)
/* 062F5C 7F02E42C 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 062F60 7F02E430 E7A80014 */   swc1  $f8, 0x14($sp)
/* 062F64 7F02E434 10000014 */  b     .L7F02E488
/* 062F68 7F02E438 8E39002C */   lw    $t9, 0x2c($s1)
.L7F02E43C:
/* 062F6C 7F02E43C 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 062F70 7F02E440 02002025 */   move  $a0, $s0
/* 062F74 7F02E444 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 062F78 7F02E448 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 062F7C 7F02E44C AFA2002C */  sw    $v0, 0x2c($sp)
/* 062F80 7F02E450 02202025 */  move  $a0, $s1
/* 062F84 7F02E454 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 062F88 7F02E458 3C053F00 */   lui   $a1, 0x3f00
/* 062F8C 7F02E45C 8E38002C */  lw    $t8, 0x2c($s1)
/* 062F90 7F02E460 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 062F94 7F02E464 44815000 */  mtc1  $at, $f10
/* 062F98 7F02E468 82060024 */  lb    $a2, 0x24($s0)
/* 062F9C 7F02E46C 8F07001C */  lw    $a3, 0x1c($t8)
/* 062FA0 7F02E470 E7A00010 */  swc1  $f0, 0x10($sp)
/* 062FA4 7F02E474 02002025 */  move  $a0, $s0
/* 062FA8 7F02E478 8FA5002C */  lw    $a1, 0x2c($sp)
/* 062FAC 7F02E47C 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 062FB0 7F02E480 E7AA0014 */   swc1  $f10, 0x14($sp)
/* 062FB4 7F02E484 8E39002C */  lw    $t9, 0x2c($s1)
.L7F02E488:
/* 062FB8 7F02E488 44808000 */  mtc1  $zero, $f16
/* 062FBC 7F02E48C C7200014 */  lwc1  $f0, 0x14($t9)
/* 062FC0 7F02E490 4600803E */  c.le.s $f16, $f0
/* 062FC4 7F02E494 00000000 */  nop   
/* 062FC8 7F02E498 45020005 */  bc1fl .L7F02E4B0
/* 062FCC 7F02E49C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 062FD0 7F02E4A0 44050000 */  mfc1  $a1, $f0
/* 062FD4 7F02E4A4 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 062FD8 7F02E4A8 02002025 */   move  $a0, $s0
/* 062FDC 7F02E4AC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F02E4B0:
/* 062FE0 7F02E4B0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 062FE4 7F02E4B4 8FB10020 */  lw    $s1, 0x20($sp)
/* 062FE8 7F02E4B8 03E00008 */  jr    $ra
/* 062FEC 7F02E4BC 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02E4C0(void) {

}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80051FC8
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02E4C0
/* 062FF0 7F02E4C0 27BDFF90 */  addiu $sp, $sp, -0x70
/* 062FF4 7F02E4C4 AFBF0044 */  sw    $ra, 0x44($sp)
/* 062FF8 7F02E4C8 AFB30040 */  sw    $s3, 0x40($sp)
/* 062FFC 7F02E4CC AFB2003C */  sw    $s2, 0x3c($sp)
/* 063000 7F02E4D0 AFB10038 */  sw    $s1, 0x38($sp)
/* 063004 7F02E4D4 AFB00034 */  sw    $s0, 0x34($sp)
/* 063008 7F02E4D8 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 06300C 7F02E4DC F7B60020 */  sdc1  $f22, 0x20($sp)
/* 063010 7F02E4E0 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 063014 7F02E4E4 8C93001C */  lw    $s3, 0x1c($a0)
/* 063018 7F02E4E8 00808025 */  move  $s0, $a0
/* 06301C 7F02E4EC 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 063020 7F02E4F0 02602025 */   move  $a0, $s3
/* 063024 7F02E4F4 8E0F0044 */  lw    $t7, 0x44($s0)
/* 063028 7F02E4F8 8E0E0048 */  lw    $t6, 0x48($s0)
/* 06302C 7F02E4FC 46000506 */  mov.s $f20, $f0
/* 063030 7F02E500 25F8FFE2 */  addiu $t8, $t7, -0x1e
/* 063034 7F02E504 01D8082A */  slt   $at, $t6, $t8
/* 063038 7F02E508 5020004B */  beql  $at, $zero, .L7F02E638
/* 06303C 7F02E50C 3C013F00 */   lui   $at, 0x3f00
/* 063040 7F02E510 8E790054 */  lw    $t9, 0x54($s3)
/* 063044 7F02E514 57200048 */  bnezl $t9, .L7F02E638
/* 063048 7F02E518 3C013F00 */   lui   $at, 0x3f00
/* 06304C 7F02E51C 8E05002C */  lw    $a1, 0x2c($s0)
/* 063050 7F02E520 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 063054 7F02E524 44813000 */  mtc1  $at, $f6
/* 063058 7F02E528 C4A40018 */  lwc1  $f4, 0x18($a1)
/* 06305C 7F02E52C 46062200 */  add.s $f8, $f4, $f6
/* 063060 7F02E530 4600403C */  c.lt.s $f8, $f0
/* 063064 7F02E534 00000000 */  nop   
/* 063068 7F02E538 4502003F */  bc1fl .L7F02E638
/* 06306C 7F02E53C 3C013F00 */   lui   $at, 0x3f00
/* 063070 7F02E540 C4AA001C */  lwc1  $f10, 0x1c($a1)
/* 063074 7F02E544 460A003C */  c.lt.s $f0, $f10
/* 063078 7F02E548 00000000 */  nop   
/* 06307C 7F02E54C 4502003A */  bc1fl .L7F02E638
/* 063080 7F02E550 3C013F00 */   lui   $at, 0x3f00
/* 063084 7F02E554 4480B000 */  mtc1  $zero, $f22
/* 063088 7F02E558 C4A20024 */  lwc1  $f2, 0x24($a1)
/* 06308C 7F02E55C 4616103C */  c.lt.s $f2, $f22
/* 063090 7F02E560 00000000 */  nop   
/* 063094 7F02E564 45030006 */  bc1tl .L7F02E580
/* 063098 7F02E568 82080036 */   lb    $t0, 0x36($s0)
/* 06309C 7F02E56C 4602003C */  c.lt.s $f0, $f2
/* 0630A0 7F02E570 00000000 */  nop   
/* 0630A4 7F02E574 45020030 */  bc1fl .L7F02E638
/* 0630A8 7F02E578 3C013F00 */   li    $at, 0x3F000000 # 0.500000
/* 0630AC 7F02E57C 82080036 */  lb    $t0, 0x36($s0)
.L7F02E580:
/* 0630B0 7F02E580 15000024 */  bnez  $t0, .L7F02E614
/* 0630B4 7F02E584 00000000 */   nop   
/* 0630B8 7F02E588 0FC0B8B8 */  jal   sub_GAME_7F02E2E0
/* 0630BC 7F02E58C 02002025 */   move  $a0, $s0
/* 0630C0 7F02E590 1440001E */  bnez  $v0, .L7F02E60C
/* 0630C4 7F02E594 00000000 */   nop   
/* 0630C8 7F02E598 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 0630CC 7F02E59C 02602025 */   move  $a0, $s3
/* 0630D0 7F02E5A0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0630D4 7F02E5A4 4481C000 */  mtc1  $at, $f24
/* 0630D8 7F02E5A8 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 0630DC 7F02E5AC 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0630E0 7F02E5B0 4405C000 */  mfc1  $a1, $f24
/* 0630E4 7F02E5B4 00408825 */  move  $s1, $v0
/* 0630E8 7F02E5B8 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 0630EC 7F02E5BC 02002025 */   move  $a0, $s0
/* 0630F0 7F02E5C0 8E09002C */  lw    $t1, 0x2c($s0)
/* 0630F4 7F02E5C4 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 0630F8 7F02E5C8 44818000 */  mtc1  $at, $f16
/* 0630FC 7F02E5CC 82660024 */  lb    $a2, 0x24($s3)
/* 063100 7F02E5D0 8D27001C */  lw    $a3, 0x1c($t1)
/* 063104 7F02E5D4 E7A00010 */  swc1  $f0, 0x10($sp)
/* 063108 7F02E5D8 02602025 */  move  $a0, $s3
/* 06310C 7F02E5DC 02202825 */  move  $a1, $s1
/* 063110 7F02E5E0 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 063114 7F02E5E4 E7B00014 */   swc1  $f16, 0x14($sp)
/* 063118 7F02E5E8 8E0A002C */  lw    $t2, 0x2c($s0)
/* 06311C 7F02E5EC C5400014 */  lwc1  $f0, 0x14($t2)
/* 063120 7F02E5F0 4600B03E */  c.le.s $f22, $f0
/* 063124 7F02E5F4 00000000 */  nop   
/* 063128 7F02E5F8 45000004 */  bc1f  .L7F02E60C
/* 06312C 7F02E5FC 00000000 */   nop   
/* 063130 7F02E600 44050000 */  mfc1  $a1, $f0
/* 063134 7F02E604 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 063138 7F02E608 02602025 */   move  $a0, $s3
.L7F02E60C:
/* 06313C 7F02E60C 10000004 */  b     .L7F02E620
/* 063140 7F02E610 820B0034 */   lb    $t3, 0x34($s0)
.L7F02E614:
/* 063144 7F02E614 0FC0B8EE */  jal   sub_GAME_7F02E3B8
/* 063148 7F02E618 02002025 */   move  $a0, $s0
/* 06314C 7F02E61C 820B0034 */  lb    $t3, 0x34($s0)
.L7F02E620:
/* 063150 7F02E620 02602025 */  move  $a0, $s3
/* 063154 7F02E624 256C0001 */  addiu $t4, $t3, 1
/* 063158 7F02E628 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 06315C 7F02E62C A20C0033 */   sb    $t4, 0x33($s0)
/* 063160 7F02E630 46000506 */  mov.s $f20, $f0
/* 063164 7F02E634 3C013F00 */  li    $at, 0x3F000000 # 0.500000
.L7F02E638:
/* 063168 7F02E638 4481C000 */  mtc1  $at, $f24
/* 06316C 7F02E63C 4480B000 */  mtc1  $zero, $f22
/* 063170 7F02E640 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 063174 7F02E644 02602025 */   move  $a0, $s3
/* 063178 7F02E648 4614003E */  c.le.s $f0, $f20
/* 06317C 7F02E64C 00000000 */  nop   
/* 063180 7F02E650 45020076 */  bc1fl .L7F02E82C
/* 063184 7F02E654 8E02004C */   lw    $v0, 0x4c($s0)
/* 063188 7F02E658 820D0037 */  lb    $t5, 0x37($s0)
/* 06318C 7F02E65C 15A00006 */  bnez  $t5, .L7F02E678
/* 063190 7F02E660 00000000 */   nop   
/* 063194 7F02E664 82030034 */  lb    $v1, 0x34($s0)
/* 063198 7F02E668 82020033 */  lb    $v0, 0x33($s0)
/* 06319C 7F02E66C 0062082A */  slt   $at, $v1, $v0
/* 0631A0 7F02E670 1020000F */  beqz  $at, .L7F02E6B0
/* 0631A4 7F02E674 00000000 */   nop   
.L7F02E678:
/* 0631A8 7F02E678 0FC0B8B8 */  jal   sub_GAME_7F02E2E0
/* 0631AC 7F02E67C 02002025 */   move  $a0, $s0
/* 0631B0 7F02E680 14400066 */  bnez  $v0, .L7F02E81C
/* 0631B4 7F02E684 00000000 */   nop   
/* 0631B8 7F02E688 8E0F004C */  lw    $t7, 0x4c($s0)
/* 0631BC 7F02E68C 31EE0001 */  andi  $t6, $t7, 1
/* 0631C0 7F02E690 11C00003 */  beqz  $t6, .L7F02E6A0
/* 0631C4 7F02E694 00000000 */   nop   
/* 0631C8 7F02E698 0FC0A6EC */  jal   chrlvSetTargetToPlayer
/* 0631CC 7F02E69C 02002025 */   move  $a0, $s0
.L7F02E6A0:
/* 0631D0 7F02E6A0 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 0631D4 7F02E6A4 02002025 */   move  $a0, $s0
/* 0631D8 7F02E6A8 1000014B */  b     .L7F02EBD8
/* 0631DC 7F02E6AC 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F02E6B0:
/* 0631E0 7F02E6B0 14620006 */  bne   $v1, $v0, .L7F02E6CC
/* 0631E4 7F02E6B4 24580001 */   addiu $t8, $v0, 1
/* 0631E8 7F02E6B8 A2180033 */  sb    $t8, 0x33($s0)
/* 0631EC 7F02E6BC 0FC0B8EE */  jal   sub_GAME_7F02E3B8
/* 0631F0 7F02E6C0 02002025 */   move  $a0, $s0
/* 0631F4 7F02E6C4 10000055 */  b     .L7F02E81C
/* 0631F8 7F02E6C8 00000000 */   nop   
.L7F02E6CC:
/* 0631FC 7F02E6CC 82190031 */  lb    $t9, 0x31($s0)
/* 063200 7F02E6D0 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 063204 7F02E6D4 02602025 */  move  $a0, $s3
/* 063208 7F02E6D8 13200050 */  beqz  $t9, .L7F02E81C
/* 06320C 7F02E6DC 00000000 */   nop   
/* 063210 7F02E6E0 82080036 */  lb    $t0, 0x36($s0)
/* 063214 7F02E6E4 4600C306 */  mov.s $f12, $f24
/* 063218 7F02E6E8 51000014 */  beql  $t0, $zero, .L7F02E73C
/* 06321C 7F02E6EC 8E05002C */   lw    $a1, 0x2c($s0)
/* 063220 7F02E6F0 8E05002C */  lw    $a1, 0x2c($s0)
/* 063224 7F02E6F4 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 063228 7F02E6F8 4600B03C */  c.lt.s $f22, $f0
/* 06322C 7F02E6FC 00000000 */  nop   
/* 063230 7F02E700 45020004 */  bc1fl .L7F02E714
/* 063234 7F02E704 C4AE0018 */   lwc1  $f14, 0x18($a1)
/* 063238 7F02E708 10000002 */  b     .L7F02E714
/* 06323C 7F02E70C 46000386 */   mov.s $f14, $f0
/* 063240 7F02E710 C4AE0018 */  lwc1  $f14, 0x18($a1)
.L7F02E714:
/* 063244 7F02E714 C4A20024 */  lwc1  $f2, 0x24($a1)
/* 063248 7F02E718 4602B03C */  c.lt.s $f22, $f2
/* 06324C 7F02E71C 00000000 */  nop   
/* 063250 7F02E720 45000003 */  bc1f  .L7F02E730
/* 063254 7F02E724 00000000 */   nop   
/* 063258 7F02E728 1000000D */  b     .L7F02E760
/* 06325C 7F02E72C 46001506 */   mov.s $f20, $f2
.L7F02E730:
/* 063260 7F02E730 1000000B */  b     .L7F02E760
/* 063264 7F02E734 C4B4001C */   lwc1  $f20, 0x1c($a1)
/* 063268 7F02E738 8E05002C */  lw    $a1, 0x2c($s0)
.L7F02E73C:
/* 06326C 7F02E73C C4A00020 */  lwc1  $f0, 0x20($a1)
/* 063270 7F02E740 C4AE0018 */  lwc1  $f14, 0x18($a1)
/* 063274 7F02E744 4600B03C */  c.lt.s $f22, $f0
/* 063278 7F02E748 00000000 */  nop   
/* 06327C 7F02E74C 45020004 */  bc1fl .L7F02E760
/* 063280 7F02E750 C4B4001C */   lwc1  $f20, 0x1c($a1)
/* 063284 7F02E754 10000002 */  b     .L7F02E760
/* 063288 7F02E758 46000506 */   mov.s $f20, $f0
/* 06328C 7F02E75C C4B4001C */  lwc1  $f20, 0x1c($a1)
.L7F02E760:
/* 063290 7F02E760 460EA001 */  sub.s $f0, $f20, $f14
/* 063294 7F02E764 44811000 */  mtc1  $at, $f2
/* 063298 7F02E768 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 06329C 7F02E76C 4602003C */  c.lt.s $f0, $f2
/* 0632A0 7F02E770 00000000 */  nop   
/* 0632A4 7F02E774 45020005 */  bc1fl .L7F02E78C
/* 0632A8 7F02E778 44812000 */   mtc1  $at, $f4
/* 0632AC 7F02E77C 46180482 */  mul.s $f18, $f0, $f24
/* 0632B0 7F02E780 1000000D */  b     .L7F02E7B8
/* 0632B4 7F02E784 46029303 */   div.s $f12, $f18, $f2
/* 0632B8 7F02E788 44812000 */  mtc1  $at, $f4
.L7F02E78C:
/* 0632BC 7F02E78C 00000000 */  nop   
/* 0632C0 7F02E790 4600203C */  c.lt.s $f4, $f0
/* 0632C4 7F02E794 00000000 */  nop   
/* 0632C8 7F02E798 45020008 */  bc1fl .L7F02E7BC
/* 0632CC 7F02E79C 8209003A */   lb    $t1, 0x3a($s0)
/* 0632D0 7F02E7A0 46180182 */  mul.s $f6, $f0, $f24
/* 0632D4 7F02E7A4 3C013D80 */  li    $at, 0x3D800000 # 0.062500
/* 0632D8 7F02E7A8 44814000 */  mtc1  $at, $f8
/* 0632DC 7F02E7AC 00000000 */  nop   
/* 0632E0 7F02E7B0 46083302 */  mul.s $f12, $f6, $f8
/* 0632E4 7F02E7B4 00000000 */  nop   
.L7F02E7B8:
/* 0632E8 7F02E7B8 8209003A */  lb    $t1, 0x3a($s0)
.L7F02E7BC:
/* 0632EC 7F02E7BC 51200006 */  beql  $t1, $zero, .L7F02E7D8
/* 0632F0 7F02E7C0 A2000031 */   sb    $zero, 0x31($s0)
/* 0632F4 7F02E7C4 820A003B */  lb    $t2, 0x3b($s0)
/* 0632F8 7F02E7C8 51400003 */  beql  $t2, $zero, .L7F02E7D8
/* 0632FC 7F02E7CC A2000031 */   sb    $zero, 0x31($s0)
/* 063300 7F02E7D0 460C6300 */  add.s $f12, $f12, $f12
/* 063304 7F02E7D4 A2000031 */  sb    $zero, 0x31($s0)
.L7F02E7D8:
/* 063308 7F02E7D8 E7AE005C */  swc1  $f14, 0x5c($sp)
/* 06330C 7F02E7DC 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 063310 7F02E7E0 E7AC0060 */   swc1  $f12, 0x60($sp)
/* 063314 7F02E7E4 C7AE005C */  lwc1  $f14, 0x5c($sp)
/* 063318 7F02E7E8 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 06331C 7F02E7EC 44815000 */  mtc1  $at, $f10
/* 063320 7F02E7F0 C7AC0060 */  lwc1  $f12, 0x60($sp)
/* 063324 7F02E7F4 82660024 */  lb    $a2, 0x24($s3)
/* 063328 7F02E7F8 44077000 */  mfc1  $a3, $f14
/* 06332C 7F02E7FC 02602025 */  move  $a0, $s3
/* 063330 7F02E800 00402825 */  move  $a1, $v0
/* 063334 7F02E804 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 063338 7F02E808 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 06333C 7F02E80C E7AC0010 */   swc1  $f12, 0x10($sp)
/* 063340 7F02E810 4405A000 */  mfc1  $a1, $f20
/* 063344 7F02E814 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 063348 7F02E818 02602025 */   move  $a0, $s3
.L7F02E81C:
/* 06334C 7F02E81C 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 063350 7F02E820 02602025 */   move  $a0, $s3
/* 063354 7F02E824 46000506 */  mov.s $f20, $f0
/* 063358 7F02E828 8E02004C */  lw    $v0, 0x4c($s0)
.L7F02E82C:
/* 06335C 7F02E82C 304B0040 */  andi  $t3, $v0, 0x40
/* 063360 7F02E830 5560002B */  bnezl $t3, .L7F02E8E0
/* 063364 7F02E834 8E05002C */   lw    $a1, 0x2c($s0)
/* 063368 7F02E838 8E05002C */  lw    $a1, 0x2c($s0)
/* 06336C 7F02E83C 304C0020 */  andi  $t4, $v0, 0x20
/* 063370 7F02E840 02602025 */  move  $a0, $s3
/* 063374 7F02E844 C4A2000C */  lwc1  $f2, 0xc($a1)
/* 063378 7F02E848 1180000F */  beqz  $t4, .L7F02E888
/* 06337C 7F02E84C C4AC0004 */   lwc1  $f12, 4($a1)
/* 063380 7F02E850 E7A20050 */  swc1  $f2, 0x50($sp)
/* 063384 7F02E854 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 063388 7F02E858 E7AC004C */   swc1  $f12, 0x4c($sp)
/* 06338C 7F02E85C C7AC004C */  lwc1  $f12, 0x4c($sp)
/* 063390 7F02E860 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 063394 7F02E864 02602025 */  move  $a0, $s3
/* 063398 7F02E868 460C003C */  c.lt.s $f0, $f12
/* 06339C 7F02E86C 00000000 */  nop   
/* 0633A0 7F02E870 45020006 */  bc1fl .L7F02E88C
/* 0633A4 7F02E874 826D0024 */   lb    $t5, 0x24($s3)
/* 0633A8 7F02E878 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 0633AC 7F02E87C E7A20050 */   swc1  $f2, 0x50($sp)
/* 0633B0 7F02E880 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0633B4 7F02E884 46000306 */  mov.s $f12, $f0
.L7F02E888:
/* 0633B8 7F02E888 826D0024 */  lb    $t5, 0x24($s3)
.L7F02E88C:
/* 0633BC 7F02E88C 02002025 */  move  $a0, $s0
/* 0633C0 7F02E890 3C053F80 */  lui   $a1, 0x3f80
/* 0633C4 7F02E894 11A00004 */  beqz  $t5, .L7F02E8A8
/* 0633C8 7F02E898 3C063FCC */   lui   $a2, (0x3FCCCCCD >> 16) # lui $a2, 0x3fcc
/* 0633CC 7F02E89C 3C018005 */  lui   $at, %hi(D_80051FC8)
/* 0633D0 7F02E8A0 C4301FC8 */  lwc1  $f16, %lo(D_80051FC8)($at)
/* 0633D4 7F02E8A4 46028081 */  sub.s $f2, $f16, $f2
.L7F02E8A8:
/* 0633D8 7F02E8A8 34C6CCCD */  ori   $a2, (0x3FCCCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0633DC 7F02E8AC E7A20050 */  swc1  $f2, 0x50($sp)
/* 0633E0 7F02E8B0 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 0633E4 7F02E8B4 E7AC004C */   swc1  $f12, 0x4c($sp)
/* 0633E8 7F02E8B8 C7AC004C */  lwc1  $f12, 0x4c($sp)
/* 0633EC 7F02E8BC C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0633F0 7F02E8C0 82050030 */  lb    $a1, 0x30($s0)
/* 0633F4 7F02E8C4 44070000 */  mfc1  $a3, $f0
/* 0633F8 7F02E8C8 44066000 */  mfc1  $a2, $f12
/* 0633FC 7F02E8CC 02002025 */  move  $a0, $s0
/* 063400 7F02E8D0 0FC0B0AC */  jal   sub_GAME_7F02C2B0
/* 063404 7F02E8D4 E7A20010 */   swc1  $f2, 0x10($sp)
/* 063408 7F02E8D8 A2020030 */  sb    $v0, 0x30($s0)
/* 06340C 7F02E8DC 8E05002C */  lw    $a1, 0x2c($s0)
.L7F02E8E0:
/* 063410 7F02E8E0 C4B20028 */  lwc1  $f18, 0x28($a1)
/* 063414 7F02E8E4 4614903C */  c.lt.s $f18, $f20
/* 063418 7F02E8E8 00000000 */  nop   
/* 06341C 7F02E8EC 4500000F */  bc1f  .L7F02E92C
/* 063420 7F02E8F0 00000000 */   nop   
/* 063424 7F02E8F4 C4A4002C */  lwc1  $f4, 0x2c($a1)
/* 063428 7F02E8F8 02002025 */  move  $a0, $s0
/* 06342C 7F02E8FC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 063430 7F02E900 4604A03C */  c.lt.s $f20, $f4
/* 063434 7F02E904 00000000 */  nop   
/* 063438 7F02E908 45000008 */  bc1f  .L7F02E92C
/* 06343C 7F02E90C 00000000 */   nop   
/* 063440 7F02E910 44813000 */  mtc1  $at, $f6
/* 063444 7F02E914 82060039 */  lb    $a2, 0x39($s0)
/* 063448 7F02E918 82070038 */  lb    $a3, 0x38($s0)
/* 06344C 7F02E91C 0FC0B130 */  jal   sub_GAME_7F02C4C0
/* 063450 7F02E920 E7A60010 */   swc1  $f6, 0x10($sp)
/* 063454 7F02E924 10000004 */  b     .L7F02E938
/* 063458 7F02E928 00008825 */   move  $s1, $zero
.L7F02E92C:
/* 06345C 7F02E92C 0FC0B43E */  jal   sub_GAME_7F02D0F8
/* 063460 7F02E930 02002025 */   move  $a0, $s0
/* 063464 7F02E934 00008825 */  move  $s1, $zero
.L7F02E938:
/* 063468 7F02E938 02009025 */  move  $s2, $s0
.L7F02E93C:
/* 06346C 7F02E93C 824F0038 */  lb    $t7, 0x38($s2)
/* 063470 7F02E940 02002025 */  move  $a0, $s0
/* 063474 7F02E944 02202825 */  move  $a1, $s1
/* 063478 7F02E948 11E0009C */  beqz  $t7, .L7F02EBBC
/* 06347C 7F02E94C 00000000 */   nop   
/* 063480 7F02E950 824E003A */  lb    $t6, 0x3a($s2)
/* 063484 7F02E954 55C00064 */  bnezl $t6, .L7F02EAE8
/* 063488 7F02E958 82090031 */   lb    $t1, 0x31($s0)
/* 06348C 7F02E95C 8E05002C */  lw    $a1, 0x2c($s0)
/* 063490 7F02E960 02002025 */  move  $a0, $s0
/* 063494 7F02E964 00003025 */  move  $a2, $zero
/* 063498 7F02E968 C4A80018 */  lwc1  $f8, 0x18($a1)
/* 06349C 7F02E96C 4614403E */  c.le.s $f8, $f20
/* 0634A0 7F02E970 00000000 */  nop   
/* 0634A4 7F02E974 45000040 */  bc1f  .L7F02EA78
/* 0634A8 7F02E978 00000000 */   nop   
/* 0634AC 7F02E97C C4AA001C */  lwc1  $f10, 0x1c($a1)
/* 0634B0 7F02E980 02202825 */  move  $a1, $s1
/* 0634B4 7F02E984 460AA03C */  c.lt.s $f20, $f10
/* 0634B8 7F02E988 00000000 */  nop   
/* 0634BC 7F02E98C 4500003A */  bc1f  .L7F02EA78
/* 0634C0 7F02E990 00000000 */   nop   
/* 0634C4 7F02E994 02002025 */  move  $a0, $s0
/* 0634C8 7F02E998 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 0634CC 7F02E99C 24060001 */   li    $a2, 1
/* 0634D0 7F02E9A0 82190007 */  lb    $t9, 7($s0)
/* 0634D4 7F02E9A4 3C188005 */  lui   $t8, %hi(g_GlobalTimer) 
/* 0634D8 7F02E9A8 8F18837C */  lw    $t8, %lo(g_GlobalTimer)($t8)
/* 0634DC 7F02E9AC 2401000A */  li    $at, 10
/* 0634E0 7F02E9B0 1721002B */  bne   $t9, $at, .L7F02EA60
/* 0634E4 7F02E9B4 AE180044 */   sw    $t8, 0x44($s0)
/* 0634E8 7F02E9B8 8E05002C */  lw    $a1, 0x2c($s0)
/* 0634EC 7F02E9BC 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 0634F0 7F02E9C0 44812000 */  mtc1  $at, $f4
/* 0634F4 7F02E9C4 C4B0001C */  lwc1  $f16, 0x1c($a1)
/* 0634F8 7F02E9C8 C4B20018 */  lwc1  $f18, 0x18($a1)
/* 0634FC 7F02E9CC 46128001 */  sub.s $f0, $f16, $f18
/* 063500 7F02E9D0 4604003C */  c.lt.s $f0, $f4
/* 063504 7F02E9D4 00000000 */  nop   
/* 063508 7F02E9D8 4502001C */  bc1fl .L7F02EA4C
/* 06350C 7F02E9DC 4405C000 */   mfc1  $a1, $f24
/* 063510 7F02E9E0 4600018D */  trunc.w.s $f6, $f0
/* 063514 7F02E9E4 8E080040 */  lw    $t0, 0x40($s0)
/* 063518 7F02E9E8 240C003C */  li    $t4, 60
/* 06351C 7F02E9EC 02602025 */  move  $a0, $s3
/* 063520 7F02E9F0 440A3000 */  mfc1  $t2, $f6
/* 063524 7F02E9F4 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 063528 7F02E9F8 000A5840 */  sll   $t3, $t2, 1
/* 06352C 7F02E9FC 018B6823 */  subu  $t5, $t4, $t3
/* 063530 7F02EA00 010D082A */  slt   $at, $t0, $t5
/* 063534 7F02EA04 54200008 */  bnezl $at, .L7F02EA28
/* 063538 7F02EA08 4406B000 */   mfc1  $a2, $f22
/* 06353C 7F02EA0C 4405C000 */  mfc1  $a1, $f24
/* 063540 7F02EA10 4406B000 */  mfc1  $a2, $f22
/* 063544 7F02EA14 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 063548 7F02EA18 02602025 */   move  $a0, $s3
/* 06354C 7F02EA1C 1000006A */  b     .L7F02EBC8
/* 063550 7F02EA20 26310001 */   addiu $s1, $s1, 1
/* 063554 7F02EA24 4406B000 */  mfc1  $a2, $f22
.L7F02EA28:
/* 063558 7F02EA28 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 06355C 7F02EA2C 34A5CCCD */   ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 063560 7F02EA30 3C0E8005 */  lui   $t6, %hi(g_ClockTimer) 
/* 063564 7F02EA34 8DCE8374 */  lw    $t6, %lo(g_ClockTimer)($t6)
/* 063568 7F02EA38 8E0F0040 */  lw    $t7, 0x40($s0)
/* 06356C 7F02EA3C 01EEC021 */  addu  $t8, $t7, $t6
/* 063570 7F02EA40 10000060 */  b     .L7F02EBC4
/* 063574 7F02EA44 AE180040 */   sw    $t8, 0x40($s0)
/* 063578 7F02EA48 4405C000 */  mfc1  $a1, $f24
.L7F02EA4C:
/* 06357C 7F02EA4C 4406B000 */  mfc1  $a2, $f22
/* 063580 7F02EA50 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 063584 7F02EA54 02602025 */   move  $a0, $s3
/* 063588 7F02EA58 1000005B */  b     .L7F02EBC8
/* 06358C 7F02EA5C 26310001 */   addiu $s1, $s1, 1
.L7F02EA60:
/* 063590 7F02EA60 4405C000 */  mfc1  $a1, $f24
/* 063594 7F02EA64 4406B000 */  mfc1  $a2, $f22
/* 063598 7F02EA68 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 06359C 7F02EA6C 02602025 */   move  $a0, $s3
/* 0635A0 7F02EA70 10000055 */  b     .L7F02EBC8
/* 0635A4 7F02EA74 26310001 */   addiu $s1, $s1, 1
.L7F02EA78:
/* 0635A8 7F02EA78 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 0635AC 7F02EA7C 02202825 */   move  $a1, $s1
/* 0635B0 7F02EA80 82190007 */  lb    $t9, 7($s0)
/* 0635B4 7F02EA84 2401000A */  li    $at, 10
/* 0635B8 7F02EA88 02002025 */  move  $a0, $s0
/* 0635BC 7F02EA8C 1721000C */  bne   $t9, $at, .L7F02EAC0
/* 0635C0 7F02EA90 3C063F4C */   lui   $a2, 0x3f4c
/* 0635C4 7F02EA94 4405C000 */  mfc1  $a1, $f24
/* 0635C8 7F02EA98 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 0635CC 7F02EA9C 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0635D0 7F02EAA0 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 0635D4 7F02EAA4 02002025 */   move  $a0, $s0
/* 0635D8 7F02EAA8 44050000 */  mfc1  $a1, $f0
/* 0635DC 7F02EAAC 4406B000 */  mfc1  $a2, $f22
/* 0635E0 7F02EAB0 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 0635E4 7F02EAB4 02602025 */   move  $a0, $s3
/* 0635E8 7F02EAB8 10000043 */  b     .L7F02EBC8
/* 0635EC 7F02EABC 26310001 */   addiu $s1, $s1, 1
.L7F02EAC0:
/* 0635F0 7F02EAC0 4405C000 */  mfc1  $a1, $f24
/* 0635F4 7F02EAC4 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 0635F8 7F02EAC8 34C6CCCD */   ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0635FC 7F02EACC 44050000 */  mfc1  $a1, $f0
/* 063600 7F02EAD0 4406B000 */  mfc1  $a2, $f22
/* 063604 7F02EAD4 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 063608 7F02EAD8 02602025 */   move  $a0, $s3
/* 06360C 7F02EADC 1000003A */  b     .L7F02EBC8
/* 063610 7F02EAE0 26310001 */   addiu $s1, $s1, 1
/* 063614 7F02EAE4 82090031 */  lb    $t1, 0x31($s0)
.L7F02EAE8:
/* 063618 7F02EAE8 02002025 */  move  $a0, $s0
/* 06361C 7F02EAEC 00003025 */  move  $a2, $zero
/* 063620 7F02EAF0 1520002E */  bnez  $t1, .L7F02EBAC
/* 063624 7F02EAF4 00000000 */   nop   
/* 063628 7F02EAF8 82020032 */  lb    $v0, 0x32($s0)
/* 06362C 7F02EAFC 12220004 */  beq   $s1, $v0, .L7F02EB10
/* 063630 7F02EB00 02025021 */   addu  $t2, $s0, $v0
/* 063634 7F02EB04 814C003A */  lb    $t4, 0x3a($t2)
/* 063638 7F02EB08 15800028 */  bnez  $t4, .L7F02EBAC
/* 06363C 7F02EB0C 00000000 */   nop   
.L7F02EB10:
/* 063640 7F02EB10 8E05002C */  lw    $a1, 0x2c($s0)
/* 063644 7F02EB14 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 063648 7F02EB18 4600B03E */  c.le.s $f22, $f0
/* 06364C 7F02EB1C 00000000 */  nop   
/* 063650 7F02EB20 4502000B */  bc1fl .L7F02EB50
/* 063654 7F02EB24 4616003C */   c.lt.s $f0, $f22
/* 063658 7F02EB28 4614003E */  c.le.s $f0, $f20
/* 06365C 7F02EB2C 00000000 */  nop   
/* 063660 7F02EB30 45020007 */  bc1fl .L7F02EB50
/* 063664 7F02EB34 4616003C */   c.lt.s $f0, $f22
/* 063668 7F02EB38 C4A80024 */  lwc1  $f8, 0x24($a1)
/* 06366C 7F02EB3C 4608A03E */  c.le.s $f20, $f8
/* 063670 7F02EB40 00000000 */  nop   
/* 063674 7F02EB44 4503000B */  bc1tl .L7F02EB74
/* 063678 7F02EB48 82080033 */   lb    $t0, 0x33($s0)
/* 06367C 7F02EB4C 4616003C */  c.lt.s $f0, $f22
.L7F02EB50:
/* 063680 7F02EB50 00000000 */  nop   
/* 063684 7F02EB54 45000015 */  bc1f  .L7F02EBAC
/* 063688 7F02EB58 00000000 */   nop   
/* 06368C 7F02EB5C C4AA0018 */  lwc1  $f10, 0x18($a1)
/* 063690 7F02EB60 4614503E */  c.le.s $f10, $f20
/* 063694 7F02EB64 00000000 */  nop   
/* 063698 7F02EB68 45000010 */  bc1f  .L7F02EBAC
/* 06369C 7F02EB6C 00000000 */   nop   
/* 0636A0 7F02EB70 82080033 */  lb    $t0, 0x33($s0)
.L7F02EB74:
/* 0636A4 7F02EB74 24060001 */  li    $a2, 1
/* 0636A8 7F02EB78 00C25823 */  subu  $t3, $a2, $v0
/* 0636AC 7F02EB7C 250D0001 */  addiu $t5, $t0, 1
/* 0636B0 7F02EB80 A2060031 */  sb    $a2, 0x31($s0)
/* 0636B4 7F02EB84 A20B0032 */  sb    $t3, 0x32($s0)
/* 0636B8 7F02EB88 A20D0033 */  sb    $t5, 0x33($s0)
/* 0636BC 7F02EB8C 3C0F8005 */  lui   $t7, %hi(g_GlobalTimer) 
/* 0636C0 7F02EB90 8DEF837C */  lw    $t7, %lo(g_GlobalTimer)($t7)
/* 0636C4 7F02EB94 02002025 */  move  $a0, $s0
/* 0636C8 7F02EB98 02202825 */  move  $a1, $s1
/* 0636CC 7F02EB9C 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 0636D0 7F02EBA0 AE0F0044 */   sw    $t7, 0x44($s0)
/* 0636D4 7F02EBA4 10000008 */  b     .L7F02EBC8
/* 0636D8 7F02EBA8 26310001 */   addiu $s1, $s1, 1
.L7F02EBAC:
/* 0636DC 7F02EBAC 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 0636E0 7F02EBB0 02202825 */   move  $a1, $s1
/* 0636E4 7F02EBB4 10000004 */  b     .L7F02EBC8
/* 0636E8 7F02EBB8 26310001 */   addiu $s1, $s1, 1
.L7F02EBBC:
/* 0636EC 7F02EBBC 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 0636F0 7F02EBC0 00003025 */   move  $a2, $zero
.L7F02EBC4:
/* 0636F4 7F02EBC4 26310001 */  addiu $s1, $s1, 1
.L7F02EBC8:
/* 0636F8 7F02EBC8 24010002 */  li    $at, 2
/* 0636FC 7F02EBCC 1621FF5B */  bne   $s1, $at, .L7F02E93C
/* 063700 7F02EBD0 26520001 */   addiu $s2, $s2, 1
/* 063704 7F02EBD4 8FBF0044 */  lw    $ra, 0x44($sp)
.L7F02EBD8:
/* 063708 7F02EBD8 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 06370C 7F02EBDC D7B60020 */  ldc1  $f22, 0x20($sp)
/* 063710 7F02EBE0 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 063714 7F02EBE4 8FB00034 */  lw    $s0, 0x34($sp)
/* 063718 7F02EBE8 8FB10038 */  lw    $s1, 0x38($sp)
/* 06371C 7F02EBEC 8FB2003C */  lw    $s2, 0x3c($sp)
/* 063720 7F02EBF0 8FB30040 */  lw    $s3, 0x40($sp)
/* 063724 7F02EBF4 03E00008 */  jr    $ra
/* 063728 7F02EBF8 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80051FC8
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02E4C0
/* 060EE4 7F02E4F4 27BDFF90 */  addiu $sp, $sp, -0x70
/* 060EE8 7F02E4F8 AFBF0044 */  sw    $ra, 0x44($sp)
/* 060EEC 7F02E4FC AFB30040 */  sw    $s3, 0x40($sp)
/* 060EF0 7F02E500 AFB2003C */  sw    $s2, 0x3c($sp)
/* 060EF4 7F02E504 AFB10038 */  sw    $s1, 0x38($sp)
/* 060EF8 7F02E508 AFB00034 */  sw    $s0, 0x34($sp)
/* 060EFC 7F02E50C F7B80028 */  sdc1  $f24, 0x28($sp)
/* 060F00 7F02E510 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 060F04 7F02E514 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 060F08 7F02E518 8C93001C */  lw    $s3, 0x1c($a0)
/* 060F0C 7F02E51C 00808025 */  move  $s0, $a0
/* 060F10 7F02E520 0FC1BDD7 */  jal   objecthandlerGetModelField28
/* 060F14 7F02E524 02602025 */   move  $a0, $s3
/* 060F18 7F02E528 8E0F0044 */  lw    $t7, 0x44($s0)
/* 060F1C 7F02E52C 8E0E0048 */  lw    $t6, 0x48($s0)
/* 060F20 7F02E530 46000506 */  mov.s $f20, $f0
/* 060F24 7F02E534 25F8FFE7 */  addiu $t8, $t7, -0x19
/* 060F28 7F02E538 01D8082A */  slt   $at, $t6, $t8
/* 060F2C 7F02E53C 5020004B */  beql  $at, $zero, .L7F02E66C
/* 060F30 7F02E540 3C013F00 */   lui   $at, 0x3f00
/* 060F34 7F02E544 8E790054 */  lw    $t9, 0x54($s3)
/* 060F38 7F02E548 57200048 */  bnezl $t9, .L7F02E66C
/* 060F3C 7F02E54C 3C013F00 */   lui   $at, 0x3f00
/* 060F40 7F02E550 8E05002C */  lw    $a1, 0x2c($s0)
/* 060F44 7F02E554 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 060F48 7F02E558 44813000 */  mtc1  $at, $f6
/* 060F4C 7F02E55C C4A40018 */  lwc1  $f4, 0x18($a1)
/* 060F50 7F02E560 46062200 */  add.s $f8, $f4, $f6
/* 060F54 7F02E564 4600403C */  c.lt.s $f8, $f0
/* 060F58 7F02E568 00000000 */  nop   
/* 060F5C 7F02E56C 4502003F */  bc1fl .L7F02E66C
/* 060F60 7F02E570 3C013F00 */   lui   $at, 0x3f00
/* 060F64 7F02E574 C4AA001C */  lwc1  $f10, 0x1c($a1)
/* 060F68 7F02E578 460A003C */  c.lt.s $f0, $f10
/* 060F6C 7F02E57C 00000000 */  nop   
/* 060F70 7F02E580 4502003A */  bc1fl .L7F02E66C
/* 060F74 7F02E584 3C013F00 */   lui   $at, 0x3f00
/* 060F78 7F02E588 4480B000 */  mtc1  $zero, $f22
/* 060F7C 7F02E58C C4A20024 */  lwc1  $f2, 0x24($a1)
/* 060F80 7F02E590 4616103C */  c.lt.s $f2, $f22
/* 060F84 7F02E594 00000000 */  nop   
/* 060F88 7F02E598 45030006 */  bc1tl .L7F02E5B4
/* 060F8C 7F02E59C 82080036 */   lb    $t0, 0x36($s0)
/* 060F90 7F02E5A0 4602003C */  c.lt.s $f0, $f2
/* 060F94 7F02E5A4 00000000 */  nop   
/* 060F98 7F02E5A8 45020030 */  bc1fl .L7F02E66C
/* 060F9C 7F02E5AC 3C013F00 */   li    $at, 0x3F000000 # 0.500000
/* 060FA0 7F02E5B0 82080036 */  lb    $t0, 0x36($s0)
.L7F02E5B4:
/* 060FA4 7F02E5B4 15000024 */  bnez  $t0, .L7F02E648
/* 060FA8 7F02E5B8 00000000 */   nop   
/* 060FAC 7F02E5BC 0FC0B8C5 */  jal   sub_GAME_7F02E2E0
/* 060FB0 7F02E5C0 02002025 */   move  $a0, $s0
/* 060FB4 7F02E5C4 1440001E */  bnez  $v0, .L7F02E640
/* 060FB8 7F02E5C8 00000000 */   nop   
/* 060FBC 7F02E5CC 0FC1BDD3 */  jal   sub_GAME_7F06F5AC
/* 060FC0 7F02E5D0 02602025 */   move  $a0, $s3
/* 060FC4 7F02E5D4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 060FC8 7F02E5D8 4481C000 */  mtc1  $at, $f24
/* 060FCC 7F02E5DC 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 060FD0 7F02E5E0 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 060FD4 7F02E5E4 4405C000 */  mfc1  $a1, $f24
/* 060FD8 7F02E5E8 00408825 */  move  $s1, $v0
/* 060FDC 7F02E5EC 0FC08ED1 */  jal   chrlvGetGuard007SpeedRating
/* 060FE0 7F02E5F0 02002025 */   move  $a0, $s0
/* 060FE4 7F02E5F4 8E09002C */  lw    $t1, 0x2c($s0)
/* 060FE8 7F02E5F8 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 060FEC 7F02E5FC 44818000 */  mtc1  $at, $f16
/* 060FF0 7F02E600 82660024 */  lb    $a2, 0x24($s3)
/* 060FF4 7F02E604 8D27001C */  lw    $a3, 0x1c($t1)
/* 060FF8 7F02E608 E7A00010 */  swc1  $f0, 0x10($sp)
/* 060FFC 7F02E60C 02602025 */  move  $a0, $s3
/* 061000 7F02E610 02202825 */  move  $a1, $s1
/* 061004 7F02E614 0FC1BF92 */  jal   objecthandlerAnimationRelated7F06FCA8
/* 061008 7F02E618 E7B00014 */   swc1  $f16, 0x14($sp)
/* 06100C 7F02E61C 8E0A002C */  lw    $t2, 0x2c($s0)
/* 061010 7F02E620 C5400014 */  lwc1  $f0, 0x14($t2)
/* 061014 7F02E624 4600B03E */  c.le.s $f22, $f0
/* 061018 7F02E628 00000000 */  nop   
/* 06101C 7F02E62C 45000004 */  bc1f  .L7F02E640
/* 061020 7F02E630 00000000 */   nop   
/* 061024 7F02E634 44050000 */  mfc1  $a1, $f0
/* 061028 7F02E638 0FC1BFE2 */  jal   sub_GAME_7F06FDE8
/* 06102C 7F02E63C 02602025 */   move  $a0, $s3
.L7F02E640:
/* 061030 7F02E640 10000004 */  b     .L7F02E654
/* 061034 7F02E644 820B0034 */   lb    $t3, 0x34($s0)
.L7F02E648:
/* 061038 7F02E648 0FC0B8FB */  jal   sub_GAME_7F02E3B8
/* 06103C 7F02E64C 02002025 */   move  $a0, $s0
/* 061040 7F02E650 820B0034 */  lb    $t3, 0x34($s0)
.L7F02E654:
/* 061044 7F02E654 02602025 */  move  $a0, $s3
/* 061048 7F02E658 256C0001 */  addiu $t4, $t3, 1
/* 06104C 7F02E65C 0FC1BDD7 */  jal   objecthandlerGetModelField28
/* 061050 7F02E660 A20C0033 */   sb    $t4, 0x33($s0)
/* 061054 7F02E664 46000506 */  mov.s $f20, $f0
/* 061058 7F02E668 3C013F00 */  li    $at, 0x3F000000 # 0.500000
.L7F02E66C:
/* 06105C 7F02E66C 4481C000 */  mtc1  $at, $f24
/* 061060 7F02E670 4480B000 */  mtc1  $zero, $f22
/* 061064 7F02E674 0FC1BDD9 */  jal   sub_GAME_7F06F5C4
/* 061068 7F02E678 02602025 */   move  $a0, $s3
/* 06106C 7F02E67C 4614003E */  c.le.s $f0, $f20
/* 061070 7F02E680 00000000 */  nop   
/* 061074 7F02E684 45020076 */  bc1fl .L7F02E860
/* 061078 7F02E688 8E02004C */   lw    $v0, 0x4c($s0)
/* 06107C 7F02E68C 820D0037 */  lb    $t5, 0x37($s0)
/* 061080 7F02E690 15A00006 */  bnez  $t5, .L7F02E6AC
/* 061084 7F02E694 00000000 */   nop   
/* 061088 7F02E698 82030034 */  lb    $v1, 0x34($s0)
/* 06108C 7F02E69C 82020033 */  lb    $v0, 0x33($s0)
/* 061090 7F02E6A0 0062082A */  slt   $at, $v1, $v0
/* 061094 7F02E6A4 1020000F */  beqz  $at, .L7F02E6E4
/* 061098 7F02E6A8 00000000 */   nop   
.L7F02E6AC:
/* 06109C 7F02E6AC 0FC0B8C5 */  jal   sub_GAME_7F02E2E0
/* 0610A0 7F02E6B0 02002025 */   move  $a0, $s0
/* 0610A4 7F02E6B4 14400066 */  bnez  $v0, .L7F02E850
/* 0610A8 7F02E6B8 00000000 */   nop   
/* 0610AC 7F02E6BC 8E0F004C */  lw    $t7, 0x4c($s0)
/* 0610B0 7F02E6C0 31EE0001 */  andi  $t6, $t7, 1
/* 0610B4 7F02E6C4 11C00003 */  beqz  $t6, .L7F02E6D4
/* 0610B8 7F02E6C8 00000000 */   nop   
/* 0610BC 7F02E6CC 0FC0A6F9 */  jal   chrlvSetTargetToPlayer
/* 0610C0 7F02E6D0 02002025 */   move  $a0, $s0
.L7F02E6D4:
/* 0610C4 7F02E6D4 0FC08F8C */  jal   chrlvKneelingAnimationRelated7F023E48
/* 0610C8 7F02E6D8 02002025 */   move  $a0, $s0
/* 0610CC 7F02E6DC 10000151 */  b     .L7F02EC24
/* 0610D0 7F02E6E0 8FBF0044 */   lw    $ra, 0x44($sp)
.L7F02E6E4:
/* 0610D4 7F02E6E4 14620006 */  bne   $v1, $v0, .L7F02E700
/* 0610D8 7F02E6E8 24580001 */   addiu $t8, $v0, 1
/* 0610DC 7F02E6EC A2180033 */  sb    $t8, 0x33($s0)
/* 0610E0 7F02E6F0 0FC0B8FB */  jal   sub_GAME_7F02E3B8
/* 0610E4 7F02E6F4 02002025 */   move  $a0, $s0
/* 0610E8 7F02E6F8 10000055 */  b     .L7F02E850
/* 0610EC 7F02E6FC 00000000 */   nop   
.L7F02E700:
/* 0610F0 7F02E700 82190031 */  lb    $t9, 0x31($s0)
/* 0610F4 7F02E704 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 0610F8 7F02E708 02602025 */  move  $a0, $s3
/* 0610FC 7F02E70C 13200050 */  beqz  $t9, .L7F02E850
/* 061100 7F02E710 00000000 */   nop   
/* 061104 7F02E714 82080036 */  lb    $t0, 0x36($s0)
/* 061108 7F02E718 4600C306 */  mov.s $f12, $f24
/* 06110C 7F02E71C 51000014 */  beql  $t0, $zero, .L7F02E770
/* 061110 7F02E720 8E05002C */   lw    $a1, 0x2c($s0)
/* 061114 7F02E724 8E05002C */  lw    $a1, 0x2c($s0)
/* 061118 7F02E728 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 06111C 7F02E72C 4600B03C */  c.lt.s $f22, $f0
/* 061120 7F02E730 00000000 */  nop   
/* 061124 7F02E734 45020004 */  bc1fl .L7F02E748
/* 061128 7F02E738 C4AE0018 */   lwc1  $f14, 0x18($a1)
/* 06112C 7F02E73C 10000002 */  b     .L7F02E748
/* 061130 7F02E740 46000386 */   mov.s $f14, $f0
/* 061134 7F02E744 C4AE0018 */  lwc1  $f14, 0x18($a1)
.L7F02E748:
/* 061138 7F02E748 C4A20024 */  lwc1  $f2, 0x24($a1)
/* 06113C 7F02E74C 4602B03C */  c.lt.s $f22, $f2
/* 061140 7F02E750 00000000 */  nop   
/* 061144 7F02E754 45000003 */  bc1f  .L7F02E764
/* 061148 7F02E758 00000000 */   nop   
/* 06114C 7F02E75C 1000000D */  b     .L7F02E794
/* 061150 7F02E760 46001506 */   mov.s $f20, $f2
.L7F02E764:
/* 061154 7F02E764 1000000B */  b     .L7F02E794
/* 061158 7F02E768 C4B4001C */   lwc1  $f20, 0x1c($a1)
/* 06115C 7F02E76C 8E05002C */  lw    $a1, 0x2c($s0)
.L7F02E770:
/* 061160 7F02E770 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 061164 7F02E774 C4AE0018 */  lwc1  $f14, 0x18($a1)
/* 061168 7F02E778 4600B03C */  c.lt.s $f22, $f0
/* 06116C 7F02E77C 00000000 */  nop   
/* 061170 7F02E780 45020004 */  bc1fl .L7F02E794
/* 061174 7F02E784 C4B4001C */   lwc1  $f20, 0x1c($a1)
/* 061178 7F02E788 10000002 */  b     .L7F02E794
/* 06117C 7F02E78C 46000506 */   mov.s $f20, $f0
/* 061180 7F02E790 C4B4001C */  lwc1  $f20, 0x1c($a1)
.L7F02E794:
/* 061184 7F02E794 460EA001 */  sub.s $f0, $f20, $f14
/* 061188 7F02E798 44811000 */  mtc1  $at, $f2
/* 06118C 7F02E79C 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 061190 7F02E7A0 4602003C */  c.lt.s $f0, $f2
/* 061194 7F02E7A4 00000000 */  nop   
/* 061198 7F02E7A8 45020005 */  bc1fl .L7F02E7C0
/* 06119C 7F02E7AC 44812000 */   mtc1  $at, $f4
/* 0611A0 7F02E7B0 46180482 */  mul.s $f18, $f0, $f24
/* 0611A4 7F02E7B4 1000000D */  b     .L7F02E7EC
/* 0611A8 7F02E7B8 46029303 */   div.s $f12, $f18, $f2
/* 0611AC 7F02E7BC 44812000 */  mtc1  $at, $f4
.L7F02E7C0:
/* 0611B0 7F02E7C0 00000000 */  nop   
/* 0611B4 7F02E7C4 4600203C */  c.lt.s $f4, $f0
/* 0611B8 7F02E7C8 00000000 */  nop   
/* 0611BC 7F02E7CC 45020008 */  bc1fl .L7F02E7F0
/* 0611C0 7F02E7D0 8209003A */   lb    $t1, 0x3a($s0)
/* 0611C4 7F02E7D4 46180182 */  mul.s $f6, $f0, $f24
/* 0611C8 7F02E7D8 3C013D80 */  li    $at, 0x3D800000 # 0.062500
/* 0611CC 7F02E7DC 44814000 */  mtc1  $at, $f8
/* 0611D0 7F02E7E0 00000000 */  nop   
/* 0611D4 7F02E7E4 46083302 */  mul.s $f12, $f6, $f8
/* 0611D8 7F02E7E8 00000000 */  nop   
.L7F02E7EC:
/* 0611DC 7F02E7EC 8209003A */  lb    $t1, 0x3a($s0)
.L7F02E7F0:
/* 0611E0 7F02E7F0 51200006 */  beql  $t1, $zero, .L7F02E80C
/* 0611E4 7F02E7F4 A2000031 */   sb    $zero, 0x31($s0)
/* 0611E8 7F02E7F8 820A003B */  lb    $t2, 0x3b($s0)
/* 0611EC 7F02E7FC 51400003 */  beql  $t2, $zero, .L7F02E80C
/* 0611F0 7F02E800 A2000031 */   sb    $zero, 0x31($s0)
/* 0611F4 7F02E804 460C6300 */  add.s $f12, $f12, $f12
/* 0611F8 7F02E808 A2000031 */  sb    $zero, 0x31($s0)
.L7F02E80C:
/* 0611FC 7F02E80C E7AE005C */  swc1  $f14, 0x5c($sp)
/* 061200 7F02E810 0FC1BDD3 */  jal   sub_GAME_7F06F5AC
/* 061204 7F02E814 E7AC0060 */   swc1  $f12, 0x60($sp)
/* 061208 7F02E818 C7AE005C */  lwc1  $f14, 0x5c($sp)
/* 06120C 7F02E81C 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 061210 7F02E820 44815000 */  mtc1  $at, $f10
/* 061214 7F02E824 C7AC0060 */  lwc1  $f12, 0x60($sp)
/* 061218 7F02E828 82660024 */  lb    $a2, 0x24($s3)
/* 06121C 7F02E82C 44077000 */  mfc1  $a3, $f14
/* 061220 7F02E830 02602025 */  move  $a0, $s3
/* 061224 7F02E834 00402825 */  move  $a1, $v0
/* 061228 7F02E838 E7AA0014 */  swc1  $f10, 0x14($sp)
/* 06122C 7F02E83C 0FC1BF92 */  jal   objecthandlerAnimationRelated7F06FCA8
/* 061230 7F02E840 E7AC0010 */   swc1  $f12, 0x10($sp)
/* 061234 7F02E844 4405A000 */  mfc1  $a1, $f20
/* 061238 7F02E848 0FC1BFE2 */  jal   sub_GAME_7F06FDE8
/* 06123C 7F02E84C 02602025 */   move  $a0, $s3
.L7F02E850:
/* 061240 7F02E850 0FC1BDD7 */  jal   objecthandlerGetModelField28
/* 061244 7F02E854 02602025 */   move  $a0, $s3
/* 061248 7F02E858 46000506 */  mov.s $f20, $f0
/* 06124C 7F02E85C 8E02004C */  lw    $v0, 0x4c($s0)
.L7F02E860:
/* 061250 7F02E860 304B0040 */  andi  $t3, $v0, 0x40
/* 061254 7F02E864 5560002B */  bnezl $t3, .L7F02E914
/* 061258 7F02E868 8E05002C */   lw    $a1, 0x2c($s0)
/* 06125C 7F02E86C 8E05002C */  lw    $a1, 0x2c($s0)
/* 061260 7F02E870 304C0020 */  andi  $t4, $v0, 0x20
/* 061264 7F02E874 02602025 */  move  $a0, $s3
/* 061268 7F02E878 C4A2000C */  lwc1  $f2, 0xc($a1)
/* 06126C 7F02E87C 1180000F */  beqz  $t4, .L7F02E8BC
/* 061270 7F02E880 C4AC0004 */   lwc1  $f12, 4($a1)
/* 061274 7F02E884 E7A20050 */  swc1  $f2, 0x50($sp)
/* 061278 7F02E888 0FC1BDD9 */  jal   sub_GAME_7F06F5C4
/* 06127C 7F02E88C E7AC004C */   swc1  $f12, 0x4c($sp)
/* 061280 7F02E890 C7AC004C */  lwc1  $f12, 0x4c($sp)
/* 061284 7F02E894 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 061288 7F02E898 02602025 */  move  $a0, $s3
/* 06128C 7F02E89C 460C003C */  c.lt.s $f0, $f12
/* 061290 7F02E8A0 00000000 */  nop   
/* 061294 7F02E8A4 45020006 */  bc1fl .L7F02E8C0
/* 061298 7F02E8A8 826D0024 */   lb    $t5, 0x24($s3)
/* 06129C 7F02E8AC 0FC1BDD9 */  jal   sub_GAME_7F06F5C4
/* 0612A0 7F02E8B0 E7A20050 */   swc1  $f2, 0x50($sp)
/* 0612A4 7F02E8B4 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0612A8 7F02E8B8 46000306 */  mov.s $f12, $f0
.L7F02E8BC:
/* 0612AC 7F02E8BC 826D0024 */  lb    $t5, 0x24($s3)
.L7F02E8C0:
/* 0612B0 7F02E8C0 02002025 */  move  $a0, $s0
/* 0612B4 7F02E8C4 3C053F80 */  lui   $a1, 0x3f80
/* 0612B8 7F02E8C8 11A00004 */  beqz  $t5, .L7F02E8DC
/* 0612BC 7F02E8CC 3C063FCC */   lui   $a2, (0x3FCCCCCD >> 16) # lui $a2, 0x3fcc
/* 0612C0 7F02E8D0 3C018005 */  lui   $at, %hi(D_80051FC8) # $at, 0x8005
/* 0612C4 7F02E8D4 C4308100 */  lwc1  $f16, %lo(D_80051FC8)($at)
/* 0612C8 7F02E8D8 46028081 */  sub.s $f2, $f16, $f2
.L7F02E8DC:
/* 0612CC 7F02E8DC 34C6CCCD */  ori   $a2, (0x3FCCCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0612D0 7F02E8E0 E7A20050 */  swc1  $f2, 0x50($sp)
/* 0612D4 7F02E8E4 0FC08ED1 */  jal   chrlvGetGuard007SpeedRating
/* 0612D8 7F02E8E8 E7AC004C */   swc1  $f12, 0x4c($sp)
/* 0612DC 7F02E8EC C7AC004C */  lwc1  $f12, 0x4c($sp)
/* 0612E0 7F02E8F0 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 0612E4 7F02E8F4 82050030 */  lb    $a1, 0x30($s0)
/* 0612E8 7F02E8F8 44070000 */  mfc1  $a3, $f0
/* 0612EC 7F02E8FC 44066000 */  mfc1  $a2, $f12
/* 0612F0 7F02E900 02002025 */  move  $a0, $s0
/* 0612F4 7F02E904 0FC0B0B9 */  jal   sub_GAME_7F02C2B0
/* 0612F8 7F02E908 E7A20010 */   swc1  $f2, 0x10($sp)
/* 0612FC 7F02E90C A2020030 */  sb    $v0, 0x30($s0)
/* 061300 7F02E910 8E05002C */  lw    $a1, 0x2c($s0)
.L7F02E914:
/* 061304 7F02E914 C4B20028 */  lwc1  $f18, 0x28($a1)
/* 061308 7F02E918 4614903C */  c.lt.s $f18, $f20
/* 06130C 7F02E91C 00000000 */  nop   
/* 061310 7F02E920 4500000F */  bc1f  .L7F02E960
/* 061314 7F02E924 00000000 */   nop   
/* 061318 7F02E928 C4A4002C */  lwc1  $f4, 0x2c($a1)
/* 06131C 7F02E92C 02002025 */  move  $a0, $s0
/* 061320 7F02E930 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 061324 7F02E934 4604A03C */  c.lt.s $f20, $f4
/* 061328 7F02E938 00000000 */  nop   
/* 06132C 7F02E93C 45000008 */  bc1f  .L7F02E960
/* 061330 7F02E940 00000000 */   nop   
/* 061334 7F02E944 44813000 */  mtc1  $at, $f6
/* 061338 7F02E948 82060039 */  lb    $a2, 0x39($s0)
/* 06133C 7F02E94C 82070038 */  lb    $a3, 0x38($s0)
/* 061340 7F02E950 0FC0B13D */  jal   sub_GAME_7F02C4C0
/* 061344 7F02E954 E7A60010 */   swc1  $f6, 0x10($sp)
/* 061348 7F02E958 10000004 */  b     .L7F02E96C
/* 06134C 7F02E95C 00008825 */   move  $s1, $zero
.L7F02E960:
/* 061350 7F02E960 0FC0B44B */  jal   sub_GAME_7F02D0F8
/* 061354 7F02E964 02002025 */   move  $a0, $s0
/* 061358 7F02E968 00008825 */  move  $s1, $zero
.L7F02E96C:
/* 06135C 7F02E96C 02009025 */  move  $s2, $s0
.L7F02E970:
/* 061360 7F02E970 824F0038 */  lb    $t7, 0x38($s2)
/* 061364 7F02E974 02002025 */  move  $a0, $s0
/* 061368 7F02E978 02202825 */  move  $a1, $s1
/* 06136C 7F02E97C 11E000A2 */  beqz  $t7, .L7F02EC08
/* 061370 7F02E980 00000000 */   nop   
/* 061374 7F02E984 824E003A */  lb    $t6, 0x3a($s2)
/* 061378 7F02E988 55C0006A */  bnezl $t6, .L7F02EB34
/* 06137C 7F02E98C 82090031 */   lb    $t1, 0x31($s0)
/* 061380 7F02E990 8E05002C */  lw    $a1, 0x2c($s0)
/* 061384 7F02E994 02002025 */  move  $a0, $s0
/* 061388 7F02E998 00003025 */  move  $a2, $zero
/* 06138C 7F02E99C C4A80018 */  lwc1  $f8, 0x18($a1)
/* 061390 7F02E9A0 4614403E */  c.le.s $f8, $f20
/* 061394 7F02E9A4 00000000 */  nop   
/* 061398 7F02E9A8 45000046 */  bc1f  .L7F02EAC4
/* 06139C 7F02E9AC 00000000 */   nop   
/* 0613A0 7F02E9B0 C4AA001C */  lwc1  $f10, 0x1c($a1)
/* 0613A4 7F02E9B4 02202825 */  move  $a1, $s1
/* 0613A8 7F02E9B8 460AA03C */  c.lt.s $f20, $f10
/* 0613AC 7F02E9BC 00000000 */  nop   
/* 0613B0 7F02E9C0 45000040 */  bc1f  .L7F02EAC4
/* 0613B4 7F02E9C4 00000000 */   nop   
/* 0613B8 7F02E9C8 02002025 */  move  $a0, $s0
/* 0613BC 7F02E9CC 0FC0B47E */  jal   sub_GAME_7F02D1C4
/* 0613C0 7F02E9D0 24060001 */   li    $a2, 1
/* 0613C4 7F02E9D4 82190007 */  lb    $t9, 7($s0)
/* 0613C8 7F02E9D8 3C188004 */  lui   $t8, %hi(g_GlobalTimer) # $t8, 0x8004
/* 0613CC 7F02E9DC 8F180FFC */  lw    $t8, %lo(g_GlobalTimer)($t8)
/* 0613D0 7F02E9E0 2401000A */  li    $at, 10
/* 0613D4 7F02E9E4 17210031 */  bne   $t9, $at, .L7F02EAAC
/* 0613D8 7F02E9E8 AE180044 */   sw    $t8, 0x44($s0)
/* 0613DC 7F02E9EC 8E05002C */  lw    $a1, 0x2c($s0)
/* 0613E0 7F02E9F0 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 0613E4 7F02E9F4 44813000 */  mtc1  $at, $f6
/* 0613E8 7F02E9F8 C4B0001C */  lwc1  $f16, 0x1c($a1)
/* 0613EC 7F02E9FC C4B20018 */  lwc1  $f18, 0x18($a1)
/* 0613F0 7F02EA00 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0613F4 7F02EA04 44815000 */  mtc1  $at, $f10
/* 0613F8 7F02EA08 46128101 */  sub.s $f4, $f16, $f18
/* 0613FC 7F02EA0C 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 061400 7F02EA10 44818000 */  mtc1  $at, $f16
/* 061404 7F02EA14 46062202 */  mul.s $f8, $f4, $f6
/* 061408 7F02EA18 460A4003 */  div.s $f0, $f8, $f10
/* 06140C 7F02EA1C 4610003C */  c.lt.s $f0, $f16
/* 061410 7F02EA20 00000000 */  nop   
/* 061414 7F02EA24 4502001C */  bc1fl .L7F02EA98
/* 061418 7F02EA28 4405C000 */   mfc1  $a1, $f24
/* 06141C 7F02EA2C 4600048D */  trunc.w.s $f18, $f0
/* 061420 7F02EA30 8E080040 */  lw    $t0, 0x40($s0)
/* 061424 7F02EA34 240C0032 */  li    $t4, 50
/* 061428 7F02EA38 02602025 */  move  $a0, $s3
/* 06142C 7F02EA3C 440A9000 */  mfc1  $t2, $f18
/* 061430 7F02EA40 3C053DCC */  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
/* 061434 7F02EA44 000A5840 */  sll   $t3, $t2, 1
/* 061438 7F02EA48 018B6823 */  subu  $t5, $t4, $t3
/* 06143C 7F02EA4C 010D082A */  slt   $at, $t0, $t5
/* 061440 7F02EA50 54200008 */  bnezl $at, .L7F02EA74
/* 061444 7F02EA54 4406B000 */   mfc1  $a2, $f22
/* 061448 7F02EA58 4405C000 */  mfc1  $a1, $f24
/* 06144C 7F02EA5C 4406B000 */  mfc1  $a2, $f22
/* 061450 7F02EA60 0FC1BFFB */  jal   sub_GAME_7F06FE4C
/* 061454 7F02EA64 02602025 */   move  $a0, $s3
/* 061458 7F02EA68 1000006A */  b     .L7F02EC14
/* 06145C 7F02EA6C 26310001 */   addiu $s1, $s1, 1
/* 061460 7F02EA70 4406B000 */  mfc1  $a2, $f22
.L7F02EA74:
/* 061464 7F02EA74 0FC1BFFB */  jal   sub_GAME_7F06FE4C
/* 061468 7F02EA78 34A5CCCD */   ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 06146C 7F02EA7C 3C0E8004 */  lui   $t6, %hi(g_ClockTimer) # $t6, 0x8004
/* 061470 7F02EA80 8DCE0FF4 */  lw    $t6, %lo(g_ClockTimer)($t6)
/* 061474 7F02EA84 8E0F0040 */  lw    $t7, 0x40($s0)
/* 061478 7F02EA88 01EEC021 */  addu  $t8, $t7, $t6
/* 06147C 7F02EA8C 10000060 */  b     .L7F02EC10
/* 061480 7F02EA90 AE180040 */   sw    $t8, 0x40($s0)
/* 061484 7F02EA94 4405C000 */  mfc1  $a1, $f24
.L7F02EA98:
/* 061488 7F02EA98 4406B000 */  mfc1  $a2, $f22
/* 06148C 7F02EA9C 0FC1BFFB */  jal   sub_GAME_7F06FE4C
/* 061490 7F02EAA0 02602025 */   move  $a0, $s3
/* 061494 7F02EAA4 1000005B */  b     .L7F02EC14
/* 061498 7F02EAA8 26310001 */   addiu $s1, $s1, 1
.L7F02EAAC:
/* 06149C 7F02EAAC 4405C000 */  mfc1  $a1, $f24
/* 0614A0 7F02EAB0 4406B000 */  mfc1  $a2, $f22
/* 0614A4 7F02EAB4 0FC1BFFB */  jal   sub_GAME_7F06FE4C
/* 0614A8 7F02EAB8 02602025 */   move  $a0, $s3
/* 0614AC 7F02EABC 10000055 */  b     .L7F02EC14
/* 0614B0 7F02EAC0 26310001 */   addiu $s1, $s1, 1
.L7F02EAC4:
/* 0614B4 7F02EAC4 0FC0B47E */  jal   sub_GAME_7F02D1C4
/* 0614B8 7F02EAC8 02202825 */   move  $a1, $s1
/* 0614BC 7F02EACC 82190007 */  lb    $t9, 7($s0)
/* 0614C0 7F02EAD0 2401000A */  li    $at, 10
/* 0614C4 7F02EAD4 02002025 */  move  $a0, $s0
/* 0614C8 7F02EAD8 1721000C */  bne   $t9, $at, .L7F02EB0C
/* 0614CC 7F02EADC 3C063F4C */   lui   $a2, 0x3f4c
/* 0614D0 7F02EAE0 4405C000 */  mfc1  $a1, $f24
/* 0614D4 7F02EAE4 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 0614D8 7F02EAE8 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0614DC 7F02EAEC 0FC08ED1 */  jal   chrlvGetGuard007SpeedRating
/* 0614E0 7F02EAF0 02002025 */   move  $a0, $s0
/* 0614E4 7F02EAF4 44050000 */  mfc1  $a1, $f0
/* 0614E8 7F02EAF8 4406B000 */  mfc1  $a2, $f22
/* 0614EC 7F02EAFC 0FC1BFFB */  jal   sub_GAME_7F06FE4C
/* 0614F0 7F02EB00 02602025 */   move  $a0, $s3
/* 0614F4 7F02EB04 10000043 */  b     .L7F02EC14
/* 0614F8 7F02EB08 26310001 */   addiu $s1, $s1, 1
.L7F02EB0C:
/* 0614FC 7F02EB0C 4405C000 */  mfc1  $a1, $f24
/* 061500 7F02EB10 0FC08ED1 */  jal   chrlvGetGuard007SpeedRating
/* 061504 7F02EB14 34C6CCCD */   ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 061508 7F02EB18 44050000 */  mfc1  $a1, $f0
/* 06150C 7F02EB1C 4406B000 */  mfc1  $a2, $f22
/* 061510 7F02EB20 0FC1BFFB */  jal   sub_GAME_7F06FE4C
/* 061514 7F02EB24 02602025 */   move  $a0, $s3
/* 061518 7F02EB28 1000003A */  b     .L7F02EC14
/* 06151C 7F02EB2C 26310001 */   addiu $s1, $s1, 1
/* 061520 7F02EB30 82090031 */  lb    $t1, 0x31($s0)
.L7F02EB34:
/* 061524 7F02EB34 02002025 */  move  $a0, $s0
/* 061528 7F02EB38 00003025 */  move  $a2, $zero
/* 06152C 7F02EB3C 1520002E */  bnez  $t1, .L7F02EBF8
/* 061530 7F02EB40 00000000 */   nop   
/* 061534 7F02EB44 82020032 */  lb    $v0, 0x32($s0)
/* 061538 7F02EB48 12220004 */  beq   $s1, $v0, .L7F02EB5C
/* 06153C 7F02EB4C 02025021 */   addu  $t2, $s0, $v0
/* 061540 7F02EB50 814C003A */  lb    $t4, 0x3a($t2)
/* 061544 7F02EB54 15800028 */  bnez  $t4, .L7F02EBF8
/* 061548 7F02EB58 00000000 */   nop   
.L7F02EB5C:
/* 06154C 7F02EB5C 8E05002C */  lw    $a1, 0x2c($s0)
/* 061550 7F02EB60 C4A00020 */  lwc1  $f0, 0x20($a1)
/* 061554 7F02EB64 4600B03E */  c.le.s $f22, $f0
/* 061558 7F02EB68 00000000 */  nop   
/* 06155C 7F02EB6C 4502000B */  bc1fl .L7F02EB9C
/* 061560 7F02EB70 4616003C */   c.lt.s $f0, $f22
/* 061564 7F02EB74 4614003E */  c.le.s $f0, $f20
/* 061568 7F02EB78 00000000 */  nop   
/* 06156C 7F02EB7C 45020007 */  bc1fl .L7F02EB9C
/* 061570 7F02EB80 4616003C */   c.lt.s $f0, $f22
/* 061574 7F02EB84 C4A40024 */  lwc1  $f4, 0x24($a1)
/* 061578 7F02EB88 4604A03E */  c.le.s $f20, $f4
/* 06157C 7F02EB8C 00000000 */  nop   
/* 061580 7F02EB90 4503000B */  bc1tl .L7F02EBC0
/* 061584 7F02EB94 82080033 */   lb    $t0, 0x33($s0)
/* 061588 7F02EB98 4616003C */  c.lt.s $f0, $f22
.L7F02EB9C:
/* 06158C 7F02EB9C 00000000 */  nop   
/* 061590 7F02EBA0 45000015 */  bc1f  .L7F02EBF8
/* 061594 7F02EBA4 00000000 */   nop   
/* 061598 7F02EBA8 C4A60018 */  lwc1  $f6, 0x18($a1)
/* 06159C 7F02EBAC 4614303E */  c.le.s $f6, $f20
/* 0615A0 7F02EBB0 00000000 */  nop   
/* 0615A4 7F02EBB4 45000010 */  bc1f  .L7F02EBF8
/* 0615A8 7F02EBB8 00000000 */   nop   
/* 0615AC 7F02EBBC 82080033 */  lb    $t0, 0x33($s0)
.L7F02EBC0:
/* 0615B0 7F02EBC0 24060001 */  li    $a2, 1
/* 0615B4 7F02EBC4 00C25823 */  subu  $t3, $a2, $v0
/* 0615B8 7F02EBC8 250D0001 */  addiu $t5, $t0, 1
/* 0615BC 7F02EBCC A2060031 */  sb    $a2, 0x31($s0)
/* 0615C0 7F02EBD0 A20B0032 */  sb    $t3, 0x32($s0)
/* 0615C4 7F02EBD4 A20D0033 */  sb    $t5, 0x33($s0)
/* 0615C8 7F02EBD8 3C0F8004 */  lui   $t7, %hi(g_GlobalTimer) # $t7, 0x8004
/* 0615CC 7F02EBDC 8DEF0FFC */  lw    $t7, %lo(g_GlobalTimer)($t7)
/* 0615D0 7F02EBE0 02002025 */  move  $a0, $s0
/* 0615D4 7F02EBE4 02202825 */  move  $a1, $s1
/* 0615D8 7F02EBE8 0FC0B47E */  jal   sub_GAME_7F02D1C4
/* 0615DC 7F02EBEC AE0F0044 */   sw    $t7, 0x44($s0)
/* 0615E0 7F02EBF0 10000008 */  b     .L7F02EC14
/* 0615E4 7F02EBF4 26310001 */   addiu $s1, $s1, 1
.L7F02EBF8:
/* 0615E8 7F02EBF8 0FC0B47E */  jal   sub_GAME_7F02D1C4
/* 0615EC 7F02EBFC 02202825 */   move  $a1, $s1
/* 0615F0 7F02EC00 10000004 */  b     .L7F02EC14
/* 0615F4 7F02EC04 26310001 */   addiu $s1, $s1, 1
.L7F02EC08:
/* 0615F8 7F02EC08 0FC0B47E */  jal   sub_GAME_7F02D1C4
/* 0615FC 7F02EC0C 00003025 */   move  $a2, $zero
.L7F02EC10:
/* 061600 7F02EC10 26310001 */  addiu $s1, $s1, 1
.L7F02EC14:
/* 061604 7F02EC14 24010002 */  li    $at, 2
/* 061608 7F02EC18 1621FF55 */  bne   $s1, $at, .L7F02E970
/* 06160C 7F02EC1C 26520001 */   addiu $s2, $s2, 1
/* 061610 7F02EC20 8FBF0044 */  lw    $ra, 0x44($sp)
.L7F02EC24:
/* 061614 7F02EC24 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 061618 7F02EC28 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 06161C 7F02EC2C D7B80028 */  ldc1  $f24, 0x28($sp)
/* 061620 7F02EC30 8FB00034 */  lw    $s0, 0x34($sp)
/* 061624 7F02EC34 8FB10038 */  lw    $s1, 0x38($sp)
/* 061628 7F02EC38 8FB2003C */  lw    $s2, 0x3c($sp)
/* 06162C 7F02EC3C 8FB30040 */  lw    $s3, 0x40($sp)
/* 061630 7F02EC40 03E00008 */  jr    $ra
/* 061634 7F02EC44 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif
#endif


#ifdef NONMATCHING
void sub_GAME_7F02EBFC(void) {

}
#else

#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80051FCC
.word 0x3e4ccccd /*0.2*/
.text
glabel sub_GAME_7F02EBFC
/* 06372C 7F02EBFC 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 063730 7F02EC00 AFBF0024 */  sw    $ra, 0x24($sp)
/* 063734 7F02EC04 AFB10020 */  sw    $s1, 0x20($sp)
/* 063738 7F02EC08 AFB0001C */  sw    $s0, 0x1c($sp)
/* 06373C 7F02EC0C 8C91001C */  lw    $s1, 0x1c($a0)
/* 063740 7F02EC10 00808025 */  move  $s0, $a0
/* 063744 7F02EC14 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 063748 7F02EC18 02202025 */   move  $a0, $s1
/* 06374C 7F02EC1C 8E020058 */  lw    $v0, 0x58($s0)
/* 063750 7F02EC20 46000086 */  mov.s $f2, $f0
/* 063754 7F02EC24 24010001 */  li    $at, 1
/* 063758 7F02EC28 5040004E */  beql  $v0, $zero, .L7F02ED64
/* 06375C 7F02EC2C 8E02004C */   lw    $v0, 0x4c($s0)
/* 063760 7F02EC30 1441002D */  bne   $v0, $at, .L7F02ECE8
/* 063764 7F02EC34 02202025 */   move  $a0, $s1
/* 063768 7F02EC38 8E02002C */  lw    $v0, 0x2c($s0)
/* 06376C 7F02EC3C 44802000 */  mtc1  $zero, $f4
/* 063770 7F02EC40 C4400024 */  lwc1  $f0, 0x24($v0)
/* 063774 7F02EC44 4600203E */  c.le.s $f4, $f0
/* 063778 7F02EC48 00000000 */  nop   
/* 06377C 7F02EC4C 45020004 */  bc1fl .L7F02EC60
/* 063780 7F02EC50 C442001C */   lwc1  $f2, 0x1c($v0)
/* 063784 7F02EC54 10000002 */  b     .L7F02EC60
/* 063788 7F02EC58 46000086 */   mov.s $f2, $f0
/* 06378C 7F02EC5C C442001C */  lwc1  $f2, 0x1c($v0)
.L7F02EC60:
/* 063790 7F02EC60 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 063794 7F02EC64 E7A20034 */   swc1  $f2, 0x34($sp)
/* 063798 7F02EC68 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 06379C 7F02EC6C 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0637A0 7F02EC70 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0637A4 7F02EC74 02002025 */  move  $a0, $s0
/* 0637A8 7F02EC78 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 0637AC 7F02EC7C 3C053F00 */   lui   $a1, 0x3f00
/* 0637B0 7F02EC80 C7A20034 */  lwc1  $f2, 0x34($sp)
/* 0637B4 7F02EC84 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0637B8 7F02EC88 44813000 */  mtc1  $at, $f6
/* 0637BC 7F02EC8C 82260024 */  lb    $a2, 0x24($s1)
/* 0637C0 7F02EC90 44071000 */  mfc1  $a3, $f2
/* 0637C4 7F02EC94 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0637C8 7F02EC98 02202025 */  move  $a0, $s1
/* 0637CC 7F02EC9C 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0637D0 7F02ECA0 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 0637D4 7F02ECA4 E7A60014 */   swc1  $f6, 0x14($sp)
/* 0637D8 7F02ECA8 8E0E002C */  lw    $t6, 0x2c($s0)
/* 0637DC 7F02ECAC 44804000 */  mtc1  $zero, $f8
/* 0637E0 7F02ECB0 C5C00014 */  lwc1  $f0, 0x14($t6)
/* 0637E4 7F02ECB4 4600403E */  c.le.s $f8, $f0
/* 0637E8 7F02ECB8 00000000 */  nop   
/* 0637EC 7F02ECBC 45020005 */  bc1fl .L7F02ECD4
/* 0637F0 7F02ECC0 240F0002 */   li    $t7, 2
/* 0637F4 7F02ECC4 44050000 */  mfc1  $a1, $f0
/* 0637F8 7F02ECC8 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 0637FC 7F02ECCC 02202025 */   move  $a0, $s1
/* 063800 7F02ECD0 240F0002 */  li    $t7, 2
.L7F02ECD4:
/* 063804 7F02ECD4 AE0F0058 */  sw    $t7, 0x58($s0)
/* 063808 7F02ECD8 0FC0B43E */  jal   sub_GAME_7F02D0F8
/* 06380C 7F02ECDC 02002025 */   move  $a0, $s0
/* 063810 7F02ECE0 1000007B */  b     .L7F02EED0
/* 063814 7F02ECE4 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F02ECE8:
/* 063818 7F02ECE8 24010002 */  li    $at, 2
/* 06381C 7F02ECEC 1441001C */  bne   $v0, $at, .L7F02ED60
/* 063820 7F02ECF0 02202025 */   move  $a0, $s1
/* 063824 7F02ECF4 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 063828 7F02ECF8 E7A20038 */   swc1  $f2, 0x38($sp)
/* 06382C 7F02ECFC C7A20038 */  lwc1  $f2, 0x38($sp)
/* 063830 7F02ED00 4602003E */  c.le.s $f0, $f2
/* 063834 7F02ED04 00000000 */  nop   
/* 063838 7F02ED08 45020071 */  bc1fl .L7F02EED0
/* 06383C 7F02ED0C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 063840 7F02ED10 8E18004C */  lw    $t8, 0x4c($s0)
/* 063844 7F02ED14 8E0A0054 */  lw    $t2, 0x54($s0)
/* 063848 7F02ED18 2401FFBF */  li    $at, -65
/* 06384C 7F02ED1C 37190020 */  ori   $t9, $t8, 0x20
/* 063850 7F02ED20 AE19004C */  sw    $t9, 0x4c($s0)
/* 063854 7F02ED24 03214824 */  and   $t1, $t9, $at
/* 063858 7F02ED28 11400007 */  beqz  $t2, .L7F02ED48
/* 06385C 7F02ED2C AE09004C */   sw    $t1, 0x4c($s0)
/* 063860 7F02ED30 02002025 */  move  $a0, $s0
/* 063864 7F02ED34 01202825 */  move  $a1, $t1
/* 063868 7F02ED38 0FC09558 */  jal   sub_GAME_7F025560
/* 06386C 7F02ED3C 8E060050 */   lw    $a2, 0x50($s0)
/* 063870 7F02ED40 10000063 */  b     .L7F02EED0
/* 063874 7F02ED44 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F02ED48:
/* 063878 7F02ED48 02002025 */  move  $a0, $s0
/* 06387C 7F02ED4C 8E05004C */  lw    $a1, 0x4c($s0)
/* 063880 7F02ED50 0FC095BC */  jal   sub_GAME_7F0256F0
/* 063884 7F02ED54 8E060050 */   lw    $a2, 0x50($s0)
/* 063888 7F02ED58 1000005D */  b     .L7F02EED0
/* 06388C 7F02ED5C 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F02ED60:
/* 063890 7F02ED60 8E02004C */  lw    $v0, 0x4c($s0)
.L7F02ED64:
/* 063894 7F02ED64 304B0020 */  andi  $t3, $v0, 0x20
/* 063898 7F02ED68 1160001C */  beqz  $t3, .L7F02EDDC
/* 06389C 7F02ED6C 304C0040 */   andi  $t4, $v0, 0x40
/* 0638A0 7F02ED70 1180000D */  beqz  $t4, .L7F02EDA8
/* 0638A4 7F02ED74 02202025 */   move  $a0, $s1
/* 0638A8 7F02ED78 3C018005 */  lui   $at, %hi(D_80051FCC)
/* 0638AC 7F02ED7C C42A1FCC */  lwc1  $f10, %lo(D_80051FCC)($at)
/* 0638B0 7F02ED80 8E05002C */  lw    $a1, 0x2c($s0)
/* 0638B4 7F02ED84 82060039 */  lb    $a2, 0x39($s0)
/* 0638B8 7F02ED88 82070038 */  lb    $a3, 0x38($s0)
/* 0638BC 7F02ED8C 02002025 */  move  $a0, $s0
/* 0638C0 7F02ED90 0FC0B130 */  jal   sub_GAME_7F02C4C0
/* 0638C4 7F02ED94 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0638C8 7F02ED98 1440004C */  bnez  $v0, .L7F02EECC
/* 0638CC 7F02ED9C 240D0001 */   li    $t5, 1
/* 0638D0 7F02EDA0 1000004A */  b     .L7F02EECC
/* 0638D4 7F02EDA4 AE0D0058 */   sw    $t5, 0x58($s0)
.L7F02EDA8:
/* 0638D8 7F02EDA8 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 0638DC 7F02EDAC E7A20038 */   swc1  $f2, 0x38($sp)
/* 0638E0 7F02EDB0 C7A20038 */  lwc1  $f2, 0x38($sp)
/* 0638E4 7F02EDB4 4602003E */  c.le.s $f0, $f2
/* 0638E8 7F02EDB8 00000000 */  nop   
/* 0638EC 7F02EDBC 45020008 */  bc1fl .L7F02EDE0
/* 0638F0 7F02EDC0 82190036 */   lb    $t9, 0x36($s0)
/* 0638F4 7F02EDC4 8E0E004C */  lw    $t6, 0x4c($s0)
/* 0638F8 7F02EDC8 24180002 */  li    $t8, 2
/* 0638FC 7F02EDCC A2180030 */  sb    $t8, 0x30($s0)
/* 063900 7F02EDD0 35CF0040 */  ori   $t7, $t6, 0x40
/* 063904 7F02EDD4 1000003D */  b     .L7F02EECC
/* 063908 7F02EDD8 AE0F004C */   sw    $t7, 0x4c($s0)
.L7F02EDDC:
/* 06390C 7F02EDDC 82190036 */  lb    $t9, 0x36($s0)
.L7F02EDE0:
/* 063910 7F02EDE0 17200038 */  bnez  $t9, .L7F02EEC4
/* 063914 7F02EDE4 00000000 */   nop   
/* 063918 7F02EDE8 8E08002C */  lw    $t0, 0x2c($s0)
/* 06391C 7F02EDEC 44808000 */  mtc1  $zero, $f16
/* 063920 7F02EDF0 C5000024 */  lwc1  $f0, 0x24($t0)
/* 063924 7F02EDF4 4600803C */  c.lt.s $f16, $f0
/* 063928 7F02EDF8 00000000 */  nop   
/* 06392C 7F02EDFC 45000031 */  bc1f  .L7F02EEC4
/* 063930 7F02EE00 00000000 */   nop   
/* 063934 7F02EE04 4600103E */  c.le.s $f2, $f0
/* 063938 7F02EE08 02202025 */  move  $a0, $s1
/* 06393C 7F02EE0C 4500002D */  bc1f  .L7F02EEC4
/* 063940 7F02EE10 00000000 */   nop   
/* 063944 7F02EE14 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 063948 7F02EE18 E7A20038 */   swc1  $f2, 0x38($sp)
/* 06394C 7F02EE1C C7A20038 */  lwc1  $f2, 0x38($sp)
/* 063950 7F02EE20 4602003E */  c.le.s $f0, $f2
/* 063954 7F02EE24 00000000 */  nop   
/* 063958 7F02EE28 45000026 */  bc1f  .L7F02EEC4
/* 06395C 7F02EE2C 00000000 */   nop   
/* 063960 7F02EE30 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 063964 7F02EE34 02202025 */   move  $a0, $s1
/* 063968 7F02EE38 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 06396C 7F02EE3C 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 063970 7F02EE40 AFA2002C */  sw    $v0, 0x2c($sp)
/* 063974 7F02EE44 02002025 */  move  $a0, $s0
/* 063978 7F02EE48 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 06397C 7F02EE4C 3C053F00 */   lui   $a1, 0x3f00
/* 063980 7F02EE50 8E09002C */  lw    $t1, 0x2c($s0)
/* 063984 7F02EE54 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 063988 7F02EE58 44819000 */  mtc1  $at, $f18
/* 06398C 7F02EE5C 82260024 */  lb    $a2, 0x24($s1)
/* 063990 7F02EE60 8D270024 */  lw    $a3, 0x24($t1)
/* 063994 7F02EE64 E7A00010 */  swc1  $f0, 0x10($sp)
/* 063998 7F02EE68 02202025 */  move  $a0, $s1
/* 06399C 7F02EE6C 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0639A0 7F02EE70 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 0639A4 7F02EE74 E7B20014 */   swc1  $f18, 0x14($sp)
/* 0639A8 7F02EE78 820A0037 */  lb    $t2, 0x37($s0)
/* 0639AC 7F02EE7C 5140000E */  beql  $t2, $zero, .L7F02EEB8
/* 0639B0 7F02EE80 8E0C002C */   lw    $t4, 0x2c($s0)
/* 0639B4 7F02EE84 8E0B002C */  lw    $t3, 0x2c($s0)
/* 0639B8 7F02EE88 44802000 */  mtc1  $zero, $f4
/* 0639BC 7F02EE8C C5600014 */  lwc1  $f0, 0x14($t3)
/* 0639C0 7F02EE90 4600203E */  c.le.s $f4, $f0
/* 0639C4 7F02EE94 00000000 */  nop   
/* 0639C8 7F02EE98 4500000A */  bc1f  .L7F02EEC4
/* 0639CC 7F02EE9C 00000000 */   nop   
/* 0639D0 7F02EEA0 44050000 */  mfc1  $a1, $f0
/* 0639D4 7F02EEA4 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 0639D8 7F02EEA8 02202025 */   move  $a0, $s1
/* 0639DC 7F02EEAC 10000005 */  b     .L7F02EEC4
/* 0639E0 7F02EEB0 00000000 */   nop   
/* 0639E4 7F02EEB4 8E0C002C */  lw    $t4, 0x2c($s0)
.L7F02EEB8:
/* 0639E8 7F02EEB8 02202025 */  move  $a0, $s1
/* 0639EC 7F02EEBC 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 0639F0 7F02EEC0 8D85001C */   lw    $a1, 0x1c($t4)
.L7F02EEC4:
/* 0639F4 7F02EEC4 0FC0B930 */  jal   sub_GAME_7F02E4C0
/* 0639F8 7F02EEC8 02002025 */   move  $a0, $s0
.L7F02EECC:
/* 0639FC 7F02EECC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F02EED0:
/* 063A00 7F02EED0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 063A04 7F02EED4 8FB10020 */  lw    $s1, 0x20($sp)
/* 063A08 7F02EED8 03E00008 */  jr    $ra
/* 063A0C 7F02EEDC 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

#ifndef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80051FCC
.word 0x3e4ccccd /*0.2*/

.text
glabel sub_GAME_7F02EBFC
/* 063A74 7F02EF04 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 063A78 7F02EF08 AFBF0024 */  sw    $ra, 0x24($sp)
/* 063A7C 7F02EF0C AFB10020 */  sw    $s1, 0x20($sp)
/* 063A80 7F02EF10 AFB0001C */  sw    $s0, 0x1c($sp)
/* 063A84 7F02EF14 8C91001C */  lw    $s1, 0x1c($a0)
/* 063A88 7F02EF18 00808025 */  move  $s0, $a0
/* 063A8C 7F02EF1C 0FC1BEEB */  jal   objecthandlerGetModelField28
/* 063A90 7F02EF20 02202025 */   move  $a0, $s1
/* 063A94 7F02EF24 8E020058 */  lw    $v0, 0x58($s0)
/* 063A98 7F02EF28 46000086 */  mov.s $f2, $f0
/* 063A9C 7F02EF2C 24010001 */  li    $at, 1
/* 063AA0 7F02EF30 5040004C */  beql  $v0, $zero, .Ljp7F02F064
/* 063AA4 7F02EF34 8E02004C */   lw    $v0, 0x4c($s0)
/* 063AA8 7F02EF38 1441002D */  bne   $v0, $at, .Ljp7F02EFF0
/* 063AAC 7F02EF3C 02202025 */   move  $a0, $s1
/* 063AB0 7F02EF40 8E02002C */  lw    $v0, 0x2c($s0)
/* 063AB4 7F02EF44 44802000 */  mtc1  $zero, $f4
/* 063AB8 7F02EF48 C4400024 */  lwc1  $f0, 0x24($v0)
/* 063ABC 7F02EF4C 4600203E */  c.le.s $f4, $f0
/* 063AC0 7F02EF50 00000000 */  nop   
/* 063AC4 7F02EF54 45020004 */  bc1fl .Ljp7F02EF68
/* 063AC8 7F02EF58 C442001C */   lwc1  $f2, 0x1c($v0)
/* 063ACC 7F02EF5C 10000002 */  b     .Ljp7F02EF68
/* 063AD0 7F02EF60 46000086 */   mov.s $f2, $f0
/* 063AD4 7F02EF64 C442001C */  lwc1  $f2, 0x1c($v0)
.Ljp7F02EF68:
/* 063AD8 7F02EF68 0FC1BEE7 */  jal   sub_GAME_7F06F5AC
/* 063ADC 7F02EF6C E7A20034 */   swc1  $f2, 0x34($sp)
/* 063AE0 7F02EF70 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 063AE4 7F02EF74 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 063AE8 7F02EF78 AFA2002C */  sw    $v0, 0x2c($sp)
/* 063AEC 7F02EF7C 02002025 */  move  $a0, $s0
/* 063AF0 7F02EF80 0FC08F99 */  jal   chrlvGetGuard007SpeedRating
/* 063AF4 7F02EF84 3C053F00 */   lui   $a1, 0x3f00
/* 063AF8 7F02EF88 C7A20034 */  lwc1  $f2, 0x34($sp)
/* 063AFC 7F02EF8C 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 063B00 7F02EF90 44813000 */  mtc1  $at, $f6
/* 063B04 7F02EF94 82260024 */  lb    $a2, 0x24($s1)
/* 063B08 7F02EF98 44071000 */  mfc1  $a3, $f2
/* 063B0C 7F02EF9C E7A00010 */  swc1  $f0, 0x10($sp)
/* 063B10 7F02EFA0 02202025 */  move  $a0, $s1
/* 063B14 7F02EFA4 8FA5002C */  lw    $a1, 0x2c($sp)
/* 063B18 7F02EFA8 0FC1C0A6 */  jal   objecthandlerAnimationRelated7F06FCA8
/* 063B1C 7F02EFAC E7A60014 */   swc1  $f6, 0x14($sp)
/* 063B20 7F02EFB0 8E0E002C */  lw    $t6, 0x2c($s0)
/* 063B24 7F02EFB4 44804000 */  mtc1  $zero, $f8
/* 063B28 7F02EFB8 C5C00014 */  lwc1  $f0, 0x14($t6)
/* 063B2C 7F02EFBC 4600403E */  c.le.s $f8, $f0
/* 063B30 7F02EFC0 00000000 */  nop   
/* 063B34 7F02EFC4 45020005 */  bc1fl .Ljp7F02EFDC
/* 063B38 7F02EFC8 240F0002 */   li    $t7, 2
/* 063B3C 7F02EFCC 44050000 */  mfc1  $a1, $f0
/* 063B40 7F02EFD0 0FC1C0F6 */  jal   sub_GAME_7F06FDE8
/* 063B44 7F02EFD4 02202025 */   move  $a0, $s1
/* 063B48 7F02EFD8 240F0002 */  li    $t7, 2
.Ljp7F02EFDC:
/* 063B4C 7F02EFDC AE0F0058 */  sw    $t7, 0x58($s0)
/* 063B50 7F02EFE0 0FC0B500 */  jal   sub_GAME_7F02D0F8
/* 063B54 7F02EFE4 02002025 */   move  $a0, $s0
/* 063B58 7F02EFE8 10000079 */  b     .Ljp7F02F1D0
/* 063B5C 7F02EFEC 8FBF0024 */   lw    $ra, 0x24($sp)
.Ljp7F02EFF0:
/* 063B60 7F02EFF0 24010002 */  li    $at, 2
/* 063B64 7F02EFF4 1441001A */  bne   $v0, $at, .Ljp7F02F060
/* 063B68 7F02EFF8 02202025 */   move  $a0, $s1
/* 063B6C 7F02EFFC 0FC1BEED */  jal   sub_GAME_7F06F5C4
/* 063B70 7F02F000 E7A20038 */   swc1  $f2, 0x38($sp)
/* 063B74 7F02F004 C7A20038 */  lwc1  $f2, 0x38($sp)
/* 063B78 7F02F008 4602003E */  c.le.s $f0, $f2
/* 063B7C 7F02F00C 00000000 */  nop   
/* 063B80 7F02F010 4502006F */  bc1fl .Ljp7F02F1D0
/* 063B84 7F02F014 8FBF0024 */   lw    $ra, 0x24($sp)
/* 063B88 7F02F018 8E18004C */  lw    $t8, 0x4c($s0)
/* 063B8C 7F02F01C 8E080054 */  lw    $t0, 0x54($s0)
/* 063B90 7F02F020 2401FFBF */  li    $at, -65
/* 063B94 7F02F024 0301C824 */  and   $t9, $t8, $at
/* 063B98 7F02F028 11000007 */  beqz  $t0, .Ljp7F02F048
/* 063B9C 7F02F02C AE19004C */   sw    $t9, 0x4c($s0)
/* 063BA0 7F02F030 02002025 */  move  $a0, $s0
/* 063BA4 7F02F034 03202825 */  move  $a1, $t9
/* 063BA8 7F02F038 0FC0961A */  jal   sub_GAME_7F025560
/* 063BAC 7F02F03C 8E060050 */   lw    $a2, 0x50($s0)
/* 063BB0 7F02F040 10000063 */  b     .Ljp7F02F1D0
/* 063BB4 7F02F044 8FBF0024 */   lw    $ra, 0x24($sp)
.Ljp7F02F048:
/* 063BB8 7F02F048 02002025 */  move  $a0, $s0
/* 063BBC 7F02F04C 8E05004C */  lw    $a1, 0x4c($s0)
/* 063BC0 7F02F050 0FC0967E */  jal   sub_GAME_7F0256F0
/* 063BC4 7F02F054 8E060050 */   lw    $a2, 0x50($s0)
/* 063BC8 7F02F058 1000005D */  b     .Ljp7F02F1D0
/* 063BCC 7F02F05C 8FBF0024 */   lw    $ra, 0x24($sp)
.Ljp7F02F060:
/* 063BD0 7F02F060 8E02004C */  lw    $v0, 0x4c($s0)
.Ljp7F02F064:
/* 063BD4 7F02F064 30490020 */  andi  $t1, $v0, 0x20
/* 063BD8 7F02F068 1120001C */  beqz  $t1, .Ljp7F02F0DC
/* 063BDC 7F02F06C 304A0040 */   andi  $t2, $v0, 0x40
/* 063BE0 7F02F070 1140000D */  beqz  $t2, .Ljp7F02F0A8
/* 063BE4 7F02F074 02202025 */   move  $a0, $s1
/* 063BE8 7F02F078 3C018005 */  lui   $at, %hi(D_80051FCC) # $at, 0x8005
/* 063BEC 7F02F07C C42A1FFC */  lwc1  $f10, %lo(D_80051FCC)($at)
/* 063BF0 7F02F080 8E05002C */  lw    $a1, 0x2c($s0)
/* 063BF4 7F02F084 82060039 */  lb    $a2, 0x39($s0)
/* 063BF8 7F02F088 82070038 */  lb    $a3, 0x38($s0)
/* 063BFC 7F02F08C 02002025 */  move  $a0, $s0
/* 063C00 7F02F090 0FC0B1F2 */  jal   sub_GAME_7F02C4C0
/* 063C04 7F02F094 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 063C08 7F02F098 1440004C */  bnez  $v0, .Ljp7F02F1CC
/* 063C0C 7F02F09C 240B0001 */   li    $t3, 1
/* 063C10 7F02F0A0 1000004A */  b     .Ljp7F02F1CC
/* 063C14 7F02F0A4 AE0B0058 */   sw    $t3, 0x58($s0)
.Ljp7F02F0A8:
/* 063C18 7F02F0A8 0FC1BEED */  jal   sub_GAME_7F06F5C4
/* 063C1C 7F02F0AC E7A20038 */   swc1  $f2, 0x38($sp)
/* 063C20 7F02F0B0 C7A20038 */  lwc1  $f2, 0x38($sp)
/* 063C24 7F02F0B4 4602003E */  c.le.s $f0, $f2
/* 063C28 7F02F0B8 00000000 */  nop   
/* 063C2C 7F02F0BC 45020008 */  bc1fl .Ljp7F02F0E0
/* 063C30 7F02F0C0 820F0036 */   lb    $t7, 0x36($s0)
/* 063C34 7F02F0C4 8E0C004C */  lw    $t4, 0x4c($s0)
/* 063C38 7F02F0C8 240E0002 */  li    $t6, 2
/* 063C3C 7F02F0CC A20E0030 */  sb    $t6, 0x30($s0)
/* 063C40 7F02F0D0 358D0040 */  ori   $t5, $t4, 0x40
/* 063C44 7F02F0D4 1000003D */  b     .Ljp7F02F1CC
/* 063C48 7F02F0D8 AE0D004C */   sw    $t5, 0x4c($s0)
.Ljp7F02F0DC:
/* 063C4C 7F02F0DC 820F0036 */  lb    $t7, 0x36($s0)
.Ljp7F02F0E0:
/* 063C50 7F02F0E0 15E00038 */  bnez  $t7, .Ljp7F02F1C4
/* 063C54 7F02F0E4 00000000 */   nop   
/* 063C58 7F02F0E8 8E18002C */  lw    $t8, 0x2c($s0)
/* 063C5C 7F02F0EC 44808000 */  mtc1  $zero, $f16
/* 063C60 7F02F0F0 C7000024 */  lwc1  $f0, 0x24($t8)
/* 063C64 7F02F0F4 4600803C */  c.lt.s $f16, $f0
/* 063C68 7F02F0F8 00000000 */  nop   
/* 063C6C 7F02F0FC 45000031 */  bc1f  .Ljp7F02F1C4
/* 063C70 7F02F100 00000000 */   nop   
/* 063C74 7F02F104 4600103E */  c.le.s $f2, $f0
/* 063C78 7F02F108 02202025 */  move  $a0, $s1
/* 063C7C 7F02F10C 4500002D */  bc1f  .Ljp7F02F1C4
/* 063C80 7F02F110 00000000 */   nop   
/* 063C84 7F02F114 0FC1BEED */  jal   sub_GAME_7F06F5C4
/* 063C88 7F02F118 E7A20038 */   swc1  $f2, 0x38($sp)
/* 063C8C 7F02F11C C7A20038 */  lwc1  $f2, 0x38($sp)
/* 063C90 7F02F120 4602003E */  c.le.s $f0, $f2
/* 063C94 7F02F124 00000000 */  nop   
/* 063C98 7F02F128 45000026 */  bc1f  .Ljp7F02F1C4
/* 063C9C 7F02F12C 00000000 */   nop   
/* 063CA0 7F02F130 0FC1BEE7 */  jal   sub_GAME_7F06F5AC
/* 063CA4 7F02F134 02202025 */   move  $a0, $s1
/* 063CA8 7F02F138 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 063CAC 7F02F13C 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 063CB0 7F02F140 AFA2002C */  sw    $v0, 0x2c($sp)
/* 063CB4 7F02F144 02002025 */  move  $a0, $s0
/* 063CB8 7F02F148 0FC08F99 */  jal   chrlvGetGuard007SpeedRating
/* 063CBC 7F02F14C 3C053F00 */   lui   $a1, 0x3f00
/* 063CC0 7F02F150 8E19002C */  lw    $t9, 0x2c($s0)
/* 063CC4 7F02F154 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 063CC8 7F02F158 44819000 */  mtc1  $at, $f18
/* 063CCC 7F02F15C 82260024 */  lb    $a2, 0x24($s1)
/* 063CD0 7F02F160 8F270024 */  lw    $a3, 0x24($t9)
/* 063CD4 7F02F164 E7A00010 */  swc1  $f0, 0x10($sp)
/* 063CD8 7F02F168 02202025 */  move  $a0, $s1
/* 063CDC 7F02F16C 8FA5002C */  lw    $a1, 0x2c($sp)
/* 063CE0 7F02F170 0FC1C0A6 */  jal   objecthandlerAnimationRelated7F06FCA8
/* 063CE4 7F02F174 E7B20014 */   swc1  $f18, 0x14($sp)
/* 063CE8 7F02F178 82080037 */  lb    $t0, 0x37($s0)
/* 063CEC 7F02F17C 5100000E */  beql  $t0, $zero, .Ljp7F02F1B8
/* 063CF0 7F02F180 8E0A002C */   lw    $t2, 0x2c($s0)
/* 063CF4 7F02F184 8E09002C */  lw    $t1, 0x2c($s0)
/* 063CF8 7F02F188 44802000 */  mtc1  $zero, $f4
/* 063CFC 7F02F18C C5200014 */  lwc1  $f0, 0x14($t1)
/* 063D00 7F02F190 4600203E */  c.le.s $f4, $f0
/* 063D04 7F02F194 00000000 */  nop   
/* 063D08 7F02F198 4500000A */  bc1f  .Ljp7F02F1C4
/* 063D0C 7F02F19C 00000000 */   nop   
/* 063D10 7F02F1A0 44050000 */  mfc1  $a1, $f0
/* 063D14 7F02F1A4 0FC1C0F6 */  jal   sub_GAME_7F06FDE8
/* 063D18 7F02F1A8 02202025 */   move  $a0, $s1
/* 063D1C 7F02F1AC 10000005 */  b     .Ljp7F02F1C4
/* 063D20 7F02F1B0 00000000 */   nop   
/* 063D24 7F02F1B4 8E0A002C */  lw    $t2, 0x2c($s0)
.Ljp7F02F1B8:
/* 063D28 7F02F1B8 02202025 */  move  $a0, $s1
/* 063D2C 7F02F1BC 0FC1C0F6 */  jal   sub_GAME_7F06FDE8
/* 063D30 7F02F1C0 8D45001C */   lw    $a1, 0x1c($t2)
.Ljp7F02F1C4:
/* 063D34 7F02F1C4 0FC0B9F2 */  jal   sub_GAME_7F02E4C0
/* 063D38 7F02F1C8 02002025 */   move  $a0, $s0
.Ljp7F02F1CC:
/* 063D3C 7F02F1CC 8FBF0024 */  lw    $ra, 0x24($sp)
.Ljp7F02F1D0:
/* 063D40 7F02F1D0 8FB0001C */  lw    $s0, 0x1c($sp)
/* 063D44 7F02F1D4 8FB10020 */  lw    $s1, 0x20($sp)
/* 063D48 7F02F1D8 03E00008 */  jr    $ra
/* 063D4C 7F02F1DC 27BD0040 */   addiu $sp, $sp, 0x40
    
)
#endif


#endif

#ifdef NONMATCHING
void sub_GAME_7F02EEE0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02EEE0
/* 063A10 7F02EEE0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 063A14 7F02EEE4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 063A18 7F02EEE8 AFA40048 */  sw    $a0, 0x48($sp)
/* 063A1C 7F02EEEC 808F0035 */  lb    $t7, 0x35($a0)
/* 063A20 7F02EEF0 11E0013B */  beqz  $t7, .L7F02F3E0
/* 063A24 7F02EEF4 00000000 */   nop   
/* 063A28 7F02EEF8 8C84001C */  lw    $a0, 0x1c($a0)
/* 063A2C 7F02EEFC 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 063A30 7F02EF00 AFA40044 */   sw    $a0, 0x44($sp)
/* 063A34 7F02EF04 8FA70048 */  lw    $a3, 0x48($sp)
/* 063A38 7F02EF08 3C188003 */  lui   $t8, %hi(D_80030198) 
/* 063A3C 7F02EF0C 27180198 */  addiu $t8, %lo(D_80030198) # addiu $t8, $t8, 0x198
/* 063A40 7F02EF10 8CE2002C */  lw    $v0, 0x2c($a3)
/* 063A44 7F02EF14 3C198003 */  lui   $t9, %hi(D_800301E0) 
/* 063A48 7F02EF18 46000306 */  mov.s $f12, $f0
/* 063A4C 7F02EF1C 13020009 */  beq   $t8, $v0, .L7F02EF44
/* 063A50 7F02EF20 273901E0 */   addiu $t9, %lo(D_800301E0) # addiu $t9, $t9, 0x1e0
/* 063A54 7F02EF24 13220007 */  beq   $t9, $v0, .L7F02EF44
/* 063A58 7F02EF28 3C088003 */   lui   $t0, %hi(D_80030228) 
/* 063A5C 7F02EF2C 25080228 */  addiu $t0, %lo(D_80030228) # addiu $t0, $t0, 0x228
/* 063A60 7F02EF30 11020004 */  beq   $t0, $v0, .L7F02EF44
/* 063A64 7F02EF34 3C098003 */   lui   $t1, %hi(D_80030270) 
/* 063A68 7F02EF38 25290270 */  addiu $t1, %lo(D_80030270) # addiu $t1, $t1, 0x270
/* 063A6C 7F02EF3C 152200C7 */  bne   $t1, $v0, .L7F02F25C
/* 063A70 7F02EF40 3C188003 */   lui   $t8, %hi(D_800302B8)
.L7F02EF44:
/* 063A74 7F02EF44 C4440014 */  lwc1  $f4, 0x14($v0)
/* 063A78 7F02EF48 8FAA0044 */  lw    $t2, 0x44($sp)
/* 063A7C 7F02EF4C 4600203E */  c.le.s $f4, $f0
/* 063A80 7F02EF50 00000000 */  nop   
/* 063A84 7F02EF54 450000BF */  bc1f  .L7F02F254
/* 063A88 7F02EF58 00000000 */   nop   
/* 063A8C 7F02EF5C 814B0024 */  lb    $t3, 0x24($t2)
/* 063A90 7F02EF60 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 063A94 7F02EF64 44811000 */  mtc1  $at, $f2
/* 063A98 7F02EF68 AFAB0038 */  sw    $t3, 0x38($sp)
/* 063A9C 7F02EF6C 80EC0039 */  lb    $t4, 0x39($a3)
/* 063AA0 7F02EF70 24430120 */  addiu $v1, $v0, 0x120
/* 063AA4 7F02EF74 11800010 */  beqz  $t4, .L7F02EFB8
/* 063AA8 7F02EF78 00000000 */   nop   
/* 063AAC 7F02EF7C 80ED0038 */  lb    $t5, 0x38($a3)
/* 063AB0 7F02EF80 11A0000D */  beqz  $t5, .L7F02EFB8
/* 063AB4 7F02EF84 00000000 */   nop   
/* 063AB8 7F02EF88 AFA3003C */  sw    $v1, 0x3c($sp)
/* 063ABC 7F02EF8C 0C002914 */  jal   randomGetNext
/* 063AC0 7F02EF90 E7A20034 */   swc1  $f2, 0x34($sp)
/* 063AC4 7F02EF94 304F0001 */  andi  $t7, $v0, 1
/* 063AC8 7F02EF98 8FA3003C */  lw    $v1, 0x3c($sp)
/* 063ACC 7F02EF9C 15E00004 */  bnez  $t7, .L7F02EFB0
/* 063AD0 7F02EFA0 C7A20034 */   lwc1  $f2, 0x34($sp)
/* 063AD4 7F02EFA4 24630120 */  addiu $v1, $v1, 0x120
/* 063AD8 7F02EFA8 10000003 */  b     .L7F02EFB8
/* 063ADC 7F02EFAC 8FA70048 */   lw    $a3, 0x48($sp)
.L7F02EFB0:
/* 063AE0 7F02EFB0 24630240 */  addiu $v1, $v1, 0x240
/* 063AE4 7F02EFB4 8FA70048 */  lw    $a3, 0x48($sp)
.L7F02EFB8:
/* 063AE8 7F02EFB8 3C028003 */  lui   $v0, %hi(D_80030078)
/* 063AEC 7F02EFBC 24420078 */  addiu $v0, %lo(D_80030078) # addiu $v0, $v0, 0x78
/* 063AF0 7F02EFC0 244E0240 */  addiu $t6, $v0, 0x240
/* 063AF4 7F02EFC4 146E0005 */  bne   $v1, $t6, .L7F02EFDC
/* 063AF8 7F02EFC8 00E02025 */   move  $a0, $a3
/* 063AFC 7F02EFCC 3C0141C0 */  li    $at, 0x41C00000 # 24.000000
/* 063B00 7F02EFD0 44811000 */  mtc1  $at, $f2
/* 063B04 7F02EFD4 10000043 */  b     .L7F02F0E4
/* 063B08 7F02EFD8 24190002 */   li    $t9, 2
.L7F02EFDC:
/* 063B0C 7F02EFDC 24580288 */  addiu $t8, $v0, 0x288
/* 063B10 7F02EFE0 14780005 */  bne   $v1, $t8, .L7F02EFF8
/* 063B14 7F02EFE4 245902D0 */   addiu $t9, $v0, 0x2d0
/* 063B18 7F02EFE8 3C0141C0 */  li    $at, 0x41C00000 # 24.000000
/* 063B1C 7F02EFEC 44811000 */  mtc1  $at, $f2
/* 063B20 7F02EFF0 1000003C */  b     .L7F02F0E4
/* 063B24 7F02EFF4 24190002 */   li    $t9, 2
.L7F02EFF8:
/* 063B28 7F02EFF8 14790005 */  bne   $v1, $t9, .L7F02F010
/* 063B2C 7F02EFFC 24480318 */   addiu $t0, $v0, 0x318
/* 063B30 7F02F000 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 063B34 7F02F004 44811000 */  mtc1  $at, $f2
/* 063B38 7F02F008 10000036 */  b     .L7F02F0E4
/* 063B3C 7F02F00C 24190002 */   li    $t9, 2
.L7F02F010:
/* 063B40 7F02F010 14680005 */  bne   $v1, $t0, .L7F02F028
/* 063B44 7F02F014 24490360 */   addiu $t1, $v0, 0x360
/* 063B48 7F02F018 3C014230 */  li    $at, 0x42300000 # 44.000000
/* 063B4C 7F02F01C 44811000 */  mtc1  $at, $f2
/* 063B50 7F02F020 10000030 */  b     .L7F02F0E4
/* 063B54 7F02F024 24190002 */   li    $t9, 2
.L7F02F028:
/* 063B58 7F02F028 14690005 */  bne   $v1, $t1, .L7F02F040
/* 063B5C 7F02F02C 244A03A8 */   addiu $t2, $v0, 0x3a8
/* 063B60 7F02F030 3C0141C0 */  li    $at, 0x41C00000 # 24.000000
/* 063B64 7F02F034 44811000 */  mtc1  $at, $f2
/* 063B68 7F02F038 1000002A */  b     .L7F02F0E4
/* 063B6C 7F02F03C 24190002 */   li    $t9, 2
.L7F02F040:
/* 063B70 7F02F040 146A0005 */  bne   $v1, $t2, .L7F02F058
/* 063B74 7F02F044 244B03F0 */   addiu $t3, $v0, 0x3f0
/* 063B78 7F02F048 3C014208 */  li    $at, 0x42080000 # 34.000000
/* 063B7C 7F02F04C 44811000 */  mtc1  $at, $f2
/* 063B80 7F02F050 10000024 */  b     .L7F02F0E4
/* 063B84 7F02F054 24190002 */   li    $t9, 2
.L7F02F058:
/* 063B88 7F02F058 146B0005 */  bne   $v1, $t3, .L7F02F070
/* 063B8C 7F02F05C 244C0438 */   addiu $t4, $v0, 0x438
/* 063B90 7F02F060 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 063B94 7F02F064 44811000 */  mtc1  $at, $f2
/* 063B98 7F02F068 1000001E */  b     .L7F02F0E4
/* 063B9C 7F02F06C 24190002 */   li    $t9, 2
.L7F02F070:
/* 063BA0 7F02F070 146C0005 */  bne   $v1, $t4, .L7F02F088
/* 063BA4 7F02F074 244D0480 */   addiu $t5, $v0, 0x480
/* 063BA8 7F02F078 3C014230 */  li    $at, 0x42300000 # 44.000000
/* 063BAC 7F02F07C 44811000 */  mtc1  $at, $f2
/* 063BB0 7F02F080 10000018 */  b     .L7F02F0E4
/* 063BB4 7F02F084 24190002 */   li    $t9, 2
.L7F02F088:
/* 063BB8 7F02F088 146D0005 */  bne   $v1, $t5, .L7F02F0A0
/* 063BBC 7F02F08C 244F04C8 */   addiu $t7, $v0, 0x4c8
/* 063BC0 7F02F090 3C0141C0 */  li    $at, 0x41C00000 # 24.000000
/* 063BC4 7F02F094 44811000 */  mtc1  $at, $f2
/* 063BC8 7F02F098 10000012 */  b     .L7F02F0E4
/* 063BCC 7F02F09C 24190002 */   li    $t9, 2
.L7F02F0A0:
/* 063BD0 7F02F0A0 146F0005 */  bne   $v1, $t7, .L7F02F0B8
/* 063BD4 7F02F0A4 244E0510 */   addiu $t6, $v0, 0x510
/* 063BD8 7F02F0A8 3C014208 */  li    $at, 0x42080000 # 34.000000
/* 063BDC 7F02F0AC 44811000 */  mtc1  $at, $f2
/* 063BE0 7F02F0B0 1000000C */  b     .L7F02F0E4
/* 063BE4 7F02F0B4 24190002 */   li    $t9, 2
.L7F02F0B8:
/* 063BE8 7F02F0B8 146E0005 */  bne   $v1, $t6, .L7F02F0D0
/* 063BEC 7F02F0BC 24580558 */   addiu $t8, $v0, 0x558
/* 063BF0 7F02F0C0 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 063BF4 7F02F0C4 44811000 */  mtc1  $at, $f2
/* 063BF8 7F02F0C8 10000006 */  b     .L7F02F0E4
/* 063BFC 7F02F0CC 24190002 */   li    $t9, 2
.L7F02F0D0:
/* 063C00 7F02F0D0 14780003 */  bne   $v1, $t8, .L7F02F0E0
/* 063C04 7F02F0D4 3C014230 */   li    $at, 0x42300000 # 44.000000
/* 063C08 7F02F0D8 44811000 */  mtc1  $at, $f2
/* 063C0C 7F02F0DC 00000000 */  nop   
.L7F02F0E0:
/* 063C10 7F02F0E0 24190002 */  li    $t9, 2
.L7F02F0E4:
/* 063C14 7F02F0E4 A0F90030 */  sb    $t9, 0x30($a3)
/* 063C18 7F02F0E8 ACE3002C */  sw    $v1, 0x2c($a3)
/* 063C1C 7F02F0EC A0E00008 */  sb    $zero, 8($a3)
/* 063C20 7F02F0F0 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 063C24 7F02F0F4 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 063C28 7F02F0F8 E7A20034 */  swc1  $f2, 0x34($sp)
/* 063C2C 7F02F0FC AFA3003C */  sw    $v1, 0x3c($sp)
/* 063C30 7F02F100 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 063C34 7F02F104 3C053F00 */   lui   $a1, 0x3f00
/* 063C38 7F02F108 8FA3003C */  lw    $v1, 0x3c($sp)
/* 063C3C 7F02F10C C7A20034 */  lwc1  $f2, 0x34($sp)
/* 063C40 7F02F110 8FA40044 */  lw    $a0, 0x44($sp)
/* 063C44 7F02F114 8C650000 */  lw    $a1, ($v1)
/* 063C48 7F02F118 8C670010 */  lw    $a3, 0x10($v1)
/* 063C4C 7F02F11C E7A00010 */  swc1  $f0, 0x10($sp)
/* 063C50 7F02F120 8FA60038 */  lw    $a2, 0x38($sp)
/* 063C54 7F02F124 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 063C58 7F02F128 E7A20014 */   swc1  $f2, 0x14($sp)
/* 063C5C 7F02F12C 8FA80048 */  lw    $t0, 0x48($sp)
/* 063C60 7F02F130 8FA3003C */  lw    $v1, 0x3c($sp)
/* 063C64 7F02F134 C7A20034 */  lwc1  $f2, 0x34($sp)
/* 063C68 7F02F138 81090036 */  lb    $t1, 0x36($t0)
/* 063C6C 7F02F13C 51200014 */  beql  $t1, $zero, .L7F02F190
/* 063C70 7F02F140 C4600020 */   lwc1  $f0, 0x20($v1)
/* 063C74 7F02F144 C4600024 */  lwc1  $f0, 0x24($v1)
/* 063C78 7F02F148 44803000 */  mtc1  $zero, $f6
/* 063C7C 7F02F14C 8FA40044 */  lw    $a0, 0x44($sp)
/* 063C80 7F02F150 4600303E */  c.le.s $f6, $f0
/* 063C84 7F02F154 00000000 */  nop   
/* 063C88 7F02F158 45020008 */  bc1fl .L7F02F17C
/* 063C8C 7F02F15C 8C65001C */   lw    $a1, 0x1c($v1)
/* 063C90 7F02F160 44050000 */  mfc1  $a1, $f0
/* 063C94 7F02F164 8FA40044 */  lw    $a0, 0x44($sp)
/* 063C98 7F02F168 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 063C9C 7F02F16C E7A20034 */   swc1  $f2, 0x34($sp)
/* 063CA0 7F02F170 1000001D */  b     .L7F02F1E8
/* 063CA4 7F02F174 C7A20034 */   lwc1  $f2, 0x34($sp)
/* 063CA8 7F02F178 8C65001C */  lw    $a1, 0x1c($v1)
.L7F02F17C:
/* 063CAC 7F02F17C 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 063CB0 7F02F180 E7A20034 */   swc1  $f2, 0x34($sp)
/* 063CB4 7F02F184 10000018 */  b     .L7F02F1E8
/* 063CB8 7F02F188 C7A20034 */   lwc1  $f2, 0x34($sp)
/* 063CBC 7F02F18C C4600020 */  lwc1  $f0, 0x20($v1)
.L7F02F190:
/* 063CC0 7F02F190 44804000 */  mtc1  $zero, $f8
/* 063CC4 7F02F194 8FA40044 */  lw    $a0, 0x44($sp)
/* 063CC8 7F02F198 4600403E */  c.le.s $f8, $f0
/* 063CCC 7F02F19C 00000000 */  nop   
/* 063CD0 7F02F1A0 45020007 */  bc1fl .L7F02F1C0
/* 063CD4 7F02F1A4 C4600014 */   lwc1  $f0, 0x14($v1)
/* 063CD8 7F02F1A8 44050000 */  mfc1  $a1, $f0
/* 063CDC 7F02F1AC 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 063CE0 7F02F1B0 E7A20034 */   swc1  $f2, 0x34($sp)
/* 063CE4 7F02F1B4 1000000C */  b     .L7F02F1E8
/* 063CE8 7F02F1B8 C7A20034 */   lwc1  $f2, 0x34($sp)
/* 063CEC 7F02F1BC C4600014 */  lwc1  $f0, 0x14($v1)
.L7F02F1C0:
/* 063CF0 7F02F1C0 44805000 */  mtc1  $zero, $f10
/* 063CF4 7F02F1C4 8FA40044 */  lw    $a0, 0x44($sp)
/* 063CF8 7F02F1C8 4600503E */  c.le.s $f10, $f0
/* 063CFC 7F02F1CC 00000000 */  nop   
/* 063D00 7F02F1D0 45020006 */  bc1fl .L7F02F1EC
/* 063D04 7F02F1D4 8FAA0048 */   lw    $t2, 0x48($sp)
/* 063D08 7F02F1D8 44050000 */  mfc1  $a1, $f0
/* 063D0C 7F02F1DC 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 063D10 7F02F1E0 E7A20034 */   swc1  $f2, 0x34($sp)
/* 063D14 7F02F1E4 C7A20034 */  lwc1  $f2, 0x34($sp)
.L7F02F1E8:
/* 063D18 7F02F1E8 8FAA0048 */  lw    $t2, 0x48($sp)
.L7F02F1EC:
/* 063D1C 7F02F1EC 44808000 */  mtc1  $zero, $f16
/* 063D20 7F02F1F0 8FA40044 */  lw    $a0, 0x44($sp)
/* 063D24 7F02F1F4 8D4B002C */  lw    $t3, 0x2c($t2)
/* 063D28 7F02F1F8 C572000C */  lwc1  $f18, 0xc($t3)
/* 063D2C 7F02F1FC 46128032 */  c.eq.s $f16, $f18
/* 063D30 7F02F200 00000000 */  nop   
/* 063D34 7F02F204 45010013 */  bc1t  .L7F02F254
/* 063D38 7F02F208 00000000 */   nop   
/* 063D3C 7F02F20C 8C8C0008 */  lw    $t4, 8($a0)
/* 063D40 7F02F210 8D850000 */  lw    $a1, ($t4)
/* 063D44 7F02F214 0FC1B1E7 */  jal   extract_id_from_object_structure_microcode
/* 063D48 7F02F218 E7A20034 */   swc1  $f2, 0x34($sp)
/* 063D4C 7F02F21C C7A20034 */  lwc1  $f2, 0x34($sp)
/* 063D50 7F02F220 E442005C */  swc1  $f2, 0x5c($v0)
/* 063D54 7F02F224 8FAD0048 */  lw    $t5, 0x48($sp)
/* 063D58 7F02F228 8DAF002C */  lw    $t7, 0x2c($t5)
/* 063D5C 7F02F22C C5E4000C */  lwc1  $f4, 0xc($t7)
/* 063D60 7F02F230 46002187 */  neg.s $f6, $f4
/* 063D64 7F02F234 46023203 */  div.s $f8, $f6, $f2
/* 063D68 7F02F238 E4480058 */  swc1  $f8, 0x58($v0)
/* 063D6C 7F02F23C 8FAE0038 */  lw    $t6, 0x38($sp)
/* 063D70 7F02F240 11C00004 */  beqz  $t6, .L7F02F254
/* 063D74 7F02F244 00000000 */   nop   
/* 063D78 7F02F248 C44A0058 */  lwc1  $f10, 0x58($v0)
/* 063D7C 7F02F24C 46005407 */  neg.s $f16, $f10
/* 063D80 7F02F250 E4500058 */  swc1  $f16, 0x58($v0)
.L7F02F254:
/* 063D84 7F02F254 10000062 */  b     .L7F02F3E0
/* 063D88 7F02F258 00000000 */   nop   
.L7F02F25C:
/* 063D8C 7F02F25C 271802B8 */  addiu $t8, $t8, %lo(D_800302B8)
/* 063D90 7F02F260 13020022 */  beq   $t8, $v0, .L7F02F2EC
/* 063D94 7F02F264 3C198003 */   lui   $t9, %hi(D_80030300) 
/* 063D98 7F02F268 27390300 */  addiu $t9, %lo(D_80030300) # addiu $t9, $t9, 0x300
/* 063D9C 7F02F26C 1322001F */  beq   $t9, $v0, .L7F02F2EC
/* 063DA0 7F02F270 3C088003 */   lui   $t0, %hi(D_80030348) 
/* 063DA4 7F02F274 25080348 */  addiu $t0, %lo(D_80030348) # addiu $t0, $t0, 0x348
/* 063DA8 7F02F278 1102001C */  beq   $t0, $v0, .L7F02F2EC
/* 063DAC 7F02F27C 3C098003 */   lui   $t1, %hi(D_80030390) 
/* 063DB0 7F02F280 25290390 */  addiu $t1, %lo(D_80030390) # addiu $t1, $t1, 0x390
/* 063DB4 7F02F284 11220019 */  beq   $t1, $v0, .L7F02F2EC
/* 063DB8 7F02F288 3C0A8003 */   lui   $t2, %hi(D_800303D8) 
/* 063DBC 7F02F28C 254A03D8 */  addiu $t2, %lo(D_800303D8) # addiu $t2, $t2, 0x3d8
/* 063DC0 7F02F290 11420016 */  beq   $t2, $v0, .L7F02F2EC
/* 063DC4 7F02F294 3C0B8003 */   lui   $t3, %hi(D_80030420) 
/* 063DC8 7F02F298 256B0420 */  addiu $t3, %lo(D_80030420) # addiu $t3, $t3, 0x420
/* 063DCC 7F02F29C 11620013 */  beq   $t3, $v0, .L7F02F2EC
/* 063DD0 7F02F2A0 3C0C8003 */   lui   $t4, %hi(D_80030468) 
/* 063DD4 7F02F2A4 258C0468 */  addiu $t4, %lo(D_80030468) # addiu $t4, $t4, 0x468
/* 063DD8 7F02F2A8 11820010 */  beq   $t4, $v0, .L7F02F2EC
/* 063DDC 7F02F2AC 3C0D8003 */   lui   $t5, %hi(D_800304B0) 
/* 063DE0 7F02F2B0 25AD04B0 */  addiu $t5, %lo(D_800304B0) # addiu $t5, $t5, 0x4b0
/* 063DE4 7F02F2B4 11A2000D */  beq   $t5, $v0, .L7F02F2EC
/* 063DE8 7F02F2B8 3C0F8003 */   lui   $t7, %hi(D_800304F8) 
/* 063DEC 7F02F2BC 25EF04F8 */  addiu $t7, %lo(D_800304F8) # addiu $t7, $t7, 0x4f8
/* 063DF0 7F02F2C0 11E2000A */  beq   $t7, $v0, .L7F02F2EC
/* 063DF4 7F02F2C4 3C0E8003 */   lui   $t6, %hi(D_80030540) 
/* 063DF8 7F02F2C8 25CE0540 */  addiu $t6, %lo(D_80030540) # addiu $t6, $t6, 0x540
/* 063DFC 7F02F2CC 11C20007 */  beq   $t6, $v0, .L7F02F2EC
/* 063E00 7F02F2D0 3C188003 */   lui   $t8, %hi(D_80030588) 
/* 063E04 7F02F2D4 27180588 */  addiu $t8, %lo(D_80030588) # addiu $t8, $t8, 0x588
/* 063E08 7F02F2D8 13020004 */  beq   $t8, $v0, .L7F02F2EC
/* 063E0C 7F02F2DC 3C198003 */   lui   $t9, %hi(D_800305D0) 
/* 063E10 7F02F2E0 273905D0 */  addiu $t9, %lo(D_800305D0) # addiu $t9, $t9, 0x5d0
/* 063E14 7F02F2E4 1722003E */  bne   $t9, $v0, .L7F02F3E0
/* 063E18 7F02F2E8 00000000 */   nop   
.L7F02F2EC:
/* 063E1C 7F02F2EC 80E80036 */  lb    $t0, 0x36($a3)
/* 063E20 7F02F2F0 1500003B */  bnez  $t0, .L7F02F3E0
/* 063E24 7F02F2F4 00000000 */   nop   
/* 063E28 7F02F2F8 C4420024 */  lwc1  $f2, 0x24($v0)
/* 063E2C 7F02F2FC 44809000 */  mtc1  $zero, $f18
/* 063E30 7F02F300 00000000 */  nop   
/* 063E34 7F02F304 4602903C */  c.lt.s $f18, $f2
/* 063E38 7F02F308 00000000 */  nop   
/* 063E3C 7F02F30C 45000034 */  bc1f  .L7F02F3E0
/* 063E40 7F02F310 00000000 */   nop   
/* 063E44 7F02F314 4602003E */  c.le.s $f0, $f2
/* 063E48 7F02F318 8FA40044 */  lw    $a0, 0x44($sp)
/* 063E4C 7F02F31C 45000030 */  bc1f  .L7F02F3E0
/* 063E50 7F02F320 00000000 */   nop   
/* 063E54 7F02F324 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 063E58 7F02F328 E7AC0040 */   swc1  $f12, 0x40($sp)
/* 063E5C 7F02F32C C7AC0040 */  lwc1  $f12, 0x40($sp)
/* 063E60 7F02F330 460C003E */  c.le.s $f0, $f12
/* 063E64 7F02F334 00000000 */  nop   
/* 063E68 7F02F338 45000029 */  bc1f  .L7F02F3E0
/* 063E6C 7F02F33C 00000000 */   nop   
/* 063E70 7F02F340 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 063E74 7F02F344 8FA40044 */   lw    $a0, 0x44($sp)
/* 063E78 7F02F348 3C063F4C */  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
/* 063E7C 7F02F34C 34C6CCCD */  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 063E80 7F02F350 AFA20024 */  sw    $v0, 0x24($sp)
/* 063E84 7F02F354 8FA40048 */  lw    $a0, 0x48($sp)
/* 063E88 7F02F358 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 063E8C 7F02F35C 3C053F00 */   lui   $a1, 0x3f00
/* 063E90 7F02F360 8FAA0048 */  lw    $t2, 0x48($sp)
/* 063E94 7F02F364 8FA40044 */  lw    $a0, 0x44($sp)
/* 063E98 7F02F368 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 063E9C 7F02F36C 8D4B002C */  lw    $t3, 0x2c($t2)
/* 063EA0 7F02F370 44812000 */  mtc1  $at, $f4
/* 063EA4 7F02F374 80860024 */  lb    $a2, 0x24($a0)
/* 063EA8 7F02F378 8D670024 */  lw    $a3, 0x24($t3)
/* 063EAC 7F02F37C E7A00010 */  swc1  $f0, 0x10($sp)
/* 063EB0 7F02F380 8FA50024 */  lw    $a1, 0x24($sp)
/* 063EB4 7F02F384 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 063EB8 7F02F388 E7A40014 */   swc1  $f4, 0x14($sp)
/* 063EBC 7F02F38C 8FAC0048 */  lw    $t4, 0x48($sp)
/* 063EC0 7F02F390 8FAE0048 */  lw    $t6, 0x48($sp)
/* 063EC4 7F02F394 818D0037 */  lb    $t5, 0x37($t4)
/* 063EC8 7F02F398 51A0000E */  beql  $t5, $zero, .L7F02F3D4
/* 063ECC 7F02F39C 8DD8002C */   lw    $t8, 0x2c($t6)
/* 063ED0 7F02F3A0 8D8F002C */  lw    $t7, 0x2c($t4)
/* 063ED4 7F02F3A4 44803000 */  mtc1  $zero, $f6
/* 063ED8 7F02F3A8 C5E00014 */  lwc1  $f0, 0x14($t7)
/* 063EDC 7F02F3AC 4600303E */  c.le.s $f6, $f0
/* 063EE0 7F02F3B0 00000000 */  nop   
/* 063EE4 7F02F3B4 4500000A */  bc1f  .L7F02F3E0
/* 063EE8 7F02F3B8 00000000 */   nop   
/* 063EEC 7F02F3BC 44050000 */  mfc1  $a1, $f0
/* 063EF0 7F02F3C0 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 063EF4 7F02F3C4 8FA40044 */   lw    $a0, 0x44($sp)
/* 063EF8 7F02F3C8 10000005 */  b     .L7F02F3E0
/* 063EFC 7F02F3CC 00000000 */   nop   
/* 063F00 7F02F3D0 8DD8002C */  lw    $t8, 0x2c($t6)
.L7F02F3D4:
/* 063F04 7F02F3D4 8FA40044 */  lw    $a0, 0x44($sp)
/* 063F08 7F02F3D8 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 063F0C 7F02F3DC 8F05001C */   lw    $a1, 0x1c($t8)
.L7F02F3E0:
/* 063F10 7F02F3E0 0FC0B930 */  jal   sub_GAME_7F02E4C0
/* 063F14 7F02F3E4 8FA40048 */   lw    $a0, 0x48($sp)
/* 063F18 7F02F3E8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 063F1C 7F02F3EC 27BD0048 */  addiu $sp, $sp, 0x48
/* 063F20 7F02F3F0 03E00008 */  jr    $ra
/* 063F24 7F02F3F4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02F3F8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02F3F8
/* 063F28 7F02F3F8 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 063F2C 7F02F3FC AFB00020 */  sw    $s0, 0x20($sp)
/* 063F30 7F02F400 00808025 */  move  $s0, $a0
/* 063F34 7F02F404 AFBF0024 */  sw    $ra, 0x24($sp)
/* 063F38 7F02F408 8C84001C */  lw    $a0, 0x1c($a0)
/* 063F3C 7F02F40C 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 063F40 7F02F410 AFA40044 */   sw    $a0, 0x44($sp)
/* 063F44 7F02F414 8FAE0044 */  lw    $t6, 0x44($sp)
/* 063F48 7F02F418 46000086 */  mov.s $f2, $f0
/* 063F4C 7F02F41C 00003025 */  move  $a2, $zero
/* 063F50 7F02F420 81CF0024 */  lb    $t7, 0x24($t6)
/* 063F54 7F02F424 02002025 */  move  $a0, $s0
/* 063F58 7F02F428 11E00003 */  beqz  $t7, .L7F02F438
/* 063F5C 7F02F42C 00000000 */   nop   
/* 063F60 7F02F430 10000001 */  b     .L7F02F438
/* 063F64 7F02F434 24060001 */   li    $a2, 1
.L7F02F438:
/* 063F68 7F02F438 00C02825 */  move  $a1, $a2
/* 063F6C 7F02F43C AFA6003C */  sw    $a2, 0x3c($sp)
/* 063F70 7F02F440 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 063F74 7F02F444 E7A20040 */   swc1  $f2, 0x40($sp)
/* 063F78 7F02F448 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 063F7C 7F02F44C C7A20040 */  lwc1  $f2, 0x40($sp)
/* 063F80 7F02F450 44812000 */  mtc1  $at, $f4
/* 063F84 7F02F454 8FA6003C */  lw    $a2, 0x3c($sp)
/* 063F88 7F02F458 4602203E */  c.le.s $f4, $f2
/* 063F8C 7F02F45C 00000000 */  nop   
/* 063F90 7F02F460 45020009 */  bc1fl .L7F02F488
/* 063F94 7F02F464 3C014274 */   lui   $at, 0x4274
/* 063F98 7F02F468 50400007 */  beql  $v0, $zero, .L7F02F488
/* 063F9C 7F02F46C 3C014274 */   li    $at, 0x42740000 # 61.000000
/* 063FA0 7F02F470 8C430004 */  lw    $v1, 4($v0)
/* 063FA4 7F02F474 2401F7FF */  li    $at, -2049
/* 063FA8 7F02F478 8C780064 */  lw    $t8, 0x64($v1)
/* 063FAC 7F02F47C 0301C824 */  and   $t9, $t8, $at
/* 063FB0 7F02F480 AC790064 */  sw    $t9, 0x64($v1)
/* 063FB4 7F02F484 3C014274 */  li    $at, 0x42740000 # 61.000000
.L7F02F488:
/* 063FB8 7F02F488 44813000 */  mtc1  $at, $f6
/* 063FBC 7F02F48C 3C0142EE */  li    $at, 0x42EE0000 # 119.000000
/* 063FC0 7F02F490 44814000 */  mtc1  $at, $f8
/* 063FC4 7F02F494 4602303E */  c.le.s $f6, $f2
/* 063FC8 7F02F498 00000000 */  nop   
/* 063FCC 7F02F49C 45020007 */  bc1fl .L7F02F4BC
/* 063FD0 7F02F4A0 4602403E */   c.le.s $f8, $f2
/* 063FD4 7F02F4A4 50400005 */  beql  $v0, $zero, .L7F02F4BC
/* 063FD8 7F02F4A8 4602403E */   c.le.s $f8, $f2
/* 063FDC 7F02F4AC 8C430004 */  lw    $v1, 4($v0)
/* 063FE0 7F02F4B0 240800B4 */  li    $t0, 180
/* 063FE4 7F02F4B4 A4680082 */  sh    $t0, 0x82($v1)
/* 063FE8 7F02F4B8 4602403E */  c.le.s $f8, $f2
.L7F02F4BC:
/* 063FEC 7F02F4BC 00000000 */  nop   
/* 063FF0 7F02F4C0 4502000D */  bc1fl .L7F02F4F8
/* 063FF4 7F02F4C4 8FA40044 */   lw    $a0, 0x44($sp)
/* 063FF8 7F02F4C8 1040000A */  beqz  $v0, .L7F02F4F4
/* 063FFC 7F02F4CC 00064880 */   sll   $t1, $a2, 2
/* 064000 7F02F4D0 02095021 */  addu  $t2, $s0, $t1
/* 064004 7F02F4D4 8D440160 */  lw    $a0, 0x160($t2)
/* 064008 7F02F4D8 E7A20040 */  swc1  $f2, 0x40($sp)
/* 06400C 7F02F4DC 0FC12FF4 */  jal   sub_GAME_7F04BFD0
/* 064010 7F02F4E0 24050003 */   li    $a1, 3
/* 064014 7F02F4E4 960B0012 */  lhu   $t3, 0x12($s0)
/* 064018 7F02F4E8 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 06401C 7F02F4EC 356C0001 */  ori   $t4, $t3, 1
/* 064020 7F02F4F0 A60C0012 */  sh    $t4, 0x12($s0)
.L7F02F4F4:
/* 064024 7F02F4F4 8FA40044 */  lw    $a0, 0x44($sp)
.L7F02F4F8:
/* 064028 7F02F4F8 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 06402C 7F02F4FC E7A20040 */   swc1  $f2, 0x40($sp)
/* 064030 7F02F500 E7A0002C */  swc1  $f0, 0x2c($sp)
/* 064034 7F02F504 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 064038 7F02F508 8FA40044 */   lw    $a0, 0x44($sp)
/* 06403C 7F02F50C C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 064040 7F02F510 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 064044 7F02F514 3C0142AE */  li    $at, 0x42AE0000 # 87.000000
/* 064048 7F02F518 460A003E */  c.le.s $f0, $f10
/* 06404C 7F02F51C 00000000 */  nop   
/* 064050 7F02F520 45020006 */  bc1fl .L7F02F53C
/* 064054 7F02F524 44818000 */   mtc1  $at, $f16
/* 064058 7F02F528 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 06405C 7F02F52C 02002025 */   move  $a0, $s0
/* 064060 7F02F530 10000018 */  b     .L7F02F594
/* 064064 7F02F534 8FBF0024 */   lw    $ra, 0x24($sp)
/* 064068 7F02F538 44818000 */  mtc1  $at, $f16
.L7F02F53C:
/* 06406C 7F02F53C 3C0142DC */  li    $at, 0x42DC0000 # 110.000000
/* 064070 7F02F540 4602803E */  c.le.s $f16, $f2
/* 064074 7F02F544 00000000 */  nop   
/* 064078 7F02F548 45020012 */  bc1fl .L7F02F594
/* 06407C 7F02F54C 8FBF0024 */   lw    $ra, 0x24($sp)
/* 064080 7F02F550 44819000 */  mtc1  $at, $f18
/* 064084 7F02F554 02002025 */  move  $a0, $s0
/* 064088 7F02F558 3C053F80 */  lui   $a1, 0x3f80
/* 06408C 7F02F55C 4612103E */  c.le.s $f2, $f18
/* 064090 7F02F560 3C063FCC */  lui   $a2, (0x3FCCCCCD >> 16) # lui $a2, 0x3fcc
/* 064094 7F02F564 4502000B */  bc1fl .L7F02F594
/* 064098 7F02F568 8FBF0024 */   lw    $ra, 0x24($sp)
/* 06409C 7F02F56C 0FC08ED7 */  jal   chrlvGetGuard007SpeedRating
/* 0640A0 7F02F570 34C6CCCD */   ori   $a2, (0x3FCCCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 0640A4 7F02F574 44802000 */  mtc1  $zero, $f4
/* 0640A8 7F02F578 44070000 */  mfc1  $a3, $f0
/* 0640AC 7F02F57C 02002025 */  move  $a0, $s0
/* 0640B0 7F02F580 24050001 */  li    $a1, 1
/* 0640B4 7F02F584 3C0642DC */  lui   $a2, 0x42dc
/* 0640B8 7F02F588 0FC0B0AC */  jal   sub_GAME_7F02C2B0
/* 0640BC 7F02F58C E7A40010 */   swc1  $f4, 0x10($sp)
/* 0640C0 7F02F590 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F02F594:
/* 0640C4 7F02F594 8FB00020 */  lw    $s0, 0x20($sp)
/* 0640C8 7F02F598 27BD0048 */  addiu $sp, $sp, 0x48
/* 0640CC 7F02F59C 03E00008 */  jr    $ra
/* 0640D0 7F02F5A0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02F5A4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02F5A4
/* 0640D4 7F02F5A4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0640D8 7F02F5A8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0640DC 7F02F5AC AFB00020 */  sw    $s0, 0x20($sp)
/* 0640E0 7F02F5B0 AFA40030 */  sw    $a0, 0x30($sp)
/* 0640E4 7F02F5B4 8C90001C */  lw    $s0, 0x1c($a0)
/* 0640E8 7F02F5B8 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 0640EC 7F02F5BC 02002025 */   move  $a0, $s0
/* 0640F0 7F02F5C0 3C0142AC */  li    $at, 0x42AC0000 # 86.000000
/* 0640F4 7F02F5C4 44812000 */  mtc1  $at, $f4
/* 0640F8 7F02F5C8 46000086 */  mov.s $f2, $f0
/* 0640FC 7F02F5CC 02002025 */  move  $a0, $s0
/* 064100 7F02F5D0 4604003C */  c.lt.s $f0, $f4
/* 064104 7F02F5D4 00000000 */  nop   
/* 064108 7F02F5D8 4502001D */  bc1fl .L7F02F650
/* 06410C 7F02F5DC 02002025 */   move  $a0, $s0
/* 064110 7F02F5E0 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 064114 7F02F5E4 E7A20028 */   swc1  $f2, 0x28($sp)
/* 064118 7F02F5E8 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 06411C 7F02F5EC 4602003E */  c.le.s $f0, $f2
/* 064120 7F02F5F0 00000000 */  nop   
/* 064124 7F02F5F4 45020016 */  bc1fl .L7F02F650
/* 064128 7F02F5F8 02002025 */   move  $a0, $s0
/* 06412C 7F02F5FC 0FC1BD84 */  jal   sub_GAME_7F06F610
/* 064130 7F02F600 02002025 */   move  $a0, $s0
/* 064134 7F02F604 3C0F8007 */  lui   $t7, %hi(ptr_animation_table) 
/* 064138 7F02F608 3C0141C0 */  li    $at, 0x41C00000 # 24.000000
/* 06413C 7F02F60C 44813000 */  mtc1  $at, $f6
/* 064140 7F02F610 8DEF9538 */  lw    $t7, %lo(ptr_animation_table)($t7)
/* 064144 7F02F614 3C180000 */  lui   $t8, %hi(0x00006254) # $t8, 0
/* 064148 7F02F618 27186254 */  addiu $t8, %lo(0x00006254) # addiu $t8, $t8, 0x6254
/* 06414C 7F02F61C 02002025 */  move  $a0, $s0
/* 064150 7F02F620 00003025 */  move  $a2, $zero
/* 064154 7F02F624 3C0742AC */  lui   $a3, 0x42ac
/* 064158 7F02F628 E7A00010 */  swc1  $f0, 0x10($sp)
/* 06415C 7F02F62C 01F82821 */  addu  $a1, $t7, $t8
/* 064160 7F02F630 0FC1BF2A */  jal   objecthandlerAnimationRelated7F06FCA8
/* 064164 7F02F634 E7A60014 */   swc1  $f6, 0x14($sp)
/* 064168 7F02F638 02002025 */  move  $a0, $s0
/* 06416C 7F02F63C 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 064170 7F02F640 3C054303 */   lui   $a1, 0x4303
/* 064174 7F02F644 1000000C */  b     .L7F02F678
/* 064178 7F02F648 8FBF0024 */   lw    $ra, 0x24($sp)
/* 06417C 7F02F64C 02002025 */  move  $a0, $s0
.L7F02F650:
/* 064180 7F02F650 0FC1BD71 */  jal   sub_GAME_7F06F5C4
/* 064184 7F02F654 E7A20028 */   swc1  $f2, 0x28($sp)
/* 064188 7F02F658 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 06418C 7F02F65C 4602003E */  c.le.s $f0, $f2
/* 064190 7F02F660 00000000 */  nop   
/* 064194 7F02F664 45020004 */  bc1fl .L7F02F678
/* 064198 7F02F668 8FBF0024 */   lw    $ra, 0x24($sp)
/* 06419C 7F02F66C 0FC08F2E */  jal   chrlvKneelingAnimationRelated
/* 0641A0 7F02F670 8FA40030 */   lw    $a0, 0x30($sp)
/* 0641A4 7F02F674 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F02F678:
/* 0641A8 7F02F678 8FB00020 */  lw    $s0, 0x20($sp)
/* 0641AC 7F02F67C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0641B0 7F02F680 03E00008 */  jr    $ra
/* 0641B4 7F02F684 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02F688(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02F688
/* 0641B8 7F02F688 03E00008 */  jr    $ra
/* 0641BC 7F02F68C AFA40000 */   sw    $a0, ($sp)
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02F690(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80051FD0
.word 0x40c90fdb /*6.2831855*/
glabel D_80051FD4
.word 0x40490fdb /*3.1415927*/
glabel D_80051FD8
.word 0x40c90fdb /*6.2831855*/
glabel D_80051FDC
.word 0x3e9930a7 /*0.29919931*/
glabel D_80051FE0
.word 0x3c751aa5 /*0.014959966*/
glabel D_80051FE4
.word 0x3ec90fdb /*0.39269909*/
glabel D_80051FE8
.word 0x3ca0d97c /*0.019634955*/
glabel D_80051FEC
.word 0x3fa0d97c /*1.2566371*/
glabel D_80051FF0
.word 0x3dc90fdb /*0.098174773*/
glabel D_80051FF4
.word 0x3e490fdb /*0.19634955*/
glabel D_80051FF8
.word 0x3c751aa5 /*0.014959966*/
glabel D_80051FFC
.word 0x3ec90fdb /*0.39269909*/
glabel D_80052000
.word 0x3c20d97c /*0.0098174773*/
glabel D_80052004
.word 0x3fa0d97c /*1.2566371*/
glabel D_80052008
.word 0x3d490fdb /*0.049087387*/
glabel D_8005200C
.word 0x3e00adfd /*0.12566371*/
glabel D_80052010
.word 0x3c20d97c /*0.0098174773*/
.text
glabel sub_GAME_7F02F690
/* 0641C0 7F02F690 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0641C4 7F02F694 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0641C8 7F02F698 AFA60058 */  sw    $a2, 0x58($sp)
/* 0641CC 7F02F69C AFA7005C */  sw    $a3, 0x5c($sp)
/* 0641D0 7F02F6A0 8C8E001C */  lw    $t6, 0x1c($a0)
/* 0641D4 7F02F6A4 8C820018 */  lw    $v0, 0x18($a0)
/* 0641D8 7F02F6A8 AFAE0048 */  sw    $t6, 0x48($sp)
/* 0641DC 7F02F6AC C4A40000 */  lwc1  $f4, ($a1)
/* 0641E0 7F02F6B0 C4A80008 */  lwc1  $f8, 8($a1)
/* 0641E4 7F02F6B4 C4460008 */  lwc1  $f6, 8($v0)
/* 0641E8 7F02F6B8 C44A0010 */  lwc1  $f10, 0x10($v0)
/* 0641EC 7F02F6BC 46062301 */  sub.s $f12, $f4, $f6
/* 0641F0 7F02F6C0 0FC16A8C */  jal   atan2f
/* 0641F4 7F02F6C4 460A4381 */   sub.s $f14, $f8, $f10
/* 0641F8 7F02F6C8 8FA40048 */  lw    $a0, 0x48($sp)
/* 0641FC 7F02F6CC 0FC1B320 */  jal   getsubroty
/* 064200 7F02F6D0 E7A0003C */   swc1  $f0, 0x3c($sp)
/* 064204 7F02F6D4 C7AE003C */  lwc1  $f14, 0x3c($sp)
/* 064208 7F02F6D8 E7A00038 */  swc1  $f0, 0x38($sp)
/* 06420C 7F02F6DC 00001825 */  move  $v1, $zero
/* 064210 7F02F6E0 4600703C */  c.lt.s $f14, $f0
/* 064214 7F02F6E4 3C018005 */  lui   $at, %hi(D_80051FD0)
/* 064218 7F02F6E8 46007301 */  sub.s $f12, $f14, $f0
/* 06421C 7F02F6EC 8FA20058 */  lw    $v0, 0x58($sp)
/* 064220 7F02F6F0 8FAF0048 */  lw    $t7, 0x48($sp)
/* 064224 7F02F6F4 45000003 */  bc1f  .L7F02F704
/* 064228 7F02F6F8 46006086 */   mov.s $f2, $f12
/* 06422C 7F02F6FC C4301FD0 */  lwc1  $f16, %lo(D_80051FD0)($at)
/* 064230 7F02F700 46106080 */  add.s $f2, $f12, $f16
.L7F02F704:
/* 064234 7F02F704 3C018005 */  lui   $at, %hi(D_80051FD4)
/* 064238 7F02F708 C4321FD4 */  lwc1  $f18, %lo(D_80051FD4)($at)
/* 06423C 7F02F70C 46001006 */  mov.s $f0, $f2
/* 064240 7F02F710 3C018005 */  lui   $at, %hi(D_80051FD8)
/* 064244 7F02F714 4602903C */  c.lt.s $f18, $f2
/* 064248 7F02F718 00000000 */  nop   
/* 06424C 7F02F71C 45020004 */  bc1fl .L7F02F730
/* 064250 7F02F720 24010002 */   li    $at, 2
/* 064254 7F02F724 C4241FD8 */  lwc1  $f4, %lo(D_80051FD8)($at)
/* 064258 7F02F728 46022001 */  sub.s $f0, $f4, $f2
/* 06425C 7F02F72C 24010002 */  li    $at, 2
.L7F02F730:
/* 064260 7F02F730 14410005 */  bne   $v0, $at, .L7F02F748
/* 064264 7F02F734 3C018005 */   lui   $at, %hi(D_80051FDC)
/* 064268 7F02F738 C42C1FDC */  lwc1  $f12, %lo(D_80051FDC)($at)
/* 06426C 7F02F73C 3C018005 */  lui   $at, %hi(D_80051FE0)
/* 064270 7F02F740 10000030 */  b     .L7F02F804
/* 064274 7F02F744 C4201FE0 */   lwc1  $f0, %lo(D_80051FE0)($at)
.L7F02F748:
/* 064278 7F02F748 24010001 */  li    $at, 1
/* 06427C 7F02F74C 14410017 */  bne   $v0, $at, .L7F02F7AC
/* 064280 7F02F750 3C018005 */   lui   $at, %hi(D_80051FE4)
/* 064284 7F02F754 C4261FE4 */  lwc1  $f6, %lo(D_80051FE4)($at)
/* 064288 7F02F758 3C018005 */  lui   $at, %hi(D_80051FEC)
/* 06428C 7F02F75C 4606003C */  c.lt.s $f0, $f6
/* 064290 7F02F760 00000000 */  nop   
/* 064294 7F02F764 45000004 */  bc1f  .L7F02F778
/* 064298 7F02F768 00000000 */   nop   
/* 06429C 7F02F76C 3C018005 */  lui   $at, %hi(D_80051FE8)
/* 0642A0 7F02F770 1000000B */  b     .L7F02F7A0
/* 0642A4 7F02F774 C42C1FE8 */   lwc1  $f12, %lo(D_80051FE8)($at)
.L7F02F778:
/* 0642A8 7F02F778 C4281FEC */  lwc1  $f8, %lo(D_80051FEC)($at)
/* 0642AC 7F02F77C 3C018005 */  lui   $at, %hi(D_80051FF4)
/* 0642B0 7F02F780 4608003C */  c.lt.s $f0, $f8
/* 0642B4 7F02F784 00000000 */  nop   
/* 0642B8 7F02F788 45000004 */  bc1f  .L7F02F79C
/* 0642BC 7F02F78C 00000000 */   nop   
/* 0642C0 7F02F790 3C018005 */  lui   $at, %hi(D_80051FF0)
/* 0642C4 7F02F794 10000002 */  b     .L7F02F7A0
/* 0642C8 7F02F798 C42C1FF0 */   lwc1  $f12, %lo(D_80051FF0)($at)
.L7F02F79C:
/* 0642CC 7F02F79C C42C1FF4 */  lwc1  $f12, %lo(D_80051FF4)($at)
.L7F02F7A0:
/* 0642D0 7F02F7A0 3C018005 */  lui   $at, %hi(D_80051FF8)
/* 0642D4 7F02F7A4 10000017 */  b     .L7F02F804
/* 0642D8 7F02F7A8 C4201FF8 */   lwc1  $f0, %lo(D_80051FF8)($at)
.L7F02F7AC:
/* 0642DC 7F02F7AC 3C018005 */  lui   $at, %hi(D_80051FFC)
/* 0642E0 7F02F7B0 C42A1FFC */  lwc1  $f10, %lo(D_80051FFC)($at)
/* 0642E4 7F02F7B4 3C018005 */  lui   $at, %hi(D_80052004)
/* 0642E8 7F02F7B8 460A003C */  c.lt.s $f0, $f10
/* 0642EC 7F02F7BC 00000000 */  nop   
/* 0642F0 7F02F7C0 45000004 */  bc1f  .L7F02F7D4
/* 0642F4 7F02F7C4 00000000 */   nop   
/* 0642F8 7F02F7C8 3C018005 */  lui   $at, %hi(D_80052000)
/* 0642FC 7F02F7CC 1000000B */  b     .L7F02F7FC
/* 064300 7F02F7D0 C42C2000 */   lwc1  $f12, %lo(D_80052000)($at)
.L7F02F7D4:
/* 064304 7F02F7D4 C4302004 */  lwc1  $f16, %lo(D_80052004)($at)
/* 064308 7F02F7D8 3C018005 */  lui   $at, %hi(D_8005200C)
/* 06430C 7F02F7DC 4610003C */  c.lt.s $f0, $f16
/* 064310 7F02F7E0 00000000 */  nop   
/* 064314 7F02F7E4 45000004 */  bc1f  .L7F02F7F8
/* 064318 7F02F7E8 00000000 */   nop   
/* 06431C 7F02F7EC 3C018005 */  lui   $at, %hi(D_80052008)
/* 064320 7F02F7F0 10000002 */  b     .L7F02F7FC
/* 064324 7F02F7F4 C42C2008 */   lwc1  $f12, %lo(D_80052008)($at)
.L7F02F7F8:
/* 064328 7F02F7F8 C42C200C */  lwc1  $f12, %lo(D_8005200C)($at)
.L7F02F7FC:
/* 06432C 7F02F7FC 3C018005 */  lui   $at, %hi(D_80052010)
/* 064330 7F02F800 C4202010 */  lwc1  $f0, %lo(D_80052010)($at)
.L7F02F804:
/* 064334 7F02F804 C5E200A4 */  lwc1  $f2, 0xa4($t7)
/* 064338 7F02F808 44057000 */  mfc1  $a1, $f14
/* 06433C 7F02F80C E7AE003C */  swc1  $f14, 0x3c($sp)
/* 064340 7F02F810 46026302 */  mul.s $f12, $f12, $f2
/* 064344 7F02F814 AFA30024 */  sw    $v1, 0x24($sp)
/* 064348 7F02F818 27A40038 */  addiu $a0, $sp, 0x38
/* 06434C 7F02F81C 46020002 */  mul.s $f0, $f0, $f2
/* 064350 7F02F820 8FA6005C */  lw    $a2, 0x5c($sp)
/* 064354 7F02F824 E7AC0014 */  swc1  $f12, 0x14($sp)
/* 064358 7F02F828 46000480 */  add.s $f18, $f0, $f0
/* 06435C 7F02F82C 44070000 */  mfc1  $a3, $f0
/* 064360 7F02F830 0FC10C43 */  jal   sub_GAME_7F04310C
/* 064364 7F02F834 E7B20010 */   swc1  $f18, 0x10($sp)
/* 064368 7F02F838 C7AE003C */  lwc1  $f14, 0x3c($sp)
/* 06436C 7F02F83C C7A40038 */  lwc1  $f4, 0x38($sp)
/* 064370 7F02F840 8FA30024 */  lw    $v1, 0x24($sp)
/* 064374 7F02F844 8FB8005C */  lw    $t8, 0x5c($sp)
/* 064378 7F02F848 460E2032 */  c.eq.s $f4, $f14
/* 06437C 7F02F84C 00000000 */  nop   
/* 064380 7F02F850 45020005 */  bc1fl .L7F02F868
/* 064384 7F02F854 8FA40048 */   lw    $a0, 0x48($sp)
/* 064388 7F02F858 44803000 */  mtc1  $zero, $f6
/* 06438C 7F02F85C 24030001 */  li    $v1, 1
/* 064390 7F02F860 E7060000 */  swc1  $f6, ($t8)
/* 064394 7F02F864 8FA40048 */  lw    $a0, 0x48($sp)
.L7F02F868:
/* 064398 7F02F868 8FA50038 */  lw    $a1, 0x38($sp)
/* 06439C 7F02F86C 0FC1B34F */  jal   setsubroty
/* 0643A0 7F02F870 AFA30024 */   sw    $v1, 0x24($sp)
/* 0643A4 7F02F874 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0643A8 7F02F878 8FA20024 */  lw    $v0, 0x24($sp)
/* 0643AC 7F02F87C 27BD0050 */  addiu $sp, $sp, 0x50
/* 0643B0 7F02F880 03E00008 */  jr    $ra
/* 0643B4 7F02F884 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02F888(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02F888
/* 0643B8 7F02F888 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0643BC 7F02F88C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0643C0 7F02F890 AFB00020 */  sw    $s0, 0x20($sp)
/* 0643C4 7F02F894 AFB20028 */  sw    $s2, 0x28($sp)
/* 0643C8 7F02F898 AFB10024 */  sw    $s1, 0x24($sp)
/* 0643CC 7F02F89C 00808025 */  move  $s0, $a0
/* 0643D0 7F02F8A0 8C91001C */  lw    $s1, 0x1c($a0)
/* 0643D4 7F02F8A4 0FC225E6 */  jal   get_curplayer_positiondata
/* 0643D8 7F02F8A8 8C920018 */   lw    $s2, 0x18($a0)
/* 0643DC 7F02F8AC 3C0F8005 */  lui   $t7, %hi(g_ClockTimer) 
/* 0643E0 7F02F8B0 8DEF8374 */  lw    $t7, %lo(g_ClockTimer)($t7)
/* 0643E4 7F02F8B4 8E0E0030 */  lw    $t6, 0x30($s0)
/* 0643E8 7F02F8B8 3C048005 */  lui   $a0, %hi(g_GlobalTimer)
/* 0643EC 7F02F8BC 82080009 */  lb    $t0, 9($s0)
/* 0643F0 7F02F8C0 01CFC021 */  addu  $t8, $t6, $t7
/* 0643F4 7F02F8C4 2484837C */  addiu $a0, %lo(g_GlobalTimer) # addiu $a0, $a0, -0x7c84
/* 0643F8 7F02F8C8 AE180030 */  sw    $t8, 0x30($s0)
/* 0643FC 7F02F8CC 8C990000 */  lw    $t9, ($a0)
/* 064400 7F02F8D0 24010001 */  li    $at, 1
/* 064404 7F02F8D4 00401825 */  move  $v1, $v0
/* 064408 7F02F8D8 1101000B */  beq   $t0, $at, .L7F02F908
/* 06440C 7F02F8DC AE1900C8 */   sw    $t9, 0xc8($s0)
/* 064410 7F02F8E0 8C8A0000 */  lw    $t2, ($a0)
/* 064414 7F02F8E4 8E0900CC */  lw    $t1, 0xcc($s0)
/* 064418 7F02F8E8 254BFFC4 */  addiu $t3, $t2, -0x3c
/* 06441C 7F02F8EC 012B082A */  slt   $at, $t1, $t3
/* 064420 7F02F8F0 14200005 */  bnez  $at, .L7F02F908
/* 064424 7F02F8F4 00000000 */   nop   
/* 064428 7F02F8F8 8E0C0034 */  lw    $t4, 0x34($s0)
/* 06442C 7F02F8FC 0198082A */  slt   $at, $t4, $t8
/* 064430 7F02F900 50200035 */  beql  $at, $zero, .L7F02F9D8
/* 064434 7F02F904 C4520008 */   lwc1  $f18, 8($v0)
.L7F02F908:
/* 064438 7F02F908 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 06443C 7F02F90C 02202025 */   move  $a0, $s1
/* 064440 7F02F910 E7A00034 */  swc1  $f0, 0x34($sp)
/* 064444 7F02F914 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 064448 7F02F918 02202025 */   move  $a0, $s1
/* 06444C 7F02F91C 944E0004 */  lhu   $t6, 4($v0)
/* 064450 7F02F920 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 064454 7F02F924 02202025 */  move  $a0, $s1
/* 064458 7F02F928 448E2000 */  mtc1  $t6, $f4
/* 06445C 7F02F92C 24050000 */  li    $a1, 0
/* 064460 7F02F930 05C10004 */  bgez  $t6, .L7F02F944
/* 064464 7F02F934 468021A0 */   cvt.s.w $f6, $f4
/* 064468 7F02F938 44814000 */  mtc1  $at, $f8
/* 06446C 7F02F93C 00000000 */  nop   
/* 064470 7F02F940 46083180 */  add.s $f6, $f6, $f8
.L7F02F944:
/* 064474 7F02F944 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 064478 7F02F948 44815000 */  mtc1  $at, $f10
/* 06447C 7F02F94C C7B20034 */  lwc1  $f18, 0x34($sp)
/* 064480 7F02F950 460A3402 */  mul.s $f16, $f6, $f10
/* 064484 7F02F954 4612803C */  c.lt.s $f16, $f18
/* 064488 7F02F958 00000000 */  nop   
/* 06448C 7F02F95C 45000005 */  bc1f  .L7F02F974
/* 064490 7F02F960 00000000 */   nop   
/* 064494 7F02F964 0FC1BFA4 */  jal   sub_GAME_7F06FE90
/* 064498 7F02F968 3C064180 */   lui   $a2, 0x4180
/* 06449C 7F02F96C 10000013 */  b     .L7F02F9BC
/* 0644A0 7F02F970 00000000 */   nop   
.L7F02F974:
/* 0644A4 7F02F974 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 0644A8 7F02F978 02202025 */   move  $a0, $s1
/* 0644AC 7F02F97C 944F0004 */  lhu   $t7, 4($v0)
/* 0644B0 7F02F980 02202025 */  move  $a0, $s1
/* 0644B4 7F02F984 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0644B8 7F02F988 448F2000 */  mtc1  $t7, $f4
/* 0644BC 7F02F98C 05E10004 */  bgez  $t7, .L7F02F9A0
/* 0644C0 7F02F990 46802220 */   cvt.s.w $f8, $f4
/* 0644C4 7F02F994 44813000 */  mtc1  $at, $f6
/* 0644C8 7F02F998 00000000 */  nop   
/* 0644CC 7F02F99C 46064200 */  add.s $f8, $f8, $f6
.L7F02F9A0:
/* 0644D0 7F02F9A0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0644D4 7F02F9A4 44815000 */  mtc1  $at, $f10
/* 0644D8 7F02F9A8 3C064180 */  lui   $a2, 0x4180
/* 0644DC 7F02F9AC 460A4402 */  mul.s $f16, $f8, $f10
/* 0644E0 7F02F9B0 44058000 */  mfc1  $a1, $f16
/* 0644E4 7F02F9B4 0FC1BFA4 */  jal   sub_GAME_7F06FE90
/* 0644E8 7F02F9B8 00000000 */   nop   
.L7F02F9BC:
/* 0644EC 7F02F9BC 0FC0A6EC */  jal   chrlvSetTargetToPlayer
/* 0644F0 7F02F9C0 02002025 */   move  $a0, $s0
/* 0644F4 7F02F9C4 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 0644F8 7F02F9C8 02002025 */   move  $a0, $s0
/* 0644FC 7F02F9CC 10000094 */  b     .L7F02FC20
/* 064500 7F02F9D0 8FBF002C */   lw    $ra, 0x2c($sp)
/* 064504 7F02F9D4 C4520008 */  lwc1  $f18, 8($v0)
.L7F02F9D8:
/* 064508 7F02F9D8 C6440008 */  lwc1  $f4, 8($s2)
/* 06450C 7F02F9DC 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 064510 7F02F9E0 44816000 */  mtc1  $at, $f12
/* 064514 7F02F9E4 46049001 */  sub.s $f0, $f18, $f4
/* 064518 7F02F9E8 C4460010 */  lwc1  $f6, 0x10($v0)
/* 06451C 7F02F9EC C6480010 */  lwc1  $f8, 0x10($s2)
/* 064520 7F02F9F0 3C01C396 */  li    $at, 0xC3960000 # -300.000000
/* 064524 7F02F9F4 460C003C */  c.lt.s $f0, $f12
/* 064528 7F02F9F8 02002025 */  move  $a0, $s0
/* 06452C 7F02F9FC 24650008 */  addiu $a1, $v1, 8
/* 064530 7F02FA00 00003025 */  move  $a2, $zero
/* 064534 7F02FA04 45000015 */  bc1f  .L7F02FA5C
/* 064538 7F02FA08 46083081 */   sub.s $f2, $f6, $f8
/* 06453C 7F02FA0C 44817000 */  mtc1  $at, $f14
/* 064540 7F02FA10 00000000 */  nop   
/* 064544 7F02FA14 4600703C */  c.lt.s $f14, $f0
/* 064548 7F02FA18 00000000 */  nop   
/* 06454C 7F02FA1C 4500000F */  bc1f  .L7F02FA5C
/* 064550 7F02FA20 00000000 */   nop   
/* 064554 7F02FA24 460C103C */  c.lt.s $f2, $f12
/* 064558 7F02FA28 00000000 */  nop   
/* 06455C 7F02FA2C 4500000B */  bc1f  .L7F02FA5C
/* 064560 7F02FA30 00000000 */   nop   
/* 064564 7F02FA34 4602703C */  c.lt.s $f14, $f2
/* 064568 7F02FA38 00000000 */  nop   
/* 06456C 7F02FA3C 45000007 */  bc1f  .L7F02FA5C
/* 064570 7F02FA40 00000000 */   nop   
/* 064574 7F02FA44 0FC0A6EC */  jal   chrlvSetTargetToPlayer
/* 064578 7F02FA48 02002025 */   move  $a0, $s0
/* 06457C 7F02FA4C 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 064580 7F02FA50 02002025 */   move  $a0, $s0
/* 064584 7F02FA54 10000072 */  b     .L7F02FC20
/* 064588 7F02FA58 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F02FA5C:
/* 06458C 7F02FA5C 0FC0BDA4 */  jal   sub_GAME_7F02F690
/* 064590 7F02FA60 26070054 */   addiu $a3, $s0, 0x54
/* 064594 7F02FA64 10400002 */  beqz  $v0, .L7F02FA70
/* 064598 7F02FA68 24180001 */   li    $t8, 1
/* 06459C 7F02FA6C AE180038 */  sw    $t8, 0x38($s0)
.L7F02FA70:
/* 0645A0 7F02FA70 8E190030 */  lw    $t9, 0x30($s0)
/* 0645A4 7F02FA74 02002025 */  move  $a0, $s0
/* 0645A8 7F02FA78 2B210015 */  slti  $at, $t9, 0x15
/* 0645AC 7F02FA7C 14200009 */  bnez  $at, .L7F02FAA4
/* 0645B0 7F02FA80 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 0645B4 7F02FA84 44815000 */  mtc1  $at, $f10
/* 0645B8 7F02FA88 8E05003C */  lw    $a1, 0x3c($s0)
/* 0645BC 7F02FA8C 82060049 */  lb    $a2, 0x49($s0)
/* 0645C0 7F02FA90 82070048 */  lb    $a3, 0x48($s0)
/* 0645C4 7F02FA94 0FC0B130 */  jal   sub_GAME_7F02C4C0
/* 0645C8 7F02FA98 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0645CC 7F02FA9C 10000004 */  b     .L7F02FAB0
/* 0645D0 7F02FAA0 8E080038 */   lw    $t0, 0x38($s0)
.L7F02FAA4:
/* 0645D4 7F02FAA4 0FC0B43E */  jal   sub_GAME_7F02D0F8
/* 0645D8 7F02FAA8 02002025 */   move  $a0, $s0
/* 0645DC 7F02FAAC 8E080038 */  lw    $t0, 0x38($s0)
.L7F02FAB0:
/* 0645E0 7F02FAB0 02002025 */  move  $a0, $s0
/* 0645E4 7F02FAB4 24050001 */  li    $a1, 1
/* 0645E8 7F02FAB8 11000052 */  beqz  $t0, .L7F02FC04
/* 0645EC 7F02FABC 00000000 */   nop   
/* 0645F0 7F02FAC0 8E0A0030 */  lw    $t2, 0x30($s0)
/* 0645F4 7F02FAC4 00008825 */  move  $s1, $zero
/* 0645F8 7F02FAC8 02009025 */  move  $s2, $s0
/* 0645FC 7F02FACC 2941001F */  slti  $at, $t2, 0x1f
/* 064600 7F02FAD0 1420004C */  bnez  $at, .L7F02FC04
/* 064604 7F02FAD4 00000000 */   nop   
.L7F02FAD8:
/* 064608 7F02FAD8 82490048 */  lb    $t1, 0x48($s2)
/* 06460C 7F02FADC 02002025 */  move  $a0, $s0
/* 064610 7F02FAE0 02202825 */  move  $a1, $s1
/* 064614 7F02FAE4 1120003F */  beqz  $t1, .L7F02FBE4
/* 064618 7F02FAE8 00000000 */   nop   
/* 06461C 7F02FAEC 824B004A */  lb    $t3, 0x4a($s2)
/* 064620 7F02FAF0 02002025 */  move  $a0, $s0
/* 064624 7F02FAF4 02202825 */  move  $a1, $s1
/* 064628 7F02FAF8 55600006 */  bnezl $t3, .L7F02FB14
/* 06462C 7F02FAFC 8E020030 */   lw    $v0, 0x30($s0)
/* 064630 7F02FB00 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 064634 7F02FB04 24060001 */   li    $a2, 1
/* 064638 7F02FB08 10000039 */  b     .L7F02FBF0
/* 06463C 7F02FB0C 26310001 */   addiu $s1, $s1, 1
/* 064640 7F02FB10 8E020030 */  lw    $v0, 0x30($s0)
.L7F02FB14:
/* 064644 7F02FB14 8E0C0040 */  lw    $t4, 0x40($s0)
/* 064648 7F02FB18 02002025 */  move  $a0, $s0
/* 06464C 7F02FB1C 02202825 */  move  $a1, $s1
/* 064650 7F02FB20 0182082A */  slt   $at, $t4, $v0
/* 064654 7F02FB24 1020002B */  beqz  $at, .L7F02FBD4
/* 064658 7F02FB28 00000000 */   nop   
/* 06465C 7F02FB2C 8E030044 */  lw    $v1, 0x44($s0)
/* 064660 7F02FB30 00117823 */  negu  $t7, $s1
/* 064664 7F02FB34 020FC021 */  addu  $t8, $s0, $t7
/* 064668 7F02FB38 12230004 */  beq   $s1, $v1, .L7F02FB4C
/* 06466C 7F02FB3C 02036821 */   addu  $t5, $s0, $v1
/* 064670 7F02FB40 81AE004A */  lb    $t6, 0x4a($t5)
/* 064674 7F02FB44 15C00023 */  bnez  $t6, .L7F02FBD4
/* 064678 7F02FB48 00000000 */   nop   
.L7F02FB4C:
/* 06467C 7F02FB4C AE020040 */  sw    $v0, 0x40($s0)
/* 064680 7F02FB50 8319004B */  lb    $t9, 0x4b($t8)
/* 064684 7F02FB54 240A0001 */  li    $t2, 1
/* 064688 7F02FB58 02002025 */  move  $a0, $s0
/* 06468C 7F02FB5C 5320000C */  beql  $t9, $zero, .L7F02FB90
/* 064690 7F02FB60 824D004C */   lb    $t5, 0x4c($s2)
/* 064694 7F02FB64 8248004C */  lb    $t0, 0x4c($s2)
/* 064698 7F02FB68 2449005A */  addiu $t1, $v0, 0x5a
/* 06469C 7F02FB6C 51000004 */  beql  $t0, $zero, .L7F02FB80
/* 0646A0 7F02FB70 8E0B0040 */   lw    $t3, 0x40($s0)
/* 0646A4 7F02FB74 1000000F */  b     .L7F02FBB4
/* 0646A8 7F02FB78 AE090040 */   sw    $t1, 0x40($s0)
/* 0646AC 7F02FB7C 8E0B0040 */  lw    $t3, 0x40($s0)
.L7F02FB80:
/* 0646B0 7F02FB80 256C0014 */  addiu $t4, $t3, 0x14
/* 0646B4 7F02FB84 1000000B */  b     .L7F02FBB4
/* 0646B8 7F02FB88 AE0C0040 */   sw    $t4, 0x40($s0)
/* 0646BC 7F02FB8C 824D004C */  lb    $t5, 0x4c($s2)
.L7F02FB90:
/* 0646C0 7F02FB90 51A00006 */  beql  $t5, $zero, .L7F02FBAC
/* 0646C4 7F02FB94 8E180040 */   lw    $t8, 0x40($s0)
/* 0646C8 7F02FB98 8E0E0040 */  lw    $t6, 0x40($s0)
/* 0646CC 7F02FB9C 25CF00B4 */  addiu $t7, $t6, 0xb4
/* 0646D0 7F02FBA0 10000004 */  b     .L7F02FBB4
/* 0646D4 7F02FBA4 AE0F0040 */   sw    $t7, 0x40($s0)
/* 0646D8 7F02FBA8 8E180040 */  lw    $t8, 0x40($s0)
.L7F02FBAC:
/* 0646DC 7F02FBAC 27190028 */  addiu $t9, $t8, 0x28
/* 0646E0 7F02FBB0 AE190040 */  sw    $t9, 0x40($s0)
.L7F02FBB4:
/* 0646E4 7F02FBB4 8E080044 */  lw    $t0, 0x44($s0)
/* 0646E8 7F02FBB8 02202825 */  move  $a1, $s1
/* 0646EC 7F02FBBC 24060001 */  li    $a2, 1
/* 0646F0 7F02FBC0 01484823 */  subu  $t1, $t2, $t0
/* 0646F4 7F02FBC4 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 0646F8 7F02FBC8 AE090044 */   sw    $t1, 0x44($s0)
/* 0646FC 7F02FBCC 10000008 */  b     .L7F02FBF0
/* 064700 7F02FBD0 26310001 */   addiu $s1, $s1, 1
.L7F02FBD4:
/* 064704 7F02FBD4 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 064708 7F02FBD8 00003025 */   move  $a2, $zero
/* 06470C 7F02FBDC 10000004 */  b     .L7F02FBF0
/* 064710 7F02FBE0 26310001 */   addiu $s1, $s1, 1
.L7F02FBE4:
/* 064714 7F02FBE4 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 064718 7F02FBE8 00003025 */   move  $a2, $zero
/* 06471C 7F02FBEC 26310001 */  addiu $s1, $s1, 1
.L7F02FBF0:
/* 064720 7F02FBF0 24010002 */  li    $at, 2
/* 064724 7F02FBF4 1621FFB8 */  bne   $s1, $at, .L7F02FAD8
/* 064728 7F02FBF8 26520001 */   addiu $s2, $s2, 1
/* 06472C 7F02FBFC 10000008 */  b     .L7F02FC20
/* 064730 7F02FC00 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F02FC04:
/* 064734 7F02FC04 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 064738 7F02FC08 00003025 */   move  $a2, $zero
/* 06473C 7F02FC0C 02002025 */  move  $a0, $s0
/* 064740 7F02FC10 00002825 */  move  $a1, $zero
/* 064744 7F02FC14 0FC0B471 */  jal   sub_GAME_7F02D1C4
/* 064748 7F02FC18 00003025 */   move  $a2, $zero
/* 06474C 7F02FC1C 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F02FC20:
/* 064750 7F02FC20 8FB00020 */  lw    $s0, 0x20($sp)
/* 064754 7F02FC24 8FB10024 */  lw    $s1, 0x24($sp)
/* 064758 7F02FC28 8FB20028 */  lw    $s2, 0x28($sp)
/* 06475C 7F02FC2C 03E00008 */  jr    $ra
/* 064760 7F02FC30 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02FC34(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02FC34
/* 064764 7F02FC34 C4C40000 */  lwc1  $f4, ($a2)
/* 064768 7F02FC38 C4860000 */  lwc1  $f6, ($a0)
/* 06476C 7F02FC3C 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 064770 7F02FC40 44808000 */  mtc1  $zero, $f16
/* 064774 7F02FC44 46062201 */  sub.s $f8, $f4, $f6
/* 064778 7F02FC48 44876000 */  mtc1  $a3, $f12
/* 06477C 7F02FC4C E7A80004 */  swc1  $f8, 4($sp)
/* 064780 7F02FC50 C4840008 */  lwc1  $f4, 8($a0)
/* 064784 7F02FC54 C4CA0008 */  lwc1  $f10, 8($a2)
/* 064788 7F02FC58 46045181 */  sub.s $f6, $f10, $f4
/* 06478C 7F02FC5C E7A6000C */  swc1  $f6, 0xc($sp)
/* 064790 7F02FC60 C4A00000 */  lwc1  $f0, ($a1)
/* 064794 7F02FC64 C7AA000C */  lwc1  $f10, 0xc($sp)
/* 064798 7F02FC68 46008032 */  c.eq.s $f16, $f0
/* 06479C 7F02FC6C 00000000 */  nop   
/* 0647A0 7F02FC70 45020015 */  bc1fl .L7F02FCC8
/* 0647A4 7F02FC74 C4A20008 */   lwc1  $f2, 8($a1)
/* 0647A8 7F02FC78 C4A80008 */  lwc1  $f8, 8($a1)
/* 0647AC 7F02FC7C C7A2000C */  lwc1  $f2, 0xc($sp)
/* 0647B0 7F02FC80 46088032 */  c.eq.s $f16, $f8
/* 0647B4 7F02FC84 00000000 */  nop   
/* 0647B8 7F02FC88 4502000F */  bc1fl .L7F02FCC8
/* 0647BC 7F02FC8C C4A20008 */   lwc1  $f2, 8($a1)
/* 0647C0 7F02FC90 46021282 */  mul.s $f10, $f2, $f2
/* 0647C4 7F02FC94 C7A00004 */  lwc1  $f0, 4($sp)
/* 0647C8 7F02FC98 00001025 */  move  $v0, $zero
/* 0647CC 7F02FC9C 46000102 */  mul.s $f4, $f0, $f0
/* 0647D0 7F02FCA0 46045180 */  add.s $f6, $f10, $f4
/* 0647D4 7F02FCA4 460C6202 */  mul.s $f8, $f12, $f12
/* 0647D8 7F02FCA8 4608303E */  c.le.s $f6, $f8
/* 0647DC 7F02FCAC 00000000 */  nop   
/* 0647E0 7F02FCB0 45000025 */  bc1f  .L7F02FD48
/* 0647E4 7F02FCB4 00000000 */   nop   
/* 0647E8 7F02FCB8 24020001 */  li    $v0, 1
/* 0647EC 7F02FCBC 10000022 */  b     .L7F02FD48
/* 0647F0 7F02FCC0 00000000 */   nop   
/* 0647F4 7F02FCC4 C4A20008 */  lwc1  $f2, 8($a1)
.L7F02FCC8:
/* 0647F8 7F02FCC8 C7A80004 */  lwc1  $f8, 4($sp)
/* 0647FC 7F02FCCC 00001025 */  move  $v0, $zero
/* 064800 7F02FCD0 46025102 */  mul.s $f4, $f10, $f2
/* 064804 7F02FCD4 00000000 */  nop   
/* 064808 7F02FCD8 46080182 */  mul.s $f6, $f0, $f8
/* 06480C 7F02FCDC 46062380 */  add.s $f14, $f4, $f6
/* 064810 7F02FCE0 460E803C */  c.lt.s $f16, $f14
/* 064814 7F02FCE4 00000000 */  nop   
/* 064818 7F02FCE8 45000017 */  bc1f  .L7F02FD48
/* 06481C 7F02FCEC 00000000 */   nop   
/* 064820 7F02FCF0 46021102 */  mul.s $f4, $f2, $f2
/* 064824 7F02FCF4 00000000 */  nop   
/* 064828 7F02FCF8 46000182 */  mul.s $f6, $f0, $f0
/* 06482C 7F02FCFC 46062400 */  add.s $f16, $f4, $f6
/* 064830 7F02FD00 460A5102 */  mul.s $f4, $f10, $f10
/* 064834 7F02FD04 00000000 */  nop   
/* 064838 7F02FD08 46084182 */  mul.s $f6, $f8, $f8
/* 06483C 7F02FD0C 00000000 */  nop   
/* 064840 7F02FD10 460E7282 */  mul.s $f10, $f14, $f14
/* 064844 7F02FD14 00000000 */  nop   
/* 064848 7F02FD18 460C6202 */  mul.s $f8, $f12, $f12
/* 06484C 7F02FD1C 46062480 */  add.s $f18, $f4, $f6
/* 064850 7F02FD20 46089101 */  sub.s $f4, $f18, $f8
/* 064854 7F02FD24 46102182 */  mul.s $f6, $f4, $f16
/* 064858 7F02FD28 460A303E */  c.le.s $f6, $f10
/* 06485C 7F02FD2C 00000000 */  nop   
/* 064860 7F02FD30 45000003 */  bc1f  .L7F02FD40
/* 064864 7F02FD34 00000000 */   nop   
/* 064868 7F02FD38 10000003 */  b     .L7F02FD48
/* 06486C 7F02FD3C 24020001 */   li    $v0, 1
.L7F02FD40:
/* 064870 7F02FD40 10000001 */  b     .L7F02FD48
/* 064874 7F02FD44 00001025 */   move  $v0, $zero
.L7F02FD48:
/* 064878 7F02FD48 03E00008 */  jr    $ra
/* 06487C 7F02FD4C 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02FD50(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02FD50
/* 064880 7F02FD50 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 064884 7F02FD54 AFBF001C */  sw    $ra, 0x1c($sp)
/* 064888 7F02FD58 AFB00018 */  sw    $s0, 0x18($sp)
/* 06488C 7F02FD5C 44876000 */  mtc1  $a3, $f12
/* 064890 7F02FD60 C4C00000 */  lwc1  $f0, ($a2)
/* 064894 7F02FD64 C4900000 */  lwc1  $f16, ($a0)
/* 064898 7F02FD68 00A08025 */  move  $s0, $a1
/* 06489C 7F02FD6C 460C0081 */  sub.s $f2, $f0, $f12
/* 0648A0 7F02FD70 4602803E */  c.le.s $f16, $f2
/* 0648A4 7F02FD74 00000000 */  nop   
/* 0648A8 7F02FD78 45020009 */  bc1fl .L7F02FDA0
/* 0648AC 7F02FD7C 460C0080 */   add.s $f2, $f0, $f12
/* 0648B0 7F02FD80 C4A40000 */  lwc1  $f4, ($a1)
/* 0648B4 7F02FD84 4602203E */  c.le.s $f4, $f2
/* 0648B8 7F02FD88 00000000 */  nop   
/* 0648BC 7F02FD8C 45020004 */  bc1fl .L7F02FDA0
/* 0648C0 7F02FD90 460C0080 */   add.s $f2, $f0, $f12
/* 0648C4 7F02FD94 10000033 */  b     .L7F02FE64
/* 0648C8 7F02FD98 00001025 */   move  $v0, $zero
/* 0648CC 7F02FD9C 460C0080 */  add.s $f2, $f0, $f12
.L7F02FDA0:
/* 0648D0 7F02FDA0 4610103E */  c.le.s $f2, $f16
/* 0648D4 7F02FDA4 00000000 */  nop   
/* 0648D8 7F02FDA8 45020009 */  bc1fl .L7F02FDD0
/* 0648DC 7F02FDAC C4C00008 */   lwc1  $f0, 8($a2)
/* 0648E0 7F02FDB0 C6060000 */  lwc1  $f6, ($s0)
/* 0648E4 7F02FDB4 4606103E */  c.le.s $f2, $f6
/* 0648E8 7F02FDB8 00000000 */  nop   
/* 0648EC 7F02FDBC 45020004 */  bc1fl .L7F02FDD0
/* 0648F0 7F02FDC0 C4C00008 */   lwc1  $f0, 8($a2)
/* 0648F4 7F02FDC4 10000027 */  b     .L7F02FE64
/* 0648F8 7F02FDC8 00001025 */   move  $v0, $zero
/* 0648FC 7F02FDCC C4C00008 */  lwc1  $f0, 8($a2)
.L7F02FDD0:
/* 064900 7F02FDD0 C48E0008 */  lwc1  $f14, 8($a0)
/* 064904 7F02FDD4 460C0081 */  sub.s $f2, $f0, $f12
/* 064908 7F02FDD8 4602703E */  c.le.s $f14, $f2
/* 06490C 7F02FDDC 00000000 */  nop   
/* 064910 7F02FDE0 45020009 */  bc1fl .L7F02FE08
/* 064914 7F02FDE4 460C0080 */   add.s $f2, $f0, $f12
/* 064918 7F02FDE8 C6080008 */  lwc1  $f8, 8($s0)
/* 06491C 7F02FDEC 4602403E */  c.le.s $f8, $f2
/* 064920 7F02FDF0 00000000 */  nop   
/* 064924 7F02FDF4 45020004 */  bc1fl .L7F02FE08
/* 064928 7F02FDF8 460C0080 */   add.s $f2, $f0, $f12
/* 06492C 7F02FDFC 10000019 */  b     .L7F02FE64
/* 064930 7F02FE00 00001025 */   move  $v0, $zero
/* 064934 7F02FE04 460C0080 */  add.s $f2, $f0, $f12
.L7F02FE08:
/* 064938 7F02FE08 460E103E */  c.le.s $f2, $f14
/* 06493C 7F02FE0C 00000000 */  nop   
/* 064940 7F02FE10 45020009 */  bc1fl .L7F02FE38
/* 064944 7F02FE14 C6120000 */   lwc1  $f18, ($s0)
/* 064948 7F02FE18 C60A0008 */  lwc1  $f10, 8($s0)
/* 06494C 7F02FE1C 460A103E */  c.le.s $f2, $f10
/* 064950 7F02FE20 00000000 */  nop   
/* 064954 7F02FE24 45020004 */  bc1fl .L7F02FE38
/* 064958 7F02FE28 C6120000 */   lwc1  $f18, ($s0)
/* 06495C 7F02FE2C 1000000D */  b     .L7F02FE64
/* 064960 7F02FE30 00001025 */   move  $v0, $zero
/* 064964 7F02FE34 C6120000 */  lwc1  $f18, ($s0)
.L7F02FE38:
/* 064968 7F02FE38 44803000 */  mtc1  $zero, $f6
/* 06496C 7F02FE3C 44076000 */  mfc1  $a3, $f12
/* 064970 7F02FE40 46109101 */  sub.s $f4, $f18, $f16
/* 064974 7F02FE44 E7A60038 */  swc1  $f6, 0x38($sp)
/* 064978 7F02FE48 27A50034 */  addiu $a1, $sp, 0x34
/* 06497C 7F02FE4C E7A40034 */  swc1  $f4, 0x34($sp)
/* 064980 7F02FE50 C48A0008 */  lwc1  $f10, 8($a0)
/* 064984 7F02FE54 C6080008 */  lwc1  $f8, 8($s0)
/* 064988 7F02FE58 460A4481 */  sub.s $f18, $f8, $f10
/* 06498C 7F02FE5C 0FC0BF0D */  jal   sub_GAME_7F02FC34
/* 064990 7F02FE60 E7B2003C */   swc1  $f18, 0x3c($sp)
.L7F02FE64:
/* 064994 7F02FE64 8FBF001C */  lw    $ra, 0x1c($sp)
/* 064998 7F02FE68 8FB00018 */  lw    $s0, 0x18($sp)
/* 06499C 7F02FE6C 27BD0040 */  addiu $sp, $sp, 0x40
/* 0649A0 7F02FE70 03E00008 */  jr    $ra
/* 0649A4 7F02FE74 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F02FE78(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F02FE78
/* 0649A8 7F02FE78 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0649AC 7F02FE7C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0649B0 7F02FE80 AFB10018 */  sw    $s1, 0x18($sp)
/* 0649B4 7F02FE84 AFB00014 */  sw    $s0, 0x14($sp)
/* 0649B8 7F02FE88 3C038005 */  lui   $v1, %hi(g_GlobalTimer)
/* 0649BC 7F02FE8C 808F0009 */  lb    $t7, 9($a0)
/* 0649C0 7F02FE90 2463837C */  addiu $v1, %lo(g_GlobalTimer) # addiu $v1, $v1, -0x7c84
/* 0649C4 7F02FE94 8C6E0000 */  lw    $t6, ($v1)
/* 0649C8 7F02FE98 24010001 */  li    $at, 1
/* 0649CC 7F02FE9C 00808025 */  move  $s0, $a0
/* 0649D0 7F02FEA0 8C820018 */  lw    $v0, 0x18($a0)
/* 0649D4 7F02FEA4 8C91001C */  lw    $s1, 0x1c($a0)
/* 0649D8 7F02FEA8 11E1000E */  beq   $t7, $at, .L7F02FEE4
/* 0649DC 7F02FEAC AC8E00C8 */   sw    $t6, 0xc8($a0)
/* 0649E0 7F02FEB0 8C790000 */  lw    $t9, ($v1)
/* 0649E4 7F02FEB4 8C9800CC */  lw    $t8, 0xcc($a0)
/* 0649E8 7F02FEB8 248400BC */  addiu $a0, $a0, 0xbc
/* 0649EC 7F02FEBC 2728FFC4 */  addiu $t0, $t9, -0x3c
/* 0649F0 7F02FEC0 0308082A */  slt   $at, $t8, $t0
/* 0649F4 7F02FEC4 14200007 */  bnez  $at, .L7F02FEE4
/* 0649F8 7F02FEC8 24450008 */   addiu $a1, $v0, 8
/* 0649FC 7F02FECC 2606002C */  addiu $a2, $s0, 0x2c
/* 064A00 7F02FED0 8E070038 */  lw    $a3, 0x38($s0)
/* 064A04 7F02FED4 0FC0BF54 */  jal   sub_GAME_7F02FD50
/* 064A08 7F02FED8 AFA60020 */   sw    $a2, 0x20($sp)
/* 064A0C 7F02FEDC 10400068 */  beqz  $v0, .L7F030080
/* 064A10 7F02FEE0 02002025 */   move  $a0, $s0
.L7F02FEE4:
/* 064A14 7F02FEE4 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 064A18 7F02FEE8 02202025 */   move  $a0, $s1
/* 064A1C 7F02FEEC 0FC1BD6F */  jal   objecthandlerGetModelField28
/* 064A20 7F02FEF0 02202025 */   move  $a0, $s1
/* 064A24 7F02FEF4 44803000 */  mtc1  $zero, $f6
/* 064A28 7F02FEF8 44802000 */  mtc1  $zero, $f4
/* 064A2C 7F02FEFC 02202025 */  move  $a0, $s1
/* 064A30 7F02FF00 4606003C */  c.lt.s $f0, $f6
/* 064A34 7F02FF04 46040081 */  sub.s $f2, $f0, $f4
/* 064A38 7F02FF08 4502000E */  bc1fl .L7F02FF44
/* 064A3C 7F02FF0C 02202025 */   move  $a0, $s1
/* 064A40 7F02FF10 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 064A44 7F02FF14 E7A20034 */   swc1  $f2, 0x34($sp)
/* 064A48 7F02FF18 94490004 */  lhu   $t1, 4($v0)
/* 064A4C 7F02FF1C C7A20034 */  lwc1  $f2, 0x34($sp)
/* 064A50 7F02FF20 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 064A54 7F02FF24 44894000 */  mtc1  $t1, $f8
/* 064A58 7F02FF28 05210004 */  bgez  $t1, .L7F02FF3C
/* 064A5C 7F02FF2C 468042A0 */   cvt.s.w $f10, $f8
/* 064A60 7F02FF30 44818000 */  mtc1  $at, $f16
/* 064A64 7F02FF34 00000000 */  nop   
/* 064A68 7F02FF38 46105280 */  add.s $f10, $f10, $f16
.L7F02FF3C:
/* 064A6C 7F02FF3C 460A1080 */  add.s $f2, $f2, $f10
/* 064A70 7F02FF40 02202025 */  move  $a0, $s1
.L7F02FF44:
/* 064A74 7F02FF44 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 064A78 7F02FF48 E7A20034 */   swc1  $f2, 0x34($sp)
/* 064A7C 7F02FF4C 944A0004 */  lhu   $t2, 4($v0)
/* 064A80 7F02FF50 C7A20034 */  lwc1  $f2, 0x34($sp)
/* 064A84 7F02FF54 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 064A88 7F02FF58 448A9000 */  mtc1  $t2, $f18
/* 064A8C 7F02FF5C 05410004 */  bgez  $t2, .L7F02FF70
/* 064A90 7F02FF60 46809120 */   cvt.s.w $f4, $f18
/* 064A94 7F02FF64 44813000 */  mtc1  $at, $f6
/* 064A98 7F02FF68 00000000 */  nop   
/* 064A9C 7F02FF6C 46062100 */  add.s $f4, $f4, $f6
.L7F02FF70:
/* 064AA0 7F02FF70 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 064AA4 7F02FF74 44814000 */  mtc1  $at, $f8
/* 064AA8 7F02FF78 00000000 */  nop   
/* 064AAC 7F02FF7C 46082402 */  mul.s $f16, $f4, $f8
/* 064AB0 7F02FF80 4602803C */  c.lt.s $f16, $f2
/* 064AB4 7F02FF84 00000000 */  nop   
/* 064AB8 7F02FF88 45000014 */  bc1f  .L7F02FFDC
/* 064ABC 7F02FF8C 00000000 */   nop   
/* 064AC0 7F02FF90 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 064AC4 7F02FF94 02202025 */   move  $a0, $s1
/* 064AC8 7F02FF98 944B0004 */  lhu   $t3, 4($v0)
/* 064ACC 7F02FF9C 44802000 */  mtc1  $zero, $f4
/* 064AD0 7F02FFA0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 064AD4 7F02FFA4 448B5000 */  mtc1  $t3, $f10
/* 064AD8 7F02FFA8 05610004 */  bgez  $t3, .L7F02FFBC
/* 064ADC 7F02FFAC 468054A0 */   cvt.s.w $f18, $f10
/* 064AE0 7F02FFB0 44813000 */  mtc1  $at, $f6
/* 064AE4 7F02FFB4 00000000 */  nop   
/* 064AE8 7F02FFB8 46069480 */  add.s $f18, $f18, $f6
.L7F02FFBC:
/* 064AEC 7F02FFBC 46049081 */  sub.s $f2, $f18, $f4
/* 064AF0 7F02FFC0 02202025 */  move  $a0, $s1
/* 064AF4 7F02FFC4 3C064180 */  lui   $a2, 0x4180
/* 064AF8 7F02FFC8 44051000 */  mfc1  $a1, $f2
/* 064AFC 7F02FFCC 0FC1BFA4 */  jal   sub_GAME_7F06FE90
/* 064B00 7F02FFD0 00000000 */   nop   
/* 064B04 7F02FFD4 10000026 */  b     .L7F030070
/* 064B08 7F02FFD8 00000000 */   nop   
.L7F02FFDC:
/* 064B0C 7F02FFDC 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 064B10 7F02FFE0 02202025 */   move  $a0, $s1
/* 064B14 7F02FFE4 944C0004 */  lhu   $t4, 4($v0)
/* 064B18 7F02FFE8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 064B1C 7F02FFEC 02202025 */  move  $a0, $s1
/* 064B20 7F02FFF0 448C4000 */  mtc1  $t4, $f8
/* 064B24 7F02FFF4 05810004 */  bgez  $t4, .L7F030008
/* 064B28 7F02FFF8 46804420 */   cvt.s.w $f16, $f8
/* 064B2C 7F02FFFC 44815000 */  mtc1  $at, $f10
/* 064B30 7F030000 00000000 */  nop   
/* 064B34 7F030004 460A8400 */  add.s $f16, $f16, $f10
.L7F030008:
/* 064B38 7F030008 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 064B3C 7F03000C 44813000 */  mtc1  $at, $f6
/* 064B40 7F030010 44802000 */  mtc1  $zero, $f4
/* 064B44 7F030014 44804000 */  mtc1  $zero, $f8
/* 064B48 7F030018 46068482 */  mul.s $f18, $f16, $f6
/* 064B4C 7F03001C 46049081 */  sub.s $f2, $f18, $f4
/* 064B50 7F030020 4608103C */  c.lt.s $f2, $f8
/* 064B54 7F030024 00000000 */  nop   
/* 064B58 7F030028 4502000E */  bc1fl .L7F030064
/* 064B5C 7F03002C 44051000 */   mfc1  $a1, $f2
/* 064B60 7F030030 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 064B64 7F030034 E7A20034 */   swc1  $f2, 0x34($sp)
/* 064B68 7F030038 944D0004 */  lhu   $t5, 4($v0)
/* 064B6C 7F03003C C7A20034 */  lwc1  $f2, 0x34($sp)
/* 064B70 7F030040 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 064B74 7F030044 448D5000 */  mtc1  $t5, $f10
/* 064B78 7F030048 05A10004 */  bgez  $t5, .L7F03005C
/* 064B7C 7F03004C 46805420 */   cvt.s.w $f16, $f10
/* 064B80 7F030050 44813000 */  mtc1  $at, $f6
/* 064B84 7F030054 00000000 */  nop   
/* 064B88 7F030058 46068400 */  add.s $f16, $f16, $f6
.L7F03005C:
/* 064B8C 7F03005C 46101080 */  add.s $f2, $f2, $f16
/* 064B90 7F030060 44051000 */  mfc1  $a1, $f2
.L7F030064:
/* 064B94 7F030064 02202025 */  move  $a0, $s1
/* 064B98 7F030068 0FC1BFA4 */  jal   sub_GAME_7F06FE90
/* 064B9C 7F03006C 3C064180 */   lui   $a2, 0x4180
.L7F030070:
/* 064BA0 7F030070 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 064BA4 7F030074 02002025 */   move  $a0, $s0
/* 064BA8 7F030078 10000027 */  b     .L7F030118
/* 064BAC 7F03007C 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F030080:
/* 064BB0 7F030080 8FA50020 */  lw    $a1, 0x20($sp)
/* 064BB4 7F030084 24060001 */  li    $a2, 1
/* 064BB8 7F030088 0FC0BDA4 */  jal   sub_GAME_7F02F690
/* 064BBC 7F03008C 26070040 */   addiu $a3, $s0, 0x40
/* 064BC0 7F030090 8E03003C */  lw    $v1, 0x3c($s0)
/* 064BC4 7F030094 3C0E8005 */  lui   $t6, %hi(g_ClockTimer) 
/* 064BC8 7F030098 3C018003 */  lui   $at, %hi(D_80030988)
/* 064BCC 7F03009C 18600005 */  blez  $v1, .L7F0300B4
/* 064BD0 7F0300A0 00000000 */   nop   
/* 064BD4 7F0300A4 8DCE8374 */  lw    $t6, %lo(g_ClockTimer)($t6)
/* 064BD8 7F0300A8 006E7823 */  subu  $t7, $v1, $t6
/* 064BDC 7F0300AC 10000019 */  b     .L7F030114
/* 064BE0 7F0300B0 AE0F003C */   sw    $t7, 0x3c($s0)
.L7F0300B4:
/* 064BE4 7F0300B4 C4320988 */  lwc1  $f18, %lo(D_80030988)($at)
/* 064BE8 7F0300B8 02202025 */  move  $a0, $s1
/* 064BEC 7F0300BC 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 064BF0 7F0300C0 E7B2002C */   swc1  $f18, 0x2c($sp)
/* 064BF4 7F0300C4 3C198007 */  lui   $t9, %hi(ptr_animation_table) 
/* 064BF8 7F0300C8 8F399538 */  lw    $t9, %lo(ptr_animation_table)($t9)
/* 064BFC 7F0300CC 3C180000 */  lui   $t8, %hi(0x0000777C) # $t8, 0
/* 064C00 7F0300D0 2718777C */  addiu $t8, %lo(0x0000777C) # addiu $t8, $t8, 0x777c
/* 064C04 7F0300D4 03384021 */  addu  $t0, $t9, $t8
/* 064C08 7F0300D8 14480003 */  bne   $v0, $t0, .L7F0300E8
/* 064C0C 7F0300DC 3C018003 */   lui   $at, %hi(D_80030994)
/* 064C10 7F0300E0 C4240994 */  lwc1  $f4, %lo(D_80030994)($at)
/* 064C14 7F0300E4 E7A4002C */  swc1  $f4, 0x2c($sp)
.L7F0300E8:
/* 064C18 7F0300E8 0FC1BD86 */  jal   sub_GAME_7F06F618
/* 064C1C 7F0300EC 02202025 */   move  $a0, $s1
/* 064C20 7F0300F0 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 064C24 7F0300F4 C42A8378 */  lwc1  $f10, %lo(g_GlobalTimerDelta)($at)
/* 064C28 7F0300F8 C7A8002C */  lwc1  $f8, 0x2c($sp)
/* 064C2C 7F0300FC C6120038 */  lwc1  $f18, 0x38($s0)
/* 064C30 7F030100 460A4182 */  mul.s $f6, $f8, $f10
/* 064C34 7F030104 00000000 */  nop   
/* 064C38 7F030108 46003402 */  mul.s $f16, $f6, $f0
/* 064C3C 7F03010C 46109100 */  add.s $f4, $f18, $f16
/* 064C40 7F030110 E6040038 */  swc1  $f4, 0x38($s0)
.L7F030114:
/* 064C44 7F030114 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F030118:
/* 064C48 7F030118 8FB00014 */  lw    $s0, 0x14($sp)
/* 064C4C 7F03011C 8FB10018 */  lw    $s1, 0x18($sp)
/* 064C50 7F030120 03E00008 */  jr    $ra
/* 064C54 7F030124 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F030128(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F030128
/* 064C58 7F030128 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 064C5C 7F03012C AFBF002C */  sw    $ra, 0x2c($sp)
/* 064C60 7F030130 AFA40048 */  sw    $a0, 0x48($sp)
/* 064C64 7F030134 AFA5004C */  sw    $a1, 0x4c($sp)
/* 064C68 7F030138 AFA60050 */  sw    $a2, 0x50($sp)
/* 064C6C 7F03013C AFA70054 */  sw    $a3, 0x54($sp)
/* 064C70 7F030140 AFA60044 */  sw    $a2, 0x44($sp)
/* 064C74 7F030144 AFA00040 */  sw    $zero, 0x40($sp)
/* 064C78 7F030148 8C840018 */  lw    $a0, 0x18($a0)
/* 064C7C 7F03014C 27A6003C */  addiu $a2, $sp, 0x3c
/* 064C80 7F030150 27A70038 */  addiu $a3, $sp, 0x38
/* 064C84 7F030154 0FC08C58 */  jal   chrGetChrWidthHeight
/* 064C88 7F030158 27A50034 */   addiu $a1, $sp, 0x34
/* 064C8C 7F03015C 8FA40048 */  lw    $a0, 0x48($sp)
/* 064C90 7F030160 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 064C94 7F030164 00002825 */   move  $a1, $zero
/* 064C98 7F030168 8FA2004C */  lw    $v0, 0x4c($sp)
/* 064C9C 7F03016C 8FA30054 */  lw    $v1, 0x54($sp)
/* 064CA0 7F030170 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 064CA4 7F030174 8C450000 */  lw    $a1, ($v0)
/* 064CA8 7F030178 C4640008 */  lwc1  $f4, 8($v1)
/* 064CAC 7F03017C 8C460008 */  lw    $a2, 8($v0)
/* 064CB0 7F030180 8C670000 */  lw    $a3, ($v1)
/* 064CB4 7F030184 44818000 */  mtc1  $at, $f16
/* 064CB8 7F030188 8FB8005C */  lw    $t8, 0x5c($sp)
/* 064CBC 7F03018C C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 064CC0 7F030190 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 064CC4 7F030194 44805000 */  mtc1  $zero, $f10
/* 064CC8 7F030198 27A40044 */  addiu $a0, $sp, 0x44
/* 064CCC 7F03019C E7A40010 */  swc1  $f4, 0x10($sp)
/* 064CD0 7F0301A0 AFB80014 */  sw    $t8, 0x14($sp)
/* 064CD4 7F0301A4 E7B00024 */  swc1  $f16, 0x24($sp)
/* 064CD8 7F0301A8 E7A60018 */  swc1  $f6, 0x18($sp)
/* 064CDC 7F0301AC E7A8001C */  swc1  $f8, 0x1c($sp)
/* 064CE0 7F0301B0 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 064CE4 7F0301B4 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 064CE8 7F0301B8 10400009 */  beqz  $v0, .L7F0301E0
/* 064CEC 7F0301BC 24050001 */   li    $a1, 1
/* 064CF0 7F0301C0 8FA20058 */  lw    $v0, 0x58($sp)
/* 064CF4 7F0301C4 8FB90044 */  lw    $t9, 0x44($sp)
/* 064CF8 7F0301C8 24080001 */  li    $t0, 1
/* 064CFC 7F0301CC 50400004 */  beql  $v0, $zero, .L7F0301E0
/* 064D00 7F0301D0 AFA80040 */   sw    $t0, 0x40($sp)
/* 064D04 7F0301D4 17220002 */  bne   $t9, $v0, .L7F0301E0
/* 064D08 7F0301D8 00000000 */   nop   
/* 064D0C 7F0301DC AFA80040 */  sw    $t0, 0x40($sp)
.L7F0301E0:
/* 064D10 7F0301E0 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 064D14 7F0301E4 8FA40048 */   lw    $a0, 0x48($sp)
/* 064D18 7F0301E8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 064D1C 7F0301EC 8FA20040 */  lw    $v0, 0x40($sp)
/* 064D20 7F0301F0 27BD0048 */  addiu $sp, $sp, 0x48
/* 064D24 7F0301F4 03E00008 */  jr    $ra
/* 064D28 7F0301F8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0301FC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0301FC
/* 064D2C 7F0301FC 27BDFF78 */  addiu $sp, $sp, -0x88
/* 064D30 7F030200 AFB10048 */  sw    $s1, 0x48($sp)
/* 064D34 7F030204 AFB00044 */  sw    $s0, 0x44($sp)
/* 064D38 7F030208 00A08025 */  move  $s0, $a1
/* 064D3C 7F03020C 00E08825 */  move  $s1, $a3
/* 064D40 7F030210 AFBF004C */  sw    $ra, 0x4c($sp)
/* 064D44 7F030214 F7B80038 */  sdc1  $f24, 0x38($sp)
/* 064D48 7F030218 F7B60030 */  sdc1  $f22, 0x30($sp)
/* 064D4C 7F03021C F7B40028 */  sdc1  $f20, 0x28($sp)
/* 064D50 7F030220 AFA40088 */  sw    $a0, 0x88($sp)
/* 064D54 7F030224 AFA60090 */  sw    $a2, 0x90($sp)
/* 064D58 7F030228 AFA00068 */  sw    $zero, 0x68($sp)
/* 064D5C 7F03022C 8C840018 */  lw    $a0, 0x18($a0)
/* 064D60 7F030230 27A60064 */  addiu $a2, $sp, 0x64
/* 064D64 7F030234 27A70060 */  addiu $a3, $sp, 0x60
/* 064D68 7F030238 0FC08C58 */  jal   chrGetChrWidthHeight
/* 064D6C 7F03023C 27A5005C */   addiu $a1, $sp, 0x5c
/* 064D70 7F030240 C6240000 */  lwc1  $f4, ($s1)
/* 064D74 7F030244 C6060000 */  lwc1  $f6, ($s0)
/* 064D78 7F030248 4480C000 */  mtc1  $zero, $f24
/* 064D7C 7F03024C 46062201 */  sub.s $f8, $f4, $f6
/* 064D80 7F030250 E7B8007C */  swc1  $f24, 0x7c($sp)
/* 064D84 7F030254 E7A80078 */  swc1  $f8, 0x78($sp)
/* 064D88 7F030258 C7A60078 */  lwc1  $f6, 0x78($sp)
/* 064D8C 7F03025C C6120008 */  lwc1  $f18, 8($s0)
/* 064D90 7F030260 C62A0008 */  lwc1  $f10, 8($s1)
/* 064D94 7F030264 4606C032 */  c.eq.s $f24, $f6
/* 064D98 7F030268 46125101 */  sub.s $f4, $f10, $f18
/* 064D9C 7F03026C 45000009 */  bc1f  .L7F030294
/* 064DA0 7F030270 E7A40080 */   swc1  $f4, 0x80($sp)
/* 064DA4 7F030274 C7B00080 */  lwc1  $f16, 0x80($sp)
/* 064DA8 7F030278 240F0001 */  li    $t7, 1
/* 064DAC 7F03027C 4610C032 */  c.eq.s $f24, $f16
/* 064DB0 7F030280 00000000 */  nop   
/* 064DB4 7F030284 45020004 */  bc1fl .L7F030298
/* 064DB8 7F030288 C7B00080 */   lwc1  $f16, 0x80($sp)
/* 064DBC 7F03028C 1000007E */  b     .L7F030488
/* 064DC0 7F030290 AFAF0068 */   sw    $t7, 0x68($sp)
.L7F030294:
/* 064DC4 7F030294 C7B00080 */  lwc1  $f16, 0x80($sp)
.L7F030298:
/* 064DC8 7F030298 C7AE0078 */  lwc1  $f14, 0x78($sp)
/* 064DCC 7F03029C 46108202 */  mul.s $f8, $f16, $f16
/* 064DD0 7F0302A0 00000000 */  nop   
/* 064DD4 7F0302A4 460E7282 */  mul.s $f10, $f14, $f14
/* 064DD8 7F0302A8 0C007DF8 */  jal   sqrtf
/* 064DDC 7F0302AC 460A4300 */   add.s $f12, $f8, $f10
/* 064DE0 7F0302B0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 064DE4 7F0302B4 44819000 */  mtc1  $at, $f18
/* 064DE8 7F0302B8 C7AE0078 */  lwc1  $f14, 0x78($sp)
/* 064DEC 7F0302BC C7B00080 */  lwc1  $f16, 0x80($sp)
/* 064DF0 7F0302C0 46009083 */  div.s $f2, $f18, $f0
/* 064DF4 7F0302C4 C7AC0098 */  lwc1  $f12, 0x98($sp)
/* 064DF8 7F0302C8 8FA40088 */  lw    $a0, 0x88($sp)
/* 064DFC 7F0302CC 00002825 */  move  $a1, $zero
/* 064E00 7F0302D0 46027382 */  mul.s $f14, $f14, $f2
/* 064E04 7F0302D4 00000000 */  nop   
/* 064E08 7F0302D8 46028402 */  mul.s $f16, $f16, $f2
/* 064E0C 7F0302DC 00000000 */  nop   
/* 064E10 7F0302E0 460C7502 */  mul.s $f20, $f14, $f12
/* 064E14 7F0302E4 E7AE0078 */  swc1  $f14, 0x78($sp)
/* 064E18 7F0302E8 460C8582 */  mul.s $f22, $f16, $f12
/* 064E1C 7F0302EC 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 064E20 7F0302F0 E7B00080 */   swc1  $f16, 0x80($sp)
/* 064E24 7F0302F4 8FB80090 */  lw    $t8, 0x90($sp)
/* 064E28 7F0302F8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 064E2C 7F0302FC 44819000 */  mtc1  $at, $f18
/* 064E30 7F030300 AFB80084 */  sw    $t8, 0x84($sp)
/* 064E34 7F030304 C6000000 */  lwc1  $f0, ($s0)
/* 064E38 7F030308 C6020008 */  lwc1  $f2, 8($s0)
/* 064E3C 7F03030C 8FB9009C */  lw    $t9, 0x9c($sp)
/* 064E40 7F030310 46160100 */  add.s $f4, $f0, $f22
/* 064E44 7F030314 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 064E48 7F030318 C7AA0060 */  lwc1  $f10, 0x60($sp)
/* 064E4C 7F03031C 46141181 */  sub.s $f6, $f2, $f20
/* 064E50 7F030320 44072000 */  mfc1  $a3, $f4
/* 064E54 7F030324 44050000 */  mfc1  $a1, $f0
/* 064E58 7F030328 44061000 */  mfc1  $a2, $f2
/* 064E5C 7F03032C E7A60010 */  swc1  $f6, 0x10($sp)
/* 064E60 7F030330 E7B80020 */  swc1  $f24, 0x20($sp)
/* 064E64 7F030334 27A40084 */  addiu $a0, $sp, 0x84
/* 064E68 7F030338 E7B20024 */  swc1  $f18, 0x24($sp)
/* 064E6C 7F03033C AFB90014 */  sw    $t9, 0x14($sp)
/* 064E70 7F030340 E7A80018 */  swc1  $f8, 0x18($sp)
/* 064E74 7F030344 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 064E78 7F030348 E7AA001C */   swc1  $f10, 0x1c($sp)
/* 064E7C 7F03034C 1040004B */  beqz  $v0, .L7F03047C
/* 064E80 7F030350 27A40084 */   addiu $a0, $sp, 0x84
/* 064E84 7F030354 C6040000 */  lwc1  $f4, ($s0)
/* 064E88 7F030358 C6080008 */  lwc1  $f8, 8($s0)
/* 064E8C 7F03035C C6320000 */  lwc1  $f18, ($s1)
/* 064E90 7F030360 46162180 */  add.s $f6, $f4, $f22
/* 064E94 7F030364 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 064E98 7F030368 8FA8009C */  lw    $t0, 0x9c($sp)
/* 064E9C 7F03036C 46144281 */  sub.s $f10, $f8, $f20
/* 064EA0 7F030370 44053000 */  mfc1  $a1, $f6
/* 064EA4 7F030374 C6260008 */  lwc1  $f6, 8($s1)
/* 064EA8 7F030378 46169100 */  add.s $f4, $f18, $f22
/* 064EAC 7F03037C 44065000 */  mfc1  $a2, $f10
/* 064EB0 7F030380 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 064EB4 7F030384 46143201 */  sub.s $f8, $f6, $f20
/* 064EB8 7F030388 44072000 */  mfc1  $a3, $f4
/* 064EBC 7F03038C 44812000 */  mtc1  $at, $f4
/* 064EC0 7F030390 C7B20060 */  lwc1  $f18, 0x60($sp)
/* 064EC4 7F030394 E7A80010 */  swc1  $f8, 0x10($sp)
/* 064EC8 7F030398 E7B80020 */  swc1  $f24, 0x20($sp)
/* 064ECC 7F03039C AFA80014 */  sw    $t0, 0x14($sp)
/* 064ED0 7F0303A0 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 064ED4 7F0303A4 E7B2001C */  swc1  $f18, 0x1c($sp)
/* 064ED8 7F0303A8 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 064EDC 7F0303AC E7A40024 */   swc1  $f4, 0x24($sp)
/* 064EE0 7F0303B0 10400032 */  beqz  $v0, .L7F03047C
/* 064EE4 7F0303B4 8FA90090 */   lw    $t1, 0x90($sp)
/* 064EE8 7F0303B8 AFA90084 */  sw    $t1, 0x84($sp)
/* 064EEC 7F0303BC C6000000 */  lwc1  $f0, ($s0)
/* 064EF0 7F0303C0 C6020008 */  lwc1  $f2, 8($s0)
/* 064EF4 7F0303C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 064EF8 7F0303C8 46160181 */  sub.s $f6, $f0, $f22
/* 064EFC 7F0303CC 44812000 */  mtc1  $at, $f4
/* 064F00 7F0303D0 8FAA009C */  lw    $t2, 0x9c($sp)
/* 064F04 7F0303D4 46141200 */  add.s $f8, $f2, $f20
/* 064F08 7F0303D8 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 064F0C 7F0303DC C7B20060 */  lwc1  $f18, 0x60($sp)
/* 064F10 7F0303E0 44073000 */  mfc1  $a3, $f6
/* 064F14 7F0303E4 44050000 */  mfc1  $a1, $f0
/* 064F18 7F0303E8 44061000 */  mfc1  $a2, $f2
/* 064F1C 7F0303EC E7A80010 */  swc1  $f8, 0x10($sp)
/* 064F20 7F0303F0 E7B80020 */  swc1  $f24, 0x20($sp)
/* 064F24 7F0303F4 27A40084 */  addiu $a0, $sp, 0x84
/* 064F28 7F0303F8 AFAA0014 */  sw    $t2, 0x14($sp)
/* 064F2C 7F0303FC E7A40024 */  swc1  $f4, 0x24($sp)
/* 064F30 7F030400 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 064F34 7F030404 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 064F38 7F030408 E7B2001C */   swc1  $f18, 0x1c($sp)
/* 064F3C 7F03040C 1040001B */  beqz  $v0, .L7F03047C
/* 064F40 7F030410 27A40084 */   addiu $a0, $sp, 0x84
/* 064F44 7F030414 C6060000 */  lwc1  $f6, ($s0)
/* 064F48 7F030418 C60A0008 */  lwc1  $f10, 8($s0)
/* 064F4C 7F03041C C6240000 */  lwc1  $f4, ($s1)
/* 064F50 7F030420 46163201 */  sub.s $f8, $f6, $f22
/* 064F54 7F030424 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 064F58 7F030428 8FAB009C */  lw    $t3, 0x9c($sp)
/* 064F5C 7F03042C 46145480 */  add.s $f18, $f10, $f20
/* 064F60 7F030430 44054000 */  mfc1  $a1, $f8
/* 064F64 7F030434 C6280008 */  lwc1  $f8, 8($s1)
/* 064F68 7F030438 46162181 */  sub.s $f6, $f4, $f22
/* 064F6C 7F03043C 44069000 */  mfc1  $a2, $f18
/* 064F70 7F030440 C7B20064 */  lwc1  $f18, 0x64($sp)
/* 064F74 7F030444 46144280 */  add.s $f10, $f8, $f20
/* 064F78 7F030448 44073000 */  mfc1  $a3, $f6
/* 064F7C 7F03044C 44813000 */  mtc1  $at, $f6
/* 064F80 7F030450 C7A40060 */  lwc1  $f4, 0x60($sp)
/* 064F84 7F030454 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 064F88 7F030458 E7B80020 */  swc1  $f24, 0x20($sp)
/* 064F8C 7F03045C AFAB0014 */  sw    $t3, 0x14($sp)
/* 064F90 7F030460 E7B20018 */  swc1  $f18, 0x18($sp)
/* 064F94 7F030464 E7A4001C */  swc1  $f4, 0x1c($sp)
/* 064F98 7F030468 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 064F9C 7F03046C E7A60024 */   swc1  $f6, 0x24($sp)
/* 064FA0 7F030470 10400002 */  beqz  $v0, .L7F03047C
/* 064FA4 7F030474 240C0001 */   li    $t4, 1
/* 064FA8 7F030478 AFAC0068 */  sw    $t4, 0x68($sp)
.L7F03047C:
/* 064FAC 7F03047C 8FA40088 */  lw    $a0, 0x88($sp)
/* 064FB0 7F030480 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 064FB4 7F030484 24050001 */   li    $a1, 1
.L7F030488:
/* 064FB8 7F030488 8FBF004C */  lw    $ra, 0x4c($sp)
/* 064FBC 7F03048C 8FA20068 */  lw    $v0, 0x68($sp)
/* 064FC0 7F030490 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 064FC4 7F030494 D7B60030 */  ldc1  $f22, 0x30($sp)
/* 064FC8 7F030498 D7B80038 */  ldc1  $f24, 0x38($sp)
/* 064FCC 7F03049C 8FB00044 */  lw    $s0, 0x44($sp)
/* 064FD0 7F0304A0 8FB10048 */  lw    $s1, 0x48($sp)
/* 064FD4 7F0304A4 03E00008 */  jr    $ra
/* 064FD8 7F0304A8 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0304AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0304AC
/* 064FDC 7F0304AC 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 064FE0 7F0304B0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 064FE4 7F0304B4 AFA40048 */  sw    $a0, 0x48($sp)
/* 064FE8 7F0304B8 AFA5004C */  sw    $a1, 0x4c($sp)
/* 064FEC 7F0304BC AFA60050 */  sw    $a2, 0x50($sp)
/* 064FF0 7F0304C0 AFA70054 */  sw    $a3, 0x54($sp)
/* 064FF4 7F0304C4 AFA60044 */  sw    $a2, 0x44($sp)
/* 064FF8 7F0304C8 AFA00040 */  sw    $zero, 0x40($sp)
/* 064FFC 7F0304CC 8C840018 */  lw    $a0, 0x18($a0)
/* 065000 7F0304D0 27A6003C */  addiu $a2, $sp, 0x3c
/* 065004 7F0304D4 27A70038 */  addiu $a3, $sp, 0x38
/* 065008 7F0304D8 0FC08C58 */  jal   chrGetChrWidthHeight
/* 06500C 7F0304DC 27A50034 */   addiu $a1, $sp, 0x34
/* 065010 7F0304E0 8FA40048 */  lw    $a0, 0x48($sp)
/* 065014 7F0304E4 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 065018 7F0304E8 00002825 */   move  $a1, $zero
/* 06501C 7F0304EC 8FA20054 */  lw    $v0, 0x54($sp)
/* 065020 7F0304F0 8FA3004C */  lw    $v1, 0x4c($sp)
/* 065024 7F0304F4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065028 7F0304F8 C4440008 */  lwc1  $f4, 8($v0)
/* 06502C 7F0304FC 8C470000 */  lw    $a3, ($v0)
/* 065030 7F030500 8C650000 */  lw    $a1, ($v1)
/* 065034 7F030504 8C660008 */  lw    $a2, 8($v1)
/* 065038 7F030508 44818000 */  mtc1  $at, $f16
/* 06503C 7F03050C 8FB80060 */  lw    $t8, 0x60($sp)
/* 065040 7F030510 C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 065044 7F030514 C7A80038 */  lwc1  $f8, 0x38($sp)
/* 065048 7F030518 44805000 */  mtc1  $zero, $f10
/* 06504C 7F03051C 27A40044 */  addiu $a0, $sp, 0x44
/* 065050 7F030520 E7A40010 */  swc1  $f4, 0x10($sp)
/* 065054 7F030524 AFB80014 */  sw    $t8, 0x14($sp)
/* 065058 7F030528 E7B00024 */  swc1  $f16, 0x24($sp)
/* 06505C 7F03052C E7A60018 */  swc1  $f6, 0x18($sp)
/* 065060 7F030530 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 065064 7F030534 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 065068 7F030538 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 06506C 7F03053C 10400020 */  beqz  $v0, .L7F0305C0
/* 065070 7F030540 8FB90044 */   lw    $t9, 0x44($sp)
/* 065074 7F030544 8FA20058 */  lw    $v0, 0x58($sp)
/* 065078 7F030548 8FA80054 */  lw    $t0, 0x54($sp)
/* 06507C 7F03054C AFB90030 */  sw    $t9, 0x30($sp)
/* 065080 7F030550 C4520008 */  lwc1  $f18, 8($v0)
/* 065084 7F030554 8C470000 */  lw    $a3, ($v0)
/* 065088 7F030558 8D060008 */  lw    $a2, 8($t0)
/* 06508C 7F03055C 8D050000 */  lw    $a1, ($t0)
/* 065090 7F030560 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065094 7F030564 44815000 */  mtc1  $at, $f10
/* 065098 7F030568 8FA90060 */  lw    $t1, 0x60($sp)
/* 06509C 7F03056C C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 0650A0 7F030570 C7A60038 */  lwc1  $f6, 0x38($sp)
/* 0650A4 7F030574 44804000 */  mtc1  $zero, $f8
/* 0650A8 7F030578 27A40030 */  addiu $a0, $sp, 0x30
/* 0650AC 7F03057C E7B20010 */  swc1  $f18, 0x10($sp)
/* 0650B0 7F030580 AFA90014 */  sw    $t1, 0x14($sp)
/* 0650B4 7F030584 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 0650B8 7F030588 E7A40018 */  swc1  $f4, 0x18($sp)
/* 0650BC 7F03058C E7A6001C */  swc1  $f6, 0x1c($sp)
/* 0650C0 7F030590 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 0650C4 7F030594 E7A80020 */   swc1  $f8, 0x20($sp)
/* 0650C8 7F030598 5040000A */  beql  $v0, $zero, .L7F0305C4
/* 0650CC 7F03059C 8FA40048 */   lw    $a0, 0x48($sp)
/* 0650D0 7F0305A0 8FA2005C */  lw    $v0, 0x5c($sp)
/* 0650D4 7F0305A4 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0650D8 7F0305A8 240B0001 */  li    $t3, 1
/* 0650DC 7F0305AC 50400004 */  beql  $v0, $zero, .L7F0305C0
/* 0650E0 7F0305B0 AFAB0040 */   sw    $t3, 0x40($sp)
/* 0650E4 7F0305B4 55420003 */  bnel  $t2, $v0, .L7F0305C4
/* 0650E8 7F0305B8 8FA40048 */   lw    $a0, 0x48($sp)
/* 0650EC 7F0305BC AFAB0040 */  sw    $t3, 0x40($sp)
.L7F0305C0:
/* 0650F0 7F0305C0 8FA40048 */  lw    $a0, 0x48($sp)
.L7F0305C4:
/* 0650F4 7F0305C4 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 0650F8 7F0305C8 24050001 */   li    $a1, 1
/* 0650FC 7F0305CC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 065100 7F0305D0 8FA20040 */  lw    $v0, 0x40($sp)
/* 065104 7F0305D4 27BD0048 */  addiu $sp, $sp, 0x48
/* 065108 7F0305D8 03E00008 */  jr    $ra
/* 06510C 7F0305DC 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0305E0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0305E0
/* 065110 7F0305E0 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 065114 7F0305E4 AFB10030 */  sw    $s1, 0x30($sp)
/* 065118 7F0305E8 AFB0002C */  sw    $s0, 0x2c($sp)
/* 06511C 7F0305EC 00E08025 */  move  $s0, $a3
/* 065120 7F0305F0 00808825 */  move  $s1, $a0
/* 065124 7F0305F4 AFBF0034 */  sw    $ra, 0x34($sp)
/* 065128 7F0305F8 AFA50054 */  sw    $a1, 0x54($sp)
/* 06512C 7F0305FC AFA60058 */  sw    $a2, 0x58($sp)
/* 065130 7F030600 AFA6004C */  sw    $a2, 0x4c($sp)
/* 065134 7F030604 AFA00048 */  sw    $zero, 0x48($sp)
/* 065138 7F030608 8C840018 */  lw    $a0, 0x18($a0)
/* 06513C 7F03060C 27A60044 */  addiu $a2, $sp, 0x44
/* 065140 7F030610 27A5003C */  addiu $a1, $sp, 0x3c
/* 065144 7F030614 0FC08C58 */  jal   chrGetChrWidthHeight
/* 065148 7F030618 27A70040 */   addiu $a3, $sp, 0x40
/* 06514C 7F03061C 02202025 */  move  $a0, $s1
/* 065150 7F030620 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 065154 7F030624 00002825 */   move  $a1, $zero
/* 065158 7F030628 8FA20054 */  lw    $v0, 0x54($sp)
/* 06515C 7F03062C C6040008 */  lwc1  $f4, 8($s0)
/* 065160 7F030630 8E070000 */  lw    $a3, ($s0)
/* 065164 7F030634 8C450000 */  lw    $a1, ($v0)
/* 065168 7F030638 8C460008 */  lw    $a2, 8($v0)
/* 06516C 7F03063C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065170 7F030640 44818000 */  mtc1  $at, $f16
/* 065174 7F030644 8FAF0068 */  lw    $t7, 0x68($sp)
/* 065178 7F030648 C7A60044 */  lwc1  $f6, 0x44($sp)
/* 06517C 7F03064C C7A80040 */  lwc1  $f8, 0x40($sp)
/* 065180 7F030650 44805000 */  mtc1  $zero, $f10
/* 065184 7F030654 27A4004C */  addiu $a0, $sp, 0x4c
/* 065188 7F030658 E7A40010 */  swc1  $f4, 0x10($sp)
/* 06518C 7F03065C AFAF0014 */  sw    $t7, 0x14($sp)
/* 065190 7F030660 E7B00024 */  swc1  $f16, 0x24($sp)
/* 065194 7F030664 E7A60018 */  swc1  $f6, 0x18($sp)
/* 065198 7F030668 E7A8001C */  swc1  $f8, 0x1c($sp)
/* 06519C 7F03066C 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 0651A0 7F030670 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 0651A4 7F030674 1040002C */  beqz  $v0, .L7F030728
/* 0651A8 7F030678 8FB8004C */   lw    $t8, 0x4c($sp)
/* 0651AC 7F03067C 8FA20060 */  lw    $v0, 0x60($sp)
/* 0651B0 7F030680 AFB80038 */  sw    $t8, 0x38($sp)
/* 0651B4 7F030684 8E060008 */  lw    $a2, 8($s0)
/* 0651B8 7F030688 C4520008 */  lwc1  $f18, 8($v0)
/* 0651BC 7F03068C 8E050000 */  lw    $a1, ($s0)
/* 0651C0 7F030690 8C470000 */  lw    $a3, ($v0)
/* 0651C4 7F030694 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0651C8 7F030698 44815000 */  mtc1  $at, $f10
/* 0651CC 7F03069C 8FB90068 */  lw    $t9, 0x68($sp)
/* 0651D0 7F0306A0 C7A40044 */  lwc1  $f4, 0x44($sp)
/* 0651D4 7F0306A4 C7A60040 */  lwc1  $f6, 0x40($sp)
/* 0651D8 7F0306A8 44804000 */  mtc1  $zero, $f8
/* 0651DC 7F0306AC 27A40038 */  addiu $a0, $sp, 0x38
/* 0651E0 7F0306B0 E7B20010 */  swc1  $f18, 0x10($sp)
/* 0651E4 7F0306B4 AFB90014 */  sw    $t9, 0x14($sp)
/* 0651E8 7F0306B8 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 0651EC 7F0306BC E7A40018 */  swc1  $f4, 0x18($sp)
/* 0651F0 7F0306C0 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 0651F4 7F0306C4 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 0651F8 7F0306C8 E7A80020 */   swc1  $f8, 0x20($sp)
/* 0651FC 7F0306CC 10400016 */  beqz  $v0, .L7F030728
/* 065200 7F0306D0 02202025 */   move  $a0, $s1
/* 065204 7F0306D4 C7B00064 */  lwc1  $f16, 0x64($sp)
/* 065208 7F0306D8 8FA80068 */  lw    $t0, 0x68($sp)
/* 06520C 7F0306DC 8FA50054 */  lw    $a1, 0x54($sp)
/* 065210 7F0306E0 8FA60058 */  lw    $a2, 0x58($sp)
/* 065214 7F0306E4 02003825 */  move  $a3, $s0
/* 065218 7F0306E8 E7B00010 */  swc1  $f16, 0x10($sp)
/* 06521C 7F0306EC 0FC0C07F */  jal   sub_GAME_7F0301FC
/* 065220 7F0306F0 AFA80014 */   sw    $t0, 0x14($sp)
/* 065224 7F0306F4 1040000C */  beqz  $v0, .L7F030728
/* 065228 7F0306F8 02202025 */   move  $a0, $s1
/* 06522C 7F0306FC C7B20064 */  lwc1  $f18, 0x64($sp)
/* 065230 7F030700 8FA90068 */  lw    $t1, 0x68($sp)
/* 065234 7F030704 02002825 */  move  $a1, $s0
/* 065238 7F030708 8FA6004C */  lw    $a2, 0x4c($sp)
/* 06523C 7F03070C 8FA70060 */  lw    $a3, 0x60($sp)
/* 065240 7F030710 E7B20010 */  swc1  $f18, 0x10($sp)
/* 065244 7F030714 0FC0C07F */  jal   sub_GAME_7F0301FC
/* 065248 7F030718 AFA90014 */   sw    $t1, 0x14($sp)
/* 06524C 7F03071C 10400002 */  beqz  $v0, .L7F030728
/* 065250 7F030720 240A0001 */   li    $t2, 1
/* 065254 7F030724 AFAA0048 */  sw    $t2, 0x48($sp)
.L7F030728:
/* 065258 7F030728 02202025 */  move  $a0, $s1
/* 06525C 7F03072C 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 065260 7F030730 24050001 */   li    $a1, 1
/* 065264 7F030734 8FBF0034 */  lw    $ra, 0x34($sp)
/* 065268 7F030738 8FA20048 */  lw    $v0, 0x48($sp)
/* 06526C 7F03073C 8FB0002C */  lw    $s0, 0x2c($sp)
/* 065270 7F030740 8FB10030 */  lw    $s1, 0x30($sp)
/* 065274 7F030744 03E00008 */  jr    $ra
/* 065278 7F030748 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F03074C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03074C
/* 06527C 7F03074C C4A40000 */  lwc1  $f4, ($a1)
/* 065280 7F030750 C4860000 */  lwc1  $f6, ($a0)
/* 065284 7F030754 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 065288 7F030758 44800000 */  mtc1  $zero, $f0
/* 06528C 7F03075C 46062201 */  sub.s $f8, $f4, $f6
/* 065290 7F030760 E7A8000C */  swc1  $f8, 0xc($sp)
/* 065294 7F030764 C4900004 */  lwc1  $f16, 4($a0)
/* 065298 7F030768 C4AA0004 */  lwc1  $f10, 4($a1)
/* 06529C 7F03076C 46105481 */  sub.s $f18, $f10, $f16
/* 0652A0 7F030770 E7B20010 */  swc1  $f18, 0x10($sp)
/* 0652A4 7F030774 C4860008 */  lwc1  $f6, 8($a0)
/* 0652A8 7F030778 C4A40008 */  lwc1  $f4, 8($a1)
/* 0652AC 7F03077C 46062201 */  sub.s $f8, $f4, $f6
/* 0652B0 7F030780 E7A80014 */  swc1  $f8, 0x14($sp)
/* 0652B4 7F030784 C4CA0008 */  lwc1  $f10, 8($a2)
/* 0652B8 7F030788 E7A00004 */  swc1  $f0, 4($sp)
/* 0652BC 7F03078C C7A40014 */  lwc1  $f4, 0x14($sp)
/* 0652C0 7F030790 46005407 */  neg.s $f16, $f10
/* 0652C4 7F030794 E7B00000 */  swc1  $f16, ($sp)
/* 0652C8 7F030798 C4D20000 */  lwc1  $f18, ($a2)
/* 0652CC 7F03079C C7AA0000 */  lwc1  $f10, ($sp)
/* 0652D0 7F0307A0 C7B0000C */  lwc1  $f16, 0xc($sp)
/* 0652D4 7F0307A4 E7B20008 */  swc1  $f18, 8($sp)
/* 0652D8 7F0307A8 C7A60008 */  lwc1  $f6, 8($sp)
/* 0652DC 7F0307AC 46062202 */  mul.s $f8, $f4, $f6
/* 0652E0 7F0307B0 00000000 */  nop   
/* 0652E4 7F0307B4 46105482 */  mul.s $f18, $f10, $f16
/* 0652E8 7F0307B8 46124100 */  add.s $f4, $f8, $f18
/* 0652EC 7F0307BC 4604003C */  c.lt.s $f0, $f4
/* 0652F0 7F0307C0 00000000 */  nop   
/* 0652F4 7F0307C4 45010013 */  bc1t  .L7F030814
/* 0652F8 7F0307C8 00000000 */   nop   
/* 0652FC 7F0307CC C4860000 */  lwc1  $f6, ($a0)
/* 065300 7F0307D0 E7A6000C */  swc1  $f6, 0xc($sp)
/* 065304 7F0307D4 C48A0004 */  lwc1  $f10, 4($a0)
/* 065308 7F0307D8 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 06530C 7F0307DC C4900008 */  lwc1  $f16, 8($a0)
/* 065310 7F0307E0 E7B00014 */  swc1  $f16, 0x14($sp)
/* 065314 7F0307E4 C4A80000 */  lwc1  $f8, ($a1)
/* 065318 7F0307E8 E4880000 */  swc1  $f8, ($a0)
/* 06531C 7F0307EC C4B20004 */  lwc1  $f18, 4($a1)
/* 065320 7F0307F0 E4920004 */  swc1  $f18, 4($a0)
/* 065324 7F0307F4 C4A40008 */  lwc1  $f4, 8($a1)
/* 065328 7F0307F8 E4840008 */  swc1  $f4, 8($a0)
/* 06532C 7F0307FC C7A6000C */  lwc1  $f6, 0xc($sp)
/* 065330 7F030800 E4A60000 */  swc1  $f6, ($a1)
/* 065334 7F030804 C7AA0010 */  lwc1  $f10, 0x10($sp)
/* 065338 7F030808 E4AA0004 */  swc1  $f10, 4($a1)
/* 06533C 7F03080C C7B00014 */  lwc1  $f16, 0x14($sp)
/* 065340 7F030810 E4B00008 */  swc1  $f16, 8($a1)
.L7F030814:
/* 065344 7F030814 03E00008 */  jr    $ra
/* 065348 7F030818 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F03081C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80052014
.word 0x3f733333 /*0.94999999*/
glabel D_80052018
.word 0x3f733333 /*0.94999999*/
glabel D_8005201C
.word 0x3f99999a /*1.2*/
glabel D_80052020
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F03081C
/* 06534C 7F03081C 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 065350 7F030820 AFB00030 */  sw    $s0, 0x30($sp)
/* 065354 7F030824 00A08025 */  move  $s0, $a1
/* 065358 7F030828 AFBF0034 */  sw    $ra, 0x34($sp)
/* 06535C 7F03082C AFA400B0 */  sw    $a0, 0xb0($sp)
/* 065360 7F030830 AFA600B8 */  sw    $a2, 0xb8($sp)
/* 065364 7F030834 AFA700BC */  sw    $a3, 0xbc($sp)
/* 065368 7F030838 AFA00088 */  sw    $zero, 0x88($sp)
/* 06536C 7F03083C AFA00084 */  sw    $zero, 0x84($sp)
/* 065370 7F030840 AFA00050 */  sw    $zero, 0x50($sp)
/* 065374 7F030844 8C840018 */  lw    $a0, 0x18($a0)
/* 065378 7F030848 27A70048 */  addiu $a3, $sp, 0x48
/* 06537C 7F03084C 27A6004C */  addiu $a2, $sp, 0x4c
/* 065380 7F030850 0FC08C58 */  jal   chrGetChrWidthHeight
/* 065384 7F030854 27A50044 */   addiu $a1, $sp, 0x44
/* 065388 7F030858 8FA200BC */  lw    $v0, 0xbc($sp)
/* 06538C 7F03085C C6060000 */  lwc1  $f6, ($s0)
/* 065390 7F030860 44800000 */  mtc1  $zero, $f0
/* 065394 7F030864 C4440000 */  lwc1  $f4, ($v0)
/* 065398 7F030868 E7A000A4 */  swc1  $f0, 0xa4($sp)
/* 06539C 7F03086C 46062201 */  sub.s $f8, $f4, $f6
/* 0653A0 7F030870 E7A800A0 */  swc1  $f8, 0xa0($sp)
/* 0653A4 7F030874 C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 0653A8 7F030878 C6040008 */  lwc1  $f4, 8($s0)
/* 0653AC 7F03087C C44A0008 */  lwc1  $f10, 8($v0)
/* 0653B0 7F030880 46080032 */  c.eq.s $f0, $f8
/* 0653B4 7F030884 46045181 */  sub.s $f6, $f10, $f4
/* 0653B8 7F030888 45000008 */  bc1f  .L7F0308AC
/* 0653BC 7F03088C E7A600A8 */   swc1  $f6, 0xa8($sp)
/* 0653C0 7F030890 C7B200A8 */  lwc1  $f18, 0xa8($sp)
/* 0653C4 7F030894 46120032 */  c.eq.s $f0, $f18
/* 0653C8 7F030898 00000000 */  nop   
/* 0653CC 7F03089C 45020004 */  bc1fl .L7F0308B0
/* 0653D0 7F0308A0 C7B200A8 */   lwc1  $f18, 0xa8($sp)
/* 0653D4 7F0308A4 1000012D */  b     .L7F030D5C
/* 0653D8 7F0308A8 24020001 */   li    $v0, 1
.L7F0308AC:
/* 0653DC 7F0308AC C7B200A8 */  lwc1  $f18, 0xa8($sp)
.L7F0308B0:
/* 0653E0 7F0308B0 C7B000A0 */  lwc1  $f16, 0xa0($sp)
/* 0653E4 7F0308B4 46129282 */  mul.s $f10, $f18, $f18
/* 0653E8 7F0308B8 00000000 */  nop   
/* 0653EC 7F0308BC 46108102 */  mul.s $f4, $f16, $f16
/* 0653F0 7F0308C0 0C007DF8 */  jal   sqrtf
/* 0653F4 7F0308C4 46045300 */   add.s $f12, $f10, $f4
/* 0653F8 7F0308C8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0653FC 7F0308CC 44813000 */  mtc1  $at, $f6
/* 065400 7F0308D0 C7B000A0 */  lwc1  $f16, 0xa0($sp)
/* 065404 7F0308D4 C7B200A8 */  lwc1  $f18, 0xa8($sp)
/* 065408 7F0308D8 46003083 */  div.s $f2, $f6, $f0
/* 06540C 7F0308DC C7A800CC */  lwc1  $f8, 0xcc($sp)
/* 065410 7F0308E0 3C018005 */  lui   $at, %hi(D_80052014)
/* 065414 7F0308E4 C42A2014 */  lwc1  $f10, %lo(D_80052014)($at)
/* 065418 7F0308E8 3C018005 */  lui   $at, %hi(D_80052018)
/* 06541C 7F0308EC C4262018 */  lwc1  $f6, %lo(D_80052018)($at)
/* 065420 7F0308F0 3C018005 */  lui   $at, %hi(D_8005201C)
/* 065424 7F0308F4 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 065428 7F0308F8 00002825 */  move  $a1, $zero
/* 06542C 7F0308FC 46028402 */  mul.s $f16, $f16, $f2
/* 065430 7F030900 00000000 */  nop   
/* 065434 7F030904 46029482 */  mul.s $f18, $f18, $f2
/* 065438 7F030908 00000000 */  nop   
/* 06543C 7F03090C 46088302 */  mul.s $f12, $f16, $f8
/* 065440 7F030910 E7B000A0 */  swc1  $f16, 0xa0($sp)
/* 065444 7F030914 E7B200A8 */  swc1  $f18, 0xa8($sp)
/* 065448 7F030918 460A6102 */  mul.s $f4, $f12, $f10
/* 06544C 7F03091C 00000000 */  nop   
/* 065450 7F030920 46089382 */  mul.s $f14, $f18, $f8
/* 065454 7F030924 E7A4009C */  swc1  $f4, 0x9c($sp)
/* 065458 7F030928 C424201C */  lwc1  $f4, %lo(D_8005201C)($at)
/* 06545C 7F03092C 3C018005 */  lui   $at, %hi(D_80052020)
/* 065460 7F030930 46067282 */  mul.s $f10, $f14, $f6
/* 065464 7F030934 C4262020 */  lwc1  $f6, %lo(D_80052020)($at)
/* 065468 7F030938 46046202 */  mul.s $f8, $f12, $f4
/* 06546C 7F03093C E7AA0098 */  swc1  $f10, 0x98($sp)
/* 065470 7F030940 46067282 */  mul.s $f10, $f14, $f6
/* 065474 7F030944 E7A80094 */  swc1  $f8, 0x94($sp)
/* 065478 7F030948 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 06547C 7F03094C E7AA0090 */   swc1  $f10, 0x90($sp)
/* 065480 7F030950 0FC2C731 */  jal   sub_GAME_7F0B1CC4
/* 065484 7F030954 00000000 */   nop   
/* 065488 7F030958 8FAF00B8 */  lw    $t7, 0xb8($sp)
/* 06548C 7F03095C C7A40098 */  lwc1  $f4, 0x98($sp)
/* 065490 7F030960 C7A6009C */  lwc1  $f6, 0x9c($sp)
/* 065494 7F030964 AFAF00AC */  sw    $t7, 0xac($sp)
/* 065498 7F030968 C6020008 */  lwc1  $f2, 8($s0)
/* 06549C 7F03096C C6000000 */  lwc1  $f0, ($s0)
/* 0654A0 7F030970 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0654A4 7F030974 46061281 */  sub.s $f10, $f2, $f6
/* 0654A8 7F030978 44803000 */  mtc1  $zero, $f6
/* 0654AC 7F03097C 8FB800D0 */  lw    $t8, 0xd0($sp)
/* 0654B0 7F030980 46040200 */  add.s $f8, $f0, $f4
/* 0654B4 7F030984 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 0654B8 7F030988 44815000 */  mtc1  $at, $f10
/* 0654BC 7F03098C C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 0654C0 7F030990 44074000 */  mfc1  $a3, $f8
/* 0654C4 7F030994 C7A80048 */  lwc1  $f8, 0x48($sp)
/* 0654C8 7F030998 44061000 */  mfc1  $a2, $f2
/* 0654CC 7F03099C 44050000 */  mfc1  $a1, $f0
/* 0654D0 7F0309A0 27A400AC */  addiu $a0, $sp, 0xac
/* 0654D4 7F0309A4 AFB80014 */  sw    $t8, 0x14($sp)
/* 0654D8 7F0309A8 E7A60020 */  swc1  $f6, 0x20($sp)
/* 0654DC 7F0309AC E7A40018 */  swc1  $f4, 0x18($sp)
/* 0654E0 7F0309B0 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 0654E4 7F0309B4 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 0654E8 7F0309B8 E7A8001C */   swc1  $f8, 0x1c($sp)
/* 0654EC 7F0309BC 10400026 */  beqz  $v0, .L7F030A58
/* 0654F0 7F0309C0 27A400AC */   addiu $a0, $sp, 0xac
/* 0654F4 7F0309C4 8FA200BC */  lw    $v0, 0xbc($sp)
/* 0654F8 7F0309C8 C7B200C8 */  lwc1  $f18, 0xc8($sp)
/* 0654FC 7F0309CC C6100000 */  lwc1  $f16, ($s0)
/* 065500 7F0309D0 C7AE0098 */  lwc1  $f14, 0x98($sp)
/* 065504 7F0309D4 C60C0008 */  lwc1  $f12, 8($s0)
/* 065508 7F0309D8 C7AA009C */  lwc1  $f10, 0x9c($sp)
/* 06550C 7F0309DC 460E8380 */  add.s $f14, $f16, $f14
/* 065510 7F0309E0 C7B000A0 */  lwc1  $f16, 0xa0($sp)
/* 065514 7F0309E4 C4480000 */  lwc1  $f8, ($v0)
/* 065518 7F0309E8 460A6281 */  sub.s $f10, $f12, $f10
/* 06551C 7F0309EC 46128402 */  mul.s $f16, $f16, $f18
/* 065520 7F0309F0 C7AC0090 */  lwc1  $f12, 0x90($sp)
/* 065524 7F0309F4 C7A600A8 */  lwc1  $f6, 0xa8($sp)
/* 065528 7F0309F8 C4440008 */  lwc1  $f4, 8($v0)
/* 06552C 7F0309FC C7A20094 */  lwc1  $f2, 0x94($sp)
/* 065530 7F030A00 46123482 */  mul.s $f18, $f6, $f18
/* 065534 7F030A04 460C4300 */  add.s $f12, $f8, $f12
/* 065538 7F030A08 44057000 */  mfc1  $a1, $f14
/* 06553C 7F030A0C 44065000 */  mfc1  $a2, $f10
/* 065540 7F030A10 8FB900D0 */  lw    $t9, 0xd0($sp)
/* 065544 7F030A14 46022081 */  sub.s $f2, $f4, $f2
/* 065548 7F030A18 C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 06554C 7F030A1C C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 065550 7F030A20 460C8300 */  add.s $f12, $f16, $f12
/* 065554 7F030A24 44808000 */  mtc1  $zero, $f16
/* 065558 7F030A28 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 06555C 7F030A2C 46029080 */  add.s $f2, $f18, $f2
/* 065560 7F030A30 44076000 */  mfc1  $a3, $f12
/* 065564 7F030A34 44816000 */  mtc1  $at, $f12
/* 065568 7F030A38 E7A40018 */  swc1  $f4, 0x18($sp)
/* 06556C 7F030A3C E7A20010 */  swc1  $f2, 0x10($sp)
/* 065570 7F030A40 AFB90014 */  sw    $t9, 0x14($sp)
/* 065574 7F030A44 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 065578 7F030A48 E7B00020 */  swc1  $f16, 0x20($sp)
/* 06557C 7F030A4C 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 065580 7F030A50 E7AC0024 */   swc1  $f12, 0x24($sp)
/* 065584 7F030A54 14400009 */  bnez  $v0, .L7F030A7C
.L7F030A58:
/* 065588 7F030A58 24080001 */   li    $t0, 1
/* 06558C 7F030A5C AFA80088 */  sw    $t0, 0x88($sp)
/* 065590 7F030A60 27A40078 */  addiu $a0, $sp, 0x78
/* 065594 7F030A64 0FC2CA2C */  jal   getCollisionEdge_maybe
/* 065598 7F030A68 27A5006C */   addiu $a1, $sp, 0x6c
/* 06559C 7F030A6C 27A40078 */  addiu $a0, $sp, 0x78
/* 0655A0 7F030A70 27A5006C */  addiu $a1, $sp, 0x6c
/* 0655A4 7F030A74 0FC0C1D3 */  jal   sub_GAME_7F03074C
/* 0655A8 7F030A78 27A600A0 */   addiu $a2, $sp, 0xa0
.L7F030A7C:
/* 0655AC 7F030A7C 8FA900B8 */  lw    $t1, 0xb8($sp)
/* 0655B0 7F030A80 C7AA0098 */  lwc1  $f10, 0x98($sp)
/* 0655B4 7F030A84 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0655B8 7F030A88 AFA900AC */  sw    $t1, 0xac($sp)
/* 0655BC 7F030A8C C6020008 */  lwc1  $f2, 8($s0)
/* 0655C0 7F030A90 C6000000 */  lwc1  $f0, ($s0)
/* 0655C4 7F030A94 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0655C8 7F030A98 46041180 */  add.s $f6, $f2, $f4
/* 0655CC 7F030A9C 44802000 */  mtc1  $zero, $f4
/* 0655D0 7F030AA0 8FAA00D0 */  lw    $t2, 0xd0($sp)
/* 0655D4 7F030AA4 460A0201 */  sub.s $f8, $f0, $f10
/* 0655D8 7F030AA8 E7A60010 */  swc1  $f6, 0x10($sp)
/* 0655DC 7F030AAC 44813000 */  mtc1  $at, $f6
/* 0655E0 7F030AB0 C7AA004C */  lwc1  $f10, 0x4c($sp)
/* 0655E4 7F030AB4 44074000 */  mfc1  $a3, $f8
/* 0655E8 7F030AB8 C7A80048 */  lwc1  $f8, 0x48($sp)
/* 0655EC 7F030ABC 44061000 */  mfc1  $a2, $f2
/* 0655F0 7F030AC0 44050000 */  mfc1  $a1, $f0
/* 0655F4 7F030AC4 27A400AC */  addiu $a0, $sp, 0xac
/* 0655F8 7F030AC8 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0655FC 7F030ACC E7A40020 */  swc1  $f4, 0x20($sp)
/* 065600 7F030AD0 E7AA0018 */  swc1  $f10, 0x18($sp)
/* 065604 7F030AD4 E7A60024 */  swc1  $f6, 0x24($sp)
/* 065608 7F030AD8 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 06560C 7F030ADC E7A8001C */   swc1  $f8, 0x1c($sp)
/* 065610 7F030AE0 10400026 */  beqz  $v0, .L7F030B7C
/* 065614 7F030AE4 27A400AC */   addiu $a0, $sp, 0xac
/* 065618 7F030AE8 8FA200BC */  lw    $v0, 0xbc($sp)
/* 06561C 7F030AEC C6120008 */  lwc1  $f18, 8($s0)
/* 065620 7F030AF0 C7B0009C */  lwc1  $f16, 0x9c($sp)
/* 065624 7F030AF4 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 065628 7F030AF8 C7AC00C8 */  lwc1  $f12, 0xc8($sp)
/* 06562C 7F030AFC 46109400 */  add.s $f16, $f18, $f16
/* 065630 7F030B00 C4520000 */  lwc1  $f18, ($v0)
/* 065634 7F030B04 460C7382 */  mul.s $f14, $f14, $f12
/* 065638 7F030B08 C60A0000 */  lwc1  $f10, ($s0)
/* 06563C 7F030B0C C7A80098 */  lwc1  $f8, 0x98($sp)
/* 065640 7F030B10 C7A60090 */  lwc1  $f6, 0x90($sp)
/* 065644 7F030B14 C7A400A8 */  lwc1  $f4, 0xa8($sp)
/* 065648 7F030B18 46085201 */  sub.s $f8, $f10, $f8
/* 06564C 7F030B1C C44A0008 */  lwc1  $f10, 8($v0)
/* 065650 7F030B20 C7A20094 */  lwc1  $f2, 0x94($sp)
/* 065654 7F030B24 46069181 */  sub.s $f6, $f18, $f6
/* 065658 7F030B28 460C2302 */  mul.s $f12, $f4, $f12
/* 06565C 7F030B2C 44054000 */  mfc1  $a1, $f8
/* 065660 7F030B30 46025080 */  add.s $f2, $f10, $f2
/* 065664 7F030B34 44068000 */  mfc1  $a2, $f16
/* 065668 7F030B38 8FAB00D0 */  lw    $t3, 0xd0($sp)
/* 06566C 7F030B3C 46067180 */  add.s $f6, $f14, $f6
/* 065670 7F030B40 C7AE004C */  lwc1  $f14, 0x4c($sp)
/* 065674 7F030B44 C7B00048 */  lwc1  $f16, 0x48($sp)
/* 065678 7F030B48 46026080 */  add.s $f2, $f12, $f2
/* 06567C 7F030B4C 44073000 */  mfc1  $a3, $f6
/* 065680 7F030B50 44803000 */  mtc1  $zero, $f6
/* 065684 7F030B54 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065688 7F030B58 44816000 */  mtc1  $at, $f12
/* 06568C 7F030B5C E7A20010 */  swc1  $f2, 0x10($sp)
/* 065690 7F030B60 E7AE0018 */  swc1  $f14, 0x18($sp)
/* 065694 7F030B64 AFAB0014 */  sw    $t3, 0x14($sp)
/* 065698 7F030B68 E7B0001C */  swc1  $f16, 0x1c($sp)
/* 06569C 7F030B6C E7A60020 */  swc1  $f6, 0x20($sp)
/* 0656A0 7F030B70 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 0656A4 7F030B74 E7AC0024 */   swc1  $f12, 0x24($sp)
/* 0656A8 7F030B78 14400009 */  bnez  $v0, .L7F030BA0
.L7F030B7C:
/* 0656AC 7F030B7C 240C0001 */   li    $t4, 1
/* 0656B0 7F030B80 AFAC0084 */  sw    $t4, 0x84($sp)
/* 0656B4 7F030B84 27A40060 */  addiu $a0, $sp, 0x60
/* 0656B8 7F030B88 0FC2CA2C */  jal   getCollisionEdge_maybe
/* 0656BC 7F030B8C 27A50054 */   addiu $a1, $sp, 0x54
/* 0656C0 7F030B90 27A40060 */  addiu $a0, $sp, 0x60
/* 0656C4 7F030B94 27A50054 */  addiu $a1, $sp, 0x54
/* 0656C8 7F030B98 0FC0C1D3 */  jal   sub_GAME_7F03074C
/* 0656CC 7F030B9C 27A600A0 */   addiu $a2, $sp, 0xa0
.L7F030BA0:
/* 0656D0 7F030BA0 8FAD0088 */  lw    $t5, 0x88($sp)
/* 0656D4 7F030BA4 8FAE0084 */  lw    $t6, 0x84($sp)
/* 0656D8 7F030BA8 8FAF0088 */  lw    $t7, 0x88($sp)
/* 0656DC 7F030BAC 11A00019 */  beqz  $t5, .L7F030C14
/* 0656E0 7F030BB0 00000000 */   nop   
/* 0656E4 7F030BB4 11C00017 */  beqz  $t6, .L7F030C14
/* 0656E8 7F030BB8 27A40078 */   addiu $a0, $sp, 0x78
/* 0656EC 7F030BBC 27A50060 */  addiu $a1, $sp, 0x60
/* 0656F0 7F030BC0 0FC0C1D3 */  jal   sub_GAME_7F03074C
/* 0656F4 7F030BC4 27A600A0 */   addiu $a2, $sp, 0xa0
/* 0656F8 7F030BC8 27A4006C */  addiu $a0, $sp, 0x6c
/* 0656FC 7F030BCC 27A50054 */  addiu $a1, $sp, 0x54
/* 065700 7F030BD0 0FC0C1D3 */  jal   sub_GAME_7F03074C
/* 065704 7F030BD4 27A600A0 */   addiu $a2, $sp, 0xa0
/* 065708 7F030BD8 8FA400C0 */  lw    $a0, 0xc0($sp)
/* 06570C 7F030BDC C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 065710 7F030BE0 8FA500C4 */  lw    $a1, 0xc4($sp)
/* 065714 7F030BE4 E48A0000 */  swc1  $f10, ($a0)
/* 065718 7F030BE8 C7A8007C */  lwc1  $f8, 0x7c($sp)
/* 06571C 7F030BEC E4880004 */  swc1  $f8, 4($a0)
/* 065720 7F030BF0 C7A60080 */  lwc1  $f6, 0x80($sp)
/* 065724 7F030BF4 E4860008 */  swc1  $f6, 8($a0)
/* 065728 7F030BF8 C7A40054 */  lwc1  $f4, 0x54($sp)
/* 06572C 7F030BFC E4A40000 */  swc1  $f4, ($a1)
/* 065730 7F030C00 C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 065734 7F030C04 E4AA0004 */  swc1  $f10, 4($a1)
/* 065738 7F030C08 C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 06573C 7F030C0C 1000004F */  b     .L7F030D4C
/* 065740 7F030C10 E4A80008 */   swc1  $f8, 8($a1)
.L7F030C14:
/* 065744 7F030C14 11E00010 */  beqz  $t7, .L7F030C58
/* 065748 7F030C18 8FB80084 */   lw    $t8, 0x84($sp)
/* 06574C 7F030C1C 8FA400C0 */  lw    $a0, 0xc0($sp)
/* 065750 7F030C20 C7A60078 */  lwc1  $f6, 0x78($sp)
/* 065754 7F030C24 8FA500C4 */  lw    $a1, 0xc4($sp)
/* 065758 7F030C28 E4860000 */  swc1  $f6, ($a0)
/* 06575C 7F030C2C C7A4007C */  lwc1  $f4, 0x7c($sp)
/* 065760 7F030C30 E4840004 */  swc1  $f4, 4($a0)
/* 065764 7F030C34 C7AA0080 */  lwc1  $f10, 0x80($sp)
/* 065768 7F030C38 E48A0008 */  swc1  $f10, 8($a0)
/* 06576C 7F030C3C C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 065770 7F030C40 E4A80000 */  swc1  $f8, ($a1)
/* 065774 7F030C44 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 065778 7F030C48 E4A60004 */  swc1  $f6, 4($a1)
/* 06577C 7F030C4C C7A40074 */  lwc1  $f4, 0x74($sp)
/* 065780 7F030C50 1000003E */  b     .L7F030D4C
/* 065784 7F030C54 E4A40008 */   swc1  $f4, 8($a1)
.L7F030C58:
/* 065788 7F030C58 13000010 */  beqz  $t8, .L7F030C9C
/* 06578C 7F030C5C 8FA200BC */   lw    $v0, 0xbc($sp)
/* 065790 7F030C60 8FA400C0 */  lw    $a0, 0xc0($sp)
/* 065794 7F030C64 C7AA0060 */  lwc1  $f10, 0x60($sp)
/* 065798 7F030C68 8FA500C4 */  lw    $a1, 0xc4($sp)
/* 06579C 7F030C6C E48A0000 */  swc1  $f10, ($a0)
/* 0657A0 7F030C70 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 0657A4 7F030C74 E4880004 */  swc1  $f8, 4($a0)
/* 0657A8 7F030C78 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0657AC 7F030C7C E4860008 */  swc1  $f6, 8($a0)
/* 0657B0 7F030C80 C7A40054 */  lwc1  $f4, 0x54($sp)
/* 0657B4 7F030C84 E4A40000 */  swc1  $f4, ($a1)
/* 0657B8 7F030C88 C7AA0058 */  lwc1  $f10, 0x58($sp)
/* 0657BC 7F030C8C E4AA0004 */  swc1  $f10, 4($a1)
/* 0657C0 7F030C90 C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 0657C4 7F030C94 1000002D */  b     .L7F030D4C
/* 0657C8 7F030C98 E4A80008 */   swc1  $f8, 8($a1)
.L7F030C9C:
/* 0657CC 7F030C9C 8FB900B8 */  lw    $t9, 0xb8($sp)
/* 0657D0 7F030CA0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0657D4 7F030CA4 8FA800D0 */  lw    $t0, 0xd0($sp)
/* 0657D8 7F030CA8 AFB900AC */  sw    $t9, 0xac($sp)
/* 0657DC 7F030CAC C4460008 */  lwc1  $f6, 8($v0)
/* 0657E0 7F030CB0 8C470000 */  lw    $a3, ($v0)
/* 0657E4 7F030CB4 8E060008 */  lw    $a2, 8($s0)
/* 0657E8 7F030CB8 8E050000 */  lw    $a1, ($s0)
/* 0657EC 7F030CBC E7A60010 */  swc1  $f6, 0x10($sp)
/* 0657F0 7F030CC0 44813000 */  mtc1  $at, $f6
/* 0657F4 7F030CC4 C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 0657F8 7F030CC8 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 0657FC 7F030CCC 44804000 */  mtc1  $zero, $f8
/* 065800 7F030CD0 27A400AC */  addiu $a0, $sp, 0xac
/* 065804 7F030CD4 AFA80014 */  sw    $t0, 0x14($sp)
/* 065808 7F030CD8 E7A40018 */  swc1  $f4, 0x18($sp)
/* 06580C 7F030CDC E7A60024 */  swc1  $f6, 0x24($sp)
/* 065810 7F030CE0 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 065814 7F030CE4 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 065818 7F030CE8 E7A80020 */   swc1  $f8, 0x20($sp)
/* 06581C 7F030CEC 10400010 */  beqz  $v0, .L7F030D30
/* 065820 7F030CF0 27A400AC */   addiu $a0, $sp, 0xac
/* 065824 7F030CF4 8FA900BC */  lw    $t1, 0xbc($sp)
/* 065828 7F030CF8 8FAA00D0 */  lw    $t2, 0xd0($sp)
/* 06582C 7F030CFC C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 065830 7F030D00 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 065834 7F030D04 8D250000 */  lw    $a1, ($t1)
/* 065838 7F030D08 8D260008 */  lw    $a2, 8($t1)
/* 06583C 7F030D0C 8FA700CC */  lw    $a3, 0xcc($sp)
/* 065840 7F030D10 AFAA0010 */  sw    $t2, 0x10($sp)
/* 065844 7F030D14 E7A40014 */  swc1  $f4, 0x14($sp)
/* 065848 7F030D18 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 06584C 7F030D1C E7AA0018 */   swc1  $f10, 0x18($sp)
/* 065850 7F030D20 04410003 */  bgez  $v0, .L7F030D30
/* 065854 7F030D24 240B0001 */   li    $t3, 1
/* 065858 7F030D28 10000008 */  b     .L7F030D4C
/* 06585C 7F030D2C AFAB0050 */   sw    $t3, 0x50($sp)
.L7F030D30:
/* 065860 7F030D30 8FA400C0 */  lw    $a0, 0xc0($sp)
/* 065864 7F030D34 0FC2CA2C */  jal   getCollisionEdge_maybe
/* 065868 7F030D38 8FA500C4 */   lw    $a1, 0xc4($sp)
/* 06586C 7F030D3C 8FA400C0 */  lw    $a0, 0xc0($sp)
/* 065870 7F030D40 8FA500C4 */  lw    $a1, 0xc4($sp)
/* 065874 7F030D44 0FC0C1D3 */  jal   sub_GAME_7F03074C
/* 065878 7F030D48 27A600A0 */   addiu $a2, $sp, 0xa0
.L7F030D4C:
/* 06587C 7F030D4C 8FA400B0 */  lw    $a0, 0xb0($sp)
/* 065880 7F030D50 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 065884 7F030D54 24050001 */   li    $a1, 1
/* 065888 7F030D58 8FA20050 */  lw    $v0, 0x50($sp)
.L7F030D5C:
/* 06588C 7F030D5C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 065890 7F030D60 8FB00030 */  lw    $s0, 0x30($sp)
/* 065894 7F030D64 27BD00B0 */  addiu $sp, $sp, 0xb0
/* 065898 7F030D68 03E00008 */  jr    $ra
/* 06589C 7F030D6C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F030D70(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80052024
.word 0x3f733333 /*0.94999999*/
glabel D_80052028
.word 0x3f733333 /*0.94999999*/
glabel D_8005202C
.word 0x3f99999a /*1.2*/
glabel D_80052030
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F030D70
/* 0658A0 7F030D70 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0658A4 7F030D74 AFB00030 */  sw    $s0, 0x30($sp)
/* 0658A8 7F030D78 00A08025 */  move  $s0, $a1
/* 0658AC 7F030D7C AFBF0034 */  sw    $ra, 0x34($sp)
/* 0658B0 7F030D80 AFA400B8 */  sw    $a0, 0xb8($sp)
/* 0658B4 7F030D84 AFA600C0 */  sw    $a2, 0xc0($sp)
/* 0658B8 7F030D88 AFA700C4 */  sw    $a3, 0xc4($sp)
/* 0658BC 7F030D8C AFA00090 */  sw    $zero, 0x90($sp)
/* 0658C0 7F030D90 AFA0008C */  sw    $zero, 0x8c($sp)
/* 0658C4 7F030D94 AFA00058 */  sw    $zero, 0x58($sp)
/* 0658C8 7F030D98 8C840018 */  lw    $a0, 0x18($a0)
/* 0658CC 7F030D9C 27A70048 */  addiu $a3, $sp, 0x48
/* 0658D0 7F030DA0 27A6004C */  addiu $a2, $sp, 0x4c
/* 0658D4 7F030DA4 0FC08C58 */  jal   chrGetChrWidthHeight
/* 0658D8 7F030DA8 27A50044 */   addiu $a1, $sp, 0x44
/* 0658DC 7F030DAC 8FA200C4 */  lw    $v0, 0xc4($sp)
/* 0658E0 7F030DB0 C6060000 */  lwc1  $f6, ($s0)
/* 0658E4 7F030DB4 44800000 */  mtc1  $zero, $f0
/* 0658E8 7F030DB8 C4440000 */  lwc1  $f4, ($v0)
/* 0658EC 7F030DBC E7A000AC */  swc1  $f0, 0xac($sp)
/* 0658F0 7F030DC0 46062201 */  sub.s $f8, $f4, $f6
/* 0658F4 7F030DC4 E7A800A8 */  swc1  $f8, 0xa8($sp)
/* 0658F8 7F030DC8 C7A800A8 */  lwc1  $f8, 0xa8($sp)
/* 0658FC 7F030DCC C6040008 */  lwc1  $f4, 8($s0)
/* 065900 7F030DD0 C44A0008 */  lwc1  $f10, 8($v0)
/* 065904 7F030DD4 46080032 */  c.eq.s $f0, $f8
/* 065908 7F030DD8 46045181 */  sub.s $f6, $f10, $f4
/* 06590C 7F030DDC 45000008 */  bc1f  .L7F030E00
/* 065910 7F030DE0 E7A600B0 */   swc1  $f6, 0xb0($sp)
/* 065914 7F030DE4 C7B200B0 */  lwc1  $f18, 0xb0($sp)
/* 065918 7F030DE8 46120032 */  c.eq.s $f0, $f18
/* 06591C 7F030DEC 00000000 */  nop   
/* 065920 7F030DF0 45020004 */  bc1fl .L7F030E04
/* 065924 7F030DF4 C7B200B0 */   lwc1  $f18, 0xb0($sp)
/* 065928 7F030DF8 1000013F */  b     .L7F0312F8
/* 06592C 7F030DFC 24020001 */   li    $v0, 1
.L7F030E00:
/* 065930 7F030E00 C7B200B0 */  lwc1  $f18, 0xb0($sp)
.L7F030E04:
/* 065934 7F030E04 C7B000A8 */  lwc1  $f16, 0xa8($sp)
/* 065938 7F030E08 46129282 */  mul.s $f10, $f18, $f18
/* 06593C 7F030E0C 00000000 */  nop   
/* 065940 7F030E10 46108102 */  mul.s $f4, $f16, $f16
/* 065944 7F030E14 0C007DF8 */  jal   sqrtf
/* 065948 7F030E18 46045300 */   add.s $f12, $f10, $f4
/* 06594C 7F030E1C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065950 7F030E20 44813000 */  mtc1  $at, $f6
/* 065954 7F030E24 C7B000A8 */  lwc1  $f16, 0xa8($sp)
/* 065958 7F030E28 C7B200B0 */  lwc1  $f18, 0xb0($sp)
/* 06595C 7F030E2C 46003083 */  div.s $f2, $f6, $f0
/* 065960 7F030E30 C7A800D4 */  lwc1  $f8, 0xd4($sp)
/* 065964 7F030E34 3C018005 */  lui   $at, %hi(D_80052024)
/* 065968 7F030E38 C42A2024 */  lwc1  $f10, %lo(D_80052024)($at)
/* 06596C 7F030E3C 3C018005 */  lui   $at, %hi(D_80052028)
/* 065970 7F030E40 C4262028 */  lwc1  $f6, %lo(D_80052028)($at)
/* 065974 7F030E44 3C018005 */  lui   $at, %hi(D_8005202C)
/* 065978 7F030E48 8FA400B8 */  lw    $a0, 0xb8($sp)
/* 06597C 7F030E4C 00002825 */  move  $a1, $zero
/* 065980 7F030E50 46028402 */  mul.s $f16, $f16, $f2
/* 065984 7F030E54 00000000 */  nop   
/* 065988 7F030E58 46029482 */  mul.s $f18, $f18, $f2
/* 06598C 7F030E5C 00000000 */  nop   
/* 065990 7F030E60 46088302 */  mul.s $f12, $f16, $f8
/* 065994 7F030E64 E7B000A8 */  swc1  $f16, 0xa8($sp)
/* 065998 7F030E68 E7B200B0 */  swc1  $f18, 0xb0($sp)
/* 06599C 7F030E6C 460A6102 */  mul.s $f4, $f12, $f10
/* 0659A0 7F030E70 00000000 */  nop   
/* 0659A4 7F030E74 46089382 */  mul.s $f14, $f18, $f8
/* 0659A8 7F030E78 E7A400A4 */  swc1  $f4, 0xa4($sp)
/* 0659AC 7F030E7C C424202C */  lwc1  $f4, %lo(D_8005202C)($at)
/* 0659B0 7F030E80 3C018005 */  lui   $at, %hi(D_80052030)
/* 0659B4 7F030E84 46067282 */  mul.s $f10, $f14, $f6
/* 0659B8 7F030E88 C4262030 */  lwc1  $f6, %lo(D_80052030)($at)
/* 0659BC 7F030E8C 46046202 */  mul.s $f8, $f12, $f4
/* 0659C0 7F030E90 E7AA00A0 */  swc1  $f10, 0xa0($sp)
/* 0659C4 7F030E94 46067282 */  mul.s $f10, $f14, $f6
/* 0659C8 7F030E98 E7A8009C */  swc1  $f8, 0x9c($sp)
/* 0659CC 7F030E9C 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 0659D0 7F030EA0 E7AA0098 */   swc1  $f10, 0x98($sp)
/* 0659D4 7F030EA4 0FC2C731 */  jal   sub_GAME_7F0B1CC4
/* 0659D8 7F030EA8 00000000 */   nop   
/* 0659DC 7F030EAC 8FAF00C0 */  lw    $t7, 0xc0($sp)
/* 0659E0 7F030EB0 C7A400A0 */  lwc1  $f4, 0xa0($sp)
/* 0659E4 7F030EB4 C7A600A4 */  lwc1  $f6, 0xa4($sp)
/* 0659E8 7F030EB8 AFAF00B4 */  sw    $t7, 0xb4($sp)
/* 0659EC 7F030EBC C6020008 */  lwc1  $f2, 8($s0)
/* 0659F0 7F030EC0 C6000000 */  lwc1  $f0, ($s0)
/* 0659F4 7F030EC4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0659F8 7F030EC8 46061281 */  sub.s $f10, $f2, $f6
/* 0659FC 7F030ECC 44803000 */  mtc1  $zero, $f6
/* 065A00 7F030ED0 8FB800D8 */  lw    $t8, 0xd8($sp)
/* 065A04 7F030ED4 46040200 */  add.s $f8, $f0, $f4
/* 065A08 7F030ED8 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 065A0C 7F030EDC 44815000 */  mtc1  $at, $f10
/* 065A10 7F030EE0 C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 065A14 7F030EE4 44074000 */  mfc1  $a3, $f8
/* 065A18 7F030EE8 C7A80048 */  lwc1  $f8, 0x48($sp)
/* 065A1C 7F030EEC 44061000 */  mfc1  $a2, $f2
/* 065A20 7F030EF0 44050000 */  mfc1  $a1, $f0
/* 065A24 7F030EF4 27A400B4 */  addiu $a0, $sp, 0xb4
/* 065A28 7F030EF8 AFB80014 */  sw    $t8, 0x14($sp)
/* 065A2C 7F030EFC E7A60020 */  swc1  $f6, 0x20($sp)
/* 065A30 7F030F00 E7A40018 */  swc1  $f4, 0x18($sp)
/* 065A34 7F030F04 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 065A38 7F030F08 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 065A3C 7F030F0C E7A8001C */   swc1  $f8, 0x1c($sp)
/* 065A40 7F030F10 10400026 */  beqz  $v0, .L7F030FAC
/* 065A44 7F030F14 27A400B4 */   addiu $a0, $sp, 0xb4
/* 065A48 7F030F18 8FA200C4 */  lw    $v0, 0xc4($sp)
/* 065A4C 7F030F1C C7B200D0 */  lwc1  $f18, 0xd0($sp)
/* 065A50 7F030F20 C6100000 */  lwc1  $f16, ($s0)
/* 065A54 7F030F24 C7AE00A0 */  lwc1  $f14, 0xa0($sp)
/* 065A58 7F030F28 C60C0008 */  lwc1  $f12, 8($s0)
/* 065A5C 7F030F2C C7AA00A4 */  lwc1  $f10, 0xa4($sp)
/* 065A60 7F030F30 460E8380 */  add.s $f14, $f16, $f14
/* 065A64 7F030F34 C7B000A8 */  lwc1  $f16, 0xa8($sp)
/* 065A68 7F030F38 C4480000 */  lwc1  $f8, ($v0)
/* 065A6C 7F030F3C 460A6281 */  sub.s $f10, $f12, $f10
/* 065A70 7F030F40 46128402 */  mul.s $f16, $f16, $f18
/* 065A74 7F030F44 C7AC0098 */  lwc1  $f12, 0x98($sp)
/* 065A78 7F030F48 C7A600B0 */  lwc1  $f6, 0xb0($sp)
/* 065A7C 7F030F4C C4440008 */  lwc1  $f4, 8($v0)
/* 065A80 7F030F50 C7A2009C */  lwc1  $f2, 0x9c($sp)
/* 065A84 7F030F54 46123482 */  mul.s $f18, $f6, $f18
/* 065A88 7F030F58 460C4300 */  add.s $f12, $f8, $f12
/* 065A8C 7F030F5C 44057000 */  mfc1  $a1, $f14
/* 065A90 7F030F60 44065000 */  mfc1  $a2, $f10
/* 065A94 7F030F64 8FB900D8 */  lw    $t9, 0xd8($sp)
/* 065A98 7F030F68 46022081 */  sub.s $f2, $f4, $f2
/* 065A9C 7F030F6C C7A4004C */  lwc1  $f4, 0x4c($sp)
/* 065AA0 7F030F70 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 065AA4 7F030F74 460C8300 */  add.s $f12, $f16, $f12
/* 065AA8 7F030F78 44808000 */  mtc1  $zero, $f16
/* 065AAC 7F030F7C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065AB0 7F030F80 46029080 */  add.s $f2, $f18, $f2
/* 065AB4 7F030F84 44076000 */  mfc1  $a3, $f12
/* 065AB8 7F030F88 44816000 */  mtc1  $at, $f12
/* 065ABC 7F030F8C E7A40018 */  swc1  $f4, 0x18($sp)
/* 065AC0 7F030F90 E7A20010 */  swc1  $f2, 0x10($sp)
/* 065AC4 7F030F94 AFB90014 */  sw    $t9, 0x14($sp)
/* 065AC8 7F030F98 E7AA001C */  swc1  $f10, 0x1c($sp)
/* 065ACC 7F030F9C E7B00020 */  swc1  $f16, 0x20($sp)
/* 065AD0 7F030FA0 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 065AD4 7F030FA4 E7AC0024 */   swc1  $f12, 0x24($sp)
/* 065AD8 7F030FA8 1440000C */  bnez  $v0, .L7F030FDC
.L7F030FAC:
/* 065ADC 7F030FAC 24080001 */   li    $t0, 1
/* 065AE0 7F030FB0 AFA80090 */  sw    $t0, 0x90($sp)
/* 065AE4 7F030FB4 27A40080 */  addiu $a0, $sp, 0x80
/* 065AE8 7F030FB8 0FC2CA2C */  jal   getCollisionEdge_maybe
/* 065AEC 7F030FBC 27A50074 */   addiu $a1, $sp, 0x74
/* 065AF0 7F030FC0 27A40080 */  addiu $a0, $sp, 0x80
/* 065AF4 7F030FC4 27A50074 */  addiu $a1, $sp, 0x74
/* 065AF8 7F030FC8 0FC0C1D3 */  jal   sub_GAME_7F03074C
/* 065AFC 7F030FCC 27A600A8 */   addiu $a2, $sp, 0xa8
/* 065B00 7F030FD0 3C018008 */  lui   $at, %hi(stanSavedColl_someMin)
/* 065B04 7F030FD4 C42ABA00 */  lwc1  $f10, %lo(stanSavedColl_someMin)($at)
/* 065B08 7F030FD8 E7AA0054 */  swc1  $f10, 0x54($sp)
.L7F030FDC:
/* 065B0C 7F030FDC 8FA900C0 */  lw    $t1, 0xc0($sp)
/* 065B10 7F030FE0 C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 065B14 7F030FE4 C7A600A4 */  lwc1  $f6, 0xa4($sp)
/* 065B18 7F030FE8 AFA900B4 */  sw    $t1, 0xb4($sp)
/* 065B1C 7F030FEC C6020008 */  lwc1  $f2, 8($s0)
/* 065B20 7F030FF0 C6000000 */  lwc1  $f0, ($s0)
/* 065B24 7F030FF4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065B28 7F030FF8 46061280 */  add.s $f10, $f2, $f6
/* 065B2C 7F030FFC 44803000 */  mtc1  $zero, $f6
/* 065B30 7F031000 8FAA00D8 */  lw    $t2, 0xd8($sp)
/* 065B34 7F031004 46080101 */  sub.s $f4, $f0, $f8
/* 065B38 7F031008 E7AA0010 */  swc1  $f10, 0x10($sp)
/* 065B3C 7F03100C 44815000 */  mtc1  $at, $f10
/* 065B40 7F031010 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 065B44 7F031014 44072000 */  mfc1  $a3, $f4
/* 065B48 7F031018 C7A40048 */  lwc1  $f4, 0x48($sp)
/* 065B4C 7F03101C 44061000 */  mfc1  $a2, $f2
/* 065B50 7F031020 44050000 */  mfc1  $a1, $f0
/* 065B54 7F031024 27A400B4 */  addiu $a0, $sp, 0xb4
/* 065B58 7F031028 AFAA0014 */  sw    $t2, 0x14($sp)
/* 065B5C 7F03102C E7A60020 */  swc1  $f6, 0x20($sp)
/* 065B60 7F031030 E7A80018 */  swc1  $f8, 0x18($sp)
/* 065B64 7F031034 E7AA0024 */  swc1  $f10, 0x24($sp)
/* 065B68 7F031038 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 065B6C 7F03103C E7A4001C */   swc1  $f4, 0x1c($sp)
/* 065B70 7F031040 10400026 */  beqz  $v0, .L7F0310DC
/* 065B74 7F031044 27A400B4 */   addiu $a0, $sp, 0xb4
/* 065B78 7F031048 8FA200C4 */  lw    $v0, 0xc4($sp)
/* 065B7C 7F03104C C6120008 */  lwc1  $f18, 8($s0)
/* 065B80 7F031050 C7B000A4 */  lwc1  $f16, 0xa4($sp)
/* 065B84 7F031054 C7AE00A8 */  lwc1  $f14, 0xa8($sp)
/* 065B88 7F031058 C7AC00D0 */  lwc1  $f12, 0xd0($sp)
/* 065B8C 7F03105C 46109400 */  add.s $f16, $f18, $f16
/* 065B90 7F031060 C4520000 */  lwc1  $f18, ($v0)
/* 065B94 7F031064 460C7382 */  mul.s $f14, $f14, $f12
/* 065B98 7F031068 C60A0000 */  lwc1  $f10, ($s0)
/* 065B9C 7F03106C C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 065BA0 7F031070 C7A60098 */  lwc1  $f6, 0x98($sp)
/* 065BA4 7F031074 C7A400B0 */  lwc1  $f4, 0xb0($sp)
/* 065BA8 7F031078 46085201 */  sub.s $f8, $f10, $f8
/* 065BAC 7F03107C C44A0008 */  lwc1  $f10, 8($v0)
/* 065BB0 7F031080 C7A2009C */  lwc1  $f2, 0x9c($sp)
/* 065BB4 7F031084 46069181 */  sub.s $f6, $f18, $f6
/* 065BB8 7F031088 460C2302 */  mul.s $f12, $f4, $f12
/* 065BBC 7F03108C 44054000 */  mfc1  $a1, $f8
/* 065BC0 7F031090 46025080 */  add.s $f2, $f10, $f2
/* 065BC4 7F031094 44068000 */  mfc1  $a2, $f16
/* 065BC8 7F031098 8FAB00D8 */  lw    $t3, 0xd8($sp)
/* 065BCC 7F03109C 46067180 */  add.s $f6, $f14, $f6
/* 065BD0 7F0310A0 C7AE004C */  lwc1  $f14, 0x4c($sp)
/* 065BD4 7F0310A4 C7B00048 */  lwc1  $f16, 0x48($sp)
/* 065BD8 7F0310A8 46026080 */  add.s $f2, $f12, $f2
/* 065BDC 7F0310AC 44073000 */  mfc1  $a3, $f6
/* 065BE0 7F0310B0 44803000 */  mtc1  $zero, $f6
/* 065BE4 7F0310B4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065BE8 7F0310B8 44816000 */  mtc1  $at, $f12
/* 065BEC 7F0310BC E7A20010 */  swc1  $f2, 0x10($sp)
/* 065BF0 7F0310C0 E7AE0018 */  swc1  $f14, 0x18($sp)
/* 065BF4 7F0310C4 AFAB0014 */  sw    $t3, 0x14($sp)
/* 065BF8 7F0310C8 E7B0001C */  swc1  $f16, 0x1c($sp)
/* 065BFC 7F0310CC E7A60020 */  swc1  $f6, 0x20($sp)
/* 065C00 7F0310D0 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 065C04 7F0310D4 E7AC0024 */   swc1  $f12, 0x24($sp)
/* 065C08 7F0310D8 1440000C */  bnez  $v0, .L7F03110C
.L7F0310DC:
/* 065C0C 7F0310DC 240C0001 */   li    $t4, 1
/* 065C10 7F0310E0 AFAC008C */  sw    $t4, 0x8c($sp)
/* 065C14 7F0310E4 27A40068 */  addiu $a0, $sp, 0x68
/* 065C18 7F0310E8 0FC2CA2C */  jal   getCollisionEdge_maybe
/* 065C1C 7F0310EC 27A5005C */   addiu $a1, $sp, 0x5c
/* 065C20 7F0310F0 27A40068 */  addiu $a0, $sp, 0x68
/* 065C24 7F0310F4 27A5005C */  addiu $a1, $sp, 0x5c
/* 065C28 7F0310F8 0FC0C1D3 */  jal   sub_GAME_7F03074C
/* 065C2C 7F0310FC 27A600A8 */   addiu $a2, $sp, 0xa8
/* 065C30 7F031100 3C018008 */  lui   $at, %hi(stanSavedColl_someMin)
/* 065C34 7F031104 C428BA00 */  lwc1  $f8, %lo(stanSavedColl_someMin)($at)
/* 065C38 7F031108 E7A80050 */  swc1  $f8, 0x50($sp)
.L7F03110C:
/* 065C3C 7F03110C 8FAD0090 */  lw    $t5, 0x90($sp)
/* 065C40 7F031110 8FAE008C */  lw    $t6, 0x8c($sp)
/* 065C44 7F031114 8FAF0090 */  lw    $t7, 0x90($sp)
/* 065C48 7F031118 11A00025 */  beqz  $t5, .L7F0311B0
/* 065C4C 7F03111C 00000000 */   nop   
/* 065C50 7F031120 11C00023 */  beqz  $t6, .L7F0311B0
/* 065C54 7F031124 C7A40054 */   lwc1  $f4, 0x54($sp)
/* 065C58 7F031128 C7AA0050 */  lwc1  $f10, 0x50($sp)
/* 065C5C 7F03112C C7A60080 */  lwc1  $f6, 0x80($sp)
/* 065C60 7F031130 8FA400C8 */  lw    $a0, 0xc8($sp)
/* 065C64 7F031134 460A203C */  c.lt.s $f4, $f10
/* 065C68 7F031138 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 065C6C 7F03113C 45020010 */  bc1fl .L7F031180
/* 065C70 7F031140 8FA500CC */   lw    $a1, 0xcc($sp)
/* 065C74 7F031144 8FA400C8 */  lw    $a0, 0xc8($sp)
/* 065C78 7F031148 8FA500CC */  lw    $a1, 0xcc($sp)
/* 065C7C 7F03114C E4860000 */  swc1  $f6, ($a0)
/* 065C80 7F031150 C7A80084 */  lwc1  $f8, 0x84($sp)
/* 065C84 7F031154 E4880004 */  swc1  $f8, 4($a0)
/* 065C88 7F031158 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 065C8C 7F03115C E4840008 */  swc1  $f4, 8($a0)
/* 065C90 7F031160 C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 065C94 7F031164 E4AA0000 */  swc1  $f10, ($a1)
/* 065C98 7F031168 C7A60078 */  lwc1  $f6, 0x78($sp)
/* 065C9C 7F03116C E4A60004 */  swc1  $f6, 4($a1)
/* 065CA0 7F031170 C7A8007C */  lwc1  $f8, 0x7c($sp)
/* 065CA4 7F031174 1000005C */  b     .L7F0312E8
/* 065CA8 7F031178 E4A80008 */   swc1  $f8, 8($a1)
/* 065CAC 7F03117C 8FA500CC */  lw    $a1, 0xcc($sp)
.L7F031180:
/* 065CB0 7F031180 E4840000 */  swc1  $f4, ($a0)
/* 065CB4 7F031184 C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 065CB8 7F031188 E48A0004 */  swc1  $f10, 4($a0)
/* 065CBC 7F03118C C7A60070 */  lwc1  $f6, 0x70($sp)
/* 065CC0 7F031190 E4860008 */  swc1  $f6, 8($a0)
/* 065CC4 7F031194 C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 065CC8 7F031198 E4A80000 */  swc1  $f8, ($a1)
/* 065CCC 7F03119C C7A40060 */  lwc1  $f4, 0x60($sp)
/* 065CD0 7F0311A0 E4A40004 */  swc1  $f4, 4($a1)
/* 065CD4 7F0311A4 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 065CD8 7F0311A8 1000004F */  b     .L7F0312E8
/* 065CDC 7F0311AC E4AA0008 */   swc1  $f10, 8($a1)
.L7F0311B0:
/* 065CE0 7F0311B0 11E00010 */  beqz  $t7, .L7F0311F4
/* 065CE4 7F0311B4 8FB8008C */   lw    $t8, 0x8c($sp)
/* 065CE8 7F0311B8 8FA400C8 */  lw    $a0, 0xc8($sp)
/* 065CEC 7F0311BC C7A60080 */  lwc1  $f6, 0x80($sp)
/* 065CF0 7F0311C0 8FA500CC */  lw    $a1, 0xcc($sp)
/* 065CF4 7F0311C4 E4860000 */  swc1  $f6, ($a0)
/* 065CF8 7F0311C8 C7A80084 */  lwc1  $f8, 0x84($sp)
/* 065CFC 7F0311CC E4880004 */  swc1  $f8, 4($a0)
/* 065D00 7F0311D0 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 065D04 7F0311D4 E4840008 */  swc1  $f4, 8($a0)
/* 065D08 7F0311D8 C7AA0074 */  lwc1  $f10, 0x74($sp)
/* 065D0C 7F0311DC E4AA0000 */  swc1  $f10, ($a1)
/* 065D10 7F0311E0 C7A60078 */  lwc1  $f6, 0x78($sp)
/* 065D14 7F0311E4 E4A60004 */  swc1  $f6, 4($a1)
/* 065D18 7F0311E8 C7A8007C */  lwc1  $f8, 0x7c($sp)
/* 065D1C 7F0311EC 1000003E */  b     .L7F0312E8
/* 065D20 7F0311F0 E4A80008 */   swc1  $f8, 8($a1)
.L7F0311F4:
/* 065D24 7F0311F4 13000010 */  beqz  $t8, .L7F031238
/* 065D28 7F0311F8 8FA200C4 */   lw    $v0, 0xc4($sp)
/* 065D2C 7F0311FC 8FA400C8 */  lw    $a0, 0xc8($sp)
/* 065D30 7F031200 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 065D34 7F031204 8FA500CC */  lw    $a1, 0xcc($sp)
/* 065D38 7F031208 E4840000 */  swc1  $f4, ($a0)
/* 065D3C 7F03120C C7AA006C */  lwc1  $f10, 0x6c($sp)
/* 065D40 7F031210 E48A0004 */  swc1  $f10, 4($a0)
/* 065D44 7F031214 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 065D48 7F031218 E4860008 */  swc1  $f6, 8($a0)
/* 065D4C 7F03121C C7A8005C */  lwc1  $f8, 0x5c($sp)
/* 065D50 7F031220 E4A80000 */  swc1  $f8, ($a1)
/* 065D54 7F031224 C7A40060 */  lwc1  $f4, 0x60($sp)
/* 065D58 7F031228 E4A40004 */  swc1  $f4, 4($a1)
/* 065D5C 7F03122C C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 065D60 7F031230 1000002D */  b     .L7F0312E8
/* 065D64 7F031234 E4AA0008 */   swc1  $f10, 8($a1)
.L7F031238:
/* 065D68 7F031238 8FB900C0 */  lw    $t9, 0xc0($sp)
/* 065D6C 7F03123C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065D70 7F031240 8FA800D8 */  lw    $t0, 0xd8($sp)
/* 065D74 7F031244 AFB900B4 */  sw    $t9, 0xb4($sp)
/* 065D78 7F031248 C4460008 */  lwc1  $f6, 8($v0)
/* 065D7C 7F03124C 8C470000 */  lw    $a3, ($v0)
/* 065D80 7F031250 8E060008 */  lw    $a2, 8($s0)
/* 065D84 7F031254 8E050000 */  lw    $a1, ($s0)
/* 065D88 7F031258 E7A60010 */  swc1  $f6, 0x10($sp)
/* 065D8C 7F03125C 44813000 */  mtc1  $at, $f6
/* 065D90 7F031260 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 065D94 7F031264 C7A40048 */  lwc1  $f4, 0x48($sp)
/* 065D98 7F031268 44805000 */  mtc1  $zero, $f10
/* 065D9C 7F03126C 27A400B4 */  addiu $a0, $sp, 0xb4
/* 065DA0 7F031270 AFA80014 */  sw    $t0, 0x14($sp)
/* 065DA4 7F031274 E7A80018 */  swc1  $f8, 0x18($sp)
/* 065DA8 7F031278 E7A60024 */  swc1  $f6, 0x24($sp)
/* 065DAC 7F03127C E7A4001C */  swc1  $f4, 0x1c($sp)
/* 065DB0 7F031280 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 065DB4 7F031284 E7AA0020 */   swc1  $f10, 0x20($sp)
/* 065DB8 7F031288 10400010 */  beqz  $v0, .L7F0312CC
/* 065DBC 7F03128C 27A400B4 */   addiu $a0, $sp, 0xb4
/* 065DC0 7F031290 8FA900C4 */  lw    $t1, 0xc4($sp)
/* 065DC4 7F031294 8FAA00D8 */  lw    $t2, 0xd8($sp)
/* 065DC8 7F031298 C7A8004C */  lwc1  $f8, 0x4c($sp)
/* 065DCC 7F03129C C7A40048 */  lwc1  $f4, 0x48($sp)
/* 065DD0 7F0312A0 8D250000 */  lw    $a1, ($t1)
/* 065DD4 7F0312A4 8D260008 */  lw    $a2, 8($t1)
/* 065DD8 7F0312A8 8FA700D4 */  lw    $a3, 0xd4($sp)
/* 065DDC 7F0312AC AFAA0010 */  sw    $t2, 0x10($sp)
/* 065DE0 7F0312B0 E7A80014 */  swc1  $f8, 0x14($sp)
/* 065DE4 7F0312B4 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 065DE8 7F0312B8 E7A40018 */   swc1  $f4, 0x18($sp)
/* 065DEC 7F0312BC 04410003 */  bgez  $v0, .L7F0312CC
/* 065DF0 7F0312C0 240B0001 */   li    $t3, 1
/* 065DF4 7F0312C4 10000008 */  b     .L7F0312E8
/* 065DF8 7F0312C8 AFAB0058 */   sw    $t3, 0x58($sp)
.L7F0312CC:
/* 065DFC 7F0312CC 8FA400C8 */  lw    $a0, 0xc8($sp)
/* 065E00 7F0312D0 0FC2CA2C */  jal   getCollisionEdge_maybe
/* 065E04 7F0312D4 8FA500CC */   lw    $a1, 0xcc($sp)
/* 065E08 7F0312D8 8FA400C8 */  lw    $a0, 0xc8($sp)
/* 065E0C 7F0312DC 8FA500CC */  lw    $a1, 0xcc($sp)
/* 065E10 7F0312E0 0FC0C1D3 */  jal   sub_GAME_7F03074C
/* 065E14 7F0312E4 27A600A8 */   addiu $a2, $sp, 0xa8
.L7F0312E8:
/* 065E18 7F0312E8 8FA400B8 */  lw    $a0, 0xb8($sp)
/* 065E1C 7F0312EC 0FC07D7A */  jal   set_or_unset_GUARDdata_flag
/* 065E20 7F0312F0 24050001 */   li    $a1, 1
/* 065E24 7F0312F4 8FA20058 */  lw    $v0, 0x58($sp)
.L7F0312F8:
/* 065E28 7F0312F8 8FBF0034 */  lw    $ra, 0x34($sp)
/* 065E2C 7F0312FC 8FB00030 */  lw    $s0, 0x30($sp)
/* 065E30 7F031300 27BD00B8 */  addiu $sp, $sp, 0xb8
/* 065E34 7F031304 03E00008 */  jr    $ra
/* 065E38 7F031308 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F03130C(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80052034
.word 0x3f490fdb /*0.78539819*/
glabel D_80052038
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F03130C
/* 065E3C 7F03130C 27BDFF80 */  addiu $sp, $sp, -0x80
/* 065E40 7F031310 AFBF0034 */  sw    $ra, 0x34($sp)
/* 065E44 7F031314 AFB00030 */  sw    $s0, 0x30($sp)
/* 065E48 7F031318 AFA40080 */  sw    $a0, 0x80($sp)
/* 065E4C 7F03131C AFA60088 */  sw    $a2, 0x88($sp)
/* 065E50 7F031320 00A08025 */  move  $s0, $a1
/* 065E54 7F031324 10C00004 */  beqz  $a2, .L7F031338
/* 065E58 7F031328 8C820018 */   lw    $v0, 0x18($a0)
/* 065E5C 7F03132C AFA5004C */  sw    $a1, 0x4c($sp)
/* 065E60 7F031330 10000003 */  b     .L7F031340
/* 065E64 7F031334 AFA70048 */   sw    $a3, 0x48($sp)
.L7F031338:
/* 065E68 7F031338 AFA7004C */  sw    $a3, 0x4c($sp)
/* 065E6C 7F03133C AFB00048 */  sw    $s0, 0x48($sp)
.L7F031340:
/* 065E70 7F031340 C6040000 */  lwc1  $f4, ($s0)
/* 065E74 7F031344 C4460008 */  lwc1  $f6, 8($v0)
/* 065E78 7F031348 44805000 */  mtc1  $zero, $f10
/* 065E7C 7F03134C 46062201 */  sub.s $f8, $f4, $f6
/* 065E80 7F031350 E7AA0074 */  swc1  $f10, 0x74($sp)
/* 065E84 7F031354 E7A80070 */  swc1  $f8, 0x70($sp)
/* 065E88 7F031358 C4460010 */  lwc1  $f6, 0x10($v0)
/* 065E8C 7F03135C C6040008 */  lwc1  $f4, 8($s0)
/* 065E90 7F031360 AFA2007C */  sw    $v0, 0x7c($sp)
/* 065E94 7F031364 46062201 */  sub.s $f8, $f4, $f6
/* 065E98 7F031368 C7A60070 */  lwc1  $f6, 0x70($sp)
/* 065E9C 7F03136C E7A80078 */  swc1  $f8, 0x78($sp)
/* 065EA0 7F031370 C7AA0078 */  lwc1  $f10, 0x78($sp)
/* 065EA4 7F031374 460A5102 */  mul.s $f4, $f10, $f10
/* 065EA8 7F031378 00000000 */  nop   
/* 065EAC 7F03137C 46063202 */  mul.s $f8, $f6, $f6
/* 065EB0 7F031380 0C007DF8 */  jal   sqrtf
/* 065EB4 7F031384 46082300 */   add.s $f12, $f4, $f8
/* 065EB8 7F031388 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 065EBC 7F03138C 44818000 */  mtc1  $at, $f16
/* 065EC0 7F031390 C7B20090 */  lwc1  $f18, 0x90($sp)
/* 065EC4 7F031394 C7AA0070 */  lwc1  $f10, 0x70($sp)
/* 065EC8 7F031398 46008383 */  div.s $f14, $f16, $f0
/* 065ECC 7F03139C C7A40078 */  lwc1  $f4, 0x78($sp)
/* 065ED0 7F0313A0 3C018005 */  lui   $at, %hi(D_80052034)
/* 065ED4 7F0313A4 460E9082 */  mul.s $f2, $f18, $f14
/* 065ED8 7F0313A8 00000000 */  nop   
/* 065EDC 7F0313AC 46025182 */  mul.s $f6, $f10, $f2
/* 065EE0 7F0313B0 4602803C */  c.lt.s $f16, $f2
/* 065EE4 7F0313B4 46022202 */  mul.s $f8, $f4, $f2
/* 065EE8 7F0313B8 E7A60070 */  swc1  $f6, 0x70($sp)
/* 065EEC 7F0313BC 45000003 */  bc1f  .L7F0313CC
/* 065EF0 7F0313C0 E7A80078 */   swc1  $f8, 0x78($sp)
/* 065EF4 7F0313C4 10000005 */  b     .L7F0313DC
/* 065EF8 7F0313C8 C42C2034 */   lwc1  $f12, %lo(D_80052034)($at)
.L7F0313CC:
/* 065EFC 7F0313CC 460E9302 */  mul.s $f12, $f18, $f14
/* 065F00 7F0313D0 0FC16B2C */  jal   acosf
/* 065F04 7F0313D4 00000000 */   nop   
/* 065F08 7F0313D8 46000306 */  mov.s $f12, $f0
.L7F0313DC:
/* 065F0C 7F0313DC 8FB80088 */  lw    $t8, 0x88($sp)
/* 065F10 7F0313E0 17000009 */  bnez  $t8, .L7F031408
/* 065F14 7F0313E4 00000000 */   nop   
/* 065F18 7F0313E8 44805000 */  mtc1  $zero, $f10
/* 065F1C 7F0313EC 3C018005 */  lui   $at, %hi(D_80052038)
/* 065F20 7F0313F0 460A6032 */  c.eq.s $f12, $f10
/* 065F24 7F0313F4 00000000 */  nop   
/* 065F28 7F0313F8 45010003 */  bc1t  .L7F031408
/* 065F2C 7F0313FC 00000000 */   nop   
/* 065F30 7F031400 C4262038 */  lwc1  $f6, %lo(D_80052038)($at)
/* 065F34 7F031404 460C3301 */  sub.s $f12, $f6, $f12
.L7F031408:
/* 065F38 7F031408 0FC15FA8 */  jal   cosf
/* 065F3C 7F03140C E7AC005C */   swc1  $f12, 0x5c($sp)
/* 065F40 7F031410 C7AC005C */  lwc1  $f12, 0x5c($sp)
/* 065F44 7F031414 0FC15FAB */  jal   sinf
/* 065F48 7F031418 E7A00040 */   swc1  $f0, 0x40($sp)
/* 065F4C 7F03141C C7A40040 */  lwc1  $f4, 0x40($sp)
/* 065F50 7F031420 C7AA0070 */  lwc1  $f10, 0x70($sp)
/* 065F54 7F031424 C7AC005C */  lwc1  $f12, 0x5c($sp)
/* 065F58 7F031428 46002207 */  neg.s $f8, $f4
/* 065F5C 7F03142C C7A40078 */  lwc1  $f4, 0x78($sp)
/* 065F60 7F031430 460A4182 */  mul.s $f6, $f8, $f10
/* 065F64 7F031434 00000000 */  nop   
/* 065F68 7F031438 46002202 */  mul.s $f8, $f4, $f0
/* 065F6C 7F03143C 44802000 */  mtc1  $zero, $f4
/* 065F70 7F031440 00000000 */  nop   
/* 065F74 7F031444 E7A40054 */  swc1  $f4, 0x54($sp)
/* 065F78 7F031448 46064280 */  add.s $f10, $f8, $f6
/* 065F7C 7F03144C 0FC15FAB */  jal   sinf
/* 065F80 7F031450 E7AA0050 */   swc1  $f10, 0x50($sp)
/* 065F84 7F031454 C7AC005C */  lwc1  $f12, 0x5c($sp)
/* 065F88 7F031458 0FC15FA8 */  jal   cosf
/* 065F8C 7F03145C E7A00040 */   swc1  $f0, 0x40($sp)
/* 065F90 7F031460 C7A80040 */  lwc1  $f8, 0x40($sp)
/* 065F94 7F031464 C7AA0070 */  lwc1  $f10, 0x70($sp)
/* 065F98 7F031468 8FA2007C */  lw    $v0, 0x7c($sp)
/* 065F9C 7F03146C 46004187 */  neg.s $f6, $f8
/* 065FA0 7F031470 C7A80078 */  lwc1  $f8, 0x78($sp)
/* 065FA4 7F031474 460A3102 */  mul.s $f4, $f6, $f10
/* 065FA8 7F031478 8FB9004C */  lw    $t9, 0x4c($sp)
/* 065FAC 7F03147C 8FA80048 */  lw    $t0, 0x48($sp)
/* 065FB0 7F031480 46004182 */  mul.s $f6, $f8, $f0
/* 065FB4 7F031484 C7A80050 */  lwc1  $f8, 0x50($sp)
/* 065FB8 7F031488 8FA40080 */  lw    $a0, 0x80($sp)
/* 065FBC 7F03148C 8FA900A4 */  lw    $t1, 0xa4($sp)
/* 065FC0 7F031490 24450008 */  addiu $a1, $v0, 8
/* 065FC4 7F031494 27A70064 */  addiu $a3, $sp, 0x64
/* 065FC8 7F031498 46062281 */  sub.s $f10, $f4, $f6
/* 065FCC 7F03149C E7AA0058 */  swc1  $f10, 0x58($sp)
/* 065FD0 7F0314A0 C6040000 */  lwc1  $f4, ($s0)
/* 065FD4 7F0314A4 46044180 */  add.s $f6, $f8, $f4
/* 065FD8 7F0314A8 E7A60064 */  swc1  $f6, 0x64($sp)
/* 065FDC 7F0314AC C6080004 */  lwc1  $f8, 4($s0)
/* 065FE0 7F0314B0 E7A80068 */  swc1  $f8, 0x68($sp)
/* 065FE4 7F0314B4 C6040008 */  lwc1  $f4, 8($s0)
/* 065FE8 7F0314B8 C7A800A0 */  lwc1  $f8, 0xa0($sp)
/* 065FEC 7F0314BC 46045180 */  add.s $f6, $f10, $f4
/* 065FF0 7F0314C0 E7A6006C */  swc1  $f6, 0x6c($sp)
/* 065FF4 7F0314C4 8C460014 */  lw    $a2, 0x14($v0)
/* 065FF8 7F0314C8 AFB90010 */  sw    $t9, 0x10($sp)
/* 065FFC 7F0314CC AFA80014 */  sw    $t0, 0x14($sp)
/* 066000 7F0314D0 E7A80018 */  swc1  $f8, 0x18($sp)
/* 066004 7F0314D4 C48A0024 */  lwc1  $f10, 0x24($a0)
/* 066008 7F0314D8 AFA5003C */  sw    $a1, 0x3c($sp)
/* 06600C 7F0314DC AFA90020 */  sw    $t1, 0x20($sp)
/* 066010 7F0314E0 0FC0C207 */  jal   sub_GAME_7F03081C
/* 066014 7F0314E4 E7AA001C */   swc1  $f10, 0x1c($sp)
/* 066018 7F0314E8 10400028 */  beqz  $v0, .L7F03158C
/* 06601C 7F0314EC 8FA5003C */   lw    $a1, 0x3c($sp)
/* 066020 7F0314F0 8FAA0094 */  lw    $t2, 0x94($sp)
/* 066024 7F0314F4 8FA40080 */  lw    $a0, 0x80($sp)
/* 066028 7F0314F8 8FAB007C */  lw    $t3, 0x7c($sp)
/* 06602C 7F0314FC 1140000A */  beqz  $t2, .L7F031528
/* 066030 7F031500 27A70064 */   addiu $a3, $sp, 0x64
/* 066034 7F031504 8FAC0098 */  lw    $t4, 0x98($sp)
/* 066038 7F031508 8FAD00A4 */  lw    $t5, 0xa4($sp)
/* 06603C 7F03150C 8D660014 */  lw    $a2, 0x14($t3)
/* 066040 7F031510 AFA00014 */  sw    $zero, 0x14($sp)
/* 066044 7F031514 AFAC0010 */  sw    $t4, 0x10($sp)
/* 066048 7F031518 0FC0C12B */  jal   sub_GAME_7F0304AC
/* 06604C 7F03151C AFAD0018 */   sw    $t5, 0x18($sp)
/* 066050 7F031520 5040001B */  beql  $v0, $zero, .L7F031590
/* 066054 7F031524 00001025 */   move  $v0, $zero
.L7F031528:
/* 066058 7F031528 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 06605C 7F03152C 8FA2009C */  lw    $v0, 0x9c($sp)
/* 066060 7F031530 24180001 */  li    $t8, 1
/* 066064 7F031534 51C0000D */  beql  $t6, $zero, .L7F03156C
/* 066068 7F031538 A0580002 */   sb    $t8, 2($v0)
/* 06606C 7F03153C 8FA2009C */  lw    $v0, 0x9c($sp)
/* 066070 7F031540 240F0001 */  li    $t7, 1
/* 066074 7F031544 A04F0003 */  sb    $t7, 3($v0)
/* 066078 7F031548 C7A40064 */  lwc1  $f4, 0x64($sp)
/* 06607C 7F03154C E444002C */  swc1  $f4, 0x2c($v0)
/* 066080 7F031550 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 066084 7F031554 E4460030 */  swc1  $f6, 0x30($v0)
/* 066088 7F031558 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 06608C 7F03155C E4480034 */  swc1  $f8, 0x34($v0)
/* 066090 7F031560 1000000B */  b     .L7F031590
/* 066094 7F031564 24020001 */   li    $v0, 1
/* 066098 7F031568 A0580002 */  sb    $t8, 2($v0)
.L7F03156C:
/* 06609C 7F03156C C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0660A0 7F031570 E44A0004 */  swc1  $f10, 4($v0)
/* 0660A4 7F031574 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 0660A8 7F031578 E4440008 */  swc1  $f4, 8($v0)
/* 0660AC 7F03157C C7A6006C */  lwc1  $f6, 0x6c($sp)
/* 0660B0 7F031580 E446000C */  swc1  $f6, 0xc($v0)
/* 0660B4 7F031584 10000002 */  b     .L7F031590
/* 0660B8 7F031588 24020001 */   li    $v0, 1
.L7F03158C:
/* 0660BC 7F03158C 00001025 */  move  $v0, $zero
.L7F031590:
/* 0660C0 7F031590 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0660C4 7F031594 8FB00030 */  lw    $s0, 0x30($sp)
/* 0660C8 7F031598 27BD0080 */  addiu $sp, $sp, 0x80
/* 0660CC 7F03159C 03E00008 */  jr    $ra
/* 0660D0 7F0315A0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0315A4(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005203C
.word 0x40490fdb /*3.1415927*/
glabel D_80052040
.word 0x40c90fdb /*6.2831855*/
glabel D_80052044
.word 0x3f99999a /*1.2*/
glabel D_80052048
.word 0x3f866666 /*1.05*/
glabel D_8005204C
.word 0x3f99999a /*1.2*/
glabel D_80052050
.word 0x3f866666 /*1.05*/
glabel D_80052054
.word 0x3f99999a /*1.2*/
glabel D_80052058
.word 0x3f866666 /*1.05*/
glabel D_8005205C
.word 0x3f8ccccd /*1.1*/
glabel D_80052060
.word 0x3f8ccccd /*1.1*/
glabel D_80052064
.word 0x471c4000 /*40000.0*/
.text
glabel sub_GAME_7F0315A4
/* 0660D4 7F0315A4 27BDFEF0 */  addiu $sp, $sp, -0x110
/* 0660D8 7F0315A8 AFBF0084 */  sw    $ra, 0x84($sp)
/* 0660DC 7F0315AC AFB70080 */  sw    $s7, 0x80($sp)
/* 0660E0 7F0315B0 AFB6007C */  sw    $s6, 0x7c($sp)
/* 0660E4 7F0315B4 AFB50078 */  sw    $s5, 0x78($sp)
/* 0660E8 7F0315B8 AFB40074 */  sw    $s4, 0x74($sp)
/* 0660EC 7F0315BC AFB30070 */  sw    $s3, 0x70($sp)
/* 0660F0 7F0315C0 AFB2006C */  sw    $s2, 0x6c($sp)
/* 0660F4 7F0315C4 AFB10068 */  sw    $s1, 0x68($sp)
/* 0660F8 7F0315C8 AFB00064 */  sw    $s0, 0x64($sp)
/* 0660FC 7F0315CC F7BE0058 */  sdc1  $f30, 0x58($sp)
/* 066100 7F0315D0 F7BC0050 */  sdc1  $f28, 0x50($sp)
/* 066104 7F0315D4 F7BA0048 */  sdc1  $f26, 0x48($sp)
/* 066108 7F0315D8 F7B80040 */  sdc1  $f24, 0x40($sp)
/* 06610C 7F0315DC F7B60038 */  sdc1  $f22, 0x38($sp)
/* 066110 7F0315E0 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 066114 7F0315E4 AFA60118 */  sw    $a2, 0x118($sp)
/* 066118 7F0315E8 948E0012 */  lhu   $t6, 0x12($a0)
/* 06611C 7F0315EC 00E08025 */  move  $s0, $a3
/* 066120 7F0315F0 00809025 */  move  $s2, $a0
/* 066124 7F0315F4 31CF0010 */  andi  $t7, $t6, 0x10
/* 066128 7F0315F8 00A0A025 */  move  $s4, $a1
/* 06612C 7F0315FC 8C910018 */  lw    $s1, 0x18($a0)
/* 066130 7F031600 11E00002 */  beqz  $t7, .L7F03160C
/* 066134 7F031604 3416801D */   li    $s6, 32797
/* 066138 7F031608 2416001F */  li    $s6, 31
.L7F03160C:
/* 06613C 7F03160C 3C018005 */  lui   $at, %hi(D_8005203C)
/* 066140 7F031610 C43E203C */  lwc1  $f30, %lo(D_8005203C)($at)
/* 066144 7F031614 3C018005 */  lui   $at, %hi(D_80052040)
/* 066148 7F031618 4480E000 */  mtc1  $zero, $f28
/* 06614C 7F03161C C43A2040 */  lwc1  $f26, %lo(D_80052040)($at)
/* 066150 7F031620 AFA000F0 */  sw    $zero, 0xf0($sp)
/* 066154 7F031624 24170001 */  li    $s7, 1
/* 066158 7F031628 24150004 */  li    $s5, 4
/* 06615C 7F03162C 27B300F4 */  addiu $s3, $sp, 0xf4
.L7F031630:
/* 066160 7F031630 82020000 */  lb    $v0, ($s0)
/* 066164 7F031634 24010002 */  li    $at, 2
/* 066168 7F031638 50400004 */  beql  $v0, $zero, .L7F03164C
/* 06616C 7F03163C C6840000 */   lwc1  $f4, ($s4)
/* 066170 7F031640 1441002D */  bne   $v0, $at, .L7F0316F8
/* 066174 7F031644 00000000 */   nop   
/* 066178 7F031648 C6840000 */  lwc1  $f4, ($s4)
.L7F03164C:
/* 06617C 7F03164C 26180010 */  addiu $t8, $s0, 0x10
/* 066180 7F031650 2619001C */  addiu $t9, $s0, 0x1c
/* 066184 7F031654 E7A40100 */  swc1  $f4, 0x100($sp)
/* 066188 7F031658 C6860004 */  lwc1  $f6, 4($s4)
/* 06618C 7F03165C 24080010 */  li    $t0, 16
/* 066190 7F031660 02402025 */  move  $a0, $s2
/* 066194 7F031664 E7A60104 */  swc1  $f6, 0x104($sp)
/* 066198 7F031668 C6880008 */  lwc1  $f8, 8($s4)
/* 06619C 7F03166C 26250008 */  addiu $a1, $s1, 8
/* 0661A0 7F031670 27A70100 */  addiu $a3, $sp, 0x100
/* 0661A4 7F031674 E7A80108 */  swc1  $f8, 0x108($sp)
/* 0661A8 7F031678 8E260014 */  lw    $a2, 0x14($s1)
/* 0661AC 7F03167C AFB90014 */  sw    $t9, 0x14($sp)
/* 0661B0 7F031680 AFB80010 */  sw    $t8, 0x10($sp)
/* 0661B4 7F031684 C6400024 */  lwc1  $f0, 0x24($s2)
/* 0661B8 7F031688 AFA80020 */  sw    $t0, 0x20($sp)
/* 0661BC 7F03168C 46000287 */  neg.s $f10, $f0
/* 0661C0 7F031690 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 0661C4 7F031694 0FC0C207 */  jal   sub_GAME_7F03081C
/* 0661C8 7F031698 E7AA0018 */   swc1  $f10, 0x18($sp)
/* 0661CC 7F03169C 5040000B */  beql  $v0, $zero, .L7F0316CC
/* 0661D0 7F0316A0 82020000 */   lb    $v0, ($s0)
/* 0661D4 7F0316A4 A2170002 */  sb    $s7, 2($s0)
/* 0661D8 7F0316A8 C7B20100 */  lwc1  $f18, 0x100($sp)
/* 0661DC 7F0316AC E6120004 */  swc1  $f18, 4($s0)
/* 0661E0 7F0316B0 C7A40104 */  lwc1  $f4, 0x104($sp)
/* 0661E4 7F0316B4 E6040008 */  swc1  $f4, 8($s0)
/* 0661E8 7F0316B8 C7A60108 */  lwc1  $f6, 0x108($sp)
/* 0661EC 7F0316BC A2150000 */  sb    $s5, ($s0)
/* 0661F0 7F0316C0 1000019B */  b     .L7F031D30
/* 0661F4 7F0316C4 E606000C */   swc1  $f6, 0xc($s0)
/* 0661F8 7F0316C8 82020000 */  lb    $v0, ($s0)
.L7F0316CC:
/* 0661FC 7F0316CC 24010002 */  li    $at, 2
/* 066200 7F0316D0 14400004 */  bnez  $v0, .L7F0316E4
/* 066204 7F0316D4 00000000 */   nop   
/* 066208 7F0316D8 A2170000 */  sb    $s7, ($s0)
/* 06620C 7F0316DC 10000194 */  b     .L7F031D30
/* 066210 7F0316E0 A2000001 */   sb    $zero, 1($s0)
.L7F0316E4:
/* 066214 7F0316E4 14410192 */  bne   $v0, $at, .L7F031D30
/* 066218 7F0316E8 24090003 */   li    $t1, 3
/* 06621C 7F0316EC A2090000 */  sb    $t1, ($s0)
/* 066220 7F0316F0 1000018F */  b     .L7F031D30
/* 066224 7F0316F4 A2000001 */   sb    $zero, 1($s0)
.L7F0316F8:
/* 066228 7F0316F8 16E20035 */  bne   $s7, $v0, .L7F0317D0
/* 06622C 7F0316FC 24010003 */   li    $at, 3
/* 066230 7F031700 3C018005 */  lui   $at, %hi(D_80052044)
/* 066234 7F031704 C42A2044 */  lwc1  $f10, %lo(D_80052044)($at)
/* 066238 7F031708 C6480024 */  lwc1  $f8, 0x24($s2)
/* 06623C 7F03170C 3C018005 */  lui   $at, %hi(D_80052048)
/* 066240 7F031710 C4242048 */  lwc1  $f4, %lo(D_80052048)($at)
/* 066244 7F031714 460A4482 */  mul.s $f18, $f8, $f10
/* 066248 7F031718 240A0010 */  li    $t2, 16
/* 06624C 7F03171C AFAA0024 */  sw    $t2, 0x24($sp)
/* 066250 7F031720 AFA00028 */  sw    $zero, 0x28($sp)
/* 066254 7F031724 E7BC0020 */  swc1  $f28, 0x20($sp)
/* 066258 7F031728 AFB0001C */  sw    $s0, 0x1c($sp)
/* 06625C 7F03172C AFB40018 */  sw    $s4, 0x18($sp)
/* 066260 7F031730 46049002 */  mul.s $f0, $f18, $f4
/* 066264 7F031734 AFB70014 */  sw    $s7, 0x14($sp)
/* 066268 7F031738 02402025 */  move  $a0, $s2
/* 06626C 7F03173C 26050010 */  addiu $a1, $s0, 0x10
/* 066270 7F031740 02E03025 */  move  $a2, $s7
/* 066274 7F031744 02603825 */  move  $a3, $s3
/* 066278 7F031748 E7A00010 */  swc1  $f0, 0x10($sp)
/* 06627C 7F03174C 0FC0C4C3 */  jal   sub_GAME_7F03130C
/* 066280 7F031750 E7A000E8 */   swc1  $f0, 0xe8($sp)
/* 066284 7F031754 10400003 */  beqz  $v0, .L7F031764
/* 066288 7F031758 C7A000E8 */   lwc1  $f0, 0xe8($sp)
/* 06628C 7F03175C 10000174 */  b     .L7F031D30
/* 066290 7F031760 A2150000 */   sb    $s5, ($s0)
.L7F031764:
/* 066294 7F031764 240B0010 */  li    $t3, 16
/* 066298 7F031768 AFAB0024 */  sw    $t3, 0x24($sp)
/* 06629C 7F03176C 02402025 */  move  $a0, $s2
/* 0662A0 7F031770 2605001C */  addiu $a1, $s0, 0x1c
/* 0662A4 7F031774 00003025 */  move  $a2, $zero
/* 0662A8 7F031778 02603825 */  move  $a3, $s3
/* 0662AC 7F03177C E7A00010 */  swc1  $f0, 0x10($sp)
/* 0662B0 7F031780 AFB70014 */  sw    $s7, 0x14($sp)
/* 0662B4 7F031784 AFB40018 */  sw    $s4, 0x18($sp)
/* 0662B8 7F031788 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0662BC 7F03178C E7BC0020 */  swc1  $f28, 0x20($sp)
/* 0662C0 7F031790 0FC0C4C3 */  jal   sub_GAME_7F03130C
/* 0662C4 7F031794 AFA00028 */   sw    $zero, 0x28($sp)
/* 0662C8 7F031798 50400004 */  beql  $v0, $zero, .L7F0317AC
/* 0662CC 7F03179C 820C0001 */   lb    $t4, 1($s0)
/* 0662D0 7F0317A0 10000163 */  b     .L7F031D30
/* 0662D4 7F0317A4 A2150000 */   sb    $s5, ($s0)
/* 0662D8 7F0317A8 820C0001 */  lb    $t4, 1($s0)
.L7F0317AC:
/* 0662DC 7F0317AC 240F0002 */  li    $t7, 2
/* 0662E0 7F0317B0 258D0001 */  addiu $t5, $t4, 1
/* 0662E4 7F0317B4 A20D0001 */  sb    $t5, 1($s0)
/* 0662E8 7F0317B8 820E0001 */  lb    $t6, 1($s0)
/* 0662EC 7F0317BC 29C10006 */  slti  $at, $t6, 6
/* 0662F0 7F0317C0 5420015C */  bnezl $at, .L7F031D34
/* 0662F4 7F0317C4 8FA800F0 */   lw    $t0, 0xf0($sp)
/* 0662F8 7F0317C8 10000159 */  b     .L7F031D30
/* 0662FC 7F0317CC A20F0000 */   sb    $t7, ($s0)
.L7F0317D0:
/* 066300 7F0317D0 1441003F */  bne   $v0, $at, .L7F0318D0
/* 066304 7F0317D4 3C018005 */   lui   $at, %hi(D_8005204C)
/* 066308 7F0317D8 C428204C */  lwc1  $f8, %lo(D_8005204C)($at)
/* 06630C 7F0317DC C6460024 */  lwc1  $f6, 0x24($s2)
/* 066310 7F0317E0 3C018005 */  lui   $at, %hi(D_80052050)
/* 066314 7F0317E4 C4322050 */  lwc1  $f18, %lo(D_80052050)($at)
/* 066318 7F0317E8 46083282 */  mul.s $f10, $f6, $f8
/* 06631C 7F0317EC 24180010 */  li    $t8, 16
/* 066320 7F0317F0 AFB80024 */  sw    $t8, 0x24($sp)
/* 066324 7F0317F4 AFA00028 */  sw    $zero, 0x28($sp)
/* 066328 7F0317F8 E7BC0020 */  swc1  $f28, 0x20($sp)
/* 06632C 7F0317FC AFB0001C */  sw    $s0, 0x1c($sp)
/* 066330 7F031800 AFA00018 */  sw    $zero, 0x18($sp)
/* 066334 7F031804 46125002 */  mul.s $f0, $f10, $f18
/* 066338 7F031808 AFA00014 */  sw    $zero, 0x14($sp)
/* 06633C 7F03180C 02402025 */  move  $a0, $s2
/* 066340 7F031810 26050010 */  addiu $a1, $s0, 0x10
/* 066344 7F031814 02E03025 */  move  $a2, $s7
/* 066348 7F031818 02603825 */  move  $a3, $s3
/* 06634C 7F03181C E7A00010 */  swc1  $f0, 0x10($sp)
/* 066350 7F031820 0FC0C4C3 */  jal   sub_GAME_7F03130C
/* 066354 7F031824 E7A000E4 */   swc1  $f0, 0xe4($sp)
/* 066358 7F031828 10400003 */  beqz  $v0, .L7F031838
/* 06635C 7F03182C C7A000E4 */   lwc1  $f0, 0xe4($sp)
/* 066360 7F031830 1000013F */  b     .L7F031D30
/* 066364 7F031834 A2150000 */   sb    $s5, ($s0)
.L7F031838:
/* 066368 7F031838 24190010 */  li    $t9, 16
/* 06636C 7F03183C AFB90024 */  sw    $t9, 0x24($sp)
/* 066370 7F031840 02402025 */  move  $a0, $s2
/* 066374 7F031844 2605001C */  addiu $a1, $s0, 0x1c
/* 066378 7F031848 00003025 */  move  $a2, $zero
/* 06637C 7F03184C 02603825 */  move  $a3, $s3
/* 066380 7F031850 E7A00010 */  swc1  $f0, 0x10($sp)
/* 066384 7F031854 AFA00014 */  sw    $zero, 0x14($sp)
/* 066388 7F031858 AFA00018 */  sw    $zero, 0x18($sp)
/* 06638C 7F03185C AFB0001C */  sw    $s0, 0x1c($sp)
/* 066390 7F031860 E7BC0020 */  swc1  $f28, 0x20($sp)
/* 066394 7F031864 0FC0C4C3 */  jal   sub_GAME_7F03130C
/* 066398 7F031868 AFA00028 */   sw    $zero, 0x28($sp)
/* 06639C 7F03186C 50400004 */  beql  $v0, $zero, .L7F031880
/* 0663A0 7F031870 82080001 */   lb    $t0, 1($s0)
/* 0663A4 7F031874 1000012E */  b     .L7F031D30
/* 0663A8 7F031878 A2150000 */   sb    $s5, ($s0)
/* 0663AC 7F03187C 82080001 */  lb    $t0, 1($s0)
.L7F031880:
/* 0663B0 7F031880 25090001 */  addiu $t1, $t0, 1
/* 0663B4 7F031884 A2090001 */  sb    $t1, 1($s0)
/* 0663B8 7F031888 820A0001 */  lb    $t2, 1($s0)
/* 0663BC 7F03188C 29410006 */  slti  $at, $t2, 6
/* 0663C0 7F031890 54200128 */  bnezl $at, .L7F031D34
/* 0663C4 7F031894 8FA800F0 */   lw    $t0, 0xf0($sp)
/* 0663C8 7F031898 A2000002 */  sb    $zero, 2($s0)
/* 0663CC 7F03189C 820B0002 */  lb    $t3, 2($s0)
/* 0663D0 7F0318A0 A20B0003 */  sb    $t3, 3($s0)
/* 0663D4 7F0318A4 C6800000 */  lwc1  $f0, ($s4)
/* 0663D8 7F0318A8 E6000004 */  swc1  $f0, 4($s0)
/* 0663DC 7F0318AC E600002C */  swc1  $f0, 0x2c($s0)
/* 0663E0 7F0318B0 C6800004 */  lwc1  $f0, 4($s4)
/* 0663E4 7F0318B4 E6000008 */  swc1  $f0, 8($s0)
/* 0663E8 7F0318B8 E6000030 */  swc1  $f0, 0x30($s0)
/* 0663EC 7F0318BC C6800008 */  lwc1  $f0, 8($s4)
/* 0663F0 7F0318C0 A2000000 */  sb    $zero, ($s0)
/* 0663F4 7F0318C4 E600000C */  swc1  $f0, 0xc($s0)
/* 0663F8 7F0318C8 10000119 */  b     .L7F031D30
/* 0663FC 7F0318CC E6000034 */   swc1  $f0, 0x34($s0)
.L7F0318D0:
/* 066400 7F0318D0 16A2001D */  bne   $s5, $v0, .L7F031948
/* 066404 7F0318D4 24010005 */   li    $at, 5
/* 066408 7F0318D8 8E260014 */  lw    $a2, 0x14($s1)
/* 06640C 7F0318DC 260C0010 */  addiu $t4, $s0, 0x10
/* 066410 7F0318E0 260D001C */  addiu $t5, $s0, 0x1c
/* 066414 7F0318E4 AFAD0014 */  sw    $t5, 0x14($sp)
/* 066418 7F0318E8 AFAC0010 */  sw    $t4, 0x10($sp)
/* 06641C 7F0318EC C6400024 */  lwc1  $f0, 0x24($s2)
/* 066420 7F0318F0 AFB60020 */  sw    $s6, 0x20($sp)
/* 066424 7F0318F4 02402025 */  move  $a0, $s2
/* 066428 7F0318F8 46000107 */  neg.s $f4, $f0
/* 06642C 7F0318FC 26250008 */  addiu $a1, $s1, 8
/* 066430 7F031900 E7A40018 */  swc1  $f4, 0x18($sp)
/* 066434 7F031904 26070004 */  addiu $a3, $s0, 4
/* 066438 7F031908 0FC0C35C */  jal   sub_GAME_7F030D70
/* 06643C 7F03190C E7A0001C */   swc1  $f0, 0x1c($sp)
/* 066440 7F031910 1040000A */  beqz  $v0, .L7F03193C
/* 066444 7F031914 240E0005 */   li    $t6, 5
/* 066448 7F031918 C6060004 */  lwc1  $f6, 4($s0)
/* 06644C 7F03191C C6080008 */  lwc1  $f8, 8($s0)
/* 066450 7F031920 C60A000C */  lwc1  $f10, 0xc($s0)
/* 066454 7F031924 A2170003 */  sb    $s7, 3($s0)
/* 066458 7F031928 A2000000 */  sb    $zero, ($s0)
/* 06645C 7F03192C E606002C */  swc1  $f6, 0x2c($s0)
/* 066460 7F031930 E6080030 */  swc1  $f8, 0x30($s0)
/* 066464 7F031934 100000FE */  b     .L7F031D30
/* 066468 7F031938 E60A0034 */   swc1  $f10, 0x34($s0)
.L7F03193C:
/* 06646C 7F03193C A20E0000 */  sb    $t6, ($s0)
/* 066470 7F031940 100000FB */  b     .L7F031D30
/* 066474 7F031944 A2000001 */   sb    $zero, 1($s0)
.L7F031948:
/* 066478 7F031948 144100F9 */  bne   $v0, $at, .L7F031D30
/* 06647C 7F03194C 3C018005 */   lui   $at, %hi(D_80052054)
/* 066480 7F031950 C4242054 */  lwc1  $f4, %lo(D_80052054)($at)
/* 066484 7F031954 C6520024 */  lwc1  $f18, 0x24($s2)
/* 066488 7F031958 3C018005 */  lui   $at, %hi(D_80052058)
/* 06648C 7F03195C C4282058 */  lwc1  $f8, %lo(D_80052058)($at)
/* 066490 7F031960 46049182 */  mul.s $f6, $f18, $f4
/* 066494 7F031964 C604000C */  lwc1  $f4, 0xc($s0)
/* 066498 7F031968 C6320008 */  lwc1  $f18, 8($s1)
/* 06649C 7F03196C C60A0004 */  lwc1  $f10, 4($s0)
/* 0664A0 7F031970 46125301 */  sub.s $f12, $f10, $f18
/* 0664A4 7F031974 46083602 */  mul.s $f24, $f6, $f8
/* 0664A8 7F031978 C6260010 */  lwc1  $f6, 0x10($s1)
/* 0664AC 7F03197C 0FC16A8C */  jal   atan2f
/* 0664B0 7F031980 46062381 */   sub.s $f14, $f4, $f6
/* 0664B4 7F031984 C6160010 */  lwc1  $f22, 0x10($s0)
/* 0664B8 7F031988 C6320008 */  lwc1  $f18, 8($s1)
/* 0664BC 7F03198C C6100018 */  lwc1  $f16, 0x18($s0)
/* 0664C0 7F031990 C62A0010 */  lwc1  $f10, 0x10($s1)
/* 0664C4 7F031994 4612B301 */  sub.s $f12, $f22, $f18
/* 0664C8 7F031998 46000506 */  mov.s $f20, $f0
/* 0664CC 7F03199C 0FC16A8C */  jal   atan2f
/* 0664D0 7F0319A0 460A8381 */   sub.s $f14, $f16, $f10
/* 0664D4 7F0319A4 4600A581 */  sub.s $f22, $f20, $f0
/* 0664D8 7F0319A8 C612001C */  lwc1  $f18, 0x1c($s0)
/* 0664DC 7F0319AC C6300008 */  lwc1  $f16, 8($s1)
/* 0664E0 7F0319B0 C60A0024 */  lwc1  $f10, 0x24($s0)
/* 0664E4 7F0319B4 C6280010 */  lwc1  $f8, 0x10($s1)
/* 0664E8 7F0319B8 46109301 */  sub.s $f12, $f18, $f16
/* 0664EC 7F0319BC E7B600D4 */  swc1  $f22, 0xd4($sp)
/* 0664F0 7F0319C0 0FC16A8C */  jal   atan2f
/* 0664F4 7F0319C4 46085381 */   sub.s $f14, $f10, $f8
/* 0664F8 7F0319C8 C7B000D4 */  lwc1  $f16, 0xd4($sp)
/* 0664FC 7F0319CC 4600A301 */  sub.s $f12, $f20, $f0
/* 066500 7F0319D0 02603825 */  move  $a3, $s3
/* 066504 7F0319D4 02402025 */  move  $a0, $s2
/* 066508 7F0319D8 461C803C */  c.lt.s $f16, $f28
/* 06650C 7F0319DC 46006086 */  mov.s $f2, $f12
/* 066510 7F0319E0 2605001C */  addiu $a1, $s0, 0x1c
/* 066514 7F0319E4 00003025 */  move  $a2, $zero
/* 066518 7F0319E8 45000002 */  bc1f  .L7F0319F4
/* 06651C 7F0319EC 3C018005 */   lui   $at, %hi(D_80052060)
/* 066520 7F0319F0 461A8400 */  add.s $f16, $f16, $f26
.L7F0319F4:
/* 066524 7F0319F4 4610F03E */  c.le.s $f30, $f16
/* 066528 7F0319F8 00000000 */  nop   
/* 06652C 7F0319FC 45020003 */  bc1fl .L7F031A0C
/* 066530 7F031A00 461C803C */   c.lt.s $f16, $f28
/* 066534 7F031A04 461A8401 */  sub.s $f16, $f16, $f26
/* 066538 7F031A08 461C803C */  c.lt.s $f16, $f28
.L7F031A0C:
/* 06653C 7F031A0C 00000000 */  nop   
/* 066540 7F031A10 45020003 */  bc1fl .L7F031A20
/* 066544 7F031A14 461C603C */   c.lt.s $f12, $f28
/* 066548 7F031A18 46008407 */  neg.s $f16, $f16
/* 06654C 7F031A1C 461C603C */  c.lt.s $f12, $f28
.L7F031A20:
/* 066550 7F031A20 00000000 */  nop   
/* 066554 7F031A24 45020003 */  bc1fl .L7F031A34
/* 066558 7F031A28 4602F03E */   c.le.s $f30, $f2
/* 06655C 7F031A2C 461A6080 */  add.s $f2, $f12, $f26
/* 066560 7F031A30 4602F03E */  c.le.s $f30, $f2
.L7F031A34:
/* 066564 7F031A34 00000000 */  nop   
/* 066568 7F031A38 45020003 */  bc1fl .L7F031A48
/* 06656C 7F031A3C 461C103C */   c.lt.s $f2, $f28
/* 066570 7F031A40 461A1081 */  sub.s $f2, $f2, $f26
/* 066574 7F031A44 461C103C */  c.lt.s $f2, $f28
.L7F031A48:
/* 066578 7F031A48 00000000 */  nop   
/* 06657C 7F031A4C 45020003 */  bc1fl .L7F031A5C
/* 066580 7F031A50 4602803C */   c.lt.s $f16, $f2
/* 066584 7F031A54 46001087 */  neg.s $f2, $f2
/* 066588 7F031A58 4602803C */  c.lt.s $f16, $f2
.L7F031A5C:
/* 06658C 7F031A5C 00000000 */  nop   
/* 066590 7F031A60 45000057 */  bc1f  .L7F031BC0
/* 066594 7F031A64 00000000 */   nop   
/* 066598 7F031A68 3C018005 */  lui   $at, %hi(D_80052060)
/* 06659C 7F031A6C C424205C */  lwc1  $f4, %lo(D_8005205C)($at)
/* 0665A0 7F031A70 02402025 */  move  $a0, $s2
/* 0665A4 7F031A74 26050010 */  addiu $a1, $s0, 0x10
/* 0665A8 7F031A78 4604C582 */  mul.s $f22, $f24, $f4
/* 0665AC 7F031A7C 02E03025 */  move  $a2, $s7
/* 0665B0 7F031A80 E7B80010 */  swc1  $f24, 0x10($sp)
/* 0665B4 7F031A84 AFA00014 */  sw    $zero, 0x14($sp)
/* 0665B8 7F031A88 AFA00018 */  sw    $zero, 0x18($sp)
/* 0665BC 7F031A8C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0665C0 7F031A90 AFB60024 */  sw    $s6, 0x24($sp)
/* 0665C4 7F031A94 E7B60020 */  swc1  $f22, 0x20($sp)
/* 0665C8 7F031A98 0FC0C4C3 */  jal   sub_GAME_7F03130C
/* 0665CC 7F031A9C AFB70028 */   sw    $s7, 0x28($sp)
/* 0665D0 7F031AA0 50400004 */  beql  $v0, $zero, .L7F031AB4
/* 0665D4 7F031AA4 C6060010 */   lwc1  $f6, 0x10($s0)
/* 0665D8 7F031AA8 100000A5 */  b     .L7F031D40
/* 0665DC 7F031AAC A2000000 */   sb    $zero, ($s0)
/* 0665E0 7F031AB0 C6060010 */  lwc1  $f6, 0x10($s0)
.L7F031AB4:
/* 0665E4 7F031AB4 C6280008 */  lwc1  $f8, 8($s1)
/* 0665E8 7F031AB8 C60A0018 */  lwc1  $f10, 0x18($s0)
/* 0665EC 7F031ABC C6320010 */  lwc1  $f18, 0x10($s1)
/* 0665F0 7F031AC0 46083301 */  sub.s $f12, $f6, $f8
/* 0665F4 7F031AC4 0FC16A8C */  jal   atan2f
/* 0665F8 7F031AC8 46125381 */   sub.s $f14, $f10, $f18
/* 0665FC 7F031ACC 4600A481 */  sub.s $f18, $f20, $f0
/* 066600 7F031AD0 C7B000F4 */  lwc1  $f16, 0xf4($sp)
/* 066604 7F031AD4 C62A0008 */  lwc1  $f10, 8($s1)
/* 066608 7F031AD8 C7A800FC */  lwc1  $f8, 0xfc($sp)
/* 06660C 7F031ADC C6260010 */  lwc1  $f6, 0x10($s1)
/* 066610 7F031AE0 460A8301 */  sub.s $f12, $f16, $f10
/* 066614 7F031AE4 E7B200C4 */  swc1  $f18, 0xc4($sp)
/* 066618 7F031AE8 0FC16A8C */  jal   atan2f
/* 06661C 7F031AEC 46064381 */   sub.s $f14, $f8, $f6
/* 066620 7F031AF0 C7B000C4 */  lwc1  $f16, 0xc4($sp)
/* 066624 7F031AF4 4600A301 */  sub.s $f12, $f20, $f0
/* 066628 7F031AF8 02402025 */  move  $a0, $s2
/* 06662C 7F031AFC 02602825 */  move  $a1, $s3
/* 066630 7F031B00 461C803C */  c.lt.s $f16, $f28
/* 066634 7F031B04 46006086 */  mov.s $f2, $f12
/* 066638 7F031B08 00003025 */  move  $a2, $zero
/* 06663C 7F031B0C 02603825 */  move  $a3, $s3
/* 066640 7F031B10 45020003 */  bc1fl .L7F031B20
/* 066644 7F031B14 4610F03E */   c.le.s $f30, $f16
/* 066648 7F031B18 461A8400 */  add.s $f16, $f16, $f26
/* 06664C 7F031B1C 4610F03E */  c.le.s $f30, $f16
.L7F031B20:
/* 066650 7F031B20 00000000 */  nop   
/* 066654 7F031B24 45020003 */  bc1fl .L7F031B34
/* 066658 7F031B28 461C803C */   c.lt.s $f16, $f28
/* 06665C 7F031B2C 461A8401 */  sub.s $f16, $f16, $f26
/* 066660 7F031B30 461C803C */  c.lt.s $f16, $f28
.L7F031B34:
/* 066664 7F031B34 00000000 */  nop   
/* 066668 7F031B38 45020003 */  bc1fl .L7F031B48
/* 06666C 7F031B3C 461C603C */   c.lt.s $f12, $f28
/* 066670 7F031B40 46008407 */  neg.s $f16, $f16
/* 066674 7F031B44 461C603C */  c.lt.s $f12, $f28
.L7F031B48:
/* 066678 7F031B48 00000000 */  nop   
/* 06667C 7F031B4C 45020003 */  bc1fl .L7F031B5C
/* 066680 7F031B50 4602F03E */   c.le.s $f30, $f2
/* 066684 7F031B54 461A6080 */  add.s $f2, $f12, $f26
/* 066688 7F031B58 4602F03E */  c.le.s $f30, $f2
.L7F031B5C:
/* 06668C 7F031B5C 00000000 */  nop   
/* 066690 7F031B60 45020003 */  bc1fl .L7F031B70
/* 066694 7F031B64 461C103C */   c.lt.s $f2, $f28
/* 066698 7F031B68 461A1081 */  sub.s $f2, $f2, $f26
/* 06669C 7F031B6C 461C103C */  c.lt.s $f2, $f28
.L7F031B70:
/* 0666A0 7F031B70 00000000 */  nop   
/* 0666A4 7F031B74 45020003 */  bc1fl .L7F031B84
/* 0666A8 7F031B78 4610103C */   c.lt.s $f2, $f16
/* 0666AC 7F031B7C 46001087 */  neg.s $f2, $f2
/* 0666B0 7F031B80 4610103C */  c.lt.s $f2, $f16
.L7F031B84:
/* 0666B4 7F031B84 00000000 */  nop   
/* 0666B8 7F031B88 45020061 */  bc1fl .L7F031D10
/* 0666BC 7F031B8C 820F0001 */   lb    $t7, 1($s0)
/* 0666C0 7F031B90 E7B80010 */  swc1  $f24, 0x10($sp)
/* 0666C4 7F031B94 AFA00014 */  sw    $zero, 0x14($sp)
/* 0666C8 7F031B98 AFA00018 */  sw    $zero, 0x18($sp)
/* 0666CC 7F031B9C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0666D0 7F031BA0 E7B60020 */  swc1  $f22, 0x20($sp)
/* 0666D4 7F031BA4 AFB60024 */  sw    $s6, 0x24($sp)
/* 0666D8 7F031BA8 0FC0C4C3 */  jal   sub_GAME_7F03130C
/* 0666DC 7F031BAC AFB70028 */   sw    $s7, 0x28($sp)
/* 0666E0 7F031BB0 50400057 */  beql  $v0, $zero, .L7F031D10
/* 0666E4 7F031BB4 820F0001 */   lb    $t7, 1($s0)
/* 0666E8 7F031BB8 10000061 */  b     .L7F031D40
/* 0666EC 7F031BBC A2000000 */   sb    $zero, ($s0)
.L7F031BC0:
/* 0666F0 7F031BC0 C4322060 */  lwc1  $f18, %lo(D_80052060)($at)
/* 0666F4 7F031BC4 02603825 */  move  $a3, $s3
/* 0666F8 7F031BC8 E7B80010 */  swc1  $f24, 0x10($sp)
/* 0666FC 7F031BCC 4612C582 */  mul.s $f22, $f24, $f18
/* 066700 7F031BD0 AFA00014 */  sw    $zero, 0x14($sp)
/* 066704 7F031BD4 AFA00018 */  sw    $zero, 0x18($sp)
/* 066708 7F031BD8 AFB0001C */  sw    $s0, 0x1c($sp)
/* 06670C 7F031BDC AFB60024 */  sw    $s6, 0x24($sp)
/* 066710 7F031BE0 AFB70028 */  sw    $s7, 0x28($sp)
/* 066714 7F031BE4 0FC0C4C3 */  jal   sub_GAME_7F03130C
/* 066718 7F031BE8 E7B60020 */   swc1  $f22, 0x20($sp)
/* 06671C 7F031BEC 50400004 */  beql  $v0, $zero, .L7F031C00
/* 066720 7F031BF0 C604001C */   lwc1  $f4, 0x1c($s0)
/* 066724 7F031BF4 10000052 */  b     .L7F031D40
/* 066728 7F031BF8 A2000000 */   sb    $zero, ($s0)
/* 06672C 7F031BFC C604001C */  lwc1  $f4, 0x1c($s0)
.L7F031C00:
/* 066730 7F031C00 C6260008 */  lwc1  $f6, 8($s1)
/* 066734 7F031C04 C6080024 */  lwc1  $f8, 0x24($s0)
/* 066738 7F031C08 C62A0010 */  lwc1  $f10, 0x10($s1)
/* 06673C 7F031C0C 46062301 */  sub.s $f12, $f4, $f6
/* 066740 7F031C10 0FC16A8C */  jal   atan2f
/* 066744 7F031C14 460A4381 */   sub.s $f14, $f8, $f10
/* 066748 7F031C18 4600A481 */  sub.s $f18, $f20, $f0
/* 06674C 7F031C1C C7B000F4 */  lwc1  $f16, 0xf4($sp)
/* 066750 7F031C20 C62A0008 */  lwc1  $f10, 8($s1)
/* 066754 7F031C24 C7A800FC */  lwc1  $f8, 0xfc($sp)
/* 066758 7F031C28 C6260010 */  lwc1  $f6, 0x10($s1)
/* 06675C 7F031C2C 460A8301 */  sub.s $f12, $f16, $f10
/* 066760 7F031C30 E7B200B4 */  swc1  $f18, 0xb4($sp)
/* 066764 7F031C34 0FC16A8C */  jal   atan2f
/* 066768 7F031C38 46064381 */   sub.s $f14, $f8, $f6
/* 06676C 7F031C3C C7B000B4 */  lwc1  $f16, 0xb4($sp)
/* 066770 7F031C40 4600A301 */  sub.s $f12, $f20, $f0
/* 066774 7F031C44 02402025 */  move  $a0, $s2
/* 066778 7F031C48 02602825 */  move  $a1, $s3
/* 06677C 7F031C4C 461C803C */  c.lt.s $f16, $f28
/* 066780 7F031C50 46006086 */  mov.s $f2, $f12
/* 066784 7F031C54 02E03025 */  move  $a2, $s7
/* 066788 7F031C58 02603825 */  move  $a3, $s3
/* 06678C 7F031C5C 45020003 */  bc1fl .L7F031C6C
/* 066790 7F031C60 4610F03E */   c.le.s $f30, $f16
/* 066794 7F031C64 461A8400 */  add.s $f16, $f16, $f26
/* 066798 7F031C68 4610F03E */  c.le.s $f30, $f16
.L7F031C6C:
/* 06679C 7F031C6C 00000000 */  nop   
/* 0667A0 7F031C70 45020003 */  bc1fl .L7F031C80
/* 0667A4 7F031C74 461C803C */   c.lt.s $f16, $f28
/* 0667A8 7F031C78 461A8401 */  sub.s $f16, $f16, $f26
/* 0667AC 7F031C7C 461C803C */  c.lt.s $f16, $f28
.L7F031C80:
/* 0667B0 7F031C80 00000000 */  nop   
/* 0667B4 7F031C84 45020003 */  bc1fl .L7F031C94
/* 0667B8 7F031C88 461C603C */   c.lt.s $f12, $f28
/* 0667BC 7F031C8C 46008407 */  neg.s $f16, $f16
/* 0667C0 7F031C90 461C603C */  c.lt.s $f12, $f28
.L7F031C94:
/* 0667C4 7F031C94 00000000 */  nop   
/* 0667C8 7F031C98 45020003 */  bc1fl .L7F031CA8
/* 0667CC 7F031C9C 4602F03E */   c.le.s $f30, $f2
/* 0667D0 7F031CA0 461A6080 */  add.s $f2, $f12, $f26
/* 0667D4 7F031CA4 4602F03E */  c.le.s $f30, $f2
.L7F031CA8:
/* 0667D8 7F031CA8 00000000 */  nop   
/* 0667DC 7F031CAC 45020003 */  bc1fl .L7F031CBC
/* 0667E0 7F031CB0 461C103C */   c.lt.s $f2, $f28
/* 0667E4 7F031CB4 461A1081 */  sub.s $f2, $f2, $f26
/* 0667E8 7F031CB8 461C103C */  c.lt.s $f2, $f28
.L7F031CBC:
/* 0667EC 7F031CBC 00000000 */  nop   
/* 0667F0 7F031CC0 45020003 */  bc1fl .L7F031CD0
/* 0667F4 7F031CC4 4610103C */   c.lt.s $f2, $f16
/* 0667F8 7F031CC8 46001087 */  neg.s $f2, $f2
/* 0667FC 7F031CCC 4610103C */  c.lt.s $f2, $f16
.L7F031CD0:
/* 066800 7F031CD0 00000000 */  nop   
/* 066804 7F031CD4 4502000E */  bc1fl .L7F031D10
/* 066808 7F031CD8 820F0001 */   lb    $t7, 1($s0)
/* 06680C 7F031CDC E7B80010 */  swc1  $f24, 0x10($sp)
/* 066810 7F031CE0 AFA00014 */  sw    $zero, 0x14($sp)
/* 066814 7F031CE4 AFA00018 */  sw    $zero, 0x18($sp)
/* 066818 7F031CE8 AFB0001C */  sw    $s0, 0x1c($sp)
/* 06681C 7F031CEC E7B60020 */  swc1  $f22, 0x20($sp)
/* 066820 7F031CF0 AFB60024 */  sw    $s6, 0x24($sp)
/* 066824 7F031CF4 0FC0C4C3 */  jal   sub_GAME_7F03130C
/* 066828 7F031CF8 AFB70028 */   sw    $s7, 0x28($sp)
/* 06682C 7F031CFC 50400004 */  beql  $v0, $zero, .L7F031D10
/* 066830 7F031D00 820F0001 */   lb    $t7, 1($s0)
/* 066834 7F031D04 1000000E */  b     .L7F031D40
/* 066838 7F031D08 A2000000 */   sb    $zero, ($s0)
/* 06683C 7F031D0C 820F0001 */  lb    $t7, 1($s0)
.L7F031D10:
/* 066840 7F031D10 25F80001 */  addiu $t8, $t7, 1
/* 066844 7F031D14 A2180001 */  sb    $t8, 1($s0)
/* 066848 7F031D18 82190001 */  lb    $t9, 1($s0)
/* 06684C 7F031D1C 2B210006 */  slti  $at, $t9, 6
/* 066850 7F031D20 54200004 */  bnezl $at, .L7F031D34
/* 066854 7F031D24 8FA800F0 */   lw    $t0, 0xf0($sp)
/* 066858 7F031D28 A2000003 */  sb    $zero, 3($s0)
/* 06685C 7F031D2C A2000000 */  sb    $zero, ($s0)
.L7F031D30:
/* 066860 7F031D30 8FA800F0 */  lw    $t0, 0xf0($sp)
.L7F031D34:
/* 066864 7F031D34 25090001 */  addiu $t1, $t0, 1
/* 066868 7F031D38 1537FE3D */  bne   $t1, $s7, .L7F031630
/* 06686C 7F031D3C AFA900F0 */   sw    $t1, 0xf0($sp)
.L7F031D40:
/* 066870 7F031D40 820A0003 */  lb    $t2, 3($s0)
/* 066874 7F031D44 240D5000 */  li    $t5, 20480
/* 066878 7F031D48 55400008 */  bnezl $t2, .L7F031D6C
/* 06687C 7F031D4C 8E0B0028 */   lw    $t3, 0x28($s0)
/* 066880 7F031D50 C60A0004 */  lwc1  $f10, 4($s0)
/* 066884 7F031D54 C6120008 */  lwc1  $f18, 8($s0)
/* 066888 7F031D58 C604000C */  lwc1  $f4, 0xc($s0)
/* 06688C 7F031D5C E60A002C */  swc1  $f10, 0x2c($s0)
/* 066890 7F031D60 E6120030 */  swc1  $f18, 0x30($s0)
/* 066894 7F031D64 E6040034 */  swc1  $f4, 0x34($s0)
/* 066898 7F031D68 8E0B0028 */  lw    $t3, 0x28($s0)
.L7F031D6C:
/* 06689C 7F031D6C 2401000A */  li    $at, 10
/* 0668A0 7F031D70 0161001A */  div   $zero, $t3, $at
/* 0668A4 7F031D74 00006010 */  mfhi  $t4
/* 0668A8 7F031D78 55800072 */  bnezl $t4, .L7F031F44
/* 0668AC 7F031D7C 824E0007 */   lb    $t6, 7($s2)
/* 0668B0 7F031D80 C6060034 */  lwc1  $f6, 0x34($s0)
/* 0668B4 7F031D84 8E240014 */  lw    $a0, 0x14($s1)
/* 0668B8 7F031D88 8E250008 */  lw    $a1, 8($s1)
/* 0668BC 7F031D8C 8E260010 */  lw    $a2, 0x10($s1)
/* 0668C0 7F031D90 8E07002C */  lw    $a3, 0x2c($s0)
/* 0668C4 7F031D94 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0668C8 7F031D98 0FC2C504 */  jal   sub_GAME_7F0B1410
/* 0668CC 7F031D9C E7A60010 */   swc1  $f6, 0x10($sp)
/* 0668D0 7F031DA0 10400042 */  beqz  $v0, .L7F031EAC
/* 0668D4 7F031DA4 00409825 */   move  $s3, $v0
/* 0668D8 7F031DA8 8C430004 */  lw    $v1, 4($v0)
/* 0668DC 7F031DAC 8C6E000C */  lw    $t6, 0xc($v1)
/* 0668E0 7F031DB0 000E7880 */  sll   $t7, $t6, 2
/* 0668E4 7F031DB4 05E2003D */  bltzl $t7, .L7F031EAC
/* 0668E8 7F031DB8 00009825 */   move  $s3, $zero
/* 0668EC 7F031DBC C4480008 */  lwc1  $f8, 8($v0)
/* 0668F0 7F031DC0 C62A0008 */  lwc1  $f10, 8($s1)
/* 0668F4 7F031DC4 C452000C */  lwc1  $f18, 0xc($v0)
/* 0668F8 7F031DC8 C624000C */  lwc1  $f4, 0xc($s1)
/* 0668FC 7F031DCC 460A4001 */  sub.s $f0, $f8, $f10
/* 066900 7F031DD0 C6280010 */  lwc1  $f8, 0x10($s1)
/* 066904 7F031DD4 C4460010 */  lwc1  $f6, 0x10($v0)
/* 066908 7F031DD8 46049081 */  sub.s $f2, $f18, $f4
/* 06690C 7F031DDC 46000282 */  mul.s $f10, $f0, $f0
/* 066910 7F031DE0 3C018005 */  lui   $at, %hi(D_80052064)
/* 066914 7F031DE4 46083301 */  sub.s $f12, $f6, $f8
/* 066918 7F031DE8 46021482 */  mul.s $f18, $f2, $f2
/* 06691C 7F031DEC 02402025 */  move  $a0, $s2
/* 066920 7F031DF0 460C6182 */  mul.s $f6, $f12, $f12
/* 066924 7F031DF4 46125100 */  add.s $f4, $f10, $f18
/* 066928 7F031DF8 C42A2064 */  lwc1  $f10, %lo(D_80052064)($at)
/* 06692C 7F031DFC 46062200 */  add.s $f8, $f4, $f6
/* 066930 7F031E00 460A403C */  c.lt.s $f8, $f10
/* 066934 7F031E04 00000000 */  nop   
/* 066938 7F031E08 45000025 */  bc1f  .L7F031EA0
/* 06693C 7F031E0C 00000000 */   nop   
/* 066940 7F031E10 0FC0A07D */  jal   sub_GAME_7F0281F4
/* 066944 7F031E14 00000000 */   nop   
/* 066948 7F031E18 02202025 */  move  $a0, $s1
/* 06694C 7F031E1C 0FC156DE */  jal   sub_GAME_7F055B78
/* 066950 7F031E20 8E650004 */   lw    $a1, 4($s3)
/* 066954 7F031E24 8E640004 */  lw    $a0, 4($s3)
/* 066958 7F031E28 0FC15262 */  jal   set_door_state
/* 06695C 7F031E2C 02E02825 */   move  $a1, $s7
/* 066960 7F031E30 96580012 */  lhu   $t8, 0x12($s2)
/* 066964 7F031E34 33190010 */  andi  $t9, $t8, 0x10
/* 066968 7F031E38 1720001C */  bnez  $t9, .L7F031EAC
/* 06696C 7F031E3C 00000000 */   nop   
/* 066970 7F031E40 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 066974 7F031E44 8E44001C */   lw    $a0, 0x1c($s2)
/* 066978 7F031E48 3C088007 */  lui   $t0, %hi(ptr_animation_table) 
/* 06697C 7F031E4C 8D089538 */  lw    $t0, %lo(ptr_animation_table)($t0)
/* 066980 7F031E50 3C090001 */  lui   $t1, %hi(0x00008194) # $t1, 1
/* 066984 7F031E54 25298194 */  addiu $t1, %lo(0x00008194) # addiu $t1, $t1, -0x7e6c
/* 066988 7F031E58 01095021 */  addu  $t2, $t0, $t1
/* 06698C 7F031E5C 104A0013 */  beq   $v0, $t2, .L7F031EAC
/* 066990 7F031E60 00000000 */   nop   
/* 066994 7F031E64 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 066998 7F031E68 8E44001C */   lw    $a0, 0x1c($s2)
/* 06699C 7F031E6C 3C0B8007 */  lui   $t3, %hi(ptr_animation_table) 
/* 0669A0 7F031E70 8D6B9538 */  lw    $t3, %lo(ptr_animation_table)($t3)
/* 0669A4 7F031E74 3C0C0000 */  lui   $t4, %hi(0x0000001C) # $t4, 0
/* 0669A8 7F031E78 258C001C */  addiu $t4, %lo(0x0000001C) # addiu $t4, $t4, 0x1c
/* 0669AC 7F031E7C 016C6821 */  addu  $t5, $t3, $t4
/* 0669B0 7F031E80 104D000A */  beq   $v0, $t5, .L7F031EAC
/* 0669B4 7F031E84 02402025 */   move  $a0, $s2
/* 0669B8 7F031E88 0FC08E52 */  jal   chrlvIdleAnimationRelated
/* 0669BC 7F031E8C 3C054180 */   lui   $a1, 0x4180
/* 0669C0 7F031E90 3C0E8005 */  lui   $t6, %hi(g_GlobalTimer) 
/* 0669C4 7F031E94 8DCE837C */  lw    $t6, %lo(g_GlobalTimer)($t6)
/* 0669C8 7F031E98 10000004 */  b     .L7F031EAC
/* 0669CC 7F031E9C AE4E00CC */   sw    $t6, 0xcc($s2)
.L7F031EA0:
/* 0669D0 7F031EA0 10000002 */  b     .L7F031EAC
/* 0669D4 7F031EA4 00009825 */   move  $s3, $zero
/* 0669D8 7F031EA8 00009825 */  move  $s3, $zero
.L7F031EAC:
/* 0669DC 7F031EAC 12600005 */  beqz  $s3, .L7F031EC4
/* 0669E0 7F031EB0 3C110001 */   lui   $s1, %hi(0x00008194) # $s1, 1
/* 0669E4 7F031EB4 964F0012 */  lhu   $t7, 0x12($s2)
/* 0669E8 7F031EB8 31F80010 */  andi  $t8, $t7, 0x10
/* 0669EC 7F031EBC 53000021 */  beql  $t8, $zero, .L7F031F44
/* 0669F0 7F031EC0 824E0007 */   lb    $t6, 7($s2)
.L7F031EC4:
/* 0669F4 7F031EC4 8E44001C */  lw    $a0, 0x1c($s2)
/* 0669F8 7F031EC8 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 0669FC 7F031ECC 26318194 */   addiu $s1, %lo(0x00008194) # addiu $s1, $s1, -0x7e6c
/* 066A00 7F031ED0 3C198007 */  lui   $t9, %hi(ptr_animation_table) 
/* 066A04 7F031ED4 8F399538 */  lw    $t9, %lo(ptr_animation_table)($t9)
/* 066A08 7F031ED8 02394021 */  addu  $t0, $s1, $t9
/* 066A0C 7F031EDC 10480009 */  beq   $v0, $t0, .L7F031F04
/* 066A10 7F031EE0 3C110000 */   lui   $s1, %hi(0x0000001C) # $s1, 0
/* 066A14 7F031EE4 8E44001C */  lw    $a0, 0x1c($s2)
/* 066A18 7F031EE8 0FC1BD6B */  jal   sub_GAME_7F06F5AC
/* 066A1C 7F031EEC 2631001C */   addiu $s1, %lo(0x0000001C) # addiu $s1, $s1, 0x1c
/* 066A20 7F031EF0 3C098007 */  lui   $t1, %hi(ptr_animation_table) 
/* 066A24 7F031EF4 8D299538 */  lw    $t1, %lo(ptr_animation_table)($t1)
/* 066A28 7F031EF8 02295021 */  addu  $t2, $s1, $t1
/* 066A2C 7F031EFC 144A000B */  bne   $v0, $t2, .L7F031F2C
/* 066A30 7F031F00 00000000 */   nop   
.L7F031F04:
/* 066A34 7F031F04 824B0007 */  lb    $t3, 7($s2)
/* 066A38 7F031F08 2401000E */  li    $at, 14
/* 066A3C 7F031F0C 15610005 */  bne   $t3, $at, .L7F031F24
/* 066A40 7F031F10 00000000 */   nop   
/* 066A44 7F031F14 0FC0A3EB */  jal   chrlvWalkingAnimationRelated
/* 066A48 7F031F18 02402025 */   move  $a0, $s2
/* 066A4C 7F031F1C 10000003 */  b     .L7F031F2C
/* 066A50 7F031F20 00000000 */   nop   
.L7F031F24:
/* 066A54 7F031F24 0FC0A368 */  jal   play_hit_soundeffect_and_proper_volume
/* 066A58 7F031F28 02402025 */   move  $a0, $s2
.L7F031F2C:
/* 066A5C 7F031F2C 56600005 */  bnezl $s3, .L7F031F44
/* 066A60 7F031F30 824E0007 */   lb    $t6, 7($s2)
/* 066A64 7F031F34 964C0012 */  lhu   $t4, 0x12($s2)
/* 066A68 7F031F38 318DFFEF */  andi  $t5, $t4, 0xffef
/* 066A6C 7F031F3C A64D0012 */  sh    $t5, 0x12($s2)
/* 066A70 7F031F40 824E0007 */  lb    $t6, 7($s2)
.L7F031F44:
/* 066A74 7F031F44 2401000E */  li    $at, 14
/* 066A78 7F031F48 02402025 */  move  $a0, $s2
/* 066A7C 7F031F4C 15C10008 */  bne   $t6, $at, .L7F031F70
/* 066A80 7F031F50 2605002C */   addiu $a1, $s0, 0x2c
/* 066A84 7F031F54 02402025 */  move  $a0, $s2
/* 066A88 7F031F58 2605002C */  addiu $a1, $s0, 0x2c
/* 066A8C 7F031F5C 00003025 */  move  $a2, $zero
/* 066A90 7F031F60 0FC0BDA4 */  jal   sub_GAME_7F02F690
/* 066A94 7F031F64 2647007C */   addiu $a3, $s2, 0x7c
/* 066A98 7F031F68 10000037 */  b     .L7F032048
/* 066A9C 7F031F6C 8FBF0084 */   lw    $ra, 0x84($sp)
.L7F031F70:
/* 066AA0 7F031F70 92460059 */  lbu   $a2, 0x59($s2)
/* 066AA4 7F031F74 0FC0BDA4 */  jal   sub_GAME_7F02F690
/* 066AA8 7F031F78 264700A0 */   addiu $a3, $s2, 0xa0
/* 066AAC 7F031F7C 92430059 */  lbu   $v1, 0x59($s2)
/* 066AB0 7F031F80 24010002 */  li    $at, 2
/* 066AB4 7F031F84 1461001D */  bne   $v1, $at, .L7F031FFC
/* 066AB8 7F031F88 00000000 */   nop   
/* 066ABC 7F031F8C C65200A0 */  lwc1  $f18, 0xa0($s2)
/* 066AC0 7F031F90 3C053E80 */  lui   $a1, 0x3e80
/* 066AC4 7F031F94 4612E032 */  c.eq.s $f28, $f18
/* 066AC8 7F031F98 00000000 */  nop   
/* 066ACC 7F031F9C 45030007 */  bc1tl .L7F031FBC
/* 066AD0 7F031FA0 8E4F0014 */   lw    $t7, 0x14($s2)
/* 066AD4 7F031FA4 4406E000 */  mfc1  $a2, $f28
/* 066AD8 7F031FA8 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 066ADC 7F031FAC 8E44001C */   lw    $a0, 0x1c($s2)
/* 066AE0 7F031FB0 10000025 */  b     .L7F032048
/* 066AE4 7F031FB4 8FBF0084 */   lw    $ra, 0x84($sp)
/* 066AE8 7F031FB8 8E4F0014 */  lw    $t7, 0x14($s2)
.L7F031FBC:
/* 066AEC 7F031FBC 3C053F00 */  lui   $a1, 0x3f00
/* 066AF0 7F031FC0 000FC300 */  sll   $t8, $t7, 0xc
/* 066AF4 7F031FC4 07030009 */  bgezl $t8, .L7F031FEC
/* 066AF8 7F031FC8 4406E000 */   mfc1  $a2, $f28
/* 066AFC 7F031FCC 3C053F26 */  lui   $a1, (0x3F266666 >> 16) # lui $a1, 0x3f26
/* 066B00 7F031FD0 4406E000 */  mfc1  $a2, $f28
/* 066B04 7F031FD4 34A56666 */  ori   $a1, (0x3F266666 & 0xFFFF) # ori $a1, $a1, 0x6666
/* 066B08 7F031FD8 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 066B0C 7F031FDC 8E44001C */   lw    $a0, 0x1c($s2)
/* 066B10 7F031FE0 10000019 */  b     .L7F032048
/* 066B14 7F031FE4 8FBF0084 */   lw    $ra, 0x84($sp)
/* 066B18 7F031FE8 4406E000 */  mfc1  $a2, $f28
.L7F031FEC:
/* 066B1C 7F031FEC 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 066B20 7F031FF0 8E44001C */   lw    $a0, 0x1c($s2)
/* 066B24 7F031FF4 10000014 */  b     .L7F032048
/* 066B28 7F031FF8 8FBF0084 */   lw    $ra, 0x84($sp)
.L7F031FFC:
/* 066B2C 7F031FFC 56E30012 */  bnel  $s7, $v1, .L7F032048
/* 066B30 7F032000 8FBF0084 */   lw    $ra, 0x84($sp)
/* 066B34 7F032004 C64400A0 */  lwc1  $f4, 0xa0($s2)
/* 066B38 7F032008 3C053F00 */  lui   $a1, 0x3f00
/* 066B3C 7F03200C 4604E032 */  c.eq.s $f28, $f4
/* 066B40 7F032010 00000000 */  nop   
/* 066B44 7F032014 45030009 */  bc1tl .L7F03203C
/* 066B48 7F032018 4406E000 */   mfc1  $a2, $f28
/* 066B4C 7F03201C 3C053ECC */  lui   $a1, (0x3ECCCCCD >> 16) # lui $a1, 0x3ecc
/* 066B50 7F032020 4406E000 */  mfc1  $a2, $f28
/* 066B54 7F032024 34A5CCCD */  ori   $a1, (0x3ECCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
/* 066B58 7F032028 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 066B5C 7F03202C 8E44001C */   lw    $a0, 0x1c($s2)
/* 066B60 7F032030 10000005 */  b     .L7F032048
/* 066B64 7F032034 8FBF0084 */   lw    $ra, 0x84($sp)
/* 066B68 7F032038 4406E000 */  mfc1  $a2, $f28
.L7F03203C:
/* 066B6C 7F03203C 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 066B70 7F032040 8E44001C */   lw    $a0, 0x1c($s2)
/* 066B74 7F032044 8FBF0084 */  lw    $ra, 0x84($sp)
.L7F032048:
/* 066B78 7F032048 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 066B7C 7F03204C D7B60038 */  ldc1  $f22, 0x38($sp)
/* 066B80 7F032050 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 066B84 7F032054 D7BA0048 */  ldc1  $f26, 0x48($sp)
/* 066B88 7F032058 D7BC0050 */  ldc1  $f28, 0x50($sp)
/* 066B8C 7F03205C D7BE0058 */  ldc1  $f30, 0x58($sp)
/* 066B90 7F032060 8FB00064 */  lw    $s0, 0x64($sp)
/* 066B94 7F032064 8FB10068 */  lw    $s1, 0x68($sp)
/* 066B98 7F032068 8FB2006C */  lw    $s2, 0x6c($sp)
/* 066B9C 7F03206C 8FB30070 */  lw    $s3, 0x70($sp)
/* 066BA0 7F032070 8FB40074 */  lw    $s4, 0x74($sp)
/* 066BA4 7F032074 8FB50078 */  lw    $s5, 0x78($sp)
/* 066BA8 7F032078 8FB6007C */  lw    $s6, 0x7c($sp)
/* 066BAC 7F03207C 8FB70080 */  lw    $s7, 0x80($sp)
/* 066BB0 7F032080 03E00008 */  jr    $ra
/* 066BB4 7F032084 27BD0110 */   addiu $sp, $sp, 0x110
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F032088(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80052068
.word 0x3f99999a /*1.2*/
glabel D_8005206C
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F032088
/* 066BB8 7F032088 27BDFF78 */  addiu $sp, $sp, -0x88
/* 066BBC 7F03208C AFBF0024 */  sw    $ra, 0x24($sp)
/* 066BC0 7F032090 AFB00020 */  sw    $s0, 0x20($sp)
/* 066BC4 7F032094 8C8E0018 */  lw    $t6, 0x18($a0)
/* 066BC8 7F032098 AFA00074 */  sw    $zero, 0x74($sp)
/* 066BCC 7F03209C 3C198005 */  lui   $t9, %hi(g_GlobalTimer) 
/* 066BD0 7F0320A0 AFAE0078 */  sw    $t6, 0x78($sp)
/* 066BD4 7F0320A4 8C8F0084 */  lw    $t7, 0x84($a0)
/* 066BD8 7F0320A8 3C098005 */  lui   $t1, %hi(g_GlobalTimer) 
/* 066BDC 7F0320AC 8C8800CC */  lw    $t0, 0xcc($a0)
/* 066BE0 7F0320B0 25F80001 */  addiu $t8, $t7, 1
/* 066BE4 7F0320B4 AC980084 */  sw    $t8, 0x84($a0)
/* 066BE8 7F0320B8 8F39837C */  lw    $t9, %lo(g_GlobalTimer)($t9)
/* 066BEC 7F0320BC 00808025 */  move  $s0, $a0
/* 066BF0 7F0320C0 2605002C */  addiu $a1, $s0, 0x2c
/* 066BF4 7F0320C4 AC9900C8 */  sw    $t9, 0xc8($a0)
/* 066BF8 7F0320C8 8D29837C */  lw    $t1, %lo(g_GlobalTimer)($t1)
/* 066BFC 7F0320CC 252AFFC4 */  addiu $t2, $t1, -0x3c
/* 066C00 7F0320D0 010A082A */  slt   $at, $t0, $t2
/* 066C04 7F0320D4 10200004 */  beqz  $at, .L7F0320E8
/* 066C08 7F0320D8 00000000 */   nop   
/* 066C0C 7F0320DC 8E060038 */  lw    $a2, 0x38($s0)
/* 066C10 7F0320E0 0FC0A377 */  jal   plot_course_for_actor
/* 066C14 7F0320E4 92070059 */   lbu   $a3, 0x59($s0)
.L7F0320E8:
/* 066C18 7F0320E8 0FC0A07F */  jal   chrlvPlotCourseRelated
/* 066C1C 7F0320EC 02002025 */   move  $a0, $s0
/* 066C20 7F0320F0 820B005C */  lb    $t3, 0x5c($s0)
/* 066C24 7F0320F4 24010006 */  li    $at, 6
/* 066C28 7F0320F8 3C0C8005 */  lui   $t4, %hi(g_GlobalTimer) 
/* 066C2C 7F0320FC 11610015 */  beq   $t3, $at, .L7F032154
/* 066C30 7F032100 00000000 */   nop   
/* 066C34 7F032104 8E0D009C */  lw    $t5, 0x9c($s0)
/* 066C38 7F032108 8D8C837C */  lw    $t4, %lo(g_GlobalTimer)($t4)
/* 066C3C 7F03210C 02002025 */  move  $a0, $s0
/* 066C40 7F032110 25AE00B4 */  addiu $t6, $t5, 0xb4
/* 066C44 7F032114 01CC082A */  slt   $at, $t6, $t4
/* 066C48 7F032118 1020000E */  beqz  $at, .L7F032154
/* 066C4C 7F03211C 27A50068 */   addiu $a1, $sp, 0x68
/* 066C50 7F032120 0FC09FC8 */  jal   chrlvActGoposRelated
/* 066C54 7F032124 27A60064 */   addiu $a2, $sp, 0x64
/* 066C58 7F032128 02002025 */  move  $a0, $s0
/* 066C5C 7F03212C 27A50068 */  addiu $a1, $sp, 0x68
/* 066C60 7F032130 0FC09F6C */  jal   chrlvStanRoomRelated
/* 066C64 7F032134 8FA60064 */   lw    $a2, 0x64($sp)
/* 066C68 7F032138 10400006 */  beqz  $v0, .L7F032154
/* 066C6C 7F03213C 240F0001 */   li    $t7, 1
/* 066C70 7F032140 AFAF0074 */  sw    $t7, 0x74($sp)
/* 066C74 7F032144 02002025 */  move  $a0, $s0
/* 066C78 7F032148 2605005C */  addiu $a1, $s0, 0x5c
/* 066C7C 7F03214C 0FC09FA4 */  jal   chrlvSetGoposSegDistTotal
/* 066C80 7F032150 27A60068 */   addiu $a2, $sp, 0x68
.L7F032154:
/* 066C84 7F032154 3C188003 */  lui   $t8, %hi(setting_007_5) 
/* 066C88 7F032158 8F18CE50 */  lw    $t8, %lo(setting_007_5)($t8)
/* 066C8C 7F03215C 2B01000A */  slti  $at, $t8, 0xa
/* 066C90 7F032160 54200006 */  bnezl $at, .L7F03217C
/* 066C94 7F032164 8219005C */   lb    $t9, 0x5c($s0)
/* 066C98 7F032168 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 066C9C 7F03216C 02002025 */   move  $a0, $s0
/* 066CA0 7F032170 100000F1 */  b     .L7F032538
/* 066CA4 7F032174 8FBF0024 */   lw    $ra, 0x24($sp)
/* 066CA8 7F032178 8219005C */  lb    $t9, 0x5c($s0)
.L7F03217C:
/* 066CAC 7F03217C 24010006 */  li    $at, 6
/* 066CB0 7F032180 02002025 */  move  $a0, $s0
/* 066CB4 7F032184 17210024 */  bne   $t9, $at, .L7F032218
/* 066CB8 7F032188 27A50058 */   addiu $a1, $sp, 0x58
/* 066CBC 7F03218C 0FC09FC8 */  jal   chrlvActGoposRelated
/* 066CC0 7F032190 27A60054 */   addiu $a2, $sp, 0x54
/* 066CC4 7F032194 8FA90074 */  lw    $t1, 0x74($sp)
/* 066CC8 7F032198 8FA80078 */  lw    $t0, 0x78($sp)
/* 066CCC 7F03219C 55200012 */  bnezl $t1, .L7F0321E8
/* 066CD0 7F0321A0 260C005C */   addiu $t4, $s0, 0x5c
/* 066CD4 7F0321A4 910A0001 */  lbu   $t2, 1($t0)
/* 066CD8 7F0321A8 02002025 */  move  $a0, $s0
/* 066CDC 7F0321AC 27A50058 */  addiu $a1, $sp, 0x58
/* 066CE0 7F0321B0 314B0002 */  andi  $t3, $t2, 2
/* 066CE4 7F0321B4 15600005 */  bnez  $t3, .L7F0321CC
/* 066CE8 7F0321B8 00000000 */   nop   
/* 066CEC 7F0321BC 0FC09F6C */  jal   chrlvStanRoomRelated
/* 066CF0 7F0321C0 8FA60054 */   lw    $a2, 0x54($sp)
/* 066CF4 7F0321C4 54400008 */  bnezl $v0, .L7F0321E8
/* 066CF8 7F0321C8 260C005C */   addiu $t4, $s0, 0x5c
.L7F0321CC:
/* 066CFC 7F0321CC 0FC0A0A3 */  jal   chrlvActGoposSetTargetPosRelated
/* 066D00 7F0321D0 02002025 */   move  $a0, $s0
/* 066D04 7F0321D4 3C0D8005 */  lui   $t5, %hi(g_GlobalTimer) 
/* 066D08 7F0321D8 8DAD837C */  lw    $t5, %lo(g_GlobalTimer)($t5)
/* 066D0C 7F0321DC 100000D5 */  b     .L7F032534
/* 066D10 7F0321E0 AE0D009C */   sw    $t5, 0x9c($s0)
/* 066D14 7F0321E4 260C005C */  addiu $t4, $s0, 0x5c
.L7F0321E8:
/* 066D18 7F0321E8 AFAC0034 */  sw    $t4, 0x34($sp)
/* 066D1C 7F0321EC 0FC09FEA */  jal   chrlvModelScaleAnimationRelated
/* 066D20 7F0321F0 02002025 */   move  $a0, $s0
/* 066D24 7F0321F4 8FAE0054 */  lw    $t6, 0x54($sp)
/* 066D28 7F0321F8 44060000 */  mfc1  $a2, $f0
/* 066D2C 7F0321FC 02002025 */  move  $a0, $s0
/* 066D30 7F032200 8FA50034 */  lw    $a1, 0x34($sp)
/* 066D34 7F032204 27A70058 */  addiu $a3, $sp, 0x58
/* 066D38 7F032208 0FC0A180 */  jal   sub_GAME_7F028600
/* 066D3C 7F03220C AFAE0010 */   sw    $t6, 0x10($sp)
/* 066D40 7F032210 100000C9 */  b     .L7F032538
/* 066D44 7F032214 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F032218:
/* 066D48 7F032218 920F0058 */  lbu   $t7, 0x58($s0)
/* 066D4C 7F03221C 8FA50078 */  lw    $a1, 0x78($sp)
/* 066D50 7F032220 00001825 */  move  $v1, $zero
/* 066D54 7F032224 000FC080 */  sll   $t8, $t7, 2
/* 066D58 7F032228 0218C821 */  addu  $t9, $s0, $t8
/* 066D5C 7F03222C 8F220040 */  lw    $v0, 0x40($t9)
/* 066D60 7F032230 260400BC */  addiu $a0, $s0, 0xbc
/* 066D64 7F032234 2606002C */  addiu $a2, $s0, 0x2c
/* 066D68 7F032238 10400015 */  beqz  $v0, .L7F032290
/* 066D6C 7F03223C 24A50008 */   addiu $a1, $a1, 8
/* 066D70 7F032240 8C490000 */  lw    $t1, ($v0)
/* 066D74 7F032244 8FA50078 */  lw    $a1, 0x78($sp)
/* 066D78 7F032248 3C0A8007 */  lui   $t2, %hi(ptr_0xxxpresets) 
/* 066D7C 7F03224C 00094080 */  sll   $t0, $t1, 2
/* 066D80 7F032250 01094023 */  subu  $t0, $t0, $t1
/* 066D84 7F032254 00084080 */  sll   $t0, $t0, 2
/* 066D88 7F032258 8D4A5D18 */  lw    $t2, %lo(ptr_0xxxpresets)($t2)
/* 066D8C 7F03225C 01094023 */  subu  $t0, $t0, $t1
/* 066D90 7F032260 00084080 */  sll   $t0, $t0, 2
/* 066D94 7F032264 24A50008 */  addiu $a1, $a1, 8
/* 066D98 7F032268 AFA5002C */  sw    $a1, 0x2c($sp)
/* 066D9C 7F03226C AFA0004C */  sw    $zero, 0x4c($sp)
/* 066DA0 7F032270 260400BC */  addiu $a0, $s0, 0xbc
/* 066DA4 7F032274 3C0741F0 */  lui   $a3, 0x41f0
/* 066DA8 7F032278 0FC0BF54 */  jal   sub_GAME_7F02FD50
/* 066DAC 7F03227C 010A3021 */   addu  $a2, $t0, $t2
/* 066DB0 7F032280 1040000D */  beqz  $v0, .L7F0322B8
/* 066DB4 7F032284 8FA3004C */   lw    $v1, 0x4c($sp)
/* 066DB8 7F032288 1000000B */  b     .L7F0322B8
/* 066DBC 7F03228C 24030001 */   li    $v1, 1
.L7F032290:
/* 066DC0 7F032290 3C0741F0 */  lui   $a3, 0x41f0
/* 066DC4 7F032294 AFA3004C */  sw    $v1, 0x4c($sp)
/* 066DC8 7F032298 0FC0BF54 */  jal   sub_GAME_7F02FD50
/* 066DCC 7F03229C AFA5002C */   sw    $a1, 0x2c($sp)
/* 066DD0 7F0322A0 10400005 */  beqz  $v0, .L7F0322B8
/* 066DD4 7F0322A4 8FA3004C */   lw    $v1, 0x4c($sp)
/* 066DD8 7F0322A8 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 066DDC 7F0322AC 02002025 */   move  $a0, $s0
/* 066DE0 7F0322B0 100000A1 */  b     .L7F032538
/* 066DE4 7F0322B4 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F0322B8:
/* 066DE8 7F0322B8 260B005C */  addiu $t3, $s0, 0x5c
/* 066DEC 7F0322BC 10600003 */  beqz  $v1, .L7F0322CC
/* 066DF0 7F0322C0 AFAB0034 */   sw    $t3, 0x34($sp)
/* 066DF4 7F0322C4 0FC0A0B8 */  jal   chrlvActGoposIncCurIndex
/* 066DF8 7F0322C8 02002025 */   move  $a0, $s0
.L7F0322CC:
/* 066DFC 7F0322CC 8E0D0084 */  lw    $t5, 0x84($s0)
/* 066E00 7F0322D0 2401000A */  li    $at, 10
/* 066E04 7F0322D4 01A1001A */  div   $zero, $t5, $at
/* 066E08 7F0322D8 00006010 */  mfhi  $t4
/* 066E0C 7F0322DC 24010005 */  li    $at, 5
/* 066E10 7F0322E0 5581003F */  bnel  $t4, $at, .L7F0323E0
/* 066E14 7F0322E4 8E190084 */   lw    $t9, 0x84($s0)
/* 066E18 7F0322E8 92030058 */  lbu   $v1, 0x58($s0)
/* 066E1C 7F0322EC 00037080 */  sll   $t6, $v1, 2
/* 066E20 7F0322F0 020E7821 */  addu  $t7, $s0, $t6
/* 066E24 7F0322F4 8DE20040 */  lw    $v0, 0x40($t7)
/* 066E28 7F0322F8 0003C080 */  sll   $t8, $v1, 2
/* 066E2C 7F0322FC 02182021 */  addu  $a0, $s0, $t8
/* 066E30 7F032300 50400037 */  beql  $v0, $zero, .L7F0323E0
/* 066E34 7F032304 8E190084 */   lw    $t9, 0x84($s0)
/* 066E38 7F032308 8C820044 */  lw    $v0, 0x44($a0)
/* 066E3C 7F03230C 240E0010 */  li    $t6, 16
/* 066E40 7F032310 50400033 */  beql  $v0, $zero, .L7F0323E0
/* 066E44 7F032314 8E190084 */   lw    $t9, 0x84($s0)
/* 066E48 7F032318 8C820048 */  lw    $v0, 0x48($a0)
/* 066E4C 7F03231C 260B002C */  addiu $t3, $s0, 0x2c
/* 066E50 7F032320 02002025 */  move  $a0, $s0
/* 066E54 7F032324 5040000F */  beql  $v0, $zero, .L7F032364
/* 066E58 7F032328 AFAB0080 */   sw    $t3, 0x80($sp)
/* 066E5C 7F03232C 8C590000 */  lw    $t9, ($v0)
/* 066E60 7F032330 3C088007 */  lui   $t0, %hi(ptr_0xxxpresets) 
/* 066E64 7F032334 8D085D18 */  lw    $t0, %lo(ptr_0xxxpresets)($t0)
/* 066E68 7F032338 00194880 */  sll   $t1, $t9, 2
/* 066E6C 7F03233C 01394823 */  subu  $t1, $t1, $t9
/* 066E70 7F032340 00094880 */  sll   $t1, $t1, 2
/* 066E74 7F032344 01394823 */  subu  $t1, $t1, $t9
/* 066E78 7F032348 00094880 */  sll   $t1, $t1, 2
/* 066E7C 7F03234C 01281821 */  addu  $v1, $t1, $t0
/* 066E80 7F032350 AFA30080 */  sw    $v1, 0x80($sp)
/* 066E84 7F032354 8C6A0028 */  lw    $t2, 0x28($v1)
/* 066E88 7F032358 10000004 */  b     .L7F03236C
/* 066E8C 7F03235C AFAA007C */   sw    $t2, 0x7c($sp)
/* 066E90 7F032360 AFAB0080 */  sw    $t3, 0x80($sp)
.L7F032364:
/* 066E94 7F032364 8E060038 */  lw    $a2, 0x38($s0)
/* 066E98 7F032368 AFA6007C */  sw    $a2, 0x7c($sp)
.L7F03236C:
/* 066E9C 7F03236C 8FAD0078 */  lw    $t5, 0x78($sp)
/* 066EA0 7F032370 8FAC007C */  lw    $t4, 0x7c($sp)
/* 066EA4 7F032374 8FA5002C */  lw    $a1, 0x2c($sp)
/* 066EA8 7F032378 8DA60014 */  lw    $a2, 0x14($t5)
/* 066EAC 7F03237C AFAE0014 */  sw    $t6, 0x14($sp)
/* 066EB0 7F032380 8FA70080 */  lw    $a3, 0x80($sp)
/* 066EB4 7F032384 0FC0C04A */  jal   sub_GAME_7F030128
/* 066EB8 7F032388 AFAC0010 */   sw    $t4, 0x10($sp)
/* 066EBC 7F03238C 10400013 */  beqz  $v0, .L7F0323DC
/* 066EC0 7F032390 3C018005 */   lui   $at, %hi(D_80052068)
/* 066EC4 7F032394 C6040024 */  lwc1  $f4, 0x24($s0)
/* 066EC8 7F032398 C4262068 */  lwc1  $f6, %lo(D_80052068)($at)
/* 066ECC 7F03239C 8FAF0078 */  lw    $t7, 0x78($sp)
/* 066ED0 7F0323A0 24180010 */  li    $t8, 16
/* 066ED4 7F0323A4 46062202 */  mul.s $f8, $f4, $f6
/* 066ED8 7F0323A8 8DE60014 */  lw    $a2, 0x14($t7)
/* 066EDC 7F0323AC AFB80014 */  sw    $t8, 0x14($sp)
/* 066EE0 7F0323B0 02002025 */  move  $a0, $s0
/* 066EE4 7F0323B4 8FA5002C */  lw    $a1, 0x2c($sp)
/* 066EE8 7F0323B8 8FA70080 */  lw    $a3, 0x80($sp)
/* 066EEC 7F0323BC 0FC0C07F */  jal   sub_GAME_7F0301FC
/* 066EF0 7F0323C0 E7A80010 */   swc1  $f8, 0x10($sp)
/* 066EF4 7F0323C4 50400006 */  beql  $v0, $zero, .L7F0323E0
/* 066EF8 7F0323C8 8E190084 */   lw    $t9, 0x84($s0)
/* 066EFC 7F0323CC 0FC0A0B8 */  jal   chrlvActGoposIncCurIndex
/* 066F00 7F0323D0 02002025 */   move  $a0, $s0
/* 066F04 7F0323D4 0FC0A0B8 */  jal   chrlvActGoposIncCurIndex
/* 066F08 7F0323D8 02002025 */   move  $a0, $s0
.L7F0323DC:
/* 066F0C 7F0323DC 8E190084 */  lw    $t9, 0x84($s0)
.L7F0323E0:
/* 066F10 7F0323E0 2401000A */  li    $at, 10
/* 066F14 7F0323E4 0321001A */  div   $zero, $t9, $at
/* 066F18 7F0323E8 00004810 */  mfhi  $t1
/* 066F1C 7F0323EC 55200039 */  bnezl $t1, .L7F0324D4
/* 066F20 7F0323F0 920C0058 */   lbu   $t4, 0x58($s0)
/* 066F24 7F0323F4 92030058 */  lbu   $v1, 0x58($s0)
/* 066F28 7F0323F8 02002025 */  move  $a0, $s0
/* 066F2C 7F0323FC 00034080 */  sll   $t0, $v1, 2
/* 066F30 7F032400 02085021 */  addu  $t2, $s0, $t0
/* 066F34 7F032404 8D420040 */  lw    $v0, 0x40($t2)
/* 066F38 7F032408 00035880 */  sll   $t3, $v1, 2
/* 066F3C 7F03240C 020B6821 */  addu  $t5, $s0, $t3
/* 066F40 7F032410 1040002F */  beqz  $v0, .L7F0324D0
/* 066F44 7F032414 240A0010 */   li    $t2, 16
/* 066F48 7F032418 8DA20044 */  lw    $v0, 0x44($t5)
/* 066F4C 7F03241C 2619002C */  addiu $t9, $s0, 0x2c
/* 066F50 7F032420 5040000F */  beql  $v0, $zero, .L7F032460
/* 066F54 7F032424 AFB90080 */   sw    $t9, 0x80($sp)
/* 066F58 7F032428 8C4C0000 */  lw    $t4, ($v0)
/* 066F5C 7F03242C 3C0F8007 */  lui   $t7, %hi(ptr_0xxxpresets) 
/* 066F60 7F032430 8DEF5D18 */  lw    $t7, %lo(ptr_0xxxpresets)($t7)
/* 066F64 7F032434 000C7080 */  sll   $t6, $t4, 2
/* 066F68 7F032438 01CC7023 */  subu  $t6, $t6, $t4
/* 066F6C 7F03243C 000E7080 */  sll   $t6, $t6, 2
/* 066F70 7F032440 01CC7023 */  subu  $t6, $t6, $t4
/* 066F74 7F032444 000E7080 */  sll   $t6, $t6, 2
/* 066F78 7F032448 01CF1821 */  addu  $v1, $t6, $t7
/* 066F7C 7F03244C AFA30080 */  sw    $v1, 0x80($sp)
/* 066F80 7F032450 8C780028 */  lw    $t8, 0x28($v1)
/* 066F84 7F032454 10000004 */  b     .L7F032468
/* 066F88 7F032458 AFB8007C */   sw    $t8, 0x7c($sp)
/* 066F8C 7F03245C AFB90080 */  sw    $t9, 0x80($sp)
.L7F032460:
/* 066F90 7F032460 8E060038 */  lw    $a2, 0x38($s0)
/* 066F94 7F032464 AFA6007C */  sw    $a2, 0x7c($sp)
.L7F032468:
/* 066F98 7F032468 8FA90078 */  lw    $t1, 0x78($sp)
/* 066F9C 7F03246C 8FA8007C */  lw    $t0, 0x7c($sp)
/* 066FA0 7F032470 8FA5002C */  lw    $a1, 0x2c($sp)
/* 066FA4 7F032474 8D260014 */  lw    $a2, 0x14($t1)
/* 066FA8 7F032478 AFAA0014 */  sw    $t2, 0x14($sp)
/* 066FAC 7F03247C 8FA70080 */  lw    $a3, 0x80($sp)
/* 066FB0 7F032480 0FC0C04A */  jal   sub_GAME_7F030128
/* 066FB4 7F032484 AFA80010 */   sw    $t0, 0x10($sp)
/* 066FB8 7F032488 10400011 */  beqz  $v0, .L7F0324D0
/* 066FBC 7F03248C 3C018005 */   lui   $at, %hi(D_8005206C)
/* 066FC0 7F032490 C60A0024 */  lwc1  $f10, 0x24($s0)
/* 066FC4 7F032494 C430206C */  lwc1  $f16, %lo(D_8005206C)($at)
/* 066FC8 7F032498 8FAB0078 */  lw    $t3, 0x78($sp)
/* 066FCC 7F03249C 240D0010 */  li    $t5, 16
/* 066FD0 7F0324A0 46105482 */  mul.s $f18, $f10, $f16
/* 066FD4 7F0324A4 8D660014 */  lw    $a2, 0x14($t3)
/* 066FD8 7F0324A8 AFAD0014 */  sw    $t5, 0x14($sp)
/* 066FDC 7F0324AC 02002025 */  move  $a0, $s0
/* 066FE0 7F0324B0 8FA5002C */  lw    $a1, 0x2c($sp)
/* 066FE4 7F0324B4 8FA70080 */  lw    $a3, 0x80($sp)
/* 066FE8 7F0324B8 0FC0C07F */  jal   sub_GAME_7F0301FC
/* 066FEC 7F0324BC E7B20010 */   swc1  $f18, 0x10($sp)
/* 066FF0 7F0324C0 50400004 */  beql  $v0, $zero, .L7F0324D4
/* 066FF4 7F0324C4 920C0058 */   lbu   $t4, 0x58($s0)
/* 066FF8 7F0324C8 0FC0A0B8 */  jal   chrlvActGoposIncCurIndex
/* 066FFC 7F0324CC 02002025 */   move  $a0, $s0
.L7F0324D0:
/* 067000 7F0324D0 920C0058 */  lbu   $t4, 0x58($s0)
.L7F0324D4:
/* 067004 7F0324D4 2608002C */  addiu $t0, $s0, 0x2c
/* 067008 7F0324D8 02002025 */  move  $a0, $s0
/* 06700C 7F0324DC 000C7080 */  sll   $t6, $t4, 2
/* 067010 7F0324E0 020E7821 */  addu  $t7, $s0, $t6
/* 067014 7F0324E4 8DE20040 */  lw    $v0, 0x40($t7)
/* 067018 7F0324E8 5040000E */  beql  $v0, $zero, .L7F032524
/* 06701C 7F0324EC AFA80080 */   sw    $t0, 0x80($sp)
/* 067020 7F0324F0 8C580000 */  lw    $t8, ($v0)
/* 067024 7F0324F4 3C098007 */  lui   $t1, %hi(ptr_0xxxpresets) 
/* 067028 7F0324F8 8D295D18 */  lw    $t1, %lo(ptr_0xxxpresets)($t1)
/* 06702C 7F0324FC 0018C880 */  sll   $t9, $t8, 2
/* 067030 7F032500 0338C823 */  subu  $t9, $t9, $t8
/* 067034 7F032504 0019C880 */  sll   $t9, $t9, 2
/* 067038 7F032508 0338C823 */  subu  $t9, $t9, $t8
/* 06703C 7F03250C 0019C880 */  sll   $t9, $t9, 2
/* 067040 7F032510 03291821 */  addu  $v1, $t9, $t1
/* 067044 7F032514 AFA30080 */  sw    $v1, 0x80($sp)
/* 067048 7F032518 10000003 */  b     .L7F032528
/* 06704C 7F03251C 8C660028 */   lw    $a2, 0x28($v1)
/* 067050 7F032520 AFA80080 */  sw    $t0, 0x80($sp)
.L7F032524:
/* 067054 7F032524 8E060038 */  lw    $a2, 0x38($s0)
.L7F032528:
/* 067058 7F032528 8FA50080 */  lw    $a1, 0x80($sp)
/* 06705C 7F03252C 0FC0C569 */  jal   sub_GAME_7F0315A4
/* 067060 7F032530 8FA70034 */   lw    $a3, 0x34($sp)
.L7F032534:
/* 067064 7F032534 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F032538:
/* 067068 7F032538 8FB00020 */  lw    $s0, 0x20($sp)
/* 06706C 7F03253C 27BD0088 */  addiu $sp, $sp, 0x88
/* 067070 7F032540 03E00008 */  jr    $ra
/* 067074 7F032544 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F032548(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F032548
/* 067078 7F032548 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 06707C 7F03254C AFBF0024 */  sw    $ra, 0x24($sp)
/* 067080 7F032550 AFB10020 */  sw    $s1, 0x20($sp)
/* 067084 7F032554 AFB0001C */  sw    $s0, 0x1c($sp)
/* 067088 7F032558 8C8E0018 */  lw    $t6, 0x18($a0)
/* 06708C 7F03255C 00808025 */  move  $s0, $a0
/* 067090 7F032560 0FC0A11D */  jal   sub_GAME_7F028474
/* 067094 7F032564 AFAE003C */   sw    $t6, 0x3c($sp)
/* 067098 7F032568 AFA00034 */  sw    $zero, 0x34($sp)
/* 06709C 7F03256C 8E0F0060 */  lw    $t7, 0x60($s0)
/* 0670A0 7F032570 82080038 */  lb    $t0, 0x38($s0)
/* 0670A4 7F032574 3C198005 */  lui   $t9, %hi(g_GlobalTimer) 
/* 0670A8 7F032578 25F80001 */  addiu $t8, $t7, 1
/* 0670AC 7F03257C AE180060 */  sw    $t8, 0x60($s0)
/* 0670B0 7F032580 8F39837C */  lw    $t9, %lo(g_GlobalTimer)($t9)
/* 0670B4 7F032584 24010006 */  li    $at, 6
/* 0670B8 7F032588 00408825 */  move  $s1, $v0
/* 0670BC 7F03258C 11010012 */  beq   $t0, $at, .L7F0325D8
/* 0670C0 7F032590 AE1900C8 */   sw    $t9, 0xc8($s0)
/* 0670C4 7F032594 8E0A0078 */  lw    $t2, 0x78($s0)
/* 0670C8 7F032598 3C098005 */  lui   $t1, %hi(g_GlobalTimer) 
/* 0670CC 7F03259C 8D29837C */  lw    $t1, %lo(g_GlobalTimer)($t1)
/* 0670D0 7F0325A0 254B00B4 */  addiu $t3, $t2, 0xb4
/* 0670D4 7F0325A4 02002025 */  move  $a0, $s0
/* 0670D8 7F0325A8 0169082A */  slt   $at, $t3, $t1
/* 0670DC 7F0325AC 5020000B */  beql  $at, $zero, .L7F0325DC
/* 0670E0 7F0325B0 820D0038 */   lb    $t5, 0x38($s0)
/* 0670E4 7F0325B4 0FC09F9C */  jal   chrlvStanRoomRelatedPad
/* 0670E8 7F0325B8 00402825 */   move  $a1, $v0
/* 0670EC 7F0325BC 10400006 */  beqz  $v0, .L7F0325D8
/* 0670F0 7F0325C0 240C0001 */   li    $t4, 1
/* 0670F4 7F0325C4 AFAC0034 */  sw    $t4, 0x34($sp)
/* 0670F8 7F0325C8 02002025 */  move  $a0, $s0
/* 0670FC 7F0325CC 26050038 */  addiu $a1, $s0, 0x38
/* 067100 7F0325D0 0FC09FA4 */  jal   chrlvSetGoposSegDistTotal
/* 067104 7F0325D4 02203025 */   move  $a2, $s1
.L7F0325D8:
/* 067108 7F0325D8 820D0038 */  lb    $t5, 0x38($s0)
.L7F0325DC:
/* 06710C 7F0325DC 24010006 */  li    $at, 6
/* 067110 7F0325E0 26090038 */  addiu $t1, $s0, 0x38
/* 067114 7F0325E4 15A1001E */  bne   $t5, $at, .L7F032660
/* 067118 7F0325E8 260400BC */   addiu $a0, $s0, 0xbc
/* 06711C 7F0325EC 8FAE0034 */  lw    $t6, 0x34($sp)
/* 067120 7F0325F0 8FAF003C */  lw    $t7, 0x3c($sp)
/* 067124 7F0325F4 55C00011 */  bnezl $t6, .L7F03263C
/* 067128 7F0325F8 8E2A0028 */   lw    $t2, 0x28($s1)
/* 06712C 7F0325FC 91F80001 */  lbu   $t8, 1($t7)
/* 067130 7F032600 02002025 */  move  $a0, $s0
/* 067134 7F032604 33190002 */  andi  $t9, $t8, 2
/* 067138 7F032608 17200004 */  bnez  $t9, .L7F03261C
/* 06713C 7F03260C 00000000 */   nop   
/* 067140 7F032610 0FC09F9C */  jal   chrlvStanRoomRelatedPad
/* 067144 7F032614 02202825 */   move  $a1, $s1
/* 067148 7F032618 14400007 */  bnez  $v0, .L7F032638
.L7F03261C:
/* 06714C 7F03261C 3C088005 */   lui   $t0, %hi(g_GlobalTimer) 
/* 067150 7F032620 8D08837C */  lw    $t0, %lo(g_GlobalTimer)($t0)
/* 067154 7F032624 02002025 */  move  $a0, $s0
/* 067158 7F032628 0FC0A125 */  jal   sub_GAME_7F028494
/* 06715C 7F03262C AE080078 */   sw    $t0, 0x78($s0)
/* 067160 7F032630 1000001E */  b     .L7F0326AC
/* 067164 7F032634 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F032638:
/* 067168 7F032638 8E2A0028 */  lw    $t2, 0x28($s1)
.L7F03263C:
/* 06716C 7F03263C 3C068003 */  lui   $a2, %hi(D_80030984)
/* 067170 7F032640 8CC60984 */  lw    $a2, %lo(D_80030984)($a2)
/* 067174 7F032644 02002025 */  move  $a0, $s0
/* 067178 7F032648 26050038 */  addiu $a1, $s0, 0x38
/* 06717C 7F03264C 02203825 */  move  $a3, $s1
/* 067180 7F032650 0FC0A180 */  jal   sub_GAME_7F028600
/* 067184 7F032654 AFAA0010 */   sw    $t2, 0x10($sp)
/* 067188 7F032658 10000014 */  b     .L7F0326AC
/* 06718C 7F03265C 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F032660:
/* 067190 7F032660 8FA5003C */  lw    $a1, 0x3c($sp)
/* 067194 7F032664 AFA9002C */  sw    $t1, 0x2c($sp)
/* 067198 7F032668 02203025 */  move  $a2, $s1
/* 06719C 7F03266C 3C0741F0 */  lui   $a3, 0x41f0
/* 0671A0 7F032670 0FC0BF54 */  jal   sub_GAME_7F02FD50
/* 0671A4 7F032674 24A50008 */   addiu $a1, $a1, 8
/* 0671A8 7F032678 50400007 */  beql  $v0, $zero, .L7F032698
/* 0671AC 7F03267C 02002025 */   move  $a0, $s0
/* 0671B0 7F032680 0FC0A137 */  jal   sub_GAME_7F0284DC
/* 0671B4 7F032684 02002025 */   move  $a0, $s0
/* 0671B8 7F032688 0FC0A11D */  jal   sub_GAME_7F028474
/* 0671BC 7F03268C 02002025 */   move  $a0, $s0
/* 0671C0 7F032690 00408825 */  move  $s1, $v0
/* 0671C4 7F032694 02002025 */  move  $a0, $s0
.L7F032698:
/* 0671C8 7F032698 02202825 */  move  $a1, $s1
/* 0671CC 7F03269C 8E260028 */  lw    $a2, 0x28($s1)
/* 0671D0 7F0326A0 0FC0C569 */  jal   sub_GAME_7F0315A4
/* 0671D4 7F0326A4 8FA7002C */   lw    $a3, 0x2c($sp)
/* 0671D8 7F0326A8 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F0326AC:
/* 0671DC 7F0326AC 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0671E0 7F0326B0 8FB10020 */  lw    $s1, 0x20($sp)
/* 0671E4 7F0326B4 03E00008 */  jr    $ra
/* 0671E8 7F0326B8 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif



#ifdef NONMATCHING
void manage_actions(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel jpt_80052070
 .word .L7F032788
 .word .L7F032798
 .word .L7F0327A8
 .word .L7F0327B8
 .word .L7F032808
 .word .L7F0327C8
 .word .L7F0327D8
 .word .L7F032818
 .word .L7F032828
 .word .L7F032838
 .word .L7F0327E8
 .word .L7F0327F8
 .word .L7F032848
 .word .L7F032858
 .word .L7F032868
 .word .L7F032878
 .word def_7F032780
 .word .L7F032898
 .word .L7F0328A8
 .word .L7F0328B8
 .word def_7F032780
 .word .L7F032888
 .word .L7F0328C8
 .word .L7F0328D8
.text
glabel manage_actions
/* 0671EC 7F0326BC 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0671F0 7F0326C0 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0671F4 7F0326C4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0671F8 7F0326C8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0671FC 7F0326CC 00808025 */  move  $s0, $a0
/* 067200 7F0326D0 1840008D */  blez  $v0, .L7F032908
/* 067204 7F0326D4 AFBF001C */   sw    $ra, 0x1c($sp)
/* 067208 7F0326D8 808E0007 */  lb    $t6, 7($a0)
/* 06720C 7F0326DC 55C0000A */  bnezl $t6, .L7F032708
/* 067210 7F0326E0 96190012 */   lhu   $t9, 0x12($s0)
/* 067214 7F0326E4 8C8F0014 */  lw    $t7, 0x14($a0)
/* 067218 7F0326E8 24050000 */  li    $a1, 0
/* 06721C 7F0326EC 35F80001 */  ori   $t8, $t7, 1
/* 067220 7F0326F0 0FC08EA5 */  jal   chrlvIdleAnimationRelated7F023A94
/* 067224 7F0326F4 AC980014 */   sw    $t8, 0x14($a0)
/* 067228 7F0326F8 A2000008 */  sb    $zero, 8($s0)
/* 06722C 7F0326FC 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 067230 7F032700 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 067234 7F032704 96190012 */  lhu   $t9, 0x12($s0)
.L7F032708:
/* 067238 7F032708 02002025 */  move  $a0, $s0
/* 06723C 7F03270C 24050003 */  li    $a1, 3
/* 067240 7F032710 33280040 */  andi  $t0, $t9, 0x40
/* 067244 7F032714 51000007 */  beql  $t0, $zero, .L7F032734
/* 067248 7F032718 820B0008 */   lb    $t3, 8($s0)
/* 06724C 7F03271C 8E090110 */  lw    $t1, 0x110($s0)
/* 067250 7F032720 01225021 */  addu  $t2, $t1, $v0
/* 067254 7F032724 AE0A0110 */  sw    $t2, 0x110($s0)
/* 067258 7F032728 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 06725C 7F03272C 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 067260 7F032730 820B0008 */  lb    $t3, 8($s0)
.L7F032734:
/* 067264 7F032734 01626023 */  subu  $t4, $t3, $v0
/* 067268 7F032738 A20C0008 */  sb    $t4, 8($s0)
/* 06726C 7F03273C 820D0008 */  lb    $t5, 8($s0)
/* 067270 7F032740 05A00005 */  bltz  $t5, .L7F032758
/* 067274 7F032744 00000000 */   nop   
/* 067278 7F032748 8E0E0014 */  lw    $t6, 0x14($s0)
/* 06727C 7F03274C 000E7B40 */  sll   $t7, $t6, 0xd
/* 067280 7F032750 05E3006E */  bgezl $t7, .L7F03290C
/* 067284 7F032754 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F032758:
/* 067288 7F032758 0FC0D521 */  jal   parse_handle_actionblocks
/* 06728C 7F03275C A2000008 */   sb    $zero, 8($s0)
/* 067290 7F032760 82180007 */  lb    $t8, 7($s0)
/* 067294 7F032764 2719FFFF */  addiu $t9, $t8, -1
/* 067298 7F032768 2F210018 */  sltiu $at, $t9, 0x18
/* 06729C 7F03276C 1020005C */  beqz  $at, .L7F0328E0
/* 0672A0 7F032770 0019C880 */   sll   $t9, $t9, 2
/* 0672A4 7F032774 3C018005 */  lui   $at, %hi(jpt_80052070)
/* 0672A8 7F032778 00390821 */  addu  $at, $at, $t9
/* 0672AC 7F03277C 8C392070 */  lw    $t9, %lo(jpt_80052070)($at)
/* 0672B0 7F032780 03200008 */  jr    $t9
/* 0672B4 7F032784 00000000 */   nop   
.L7F032788:
/* 0672B8 7F032788 0FC0AB66 */  jal   sub_GAME_7F02AD98
/* 0672BC 7F03278C 02002025 */   move  $a0, $s0
/* 0672C0 7F032790 10000054 */  b     .L7F0328E4
/* 0672C4 7F032794 8E080014 */   lw    $t0, 0x14($s0)
.L7F032798:
/* 0672C8 7F032798 0FC0AD38 */  jal   actor_reset_sleep
/* 0672CC 7F03279C 02002025 */   move  $a0, $s0
/* 0672D0 7F0327A0 10000050 */  b     .L7F0328E4
/* 0672D4 7F0327A4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0327A8:
/* 0672D8 7F0327A8 0FC0AD3A */  jal   sub_GAME_7F02B4E8
/* 0672DC 7F0327AC 02002025 */   move  $a0, $s0
/* 0672E0 7F0327B0 1000004C */  b     .L7F0328E4
/* 0672E4 7F0327B4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0327B8:
/* 0672E8 7F0327B8 0FC0AE69 */  jal   guard_body_hit_sfx
/* 0672EC 7F0327BC 02002025 */   move  $a0, $s0
/* 0672F0 7F0327C0 10000048 */  b     .L7F0328E4
/* 0672F4 7F0327C4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0327C8:
/* 0672F8 7F0327C8 0FC0AF20 */  jal   sub_GAME_7F02BC80
/* 0672FC 7F0327CC 02002025 */   move  $a0, $s0
/* 067300 7F0327D0 10000044 */  b     .L7F0328E4
/* 067304 7F0327D4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0327D8:
/* 067308 7F0327D8 0FC0AF48 */  jal   sub_GAME_7F02BD20
/* 06730C 7F0327DC 02002025 */   move  $a0, $s0
/* 067310 7F0327E0 10000040 */  b     .L7F0328E4
/* 067314 7F0327E4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0327E8:
/* 067318 7F0327E8 0FC0AF69 */  jal   sub_GAME_7F02BDA4
/* 06731C 7F0327EC 02002025 */   move  $a0, $s0
/* 067320 7F0327F0 1000003C */  b     .L7F0328E4
/* 067324 7F0327F4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0327F8:
/* 067328 7F0327F8 0FC0AF80 */  jal   sub_GAME_7F02BE00
/* 06732C 7F0327FC 02002025 */   move  $a0, $s0
/* 067330 7F032800 10000038 */  b     .L7F0328E4
/* 067334 7F032804 8E080014 */   lw    $t0, 0x14($s0)
.L7F032808:
/* 067338 7F032808 0FC0ADDD */  jal   manage_guard_fade
/* 06733C 7F03280C 02002025 */   move  $a0, $s0
/* 067340 7F032810 10000034 */  b     .L7F0328E4
/* 067344 7F032814 8E080014 */   lw    $t0, 0x14($s0)
.L7F032818:
/* 067348 7F032818 0FC0BAFF */  jal   sub_GAME_7F02EBFC
/* 06734C 7F03281C 02002025 */   move  $a0, $s0
/* 067350 7F032820 10000030 */  b     .L7F0328E4
/* 067354 7F032824 8E080014 */   lw    $t0, 0x14($s0)
.L7F032828:
/* 067358 7F032828 0FC0BE22 */  jal   sub_GAME_7F02F888
/* 06735C 7F03282C 02002025 */   move  $a0, $s0
/* 067360 7F032830 1000002C */  b     .L7F0328E4
/* 067364 7F032834 8E080014 */   lw    $t0, 0x14($s0)
.L7F032838:
/* 067368 7F032838 0FC0BBB8 */  jal   sub_GAME_7F02EEE0
/* 06736C 7F03283C 02002025 */   move  $a0, $s0
/* 067370 7F032840 10000028 */  b     .L7F0328E4
/* 067374 7F032844 8E080014 */   lw    $t0, 0x14($s0)
.L7F032848:
/* 067378 7F032848 0FC0BF9E */  jal   sub_GAME_7F02FE78
/* 06737C 7F03284C 02002025 */   move  $a0, $s0
/* 067380 7F032850 10000024 */  b     .L7F0328E4
/* 067384 7F032854 8E080014 */   lw    $t0, 0x14($s0)
.L7F032858:
/* 067388 7F032858 0FC0C952 */  jal   sub_GAME_7F032548
/* 06738C 7F03285C 02002025 */   move  $a0, $s0
/* 067390 7F032860 10000020 */  b     .L7F0328E4
/* 067394 7F032864 8E080014 */   lw    $t0, 0x14($s0)
.L7F032868:
/* 067398 7F032868 0FC0C822 */  jal   sub_GAME_7F032088
/* 06739C 7F03286C 02002025 */   move  $a0, $s0
/* 0673A0 7F032870 1000001C */  b     .L7F0328E4
/* 0673A4 7F032874 8E080014 */   lw    $t0, 0x14($s0)
.L7F032878:
/* 0673A8 7F032878 0FC0AD8E */  jal   chrlvSurrenderAnimationRelated7F02B638
/* 0673AC 7F03287C 02002025 */   move  $a0, $s0
/* 0673B0 7F032880 10000018 */  b     .L7F0328E4
/* 0673B4 7F032884 8E080014 */   lw    $t0, 0x14($s0)
.L7F032888:
/* 0673B8 7F032888 0FC0AF96 */  jal   sub_GAME_7F02BE58
/* 0673BC 7F03288C 02002025 */   move  $a0, $s0
/* 0673C0 7F032890 10000014 */  b     .L7F0328E4
/* 0673C4 7F032894 8E080014 */   lw    $t0, 0x14($s0)
.L7F032898:
/* 0673C8 7F032898 0FC0AFC9 */  jal   sub_GAME_7F02BF24
/* 0673CC 7F03289C 02002025 */   move  $a0, $s0
/* 0673D0 7F0328A0 10000010 */  b     .L7F0328E4
/* 0673D4 7F0328A4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0328A8:
/* 0673D8 7F0328A8 0FC0AFAA */  jal   sub_GAME_7F02BEA8
/* 0673DC 7F0328AC 02002025 */   move  $a0, $s0
/* 0673E0 7F0328B0 1000000C */  b     .L7F0328E4
/* 0673E4 7F0328B4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0328B8:
/* 0673E8 7F0328B8 0FC0BCFE */  jal   sub_GAME_7F02F3F8
/* 0673EC 7F0328BC 02002025 */   move  $a0, $s0
/* 0673F0 7F0328C0 10000008 */  b     .L7F0328E4
/* 0673F4 7F0328C4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0328C8:
/* 0673F8 7F0328C8 0FC0BD69 */  jal   sub_GAME_7F02F5A4
/* 0673FC 7F0328CC 02002025 */   move  $a0, $s0
/* 067400 7F0328D0 10000004 */  b     .L7F0328E4
/* 067404 7F0328D4 8E080014 */   lw    $t0, 0x14($s0)
.L7F0328D8:
/* 067408 7F0328D8 0FC0BDA2 */  jal   sub_GAME_7F02F688
/* 06740C 7F0328DC 02002025 */   move  $a0, $s0
def_7F032780:
.L7F0328E0:
/* 067410 7F0328E0 8E080014 */  lw    $t0, 0x14($s0)
.L7F0328E4:
/* 067414 7F0328E4 960A0012 */  lhu   $t2, 0x12($s0)
/* 067418 7F0328E8 2402FFFF */  li    $v0, -1
/* 06741C 7F0328EC 2401FFFB */  li    $at, -5
/* 067420 7F0328F0 01014824 */  and   $t1, $t0, $at
/* 067424 7F0328F4 314BFDFD */  andi  $t3, $t2, 0xfdfd
/* 067428 7F0328F8 AE090014 */  sw    $t1, 0x14($s0)
/* 06742C 7F0328FC A60B0012 */  sh    $t3, 0x12($s0)
/* 067430 7F032900 A6020118 */  sh    $v0, 0x118($s0)
/* 067434 7F032904 A602011A */  sh    $v0, 0x11a($s0)
.L7F032908:
/* 067438 7F032908 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F03290C:
/* 06743C 7F03290C 8FB00018 */  lw    $s0, 0x18($sp)
/* 067440 7F032910 27BD0020 */  addiu $sp, $sp, 0x20
/* 067444 7F032914 03E00008 */  jr    $ra
/* 067448 7F032918 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F03291C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03291C
/* 06744C 7F03291C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 067450 7F032920 AFBF001C */  sw    $ra, 0x1c($sp)
/* 067454 7F032924 0FC07D4C */  jal   get_numguards
/* 067458 7F032928 AFB00018 */   sw    $s0, 0x18($sp)
/* 06745C 7F03292C 3C0E8003 */  lui   $t6, %hi(objectiveregisters3) 
/* 067460 7F032930 8DCE0980 */  lw    $t6, %lo(objectiveregisters3)($t6)
/* 067464 7F032934 00405825 */  move  $t3, $v0
/* 067468 7F032938 00001825 */  move  $v1, $zero
/* 06746C 7F03293C 19C00010 */  blez  $t6, .L7F032980
/* 067470 7F032940 00008025 */   move  $s0, $zero
.L7F032944:
/* 067474 7F032944 3C0F8003 */  lui   $t7, %hi(objectiveregisters2) 
/* 067478 7F032948 8DEF097C */  lw    $t7, %lo(objectiveregisters2)($t7)
/* 06747C 7F03294C AFA30024 */  sw    $v1, 0x24($sp)
/* 067480 7F032950 AFAB0020 */  sw    $t3, 0x20($sp)
/* 067484 7F032954 0FC0C9AF */  jal   manage_actions
/* 067488 7F032958 020F2021 */   addu  $a0, $s0, $t7
/* 06748C 7F03295C 8FA30024 */  lw    $v1, 0x24($sp)
/* 067490 7F032960 3C188003 */  lui   $t8, %hi(objectiveregisters3) 
/* 067494 7F032964 8F180980 */  lw    $t8, %lo(objectiveregisters3)($t8)
/* 067498 7F032968 24630001 */  addiu $v1, $v1, 1
/* 06749C 7F03296C 261001DC */  addiu $s0, $s0, 0x1dc
/* 0674A0 7F032970 0078082A */  slt   $at, $v1, $t8
/* 0674A4 7F032974 1420FFF3 */  bnez  $at, .L7F032944
/* 0674A8 7F032978 8FAB0020 */   lw    $t3, 0x20($sp)
/* 0674AC 7F03297C 00001825 */  move  $v1, $zero
.L7F032980:
/* 0674B0 7F032980 3C048003 */  lui   $a0, %hi(setting_007_5)
/* 0674B4 7F032984 2484CE50 */  addiu $a0, %lo(setting_007_5) # addiu $a0, $a0, -0x31b0
/* 0674B8 7F032988 19600072 */  blez  $t3, .L7F032B54
/* 0674BC 7F03298C AC800000 */   sw    $zero, ($a0)
/* 0674C0 7F032990 31620003 */  andi  $v0, $t3, 3
/* 0674C4 7F032994 1040001D */  beqz  $v0, .L7F032A0C
/* 0674C8 7F032998 00403825 */   move  $a3, $v0
/* 0674CC 7F03299C 0003C900 */  sll   $t9, $v1, 4
/* 0674D0 7F0329A0 0323C823 */  subu  $t9, $t9, $v1
/* 0674D4 7F0329A4 3C0C8003 */  lui   $t4, %hi(ptr_guard_data) 
/* 0674D8 7F0329A8 8D8CCC64 */  lw    $t4, %lo(ptr_guard_data)($t4)
/* 0674DC 7F0329AC 0019C8C0 */  sll   $t9, $t9, 3
/* 0674E0 7F0329B0 0323C823 */  subu  $t9, $t9, $v1
/* 0674E4 7F0329B4 0019C880 */  sll   $t9, $t9, 2
/* 0674E8 7F0329B8 3C068005 */  lui   $a2, %hi(g_GlobalTimer)
/* 0674EC 7F0329BC 24C6837C */  addiu $a2, %lo(g_GlobalTimer) # addiu $a2, $a2, -0x7c84
/* 0674F0 7F0329C0 032C2821 */  addu  $a1, $t9, $t4
.L7F0329C4:
/* 0674F4 7F0329C4 8CAD001C */  lw    $t5, 0x1c($a1)
/* 0674F8 7F0329C8 24630001 */  addiu $v1, $v1, 1
/* 0674FC 7F0329CC 11A0000C */  beqz  $t5, .L7F032A00
/* 067500 7F0329D0 00000000 */   nop   
/* 067504 7F0329D4 8CA200D4 */  lw    $v0, 0xd4($a1)
/* 067508 7F0329D8 18400009 */  blez  $v0, .L7F032A00
/* 06750C 7F0329DC 00000000 */   nop   
/* 067510 7F0329E0 8CCE0000 */  lw    $t6, ($a2)
/* 067514 7F0329E4 01C27823 */  subu  $t7, $t6, $v0
/* 067518 7F0329E8 29E10078 */  slti  $at, $t7, 0x78
/* 06751C 7F0329EC 10200004 */  beqz  $at, .L7F032A00
/* 067520 7F0329F0 00000000 */   nop   
/* 067524 7F0329F4 8C980000 */  lw    $t8, ($a0)
/* 067528 7F0329F8 27190001 */  addiu $t9, $t8, 1
/* 06752C 7F0329FC AC990000 */  sw    $t9, ($a0)
.L7F032A00:
/* 067530 7F032A00 14E3FFF0 */  bne   $a3, $v1, .L7F0329C4
/* 067534 7F032A04 24A501DC */   addiu $a1, $a1, 0x1dc
/* 067538 7F032A08 106B0052 */  beq   $v1, $t3, .L7F032B54
.L7F032A0C:
/* 06753C 7F032A0C 00038100 */   sll   $s0, $v1, 4
/* 067540 7F032A10 02038023 */  subu  $s0, $s0, $v1
/* 067544 7F032A14 3C0C8003 */  lui   $t4, %hi(ptr_guard_data) 
/* 067548 7F032A18 8D8CCC64 */  lw    $t4, %lo(ptr_guard_data)($t4)
/* 06754C 7F032A1C 001080C0 */  sll   $s0, $s0, 3
/* 067550 7F032A20 02038023 */  subu  $s0, $s0, $v1
/* 067554 7F032A24 00108080 */  sll   $s0, $s0, 2
/* 067558 7F032A28 000B5100 */  sll   $t2, $t3, 4
/* 06755C 7F032A2C 014B5023 */  subu  $t2, $t2, $t3
/* 067560 7F032A30 020C2821 */  addu  $a1, $s0, $t4
/* 067564 7F032A34 000A50C0 */  sll   $t2, $t2, 3
/* 067568 7F032A38 014B5023 */  subu  $t2, $t2, $t3
/* 06756C 7F032A3C 3C068005 */  lui   $a2, %hi(g_GlobalTimer)
/* 067570 7F032A40 24C6837C */  addiu $a2, %lo(g_GlobalTimer) # addiu $a2, $a2, -0x7c84
/* 067574 7F032A44 000A5080 */  sll   $t2, $t2, 2
/* 067578 7F032A48 24A701DC */  addiu $a3, $a1, 0x1dc
/* 06757C 7F032A4C 24A803B8 */  addiu $t0, $a1, 0x3b8
/* 067580 7F032A50 24A90594 */  addiu $t1, $a1, 0x594
.L7F032A54:
/* 067584 7F032A54 8CAD001C */  lw    $t5, 0x1c($a1)
/* 067588 7F032A58 26100770 */  addiu $s0, $s0, 0x770
/* 06758C 7F032A5C 51A0000D */  beql  $t5, $zero, .L7F032A94
/* 067590 7F032A60 8CEC001C */   lw    $t4, 0x1c($a3)
/* 067594 7F032A64 8CA200D4 */  lw    $v0, 0xd4($a1)
/* 067598 7F032A68 5840000A */  blezl $v0, .L7F032A94
/* 06759C 7F032A6C 8CEC001C */   lw    $t4, 0x1c($a3)
/* 0675A0 7F032A70 8CCE0000 */  lw    $t6, ($a2)
/* 0675A4 7F032A74 01C27823 */  subu  $t7, $t6, $v0
/* 0675A8 7F032A78 29E10078 */  slti  $at, $t7, 0x78
/* 0675AC 7F032A7C 50200005 */  beql  $at, $zero, .L7F032A94
/* 0675B0 7F032A80 8CEC001C */   lw    $t4, 0x1c($a3)
/* 0675B4 7F032A84 8C980000 */  lw    $t8, ($a0)
/* 0675B8 7F032A88 27190001 */  addiu $t9, $t8, 1
/* 0675BC 7F032A8C AC990000 */  sw    $t9, ($a0)
/* 0675C0 7F032A90 8CEC001C */  lw    $t4, 0x1c($a3)
.L7F032A94:
/* 0675C4 7F032A94 00E01025 */  move  $v0, $a3
/* 0675C8 7F032A98 24E70770 */  addiu $a3, $a3, 0x770
/* 0675CC 7F032A9C 1180000C */  beqz  $t4, .L7F032AD0
/* 0675D0 7F032AA0 24A50770 */   addiu $a1, $a1, 0x770
/* 0675D4 7F032AA4 8C4300D4 */  lw    $v1, 0xd4($v0)
/* 0675D8 7F032AA8 5860000A */  blezl $v1, .L7F032AD4
/* 0675DC 7F032AAC 8D19001C */   lw    $t9, 0x1c($t0)
/* 0675E0 7F032AB0 8CCD0000 */  lw    $t5, ($a2)
/* 0675E4 7F032AB4 01A37023 */  subu  $t6, $t5, $v1
/* 0675E8 7F032AB8 29C10078 */  slti  $at, $t6, 0x78
/* 0675EC 7F032ABC 50200005 */  beql  $at, $zero, .L7F032AD4
/* 0675F0 7F032AC0 8D19001C */   lw    $t9, 0x1c($t0)
/* 0675F4 7F032AC4 8C8F0000 */  lw    $t7, ($a0)
/* 0675F8 7F032AC8 25F80001 */  addiu $t8, $t7, 1
/* 0675FC 7F032ACC AC980000 */  sw    $t8, ($a0)
.L7F032AD0:
/* 067600 7F032AD0 8D19001C */  lw    $t9, 0x1c($t0)
.L7F032AD4:
/* 067604 7F032AD4 01001025 */  move  $v0, $t0
/* 067608 7F032AD8 25080770 */  addiu $t0, $t0, 0x770
/* 06760C 7F032ADC 5320000D */  beql  $t9, $zero, .L7F032B14
/* 067610 7F032AE0 8D38001C */   lw    $t8, 0x1c($t1)
/* 067614 7F032AE4 8C4300D4 */  lw    $v1, 0xd4($v0)
/* 067618 7F032AE8 5860000A */  blezl $v1, .L7F032B14
/* 06761C 7F032AEC 8D38001C */   lw    $t8, 0x1c($t1)
/* 067620 7F032AF0 8CCC0000 */  lw    $t4, ($a2)
/* 067624 7F032AF4 01836823 */  subu  $t5, $t4, $v1
/* 067628 7F032AF8 29A10078 */  slti  $at, $t5, 0x78
/* 06762C 7F032AFC 50200005 */  beql  $at, $zero, .L7F032B14
/* 067630 7F032B00 8D38001C */   lw    $t8, 0x1c($t1)
/* 067634 7F032B04 8C8E0000 */  lw    $t6, ($a0)
/* 067638 7F032B08 25CF0001 */  addiu $t7, $t6, 1
/* 06763C 7F032B0C AC8F0000 */  sw    $t7, ($a0)
/* 067640 7F032B10 8D38001C */  lw    $t8, 0x1c($t1)
.L7F032B14:
/* 067644 7F032B14 01201025 */  move  $v0, $t1
/* 067648 7F032B18 1300000C */  beqz  $t8, .L7F032B4C
/* 06764C 7F032B1C 00000000 */   nop   
/* 067650 7F032B20 8C4300D4 */  lw    $v1, 0xd4($v0)
/* 067654 7F032B24 18600009 */  blez  $v1, .L7F032B4C
/* 067658 7F032B28 00000000 */   nop   
/* 06765C 7F032B2C 8CD90000 */  lw    $t9, ($a2)
/* 067660 7F032B30 03236023 */  subu  $t4, $t9, $v1
/* 067664 7F032B34 29810078 */  slti  $at, $t4, 0x78
/* 067668 7F032B38 10200004 */  beqz  $at, .L7F032B4C
/* 06766C 7F032B3C 00000000 */   nop   
/* 067670 7F032B40 8C8D0000 */  lw    $t5, ($a0)
/* 067674 7F032B44 25AE0001 */  addiu $t6, $t5, 1
/* 067678 7F032B48 AC8E0000 */  sw    $t6, ($a0)
.L7F032B4C:
/* 06767C 7F032B4C 160AFFC1 */  bne   $s0, $t2, .L7F032A54
/* 067680 7F032B50 25290770 */   addiu $t1, $t1, 0x770
.L7F032B54:
/* 067684 7F032B54 8FBF001C */  lw    $ra, 0x1c($sp)
/* 067688 7F032B58 8FB00018 */  lw    $s0, 0x18($sp)
/* 06768C 7F032B5C 27BD0028 */  addiu $sp, $sp, 0x28
/* 067690 7F032B60 03E00008 */  jr    $ra
/* 067694 7F032B64 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F032B68(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F032B68
/* 067698 7F032B68 8C8200D4 */  lw    $v0, 0xd4($a0)
/* 06769C 7F032B6C 3C0E8005 */  lui   $t6, %hi(g_GlobalTimer) 
/* 0676A0 7F032B70 58400009 */  blezl $v0, .L7F032B98
/* 0676A4 7F032B74 00001025 */   move  $v0, $zero
/* 0676A8 7F032B78 8DCE837C */  lw    $t6, %lo(g_GlobalTimer)($t6)
/* 0676AC 7F032B7C 01C27823 */  subu  $t7, $t6, $v0
/* 0676B0 7F032B80 29E10258 */  slti  $at, $t7, 0x258
/* 0676B4 7F032B84 50200004 */  beql  $at, $zero, .L7F032B98
/* 0676B8 7F032B88 00001025 */   move  $v0, $zero
/* 0676BC 7F032B8C 03E00008 */  jr    $ra
/* 0676C0 7F032B90 24020001 */   li    $v0, 1

/* 0676C4 7F032B94 00001025 */  move  $v0, $zero
.L7F032B98:
/* 0676C8 7F032B98 03E00008 */  jr    $ra
/* 0676CC 7F032B9C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F032BA0(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F032BA0
/* 0676D0 7F032BA0 8C8200F0 */  lw    $v0, 0xf0($a0)
/* 0676D4 7F032BA4 3C0E8005 */  lui   $t6, %hi(g_GlobalTimer) 
/* 0676D8 7F032BA8 58400009 */  blezl $v0, .L7F032BD0
/* 0676DC 7F032BAC 00001025 */   move  $v0, $zero
/* 0676E0 7F032BB0 8DCE837C */  lw    $t6, %lo(g_GlobalTimer)($t6)
/* 0676E4 7F032BB4 01C27823 */  subu  $t7, $t6, $v0
/* 0676E8 7F032BB8 29E10258 */  slti  $at, $t7, 0x258
/* 0676EC 7F032BBC 50200004 */  beql  $at, $zero, .L7F032BD0
/* 0676F0 7F032BC0 00001025 */   move  $v0, $zero
/* 0676F4 7F032BC4 03E00008 */  jr    $ra
/* 0676F8 7F032BC8 24020001 */   li    $v0, 1

/* 0676FC 7F032BCC 00001025 */  move  $v0, $zero
.L7F032BD0:
/* 067700 7F032BD0 03E00008 */  jr    $ra
/* 067704 7F032BD4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
// copied from ai branch:
f32 get_distance_actor_to_position(ChrRecord *self, coord3d *pos)
{
    f32 radToPos;
    f32 radMyHeading;
    PropRecord *myprop;
    f32 angle;

    radMyHeading = getsubroty(self->model);
    myprop       = self->prop;
    angle        = atan2f(pos->x - myprop->pos.x, pos->z - myprop->pos.z);
    radToPos     = angle - radMyHeading;

    if (angle < radMyHeading)
    {
        radToPos = radToPos + M_TAU;
    }
    return radToPos;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800520D0
.word 0x40c90fdb /*6.2831855*/
.text
glabel get_distance_actor_to_position
/* 067708 7F032BD8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 06770C 7F032BDC AFBF0014 */  sw    $ra, 0x14($sp)
/* 067710 7F032BE0 AFA40020 */  sw    $a0, 0x20($sp)
/* 067714 7F032BE4 AFA50024 */  sw    $a1, 0x24($sp)
/* 067718 7F032BE8 0FC1B320 */  jal   getsubroty
/* 06771C 7F032BEC 8C84001C */   lw    $a0, 0x1c($a0)
/* 067720 7F032BF0 8FAF0020 */  lw    $t7, 0x20($sp)
/* 067724 7F032BF4 8FA30024 */  lw    $v1, 0x24($sp)
/* 067728 7F032BF8 8DE20018 */  lw    $v0, 0x18($t7)
/* 06772C 7F032BFC C4640000 */  lwc1  $f4, ($v1)
/* 067730 7F032C00 C4680008 */  lwc1  $f8, 8($v1)
/* 067734 7F032C04 C4460008 */  lwc1  $f6, 8($v0)
/* 067738 7F032C08 C44A0010 */  lwc1  $f10, 0x10($v0)
/* 06773C 7F032C0C E7A00018 */  swc1  $f0, 0x18($sp)
/* 067740 7F032C10 46062301 */  sub.s $f12, $f4, $f6
/* 067744 7F032C14 0FC16A8C */  jal   atan2f
/* 067748 7F032C18 460A4381 */   sub.s $f14, $f8, $f10
/* 06774C 7F032C1C C7A20018 */  lwc1  $f2, 0x18($sp)
/* 067750 7F032C20 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067754 7F032C24 3C018005 */  lui   $at, %hi(D_800520D0)
/* 067758 7F032C28 4602003C */  c.lt.s $f0, $f2
/* 06775C 7F032C2C 27BD0020 */  addiu $sp, $sp, 0x20
/* 067760 7F032C30 46020381 */  sub.s $f14, $f0, $f2
/* 067764 7F032C34 45000003 */  bc1f  .L7F032C44
/* 067768 7F032C38 46007306 */   mov.s $f12, $f14
/* 06776C 7F032C3C C43020D0 */  lwc1  $f16, %lo(D_800520D0)($at)
/* 067770 7F032C40 46107300 */  add.s $f12, $f14, $f16
.L7F032C44:
/* 067774 7F032C44 03E00008 */  jr    $ra
/* 067778 7F032C48 46006006 */   mov.s $f0, $f12
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F032C4C(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F032C4C
/* 06777C 7F032C4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067780 7F032C50 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067784 7F032C54 0FC225E6 */  jal   get_curplayer_positiondata
/* 067788 7F032C58 AFA40018 */   sw    $a0, 0x18($sp)
/* 06778C 7F032C5C 8FA40018 */  lw    $a0, 0x18($sp)
/* 067790 7F032C60 0FC0CAF6 */  jal   get_distance_actor_to_position
/* 067794 7F032C64 24450008 */   addiu $a1, $v0, 8
/* 067798 7F032C68 8FBF0014 */  lw    $ra, 0x14($sp)
/* 06779C 7F032C6C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0677A0 7F032C70 03E00008 */  jr    $ra
/* 0677A4 7F032C74 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F032C78(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F032C78
/* 0677A8 7F032C78 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0677AC 7F032C7C 30AE0004 */  andi  $t6, $a1, 4
/* 0677B0 7F032C80 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0677B4 7F032C84 11C00012 */  beqz  $t6, .L7F032CD0
/* 0677B8 7F032C88 AFA70024 */   sw    $a3, 0x24($sp)
/* 0677BC 7F032C8C 00C02825 */  move  $a1, $a2
/* 0677C0 7F032C90 0FC0CC10 */  jal   get_handle_for_guard_id
/* 0677C4 7F032C94 AFA40018 */   sw    $a0, 0x18($sp)
/* 0677C8 7F032C98 8FA40018 */  lw    $a0, 0x18($sp)
/* 0677CC 7F032C9C 10400004 */  beqz  $v0, .L7F032CB0
/* 0677D0 7F032CA0 00401825 */   move  $v1, $v0
/* 0677D4 7F032CA4 8C4F0018 */  lw    $t7, 0x18($v0)
/* 0677D8 7F032CA8 55E00003 */  bnezl $t7, .L7F032CB8
/* 0677DC 7F032CAC 8C980018 */   lw    $t8, 0x18($a0)
.L7F032CB0:
/* 0677E0 7F032CB0 00801825 */  move  $v1, $a0
/* 0677E4 7F032CB4 8C980018 */  lw    $t8, 0x18($a0)
.L7F032CB8:
/* 0677E8 7F032CB8 8FA80024 */  lw    $t0, 0x24($sp)
/* 0677EC 7F032CBC 8F190014 */  lw    $t9, 0x14($t8)
/* 0677F0 7F032CC0 AD190000 */  sw    $t9, ($t0)
/* 0677F4 7F032CC4 8C620018 */  lw    $v0, 0x18($v1)
/* 0677F8 7F032CC8 10000025 */  b     .L7F032D60
/* 0677FC 7F032CCC 24420008 */   addiu $v0, $v0, 8
.L7F032CD0:
/* 067800 7F032CD0 30A90008 */  andi  $t1, $a1, 8
/* 067804 7F032CD4 1120001C */  beqz  $t1, .L7F032D48
/* 067808 7F032CD8 00000000 */   nop   
/* 06780C 7F032CDC 0FC0CBE5 */  jal   convertPadIf9000
/* 067810 7F032CE0 00C02825 */   move  $a1, $a2
/* 067814 7F032CE4 28412710 */  slti  $at, $v0, 0x2710
/* 067818 7F032CE8 1020000A */  beqz  $at, .L7F032D14
/* 06781C 7F032CEC 8FAF0024 */   lw    $t7, 0x24($sp)
/* 067820 7F032CF0 00025080 */  sll   $t2, $v0, 2
/* 067824 7F032CF4 01425023 */  subu  $t2, $t2, $v0
/* 067828 7F032CF8 000A5080 */  sll   $t2, $t2, 2
/* 06782C 7F032CFC 3C0B8007 */  lui   $t3, %hi(ptr_0xxxpresets) 
/* 067830 7F032D00 8D6B5D18 */  lw    $t3, %lo(ptr_0xxxpresets)($t3)
/* 067834 7F032D04 01425023 */  subu  $t2, $t2, $v0
/* 067838 7F032D08 000A5080 */  sll   $t2, $t2, 2
/* 06783C 7F032D0C 1000000A */  b     .L7F032D38
/* 067840 7F032D10 014B1821 */   addu  $v1, $t2, $t3
.L7F032D14:
/* 067844 7F032D14 3C0D8007 */  lui   $t5, %hi(ptr_2xxxpresets) 
/* 067848 7F032D18 8DAD5D1C */  lw    $t5, %lo(ptr_2xxxpresets)($t5)
/* 06784C 7F032D1C 00026100 */  sll   $t4, $v0, 4
/* 067850 7F032D20 01826021 */  addu  $t4, $t4, $v0
/* 067854 7F032D24 000C6080 */  sll   $t4, $t4, 2
/* 067858 7F032D28 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 06785C 7F032D2C 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 067860 7F032D30 018D1821 */  addu  $v1, $t4, $t5
/* 067864 7F032D34 00611821 */  addu  $v1, $v1, $at
.L7F032D38:
/* 067868 7F032D38 8C6E0028 */  lw    $t6, 0x28($v1)
/* 06786C 7F032D3C 00601025 */  move  $v0, $v1
/* 067870 7F032D40 10000007 */  b     .L7F032D60
/* 067874 7F032D44 ADEE0000 */   sw    $t6, ($t7)
.L7F032D48:
/* 067878 7F032D48 0FC225E6 */  jal   get_curplayer_positiondata
/* 06787C 7F032D4C 00000000 */   nop   
/* 067880 7F032D50 8C580014 */  lw    $t8, 0x14($v0)
/* 067884 7F032D54 8FB90024 */  lw    $t9, 0x24($sp)
/* 067888 7F032D58 24420008 */  addiu $v0, $v0, 8
/* 06788C 7F032D5C AF380000 */  sw    $t8, ($t9)
.L7F032D60:
/* 067890 7F032D60 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067894 7F032D64 27BD0018 */  addiu $sp, $sp, 0x18
/* 067898 7F032D68 03E00008 */  jr    $ra
/* 06789C 7F032D6C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void get_angle_between_actor_cur_player(void) {
// ai branch
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800520D4
.word 0x40c90fdb /*6.2831855*/
.text
glabel get_angle_between_actor_cur_player
/* 0678A0 7F032D70 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0678A4 7F032D74 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0678A8 7F032D78 0FC227B9 */  jal   get_curplay_horizontal_rotation_in_degrees
/* 0678AC 7F032D7C AFA40020 */   sw    $a0, 0x20($sp)
/* 0678B0 7F032D80 8FAE0020 */  lw    $t6, 0x20($sp)
/* 0678B4 7F032D84 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 0678B8 7F032D88 8DC30018 */  lw    $v1, 0x18($t6)
/* 0678BC 7F032D8C 0FC225E6 */  jal   get_curplayer_positiondata
/* 0678C0 7F032D90 AFA30018 */   sw    $v1, 0x18($sp)
/* 0678C4 7F032D94 8FA30018 */  lw    $v1, 0x18($sp)
/* 0678C8 7F032D98 C4460008 */  lwc1  $f6, 8($v0)
/* 0678CC 7F032D9C C44A0010 */  lwc1  $f10, 0x10($v0)
/* 0678D0 7F032DA0 C4640008 */  lwc1  $f4, 8($v1)
/* 0678D4 7F032DA4 C4680010 */  lwc1  $f8, 0x10($v1)
/* 0678D8 7F032DA8 46062301 */  sub.s $f12, $f4, $f6
/* 0678DC 7F032DAC 0FC16A8C */  jal   atan2f
/* 0678E0 7F032DB0 460A4381 */   sub.s $f14, $f8, $f10
/* 0678E4 7F032DB4 C7AE001C */  lwc1  $f14, 0x1c($sp)
/* 0678E8 7F032DB8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0678EC 7F032DBC 3C018005 */  lui   $at, %hi(D_800520D4)
/* 0678F0 7F032DC0 460E003C */  c.lt.s $f0, $f14
/* 0678F4 7F032DC4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0678F8 7F032DC8 460E0301 */  sub.s $f12, $f0, $f14
/* 0678FC 7F032DCC 45000003 */  bc1f  .L7F032DDC
/* 067900 7F032DD0 46006086 */   mov.s $f2, $f12
/* 067904 7F032DD4 C43020D4 */  lwc1  $f16, %lo(D_800520D4)($at)
/* 067908 7F032DD8 46106080 */  add.s $f2, $f12, $f16
.L7F032DDC:
/* 06790C 7F032DDC 03E00008 */  jr    $ra
/* 067910 7F032DE0 46001006 */   mov.s $f0, $f2
)
#endif


f32 distToBond3D(struct ChrRecord *guardData)
{
  struct PropRecord *guardPosData;
  struct PropRecord *playerPosData;
  float xDiff;
  float yDiff;
  float zDiff;
  
  guardPosData = guardData->prop;
  playerPosData = get_curplayer_positiondata();
  xDiff = playerPosData->pos.x - guardPosData->pos.x;
  yDiff = playerPosData->pos.y - guardPosData->pos.y;
  zDiff = playerPosData->pos.z - guardPosData->pos.z;

  return sqrtf(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
}


#ifdef NONMATCHING
void sub_GAME_7F032E48(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F032E48
/* 067978 7F032E48 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 06797C 7F032E4C AFBF0014 */  sw    $ra, 0x14($sp)
/* 067980 7F032E50 8C860018 */  lw    $a2, 0x18($a0)
/* 067984 7F032E54 0FC0CBE5 */  jal   convertPadIf9000
/* 067988 7F032E58 AFA6001C */   sw    $a2, 0x1c($sp)
/* 06798C 7F032E5C 28412710 */  slti  $at, $v0, 0x2710
/* 067990 7F032E60 1020000A */  beqz  $at, .L7F032E8C
/* 067994 7F032E64 8FA6001C */   lw    $a2, 0x1c($sp)
/* 067998 7F032E68 00027080 */  sll   $t6, $v0, 2
/* 06799C 7F032E6C 01C27023 */  subu  $t6, $t6, $v0
/* 0679A0 7F032E70 000E7080 */  sll   $t6, $t6, 2
/* 0679A4 7F032E74 3C0F8007 */  lui   $t7, %hi(ptr_0xxxpresets) 
/* 0679A8 7F032E78 8DEF5D18 */  lw    $t7, %lo(ptr_0xxxpresets)($t7)
/* 0679AC 7F032E7C 01C27023 */  subu  $t6, $t6, $v0
/* 0679B0 7F032E80 000E7080 */  sll   $t6, $t6, 2
/* 0679B4 7F032E84 1000000A */  b     .L7F032EB0
/* 0679B8 7F032E88 01CF1821 */   addu  $v1, $t6, $t7
.L7F032E8C:
/* 0679BC 7F032E8C 3C198007 */  lui   $t9, %hi(ptr_2xxxpresets) 
/* 0679C0 7F032E90 8F395D1C */  lw    $t9, %lo(ptr_2xxxpresets)($t9)
/* 0679C4 7F032E94 0002C100 */  sll   $t8, $v0, 4
/* 0679C8 7F032E98 0302C021 */  addu  $t8, $t8, $v0
/* 0679CC 7F032E9C 0018C080 */  sll   $t8, $t8, 2
/* 0679D0 7F032EA0 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 0679D4 7F032EA4 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 0679D8 7F032EA8 03191821 */  addu  $v1, $t8, $t9
/* 0679DC 7F032EAC 00611821 */  addu  $v1, $v1, $at
.L7F032EB0:
/* 0679E0 7F032EB0 C4640000 */  lwc1  $f4, ($v1)
/* 0679E4 7F032EB4 C4C60008 */  lwc1  $f6, 8($a2)
/* 0679E8 7F032EB8 C4680004 */  lwc1  $f8, 4($v1)
/* 0679EC 7F032EBC C4CA000C */  lwc1  $f10, 0xc($a2)
/* 0679F0 7F032EC0 46062001 */  sub.s $f0, $f4, $f6
/* 0679F4 7F032EC4 C4700008 */  lwc1  $f16, 8($v1)
/* 0679F8 7F032EC8 C4D20010 */  lwc1  $f18, 0x10($a2)
/* 0679FC 7F032ECC 460A4081 */  sub.s $f2, $f8, $f10
/* 067A00 7F032ED0 46000102 */  mul.s $f4, $f0, $f0
/* 067A04 7F032ED4 46128381 */  sub.s $f14, $f16, $f18
/* 067A08 7F032ED8 46021182 */  mul.s $f6, $f2, $f2
/* 067A0C 7F032EDC 46062200 */  add.s $f8, $f4, $f6
/* 067A10 7F032EE0 460E7282 */  mul.s $f10, $f14, $f14
/* 067A14 7F032EE4 0C007DF8 */  jal   sqrtf
/* 067A18 7F032EE8 460A4300 */   add.s $f12, $f8, $f10
/* 067A1C 7F032EEC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067A20 7F032EF0 27BD0020 */  addiu $sp, $sp, 0x20
/* 067A24 7F032EF4 03E00008 */  jr    $ra
/* 067A28 7F032EF8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_if_room_for_preset_loaded(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel check_if_room_for_preset_loaded
/* 067A2C 7F032EFC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067A30 7F032F00 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067A34 7F032F04 0FC0CBE5 */  jal   convertPadIf9000
/* 067A38 7F032F08 00000000 */   nop   
/* 067A3C 7F032F0C 28412710 */  slti  $at, $v0, 0x2710
/* 067A40 7F032F10 1020000A */  beqz  $at, .L7F032F3C
/* 067A44 7F032F14 0002C100 */   sll   $t8, $v0, 4
/* 067A48 7F032F18 00027080 */  sll   $t6, $v0, 2
/* 067A4C 7F032F1C 01C27023 */  subu  $t6, $t6, $v0
/* 067A50 7F032F20 000E7080 */  sll   $t6, $t6, 2
/* 067A54 7F032F24 3C0F8007 */  lui   $t7, %hi(ptr_0xxxpresets) 
/* 067A58 7F032F28 8DEF5D18 */  lw    $t7, %lo(ptr_0xxxpresets)($t7)
/* 067A5C 7F032F2C 01C27023 */  subu  $t6, $t6, $v0
/* 067A60 7F032F30 000E7080 */  sll   $t6, $t6, 2
/* 067A64 7F032F34 10000009 */  b     .L7F032F5C
/* 067A68 7F032F38 01CF1821 */   addu  $v1, $t6, $t7
.L7F032F3C:
/* 067A6C 7F032F3C 3C198007 */  lui   $t9, %hi(ptr_2xxxpresets) 
/* 067A70 7F032F40 8F395D1C */  lw    $t9, %lo(ptr_2xxxpresets)($t9)
/* 067A74 7F032F44 0302C021 */  addu  $t8, $t8, $v0
/* 067A78 7F032F48 0018C080 */  sll   $t8, $t8, 2
/* 067A7C 7F032F4C 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 067A80 7F032F50 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 067A84 7F032F54 03191821 */  addu  $v1, $t8, $t9
/* 067A88 7F032F58 00611821 */  addu  $v1, $v1, $at
.L7F032F5C:
/* 067A8C 7F032F5C 8C640028 */  lw    $a0, 0x28($v1)
/* 067A90 7F032F60 00001025 */  move  $v0, $zero
/* 067A94 7F032F64 10800007 */  beqz  $a0, .L7F032F84
/* 067A98 7F032F68 00000000 */   nop   
/* 067A9C 7F032F6C 0FC2CBF6 */  jal   getTileRoom
/* 067AA0 7F032F70 00000000 */   nop   
/* 067AA4 7F032F74 0FC2D794 */  jal   getROOMID_Bitflags
/* 067AA8 7F032F78 00402025 */   move  $a0, $v0
/* 067AAC 7F032F7C 10000002 */  b     .L7F032F88
/* 067AB0 7F032F80 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F032F84:
/* 067AB4 7F032F84 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F032F88:
/* 067AB8 7F032F88 27BD0018 */  addiu $sp, $sp, 0x18
/* 067ABC 7F032F8C 03E00008 */  jr    $ra
/* 067AC0 7F032F90 00000000 */   nop   
)
#endif


s32 convertPadIf9000(struct ChrRecord *guardData,s32 padNo)
{
    // Guard's target pad.
    if (padNo == PAD_PRESET) {
        padNo = (s32)guardData->padpreset1;
    }
    return padNo;
}


#ifdef NONMATCHING
void sub_GAME_7F032FAC(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F032FAC
/* 067ADC 7F032FAC 240100FA */  li    $at, 250
/* 067AE0 7F032FB0 54A10004 */  bnel  $a1, $at, .L7F032FC4
/* 067AE4 7F032FB4 240100FB */   li    $at, 251
/* 067AE8 7F032FB8 03E00008 */  jr    $ra
/* 067AEC 7F032FBC 84820118 */   lh    $v0, 0x118($a0)

/* 067AF0 7F032FC0 240100FB */  li    $at, 251
.L7F032FC4:
/* 067AF4 7F032FC4 54A10004 */  bnel  $a1, $at, .L7F032FD8
/* 067AF8 7F032FC8 240100FC */   li    $at, 252
/* 067AFC 7F032FCC 03E00008 */  jr    $ra
/* 067B00 7F032FD0 8482011A */   lh    $v0, 0x11a($a0)

/* 067B04 7F032FD4 240100FC */  li    $at, 252
.L7F032FD8:
/* 067B08 7F032FD8 54A10004 */  bnel  $a1, $at, .L7F032FEC
/* 067B0C 7F032FDC 240100FD */   li    $at, 253
/* 067B10 7F032FE0 03E00008 */  jr    $ra
/* 067B14 7F032FE4 84820116 */   lh    $v0, 0x116($a0)

/* 067B18 7F032FE8 240100FD */  li    $at, 253
.L7F032FEC:
/* 067B1C 7F032FEC 54A10004 */  bnel  $a1, $at, .L7F033000
/* 067B20 7F032FF0 240100F9 */   li    $at, 249
/* 067B24 7F032FF4 03E00008 */  jr    $ra
/* 067B28 7F032FF8 84820000 */   lh    $v0, ($a0)

/* 067B2C 7F032FFC 240100F9 */  li    $at, 249
.L7F033000:
/* 067B30 7F033000 54A10005 */  bnel  $a1, $at, .L7F033018
/* 067B34 7F033004 240100F8 */   li    $at, 248
/* 067B38 7F033008 84850000 */  lh    $a1, ($a0)
/* 067B3C 7F03300C 03E00008 */  jr    $ra
/* 067B40 7F033010 24A22710 */   addiu $v0, $a1, 0x2710

/* 067B44 7F033014 240100F8 */  li    $at, 248
.L7F033018:
/* 067B48 7F033018 14A10007 */  bne   $a1, $at, .L7F033038
/* 067B4C 7F03301C 3C0E8008 */   lui   $t6, %hi(g_CurrentPlayer) 
/* 067B50 7F033020 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 067B54 7F033024 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 067B58 7F033028 8DE20004 */  lw    $v0, 4($t7)
/* 067B5C 7F03302C 10400002 */  beqz  $v0, .L7F033038
/* 067B60 7F033030 00000000 */   nop   
/* 067B64 7F033034 84450000 */  lh    $a1, ($v0)
.L7F033038:
/* 067B68 7F033038 03E00008 */  jr    $ra
/* 067B6C 7F03303C 00A01025 */   move  $v0, $a1
)
#endif



#ifdef NONMATCHING
void get_handle_for_guard_id(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_handle_for_guard_id
/* 067B70 7F033040 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067B74 7F033044 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067B78 7F033048 0FC0CBEB */  jal   sub_GAME_7F032FAC
/* 067B7C 7F03304C 00000000 */   nop   
/* 067B80 7F033050 00402025 */  move  $a0, $v0
/* 067B84 7F033054 0FC08BF2 */  jal   chrGetGuardData
/* 067B88 7F033058 AFA2001C */   sw    $v0, 0x1c($sp)
/* 067B8C 7F03305C 8FA6001C */  lw    $a2, 0x1c($sp)
/* 067B90 7F033060 14400013 */  bnez  $v0, .L7F0330B0
/* 067B94 7F033064 00404025 */   move  $t0, $v0
/* 067B98 7F033068 3C058003 */  lui   $a1, %hi(objectiveregisters3)
/* 067B9C 7F03306C 8CA50980 */  lw    $a1, %lo(objectiveregisters3)($a1)
/* 067BA0 7F033070 00001025 */  move  $v0, $zero
/* 067BA4 7F033074 3C078003 */  lui   $a3, %hi(objectiveregisters2)
/* 067BA8 7F033078 58A0000E */  blezl $a1, .L7F0330B4
/* 067BAC 7F03307C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 067BB0 7F033080 8CE7097C */  lw    $a3, %lo(objectiveregisters2)($a3)
/* 067BB4 7F033084 00002025 */  move  $a0, $zero
/* 067BB8 7F033088 00E01825 */  move  $v1, $a3
.L7F03308C:
/* 067BBC 7F03308C 846E0000 */  lh    $t6, ($v1)
/* 067BC0 7F033090 24420001 */  addiu $v0, $v0, 1
/* 067BC4 7F033094 0045082A */  slt   $at, $v0, $a1
/* 067BC8 7F033098 14CE0003 */  bne   $a2, $t6, .L7F0330A8
/* 067BCC 7F03309C 246301DC */   addiu $v1, $v1, 0x1dc
/* 067BD0 7F0330A0 10000003 */  b     .L7F0330B0
/* 067BD4 7F0330A4 00874021 */   addu  $t0, $a0, $a3
.L7F0330A8:
/* 067BD8 7F0330A8 1420FFF8 */  bnez  $at, .L7F03308C
/* 067BDC 7F0330AC 248401DC */   addiu $a0, $a0, 0x1dc
.L7F0330B0:
/* 067BE0 7F0330B0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0330B4:
/* 067BE4 7F0330B4 27BD0018 */  addiu $sp, $sp, 0x18
/* 067BE8 7F0330B8 01001025 */  move  $v0, $t0
/* 067BEC 7F0330BC 03E00008 */  jr    $ra
/* 067BF0 7F0330C0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void get_distance_between_actor_and_actorID(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel get_distance_between_actor_and_actorID
/* 067BF4 7F0330C4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 067BF8 7F0330C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067BFC 7F0330CC 8C830018 */  lw    $v1, 0x18($a0)
/* 067C00 7F0330D0 0FC0CC10 */  jal   get_handle_for_guard_id
/* 067C04 7F0330D4 AFA3001C */   sw    $v1, 0x1c($sp)
/* 067C08 7F0330D8 44801000 */  mtc1  $zero, $f2
/* 067C0C 7F0330DC 10400018 */  beqz  $v0, .L7F033140
/* 067C10 7F0330E0 8FA3001C */   lw    $v1, 0x1c($sp)
/* 067C14 7F0330E4 8C4E001C */  lw    $t6, 0x1c($v0)
/* 067C18 7F0330E8 51C00016 */  beql  $t6, $zero, .L7F033144
/* 067C1C 7F0330EC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 067C20 7F0330F0 8C4F0018 */  lw    $t7, 0x18($v0)
/* 067C24 7F0330F4 51E00013 */  beql  $t7, $zero, .L7F033144
/* 067C28 7F0330F8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 067C2C 7F0330FC 8C420018 */  lw    $v0, 0x18($v0)
/* 067C30 7F033100 C4660008 */  lwc1  $f6, 8($v1)
/* 067C34 7F033104 C46A000C */  lwc1  $f10, 0xc($v1)
/* 067C38 7F033108 C4440008 */  lwc1  $f4, 8($v0)
/* 067C3C 7F03310C C448000C */  lwc1  $f8, 0xc($v0)
/* 067C40 7F033110 C4720010 */  lwc1  $f18, 0x10($v1)
/* 067C44 7F033114 46062001 */  sub.s $f0, $f4, $f6
/* 067C48 7F033118 C4500010 */  lwc1  $f16, 0x10($v0)
/* 067C4C 7F03311C 460A4081 */  sub.s $f2, $f8, $f10
/* 067C50 7F033120 46000102 */  mul.s $f4, $f0, $f0
/* 067C54 7F033124 46128381 */  sub.s $f14, $f16, $f18
/* 067C58 7F033128 46021182 */  mul.s $f6, $f2, $f2
/* 067C5C 7F03312C 46062200 */  add.s $f8, $f4, $f6
/* 067C60 7F033130 460E7282 */  mul.s $f10, $f14, $f14
/* 067C64 7F033134 0C007DF8 */  jal   sqrtf
/* 067C68 7F033138 460A4300 */   add.s $f12, $f8, $f10
/* 067C6C 7F03313C 46000086 */  mov.s $f2, $f0
.L7F033140:
/* 067C70 7F033140 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F033144:
/* 067C74 7F033144 27BD0020 */  addiu $sp, $sp, 0x20
/* 067C78 7F033148 46001006 */  mov.s $f0, $f2
/* 067C7C 7F03314C 03E00008 */  jr    $ra
/* 067C80 7F033150 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void get_distance_between_actor_and_preset(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel get_distance_between_actor_and_preset
/* 067C84 7F033154 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 067C88 7F033158 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067C8C 7F03315C AFA40020 */  sw    $a0, 0x20($sp)
/* 067C90 7F033160 0FC225E6 */  jal   get_curplayer_positiondata
/* 067C94 7F033164 AFA50024 */   sw    $a1, 0x24($sp)
/* 067C98 7F033168 8FA40020 */  lw    $a0, 0x20($sp)
/* 067C9C 7F03316C 8FA50024 */  lw    $a1, 0x24($sp)
/* 067CA0 7F033170 0FC0CBE5 */  jal   convertPadIf9000
/* 067CA4 7F033174 AFA2001C */   sw    $v0, 0x1c($sp)
/* 067CA8 7F033178 28412710 */  slti  $at, $v0, 0x2710
/* 067CAC 7F03317C 1020000A */  beqz  $at, .L7F0331A8
/* 067CB0 7F033180 8FA6001C */   lw    $a2, 0x1c($sp)
/* 067CB4 7F033184 00027080 */  sll   $t6, $v0, 2
/* 067CB8 7F033188 01C27023 */  subu  $t6, $t6, $v0
/* 067CBC 7F03318C 000E7080 */  sll   $t6, $t6, 2
/* 067CC0 7F033190 3C0F8007 */  lui   $t7, %hi(ptr_0xxxpresets) 
/* 067CC4 7F033194 8DEF5D18 */  lw    $t7, %lo(ptr_0xxxpresets)($t7)
/* 067CC8 7F033198 01C27023 */  subu  $t6, $t6, $v0
/* 067CCC 7F03319C 000E7080 */  sll   $t6, $t6, 2
/* 067CD0 7F0331A0 1000000A */  b     .L7F0331CC
/* 067CD4 7F0331A4 01CF1821 */   addu  $v1, $t6, $t7
.L7F0331A8:
/* 067CD8 7F0331A8 3C198007 */  lui   $t9, %hi(ptr_2xxxpresets) 
/* 067CDC 7F0331AC 8F395D1C */  lw    $t9, %lo(ptr_2xxxpresets)($t9)
/* 067CE0 7F0331B0 0002C100 */  sll   $t8, $v0, 4
/* 067CE4 7F0331B4 0302C021 */  addu  $t8, $t8, $v0
/* 067CE8 7F0331B8 0018C080 */  sll   $t8, $t8, 2
/* 067CEC 7F0331BC 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 067CF0 7F0331C0 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 067CF4 7F0331C4 03191821 */  addu  $v1, $t8, $t9
/* 067CF8 7F0331C8 00611821 */  addu  $v1, $v1, $at
.L7F0331CC:
/* 067CFC 7F0331CC C4640000 */  lwc1  $f4, ($v1)
/* 067D00 7F0331D0 C4C60008 */  lwc1  $f6, 8($a2)
/* 067D04 7F0331D4 C4680004 */  lwc1  $f8, 4($v1)
/* 067D08 7F0331D8 C4CA000C */  lwc1  $f10, 0xc($a2)
/* 067D0C 7F0331DC 46062001 */  sub.s $f0, $f4, $f6
/* 067D10 7F0331E0 C4700008 */  lwc1  $f16, 8($v1)
/* 067D14 7F0331E4 C4D20010 */  lwc1  $f18, 0x10($a2)
/* 067D18 7F0331E8 460A4081 */  sub.s $f2, $f8, $f10
/* 067D1C 7F0331EC 46000102 */  mul.s $f4, $f0, $f0
/* 067D20 7F0331F0 46128381 */  sub.s $f14, $f16, $f18
/* 067D24 7F0331F4 46021182 */  mul.s $f6, $f2, $f2
/* 067D28 7F0331F8 46062200 */  add.s $f8, $f4, $f6
/* 067D2C 7F0331FC 460E7282 */  mul.s $f10, $f14, $f14
/* 067D30 7F033200 0C007DF8 */  jal   sqrtf
/* 067D34 7F033204 460A4300 */   add.s $f12, $f8, $f10
/* 067D38 7F033208 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067D3C 7F03320C 27BD0020 */  addiu $sp, $sp, 0x20
/* 067D40 7F033210 03E00008 */  jr    $ra
/* 067D44 7F033214 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033218(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033218
/* 067D48 7F033218 AFA50004 */  sw    $a1, 4($sp)
/* 067D4C 7F03321C 908F010E */  lbu   $t7, 0x10e($a0)
/* 067D50 7F033220 01E5C025 */  or    $t8, $t7, $a1
/* 067D54 7F033224 03E00008 */  jr    $ra
/* 067D58 7F033228 A098010E */   sb    $t8, 0x10e($a0)
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F03322C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F03322C
/* 067D5C 7F03322C AFA50004 */  sw    $a1, 4($sp)
/* 067D60 7F033230 908F010E */  lbu   $t7, 0x10e($a0)
/* 067D64 7F033234 00A0C027 */  not   $t8, $a1
/* 067D68 7F033238 01F8C824 */  and   $t9, $t7, $t8
/* 067D6C 7F03323C 03E00008 */  jr    $ra
/* 067D70 7F033240 A099010E */   sb    $t9, 0x10e($a0)
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033244(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033244
/* 067D74 7F033244 AFA50004 */  sw    $a1, 4($sp)
/* 067D78 7F033248 908F010E */  lbu   $t7, 0x10e($a0)
/* 067D7C 7F03324C 30AE00FF */  andi  $t6, $a1, 0xff
/* 067D80 7F033250 01EE1024 */  and   $v0, $t7, $t6
/* 067D84 7F033254 0002C02B */  sltu  $t8, $zero, $v0
/* 067D88 7F033258 03E00008 */  jr    $ra
/* 067D8C 7F03325C 03001025 */   move  $v0, $t8
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033260(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033260
/* 067D90 7F033260 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067D94 7F033264 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067D98 7F033268 0FC0CC10 */  jal   get_handle_for_guard_id
/* 067D9C 7F03326C AFA60020 */   sw    $a2, 0x20($sp)
/* 067DA0 7F033270 10400003 */  beqz  $v0, .L7F033280
/* 067DA4 7F033274 00402025 */   move  $a0, $v0
/* 067DA8 7F033278 0FC0CC86 */  jal   sub_GAME_7F033218
/* 067DAC 7F03327C 93A50023 */   lbu   $a1, 0x23($sp)
.L7F033280:
/* 067DB0 7F033280 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067DB4 7F033284 27BD0018 */  addiu $sp, $sp, 0x18
/* 067DB8 7F033288 03E00008 */  jr    $ra
/* 067DBC 7F03328C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033290(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033290
/* 067DC0 7F033290 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067DC4 7F033294 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067DC8 7F033298 0FC0CC10 */  jal   get_handle_for_guard_id
/* 067DCC 7F03329C AFA60020 */   sw    $a2, 0x20($sp)
/* 067DD0 7F0332A0 10400003 */  beqz  $v0, .L7F0332B0
/* 067DD4 7F0332A4 00402025 */   move  $a0, $v0
/* 067DD8 7F0332A8 0FC0CC8B */  jal   sub_GAME_7F03322C
/* 067DDC 7F0332AC 93A50023 */   lbu   $a1, 0x23($sp)
.L7F0332B0:
/* 067DE0 7F0332B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067DE4 7F0332B4 27BD0018 */  addiu $sp, $sp, 0x18
/* 067DE8 7F0332B8 03E00008 */  jr    $ra
/* 067DEC 7F0332BC 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0332C0(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0332C0
/* 067DF0 7F0332C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067DF4 7F0332C4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067DF8 7F0332C8 0FC0CC10 */  jal   get_handle_for_guard_id
/* 067DFC 7F0332CC AFA60020 */   sw    $a2, 0x20($sp)
/* 067E00 7F0332D0 10400005 */  beqz  $v0, .L7F0332E8
/* 067E04 7F0332D4 00402025 */   move  $a0, $v0
/* 067E08 7F0332D8 0FC0CC91 */  jal   sub_GAME_7F033244
/* 067E0C 7F0332DC 93A50023 */   lbu   $a1, 0x23($sp)
/* 067E10 7F0332E0 10000003 */  b     .L7F0332F0
/* 067E14 7F0332E4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0332E8:
/* 067E18 7F0332E8 00001025 */  move  $v0, $zero
/* 067E1C 7F0332EC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0332F0:
/* 067E20 7F0332F0 27BD0018 */  addiu $sp, $sp, 0x18
/* 067E24 7F0332F4 03E00008 */  jr    $ra
/* 067E28 7F0332F8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void toggle_objective_bitflags(void) {

}
#else
GLOBAL_ASM(
.text
glabel toggle_objective_bitflags
/* 067E2C 7F0332FC 3C028003 */  lui   $v0, %hi(objectiveregisters1)
/* 067E30 7F033300 24420978 */  addiu $v0, %lo(objectiveregisters1) # addiu $v0, $v0, 0x978
/* 067E34 7F033304 8C4E0000 */  lw    $t6, ($v0)
/* 067E38 7F033308 AFA40000 */  sw    $a0, ($sp)
/* 067E3C 7F03330C 01C57825 */  or    $t7, $t6, $a1
/* 067E40 7F033310 03E00008 */  jr    $ra
/* 067E44 7F033314 AC4F0000 */   sw    $t7, ($v0)
)
#endif



#ifdef NONMATCHING
void untoggle_objective_bitflags(void) {

}
#else
GLOBAL_ASM(
.text
glabel untoggle_objective_bitflags
/* 067E48 7F033318 3C028003 */  lui   $v0, %hi(objectiveregisters1)
/* 067E4C 7F03331C 24420978 */  addiu $v0, %lo(objectiveregisters1) # addiu $v0, $v0, 0x978
/* 067E50 7F033320 8C4F0000 */  lw    $t7, ($v0)
/* 067E54 7F033324 00A07027 */  not   $t6, $a1
/* 067E58 7F033328 AFA40000 */  sw    $a0, ($sp)
/* 067E5C 7F03332C 01CFC024 */  and   $t8, $t6, $t7
/* 067E60 7F033330 03E00008 */  jr    $ra
/* 067E64 7F033334 AC580000 */   sw    $t8, ($v0)
)
#endif



#ifdef NONMATCHING
void check_if_objective_bitflags_set(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_objective_bitflags_set
/* 067E68 7F033338 3C0E8003 */  lui   $t6, %hi(objectiveregisters1) 
/* 067E6C 7F03333C 8DCE0978 */  lw    $t6, %lo(objectiveregisters1)($t6)
/* 067E70 7F033340 AFA40000 */  sw    $a0, ($sp)
/* 067E74 7F033344 01C51024 */  and   $v0, $t6, $a1
/* 067E78 7F033348 0002782B */  sltu  $t7, $zero, $v0
/* 067E7C 7F03334C 03E00008 */  jr    $ra
/* 067E80 7F033350 01E01025 */   move  $v0, $t7
)
#endif



#ifdef NONMATCHING
void check_if_actor_02_flag_set(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_actor_02_flag_set
/* 067E84 7F033354 94820012 */  lhu   $v0, 0x12($a0)
/* 067E88 7F033358 304E0002 */  andi  $t6, $v0, 2
/* 067E8C 7F03335C 03E00008 */  jr    $ra
/* 067E90 7F033360 000E102B */   sltu  $v0, $zero, $t6
)
#endif



#ifdef NONMATCHING
void check_if_able_to_then_surrender(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_able_to_then_surrender
/* 067E94 7F033364 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067E98 7F033368 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067E9C 7F03336C 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 067EA0 7F033370 AFA40018 */   sw    $a0, 0x18($sp)
/* 067EA4 7F033374 50400006 */  beql  $v0, $zero, .L7F033390
/* 067EA8 7F033378 00001025 */   move  $v0, $zero
/* 067EAC 7F03337C 0FC09192 */  jal   chrlvActorThrowWeaponSurrender
/* 067EB0 7F033380 8FA40018 */   lw    $a0, 0x18($sp)
/* 067EB4 7F033384 10000002 */  b     .L7F033390
/* 067EB8 7F033388 24020001 */   li    $v0, 1
/* 067EBC 7F03338C 00001025 */  move  $v0, $zero
.L7F033390:
/* 067EC0 7F033390 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067EC4 7F033394 27BD0018 */  addiu $sp, $sp, 0x18
/* 067EC8 7F033398 03E00008 */  jr    $ra
/* 067ECC 7F03339C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0333A0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0333A0
/* 067ED0 7F0333A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067ED4 7F0333A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067ED8 7F0333A8 0FC091EE */  jal   chrlvActorFadeAway
/* 067EDC 7F0333AC 00000000 */   nop   
/* 067EE0 7F0333B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067EE4 7F0333B4 27BD0018 */  addiu $sp, $sp, 0x18
/* 067EE8 7F0333B8 24020001 */  li    $v0, 1
/* 067EEC 7F0333BC 03E00008 */  jr    $ra
/* 067EF0 7F0333C0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void reset_and_start_loop_counter(void) {

}
#else
GLOBAL_ASM(
.text
glabel reset_and_start_loop_counter
/* 067EF4 7F0333C4 948E0012 */  lhu   $t6, 0x12($a0)
/* 067EF8 7F0333C8 AC800110 */  sw    $zero, 0x110($a0)
/* 067EFC 7F0333CC 35CF0040 */  ori   $t7, $t6, 0x40
/* 067F00 7F0333D0 03E00008 */  jr    $ra
/* 067F04 7F0333D4 A48F0012 */   sh    $t7, 0x12($a0)
)
#endif



#ifdef NONMATCHING
void get_loop_counter_time_in_seconds(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_loop_counter_time_in_seconds
/* 067F08 7F0333D8 8C8E0110 */  lw    $t6, 0x110($a0)
/* 067F0C 7F0333DC 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 067F10 7F0333E0 44814000 */  mtc1  $at, $f8
/* 067F14 7F0333E4 448E2000 */  mtc1  $t6, $f4
/* 067F18 7F0333E8 00000000 */  nop   
/* 067F1C 7F0333EC 468021A0 */  cvt.s.w $f6, $f4
/* 067F20 7F0333F0 03E00008 */  jr    $ra
/* 067F24 7F0333F4 46083003 */   div.s $f0, $f6, $f8
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0333F8(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800520D8
.word 0x3f4ccccd /*0.80000001*/
.text
glabel sub_GAME_7F0333F8
/* 067F28 7F0333F8 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 067F2C 7F0333FC AFBF0014 */  sw    $ra, 0x14($sp)
/* 067F30 7F033400 0FC0A5D8 */  jal   chrlvCurrentPlayerCall7F0B0E24
/* 067F34 7F033404 AFA40048 */   sw    $a0, 0x48($sp)
/* 067F38 7F033408 1040001C */  beqz  $v0, .L7F03347C
/* 067F3C 7F03340C 8FAE0048 */   lw    $t6, 0x48($sp)
/* 067F40 7F033410 8DC4001C */  lw    $a0, 0x1c($t6)
/* 067F44 7F033414 0FC1B403 */  jal   getinstsize
/* 067F48 7F033418 AFA40044 */   sw    $a0, 0x44($sp)
/* 067F4C 7F03341C 3C018005 */  lui   $at, %hi(D_800520D8)
/* 067F50 7F033420 C42420D8 */  lwc1  $f4, %lo(D_800520D8)($at)
/* 067F54 7F033424 27A40038 */  addiu $a0, $sp, 0x38
/* 067F58 7F033428 27A5002C */  addiu $a1, $sp, 0x2c
/* 067F5C 7F03342C 46040182 */  mul.s $f6, $f0, $f4
/* 067F60 7F033430 0FC1A064 */  jal   sub_GAME_7F068190
/* 067F64 7F033434 E7A6001C */   swc1  $f6, 0x1c($sp)
/* 067F68 7F033438 8FA40044 */  lw    $a0, 0x44($sp)
/* 067F6C 7F03343C 0FC1B2E6 */  jal   getsuboffset
/* 067F70 7F033440 27A50020 */   addiu $a1, $sp, 0x20
/* 067F74 7F033444 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 067F78 7F033448 00000000 */   nop   
/* 067F7C 7F03344C 00402025 */  move  $a0, $v0
/* 067F80 7F033450 0FC1611D */  jal   matrix_4x4_transform_vector_in_place
/* 067F84 7F033454 27A50020 */   addiu $a1, $sp, 0x20
/* 067F88 7F033458 27A40038 */  addiu $a0, $sp, 0x38
/* 067F8C 7F03345C 27A5002C */  addiu $a1, $sp, 0x2c
/* 067F90 7F033460 27A60020 */  addiu $a2, $sp, 0x20
/* 067F94 7F033464 0FC1041D */  jal   sub_GAME_7F041074
/* 067F98 7F033468 8FA7001C */   lw    $a3, 0x1c($sp)
/* 067F9C 7F03346C 50400004 */  beql  $v0, $zero, .L7F033480
/* 067FA0 7F033470 00001025 */   move  $v0, $zero
/* 067FA4 7F033474 10000002 */  b     .L7F033480
/* 067FA8 7F033478 24020001 */   li    $v0, 1
.L7F03347C:
/* 067FAC 7F03347C 00001025 */  move  $v0, $zero
.L7F033480:
/* 067FB0 7F033480 8FBF0014 */  lw    $ra, 0x14($sp)
/* 067FB4 7F033484 27BD0048 */  addiu $sp, $sp, 0x48
/* 067FB8 7F033488 03E00008 */  jr    $ra
/* 067FBC 7F03348C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_if_actor_invisible(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_actor_invisible
/* 067FC0 7F033490 8C820014 */  lw    $v0, 0x14($a0)
/* 067FC4 7F033494 304E0004 */  andi  $t6, $v0, 4
/* 067FC8 7F033498 03E00008 */  jr    $ra
/* 067FCC 7F03349C 000E102B */   sltu  $v0, $zero, $t6
)
#endif



#ifdef NONMATCHING
void actor_move_to_curplayer_at_speed(void) {

}
#else
GLOBAL_ASM(
.text
glabel actor_move_to_curplayer_at_speed
/* 067FD0 7F0334A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 067FD4 7F0334A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 067FD8 7F0334A8 AFA40018 */  sw    $a0, 0x18($sp)
/* 067FDC 7F0334AC 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 067FE0 7F0334B0 AFA5001C */   sw    $a1, 0x1c($sp)
/* 067FE4 7F0334B4 10400010 */  beqz  $v0, .L7F0334F8
/* 067FE8 7F0334B8 3C0E8003 */   lui   $t6, %hi(setting_007_5) 
/* 067FEC 7F0334BC 8DCECE50 */  lw    $t6, %lo(setting_007_5)($t6)
/* 067FF0 7F0334C0 29C1000A */  slti  $at, $t6, 0xa
/* 067FF4 7F0334C4 5020000D */  beql  $at, $zero, .L7F0334FC
/* 067FF8 7F0334C8 00001025 */   move  $v0, $zero
/* 067FFC 7F0334CC 0FC225E6 */  jal   get_curplayer_positiondata
/* 068000 7F0334D0 00000000 */   nop   
/* 068004 7F0334D4 8FA40018 */  lw    $a0, 0x18($sp)
/* 068008 7F0334D8 24450008 */  addiu $a1, $v0, 8
/* 06800C 7F0334DC 8C460014 */  lw    $a2, 0x14($v0)
/* 068010 7F0334E0 0FC0A377 */  jal   plot_course_for_actor
/* 068014 7F0334E4 8FA7001C */   lw    $a3, 0x1c($sp)
/* 068018 7F0334E8 50400004 */  beql  $v0, $zero, .L7F0334FC
/* 06801C 7F0334EC 00001025 */   move  $v0, $zero
/* 068020 7F0334F0 10000002 */  b     .L7F0334FC
/* 068024 7F0334F4 24020001 */   li    $v0, 1
.L7F0334F8:
/* 068028 7F0334F8 00001025 */  move  $v0, $zero
.L7F0334FC:
/* 06802C 7F0334FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 068030 7F033500 27BD0018 */  addiu $sp, $sp, 0x18
/* 068034 7F033504 03E00008 */  jr    $ra
/* 068038 7F033508 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void actor_move_to_actorID_at_speed(void) {

}
#else
GLOBAL_ASM(
.text
glabel actor_move_to_actorID_at_speed
/* 06803C 7F03350C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 068040 7F033510 AFBF0014 */  sw    $ra, 0x14($sp)
/* 068044 7F033514 AFA40018 */  sw    $a0, 0x18($sp)
/* 068048 7F033518 AFA5001C */  sw    $a1, 0x1c($sp)
/* 06804C 7F03351C 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 068050 7F033520 AFA60020 */   sw    $a2, 0x20($sp)
/* 068054 7F033524 1040001A */  beqz  $v0, .L7F033590
/* 068058 7F033528 3C0E8003 */   lui   $t6, %hi(setting_007_5) 
/* 06805C 7F03352C 8DCECE50 */  lw    $t6, %lo(setting_007_5)($t6)
/* 068060 7F033530 8FA40018 */  lw    $a0, 0x18($sp)
/* 068064 7F033534 29C1000A */  slti  $at, $t6, 0xa
/* 068068 7F033538 50200016 */  beql  $at, $zero, .L7F033594
/* 06806C 7F03353C 00001025 */   move  $v0, $zero
/* 068070 7F033540 0FC0CC10 */  jal   get_handle_for_guard_id
/* 068074 7F033544 8FA5001C */   lw    $a1, 0x1c($sp)
/* 068078 7F033548 50400012 */  beql  $v0, $zero, .L7F033594
/* 06807C 7F03354C 00001025 */   move  $v0, $zero
/* 068080 7F033550 8C4F001C */  lw    $t7, 0x1c($v0)
/* 068084 7F033554 51E0000F */  beql  $t7, $zero, .L7F033594
/* 068088 7F033558 00001025 */   move  $v0, $zero
/* 06808C 7F03355C 8C580018 */  lw    $t8, 0x18($v0)
/* 068090 7F033560 5300000C */  beql  $t8, $zero, .L7F033594
/* 068094 7F033564 00001025 */   move  $v0, $zero
/* 068098 7F033568 8C420018 */  lw    $v0, 0x18($v0)
/* 06809C 7F03356C 8FA40018 */  lw    $a0, 0x18($sp)
/* 0680A0 7F033570 8FA70020 */  lw    $a3, 0x20($sp)
/* 0680A4 7F033574 24450008 */  addiu $a1, $v0, 8
/* 0680A8 7F033578 0FC0A377 */  jal   plot_course_for_actor
/* 0680AC 7F03357C 8C460014 */   lw    $a2, 0x14($v0)
/* 0680B0 7F033580 50400004 */  beql  $v0, $zero, .L7F033594
/* 0680B4 7F033584 00001025 */   move  $v0, $zero
/* 0680B8 7F033588 10000002 */  b     .L7F033594
/* 0680BC 7F03358C 24020001 */   li    $v0, 1
.L7F033590:
/* 0680C0 7F033590 00001025 */  move  $v0, $zero
.L7F033594:
/* 0680C4 7F033594 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0680C8 7F033598 27BD0018 */  addiu $sp, $sp, 0x18
/* 0680CC 7F03359C 03E00008 */  jr    $ra
/* 0680D0 7F0335A0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void get_times_actor_shot(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_times_actor_shot
/* 0680D4 7F0335A4 03E00008 */  jr    $ra
/* 0680D8 7F0335A8 8082000B */   lb    $v0, 0xb($a0)
)
#endif



#ifdef NONMATCHING
void get_num_shots_near_actor(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_num_shots_near_actor
/* 0680DC 7F0335AC 03E00008 */  jr    $ra
/* 0680E0 7F0335B0 8082000A */   lb    $v0, 0xa($a0)
)
#endif



#ifdef NONMATCHING
void check_if_actor_FA_target_set(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_actor_FA_target_set
/* 0680E4 7F0335B4 84820118 */  lh    $v0, 0x118($a0)
/* 0680E8 7F0335B8 284E0000 */  slti  $t6, $v0, 0
/* 0680EC 7F0335BC 03E00008 */  jr    $ra
/* 0680F0 7F0335C0 39C20001 */   xori  $v0, $t6, 1
)
#endif



#ifdef NONMATCHING
void check_if_actor_FB_target_set(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_actor_FB_target_set
/* 0680F4 7F0335C4 8482011A */  lh    $v0, 0x11a($a0)
/* 0680F8 7F0335C8 284E0000 */  slti  $t6, $v0, 0
/* 0680FC 7F0335CC 03E00008 */  jr    $ra
/* 068100 7F0335D0 39C20001 */   xori  $v0, $t6, 1
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F0335D4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0335D4
/* 068104 7F0335D4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 068108 7F0335D8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 06810C 7F0335DC 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 068110 7F0335E0 AFA40018 */   sw    $a0, 0x18($sp)
/* 068114 7F0335E4 50400006 */  beql  $v0, $zero, .L7F033600
/* 068118 7F0335E8 00001025 */   move  $v0, $zero
/* 06811C 7F0335EC 0FC08F92 */  jal   chrlvKneelingAnimationRelated7F023E48
/* 068120 7F0335F0 8FA40018 */   lw    $a0, 0x18($sp)
/* 068124 7F0335F4 10000002 */  b     .L7F033600
/* 068128 7F0335F8 24020001 */   li    $v0, 1
/* 06812C 7F0335FC 00001025 */  move  $v0, $zero
.L7F033600:
/* 068130 7F033600 8FBF0014 */  lw    $ra, 0x14($sp)
/* 068134 7F033604 27BD0018 */  addiu $sp, $sp, 0x18
/* 068138 7F033608 03E00008 */  jr    $ra
/* 06813C 7F03360C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_if_able_to_then_shuffle_feet(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_able_to_then_shuffle_feet
/* 068140 7F033610 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 068144 7F033614 AFBF0014 */  sw    $ra, 0x14($sp)
/* 068148 7F033618 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 06814C 7F03361C AFA40018 */   sw    $a0, 0x18($sp)
/* 068150 7F033620 50400006 */  beql  $v0, $zero, .L7F03363C
/* 068154 7F033624 00001025 */   move  $v0, $zero
/* 068158 7F033628 0FC09106 */  jal   chrlvActorShuffleFeet
/* 06815C 7F03362C 8FA40018 */   lw    $a0, 0x18($sp)
/* 068160 7F033630 10000002 */  b     .L7F03363C
/* 068164 7F033634 24020001 */   li    $v0, 1
/* 068168 7F033638 00001025 */  move  $v0, $zero
.L7F03363C:
/* 06816C 7F03363C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 068170 7F033640 27BD0018 */  addiu $sp, $sp, 0x18
/* 068174 7F033644 03E00008 */  jr    $ra
/* 068178 7F033648 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_if_able_to_then_fawn_on_shoulder(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_able_to_then_fawn_on_shoulder
/* 06817C 7F03364C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 068180 7F033650 AFBF0014 */  sw    $ra, 0x14($sp)
/* 068184 7F033654 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 068188 7F033658 AFA40018 */   sw    $a0, 0x18($sp)
/* 06818C 7F03365C 50400006 */  beql  $v0, $zero, .L7F033678
/* 068190 7F033660 00001025 */   move  $v0, $zero
/* 068194 7F033664 0FC0912B */  jal   chrlvSurrenderAnimationRelated
/* 068198 7F033668 8FA40018 */   lw    $a0, 0x18($sp)
/* 06819C 7F03366C 10000002 */  b     .L7F033678
/* 0681A0 7F033670 24020001 */   li    $v0, 1
/* 0681A4 7F033674 00001025 */  move  $v0, $zero
.L7F033678:
/* 0681A8 7F033678 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0681AC 7F03367C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0681B0 7F033680 03E00008 */  jr    $ra
/* 0681B4 7F033684 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_if_able_to_then_look_flustered(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_able_to_then_look_flustered
/* 0681B8 7F033688 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0681BC 7F03368C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0681C0 7F033690 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 0681C4 7F033694 AFA40018 */   sw    $a0, 0x18($sp)
/* 0681C8 7F033698 50400006 */  beql  $v0, $zero, .L7F0336B4
/* 0681CC 7F03369C 00001025 */   move  $v0, $zero
/* 0681D0 7F0336A0 0FC09152 */  jal   chrlvActorLookFlustered
/* 0681D4 7F0336A4 8FA40018 */   lw    $a0, 0x18($sp)
/* 0681D8 7F0336A8 10000002 */  b     .L7F0336B4
/* 0681DC 7F0336AC 24020001 */   li    $v0, 1
/* 0681E0 7F0336B0 00001025 */  move  $v0, $zero
.L7F0336B4:
/* 0681E4 7F0336B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0681E8 7F0336B8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0681EC 7F0336BC 03E00008 */  jr    $ra
/* 0681F0 7F0336C0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_if_able_to_then_kneel(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_if_able_to_then_kneel
/* 0681F4 7F0336C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0681F8 7F0336C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0681FC 7F0336CC 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 068200 7F0336D0 AFA40018 */   sw    $a0, 0x18($sp)
/* 068204 7F0336D4 50400006 */  beql  $v0, $zero, .L7F0336F0
/* 068208 7F0336D8 00001025 */   move  $v0, $zero
/* 06820C 7F0336DC 0FC08F9D */  jal   chrlvActorKneel
/* 068210 7F0336E0 8FA40018 */   lw    $a0, 0x18($sp)
/* 068214 7F0336E4 10000002 */  b     .L7F0336F0
/* 068218 7F0336E8 24020001 */   li    $v0, 1
/* 06821C 7F0336EC 00001025 */  move  $v0, $zero
.L7F0336F0:
/* 068220 7F0336F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 068224 7F0336F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 068228 7F0336F8 03E00008 */  jr    $ra
/* 06822C 7F0336FC 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_if_able_to_then_perform_animation(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel check_if_able_to_then_perform_animation
/* 068230 7F033700 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 068234 7F033704 AFBF001C */  sw    $ra, 0x1c($sp)
/* 068238 7F033708 AFA40020 */  sw    $a0, 0x20($sp)
/* 06823C 7F03370C AFA50024 */  sw    $a1, 0x24($sp)
/* 068240 7F033710 AFA60028 */  sw    $a2, 0x28($sp)
/* 068244 7F033714 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 068248 7F033718 AFA7002C */   sw    $a3, 0x2c($sp)
/* 06824C 7F03371C 1040000B */  beqz  $v0, .L7F03374C
/* 068250 7F033720 8FA40020 */   lw    $a0, 0x20($sp)
/* 068254 7F033724 93AE0033 */  lbu   $t6, 0x33($sp)
/* 068258 7F033728 8FAF0034 */  lw    $t7, 0x34($sp)
/* 06825C 7F03372C 8FA50024 */  lw    $a1, 0x24($sp)
/* 068260 7F033730 8FA60028 */  lw    $a2, 0x28($sp)
/* 068264 7F033734 8FA7002C */  lw    $a3, 0x2c($sp)
/* 068268 7F033738 AFAE0010 */  sw    $t6, 0x10($sp)
/* 06826C 7F03373C 0FC08FF9 */  jal   chrlvPerformAnimationForActor
/* 068270 7F033740 AFAF0014 */   sw    $t7, 0x14($sp)
/* 068274 7F033744 10000002 */  b     .L7F033750
/* 068278 7F033748 24020001 */   li    $v0, 1
.L7F03374C:
/* 06827C 7F03374C 00001025 */  move  $v0, $zero
.L7F033750:
/* 068280 7F033750 8FBF001C */  lw    $ra, 0x1c($sp)
/* 068284 7F033754 27BD0020 */  addiu $sp, $sp, 0x20
/* 068288 7F033758 03E00008 */  jr    $ra
/* 06828C 7F03375C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void alarm_timer_related(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel alarm_timer_related
/* 068290 7F033760 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 068294 7F033764 AFBF0014 */  sw    $ra, 0x14($sp)
/* 068298 7F033768 0FC15794 */  jal   is_alarm_on
/* 06829C 7F03376C AFA40018 */   sw    $a0, 0x18($sp)
/* 0682A0 7F033770 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0682A4 7F033774 27BD0018 */  addiu $sp, $sp, 0x18
/* 0682A8 7F033778 03E00008 */  jr    $ra
/* 0682AC 7F03377C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033780(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800520DC
.word 0x40c90fdb /*6.2831855*/
glabel D_800520E0
.word 0x3fc90fdb /*1.5707964*/
glabel D_800520E4
.word 0x4096cbe4 /*4.712389*/
.text
glabel sub_GAME_7F033780
/* 0682B0 7F033780 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0682B4 7F033784 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0682B8 7F033788 AFA60020 */  sw    $a2, 0x20($sp)
/* 0682BC 7F03378C 8C8E0000 */  lw    $t6, ($a0)
/* 0682C0 7F033790 3C188007 */  lui   $t8, %hi(ptr_0xxxpresets) 
/* 0682C4 7F033794 8F185D18 */  lw    $t8, %lo(ptr_0xxxpresets)($t8)
/* 0682C8 7F033798 000E7880 */  sll   $t7, $t6, 2
/* 0682CC 7F03379C 01EE7823 */  subu  $t7, $t7, $t6
/* 0682D0 7F0337A0 000F7880 */  sll   $t7, $t7, 2
/* 0682D4 7F0337A4 01EE7823 */  subu  $t7, $t7, $t6
/* 0682D8 7F0337A8 000F7880 */  sll   $t7, $t7, 2
/* 0682DC 7F0337AC 01F81021 */  addu  $v0, $t7, $t8
/* 0682E0 7F0337B0 C4440000 */  lwc1  $f4, ($v0)
/* 0682E4 7F0337B4 C4A60000 */  lwc1  $f6, ($a1)
/* 0682E8 7F0337B8 C4480008 */  lwc1  $f8, 8($v0)
/* 0682EC 7F0337BC C4AA0008 */  lwc1  $f10, 8($a1)
/* 0682F0 7F0337C0 46062301 */  sub.s $f12, $f4, $f6
/* 0682F4 7F0337C4 0FC16A8C */  jal   atan2f
/* 0682F8 7F0337C8 460A4381 */   sub.s $f14, $f8, $f10
/* 0682FC 7F0337CC C7AE0020 */  lwc1  $f14, 0x20($sp)
/* 068300 7F0337D0 3C018005 */  lui   $at, %hi(D_800520DC)
/* 068304 7F0337D4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 068308 7F0337D8 4600703C */  c.lt.s $f14, $f0
/* 06830C 7F0337DC 46007301 */  sub.s $f12, $f14, $f0
/* 068310 7F0337E0 45000003 */  bc1f  .L7F0337F0
/* 068314 7F0337E4 46006086 */   mov.s $f2, $f12
/* 068318 7F0337E8 C43020DC */  lwc1  $f16, %lo(D_800520DC)($at)
/* 06831C 7F0337EC 46106080 */  add.s $f2, $f12, $f16
.L7F0337F0:
/* 068320 7F0337F0 3C018005 */  lui   $at, %hi(D_800520E0)
/* 068324 7F0337F4 C43220E0 */  lwc1  $f18, %lo(D_800520E0)($at)
/* 068328 7F0337F8 3C018005 */  lui   $at, %hi(D_800520E4)
/* 06832C 7F0337FC 4612103C */  c.lt.s $f2, $f18
/* 068330 7F033800 00000000 */  nop   
/* 068334 7F033804 45010007 */  bc1t  .L7F033824
/* 068338 7F033808 00000000 */   nop   
/* 06833C 7F03380C C42420E4 */  lwc1  $f4, %lo(D_800520E4)($at)
/* 068340 7F033810 00001025 */  move  $v0, $zero
/* 068344 7F033814 4602203C */  c.lt.s $f4, $f2
/* 068348 7F033818 00000000 */  nop   
/* 06834C 7F03381C 45000003 */  bc1f  .L7F03382C
/* 068350 7F033820 00000000 */   nop   
.L7F033824:
/* 068354 7F033824 10000001 */  b     .L7F03382C
/* 068358 7F033828 24020001 */   li    $v0, 1
.L7F03382C:
/* 06835C 7F03382C 03E00008 */  jr    $ra
/* 068360 7F033830 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033834(void) {
// ai branch
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800520E8
.word 0x40490fdb /*3.1415927*/
glabel D_800520EC
.word 0x3fc90fdb /*1.5707964*/
glabel D_800520F0
.word 0x4096cbe4 /*4.712389*/
glabel D_800520F4
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F033834
/* 068364 7F033834 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 068368 7F033838 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 06836C 7F03383C 4486A000 */  mtc1  $a2, $f20
/* 068370 7F033840 AFBF0034 */  sw    $ra, 0x34($sp)
/* 068374 7F033844 AFB40030 */  sw    $s4, 0x30($sp)
/* 068378 7F033848 AFB00020 */  sw    $s0, 0x20($sp)
/* 06837C 7F03384C 30F000FF */  andi  $s0, $a3, 0xff
/* 068380 7F033850 0080A025 */  move  $s4, $a0
/* 068384 7F033854 AFB3002C */  sw    $s3, 0x2c($sp)
/* 068388 7F033858 AFB20028 */  sw    $s2, 0x28($sp)
/* 06838C 7F03385C AFB10024 */  sw    $s1, 0x24($sp)
/* 068390 7F033860 0FC09F35 */  jal   chrlvStanPathRelated
/* 068394 7F033864 AFA70044 */   sw    $a3, 0x44($sp)
/* 068398 7F033868 10400041 */  beqz  $v0, .L7F033970
/* 06839C 7F03386C 00409825 */   move  $s3, $v0
/* 0683A0 7F033870 24010001 */  li    $at, 1
/* 0683A4 7F033874 1201000A */  beq   $s0, $at, .L7F0338A0
/* 0683A8 7F033878 02602025 */   move  $a0, $s3
/* 0683AC 7F03387C 24010002 */  li    $at, 2
/* 0683B0 7F033880 1201000B */  beq   $s0, $at, .L7F0338B0
/* 0683B4 7F033884 24010004 */   li    $at, 4
/* 0683B8 7F033888 1201000D */  beq   $s0, $at, .L7F0338C0
/* 0683BC 7F03388C 24010008 */   li    $at, 8
/* 0683C0 7F033890 1201000E */  beq   $s0, $at, .L7F0338CC
/* 0683C4 7F033894 00000000 */   nop   
/* 0683C8 7F033898 1000000C */  b     .L7F0338CC
/* 0683CC 7F03389C 00000000 */   nop   
.L7F0338A0:
/* 0683D0 7F0338A0 3C018005 */  lui   $at, %hi(D_800520E8)
/* 0683D4 7F0338A4 C42420E8 */  lwc1  $f4, %lo(D_800520E8)($at)
/* 0683D8 7F0338A8 10000008 */  b     .L7F0338CC
/* 0683DC 7F0338AC 4604A500 */   add.s $f20, $f20, $f4
.L7F0338B0:
/* 0683E0 7F0338B0 3C018005 */  lui   $at, %hi(D_800520EC)
/* 0683E4 7F0338B4 C42620EC */  lwc1  $f6, %lo(D_800520EC)($at)
/* 0683E8 7F0338B8 10000004 */  b     .L7F0338CC
/* 0683EC 7F0338BC 4606A500 */   add.s $f20, $f20, $f6
.L7F0338C0:
/* 0683F0 7F0338C0 3C018005 */  lui   $at, %hi(D_800520F0)
/* 0683F4 7F0338C4 C42820F0 */  lwc1  $f8, %lo(D_800520F0)($at)
/* 0683F8 7F0338C8 4608A500 */  add.s $f20, $f20, $f8
.L7F0338CC:
/* 0683FC 7F0338CC 3C018005 */  lui   $at, %hi(D_800520F4)
/* 068400 7F0338D0 C42020F4 */  lwc1  $f0, %lo(D_800520F4)($at)
/* 068404 7F0338D4 4614003E */  c.le.s $f0, $f20
/* 068408 7F0338D8 00000000 */  nop   
/* 06840C 7F0338DC 45020003 */  bc1fl .L7F0338EC
/* 068410 7F0338E0 4406A000 */   mfc1  $a2, $f20
/* 068414 7F0338E4 4600A501 */  sub.s $f20, $f20, $f0
/* 068418 7F0338E8 4406A000 */  mfc1  $a2, $f20
.L7F0338EC:
/* 06841C 7F0338EC 0FC0CDE0 */  jal   sub_GAME_7F033780
/* 068420 7F0338F0 02802825 */   move  $a1, $s4
/* 068424 7F0338F4 50400004 */  beql  $v0, $zero, .L7F033908
/* 068428 7F0338F8 8E6E0004 */   lw    $t6, 4($s3)
/* 06842C 7F0338FC 1000001D */  b     .L7F033974
/* 068430 7F033900 8E620000 */   lw    $v0, ($s3)
/* 068434 7F033904 8E6E0004 */  lw    $t6, 4($s3)
.L7F033908:
/* 068438 7F033908 3C128007 */  lui   $s2, %hi(ptr_setup_path_tbl)
/* 06843C 7F03390C 26525D00 */  addiu $s2, %lo(ptr_setup_path_tbl) # addiu $s2, $s2, 0x5d00
/* 068440 7F033910 8DD10000 */  lw    $s1, ($t6)
/* 068444 7F033914 00008025 */  move  $s0, $zero
/* 068448 7F033918 06220016 */  bltzl $s1, .L7F033974
/* 06844C 7F03391C 2402FFFF */   li    $v0, -1
/* 068450 7F033920 8E580000 */  lw    $t8, ($s2)
.L7F033924:
/* 068454 7F033924 00117900 */  sll   $t7, $s1, 4
/* 068458 7F033928 4406A000 */  mfc1  $a2, $f20
/* 06845C 7F03392C 02802825 */  move  $a1, $s4
/* 068460 7F033930 0FC0CDE0 */  jal   sub_GAME_7F033780
/* 068464 7F033934 01F82021 */   addu  $a0, $t7, $t8
/* 068468 7F033938 50400007 */  beql  $v0, $zero, .L7F033958
/* 06846C 7F03393C 8E6A0004 */   lw    $t2, 4($s3)
/* 068470 7F033940 8E590000 */  lw    $t9, ($s2)
/* 068474 7F033944 00114100 */  sll   $t0, $s1, 4
/* 068478 7F033948 03284821 */  addu  $t1, $t9, $t0
/* 06847C 7F03394C 10000009 */  b     .L7F033974
/* 068480 7F033950 8D220000 */   lw    $v0, ($t1)
/* 068484 7F033954 8E6A0004 */  lw    $t2, 4($s3)
.L7F033958:
/* 068488 7F033958 26100001 */  addiu $s0, $s0, 1
/* 06848C 7F03395C 00105880 */  sll   $t3, $s0, 2
/* 068490 7F033960 014B6021 */  addu  $t4, $t2, $t3
/* 068494 7F033964 8D910000 */  lw    $s1, ($t4)
/* 068498 7F033968 0623FFEE */  bgezl $s1, .L7F033924
/* 06849C 7F03396C 8E580000 */   lw    $t8, ($s2)
.L7F033970:
/* 0684A0 7F033970 2402FFFF */  li    $v0, -1
.L7F033974:
/* 0684A4 7F033974 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0684A8 7F033978 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0684AC 7F03397C 8FB00020 */  lw    $s0, 0x20($sp)
/* 0684B0 7F033980 8FB10024 */  lw    $s1, 0x24($sp)
/* 0684B4 7F033984 8FB20028 */  lw    $s2, 0x28($sp)
/* 0684B8 7F033988 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0684BC 7F03398C 8FB40030 */  lw    $s4, 0x30($sp)
/* 0684C0 7F033990 03E00008 */  jr    $ra
/* 0684C4 7F033994 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif



#ifdef NONMATCHING
void check_2328_preset_set_with_method(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel check_2328_preset_set_with_method
/* 0684C8 7F033998 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0684CC 7F03399C AFB00014 */  sw    $s0, 0x14($sp)
/* 0684D0 7F0339A0 30B000FF */  andi  $s0, $a1, 0xff
/* 0684D4 7F0339A4 AFB10018 */  sw    $s1, 0x18($sp)
/* 0684D8 7F0339A8 24010010 */  li    $at, 16
/* 0684DC 7F0339AC 00808825 */  move  $s1, $a0
/* 0684E0 7F0339B0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0684E4 7F0339B4 AFA5004C */  sw    $a1, 0x4c($sp)
/* 0684E8 7F0339B8 12010004 */  beq   $s0, $at, .L7F0339CC
/* 0684EC 7F0339BC 02003025 */   move  $a2, $s0
/* 0684F0 7F0339C0 24010020 */  li    $at, 32
/* 0684F4 7F0339C4 16010026 */  bne   $s0, $at, .L7F033A60
/* 0684F8 7F0339C8 00000000 */   nop   
.L7F0339CC:
/* 0684FC 7F0339CC 8E300018 */  lw    $s0, 0x18($s1)
/* 068500 7F0339D0 0FC225E6 */  jal   get_curplayer_positiondata
/* 068504 7F0339D4 AFA60020 */   sw    $a2, 0x20($sp)
/* 068508 7F0339D8 8E050014 */  lw    $a1, 0x14($s0)
/* 06850C 7F0339DC AFA20040 */  sw    $v0, 0x40($sp)
/* 068510 7F0339E0 0FC09F35 */  jal   chrlvStanPathRelated
/* 068514 7F0339E4 26040008 */   addiu $a0, $s0, 8
/* 068518 7F0339E8 8FA30040 */  lw    $v1, 0x40($sp)
/* 06851C 7F0339EC 00408025 */  move  $s0, $v0
/* 068520 7F0339F0 24640008 */  addiu $a0, $v1, 8
/* 068524 7F0339F4 0FC09F35 */  jal   chrlvStanPathRelated
/* 068528 7F0339F8 8C650014 */   lw    $a1, 0x14($v1)
/* 06852C 7F0339FC 8FA60020 */  lw    $a2, 0x20($sp)
/* 068530 7F033A00 12000024 */  beqz  $s0, .L7F033A94
/* 068534 7F033A04 00402825 */   move  $a1, $v0
/* 068538 7F033A08 10400022 */  beqz  $v0, .L7F033A94
/* 06853C 7F033A0C 24010010 */   li    $at, 16
/* 068540 7F033A10 14C1000B */  bne   $a2, $at, .L7F033A40
/* 068544 7F033A14 02002025 */   move  $a0, $s0
/* 068548 7F033A18 27A6002C */  addiu $a2, $sp, 0x2c
/* 06854C 7F033A1C 0FC23D3C */  jal   sub_GAME_7F08F4F0
/* 068550 7F033A20 24070003 */   li    $a3, 3
/* 068554 7F033A24 28410003 */  slti  $at, $v0, 3
/* 068558 7F033A28 1420001A */  bnez  $at, .L7F033A94
/* 06855C 7F033A2C 8FAE0030 */   lw    $t6, 0x30($sp)
/* 068560 7F033A30 8DCF0000 */  lw    $t7, ($t6)
/* 068564 7F033A34 24020001 */  li    $v0, 1
/* 068568 7F033A38 10000017 */  b     .L7F033A98
/* 06856C 7F033A3C A62F0114 */   sh    $t7, 0x114($s1)
.L7F033A40:
/* 068570 7F033A40 0FC23EE4 */  jal   sub_GAME_7F08FB90
/* 068574 7F033A44 02002025 */   move  $a0, $s0
/* 068578 7F033A48 50400013 */  beql  $v0, $zero, .L7F033A98
/* 06857C 7F033A4C 00001025 */   move  $v0, $zero
/* 068580 7F033A50 8C580000 */  lw    $t8, ($v0)
/* 068584 7F033A54 24020001 */  li    $v0, 1
/* 068588 7F033A58 1000000F */  b     .L7F033A98
/* 06858C 7F033A5C A6380114 */   sh    $t8, 0x114($s1)
.L7F033A60:
/* 068590 7F033A60 0FC1B320 */  jal   getsubroty
/* 068594 7F033A64 8E24001C */   lw    $a0, 0x1c($s1)
/* 068598 7F033A68 8E220018 */  lw    $v0, 0x18($s1)
/* 06859C 7F033A6C 44060000 */  mfc1  $a2, $f0
/* 0685A0 7F033A70 320700FF */  andi  $a3, $s0, 0xff
/* 0685A4 7F033A74 24440008 */  addiu $a0, $v0, 8
/* 0685A8 7F033A78 0FC0CE0D */  jal   sub_GAME_7F033834
/* 0685AC 7F033A7C 8C450014 */   lw    $a1, 0x14($v0)
/* 0685B0 7F033A80 04420005 */  bltzl $v0, .L7F033A98
/* 0685B4 7F033A84 00001025 */   move  $v0, $zero
/* 0685B8 7F033A88 A6220114 */  sh    $v0, 0x114($s1)
/* 0685BC 7F033A8C 10000002 */  b     .L7F033A98
/* 0685C0 7F033A90 24020001 */   li    $v0, 1
.L7F033A94:
/* 0685C4 7F033A94 00001025 */  move  $v0, $zero
.L7F033A98:
/* 0685C8 7F033A98 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0685CC 7F033A9C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0685D0 7F033AA0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0685D4 7F033AA4 03E00008 */  jr    $ra
/* 0685D8 7F033AA8 27BD0048 */   addiu $sp, $sp, 0x48
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033AAC(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033AAC
/* 0685DC 7F033AAC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0685E0 7F033AB0 30A700FF */  andi  $a3, $a1, 0xff
/* 0685E4 7F033AB4 24010010 */  li    $at, 16
/* 0685E8 7F033AB8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0685EC 7F033ABC AFA40020 */  sw    $a0, 0x20($sp)
/* 0685F0 7F033AC0 AFA50024 */  sw    $a1, 0x24($sp)
/* 0685F4 7F033AC4 10E10004 */  beq   $a3, $at, .L7F033AD8
/* 0685F8 7F033AC8 00E01025 */   move  $v0, $a3
/* 0685FC 7F033ACC 24010020 */  li    $at, 32
/* 068600 7F033AD0 14410006 */  bne   $v0, $at, .L7F033AEC
/* 068604 7F033AD4 00000000 */   nop   
.L7F033AD8:
/* 068608 7F033AD8 8FA40020 */  lw    $a0, 0x20($sp)
/* 06860C 7F033ADC 0FC0CE66 */  jal   check_2328_preset_set_with_method
/* 068610 7F033AE0 30E500FF */   andi  $a1, $a3, 0xff
/* 068614 7F033AE4 10000011 */  b     .L7F033B2C
/* 068618 7F033AE8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F033AEC:
/* 06861C 7F033AEC 0FC227B9 */  jal   get_curplay_horizontal_rotation_in_degrees
/* 068620 7F033AF0 A3A70027 */   sb    $a3, 0x27($sp)
/* 068624 7F033AF4 0FC225E6 */  jal   get_curplayer_positiondata
/* 068628 7F033AF8 E7A0001C */   swc1  $f0, 0x1c($sp)
/* 06862C 7F033AFC 93A70027 */  lbu   $a3, 0x27($sp)
/* 068630 7F033B00 24440008 */  addiu $a0, $v0, 8
/* 068634 7F033B04 8C450014 */  lw    $a1, 0x14($v0)
/* 068638 7F033B08 0FC0CE0D */  jal   sub_GAME_7F033834
/* 06863C 7F033B0C 8FA6001C */   lw    $a2, 0x1c($sp)
/* 068640 7F033B10 04400004 */  bltz  $v0, .L7F033B24
/* 068644 7F033B14 8FAE0020 */   lw    $t6, 0x20($sp)
/* 068648 7F033B18 A5C20114 */  sh    $v0, 0x114($t6)
/* 06864C 7F033B1C 10000002 */  b     .L7F033B28
/* 068650 7F033B20 24020001 */   li    $v0, 1
.L7F033B24:
/* 068654 7F033B24 00001025 */  move  $v0, $zero
.L7F033B28:
/* 068658 7F033B28 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F033B2C:
/* 06865C 7F033B2C 27BD0020 */  addiu $sp, $sp, 0x20
/* 068660 7F033B30 03E00008 */  jr    $ra
/* 068664 7F033B34 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033B38(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033B38
/* 068668 7F033B38 27BDFF98 */  addiu $sp, $sp, -0x68
/* 06866C 7F033B3C 44856000 */  mtc1  $a1, $f12
/* 068670 7F033B40 AFBF0064 */  sw    $ra, 0x64($sp)
/* 068674 7F033B44 AFB5005C */  sw    $s5, 0x5c($sp)
/* 068678 7F033B48 0080A825 */  move  $s5, $a0
/* 06867C 7F033B4C AFB60060 */  sw    $s6, 0x60($sp)
/* 068680 7F033B50 AFB40058 */  sw    $s4, 0x58($sp)
/* 068684 7F033B54 AFB30054 */  sw    $s3, 0x54($sp)
/* 068688 7F033B58 AFB20050 */  sw    $s2, 0x50($sp)
/* 06868C 7F033B5C AFB1004C */  sw    $s1, 0x4c($sp)
/* 068690 7F033B60 AFB00048 */  sw    $s0, 0x48($sp)
/* 068694 7F033B64 F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 068698 7F033B68 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 06869C 7F033B6C F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0686A0 7F033B70 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0686A4 7F033B74 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0686A8 7F033B78 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0686AC 7F033B7C 0FC07D4C */  jal   get_numguards
/* 0686B0 7F033B80 E7AC006C */   swc1  $f12, 0x6c($sp)
/* 0686B4 7F033B84 8EA30018 */  lw    $v1, 0x18($s5)
/* 0686B8 7F033B88 C7AC006C */  lwc1  $f12, 0x6c($sp)
/* 0686BC 7F033B8C 0040A025 */  move  $s4, $v0
/* 0686C0 7F033B90 C4600008 */  lwc1  $f0, 8($v1)
/* 0686C4 7F033B94 C462000C */  lwc1  $f2, 0xc($v1)
/* 0686C8 7F033B98 C46E0010 */  lwc1  $f14, 0x10($v1)
/* 0686CC 7F033B9C 8C6E0014 */  lw    $t6, 0x14($v1)
/* 0686D0 7F033BA0 00008825 */  move  $s1, $zero
/* 0686D4 7F033BA4 460C0501 */  sub.s $f20, $f0, $f12
/* 0686D8 7F033BA8 91D30003 */  lbu   $s3, 3($t6)
/* 0686DC 7F033BAC 460C0580 */  add.s $f22, $f0, $f12
/* 0686E0 7F033BB0 460C1601 */  sub.s $f24, $f2, $f12
/* 0686E4 7F033BB4 460C1680 */  add.s $f26, $f2, $f12
/* 0686E8 7F033BB8 460C7701 */  sub.s $f28, $f14, $f12
/* 0686EC 7F033BBC 1840003C */  blez  $v0, .L7F033CB0
/* 0686F0 7F033BC0 460C7780 */   add.s $f30, $f14, $f12
/* 0686F4 7F033BC4 3C168003 */  lui   $s6, %hi(ptr_guard_data)
/* 0686F8 7F033BC8 26D6CC64 */  addiu $s6, %lo(ptr_guard_data) # addiu $s6, $s6, -0x339c
/* 0686FC 7F033BCC 00009025 */  move  $s2, $zero
.L7F033BD0:
/* 068700 7F033BD0 8ECF0000 */  lw    $t7, ($s6)
/* 068704 7F033BD4 024F8021 */  addu  $s0, $s2, $t7
/* 068708 7F033BD8 52150032 */  beql  $s0, $s5, .L7F033CA4
/* 06870C 7F033BDC 26310001 */   addiu $s1, $s1, 1
/* 068710 7F033BE0 8E18001C */  lw    $t8, 0x1c($s0)
/* 068714 7F033BE4 5300002F */  beql  $t8, $zero, .L7F033CA4
/* 068718 7F033BE8 26310001 */   addiu $s1, $s1, 1
/* 06871C 7F033BEC 0FC0A8A9 */  jal   chrIsDead
/* 068720 7F033BF0 02002025 */   move  $a0, $s0
/* 068724 7F033BF4 5440002B */  bnezl $v0, .L7F033CA4
/* 068728 7F033BF8 26310001 */   addiu $s1, $s1, 1
/* 06872C 7F033BFC 8E030018 */  lw    $v1, 0x18($s0)
/* 068730 7F033C00 24620008 */  addiu $v0, $v1, 8
/* 068734 7F033C04 C4400000 */  lwc1  $f0, ($v0)
/* 068738 7F033C08 4600A03E */  c.le.s $f20, $f0
/* 06873C 7F033C0C 00000000 */  nop   
/* 068740 7F033C10 45020024 */  bc1fl .L7F033CA4
/* 068744 7F033C14 26310001 */   addiu $s1, $s1, 1
/* 068748 7F033C18 4616003E */  c.le.s $f0, $f22
/* 06874C 7F033C1C 00000000 */  nop   
/* 068750 7F033C20 45020020 */  bc1fl .L7F033CA4
/* 068754 7F033C24 26310001 */   addiu $s1, $s1, 1
/* 068758 7F033C28 C4400004 */  lwc1  $f0, 4($v0)
/* 06875C 7F033C2C 4600C03E */  c.le.s $f24, $f0
/* 068760 7F033C30 00000000 */  nop   
/* 068764 7F033C34 4502001B */  bc1fl .L7F033CA4
/* 068768 7F033C38 26310001 */   addiu $s1, $s1, 1
/* 06876C 7F033C3C 461A003E */  c.le.s $f0, $f26
/* 068770 7F033C40 00000000 */  nop   
/* 068774 7F033C44 45020017 */  bc1fl .L7F033CA4
/* 068778 7F033C48 26310001 */   addiu $s1, $s1, 1
/* 06877C 7F033C4C C4400008 */  lwc1  $f0, 8($v0)
/* 068780 7F033C50 4600E03E */  c.le.s $f28, $f0
/* 068784 7F033C54 00000000 */  nop   
/* 068788 7F033C58 45020012 */  bc1fl .L7F033CA4
/* 06878C 7F033C5C 26310001 */   addiu $s1, $s1, 1
/* 068790 7F033C60 461E003E */  c.le.s $f0, $f30
/* 068794 7F033C64 00000000 */  nop   
/* 068798 7F033C68 4502000E */  bc1fl .L7F033CA4
/* 06879C 7F033C6C 26310001 */   addiu $s1, $s1, 1
/* 0687A0 7F033C70 8C790014 */  lw    $t9, 0x14($v1)
/* 0687A4 7F033C74 93250003 */  lbu   $a1, 3($t9)
/* 0687A8 7F033C78 52650006 */  beql  $s3, $a1, .L7F033C94
/* 0687AC 7F033C7C 86080000 */   lh    $t0, ($s0)
/* 0687B0 7F033C80 0FC2E3F4 */  jal   sub_GAME_7F0B8FD0
/* 0687B4 7F033C84 02602025 */   move  $a0, $s3
/* 0687B8 7F033C88 50400006 */  beql  $v0, $zero, .L7F033CA4
/* 0687BC 7F033C8C 26310001 */   addiu $s1, $s1, 1
/* 0687C0 7F033C90 86080000 */  lh    $t0, ($s0)
.L7F033C94:
/* 0687C4 7F033C94 24020001 */  li    $v0, 1
/* 0687C8 7F033C98 10000006 */  b     .L7F033CB4
/* 0687CC 7F033C9C A6A80116 */   sh    $t0, 0x116($s5)
/* 0687D0 7F033CA0 26310001 */  addiu $s1, $s1, 1
.L7F033CA4:
/* 0687D4 7F033CA4 0234082A */  slt   $at, $s1, $s4
/* 0687D8 7F033CA8 1420FFC9 */  bnez  $at, .L7F033BD0
/* 0687DC 7F033CAC 265201DC */   addiu $s2, $s2, 0x1dc
.L7F033CB0:
/* 0687E0 7F033CB0 00001025 */  move  $v0, $zero
.L7F033CB4:
/* 0687E4 7F033CB4 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0687E8 7F033CB8 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0687EC 7F033CBC D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0687F0 7F033CC0 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0687F4 7F033CC4 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0687F8 7F033CC8 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0687FC 7F033CCC D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 068800 7F033CD0 8FB00048 */  lw    $s0, 0x48($sp)
/* 068804 7F033CD4 8FB1004C */  lw    $s1, 0x4c($sp)
/* 068808 7F033CD8 8FB20050 */  lw    $s2, 0x50($sp)
/* 06880C 7F033CDC 8FB30054 */  lw    $s3, 0x54($sp)
/* 068810 7F033CE0 8FB40058 */  lw    $s4, 0x58($sp)
/* 068814 7F033CE4 8FB5005C */  lw    $s5, 0x5c($sp)
/* 068818 7F033CE8 8FB60060 */  lw    $s6, 0x60($sp)
/* 06881C 7F033CEC 03E00008 */  jr    $ra
/* 068820 7F033CF0 27BD0068 */   addiu $sp, $sp, 0x68
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033CF4(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033CF4
/* 068824 7F033CF4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 068828 7F033CF8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 06882C 7F033CFC 0FC0CBEB */  jal   sub_GAME_7F032FAC
/* 068830 7F033D00 AFA40018 */   sw    $a0, 0x18($sp)
/* 068834 7F033D04 8FAE0018 */  lw    $t6, 0x18($sp)
/* 068838 7F033D08 A5C20116 */  sh    $v0, 0x116($t6)
/* 06883C 7F033D0C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 068840 7F033D10 27BD0018 */  addiu $sp, $sp, 0x18
/* 068844 7F033D14 03E00008 */  jr    $ra
/* 068848 7F033D18 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033D1C(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033D1C
/* 06884C 7F033D1C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 068850 7F033D20 AFBF0014 */  sw    $ra, 0x14($sp)
/* 068854 7F033D24 AFA40020 */  sw    $a0, 0x20($sp)
/* 068858 7F033D28 0FC0CC10 */  jal   get_handle_for_guard_id
/* 06885C 7F033D2C AFA60028 */   sw    $a2, 0x28($sp)
/* 068860 7F033D30 10400006 */  beqz  $v0, .L7F033D4C
/* 068864 7F033D34 8FA40020 */   lw    $a0, 0x20($sp)
/* 068868 7F033D38 8FA50028 */  lw    $a1, 0x28($sp)
/* 06886C 7F033D3C 0FC0CBEB */  jal   sub_GAME_7F032FAC
/* 068870 7F033D40 AFA2001C */   sw    $v0, 0x1c($sp)
/* 068874 7F033D44 8FA3001C */  lw    $v1, 0x1c($sp)
/* 068878 7F033D48 A4620116 */  sh    $v0, 0x116($v1)
.L7F033D4C:
/* 06887C 7F033D4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 068880 7F033D50 27BD0020 */  addiu $sp, $sp, 0x20
/* 068884 7F033D54 03E00008 */  jr    $ra
/* 068888 7F033D58 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033D5C(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033D5C
/* 06888C 7F033D5C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 068890 7F033D60 AFBF0014 */  sw    $ra, 0x14($sp)
/* 068894 7F033D64 0FC0CBE5 */  jal   convertPadIf9000
/* 068898 7F033D68 AFA40018 */   sw    $a0, 0x18($sp)
/* 06889C 7F033D6C 8FAE0018 */  lw    $t6, 0x18($sp)
/* 0688A0 7F033D70 A5C20114 */  sh    $v0, 0x114($t6)
/* 0688A4 7F033D74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0688A8 7F033D78 27BD0018 */  addiu $sp, $sp, 0x18
/* 0688AC 7F033D7C 03E00008 */  jr    $ra
/* 0688B0 7F033D80 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033D84(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033D84
/* 0688B4 7F033D84 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0688B8 7F033D88 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0688BC 7F033D8C AFA40020 */  sw    $a0, 0x20($sp)
/* 0688C0 7F033D90 0FC0CC10 */  jal   get_handle_for_guard_id
/* 0688C4 7F033D94 AFA60028 */   sw    $a2, 0x28($sp)
/* 0688C8 7F033D98 10400006 */  beqz  $v0, .L7F033DB4
/* 0688CC 7F033D9C 8FA40020 */   lw    $a0, 0x20($sp)
/* 0688D0 7F033DA0 8FA50028 */  lw    $a1, 0x28($sp)
/* 0688D4 7F033DA4 0FC0CBE5 */  jal   convertPadIf9000
/* 0688D8 7F033DA8 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0688DC 7F033DAC 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0688E0 7F033DB0 A4620114 */  sh    $v0, 0x114($v1)
.L7F033DB4:
/* 0688E4 7F033DB4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0688E8 7F033DB8 27BD0020 */  addiu $sp, $sp, 0x20
/* 0688EC 7F033DBC 03E00008 */  jr    $ra
/* 0688F0 7F033DC0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033DC4(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033DC4
/* 0688F4 7F033DC4 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0688F8 7F033DC8 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0688FC 7F033DCC AFB10028 */  sw    $s1, 0x28($sp)
/* 068900 7F033DD0 AFB00024 */  sw    $s0, 0x24($sp)
/* 068904 7F033DD4 0FC225E6 */  jal   get_curplayer_positiondata
/* 068908 7F033DD8 AFA40060 */   sw    $a0, 0x60($sp)
/* 06890C 7F033DDC 8FAE0060 */  lw    $t6, 0x60($sp)
/* 068910 7F033DE0 00408825 */  move  $s1, $v0
/* 068914 7F033DE4 8DD00018 */  lw    $s0, 0x18($t6)
/* 068918 7F033DE8 8E0F0014 */  lw    $t7, 0x14($s0)
/* 06891C 7F033DEC 0FC2C731 */  jal   sub_GAME_7F0B1CC4
/* 068920 7F033DF0 AFAF0054 */   sw    $t7, 0x54($sp)
/* 068924 7F033DF4 C6240010 */  lwc1  $f4, 0x10($s1)
/* 068928 7F033DF8 8E050008 */  lw    $a1, 8($s0)
/* 06892C 7F033DFC 8E060010 */  lw    $a2, 0x10($s0)
/* 068930 7F033E00 8E270008 */  lw    $a3, 8($s1)
/* 068934 7F033E04 27A40054 */  addiu $a0, $sp, 0x54
/* 068938 7F033E08 0FC2C2F9 */  jal   walkTilesBetweenPoints_NoCallback
/* 06893C 7F033E0C E7A40010 */   swc1  $f4, 0x10($sp)
/* 068940 7F033E10 10400003 */  beqz  $v0, .L7F033E20
/* 068944 7F033E14 27A40048 */   addiu $a0, $sp, 0x48
/* 068948 7F033E18 1000001F */  b     .L7F033E98
/* 06894C 7F033E1C 00001025 */   move  $v0, $zero
.L7F033E20:
/* 068950 7F033E20 0FC2CA2C */  jal   getCollisionEdge_maybe
/* 068954 7F033E24 27A5003C */   addiu $a1, $sp, 0x3c
/* 068958 7F033E28 8E060014 */  lw    $a2, 0x14($s0)
/* 06895C 7F033E2C 26230008 */  addiu $v1, $s1, 8
/* 068960 7F033E30 AFA30010 */  sw    $v1, 0x10($sp)
/* 068964 7F033E34 8E380014 */  lw    $t8, 0x14($s1)
/* 068968 7F033E38 26050008 */  addiu $a1, $s0, 8
/* 06896C 7F033E3C AFA50038 */  sw    $a1, 0x38($sp)
/* 068970 7F033E40 AFA30034 */  sw    $v1, 0x34($sp)
/* 068974 7F033E44 AFA00018 */  sw    $zero, 0x18($sp)
/* 068978 7F033E48 8FA40060 */  lw    $a0, 0x60($sp)
/* 06897C 7F033E4C 27A70048 */  addiu $a3, $sp, 0x48
/* 068980 7F033E50 0FC0C12B */  jal   sub_GAME_7F0304AC
/* 068984 7F033E54 AFB80014 */   sw    $t8, 0x14($sp)
/* 068988 7F033E58 8FA30034 */  lw    $v1, 0x34($sp)
/* 06898C 7F033E5C 1440000B */  bnez  $v0, .L7F033E8C
/* 068990 7F033E60 8FA50038 */   lw    $a1, 0x38($sp)
/* 068994 7F033E64 8E060014 */  lw    $a2, 0x14($s0)
/* 068998 7F033E68 AFA30010 */  sw    $v1, 0x10($sp)
/* 06899C 7F033E6C 8E390014 */  lw    $t9, 0x14($s1)
/* 0689A0 7F033E70 AFA00018 */  sw    $zero, 0x18($sp)
/* 0689A4 7F033E74 8FA40060 */  lw    $a0, 0x60($sp)
/* 0689A8 7F033E78 27A7003C */  addiu $a3, $sp, 0x3c
/* 0689AC 7F033E7C 0FC0C12B */  jal   sub_GAME_7F0304AC
/* 0689B0 7F033E80 AFB90014 */   sw    $t9, 0x14($sp)
/* 0689B4 7F033E84 50400004 */  beql  $v0, $zero, .L7F033E98
/* 0689B8 7F033E88 00001025 */   move  $v0, $zero
.L7F033E8C:
/* 0689BC 7F033E8C 10000002 */  b     .L7F033E98
/* 0689C0 7F033E90 24020001 */   li    $v0, 1
/* 0689C4 7F033E94 00001025 */  move  $v0, $zero
.L7F033E98:
/* 0689C8 7F033E98 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0689CC 7F033E9C 8FB00024 */  lw    $s0, 0x24($sp)
/* 0689D0 7F033EA0 8FB10028 */  lw    $s1, 0x28($sp)
/* 0689D4 7F033EA4 03E00008 */  jr    $ra
/* 0689D8 7F033EA8 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033EAC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F033EAC
/* 0689DC 7F033EAC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0689E0 7F033EB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0689E4 7F033EB4 AFA40030 */  sw    $a0, 0x30($sp)
/* 0689E8 7F033EB8 240E0001 */  li    $t6, 1
/* 0689EC 7F033EBC AFA50034 */  sw    $a1, 0x34($sp)
/* 0689F0 7F033EC0 AFAE002C */  sw    $t6, 0x2c($sp)
/* 0689F4 7F033EC4 0FC2CBF6 */  jal   getTileRoom
/* 0689F8 7F033EC8 00A02025 */   move  $a0, $a1
/* 0689FC 7F033ECC 0FC2D794 */  jal   getROOMID_Bitflags
/* 068A00 7F033ED0 00402025 */   move  $a0, $v0
/* 068A04 7F033ED4 10400017 */  beqz  $v0, .L7F033F34
/* 068A08 7F033ED8 8FA40030 */   lw    $a0, 0x30($sp)
/* 068A0C 7F033EDC 0FC2ECB2 */  jal   sub_GAME_7F0BB2C8
/* 068A10 7F033EE0 24050000 */   li    $a1, 0
/* 068A14 7F033EE4 50400014 */  beql  $v0, $zero, .L7F033F38
/* 068A18 7F033EE8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 068A1C 7F033EEC 0FC2CBF6 */  jal   getTileRoom
/* 068A20 7F033EF0 8FA40034 */   lw    $a0, 0x34($sp)
/* 068A24 7F033EF4 00402025 */  move  $a0, $v0
/* 068A28 7F033EF8 0FC2CF03 */  jal   sub_GAME_7F0B3C0C
/* 068A2C 7F033EFC 27A5001C */   addiu $a1, $sp, 0x1c
/* 068A30 7F033F00 10400008 */  beqz  $v0, .L7F033F24
/* 068A34 7F033F04 8FA40030 */   lw    $a0, 0x30($sp)
/* 068A38 7F033F08 8FA40030 */  lw    $a0, 0x30($sp)
/* 068A3C 7F033F0C 3C054348 */  lui   $a1, 0x4348
/* 068A40 7F033F10 0FC1E2FD */  jal   sub_GAME_7F078BF4
/* 068A44 7F033F14 27A6001C */   addiu $a2, $sp, 0x1c
/* 068A48 7F033F18 2C4F0001 */  sltiu $t7, $v0, 1
/* 068A4C 7F033F1C 10000005 */  b     .L7F033F34
/* 068A50 7F033F20 AFAF002C */   sw    $t7, 0x2c($sp)
.L7F033F24:
/* 068A54 7F033F24 0FC1E296 */  jal   sub_GAME_7F078A58
/* 068A58 7F033F28 3C054348 */   lui   $a1, 0x4348
/* 068A5C 7F033F2C 2C580001 */  sltiu $t8, $v0, 1
/* 068A60 7F033F30 AFB8002C */  sw    $t8, 0x2c($sp)
.L7F033F34:
/* 068A64 7F033F34 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F033F38:
/* 068A68 7F033F38 8FA2002C */  lw    $v0, 0x2c($sp)
/* 068A6C 7F033F3C 27BD0030 */  addiu $sp, $sp, 0x30
/* 068A70 7F033F40 03E00008 */  jr    $ra
/* 068A74 7F033F44 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F033F48(void) {
// ai branch
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800520F8
.word 0x3f490fdb /*0.78539819*/
glabel D_800520FC
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F033F48
/* 068A78 7F033F48 27BDFF68 */  addiu $sp, $sp, -0x98
/* 068A7C 7F033F4C AFBF007C */  sw    $ra, 0x7c($sp)
/* 068A80 7F033F50 AFB60078 */  sw    $s6, 0x78($sp)
/* 068A84 7F033F54 AFB50074 */  sw    $s5, 0x74($sp)
/* 068A88 7F033F58 AFB40070 */  sw    $s4, 0x70($sp)
/* 068A8C 7F033F5C AFB3006C */  sw    $s3, 0x6c($sp)
/* 068A90 7F033F60 AFB20068 */  sw    $s2, 0x68($sp)
/* 068A94 7F033F64 AFB10064 */  sw    $s1, 0x64($sp)
/* 068A98 7F033F68 AFB00060 */  sw    $s0, 0x60($sp)
/* 068A9C 7F033F6C F7BE0058 */  sdc1  $f30, 0x58($sp)
/* 068AA0 7F033F70 F7BC0050 */  sdc1  $f28, 0x50($sp)
/* 068AA4 7F033F74 F7BA0048 */  sdc1  $f26, 0x48($sp)
/* 068AA8 7F033F78 F7B80040 */  sdc1  $f24, 0x40($sp)
/* 068AAC 7F033F7C F7B60038 */  sdc1  $f22, 0x38($sp)
/* 068AB0 7F033F80 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 068AB4 7F033F84 8CAE0000 */  lw    $t6, ($a1)
/* 068AB8 7F033F88 00808025 */  move  $s0, $a0
/* 068ABC 7F033F8C 4486A000 */  mtc1  $a2, $f20
/* 068AC0 7F033F90 AFAE0088 */  sw    $t6, 0x88($sp)
/* 068AC4 7F033F94 00A0A825 */  move  $s5, $a1
/* 068AC8 7F033F98 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 068ACC 7F033F9C 4481C000 */  mtc1  $at, $f24
/* 068AD0 7F033FA0 4480B000 */  mtc1  $zero, $f22
/* 068AD4 7F033FA4 8E050000 */  lw    $a1, ($s0)
/* 068AD8 7F033FA8 8E060008 */  lw    $a2, 8($s0)
/* 068ADC 7F033FAC 27B20088 */  addiu $s2, $sp, 0x88
/* 068AE0 7F033FB0 00E0B025 */  move  $s6, $a3
/* 068AE4 7F033FB4 240F001F */  li    $t7, 31
/* 068AE8 7F033FB8 AFAF0010 */  sw    $t7, 0x10($sp)
/* 068AEC 7F033FBC 3C0741A0 */  lui   $a3, 0x41a0
/* 068AF0 7F033FC0 02402025 */  move  $a0, $s2
/* 068AF4 7F033FC4 E7B80018 */  swc1  $f24, 0x18($sp)
/* 068AF8 7F033FC8 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 068AFC 7F033FCC E7B60014 */   swc1  $f22, 0x14($sp)
/* 068B00 7F033FD0 04410009 */  bgez  $v0, .L7F033FF8
/* 068B04 7F033FD4 00000000 */   nop   
/* 068B08 7F033FD8 16C00005 */  bnez  $s6, .L7F033FF0
/* 068B0C 7F033FDC 02002025 */   move  $a0, $s0
/* 068B10 7F033FE0 0FC0CFAB */  jal   sub_GAME_7F033EAC
/* 068B14 7F033FE4 8EA50000 */   lw    $a1, ($s5)
/* 068B18 7F033FE8 10400003 */  beqz  $v0, .L7F033FF8
/* 068B1C 7F033FEC 00000000 */   nop   
.L7F033FF0:
/* 068B20 7F033FF0 1000004A */  b     .L7F03411C
/* 068B24 7F033FF4 24020001 */   li    $v0, 1
.L7F033FF8:
/* 068B28 7F033FF8 3C018005 */  lui   $at, %hi(D_800520F8)
/* 068B2C 7F033FFC C43E20F8 */  lwc1  $f30, %lo(D_800520F8)($at)
/* 068B30 7F034000 3C018005 */  lui   $at, %hi(D_800520FC)
/* 068B34 7F034004 C43C20FC */  lwc1  $f28, %lo(D_800520FC)($at)
/* 068B38 7F034008 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 068B3C 7F03400C 4481D000 */  mtc1  $at, $f26
/* 068B40 7F034010 00008825 */  move  $s1, $zero
/* 068B44 7F034014 24140008 */  li    $s4, 8
/* 068B48 7F034018 27B3008C */  addiu $s3, $sp, 0x8c
.L7F03401C:
/* 068B4C 7F03401C 0FC15FAB */  jal   sinf
/* 068B50 7F034020 4600A306 */   mov.s $f12, $f20
/* 068B54 7F034024 461A0102 */  mul.s $f4, $f0, $f26
/* 068B58 7F034028 C6060000 */  lwc1  $f6, ($s0)
/* 068B5C 7F03402C 4600A306 */  mov.s $f12, $f20
/* 068B60 7F034030 46062200 */  add.s $f8, $f4, $f6
/* 068B64 7F034034 E7A8008C */  swc1  $f8, 0x8c($sp)
/* 068B68 7F034038 C60A0004 */  lwc1  $f10, 4($s0)
/* 068B6C 7F03403C 0FC15FA8 */  jal   cosf
/* 068B70 7F034040 E7AA0090 */   swc1  $f10, 0x90($sp)
/* 068B74 7F034044 461A0402 */  mul.s $f16, $f0, $f26
/* 068B78 7F034048 C6120008 */  lwc1  $f18, 8($s0)
/* 068B7C 7F03404C 24190013 */  li    $t9, 19
/* 068B80 7F034050 02402025 */  move  $a0, $s2
/* 068B84 7F034054 8FA7008C */  lw    $a3, 0x8c($sp)
/* 068B88 7F034058 46128100 */  add.s $f4, $f16, $f18
/* 068B8C 7F03405C E7A40094 */  swc1  $f4, 0x94($sp)
/* 068B90 7F034060 8EB80000 */  lw    $t8, ($s5)
/* 068B94 7F034064 AFB80088 */  sw    $t8, 0x88($sp)
/* 068B98 7F034068 8E060008 */  lw    $a2, 8($s0)
/* 068B9C 7F03406C 8E050000 */  lw    $a1, ($s0)
/* 068BA0 7F034070 E7B80024 */  swc1  $f24, 0x24($sp)
/* 068BA4 7F034074 E7B60020 */  swc1  $f22, 0x20($sp)
/* 068BA8 7F034078 E7B8001C */  swc1  $f24, 0x1c($sp)
/* 068BAC 7F03407C E7B60018 */  swc1  $f22, 0x18($sp)
/* 068BB0 7F034080 AFB90014 */  sw    $t9, 0x14($sp)
/* 068BB4 7F034084 0FC2C389 */  jal   sub_GAME_7F0B0E24
/* 068BB8 7F034088 E7A40010 */   swc1  $f4, 0x10($sp)
/* 068BBC 7F03408C 10400019 */  beqz  $v0, .L7F0340F4
/* 068BC0 7F034090 02402025 */   move  $a0, $s2
/* 068BC4 7F034094 2408001F */  li    $t0, 31
/* 068BC8 7F034098 AFA80010 */  sw    $t0, 0x10($sp)
/* 068BCC 7F03409C 8FA5008C */  lw    $a1, 0x8c($sp)
/* 068BD0 7F0340A0 8FA60094 */  lw    $a2, 0x94($sp)
/* 068BD4 7F0340A4 3C0741A0 */  lui   $a3, 0x41a0
/* 068BD8 7F0340A8 E7B60014 */  swc1  $f22, 0x14($sp)
/* 068BDC 7F0340AC 0FC2C62E */  jal   sub_GAME_7F0B18B8
/* 068BE0 7F0340B0 E7B80018 */   swc1  $f24, 0x18($sp)
/* 068BE4 7F0340B4 0441000F */  bgez  $v0, .L7F0340F4
/* 068BE8 7F0340B8 02602025 */   move  $a0, $s3
/* 068BEC 7F0340BC 56C00006 */  bnezl $s6, .L7F0340D8
/* 068BF0 7F0340C0 8FA90088 */   lw    $t1, 0x88($sp)
/* 068BF4 7F0340C4 0FC0CFAB */  jal   sub_GAME_7F033EAC
/* 068BF8 7F0340C8 8FA50088 */   lw    $a1, 0x88($sp)
/* 068BFC 7F0340CC 5040000A */  beql  $v0, $zero, .L7F0340F8
/* 068C00 7F0340D0 461EA500 */   add.s $f20, $f20, $f30
/* 068C04 7F0340D4 8FA90088 */  lw    $t1, 0x88($sp)
.L7F0340D8:
/* 068C08 7F0340D8 24020001 */  li    $v0, 1
/* 068C0C 7F0340DC AEA90000 */  sw    $t1, ($s5)
/* 068C10 7F0340E0 C7A6008C */  lwc1  $f6, 0x8c($sp)
/* 068C14 7F0340E4 E6060000 */  swc1  $f6, ($s0)
/* 068C18 7F0340E8 C7A80094 */  lwc1  $f8, 0x94($sp)
/* 068C1C 7F0340EC 1000000B */  b     .L7F03411C
/* 068C20 7F0340F0 E6080008 */   swc1  $f8, 8($s0)
.L7F0340F4:
/* 068C24 7F0340F4 461EA500 */  add.s $f20, $f20, $f30
.L7F0340F8:
/* 068C28 7F0340F8 26310001 */  addiu $s1, $s1, 1
/* 068C2C 7F0340FC 4614E03E */  c.le.s $f28, $f20
/* 068C30 7F034100 00000000 */  nop   
/* 068C34 7F034104 45000002 */  bc1f  .L7F034110
/* 068C38 7F034108 00000000 */   nop   
/* 068C3C 7F03410C 461CA501 */  sub.s $f20, $f20, $f28
.L7F034110:
/* 068C40 7F034110 1634FFC2 */  bne   $s1, $s4, .L7F03401C
/* 068C44 7F034114 00000000 */   nop   
/* 068C48 7F034118 00001025 */  move  $v0, $zero
.L7F03411C:
/* 068C4C 7F03411C 8FBF007C */  lw    $ra, 0x7c($sp)
/* 068C50 7F034120 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 068C54 7F034124 D7B60038 */  ldc1  $f22, 0x38($sp)
/* 068C58 7F034128 D7B80040 */  ldc1  $f24, 0x40($sp)
/* 068C5C 7F03412C D7BA0048 */  ldc1  $f26, 0x48($sp)
/* 068C60 7F034130 D7BC0050 */  ldc1  $f28, 0x50($sp)
/* 068C64 7F034134 D7BE0058 */  ldc1  $f30, 0x58($sp)
/* 068C68 7F034138 8FB00060 */  lw    $s0, 0x60($sp)
/* 068C6C 7F03413C 8FB10064 */  lw    $s1, 0x64($sp)
/* 068C70 7F034140 8FB20068 */  lw    $s2, 0x68($sp)
/* 068C74 7F034144 8FB3006C */  lw    $s3, 0x6c($sp)
/* 068C78 7F034148 8FB40070 */  lw    $s4, 0x70($sp)
/* 068C7C 7F03414C 8FB50074 */  lw    $s5, 0x74($sp)
/* 068C80 7F034150 8FB60078 */  lw    $s6, 0x78($sp)
/* 068C84 7F034154 03E00008 */  jr    $ra
/* 068C88 7F034158 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif



#ifdef NONMATCHING
void actionblock_guard_constructor_BDBE(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel actionblock_guard_constructor_BDBE
/* 068C8C 7F03415C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 068C90 7F034160 AFBF001C */  sw    $ra, 0x1c($sp)
/* 068C94 7F034164 AFA40040 */  sw    $a0, 0x40($sp)
/* 068C98 7F034168 AFA50044 */  sw    $a1, 0x44($sp)
/* 068C9C 7F03416C AFA60048 */  sw    $a2, 0x48($sp)
/* 068CA0 7F034170 0FC07FF0 */  jal   chrGetNumFree
/* 068CA4 7F034174 AFA7004C */   sw    $a3, 0x4c($sp)
/* 068CA8 7F034178 28410003 */  slti  $at, $v0, 3
/* 068CAC 7F03417C 14200031 */  bnez  $at, .L7F034244
/* 068CB0 7F034180 8FA30048 */   lw    $v1, 0x48($sp)
/* 068CB4 7F034184 8FAE0044 */  lw    $t6, 0x44($sp)
/* 068CB8 7F034188 05C30006 */  bgezl $t6, .L7F0341A4
/* 068CBC 7F03418C C4640000 */   lwc1  $f4, ($v1)
/* 068CC0 7F034190 0FC08D6B */  jal   select_psuedorandom_heads
/* 068CC4 7F034194 8FA40040 */   lw    $a0, 0x40($sp)
/* 068CC8 7F034198 8FA30048 */  lw    $v1, 0x48($sp)
/* 068CCC 7F03419C AFA20044 */  sw    $v0, 0x44($sp)
/* 068CD0 7F0341A0 C4640000 */  lwc1  $f4, ($v1)
.L7F0341A4:
/* 068CD4 7F0341A4 8FA70058 */  lw    $a3, 0x58($sp)
/* 068CD8 7F0341A8 8FAF004C */  lw    $t7, 0x4c($sp)
/* 068CDC 7F0341AC E7A40030 */  swc1  $f4, 0x30($sp)
/* 068CE0 7F0341B0 C4660004 */  lwc1  $f6, 4($v1)
/* 068CE4 7F0341B4 30F80010 */  andi  $t8, $a3, 0x10
/* 068CE8 7F0341B8 0018382B */  sltu  $a3, $zero, $t8
/* 068CEC 7F0341BC E7A60034 */  swc1  $f6, 0x34($sp)
/* 068CF0 7F0341C0 C4680008 */  lwc1  $f8, 8($v1)
/* 068CF4 7F0341C4 27A40030 */  addiu $a0, $sp, 0x30
/* 068CF8 7F0341C8 27A50028 */  addiu $a1, $sp, 0x28
/* 068CFC 7F0341CC 8FA60050 */  lw    $a2, 0x50($sp)
/* 068D00 7F0341D0 AFAF0028 */  sw    $t7, 0x28($sp)
/* 068D04 7F0341D4 0FC0CFD2 */  jal   sub_GAME_7F033F48
/* 068D08 7F0341D8 E7A80038 */   swc1  $f8, 0x38($sp)
/* 068D0C 7F0341DC 10400019 */  beqz  $v0, .L7F034244
/* 068D10 7F0341E0 8FA40040 */   lw    $a0, 0x40($sp)
/* 068D14 7F0341E4 8FA50044 */  lw    $a1, 0x44($sp)
/* 068D18 7F0341E8 0FC08D34 */  jal   retrieve_header_for_body_and_head
/* 068D1C 7F0341EC 8FA60058 */   lw    $a2, 0x58($sp)
/* 068D20 7F0341F0 10400014 */  beqz  $v0, .L7F034244
/* 068D24 7F0341F4 00402025 */   move  $a0, $v0
/* 068D28 7F0341F8 8FA80054 */  lw    $t0, 0x54($sp)
/* 068D2C 7F0341FC 27A50030 */  addiu $a1, $sp, 0x30
/* 068D30 7F034200 8FA60050 */  lw    $a2, 0x50($sp)
/* 068D34 7F034204 8FA70028 */  lw    $a3, 0x28($sp)
/* 068D38 7F034208 0FC080EE */  jal   replace_GUARDdata_with_actual_values
/* 068D3C 7F03420C AFA80010 */   sw    $t0, 0x10($sp)
/* 068D40 7F034210 1040000C */  beqz  $v0, .L7F034244
/* 068D44 7F034214 00402025 */   move  $a0, $v0
/* 068D48 7F034218 0FC0E93C */  jal   sub_GAME_7F03A4F0
/* 068D4C 7F03421C AFA2003C */   sw    $v0, 0x3c($sp)
/* 068D50 7F034220 0FC0E901 */  jal   set_stateflag_0x04_for_posdata
/* 068D54 7F034224 8FA4003C */   lw    $a0, 0x3c($sp)
/* 068D58 7F034228 8FA2003C */  lw    $v0, 0x3c($sp)
/* 068D5C 7F03422C 8FA90044 */  lw    $t1, 0x44($sp)
/* 068D60 7F034230 8C430004 */  lw    $v1, 4($v0)
/* 068D64 7F034234 A0690006 */  sb    $t1, 6($v1)
/* 068D68 7F034238 8FAA0040 */  lw    $t2, 0x40($sp)
/* 068D6C 7F03423C 10000002 */  b     .L7F034248
/* 068D70 7F034240 A06A000F */   sb    $t2, 0xf($v1)
.L7F034244:
/* 068D74 7F034244 00001025 */  move  $v0, $zero
.L7F034248:
/* 068D78 7F034248 8FBF001C */  lw    $ra, 0x1c($sp)
/* 068D7C 7F03424C 27BD0040 */  addiu $sp, $sp, 0x40
/* 068D80 7F034250 03E00008 */  jr    $ra
/* 068D84 7F034254 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void guard_constructor_BD(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel guard_constructor_BD
/* 068D88 7F034258 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 068D8C 7F03425C AFBF0024 */  sw    $ra, 0x24($sp)
/* 068D90 7F034260 AFA50034 */  sw    $a1, 0x34($sp)
/* 068D94 7F034264 AFA60038 */  sw    $a2, 0x38($sp)
/* 068D98 7F034268 0FC0CBE5 */  jal   convertPadIf9000
/* 068D9C 7F03426C 00E02825 */   move  $a1, $a3
/* 068DA0 7F034270 28412710 */  slti  $at, $v0, 0x2710
/* 068DA4 7F034274 1020000A */  beqz  $at, .L7F0342A0
/* 068DA8 7F034278 0002C100 */   sll   $t8, $v0, 4
/* 068DAC 7F03427C 00027080 */  sll   $t6, $v0, 2
/* 068DB0 7F034280 01C27023 */  subu  $t6, $t6, $v0
/* 068DB4 7F034284 000E7080 */  sll   $t6, $t6, 2
/* 068DB8 7F034288 3C0F8007 */  lui   $t7, %hi(ptr_0xxxpresets) 
/* 068DBC 7F03428C 8DEF5D18 */  lw    $t7, %lo(ptr_0xxxpresets)($t7)
/* 068DC0 7F034290 01C27023 */  subu  $t6, $t6, $v0
/* 068DC4 7F034294 000E7080 */  sll   $t6, $t6, 2
/* 068DC8 7F034298 10000009 */  b     .L7F0342C0
/* 068DCC 7F03429C 01CF3021 */   addu  $a2, $t6, $t7
.L7F0342A0:
/* 068DD0 7F0342A0 3C198007 */  lui   $t9, %hi(ptr_2xxxpresets) 
/* 068DD4 7F0342A4 8F395D1C */  lw    $t9, %lo(ptr_2xxxpresets)($t9)
/* 068DD8 7F0342A8 0302C021 */  addu  $t8, $t8, $v0
/* 068DDC 7F0342AC 0018C080 */  sll   $t8, $t8, 2
/* 068DE0 7F0342B0 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 068DE4 7F0342B4 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 068DE8 7F0342B8 03193021 */  addu  $a2, $t8, $t9
/* 068DEC 7F0342BC 00C13021 */  addu  $a2, $a2, $at
.L7F0342C0:
/* 068DF0 7F0342C0 C4CC0018 */  lwc1  $f12, 0x18($a2)
/* 068DF4 7F0342C4 C4CE0020 */  lwc1  $f14, 0x20($a2)
/* 068DF8 7F0342C8 0FC16A8C */  jal   atan2f
/* 068DFC 7F0342CC AFA6002C */   sw    $a2, 0x2c($sp)
/* 068E00 7F0342D0 8FA6002C */  lw    $a2, 0x2c($sp)
/* 068E04 7F0342D4 8FA80040 */  lw    $t0, 0x40($sp)
/* 068E08 7F0342D8 8FA90044 */  lw    $t1, 0x44($sp)
/* 068E0C 7F0342DC 8CC70028 */  lw    $a3, 0x28($a2)
/* 068E10 7F0342E0 E7A00010 */  swc1  $f0, 0x10($sp)
/* 068E14 7F0342E4 8FA40034 */  lw    $a0, 0x34($sp)
/* 068E18 7F0342E8 8FA50038 */  lw    $a1, 0x38($sp)
/* 068E1C 7F0342EC AFA80014 */  sw    $t0, 0x14($sp)
/* 068E20 7F0342F0 0FC0D057 */  jal   actionblock_guard_constructor_BDBE
/* 068E24 7F0342F4 AFA90018 */   sw    $t1, 0x18($sp)
/* 068E28 7F0342F8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 068E2C 7F0342FC 27BD0030 */  addiu $sp, $sp, 0x30
/* 068E30 7F034300 03E00008 */  jr    $ra
/* 068E34 7F034304 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void guard_constructor_BE(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel guard_constructor_BE
/* 068E38 7F034308 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 068E3C 7F03430C AFBF0024 */  sw    $ra, 0x24($sp)
/* 068E40 7F034310 AFA50034 */  sw    $a1, 0x34($sp)
/* 068E44 7F034314 AFA60038 */  sw    $a2, 0x38($sp)
/* 068E48 7F034318 0FC0CC10 */  jal   get_handle_for_guard_id
/* 068E4C 7F03431C 00E02825 */   move  $a1, $a3
/* 068E50 7F034320 8C4E0014 */  lw    $t6, 0x14($v0)
/* 068E54 7F034324 31CF0008 */  andi  $t7, $t6, 8
/* 068E58 7F034328 55E00013 */  bnezl $t7, .L7F034378
/* 068E5C 7F03432C 00001025 */   move  $v0, $zero
/* 068E60 7F034330 8C44001C */  lw    $a0, 0x1c($v0)
/* 068E64 7F034334 0FC1B320 */  jal   getsubroty
/* 068E68 7F034338 AFA2002C */   sw    $v0, 0x2c($sp)
/* 068E6C 7F03433C 8FA3002C */  lw    $v1, 0x2c($sp)
/* 068E70 7F034340 8FB80040 */  lw    $t8, 0x40($sp)
/* 068E74 7F034344 8FB90044 */  lw    $t9, 0x44($sp)
/* 068E78 7F034348 8C620018 */  lw    $v0, 0x18($v1)
/* 068E7C 7F03434C 8FA40034 */  lw    $a0, 0x34($sp)
/* 068E80 7F034350 8FA50038 */  lw    $a1, 0x38($sp)
/* 068E84 7F034354 8C470014 */  lw    $a3, 0x14($v0)
/* 068E88 7F034358 E7A00010 */  swc1  $f0, 0x10($sp)
/* 068E8C 7F03435C AFB80014 */  sw    $t8, 0x14($sp)
/* 068E90 7F034360 AFB90018 */  sw    $t9, 0x18($sp)
/* 068E94 7F034364 0FC0D057 */  jal   actionblock_guard_constructor_BDBE
/* 068E98 7F034368 24460008 */   addiu $a2, $v0, 8
/* 068E9C 7F03436C 10000003 */  b     .L7F03437C
/* 068EA0 7F034370 8FBF0024 */   lw    $ra, 0x24($sp)
/* 068EA4 7F034374 00001025 */  move  $v0, $zero
.L7F034378:
/* 068EA8 7F034378 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F03437C:
/* 068EAC 7F03437C 27BD0030 */  addiu $sp, $sp, 0x30
/* 068EB0 7F034380 03E00008 */  jr    $ra
/* 068EB4 7F034384 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_if_actorID_is_at_preset(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel check_if_actorID_is_at_preset
/* 068EB8 7F034388 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 068EBC 7F03438C AFBF0014 */  sw    $ra, 0x14($sp)
/* 068EC0 7F034390 AFA40020 */  sw    $a0, 0x20($sp)
/* 068EC4 7F034394 0FC0CC10 */  jal   get_handle_for_guard_id
/* 068EC8 7F034398 AFA60028 */   sw    $a2, 0x28($sp)
/* 068ECC 7F03439C 8FA40020 */  lw    $a0, 0x20($sp)
/* 068ED0 7F0343A0 8FA50028 */  lw    $a1, 0x28($sp)
/* 068ED4 7F0343A4 0FC0CBE5 */  jal   convertPadIf9000
/* 068ED8 7F0343A8 AFA20018 */   sw    $v0, 0x18($sp)
/* 068EDC 7F0343AC 28412710 */  slti  $at, $v0, 0x2710
/* 068EE0 7F0343B0 1020000A */  beqz  $at, .L7F0343DC
/* 068EE4 7F0343B4 8FA60018 */   lw    $a2, 0x18($sp)
/* 068EE8 7F0343B8 00027080 */  sll   $t6, $v0, 2
/* 068EEC 7F0343BC 01C27023 */  subu  $t6, $t6, $v0
/* 068EF0 7F0343C0 000E7080 */  sll   $t6, $t6, 2
/* 068EF4 7F0343C4 3C0F8007 */  lui   $t7, %hi(ptr_0xxxpresets) 
/* 068EF8 7F0343C8 8DEF5D18 */  lw    $t7, %lo(ptr_0xxxpresets)($t7)
/* 068EFC 7F0343CC 01C27023 */  subu  $t6, $t6, $v0
/* 068F00 7F0343D0 000E7080 */  sll   $t6, $t6, 2
/* 068F04 7F0343D4 1000000A */  b     .L7F034400
/* 068F08 7F0343D8 01CF1821 */   addu  $v1, $t6, $t7
.L7F0343DC:
/* 068F0C 7F0343DC 3C198007 */  lui   $t9, %hi(ptr_2xxxpresets) 
/* 068F10 7F0343E0 8F395D1C */  lw    $t9, %lo(ptr_2xxxpresets)($t9)
/* 068F14 7F0343E4 0002C100 */  sll   $t8, $v0, 4
/* 068F18 7F0343E8 0302C021 */  addu  $t8, $t8, $v0
/* 068F1C 7F0343EC 0018C080 */  sll   $t8, $t8, 2
/* 068F20 7F0343F0 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 068F24 7F0343F4 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 068F28 7F0343F8 03191821 */  addu  $v1, $t8, $t9
/* 068F2C 7F0343FC 00611821 */  addu  $v1, $v1, $at
.L7F034400:
/* 068F30 7F034400 8C620028 */  lw    $v0, 0x28($v1)
/* 068F34 7F034404 8FBF0014 */  lw    $ra, 0x14($sp)
/* 068F38 7F034408 5040000E */  beql  $v0, $zero, .L7F034444
/* 068F3C 7F03440C 00001025 */   move  $v0, $zero
/* 068F40 7F034410 50C0000C */  beql  $a2, $zero, .L7F034444
/* 068F44 7F034414 00001025 */   move  $v0, $zero
/* 068F48 7F034418 8CC30018 */  lw    $v1, 0x18($a2)
/* 068F4C 7F03441C 50600009 */  beql  $v1, $zero, .L7F034444
/* 068F50 7F034420 00001025 */   move  $v0, $zero
/* 068F54 7F034424 8C680014 */  lw    $t0, 0x14($v1)
/* 068F58 7F034428 904A0003 */  lbu   $t2, 3($v0)
/* 068F5C 7F03442C 91090003 */  lbu   $t1, 3($t0)
/* 068F60 7F034430 552A0004 */  bnel  $t1, $t2, .L7F034444
/* 068F64 7F034434 00001025 */   move  $v0, $zero
/* 068F68 7F034438 10000002 */  b     .L7F034444
/* 068F6C 7F03443C 24020001 */   li    $v0, 1
/* 068F70 7F034440 00001025 */  move  $v0, $zero
.L7F034444:
/* 068F74 7F034444 03E00008 */  jr    $ra
/* 068F78 7F034448 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif



#ifdef NONMATCHING
void check_if_actor_is_at_preset(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel check_if_actor_is_at_preset
/* 068F7C 7F03444C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 068F80 7F034450 AFBF0014 */  sw    $ra, 0x14($sp)
/* 068F84 7F034454 AFA40020 */  sw    $a0, 0x20($sp)
/* 068F88 7F034458 0FC225E6 */  jal   get_curplayer_positiondata
/* 068F8C 7F03445C AFA50024 */   sw    $a1, 0x24($sp)
/* 068F90 7F034460 AFA2001C */  sw    $v0, 0x1c($sp)
/* 068F94 7F034464 8FA40020 */  lw    $a0, 0x20($sp)
/* 068F98 7F034468 0FC0CBE5 */  jal   convertPadIf9000
/* 068F9C 7F03446C 8FA50024 */   lw    $a1, 0x24($sp)
/* 068FA0 7F034470 28412710 */  slti  $at, $v0, 0x2710
/* 068FA4 7F034474 1020000A */  beqz  $at, .L7F0344A0
/* 068FA8 7F034478 8FBF0014 */   lw    $ra, 0x14($sp)
/* 068FAC 7F03447C 00027080 */  sll   $t6, $v0, 2
/* 068FB0 7F034480 01C27023 */  subu  $t6, $t6, $v0
/* 068FB4 7F034484 000E7080 */  sll   $t6, $t6, 2
/* 068FB8 7F034488 3C0F8007 */  lui   $t7, %hi(ptr_0xxxpresets) 
/* 068FBC 7F03448C 8DEF5D18 */  lw    $t7, %lo(ptr_0xxxpresets)($t7)
/* 068FC0 7F034490 01C27023 */  subu  $t6, $t6, $v0
/* 068FC4 7F034494 000E7080 */  sll   $t6, $t6, 2
/* 068FC8 7F034498 1000000A */  b     .L7F0344C4
/* 068FCC 7F03449C 01CF1821 */   addu  $v1, $t6, $t7
.L7F0344A0:
/* 068FD0 7F0344A0 3C198007 */  lui   $t9, %hi(ptr_2xxxpresets) 
/* 068FD4 7F0344A4 8F395D1C */  lw    $t9, %lo(ptr_2xxxpresets)($t9)
/* 068FD8 7F0344A8 0002C100 */  sll   $t8, $v0, 4
/* 068FDC 7F0344AC 0302C021 */  addu  $t8, $t8, $v0
/* 068FE0 7F0344B0 0018C080 */  sll   $t8, $t8, 2
/* 068FE4 7F0344B4 3C01FFF5 */  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
/* 068FE8 7F0344B8 34219FC0 */  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
/* 068FEC 7F0344BC 03191821 */  addu  $v1, $t8, $t9
/* 068FF0 7F0344C0 00611821 */  addu  $v1, $v1, $at
.L7F0344C4:
/* 068FF4 7F0344C4 8C620028 */  lw    $v0, 0x28($v1)
/* 068FF8 7F0344C8 8FA8001C */  lw    $t0, 0x1c($sp)
/* 068FFC 7F0344CC 50400009 */  beql  $v0, $zero, .L7F0344F4
/* 069000 7F0344D0 00001025 */   move  $v0, $zero
/* 069004 7F0344D4 8D090014 */  lw    $t1, 0x14($t0)
/* 069008 7F0344D8 904B0003 */  lbu   $t3, 3($v0)
/* 06900C 7F0344DC 912A0003 */  lbu   $t2, 3($t1)
/* 069010 7F0344E0 554B0004 */  bnel  $t2, $t3, .L7F0344F4
/* 069014 7F0344E4 00001025 */   move  $v0, $zero
/* 069018 7F0344E8 10000002 */  b     .L7F0344F4
/* 06901C 7F0344EC 24020001 */   li    $v0, 1
/* 069020 7F0344F0 00001025 */  move  $v0, $zero
.L7F0344F4:
/* 069024 7F0344F4 03E00008 */  jr    $ra
/* 069028 7F0344F8 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif



#ifdef NONMATCHING
void removed_animation_routine_27(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel removed_animation_routine_27
/* 06902C 7F0344FC AFA40000 */  sw    $a0, ($sp)
/* 069030 7F034500 03E00008 */  jr    $ra
/* 069034 7F034504 00001025 */   move  $v0, $zero
)
#endif



#ifdef NONMATCHING
void removed_animation_routine_2B(void) {
// ai branch
}
#else
GLOBAL_ASM(
.text
glabel removed_animation_routine_2B
/* 069038 7F034508 AFA40000 */  sw    $a0, ($sp)
/* 06903C 7F03450C 03E00008 */  jr    $ra
/* 069040 7F034510 00001025 */   move  $v0, $zero
)
#endif



#ifdef NONMATCHING
// ai branch
? sub_GAME_7F034514(s32 arg0, s32 arg1)
{
    s32 temp_ret;

    arg1 = convertPadIf9000();
    if (chrIsNotDeadOrShot(arg0) != 0)
    {
        temp_ret = scan_position_data_table_for_normal_object_at_preset(arg1);
        if (temp_ret != 0)
        {
            if (check_if_object_has_not_been_destroyed(temp_ret) != 0)
            {
                chrlvExtendLeftHandAnimationRelated(arg0);
                return 1;
            }
        }
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F034514
/* 069044 7F034514 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 069048 7F034518 AFBF0014 */  sw    $ra, 0x14($sp)
/* 06904C 7F03451C 0FC0CBE5 */  jal   convertPadIf9000
/* 069050 7F034520 AFA40018 */   sw    $a0, 0x18($sp)
/* 069054 7F034524 AFA2001C */  sw    $v0, 0x1c($sp)
/* 069058 7F034528 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 06905C 7F03452C 8FA40018 */   lw    $a0, 0x18($sp)
/* 069060 7F034530 5040000E */  beql  $v0, $zero, .L7F03456C
/* 069064 7F034534 00001025 */   move  $v0, $zero
/* 069068 7F034538 0FC0FE91 */  jal   scan_position_data_table_for_normal_object_at_preset
/* 06906C 7F03453C 8FA4001C */   lw    $a0, 0x1c($sp)
/* 069070 7F034540 10400009 */  beqz  $v0, .L7F034568
/* 069074 7F034544 00402025 */   move  $a0, $v0
/* 069078 7F034548 0FC13BCD */  jal   check_if_object_has_not_been_destroyed
/* 06907C 7F03454C 00000000 */   nop   
/* 069080 7F034550 50400006 */  beql  $v0, $zero, .L7F03456C
/* 069084 7F034554 00001025 */   move  $v0, $zero
/* 069088 7F034558 0FC09054 */  jal   chrlvExtendLeftHandAnimationRelated
/* 06908C 7F03455C 8FA40018 */   lw    $a0, 0x18($sp)
/* 069090 7F034560 10000002 */  b     .L7F03456C
/* 069094 7F034564 24020001 */   li    $v0, 1
.L7F034568:
/* 069098 7F034568 00001025 */  move  $v0, $zero
.L7F03456C:
/* 06909C 7F03456C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0690A0 7F034570 27BD0018 */  addiu $sp, $sp, 0x18
/* 0690A4 7F034574 03E00008 */  jr    $ra
/* 0690A8 7F034578 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
// ai branch
? actor_draws_throws_grenade_at_player_if_possible(void *arg0)
{
    s32 sp24;
    s32 sp20;
    s32 temp_ret;
    s32 temp_ret_2;
    void *temp_v1;
    ? phi_a3;
    ? phi_a2;

    if ((u32) (randomGetNext() % 0xffU) >= (u32) arg0->unk10)
    {
        return 0;
    }
    if (distToBond3D(arg0) < 10.0f)
    {
        return 0;
    }
    if (chrIsNotDeadOrShot(arg0) != 0)
    {
        sp24 = something_with_weaponpos_of_guarddata_hand(arg0, 1);
        temp_ret = something_with_weaponpos_of_guarddata_hand(arg0, 0);
        sp20 = temp_ret;
        if (temp_ret != 0)
        {
            if (temp_ret->unk4->unk80 == 0x1a)
            {
                chrlvThrowGrenadeAnimationRelated(arg0, temp_ret, 0, 0);
                return 1;
            }
        }
        if (sp24 != 0)
        {
            if (sp24->unk4->unk80 == 0x1a)
            {
                chrlvThrowGrenadeAnimationRelated(arg0, sp24, 1, 0);
                return 1;
            }
        }
        if ((sp24 == 0) || (temp_ret == 0))
        {
            phi_a3 = 0;
            if (temp_ret != 0)
            {
                phi_a3 = 0x10000000;
            }
            temp_ret_2 = actor_draws_weapon_with_model(arg0, 0xc4, 0x1a, phi_a3);
            if (temp_ret_2 != 0)
            {
                temp_v1 = temp_ret_2->unk4;
                temp_v1->unk64 = (s32) (temp_v1->unk64 | 0x800);
                phi_a2 = 1;
                if (sp20 == 0)
                {
                    phi_a2 = 0;
                }
                chrlvThrowGrenadeAnimationRelated(arg0, temp_ret_2, phi_a2, 1);
                return 1;
            }
        }
        else
        {

        }
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel actor_draws_throws_grenade_at_player_if_possible
/* 0690AC 7F03457C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0690B0 7F034580 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0690B4 7F034584 AFB00018 */  sw    $s0, 0x18($sp)
/* 0690B8 7F034588 0C002914 */  jal   randomGetNext
/* 0690BC 7F03458C 00808025 */   move  $s0, $a0
/* 0690C0 7F034590 240100FF */  li    $at, 255
/* 0690C4 7F034594 0041001B */  divu  $zero, $v0, $at
/* 0690C8 7F034598 920F0010 */  lbu   $t7, 0x10($s0)
/* 0690CC 7F03459C 00007010 */  mfhi  $t6
/* 0690D0 7F0345A0 01CF082B */  sltu  $at, $t6, $t7
/* 0690D4 7F0345A4 14200003 */  bnez  $at, .L7F0345B4
/* 0690D8 7F0345A8 00000000 */   nop   
/* 0690DC 7F0345AC 1000004E */  b     .L7F0346E8
/* 0690E0 7F0345B0 00001025 */   move  $v0, $zero
.L7F0345B4:
/* 0690E4 7F0345B4 0FC0CB79 */  jal   distToBond3D
/* 0690E8 7F0345B8 02002025 */   move  $a0, $s0
/* 0690EC 7F0345BC 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0690F0 7F0345C0 44812000 */  mtc1  $at, $f4
/* 0690F4 7F0345C4 00000000 */  nop   
/* 0690F8 7F0345C8 4604003C */  c.lt.s $f0, $f4
/* 0690FC 7F0345CC 00000000 */  nop   
/* 069100 7F0345D0 45000003 */  bc1f  .L7F0345E0
/* 069104 7F0345D4 00000000 */   nop   
/* 069108 7F0345D8 10000043 */  b     .L7F0346E8
/* 06910C 7F0345DC 00001025 */   move  $v0, $zero
.L7F0345E0:
/* 069110 7F0345E0 0FC0A896 */  jal   chrIsNotDeadOrShot
/* 069114 7F0345E4 02002025 */   move  $a0, $s0
/* 069118 7F0345E8 1040003E */  beqz  $v0, .L7F0346E4
/* 06911C 7F0345EC 02002025 */   move  $a0, $s0
/* 069120 7F0345F0 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 069124 7F0345F4 24050001 */   li    $a1, 1
/* 069128 7F0345F8 AFA20024 */  sw    $v0, 0x24($sp)
/* 06912C 7F0345FC 02002025 */  move  $a0, $s0
/* 069130 7F034600 0FC08C0B */  jal   something_with_weaponpos_of_guarddata_hand
/* 069134 7F034604 00002825 */   move  $a1, $zero
/* 069138 7F034608 8FA50024 */  lw    $a1, 0x24($sp)
/* 06913C 7F03460C 1040000D */  beqz  $v0, .L7F034644
/* 069140 7F034610 AFA20020 */   sw    $v0, 0x20($sp)
/* 069144 7F034614 8C430004 */  lw    $v1, 4($v0)
/* 069148 7F034618 2401001A */  li    $at, 26
/* 06914C 7F03461C 02002025 */  move  $a0, $s0
/* 069150 7F034620 80780080 */  lb    $t8, 0x80($v1)
/* 069154 7F034624 00003025 */  move  $a2, $zero
/* 069158 7F034628 00003825 */  move  $a3, $zero
/* 06915C 7F03462C 17010005 */  bne   $t8, $at, .L7F034644
/* 069160 7F034630 00000000 */   nop   
/* 069164 7F034634 0FC0908E */  jal   chrlvThrowGrenadeAnimationRelated
/* 069168 7F034638 00402825 */   move  $a1, $v0
/* 06916C 7F03463C 1000002A */  b     .L7F0346E8
/* 069170 7F034640 24020001 */   li    $v0, 1
.L7F034644:
/* 069174 7F034644 10A0000C */  beqz  $a1, .L7F034678
/* 069178 7F034648 00000000 */   nop   
/* 06917C 7F03464C 8CA30004 */  lw    $v1, 4($a1)
/* 069180 7F034650 2401001A */  li    $at, 26
/* 069184 7F034654 02002025 */  move  $a0, $s0
/* 069188 7F034658 80790080 */  lb    $t9, 0x80($v1)
/* 06918C 7F03465C 24060001 */  li    $a2, 1
/* 069190 7F034660 17210005 */  bne   $t9, $at, .L7F034678
/* 069194 7F034664 00000000 */   nop   
/* 069198 7F034668 0FC0908E */  jal   chrlvThrowGrenadeAnimationRelated
/* 06919C 7F03466C 00003825 */   move  $a3, $zero
/* 0691A0 7F034670 1000001D */  b     .L7F0346E8
/* 0691A4 7F034674 24020001 */   li    $v0, 1
.L7F034678:
/* 0691A8 7F034678 10A00003 */  beqz  $a1, .L7F034688
/* 0691AC 7F03467C 02002025 */   move  $a0, $s0
/* 0691B0 7F034680 54400019 */  bnezl $v0, .L7F0346E8
/* 0691B4 7F034684 00001025 */   move  $v0, $zero
.L7F034688:
/* 0691B8 7F034688 10400002 */  beqz  $v0, .L7F034694
/* 0691BC 7F03468C 00003825 */   move  $a3, $zero
/* 0691C0 7F034690 3C071000 */  lui   $a3, 0x1000
.L7F034694:
/* 0691C4 7F034694 240500C4 */  li    $a1, 196
/* 0691C8 7F034698 0FC148F5 */  jal   actor_draws_weapon_with_model
/* 0691CC 7F03469C 2406001A */   li    $a2, 26
/* 0691D0 7F0346A0 10400010 */  beqz  $v0, .L7F0346E4
/* 0691D4 7F0346A4 00402825 */   move  $a1, $v0
/* 0691D8 7F0346A8 8C430004 */  lw    $v1, 4($v0)
/* 0691DC 7F0346AC 02002025 */  move  $a0, $s0
/* 0691E0 7F0346B0 24060001 */  li    $a2, 1
/* 0691E4 7F0346B4 8C680064 */  lw    $t0, 0x64($v1)
/* 0691E8 7F0346B8 35090800 */  ori   $t1, $t0, 0x800
/* 0691EC 7F0346BC AC690064 */  sw    $t1, 0x64($v1)
/* 0691F0 7F0346C0 8FAA0020 */  lw    $t2, 0x20($sp)
/* 0691F4 7F0346C4 15400003 */  bnez  $t2, .L7F0346D4
/* 0691F8 7F0346C8 00000000 */   nop   
/* 0691FC 7F0346CC 10000001 */  b     .L7F0346D4
/* 069200 7F0346D0 00003025 */   move  $a2, $zero
.L7F0346D4:
/* 069204 7F0346D4 0FC0908E */  jal   chrlvThrowGrenadeAnimationRelated
/* 069208 7F0346D8 24070001 */   li    $a3, 1
/* 06920C 7F0346DC 10000002 */  b     .L7F0346E8
/* 069210 7F0346E0 24020001 */   li    $v0, 1
.L7F0346E4:
/* 069214 7F0346E4 00001025 */  move  $v0, $zero
.L7F0346E8:
/* 069218 7F0346E8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 06921C 7F0346EC 8FB00018 */  lw    $s0, 0x18($sp)
/* 069220 7F0346F0 27BD0028 */  addiu $sp, $sp, 0x28
/* 069224 7F0346F4 03E00008 */  jr    $ra
/* 069228 7F0346F8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
// ai branch
? actor_drops_itemtype_setting_timer(void *arg0, s32 arg1, s32 arg2)
{
    s32 sp1C;
    s32 temp_ret;
    void *temp_a0;

    temp_ret = create_new_item_instance_of_model(arg1, arg2 & 0xff);
    if (temp_ret != 0)
    {
        if (temp_ret->unk10 != 0)
        {
            temp_a0 = temp_ret->unk14;
            sp1C = temp_ret;
            set_obj_instance_controller_scale(temp_a0, temp_a0->unk14);
            attachNewChild(sp1C->unk10, arg0->unk18);
            sp1C->unk82 = (u16)0xb4;
            sub_GAME_7F04BFD0(sp1C->unk10, 1);
            arg0->unk12 = (s16) (arg0->unk12 | 1);
            return 1;
        }
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel actor_drops_itemtype_setting_timer
/* 06922C 7F0346FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 069230 7F034700 AFA40020 */  sw    $a0, 0x20($sp)
/* 069234 7F034704 AFBF0014 */  sw    $ra, 0x14($sp)
/* 069238 7F034708 30CE00FF */  andi  $t6, $a2, 0xff
/* 06923C 7F03470C 00A02025 */  move  $a0, $a1
/* 069240 7F034710 AFA60028 */  sw    $a2, 0x28($sp)
/* 069244 7F034714 0FC1481B */  jal   create_new_item_instance_of_model
/* 069248 7F034718 01C02825 */   move  $a1, $t6
/* 06924C 7F03471C 5040001A */  beql  $v0, $zero, .L7F034788
/* 069250 7F034720 00001025 */   move  $v0, $zero
/* 069254 7F034724 8C4F0010 */  lw    $t7, 0x10($v0)
/* 069258 7F034728 51E00017 */  beql  $t7, $zero, .L7F034788
/* 06925C 7F03472C 00001025 */   move  $v0, $zero
/* 069260 7F034730 8C440014 */  lw    $a0, 0x14($v0)
/* 069264 7F034734 8C850014 */  lw    $a1, 0x14($a0)
/* 069268 7F034738 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 06926C 7F03473C AFA2001C */   sw    $v0, 0x1c($sp)
/* 069270 7F034740 8FA3001C */  lw    $v1, 0x1c($sp)
/* 069274 7F034744 8FB80020 */  lw    $t8, 0x20($sp)
/* 069278 7F034748 8C640010 */  lw    $a0, 0x10($v1)
/* 06927C 7F03474C 0FC0E969 */  jal   attachNewChild
/* 069280 7F034750 8F050018 */   lw    $a1, 0x18($t8)
/* 069284 7F034754 8FA3001C */  lw    $v1, 0x1c($sp)
/* 069288 7F034758 241900B4 */  li    $t9, 180
/* 06928C 7F03475C 24050001 */  li    $a1, 1
/* 069290 7F034760 A4790082 */  sh    $t9, 0x82($v1)
/* 069294 7F034764 0FC12FF4 */  jal   sub_GAME_7F04BFD0
/* 069298 7F034768 8C640010 */   lw    $a0, 0x10($v1)
/* 06929C 7F03476C 8FA80020 */  lw    $t0, 0x20($sp)
/* 0692A0 7F034770 24020001 */  li    $v0, 1
/* 0692A4 7F034774 95090012 */  lhu   $t1, 0x12($t0)
/* 0692A8 7F034778 352A0001 */  ori   $t2, $t1, 1
/* 0692AC 7F03477C 10000002 */  b     .L7F034788
/* 0692B0 7F034780 A50A0012 */   sh    $t2, 0x12($t0)
/* 0692B4 7F034784 00001025 */  move  $v0, $zero
.L7F034788:
/* 0692B8 7F034788 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0692BC 7F03478C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0692C0 7F034790 03E00008 */  jr    $ra
/* 0692C4 7F034794 00000000 */   nop   
)
#endif
  

