#include "ultra64.h"
#include "game/unk_0C0A70.h"

// data
s32 D_80048490 = -1;
s32 D_80048494 = 0;

/**
 * Appears to be rendered framerate, or some kind of counter since the last frame update.
 */
s32 D_80048498 = 1;
#ifdef VERSION_JP
f32 jpD_800484CC = 1.0f;
f32 jpD_800484D0 = 1.0f;
#endif
s32 D_8004849C = -1;
s32 D_800484A0 = 0;
s32 D_800484A4 = 0;
s32 D_800484A8 = 0;
u32 copy_of_osgetcount_value_0 = 0;
u32 copy_of_osgetcount_value_1 = 0;
s32 D_800484B4 = 1;




void store_osgetcount(void)
{
    copy_of_osgetcount_value_1 = osGetCount();
    copy_of_osgetcount_value_0 = copy_of_osgetcount_value_1;
}


void sub_GAME_7F0C0AA0(s32 arg0)
{
    copy_of_osgetcount_value_0 = (s32) copy_of_osgetcount_value_1;
    copy_of_osgetcount_value_1 = osGetCount();

    D_80048490 = D_80048494;
    D_80048494 = (s32) (D_80048494 + arg0);
    D_80048498 = arg0;
    #ifdef VERSION_JP
    jpD_800484CC = (f32) arg0;
    jpD_800484D0 = (f32) jpD_800484CC;
    #endif
    D_8004849C = (s32) D_800484A0;
    D_800484A0 = (s32) (D_80048494 / 2);
    D_800484A4 = (s32) (D_80048494 & 1);
    D_800484A8 = (s32) (D_800484A0 - D_8004849C);
}


void sub_GAME_7F0C0B4C(void)
{
  u32 uVar1;
  
  do {
    uVar1 = ((osGetCount() - copy_of_osgetcount_value_1) + 0x5eb61) / 0xbd6c3;
  } while (uVar1 < D_800484B4);

  D_800484B4 = 1;
  sub_GAME_7F0C0AA0(uVar1);
}


void sub_GAME_7F0C0BE4(s32 arg0) {
    D_800484B4 = arg0;
}






