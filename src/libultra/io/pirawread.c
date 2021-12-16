#include "libultra_internal.h"
#include "include/PR/rcp.h"
#include "piint.h"

extern u32 osRomBase;

s32 osPiRawReadIo(u32 a0, u32 *a1) {
    register int status;
    WAIT_ON_IOBUSY(status);
    *a1 = IO_READ(osRomBase | a0);
    return 0;
}
