#include "libultra_internal.h"
#include "include/PR/rcp.h"

s32 __osSpRawStartDma(u32 dir, u32 devAddr, void *dram_ptr, size_t size) {
    if (__osSpDeviceBusy()) {
        return -1;
    }
    IO_WRITE(SP_MEM_ADDR_REG, devAddr);
    IO_WRITE(SP_DRAM_ADDR_REG, osVirtualToPhysical(dram_ptr));
    if (dir == OS_READ)
        IO_WRITE(SP_WR_LEN_REG, size - 1);
    else
        IO_WRITE(SP_RD_LEN_REG, size - 1);
    return 0;
}
