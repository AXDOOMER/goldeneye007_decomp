#include "ultra64.h"
#include "game/bond.h"
#include "game/chr.h"
#include "game/unk_093880.h"
#include "game/textrelated.h"
#include "bondconstants.h"
#include "game/lvl_text.h"
#include "game/bondinv.h"
#include "game/bondwalk.h"
#include "game/lvl.h"
#include "bondtypes.h"

void reinit_inventory(void) {
    s32 i;

    for (i=0; i < pPlayer->equipmaxitems; i++) {
        pPlayer->p_itemcur[i].type = -1;
    }
    
    pPlayer->ptr_inventory_first_in_cycle = NULL;
    pPlayer->textoverrides = NULL;
    pPlayer->equipcuritem = 0;
}

/**
 * Sorts subject into its correct position in the inventory list.
 *
 * Subject is expected to initially be at the head of the list. It works by
 * swapping the subject with the item to its right as many times as needed.
 */
void inv_sort_item(InvItem *subject) {
    
    InvItem *candidate;
    s32 subjweapon1 = -1;
    s32 subjweapon2 = -1;
    s32 candweapon1;
    s32 candweapon2;

    // Prepare subject's properties for comparisons
    if (subject->type == INV_ITEM_WEAPON) {
        subjweapon1 = subject->type_inv_item.type_weap.weapon;
    } else if (subject->type == INV_ITEM_DUAL) {
        subjweapon1 = subject->type_inv_item.type_dual.weapon_right;
        subjweapon2 = subject->type_inv_item.type_dual.weapon_left;
    } else if (subject->type == INV_ITEM_PROP) {
        subjweapon1 = 2000;
    }

    candidate = subject->next;

    while (pPlayer->ptr_inventory_first_in_cycle != subject->next) {
        // Prepare candidate's properties for comparisons
        candweapon1 = -1;
        candweapon2 = -1;

        if (subject->next->type == INV_ITEM_WEAPON) {
            candweapon1 = subject->next->type_inv_item.type_weap.weapon;
        } else if (subject->next->type == INV_ITEM_DUAL) {
            candweapon1 = subject->next->type_inv_item.type_dual.weapon_right;
            candweapon2 = subject->next->type_inv_item.type_dual.weapon_left;
        } else if (subject->next->type == INV_ITEM_PROP) {
            candweapon1 = 1000;
        }

        // If the candidate should sort ahead of subject
        // then subject is in the desired position.
        if (candweapon1 >= subjweapon1 &&
                (subjweapon1 != candweapon1 || subjweapon2 <= candweapon2)) {
            return;
        }

        // If there's only two items in the list then there's no point swapping
        // them. Just set the list head to the candidate.
        if (candidate->next == subject) {
            pPlayer->ptr_inventory_first_in_cycle = candidate;
        } else {
            // Swap subject with candidate
            subject->next = candidate->next;
            candidate->prev = subject->prev;
            subject->prev = candidate;
            candidate->next = subject;
            subject->next->prev = subject;
            candidate->prev->next = candidate;

            // Set new list head if subject was the head
            if (subject == pPlayer->ptr_inventory_first_in_cycle) {
                pPlayer->ptr_inventory_first_in_cycle = candidate;
            }
        }

        candidate = subject->next;
    }
}

void inv_insert_item(InvItem *item) {
  
  if (pPlayer->ptr_inventory_first_in_cycle) {
        
        item->next = pPlayer->ptr_inventory_first_in_cycle;
        item->prev = pPlayer->ptr_inventory_first_in_cycle->prev;

        item->next->prev = item;
        item->prev->next = item;

    }
    else {
        item->next = item;
        item->prev = item;
    }

    pPlayer->ptr_inventory_first_in_cycle = item;
    inv_sort_item(item);
    return;
}


void inventory_remove_item(InvItem *item) {

    InvItem *prev;
    InvItem *next;
  
    next = item->next;
    prev = item->prev;

    if (item == pPlayer->ptr_inventory_first_in_cycle) {
    
        if (item == item->next) {
            pPlayer->ptr_inventory_first_in_cycle = NULL;
        }
        else {
            pPlayer->ptr_inventory_first_in_cycle = item->next;
        }
    }
  
    next->prev = prev;
    prev->next = next; 
    item->type = -1;
    return;
}

InvItem *get_ptr_next_available_weapon(void)
{
    int i;

    for (i = 0; i < pPlayer->equipmaxitems; i++) {
        if (pPlayer->p_itemcur[i].type == -1) {
            return &pPlayer->p_itemcur[i];
        }
    }

    return NULL;
}


void set_BONDdata_allguns_flag(s32 all_guns) {
    pPlayer->equipallguns = all_guns;
}

s32 get_BONDdata_allguns_flag(void) {
    return pPlayer->equipallguns;
}


InvItem *get_inventory_item(ITEM_IDS weapon) {

    InvItem *first = pPlayer->ptr_inventory_first_in_cycle;
    InvItem *item = first;

    while (item) {

        if (item->type == INV_ITEM_WEAPON && item->type_inv_item.type_weap.weapon == weapon) {
            return item;
        }

        item = item->next;

        if (item == first) {
            break;
        }
    }

    return NULL;
}


/**
 * Is item in inventory
 * @param item: enum Item ID eg: ITEM_KNIFE
 * @return TRUE/FALSE
 */
int is_item_in_inventory(ITEM_IDS item) 
{
    return get_inventory_item(item) != NULL;
}


InvItem *get_dual_weapon(ITEM_IDS right, ITEM_IDS left) {

    InvItem *first = pPlayer->ptr_inventory_first_in_cycle;
    InvItem *item = first;

    while (item) {

        if (item->type == INV_ITEM_DUAL &&
            item->type_inv_item.type_dual.weapon_right == right &&
            item->type_inv_item.type_dual.weapon_left == left) {
            return item;
        }

        item = item->next;

        if (item == first) {
            break;
        }
    }

    return NULL;
}


 /**
 * Is dual weapon in inventory
 * @param right: enum Item ID eg: ITEM_KNIFE
 * @param left: enum Item ID eg: ITEM_KNIFE
 * @return TRUE/FALSE
 */
int is_dual_weapon_in_inventory(ITEM_IDS right, ITEM_IDS left) 
{
    return get_dual_weapon(right, left) != NULL;
}

int check_if_item_available(ITEM_IDS weaponid)
{    

    if (((pPlayer->equipallguns) && (weaponid != ITEM_UNARMED) && (weaponid < ITEM_BOMBCASE)))
    {
#ifdef VERSION_JP
    if  ((!j_text_trigger || (weaponid != ITEM_KNIFE)))
    {
        return 1;
    }
#else
        return 1;
#endif
    }
    return is_item_in_inventory(weaponid);
}


int check_if_item_for_hand_available(ITEM_IDS right, ITEM_IDS left)
{
#ifdef VERSION_US
    if (pPlayer->equipallguns &&
        right < ITEM_BOMBCASE &&
        right == left &&
        getPlayerCount() == 1 &&
        bondwalkItemCheckBitflags(right, 0x100000))
    {
        return 1;
    }
#endif

#ifdef VERSION_JP
    if (left == 0)
    {
        return 1;
    }
    else
    {
        if (pPlayer->equipallguns &&
            right < ITEM_BOMBCASE &&
            right == left &&
            getPlayerCount() == 1 &&
            bondwalkItemCheckBitflags(right, 0x100000) &&
            (j_text_trigger == 0 || (right != ITEM_KNIFE)))
        {
            return 1;
        }
    }
#endif

    return is_dual_weapon_in_inventory(right, left);
}



int add_item_to_inventory(ITEM_IDS item)
{
    InvItem *nextItem;
  
    if (is_item_in_inventory(item) == 0)
    {
        nextItem = get_ptr_next_available_weapon();
        if (nextItem)
        {
            nextItem->type = INV_ITEM_WEAPON;
            nextItem->type_inv_item.type_weap.weapon = item;
            inv_insert_item(nextItem);
        }

        if ((pPlayer->equipallguns) && (item < ITEM_BOMBCASE))
        {
#ifdef VERSION_JP
        if  ((!j_text_trigger || (item != ITEM_KNIFE)))
        {
            return FALSE;
        }
#else
            return FALSE;
#endif
        }
        return TRUE;
    }
    return FALSE;
}


int add_doubles_item_to_inventory(ITEM_IDS right, ITEM_IDS left)
{
    InvItem *item;
  
    if (is_dual_weapon_in_inventory(right, left) == 0) {
    
        item = get_ptr_next_available_weapon();
    
        if (item) {
            item->type = INV_ITEM_DUAL;
            item->type_inv_item.type_dual.weapon_right = right;
            item->type_inv_item.type_dual.weapon_left = left;
            inv_insert_item(item);
        }
        return TRUE;
    } else {
        return FALSE;
    }
}


WeaponObjRecord *inventory_remove_prop_weapon_by_id(ITEM_IDS weaponnum)
{
    if (pPlayer->ptr_inventory_first_in_cycle) {
        InvItem *item = pPlayer->ptr_inventory_first_in_cycle->next;

        while (TRUE) {
            InvItem *next = item->next;
        
            if (item->type == INV_ITEM_PROP) {
                PropRecord *prop = item->type_inv_item.type_prop.prop;
                
                if (prop->type == PROP_TYPE_WEAPON) {
                    ObjectRecord *obj = prop->Entityp.obj;
                    
                    if (obj->head.type == PROPDEF_COLLECTABLE) {
                        WeaponObjRecord *weapon = (WeaponObjRecord *)prop->Entityp.obj;

                        if (weapon->weaponnum == weaponnum) {
                            inventory_remove_item(item);
                            return weapon;
                        }
                    }
                }
            }

            if ((item == pPlayer->ptr_inventory_first_in_cycle) || (!pPlayer->ptr_inventory_first_in_cycle)) {   
                break;
            }

            item = next;
        }
    }

    return NULL;
}

void inventory_remove_item_by_id(ITEM_IDS weaponnum)
{
    if (pPlayer->ptr_inventory_first_in_cycle) {
        InvItem *item = pPlayer->ptr_inventory_first_in_cycle->next;

        while (TRUE) {
            InvItem *next = item->next;
            
            if (item->type == INV_ITEM_PROP) {
                PropRecord *prop = item->type_inv_item.type_prop.prop;
                
                if (prop->type == PROP_TYPE_WEAPON) {
                    ObjectRecord *obj = prop->Entityp.obj;

                    if (obj->head.type == PROPDEF_COLLECTABLE) {
                        WeaponObjRecord *weapon = (WeaponObjRecord *)prop->Entityp.obj;
                        
                        if (weapon->weaponnum == weaponnum) {
                            inventory_remove_item(item);
                        }
                    }
                }

            } else if (item->type == INV_ITEM_WEAPON) {
                if (item->type_inv_item.type_weap.weapon == weaponnum) {
                    inventory_remove_item(item);
                }
            }

            if ((item == pPlayer->ptr_inventory_first_in_cycle) || (!pPlayer->ptr_inventory_first_in_cycle)) {   
                break;
            }

            item = next;
        }
    }
}

int add_prop_to_inventory(PropRecord *prop) {

    InvItem *item;

    item = get_ptr_next_available_weapon();
    
    if (item) {
        item->type = INV_ITEM_PROP;
        item->type_inv_item.type_prop.prop = prop;
        inv_insert_item(item);
    }

    return TRUE;
}


