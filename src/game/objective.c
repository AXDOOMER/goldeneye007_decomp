#include <ultra64.h>
#include <boss.h>
#include "objective.h"
#include "objective_status.h"



/*
 * Clears Objectives and states.
 *
 * NTSC address 0x7F004EC0.
 */
void something_with_stage_objectives(void)
{
    s32 i;

    OBJECTIVESTATUS *start;
    OBJECTIVESTATUS *end;

    if (bossGetStageNum() != LEVELID_TITLE)
    {
        objective_count = -1;

        for (i = 0; i < OBJECTIVES_MAX; i++)
        {
            objectiveStatuses[i] = OBJECTIVESTATUS_INCOMPLETE;
        }
    }

#if defined(VERSION_JP) || defined(VERSION_EU)
    objective_count_related = 0;
#endif

    for (i = 0; i < OBJECTIVES_MAX; i++)
    {
        objective_ptrs[i] = NULL;
    }
    
    ptr_last_tag_entry_type16 = NULL;
    ptr_last_briefing_setup_entry_type23 = NULL;
    ptr_last_enter_room_subobject_entry_type20 = NULL;
    ptr_last_deposit_in_room_subobject_entry_type21 = NULL;
    ptr_last_photo_obj_in_room_subobject_entry_type1E = NULL;
}

void set_parent_cur_tag_entry(struct TagObjectRecord *arg0)
{
    arg0->NextTag = ptr_last_tag_entry_type16;
    ptr_last_tag_entry_type16 = arg0;
}



#ifdef NONMATCHING
void *setup_briefing_text_entry_parent(void *arg0) {
    // Node 0
    arg0->unkC = (void *) ptr_last_briefing_setup_entry_type23;
    ptr_last_briefing_setup_entry_type23 = arg0;
    return;
    // (possible return value: &ptr_last_briefing_setup_entry_type23)
}

#else
GLOBAL_ASM(
.text
glabel setup_briefing_text_entry_parent
/* 039AD0 7F004FA0 3C028007 */  lui   $v0, %hi(ptr_last_briefing_setup_entry_type23)
/* 039AD4 7F004FA4 24425D84 */  addiu $v0, %lo(ptr_last_briefing_setup_entry_type23) # addiu $v0, $v0, 0x5d84
/* 039AD8 7F004FA8 8C4E0000 */  lw    $t6, ($v0)
/* 039ADC 7F004FAC AC8E000C */  sw    $t6, 0xc($a0)
/* 039AE0 7F004FB0 03E00008 */  jr    $ra
/* 039AE4 7F004FB4 AC440000 */   sw    $a0, ($v0)
)
#endif


void add_ptr_to_objective(struct objective_entry* objective)
{
    objective_ptrs[objective->menu] = objective;

    if (objective_count < objective->menu)
    {
        objective_count = objective->menu;
    }
}


#ifdef NONMATCHING
void *set_parent_cur_obj_enter_room(void *arg0) {
    // Node 0
    arg0->unkC = (void *) ptr_last_enter_room_subobject_entry_type20;
    ptr_last_enter_room_subobject_entry_type20 = arg0;
    return;
    // (possible return value: &ptr_last_enter_room_subobject_entry_type20)
}

#else
GLOBAL_ASM(
.text
glabel set_parent_cur_obj_enter_room
/* 039B24 7F004FF4 3C028007 */  lui   $v0, %hi(ptr_last_enter_room_subobject_entry_type20)
/* 039B28 7F004FF8 24425D88 */  addiu $v0, %lo(ptr_last_enter_room_subobject_entry_type20) # addiu $v0, $v0, 0x5d88
/* 039B2C 7F004FFC 8C4E0000 */  lw    $t6, ($v0)
/* 039B30 7F005000 AC8E000C */  sw    $t6, 0xc($a0)
/* 039B34 7F005004 03E00008 */  jr    $ra
/* 039B38 7F005008 AC440000 */   sw    $a0, ($v0)
)
#endif


#ifdef NONMATCHING
void *set_parent_cur_obj_deposited_in_room(void *arg0) {
    // Node 0
    arg0->unk10 = (void *) ptr_last_deposit_in_room_subobject_entry_type21;
    ptr_last_deposit_in_room_subobject_entry_type21 = arg0;
    return;
    // (possible return value: &ptr_last_deposit_in_room_subobject_entry_type21)
}

#else
GLOBAL_ASM(
.text
glabel set_parent_cur_obj_deposited_in_room
/* 039B3C 7F00500C 3C028007 */  lui   $v0, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
/* 039B40 7F005010 24425D8C */  addiu $v0, %lo(ptr_last_deposit_in_room_subobject_entry_type21) # addiu $v0, $v0, 0x5d8c
/* 039B44 7F005014 8C4E0000 */  lw    $t6, ($v0)
/* 039B48 7F005018 AC8E0010 */  sw    $t6, 0x10($a0)
/* 039B4C 7F00501C 03E00008 */  jr    $ra
/* 039B50 7F005020 AC440000 */   sw    $a0, ($v0)
)
#endif


#ifdef NONMATCHING
void *set_parent_cur_obj_photograph(void *arg0) {
    // Node 0
    arg0->unkC = (void *) ptr_last_photo_obj_in_room_subobject_entry_type1E;
    ptr_last_photo_obj_in_room_subobject_entry_type1E = arg0;
    return;
    // (possible return value: &ptr_last_photo_obj_in_room_subobject_entry_type1E)
}

#else
GLOBAL_ASM(
.text
glabel set_parent_cur_obj_photograph
/* 039B54 7F005024 3C028007 */  lui   $v0, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
/* 039B58 7F005028 24425D90 */  addiu $v0, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E) # addiu $v0, $v0, 0x5d90
/* 039B5C 7F00502C 8C4E0000 */  lw    $t6, ($v0)
/* 039B60 7F005030 AC8E000C */  sw    $t6, 0xc($a0)
/* 039B64 7F005034 03E00008 */  jr    $ra
/* 039B68 7F005038 AC440000 */   sw    $a0, ($v0)
)
#endif


