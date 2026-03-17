#ifndef _OSINT_H_
#define _OSINT_H_

/**************************************************************************
 *                                                                        *
 *               Copyright (C) 1994, Silicon Graphics, Inc.               *
 *                                                                        *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *                                                                        *
 **************************************************************************/

#include <os.h>
#include <os_internal.h>
#include <sptask.h>
#include <ucontext.h>

/***************************************
 *
 * Type definitions
 *
 */
typedef struct
{
    OSThread *next;
    OSPri     priority;
} __OSThreadTail;

typedef struct
{
    OSMesgQueue *messageQueue;
    OSMesg       message;
} __OSEventState;

/***************************************
 *
 * Macro definitions
 *
 */

/* Debug macros */

#ifdef DEBUG

extern unsigned long Dflags; /* Global debug flag */

    /* Debug flag settings */
    #define DALL     0xFFFFFFFF /* Turn on all debug types */
    #define DERROR   0x00000001 /* Turn on error tracing */
    #define DTHREAD  0x00000002 /* Turn on thread tracing */
    #define DTIMER   0x00000004 /* Turn on timer tracing */
    #define DMESSAGE 0x00000008 /* Turn on message tracing */
    #define DMEMORY  0x00000010 /* Turn on memory tracing */
    #define DREGION  0x00000020 /* Turn on region tracing */

    #define _TRACE(type, code)                          \
        {                                               \
            if (Dflags & (type))                        \
            {                                           \
                printf("%s, %d: ", __FILE__, __LINE__); \
                code;                                   \
            }                                           \
        }

    #define _ASSERT(EX) ((EX) ? _Assert(__FILE__, __LINE__, #EX) : ((void)0))

#else
    #define _TRACE(type, code)
    #define _ASSERT(EX)
#endif

/***************************************
 *
 * Extern function prototypes
 *
 */

/* exports from devmgr.c */

extern void           __osDevMgrMain(void *);

/* exports from event.c */

extern __OSEventState __osEventStateTab[];

/* exports from interrupt.c */

extern u32            __osDisableInt(void);
extern void           __osRestoreInt(u32);

/* exports from thread.c */

extern __OSThreadTail __osThreadTail;
extern OSThread      *__osRunningThread;
extern OSThread      *__osRunQueue;
extern OSThread      *__osActiveQueue;
extern OSThread      *__osActiveQueueTail;

extern void           __osPrintRunQueue(void);
extern void           __osEnqueueThread(OSThread **, OSThread *);
extern void           __osDequeueThread(OSThread **, OSThread *);
extern OSThread      *__osPopThread(OSThread **);

/* exports from unixthread.c */

extern ucontext_t     __osDispatchContext;
extern void           __osCleanupThread(void);
extern void           __osDispatcher(void);
extern void           __osDispatchThread(void);
extern void           __osEnqueueAndYield(OSThread **);

// #endif  /* _OSINT_H_ */

// not sure if this should be here
extern s32            osViClock;
extern void           __osTimerServicesInit(void);
extern s32            __osAiDeviceBusy(void);
extern int            __osDpDeviceBusy(void);

extern void           __osSetTimerIntr(OSTime);
extern OSTime         __osInsertTimer(OSTimer *);
extern void           __osTimerInterrupt(void);
extern u32            __osProbeTLB(void *);
extern int            __osSpDeviceBusy(void);
extern OSThread      *__osFaultedThread;
extern OSTimer       *__osTimerList;
extern OSTimer        __osBaseTimer;
extern OSTime         __osCurrentTime;
extern u32            __osBaseCounter;
extern u32            __osViIntrCount;
extern u32            __osTimerCounter;
#endif