int add_weapon_by_prop(PropRecord *prop)
{
    int added;
    added = FALSE;

    if (prop->type == PROP_TYPE_WEAPON)
    {
        ObjectRecord *obj = prop->Entityp.obj;

        if (obj->head.type == PROPDEF_COLLECTABLE)
        {
            WeaponObjRecord *weapon = (WeaponObjRecord *)prop->Entityp.obj;
            WeaponObjRecord *otherweapon;

            s8 weaponnum = weapon->weaponnum;
            added = add_item_to_inventory(weaponnum);
            
            otherweapon = weapon->dualweapon;
            if (otherweapon != 0)
            {
                if (weapon->base.flags & PROPFLAG_10000000)
                {
                    added = is_dual_weapon_in_inventory(otherweapon->weaponnum, weaponnum) == 0;
                }
                else
                {
                    added = is_dual_weapon_in_inventory(weaponnum, otherweapon->weaponnum) == 0;
                }
                weapon->dualweapon->LinkedWeaponType = weaponnum;
                weapon->dualweapon->dualweapon = 0;
                weapon->dualweapon = NULL;
            }
            else
            {
                if (weapon->LinkedWeaponType >= 0)
                {
                    if (weapon->base.flags & PROPFLAG_10000000)
                    {
                        added = add_doubles_item_to_inventory(weapon->LinkedWeaponType, weaponnum);
                    }
                    else
                    {
                        added = add_doubles_item_to_inventory(weaponnum, weapon->LinkedWeaponType);
                    }
                }
            }
        }
    }
    return added;
}






#ifndef VERSION_EU
void choose_cycle_forward_weapon(s32 *nextright, s32 *nextleft, s32 requireammo)
{
	s32 weapon1 = *nextright;
	s32 weapon2 = *nextleft;

    InvItem *item = pPlayer->ptr_inventory_first_in_cycle;
        
    while (item) {
        if (item->type == INV_ITEM_WEAPON) {
            if (item->type_inv_item.type_weap.weapon < 0x21 && item->type_inv_item.type_weap.weapon > weapon1) {
                if (requireammo == FALSE || bondwalkItemHasAmmo(item->type_inv_item.type_weap.weapon)) {
                    weapon1 = item->type_inv_item.type_weap.weapon;
                    weapon2 = 0;
                    break;
                }
            }
        } else if (item->type == INV_ITEM_DUAL) {
            if (item->type_inv_item.type_dual.weapon_right > weapon1
                    || (weapon1 == item->type_inv_item.type_dual.weapon_right && item->type_inv_item.type_dual.weapon_left > weapon2)) {
                if (requireammo == FALSE || bondwalkItemHasAmmo(item->type_inv_item.type_dual.weapon_right) || bondwalkItemHasAmmo(item->type_inv_item.type_dual.weapon_left)) {
                    weapon1 = item->type_inv_item.type_dual.weapon_right;
                    weapon2 = item->type_inv_item.type_dual.weapon_left;
                    break;
                }
            }
        }

        item = item->next;

        if (item == pPlayer->ptr_inventory_first_in_cycle) {
            if (requireammo) {
                break;
            }

            weapon1 = -1;
            weapon2 = -1;
        }
    }
    
	if (pPlayer->equipallguns) {
        
        s32 candidate = *nextright;

        if (getPlayerCount() == 1
            && bondwalkItemCheckBitflags(*nextright, 0x100000)
            && (*nextleft < *nextright)
            && (requireammo == FALSE || bondwalkItemHasAmmo(*nextright))
            && (weapon1 != *nextright || *nextright < weapon2)
        #ifdef VERSION_JP
            && (j_text_trigger == 0 || *nextright != 2)
        #endif
        ) {
            
            weapon1 = *nextright;
            weapon2 = *nextright;
                
        } else {

            if ((weapon1 != *nextright) || (weapon2 == *nextleft)) {
                // Find next weapon
                do {
                    candidate = (candidate + 1) % 0x21;

                    if (candidate == 0) {
                        candidate = (candidate + 1) % 0x21;
                    }

                    if ((requireammo == FALSE || bondwalkItemHasAmmo(candidate))
                    #ifdef VERSION_JP
                        && (j_text_trigger == 0 || candidate != 2)
                    #endif
                    ) {
                        weapon1 = candidate;
                        weapon2 = 0;
                        break;
                    }
                } while (candidate != weapon1);
            }
        }
    } 

	*nextright = weapon1;
	*nextleft = weapon2;
}
#endif



