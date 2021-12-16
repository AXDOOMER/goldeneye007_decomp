#include "include/PR/os.h"
#include "ultra64.h"
#include "osint.h"

OSPri osGetThreadPri(OSThread *thread) {
    if (thread == NULL) {
        thread = __osRunningThread;
    }
    return thread->priority;
}
