#include "ultra64.h"



#ifdef NONMATCHING
u32 osPiGetStatus(void) {
    // (possible return value: *(void *)PI_STATUS_REG)
}
#else
GLOBAL_ASM(
.text
glabel osPiGetStatus
/* 00DC70 7000D070 3C0EA460 */  lui   $t6, %hi(0xA4600010)
/* 00DC74 7000D074 03E00008 */  jr    $ra
/* 00DC78 7000D078 8DC20010 */   lw    $v0, %lo(0xA4600010)($t6)
)
#endif
