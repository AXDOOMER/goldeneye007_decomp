#ifndef _BONDINV_H_
#define _BONDINV_H_
#include "ultra64.h"
#include "game/bond.h"

void reinit_inventory(void);
s32 bondinvIsAliveWithFlag(void);
s32 count_total_items_in_inventory(void);

InvItem *inv_get_item_by_index(s32 index);
textoverride *get_textoverride_by_obj(ObjectRecord *obj);
textoverride *get_textoverride_by_weaponum(ITEM_IDS weaponnum);

void sub_GAME_7F08CB10(int *nextright, int *nextleft, int param_3);

void choose_cycle_forward_weapon(s32 *nextright, s32 *nextleft, s32 direction);

#endif
