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

// same codegen as (x & 0xffff)
#define TO_U16_A(x) ((u16)(x))
// same codegen as ((u16)(x))
#define TO_U16_B(x) (x & 0xffff)

#define TO_U16_C(x) ((u16)(x & 0xffff))

#define TO_U16_M(x) ((x) % 0xffff)

/**
 * Splits a 32 bit value into upper and lower 16, adds a 16 bit value to each, and combines back to 32 bits.
 * 
 * Note: both unsigned 16 bit casts result in the same codegen, but I'm using different
 * macros to give a more "natural" explanation of the asm codegen.
 */
#define ADD_LOW_AND_HI_16_TRUNCATE(x32, add16) ((TO_U16_B(TO_U16_A((x32) >> 16) + (add16)) << 16) | TO_U16_B(TO_U16_A(x32) + (add16)))

#define ADD_LOW_AND_HI_16_MOD(x32, add16) ((TO_U16_M(TO_U16_B((x32) >> 16) + (add16)) << 16) | TO_U16_M(TO_U16_A(x32) + (add16)))

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
s32 g_viHorizontalOffset = 0;

/**
 * Address 800232A0.
 * vimode vStart vertical offset in video_related_8.
 * (see D_800232B4 before changing the name)
 */
s32 D_800232A0 = 0;

VideoSettings *ptr_video_settings1 = &g_videoSettings[0];
VideoSettings *ptr_video_settings2 = &g_videoSettings[0];
s32 g_viColorOutputMode = 1;

/**
 * Address 800232B0.
 * D_800232B4 multiplier sign. This is only ever 1 or -1.
 */
s32 g_viVstartSign = 1;

/**
 * Address 800232B4.
 * vimode vStart vertical offset in viVsyncRelated.
 * (see D_800232A0 before changing the name)
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
u8 g_viVideoSettings1FrameBufferIndex;

/**
 * Address 80060879.
 * cfb_16 index for ptr_video_settings2 and pPlayer->viewports.
 */
u8 g_viVideoSettings2FrameBufferIndex;

/**
 * Current vi mode pointer.
 */
OSViMode *viMode;

/**
 * Address 80060880.
 * Original viMode->comRegs.hStart.
 */
u32 g_viOriginalHstart;

/**
 * Address 80060884.
 * Original viMode->fldRegs[0].vStart.
 */
u32 g_viOriginalVstart0;

/**
 * Address 80060888.
 * Original viMode->fldRegs[1].vStart.
 */
u32 g_viOriginalVstart1;

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
    g_viVideoSettings1FrameBufferIndex = 0;
    g_viVideoSettings2FrameBufferIndex = 1;

    ptr_video_settings1 = (VideoSettings*)((u8*)&g_videoSettings + (g_viVideoSettings1FrameBufferIndex * sizeof(VideoSettings)));
    ptr_video_settings1->framebuf = cfb_16[g_viVideoSettings1FrameBufferIndex]; 

    ptr_video_settings2 = (VideoSettings*)((u8*)&g_videoSettings + (g_viVideoSettings2FrameBufferIndex * sizeof(VideoSettings)));
    ptr_video_settings2->framebuf = cfb_16[g_viVideoSettings2FrameBufferIndex];
    
    g_viHorizontalOffset = 0;
    #ifndef VERSION_EU
    D_800232A0 = 0;
    #else
    D_800232A0 = 0xffffffe0;
    #endif
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

    verticalOffset = g_viVstartSign * D_800232B4;

    // note the implicit cast from unsigned to signed.
    registerValue = g_viOriginalVstart0;
    (*viMode).fldRegs[0].vStart = ADD_LOW_AND_HI_16_TRUNCATE(registerValue, verticalOffset);

    registerValue = g_viOriginalVstart1;
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

    g_viVstartSign = -g_viVstartSign;
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
 * There's a problem loading D_800232C0 the first time (+1 instruction), and again when
 * it's being stored (-1 instruction), but the opcodes match other than that.
 * Then just some regalloc.
 */
