#include "libultra_internal.h"
#include "include/PR/rcp.h"

s32 __osSiRawReadIo(void *a0, u32 *a1) {
    if (__osSiDeviceBusy()) {
        return -1;
    }
    *a1 = IO_READ((uintptr_t) a0);
    return 0;
}
