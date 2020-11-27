#ifndef _STAN_H_
#define _STAN_H_
#include "ultra64.h"


struct StanTilePoint {
    s16 x;
    s16 y;
    s16 z;
    u16 link;
};

struct StandTile {
    u32 nameAndRoom;
    u32 header;
    struct StanTilePoint points[9]; // actually a FAM fam
};

void stanInitDebugNoticeList(void);

#endif
