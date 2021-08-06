#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"

//D:800375D0
#include "assets/obseg/prop/propModelFileHeaders.inc.c"

//D:8003A050
ModelJoint JOINTLIST(cctv)[2] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003}
};
//D:8003A05C
MODELSKELETON(cctv, 2, 6)



//D:8003A068
ModelJoint JOINTLIST(console_one_screen)[1] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A070
MODELSKELETON(console_one_screen, 1, 3)



//D:8003A07C
ModelJoint JOINTLIST(console_four_screen)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A084
MODELSKELETON(console_four_screen, 1, 3)

//D:8003A090
ModelJoint JOINTLIST(tv_holder)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A0B0
MODELSKELETON(tv_holder, 5, 0xF)



//D:8003A0BC
ModelJoint JOINTLIST(rotating_stuff)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003A0E0
MODELSKELETON(rotating_stuff, 6, 0x12)



//D:8003A0EC
ModelJoint JOINTLIST(eyelid_door)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006}
};
MODELSKELETON(eyelid_door, 3, 9)



//D:8003A10C
ModelJoint JOINTLIST(iris_door)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012},
    {0x0002, 0x0015, 0x0015},
    {0x0002, 0x0018, 0x0018},
    {0x0002, 0x001B, 0x001B},
    {0x0002, 0x001E, 0x001E},
    {0x0002, 0x0021, 0x0021},
    {0x0002, 0x0024, 0x0024}
};
//D:8003A15C
MODELSKELETON(iris_door, 0xD, 0x27)



//D:8003A168
ModelJoint JOINTLIST(walletbond)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A170
MODELSKELETON(walletbond, 1, 3)



//D:8003A17C
ModelJoint JOINTLIST(car)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A19C
MODELSKELETON(car, 5, 0xF)


//D:8003A1A8
ModelJoint JOINTLIST(flying)[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0015, 0x0003, 0x0003},
    {0x0015, 0x0004, 0x0004},
    {0x0015, 0x0005, 0x0005}
};
//D:8003A1C8
MODELSKELETON(flying, 5, 3)



//D:8003A1D4
ModelJoint JOINTLIST(door)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A1DC
MODELSKELETON(door, 1, 3)



//D:8003A1E8
ModelJoint JOINTLIST(tank)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A208
MODELSKELETON(tank, 5, 0xF)



//D:8003A214
ModelJoint JOINTLIST(hat)[] = {
    {0x0015, 0x0000, 0x0000},
};
//D:8003A21C
MODELSKELETON(hat, 1, 0)



//D:8003A228                     .globl PitemZ_entries
#include "assets/obseg/prop/propItemModelFileRecord.inc.c"

//D:8003b224
#include "assets/obseg/prop/propExplosionDetailsRecords.inc.c"
