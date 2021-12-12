#include "ultra64.h"
#include "memp.h"
#include "game/bg.h"
#include "game/initobjects.h"
#include "game/chrai.h"
#include "game/chrobjhandler.h"
//this file may very well be a few different sub files

struct object_animation_controller ptr_monitorimageobjectanimationcontroller = {&monAnim00Bond, 0, 0xFFFF, 0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 1.0, 0.0};
struct object_animation_controller unknown_object_animation_controller = {&monAnim34, 0, 0xFFFF, 0, 0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1.0};
struct object_animation_controller taser_object_animation_controller = {&monAnim35Taser, 0, 0xFFFF, 0, 0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1.0};
f32 unused_8002a3bc = 0.0f;
f32 scale_1_0_item_related = 1.0f;

// forward declarations

void alloc_lookup_buffers();
void write_monitor_ani_control_blocks();
void initialize_temp_mine_table();

// end forward declarations


/**
 * Address 0x7F0014B0.
*/
void init_sound_effects_registers(void)
{
    s32 i;

    for (i=0; i<SFX_RELATED_LEN; i++)
    {
        sfx_related[i].field_0x0 = 0;
    }

}


/**
 * Address 0x7F0014E0.
*/
void init_load_objpos_table(void)
{
    s32 i;

    difficulty = 1.0f;
    ptr_obj_pos_list_current_entry = 
        ptr_obj_pos_list_first_entry = NULL;
    g_OnScreenPropCount = 0;
    g_OnScreenPropList[0] = NULL;
    g_LastOnScreenProp = (PropRecord *) g_OnScreenPropList;
    ptr_obj_pos_list_final_entry = pos_data_entry;

    for (i=0; i<(POS_DATA_ENTRY_LEN-1); i++)
    {
        pos_data_entry[i].prev = &pos_data_entry[i+1];
    }

    alloc_lookup_buffers();
}


/**
 * Address 0x7F0015D0.
*/
void alloc_lookup_buffers(void)
{
    s32 j;
    s32 i;

    ptr_list_object_lookup_indices = (s16*)mempAllocBytesInBank(PTR_LIST_OBJECT_LOOKUP_INDICES_LEN * sizeof(s16), 4);
    ptr_room_lookup_buffer_maybe = (s16*)mempAllocBytesInBank((((MaxNumRooms * 4) + 0xF) | 0xF) ^ 0xF, 4);
    dword_CODE_bss_8007161C = (s16*)mempAllocBytesInBank(BSS_8007161C_LEN * sizeof(struct unk_8007161c), 4);

    ptr_list_object_lookup_indices[0] = -1;

    for (i=0; i<MaxNumRooms; i++)
    {
        ptr_room_lookup_buffer_maybe[i] = -1;
    }

    for (i=0; i<BSS_8007161C_LEN; i++)
    {
        dword_CODE_bss_8007161C[i].data[0] = -2;

        for (j=1; j<BSS_8007161C_DATA_LEN; j++)
        {
            dword_CODE_bss_8007161C[i].data[j] = -1;
        }
    }
}



/**
 * Address 0x7F001750.
*/
void reinit_between_menus(void)
{
    s32 i;

    write_monitor_ani_control_blocks();
    initialize_temp_mine_table();
    alarm_timer = 0;
    ptr_alarm_sfx = 0;
    toxic_gas_sound_timer = 0.0f;
    activate_gas_sound_timer = 0;
    D_80030AD0.f[0] = 0.0f;
    D_80030AD0.f[1] = 0.0f;
    D_80030AD0.f[2] = 0.0f;
    D_80030ADC = 0;
    D_80030AE0 = 0.0f;
    ptr_gas_sound = 0;
    clock_drawn_flag = 1;
    clock_enable = 0;
    clock_time = 0.0f;
    D_80030AF4 = 0;

    for (i=0; i<PROJECTILEDATA_START_ADDRESS_LEN; i++)
    {
        ProjectileData_start_address[i].unk10 = 0;
    }

    D_80030AF8 = 0;

    for (i=0; i<BSS_80072E70_DATA_LEN; i++)
    {
        dword_CODE_bss_80072E70[i].unk10 = 0;
    }
    
    D_80030AFC = 0;

    for (i=0; i<BSS_80073370_DATA_LEN; i++)
    {
        dword_CODE_bss_80073370[i].unk10 = 0;
    }

    for (i=0; i<BSS_80073DC0_DATA_LEN; i++)
    {
        dword_CODE_bss_80073DC0[i].unk00 = 0x80000000;
        dword_CODE_bss_80073DC0[i].unk98 = 0;
        dword_CODE_bss_80073DC0[i].unk9C = 0;
    }

    for (i=0; i<BSS_80075030_DATA_LEN; i++)
    {
        dword_CODE_bss_80075030[i].unk00 = 1;
    }

    g_LevelLoadPropSwitch = NULL;
    g_LevelLoadPropLockDoor = NULL;
    D_80030B08 = NULL;
    D_80030B0C = 0;
    bodypartshot = -1;
    F_80030B14 = 1.0f;
    F_80030B18 = 1.0f;
    F_80030B1C = 1.0f;
    F_80030B20 = 1.0f;
    F_80030B24 = 1.0f;
    g_SoloAmmoMultiplier = 1.0f;
}

