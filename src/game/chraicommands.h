#ifndef _CHRAICOMMANDS_H_
#define _CHRAICOMMANDS_H_
#include "ultra64.h"

/*=============================================================================
// chr ai commands reference
// programmed by mark edmonds and martin hollis
//=============================================================================
// terminology:
// chr              character
// obj              objective
// chr ai lists     0400-04FF range
// obj ai lists     1000-10FF range
// global ai lists  0000-0011 range
//=============================================================================
// character ai list info
//=============================================================================
// chr ai lists drive the gameplay, such as attacking/chasing player. a chr ai
// list will not execute until a guard is assigned that list (unlike obj lists).
// multiple guards can use the same ai list - each guard is treated as a independent
// thread with their own instance of unique data
//=============================================================================
// objective ai list info
//=============================================================================
// obj ai lists run continuously in the background without a guard attached.
// they still have a chr struct but lack a model/position in the level, they are
// commonly used for level scripting (objectives) or monitoring guard spawns.
// obj ai lists cannot run guard commands due to the lack of level presence
//=============================================================================
// global ai list info
//=============================================================================
// global ai lists are 0x11 useful lists accessible with every level. the above
// lists (chr/obj) are unique to each setup file, compared to global lists which
// are accessible throughout the entire game. they contain generic guard ai lists
// used for most levels
//=============================================================================
// note:
// commands with guard prefix are exclusive to guards in levels, they can't be
// executed by obj ai lists (10XX) or it will crash! commands with chr prefix can
// be from both obj and chr ai lists - exceptions to this rule are detailed within
// the command description
//===========================================================================*/

#define chararray16(input) (input & 0xFF00) >> 8, input & 0x00FF
#define chararray32(input) (input & 0xFF000000) >> 24, (input & 0x00FF0000) >> 16, (input & 0x0000FF00) >> 8, input & 0x000000FF

#define CHRAI_ID_PLAYER -8
#define CHRAI_ID_CLONE -7
#define CHRAI_ID_SEE_SHOT -6 /* stored as chr->chrseeshot */
#define CHRAI_ID_SEE_DIE -5 /* stored as chr->chrseedie */
#define CHRAI_ID_PRESET -4 /* stored as chr->chrpreset1 */
#define CHRAI_ID_SELF -3

#define PAD_PRESET 9000 /* stored as chr->padpreset1 */

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
// info: make chr goto another list and start executing from beginning
// note: cannot jump to obj lists (10XX)
//===========================================================================*/
#define goto_ai_list_ID 0x05
#define goto_ai_list_LENGTH 0x04
#define goto_ai_list(chr_num, ai_list) \
        goto_ai_list_ID, \
        chr_num, \
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
// info: set guard to playback animation - used when shots land near guard
//===========================================================================*/
#define guard_animation_looks_around_self_ID 0x0D
#define guard_animation_looks_around_self_LENGTH 0x01
#define guard_animation_looks_around_self \
        guard_animation_looks_around_self_ID,

/*=============================================================================
// name: guard_runs_to_pad
// command id: 1C
//=============================================================================
// info: makes the guard run to pad
//===========================================================================*/
#define guard_runs_to_pad_ID 0x1C
#define guard_runs_to_pad_LENGTH 0x03
#define guard_runs_to_pad(pad) \
        guard_runs_to_pad_ID, \
        chararray16(pad),

/*=============================================================================
// name: guard_runs_to_padpreset
// command id: 1D
//=============================================================================
// info: makes the guard run to guard->padpreset1 (PAD_PRESET - 9000)
//===========================================================================*/
#define guard_runs_to_padpreset_ID 0x1D
#define guard_runs_to_padpreset_LENGTH 0x01
#define guard_runs_to_padpreset \
        guard_runs_to_padpreset_ID,

/*=============================================================================
// name: guard_walks_to_pad
// command id: 1E
//=============================================================================
// info: makes the guard walk to pad
//===========================================================================*/
#define guard_walks_to_pad_ID 0x1E
#define guard_walks_to_pad_LENGTH 0x03
#define guard_walks_to_pad(pad) \
        guard_walks_to_pad_ID, \
        chararray16(pad),

/*=============================================================================
// name: guard_sprints_to_pad
// command id: 1F
//=============================================================================
// info: makes the guard sprint to pad
//===========================================================================*/
#define guard_sprints_to_pad_ID 0x1F
#define guard_sprints_to_pad_LENGTH 0x03
#define guard_sprints_to_pad(pad) \
        guard_sprints_to_pad_ID, \
        chararray16(pad),

