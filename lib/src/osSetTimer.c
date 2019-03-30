#include "libultra_internal.h"

// Externs defined in osTimer.c
extern OSTimer *firstTimer;
extern u64 __osInsertTimer(OSTimer *);

u32 osSetTimer(OSTimer *timer, OSTime countdown, u64 interval, OSMesgQueue *mq, OSMesg msg)
{
    u64 rem;
    timer->next = NULL;
    timer->prev = NULL;
    timer->interval = interval;
    if (countdown != 0)
    {
        timer->remaining = countdown;
    }
    else
    {
        timer->remaining = interval;
    }
    timer->mq = mq;
    timer->msg = msg;
    rem = __osInsertTimer(timer);
    if (firstTimer->next == timer)
    {
        __osSetTimerIntr(rem);
    }
    return 0;
}
