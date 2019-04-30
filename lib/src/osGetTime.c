#include "libultra_internal.h"

extern OSTime osCurrentTime;
extern u32 lastViCount;

OSTime osGetTime()
{
    u32 count;
    u32 diff;
    OSTime time;

    register u32 saveMask;
    saveMask = __osDisableInt();

    count = osGetCount();
    diff = count - lastViCount;
    time = osCurrentTime;

    __osRestoreInt(saveMask);

    return time + diff;
}
