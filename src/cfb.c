#include "ultra64.h"
#include "bondgame.h"

#include "fr.h"

#if defined(VERSION_US) || defined(VERSION_JP)
/* NTSC */
u8 cfb_16[NUM_VIDEO_FRAME_BUFFERS][SCREEN_WIDTH * SCREEN_HEIGHT * 2];
#endif

#if defined(VERSION_EU)
/* PAL */
u8 cfb_16[NUM_VIDEO_FRAME_BUFFERS][SCREEN_WIDTH * SCREEN_HEIGHT_EU * 2];
#endif