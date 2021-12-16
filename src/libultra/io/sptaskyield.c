#include "include/PR/os.h"
#include "ultra64.h"

void osSpTaskYield(void) {
    __osSpSetStatus(SPSTATUS_SET_SIGNAL0);
}
