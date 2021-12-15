#include "libultra_internal.h"

extern OSTime __osCurrentTime;
extern u32 __osBaseCounter;

OSTime osGetTime() {
    u32 sp34;
    u32 sp30;
    OSTime sp28;
    register u32 int_disabled;
    int_disabled = __osDisableInt();
    sp34 = osGetCount();
    sp30 = sp34 - __osBaseCounter;
    sp28 = __osCurrentTime;
    __osRestoreInt(int_disabled);
    return sp28 + sp30;
}

