#ifndef _RMON_H_
#define _RMON_H_
#include <ultra64.h>
#ifdef DEBUG
    #define ISFINALBUILD 0
#else
    #define ISFINALBUILD 1
#endif
void rmonMain(void);
s32 rmonIsFinalBuild(void);
s32 rmonStatus(void);
void rmonHostWriteData(void);
void rmonHostReadData(void);
s32 osSyncPrintf(const char *fmt, ...);

#endif
