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
// chr ai lists     0401-04FF range
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
#define chararray24(input) (input & 0xFF0000) >> 16, (input & 0x00FF00) >> 8, input & 0x0000FF
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
// infinite loop (commands 02/03/01) or jump to global list #0001 when list has
// finished tasks
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
// bitfield (hex):
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
#define guard_animation(animation_id, start_time60, end_time60, bitfield, tween_time60) \
        guard_animation_ID, \
        chararray16(animation_id), \
        chararray16(start_time60), \
        chararray16(end_time60), \
        bitfield, \
        tween_time60,

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
// name: guard_sidesteps
// command id: 0E
//=============================================================================
// info: trigger guard to sidestep, goto label if successful
//===========================================================================*/
#define guard_sidesteps_ID 0x0E
#define guard_sidesteps_LENGTH 0x02
#define guard_sidesteps(label) \
        guard_sidesteps_ID, \
        label,

/*=============================================================================
// name: guard_sideways_hop
// command id: 0F
//=============================================================================
// info: trigger guard to hop sideways, goto label if successful
//===========================================================================*/
#define guard_sideways_hop_ID 0x0F
#define guard_sideways_hop_LENGTH 0x02
#define guard_sideways_hop(label) \
        guard_sideways_hop_ID, \
        label,

/*=============================================================================
// name: guard_sideways_run
// command id: 10
//=============================================================================
// info: trigger guard to run sideways of bond, goto label if successful
// note: sideways direction is random
//===========================================================================*/
#define guard_sideways_run_ID 0x10
#define guard_sideways_run_LENGTH 0x02
#define guard_sideways_run(label) \
        guard_sideways_run_ID, \
        label,

/*=============================================================================
// name: guard_fire_walk
// command id: 11
//=============================================================================
// info: trigger guard to walk and fire at bond, goto label if successful
// note: bond needs to be at long distance away from guard to work
//===========================================================================*/
#define guard_fire_walk_ID 0x11
#define guard_fire_walk_LENGTH 0x02
#define guard_fire_walk(label) \
        guard_fire_walk_ID, \
        label,

/*=============================================================================
// name: guard_fire_run
// command id: 12
//=============================================================================
// info: trigger guard to run and fire at bond, goto label if successful
// note: bond needs to be at long distance away from guard to work
//===========================================================================*/
#define guard_fire_run_ID 0x12
#define guard_fire_run_LENGTH 0x02
#define guard_fire_run(label) \
        guard_fire_run_ID, \
        label,

/*=============================================================================
// name: guard_fire_roll
// command id: 13
//=============================================================================
// info: trigger guard to roll on ground then fire at bond, goto label if successful
// note: bond cannot be too close to guard or it won't work
//===========================================================================*/
#define guard_fire_roll_ID 0x13
#define guard_fire_roll_LENGTH 0x02
#define guard_fire_roll(label) \
        guard_fire_roll_ID, \
        label,

/*=============================================================================
// name: guard_fire_or_aim_at_target
// command id: 14
//=============================================================================
// info: make guard aim/fire at target, goto label if successful
// note: bitfield argument is used to set the target type (pad/bond/chr)
// bitfield (hex):
// 0001: set target to bond (ignores target argument)
// 0004: set target type to chr_num
// 0008: set target type to pad
// 0020: aim at target instead of firing
//===========================================================================*/
#define guard_fire_or_aim_at_target_ID 0x14
#define guard_fire_or_aim_at_target_LENGTH 0x06
#define guard_fire_or_aim_at_target(bitfield, target, label) \
        guard_fire_or_aim_at_target_ID, \
        chararray16(bitfield), \
        chararray16(target), \
        label,

/*=============================================================================
// name: guard_fire_or_aim_at_target_kneel
// command id: 15
//=============================================================================
// info: make guard kneel and aim/fire at target, goto label if successful
// note: bitfield argument is used to set the target type (pad/bond/chr)
// bitfield (hex):
// 0001: set target to bond (ignores target argument)
// 0004: set target type to chr_num
// 0008: set target type to pad
// 0020: aim at target instead of firing
//===========================================================================*/
#define guard_fire_or_aim_at_target_kneel_ID 0x15
#define guard_fire_or_aim_at_target_kneel_LENGTH 0x06
#define guard_fire_or_aim_at_target_kneel(bitfield, target, label) \
        guard_fire_or_aim_at_target_kneel_ID, \
        chararray16(bitfield), \
        chararray16(target), \
        label,

