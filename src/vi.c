#include "ultra64.h"
#include "PR/gbi.h"

/**
 * EU .data, offset from start of data_seg : 0x3740
*/

OSMesg vi_c_debug_MSG[0x8];
OSMesgQueue vi_c_debug_MQ;

/* wtf is this, should it be split? is it part of debugmenu.? */
u32 viDebugNoticeList[] = 
{
    0, 0, 0,
    0, 0, 0
};

#ifndef VERSION_EU
//80024518
Gfx viDLEnd[] = {
	gsSPEndDisplayList()
};
#endif


void viDebugRemoved(void) {
    return;
}

void viInitDebugNoticeList(void)
{
    debTryAdd(&viDebugNoticeList, "vi_c_debug");
    osCreateMesgQueue(&vi_c_debug_MQ, &vi_c_debug_MSG, 8);
}




