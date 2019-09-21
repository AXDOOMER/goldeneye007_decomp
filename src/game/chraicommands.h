#ifndef _CHRAICOMMANDS_H_
#define _CHRAICOMMANDS_H_
#include "ultra64.h"

/*=============================================================================
// terminology:
// chr              character
// obj              objective
// chr ai lists     0400-04FF range
// obj ai lists     1000-10FF range
// global ai lists  0000-0011 range
//=============================================================================
// info:
// character ai list info -
// chr ai lists drive the gameplay, such as attacking/chasing player. a chr ai list
// will not execute until a guard is assigned that list (unlike obj lists). multiple
// guards can use the same ai list - each guard is treated as a independent thread
// with their own instance of unique data
// objective ai list info -
// obj ai lists run continuously in the background without a guard attached
// they still have a chr struct but lack a model/position in the level, they are
// commonly used for level scripting (objectives) or monitoring guard spawns
//=============================================================================
// note:
// commands with guard prefix are exclusive to chr/global ai lists, they can't be
// executed by obj ai lists (10XX) or it will crash! commands with chr prefix can
// be from both obj and chr ai lists - exceptions to this rule are detailed within
// the command description
//===========================================================================*/

#define chararray16(input) (input & 0xFF00) >> 8, input & 0x00FF
#define chararray32(input) (input & 0xFF000000) >> 24, (input & 0x00FF0000) >> 16, (input & 0x0000FF00) >> 8, input & 0x000000FF

#define CHRAI_ID_PLAYER -8
#define CHRAI_ID_CLONE -7
#define CHRAI_ID_SEE_SHOT -6
#define CHRAI_ID_SEE_DIE -5
#define CHRAI_ID_PRESET -4
#define CHRAI_ID_SELF -3

/*=============================================================================
// name: goto_next
// command id: 00
//=============================================================================
// info: goto the next label (command 02) - skips all commands between command
//       and goto label - continues executing after found label
//===========================================================================*/
#define goto_next_ID 0x00
#define goto_next_LENGTH 0x02
#define goto_next(label) \
        goto_next_ID, \
        label,

/*=============================================================================
// name: goto_first
// command id: 01
//=============================================================================
// info: like goto_next, but it starts scanning label from start of list
//===========================================================================*/
#define goto_first_ID 0x01
#define goto_first_LENGTH 0x02
#define goto_first(label) \
        goto_first_ID, \
        label,

/*=============================================================================
// name: label
// command id: 02
//=============================================================================
// info: label marker for ai list - used for all commands that return true
//===========================================================================*/
#define label_ID 0x02
#define label_LENGTH 0x02
#define label(id) \
        label_ID, \
        id,

/*=============================================================================
// name: sleep
// id number: 03
//=============================================================================
// info: halt the ai list - frees engine to start executing next ai list until
//       all lists have been executed for game tick.
// note: offscreen/idle guards will take 14 game ticks instead of 1 tick on sleep
//===========================================================================*/
#define sleep_ID 0x03
#define sleep_LENGTH 0x01
#define sleep \
        sleep_ID,

/*=============================================================================
// name: ai_list_end
// command id: 04
//=============================================================================
// info: used for ai list parser to check when list ends
// note: not recommended to execute this command - to finish a list create an
// infinite loop (cmds 02/03/01) or jump to global list #0001 when list completes
//===========================================================================*/
#define ai_list_end_ID 0x04
#define ai_list_end_LENGTH 0x01
#define ai_list_end \
        ai_list_end_ID

/*=============================================================================
// name: goto_ai_list
// command id: 05
//=============================================================================
// info: goto another list and start executing from beginning
// note: cannot jump to obj lists (10XX)
//===========================================================================*/
#define goto_ai_list_ID 0x05
#define goto_ai_list_LENGTH 0x04
#define goto_ai_list(chr_id, ai_list) \
        goto_ai_list_ID, \
        chr_id, \
        chararray16(ai_list),

/*=============================================================================
// name: set_return_ai_list
// command id: 06
//=============================================================================
// info: store a list ptr in current chr struct - used for command 07 return
// note: stored list cannot be set to obj lists (10XX)
//===========================================================================*/
#define set_return_ai_list_ID 0x06
#define set_return_ai_list_LENGTH 0x03
#define set_return_ai_list(ai_list) \
        set_return_ai_list_ID, \
        chararray16(ai_list),

