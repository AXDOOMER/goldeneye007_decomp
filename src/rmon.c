#include "ultra64.h"


void rmonproc(void) {
    // (function likely void)
}

s32 rmon_debug_is_final_build(void) {
    return 1;
}

s32 rmon_debug_returns_neg_1(void) {
    return -1;
}

void rmon_debug_stub(void) {
    // Removed
}

void rmon_debug_stub_0(void) {
    // Removed
}

void rmon_debug_stub_1(void) {
    // Removed
}

void rmon_debug_stub_2(void) {
    // Removed
}

void rmon_debug_stub_3(void) {
    // Removed
}

void rmon_debug_stub_4(void) {
    // Removed
}

void __osRdbSend(unsigned char);
char *proutSyncPrintf(char *dst, const char *src, size_t count) {
    s32 i = 0;
    while (i != count) {
        __osRdbSend(src[i++]);
    }    
    return 1;
}

#ifdef NONMATCHING
void osSyncPrintf(s32 arg0, s32 arg1, ? arg2, ? arg3)
{
    _Printf(&proutSyncPrintf, 0, arg0, &arg1);
}
#else
GLOBAL_ASM(
.text
glabel osSyncPrintf
/* 00DB44 7000CF44 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00DB48 7000CF48 AFA40020 */  sw    $a0, 0x20($sp)
/* 00DB4C 7000CF4C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00DB50 7000CF50 AFA50024 */  sw    $a1, 0x24($sp)
/* 00DB54 7000CF54 AFA60028 */  sw    $a2, 0x28($sp)
/* 00DB58 7000CF58 AFA7002C */  sw    $a3, 0x2c($sp)
/* 00DB5C 7000CF5C 3C047001 */  lui   $a0, %hi(proutSyncPrintf) # $a0, 0x7001
/* 00DB60 7000CF60 2484CEE8 */  addiu $a0, %lo(proutSyncPrintf) # addiu $a0, $a0, -0x3118
/* 00DB64 7000CF64 27A70024 */  addiu $a3, $sp, 0x24
/* 00DB68 7000CF68 8FA60020 */  lw    $a2, 0x20($sp)
/* 00DB6C 7000CF6C 0C004FD8 */  jal   _Printf
/* 00DB70 7000CF70 00002825 */   move  $a1, $zero
/* 00DB74 7000CF74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00DB78 7000CF78 27BD0020 */  addiu $sp, $sp, 0x20
/* 00DB7C 7000CF7C 03E00008 */  jr    $ra
/* 00DB80 7000CF80 00000000 */   nop  
)
#endif




