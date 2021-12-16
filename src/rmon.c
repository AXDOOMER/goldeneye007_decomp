#include <stdarg.h>
#include "ultra64.h"
#include "libultra/libc/xstdio.h"
#include "deb_print.h"
#include "rmon.h"


/**
 * Removed
 * rmonMain
 * rmon main function
 */
void rmonMain(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * rmonIsFinalBuild
 * returns true if this is the final build
 */
s32 rmonIsFinalBuild(void) {
    return ISFINALBUILD;
}

/**
 * REMOVED
 * rmonStatus
 * returns the status of rmon
 */
s32 rmonStatus(void) {
    #ifdef DEBUG
        //removed
    #else
        return -1;
    #endif

}


#ifdef NONMATCHING
/**
 * todo/hack/fixme:
 * Incompatible function definition. indy_commands requires the os.h definition,
 * but the function here has no arguments.
*/
void osWriteHost(void)
{
    // removed
}
#else
GLOBAL_ASM(
.text
glabel osWriteHost
jr $ra
nop
)
#endif

#ifdef NONMATCHING
/**
 * todo/hack/fixme:
 * Incompatible function definition. indy_commands requires the os.h definition,
 * but the function here has no arguments.
*/
void osReadHost(void)
{
    // removed
}
#else
GLOBAL_ASM(
.text
glabel osReadHost
jr $ra
nop
)
#endif

/**
 * Removed
 * rmon7000CEC8
 * unknown function
 */
void rmon7000CEC8(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 * rmon7000CED0
 * unknown function
 */
void rmon7000CED0(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 * rmon7000CED8
 * unknown function
 */
void rmon7000CED8(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 * rmon7000CEE0
 * unknown function
 */
void rmon7000CEE0(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * rmonprout
 */
 
char *rmonprout(char *dst, const char *src, size_t count) {

    s32 i = 0;
    while (i != count) {
        deboutWriteChar(src[i++]);
    }    
    return (char *)1;
}

/**
 * osSyncPrintf
 */
s32 osSyncPrintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    _Printf(&rmonprout, NULL, fmt, args);
}
