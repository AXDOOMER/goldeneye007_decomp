#ifndef _RMON_H_
#define _RMON_H_

#ifdef DEBUG
    #define ISFINALBUILD 0
#else
    #define ISFINALBUILD 1
#endif

void rmonMain(void);
s32 rmonIsFinalBuild(void);
s32 rmonStatus(void);
void osWriteHost(void * arg0, u32 arg1);
void osReadHost(void * arg0, u32 arg1);
s32 osSyncPrintf(const char *fmt, ...);

#endif