#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel choose_cycle_forward_weapon
/* 0C139C 7F08C86C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C13A0 7F08C870 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C13A4 7F08C874 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C13A8 7F08C878 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C13AC 7F08C87C AFB30020 */  sw    $s3, 0x20($sp)
/* 0C13B0 7F08C880 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C13B4 7F08C884 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C13B8 7F08C888 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C13BC 7F08C88C AFA40028 */  sw    $a0, 0x28($sp)
/* 0C13C0 7F08C890 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0C13C4 7F08C894 8C7011E0 */  lw    $s0, 0x11e0($v1)
/* 0C13C8 7F08C898 00C09025 */  move  $s2, $a2
/* 0C13CC 7F08C89C 8C910000 */  lw    $s1, ($a0)
/* 0C13D0 7F08C8A0 1200003D */  beqz  $s0, .L7F08C998
/* 0C13D4 7F08C8A4 8CB30000 */   lw    $s3, ($a1)
/* 0C13D8 7F08C8A8 8E020000 */  lw    $v0, ($s0)
.L7F08C8AC:
/* 0C13DC 7F08C8AC 24010001 */  li    $at, 1
/* 0C13E0 7F08C8B0 54410013 */  bnel  $v0, $at, .L7F08C900
/* 0C13E4 7F08C8B4 24010003 */   li    $at, 3
/* 0C13E8 7F08C8B8 8E040004 */  lw    $a0, 4($s0)
/* 0C13EC 7F08C8BC 28810021 */  slti  $at, $a0, 0x21
/* 0C13F0 7F08C8C0 10200029 */  beqz  $at, .L7F08C968
/* 0C13F4 7F08C8C4 0224082A */   slt   $at, $s1, $a0
/* 0C13F8 7F08C8C8 10200027 */  beqz  $at, .L7F08C968
/* 0C13FC 7F08C8CC 00000000 */   nop   
/* 0C1400 7F08C8D0 52400008 */  beql  $s2, $zero, .L7F08C8F4
/* 0C1404 7F08C8D4 00808825 */   move  $s1, $a0
/* 0C1408 7F08C8D8 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C140C 7F08C8DC 00000000 */   nop   
/* 0C1410 7F08C8E0 10400021 */  beqz  $v0, .L7F08C968
/* 0C1414 7F08C8E4 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C1418 7F08C8E8 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C141C 7F08C8EC 8E040004 */  lw    $a0, 4($s0)
/* 0C1420 7F08C8F0 00808825 */  move  $s1, $a0
.L7F08C8F4:
/* 0C1424 7F08C8F4 10000028 */  b     .L7F08C998
/* 0C1428 7F08C8F8 00009825 */   move  $s3, $zero
/* 0C142C 7F08C8FC 24010003 */  li    $at, 3
.L7F08C900:
/* 0C1430 7F08C900 14410019 */  bne   $v0, $at, .L7F08C968
/* 0C1434 7F08C904 00000000 */   nop   
/* 0C1438 7F08C908 8E040004 */  lw    $a0, 4($s0)
/* 0C143C 7F08C90C 0224082A */  slt   $at, $s1, $a0
/* 0C1440 7F08C910 14200007 */  bnez  $at, .L7F08C930
/* 0C1444 7F08C914 00000000 */   nop   
/* 0C1448 7F08C918 16240013 */  bne   $s1, $a0, .L7F08C968
/* 0C144C 7F08C91C 00000000 */   nop   
/* 0C1450 7F08C920 8E180008 */  lw    $t8, 8($s0)
/* 0C1454 7F08C924 0278082A */  slt   $at, $s3, $t8
/* 0C1458 7F08C928 1020000F */  beqz  $at, .L7F08C968
/* 0C145C 7F08C92C 00000000 */   nop   
.L7F08C930:
/* 0C1460 7F08C930 12400008 */  beqz  $s2, .L7F08C954
/* 0C1464 7F08C934 00000000 */   nop   
/* 0C1468 7F08C938 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C146C 7F08C93C 00000000 */   nop   
/* 0C1470 7F08C940 14400004 */  bnez  $v0, .L7F08C954
/* 0C1474 7F08C944 00000000 */   nop   
/* 0C1478 7F08C948 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C147C 7F08C94C 8E040008 */   lw    $a0, 8($s0)
/* 0C1480 7F08C950 10400005 */  beqz  $v0, .L7F08C968
.L7F08C954:
/* 0C1484 7F08C954 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C1488 7F08C958 8E110004 */  lw    $s1, 4($s0)
/* 0C148C 7F08C95C 8E130008 */  lw    $s3, 8($s0)
/* 0C1490 7F08C960 1000000D */  b     .L7F08C998
/* 0C1494 7F08C964 8C63A0B0 */   lw    $v1, %lo(pPlayer)($v1)
.L7F08C968:
/* 0C1498 7F08C968 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C149C 7F08C96C 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C14A0 7F08C970 8E10000C */  lw    $s0, 0xc($s0)
/* 0C14A4 7F08C974 8C7911E0 */  lw    $t9, 0x11e0($v1)
/* 0C14A8 7F08C978 16190005 */  bne   $s0, $t9, .L7F08C990
/* 0C14AC 7F08C97C 00000000 */   nop   
/* 0C14B0 7F08C980 56400006 */  bnezl $s2, .L7F08C99C
/* 0C14B4 7F08C984 8C6811EC */   lw    $t0, 0x11ec($v1)
/* 0C14B8 7F08C988 2411FFFF */  li    $s1, -1
/* 0C14BC 7F08C98C 2413FFFF */  li    $s3, -1
.L7F08C990:
/* 0C14C0 7F08C990 5600FFC6 */  bnezl $s0, .L7F08C8AC
/* 0C14C4 7F08C994 8E020000 */   lw    $v0, ($s0)
.L7F08C998:
/* 0C14C8 7F08C998 8C6811EC */  lw    $t0, 0x11ec($v1)
.L7F08C99C:
/* 0C14CC 7F08C99C 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C14D0 7F08C9A0 51000051 */  beql  $t0, $zero, .L7F08CAE8
/* 0C14D4 7F08C9A4 8FAB0028 */   lw    $t3, 0x28($sp)
/* 0C14D8 7F08C9A8 0FC26919 */  jal   getPlayerCount
/* 0C14DC 7F08C9AC 8D300000 */   lw    $s0, ($t1)
/* 0C14E0 7F08C9B0 24010001 */  li    $at, 1
/* 0C14E4 7F08C9B4 5441001E */  bnel  $v0, $at, .L7F08CA30
/* 0C14E8 7F08C9B8 8FAF0028 */   lw    $t7, 0x28($sp)
/* 0C14EC 7F08C9BC 8FAA0028 */  lw    $t2, 0x28($sp)
/* 0C14F0 7F08C9C0 3C050010 */  lui   $a1, 0x10
/* 0C14F4 7F08C9C4 0FC1782D */  jal   bondwalkItemCheckBitflags
/* 0C14F8 7F08C9C8 8D440000 */   lw    $a0, ($t2)
/* 0C14FC 7F08C9CC 50400018 */  beql  $v0, $zero, .L7F08CA30
/* 0C1500 7F08C9D0 8FAF0028 */   lw    $t7, 0x28($sp)
/* 0C1504 7F08C9D4 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0C1508 7F08C9D8 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0C150C 7F08C9DC 8D640000 */  lw    $a0, ($t3)
/* 0C1510 7F08C9E0 8D8D0000 */  lw    $t5, ($t4)
/* 0C1514 7F08C9E4 01A4082A */  slt   $at, $t5, $a0
/* 0C1518 7F08C9E8 50200011 */  beql  $at, $zero, .L7F08CA30
/* 0C151C 7F08C9EC 8FAF0028 */   lw    $t7, 0x28($sp)
/* 0C1520 7F08C9F0 12400007 */  beqz  $s2, .L7F08CA10
/* 0C1524 7F08C9F4 00000000 */   nop   
/* 0C1528 7F08C9F8 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C152C 7F08C9FC 00000000 */   nop   
/* 0C1530 7F08CA00 5040000B */  beql  $v0, $zero, .L7F08CA30
/* 0C1534 7F08CA04 8FAF0028 */   lw    $t7, 0x28($sp)
/* 0C1538 7F08CA08 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0C153C 7F08CA0C 8DC40000 */  lw    $a0, ($t6)
.L7F08CA10:
/* 0C1540 7F08CA10 16240003 */  bne   $s1, $a0, .L7F08CA20
/* 0C1544 7F08CA14 0093082A */   slt   $at, $a0, $s3
/* 0C1548 7F08CA18 50200005 */  beql  $at, $zero, .L7F08CA30
/* 0C154C 7F08CA1C 8FAF0028 */   lw    $t7, 0x28($sp)
.L7F08CA20:
/* 0C1550 7F08CA20 00808825 */  move  $s1, $a0
/* 0C1554 7F08CA24 1000002F */  b     .L7F08CAE4
/* 0C1558 7F08CA28 00809825 */   move  $s3, $a0
/* 0C155C 7F08CA2C 8FAF0028 */  lw    $t7, 0x28($sp)
.L7F08CA30:
/* 0C1560 7F08CA30 24030021 */  li    $v1, 33
/* 0C1564 7F08CA34 8DF80000 */  lw    $t8, ($t7)
/* 0C1568 7F08CA38 16380005 */  bne   $s1, $t8, .L7F08CA50
/* 0C156C 7F08CA3C 00000000 */   nop   
/* 0C1570 7F08CA40 8FB9002C */  lw    $t9, 0x2c($sp)
/* 0C1574 7F08CA44 8F280000 */  lw    $t0, ($t9)
/* 0C1578 7F08CA48 56680027 */  bnel  $s3, $t0, .L7F08CAE8
/* 0C157C 7F08CA4C 8FAB0028 */   lw    $t3, 0x28($sp)
.L7F08CA50:
/* 0C1580 7F08CA50 26090001 */  addiu $t1, $s0, 1
.L7F08CA54:
/* 0C1584 7F08CA54 0123001A */  div   $zero, $t1, $v1
/* 0C1588 7F08CA58 00008010 */  mfhi  $s0
/* 0C158C 7F08CA5C 260A0001 */  addiu $t2, $s0, 1
/* 0C1590 7F08CA60 14600002 */  bnez  $v1, .L7F08CA6C
/* 0C1594 7F08CA64 00000000 */   nop   
/* 0C1598 7F08CA68 0007000D */  break 7
.L7F08CA6C:
/* 0C159C 7F08CA6C 2401FFFF */  li    $at, -1
/* 0C15A0 7F08CA70 14610004 */  bne   $v1, $at, .L7F08CA84
/* 0C15A4 7F08CA74 3C018000 */   lui   $at, 0x8000
/* 0C15A8 7F08CA78 15210002 */  bne   $t1, $at, .L7F08CA84
/* 0C15AC 7F08CA7C 00000000 */   nop   
/* 0C15B0 7F08CA80 0006000D */  break 6
.L7F08CA84:
/* 0C15B4 7F08CA84 1600000C */  bnez  $s0, .L7F08CAB8
/* 0C15B8 7F08CA88 00000000 */   nop   
/* 0C15BC 7F08CA8C 0143001A */  div   $zero, $t2, $v1
/* 0C15C0 7F08CA90 00008010 */  mfhi  $s0
/* 0C15C4 7F08CA94 14600002 */  bnez  $v1, .L7F08CAA0
/* 0C15C8 7F08CA98 00000000 */   nop   
/* 0C15CC 7F08CA9C 0007000D */  break 7
.L7F08CAA0:
/* 0C15D0 7F08CAA0 2401FFFF */  li    $at, -1
/* 0C15D4 7F08CAA4 14610004 */  bne   $v1, $at, .L7F08CAB8
/* 0C15D8 7F08CAA8 3C018000 */   lui   $at, 0x8000
/* 0C15DC 7F08CAAC 15410002 */  bne   $t2, $at, .L7F08CAB8
/* 0C15E0 7F08CAB0 00000000 */   nop   
/* 0C15E4 7F08CAB4 0006000D */  break 6
.L7F08CAB8:
/* 0C15E8 7F08CAB8 52400006 */  beql  $s2, $zero, .L7F08CAD4
/* 0C15EC 7F08CABC 02008825 */   move  $s1, $s0
/* 0C15F0 7F08CAC0 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C15F4 7F08CAC4 02002025 */   move  $a0, $s0
/* 0C15F8 7F08CAC8 10400004 */  beqz  $v0, .L7F08CADC
/* 0C15FC 7F08CACC 24030021 */   li    $v1, 33
/* 0C1600 7F08CAD0 02008825 */  move  $s1, $s0
.L7F08CAD4:
/* 0C1604 7F08CAD4 10000003 */  b     .L7F08CAE4
/* 0C1608 7F08CAD8 00009825 */   move  $s3, $zero
.L7F08CADC:
/* 0C160C 7F08CADC 5611FFDD */  bnel  $s0, $s1, .L7F08CA54
/* 0C1610 7F08CAE0 26090001 */   addiu $t1, $s0, 1
.L7F08CAE4:
/* 0C1614 7F08CAE4 8FAB0028 */  lw    $t3, 0x28($sp)
.L7F08CAE8:
/* 0C1618 7F08CAE8 AD710000 */  sw    $s1, ($t3)
/* 0C161C 7F08CAEC 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0C1620 7F08CAF0 AD930000 */  sw    $s3, ($t4)
/* 0C1624 7F08CAF4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C1628 7F08CAF8 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C162C 7F08CAFC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C1630 7F08CB00 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C1634 7F08CB04 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C1638 7F08CB08 03E00008 */  jr    $ra
/* 0C163C 7F08CB0C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif


#ifndef VERSION_EU
void choose_cycle_back_weapon(s32 *nextright, s32 *nextleft, s32 requireammo)
{
	s32 weapon1 = *nextright;
	s32 weapon2 = *nextleft;

    if (pPlayer->ptr_inventory_first_in_cycle != NULL) {

        InvItem *item = pPlayer->ptr_inventory_first_in_cycle->prev;
            
        while (TRUE) {
            if (item->type == INV_ITEM_WEAPON) {
                if (item->type_inv_item.type_weap.weapon < 0x21 && (item->type_inv_item.type_weap.weapon < weapon1 || (weapon1 == item->type_inv_item.type_weap.weapon && weapon2 > 0)))
                {
                    if (requireammo == FALSE || bondwalkItemHasAmmo(item->type_inv_item.type_weap.weapon)) {
                        weapon1 = item->type_inv_item.type_weap.weapon;
                        weapon2 = 0;
                        break;
                    }
                }
            } else if (item->type == INV_ITEM_DUAL) {
                if (item->type_inv_item.type_dual.weapon_right < weapon1
                        || (weapon1 == item->type_inv_item.type_dual.weapon_right && item->type_inv_item.type_dual.weapon_left < weapon2)) {
                    if (requireammo == FALSE || bondwalkItemHasAmmo(item->type_inv_item.type_dual.weapon_right) || bondwalkItemHasAmmo(item->type_inv_item.type_dual.weapon_left)) {
                        weapon1 = item->type_inv_item.type_dual.weapon_right;
                        weapon2 = item->type_inv_item.type_dual.weapon_left;
                        break;
                    }
                }
            }

            if (item == pPlayer->ptr_inventory_first_in_cycle) {
                if (requireammo) {
                    break;
                }

                weapon1 = 1000;
                weapon2 = 1000;
            }

            item = item->prev;
        }
    }
    
	if (pPlayer->equipallguns) {
        
        s32 candidate = *nextright;

        if (*nextleft == 0) {
            candidate = (candidate + 0x20) % 0x21;
            if (candidate == 0) {
                candidate = (candidate + 0x20) % 0x21;
            }
        }

        while (TRUE) {
    
            if (candidate == weapon1) {
                
                if (getPlayerCount() == 1
                    && bondwalkItemCheckBitflags(candidate, 0x100000)
                    && (requireammo == FALSE || bondwalkItemHasAmmo(candidate))
                    && (candidate != *nextright || candidate < *nextleft)
                    && (weapon2 < candidate)
                #ifdef VERSION_JP
                    && (j_text_trigger == 0 || candidate != 2)
                #endif
                ) {
                    weapon1 = candidate;
                    weapon2 = candidate;
                }
                
                break;
            }
            else if (
                (requireammo == FALSE || bondwalkItemHasAmmo(candidate))
                #ifdef VERSION_JP
                    && (j_text_trigger == 0 || candidate != 2)
                #endif
            ) {
                
                if (getPlayerCount() == 1
                    && bondwalkItemCheckBitflags(candidate, 0x100000)
                    && (candidate != *nextright || candidate < *nextleft))
                {
                    weapon1 = candidate;
                    weapon2 = candidate;
                } else {
                    weapon1 = candidate;
                    weapon2 = 0;
                }
                
                break;
            
            } else {
                candidate = (candidate + 0x20) % 0x21;
                if (candidate == 0) {
                    candidate = (candidate + 0x20) % 0x21;
                }
            }
        }
    } 

	*nextright = weapon1;
	*nextleft = weapon2;
}
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel choose_cycle_back_weapon
/* 0C1640 7F08CB10 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C1644 7F08CB14 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C1648 7F08CB18 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C164C 7F08CB1C AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C1650 7F08CB20 AFB30020 */  sw    $s3, 0x20($sp)
/* 0C1654 7F08CB24 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C1658 7F08CB28 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C165C 7F08CB2C AFB00014 */  sw    $s0, 0x14($sp)
/* 0C1660 7F08CB30 AFA40028 */  sw    $a0, 0x28($sp)
/* 0C1664 7F08CB34 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0C1668 7F08CB38 8C6211E0 */  lw    $v0, 0x11e0($v1)
/* 0C166C 7F08CB3C 00C09025 */  move  $s2, $a2
/* 0C1670 7F08CB40 8C910000 */  lw    $s1, ($a0)
/* 0C1674 7F08CB44 00807025 */  move  $t6, $a0
/* 0C1678 7F08CB48 8CB30000 */  lw    $s3, ($a1)
/* 0C167C 7F08CB4C 10400042 */  beqz  $v0, .L7F08CC58
/* 0C1680 7F08CB50 00A07825 */   move  $t7, $a1
/* 0C1684 7F08CB54 8C500010 */  lw    $s0, 0x10($v0)
.L7F08CB58:
/* 0C1688 7F08CB58 8E020000 */  lw    $v0, ($s0)
/* 0C168C 7F08CB5C 24010001 */  li    $at, 1
/* 0C1690 7F08CB60 54410018 */  bnel  $v0, $at, .L7F08CBC4
/* 0C1694 7F08CB64 24010003 */   li    $at, 3
/* 0C1698 7F08CB68 8E040004 */  lw    $a0, 4($s0)
/* 0C169C 7F08CB6C 28810021 */  slti  $at, $a0, 0x21
/* 0C16A0 7F08CB70 1020002E */  beqz  $at, .L7F08CC2C
/* 0C16A4 7F08CB74 00000000 */   nop   
/* 0C16A8 7F08CB78 0091082A */  slt   $at, $a0, $s1
/* 0C16AC 7F08CB7C 14200005 */  bnez  $at, .L7F08CB94
/* 0C16B0 7F08CB80 00000000 */   nop   
/* 0C16B4 7F08CB84 16240029 */  bne   $s1, $a0, .L7F08CC2C
/* 0C16B8 7F08CB88 00000000 */   nop   
/* 0C16BC 7F08CB8C 1A600027 */  blez  $s3, .L7F08CC2C
/* 0C16C0 7F08CB90 00000000 */   nop   
.L7F08CB94:
/* 0C16C4 7F08CB94 52400008 */  beql  $s2, $zero, .L7F08CBB8
/* 0C16C8 7F08CB98 00808825 */   move  $s1, $a0
/* 0C16CC 7F08CB9C 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C16D0 7F08CBA0 00000000 */   nop   
/* 0C16D4 7F08CBA4 10400021 */  beqz  $v0, .L7F08CC2C
/* 0C16D8 7F08CBA8 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C16DC 7F08CBAC 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C16E0 7F08CBB0 8E040004 */  lw    $a0, 4($s0)
/* 0C16E4 7F08CBB4 00808825 */  move  $s1, $a0
.L7F08CBB8:
/* 0C16E8 7F08CBB8 10000027 */  b     .L7F08CC58
/* 0C16EC 7F08CBBC 00009825 */   move  $s3, $zero
/* 0C16F0 7F08CBC0 24010003 */  li    $at, 3
.L7F08CBC4:
/* 0C16F4 7F08CBC4 14410019 */  bne   $v0, $at, .L7F08CC2C
/* 0C16F8 7F08CBC8 00000000 */   nop   
/* 0C16FC 7F08CBCC 8E040004 */  lw    $a0, 4($s0)
/* 0C1700 7F08CBD0 0091082A */  slt   $at, $a0, $s1
/* 0C1704 7F08CBD4 14200007 */  bnez  $at, .L7F08CBF4
/* 0C1708 7F08CBD8 00000000 */   nop   
/* 0C170C 7F08CBDC 16240013 */  bne   $s1, $a0, .L7F08CC2C
/* 0C1710 7F08CBE0 00000000 */   nop   
/* 0C1714 7F08CBE4 8E180008 */  lw    $t8, 8($s0)
/* 0C1718 7F08CBE8 0313082A */  slt   $at, $t8, $s3
/* 0C171C 7F08CBEC 1020000F */  beqz  $at, .L7F08CC2C
/* 0C1720 7F08CBF0 00000000 */   nop   
.L7F08CBF4:
/* 0C1724 7F08CBF4 12400008 */  beqz  $s2, .L7F08CC18
/* 0C1728 7F08CBF8 00000000 */   nop   
/* 0C172C 7F08CBFC 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C1730 7F08CC00 00000000 */   nop   
/* 0C1734 7F08CC04 14400004 */  bnez  $v0, .L7F08CC18
/* 0C1738 7F08CC08 00000000 */   nop   
/* 0C173C 7F08CC0C 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C1740 7F08CC10 8E040008 */   lw    $a0, 8($s0)
/* 0C1744 7F08CC14 10400005 */  beqz  $v0, .L7F08CC2C
.L7F08CC18:
/* 0C1748 7F08CC18 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C174C 7F08CC1C 8E110004 */  lw    $s1, 4($s0)
/* 0C1750 7F08CC20 8E130008 */  lw    $s3, 8($s0)
/* 0C1754 7F08CC24 1000000C */  b     .L7F08CC58
/* 0C1758 7F08CC28 8C63A0B0 */   lw    $v1, %lo(pPlayer)($v1)
.L7F08CC2C:
/* 0C175C 7F08CC2C 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C1760 7F08CC30 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C1764 7F08CC34 8C7911E0 */  lw    $t9, 0x11e0($v1)
/* 0C1768 7F08CC38 16190005 */  bne   $s0, $t9, .L7F08CC50
/* 0C176C 7F08CC3C 00000000 */   nop   
/* 0C1770 7F08CC40 56400006 */  bnezl $s2, .L7F08CC5C
/* 0C1774 7F08CC44 8C6811EC */   lw    $t0, 0x11ec($v1)
/* 0C1778 7F08CC48 241103E8 */  li    $s1, 1000
/* 0C177C 7F08CC4C 241303E8 */  li    $s3, 1000
.L7F08CC50:
/* 0C1780 7F08CC50 1000FFC1 */  b     .L7F08CB58
/* 0C1784 7F08CC54 8E100010 */   lw    $s0, 0x10($s0)
.L7F08CC58:
/* 0C1788 7F08CC58 8C6811EC */  lw    $t0, 0x11ec($v1)
.L7F08CC5C:
/* 0C178C 7F08CC5C 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0C1790 7F08CC60 51000079 */  beql  $t0, $zero, .L7F08CE48
/* 0C1794 7F08CC64 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1798 7F08CC68 8D4B0000 */  lw    $t3, ($t2)
/* 0C179C 7F08CC6C 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C17A0 7F08CC70 24030021 */  li    $v1, 33
/* 0C17A4 7F08CC74 1560001B */  bnez  $t3, .L7F08CCE4
/* 0C17A8 7F08CC78 8D300000 */   lw    $s0, ($t1)
/* 0C17AC 7F08CC7C 260C0020 */  addiu $t4, $s0, 0x20
/* 0C17B0 7F08CC80 0183001A */  div   $zero, $t4, $v1
/* 0C17B4 7F08CC84 00008010 */  mfhi  $s0
/* 0C17B8 7F08CC88 260D0020 */  addiu $t5, $s0, 0x20
/* 0C17BC 7F08CC8C 14600002 */  bnez  $v1, .L7F08CC98
/* 0C17C0 7F08CC90 00000000 */   nop   
/* 0C17C4 7F08CC94 0007000D */  break 7
.L7F08CC98:
/* 0C17C8 7F08CC98 2401FFFF */  li    $at, -1
/* 0C17CC 7F08CC9C 14610004 */  bne   $v1, $at, .L7F08CCB0
/* 0C17D0 7F08CCA0 3C018000 */   lui   $at, 0x8000
/* 0C17D4 7F08CCA4 15810002 */  bne   $t4, $at, .L7F08CCB0
/* 0C17D8 7F08CCA8 00000000 */   nop   
/* 0C17DC 7F08CCAC 0006000D */  break 6
.L7F08CCB0:
/* 0C17E0 7F08CCB0 1600000C */  bnez  $s0, .L7F08CCE4
/* 0C17E4 7F08CCB4 00000000 */   nop   
/* 0C17E8 7F08CCB8 01A3001A */  div   $zero, $t5, $v1
/* 0C17EC 7F08CCBC 00008010 */  mfhi  $s0
/* 0C17F0 7F08CCC0 14600002 */  bnez  $v1, .L7F08CCCC
/* 0C17F4 7F08CCC4 00000000 */   nop   
/* 0C17F8 7F08CCC8 0007000D */  break 7
.L7F08CCCC:
/* 0C17FC 7F08CCCC 2401FFFF */  li    $at, -1
/* 0C1800 7F08CCD0 14610004 */  bne   $v1, $at, .L7F08CCE4
/* 0C1804 7F08CCD4 3C018000 */   lui   $at, 0x8000
/* 0C1808 7F08CCD8 15A10002 */  bne   $t5, $at, .L7F08CCE4
/* 0C180C 7F08CCDC 00000000 */   nop   
/* 0C1810 7F08CCE0 0006000D */  break 6
.L7F08CCE4:
/* 0C1814 7F08CCE4 1611001E */  bne   $s0, $s1, .L7F08CD60
/* 0C1818 7F08CCE8 00000000 */   nop   
/* 0C181C 7F08CCEC 0FC26919 */  jal   getPlayerCount
/* 0C1820 7F08CCF0 00000000 */   nop   
/* 0C1824 7F08CCF4 24010001 */  li    $at, 1
/* 0C1828 7F08CCF8 14410052 */  bne   $v0, $at, .L7F08CE44
/* 0C182C 7F08CCFC 02002025 */   move  $a0, $s0
/* 0C1830 7F08CD00 0FC1782D */  jal   bondwalkItemCheckBitflags
/* 0C1834 7F08CD04 3C050010 */   lui   $a1, 0x10
/* 0C1838 7F08CD08 5040004F */  beql  $v0, $zero, .L7F08CE48
/* 0C183C 7F08CD0C 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1840 7F08CD10 52400006 */  beql  $s2, $zero, .L7F08CD2C
/* 0C1844 7F08CD14 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1848 7F08CD18 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C184C 7F08CD1C 02002025 */   move  $a0, $s0
/* 0C1850 7F08CD20 50400049 */  beql  $v0, $zero, .L7F08CE48
/* 0C1854 7F08CD24 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1858 7F08CD28 8FAE0028 */  lw    $t6, 0x28($sp)
.L7F08CD2C:
/* 0C185C 7F08CD2C 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0C1860 7F08CD30 8DCF0000 */  lw    $t7, ($t6)
/* 0C1864 7F08CD34 560F0005 */  bnel  $s0, $t7, .L7F08CD4C
/* 0C1868 7F08CD38 0270082A */   slt   $at, $s3, $s0
/* 0C186C 7F08CD3C 8F190000 */  lw    $t9, ($t8)
/* 0C1870 7F08CD40 0219082A */  slt   $at, $s0, $t9
/* 0C1874 7F08CD44 1020003F */  beqz  $at, .L7F08CE44
/* 0C1878 7F08CD48 0270082A */   slt   $at, $s3, $s0
.L7F08CD4C:
/* 0C187C 7F08CD4C 5020003E */  beql  $at, $zero, .L7F08CE48
/* 0C1880 7F08CD50 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1884 7F08CD54 02008825 */  move  $s1, $s0
/* 0C1888 7F08CD58 1000003A */  b     .L7F08CE44
/* 0C188C 7F08CD5C 02009825 */   move  $s3, $s0
.L7F08CD60:
/* 0C1890 7F08CD60 12400005 */  beqz  $s2, .L7F08CD78
/* 0C1894 7F08CD64 00000000 */   nop   
/* 0C1898 7F08CD68 0FC17817 */  jal   bondwalkItemHasAmmo
/* 0C189C 7F08CD6C 02002025 */   move  $a0, $s0
/* 0C18A0 7F08CD70 10400018 */  beqz  $v0, .L7F08CDD4
/* 0C18A4 7F08CD74 24030021 */   li    $v1, 33
.L7F08CD78:
/* 0C18A8 7F08CD78 0FC26919 */  jal   getPlayerCount
/* 0C18AC 7F08CD7C 00000000 */   nop   
/* 0C18B0 7F08CD80 24010001 */  li    $at, 1
/* 0C18B4 7F08CD84 14410010 */  bne   $v0, $at, .L7F08CDC8
/* 0C18B8 7F08CD88 02002025 */   move  $a0, $s0
/* 0C18BC 7F08CD8C 0FC1782D */  jal   bondwalkItemCheckBitflags
/* 0C18C0 7F08CD90 3C050010 */   lui   $a1, 0x10
/* 0C18C4 7F08CD94 1040000C */  beqz  $v0, .L7F08CDC8
/* 0C18C8 7F08CD98 8FA80028 */   lw    $t0, 0x28($sp)
/* 0C18CC 7F08CD9C 8D090000 */  lw    $t1, ($t0)
/* 0C18D0 7F08CDA0 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0C18D4 7F08CDA4 02008825 */  move  $s1, $s0
/* 0C18D8 7F08CDA8 16090005 */  bne   $s0, $t1, .L7F08CDC0
/* 0C18DC 7F08CDAC 00000000 */   nop   
/* 0C18E0 7F08CDB0 8D4B0000 */  lw    $t3, ($t2)
/* 0C18E4 7F08CDB4 020B082A */  slt   $at, $s0, $t3
/* 0C18E8 7F08CDB8 50200004 */  beql  $at, $zero, .L7F08CDCC
/* 0C18EC 7F08CDBC 02008825 */   move  $s1, $s0
.L7F08CDC0:
/* 0C18F0 7F08CDC0 10000020 */  b     .L7F08CE44
/* 0C18F4 7F08CDC4 02009825 */   move  $s3, $s0
.L7F08CDC8:
/* 0C18F8 7F08CDC8 02008825 */  move  $s1, $s0
.L7F08CDCC:
/* 0C18FC 7F08CDCC 1000001D */  b     .L7F08CE44
/* 0C1900 7F08CDD0 00009825 */   move  $s3, $zero
.L7F08CDD4:
/* 0C1904 7F08CDD4 260C0020 */  addiu $t4, $s0, 0x20
/* 0C1908 7F08CDD8 0183001A */  div   $zero, $t4, $v1
/* 0C190C 7F08CDDC 00008010 */  mfhi  $s0
/* 0C1910 7F08CDE0 14600002 */  bnez  $v1, .L7F08CDEC
/* 0C1914 7F08CDE4 00000000 */   nop   
/* 0C1918 7F08CDE8 0007000D */  break 7
.L7F08CDEC:
/* 0C191C 7F08CDEC 2401FFFF */  li    $at, -1
/* 0C1920 7F08CDF0 14610004 */  bne   $v1, $at, .L7F08CE04
/* 0C1924 7F08CDF4 3C018000 */   lui   $at, 0x8000
/* 0C1928 7F08CDF8 15810002 */  bne   $t4, $at, .L7F08CE04
/* 0C192C 7F08CDFC 00000000 */   nop   
/* 0C1930 7F08CE00 0006000D */  break 6
.L7F08CE04:
/* 0C1934 7F08CE04 1600FFB7 */  bnez  $s0, .L7F08CCE4
/* 0C1938 7F08CE08 00000000 */   nop   
/* 0C193C 7F08CE0C 260D0020 */  addiu $t5, $s0, 0x20
/* 0C1940 7F08CE10 01A3001A */  div   $zero, $t5, $v1
/* 0C1944 7F08CE14 00008010 */  mfhi  $s0
/* 0C1948 7F08CE18 14600002 */  bnez  $v1, .L7F08CE24
/* 0C194C 7F08CE1C 00000000 */   nop   
/* 0C1950 7F08CE20 0007000D */  break 7
.L7F08CE24:
/* 0C1954 7F08CE24 2401FFFF */  li    $at, -1
/* 0C1958 7F08CE28 14610004 */  bne   $v1, $at, .L7F08CE3C
/* 0C195C 7F08CE2C 3C018000 */   lui   $at, 0x8000
/* 0C1960 7F08CE30 15A10002 */  bne   $t5, $at, .L7F08CE3C
/* 0C1964 7F08CE34 00000000 */   nop   
/* 0C1968 7F08CE38 0006000D */  break 6
.L7F08CE3C:
/* 0C196C 7F08CE3C 1000FFA9 */  b     .L7F08CCE4
/* 0C1970 7F08CE40 00000000 */   nop   
.L7F08CE44:
/* 0C1974 7F08CE44 8FAE0028 */  lw    $t6, 0x28($sp)
.L7F08CE48:
/* 0C1978 7F08CE48 ADD10000 */  sw    $s1, ($t6)
/* 0C197C 7F08CE4C 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0C1980 7F08CE50 ADF30000 */  sw    $s3, ($t7)
/* 0C1984 7F08CE54 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C1988 7F08CE58 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C198C 7F08CE5C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C1990 7F08CE60 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C1994 7F08CE64 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C1998 7F08CE68 03E00008 */  jr    $ra
/* 0C199C 7F08CE6C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

s32 inv_has_key_flags(u32 wantkeyflags)
{
    u32 heldkeyflags = 0;
    InvItem *item = pPlayer->ptr_inventory_first_in_cycle;

    while (item) {
        if (item->type == INV_ITEM_PROP) {
            PropRecord *prop = item->type_inv_item.type_prop.prop;

            if (prop->type == PROP_TYPE_OBJ) {
                ObjectRecord *obj = prop->Entityp.obj;

                if (obj->head.type == PROPDEF_KEY) {
                    KeyRecord *key = (KeyRecord *)prop->Entityp.obj;

                    heldkeyflags |= key->keyflags;

                    if ((wantkeyflags & heldkeyflags) == wantkeyflags) {
                        return TRUE;
                    }
                }
            }
        }

        item = item->next;

        if (item == pPlayer->ptr_inventory_first_in_cycle) {
            break;
        }
    }

    return FALSE;
}



s32 checkHasGEKey(void)
{
    InvItem *item;
    PropRecord *prop;
    ObjectRecord *obj;
    
    item = pPlayer->ptr_inventory_first_in_cycle;

    while (item) {

        if (item->type == INV_ITEM_PROP) {

            prop = item->type_inv_item.type_prop.prop;
            
            if (prop->type == PROP_TYPE_WEAPON) {

                obj = prop->Entityp.obj;
                
                if (obj->obj == PROJECTILES_TYPE_GE_KEY) {
                    return TRUE;
               }
            }
        }

        item = item->next;

        if (item == pPlayer->ptr_inventory_first_in_cycle) {
            break;
        }
    }

    return FALSE;
}

/**
 * Is the player alive with flag tag token in inventory
 * @return TRUE/FALSE
 */