/*=============================================================================
// name: goto_return_ai_list
// command id: 07
//=============================================================================
// info: goto the return list set in current chr struct
//===========================================================================*/
#define goto_return_ai_list_ID 0x07
#define goto_return_ai_list_LENGTH 0x01
#define goto_return_ai_list \
        goto_return_ai_list_ID,

/*=============================================================================
// name: guard_animation_stop
// command id: 08
//=============================================================================
// info: reset guard back to idle pose - can be used to stop guards in place
//===========================================================================*/
#define guard_reset_pose_ID 0x08
#define guard_reset_pose_LENGTH 0x01
#define guard_reset_pose \
        guard_reset_pose_ID,

/*=============================================================================
// name: guard_kneel
// command id: 09
//=============================================================================
// info: make guard kneel on one knee
//===========================================================================*/
#define guard_kneel_ID 0x09
#define guard_kneel_LENGTH 0x01
#define guard_kneel \
        guard_kneel_ID,

/*=============================================================================
// name: guard_animation
// command id: 0A
//=============================================================================
// info: set guard to playback animation
//=============================================================================
// arguments:
// start/end set to -1/-1 will playback the entire animation length
// tween time will set how long it will take to transition from the previous state
// (if this value is too low it may crash! - use 0x10 if unsure)
// start/end keyframe and tween use 60 tick units
// bitfield:
// 01 - mirror animation
// 02 - ?? (cancels no translation flag)
// 04 - loop/hold last frame (required for reverse flag)
// 08 - play sneeze sfx with animation 9F (triggers 50% of the time)
// 10 - idle pose after animation has completed (does not work with looping animations)
// 20 - translation multiplier x 4 (used for dam and cradle cinema)
// 40 - no translation
// 80 - reverse animation (only for looped animations)
//===========================================================================*/
#define guard_animation_ID 0x0A
#define guard_animation_LENGTH 0x09
#define guard_animation(animation_id, start_timer60, end_timer60, bitfield, tween_timer60) \
        guard_animation_ID, \
        chararray16(animation_id), \
        chararray16(start_timer60), \
        chararray16(end_timer60), \
        bitfield, \
        tween_timer60,

/*=============================================================================
// name: guard_playing_animation
// command id: 0B
//=============================================================================
// info: if guard is in animation playback state (ACT_ANIM), goto label
//===========================================================================*/
#define guard_playing_animation_ID 0x0B
#define guard_playing_animation_LENGTH 0x02
#define guard_playing_animation(label) \
        guard_playing_animation_ID, \
        label,

/*=============================================================================
// name: guard_points_at_bond
// command id: 0C
//=============================================================================
// info: guard points if bond is directly in front of guard, else command is ignored
//===========================================================================*/
#define guard_points_at_bond_ID 0x0C
#define guard_points_at_bond_LENGTH 0x01
#define guard_points_at_bond \
        guard_points_at_bond_ID,

/*=============================================================================
// name: guard_animation_looks_around_self
// command id: 0D
//=============================================================================
// info: set guard to playback animation - command is used when firing around guard
//===========================================================================*/
#define guard_animation_looks_around_self_ID 0x0D
#define guard_animation_looks_around_self_LENGTH 0x01
#define guard_animation_looks_around_self \
        guard_animation_looks_around_self_ID,

/*=============================================================================
// name: guard_jogs_to_predefined
// command id: 1D
//=============================================================================
// info: makes the guard jog to predefined pad 2328
//===========================================================================*/
#define guard_jogs_to_predefined_ID 0x1D
#define guard_jogs_to_predefined_LENGTH 0x01
#define guard_jogs_to_predefined \
        guard_jogs_to_predefined_ID,


/*=============================================================================
// name: guard_surrenders
// command id: 21
//=============================================================================
// info: makes a guard surrender and drop all his objects
//===========================================================================*/
#define guard_surrenders_ID 0x21
#define guard_surrenders_LENGTH 0x01
#define guard_surrenders \
        guard_surrenders_ID,

/*=============================================================================
// name: guard_move_disappear
// command id: 22
//=============================================================================
// info: 
//===========================================================================*/
#define guard_move_disappear_ID 0x22
#define guard_move_disappear_LENGTH 0x01
#define guard_move_disappear \
        guard_move_disappear_ID,


/*=============================================================================
// name: activate_alarm
// command id: 25
//=============================================================================
// info: activates alarm
//===========================================================================*/

