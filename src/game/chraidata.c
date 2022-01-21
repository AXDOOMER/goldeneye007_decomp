#include <ultra64.h>
#include <bondgame.h>
#include "chrobjdata.h"
// bss


/* global ai lists used for all levels */
// data
//D:80037070
u8 dword_D_80037070[] = { // GLIST_AIM_AT_BOND: continuously aim at bond with weapon
    guard_try_fire_or_aim_at_target(TARGET_BOND | TARGET_AIM_ONLY, 0, 0x01)
    goto_loop_infinite(0x01)
    ai_list_end
};

//D:8003707C
u8 dword_D_8003707C[] = { // GLIST_END_ROUTINE: end routine (loop forever)
    goto_loop_infinite(0x11)
    ai_list_end
};

//D:80037084
u8 dword_D_80037084[] = { // GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE: wait for bond detection (spawn clone when heard bond)
    goto_loop_start(0x01)
        if_chr_dying_or_dead(CHR_SELF, 0x11) // guard died, safely end list
        if_guard_has_stopped_moving(0x06) // guard has stopped moving, safe to continue
        goto_loop_repeat(0x01)
    label(0x06)
        if_guard_sees_bond(0x07)
        if_guard_was_shot_or_seen_bond_within_last_10_secs(0x0D)
        if_guard_heard_bond_within_last_10_secs(0x0E)
        if_guard_shot_from_bond_missed(0x10)
        if_guard_see_another_guard_shot(0x0D)
        if_guard_see_another_guard_die(0x0D)
        if_guard_playing_animation(0x03) // playing idle animation
        random_generate_greater_than(1, 0x03) // 1/255 chance of playing idle animation
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_IDLE_RAND_ANIM_SUBROUTINE) // play idle animation and return to list
    label(0x03)
        goto_loop_repeat(0x01)
    label(0x10) // bond shot near guard
        random_generate_greater_than(127, 0x07) // 50% chance of playing looking around animation
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE)
    label(0x07) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
    label(0x0D) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    label(0x0E) // guard heard bond, attempt to spawn clone (only if chr has clone flag)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_SPAWN_CLONE_OR_RUN_TO_BOND)
    label(0x11) // guard has died, end routine
        jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:800370DC
