#include <ultra64.h>
#include "unk_0A1DA0.h"



void sub_GAME_7F007920(void) {
    s32 i;
    for (i = 0; i < SHATTERED_WINDOW_PIECES_BUFFER_LEN; i++)
    {
        ptr_shattered_window_pieces[i].field_0x0 = 0;
    }
}

