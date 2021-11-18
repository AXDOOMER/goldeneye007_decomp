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


#endif
