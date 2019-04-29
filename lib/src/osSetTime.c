#include "libultra_internal.h"
extern OSTime osCurrentTime;
void osSetTime(OSTime time)
{
    osCurrentTime = time;
}
