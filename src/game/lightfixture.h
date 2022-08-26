#ifndef _LIGHTFIXTURE_H_
#define _LIGHTFIXTURE_H_

#include <ultra64.h>

typedef struct s_lightfixture {
    s16 index;
    s16 RESERVED;
    Gfx *ptr_start_pertinent_DL;
    void *ptr_end_pertinent_DL;
} s_lightfixture;

struct bondstruct_unk_80082B18 {
    u16 unk00;
    u16 unk02;
};

struct bondstruct_unk_room_related {
    s8 unk00;
    s8 unk01;
    s16 unk02;
    s32 unk04;
};

#endif