u8 dword_D_800370DC[] = { // GLIST_IDLE_RAND_ANIM_SUBROUTINE: play idle animation (subroutine)
    random_generate_greater_than(50, 0x03) // generate annd compare random seed to see which animation to play
    guard_play_animation(ANIM_yawning, 0, 193, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
    goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(100, 0x03)
        guard_play_animation(ANIM_swatting_flies, 0, 294, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(150, 0x03)
        guard_play_animation(ANIM_scratching_leg, 0, 183, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(200, 0x03)
        guard_play_animation(ANIM_scratching_butt, 0, 123, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(250, 0x03)
        guard_play_animation(ANIM_adjusting_crotch, 0, 56, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        guard_play_animation(ANIM_sneeze, 0, 137, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x02)
        jump_to_return_ai_list
    ai_list_end
};

//D:8003713C
u8 dword_D_8003713C[] = { // GLIST_KEYBOARD_RAND_ANIM_SUBROUTINE: play use keyboard animation (subroutine)
    random_generate_greater_than(60, 0x03)
    guard_play_animation(ANIM_keyboard_right_hand1, 0, 69, 0x00, ANIM_DEFAULT_INTERPOLATION)
    goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(120, 0x03)
        guard_play_animation(ANIM_keyboard_right_hand2, 0, 74, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(180, 0x03)
        guard_play_animation(ANIM_keyboard_left_hand, 0, 79, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        guard_play_animation(ANIM_keyboard_right_hand_tapping, 0, 89, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x02)
        jump_to_return_ai_list
    ai_list_end
};

//D:8003717C
u8 dword_D_8003717C[] = { // GLIST_DETECT_BOND_DEAF_NO_CLONE_NO_IDLE_ANIM: wait for bond detection (deaf/no clones/no idling)
    goto_loop_start(0x01) // wait for guard to stop moving before branching to next logic
        if_guard_has_stopped_moving(0x06)
        goto_loop_repeat(0x01)
    label(0x06)
        if_guard_sees_bond(0x07)
        if_guard_was_shot_or_seen_bond_within_last_10_secs(0x0D)
        if_guard_shot_from_bond_missed(0x10)
        if_guard_see_another_guard_shot(0x0D)
        if_guard_see_another_guard_die(0x0D)
        goto_loop_repeat(0x01)
    label(0x10) // bond shot near guard
        random_generate_greater_than(127, 0x07) // 50% chance of playing looking around animation
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE)
    label(0x07) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
    label(0x0D) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800371B4
u8 dword_D_800371B4[] = { // GLIST_FIRE_RAND_ANIM_SUBROUTINE: fire at bond with random animation (subroutine)
    if_guard_bitfield_is_set_on(BITFIELD_DONT_POINT_AT_BOND, 0x03) // if guard already pointed at bond, goto label 03
    random_generate_greater_than(32, 0x03) // 12.5% chance of pointing to bond
    guard_points_at_bond
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // don't point again, thank you object permanence
    jump_to_return_ai_list // guard pointed at bond, return to list
    label(0x03)
        guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // set flag so we don't point at bond, only do that for first time in list
        guard_try_throwing_grenade(0x02) // attempt to throw grenade, depends on chr->grenadeprob value
    label(0x03)
        random_generate_greater_than(10, 0x03)
        guard_try_firing_roll(0x02)
    label(0x03)
        random_generate_greater_than(10, 0x03)
        guard_try_hopping_sideways(0x02)
    label(0x03)
        random_generate_greater_than(25, 0x03)
        guard_try_sidestepping(0x02)
    label(0x03)
        random_generate_greater_than(50, 0x03)
        guard_try_running_to_side(0x02)
    label(0x03)
        random_generate_greater_than(64, 0x03)
        guard_try_firing_walk(0x02) // infinite ammo death sentence ;)
    label(0x03)
        if_random_seed_greater_than(127, 0x03)
        guard_try_firing_run(0x02)
    label(0x03)
        random_generate_greater_than(127, 0x0B)
        guard_try_fire_or_aim_at_target(TARGET_BOND, 0, 0x02)
    label(0x0B)
        guard_try_fire_or_aim_at_target_kneel(TARGET_BOND, 0, 0x02)
    label(0x02) // guard did the thing, now go back home
        jump_to_return_ai_list
    ai_list_end
};

//D:8003720C
u8 dword_D_8003720C[] = { // GLIST_RUN_TO_BOND_SUBROUTINE: run to bond and fire (subroutine)
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // guard is aware of bond, so don't point at him when first spotted
    guard_try_running_to_bond_position(0x01) // goto loop if bond position is reachable
    jump_to_return_ai_list // if guard can't reach bond, return to ai list (read guard_try_running_to_bond_position command info)
    goto_loop_start(0x01)
        if_guard_has_stopped_moving(0x06)
        if_guard_sees_bond(0x07) // detected bond, goto attack list
        goto_loop_repeat(0x01)
    label(0x07)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
    label(0x06)
        jump_to_return_ai_list
    ai_list_end
};

//D:80037224
u8 dword_D_80037224[] = { // GLIST_SPAWN_CLONE_OR_RUN_TO_BOND: if chr has been seen, run to bond - else spawn clone
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // guard is aware of bond, so don't point at him when first spotted
    if_guard_has_not_been_seen(0x0E) // if guard has yet to be seen by bond, goto 0E
    jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE) // guard has been seen, run to bond and fire
    label(0x0E)
        if_chr_does_not_exist(CHR_CLONE, 0x0E) // if clone doesn't exist, goto 0E
        jump_to_ai_list(CHR_SELF, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE) // continue idling
    label(0x0E)
        chr_try_spawning_clone(CHR_SELF, GLIST_RUN_TO_BOND_AND_FIRE, 0x03) // attempt to spawn clone with run to bond list assigned, if success goto 03
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE) // guard failed to spawn (not enough memory/guard doesn't have clone flag on), just run at bond anyway
    label(0x03) // if clone spawn was successful
        jump_to_ai_list(CHR_SELF, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE) // set original chr to sit tight while the clone does all the work, giving the illusion that bunker ii is a crowded complex
    ai_list_end
};

//D:80037248
u8 dword_D_80037248[] = { // GLIST_RUN_TO_BOND_AND_FIRE: run to bond and fire
    set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
    jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:80037250
u8 dword_D_80037250[] = { // GLIST_DETECT_BOND_NO_CLONE_NO_IDLE_ANIM: wait for bond detection (no clones/no idling)
    goto_loop_start(0x01) // wait for guard to stop moving before branching to next logic
        if_guard_sees_bond(0x07)
        if_guard_was_shot_or_seen_bond_within_last_10_secs(0x0D)
        if_guard_heard_bond_within_last_10_secs(0x0D)
        if_guard_shot_from_bond_missed(0x0D)
        if_guard_see_another_guard_shot(0x0D)
        if_guard_see_another_guard_die(0x0D)
        goto_loop_repeat(0x01)
    label(0x07) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
    label(0x0D) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    label(0x0E) // unused spawn clone reaction for hearing bond, likely made game too difficult/slow
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_SPAWN_CLONE_OR_RUN_TO_BOND)
    ai_list_end
};

//D:80037280
u8 dword_D_80037280[] = { // GLIST_RUN_TO_CHR_PADPRESET_AND_ACTIVATE_ALARM: run to chr->padpreset1 and activate alarm
    goto_loop_start(0x01) // wait for guard to stop moving before branching to next logic
        if_guard_has_stopped_moving(0x06)
        goto_loop_repeat(0x01)
    label(0x06)
        if_guard_sees_bond(0x0F)
        if_guard_hits_missed_greater_than(0, 0x10)
        if_guard_heard_bond_within_last_10_secs(0x10)
        if_guard_see_another_guard_shot(0x10)
        if_guard_see_another_guard_die(0x10)
        goto_loop_repeat(0x01)
    label(0x10) // a guard in sight was killed/shot, heard bond or bond shot guard
        if_guard_hits_greater_than(0, 0x0F) // doesn't make sense why the guard would be mildly curious about getting shot
        guard_looks_around_self
    goto_loop_start(0x04) // wait for guard to stop moving before branching to next logic (triggered by look around animation)
        if_guard_has_stopped_moving(0x0F)
        goto_loop_repeat(0x04)
    label(0x0F)
        guard_runs_to_pad(PAD_PRESET)
    goto_loop_start(0x03) // wait for guard to stop moving (reached destination/guard was shot)
        if_guard_has_stopped_moving(0x02)
        goto_loop_repeat(0x03)
    label(0x02)
        if_chr_meters_to_pad_greater_than(CHR_SELF, 1, PAD_PRESET, 0x02) // if guard is more than 1 meter away from alarm, skip to attack ai list
        guard_try_triggering_alarm_at_pad(PAD_PRESET, 0x05)
        goto_next(0x02) // didn't activate alarm (alarm destroyed?)
    goto_loop_start(0x05) // wait for guard to finish activating alarm
        if_guard_has_stopped_moving(0x02)
        goto_loop_repeat(0x05)
    label(0x02)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800372D0
u8 dword_D_800372D0[] = { // GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE: startle character (subroutine)
    guard_looks_around_self // trigger animation
    goto_loop_start(0x01)
        if_guard_has_stopped_moving(0x02) // wait for chr to stop moving
        goto_loop_repeat(0x01)
    label(0x02) // chr stopped moving
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800372E0
u8 dword_D_800372E0[] = { // GLIST_RUN_TO_BOND_AND_FIRE_HALT_CHR_RANDOMLY: forever chase bond and fire (halt randomly)
    label(0x28)
        guard_try_running_to_bond_position(0x1B) // goto loop if bond position is reachable
        debug_log 'n','o',' ','g','o','!','\n', debug_log_end // guard can't reach bond
    goto_loop_start(0x1B)
        if_guard_and_bond_within_line_of_sight(0x06)
        if_guard_has_stopped_moving(0x02)
        goto_loop_repeat(0x1B)
    label(0x01)
        ai_sleep
        if_guard_hits_less_than(6, 0x2D)
        if_guard_flags_is_set_on(CHRFLAG_INVINCIBLE, 0x2F)
    label(0x2D)
        if_guard_has_stopped_moving(0x06)
        if_guard_meters_to_bond_greater_than(20, 0x03) // if guard is further than 20 meters away from bond, goto 03
        goto_first(0x01)
    label(0x03)
        goto_first(0x28)
    label(0x06)
        if_guard_and_bond_within_line_of_sight(0x03)
        goto_next(0x02)
    label(0x24)
        ai_sleep
        if_guard_meters_to_bond_less_than(5, 0x03) // if guard is within 5 meters from bond, goto 03
        if_guard_has_stopped_moving(0x03)
        goto_first(0x28)
    label(0x03)
        if_guard_flags_is_set_on(CHRFLAG_INVINCIBLE, 0x2F)
    label(0x2B)
        random_generate_greater_than(10, 0x03)
        guard_try_throwing_grenade(0x02) // attempt to throw grenade, depends on chr->grenadeprob value
    label(0x03)
        if_random_seed_greater_than(50, 0x03)
        guard_try_sidestepping(0x02)
    label(0x03)
        if_random_seed_greater_than(60, 0x03)
        guard_try_firing_roll(0x02)
    label(0x03)
        if_random_seed_greater_than(80, 0x03)
        guard_try_firing_roll(0x02)
    label(0x03)
        if_random_seed_greater_than(100, 0x03)
        guard_try_firing_walk(0x02)
    label(0x03)
        if_random_seed_greater_than(150, 0x03)
        guard_try_firing_run(0x02)
    label(0x03)
        if_random_seed_greater_than(200, 0x03)
        guard_try_fire_or_aim_at_target(TARGET_BOND, 0, 0x02)
    label(0x03)
        guard_try_fire_or_aim_at_target_kneel(TARGET_BOND, 0, 0x02)
    label(0x02)
        if_guard_and_bond_within_line_of_sight(0x03)
        goto_next(0x1B)
    label(0x1B)
        ai_sleep
        random_generate_greater_than(160, 0x03)
        goto_next(0x1C)
    label(0x03)
        ai_sleep
        goto_first(0x01)
    label(0x1C)
        local_timer_reset_start
        guard_try_running_to_bond_position(0x1D)
    goto_loop_start(0x1D)
        if_guard_has_stopped_moving(0x03)
        if_local_timer_seconds_greater_than(1, 0x03)
        goto_loop_repeat(0x1D)
    label(0x03)
        guard_animation_stop
        debug_log 'w','a','i','t','\n', debug_log_end
        guard_bitfield_set_off(0x04)
        random_generate_greater_than(160, 0x03)
        guard_bitfield_set_on(0x04)
    label(0x03)
        local_timer_reset_start
    label(0x1E)
        ai_sleep
        if_guard_and_bond_within_line_of_sight(0x03)
        if_guard_shot_from_bond_missed(0x03)
        ai_sleep
        if_local_timer_seconds_less_than(10, 0x04) // if timer less than 10 seconds, goto 04
        if_guard_bitfield_is_set_on(0x04, 0x05)
        goto_first(0x28)
    label(0x05)
        goto_first(0x1C)
    label(0x04)
        goto_first(0x1E)
    label(0x03)
        goto_first(0x01)
    label(0x2F)
        if_guard_hits_less_than(6, 0x03)
        guard_flags_set_off(CHRFLAG_INVINCIBLE)
    label(0x03)
        goto_first(0x2B)
    ai_list_end
};

//D:800373D0
u8 dword_D_800373D0[] = { // GLIST_WAIT_ONE_SECOND_SUBROUTINE: wait for one second (subroutine)
    local_timer_reset_start
    goto_loop_start(0x1B)
        if_local_timer_seconds_greater_than(1, 0x03) // wait one second
        goto_loop_repeat(0x1B)
    label(0x03)
        jump_to_return_ai_list
    ai_list_end
};

//D:800373E0
u8 dword_D_800373E0[] = { // GLIST_EXIT_LEVEL: exit level
    exit_level
    jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:800373E8
u8 dword_D_800373E8[] = { // GLIST_DRAW_DD44_AND_FIRE: draw dd44 and fire
    guard_set_speed_rating(40) // fast boi watch out!
    guard_set_accuracy_rating(50)
    label(0x03)
        guard_try_facing_target(TARGET_BOND, 0, 0x03)
    label(0x03)
        local_timer_reset_start
    goto_loop_start(0x1B)
        if_local_timer_greater_than(20, 0x03) // wait 1/3 of a second
        goto_loop_repeat(0x1B)
    label(0x03)
        guard_play_animation(ANIM_fire_standing_draw_one_handed_weapon_fast, 0, 20, ANIM_LOOP_HOLD_LAST_FRAME, ANIM_DEFAULT_INTERPOLATION)
    goto_loop_start(0x1C)
        if_guard_has_stopped_moving(0x03)
        goto_loop_repeat(0x1C)
    label(0x03)
        guard_try_spawning_item(PROP_chrtt33, ITEM_TT33, 0, 0x03)
    label(0x03)
        guard_try_fire_or_aim_at_target(TARGET_BOND | TARGET_AIM_ONLY, 0, 0x03) // aim...
    label(0x03)
        guard_try_fire_or_aim_at_target_update(TARGET_BOND, 0, 0x03) // FIRE!
    label(0x03)
    goto_loop_start(0x1E) // loop until guard has stopped firing at bond
        if_guard_has_stopped_moving(0x03)
        goto_loop_repeat(0x1E)
    label(0x03)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:80037444
u8 dword_D_80037444[] = { // GLIST_REMOVE_CHR: remove chr
    chr_remove_instant(CHR_SELF) // remove self
    jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:8003744C
struct struct_13 D_8003744C[] = { // global ai lists (glists)
    {dword_D_80037070, GLIST_AIM_AT_BOND},
    {dword_D_8003707C, GLIST_END_ROUTINE},
    {dword_D_80037084, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE},
    {dword_D_800370DC, GLIST_IDLE_RAND_ANIM_SUBROUTINE},
    {dword_D_8003713C, GLIST_KEYBOARD_RAND_ANIM_SUBROUTINE},
    {dword_D_8003717C, GLIST_DETECT_BOND_DEAF_NO_CLONE_NO_IDLE_ANIM},
    {dword_D_800371B4, GLIST_FIRE_RAND_ANIM_SUBROUTINE},
    {dword_D_80037250, GLIST_DETECT_BOND_NO_CLONE_NO_IDLE_ANIM},
    {dword_D_8003720C, GLIST_RUN_TO_BOND_SUBROUTINE},
    {dword_D_80037280, GLIST_RUN_TO_CHR_PADPRESET_AND_ACTIVATE_ALARM},
    {dword_D_800372D0, GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE},
    {dword_D_80037224, GLIST_SPAWN_CLONE_OR_RUN_TO_BOND},
    {dword_D_80037248, GLIST_RUN_TO_BOND_AND_FIRE},
    {dword_D_800372E0, GLIST_RUN_TO_BOND_AND_FIRE_HALT_CHR_RANDOMLY},
    {dword_D_800373D0, GLIST_WAIT_ONE_SECOND_SUBROUTINE},
    {dword_D_800373E0, GLIST_EXIT_LEVEL},
    {dword_D_800373E8, GLIST_DRAW_DD44_AND_FIRE},
    {dword_D_80037444, GLIST_REMOVE_CHR}
};
//D:800374DC
u32 D_800374DC[] = {0,0};

//D:800374E4
char * setup_text_pointers[] = {
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

