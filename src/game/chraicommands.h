#ifndef _CHRAICOMMANDS_H_
#define _CHRAICOMMANDS_H_
#include "ultra64.h"

/*=============================================================================
// chr ai commands reference
// programmed by mark edmonds and martin hollis
//=============================================================================
// terminology:
// list             list of ai commands - list must end with 04 command
// chr              character
// obj              objective
// glist            global list
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
// lists (chr/obj) are unique to each level setup file, compared to global lists
// which are accessible throughout the entire game. they contain generic ai lists
// used for most levels
//=============================================================================
// command note
//=============================================================================
// commands with guard prefix are exclusive to chr ai lists, they can't be
// executed by obj ai lists (10XX) or it will crash! commands with chr prefix can
// be used by obj/chr ai lists - exceptions to this rule are detailed within
// the command description
//===========================================================================*/

#define chararray16(input) (input & 0xFF00) >> 8, input & 0x00FF
#define chararray24(input) (input & 0xFF0000) >> 16, (input & 0x00FF00) >> 8, input & 0x0000FF
#define chararray32(input) (input & 0xFF000000) >> 24, (input & 0x00FF0000) >> 16, (input & 0x0000FF00) >> 8, input & 0x000000FF

#define CHR_BOND -8
#define CHR_CLONE -7
#define CHR_SEE_SHOT -6 /* stored as chr->chrseeshot */
#define CHR_SEE_DIE -5 /* stored as chr->chrseedie */
#define CHR_PRESET -4 /* stored as chr->chrpreset1 */
#define CHR_SELF -3

#define PAD_PRESET 9000 /* stored as chr->padpreset1 */

#define AI_LIST_GLOBAL_START 0x0000
#define AI_LIST_CHR_START 0x0401
#define AI_LIST_OBJ_START 0x1000

/*=============================================================================
// global ai lists - glists
//===========================================================================*/
#define GLIST_AIM_AT_BOND                              0x0000 // continuously aim at bond with weapon
#define GLIST_END_ROUTINE                              0x0001 // end routine (loop forever)
#define GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE 0x0002 // wait for bond detection - spawn clone on heard gunfire
#define GLIST_IDLE_RAND_ANIM_SUBROUTINE                0x0003 // play a random idle animation (subroutine)
#define GLIST_KEYBOARD_RAND_ANIM_SUBROUTINE            0x0004 // play a random use keyboard animation (subroutine)
#define GLIST_DETECT_BOND_DEAF_NO_CLONE_NO_IDLE_ANIM   0x0005 // wait for bond detection - ignore gunfire and don't play idle animations
#define GLIST_FIRE_RAND_ANIM_SUBROUTINE                0x0006 // fire at bond with random animation (subroutine)
#define GLIST_DETECT_BOND_NO_CLONE_NO_IDLE_ANIM        0x0007 // wait for bond detection - don't spawn clone and don't play idle animations
#define GLIST_RUN_TO_BOND_SUBROUTINE                   0x0008 // run to bond (subroutine)
#define GLIST_RUN_TO_CHR_PADPRESET_AND_ACTIVATE_ALARM  0x0009 // run to chr->padpreset1 and activate alarm
#define GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE   0x000A // startle character (subroutine)
#define GLIST_SPAWN_CLONE_OR_RUN_TO_BOND               0x000B // if chr has been seen, run to bond - else spawn clone
#define GLIST_RUN_TO_BOND_AND_FIRE                     0x000C // run to bond and fire
#define GLIST_RUN_TO_BOND_AND_FIRE_RANDOMLY_HALT_CHR   0x000D // run to bond and fire (randomly halt - never gives up chasing bond)
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
#define TARGET_CHR          0x0004
#define TARGET_PAD          0x0008
#define TARGET_AIM_ONLY     0x0020

// command 18-19 target body part values
#define TARGET_NULL_PART        0x0 // null part, no reaction - 1x damage
#define TARGET_LEFT_FOOT        0x1 // left foot - 1x damage
#define TARGET_LEFT_LEG         0x2 // left leg - 1x damage
#define TARGET_LEFT_THIGH       0x3 // left thigh - 1x damage
#define TARGET_RIGHT_FOOT       0x4 // right foot - 1x damage
#define TARGET_RIGHT_LEG        0x5 // right leg - 1x damage
#define TARGET_RIGHT_THIGH      0x6 // right thigh - 1x damage
#define TARGET_PELVIS           0x7 // pelvis - 1x damage
#define TARGET_HEAD             0x8 // head - 4x damage
#define TARGET_LEFT_HAND        0x9 // left hand - 1x damage
#define TARGET_LEFT_ARM         0xA // left arm - 1x damage
#define TARGET_LEFT_SHOULDER    0xB // left shoulder - 1x damage
#define TARGET_RIGHT_HAND       0xC // right hand - 1x damage
#define TARGET_RIGHT_ARM        0xD // right arm - 1x damage
#define TARGET_RIGHT_SHOULDER   0xE // right shoulder - 1x damage
#define TARGET_CHEST            0xF // chest - 2x damage

