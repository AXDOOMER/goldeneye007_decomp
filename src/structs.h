#ifndef _TED_H_
#define _TED_H_

#include "ultra64.h"
#include "game/stan.h"

// Staying here for the moment.

struct float3
{
    f32 x;
    f32 y;
    f32 z;
};

struct float2
{
    f32 x;
    f32 z;
};

enum EObjectClass { // u8
    Zero,
    NormalObj1,
    Door,
    Guard,
    NormalObject2,
    Unknown,
    OtherPlayer
};

struct prop {
    u8 type; // enum EObjectClass
    u8 flags;
    s16 timetoregen;
    union {
        void *voidp;
        struct chrdata* chr;
        struct ObjectRecord* obj;
        // 	struct defaultobj *obj;
        // 	struct doorobj *door;
        // 	struct weaponobj *weapon;
        // 	struct explosion *explosion;
        // 	struct smoke *smoke;
    };
    /* 0x08 */
    struct float3 position;
    /* 0x14 */
    struct StandTile * standTile;
    /* 0x18 */
    u32 unknown_0x18;
    /* 0x1C */
    struct prop * host;
    struct prop * child;
    struct prop * nextSibling;
    struct prop * prevSibling;
    u8 rooms[4];
};

#endif
