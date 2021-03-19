#ifndef _VIDEO_H_
#define _VIDEO_H_
#include "ultra64.h"

#define NUM_VIDEO_FRAME_BUFFERS    2
#define NUM_VIDEO_SETTINGS         NUM_VIDEO_FRAME_BUFFERS


#define	SCREEN_HEIGHT_MIN   240
#define	SCREEN_HEIGHT_240   240
#define	SCREEN_HEIGHT_330   330
#define	SCREEN_HEIGHT_MAX   480

#define SCREEN_WIDTH_MIN    320
#define SCREEN_WIDTH_320    320
#define SCREEN_WIDTH_440    440
#define SCREEN_WIDTH_MAX    640

#define	SCREEN_HEIGHT     SCREEN_HEIGHT_240
#define SCREEN_WIDTH      SCREEN_WIDTH_320

#define XSCALE_MAX      0x400
#define YSCALE_MAX      0x800

typedef struct video_settings video_settings, *Pvideo_settings;

struct video_settings {
    /**
     * enum VIDEOMODE.
     */
    u8 mode;
    s8 field_01;
    s8 field_02;
    s8 field_03;
    s16 x;
    s16 y;
    f32 fovy;
    f32 aspect;
    f32 znear;
    f32 zfar;

    /**
     * Screen width.
     */
    s16 bufx;

    /**
     * Screen height.
     */
    s16 bufy;
    s16 viewx;
    s16 viewy;
    s16 viewleft;
    s16 viewtop;
    s32 usezbuf;
    u8* framebuf;
};

extern OSViMode *viMode;
extern u32 dword_CODE_bss_80060880;
extern u32 dword_CODE_bss_80060884;
extern u32 dword_CODE_bss_80060888;

extern u8 cfb_16[NUM_VIDEO_FRAME_BUFFERS][SCREEN_WIDTH * SCREEN_HEIGHT * 2];

void viSet800232B4(f32 param_1);

s16 viGetX(void);
s16 viGetY(void);
s16 viGetViewLeft(void);
s16 viGetViewTop(void);
s16 viGetViewWidth(void);
s16 viGetViewHeight(void);
u8 *viGetFrameBuf2(void);
void viSetFovY(f32 fovy);
void viSetAspect(f32 aspect);
void viSetZRange(f32 near, f32 far);
void viSetUseZBuf(s32 usezbuf);
void viSetViewSize(s16 x, s16 y);
void viSetViewPosition(s16 left, s16 top);
void viInitBuffers(void);
void video_related_8(void);

void indy_grab_jpg_16bit(void);
void indy_grab_jpg_32bit(void);
void indy_grab_rgb_16bit(void);
void indy_grab_rgb_32bit(void);
#endif


