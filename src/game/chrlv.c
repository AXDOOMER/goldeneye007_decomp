#include "ultra64.h"
#include "bondaicommands.h"
#include "bondgame.h"
#include "bondconstants.h"
#include "chrlv.h"
#include "include/limits.h"
#include "include/math.h"
#include "music.h"
#include "random.h"
#include "game/bg.h"
#include "game/bondview.h"
#include "game/chr.h"
#include "game/chr_b.h"
#include "game/chrai.h"
#include "game/chrobjhandler.h"
#include "game/file.h"
#include "game/fog.h"
#include "game/front.h"
#include "game/gun.h"
#include "game/initanitable.h"
#include "game/loadobjectmodel.h"
#include "game/lvl.h"
#include "game/math_asinfacosf.h"
#include "game/math_atan2f.h"
#include "game/matrixmath.h"
#include "game/objecthandler.h"
#include "game/player.h"
#include "game/player_2.h"
#include "game/stan.h"
#include "game/unk_08DBB0.h"
#include "game/unk_0A1DA0.h"

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
struct coord3d *chrlvGetChrOrPresetLocation(ChrRecord *self, s32 flags, s32 lookup_id, StandTile **stan);
void sub_GAME_7F02D184(struct ChrRecord *arg0);
void sub_GAME_7F0281F4(struct ChrRecord *arg0);
s32 plot_course_for_actor(ChrRecord *arg0, struct act_gopos *arg1, struct StandTile *stan, SPEED speed);
void chrlvPlotCourseRelated(struct ChrRecord *arg0);
void chrlvActGoposSetTargetPosRelated(ChrRecord *arg0);
void chrlvActGoposIncCurIndex(struct ChrRecord *arg0);
void play_hit_soundeffect_and_proper_volume(struct ChrRecord *arg0);
void get_sound_at_range(ChrRecord *arg0, s32 arg1, s32 arg2);
void chrlvSetGoposSegDistTotal(struct ChrRecord *arg0, struct waydata *arg1, struct coord3d *arg2);
void chrlvIterateGuardSeeShotDie(ChrRecord *, s32);
s32 chrlvCall7F02982C(PropRecord *arg0, struct coord3d *arg1, f32 arg2);
void chrlvTickSurrender(struct ChrRecord *arg0);
void chrlvWalkingAnimationRelated(ChrRecord *arg0);
void setSeenBondTimeToNow(struct ChrRecord *guardData);
s32 chrlvAttackRelated7F0292A8(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2);
s32 chrlvMaybeSameRoom(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2);
s32 chrlvCurrentPlayerCall7F0B0E24(ChrRecord *arg0);
s32 chrlvCall7F0B0E24WithChrWidthHeight(PropRecord *arg0, struct coord3d *arg1, struct coord3d *arg2);
void chrlvSetTargetToPlayer(ChrRecord *arg0);
s32 chrlvSeenWithin600(ChrRecord *);
s32 sub_GAME_7F029D70(ChrRecord *self);
void chrlvNormDistanceToPlayer(ChrRecord *arg0, s32 arg1, struct coord3d *arg2);
s32 sub_GAME_7F02A0EC(ChrRecord *arg0, s32 arg1, f32 arg2);
void chrlvModelRotyRelated(ChrRecord *arg0, s32 arg1, struct coord3d *arg2);
s32 chrIsNotDeadOrShot(struct ChrRecord *chr);
void chrlvTickAnim(ChrRecord *arg0);
void chrlvTickDead(ChrRecord *arg0);
void chrlvTickArgh(ChrRecord *arg0);
void chrlvTickPreArgh(ChrRecord *arg0);
void chrlvTickSidestep(ChrRecord *arg0);
void chrlvTickJumpout(ChrRecord *arg0);
void chrlvTickTest(ChrRecord *arg0);
void chrlvTickStartAlarm(ChrRecord *arg0);
void chrlvTickSurprised(ChrRecord *arg0);
void sub_GAME_7F02BFE4(ChrRecord *arg0, s32 arg1, s32 arg2);
s32 chrlvSetSubroty(ChrRecord *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 chrlvUpdateAimendsideback(ChrRecord *arg0, struct weapon_firing_animation_table *arg1, s32 arg2, s32 arg3, f32 arg4);
void chrlvResetAimend(struct ChrRecord *arg0);
void chrlvToggleHiddenRelated(ChrRecord *arg0, s32 arg1, s32 arg2);
void chrlvUpdateShotbondsum(ChrRecord *arg0, s32 *arg1, s32 *arg2, ITEM_IDS item);
f32 sub_GAME_7F02C27C(struct ChrRecord *arg0);
void chrlvFireWeaponRelated(ChrRecord *self, s32 hand);
s32 chrlvAttackrollAnimationRelated7F02E2E0(ChrRecord *arg0);
void chrlvAttackrollAnimationRelated7F02E3B8(ChrRecord *arg0);
void sub_GAME_7F0256F0(ChrRecord *arg0, s32 arg1, s32 arg2);
void chrlvTickAttack(ChrRecord *arg0);
void sub_GAME_7F02E4C0(ChrRecord *);
void sub_GAME_7F025C40(struct ChrRecord *chr, s32);
void sub_GAME_7F02587C(struct ChrRecord *chr, s32);
void sub_GAME_7F024CF8(struct ChrRecord *arg0, struct coord3d *arg1);
void chrlvTickThrowGrenade(ChrRecord *self);
void chrlvTickBondIntro(ChrRecord *arg0);
void chrlvTickBondDieRemoved(ChrRecord *arg0);
s32 chrlvApplySpeed(ChrRecord *self, struct coord3d *arg1, s32 arg2, f32 *speedPtr);
void chrlvTickAttackWalk(ChrRecord *self);
void chrlvTickRunPos(ChrRecord *self);
s32 sub_GAME_7F030128(ChrRecord *arg0, struct coord3d *point, StandTile *arg2, struct coord3d *dest, StandTile * arg4, s32 objflags);
s32 sub_GAME_7F0301FC(ChrRecord *arg0, struct coord3d *point, StandTile *arg2, struct coord3d *dest, f32 arg4, s32 arg5);
s32 sub_GAME_7F0304AC(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2, struct coord3d *arg3, struct coord3d *arg4, StandTile *arg5, s32 arg6);
void chrlvSwapIfDiffArg2Determinate(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *arg2);
s32 sub_GAME_7F03081C(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2, struct coord3d *arg3, struct coord3d *arg4, struct coord3d *arg5, f32 arg6, f32 arg7, s32 arg8);
s32 sub_GAME_7F030D70(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2, struct coord3d *arg3, struct coord3d *arg4, struct coord3d *arg5, f32 arg6, f32 arg7, s32 arg8);
void sub_GAME_7F028600(ChrRecord *arg0, struct waydata *arg1, f32 arg2, struct coord3d *arg3, StandTile *arg4);
void chrlvTravelTick(ChrRecord *, struct coord3d *, StandTile *, struct waydata *);
void chrlvTickGoPos(ChrRecord *arg0);
void chrlvSetNextActPatrolStepPadPos(struct ChrRecord *arg0);
void sub_GAME_7F0284DC(struct ChrRecord *arg0);
void chrlvTickPatrol(ChrRecord *arg0);
f32 get_distance_actor_to_position(struct ChrRecord *self, struct coord3d *pos);
s32 chrResolveId(ChrRecord *self, s32 id);
s32 sub_GAME_7F033780(s32 *arg0, struct coord3d *arg1, f32 angle);
s32 chrlvFindPathNeighborRelated(struct coord3d *bondpos, struct StandTile *stan, f32 rot, u8 quadrant);
s32 sub_GAME_7F033EAC(struct coord3d *arg0, StandTile *arg1);
struct PropRecord *actionblock_guard_constructor_BDBE(s32 bodynum, s32 headnum, struct coord3d *pos, struct StandTile *stan, f32 yrot, s32 arg4, s32 arg5);
void sub_GAME_7F02516C(ChrRecord *arg0, void ** arg1, s32 arg2, struct point2d *arg3, s32 arg4, s32 arg5, s32 arg6);
s32 chrlvPatrolCalculateStep(ChrRecord *arg0, bool *forward, s32 numsteps);
s32 sub_GAME_7F028510(struct rect4f *arg0, struct ObjHeaderData *arg1);
s32 sub_GAME_7F03130C(ChrRecord *arg0,struct coord3d *arg1,s32 arg2,struct coord3d *arg3,f32 arg4,s32 arg5,struct coord3d *arg6,struct waydata *arg7,f32 arg8,s32 arg9,s32 set_copy);

// unknown type for arg1, reads offsets 0x30,0x34,0x40,0x44
// arg2 is only used to compare to zero, either flag or pointer
void chrlvUpdateAimendbackShoulders(ChrRecord *, void *, s32, s32, f32);


// end forward declarations














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



/**
 * Address 0x7F02370C.
*/
void expand_09_characters(s32 arg0, GuardRecord *arg1, s32 arg2)
{
    struct pad *pad;
    s32 unused2;
    struct StandTile *sp54; // 84
    s32 unused3;
    struct ChrRecord *temp_v0_5;
    struct pad *sp48; // 72
    struct PropRecord *temp_v0_4;
    struct ChrModelFileRecord *cmfr;
    f32 sp3C; // 60
    struct Model *sp38; //56
    s32 bodyid;
    s32 headid;

    pad = &ptr_0xxxpresets[arg1->PadID];

    if (sub_GAME_7F056850(pad, pad->stan, 20.0f, (struct pad *)&sp48, &sp54) != 0)
    {
        headid = -1;
        bodyid = (arg1->BodyID == 0xFFFF) 
            ? get_current_random_body()
            : arg1->BodyID;

        cmfr = &c_item_entries[bodyid];
        if (cmfr->hasHead == 0)
        {
            headid = (arg1->HeadID >= 0)
                ? arg1->HeadID
                : select_psuedorandom_heads(bodyid);
        }

        sp38 = retrieve_header_for_body_and_head(bodyid, headid, (u32) arg1->unk10);

        if (sp38 != 0)
        {
            sp3C = atan2f(pad->look.f[0], pad->look.f[2]);
            temp_v0_4 = replace_GUARDdata_with_actual_values(sp38, (struct pad *)&sp48, sp3C, sp54, LoadNext_PrevActionBlock(arg1->AIListID));
            
            if (temp_v0_4 != 0)
            {
                set_current_objposdata_plus_0x28(temp_v0_4);
                set_stateflag_0x04_for_posdata(temp_v0_4);

                temp_v0_5 = temp_v0_4->chr;
                temp_v0_5->chrnum = (s16) arg1->chrnum;
                temp_v0_5->hearingscale = ((f32)arg1->health) / 1000.0f;
                temp_v0_5->visionrange = (f32)arg1->ReactionTime;
                temp_v0_5->padpreset1 = (s16) arg1->Preset;
                temp_v0_5->chrpreset1 = (s16) arg1->unk0a;
                temp_v0_5->headnum = (s8) headid;
                temp_v0_5->bodynum = (s8) bodyid;
                
                if ((arg1->unk10 & 4) != 0)
                {
                    temp_v0_5->chrflags |= 2;
                }

                if ((arg1->unk10 & 8) != 0)
                {
                    temp_v0_5->chrflags |= 0x10;
                }

                arg1->Data = temp_v0_5;
            }
        }
    }
}



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

        if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ANIM_DATA_fire_kneel_forward_one_handed_weapon_slow + (s32)&ptr_animation_table->data)
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, (s32)&ANIM_DATA_fire_kneel_forward_one_handed_weapon_slow + (s32)&ptr_animation_table->data, (s32) arg0->model->gunhand, 109.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
            sub_GAME_7F06FDE8(arg0->model, 140.0f);
        }
        else
        {
            objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_fire_kneel_left_leg], (s32) arg0->model->gunhand, 120.0f, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
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
    arg0->act_anim.unk30 = (arg4 & 4) != 0;
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

    temp_f0 = chrGetAngleToBond(arg0);

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

            arg0->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
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




#ifndef VERSION_EU
/**
 * Address 0x7F024CF8 (not EU).
 * Address 0x7F024CE0 (VERSION_EU).
 */
void sub_GAME_7F024CF8(struct ChrRecord *arg0, struct coord3d *arg1)
{
    f32 dx;
    f32 dz;
    s32 unused;
    f32 sq;
    struct PropRecord *left;
    struct PropRecord *right;
    s32 sp2C;
    s32 phi_a2;

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
            phi_a2 = left != 0;
        }
        else
        {
            phi_a2 = left != 0;
        }
    }

    sub_GAME_7F02D184(arg0);

    arg0->actiontype = ACT_RUNPOS;
    arg0->act_runpos.pos.f[0] = arg1->f[0];
    arg0->act_runpos.pos.f[1] = arg1->f[1];
    arg0->act_runpos.pos.f[2] = arg1->f[2];
    arg0->sleep = 0;
    arg0->act_runpos.turnspeed = 0;
    arg0->act_runpos.neardist = 30.0f;

    if (sp2C)
    {
#ifdef VERSION_EU
        arg0->act_runpos.eta60 = (s32) (((sq / (D_80030988 * 0.5f)) * 50.0f) / 60.0f);
#else
        arg0->act_runpos.eta60 = (s32) (sq / (D_80030988 * 0.5f));
#endif
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_running], phi_a2, 0, 0.5f, 16.0f);
    }
    else
    {
#ifdef VERSION_EU
        arg0->act_runpos.eta60 = (s32) (((sq / (D_80030994 * 0.5f)) * 50.0f) / 60.0f);
#else
        arg0->act_runpos.eta60 = (s32) (sq / (D_80030994 * 0.5f));
#endif
        objecthandlerAnimationRelated7F06FCA8(arg0->model, (void*)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon], phi_a2, 0, 0.5f, 16.0f);
    }
}
#else

#ifdef NONMATCHING
    // should be implemented above, but untested.
#else
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

    struct weapon_firing_animation_table *f = arg0->act_attack.animfloats;

    if ((arg0->act_attack.attacktype & TARGET_AIM_ONLY) != 0)
    {
        if ((f->anonymous_8 >= 0.0f) && (f->anonymous_8 < f->anonymous_6))
        {
            sub_GAME_7F06FDE8(model, f->anonymous_8);
        }
        else
        {
            sub_GAME_7F06FDE8(model, f->anonymous_6);
        }
    }
    else if (arg0->act_attack.unk36 != 0)
    {
        if (f->anonymous_8 >= 0.0f)
        {
            sub_GAME_7F06FDE8(model, f->anonymous_8);
        }
        else
        {
            sub_GAME_7F06FDE8(model, f->anonymous_6);
        }
    }
    else if (f->anonymous_8 >= 0.0f)
    {
        sub_GAME_7F06FDE8(model, f->anonymous_8);
    }
    else if (f->anonymous_5 >= 0.0f)
    {
        sub_GAME_7F06FDE8(model, f->anonymous_5);
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

    return get_distance_actor_to_position(arg0, (struct coord3d *)chrlvGetChrOrPresetLocation(arg0, arg1, arg2, &out_unused));
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



/**
 * Address 0x7F025560.
*/
void sub_GAME_7F025560(ChrRecord *arg0, s32 arg1, s32 arg2)
{
    PropRecord *left;
    PropRecord *right;
    s32 last_arg2;
    void ** animation_pointer;
    struct point2d sp;
    PropRecord * left2;
    PropRecord * right2;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    sp = D_800309B8;

    if ((left != NULL) && (right != NULL))
    {
        left2 = is_weapon_in_guarddata_hand(arg0, LEFT_HAND);
        right2 = is_weapon_in_guarddata_hand(arg0, RIGHT_HAND);

        if ((left2 != NULL) && (right2 != NULL))
        {
            last_arg2 = (u32)randomGetNext() & (u32)1;

            if (((u32)randomGetNext() % 3U) == 0)
            {
                animation_pointer = ptr_pistol_firing_animation_groups;
                sp.p[LEFT_HAND] = last_arg2;
                sp.p[RIGHT_HAND] = !last_arg2;
            }
            else
            {
                animation_pointer = ptr_doubles_firing_animation_groups;
                sp.p[LEFT_HAND] = 1;
                sp.p[RIGHT_HAND] = 1;
            }
        }
        else
        {
            last_arg2 = right2 == 0;
            animation_pointer = ptr_pistol_firing_animation_groups;
            sp.p[LEFT_HAND] = last_arg2;
            sp.p[RIGHT_HAND] = !last_arg2;
        }
    }
    else
    {
        if ((check_if_item_held_like_pistol(left) != 0) || (check_if_item_held_like_pistol(right) != 0))
        {
            last_arg2 = left != 0;
            animation_pointer = ptr_pistol_firing_animation_groups;
            sp.p[LEFT_HAND] = last_arg2;
            sp.p[RIGHT_HAND] = !last_arg2;
        }
        else
        {
            last_arg2 = left != 0;
            animation_pointer = ptr_rifle_firing_animation_groups;
            sp.p[LEFT_HAND] = last_arg2;
            sp.p[RIGHT_HAND] = !last_arg2;
        }
    }

    sub_GAME_7F02516C(arg0, animation_pointer, last_arg2, &sp, arg1, arg2, 1);
}



/**
 * Address 0x7F0256F0.
 * PD: chrAttackKneel.
*/
void sub_GAME_7F0256F0(ChrRecord *arg0, s32 arg1, s32 arg2)
{
    PropRecord *left;
    PropRecord *right;
    s32 last_arg2;
    void ** animation_pointer;
    struct point2d sp;
    PropRecord * left2;
    PropRecord * right2;

    left = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
    right = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);

    sp = D_800309C0;

    if ((left != NULL) && (right != NULL))
    {
        left2 = is_weapon_in_guarddata_hand(arg0, LEFT_HAND);
        right2 = is_weapon_in_guarddata_hand(arg0, RIGHT_HAND);

        if ((left2 != NULL) && (right2 != NULL))
        {
            last_arg2 = (u32)randomGetNext() & (u32)1;

            if (((u32)randomGetNext() % 3U) == 0)
            {
                animation_pointer = ptr_crouched_pistol_firing_animation_groups;
                sp.p[LEFT_HAND] = last_arg2;
                sp.p[RIGHT_HAND] = !last_arg2;
            }
            else
            {
                animation_pointer = ptr_crouched_doubles_firing_animation_groups;
                sp.p[LEFT_HAND] = 1;
                sp.p[RIGHT_HAND] = 1;
            }
        }
        else
        {
            last_arg2 = right2 == 0;
            animation_pointer = ptr_crouched_pistol_firing_animation_groups;
            sp.p[LEFT_HAND] = last_arg2;
            sp.p[RIGHT_HAND] = !last_arg2;
        }
    }
    else
    {
        if ((check_if_item_held_like_pistol(left) != 0) || (check_if_item_held_like_pistol(right) != 0))
        {
            last_arg2 = left != 0;
            animation_pointer = ptr_crouched_pistol_firing_animation_groups;
            sp.p[LEFT_HAND] = last_arg2;
            sp.p[RIGHT_HAND] = !last_arg2;
        }
        else
        {
            last_arg2 = left != 0;
            animation_pointer = ptr_crouched_rifle_firing_animation_groups;
            sp.p[LEFT_HAND] = last_arg2;
            sp.p[RIGHT_HAND] = !last_arg2;
        }
    }

    sub_GAME_7F02516C(arg0, animation_pointer, last_arg2, &sp, arg1, arg2, 0);
}


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
/* 05A4B4 7F025984 3C0A8003 */   lui   $t2, %hi(D_80030660 + 144) 
/* 05A4B8 7F025988 3C098003 */  lui   $t1, %hi(D_80030660 + 216) 
/* 05A4BC 7F02598C 25290738 */  addiu $t1, %lo(D_80030660 + 216) # addiu $t1, $t1, 0x738
/* 05A4C0 7F025990 10000003 */  b     .L7F0259A0
/* 05A4C4 7F025994 AFA90084 */   sw    $t1, 0x84($sp)
.L7F025998:
/* 05A4C8 7F025998 254A06F0 */  addiu $t2, %lo(D_80030660 + 144) # addiu $t2, $t2, 0x6f0
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
/* 05A504 7F0259D4 3C198003 */   lui   $t9, %hi(D_80030660 + 288) 
/* 05A508 7F0259D8 3C0E8003 */  lui   $t6, %hi(D_80030660 + 360) 
/* 05A50C 7F0259DC 25CE07C8 */  addiu $t6, %lo(D_80030660 + 360) # addiu $t6, $t6, 0x7c8
/* 05A510 7F0259E0 10000003 */  b     .L7F0259F0
/* 05A514 7F0259E4 AFAE0084 */   sw    $t6, 0x84($sp)
.L7F0259E8:
/* 05A518 7F0259E8 27390780 */  addiu $t9, %lo(D_80030660 + 288) # addiu $t9, $t9, 0x780
/* 05A51C 7F0259EC AFB90084 */  sw    $t9, 0x84($sp)
.L7F0259F0:
/* 05A520 7F0259F0 AFB40074 */  sw    $s4, 0x74($sp)
/* 05A524 7F0259F4 10000038 */  b     .L7F025AD8
/* 05A528 7F0259F8 AFB40070 */   sw    $s4, 0x70($sp)
.L7F0259FC:
/* 05A52C 7F0259FC 12400005 */  beqz  $s2, .L7F025A14
/* 05A530 7F025A00 3C088003 */   lui   $t0, %hi(D_80030660 + 432) 
/* 05A534 7F025A04 3C188003 */  lui   $t8, %hi(D_80030660 + 504) 
/* 05A538 7F025A08 27180858 */  addiu $t8, %lo(D_80030660 + 504) # addiu $t8, $t8, 0x858
/* 05A53C 7F025A0C 10000003 */  b     .L7F025A1C
/* 05A540 7F025A10 AFB80084 */   sw    $t8, 0x84($sp)
.L7F025A14:
/* 05A544 7F025A14 25080810 */  addiu $t0, %lo(D_80030660 + 432) # addiu $t0, $t0, 0x810
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
/* 05A580 7F025A50 3C0C8003 */  lui   $t4, %hi(D_80030660 + 216) 
/* 05A584 7F025A54 258C0738 */  addiu $t4, %lo(D_80030660 + 216) # addiu $t4, $t4, 0x738
/* 05A588 7F025A58 10000004 */  b     .L7F025A6C
/* 05A58C 7F025A5C AFAC0084 */   sw    $t4, 0x84($sp)
.L7F025A60:
/* 05A590 7F025A60 3C0B8003 */  lui   $t3, %hi(D_80030660 + 144) 
/* 05A594 7F025A64 256B06F0 */  addiu $t3, %lo(D_80030660 + 144) # addiu $t3, $t3, 0x6f0
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
/* 05A5CC 7F025A9C 3C0A8003 */  lui   $t2, %hi(D_80030660 + 72) 
/* 05A5D0 7F025AA0 254A06A8 */  addiu $t2, %lo(D_80030660 + 72) # addiu $t2, $t2, 0x6a8
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
/* 05A940 7F025E10 3C0F8003 */   lui   $t7, %hi(D_80030078 + 144) 
/* 05A944 7F025E14 3C188003 */  lui   $t8, %hi(D_80030078) 
/* 05A948 7F025E18 27180078 */  addiu $t8, %lo(D_80030078) # addiu $t8, $t8, 0x78
/* 05A94C 7F025E1C 1000000F */  b     .L7F025E5C
/* 05A950 7F025E20 AFB80088 */   sw    $t8, 0x88($sp)
.L7F025E24:
/* 05A954 7F025E24 25EF0108 */  addiu $t7, %lo(D_80030078 + 144) # addiu $t7, $t7, 0x108
/* 05A958 7F025E28 1000000C */  b     .L7F025E5C
/* 05A95C 7F025E2C AFAF0088 */   sw    $t7, 0x88($sp)
.L7F025E30:
/* 05A960 7F025E30 0C002914 */  jal   randomGetNext
/* 05A964 7F025E34 00000000 */   nop   
/* 05A968 7F025E38 30480001 */  andi  $t0, $v0, 1
/* 05A96C 7F025E3C 11000005 */  beqz  $t0, .L7F025E54
/* 05A970 7F025E40 3C098003 */   lui   $t1, %hi(D_80030078 + 216) 
/* 05A974 7F025E44 3C198003 */  lui   $t9, %hi(D_80030078 + 72) 
/* 05A978 7F025E48 273900C0 */  addiu $t9, %lo(D_80030078 + 72) # addiu $t9, $t9, 0xc0
/* 05A97C 7F025E4C 10000003 */  b     .L7F025E5C
/* 05A980 7F025E50 AFB90088 */   sw    $t9, 0x88($sp)
.L7F025E54:
/* 05A984 7F025E54 25290150 */  addiu $t1, %lo(D_80030078 + 216) # addiu $t1, $t1, 0x150
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

    getCollisionEdge_maybe(&sp2C, &sp20);
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

    getCollisionEdge_maybe(&sp2C, &sp20);

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
        flag1 = (arg0->actiontype == ACT_ARGH) && (g_GlobalTimer == arg0->act_argh.unk30);

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
                arg0->act_argh.unk30 = g_GlobalTimer;
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
                    arg0->act_argh.unk30 = g_GlobalTimer;
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
                arg0->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
            }

            if ((arg0->weapons_held[LEFT_HAND] != NULL) && ((arg0->weapons_held[LEFT_HAND]->obj->flags & 0x2000) == 0))
            {
                sub_GAME_7F04BFD0(arg0->weapons_held[LEFT_HAND], 1);
                arg0->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
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
        if (arg0->act_attackroll.unk35 != 0)
        {
            if (
                (arg0->act_attackroll.animfloats == &D_80030078[4])
                || (arg0->act_attackroll.animfloats == &D_80030078[5])
                || (arg0->act_attackroll.animfloats == &D_80030078[6])
                || (arg0->act_attackroll.animfloats == &D_80030078[7]))
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

    if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_sprinting])
    {
        scale_factor = D_8003098C;
    }
    else if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running])
    {
        scale_factor = D_80030988;
    }
    else if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ANIM_DATA_sprinting_one_handed_weapon + (s32)&ptr_animation_table->data[0])
    {
        scale_factor = D_80030998;
    }
    else if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon])
    {
        scale_factor = D_80030994;
    }
    else if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_unarmed])
    {
        scale_factor = D_80030990;
    }
    // typo/mistake, `ANIM_DATA_sprinting_one_handed_weapon` is duplicate of above.
    // compiler swaps addition order when reading this from the stack, unlike addresses only seen once (seen once means not saved to stack).
    else if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ANIM_DATA_sprinting_one_handed_weapon + (s32)&ptr_animation_table->data[0])
    {
        scale_factor = D_800309A4;
    }
    else if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running_female])
    {
        scale_factor = D_800309A0;
    }
    else if ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_walking_female])
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

    if (arg0->act_gopos.waydata.mode != WAYMODE_MAGIC)
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



