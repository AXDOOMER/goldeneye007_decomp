//FIXME i still need data/bss love.
#include "ultra64.h"
#include "sched.h"
#include "audi.h"

/**
 * @file audi.c
 * This file contains audio code. Starts main audio thread, handles some audio DMA.
 */

#define NUMBER_OUTPUT_BUFFERS               3
#define NUMBER_ACMD_LISTS                   2
#define NUMBER_DMA_BUFFERS                 64
#define EXTRA_SAMPLES                    0x25
#define AUDIO_FRAME_MESSAGE_QUEUE_SIZE      8
#define AUDIO_REPLY_MESSAGE_QUEUE_SIZE      8

#define MAIN_QUIT_MESSAGE   10
#define AUDIO_MANAGER_COUNT_INTERVAL    0xf0

extern long long int rspbootTextStart[];
extern long long int gsp3DTextStart[];
extern long long int aspMainTextStart[];
extern long long int aspMainDataStart[];

/**
 * Copied from the n64devkit audio examples.
 * sizeof(struct _DMABuffer) == 0x14 (20)
 */
typedef struct _DMABuffer {
    /**
     * 0x0.
     */
    ALLink node;

    /**
     * 0x8.
     */
    int startAddr;

    /**
     * 0xc.
     */
    u32 lastFrame;

    /**
     * 0x10.
     */
    char* ptr;
} DMABuffer;

/**
 * Copied from the n64devkit audio examples.
 * sizeof(struct _DMAState) == 0xc (12).
 */
typedef struct _DMAState {
    /**
     * This was defined (in the devkit) as u8 (and code expects a byte), but the size 
     * of the struct and offset for firstUsed seems to make this u32/s32.
     * I'm adding the union to make this explicit.
     * 0x0.
     */
    union {
        u8 initialized;
        s32 _unusedAlign;
    } u;

    /**
     * 0x4.
     */
    DMABuffer *firstUsed;

    /**
     * 0x8.
     */
    DMABuffer *firstFree;
} DMAState;

typedef union AudioMessage_u {
    struct {
        s16 type;
    } gen;
    
    struct {
        s16 type;
        struct AudioInfo_s *info;
    } done;
    
    OSScMsg app;
} AudioMessage;

/**
* Modified from n64devkit example.
* sizeof(struct _DMAState) == 0xc (12).
*/
typedef struct AudioInfo_s {
    /**
    * Output data pointer.
    * 0x0.
    */
    s16 *data;

    /**
     * # of samples synthesized in this frame
     * 0x4.
     */
    s16 frameSamples;

    /**
     * scheduler structure
     * 0x8
     */
    OSScTask task;
} AudioInfo;

u32 D_800230F0 = 0;

u32 audioFrameCount = 0;

u32 nextDMA = 0;

u32 currentAcmdList = 0;

u64 D_80023100[]= {
 {0x000600001900},
 {0x0000000000A0},
 {0x2666FFFFD99A},
 {0x000000000000},
 {0x000000000000},
 {0x00A000000140},
 {0x2666FFFFD99A},
 {0x2B8400000000},
 {0x000000002500},
 {0x032000000A00},
 {0x4000FFFFC000},
 {0x11EB00000000},
 {0x000000003000},
 {0x0C80000015E0},
 {0x4000FFFFC000},
 {0x11EB00000000},
 {0x000000003500},
 {0x0D20000012C0},
 {0x2000FFFFE000},
 {0x000000000000},
 {0x000000004000},
 {0x000000001720},
 {0x32C8FFFFCD38},
 {0x00000000017C},
 {0x000A00004500},
};

s32 firstTime = 1;


/*bss needs fixing */
s32 dword_CODE_bss_8005E4B0[2];


/**
 * Address 8005E4B8.
 * (type is u64)
 * Used in audio_manager_main.
 * This looks like it stores the largest sDeltaTime between
 * counts of AUDIO_MANAGER_COUNT_INTERVAL.
 */
OSTime largestDeltaTime;

/**
 * Address 8005E4C0.
 * (type is u64)
 * Used in audio_manager_main.
 * Stores the elpased time of main loop (difference between sEndTime and sStartTime).
 */
#ifdef NONMATCHING
OSTime deltaTime;
#else
s32 dword_CODE_bss_8005E4C0;
s32 dword_CODE_bss_8005E4C4;
#endif

/**
 * Address 8005E4C8.
 * Every AUDIO_MANAGER_COUNT_INTERVAL number of events, the average for sDeltaTimeSum
 * is computed and stored here.
 */
#ifdef NONMATCHING
u64 deltaAverage;
#else
s32 dword_CODE_bss_8005E4C8;
s32 dword_CODE_bss_8005E4CC;
#endif

/**
 * Address 8005E4D0.
 * Tracks the sum total elapsed time. Reset every AUDIO_MANAGER_COUNT_INTERVAL.
 */
u64 deltaTimeSum;

/**
 * Address 8005E4D8.
 * (type is u64)
 * Used in audio_manager_main.
 * Stores the time at the start of the loop.
 */
OSTime startTime;

/**
 * Address 8005E4E0.
 * (type is u64)
 * Used in audio_manager_main.
 * Stores the time after primary processing is done.
 */
OSTime endTime;

/**
 * bss needs fixing
 */
char dword_CODE_bss_8005E4E8[0x30];

/**
 * Address 8005e518.
 */
struct _AudioManager {

    /**
     * 4
     */
    Acmd *cmdList[NUMBER_ACMD_LISTS];
    
    /**
     * 0
     */
    AudioInfo *audioInfo[NUMBER_OUTPUT_BUFFERS];
    
    /**
    * 8
    */
    u32 numberOutputBuffers;
    
    /**
     * 0xc
     */
    OSThread audioThread;
    
    /**
     * 0x1c8.
     */
    OSMesgQueue frameMessageQueue;
    
    /**
     * 0x1e0.
     */
    OSMesg frameMessageBuffer[AUDIO_FRAME_MESSAGE_QUEUE_SIZE - 1];
    

    u32 numberAcmdLists;

    /**
     * 0x200.
     */
    OSMesgQueue replyMessageQueue;

    

    /**
     * 0x218.
     */
    OSMesg replyMessageBuffer[AUDIO_REPLY_MESSAGE_QUEUE_SIZE - 1];

    s32 pad1;

    /**
     * 0x
     */
    DMABuffer dmaBuffer;
    
    s32 pad[15];
    
    

} AudioManager;






//8005e7a0
OSScClient audioClient[2];

/**
 * Address 0x8005e7b0.
 */
DMAState dmaState;

DMABuffer dmaBuffers[NUMBER_DMA_BUFFERS];

s32 minFrameSize;
s32 frameSize;
s32 maxFrameSize;
s32 commandLength;

OSIoMesg audDMAIOMesgBuf[0x40];
OSMesgQueue audDMAMessageQ;
char audDMAMessageBuf[0x108];

// Forward declarations
s32 dmaCallBack(s32 addr, s32 len, void* state);
void clear_audio_dma(void);
void audio_manager_handle_frame_message(AudioInfo *info, AudioInfo *lastInfo);
void audio_manager_handle_done_message(AudioInfo *info);

/**
 * 29D0	70001BD0
 */
