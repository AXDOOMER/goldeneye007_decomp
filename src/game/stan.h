#ifndef _STAN_H_
#define _STAN_H_
#include "ultra64.h"


struct StandTilePoint {
    s16 x;
    s16 y;
    s16 z;
    u16 link;
};

struct StandTile {
    u32 nameAndRoom;
    u32 header;
    struct StandTilePoint points[1];
};

void stanInitDebugNoticeList(void);

#endif
