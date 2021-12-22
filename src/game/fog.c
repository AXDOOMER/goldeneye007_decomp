#include "ultra64.h"

#include "bondtypes.h"
#include "bondconstants.h"
#include "fr.h"
#include "game/bg.h"
#include "game/bondview.h"
#include "game/fog.h"

// internal struct
struct FogDetails
{
    f32 g_CurFogDetails;
    f32 scaled_far_fog_dist;
    u32 unk08;
    u32 unk0c;
    f32 far_fog_dist_scaled;
    f32 near_fog_dist_scaled;
};

/**
 * Address 0x800825C0.
*/
s32 g_FogSkyIsEnabled;

/**
 * Address 0x800825C4.
*/
struct NearFogData *g_NearFogValuesP;

/**
 * Address 0x800825C8.
*/
struct FogDetails g_CurFogDetails;

/**
 * Address 0x800825E0.
*/
f32 g_FarFogIntensity;

/**
 * Address 0x800825E4.
*/
f32 g_DifferenceFromFarFogIntensity;

/**
 * Address 0x800825E8.
*/
struct EnvironmentData *g_EnvironmentFoundp;

/**
 * Address 0x800825EC.
*/
struct EnvironmentData * g_EnvironmentMainp;

/**
 * Address 0x800825F0.
*/
struct EnvironmentData * g_EnvironmentAltp;

/**
 * Unreferenced.
 * 
 * Address 0x800825F4.
*/
s32 D_800825F4;

/**
 * Unreferenced.
 * 
 * Address 0x80044DC0.
*/
s32 D_80044DC0 = 0;

/**
 * Address 0x80044DC4.
*/
f32 g_ScaledFarFogIntensity = 3.4028235e38;

/**
 * Address 0x80044DC8.
*/
f32 g_ScaledDifferenceFromFarFogIntensity = 0.0;

/**
 * Address 0x80044DCC.
*/
struct CurrentEnvData g_CurrentEnvironment = { 
    {
        0x384, // s32 DifferenceFromFarIntensity;
        0x3e8 // u32 FarIntensity;
    },
    {
        0,     // u8  Red;
        0,     // u8  Green;
        0,     // u8  Blue;
        0,     // u8  Clouds;
        0.0f,  // f32 CloudRepeat;
        0,     // s16 SkyImageId;
        0,
        0.0f,  // f32 CloudRed;
        0.0f,  // f32 CloudGreen;
        0.0f,  // f32 CloudBlue;
        0,     // u8  IsWater;
        0,0,0,
        0.0f,  // f32 WaterRepeat;
        0,     // s16 WaterImageId;
        0,
        0.0f,  // f32 WaterRed;
        0.0f,  // f32 WaterGreen;
        0.0f,  // f32 WaterBlue;
        0.0f  // f32 WaterConcavity;
    }
};

s32 D_80044E08 = 0;
s32 D_80044E0C = 0;