/**
 * Called from lvreset2 when PROPDEF type is PROPDEF_SWITCH.
 * Address 0x7F001910.
*/
void initSetLevelLoadPropSwitch(struct ObjectRecord *arg0)
{
    *((struct ObjectRecord **)&arg0->flags2) = g_LevelLoadPropSwitch;
    g_LevelLoadPropSwitch = arg0;
}

/**
 * Called from lvreset2 when PROPDEF type is PROPDEF_LOCK_DOOR.
 * Address 0x7F001928.
*/
void initSetLevelLoadPropLockDoor(struct ObjectRecord *arg0)
{
    *((struct ObjectRecord **)&arg0->flags2) = g_LevelLoadPropLockDoor;
    g_LevelLoadPropLockDoor = arg0;
}

#ifdef NONMATCHING
// PROPDEF_SAFE_ITEM
void sub_GAME_7F001940(struct ObjectRecord *arg0)
{
    arg0->ptrPOSData = D_80030B08;
    D_80030B08 = arg0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F001940
/* 036470 7F001940 3C028003 */  lui   $v0, %hi(D_80030B08)
/* 036474 7F001944 24420B08 */  addiu $v0, %lo(D_80030B08) # addiu $v0, $v0, 0xb08
/* 036478 7F001948 8C4E0000 */  lw    $t6, ($v0)
/* 03647C 7F00194C AC8E0010 */  sw    $t6, 0x10($a0)
/* 036480 7F001950 03E00008 */  jr    $ra
/* 036484 7F001954 AC440000 */   sw    $a0, ($v0)
)
#endif