#define activate_alarm_ID 0x25
#define activate_alarm_LENGTH 0x01
#define activate_alarm \
        activate_alarm_ID,

/*=============================================================================
// name: deactivate_alarm
// command id: 26
//=============================================================================
// info: deactivates alarm
//===========================================================================*/

#define deactivate_alarm_ID 0x26
#define deactivate_alarm_LENGTH 0x01
#define deactivate_alarm \
        deactivate_alarm_ID,

/*=============================================================================
// name: seed_random_byte
// command id: 33
//=============================================================================
// info: seeds random byte
//===========================================================================*/

#define seed_random_byte_ID 0x33
#define seed_random_byte_LENGTH 0x01
#define seed_random_byte \
        seed_random_byte_ID,

/*=============================================================================
// name: chr_in_room_with_pad
// command id: 54
//=============================================================================
// info: if chr id in same room with pad, goto label
//===========================================================================*/
#define chr_in_room_with_pad_ID 0x54
#define chr_in_room_with_pad_LENGTH 0x05
#define chr_in_room_with_pad(chr_id, pad, label) \
        chr_in_room_with_pad_ID, \
        chr_id, \
        chararray16(pad), \
        label,

/*=============================================================================
// name: bond_in_room_with_pad
// command id: 55
//=============================================================================
// info: if bond in same room with pad, goto label
//===========================================================================*/
#define bond_in_room_with_pad_ID 0x55
#define bond_in_room_with_pad_LENGTH 0x04
#define bond_in_room_with_pad(pad, label) \
        bond_in_room_with_pad_ID, \
        chararray16(pad), \
        label,

/*=============================================================================
// name: reset_cycle_counter_and_enable
// command id: AE
//=============================================================================
// info: resets the cycle counter and enables it
//===========================================================================*/
#define reset_cycle_counter_and_enable_ID 0xAE
#define reset_cycle_counter_and_enable_LENGTH 0x01
#define reset_cycle_counter_and_enable \
        reset_cycle_counter_and_enable_ID,

/*=============================================================================
// name: reset_cycle_counter
// command id: AF
//=============================================================================
// info: resets the cycle counter
//===========================================================================*/
#define reset_cycle_counter_ID 0xAF
#define reset_cycle_counter_LENGTH 0x01
#define reset_cycle_counter \
        reset_cycle_counter_ID,

/*=============================================================================
// name: disable_cycle_counter
// command id: B0
//=============================================================================
// info: stops the cycle counter
//===========================================================================*/
#define disable_cycle_counter_ID 0xB0
#define disable_cycle_counter_LENGTH 0x01
#define disable_cycle_counter \
        disable_cycle_counter_ID,

/*=============================================================================
// name: enable_cycle_counter
// command id: B1
//=============================================================================
// info: starts the cycle counter
//===========================================================================*/
#define enable_cycle_counter_ID 0xB1
#define enable_cycle_counter_LENGTH 0x01
#define enable_cycle_counter \
        enable_cycle_counter_ID

/*=============================================================================
// name: show_timer
// command id: B5
//=============================================================================
// info: shows the timer
//===========================================================================*/
#define show_timer_ID 0xB5
#define show_timer_LENGTH 0x01
#define show_timer \
        show_timer_ID,

/*=============================================================================
// name: hide_timer
// command id: B6
//=============================================================================
// info: hides the timer
//===========================================================================*/
#define hide_timer_ID 0xB6
#define hide_timer_LENGTH 0x01
#define hide_timer \
        hide_timer_ID,

/*=============================================================================
// name: stop_timer
// command id: B8
//=============================================================================
// info: stops the timer
//===========================================================================*/
#define stop_timer_ID 0xB8
#define stop_timer_LENGTH 0x01
#define stop_timer \
        stop_timer_ID,

/*=============================================================================
// name: start_timer
// command id: B9
//=============================================================================
// info: starts the timer
//===========================================================================*/
#define start_timer_ID 0xB9
#define start_timer_LENGTH 0x01
#define start_timer \
        start_timer_ID,

/*=============================================================================
// name: exit_level
// command id: D2
//=============================================================================
// info: exits the level
//===========================================================================*/
#define exit_level_ID 0xD2
#define exit_level_LENGTH 0x01
#define exit_level \
        exit_level_ID,

/*=============================================================================
// name: return_from_camera_scene
// command id: D3
//=============================================================================
// info: 
//===========================================================================*/
#define return_from_camera_scene_ID 0xD3
#define return_from_camera_scene_LENGTH 0x01
#define return_from_camera_scene \
        return_from_camera_scene_ID,

