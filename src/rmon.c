#include <stdarg.h>
#include "ultra64.h"
#include "deb_print.h"

/**
 * Removed
 */
void rmonMain(void) {
    #ifdef DEBUG
        //removed
    #endif
}

s32 rmonIsFinalBuild(void) {
    #ifdef DEBUG
        return FALSE; //removed
    #else
        return TRUE;
    #endif
}

/**
 * Removed
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
 */
void rmonHostWriteData(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 */
void rmonHostReadData(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 */
void rmon7000CEC8(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 */
void rmon7000CED0(void) {
    // Removed
}

/**
 * Removed
 */
void rmon7000CED8(void) {
    #ifdef DEBUG
        //removed
    #endif
}

/**
 * Removed
 */
void rmon7000CEE0(void) {
    #ifdef DEBUG
        //removed
    #endif
}

char *rmonprout(char *dst, const char *src, size_t count) {
    s32 i = 0;
    while (i != count) {
        deboutWriteChar(src[i++]);
    }    
    return 1;
}

s32 osSyncPrintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    _Printf(&rmonprout, NULL, fmt, args);
}