/*=============================================================================
// name: guard_fire_or_aim_at_target_update
// command id: 16
//=============================================================================
// info: update guard's aim/fire target, goto label if successful
// note: this command only works if guard is currently aiming at a target
// bitfield argument is used to set the target type (pad/bond/chr)
// bitfield (hex):
// 0001: set target to bond (ignores target argument)
// 0004: set target type to chr_num
// 0008: set target type to pad
// 0020: aim at target instead of firing
//===========================================================================*/
#define guard_fire_or_aim_at_target_update_ID 0x16
#define guard_fire_or_aim_at_target_update_LENGTH 0x06
#define guard_fire_or_aim_at_target_update(bitfield, target, label) \
        guard_fire_or_aim_at_target_update_ID, \
        chararray16(bitfield), \
        chararray16(target), \
        label,

/*=============================================================================
// name: guard_faces_target
// command id: 17
//=============================================================================
// info: make guard continuously face target, goto label if successful
// note: if guard was shot while facing target, guard will snap out of facing state
// bitfield argument is used to set the target type (pad/bond/chr)
// bitfield (hex):
// 0001: set target to bond (ignores target argument)
// 0004: set target type to chr_num
// 0008: set target type to pad
//===========================================================================*/
#define guard_faces_target_ID 0x17
#define guard_faces_target_LENGTH 0x06
#define guard_faces_target(bitfield, target, label) \
        guard_faces_target_ID, \
        chararray16(bitfield), \
        chararray16(target), \
        label,

/*=============================================================================
// name: chr_hit_body_part_with_item_damage
// command id: 18
//=============================================================================
// info: hit chr's body part with item's damage, play reaction to hit location
// note: can't be used for bond - command does not trigger item's fire sfx.
// item's damage uses body part damage modifier like in-game
// body part number (hex) and damage modifier:
// 00: null part, no reaction - 1x
// 01: left foot - 1x
// 02: left leg - 1x
// 03: left thigh - 1x
// 04: right foot - 1x
// 05: right leg - 1x
// 06: right thigh - 1x
// 07: pelvis - 1x
// 08: head - 4x
// 09: left hand - 1x
// 0A: left arm - 1x
// 0B: left shoulder - 1x
// 0C: right hand - 1x
// 0D: right arm - 1x
// 0E: right shoulder - 1x
// 0F: torso - 2x
//===========================================================================*/
#define chr_hit_body_part_with_item_damage_ID 0x18
#define chr_hit_body_part_with_item_damage_LENGTH 0x04
#define chr_hit_body_part_with_item_damage(chr_num, part_num, item_num) \
        chr_hit_body_part_with_item_damage_ID, \
        chr_num, \
        part_num, \
        item_num,

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
// note: guard collision is ignored during fade - will not drop items
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
// name: alarm_on
// command id: 25
//=============================================================================
// info: activates alarm
//===========================================================================*/
#define alarm_on_ID 0x25
#define alarm_on_LENGTH 0x01
#define alarm_on \
        alarm_on_ID,

/*=============================================================================
// name: alarm_off
// command id: 26
//=============================================================================
// info: deactivates alarm
//===========================================================================*/
#define alarm_off_ID 0x26
#define alarm_off_LENGTH 0x01
#define alarm_off \
        alarm_off_ID,

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
// name: guard_has_not_been_seen
// command id: 41
//=============================================================================
// info: if guard has not been seen before on screen, goto label
// note: when bond has seen guard, it will add a flag to chr->chrflags.
//       the seen flag will be kept true for duration of level
//===========================================================================*/
#define guard_has_not_been_seen_ID 0x41
#define guard_has_not_been_seen_LENGTH 0x02
#define guard_has_not_been_seen(label) \
        guard_has_not_been_seen_ID, \
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
// name: chr_timer_reset_start
// command id: AE
//=============================================================================
// info: reset and start chr->timer60
// note: chr timer is different to hud timer. chr timer is unique for each chr,
// while hud timer is global for the entire mission. chr->timer60 only counts up
//===========================================================================*/
#define chr_timer_reset_start_ID 0xAE
#define chr_timer_reset_start_LENGTH 0x01
#define chr_timer_reset_start \
        chr_timer_reset_start_ID,

/*=============================================================================
// name: chr_timer_reset
// command id: AF
//=============================================================================
// info: reset chr->timer60
// note: chr timer is different to hud timer. chr timer is unique for each chr,
// while hud timer is global for the entire mission. chr->timer60 only counts up
//===========================================================================*/
#define chr_timer_reset_ID 0xAF
#define chr_timer_reset_LENGTH 0x01
#define chr_timer_reset \
        chr_timer_reset_ID,

