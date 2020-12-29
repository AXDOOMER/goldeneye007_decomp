#ifndef _VIDEO_H_
#define _VIDEO_H_
#include "ultra64.h"

typedef struct video_settings video_settings, *Pvideo_settings;

struct video_settings {
    s8 mode;
    s8 test1;
    s8 test2;
    s8 test3;
    s16 x;
    s16 y;
    f32 fovy;
    f32 aspect;
    f32 znear;
    f32 zfar;
    s16 bufx;
    s16 bufy;
    s16 viewx;
    s16 viewy;
    s16 viewleft;
    s16 viewtop;
    s32 usezbuf;
    u8* framebuf;
};

void set_video2_settings_fovy(f32 fovy);
void set_video2_settings_aspect(f32 aspect);
void set_video2_settings_near_far(f32 near, f32 far);
void set_video2_settings_usezbuf(s32 usezbuf);
#endif


