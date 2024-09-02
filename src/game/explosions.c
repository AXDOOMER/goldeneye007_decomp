#include <ultra64.h>
#include <PR/os.h>
#include <PR/gbi.h>
#include <gbi_extension.h>
#include <bondconstants.h>
#include <bondtypes.h>
#include <limits.h>
#include "bg.h"
#include "bondview.h"
#include "cheat_buttons.h"
#include "chrai.h"
#include "chrlv.h"
#include "chrobjhandler.h"
#include "explosions.h"
#include "fr.h"
#include "image_bank.h"
#include "othermodemicrocode.h"
#include "lvl.h"
#include "matrixmath.h"
#include "music.h"
#include "player.h"
#include "random.h"
#include "snd.h"
#include "stan.h"
#include "unk_0BC530.h"
#include <assets/GlobalImageTable.h>

// bss
//CODE.bss:8007A100
// possibly   printf("Allocating %d bytes for glass data (%d bits)\n",DAT_83bd5fb0 * 0x88 + 0xf & 0xfffffff0,         DAT_83bd5fb0);
char dword_CODE_bss_8007A100[0x40];

/**
 * ptr_smoke_buf = mempAllocBytesInBank(0x1FE0, MEMPOOL_STAGE);
 * printf("Allocating %d bytes for smoke data\n",0x9f60);
 * Address 0x8007A140.
*/
struct Smoke *ptr_smoke_buf;

/**
 * ptr_explosion_buf = mempAllocBytesInBank(0x1740, MEMPOOL_STAGE);
 * printf("Allocating %d bytes for explosion data\n",0x2e80);
 * Address 0x8007A144.
*/
struct Explosion *ptr_explosion_buf;

//CODE.bss:8007A148
s32 max_particles;
//CODE.bss:8007A14C
// printf("Allocating %d bytes for debris data (%d bits)\n", DAT_83bd2af0 * 0xa4, DAT_83bd2af0);
struct FlyingParticles *ptr_flying_particles_buf;

/**
 * ptr_scorch_buf = mempAllocBytesInBank(0x6E0, MEMPOOL_STAGE);
 * printf("Allocating %d bytes for scorch data\n",0xa50);
 * sizeof each entry == 0x58
 * Address 0x8007A150.
*/
struct Scorch *ptr_scorch_buf;

/**
 * ptr_bullet_impact_buf = mempAllocBytesInBank(0x1F40, MEMPOOL_STAGE);
 * printf("Allocating %d bytes for wallhit data\n",0x3070);
 * Address 0x8007A154.
*/
struct BulletImpact *ptr_bullet_impact_buf;

// data
//D:80040170
s32 numExplosionEntries = 0;
//D:80040174
s32 numSmokeEntries = 0;
//D:80040178
f32 D_80040178 = 1.0;

#if defined(VERSION_EU)
s_smoketype array_smoke_types[] = {
   // dur, appr, dis, size, bgrate,    r,  g,    b, fgrate, propclouds
    {   1,   50,  99,    0,   0.0f, 128, 128, 128,   0.3f,     150 },
    { 400,   50,  37,   60,  0.02f,  80,  80,  96,   0.3f,     150 },
    { 400,   50,  42,   20,  0.01f, 128, 128, 128,   0.3f,     150 },
    { 525,   50, 100,  100,  0.01f, 192, 192, 192,   0.3f,     150 },
    { 525,   50,  50,   80,  0.02f,  64,  64,  64,   0.3f,     150 },
    { 640,   50,  42,  190,  0.15f,  64,  64,  64,   0.3f,     150 },
    { 750,   50,  58,  300,  0.01f,  64,  64,  64,   0.3f,     150 },
    {  50,   50,   7,   15,  0.03f, 255, 255, 255,   0.3f,     150 },
    {  17,    1,   5,   30,  0.03f, 255, 255, 255,   2.0f,      25 },
    {  21,    1,   6,   16,  0.03f, 224, 224, 224,   3.0f,      25 },
    { 750,   50,  58,  900,  0.01f,  64,  64,  64,   0.3f,     150 }
};
#else
//D:8004017C
s_smoketype array_smoke_types[] = {
   // dur, appr, dis,size, bgrate,   r,  g,    b, fgrate, propclouds
    {   1,   60,  99,   0,   0.0f, 128, 128, 128,   0.3f,     180},
    { 480,   60,  45,  60,  0.02f,  80,  80,  96,   0.3f,     180},
    { 480,   60,  50,  20,  0.01f, 128, 128, 128,   0.3f,     180},
    { 640,   60, 120, 100,  0.01f, 192, 192, 192,   0.3f,     180},
    { 640,   60,  60,  80,  0.02f,  64,  64,  64,   0.3f,     180},
    { 770,   60,  50, 190,  0.15f,  64,  64,  64,   0.3f,     180},
    { 900,   60,  70, 300,  0.01f,  64,  64,  64,   0.3f,     180},
    {  60,   60,   8,  15,  0.03f, 255, 255, 255,   0.3f,     180},
    {  20,    1,   6,  30,  0.03f, 255, 255, 255,   2.0f,      30},
    {  25,    1,   7,  16,  0.03f, 224, 224, 224,   3.0f,      30},
    { 900,   60,  70, 900,  0.01f,  64,  64,  64,   0.3f,     180}
};
#endif

