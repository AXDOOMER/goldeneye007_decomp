#include <stdarg.h>
#include "ultra64.h"
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

/**
 * Removed
 * osWriteHost
 * writes data to the host
 */
void osWriteHost(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 * osReadHost
 * reads data from the host
 */
void osReadHost(void) {
    #ifdef DEBUG
        //removed
    #endif
}

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
    return 1;
}

/**
 * osSyncPrintf
 */
s32 osSyncPrintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    _Printf(&rmonprout, NULL, fmt, args);
}
