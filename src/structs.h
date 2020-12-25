#ifndef _TED_H_
#define _TED_H_

#include "ultra64.h"
#include "game/stan.h"

// Staying here for the moment.

enum EObjectClass { // u8
    Zero,
    NormalObj1,
    Door,
    Guard,
    NormalObject2,
    Unknown,
    OtherPlayer
};

struct float3 {
    float x;
    float y;
    float z;
};

struct float2 {
    float x;
    float z;
};

struct PositionData {
    u8 objectClass; // enum EObjectClass
    u8 flags;
    short unknown_0x2;
    void* object_data;
    /* 0x08 */
    struct float3 position;
    /* 0x14 */
    struct StandTile * standTile;
    /* 0x18 */
    u32 unknown_0x18;
    /* 0x1C */
    struct PositionData * host;
    struct PositionData * child;
    struct PositionData * nextSibling;
    struct PositionData * prevSibling;
    u8 rooms[4];
};

#endif
