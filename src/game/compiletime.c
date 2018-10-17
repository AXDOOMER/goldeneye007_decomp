#include "ultra64.h"






#ifdef NONMATCHING
void get_compile_time(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_compile_time
/* 1065E0 7F0D1AB0 3C028006 */  lui   $v0, 0x8006
/* 1065E4 7F0D1AB4 03E00008 */  jr    $ra
/* 1065E8 7F0D1AB8 2442C000 */   addiu $v0, $v0, -0x4000
)
#endif


