#ifndef _BONDCOMMANDS_H_
#define _BONDCOMMANDS_H_
#include "ultra64.h"

#define chararray16(input) (input & 0xFF00) >> 8, input & 0x00FF
#define chararray24(input) (input & 0xFF0000) >> 16, (input & 0x00FF00) >> 8, input & 0x0000FF
#define chararray32(input) (input & 0xFF000000) >> 24, (input & 0x00FF0000) >> 16, (input & 0x0000FF00) >> 8, input & 0x000000FF

/*=============================================================================
// chr ai commands reference
// programmed by mark edmonds and martin hollis
//=============================================================================
// terminology:
// chr              character
// obj              objective
// list             list of ai commands - list must end with 04 command
// glist            global list
// chr ai lists     0401-04FF range
// obj ai lists     1000-10FF range
// global ai lists  0000-0011 range
//=============================================================================
// ai list intro
//=============================================================================
// ai list are a list of ai commands that are executed from top to bottom.
// they are used to control guard ai (fire, chase, go to position, etc) and
// objective ai (objective logic, mission fail state, spawning guards, etc)
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
// lists (chr/obj) are unique to each level setup file, compared to global lists
// which are accessible throughout the entire game. they contain generic ai lists
// used for most levels
//=============================================================================
// ai command note
//=============================================================================
// commands with guard/vehicle prefix are exclusive to chr ai lists, they can't
// be executed by obj ai lists (10XX) or it will crash! commands with chr prefix
// can be used by obj/chr ai lists - exceptions to this rule are detailed within
// the command description
//=============================================================================
// ai commands with chr number argument
//=============================================================================
// commands with a chr prefix need a chr number argument. now for the most part,
// this can be used with any loaded chr num and it will work fine. there is however
// one exception to this and that is special chr num ID CHR_BOND. this ID only
// works when bond has a third person model assigned (intro/exit cutscene)
// only use CHR_BOND for intro/exit cutscene specific logic
//=============================================================================
// ai commands with label argument
//=============================================================================
// most commands will have a label argument in their function description. this
// is used when a command has a false/true state. for example, the run to bond
// command (28) has goto label argument. when the command is executed, it will
// check if the guard is able to run to bond. if for some reason the command fails
// (bond is unreachable/guard is dying/etc) then the command will not goto label
// and the next command will be executed. the most common use of commands with
// goto labels are jumping out of an infinite loop - for an example check global
// ai list GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE
//===========================================================================*/

#define AI_LIST_GLOBAL_START 0x0000
#define AI_LIST_CHR_START 0x0401
#define AI_LIST_OBJ_START 0x1000

#define AI_CMDS_TOTAL (object_rocket_launch_ID + 1)

/*=============================================================================
// global ai lists - glists
//===========================================================================*/
#define GLIST_AIM_AT_BOND                              0x0000 // continuously aim at bond with weapon
#define GLIST_END_ROUTINE                              0x0001 // end routine (loop forever)
#define GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE 0x0002 // wait for bond detection (spawn clone when heard bond)
#define GLIST_IDLE_RAND_ANIM_SUBROUTINE                0x0003 // play idle animation (subroutine)
#define GLIST_KEYBOARD_RAND_ANIM_SUBROUTINE            0x0004 // play use keyboard animation (subroutine)
#define GLIST_DETECT_BOND_DEAF_NO_CLONE_NO_IDLE_ANIM   0x0005 // wait for bond detection (deaf & no idling)
#define GLIST_FIRE_RAND_ANIM_SUBROUTINE                0x0006 // fire at bond with random animation (subroutine)
#define GLIST_DETECT_BOND_NO_CLONE_NO_IDLE_ANIM        0x0007 // wait for bond detection (no clones & no idling)
#define GLIST_RUN_TO_BOND_SUBROUTINE                   0x0008 // run to bond and fire (subroutine)
#define GLIST_RUN_TO_CHR_PADPRESET_AND_ACTIVATE_ALARM  0x0009 // run to chr->padpreset1 and activate alarm
#define GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE   0x000A // startle character (subroutine)
#define GLIST_SPAWN_CLONE_OR_RUN_TO_BOND               0x000B // if chr has been seen, run to bond - else spawn clone
#define GLIST_RUN_TO_BOND_AND_FIRE                     0x000C // run to bond and fire
#define GLIST_RUN_TO_BOND_AND_FIRE_HALT_CHR_RANDOMLY   0x000D // forever chase bond and fire (halt randomly)
#define GLIST_WAIT_ONE_SECOND_SUBROUTINE               0x000E // wait for one second (subroutine)
#define GLIST_EXIT_LEVEL                               0x000F // exit level
#define GLIST_DRAW_DD44_AND_FIRE                       0x0010 // draw dd44 and fire
#define GLIST_REMOVE_CHR                               0x0011 // remove chr
/*===========================================================================*/

/*=============================================================================
// command bitflags and common settings
//===========================================================================*/
// command 0A animation bitflags
#define ANIM_MIRROR                     0x01
#define ANIM_UNKNOWN                    0x02
#define ANIM_LOOP_HOLD_LAST_FRAME       0x04
#define ANIM_PLAY_SFX                   0x08
#define ANIM_IDLE_POSE_WHEN_COMPLETE    0x10
#define ANIM_TRANSLATION_SCALE          0x20
#define ANIM_NO_TRANSLATION             0x40
#define ANIM_REVERSE_LOOPING_ANIMATION  0x80

#define ANIM_DEFAULT_INTERPOLATION      0x10

// command 14-17 target bitflags
#define TARGET_BOND         0x0001
#define TARGET_FRONT_OF_CHR 0x0002
#define TARGET_CHR          0x0004
#define TARGET_PAD          0x0008
#define TARGET_COMPASS      0x0010
#define TARGET_AIM_ONLY     0x0020

// command 18-19 target body part values
#define TARGET_NULL_PART        0x00 // null part, no reaction - 1x damage
#define TARGET_LEFT_FOOT        0x01 // left foot - 1x damage
#define TARGET_LEFT_LEG         0x02 // left leg - 1x damage
#define TARGET_LEFT_THIGH       0x03 // left thigh - 1x damage
#define TARGET_RIGHT_FOOT       0x04 // right foot - 1x damage
#define TARGET_RIGHT_LEG        0x05 // right leg - 1x damage
#define TARGET_RIGHT_THIGH      0x06 // right thigh - 1x damage
#define TARGET_PELVIS           0x07 // pelvis - 1x damage
#define TARGET_HEAD             0x08 // head - 4x damage
#define TARGET_LEFT_HAND        0x09 // left hand - 1x damage
#define TARGET_LEFT_ARM         0x0A // left arm - 1x damage
#define TARGET_LEFT_SHOULDER    0x0B // left shoulder - 1x damage
#define TARGET_RIGHT_HAND       0x0C // right hand - 1x damage
#define TARGET_RIGHT_ARM        0x0D // right arm - 1x damage
#define TARGET_RIGHT_SHOULDER   0x0E // right shoulder - 1x damage
#define TARGET_CHEST            0x0F // chest - 2x damage

// command 68
#define DOOR_STATE_CLOSED       0x01
#define DOOR_STATE_OPEN         0x02
#define DOOR_STATE_CLOSING      0x04
#define DOOR_STATE_OPENING      0x08

// command D7
#define HUD_HIDE_ALL            0x00
#define HUD_SHOW_TEXT_TOP       0x01
#define HUD_SHOW_TEXT_BOTTOM    0x02
#define HUD_SHOW_HUD_TIMER      0x04

// command 94-99 chr->BITFIELD - used for ai list GLIST_FIRE_RAND_ANIM_SUBROUTINE
#define BITFIELD_DONT_POINT_AT_BOND     0x01 // if enabled, don't point at bond

/*===========================================================================*/

/*=============================================================================
// ai command shortcuts
//===========================================================================*/
#define goto_loop_start(label_id) \
        label(label_id) \
        ai_sleep

#define goto_loop_repeat(label) \
        goto_first(label)

#define goto_loop_infinite(label_id) \
        label(label_id) \
        ai_sleep \
        goto_first(label_id)

#define random_generate_greater_than(byte, label) \
        random_generate \
        random_greater_than(byte, label)

#define random_generate_less_than(byte, label) \
        random_generate \
        random_less_than(byte, label)

#define guard_meters_to_bond_less_than(distance, label) \
        guard_distance_to_bond_less_than((distance * 10U), label)

#define guard_meters_to_bond_greater_than(distance, label) \
        guard_distance_to_bond_greater_than((distance * 10U), label)

#define chr_meters_to_pad_less_than(chr_num, distance, pad, label) \
        chr_distance_to_pad_less_than(chr_num, (distance * 10U), pad, label)

#define chr_meters_to_pad_greater_than(chr_num, distance, pad, label) \
        chr_distance_to_pad_greater_than(chr_num, (distance * 10U), pad, label)

#define guard_meters_to_chr_less_than(distance, chr_num, label) \
        guard_distance_to_chr_less_than((distance * 10U), chr_num, label)

#define guard_meters_to_chr_greater_than(distance, chr_num, label) \
        guard_distance_to_chr_greater_than((distance * 10U), chr_num, label)

#define guard_set_chr_preset_to_guard_within_meters(distance, label) \
        guard_set_chr_preset_to_guard_within_distance((distance * 10U), label)

#define bond_meters_to_pad_less_than(distance, pad, label) \
        bond_distance_to_pad_less_than((distance * 10U), pad, label)

#define bond_meters_to_pad_greater_than(distance, pad, label) \
        bond_distance_to_pad_greater_than((distance * 10U), pad, label)

#define debug_log_end \
        '\0',

#define chr_timer_seconds_less_than(seconds, label) \
        chr_timer_less_than((SECS_TO_TIMER60(seconds)), label)

#define chr_timer_seconds_greater_than(seconds, label) \
        chr_timer_greater_than((SECS_TO_TIMER60(seconds)), label)

#define camera_wait_for_loading \
        ai_sleep \
        ai_sleep \
        ai_sleep
/*===========================================================================*/

/*=============================================================================
// ai commands macros and information
//=============================================================================
// name and description per command, please read carefully when creating new
// ai lists. ensure that you don't cause loops without a ai_sleep command or else
// command parser will never release and game will softlock
//===========================================================================*/

/*=============================================================================
// name: goto_next
// command id: 00
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
// info: label marker for ai list - used for all commands that return true
//===========================================================================*/
#define label_ID 0x02
#define label_LENGTH 0x02
#define label(id) \
        label_ID, \
        id,

/*=============================================================================
// name: ai_sleep
// id number: 03
// info: halt the ai list - frees engine to start executing next ai list until
//       all lists have been executed for game tick.
//=============================================================================
// note: offscreen/idle guards will take 14 game ticks instead of 1 tick on ai_sleep
//===========================================================================*/
#define ai_sleep_ID 0x03
#define ai_sleep_LENGTH 0x01
#define ai_sleep \
        ai_sleep_ID,

/*=============================================================================
// name: ai_list_end
// command id: 04
// info: used for ai list parser to check when list ends
//=============================================================================
// note: not recommended to execute this command - to finish a list create an
// infinite loop (goto_loop_infinite) or jump to glist end routine when list has
// finished tasks
//===========================================================================*/
#define ai_list_end_ID 0x04
#define ai_list_end_LENGTH 0x01
#define ai_list_end \
        ai_list_end_ID

/*=============================================================================
// name: goto_ai_list
// command id: 05
// info: make chr goto another list and start executing from beginning
//=============================================================================
// note: not recommended to goto an obj list (10XX)
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
// info: store a list ptr in current chr struct - used for command 07 return
//=============================================================================
// note: not recommended to set stored list to an obj list (10XX)
//===========================================================================*/
#define set_return_ai_list_ID 0x06
#define set_return_ai_list_LENGTH 0x03
#define set_return_ai_list(ai_list) \
        set_return_ai_list_ID, \
        chararray16(ai_list),

/*=============================================================================
// name: goto_return_ai_list
// command id: 07
// info: goto the return list set in chr struct - pointer set by command 06.
//       used for subroutine lists. if list pointer isn't set, game will crash
//=============================================================================
// note: after return, set chr->aioffset to top of ai list
//===========================================================================*/
#define goto_return_ai_list_ID 0x07
#define goto_return_ai_list_LENGTH 0x01
#define goto_return_ai_list \
        goto_return_ai_list_ID,

/*=============================================================================
// name: guard_animation_stop
// command id: 08
// info: reset guard back to idle pose - can be used to stop guards in place
//===========================================================================*/
#define guard_animation_stop_ID 0x08
#define guard_animation_stop_LENGTH 0x01
#define guard_animation_stop \
        guard_animation_stop_ID,

/*=============================================================================
// name: guard_kneel
// command id: 09
// info: make guard kneel on one knee
//===========================================================================*/
#define guard_kneel_ID 0x09
#define guard_kneel_LENGTH 0x01
#define guard_kneel \
        guard_kneel_ID,

