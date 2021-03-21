#ifndef _ULTRA64_VI_H_
#define _ULTRA64_VI_H_

#include <PR/ultratypes.h>
#include <PR/os_message.h>

/* Ultra64 Video Interface */

/*
 * Values for osTvType 
 */
#define    OS_TV_PAL        0
#define    OS_TV_NTSC        1
#define    OS_TV_MPAL        2

/*
 * Video Interface (VI) special features
 */
#define OS_VI_GAMMA_ON 0x0001
#define OS_VI_GAMMA_OFF 0x0002
#define OS_VI_GAMMA_DITHER_ON 0x0004
#define OS_VI_GAMMA_DITHER_OFF 0x0008
#define OS_VI_DIVOT_ON 0x0010
#define OS_VI_DIVOT_OFF 0x0020
#define OS_VI_DITHER_FILTER_ON 0x0040
#define OS_VI_DITHER_FILTER_OFF 0x0080

/*
 * Video Interface (VI) mode attribute bit
 */
#define OS_VI_BIT_NONINTERLACE        0x0001          /* lo-res */
#define OS_VI_BIT_INTERLACE        0x0002          /* lo-res */
#define OS_VI_BIT_NORMALINTERLACE    0x0004          /* hi-res */
#define OS_VI_BIT_DEFLICKINTERLACE    0x0008          /* hi-res */
#define OS_VI_BIT_ANTIALIAS        0x0010
#define OS_VI_BIT_POINTSAMPLE        0x0020
#define OS_VI_BIT_16PIXEL        0x0040
#define OS_VI_BIT_32PIXEL        0x0080
#define OS_VI_BIT_LORES            0x0100
#define OS_VI_BIT_HIRES            0x0200
#define OS_VI_BIT_NTSC            0x0400
#define OS_VI_BIT_PAL            0x0800



/**
 * The VI is responsible for displaying the RDP-rendered images in different video modes. Currently,
 * VI supports 42 video display modes -- 14 for NTSC, 14 for PAL, and 14 for MPAL. Each mode contains
 * different settings to handle attributes such as interlaced and non- interlaced, 16-bit and 32-bit
 * color pixel, and low and high resolution. Furthermore, a mode can be configured to rescale the
 * image to sacrifice resolution for rendering speed.
 * 
 * These supported modes can be represented by 5 switches:
 * 
 *      high/low resolution
 *      16-/32-bit color pixel
 *      anti-aliased/point-sampled
 *      filtered/not filtered
 *      NTSC/PAL/MPAL format
 * 
 * There are symbolic names defined for these modes in <os.h>. For example, uhOpenGame represents
 * an NTSC mode that supports low resolution, point sampled, non- interlaced, and 16-bit color
 * pixel. Similarly, OS_VI_PAL_LPN1 refers to the same mode but in PAL format. The last
 * four-character block (LPN1) in the symbol name is constructed by using the following codes for
 * each character position:
 * 
 *      1st position is H for high resolution or L for low resolution
 *      2nd position is A for anti-aliasing or P for point-sampled
 *      3rd position for:
 *          Low resolution is N for non-interlace or F for interlace
 *          High resolution is N for normal-interlace F deflickered interlace
 *      4th position is 1 for 16-bit pixel size or 2 for 32-bit pixel size
 * 
 * When you apply these codes, the following 14 modes are supported for NTSC as well as for
 * PAL and MPAL for a total of 42 modes:
 * 
 *      LPN1   HPN1
 *      LPF1   HPF1
 *      LAN1   HAN1
 *      LAF1   HAF1
 *      LPN2   HPN2
 *      LPF2   HPF2
 *      LAN2   LAF2
 * 
 * In low resolution (320 pixels by 240 lines), you have a choice between non-interlaced and
 * interlaced mode. Non-interlaced mode repeats the same frame each field. Interlaced mode
 * interpolates between adjacent lines, weighting 75% of the line above plus 25% of the line
 * below in the first field, and then weighting 25% of the line above plus 75% of the line
 * below in the second field. Note that there is no flicker because there are no high spatial
 * frequencies.
 * 
 * In high resolution (640 pixels by 480 lines), you have a choice between normal interlace
 * and deflickered interlace. Normal interlace uses just the data rendered in one field to
 * display that field. This mode can use one high resolution frame buffer without additional
 * double buffering because one field can be displayed while the next is being rendered without
 * stepping on each other. However, any single pixel with high detail will flicker because it
 * is only displayed in one field. Deflickered interlace averages adjacent lines to filter out
 * the high frequency vertical detail, but at the cost of requiring double buffering of the
 * entire high resolution frame because both rendered fields are used to display each field. 
 * 
 * source: /Functions Reference Manual/os/osVi.html
 */

//////////////////////////////////////////////////////////////////////////////////////////
// NTSC

/**
 * NTSC, low resolution, point-sampled, not filtered, 16 bit pixels
 */
