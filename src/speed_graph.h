#ifndef _SPEED_GRAPH_H_
#define _SPEED_GRAPH_H_

#include "ultra64.h"

Gfx *speedGraphDisplay(Gfx *gdl);
void speedGraphVideoRelated_2(void);

#if defined(VERSION_EU)
void speedGraphVideoRelated_3(void);
#else
void speedGraphVideoRelated_3(s32 arg0);
#endif

void video_DL_related_4(void);

#endif