#ifdef NONMATCHING
void amCreateAudioMgr(void *arg0)
{
    ? sp48;
    f32 temp_f0;
    s32 temp_ret;
    s32 temp_s2;
    u32 temp_s0;
    u32 temp_t0;
    u32 temp_t9;
    u32 temp_v1;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_t0_2;
    void *temp_t7;
    u32 phi_v1;
    u32 phi_v1_2;
    void *phi_t7;
    void *phi_t0;
    void *phi_s0;
    s32 phi_s0_2;
    void *phi_s1;
    s32 phi_s2;
    void *phi_s0_3;

    arg0->unk10 = &audio_manager_dma_new;
    temp_ret = osAiSetFrequency(0x5622);
    arg0->unk18 = temp_ret;
    temp_f0 = (f32) (temp_ret * 2) / 60.0f;
    temp_t9 = (u32) temp_f0;
    frameSize = temp_t9;
    temp_t0 = temp_t9 + 1;
    phi_v1 = temp_t9;
    if ((f32) temp_t9 < temp_f0)
    {
        frameSize = temp_t0;
        phi_v1 = temp_t0;
    }
    phi_v1_2 = phi_v1;
    if ((phi_v1 & 0xf) != 0)
    {
        temp_v1 = (phi_v1 & -0x10) + 0x10;
        frameSize = temp_v1;
        phi_v1_2 = temp_v1;
    }
    minFrameSize = (s32) (phi_v1_2 + -0x10);
    maxFrameSize = (s32) (phi_v1_2 + 0x35);
    if (arg0->unk1C == 6)
    {
        phi_t7 = &D_80023100;
        phi_t0 = &sp48;
loop_6:
        temp_t7 = phi_t7 + 0xc;
        temp_t0_2 = phi_t0 + 0xc;
        temp_t0_2->unk-C = (?32) *phi_t7;
        temp_t0_2->unk-8 = (?32) temp_t7->unk-8;
        temp_t0_2->unk-4 = (?32) temp_t7->unk-4;
        phi_t7 = temp_t7;
        phi_t0 = temp_t0_2;
        if (temp_t7 != (&D_80023100 + 0xc0))
        {
            goto loop_6;
        }
        temp_t0_2->unk0 = (?32) temp_t7->unk0;
        temp_t0_2->unk4 = (?32) temp_t7->unk4;
        arg0->unk20 = &sp48;
        alInit(&AudioManager+0x238, arg0);
    }
    else
    {
        alInit(&AudioManager+0x238, arg0);
    }
    phi_s0 = &AudioManager;
loop_10:
    phi_s0->unk8 = alHeapDBAlloc(0, 0, arg0->unk14, 1, 0x60);
    temp_s0 = phi_s0 + 4;
    *phi_s0->unk8 = alHeapDBAlloc(0, 0, arg0->unk14, 1, (s32) (maxFrameSize * 4));
    phi_s0 = temp_s0;
    if (temp_s0 < &AudioManager+0xC)
    {
        goto loop_10;
    }
    osCreateMesgQueue(&AudioManager+0x200, &AudioManager+0x218, 8);
    osCreateMesgQueue(&AudioManager+0x1C8, &AudioManager+0x1E0, 8);
    osCreateMesgQueue(&audDMAMessageQ, &audDMAMessageBuf, 0x40);
    dmaBuffers.unk4 = 0;
    dmaBuffers.unk0 = 0;
    phi_s0_2 = dmaBuffers + 0xe;
    phi_s1 = &dmaBuffers;
    phi_s2 = 0;
loop_12:
    alLink(phi_s0_2, phi_s1);
    temp_s2 = phi_s2 + 1;
    temp_s1 = phi_s1 + 0x14;
    temp_s1->unk-4 = alHeapDBAlloc(0, 0, arg0->unk14, 1, 0x200);
    phi_s0_2 = phi_s0_2 + 0x14;
    phi_s1 = temp_s1;
    phi_s2 = temp_s2;
    if (temp_s2 < 0x3f)
    {
        goto loop_12;
    }
    temp_s1->unk10 = alHeapDBAlloc(0, 0, arg0->unk14, 1, 0x200);
    phi_s0_3 = &AudioManager;
loop_14:
    temp_s0_2 = phi_s0_3 + 4;
    temp_s0_2->unk-4 = alHeapDBAlloc(0, 0, arg0->unk14, 1, 0x5dc0);
    phi_s0_3 = temp_s0_2;
    if (temp_s0_2 != &AudioManager+0x8)
    {
        goto loop_14;
    }
    osCreateThread(&AudioManager+0x18, 4, &audio_manager_main, 0, set_stack_entry(&sp_audi, 0x1000), 0x14);
}
#else
GLOBAL_ASM(
.text
glabel amCreateAudioMgr
/* 0027D0 70001BD0 27BDFEE8 */  addiu $sp, $sp, -0x118
/* 0027D4 70001BD4 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0027D8 70001BD8 3C0E7000 */  lui   $t6, %hi(audio_manager_dma_new) # $t6, 0x7000
/* 0027DC 70001BDC AFBF0034 */  sw    $ra, 0x34($sp)
/* 0027E0 70001BE0 AFB40030 */  sw    $s4, 0x30($sp)
/* 0027E4 70001BE4 AFB20028 */  sw    $s2, 0x28($sp)
/* 0027E8 70001BE8 AFB10024 */  sw    $s1, 0x24($sp)
/* 0027EC 70001BEC AFB00020 */  sw    $s0, 0x20($sp)
/* 0027F0 70001BF0 25CE25D8 */  addiu $t6, %lo(audio_manager_dma_new) # addiu $t6, $t6, 0x25d8
/* 0027F4 70001BF4 00809825 */  move  $s3, $a0
/* 0027F8 70001BF8 AC8E0010 */  sw    $t6, 0x10($a0)
/* 0027FC 70001BFC 0C003A4C */  jal   osAiSetFrequency
/* 002800 70001C00 24045622 */   li    $a0, 22050
/* 002804 70001C04 00027840 */  sll   $t7, $v0, 1
/* 002808 70001C08 448F2000 */  mtc1  $t7, $f4
/* 00280C 70001C0C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 002810 70001C10 44814000 */  mtc1  $at, $f8
/* 002814 70001C14 468021A0 */  cvt.s.w $f6, $f4
/* 002818 70001C18 24190001 */  li    $t9, 1
/* 00281C 70001C1C 3C048006 */  lui   $a0, %hi(frameSize)
/* 002820 70001C20 3C148006 */  lui   $s4, %hi(maxFrameSize)
/* 002824 70001C24 2484ECC4 */  addiu $a0, %lo(frameSize) # addiu $a0, $a0, -0x133c
/* 002828 70001C28 AE620018 */  sw    $v0, 0x18($s3)
/* 00282C 70001C2C 46083003 */  div.s $f0, $f6, $f8
/* 002830 70001C30 2694ECC8 */  addiu $s4, %lo(maxFrameSize) # addiu $s4, $s4, -0x1338
/* 002834 70001C34 4458F800 */  cfc1  $t8, $31
/* 002838 70001C38 44D9F800 */  ctc1  $t9, $31
/* 00283C 70001C3C 00000000 */  nop   
/* 002840 70001C40 460002A4 */  cvt.w.s $f10, $f0
/* 002844 70001C44 4459F800 */  cfc1  $t9, $31
/* 002848 70001C48 00000000 */  nop   
/* 00284C 70001C4C 33390078 */  andi  $t9, $t9, 0x78
/* 002850 70001C50 13200012 */  beqz  $t9, .L70001C9C
/* 002854 70001C54 3C014F00 */   li    $at, 0x4F000000 # 2147483648.000000
/* 002858 70001C58 44815000 */  mtc1  $at, $f10
/* 00285C 70001C5C 24190001 */  li    $t9, 1
/* 002860 70001C60 460A0281 */  sub.s $f10, $f0, $f10
/* 002864 70001C64 44D9F800 */  ctc1  $t9, $31
/* 002868 70001C68 00000000 */  nop   
/* 00286C 70001C6C 460052A4 */  cvt.w.s $f10, $f10
/* 002870 70001C70 4459F800 */  cfc1  $t9, $31
/* 002874 70001C74 00000000 */  nop   
/* 002878 70001C78 33390078 */  andi  $t9, $t9, 0x78
/* 00287C 70001C7C 17200005 */  bnez  $t9, .L70001C94
/* 002880 70001C80 00000000 */   nop   
/* 002884 70001C84 44195000 */  mfc1  $t9, $f10
/* 002888 70001C88 3C018000 */  lui   $at, 0x8000
/* 00288C 70001C8C 10000007 */  b     .L70001CAC
/* 002890 70001C90 0321C825 */   or    $t9, $t9, $at
.L70001C94:
/* 002894 70001C94 10000005 */  b     .L70001CAC
/* 002898 70001C98 2419FFFF */   li    $t9, -1
.L70001C9C:
/* 00289C 70001C9C 44195000 */  mfc1  $t9, $f10
/* 0028A0 70001CA0 00000000 */  nop   
/* 0028A4 70001CA4 0720FFFB */  bltz  $t9, .L70001C94
/* 0028A8 70001CA8 00000000 */   nop   
.L70001CAC:
/* 0028AC 70001CAC 03201825 */  move  $v1, $t9
/* 0028B0 70001CB0 44D8F800 */  ctc1  $t8, $31
/* 0028B4 70001CB4 44838000 */  mtc1  $v1, $f16
/* 0028B8 70001CB8 AC990000 */  sw    $t9, ($a0)
/* 0028BC 70001CBC 07210005 */  bgez  $t9, .L70001CD4
/* 0028C0 70001CC0 468084A0 */   cvt.s.w $f18, $f16
/* 0028C4 70001CC4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0028C8 70001CC8 44812000 */  mtc1  $at, $f4
/* 0028CC 70001CCC 00000000 */  nop   
/* 0028D0 70001CD0 46049480 */  add.s $f18, $f18, $f4
.L70001CD4:
/* 0028D4 70001CD4 4600903C */  c.lt.s $f18, $f0
/* 0028D8 70001CD8 00000000 */  nop   
/* 0028DC 70001CDC 45000003 */  bc1f  .L70001CEC
/* 0028E0 70001CE0 24680001 */   addiu $t0, $v1, 1
/* 0028E4 70001CE4 AC880000 */  sw    $t0, ($a0)
/* 0028E8 70001CE8 01001825 */  move  $v1, $t0
.L70001CEC:
/* 0028EC 70001CEC 3069000F */  andi  $t1, $v1, 0xf
/* 0028F0 70001CF0 11200004 */  beqz  $t1, .L70001D04
/* 0028F4 70001CF4 2401FFF0 */   li    $at, -16
/* 0028F8 70001CF8 00615024 */  and   $t2, $v1, $at
/* 0028FC 70001CFC 25430010 */  addiu $v1, $t2, 0x10
/* 002900 70001D00 AC830000 */  sw    $v1, ($a0)
.L70001D04:
/* 002904 70001D04 246CFFF0 */  addiu $t4, $v1, -0x10
/* 002908 70001D08 3C018006 */  lui   $at, %hi(minFrameSize)
/* 00290C 70001D0C AC2CECC0 */  sw    $t4, %lo(minFrameSize)($at)
/* 002910 70001D10 246D0035 */  addiu $t5, $v1, 0x35
/* 002914 70001D14 AE8D0000 */  sw    $t5, ($s4)
/* 002918 70001D18 926E001C */  lbu   $t6, 0x1c($s3)
/* 00291C 70001D1C 24010006 */  li    $at, 6
/* 002920 70001D20 3C048006 */  lui   $a0, %hi(AudioManager+0x238)
/* 002924 70001D24 15C1001A */  bne   $t6, $at, .L70001D90
/* 002928 70001D28 2484E750 */   addiu $a0, %lo(AudioManager+0x238) # addiu $a0, $a0, -0x18b0
/* 00292C 70001D2C 3C0F8002 */  lui   $t7, %hi(D_80023100) 
/* 002930 70001D30 27A20048 */  addiu $v0, $sp, 0x48
/* 002934 70001D34 25EF3100 */  addiu $t7, %lo(D_80023100) # addiu $t7, $t7, 0x3100
/* 002938 70001D38 25F900C0 */  addiu $t9, $t7, 0xc0
/* 00293C 70001D3C 00404025 */  move  $t0, $v0
.L70001D40:
/* 002940 70001D40 8DE10000 */  lw    $at, ($t7)
/* 002944 70001D44 25EF000C */  addiu $t7, $t7, 0xc
/* 002948 70001D48 2508000C */  addiu $t0, $t0, 0xc
/* 00294C 70001D4C AD01FFF4 */  sw    $at, -0xc($t0)
/* 002950 70001D50 8DE1FFF8 */  lw    $at, -8($t7)
/* 002954 70001D54 AD01FFF8 */  sw    $at, -8($t0)
/* 002958 70001D58 8DE1FFFC */  lw    $at, -4($t7)
/* 00295C 70001D5C 15F9FFF8 */  bne   $t7, $t9, .L70001D40
/* 002960 70001D60 AD01FFFC */   sw    $at, -4($t0)
/* 002964 70001D64 8DE10000 */  lw    $at, ($t7)
/* 002968 70001D68 3C048006 */  lui   $a0, %hi(AudioManager+0x238)
/* 00296C 70001D6C 2484E750 */  addiu $a0, %lo(AudioManager+0x238) # addiu $a0, $a0, -0x18b0
/* 002970 70001D70 AD010000 */  sw    $at, ($t0)
/* 002974 70001D74 8DF90004 */  lw    $t9, 4($t7)
/* 002978 70001D78 02602825 */  move  $a1, $s3
/* 00297C 70001D7C AD190004 */  sw    $t9, 4($t0)
/* 002980 70001D80 0C003AC7 */  jal   alInit
/* 002984 70001D84 AE620020 */   sw    $v0, 0x20($s3)
/* 002988 70001D88 10000003 */  b     .L70001D98
/* 00298C 70001D8C 00000000 */   nop   
.L70001D90:
/* 002990 70001D90 0C003AC7 */  jal   alInit
/* 002994 70001D94 02602825 */   move  $a1, $s3
.L70001D98:
/* 002998 70001D98 3C108006 */  lui   $s0, %hi(AudioManager)
/* 00299C 70001D9C 3C118006 */  lui   $s1, %hi(AudioManager+0xC)
/* 0029A0 70001DA0 2631E524 */  addiu $s1, %lo(AudioManager+0xC) # addiu $s1, $s1, -0x1adc
/* 0029A4 70001DA4 2610E518 */  addiu $s0, %lo(AudioManager) # addiu $s0, $s0, -0x1ae8
.L70001DA8:
/* 0029A8 70001DA8 8E660014 */  lw    $a2, 0x14($s3)
/* 0029AC 70001DAC 24090060 */  li    $t1, 96
/* 0029B0 70001DB0 AFA90010 */  sw    $t1, 0x10($sp)
/* 0029B4 70001DB4 00002025 */  move  $a0, $zero
/* 0029B8 70001DB8 00002825 */  move  $a1, $zero
/* 0029BC 70001DBC 0C003AD4 */  jal   alHeapDBAlloc
/* 0029C0 70001DC0 24070001 */   li    $a3, 1
/* 0029C4 70001DC4 8E8A0000 */  lw    $t2, ($s4)
/* 0029C8 70001DC8 AE020008 */  sw    $v0, 8($s0)
/* 0029CC 70001DCC 8E660014 */  lw    $a2, 0x14($s3)
/* 0029D0 70001DD0 000A5880 */  sll   $t3, $t2, 2
/* 0029D4 70001DD4 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0029D8 70001DD8 00002025 */  move  $a0, $zero
/* 0029DC 70001DDC 00002825 */  move  $a1, $zero
/* 0029E0 70001DE0 0C003AD4 */  jal   alHeapDBAlloc
/* 0029E4 70001DE4 24070001 */   li    $a3, 1
/* 0029E8 70001DE8 8E0C0008 */  lw    $t4, 8($s0)
/* 0029EC 70001DEC 26100004 */  addiu $s0, $s0, 4
/* 0029F0 70001DF0 0211082B */  sltu  $at, $s0, $s1
/* 0029F4 70001DF4 1420FFEC */  bnez  $at, .L70001DA8
/* 0029F8 70001DF8 AD820000 */   sw    $v0, ($t4)
/* 0029FC 70001DFC 3C048006 */  lui   $a0, %hi(AudioManager+0x200)
/* 002A00 70001E00 3C058006 */  lui   $a1, %hi(AudioManager+0x218)
/* 002A04 70001E04 24A5E730 */  addiu $a1, %lo(AudioManager+0x218) # addiu $a1, $a1, -0x18d0
/* 002A08 70001E08 2484E718 */  addiu $a0, %lo(AudioManager+0x200) # addiu $a0, $a0, -0x18e8
/* 002A0C 70001E0C 0C0035B4 */  jal   osCreateMesgQueue
/* 002A10 70001E10 24060008 */   li    $a2, 8
/* 002A14 70001E14 3C048006 */  lui   $a0, %hi(AudioManager+0x1C8)
/* 002A18 70001E18 3C058006 */  lui   $a1, %hi(AudioManager+0x1E0)
/* 002A1C 70001E1C 24A5E6F8 */  addiu $a1, %lo(AudioManager+0x1E0) # addiu $a1, $a1, -0x1908
/* 002A20 70001E20 2484E6E0 */  addiu $a0, %lo(AudioManager+0x1C8) # addiu $a0, $a0, -0x1920
/* 002A24 70001E24 0C0035B4 */  jal   osCreateMesgQueue
/* 002A28 70001E28 24060008 */   li    $a2, 8
/* 002A2C 70001E2C 3C048006 */  lui   $a0, %hi(audDMAMessageQ)
/* 002A30 70001E30 3C058006 */  lui   $a1, %hi(audDMAMessageBuf)
/* 002A34 70001E34 24A5F2E8 */  addiu $a1, %lo(audDMAMessageBuf) # addiu $a1, $a1, -0xd18
/* 002A38 70001E38 2484F2D0 */  addiu $a0, %lo(audDMAMessageQ) # addiu $a0, $a0, -0xd30
/* 002A3C 70001E3C 0C0035B4 */  jal   osCreateMesgQueue
/* 002A40 70001E40 24060040 */   li    $a2, 64
/* 002A44 70001E44 3C028006 */  lui   $v0, %hi(dmaBuffers)
/* 002A48 70001E48 2442E7C0 */  addiu $v0, %lo(dmaBuffers) # addiu $v0, $v0, -0x1840
/* 002A4C 70001E4C 3C118006 */  lui   $s1, %hi(dmaBuffers)
/* 002A50 70001E50 3C108006 */  lui   $s0, %hi(dmaBuffers+20)
/* 002A54 70001E54 AC400004 */  sw    $zero, 4($v0)
/* 002A58 70001E58 AC400000 */  sw    $zero, ($v0)
/* 002A5C 70001E5C 2610E7D4 */  addiu $s0, $s0, %lo(dmaBuffers+20)
/* 002A60 70001E60 2631E7C0 */  addiu $s1, %lo(dmaBuffers) # addiu $s1, $s1, -0x1840
/* 002A64 70001E64 00009025 */  move  $s2, $zero
.L70001E68:
/* 002A68 70001E68 02002025 */  move  $a0, $s0
/* 002A6C 70001E6C 0C003AB0 */  jal   alLink
/* 002A70 70001E70 02202825 */   move  $a1, $s1
/* 002A74 70001E74 8E660014 */  lw    $a2, 0x14($s3)
/* 002A78 70001E78 240D0200 */  li    $t5, 512
/* 002A7C 70001E7C AFAD0010 */  sw    $t5, 0x10($sp)
/* 002A80 70001E80 00002025 */  move  $a0, $zero
/* 002A84 70001E84 00002825 */  move  $a1, $zero
/* 002A88 70001E88 0C003AD4 */  jal   alHeapDBAlloc
/* 002A8C 70001E8C 24070001 */   li    $a3, 1
/* 002A90 70001E90 26520001 */  addiu $s2, $s2, 1
/* 002A94 70001E94 2A41003F */  slti  $at, $s2, 0x3f
/* 002A98 70001E98 26310014 */  addiu $s1, $s1, 0x14
/* 002A9C 70001E9C 26100014 */  addiu $s0, $s0, 0x14
/* 002AA0 70001EA0 1420FFF1 */  bnez  $at, .L70001E68
/* 002AA4 70001EA4 AE22FFFC */   sw    $v0, -4($s1)
/* 002AA8 70001EA8 8E660014 */  lw    $a2, 0x14($s3)
/* 002AAC 70001EAC 240E0200 */  li    $t6, 512
/* 002AB0 70001EB0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 002AB4 70001EB4 00002025 */  move  $a0, $zero
/* 002AB8 70001EB8 00002825 */  move  $a1, $zero
/* 002ABC 70001EBC 0C003AD4 */  jal   alHeapDBAlloc
/* 002AC0 70001EC0 24070001 */   li    $a3, 1
/* 002AC4 70001EC4 AE220010 */  sw    $v0, 0x10($s1)
/* 002AC8 70001EC8 3C118006 */  lui   $s1, %hi(AudioManager+0x8)
/* 002ACC 70001ECC 3C108006 */  lui   $s0, %hi(AudioManager)
/* 002AD0 70001ED0 2610E518 */  addiu $s0, %lo(AudioManager) # addiu $s0, $s0, -0x1ae8
/* 002AD4 70001ED4 2631E520 */  addiu $s1, %lo(AudioManager+0x8) # addiu $s1, $s1, -0x1ae0
.L70001ED8:
/* 002AD8 70001ED8 8E660014 */  lw    $a2, 0x14($s3)
/* 002ADC 70001EDC 24185DC0 */  li    $t8, 24000
/* 002AE0 70001EE0 AFB80010 */  sw    $t8, 0x10($sp)
/* 002AE4 70001EE4 00002025 */  move  $a0, $zero
/* 002AE8 70001EE8 00002825 */  move  $a1, $zero
/* 002AEC 70001EEC 0C003AD4 */  jal   alHeapDBAlloc
/* 002AF0 70001EF0 24070001 */   li    $a3, 1
/* 002AF4 70001EF4 26100004 */  addiu $s0, $s0, 4
/* 002AF8 70001EF8 1611FFF7 */  bne   $s0, $s1, .L70001ED8
/* 002AFC 70001EFC AE02FFFC */   sw    $v0, -4($s0)
/* 002B00 70001F00 3C04803B */  lui   $a0, %hi(sp_audi) # $a0, 0x803b
/* 002B04 70001F04 24843950 */  addiu $a0, %lo(sp_audi) # addiu $a0, $a0, 0x3950
/* 002B08 70001F08 0C0001BC */  jal   set_stack_entry
/* 002B0C 70001F0C 24051000 */   li    $a1, 4096
/* 002B10 70001F10 3C048006 */  lui   $a0, %hi(AudioManager+0x18)
/* 002B14 70001F14 3C067000 */  lui   $a2, %hi(audio_manager_main) # $a2, 0x7000
/* 002B18 70001F18 24190014 */  li    $t9, 20
/* 002B1C 70001F1C AFB90014 */  sw    $t9, 0x14($sp)
/* 002B20 70001F20 24C61F7C */  addiu $a2, %lo(audio_manager_main) # addiu $a2, $a2, 0x1f7c
/* 002B24 70001F24 2484E530 */  addiu $a0, %lo(AudioManager+0x18) # addiu $a0, $a0, -0x1ad0
/* 002B28 70001F28 24050004 */  li    $a1, 4
/* 002B2C 70001F2C 00003825 */  move  $a3, $zero
/* 002B30 70001F30 0C00350C */  jal   osCreateThread
/* 002B34 70001F34 AFA20010 */   sw    $v0, 0x10($sp)
/* 002B38 70001F38 8FBF0034 */  lw    $ra, 0x34($sp)
/* 002B3C 70001F3C 8FB00020 */  lw    $s0, 0x20($sp)
/* 002B40 70001F40 8FB10024 */  lw    $s1, 0x24($sp)
/* 002B44 70001F44 8FB20028 */  lw    $s2, 0x28($sp)
/* 002B48 70001F48 8FB3002C */  lw    $s3, 0x2c($sp)
/* 002B4C 70001F4C 8FB40030 */  lw    $s4, 0x30($sp)
/* 002B50 70001F50 03E00008 */  jr    $ra
/* 002B54 70001F54 27BD0118 */   addiu $sp, $sp, 0x118
)
#endif

