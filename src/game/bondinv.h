#ifndef _BONDINV_H_
#define _BONDINV_H_
#include <ultra64.h>
#include <bondconstants.h>
#include "bondview.h"

void reinit_inventory(void);
s32 bondinvIsAliveWithFlag(void);
s32 count_total_items_in_inventory(void);

InvItem *inv_get_item_by_index(s32 index);
textoverride *get_textoverride_by_obj(ObjectRecord *obj);
textoverride *get_textoverride_by_weaponum(ITEM_IDS weaponnum);

void choose_cycle_back_weapon(s32 *nextright, s32 *nextleft, s32 requireammo);
void choose_cycle_forward_weapon(s32 *nextright, s32 *nextleft, s32 requireammo);
int checkforgoldengun(void);
int add_item_to_inventory(ITEM_IDS item);
int add_doubles_item_to_inventory(ITEM_IDS right, ITEM_IDS left);
s32 get_BONDdata_allguns_flag(void);
void set_BONDdata_allguns_flag(s32 all_guns);

#endif
