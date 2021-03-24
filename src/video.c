#include "ultra64.h"
#include "vi.h"
#include "video.h"
#include "bondgame.h"
#include "bondconstants.h"
#include "unk_093880.h" // pPlayer
#include "sched.h"
#include "rsp.h"
#include "libultra/os.h"
#include "include/PR/os_vi.h"
#include "indy_comms.h"
#include "game/bond.h"
#include "game/viewport.h"
#include "game/dyn.h"

/**
 * @file video.c
 * This file contains video handling code. 
 */

/**
 * Address 80023240.
 */
u32 g_unused80023240 = 0;

struct VideoSettings_s g_videoSettings[NUM_VIDEO_SETTINGS] = 
{
    {0, 0, 0, 0, 320, 240, 60.0f, 1.3333334f, 30.0f, 10000.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 320, 240, 0, 0, 1, NULL},
    {0, 0, 0, 0, 320, 240, 60.0f, 1.3333334f, 30.0f, 10000.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 320, 240, 0, 0, 1, NULL}
};

/**
 * Address 8002329C.
 * vimode hStart horizontal offset in video_related_8.
 */
s32 D_8002329C = 0;

/**
 * Address 800232A0.
 * vimode vStart vertical offset in video_related_8.
 */
s32 D_800232A0 = 0;

VideoSettings *ptr_video_settings1 = &g_videoSettings[0];
VideoSettings *ptr_video_settings2 = &g_videoSettings[0];
s32 g_viColorOutputMode = 1;

/**
 * Address 800232B0.
 * D_800232B4 multiplier sign. This is only ever 1 or -1.
 */
s32 D_800232B0 = 1;

/**
 * Address 800232B4.
 * vimode vStart vertical offset in viVsyncRelated.
 */
s32 D_800232B4 = 0;

/**
 * Address 800232B8.
 * Some kind of counter for how frequently D_800232B4 is zero'd in viVsyncRelated.
 */
u32 D_800232B8 = 0;

/**
 * Address 800232BC.
 * Some kind of counter for how frequently osViBlack is called with "active" parameter.
 * Note: might be signed.
 */
u32 D_800232BC = 3;

/**
 * Address 800232C0.
 * should correlate to g_schedViCurrentFrameBuffer
 */
s32 D_800232C0 = 0;

s32 g_indyJpg16BitGrabnum = 1;
s32 g_indyJpg32BitGrabnum = 1;
s32 g_indyRgb16BitGrabnum = 1;
s32 g_indyRgb32BitGrabnum = 1;
f32 g_viProjectionMatrixF[4][4];
Mtx *g_viProjectionMatrix;
u16 g_viPerspNorm;

/**
 * Address 80060828.
 * Original vi mode.
 * (name following n64devkit\ultra\usr\src\pr\demos\threadmonkey\block.c)
 */
OSViMode g_viOriginalVideoMode;

/**
 * Address 80060878.
 * cfb_16 index for ptr_video_settings1.
 */
u8 off_CODE_bss_80060878;

/**
 * Address 80060879.
 * cfb_16 index for ptr_video_settings2.
 */
u8 off_CODE_bss_80060879;

/**
 * Current vi mode pointer.
 */
OSViMode *viMode;

/**
 * Address 80060880.
 * Original viMode->comRegs.hStart.
 */
u32 dword_CODE_bss_80060880;

/**
 * Address 80060884.
 * Original viMode->fldRegs[0].vStart.
 */
u32 dword_CODE_bss_80060884;

/**
 * Address 80060888.
 * Original viMode->fldRegs[1].vStart.
 */
u32 dword_CODE_bss_80060888;

s32 g_unused8006088C;

/**
 * Address 80028480.
 * Const runtime supported screen widths.
 */
const s16 g_viRuntimeScreenWidths[] = {SCREEN_WIDTH_MIN, SCREEN_WIDTH, SCREEN_WIDTH_MAX};

