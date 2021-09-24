#ifndef _STAN_H_
#define _STAN_H_
#include "ultra64.h"



typedef struct StandTilePoint {
    s16 x;
    s16 y;
    s16 z;
    u16 link;
} StandTilePoint;

typedef struct StandTileHeaderMid {
    u16 special : 4; 
    u16 r : 4;
    u16 g : 4;
    u16 b : 4;
} StandTileHeaderMid;

typedef struct StandTileHeaderTail {
    s16 pointCount : 4; // seen lh, not lhu. Also seen with an explicit unnecessary '& 0xF' 
    s16 headerC : 4;
    s16 headerD : 4;
    s16 headerE : 4;
} StandTileHeaderTail;

typedef struct StandTile {
    u32 name1:24;

    u8 room;    // compared to 0xFF, not -1 in a function. Seen LBUs.
    StandTileHeaderMid headerMid;

    /* 0x06 */
    // They appear to have performed the bit field work themselves here,
    //   but we provide the StandTileHeaderTail member for clarity - it should be unused I believe.
    StandTileHeaderTail hdrTail;

    /* 0x08 */
    struct StandTilePoint points[];
} StandTile;

typedef struct StandFilePoint {
    u16 x;
    u16 y;
    u16 z;
    u16 link;
} StandFilePoint;

typedef struct StandFileTile {
    u32 name1:24;
    //u8 name2;
    u8 room;    // compared to 0xFF, not -1 in a function. Seen LBUs.
    StandTileHeaderMid headerMid;

    /* 0x06 */
    // They appear to have performed the bit field work themselves here,
    //   but we provide the StandTileHeaderTail member for clarity - it should be unused I believe.
    StandTileHeaderTail hdrTail;

    /* 0x08 */
    //hack remove for compiling stan files
    //struct StandTilePoint points[1];
} StandFileTile;

typedef struct StandFileHeader {
    void* unk1;
    StandTile *firstTile;
    u8 unk2[];
} StandFileHeader;

// RGB? I've called them 'triple' because I don't really know what RGB is
// No parens around params
#define STAN_TRIPLE_TO_PNT_INDEX(tile, tripleIndex) (tile->hdrTail >> (8 - 4*tripleIndex) & 0xF)
#define STAN_POINT_COUNT(tile) (tile->hdrTail.pointCount & 0xF)

// May be internal only, nice here.
struct StandTileWalkCallbackRecord {
    s32 * roomBuf;
    s32 count;
    s32 bufMax;
    s32 lastRoom;
};
typedef void (*standTileWalkCallback_t)(struct StandTile*, struct StandTile*, struct StandTileWalkCallbackRecord*);
// Necessary forward declaration
void noteTileRoomIfDifferentToPrev(struct StandTile *tile, struct StandTile *unused, struct StandTileWalkCallbackRecord *data);

// Very similar but definitely different to the above?
struct StandTileLocusCallbackRecord {
    s32 * roomBuf;
    s32 count;
    s32 bufMax;
    s32 nearEdgeCount;
};

typedef struct StandFileFooter {
    char strictstring[8];
    void* unk3;
    void* unk4;
    void* unk5;
    void* unk6;
} StandFileFooter;

typedef s32 (*standTileLocusCallback_A_t)(struct StandTile*, struct StandTileLocusCallbackRecord*);
typedef s32 (*standTileLocusCallback_B_t)(struct StandTile*, s32, float, float, void, float*);  // 5th parameter uncertain
typedef s32 (*standTileLocusCallback_C_t)(struct StandTile**, s32, struct StandTileLocusCallbackRecord*);

typedef s32 (*tilePredicate_t)(struct StandTile*);

void stanInitDebugNoticeList(void);

/* Beta definitions, to allow citadel stan in .c file to build into .bin */

typedef struct BetaStandFilePoint {
    float x;
    float y;
    float z;
    u32 link;
} BetaStandFilePoint;

typedef struct BetaStandTileHeaderTail {
    u8 pointCount;
    u8 headerC;
    u8 headerD;
    u8 headerE;
} BetaStandTileHeaderTail;

typedef struct BetaStandTile {
    const char *debugName;
    StandTileHeaderMid headerMid;
    u16 betaUnknown;
    BetaStandTileHeaderTail hdrTail;
    struct BetaStandFilePoint points[];
} BetaStandTile;

StandTilePoint *stanMatchTileName(char*);

#endif
