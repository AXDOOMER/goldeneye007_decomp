#include "ultra64.h"

#define PIAccessQueueSize 2

OSMesg piAccessBuf[PIAccessQueueSize];
OSMesgQueue __osPiAccessQueue;
u32 __osPiAccessQueueEnabled = 0;

void __osPiCreateAccessQueue(void) {
    __osPiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osPiAccessQueue, &piAccessBuf[0], PIAccessQueueSize - 1);
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osPiGetAccess(void) {
    OSMesg sp1c;
    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }
    osRecvMesg(&__osPiAccessQueue, &sp1c, OS_MESG_BLOCK);
}

void __osPiRelAccess(void) {
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