/**
 * 2B58 70001F58
 * insert sound manager thread
 *	redirect to 7000D580: A0=8005E530
 */
void start_audio_thread(void) {
    osStartThread(&AudioManager.audioThread);
}

#ifdef NONMATCHING
/**
 * 2B7C 70001F7C
 * Looks to be loosely based on method
 *     __amMain
 * from the n64devkit. This method makes some kind of video calls,
 * but also does some kind of debug tracking of the time spent between
 * beginning and end of processing.
 *
 * @param arg unused.
 *
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: yes
 * - identical registers: fail
 * - number of attempts: 1
 * - last attempt: 2021.01.17
 *
 * notes: It looks like there are two issues.
 * 1) The static variables are being loaded into the wrong registers.
 *     This is sEndTime, sStartTime, sLargestDeltaTime, sDeltaTimeSum.
 *     This causes trickle down differences.
 * 2) Inside the first if block, registers are saved onto the stack,
 *     but the stack locations differ.
 *     This causes trickle down differences.
 */
void audio_manager_main(void* arg)
{
    // eventually overflows.
    s32 counter = 0;
    
    s32 done = 0;
    AudioMessage *msg = 0;
    AudioInfo *lastInfo = 0;
    u64 localDelta;
    
    osScAddClient(&sc, &(audioClient[0]), &(AudioManager.frameMessageQueue), (void*)1);

    while (!done)
    {
        osRecvMesg(&AudioManager.frameMessageQueue, (OSMesg *)&msg, OS_MESG_BLOCK);
        
        switch (msg->gen.type)
        {
            case (OS_SC_RETRACE_MSG):
            {
                startTime = osGetTime();
                
                video_related_3(0x30000);
                audio_manager_handle_frame_message(AudioManager.audioInfo[audioFrameCount % 3U], lastInfo);
                counter++;
                video_related_3(0x60000);

                endTime = osGetTime();
                
                localDelta = endTime - startTime;
                
                // deltaTime doesn't seem to be used...
                deltaTime = localDelta;
            
                if ((counter % AUDIO_MANAGER_COUNT_INTERVAL) == 0)
                {
                    deltaAverage = deltaTimeSum / AUDIO_MANAGER_COUNT_INTERVAL;
                    
                    // Why is this computed a second time?
                    localDelta = endTime - startTime;
                    
                    deltaTimeSum = 0U;
                    largestDeltaTime = 0U;
                }
                else
                {
                    // First use of sDeltaTimeSum, uninitialized (hopefully zero)
                    deltaTimeSum = deltaTimeSum + endTime - startTime;
                }
                
                if (largestDeltaTime < localDelta)
                {
                    largestDeltaTime = localDelta;
                }
                
                osRecvMesg(&AudioManager.replyMessageQueue, (OSMesg *)&lastInfo, OS_MESG_BLOCK);
                
                audio_manager_handle_done_message(lastInfo);
            }
                break;
                
            case (5):
                done = 1;
                break;
                
            case (MAIN_QUIT_MESSAGE):
                done = 1;
                break;
                
            default:
                break;
        }
    }
    
    alClose(&(AudioManager.dmaBuffer));
}
#else
GLOBAL_ASM(
.text
glabel audio_manager_main
/* 002B7C 70001F7C 27BDFF90 */  addiu $sp, $sp, -0x70
/* 002B80 70001F80 AFB60030 */  sw    $s6, 0x30($sp)
/* 002B84 70001F84 3C168006 */  lui   $s6, %hi(AudioManager+0x1C8)
/* 002B88 70001F88 AFA40070 */  sw    $a0, 0x70($sp)
/* 002B8C 70001F8C 26D6E6E0 */  addiu $s6, %lo(AudioManager+0x1C8) # addiu $s6, $s6, -0x1920
/* 002B90 70001F90 AFBF003C */  sw    $ra, 0x3c($sp)
/* 002B94 70001F94 AFB20020 */  sw    $s2, 0x20($sp)
/* 002B98 70001F98 AFB1001C */  sw    $s1, 0x1c($sp)
/* 002B9C 70001F9C 3C048006 */  lui   $a0, %hi(sc)
/* 002BA0 70001FA0 3C058006 */  lui   $a1, %hi(audioClient)
/* 002BA4 70001FA4 AFBE0038 */  sw    $fp, 0x38($sp)
/* 002BA8 70001FA8 AFB70034 */  sw    $s7, 0x34($sp)
/* 002BAC 70001FAC AFB5002C */  sw    $s5, 0x2c($sp)
/* 002BB0 70001FB0 AFB40028 */  sw    $s4, 0x28($sp)
/* 002BB4 70001FB4 AFB30024 */  sw    $s3, 0x24($sp)
/* 002BB8 70001FB8 AFB00018 */  sw    $s0, 0x18($sp)
/* 002BBC 70001FBC 00008825 */  move  $s1, $zero
/* 002BC0 70001FC0 00009025 */  move  $s2, $zero
/* 002BC4 70001FC4 AFA00064 */  sw    $zero, 0x64($sp)
/* 002BC8 70001FC8 AFA00060 */  sw    $zero, 0x60($sp)
/* 002BCC 70001FCC 24A5E7A0 */  addiu $a1, %lo(audioClient) # addiu $a1, $a1, -0x1860
/* 002BD0 70001FD0 2484DA40 */  addiu $a0, %lo(sc) # addiu $a0, $a0, -0x25c0
/* 002BD4 70001FD4 02C03025 */  move  $a2, $s6
/* 002BD8 70001FD8 0C000305 */  jal   osScAddClient
/* 002BDC 70001FDC 24070001 */   li    $a3, 1
/* 002BE0 70001FE0 3C158006 */  lui   $s5, %hi(endTime)
/* 002BE4 70001FE4 3C148006 */  lui   $s4, %hi(startTime)
/* 002BE8 70001FE8 3C138006 */  lui   $s3, %hi(largestDeltaTime)
/* 002BEC 70001FEC 3C108006 */  lui   $s0, %hi(deltaTimeSum)
/* 002BF0 70001FF0 2610E4D0 */  addiu $s0, %lo(deltaTimeSum) # addiu $s0, $s0, -0x1b30
/* 002BF4 70001FF4 2673E4B8 */  addiu $s3, %lo(largestDeltaTime) # addiu $s3, $s3, -0x1b48
/* 002BF8 70001FF8 2694E4D8 */  addiu $s4, %lo(startTime) # addiu $s4, $s4, -0x1b28
/* 002BFC 70001FFC 26B5E4E0 */  addiu $s5, %lo(endTime) # addiu $s5, $s5, -0x1b20
/* 002C00 70002000 241E0001 */  li    $fp, 1
/* 002C04 70002004 27B70064 */  addiu $s7, $sp, 0x64
/* 002C08 70002008 02C02025 */  move  $a0, $s6
.L7000200C:
/* 002C0C 7000200C 02E02825 */  move  $a1, $s7
/* 002C10 70002010 0C003774 */  jal   osRecvMesg
/* 002C14 70002014 03C03025 */   move  $a2, $fp
/* 002C18 70002018 8FAE0064 */  lw    $t6, 0x64($sp)
/* 002C1C 7000201C 24010005 */  li    $at, 5
/* 002C20 70002020 85C40000 */  lh    $a0, ($t6)
/* 002C24 70002024 109E0007 */  beq   $a0, $fp, .L70002044
/* 002C28 70002028 00000000 */   nop   
/* 002C2C 7000202C 10810071 */  beq   $a0, $at, .L700021F4
/* 002C30 70002030 2401000A */   li    $at, 10
/* 002C34 70002034 50810072 */  beql  $a0, $at, .L70002200
/* 002C38 70002038 03C09025 */   move  $s2, $fp
/* 002C3C 7000203C 10000070 */  b     .L70002200
/* 002C40 70002040 00000000 */   nop   
.L70002044:
/* 002C44 70002044 0C003AEC */  jal   osGetTime
/* 002C48 70002048 00000000 */   nop   
/* 002C4C 7000204C AE820000 */  sw    $v0, ($s4)
/* 002C50 70002050 AE830004 */  sw    $v1, 4($s4)
/* 002C54 70002054 0C000A15 */  jal   video_related_3
/* 002C58 70002058 3C040003 */   lui   $a0, 3
/* 002C5C 7000205C 3C0F8002 */  lui   $t7, %hi(audioFrameCount) 
/* 002C60 70002060 8DEF30F4 */  lw    $t7, %lo(audioFrameCount)($t7)
/* 002C64 70002064 24010003 */  li    $at, 3
/* 002C68 70002068 3C048006 */  lui   $a0, %hi(AudioManager+8)
/* 002C6C 7000206C 01E1001B */  divu  $zero, $t7, $at
/* 002C70 70002070 0000C010 */  mfhi  $t8
/* 002C74 70002074 0018C880 */  sll   $t9, $t8, 2
/* 002C78 70002078 00992021 */  addu  $a0, $a0, $t9
/* 002C7C 7000207C 8C84E520 */  lw    $a0, %lo(AudioManager+8)($a0)
/* 002C80 70002080 0C000891 */  jal   audio_manager_handle_frame_message
/* 002C84 70002084 8FA50060 */   lw    $a1, 0x60($sp)
/* 002C88 70002088 26310001 */  addiu $s1, $s1, 1
/* 002C8C 7000208C 0C000A15 */  jal   video_related_3
/* 002C90 70002090 3C040006 */   lui   $a0, 6
/* 002C94 70002094 0C003AEC */  jal   osGetTime
/* 002C98 70002098 00000000 */   nop   
/* 002C9C 7000209C 8E8A0000 */  lw    $t2, ($s4)
/* 002CA0 700020A0 8E8B0004 */  lw    $t3, 4($s4)
/* 002CA4 700020A4 AEA20000 */  sw    $v0, ($s5)
/* 002CA8 700020A8 004AC023 */  subu  $t8, $v0, $t2
/* 002CAC 700020AC 006B082B */  sltu  $at, $v1, $t3
/* 002CB0 700020B0 0301C023 */  subu  $t8, $t8, $at
/* 002CB4 700020B4 AEA30004 */  sw    $v1, 4($s5)
/* 002CB8 700020B8 3C018006 */  lui   $at, %hi(dword_CODE_bss_8005E4C0)
/* 002CBC 700020BC 006BC823 */  subu  $t9, $v1, $t3
/* 002CC0 700020C0 AC39E4C4 */  sw    $t9, %lo(dword_CODE_bss_8005E4C4)($at)
/* 002CC4 700020C4 AC38E4C0 */  sw    $t8, %lo(dword_CODE_bss_8005E4C0)($at)
/* 002CC8 700020C8 240100F0 */  li    $at, 240
/* 002CCC 700020CC 0221001A */  div   $zero, $s1, $at
/* 002CD0 700020D0 00004010 */  mfhi  $t0
/* 002CD4 700020D4 AFB90044 */  sw    $t9, 0x44($sp)
/* 002CD8 700020D8 AFB80040 */  sw    $t8, 0x40($sp)
/* 002CDC 700020DC AFA20050 */  sw    $v0, 0x50($sp)
/* 002CE0 700020E0 AFA30054 */  sw    $v1, 0x54($sp)
/* 002CE4 700020E4 AFAA0048 */  sw    $t2, 0x48($sp)
/* 002CE8 700020E8 1500001C */  bnez  $t0, .L7000215C
/* 002CEC 700020EC AFAB004C */   sw    $t3, 0x4c($sp)
/* 002CF0 700020F0 8E040000 */  lw    $a0, ($s0)
/* 002CF4 700020F4 8E050004 */  lw    $a1, 4($s0)
/* 002CF8 700020F8 24060000 */  li    $a2, 0
/* 002CFC 700020FC 0C003B2A */  jal   __ull_div
/* 002D00 70002100 240700F0 */   li    $a3, 240
/* 002D04 70002104 3C018006 */  lui   $at, %hi(dword_CODE_bss_8005E4CC)
/* 002D08 70002108 AC22E4C8 */  sw    $v0, %lo(dword_CODE_bss_8005E4C8)($at)
/* 002D0C 7000210C AC23E4CC */  sw    $v1, %lo(dword_CODE_bss_8005E4CC)($at)
/* 002D10 70002110 8E990004 */  lw    $t9, 4($s4)
/* 002D14 70002114 8E980000 */  lw    $t8, ($s4)
/* 002D18 70002118 8EAF0004 */  lw    $t7, 4($s5)
/* 002D1C 7000211C 8EAE0000 */  lw    $t6, ($s5)
/* 002D20 70002120 240A0000 */  li    $t2, 0
/* 002D24 70002124 01F9082B */  sltu  $at, $t7, $t9
/* 002D28 70002128 01D84023 */  subu  $t0, $t6, $t8
/* 002D2C 7000212C 01014023 */  subu  $t0, $t0, $at
/* 002D30 70002130 240B0000 */  li    $t3, 0
/* 002D34 70002134 240C0000 */  li    $t4, 0
/* 002D38 70002138 240D0000 */  li    $t5, 0
/* 002D3C 7000213C 01F94823 */  subu  $t1, $t7, $t9
/* 002D40 70002140 AFA90044 */  sw    $t1, 0x44($sp)
/* 002D44 70002144 AE6D0004 */  sw    $t5, 4($s3)
/* 002D48 70002148 AE6C0000 */  sw    $t4, ($s3)
/* 002D4C 7000214C AE0B0004 */  sw    $t3, 4($s0)
/* 002D50 70002150 AFA80040 */  sw    $t0, 0x40($sp)
/* 002D54 70002154 10000011 */  b     .L7000219C
/* 002D58 70002158 AE0A0000 */   sw    $t2, ($s0)
.L7000215C:
/* 002D5C 7000215C 8E0B0004 */  lw    $t3, 4($s0)
/* 002D60 70002160 8FAD0054 */  lw    $t5, 0x54($sp)
/* 002D64 70002164 8E0A0000 */  lw    $t2, ($s0)
/* 002D68 70002168 8FAC0050 */  lw    $t4, 0x50($sp)
/* 002D6C 7000216C 016D7821 */  addu  $t7, $t3, $t5
/* 002D70 70002170 8FB80048 */  lw    $t8, 0x48($sp)
/* 002D74 70002174 8FB9004C */  lw    $t9, 0x4c($sp)
/* 002D78 70002178 01ED082B */  sltu  $at, $t7, $t5
/* 002D7C 7000217C 002A7021 */  addu  $t6, $at, $t2
/* 002D80 70002180 01CC7021 */  addu  $t6, $t6, $t4
/* 002D84 70002184 01D84023 */  subu  $t0, $t6, $t8
/* 002D88 70002188 01F9082B */  sltu  $at, $t7, $t9
/* 002D8C 7000218C 01014023 */  subu  $t0, $t0, $at
/* 002D90 70002190 01F94823 */  subu  $t1, $t7, $t9
/* 002D94 70002194 AE090004 */  sw    $t1, 4($s0)
/* 002D98 70002198 AE080000 */  sw    $t0, ($s0)
.L7000219C:
/* 002D9C 7000219C 8E6A0000 */  lw    $t2, ($s3)
/* 002DA0 700021A0 8FAC0040 */  lw    $t4, 0x40($sp)
/* 002DA4 700021A4 8E6B0004 */  lw    $t3, 4($s3)
/* 002DA8 700021A8 8FAD0044 */  lw    $t5, 0x44($sp)
/* 002DAC 700021AC 018A082B */  sltu  $at, $t4, $t2
/* 002DB0 700021B0 14200008 */  bnez  $at, .L700021D4
/* 002DB4 700021B4 3C048006 */   lui   $a0, %hi(AudioManager+0x200)
/* 002DB8 700021B8 014C082B */  sltu  $at, $t2, $t4
/* 002DBC 700021BC 14200003 */  bnez  $at, .L700021CC
/* 002DC0 700021C0 016D082B */   sltu  $at, $t3, $t5
/* 002DC4 700021C4 10200003 */  beqz  $at, .L700021D4
/* 002DC8 700021C8 00000000 */   nop   
.L700021CC:
/* 002DCC 700021CC AE6C0000 */  sw    $t4, ($s3)
/* 002DD0 700021D0 AE6D0004 */  sw    $t5, 4($s3)
.L700021D4:
/* 002DD4 700021D4 2484E718 */  addiu $a0, %lo(AudioManager+0x200) # addiu $a0, $a0, -0x18e8
/* 002DD8 700021D8 27A50060 */  addiu $a1, $sp, 0x60
/* 002DDC 700021DC 0C003774 */  jal   osRecvMesg
/* 002DE0 700021E0 03C03025 */   move  $a2, $fp
/* 002DE4 700021E4 0C0008F9 */  jal   audio_manager_handle_done_message
/* 002DE8 700021E8 8FA40060 */   lw    $a0, 0x60($sp)
/* 002DEC 700021EC 10000004 */  b     .L70002200
/* 002DF0 700021F0 00000000 */   nop   
.L700021F4:
/* 002DF4 700021F4 10000002 */  b     .L70002200
/* 002DF8 700021F8 03C09025 */   move  $s2, $fp
/* 002DFC 700021FC 03C09025 */  move  $s2, $fp
.L70002200:
/* 002E00 70002200 5240FF82 */  beql  $s2, $zero, .L7000200C
/* 002E04 70002204 02C02025 */   move  $a0, $s6
/* 002E08 70002208 3C048006 */  lui   $a0, %hi(AudioManager+0x238)
/* 002E0C 7000220C 0C003AB9 */  jal   alClose
/* 002E10 70002210 2484E750 */   addiu $a0, %lo(AudioManager+0x238) # addiu $a0, $a0, -0x18b0
/* 002E14 70002214 8FBF003C */  lw    $ra, 0x3c($sp)
/* 002E18 70002218 8FB00018 */  lw    $s0, 0x18($sp)
/* 002E1C 7000221C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 002E20 70002220 8FB20020 */  lw    $s2, 0x20($sp)
/* 002E24 70002224 8FB30024 */  lw    $s3, 0x24($sp)
/* 002E28 70002228 8FB40028 */  lw    $s4, 0x28($sp)
/* 002E2C 7000222C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 002E30 70002230 8FB60030 */  lw    $s6, 0x30($sp)
/* 002E34 70002234 8FB70034 */  lw    $s7, 0x34($sp)
/* 002E38 70002238 8FBE0038 */  lw    $fp, 0x38($sp)
/* 002E3C 7000223C 03E00008 */  jr    $ra
/* 002E40 70002240 27BD0070 */   addiu $sp, $sp, 0x70
)
#endif

