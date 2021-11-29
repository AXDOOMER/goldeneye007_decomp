#ifndef _UNK_0CC4C0_H_
#define _UNK_0CC4C0_H_
#include "ultra64.h"

struct image_sound
{
    /**
     * Array of sound effect ids.
    */
    u16 *sfx;

    u8 *thing2;

    /**
     * Number of items in sfx array.
    */
    u16 sfx_len;

    /**
     * Number of items in thing2 array.
    */
    u16 thing2_len;
};

#endif
