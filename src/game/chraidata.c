#include <ultra64.h>
#include <bondgame.h>
#include <bondaicommands.h>
#include "chrobjdata.h"
// bss

/*=============================================================================
// Global AI Lists - GLists
//===========================================================================*/

//private enum, only accessable from within this file
static enum gListLabels
{
    lblZero,
    lblLoop,
    lblDone,
    lblNext,
    lblWaiting,
    lblAlarmActivated,
    lblStoppedMoving,
    lblSeesBond,
    lblKneel             = 11,
    lbl12,
    lblBuddyShot,
    lblCloneContinue,
    lblJogToObjective,
    lblNearMiss,
    lblDead,
    /*Big Gap? wonder why*/
    lblJogging           = 27,
    lblResetAndJogAgain,
    lblAbleToJog,
    lblSitRep,
    lblCheckDistance     = 36,
    lblJog               = 40,
    lblMaybeThrowGrenade = 43,
    lblCheckDistance2    = 45,
    lbl46,
    lblInvincibleCheck
};


/* global ai lists used for all levels */
// data
//D:80037070
// Continuously aim at bond with weapon
u8 glist_aim_at_bond[] = { 
    guard_try_fire_or_aim_at_target(TARGET_BOND | TARGET_AIM_ONLY, 0, lblLoop)
        LOOP_FOREVER(lblLoop)
    ai_list_end
};

//D:8003707C
// end routine (loop forever)
u8 glist_end_routine[] = { 
    LOOP_FOREVER(lblDead)
    ai_list_end
};

//D:80037084
// Wait for bond detection (spawn clone when heard bond)
u8 glist_detect_bond_spawn_clone_on_heard_gunfire[] = { 
    DO(lblLoop)
        if_chr_dying_or_dead(CHR_SELF, lblDead)       // guard died, safely end list
        if_guard_has_stopped_moving(lblStoppedMoving) // guard has stopped moving, safe to continue
        /*ELSE*/
        CONTINUE(lblLoop)
        
        
        label(lblStoppedMoving)
            if_guard_sees_bond(lblSeesBond)
            /*ELSE*/ if_guard_was_shot_or_seen_bond_within_last_10_secs(lblBuddyShot) /*BREAK*/
            /*ELSE*/ if_guard_heard_bond_within_last_10_secs(lblCloneContinue)        /*BREAK*/
            /*ELSE*/ if_guard_shot_from_bond_missed(lblNearMiss)                      /*BREAK*/
            /*ELSE*/ if_guard_see_another_guard_shot(lblBuddyShot)                    /*BREAK*/
            /*ELSE*/ if_guard_see_another_guard_die(lblBuddyShot)                     /*BREAK*/
            /*ELSE*/ if_guard_playing_animation(lblNext)                              // playing idle animation
            /*ELSEIF*/ random_generate_greater_than(1, lblNext)                       // 1/255 chance of playing idle animation
            /*ELSE*/ 
            set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
            jump_to_ai_list(CHR_SELF, GLIST_IDLE_RAND_ANIM_SUBROUTINE)                // play idle animation and return to list
            /*ENDIF*/ 
    
        label(lblNext) 

    LOOP(lblLoop)
    
    
    label(lblNearMiss) // bond shot near guard
        random_generate_greater_than(127, lblSeesBond) // 50% chance of playing looking around animation
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE)
        
    label(lblSeesBond) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
        
    label(lblBuddyShot) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
        
    label(lblCloneContinue) // guard heard bond, attempt to spawn clone (only if chr has clone flag)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_SPAWN_CLONE_OR_RUN_TO_BOND)
        
    label(lblDead) // guard has died, end routine
        jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:800370DC