/**
 * Address 80028488.
 * Const runtime supported screen heights.
 */
const s16 g_viRuntimeScreenHeights[] = {SCREEN_HEIGHT_MIN, SCREEN_HEIGHT, SCREEN_HEIGHT_MAX};

/**
 * 3C60	70003060
 */
void viInitVideoSettings(void)
{
    off_CODE_bss_80060878 = 0;
    off_CODE_bss_80060879 = 1;

    ptr_video_settings1 = (VideoSettings*)((u8*)&g_videoSettings + (off_CODE_bss_80060878 * sizeof(VideoSettings)));
    ptr_video_settings1->framebuf = cfb_16[off_CODE_bss_80060878]; 

    ptr_video_settings2 = (VideoSettings*)((u8*)&g_videoSettings + (off_CODE_bss_80060879 * sizeof(VideoSettings)));
    ptr_video_settings2->framebuf = cfb_16[off_CODE_bss_80060879];
    
    D_8002329C = 0;
    D_800232A0 = 0;
}

void viInitBuffers(void)
{
    s32 i;
    u8* p1 = cfb_16[0];
    u8* p2 = cfb_16[1];

    zbufDeallocate();

    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 2; i++)
    {
        p1[i] = 0;
        p2[i] = 0;
    }
}

void viSet800232BC(u32 arg0)
{
    arg0 += 2;
    D_800232BC = arg0;
}

/**
 * 3DA0	700031A0
 * Calls osViSetMode with current viMode.
 * Also calls osViBlack.
 * Applies verticalOffset to vstart.
 * 
 * Looks related to n64devkit\ultra\usr\src\pr\demos\blockmonkey\block.c
 * in particular, ModifyVStart
 */
void viVsyncRelated(void)
{
    s32 verticalOffset;
    s32 registerValue;

    if (D_800232B8 > 0)
    {
        D_800232B8--;
        
        if (D_800232B8 == 0)
        {
            D_800232B4 = 0;
        }
    }

    verticalOffset = D_800232B0 * D_800232B4;

// same codegen as (x & 0xffff)
#define TO_U16_A(x) ((u16)(x))
// same codegen as ((u16)(x))
#define TO_U16_B(x) (x & 0xffff)

#define TO_U16_C(x) ((u16)(x & 0xffff))

/**
 * Splits a 32 bit value into upper and lower 16, adds a 16 bit value to each, and combines back to 32 bits.
 * 
 * Note: both unsigned 16 bit casts result in the same codegen, but I'm using different
 * macros to give a more "natural" explanation of the asm codegen.
 * 
 * TODO: Move this to top of file/cleanup after determining how this is used in video_related_8.
 */
#define ADD_LOW_AND_HI_16_TRUNCATE(x32, add16) ((TO_U16_B(TO_U16_A((x32) >> 16) + (add16)) << 16) | TO_U16_B(TO_U16_A(x32) + (add16)))

    // note the implicit cast from unsigned to signed.
    registerValue = dword_CODE_bss_80060884;
    (*viMode).fldRegs[0].vStart = ADD_LOW_AND_HI_16_TRUNCATE(registerValue, verticalOffset);

    registerValue = dword_CODE_bss_80060888;
    (*viMode).fldRegs[1].vStart = ADD_LOW_AND_HI_16_TRUNCATE(registerValue, verticalOffset);

    osViSetMode(viMode);
    osViBlack(D_800232BC);

    // D_800232BC might be declared signed which means the if statement is
    //
    //    if (D_800232BC != 0 && D_800232BC < 3)
    //
    // but this way feels "safer", though the cast to (s32) now seems unnatural.
    // The "right" answer depends on what's supposed to happen for values like -1 or 0xffffffff ...
    if (D_800232BC > 0 && (s32)D_800232BC < 3)
    {
        D_800232BC--;
    }

    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF);

    D_800232B0 = -D_800232B0;
}

