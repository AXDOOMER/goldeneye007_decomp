#include "ultra64.h"


OSMesg piCmdBuf;
OSMesgQueue piCmdQ[8];

void start_pi_manager(void) {
    osCreatePiManager(0x96, &piCmdQ, &piCmdBuf, 8);
}
