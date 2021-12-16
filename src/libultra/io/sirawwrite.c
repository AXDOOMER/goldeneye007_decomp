#include "include/PR/rcp.h"

s32 __osSiRawWriteIo(void *a0, u32 a1) {
    if (__osSiDeviceBusy()) {
        return -1;
    }
    IO_WRITE((uintptr_t) a0, a1);
    return 0;
}