#define OS_VI_NTSC_LPN1		0	

/**
 * NTSC, low resolution, point-sampled, filtered, 16 bit pixels
 */
#define OS_VI_NTSC_LPF1		1

/**
 * NTSC, low resolution, anti-aliased, not filtered, 16 bit pixels
 */
#define OS_VI_NTSC_LAN1		2

/**
 * NTSC, low resolution, anti-aliased, filtered, 16 bit pixels
 */
#define OS_VI_NTSC_LAF1		3

/**
 * NTSC, low resolution, point-sampled, not filtered, 32 bit pixels
 */
#define OS_VI_NTSC_LPN2		4

/**
 * NTSC, low resolution, point-sampled, filtered, 32 bit pixels
 */
#define OS_VI_NTSC_LPF2		5

/**
 * NTSC, low resolution, anti-aliased, not filtered, 32 bit pixels
 */
#define OS_VI_NTSC_LAN2		6

/**
 * NTSC, low resolution, anti-aliased, filtered, 32 bit pixels
 */
#define OS_VI_NTSC_LAF2		7

/**
 * NTSC, high resolution, point-sampled, not filtered, 16 bit pixels
 */
#define OS_VI_NTSC_HPN1		8

/**
 * NTSC, high resolution, point-sampled, filtered, 16 bit pixels
 */
#define OS_VI_NTSC_HPF1		9

/**
 * NTSC, high resolution, anti-aliased, not filtered, 16 bit pixels
 */
#define OS_VI_NTSC_HAN1		10

/**
 * NTSC, high resolution, anti-aliased, filtered, 16 bit pixels
 */
#define OS_VI_NTSC_HAF1		11

/**
 * NTSC, high resolution, point-sampled, not filtered, 32 bit pixels
 */
#define OS_VI_NTSC_HPN2		12

/**
 * NTSC, high resolution, point-sampled, filtered, 32 bit pixels
 */
#define OS_VI_NTSC_HPF2		13

//////////////////////////////////////////////////////////////////////////////////////////
// PAL

/**
 * PAL, low resolution, point-sampled, not filtered, 16 bit pixels
 */
#define OS_VI_PAL_LPN1		14

/**
 * PAL, low resolution, point-sampled, filtered, 16 bit pixels
 */
#define OS_VI_PAL_LPF1		15

/**
 * PAL, low resolution, anti-aliased, not filtered, 16 bit pixels
 */
#define OS_VI_PAL_LAN1		16

/**
 * PAL, low resolution, anti-aliased, filtered, 16 bit pixels
 */
#define OS_VI_PAL_LAF1		17

/**
 * PAL, low resolution, point-sampled, not filtered, 32 bit pixels
 */
#define OS_VI_PAL_LPN2		18

/**
 * PAL, low resolution, point-sampled, filtered, 32 bit pixels
 */
#define OS_VI_PAL_LPF2		19

/**
 * PAL, low resolution, anti-aliased, not filtered, 32 bit pixels
 */
#define OS_VI_PAL_LAN2		20

/**
 * PAL, low resolution, anti-aliased, filtered, 32 bit pixels
 */
#define OS_VI_PAL_LAF2		21

/**
 * PAL, high resolution, point-sampled, not filtered, 16 bit pixels
 */
#define OS_VI_PAL_HPN1		22

/**
 * PAL, high resolution, point-sampled, filtered, 16 bit pixels
 */
#define OS_VI_PAL_HPF1		23

/**
 * PAL, high resolution, anti-aliased, not filtered, 16 bit pixels
 */
#define OS_VI_PAL_HAN1		24

/**
 * PAL, high resolution, anti-aliased, filtered, 16 bit pixels
 */
#define OS_VI_PAL_HAF1		25

/**
 * PAL, high resolution, point-sampled, not filtered, 32 bit pixels
 */
#define OS_VI_PAL_HPN2		26

/**
 * PAL, high resolution, point-sampled, filtered, 32 bit pixels
 */
#define OS_VI_PAL_HPF2		27

//////////////////////////////////////////////////////////////////////////////////////////
// MPAL

/**
 * MPAL, low resolution, point-sampled, not filtered, 16 bit pixels
 */
#define OS_VI_MPAL_LPN1     28

/**
 * MPAL, low resolution, point-sampled, filtered, 16 bit pixels
 */
#define OS_VI_MPAL_LPF1     29

/**
 * MPAL, low resolution, anti-aliased, not filtered, 16 bit pixels
 */
#define OS_VI_MPAL_LAN1     30

/**
 * MPAL, low resolution, anti-aliased, filtered, 16 bit pixels
 */
#define OS_VI_MPAL_LAF1     31

/**
 * MPAL, low resolution, point-sampled, not filtered, 32 bit pixels
 */
#define OS_VI_MPAL_LPN2     32

/**
 * MPAL, low resolution, point-sampled, filtered, 32 bit pixels
 */
#define OS_VI_MPAL_LPF2     33

