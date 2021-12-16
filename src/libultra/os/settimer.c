#include "include/PR/os.h"
#include "ultra64.h"

extern OSTimer *__osTimerList;
extern u64 __osInsertTimer(OSTimer *);

int osSetTimer(OSTimer *a0, OSTime a1, OSTime a2, OSMesgQueue *a3, OSMesg a4) {
    u64 sp18;
    a0->next = NULL;
    a0->prev = NULL;
    a0->interval = a2;
    if (a1 != 0) {
        a0->value = a1;
    } else {
        a0->value = a2;
    }
    a0->mq = a3;
    a0->msg = a4;
    sp18 = __osInsertTimer(a0);
    if (__osTimerList->next == a0) {
        __osSetTimerIntr(sp18);
    }
    return 0;
}
