#ifndef _VIDEO_H_
#define _VIDEO_H_
#include "ultra64.h"

typedef struct video_settings video_settings, *Pvideo_settings;

struct video_settings {
    int mode;
    short txtClipW;
    short txtClipH;
    f32 far;
    f32 scale;
    f32 aspect;
    f32 anonymous_6;
    short somethingW;
    short somethingH;
    short width;
    short height;
    short ulx;
    short uly;
    int anonymous_12;
    u8* frameb;
};

void setvideo_far(f32 arg0);
void set_page_aspect(f32 arg0);
void set_page_height(f32 arg0, f32 arg1);
void set_video2_settings_offset_24(int param_1);
#endif


