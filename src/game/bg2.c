#include <ultra64.h>
#include <PR/os.h>
#include <PR/gbi.h>
#include <bondconstants.h>
#include <fr.h>
#include <memp.h>
#include "bg.h"
#include "bondview.h"
#include "debugmenu_handler.h"
#include "decompress.h"
#include "fog.h"
#include "lvl.h"
#include "math_ceil.h"
#include "matrixmath.h"
#include "player.h"
#include "explosions.h"
#include "unk_0BC530.h"

// new file, per EU

#ifdef NONMATCHING
u32 sub_GAME_7F0BA5C0(u32 arg0, u32 arg1) {
    s32 temp_a0;
    u32 temp_v0;
    void *phi_v0;
    s32 phi_a0;
    void *phi_v1;

    // Node 0
    if (arg0 < arg1)
    {
        // Node 1
        phi_v0 = arg0;
loop_2:
        // Node 2
        if (DL_LUT_PRIMARY_ADDFOG != 0)
        {
            // Node 3
            phi_a0 = DL_LUT_PRIMARY_ADDFOG;
            phi_v1 = &DL_LUT_PRIMARY_ADDFOG;
loop_4:
            // Node 4
            if (*phi_v0 == phi_a0)
            {
                // Node 5
                if (phi_v0->unk4 == phi_v1->unk4)
                {
                    // Node 6
                    *phi_v0 = (s32) phi_v1->unk8;
                    phi_v0->unk4 = (s32) phi_v1->unkC;
                }
            }
            // Node 7
            temp_a0 = phi_v1->unk10;
            phi_a0 = temp_a0;
            phi_v1 = (phi_v1 + 0x10);
            if (temp_a0 != 0)
            {
                goto loop_4;
            }
        }
        // Node 8
        temp_v0 = (phi_v0 + 8);
        phi_v0 = temp_v0;
        if (temp_v0 < arg1)
        {
            goto loop_2;
        }
    }
    // Node 9
    return arg0;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BA5C0
/* 0EF0F0 7F0BA5C0 0085082B */  sltu  $at, $a0, $a1
/* 0EF0F4 7F0BA5C4 1020001C */  beqz  $at, .L7F0BA638
/* 0EF0F8 7F0BA5C8 00801025 */   move  $v0, $a0
/* 0EF0FC 7F0BA5CC 3C068004 */  lui   $a2, %hi(DL_LUT_PRIMARY_ADDFOG)
/* 0EF100 7F0BA5D0 24C64940 */  addiu $a2, %lo(DL_LUT_PRIMARY_ADDFOG) # addiu $a2, $a2, 0x4940
/* 0EF104 7F0BA5D4 8CCE0000 */  lw    $t6, ($a2)
.L7F0BA5D8:
/* 0EF108 7F0BA5D8 3C0F8004 */  lui   $t7, %hi(DL_LUT_PRIMARY_ADDFOG) 
/* 0EF10C 7F0BA5DC 25EF4940 */  addiu $t7, %lo(DL_LUT_PRIMARY_ADDFOG) # addiu $t7, $t7, 0x4940
/* 0EF110 7F0BA5E0 11C00011 */  beqz  $t6, .L7F0BA628
/* 0EF114 7F0BA5E4 00C01825 */   move  $v1, $a2
/* 0EF118 7F0BA5E8 8DE40000 */  lw    $a0, ($t7)
/* 0EF11C 7F0BA5EC 8C580000 */  lw    $t8, ($v0)
.L7F0BA5F0:
/* 0EF120 7F0BA5F0 5704000A */  bnel  $t8, $a0, .L7F0BA61C
/* 0EF124 7F0BA5F4 8C640010 */   lw    $a0, 0x10($v1)
/* 0EF128 7F0BA5F8 8C590004 */  lw    $t9, 4($v0)
/* 0EF12C 7F0BA5FC 8C680004 */  lw    $t0, 4($v1)
/* 0EF130 7F0BA600 57280006 */  bnel  $t9, $t0, .L7F0BA61C
/* 0EF134 7F0BA604 8C640010 */   lw    $a0, 0x10($v1)
/* 0EF138 7F0BA608 8C610008 */  lw    $at, 8($v1)
/* 0EF13C 7F0BA60C AC410000 */  sw    $at, ($v0)
/* 0EF140 7F0BA610 8C6A000C */  lw    $t2, 0xc($v1)
/* 0EF144 7F0BA614 AC4A0004 */  sw    $t2, 4($v0)
/* 0EF148 7F0BA618 8C640010 */  lw    $a0, 0x10($v1)
.L7F0BA61C:
/* 0EF14C 7F0BA61C 24630010 */  addiu $v1, $v1, 0x10
/* 0EF150 7F0BA620 5480FFF3 */  bnezl $a0, .L7F0BA5F0
/* 0EF154 7F0BA624 8C580000 */   lw    $t8, ($v0)
.L7F0BA628:
/* 0EF158 7F0BA628 24420008 */  addiu $v0, $v0, 8
/* 0EF15C 7F0BA62C 0045082B */  sltu  $at, $v0, $a1
/* 0EF160 7F0BA630 5420FFE9 */  bnezl $at, .L7F0BA5D8
/* 0EF164 7F0BA634 8CCE0000 */   lw    $t6, ($a2)
.L7F0BA638:
/* 0EF168 7F0BA638 03E00008 */  jr    $ra
/* 0EF16C 7F0BA63C 00000000 */   nop   
)

#endif




void bgLoadFromDynamicCCRMLUT(Gfx *arg0, Gfx *arg1, enum CCRMLUT arg2)
{
    Gfx *var_v0;
    Gfx *var_v1;

    static s32 D_80044DB0 = 0;

    var_v0 = arg0;

    while (((arg1 != NULL) && (var_v0 < arg1)) || ((arg1 == NULL) && (((s8*)var_v0)[0] != (s8)G_ENDDL)))
    {
        for (var_v1 = ptrDynamic_CC_RM_LUT[(s32)arg2]; var_v1->words.w0 != 0; var_v1 += 2)
        {
            if ((var_v1->words.w0 == var_v0->words.w0) && (var_v1->words.w1 == var_v0->words.w1))
            {
                D_80044DB0 += 1;
                
                *var_v0 = *(var_v1+1);
            }
        }

        var_v0++;
    }
}
