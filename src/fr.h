#ifndef _VIDEO_H_
#define _VIDEO_H_
#include "ultra64.h"

#define NUM_VIDEO_FRAME_BUFFERS    2
#define NUM_VIDEO_SETTINGS         NUM_VIDEO_FRAME_BUFFERS

#define WIDESCREEN_ASPECT ((f32)(16.0f/9.0f))


#define	SCREEN_HEIGHT_MIN   240
#define	SCREEN_HEIGHT_240   240
#define	SCREEN_HEIGHT_272   272
#define	SCREEN_HEIGHT_330   330
#define	SCREEN_HEIGHT_MAX   480
#define	SCREEN_HEIGHT_MAX_EU   572

#define SCREEN_WIDTH_MIN    320
#define SCREEN_WIDTH_320    320
#define SCREEN_WIDTH_440    440
#define SCREEN_WIDTH_MAX    640

#define VIEWPORT_WIDTH_FULLSCREEN SCREEN_WIDTH_320
#define VIEWPORT_WIDTH_WIDESCREEN SCREEN_WIDTH_320
#define VIEWPORT_WIDTH_CINEMA     SCREEN_WIDTH_320

/* 304 = 320 - 16 ?? */
#define VIEWPORT_HEIGHT_FULLSCREEN 304
#define VIEWPORT_HEIGHT_WIDESCREEN 248
#define VIEWPORT_HEIGHT_CINEMA     190
#define VIEWPORT_HEIGHT_DEFAULT    220

#define VIEWPORT_OFFSET_HEIGHT_WIDESCREEN 180
#define VIEWPORT_OFFSET_HEIGHT_CINEMA     136

/* 159 = (640 / 4) - 1 */
#define VIEWPORT_WIDTH_4P 159
/* 109 = (440 / 4) - 1 */
#define VIEWPORT_HEIGHT_4P 109

#define VIEWPORT_ULY_2P_PLAYER_1       10
#define VIEWPORT_ULY_2P_PLAYER_2       121
#define VIEWPORT_ULY_4P_PLAYER_12      VIEWPORT_ULY_2P_PLAYER_1
#define VIEWPORT_ULY_4P_PLAYER_34      VIEWPORT_ULY_2P_PLAYER_2
#define VIEWPORT_ULY_CAM_FULLSCREEN    13
#define VIEWPORT_ULY_CAM_WIDESCREEN    41
#define VIEWPORT_ULY_CAM_CINEMA        70
#define VIEWPORT_ULY_WIDESCREEN_OFFSET 30
#define VIEWPORT_ULY_CINEMA_OFFSET     52
#define VIEWPORT_ULY_DEFAULT           VIEWPORT_ULY_2P_PLAYER_1

#if defined(VERSION_EU)
/* PAL */
#define	SCREEN_HEIGHT     SCREEN_HEIGHT_272
#else
/* NTSC */
#define	SCREEN_HEIGHT     SCREEN_HEIGHT_240
#endif

#define SCREEN_WIDTH      SCREEN_WIDTH_320

#define XSCALE_MAX      0x400
#define YSCALE_MAX      0x800

typedef struct VideoSettings_s {
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
} VideoSettings;

extern OSViMode *viMode;
extern u32 g_viOriginalHstart;
extern u32 g_viOriginalVstart0;
extern u32 g_viOriginalVstart1;
extern Mtx *g_viProjectionMatrix;

/* SCREEN_HEIGHT #define changes based on version (PAL or NTSC) */
extern u8 cfb_16[NUM_VIDEO_FRAME_BUFFERS][SCREEN_WIDTH * SCREEN_HEIGHT * 2];

void viSet800232B4(f32 param_1);

void viInitVideoSettings(void);
s16 viGetX(void);
s16 viGetY(void);
s16 viGetViewLeft(void);
s16 viGetViewTop(void);
s16 viGetViewWidth(void);
s16 viGetViewHeight(void);
u8 *viGetFrameBuf2(void);
void viSetFrameBuf2(u8 *buf);
void viSetFovY(f32 fovy);
f32 viGetFovY(void);
void viSetAspect(f32 aspect);
void viSetZRange(f32 near, f32 far);
void viSetUseZBuf(s32 usezbuf);
void viSetViewSize(s16 x, s16 y);
void viSetViewPosition(s16 left, s16 top);
void viInitBuffers(void);
void viVsyncRelated(void);
void viSetHorizontalOffset(s32 arg0);
s32 viGetHorizontalOffset(void);
void video_related_8(void);
void viSetBuf(s16 x, s16 y);
void viSetXY(s16 x, s16 y);

Gfx *viSetupScreensForNumPlayers(Gfx *gdl);

void indyGrabJpg16bit(void);
void indyGrabJpg32bit(void);
void indyGrabRgb16bit(void);
void indyGrabRgb32bit(void);

void viSetVideoMode(s32 m);
s32 viGet800232A0(void);
void viSet800232A0(s32 arg0);

Gfx *viClearZBufCurrentPlayer(Gfx *gdl);
Gfx *video_related_F(Gfx *gdl);
void viGetZRange(f32 *zrange);
#endif


