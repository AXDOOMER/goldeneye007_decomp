#include "ultra64"


OSMesg piCmdBuf;
OSMesgQueue piCmdQ[8];

GLOBAL_ASM()
glabel start_pi_manager
/* 00B8F0 7000ACF0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00B8F4 7000ACF4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00B8F8 7000ACF8 3C058006 */  lui   $a1, %hi(piCmdQ) # $a1, 0x8006
/* 00B8FC 7000ACFC 3C068006 */  lui   $a2, %hi(piCmdBuf) # $a2, 0x8006
/* 00B900 7000AD00 24C64EB0 */  addiu $a2, %lo(piCmdBuf) # addiu $a2, $a2, 0x4eb0
/* 00B904 7000AD04 24A54ED0 */  addiu $a1, %lo(piCmdQ) # addiu $a1, $a1, 0x4ed0
/* 00B908 7000AD08 24040096 */  li    $a0, 150
/* 00B90C 7000AD0C 0C00516C */  jal   osCreatePiManager
/* 00B910 7000AD10 24070008 */   li    $a3, 8
/* 00B914 7000AD14 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00B918 7000AD18 27BD0018 */  addiu $sp, $sp, 0x18
/* 00B91C 7000AD1C 03E00008 */  jr    $ra
/* 00B920 7000AD20 00000000 */   nop 
)

void start_pi_manager(void) {
    // Node 0
    osCreatePiManager(0x96, &piCmdQ, &piCmdBuf, 8);
    return;
    // (possible return value: osCreatePiManager(0x96, &piCmdQ, &piCmdBuf, 8))
}