/**
 * MPAL, low resolution, anti-aliased, not filtered, 32 bit pixels
 */
#define OS_VI_MPAL_LAN2     34

/**
 * MPAL, low resolution, anti-aliased, filtered, 32 bit pixels
 */
#define OS_VI_MPAL_LAF2     35

/**
 * MPAL, high resolution, point-sampled, not filtered, 16 bit pixels
 */
#define OS_VI_MPAL_HPN1     36

/**
 * MPAL, high resolution, point-sampled, filtered, 16 bit pixels
 */
#define OS_VI_MPAL_HPF1     37

/**
 * MPAL, high resolution, anti-aliased, not filtered, 16 bit pixels
 */
#define OS_VI_MPAL_HAN1     38

/**
 * MPAL, high resolution, anti-aliased, filtered, 16 bit pixels
 */
#define OS_VI_MPAL_HAF1     39

/**
 * MPAL, high resolution, point-sampled, not filtered, 32 bit pixels
 */
#define OS_VI_MPAL_HPN2     40

/**
 * MPAL, high resolution, point-sampled, filtered, 32 bit pixels
 */
#define OS_VI_MPAL_HPF2     41


/* Types */

typedef struct
{
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;

typedef struct
{
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;

typedef struct
{
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;

typedef struct
{
    /* 0x00 */ u16 unk00; //some kind of flags.  swap buffer sets to 0x10
    /* 0x02 */ u16 retraceCount;
    /* 0x04 */ void* buffer;
    /* 0x08 */ OSViMode *modep;
    /* 0x0c */ u32 features;
    /* 0x10 */ OSMesgQueue *mq;
    /* 0x14 */ OSMesg *msg;
    /* 0x18 */ u32 unk18;
    /* 0x1c */ u32 unk1c;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u16 unk28;
    /* 0x2c */ u32 unk2c;
} OSViContext;

/**************************************************************************
 *
 * Extern variables
 *
 */
extern OSViMode    osViModeTable[];    /* Global VI mode table */

extern OSViMode    osViModeNtscLpn1;    /* Individual VI NTSC modes */
extern OSViMode    osViModeNtscLpf1;
extern OSViMode    osViModeNtscLan1;
extern OSViMode    osViModeNtscLaf1;
extern OSViMode    osViModeNtscLpn2;
extern OSViMode    osViModeNtscLpf2;
extern OSViMode    osViModeNtscLan2;
extern OSViMode    osViModeNtscLaf2;
extern OSViMode    osViModeNtscHpn1;
extern OSViMode    osViModeNtscHpf1;
extern OSViMode    osViModeNtscHan1;
extern OSViMode    osViModeNtscHaf1;
extern OSViMode    osViModeNtscHpn2;
extern OSViMode    osViModeNtscHpf2;

extern OSViMode    osViModePalLpn1;    /* Individual VI PAL modes */
extern OSViMode    osViModePalLpf1;
extern OSViMode    osViModePalLan1;
extern OSViMode    osViModePalLaf1;
extern OSViMode    osViModePalLpn2;
extern OSViMode    osViModePalLpf2;
extern OSViMode    osViModePalLan2;
extern OSViMode    osViModePalLaf2;
extern OSViMode    osViModePalHpn1;
extern OSViMode    osViModePalHpf1;
extern OSViMode    osViModePalHan1;
extern OSViMode    osViModePalHaf1;
extern OSViMode    osViModePalHpn2;
extern OSViMode    osViModePalHpf2;

extern OSViMode    osViModeMpalLpn1;    /* Individual VI MPAL modes */
extern OSViMode    osViModeMpalLpf1;
extern OSViMode    osViModeMpalLan1;
extern OSViMode    osViModeMpalLaf1;
extern OSViMode    osViModeMpalLpn2;
extern OSViMode    osViModeMpalLpf2;
extern OSViMode    osViModeMpalLan2;
extern OSViMode    osViModeMpalLaf2;
extern OSViMode    osViModeMpalHpn1;
extern OSViMode    osViModeMpalHpf1;
extern OSViMode    osViModeMpalHan1;
extern OSViMode    osViModeMpalHaf1;
extern OSViMode    osViModeMpalHpn2;
extern OSViMode    osViModeMpalHpf2;

/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Video interface (Vi) */
u32 osViGetStatus(void);
u32 osViGetCurrentMode(void);
u32 osViGetCurrentLine(void);
u32 osViGetCurrentField(void);
void *osViGetCurrentFramebuffer(void);
void *osViGetNextFramebuffer(void);
void osViSetXScale(f32);
void osViSetYScale(f32);
void osViSetSpecialFeatures(u32 func);
void osViSetMode(OSViMode *mode);
void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount);
void osViSwapBuffer(void *vaddr);
void osViBlack(u8 active);
void osViFade(u8, u16);
void osViRepeatLine(u8);
void osCreateViManager(OSPri);
#endif