/*=============================================================================
// name: enable_all_on_screen_displays
// command id: D8
//=============================================================================
// info:
//===========================================================================*/
#define enable_all_on_screen_displays_ID 0xD8
#define enable_all_on_screen_displays_LENGTH 0x01
#define enable_all_on_screen_displays \
        enable_all_on_screen_displays_ID,

/*=============================================================================
// name: fade_out
// command id: DA
//=============================================================================
// info: fades the screen out
//===========================================================================*/
#define fade_out_ID 0xDA
#define fade_out_LENGTH 0x01
#define fade_out \
        fade_out_ID,

/*=============================================================================
// name: fade_in
// command id: DB
//=============================================================================
// info: fades the screen in
//===========================================================================*/
#define fade_in_ID 0xDB
#define fade_in_LENGTH 0x01
#define fade_in \
        fade_in_ID,

/*=============================================================================
// name: hide_all_chr
// command id: DD
//=============================================================================
// info: 
//===========================================================================*/
#define hide_all_chr_ID 0xDD
#define hide_all_chr_LENGTH 0x01
#define hide_all_chr \
        hide_all_chr_ID,

/*=============================================================================
// name: show_all_chr
// command id: DE
//=============================================================================
// info:
//===========================================================================*/
#define show_all_chr_ID 0xDE
#define show_all_chr_LENGTH 0x01
#define show_all_chr \
        show_all_chr_ID,

/*=============================================================================
// name: sky_switch_instant
// command id: E9
//=============================================================================
// info: instantly switches sky bank
//===========================================================================*/
#define sky_switch_instant_ID 0xE9
#define sky_switch_instant_LENGTH 0x01
#define sky_switch_instant \
        sky_switch_instant_ID,

/*=============================================================================
// name: stop_game_time
// command id: EA
//=============================================================================
// info: stops the mission time
//===========================================================================*/
#define stop_game_time_ID 0xEA
#define stop_game_time_LENGTH 0x01
#define stop_game_time \
        stop_game_time_ID,

/*=============================================================================
// name: bond_disable_pickups_and_damage
// command id: EC
//=============================================================================
// info: Use this for level exit trigger, so Bond cannot die during exit cutscene.
//===========================================================================*/
#define bond_disable_pickups_and_damage_ID 0xEC
#define bond_disable_pickups_and_damage_LENGTH 0x01
#define bond_disable_pickups_and_damage \
        bond_disable_pickups_and_damage_ID,

/*=============================================================================
// name: hide_first_person_display
// command id: ED
//=============================================================================
// info: 
//===========================================================================*/
#define hide_first_person_display_ID 0xED
#define hide_first_person_display_LENGTH 0x01
#define hide_first_person_display \
        hide_first_person_display_ID,

/*=============================================================================
// name: trigger_credits
// command id: EF
//=============================================================================
// info:
//===========================================================================*/
#define trigger_credits_ID 0xEF
#define trigger_credits_LENGTH 0x01
#define trigger_credits \
        trigger_credits_ID,

/*=============================================================================
// name: trigger_explosions
// command id: F6
//=============================================================================
// info: triggers explosions around the player
//===========================================================================*/
#define trigger_explosions_ID 0xF6
#define trigger_explosions_LENGTH 0x01
#define trigger_explosions \
        trigger_explosions_ID,

/*=============================================================================
// name: set_killed_in_action
// command id: F9
//=============================================================================
// info: sets player state to KIA. Automatic mission failure
//===========================================================================*/
#define set_killed_in_action_ID 0xF9
#define set_killed_in_action_LENGTH 0x01
#define set_killed_in_action \
        set_killed_in_action_ID,

/*=============================================================================
// name: guard_raises_arms
// command id: FA
//=============================================================================
// info: makes guard raise his arms for half a second
//===========================================================================*/
#define guard_raises_arms_ID 0xFA
#define guard_raises_arms_LENGTH 0x01
#define guard_raises_arms \
        guard_raises_arms_ID,

/*=============================================================================
// name: sky_switch_transition
// command id: FB
//=============================================================================
// info: fades between sky banks
//===========================================================================*/
#define sky_switch_transition_ID 0xFB
#define sky_switch_transition_LENGTH 0x01
#define sky_switch_transition \
        sky_switch_transition_ID,


#endif
