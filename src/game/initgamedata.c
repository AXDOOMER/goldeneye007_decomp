#include "ultra64.h"









#ifdef NONMATCHING
void initGameData(void) {
    current_menu = -1;
    menu_update = 0;
    maybe_prev_menu = -1;
    menu_timer = 0;
    selected_stage = -1;
    ptr_briefingdata = -1;
    selected_difficulty = -1;
    screen_size = 0;
    folder_selection_screen_option_icon = 0;
    selected_folder_num = 0;
    mission_failed_or_aborted = 0;
    is_first_time_on_legal_screen = 1;
    is_first_time_on_main_menu = 1;
    prev_keypresses = 0;
    maybe_is_in_menu = 1;
    slider_007_mode_reaction = 0.0f;
    slider_007_mode_health = 1.0f;
    slider_007_mode_accuracy = 1.0f;
    slider_007_mode_damage = 1.0f;
    do_not_play_intro_movie = 0;
    randomly_selected_intro_animation = 0;
    intro_animation_count = 0;
    D_8002B5F4 = 0;
    D_8002B5F8 = 0;
    full_actor_intro = 0;
}
#else
GLOBAL_ASM(
.text
glabel initGameData
/* 034B30 7F000000 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 034B34 7F000004 44810000 */  mtc1  $at, $f0
/* 034B38 7F000008 2402FFFF */  li    $v0, -1
/* 034B3C 7F00000C 3C018003 */  lui   $at, %hi(current_menu) # $at, 0x8003
/* 034B40 7F000010 AC22A8C0 */  sw    $v0, %lo(current_menu)($at)
/* 034B44 7F000014 3C018003 */  lui   $at, %hi(menu_update) # $at, 0x8003
/* 034B48 7F000018 AC20A8C4 */  sw    $zero, %lo(menu_update)($at)
/* 034B4C 7F00001C 3C018003 */  lui   $at, %hi(maybe_prev_menu) # $at, 0x8003
/* 034B50 7F000020 AC22A8C8 */  sw    $v0, %lo(maybe_prev_menu)($at)
/* 034B54 7F000024 3C018003 */  lui   $at, %hi(menu_timer) # $at, 0x8003
/* 034B58 7F000028 AC20A8CC */  sw    $zero, %lo(menu_timer)($at)
/* 034B5C 7F00002C 3C018003 */  lui   $at, %hi(selected_stage) # $at, 0x8003
/* 034B60 7F000030 AC22A8F4 */  sw    $v0, %lo(selected_stage)($at)
/* 034B64 7F000034 3C018003 */  lui   $at, %hi(ptr_briefingdata) # $at, 0x8003
/* 034B68 7F000038 AC22A8F8 */  sw    $v0, %lo(ptr_briefingdata)($at)
/* 034B6C 7F00003C 3C018003 */  lui   $at, %hi(selected_difficulty) # $at, 0x8003
/* 034B70 7F000040 AC22A8FC */  sw    $v0, %lo(selected_difficulty)($at)
/* 034B74 7F000044 3C018003 */  lui   $at, %hi(screen_size) # $at, 0x8003
/* 034B78 7F000048 AC20A940 */  sw    $zero, %lo(screen_size)($at)
/* 034B7C 7F00004C 3C018003 */  lui   $at, %hi(folder_selection_screen_option_icon) # $at, 0x8003
/* 034B80 7F000050 AC20A918 */  sw    $zero, %lo(folder_selection_screen_option_icon)($at)
/* 034B84 7F000054 3C018003 */  lui   $at, %hi(selected_folder_num) # $at, 0x8003
/* 034B88 7F000058 AC20A8E8 */  sw    $zero, %lo(selected_folder_num)($at)
/* 034B8C 7F00005C 3C018003 */  lui   $at, %hi(mission_failed_or_aborted) # $at, 0x8003
/* 034B90 7F000060 AC20A924 */  sw    $zero, %lo(mission_failed_or_aborted)($at)
/* 034B94 7F000064 24030001 */  li    $v1, 1
/* 034B98 7F000068 3C018003 */  lui   $at, %hi(is_first_time_on_legal_screen) # $at, 0x8003
/* 034B9C 7F00006C AC23A92C */  sw    $v1, %lo(is_first_time_on_legal_screen)($at)
/* 034BA0 7F000070 3C018003 */  lui   $at, %hi(is_first_time_on_main_menu) # $at, 0x8003
/* 034BA4 7F000074 AC23A930 */  sw    $v1, %lo(is_first_time_on_main_menu)($at)
/* 034BA8 7F000078 3C018003 */  lui   $at, %hi(prev_keypresses) # $at, 0x8003
/* 034BAC 7F00007C AC20A934 */  sw    $zero, %lo(prev_keypresses)($at)
/* 034BB0 7F000080 44802000 */  mtc1  $zero, $f4
/* 034BB4 7F000084 3C018003 */  lui   $at, %hi(maybe_is_in_menu) # $at, 0x8003
/* 034BB8 7F000088 AC23A93C */  sw    $v1, %lo(maybe_is_in_menu)($at)
/* 034BBC 7F00008C 3C018003 */  lui   $at, %hi(slider_007_mode_reaction) # $at, 0x8003
/* 034BC0 7F000090 E424A9A0 */  swc1  $f4, %lo(slider_007_mode_reaction)($at)
/* 034BC4 7F000094 3C018003 */  lui   $at, %hi(slider_007_mode_health) # $at, 0x8003
/* 034BC8 7F000098 E420A9A4 */  swc1  $f0, %lo(slider_007_mode_health)($at)
/* 034BCC 7F00009C 3C018003 */  lui   $at, %hi(slider_007_mode_accuracy) # $at, 0x8003
/* 034BD0 7F0000A0 E420A9A8 */  swc1  $f0, %lo(slider_007_mode_accuracy)($at)
/* 034BD4 7F0000A4 3C018003 */  lui   $at, %hi(slider_007_mode_damage) # $at, 0x8003
/* 034BD8 7F0000A8 E420A9AC */  swc1  $f0, %lo(slider_007_mode_damage)($at)
/* 034BDC 7F0000AC 3C018003 */  lui   $at, %hi(do_not_play_intro_movie) # $at, 0x8003
/* 034BE0 7F0000B0 AC20B5E8 */  sw    $zero, %lo(do_not_play_intro_movie)($at)
/* 034BE4 7F0000B4 3C018003 */  lui   $at, %hi(randomly_selected_intro_animation) # $at, 0x8003
/* 034BE8 7F0000B8 AC20B5EC */  sw    $zero, %lo(randomly_selected_intro_animation)($at)
/* 034BEC 7F0000BC 3C018003 */  lui   $at, %hi(intro_animation_count) # $at, 0x8003
/* 034BF0 7F0000C0 AC20B5F0 */  sw    $zero, %lo(intro_animation_count)($at)
/* 034BF4 7F0000C4 3C018003 */  lui   $at, %hi(D_8002B5F4) # $at, 0x8003
/* 034BF8 7F0000C8 AC20B5F4 */  sw    $zero, %lo(D_8002B5F4)($at)
/* 034BFC 7F0000CC 3C018003 */  lui   $at, %hi(D_8002B5F8) # $at, 0x8003
/* 034C00 7F0000D0 AC20B5F8 */  sw    $zero, %lo(D_8002B5F8)($at)
/* 034C04 7F0000D4 3C018003 */  lui   $at, %hi(full_actor_intro)
/* 034C08 7F0000D8 03E00008 */  jr    $ra
/* 034C0C 7F0000DC AC20B5FC */   sw    $zero, %lo(full_actor_intro)($at)
)
#endif