int bondinvIsAliveWithFlag(void)
{
    if (!pPlayer->bonddead) {
        return is_item_in_inventory(ITEM_TOKEN);
    }

    return FALSE;
}


/**
 * Is the Golden Gun in inventory
 * @return TRUE/FALSE
 */
int checkforgoldengun(void) 
{
    return is_item_in_inventory(ITEM_GOLDENGUN);
}

int is_prop_in_inventory(PropRecord *prop) {

    InvItem *item = pPlayer->ptr_inventory_first_in_cycle;

    while (item) {

        if (item->type == INV_ITEM_PROP && item->type_inv_item.type_prop.prop == prop) {
            return TRUE;
        }

        item = item->next;

        if (item == pPlayer->ptr_inventory_first_in_cycle) {
            break;
        }
    }

    return FALSE;
}


#ifndef VERSION_EU
s32 count_total_items_in_inventory(void) {

    InvItem *item;
    s32 numitems = 0;

    if (pPlayer->equipallguns) {
        #ifdef VERSION_JP
            numitems = (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS);
        #else
            numitems = ITEM_TANKSHELLS;
        #endif
    }

    item = pPlayer->ptr_inventory_first_in_cycle;

    while (item) {
      
        if (item->type == INV_ITEM_PROP) { 
            
            PropRecord *prop = item->type_inv_item.type_prop.prop;

            if (prop->type == PROP_TYPE_WEAPON) {

                ObjectRecord *obj = prop->Entityp.obj;
     
                if (obj->runtime_bitflags & 0x400) {
                    numitems = numitems + 1;
                }

            } else if (prop->type == PROP_TYPE_OBJ) {

                if ((prop->Entityp.obj->flags2 & 0x40000) == 0) {
                    numitems = numitems + 1;
                }
            }

        } else if (item->type == INV_ITEM_WEAPON) { 
            
            if ((pPlayer->equipallguns == FALSE) || (item->type_inv_item.type_weap.weapon > ITEM_TANKSHELLS)) {
                numitems = numitems + 1;
            }
        }

        item = item->next;

        if (item == pPlayer->ptr_inventory_first_in_cycle) {
            break;
        }
    }

    return numitems;
}
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel count_total_items_in_inventory
/* 0C1B68 7F08D038 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C1B6C 7F08D03C 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C1B70 7F08D040 00001825 */  move  $v1, $zero
/* 0C1B74 7F08D044 3C0B0004 */  lui   $t3, 4
/* 0C1B78 7F08D048 8C4411EC */  lw    $a0, 0x11ec($v0)
/* 0C1B7C 7F08D04C 240A0001 */  li    $t2, 1
/* 0C1B80 7F08D050 24090004 */  li    $t1, 4
/* 0C1B84 7F08D054 10800002 */  beqz  $a0, .L7F08D060
/* 0C1B88 7F08D058 24080002 */   li    $t0, 2
/* 0C1B8C 7F08D05C 24030020 */  li    $v1, 32
.L7F08D060:
/* 0C1B90 7F08D060 8C4611E0 */  lw    $a2, 0x11e0($v0)
/* 0C1B94 7F08D064 10C00026 */  beqz  $a2, .L7F08D100
/* 0C1B98 7F08D068 00C02825 */   move  $a1, $a2
/* 0C1B9C 7F08D06C 8CA20000 */  lw    $v0, ($a1)
.L7F08D070:
/* 0C1BA0 7F08D070 15020015 */  bne   $t0, $v0, .L7F08D0C8
/* 0C1BA4 7F08D074 00000000 */   nop   
/* 0C1BA8 7F08D078 8CA20004 */  lw    $v0, 4($a1)
/* 0C1BAC 7F08D07C 90470000 */  lbu   $a3, ($v0)
/* 0C1BB0 7F08D080 15270008 */  bne   $t1, $a3, .L7F08D0A4
/* 0C1BB4 7F08D084 00000000 */   nop   
/* 0C1BB8 7F08D088 8C470004 */  lw    $a3, 4($v0)
/* 0C1BBC 7F08D08C 8CEE0064 */  lw    $t6, 0x64($a3)
/* 0C1BC0 7F08D090 31CF0400 */  andi  $t7, $t6, 0x400
/* 0C1BC4 7F08D094 51E00016 */  beql  $t7, $zero, .L7F08D0F0
/* 0C1BC8 7F08D098 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1BCC 7F08D09C 10000013 */  b     .L7F08D0EC
/* 0C1BD0 7F08D0A0 24630001 */   addiu $v1, $v1, 1
.L7F08D0A4:
/* 0C1BD4 7F08D0A4 55470012 */  bnel  $t2, $a3, .L7F08D0F0
/* 0C1BD8 7F08D0A8 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1BDC 7F08D0AC 8C580004 */  lw    $t8, 4($v0)
/* 0C1BE0 7F08D0B0 8F19000C */  lw    $t9, 0xc($t8)
/* 0C1BE4 7F08D0B4 032B6024 */  and   $t4, $t9, $t3
/* 0C1BE8 7F08D0B8 5580000D */  bnezl $t4, .L7F08D0F0
/* 0C1BEC 7F08D0BC 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1BF0 7F08D0C0 1000000A */  b     .L7F08D0EC
/* 0C1BF4 7F08D0C4 24630001 */   addiu $v1, $v1, 1
.L7F08D0C8:
/* 0C1BF8 7F08D0C8 55420009 */  bnel  $t2, $v0, .L7F08D0F0
/* 0C1BFC 7F08D0CC 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1C00 7F08D0D0 50800006 */  beql  $a0, $zero, .L7F08D0EC
/* 0C1C04 7F08D0D4 24630001 */   addiu $v1, $v1, 1
/* 0C1C08 7F08D0D8 8CAD0004 */  lw    $t5, 4($a1)
/* 0C1C0C 7F08D0DC 29A10021 */  slti  $at, $t5, 0x21
/* 0C1C10 7F08D0E0 54200003 */  bnezl $at, .L7F08D0F0
/* 0C1C14 7F08D0E4 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1C18 7F08D0E8 24630001 */  addiu $v1, $v1, 1
.L7F08D0EC:
/* 0C1C1C 7F08D0EC 8CA5000C */  lw    $a1, 0xc($a1)
.L7F08D0F0:
/* 0C1C20 7F08D0F0 10A60003 */  beq   $a1, $a2, .L7F08D100
/* 0C1C24 7F08D0F4 00000000 */   nop   
/* 0C1C28 7F08D0F8 54A0FFDD */  bnezl $a1, .L7F08D070
/* 0C1C2C 7F08D0FC 8CA20000 */   lw    $v0, ($a1)
.L7F08D100:
/* 0C1C30 7F08D100 03E00008 */  jr    $ra
/* 0C1C34 7F08D104 00601025 */   move  $v0, $v1
)
#endif