/*=============================================================================
// name: guard_animation
// command id: 0A
// info: set guard to playback animation
//=============================================================================
// arguments:
// start/end set to -1/-1 will playback the entire animation length
// interpolation time will set how long it will take to transition from the previous state
// if interpolation time is too low it may crash! - use 0x10 if unsure
// start/end keyframe and interpolation use 60 tick units
// bitfield (hex):
// 01: mirror animation
// 02: ?? (cancels no translation flag)
// 04: loop/hold last frame (required for reverse flag)
// 08: play sneeze sfx with animation 9F (triggers 50% of the time)
// 10: idle pose after animation has completed (does not work with looping animations)
// 20: translation multiplier x 4 (used for dam and cradle cinema)
// 40: no translation
// 80: reverse animation (only for looped animations)
//===========================================================================*/
#define guard_animation_ID 0x0A
#define guard_animation_LENGTH 0x09
#define guard_animation(animation_id, start_time60, end_time60, bitfield, interpol_time60) \
        guard_animation_ID, \
        chararray16(animation_id), \
        chararray16(start_time60), \
        chararray16(end_time60), \
        bitfield, \
        interpol_time60,

/*=============================================================================
// name: guard_playing_animation
// command id: 0B
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
// info: guard points if bond is directly in front of guard, else command is ignored
//=============================================================================
// note: global ai list GLIST_FIRE_RAND_ANIM_SUBROUTINE skips this command if
// bitfield flag BITFIELD_DONT_POINT_AT_BOND is on
//===========================================================================*/
#define guard_points_at_bond_ID 0x0C
#define guard_points_at_bond_LENGTH 0x01
#define guard_points_at_bond \
        guard_points_at_bond_ID,

/*=============================================================================
// name: guard_animation_looks_around_self
// command id: 0D
// info: set guard to playback animation - used when shots land near guard
//===========================================================================*/
#define guard_animation_looks_around_self_ID 0x0D
#define guard_animation_looks_around_self_LENGTH 0x01
#define guard_animation_looks_around_self \
        guard_animation_looks_around_self_ID,

/*=============================================================================
// name: guard_sidesteps
// command id: 0E
// info: trigger guard to sidestep, goto label if successful
//=============================================================================
// note: direction is random
//===========================================================================*/
#define guard_sidesteps_ID 0x0E
#define guard_sidesteps_LENGTH 0x02
#define guard_sidesteps(label) \
        guard_sidesteps_ID, \
        label,

/*=============================================================================
// name: guard_sideways_hop
// command id: 0F
// info: trigger guard to hop sideways, goto label if successful
//=============================================================================
// note: direction is random
//===========================================================================*/
#define guard_sideways_hop_ID 0x0F
#define guard_sideways_hop_LENGTH 0x02
#define guard_sideways_hop(label) \
        guard_sideways_hop_ID, \
        label,

/*=============================================================================
// name: guard_sideways_run
// command id: 10
// info: trigger guard to run sideways of bond, goto label if successful
//=============================================================================
// note: direction is random
//===========================================================================*/
#define guard_sideways_run_ID 0x10
#define guard_sideways_run_LENGTH 0x02
#define guard_sideways_run(label) \
        guard_sideways_run_ID, \
        label,

/*=============================================================================
// name: guard_fire_walk
// command id: 11
// info: trigger guard to walk and fire at bond, goto label if successful
//=============================================================================
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
// info: trigger guard to run and fire at bond, goto label if successful
//=============================================================================
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
// info: trigger guard to roll on ground then fire at bond, goto label if successful
//=============================================================================
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
// info: make guard aim/fire their weapon at target, goto label if successful
//=============================================================================
// note: bitfield argument is used to set the target type (pad/bond/chr)
// bitfield (hex):
// 0001: set target to bond (ignores target argument)
// 0004: set target type to chr_num
// 0008: set target type to pad
// 0010: set target to compass direction (hex) N: 0000 E: C000 S: 8000: W: 4000
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
// info: make guard kneel and aim/fire their weapon at target, goto label if successful
//=============================================================================
// note: bitfield argument is used to set the target type (pad/bond/chr)
// bitfield (hex):
// 0001: set target to bond (ignores target argument)
// 0004: set target type to chr_num
// 0008: set target type to pad
// 0010: set target to compass direction (hex) N: 0000 E: C000 S: 8000: W: 4000
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
// info: update guard's aim/fire target, goto label if successful
//=============================================================================
// note: this command only works if guard is currently aiming at a target
// bitfield argument is used to set the target type (pad/bond/chr)
// bitfield (hex):
// 0001: set target to bond (ignores target argument)
// 0004: set target type to chr_num
// 0008: set target type to pad
// 0010: set target to compass direction (hex) N: 0000 E: C000 S: 8000: W: 4000
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
// info: make guard continuously face target, goto label if successful
//=============================================================================
// note: if guard was shot while facing target, guard will snap out of facing state
// bitfield argument is used to set the target type (pad/bond/chr)
// bitfield (hex):
// 0001: set target to bond (ignores target argument)
// 0004: set target type to chr_num
// 0008: set target type to pad
// 0010: set target to compass direction (hex) N: 0000 E: C000 S: 8000: W: 4000
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
// info: hit chr's body part with item's damage, play reaction to hit location
//=============================================================================
// note: command does not trigger item's fire sfx. item's damage uses body part
// damage modifier
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
// 0F: chest - 2x
//===========================================================================*/
#define chr_hit_body_part_with_item_damage_ID 0x18
#define chr_hit_body_part_with_item_damage_LENGTH 0x04
#define chr_hit_body_part_with_item_damage(chr_num, part_num, item_num) \
        chr_hit_body_part_with_item_damage_ID, \
        chr_num, \
        part_num, \
        item_num,

/*=============================================================================
// name: chr_hit_chr_body_part_with_held_item
// command id: 19
// info: chr hits chr's body part with held item, play reaction to hit location
//=============================================================================
// note: command does not trigger item's fire sfx or chr firing animation.
// item's damage uses body part damage modifier
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
// 0F: chest - 2x
//===========================================================================*/
#define chr_hit_chr_body_part_with_held_item_ID 0x19
#define chr_hit_chr_body_part_with_held_item_LENGTH 0x04
#define chr_hit_chr_body_part_with_held_item(chr_num, chr_num_target, part_num) \
        chr_hit_chr_body_part_with_held_item_ID, \
        chr_num, \
        chr_num_target, \
        part_num,

/*=============================================================================
// name: guard_throw_grenade
// command id: 1A
// info: trigger guard to throw a grenade at bond, goto label if successful
//=============================================================================
// note: a rng byte is generated and compared again chr->grenadeprob, if rng byte
// is less than grenadeprob throw grenade and goto label, else do nothing.
// chr->grenadeprob default is 0 - to change use setup object 12 or command 8D
//===========================================================================*/
#define guard_throw_grenade_ID 0x1A
#define guard_throw_grenade_LENGTH 0x02
#define guard_throw_grenade(label) \
        guard_throw_grenade_ID, \
        label,

/*=============================================================================
// name: guard_drop_item
// command id: 1B
// info: spawn and drop item with prop model from guard, goto label if successful
//=============================================================================
// note: dropped item uses item type (08) with model number - they can be picked up.
// grenade/mines will be dropped live - this is used for cradle (list #0411)
//===========================================================================*/
#define guard_drop_item_ID 0x1B
#define guard_drop_item_LENGTH 0x05
#define guard_drop_item(prop_num, item_num, label) \
        guard_drop_item_ID, \
        chararray16(prop_num), \
        item_num, \
        label,

/*=============================================================================
// name: guard_runs_to_pad
// command id: 1C
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
// info: makes the guard run to guard->padpreset1 (PAD_PRESET - 9000)
//===========================================================================*/
#define guard_runs_to_padpreset_ID 0x1D
#define guard_runs_to_padpreset_LENGTH 0x01
#define guard_runs_to_padpreset \
        guard_runs_to_padpreset_ID,

/*=============================================================================
// name: guard_walks_to_pad
// command id: 1E
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
// info: makes the guard sprint to pad
//===========================================================================*/
#define guard_sprints_to_pad_ID 0x1F
#define guard_sprints_to_pad_LENGTH 0x03
#define guard_sprints_to_pad(pad) \
        guard_sprints_to_pad_ID, \
        chararray16(pad),

/*=============================================================================
// name: guard_start_patrol
// command id: 20
// info: makes guard walk a predefined path within setup
//=============================================================================
// note: usually paired with goto glist 0005/0007
//===========================================================================*/
#define guard_start_patrol_ID 0x20
#define guard_start_patrol_LENGTH 0x02
#define guard_start_patrol(path_num) \
        guard_start_patrol_ID, \
        path_num,

/*=============================================================================
// name: guard_surrenders
// command id: 21
// info: makes a guard surrender and drop all attached and held items
//=============================================================================
// note: will not drop items embedded within guard
//===========================================================================*/
#define guard_surrenders_ID 0x21
#define guard_surrenders_LENGTH 0x01
#define guard_surrenders \
        guard_surrenders_ID,

/*=============================================================================
// name: guard_remove_fade
// command id: 22
// info: sets guard to fade away - fade time is 90 ticks (1.5 seconds). when
//       the fade finishes, automatically remove guard
//=============================================================================
// note: guard collision is ignored during fade - will not drop items
//===========================================================================*/
#define guard_remove_fade_ID 0x22
#define guard_remove_fade_LENGTH 0x01
#define guard_remove_fade \
        guard_remove_fade_ID,

/*=============================================================================
// name: chr_remove_instant
// command id: 23
// info: instantly remove chr unlike above command
//=============================================================================
// note: will not drop items
//===========================================================================*/
#define chr_remove_instant_ID 0x23
#define chr_remove_instant_LENGTH 0x02
#define chr_remove_instant(chr_num) \
        chr_remove_instant_ID, \
        chr_num,

/*=============================================================================
// name: guard_trigger_alarm_at_pad
// command id: 24
// info: guard activates alarm assigned to pad, goto label if successful
//=============================================================================
// note: command doesn't care what object type is at pad, as long as the object
// isn't destroyed. command also checks if guard is alive before activating alarm.
// when triggering alarm, guard will be set to state ACT_STARTALARM and play animation
//===========================================================================*/
#define guard_trigger_alarm_at_pad_ID 0x24
#define guard_trigger_alarm_at_pad_LENGTH 0x04
#define guard_trigger_alarm_at_pad(pad, label) \
        guard_trigger_alarm_at_pad_ID, \
        chararray16(pad), \
        label,

/*=============================================================================
// name: alarm_on
// command id: 25
// info: activates alarm
//===========================================================================*/
#define alarm_on_ID 0x25
#define alarm_on_LENGTH 0x01
#define alarm_on \
        alarm_on_ID,

/*=============================================================================
// name: alarm_off
// command id: 26
// info: deactivates alarm
//===========================================================================*/
#define alarm_off_ID 0x26
#define alarm_off_LENGTH 0x01
#define alarm_off \
        alarm_off_ID,

/*=============================================================================
// name: removed_command27
// command id: 27
// info: command no longer exists, never goto label
//===========================================================================*/
#define removed_command27_ID 0x27
#define removed_command27_LENGTH 0x02
#define removed_command27(label) \
        removed_command27_ID, \
        label,

/*=============================================================================
// name: guard_runs_to_bond_position
// command id: 28
// info: if guard is able to run to bond, goto label
//=============================================================================
// note: don't goto label if guard can't run to bond (guard has died) or bond is
//       at an unreachable area (no navigation pads in area)
//===========================================================================*/
#define guard_runs_to_bond_position_ID 0x28
#define guard_runs_to_bond_position_LENGTH 0x02
#define guard_runs_to_bond_position(label) \
        guard_runs_to_bond_position_ID, \
        label,

/*=============================================================================
// name: guard_walks_to_bond_position
// command id: 29
// info: if guard is able to walk to bond, goto label
//=============================================================================
// note: don't goto label if guard can't walk to bond (guard has died) or bond is
//       at an unreachable area (no navigation pads in area)
//===========================================================================*/
#define guard_walks_to_bond_position_ID 0x29
#define guard_walks_to_bond_position_LENGTH 0x02
#define guard_walks_to_bond_position(label) \
        guard_walks_to_bond_position_ID, \
        label,

/*=============================================================================
// name: guard_sprints_to_bond_position
// command id: 2A
// info: if guard is able to sprint to bond, goto label
//=============================================================================
// note: don't goto label if guard can't sprint to bond (guard has died) or bond
//       is at an unreachable area (no navigation pads in area)
//===========================================================================*/
#define guard_sprints_to_bond_position_ID 0x2A
#define guard_sprints_to_bond_position_LENGTH 0x02
#define guard_sprints_to_bond_position(label) \
        guard_sprints_to_bond_position_ID, \
        label,

/*=============================================================================
// name: removed_command2B
// command id: 2B
// info: command no longer exists, never goto label
//===========================================================================*/
#define removed_command2B_ID 0x2B
#define removed_command2B_LENGTH 0x02
#define removed_command2B(label) \
        removed_command2B_ID, \
        label,

/*=============================================================================
// name: guard_runs_to_chr_position
// command id: 2C
// info: if guard is able to run to chr, goto label
//=============================================================================
// note: don't goto label if guard can't run to chr (guard has died) or chr is
// at an unreachable area (no navigation pads in area) or chr doesn't exist
//===========================================================================*/
#define guard_runs_to_chr_position_ID 0x2C
#define guard_runs_to_chr_position_LENGTH 0x03
#define guard_runs_to_chr_position(chr_num, label) \
        guard_runs_to_chr_position_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: guard_walks_to_chr_position
