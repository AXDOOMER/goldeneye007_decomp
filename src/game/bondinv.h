#ifndef _BONDINV_H_
#define _BONDINV_H_
#include "ultra64.h"

void reinit_inventory(void);
s32 bondinvIsAliveWithFlag(void);
s32 count_total_items_in_inventory(void);

InvItem *inv_get_item_by_index(s32 index);
textoverride *get_textoverride_by_obj(ObjectRecord *obj);
textoverride *get_textoverride_by_weaponum(ITEM_IDS weaponnum);

void sub_GAME_7F08CB10(int *param_1, int *param_2, int param_3);

void sub_GAME_7F08C86C(int *nextright, int *nextleft, int direction);

#endif