/**
 * 3E98 70003298
 * Some code (and defines) based on n64devkit\ultra\usr\src\pr\demos\blockmonkey\block.c
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * // First half matching very well, second half less so.
 */
void video_related_8(void)
{
    f32 calculatedYScale;
    f32 calculatedXScale;
    //OSViMode *viModeTmp;
    VideoSettings *settings;
    s32 registerValue;

    //s32 *pD_800232C0 = &D_800232C0;
    //s32 localD_800232C0;

    if (ptr_video_settings2->mode != ptr_video_settings1->mode)
    {
        switch (ptr_video_settings2->mode)
        {
            case VIDEOMODE_DISABLE_320x240:
            {
                osViSetYScale(1.0f);
                osViBlack(TRUE);

                break;
            }

            case VIDEOMODE_320x240:
            {
                if (g_viColorOutputMode != COLORMODE_32BIT)
                {
                    if (osTvType == TV_TYPE_MPAL)
                    {
                        g_viOriginalVideoMode = osViModeTable[OS_VI_MPAL_LAN1];
                    }
                    else
                    {
                        g_viOriginalVideoMode = osViModeTable[OS_VI_NTSC_LAN1];
                    }
                }
                else
                {
                    if (osTvType == TV_TYPE_MPAL)
                    {
                        g_viOriginalVideoMode = osViModeTable[OS_VI_MPAL_LAN2];
                    }
                    else
                    {
                        g_viOriginalVideoMode = osViModeTable[OS_VI_NTSC_LAN2];
                    }
                }

                viMode = &g_viOriginalVideoMode;

                dword_CODE_bss_80060880 = viMode->comRegs.hStart;
                dword_CODE_bss_80060884 = viMode->fldRegs[0].vStart;
                dword_CODE_bss_80060888 = viMode->fldRegs[1].vStart;

                viSet800232BC(0);

                break;
            }

            case VIDEOMODE_640x480:
            {
                if (osTvType == TV_TYPE_MPAL)
                {
                    viMode = &osViModeTable[OS_VI_MPAL_HAF1];
                }
                else
                {
                    viMode = &osViModeTable[OS_VI_NTSC_HAF1];
                }
                
                dword_CODE_bss_80060880 = viMode->comRegs.hStart;
                dword_CODE_bss_80060884 = viMode->fldRegs[0].vStart;
                dword_CODE_bss_80060888 = viMode->fldRegs[1].vStart;

                osViBlack(FALSE);

                break;
            }
        };

        osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF);
    }
    
    calculatedXScale = (f32)ptr_video_settings2->x / (f32)ptr_video_settings2->bufx;
    calculatedYScale = (f32)ptr_video_settings2->y / (f32)ptr_video_settings2->bufy;

    // osViBlack requires YScale to be 1.0, otherwise, 
    //     "Using it for YScale factors that are not 1.0 creates the potential
    //     for the video interface to malfunction and enter a state that cannot
    //     be exited without resetting the system."
    if (ptr_video_settings2->mode == VIDEOMODE_DISABLE_320x240)
    {
        calculatedYScale = 1.0f;
    }

    //pD_800232C0 = &D_800232C0;
    //localD_800232C0 = D_800232C0;

