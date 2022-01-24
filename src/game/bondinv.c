#include <ultra64.h>
#include "bondview.h"
#include "chr.h"
#include "player.h"
#include "textrelated.h"
#include <bondconstants.h>
#include "lvl_text.h"
#include "bondinv.h"
#include "gun.h"
#include "lvl.h"
#include <bondtypes.h>

void reinit_inventory(void)
{
    s32 i;

    for (i = 0; i < g_CurrentPlayer->equipmaxitems; i++)
    {
        g_CurrentPlayer->p_itemcur[i].type = -1;
    }

    g_CurrentPlayer->ptr_inventory_first_in_cycle = NULL;
    g_CurrentPlayer->textoverrides                = NULL;
    g_CurrentPlayer->equipcuritem                 = 0;
}

/**
 * Sorts subject into its correct position in the inventory list.
 *
 * Subject is expected to initially be at the head of the list. It works by
 * swapping the subject with the item to its right as many times as needed.
 */
void inv_sort_item(InvItem *subject)
{
    InvItem *candidate;
    s32      subjweapon1 = -1;
    s32      subjweapon2 = -1;
    s32      candweapon1;
    s32      candweapon2;

    // Prepare subject's properties for comparisons
    if (subject->type == INV_ITEM_WEAPON)
    {
        subjweapon1 = subject->type_inv_item.type_weap.weapon;
    }
    else if (subject->type == INV_ITEM_DUAL)
    {
        subjweapon1 = subject->type_inv_item.type_dual.weapon_right;
        subjweapon2 = subject->type_inv_item.type_dual.weapon_left;
    }
    else if (subject->type == INV_ITEM_PROP)
    {
        subjweapon1 = 2000;
    }

    candidate = subject->next;

    while (g_CurrentPlayer->ptr_inventory_first_in_cycle != subject->next)
    {
        // Prepare candidate's properties for comparisons
        candweapon1 = -1;
        candweapon2 = -1;

        if (subject->next->type == INV_ITEM_WEAPON)
        {
            candweapon1 = subject->next->type_inv_item.type_weap.weapon;
        }
        else if (subject->next->type == INV_ITEM_DUAL)
        {
            candweapon1 = subject->next->type_inv_item.type_dual.weapon_right;
            candweapon2 = subject->next->type_inv_item.type_dual.weapon_left;
        }
        else if (subject->next->type == INV_ITEM_PROP)
        {
            candweapon1 = 1000;
        }

        // If the candidate should sort ahead of subject
        // then subject is in the desired position.
        if (candweapon1 >= subjweapon1 &&
            (subjweapon1 != candweapon1 || subjweapon2 <= candweapon2))
        {
            return;
        }

        // If there's only two items in the list then there's no point swapping
        // them. Just set the list head to the candidate.
        if (candidate->next == subject)
        {
            g_CurrentPlayer->ptr_inventory_first_in_cycle = candidate;
        }
        else
        {
            // Swap subject with candidate
            subject->next         = candidate->next;
            candidate->prev       = subject->prev;
            subject->prev         = candidate;
            candidate->next       = subject;
            subject->next->prev   = subject;
            candidate->prev->next = candidate;

            // Set new list head if subject was the head
            if (subject == g_CurrentPlayer->ptr_inventory_first_in_cycle)
            {
                g_CurrentPlayer->ptr_inventory_first_in_cycle = candidate;
            }
        }

        candidate = subject->next;
    }
}

void inv_insert_item(InvItem *item)
{
    if (g_CurrentPlayer->ptr_inventory_first_in_cycle)
    {
        item->next = g_CurrentPlayer->ptr_inventory_first_in_cycle;
        item->prev = g_CurrentPlayer->ptr_inventory_first_in_cycle->prev;

        item->next->prev = item;
        item->prev->next = item;
    }
    else
    {
        item->next = item;
        item->prev = item;
    }

    g_CurrentPlayer->ptr_inventory_first_in_cycle = item;
    inv_sort_item(item);
    return;
}

