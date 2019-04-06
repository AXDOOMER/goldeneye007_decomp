#include "ultra64.h"

#ifdef NONMATCHING
void osCreateMesgQueue(void *arg0, s32 arg1, ?32 arg2) {
    // Node 0
    *arg0 = &__osThreadTail;
    arg0->unk4 = &__osThreadTail;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = arg2;
    arg0->unk14 = arg1;
    return;
    // (function likely void)
}
#else
GLOBAL_ASM(
.text
glabel osCreateMesgQueue
/* 00E2D0 7000D6D0 3C0E8002 */  lui   $t6, %hi(__osThreadTail) # $t6, 0x8002
/* 00E2D4 7000D6D4 3C0F8002 */  lui   $t7, %hi(__osThreadTail) # $t7, 0x8002
/* 00E2D8 7000D6D8 25CE7720 */  addiu $t6, %lo(__osThreadTail) # addiu $t6, $t6, 0x7720
/* 00E2DC 7000D6DC 25EF7720 */  addiu $t7, %lo(__osThreadTail) # addiu $t7, $t7, 0x7720
/* 00E2E0 7000D6E0 AC8E0000 */  sw    $t6, ($a0)
/* 00E2E4 7000D6E4 AC8F0004 */  sw    $t7, 4($a0)
/* 00E2E8 7000D6E8 AC800008 */  sw    $zero, 8($a0)
/* 00E2EC 7000D6EC AC80000C */  sw    $zero, 0xc($a0)
/* 00E2F0 7000D6F0 AC860010 */  sw    $a2, 0x10($a0)
/* 00E2F4 7000D6F4 03E00008 */  jr    $ra
/* 00E2F8 7000D6F8 AC850014 */   sw    $a1, 0x14($a0)
)
#endif