#define GET_D_800232C0 D_800232C0

    g_ViXScales[GET_D_800232C0] = calculatedXScale;
    g_ViYScales[GET_D_800232C0] = calculatedYScale;
    
    if (ptr_video_settings2->mode == VIDEOMODE_320x240)
    {
        g_ViModePtrs[GET_D_800232C0] = &g_viOriginalVideoMode;

        if (g_viColorOutputMode != COLORMODE_32BIT)
        {
            if (osTvType == TV_TYPE_MPAL)
            {
                g_ViModes[GET_D_800232C0] = osViModeTable[OS_VI_MPAL_LAN1];
            }
            else
            {
                g_ViModes[GET_D_800232C0] = osViModeTable[OS_VI_NTSC_LAN1];
            }
        }
        else
        {
            if (osTvType == TV_TYPE_MPAL)
            {
                g_ViModes[GET_D_800232C0] = osViModeTable[OS_VI_MPAL_LAN2];
            }
            else
            {
                g_ViModes[GET_D_800232C0] = osViModeTable[OS_VI_NTSC_LAN2];
            }
        }

        //viModeTmp = &g_ViModes[GET_D_800232C0];

        g_ViModes[GET_D_800232C0].comRegs.width = ptr_video_settings2->bufx;
        g_ViModes[GET_D_800232C0].comRegs.xScale = ((ptr_video_settings2->bufx * XSCALE_MAX) / SCREEN_WIDTH_MAX);
        g_ViModes[GET_D_800232C0].fldRegs[0].yScale = ((ptr_video_settings2->bufy * YSCALE_MAX) / SCREEN_HEIGHT_MAX);
        g_ViModes[GET_D_800232C0].fldRegs[1].yScale = ((ptr_video_settings2->bufy * YSCALE_MAX) / SCREEN_HEIGHT_MAX);
        g_ViModes[GET_D_800232C0].fldRegs[0].origin = (ptr_video_settings2->bufx * 2);
        g_ViModes[GET_D_800232C0].fldRegs[1].origin = (ptr_video_settings2->bufx * 2);

#define TO_U16_M(x) ((x) % 0xffff)

#define ADD_LOW_AND_HI_16_MOD(x32, add16) ((TO_U16_M(TO_U16_A((x32) >> 16) + (add16)) << 16) | TO_U16_M(TO_U16_A(x32) + (add16)))

        registerValue = g_ViModes[GET_D_800232C0].comRegs.hStart;
        //registerValue = (((((registerValue >> 16) & 0xffff) + D_8002329C) % 0xffff) << 16) | (((((registerValue >> 0) & 0xffff) + D_8002329C) % 0xffff) << 0);
        registerValue = ADD_LOW_AND_HI_16_MOD(registerValue, D_8002329C);
        g_ViModes[GET_D_800232C0].comRegs.hStart = registerValue;
        dword_CODE_bss_80060880 = registerValue;

        registerValue = g_ViModes[GET_D_800232C0].fldRegs[0].vStart;
        //registerValue = (((((registerValue >> 16) & 0xffff) + D_800232A0) % 0xffff) << 16) | (((((registerValue >> 0) & 0xffff) + D_800232A0) % 0xffff) << 0);
        registerValue = ADD_LOW_AND_HI_16_MOD(registerValue, D_800232A0);
        g_ViModes[GET_D_800232C0].fldRegs[0].vStart = registerValue;
        dword_CODE_bss_80060884 = registerValue;

        registerValue = g_ViModes[GET_D_800232C0].fldRegs[1].vStart;
        //registerValue = (((((registerValue >> 16) & 0xffff) + D_800232A0) % 0xffff) << 16) | (((((registerValue >> 0) & 0xffff) + D_800232A0) % 0xffff) <<  0);
        registerValue = ADD_LOW_AND_HI_16_MOD(registerValue, D_800232A0);
        g_ViModes[GET_D_800232C0].fldRegs[1].vStart = registerValue;
        dword_CODE_bss_80060888 = registerValue;

        g_ViChangeVideoModes[GET_D_800232C0] = 1;
    }
    else
    {
        g_ViChangeVideoModes[GET_D_800232C0] = 0;
    }

    D_800232C0 = (D_800232C0 + 1) % NUM_VIDEO_FRAME_BUFFERS;

    if (g_viColorOutputMode != COLORMODE_32BIT)
    {
        (*g_gfxTaskSettingsList)->framebuffer = ptr_video_settings2->framebuf;
    }
    else
    {
        (*g_gfxTaskSettingsList)->framebuffer = cfb_16[0];
    }

    off_CODE_bss_80060878 = (off_CODE_bss_80060878 + 1) % NUM_VIDEO_SETTINGS;
    off_CODE_bss_80060879 = (off_CODE_bss_80060879 + 1) % NUM_VIDEO_SETTINGS;
    
    settings = ptr_video_settings2;

    ptr_video_settings1 = &g_videoSettings + (off_CODE_bss_80060878 * sizeof(VideoSettings));
    ptr_video_settings2 = &g_videoSettings + (off_CODE_bss_80060879 * sizeof(VideoSettings));
    // ptr_video_settings1 = (VideoSettings*)((u8*)&g_videoSettings + (off_CODE_bss_80060878 * sizeof(VideoSettings)));
    // ptr_video_settings2 = (VideoSettings*)((u8*)&g_videoSettings + (off_CODE_bss_80060879 * sizeof(VideoSettings)));

    bcopy(settings, ptr_video_settings2, sizeof(VideoSettings));
    ptr_video_settings2->framebuf = cfb_16[off_CODE_bss_80060879];
}