void inventory_remove_item(InvItem *item)
{
    InvItem *prev;
    InvItem *next;

    next = item->next;
    prev = item->prev;

    if (item == g_CurrentPlayer->ptr_inventory_first_in_cycle)
    {
        if (item == item->next)
        {
            g_CurrentPlayer->ptr_inventory_first_in_cycle = NULL;
        }
        else
        {
            g_CurrentPlayer->ptr_inventory_first_in_cycle = item->next;
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

    for (i = 0; i < g_CurrentPlayer->equipmaxitems; i++)
    {
        if (g_CurrentPlayer->p_itemcur[i].type == -1)
        {
            return &g_CurrentPlayer->p_itemcur[i];
        }
    }

    return NULL;
}

void set_BONDdata_allguns_flag(s32 all_guns)
{
    g_CurrentPlayer->equipallguns = all_guns;
}

s32 get_BONDdata_allguns_flag(void)
{
    return g_CurrentPlayer->equipallguns;
}

InvItem *get_inventory_item(ITEM_IDS weapon)
{
    InvItem *first = g_CurrentPlayer->ptr_inventory_first_in_cycle;
    InvItem *item  = first;

    while (item)
    {
        if (item->type == INV_ITEM_WEAPON && item->type_inv_item.type_weap.weapon == weapon)
        {
            return item;
        }

        item = item->next;

        if (item == first)
        {
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

InvItem *get_dual_weapon(ITEM_IDS right, ITEM_IDS left)
{
    InvItem *first = g_CurrentPlayer->ptr_inventory_first_in_cycle;
    InvItem *item  = first;

    while (item)
    {
        if (item->type == INV_ITEM_DUAL &&
            item->type_inv_item.type_dual.weapon_right == right &&
            item->type_inv_item.type_dual.weapon_left == left)
        {
            return item;
        }

        item = item->next;

        if (item == first)
        {
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
    if (((g_CurrentPlayer->equipallguns) && (weaponid != ITEM_UNARMED) && (weaponid < ITEM_BOMBCASE)))
    {
#ifndef VERSION_US
        if ((!j_text_trigger || (weaponid != ITEM_KNIFE)))
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
    if (g_CurrentPlayer->equipallguns &&
        right < ITEM_BOMBCASE &&
        right == left &&
        getPlayerCount() == 1 &&
        bondwalkItemCheckBitflags(right, 0x100000))
    {
        return 1;
    }
#else
    if (left == 0)
    {
        return 1;
    }
    else
    {
        if (g_CurrentPlayer->equipallguns &&
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

        if ((g_CurrentPlayer->equipallguns) && (item < ITEM_BOMBCASE))
        {
#ifndef VERSION_US
            if ((!j_text_trigger || (item != ITEM_KNIFE)))
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

    if (is_dual_weapon_in_inventory(right, left) == 0)
    {
        item = get_ptr_next_available_weapon();

        if (item)
        {
            item->type                                 = INV_ITEM_DUAL;
            item->type_inv_item.type_dual.weapon_right = right;
            item->type_inv_item.type_dual.weapon_left  = left;
            inv_insert_item(item);
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

WeaponObjRecord *inventory_remove_prop_weapon_by_id(ITEM_IDS weaponnum)
{
    if (g_CurrentPlayer->ptr_inventory_first_in_cycle)
    {
        InvItem *item = g_CurrentPlayer->ptr_inventory_first_in_cycle->next;

        while (TRUE)
        {
            InvItem *next = item->next;

            if (item->type == INV_ITEM_PROP)
            {
                PropRecord *prop = item->type_inv_item.type_prop.prop;

                if (prop->type == PROP_TYPE_WEAPON)
                {
                    ObjectRecord *obj = prop->obj;

                    if (obj->type == PROPDEF_COLLECTABLE)
                    {
                        WeaponObjRecord *weapon = (WeaponObjRecord *)prop->obj;

                        if (weapon->weaponnum == weaponnum)
                        {
                            inventory_remove_item(item);
                            return weapon;
                        }
                    }
                }
            }

            if ((item == g_CurrentPlayer->ptr_inventory_first_in_cycle) || (!g_CurrentPlayer->ptr_inventory_first_in_cycle))
            {
                break;
            }

            item = next;
        }
    }

    return NULL;
}

void inventory_remove_item_by_id(ITEM_IDS weaponnum)
{
    if (g_CurrentPlayer->ptr_inventory_first_in_cycle)
    {
        InvItem *item = g_CurrentPlayer->ptr_inventory_first_in_cycle->next;

        while (TRUE)
        {
            InvItem *next = item->next;

            if (item->type == INV_ITEM_PROP)
            {
                PropRecord *prop = item->type_inv_item.type_prop.prop;

                if (prop->type == PROP_TYPE_WEAPON)
                {
                    ObjectRecord *obj = prop->obj;

                    if (obj->type == PROPDEF_COLLECTABLE)
                    {
                        WeaponObjRecord *weapon = (WeaponObjRecord *)prop->obj;

                        if (weapon->weaponnum == weaponnum)
                        {
                            inventory_remove_item(item);
                        }
                    }
                }
            }
            else if (item->type == INV_ITEM_WEAPON)
            {
                if (item->type_inv_item.type_weap.weapon == weaponnum)
                {
                    inventory_remove_item(item);
                }
            }

            if ((item == g_CurrentPlayer->ptr_inventory_first_in_cycle) || (!g_CurrentPlayer->ptr_inventory_first_in_cycle))
            {
                break;
            }

            item = next;
        }
    }
}

int add_prop_to_inventory(PropRecord *prop)
{
    InvItem *item;

    item = get_ptr_next_available_weapon();

    if (item)
    {
        item->type                         = INV_ITEM_PROP;
        item->type_inv_item.type_prop.prop = prop;
        inv_insert_item(item);
    }

    return TRUE;
}

#ifndef VERSION_EU
int add_weapon_by_prop(PropRecord *prop)
{
    int added;
    added = FALSE;

    if (prop->type == PROP_TYPE_WEAPON)
    {
        ObjectRecord *obj = prop->obj;

        if (obj->type == PROPDEF_COLLECTABLE)
        {
            WeaponObjRecord *weapon = (WeaponObjRecord *)prop->obj;
            WeaponObjRecord *otherweapon;

            s8 weaponnum = weapon->weaponnum;
            added = add_item_to_inventory(weaponnum);

            otherweapon = weapon->dualweapon;
            if (otherweapon != 0)
            {
                if (weapon->flags & PROPFLAG_10000000)
                {
                    added = is_dual_weapon_in_inventory(otherweapon->weaponnum, weaponnum) == 0;
                }
                else
                {
                    added = is_dual_weapon_in_inventory(weaponnum, otherweapon->weaponnum) == 0;
                }
                weapon->dualweapon->LinkedWeaponType = weaponnum;
                weapon->dualweapon->dualweapon       = 0;
                weapon->dualweapon                   = NULL;
            }
            else
            {
                if (weapon->LinkedWeaponType >= 0)
                {
                    if (weapon->flags & PROPFLAG_10000000)
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
#else

#endif
#ifdef VERSION_EU
GLOBAL_ASM(
.text
glabel add_weapon_by_prop
/* 0BF4CC 7F08CADC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0BF4D0 7F08CAE0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0BF4D4 7F08CAE4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0BF4D8 7F08CAE8 908E0000 */  lbu   $t6, ($a0)
/* 0BF4DC 7F08CAEC 24010004 */  li    $at, 4
/* 0BF4E0 7F08CAF0 00002825 */  move  $a1, $zero
/* 0BF4E4 7F08CAF4 55C10037 */  bnel  $t6, $at, .L7F08CBD4
/* 0BF4E8 7F08CAF8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0BF4EC 7F08CAFC 8C860004 */  lw    $a2, 4($a0)
/* 0BF4F0 7F08CB00 24010008 */  li    $at, 8
/* 0BF4F4 7F08CB04 90CF0003 */  lbu   $t7, 3($a2)
/* 0BF4F8 7F08CB08 55E10032 */  bnel  $t7, $at, .L7F08CBD4
/* 0BF4FC 7F08CB0C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0BF500 7F08CB10 80D00080 */  lb    $s0, 0x80($a2)
/* 0BF504 7F08CB14 AFA60024 */  sw    $a2, 0x24($sp)
/* 0BF508 7F08CB18 0FC231FA */  jal   add_item_to_inventory
/* 0BF50C 7F08CB1C 02002025 */   move  $a0, $s0
/* 0BF510 7F08CB20 8FA30024 */  lw    $v1, 0x24($sp)
/* 0BF514 7F08CB24 00402825 */  move  $a1, $v0
/* 0BF518 7F08CB28 8C660084 */  lw    $a2, 0x84($v1)
/* 0BF51C 7F08CB2C 50C00019 */  beql  $a2, $zero, .L7F08CB94eu
/* 0BF520 7F08CB30 80660081 */   lb    $a2, 0x81($v1)
/* 0BF524 7F08CB34 8C780008 */  lw    $t8, 8($v1)
/* 0BF528 7F08CB38 02002825 */  move  $a1, $s0
/* 0BF52C 7F08CB3C 02002025 */  move  $a0, $s0
/* 0BF530 7F08CB40 0018C8C0 */  sll   $t9, $t8, 3
/* 0BF534 7F08CB44 07230008 */  bgezl $t9, .L7F08CB68
/* 0BF538 7F08CB48 80C50080 */   lb    $a1, 0x80($a2)
/* 0BF53C 7F08CB4C 80C40080 */  lb    $a0, 0x80($a2)
/* 0BF540 7F08CB50 0FC231AB */  jal   add_doubles_item_to_inventory
/* 0BF544 7F08CB54 AFA30024 */   sw    $v1, 0x24($sp)
/* 0BF548 7F08CB58 8FA30024 */  lw    $v1, 0x24($sp)
/* 0BF54C 7F08CB5C 10000006 */  b     .L7F08CB78
/* 0BF550 7F08CB60 2C450001 */   sltiu $a1, $v0, 1
/* 0BF554 7F08CB64 80C50080 */  lb    $a1, 0x80($a2)
.L7F08CB68:
/* 0BF558 7F08CB68 0FC231AB */  jal   add_doubles_item_to_inventory
/* 0BF55C 7F08CB6C AFA30024 */   sw    $v1, 0x24($sp)
/* 0BF560 7F08CB70 8FA30024 */  lw    $v1, 0x24($sp)
/* 0BF564 7F08CB74 2C450001 */  sltiu $a1, $v0, 1
.L7F08CB78:
/* 0BF568 7F08CB78 8C680084 */  lw    $t0, 0x84($v1)
/* 0BF56C 7F08CB7C A1100081 */  sb    $s0, 0x81($t0)
/* 0BF570 7F08CB80 8C690084 */  lw    $t1, 0x84($v1)
/* 0BF574 7F08CB84 AD200084 */  sw    $zero, 0x84($t1)
/* 0BF578 7F08CB88 10000011 */  b     .L7F08CBD0
/* 0BF57C 7F08CB8C AC600084 */   sw    $zero, 0x84($v1)
/* 0BF580 7F08CB90 80660081 */  lb    $a2, 0x81($v1)
.L7F08CB94eu:
/* 0BF584 7F08CB94 04C2000F */  bltzl $a2, .L7F08CBD4
/* 0BF588 7F08CB98 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0BF58C 7F08CB9C 8C6A0008 */  lw    $t2, 8($v1)
/* 0BF590 7F08CBA0 02002825 */  move  $a1, $s0
/* 0BF594 7F08CBA4 02002025 */  move  $a0, $s0
/* 0BF598 7F08CBA8 000A58C0 */  sll   $t3, $t2, 3
/* 0BF59C 7F08CBAC 05610005 */  bgez  $t3, .L7F08CBC4eu
/* 0BF5A0 7F08CBB0 00000000 */   nop   
/* 0BF5A4 7F08CBB4 0FC23221 */  jal   is_dual_weapon_in_inventory
/* 0BF5A8 7F08CBB8 00C02025 */   move  $a0, $a2
/* 0BF5AC 7F08CBBC 10000004 */  b     .L7F08CBD0
/* 0BF5B0 7F08CBC0 00402825 */   move  $a1, $v0
.L7F08CBC4eu:
/* 0BF5B4 7F08CBC4 0FC23221 */  jal   is_dual_weapon_in_inventory
/* 0BF5B8 7F08CBC8 00C02825 */   move  $a1, $a2
/* 0BF5BC 7F08CBCC 00402825 */  move  $a1, $v0
.L7F08CBD0:
/* 0BF5C0 7F08CBD0 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F08CBD4:
/* 0BF5C4 7F08CBD4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0BF5C8 7F08CBD8 27BD0030 */  addiu $sp, $sp, 0x30
/* 0BF5CC 7F08CBDC 03E00008 */  jr    $ra
/* 0BF5D0 7F08CBE0 00A01025 */   move  $v0, $a1
)
#endif






void choose_cycle_forward_weapon(s32 *nextright, s32 *nextleft, s32 requireammo)
{
    s32      weapon1 = *nextright;
    s32      weapon2 = *nextleft;
    InvItem *item    = g_CurrentPlayer->ptr_inventory_first_in_cycle;

    while (item)
    {
        if (item->type == INV_ITEM_WEAPON)
        {
            if (item->type_inv_item.type_weap.weapon < ITEM_BOMBCASE && item->type_inv_item.type_weap.weapon > weapon1)
            {
                if (requireammo == FALSE || bondwalkItemHasAmmo(item->type_inv_item.type_weap.weapon))
                {
                    weapon1 = item->type_inv_item.type_weap.weapon;
                    weapon2 = 0;
                    break;
                }
            }
        }
        else if (item->type == INV_ITEM_DUAL)
        {
            if (item->type_inv_item.type_dual.weapon_right > weapon1 || (weapon1 == item->type_inv_item.type_dual.weapon_right && item->type_inv_item.type_dual.weapon_left > weapon2))
            {
                if (requireammo == FALSE || bondwalkItemHasAmmo(item->type_inv_item.type_dual.weapon_right) || bondwalkItemHasAmmo(item->type_inv_item.type_dual.weapon_left))
                {
                    weapon1 = item->type_inv_item.type_dual.weapon_right;
                    weapon2 = item->type_inv_item.type_dual.weapon_left;
                    break;
                }
            }
        }

        item = item->next;

        if (item == g_CurrentPlayer->ptr_inventory_first_in_cycle)
        {
            if (requireammo)
            {
                break;
            }

            weapon1 = -1;
            weapon2 = -1;
        }
    }

    if (g_CurrentPlayer->equipallguns)
    {
        s32 candidate = *nextright;

        if (getPlayerCount() == 1 && bondwalkItemCheckBitflags(*nextright, 0x100000) && (*nextleft < *nextright) && (requireammo == FALSE || bondwalkItemHasAmmo(*nextright)) && (weapon1 != *nextright || *nextright < weapon2)
#ifndef VERSION_US
            && (j_text_trigger == 0 || *nextright != 2)
#endif
        )
        {
            weapon1 = *nextright;
            weapon2 = *nextright;
        }
        else
        {
            if ((weapon1 != *nextright) || (weapon2 == *nextleft))
            {
                // Find next weapon
                do
                {
                    candidate = (candidate + 1) % ITEM_BOMBCASE;

                    if (candidate == 0)
                    {
                        candidate = (candidate + 1) % ITEM_BOMBCASE;
                    }

                    if ((requireammo == FALSE || bondwalkItemHasAmmo(candidate))
#ifndef VERSION_US
                        && (j_text_trigger == 0 || candidate != 2)
#endif
                    )
                    {
                        weapon1 = candidate;
                        weapon2 = 0;
                        break;
                    }
                } while (candidate != weapon1);
            }
        }
    }

    *nextright = weapon1;
    *nextleft  = weapon2;
}

void choose_cycle_back_weapon(s32 *nextright, s32 *nextleft, s32 requireammo)
{
    s32 weapon1 = *nextright;
    s32 weapon2 = *nextleft;

    if (g_CurrentPlayer->ptr_inventory_first_in_cycle != NULL)
    {
        InvItem *item = g_CurrentPlayer->ptr_inventory_first_in_cycle->prev;

        while (TRUE)
        {
            if (item->type == INV_ITEM_WEAPON)
            {
                if (item->type_inv_item.type_weap.weapon < ITEM_BOMBCASE && (item->type_inv_item.type_weap.weapon < weapon1 || (weapon1 == item->type_inv_item.type_weap.weapon && weapon2 > 0)))
                {
                    if (requireammo == FALSE || bondwalkItemHasAmmo(item->type_inv_item.type_weap.weapon))
                    {
                        weapon1 = item->type_inv_item.type_weap.weapon;
                        weapon2 = 0;
                        break;
                    }
                }
            }
            else if (item->type == INV_ITEM_DUAL)
            {
                if (item->type_inv_item.type_dual.weapon_right < weapon1 || (weapon1 == item->type_inv_item.type_dual.weapon_right && item->type_inv_item.type_dual.weapon_left < weapon2))
                {
                    if (requireammo == FALSE || bondwalkItemHasAmmo(item->type_inv_item.type_dual.weapon_right) || bondwalkItemHasAmmo(item->type_inv_item.type_dual.weapon_left))
                    {
                        weapon1 = item->type_inv_item.type_dual.weapon_right;
                        weapon2 = item->type_inv_item.type_dual.weapon_left;
                        break;
                    }
                }
            }

            if (item == g_CurrentPlayer->ptr_inventory_first_in_cycle)
            {
                if (requireammo)
                {
                    break;
                }

                weapon1 = 1000;
                weapon2 = 1000;
            }

            item = item->prev;
        }
    }

    if (g_CurrentPlayer->equipallguns)
    {
        s32 candidate = *nextright;

        if (*nextleft == 0)
        {
            candidate = (candidate + ITEM_BOMBCASE - 1) % ITEM_BOMBCASE;
            if (candidate == 0)
            {
                candidate = (candidate + ITEM_BOMBCASE - 1) % ITEM_BOMBCASE;
            }
        }

        while (TRUE)
        {
            if (candidate == weapon1)
            {
                if (getPlayerCount() == 1 && bondwalkItemCheckBitflags(candidate, 0x100000) && (requireammo == FALSE || bondwalkItemHasAmmo(candidate)) && (candidate != *nextright || candidate < *nextleft) && (weapon2 < candidate)
#ifndef VERSION_US
                    && (j_text_trigger == 0 || candidate != 2)
#endif
                )
                {
                    weapon1 = candidate;
                    weapon2 = candidate;
                }

                break;
            }
            else if (
                (requireammo == FALSE || bondwalkItemHasAmmo(candidate))
#ifndef VERSION_US
                && (j_text_trigger == 0 || candidate != 2)
#endif
            )
            {
                if (getPlayerCount() == 1 && bondwalkItemCheckBitflags(candidate, 0x100000) && (candidate != *nextright || candidate < *nextleft))
                {
                    weapon1 = candidate;
                    weapon2 = candidate;
                }
                else
                {
                    weapon1 = candidate;
                    weapon2 = 0;
                }

                break;
            }
            else
            {
                candidate = (candidate + ITEM_BOMBCASE - 1) % ITEM_BOMBCASE;
                if (candidate == 0)
                {
                    candidate = (candidate + ITEM_BOMBCASE - 1) % ITEM_BOMBCASE;
                }
            }
        }
    }

    *nextright = weapon1;
    *nextleft  = weapon2;
}

bool inv_has_key_flags(u32 wantkeyflags)
{
    u32      heldkeyflags = 0;
    InvItem *item         = g_CurrentPlayer->ptr_inventory_first_in_cycle;

    while (item)
    {
        if (item->type == INV_ITEM_PROP)
        {
            PropRecord *prop = item->type_inv_item.type_prop.prop;

            if (prop->type == PROP_TYPE_OBJ)
            {
                ObjectRecord *obj = prop->obj;

                if (obj->type == PROPDEF_KEY)
                {
                    KeyRecord *key = (KeyRecord *)prop->obj;

                    heldkeyflags |= key->keyflags;

                    if ((wantkeyflags & heldkeyflags) == wantkeyflags)
                    {
                        return TRUE;
                    }
                }
            }
        }

        item = item->next;

        if (item == g_CurrentPlayer->ptr_inventory_first_in_cycle)
        {
            break;
        }
    }

    return FALSE;
}

bool checkHasGEKey(void)
{
    InvItem      *item;
    PropRecord   *prop;
    ObjectRecord *obj;

    item = g_CurrentPlayer->ptr_inventory_first_in_cycle;

    while (item)
    {
        if (item->type == INV_ITEM_PROP)
        {
            prop = item->type_inv_item.type_prop.prop;

            if (prop->type == PROP_TYPE_WEAPON)
            {
                obj = prop->obj;

                if (obj->obj == PROJECTILES_TYPE_GE_KEY)
                {
                    return TRUE;
                }
            }
        }

        item = item->next;

        if (item == g_CurrentPlayer->ptr_inventory_first_in_cycle)
        {
            break;
        }
    }

    return FALSE;
}

/**
 * Is the player alive with flag tag token in inventory
 * @return TRUE/FALSE
 */
bool bondinvIsAliveWithFlag(void)
{
    if (!g_CurrentPlayer->bonddead)
    {
        return is_item_in_inventory(ITEM_TOKEN);
    }

    return FALSE;
}

/**
 * Is the Golden Gun in inventory
 * @return TRUE/FALSE
 */
bool checkforgoldengun(void)
{
    return is_item_in_inventory(ITEM_GOLDENGUN);
}

bool is_prop_in_inventory(PropRecord *prop)
{
    InvItem *item = g_CurrentPlayer->ptr_inventory_first_in_cycle;

    while (item)
    {
        if (item->type == INV_ITEM_PROP && item->type_inv_item.type_prop.prop == prop)
        {
            return TRUE;
        }

        item = item->next;

        if (item == g_CurrentPlayer->ptr_inventory_first_in_cycle)
        {
            break;
        }
    }

    return FALSE;
}

s32 count_total_items_in_inventory(void)
{
    InvItem *item;
    s32      numitems = 0;

    if (g_CurrentPlayer->equipallguns)
    {
#ifndef VERSION_US
        numitems = (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS);
#else
        numitems = ITEM_TANKSHELLS;
#endif
    }

    item = g_CurrentPlayer->ptr_inventory_first_in_cycle;

    while (item)
    {
        if (item->type == INV_ITEM_PROP)
        {
            PropRecord *prop = item->type_inv_item.type_prop.prop;

            if (prop->type == PROP_TYPE_WEAPON)
            {
                ObjectRecord *obj = prop->obj;

                if (obj->runtime_bitflags & 0x400)
                {
                    numitems = numitems + 1;
                }
            }
            else if (prop->type == PROP_TYPE_OBJ)
            {
                if ((prop->obj->flags2 & 0x40000) == 0)
                {
                    numitems = numitems + 1;
                }
            }
        }
        else if (item->type == INV_ITEM_WEAPON)
        {
            if ((g_CurrentPlayer->equipallguns == FALSE) || (item->type_inv_item.type_weap.weapon > ITEM_TANKSHELLS))
            {
                numitems = numitems + 1;
            }
        }

        item = item->next;

        if (item == g_CurrentPlayer->ptr_inventory_first_in_cycle)
        {
            break;
        }
    }

    return numitems;
}

InvItem *inv_get_item_by_index(s32 index)
{
    InvItem *item;

    if (g_CurrentPlayer->equipallguns)
    {
#ifndef VERSION_US
        if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
#else
        if (index < ITEM_TANKSHELLS)
#endif
        {
            return NULL;
        }

#ifndef VERSION_US
        index = index - (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS);
#else
        index = index - ITEM_TANKSHELLS;
#endif
    }

    item = g_CurrentPlayer->ptr_inventory_first_in_cycle;

    while (item)
    {
        if (item->type == INV_ITEM_PROP)
        {
            PropRecord *prop = item->type_inv_item.type_prop.prop;

            if (prop->type == PROP_TYPE_WEAPON)
            {
                ObjectRecord *obj = prop->obj;

                if (obj->runtime_bitflags & 0x400)
                {
                    if (index == 0)
                    {
                        return item;
                    }
                    index--;
                }
            }
            else if (prop->type == PROP_TYPE_OBJ)
            {
                if ((prop->obj->flags2 & 0x40000) == 0)
                {
                    if (index == 0)
                    {
                        return item;
                    }
                    index--;
                }
            }
        }
        else if (item->type == INV_ITEM_WEAPON)
        {
            if ((g_CurrentPlayer->equipallguns == FALSE) || (item->type_inv_item.type_weap.weapon > ITEM_TANKSHELLS))
            {
                if (index == 0)
                {
                    return item;
                }
                index--;
            }
        }

        item = item->next;

        if (item == g_CurrentPlayer->ptr_inventory_first_in_cycle)
        {
            break;
        }
    }

    return NULL;
}

textoverride *get_textoverride_by_obj(ObjectRecord *obj)
{
    textoverride *override = g_CurrentPlayer->textoverrides;

    while (override)
    {
        if (override->obj == obj)
        {
            return override;
        }

        override = override->next;
    }

    return NULL;
}

textoverride *get_textoverride_by_weaponum(ITEM_IDS weaponnum)
{
    textoverride *override = g_CurrentPlayer->textoverrides;

    while (override)
    {
        if ((override->objoffset == 0) && (override->weapon == weaponnum))
        {
            return override;
        }

        override = override->next;
    }

    return NULL;
}

s32 get_weaponnum_by_inv_index(s32 index)
{
    textoverride *override;
    InvItem *     inv_item;

    inv_item = inv_get_item_by_index(index);

    if (inv_item)
    {
        if (inv_item->type == INV_ITEM_PROP)
        {
            PropRecord *prop = inv_item->type_inv_item.type_prop.prop;

            override = get_textoverride_by_obj(prop->obj);

            if (override)
            {
                return override->weapon;
            }
        }
        else if (inv_item->type == INV_ITEM_WEAPON)
        {
            return inv_item->type_inv_item.type_weap.weapon;
        }
    }
    else
    {
        if (g_CurrentPlayer->equipallguns)
        {
#ifndef VERSION_US
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return index + 2;
                }

                return index + 1;
            }
#else
            if (index < ITEM_TANKSHELLS)
            {
                return index + 1;
            }
#endif
        }
    }

    return 0;
}

u16 *inv_get_name_by_index(s32 index)
{
    InvItem      *item      = inv_get_item_by_index(index);
    ITEM_IDS      weaponnum = 0;
    textoverride *override;

    if (item)
    {
        if (item->type == INV_ITEM_PROP)
        {
            PropRecord *prop = item->type_inv_item.type_prop.prop;
            override         = get_textoverride_by_obj(prop->obj);

            if (override)
            {
                if (override->unk6)
                {
                    return get_textptr_for_textID(override->unk6);
                }

                weaponnum = override->weapon;
            }
        }
        else if (item->type == INV_ITEM_WEAPON)
        {
            weaponnum = item->type_inv_item.type_weap.weapon;
            override  = get_textoverride_by_weaponum(weaponnum);

            if (override && override->unk6)
            {
                return get_textptr_for_textID(override->unk6);
            }
        }
    }
    else
    {
        if (g_CurrentPlayer->equipallguns)
        {
#ifndef VERSION_US
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return get_ptr_short_watch_text_for_item(index + 2);
                }

                return get_ptr_short_watch_text_for_item(index + 1);
            }
#else
            if (index < ITEM_TANKSHELLS)
            {
                return get_ptr_short_watch_text_for_item(index + 1);
            }
#endif
        }
    }

    return get_ptr_short_watch_text_for_item(weaponnum);
}

u16 *inv_get_long_name_by_index(s32 index)
{
    InvItem      *item      = inv_get_item_by_index(index);
    ITEM_IDS      weaponnum = 0;
    textoverride *override;

    if (item)
    {
        if (item->type == INV_ITEM_PROP)
        {
            PropRecord *prop = item->type_inv_item.type_prop.prop;
            override         = get_textoverride_by_obj(prop->obj);

            if (override)
            {
                if (override->unk7)
                {
                    return get_textptr_for_textID(override->unk7);
                }

                weaponnum = override->weapon;
            }
        }
        else if (item->type == INV_ITEM_WEAPON)
        {
            weaponnum = item->type_inv_item.type_weap.weapon;
            override  = get_textoverride_by_weaponum(weaponnum);

            if (override && override->unk7)
            {
                return get_textptr_for_textID(override->unk7);
            }
        }
    }
    else
    {
        if (g_CurrentPlayer->equipallguns)
        {
#ifndef VERSION_US
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return get_ptr_long_watch_text_for_item(index + 2);
                }

                return get_ptr_long_watch_text_for_item(index + 1);
            }
#else
            if (index < ITEM_TANKSHELLS)
            {
                return get_ptr_long_watch_text_for_item(index + 1);
            }
#endif
        }
    }

    return get_ptr_long_watch_text_for_item(weaponnum);
}

int sub_GAME_7F08D528(int index)
{
    return get_45_degree_angle_0(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D550(int index)
{
    return get_horizontal_offset_on_solo_watch_menu_for_item(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D578(int index)
{
    return get_vertical_offset_on_solo_watch_menu_for_item(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D5A0(int index)
{
    return get_depth_offset_solo_watch_menu_inventory_page_for_item(get_weaponnum_by_inv_index(index));
}

u16 *inv_get_first_title_name_by_index(s32 index)
{
    InvItem      *item      = inv_get_item_by_index(index);
    ITEM_IDS      weaponnum = 0;
    textoverride *override;

    if (item)
    {
        if (item->type == INV_ITEM_PROP)
        {
            PropRecord *prop = item->type_inv_item.type_prop.prop;
            override         = get_textoverride_by_obj(prop->obj);

            if (override)
            {
                if (override->unk4)
                {
                    return get_textptr_for_textID(override->unk4);
                }

                weaponnum = override->weapon;
            }
        }
        else if (item->type == INV_ITEM_WEAPON)
        {
            weaponnum = item->type_inv_item.type_weap.weapon;
            override  = get_textoverride_by_weaponum(weaponnum);

            if (override && override->unk4)
            {
                return get_textptr_for_textID(override->unk4);
            }
        }
    }
    else
    {
        if (g_CurrentPlayer->equipallguns)
        {
#ifndef VERSION_US
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return get_ptr_first_title_line_item(index + 2);
                }

                return get_ptr_first_title_line_item(index + 1);
            }
#else
            if (index < ITEM_TANKSHELLS)
            {
                return get_ptr_first_title_line_item(index + 1);
            }
#endif
        }
    }

    return get_ptr_first_title_line_item(weaponnum);
}

u16 *inv_get_second_title_name_by_index(s32 index)
{
    InvItem      *item      = inv_get_item_by_index(index);
    ITEM_IDS      weaponnum = 0;
    textoverride *override;

    if (item)
    {
        if (item->type == INV_ITEM_PROP)
        {
            PropRecord *prop = item->type_inv_item.type_prop.prop;
            override         = get_textoverride_by_obj(prop->obj);

            if (override)
            {
                if (override->unk5)
                {
                    return get_textptr_for_textID(override->unk5);
                }

                weaponnum = override->weapon;
            }
        }
        else if (item->type == INV_ITEM_WEAPON)
        {
            weaponnum = item->type_inv_item.type_weap.weapon;
            override  = get_textoverride_by_weaponum(weaponnum);

            if (override && override->unk5)
            {
                return get_textptr_for_textID(override->unk5);
            }
        }
    }
    else
    {
        if (g_CurrentPlayer->equipallguns)
        {
#ifndef VERSION_US
            if (index < (j_text_trigger ? ITEM_TASER : ITEM_TANKSHELLS))
            {
                if (j_text_trigger && ((index + 1) >= 2))
                {
                    return get_ptr_second_title_line_item(index + 2);
                }

                return get_ptr_second_title_line_item(index + 1);
            }
#else
            if (index < ITEM_TANKSHELLS)
            {
                return get_ptr_second_title_line_item(index + 1);
            }
#endif
        }
    }

    return get_ptr_second_title_line_item(weaponnum);
}

int sub_GAME_7F08D7B0(int index)
{
    return get_45_degree_angle(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D7D8(int index)
{
    return get_vertical_position_solo_watch_menu_main_page_for_item(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D800(int index)
{
    return get_lateral_position_solo_watch_menu_main_page_for_item(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D828(int index)
{
    return get_depth_on_solo_watch_menu_page_for_item(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D850(int index)
{
    return get_xrotation_solo_watch_menu_for_item(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D878(int index)
{
    return get_yrotation_solo_watch_menu_for_item(get_weaponnum_by_inv_index(index));
}

void sub_GAME_7F08D8A0(textoverride *override)
{
    override->next                 = g_CurrentPlayer->textoverrides;
    g_CurrentPlayer->textoverrides = override;
}

int get_BONDdata_equipcuritem(void)
{
    return g_CurrentPlayer->equipcuritem;
}

void set_BONDdata_equipcuritem(int current_item)
{
    g_CurrentPlayer->equipcuritem = current_item;
}

void calculate_equip_cur_item(void)
{
    s32 current_weapon;
    s32 i;

    current_weapon = get_item_in_hand(GUNRIGHT);

    g_CurrentPlayer->equipcuritem = 0;

    for (i = 0; i < count_total_items_in_inventory(); i++)
    {
        if (get_weaponnum_by_inv_index(i) == current_weapon)
        {
            g_CurrentPlayer->equipcuritem = i;
            return;
        }
    }
}

u8 *obj_get_activated_text(ObjectRecord *obj)
{
    textoverride *override = get_textoverride_by_obj(obj);

    if (override && override->unk8)
    {
        return get_textptr_for_textID(override->unk8);
    }

    return NULL;
}

u8 *weapon_get_activated_text(ITEM_IDS weaponnum)
{
    textoverride *override = get_textoverride_by_weaponum(weaponnum);

    if (override && override->unk8)
    {
        return get_textptr_for_textID(override->unk8);
    }

    return NULL;
}

void increment_held_time(s32 weapon1, s32 weapon2)
{
    s32 leastusedtime;
    s32 leastusedindex;
    s32 i;

    if (!bondwalkItemCheckBitflags(weapon1, 0x20000))
    {
        return;
    }

    leastusedtime  = 0x7fffffff;
    leastusedindex = 0;

    if (!bondwalkItemCheckBitflags(weapon2, 0x20000))
    {
        weapon2 = 0;
    }

    for (i = 0; i < 10; i++)
    {
        s32 time = g_CurrentPlayer->gunheldarr[i].totaltime;

        if (time >= 0)
        {
            if (weapon1 == g_CurrentPlayer->gunheldarr[i].weapon1 &&
                weapon2 == g_CurrentPlayer->gunheldarr[i].weapon2)
            {
                g_CurrentPlayer->gunheldarr[i].totaltime = time + g_ClockTimer;
                break;
            }

            if (time < leastusedtime)
            {
                leastusedtime  = time;
                leastusedindex = i;
            }
        }
        else
        {
            leastusedindex = i;
            i              = 10;
            break;
        }
    }

    if (i == 10)
    {
        g_CurrentPlayer->gunheldarr[leastusedindex].totaltime = g_ClockTimer;
        g_CurrentPlayer->gunheldarr[leastusedindex].weapon1   = weapon1;
        g_CurrentPlayer->gunheldarr[leastusedindex].weapon2   = weapon2;
    }
}

s32 get_weapon_of_choice(s32 *weapon1, s32 *weapon2)
{
    s32 mosttime = -1;
    s32 i;

    *weapon1 = 0;
    *weapon2 = 0;

    for (i = 0; i < 10; i++)
    {
        if (g_CurrentPlayer->gunheldarr[i].totaltime >= 0 && g_CurrentPlayer->gunheldarr[i].totaltime > mosttime)
        {
            mosttime = g_CurrentPlayer->gunheldarr[i].totaltime;
            *weapon1 = g_CurrentPlayer->gunheldarr[i].weapon1;
            *weapon2 = g_CurrentPlayer->gunheldarr[i].weapon2;
        }
    }
}