// command id: 2D
// info: if guard is able to walk to chr, goto label
//=============================================================================
// note: don't goto label if guard can't walk to chr (guard has died) or chr is
// at an unreachable area (no navigation pads in area) or chr doesn't exist
//===========================================================================*/
#define guard_walks_to_chr_position_ID 0x2D
#define guard_walks_to_chr_position_LENGTH 0x03
#define guard_walks_to_chr_position(chr_num, label) \
        guard_walks_to_chr_position_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: guard_sprints_to_chr_position
// command id: 2E
// info: if guard is able to sprint to chr, goto label
//=============================================================================
// note: don't goto label if guard can't sprint to chr (guard has died) or chr
// is at an unreachable area (no navigation pads in area) or chr doesn't exist
//===========================================================================*/
#define guard_sprints_to_chr_position_ID 0x2E
#define guard_sprints_to_chr_position_LENGTH 0x03
#define guard_sprints_to_chr_position(chr_num, label) \
        guard_sprints_to_chr_position_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: guard_has_stopped_moving
// command id: 2F
// info: if guard has stopped moving, goto label
//=============================================================================
// note: check if guard isn't looking for bond or if guard has finished moving
//       to destination
//===========================================================================*/
#define guard_has_stopped_moving_ID 0x2F
#define guard_has_stopped_moving_LENGTH 0x02
#define guard_has_stopped_moving(label) \
        guard_has_stopped_moving_ID, \
        label,

/*=============================================================================
// name: chr_dying_or_dead
// command id: 30
// info: if chr has died (or in dying state), goto label
//===========================================================================*/
#define chr_dying_or_dead_ID 0x30
#define chr_dying_or_dead_LENGTH 0x03
#define chr_dying_or_dead(chr_num, label) \
        chr_dying_or_dead_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: chr_does_not_exist
// command id: 31
// info: if chr doesn't exist (died and faded/not spawned), goto label
//=============================================================================
// note: this command is used to check if chr has finished dying animation and
// faded away, or chr num is free
//===========================================================================*/
#define chr_does_not_exist_ID 0x31
#define chr_does_not_exist_LENGTH 0x03
#define chr_does_not_exist(chr_num, label) \
        chr_does_not_exist_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: guard_sees_bond
// command id: 32
// info: check vision for bond, goto label if spotted bond
//=============================================================================
// note: uses chr->visionrange while checking for bond. once bond has been spotted,
// check if bond and guard are within line of sight (ignores facing direction).
// if bond breaks line of sight, do not goto label. if bond has broken line of
// sight for more than 10 seconds, reset spotted bond state
//===========================================================================*/
#define guard_sees_bond_ID 0x32
#define guard_sees_bond_LENGTH 0x02
#define guard_sees_bond(label) \
        guard_sees_bond_ID, \
        label,

/*=============================================================================
// name: random_generate
// command id: 33
// info: generate a random byte and store to chr->random
//=============================================================================
// note: random byte range is 00-FF (unsigned)
//===========================================================================*/
#define random_generate_ID 0x33
#define random_generate_LENGTH 0x01
#define random_generate \
        random_generate_ID,

/*=============================================================================
// name: random_less_than
// command id: 34
// info: if chr->random < byte, goto label
//=============================================================================
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
// info: if chr->random > byte, goto label
//=============================================================================
// note: compare is unsigned
//===========================================================================*/
#define random_greater_than_ID 0x35
#define random_greater_than_LENGTH 0x03
#define random_greater_than(byte, label) \
        random_greater_than_ID, \
        byte, \
        label,

/*=============================================================================
// name: alarm_is_set_on_unused
// command id: 36
// info: if alarm is activated, goto label
//=============================================================================
// note: this command works but is unused in retail game, use command 37 instead
//===========================================================================*/
#define alarm_is_set_on_unused_ID 0x36
#define alarm_is_set_on_unused_LENGTH 0x02
#define alarm_is_set_on_unused(label) \
        alarm_is_set_on_unused_ID, \
        label,

/*=============================================================================
// name: alarm_is_set_on
// command id: 37
// info: if alarm is activated, goto label
//===========================================================================*/
#define alarm_is_set_on_ID 0x37
#define alarm_is_set_on_LENGTH 0x02
#define alarm_is_set_on(label) \
        alarm_is_set_on_ID, \
        label,

/*=============================================================================
// name: gas_is_leaking
// command id: 38
// info: if gas leak event triggered, goto label
//=============================================================================
// note: once gas leak event has started, always goto label
//===========================================================================*/
#define gas_is_leaking_ID 0x38
#define gas_is_leaking_LENGTH 0x02
#define gas_is_leaking(label) \
        gas_is_leaking_ID, \
        label,

/*=============================================================================
// name: guard_heard_bond
// command id: 39
// info: if guard heard bond fire weapon, goto label
//=============================================================================
// note: uses chr->hearingscale while listening for bond. to check if bond has
//       shot within the last 10 seconds, use command 3F
//===========================================================================*/
#define guard_heard_bond_ID 0x39
#define guard_heard_bond_LENGTH 0x02
#define guard_heard_bond(label) \
        guard_heard_bond_ID, \
        label,

/*=============================================================================
// name: guard_see_guard_shot
// command id: 3A
// info: if guard sees another guard shot (from anyone), goto label
//=============================================================================
// note: guard friendly fire (if flagged) will trigger this command to goto label.
//       command checks if chr->chrseeshot is set to valid chrnum (not -1)
//===========================================================================*/
#define guard_see_guard_shot_ID 0x3A
#define guard_see_guard_shot_LENGTH 0x02
#define guard_see_guard_shot(label) \
        guard_see_guard_shot_ID, \
        label,

/*=============================================================================
// name: guard_see_guard_die
// command id: 3B
// info: if guard sees another guard die (from anyone), goto label
//=============================================================================
// note: when a guard in sight switches to ACT_DIE/ACT_DEAD, goto label.
//       command checks if chr->chrseedie is set to valid chrnum (not -1)
//===========================================================================*/
#define guard_see_guard_die_ID 0x3B
#define guard_see_guard_die_LENGTH 0x02
#define guard_see_guard_die(label) \
        guard_see_guard_die_ID, \
        label,

/*=============================================================================
// name: guard_and_bond_within_line_of_sight
// command id: 3C
// info: if guard and bond are within line of sight, goto label
//=============================================================================
// note: line of sight uses clipping - ignores facing direction of bond/guard.
// if prop/guard is in the way do not goto label. does not use chr->visionrange
// for line of sight check. use command 32 to check using chr->visionrange and
// command 42 to account for bond's view
//===========================================================================*/
#define guard_and_bond_within_line_of_sight_ID 0x3C
#define guard_and_bond_within_line_of_sight_LENGTH 0x02
#define guard_and_bond_within_line_of_sight(label) \
        guard_and_bond_within_line_of_sight_ID, \
        label,

/*=============================================================================
// name: guard_and_bond_within_partial_line_of_sight
// command id: 3D
// info: if guard and bond are within partial line of sight, goto label
//=============================================================================
// note: unused command, functions like above but only goto label if bond is
//       half occluded by clipping (not blocked or within full view)
//===========================================================================*/
#define guard_and_bond_within_partial_line_of_sight_ID 0x3D
#define guard_and_bond_within_partial_line_of_sight_LENGTH 0x02
#define guard_and_bond_within_partial_line_of_sight(label) \
        guard_and_bond_within_partial_line_of_sight_ID, \
        label,

/*=============================================================================
// name: guard_was_shot_within_last_10_secs
// command id: 3E
// info: if guard was shot (from anyone) within the last 10 seconds, goto label
//===========================================================================*/
#define guard_was_shot_within_last_10_secs_ID 0x3E
#define guard_was_shot_within_last_10_secs_LENGTH 0x02
#define guard_was_shot_within_last_10_secs(label) \
        guard_was_shot_within_last_10_secs_ID, \
        label,

/*=============================================================================
// name: guard_heard_bond_within_last_10_secs
// command id: 3F
// info: if guard heard bond fire weapon within the last 10 seconds, goto label
//=============================================================================
// note: uses chr->hearingscale while listening for bond. to check if bond has
//       now fired weapon instead of within the last 10 seconds, use command 39
//===========================================================================*/
#define guard_heard_bond_within_last_10_secs_ID 0x3F
#define guard_heard_bond_within_last_10_secs_LENGTH 0x02
#define guard_heard_bond_within_last_10_secs(label) \
        guard_heard_bond_within_last_10_secs_ID, \
        label,

/*=============================================================================
// name: guard_in_room_with_chr
// command id: 40
// info: if guard is in same room with chr, goto label
//===========================================================================*/
#define guard_in_room_with_chr_ID 0x40
#define guard_in_room_with_chr_LENGTH 0x03
#define guard_in_room_with_chr(chr_num, label) \
        guard_in_room_with_chr_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: guard_has_not_been_seen
// command id: 41
// info: if guard has not been seen before on screen, goto label
//=============================================================================
// note: when bond has seen guard, it will add a flag to chr->chrflags.
//       the seen flag will be kept true for duration of level
//===========================================================================*/
#define guard_has_not_been_seen_ID 0x41
#define guard_has_not_been_seen_LENGTH 0x02
#define guard_has_not_been_seen(label) \
        guard_has_not_been_seen_ID, \
        label,

/*=============================================================================
// name: guard_is_on_screen
// command id: 42
// info: if guard is currently being rendered on screen, goto label
//=============================================================================
// note: portals will affect this command's output. if guard is being culled
//       off screen, command will not goto label
//===========================================================================*/
#define guard_is_on_screen_ID 0x42
#define guard_is_on_screen_LENGTH 0x02
#define guard_is_on_screen(label) \
        guard_is_on_screen_ID, \
        label,

/*=============================================================================
// name: guard_room_containing_self_is_on_screen
// command id: 43
// info: if the room containing guard is being rendered on screen, goto label
//=============================================================================
// note: only checks if room is being rendered, not if bond can see guard.
//       to check if guard is being rendered use command 42 instead.
//===========================================================================*/
#define guard_room_containing_self_is_on_screen_ID 0x43
#define guard_room_containing_self_is_on_screen_LENGTH 0x02
#define guard_room_containing_self_is_on_screen(label) \
        guard_room_containing_self_is_on_screen_ID, \
        label,

/*=============================================================================
// name: room_containing_pad_is_on_screen
// command id: 44
// info: if room containing pad is being rendered on screen, goto label
//=============================================================================
// note: only checks if room is being rendered, not if bond can see inside room
//===========================================================================*/
#define room_containing_pad_is_on_screen_ID 0x44
#define room_containing_pad_is_on_screen_LENGTH 0x04
#define room_containing_pad_is_on_screen(pad, label) \
        room_containing_pad_is_on_screen_ID, \
        chararray16(pad), \
        label,

/*=============================================================================
// name: guard_is_targeted_by_bond
// command id: 45
// info: if bond is looking/aiming at guard, goto label
//=============================================================================
// note: also checks if crosshair is aiming at guard
//===========================================================================*/
#define guard_is_targeted_by_bond_ID 0x45
#define guard_is_targeted_by_bond_LENGTH 0x02
#define guard_is_targeted_by_bond(label) \
        guard_is_targeted_by_bond_ID, \
        label,

/*=============================================================================
// name: guard_shot_from_bond_missed
// command id: 46
// info: if bond's shot missed/landed near guard, goto label
//=============================================================================
// note: command will sometimes goto label if guard was shot - use command
//       3E instead to check if guard was shot recently (more consistent)
//===========================================================================*/
#define guard_shot_from_bond_missed_ID 0x46
#define guard_shot_from_bond_missed_LENGTH 0x02
#define guard_shot_from_bond_missed(label) \
        guard_shot_from_bond_missed_ID, \
        label,

/*=============================================================================
// name: guard_counter_clockwise_direction_to_bond_less_than
// command id: 47
// info: if guard's counter-clockwise direction to bond < direction argument, goto label
//=============================================================================
// note: direction input (hex):
// 00: no rotation, never goto label because degrees are always above 0
// 40: bond and guard within 9-to-12 o'clock (90 degrees)
// 80: bond is on guard's left-side (180 degrees)
// C0: bond and guard within 3-to-12 o'clock (270 degrees)
// FF: full rotation, always goto label except for a tiny degree (0-359 degrees)
//===========================================================================*/
#define guard_counter_clockwise_direction_to_bond_less_than_ID 0x47
#define guard_counter_clockwise_direction_to_bond_less_than_LENGTH 0x03
#define guard_counter_clockwise_direction_to_bond_less_than(direction, label) \
        guard_counter_clockwise_direction_to_bond_less_than_ID, \
        direction, \
        label,

/*=============================================================================
// name: guard_counter_clockwise_direction_to_bond_greater_than
// command id: 48
// info: if guard's counter-clockwise direction to bond > direction argument, goto label
//=============================================================================
// note: direction input (hex):
// FF: no rotation, never goto label except for a tiny degree (0-1 degrees)
// C0: bond and guard within 12-to-3 o'clock (90 degrees)
// 80: bond on guard's right-side (180 degrees)
// 40: bond and guard within 12-to-9 o'clock (270 degrees)
// 00: full rotation, always goto label
//===========================================================================*/
#define guard_counter_clockwise_direction_to_bond_greater_than_ID 0x48
#define guard_counter_clockwise_direction_to_bond_greater_than_LENGTH 0x03
#define guard_counter_clockwise_direction_to_bond_greater_than(direction, label) \
        guard_counter_clockwise_direction_to_bond_greater_than_ID, \
        direction, \
        label,