#ifndef VERSION_EU
InvItem *inv_get_item_by_index(s32 index)
{
    InvItem *item;

    if (pPlayer->equipallguns) {

#ifdef VERSION_JP
        if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS)) {
#else
        if (index < ITEM_TANKSHELLS) {
#endif
            return NULL;
        }

#ifdef VERSION_JP
        index = index - (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS);
#else
        index = index - ITEM_TANKSHELLS;
#endif
    }

    item = pPlayer->ptr_inventory_first_in_cycle;

    while (item) {
        
        if (item->type == INV_ITEM_PROP) {
            
            PropRecord *prop = item->type_inv_item.type_prop.prop;

            if (prop->type == PROP_TYPE_WEAPON) {

                ObjectRecord *obj = prop->Entityp.obj;
                
                if (obj->runtime_bitflags & 0x400) {
                    if (index == 0) {
                        return item;
                    }
                    index--;
                }

            } else if (prop->type == PROP_TYPE_OBJ) {
                
                if ((prop->Entityp.obj->flags2 & 0x40000) == 0) {
                    if (index == 0) {
                        return item;
                    }
                    index--;
                }
            }
            
        } else if (item->type == INV_ITEM_WEAPON) {

            if ((pPlayer->equipallguns == FALSE) || ( item->type_inv_item.type_weap.weapon > ITEM_TANKSHELLS)) {
                if (index == 0) {
                    return item;
                }
                index--;
            }
        }

        item = item->next;

        if (item == pPlayer->ptr_inventory_first_in_cycle) {
            break;
        }
    }

    return NULL;
}
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel inv_get_item_by_index
/* 0C1C38 7F08D108 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C1C3C 7F08D10C 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C1C40 7F08D110 28810020 */  slti  $at, $a0, 0x20
/* 0C1C44 7F08D114 8C4311EC */  lw    $v1, 0x11ec($v0)
/* 0C1C48 7F08D118 50600006 */  beql  $v1, $zero, .L7F08D134
/* 0C1C4C 7F08D11C 8C4611E0 */   lw    $a2, 0x11e0($v0)
/* 0C1C50 7F08D120 10200003 */  beqz  $at, .L7F08D130
/* 0C1C54 7F08D124 2484FFE0 */   addiu $a0, $a0, -0x20
/* 0C1C58 7F08D128 03E00008 */  jr    $ra
/* 0C1C5C 7F08D12C 00001025 */   move  $v0, $zero