/**
 * Address 0x80044E10.
*/
struct EnvironmentData fog_tables[] = {
     //stageID                              blendmultiplier    farfog    nearfog  mvisrng  mobfnrng  mnvisrng   intensity  dif_ght  far_alight    red     green     blue    clouds   cloudrept skyimid reserved  cloudred   green    blue   iswater  padding[3]  waterrepeat  waterid reserved2   water red,green,blue  waterconcavity
    {LEVELID_STATUE                             ,        15,      3500,    2000,     2500,    2000,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,    0,        0,        170,    100,     40,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,    30.0 },
    {LEVELID_CONTROL                            ,        10,     10000,    2500,     5000,     800,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,    0,        0,          0,      0,      0,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_ARCHIVES                           ,        10,      3000,    2000,     3000,     500,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_TRAIN                              ,        10,      1500,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,             0,       1,        0,        0,   255,  255,    25.0 },
    {LEVELID_TRAIN + ENVIRONMENTDATA_ALT        ,        20,     15000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,             0,       1,        0,        0,   255,  255,    25.0 },
    {LEVELID_STREETS                            ,        10,      7500,    5000,     6000,    1000,        0,      0x3E7,    0x3E4,    0x3E8,    0x10,    0x18,    0x20,        1,      5000,    0,        0,        225,    175,    100,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,    25.0 },
    {LEVELID_DEPOT                              ,        10,      3000,    1600,     2000,     800,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       8,        1,      7500,    0,        0,         70,    199,    186,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,    25.0 },
    {LEVELID_COMPLEX                            ,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,    0,        0,        220,      0,     20,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_DAM                                ,         5,     15000,    3333,     4444,     600,        0,      0x3E7,    0x3E3,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_DAM + ENVIRONMENTDATA_CINEMA       ,        30,     15000,    3333,     4444,     600,        0,      0x3E7,    0x3E3,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_FACILITY                           ,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3DE,    0x3E8,    0x10,    0x20,    0x10,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_FACILITY + ENVIRONMENTDATA_ALT     ,        10,      1000,       0,        0,       0,        0,      0x3E7,    0x3DE,    0x3E8,    0x40,    0x80,    0x40,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_RUNWAY                             ,        10,     15000,    6000,     8000,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x10,    0x30,    0x40,        1,      5000,    0,        0,         25,     25,     25,        0,    0,0,0,         -1000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_SURFACE                            ,         2,      2500,    4444,     5555,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x60,    0x80,        1,     10000,    0,        0,        240,    120,    30,         0,    0,0,0,             0,       1,        0,        0,   255,  255,     7.0 },
    {LEVELID_JUNGLE                             ,        10,      2500,    1500,     2500,    1000,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x20,       0,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_TEMPLE                             ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x18,    0x28,        1,     10000,    0,        0,        160,    160,    190,        0,    0,0,0,          -500,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_CAVERNS                            ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -3000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CRADLE                             ,        10,      9500,    3333,     4444,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,    0,        0,        255,    255,      0,        0,    0,0,0,        -10000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_SURFACE2                           ,         2,      2000,    2500,     3055,     750,        0,      0x3E7,    0x3BD,    0x3E8,    0x20,    0x10,    0x10,        1,      5000,    0,        0,         58,     17,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,    20.0 },
    {LEVELID_SURFACE2 + ENVIRONMENTDATA_CINEMA  ,         2,      8000,    6000,     8000,     800,        0,      0x3E7,    0x3DF,    0x3E8,    0x20,    0x10,    0x10,        1,      5000,    0,        0,         58,     17,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_BUNKER2                            ,        10,     10000,    1000,    15000,     750,        0,      0x3E7,    0x3E4,    0x41A,    0x10,       0,       0,        1,      5000,    0,        0,         58,     17,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_2,        10,      2500,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,    0,        0,        130,    120,    110,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_3,        10,      2000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,    0,        0,        130,    120,    110,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_4,        10,      1500,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,    0,        0,        130,    120,    110,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_2 ,        10,      7000,    3333,     4444,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,    0,        0,        255,    255,      0,        0,    0,0,0,        -10000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_3 ,        10,      5500,    3333,     4444,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,    0,        0,        255,    255,      0,        0,    0,0,0,        -10000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_4 ,        10,      4000,    3333,     4444,     800,        0,      0x3E7,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,    0,        0,        255,    255,      0,        0,    0,0,0,        -10000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_2 ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,    0,        0,        120,    120,    120,        0,    0,0,0,          -500,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_3 ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,    0,        0,        120,    120,    120,        0,    0,0,0,          -500,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_4 ,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,    0,        0,        120,    120,    120,        0,    0,0,0,          -500,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_2,        10,      7500,       0,        0,       0,        0,      0x3E7,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -3000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_3,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -3000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -3000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_2,        10,      7500,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,    0,        0,          0,      0,      0,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_3,        10,      6000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,    0,        0,          0,      0,      0,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,    0,        0,          0,      0,      0,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_CITADEL                            ,        10,     20000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,    0,        0,        255,    108,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_2,        10,     20000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,    0,        0,        255,    108,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_3,        10,     20000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,    0,        0,        255,    108,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_4,        10,     20000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,    0,        0,        255,    108,      0,        0,    0,0,0,         -1000,       1,        0,        0,   255,  255,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_2,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,    0,        0,        220,      0,     20,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_3,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,    0,        0,        220,      0,     20,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,        0,      0x3E7,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,    0,        0,        220,      0,     20,        0,    0,0,0,             0,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_AZTEC                              ,        10,     15000,    3000,     4000,     600,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        1,      7500,    0,        0,         83,     72,     65,        0,    0,0,0,         -5000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_AZTEC + ENVIRONMENTDATA_ALT        ,        30,     15000,    3000,     4000,     600,        0,      0x3E7,    0x3E4,    0x3E8,       0,       0,       0,        1,      7500,    0,        0,         83,     72,     65,        0,    0,0,0,         -5000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_EGYPT                              ,        10,     20000,    3000,     4000,     600,        0,      0x3E7,    0x3E4,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,    0,        0,        255,    255,    255,        0,    0,0,0,         -5000,       0,        0,        0,     0,    0,     0.0 },
    {LEVELID_EGYPT + ENVIRONMENTDATA_ALT        ,        10,     10000,    3000,     4000,     600,        0,      0x3E7,    0x3CC,    0x3E8,       0,       0,       0,        1,      7500,    0,        0,         83,     10,     10,        0,    0,0,0,         -5000,       0,        0,        0,     0,    0,     0.0 },
    {ENVIRONMENTDATA_END},

};

struct EnvironmentData_Fogless fog_tables2[] = {
    {LEVELID_NONE   ,    0,       0x10,    0x40,    0,        5000.0,        0,        0,        255.0,        255.0,        255.0,        0,        0,        0,        0,           0.0,        0,        0,          0.0,          0.0,          0.0,        0.0},
    {LEVELID_FRIGATE,    0x10,    0x30,    0x60,    1,        3000.0,        0,        0,        230.0,        230.0,        230.0,        1,        0,        0,        0,        -150.0,        2,        0,        255.0,        255.0,        150.0,        0.0},
    {LEVELID_CUBA   ,    0x30,    0x40,    0x10,    0,        5000.0,        0,        0,        255.0,        255.0,        255.0,        0,        0,        0,        0,           0.0,        0,        0,          0.0,          0.0,          0.0,        0.0},
    {ENVIRONMENTDATA_END}
};

// forward declarations

void fogLoadCurrentEnvironment(struct EnvironmentData *arg0);
void fogLoadFoglessCurrentEnvironment(struct EnvironmentData_Fogless *arg0);

// end forward declarations



/**
 * Unreferenced.
 * 
 * Address 0x7F0BA720.
*/
void sub_GAME_7F0BA720(s32 a, s32 b)
{
    return;
}


struct CurrentEnvData *fogGetCurrentEnvironmentp(void)
{
    return &g_CurrentEnvironment;
}


/**
 * Unreferenced.
*/
f32 fogGetScaledFarFogIntensity(void)
{
    return g_ScaledFarFogIntensity;
}


f32 fogGetScaledFarFogIntensitySquared(void)
{
    return g_ScaledFarFogIntensity * g_ScaledFarFogIntensity;
}


