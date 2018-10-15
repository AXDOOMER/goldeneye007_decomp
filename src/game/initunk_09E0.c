#include "ultra64.h"

//fix when header known
extern s32 D_80036414;
extern s32 D_80036418;
extern s32 D_8003641C;


void sub_GAME_7F0009E0(s32 arg0, s32 arg1, s32 arg2) {
    D_80036414 = arg0;
    D_80036418 = arg1;
    D_8003641C = arg2;
}

