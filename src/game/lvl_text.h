#ifndef _LVL_TEXT_H_
#define _LVL_TEXT_H_
#include "ultra64.h"

struct stringentry {
    char *string;
};

extern s32 j_text_trigger;

void something_with_LnameJ(void);
u8 * get_textptr_for_textID(s32 slotID);

#endif