/*=============================================================================
// name: guard_set_patrol
// command id: 20
//=============================================================================
// info: makes guard walk a predefined path within setup
// note: usually paired with jump to global list #0005 or #0007
//===========================================================================*/
#define guard_set_patrol_ID 0x20
#define guard_set_patrol_LENGTH 0x02
#define guard_set_patrol(path_num) \
        guard_set_patrol_ID, \
        path_num,

/*=============================================================================
// name: guard_surrenders
// command id: 21
//=============================================================================
// info: makes a guard surrender and drop all attached and held items
// note: will not drop items embedded within guard
//===========================================================================*/
#define guard_surrenders_ID 0x21
#define guard_surrenders_LENGTH 0x01
#define guard_surrenders \
        guard_surrenders_ID,

/*=============================================================================
// name: guard_remove_fade
// command id: 22
//=============================================================================
// info: sets guard to fade away - fade time is 90 ticks (1.5 seconds). when
//       the fade finishes, automatically remove guard
// note: guard collision is disable during fade - will not drop items
//===========================================================================*/
#define guard_remove_fade_ID 0x22
#define guard_remove_fade_LENGTH 0x01
#define guard_remove_fade \
        guard_remove_fade_ID,

/*=============================================================================
// name: chr_remove_instant
// command id: 23
//=============================================================================
// info: instantly remove chr unlike above command
// note: will not drop items
//===========================================================================*/
#define chr_remove_instant_ID 0x23
#define chr_remove_instant_LENGTH 0x02
#define chr_remove_instant(chr_num) \
        chr_remove_instant_ID, \
        chr_num

/*=============================================================================
// name: alarm_enable
// command id: 25
//=============================================================================
// info: activates alarm
//===========================================================================*/
#define alarm_enable_ID 0x25
#define alarm_enable_LENGTH 0x01
#define alarm_enable \
        alarm_enable_ID,

/*=============================================================================
// name: alarm_disable
// command id: 26
//=============================================================================
// info: deactivates alarm
//===========================================================================*/
#define alarm_disable_ID 0x26
#define alarm_disable_LENGTH 0x01
#define alarm_disable \
        alarm_disable_ID,

/*=============================================================================
// name: random_generate
// command id: 33
//=============================================================================
// info: generate a random byte and store to chr->random
// note: range is 00-FF
//===========================================================================*/
#define random_generate_ID 0x33
#define random_generate_LENGTH 0x01
#define random_generate \
        random_generate_ID,

/*=============================================================================
// name: random_less_than
// command id: 34
//=============================================================================
// info: if chr->random < byte, goto label
// note: compare is unsigned
//===========================================================================*/
#define random_less_than_ID 0x34
#define random_less_than_LENGTH 0x03
#define random_less_than(byte, label) \
        random_less_than_ID, \
        byte, \
        label,

/*=============================================================================
// name: random_greater_than
// command id: 35
//=============================================================================
// info: if chr->random > byte, goto label
// note: compare is unsigned
//===========================================================================*/
#define random_greater_than_ID 0x35
#define random_greater_than_LENGTH 0x03
#define random_greater_than(byte, label) \
        random_greater_than_ID, \
        byte, \
        label,

/*=============================================================================
// name: chr_in_room_with_pad
// command id: 54
//=============================================================================
// info: if chr id in same room with pad, goto label
//===========================================================================*/
#define chr_in_room_with_pad_ID 0x54
#define chr_in_room_with_pad_LENGTH 0x05
#define chr_in_room_with_pad(chr_num, pad, label) \
        chr_in_room_with_pad_ID, \
        chr_num, \
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
// name: timer_reset_start
// command id: AE
//=============================================================================
// info: reset and start chr->timer60
//===========================================================================*/
#define timer_reset_start_ID 0xAE
#define timer_reset_start_LENGTH 0x01
#define timer_reset_start \
        timer_reset_start_ID,

/*=============================================================================
// name: timer_reset
// command id: AF
//=============================================================================
// info: reset chr->timer60
//===========================================================================*/
#define timer_reset_ID 0xAF
#define timer_reset_LENGTH 0x01
#define timer_reset \
        timer_reset_ID,

/*=============================================================================
// name: timer_stop
// command id: B0
//=============================================================================
// info: pauses chr->timer60 (does not reset value)
//===========================================================================*/
#define timer_stop_ID 0xB0
#define timer_stop_LENGTH 0x01
#define timer_stop \
        timer_stop_ID,

/*=============================================================================
// name: timer_start
// command id: B1
//=============================================================================
// info: start chr->timer60 (does not reset value)
//===========================================================================*/
#define timer_start_ID 0xB1
#define timer_start_LENGTH 0x01
#define timer_start \
        timer_start_ID,