/*=============================================================================
// name: guard_counter_clockwise_direction_from_bond_less_than
// command id: 49
// info: if bond's counter-clockwise direction to guard < direction argument, goto label
//=============================================================================
// note: direction input (hex):
// 00: no rotation, never goto label because degrees are always above 0
// 40: guard and bond within 9-to-12 o'clock (90 degrees)
// 80: guard is on bond's left-side (180 degrees)
// C0: guard and bond within 3-to-12 o'clock (270 degrees)
// FF: full rotation, always goto label except for a tiny degree (0-359 degrees)
//===========================================================================*/
#define guard_counter_clockwise_direction_from_bond_less_than_ID 0x49
#define guard_counter_clockwise_direction_from_bond_less_than_LENGTH 0x03
#define guard_counter_clockwise_direction_from_bond_less_than(direction, label) \
        guard_counter_clockwise_direction_from_bond_less_than_ID, \
        direction, \
        label,

/*=============================================================================
// name: guard_counter_clockwise_direction_from_bond_greater_than
// command id: 4A
// info: if bond's counter-clockwise direction to guard > direction argument, goto label
//=============================================================================
// note: direction input (hex):
// FF: no rotation, never goto label except for a tiny degree (0-1 degrees)
// C0: guard and bond within 12-to-3 o'clock (90 degrees)
// 80: guard on bond's right-side (180 degrees)
// 40: guard and bond within 12-to-9 o'clock (270 degrees)
// 00: full rotation, always goto label
//===========================================================================*/
#define guard_counter_clockwise_direction_from_bond_greater_than_ID 0x4A
#define guard_counter_clockwise_direction_from_bond_greater_than_LENGTH 0x03
#define guard_counter_clockwise_direction_from_bond_greater_than(direction, label) \
        guard_counter_clockwise_direction_from_bond_greater_than_ID, \
        direction, \
        label,

/*=============================================================================
// name: guard_distance_to_bond_less_than
// command id: 4B
// info: if guard's distance to bond < distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define guard_distance_to_bond_less_than_ID 0x4B
#define guard_distance_to_bond_less_than_LENGTH 0x04
#define guard_distance_to_bond_less_than(distance, label) \
        guard_distance_to_bond_less_than_ID, \
        chararray16(distance), \
        label,

/*=============================================================================
// name: guard_distance_to_bond_greater_than
// command id: 4C
// info: if guard's distance to bond > distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define guard_distance_to_bond_greater_than_ID 0x4C
#define guard_distance_to_bond_greater_than_LENGTH 0x04
#define guard_distance_to_bond_greater_than(distance, label) \
        guard_distance_to_bond_greater_than_ID, \
        chararray16(distance), \
        label,

/*=============================================================================
// name: chr_distance_to_pad_less_than
// command id: 4D
// info: if chr's distance to pad < distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define chr_distance_to_pad_less_than_ID 0x4D
#define chr_distance_to_pad_less_than_LENGTH 0x07
#define chr_distance_to_pad_less_than(chr_num, distance, pad, label) \
        chr_distance_to_pad_less_than_ID, \
        chr_num, \
        chararray16(distance), \
        chararray16(pad), \
        label,

/*=============================================================================
// name: chr_distance_to_pad_greater_than
// command id: 4E
// info: if chr's distance to pad > distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define chr_distance_to_pad_greater_than_ID 0x4E
#define chr_distance_to_pad_greater_than_LENGTH 0x07
#define chr_distance_to_pad_greater_than(chr_num, distance, pad, label) \
        chr_distance_to_pad_greater_than_ID, \
        chr_num, \
        chararray16(distance), \
        chararray16(pad), \
        label,

/*=============================================================================
// name: guard_distance_to_chr_less_than
// command id: 4F
// info: if guard's distance to chr < distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define guard_distance_to_chr_less_than_ID 0x4F
#define guard_distance_to_chr_less_than_LENGTH 0x05
#define guard_distance_to_chr_less_than(distance, chr_num, label) \
        guard_distance_to_chr_less_than_ID, \
        chararray16(distance), \
        chr_num, \
        label,

/*=============================================================================
// name: guard_distance_to_chr_greater_than
// command id: 50
// info: if guard's distance to chr > distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define guard_distance_to_chr_greater_than_ID 0x50
#define guard_distance_to_chr_greater_than_LENGTH 0x05
#define guard_distance_to_chr_greater_than(distance, chr_num, label) \
        guard_distance_to_chr_greater_than_ID, \
        chararray16(distance), \
        chr_num, \
        label,

/*=============================================================================
// name: guard_set_chr_preset_to_guard_within_distance
// command id: 51
// info: if guard's distance to any chr < distance argument, set chr->padpreset1
//       to found guard's chrnum and goto label
//=============================================================================
// note: argument scale is 10 units per meter. command does not pick the closest
// found chr, but whoever was first found within the distance argument. if no
// guards were found within distance range, do not goto label
//===========================================================================*/
#define guard_set_chr_preset_to_guard_within_distance_ID 0x51
#define guard_set_chr_preset_to_guard_within_distance_LENGTH 0x04
#define guard_set_chr_preset_to_guard_within_distance(distance, label) \
        guard_set_chr_preset_to_guard_within_distance_ID, \
        chararray16(distance), \
        label,

/*=============================================================================
// name: bond_distance_to_pad_less_than
// command id: 52
// info: if bond's distance to pad < distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define bond_distance_to_pad_less_than_ID 0x52
#define bond_distance_to_pad_less_than_LENGTH 0x06
#define bond_distance_to_pad_less_than(distance, pad, label) \
        bond_distance_to_pad_less_than_ID, \
        chararray16(distance), \
        chararray16(pad), \
        label,

/*=============================================================================
// name: bond_distance_to_pad_greater_than
// command id: 53
// info: if bond's distance to pad > distance argument, goto label
//=============================================================================
// note: argument scale is 10 units per meter
//===========================================================================*/
#define bond_distance_to_pad_greater_than_ID 0x53
#define bond_distance_to_pad_greater_than_LENGTH 0x06
#define bond_distance_to_pad_greater_than(distance, pad, label) \
        bond_distance_to_pad_greater_than_ID, \
        chararray16(distance), \
        chararray16(pad), \
        label,

/*=============================================================================
// name: chr_in_room_with_pad
// command id: 54
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
// info: if bond in same room with pad, goto label
//===========================================================================*/
#define bond_in_room_with_pad_ID 0x55
#define bond_in_room_with_pad_LENGTH 0x04
#define bond_in_room_with_pad(pad, label) \
        bond_in_room_with_pad_ID, \
        chararray16(pad), \
        label,

/*=============================================================================
// name: bond_collected_object
// command id: 56
// info: if bond collected tagged object, goto label
//===========================================================================*/
#define bond_collected_object_ID 0x56
#define bond_collected_object_LENGTH 0x03
#define bond_collected_object(object_tag, label) \
        bond_collected_object_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: item_is_stationary_within_level
// command id: 57
// info: if item exists in level and is stationary (not moving/in mid-air), goto label
//=============================================================================
// note: used to check if bond threw an item in level. also checks if item was
// attached to an object (item is stationary within level). so make sure command
// 58 takes priority over command 57 when using both commands
//===========================================================================*/
#define item_is_stationary_within_level_ID 0x57
#define item_is_stationary_within_level_LENGTH 0x03
#define item_is_stationary_within_level(item_num, label) \
        item_is_stationary_within_level_ID, \
        item_num, \
        label,

/*=============================================================================
// name: item_is_attached_to_object
// command id: 58
// info: if item was thrown onto tagged object, goto label
//=============================================================================
// note: used to check if bond threw an item onto a tagged object
//===========================================================================*/
#define item_is_attached_to_object_ID 0x58
#define item_is_attached_to_object_LENGTH 0x04
#define item_is_attached_to_object(item_num, object_tag, label) \
        item_is_attached_to_object_ID, \
        item_num, \
        object_tag, \
        label,

/*=============================================================================
// name: bond_has_item_equipped
// command id: 59
// info: if bond has an item equipped (currently held), goto label
//===========================================================================*/
#define bond_has_item_equipped_ID 0x59
#define bond_has_item_equipped_LENGTH 0x03
#define bond_has_item_equipped(item_num, label) \
        bond_has_item_equipped_ID, \
        item_num, \
        label,

/*=============================================================================
// name: object_exists
// command id: 5A
// info: if tagged object exists in level, goto label
//===========================================================================*/
#define object_exists_ID 0x5A
#define object_exists_LENGTH 0x03
#define object_exists(object_tag, label) \
        object_exists_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: object_not_destroyed
// command id: 5B
// info: if tagged object is not destroyed, goto label
//===========================================================================*/
#define object_not_destroyed_ID 0x5B
#define object_not_destroyed_LENGTH 0x03
#define object_not_destroyed(object_tag, label) \
        object_not_destroyed_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: object_was_activated
// command id: 5C
// info: if tagged object was activated since last check, goto label
//=============================================================================
// note: when executed, it will clear tagged object's activated flag. only bond
//       and command 5E can activate tagged objects
//===========================================================================*/
#define object_was_activated_ID 0x5C
#define object_was_activated_LENGTH 0x03
#define object_was_activated(object_tag, label) \
        object_was_activated_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: bond_used_gadget_on_object
// command id: 5D
// info: if bond used a gadget item on a tagged object since last check, goto label
//=============================================================================
// note: gadgets are a pre-defined list of items set to gadget flag:
// ITEM_BOMBDEFUSER
// ITEM_DATATHIEF
// ITEM_DOORDECODER
// ITEM_EXPLOSIVEFLOPPY
// ITEM_DATTAPE
//===========================================================================*/
#define bond_used_gadget_on_object_ID 0x5D
#define bond_used_gadget_on_object_LENGTH 0x03
#define bond_used_gadget_on_object(object_tag, label) \
        bond_used_gadget_on_object_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: object_activate
// command id: 5E
// info: activate a tagged object
//===========================================================================*/
#define object_activate_ID 0x5E
#define object_activate_LENGTH 0x02
#define object_activate(object_tag) \
        object_activate_ID, \
        object_tag,

/*=============================================================================
// name: object_destroy
// command id: 5F
// info: destroy/explode a tagged object
//=============================================================================
// note: only works if object is not destroyed. cannot destroy invincible objects
//===========================================================================*/
#define object_destroy_ID 0x5F
#define object_destroy_LENGTH 0x02
#define object_destroy(object_tag) \
        object_destroy_ID, \
        object_tag,

/*=============================================================================
// name: object_detach_from_chr
// command id: 60
// info: detach tagged object from chr and drop to ground
//=============================================================================
// note: item must be attached to a chr. embedded objects will not drop, only
//       works with attached objects. props can be damaged on drop
//===========================================================================*/
#define object_detach_from_chr_ID 0x60
#define object_detach_from_chr_LENGTH 0x02
#define object_detach_from_chr(object_tag) \
        object_detach_from_chr_ID, \
        object_tag,

/*=============================================================================
// name: chr_drop_all_concealed_items
// command id: 61
// info: make chr drop all concealed attachments
//=============================================================================
// note: item must be attached to chr, to drop held items use command 62. embedded
// objects will not drop, only works with attached objects. props can be damaged
// on drop
//===========================================================================*/
#define chr_drop_all_concealed_items_ID 0x61
#define chr_drop_all_concealed_items_LENGTH 0x02
#define chr_drop_all_concealed_items(chr_num) \
        chr_drop_all_concealed_items_ID, \
        chr_num,

/*=============================================================================
// name: chr_drop_all_held_items
// command id: 62
// info: make chr drop all held items
//=============================================================================
// note: items must be held by chr, to drop concealed attachments use command 61.
// embedded objects will not drop, only works with attached objects
//===========================================================================*/
#define chr_drop_all_held_items_ID 0x62
#define chr_drop_all_held_items_LENGTH 0x02
#define chr_drop_all_held_items(chr_num) \
        chr_drop_all_held_items_ID, \
        chr_num,

/*=============================================================================
// name: bond_collect_object
// command id: 63
// info: force bond to instantly collect a tagged object
//=============================================================================
// note: does not trigger bottom text telling player they collected an item
//===========================================================================*/
#define bond_collect_object_ID 0x63
#define bond_collect_object_LENGTH 0x02
#define bond_collect_object(object_tag) \
        bond_collect_object_ID, \
        object_tag,

/*=============================================================================
// name: chr_equip_object
// command id: 64
// info: makes chr hold tagged object
//=============================================================================
// note: if chr's hands are occupied, object will be equipped as an concealed
// attachment. but if tagged object's handedness flag is free on guard then
// guard will equip weapon. tagged object's prop must have a holding position
// command within the model file
//===========================================================================*/
#define chr_equip_object_ID 0x64
#define chr_equip_object_LENGTH 0x03
#define chr_equip_object(object_tag, chr_num) \
        chr_equip_object_ID, \
        object_tag, \
        chr_num,

/*=============================================================================
// name: object_move_to_pad
// command id: 65
// info: move object to pad
//=============================================================================
// note: if object is assigned to extra pad, then object scale will be lost after
//       moving to target pad. object will inherit rotation from target pad
//===========================================================================*/
#define chr_equip_object_ID 0x65
#define chr_equip_object_LENGTH 0x04
#define chr_equip_object(object_tag, pad) \
        chr_equip_object_ID, \
        object_tag, \
        chrarray16(pad),