void viSet800232B4(f32 param_1)
{
    if (param_1 > 14.0f)
    {
        param_1 = 14.0f;
    }

    if (param_1 < 0.0f)
    {
        param_1 = 0.0f;
    }

    D_800232B4 = (s32)param_1;
    D_800232B8 = 10;
}

void viRecvMesg(int count)
{
    do
    {
        osRecvMesg(&vi_c_debug_MQ, NULL, 1);
        count--;
    }
    while (count > 0);
}

void viSetVideoMode(s32 videomode)
{
    ptr_video_settings2->mode = videomode;
    ptr_video_settings2->x = ptr_video_settings2->bufx = g_viRuntimeScreenWidths[videomode];
    ptr_video_settings2->y = ptr_video_settings2->bufy = g_viRuntimeScreenHeights[videomode];
}

void viSetColorMode16Bit(void)
{
    g_viColorOutputMode = COLORMODE_16BIT;
}

void viSetColorMode32Bit(void)
{
    g_viColorOutputMode = COLORMODE_32BIT;
}

u8 *viGetFrameBuf2(void)
{
    return ptr_video_settings2->framebuf;
}

u8 *viGetFrameBuf1(void)
{
    return ptr_video_settings1->framebuf;
}

void viSetFrameBuf2(u8 *buf)
{
    ptr_video_settings2->framebuf = buf;
}

u16 viGetPerspNorm(void)
{
    return g_viPerspNorm;
}

Gfx *video_related_F(Gfx *gdl)
{
    if (pPlayer != NULL)
    {
        pPlayer->viewports[off_CODE_bss_80060879].vp.vscale[0] = (ptr_video_settings2->viewx * 2);
        pPlayer->viewports[off_CODE_bss_80060879].vp.vtrans[0] = (ptr_video_settings2->viewx * 2) + (ptr_video_settings2->viewleft * 4);
        pPlayer->viewports[off_CODE_bss_80060879].vp.vscale[1] = (ptr_video_settings2->viewy * 2);
        pPlayer->viewports[off_CODE_bss_80060879].vp.vtrans[1] = (ptr_video_settings2->viewy * 2) + (ptr_video_settings2->viewtop * 4);
    }

    gSPViewport(gdl++, OS_K0_TO_PHYSICAL(&pPlayer->viewports[off_CODE_bss_80060879]));
    g_viProjectionMatrix = dynAllocateMatrix();    
    guPerspectiveF(g_viProjectionMatrixF, &g_viPerspNorm, ptr_video_settings2->fovy, ptr_video_settings2->aspect, ptr_video_settings2->znear, ptr_video_settings2->zfar, 1.0f);
    guMtxF2L(g_viProjectionMatrixF, g_viProjectionMatrix);
    gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(g_viProjectionMatrix), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPPerspNormalize(gdl++, g_viPerspNorm);
    currentPlayerSetProjectionMatrix(g_viProjectionMatrix);
    currentPlayerSetProjectionMatrixF(g_viProjectionMatrixF);

    if (g_viColorOutputMode != COLORMODE_32BIT)
    {
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, ptr_video_settings2->bufx, OS_K0_TO_PHYSICAL(ptr_video_settings2->framebuf));
    }
    else
    {
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, ptr_video_settings2->bufx, OS_K0_TO_PHYSICAL(cfb_16[0]));
    }

    return gdl;
}

