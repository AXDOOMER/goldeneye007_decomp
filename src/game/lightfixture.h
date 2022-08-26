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
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
};

#endif