// command 94-99 chr->bitfield - used for ai list GLIST_FIRE_RAND_ANIM_SUBROUTINE
#define BITFIELD_DONT_POINT_AT_BOND     0x01 // if enabled, don't point at bond

// command 9D-A2 (incomplete)
#define CHRFLAG_SUNGLASSES              0x00000002 // sunglasses
#define CHRFLAG_INVINCIBLE              0x00000010 // invincible
#define CHRFLAG_CAN_SHOOT_CHRS          0x00000040 // can shoot other guards
#define CHRFLAG_HIDDEN                  0x00000400 // hidden
#define CHRFLAG_NO_AUTOAIM              0x00000800 // no autoaim
#define CHRFLAG_LOCK_Y_POS              0x00001000 // lock y position (no gravity, used for dam/cradle jump)
#define CHRFLAG_NO_SHADOW               0x00002000 // no shadow
#define CHRFLAG_IGNORE_ANIM_TRANSLATION 0x00004000 // ignore animation translation
#define CHRFLAG_INCREASE_SPRINT_SPEED   0x00080000 // increase sprinting speed

/*=============================================================================
// ai commands macros and information
//=============================================================================
// name and description per command, please read carefully when creating new
// commands. ensure that you don't cause loops without a sleep command or else
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
// name: sleep
// id number: 03
// info: halt the ai list - frees engine to start executing next ai list until
//       all lists have been executed for game tick.
//=============================================================================
// note: offscreen/idle guards will take 14 game ticks instead of 1 tick on sleep
//===========================================================================*/
#define sleep_ID 0x03
#define sleep_LENGTH 0x01
#define sleep \
        sleep_ID,

/*=============================================================================
// name: ai_list_end
// command id: 04
// info: used for ai list parser to check when list ends
//=============================================================================
// note: not recommended to execute this command - to finish a list create an
// infinite loop (commands 02/03/01) or jump to glist end routine when list has
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
// info: store a list ptr in current chr struct - used for command 07 return
//=============================================================================
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
#define guard_reset_pose_ID 0x08
#define guard_reset_pose_LENGTH 0x01
#define guard_reset_pose \
        guard_reset_pose_ID,

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
// note: can't be used for bond - command does not trigger item's fire sfx.
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
// note: can't be used for bond - command does not trigger item's fire sfx or
// chr firing animation. item's damage uses body part damage modifier
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
// info: trigger guard to throw a grenade at player, goto label if successful
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
//=============================================================================
// note: can't be used for bond - use command EB instead
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
// note: can't be used for bond - use command EB instead. this command is used
// to check if chr has finished dying animation and faded away, or chr num is free
//===========================================================================*/
#define chr_does_not_exist_ID 0x31
#define chr_does_not_exist_LENGTH 0x03
#define chr_does_not_exist(chr_num, label) \
        chr_does_not_exist_ID, \
        chr_num, \
        label,

/*=============================================================================
// name: guard_check_vision_for_bond
// command id: 32
// info: check vision for bond, goto label if spotted bond
//=============================================================================
// note: uses chr->visionrange while checking for bond. once bond has been spotted,
// check if bond and guard are within line of sight (ignores facing direction).
// if bond breaks line of sight, do not goto label. if bond has broken line of
// sight for more than 10 seconds, reset spotted bond state
//===========================================================================*/
#define guard_check_vision_for_bond_ID 0x32
#define guard_check_vision_for_bond_LENGTH 0x02
#define guard_check_vision_for_bond(label) \
        guard_check_vision_for_bond_ID, \
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
// name: alarm_is_on_unused
// command id: 36
// info: if alarm is activated, goto label
//=============================================================================
// note: this command works but is unused in retail game, use command 37 instead
//===========================================================================*/
#define alarm_is_on_unused_ID 0x36
#define alarm_is_on_unused_LENGTH 0x02
#define alarm_is_on_unused(label) \
        alarm_is_on_unused_ID, \
        label,

/*=============================================================================
// name: alarm_is_on
// command id: 37
// info: if alarm is activated, goto label
//===========================================================================*/
#define alarm_is_on_ID 0x37
#define alarm_is_on_LENGTH 0x02
#define alarm_is_on(label) \
        alarm_is_on_ID, \
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
// name: guard_and_bond_within_line_of_sight
// command id: 3C
// info: if guard and bond are within line of sight, goto label
//=============================================================================
// note: line of sight uses clipping - ignores facing direction of bond/guard.
// does not use chr->visionrange for line of sight check. use command 32 to check
// using chr->visionrange and command 42 to account for bond's view
//===========================================================================*/
#define guard_and_bond_within_line_of_sight_ID 0x3C
#define guard_and_bond_within_line_of_sight_LENGTH 0x02
#define guard_and_bond_within_line_of_sight(label) \
        guard_and_bond_within_line_of_sight_ID, \
        label,

