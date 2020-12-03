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
    u16 name1;
    u8 name2;
    u8 room;    // compared to 0xFF, not -1 in a function
    s16 headerA;

    s8 pointCount : 4; // seen lh, not lhu. Also seen with an explicit unnecessary '& 0xF' 
    u8 headerC : 4;
    u8 headerD;

    /* 0x08 */
    struct StandTilePoint points[1];
};

void stanInitDebugNoticeList(void);

#endif
