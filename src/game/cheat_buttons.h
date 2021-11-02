#ifndef _CHEAT_BUTTONS_H_
#define _CHEAT_BUTTONS_H_
#include "ultra64.h"

struct struct_15 {
    char anonymous_0;
    char field_1;
    char field_2;
    char field_3;
    void * anonymous_1;
    int anonymous_2;
    int anonymous_3;
};

extern char off_CODE_bss_80079E30[0x4C];

u32 is_cheat_index_equal_to_1C(u32 cheatindex);
void turn_on_cheat_for_players(u32 cheatindex);

#endif
