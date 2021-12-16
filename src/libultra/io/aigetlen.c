#include "libultra_internal.h"
#include "include/PR/os.h"
#include "include/PR/rcp.h"

u32 osAiGetLength() {
    return IO_READ(AI_LEN_REG);
}
