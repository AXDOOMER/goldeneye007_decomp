#ifndef _STAN_H_
#define _STAN_H_
#include "ultra64.h"


struct TilePoint {
    s16 x;
    s16 y;
    s16 z;
    u16 link;
};

struct Tile {
    u32 nameAndRoom;
    u32 header;
    struct TilePoint points[9]; // actually a FAM
};

void stanInitDebugNoticeList(void);

#endif