/**
 * 2E44	70002244
 * Based on method
 *     static u32 __amHandleFrameMsg(AudioInfo *info, AudioInfo *lastInfo)
 * from the n64devkit demos_old/simple/audiomgr.c.
 *
 * original documentation:
 * First, clear the past audio dma's, then calculate 
 * the number of samples you will need for this frame. This value varies
 * due to the fact that audio is synchronised off of the video interupt 
 * which can have a small amount of jitter in it. Varying the number of 
 * samples slightly will allow you to stay in synch with the video. This
 * is an advantageous thing to do, since if you are in synch with the 
 * video, you will have fewer graphics yields. After you've calculated 
 * the number of frames needed, call alAudioFrame, which will call all
 * of the synthesizer's players (sequence player and sound player) to
 * generate the audio task list. If you get a valid task list back, put
 * it in a task structure and send a message to the scheduler to let it
 * know that the next frame of audio is ready for processing.
 * 
 * @param info audio info.
 * @param lastInfo last info.
 */
void audio_manager_handle_frame_message(AudioInfo *info, AudioInfo *lastInfo) {
    s16* outBuffer;
    Acmd *cmdlp;
    s32 temp_v1;

    /* call once a frame, before doing alAudioFrame */
    clear_audio_dma();
    
    outBuffer = (s16*)osVirtualToPhysical(info->data);
    
    if (lastInfo)
    {
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples * 4);
    }
    
    /* calculate how many samples needed for this frame to keep the DAC full */
    /* this will vary slightly frame to frame, must recalculate every frame */
    /* divide by four, to convert bytes */
    /* to stereo 16 bit samples */
    info->frameSamples = (u16)(((frameSize - (osAiGetLength() >> 2)) + 16 + EXTRA_SAMPLES) & ~0xf);  
    temp_v1 = minFrameSize;
    
    if ((s32)info->frameSamples < (s32)(s16)temp_v1)
    {
        info->frameSamples = (s16)temp_v1;
    }
    
    cmdlp = (Acmd*)alAudioFrame(AudioManager.cmdList[currentAcmdList], &commandLength, outBuffer, info->frameSamples);
    
    /* paranoia */
    info->task.next = 0;
    info->task.flags = 0;

    /* reply to when finished */
    info->task.msgQ = (void *) (&(AudioManager.replyMessageQueue.mtqueue));

    /* reply with this message */
    info->task.msg = info;
    info->task.flags = OS_SC_NEEDS_RSP;
    info->task.list.t.data_ptr = (u64*)(AudioManager.cmdList[currentAcmdList]);
    info->task.list.t.data_size = (((s32)cmdlp - (s32)AudioManager.cmdList[currentAcmdList]) >> 3) * sizeof(Acmd);
    info->task.list.t.type = M_AUDTASK;
    info->task.list.t.ucode_boot = (u64*)rspbootTextStart;
    info->task.list.t.ucode_boot_size = ((s32)gsp3DTextStart - (s32)rspbootTextStart);
    info->task.list.t.flags = 0; // 1c
    info->task.list.t.ucode = (u64*)aspMainTextStart;
    info->task.list.t.ucode_data = (u64*)aspMainDataStart;
    info->task.list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    info->task.list.t.yield_data_ptr = NULL; // 50
    info->task.list.t.yield_data_size = 0; // 54
    
    /* swap which acmd list you use each frame */
    osSendMesg(osScGetCmdQ(&sc), (OSMesg)&info->task, OS_MESG_NOBLOCK);
    
    currentAcmdList ^= 1;
}