/*=============================================================================
// name: door_open
// command id: 66
// info: open tagged door
//=============================================================================
// note: open tagged door even if locked
//===========================================================================*/
#define door_open_ID 0x66
#define door_open_LENGTH 0x02
#define door_open(object_tag) \
        door_open_ID, \
        object_tag,

/*=============================================================================
// name: door_close
// command id: 67
// info: close tagged door
//===========================================================================*/
#define door_close_ID 0x67
#define door_close_LENGTH 0x02
#define door_close(object_tag) \
        door_close_ID, \
        object_tag,

/*=============================================================================
// name: door_check_state
// command id: 68
// info: if tagged door state matches any of bitfield argument, goto label
//=============================================================================
// note: door flag state (hex):
// 01: closed
// 02: open
// 04: closing
// 08: opening
//===========================================================================*/
#define door_check_state_ID 0x68
#define door_check_state_LENGTH 0x04
#define door_check_state(object_tag, door_state, label) \
        door_check_state_ID, \
        object_tag, \
        door_state, \
        label,

/*=============================================================================
// name: door_has_been_opened_before
// command id: 69
// info: if tagged door has been opened before, goto label
//=============================================================================
// note: if tagged door is open by default in setup, then it must be closed before
//       it will check if opened again
//===========================================================================*/
#define door_has_been_opened_before_ID 0x69
#define door_has_been_opened_before_LENGTH 0x03
#define door_has_been_opened_before(object_tag, label) \
        door_has_been_opened_before_ID, \
        object_tag, \
        label,

/*=============================================================================
// name: door_set_lock
// command id: 6A
// info: set tagged door's lock with flags
//=============================================================================
// note: use DOOR_LOCK_# flags for lock argument. lock flags are same as used
//       within setup for doors and keys
//===========================================================================*/
#define door_set_lock_ID 0x6A
#define door_set_lock_LENGTH 0x03
#define door_set_lock(object_tag, lock_flag) \
        door_set_lock_ID, \
        object_tag, \
        lock_flag,

/*=============================================================================
// name: door_unset_lock
// command id: 6B
// info: unset tagged door's lock with flags
//=============================================================================
// note: use DOOR_LOCK_# flags for lock argument. lock flags are same as used
//       within setup for doors and keys
//===========================================================================*/
#define door_unset_lock_ID 0x6B
#define door_unset_lock_LENGTH 0x03
#define door_unset_lock(object_tag, lock_flag) \
        door_unset_lock_ID, \
        object_tag, \
        lock_flag,

/*=============================================================================
// name: door_check_lock
// command id: 6C
// info: if tagged door's lock flags matches any lock flag argument, goto label
//=============================================================================
// note: use DOOR_LOCK_# flags for lock argument. lock flags are same as used
//       within setup for doors and keys
//===========================================================================*/
#define door_check_lock_ID 0x6C
#define door_check_lock_LENGTH 0x04
#define door_check_lock(object_tag, lock_flag, label) \
        door_check_lock_ID, \
        object_tag, \
        lock_flag, \
        label,

/*=============================================================================
// name: objective_num_complete
// command id: 6D
// info: if objective # completed, goto label
//=============================================================================
// note: ignores difficulty settings. for example - if game on agent and player
// completes an unlisted 00 agent objective, checking that objective num will
// goto label
//===========================================================================*/
#define objective_num_complete_ID 0x6D
#define objective_num_complete_LENGTH 0x03
#define objective_num_complete(obj_num, label) \
        objective_num_complete_ID, \
        obj_num, \
        label,

/*=============================================================================
// name: guard_unknown6E
// command id: 6E
// info: unknown command, goto label
//=============================================================================
// note: sets chr->padpreset1
// bitfield (hex):
// 0001: sets to nearest pad to path to bond
// 0004: ???
// 0008: ???
// 0010: ???
// 0020: ???
//===========================================================================*/
#define guard_unknown6E_ID 0x6E
#define guard_unknown6E_LENGTH 0x03
#define guard_unknown6E(unknown_flag, label) \
        guard_unknown6E_ID, \
        unknown_flag, \
        label,

/*=============================================================================
// name: guard_unknown6F
// command id: 6F
// info: unknown command, goto label
//=============================================================================
// note: sets chr->padpreset1
// bitfield (hex):
// 0001: set to nearest pad in direction of bond
// 0004: ???
// 0008: ???
// 0010: ???
// 0020: ???
//===========================================================================*/
#define guard_unknown6F_ID 0x6F
#define guard_unknown6F_LENGTH 0x03
#define guard_unknown6F(unknown_flag, label) \
        guard_unknown6F_ID, \
        unknown_flag, \
        label,

/*=============================================================================
// name: game_difficulty_less_than
// command id: 70
// info: if current difficulty < difficulty argument, goto label
//=============================================================================
// note: provided argument will compare the following difficult settings
// 01: agent only
// 02: agent/secret agent
// 03: agent/secret agent/00 agent
//===========================================================================*/
#define game_difficulty_less_than_ID 0x70
#define game_difficulty_less_than_LENGTH 0x03
#define game_difficulty_less_than(argument, label) \
        game_difficulty_less_than_ID, \
        argument, \
        label,

/*=============================================================================
// name: game_difficulty_greater_than
// command id: 71
// info: if current difficulty > difficulty argument, goto label
//=============================================================================
// note: provided argument will compare the following difficult settings
// 00: secret agent/00 agent/007
// 01: 00 agent/007
// 02: 007 only
//===========================================================================*/
#define game_difficulty_greater_than_ID 0x71
#define game_difficulty_greater_than_LENGTH 0x03
#define game_difficulty_greater_than(argument, label) \
        game_difficulty_greater_than_ID, \
        argument, \
        label,

/*=============================================================================
// name: mission_time_less_than
// command id: 72
// info: if current mission time (in seconds) < seconds argument, goto label
//=============================================================================
// note: converts (unsigned) seconds to float and compares against mission timer
//===========================================================================*/
#define mission_time_less_than_ID 0x72
#define mission_time_less_than_LENGTH 0x04
#define mission_time_less_than(seconds, label) \
        mission_time_less_than_ID, \
        chararray16(seconds), \
        label,

/*=============================================================================
// name: mission_time_greater_than
// command id: 73
// info: if current mission time (in seconds) > seconds argument, goto label
//=============================================================================
// note: converts (unsigned) seconds to float and compares against mission timer
//===========================================================================*/
#define mission_time_greater_than_ID 0x73
#define mission_time_greater_than_LENGTH 0x04
#define mission_time_greater_than(seconds, label) \
        mission_time_greater_than_ID, \
        chararray16(seconds), \
        label,

/*=============================================================================
// name: system_power_time_less_than
// command id: 74
// info: if system powered on time (in minutes) < minutes argument, goto label
//=============================================================================
// note: converts (unsigned) minutes to float and compares against system time
//===========================================================================*/
#define system_power_time_less_than_ID 0x74
#define system_power_time_less_than_LENGTH 0x04
#define system_power_time_less_than(minutes, label) \
        system_power_time_less_than_ID, \
        chararray16(minutes), \
        label,

/*=============================================================================
// name: system_power_time_greater_than
// command id: 75
// info: if system powered on time (in minutes) > minutes argument, goto label
//=============================================================================
// note: converts (unsigned) minutes to float and compares against system time
//===========================================================================*/
#define system_power_time_greater_than_ID 0x75
#define system_power_time_greater_than_LENGTH 0x04
#define system_power_time_greater_than(minutes, label) \
        system_power_time_greater_than_ID, \
        chararray16(minutes), \
        label,

/*=============================================================================
// name: level_id_less_than
// command id: 76
// info: if current level id < level id argument, goto label
//=============================================================================
// note: level id uses LEVELID enum values, not briefing menu stage number
//===========================================================================*/
#define level_id_less_than_ID 0x76
#define level_id_less_than_LENGTH 0x03
#define level_id_less_than(level_id, label) \
        level_id_less_than_ID, \
        level_id, \
        label,

/*=============================================================================
// name: level_id_greater_than
// command id: 77
// info: if current level id > level id argument, goto label
//=============================================================================
// note: level id uses LEVELID enum values, not briefing menu stage number
//===========================================================================*/
#define level_id_greater_than_ID 0x77
#define level_id_greater_than_LENGTH 0x03
#define level_id_greater_than(level_id, label) \
        level_id_greater_than_ID, \
        level_id, \
        label,

/*=============================================================================
// name: guard_hits_less_than
// command id: 78
// info: if guard's hits taken < hit_num, goto label
//=============================================================================
// note: compares signed byte against chr->numarghs
//===========================================================================*/
#define guard_hits_less_than_ID 0x78
#define guard_hits_less_than_LENGTH 0x03
#define guard_hits_less_than(hit_num, label) \
        guard_hits_less_than_ID, \
        hit_num, \
        label,

/*=============================================================================
// name: guard_hits_greater_than
// command id: 79
// info: if guard's hits taken > hit_num, goto label
//=============================================================================
// note: compares signed byte argument against chr->numarghs
//===========================================================================*/
#define guard_hits_greater_than_ID 0x79
#define guard_hits_greater_than_LENGTH 0x03
#define guard_hits_greater_than(hit_num, label) \
        guard_hits_greater_than_ID, \
        hit_num, \
        label,

/*=============================================================================
// name: guard_hits_missed_less_than
// command id: 7A
// info: if bond's shot missed/landed near guard total < missed_num, goto label
//=============================================================================
// note: compares signed byte against chr->numclosearghs
//===========================================================================*/
#define guard_hits_missed_less_than_ID 0x7A
#define guard_hits_missed_less_than_LENGTH 0x03
#define guard_hits_missed_less_than(missed_num, label) \
        guard_hits_missed_less_than_ID, \
        missed_num, \
        label,

/*=============================================================================
// name: guard_hits_missed_greater_than
// command id: 7B
// info: if bond's shot missed/landed near guard total > missed_num, goto label
//=============================================================================
// note: compares signed byte argument against chr->numclosearghs
//===========================================================================*/
#define guard_hits_missed_greater_than_ID 0x7B
#define guard_hits_missed_greater_than_LENGTH 0x03
#define guard_hits_missed_greater_than(missed_num, label) \
        guard_hits_missed_greater_than_ID, \
        missed_num, \
        label,

/*=============================================================================
// name: chr_health_less_than
// command id: 7C
// info: if chr's health < health argument, goto label
//=============================================================================
// note: argument is unsigned. converted to float and compares different between
// chr->maxdamage - chr->damage. default guard health is 40 (0x28), or after
// float conversion 4.0f. armour is tested
//===========================================================================*/
#define chr_health_less_than_ID 0x7C
#define chr_health_less_than_LENGTH 0x04
#define chr_health_less_than(chr_num, health, label) \
        chr_health_less_than_ID, \
        chr_num, \
        health, \
        label,

/*=============================================================================
// name: chr_health_greater_than
// command id: 7D
// info: if chr's health > health argument, goto label
//=============================================================================
// note: argument is unsigned. converted to float and compares different between
// chr->maxdamage - chr->damage. default guard health is 40 (0x28), or after
// float conversion 4.0f. armour is tested
//===========================================================================*/
#define chr_health_greater_than_ID 0x7D
#define chr_health_greater_than_LENGTH 0x04
#define chr_health_greater_than(chr_num, health, label) \
        chr_health_greater_than_ID, \
        chr_num, \
        health, \
        label,

/*=============================================================================
// name: bond_health_less_than
// command id: 7F
// info: if bond's health < health argument, goto label
//=============================================================================
// note: does not check armour. health argument is unsigned, argument range is
//       between 00 and FF, with FF equal to 100% health
//===========================================================================*/
#define bond_health_less_than_ID 0x7F
#define bond_health_less_than_LENGTH 0x03
#define bond_health_less_than(health, label) \
        bond_health_less_than_ID, \
        health, \
        label,

/*=============================================================================
// name: bond_health_greater_than
// command id: 80
// info: if bond's health > health argument, goto label
//=============================================================================
// note: does not check armour. health argument is unsigned, argument range is
//       between 00 and FF, with FF equal to 100% health
//===========================================================================*/
#define bond_health_greater_than_ID 0x80
#define bond_health_greater_than_LENGTH 0x03
#define bond_health_greater_than(health, label) \
        bond_health_greater_than_ID, \
        health, \
        label,

/*=============================================================================
// name: guard_set_hearing_scale
// command id: 8B
// info: set guard's hearing scale - the higher the value, the further away guard
//       can hear bond's gunfire
//=============================================================================
// note: sets to chr->hearingscale. default value is 0x03E8 (1000 dec). argument
//       is converted to float and divided by 1000 before setting to hearingscale
//===========================================================================*/
#define guard_set_hearing_scale_ID 0x8B
#define guard_set_hearing_scale_LENGTH 0x03
#define guard_set_hearing_scale(hearing_scale) \
        guard_set_hearing_scale_ID, \
        chararray16(hearing_scale),