Gfx *viClearZBufCurrentPlayer(Gfx *gdl)
{
    if (ptr_video_settings2->usezbuf != 0)
    {
        gdl = zbufClearCurrentPlayer(zbufInit(gdl));
    }

    return gdl;
}

Gfx *viFillScreen(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPFillRectangle(gdl++, 0, 0, (ptr_video_settings2->bufx - 1), (ptr_video_settings2->bufy - 1));
	gDPPipeSync(gdl++);

    return gdl;
}

Gfx *viSetupScreensForNumPlayers(Gfx *gdl)
{
    gDPSetCycleType(gdl++, G_CYC_FILL);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetX(), viGetY());
    gDPSetFillColor(gdl++, ((GPACK_RGBA5551(0,0,0,1) << 16) | GPACK_RGBA5551(0,0,0,1)));

    if (viGetViewTop() > 0)
    {
        if (sub_GAME_7F09B4D8(get_cur_playernum()) == 0)
        {
            gDPFillRectangle(gdl++, 0, 0, (viGetX() - 1), (viGetViewTop() - 1));
            gDPPipeSync(gdl++);
        }
    }

    if (getPlayerCount() == 1)
    {
        if ((viGetViewTop() + viGetViewHeight()) < viGetY())
        {
            gDPFillRectangle(gdl++, 0, (viGetViewTop() + viGetViewHeight()), (viGetX() - 1), (viGetY() - 1));
            gDPPipeSync(gdl++);
        }
    }
    else
    {
        if (sub_GAME_7F09B4D8(get_cur_playernum()) == 0)
        {
            if ((viGetViewTop() + viGetViewHeight() + viGetViewHeight()) < viGetY())
            {
                gDPFillRectangle(gdl++, 0, (viGetViewTop() + viGetViewHeight() + viGetViewHeight()), (viGetX() - 1), (viGetY() - 1));
                gDPPipeSync(gdl++);
            }

            gDPFillRectangle(gdl++, 0, ((SCREEN_HEIGHT / 2) - 1), (viGetX() - 1), (SCREEN_HEIGHT / 2));
            gDPPipeSync(gdl++);

            if (getPlayerCount() >= 3)
            {
                gDPFillRectangle(gdl++, ((SCREEN_WIDTH / 2) - 1), 0, (SCREEN_WIDTH / 2), (viGetY() - 1));
                gDPPipeSync(gdl++);
            }

            if (getPlayerCount() == 3)
            {
                gDPFillRectangle(gdl++, ((SCREEN_WIDTH / 2) + 1), ((SCREEN_HEIGHT / 2) + 1), (viGetX() - 1), (viGetY() - 1));
                gDPPipeSync(gdl++);
            }
        }
    }

    return gdl;
}

void viSet800232A0(s32 arg0)
{
    D_800232A0 = arg0;
}

s32 viGet800232A0(void)
{
    return D_800232A0;
}

void viSet8002329C(s32 arg0)
{
    D_8002329C = arg0;
}

s32 viGet8002329C(void)
{
    return D_8002329C;
}

void viSetBuf(s16 x, s16 y)
{
    ptr_video_settings2->bufx = x;
    ptr_video_settings2->bufy = y;
}

s16 viGetBufX(void)
{
    return ptr_video_settings2->bufx;
}

s16 viGetBufY(void)
{
    return ptr_video_settings2->bufy;
}