#if defined(VERSION_EU)
s_explosiontype array_explosion_types[] = {
   //hrange, vrange,    hchg,               vchg,           expsize, exprang, dmgrang,   dur, proprate, flarespd, nbits,  bitsize, bitdist, bithvel, bitvvel, smoketype,             sndid, damage
    {  0.1f,   0.1f,    0.0f,               0.0f,                   0.1f,    0.0f,    0.0f,     1,        1,     1.0f,     0,     0.1f,    0.0f,    0.0f,    0.0f,         0,              0x00,   0.0f},
    {  1.0f,   1.0f,    0.0f,               0.0f,                   1.0f,    0.0f,    0.0f,    25,        1,     1.0f,    10,     5.0f,    0.0f,    2.0f,    6.0f,         7,              0x00,   0.0f},
    { 20.0f,  20.0f,    0.0f,               0.0f,                  30.0f,   50.0f,   50.0f,    67,        1,     3.0f,    40,     6.0f,    5.0f,    0.7f,    6.0f,         2,  EXPLOSION_1B_SFX, 0.125f},
    { 50.0f,  50.0f,    0.0f,               0.0f,                  50.0f,  100.0f,  100.0f,    75,        1,     4.0f,    50,     6.0f,   10.0f,    1.0f,    6.0f,         2,  EXPLOSION_1C_SFX,   0.5f},
    { 60.0f,  80.0f,    1.20000004768f,     0.360000014305f,      100.0f,  150.0f,  280.0f,   100,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   1.0f},
    { 60.0f, 120.0f,    1.20000004768f,     0.360000014305f,      150.0f,  200.0f,  310.0f,   100,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 20.0f,  20.0f,    0.0f,               0.0f,                  22.0f,   40.0f,   40.0f,    67,        1,     3.0f,    40,     6.0f,    5.0f,    0.7f,    6.0f,         2,  EXPLOSION_1B_SFX,   0.5f},
    { 35.0f,  40.0f,    0.0f,               0.0f,                  35.0f,   70.0f,   70.0f,    75,        1,     4.0f,    50,     6.0f,   10.0f,    1.0f,    6.0f,         2,  EXPLOSION_1C_SFX,   1.0f},
    { 50.0f,  80.0f,    1.20000004768f,     0.360000014305f,       50.0f,  100.0f,  220.0f,   100,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 60.0f, 120.0f,    1.20000004768f,     0.360000014305f,       50.0f,  130.0f,  230.0f,   100,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 40.0f,  40.0f,    0.5f,               0.239999994635582f,    70.0f,  100.0f,  180.0f,   162,        4,     5.0f,   120,     6.0f,   30.0f,    2.5f,    6.0f,         4,  EXPLOSION_5A_SFX,   1.0f},
    { 50.0f,  50.0f,    0.699999988079071f, 0.5f,                 100.0f,  150.0f,  260.0f,   150,        1,     4.0f,   150,     6.0f,   30.0f,    3.0f,    6.0f,         4,  EXPLOSION_4A_SFX,   2.0f},
    { 70.0f,  60.0f,    1.20000004768372f,  0.699999988079071f,   150.0f,  225.0f,  320.0f,   150,        2,     5.0f,   150,     6.0f,   30.0f,    4.0f,   12.0f,         5,  EXPLOSION_4A_SFX,   4.0f},
    /* standard explosion for grenades and mines */
    { 80.0f,  60.0f,    2.40000009536743f,  0.899999976158142f,   200.0f,  300.0f,  480.0f,   150,        2,     5.0f,   200,     6.0f,   30.0f,    6.0f,   15.0f,         6,  EXPLOSION_4B_SFX,   4.0f},
    { 50.0f,  50.0f,    0.0f,               0.0f,                 120.0f,  200.0f,  400.0f,   125,        4,     4.0f,   150,     6.0f,   30.0f,    3.0f,    6.0f,         4,  EXPLOSION_4B_SFX,   4.0f},
    {  1.0f,   1.0f,    0.0f,               0.0f,                   1.0f,    0.0f,    0.0f,     1,        1,     1.0f,   150,     6.0f,   30.0f,    2.5f,    6.0f,         7,  EXPLOSION_2B_SFX,   0.0f},
    {  1.0f,   1.0f,    0.0f,               0.0f,                   1.0f,    0.0f,    0.0f,     1,        1,     1.0f,   100,     6.0f,   30.0f,    2.5f,    6.0f,         7,  EXPLOSION_2B_SFX,   0.0f},
    { 80.0f,  60.0f,   18.0f,               6.0f,                1500.0f, 2200.0f, 3600.0f,   250,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
    { 80.0f,  60.0f,    3.59999990463257f,  1.20000004768372f,    300.0f,  450.0f,  640.0f,    50,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
    /* facility remote mine */
    { 90.0f,  75.0f,    3.0f,               1.0f,                 250.0f,  375.0f,  600.0f,   150,        2,     5.0f,   200,     6.0f,   30.0f,    6.0f,   15.0f,         6,  EXPLOSION_4B_SFX,   4.0f},
    {160.0f, 120.0f,    7.19999980926514f,  2.40000009536743f,    600.0f,  450.0f,  640.0f,    50,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
};
#else
s_explosiontype array_explosion_types[] = {
   //hrange, vrange,    hchg,  vchg,  expsize, exprang, dmgrang,   dur, proprate, flarespd, nbits,  bitsize, bitdist, bithvel, bitvvel, smoketype,             sndid, damage
    {  0.1f,   0.1f,    0.0f,  0.0f,     0.1f,    0.0f,    0.0f,     1,        1,     1.0f,     0,     0.1f,    0.0f,    0.0f,    0.0f,         0,              0x00,   0.0f},
    {  1.0f,   1.0f,    0.0f,  0.0f,     1.0f,    0.0f,    0.0f,    30,        1,     1.0f,    10,     5.0f,    0.0f,    2.0f,    6.0f,         7,              0x00,   0.0f},
    { 20.0f,  20.0f,    0.0f,  0.0f,    30.0f,   50.0f,   50.0f,    80,        1,     3.0f,    40,     6.0f,    5.0f,    0.7f,    6.0f,         2,  EXPLOSION_1B_SFX, 0.125f},
    { 50.0f,  50.0f,    0.0f,  0.0f,    50.0f,  100.0f,  100.0f,    90,        1,     4.0f,    50,     6.0f,   10.0f,    1.0f,    6.0f,         2,  EXPLOSION_1C_SFX,   0.5f},
    { 60.0f,  80.0f,    1.0f,  0.3f,   100.0f,  150.0f,  280.0f,   120,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   1.0f},
    { 60.0f, 120.0f,    1.0f,  0.3f,   150.0f,  200.0f,  310.0f,   120,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 20.0f,  20.0f,    0.0f,  0.0f,    22.0f,   40.0f,   40.0f,    80,        1,     3.0f,    40,     6.0f,    5.0f,    0.7f,    6.0f,         2,  EXPLOSION_1B_SFX,   0.5f},
    { 35.0f,  40.0f,    0.0f,  0.0f,    35.0f,   70.0f,   70.0f,    90,        1,     4.0f,    50,     6.0f,   10.0f,    1.0f,    6.0f,         2,  EXPLOSION_1C_SFX,   1.0f},
    { 50.0f,  80.0f,    1.0f,  0.3f,    50.0f,  100.0f,  220.0f,   120,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 60.0f, 120.0f,    1.0f,  0.3f,    50.0f,  130.0f,  230.0f,   120,        2,     5.0f,    80,     8.0f,   30.0f,    2.0f,    6.0f,         1,  EXPLOSION_4A_SFX,   2.0f},
    { 40.0f,  40.0f,    0.4f,  0.2f,    70.0f,  100.0f,  180.0f,   170,        4,     5.0f,   120,     6.0f,   30.0f,    2.5f,    6.0f,         4,  EXPLOSION_5A_SFX,   1.0f},
    { 50.0f,  50.0f,    0.6f,  0.4f,   100.0f,  150.0f,  260.0f,   180,        1,     4.0f,   150,     6.0f,   30.0f,    3.0f,    6.0f,         4,  EXPLOSION_4A_SFX,   2.0f},
    { 70.0f,  60.0f,    1.0f,  0.6f,   150.0f,  225.0f,  320.0f,   180,        2,     5.0f,   150,     6.0f,   30.0f,    4.0f,   12.0f,         5,  EXPLOSION_4A_SFX,   4.0f},
    { 80.0f,  60.0f,    2.0f,  0.7f,   200.0f,  300.0f,  480.0f,   180,        2,     5.0f,   200,     6.0f,   30.0f,    6.0f,   15.0f,         6,  EXPLOSION_4B_SFX,   4.0f},
    { 50.0f,  50.0f,    0.0f,  0.0f,   120.0f,  200.0f,  400.0f,   150,        4,     4.0f,   150,     6.0f,   30.0f,    3.0f,    6.0f,         4,  EXPLOSION_4B_SFX,   4.0f},
    {  1.0f,   1.0f,    0.0f,  0.0f,     1.0f,    0.0f,    0.0f,     1,        1,     1.0f,   150,     6.0f,   30.0f,    2.5f,    6.0f,         7,  EXPLOSION_2B_SFX,   0.0f},
    {  1.0f,   1.0f,    0.0f,  0.0f,     1.0f,    0.0f,    0.0f,     1,        1,     1.0f,   100,     6.0f,   30.0f,    2.5f,    6.0f,         7,  EXPLOSION_2B_SFX,   0.0f},
    { 80.0f,  60.0f,   15.0f,  5.0f,  1500.0f, 2200.0f, 3600.0f,   300,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
    { 80.0f,  60.0f,    3.0f,  1.0f,   300.0f,  450.0f,  640.0f,    60,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
    { 90.0f,  75.0f,    2.5f, 0.87f,   250.0f,  375.0f,  600.0f,   180,        2,     5.0f,   200,     6.0f,   30.0f,    6.0f,   15.0f,         6,  EXPLOSION_4B_SFX,   4.0f},
    {160.0f, 120.0f,    6.0f,  2.0f,   600.0f,  450.0f,  640.0f,    60,        1,     2.0f,     0,     0.0f,    0.0f,    0.0f,    0.0f,         0,  EXPLOSION_4B_SFX,   4.0f},
};
#endif

Gfx * array_explosion_dl_ptrs[] = {
    &globalDL_0x078,
    &globalDL_0x120,
    &globalDL_0x1c8,
    &globalDL_0x270,
    &globalDL_0x318,
    &globalDL_0x3c0,
    &globalDL_0x468,
    &globalDL_0x510,
    &globalDL_0x5b8,
    &globalDL_0x660,
    &globalDL_0x708,
    &globalDL_0x7b0,
    &globalDL_0x858,
    &globalDL_0x900,
    &globalDL_0x9a8
};
s32 numParticleEntries = 0;
s32 numScorchEntries = 0;
s32 numImpactEntries = 0;
//D:8004080C
s_impacttype D_8004080C[] = {
    {10.0f, 10.0f, 1, 2, 8},
    { 6.0f,  6.0f, 1, 2, 8},
    { 8.0f,  8.0f, 0, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    { 6.0f,  6.0f, 1, 2, 8},
    { 8.0f,  8.0f, 1, 2, 8},
    {12.0f, 12.0f, 1, 2, 8},
    { 6.0f,  6.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {20.0f, 20.0f, 1, 2, 8},
    {24.0f, 24.0f, 1, 2, 8},
    { 6.0f,  6.0f, 1, 2, 1},
    { 6.0f,  6.0f, 1, 2, 1},
    {24.0f, 24.0f, 2, 2, 8},
    { 6.0f,  6.0f, 1, 2, 1},
    { 8.0f,  8.0f, 1, 2, 1},
    {12.0f, 12.0f, 1, 2, 1},
};

u32 D_800408FC = 0;

Vtx D_80040900 = {0, 0, 0, 0, 0, 0, 0xff, 0xff, 0xff, 0xff };

Vtx D_80040910 = {0, 0, 0, 0, 0, 0, 0x0, 0x0, 0x0, 0x0 };


Vtx D_80040920 = {0, 0, 0, 0, 0, 0, 0x0, 0x0, 0x0, 0xDC };
Vtx D_80040930 = {0, 0, 0, 0, 0, 0, 0x0, 0x0, 0x0, 0xDC };


// rodata

/*** prototypes */

void init_gray_flying_particles(coord3d *spawnpos, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 sub_GAME_7F0A0C74(f32 arg0);
void sub_GAME_7F0A0E98(s32 arg0);
void sub_GAME_7F09C9D8(PropRecord *arg0, f32 arg1, f32 arg2);
void sub_GAME_7F09C9D8(struct PropRecord *arg0, f32 arg1, f32 arg2);
void sub_GAME_7F0A027C(struct coord3d *arg0, f32 arg1, s16 arg2);
Gfx *sub_GAME_7F09D82C(struct ExplosionPart *arg0, Gfx *gdl, struct coord3d *coord);

/*** *************************************************************************************************************/

/**
 * Named same as Perfect Dark.
 * NTSC 0x7F09C250
*/
#if defined(VERSION_JP) || defined(VERSION_EU)
s32
#else
void
#endif
explosionCreate(PropRecord *arg0, struct coord3d *target_pos, StandTile *target_stan, s16 explosion_type, s32 arg4, s32 player, u8 *rooms, s32 arg7)
{
    s_explosiontype *sp44;
    struct Explosion *sp40;
    f32 sp3C;
    f32 sp38;
    s32 var_v0;
    PropRecord *sp30;
    
    sp44 = &array_explosion_types[explosion_type];
    sp40 = NULL;
    
#if defined(VERSION_US)
    if ((explosion_type != 0x10) && (explosion_type != 1))
    {
        numExplosionEntries = 6;
    }
#endif

    for (var_v0 = 0; var_v0 < EXPLOSION_BUFFER_LEN; var_v0++)
    {
        if (ptr_explosion_buf[var_v0].prop == NULL)
        {
            sp40 = &ptr_explosion_buf[var_v0];
            break;
        }
    }

    if (sp40 != NULL)
    {
        sp30 = chrpropAllocate();
        
#if defined(VERSION_JP) || defined(VERSION_EU)
        if ((explosion_type != 0x10) && (explosion_type != 1))
        {
            numExplosionEntries = 6;
        }
#endif

        if ((s32) sp44->sndID > 0)
        {
            chrobjSndCreatePostEventDefault(sndPlaySfx((struct ALBankAlt_s *) g_musicSfxBufferPtr, (s16) sp44->sndID, NULL), target_pos);
        }

        if (sp30 != NULL)
        {
            sp30->type = PROP_TYPE_EXPLOSION;
            sp30->flags |= PROPFLAG_ONSCREEN;
            sp30->explosion = sp40;
            var_v0 = 0;
            sp30->stan = target_stan;
            sp30->pos.f[0] = target_pos->f[0];
            sp30->pos.f[1] = target_pos->f[1];
            sp30->pos.f[2] = target_pos->f[2];

            while (rooms[var_v0] != 0xff && var_v0 < 7)
            {
                sp30->rooms[var_v0] = rooms[var_v0];
                var_v0++;
            }

            sp30->rooms[var_v0] = 0xFF;

            if (arg7 != 0)
            {
                sp30->flags |= PROPFLAG_00000008;
            }

            chrpropActivateThisFrame(sp30);
            chrpropEnable(sp30);
            
            sp40->explosion_type = explosion_type;
            sp40->age = 0;
            sp40->unk3CA = -1;
            sp40->unk3CD = (u8) arg4;
            sp40->prop = sp30;
            sp40->unk04 = arg0;
            sp40->player = (s8) player;

            if (arg4 != 0)
            {
                if ((arg0 != NULL) && (arg0->stan != NULL))
                {
                    sp40->pos.f[0] = arg0->pos.f[0];
                    sp40->pos.f[1] = stanGetPositionYValue(arg0->stan, arg0->pos.f[0], arg0->pos.f[2]) + 4.0f;
                    sp40->pos.f[2] = arg0->pos.f[2];
                    sp40->room = getTileRoom(arg0->stan);
                }
                else
                {
                    sp40->pos.f[0] = target_pos->f[0];
                    sp40->pos.f[1] = stanGetPositionYValue(target_stan, target_pos->f[0], target_pos->f[2]) + 4.0f;
                    sp40->pos.f[2] = target_pos->f[2];
                    sp40->room = getTileRoom(target_stan);
                }
            }
            else
            {
                sp40->pos.f[0] = 999999.9f;
            }

            sp3C = ((RANDOMFRAC() * 0.5f) + 1.0f) * sp44->explosion_size;
            sp38 = RANDOMFRAC() * M_TAU_F;

            sp40->parts[0].size = cosf(sp38) * sp3C;
            sp40->parts[0].rot = sinf(sp38) * sp3C;
            sp40->parts[0].frame = 1;
            sp40->parts[0].pos.f[0] = target_pos->f[0];
            sp40->parts[0].pos.f[1] = target_pos->f[1];
            sp40->parts[0].pos.f[2] = target_pos->f[2];

            for (var_v0 = 0; var_v0 < sp44->numshrapnelbits; var_v0++)
            {
                init_gray_flying_particles(target_pos, sp44->shrapnel_scatter_dist, sp44->shrapnel_hvel, sp44->shrapnel_vvel, sp44->shrapnel_size);
            }

            if (getPlayerCount() >= 2)
            {
                for (var_v0 = 0; var_v0 < SMOKE_BUFFER_LEN; var_v0++)
                {
                    if (ptr_smoke_buf[var_v0].prop != NULL)
                    {
                        struct Smoke *smoke = &ptr_smoke_buf[var_v0];

                        if (smoke->smoke_type != 7 && smoke->smoke_type != 8 && smoke->smoke_type != 9)
                        {
                            smoke->duration = array_smoke_types[smoke->smoke_type].duration;
                        }
                    }                    
                }
            }
        }
    }

#if defined(VERSION_JP) || defined(VERSION_EU)
    return sp40 != 0;
#endif
}


void setSixExplosionAndSmokeEntries(void) {
        numExplosionEntries = 6;
        numSmokeEntries = 6;
}


void sub_GAME_7F09C7C4(coord3d* arg0, coord3d* arg1, coord3d* arg2)
{
    PropRecord* explosion_prop;
    f32 angle;
    f32 diff_x;
    f32 diff_z;
    f32 mag_scalar_x;
    f32 mag_scalar_z;
    f32 diff_y;
    f32 explosion_mag;

    s32 i;
    f32 dist;
    f32 dist2;

    if (numExplosionEntries == 0)
    {
        viShake(0.0f);
        return;
    }

    angle = 0.8f;
    mag_scalar_x = (cosf(angle) * arg1->x) - (sinf(angle) * arg1->f[2]);
    mag_scalar_z = (sinf(angle) * arg1->x) + (cosf(angle) * arg1->f[2]);

    explosion_mag = 0.0f;

    for (i = 0; i < EXPLOSION_BUFFER_LEN; i++)
    {
        explosion_prop = ptr_explosion_buf[i].prop;
        if (explosion_prop != NULL)
        {
            diff_x = explosion_prop->pos.x - arg0->x;
            diff_y = explosion_prop->pos.y - arg0->y;
            diff_z = explosion_prop->pos.z - arg0->z;
#ifndef VERSION_US
            dist = sqrtf((diff_x * diff_x) + (diff_y * diff_y) + (diff_z * diff_z));
            if (dist == 0.0f) { dist = 0.0001f; }
            dist2 = array_explosion_types[ptr_explosion_buf[i].explosion_type].explosion_size / dist;
#else
            dist = (diff_x * diff_x) + (diff_y * diff_y) + (diff_z * diff_z);
            dist2 = array_explosion_types[ptr_explosion_buf[i].explosion_type].explosion_size / sqrtf(dist);
#endif
            explosion_mag += dist2 * 15.0f;
        }
    }

    if (numSmokeEntries > 0)
    {
        numSmokeEntries--;
        explosion_mag++;
    }

    numExplosionEntries--;
    if (numExplosionEntries & 2)
    {
        arg2->y = explosion_mag;
        explosion_mag = -explosion_mag;
    }
    else
    {
        arg2->y = -explosion_mag;
    }

    arg2->x = explosion_mag * mag_scalar_x;
    arg2->z = explosion_mag * mag_scalar_z;

    viShake((f32) numExplosionEntries * explosion_mag);
}

/***
 * see Perfect Dark void explosionInflictDamage(struct prop *expprop)
 * Address 0x7F09C9D8 (NTSC)
*/
void sub_GAME_7F09C9D8(PropRecord *arg0, f32 arg1, f32 arg2)
{
    s32 spE0[8];
    PropRecord *temp_s0;    
    s16 *var_s3;
    s_explosiontype *temp_s6;
    struct Explosion *temp_s2;

    temp_s2 = arg0->explosion;
    temp_s6 = &array_explosion_types[temp_s2->explosion_type];

    if (temp_s2->age >= temp_s2->unk3CA)
    {
        chraiGetPropRoomIds(arg0, &spE0[0]);
        roomGetProps(&spE0[0]);

        for (var_s3 = ptr_list_object_lookup_indices; *var_s3 >= 0; var_s3++)
        {
            temp_s0 = &pos_data_entry[*var_s3];

            if ((temp_s0 != temp_s2->unk04) && (temp_s0->timetoregen == 0))
            {
                if (temp_s0->type == PROP_TYPE_OBJ || temp_s0->type == PROP_TYPE_WEAPON || temp_s0->type == PROP_TYPE_DOOR)
                {
                    struct ObjectRecord *spCC;
                    f32 xdist;
                    f32 ydist;
                    f32 zdist;
                    
                    spCC = temp_s0->obj;
                    xdist = spCC->runtime_pos.f[0] - arg0->pos.f[0];
                    ydist = spCC->runtime_pos.f[1] - arg0->pos.f[1];
                    zdist = spCC->runtime_pos.f[2] - arg0->pos.f[2];

                    if ((xdist <= arg1)
                        && (-arg1 <= xdist)
                        && (ydist <= arg2)
                        && (-arg2 <= ydist)
                        && (zdist <= arg1)
                        && (-arg1 <= zdist))
                    {
                        f32 xfrac;
                        f32 yfrac;
                        f32 zfrac;
                        f32 minfrac;
                        
                        xfrac = xdist / arg1;
                        yfrac = ydist / arg2;
                        zfrac = zdist / arg1;

                        if (xfrac < 0.0f)
                        {
                            xfrac = -xfrac;
                        }
                        
                        if (yfrac < 0.0f)
                        {
                            yfrac = -yfrac;
                        }

                        if (zfrac < 0.0f)
                        {
                            zfrac = -zfrac;
                        }
                        
                        xfrac = 1.0f - xfrac;
                        yfrac = 1.0f - yfrac;
                        zfrac = 1.0f - zfrac;

                        minfrac = xfrac;

                        if (yfrac < minfrac)
                        {
                            minfrac = yfrac;
                        }
                        
                        if (zfrac < minfrac)
                        {
                            minfrac = zfrac;
                        }

                        minfrac = minfrac * EXPLOSION_DAMAGE_SCALER * temp_s6->damage;

                        if (!(spCC->runtime_bitflags & 0x1000) && !(spCC->flags2 & 0x200400))
                        {
                            maybe_detonate_object_and_its_children(
                                temp_s0,
                                ((RANDOMFRAC() * 0.5f) + 1.0f) * minfrac,
                                &spCC->runtime_pos,
                                0x1D,
                                (s32) temp_s2->player);
                        }
                    }

                }
                else if (temp_s0->type == PROP_TYPE_CHR || temp_s0->type == PROP_TYPE_VIEWER)
                {
                    f32 xdist;
                    f32 ydist;
                    f32 zdist;
                    
                    xdist = temp_s0->pos.f[0] - arg0->pos.f[0];
                    ydist = temp_s0->pos.f[1] - arg0->pos.f[1];
                    zdist = temp_s0->pos.f[2] - arg0->pos.f[2];

                    if ((xdist <= arg1)
                        && (-arg1 <= xdist)
                        && (ydist <= arg2)
                        && (-arg2 <= ydist)
                        && (zdist <= arg1)
                        && (-arg1 <= zdist))
                    {
                        f32 xfrac;
                        f32 yfrac;
                        f32 zfrac;
                        f32 minfrac;
                        
                        xfrac = xdist / arg1;
                        yfrac = ydist / arg2;
                        zfrac = zdist / arg1;

                        if (xfrac < 0.0f)
                        {
                            xfrac = -xfrac;
                        }

                        if (yfrac < 0.0f)
                        {
                            yfrac = -yfrac;
                        }

                        if (zfrac < 0.0f)
                        {
                            zfrac = -zfrac;
                        }
                        
                        xfrac = 1.0f - xfrac;
                        yfrac = 1.0f - yfrac;
                        zfrac = 1.0f - zfrac;

                        minfrac = xfrac;

                        if (yfrac < minfrac)
                        {
                            minfrac = yfrac;
                        }
                        
                        if (zfrac < minfrac)
                        {
                            minfrac = zfrac;
                        }

                        minfrac *= minfrac;
                        minfrac = minfrac * EXPLOSION_DAMAGE_SCALER * temp_s6->damage;

                        if (temp_s0->type == PROP_TYPE_CHR)
                        {
                            chrlvExplosionDamage(temp_s0->chr, &arg0->pos, minfrac, 1);
                        }
                        else
                        {
                            s32 sp90;
                            
                            if ((xdist != 0.0f) || (zdist != 0.0f))
                            {
                                f32 temp_f2_3 = sqrtf((xdist * xdist) + (zdist * zdist));
                                xdist *= 1.0f / temp_f2_3;
                                zdist *= 1.0f / temp_f2_3;
                            }
                            
                            sp90 = get_cur_playernum();
                            set_cur_player(getPlayerPointerIndex(temp_s0));
                            
                            if (getPlayerCount() == 1)
                            {
                                minfrac *= D_80040178;
                            }
                            
                            if (isBondInTank() == 1)
                            {
                                minfrac *= 2.0f;
                            }
                            
                            record_damage_kills(minfrac, xdist, zdist, (s32) temp_s2->player, 1);
                            set_cur_player(sp90);
                        }
                    }
                }
            }
        }

        temp_s2->unk3CA = temp_s2->age + (temp_s6->duration >> 2);
    }
}





/***
 * see Perfect Dark u32 explosionTick(struct prop *prop)
 * 
 * NTSC address 0x7F09CEE8.
*/
s32 sub_GAME_7F09CEE8(PropRecord* arg0)
{
    s32 var_s4;
    s32 j;
    s32 k;
    
    f32 hrange;
    f32 vrange;
    f32 temp_f20;
    f32 temp_f12;
    
    struct Explosion *exp;
    s_explosiontype *explosiontype;
    
    f32 lvupdate;
    s32 sp9C;
    struct coord3d sp90;
    struct coord3d sp84;
    
    
    exp = arg0->explosion;
    explosiontype = &array_explosion_types[exp->explosion_type];
    
    if (g_ClockTimer == 0)
    {
        return 0;
    }
    
    lvupdate = (g_ClockTimer < 15) ? (f32) g_ClockTimer : 15.0f;

    if ((exp->age >= 8) && (exp->age < explosiontype->duration))
    {
        hrange = explosiontype->hrange + (explosiontype->hchange * exp->age);
        vrange = explosiontype->vrange + (explosiontype->vchange * exp->age);

        if (exp->explosion_type == 0xE)
        {
            if (exp->age < 0x20)
            {
                arg0->pos.f[1] += 10.0f * lvupdate;
            }
            
            if (exp->age >= 0x21)
            {
                hrange = (exp->age * 3.0f) + 40.0f;
                
                if (hrange > 300.0f)
                {
                    hrange = 300.0f;
                }
                
                vrange = 20.0f;
            }
        }

        sp9C = (s32) (((f32)explosiontype->propagationrate * (f32)exp->age) / (f32)explosiontype->duration) + 1;
        for (var_s4 = 0; var_s4 < sp9C; var_s4++)
        {
            for (j=0; j<EXPLOSION_PARTS_LEN; j++)
            {
                if (exp->parts[j].frame == 0)
                {
                    exp->parts[j].frame = 1;
    
                    exp->parts[j].pos.f[0] = arg0->pos.f[0] + ((RANDOMFRAC() - 0.5f) * hrange);
                    exp->parts[j].pos.f[1] = arg0->pos.f[1] + ((RANDOMFRAC() - 0.5f) * vrange);
                    exp->parts[j].pos.f[2] = arg0->pos.f[2] + ((RANDOMFRAC() - 0.5f) * hrange);
    
                    temp_f20 = ((RANDOMFRAC() * 0.5f) + 1.0f) * explosiontype->explosion_size;
                    temp_f12 = RANDOMFRAC() * M_TAU_F;
        
                    exp->parts[j].size = cosf(temp_f12) * temp_f20;
                    exp->parts[j].rot = sinf(temp_f12) * temp_f20;

                    break;
                }
            }
        }
        
        // see Perfect Dark void explosionGetBboxAtFrame(struct coord *lower, struct coord *upper, s32 frame, struct prop *prop)

        hrange = (hrange * 0.5f) + explosiontype->explosion_size * 1.5f;
        vrange = (vrange * 0.5f) + explosiontype->explosion_size * 1.5f;
        
        sp90.f[0] = arg0->pos.f[0] - hrange;
        sp90.f[1] = arg0->pos.f[1] - vrange;
        sp90.f[2] = arg0->pos.f[2] - hrange;
        
        sp84.f[0] = arg0->pos.f[0] + hrange;
        sp84.f[1] = arg0->pos.f[1] + vrange;
        sp84.f[2] = arg0->pos.f[2] + hrange;

        // end explosionGetBboxAtFrame.
        
        sub_GAME_7F03E27C(arg0, &sp90, &sp84, hrange);

        vrange = explosiontype->explosion_range + (((explosiontype->dmg_range - explosiontype->explosion_range) * (f32) exp->age) / (f32) explosiontype->duration);
        sub_GAME_7F09C9D8(arg0, vrange, vrange);
    }
    
    for (k = 0; k < (s32) lvupdate; k++)
    {
        exp->age++;
        
        for (j=0; j<EXPLOSION_PARTS_LEN; j++)
        {
            if (exp->parts[j].frame > 0)
            {
                exp->parts[j].frame++;
            }
        }

        if (((exp->age == 0xF) && (exp->explosion_type == 0xE))
            || (((exp->age + 0x14) == (s16) explosiontype->duration) && (exp->explosion_type != 0xE)))
        {
            if ((exp->unk04 != NULL) && (exp->unk04->stan != NULL))
            {
                if (exp->unk04->type == PROP_TYPE_OBJ)
                {
                    struct ObjectRecord *obj = exp->unk04->obj;
                    sub_GAME_7F09E700(&obj->runtime_pos, exp->unk04->stan, (s16) explosiontype->smoketype, exp->unk04->rooms, (arg0->flags & 8) != 0);
                }
                else
                {
                    sub_GAME_7F09E700(&exp->unk04->pos, exp->unk04->stan, (s16) explosiontype->smoketype, exp->unk04->rooms, (arg0->flags & 8) != 0);
                }
            }
            else
            {
                sub_GAME_7F09E700(&arg0->pos, arg0->stan, (s16) explosiontype->smoketype, arg0->rooms, (arg0->flags & 8) != 0);
            }
        }
        
        if ((exp->age == ((s16) explosiontype->duration >> 1)) && (exp->unk3CD != 0))
        {
            sub_GAME_7F0A027C(&exp->pos, explosiontype->explosion_size * 4.0f, exp->room);
        }
    }

    if (exp->age >= explosiontype->duration + (s32) (16.0f * explosiontype->flareanimspeed))
    {
        exp->prop = NULL;
        return 1;
    }
    
    return 0;
}



/*
* Address: 0x7F09D4EC
*/
u8 explosionTick(PropRecord* prop)
{
    Mtxf* player_matrix;

    player_matrix = camGetWorldToScreenMtxf();
    prop->Unk18 = -((((player_matrix->m[0][2] * prop->pos.x) + (player_matrix->m[1][2] * prop->pos.y)) + (player_matrix->m[2][2] * prop->pos.z)) + player_matrix->m[3][2]);

    if (prop->Unk18 < 100.0f)
    {
        prop->Unk18 *= 0.5f;
    }
    else
    {
        prop->Unk18 -= 100.0f;
    }

    if (g_ClockTimer == 0)
    {
        return 0;
    }

    return 0;
}


/***
 * Perfect Dark Gfx *explosionRender(struct prop *prop, Gfx *gdl, bool xlupass)
 * 
 * NTSC address 0x7F09D5A0.
*/
Gfx *unk09c250RenderPropExplosion(PropRecord *prop, Gfx *gdl, s32 withalpha)
{
    s32 temp_s1;
    struct Explosion *temp_s5;
    struct coord3d *temp_s6;
    s32 var_s2;
    
    struct bbox2d sp70;
    
    s32 temp_f10;

    s32 i;
    
    temp_s1 = prop->rooms[0];
    temp_s5 = prop->explosion;
    temp_s6 = getRoomIndexPOS((s32) temp_s1);
    
    if (withalpha == 0)
    {
        return gdl;
    }
    else
    {
        if (sub_GAME_7F054A64(prop, &sp70) > 0)
        {
            gdl = bgScissorCurrentPlayerViewF(gdl, sp70.min.f[0], sp70.min.f[1], sp70.max.f[0], sp70.max.f[1]);
        }
        else
        {
            gdl = bgScissorCurrentPlayerViewDefault(gdl);
        }

        gSPClearGeometryMode(gdl++, G_CULL_BOTH | G_FOG);
        gSPMatrix(gdl++, osVirtualToPhysical((void*)get_BONDdata_field_10E0()), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));

        gdl = sub_GAME_7F0BC9C4(gdl, temp_s1);

        gSPSegment(gdl++, SPSEGMENT_GETITLE, osVirtualToPhysical(pGlobalimagetable));

        for (var_s2 = 14;
            var_s2 >= 0;
            var_s2--)
        {
            gSPDisplayList(gdl++, array_explosion_dl_ptrs[var_s2]);
            
            for (i = 0; i < EXPLOSION_PARTS_LEN; i++)
            {
                if (temp_s5->parts[i].frame > 0
                    && var_s2 == (s32)( (f32)(temp_s5->parts[i].frame - 1) / array_explosion_types[temp_s5->explosion_type].flareanimspeed ) )
                {
                    gdl = sub_GAME_7F09D82C(&temp_s5->parts[i], gdl, temp_s6);
                }
            }
        }

        gSPMatrix(gdl++, osVirtualToPhysical((void*)currentPlayerGetProjectionMatrix()), (G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION));

        temp_f10 = (s32) (array_explosion_types[temp_s5->explosion_type].flareanimspeed * 15.0f);

        for (i = 0; i < EXPLOSION_PARTS_LEN; i++)
        {
            if (temp_f10 < temp_s5->parts[i].frame)
            {
                temp_s5->parts[i].frame = 0;
            }
        }
    }

    return gdl;
}



/***
 * Perfect Dark Gfx *explosionRenderPart(struct explosion *exp, struct explosionpart *part, Gfx *gdl, struct coord *coord, s32 arg4)
 * 
 * NTSC address 0x7F09D82C.
*/
Gfx *sub_GAME_7F09D82C(struct ExplosionPart *arg0, Gfx *gdl, struct coord3d *coord)
{
    s32 padding1;
    f32 f2;
    
    Vtx spA0;
    Mtxf *sp9C;
    struct coord3d *sp98;
    struct coord3d sp8C;
    struct coord3d sp80;
    struct coord3d sp74;
    struct coord3d sp68;  

    f32 sp64;
    f32 sp60;
    f32 sp5C;
    
    Vtx *vertices;
    
    f32 sp54;
    f32 sp50;
    
    f32 sp4c;
    f32 sp48;
    f32 sp44;
    
    f32 temp_f0;
    f32 var_f12;    

    spA0 = D_80040900;

    sp9C = currentPlayerGetMatrix10D4();
    sp98 = bondviewGetCurrentPlayersPosition();

    sp64 = arg0->pos.f[0] - sp98->f[0];
    sp60 = arg0->pos.f[1] - sp98->f[1];
    sp5C = arg0->pos.f[2] - sp98->f[2];

    temp_f0 = sqrtf((sp64 * sp64) + (sp60 * sp60) + (sp5C * sp5C));
    var_f12 = temp_f0 * 0.5f;
    if (var_f12 > 100.0f)
    {
        var_f12 = 100.0f;
    }

    if (temp_f0 == 0)
    {
        f2 = 0.0f;
    }
    else
    {
        f2 = (temp_f0 - var_f12) / temp_f0;
    }

    sp54 = arg0->size * f2;
    sp50 = arg0->rot * f2;
    
    sp4c = sp98->f[0] + (sp64 * f2);
    sp48 = sp98->f[1] + (sp60 * f2);
    sp44 = sp98->f[2] + (sp5C * f2);

    vertices = dynAllocate7F0BD6C4(4);

    vertices[0] = spA0;
    vertices[1] = spA0;
    vertices[2] = spA0;
    vertices[3] = spA0;
    vertices[4] = spA0;

    sp8C.f[0] = sp9C->m[0][0] * sp54;
    sp8C.f[1] = sp9C->m[0][1] * sp54;
    sp8C.f[2] = sp9C->m[0][2] * sp54;

    sp80.f[0] = sp9C->m[0][0] * sp50;
    sp80.f[1] = sp9C->m[0][1] * sp50;
    sp80.f[2] = sp9C->m[0][2] * sp50;

    sp74.f[0] = sp9C->m[1][0] * sp54;
    sp74.f[1] = sp9C->m[1][1] * sp54;
    sp74.f[2] = sp9C->m[1][2] * sp54;

    sp68.f[0] = sp9C->m[1][0] * sp50;
    sp68.f[1] = sp9C->m[1][1] * sp50;
    sp68.f[2] = sp9C->m[1][2] * sp50;

    vertices[0].v.ob[0] = (sp4c - sp8C.f[0] - sp68.f[0]) * get_room_data_float1() - coord->f[0];
	vertices[0].v.ob[1] = (sp48 - sp8C.f[1] - sp68.f[1]) * get_room_data_float1() - coord->f[1];
	vertices[0].v.ob[2] = (sp44 - sp8C.f[2] - sp68.f[2]) * get_room_data_float1() - coord->f[2];
	vertices[0].v.tc[0] = 1760;
	vertices[0].v.tc[1] = 0;

	vertices[1].v.ob[0] = (sp4c + sp80.f[0] - sp74.f[0]) * get_room_data_float1() - coord->f[0];
	vertices[1].v.ob[1] = (sp48 + sp80.f[1] - sp74.f[1]) * get_room_data_float1() - coord->f[1];
	vertices[1].v.ob[2] = (sp44 + sp80.f[2] - sp74.f[2]) * get_room_data_float1() - coord->f[2];
	vertices[1].v.tc[0] = 0;
	vertices[1].v.tc[1] = 0;

	vertices[2].v.ob[0] = (sp4c + sp8C.f[0] + sp68.f[0]) * get_room_data_float1() - coord->f[0];
	vertices[2].v.ob[1] = (sp48 + sp8C.f[1] + sp68.f[1]) * get_room_data_float1() - coord->f[1];
	vertices[2].v.ob[2] = (sp44 + sp8C.f[2] + sp68.f[2]) * get_room_data_float1() - coord->f[2];
	vertices[2].v.tc[0] = 0;
	vertices[2].v.tc[1] = 1760;

	vertices[3].v.ob[0] = (sp4c - sp80.f[0] + sp74.f[0]) * get_room_data_float1() - coord->f[0];
	vertices[3].v.ob[1] = (sp48 - sp80.f[1] + sp74.f[1]) * get_room_data_float1() - coord->f[1];
	vertices[3].v.ob[2] = (sp44 - sp80.f[2] + sp74.f[2]) * get_room_data_float1() - coord->f[2];
	vertices[3].v.tc[0] = 1760;
	vertices[3].v.tc[1] = 1760;

    gSPVertex(gdl++, osVirtualToPhysical(vertices), 4, 0);

	gSP2Triangles(gdl++, 0, 1, 2, 0, 0, 2, 3, 0);

	return gdl;
}



/***
 * Perfect Dark Gfx *smokeRenderPart(struct smoke *smoke, struct smokepart *part, Gfx *gdl, struct coord *coord, f32 size)
 * 
 * NTSC address 0x7F09DDA4.
*/
Gfx *sub_GAME_7F09DDA4(struct Smoke *arg0, struct SmokePart *arg1, Gfx *arg2, struct coord3d *arg3)
{
    Vtx *vertices;
    Vtx spC0;
    Mtxf *mtx;
    struct coord3d spB0;
    struct coord3d spA4;
    struct coord3d sp98;
    struct coord3d sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    u8 sp77;
    struct coord3d *sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 temp_f0;
    f32 range;
    f32 mult;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    
    spC0 = D_80040910;

    mtx = currentPlayerGetMatrix10D4();
    sp70 = bondviewGetCurrentPlayersPosition();

    if (array_smoke_types[arg0->smoke_type].rateappear >= arg1->count)
    {
        sp77 = (arg1->alpha / (f32) array_smoke_types[arg0->smoke_type].rateappear) * arg1->count;
    }
    else
    {
        sp77 = arg1->alpha;
    }

    vertices = dynAllocate7F0BD6C4(4);

    vertices[0] = spC0;
    vertices[1] = spC0;
    vertices[2] = spC0;
    vertices[3] = spC0;

    sp88 = cosf(arg1->rot) * arg1->size;
    sp84 = sinf(arg1->rot) * arg1->size;

    sp80 = arg1->pos.f[0] + (sinf(arg1->offset1) * 7.0f);
    sp7C = arg1->pos.f[1];
    sp78 = arg1->pos.f[2] + (sinf(arg1->offset2) * 7.0f);

    sp6C = sp80 - sp70->f[0];
    sp68 = sp7C - sp70->f[1];
    sp64 = sp78 - sp70->f[2];

    temp_f0 = sqrtf((sp6C * sp6C) + (sp68 * sp68) + (sp64 * sp64));

    if (temp_f0 > 30000.0f)
    {
        return arg2;
    }

    range = temp_f0 * 0.5f;

	if (range > 100.0f) {
		range = 100.0f;
	}

	if (temp_f0 == 0.0f) {
		mult = 0.0f;
	} else {
		mult = (temp_f0 - range) / temp_f0;
	}

	sp88 = sp88 * mult;
	sp84 = sp84 * mult;

	sp80 = sp70->f[0] + sp6C * mult;
	sp7C = sp70->f[1] + sp68 * mult;
	sp78 = sp70->f[2] + sp64 * mult;

	spB0.f[0] = mtx->m[0][0] * sp88;
	spB0.f[1] = mtx->m[0][1] * sp88;
	spB0.f[2] = mtx->m[0][2] * sp88;
	spA4.f[0] = mtx->m[0][0] * sp84;
	spA4.f[1] = mtx->m[0][1] * sp84;
	spA4.f[2] = mtx->m[0][2] * sp84;
	sp98.f[0] = mtx->m[1][0] * sp88;
	sp98.f[1] = mtx->m[1][1] * sp88;
	sp98.f[2] = mtx->m[1][2] * sp88;
	sp8C.f[0] = mtx->m[1][0] * sp84;
	sp8C.f[1] = mtx->m[1][1] * sp84;
	sp8C.f[2] = mtx->m[1][2] * sp84;

    sp54 = ((sp80 - spB0.f[0] - sp8C.f[0]) * get_room_data_float1() - arg3->f[0]) * 10.0f;
	sp50 = ((sp7C - spB0.f[1] - sp8C.f[1]) * get_room_data_float1() - arg3->f[1]) * 10.0f;
	sp4C = ((sp78 - spB0.f[2] - sp8C.f[2]) * get_room_data_float1() - arg3->f[2]) * 10.0f;

    if (sp54 > 30000.0f
        || sp54 < -30000.0f
        || sp50 > 30000.0f
        || sp50 < -30000.0f
        || sp4C > 30000.0f
        || sp4C < -30000.0f)
    {
		return arg2;
	}

    vertices[0].v.ob[0] = sp54;
	vertices[0].v.ob[1] = sp50;
	vertices[0].v.ob[2] = sp4C;
	vertices[0].v.tc[0] = 1760;
	vertices[0].v.tc[1] = 0;
    vertices[0].v.cn[0] = array_smoke_types[arg0->smoke_type].r;
    vertices[0].v.cn[1] = array_smoke_types[arg0->smoke_type].g;
    vertices[0].v.cn[2] = array_smoke_types[arg0->smoke_type].b;
    vertices[0].v.cn[3] = sp77;

    vertices[1].v.ob[0] = ((((sp80 + spA4.f[0]) - sp98.f[0]) * get_room_data_float1()) - arg3->f[0]) * 10.0f;
    vertices[1].v.ob[1] = ((((sp7C + spA4.f[1]) - sp98.f[1]) * get_room_data_float1()) - arg3->f[1]) * 10.0f;
    vertices[1].v.ob[2] = ((((sp78 + spA4.f[2]) - sp98.f[2]) * get_room_data_float1()) - arg3->f[2]) * 10.0f;
    vertices[1].v.tc[0] = 0;
    vertices[1].v.tc[1] = 0;
    vertices[1].v.cn[0] = array_smoke_types[arg0->smoke_type].r;
    vertices[1].v.cn[1] = array_smoke_types[arg0->smoke_type].g;
    vertices[1].v.cn[2] = array_smoke_types[arg0->smoke_type].b;
    vertices[1].v.cn[3] = sp77;
    
    vertices[2].v.ob[0] = (((sp80 + spB0.f[0] + sp8C.f[0]) * get_room_data_float1()) - arg3->f[0]) * 10.0f;
    vertices[2].v.ob[1] = (((sp7C + spB0.f[1] + sp8C.f[1]) * get_room_data_float1()) - arg3->f[1]) * 10.0f;
    vertices[2].v.ob[2] = (((sp78 + spB0.f[2] + sp8C.f[2]) * get_room_data_float1()) - arg3->f[2]) * 10.0f;
    vertices[2].v.tc[0] = 0;
    vertices[2].v.tc[1] = 1760;
    vertices[2].v.cn[0] = array_smoke_types[arg0->smoke_type].r;
    vertices[2].v.cn[1] = array_smoke_types[arg0->smoke_type].g;
    vertices[2].v.cn[2] = array_smoke_types[arg0->smoke_type].b;
    vertices[2].v.cn[3] = sp77;
    
    vertices[3].v.ob[0] = ((((sp80 - spA4.f[0]) + sp98.f[0]) * get_room_data_float1()) - arg3->f[0]) * 10.0f;
    vertices[3].v.ob[1] = ((((sp7C - spA4.f[1]) + sp98.f[1]) * get_room_data_float1()) - arg3->f[1]) * 10.0f;
    vertices[3].v.ob[2] = ((((sp78 - spA4.f[2]) + sp98.f[2]) * get_room_data_float1()) - arg3->f[2]) * 10.0f;
    vertices[3].v.tc[0] = 1760;
    vertices[3].v.tc[1] = 1760;
    vertices[3].v.cn[0] = array_smoke_types[arg0->smoke_type].r;
    vertices[3].v.cn[1] = array_smoke_types[arg0->smoke_type].g;
    vertices[3].v.cn[2] = array_smoke_types[arg0->smoke_type].b;
    vertices[3].v.cn[3] = sp77;

    gSPVertex(arg2++, osVirtualToPhysical(vertices), 4, 0);

	gSP2Triangles(arg2++, 0, 1, 2, 0, 0, 2, 3, 0);

	return arg2;
}


void sub_GAME_7F09E700(coord3d *pos, StandTile *stan, s16 arg2, u8 *rooms, s32 arg4)
{
    struct Smoke *smoke;
    struct Smoke *smoke_tmp;
    s32 i;
    s32 player_count;
    PropRecord *prop;

    smoke = NULL;
    player_count = getPlayerCount();

    for (i = 0; i < 20; i++)
    {
        if (ptr_smoke_buf[i].prop == NULL)
        {
            smoke = &ptr_smoke_buf[i];
            break;
        }
        else if (player_count >= 2)
        {
            smoke_tmp = (i + ptr_smoke_buf);
            if (((smoke_tmp->smoke_type != 7) && (smoke_tmp->smoke_type != 8)) && (smoke_tmp->smoke_type != 9))
            {
                smoke_tmp->duration = (s16) array_smoke_types[smoke_tmp->smoke_type].duration;
            }
        }
    }

    if (smoke == NULL) { return; }

    prop = chrpropAllocate();
    if (prop == NULL) { return; }

    prop->type = 8;
    prop->flags |= 2;
    prop->smoke = smoke;
    prop->stan = stan;
    prop->pos.x = pos->x;
    prop->pos.y = pos->y;
    prop->pos.z = pos->z;

    for (i = 0; (rooms[i] != 0xFF) && (i < 7); i++)
    {
        prop->rooms[i] = rooms[i];
    }
    prop->rooms[i] = 0xFF;

    if (arg4 != 0)
    {
        prop->flags |= 8;
    }

    chrpropActivateThisFrame(prop);
    chrpropEnable(prop);
    smoke->prop = prop;
    smoke->duration = 0;
    smoke->smoke_type = arg2;
}


#ifdef NONMATCHING
void sub_GAME_7F09E8AC(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800576CC
.word 0x3e19999a /*0.15000001*/
glabel D_800576D0
.word 0x3e99999a /*0.30000001*/
glabel D_800576D4
.word 0x3c23d70a /*0.0099999998*/
glabel D_800576D8
.word 0x3ca3d70a /*0.02*/
glabel D_800576DC
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F09E8AC
/* 0D33DC 7F09E8AC 27BDFF30 */  addiu $sp, $sp, -0xd0
/* 0D33E0 7F09E8B0 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0D33E4 7F09E8B4 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0D33E8 7F09E8B8 AFBF006C */  sw    $ra, 0x6c($sp)
/* 0D33EC 7F09E8BC AFBE0068 */  sw    $fp, 0x68($sp)
/* 0D33F0 7F09E8C0 AFB70064 */  sw    $s7, 0x64($sp)
/* 0D33F4 7F09E8C4 AFB60060 */  sw    $s6, 0x60($sp)
/* 0D33F8 7F09E8C8 AFB5005C */  sw    $s5, 0x5c($sp)
/* 0D33FC 7F09E8CC AFB40058 */  sw    $s4, 0x58($sp)
/* 0D3400 7F09E8D0 AFB30054 */  sw    $s3, 0x54($sp)
/* 0D3404 7F09E8D4 AFB20050 */  sw    $s2, 0x50($sp)
/* 0D3408 7F09E8D8 AFB1004C */  sw    $s1, 0x4c($sp)
/* 0D340C 7F09E8DC AFB00048 */  sw    $s0, 0x48($sp)
/* 0D3410 7F09E8E0 F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0D3414 7F09E8E4 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0D3418 7F09E8E8 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0D341C 7F09E8EC F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D3420 7F09E8F0 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D3424 7F09E8F4 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D3428 7F09E8F8 0080B825 */  move  $s7, $a0
/* 0D342C 7F09E8FC 14400003 */  bnez  $v0, .L7F09E90C
/* 0D3430 7F09E900 8C930004 */   lw    $s3, 4($a0)
/* 0D3434 7F09E904 10000193 */  b     .L7F09EF54
/* 0D3438 7F09E908 00001025 */   move  $v0, $zero
.L7F09E90C:
/* 0D343C 7F09E90C 2841000F */  slti  $at, $v0, 0xf
/* 0D3440 7F09E910 50200005 */  beql  $at, $zero, .L7F09E928
/* 0D3444 7F09E914 3C014170 */   lui   $at, 0x4170
/* 0D3448 7F09E918 44822000 */  mtc1  $v0, $f4
/* 0D344C 7F09E91C 10000004 */  b     .L7F09E930
/* 0D3450 7F09E920 46802020 */   cvt.s.w $f0, $f4
/* 0D3454 7F09E924 3C014170 */  li    $at, 0x41700000 # 15.000000
.L7F09E928:
/* 0D3458 7F09E928 44810000 */  mtc1  $at, $f0
/* 0D345C 7F09E92C 00000000 */  nop
.L7F09E930:
/* 0D3460 7F09E930 4600018D */  trunc.w.s $f6, $f0
/* 0D3464 7F09E934 3C158004 */  lui   $s5, %hi(array_smoke_types)
/* 0D3468 7F09E938 26B5017C */  addiu $s5, %lo(array_smoke_types) # addiu $s5, $s5, 0x17c
/* 0D346C 7F09E93C 0000F025 */  move  $fp, $zero
/* 0D3470 7F09E940 440F3000 */  mfc1  $t7, $f6
/* 0D3474 7F09E944 3C018005 */  lui   $at, %hi(D_800576CC)
/* 0D3478 7F09E948 24160018 */  li    $s6, 24
/* 0D347C 7F09E94C 19E000FD */  blez  $t7, .L7F09ED44
/* 0D3480 7F09E950 AFAF008C */   sw    $t7, 0x8c($sp)
/* 0D3484 7F09E954 C43E76CC */  lwc1  $f30, %lo(D_800576CC)($at)
/* 0D3488 7F09E958 3C018005 */  lui    $at, %hi(D_800576D0)
/* 0D348C 7F09E95C C43C76D0 */  lwc1  $f28, %lo(D_800576D0)($at)
/* 0D3490 7F09E960 3C018005 */  lui    $at, %hi(D_800576D4)
/* 0D3494 7F09E964 C43876D4 */  lwc1  $f24, %lo(D_800576D4)($at)
/* 0D3498 7F09E968 3C018005 */  lui    $at, %hi(D_800576D8)
/* 0D349C 7F09E96C C43676D8 */  lwc1  $f22, %lo(D_800576D8)($at)
/* 0D34A0 7F09E970 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D34A4 7F09E974 4481A000 */  mtc1  $at, $f20
/* 0D34A8 7F09E978 4480D000 */  mtc1  $zero, $f26
/* 0D34AC 7F09E97C 24140190 */  li    $s4, 400
/* 0D34B0 7F09E980 86790004 */  lh    $t9, 4($s3)
.L7F09E984:
/* 0D34B4 7F09E984 00001025 */  move  $v0, $zero
/* 0D34B8 7F09E988 00009025 */  move  $s2, $zero
/* 0D34BC 7F09E98C 27280001 */  addiu $t0, $t9, 1
/* 0D34C0 7F09E990 A6680004 */  sh    $t0, 4($s3)
/* 0D34C4 7F09E994 02608825 */  move  $s1, $s3
.L7F09E998:
/* 0D34C8 7F09E998 C6280014 */  lwc1  $f8, 0x14($s1)
/* 0D34CC 7F09E99C 4608D032 */  c.eq.s $f26, $f8
/* 0D34D0 7F09E9A0 00000000 */  nop
/* 0D34D4 7F09E9A4 4503003C */  bc1tl .L7F09EA98
/* 0D34D8 7F09E9A8 26520028 */   addiu $s2, $s2, 0x28
/* 0D34DC 7F09E9AC 26300008 */  addiu $s0, $s1, 8
/* 0D34E0 7F09E9B0 C60A0004 */  lwc1  $f10, 4($s0)
/* 0D34E4 7F09E9B4 C612000C */  lwc1  $f18, 0xc($s0)
/* 0D34E8 7F09E9B8 C6060020 */  lwc1  $f6, 0x20($s0)
/* 0D34EC 7F09E9BC 461C5400 */  add.s $f16, $f10, $f28
/* 0D34F0 7F09E9C0 860C0024 */  lh    $t4, 0x24($s0)
/* 0D34F4 7F09E9C4 461E9100 */  add.s $f4, $f18, $f30
/* 0D34F8 7F09E9C8 E6100004 */  swc1  $f16, 4($s0)
/* 0D34FC 7F09E9CC C6100010 */  lwc1  $f16, 0x10($s0)
/* 0D3500 7F09E9D0 C6120014 */  lwc1  $f18, 0x14($s0)
/* 0D3504 7F09E9D4 E604000C */  swc1  $f4, 0xc($s0)
/* 0D3508 7F09E9D8 86690006 */  lh    $t1, 6($s3)
/* 0D350C 7F09E9DC 46128100 */  add.s $f4, $f16, $f18
/* 0D3510 7F09E9E0 258D0001 */  addiu $t5, $t4, 1
/* 0D3514 7F09E9E4 01360019 */  multu $t1, $s6
/* 0D3518 7F09E9E8 00005012 */  mflo  $t2
/* 0D351C 7F09E9EC 02AA5821 */  addu  $t3, $s5, $t2
/* 0D3520 7F09E9F0 C5680010 */  lwc1  $f8, 0x10($t3)
/* 0D3524 7F09E9F4 A60D0024 */  sh    $t5, 0x24($s0)
/* 0D3528 7F09E9F8 E6040010 */  swc1  $f4, 0x10($s0)
/* 0D352C 7F09E9FC 46083281 */  sub.s $f10, $f6, $f8
/* 0D3530 7F09EA00 0C002914 */  jal   randomGetNext
/* 0D3534 7F09EA04 E60A0020 */   swc1  $f10, 0x20($s0)
/* 0D3538 7F09EA08 44824000 */  mtc1  $v0, $f8
/* 0D353C 7F09EA0C C6060018 */  lwc1  $f6, 0x18($s0)
/* 0D3540 7F09EA10 04410005 */  bgez  $v0, .L7F09EA28
/* 0D3544 7F09EA14 468042A0 */   cvt.s.w $f10, $f8
/* 0D3548 7F09EA18 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D354C 7F09EA1C 44818000 */  mtc1  $at, $f16
/* 0D3550 7F09EA20 00000000 */  nop
/* 0D3554 7F09EA24 46105280 */  add.s $f10, $f10, $f16
.L7F09EA28:
/* 0D3558 7F09EA28 46145482 */  mul.s $f18, $f10, $f20
/* 0D355C 7F09EA2C 00000000 */  nop
/* 0D3560 7F09EA30 46189102 */  mul.s $f4, $f18, $f24
/* 0D3564 7F09EA34 4604B200 */  add.s $f8, $f22, $f4
/* 0D3568 7F09EA38 46083400 */  add.s $f16, $f6, $f8
/* 0D356C 7F09EA3C 0C002914 */  jal   randomGetNext
/* 0D3570 7F09EA40 E6100018 */   swc1  $f16, 0x18($s0)
/* 0D3574 7F09EA44 44829000 */  mtc1  $v0, $f18
/* 0D3578 7F09EA48 C60A001C */  lwc1  $f10, 0x1c($s0)
/* 0D357C 7F09EA4C 04410005 */  bgez  $v0, .L7F09EA64
/* 0D3580 7F09EA50 46809120 */   cvt.s.w $f4, $f18
/* 0D3584 7F09EA54 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3588 7F09EA58 44813000 */  mtc1  $at, $f6
/* 0D358C 7F09EA5C 00000000 */  nop
/* 0D3590 7F09EA60 46062100 */  add.s $f4, $f4, $f6
.L7F09EA64:
/* 0D3594 7F09EA64 46142202 */  mul.s $f8, $f4, $f20
/* 0D3598 7F09EA68 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D359C 7F09EA6C C6040020 */  lwc1  $f4, 0x20($s0)
/* 0D35A0 7F09EA70 46184402 */  mul.s $f16, $f8, $f24
/* 0D35A4 7F09EA74 44814000 */  mtc1  $at, $f8
/* 0D35A8 7F09EA78 00000000 */  nop
/* 0D35AC 7F09EA7C 4608203C */  c.lt.s $f4, $f8
/* 0D35B0 7F09EA80 4610B480 */  add.s $f18, $f22, $f16
/* 0D35B4 7F09EA84 46125180 */  add.s $f6, $f10, $f18
/* 0D35B8 7F09EA88 45000002 */  bc1f  .L7F09EA94
/* 0D35BC 7F09EA8C E606001C */   swc1  $f6, 0x1c($s0)
/* 0D35C0 7F09EA90 E61A000C */  swc1  $f26, 0xc($s0)
.L7F09EA94:
/* 0D35C4 7F09EA94 26520028 */  addiu $s2, $s2, 0x28
.L7F09EA98:
/* 0D35C8 7F09EA98 2A410190 */  slti  $at, $s2, 0x190
/* 0D35CC 7F09EA9C 1420FFBE */  bnez  $at, .L7F09E998
/* 0D35D0 7F09EAA0 26310028 */   addiu $s1, $s1, 0x28
/* 0D35D4 7F09EAA4 866E0006 */  lh    $t6, 6($s3)
/* 0D35D8 7F09EAA8 86630004 */  lh    $v1, 4($s3)
/* 0D35DC 7F09EAAC 01D60019 */  multu $t6, $s6
/* 0D35E0 7F09EAB0 00007812 */  mflo  $t7
/* 0D35E4 7F09EAB4 02AF2021 */  addu  $a0, $s5, $t7
/* 0D35E8 7F09EAB8 84980000 */  lh    $t8, ($a0)
/* 0D35EC 7F09EABC 0078082A */  slt   $at, $v1, $t8
/* 0D35F0 7F09EAC0 5020009D */  beql  $at, $zero, .L7F09ED38
/* 0D35F4 7F09EAC4 8FAB008C */   lw    $t3, 0x8c($sp)
/* 0D35F8 7F09EAC8 84990004 */  lh    $t9, 4($a0)
/* 0D35FC 7F09EACC 00009025 */  move  $s2, $zero
/* 0D3600 7F09EAD0 02608825 */  move  $s1, $s3
/* 0D3604 7F09EAD4 0079001A */  div   $zero, $v1, $t9
/* 0D3608 7F09EAD8 17200002 */  bnez  $t9, .L7F09EAE4
/* 0D360C 7F09EADC 00000000 */   nop
/* 0D3610 7F09EAE0 0007000D */  break 7
.L7F09EAE4:
/* 0D3614 7F09EAE4 2401FFFF */  li    $at, -1
/* 0D3618 7F09EAE8 17210004 */  bne   $t9, $at, .L7F09EAFC
/* 0D361C 7F09EAEC 3C018000 */   li    $at, 0x80000000 # -0.000000
/* 0D3620 7F09EAF0 14610002 */  bne   $v1, $at, .L7F09EAFC
/* 0D3624 7F09EAF4 00000000 */   nop
/* 0D3628 7F09EAF8 0006000D */  break 6
.L7F09EAFC:
/* 0D362C 7F09EAFC 24010001 */  li    $at, 1
/* 0D3630 7F09EB00 00004010 */  mfhi  $t0
/* 0D3634 7F09EB04 5501008C */  bnel  $t0, $at, .L7F09ED38
/* 0D3638 7F09EB08 8FAB008C */   lw    $t3, 0x8c($sp)
.L7F09EB0C:
/* 0D363C 7F09EB0C C6300014 */  lwc1  $f16, 0x14($s1)
/* 0D3640 7F09EB10 26520028 */  addiu $s2, $s2, 0x28
/* 0D3644 7F09EB14 4610D032 */  c.eq.s $f26, $f16
/* 0D3648 7F09EB18 00000000 */  nop
/* 0D364C 7F09EB1C 45000083 */  bc1f  .L7F09ED2C
/* 0D3650 7F09EB20 00000000 */   nop
/* 0D3654 7F09EB24 0C002914 */  jal   randomGetNext
/* 0D3658 7F09EB28 00000000 */   nop
/* 0D365C 7F09EB2C 44825000 */  mtc1  $v0, $f10
/* 0D3660 7F09EB30 26300008 */  addiu $s0, $s1, 8
/* 0D3664 7F09EB34 04410005 */  bgez  $v0, .L7F09EB4C
/* 0D3668 7F09EB38 468054A0 */   cvt.s.w $f18, $f10
/* 0D366C 7F09EB3C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3670 7F09EB40 44813000 */  mtc1  $at, $f6
/* 0D3674 7F09EB44 00000000 */  nop
/* 0D3678 7F09EB48 46069480 */  add.s $f18, $f18, $f6
.L7F09EB4C:
/* 0D367C 7F09EB4C 86690006 */  lh    $t1, 6($s3)
/* 0D3680 7F09EB50 46149102 */  mul.s $f4, $f18, $f20
/* 0D3684 7F09EB54 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D3688 7F09EB58 01360019 */  multu $t1, $s6
/* 0D368C 7F09EB5C 44814000 */  mtc1  $at, $f8
/* 0D3690 7F09EB60 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D3694 7F09EB64 44815000 */  mtc1  $at, $f10
/* 0D3698 7F09EB68 46082402 */  mul.s $f16, $f4, $f8
/* 0D369C 7F09EB6C 00005012 */  mflo  $t2
/* 0D36A0 7F09EB70 02AA5821 */  addu  $t3, $s5, $t2
/* 0D36A4 7F09EB74 856C0006 */  lh    $t4, 6($t3)
/* 0D36A8 7F09EB78 460A8180 */  add.s $f6, $f16, $f10
/* 0D36AC 7F09EB7C 448C9000 */  mtc1  $t4, $f18
/* 0D36B0 7F09EB80 00000000 */  nop
/* 0D36B4 7F09EB84 46809120 */  cvt.s.w $f4, $f18
/* 0D36B8 7F09EB88 46043202 */  mul.s $f8, $f6, $f4
/* 0D36BC 7F09EB8C 0C002914 */  jal   randomGetNext
/* 0D36C0 7F09EB90 E608000C */   swc1  $f8, 0xc($s0)
/* 0D36C4 7F09EB94 24010046 */  li    $at, 70
/* 0D36C8 7F09EB98 0041001B */  divu  $zero, $v0, $at
/* 0D36CC 7F09EB9C 00006810 */  mfhi  $t5
/* 0D36D0 7F09EBA0 448D8000 */  mtc1  $t5, $f16
/* 0D36D4 7F09EBA4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D36D8 7F09EBA8 05A10004 */  bgez  $t5, .L7F09EBBC
/* 0D36DC 7F09EBAC 468082A0 */   cvt.s.w $f10, $f16
/* 0D36E0 7F09EBB0 44819000 */  mtc1  $at, $f18
/* 0D36E4 7F09EBB4 00000000 */  nop
/* 0D36E8 7F09EBB8 46125280 */  add.s $f10, $f10, $f18
.L7F09EBBC:
/* 0D36EC 7F09EBBC 3C0142DC */  li    $at, 0x42DC0000 # 110.000000
/* 0D36F0 7F09EBC0 44813000 */  mtc1  $at, $f6
/* 0D36F4 7F09EBC4 A6000024 */  sh    $zero, 0x24($s0)
/* 0D36F8 7F09EBC8 46065100 */  add.s $f4, $f10, $f6
/* 0D36FC 7F09EBCC 0C002914 */  jal   randomGetNext
/* 0D3700 7F09EBD0 E6040020 */   swc1  $f4, 0x20($s0)
/* 0D3704 7F09EBD4 44824000 */  mtc1  $v0, $f8
/* 0D3708 7F09EBD8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D370C 7F09EBDC 04410004 */  bgez  $v0, .L7F09EBF0
/* 0D3710 7F09EBE0 46804420 */   cvt.s.w $f16, $f8
/* 0D3714 7F09EBE4 44819000 */  mtc1  $at, $f18
/* 0D3718 7F09EBE8 00000000 */  nop
/* 0D371C 7F09EBEC 46128400 */  add.s $f16, $f16, $f18
.L7F09EBF0:
/* 0D3720 7F09EBF0 46148282 */  mul.s $f10, $f16, $f20
/* 0D3724 7F09EBF4 3C018005 */  lui    $at, %hi(D_800576DC)
/* 0D3728 7F09EBF8 C42676DC */  lwc1  $f6, %lo(D_800576DC)($at)
/* 0D372C 7F09EBFC 46065102 */  mul.s $f4, $f10, $f6
/* 0D3730 7F09EC00 0C002914 */  jal   randomGetNext
/* 0D3734 7F09EC04 E6040010 */   swc1  $f4, 0x10($s0)
/* 0D3738 7F09EC08 44829000 */  mtc1  $v0, $f18
/* 0D373C 7F09EC0C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D3740 7F09EC10 44814000 */  mtc1  $at, $f8
/* 0D3744 7F09EC14 04410005 */  bgez  $v0, .L7F09EC2C
/* 0D3748 7F09EC18 46809420 */   cvt.s.w $f16, $f18
/* 0D374C 7F09EC1C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D3750 7F09EC20 44815000 */  mtc1  $at, $f10
/* 0D3754 7F09EC24 00000000 */  nop
/* 0D3758 7F09EC28 460A8400 */  add.s $f16, $f16, $f10
.L7F09EC2C:
/* 0D375C 7F09EC2C 866E0006 */  lh    $t6, 6($s3)
/* 0D3760 7F09EC30 46148182 */  mul.s $f6, $f16, $f20
/* 0D3764 7F09EC34 46064101 */  sub.s $f4, $f8, $f6
/* 0D3768 7F09EC38 01D60019 */  multu $t6, $s6
/* 0D376C 7F09EC3C 00007812 */  mflo  $t7
/* 0D3770 7F09EC40 02AFC021 */  addu  $t8, $s5, $t7
/* 0D3774 7F09EC44 C7120008 */  lwc1  $f18, 8($t8)
/* 0D3778 7F09EC48 46049282 */  mul.s $f10, $f18, $f4
/* 0D377C 7F09EC4C E60A0014 */  swc1  $f10, 0x14($s0)
/* 0D3780 7F09EC50 C6F00008 */  lwc1  $f16, 8($s7)
/* 0D3784 7F09EC54 E6100000 */  swc1  $f16, ($s0)
/* 0D3788 7F09EC58 C6E8000C */  lwc1  $f8, 0xc($s7)
/* 0D378C 7F09EC5C E6080004 */  swc1  $f8, 4($s0)
/* 0D3790 7F09EC60 C6E60010 */  lwc1  $f6, 0x10($s7)
/* 0D3794 7F09EC64 0C002914 */  jal   randomGetNext
/* 0D3798 7F09EC68 E6060008 */   swc1  $f6, 8($s0)
/* 0D379C 7F09EC6C 44829000 */  mtc1  $v0, $f18
/* 0D37A0 7F09EC70 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D37A4 7F09EC74 04410004 */  bgez  $v0, .L7F09EC88
/* 0D37A8 7F09EC78 46809120 */   cvt.s.w $f4, $f18
/* 0D37AC 7F09EC7C 44815000 */  mtc1  $at, $f10
/* 0D37B0 7F09EC80 00000000 */  nop
/* 0D37B4 7F09EC84 460A2100 */  add.s $f4, $f4, $f10
.L7F09EC88:
/* 0D37B8 7F09EC88 46142402 */  mul.s $f16, $f4, $f20
/* 0D37BC 7F09EC8C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D37C0 7F09EC90 44814000 */  mtc1  $at, $f8
/* 0D37C4 7F09EC94 00000000 */  nop
/* 0D37C8 7F09EC98 46088182 */  mul.s $f6, $f16, $f8
/* 0D37CC 7F09EC9C 0C002914 */  jal   randomGetNext
/* 0D37D0 7F09ECA0 E6060018 */   swc1  $f6, 0x18($s0)
/* 0D37D4 7F09ECA4 44829000 */  mtc1  $v0, $f18
/* 0D37D8 7F09ECA8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D37DC 7F09ECAC 04410004 */  bgez  $v0, .L7F09ECC0
/* 0D37E0 7F09ECB0 468092A0 */   cvt.s.w $f10, $f18
/* 0D37E4 7F09ECB4 44812000 */  mtc1  $at, $f4
/* 0D37E8 7F09ECB8 00000000 */  nop
/* 0D37EC 7F09ECBC 46045280 */  add.s $f10, $f10, $f4
.L7F09ECC0:
/* 0D37F0 7F09ECC0 46145402 */  mul.s $f16, $f10, $f20
/* 0D37F4 7F09ECC4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D37F8 7F09ECC8 44814000 */  mtc1  $at, $f8
/* 0D37FC 7F09ECCC 00000000 */  nop
/* 0D3800 7F09ECD0 46088182 */  mul.s $f6, $f16, $f8
/* 0D3804 7F09ECD4 E606001C */  swc1  $f6, 0x1c($s0)
/* 0D3808 7F09ECD8 86790006 */  lh    $t9, 6($s3)
/* 0D380C 7F09ECDC 86630004 */  lh    $v1, 4($s3)
/* 0D3810 7F09ECE0 03360019 */  multu $t9, $s6
/* 0D3814 7F09ECE4 00004012 */  mflo  $t0
/* 0D3818 7F09ECE8 02A82021 */  addu  $a0, $s5, $t0
/* 0D381C 7F09ECEC 84850000 */  lh    $a1, ($a0)
/* 0D3820 7F09ECF0 84860014 */  lh    $a2, 0x14($a0)
/* 0D3824 7F09ECF4 00A64823 */  subu  $t1, $a1, $a2
/* 0D3828 7F09ECF8 0123082A */  slt   $at, $t1, $v1
/* 0D382C 7F09ECFC 5020000E */  beql  $at, $zero, .L7F09ED38
/* 0D3830 7F09ED00 8FAB008C */   lw    $t3, 0x8c($sp)
/* 0D3834 7F09ED04 00A35023 */  subu  $t2, $a1, $v1
/* 0D3838 7F09ED08 448A9000 */  mtc1  $t2, $f18
/* 0D383C 7F09ED0C 44865000 */  mtc1  $a2, $f10
/* 0D3840 7F09ED10 C6060020 */  lwc1  $f6, 0x20($s0)
/* 0D3844 7F09ED14 46809120 */  cvt.s.w $f4, $f18
/* 0D3848 7F09ED18 46805420 */  cvt.s.w $f16, $f10
/* 0D384C 7F09ED1C 46102203 */  div.s $f8, $f4, $f16
/* 0D3850 7F09ED20 46083482 */  mul.s $f18, $f6, $f8
/* 0D3854 7F09ED24 10000003 */  b     .L7F09ED34
/* 0D3858 7F09ED28 E6120020 */   swc1  $f18, 0x20($s0)
.L7F09ED2C:
/* 0D385C 7F09ED2C 1654FF77 */  bne   $s2, $s4, .L7F09EB0C
/* 0D3860 7F09ED30 26310028 */   addiu $s1, $s1, 0x28
.L7F09ED34:
/* 0D3864 7F09ED34 8FAB008C */  lw    $t3, 0x8c($sp)
.L7F09ED38:
/* 0D3868 7F09ED38 27DE0001 */  addiu $fp, $fp, 1
/* 0D386C 7F09ED3C 57CBFF11 */  bnel  $fp, $t3, .L7F09E984
/* 0D3870 7F09ED40 86790004 */   lh    $t9, 4($s3)
.L7F09ED44:
/* 0D3874 7F09ED44 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D3878 7F09ED48 44812000 */  mtc1  $at, $f4
/* 0D387C 7F09ED4C C6EA0008 */  lwc1  $f10, 8($s7)
/* 0D3880 7F09ED50 44814000 */  mtc1  $at, $f8
/* 0D3884 7F09ED54 4480D000 */  mtc1  $zero, $f26
/* 0D3888 7F09ED58 46045401 */  sub.s $f16, $f10, $f4
/* 0D388C 7F09ED5C 44812000 */  mtc1  $at, $f4
/* 0D3890 7F09ED60 3C158004 */  lui   $s5, %hi(array_smoke_types)
/* 0D3894 7F09ED64 26B5017C */  addiu $s5, %lo(array_smoke_types) # addiu $s5, $s5, 0x17c
/* 0D3898 7F09ED68 E7B000A8 */  swc1  $f16, 0xa8($sp)
/* 0D389C 7F09ED6C C6E6000C */  lwc1  $f6, 0xc($s7)
/* 0D38A0 7F09ED70 24160018 */  li    $s6, 24
/* 0D38A4 7F09ED74 00009025 */  move  $s2, $zero
/* 0D38A8 7F09ED78 46083481 */  sub.s $f18, $f6, $f8
/* 0D38AC 7F09ED7C 44814000 */  mtc1  $at, $f8
/* 0D38B0 7F09ED80 02608825 */  move  $s1, $s3
/* 0D38B4 7F09ED84 27B0009C */  addiu $s0, $sp, 0x9c
/* 0D38B8 7F09ED88 E7B200AC */  swc1  $f18, 0xac($sp)
/* 0D38BC 7F09ED8C C6EA0010 */  lwc1  $f10, 0x10($s7)
/* 0D38C0 7F09ED90 27A600B4 */  addiu $a2, $sp, 0xb4
/* 0D38C4 7F09ED94 4600D386 */  mov.s $f14, $f26
/* 0D38C8 7F09ED98 46045401 */  sub.s $f16, $f10, $f4
/* 0D38CC 7F09ED9C 44812000 */  mtc1  $at, $f4
/* 0D38D0 7F09EDA0 E7B000B0 */  swc1  $f16, 0xb0($sp)
/* 0D38D4 7F09EDA4 C6E60008 */  lwc1  $f6, 8($s7)
/* 0D38D8 7F09EDA8 46083480 */  add.s $f18, $f6, $f8
/* 0D38DC 7F09EDAC 44814000 */  mtc1  $at, $f8
/* 0D38E0 7F09EDB0 E7B2009C */  swc1  $f18, 0x9c($sp)
/* 0D38E4 7F09EDB4 C6EA000C */  lwc1  $f10, 0xc($s7)
/* 0D38E8 7F09EDB8 46045400 */  add.s $f16, $f10, $f4
/* 0D38EC 7F09EDBC E7B000A0 */  swc1  $f16, 0xa0($sp)
/* 0D38F0 7F09EDC0 C6E60010 */  lwc1  $f6, 0x10($s7)
/* 0D38F4 7F09EDC4 46083480 */  add.s $f18, $f6, $f8
/* 0D38F8 7F09EDC8 E7B200A4 */  swc1  $f18, 0xa4($sp)
.L7F09EDCC:
/* 0D38FC 7F09EDCC C62A0014 */  lwc1  $f10, 0x14($s1)
/* 0D3900 7F09EDD0 26520028 */  addiu $s2, $s2, 0x28
/* 0D3904 7F09EDD4 2A410190 */  slti  $at, $s2, 0x190
/* 0D3908 7F09EDD8 460AD032 */  c.eq.s $f26, $f10
/* 0D390C 7F09EDDC 00002025 */  move  $a0, $zero
/* 0D3910 7F09EDE0 02202825 */  move  $a1, $s1
/* 0D3914 7F09EDE4 27A200A8 */  addiu $v0, $sp, 0xa8
/* 0D3918 7F09EDE8 45010016 */  bc1t  .L7F09EE44
/* 0D391C 7F09EDEC 00000000 */   nop
.L7F09EDF0:
/* 0D3920 7F09EDF0 C4A40008 */  lwc1  $f4, 8($a1)
/* 0D3924 7F09EDF4 C6300014 */  lwc1  $f16, 0x14($s1)
/* 0D3928 7F09EDF8 C4460000 */  lwc1  $f6, ($v0)
/* 0D392C 7F09EDFC 24A50004 */  addiu $a1, $a1, 4
/* 0D3930 7F09EE00 46102001 */  sub.s $f0, $f4, $f16
/* 0D3934 7F09EE04 02041821 */  addu  $v1, $s0, $a0
/* 0D3938 7F09EE08 4606003C */  c.lt.s $f0, $f6
/* 0D393C 7F09EE0C 00000000 */  nop
/* 0D3940 7F09EE10 45020004 */  bc1fl .L7F09EE24
/* 0D3944 7F09EE14 C4680000 */   lwc1  $f8, ($v1)
/* 0D3948 7F09EE18 10000007 */  b     .L7F09EE38
/* 0D394C 7F09EE1C E4400000 */   swc1  $f0, ($v0)
/* 0D3950 7F09EE20 C4680000 */  lwc1  $f8, ($v1)
.L7F09EE24:
/* 0D3954 7F09EE24 4600403C */  c.lt.s $f8, $f0
/* 0D3958 7F09EE28 00000000 */  nop
/* 0D395C 7F09EE2C 45020003 */  bc1fl .L7F09EE3C
/* 0D3960 7F09EE30 24420004 */   addiu $v0, $v0, 4
/* 0D3964 7F09EE34 E4600000 */  swc1  $f0, ($v1)
.L7F09EE38:
/* 0D3968 7F09EE38 24420004 */  addiu $v0, $v0, 4
.L7F09EE3C:
/* 0D396C 7F09EE3C 1446FFEC */  bne   $v0, $a2, .L7F09EDF0
/* 0D3970 7F09EE40 24840004 */   addiu $a0, $a0, 4
.L7F09EE44:
/* 0D3974 7F09EE44 1420FFE1 */  bnez  $at, .L7F09EDCC
/* 0D3978 7F09EE48 26310028 */   addiu $s1, $s1, 0x28
/* 0D397C 7F09EE4C C6E00008 */  lwc1  $f0, 8($s7)
/* 0D3980 7F09EE50 C7B200A8 */  lwc1  $f18, 0xa8($sp)
/* 0D3984 7F09EE54 C7AA00B0 */  lwc1  $f10, 0xb0($sp)
/* 0D3988 7F09EE58 C7A4009C */  lwc1  $f4, 0x9c($sp)
/* 0D398C 7F09EE5C 46120081 */  sub.s $f2, $f0, $f18
/* 0D3990 7F09EE60 C7B000A4 */  lwc1  $f16, 0xa4($sp)
/* 0D3994 7F09EE64 02E02025 */  move  $a0, $s7
/* 0D3998 7F09EE68 27A500A8 */  addiu $a1, $sp, 0xa8
/* 0D399C 7F09EE6C 4602D03C */  c.lt.s $f26, $f2
/* 0D39A0 7F09EE70 00000000 */  nop
/* 0D39A4 7F09EE74 45020003 */  bc1fl .L7F09EE84
/* 0D39A8 7F09EE78 C6E20010 */   lwc1  $f2, 0x10($s7)
/* 0D39AC 7F09EE7C 46001386 */  mov.s $f14, $f2
/* 0D39B0 7F09EE80 C6E20010 */  lwc1  $f2, 0x10($s7)
.L7F09EE84:
/* 0D39B4 7F09EE84 460A1301 */  sub.s $f12, $f2, $f10
/* 0D39B8 7F09EE88 460C703C */  c.lt.s $f14, $f12
/* 0D39BC 7F09EE8C 00000000 */  nop
/* 0D39C0 7F09EE90 45020003 */  bc1fl .L7F09EEA0
/* 0D39C4 7F09EE94 46002301 */   sub.s $f12, $f4, $f0
/* 0D39C8 7F09EE98 46006386 */  mov.s $f14, $f12
/* 0D39CC 7F09EE9C 46002301 */  sub.s $f12, $f4, $f0
.L7F09EEA0:
/* 0D39D0 7F09EEA0 46028001 */  sub.s $f0, $f16, $f2
/* 0D39D4 7F09EEA4 460C703C */  c.lt.s $f14, $f12
/* 0D39D8 7F09EEA8 00000000 */  nop
/* 0D39DC 7F09EEAC 45020003 */  bc1fl .L7F09EEBC
/* 0D39E0 7F09EEB0 4600703C */   c.lt.s $f14, $f0
/* 0D39E4 7F09EEB4 46006386 */  mov.s $f14, $f12
/* 0D39E8 7F09EEB8 4600703C */  c.lt.s $f14, $f0
.L7F09EEBC:
/* 0D39EC 7F09EEBC 00000000 */  nop
/* 0D39F0 7F09EEC0 45020003 */  bc1fl .L7F09EED0
/* 0D39F4 7F09EEC4 44077000 */   mfc1  $a3, $f14
/* 0D39F8 7F09EEC8 46000386 */  mov.s $f14, $f0
/* 0D39FC 7F09EECC 44077000 */  mfc1  $a3, $f14
.L7F09EED0:
/* 0D3A00 7F09EED0 0FC0F89F */  jal   sub_GAME_7F03E27C
/* 0D3A04 7F09EED4 02003025 */   move  $a2, $s0
/* 0D3A08 7F09EED8 866C0006 */  lh    $t4, 6($s3)
/* 0D3A0C 7F09EEDC 86780004 */  lh    $t8, 4($s3)
/* 0D3A10 7F09EEE0 00009025 */  move  $s2, $zero
/* 0D3A14 7F09EEE4 01960019 */  multu $t4, $s6
/* 0D3A18 7F09EEE8 02608825 */  move  $s1, $s3
/* 0D3A1C 7F09EEEC 24020190 */  li    $v0, 400
/* 0D3A20 7F09EEF0 00001825 */  move  $v1, $zero
/* 0D3A24 7F09EEF4 00006812 */  mflo  $t5
/* 0D3A28 7F09EEF8 02AD7021 */  addu  $t6, $s5, $t5
/* 0D3A2C 7F09EEFC 85CF0004 */  lh    $t7, 4($t6)
/* 0D3A30 7F09EF00 01F8082A */  slt   $at, $t7, $t8
/* 0D3A34 7F09EF04 1020000E */  beqz  $at, .L7F09EF40
/* 0D3A38 7F09EF08 00000000 */   nop
/* 0D3A3C 7F09EF0C 24030001 */  li    $v1, 1
.L7F09EF10:
/* 0D3A40 7F09EF10 C6260014 */  lwc1  $f6, 0x14($s1)
/* 0D3A44 7F09EF14 26520028 */  addiu $s2, $s2, 0x28
/* 0D3A48 7F09EF18 4606D03C */  c.lt.s $f26, $f6
/* 0D3A4C 7F09EF1C 00000000 */  nop
/* 0D3A50 7F09EF20 45000003 */  bc1f  .L7F09EF30
/* 0D3A54 7F09EF24 00000000 */   nop
/* 0D3A58 7F09EF28 10000005 */  b     .L7F09EF40
/* 0D3A5C 7F09EF2C 00001825 */   move  $v1, $zero
.L7F09EF30:
/* 0D3A60 7F09EF30 1642FFF7 */  bne   $s2, $v0, .L7F09EF10
/* 0D3A64 7F09EF34 26310028 */   addiu $s1, $s1, 0x28
/* 0D3A68 7F09EF38 10000001 */  b     .L7F09EF40
/* 0D3A6C 7F09EF3C 00000000 */   nop
.L7F09EF40:
/* 0D3A70 7F09EF40 10600004 */  beqz  $v1, .L7F09EF54
/* 0D3A74 7F09EF44 00001025 */   move  $v0, $zero
/* 0D3A78 7F09EF48 AE600000 */  sw    $zero, ($s3)
/* 0D3A7C 7F09EF4C 10000001 */  b     .L7F09EF54
/* 0D3A80 7F09EF50 24020001 */   li    $v0, 1
.L7F09EF54:
/* 0D3A84 7F09EF54 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0D3A88 7F09EF58 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D3A8C 7F09EF5C D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D3A90 7F09EF60 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0D3A94 7F09EF64 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0D3A98 7F09EF68 D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0D3A9C 7F09EF6C D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0D3AA0 7F09EF70 8FB00048 */  lw    $s0, 0x48($sp)
/* 0D3AA4 7F09EF74 8FB1004C */  lw    $s1, 0x4c($sp)
/* 0D3AA8 7F09EF78 8FB20050 */  lw    $s2, 0x50($sp)
/* 0D3AAC 7F09EF7C 8FB30054 */  lw    $s3, 0x54($sp)
/* 0D3AB0 7F09EF80 8FB40058 */  lw    $s4, 0x58($sp)
/* 0D3AB4 7F09EF84 8FB5005C */  lw    $s5, 0x5c($sp)
/* 0D3AB8 7F09EF88 8FB60060 */  lw    $s6, 0x60($sp)
/* 0D3ABC 7F09EF8C 8FB70064 */  lw    $s7, 0x64($sp)
/* 0D3AC0 7F09EF90 8FBE0068 */  lw    $fp, 0x68($sp)
/* 0D3AC4 7F09EF94 03E00008 */  jr    $ra
/* 0D3AC8 7F09EF98 27BD00D0 */   addiu $sp, $sp, 0xd0
)
#endif


/*
* Address: 0x7F09EF9C
*/
u8 smokeTick(PropRecord* prop)
{
    Mtxf* player_matrix;

    player_matrix = camGetWorldToScreenMtxf();
    prop->Unk18 = -((((player_matrix->m[0][2] * prop->pos.x) + (player_matrix->m[1][2] * prop->pos.y)) + (player_matrix->m[2][2] * prop->pos.z)) + player_matrix->m[3][2]);

    if (prop->Unk18 < 100.0f)
    {
        prop->Unk18 *= 0.5f;
    }
    else
    {
        prop->Unk18 -= 100.0f;
    }

    return 0;
}


#ifdef NONMATCHING
void unk09c250RenderPropSmoke(void) {

}
#else
GLOBAL_ASM(
.text
glabel unk09c250RenderPropSmoke
/* 0D3B6C 7F09F03C 27BDFF70 */  addiu $sp, $sp, -0x90
/* 0D3B70 7F09F040 AFB00024 */  sw    $s0, 0x24($sp)
/* 0D3B74 7F09F044 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0D3B78 7F09F048 AFB50038 */  sw    $s5, 0x38($sp)
/* 0D3B7C 7F09F04C AFB40034 */  sw    $s4, 0x34($sp)
/* 0D3B80 7F09F050 AFB30030 */  sw    $s3, 0x30($sp)
/* 0D3B84 7F09F054 AFB2002C */  sw    $s2, 0x2c($sp)
/* 0D3B88 7F09F058 AFB10028 */  sw    $s1, 0x28($sp)
/* 0D3B8C 7F09F05C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D3B90 7F09F060 9091002C */  lbu   $s1, 0x2c($a0)
/* 0D3B94 7F09F064 00808025 */  move  $s0, $a0
/* 0D3B98 7F09F068 8C940004 */  lw    $s4, 4($a0)
/* 0D3B9C 7F09F06C 00A09025 */  move  $s2, $a1
/* 0D3BA0 7F09F070 00C09825 */  move  $s3, $a2
/* 0D3BA4 7F09F074 0FC2F285 */  jal   getRoomIndexPOS
/* 0D3BA8 7F09F078 02202025 */   move  $a0, $s1
/* 0D3BAC 7F09F07C 16600003 */  bnez  $s3, .L7F09F08C
/* 0D3BB0 7F09F080 0040A825 */   move  $s5, $v0
/* 0D3BB4 7F09F084 10000069 */  b     .L7F09F22C
/* 0D3BB8 7F09F088 02401025 */   move  $v0, $s2
.L7F09F08C:
/* 0D3BBC 7F09F08C 02002025 */  move  $a0, $s0
/* 0D3BC0 7F09F090 0FC15299 */  jal   sub_GAME_7F054A64
/* 0D3BC4 7F09F094 27A50078 */   addiu $a1, $sp, 0x78
/* 0D3BC8 7F09F098 1840000A */  blez  $v0, .L7F09F0C4
/* 0D3BCC 7F09F09C 00000000 */   nop
/* 0D3BD0 7F09F0A0 C7A40084 */  lwc1  $f4, 0x84($sp)
/* 0D3BD4 7F09F0A4 02402025 */  move  $a0, $s2
/* 0D3BD8 7F09F0A8 8FA50078 */  lw    $a1, 0x78($sp)
/* 0D3BDC 7F09F0AC 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0D3BE0 7F09F0B0 8FA70080 */  lw    $a3, 0x80($sp)
/* 0D3BE4 7F09F0B4 0FC2D3FD */  jal   bgScissorCurrentPlayerViewF
/* 0D3BE8 7F09F0B8 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0D3BEC 7F09F0BC 10000004 */  b     .L7F09F0D0
/* 0D3BF0 7F09F0C0 00409025 */   move  $s2, $v0
.L7F09F0C4:
/* 0D3BF4 7F09F0C4 0FC2D3ED */  jal   bgScissorCurrentPlayerViewDefault
/* 0D3BF8 7F09F0C8 02402025 */   move  $a0, $s2
/* 0D3BFC 7F09F0CC 00409025 */  move  $s2, $v0
.L7F09F0D0:
/* 0D3C00 7F09F0D0 02401025 */  move  $v0, $s2
/* 0D3C04 7F09F0D4 3C0F0001 */  lui   $t7, (0x00013000 >> 16) # lui $t7, 1
/* 0D3C08 7F09F0D8 35EF3000 */  ori   $t7, (0x00013000 & 0xFFFF) # ori $t7, $t7, 0x3000
/* 0D3C0C 7F09F0DC 26520008 */  addiu $s2, $s2, 8
/* 0D3C10 7F09F0E0 3C0EB600 */  lui   $t6, 0xb600
/* 0D3C14 7F09F0E4 3C180103 */  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
/* 0D3C18 7F09F0E8 AC4E0000 */  sw    $t6, ($v0)
/* 0D3C1C 7F09F0EC AC4F0004 */  sw    $t7, 4($v0)
/* 0D3C20 7F09F0F0 37180040 */  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
/* 0D3C24 7F09F0F4 02408025 */  move  $s0, $s2
/* 0D3C28 7F09F0F8 AE180000 */  sw    $t8, ($s0)
/* 0D3C2C 7F09F0FC 0FC1E0E5 */  jal   get_BONDdata_field_10E0
/* 0D3C30 7F09F100 26520008 */   addiu $s2, $s2, 8
/* 0D3C34 7F09F104 0C003A2C */  jal   osVirtualToPhysical
/* 0D3C38 7F09F108 00402025 */   move  $a0, $v0
/* 0D3C3C 7F09F10C AE020004 */  sw    $v0, 4($s0)
/* 0D3C40 7F09F110 02402025 */  move  $a0, $s2
/* 0D3C44 7F09F114 0FC2F271 */  jal   sub_GAME_7F0BC9C4
/* 0D3C48 7F09F118 02202825 */   move  $a1, $s1
/* 0D3C4C 7F09F11C 3C190100 */  lui   $t9, (0x01000040 >> 16) # lui $t9, 0x100
/* 0D3C50 7F09F120 37390040 */  ori   $t9, (0x01000040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0D3C54 7F09F124 3C048008 */  lui   $a0, %hi(dword_CODE_bss_8007A100)
/* 0D3C58 7F09F128 2484A100 */  addiu $a0, %lo(dword_CODE_bss_8007A100) # addiu $a0, $a0, -0x5f00
/* 0D3C5C 7F09F12C AC590000 */  sw    $t9, ($v0)
/* 0D3C60 7F09F130 00408025 */  move  $s0, $v0
/* 0D3C64 7F09F134 0C003A2C */  jal   osVirtualToPhysical
/* 0D3C68 7F09F138 24520008 */   addiu $s2, $v0, 8
/* 0D3C6C 7F09F13C 3C08BC00 */  lui   $t0, (0xBC000806 >> 16) # lui $t0, 0xbc00
/* 0D3C70 7F09F140 AE020004 */  sw    $v0, 4($s0)
/* 0D3C74 7F09F144 35080806 */  ori   $t0, (0xBC000806 & 0xFFFF) # ori $t0, $t0, 0x806
/* 0D3C78 7F09F148 02409825 */  move  $s3, $s2
/* 0D3C7C 7F09F14C AE680000 */  sw    $t0, ($s3)
/* 0D3C80 7F09F150 3C048009 */  lui   $a0, %hi(pGlobalimagetable)
/* 0D3C84 7F09F154 8C84D0B4 */  lw    $a0, %lo(pGlobalimagetable)($a0)
/* 0D3C88 7F09F158 0C003A2C */  jal   osVirtualToPhysical
/* 0D3C8C 7F09F15C 26520008 */   addiu $s2, $s2, 8
/* 0D3C90 7F09F160 AE620004 */  sw    $v0, 4($s3)
/* 0D3C94 7F09F164 02401825 */  move  $v1, $s2
/* 0D3C98 7F09F168 26520008 */  addiu $s2, $s2, 8
/* 0D3C9C 7F09F16C 3C0A0200 */  lui   $t2, 0x200
/* 0D3CA0 7F09F170 254A0000 */  addiu $t2, $t2, 0
/* 0D3CA4 7F09F174 3C090600 */  lui   $t1, 0x600
/* 0D3CA8 7F09F178 02402025 */  move  $a0, $s2
/* 0D3CAC 7F09F17C AC690000 */  sw    $t1, ($v1)
/* 0D3CB0 7F09F180 AC6A0004 */  sw    $t2, 4($v1)
/* 0D3CB4 7F09F184 3C0BBA00 */  lui   $t3, (0xBA000602 >> 16) # lui $t3, 0xba00
/* 0D3CB8 7F09F188 356B0602 */  ori   $t3, (0xBA000602 & 0xFFFF) # ori $t3, $t3, 0x602
/* 0D3CBC 7F09F18C 240C0080 */  li    $t4, 128
/* 0D3CC0 7F09F190 4480A000 */  mtc1  $zero, $f20
/* 0D3CC4 7F09F194 AC8C0004 */  sw    $t4, 4($a0)
/* 0D3CC8 7F09F198 AC8B0000 */  sw    $t3, ($a0)
/* 0D3CCC 7F09F19C 26520008 */  addiu $s2, $s2, 8
/* 0D3CD0 7F09F1A0 24130190 */  li    $s3, 400
/* 0D3CD4 7F09F1A4 00008825 */  move  $s1, $zero
/* 0D3CD8 7F09F1A8 02808025 */  move  $s0, $s4
.L7F09F1AC:
/* 0D3CDC 7F09F1AC C6060014 */  lwc1  $f6, 0x14($s0)
/* 0D3CE0 7F09F1B0 02802025 */  move  $a0, $s4
/* 0D3CE4 7F09F1B4 26050008 */  addiu $a1, $s0, 8
/* 0D3CE8 7F09F1B8 4606A03C */  c.lt.s $f20, $f6
/* 0D3CEC 7F09F1BC 02403025 */  move  $a2, $s2
/* 0D3CF0 7F09F1C0 45020006 */  bc1fl .L7F09F1DC
/* 0D3CF4 7F09F1C4 E6140014 */   swc1  $f20, 0x14($s0)
/* 0D3CF8 7F09F1C8 0FC27769 */  jal   sub_GAME_7F09DDA4
/* 0D3CFC 7F09F1CC 02A03825 */   move  $a3, $s5
/* 0D3D00 7F09F1D0 10000002 */  b     .L7F09F1DC
/* 0D3D04 7F09F1D4 00409025 */   move  $s2, $v0
/* 0D3D08 7F09F1D8 E6140014 */  swc1  $f20, 0x14($s0)
.L7F09F1DC:
/* 0D3D0C 7F09F1DC 26310028 */  addiu $s1, $s1, 0x28
/* 0D3D10 7F09F1E0 1633FFF2 */  bne   $s1, $s3, .L7F09F1AC
/* 0D3D14 7F09F1E4 26100028 */   addiu $s0, $s0, 0x28
/* 0D3D18 7F09F1E8 02401025 */  move  $v0, $s2
/* 0D3D1C 7F09F1EC 3C0DBA00 */  lui   $t5, (0xBA000602 >> 16) # lui $t5, 0xba00
/* 0D3D20 7F09F1F0 35AD0602 */  ori   $t5, (0xBA000602 & 0xFFFF) # ori $t5, $t5, 0x602
/* 0D3D24 7F09F1F4 26520008 */  addiu $s2, $s2, 8
/* 0D3D28 7F09F1F8 240E0040 */  li    $t6, 64
/* 0D3D2C 7F09F1FC 3C0F0103 */  lui   $t7, (0x01030040 >> 16) # lui $t7, 0x103
/* 0D3D30 7F09F200 AC4E0004 */  sw    $t6, 4($v0)
/* 0D3D34 7F09F204 AC4D0000 */  sw    $t5, ($v0)
/* 0D3D38 7F09F208 35EF0040 */  ori   $t7, (0x01030040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 0D3D3C 7F09F20C 02408025 */  move  $s0, $s2
/* 0D3D40 7F09F210 AE0F0000 */  sw    $t7, ($s0)
/* 0D3D44 7F09F214 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0D3D48 7F09F218 26520008 */   addiu $s2, $s2, 8
/* 0D3D4C 7F09F21C 0C003A2C */  jal   osVirtualToPhysical
/* 0D3D50 7F09F220 00402025 */   move  $a0, $v0
/* 0D3D54 7F09F224 AE020004 */  sw    $v0, 4($s0)
/* 0D3D58 7F09F228 02401025 */  move  $v0, $s2
.L7F09F22C:
/* 0D3D5C 7F09F22C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0D3D60 7F09F230 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D3D64 7F09F234 8FB00024 */  lw    $s0, 0x24($sp)
/* 0D3D68 7F09F238 8FB10028 */  lw    $s1, 0x28($sp)
/* 0D3D6C 7F09F23C 8FB2002C */  lw    $s2, 0x2c($sp)
/* 0D3D70 7F09F240 8FB30030 */  lw    $s3, 0x30($sp)
/* 0D3D74 7F09F244 8FB40034 */  lw    $s4, 0x34($sp)
/* 0D3D78 7F09F248 8FB50038 */  lw    $s5, 0x38($sp)
/* 0D3D7C 7F09F24C 03E00008 */  jr    $ra
/* 0D3D80 7F09F250 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif


void init_gray_flying_particles(coord3d *spawnpos, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    // these are gray rectangles of dust created from shooting walls with guns that fall down with gravity
    // a bullet will create a group of them flying off the wall

    f32 rand1;
    f32 rand2;
    f32 rand3;
    s16 unk08_upper;
    s16 unk0A_upper;
    s8 rand_s8;

    rand1 = (2.0f * (((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX))) - 1.0f;
    rand2 = ((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 1.12f) - 0.12f;
    rand3 = (2.0f * (((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX))) - 1.0f;

    ptr_flying_particles_buf[numParticleEntries].unk00 = 1;

    ptr_flying_particles_buf[numParticleEntries].x = spawnpos->f[0] + (arg1 * rand1);
    ptr_flying_particles_buf[numParticleEntries].y = spawnpos->f[1] + (arg1 * rand2);
    ptr_flying_particles_buf[numParticleEntries].z = spawnpos->f[2] + (arg1 * rand3);

    ptr_flying_particles_buf[numParticleEntries].unk1C = rand1 * arg2;
    ptr_flying_particles_buf[numParticleEntries].unk20 = rand2 * arg3;
    ptr_flying_particles_buf[numParticleEntries].unk24 = rand3 * arg2;

    ptr_flying_particles_buf[numParticleEntries].unk38[0].unk00 = (s16) ((s32) ((((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.75f) + 0.75f) * arg4));
    ptr_flying_particles_buf[numParticleEntries].unk38[0].unk02 = 0;
    ptr_flying_particles_buf[numParticleEntries].unk38[0].unk04 = (s16) ((s32) ((((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.75f) + 0.75f) * arg4));

    if (1)
    {
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk00 = (s16) ((s32) ((((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.75f) + 0.75f) * arg4));
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk02 = 0;
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk04 = (s16) ((s32) ((((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.75f) + 0.75f) * (-arg4)));

        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk00 = (s16) ((s32) ((((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.75f) + 0.75f) * (-arg4)));
        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk02 = 0;
        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk04 = (s16) ((s32) ((((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.75f) + 0.75f) * (-arg4)));

        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk00 = (s16) ((s32) ((((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.75f) + 0.75f) * (-arg4)));
        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk02 = 0;
        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk04 = (s16) ((s32) ((((((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.75f) + 0.75f) * arg4));
    }

    if (1) {}

    unk08_upper = (randomGetNext() & 3) << 8;
    unk0A_upper = (randomGetNext() & 3) << 8;

    ptr_flying_particles_buf[numParticleEntries].unk38[0].unk08 = unk08_upper + 0xE0;
    ptr_flying_particles_buf[numParticleEntries].unk38[0].unk0A = unk0A_upper + 0xE0;
    ptr_flying_particles_buf[numParticleEntries].unk38[1].unk08 = unk08_upper + 0xE0;
    ptr_flying_particles_buf[numParticleEntries].unk38[1].unk0A = unk0A_upper;
    ptr_flying_particles_buf[numParticleEntries].unk38[2].unk08 = unk08_upper;
    ptr_flying_particles_buf[numParticleEntries].unk38[2].unk0A = unk0A_upper;
    ptr_flying_particles_buf[numParticleEntries].unk38[3].unk08 = unk08_upper;
    ptr_flying_particles_buf[numParticleEntries].unk38[3].unk0A = unk0A_upper + 0xE0;

    if (randomGetNext() & 1)
    {
        rand_s8 = 0xFF - (randomGetNext() & 0x3F);
        ptr_flying_particles_buf[numParticleEntries].unk38[0].unk0E = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[0].unk0D = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[0].unk0C = rand_s8;
        rand_s8 = 0xFF - (randomGetNext() & 0x3F);
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk0E = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk0D = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk0C = rand_s8;
        rand_s8 = 0xFF - (randomGetNext() & 0x3F);
        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk0E = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk0D = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk0C = rand_s8;
        rand_s8 = 0xFF - (randomGetNext() & 0x3F);
        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk0E = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk0D = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk0C = rand_s8;
    }
    else
    {
        rand_s8 = randomGetNext() & 0x3F;
        ptr_flying_particles_buf[numParticleEntries].unk38[0].unk0E = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[0].unk0D = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[0].unk0C = rand_s8;
        rand_s8 = randomGetNext() & 0x3F;
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk0E = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk0D = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[1].unk0C = rand_s8;
        rand_s8 = randomGetNext() & 0x3F;
        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk0E = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk0D = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[2].unk0C = rand_s8;
        rand_s8 = randomGetNext() & 0x3F;
        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk0E = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk0D = rand_s8;
        ptr_flying_particles_buf[numParticleEntries].unk38[3].unk0C = rand_s8;
    }

    ptr_flying_particles_buf[numParticleEntries].unk38[0].unk0F = 0xdc;
    ptr_flying_particles_buf[numParticleEntries].unk38[1].unk0F = 0xdc;
    ptr_flying_particles_buf[numParticleEntries].unk38[2].unk0F = 0xdc;
    ptr_flying_particles_buf[numParticleEntries].unk38[3].unk0F = 0xdc;

    ptr_flying_particles_buf[numParticleEntries].unk10 = (((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * M_TAU_F;
    ptr_flying_particles_buf[numParticleEntries].unk14 = (((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * M_TAU_F;
    ptr_flying_particles_buf[numParticleEntries].unk18 = (((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * M_TAU_F;

    ptr_flying_particles_buf[numParticleEntries].unk28 = (((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.1f;
    ptr_flying_particles_buf[numParticleEntries].unk2C = (((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.1f;
    ptr_flying_particles_buf[numParticleEntries].unk30 = (((f32) randomGetNext()) * (1.0f / (f32)UINT_MAX)) * 0.1f;

    numParticleEntries++;
    if (numParticleEntries >= max_particles)
    {
        numParticleEntries = 0;
    }
}


void update_gray_flying_particles(void)
{
    f32 scalar;
    s32 i;
    s32 j;

    if (g_ClockTimer < 0xF)
    {
        scalar = g_ClockTimer;
    }
    else
    {
        scalar = 15.0f;
    }


    for (i = 0; i < max_particles; i++)
    {
        if (ptr_flying_particles_buf[i].unk00 > 0)
        {
            ptr_flying_particles_buf[i].unk00 += (s32) scalar;

            ptr_flying_particles_buf[i].unk10 += ptr_flying_particles_buf[i].unk28 * scalar;
            ptr_flying_particles_buf[i].unk14 += ptr_flying_particles_buf[i].unk2C * scalar;
            ptr_flying_particles_buf[i].unk18 += ptr_flying_particles_buf[i].unk30 * scalar;
            ptr_flying_particles_buf[i].x += ptr_flying_particles_buf[i].unk1C * scalar;
            ptr_flying_particles_buf[i].z += ptr_flying_particles_buf[i].unk24 * scalar;

            for (j = 0; j < (s32)scalar; j++)
            {
                // initially sends particles flying up
                ptr_flying_particles_buf[i].y += ptr_flying_particles_buf[i].unk20;

                // applies gravity so particles fall down
                if (ptr_flying_particles_buf[i].unk20 > -3.75f)
                {
                    ptr_flying_particles_buf[i].unk20 -= 0.2f;
                }
            }

            // handles particles life time
            if ((ptr_flying_particles_buf[i].unk00 >= 0x65) && (!(randomGetNext() & 0x1F) || (ptr_flying_particles_buf[i].unk00 == 0x12C)))
            {
                ptr_flying_particles_buf[i].unk00 = 0;
            }

            // position-related. deletes particles that are too low or too high.
            if ((ptr_flying_particles_buf[i].y < -30000.0f) || (ptr_flying_particles_buf[i].y > 30000.0f))
            {
                ptr_flying_particles_buf[i].unk00 = 0;
            }
        }
    }
}


#ifdef NONMATCHING
Gfx * sub_GAME_7F0A0034(Gfx *arg0) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800576FC
.word 0xc69c4000 /*-20000.0*/
glabel D_80057700
.word 0x469c4000 /*20000.0*/
.text
glabel sub_GAME_7F0A0034
/* 0D4B64 7F0A0034 27BDFF40 */  addiu $sp, $sp, -0xc0
/* 0D4B68 7F0A0038 AFB00028 */  sw    $s0, 0x28($sp)
/* 0D4B6C 7F0A003C AFBF004C */  sw    $ra, 0x4c($sp)
/* 0D4B70 7F0A0040 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0D4B74 7F0A0044 AFB70044 */  sw    $s7, 0x44($sp)
/* 0D4B78 7F0A0048 AFB60040 */  sw    $s6, 0x40($sp)
/* 0D4B7C 7F0A004C AFB5003C */  sw    $s5, 0x3c($sp)
/* 0D4B80 7F0A0050 AFB40038 */  sw    $s4, 0x38($sp)
/* 0D4B84 7F0A0054 AFB30034 */  sw    $s3, 0x34($sp)
/* 0D4B88 7F0A0058 AFB20030 */  sw    $s2, 0x30($sp)
/* 0D4B8C 7F0A005C AFB1002C */  sw    $s1, 0x2c($sp)
/* 0D4B90 7F0A0060 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D4B94 7F0A0064 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D4B98 7F0A0068 3C0EB600 */  lui   $t6, 0xb600
/* 0D4B9C 7F0A006C 240F3000 */  li    $t7, 12288
/* 0D4BA0 7F0A0070 AC8F0004 */  sw    $t7, 4($a0)
/* 0D4BA4 7F0A0074 AC8E0000 */  sw    $t6, ($a0)
/* 0D4BA8 7F0A0078 24900008 */  addiu $s0, $a0, 8
/* 0D4BAC 7F0A007C 3C18BC00 */  lui   $t8, (0xBC000806 >> 16) # lui $t8, 0xbc00
/* 0D4BB0 7F0A0080 37180806 */  ori   $t8, (0xBC000806 & 0xFFFF) # ori $t8, $t8, 0x806
/* 0D4BB4 7F0A0084 02008825 */  move  $s1, $s0
/* 0D4BB8 7F0A0088 AE380000 */  sw    $t8, ($s1)
/* 0D4BBC 7F0A008C 3C048009 */  lui   $a0, %hi(pGlobalimagetable)
/* 0D4BC0 7F0A0090 8C84D0B4 */  lw    $a0, %lo(pGlobalimagetable)($a0)
/* 0D4BC4 7F0A0094 0C003A2C */  jal   osVirtualToPhysical
/* 0D4BC8 7F0A0098 26100008 */   addiu $s0, $s0, 8
/* 0D4BCC 7F0A009C 02001825 */  move  $v1, $s0
/* 0D4BD0 7F0A00A0 AE220004 */  sw    $v0, 4($s1)
/* 0D4BD4 7F0A00A4 3C080200 */  lui   $t0, 0x200
/* 0D4BD8 7F0A00A8 25080A50 */  addiu $t0, $t0, 0xa50
/* 0D4BDC 7F0A00AC 26100008 */  addiu $s0, $s0, 8
/* 0D4BE0 7F0A00B0 3C190600 */  lui   $t9, 0x600
/* 0D4BE4 7F0A00B4 AC790000 */  sw    $t9, ($v1)
/* 0D4BE8 7F0A00B8 AC680004 */  sw    $t0, 4($v1)
/* 0D4BEC 7F0A00BC 02002025 */  move  $a0, $s0
/* 0D4BF0 7F0A00C0 3C09B900 */  lui   $t1, (0xB900031D >> 16) # lui $t1, 0xb900
/* 0D4BF4 7F0A00C4 3C0A0050 */  lui   $t2, (0x005049D8 >> 16) # lui $t2, 0x50
/* 0D4BF8 7F0A00C8 354A49D8 */  ori   $t2, (0x005049D8 & 0xFFFF) # ori $t2, $t2, 0x49d8
/* 0D4BFC 7F0A00CC 3529031D */  ori   $t1, (0xB900031D & 0xFFFF) # ori $t1, $t1, 0x31d
/* 0D4C00 7F0A00D0 AC890000 */  sw    $t1, ($a0)
/* 0D4C04 7F0A00D4 AC8A0004 */  sw    $t2, 4($a0)
/* 0D4C08 7F0A00D8 3C0B8008 */  lui   $t3, %hi(max_particles)
/* 0D4C0C 7F0A00DC 8D6BA148 */  lw    $t3, %lo(max_particles)($t3)
/* 0D4C10 7F0A00E0 26100008 */  addiu $s0, $s0, 8
/* 0D4C14 7F0A00E4 0000A825 */  move  $s5, $zero
/* 0D4C18 7F0A00E8 19600055 */  blez  $t3, .L7F0A0240
/* 0D4C1C 7F0A00EC 00009825 */   move  $s3, $zero
/* 0D4C20 7F0A00F0 3C018005 */  lui   $at, %hi(D_800576FC)
/* 0D4C24 7F0A00F4 C43676FC */  lwc1  $f22, %lo(D_800576FC)($at)
/* 0D4C28 7F0A00F8 3C018005 */  lui   $at, %hi(D_80057700)
/* 0D4C2C 7F0A00FC 3C1E0430 */  lui   $fp, (0x04300040 >> 16) # lui $fp, 0x430
/* 0D4C30 7F0A0100 3C170102 */  lui   $s7, (0x01020040 >> 16) # lui $s7, 0x102
/* 0D4C34 7F0A0104 3C168008 */  lui   $s6, %hi(ptr_flying_particles_buf)
/* 0D4C38 7F0A0108 26D6A14C */  addiu $s6, %lo(ptr_flying_particles_buf) # addiu $s6, $s6, -0x5eb4
/* 0D4C3C 7F0A010C 36F70040 */  ori   $s7, (0x01020040 & 0xFFFF) # ori $s7, $s7, 0x40
/* 0D4C40 7F0A0110 37DE0040 */  ori   $fp, (0x04300040 & 0xFFFF) # ori $fp, $fp, 0x40
/* 0D4C44 7F0A0114 C4347700 */  lwc1  $f20, %lo(D_80057700)($at)
/* 0D4C48 7F0A0118 27B40080 */  addiu $s4, $sp, 0x80
/* 0D4C4C 7F0A011C 8ECC0000 */  lw    $t4, ($s6)
.L7F0A0120:
/* 0D4C50 7F0A0120 01931021 */  addu  $v0, $t4, $s3
/* 0D4C54 7F0A0124 8C4D0000 */  lw    $t5, ($v0)
/* 0D4C58 7F0A0128 24440004 */  addiu $a0, $v0, 4
/* 0D4C5C 7F0A012C 24450010 */  addiu $a1, $v0, 0x10
/* 0D4C60 7F0A0130 19A0003C */  blez  $t5, .L7F0A0224
/* 0D4C64 7F0A0134 00000000 */   nop
/* 0D4C68 7F0A0138 0FC1624B */  jal   matrix_4x4_set_position_and_rotation_around_xyz
/* 0D4C6C 7F0A013C 02803025 */   move  $a2, $s4
/* 0D4C70 7F0A0140 0FC1E0F1 */  jal   camGetWorldToScreenMtxf
/* 0D4C74 7F0A0144 00000000 */   nop
/* 0D4C78 7F0A0148 00402025 */  move  $a0, $v0
/* 0D4C7C 7F0A014C 0FC16026 */  jal   matrix_4x4_multiply_homogeneous_in_place
/* 0D4C80 7F0A0150 02802825 */   move  $a1, $s4
/* 0D4C84 7F0A0154 C7A000B0 */  lwc1  $f0, 0xb0($sp)
/* 0D4C88 7F0A0158 4614003C */  c.lt.s $f0, $f20
/* 0D4C8C 7F0A015C 00000000 */  nop
/* 0D4C90 7F0A0160 45000030 */  bc1f  .L7F0A0224
/* 0D4C94 7F0A0164 00000000 */   nop
/* 0D4C98 7F0A0168 4600B03C */  c.lt.s $f22, $f0
/* 0D4C9C 7F0A016C C7A000B4 */  lwc1  $f0, 0xb4($sp)
/* 0D4CA0 7F0A0170 4500002C */  bc1f  .L7F0A0224
/* 0D4CA4 7F0A0174 00000000 */   nop
/* 0D4CA8 7F0A0178 4614003C */  c.lt.s $f0, $f20
/* 0D4CAC 7F0A017C 00000000 */  nop
/* 0D4CB0 7F0A0180 45000028 */  bc1f  .L7F0A0224
/* 0D4CB4 7F0A0184 00000000 */   nop
/* 0D4CB8 7F0A0188 4600B03C */  c.lt.s $f22, $f0
/* 0D4CBC 7F0A018C C7A000B8 */  lwc1  $f0, 0xb8($sp)
/* 0D4CC0 7F0A0190 45000024 */  bc1f  .L7F0A0224
/* 0D4CC4 7F0A0194 00000000 */   nop
/* 0D4CC8 7F0A0198 4614003C */  c.lt.s $f0, $f20
/* 0D4CCC 7F0A019C 00000000 */  nop
/* 0D4CD0 7F0A01A0 45000020 */  bc1f  .L7F0A0224
/* 0D4CD4 7F0A01A4 00000000 */   nop
/* 0D4CD8 7F0A01A8 4600B03C */  c.lt.s $f22, $f0
/* 0D4CDC 7F0A01AC 00000000 */  nop
/* 0D4CE0 7F0A01B0 4500001C */  bc1f  .L7F0A0224
/* 0D4CE4 7F0A01B4 00000000 */   nop
/* 0D4CE8 7F0A01B8 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0D4CEC 7F0A01BC 00000000 */   nop
/* 0D4CF0 7F0A01C0 00409025 */  move  $s2, $v0
/* 0D4CF4 7F0A01C4 02802025 */  move  $a0, $s4
/* 0D4CF8 7F0A01C8 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 0D4CFC 7F0A01CC 00402825 */   move  $a1, $v0
/* 0D4D00 7F0A01D0 02008825 */  move  $s1, $s0
/* 0D4D04 7F0A01D4 AE370000 */  sw    $s7, ($s1)
/* 0D4D08 7F0A01D8 26100008 */  addiu $s0, $s0, 8
/* 0D4D0C 7F0A01DC 0C003A2C */  jal   osVirtualToPhysical
/* 0D4D10 7F0A01E0 02402025 */   move  $a0, $s2
/* 0D4D14 7F0A01E4 AE220004 */  sw    $v0, 4($s1)
/* 0D4D18 7F0A01E8 02009025 */  move  $s2, $s0
/* 0D4D1C 7F0A01EC AE5E0000 */  sw    $fp, ($s2)
/* 0D4D20 7F0A01F0 8ECE0000 */  lw    $t6, ($s6)
/* 0D4D24 7F0A01F4 26100008 */  addiu $s0, $s0, 8
/* 0D4D28 7F0A01F8 01D32021 */  addu  $a0, $t6, $s3
/* 0D4D2C 7F0A01FC 0C003A2C */  jal   osVirtualToPhysical
/* 0D4D30 7F0A0200 24840038 */   addiu $a0, $a0, 0x38
/* 0D4D34 7F0A0204 02001825 */  move  $v1, $s0
/* 0D4D38 7F0A0208 AE420004 */  sw    $v0, 4($s2)
/* 0D4D3C 7F0A020C 3C0FB100 */  lui   $t7, (0xB1000032 >> 16) # lui $t7, 0xb100
/* 0D4D40 7F0A0210 35EF0032 */  ori   $t7, (0xB1000032 & 0xFFFF) # ori $t7, $t7, 0x32
/* 0D4D44 7F0A0214 24182010 */  li    $t8, 8208
/* 0D4D48 7F0A0218 AC780004 */  sw    $t8, 4($v1)
/* 0D4D4C 7F0A021C AC6F0000 */  sw    $t7, ($v1)
/* 0D4D50 7F0A0220 26100008 */  addiu $s0, $s0, 8
.L7F0A0224:
/* 0D4D54 7F0A0224 3C198008 */  lui   $t9, %hi(max_particles)
/* 0D4D58 7F0A0228 8F39A148 */  lw    $t9, %lo(max_particles)($t9)
/* 0D4D5C 7F0A022C 26B50001 */  addiu $s5, $s5, 1
/* 0D4D60 7F0A0230 26730078 */  addiu $s3, $s3, 0x78
/* 0D4D64 7F0A0234 02B9082A */  slt   $at, $s5, $t9
/* 0D4D68 7F0A0238 5420FFB9 */  bnezl $at, .L7F0A0120
/* 0D4D6C 7F0A023C 8ECC0000 */   lw    $t4, ($s6)
.L7F0A0240:
/* 0D4D70 7F0A0240 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0D4D74 7F0A0244 02001025 */  move  $v0, $s0
/* 0D4D78 7F0A0248 8FB00028 */  lw    $s0, 0x28($sp)
/* 0D4D7C 7F0A024C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D4D80 7F0A0250 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D4D84 7F0A0254 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0D4D88 7F0A0258 8FB20030 */  lw    $s2, 0x30($sp)
/* 0D4D8C 7F0A025C 8FB30034 */  lw    $s3, 0x34($sp)
/* 0D4D90 7F0A0260 8FB40038 */  lw    $s4, 0x38($sp)
/* 0D4D94 7F0A0264 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0D4D98 7F0A0268 8FB60040 */  lw    $s6, 0x40($sp)
/* 0D4D9C 7F0A026C 8FB70044 */  lw    $s7, 0x44($sp)
/* 0D4DA0 7F0A0270 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0D4DA4 7F0A0274 03E00008 */  jr    $ra
/* 0D4DA8 7F0A0278 27BD00C0 */   addiu $sp, $sp, 0xc0
)
#endif




/***
 * NTSC address 0x7F0A027C.
*/
void sub_GAME_7F0A027C(struct coord3d *arg0, f32 arg1, s16 arg2)
{
    Vtx sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    u8 sp4B;
    struct coord3d *temp_s0;
    u32 temp_hi;

    sp58 = D_80040920;

    sp54 = RANDOMFRAC() * M_TAU_F;
    sp4B = 0xFF - (randomGetNext() % 80U);

    temp_s0 = getRoomIndexPOS((s32) arg2);

    if (getPlayerCount() < 2)
    {
        if (arg1 > 200.0f)
        {
            arg1 = 200.0f;
        }

        arg1 *= (0.8f + (0.2f * RANDOMFRAC()));
        
        arg0->f[0] = (arg0->f[0] * get_room_data_float1()) - temp_s0->f[0];
        arg0->f[1] = (arg0->f[1] * get_room_data_float1()) - temp_s0->f[1];
        arg0->f[2] = (arg0->f[2] * get_room_data_float1()) - temp_s0->f[2];

        arg1 *= get_room_data_float1();

        sp50 = cosf(sp54) * arg1;
        sp4C = sinf(sp54) * arg1;

        ptr_scorch_buf[numScorchEntries].roomid = arg2;
        ptr_scorch_buf[numScorchEntries].unk04.f[0] = arg0->f[0];
        ptr_scorch_buf[numScorchEntries].unk04.f[1] = arg0->f[1];
        ptr_scorch_buf[numScorchEntries].unk04.f[2] = arg0->f[2];
        ptr_scorch_buf[numScorchEntries].unk10 = arg1;
        
        ptr_scorch_buf[numScorchEntries].vertex_list[0] = sp58;
        ptr_scorch_buf[numScorchEntries].vertex_list[1] = sp58;
        ptr_scorch_buf[numScorchEntries].vertex_list[2] = sp58;
        ptr_scorch_buf[numScorchEntries].vertex_list[3] = sp58;

        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.ob[0] = (s16) (s32) (arg0->f[0] + sp50);
        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.ob[1] = (s16) (s32) (arg0->f[1] + 0.5f);
        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.ob[2] = (s16) (s32) (arg0->f[2] + sp4C);
        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.tc[0] = 0;
        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.tc[1] = genericimage->width << 5;
        temp_hi = randomGetNext() % 50U;
        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.cn[2] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.cn[1] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.cn[0] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[0].v.cn[3] = sp4B;

        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.ob[0] = (s16) (s32) (arg0->f[0] + sp4C);
        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.ob[1] = (s16) (s32) (arg0->f[1] + 0.5f);
        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.ob[2] = (s16) (s32) (arg0->f[2] - sp50);
        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.tc[0] = 0;
        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.tc[1] = 0;
        temp_hi = randomGetNext() % 50U;
        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.cn[2] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.cn[1] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.cn[0] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[1].v.cn[3] = sp4B;
        
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.ob[0] = (s16) (s32) (arg0->f[0] - sp50);
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.ob[1] = (s16) (s32) (arg0->f[1] + 0.5f);
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.ob[2] = (s16) (s32) (arg0->f[2] - sp4C);
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.tc[0] = genericimage->height << 5;
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.tc[1] = 0;
        temp_hi = randomGetNext() % 50U;
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.cn[2] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.cn[1] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.cn[0] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[2].v.cn[3] = sp4B;
        
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.ob[0] = (s16) (s32) (arg0->f[0] - sp4C);
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.ob[1] = (s16) (s32) (arg0->f[1] + 0.5f);
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.ob[2] = (s16) (s32) (arg0->f[2] + sp50);
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.tc[0] = genericimage->width << 5;
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.tc[1] = genericimage->height << 5;
        temp_hi = randomGetNext() % 50U;
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.cn[2] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.cn[1] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.cn[0] = (u8) temp_hi;
        ptr_scorch_buf[numScorchEntries].vertex_list[3].v.cn[3] = sp4B;

        numScorchEntries++;
        if (numScorchEntries >= SCORCH_BUFFER_LEN)
        {
            numScorchEntries = 0;
        }
    }
}




/**
 * Address 0x7F0A0AB4.
*/
Gfx *sub_GAME_7F0A0AB4(Gfx *arg0)
{
    //temp_t6 = arg0;
    s32 i;
    s32 phi_s3 = -1;

    if (getPlayerCount() >= 2)
    {
        return arg0;
    }
    else
    {
        gSPSetGeometryMode(arg0++, G_CULL_BACK);
        gSPClearGeometryMode(arg0++, G_CULL_FRONT | G_FOG);
        gDPSetColorDither(arg0++, G_CD_NOISE);

        texSelect(&arg0, genericimage, 4, 1, 2);

        for (i=0; i<20; i++)
        {
            if (ptr_scorch_buf[i].roomid >= 0 && getROOMID_isRendered(ptr_scorch_buf[i].roomid))
            {
                if (phi_s3 != ptr_scorch_buf[i].roomid)
                {
                    phi_s3 = ptr_scorch_buf[i].roomid;
                    arg0 = sub_GAME_7F0BC9C4(arg0, ptr_scorch_buf[i].roomid);
                }

                /**
                 * Loads into the RSP vertex buffer the vertices that will be used by the gSP1Triangle commands that generates polygons.
                 *
                 * param v: the segment address of vertex list.
                 * param n: the number of vertices (1~32)
                 * param v0: Starting index in vertex buffer where vertices are to be loaded
                 * gSPVertex(Gfx *gdl, Vtx *v, u32 n, u32 v0)
                */
                gSPVertex(arg0++, osVirtualToPhysical((void*)ptr_scorch_buf[i].vertex_list), 4, 0);
                gSP2Triangles(arg0++,
                                0, 1, 2, 0,
                                0, 2, 3, 0);
            }
        }

        gDPSetColorDither(arg0++, G_CD_BAYER);
    }

    return arg0;
}





s32 sub_GAME_7F0A0C74(f32 arg0)
{
    if (arg0 >= 0.0f)
    {
        return (s32) (arg0 + 0.5f);
    }
    return (s32) (arg0 - 0.5f);
}



void sub_GAME_7F0A0CCC(PropRecord* arg0, s8 arg1)
{
    s32 i;
    for (i = 0; i < BULLET_IMPACT_BUFFER_LEN; i++)
    {
        if ((arg0 == ptr_bullet_impact_buf[i].unk48) && (arg1 == ptr_bullet_impact_buf[i].unk4D))
        {
            ptr_bullet_impact_buf[i].unk00 = -1;
        }
    }
}



void sub_GAME_7F0A0D90(PropRecord* arg0)
{
    s32 i;
    for (i = 0; i < BULLET_IMPACT_BUFFER_LEN; i++)
    {
        if ((arg0 == ptr_bullet_impact_buf[i].unk48) && (D_8004080C[ptr_bullet_impact_buf[i].unk02].unk1 == 2))
        {
            ptr_bullet_impact_buf[i].unk00 = -1;
        }
    }
}


void sub_GAME_7F0A0E98(s32 arg0)
{
    u32 val;
    s32 i;
    for (i = 0; i < SMOKE_PARTS_LEN; i++)
    {
        val = (u32) (((f32) i / 10.0f) * 255.0f);

        ptr_bullet_impact_buf[arg0].vertex_list[3].v.cn[3] = val; // alpha
        ptr_bullet_impact_buf[arg0].vertex_list[2].v.cn[3] = val; // alpha
        ptr_bullet_impact_buf[arg0].vertex_list[1].v.cn[3] = val; // alpha
        ptr_bullet_impact_buf[arg0].vertex_list[0].v.cn[3] = val; // alpha

        if (++arg0 >= BULLET_IMPACT_BUFFER_LEN)
        {
            arg0 = 0;
        }
    }
}


/***
 * NTSC address 0x7F0A108C.
*/
void sub_GAME_7F0A108C(struct coord3d *arg0, struct coord3d *arg1, s16 arg2, s16 arg3, PropRecord *arg4, s8 arg5, s8 arg6)
{
    Vtx spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 temp_f6;
    f32 temp_f2_2;
    f32 temp_f12;
    f32 spC4;
    struct coord3d *temp_s0_2;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    s32 temp_v1;
    struct coord3d spA0;
    f32 sp9C;
    f32 sp98;
    RenderPosView *temp_s1;
    ObjectRecord *temp_s0;
    f32 temp_f0;
    f32 sp88;
    s32 var_s1;
    struct coord3d sp78;
    struct coord3d sp6C;
    f32 zero = 0.0f;
    s_impacttype *sp50;
    u8 var_s0;
    u8 sp62;
    u8 sp61;

    spE0 = D_80040930;

    if (cheatIsActive(CHEAT_PAINTBALL))
    {
        arg2 = 0x10;
    }

    spA0.f[0] = arg0->f[0];
    spA0.f[1] = arg0->f[1];
    spA0.f[2] = arg0->f[2];

    sp50 = &D_8004080C[arg2];

    sp9C = sp50->width;
    sp98 = sp50->height;

    if ((arg1->f[0] == 0.0f) && (arg1->f[2] == 0.0f))
    {
        spB8 = 0.0f;
        spB4 = 0.0f;
        spBC = 0.0f;
        spB0 = 1.0f;
        spC4 = 1.0f;
    }
    else
    {
        temp_f0 = sqrtf((arg1->f[0] * arg1->f[0]) + (arg1->f[1] * arg1->f[1]) + (arg1->f[2] * arg1->f[2]));

        spDC = arg1->f[0] / temp_f0;
        spD8 = arg1->f[1] / temp_f0;
        spD4 = arg1->f[2] / temp_f0;

        temp_f0 = sqrtf((spDC * spDC) + (spD4 * spD4));

        temp_f2_2 = spDC / temp_f0;
        temp_f12 = spD4 / temp_f0;
        
        spBC = -temp_f2_2;
        spB8 = spD8 * temp_f2_2;
        spB4 = -temp_f0;
        spB0 = spD8 * temp_f12;
        spC4 = temp_f12;
    }

    if (arg4 != NULL)
    {
        temp_s0 = arg4->obj;
        temp_s1 = &temp_s0->model->render_pos[arg5];
        
        sp78.f[0] = spC4;
        sp78.f[1] = 0.0f;
        sp78.f[2] = spBC;
        
        sp6C.f[0] = spB8;
        sp6C.f[1] = spB4;
        sp6C.f[2] = spB0;
        
        mtx4RotateVecInPlace(&temp_s1->pos, &sp78);
        mtx4RotateVecInPlace(&temp_s1->pos, &sp6C);
        
        sp88 = sqrtf((sp78.f[0] * sp78.f[0]) + (sp78.f[1] * sp78.f[1]) + (sp78.f[2] * sp78.f[2]));
        temp_f6 = sqrtf((sp6C.f[0] * sp6C.f[0]) + (sp6C.f[1] * sp6C.f[1]) + (sp6C.f[2] * sp6C.f[2]));
        
        sp9C /= sp88;
        sp98 /= temp_f6;
        
        if ((sp50->unk2 < 2) && (sp50->unk1 == 2))
        {
            temp_s0->state |= PROPSTATE_2;
        }
        else
        {
            temp_s0->state |= PROPSTATE_DAMAGED;
        }
    }
    else
    {
        temp_s0_2 = getRoomIndexPOS((s32) arg3);
        spA0.f[0] = (spA0.f[0] * get_room_data_float1()) - temp_s0_2->f[0];
        spA0.f[1] = (spA0.f[1] * get_room_data_float1()) - temp_s0_2->f[1];
        spA0.f[2] = (spA0.f[2] * get_room_data_float1()) - temp_s0_2->f[2];
        sp9C *= get_room_data_float1();
        sp98 *= get_room_data_float1();
    }

    ptr_bullet_impact_buf[numImpactEntries].unk48 = arg4;
    ptr_bullet_impact_buf[numImpactEntries].unk4C = arg5;
    ptr_bullet_impact_buf[numImpactEntries].unk4D = arg6;
    ptr_bullet_impact_buf[numImpactEntries].unk00 = arg3;
    ptr_bullet_impact_buf[numImpactEntries].unk02 = arg2;

    ptr_bullet_impact_buf[numImpactEntries].vertex_list[0] = spE0;
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[1] = spE0;
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[2] = spE0;
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[3] = spE0;

    ptr_bullet_impact_buf[numImpactEntries].vertex_list[0].v.ob[0] = sub_GAME_7F0A0C74((spA0.f[0] - (sp9C * spC4)) - (sp98 * spB8));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[0].v.ob[1] = sub_GAME_7F0A0C74((spA0.f[1] - zero) - (sp98 * spB4));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[0].v.ob[2] = sub_GAME_7F0A0C74((spA0.f[2] - (sp9C * spBC)) - (sp98 * spB0));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[0].v.tc[0] = 0;
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[0].v.tc[1] = impactimages[arg2].height << 5;
    
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[1].v.ob[0] = sub_GAME_7F0A0C74((spA0.f[0] - (sp9C * spC4)) + (sp98 * spB8));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[1].v.ob[1] = sub_GAME_7F0A0C74((spA0.f[1] - zero) + (sp98 * spB4));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[1].v.ob[2] = sub_GAME_7F0A0C74((spA0.f[2] - (sp9C * spBC)) + (sp98 * spB0));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[1].v.tc[0] = 0;
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[1].v.tc[1] = 0;
    
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[2].v.ob[0] = sub_GAME_7F0A0C74(spA0.f[0] + (sp9C * spC4) + (sp98 * spB8));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[2].v.ob[1] = sub_GAME_7F0A0C74(spA0.f[1] + zero + (sp98 * spB4));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[2].v.ob[2] = sub_GAME_7F0A0C74(spA0.f[2] + (sp9C * spBC) + (sp98 * spB0));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[2].v.tc[0] = impactimages[arg2].width << 5;
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[2].v.tc[1] = 0;
    
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[3].v.ob[0] = sub_GAME_7F0A0C74((spA0.f[0] + (sp9C * spC4)) - (sp98 * spB8));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[3].v.ob[1] = sub_GAME_7F0A0C74((spA0.f[1] + zero) - (sp98 * spB4));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[3].v.ob[2] = sub_GAME_7F0A0C74((spA0.f[2] + (sp9C * spBC)) - (sp98 * spB0));
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[3].v.tc[0] = impactimages[arg2].width << 5;
    ptr_bullet_impact_buf[numImpactEntries].vertex_list[3].v.tc[1] = impactimages[arg2].height << 5;
    
    for (var_s1 = 0; var_s1 < 4; var_s1++)
    {
        switch (sp50->apptype)
        {
            default:
                var_s0 = 0;
            break;

            case 1:
                temp_v1 = 0xFF - (randomGetNext() % 40U);
                sp61 = temp_v1;
                sp62 = temp_v1;
                var_s0 = temp_v1;
            break;

            case 0:
                temp_v1 = randomGetNext() % 40U;
                sp61 = temp_v1;
                sp62 = temp_v1;
                var_s0 = temp_v1;
            break;

            case 2:
                var_s0 = (randomGetNext() & 1) ? 0xff : 0;
                sp62 = (randomGetNext() & 1) ? 0xff : 0;
                sp61 = (randomGetNext() & 1) ? 0xff : 0;
            break;
        }

        ptr_bullet_impact_buf[numImpactEntries].vertex_list[var_s1].v.cn[0] = var_s0;
        ptr_bullet_impact_buf[numImpactEntries].vertex_list[var_s1].v.cn[1] = sp62;
        ptr_bullet_impact_buf[numImpactEntries].vertex_list[var_s1].v.cn[2] = sp61;
        ptr_bullet_impact_buf[numImpactEntries].vertex_list[var_s1].v.cn[3] = 0xff; // alpha
    }

    numImpactEntries++;
    if (numImpactEntries >= BULLET_IMPACT_BUFFER_LEN)
    {
        numImpactEntries = 0;
    }
    
    sub_GAME_7F0A0E98(numImpactEntries);
    
    ptr_bullet_impact_buf[numImpactEntries].unk00 = -1;
}





#ifdef NONMATCHING
void explosionRenderBulletImpactOnProp(void) {

}
#else
GLOBAL_ASM(
.text
glabel explosionRenderBulletImpactOnProp
/* 0D65C4 7F0A1A94 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0D65C8 7F0A1A98 AFB60038 */  sw    $s6, 0x38($sp)
/* 0D65CC 7F0A1A9C AFB50034 */  sw    $s5, 0x34($sp)
/* 0D65D0 7F0A1AA0 240EFFFF */  li    $t6, -1
/* 0D65D4 7F0A1AA4 00A0B025 */  move  $s6, $a1
/* 0D65D8 7F0A1AA8 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D65DC 7F0A1AAC AFBE0040 */  sw    $fp, 0x40($sp)
/* 0D65E0 7F0A1AB0 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0D65E4 7F0A1AB4 AFB40030 */  sw    $s4, 0x30($sp)
/* 0D65E8 7F0A1AB8 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0D65EC 7F0A1ABC AFB20028 */  sw    $s2, 0x28($sp)
/* 0D65F0 7F0A1AC0 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D65F4 7F0A1AC4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D65F8 7F0A1AC8 AFA40060 */  sw    $a0, 0x60($sp)
/* 0D65FC 7F0A1ACC AFA60068 */  sw    $a2, 0x68($sp)
/* 0D6600 7F0A1AD0 2415FFFF */  li    $s5, -1
/* 0D6604 7F0A1AD4 AFA00050 */  sw    $zero, 0x50($sp)
/* 0D6608 7F0A1AD8 AFA0004C */  sw    $zero, 0x4c($sp)
/* 0D660C 7F0A1ADC 10A00003 */  beqz  $a1, .L7F0A1AEC
/* 0D6610 7F0A1AE0 AFAE0048 */   sw    $t6, 0x48($sp)
/* 0D6614 7F0A1AE4 8CAF0004 */  lw    $t7, 4($a1)
/* 0D6618 7F0A1AE8 AFAF004C */  sw    $t7, 0x4c($sp)
.L7F0A1AEC:
/* 0D661C 7F0A1AEC 8FB80060 */  lw    $t8, 0x60($sp)
/* 0D6620 7F0A1AF0 3C08B600 */  lui   $t0, 0xb600
/* 0D6624 7F0A1AF4 24093000 */  li    $t1, 12288
/* 0D6628 7F0A1AF8 27190008 */  addiu $t9, $t8, 8
/* 0D662C 7F0A1AFC AFB90060 */  sw    $t9, 0x60($sp)
/* 0D6630 7F0A1B00 AF090004 */  sw    $t1, 4($t8)
/* 0D6634 7F0A1B04 AF080000 */  sw    $t0, ($t8)
/* 0D6638 7F0A1B08 8FAA0060 */  lw    $t2, 0x60($sp)
/* 0D663C 7F0A1B0C 3C0CBA00 */  lui   $t4, (0xBA000602 >> 16) # lui $t4, 0xba00
/* 0D6640 7F0A1B10 358C0602 */  ori   $t4, (0xBA000602 & 0xFFFF) # ori $t4, $t4, 0x602
/* 0D6644 7F0A1B14 254B0008 */  addiu $t3, $t2, 8
/* 0D6648 7F0A1B18 AFAB0060 */  sw    $t3, 0x60($sp)
/* 0D664C 7F0A1B1C 240D0080 */  li    $t5, 128
/* 0D6650 7F0A1B20 3C1E8004 */  lui   $fp, %hi(D_8004080C)
/* 0D6654 7F0A1B24 3C178008 */  lui   $s7, %hi(ptr_bullet_impact_buf)
/* 0D6658 7F0A1B28 26F7A154 */  addiu $s7, %lo(ptr_bullet_impact_buf) # addiu $s7, $s7, -0x5eac
/* 0D665C 7F0A1B2C 27DE080C */  addiu $fp, %lo(D_8004080C) # addiu $fp, $fp, 0x80c
/* 0D6660 7F0A1B30 0000A025 */  move  $s4, $zero
/* 0D6664 7F0A1B34 AD4D0004 */  sw    $t5, 4($t2)
/* 0D6668 7F0A1B38 AD4C0000 */  sw    $t4, ($t2)
/* 0D666C 7F0A1B3C 8EEE0000 */  lw    $t6, ($s7)
.L7F0A1B40:
/* 0D6670 7F0A1B40 01D41821 */  addu  $v1, $t6, $s4
/* 0D6674 7F0A1B44 8C6F0048 */  lw    $t7, 0x48($v1)
/* 0D6678 7F0A1B48 56CF0068 */  bnel  $s6, $t7, .L7F0A1CEC
/* 0D667C 7F0A1B4C 26940050 */   addiu $s4, $s4, 0x50
/* 0D6680 7F0A1B50 84650000 */  lh    $a1, ($v1)
/* 0D6684 7F0A1B54 04A20065 */  bltzl $a1, .L7F0A1CEC
/* 0D6688 7F0A1B58 26940050 */   addiu $s4, $s4, 0x50
/* 0D668C 7F0A1B5C 56C00008 */  bnezl $s6, .L7F0A1B80
/* 0D6690 7F0A1B60 8FB90068 */   lw    $t9, 0x68($sp)
/* 0D6694 7F0A1B64 0FC2D794 */  jal   getROOMID_isRendered
/* 0D6698 7F0A1B68 00A02025 */   move  $a0, $a1
/* 0D669C 7F0A1B6C 5040005F */  beql  $v0, $zero, .L7F0A1CEC
/* 0D66A0 7F0A1B70 26940050 */   addiu $s4, $s4, 0x50
/* 0D66A4 7F0A1B74 8EF80000 */  lw    $t8, ($s7)
/* 0D66A8 7F0A1B78 03141821 */  addu  $v1, $t8, $s4
/* 0D66AC 7F0A1B7C 8FB90068 */  lw    $t9, 0x68($sp)
.L7F0A1B80:
/* 0D66B0 7F0A1B80 84730002 */  lh    $s3, 2($v1)
/* 0D66B4 7F0A1B84 240C0001 */  li    $t4, 1
/* 0D66B8 7F0A1B88 1320000D */  beqz  $t9, .L7F0A1BC0
/* 0D66BC 7F0A1B8C 00139080 */   sll   $s2, $s3, 2
/* 0D66C0 7F0A1B90 00139080 */  sll   $s2, $s3, 2
/* 0D66C4 7F0A1B94 02539023 */  subu  $s2, $s2, $s3
/* 0D66C8 7F0A1B98 00129080 */  sll   $s2, $s2, 2
/* 0D66CC 7F0A1B9C 03D28021 */  addu  $s0, $fp, $s2
/* 0D66D0 7F0A1BA0 9202000A */  lbu   $v0, 0xa($s0)
/* 0D66D4 7F0A1BA4 28480002 */  slti  $t0, $v0, 2
/* 0D66D8 7F0A1BA8 11000010 */  beqz  $t0, .L7F0A1BEC
/* 0D66DC 7F0A1BAC 01001025 */   move  $v0, $t0
/* 0D66E0 7F0A1BB0 92020009 */  lbu   $v0, 9($s0)
/* 0D66E4 7F0A1BB4 38490002 */  xori  $t1, $v0, 2
/* 0D66E8 7F0A1BB8 1000000C */  b     .L7F0A1BEC
/* 0D66EC 7F0A1BBC 2D220001 */   sltiu $v0, $t1, 1
.L7F0A1BC0:
/* 0D66F0 7F0A1BC0 02539023 */  subu  $s2, $s2, $s3
/* 0D66F4 7F0A1BC4 00129080 */  sll   $s2, $s2, 2
/* 0D66F8 7F0A1BC8 03D28021 */  addu  $s0, $fp, $s2
/* 0D66FC 7F0A1BCC 9202000A */  lbu   $v0, 0xa($s0)
/* 0D6700 7F0A1BD0 284A0002 */  slti  $t2, $v0, 2
/* 0D6704 7F0A1BD4 39420001 */  xori  $v0, $t2, 1
/* 0D6708 7F0A1BD8 14400004 */  bnez  $v0, .L7F0A1BEC
/* 0D670C 7F0A1BDC 00000000 */   nop
/* 0D6710 7F0A1BE0 92020009 */  lbu   $v0, 9($s0)
/* 0D6714 7F0A1BE4 384B0002 */  xori  $t3, $v0, 2
/* 0D6718 7F0A1BE8 000B102B */  sltu  $v0, $zero, $t3
.L7F0A1BEC:
/* 0D671C 7F0A1BEC 5040003F */  beql  $v0, $zero, .L7F0A1CEC
/* 0D6720 7F0A1BF0 26940050 */   addiu $s4, $s4, 0x50
/* 0D6724 7F0A1BF4 12C00014 */  beqz  $s6, .L7F0A1C48
/* 0D6728 7F0A1BF8 AFAC0050 */   sw    $t4, 0x50($sp)
/* 0D672C 7F0A1BFC 8062004C */  lb    $v0, 0x4c($v1)
/* 0D6730 7F0A1C00 8FAE004C */  lw    $t6, 0x4c($sp)
/* 0D6734 7F0A1C04 8FB10060 */  lw    $s1, 0x60($sp)
/* 0D6738 7F0A1C08 12A20018 */  beq   $s5, $v0, .L7F0A1C6C
/* 0D673C 7F0A1C0C 00026980 */   sll   $t5, $v0, 6
/* 0D6740 7F0A1C10 8DCF0014 */  lw    $t7, 0x14($t6)
/* 0D6744 7F0A1C14 0002AC00 */  sll   $s5, $v0, 0x10
/* 0D6748 7F0A1C18 26290008 */  addiu $t1, $s1, 8
/* 0D674C 7F0A1C1C 8DF8000C */  lw    $t8, 0xc($t7)
/* 0D6750 7F0A1C20 3C0A0102 */  lui   $t2, (0x01020040 >> 16) # lui $t2, 0x102
/* 0D6754 7F0A1C24 0015CC03 */  sra   $t9, $s5, 0x10
/* 0D6758 7F0A1C28 354A0040 */  ori   $t2, (0x01020040 & 0xFFFF) # ori $t2, $t2, 0x40
/* 0D675C 7F0A1C2C AFA90060 */  sw    $t1, 0x60($sp)
/* 0D6760 7F0A1C30 0320A825 */  move  $s5, $t9
/* 0D6764 7F0A1C34 AE2A0000 */  sw    $t2, ($s1)
/* 0D6768 7F0A1C38 0C003A2C */  jal   osVirtualToPhysical
/* 0D676C 7F0A1C3C 01B82021 */   addu  $a0, $t5, $t8
/* 0D6770 7F0A1C40 1000000A */  b     .L7F0A1C6C
/* 0D6774 7F0A1C44 AE220004 */   sw    $v0, 4($s1)
.L7F0A1C48:
/* 0D6778 7F0A1C48 84650000 */  lh    $a1, ($v1)
/* 0D677C 7F0A1C4C 8FA40060 */  lw    $a0, 0x60($sp)
/* 0D6780 7F0A1C50 52A50007 */  beql  $s5, $a1, .L7F0A1C70
/* 0D6784 7F0A1C54 8FAC0048 */   lw    $t4, 0x48($sp)
/* 0D6788 7F0A1C58 0005AC00 */  sll   $s5, $a1, 0x10
/* 0D678C 7F0A1C5C 00155C03 */  sra   $t3, $s5, 0x10
/* 0D6790 7F0A1C60 0FC2F271 */  jal   sub_GAME_7F0BC9C4
/* 0D6794 7F0A1C64 0160A825 */   move  $s5, $t3
/* 0D6798 7F0A1C68 AFA20060 */  sw    $v0, 0x60($sp)
.L7F0A1C6C:
/* 0D679C 7F0A1C6C 8FAC0048 */  lw    $t4, 0x48($sp)
.L7F0A1C70:
/* 0D67A0 7F0A1C70 27A40060 */  addiu $a0, $sp, 0x60
/* 0D67A4 7F0A1C74 3C0E8009 */  lui   $t6, %hi(impactimages)
/* 0D67A8 7F0A1C78 11930008 */  beq   $t4, $s3, .L7F0A1C9C
/* 0D67AC 7F0A1C7C 240F0002 */   li    $t7, 2
/* 0D67B0 7F0A1C80 8DCED0BC */  lw    $t6, %lo(impactimages)($t6)
/* 0D67B4 7F0A1C84 92060009 */  lbu   $a2, 9($s0)
/* 0D67B8 7F0A1C88 9207000A */  lbu   $a3, 0xa($s0)
/* 0D67BC 7F0A1C8C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0D67C0 7F0A1C90 0FC1DB5A */  jal   texSelect
/* 0D67C4 7F0A1C94 024E2821 */   addu  $a1, $s2, $t6
/* 0D67C8 7F0A1C98 AFB30048 */  sw    $s3, 0x48($sp)
.L7F0A1C9C:
/* 0D67CC 7F0A1C9C 8FB00060 */  lw    $s0, 0x60($sp)
/* 0D67D0 7F0A1CA0 3C190430 */  lui   $t9, (0x04300040 >> 16) # lui $t9, 0x430
/* 0D67D4 7F0A1CA4 37390040 */  ori   $t9, (0x04300040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0D67D8 7F0A1CA8 26180008 */  addiu $t8, $s0, 8
/* 0D67DC 7F0A1CAC AFB80060 */  sw    $t8, 0x60($sp)
/* 0D67E0 7F0A1CB0 AE190000 */  sw    $t9, ($s0)
/* 0D67E4 7F0A1CB4 8EE80000 */  lw    $t0, ($s7)
/* 0D67E8 7F0A1CB8 01142021 */  addu  $a0, $t0, $s4
/* 0D67EC 7F0A1CBC 0C003A2C */  jal   osVirtualToPhysical
/* 0D67F0 7F0A1CC0 24840008 */   addiu $a0, $a0, 8
/* 0D67F4 7F0A1CC4 AE020004 */  sw    $v0, 4($s0)
/* 0D67F8 7F0A1CC8 8FA90060 */  lw    $t1, 0x60($sp)
/* 0D67FC 7F0A1CCC 3C0BB100 */  lui   $t3, (0xB1000032 >> 16) # lui $t3, 0xb100
/* 0D6800 7F0A1CD0 356B0032 */  ori   $t3, (0xB1000032 & 0xFFFF) # ori $t3, $t3, 0x32
/* 0D6804 7F0A1CD4 252A0008 */  addiu $t2, $t1, 8
/* 0D6808 7F0A1CD8 AFAA0060 */  sw    $t2, 0x60($sp)
/* 0D680C 7F0A1CDC 240C2010 */  li    $t4, 8208
/* 0D6810 7F0A1CE0 AD2C0004 */  sw    $t4, 4($t1)
/* 0D6814 7F0A1CE4 AD2B0000 */  sw    $t3, ($t1)
/* 0D6818 7F0A1CE8 26940050 */  addiu $s4, $s4, 0x50
.L7F0A1CEC:
/* 0D681C 7F0A1CEC 24011F40 */  li    $at, 8000
/* 0D6820 7F0A1CF0 5681FF93 */  bnel  $s4, $at, .L7F0A1B40
/* 0D6824 7F0A1CF4 8EEE0000 */   lw    $t6, ($s7)
/* 0D6828 7F0A1CF8 12C0000A */  beqz  $s6, .L7F0A1D24
/* 0D682C 7F0A1CFC 8FAE0050 */   lw    $t6, 0x50($sp)
/* 0D6830 7F0A1D00 15C00008 */  bnez  $t6, .L7F0A1D24
/* 0D6834 7F0A1D04 8FAF004C */   lw    $t7, 0x4c($sp)
/* 0D6838 7F0A1D08 8FB80068 */  lw    $t8, 0x68($sp)
/* 0D683C 7F0A1D0C 91ED0002 */  lbu   $t5, 2($t7)
/* 0D6840 7F0A1D10 24190001 */  li    $t9, 1
/* 0D6844 7F0A1D14 03194004 */  sllv  $t0, $t9, $t8
/* 0D6848 7F0A1D18 01004827 */  not   $t1, $t0
/* 0D684C 7F0A1D1C 01A95024 */  and   $t2, $t5, $t1
/* 0D6850 7F0A1D20 A1EA0002 */  sb    $t2, 2($t7)
.L7F0A1D24:
/* 0D6854 7F0A1D24 8FAB0060 */  lw    $t3, 0x60($sp)
/* 0D6858 7F0A1D28 3C0EBA00 */  lui   $t6, (0xBA000602 >> 16) # lui $t6, 0xba00
/* 0D685C 7F0A1D2C 35CE0602 */  ori   $t6, (0xBA000602 & 0xFFFF) # ori $t6, $t6, 0x602
/* 0D6860 7F0A1D30 256C0008 */  addiu $t4, $t3, 8
/* 0D6864 7F0A1D34 AFAC0060 */  sw    $t4, 0x60($sp)
/* 0D6868 7F0A1D38 24190040 */  li    $t9, 64
/* 0D686C 7F0A1D3C AD790004 */  sw    $t9, 4($t3)
/* 0D6870 7F0A1D40 AD6E0000 */  sw    $t6, ($t3)
/* 0D6874 7F0A1D44 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0D6878 7F0A1D48 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0D687C 7F0A1D4C 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0D6880 7F0A1D50 8FB60038 */  lw    $s6, 0x38($sp)
/* 0D6884 7F0A1D54 8FB50034 */  lw    $s5, 0x34($sp)
/* 0D6888 7F0A1D58 8FB40030 */  lw    $s4, 0x30($sp)
/* 0D688C 7F0A1D5C 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0D6890 7F0A1D60 8FB20028 */  lw    $s2, 0x28($sp)
/* 0D6894 7F0A1D64 8FB10024 */  lw    $s1, 0x24($sp)
/* 0D6898 7F0A1D68 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D689C 7F0A1D6C 8FA20060 */  lw    $v0, 0x60($sp)
/* 0D68A0 7F0A1D70 03E00008 */  jr    $ra
/* 0D68A4 7F0A1D74 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif






Gfx * sub_GAME_7F0A1D78(Gfx *arg0)
{
    return explosionRenderBulletImpactOnProp(arg0, NULL, 0);
}