/*=============================================================================
// name: guard_set_vision_range
// command id: 8C
// info: set guard's vision range - the smaller the value, the longer the guard
//       takes to detect bond with command 32. does not affect firing distance
//=============================================================================
// note: sets to chr->visionrange. default value is 0x0064 (100 dec). argument
//       is converted to float before setting to hearingscale
//===========================================================================*/
#define guard_set_vision_range_ID 0x8C
#define guard_set_vision_range_LENGTH 0x02
#define guard_set_vision_range(vision_range) \
        guard_set_vision_range_ID, \
        vision_range,

/*=============================================================================
// name: guard_set_grenade_probability
// command id: 8D
// info: set guard's grenade probability - used for rng comparison by command 1A.
//       the higher the value, the likelyhood of guard throwing a grenade
//=============================================================================
// note: sets to chr->grenadeprob - 0 by default. argument is unsigned. the only
// way to make guards throw grenades is by using this command or assigning setup
// object 0x12 to chr
//===========================================================================*/
#define guard_set_grenade_probability_ID 0x8D
#define guard_set_grenade_probability_LENGTH 0x02
#define guard_set_grenade_probability(grenade_prob) \
        guard_set_grenade_probability_ID, \
        grenade_prob,

/*=============================================================================
// name: guard_set_chr_num
// command id: 8E
// info: set guard's chr num
//=============================================================================
// note: sets to chr->chrnum - commonly used for respawning guards
//===========================================================================*/
#define guard_set_chr_num_ID 0x8E
#define guard_set_chr_num_LENGTH 0x02
#define guard_set_chr_num(chr_num) \
        guard_set_chr_num_ID, \
        chr_num,

/*=============================================================================
// name: guard_set_health_total
// command id: 8F
// info: set guard's total health - the higher the value, the more shots needed
//       to kill guard. 
//=============================================================================
// note: sets to chr->maxdamage. default health is 4.0f (0x0028/40 dec for argument).
// argument is converted to float and divided by 10 before setting to maxdamage.
// if difficulty mode 007 is active, command will use 007 health modifier
//===========================================================================*/
#define guard_set_health_total_ID 0x8F
#define guard_set_health_total_LENGTH 0x03
#define guard_set_health_total(total_health) \
        guard_set_health_total_ID, \
        chararray16(total_health),

/*=============================================================================
// name: guard_set_armour
// command id: 90
// info: set guard's armour value - the higher the value, the higher the armour.
// armoured guards will not show hit reactions. they also don't instantly die
// from explosions, instead taking damaged based on how close they are to explosions
// like bond. to any setup designers reading this, please use armour sparingly!
//=============================================================================
// note: subtracts from chr->damage - negative damage means guard has armour.
// instead of storing armour as a separate chr variable, we reuse the current
// damage and read negative damage as armour. technically this command should
// be titled 'guard_remove_damage' but its used mostly for adding armour to guards.
// argument is converted to float and divided by 10 before subtracting chr->damage.
// if difficulty mode 007 is active, command will use 007 health modifier.
// argument is unsigned - 0xFFFF will be set to 6553.5f armour, or -6553.5f damage
//===========================================================================*/
#define guard_set_armour_ID 0x90
#define guard_set_armour_LENGTH 0x03
#define guard_set_armour(armour_value) \
        guard_set_armour_ID, \
        chararray16(armour_value),

/*=============================================================================
// name: guard_set_speed_rating
// command id: 91
// info: set guard's speed rating - controls how quickly the guard animates.
//=============================================================================
// note: sets to chr->speedrating. default speed is 0 - argument is signed.
// negative values will make guard animate slower - this affects firing animations.
// command does not use 007 reaction speed modifier. do not use values above 0x60
// or it may crash
//===========================================================================*/
#define guard_set_speed_rating_ID 0x91
#define guard_set_speed_rating_LENGTH 0x02
#define guard_set_speed_rating(speed_rating) \
        guard_set_speed_rating_ID, \
        speed_rating,

/*=============================================================================
// name: guard_set_argh_rating
// command id: 92
// info: set guard's argh rating - controls how quickly the guard recovers from
//       being shot. range is -128 to 127 (127 show almost no hit reaction)
//=============================================================================
// note: sets to chr->arghrating. default value is 0 - argument is signed.
// negative values will make guard animate slower - this affects firing animations.
// command does not use 007 reaction speed modifier
//===========================================================================*/
#define guard_set_argh_rating_ID 0x92
#define guard_set_argh_rating_LENGTH 0x02
#define guard_set_argh_rating(speed_rating) \
        guard_set_argh_rating_ID, \
        speed_rating,

/*=============================================================================
// name: guard_set_accuracy_rating
// command id: 93
// info: set guard's accuracy rating - controls how accurately the guard fires
//       their weapon
//=============================================================================
// note: sets to chr->accuracyrating. default value is 0 and ranges from -128
// to 127, argument is signed byte. command does not use 007 accuracy modifier
//===========================================================================*/
#define guard_set_accuracy_rating_ID 0x93
#define guard_set_accuracy_rating_LENGTH 0x02
#define guard_set_accuracy_rating(accuracy_rating) \
        guard_set_accuracy_rating_ID, \
        accuracy_rating,

/*=============================================================================
// name: guard_bitfield_set_on
// command id: 94
// info: set chr->BITFIELD on
//=============================================================================
// note: can be used to store a flag per chr, useful for missions. global lists
// reserve flag 01, which is defined as BITFIELD_DONT_POINT_AT_BOND. other bits
// are free to use for each setup
//===========================================================================*/
#define guard_bitfield_set_on_ID 0x94
#define guard_bitfield_set_on_LENGTH 0x02
#define guard_bitfield_set_on(bitfield) \
        guard_bitfield_set_on_ID, \
        bitfield,

/*=============================================================================
// name: guard_bitfield_set_off
// command id: 95
// info: set chr->BITFIELD off
//=============================================================================
// note: can be used to store a flag per chr, useful for missions. global lists
// reserve flag 01, which is defined as BITFIELD_DONT_POINT_AT_BOND. other bits
// are free to use for each setup
//===========================================================================*/
#define guard_bitfield_set_off_ID 0x95
#define guard_bitfield_set_off_LENGTH 0x02
#define guard_bitfield_set_off(bitfield) \
        guard_bitfield_set_off_ID, \
        bitfield,

/*=============================================================================
// name: guard_bitfield_is_set_on
// command id: 96
// info: if bits is set on in chr->BITFIELD, goto label
//===========================================================================*/
#define guard_bitfield_is_set_on_ID 0x96
#define guard_bitfield_is_set_on_LENGTH 0x03
#define guard_bitfield_is_set_on(bitfield, label) \
        guard_bitfield_is_set_on_ID, \
        bitfield, \
        label,

/*=============================================================================
// name: chr_bitfield_set_on
// command id: 97
// info: set chr->BITFIELD on
//=============================================================================
// note: can be used to store a flag per chr, useful for missions. global lists
// reserve flag 01, which is defined as BITFIELD_DONT_POINT_AT_BOND. other bits
// are free to use for each setup
//===========================================================================*/
#define chr_bitfield_set_on_ID 0x97
#define chr_bitfield_set_on_LENGTH 0x03
#define chr_bitfield_set_on(chr_num, bitfield) \
        chr_bitfield_set_on_ID, \
        chr_num, \
        bitfield,

/*=============================================================================
// name: chr_bitfield_set_off
// command id: 98
// info: set chr->BITFIELD off
//=============================================================================
// note: can be used to store a flag per chr, useful for missions. global lists
// reserve flag 01, which is defined as BITFIELD_DONT_POINT_AT_BOND. other bits
// are free to use for each setup
//===========================================================================*/
#define chr_bitfield_set_off_ID 0x98
#define chr_bitfield_set_off_LENGTH 0x03
#define chr_bitfield_set_off(chr_num, bitfield) \
        chr_bitfield_set_off_ID, \
        chr_num, \
        bitfield,

/*=============================================================================
// name: chr_bitfield_is_set_on
// command id: 99
// info: if bits is set on in chr->BITFIELD, goto label
//===========================================================================*/
#define chr_bitfield_is_set_on_ID 0x99
#define chr_bitfield_is_set_on_LENGTH 0x04
#define chr_bitfield_is_set_on(chr_num, bitfield, label) \
        chr_bitfield_is_set_on_ID, \
        chr_num, \
        bitfield, \
        label,

/*=============================================================================
// name: objective_bitfield_set_on
// command id: 9A
// info: set bits in objective bitfield on
//=============================================================================
// note: can be used to store a mission unique objective flag, which can be set
// to mission objectives. it can also be used to store miscellaneous flags used
// by other ai lists
//===========================================================================*/
#define objective_bitfield_set_on_ID 0x9A
#define objective_bitfield_set_on_LENGTH 0x05
#define objective_bitfield_set_on(bitfield) \
        objective_bitfield_set_on_ID, \
        chararray32(bitfield)

/*=============================================================================
// name: objective_bitfield_set_off
// command id: 9B
// info: set bits in objective bitfield off
//=============================================================================
// note: can be used to store a mission unique objective flag, which can be set
// to mission objectives. it can also be used to store miscellaneous flags used
// by other ai lists
//===========================================================================*/
#define objective_bitfield_set_off_ID 0x9B
#define objective_bitfield_set_off_LENGTH 0x05
#define objective_bitfield_set_off(bitfield) \
        objective_bitfield_set_off_ID, \
        chararray32(bitfield)

/*=============================================================================
// name: objective_bitfield_is_set_on
// command id: 9C
// info: if bits in objective bitfield are set on, goto label
//=============================================================================
// note: can check multiple flags at once
//===========================================================================*/
#define objective_bitfield_is_set_on_ID 0x9C
#define objective_bitfield_is_set_on_LENGTH 0x06
#define objective_bitfield_is_set_on(bitfield, label) \
        objective_bitfield_is_set_on_ID, \
        chararray32(bitfield), \
        label,

/*=============================================================================
// name: guard_flags_set_on
// command id: 9D
// info: set chr->chrflags on
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine.
// bitfield (hex):
// 00000002: sunglasses
// 00000010: invincible
// 00000040: can shoot other guards
// 00000400: hidden
// 00000800: no autoaim
// 00001000: lock y position (no gravity, used for dam/cradle jump)
// 00002000: no shadow
// 00004000: ignore animation translation
// 00010000: count death as civilian killed
// 00080000: increase sprinting speed
//===========================================================================*/
#define guard_flags_set_on_ID 0x9D
#define guard_flags_set_on_LENGTH 0x05
#define guard_flags_set_on(bitfield) \
        guard_flags_set_on_ID, \
        chararray32(bitfield),

/*=============================================================================
// name: guard_flags_set_off
// command id: 9E
// info: set chr->chrflags off
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine.
// bitfield (hex):
// 00000002: sunglasses
// 00000010: invincible
// 00000040: can shoot other guards
// 00000400: hidden
// 00000800: no autoaim
// 00001000: lock y position (no gravity, used for dam/cradle jump)
// 00002000: no shadow
// 00004000: ignore animation translation
// 00010000: count death as civilian killed
// 00080000: increase sprinting speed
//===========================================================================*/
#define guard_flags_set_off_ID 0x9E
#define guard_flags_set_off_LENGTH 0x05
#define guard_flags_set_off(bitfield) \
        guard_flags_set_off_ID, \
        chararray32(bitfield),

/*=============================================================================
// name: guard_flags_is_set_on
// command id: 9F
// info: if bits is set on in chr->chrflags, goto label
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine.
// bitfield (hex):
// 00000002: sunglasses
// 00000010: invincible
// 00000040: can shoot other guards
// 00000400: hidden
// 00000800: no autoaim
// 00001000: lock y position (no gravity, used for dam/cradle jump)
// 00002000: no shadow
// 00004000: ignore animation translation
// 00010000: count death as civilian killed
// 00080000: increase sprinting speed
//===========================================================================*/
#define guard_flags_is_set_on_ID 0x9F
#define guard_flags_is_set_on_LENGTH 0x06
#define guard_flags_is_set_on(bitfield, label) \
        guard_flags_is_set_on_ID, \
        chararray32(bitfield), \
        label,

/*=============================================================================
// name: chr_flags_set_on
// command id: A0
// info: set chr->chrflags on
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine.
// bitfield (hex):
// 00000002: sunglasses
// 00000010: invincible
// 00000040: can shoot other guards
// 00000400: hidden
// 00000800: no autoaim
// 00001000: lock y position (no gravity, used for dam/cradle jump)
// 00002000: no shadow
// 00004000: ignore animation translation
// 00010000: count death as civilian killed
// 00080000: increase sprinting speed
//===========================================================================*/
#define chr_flags_set_on_ID 0xA0
#define chr_flags_set_on_LENGTH 0x06
#define chr_flags_set_on(chr_num, bitfield) \
        chr_flags_set_on_ID, \
        chr_num, \
        chararray32(bitfield),

/*=============================================================================
// name: chr_flags_set_off
// command id: A1
// info: set chr->chrflags off
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine.
// bitfield (hex):
// 00000002: sunglasses
// 00000010: invincible
// 00000040: can shoot other guards
// 00000400: hidden
// 00000800: no autoaim
// 00001000: lock y position (no gravity, used for dam/cradle jump)
// 00002000: no shadow
// 00004000: ignore animation translation
// 00010000: count death as civilian killed
// 00080000: increase sprinting speed
//===========================================================================*/
#define chr_flags_set_off_ID 0xA1
#define chr_flags_set_off_LENGTH 0x06
#define chr_flags_set_off(chr_num, bitfield) \
        chr_flags_set_off_ID, \
        chr_num, \
        chararray32(bitfield),