.L7F08D130:
/* 0C1C60 7F08D130 8C4611E0 */  lw    $a2, 0x11e0($v0)
.L7F08D134:
/* 0C1C64 7F08D134 3C0B0004 */  lui   $t3, 4
/* 0C1C68 7F08D138 240A0001 */  li    $t2, 1
/* 0C1C6C 7F08D13C 10C00034 */  beqz  $a2, .L7F08D210
/* 0C1C70 7F08D140 00C02825 */   move  $a1, $a2
/* 0C1C74 7F08D144 24090004 */  li    $t1, 4
/* 0C1C78 7F08D148 24080002 */  li    $t0, 2
/* 0C1C7C 7F08D14C 8CA20000 */  lw    $v0, ($a1)
.L7F08D150:
/* 0C1C80 7F08D150 1502001D */  bne   $t0, $v0, .L7F08D1C8
/* 0C1C84 7F08D154 00000000 */   nop   
/* 0C1C88 7F08D158 8CA20004 */  lw    $v0, 4($a1)
/* 0C1C8C 7F08D15C 90470000 */  lbu   $a3, ($v0)
/* 0C1C90 7F08D160 1527000C */  bne   $t1, $a3, .L7F08D194
/* 0C1C94 7F08D164 00000000 */   nop   
/* 0C1C98 7F08D168 8C470004 */  lw    $a3, 4($v0)
/* 0C1C9C 7F08D16C 8CEE0064 */  lw    $t6, 0x64($a3)
/* 0C1CA0 7F08D170 31CF0400 */  andi  $t7, $t6, 0x400
/* 0C1CA4 7F08D174 51E00022 */  beql  $t7, $zero, .L7F08D200
/* 0C1CA8 7F08D178 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1CAC 7F08D17C 14800003 */  bnez  $a0, .L7F08D18C
/* 0C1CB0 7F08D180 00000000 */   nop   
/* 0C1CB4 7F08D184 03E00008 */  jr    $ra
/* 0C1CB8 7F08D188 00A01025 */   move  $v0, $a1

.L7F08D18C:
/* 0C1CBC 7F08D18C 1000001B */  b     .L7F08D1FC
/* 0C1CC0 7F08D190 2484FFFF */   addiu $a0, $a0, -1
.L7F08D194:
/* 0C1CC4 7F08D194 5547001A */  bnel  $t2, $a3, .L7F08D200
/* 0C1CC8 7F08D198 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1CCC 7F08D19C 8C580004 */  lw    $t8, 4($v0)
/* 0C1CD0 7F08D1A0 8F19000C */  lw    $t9, 0xc($t8)
/* 0C1CD4 7F08D1A4 032B6024 */  and   $t4, $t9, $t3
/* 0C1CD8 7F08D1A8 55800015 */  bnezl $t4, .L7F08D200
/* 0C1CDC 7F08D1AC 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1CE0 7F08D1B0 14800003 */  bnez  $a0, .L7F08D1C0
/* 0C1CE4 7F08D1B4 00000000 */   nop   
/* 0C1CE8 7F08D1B8 03E00008 */  jr    $ra
/* 0C1CEC 7F08D1BC 00A01025 */   move  $v0, $a1

.L7F08D1C0:
/* 0C1CF0 7F08D1C0 1000000E */  b     .L7F08D1FC
/* 0C1CF4 7F08D1C4 2484FFFF */   addiu $a0, $a0, -1
.L7F08D1C8:
/* 0C1CF8 7F08D1C8 5542000D */  bnel  $t2, $v0, .L7F08D200
/* 0C1CFC 7F08D1CC 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1D00 7F08D1D0 10600005 */  beqz  $v1, .L7F08D1E8
/* 0C1D04 7F08D1D4 00000000 */   nop   
/* 0C1D08 7F08D1D8 8CAD0004 */  lw    $t5, 4($a1)
/* 0C1D0C 7F08D1DC 29A10021 */  slti  $at, $t5, 0x21
/* 0C1D10 7F08D1E0 54200007 */  bnezl $at, .L7F08D200
/* 0C1D14 7F08D1E4 8CA5000C */   lw    $a1, 0xc($a1)
.L7F08D1E8:
/* 0C1D18 7F08D1E8 54800004 */  bnezl $a0, .L7F08D1FC
/* 0C1D1C 7F08D1EC 2484FFFF */   addiu $a0, $a0, -1
/* 0C1D20 7F08D1F0 03E00008 */  jr    $ra
/* 0C1D24 7F08D1F4 00A01025 */   move  $v0, $a1

/* 0C1D28 7F08D1F8 2484FFFF */  addiu $a0, $a0, -1
.L7F08D1FC:
/* 0C1D2C 7F08D1FC 8CA5000C */  lw    $a1, 0xc($a1)
.L7F08D200:
/* 0C1D30 7F08D200 50A60004 */  beql  $a1, $a2, .L7F08D214
/* 0C1D34 7F08D204 00001025 */   move  $v0, $zero
/* 0C1D38 7F08D208 54A0FFD1 */  bnezl $a1, .L7F08D150
/* 0C1D3C 7F08D20C 8CA20000 */   lw    $v0, ($a1)
.L7F08D210:
/* 0C1D40 7F08D210 00001025 */  move  $v0, $zero
.L7F08D214:
/* 0C1D44 7F08D214 03E00008 */  jr    $ra
/* 0C1D48 7F08D218 00000000 */   nop   
)
#endif




textoverride *get_textoverride_by_obj(ObjectRecord *obj) {
    
    textoverride *override = pPlayer->textoverrides;

    while (override) {
      
        if (override->obj == obj) {
            return override;
        }
      
        override = override->next;
    }

    return NULL;
}

textoverride *get_textoverride_by_weaponum(ITEM_IDS weaponnum) {
    
    textoverride *override = pPlayer->textoverrides;

    while (override) {
      
        if ((override->objoffset == 0) && (override->weapon == weaponnum)) {
            return override;
        }
      
        override = override->next;
    }

    return NULL;
}


s32 get_weaponnum_by_inv_index(s32 index) {

    textoverride *override;
    InvItem *inv_item;

    inv_item = inv_get_item_by_index(index);
    
    if (inv_item) {

        if (inv_item->type == INV_ITEM_PROP) {

            PropRecord *prop = inv_item->type_inv_item.type_prop.prop;
            
            override = get_textoverride_by_obj(prop->Entityp.obj);
            
            if (override) {
                return override->weapon;
            }

        } else if (inv_item->type == INV_ITEM_WEAPON) {
            return inv_item->type_inv_item.type_weap.weapon;
        }

    } else { 
    
        if (pPlayer->equipallguns) {
#ifdef VERSION_JP
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return index + 2;
                }

                return index + 1;
            }
#else
           if (index < ITEM_TANKSHELLS) {
               return index + 1;
           }
#endif
        }
    }
    
    return 0;
}

#ifndef VERSION_EU
u16 *inv_get_name_by_index(s32 index) {
    
    InvItem *item = inv_get_item_by_index(index);
    ITEM_IDS weaponnum = 0;
    textoverride *override;

    if (item) {

        if (item->type == INV_ITEM_PROP) {
            
            PropRecord *prop = item->type_inv_item.type_prop.prop;
            override = get_textoverride_by_obj(prop->Entityp.obj);

            if (override) {
                
                if (override->unk6) {
                    return get_textptr_for_textID(override->unk6);
                }

                weaponnum = override->weapon;
            }

        } else if (item->type == INV_ITEM_WEAPON) {
            
            weaponnum = item->type_inv_item.type_weap.weapon;
            override = get_textoverride_by_weaponum(weaponnum);

            if (override && override->unk6) {
                return get_textptr_for_textID(override->unk6);
            }
        }

    } else { 
    
        if (pPlayer->equipallguns) {
#ifdef VERSION_JP
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return get_ptr_short_watch_text_for_item(index + 2);
                }

                return get_ptr_short_watch_text_for_item(index + 1);
            }
#else
           if (index < ITEM_TANKSHELLS) {
               return get_ptr_short_watch_text_for_item(index + 1);
           }
#endif
        }
    }

    return get_ptr_short_watch_text_for_item(weaponnum);
}
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel inv_get_name_by_index
/* 0C1E70 7F08D340 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C1E74 7F08D344 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C1E78 7F08D348 0FC23442 */  jal   inv_get_item_by_index
/* 0C1E7C 7F08D34C AFA40020 */   sw    $a0, 0x20($sp)
/* 0C1E80 7F08D350 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C1E84 7F08D354 00401825 */  move  $v1, $v0
/* 0C1E88 7F08D358 10400024 */  beqz  $v0, .L7F08D3EC
/* 0C1E8C 7F08D35C 00003025 */   move  $a2, $zero
/* 0C1E90 7F08D360 8C440000 */  lw    $a0, ($v0)
/* 0C1E94 7F08D364 24010002 */  li    $at, 2
/* 0C1E98 7F08D368 54810012 */  bnel  $a0, $at, .L7F08D3B4
/* 0C1E9C 7F08D36C 24010001 */   li    $at, 1
/* 0C1EA0 7F08D370 8C420004 */  lw    $v0, 4($v0)
/* 0C1EA4 7F08D374 8C440004 */  lw    $a0, 4($v0)
/* 0C1EA8 7F08D378 0FC23487 */  jal   get_textoverride_by_obj
/* 0C1EAC 7F08D37C AFA00018 */   sw    $zero, 0x18($sp)
/* 0C1EB0 7F08D380 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C1EB4 7F08D384 10400025 */  beqz  $v0, .L7F08D41C
/* 0C1EB8 7F08D388 00401825 */   move  $v1, $v0
/* 0C1EBC 7F08D38C 8C4E0014 */  lw    $t6, 0x14($v0)
/* 0C1EC0 7F08D390 11C00005 */  beqz  $t6, .L7F08D3A8
/* 0C1EC4 7F08D394 00000000 */   nop   
/* 0C1EC8 7F08D398 0FC30776 */  jal   get_textptr_for_textID
/* 0C1ECC 7F08D39C 8C640014 */   lw    $a0, 0x14($v1)
/* 0C1ED0 7F08D3A0 10000021 */  b     .L7F08D428
/* 0C1ED4 7F08D3A4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D3A8:
/* 0C1ED8 7F08D3A8 1000001C */  b     .L7F08D41C
/* 0C1EDC 7F08D3AC 8C460008 */   lw    $a2, 8($v0)
/* 0C1EE0 7F08D3B0 24010001 */  li    $at, 1
.L7F08D3B4:
/* 0C1EE4 7F08D3B4 14810019 */  bne   $a0, $at, .L7F08D41C
/* 0C1EE8 7F08D3B8 00000000 */   nop   
/* 0C1EEC 7F08D3BC 8C640004 */  lw    $a0, 4($v1)
/* 0C1EF0 7F08D3C0 0FC23497 */  jal   get_textoverride_by_weaponum
/* 0C1EF4 7F08D3C4 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C1EF8 7F08D3C8 10400014 */  beqz  $v0, .L7F08D41C
/* 0C1EFC 7F08D3CC 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C1F00 7F08D3D0 8C4F0014 */  lw    $t7, 0x14($v0)
/* 0C1F04 7F08D3D4 11E00011 */  beqz  $t7, .L7F08D41C
/* 0C1F08 7F08D3D8 00000000 */   nop   
/* 0C1F0C 7F08D3DC 0FC30776 */  jal   get_textptr_for_textID
/* 0C1F10 7F08D3E0 8C440014 */   lw    $a0, 0x14($v0)
/* 0C1F14 7F08D3E4 10000010 */  b     .L7F08D428
/* 0C1F18 7F08D3E8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D3EC:
/* 0C1F1C 7F08D3EC 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C1F20 7F08D3F0 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C1F24 7F08D3F4 28A10020 */  slti  $at, $a1, 0x20
/* 0C1F28 7F08D3F8 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C1F2C 7F08D3FC 13200007 */  beqz  $t9, .L7F08D41C
/* 0C1F30 7F08D400 00000000 */   nop   
/* 0C1F34 7F08D404 10200005 */  beqz  $at, .L7F08D41C
/* 0C1F38 7F08D408 00000000 */   nop   
/* 0C1F3C 7F08D40C 0FC19C2A */  jal   get_ptr_short_watch_text_for_item
/* 0C1F40 7F08D410 24A40001 */   addiu $a0, $a1, 1
/* 0C1F44 7F08D414 10000004 */  b     .L7F08D428
/* 0C1F48 7F08D418 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D41C:
/* 0C1F4C 7F08D41C 0FC19C2A */  jal   get_ptr_short_watch_text_for_item
/* 0C1F50 7F08D420 00C02025 */   move  $a0, $a2
/* 0C1F54 7F08D424 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D428:
/* 0C1F58 7F08D428 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C1F5C 7F08D42C 03E00008 */  jr    $ra
/* 0C1F60 7F08D430 00000000 */   nop   
)
#endif