#ifdef NONMATCHING
void video_related_8(void)
{
    s32 registerValue;
    f32 calculatedYScale;
    f32 calculatedXScale;
    VideoSettings *settings;

    s32 nextMode;

    if (ptr_video_settings1->mode != ptr_video_settings2->mode)
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

                g_viOriginalHstart = viMode->comRegs.hStart;
                g_viOriginalVstart0 = viMode->fldRegs[0].vStart;
                g_viOriginalVstart1 = viMode->fldRegs[1].vStart;

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
                
                g_viOriginalHstart = viMode->comRegs.hStart;
                g_viOriginalVstart0 = viMode->fldRegs[0].vStart;
                g_viOriginalVstart1 = viMode->fldRegs[1].vStart;

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

    // macro for testing theories ...
#define GET_D_800232C0 D_800232C0
    
    // current:
    // lui    t4,      0x0   4ec: R_MIPS_HI16   D_800232C0
    // ...
    // addiu  t4, t4,    0   4f8: R_MIPS_LO16   D_800232C0
    // ...
    // lw     t0,    0(t4)
    //
    // target:
    // lui    t2,      0x0   4f0: R_MIPS_HI16   D_800232C0
    // ...
    // lw     t2,    0(t2)   520: R_MIPS_LO16   D_800232C0

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

        g_ViModes[GET_D_800232C0].comRegs.width = ptr_video_settings2->bufx;
        g_ViModes[GET_D_800232C0].comRegs.xScale = ((ptr_video_settings2->bufx * XSCALE_MAX) / SCREEN_WIDTH_MAX);
        g_ViModes[GET_D_800232C0].fldRegs[0].yScale = ((ptr_video_settings2->bufy * YSCALE_MAX) / SCREEN_HEIGHT_MAX);
        g_ViModes[GET_D_800232C0].fldRegs[1].yScale = ((ptr_video_settings2->bufy * YSCALE_MAX) / SCREEN_HEIGHT_MAX);
        g_ViModes[GET_D_800232C0].fldRegs[0].origin = (ptr_video_settings2->bufx * 2);
        g_ViModes[GET_D_800232C0].fldRegs[1].origin = (ptr_video_settings2->bufx * 2);

        registerValue = g_ViModes[GET_D_800232C0].comRegs.hStart;
        registerValue = ADD_LOW_AND_HI_16_MOD(registerValue, g_viHorizontalOffset);
        g_ViModes[GET_D_800232C0].comRegs.hStart = registerValue;
        g_viOriginalHstart = registerValue;

        registerValue = g_ViModes[GET_D_800232C0].fldRegs[0].vStart;
        registerValue = ADD_LOW_AND_HI_16_MOD(registerValue, D_800232A0);
        g_ViModes[GET_D_800232C0].fldRegs[0].vStart = registerValue;
        g_viOriginalVstart0 = registerValue;

        registerValue = g_ViModes[GET_D_800232C0].fldRegs[1].vStart;
        registerValue = ADD_LOW_AND_HI_16_MOD(registerValue, D_800232A0);
        g_ViModes[GET_D_800232C0].fldRegs[1].vStart = registerValue;
        g_viOriginalVstart1 = registerValue;

        g_ViChangeVideoModes[GET_D_800232C0] = 1;
    }
    else
    {
        g_ViChangeVideoModes[GET_D_800232C0] = 0;
    }

    // current:
    // ...
    // sw     t9,    0(t4)
    //
    // target:
    // lui    at,      0x0   98c: R_MIPS_HI16   D_800232C0
    // ...
    // lw     sw,    0(at)   994: R_MIPS_LO16   D_800232C0

    // This is probably just a happy little accident, but this causes the
    // rest of the function to match.
    // Instead if probably looks like the increment+mod a few lines later:
    // //D_800232C0 = (D_800232C0 + 1) % NUM_VIDEO_FRAME_BUFFERS;
    nextMode = (D_800232C0 + 1) % NUM_VIDEO_FRAME_BUFFERS;
    D_800232C0 = nextMode;

    if (g_viColorOutputMode != COLORMODE_32BIT)
    {
        ((struct GfxInfo_s *)g_gfxTaskSettingsList)->cfb = ptr_video_settings2->framebuf;
    }
    else
    {
        ((struct GfxInfo_s *)g_gfxTaskSettingsList)->cfb = cfb_16[0];
    }
    
    settings = ptr_video_settings2;

    g_viVideoSettings1FrameBufferIndex = (g_viVideoSettings1FrameBufferIndex + 1) % NUM_VIDEO_SETTINGS;
    g_viVideoSettings2FrameBufferIndex = (g_viVideoSettings2FrameBufferIndex + 1) % NUM_VIDEO_SETTINGS;

    // first li 44, needs to be signed. (sizeof(VideoSettings) == 44)
    ptr_video_settings1 = (VideoSettings*)((u8*)&g_videoSettings + (g_viVideoSettings1FrameBufferIndex * (s32)sizeof(VideoSettings)));
    ptr_video_settings2 = (VideoSettings*)((u8*)&g_videoSettings + (g_viVideoSettings2FrameBufferIndex * (s32)sizeof(VideoSettings)));
    
    // second li 44, can be signed or unsigned.
    bcopy(settings, ptr_video_settings2, sizeof(VideoSettings));
    ptr_video_settings2->framebuf = cfb_16[g_viVideoSettings2FrameBufferIndex];
}
#else
GLOBAL_ASM(
.text
glabel video_related_8
/* 003E98 70003298 3C0D8002 */  lui   $t5, %hi(ptr_video_settings2) 
/* 003E9C 7000329C 25AD32A8 */  addiu $t5, %lo(ptr_video_settings2) # addiu $t5, $t5, 0x32a8
/* 003EA0 700032A0 3C0E8002 */  lui   $t6, %hi(ptr_video_settings1) 
/* 003EA4 700032A4 8DCE32A4 */  lw    $t6, %lo(ptr_video_settings1)($t6)
/* 003EA8 700032A8 8DA80000 */  lw    $t0, ($t5)
/* 003EAC 700032AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 003EB0 700032B0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 003EB4 700032B4 91CF0000 */  lbu   $t7, ($t6)
/* 003EB8 700032B8 91020000 */  lbu   $v0, ($t0)
/* 003EBC 700032BC 504F009B */  beql  $v0, $t7, .L7000352C
/* 003EC0 700032C0 850F0004 */   lh    $t7, 4($t0)
/* 003EC4 700032C4 10400009 */  beqz  $v0, .L700032EC
/* 003EC8 700032C8 3C013F80 */   li    $at, 0x3F800000 # 1.000000
/* 003ECC 700032CC 24010001 */  li    $at, 1
/* 003ED0 700032D0 1041000D */  beq   $v0, $at, .L70003308
/* 003ED4 700032D4 3C188002 */   lui   $t8, %hi(g_viColorOutputMode) 
/* 003ED8 700032D8 24010002 */  li    $at, 2
/* 003EDC 700032DC 10410071 */  beq   $v0, $at, .L700034A4
/* 003EE0 700032E0 3C198000 */   lui   $t9, 0x8000
/* 003EE4 700032E4 10000089 */  b     .L7000350C
/* 003EE8 700032E8 00000000 */   nop   
.L700032EC:
/* 003EEC 700032EC 44816000 */  mtc1  $at, $f12
/* 003EF0 700032F0 0C003880 */  jal   osViSetYScale
/* 003EF4 700032F4 00000000 */   nop   
/* 003EF8 700032F8 0C0038B4 */  jal   osViBlack
/* 003EFC 700032FC 24040001 */   li    $a0, 1
/* 003F00 70003300 10000082 */  b     .L7000350C
/* 003F04 70003304 00000000 */   nop   
.L70003308:
/* 003F08 70003308 8F1832AC */  lw    $t8, %lo(g_viColorOutputMode)($t8)
/* 003F0C 7000330C 3C038006 */  lui   $v1, %hi(viMode)
/* 003F10 70003310 3C0F8000 */  lui   $t7, 0x8000
/* 003F14 70003314 1300002B */  beqz  $t8, .L700033C4
/* 003F18 70003318 2463087C */   addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
/* 003F1C 7000331C 3C198000 */  lui   $t9, %hi(osTvType) 
/* 003F20 70003320 8F390300 */  lw    $t9, %lo(osTvType)($t9)
/* 003F24 70003324 24010002 */  li    $at, 2
/* 003F28 70003328 3C188006 */  lui   $t8, %hi(g_viOriginalVideoMode) 
/* 003F2C 7000332C 17210014 */  bne   $t9, $at, .L70003380
/* 003F30 70003330 27180828 */   addiu $t8, %lo(g_viOriginalVideoMode) # addiu $t8, $t8, 0x828
/* 003F34 70003334 3C0F8002 */  lui   $t7, %hi(osViModeTable_osViModeMpalLan1) 
/* 003F38 70003338 25EF7320 */  addiu $t7, %lo(osViModeTable_osViModeMpalLan1) # addiu $t7, $t7, 0x7320
/* 003F3C 7000333C 3C0E8006 */  lui   $t6, %hi(g_viOriginalVideoMode) 
/* 003F40 70003340 25CE0828 */  addiu $t6, %lo(g_viOriginalVideoMode) # addiu $t6, $t6, 0x828
/* 003F44 70003344 25F90048 */  addiu $t9, $t7, 0x48
.L70003348:
/* 003F48 70003348 8DE10000 */  lw    $at, ($t7)
/* 003F4C 7000334C 25EF000C */  addiu $t7, $t7, 0xc
/* 003F50 70003350 25CE000C */  addiu $t6, $t6, 0xc
/* 003F54 70003354 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 003F58 70003358 8DE1FFF8 */  lw    $at, -8($t7)
/* 003F5C 7000335C ADC1FFF8 */  sw    $at, -8($t6)
/* 003F60 70003360 8DE1FFFC */  lw    $at, -4($t7)
/* 003F64 70003364 15F9FFF8 */  bne   $t7, $t9, .L70003348
/* 003F68 70003368 ADC1FFFC */   sw    $at, -4($t6)
/* 003F6C 7000336C 8DE10000 */  lw    $at, ($t7)
/* 003F70 70003370 8DF90004 */  lw    $t9, 4($t7)
/* 003F74 70003374 ADC10000 */  sw    $at, ($t6)
/* 003F78 70003378 1000003A */  b     .L70003464
/* 003F7C 7000337C ADD90004 */   sw    $t9, 4($t6)
.L70003380:
/* 003F80 70003380 3C198002 */  lui   $t9, %hi(osViModeTable_osViModeNtscLan1) 
/* 003F84 70003384 27396A60 */  addiu $t9, %lo(osViModeTable_osViModeNtscLan1) # addiu $t9, $t9, 0x6a60
/* 003F88 70003388 272E0048 */  addiu $t6, $t9, 0x48
.L7000338C:
/* 003F8C 7000338C 8F210000 */  lw    $at, ($t9)
/* 003F90 70003390 2739000C */  addiu $t9, $t9, 0xc
/* 003F94 70003394 2718000C */  addiu $t8, $t8, 0xc
/* 003F98 70003398 AF01FFF4 */  sw    $at, -0xc($t8)
/* 003F9C 7000339C 8F21FFF8 */  lw    $at, -8($t9)
/* 003FA0 700033A0 AF01FFF8 */  sw    $at, -8($t8)
/* 003FA4 700033A4 8F21FFFC */  lw    $at, -4($t9)
/* 003FA8 700033A8 172EFFF8 */  bne   $t9, $t6, .L7000338C
/* 003FAC 700033AC AF01FFFC */   sw    $at, -4($t8)
/* 003FB0 700033B0 8F210000 */  lw    $at, ($t9)
/* 003FB4 700033B4 8F2E0004 */  lw    $t6, 4($t9)
/* 003FB8 700033B8 AF010000 */  sw    $at, ($t8)
/* 003FBC 700033BC 10000029 */  b     .L70003464
/* 003FC0 700033C0 AF0E0004 */   sw    $t6, 4($t8)
.L700033C4:
/* 003FC4 700033C4 8DEF0300 */  lw    $t7, 0x300($t7)
/* 003FC8 700033C8 24010002 */  li    $at, 2
/* 003FCC 700033CC 3C188006 */  lui   $t8, %hi(g_viOriginalVideoMode) 
/* 003FD0 700033D0 15E10014 */  bne   $t7, $at, .L70003424
/* 003FD4 700033D4 27180828 */   addiu $t8, %lo(g_viOriginalVideoMode) # addiu $t8, $t8, 0x828
/* 003FD8 700033D8 3C198002 */  lui   $t9, %hi(osViModeTable_osViModeMpalLan2) 
/* 003FDC 700033DC 27397460 */  addiu $t9, %lo(osViModeTable_osViModeMpalLan2) # addiu $t9, $t9, 0x7460
/* 003FE0 700033E0 3C0E8006 */  lui   $t6, %hi(g_viOriginalVideoMode) 
/* 003FE4 700033E4 25CE0828 */  addiu $t6, %lo(g_viOriginalVideoMode) # addiu $t6, $t6, 0x828
/* 003FE8 700033E8 272F0048 */  addiu $t7, $t9, 0x48
.L700033EC:
/* 003FEC 700033EC 8F210000 */  lw    $at, ($t9)
/* 003FF0 700033F0 2739000C */  addiu $t9, $t9, 0xc
/* 003FF4 700033F4 25CE000C */  addiu $t6, $t6, 0xc
/* 003FF8 700033F8 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 003FFC 700033FC 8F21FFF8 */  lw    $at, -8($t9)
/* 004000 70003400 ADC1FFF8 */  sw    $at, -8($t6)
/* 004004 70003404 8F21FFFC */  lw    $at, -4($t9)
/* 004008 70003408 172FFFF8 */  bne   $t9, $t7, .L700033EC
/* 00400C 7000340C ADC1FFFC */   sw    $at, -4($t6)
/* 004010 70003410 8F210000 */  lw    $at, ($t9)
/* 004014 70003414 8F2F0004 */  lw    $t7, 4($t9)
/* 004018 70003418 ADC10000 */  sw    $at, ($t6)
/* 00401C 7000341C 10000011 */  b     .L70003464
/* 004020 70003420 ADCF0004 */   sw    $t7, 4($t6)
.L70003424:
/* 004024 70003424 3C0F8002 */  lui   $t7, %hi(osViModeTable_osViModeNtscLan2) 
/* 004028 70003428 25EF6BA0 */  addiu $t7, %lo(osViModeTable_osViModeNtscLan2) # addiu $t7, $t7, 0x6ba0
/* 00402C 7000342C 25EE0048 */  addiu $t6, $t7, 0x48
.L70003430:
/* 004030 70003430 8DE10000 */  lw    $at, ($t7)
/* 004034 70003434 25EF000C */  addiu $t7, $t7, 0xc
/* 004038 70003438 2718000C */  addiu $t8, $t8, 0xc
/* 00403C 7000343C AF01FFF4 */  sw    $at, -0xc($t8)
/* 004040 70003440 8DE1FFF8 */  lw    $at, -8($t7)
/* 004044 70003444 AF01FFF8 */  sw    $at, -8($t8)
/* 004048 70003448 8DE1FFFC */  lw    $at, -4($t7)
/* 00404C 7000344C 15EEFFF8 */  bne   $t7, $t6, .L70003430
/* 004050 70003450 AF01FFFC */   sw    $at, -4($t8)
/* 004054 70003454 8DE10000 */  lw    $at, ($t7)
/* 004058 70003458 8DEE0004 */  lw    $t6, 4($t7)
/* 00405C 7000345C AF010000 */  sw    $at, ($t8)
/* 004060 70003460 AF0E0004 */  sw    $t6, 4($t8)
.L70003464:
/* 004064 70003464 3C198006 */  lui   $t9, %hi(g_viOriginalVideoMode) 
/* 004068 70003468 27390828 */  addiu $t9, %lo(g_viOriginalVideoMode) # addiu $t9, $t9, 0x828
/* 00406C 7000346C AC790000 */  sw    $t9, ($v1)
/* 004070 70003470 8F2E001C */  lw    $t6, 0x1c($t9)
/* 004074 70003474 3C018006 */  lui   $at, %hi(viMode+0x4)
/* 004078 70003478 00002025 */  move  $a0, $zero
/* 00407C 7000347C AC2E0880 */  sw    $t6, %lo(viMode+0x4)($at)
/* 004080 70003480 8F2F0030 */  lw    $t7, 0x30($t9)
/* 004084 70003484 3C018006 */  lui   $at, %hi(viMode+0x8)
/* 004088 70003488 AC2F0884 */  sw    $t7, %lo(viMode+0x8)($at)
/* 00408C 7000348C 8F380044 */  lw    $t8, 0x44($t9)
/* 004090 70003490 3C018006 */  lui   $at, %hi(viMode+0xC)
/* 004094 70003494 0C000C64 */  jal   viSet800232BC
/* 004098 70003498 AC380888 */   sw    $t8, %lo(viMode+0xC)($at)
/* 00409C 7000349C 1000001B */  b     .L7000350C
/* 0040A0 700034A0 00000000 */   nop   
.L700034A4:
/* 0040A4 700034A4 8F390300 */  lw    $t9, 0x300($t9)
/* 0040A8 700034A8 24010002 */  li    $at, 2
/* 0040AC 700034AC 3C038006 */  lui   $v1, %hi(viMode)
/* 0040B0 700034B0 17210007 */  bne   $t9, $at, .L700034D0
/* 0040B4 700034B4 2463087C */   addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
/* 0040B8 700034B8 3C038006 */  lui   $v1, %hi(viMode)
/* 0040BC 700034BC 3C0E8002 */  lui   $t6, %hi(osViModeTable_osViModeMpalHaf1) 
/* 0040C0 700034C0 2463087C */  addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
/* 0040C4 700034C4 25CE75F0 */  addiu $t6, %lo(osViModeTable_osViModeMpalHaf1) # addiu $t6, $t6, 0x75f0
/* 0040C8 700034C8 10000004 */  b     .L700034DC
/* 0040CC 700034CC AC6E0000 */   sw    $t6, ($v1)
.L700034D0:
/* 0040D0 700034D0 3C0F8002 */  lui   $t7, %hi(osViModeTable_osViModeNtscHaf1) 
/* 0040D4 700034D4 25EF6D30 */  addiu $t7, %lo(osViModeTable_osViModeNtscHaf1) # addiu $t7, $t7, 0x6d30
/* 0040D8 700034D8 AC6F0000 */  sw    $t7, ($v1)
.L700034DC:
/* 0040DC 700034DC 8C620000 */  lw    $v0, ($v1)
/* 0040E0 700034E0 3C018006 */  lui   $at, %hi(viMode+0x4)
/* 0040E4 700034E4 00002025 */  move  $a0, $zero
/* 0040E8 700034E8 8C58001C */  lw    $t8, 0x1c($v0)
/* 0040EC 700034EC AC380880 */  sw    $t8, %lo(viMode+0x4)($at)
/* 0040F0 700034F0 8C590030 */  lw    $t9, 0x30($v0)
/* 0040F4 700034F4 3C018006 */  lui   $at, %hi(viMode+0x8)
/* 0040F8 700034F8 AC390884 */  sw    $t9, %lo(viMode+0x8)($at)
/* 0040FC 700034FC 8C4E0044 */  lw    $t6, 0x44($v0)
/* 004100 70003500 3C018006 */  lui   $at, %hi(viMode+0xC)
/* 004104 70003504 0C0038B4 */  jal   osViBlack
/* 004108 70003508 AC2E0888 */   sw    $t6, %lo(viMode+0xC)($at)
.L7000350C:
/* 00410C 7000350C 0C003DEC */  jal   osViSetSpecialFeatures
/* 004110 70003510 24040042 */   li    $a0, 66
/* 004114 70003514 3C088002 */  lui   $t0, %hi(ptr_video_settings2) 
/* 004118 70003518 8D0832A8 */  lw    $t0, %lo(ptr_video_settings2)($t0)
/* 00411C 7000351C 3C0D8002 */  lui   $t5, %hi(ptr_video_settings2) 
/* 004120 70003520 25AD32A8 */  addiu $t5, %lo(ptr_video_settings2) # addiu $t5, $t5, 0x32a8
/* 004124 70003524 91020000 */  lbu   $v0, ($t0)
/* 004128 70003528 850F0004 */  lh    $t7, 4($t0)
.L7000352C:
/* 00412C 7000352C 85180018 */  lh    $t8, 0x18($t0)
/* 004130 70003530 85190006 */  lh    $t9, 6($t0)
/* 004134 70003534 448F2000 */  mtc1  $t7, $f4
/* 004138 70003538 850E001A */  lh    $t6, 0x1a($t0)
/* 00413C 7000353C 44984000 */  mtc1  $t8, $f8
/* 004140 70003540 468021A0 */  cvt.s.w $f6, $f4
/* 004144 70003544 44998000 */  mtc1  $t9, $f16
/* 004148 70003548 448E2000 */  mtc1  $t6, $f4
/* 00414C 7000354C 3C188006 */  lui   $t8, %hi(g_viOriginalVideoMode) 
/* 004150 70003550 3C0A8002 */  lui   $t2, %hi(D_800232C0) 
/* 004154 70003554 468042A0 */  cvt.s.w $f10, $f8
/* 004158 70003558 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 00415C 7000355C 27180828 */  addiu $t8, %lo(g_viOriginalVideoMode) # addiu $t8, $t8, 0x828
/* 004160 70003560 3C0B8002 */  lui   $t3, %hi(g_viColorOutputMode) 
/* 004164 70003564 468084A0 */  cvt.s.w $f18, $f16
/* 004168 70003568 46802220 */  cvt.s.w $f8, $f4
/* 00416C 7000356C 460A3083 */  div.s $f2, $f6, $f10
/* 004170 70003570 14400003 */  bnez  $v0, .L70003580
/* 004174 70003574 46089003 */   div.s $f0, $f18, $f8
/* 004178 70003578 44810000 */  mtc1  $at, $f0
/* 00417C 7000357C 00000000 */  nop   
.L70003580:
/* 004180 70003580 8D4A32C0 */  lw    $t2, %lo(D_800232C0)($t2)
/* 004184 70003584 3C018002 */  lui   $at, %hi(g_ViXScales)
/* 004188 70003588 000A4880 */  sll   $t1, $t2, 2
/* 00418C 7000358C 00290821 */  addu  $at, $at, $t1
/* 004190 70003590 E42230B4 */  swc1  $f2, %lo(g_ViXScales)($at)
/* 004194 70003594 3C018002 */  lui   $at, %hi(g_ViYScales)
/* 004198 70003598 00290821 */  addu  $at, $at, $t1
/* 00419C 7000359C E42030BC */  swc1  $f0, %lo(g_ViYScales)($at)
/* 0041A0 700035A0 910F0000 */  lbu   $t7, ($t0)
/* 0041A4 700035A4 24010001 */  li    $at, 1
/* 0041A8 700035A8 15E10105 */  bne   $t7, $at, .L700039C0
/* 0041AC 700035AC 00000000 */   nop   
/* 0041B0 700035B0 8D6B32AC */  lw    $t3, %lo(g_viColorOutputMode)($t3)
/* 0041B4 700035B4 3C018006 */  lui   $at, %hi(g_ViModePtrs)
/* 0041B8 700035B8 00290821 */  addu  $at, $at, $t1
/* 0041BC 700035BC 11600035 */  beqz  $t3, .L70003694
/* 0041C0 700035C0 AC38DBE0 */   sw    $t8, %lo(g_ViModePtrs)($at)
/* 0041C4 700035C4 3C198000 */  lui   $t9, %hi(osTvType) 
/* 0041C8 700035C8 8F390300 */  lw    $t9, %lo(osTvType)($t9)
/* 0041CC 700035CC 24010002 */  li    $at, 2
/* 0041D0 700035D0 3C0E8006 */  lui   $t6, %hi(g_ViModes) 
/* 0041D4 700035D4 17210019 */  bne   $t9, $at, .L7000363C
/* 0041D8 700035D8 25CEDB40 */   addiu $t6, %lo(g_ViModes) # addiu $t6, $t6, -0x24c0
/* 0041DC 700035DC 000A7080 */  sll   $t6, $t2, 2
/* 0041E0 700035E0 01CA7021 */  addu  $t6, $t6, $t2
/* 0041E4 700035E4 3C0F8006 */  lui   $t7, %hi(g_ViModes) 
/* 0041E8 700035E8 25EFDB40 */  addiu $t7, %lo(g_ViModes) # addiu $t7, $t7, -0x24c0
/* 0041EC 700035EC 000E7100 */  sll   $t6, $t6, 4
/* 0041F0 700035F0 01CF1821 */  addu  $v1, $t6, $t7
/* 0041F4 700035F4 3C188002 */  lui   $t8, %hi(osViModeTable_osViModeMpalLan1) 
/* 0041F8 700035F8 27187320 */  addiu $t8, %lo(osViModeTable_osViModeMpalLan1) # addiu $t8, $t8, 0x7320
/* 0041FC 700035FC 270E0048 */  addiu $t6, $t8, 0x48
/* 004200 70003600 00607825 */  move  $t7, $v1
.L70003604:
/* 004204 70003604 8F010000 */  lw    $at, ($t8)
/* 004208 70003608 2718000C */  addiu $t8, $t8, 0xc
/* 00420C 7000360C 25EF000C */  addiu $t7, $t7, 0xc
/* 004210 70003610 ADE1FFF4 */  sw    $at, -0xc($t7)
/* 004214 70003614 8F01FFF8 */  lw    $at, -8($t8)
/* 004218 70003618 ADE1FFF8 */  sw    $at, -8($t7)
/* 00421C 7000361C 8F01FFFC */  lw    $at, -4($t8)
/* 004220 70003620 170EFFF8 */  bne   $t8, $t6, .L70003604
/* 004224 70003624 ADE1FFFC */   sw    $at, -4($t7)
/* 004228 70003628 8F010000 */  lw    $at, ($t8)
/* 00422C 7000362C ADE10000 */  sw    $at, ($t7)
/* 004230 70003630 8F0E0004 */  lw    $t6, 4($t8)
/* 004234 70003634 1000004A */  b     .L70003760
/* 004238 70003638 ADEE0004 */   sw    $t6, 4($t7)
.L7000363C:
/* 00423C 7000363C 000AC880 */  sll   $t9, $t2, 2
/* 004240 70003640 032AC821 */  addu  $t9, $t9, $t2
/* 004244 70003644 0019C900 */  sll   $t9, $t9, 4
/* 004248 70003648 032E1821 */  addu  $v1, $t9, $t6
/* 00424C 7000364C 3C188002 */  lui   $t8, %hi(osViModeTable_osViModeNtscLan1) 
/* 004250 70003650 27186A60 */  addiu $t8, %lo(osViModeTable_osViModeNtscLan1) # addiu $t8, $t8, 0x6a60
/* 004254 70003654 27190048 */  addiu $t9, $t8, 0x48
/* 004258 70003658 00607025 */  move  $t6, $v1
.L7000365C:
/* 00425C 7000365C 8F010000 */  lw    $at, ($t8)
/* 004260 70003660 2718000C */  addiu $t8, $t8, 0xc
/* 004264 70003664 25CE000C */  addiu $t6, $t6, 0xc
/* 004268 70003668 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 00426C 7000366C 8F01FFF8 */  lw    $at, -8($t8)
/* 004270 70003670 ADC1FFF8 */  sw    $at, -8($t6)
/* 004274 70003674 8F01FFFC */  lw    $at, -4($t8)
/* 004278 70003678 1719FFF8 */  bne   $t8, $t9, .L7000365C
/* 00427C 7000367C ADC1FFFC */   sw    $at, -4($t6)
/* 004280 70003680 8F010000 */  lw    $at, ($t8)
/* 004284 70003684 ADC10000 */  sw    $at, ($t6)
/* 004288 70003688 8F190004 */  lw    $t9, 4($t8)
/* 00428C 7000368C 10000034 */  b     .L70003760
/* 004290 70003690 ADD90004 */   sw    $t9, 4($t6)
.L70003694:
/* 004294 70003694 3C0F8000 */  lui   $t7, %hi(osTvType) 
/* 004298 70003698 8DEF0300 */  lw    $t7, %lo(osTvType)($t7)
/* 00429C 7000369C 24010002 */  li    $at, 2
/* 0042A0 700036A0 15E10018 */  bne   $t7, $at, .L70003704
/* 0042A4 700036A4 000AC880 */   sll   $t9, $t2, 2
/* 0042A8 700036A8 032AC821 */  addu  $t9, $t9, $t2
/* 0042AC 700036AC 3C188006 */  lui   $t8, %hi(g_ViModes) 
/* 0042B0 700036B0 2718DB40 */  addiu $t8, %lo(g_ViModes) # addiu $t8, $t8, -0x24c0
/* 0042B4 700036B4 0019C900 */  sll   $t9, $t9, 4
/* 0042B8 700036B8 03381821 */  addu  $v1, $t9, $t8
/* 0042BC 700036BC 3C0E8002 */  lui   $t6, %hi(osViModeTable_osViModeMpalLan2) 
/* 0042C0 700036C0 25CE7460 */  addiu $t6, %lo(osViModeTable_osViModeMpalLan2) # addiu $t6, $t6, 0x7460
/* 0042C4 700036C4 25D90048 */  addiu $t9, $t6, 0x48
/* 0042C8 700036C8 0060C025 */  move  $t8, $v1
.L700036CC:
/* 0042CC 700036CC 8DC10000 */  lw    $at, ($t6)
/* 0042D0 700036D0 25CE000C */  addiu $t6, $t6, 0xc
/* 0042D4 700036D4 2718000C */  addiu $t8, $t8, 0xc
/* 0042D8 700036D8 AF01FFF4 */  sw    $at, -0xc($t8)
/* 0042DC 700036DC 8DC1FFF8 */  lw    $at, -8($t6)
/* 0042E0 700036E0 AF01FFF8 */  sw    $at, -8($t8)
/* 0042E4 700036E4 8DC1FFFC */  lw    $at, -4($t6)
/* 0042E8 700036E8 15D9FFF8 */  bne   $t6, $t9, .L700036CC
/* 0042EC 700036EC AF01FFFC */   sw    $at, -4($t8)
/* 0042F0 700036F0 8DC10000 */  lw    $at, ($t6)
/* 0042F4 700036F4 AF010000 */  sw    $at, ($t8)
/* 0042F8 700036F8 8DD90004 */  lw    $t9, 4($t6)
/* 0042FC 700036FC 10000018 */  b     .L70003760
/* 004300 70003700 AF190004 */   sw    $t9, 4($t8)
.L70003704:
/* 004304 70003704 000A7880 */  sll   $t7, $t2, 2
/* 004308 70003708 01EA7821 */  addu  $t7, $t7, $t2
/* 00430C 7000370C 3C198006 */  lui   $t9, %hi(g_ViModes) 
/* 004310 70003710 2739DB40 */  addiu $t9, %lo(g_ViModes) # addiu $t9, $t9, -0x24c0
/* 004314 70003714 000F7900 */  sll   $t7, $t7, 4
/* 004318 70003718 01F91821 */  addu  $v1, $t7, $t9
/* 00431C 7000371C 3C0E8002 */  lui   $t6, %hi(osViModeTable_osViModeNtscLan2) 
/* 004320 70003720 25CE6BA0 */  addiu $t6, %lo(osViModeTable_osViModeNtscLan2) # addiu $t6, $t6, 0x6ba0
/* 004324 70003724 25CF0048 */  addiu $t7, $t6, 0x48
/* 004328 70003728 0060C825 */  move  $t9, $v1
.L7000372C:
/* 00432C 7000372C 8DC10000 */  lw    $at, ($t6)
/* 004330 70003730 25CE000C */  addiu $t6, $t6, 0xc
/* 004334 70003734 2739000C */  addiu $t9, $t9, 0xc
/* 004338 70003738 AF21FFF4 */  sw    $at, -0xc($t9)
/* 00433C 7000373C 8DC1FFF8 */  lw    $at, -8($t6)
/* 004340 70003740 AF21FFF8 */  sw    $at, -8($t9)
/* 004344 70003744 8DC1FFFC */  lw    $at, -4($t6)
/* 004348 70003748 15CFFFF8 */  bne   $t6, $t7, .L7000372C
/* 00434C 7000374C AF21FFFC */   sw    $at, -4($t9)
/* 004350 70003750 8DC10000 */  lw    $at, ($t6)
/* 004354 70003754 AF210000 */  sw    $at, ($t9)
/* 004358 70003758 8DCF0004 */  lw    $t7, 4($t6)
/* 00435C 7000375C AF2F0004 */  sw    $t7, 4($t9)
.L70003760:
/* 004360 70003760 85180018 */  lh    $t8, 0x18($t0)
/* 004364 70003764 24010280 */  li    $at, 640
/* 004368 70003768 240C01E0 */  li    $t4, 480
/* 00436C 7000376C AC780008 */  sw    $t8, 8($v1)
/* 004370 70003770 850F0018 */  lh    $t7, 0x18($t0)
/* 004374 70003774 8C62001C */  lw    $v0, 0x1c($v1)
/* 004378 70003778 3C078002 */  lui   $a3, %hi(g_viHorizontalOffset)
/* 00437C 7000377C 000F7280 */  sll   $t6, $t7, 0xa
/* 004380 70003780 01C1001A */  div   $zero, $t6, $at
/* 004384 70003784 0000C812 */  mflo  $t9
/* 004388 70003788 AC790020 */  sw    $t9, 0x20($v1)
/* 00438C 7000378C 8518001A */  lh    $t8, 0x1a($t0)
/* 004390 70003790 3406FFFF */  li    $a2, 65535
/* 004394 70003794 3C058002 */  lui   $a1, %hi(D_800232A0)
/* 004398 70003798 00187AC0 */  sll   $t7, $t8, 0xb
/* 00439C 7000379C 01EC001A */  div   $zero, $t7, $t4
/* 0043A0 700037A0 00007012 */  mflo  $t6
/* 0043A4 700037A4 AC6E002C */  sw    $t6, 0x2c($v1)
/* 0043A8 700037A8 8519001A */  lh    $t9, 0x1a($t0)
/* 0043AC 700037AC 15800002 */  bnez  $t4, .L700037B8
/* 0043B0 700037B0 00000000 */   nop   
/* 0043B4 700037B4 0007000D */  break 7
.L700037B8:
/* 0043B8 700037B8 2401FFFF */  li    $at, -1
/* 0043BC 700037BC 15810004 */  bne   $t4, $at, .L700037D0
/* 0043C0 700037C0 3C018000 */   lui   $at, 0x8000
/* 0043C4 700037C4 15E10002 */  bne   $t7, $at, .L700037D0
/* 0043C8 700037C8 00000000 */   nop   
/* 0043CC 700037CC 0006000D */  break 6
.L700037D0:
/* 0043D0 700037D0 0019C2C0 */  sll   $t8, $t9, 0xb
/* 0043D4 700037D4 030C001A */  div   $zero, $t8, $t4
/* 0043D8 700037D8 00007812 */  mflo  $t7
/* 0043DC 700037DC AC6F0040 */  sw    $t7, 0x40($v1)
/* 0043E0 700037E0 850E0018 */  lh    $t6, 0x18($t0)
/* 0043E4 700037E4 15800002 */  bnez  $t4, .L700037F0
/* 0043E8 700037E8 00000000 */   nop   
/* 0043EC 700037EC 0007000D */  break 7
.L700037F0:
/* 0043F0 700037F0 2401FFFF */  li    $at, -1
/* 0043F4 700037F4 15810004 */  bne   $t4, $at, .L70003808
/* 0043F8 700037F8 3C018000 */   lui   $at, 0x8000
/* 0043FC 700037FC 17010002 */  bne   $t8, $at, .L70003808
/* 004400 70003800 00000000 */   nop   
/* 004404 70003804 0006000D */  break 6
.L70003808:
/* 004408 70003808 000EC840 */  sll   $t9, $t6, 1
/* 00440C 7000380C AC790028 */  sw    $t9, 0x28($v1)
/* 004410 70003810 85180018 */  lh    $t8, 0x18($t0)
/* 004414 70003814 00027403 */  sra   $t6, $v0, 0x10
/* 004418 70003818 31D9FFFF */  andi  $t9, $t6, 0xffff
/* 00441C 7000381C 00187840 */  sll   $t7, $t8, 1
/* 004420 70003820 AC6F003C */  sw    $t7, 0x3c($v1)
/* 004424 70003824 8CE7329C */  lw    $a3, %lo(g_viHorizontalOffset)($a3)
/* 004428 70003828 0327C021 */  addu  $t8, $t9, $a3
/* 00442C 7000382C 0306001A */  div   $zero, $t8, $a2
/* 004430 70003830 14C00002 */  bnez  $a2, .L7000383C
/* 004434 70003834 00000000 */   nop   
/* 004438 70003838 0007000D */  break 7
.L7000383C:
/* 00443C 7000383C 2401FFFF */  li    $at, -1
/* 004440 70003840 14C10004 */  bne   $a2, $at, .L70003854
/* 004444 70003844 3C018000 */   lui   $at, 0x8000
/* 004448 70003848 17010002 */  bne   $t8, $at, .L70003854
/* 00444C 7000384C 00000000 */   nop   
/* 004450 70003850 0006000D */  break 6
.L70003854:
/* 004454 70003854 3059FFFF */  andi  $t9, $v0, 0xffff
/* 004458 70003858 00007810 */  mfhi  $t7
/* 00445C 7000385C 0327C021 */  addu  $t8, $t9, $a3
/* 004460 70003860 000F7400 */  sll   $t6, $t7, 0x10
/* 004464 70003864 0306001A */  div   $zero, $t8, $a2
/* 004468 70003868 14C00002 */  bnez  $a2, .L70003874
/* 00446C 7000386C 00000000 */   nop   
/* 004470 70003870 0007000D */  break 7
.L70003874:
/* 004474 70003874 2401FFFF */  li    $at, -1
/* 004478 70003878 14C10004 */  bne   $a2, $at, .L7000388C
/* 00447C 7000387C 3C018000 */   lui   $at, 0x8000
/* 004480 70003880 17010002 */  bne   $t8, $at, .L7000388C
/* 004484 70003884 00000000 */   nop   
/* 004488 70003888 0006000D */  break 6
.L7000388C:
/* 00448C 7000388C 00007810 */  mfhi  $t7
/* 004490 70003890 01CF2025 */  or    $a0, $t6, $t7
/* 004494 70003894 AC64001C */  sw    $a0, 0x1c($v1)
/* 004498 70003898 3C018006 */  lui   $at, %hi(viMode+0x4)
/* 00449C 7000389C AC240880 */  sw    $a0, %lo(viMode+0x4)($at)
/* 0044A0 700038A0 8C620030 */  lw    $v0, 0x30($v1)
/* 0044A4 700038A4 8CA532A0 */  lw    $a1, %lo(D_800232A0)($a1)
/* 0044A8 700038A8 0002CC03 */  sra   $t9, $v0, 0x10
/* 0044AC 700038AC 3338FFFF */  andi  $t8, $t9, 0xffff
/* 0044B0 700038B0 03057021 */  addu  $t6, $t8, $a1
/* 0044B4 700038B4 01C6001A */  div   $zero, $t6, $a2
/* 0044B8 700038B8 14C00002 */  bnez  $a2, .L700038C4
/* 0044BC 700038BC 00000000 */   nop   
/* 0044C0 700038C0 0007000D */  break 7
.L700038C4:
/* 0044C4 700038C4 2401FFFF */  li    $at, -1
/* 0044C8 700038C8 14C10004 */  bne   $a2, $at, .L700038DC
/* 0044CC 700038CC 3C018000 */   lui   $at, 0x8000
/* 0044D0 700038D0 15C10002 */  bne   $t6, $at, .L700038DC
/* 0044D4 700038D4 00000000 */   nop   
/* 0044D8 700038D8 0006000D */  break 6
.L700038DC:
/* 0044DC 700038DC 3058FFFF */  andi  $t8, $v0, 0xffff
/* 0044E0 700038E0 00007810 */  mfhi  $t7
/* 0044E4 700038E4 03057021 */  addu  $t6, $t8, $a1
/* 0044E8 700038E8 000FCC00 */  sll   $t9, $t7, 0x10
/* 0044EC 700038EC 01C6001A */  div   $zero, $t6, $a2
/* 0044F0 700038F0 14C00002 */  bnez  $a2, .L700038FC
/* 0044F4 700038F4 00000000 */   nop   
/* 0044F8 700038F8 0007000D */  break 7
.L700038FC:
/* 0044FC 700038FC 2401FFFF */  li    $at, -1
/* 004500 70003900 14C10004 */  bne   $a2, $at, .L70003914
/* 004504 70003904 3C018000 */   lui   $at, 0x8000
/* 004508 70003908 15C10002 */  bne   $t6, $at, .L70003914
/* 00450C 7000390C 00000000 */   nop   
/* 004510 70003910 0006000D */  break 6
.L70003914:
/* 004514 70003914 00007810 */  mfhi  $t7
/* 004518 70003918 032F2025 */  or    $a0, $t9, $t7
/* 00451C 7000391C AC640030 */  sw    $a0, 0x30($v1)
/* 004520 70003920 3C018006 */  lui   $at, %hi(viMode+0x8)
/* 004524 70003924 AC240884 */  sw    $a0, %lo(viMode+0x8)($at)
/* 004528 70003928 8C620044 */  lw    $v0, 0x44($v1)
/* 00452C 7000392C 0002C403 */  sra   $t8, $v0, 0x10
/* 004530 70003930 330EFFFF */  andi  $t6, $t8, 0xffff
/* 004534 70003934 01C5C821 */  addu  $t9, $t6, $a1
/* 004538 70003938 0326001A */  div   $zero, $t9, $a2
/* 00453C 7000393C 14C00002 */  bnez  $a2, .L70003948
/* 004540 70003940 00000000 */   nop   
/* 004544 70003944 0007000D */  break 7
.L70003948:
/* 004548 70003948 2401FFFF */  li    $at, -1
/* 00454C 7000394C 14C10004 */  bne   $a2, $at, .L70003960
/* 004550 70003950 3C018000 */   lui   $at, 0x8000
/* 004554 70003954 17210002 */  bne   $t9, $at, .L70003960
/* 004558 70003958 00000000 */   nop   
/* 00455C 7000395C 0006000D */  break 6
.L70003960:
/* 004560 70003960 304EFFFF */  andi  $t6, $v0, 0xffff
/* 004564 70003964 01C5C821 */  addu  $t9, $t6, $a1
/* 004568 70003968 00007810 */  mfhi  $t7
/* 00456C 7000396C 000FC400 */  sll   $t8, $t7, 0x10
/* 004570 70003970 240E0001 */  li    $t6, 1
/* 004574 70003974 0326001A */  div   $zero, $t9, $a2
/* 004578 70003978 14C00002 */  bnez  $a2, .L70003984
/* 00457C 7000397C 00000000 */   nop   
/* 004580 70003980 0007000D */  break 7
.L70003984:
/* 004584 70003984 2401FFFF */  li    $at, -1
/* 004588 70003988 14C10004 */  bne   $a2, $at, .L7000399C
/* 00458C 7000398C 3C018000 */   lui   $at, 0x8000
/* 004590 70003990 17210002 */  bne   $t9, $at, .L7000399C
/* 004594 70003994 00000000 */   nop   
/* 004598 70003998 0006000D */  break 6
.L7000399C:
/* 00459C 7000399C 00007810 */  mfhi  $t7
/* 0045A0 700039A0 030F2025 */  or    $a0, $t8, $t7
/* 0045A4 700039A4 AC640044 */  sw    $a0, 0x44($v1)
/* 0045A8 700039A8 3C018006 */  lui   $at, %hi(viMode+0xC)
/* 0045AC 700039AC AC240888 */  sw    $a0, %lo(viMode+0xC)($at)
/* 0045B0 700039B0 3C018002 */  lui   $at, %hi(g_ViChangeVideoModes)
/* 0045B4 700039B4 00290821 */  addu  $at, $at, $t1
/* 0045B8 700039B8 10000006 */  b     .L700039D4
/* 0045BC 700039BC AC2E30C4 */   sw    $t6, %lo(g_ViChangeVideoModes)($at)
.L700039C0:
/* 0045C0 700039C0 3C018002 */  lui   $at, %hi(g_ViChangeVideoModes)
/* 0045C4 700039C4 00290821 */  addu  $at, $at, $t1
/* 0045C8 700039C8 3C0B8002 */  lui   $t3, %hi(g_viColorOutputMode) 
/* 0045CC 700039CC 8D6B32AC */  lw    $t3, %lo(g_viColorOutputMode)($t3)
/* 0045D0 700039D0 AC2030C4 */  sw    $zero, %lo(g_ViChangeVideoModes)($at)
.L700039D4:
/* 0045D4 700039D4 254A0001 */  addiu $t2, $t2, 1
/* 0045D8 700039D8 05410004 */  bgez  $t2, .L700039EC
/* 0045DC 700039DC 31590001 */   andi  $t9, $t2, 1
/* 0045E0 700039E0 13200002 */  beqz  $t9, .L700039EC
/* 0045E4 700039E4 00000000 */   nop   
/* 0045E8 700039E8 2739FFFE */  addiu $t9, $t9, -2
.L700039EC:
/* 0045EC 700039EC 3C018002 */  lui   $at, %hi(D_800232C0)
/* 0045F0 700039F0 11600006 */  beqz  $t3, .L70003A0C
/* 0045F4 700039F4 AC3932C0 */   sw    $t9, %lo(D_800232C0)($at)
/* 0045F8 700039F8 3C0F8005 */  lui   $t7, %hi(g_gfxTaskSettingsList) 
/* 0045FC 700039FC 8DEFEAB0 */  lw    $t7, %lo(g_gfxTaskSettingsList)($t7)
/* 004600 70003A00 8D180028 */  lw    $t8, 0x28($t0)
/* 004604 70003A04 10000006 */  b     .L70003A20
/* 004608 70003A08 ADF80058 */   sw    $t8, 0x58($t7)
.L70003A0C:
/* 00460C 70003A0C 3C198005 */  lui   $t9, %hi(g_gfxTaskSettingsList) 
/* 004610 70003A10 8F39EAB0 */  lw    $t9, %lo(g_gfxTaskSettingsList)($t9)
/* 004614 70003A14 3C0E803B */  lui   $t6, %hi(cfb_16) # $t6, 0x803b
/* 004618 70003A18 25CE5000 */  addiu $t6, %lo(cfb_16) # addiu $t6, $t6, 0x5000
/* 00461C 70003A1C AF2E0058 */  sw    $t6, 0x58($t9)
.L70003A20:
/* 004620 70003A20 3C028006 */  lui   $v0, %hi(g_viVideoSettings1FrameBufferIndex)
/* 004624 70003A24 24420878 */  addiu $v0, %lo(g_viVideoSettings1FrameBufferIndex) # addiu $v0, $v0, 0x878
/* 004628 70003A28 90580000 */  lbu   $t8, ($v0)
/* 00462C 70003A2C 3C038006 */  lui   $v1, %hi(g_viVideoSettings2FrameBufferIndex)
/* 004630 70003A30 2408002C */  li    $t0, 44
/* 004634 70003A34 270F0001 */  addiu $t7, $t8, 1
/* 004638 70003A38 24630879 */  addiu $v1, %lo(g_viVideoSettings2FrameBufferIndex) # addiu $v1, $v1, 0x879
/* 00463C 70003A3C 90790000 */  lbu   $t9, ($v1)
/* 004640 70003A40 3C078002 */  lui   $a3, %hi(g_videoSettings)
/* 004644 70003A44 24E73244 */  addiu $a3, %lo(g_videoSettings) # addiu $a3, $a3, 0x3244
/* 004648 70003A48 27380001 */  addiu $t8, $t9, 1
/* 00464C 70003A4C 8DA40000 */  lw    $a0, ($t5)
/* 004650 70003A50 05E10004 */  bgez  $t7, .L70003A64
/* 004654 70003A54 31EE0001 */   andi  $t6, $t7, 1
/* 004658 70003A58 11C00002 */  beqz  $t6, .L70003A64
/* 00465C 70003A5C 00000000 */   nop   
/* 004660 70003A60 25CEFFFE */  addiu $t6, $t6, -2
.L70003A64:
/* 004664 70003A64 A04E0000 */  sb    $t6, ($v0)
/* 004668 70003A68 904E0000 */  lbu   $t6, ($v0)
/* 00466C 70003A6C 07010004 */  bgez  $t8, .L70003A80
/* 004670 70003A70 330F0001 */   andi  $t7, $t8, 1
/* 004674 70003A74 11E00002 */  beqz  $t7, .L70003A80
/* 004678 70003A78 00000000 */   nop   
/* 00467C 70003A7C 25EFFFFE */  addiu $t7, $t7, -2
.L70003A80:
/* 004680 70003A80 01C80019 */  multu $t6, $t0
/* 004684 70003A84 A06F0000 */  sb    $t7, ($v1)
/* 004688 70003A88 3C018002 */  lui   $at, %hi(ptr_video_settings1)
/* 00468C 70003A8C 2406002C */  li    $a2, 44
/* 004690 70003A90 0000C812 */  mflo  $t9
/* 004694 70003A94 00F9C021 */  addu  $t8, $a3, $t9
/* 004698 70003A98 AC3832A4 */  sw    $t8, %lo(ptr_video_settings1)($at)
/* 00469C 70003A9C 906F0000 */  lbu   $t7, ($v1)
/* 0046A0 70003AA0 01E80019 */  multu $t7, $t0
/* 0046A4 70003AA4 00007012 */  mflo  $t6
/* 0046A8 70003AA8 00EE2821 */  addu  $a1, $a3, $t6
/* 0046AC 70003AAC 0C003E5C */  jal   bcopy
/* 0046B0 70003AB0 ADA50000 */   sw    $a1, ($t5)
/* 0046B4 70003AB4 3C038006 */  lui   $v1, %hi(g_viVideoSettings2FrameBufferIndex)
/* 0046B8 70003AB8 24630879 */  addiu $v1, %lo(g_viVideoSettings2FrameBufferIndex) # addiu $v1, $v1, 0x879
/* 0046BC 70003ABC 90780000 */  lbu   $t8, ($v1)
/* 0046C0 70003AC0 3C0E803B */  lui   $t6, %hi(cfb_16) # $t6, 0x803b
/* 0046C4 70003AC4 25CE5000 */  addiu $t6, %lo(cfb_16) # addiu $t6, $t6, 0x5000
/* 0046C8 70003AC8 00187880 */  sll   $t7, $t8, 2
/* 0046CC 70003ACC 01F87821 */  addu  $t7, $t7, $t8
/* 0046D0 70003AD0 000F7880 */  sll   $t7, $t7, 2
/* 0046D4 70003AD4 01F87823 */  subu  $t7, $t7, $t8
/* 0046D8 70003AD8 000F7880 */  sll   $t7, $t7, 2
/* 0046DC 70003ADC 01F87823 */  subu  $t7, $t7, $t8
/* 0046E0 70003AE0 3C188002 */  lui   $t8, %hi(ptr_video_settings2) 
/* 0046E4 70003AE4 8F1832A8 */  lw    $t8, %lo(ptr_video_settings2)($t8)
/* 0046E8 70003AE8 000F7AC0 */  sll   $t7, $t7, 0xb
/* 0046EC 70003AEC 01EEC821 */  addu  $t9, $t7, $t6
/* 0046F0 70003AF0 AF190028 */  sw    $t9, 0x28($t8)
/* 0046F4 70003AF4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0046F8 70003AF8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0046FC 70003AFC 03E00008 */  jr    $ra
/* 004700 70003B00 00000000 */   nop   
)
#endif

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
        pPlayer->viewports[g_viVideoSettings2FrameBufferIndex].vp.vscale[0] = (ptr_video_settings2->viewx * 2);
        pPlayer->viewports[g_viVideoSettings2FrameBufferIndex].vp.vtrans[0] = (ptr_video_settings2->viewx * 2) + (ptr_video_settings2->viewleft * 4);
        pPlayer->viewports[g_viVideoSettings2FrameBufferIndex].vp.vscale[1] = (ptr_video_settings2->viewy * 2);
        pPlayer->viewports[g_viVideoSettings2FrameBufferIndex].vp.vtrans[1] = (ptr_video_settings2->viewy * 2) + (ptr_video_settings2->viewtop * 4);
    }

    gSPViewport(gdl++, OS_K0_TO_PHYSICAL(&pPlayer->viewports[g_viVideoSettings2FrameBufferIndex]));
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