void viSetXY(s16 x, s16 y)
{
    ptr_video_settings2->x = x;
    ptr_video_settings2->y = y;
}

s16 viGetX(void)
{
    return ptr_video_settings2->x;
}

s16 viGetY(void)
{
    return ptr_video_settings2->y;
}

void viSetViewSize(s16 x, s16 y)
{
    ptr_video_settings2->viewx = x;
    ptr_video_settings2->viewy = y;
    currentPlayerSetScreenSize(ptr_video_settings2->viewx, ptr_video_settings2->viewy);
    currentPlayerSetCameraScale();
}

s16 viGetViewWidth(void)
{
    return ptr_video_settings2->viewx;
}

s16 viGetViewHeight(void)
{
    return ptr_video_settings2->viewy;
}

void viSetViewPosition(s16 left, s16 top)
{
    ptr_video_settings2->viewleft = left;
    ptr_video_settings2->viewtop = top;
    currentPlayerSetScreenPosition(ptr_video_settings2->viewleft, ptr_video_settings2->viewtop);
}

s16 viGetViewLeft(void)
{
    return ptr_video_settings2->viewleft;
}

s16 viGetViewTop(void)
{
    return ptr_video_settings2->viewtop;
}

void viSetUseZBuf(s32 usezbuf)
{
  ptr_video_settings2->usezbuf = usezbuf;
}

void viSetFovY(f32 fovy)
{
    ptr_video_settings2->fovy = fovy;
    currentPlayerSetPerspective(ptr_video_settings2->znear, ptr_video_settings2->fovy, ptr_video_settings2->aspect);
    currentPlayerSetCameraScale();
}

void viSetAspect(f32 aspect)
{
    ptr_video_settings2->aspect = aspect;
    currentPlayerSetPerspective(ptr_video_settings2->znear, ptr_video_settings2->fovy, ptr_video_settings2->aspect);
    currentPlayerSetCameraScale();
}

f32 viGetFovY(void)
{
    return ptr_video_settings2->fovy;
}

void viSetFov(f32 fovx, f32 fovy)
{
    ptr_video_settings2->fovy = fovy;
    ptr_video_settings2->aspect = (f32) (fovx / fovy);
    currentPlayerSetPerspective(ptr_video_settings2->znear, ptr_video_settings2->fovy, ptr_video_settings2->aspect);
    currentPlayerSetCameraScale();
}

void viSetZRange(f32 near, f32 far)
{
    ptr_video_settings2->znear = near;
    ptr_video_settings2->zfar = far;
    currentPlayerSetPerspective(ptr_video_settings2->znear, ptr_video_settings2->fovy, ptr_video_settings2->aspect);
    currentPlayerSetCameraScale();
}

void viGetZRange(f32 *zrange)
{
    zrange[0] = ptr_video_settings2->znear;
    zrange[1] = ptr_video_settings2->zfar;
}

Gfx *viSetFillColor(Gfx *gdl, s32 r, s32 g, s32 b)
{
    if (g_viColorOutputMode != COLORMODE_32BIT)
    {
        gDPSetFillColor(gdl++, ((GPACK_RGBA5551(r, g, b, 1) << 16) | GPACK_RGBA5551(r, g, b, 1)));
    }
    else
    {
        gDPSetFillColor(gdl++, ((r << 24) | (g << 16) | (b << 8) | 0xFF));
    }
    
    return gdl;
}

/**
 * 5358	70004758
 *     image capture routine, jpeg 16bit colour
 */