/*=============================================================================
// name: chr_timer_stop
// command id: B0
//=============================================================================
// info: pauses chr->timer60 (does not reset value)
// note: chr timer is different to hud timer. chr timer is unique for each chr,
// while hud timer is global for the entire mission. chr->timer60 only counts up
//===========================================================================*/
#define chr_timer_stop_ID 0xB0
#define chr_timer_stop_LENGTH 0x01
#define chr_timer_stop \
        chr_timer_stop_ID,

/*=============================================================================
// name: chr_timer_start
// command id: B1
//=============================================================================
// info: start chr->timer60 (does not reset value)
// note: chr timer is different to hud timer. chr timer is unique for each chr,
// while hud timer is global for the entire mission. chr->timer60 only counts up
//===========================================================================*/
#define chr_timer_start_ID 0xB1
#define chr_timer_start_LENGTH 0x01
#define chr_timer_start \
        chr_timer_start_ID,

/*=============================================================================
// name: chr_timer_has_stopped
// command id: B2
//=============================================================================
// info: if chr->timer60 is not active (paused), goto label
// note: by default, chr->timer60 is inactive
//===========================================================================*/
#define chr_timer_has_stopped_ID 0xB2
#define chr_timer_has_stopped_LENGTH 0x02
#define chr_timer_has_stopped(label) \
        chr_timer_has_stopped_ID, \
        label,

/*=============================================================================
// name: chr_timer_less_than
// command id: B3
//=============================================================================
// info: if chr->timer60 < time60, goto label
// note: time60 argument is converted to float from unsigned int and compared.
//       chr->timer60 only counts up
//===========================================================================*/
#define chr_timer_less_than_ID 0xB3
#define chr_timer_less_than_LENGTH 0x05
#define chr_timer_less_than(time60, label) \
        chr_timer_less_than_ID, \
        chararray24(time60), \
        label,

/*=============================================================================
// name: chr_timer_greater_than
// command id: B4
//=============================================================================
// info: if chr->timer60 > time60, goto label
// note: time60 argument is converted to float from unsigned int and compared.
//       chr->timer60 only counts up
//===========================================================================*/
#define chr_timer_greater_than_ID 0xB4
#define chr_timer_greater_than_LENGTH 0x05
#define chr_timer_greater_than(time60, label) \
        chr_timer_greater_than_ID, \
        chararray24(time60), \
        label,

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
#define hud_timer_set(seconds) \
        hud_timer_set_ID, \
        chararray16(seconds),

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
// name: hud_timer_has_stopped
// command id: BA
//=============================================================================
// info: if hud timer isn't active (paused), goto label
// note: by default, hud timer is inactive
//===========================================================================*/
#define hud_timer_has_stopped_ID 0xBA
#define hud_timer_has_stopped_LENGTH 0x02
#define hud_timer_has_stopped(label) \
        hud_timer_has_stopped_ID, \
        label,

/*=============================================================================
// name: hud_timer_less_than
// command id: BB
//=============================================================================
// info: if hud timer < seconds, goto label
// note: if seconds argument is 0, it will only goto label if timer is less than
// zero (counting up). seconds value is unsigned and can't test negative values
//===========================================================================*/
#define hud_timer_less_than_ID 0xBB
#define hud_timer_less_than_LENGTH 0x04
#define hud_timer_less_than(seconds, label) \
        hud_timer_less_than_ID, \
        chararray16(seconds), \
        label,

/*=============================================================================
// name: hud_timer_greater_than
// command id: BC
//=============================================================================
// info: if hud timer > seconds, goto label
// note: if seconds argument is 0, it will only goto label if timer is greater than
// zero (counting down). seconds value is unsigned and can't test negative values
//===========================================================================*/
#define hud_timer_greater_than_ID 0xBC
#define hud_timer_greater_than_LENGTH 0x04
#define hud_timer_greater_than(seconds, label) \
        hud_timer_greater_than_ID, \
        chararray16(seconds), \
        label,