void viSetHorizontalOffset(s32 arg0)
{
    g_viHorizontalOffset = arg0;
}

s32 viGetHorizontalOffset(void)
{
    return g_viHorizontalOffset;
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
        if (indycommHostCheckFileExists((u8*)&buffer, &filesize) == 0)
        {
            break;
        }

        *pgrabnum = *pgrabnum + 1;
    }
    
    sprintf(buffer, "grab.%d.temp.uix", *pgrabnum);
    indycommHostSendDump((u8*)&buffer, (u8*)ptr_video_settings2->framebuf, (viGetX() * viGetY() * 2));

    sprintf(buffer, "uix2pix grab.%d.temp.uix", *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.temp.rgb", *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg", *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "rm grab.%d.temp.uix grab.%d.temp.pix grab.%d.temp.rgb", *pgrabnum, *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "imgview grab.%d.jpeg", *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);
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
        if (indycommHostCheckFileExists((u8*)&buffer, &filesize) == 0)
        {
            break;
        }

        *pgrabnum = *pgrabnum + 1;
    }
    
    sprintf(buffer, "grab.%d.temp.Uix", *pgrabnum);
    indycommHostSendDump((u8*)&buffer, (u8*)&cfb_16, (viGetX() * viGetY() * 4));

    sprintf(buffer, "Uix2pix -xs%d grab.%d.temp.Uix", viGetX(), *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.temp.rgb", *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg", *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "rm grab.%d.temp.Uix grab.%d.temp.pix grab.%d.temp.rgb", *pgrabnum, *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "imgview grab.%d.jpeg", *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);
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
        if (indycommHostCheckFileExists((u8*)&buffer, &filesize) == 0)
        {
            break;
        }

        *pgrabnum = *pgrabnum + 1;
    }
    
    sprintf(buffer, "grab.%d.temp.uix", *pgrabnum);
    indycommHostSendDump((u8*)&buffer, (u8*)ptr_video_settings2->framebuf, (viGetX() * viGetY() * 2));

    sprintf(buffer, "uix2pix grab.%d.temp.uix", *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.rgb", *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "rm grab.%d.temp.uix grab.%d.temp.pix", *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "imgview grab.%d.rgb", *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);
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
        if (indycommHostCheckFileExists((u8*)&buffer, &filesize) == 0)
        {
            break;
        }

        *pgrabnum = *pgrabnum + 1;
    }
    
    sprintf(buffer, "grab.%d.temp.Uix", *pgrabnum);
    indycommHostSendDump((u8*)&buffer, (u8*)&cfb_16, (viGetX() * viGetY() * 4));

    sprintf(buffer, "Uix2pix -xs%d grab.%d.temp.Uix", viGetX(), *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "fromalias grab.%d.temp.pix grab.%d.rgb", *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "rm grab.%d.temp.Uix grab.%d.temp.pix", *pgrabnum, *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);

    sprintf(buffer, "imgview grab.%d.rgb", *pgrabnum);
    indycommHostSendCmd((u8*)&buffer);
}