/*=============================================================================
// name: guard_was_shot_recently
// command id: 3E
// info: if guard was shot within the last 10 seconds, goto label
//=============================================================================
// note: guard friendly fire will trigger this command to goto label
//===========================================================================*/
#define guard_was_shot_recently_ID 0x3E
#define guard_was_shot_recently_LENGTH 0x02
#define guard_was_shot_recently(label) \
        guard_was_shot_recently_ID, \
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
// note: command will sometimes goto label if guard was shot - use sub-action
// 3E instead to check if guard was shot recently (more consistent checking).
//===========================================================================*/
#define guard_shot_from_bond_missed_ID 0x46
#define guard_shot_from_bond_missed_LENGTH 0x02
#define guard_shot_from_bond_missed(label) \
        guard_shot_from_bond_missed_ID, \
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
// name: chr_drop_all_concealed_items
// command id: 61
// info: make chr drop all concealed attachments
//=============================================================================
// note: item must be attached to chr in setup. embedded objects will not drop,
// only works with attached objects. props can be damaged on drop. command can't
// be used for bond
//===========================================================================*/
#define chr_drop_all_concealed_items_ID 0x61
#define chr_drop_all_concealed_items_LENGTH 0x02
#define chr_drop_all_concealed_items(chr_num) \
        chr_drop_all_concealed_items_ID, \
        chr_num,

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
// name: guard_set_hearing_scale
// command id: 8B
// info: set guard's hearing scale - the higher the value, the further away guard
//       can hear gunfire
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
// argument is unsigned - 0xFFFF will be set to 65535.f armour, or -65535.f damage
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
#define guard_bitfield_set_on(bits) \
        guard_bitfield_set_on_ID, \
        bits,

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
#define guard_bitfield_set_off(bits) \
        guard_bitfield_set_off_ID, \
        bits,

/*=============================================================================
// name: guard_bitfield_is_on
// command id: 96
// info: if bits is set on in chr->BITFIELD, goto label
//===========================================================================*/
#define guard_bitfield_is_on_ID 0x96
#define guard_bitfield_is_on_LENGTH 0x03
#define guard_bitfield_is_on(bits, label) \
        guard_bitfield_is_on_ID, \
        bits, \
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
#define chr_bitfield_set_on(chr_num, bits) \
        chr_bitfield_set_on_ID, \
        chr_num, \
        bits,

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
#define chr_bitfield_set_off(chr_num, bits) \
        chr_bitfield_set_off_ID, \
        chr_num, \
        bits,

/*=============================================================================
// name: chr_bitfield_is_on
// command id: 99
// info: if bits is set on in chr->BITFIELD, goto label
//===========================================================================*/
#define chr_bitfield_is_on_ID 0x99
#define chr_bitfield_is_on_LENGTH 0x04
#define chr_bitfield_is_on(chr_num, bits, label) \
        chr_bitfield_is_on_ID, \
        chr_num, \
        bits, \
        label,

/*=============================================================================
// name: guard_set_flags
// command id: 9D
// info: set chr->chrflags
//=============================================================================
// note: 
//===========================================================================*/
#define guard_set_flags_ID 0x9D
#define guard_set_flags_LENGTH 0x05
#define guard_set_flags(accuracy_rating) \
        guard_set_flags_ID, \
        accuracy_rating,

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
// name: bond_in_tank
// command id: D1
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
// info: switch back to first person view. must have 3 sleep commands before
//       executing this command
//=============================================================================
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
// info: show all hud elements that have been disabled by D7
//=============================================================================
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
#define screen_fade_if_complete_ID 0xDC
#define screen_fade_if_complete_LENGTH 0x02
#define screen_fade_if_complete(label) \
        screen_fade_if_complete_ID, \
        label,

/*=============================================================================
// name: chr_hide_all
// command id: DD
// info: hide all characters in level - including bond. execute this before
//       switching to exit camera or bond will disappear
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
#define gas_leak_and_switch_fog_fog_ID 0xE9
#define gas_leak_and_switch_fog_fog_LENGTH 0x01
#define gas_leak_and_switch_fog_fog \
        gas_leak_and_switch_fog_fog_ID,

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
// name: bond_has_died
// command id: EB
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
// info: disables bond damage and ability to pick up items
//=============================================================================
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
// info: set bond's left/right weapons to be invisible
//===========================================================================*/
#define bond_hide_weapons_ID 0xED
#define bond_hide_weapons_LENGTH 0x01
#define bond_hide_weapons \
        bond_hide_weapons_ID,

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
// macros and other common shortcut commands
//===========================================================================*/
#define goto_loop_start(label_id) \
        label(label_id) \
        sleep

#define goto_loop_repeat(label) \
        goto_first(label)

#define goto_loop_infinite(label_id) \
        label(label_id) \
        sleep \
        goto_first(label_id)

#define transition_to_camera \
        sleep \
        sleep \
        sleep
#endif