/**
 * Determines which step index the chr will be at given their current index, the
 * number of steps to take and in which direction (forward or back).
 *
 * Returns the step index and populates *forward with true or false depending on
 * whether the chr will be traversing the path in the forward direction at that
 * point.
 * 
 * Address 0x7F028348.
 *
 * PD: chrPatrolCalculateStep
 */
s32 chrlvPatrolCalculateStep(ChrRecord *arg0, bool *forward, s32 numsteps)
{
    s32 nextstep = arg0->act_patrol.nextstep;
	bool isforward = *forward;

	if (numsteps < 0)
    {
		isforward = !isforward;
		numsteps = -numsteps;
	}

    while (numsteps > 0)
    {
        numsteps--;

        if (isforward)
        {
            nextstep++;

            if (arg0->act_patrol.path->data[nextstep] < 0)
            {
                nextstep -= 2;

				// Reached the end of the list
				if (arg0->act_patrol.path->flags & 1)
                {
					nextstep = 0;
				}
                else
                {
					isforward = FALSE;
				}
			}
        }
        else
        {
            nextstep--;

            if (nextstep < 0)
            {
                nextstep = 1;

				// Reached the start of the list
				if (arg0->act_patrol.path->flags & 1)
                {
					nextstep = arg0->act_patrol.path->len - 1;
				}
                else
                {
					isforward = TRUE;
				}
            }
        }
    }

    *forward = isforward;

	return nextstep;
}




#ifdef NONMATCHING

// notes: struct SetupPtrs isn't (currently defined), it's theoretical update
// to struct stagesetup. Requires AI Branch merge first.

/**
 * Address 0x7F0283FC.
*/
struct pad * chrlvGetPatrolStepPad(ChrRecord *arg0, s32 arg1)
{
    //struct patrol_path *path;
    s32 forward;
    s32 step;
    //s32 nextstep;

    forward = arg0->act_patrol.forward;

    step = chrlvPatrolCalculateStep(arg0, &forward, arg1);

    //path = arg0->act_patrol.path;

    step = arg0->act_patrol.path->data[step];

     return &((struct SetupPtrs *)&ptr_setup_path_tbl)->padlist[
         ((struct SetupPtrs *)&ptr_setup_path_tbl)->pathtbl[step].id
         ];
}

