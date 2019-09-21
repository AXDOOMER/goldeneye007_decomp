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
// be from both obj and chr ai lists exceptions to the rule are detailed in the
// command descriptions
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
// note: chr ai lists (04XX) that are idle/off screen will sleep for multiple
//       ticks instead of one tick
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
// name: chr_in_room_with_pad
// command id: 54
//=============================================================================
// info: if chr id in same room with pad, goto label
//===========================================================================*/
#define chr_in_room_with_pad_ID 0x54
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
#define bond_in_room_with_pad(pad, label) \
        bond_in_room_with_pad_ID, \
        chararray16(pad), \
        label,

#endif