/**
 * 2FE4	700023E4
 * Based on method
 *     static void __amHandleDoneMsg(AudioInfo *info)
 * from the n64devkit demos_old/simple/audiomgr.c.
 *
 * original documentation:
 * Really just debugging info in this frame. Checks
 * to make sure we completed before we were out of samples.
 * 
 * @param info Unused.
 */
void audio_manager_handle_done_message(AudioInfo *info) {
    s32 samplesLeft;
    /*
    * in the audiomgr example, firstTime is declared here with
    * the static keyword. That breaks the build, but the following
    * code will compile to a matching binary,
    */
    int *b;
    
    samplesLeft = (s32)osAiGetLength() >> 2;

    /*
    * The initial code probably looked like the following (and this
    * is what you get with mips_to_c):
    * 
    *     if (samplesLeft == 0 && !firstTime) 
    */   
    b = &firstTime;
    if (!samplesLeft && !(*b)) {
        firstTime = 0;
    }
}

/**
 * 3024	70002424
 */
#ifdef NONMATCHING
s32 dmaCallBack(s32 addr, s32 len, void* state) {
    s32 sp30;
    s32 sp48;
    ?32 sp4C;
    s32 temp_t2;
    s32 temp_a3;

    // Node 0
    temp_t2 = (arg0 & 1);
    sp48 = temp_t2;
    if (dmaState_initialized.unk4 != 0)
    {
        loop_1:
        // Node 1
        if (arg0 >= (u32) dmaState_initialized.unk4->unk8)
        {
            // Node 2
            if ((dmaState_initialized.unk4->unk8 + 0x200) >= (arg0 + arg1))
            {
                // Node 3
                dmaState_initialized.unk4->unkC = (?32) audioFrameCount;
                osVirtualToPhysical(((dmaState_initialized.unk4->unk10 + arg0) - dmaState_initialized.unk4->unk8), dmaState_initialized.unk4, arg0);
                return;
                // (possible return value: osVirtualToPhysical(((dmaState_initialized.unk4->unk10 + arg0) - dmaState_initialized.unk4->unk8), dmaState_initialized.unk4, arg0))
            }
            // Node 4
            if (*dmaState_initialized.unk4 != 0)
            {
                goto loop_1;
            }
        }
    }
    // Node 5
    if (dmaState_initialized.unk8 == 0)
    {
        // Node 6
        if (NULL == 0)
        {
            // Node 7
        }
        // Node 8
        sp30 = temp_t2;
        osVirtualToPhysical(NULL->unk10, NULL, arg0);
    }
    else
    {
        // Node 9
        dmaState_initialized.unk8 = (void *) *dmaState_initialized.unk8;
        alUnlink(dmaState_initialized.unk8, NULL, arg0);
        if (sp38 != 0)
        {
            // Node 10
            alLink(dmaState_initialized.unk8, sp38, sp38, arg14);
        }
        else
        {
            // Node 11
            if (dmaState_initialized.unk4 != 0)
            {
                // Node 12
                dmaState_initialized.unk4 = (void *) dmaState_initialized.unk8;
                *dmaState_initialized.unk8 = (void *) dmaState_initialized.unk4;
                dmaState_initialized.unk8->unk4 = 0;
                dmaState_initialized.unk4->unk4 = (void *) dmaState_initialized.unk8;
            }
            else
            {
                // Node 13
                dmaState_initialized.unk4 = (void *) dmaState_initialized.unk8;
                *dmaState_initialized.unk8 = NULL;
                dmaState_initialized.unk8->unk4 = 0;
            }
        }
        // Node 14
        temp_a3 = (arg14 - sp48);
        dmaState_initialized.unk8->unk8 = temp_a3;
        dmaState_initialized.unk8->unkC = (?32) audioFrameCount;
        nextDMA = (s32) (nextDMA + 1);
        sp4C = (?32) dmaState_initialized.unk8->unk10;
        osPiStartDma(((nextDMA * 0x18) + &audDMAIOMesgBuf), 1, 0, temp_a3, (?32) dmaState_initialized.unk8->unk10, 0x200, &audDMAMessageQ);
        osVirtualToPhysical(sp4C);
    }
    // Node 15
    return;
    // (possible return value: (osVirtualToPhysical(sp4C) + sp48))
}
#else
GLOBAL_ASM(
.text
glabel dmaCallBack
/* 003024 70002424 3C098006 */  lui   $t1, %hi(dmaState) 
/* 003028 70002428 2529E7B0 */  addiu $t1, %lo(dmaState) # addiu $t1, $t1, -0x1850
/* 00302C 7000242C 8D280004 */  lw    $t0, 4($t1)
/* 003030 70002430 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 003034 70002434 AFB00028 */  sw    $s0, 0x28($sp)
/* 003038 70002438 AFA60058 */  sw    $a2, 0x58($sp)
/* 00303C 7000243C 308A0001 */  andi  $t2, $a0, 1
/* 003040 70002440 AFBF002C */  sw    $ra, 0x2c($sp)
/* 003044 70002444 00803825 */  move  $a3, $a0
/* 003048 70002448 00003025 */  move  $a2, $zero
/* 00304C 7000244C AFAA0048 */  sw    $t2, 0x48($sp)
/* 003050 70002450 11000015 */  beqz  $t0, .L700024A8
/* 003054 70002454 01008025 */   move  $s0, $t0
/* 003058 70002458 8E020008 */  lw    $v0, 8($s0)
.L7000245C:
/* 00305C 7000245C 00E57021 */  addu  $t6, $a3, $a1
/* 003060 70002460 00E2082B */  sltu  $at, $a3, $v0
/* 003064 70002464 14200010 */  bnez  $at, .L700024A8
/* 003068 70002468 24430200 */   addiu $v1, $v0, 0x200
/* 00306C 7000246C 006E082A */  slt   $at, $v1, $t6
/* 003070 70002470 1420000A */  bnez  $at, .L7000249C
/* 003074 70002474 02003025 */   move  $a2, $s0
/* 003078 70002478 8E180010 */  lw    $t8, 0x10($s0)
/* 00307C 7000247C 3C0F8002 */  lui   $t7, %hi(audioFrameCount) 
/* 003080 70002480 8DEF30F4 */  lw    $t7, %lo(audioFrameCount)($t7)
/* 003084 70002484 0307C821 */  addu  $t9, $t8, $a3
/* 003088 70002488 03222023 */  subu  $a0, $t9, $v0
/* 00308C 7000248C 0C003A2C */  jal   osVirtualToPhysical
/* 003090 70002490 AE0F000C */   sw    $t7, 0xc($s0)
/* 003094 70002494 1000004C */  b     .L700025C8
/* 003098 70002498 8FBF002C */   lw    $ra, 0x2c($sp)
.L7000249C:
/* 00309C 7000249C 8E100000 */  lw    $s0, ($s0)
/* 0030A0 700024A0 5600FFEE */  bnezl $s0, .L7000245C
/* 0030A4 700024A4 8E020008 */   lw    $v0, 8($s0)
.L700024A8:
/* 0030A8 700024A8 8D300008 */  lw    $s0, 8($t1)
/* 0030AC 700024AC 1600000A */  bnez  $s0, .L700024D8
/* 0030B0 700024B0 02002025 */   move  $a0, $s0
/* 0030B4 700024B4 54C00003 */  bnezl $a2, .L700024C4
/* 0030B8 700024B8 8CC40010 */   lw    $a0, 0x10($a2)
/* 0030BC 700024BC 01003025 */  move  $a2, $t0
/* 0030C0 700024C0 8CC40010 */  lw    $a0, 0x10($a2)
.L700024C4:
/* 0030C4 700024C4 0C003A2C */  jal   osVirtualToPhysical
/* 0030C8 700024C8 AFAA0030 */   sw    $t2, 0x30($sp)
/* 0030CC 700024CC 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0030D0 700024D0 1000003C */  b     .L700025C4
/* 0030D4 700024D4 004A1021 */   addu  $v0, $v0, $t2
.L700024D8:
/* 0030D8 700024D8 8E0B0000 */  lw    $t3, ($s0)
/* 0030DC 700024DC AFA70050 */  sw    $a3, 0x50($sp)
/* 0030E0 700024E0 AFA60038 */  sw    $a2, 0x38($sp)
/* 0030E4 700024E4 0C003AA4 */  jal   alUnlink
/* 0030E8 700024E8 AD2B0008 */   sw    $t3, 8($t1)
/* 0030EC 700024EC 8FA60038 */  lw    $a2, 0x38($sp)
/* 0030F0 700024F0 3C098006 */  lui   $t1, %hi(dmaState) 
/* 0030F4 700024F4 2529E7B0 */  addiu $t1, %lo(dmaState) # addiu $t1, $t1, -0x1850
/* 0030F8 700024F8 10C00007 */  beqz  $a2, .L70002518
/* 0030FC 700024FC 8FA70050 */   lw    $a3, 0x50($sp)
/* 003100 70002500 02002025 */  move  $a0, $s0
/* 003104 70002504 00C02825 */  move  $a1, $a2
/* 003108 70002508 0C003AB0 */  jal   alLink
/* 00310C 7000250C AFA70050 */   sw    $a3, 0x50($sp)
/* 003110 70002510 1000000C */  b     .L70002544
/* 003114 70002514 8FA70050 */   lw    $a3, 0x50($sp)
.L70002518:
/* 003118 70002518 8D280004 */  lw    $t0, 4($t1)
/* 00311C 7000251C 51000007 */  beql  $t0, $zero, .L7000253C
/* 003120 70002520 AD300004 */   sw    $s0, 4($t1)
/* 003124 70002524 AD300004 */  sw    $s0, 4($t1)
/* 003128 70002528 AE080000 */  sw    $t0, ($s0)
/* 00312C 7000252C AE000004 */  sw    $zero, 4($s0)
/* 003130 70002530 10000004 */  b     .L70002544
/* 003134 70002534 AD100004 */   sw    $s0, 4($t0)
/* 003138 70002538 AD300004 */  sw    $s0, 4($t1)
.L7000253C:
/* 00313C 7000253C AE000000 */  sw    $zero, ($s0)
/* 003140 70002540 AE000004 */  sw    $zero, 4($s0)
.L70002544:
/* 003144 70002544 8FAC0048 */  lw    $t4, 0x48($sp)
/* 003148 70002548 3C0D8002 */  lui   $t5, %hi(audioFrameCount) 
/* 00314C 7000254C 3C088002 */  lui   $t0, %hi(nextDMA) 
/* 003150 70002550 00EC3823 */  subu  $a3, $a3, $t4
/* 003154 70002554 AE070008 */  sw    $a3, 8($s0)
/* 003158 70002558 8DAD30F4 */  lw    $t5, %lo(audioFrameCount)($t5)
/* 00315C 7000255C 250830F8 */  addiu $t0, %lo(nextDMA) # addiu $t0, $t0, 0x30f8
/* 003160 70002560 8E030010 */  lw    $v1, 0x10($s0)
/* 003164 70002564 AE0D000C */  sw    $t5, 0xc($s0)
/* 003168 70002568 8D020000 */  lw    $v0, ($t0)
/* 00316C 7000256C 3C0F8006 */  lui   $t7, %hi(audDMAIOMesgBuf) 
/* 003170 70002570 3C198006 */  lui   $t9, %hi(audDMAMessageQ) 
/* 003174 70002574 00027080 */  sll   $t6, $v0, 2
/* 003178 70002578 01C27023 */  subu  $t6, $t6, $v0
/* 00317C 7000257C 000E70C0 */  sll   $t6, $t6, 3
/* 003180 70002580 2739F2D0 */  addiu $t9, %lo(audDMAMessageQ) # addiu $t9, $t9, -0xd30
/* 003184 70002584 25EFECD0 */  addiu $t7, %lo(audDMAIOMesgBuf) # addiu $t7, $t7, -0x1330
/* 003188 70002588 24180200 */  li    $t8, 512
/* 00318C 7000258C 244B0001 */  addiu $t3, $v0, 1
/* 003190 70002590 AD0B0000 */  sw    $t3, ($t0)
/* 003194 70002594 AFB80014 */  sw    $t8, 0x14($sp)
/* 003198 70002598 01CF2021 */  addu  $a0, $t6, $t7
/* 00319C 7000259C AFB90018 */  sw    $t9, 0x18($sp)
/* 0031A0 700025A0 24050001 */  li    $a1, 1
/* 0031A4 700025A4 00003025 */  move  $a2, $zero
/* 0031A8 700025A8 AFA3004C */  sw    $v1, 0x4c($sp)
/* 0031AC 700025AC 0C003DA8 */  jal   osPiStartDma
/* 0031B0 700025B0 AFA30010 */   sw    $v1, 0x10($sp)
/* 0031B4 700025B4 0C003A2C */  jal   osVirtualToPhysical
/* 0031B8 700025B8 8FA4004C */   lw    $a0, 0x4c($sp)
/* 0031BC 700025BC 8FAC0048 */  lw    $t4, 0x48($sp)
/* 0031C0 700025C0 004C1021 */  addu  $v0, $v0, $t4
.L700025C4:
/* 0031C4 700025C4 8FBF002C */  lw    $ra, 0x2c($sp)
.L700025C8:
/* 0031C8 700025C8 8FB00028 */  lw    $s0, 0x28($sp)
/* 0031CC 700025CC 27BD0050 */  addiu $sp, $sp, 0x50
/* 0031D0 700025D0 03E00008 */  jr    $ra
/* 0031D4 700025D4 00000000 */   nop   
)
#endif