/*=============================================================================
// name: chr_flags_is_set_on
// command id: A2
// info: if bits is set on in chr->chrflags, goto label
//=============================================================================
// note: chr->chrflags are not ai list or setup exclusive, they are controlled
// by many parts of the engine.
// bitfield (hex):
// 00000002: sunglasses
// 00000010: invincible
// 00000040: can shoot other guards
// 00000400: hidden
// 00000800: no autoaim
// 00001000: lock y position (no gravity, used for dam/cradle jump)
// 00002000: no shadow
// 00004000: ignore animation translation
// 00010000: count death as civilian killed
// 00080000: increase sprinting speed
//===========================================================================*/
#define chr_flags_is_set_on_ID 0xA2
#define chr_flags_is_set_on_LENGTH 0x07
#define chr_flags_is_set_on(chr_num, bitfield, label) \
        chr_flags_is_set_on_ID, \
        chr_num, \
        chararray32(bitfield), \
        label,

/*=============================================================================
// name: guard_set_chr_preset
// command id: A9
// info: set guard->chrpreset1 to chr_preset
//=============================================================================
// note: can be used by obj ai lists
//===========================================================================*/
#define guard_set_chr_preset_ID 0xA9
#define guard_set_chr_preset_LENGTH 0x02
#define guard_set_chr_preset(chr_preset) \
        guard_set_chr_preset_ID, \
        chr_preset,

/*=============================================================================
// name: chr_set_chr_preset
// command id: AA
// info: set chr->chrpreset1 to chr_preset
//===========================================================================*/
#define chr_set_chr_preset_ID 0xAA
#define chr_set_chr_preset_LENGTH 0x03
#define chr_set_chr_preset(chr_num, chr_preset) \
        chr_set_chr_preset_ID, \
        chr_num, \
        chr_preset,

/*=============================================================================
// name: guard_set_pad_preset
// command id: AB
// info: set guard->padpreset1 to pad_preset
//=============================================================================
// note: can be used by obj ai lists
//===========================================================================*/
#define guard_set_pad_preset_ID 0xAB
#define guard_set_pad_preset_LENGTH 0x03
#define guard_set_pad_preset(chr_preset) \
        guard_set_pad_preset_ID, \
        chrarray16(pad_preset),

/*=============================================================================
// name: chr_set_pad_preset
// command id: AC
// info: set chr->padpreset1 to pad_preset
//===========================================================================*/
#define chr_set_pad_preset_ID 0xAC
#define chr_set_pad_preset_LENGTH 0x04
#define chr_set_pad_preset(chr_num, chr_preset) \
        chr_set_pad_preset_ID, \
        chr_num, \
        chrarray16(pad_preset),

/*=============================================================================
// name: debug_log
// command id: AD
// info: debug comment
//=============================================================================
// note: may have originally printed to stderr on host sgi devkit. command is
// variable length must end with null terminator character '\0' (debug_log_end)
//===========================================================================*/
#define debug_log_ID 0xAD
#define debug_log_LENGTH 0x32 // max length
#define debug_log \
        debug_log_ID,

/*=============================================================================
// name: chr_timer_reset_start
// command id: AE
// info: reset and start chr->timer60
//=============================================================================
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
// info: reset chr->timer60
//=============================================================================
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
// info: pauses chr->timer60 (does not reset value)
//=============================================================================
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
// info: start chr->timer60 (does not reset value)
//=============================================================================
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
// info: if chr->timer60 is not active (paused), goto label
//=============================================================================
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
// info: if chr->timer60 < time60, goto label
//=============================================================================
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
// info: if chr->timer60 > time60, goto label
//=============================================================================
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
// info: hides the hud timer
//=============================================================================
// note: can be used as a hidden global timer for objective logic
//===========================================================================*/
#define hud_timer_hide_ID 0xB6
#define hud_timer_hide_LENGTH 0x01
#define hud_timer_hide \
        hud_timer_hide_ID,

/*=============================================================================
// name: hud_timer_set
// command id: B7
// info: set the hud timer
//=============================================================================
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
// info: stops the hud timer
//===========================================================================*/
#define hud_timer_stop_ID 0xB8
#define hud_timer_stop_LENGTH 0x01
#define hud_timer_stop \
        hud_timer_stop_ID,

/*=============================================================================
// name: hud_timer_start
// command id: B9
// info: start the hud timer
//===========================================================================*/
#define hud_timer_start_ID 0xB9
#define hud_timer_start_LENGTH 0x01
#define hud_timer_start \
        hud_timer_start_ID,

/*=============================================================================
// name: hud_timer_has_stopped
// command id: BA
// info: if hud timer isn't active (paused), goto label
//=============================================================================
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
// info: if hud timer < seconds, goto label
//=============================================================================
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
// info: if hud timer > seconds, goto label
//=============================================================================
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
// name: guard_spawn_item
// command id: BF
// info: spawn weapon for guard, goto label if successful
//=============================================================================
// note: if out of memory/can't spawn item/hands occupied, do not got label.
// spawned prop must have a holding position command within the model file,
// else use conceal flag so guard does not attempt to hold prop
//===========================================================================*/
#define guard_spawn_item_ID 0xBF
#define guard_spawn_item_LENGTH 0x09
#define guard_spawn_item(prop_num, item_num, prop_bitfield, label) \
        guard_spawn_item_ID, \
        chararray16(prop_num), \
        item_num, \
        chararray32(prop_bitfield), \
        label,

/*=============================================================================
// name: guard_spawn_hat
// command id: C0
// info: spawn hat for guard, goto label if successful
//=============================================================================
// note: if out of memory/can't spawn item/already have hat, do not got label.
// spawned hat must have a holding position command within the model file
//===========================================================================*/
#define guard_spawn_hat_ID 0xC0
#define guard_spawn_hat_LENGTH 0x08
#define guard_spawn_hat(prop_num, prop_bitfield, label) \
        guard_spawn_hat_ID, \
        chararray16(prop_num), \
        chararray32(prop_bitfield), \
        label,

/*=============================================================================
// name: chr_spawn_clone
// command id: C1
// info: if guard has clone flag on, spawn a new guard - goto label if successful
//=============================================================================
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
// name: text_print_bottom
// command id: C2
// info: print text slot to bottom left part of screen (where pickup text is located)
//=============================================================================
// note: if text slot is not currently allocated in memory, game will softlock.
// expects string to end with \n character
//===========================================================================*/
#define text_print_bottom_ID 0xC2
#define text_print_bottom_LENGTH 0x03
#define text_print_bottom(text_slot) \
        text_print_bottom_ID, \
        chrarray16(text_slot),

/*=============================================================================
// name: text_print_top
// command id: C3
// info: print text slot to top part of screen (speech)
//=============================================================================
// note: if text slot is not currently allocated in memory, game will softlock.
// ensure that end of text has a \n character or it will misalign background area
//===========================================================================*/
#define text_print_top_ID 0xC3
#define text_print_top_LENGTH 0x03
#define text_print_top(text_slot) \
        text_print_top_ID, \
        chrarray16(text_slot),

/*=============================================================================
// name: vehicle_start_path
// command id: CB
// info: makes vehicle follow a predefined path within setup
//===========================================================================*/
#define vehicle_start_path_ID 0xCB
#define vehicle_start_path_LENGTH 0x02
#define vehicle_start_path(path_num) \
        vehicle_start_path_ID, \
        path_num,

/*=============================================================================
// name: vehicle_speed
// command id: CC
// info: sets vehicle speed, usually paired with command CB
//=============================================================================
// note: arguments are unsigned. 1000 units = 1 meter per second travel speed.
//       time60_to_top_speed is number of game ticks to reach top speed
//===========================================================================*/
#define vehicle_speed_ID 0xCC
#define vehicle_speed_LENGTH 0x05
#define vehicle_speed(top_speed, time60_to_top_speed) \
        vehicle_speed_ID, \
        chararray16(top_speed), \
        chararray16(time60_to_top_speed),

/*=============================================================================
// name: bond_in_tank
// command id: D1
// info: if bond is controlling tank, goto label
//===========================================================================*/
#define bond_in_tank_ID 0xD1
#define bond_in_tank_LENGTH 0x02
#define bond_in_tank(label) \
        bond_in_tank_ID, \
        label,

/*=============================================================================
// name: exit_level
// command id: D2
// info: exits the level
//=============================================================================
// note: recommend not to use this command, instead goto glist exit level for
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
// info: switch back to first person view
//=============================================================================
// note: unused command, never used in retail game. tagged items within inventory
// will become invalid after command - only weapons are safe. command must have
// 3 ai_sleep commands before executing this command or else engine will crash
// on console (use macro camera_wait_for_loading). if camera mode is already in
// third person then you don't need to do the above
//===========================================================================*/
#define camera_return_to_bond_ID 0xD3
#define camera_return_to_bond_LENGTH 0x01
#define camera_return_to_bond \
        camera_return_to_bond_ID,

/*=============================================================================
// name: camera_look_at_bond_from_pad
// command id: D4
// info: change view to pad and look at bond
//=============================================================================
// note: command must have 3 ai_sleep commands before executing this command or
// else engine will crash on console (use macro camera_wait_for_loading).
// if camera mode is already in third person then you don't need to do the above.
//===========================================================================*/
#define camera_look_at_bond_from_pad_ID 0xD4
#define camera_look_at_bond_from_pad_LENGTH 0x03
#define camera_look_at_bond_from_pad(pad) \
        camera_look_at_bond_from_pad_ID, \
        chararray16(pad),

/*=============================================================================
// name: camera_switch
// command id: D5
// info: change view to tagged camera's position and rotation
//=============================================================================
// note: command must have 3 ai_sleep commands before executing this command or
// else engine will crash on console (use macro camera_wait_for_loading).
// if camera mode is already in third person then you don't need to do the above.
// only look at bond if flag is set. unused flag may have separated look at bond
// as x/y flags instead of a single flag - for retail unused flag does nothing
//===========================================================================*/
#define camera_switch_ID 0xD5
#define camera_switch_LENGTH 0x06
#define camera_switch(object_tag, look_at_bond_flag, unused_flag) \
        camera_switch_ID, \
        object_tag, \
        chararray16(look_at_bond_flag), \
        chararray16(unused_flag),

/*=============================================================================
// name: bond_y_pos_less_than
// command id: D6
// info: if bond's y axis position < position argument, goto label
//=============================================================================
// note: checks if bond's y axis is below the provided argument. command uses
// world units. argument is signed and scale is 1:1 to in-game position.
// bond's point of view is accounted for by command (like debug manpos)
//===========================================================================*/
#define bond_y_pos_less_than_ID 0xD6
#define bond_y_pos_less_than_LENGTH 0x04
#define bond_y_pos_less_than(y_pos, label) \
        bond_y_pos_less_than_ID, \
        chararray16(y_pos), \
        label,

/*=============================================================================
// name: hud_hide_and_lock_controls
// command id: D7
// info: hide hud elements and lock player controls
//=============================================================================
// note: argument flag will not hide element on command execution. this is
// needed for dialog or countdown while in cinema mode. flags can be combined
// together to show multiple elements. sequential executions of D7 can be used
// to hide more elements, but once an element has been hidden it cannot be shown
// again until command D8 is executed. bond can take damage while in locked state.
// bitfield (hex):
// 00: hide all
// 01: hide all but top text
// 02: hide all but bottom text
// 04: hide all but hud timer
//===========================================================================*/
#define hud_hide_and_lock_controls_ID 0xD7
#define hud_hide_and_lock_controls_LENGTH 0x02
#define hud_hide_and_lock_controls(hud_hide_flag) \
        hud_hide_and_lock_controls_ID, \
        hide_flag,

/*=============================================================================
// name: hud_show_all
// command id: D8
// info: show all hud elements that have been disabled by D7
//=============================================================================
// note: should only be executed after D7 command, since it may toggle upper/lower
//       text displays
//===========================================================================*/
#define hud_show_all_ID 0xD8
#define hud_show_all_LENGTH 0x01
#define hud_show_all \
        hud_show_all_ID,

/*=============================================================================
// name: chr_move_to_pad
// command id: D9
// info: teleport chr to pad, goto label if successful
//===========================================================================*/
#define chr_move_to_pad_ID 0xD9
#define chr_move_to_pad_LENGTH 0x05
#define chr_move_to_pad(chr_num, pad, label) \
        chr_move_to_pad_ID, \
        chr_num, \
        chrarray16(pad), \
        label,

/*=============================================================================
// name: screen_fade_to_black
// command id: DA
// info: fades the screen out to black
//=============================================================================
// note: fade duration is 1 second
//===========================================================================*/
#define screen_fade_to_black_ID 0xDA
#define screen_fade_to_black_LENGTH 0x01
#define screen_fade_to_black \
        screen_fade_to_black_ID,

/*=============================================================================
// name: screen_fade_from_black
// command id: DB
// info: fades the screen from black
//=============================================================================
// note: fade duration is 1 second
//===========================================================================*/
#define screen_fade_from_black_ID 0xDB
#define screen_fade_from_black_LENGTH 0x01
#define screen_fade_from_black \
        screen_fade_from_black_ID,

