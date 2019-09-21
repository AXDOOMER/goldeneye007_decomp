#ifndef _CHRAICOMMANDS_H_
#define _CHRAICOMMANDS_H_
#include "ultra64.h"

// note: commands prefixed with guard are exclusive to guard ai lists,
// they can't be executed by global ai lists (10XX) or it will crash!!

#define chararray16(input) (input & 0xFF00) >> 8, input & 0x00FF
#define chararray32(input) (input & 0xFF000000) >> 24, (input & 0x00FF0000) >> 16, (input & 0x0000FF00) >> 8, input & 0x000000FF

#define CHRAI_ID_PLAYER -8
#define CHRAI_ID_CLONE -7
#define CHRAI_ID_SEE_SHOT -6
#define CHRAI_ID_SEE_DIE -5
#define CHRAI_ID_PRESET -4
#define CHRAI_ID_SELF -3

//=============================================================================
// name: goto_next
// command id: 00
//=============================================================================
// description: goto the next label (command 02) - skips all commands between
//             command and goto label - continues executing after found label
//=============================================================================
#define goto_next_ID 0x00
#define goto_next_LENGTH 0x02
#define goto_next(label) \
        goto_next_ID, \
        label,

//=============================================================================
// name: goto_first
// command id: 01
//=============================================================================
// description: like goto_next, but it starts scanning label from start of list
//=============================================================================
#define goto_first_ID 0x01
#define goto_first_LENGTH 0x02
#define goto_first(label) \
        goto_first_ID, \
        label,

//=============================================================================
// name: label
// command id: 02
//=============================================================================
// description: label marker for ai list - used for all commands that return
//              true (ie goto next label)
//=============================================================================
#define label_ID 0x02
#define label_LENGTH 0x02
#define label(id) \
        label_ID, \
        id,

//=============================================================================
// name: sleep
// id number: 03
//=============================================================================
// description: pauses the current ai list so engine can continue executing next
//    ai list (until all have been executed, in which game continues), continues
//    executing on next game tick
// notes: guard ai lists (04XX lists) that are idle/off screen will sleep for
//        multiple frames instead of one tick
//=============================================================================
#define sleep_ID 0x03
#define sleep_LENGTH 0x01
#define sleep \
        sleep_ID,

//=============================================================================
// name: ai_list_end
// command id: 04
//=============================================================================
// description: used for ai list parser to check when list ends
// notes: not recommended to execute this command - always exec an infinite
// loop (cmds 02/03/01) or jump to built in list #0001 when list is completed
//=============================================================================
#define ai_list_end_ID 0x04
#define ai_list_end_LENGTH 0x01
#define ai_list_end \
        ai_list_end_ID

//=============================================================================
// name: goto_ai_list
// command id: 05
//=============================================================================
// description: goto another ai list and start executing from beginning
// notes: cannot jump to global ai lists (10XX)
//=============================================================================
#define goto_ai_list_ID 0x05
#define goto_ai_list_LENGTH 0x04
#define goto_ai_list(ai_id, ai_list) \
        goto_ai_list_ID, \
        ai_id, \
        chararray16(ai_list),

//=============================================================================
// name: set_return_ai_list
// command id: 06
//=============================================================================
// description: store an ai list in chr struct - used for command 07 return
// notes: cannot be set to global ai lists (10XX)
//=============================================================================
#define set_return_ai_list_ID 0x06
#define set_return_ai_list_LENGTH 0x03
#define set_return_ai_list(ai_list) \
        set_return_ai_list_ID, \
        chararray16(ai_list),

//=============================================================================
// name: goto_return_ai_list
// command id: 07
//=============================================================================
// description: goto the return list stored in chr struct
//=============================================================================
#define goto_return_ai_list_ID 0x07
#define goto_return_ai_list_LENGTH 0x01
#define goto_return_ai_list \
        goto_return_ai_list_ID,

//=============================================================================
// name: guard_reset_pose
// command id: 08
//=============================================================================
// description: resets the chr animation state back to idle pose
// notes: not compatible with global ai lists (10XX)
//=============================================================================
#define guard_reset_pose_ID 0x08
#define guard_reset_pose_LENGTH 0x01
#define guard_reset_pose \
        guard_reset_pose_ID,

//=============================================================================
// name: guard_kneel
// command id: 09
//=============================================================================
// description: make guard kneel on one knee
// notes: not compatible with global ai lists (10XX)
//=============================================================================
#define guard_kneel_ID 0x09
#define guard_kneel_LENGTH 0x01
#define guard_kneel \
        guard_kneel_ID,

//=============================================================================
// name: guard_animation
// command id: 0A
//=============================================================================
// description: set chr to playback animation
// notes: not compatible with global ai lists (10XX)
//=============================================================================
// arguments:
// start/end set to -1/-1 will playback the entire animation length
// tween time will set how long it will take to transition from the previous state
// (if this value is too low it may crash!)
// bitfield:
// 01 - mirror animation
// 02 - ?? (cancels no translation flag)
// 04 - loop/hold last frame (required for reverse flag)
// 08 - play sneeze sfx with animation 9F (triggers 50% of the time)
// 10 - default pose after animation has completed (does not work with looping animations)
// 20 - translation multiplier x 4 (used for dam and cradle cinema)
// 40 - no translation
// 80 - reverse animation (only for looped animations)
//=============================================================================
#define guard_animation_ID 0x0A
#define guard_animation_LENGTH 0x09
#define guard_animation(animation_id, start_timer60, end_timer60, bitfield, tween_timer60) \
        guard_animation_ID, \
        chararray16(animation_id), \
        chararray16(start_timer60), \
        chararray16(end_timer60), \
        bitfield, \
        tween_timer60,

//=============================================================================
// name: guard_in_room_with_pad
// command id: 54
//=============================================================================
// description: if guard ID in same room with pad, goto label
//=============================================================================
#define guard_id_in_room_with_pad_ID 0x54
#define guard_id_in_room_with_pad(guard_id, pad, label) \
        guard_id_in_room_with_pad_ID, \
        guard_id, \
        chararray16(pad), \
        label,

//=============================================================================
// name: bond_in_room_with_pad
// command id: 55
//=============================================================================
// description: if bond in same room with pad, goto label
//=============================================================================
#define bond_in_room_with_pad_ID 0x55
#define bond_in_room_with_pad(pad, label) \
        bond_in_room_with_pad_ID, \
        chararray16(pad), \
        label,

#endif