/*=============================================================================
// name: chr_spawn_clone
// command id: C1
//=============================================================================
// info: if guard has clone flag on, spawn a new guard - goto label if successful
// note: clone flag is stored in chr->chrflags which is assigned at setup init.
//       newly spawned guard is placed in front of original guard
//===========================================================================*/
#define chr_spawn_clone_ID 0xC1
#define chr_spawn_clone_LENGTH 0x05
#define chr_spawn_clone(chr_num, ai_list, label) \
        chr_spawn_clone_ID, \
        chr_num, \
        chararray16(ai_list), \
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
// name: chr_hide_all
// command id: DD
//=============================================================================
// info: hide all characters in level - including bond. execute this before
//       switching to exit camera or bond will disappear
// note: hidden characters will halt ai list execution until unhidden
//===========================================================================*/
#define chr_hide_all_ID 0xDD
#define chr_hide_all_LENGTH 0x01
#define chr_hide_all \
        chr_hide_all_ID,

/*=============================================================================
// name: chr_show_all
// command id: DE
//=============================================================================
// info: show all characters previously hidden by command DD
//===========================================================================*/
#define chr_show_all_ID 0xDE
#define chr_show_all_LENGTH 0x01
#define chr_show_all \
        chr_show_all_ID,

/*=============================================================================
// name: trigger_gas_and_switch_fog
// command id: E9
//=============================================================================
// info: trigger gas leak and instantly switch fog to the next fog's slot
// note: this command triggers a gas leak. for the level egypt, this command
// will not trigger a gas leak, but instead will only switch the fog. this
// command can't be stopped after executing. level must have a fog assigned
// or will crash!
//===========================================================================*/
#define trigger_gas_and_switch_fog_ID 0xE9
#define trigger_gas_and_switch_fog_LENGTH 0x01
#define trigger_gas_and_switch_fog \
        trigger_gas_and_switch_fog_ID,

/*=============================================================================
// name: stop_mission_time_and_exit_level_on_button_input
// command id: EA
//=============================================================================
// info: stop the mission time and exit level if player 1 pressed any buttons
//===========================================================================*/
#define stop_mission_time_and_exit_level_on_button_input_ID 0xEA
#define stop_mission_time_and_exit_level_on_button_input_LENGTH 0x01
#define stop_mission_time_and_exit_level_on_button_input \
        stop_mission_time_and_exit_level_on_button_input_ID,

/*=============================================================================
// name: bond_has_died
// command id: EB
//=============================================================================
// info: if bond is dead, goto label
//===========================================================================*/
#define bond_has_died_ID 0xEB
#define bond_has_died_LENGTH 0x02
#define bond_has_died(label) \
        bond_has_died_ID, \
        label,

/*=============================================================================
// name: bond_disable_damage_and_pickups
// command id: EC
//=============================================================================
// info: disables bond damage and ability to pick up items
// note: commonly used for level exit ai lists - prevents bond dying after
//       triggering exit cutscene
//===========================================================================*/
#define bond_disable_damage_and_pickups_ID 0xEC
#define bond_disable_damage_and_pickups_LENGTH 0x01
#define bond_disable_damage_and_pickups \
        bond_disable_damage_and_pickups_ID,

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
// name: credits_roll
// command id: EF
//=============================================================================
// info: trigger credits crawl
// note: credits text and positions are stored in setup intro struct
//===========================================================================*/
#define credits_roll_ID 0xEF
#define credits_roll_LENGTH 0x01
#define credits_roll \
        credits_roll_ID,

/*=============================================================================
// name: credits_completed
// command id: F0
//=============================================================================
// info: credits crawl has finished, goto label
//===========================================================================*/
#define credits_completed_ID 0xF0
#define credits_completed_LENGTH 0x02
#define credits_completed(label) \
        credits_completed_ID, \
        label,

/*=============================================================================
// name: objective_all_completed
// command id: F1
//=============================================================================
// info: if all objectives for current difficulty has been completed, goto label
// note: uses objective difficulty settings within setup, briefing file settings
//       are not referenced. ensure both setup and briefing files are consistent
//===========================================================================*/
#define objective_all_completed_ID 0xF1
#define objective_all_completed_LENGTH 0x02
#define objective_all_completed(label) \
        objective_all_completed_ID, \
        label,

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
// info: trigger gas leak and slowly transition fog to the next fog's slot
// note: this command triggers a gas leak. for the level egypt, this command
// will not trigger a gas leak, but instead will only transition the fog.
// this command can't be stopped after executing. level must have a fog assigned
// or will crash!
//===========================================================================*/
#define trigger_gas_and_fade_fog_ID 0xFB
#define trigger_gas_and_fade_fog_LENGTH 0x01
#define trigger_gas_and_fade_fog \
        trigger_gas_and_fade_fog_ID,

#endif
