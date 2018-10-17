#include "ultra64.h"

/* rodata
D:8005C000     build_date:     .ascii "Jun 29 1997 20:46:05"<0><0><0><0>
D:8005C000                                              # DATA XREF: get_compile_time+8o
*/




#ifdef NONMATCHING
char *get_compile_time(void) {
    return "Jun 29 1997 20:46:05";
}
#else
GLOBAL_ASM(
.text
glabel get_compile_time
/* 1065E0 7F0D1AB0 3C028006 */  lui   $v0, %hi(build_date)
/* 1065E4 7F0D1AB4 03E00008 */  jr    $ra
/* 1065E8 7F0D1AB8 2442C000 */   addiu $v0, $v0, %lo(build_date)
)
#endif


