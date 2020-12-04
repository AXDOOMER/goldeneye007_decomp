#ifndef _STAN_H_
#define _STAN_H_
#include "ultra64.h"


struct StandTilePoint {
    s16 x;
    s16 y;
    s16 z;
    u16 link;
};

struct StandTileHeaderTail {
    s16 pointCount : 4; // seen lh, not lhu. Also seen with an explicit unnecessary '& 0xF' 
    s16 headerC : 4;
    s16 headerD : 4;
    s16 headerE : 4;
};

struct StandTile {
    u16 name1;
    u8 name2;
    u8 room;    // compared to 0xFF, not -1 in a function
    s16 headerA;

    /* 0x06 */
    // They appear to have performed the bit field work themselves here,
    //   but we provide the StandTileHeaderTail member for clarity - it should be unused I believe.
    s16 hdrTail;

    /* 0x08 */
    struct StandTilePoint points[1];
};

void stanInitDebugNoticeList(void);

#endif
