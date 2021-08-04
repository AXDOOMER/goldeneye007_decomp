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
ModelSkeleton SKELETON(cctv) = {2, 0, JOINTLIST(cctv), 6, 0};

//D:8003A068
ModelJoint JOINTLIST(console_one_screen)[1] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A070
ModelSkeleton SKELETON(console_one_screen) = {1, 0, JOINTLIST(console_one_screen), 3, 0};

//D:8003A07C
ModelJoint JOINTLIST(console_four_screen)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A084
ModelSkeleton SKELETON(console_four_screen) = {1, 0, JOINTLIST(console_four_screen), 3, 0};

//D:8003A090
ModelJoint JOINTLIST(tv_holder)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A0B0
ModelSkeleton SKELETON(tv_holder) = {5, 0, JOINTLIST(tv_holder), 0xF, 0};

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
ModelSkeleton SKELETON(rotating_stuff) = {6, 0, JOINTLIST(rotating_stuff), 0x12, 0};

//D:8003A0EC
ModelJoint JOINTLIST(eyelid_door)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006}
};
//D:8003A100
ModelSkeleton SKELETON(eyelid_door) = {3, 0, JOINTLIST(eyelid_door), 9, 0};

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
ModelSkeleton SKELETON(iris_door) = {0xD, 0, JOINTLIST(iris_door), 0x27, 0};

//D:8003A168
ModelJoint JOINTLIST(walletbond)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A170
ModelSkeleton SKELETON(walletbond) = {1, 0, JOINTLIST(walletbond), 3, 0};

//D:8003A17C
ModelJoint JOINTLIST(car)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A19C
ModelSkeleton SKELETON(car) = {5, 0, JOINTLIST(car), 0xF, 0};

//D:8003A1A8
ModelJoint JOINTLIST(flying)[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0015, 0x0003, 0x0003},
    {0x0015, 0x0004, 0x0004},
    {0x0015, 0x0005, 0x0005}
};
//D:8003A1C8
ModelSkeleton SKELETON(flying) = {5, 0, JOINTLIST(flying), 3, 0};

//D:8003A1D4
ModelJoint JOINTLIST(door)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A1DC
ModelSkeleton SKELETON(door) = {1, 0, JOINTLIST(door), 3, 0};

//D:8003A1E8
ModelJoint JOINTLIST(tank)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A208
ModelSkeleton SKELETON(tank) = {5, 0, JOINTLIST(tank), 0xF, 0};

//D:8003A214
ModelJoint JOINTLIST(hat)[] = {
    {0x0015, 0x0000, 0x0000},
};
//D:8003A21C
ModelSkeleton SKELETON(hat) = {1, 0, JOINTLIST(hat), 0, 0};

//D:8003A228                     .globl PitemZ_entries
#include "assets/obseg/prop/propItemModelFileRecord.inc.c"

//D:8003b224
#include "assets/obseg/prop/propExplosionDetailsRecords.inc.c"
