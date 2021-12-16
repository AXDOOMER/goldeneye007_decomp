#include "include/PR/os.h"
#include "ultra64.h"
#include "viint.h"

extern __OSViContext *__osViNext;

void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount) {
    register u32 int_disabled = __osDisableInt();
    (__osViNext)->msgq = mq;
    (__osViNext)->msg = msg;
    (__osViNext)->retraceCount = retraceCount;
    __osRestoreInt(int_disabled);
}