/**
 * 31D8 700025D8
 * Based on method
 *     ALDMAproc __amDmaNew(AMDMAState **state)
 * from the n64devkit demos_old/simple/audiomgr.c.
 *
 * original documentation:
 * Initialize the dma buffers and return the address of the
 * procedure that will be used to dma the samples from rom to ram. This 
 * routine will be called once for each physical voice that is created. 
 * In this case, because we know where all the buffers are, and since 
 * they are not attached to a specific voice, we will only really do any
 * initialization the first time. After that we just return the address
 * to the dma routine.
 * 
 * @param state will point to dmaState after call.
 * @return Address of dma callback function.
 */
ALDMAproc audio_manager_dma_new(DMAState** state)
{
    if (dmaState.u.initialized == 0) {
        dmaState.firstUsed = NULL;
        dmaState.firstFree = dmaBuffers;
        dmaState.u.initialized = (u8)1U;
    }

    *state = &dmaState;
    return &dmaCallBack;
}

/**
 * 3210 70002610
 * Based on method
 *     static void __clearAudioDMA(void)
 * from the n64devkit demos_old/simple/audiomgr.c.
 *
 * original documentation:
 * Routine to move dma buffers back to the unused list.
 * First clear out your dma messageQ. Then check each buffer to see when
 * it was last used. If that was more than FRAME_LAG frames ago, move it
 * back to the unused list. 
 */
