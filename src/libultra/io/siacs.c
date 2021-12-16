#include "include/PR/os.h"
#include "ultra64.h"

#define SIAccessQueueSize 2

OSMesg __osSiAccessBuf[SIAccessQueueSize];
OSMesgQueue __osSiAccessQueue;
u32 __osSiAccessQueueEnabled = 0;

void __osSiCreateAccessQueue() {
    __osSiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osSiAccessQueue, &__osSiAccessBuf[0], SIAccessQueueSize - 1);
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osSiGetAccess(void) {
    OSMesg sp1c;
    if (!__osSiAccessQueueEnabled) {
        __osSiCreateAccessQueue();
    }
    osRecvMesg(&__osSiAccessQueue, &sp1c, OS_MESG_BLOCK);
}

void __osSiRelAccess(void) {
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