/*=============================================================================
// name: hud_timer_show
// command id: B5
//=============================================================================
// info: shows the hud timer
//===========================================================================*/
#define hud_timer_show_ID 0xB5
#define hud_timer_show_LENGTH 0x01
#define hud_timer_show \
        hud_timer_show_ID,

/*=============================================================================
// name: hud_timer_hide
// command id: B6
//=============================================================================
// info: hides the hud timer
// note: can be used as a hidden global timer for objective logic
//===========================================================================*/
#define hud_timer_hide_ID 0xB6
#define hud_timer_hide_LENGTH 0x01
#define hud_timer_hide \
        hud_timer_hide_ID,

/*=============================================================================
// name: hud_timer_set
// command id: B7
//=============================================================================
// info: set the hud timer
// note: to make the timer count up, set to 0 and start timer
//===========================================================================*/
#define hud_timer_set_ID 0xB7
#define hud_timer_set_LENGTH 0x03
#define hud_timer_set(timer60) \
        hud_timer_set_ID, \
        chararray16(timer60),

/*=============================================================================
// name: hud_timer_stop
// command id: B8
//=============================================================================
// info: stops the hud timer
//===========================================================================*/
#define hud_timer_stop_ID 0xB8
#define hud_timer_stop_LENGTH 0x01
#define hud_timer_stop \
        hud_timer_stop_ID,

/*=============================================================================
// name: hud_timer_start
// command id: B9
//=============================================================================
// info: start the hud timer
//===========================================================================*/
#define hud_timer_start_ID 0xB9
#define hud_timer_start_LENGTH 0x01
#define hud_timer_start \
        hud_timer_start_ID,

/*=============================================================================
// name: hud_timer_is_active
// command id: BA
//=============================================================================
// info: if hud timer is active (not paused), goto label
//===========================================================================*/
#define hud_timer_is_active_ID 0xBA
#define hud_timer_is_active_LENGTH 0x02
#define hud_timer_is_active(label) \
        hud_timer_is_active_ID, \
        label,

/*=============================================================================
// name: hud_timer_less_than
// command id: BB
//=============================================================================
// info: if hud timer < short, goto label
// note: if short argument is 0, it will only goto label if timer is less than
// zero (counting up). short value is unsigned and can't test negative values
//===========================================================================*/
#define hud_timer_less_than_ID 0xBB
#define hud_timer_less_than_LENGTH 0x04
#define hud_timer_less_than(short, label) \
        hud_timer_less_than_ID, \
        chararray16(timer60), \
        label,

/*=============================================================================
// name: hud_timer_greater_than
// command id: BC
//=============================================================================
// info: if hud timer > short, goto label
// note: if short argument is 0, it will only goto label if timer is greater than
// zero (counting down). short value is unsigned and can't test negative values
//===========================================================================*/
#define hud_timer_greater_than_ID 0xBC
#define hud_timer_greater_than_LENGTH 0x04
#define hud_timer_greater_than(short, label) \
        hud_timer_greater_than_ID, \
        chararray16(timer60), \
        label,

/*=============================================================================
// name: bond_in_tank
// command id: D1
//=============================================================================
// info: checks if bond is controlling tank, goto label if true
//===========================================================================*/
#define bond_in_tank_ID 0xD1
#define bond_in_tank_LENGTH 0x02
#define bond_in_tank(label) \
        bond_in_tank_ID, \
        label,

/*=============================================================================
// name: exit_level
// command id: D2
//=============================================================================
// info: exits the level
// note: recommend not to use this command, instead goto global list 0x000F for
// exit cutscene list. retail game has a glitch with hires mode that needs to
// execute this command in a loop, check cuba's 1000 list
//===========================================================================*/
#define exit_level_ID 0xD2
#define exit_level_LENGTH 0x01
#define exit_level \
        exit_level_ID,

/*=============================================================================
// name: camera_return_to_bond
// command id: D3
//=============================================================================
// info: switch back to first person view. must have 3 sleep commands before
//       executing this command
// note: unused command, never used in retail game. tagged items within inventory
//       will become invalid after command - only weapons are safe
//===========================================================================*/
#define camera_return_to_bond_ID 0xD3
#define camera_return_to_bond_LENGTH 0x01
#define camera_return_to_bond \
        camera_return_to_bond_ID,

/*=============================================================================
// name: hud_show_all
// command id: D8
//=============================================================================
// info: show all hud elements that have been disabled by D7
// note: should only be called after D7 command, since it may toggle upper/lower
//       text displays
//===========================================================================*/
#define hud_show_all_ID 0xD8
#define hud_show_all_LENGTH 0x01
#define hud_show_all \
        hud_show_all_ID,