void clear_audio_dma(void) {
    u32 i;
    OSMesg osmesg;
    DMABuffer *dmaPtr, *nextPtr;
    
    osmesg = 0;

   /*
    * Don't block here. If dma's aren't complete, you've had an audio
    * overrun. (Bad news, but go for it anyway, and try and recover.
    */
   for (i=0; i<nextDMA; i++)
   {
       if (osRecvMesg(&audDMAMessageQ, (OSMesg *)&osmesg, OS_MESG_NOBLOCK) == -1)
        /*
            The audiomgr example has an ifndef for a debug statement as follows:
            PRINTF("Dma not done\n");
        */
        ;
   }

    dmaPtr = dmaState.firstUsed;
    while (dmaPtr)
    {
        nextPtr = (DMABuffer*)dmaPtr->node.next;

        /* remove old dma's from list */
        /* Can change FRAME_LAG value.  Should be at least one.  */
        /* Larger values mean more buffers needed, but fewer DMA's */
        if (dmaPtr->lastFrame + 1 < audioFrameCount)
        {
            if (dmaState.firstUsed == dmaPtr) {
                dmaState.firstUsed = (DMABuffer*)dmaPtr->node.next;
            }

            alUnlink((ALLink*)dmaPtr);

            if (dmaState.firstFree)
            {
                alLink((ALLink*)dmaPtr, (ALLink*)dmaState.firstFree);
            }
            else
            {
                dmaState.firstFree = dmaPtr;
                dmaPtr->node.next = 0;
                dmaPtr->node.prev = 0;
            }
        }
        dmaPtr = nextPtr;
    }

    nextDMA = 0U;
    audioFrameCount = (s32)(audioFrameCount + 1);
}