/*=============================================================================
// name: screen_fade_completed
// command id: DC
// info: when screen fade has completed (from/to black), goto label
//=============================================================================
// note: fade duration is 1 second
//===========================================================================*/
#define screen_fade_completed_ID 0xDC
#define screen_fade_completed_LENGTH 0x02
#define screen_fade_completed(label) \
        screen_fade_completed_ID, \
        label,

/*=============================================================================
// name: chr_hide_all
// command id: DD
// info: hide all characters in level - including bond's third person model.
//       execute this before switching to exit camera or bond will disappear
//=============================================================================
// note: hidden characters will halt their ai list execution until unhidden
//===========================================================================*/
#define chr_hide_all_ID 0xDD
#define chr_hide_all_LENGTH 0x01
#define chr_hide_all \
        chr_hide_all_ID,

/*=============================================================================
// name: chr_show_all
// command id: DE
// info: show all characters previously hidden by command DD
//===========================================================================*/
#define chr_show_all_ID 0xDE
#define chr_show_all_LENGTH 0x01
#define chr_show_all \
        chr_show_all_ID,

/*=============================================================================
// name: door_open_instant
// command id: DF
// info: instantly open tagged door
//=============================================================================
// note: mostly used for cutscenes, doesn't trigger door opening sfx. open tagged
//       door even if locked
//===========================================================================*/
#define door_open_instant_ID 0xDF
#define door_open_instant_LENGTH 0x02
#define door_open_instant(object_tag) \
        door_open_instant_ID, \
        object_tag,

/*=============================================================================
// name: chr_remove_item_in_hand
// command id: E0
// info: remove the item held by hand index
//=============================================================================
// note: does not drop item, instead clears holding item flag for hand index
//===========================================================================*/
#define chr_remove_item_in_hand_ID 0xE0
#define chr_remove_item_in_hand_LENGTH 0x03
#define chr_remove_item_in_hand(chr_num, hand_index) \
        chr_remove_item_in_hand_ID, \
        chr_num, \
        hand_index,

/*=============================================================================
// name: number_of_active_players_less_than
// command id: E1
// info: if the number of active players < argument, goto label
//=============================================================================
// note: single player always has a total of active players set to 1
//===========================================================================*/
#define number_of_active_players_less_than_ID 0xE1
#define number_of_active_players_less_than_LENGTH 0x03
#define number_of_active_players_less_than(number, label) \
        number_of_active_players_less_than_ID, \
        number, \
        label,

/*=============================================================================
// name: bond_equip_item
// command id: E3
// info: forces bond to equip an item - only works in first person
//=============================================================================
// note: can be used for any item, even if bond doesn't have it in inventory
//===========================================================================*/
#define bond_equip_item_ID 0xE3
#define bond_equip_item_LENGTH 0x02
#define bond_equip_item(item_num) \
        bond_equip_item_ID, \
        item_num,

/*=============================================================================
// name: bond_equip_item_cinema
// command id: E4
// info: forces bond to equip an item - only works in third person (cinema)
//=============================================================================
// note: can be used for any item, even if bond doesn't have it in inventory
//===========================================================================*/
#define bond_equip_item_cinema_ID 0xE4
#define bond_equip_item_cinema_LENGTH 0x02
#define bond_equip_item_cinema(item_num) \
        bond_equip_item_cinema_ID, \
        item_num,

/*=============================================================================
// name: object_in_room_with_pad
// command id: E6
// info: if tagged object in the same room with pad, goto label
//===========================================================================*/
#define object_in_room_with_pad_ID 0xE6
#define object_in_room_with_pad_LENGTH 0x05
#define object_in_room_with_pad(obj_num, pad, label) \
        object_in_room_with_pad_ID, \
        obj_num, \
        chrarray16(pad), \
        label,

/*=============================================================================
// name: guard_is_firing_and_unknown_flag
// command id: E7
// info: if guard is in firing state (ACT_ATTACK) and chr->field_4C | 0x40, goto label
//===========================================================================*/
#define guard_is_firing_and_unknown_flag_ID 0xE7
#define guard_is_firing_and_unknown_flag_LENGTH 0x02
#define guard_is_firing_and_unknown_flag(label) \
        guard_is_firing_and_unknown_flag_ID, \
        label,

/*=============================================================================
// name: guard_is_firing
// command id: E8
// info: if guard is in firing state (ACT_ATTACK), goto label
//===========================================================================*/
#define guard_is_firing_ID 0xE8
#define guard_is_firing_LENGTH 0x02
#define guard_is_firing(label) \
        guard_is_firing_ID, \
        label,

/*=============================================================================
// name: gas_leak_and_switch_fog
// command id: E9
// info: trigger gas leak event and instantly switch fog to the next fog's slot
//=============================================================================
// note: this command triggers a gas leak. for the level egypt, this command
// will not trigger a gas leak, but instead will only switch the fog. this
// command can't be stopped after executing. level must have a fog assigned
// or will crash!
//===========================================================================*/
#define gas_leak_and_switch_fog_ID 0xE9
#define gas_leak_and_switch_fog_LENGTH 0x01
#define gas_leak_and_switch_fog \
        gas_leak_and_switch_fog_ID,

/*=============================================================================
// name: mission_time_stop_and_exit_level_on_button_input
// command id: EA
// info: stop the mission time and exit level if player 1 pressed any buttons
//===========================================================================*/
#define mission_time_stop_and_exit_level_on_button_input_ID 0xEA
#define mission_time_stop_and_exit_level_on_button_input_LENGTH 0x01
#define mission_time_stop_and_exit_level_on_button_input \
        mission_time_stop_and_exit_level_on_button_input_ID,

/*=============================================================================
// name: bond_is_dead
// command id: EB
// info: if bond has died/been killed, goto label
//===========================================================================*/
#define bond_is_dead_ID 0xEB
#define bond_is_dead_LENGTH 0x02
#define bond_is_dead(label) \
        bond_is_dead_ID, \
        label,

/*=============================================================================
// name: bond_disable_damage_and_pickups
// command id: EC
// info: disables bond damage and ability to pick up items
//=============================================================================
// note: commonly used for level exit ai lists - prevents bond dying after
//       triggering exit cutscene. use command F3 to check if flag is set on
//===========================================================================*/
#define bond_disable_damage_and_pickups_ID 0xEC
#define bond_disable_damage_and_pickups_LENGTH 0x01
#define bond_disable_damage_and_pickups \
        bond_disable_damage_and_pickups_ID,

/*=============================================================================
// name: bond_hide_weapons
// command id: ED
// info: set bond's left/right weapons to be invisible
//===========================================================================*/
#define bond_hide_weapons_ID 0xED
#define bond_hide_weapons_LENGTH 0x01
#define bond_hide_weapons \
        bond_hide_weapons_ID,

/*=============================================================================
// name: camera_orbit_pad
// command id: EE
// info: change view to orbit a pad with set speed
//=============================================================================
// note: command must have 3 ai_sleep commands before executing this command or
// else engine will crash on console (use macro camera_wait_for_loading). if camera
// mode is already in third person then you don't need to do the above.
// arguments:
// lat_distance: camera distance from pad, 100 units per meter. argument is unsigned
// vert_distance: camera distance from pad, 100 units per meter. argument is signed
// orbit_speed: speed to orbit around pad, argument is signed. unit format uses
//              compass direction like target commands (14-17). generally stick
//              to a low range as it is used for delta timing (0100-FF00)
// pad: pad for camera to target and orbit around
// y_pos_offset: offset the relative y position for pad (boom/jib), argument is signed
// initial_rotation: uses compass direction like target commands (14-17)
//                   but inverted - hex N: 0000 E: C000 S: 8000: W: 4000
//===========================================================================*/
#define camera_orbit_pad_ID 0xEE
#define camera_orbit_pad_LENGTH 0x0D
#define camera_orbit_pad(lat_distance, vert_distance, orbit_speed, pad, y_pos_offset, initial_rotation) \
        camera_orbit_pad_ID, \
        chararray16(lat_distance), \
        chararray16(vert_distance), \
        chararray16(orbit_speed), \
        chararray16(pad), \
        chararray16(y_pos_offset), \
        chararray16(initial_rotation),

/*=============================================================================
// name: credits_roll
// command id: EF
// info: trigger credits crawl
//=============================================================================
// note: credits text and positions are stored in setup intro struct
//===========================================================================*/
#define credits_roll_ID 0xEF
#define credits_roll_LENGTH 0x01
#define credits_roll \
        credits_roll_ID,

/*=============================================================================
// name: credits_completed
// command id: F0
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
// info: if all objectives for current difficulty has been completed, goto label
//=============================================================================
// note: uses objective difficulty settings within setup, briefing file settings
//       are not referenced. ensure both setup and briefing files are consistent
//===========================================================================*/
#define objective_all_completed_ID 0xF1
#define objective_all_completed_LENGTH 0x02
#define objective_all_completed(label) \
        objective_all_completed_ID, \
        label,

/*=============================================================================
// name: bond_check_folder_actor
// command id: F2
// info: if current bond equal to folder actor index, goto label
//=============================================================================
// note: in retail release only index 0 works. originally this would have checked
// which bond (brosnan/connery/moore/dalton) is currently used, with each briefing
// folder using a different bond likeness in-game. however rare didn't have the
// license to use the other actor's faces so this feature was removed.
// command is only used for cuba (credits)
//===========================================================================*/
#define bond_check_folder_actor_ID 0xF2
#define bond_check_folder_actor_LENGTH 0x03
#define bond_check_folder_actor(bond_actor_index, label) \
        bond_check_folder_actor_ID, \
        bond_actor_index, \
        label,

/*=============================================================================
// name: bond_if_damage_and_pickups_disabled
// command id: F3
// info: if bond damage and ability to pick up items disabled, goto label
//=============================================================================
// note: used to check when bond has exited level, usually to stop guards from
//       spawning during mission cinema. use command EC to set state on
//===========================================================================*/
#define bond_if_damage_and_pickups_disabled_ID 0xF3
#define bond_if_damage_and_pickups_disabled_LENGTH 0x02
#define bond_if_damage_and_pickups_disabled(label) \
        bond_if_damage_and_pickups_disabled_ID, \
        label,

/*=============================================================================
// name: trigger_explosions_around_bond
// command id: F6
// info: triggers explosions around the player, will continue forever
//=============================================================================
// note: does not trigger level exit or killed in action state
//===========================================================================*/
#define trigger_explosions_around_bond_ID 0xF6
#define trigger_explosions_around_bond_LENGTH 0x01
#define trigger_explosions_around_bond \
        trigger_explosions_around_bond_ID,

/*=============================================================================
// name: bond_killed_civilians_greater_than
// command id: F7
// info: if bond's total civilians killed > argument, goto label
//=============================================================================
// note: guards flagged with CHRFLAG_COUNT_DEATH_AS_CIVILIAN will count towards
//       total when killed. usually set for scientists/civilians/innocent NPCs
//===========================================================================*/
#define bond_killed_civilians_greater_than_ID 0xF7
#define bond_killed_civilians_greater_than_LENGTH 0x03
#define bond_killed_civilians_greater_than(civilians_killed, label) \
        bond_killed_civilians_greater_than_ID, \
        civilians_killed, \
        label,

/*=============================================================================
// name: chr_was_shot_since_last_check
// command id: F8
// info: if chr was shot, goto label
//=============================================================================
// note: checks chr->chrflags if CHRFLAG_WAS_HIT is set. if true, unset flag and
//       goto label. CHRFLAG_WAS_HIT is set even if guard is invincible
//===========================================================================*/
#define chr_was_shot_since_last_check_ID 0xF8
#define chr_was_shot_since_last_check_LENGTH 0x03
#define chr_was_shot_since_last_check(chr_num, label) \
        chr_was_shot_since_last_check_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: bond_killed_in_action
// command id: F9
// info: sets briefing status to killed in action, automatic mission failure
//=============================================================================
// note: does not kill the player, only changes the mission status
//===========================================================================*/
#define bond_killed_in_action_ID 0xF9
#define bond_killed_in_action_LENGTH 0x01
#define bond_killed_in_action \
        bond_killed_in_action_ID,

/*=============================================================================
// name: guard_raises_arms
// command id: FA
// info: makes guard raise their arms for half a second
//===========================================================================*/
#define guard_raises_arms_ID 0xFA
#define guard_raises_arms_LENGTH 0x01
#define guard_raises_arms \
        guard_raises_arms_ID,

/*=============================================================================
// name: gas_leak_and_fade_fog
// command id: FB
// info: trigger gas leak event and slowly transition fog to the next fog's slot
//=============================================================================
// note: this command triggers a gas leak. for the level egypt, this command
// will not trigger a gas leak, but instead will only transition the fog.
// this command can't be stopped after executing. level must have a fog assigned
// or will crash!
//===========================================================================*/
#define gas_leak_and_fade_fog_ID 0xFB
#define gas_leak_and_fade_fog_LENGTH 0x01
#define gas_leak_and_fade_fog \
        gas_leak_and_fade_fog_ID,

/*=============================================================================
// name: object_rocket_launch
// command id: FC
// info: launch a tagged object like a rocket
//=============================================================================
// note: if tagged object can't be turned upright, object will be destroyed instead
//===========================================================================*/
#define object_rocket_launch_ID 0xFC
#define object_rocket_launch_LENGTH 0x02
#define object_rocket_launch(object_tag) \
        object_rocket_launch_ID, \
        object_tag,

#endif