/*=============================================================================
// name: screen_fade_to_black
// command id: DA
//=============================================================================
// info: fades the screen out to black
// note: fade duration is 1 second
//===========================================================================*/
#define screen_fade_to_black_ID 0xDA
#define screen_fade_to_black_LENGTH 0x01
#define screen_fade_to_black \
        screen_fade_to_black_ID,

/*=============================================================================
// name: screen_fade_from_black
// command id: DB
//=============================================================================
// info: fades the screen from black
// note: fade duration is 1 second
//===========================================================================*/
#define screen_fade_from_black_ID 0xDB
#define screen_fade_from_black_LENGTH 0x01
#define screen_fade_from_black \
        screen_fade_from_black_ID,

/*=============================================================================
// name: screen_fade_completed
// command id: DC
//=============================================================================
// info: when screen fade has completed (from/to black), goto label
// note: fade duration is 1 second
//===========================================================================*/
#define screen_fade_if_complete_ID 0xDC
#define screen_fade_if_complete_LENGTH 0x02
#define screen_fade_if_complete(label) \
        screen_fade_if_complete_ID, \
        label,

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
// name: trigger_gas_and_switch_fog
// command id: E9
//=============================================================================
// info: trigger gas event and instantly switch fog to the next fog's slot
// note: this command triggers a gas event. for the level egypt, this command
// will not trigger a gas event, but instead will only switch the fog. this
// command cannot be toggled after executing. level must have a fog assigned
// or will crash!
//===========================================================================*/
#define trigger_gas_and_switch_fog_ID 0xE9
#define trigger_gas_and_switch_fog_LENGTH 0x01
#define trigger_gas_and_switch_fog \
        trigger_gas_and_switch_fog_ID,

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
// name: bond_disable_interaction
// command id: EC
//=============================================================================
// info: disables bond damage and ability to pick up items
// note: commonly used for level exit ai lists - prevents bond dying after
//       triggering exit cutscene
//===========================================================================*/
#define bond_disable_interaction_ID 0xEC
#define bond_disable_interaction_LENGTH 0x01
#define bond_disable_interaction \
        bond_disable_interaction_ID,

/*=============================================================================
// name: bond_hide_weapons
// command id: ED
//=============================================================================
// info: set bond's left/right weapons to be invisible
//===========================================================================*/
#define bond_hide_weapons_ID 0xED
#define bond_hide_weapons_LENGTH 0x01
#define bond_hide_weapons \
        bond_hide_weapons_ID,

/*=============================================================================
// name: roll_credits
// command id: EF
//=============================================================================
// info: credit text and positions are stored in setup intro struct
//===========================================================================*/
#define roll_credits_ID 0xEF
#define roll_credits_LENGTH 0x01
#define roll_credits \
        roll_credits_ID,

/*=============================================================================
// name: trigger_explosions_around_bond
// command id: F6
//=============================================================================
// info: triggers explosions around the player, will continue forever
// note: does not trigger level exit or killed in action state
//===========================================================================*/
#define trigger_explosions_around_bond_ID 0xF6
#define trigger_explosions_around_bond_LENGTH 0x01
#define trigger_explosions_around_bond \
        trigger_explosions_around_bond_ID,

/*=============================================================================
// name: bond_killed_in_action
// command id: F9
//=============================================================================
// info: sets briefing status to killed in action, automatic mission failure
// note: does not kill the player, only changes the mission status
//===========================================================================*/
#define bond_killed_in_action_ID 0xF9
#define bond_killed_in_action_LENGTH 0x01
#define bond_killed_in_action \
        bond_killed_in_action_ID,

/*=============================================================================
// name: guard_raises_arms
// command id: FA
//=============================================================================
// info: makes guard raise their arms for half a second
//===========================================================================*/
#define guard_raises_arms_ID 0xFA
#define guard_raises_arms_LENGTH 0x01
#define guard_raises_arms \
        guard_raises_arms_ID,

/*=============================================================================
// name: trigger_gas_and_fade_fog
// command id: FB
//=============================================================================
// info: trigger gas event and slowly transition fog to the next fog's slot
// note: this command triggers a gas event. for the level egypt, this command
// will not trigger a gas event, but instead will only transition the fog.
// this command cannot be toggled after executing. level must have a fog assigned
// or will crash!
//===========================================================================*/
#define trigger_gas_and_fade_fog_ID 0xFB
#define trigger_gas_and_fade_fog_LENGTH 0x01
#define trigger_gas_and_fade_fog \
        trigger_gas_and_fade_fog_ID,

#endif