#ifndef VERSION_EU
u16 *inv_get_long_name_by_index(s32 index) {
    
    InvItem *item = inv_get_item_by_index(index);
    ITEM_IDS weaponnum = 0;
    textoverride *override;

    if (item) {

        if (item->type == INV_ITEM_PROP) {
            
            PropRecord *prop = item->type_inv_item.type_prop.prop;
            override = get_textoverride_by_obj(prop->Entityp.obj);

            if (override) {
                
                if (override->unk7) {
                    return get_textptr_for_textID(override->unk7);
                }

                weaponnum = override->weapon;
            }

        } else if (item->type == INV_ITEM_WEAPON) {
            
            weaponnum = item->type_inv_item.type_weap.weapon;
            override = get_textoverride_by_weaponum(weaponnum);

            if (override && override->unk7) {
                return get_textptr_for_textID(override->unk7);
            }
        }

    } else { 
    
        if (pPlayer->equipallguns) {
#ifdef VERSION_JP
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return get_ptr_long_watch_text_for_item(index + 2);
                }

                return get_ptr_long_watch_text_for_item(index + 1);
            }
#else
           if (index < ITEM_TANKSHELLS) {
               return get_ptr_long_watch_text_for_item(index + 1);
           }
#endif
        }
    }

    return get_ptr_long_watch_text_for_item(weaponnum);
}
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel inv_get_long_name_by_index
/* 0C1F64 7F08D434 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C1F68 7F08D438 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C1F6C 7F08D43C 0FC23442 */  jal   inv_get_item_by_index
/* 0C1F70 7F08D440 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C1F74 7F08D444 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C1F78 7F08D448 00401825 */  move  $v1, $v0
/* 0C1F7C 7F08D44C 10400024 */  beqz  $v0, .L7F08D4E0
/* 0C1F80 7F08D450 00003025 */   move  $a2, $zero
/* 0C1F84 7F08D454 8C440000 */  lw    $a0, ($v0)
/* 0C1F88 7F08D458 24010002 */  li    $at, 2
/* 0C1F8C 7F08D45C 54810012 */  bnel  $a0, $at, .L7F08D4A8
/* 0C1F90 7F08D460 24010001 */   li    $at, 1
/* 0C1F94 7F08D464 8C420004 */  lw    $v0, 4($v0)
/* 0C1F98 7F08D468 8C440004 */  lw    $a0, 4($v0)
/* 0C1F9C 7F08D46C 0FC23487 */  jal   get_textoverride_by_obj
/* 0C1FA0 7F08D470 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C1FA4 7F08D474 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C1FA8 7F08D478 10400025 */  beqz  $v0, .L7F08D510
/* 0C1FAC 7F08D47C 00401825 */   move  $v1, $v0
/* 0C1FB0 7F08D480 8C4E0018 */  lw    $t6, 0x18($v0)
/* 0C1FB4 7F08D484 11C00005 */  beqz  $t6, .L7F08D49C
/* 0C1FB8 7F08D488 00000000 */   nop   
/* 0C1FBC 7F08D48C 0FC30776 */  jal   get_textptr_for_textID
/* 0C1FC0 7F08D490 8C640018 */   lw    $a0, 0x18($v1)
/* 0C1FC4 7F08D494 10000021 */  b     .L7F08D51C
/* 0C1FC8 7F08D498 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D49C:
/* 0C1FCC 7F08D49C 1000001C */  b     .L7F08D510
/* 0C1FD0 7F08D4A0 8C460008 */   lw    $a2, 8($v0)
/* 0C1FD4 7F08D4A4 24010001 */  li    $at, 1
.L7F08D4A8:
/* 0C1FD8 7F08D4A8 14810019 */  bne   $a0, $at, .L7F08D510
/* 0C1FDC 7F08D4AC 00000000 */   nop   
/* 0C1FE0 7F08D4B0 8C640004 */  lw    $a0, 4($v1)
/* 0C1FE4 7F08D4B4 0FC23497 */  jal   get_textoverride_by_weaponum
/* 0C1FE8 7F08D4B8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C1FEC 7F08D4BC 10400014 */  beqz  $v0, .L7F08D510
/* 0C1FF0 7F08D4C0 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C1FF4 7F08D4C4 8C4F0018 */  lw    $t7, 0x18($v0)
/* 0C1FF8 7F08D4C8 11E00011 */  beqz  $t7, .L7F08D510
/* 0C1FFC 7F08D4CC 00000000 */   nop   
/* 0C2000 7F08D4D0 0FC30776 */  jal   get_textptr_for_textID
/* 0C2004 7F08D4D4 8C440018 */   lw    $a0, 0x18($v0)
/* 0C2008 7F08D4D8 10000010 */  b     .L7F08D51C
/* 0C200C 7F08D4DC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D4E0:
/* 0C2010 7F08D4E0 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C2014 7F08D4E4 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C2018 7F08D4E8 28A10020 */  slti  $at, $a1, 0x20
/* 0C201C 7F08D4EC 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C2020 7F08D4F0 13200007 */  beqz  $t9, .L7F08D510
/* 0C2024 7F08D4F4 00000000 */   nop   
/* 0C2028 7F08D4F8 10200005 */  beqz  $at, .L7F08D510
/* 0C202C 7F08D4FC 00000000 */   nop   
/* 0C2030 7F08D500 0FC19C37 */  jal   get_ptr_long_watch_text_for_item
/* 0C2034 7F08D504 24A40001 */   addiu $a0, $a1, 1
/* 0C2038 7F08D508 10000004 */  b     .L7F08D51C
/* 0C203C 7F08D50C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D510:
/* 0C2040 7F08D510 0FC19C37 */  jal   get_ptr_long_watch_text_for_item
/* 0C2044 7F08D514 00C02025 */   move  $a0, $a2
/* 0C2048 7F08D518 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D51C:
/* 0C204C 7F08D51C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C2050 7F08D520 03E00008 */  jr    $ra
/* 0C2054 7F08D524 00000000 */   nop   
)
#endif




int sub_GAME_7F08D528(int index) {
    return get_45_degree_angle_0(get_weaponnum_by_inv_index(index));
}






int sub_GAME_7F08D550(int index) {
    return get_horizontal_offset_on_solo_watch_menu_for_item(get_weaponnum_by_inv_index(index));
}





int sub_GAME_7F08D578(int index) {
    return get_vertical_offset_on_solo_watch_menu_for_item(get_weaponnum_by_inv_index(index));
}





int sub_GAME_7F08D5A0(int index) {
    return get_depth_offset_solo_watch_menu_inventory_page_for_item(get_weaponnum_by_inv_index(index));
}

#ifndef VERSION_EU
u16 *inv_get_first_title_name_by_index(s32 index) {
    
    InvItem *item = inv_get_item_by_index(index);
    ITEM_IDS weaponnum = 0;
    textoverride *override;

    if (item) {

        if (item->type == INV_ITEM_PROP) {
            
            PropRecord *prop = item->type_inv_item.type_prop.prop;
            override = get_textoverride_by_obj(prop->Entityp.obj);

            if (override) {
                
                if (override->unk4) {
                    return get_textptr_for_textID(override->unk4);
                }

                weaponnum = override->weapon;
            }

        } else if (item->type == INV_ITEM_WEAPON) {
            
            weaponnum = item->type_inv_item.type_weap.weapon;
            override = get_textoverride_by_weaponum(weaponnum);

            if (override && override->unk4) {
                return get_textptr_for_textID(override->unk4);
            }
        }

    } else { 
    
        if (pPlayer->equipallguns) {
#ifdef VERSION_JP
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return get_ptr_first_title_line_item(index + 2);
                }

                return get_ptr_first_title_line_item(index + 1);
            }
#else
           if (index < ITEM_TANKSHELLS) {
               return get_ptr_first_title_line_item(index + 1);
           }
#endif
        }
    }

    return get_ptr_first_title_line_item(weaponnum);
}
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel inv_get_first_title_name_by_index
/* 0C20F8 7F08D5C8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C20FC 7F08D5CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2100 7F08D5D0 0FC23442 */  jal   inv_get_item_by_index
/* 0C2104 7F08D5D4 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C2108 7F08D5D8 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C210C 7F08D5DC 00401825 */  move  $v1, $v0
/* 0C2110 7F08D5E0 10400024 */  beqz  $v0, .L7F08D674
/* 0C2114 7F08D5E4 00003025 */   move  $a2, $zero
/* 0C2118 7F08D5E8 8C440000 */  lw    $a0, ($v0)
/* 0C211C 7F08D5EC 24010002 */  li    $at, 2
/* 0C2120 7F08D5F0 54810012 */  bnel  $a0, $at, .L7F08D63C
/* 0C2124 7F08D5F4 24010001 */   li    $at, 1
/* 0C2128 7F08D5F8 8C420004 */  lw    $v0, 4($v0)
/* 0C212C 7F08D5FC 8C440004 */  lw    $a0, 4($v0)
/* 0C2130 7F08D600 0FC23487 */  jal   get_textoverride_by_obj
/* 0C2134 7F08D604 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C2138 7F08D608 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C213C 7F08D60C 10400025 */  beqz  $v0, .L7F08D6A4
/* 0C2140 7F08D610 00401825 */   move  $v1, $v0
/* 0C2144 7F08D614 8C4E000C */  lw    $t6, 0xc($v0)
/* 0C2148 7F08D618 11C00005 */  beqz  $t6, .L7F08D630
/* 0C214C 7F08D61C 00000000 */   nop   
/* 0C2150 7F08D620 0FC30776 */  jal   get_textptr_for_textID
/* 0C2154 7F08D624 8C64000C */   lw    $a0, 0xc($v1)
/* 0C2158 7F08D628 10000021 */  b     .L7F08D6B0
/* 0C215C 7F08D62C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D630:
/* 0C2160 7F08D630 1000001C */  b     .L7F08D6A4
/* 0C2164 7F08D634 8C460008 */   lw    $a2, 8($v0)
/* 0C2168 7F08D638 24010001 */  li    $at, 1
.L7F08D63C:
/* 0C216C 7F08D63C 14810019 */  bne   $a0, $at, .L7F08D6A4
/* 0C2170 7F08D640 00000000 */   nop   
/* 0C2174 7F08D644 8C640004 */  lw    $a0, 4($v1)
/* 0C2178 7F08D648 0FC23497 */  jal   get_textoverride_by_weaponum
/* 0C217C 7F08D64C AFA40018 */   sw    $a0, 0x18($sp)
/* 0C2180 7F08D650 10400014 */  beqz  $v0, .L7F08D6A4
/* 0C2184 7F08D654 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C2188 7F08D658 8C4F000C */  lw    $t7, 0xc($v0)
/* 0C218C 7F08D65C 11E00011 */  beqz  $t7, .L7F08D6A4
/* 0C2190 7F08D660 00000000 */   nop   
/* 0C2194 7F08D664 0FC30776 */  jal   get_textptr_for_textID
/* 0C2198 7F08D668 8C44000C */   lw    $a0, 0xc($v0)
/* 0C219C 7F08D66C 10000010 */  b     .L7F08D6B0
/* 0C21A0 7F08D670 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D674:
/* 0C21A4 7F08D674 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C21A8 7F08D678 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C21AC 7F08D67C 28A10020 */  slti  $at, $a1, 0x20
/* 0C21B0 7F08D680 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C21B4 7F08D684 13200007 */  beqz  $t9, .L7F08D6A4
/* 0C21B8 7F08D688 00000000 */   nop   
/* 0C21BC 7F08D68C 10200005 */  beqz  $at, .L7F08D6A4
/* 0C21C0 7F08D690 00000000 */   nop   
/* 0C21C4 7F08D694 0FC19C10 */  jal   get_ptr_first_title_line_item
/* 0C21C8 7F08D698 24A40001 */   addiu $a0, $a1, 1
/* 0C21CC 7F08D69C 10000004 */  b     .L7F08D6B0
/* 0C21D0 7F08D6A0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D6A4:
/* 0C21D4 7F08D6A4 0FC19C10 */  jal   get_ptr_first_title_line_item
/* 0C21D8 7F08D6A8 00C02025 */   move  $a0, $a2
/* 0C21DC 7F08D6AC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D6B0:
/* 0C21E0 7F08D6B0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C21E4 7F08D6B4 03E00008 */  jr    $ra
/* 0C21E8 7F08D6B8 00000000 */   nop   
)
#endif




