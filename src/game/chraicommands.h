#ifndef _CHRAICOMMANDS_H_
#define _CHRAICOMMANDS_H_
#include "ultra64.h"

#define chararray16(input) (input & 0xFF00) >> 8, input & 0xFF
#define chararray32(input) (input & 0xFF000000) >> 24, (input & 0x00FF0000) >> 16, (input & 0x0000FF00) >> 8, input & 0x000000FF

#define CHRAI_ID_PLAYER -8
#define CHRAI_ID_CLONE -7
#define CHRAI_ID_SEE_SHOT -6
#define CHRAI_ID_SEE_DIE -5
#define CHRAI_ID_PRESET -4
#define CHRAI_ID_SELF -3

/* command: goto_next */
/* id number: 00 */
/* description: jumps to next label (command 02) - skips all commands between jump and continues executing when found label */
#define goto_next_ID 0x00
#define goto_next(label) \
        goto_next_ID, \
        label,

/* command: goto_first */
/* id number: 01 */
/* description: like goto_next, but instead it starts from the top */
#define goto_first_ID 0x01
#define goto_first(label) \
        goto_first_ID, \
        label,

/* command: label */
/* id number: 02 */
/* description: label marker for ai list - used for all commands that return true (ie jump to next label) */
#define label_ID 0x02
#define label(id) \
        label_ID, \
        id,

/* command: sleep */
/* id number: 03 */
/* description: pauses the current ai list so engine can continue executing next ai list (until all have been executed, in which game continues), continues executing on next game tick */
/* notes: guard ai lists (04XX lists) that are idle/off screen will sleep for multiple frames instead of one tick */
#define sleep_ID 0x03
#define sleep \
        sleep_ID,

/* command: ai_list_end */
/* id number: 04 */
/* description: used for ai list parser to check when list ends */
/* notes: it's not recommended to ever hit this command - always do a infinite loop (02/03/01) or jump to built in list #0001 */
#define ai_list_end_ID 0x04
#define ai_list_end \
        ai_list_end_ID,

/* command: goto_ai_list */
/* id number: 05 */
/* description: jump to another ai list and continue executing from top */
/* notes: cannot jump to global ai lists (10XX) */
#define goto_ai_list_ID 0x05
#define goto_ai_list(ai_id, list) \
        goto_ai_list_ID, \
        ai_id, \
        chararray16(list),

/* command: guard_in_room_with_pad */
/* id number: 54 */
/* description: if guard ID in same room with pad, goto label */
#define guard_id_in_room_with_pad_ID 0x54
#define guard_id_in_room_with_pad(guard_id, pad, label) \
        guard_id_in_room_with_pad_ID, \
        guard_id, \
        chararray16(pad), \
        label,

/* command: bond_in_room_with_pad */
/* id number: 55 */
/* description: if bond in same room with pad, goto label */
#define bond_in_room_with_pad_ID 0x55
#define bond_in_room_with_pad(pad, label) \
        bond_in_room_with_pad_ID, \
        chararray16(pad), \
        label,

#endif