// Play idle animation (subroutine)
u8 glist_idle_rand_anim_subroutine[] = { 
    random_generate_greater_than(50, lblNext) // generate annd compare random seed to see which animation to play
    guard_play_animation(ANIM_yawning, 0, 193, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
    goto_next(lblDone) // jump to end, we're done
    
    label(lblNext)
        if_random_seed_greater_than(100, lblNext)
        guard_play_animation(ANIM_swatting_flies, 0, 294, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(lblDone) // jump to end, we're done
        
    label(lblNext)
        if_random_seed_greater_than(150, lblNext)
        guard_play_animation(ANIM_scratching_leg, 0, 183, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(lblDone) // jump to end, we're done
        
    label(lblNext)
        if_random_seed_greater_than(200, lblNext)
        guard_play_animation(ANIM_scratching_butt, 0, 123, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(lblDone) // jump to end, we're done
        
    label(lblNext)
        if_random_seed_greater_than(250, lblNext)
        guard_play_animation(ANIM_adjusting_crotch, 0, 56, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(lblDone) // jump to end, we're done
        
    label(lblNext)
        guard_play_animation(ANIM_sneeze, 0, 137, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(lblDone) // jump to end, we're done
        
    RETURN(lblDone)
};

//D:8003713C
// Play use keyboard animation (subroutine)
u8 glist_keyboard_rand_anim_subroutine[] = { 
    random_generate_greater_than(60, lblNext)
    guard_play_animation(ANIM_keyboard_right_hand1, 0, 69, 0x00, ANIM_DEFAULT_INTERPOLATION)
    goto_next(lblDone) // jump to end, we're done
    
    label(lblNext)
        if_random_seed_greater_than(120, lblNext)
        guard_play_animation(ANIM_keyboard_right_hand2, 0, 74, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(lblDone) // jump to end, we're done
        
    label(lblNext)
        if_random_seed_greater_than(180, lblNext)
        guard_play_animation(ANIM_keyboard_left_hand, 0, 79, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(lblDone) // jump to end, we're done
        
    label(lblNext)
        guard_play_animation(ANIM_keyboard_right_hand_tapping, 0, 89, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(lblDone) // jump to end, we're done
        
    RETURN(lblDone)
};

//D:8003717C
// Wait for bond detection (deaf/no clones/no idling)
u8 glist_detect_bond_deaf_no_clone_no_idle_anim[] = { 
    DO(lblLoop) // wait for guard to stop moving before branching to next logic
        if_guard_has_stopped_moving(lblStoppedMoving)
        /*ELSE*/
        CONTINUE(lblLoop)
        
        label(lblStoppedMoving)
            if_guard_sees_bond(lblSeesBond)
            if_guard_was_shot_or_seen_bond_within_last_10_secs(lblBuddyShot)
            if_guard_shot_from_bond_missed(lblNearMiss)
            if_guard_see_another_guard_shot(lblBuddyShot)
            if_guard_see_another_guard_die(lblBuddyShot)
    LOOP(lblLoop)
        
        
    label(lblNearMiss) // bond shot near guard
        random_generate_greater_than(127, lblSeesBond) // 50% chance of playing looking around animation
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE)
        
    label(lblSeesBond) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
        
    label(lblBuddyShot) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800371B4
// Fire at bond with random animation (subroutine)
u8 glist_fire_rand_anim_subroutine[] = { 
    if_guard_bitfield_is_set_on(BITFIELD_DONT_POINT_AT_BOND, lblNext) // if guard already pointed at bond
    random_generate_greater_than(32, lblNext) // 12.5% chance of pointing to bond
    guard_points_at_bond
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // don't point again, thank you object permanence
    jump_to_return_ai_list // guard pointed at bond, return to list
    
    label(lblNext)
        guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // set flag so we don't point at bond, only do that for first time in list
        guard_try_throwing_grenade(lblDone) // attempt to throw grenade, depends on chr->grenadeprob value
        
    label(lblNext)
        random_generate_greater_than(10, lblNext)
        guard_try_firing_roll(lblDone)
        
    label(lblNext)
        random_generate_greater_than(10, lblNext)
        guard_try_hopping_sideways(lblDone)
        
    label(lblNext)
        random_generate_greater_than(25, lblNext)
        guard_try_sidestepping(lblDone)
        
    label(lblNext)
        random_generate_greater_than(50, lblNext)
        guard_try_running_to_side(lblDone)
        
    label(lblNext)
        random_generate_greater_than(64, lblNext)
        guard_try_firing_walk(lblDone) // infinite ammo death sentence ;)
        
    label(lblNext)
        if_random_seed_greater_than(127, lblNext)
        guard_try_firing_run(lblDone)
        
    label(lblNext)
        random_generate_greater_than(127, lblKneel)
        guard_try_fire_or_aim_at_target(TARGET_BOND, 0, lblDone)
        
    label(lblKneel)
        guard_try_fire_or_aim_at_target_kneel(TARGET_BOND, 0, lblDone)

    RETURN(lblDone) // guard did the thing, now go back home
};

//D:8003720C
// Run to bond and fire (subroutine)
u8 glist_jog_to_bond_subroutine[] = { 
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // guard is aware of bond, so don't point at him when first spotted
    guard_try_running_to_bond_position(lblLoop) // goto loop if bond position is reachable
    jump_to_return_ai_list // if guard can't reach bond, return to ai list (read guard_try_running_to_bond_position command info)

    DO(lblLoop)
        if_guard_has_stopped_moving(lblStoppedMoving)
        if_guard_sees_bond(lblSeesBond) // detected bond, goto attack list
    LOOP(lblLoop)
        
    label(lblSeesBond)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
        
    RETURN(lblStoppedMoving)
};

//D:80037224
// If chr has been seen, run to bond - else spawn clone
u8 glist_spawn_clone_or_jog_to_bond[] = { 
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // guard is aware of bond, so don't point at him when first spotted
    if_guard_has_not_been_seen(lblCloneContinue) // if guard has yet to be seen by bond, goto 0E
    jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE) // guard has been seen, run to bond and fire
    
    label(lblCloneContinue)
        if_chr_does_not_exist(CHR_CLONE, lblCloneContinue) // if clone doesn't exist
        jump_to_ai_list(CHR_SELF, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE) // continue idling
        
    label(lblCloneContinue)
        chr_try_spawning_clone(CHR_SELF, GLIST_RUN_TO_BOND_AND_FIRE, lblNext) // attempt to spawn clone with run to bond list assigned, if success goto 03
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE) // guard failed to spawn (not enough memory/guard doesn't have clone flag on), just run at bond anyway

    label(lblNext) // if clone spawn was successful
        jump_to_ai_list(CHR_SELF, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE) // set original chr to sit tight while the clone does all the work, giving the illusion that bunker ii is a crowded complex
    ai_list_end
};

//D:80037248
// Run to bond and fire
u8 glist_jog_to_bond_and_fire[] = { 
    set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
    jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:80037250
// Wait for bond detection (no clones/no idling)
u8 glist_detect_bond_no_clone_no_idle_anim[] = { 
    DO(lblLoop) // wait for guard to stop moving before branching to next logic
        if_guard_sees_bond(lblSeesBond)
        if_guard_was_shot_or_seen_bond_within_last_10_secs(lblBuddyShot)
        if_guard_heard_bond_within_last_10_secs(lblBuddyShot)
        if_guard_shot_from_bond_missed(lblBuddyShot)
        if_guard_see_another_guard_shot(lblBuddyShot)
        if_guard_see_another_guard_die(lblBuddyShot)
    LOOP(lblLoop)
        
    label(lblSeesBond) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
        
    label(lblBuddyShot) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
        
    label(lblCloneContinue) // unused spawn clone reaction for hearing bond, likely made game too difficult/slow
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_SPAWN_CLONE_OR_RUN_TO_BOND)
    ai_list_end
};

//D:80037280
// Run to chr->padpreset1 and activate alarm
u8 glist_jog_to_chr_padpreset_and_activate_alarm[] = { 
	     
    DO(lblLoop) // wait for guard to stop moving before branching to next logic
        if_guard_has_stopped_moving(lblStoppedMoving)
        /*ELSE*/
        CONTINUE(lblLoop)
        
        label(lblStoppedMoving)
            if_guard_sees_bond(lblJogToObjective)
            if_guard_hits_missed_greater_than(0, lblNearMiss)
            if_guard_heard_bond_within_last_10_secs(lblNearMiss)
            if_guard_see_another_guard_shot(lblNearMiss)
            if_guard_see_another_guard_die(lblNearMiss)
    LOOP(lblLoop)
        

    label(lblNearMiss) // a guard in sight was killed/shot, heard bond or bond shot guard
        if_guard_hits_greater_than(0, lblJogToObjective) // doesn't make sense why the guard would be mildly curious about getting shot
        guard_looks_around_self
        
    DO(lblWaiting) // wait for guard to stop moving before branching to next logic (triggered by look around animation)
        if_guard_has_stopped_moving(lblJogToObjective)
    LOOP(lblWaiting)
        
    label(lblJogToObjective)
        guard_runs_to_pad(PAD_PRESET)
        
    DO(lblNext) // wait for guard to stop moving (reached destination/guard was shot)
        if_guard_has_stopped_moving(lblDone)
    LOOP(lblNext)
        
    label(lblDone)
        if_chr_meters_to_pad_greater_than(CHR_SELF, 1, PAD_PRESET, lblDone) // if guard is more than 1 meter away from alarm, skip to attack ai list
        guard_try_triggering_alarm_at_pad(PAD_PRESET, lblAlarmActivated)
        goto_next(lblDone) // didn't activate alarm (alarm destroyed?)
        
    DO(lblAlarmActivated) // wait for guard to finish activating alarm
        if_guard_has_stopped_moving(lblDone)
    LOOP(lblAlarmActivated)
        
    label(lblDone)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800372D0
// Startle character (subroutine)
u8 glist_startle_chr_and_jog_to_bond_subroutine[] = { 
    guard_looks_around_self // trigger animation
    DO(lblLoop)
        if_guard_has_stopped_moving(lblDone) // wait for chr to stop moving
    LOOP(lblLoop)
        
    label(lblDone) // chr stopped moving
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800372E0
// Forever chase bond and fire (halt randomly)
u8 glist_jog_to_bond_and_fire_forever[] = { 
           
    /*DO*/label(lblJog)
        guard_try_running_to_bond_position(lblJogging) // goto loop if bond position is reachable
        debug_log 'n','o',' ','g','o','!','\n', debug_log_end // guard can't reach bond
        
        DO(lblJogging)
            if_guard_and_bond_within_line_of_sight(lblStoppedMoving)
            if_guard_has_stopped_moving(lblDone)
        LOOP(lblJogging)
        
        DO(lblLoop)
            if_guard_hits_less_than(6, lblCheckDistance2)
            /*ELSE*/if_guard_flags_is_set_on(CHRFLAG_INVINCIBLE, lblInvincibleCheck) /*BREAK*/
        
        label(lblCheckDistance2)
            if_guard_has_stopped_moving(lblStoppedMoving)
            // BUG - this causes guard to shuffle about uselessly if Bond & guard are within line of sight and over 20 meters
            if_guard_meters_to_bond_greater_than(20, lblNext) // if guard is further than 20 meters away from bond, break
        LOOP(lblLoop)
        
        
        label(lblNext)
            CONTINUE(lblJog)
        
        label(lblStoppedMoving)
            if_guard_and_bond_within_line_of_sight(lblNext)
            goto_next(lblDone)
        
        label(lblCheckDistance)
            ai_sleep
            if_guard_meters_to_bond_less_than(5, lblNext) // if guard is within 5 meters from bond, goto 03
            /*ELSE*/if_guard_has_stopped_moving(lblNext)
            /*ELSE*/
            CONTINUE(lblJog)
        
        
        label(lblNext)
            if_guard_flags_is_set_on(CHRFLAG_INVINCIBLE, lblInvincibleCheck)
        
        label(lblMaybeThrowGrenade)
            random_generate_greater_than(10, lblNext)
            guard_try_throwing_grenade(lblDone) // attempt to throw grenade, depends on chr->grenadeprob value
        
        label(lblNext)
            if_random_seed_greater_than(50, lblNext)
            guard_try_sidestepping(lblDone)
        
        label(lblNext)
            if_random_seed_greater_than(60, lblNext)
            guard_try_firing_roll(lblDone)
        
        label(lblNext)
            if_random_seed_greater_than(80, lblNext)
            guard_try_firing_roll(lblDone)
        
        label(lblNext)
            if_random_seed_greater_than(100, lblNext)
            guard_try_firing_walk(lblDone)

        label(lblNext)
            if_random_seed_greater_than(150, lblNext)
            guard_try_firing_run(lblDone)

        label(lblNext)
            if_random_seed_greater_than(200, lblNext)
            guard_try_fire_or_aim_at_target(TARGET_BOND, 0, lblDone)

        label(lblNext)
            guard_try_fire_or_aim_at_target_kneel(TARGET_BOND, 0, lblDone)

        label(lblDone)
            if_guard_and_bond_within_line_of_sight(lblNext)
            goto_next(lblJogging)

        label(lblJogging)
            ai_sleep
            random_generate_greater_than(160, lblNext)
            goto_next(lblResetAndJogAgain)

        label(lblNext)
            ai_sleep
            goto_first(lblLoop)

        label(lblResetAndJogAgain)
            local_timer_reset_start
            guard_try_running_to_bond_position(lblAbleToJog)

        DO(lblAbleToJog)
            if_guard_has_stopped_moving(lblNext)
            if_local_timer_seconds_greater_than(1, lblNext)
        LOOP(lblAbleToJog)

        label(lblNext)
            guard_animation_stop
            debug_log 'w','a','i','t','\n', debug_log_end
            guard_bitfield_set_off(lblWaiting)
            random_generate_greater_than(160, lblNext)
            guard_bitfield_set_on(lblWaiting)

        label(lblNext)
            local_timer_reset_start

        label(lblSitRep)
            ai_sleep
            if_guard_and_bond_within_line_of_sight(lblNext)
            if_guard_shot_from_bond_missed(lblNext)
            ai_sleep
            if_local_timer_seconds_less_than(10, lblWaiting) // if timer less than 10 seconds, goto 04
            if_guard_bitfield_is_set_on(lblWaiting, lblAlarmActivated)
    LOOP(lblJog)


    label(lblAlarmActivated)
        goto_first(lblResetAndJogAgain)

    label(lblWaiting)
        goto_first(lblSitRep)

    label(lblNext)
        goto_first(lblLoop)


    label(lblInvincibleCheck)
        if_guard_hits_less_than(6, lblNext)
        guard_flags_set_off(CHRFLAG_INVINCIBLE)

    label(lblNext)
        goto_first(lblMaybeThrowGrenade)
    ai_list_end
};

//D:800373D0// Wait for one second (subroutine)
u8 glist_wait_one_second_subroutine[] = { 
    local_timer_reset_start
    DO(lblJogging)
        if_local_timer_seconds_greater_than(1, lblNext) // wait one second
    LOOP(lblJogging)

    RETURN(lblNext)
};

//D:800373E0// Exit level
u8 glist_exit_level[] = { 
    exit_level
    jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:800373E8// Draw Pistol and fire
u8 glist_draw_pistol_and_fire[] = { 
    guard_set_speed_rating(40) // fast boi watch out!
    guard_set_accuracy_rating(50)

    label(lblNext)
        guard_try_facing_target(TARGET_BOND, 0, lblNext)

    label(lblNext)
        local_timer_reset_start

    DO(lblJogging)
        if_local_timer_greater_than(20, lblNext) // wait 1/3 of a second
    LOOP(lblJogging)
        
    label(lblNext)
        guard_play_animation(ANIM_fire_standing_draw_one_handed_weapon_fast, 0, 20, ANIM_LOOP_HOLD_LAST_FRAME, ANIM_DEFAULT_INTERPOLATION)

    DO(lblResetAndJogAgain)
        if_guard_has_stopped_moving(lblNext)
    LOOP(lblResetAndJogAgain)

    label(lblNext)
        guard_try_spawning_item(PROP_chrtt33, ITEM_TT33, 0, lblNext)

    label(lblNext)
        guard_try_fire_or_aim_at_target(TARGET_BOND | TARGET_AIM_ONLY, 0, lblNext) // aim...

    label(lblNext)
        guard_try_fire_or_aim_at_target_update(TARGET_BOND, 0, lblNext) // FIRE!

    label(lblNext)
        DO(lblSitRep) // loop until guard has stopped firing at bond
            if_guard_has_stopped_moving(lblNext)
        LOOP(lblSitRep)

    label(lblNext)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:80037444// Remove chr
u8 glist_remove_chr[] = { 
    chr_remove_instant(CHR_SELF) // remove self
    jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:8003744C
// global ai lists (glists)
AIListRecord gGlobalAILists[] = { 
    {glist_aim_at_bond                             , GLIST_AIM_AT_BOND},
    {glist_end_routine                             , GLIST_END_ROUTINE},
    {glist_detect_bond_spawn_clone_on_heard_gunfire, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE},
    {glist_idle_rand_anim_subroutine               , GLIST_IDLE_RAND_ANIM_SUBROUTINE},
    {glist_keyboard_rand_anim_subroutine           , GLIST_KEYBOARD_RAND_ANIM_SUBROUTINE},
    {glist_detect_bond_deaf_no_clone_no_idle_anim  , GLIST_DETECT_BOND_DEAF_NO_CLONE_NO_IDLE_ANIM},
    {glist_fire_rand_anim_subroutine               , GLIST_FIRE_RAND_ANIM_SUBROUTINE},
    {glist_detect_bond_no_clone_no_idle_anim       , GLIST_DETECT_BOND_NO_CLONE_NO_IDLE_ANIM},
    {glist_jog_to_bond_subroutine                  , GLIST_RUN_TO_BOND_SUBROUTINE},
    {glist_jog_to_chr_padpreset_and_activate_alarm , GLIST_RUN_TO_CHR_PADPRESET_AND_ACTIVATE_ALARM},
    {glist_startle_chr_and_jog_to_bond_subroutine  , GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE},
    {glist_spawn_clone_or_jog_to_bond              , GLIST_SPAWN_CLONE_OR_RUN_TO_BOND},
    {glist_jog_to_bond_and_fire                    , GLIST_RUN_TO_BOND_AND_FIRE},
    {glist_jog_to_bond_and_fire_forever            , GLIST_RUN_TO_BOND_AND_FIRE_HALT_CHR_RANDOMLY},
    {glist_wait_one_second_subroutine              , GLIST_WAIT_ONE_SECOND_SUBROUTINE},
    {glist_exit_level                              , GLIST_EXIT_LEVEL},
    {glist_draw_pistol_and_fire                    , GLIST_DRAW_DD44_AND_FIRE},
    {glist_remove_chr                              , GLIST_REMOVE_CHR}
};
		             
//D:800374DC
u32 D_800374DC[] = {0,0};

//D:800374E4
char *setup_text_pointers[] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, "UsetupsevbunkerZ",
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,"UsetupsiloZ",
    "UsetupsevbunkerZ","UsetupstatueZ","UsetupcontrolZ","UsetuparchZ","UsetuptraZ",
    "UsetupdestZ","UsetupsevbZ","UsetupaztZ","UsetuppeteZ","UsetupdepoZ","UsetuprefZ",
    "UsetupcrypZ","UsetupdamZ","UsetuparkZ","UsetuprunZ","UsetupsevxZ","UsetupjunZ",
    "UsetupdishZ","UsetupcaveZ","UsetupcatZ","UsetupcradZ","UsetupshoZ","UsetupsevxbZ",
    "UsetupeldZ","UsetupimpZ","UsetupashZ","UsetuplueZ","UsetupameZ","UsetupritZ",
    "UsetupoatZ","UsetupearZ","UsetupleeZ","UsetuplipZ","UsetuplenZ","UsetupwaxZ",
    "UsetuppamZ", NULL, NULL
};