#else
GLOBAL_ASM(
.text
glabel chrlvGetPatrolStepPad
/* 05CF2C 7F0283FC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 05CF30 7F028400 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05CF34 7F028404 8C8E0034 */  lw    $t6, 0x34($a0)
/* 05CF38 7F028408 00A03025 */  move  $a2, $a1
/* 05CF3C 7F02840C 27A50020 */  addiu $a1, $sp, 0x20
/* 05CF40 7F028410 AFA40028 */  sw    $a0, 0x28($sp)
/* 05CF44 7F028414 0FC0A0D2 */  jal   chrlvPatrolCalculateStep
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
struct pad * chrlvGetNextPatrolStepPad(struct ChrRecord *arg0)
{
    return chrlvGetPatrolStepPad(arg0, 0);
}


/**
 * Address 0x7F028494.
*/
void chrlvSetNextActPatrolStepPadPos(struct ChrRecord *arg0)
{
    struct pad *temp_v0;

    temp_v0 = chrlvGetNextPatrolStepPad(arg0);
    arg0->act_patrol.waydata.mode = 0;
    arg0->act_patrol.waydata.unk01 = 0;
    arg0->act_patrol.waydata.unk02 = 0;
    arg0->act_patrol.waydata.pos.f[0] = temp_v0->pos.f[0];
    arg0->act_patrol.waydata.pos.f[1] = temp_v0->pos.f[1];
    arg0->act_patrol.waydata.pos.f[2] = temp_v0->pos.f[2];
}




/**
 * Address 0x7F0284DC.
*/
void sub_GAME_7F0284DC(struct ChrRecord *arg0)
{
    arg0->act_patrol.nextstep = chrlvPatrolCalculateStep(arg0, &arg0->act_patrol.forward, 1);
    chrlvSetNextActPatrolStepPadPos(arg0);
}



/**
 * Address 0x7F028510.
*/
s32 sub_GAME_7F028510(struct rect4f *arg0, struct ObjHeaderData *arg1)
{
    s32 sp50[8];
    s16 *temp_s0;
    struct PropRecord *propss = &pos_data_entry;
    struct rect4f *prect4f; // 68
    s32 sp40;
    
    sp50[0] = arg1->type;
    sp50[1] = -1;
    sub_GAME_7F03E3FC(&sp50);
    
    for (temp_s0 = ptr_list_object_lookup_indices; *temp_s0 >= 0; temp_s0++)
    {
        struct PropRecord *prop = &propss[*temp_s0];

        if (prop->type == PROP_TYPE_OBJ)
        {
            chraiGetCollisionBoundsWithoutY(prop, &prect4f, &sp40);

            if ((sp40 > 0) && sub_GAME_7F03CCD8(arg0, prect4f, sp40))
            {
                return 0;
            }
        }
    }

    return 1;
}


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
/* 05D278 7F028748 0FC0A11D */  jal   chrlvGetNextPatrolStepPad
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
/* 05D384 7F028854 0FC0A125 */  jal   chrlvSetNextActPatrolStepPadPos
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


/**
 * Gets character segment percent completed.
 * If action type is ACT_PATROL, computes distance between chr and target pad.
 * If action type is ACT_GOPOS, computes distance between chr and target position.
 * Otherwise result is chr->prop position.
 * 
 * @param arg0:
 * @param arg1: Out parameter. Contains result.
 * 
 * Address 0x7F028894.
 * PD: chrCalculatePosition.
*/
void chrlvGetPatrolPercentOrPosition(ChrRecord *arg0, struct coord3d *arg1)
{
    struct pad *pad;
    f32 percent;
    struct coord3d sp2C; // 44
    StandTile *stan;

    if ((arg0->actiontype == ACT_PATROL) && (arg0->act_patrol.waydata.mode == WAYMODE_MAGIC))
    {
        pad = chrlvGetNextPatrolStepPad(arg0);

        if (arg0->act_patrol.waydata.segdisttotal <= arg0->act_patrol.waydata.segdistdone)
        {
            arg1->f[0] = pad->pos.f[0];
            arg1->f[1] = pad->pos.f[1];
            arg1->f[2] = pad->pos.f[2];

            return;
        }

        percent = arg0->act_patrol.waydata.segdistdone / arg0->act_patrol.waydata.segdisttotal;

        arg1->f[0] = arg0->prop->pos.f[0] + ((pad->pos.f[0] - arg0->prop->pos.f[0]) * percent);
        arg1->f[1] = arg0->prop->pos.f[1] + ((pad->pos.f[1] - arg0->prop->pos.f[1]) * percent);
        arg1->f[2] = arg0->prop->pos.f[2] + ((pad->pos.f[2] - arg0->prop->pos.f[2]) * percent);

        return;
    }
    
    if ((arg0->actiontype == ACT_GOPOS) && (arg0->act_gopos.waydata.mode == WAYMODE_MAGIC))
    {
        chrlvActGoposRelated(arg0, &sp2C, &stan);

        if (arg0->act_gopos.waydata.segdisttotal <= arg0->act_gopos.waydata.segdistdone)
        {
            arg1->f[0] = sp2C.f[0];
            arg1->f[1] = sp2C.f[1];
            arg1->f[2] = sp2C.f[2];

            return;
        }

        percent = arg0->act_gopos.waydata.segdistdone / arg0->act_gopos.waydata.segdisttotal;

        arg1->f[0] = arg0->prop->pos.f[0] + ((sp2C.f[0] - arg0->prop->pos.f[0]) * percent);
        arg1->f[1] = arg0->prop->pos.f[1] + ((sp2C.f[1] - arg0->prop->pos.f[1]) * percent);
        arg1->f[2] = arg0->prop->pos.f[2] + ((sp2C.f[2] - arg0->prop->pos.f[2]) * percent);

        return;
    }

    arg1->f[0] = arg0->prop->pos.f[0];
    arg1->f[1] = arg0->prop->pos.f[1];
    arg1->f[2] = arg0->prop->pos.f[2];
}



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
s32 plot_course_for_actor(ChrRecord *arg0, struct act_gopos *arg1, struct StandTile *stan, SPEED speed)
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

    phi_v0 = (arg0->actiontype == ACT_GOPOS) && (arg0->act_gopos.unk59 == (u8)speed);

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
        arg0->act_gopos.unk59 = speed;
        arg0->act_gopos.speed = 0.0f;
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
void set_actor_on_path(ChrRecord *self, struct patrol_path *path)
{
    struct pad * pad;
    s32 next_step = -1;
    struct PropRecord *prop = self->prop;
    s32 count = 0;
    s32 index;

    // decomp problem area: can't seem to get arr[count] to dereference the correct number of times.
    for (index = path->data[count] ; index >= 0; count++, index = path->data[count])
    {
        //s32 aa;

        //aa = ptr_setup_path_tbl[index].id;
        //pad = &ptr_0xxxpresets[aa];
        struct path_table_alt *pta = &ptr_setup_path_tbl[index];
        pad = &ptr_0xxxpresets[pta->id];

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
    self->act_patrol.path = path;

    self->act_patrol.nextstep = next_step;
    self->act_patrol.forward = TRUE;

    self->act_patrol.waydata.age = randomGetNext() % 0x64U;
    self->act_patrol.waydata.unk03 = 0;
    self->act_init.padding[0x13] = -1;

    self->act_patrol.unk7c = 0.0f;
    chrlvSetNextActPatrolStepPadPos(self);
    self->sleep = 0;
    chrlvWalkingAnimationRelated(self);
    pad = chrlvGetNextPatrolStepPad(self);

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
/* 05DD60 7F029230 0FC0A125 */  jal   chrlvSetNextActPatrolStepPadPos
/* 05DD64 7F029234 E606007C */   swc1  $f6, 0x7c($s0)
/* 05DD68 7F029238 A2000008 */  sb    $zero, 8($s0)
/* 05DD6C 7F02923C 0FC0A3EB */  jal   chrlvWalkingAnimationRelated
/* 05DD70 7F029240 02002025 */   move  $a0, $s0
/* 05DD74 7F029244 0FC0A11D */  jal   chrlvGetNextPatrolStepPad
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
    flags = TARGET_BOND;

    if (arg0->actiontype == ACT_ATTACK)
    {
        flags = arg0->act_attack.attacktype;
    }

    if ((flags & TARGET_FRONT_OF_CHR) != 0)
    {
        ret = 1;
    }
    else
    {
        stan = arg2;
        sp3C = chrlvGetChrOrPresetLocation(arg0, flags, arg0->act_attack.entityid, &sp40);
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
    arg0->hidden |= CHRHIDDEN_ALERT_GUARD_RELATED;
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

    if (chrlvSeenWithin600(self))
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

    return FALSE; //unable to step
}



/**
 * Address 0x7F02A428.
*/
bool actor_hops_sideways(ChrRecord *self)
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

        /*DegToRad(45)*/
        if ((myNormalizedRadToBond < M_45_DEG_IN_RAD)            
            /*DegToRad(360-45)*/
            || (myNormalizedRadToBond > M_315_DEG_IN_RAD)                 
            /*DegToRad(180-45) && DegToRad(180+45)*/
            || ((myNormalizedRadToBond > M_135_DEG_IN_RAD) && (myNormalizedRadToBond < M_225_DEG_IN_RAD))
        )
        {
            HopDirection = (randomGetNext() & 1) == 0;         //Hop Left or Right

            if (sub_GAME_7F02A1E8(self, HopDirection, 200.0f)) //able to hop dir?
            {
                chrlvFireJumpToSideAnimationRelated(self, HopDirection);
                return TRUE;
            }

            HopOtherDirection = HopDirection == 0;

            if (sub_GAME_7F02A1E8(self, HopOtherDirection, 200.0f)) //able to hop other dir?
            {
                chrlvFireJumpToSideAnimationRelated(self, HopOtherDirection);
                return TRUE;
            }
        }
    }

    return FALSE; //unable to hop
}



/**
 * Address 0x7F02A588.
*/
bool actor_jogs_sideways(ChrRecord *self)
{
    struct PropRecord *myprop;
    f32 distToRun;
    struct coord3d TargetVector;
    struct coord3d TargetCoord;

    if (chrIsNotDeadOrShot(self) && ((g_GlobalTimer - self->lastwalk60) >= 181)) //>3 seconds since last walk
    {
        myprop    = self->prop;
        distToRun = ((u32)randomGetNext() * (1.0f / UINT_MAX) * 200.0f) + 200.0f; //random dist to run between 0 and 200
        chrlvNormDistanceToPlayer(self, ((u32)randomGetNext() & 1) == 0, &TargetVector);  //get vector to run on
        
        TargetCoord.f[0] = myprop->pos.f[0] + (TargetVector.f[0] * distToRun);
        TargetCoord.f[1] = myprop->pos.f[1];
        TargetCoord.f[2] = myprop->pos.f[2] + (TargetVector.f[2] * distToRun);

        if (chrlvCall7F0B0E24WithChrWidthHeight(myprop, &TargetCoord, &TargetVector))
        {
            sub_GAME_7F024CF8(self, &TargetCoord);
            return TRUE;
        }

        TargetVector.f[0] = -TargetVector.f[0];
        TargetVector.f[2] = -TargetVector.f[2];
        TargetCoord.f[0]  = myprop->pos.f[0] + (TargetVector.f[0] * distToRun);
        TargetCoord.f[1]  = myprop->pos.f[1];
        TargetCoord.f[2]  = myprop->pos.f[2] + (TargetVector.f[2] * distToRun);

        if (chrlvCall7F0B0E24WithChrWidthHeight(myprop, &TargetCoord, &TargetVector))
        {
            sub_GAME_7F024CF8(self, &TargetCoord);
            return TRUE;
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02A704.
*/
bool actor_walks_and_fires(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;

    if (chrIsNotDeadOrShot(self))
    {
        myprop   = self->prop;
        bondprop = get_curplayer_positiondata();

        if (
            (is_weapon_in_guarddata_hand(self, RIGHT_HAND) || is_weapon_in_guarddata_hand(self, LEFT_HAND))
            &&
            ((g_GlobalTimer - self->lastwalk60) >= 181)
            )
        {
            f32 dx = bondprop->pos.f[0] - myprop->pos.f[0];
            f32 dy = bondprop->pos.f[1] - myprop->pos.f[1];
            f32 dz = bondprop->pos.f[2] - myprop->pos.f[2];

            if ( ((dx*dx) + (dy*dy) + (dz*dz)) >= (1000000.0f))
            {
                sub_GAME_7F02587C(self, SPEED_WALK);
                return TRUE;
            }
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02A7F8.
*/
bool actor_runs_and_fires(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;

    if (chrIsNotDeadOrShot(self))
    {
        myprop   = self->prop;
        bondprop = get_curplayer_positiondata();

        if (
            (is_weapon_in_guarddata_hand(self, RIGHT_HAND) || is_weapon_in_guarddata_hand(self, LEFT_HAND))
            &&
            ((g_GlobalTimer - self->lastwalk60) >= 181)
            )
        {
            f32 dx = bondprop->pos.f[0] - myprop->pos.f[0];
            f32 dy = bondprop->pos.f[1] - myprop->pos.f[1];
            f32 dz = bondprop->pos.f[2] - myprop->pos.f[2];

            if ( ((dx*dx) + (dy*dy) + (dz*dz)) >= (1000000.0f))
            {
                sub_GAME_7F02587C(self, SPEED_JOG);
                return TRUE;
            }
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02A8EC.
*/
bool actor_rolls_fires_crouched(ChrRecord *self)
{
    PropRecord *myprop;
    PropRecord *bondprop;

    struct coord3d vec;

    bool HopOtherDirection;
    bool HopDirection;
    float vec2rd;

    if (chrIsNotDeadOrShot(self))
    {
        myprop   = self->prop;
        bondprop = get_curplayer_positiondata();

        if (is_weapon_in_guarddata_hand(self, RIGHT_HAND) || is_weapon_in_guarddata_hand(self, LEFT_HAND))
        {
            vec.x  = bondprop->pos.x - myprop->pos.x;
            vec.y  = bondprop->pos.y - myprop->pos.y;
            vec.z  = bondprop->pos.z - myprop->pos.z;
            vec2rd = (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);

            if ((200.0f * 200.0f) <= vec2rd) /*Bond GT 200 from chr*/
            {
                HopDirection = (randomGetNext() & 1) == 0; //Hop Left or Right

                if (sub_GAME_7F02A0EC(self, HopDirection, 200))
                {
                    sub_GAME_7F025C40(self, HopDirection);
                    return TRUE;
                }

                HopOtherDirection = HopDirection == 0;

                if (sub_GAME_7F02A0EC(self, HopOtherDirection, 200))
                {
                    sub_GAME_7F025C40(self, HopOtherDirection);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02AA1C.
*/
bool actor_aim_at_actor(ChrRecord *self, s32 a, s32 b)
{
    if ((chrIsNotDeadOrShot(self)) &&
        ((is_weapon_in_guarddata_hand(self, RIGHT_HAND)) || (is_weapon_in_guarddata_hand(self, LEFT_HAND))))
    {
        sub_GAME_7F025560(self, a, b);
        return TRUE;
    }

    return FALSE;
}




/**
 * Address 0x7F02AA88.
*/
bool actor_kneel_aim_at_actor(ChrRecord *self, s32 targettype, s32 targetid)
{
    if ((chrIsNotDeadOrShot(self)) &&
        ((is_weapon_in_guarddata_hand(self, RIGHT_HAND)) || (is_weapon_in_guarddata_hand(self, LEFT_HAND))))
    {
        sub_GAME_7F0256F0(self, targettype, targetid);
        return TRUE;
    }

    return FALSE;
}




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



/**
 * Address 0x7F02AB44.
*/
bool check_set_actor_standing_still(ChrRecord *self, s32 faceentitytype, s32 faceentityid)
{
    if (chrIsNotDeadOrShot(self) != 0)
    {
        if (self->actiontype != ACT_STAND)
        {
            chrlvKneelingAnimationRelated(self);
        }

        self->act_stand.face_entitytype = faceentitytype;
        self->act_stand.face_entityid   = faceentityid;
        self->act_stand.unk038          = 0;
        self->act_stand.unk040          = 0;

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F02ABB4.
*/
bool actor_moves_to_preset_at_speed(ChrRecord *self, s32 padid, SPEED speed)
{
    struct pad *pad;
    struct StandTile *stan2; //sp38
    struct coord3d region;
    struct StandTile *stan; //sp28 - wow, deliberate duplicate...

    if ((padid >= 0) && chrIsNotDeadOrShot(self) && (g_SeenBondRecentlyGuardCount < 10))
    {
        padid = convertPadIf9000(self, padid);
        if (isNotBoundPad(padid))
        {
            pad = &ptr_0xxxpresets[padid];
        }
        else
        {
            pad = (struct pad *)&ptr_2xxxpresets[getBoundPadNum(padid)];
        }

        stan = pad->stan;
        if (stan)
        {
            //if pad is not vertical
            if (pad->up.y < 0.5f)
            {
                stan2    = stan;
                region.x = (pad->up.x * (self->chrwidth * 1.1f)) + pad->pos.x;
                region.y = (pad->up.y * (self->chrwidth * 1.1f)) + pad->pos.y;
                region.z = (pad->up.z * (self->chrwidth * 1.1f)) + pad->pos.z;

                //if able to reach region surrounding pad?
                if (walkTilesBetweenPoints_NoCallback(&stan2, pad->pos.x, pad->pos.z, region.x, region.z) &&
                    plot_course_for_actor(self, &region, stan2, speed))
                {
                    return TRUE;
                }
            }
            else if (plot_course_for_actor(self, &pad->pos, stan, speed))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}



/**
 * Address 0x7F02AD54.
*/
bool if_actor_able_set_on_path(ChrRecord *self, s32 pathid)
{
    if (pathid && chrIsNotDeadOrShot(self))
    {
        set_actor_on_path(self, pathid);
        return TRUE;
    }

    return FALSE;
}



#ifdef NONMATCHING
void chrlvTickStand(void) {

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
glabel chrlvTickStand
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
/* 05F94C 7F02AE1C 0FC1BD6B */  jal   objecthandlerGetModelAnim
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
/* 05F97C 7F02AE4C 0FC0B0AC */  jal   chrlvSetSubroty
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



void chrlvTickKneel(struct ChrRecord *actor) {
    actor->sleep = 0;
}



/**
 * Address 0x7F02B4E8.
*/
void chrlvTickAnim(ChrRecord *arg0)
{
    s32 unused[1];

    if (arg0->act_init.padding[1] == 0)
    {
        f32 sp20 = objecthandlerGetModelField28(arg0->model);
        
        if (sub_GAME_7F06F5C4(arg0->model) <= sp20)
        {
            chrlvKneelingAnimationRelated(arg0);
        }
    }

    if (
        ((s32)objecthandlerGetModelAnim(arg0->model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_sneeze])
        && (objecthandlerGetModelField28(arg0->model) >= 42.0f)
        && ((arg0->chrflags << 6) >= 0))
    {
        if (((D_80048380 & 1) == 0) && (chrlvDistToBond3D(arg0) < 800.0f))
        {
            sub_GAME_7F053A10(sndPlaySfx(g_musicSfxBufferPtr, 0x101, 0), &arg0->prop->pos);
        }

        arg0->chrflags |= 0x2000000;
    }

    if (((s32) arg0->sleep <= 0) && (arg0->act_init.padding[3] != 0))
    {
        arg0->sleep = (randomGetNext() % 5U) + 0xE;
    }
}



/**
 * Address 0x7F02B638.
*/
void chrlvTickSurrender(struct ChrRecord *arg0)
{
    Model *model;

    if ((s32) arg0->sleep <= 0)
    {
        model = arg0->model;
        arg0->sleep = 0x10;

        if (((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed_drop_weapon]) 
            && (objecthandlerGetModelField28(model) >= 80.0f))
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



/**
 * Address 0x7F02B774.
*/
void chrlvTickDead(ChrRecord *arg0)
{
    if (arg0->act_init.padding[0] >= 0)
    {
        arg0->act_init.padding[0] += g_ClockTimer;

        if (arg0->act_init.padding[0] >= 90)
        {
            arg0->hidden |= CHRHIDDEN_REMOVE;
        }
        else
        {
            arg0->fadealpha = (u8) ((s32) ((90 - arg0->act_init.padding[0]) * 0xFF) / 90);
        }

        return;
    }

    arg0->act_init.padding[0] = 0;
}




/**
 * @param self:
 * @param flag: shot/die flag. 0 == shot, else die.
 * 
 * Address 0x7F02B800.
*/
void chrlvIterateGuardSeeShotDie(ChrRecord *self, s32 flag)
{
    ChrRecord *guard;
    PropRecord *self_prop;
    f32 dx;
    f32 dz;
    f32 dy;
    s32 numguards;
    struct PropRecord *guard_prop;
    s32 i = 0;
    s32 alert_count = 0;

    numguards = get_numguards();

    /*
     * Maybe there's removed code in these if,elseif blocks? 
    */
    if (self->actiontype == ACT_ARGH)
    {
        i = self->act_init.padding[0];
    }
    else if (self->actiontype == ACT_DIE)
    {
        i = self->act_init.padding[0];
    }

    for (; i < numguards && alert_count < 4; i++)
    {
        guard = &ptr_guard_data[i];

        if (guard->model != NULL)
        {
            guard_prop = guard->prop;
            self_prop = self->prop;
            dx = guard_prop->pos.f[0] - self_prop->pos.f[0];
            dy = guard_prop->pos.f[1] - self_prop->pos.f[1];
            dz = guard_prop->pos.f[2] - self_prop->pos.f[2];

            if (((dx * dx) + (dy * dy) + (dz * dz)) < 4000000.0f)
            {
                alert_count++;

                if (chrlvMaybeSameRoom(guard, &self_prop->pos, self_prop->stan))
                {
                    if (flag == 0)
                    {
                        guard->chrseeshot = self->chrnum;
                    }
                    else
                    {
                        guard->chrseedie = self->chrnum;
                    }
                }
            }
        }
    }

    if (self->actiontype == ACT_ARGH)
    {
        self->act_init.padding[0] = i;
    }
    else if (self->actiontype == ACT_DIE)
    {
        self->act_init.padding[0] = i;
    }
}




/**
 * Address 0x7F02B9A4.
 * PD: void chrTickDie(struct chrdata *chr).
*/
void chrlvTickDie(ChrRecord *arg0)
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
        if ((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_death_left_leg])
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

    chrlvIterateGuardSeeShotDie(arg0, 1);
}




/**
 * Address 0x7F02BC80.
*/
void chrlvTickArgh(ChrRecord *arg0)
{
    Model *model = arg0->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvSetTargetToPlayer(arg0);

        if ((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_death_left_leg])
        {
            chrlvIdleAnimationRelated7F023E14(arg0, 26.0f);
        }
        else
        {
            chrlvKneelingAnimationRelated7F023E48(arg0);
        }
    }

    chrlvIterateGuardSeeShotDie(arg0, 0);
}



/**
 * Address 0x7F02BD20.
*/
void chrlvTickPreArgh(ChrRecord *arg0)
{
    Model *model;
    struct coord3d sp30;

    model = arg0->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        sp30.f[0] = arg0->act_preargh.pos.f[0];
        sp30.f[1] = arg0->act_preargh.pos.f[1];
        sp30.f[2] = arg0->act_preargh.pos.f[2];
        triggered_on_shot_hit(arg0, &sp30, arg0->act_preargh.unk038, arg0->act_preargh.unk03c, arg0->act_preargh.unk040);
    }
}




/**
 * @see chrlvTickJumpout
 * @see chrlvTickTest
 * @see chrlvTickStartAlarm
 * 
 * Address 0x7F02BDA4.
*/
void chrlvTickSidestep(ChrRecord *arg0)
{
    Model *model = arg0->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvSetTargetToPlayer(arg0);
        chrlvIdleAnimationRelated7F023E14(arg0, 10.0f);
    }
}


/**
 * @see chrlvTickSidestep
 * @see chrlvTickTest
 * @see chrlvTickStartAlarm
 * 
 * Address 0x7F02BE00.
*/
void chrlvTickJumpout(ChrRecord *arg0)
{
    Model *model = arg0->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvSetTargetToPlayer(arg0);
        chrlvKneelingAnimationRelated7F023E48(arg0);
    }
}




/**
 * @see chrlvTickSidestep
 * @see chrlvTickJumpout
 * @see chrlvTickStartAlarm
 * 
 * Address 0x7F02BE58.
*/
void chrlvTickTest(ChrRecord *arg0)
{
    Model *model = arg0->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvKneelingAnimationRelated(arg0);
    }
}



/**
 * @see chrlvTickSidestep
 * @see chrlvTickJumpout
 * @see chrlvTickTest
 * 
 * Address 0x7F02BEA8.
*/
void chrlvTickStartAlarm(ChrRecord *arg0)
{
    Model *model = arg0->model;

    if (objecthandlerGetModelField28(model) >= 60.0f)
    {
        start_alarm();
    }

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        chrlvKneelingAnimationRelated7F023E48(arg0);
    }
}



/**
 * Address 0x7F02BF24.
*/
void chrlvTickSurprised(ChrRecord *arg0)
{
    Model *model = arg0->model;

    if (objecthandlerGetModelField28(model) >= sub_GAME_7F06F5C4(model))
    {
        if ((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_surrendering_armed])
        {
            chrlvIdleAnimationRelated7F023E14(arg0, 26.0f);
        }
        else if ((s32)objecthandlerGetModelAnim(model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_spotting_bond])
        {
            chrlvIdleAnimationRelated7F023E14(arg0, 26.0f);
        }
        else
        {
            chrlvKneelingAnimationRelated7F023E48(arg0);
        }
    }
}



#ifdef NONMATCHING
/**
 * Address 0x7F02BFE4.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: no
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * notes: struct ChrRecord needs some changes, but not sure what to figure out the weird section below.
*/
void sub_GAME_7F02BFE4(ChrRecord *arg0, s32 arg1, s32 arg2)
{
    struct PropRecord *prop;
    u8 sp33;
    u16 sp30;
    s32 phi_a1;
    ChrRecord *temp_v1;
    s32 unused[1];
    s32 sp28;
    ALSoundState *phi_a2;

    prop = something_with_weaponpos_of_guarddata_hand(arg0, arg1);
    temp_v1 = prop->chr;
    phi_a1 = 0;

    sp33 = bondwalkItemGetSoundTriggerRate((s32) temp_v1->act_attack.attack_item);
    sp30 = bondwalkItemGetSound((s32) temp_v1->act_attack.attack_item);

    if (arg2 != 0)
    {
        if ((s32) sp33 > 0)
        {
            if (((arg0->hidden & CHRHIDDEN_FIRE_TRACER) == 0) && arg0->field_178[arg1] < g_GlobalTimer)
            {
                phi_a1 = 1;
            }
        }
        else
        {
            phi_a1 = 1;
        }
    }

    if (phi_a1 != 0)
    {
        // begin decomp problem area.
        // I can't make sense of this with the current ChrRecord definition.

        // if (arg0->unk160 != NULL)
        // {
        //     if (sndGetPlayingState(arg0->unk160[arg1]) != AL_STOPPED)
        //     {
        //         sndDeactivate(arg0->unk160[arg1]);
        //     }
        // }

        // if (arg0->unk164[arg1] != NULL)
        // {
        //     if (sndGetPlayingState(arg0->unk164[arg1]) != AL_STOPPED)
        //     {
        //         sndDeactivate(arg0->unk164[arg1]);
        //     }
        // }
        
        // if (sp30 != 0)
        // {
        //     phi_a2 = NULL;
        //     if (arg0->unk160[arg1] == NULL)
        //     {
        //         phi_a2 = arg0->unk160[arg1];
        //     }
        //     else if (arg0->unk164[arg1] == NULL)
        //     {
        //         phi_a2 = arg0->unk164[arg1];
        //     }

        //     if (phi_a2 != NULL)
        //     {
        //         sndPlaySfx(g_musicSfxBufferPtr, (s16) sp30, phi_a2);
        //         sub_GAME_7F053A10(phi_a2, &arg0->prop->pos);

        //         arg0->field_178[arg1] = g_GlobalTimer + sp33;
        //         arg0->hidden |= 0x80;
        //     }
        // }
        // end decomp problem area.
    }
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


/**
 * Address 0x7F02C190.
*/
f32 chrlvGetSubrotySideback(ChrRecord *arg0)
{
    Model *model;
    f32 phi_f12;
    f32 ret;

    model = arg0->model;
    ret = getsubroty(model) + arg0->aimsideback;
    phi_f12 = 0.0f;

    if (ret >= M_TAU)
    {
        ret = ret - M_TAU;
    }
    else if (ret < 0.0f)
    {
        ret = ret + M_TAU;
    }

    if ((arg0->actiontype == ACT_ATTACK) || (arg0->actiontype == ACT_ATTACKROLL))
    {
        phi_f12 = arg0->act_attack.animfloats->anonymous_3;
    }
    else if (arg0->actiontype == ACT_BONDMULTI)
    {
        if (arg0->act_bondmulti.unk2c != NULL)
        {
            phi_f12 = arg0->act_bondmulti.unk2c[3];
        }
    }

    if (phi_f12 != 0.0f)
    {
        if (arg0->model->gunhand != RIGHT_HAND)
        {
            phi_f12 = M_TAU - phi_f12;
        }

        ret = ret + phi_f12;

        if (ret >= M_TAU)
        {
            ret = ret - M_TAU;
        }
    }

    return ret;
}




/**
 * Address 0x7F02C27C.
*/
f32 sub_GAME_7F02C27C(struct ChrRecord *arg0)
{
    f32 temp_f2;

    temp_f2 = arg0->aimuprshoulder + arg0->aimupback;
    if (temp_f2 < 0.0f)
    {
        temp_f2 = temp_f2 + M_TAU;
    }

    return temp_f2;
}



/**
 * Address 0x7F02C2B0.
*/
s32 chrlvSetSubroty(ChrRecord *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    Model *model;
    f32 sp28; //sp40
    f32 dist;
    f32 roty;
    s32 unused[1];
    f32 temp_f14;

    if (arg1 != 2)
    {
        model = arg0->model;
        sp28 = objecthandlerGetModelField28(model);
        roty = getsubroty(model);

#if defined(VERSION_JP)
        temp_f14 = 0.06283186f * arg3 * g_JP_GlobalTimerDelta * model->unka4;
#else /* VERSION_US, VERSION_EU */
        temp_f14 = 0.06283186f * arg3 * g_GlobalTimerDelta * model->unka4;
#endif

        if (arg0->actiontype == ACT_ATTACK)
        {
            dist = chrlvDistanceToChrRelated(arg0, arg0->act_attack.attacktype, arg0->act_attack.entityid);
        }
        else if (arg0->actiontype == ACT_STAND)
        {
            dist = chrlvDistanceToChrRelated(arg0, arg0->act_stand.face_entitytype, arg0->act_stand.face_entityid);
        }
        else
        {
            struct PropRecord* p;
            p = get_curplayer_positiondata();
            dist = get_distance_actor_to_position(arg0, &p->pos);
        }

        dist = dist - arg4;

        if (dist < 0.0f)
        {
            dist = dist + M_TAU;
        }

        if ((dist < temp_f14) || ((M_TAU - temp_f14) < dist))
        {
            roty += dist;
            if (roty >= M_TAU)
            {
                roty -= M_TAU;
            }

            setsubroty(model, roty);
            arg1 = 3;
        }
        else if (dist < M_PI_F)
        {
            roty += temp_f14;
            if (roty >= M_TAU)
            {
                roty -= M_TAU;
            }

            setsubroty(model, roty);
        }
        else
        {
            roty -= temp_f14;
            
            if (roty < 0.0f)
            {
                roty += M_TAU;
            }

            setsubroty(model, roty);
        }

        if (arg2 <= sp28)
        {
            arg1 = 2;
        }
    }

    return arg1;
}




/**
 * @param arg0:
 * @param arg1:
 * @param arg2:
 * @param arg3:
 * @param arg4:
 * 
 * Address 0x7F02C4C0.
*/
s32 chrlvUpdateAimendsideback(ChrRecord *arg0, struct weapon_firing_animation_table *arg1, s32 arg2, s32 arg3, f32 arg4)
{
    f32 sp164; // sp356
    f32 calc_aimendsideback; // sp352
    u32 attack_type; // sp348
    s32 entity_id; // sp344
    s32 ret; // sp340
    f32 dx; // sp336
    f32 dy; // sp332
    f32 dz; // sp328
    f32 dxdydz_square; // sp324
    Model *self_model; 
    PropRecord *self_prop; // sp316
    s32 seen_bond_flag; // sp312
    struct coord3d *current_player_pos; //sp308
    f32 ducking_height; // sp304
    struct StandTile *pstan; // sp300
    struct coord3d sp120; // sp288
    PropRecord *player_prop;
    f32 subroty; // sp280

    /////////////////////

    ret = 1;
    sp164 = 0.0f;
    attack_type = TARGET_BOND;
    entity_id = 0;
    calc_aimendsideback = 0.0f;

    if (arg0->actiontype == ACT_ATTACK)
    {
        attack_type = arg0->act_attack.attacktype;
        entity_id = arg0->act_attack.entityid;
    }
    else if (arg0->actiontype == ACT_STAND)
    {
        attack_type = arg0->act_stand.face_entitytype;
        entity_id = arg0->act_stand.face_entityid;
    }
    
    if ((attack_type & TARGET_FRONT_OF_CHR) == 0)
    {
        player_prop = get_curplayer_positiondata();
        self_prop = arg0->prop;
        current_player_pos = &player_prop->pos;

        dx = player_prop->pos.f[0] - self_prop->pos.f[0];
        dy = player_prop->pos.f[1] - self_prop->pos.f[1];
        dz = player_prop->pos.f[2] - self_prop->pos.f[2];

        dxdydz_square = (dx * dx) + (dy * dy) + (dz * dz);

        if (attack_type & TARGET_BOND)
        {
            if ((attack_type & TARGET_DONTTURN) != 0)
            {
                seen_bond_flag = 1;
            }
            else
            {
                seen_bond_flag = sub_GAME_7F0294BC(arg0);
            }
        }
        else
        {
            seen_bond_flag = 1;
        }

        if (attack_type & TARGET_BOND > 0)
        {
            ducking_height = bondviewGetPlayerDuckingHeightRelated(g_CurrentPlayer);
            if ((arg0->chrflags & 0x20) != 0)
            {
                if (((dx * dx) + (dy * dy) + (dz * dz)) < 160000.0f)
                {
                    if (self_prop->pos.f[1] < (current_player_pos->f[1] - (2.0f * ducking_height)))
                    {
                        dy -= ducking_height * (0.55f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                    }
                    else if ((current_player_pos->f[1] - (ducking_height * 0.5f)) < self_prop->pos.f[1])
                    {
                        dy -= ducking_height * (0.15f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                    }
                    else
                    {
                        dy = (((f32) (u32)randomGetNext() * (1.0f / UINT_MAX) * 0.1f * arg4) + 1.0f) * 40.0f;
                    }
                }
                else
                {
                    dy += ducking_height * (0.025f - (0.05f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
            }
            else if (((dx * dx) + (dy * dy) + (dz * dz)) > 1000000.0f)
            {
                if (((u32)randomGetNext() % 3U) == 0)
                {
                    dy += ducking_height * (0.05f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
                else
                {
                    dy -= ducking_height * (0.05f + (0.55f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
            }
            else
            {
                if (self_prop->pos.f[1] < (current_player_pos->f[1] - ducking_height))
                {
                    dy -= ducking_height * (0.55f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
                else if ((current_player_pos->f[1] - (ducking_height * 0.5f)) < self_prop->pos.f[1])
                {
                    dy -= ducking_height * (0.15f + (0.1f * ((f32) (u32)randomGetNext() * (1.0f / UINT_MAX)) * arg4));
                }
                else
                {
                    dy = (((f32) (u32)randomGetNext() * (1.0f / UINT_MAX) * 0.1f * arg4) - 0.05f) * ducking_height;
                }
            }
        }
        else
        {
            getsuboffset(arg0->model, &sp120);
            current_player_pos = chrlvGetChrOrPresetLocation(arg0, attack_type, entity_id, &pstan);
            dx = current_player_pos->f[0] - sp120.f[0];
            dy = current_player_pos->f[1] - sp120.f[1];
            dz = current_player_pos->f[2] - sp120.f[2];
        }

        if ((attack_type & 0x100) == 0)
        {
            f32 sr = sqrtf((dx * dx) + (dz * dz));
            sp164 = atan2f(dy, sr);

            if (sp164 >= M_PI_F)
            {
                sp164 = sp164 - M_TAU;
            }
        }

        if (seen_bond_flag)
        {
            Model *weapon_prop_model; // sp272
            struct coord3d sp104; // sp260
            PropRecord *weapon_prop;
            struct modeldata_root *temp_v0_4;
            Mtxf spBC; // sp188
            f32 *spB8;  // sp184
            struct coord3d spAC; //sp172
            s32 intersect_flag; // sp140
            Mtxf sp68;
            struct coord3d sp5C; // sp92
            struct coord3d sp50; // sp80
            struct coord3d sp44; // sp68
            Mtxf *temp_a0;
            struct ObjectRecord *obj;
            f32 t1;
            
            ////////////////////////////////////////////

            subroty = chrlvGetSubrotySideback(arg0);
            
            if (arg3)
            {
                weapon_prop = something_with_weaponpos_of_guarddata_hand(arg0, RIGHT_HAND);
            }
            else
            {
                weapon_prop = something_with_weaponpos_of_guarddata_hand(arg0, LEFT_HAND);
            }

            // This if block is a slight modification of @see sub_GAME_7F02D630.
            if ((weapon_prop != NULL) && (weapon_prop->flags & 2) && (dxdydz_square < 1000000.0f))
            {
                obj = weapon_prop->obj;
                weapon_prop_model = obj->model;
                intersect_flag = 0;
                
                if (weapon_prop_model->obj->Switches[0])
                {
                    temp_a0 = sub_GAME_7F06C660(weapon_prop_model, weapon_prop_model->obj->Switches[0], 0);
                    spB8 = weapon_prop_model->obj->Switches[0]->Data;
                    sub_GAME_7F058E78(temp_a0, &spBC);

                    matrix_4x4_multiply_homogeneous_in_place(currentPlayerGetMatrix10EC(), &spBC);

                    spAC.f[0] = spB8[0];
                    spAC.f[1] = spB8[1];
                    spAC.f[2] = spB8[2];

                    matrix_4x4_transform_vector_in_place(&spBC, (f32*) &spAC);

                    sp104.f[0] = spAC.f[0];
                    sp104.f[1] = spAC.f[1];
                    sp104.f[2] = spAC.f[2];

                    intersect_flag = 1;
                }
                else if (weapon_prop_model->obj->Switches[1])
                {
                    temp_a0 = sub_GAME_7F06C660(weapon_prop_model, weapon_prop_model->obj->Switches[1], 0);
                    sub_GAME_7F058E78(temp_a0, &sp68);
                    matrix_4x4_multiply_homogeneous_in_place(currentPlayerGetMatrix10EC(), &sp68);
                    sp104.f[0] = sp68.m[3][0];
                    sp104.f[1] = sp68.m[3][1];
                    sp104.f[2] = sp68.m[3][2];

                    intersect_flag = 1;
                }

                if (intersect_flag != 0)
                {
                    sp50.f[0] = sinf(subroty);
                    sp50.f[1] = 0.0f;
                    sp50.f[2] = cosf(subroty);
                    sp44.f[0] = self_prop->pos.f[0] - dz;
                    sp44.f[1] = self_prop->pos.f[1];
                    sp44.f[2] = self_prop->pos.f[2] + dx;
                    chrlvLineLineIntersection(&self_prop->pos, &sp44, &sp104, &sp50, &sp5C);
                    dx = current_player_pos->f[0] - sp5C.f[0];
                    dz = current_player_pos->f[2] - sp5C.f[2];
                }
            }

            t1 = atan2f(dx, dz);

            calc_aimendsideback = t1 - subroty;
            if (t1 < subroty)
            {
                calc_aimendsideback = t1 - subroty + M_TAU;
            }

            temp_v0_4 = (struct modeldata_root*)extract_id_from_object_structure_microcode(arg0->model, arg0->model->obj->RootNode);

            if (temp_v0_4->unk5c > 0.0f)
            {
                calc_aimendsideback = calc_aimendsideback - (temp_v0_4->unk5c * temp_v0_4->unk58);

                if (calc_aimendsideback < 0.0f)
                {
                    calc_aimendsideback = calc_aimendsideback + M_TAU;
                }

                if (calc_aimendsideback >= M_TAU)
                {
                    calc_aimendsideback = calc_aimendsideback - M_TAU;
                }
            }

            if ((attack_type & 1) && ((attack_type & 0x60) == 0))
            {
                t1 = (((f32) ((s32) ((s32) ((f32) g_GlobalTimer * arg0->model->unka4) + arg0->chrnum) % 60) * M_TAU) / 60.0f);
                t1 = sinf(t1) * (chrlvGetAimLimitAngle(dxdydz_square) * 0.5f);
                calc_aimendsideback += t1;

                if (calc_aimendsideback < 0.0f)
                {
                    calc_aimendsideback = calc_aimendsideback + M_TAU;
                }

                if (calc_aimendsideback >= M_TAU)
                {
                    calc_aimendsideback = calc_aimendsideback - M_TAU;
                }
            }

            if (calc_aimendsideback >= M_PI_F)
            {
                calc_aimendsideback = calc_aimendsideback - M_TAU;
            }

            calc_aimendsideback += arg0->aimsideback;

            if (arg0->model->gunhand != RIGHT_HAND)
            {
                if (calc_aimendsideback < -arg1->anonymous_14)
                {
                    calc_aimendsideback = -arg1->anonymous_14;
                    ret = 0;
                }
                else if (-arg1->anonymous_15 < calc_aimendsideback)
                {
                    calc_aimendsideback = -arg1->anonymous_15;
                    ret = 0;
                }
            }
            else
            {
                if (arg1->anonymous_14 < calc_aimendsideback)
                {
                    calc_aimendsideback = arg1->anonymous_14;
                    ret = 0;
                }
                else if (calc_aimendsideback < arg1->anonymous_15)
                {
                    calc_aimendsideback = arg1->anonymous_15;
                    ret = 0;
                }
            }
        }
    }

    chrlvUpdateAimendbackShoulders(arg0, arg1, arg2, arg3, sp164);
    arg0->aimendsideback = calc_aimendsideback;
    arg0->aimendcount = 0xA;

    return ret;
}




/**
 * Calculates and sets chr aimendrshoulder, aimendlshoulder, and aimendback.
 * rshoulder defaults to 0.0f, lshoulder defaults to @param next.
 * 
 * @param arg0:
 * @param arg1: todo/fixme/hack: unsure of arg1 type.
 * @param same: When set, both shoulders will receive lshoulder value. Only
 *     applies with @param swap is set.
 * @param swap: When set, aimendrshoulder will get the calculated lshoulder value,
 *     and aimendlshoulder will get the rshoulder value. If both @param swap and
 *     @param same is set they will both be set to lshoulder value.
 * @param next: Starting aimendlshoulder value.
 * 
 * Address 0x7F02D048.
*/
void chrlvUpdateAimendbackShoulders(ChrRecord *arg0, void *arg1, s32 same, s32 swap, f32 next)
{
    f32 next_lshoulder;
    f32 next_rshoulder;
    f32 next_aimendback;

    next_rshoulder = 0.0f;
    next_aimendback = 0.0f;
    next_lshoulder = next;

    if (arg1 != NULL)
    {
        if (((f32*)arg1)[12] < next)
        {
            next_aimendback = next - ((f32*)arg1)[12];
            next_lshoulder = ((f32*)arg1)[12];
        }

        else if (next < ((f32*)arg1)[13])
        {
            next_aimendback = next - ((f32*)arg1)[13];
            next_lshoulder = ((f32*)arg1)[13];
        }

        if (next_lshoulder > 0.0f)
        {
            next_rshoulder = ((f32*)arg1)[16] * next_lshoulder;
        }
        else
        {
            next_rshoulder = ((f32*)arg1)[17] * next_lshoulder;
        }
    }

    if (swap != 0)
    {
        arg0->aimendrshoulder = next_lshoulder;

        if (same != 0)
        {
            arg0->aimendlshoulder = next_lshoulder;
        }
        else
        {
            arg0->aimendlshoulder = next_rshoulder;
        }
    }
    else
    {
        arg0->aimendrshoulder = next_rshoulder;
        arg0->aimendlshoulder = next_lshoulder;
    }

    arg0->aimendback = next_aimendback;
}





/**
 * Address 0x7F02D0F8.
*/
void chrlvResetAimend(struct ChrRecord *arg0)
{
    arg0->aimendcount = 0xA;
    arg0->aimendrshoulder = 0.0f;
    arg0->aimendlshoulder = 0.0f;
    arg0->aimendback = 0.0f;
    arg0->aimendsideback = 0.0f;
}



/**
 * Address 0x7F02D118.
*/
void sub_GAME_7F02D118(ChrRecord *arg0, s32 hand, s32 arg2)
{
    PropRecord *temp_v0;

    temp_v0 = something_with_weaponpos_of_guarddata_hand(arg0, hand);

    if (temp_v0 != NULL)
    {
        sub_GAME_7F052574(temp_v0, arg2);
    }
}



/**
 * Unreferenced.
 * 
 * Address 0x7F02D148.
*/
s32 sub_GAME_7F02D148(ChrRecord *arg0, s32 hand)
{
    PropRecord *temp_v0;

    temp_v0 = something_with_weaponpos_of_guarddata_hand(arg0, hand);

    if (temp_v0 != NULL)
    {
        return sub_GAME_7F052604(temp_v0);
    }

    return 0;
}


/**
 * Address 0x7F02D184.
*/
void sub_GAME_7F02D184(struct ChrRecord *arg0)
{
    sub_GAME_7F02D118(arg0, RIGHT_HAND, 0);
    sub_GAME_7F02D118(arg0, LEFT_HAND, 0);
    chrlvResetAimend(arg0);
}


/**
 * Address 0x7F02D1C4.
*/
void chrlvToggleHiddenRelated(ChrRecord *arg0, s32 hand, s32 arg2)
{
    if (arg2 != 0)
    {
        if (hand == LEFT_HAND)
        {
            arg0->hidden |= CHRHIDDEN_FIRE_WEAPON_LEFT;
        }
        else
        {
            arg0->hidden |= CHRHIDDEN_FIRE_WEAPON_RIGHT;
        }
    }
    else if (hand == LEFT_HAND)
    {
        arg0->hidden &= 0xFFFB; // CHRHIDDEN_FIRE_WEAPON_LEFT
    }
    else
    {
        arg0->hidden &= 0xFFF7; // CHRHIDDEN_FIRE_WEAPON_RIGHT
    }

    if (arg2 == 0)
    {
        sub_GAME_7F02D118(arg0, hand, 0);
    }
}




/**
 * Address 0x7F02D244.
*/
f32 chrlvGetAimLimitAngle(f32 sqdist)
{
    if (sqdist > (1600.0f * 1600.0f))
    {
        return (M_PI_F / 167.5f);
    }

    if (sqdist > (800.0f * 800.0f))
    {
        return (M_PI_F / 83.5f);
    }

    if (sqdist > (400.0f * 400.0f))
    {
        return (M_PI_F / 42.0f);
    }

    if (sqdist > (200.0f * 200.0f))
    {
        return (M_PI_F / 21.0f);
    }

    return (M_PI_F / 12.5f);
}



/**
 * @param arg0:
 * @param arg1: out parameter. bool. Whether or not self has correct line of site to hit player.
 * @param arg2: out parameter. bool. True if damage done, false otherwise.
 * @param item: weapon doing damage
 * 
 * Address 0x7F02D2E4.
*/
void chrlvUpdateShotbondsum(ChrRecord *arg0, s32 *arg1, s32 *arg2, ITEM_IDS item)
{
    f32 limit_angle;
    f32 dxdydz_square;
    f32 dx; // sp84
    f32 dy; // sp80
    f32 dz; // sp76
    f32 atan; // sp72
    f32 subroty; // sp68
    f32 phi_f2; // sp64
    PropRecord *player_prop;
    f32 temp_f0_3;
    PropRecord *self_prop;
    f32 t2; // sp48
    f32 phi_f2_4; // sp44
    s32 padding; // unused
    s32 phi_v1;

    player_prop = get_curplayer_positiondata();
    self_prop = arg0->prop;

    dx = player_prop->pos.f[0] - self_prop->pos.f[0];
    dy = player_prop->pos.f[1] - self_prop->pos.f[1];
    dz = player_prop->pos.f[2] - self_prop->pos.f[2];
    
    atan = atan2f(dx, dz);
    subroty = chrlvGetSubrotySideback(arg0);
    phi_f2 = atan - subroty;
    dxdydz_square = (dx * dx) + (dy * dy) + (dz * dz);
    
    limit_angle = chrlvGetAimLimitAngle(dxdydz_square);

    if (phi_f2 < 0.0f)
    {
        phi_f2 += M_TAU;
    }

    phi_v1 = (phi_f2 < limit_angle);

    if ((phi_f2 < limit_angle) == 0)
    {
        phi_v1 = ((M_TAU - limit_angle) < phi_f2);
    }

    *arg1 = phi_v1;
    *arg2 = 0;

    if ((bondviewGetIfCurrentPlayerDamageShowTime() == 0) && (phi_v1 != 0))
    {
        temp_f0_3 = sqrtf(dxdydz_square);

#if defined(VERSION_JP)
        phi_f2_4 = 0.16f * g_JP_GlobalTimerDelta;
#else
        phi_f2_4 = 0.16f * g_GlobalTimerDelta;
#endif

        if (temp_f0_3 > 300.0f)
        {
            phi_f2_4 *= (300.0f / temp_f0_3);
        }

        if ((s32) arg0->accuracyrating > 0)
        {
            phi_f2_4 *= (1.0f + ((f32) arg0->accuracyrating / 10.0f));
        }
        else if ((s32) arg0->accuracyrating < 0)
        {
            if ((s32) arg0->accuracyrating < -0x63)
            {
                phi_f2_4 = 0.0f;
            }
            else
            {
                phi_f2_4 *= ((f32) (arg0->accuracyrating + 0x64) / 100.0f);
            }
        }

        if (get_007_accuracy_mod() <= 1.0f)
        {
            phi_f2_4 *= get_007_accuracy_mod();
        }
        else
        {
            phi_f2_4 *= (9.0f / (10.001f - get_007_accuracy_mod()));
        }

        phi_f2_4 *= g_AiAccuracyModifier;

        if (bondwalkItemGetAutomaticFiringRate(item) <= 0)
        {
            phi_f2_4 *= 2.0f;
        }

        if ((item == ITEM_SHOTGUN) || (item == ITEM_AUTOSHOT))
        {
            phi_f2_4 *= 2.0f;
        }

        arg0->shotbondsum += phi_f2_4;

        if (arg0->shotbondsum >= 1.0f)
        {
            t2 = (0.125f * bondwalkItemGetDestructionAmount(item) * g_AiDamageModifier) * get_007_damage_mod();

            if ((item == ITEM_SHOTGUN) || (item == ITEM_AUTOSHOT))
            {
                t2 *= 3.0f;
            }

            bondviewCallRecordDamageKills(t2, subroty, -1, 1);

            arg0->shotbondsum = 0.0f;

            if (bondviewGetIfCurrentPlayerDamageShowTime() != 0)
            {
                *arg2 = 1;
            }
        }
    }
}


/**
 * Slight modification of a part of @see chrlvUpdateAimendsideback.
 * 
 * Address 0x7F02D630.
*/
s32 sub_GAME_7F02D630(ChrRecord *arg0, HANDEDNESS hand, struct coord3d *arg2)
{
    struct ObjectRecord *obj;
    PropRecord *weapon_prop;
    Model *weapon_prop_model; // sp188
    s32 ret;
    Mtxf *temp_a0; // sp180
    Mtxf sp74;
    f32 *spB8;
    Mtxf *temp_a0_2; // sp108
    Mtxf sp68; // sp44
    
    weapon_prop = something_with_weaponpos_of_guarddata_hand(arg0, hand);
    ret = 0;

    if ((weapon_prop != NULL) )
    {
        obj = weapon_prop->obj;
        weapon_prop_model = obj->model;

        if ((weapon_prop->flags & 2))
        {
            if (weapon_prop_model->obj->Switches[0])
            {
                temp_a0 = sub_GAME_7F06C660(weapon_prop_model, weapon_prop_model->obj->Switches[0], 0);
                spB8 = weapon_prop_model->obj->Switches[0]->Data;

                arg2->f[0] = spB8[0];
                arg2->f[1] = spB8[1];
                arg2->f[2] = spB8[2];

                matrix_4x4_multiply_homogeneous(currentPlayerGetMatrix10D4(), temp_a0, &sp74);
                matrix_4x4_transform_vector_in_place(&sp74, (f32*) arg2);

                ret = 1;
            }
            else if (weapon_prop_model->obj->Switches[1])
            {
                temp_a0_2 = sub_GAME_7F06C660(weapon_prop_model, weapon_prop_model->obj->Switches[1], 0);
                matrix_4x4_multiply_homogeneous(currentPlayerGetMatrix10D4(), temp_a0_2, &sp68);

                arg2->f[0] = sp68.m[3][0];
                arg2->f[1] = sp68.m[3][1];
                arg2->f[2] = sp68.m[3][2];

                ret = 1;
            }
        }
    }

    return ret;
}



/**
 * Address 0x7F02D734.
*/
void chrlvFireWeaponRelated(ChrRecord *self, s32 hand)
{
    struct PropRecord *self_prop; // 644
    s32 phi_a2; // ?
    s32 sp27C; // stack 636
    s32 sp278;
    ChrRecord *prop_selfchr; // 628
    PropRecord *player_prop; // 624
    s32 phi_v1; // ?
    s32 sp268; // 616
    s32 sp264; // 612
    struct coord3d sp258; // 600
    StandTile *sp254; // 596
    f32 subroty; // 592
    f32 sp24C; // 588
    struct coord3d sp240; // 576
    struct StandTile *self_stan; // 572
    struct StandTile *sp238; // 568
    s32 sp234; // 564
    s32 sp230; // 560
    s32 sp22C; // 556
    struct coord3d sp220;
    s32 sp21C;
    f32 dy;
    f32 dz;
    f32 dx;
    f32 sp20C; // 524
    struct WeaponObjRecord *sp208;
    Mtxf sp1C8;
    struct coord3d sp1BC;  // 444
    PropRecord *weapon_prop;
    struct coord3d sp1AC; // 428
    Mtxf sp16C;
    Mtxf sp12C;
    struct WeaponObjRecord *sp128; // 296
    Mtxf spE8;
    struct coord3d spDC; // 220
    Mtxf sp9C;
    Mtxf sp5C; // 92
    s32 sp44;
    struct ObjectRecord_f6c * temp_v0_4;
    f32 sp4C;
    
    self_prop = self->prop;
    weapon_prop = something_with_weaponpos_of_guarddata_hand(self, hand);

    if (weapon_prop != NULL)
    {
        sp27C = 0;
        sp278 = 0;
        prop_selfchr = weapon_prop->chr;
        player_prop = get_curplayer_positiondata();
        phi_v1 = 1;

        if (self->actiontype == ACT_ATTACK)
        {
            phi_v1 = self->act_attack.attacktype;
        }

        sp44 = phi_v1 & 1;

        if (
            (sp44 == 0)
            || (self->seen_bond_time >= (g_GlobalTimer - 0x78))
            || (bondwalkItemGetAutomaticFiringRate(prop_selfchr->act_attack.attack_item) < 0))
        {
            sp268 = 0;
            sp264 = 0;
            
            self->firecount[hand]++;

            if (bondwalkItemGetAutomaticFiringRate(prop_selfchr->act_attack.attack_item) < 0)
            {
                sp268 = 1;
                sp264 = 1;
            }
            else if (((s32) self->firecount[hand] % bondwalkItemGetAutomaticFiringRate(prop_selfchr->act_attack.attack_item)) == 0)
            {
                sp268 = 1;

                if ((((s32) self->firecount[hand] % (s32) (bondwalkItemGetAutomaticFiringRate(prop_selfchr->act_attack.attack_item) * 2)) == 0) 
                    || (prop_selfchr->act_attack.attack_item == ITEM_LASER))
                {
                    sp264 = 1;
                }
            }
            else
            {
                sp278 = 1;
            }

            if (sp268 != 0)
            {
                sp254 = NULL;
                subroty = chrlvGetSubrotySideback(self);
                sp24C = sub_GAME_7F02C27C(self);
                self_stan = self_prop->stan;
                sp27C = 1;

                if (sub_GAME_7F02D630(self, hand, (struct coord3d *) &sp240) == 0)
                {
                    sp240.f[0] = self_prop->pos.f[0];
                    sp240.f[1] = self_prop->pos.f[1] + 30.0f;
                    sp240.f[2] = self_prop->pos.f[2];

                    if (hand == 1)
                    {
                        sp240.f[0] += cosf(subroty) * 10.0f;
                        sp240.f[2] += -sinf(subroty) * 10.0f;
                    }
                    else
                    {
                        sp240.f[0] += -cosf(subroty) * 10.0f;
                        sp240.f[2] += sinf(subroty) * 10.0f;
                    }
                }

                if (sub_GAME_7F0B0E24(&self_stan, self_prop->pos.x, self_prop->pos.f[2], sp240.f[0], sp240.f[2], 2, sp240.f[1] - self->ground, sp240.f[1] - self->ground, 0.0f, 1.0f) != 0)
                {
                    sp238 = self_stan;
                }
                else
                {
                    self->firecount[hand]--;
                    sp27C = 0;
                }

                if (sp27C != 0)
                {
                    sp234 = 0;
                    sp230 = 0;
                    sp22C = 1;
                    
                    sp21C = chrlvAttackRelated7F0292A8(self, &sp240, sp238);
                    
                    sp220.f[0] = cosf(sp24C) * sinf(subroty);
                    sp220.f[1] = sinf(sp24C);
                    sp220.f[2] = cosf(sp24C) * cosf(subroty);
                    
                    sp258.f[0] = sp240.f[0] + (sp220.f[0] * 65536.0f);
                    sp258.f[1] = sp240.f[1] + (sp220.f[1] * 65536.0f);
                    sp258.f[2] = sp240.f[2] + (sp220.f[2] * 65536.0f);
                    
                    set_or_unset_GUARDdata_flag(self, 0);
                    sub_GAME_7F0B1CC4();
                    self_stan = sp238;

                    if (sub_GAME_7F0B0E24(&self_stan, sp240.f[0], sp240.f[2], sp258.f[0], sp258.f[2], 0x1B, sp240.f[1], sp240.f[1], sp258.f[1], sp258.f[1]) == 0)
                    {
                        chrlvStanLineDirIntersection(&sp240, &sp220, &sp258);
                        sp254 = self_stan;
                        sp258.f[0] -= 26.0f * sp220.f[0];
                        sp258.f[1] -= 26.0f * sp220.f[1];
                        sp258.f[2] -= 26.0f * sp220.f[2];
                    }

                    set_or_unset_GUARDdata_flag(self, 1);

                    dx = sp258.f[0] - sp240.f[0];
                    dy = sp258.f[1] - sp240.f[1];
                    dz = sp258.f[2] - sp240.f[2];
                    
                    sp20C = (dx * dx) + (dy * dy) + (dz * dz);

                    if (prop_selfchr->act_attack.attack_item == ITEM_ROCKETLAUNCH)
                    {
                        if (((dx * dx) + (dy * dy) + (dz * dz)) > 160000.0f)
                        {
                            sp208 = create_new_item_instance_of_model(PROP_chrrocket, 0x56);
                            if (sp208 != NULL)
                            {
                                matrix_4x4_set_identity(&sp1C8);
                                matrix_4x4_set_rotation_around_x(sp24C, &sp16C);
                                matrix_4x4_set_rotation_around_y(subroty, &sp12C);
                                matrix_4x4_multiply_homogeneous_in_place(&sp12C, &sp16C);
                                
                                sp1AC.f[0] = sp220.f[0] * 1.111111f;
                                sp1AC.f[1] = sp220.f[1] * 1.111111f;
                                sp1AC.f[2] = sp220.f[2] * 1.111111f;

                                sp1BC.f[0] = sp1AC.f[0] * g_GlobalTimerDelta;
                                sp1BC.f[1] = sp1AC.f[1] * g_GlobalTimerDelta;
                                sp1BC.f[2] = sp1AC.f[2] * g_GlobalTimerDelta;

                                sub_GAME_7F05EB0C(sp208, &sp240, sp238, &sp16C, &sp1BC, &sp1C8, self_prop);
                                
                                if (sp208->base.runtime_bitflags & RUNTIMEBITFLAG_DEPOSIT)
                                {
                                    sp208->base.unk6C->id |= 0x80;
                                    sp208->timer = -1;
                                    sp208->base.unk6C->id |= 0x20;

                                    sp208->base.unk6C->unkb0 = sp208->base.runtime_y_pos;
                                    sp208->base.unk6C->unkb4 = sp208->base.unk6C->pos.f[1];

                                    sp208->base.unk6C->vec[0] = sp1AC.f[0];
                                    sp208->base.unk6C->vec[1] = sp1AC.f[1];
                                    sp208->base.unk6C->vec[2] = sp1AC.f[2];
                                    
                                    if (sp208->base.unk6C->unk98 == NULL)
                                    {
                                        sndPlaySfx(g_musicSfxBufferPtr, 1, &sp208->base.unk6C->unk98);
                                    }
                                    else if (sp208->base.unk6C->unk9c == NULL)
                                    {
                                        sndPlaySfx(g_musicSfxBufferPtr, 1, &sp208->base.unk6C->unk9c);
                                    }
                                }
                            }
                        }
                        else
                        {
                            sp27C = 0;
                        }
                    }
                    else if (prop_selfchr->act_attack.attack_item == ITEM_GRENADELAUNCH)
                    {
                        if (((dx * dx) + (dy * dy) + (dz * dz)) > 160000.0f)
                        {
                            sp128 = (struct WeaponObjRecord *)create_new_item_instance_of_model(PROP_chrgrenaderound, 0x57);
                            if (sp128 != NULL)
                            {
                                matrix_4x4_set_identity(&spE8);
                                spDC.f[0] = sp220.f[0] * 33.333332f;
                                spDC.f[1] = sp220.f[1] * 33.333332f;
                                spDC.f[2] = sp220.f[2] * 33.333332f;
                                matrix_4x4_set_rotation_around_x(sp24C, &sp9C);
                                matrix_4x4_set_rotation_around_y(subroty, &sp5C);
                                matrix_4x4_multiply_homogeneous_in_place(&sp5C, &sp9C);
                                sp128->timer = 0xB4;
                                sub_GAME_7F05EB0C((ObjectRecord *) sp128, &sp240, sp238, &sp9C, &spDC, &spE8, self_prop);
                                
                                if (sp128->base.runtime_bitflags & RUNTIMEBITFLAG_DEPOSIT)
                                {
                                    sp128->base.unk6C->unk8c = 0.3f;
                                    sp128->base.unk6C->unk94 = 0.13333333f;
                                    sp128->base.unk6C->unkbc = 0x3C;
                                }
                            }
                        }
                        else
                        {
                            sp27C = 0;
                        }
                    }
                    else
                    {
                        if ((sp44 != 0) && (sp21C != 0))
                        {
                            dx = (player_prop->pos.f[0] - sp240.f[0]) - (sp220.f[0] * 15.0f);
                            dy = (player_prop->pos.f[1] - sp240.f[1]) - (sp220.f[1] * 15.0f);
                            dz = (player_prop->pos.f[2] - sp240.f[2]) - (sp220.f[2] * 15.0f);
                            
                            if (((dx * dx) + (dy * dy) + (dz * dz)) <= sp20C)
                            {
                                chrlvUpdateShotbondsum(self, &sp234, &sp230, prop_selfchr->act_attack.attack_item);
                                sp22C = sp230 == 0;
                                
                                if ((sp234 != 0) && ((self->actiontype == ACT_ATTACK) || (self->actiontype == ACT_ATTACKROLL)))
                                {
                                    self->act_attack.attack_time = g_GlobalTimer;
                                }
                            }
                        }
                        else
                        {
                            if ((self->actiontype == ACT_ATTACK) || (self->actiontype == ACT_ATTACKROLL))
                            {
                                self->act_attack.attack_time = g_GlobalTimer;
                            }
                        }

                        if (sp230 != 0)
                        {
                            sp258.f[0] = player_prop->pos.f[0];
                            sp258.f[1] = player_prop->pos.f[1];
                            sp258.f[2] = player_prop->pos.f[2];
                            sp254 = player_prop->stan;
                            recall_joy2_hits_edit_detail_edit_flag(prop_selfchr->act_attack.attack_item, &player_prop->type, -1);
                        }
                        else
                        {
                            if ((
                                    (stanSavedColl_posData == NULL) 
                                    || ((stanSavedColl_posData->type != PROP_TYPE_CHR) && (stanSavedColl_posData->type != PROP_TYPE_VIEWER))
                                ) 
                                && (sp20C < 10000.0f))
                            {
                                sp22C = 0;
                            }
                        }

                        if (sp22C != 0)
                        {
                            if (sp254 != 0)
                            {
                                sub_GAME_7F0A3E1C(&sp258, 1, 26.0f, (s16) sp254->room);
                            }

                            if (stanSavedColl_posData != NULL)
                            {
                                recall_joy2_hits_edit_detail_edit_flag(prop_selfchr->act_attack.attack_item, &stanSavedColl_posData->type, -1);

                                if (stanSavedColl_posData->type == PROP_TYPE_CHR)
                                {
                                    if ((self->chrflags & 0x40) != 0)
                                    {
                                        handles_shot_actors(stanSavedColl_posData->chr, 0xF, &sp220, prop_selfchr->act_attack.attack_item, 0);
                                    }
                                }
                                else if ((stanSavedColl_posData->type == PROP_TYPE_OBJ) || (stanSavedColl_posData->type == PROP_TYPE_WEAPON))
                                {
                                    chrobjMaybeDetonateObjectIfFlags(
                                        stanSavedColl_posData->obj,
                                        bondwalkItemGetDestructionAmount(prop_selfchr->act_attack.attack_item),
                                        &sp258,
                                        prop_selfchr->act_attack.attack_item,
                                        get_cur_playernum());
                                }
                            }
                            else
                            {
                                recall_joy2_hits_edit_flag(prop_selfchr->act_attack.attack_item, &sp258, -1);
                            }
                        }

                        if (sp264 != 0)
                        {
                            switch (prop_selfchr->act_attack.attack_item) 
                            {
                                case ITEM_WPPK:
                                case ITEM_WPPKSIL:
                                case ITEM_TT33:
                                case ITEM_SKORPION:
                                case ITEM_AK47:
                                case ITEM_UZI:
                                case ITEM_MP5K:
                                case ITEM_MP5KSIL:
                                case ITEM_SPECTRE:
                                case ITEM_M16:
                                case ITEM_FNP90:
                                case ITEM_RUGER:
                                case ITEM_GOLDENGUN:
                                case ITEM_SILVERWPPK:
                                case ITEM_GOLDWPPK:
                                case ITEM_LASER:
                                    sp264 = 1;
                                    break;

                                default:
                                    sp264 = 0;
                                    break;
                            }
                        }

                        if (sp264 != 0)
                        {
                            sub_GAME_7F061948(&self->unk180[hand], prop_selfchr->act_attack.attack_item, &sp240, &sp258);
                        }
                    }
                }
            }

            phi_a2 = (sp27C != 0) || (sp278 != 0);

            sub_GAME_7F02BFE4(self, hand, phi_a2);
        }

        sub_GAME_7F02D118(self, hand, sp27C);
    }
}



/**
 * Address 0x7F02E26C.
*/
void chrlvTriggerFireWeapon(ChrRecord *arg0)
{
    arg0->hidden &= 0xFF7F; // CHRHIDDEN_FIRE_WEAPON_RIGHT

    if (arg0->hidden & CHRHIDDEN_FIRE_WEAPON_RIGHT)
    {
        chrlvFireWeaponRelated(arg0, RIGHT_HAND);

        arg0->hidden &= 0xFFF7; // CHRHIDDEN_FIRE_WEAPON_RIGHT
    }

     if (arg0->hidden & CHRHIDDEN_FIRE_WEAPON_LEFT)
    {
        chrlvFireWeaponRelated(arg0, LEFT_HAND);

        arg0->hidden &= 0xFFFB; // CHRHIDDEN_FIRE_WEAPON_LEFT
    }
}



/**
 * Address 0x7F02E2E0.
*/
s32 chrlvAttackrollAnimationRelated7F02E2E0(ChrRecord *arg0)
{
    Model *model;
    struct weapon_firing_animation_table *p;
    s32 sp24;

    if ((arg0->act_attackroll.animfloats == &D_80030078[2]) || (arg0->act_attackroll.animfloats == &D_80030078[3]))
    {
        model = arg0->model;
        sp24 = (s32) model->gunhand;
        arg0->act_attackroll.unk30 = 2;
        arg0->act_attackroll.animfloats = &D_80030078[1];
        arg0->sleep = 0;

        p = &D_80030078[1];

        objecthandlerAnimationRelated7F06FCA8(
            model,
            (void *) p->anonymous_0,
            sp24,
            p->anonymous_7,
            chrlvGetGuard007SpeedRating(arg0, 0.7f, 1.12f),
            22.0f);

        if (D_80030078[1].anonymous_5 >= 0.0f)
        {
            sub_GAME_7F06FDE8(model, D_80030078[1].anonymous_5);
        }

        return 1;
    }

    return 0;
}





/**
 * Address 0x7F02E3B8.
*/
void chrlvAttackrollAnimationRelated7F02E3B8(ChrRecord *arg0)
{
    Model *model;

    model = arg0->model;

    if (arg0->act_attackroll.animfloats->anonymous_9 > 0.0f)
    {
        objecthandlerAnimationRelated7F06FCA8(
            model,
            objecthandlerGetModelAnim(model),
            (s32) model->gunhand,
            arg0->act_attackroll.animfloats->anonymous_9,
            chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f),
            8.0f);
    }
    else
    {
        objecthandlerAnimationRelated7F06FCA8(
            model,
            objecthandlerGetModelAnim(model),
            (s32) model->gunhand,
            arg0->act_attackroll.animfloats->anonymous_7,
            chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f),
            8.0f);
    }

    if (arg0->act_attackroll.animfloats->anonymous_5 >= 0.0f)
    {
        sub_GAME_7F06FDE8(model, arg0->act_attackroll.animfloats->anonymous_5);
    }
}



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
/* 0630B8 7F02E588 0FC0B8B8 */  jal   chrlvAttackrollAnimationRelated7F02E2E0
/* 0630BC 7F02E58C 02002025 */   move  $a0, $s0
/* 0630C0 7F02E590 1440001E */  bnez  $v0, .L7F02E60C
/* 0630C4 7F02E594 00000000 */   nop   
/* 0630C8 7F02E598 0FC1BD6B */  jal   objecthandlerGetModelAnim
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
/* 063144 7F02E614 0FC0B8EE */  jal   chrlvAttackrollAnimationRelated7F02E3B8
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
/* 0631A8 7F02E678 0FC0B8B8 */  jal   chrlvAttackrollAnimationRelated7F02E2E0
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
/* 0631EC 7F02E6BC 0FC0B8EE */  jal   chrlvAttackrollAnimationRelated7F02E3B8
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
/* 06330C 7F02E7DC 0FC1BD6B */  jal   objecthandlerGetModelAnim
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
/* 063400 7F02E8D0 0FC0B0AC */  jal   chrlvSetSubroty
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
/* 06344C 7F02E91C 0FC0B130 */  jal   chrlvUpdateAimendsideback
/* 063450 7F02E920 E7A60010 */   swc1  $f6, 0x10($sp)
/* 063454 7F02E924 10000004 */  b     .L7F02E938
/* 063458 7F02E928 00008825 */   move  $s1, $zero
.L7F02E92C:
/* 06345C 7F02E92C 0FC0B43E */  jal   chrlvResetAimend
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
/* 0634C8 7F02E998 0FC0B471 */  jal   chrlvToggleHiddenRelated
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
/* 0635A8 7F02EA78 0FC0B471 */  jal   chrlvToggleHiddenRelated
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
/* 0636CC 7F02EB9C 0FC0B471 */  jal   chrlvToggleHiddenRelated
/* 0636D0 7F02EBA0 AE0F0044 */   sw    $t7, 0x44($s0)
/* 0636D4 7F02EBA4 10000008 */  b     .L7F02EBC8
/* 0636D8 7F02EBA8 26310001 */   addiu $s1, $s1, 1
.L7F02EBAC:
/* 0636DC 7F02EBAC 0FC0B471 */  jal   chrlvToggleHiddenRelated
/* 0636E0 7F02EBB0 02202825 */   move  $a1, $s1
/* 0636E4 7F02EBB4 10000004 */  b     .L7F02EBC8
/* 0636E8 7F02EBB8 26310001 */   addiu $s1, $s1, 1
.L7F02EBBC:
/* 0636EC 7F02EBBC 0FC0B471 */  jal   chrlvToggleHiddenRelated
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
/* 060FAC 7F02E5BC 0FC0B8C5 */  jal   chrlvAttackrollAnimationRelated7F02E2E0
/* 060FB0 7F02E5C0 02002025 */   move  $a0, $s0
/* 060FB4 7F02E5C4 1440001E */  bnez  $v0, .L7F02E640
/* 060FB8 7F02E5C8 00000000 */   nop   
/* 060FBC 7F02E5CC 0FC1BDD3 */  jal   objecthandlerGetModelAnim
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
/* 061038 7F02E648 0FC0B8FB */  jal   chrlvAttackrollAnimationRelated7F02E3B8
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
/* 06109C 7F02E6AC 0FC0B8C5 */  jal   chrlvAttackrollAnimationRelated7F02E2E0
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
/* 0610E0 7F02E6F0 0FC0B8FB */  jal   chrlvAttackrollAnimationRelated7F02E3B8
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
/* 061200 7F02E810 0FC1BDD3 */  jal   objecthandlerGetModelAnim
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
/* 0612F4 7F02E904 0FC0B0B9 */  jal   chrlvSetSubroty
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
/* 061340 7F02E950 0FC0B13D */  jal   chrlvUpdateAimendsideback
/* 061344 7F02E954 E7A60010 */   swc1  $f6, 0x10($sp)
/* 061348 7F02E958 10000004 */  b     .L7F02E96C
/* 06134C 7F02E95C 00008825 */   move  $s1, $zero
.L7F02E960:
/* 061350 7F02E960 0FC0B44B */  jal   chrlvResetAimend
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
/* 0613BC 7F02E9CC 0FC0B47E */  jal   chrlvToggleHiddenRelated
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
/* 0614B4 7F02EAC4 0FC0B47E */  jal   chrlvToggleHiddenRelated
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
/* 0615D8 7F02EBE8 0FC0B47E */  jal   chrlvToggleHiddenRelated
/* 0615DC 7F02EBEC AE0F0044 */   sw    $t7, 0x44($s0)
/* 0615E0 7F02EBF0 10000008 */  b     .L7F02EC14
/* 0615E4 7F02EBF4 26310001 */   addiu $s1, $s1, 1
.L7F02EBF8:
/* 0615E8 7F02EBF8 0FC0B47E */  jal   chrlvToggleHiddenRelated
/* 0615EC 7F02EBFC 02202825 */   move  $a1, $s1
/* 0615F0 7F02EC00 10000004 */  b     .L7F02EC14
/* 0615F4 7F02EC04 26310001 */   addiu $s1, $s1, 1
.L7F02EC08:
/* 0615F8 7F02EC08 0FC0B47E */  jal   chrlvToggleHiddenRelated
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


/**
 * Address 0x7F02EBFC (VERSION_US).
 * Adresss 0x7F02EF04 (other).
*/
void chrlvTickAttack(ChrRecord *arg0)
{
    Model *self_model;
    f32 temp_f0;
    f32 phi_f2;

    self_model = arg0->model;
    temp_f0 = objecthandlerGetModelField28(self_model);

    if (arg0->act_attack.type_of_motion)
    {
        if (arg0->act_attack.type_of_motion == 1)
        {
            if (arg0->act_attack.animfloats->anonymous_9 >= 0.0f)
            {
                phi_f2 = arg0->act_attack.animfloats->anonymous_9;
            }
            else
            {
                phi_f2 = arg0->act_attack.animfloats->anonymous_7;
            }

            objecthandlerAnimationRelated7F06FCA8(
                self_model,
                objecthandlerGetModelAnim(self_model),
                (s32) self_model->gunhand,
                phi_f2,
                chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f),
                16.0f);
            
            if (arg0->act_attack.animfloats->anonymous_5 >= 0.0f)
            {
                sub_GAME_7F06FDE8(self_model, arg0->act_attack.animfloats->anonymous_5);
            }

            arg0->act_attack.type_of_motion = 2;
            chrlvResetAimend(arg0);

            return;
        }

        if (arg0->act_attack.type_of_motion == 2)
        {
            if (sub_GAME_7F06F5C4(self_model) <= temp_f0)
            {
#if defined(VERSION_US)
                arg0->act_attack.attacktype |= 0x20;
#else
                // don't set 0x20
#endif
                arg0->act_attack.attacktype &= ~0x40;

                if (arg0->act_attack.unk54 != 0)
                {
                    sub_GAME_7F025560(arg0, (s32) arg0->act_attack.attacktype, arg0->act_attack.entityid);

                    return;
                }

                sub_GAME_7F0256F0(arg0, (s32) arg0->act_attack.attacktype, arg0->act_attack.entityid);

                return;
            }

            return;
        }
    }

    if ((arg0->act_attack.attacktype & 0x20) != 0)
    {
        if ((arg0->act_attack.attacktype & 0x40) != 0)
        {
            if (chrlvUpdateAimendsideback(arg0, arg0->act_attack.animfloats, (s32) arg0->act_attack.unk39, (s32) arg0->act_attack.unk38, 0.2f) == 0)
            {
                arg0->act_attack.type_of_motion = 1;
            }

            return;
        }

        if (sub_GAME_7F06F5C4(self_model) <= temp_f0)
        {
            arg0->act_attack.attacktype |= 0x40;
            arg0->act_attack.unk30 = 2;

            return;
        }
    }

    if (arg0->act_attack.unk36 == 0)
    {
        if ((arg0->act_attack.animfloats->anonymous_9 > 0.0f) && (temp_f0 <= arg0->act_attack.animfloats->anonymous_9))
        {
            if (sub_GAME_7F06F5C4(self_model) <= temp_f0)
            {
                objecthandlerAnimationRelated7F06FCA8(
                    self_model,
                    objecthandlerGetModelAnim(self_model),
                    (s32) self_model->gunhand,
                    arg0->act_attack.animfloats->anonymous_9,
                    chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f),
                    16.0f);
                
                if (arg0->act_attack.unk37 != 0)
                {
                    if (arg0->act_attack.animfloats->anonymous_5 >= 0.0f)
                    {
                        sub_GAME_7F06FDE8(self_model, arg0->act_attack.animfloats->anonymous_5);
                    }
                }
                else
                {
                    sub_GAME_7F06FDE8(self_model, arg0->act_attack.animfloats->anonymous_7);
                }
            }
        }
    }

    sub_GAME_7F02E4C0(arg0);
}





/**
 * Address 0x7F02EEE0.
*/
void chrlvTickAttackRoll(ChrRecord *arg0)
{
    Model *temp_a0; // 68
    f32 temp_f0;
    struct weapon_firing_animation_table *phi_v1; // 60
    s32 sp38; // 56
    f32 phi_f2_2; // 52
    ChrRecord *temp_v0_2;
    struct weapon_firing_animation_table *temp_v0;

    if (arg0->act_attackroll.unk35 != 0)
    {
        temp_a0 = arg0->model;
        temp_f0 = objecthandlerGetModelField28(temp_a0);

        if (
            (arg0->act_attackroll.animfloats == &D_80030078[4])
            || (arg0->act_attackroll.animfloats == &D_80030078[5])
            || (arg0->act_attackroll.animfloats == &D_80030078[6])
            || (arg0->act_attackroll.animfloats == &D_80030078[7])
        )
        {
            if (arg0->act_attackroll.animfloats->anonymous_5 <= temp_f0)
            {
                sp38 = (s32) temp_a0->gunhand;
                phi_v1 = &arg0->act_attackroll.animfloats[4];

                phi_f2_2 = 16.0f;

                if ((arg0->act_attackroll.unk39 != 0) && (arg0->act_attackroll.unk38 != 0))
                {
                    if ((randomGetNext() & 1) == 0)
                    {
                        phi_v1 = &phi_v1[4];
                    }
                    else
                    {
                        phi_v1 = &phi_v1[8];
                    }
                }

                if (phi_v1 == &D_80030078[8])
                {
                    phi_f2_2 = 24.0f;
                }
                else if (phi_v1 == &D_80030078[9])
                {
                    phi_f2_2 = 24.0f;
                }
                else if (phi_v1 == &D_80030078[10])
                {
                    phi_f2_2 = 32.0f;
                }
                else if (phi_v1 == &D_80030078[11])
                {
                    phi_f2_2 = 44.0f;
                }
                else if (phi_v1 == &D_80030078[12])
                {
                    phi_f2_2 = 24.0f;
                }
                else if (phi_v1 == &D_80030078[13])
                {
                    phi_f2_2 = 34.0f;
                }
                else if (phi_v1 == &D_80030078[14])
                {
                    phi_f2_2 = 32.0f;
                }
                else if (phi_v1 == &D_80030078[15])
                {
                    phi_f2_2 = 44.0f;
                }
                else if (phi_v1 == &D_80030078[16])
                {
                    phi_f2_2 = 24.0f;
                }
                else if (phi_v1 == &D_80030078[17])
                {
                    phi_f2_2 = 34.0f;
                }
                else if (phi_v1 == &D_80030078[18])
                {
                    phi_f2_2 = 32.0f;
                }
                else if (phi_v1 == &D_80030078[19])
                {
                    phi_f2_2 = 44.0f;
                }

                arg0->act_attackroll.unk30 = 2;
                arg0->act_attackroll.animfloats = phi_v1;
                arg0->sleep = 0;
                
                objecthandlerAnimationRelated7F06FCA8(temp_a0, (void *) phi_v1->anonymous_0, sp38, phi_v1->anonymous_4, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), phi_f2_2);
                
                if (arg0->act_attackroll.unk36 != 0)
                {
                    if (phi_v1->anonymous_9 >= 0.0f)
                    {
                        sub_GAME_7F06FDE8(temp_a0, phi_v1->anonymous_9);
                    }
                    else
                    {
                        sub_GAME_7F06FDE8(temp_a0, phi_v1->anonymous_7);
                    }
                }
                else if (phi_v1->anonymous_8 >= 0.0f)
                {
                    sub_GAME_7F06FDE8(temp_a0, phi_v1->anonymous_8);
                }
                else if (phi_v1->anonymous_5 >= 0.0f)
                {
                    sub_GAME_7F06FDE8(temp_a0, phi_v1->anonymous_5);
                }

                if (arg0->act_attackroll.animfloats->anonymous_3 != 0.0f)
                {
                    temp_v0_2 = (ChrRecord *)extract_id_from_object_structure_microcode(temp_a0, temp_a0->obj->RootNode);
                    temp_v0_2->act_attackroll.unk5c = phi_f2_2;
                    temp_v0_2->act_attackroll.unk58 = (-arg0->act_attackroll.animfloats->anonymous_3 / phi_f2_2);

                    if (sp38 != RIGHT_HAND)
                    {
                        temp_v0_2->act_attackroll.unk58 = -temp_v0_2->act_attackroll.unk58;
                    }
                }
            }
        }
        else if (
            (
                (arg0->act_attackroll.animfloats == &D_80030078[8])
                || (arg0->act_attackroll.animfloats == &D_80030078[9])
                || (arg0->act_attackroll.animfloats == &D_80030078[10])
                || (arg0->act_attackroll.animfloats == &D_80030078[11]) 
                || (arg0->act_attackroll.animfloats == &D_80030078[12])
                || (arg0->act_attackroll.animfloats == &D_80030078[13])
                || (arg0->act_attackroll.animfloats == &D_80030078[14])
                || (arg0->act_attackroll.animfloats == &D_80030078[15])
                || (arg0->act_attackroll.animfloats == &D_80030078[16])
                || (arg0->act_attackroll.animfloats == &D_80030078[17])
                || (arg0->act_attackroll.animfloats == &D_80030078[18])
                || (arg0->act_attackroll.animfloats == &D_80030078[19])
            ) 
            && (arg0->act_attackroll.unk36 == 0))
        {
            if ((arg0->act_attackroll.animfloats->anonymous_9 > 0.0f) && (temp_f0 <= arg0->act_attackroll.animfloats->anonymous_9))
            {
                if (sub_GAME_7F06F5C4(temp_a0) <= temp_f0)
                {
                    objecthandlerAnimationRelated7F06FCA8(temp_a0, objecthandlerGetModelAnim(temp_a0), (s32) temp_a0->gunhand, arg0->act_attackroll.animfloats->anonymous_9, chrlvGetGuard007SpeedRating(arg0, 0.5f, 0.8f), 16.0f);
                    
                    if (arg0->act_attackroll.unk37 != 0)
                    {
                        if (arg0->act_attackroll.animfloats->anonymous_5 >= 0.0f)
                        {
                            sub_GAME_7F06FDE8(temp_a0, arg0->act_attackroll.animfloats->anonymous_5);
                        }
                    }
                    else
                    {
                        sub_GAME_7F06FDE8(temp_a0, arg0->act_attackroll.animfloats->anonymous_7);
                    }
                }
            }
        }
    }
    sub_GAME_7F02E4C0(arg0);
}




/**
 * Address 0x7F02F3F8.
*/
void chrlvTickThrowGrenade(ChrRecord *self)
{
    Model *self_model;
    f32 temp_f2;
    s32 gunhand;
    PropRecord *held_prop;

    self_model = self->model;
    temp_f2 = objecthandlerGetModelField28(self_model);
    gunhand = (self_model->gunhand != RIGHT_HAND) ? LEFT_HAND : RIGHT_HAND;
    held_prop = something_with_weaponpos_of_guarddata_hand(self, gunhand);

    if ((temp_f2 >= 20.0f) && (held_prop != NULL))
    {
        struct ObjectRecord *obj = held_prop->obj;
        obj->runtime_bitflags &= ~0x800;
    }

    if ((temp_f2 >= 61.0f) && (held_prop != NULL))
    {
        struct WeaponObjRecord *weap = held_prop->weapon;
        weap->timer = 0xB4;
    }

    if ((temp_f2 >= 119.0f) && (held_prop != NULL))
    {
        sub_GAME_7F04BFD0(self->weapons_held[gunhand], 3);
        self->hidden |= 1;
    }

    if (objecthandlerGetModelField28(self_model) >= sub_GAME_7F06F5C4(self_model))
    {
        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }

    if ((temp_f2 >= 87.0f) && (temp_f2 <= 110.0f))
    {
        chrlvSetSubroty(self, 1, 110.0f, chrlvGetGuard007SpeedRating(self, 1.0f, 1.6f), 0.0f);
    }
}




/**
 * Address 0x7F02F5A4.
*/
void chrlvTickBondIntro(ChrRecord *arg0)
{
    Model *self_model;
    f32 sp28;

    self_model = arg0->model;
    sp28 = objecthandlerGetModelField28(self_model);

    if ((sp28 < 86.0f) && (sub_GAME_7F06F5C4(self_model) <= sp28))
    {
        objecthandlerAnimationRelated7F06FCA8(
            self_model,
            &ptr_animation_table->data[(s32)&ANIM_DATA_fire_standing_draw_one_handed_weapon_fast],
            0,
            86.0f,
            sub_GAME_7F06F610(self_model),
            24.0f);

        sub_GAME_7F06FDE8(self_model, 131.0f);

        return;
    }

    if (sub_GAME_7F06F5C4(self_model) <= sp28)
    {
        chrlvKneelingAnimationRelated(arg0);
    }
}



/**
 * Address 0x7F02F688.
*/
void chrlvTickBondDieRemoved(ChrRecord *arg0)
{
    // removed.
}



/**
 * Address 0x7F02F690.
*/
s32 chrlvApplySpeed(ChrRecord *self, struct coord3d *arg1, s32 arg2, f32 *speedPtr)
{
    f32 maxSpeed;
    Model *self_model; // 72
    PropRecord *self_prop;
    f32 accel;
    f32 maxFrac; // 60
    f32 openPosition; // 56
    f32 phi_f2;
    f32 f0f0;
    f32 dx;
    f32 dz;
    s32 sp24;

    self_prop = self->prop;
    self_model = self->model;

    dx = arg1->f[0] - self_prop->pos.f[0];
    dz = arg1->f[2] - self_prop->pos.f[2];

    maxFrac = atan2f(dx, dz);
    openPosition = getsubroty(self_model);

    sp24 = 0;
    phi_f2 = maxFrac - openPosition;

    if (maxFrac < openPosition)
    {
        phi_f2 = phi_f2 + M_TAU;
    }

    f0f0 = phi_f2;

    if (phi_f2 > M_PI_F)
    {
        f0f0 = M_TAU - phi_f2;
    }

    if (arg2 == 2)
    {
        maxSpeed = 0.2991993f;
        accel = 0.014959966f;
    }
    else if (arg2 == 1)
    {
        if (f0f0 < 0.3926991f)
        {
            maxSpeed = 0.019634955f;
        }
        else if (f0f0 < 1.2566371f)
        {
            maxSpeed = 0.09817477f;
        }
        else
        {
            maxSpeed = 0.19634955f;
        }

        accel = 0.014959966f;
    }
    else
    {
        if (f0f0 < 0.3926991f)
        {
            maxSpeed = 0.009817477f;
        }
        else if (f0f0 < 1.2566371f)
        {
            maxSpeed = 0.049087387f;
        }
        else
        {
            maxSpeed = 0.12566371f;
        }

        accel = 0.009817477f;
    }

    maxSpeed *= self_model->unka4;
    accel *= self_model->unka4;

    // void chrobjCallsApplySpeed(f32 *openPosition, f32 maxFrac, f32 *speedPtr, f32 accel, f32 decel, f32 maxSpeed)
    chrobjCallsApplySpeed(
        &openPosition,
        maxFrac,
        speedPtr,
        accel,
        accel * 2.0f,
        maxSpeed);

    if (openPosition == maxFrac)
    {
        *speedPtr = 0.0f;
        sp24 = 1;
    }

    setsubroty(self_model, openPosition);

    return sp24;
}



/**
 * Address 0x7F02F888.
*/
void chrlvTickAttackWalk(ChrRecord *self)
{
    Model *self_model;
    PropRecord *player_prop;
    f32 temp_f0;
    f32 temp_f2;
    PropRecord *self_prop;
    s32 i;

    self_model = self->model;
    self_prop = self->prop;
    player_prop = get_curplayer_positiondata();
    self->act_attackwalk.clock_timer30 += g_ClockTimer;
    self->lastwalk60 = g_GlobalTimer;

    if (
        (self->invalidmove == 1)
        || (self->lastmoveok60 < (g_GlobalTimer - 0x3C))
        || (self->act_attackwalk.clock_timer34 < self->act_attackwalk.clock_timer30))
    {
        if (objecthandlerGetModelField28(self_model) > ((f32)objecthandlerGetModelAnim(self_model)->unk04 * 0.5f))
        {
            sub_GAME_7F06FE90(self_model, 0.0f, 16.0f);
        }
        else
        {
            sub_GAME_7F06FE90(self_model, (f32)objecthandlerGetModelAnim(self_model)->unk04 * 0.5f, 16.0f);
        }

        chrlvSetTargetToPlayer(self);
        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }

    temp_f0 = player_prop->pos.f[0] - self_prop->pos.f[0];
    temp_f2 = player_prop->pos.f[2] - self_prop->pos.f[2];
    if ((temp_f0 < 300.0f) && (temp_f0 > -300.0f) && (temp_f2 < 300.0f) && (temp_f2 > -300.0f))
    {
        chrlvSetTargetToPlayer(self);
        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }

    if (chrlvApplySpeed(self, &player_prop->pos, 0, &self->act_attackwalk.speed) != 0)
    {
        self->act_attackwalk.unk038 = 1;
    }

    if (self->act_attackwalk.clock_timer30 >= 0x15)
    {
        chrlvUpdateAimendsideback(self, self->act_attackwalk.animfloats, (s32) self->act_attackwalk.unk48[1], (s32) self->act_attackwalk.unk48[0], 1.0f);
    }
    else
    {
        chrlvResetAimend(self);
    }

    if (self->act_attackwalk.unk038 && !(self->act_attackwalk.clock_timer30 < 0x1F))
    {
        for (i=0; i<2; i++)
        {
            if (self->act_attackwalk.unk48[i])
            {
                if (self->act_attackwalk.unk4a[i] == 0)
                {
                    chrlvToggleHiddenRelated(self, i, 1);
                }
                else
                {
                    if ((self->act_attackwalk.timer40 < self->act_attackwalk.clock_timer30)
                        && ((i == self->act_attackwalk.unk044) || (self->act_attackwalk.unk4a[self->act_attackwalk.unk044] == 0)))
                    {
                        self->act_attackwalk.timer40 = self->act_attackwalk.clock_timer30;

                        if (self->act_attackwalk.unk4a[1 - i])
                        {
                            if (self->act_attackwalk.unk4C[i])
                            {
                                self->act_attackwalk.timer40 += 0x5A;
                            }
                            else
                            {
                                self->act_attackwalk.timer40 += 0x14;
                            }
                        }
                        else if (self->act_attackwalk.unk4C[i])
                        {
                            self->act_attackwalk.timer40 += 0xB4;
                        }
                        else
                        {
                            self->act_attackwalk.timer40 += 0x28;
                        }

                        self->act_attackwalk.unk044 = 1 - self->act_attackwalk.unk044;

                        chrlvToggleHiddenRelated(self, i, 1);
                    }
                    else
                    {
                        chrlvToggleHiddenRelated(self, i, 0);
                    }
                }
            }
            else
            {
                chrlvToggleHiddenRelated(self, i, 0);
            }
        }

        return;
    }

    chrlvToggleHiddenRelated(self, LEFT_HAND, 0);
    chrlvToggleHiddenRelated(self, RIGHT_HAND, 0);
}




/**
 * @param arg0: point in 3d
 * @param arg1: 3 vec
 * @param arg0: point in 3d
 * @param arg0: scalar value
 * 
 * Address 0x7F02FC34.
*/
s32 chrlvGeometryRelated7F02FC34(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *arg2, f32 arg3)
{
    struct coord3d dd;
    f32 temp_f14;

    dd.f[0] = arg2->f[0] - arg0->f[0];
    dd.f[2] = arg2->f[2] - arg0->f[2];
    
    if ((arg1->f[0] == 0.0f) && (arg1->f[2] == 0.0f))
    {
        return ((dd.f[0] * dd.f[0]) + (dd.f[2] * dd.f[2])) <= (arg3 * arg3);
    }

    temp_f14 = (arg1->f[0] * dd.f[0]) + (arg1->f[2] * dd.f[2]);

    if (temp_f14 > 0.0f)
    {
        f32 tf14_2 = temp_f14 * temp_f14;
        f32 f2 = (arg1->f[0] * arg1->f[0]) + (arg1->f[2] * arg1->f[2]);
        f32 f3 = (dd.f[0] * dd.f[0]) + (dd.f[2] * dd.f[2]);

        if ((f2 * (f3 - (arg3 * arg3))) <= tf14_2)
        {
            return 1;
        }

        return 0;
    }

    return 0;
}



/**
 * @param prevpos: point in 3d
 * @param curpos: 3 vec
 * @param prevpos: point in 3d
 * @param prevpos: scalar value
 * 
 * Address 0x7F02FD50.
 * 
 * PD posIsArrivingLaterallyAtPos.
*/
s32 chrlvIsArrivingLaterallyAtPos(struct coord3d *prevpos, struct coord3d *curpos, struct coord3d *targetpos, f32 range)
{
    struct coord3d sp34;

    if ((prevpos->f[0] <= targetpos->f[0] - range) && (curpos->f[0] <= targetpos->f[0] - range))
    {
        return 0;
    }

    if ((targetpos->f[0] + range <= prevpos->f[0]) && (targetpos->f[0] + range <= curpos->f[0]))
    {
        return 0;
    }

    if ((prevpos->f[2] <= targetpos->f[2] - range) && (curpos->f[2] <= targetpos->f[2] - range))
    {
        return 0;
    }

    if ((targetpos->f[2] + range <= prevpos->f[2]) && (targetpos->f[2] + range <= curpos->f[2]))
    {
        return 0;
    }

    sp34.f[0] = curpos->f[0] - prevpos->f[0];
    sp34.f[1] = 0.0f;
    sp34.f[2] = curpos->f[2] - prevpos->f[2];

    return chrlvGeometryRelated7F02FC34(prevpos, &sp34, targetpos, range);
}



/**
 * Address 0x7F02FE78.
 * PD chrTickRunPos
*/
void chrlvTickRunPos(ChrRecord *self)
{
    PropRecord *self_prop;
    Model *self_model;
    f32 phi_f2; // 52

    self_prop = self->prop;
    self_model = self->model;
    self->lastwalk60 = g_GlobalTimer;

    if(1)
    {
        // removed
    }

    if ((self->invalidmove == 1)
        || (self->lastmoveok60 < (g_GlobalTimer - 0x3C))
        || (chrlvIsArrivingLaterallyAtPos(&self->prevpos, &self_prop->pos, &self->act_runpos.pos, self->act_runpos.neardist)))
    {
        f32 offset = 0;

        // Maybe had debug side effects, otherwise this doesn't do anything.
        objecthandlerGetModelAnim(self_model);

        phi_f2 = objecthandlerGetModelField28(self_model) - offset;
        
        if (phi_f2 < 0.0f)
        {
            phi_f2 += (f32)objecthandlerGetModelAnim(self_model)->unk04;
        }

        if (((f32)objecthandlerGetModelAnim(self_model)->unk04 * 0.5f) < phi_f2)
        {
            phi_f2 = (f32)objecthandlerGetModelAnim(self_model)->unk04 - offset;
            sub_GAME_7F06FE90(self_model, phi_f2, 16.0f);
        }
        else
        {
            phi_f2 = ((f32)objecthandlerGetModelAnim(self_model)->unk04 * 0.5f) - offset;

            if (phi_f2 < 0)
            {
                phi_f2 += (f32)objecthandlerGetModelAnim(self_model)->unk04;
            }

            sub_GAME_7F06FE90(self_model, phi_f2, 16.0f);
        }

        chrlvKneelingAnimationRelated7F023E48(self);

        return;
    }

    chrlvApplySpeed(self, &self->act_runpos.pos, 1, &self->act_runpos.turnspeed);

    if (self->act_runpos.eta60 > 0)
    {
        self->act_runpos.eta60 -= g_ClockTimer;
    }
    else
    {
        f32 sp2C;

        sp2C = D_80030988;

        if ((s32)objecthandlerGetModelAnim(self_model) == (s32)&ptr_animation_table->data[(s32)&ANIM_DATA_running_one_handed_weapon])
        {
            sp2C = D_80030994;
        }

        self->act_runpos.neardist += sp2C * g_GlobalTimerDelta * sub_GAME_7F06F618(self_model);
    }
}



/**
 * Address 0x7F030128.
*/
s32 sub_GAME_7F030128(ChrRecord *arg0, struct coord3d *point, StandTile *arg2, struct coord3d *dest, StandTile * arg4, s32 objflags)
{
    StandTile *sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    sp44 = arg2;
    sp40 = 0;
    
    chrGetChrWidthHeight(arg0->prop, &sp34, &sp3C, &sp38);
    
    set_or_unset_GUARDdata_flag(arg0, 0);
    
    if (
        sub_GAME_7F0B0E24(&sp44, point->f[0], point->f[2], dest->f[0], dest->f[2], objflags, sp3C, sp38, 0.0f, 1.0f) 
        && ((arg4 == NULL) || (sp44 == arg4)))
    {
        sp40 = 1;
    }

    set_or_unset_GUARDdata_flag(arg0, 1);

    return sp40;
}



/**
 * Address 0x7F0301FC.
*/
s32 sub_GAME_7F0301FC(ChrRecord *arg0, struct coord3d *point, StandTile *arg2, struct coord3d *dest, f32 arg4, s32 arg5)
{
    StandTile *pstan;
    struct coord3d dd;
    f32 temp_f20;
    f32 temp_f22;
    f32 norm;
    s32 ret; // 104
    f32 sp64;
    f32 sp60;
    f32 sp5C;

    ret = 0;

    chrGetChrWidthHeight(arg0->prop, &sp5C, &sp64, &sp60);

    dd.f[0] = dest->f[0] - point->f[0];
    dd.f[1] = 0.0f;
    dd.f[2] = dest->f[2] - point->f[2];

    if ((dd.f[0] == 0.0f) && (dd.f[2] == 0.0f))
    {
        ret = 1;
    }
    else
    {
        norm = (dd.f[0] * dd.f[0]) + (dd.f[2] * dd.f[2]);
        norm = 1.0f / sqrtf(norm);
        
        dd.f[0] *= norm;
        dd.f[2] *= norm;

        temp_f20 = arg4 * dd.f[0];
        temp_f22 = arg4 * dd.f[2];

        set_or_unset_GUARDdata_flag(arg0, 0);

        pstan = arg2;

        if (sub_GAME_7F0B0E24(&pstan, point->f[0], point->f[2], point->f[0] + temp_f22, point->f[2] - temp_f20, arg5, sp64, sp60, 0.0f, 1.0f)
            && sub_GAME_7F0B0E24(&pstan, point->f[0] + temp_f22, point->f[2] - temp_f20, dest->f[0] + temp_f22, dest->f[2] - temp_f20, arg5, sp64, sp60, 0.0f, 1.0f))
        {
            pstan = arg2;

            if (sub_GAME_7F0B0E24(&pstan, point->f[0], point->f[2], point->f[0] - temp_f22, point->f[2] + temp_f20, arg5, sp64, sp60, 0.0f, 1.0f)
                && sub_GAME_7F0B0E24(&pstan, point->f[0] - temp_f22, point->f[2] + temp_f20, dest->f[0] - temp_f22, dest->f[2] + temp_f20, arg5, sp64, sp60, 0.0f, 1.0f))
            {
                ret = 1;
            }
        }

        set_or_unset_GUARDdata_flag(arg0, 1);
    }

    return ret;
}



/**
 * Address 0x7F0304AC.
*/
s32 sub_GAME_7F0304AC(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2, struct coord3d *arg3, struct coord3d *arg4, StandTile *arg5, s32 arg6)
{
    StandTile *sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    StandTile *sp30;

    sp44 = arg2;
    sp40 = 0;

    chrGetChrWidthHeight(arg0->prop, &sp34, &sp3C, &sp38);
    set_or_unset_GUARDdata_flag(arg0, 0);

    if (sub_GAME_7F0B0E24(&sp44, arg1->x, arg1->f[2], arg3->x, arg3->f[2], arg6, sp3C, sp38, 0.0f, 1.0f))
    {
        sp30 = sp44;

        if (sub_GAME_7F0B0E24(&sp30, arg3->x, arg3->f[2], arg4->x, arg4->f[2], arg6, sp3C, sp38, 0.0f, 1.0f)
            && ((arg5 == NULL) || (sp30 == arg5)))
        {
            sp40 = 1;
        }
    }

    set_or_unset_GUARDdata_flag(arg0, 1);

    return sp40;
}



/**
 * Unreferenced.
 * 
 * Address 0x7F0305E0.
*/
s32 sub_GAME_7F0305E0(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2, struct coord3d *arg3, struct coord3d *arg4, f32 arg5, s32 arg6)
{
    StandTile *sp4C;
    s32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    StandTile *sp38;

    sp4C = arg2;
    sp48 = 0;

    chrGetChrWidthHeight(arg0->prop, &sp3C, &sp44, &sp40);
    set_or_unset_GUARDdata_flag(arg0, 0);

    if (sub_GAME_7F0B0E24(&sp4C, arg1->x, arg1->f[2], arg3->x, arg3->f[2], arg6, sp44, sp40, 0.0f, 1.0f))
    {
        sp38 = sp4C;

        if (sub_GAME_7F0B0E24(&sp38, arg3->x, arg3->f[2], arg4->x, arg4->f[2], arg6, sp44, sp40, 0.0f, 1.0f)
            && sub_GAME_7F0301FC(arg0, arg1, arg2, arg3, arg5, arg6)
            && sub_GAME_7F0301FC(arg0, arg3, sp4C, arg4, arg5, arg6))
        {
            sp48 = 1;
        }
    }

    set_or_unset_GUARDdata_flag(arg0, 1);

    return sp48;
}


/**
 * Subtract arg0 from arg1. Take the determinate of the result and arg2.
 * If determinate is not greater than zero, then swap arg0 and arg1.
 *
 * Address 0x7F03074C.
*/
void chrlvSwapIfDiffArg2Determinate(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *arg2)
{
    struct coord3d spock;
    struct coord3d kirk;

    spock.f[0] = arg1->f[0] - arg0->f[0];
    spock.f[1] = arg1->f[1] - arg0->f[1];
    spock.f[2] = arg1->f[2] - arg0->f[2];

    kirk.f[0] = -arg2->f[2];
    kirk.f[1] = 0.0f;
    kirk.f[2] = arg2->f[0];

    if (!(((kirk.f[0] * spock.f[0]) + (kirk.f[2] * spock.f[2])) > 0.0f))
    {
        spock.f[0] = arg0->f[0];
        spock.f[1] = arg0->f[1];
        spock.f[2] = arg0->f[2];

        arg0->f[0] = arg1->f[0];
        arg0->f[1] = arg1->f[1];
        arg0->f[2] = arg1->f[2];

        arg1->f[0] = spock.f[0];
        arg1->f[1] = spock.f[1];
        arg1->f[2] = spock.f[2];
    }
}



/**
 * Very similar to @see sub_GAME_7F030D70 .
 * Address 0x7F03081C.
*/
s32 sub_GAME_7F03081C(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2, struct coord3d *arg3, struct coord3d *arg4, struct coord3d *arg5, f32 arg6, f32 arg7, s32 arg8)
{
    StandTile *spAC;
    struct coord3d spA0;
    f32 sp9C; // 156
    f32 sp98; // 152
    f32 sp94; // 148
    f32 sp90; // 144
    f32 norm;
    s32 sp88; // 136
    s32 sp84; // 132
    struct coord3d sp78;
    struct coord3d sp6C;
    struct coord3d sp60;
    struct coord3d sp54;
    s32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    sp88 = 0;
    sp84 = 0;
    sp50 = 0;

    chrGetChrWidthHeight(arg0->prop, &sp44, &sp4C, &sp48);

    spA0.f[0] = arg3->f[0] - arg1->f[0];
    spA0.f[1] = 0.0f;
    spA0.f[2] = arg3->f[2] - arg1->f[2];
    
    if ((spA0.f[0] == 0.0f) && (spA0.f[2] == 0.0f))
    {
        return 1;
    }

    norm = (spA0.f[0] * spA0.f[0]) + (spA0.f[2] * spA0.f[2]);
    norm = 1.0f / sqrtf(norm);

    spA0.f[0] *= norm;
    spA0.f[2] *= norm;
    
    sp9C = 0.95f * (arg7 * spA0.f[0]);
    sp98 = 0.95f * (arg7 * spA0.f[2]);

    sp94 = 1.2f * (arg7 * spA0.f[0]);
    sp90 = 1.2f * (arg7 * spA0.f[2]);

    set_or_unset_GUARDdata_flag(arg0, 0);
    sub_GAME_7F0B1CC4();

    spAC = arg2;

    if ((sub_GAME_7F0B0E24(
        &spAC,
        arg1->f[0],
        arg1->f[2],
        arg1->f[0] + sp98,
        arg1->f[2] - sp9C,
        arg8,
        sp4C,
        sp48,
        0.0f,
        1.0f) == 0)
        || (sub_GAME_7F0B0E24(
            &spAC,
            arg1->f[0] + sp98,
            arg1->f[2] - sp9C,
            (arg3->f[0] + sp90) + (spA0.f[0] * arg6),
            (arg3->f[2] - sp94) + (spA0.f[2] * arg6),
            arg8,
            sp4C,
            sp48,
            0.0f,
            1.0f) == 0))
    {
        sp88 = 1;

        getCollisionEdge_maybe((struct float3 *) &sp78, (struct float3 *) &sp6C);
        chrlvSwapIfDiffArg2Determinate(&sp78, &sp6C, &spA0);
    }

    spAC = arg2;

    if ((sub_GAME_7F0B0E24(
        &spAC,
        arg1->f[0],
        arg1->f[2],
        arg1->f[0] - sp98,
        arg1->f[2] + sp9C,
        arg8,
        sp4C,
        sp48,
        0.0f,
        1.0f) == 0)
        || (sub_GAME_7F0B0E24(
            &spAC,
            arg1->f[0] - sp98,
            arg1->f[2] + sp9C,
            (arg3->f[0] - sp90) + (spA0.f[0] * arg6),
            (arg3->f[2] + sp94) + (spA0.f[2] * arg6),
            arg8,
            sp4C,
            sp48,
            0.0f,
            1.0f) == 0))
    {
        sp84 = 1;

        getCollisionEdge_maybe((struct float3 *) &sp60, (struct float3 *) &sp54);
        chrlvSwapIfDiffArg2Determinate(&sp60, &sp54, &spA0);
    }

    if ((sp88 != 0) && (sp84 != 0))
    {
        chrlvSwapIfDiffArg2Determinate(&sp78, &sp60, &spA0);
        chrlvSwapIfDiffArg2Determinate(&sp6C, &sp54, &spA0);

        arg4->f[0] = sp78.f[0];
        arg4->f[1] = sp78.f[1];
        arg4->f[2] = sp78.f[2];

        arg5->f[0] = sp54.f[0];
        arg5->f[1] = sp54.f[1];
        arg5->f[2] = sp54.f[2];
    }
    else if (sp88 != 0)
    {
        arg4->f[0] = sp78.f[0];
        arg4->f[1] = sp78.f[1];
        arg4->f[2] = sp78.f[2];

        arg5->f[0] = sp6C.f[0];
        arg5->f[1] = sp6C.f[1];
        arg5->f[2] = sp6C.f[2];
    }
    else if (sp84 != 0)
    {
        arg4->f[0] = sp60.f[0];
        arg4->f[1] = sp60.f[1];
        arg4->f[2] = sp60.f[2];

        arg5->f[0] = sp54.f[0];
        arg5->f[1] = sp54.f[1];
        arg5->f[2] = sp54.f[2];
    }
    else
    {
        spAC = arg2;

        if (sub_GAME_7F0B0E24(&spAC, arg1->f[0], arg1->f[2], arg3->f[0], arg3->f[2], arg8, sp4C, sp48, 0.0f, 1.0f)
            && sub_GAME_7F0B18B8(&spAC, arg3->f[0], arg3->f[2], arg7, arg8, sp4C, sp48) < 0)
        {
            sp50 = 1;
        }
        else
        {
            getCollisionEdge_maybe((struct float3 *)arg4, (struct float3 *)arg5);
            chrlvSwapIfDiffArg2Determinate(arg4, arg5, &spA0);
        }
    }

    set_or_unset_GUARDdata_flag(arg0, 1);

    return sp50;
}


/**
 * Very similar to @see sub_GAME_7F03081C .
 * 
 * Address 0x7F030D70.
*/
s32 sub_GAME_7F030D70(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2, struct coord3d *arg3, struct coord3d *arg4, struct coord3d *arg5, f32 arg6, f32 arg7, s32 arg8)
{
    StandTile *spAC;
    struct coord3d spA0;
    f32 sp9C; // 164
    f32 sp98; // 160
    f32 sp94; // 156
    f32 sp90; // 152
    f32 norm;
    s32 sp88; // 144
    s32 sp84; // 140
    struct coord3d sp78; // x
    struct coord3d sp6C;
    struct coord3d sp60;
    struct coord3d sp54;
    s32 sp50;
    f32 stanval1;
    f32 stanval2;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    sp88 = 0;
    sp84 = 0;
    sp50 = 0;

    chrGetChrWidthHeight(arg0->prop, &sp44, &sp4C, &sp48);

    spA0.f[0] = arg3->f[0] - arg1->f[0];
    spA0.f[1] = 0.0f;
    spA0.f[2] = arg3->f[2] - arg1->f[2];
    
    if ((spA0.f[0] == 0.0f) && (spA0.f[2] == 0.0f))
    {
        return 1;
    }

    norm = (spA0.f[0] * spA0.f[0]) + (spA0.f[2] * spA0.f[2]);
    norm = 1.0f / sqrtf(norm);

    spA0.f[0] *= norm;
    spA0.f[2] *= norm;
    
    sp9C = 0.95f * (arg7 * spA0.f[0]);
    sp98 = 0.95f * (arg7 * spA0.f[2]);

    sp94 = 1.2f * (arg7 * spA0.f[0]);
    sp90 = 1.2f * (arg7 * spA0.f[2]);

    set_or_unset_GUARDdata_flag(arg0, 0);
    sub_GAME_7F0B1CC4();

    spAC = arg2;

    if ((sub_GAME_7F0B0E24(
        &spAC,
        arg1->f[0],
        arg1->f[2],
        arg1->f[0] + sp98,
        arg1->f[2] - sp9C,
        arg8,
        sp4C,
        sp48,
        0.0f,
        1.0f) == 0)
        || (sub_GAME_7F0B0E24(
            &spAC,
            arg1->f[0] + sp98,
            arg1->f[2] - sp9C,
            (arg3->f[0] + sp90) + (spA0.f[0] * arg6),
            (arg3->f[2] - sp94) + (spA0.f[2] * arg6),
            arg8,
            sp4C,
            sp48,
            0.0f,
            1.0f) == 0))
    {
        sp88 = 1;

        getCollisionEdge_maybe((struct float3 *) &sp78, (struct float3 *) &sp6C);
        chrlvSwapIfDiffArg2Determinate(&sp78, &sp6C, &spA0);

        stanval1 = stanSavedColl_someMin;
    }

    spAC = arg2;

    if ((sub_GAME_7F0B0E24(
        &spAC,
        arg1->f[0],
        arg1->f[2],
        arg1->f[0] - sp98,
        arg1->f[2] + sp9C,
        arg8,
        sp4C,
        sp48,
        0.0f,
        1.0f) == 0)
        || (sub_GAME_7F0B0E24(
            &spAC,
            arg1->f[0] - sp98,
            arg1->f[2] + sp9C,
            (arg3->f[0] - sp90) + (spA0.f[0] * arg6),
            (arg3->f[2] + sp94) + (spA0.f[2] * arg6),
            arg8,
            sp4C,
            sp48,
            0.0f,
            1.0f) == 0))
    {
        sp84 = 1;

        getCollisionEdge_maybe((struct float3 *) &sp60, (struct float3 *) &sp54);
        chrlvSwapIfDiffArg2Determinate(&sp60, &sp54, &spA0);

        stanval2 = stanSavedColl_someMin;
    }

    if ((sp88 != 0) && (sp84 != 0))
    {
        if (stanval1 < stanval2)
        {
            arg4->f[0] = sp78.f[0];
            arg4->f[1] = sp78.f[1];
            arg4->f[2] = sp78.f[2];

            arg5->f[0] = sp6C.f[0];
            arg5->f[1] = sp6C.f[1];
            arg5->f[2] = sp6C.f[2];
        }
        else
        {
            arg4->f[0] = sp60.f[0];
            arg4->f[1] = sp60.f[1];
            arg4->f[2] = sp60.f[2];

            arg5->f[0] = sp54.f[0];
            arg5->f[1] = sp54.f[1];
            arg5->f[2] = sp54.f[2];
        }
    }
    else if (sp88 != 0)
    {
        arg4->f[0] = sp78.f[0];
        arg4->f[1] = sp78.f[1];
        arg4->f[2] = sp78.f[2];

        arg5->f[0] = sp6C.f[0];
        arg5->f[1] = sp6C.f[1];
        arg5->f[2] = sp6C.f[2];
    }
    else if (sp84 != 0)
    {
        arg4->f[0] = sp60.f[0];
        arg4->f[1] = sp60.f[1];
        arg4->f[2] = sp60.f[2];

        arg5->f[0] = sp54.f[0];
        arg5->f[1] = sp54.f[1];
        arg5->f[2] = sp54.f[2];
    }
    else
    {
        spAC = arg2;

        if (sub_GAME_7F0B0E24(&spAC, arg1->f[0], arg1->f[2], arg3->f[0], arg3->f[2], arg8, sp4C, sp48, 0.0f, 1.0f)
            && sub_GAME_7F0B18B8(&spAC, arg3->f[0], arg3->f[2], arg7, arg8, sp4C, sp48) < 0)
        {
            sp50 = 1;
        }
        else
        {
            getCollisionEdge_maybe((struct float3 *)arg4, (struct float3 *)arg5);
            chrlvSwapIfDiffArg2Determinate(arg4, arg5, &spA0);
        }
    }

    set_or_unset_GUARDdata_flag(arg0, 1);

    return sp50;
}



/**
 * Address 0x7F03130C.
*/
s32 sub_GAME_7F03130C(
    ChrRecord *arg0,
    struct coord3d *arg1,
    s32 arg2,
    struct coord3d *arg3,
    f32 arg4,
    s32 arg5,
    struct coord3d *arg6,
    struct waydata *arg7,
    f32 arg8,
    s32 arg9,
    s32 set_copy)
{
    PropRecord *self_prop; // -- 124
    struct coord3d dd; // -- 112
    struct coord3d sp64; // -- 100
    f32 norm; // -- 96
    f32 phi_f12; // 92
    struct coord3d sp50; // 80
    struct coord3d *sp4C; // 76
    struct coord3d *sp48; // 72

    self_prop = arg0->prop;

    if (arg2 != 0)
    {
        sp4C = arg1;
        sp48 = arg3;
    }
    else
    {
        sp4C = arg3;
        sp48 = arg1;
    }

    dd.f[0] = arg1->f[0] - self_prop->pos.f[0];
    dd.f[1] = 0.0f;
    dd.f[2] = arg1->f[2] - self_prop->pos.f[2];

    norm = 1.0f / sqrtf((dd.f[0] * dd.f[0]) + (dd.f[2] * dd.f[2]));

    dd.f[0] *= arg4 * norm;
    dd.f[2] *= arg4 * norm;

    if (arg4 * norm > 1.0f)
    {
        phi_f12 = M_45_DEG_IN_RAD;
    }
    else
    {
        phi_f12 = acosf(arg4 * norm);
    }

    if ((arg2 == 0) && (phi_f12 != 0.0f))
    {
        phi_f12 = M_TAU - phi_f12;
    }

    sp50.f[0] = (-cosf(phi_f12) * dd.f[0]) + (sinf(phi_f12) * dd.f[2]);
    sp50.f[1] = 0.0f;
    sp50.f[2] = (-sinf(phi_f12) * dd.f[0]) - (cosf(phi_f12) * dd.f[2]);

    sp64.f[0] = arg1->f[0] + sp50.f[0];
    sp64.f[1] = arg1->f[1];
    sp64.f[2] = arg1->f[2] + sp50.f[2];

    if (sub_GAME_7F03081C(arg0, &self_prop->pos, self_prop->stan, &sp64, sp4C, sp48, arg8, arg0->chrwidth, arg9)
        && ((arg5 == 0) || sub_GAME_7F0304AC(arg0, &self_prop->pos, self_prop->stan, &sp64, arg6, NULL, arg9)))
    {
        if (set_copy != 0)
        {
            arg7->unk03 = 1;

            arg7->pos_copy.f[0] = sp64.f[0];
            arg7->pos_copy.f[1] = sp64.f[1];
            arg7->pos_copy.f[2] = sp64.f[2];
        }
        else
        {
            arg7->unk02 = 1;

            arg7->pos.f[0] = sp64.f[0];
            arg7->pos.f[1] = sp64.f[1];
            arg7->pos.f[2] = sp64.f[2];
        }

        return 1;
    }

    return 0;
}



/**
 * Iterates travel mode. Used by both ACT_GOPOS and ACT_PATROL.
 * 10% chance to open door.
 * Calls apply speed.
 * 
 * @see chrlvTickPatrol
 * @see chrlvTickGoPos
 * 
 * Address 0x7F0315A4.
*/
void chrlvTravelTick(ChrRecord *arg0, struct coord3d *arg1, StandTile *arg2, struct waydata *arg3)
{
    s32 spF0;
    struct coord3d sp100; // 260
    struct coord3d spF4; // 244
    s32 i; // 240
    f32 spe0;
    f32 spE8; // 232
    f32 spE4; // 228
    struct ObjectRecord *obj;
    f32 spC4;
    f32 spB4;
    f32 atan_pos2_a; // 212
    f32 atan_pos3_a;
    PropRecord *self_prop;
    f32 dx;
    f32 atan_pos2_b; // 196
    f32 atan_pos3_b;
    f32 dy;
    f32 dz;
    f32 atan_pos2_c; // 180
    f32 atan_pos3_c;
    s32 max;
    f32 atan_pos;
    s32 temp_t1;
    s32 phi_s6;
    PropRecord *phi_s3;
    s32 stack_01;
    s32 stack_02;

    self_prop = arg0->prop;
    phi_s6 = 0x801D;
    if ((arg0->hidden & CHRHIDDEN_OFFSCREEN_PATROL) != 0)
    {
        phi_s6 = 0x1F;
    }

    max=1;
    for (i=0; i<1; i++)
    {
        if ((arg3->mode == WAYMODE_0) || (arg3->mode == WAYMODE_2))
        {
            sp100.f[0] = arg1->f[0];
            sp100.f[1] = arg1->f[1];
            sp100.f[2] = arg1->f[2];

            if (sub_GAME_7F03081C(arg0, &self_prop->pos, self_prop->stan, &sp100, &arg3->pos2, &arg3->pos3, -(arg0->chrwidth), arg0->chrwidth, 0x10) != 0)
            {
                arg3->unk02 = (u8) 1;
                arg3->pos.f[0] = sp100.f[0];
                arg3->pos.f[1] = sp100.f[1];
                arg3->pos.f[2] = sp100.f[2];
                arg3->mode = WAYMODE_4;
            }
            else
            {
                if (arg3->mode == WAYMODE_0)
                {
                    arg3->mode = (s8) WAYMODE_1;
                    arg3->unk01 = 0;
                }
                else if (arg3->mode == WAYMODE_2)
                {
                    arg3->mode = WAYMODE_3;
                    arg3->unk01 = 0;
                }
            }
        }
        else if (arg3->mode == WAYMODE_1)
        {
            spE8 = arg0->chrwidth * 1.2f * 1.05f;

            if (sub_GAME_7F03130C(arg0, &arg3->pos2, 1, &spF4, spE8, 1, arg1, arg3, 0.0f, 0x10, 0) != 0)
            {
                arg3->mode = WAYMODE_4;
            }
            else if (sub_GAME_7F03130C(arg0, &arg3->pos3, 0, &spF4, spE8, 1, arg1, arg3, 0.0f, 0x10, 0) != 0)
            {
                arg3->mode = WAYMODE_4;
            }
            else
            {
                arg3->unk01 = arg3->unk01 + 1;
                if (arg3->unk01 >= MAX_WAYMODE)
                {
                    arg3->mode = WAYMODE_2;
                }
            }
        }
        else if (arg3->mode == WAYMODE_3)
        {
            spE4 = arg0->chrwidth * 1.2f * 1.05f;

            if (sub_GAME_7F03130C(arg0, &arg3->pos2, 1, &spF4, spE4, 0, NULL, arg3, 0.0f, 0x10, 0) != 0)
            {
                arg3->mode = WAYMODE_4;
            }
            else if (sub_GAME_7F03130C(arg0, &arg3->pos3, 0, &spF4, spE4, 0, NULL, arg3, 0.0f, 0x10, 0) != 0)
            {
                arg3->mode = WAYMODE_4;
            }
            else
            {
                arg3->unk01 = arg3->unk01 + 1;
                if (arg3->unk01 >= MAX_WAYMODE)
                {
                    arg3->unk02 = 0;
                    arg3->unk03 = (u8) (s8) arg3->unk02;
                    arg3->pos_copy.f[0] = 
                        arg3->pos.f[0] = arg1->f[0];
                    arg3->pos_copy.f[1] =
                        arg3->pos.f[1] = arg1->f[1];
                    arg3->pos_copy.f[2] =
                        arg3->pos.f[2] = arg1->f[2];
                    arg3->mode = WAYMODE_0;
                }
            }
        }
        else if (arg3->mode == WAYMODE_4)
        {
            if (sub_GAME_7F030D70(arg0, &self_prop->pos, self_prop->stan, &arg3->pos, &arg3->pos2, &arg3->pos3, -(arg0->chrwidth), arg0->chrwidth, phi_s6) != 0)
            {
                arg3->unk03 = max;
                arg3->mode = WAYMODE_0;
                arg3->pos_copy.f[0] = arg3->pos.f[0];
                arg3->pos_copy.f[1] = arg3->pos.f[1];
                arg3->pos_copy.f[2] = arg3->pos.f[2];
            }
            else
            {
                arg3->mode = WAYMODE_5;
                arg3->unk01 = 0;
            }
        }
        else if (arg3->mode == WAYMODE_5)
        {
            spe0 = arg0->chrwidth * 1.2f * 1.05f;

            atan_pos =       atan2f( arg3->pos.f[0] - self_prop->pos.f[0],  arg3->pos.f[2] - self_prop->pos.f[2]);
            atan_pos2_a = atan_pos - atan2f(arg3->pos2.f[0] - self_prop->pos.f[0], arg3->pos2.f[2] - self_prop->pos.f[2]);
            atan_pos3_a = atan_pos - atan2f(arg3->pos3.f[0] - self_prop->pos.f[0], arg3->pos3.f[2] - self_prop->pos.f[2]);

            if (atan_pos2_a < 0.0f)
            {
                atan_pos2_a = atan_pos2_a + M_TAU;
            }

            if (atan_pos2_a >= M_PI_F)
            {
                atan_pos2_a = atan_pos2_a - M_TAU;
            }

            if (atan_pos2_a < 0.0f)
            {
                atan_pos2_a = -atan_pos2_a;
            }

            if (atan_pos3_a < 0.0f)
            {
                atan_pos3_a = atan_pos3_a + M_TAU;
            }

            if (atan_pos3_a >= M_PI_F)
            {
                atan_pos3_a = atan_pos3_a - M_TAU;
            }

            if (atan_pos3_a < 0.0f)
            {
                atan_pos3_a = -atan_pos3_a;
            }

            if (atan_pos2_a < atan_pos3_a)
            {
                if (sub_GAME_7F03130C(arg0, &arg3->pos2, 1, &spF4, spe0, 0, NULL, arg3, spe0 * 1.1f, phi_s6, 1) != 0)
                {
                    arg3->mode = WAYMODE_0;
                    break;
                }
                else
                {
                    atan_pos2_b = atan_pos - atan2f(arg3->pos2.f[0] - self_prop->pos.f[0], arg3->pos2.f[2] - self_prop->pos.f[2]);
                    atan_pos3_b = atan_pos - atan2f(spF4.f[0] - self_prop->pos.f[0], spF4.f[2] - self_prop->pos.f[2]);

                    if (atan_pos2_b < 0.0f)
                    {
                        atan_pos2_b = atan_pos2_b + M_TAU;
                    }
                    if (atan_pos2_b >= M_PI_F)
                    {
                        atan_pos2_b = atan_pos2_b - M_TAU;
                    }
                    if (atan_pos2_b < 0.0f)
                    {
                        atan_pos2_b = -atan_pos2_b;
                    }

                    if (atan_pos3_b < 0.0f)
                    {
                        atan_pos3_b = atan_pos3_b + M_TAU;
                    }
                    if (atan_pos3_b >= M_PI_F)
                    {
                        atan_pos3_b = atan_pos3_b - M_TAU;
                    }
                    if (atan_pos3_b < 0.0f)
                    {
                        atan_pos3_b = -atan_pos3_b;
                    }

                    if ((atan_pos3_b < atan_pos2_b) && (sub_GAME_7F03130C(arg0, &spF4, 0, &spF4, spe0, 0, NULL, arg3, spe0 * 1.1f, phi_s6, 1) != 0))
                    {
                        arg3->mode = WAYMODE_0;
                        break;
                    }
                }
            }
            else
            {
                if (sub_GAME_7F03130C(arg0,  &arg3->pos3, 0, &spF4, spe0, 0, NULL, arg3, spe0 * 1.1f, phi_s6, 1) != 0)
                {
                    arg3->mode = WAYMODE_0;
                    break;
                }
                else
                {
                    atan_pos2_c = atan_pos - atan2f(arg3->pos3.f[0] - self_prop->pos.f[0], arg3->pos3.f[2] - self_prop->pos.f[2]);
                    atan_pos3_c = atan_pos - atan2f(spF4.f[0] - self_prop->pos.f[0], spF4.f[2] - self_prop->pos.f[2]);
                    
                    if (atan_pos2_c < 0.0f)
                    {
                        atan_pos2_c = atan_pos2_c + M_TAU;
                    }
                    if (atan_pos2_c >= M_PI_F)
                    {
                        atan_pos2_c = atan_pos2_c - M_TAU;
                    }
                    if (atan_pos2_c < 0.0f)
                    {
                        atan_pos2_c = -atan_pos2_c;
                    }

                    if (atan_pos3_c < 0.0f)
                    {
                        atan_pos3_c = atan_pos3_c + M_TAU;
                    }
                    if (atan_pos3_c >= M_PI_F)
                    {
                        atan_pos3_c = atan_pos3_c - M_TAU;
                    }
                    if (atan_pos3_c < 0.0f)
                    {
                        atan_pos3_c = -atan_pos3_c;
                    }

                    if ((atan_pos3_c < atan_pos2_c) && (sub_GAME_7F03130C(arg0, &spF4, 1, &spF4, spe0, 0, NULL, arg3, spe0 * 1.1f, phi_s6, 1) != 0))
                    {
                        arg3->mode = WAYMODE_0;
                        break;
                    }
                }
            }

            arg3->unk01 = arg3->unk01 + 1;
            if (arg3->unk01 >= MAX_WAYMODE)
            {
                arg3->unk03 = 0;
                arg3->mode = WAYMODE_0;
            }
        }
    }

    if (arg3->unk03 == 0)
    {
        arg3->pos_copy.f[0] = arg3->pos.f[0];
        arg3->pos_copy.f[1] = arg3->pos.f[1];
        arg3->pos_copy.f[2] = arg3->pos.f[2];
    }

    if (((s32) arg3->age % 10) == 0)
    {
        phi_s3 = sub_GAME_7F0B1410(self_prop->stan, self_prop->pos.f[0], self_prop->pos.f[2], arg3->pos_copy.f[0], arg3->pos_copy.f[2], 0x5000);

        if (phi_s3 != NULL)
        {
            obj = phi_s3->obj;
            if (!(obj->flags2 & PROPFLAG_NO_AI_INTERACTION))
            {
                dx = phi_s3->pos.f[0] - self_prop->pos.f[0];
                dy = phi_s3->pos.f[1] - self_prop->pos.f[1];
                dz = phi_s3->pos.f[2] - self_prop->pos.f[2];

                if (((dx * dx) + (dy * dy) + (dz  * dz )) < 40000.0f)
                {
                    sub_GAME_7F0281F4(arg0);
                    sub_GAME_7F055B78(self_prop, phi_s3->door);
                    set_door_state(phi_s3->door, 1);

                    if (((arg0->hidden & CHRHIDDEN_OFFSCREEN_PATROL) == 0)
                        && (objecthandlerGetModelAnim(arg0->model) != (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_idle_unarmed])
                        && (objecthandlerGetModelAnim(arg0->model) != (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_idle]))
                    {
                        chrlvIdleAnimationRelated(arg0, 16.0f);
                        arg0->lastmoveok60 = g_GlobalTimer;
                    }
                }
                else
                {
                    phi_s3 = NULL;
                }
            }
            else
            {
                phi_s3 = NULL;
            }
        }

        if ((phi_s3 == NULL) || ((arg0->hidden & CHRHIDDEN_OFFSCREEN_PATROL) != 0))
        {
            if ((objecthandlerGetModelAnim(arg0->model) == (struct ModelAnimation *)((s32)&ANIM_DATA_idle_unarmed + (s32)&ptr_animation_table->data))
                || (objecthandlerGetModelAnim(arg0->model) == (struct ModelAnimation *)((s32)&ANIM_DATA_idle + (s32)&ptr_animation_table->data)))
            {
                if (arg0->actiontype == ACT_PATROL)
                {
                    chrlvWalkingAnimationRelated(arg0);
                }
                else
                {
                    play_hit_soundeffect_and_proper_volume(arg0);
                }
            }

            if (phi_s3 == NULL)
            {
                arg0->hidden &= ~(CHRHIDDEN_OFFSCREEN_PATROL);
            }
        }
    }
    
    if (arg0->actiontype == ACT_PATROL)
    {
        chrlvApplySpeed(arg0, &arg3->pos_copy, 0, &arg0->act_patrol.speed);
    }
    else
    {
        chrlvApplySpeed(arg0, &arg3->pos_copy, (s32) arg0->act_gopos.unk59, &arg0->act_gopos.speed);
    
        if (arg0->act_gopos.unk59 == 2)
        {
            if (arg0->act_gopos.speed != 0.0f)
            {
                sub_GAME_7F06FE4C(arg0->model, 0.25f, 0.0f);
            }
            else if (arg0->chrflags & CHRFLAG_INCREASE_RUNNING_SPEED)
            {
                sub_GAME_7F06FE4C(arg0->model, 0.65f, 0.0f);
            }
            else
            {
                sub_GAME_7F06FE4C(arg0->model, 0.5f, 0.0f);
            }
        }
        else if (arg0->act_gopos.unk59 == 1)
        {
            if (arg0->act_gopos.speed != 0.0f)
            {
                sub_GAME_7F06FE4C(arg0->model, 0.4f, 0.0f);
            }
            else
            {
                sub_GAME_7F06FE4C(arg0->model, 0.5f, 0.0f);
            }
        }
    }
}






/**
 * Address 0x7F032088.
*/
void chrlvTickGoPos(ChrRecord *arg0)
{
    struct path_table_alt *wp;
    struct coord3d *wp_pos;
    StandTile *wp_stan;
    PropRecord *self_prop;
    s32 sp74;
    struct coord3d sp68;
    StandTile *sp64;
    struct coord3d sp58;
    StandTile *sp54;
    struct pad *pad; // 80
    s32 phi_v1; // 76
    s32 unused[4]; // maybe used by the nested if statements ?

    self_prop = arg0->prop;
    sp74 = 0;
    arg0->act_gopos.waydata.age += 1;
    arg0->lastwalk60 = g_GlobalTimer;

    if (arg0->lastmoveok60 < (g_GlobalTimer - 0x3C))
    {
        plot_course_for_actor(arg0, &arg0->act_gopos, arg0->act_gopos.target, (s32) arg0->act_gopos.unk59);
    }

    chrlvPlotCourseRelated(arg0);

    if ((arg0->act_gopos.waydata.mode != WAYMODE_MAGIC) && ((arg0->act_gopos.unk9c + 0xB4) < g_GlobalTimer))
    {
        chrlvActGoposRelated(arg0, &sp68, &sp64);

        if (chrlvStanRoomRelated(arg0, &sp68, sp64))
        {
            sp74 = 1;
            chrlvSetGoposSegDistTotal(arg0, &arg0->act_gopos.waydata, &sp68);
        }
    }

    if (g_SeenBondRecentlyGuardCount >= 0xA)
    {
        chrlvKneelingAnimationRelated7F023E48(arg0);

        return;
    }
    
    if (arg0->act_gopos.waydata.mode == WAYMODE_MAGIC)
    {
        chrlvActGoposRelated(arg0, &sp58, &sp54);

        if ((sp74 == 0)
            && ((self_prop->flags & PROPFLAG_ONSCREEN) || (chrlvStanRoomRelated(arg0, &sp58, sp54) == 0)))
        {
            chrlvActGoposSetTargetPosRelated(arg0);
            arg0->act_gopos.unk9c = g_GlobalTimer;
            
            return;
        }

        sub_GAME_7F028600(arg0, &arg0->act_gopos.waydata, chrlvModelScaleAnimationRelated(arg0), &sp58, sp54);

        return;
    }


    phi_v1 = 0;

    wp = arg0->act_gopos.waypoints[arg0->act_gopos.curindex];

    if (wp != NULL)
    {
        if (chrlvIsArrivingLaterallyAtPos(&arg0->prevpos, &self_prop->pos, &ptr_0xxxpresets[wp->id].pos, 30.0f) != 0)
        {
            phi_v1 = 1;
        }
    }
    else
    {
        if (chrlvIsArrivingLaterallyAtPos(&arg0->prevpos, &self_prop->pos, &arg0->act_gopos.targetpos, 30.0f) != 0)
        {
            chrlvKneelingAnimationRelated7F023E48(arg0);

            return;
        }
    }

    if (phi_v1 != 0)
    {
        chrlvActGoposIncCurIndex(arg0);
    }

    if (((s32) arg0->act_gopos.waydata.age % 10) == 5)
    {
        wp = arg0->act_gopos.waypoints[arg0->act_gopos.curindex];

        if (wp != NULL)
        {
            wp = arg0->act_gopos.waypoints[arg0->act_gopos.curindex + 1];

            if (wp != NULL)
            {
                wp = arg0->act_gopos.waypoints[arg0->act_gopos.curindex + 2];

                if (wp != NULL)
                {
                    pad = &ptr_0xxxpresets[wp->id];
                    wp_pos = &pad->pos;
                    wp_stan = pad->stan;
                }
                else
                {
                    wp_pos = &arg0->act_gopos.targetpos;
                    wp_stan = arg0->act_gopos.target;
                }

                if (sub_GAME_7F030128(arg0, &self_prop->pos, self_prop->stan, wp_pos, wp_stan, 0x10) 
                    && sub_GAME_7F0301FC(arg0, &self_prop->pos, self_prop->stan, wp_pos, arg0->chrwidth * 1.2f, 0x10))
                {
                    chrlvActGoposIncCurIndex(arg0);
                    chrlvActGoposIncCurIndex(arg0);
                }
            }
        }
    }

    if (((s32) arg0->act_gopos.waydata.age % 10) == 0)
    {
        wp = arg0->act_gopos.waypoints[arg0->act_gopos.curindex];

        if (wp != NULL)
        {
            wp = arg0->act_gopos.waypoints[arg0->act_gopos.curindex + 1];

            if (wp != NULL)
            {
                pad = &ptr_0xxxpresets[wp->id];
                wp_pos = &pad->pos;
                wp_stan = pad->stan;
            }
            else
            {
                wp_pos = &arg0->act_gopos.targetpos;
                wp_stan = arg0->act_gopos.target;
            }

            if (sub_GAME_7F030128(arg0, &self_prop->pos, self_prop->stan, wp_pos, wp_stan, 0x10)
                && sub_GAME_7F0301FC(arg0, &self_prop->pos, self_prop->stan, wp_pos, arg0->chrwidth * 1.2f, 0x10))
            {
                chrlvActGoposIncCurIndex(arg0);
            }
        }
    }

    wp = arg0->act_gopos.waypoints[arg0->act_gopos.curindex];

    if (wp != NULL)
    {
        pad = &ptr_0xxxpresets[wp->id];
        wp_pos = &pad->pos;
        wp_stan = pad->stan;
    }
    else
    {
        wp_pos = &arg0->act_gopos.targetpos;
        wp_stan = arg0->act_gopos.target;
    }

    chrlvTravelTick(arg0, wp_pos, wp_stan, &arg0->act_gopos.waydata);
}



/**
 * Address 0x7F032548.
*/
void chrlvTickPatrol(ChrRecord *arg0)
{
    PropRecord *self_prop;
    s32 unused_1;
    s32 sp34;
    struct pad *temp_v0;

    self_prop = arg0->prop;
    temp_v0 = (struct pad *) chrlvGetNextPatrolStepPad(arg0);
    sp34 = 0;
    arg0->act_patrol.waydata.age += 1;
    arg0->lastwalk60 = g_GlobalTimer;

    if ((arg0->act_patrol.waydata.mode != WAYMODE_MAGIC)
        && ((arg0->act_patrol.lastvisible60 + 0xB4) < g_GlobalTimer)
        && chrlvStanRoomRelatedPad(arg0, temp_v0))
    {
        sp34 = 1;
        chrlvSetGoposSegDistTotal(arg0, &arg0->act_patrol.waydata, &temp_v0->pos);
    }

    if (arg0->act_patrol.waydata.mode == WAYMODE_MAGIC)
    {
        if ((sp34 == 0)
            && ((self_prop->flags & PROPFLAG_ONSCREEN) || (chrlvStanRoomRelatedPad(arg0, temp_v0) == 0)))
        {
            arg0->act_patrol.lastvisible60 = g_GlobalTimer;
            chrlvSetNextActPatrolStepPadPos(arg0);
        }
        else
        {
            sub_GAME_7F028600(arg0, &arg0->act_patrol.waydata, D_80030984, &temp_v0->pos, temp_v0->stan);
        }
    }
    else
    {
        if(1)
        {
            // removed
        }

        if (chrlvIsArrivingLaterallyAtPos(&arg0->prevpos, &self_prop->pos, &temp_v0->pos, 30.0f))
        {
            sub_GAME_7F0284DC(arg0);
            temp_v0 = (struct pad *)chrlvGetNextPatrolStepPad(arg0);
        }

        chrlvTravelTick(arg0, &temp_v0->pos, temp_v0->stan, &arg0->act_patrol.waydata);
    }
}



/**
 * Address 0x7F0326BC.
*/
void chrlvActionTick(ChrRecord *arg0)
{
    if (g_ClockTimer > 0)
    {
        if (arg0->actiontype == ACT_INIT)
        {
            arg0->chrflags |= 1;
            chrlvIdleAnimationRelated7F023A94(arg0, 0.0f);
            arg0->sleep = 0;
        }

        if ((arg0->hidden & 0x40) != 0)
        {
            arg0->timer60 += g_ClockTimer;
        }

        arg0->sleep -= g_ClockTimer;

        if (((s32) arg0->sleep < 0) || (arg0->chrflags & 0x40000))
        {
            arg0->sleep = 0;
            parse_handle_actionblocks(arg0, PROP_TYPE_CHR);
            
            switch (arg0->actiontype)
            {
                case ACT_STAND:
                    chrlvTickStand(arg0);
                    break;
                case ACT_KNEEL:
                    chrlvTickKneel(arg0);
                    break;
                case ACT_ANIM:
                    chrlvTickAnim(arg0);
                    break;
                case ACT_DIE:
                    chrlvTickDie(arg0);
                    break;
                case ACT_ARGH:
                    chrlvTickArgh(arg0);
                    break;
                case ACT_PREARGH:
                    chrlvTickPreArgh(arg0);
                    break;
                case ACT_SIDESTEP:
                    chrlvTickSidestep(arg0);
                    break;
                case ACT_JUMPOUT:
                    chrlvTickJumpout(arg0);
                    break;
                case ACT_DEAD:
                    chrlvTickDead(arg0);
                    break;
                case ACT_ATTACK:
                    chrlvTickAttack(arg0);
                    break;
                case ACT_ATTACKWALK:
                    chrlvTickAttackWalk(arg0);
                    break;
                case ACT_ATTACKROLL:
                    chrlvTickAttackRoll(arg0);
                    break;
                case ACT_RUNPOS:
                    chrlvTickRunPos(arg0);
                    break;
                case ACT_PATROL:
                    chrlvTickPatrol(arg0);
                    break;
                case ACT_GOPOS:
                    chrlvTickGoPos(arg0);
                    break;
                case ACT_SURRENDER:
                    chrlvTickSurrender(arg0);
                    break;
                case ACT_TEST:
                    chrlvTickTest(arg0);
                    break;
                case ACT_SURPRISED:
                    chrlvTickSurprised(arg0);
                    break;
                case ACT_STARTALARM:
                    chrlvTickStartAlarm(arg0);
                    break;
                case ACT_THROWGRENADE:
                    chrlvTickThrowGrenade(arg0);
                    break;
                case ACT_BONDINTRO:
                    chrlvTickBondIntro(arg0);
                    break;
                case ACT_BONDDIE:
                    chrlvTickBondDieRemoved(arg0);
                    break;
            }
            
            arg0->chrflags &= -5;
            arg0->hidden &= 0xFDFD;
            arg0->chrseeshot = -1;
            arg0->chrseedie = -1;
        }
    }
}


/**
 * Calls chrlvActionTick on all characters, and updates count of guards that have recently seen bond.
 * 
 * Address 0x7F03291C.
*/
void chrlvAllChrTick(void)
{
    s32 i;
    s32 max;
    struct ChrRecord *guard;

    max = get_numguards();

    for (i=0; i<g_ActiveChrsCount; i++)
    {
        chrlvActionTick(&g_ActiveChrs[i]);
    }

    g_SeenBondRecentlyGuardCount = 0;

    for (i=0; i<max; i++)
    {
        guard = &ptr_guard_data[i];

        if (guard->model != NULL)
        {
            if ((guard->lastseetarget60 > 0) && (g_GlobalTimer - guard->lastseetarget60 < 0x78))
            {
                g_SeenBondRecentlyGuardCount++;
            }
        }
    }
}


/**
 * Address 0x7F032B68.
*/
s32 chrlvSeenWithin600(ChrRecord *arg0)
{
    if ((arg0->lastseetarget60 > 0) && ((g_GlobalTimer - arg0->lastseetarget60) < 0x258))
    {
        return 1;
    }

    return 0;
}




/**
 * Address 0x7F032BA0.
*/
s32 chrlvHearWithin600(ChrRecord *arg0)
{
    if ((arg0->lastheartarget60 > 0) && ((g_GlobalTimer - arg0->lastheartarget60) < 0x258))
    {
        return 1;
    }

    return 0;
}



/**
 * Address 0x7F032BD8.
*/
f32 get_distance_actor_to_position(struct ChrRecord *self, struct coord3d *pos)
{
    f32 radToPos;
    f32 radMyHeading;
    struct PropRecord *myprop;
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


/**
 * Address 0x7F032C4C.
*/
f32 chrGetAngleToBond(struct ChrRecord *self)
{
    return get_distance_actor_to_position(self, &get_curplayer_positiondata()->pos);
}



/**
 * @param self:
 * @param flags: Lookup mode. 4 == lookup guard. 8 == lookup pad preset. Else, use current player.
 * @param lookup_id: Lookup id for guard or preset.
 * @param stan: Out parameter. Will contain found stan.
 * @returns: Position of found item (depends on lookup mode).
 * 
 * Address 0x7F032C78.
*/
struct coord3d *chrlvGetChrOrPresetLocation(ChrRecord *self, s32 flags, s32 lookup_id, StandTile **stan)
{
    ChrRecord *guard;
    PropRecord *player_prop;
    s32 padid;
    struct pad *preset_pad;

    if ((flags & 4) != 0)
    {
        guard = chrlvGetHandleForGuardId(self, lookup_id);

        if ((guard == 0) || (guard->prop == 0))
        {
            guard = self;
        }

        *stan = (StandTile *) self->prop->stan;

        return &guard->prop->pos;
    }

    if ((flags & 8) != 0)
    {
        padid = convertPadIf9000(self, lookup_id);

        if (isNotBoundPad(padid))
        {
            preset_pad = &ptr_0xxxpresets[padid];
        }
        else
        {
            preset_pad = (struct pad *)&ptr_2xxxpresets[getBoundPadNum(padid)];
        }

        *stan = (StandTile *) preset_pad->stan;

        return &preset_pad->pos;
    }

    player_prop = get_curplayer_positiondata();
    *stan = (StandTile *) player_prop->stan;
    
    return &player_prop->pos;
}


/**
 * Address 0x7F032D70.
*/
f32 chrGetAngleFromBond(ChrRecord *self)
{
    f32 radBondHeading   = get_curplay_horizontal_rotation_in_degrees();
    struct PropRecord *myprop   = self->prop;
    struct PropRecord *bondprop = get_curplayer_positiondata();
    f32 angle            = atan2f(myprop->pos.x - bondprop->pos.x, myprop->pos.z - bondprop->pos.z);
    f32 radFromBond      = angle - radBondHeading;

    if (angle < radBondHeading)
    {
        radFromBond = radFromBond + M_TAU;
    }

    return radFromBond;
}


/**
 * Address 0x7F032DE4.
*/
f32 chrlvDistToBond3D(struct ChrRecord *guardData)
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


/**
 * Address 0x7F032E48.
*/
f32 sub_GAME_7F032E48(ChrRecord *self, s32 padID)
{
    struct PropRecord *myprop;
    struct pad *pad;

    myprop = self->prop;
    padID  = convertPadIf9000(self, padID);

    if (isNotBoundPad(padID))
    {
        pad = (struct pad *)&ptr_0xxxpresets[padID];
    }
    else
    {
        pad = (struct pad *)&ptr_2xxxpresets[getBoundPadNum(padID)];
    }

    return sqrtf(
        ((pad->pos.x - myprop->pos.x) * (pad->pos.x - myprop->pos.x)) +
        ((pad->pos.y - myprop->pos.y) * (pad->pos.y - myprop->pos.y)) +
        ((pad->pos.z - myprop->pos.z) * (pad->pos.z - myprop->pos.z)));
}



/**
 * Address 0x7F032EFC.
*/
bool check_if_room_for_preset_loaded(struct ChrRecord *self, s32 padnum)
{
    struct pad *pad;
    struct StandTile *padstan;

    padnum = convertPadIf9000(self, padnum);

    if (isNotBoundPad(padnum))
    {
        pad = (struct pad *)&ptr_0xxxpresets[padnum];
    }
    else
    {
        pad = (struct pad *)&ptr_2xxxpresets[getBoundPadNum(padnum)];
    }

    padstan = pad->stan;

    if (padstan)
    {
        return getROOMID_Bitflags(getTileRoom(padstan));
    }

    return FALSE;
}


s32 convertPadIf9000(struct ChrRecord *guardData,s32 padNo)
{
    // Guard's target pad.
    if (padNo == PAD_PRESET)
    {
        padNo = (s32)guardData->padpreset1;
    }

    return padNo;
}


/**
 * Address 0x7F032FAC.
*/
s32 chrResolveId(ChrRecord *self, s32 id)
{
    if (id == (u8)CHR_SEE_SHOT)
    {
        id = self->chrseeshot;
    }
    else if (id == (u8)CHR_SEE_DIE)
    {
        id = self->chrseedie;
    }
    else if (id == (u8)CHR_PRESET)
    {
        id = self->chrpreset1;
    }
    else if (id == (u8)CHR_SELF)
    {
        id = self->chrnum;
    }
    else if (id == (u8)CHR_CLONE)
    {
        id = self->chrnum + 0x2710;
    }
    else if (id == (u8)CHR_BOND_CINEMA)
    {
        if (g_CurrentPlayer->prop->chr)
        {
            id = g_CurrentPlayer->prop->chr->chrnum;
        }
    }

    return id;
}



/**
 * Address 0x7F033040.
*/
ChrRecord *chrlvGetHandleForGuardId(ChrRecord *arg0, s32 guard_id)
{
    s32 i;
    struct ChrRecord* guard;

    guard_id = chrResolveId(arg0, guard_id);
    guard = chrGetGuardData(guard_id);

    if (guard == NULL)
    {
        for (i=0; i<g_ActiveChrsCount; i++)
        {
            if (guard_id == g_ActiveChrs[i].chrnum)
            {
                guard = &g_ActiveChrs[i];
                break;
            }
        }
    }

    return guard;
}



/**
 * Address 0x7F0330C4.
*/
f32 get_distance_between_actor_and_actorID(struct ChrRecord *self, s32 chrID)
{
    struct PropRecord *myprop;
    struct ChrRecord *chr;
    f32 distance;

    myprop   = self->prop;
    chr      = chrlvGetHandleForGuardId(self, chrID);
    distance = 0.0f;

    if (chr && chr->model && chr->prop)
    {
        distance = sqrtf(
            ((chr->prop->pos.x - myprop->pos.x) * (chr->prop->pos.x - myprop->pos.x)) +
            ((chr->prop->pos.y - myprop->pos.y) * (chr->prop->pos.y - myprop->pos.y)) +
            ((chr->prop->pos.z - myprop->pos.z) * (chr->prop->pos.z - myprop->pos.z)));
    }
    
    return distance;
}



/**
 * Address 0x7F033154.
*/
f32 get_distance_between_actor_and_preset(ChrRecord *self, s32 padid)
{
    struct PropRecord *bondprop;
    struct pad *pad;

    bondprop = get_curplayer_positiondata();
    padid    = convertPadIf9000(self, padid);

    if (isNotBoundPad(padid))
    {
        pad = (struct pad *)&ptr_0xxxpresets[padid];
    }
    else
    {
        pad = (struct pad *)&ptr_2xxxpresets[getBoundPadNum(padid)];
    }

    return sqrtf(
        ((pad->pos.x - bondprop->pos.x) * (pad->pos.x - bondprop->pos.x)) +
        ((pad->pos.y - bondprop->pos.y) * (pad->pos.y - bondprop->pos.y)) +
        ((pad->pos.z - bondprop->pos.z) * (pad->pos.z - bondprop->pos.z)));
}


/**
 * The property is named "BITFIELD".
 * Address 0x7F033218.
*/
void chrlvSetBitfieldFlags(ChrRecord *arg0, u8 arg1)
{
    arg0->BITFIELD |= arg1;
}



/**
 * The property is named "BITFIELD".
 * Address 0x7F03322C.
*/
void chrlvClearBitfieldFlags(ChrRecord *arg0, u8 arg1)
{
    arg0->BITFIELD &= ~arg1;
}



/**
 * The property is named "BITFIELD".
 * Address 0x7F033244.
*/
s32 chrlvTestBitfieldFlags(ChrRecord *self, u8 arg1)
{
    return (self->BITFIELD & arg1) != 0;
}



/**
 * The property is named "BITFIELD".
 * Address 0x7F033260.
*/
void chrlvSetGuardBitfieldFlags(ChrRecord *arg0, s32 guard_id, u8 arg2)
{
    ChrRecord *guard;

    guard = chrlvGetHandleForGuardId(arg0, guard_id);

    if (guard != NULL)
    {
        chrlvSetBitfieldFlags(guard, arg2);
    }
}



/**
 * The property is named "BITFIELD".
 * Address 0x7F033290.
*/
void chrlvClearGuardBitfieldFlags(ChrRecord *arg0, s32 guard_id, u8 arg2)
{
    ChrRecord *guard;

    guard = chrlvGetHandleForGuardId(arg0, guard_id);

    if (guard != NULL)
    {
        chrlvClearBitfieldFlags(guard, arg2);
    }
}



/**
 * The property is named "BITFIELD".
 * Address 0x7F0332C0.
*/
s32 chrlvTestGuardBitfieldFlags(ChrRecord *arg0, s32 guard_id, u8 arg2)
{
    ChrRecord *guard;

    guard = chrlvGetHandleForGuardId(arg0, guard_id);

    if (guard != NULL)
    {
        return chrlvTestBitfieldFlags(guard, arg2);
    }

    return 0;
}



/**
 * Address 0x7F0332FC.
*/
void toggle_objective_bitflags(ChrRecord *arg0, s32 arg1)
{
    objectiveregisters1 |= arg1;
}



/**
 * Address 0x7F033318.
*/
void untoggle_objective_bitflags(ChrRecord *self, u32 flags)
{
    objectiveregisters1 = ~flags & objectiveregisters1; //shorthand does not match
}


/**
 * Address 0x7F033338.
*/
bool check_if_objective_bitflags_set(ChrRecord *self, s32 flags)
{
    return (objectiveregisters1 & flags) != 0;
}



/**
 * Address 0x7F033354.
*/
bool check_if_actor_02_flag_set(ChrRecord *self)
{
    return (self->hidden & CHRHIDDEN_0002) != 0;
}



/**
 * Address 0x7F033364.
*/
bool check_if_able_to_then_surrender(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvActorThrowWeaponSurrender(self);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F0333A0.
*/
bool sub_GAME_7F0333A0(ChrRecord *self)
{
    chrlvActorFadeAway(self);

    return TRUE;
}



/**
 * Address 0x7F0333C4.
*/
void reset_and_start_loop_counter(ChrRecord *self)
{
    self->timer60 = 0;
    self->hidden |= CHRHIDDEN_TIMER_ACTIVE;
}



/**
 * Address 0x7F0333D8.
*/
f32 get_loop_counter_time_in_seconds(ChrRecord *self)
{
    return self->timer60 / 60.0f;
}



/**
 * Address 0x7F0333F8.
*/
bool sub_GAME_7F0333F8(ChrRecord *self)
{
    struct Model *mymodel;
    struct coord3d zeropos;
    struct coord3d pos;
    vec3 vec;
    f32 scale;

    if (chrlvCurrentPlayerCall7F0B0E24(self))
    {
        mymodel = self->model;
        scale   = getinstsize(mymodel) * 0.8f;
        sub_GAME_7F068190(&zeropos, &pos);
        getsuboffset(mymodel, &vec);
        matrix_4x4_transform_vector_in_place(currentPlayerGetMatrix10CC(), &vec);

        if (sub_GAME_7F041074(&zeropos, &pos, &vec, scale))
        {
            return TRUE;
        }
    }

    return FALSE;
}



/**
 * Address 0x7F033490.
*/
bool check_if_actor_invisible(ChrRecord *self)
{
    return (self->chrflags & CHRFLAG_NEAR_MISS) != 0;
}



/**
 * Address 0x7F0334A0.
*/
bool chrGoToBond(ChrRecord *self, SPEED speed)
{
    struct PropRecord *bondprop;

    if (chrIsNotDeadOrShot(self) && (g_SeenBondRecentlyGuardCount < 10))
    {
        bondprop = get_curplayer_positiondata();

        if (plot_course_for_actor(self, &bondprop->pos, bondprop->stan, speed))
        {
            return TRUE;
        }
    }

    return FALSE;
}


/**
 * Address 0x7F03350C0.
*/
bool chrGoToChr(ChrRecord *self, s32 chrid, SPEED speed)
{
    struct ChrRecord *chr;
    struct PropRecord *chrprop;

    if (chrIsNotDeadOrShot(self) && (g_SeenBondRecentlyGuardCount < 10))
    {
        chr = chrlvGetHandleForGuardId(self, chrid);
        if (chr && chr->model && chr->prop)
        {
            chrprop = chr->prop;

            if (plot_course_for_actor(self, &chrprop->pos, chrprop->stan, speed))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}



/**
 * Return number of hits.
 * 
 * Address 0x7F0335A4.
 * PD: chrGetNumArghs
 */
s8 get_times_actor_shot(ChrRecord *self)
{
    return self->numarghs;
}



/**
 * Return number of near misses
 * 
 * Address 0x7F0335AC.
 * PD: chrGetNumCloseArghs
 */
s8 get_num_shots_near_actor(ChrRecord *self)
{
    return self->numclosearghs;
}


/**
 * Return false if chrseeshot is negative.
 * 
 * Address 0x7F0335B4.
 */
bool check_if_actor_FA_target_set(ChrRecord *self)
{
    return ((self->chrseeshot < 0) ^ 1);
}


/**
 * Return false if chrseedie is negative.
 * 
 * Address 0x7F0335C4.
 */
bool check_if_actor_FB_target_set(ChrRecord *self)
{
    return ((self->chrseedie < 0) ^ 1);
}



/**
 * Address 0x7F0335D4.
*/
bool chraiStopAnimation(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvKneelingAnimationRelated7F023E48(self);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F033610.
*/
bool chrTrySurprisedOneHand(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvActorShuffleFeet(self);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F03364C.
*/
bool check_if_able_to_then_fawn_on_shoulder(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvSurrenderAnimationRelated(self);

        return TRUE;

    }
    return FALSE;
}


/**
 * Address 0x7F033688.
*/
bool check_if_able_to_then_look_flustered(ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvActorLookFlustered(self);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F0336C4.
*/
bool check_if_able_to_then_kneel(struct ChrRecord *self)
{
    if (chrIsNotDeadOrShot(self) != 0)
    {
        chrlvActorKneel(self);

        return TRUE;
    }

    return FALSE;
}


/**
 * Address 0x7F033700.
*/
s32 check_if_able_to_then_perform_animation(struct ChrRecord *self, s32 animID, s32 b, s32 c, u8 d, s32 e)
{
    if (chrIsNotDeadOrShot(self))
    {
        chrlvPerformAnimationForActor(self, animID, b, c, d, e);

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F033760.
 * PD: chrCanHearAlarm
*/
bool alarm_timer_related(ChrRecord *self)
{
    /*
     possibly this was to be more advanced than simply
     a stub to alarmIsActive.
     It could have for example done a room check
     since this has a "self" reference.
     */
    return is_alarm_on();
}



/**
 * Address 0x7F033780.
 * PD: waypointIsWithin90DegreesOfPosAngle
*/
s32 sub_GAME_7F033780(s32 *arg0, struct coord3d *arg1, f32 angle)
{
    f32 temp_f0;
    struct pad *pad;
    f32 dx;
    f32 dz;
    f32 ff;

    pad = &ptr_0xxxpresets[*arg0];
    dx = pad->pos.f[0] - arg1->f[0];
    dz = pad->pos.f[2] - arg1->f[2];
    
    temp_f0 = atan2f(dx, dz);
    ff = angle - temp_f0;

    if (angle < temp_f0)
    {
        ff += M_TAU;
    }

    if ((ff < M_90_DEG_IN_RAD) || (ff > M_270_DEG_IN_RAD))
    {
        return 1;
    }

    return 0;
}




/**
 * Attempt to find a waypoint near pos which is in a particular quadrant to pos,
 * then return its padnum.
 *
 * For example, pos is typically the player's position, angle is the direction
 * the player is facing, and quadrant is which quadrant (front/back/left/right)
 * that is desired relative to the player's position and angle.
 *
 * The function starts by finding the closest waypoint to the pos. If it's not
 * in the quadrant then its neighouring waypoints are checked too. If none of
 * those are in the quadrant then no further checks are made and the function
 * returns -1.
 *
 * Address 0x7F033834.
 * PD: chrFindWaypointWithinPosQuadrant
*/
s32 chrlvFindPathNeighborRelated(struct coord3d *bondpos, struct StandTile *stan, f32 rot, u8 quadrant)
{
    s32 padnum_2;
    s32 temp_s1;
    s32 temp_s1_2;
    struct path_table_alt *pad;
    s32 path_id;
    s32 neighbor_index;

    pad = chrlvStanPathRelated(bondpos, stan);

    if (pad)
    {
        switch (quadrant)
        {
            case QUADRANT_BACK:
                rot = rot + M_PI_F;
                break;

            case QUADRANT_SIDE1:
                rot = rot + M_90_DEG_IN_RAD;
                break;

            case QUADRANT_SIDE2:
                rot = rot + M_270_DEG_IN_RAD;
                break;

            case QUADRANT_FRONT:
                break;
        }

        if (rot >= M_TAU)
        {
            rot = rot - M_TAU;
        }

        if (sub_GAME_7F033780(pad, bondpos, rot))
        {
            return pad->id;
        }

        for (
            neighbor_index=0, path_id = pad->neighbours[neighbor_index];
            path_id>=0;
            neighbor_index++, path_id = pad->neighbours[neighbor_index]
            )
        {
            if (sub_GAME_7F033780(&ptr_setup_path_tbl[path_id].id, bondpos, rot) != 0)
            {
                return ptr_setup_path_tbl[path_id].id;
            }
        }
    }

    return -1;
}



/**
 * Address 0x7F033998.
*/
bool check_2328_preset_set_with_method(ChrRecord *self, u8 quadrant)
{
    struct PropRecord *myprop;
    struct PropRecord *bondprop;
    
    struct path_table_alt *myclosestpad;
    struct path_table_alt *bondsclosestpad;

    struct path_table_alt *sp2C[PATH_FINDING_WP_LIMIT];
    
    if ((quadrant == QUADRANT_2NDWPTOTARGET) || (quadrant == QUADRANT_20)) //sp20
    {
        myprop = self->prop;
        bondprop = get_curplayer_positiondata();
        myclosestpad = chrlvStanPathRelated(&myprop->pos, myprop->stan); //sp40
        bondsclosestpad = chrlvStanPathRelated(&bondprop->pos, bondprop->stan);

        if (myclosestpad != NULL && bondsclosestpad != NULL)
        {
            if (quadrant == QUADRANT_2NDWPTOTARGET)
            {
                if (sub_GAME_7F08F4F0(myclosestpad, bondsclosestpad, &sp2C, PATH_FINDING_WP_LIMIT) >= PATH_FINDING_WP_LIMIT)
                {
                    self->padpreset1 = sp2C[1]->id;

                    return 1;
                }
            }
            else 
            {
                myclosestpad = sub_GAME_7F08FB90(myclosestpad, bondsclosestpad);
                if (myclosestpad != NULL)
                {
                    self->padpreset1 = myclosestpad->id;

                    return 1;
                }
            }
        }
    }
    else
    {
        s32 closestpadid = chrlvFindPathNeighborRelated(&self->prop->pos, self->prop->stan, getsubroty(self->model), quadrant);

        if (closestpadid >= 0)
        {
            self->padpreset1 = closestpadid;

            return 1;
        }
    }

    return 0;
}




/**
 * Address 0x7F033AAC.
*/
bool sub_GAME_7F033AAC(ChrRecord *self, u8 padnum)
{
    f32 sp1C;
    s32 bondnearestpad;
    PropRecord *bondprop;

    if ((padnum == 16) || (padnum == 32))
    {
        return check_2328_preset_set_with_method(self, padnum);
    }

    sp1C           = get_curplay_horizontal_rotation_in_degrees();
    bondprop       = get_curplayer_positiondata();
    bondnearestpad = chrlvFindPathNeighborRelated(&bondprop->pos, bondprop->stan, sp1C, padnum);

    if (bondnearestpad >= 0)
    {
        self->padpreset1 = bondnearestpad;

        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F033B38.
 * PD: chrSetChrPresetToChrNearPos
*/
bool sub_GAME_7F033B38(struct ChrRecord *self, f32 distance)
{
    struct PropRecord *myprop;
    struct ChrRecord *chr;
    s32 numguards;
    struct coord3d distneg;
    struct coord3d distplus;
    s32 myroom;
    s32 i;

    numguards = get_numguards();
    myprop    = self->prop;
    myroom    = myprop->stan->room;

    distneg.x  = myprop->pos.x - distance;
    distplus.x = myprop->pos.x + distance;
    distneg.y  = myprop->pos.y - distance;
    distplus.y = myprop->pos.y + distance;
    distneg.z  = myprop->pos.z - distance;
    distplus.z = myprop->pos.z + distance;

    for (i = 0; i < numguards; i++)
    {
        chr = &ptr_guard_data[i];

        if ((chr != self) && chr->model && !chrIsDead(chr))
        {
            struct coord3d *pos = &chr->prop->pos;

            if (
                (pos->f[0] >= distneg.x)
                && (pos->f[0] <= distplus.x)
                && (pos->f[1] >= distneg.y) 
                && (pos->f[1] <= distplus.y)
                && (pos->f[2] >= distneg.z)
                && (pos->f[2] <= distplus.z)
                && ((chr->prop->stan->room == myroom) || sub_GAME_7F0B8FD0(myroom, chr->prop->stan->room)))
            {
                self->chrpreset1 = chr->chrnum;

                return TRUE;
            }
        }
    }
    return FALSE;
}



/**
 * Address 0x7F033CF4.
*/
void sub_GAME_7F033CF4(ChrRecord *self, s32 id)
{
    self->chrpreset1 = chrResolveId(self, id);
}


/**
 * Address 0x7F033D1C.
*/
void sub_GAME_7F033D1C(ChrRecord *self, s32 id, s32 id2)
{
    struct ChrRecord *chr;

    chr = chrlvGetHandleForGuardId(self, id);

    if (chr)
    {
        chr->chrpreset1 = chrResolveId(self, id2);
    }
}



/**
 * Address 0x7F033D5C.
*/
void sub_GAME_7F033D5C( ChrRecord *self, s32 padid)
{
    self->padpreset1 = convertPadIf9000(self, padid);
}


/**
 * Address 0x7F033D84.
*/
void sub_GAME_7F033D84(ChrRecord *self, s32 chrid, s32 padid)
{
    ChrRecord *chr = chrlvGetHandleForGuardId(self, chrid);

    if (chr)
    {
        chr->padpreset1 = convertPadIf9000(self, padid);
    }
}



/**
 * Address 0x7F033DC4.
*/
s32 chrIsTargetNearlyInSight(ChrRecord *arg0)
{
    struct PropRecord *player_prop;
    struct PropRecord *self_prop;
    StandTile *stan;
    struct coord3d sp48;
    struct coord3d sp3C;

    player_prop = get_curplayer_positiondata();
    self_prop = arg0->prop;
    stan = self_prop->stan;

    sub_GAME_7F0B1CC4();

    if (walkTilesBetweenPoints_NoCallback(&stan, self_prop->pos.f[0], self_prop->pos.f[2], player_prop->pos.f[0], player_prop->pos.f[2]))
    {
        return 0;
    }
    else
    {
        getCollisionEdge_maybe(&sp48, &sp3C);

        if (
            sub_GAME_7F0304AC(arg0, &self_prop->pos, self_prop->stan, &sp48, &player_prop->pos, player_prop->stan, 0)
            || sub_GAME_7F0304AC(arg0, &self_prop->pos, self_prop->stan, &sp3C, &player_prop->pos, player_prop->stan, 0))
        {
            return 1;
        }
    }

    return 0;
}





/**
 * Address 0x7F033EAC.
*/
s32 sub_GAME_7F033EAC(struct coord3d *arg0, StandTile *arg1)
{
    s32 sp2C;
    struct bbox2d sp1C;

    sp2C = 1;

    if (getROOMID_Bitflags(getTileRoom(arg1)) && fogPositionIsVisibleThroughFog(arg0, 0.0f))
    {
        if (bgGet2dBboxByRoomId(getTileRoom(arg1), &sp1C))
        {
            sp2C = sub_GAME_7F078BF4(arg0, 200.0f, &sp1C) == 0;
        }
        else
        {
            sp2C = sub_GAME_7F078A58(arg0, 200.0f) == 0;
        }
    }

    return sp2C;
}


/**
 * Address 0x7F033F48.
*/
bool sub_GAME_7F033F48(struct coord3d *pos, struct StandTile **arg1, f32 facing, bool b)
{
    struct coord3d angle;
    struct StandTile *s;
    s32 i;
    struct StandTile **spp;

    s = *arg1;
    spp = &s;

    if ((sub_GAME_7F0B18B8(spp, pos->f[0], pos->z, 20.0f, 0x1F, 0.0f, 1.0f) < 0) &&
        (b || sub_GAME_7F033EAC(pos, *arg1)))
    {
        return TRUE;
    }

    for (i = 0; i < 8; i++)
    {
        angle.f[0] = pos->f[0] + (sinf(facing) * 60.0f);
        angle.f[1] = pos->f[1];
        angle.f[2] = pos->f[2] + (cosf(facing) * 60.0f);

        s = *arg1;

        if (sub_GAME_7F0B0E24(spp, pos->f[0], pos->f[2], angle.f[0], angle.f[2], 0x13, 0.0f, 1.0f, 0.0f, 1.0f)
            && (sub_GAME_7F0B18B8(spp, angle.f[0], angle.f[2], 20.0f, 0x1F, 0.0f, 1.0f) < 0)
            && (b || sub_GAME_7F033EAC(&angle, s)))
        {
            *arg1 = s;

            pos->f[0] = angle.f[0]; //send back upstream
            pos->f[2] = angle.f[2];

            return TRUE;
        }

        facing += 0.7853982f;

        if (facing >= M_TAU) //clamp to 1 revolution
        {
            facing -= M_TAU;
        }
    }

    return FALSE;
}



/**
 * Address 0x7F03415C.
*/
struct PropRecord *actionblock_guard_constructor_BDBE(s32 bodynum, s32 headnum, struct coord3d *pos, struct StandTile *stan, f32 yrot, s32 arg4, s32 arg5)
{
    struct PropRecord *chrprop;
    struct coord3d newpos; //struct copy here would have been more efficient
    struct ChrRecord *chr;
    struct StandTile *stancopy;
    struct Model *chrHeader;

    if (chrGetNumFree() >= 3)
    {
        if (headnum < 0)
        {
            headnum = select_psuedorandom_heads(bodynum);
        }

        newpos.f[0] = pos->f[0];
        newpos.f[1] = pos->f[1];
        newpos.f[2] = pos->f[2];
        stancopy = stan;

        if (sub_GAME_7F033F48(&newpos, &stancopy, yrot, ((arg5 & 0x10) != 0)))
        {
            chrHeader = retrieve_header_for_body_and_head(bodynum, headnum, arg5);

            if (chrHeader != NULL)
            {
                chrprop = replace_GUARDdata_with_actual_values(chrHeader, &newpos, yrot, stancopy, arg4);

                if (chrprop != NULL)
                {
                    sub_GAME_7F03A4F0(chrprop);
                    set_stateflag_0x04_for_posdata(chrprop);
                    chr          = chrprop->chr;
                    chr->headnum = headnum;
                    chr->bodynum = bodynum;

                    return chrprop;
                }
            }
        }
    }

    return NULL;
}



/**
 * Address 0x7F034258.
*/
struct PropRecord *guard_constructor_BD(struct ChrRecord *self, s32 bodynum, s32 headnum, s32 padid, struct AIListRecord *ailist, s32 flags)
{
    struct pad *pad;
    padid = convertPadIf9000(self, padid);

    if (isNotBoundPad(padid))
    {
        pad = (struct pad *)&ptr_0xxxpresets[padid];
    }
    else
    {
        pad = (struct pad *)&ptr_2xxxpresets[getBoundPadNum(padid)];
    }

    return actionblock_guard_constructor_BDBE(bodynum, headnum, &pad->pos, pad->stan, atan2f(pad->look.f[0], pad->look.f[2]), ailist, flags);
}



/**
 * Address 0x7F034308.
 */
struct PropRecord *guard_constructor_BE(struct ChrRecord *self, s32 bodynum, s32 headnum, s32 chrnum, struct AIListRecord *ailist, s32 flags)
{
    struct ChrRecord *chr;
    chr = chrlvGetHandleForGuardId(self, chrnum);

    if ((chr->chrflags & CHRFLAG_HAS_BEEN_ON_SCREEN) == 0)
    {
        f32 chrRadHeading   = getsubroty(chr->model);
        PropRecord *chrprop = chr->prop;

        return actionblock_guard_constructor_BDBE(bodynum, headnum, &chrprop->pos, chrprop->stan, chrRadHeading, ailist, flags);
    }

    return NULL;
}



/**
 * Address 0x7F034388.
*/
bool chrIfInPadRoom(struct ChrRecord *self, s32 chrnum, s32 padnum)
{
    struct pad *pad;
    struct ChrRecord *chr;

    chr    = chrlvGetHandleForGuardId(self, chrnum);
    padnum = convertPadIf9000(self, padnum);

    if (isNotBoundPad(padnum))
    {
        pad = (struct pad *)&ptr_0xxxpresets[padnum];
    }
    else
    {
        pad = (struct pad *)&ptr_2xxxpresets[getBoundPadNum(padnum)];
    }

    if (pad->stan && chr)
    {
        if (chr->prop && (pad->stan->room == chr->prop->stan->room))
        {
            return TRUE;
        }
    }

    return FALSE;
}


/**
 * Address 0x7F03444C.
*/
bool check_if_actor_is_at_preset(struct ChrRecord *self, s32 padnum)
{
    struct PropRecord *bondprop;
    struct pad *pad;

    bondprop = get_curplayer_positiondata();
    padnum   = convertPadIf9000(self, padnum);

    if (isNotBoundPad(padnum))
    {
        pad = (struct pad *)&ptr_0xxxpresets[padnum];
    }
    else
    {
        pad = (struct pad *)&ptr_2xxxpresets[getBoundPadNum(padnum)];
    }

    if (pad->stan && (pad->stan->room == bondprop->stan->room))
    {
        return TRUE;
    }

    return FALSE;
}



/**
 * Address 0x7F0344FC.
*/
bool removed_animation_routine_27(ChrRecord *self)
{
    return FALSE;
}

/**
 * Address 0x7F034508.
*/
bool removed_animation_routine_2B(ChrRecord *self)
{
    return FALSE;
}



/**
 * Address 0x7F034514.
*/
bool sub_GAME_7F034514(struct ChrRecord *self, s32 PadId)
{
    struct ObjectRecord *objinst;

    PadId = convertPadIf9000(self, PadId);

    if (chrIsNotDeadOrShot(self))
    {
        objinst = scan_position_data_table_for_normal_object_at_preset(PadId);

        if (objinst && check_if_object_has_not_been_destroyed(objinst))
        {
            chrlvExtendLeftHandAnimationRelated(self);

            return TRUE;
        }
    }

    return FALSE;
}



/**
 * Address 0x7F03457C.
*/
bool actor_draws_throws_grenade_at_player_if_possible(struct ChrRecord *self)
{
    struct PropRecord *Left;
    struct PropRecord *Right;

    struct PropRecord *NewGrenadeProp;
    struct WeaponObjRecord *NewGrenadeObj;
    struct WeaponObjRecord *LeftWep;
    struct WeaponObjRecord *RightWep;
    s32 flags;
    //GUNHAND hand;

    if (((u32)randomGetNext() % (u32)0xFF) >= self->grenadeprob)
    {
        return 0;
    }

    if (chrlvDistToBond3D(self) < 10.0f)
    {
        return 0;
    }

    if (chrIsNotDeadOrShot(self))
    {
        Left  = something_with_weaponpos_of_guarddata_hand(self, LEFT_HAND);
        Right = something_with_weaponpos_of_guarddata_hand(self, RIGHT_HAND);

        if (Right && (RightWep = Right->weapon, RightWep->weaponnum == ITEM_GRENADE))
        {
            chrlvThrowGrenadeAnimationRelated(self, Right, RIGHT_HAND, 0);

            return 1;
        }

        if (Left && (LeftWep = Left->weapon, LeftWep->weaponnum == ITEM_GRENADE))
        {
            chrlvThrowGrenadeAnimationRelated(self, Left, LEFT_HAND, 0);

            return 1;
        }

        if (!Left || !Right)
        {
            flags = 0;
            
            if (Right)
            {
                flags = 0x10000000;
            }
            
            NewGrenadeProp = actor_draws_weapon_with_model(self, 0xC4, ITEM_GRENADE, flags);
            
            if (NewGrenadeProp)
            {
                NewGrenadeObj = NewGrenadeProp->weapon;
                NewGrenadeObj->base.runtime_bitflags |= 0x800; //manual bitflags are more effecient
                
                chrlvThrowGrenadeAnimationRelated(self, NewGrenadeProp, !Right ? RIGHT_HAND : LEFT_HAND, 1); //this matches

                return 1;
            }
        }
    }

    return 0;
}


/**
 * Address 0x7F0346FC.
*/
bool actor_drops_itemtype_setting_timer(struct ChrRecord *self, s32 modelnum, u8 weaponid)
{
    struct WeaponObjRecord *NewModel = create_new_item_instance_of_model(modelnum, weaponid);
    
    if (NewModel && NewModel->base.prop)
    {
        set_obj_instance_controller_scale(NewModel->base.model, NewModel->base.model->scale);
        attachNewChild(NewModel->base.prop, self->prop);
        NewModel->timer = 0xB4;
        sub_GAME_7F04BFD0(NewModel->base.prop, 1);
        self->hidden = self->hidden | 1;

        return TRUE;
    }

    return FALSE;
}
