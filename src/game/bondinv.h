#ifndef _BONDINV_H_
#define _BONDINV_H_
#include "ultra64.h"

void reinit_BONDdata_inventory(void);
s32 bondinvIsAliveWithFlag(void);
s32 count_total_items_in_inventory(void);

InvItem *inv_get_item_by_index(s32 index);
textoverride *get_textoverride_by_obj(ObjectRecord *obj);
textoverride *get_textoverride_by_weaponum(ITEM_IDS weaponnum);

#endif
