#include "libultra_internal.h"
#include "include/PR/rcp.h"
#include "piint.h"

extern u32 osRomBase; // TODO: figure out why this is like this

s32 osPiRawStartDma(s32 dir, u32 cart_addr, void *dram_addr, size_t size) {
    register int status;
    WAIT_ON_IOBUSY(status);

    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dram_addr));

    IO_WRITE(PI_CART_ADDR_REG, (((uintptr_t) osRomBase | cart_addr) & 0x1fffffff));

    switch (dir) {
        case 0:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case 1:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
            break;
    }
    return 0;
}

#ifdef VERSION_EU
/*s32 osPiRawStartDma_2(s32 dir, u32 cart_addr, void *dram_addr, size_t size) {
    register int status;
    WAIT_ON_IOBUSY(status);

    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dram_addr));

    IO_WRITE(PI_CART_ADDR_REG, (((uintptr_t) osRomBase | cart_addr) & 0x1fffffff));

    switch (dir) {
        case 0:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case 1:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
            break;
    }
    return 0;
}*/
#endif
