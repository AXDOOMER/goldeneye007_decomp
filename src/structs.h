#ifndef _TED_H_
#define _TED_H_

#include "ultra64.h"
#include "game/stan.h"

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
    float z;    // usually projected down, so z makes sense here.
};

struct PositionData {
    u8 objectClass; // enum EObjectClass
    u8 flags;
    short unknown_0x2;
    void* object_data;
    struct float3 position;
    struct StandTile * standTile;
    u32 unknown_0x18;
    struct positionData * host;
    struct positionData * child;
    struct positionData * prevAttachment;
    struct positionData * nextAttachment;
    char roomMaybe;
    u8 unknown_0x2d;
    u16 unknown_0x2e;
    u32 unknown_0x30;
};

#endif
