#ifndef _OBJECTIVE_STATUS_H_
#define _OBJECTIVE_STATUS_H_
#include <ultra64.h>
#include <bondtypes.h>

void             objectiveTakePictureHandler();
bool             check_objectives_complete(void);
TagObjectRecord *sub_GAME_7F057080(s32 TagID);
s32              add_objective(void);
ObjectRecord *   get_handle_to_tagged_object(s32 TagID);
OBJECTIVESTATUS  get_status_of_objective(s32 objectiveNum);
#endif