void indyGrabJpg16bit(void)
{
    s32 *pgrabnum = &g_indyJpg16BitGrabnum;
    char buffer[250];
    s32 filesize;

    while (1)
    {
        sprintf(buffer, "grab.%d.jpeg", *pgrabnum);
        if (check_file_found_on_indy((u8*)&buffer, &filesize) == 0)
        {
            break;
        }

        *pgrabnum = *pgrabnum + 1;
    }
    
    sprintf(buffer, "grab.%d.temp.uix", *pgrabnum);
    indy_send_capture_data((u8*)&buffer, (u8*)ptr_video_settings2->framebuf, (viGetX() * viGetY() * 2));

    sprintf(buffer, "uix2pix grab.%d.temp.uix", *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.temp.rgb", *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg", *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "rm grab.%d.temp.uix grab.%d.temp.pix grab.%d.temp.rgb", *pgrabnum, *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "imgview grab.%d.jpeg", *pgrabnum);
    send_command_string((u8*)&buffer);
}

/**
 * 54D4	700048D4
 *     image capture routine, jpeg 32bit colour
 */
void indyGrabJpg32bit(void)
{
    s32 *pgrabnum = &g_indyJpg32BitGrabnum;
    char buffer[250];
    s32 filesize;

    while (1)
    {
        sprintf(buffer, "grab.%d.jpeg", *pgrabnum);
        if (check_file_found_on_indy((u8*)&buffer, &filesize) == 0)
        {
            break;
        }

        *pgrabnum = *pgrabnum + 1;
    }
    
    sprintf(buffer, "grab.%d.temp.Uix", *pgrabnum);
    indy_send_capture_data((u8*)&buffer, (u8*)&cfb_16, (viGetX() * viGetY() * 4));

    sprintf(buffer, "Uix2pix -xs%d grab.%d.temp.Uix", viGetX(), *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.temp.rgb", *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg", *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "rm grab.%d.temp.Uix grab.%d.temp.pix grab.%d.temp.rgb", *pgrabnum, *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "imgview grab.%d.jpeg", *pgrabnum);
    send_command_string((u8*)&buffer);
}

/**
 * 5660	70004A60
 *     image capture routine, rgb 16bit colour
 */
void indyGrabRgb16bit(void)
{
    s32 *pgrabnum = &g_indyRgb16BitGrabnum;
    char buffer[250];
    s32 filesize;

    while (1)
    {
        sprintf(buffer, "grab.%d.rgb", *pgrabnum);
        if (check_file_found_on_indy((u8*)&buffer, &filesize) == 0)
        {
            break;
        }

        *pgrabnum = *pgrabnum + 1;
    }
    
    sprintf(buffer, "grab.%d.temp.uix", *pgrabnum);
    indy_send_capture_data((u8*)&buffer, (u8*)ptr_video_settings2->framebuf, (viGetX() * viGetY() * 2));

    sprintf(buffer, "uix2pix grab.%d.temp.uix", *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.rgb", *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "rm grab.%d.temp.uix grab.%d.temp.pix", *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "imgview grab.%d.rgb", *pgrabnum);
    send_command_string((u8*)&buffer);
}

/**
 * 57B4	70004BB4
 *     image capture routine, rgb 32bit colour
 */
void indyGrabRgb32bit(void)
{
    s32 *pgrabnum = &g_indyRgb32BitGrabnum;
    char buffer[250];
    s32 filesize;

    while (1)
    {
        sprintf(buffer, "grab.%d.rgb", *pgrabnum);
        if (check_file_found_on_indy((u8*)&buffer, &filesize) == 0)
        {
            break;
        }

        *pgrabnum = *pgrabnum + 1;
    }
    
    sprintf(buffer, "grab.%d.temp.Uix", *pgrabnum);
    indy_send_capture_data((u8*)&buffer, (u8*)&cfb_16, (viGetX() * viGetY() * 4));

    sprintf(buffer, "Uix2pix -xs%d grab.%d.temp.Uix", viGetX(), *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.rgb", *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "rm grab.%d.temp.Uix grab.%d.temp.pix", *pgrabnum, *pgrabnum);
    send_command_string((u8*)&buffer);

    sprintf(buffer, "imgview grab.%d.rgb", *pgrabnum);
    send_command_string((u8*)&buffer);
}