#ifdef NONMATCHING
void write_monitor_ani_control_blocks(void) {

}
#else
GLOBAL_ASM(
.text
glabel write_monitor_ani_control_blocks
/* 036488 7F001958 27BDFEA0 */  addiu $sp, $sp, -0x160
/* 03648C 7F00195C 3C0E8003 */  lui   $t6, %hi(ptr_monitorimageobjectanimationcontroller)
/* 036490 7F001960 27A200EC */  addiu $v0, $sp, 0xec
/* 036494 7F001964 25CEA260 */  addiu $t6, $t6, %lo(ptr_monitorimageobjectanimationcontroller)
/* 036498 7F001968 27A30078 */  addiu $v1, $sp, 0x78
/* 03649C 7F00196C 27A40004 */  addiu $a0, $sp, 4
/* 0364A0 7F001970 25D9006C */  addiu $t9, $t6, 0x6c
/* 0364A4 7F001974 00404025 */  move  $t0, $v0
.L7F001978:
/* 0364A8 7F001978 8DC10000 */  lw    $at, ($t6)
/* 0364AC 7F00197C 25CE000C */  addiu $t6, $t6, 0xc
/* 0364B0 7F001980 2508000C */  addiu $t0, $t0, 0xc
/* 0364B4 7F001984 AD01FFF4 */  sw    $at, -0xc($t0)
/* 0364B8 7F001988 8DC1FFF8 */  lw    $at, -8($t6)
/* 0364BC 7F00198C AD01FFF8 */  sw    $at, -8($t0)
/* 0364C0 7F001990 8DC1FFFC */  lw    $at, -4($t6)
/* 0364C4 7F001994 15D9FFF8 */  bne   $t6, $t9, .L7F001978
/* 0364C8 7F001998 AD01FFFC */   sw    $at, -4($t0)
/* 0364CC 7F00199C 8DC10000 */  lw    $at, ($t6)
/* 0364D0 7F0019A0 3C098007 */  lui   $t1, %hi(dword_CODE_bss_80075B98) 
/* 0364D4 7F0019A4 25295B98 */  addiu $t1, %lo(dword_CODE_bss_80075B98) # addiu $t1, $t1, 0x5b98
/* 0364D8 7F0019A8 AD010000 */  sw    $at, ($t0)
/* 0364DC 7F0019AC 8DD90004 */  lw    $t9, 4($t6)
/* 0364E0 7F0019B0 00406825 */  move  $t5, $v0
/* 0364E4 7F0019B4 244C006C */  addiu $t4, $v0, 0x6c
/* 0364E8 7F0019B8 AD190004 */  sw    $t9, 4($t0)
.L7F0019BC:
/* 0364EC 7F0019BC 8DA10000 */  lw    $at, ($t5)
/* 0364F0 7F0019C0 25AD000C */  addiu $t5, $t5, 0xc
/* 0364F4 7F0019C4 2529000C */  addiu $t1, $t1, 0xc
/* 0364F8 7F0019C8 AD21FFF4 */  sw    $at, -0xc($t1)
/* 0364FC 7F0019CC 8DA1FFF8 */  lw    $at, -8($t5)
/* 036500 7F0019D0 AD21FFF8 */  sw    $at, -8($t1)
/* 036504 7F0019D4 8DA1FFFC */  lw    $at, -4($t5)
/* 036508 7F0019D8 15ACFFF8 */  bne   $t5, $t4, .L7F0019BC
/* 03650C 7F0019DC AD21FFFC */   sw    $at, -4($t1)
/* 036510 7F0019E0 8DA10000 */  lw    $at, ($t5)
/* 036514 7F0019E4 3C188003 */  lui   $t8, %hi(unknown_object_animation_controller) 
/* 036518 7F0019E8 2718A2D4 */  addiu $t8, %lo(unknown_object_animation_controller) # addiu $t8, $t8, -0x5d2c
/* 03651C 7F0019EC AD210000 */  sw    $at, ($t1)
/* 036520 7F0019F0 8DAC0004 */  lw    $t4, 4($t5)
/* 036524 7F0019F4 270E006C */  addiu $t6, $t8, 0x6c
/* 036528 7F0019F8 00604025 */  move  $t0, $v1
/* 03652C 7F0019FC AD2C0004 */  sw    $t4, 4($t1)
.L7F001A00:
/* 036530 7F001A00 8F010000 */  lw    $at, ($t8)
/* 036534 7F001A04 2718000C */  addiu $t8, $t8, 0xc
/* 036538 7F001A08 2508000C */  addiu $t0, $t0, 0xc
/* 03653C 7F001A0C AD01FFF4 */  sw    $at, -0xc($t0)
/* 036540 7F001A10 8F01FFF8 */  lw    $at, -8($t8)
/* 036544 7F001A14 AD01FFF8 */  sw    $at, -8($t0)
/* 036548 7F001A18 8F01FFFC */  lw    $at, -4($t8)
/* 03654C 7F001A1C 170EFFF8 */  bne   $t8, $t6, .L7F001A00
/* 036550 7F001A20 AD01FFFC */   sw    $at, -4($t0)
/* 036554 7F001A24 8F010000 */  lw    $at, ($t8)
/* 036558 7F001A28 3C0B8007 */  lui   $t3, %hi(dword_CODE_bss_80075C10) 
/* 03655C 7F001A2C 256B5C10 */  addiu $t3, %lo(dword_CODE_bss_80075C10) # addiu $t3, $t3, 0x5c10
/* 036560 7F001A30 AD010000 */  sw    $at, ($t0)
/* 036564 7F001A34 8F0E0004 */  lw    $t6, 4($t8)
/* 036568 7F001A38 00604825 */  move  $t1, $v1
/* 03656C 7F001A3C 246D006C */  addiu $t5, $v1, 0x6c
/* 036570 7F001A40 AD0E0004 */  sw    $t6, 4($t0)
.L7F001A44:
/* 036574 7F001A44 8D210000 */  lw    $at, ($t1)
/* 036578 7F001A48 2529000C */  addiu $t1, $t1, 0xc
/* 03657C 7F001A4C 256B000C */  addiu $t3, $t3, 0xc
/* 036580 7F001A50 AD61FFF4 */  sw    $at, -0xc($t3)
/* 036584 7F001A54 8D21FFF8 */  lw    $at, -8($t1)
/* 036588 7F001A58 AD61FFF8 */  sw    $at, -8($t3)
/* 03658C 7F001A5C 8D21FFFC */  lw    $at, -4($t1)
/* 036590 7F001A60 152DFFF8 */  bne   $t1, $t5, .L7F001A44
/* 036594 7F001A64 AD61FFFC */   sw    $at, -4($t3)
/* 036598 7F001A68 8D210000 */  lw    $at, ($t1)
/* 03659C 7F001A6C 3C198003 */  lui   $t9, %hi(taser_object_animation_controller) 
/* 0365A0 7F001A70 2739A348 */  addiu $t9, %lo(taser_object_animation_controller) # addiu $t9, $t9, -0x5cb8
/* 0365A4 7F001A74 AD610000 */  sw    $at, ($t3)
/* 0365A8 7F001A78 8D2D0004 */  lw    $t5, 4($t1)
/* 0365AC 7F001A7C 2738006C */  addiu $t8, $t9, 0x6c
/* 0365B0 7F001A80 00804025 */  move  $t0, $a0
/* 0365B4 7F001A84 AD6D0004 */  sw    $t5, 4($t3)
.L7F001A88:
/* 0365B8 7F001A88 8F210000 */  lw    $at, ($t9)
/* 0365BC 7F001A8C 2739000C */  addiu $t9, $t9, 0xc
/* 0365C0 7F001A90 2508000C */  addiu $t0, $t0, 0xc
/* 0365C4 7F001A94 AD01FFF4 */  sw    $at, -0xc($t0)
/* 0365C8 7F001A98 8F21FFF8 */  lw    $at, -8($t9)
/* 0365CC 7F001A9C AD01FFF8 */  sw    $at, -8($t0)
/* 0365D0 7F001AA0 8F21FFFC */  lw    $at, -4($t9)
/* 0365D4 7F001AA4 1738FFF8 */  bne   $t9, $t8, .L7F001A88
/* 0365D8 7F001AA8 AD01FFFC */   sw    $at, -4($t0)
/* 0365DC 7F001AAC 8F210000 */  lw    $at, ($t9)
/* 0365E0 7F001AB0 3C0C8007 */  lui   $t4, %hi(dword_CODE_bss_80075C88) 
/* 0365E4 7F001AB4 258C5C88 */  addiu $t4, %lo(dword_CODE_bss_80075C88) # addiu $t4, $t4, 0x5c88
/* 0365E8 7F001AB8 AD010000 */  sw    $at, ($t0)
/* 0365EC 7F001ABC 8F380004 */  lw    $t8, 4($t9)
/* 0365F0 7F001AC0 00805825 */  move  $t3, $a0
/* 0365F4 7F001AC4 2489006C */  addiu $t1, $a0, 0x6c
/* 0365F8 7F001AC8 AD180004 */  sw    $t8, 4($t0)
.L7F001ACC:
/* 0365FC 7F001ACC 8D610000 */  lw    $at, ($t3)
/* 036600 7F001AD0 256B000C */  addiu $t3, $t3, 0xc
/* 036604 7F001AD4 258C000C */  addiu $t4, $t4, 0xc
/* 036608 7F001AD8 AD81FFF4 */  sw    $at, -0xc($t4)
/* 03660C 7F001ADC 8D61FFF8 */  lw    $at, -8($t3)
/* 036610 7F001AE0 AD81FFF8 */  sw    $at, -8($t4)
/* 036614 7F001AE4 8D61FFFC */  lw    $at, -4($t3)
/* 036618 7F001AE8 1569FFF8 */  bne   $t3, $t1, .L7F001ACC
/* 03661C 7F001AEC AD81FFFC */   sw    $at, -4($t4)
/* 036620 7F001AF0 8D610000 */  lw    $at, ($t3)
/* 036624 7F001AF4 AD810000 */  sw    $at, ($t4)
/* 036628 7F001AF8 8D690004 */  lw    $t1, 4($t3)
/* 03662C 7F001AFC 27BD0160 */  addiu $sp, $sp, 0x160
/* 036630 7F001B00 03E00008 */  jr    $ra
/* 036634 7F001B04 AD890004 */   sw    $t1, 4($t4)
)
#endif


void initialize_temp_mine_table(void) {
    s32 i;
    for (i=0; i<30; i++)
    {
        temp_mine_table[i] = 0;
    }
}