#ifndef VERSION_EU
u16 *inv_get_second_title_name_by_index(s32 index) {
    
    InvItem *item = inv_get_item_by_index(index);
    ITEM_IDS weaponnum = 0;
    textoverride *override;

    if (item) {

        if (item->type == INV_ITEM_PROP) {
            
            PropRecord *prop = item->type_inv_item.type_prop.prop;
            override = get_textoverride_by_obj(prop->Entityp.obj);

            if (override) {
                
                if (override->unk5) {
                    return get_textptr_for_textID(override->unk5);
                }

                weaponnum = override->weapon;
            }

        } else if (item->type == INV_ITEM_WEAPON) {
            
            weaponnum = item->type_inv_item.type_weap.weapon;
            override = get_textoverride_by_weaponum(weaponnum);

            if (override && override->unk5) {
                return get_textptr_for_textID(override->unk5);
            }
        }

    } else { 
    
        if (pPlayer->equipallguns) {
#ifdef VERSION_JP
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return get_ptr_second_title_line_item(index + 2);
                }

                return get_ptr_second_title_line_item(index + 1);
            }
#else
           if (index < ITEM_TANKSHELLS) {
               return get_ptr_second_title_line_item(index + 1);
           }
#endif
        }
    }

    return get_ptr_second_title_line_item(weaponnum);
}
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel inv_get_second_title_name_by_index
/* 0C21EC 7F08D6BC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C21F0 7F08D6C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C21F4 7F08D6C4 0FC23442 */  jal   inv_get_item_by_index
/* 0C21F8 7F08D6C8 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C21FC 7F08D6CC 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C2200 7F08D6D0 00401825 */  move  $v1, $v0
/* 0C2204 7F08D6D4 10400024 */  beqz  $v0, .L7F08D768
/* 0C2208 7F08D6D8 00003025 */   move  $a2, $zero
/* 0C220C 7F08D6DC 8C440000 */  lw    $a0, ($v0)
/* 0C2210 7F08D6E0 24010002 */  li    $at, 2
/* 0C2214 7F08D6E4 54810012 */  bnel  $a0, $at, .L7F08D730
/* 0C2218 7F08D6E8 24010001 */   li    $at, 1
/* 0C221C 7F08D6EC 8C420004 */  lw    $v0, 4($v0)
/* 0C2220 7F08D6F0 8C440004 */  lw    $a0, 4($v0)
/* 0C2224 7F08D6F4 0FC23487 */  jal   get_textoverride_by_obj
/* 0C2228 7F08D6F8 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C222C 7F08D6FC 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C2230 7F08D700 10400025 */  beqz  $v0, .L7F08D798
/* 0C2234 7F08D704 00401825 */   move  $v1, $v0
/* 0C2238 7F08D708 8C4E0010 */  lw    $t6, 0x10($v0)
/* 0C223C 7F08D70C 11C00005 */  beqz  $t6, .L7F08D724
/* 0C2240 7F08D710 00000000 */   nop   
/* 0C2244 7F08D714 0FC30776 */  jal   get_textptr_for_textID
/* 0C2248 7F08D718 8C640010 */   lw    $a0, 0x10($v1)
/* 0C224C 7F08D71C 10000021 */  b     .L7F08D7A4
/* 0C2250 7F08D720 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D724:
/* 0C2254 7F08D724 1000001C */  b     .L7F08D798
/* 0C2258 7F08D728 8C460008 */   lw    $a2, 8($v0)
/* 0C225C 7F08D72C 24010001 */  li    $at, 1
.L7F08D730:
/* 0C2260 7F08D730 14810019 */  bne   $a0, $at, .L7F08D798
/* 0C2264 7F08D734 00000000 */   nop   
/* 0C2268 7F08D738 8C640004 */  lw    $a0, 4($v1)
/* 0C226C 7F08D73C 0FC23497 */  jal   get_textoverride_by_weaponum
/* 0C2270 7F08D740 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C2274 7F08D744 10400014 */  beqz  $v0, .L7F08D798
/* 0C2278 7F08D748 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C227C 7F08D74C 8C4F0010 */  lw    $t7, 0x10($v0)
/* 0C2280 7F08D750 11E00011 */  beqz  $t7, .L7F08D798
/* 0C2284 7F08D754 00000000 */   nop   
/* 0C2288 7F08D758 0FC30776 */  jal   get_textptr_for_textID
/* 0C228C 7F08D75C 8C440010 */   lw    $a0, 0x10($v0)
/* 0C2290 7F08D760 10000010 */  b     .L7F08D7A4
/* 0C2294 7F08D764 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D768:
/* 0C2298 7F08D768 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C229C 7F08D76C 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C22A0 7F08D770 28A10020 */  slti  $at, $a1, 0x20
/* 0C22A4 7F08D774 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C22A8 7F08D778 13200007 */  beqz  $t9, .L7F08D798
/* 0C22AC 7F08D77C 00000000 */   nop   
/* 0C22B0 7F08D780 10200005 */  beqz  $at, .L7F08D798
/* 0C22B4 7F08D784 00000000 */   nop   
/* 0C22B8 7F08D788 0FC19C1D */  jal   get_ptr_second_title_line_item
/* 0C22BC 7F08D78C 24A40001 */   addiu $a0, $a1, 1
/* 0C22C0 7F08D790 10000004 */  b     .L7F08D7A4
/* 0C22C4 7F08D794 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D798:
/* 0C22C8 7F08D798 0FC19C1D */  jal   get_ptr_second_title_line_item
/* 0C22CC 7F08D79C 00C02025 */   move  $a0, $a2
/* 0C22D0 7F08D7A0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D7A4:
/* 0C22D4 7F08D7A4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C22D8 7F08D7A8 03E00008 */  jr    $ra
/* 0C22DC 7F08D7AC 00000000 */   nop   
)
#endif



int sub_GAME_7F08D7B0(int index) {
    return get_45_degree_angle(get_weaponnum_by_inv_index(index));
}





int sub_GAME_7F08D7D8(int index) {
    return get_vertical_position_solo_watch_menu_main_page_for_item(get_weaponnum_by_inv_index(index));
}




int sub_GAME_7F08D800(int index) {
    return get_lateral_position_solo_watch_menu_main_page_for_item(get_weaponnum_by_inv_index(index));
}





int sub_GAME_7F08D828(int index) {
    return get_depth_on_solo_watch_menu_page_for_item(get_weaponnum_by_inv_index(index));
}





int sub_GAME_7F08D850(int index) {
    return get_xrotation_solo_watch_menu_for_item(get_weaponnum_by_inv_index(index));
}





int sub_GAME_7F08D878(int index) {
    return get_yrotation_solo_watch_menu_for_item(get_weaponnum_by_inv_index(index));
}



void sub_GAME_7F08D8A0(textoverride *override) {
  override->next = pPlayer->textoverrides;
  pPlayer->textoverrides = override;
}

int get_BONDdata_equipcuritem(void) {
  return pPlayer->equipcuritem;
}


void set_BONDdata_equipcuritem(int current_item) {
    pPlayer->equipcuritem = current_item;
}

void calculate_equip_cur_item(void) {
    s32 current_weapon;
    s32 i;

    current_weapon = get_item_in_hand(RIGHT_HAND);
    
    pPlayer->equipcuritem = 0;

    for (i=0; i < count_total_items_in_inventory(); i++) {
        
        if (get_weaponnum_by_inv_index(i) == current_weapon) {
            pPlayer->equipcuritem = i;
            return;
        }

    }
}


u8 *obj_get_activated_text(ObjectRecord *obj) {

    textoverride *override = get_textoverride_by_obj(obj);

    if (override && override->unk8) {
        return get_textptr_for_textID(override->unk8);
    }

    return NULL;
}

u8 *weapon_get_activated_text(ITEM_IDS weaponnum) {
    
    textoverride *override = get_textoverride_by_weaponum(weaponnum);

    if (override && override->unk8) {
        return get_textptr_for_textID(override->unk8);
    }
    
    return NULL;
}


void increment_held_time(s32 weapon1, s32 weapon2)
{
    s32 leastusedtime;
    s32 leastusedindex;
    s32 i;

    if (!bondwalkItemCheckBitflags(weapon1, 0x20000)) {
        return;
    }

    leastusedtime = 0x7fffffff;
    leastusedindex = 0;

    if (!bondwalkItemCheckBitflags(weapon2, 0x20000)) {
        weapon2 = 0;
    }

    for (i = 0; i < 10; i++) {
        s32 time = pPlayer->gunheldarr[i].totaltime;

        if (time >= 0) {
            if (weapon1 == pPlayer->gunheldarr[i].weapon1 &&
                    weapon2 == pPlayer->gunheldarr[i].weapon2) {
                pPlayer->gunheldarr[i].totaltime = time + clock_timer;
                break;
            }

            if (time < leastusedtime) {
                leastusedtime = time;
                leastusedindex = i;
            }
        } else {
            leastusedindex = i;
            i = 10;
            break;
        }
    }

    if (i == 10) {
        pPlayer->gunheldarr[leastusedindex].totaltime = clock_timer;
        pPlayer->gunheldarr[leastusedindex].weapon1 = weapon1;
        pPlayer->gunheldarr[leastusedindex].weapon2 = weapon2;
    }
}

s32 get_weapon_of_choice(s32 *weapon1, s32 *weapon2)
{
    s32 mosttime = -1;
    s32 i;

    *weapon1 = 0;
    *weapon2 = 0;

    for (i = 0; i < 10; i++) {

        if (pPlayer->gunheldarr[i].totaltime >= 0
                && pPlayer->gunheldarr[i].totaltime > mosttime) {
            mosttime = pPlayer->gunheldarr[i].totaltime;
            *weapon1 = pPlayer->gunheldarr[i].weapon1;
            *weapon2 = pPlayer->gunheldarr[i].weapon2;
        }
    }
}