#if defined(VERSION_US) || defined(VERSION_JP)
/**
 * Address 0x7F0BA758.
*/
void fogLoadCurrentEnvironment(struct EnvironmentData *arg0)
{
    f32 zrange[2]; // 48
    f32 pk0;
    f32 pk4;
    f32 temp_f0;
    f32 sp20; // 32
    f32 sp1C; // 28

    viSetZRange(arg0->Visibility.BlendMultiplier, arg0->Visibility.FarFog);
    viGetZRange(&zrange);

    temp_f0 = sub_GAME_7F0B4878();
    zrange[0] /= temp_f0;
    zrange[1] /= temp_f0;

    g_DifferenceFromFarFogIntensity = ((f32) arg0->Fog.DifferenceFromFarIntensity / 1000.0f);
    g_FarFogIntensity = ((f32) arg0->Fog.FarIntensity / 1000.0f);

    g_ScaledFarFogIntensity = ((zrange[1] - zrange[0]) *  g_FarFogIntensity) + zrange[0];
    g_ScaledDifferenceFromFarFogIntensity = ((zrange[1] - zrange[0]) * g_DifferenceFromFarFogIntensity) + zrange[0];

    g_CurFogDetails.g_CurFogDetails = (arg0->Visibility.BlendMultiplier / temp_f0);
    pk0 = g_CurFogDetails.g_CurFogDetails;
    g_CurFogDetails.scaled_far_fog_dist = (arg0->Visibility.FarFog / temp_f0);
    pk4 = g_CurFogDetails.scaled_far_fog_dist;

    // numerator is constant 128.0f
    sp20 = (256.0f * (0.5f -         0.0f)) / (g_FarFogIntensity - g_DifferenceFromFarFogIntensity);
    sp1C = (256.0f * (0.5f - g_DifferenceFromFarFogIntensity)) / (g_FarFogIntensity - g_DifferenceFromFarFogIntensity);

    g_CurFogDetails.far_fog_dist_scaled = ((pk4 * -sp20 * (pk0 + 1.0f)) / (pk4 - pk0)) / 255.0f;
    g_CurFogDetails.near_fog_dist_scaled = ((sp20 * (pk4 + 1.0f) / (pk4 - pk0)) + sp1C) / 255.0f;

    g_CurrentEnvironment.Fog.DifferenceFromFarIntensity = (s32) arg0->Fog.DifferenceFromFarIntensity;
    g_CurrentEnvironment.Fog.FarIntensity = arg0->Fog.FarIntensity;
    g_CurrentEnvironment.Sky.Red = arg0->Sky.Red;
    g_CurrentEnvironment.Sky.Green = arg0->Sky.Green;
    g_CurrentEnvironment.Sky.Blue = arg0->Sky.Blue;
    g_CurrentEnvironment.Sky.Clouds = arg0->Sky.Clouds;
    g_CurrentEnvironment.Sky.CloudRepeat = arg0->Sky.CloudRepeat;
    g_CurrentEnvironment.Sky.SkyImageId = (s16) arg0->Sky.SkyImageId;
    g_CurrentEnvironment.Sky.CloudRed = arg0->Sky.CloudRed;
    g_CurrentEnvironment.Sky.CloudGreen = arg0->Sky.CloudGreen;
    g_CurrentEnvironment.Sky.CloudBlue = arg0->Sky.CloudBlue;
    g_CurrentEnvironment.Sky.IsWater = arg0->Sky.IsWater;
    g_CurrentEnvironment.Sky.WaterRepeat = arg0->Sky.WaterRepeat;
    g_CurrentEnvironment.Sky.WaterImageId = (s16) arg0->Sky.WaterImageId;
    g_CurrentEnvironment.Sky.WaterRed = arg0->Sky.WaterRed;
    g_CurrentEnvironment.Sky.WaterGreen = arg0->Sky.WaterGreen;
    g_CurrentEnvironment.Sky.WaterBlue = arg0->Sky.WaterBlue;
    g_CurrentEnvironment.Sky.WaterConcavity = arg0->Sky.WaterConcavity;

    if (arg0->Visibility.Nfd.NearFog == 0.0f)
    {
        g_NearFogValuesP = NULL;
    }
    else
    {
        g_NearFogValuesP = &arg0->Visibility.Nfd;
    }

    g_FogSkyIsEnabled = 1;
}
#endif
#if defined(VERSION_EU)
GLOBAL_ASM(
.text
glabel fogLoadCurrentEnvironment
/* 0EC3E8 7F0B99F8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0EC3EC 7F0B99FC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EC3F0 7F0B9A00 848F0004 */  lh    $t7, 4($a0)
/* 0EC3F4 7F0B9A04 848E0002 */  lh    $t6, 2($a0)
/* 0EC3F8 7F0B9A08 AFA40038 */  sw    $a0, 0x38($sp)
/* 0EC3FC 7F0B9A0C 448F3000 */  mtc1  $t7, $f6
/* 0EC400 7F0B9A10 448E2000 */  mtc1  $t6, $f4
/* 0EC404 7F0B9A14 468033A0 */  cvt.s.w $f14, $f6
/* 0EC408 7F0B9A18 0C001028 */  jal   viSetZRange
/* 0EC40C 7F0B9A1C 46802320 */   cvt.s.w $f12, $f4
/* 0EC410 7F0B9A20 0C00103F */  jal   viGetZRange
/* 0EC414 7F0B9A24 27A40030 */   addiu $a0, $sp, 0x30
/* 0EC418 7F0B9A28 0FC2CEED */  jal   sub_GAME_7F0B4878
/* 0EC41C 7F0B9A2C 00000000 */   nop   
/* 0EC420 7F0B9A30 C7A80030 */  lwc1  $f8, 0x30($sp)
/* 0EC424 7F0B9A34 C7A40034 */  lwc1  $f4, 0x34($sp)
/* 0EC428 7F0B9A38 8FA50038 */  lw    $a1, 0x38($sp)
/* 0EC42C 7F0B9A3C 46004283 */  div.s $f10, $f8, $f0
/* 0EC430 7F0B9A40 3C01447A */  li    $at, 0x447A0000 # 1000.000000
/* 0EC434 7F0B9A44 3C048007 */  lui   $a0, %hi(g_DifferenceFromFarFogIntensity) # $a0, 0x8007
/* 0EC438 7F0B9A48 2484CF84 */  addiu $a0, %lo(g_DifferenceFromFarFogIntensity) # addiu $a0, $a0, -0x307c
/* 0EC43C 7F0B9A4C 3C068007 */  lui   $a2, %hi(g_FarFogIntensity) # $a2, 0x8007
/* 0EC440 7F0B9A50 24C6CF80 */  addiu $a2, %lo(g_FarFogIntensity) # addiu $a2, $a2, -0x3080
/* 0EC444 7F0B9A54 3C038007 */  lui   $v1, %hi(g_CurFogDetails) # $v1, 0x8007
/* 0EC448 7F0B9A58 2463CF68 */  addiu $v1, %lo(g_CurFogDetails) # addiu $v1, $v1, -0x3098
/* 0EC44C 7F0B9A5C 3C028004 */  lui   $v0, %hi(g_CurrentEnvironment) # $v0, 0x8004
/* 0EC450 7F0B9A60 2442E2BC */  addiu $v0, %lo(g_CurrentEnvironment) # addiu $v0, $v0, -0x1d44
/* 0EC454 7F0B9A64 46002183 */  div.s $f6, $f4, $f0
/* 0EC458 7F0B9A68 E7AA0030 */  swc1  $f10, 0x30($sp)
/* 0EC45C 7F0B9A6C 44812000 */  mtc1  $at, $f4
/* 0EC460 7F0B9A70 E7A60034 */  swc1  $f6, 0x34($sp)
/* 0EC464 7F0B9A74 84B8000C */  lh    $t8, 0xc($a1)
/* 0EC468 7F0B9A78 44984000 */  mtc1  $t8, $f8
/* 0EC46C 7F0B9A7C 00000000 */  nop   
/* 0EC470 7F0B9A80 468042A0 */  cvt.s.w $f10, $f8
/* 0EC474 7F0B9A84 46045183 */  div.s $f6, $f10, $f4
/* 0EC478 7F0B9A88 44812000 */  mtc1  $at, $f4
/* 0EC47C 7F0B9A8C 3C018004 */  lui   $at, %hi(g_ScaledFarFogIntensity) # $at, 0x8004
/* 0EC480 7F0B9A90 E4860000 */  swc1  $f6, ($a0)
/* 0EC484 7F0B9A94 84B9000E */  lh    $t9, 0xe($a1)
/* 0EC488 7F0B9A98 44994000 */  mtc1  $t9, $f8
/* 0EC48C 7F0B9A9C 00000000 */  nop   
/* 0EC490 7F0B9AA0 468042A0 */  cvt.s.w $f10, $f8
/* 0EC494 7F0B9AA4 C7A80034 */  lwc1  $f8, 0x34($sp)
/* 0EC498 7F0B9AA8 46045183 */  div.s $f6, $f10, $f4
/* 0EC49C 7F0B9AAC C7AA0030 */  lwc1  $f10, 0x30($sp)
/* 0EC4A0 7F0B9AB0 460A4381 */  sub.s $f14, $f8, $f10
/* 0EC4A4 7F0B9AB4 E4C60000 */  swc1  $f6, ($a2)
/* 0EC4A8 7F0B9AB8 C4D00000 */  lwc1  $f16, ($a2)
/* 0EC4AC 7F0B9ABC 46107102 */  mul.s $f4, $f14, $f16
/* 0EC4B0 7F0B9AC0 46045180 */  add.s $f6, $f10, $f4
/* 0EC4B4 7F0B9AC4 E426E2B4 */  swc1  $f6, %lo(g_ScaledFarFogIntensity)($at)
/* 0EC4B8 7F0B9AC8 C4820000 */  lwc1  $f2, ($a0)
/* 0EC4BC 7F0B9ACC 3C018004 */  lui   $at, %hi(g_ScaledDifferenceFromFarFogIntensity) # $at, 0x8004
/* 0EC4C0 7F0B9AD0 46027202 */  mul.s $f8, $f14, $f2
/* 0EC4C4 7F0B9AD4 46085100 */  add.s $f4, $f10, $f8
/* 0EC4C8 7F0B9AD8 E424E2B8 */  swc1  $f4, %lo(g_ScaledDifferenceFromFarFogIntensity)($at)
/* 0EC4CC 7F0B9ADC 84A80002 */  lh    $t0, 2($a1)
/* 0EC4D0 7F0B9AE0 3C014300 */  li    $at, 0x43000000 # 128.000000
/* 0EC4D4 7F0B9AE4 44883000 */  mtc1  $t0, $f6
/* 0EC4D8 7F0B9AE8 00000000 */  nop   
/* 0EC4DC 7F0B9AEC 468032A0 */  cvt.s.w $f10, $f6
/* 0EC4E0 7F0B9AF0 46005203 */  div.s $f8, $f10, $f0
/* 0EC4E4 7F0B9AF4 E4680000 */  swc1  $f8, ($v1)
/* 0EC4E8 7F0B9AF8 84A90004 */  lh    $t1, 4($a1)
/* 0EC4EC 7F0B9AFC 46028201 */  sub.s $f8, $f16, $f2
/* 0EC4F0 7F0B9B00 C4720000 */  lwc1  $f18, ($v1)
/* 0EC4F4 7F0B9B04 44892000 */  mtc1  $t1, $f4
/* 0EC4F8 7F0B9B08 E7A80018 */  swc1  $f8, 0x18($sp)
/* 0EC4FC 7F0B9B0C 468021A0 */  cvt.s.w $f6, $f4
/* 0EC500 7F0B9B10 44812000 */  mtc1  $at, $f4
/* 0EC504 7F0B9B14 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0EC508 7F0B9B18 44814000 */  mtc1  $at, $f8
/* 0EC50C 7F0B9B1C 3C014380 */  li    $at, 0x43800000 # 256.000000
/* 0EC510 7F0B9B20 46003283 */  div.s $f10, $f6, $f0
/* 0EC514 7F0B9B24 C7A60018 */  lwc1  $f6, 0x18($sp)
/* 0EC518 7F0B9B28 E46A0004 */  swc1  $f10, 4($v1)
/* 0EC51C 7F0B9B2C 46062283 */  div.s $f10, $f4, $f6
/* 0EC520 7F0B9B30 C46C0004 */  lwc1  $f12, 4($v1)
/* 0EC524 7F0B9B34 46024101 */  sub.s $f4, $f8, $f2
/* 0EC528 7F0B9B38 E7AA0020 */  swc1  $f10, 0x20($sp)
/* 0EC52C 7F0B9B3C 44815000 */  mtc1  $at, $f10
/* 0EC530 7F0B9B40 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EC534 7F0B9B44 460A2202 */  mul.s $f8, $f4, $f10
/* 0EC538 7F0B9B48 46126281 */  sub.s $f10, $f12, $f18
/* 0EC53C 7F0B9B4C E7AA0018 */  swc1  $f10, 0x18($sp)
/* 0EC540 7F0B9B50 44815000 */  mtc1  $at, $f10
/* 0EC544 7F0B9B54 46064103 */  div.s $f4, $f8, $f6
/* 0EC548 7F0B9B58 C7A80020 */  lwc1  $f8, 0x20($sp)
/* 0EC54C 7F0B9B5C 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0EC550 7F0B9B60 46004187 */  neg.s $f6, $f8
/* 0EC554 7F0B9B64 460A9200 */  add.s $f8, $f18, $f10
/* 0EC558 7F0B9B68 C7AA0018 */  lwc1  $f10, 0x18($sp)
/* 0EC55C 7F0B9B6C E7A4001C */  swc1  $f4, 0x1c($sp)
/* 0EC560 7F0B9B70 460C3102 */  mul.s $f4, $f6, $f12
/* 0EC564 7F0B9B74 00000000 */  nop   
/* 0EC568 7F0B9B78 46082182 */  mul.s $f6, $f4, $f8
/* 0EC56C 7F0B9B7C 44814000 */  mtc1  $at, $f8
/* 0EC570 7F0B9B80 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EC574 7F0B9B84 460A3103 */  div.s $f4, $f6, $f10
/* 0EC578 7F0B9B88 44815000 */  mtc1  $at, $f10
/* 0EC57C 7F0B9B8C 3C01437F */  li    $at, 0x437F0000 # 255.000000
/* 0EC580 7F0B9B90 46082183 */  div.s $f6, $f4, $f8
/* 0EC584 7F0B9B94 C7A80020 */  lwc1  $f8, 0x20($sp)
/* 0EC588 7F0B9B98 460A6100 */  add.s $f4, $f12, $f10
/* 0EC58C 7F0B9B9C C7AA0018 */  lwc1  $f10, 0x18($sp)
/* 0EC590 7F0B9BA0 E4660010 */  swc1  $f6, 0x10($v1)
/* 0EC594 7F0B9BA4 46082182 */  mul.s $f6, $f4, $f8
/* 0EC598 7F0B9BA8 C7A8001C */  lwc1  $f8, 0x1c($sp)
/* 0EC59C 7F0B9BAC 460A3103 */  div.s $f4, $f6, $f10
/* 0EC5A0 7F0B9BB0 44815000 */  mtc1  $at, $f10
/* 0EC5A4 7F0B9BB4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EC5A8 7F0B9BB8 46082180 */  add.s $f6, $f4, $f8
/* 0EC5AC 7F0B9BBC 460A3103 */  div.s $f4, $f6, $f10
/* 0EC5B0 7F0B9BC0 E4640014 */  swc1  $f4, 0x14($v1)
/* 0EC5B4 7F0B9BC4 84AA000C */  lh    $t2, 0xc($a1)
/* 0EC5B8 7F0B9BC8 AC4A0000 */  sw    $t2, ($v0)
/* 0EC5BC 7F0B9BCC 84AB000E */  lh    $t3, 0xe($a1)
/* 0EC5C0 7F0B9BD0 AC4B0004 */  sw    $t3, 4($v0)
/* 0EC5C4 7F0B9BD4 90AC0010 */  lbu   $t4, 0x10($a1)
/* 0EC5C8 7F0B9BD8 A04C0008 */  sb    $t4, 8($v0)
/* 0EC5CC 7F0B9BDC 90AD0011 */  lbu   $t5, 0x11($a1)
/* 0EC5D0 7F0B9BE0 A04D0009 */  sb    $t5, 9($v0)
/* 0EC5D4 7F0B9BE4 90AE0012 */  lbu   $t6, 0x12($a1)
/* 0EC5D8 7F0B9BE8 A04E000A */  sb    $t6, 0xa($v0)
/* 0EC5DC 7F0B9BEC 90AF0013 */  lbu   $t7, 0x13($a1)
/* 0EC5E0 7F0B9BF0 A04F000B */  sb    $t7, 0xb($v0)
/* 0EC5E4 7F0B9BF4 84B80014 */  lh    $t8, 0x14($a1)
/* 0EC5E8 7F0B9BF8 44984000 */  mtc1  $t8, $f8
/* 0EC5EC 7F0B9BFC 00000000 */  nop   
/* 0EC5F0 7F0B9C00 468041A0 */  cvt.s.w $f6, $f8
/* 0EC5F4 7F0B9C04 E446000C */  swc1  $f6, 0xc($v0)
/* 0EC5F8 7F0B9C08 90B90016 */  lbu   $t9, 0x16($a1)
/* 0EC5FC 7F0B9C0C A4590010 */  sh    $t9, 0x10($v0)
/* 0EC600 7F0B9C10 90A80017 */  lbu   $t0, 0x17($a1)
/* 0EC604 7F0B9C14 44885000 */  mtc1  $t0, $f10
/* 0EC608 7F0B9C18 05010004 */  bgez  $t0, .L7F0B9C2C
/* 0EC60C 7F0B9C1C 46805120 */   cvt.s.w $f4, $f10
/* 0EC610 7F0B9C20 44814000 */  mtc1  $at, $f8
/* 0EC614 7F0B9C24 00000000 */  nop   
/* 0EC618 7F0B9C28 46082100 */  add.s $f4, $f4, $f8
.L7F0B9C2C:
/* 0EC61C 7F0B9C2C E4440014 */  swc1  $f4, 0x14($v0)
/* 0EC620 7F0B9C30 90A90018 */  lbu   $t1, 0x18($a1)
/* 0EC624 7F0B9C34 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EC628 7F0B9C38 44893000 */  mtc1  $t1, $f6
/* 0EC62C 7F0B9C3C 05210004 */  bgez  $t1, .L7F0B9C50
/* 0EC630 7F0B9C40 468032A0 */   cvt.s.w $f10, $f6
/* 0EC634 7F0B9C44 44814000 */  mtc1  $at, $f8
/* 0EC638 7F0B9C48 00000000 */  nop   
/* 0EC63C 7F0B9C4C 46085280 */  add.s $f10, $f10, $f8
.L7F0B9C50:
/* 0EC640 7F0B9C50 E44A0018 */  swc1  $f10, 0x18($v0)
/* 0EC644 7F0B9C54 90AA0019 */  lbu   $t2, 0x19($a1)
/* 0EC648 7F0B9C58 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EC64C 7F0B9C5C 448A2000 */  mtc1  $t2, $f4
/* 0EC650 7F0B9C60 05410004 */  bgez  $t2, .L7F0B9C74
/* 0EC654 7F0B9C64 468021A0 */   cvt.s.w $f6, $f4
/* 0EC658 7F0B9C68 44814000 */  mtc1  $at, $f8
/* 0EC65C 7F0B9C6C 00000000 */  nop   
/* 0EC660 7F0B9C70 46083180 */  add.s $f6, $f6, $f8
.L7F0B9C74:
/* 0EC664 7F0B9C74 E446001C */  swc1  $f6, 0x1c($v0)
/* 0EC668 7F0B9C78 90AB001A */  lbu   $t3, 0x1a($a1)
/* 0EC66C 7F0B9C7C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EC670 7F0B9C80 240A0001 */  li    $t2, 1
/* 0EC674 7F0B9C84 A04B0020 */  sb    $t3, 0x20($v0)
/* 0EC678 7F0B9C88 84AC001C */  lh    $t4, 0x1c($a1)
/* 0EC67C 7F0B9C8C 448C5000 */  mtc1  $t4, $f10
/* 0EC680 7F0B9C90 00000000 */  nop   
/* 0EC684 7F0B9C94 46805120 */  cvt.s.w $f4, $f10
/* 0EC688 7F0B9C98 E4440024 */  swc1  $f4, 0x24($v0)
/* 0EC68C 7F0B9C9C 90AD001E */  lbu   $t5, 0x1e($a1)
/* 0EC690 7F0B9CA0 A44D0028 */  sh    $t5, 0x28($v0)
/* 0EC694 7F0B9CA4 90AE001F */  lbu   $t6, 0x1f($a1)
/* 0EC698 7F0B9CA8 448E4000 */  mtc1  $t6, $f8
/* 0EC69C 7F0B9CAC 05C10004 */  bgez  $t6, .L7F0B9CC0
/* 0EC6A0 7F0B9CB0 468041A0 */   cvt.s.w $f6, $f8
/* 0EC6A4 7F0B9CB4 44815000 */  mtc1  $at, $f10
/* 0EC6A8 7F0B9CB8 00000000 */  nop   
/* 0EC6AC 7F0B9CBC 460A3180 */  add.s $f6, $f6, $f10
.L7F0B9CC0:
/* 0EC6B0 7F0B9CC0 E446002C */  swc1  $f6, 0x2c($v0)
/* 0EC6B4 7F0B9CC4 90AF0020 */  lbu   $t7, 0x20($a1)
/* 0EC6B8 7F0B9CC8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EC6BC 7F0B9CCC 448F2000 */  mtc1  $t7, $f4
/* 0EC6C0 7F0B9CD0 05E10004 */  bgez  $t7, .L7F0B9CE4
/* 0EC6C4 7F0B9CD4 46802220 */   cvt.s.w $f8, $f4
/* 0EC6C8 7F0B9CD8 44815000 */  mtc1  $at, $f10
/* 0EC6CC 7F0B9CDC 00000000 */  nop   
/* 0EC6D0 7F0B9CE0 460A4200 */  add.s $f8, $f8, $f10
.L7F0B9CE4:
/* 0EC6D4 7F0B9CE4 E4480030 */  swc1  $f8, 0x30($v0)
/* 0EC6D8 7F0B9CE8 90B80021 */  lbu   $t8, 0x21($a1)
/* 0EC6DC 7F0B9CEC 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EC6E0 7F0B9CF0 44983000 */  mtc1  $t8, $f6
/* 0EC6E4 7F0B9CF4 07010004 */  bgez  $t8, .L7F0B9D08
/* 0EC6E8 7F0B9CF8 46803120 */   cvt.s.w $f4, $f6
/* 0EC6EC 7F0B9CFC 44815000 */  mtc1  $at, $f10
/* 0EC6F0 7F0B9D00 00000000 */  nop   
/* 0EC6F4 7F0B9D04 460A2100 */  add.s $f4, $f4, $f10
.L7F0B9D08:
/* 0EC6F8 7F0B9D08 E4440034 */  swc1  $f4, 0x34($v0)
/* 0EC6FC 7F0B9D0C 90B90022 */  lbu   $t9, 0x22($a1)
/* 0EC700 7F0B9D10 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0EC704 7F0B9D14 44994000 */  mtc1  $t9, $f8
/* 0EC708 7F0B9D18 07210004 */  bgez  $t9, .L7F0B9D2C
/* 0EC70C 7F0B9D1C 468041A0 */   cvt.s.w $f6, $f8
/* 0EC710 7F0B9D20 44815000 */  mtc1  $at, $f10
/* 0EC714 7F0B9D24 00000000 */  nop   
/* 0EC718 7F0B9D28 460A3180 */  add.s $f6, $f6, $f10
.L7F0B9D2C:
/* 0EC71C 7F0B9D2C E4460038 */  swc1  $f6, 0x38($v0)
/* 0EC720 7F0B9D30 84A30006 */  lh    $v1, 6($a1)
/* 0EC724 7F0B9D34 3C018007 */  lui   $at, %hi(g_NearFogValuesP) # $at, 0x8007
/* 0EC728 7F0B9D38 54600004 */  bnezl $v1, .L7F0B9D4C
/* 0EC72C 7F0B9D3C 44832000 */   mtc1  $v1, $f4
/* 0EC730 7F0B9D40 10000012 */  b     .L7F0B9D8C
/* 0EC734 7F0B9D44 AC20CF64 */   sw    $zero, %lo(g_NearFogValuesP)($at)
/* 0EC738 7F0B9D48 44832000 */  mtc1  $v1, $f4
.L7F0B9D4C:
/* 0EC73C 7F0B9D4C 3C028007 */  lui   $v0, %hi(D_80044DC0) # $v0, 0x8007
/* 0EC740 7F0B9D50 2442CF98 */  addiu $v0, %lo(D_80044DC0) # addiu $v0, $v0, -0x3068
/* 0EC744 7F0B9D54 46802220 */  cvt.s.w $f8, $f4
/* 0EC748 7F0B9D58 3C018007 */  lui   $at, %hi(g_NearFogValuesP) # $at, 0x8007
/* 0EC74C 7F0B9D5C E4480000 */  swc1  $f8, ($v0)
/* 0EC750 7F0B9D60 84A80008 */  lh    $t0, 8($a1)
/* 0EC754 7F0B9D64 44885000 */  mtc1  $t0, $f10
/* 0EC758 7F0B9D68 00000000 */  nop   
/* 0EC75C 7F0B9D6C 468051A0 */  cvt.s.w $f6, $f10
/* 0EC760 7F0B9D70 E4460004 */  swc1  $f6, 4($v0)
/* 0EC764 7F0B9D74 84A9000A */  lh    $t1, 0xa($a1)
/* 0EC768 7F0B9D78 44892000 */  mtc1  $t1, $f4
/* 0EC76C 7F0B9D7C 00000000 */  nop   
/* 0EC770 7F0B9D80 46802220 */  cvt.s.w $f8, $f4
/* 0EC774 7F0B9D84 E4480008 */  swc1  $f8, 8($v0)
/* 0EC778 7F0B9D88 AC22CF64 */  sw    $v0, %lo(g_NearFogValuesP)($at)
.L7F0B9D8C:
/* 0EC77C 7F0B9D8C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EC780 7F0B9D90 3C018007 */  lui   $at, %hi(g_FogSkyIsEnabled) # $at, 0x8007
/* 0EC784 7F0B9D94 AC2ACF60 */  sw    $t2, %lo(g_FogSkyIsEnabled)($at)
/* 0EC788 7F0B9D98 03E00008 */  jr    $ra
/* 0EC78C 7F0B9D9C 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif


/**
 * Address 0x7F0BA9D0.
*/
void fogLoadFoglessCurrentEnvironment(struct EnvironmentData_Fogless *arg0)
{
    g_CurrentEnvironment.Sky.Red = arg0->Sky.Red;
    g_CurrentEnvironment.Sky.Green = arg0->Sky.Green;
    g_CurrentEnvironment.Sky.Blue = arg0->Sky.Blue;
    g_CurrentEnvironment.Sky.Clouds = arg0->Sky.Clouds;
    g_CurrentEnvironment.Sky.CloudRepeat = arg0->Sky.CloudRepeat;
    g_CurrentEnvironment.Sky.SkyImageId = arg0->Sky.SkyImageId;
    g_CurrentEnvironment.Sky.CloudRed = arg0->Sky.CloudRed;
    g_CurrentEnvironment.Sky.CloudGreen = arg0->Sky.CloudGreen;
    g_CurrentEnvironment.Sky.CloudBlue = arg0->Sky.CloudBlue;
    g_CurrentEnvironment.Sky.IsWater = arg0->Sky.IsWater;
    g_CurrentEnvironment.Sky.WaterRepeat = arg0->Sky.WaterRepeat;
    g_CurrentEnvironment.Sky.WaterImageId = arg0->Sky.WaterImageId;
    g_CurrentEnvironment.Sky.WaterRed = arg0->Sky.WaterRed;
    g_CurrentEnvironment.Sky.WaterGreen = arg0->Sky.WaterGreen;
    g_CurrentEnvironment.Sky.WaterBlue = arg0->Sky.WaterBlue;
    g_CurrentEnvironment.Sky.WaterConcavity = arg0->Sky.WaterConcavity;
}


/**
 * Address 0x7F0BAA5C.
*/
void fogRemoved7F0BAA5C(s32 a)
{
    return;
}


/**
 * Address 0x7F0BAA64.
*/
void fogLoadLevelEnvironment(s32 level_id, s32 arg1)
{
    struct EnvironmentData *phi_v1;
    struct EnvironmentData_Fogless *phi_v2;
    struct EnvironmentData_Fogless *sp1C;
    s32 num_players;

    sp1C = NULL;

    num_players = getPlayerCount();
    
    if (num_players == 1)
    {
        num_players = 0;
    }

    g_ScaledFarFogIntensity = 3.4028235e38f;
    g_ScaledDifferenceFromFarFogIntensity = 0.0f;

    if (arg1)
    {
        for (phi_v1 = &fog_tables[0]; phi_v1->Id != 0; phi_v1++)
        {
            if (phi_v1->Id == (level_id + 900))
            {
                g_EnvironmentFoundp = phi_v1;
                g_EnvironmentMainp = phi_v1;
                g_EnvironmentAltp = phi_v1 + 1;

                fogLoadCurrentEnvironment(g_EnvironmentFoundp);

                return;
            }
        }
    }
    
    for (phi_v1 = &fog_tables[0]; phi_v1->Id != 0; phi_v1++)
    {
        if (phi_v1->Id == (level_id + (num_players * 100)))
        {
            g_EnvironmentFoundp = phi_v1;
            g_EnvironmentMainp = phi_v1;
            g_EnvironmentAltp = phi_v1 + 1;

            fogLoadCurrentEnvironment(g_EnvironmentFoundp);

            return;
        }
    }

    if(1)
    {
        // removed
    }

    if (num_players >= 2)
    {
        for (phi_v1 = &fog_tables[0]; phi_v1->Id != 0; phi_v1++)
        {
            if (phi_v1->Id == (num_players * 100))
            {
                g_EnvironmentFoundp = phi_v1;
                g_EnvironmentMainp = phi_v1;
                g_EnvironmentAltp = phi_v1 + 1;

                fogLoadCurrentEnvironment(g_EnvironmentFoundp);

                return;
            }
        }
    }

    viSetZRange(15.0f, 10000.0f);
    g_FogSkyIsEnabled = 0;

    for (phi_v2 = fog_tables2; phi_v2->Id != 0; phi_v2++)
    {
        if (phi_v2->Id == level_id)
        {
            sp1C = phi_v2;

            if(1)
            {
                // removed.
                // break or return maybe?
            }
        }
    }

    if (sp1C == NULL)
    {
        sp1C = &fog_tables2[0];
    }

    fogLoadFoglessCurrentEnvironment(sp1C);
    g_EnvironmentFoundp = NULL;
}


/**
 * Address 0x7F0BACA8.
*/
void fogSwitchToSolosky2(f32 arg0)
{
    static struct EnvironmentData dword_CODE_bss_800825F8;

    dword_CODE_bss_800825F8 = *g_EnvironmentMainp;

    dword_CODE_bss_800825F8.Visibility.BlendMultiplier = 
        g_EnvironmentMainp->Visibility.BlendMultiplier
        + (arg0 * (g_EnvironmentAltp->Visibility.BlendMultiplier - g_EnvironmentMainp->Visibility.BlendMultiplier));

    dword_CODE_bss_800825F8.Visibility.FarFog = 
        g_EnvironmentMainp->Visibility.FarFog
        + (arg0 * (g_EnvironmentAltp->Visibility.FarFog - g_EnvironmentMainp->Visibility.FarFog));

    dword_CODE_bss_800825F8.Fog.DifferenceFromFarIntensity = 
        (f32)g_EnvironmentMainp->Fog.DifferenceFromFarIntensity
        + (arg0 * ((f32)g_EnvironmentAltp->Fog.DifferenceFromFarIntensity - (f32)g_EnvironmentMainp->Fog.DifferenceFromFarIntensity));

    dword_CODE_bss_800825F8.Fog.FarIntensity = 
        (f32)g_EnvironmentMainp->Fog.FarIntensity
        + (arg0 * ((f32)g_EnvironmentAltp->Fog.FarIntensity - (f32)g_EnvironmentMainp->Fog.FarIntensity));
    
    dword_CODE_bss_800825F8.Sky.Red = 
        (f32)g_EnvironmentMainp->Sky.Red
        + (arg0 * ((f32)g_EnvironmentAltp->Sky.Red - (f32)g_EnvironmentMainp->Sky.Red));

    dword_CODE_bss_800825F8.Sky.Green = 
        (f32)g_EnvironmentMainp->Sky.Green
        + (arg0 * ((f32)g_EnvironmentAltp->Sky.Green - (f32)g_EnvironmentMainp->Sky.Green));

    dword_CODE_bss_800825F8.Sky.Blue = 
        (f32)g_EnvironmentMainp->Sky.Blue
        + (arg0 * ((f32)g_EnvironmentAltp->Sky.Blue - (f32)g_EnvironmentMainp->Sky.Blue));

    dword_CODE_bss_800825F8.Sky.Red &= 0xf8;
    dword_CODE_bss_800825F8.Sky.Green &= 0xf8;
    dword_CODE_bss_800825F8.Sky.Blue &= 0xf8;

    fogLoadCurrentEnvironment(&dword_CODE_bss_800825F8);
}


/**
 * @param gdl:
 * @param arg1: not used?
 * 
 * Address 0x7F0BB070.
*/
Gfx *fogSetRenderFogColor(Gfx *gdl, s32 arg1)
{
    if (g_FogSkyIsEnabled == 0)
    {
        return gdl;
    }

    // note: both branches are exactly the same.
    // maybe one has debug code?
    if (arg1)
    {
        gDPSetFogColor(gdl++, g_CurrentEnvironment.Sky.Red, g_CurrentEnvironment.Sky.Green, g_CurrentEnvironment.Sky.Blue, 0xff);
        gSPFogPosition(gdl++, g_CurrentEnvironment.Fog.DifferenceFromFarIntensity, g_CurrentEnvironment.Fog.FarIntensity);
    }
    else
    {
        gDPSetFogColor(gdl++, g_CurrentEnvironment.Sky.Red, g_CurrentEnvironment.Sky.Green, g_CurrentEnvironment.Sky.Blue, 0xff);
        gSPFogPosition(gdl++, g_CurrentEnvironment.Fog.DifferenceFromFarIntensity, g_CurrentEnvironment.Fog.FarIntensity);
    }

    gSPSetGeometryMode(gdl++, G_FOG);
    gDPSetAlphaDither(gdl++, G_AD_NOISE);

    return gdl;
}


/**
 * Address 0x7F0BB298.
*/
Gfx *fogRenderClearFogMode(Gfx *gdl)
{
    if (g_FogSkyIsEnabled == 0)
    {
        return gdl;
    }

    gSPClearGeometryMode(gdl++, G_FOG);

    return gdl;
}


/**
 * Address 0x7F0BB2C8.
*/
s32 fogPositionIsVisibleThroughFog(struct coord3d *pos, f32 range)
{
    struct coord3d sp24;
    f32 ff;
    struct coord3d *player_pos;
    Mtxf *player_mtx;

    if (g_FogSkyIsEnabled == 0)
    {
        return 1;
    }

    player_pos = bondviewGetCurrentPlayersPosition();
    player_mtx = currentPlayerGetMatrix10CC();

    sp24.f[0] = pos->f[0] - player_pos->f[0];
    sp24.f[1] = pos->f[1] - player_pos->f[1];
    sp24.f[2] = pos->f[2] - player_pos->f[2];

    ff = (((sp24.f[0] * player_mtx->m[0][0]) + (sp24.f[1] * player_mtx->m[0][1]) + (sp24.f[2] * player_mtx->m[0][2])));

    if (ff > (g_ScaledFarFogIntensity + range))
    {
        return 0;
    }

    return 1;
}


struct NearFogData *fogGetNearFogValuesP(void)
{
    return g_NearFogValuesP;
}


/**
 * Address 0x7F0BB3A4.
*/
s32 fogGetPropDistColor(PropRecord *prop, struct rgba_f32 *color)
{
    if (g_FogSkyIsEnabled == 0)
    {
        return 2;
    }

    if (prop->Unk18 < 0.0f)
    {
        return 2;
    }

    color->rgba[0] = (f32) g_CurrentEnvironment.Sky.Red / 255.0f;
    color->rgba[1] = (f32) g_CurrentEnvironment.Sky.Green / 255.0f;
    color->rgba[2] = (f32) g_CurrentEnvironment.Sky.Blue / 255.0f;
    color->rgba[3] = (g_CurFogDetails.far_fog_dist_scaled / prop->Unk18) + g_CurFogDetails.near_fog_dist_scaled;

    if (color->rgba[3] < 0.0f)
    {
        return 2;
    }

    if (color->rgba[3] > 1.0f)
    {
        return 0;
    }

    return 1;
}
