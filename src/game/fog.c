#include <ultra64.h>

#include <bondtypes.h>
#include <bondconstants.h>
#include <fr.h>
#include "bg.h"
#include "bondview.h"
#include "fog.h"
#include <limits.h>

/**
 * Address 0x800825C0.
*/
s32 g_FogSkyIsEnabled;

/**
 * Address 0x800825C4.
*/
NearFogRecord *g_NearFogValuesP;

/**
 * Address 0x800825C8. Private struct to this file only
*/
struct FogDetails
{
    f32 g_CurFogDetails;
    f32 scaled_far_fog_dist;
    u32 unk08;
    u32 unk0c;
    f32 far_fog_dist_scaled;
    f32 near_fog_dist_scaled;
} g_CurFogDetails;

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
EnvironmentRecord *g_EnvironmentFoundp;

/**
 * Address 0x800825EC.
*/
EnvironmentRecord * g_EnvironmentMainp;

/**
 * Address 0x800825F0.
*/
EnvironmentRecord * g_EnvironmentAltp;

/**
 * Unreferenced.
 * 
 * Address 0x800825F4.
*/
s32 D_800825F4;

#if defined(VERSION_EU)
struct NearFogRecordF dword_CODE_bss_800825F8;
s32 bss_800825F8_padding[7];
#endif

/**
 * Unreferenced.
 * 
 * Address 0x80044DC0.
*/
s32 D_80044DC0 = 0;


/**
 * Address 0x80044DC4.
*/
f32 g_ScaledFarFogIntensity = FLT_MAX;

/**
 * Address 0x80044DC8.
*/
f32 g_ScaledDifferenceFromFarFogIntensity = 0.0;

/**
 * Address 0x80044DCC.
*/
CurrentEnvironmentRecord g_CurrentEnvironment = { 
    0x384, // s32 DifferenceFromFarIntensity;
    0x3e8, // u32 FarIntensity;
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
};

s32 D_80044E08 = 0;
s32 D_80044E0C = 0;

#if defined(VERSION_EU)
EnvironmentRecord fog_tables[] = {
     //stageID                              blendmultiplier    farfog    nearfog  mvisrng  mobfnrng  dif_ght  far_alight    red     green     blue    clouds   cloudrept  skymid, cloudred   green    blue   iswater  waterrepeat  waterid  water red,green,blue  waterconcavity
    {LEVELID_STATUE                             ,        15,      3500,    2000,     2500,    2000,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,       0,      170,    100,     40,        0,       -1000,       0,       0,     0,    0,    30.0 },
    {LEVELID_CONTROL                            ,        10,     10000,    2500,     5000,     800,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,       0,        0,      0,      0,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_ARCHIVES                           ,        10,      3000,    2000,     3000,     500,    0x3E4,    0x3E8,       0,       0,       0,        1,      5000,       0,      255,    255,    255,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_TRAIN                              ,        10,      1500,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,       0,      255,    255,    255,        0,           0,       1,       0,   255,  255,    25.0 },
    {LEVELID_TRAIN + ENVIRONMENTDATA_ALT        ,        20,     15000,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       8,        1,      5000,       0,      255,    255,    255,        0,           0,       1,       0,   255,  255,    25.0 },
    {LEVELID_STREETS                            ,        10,      7500,    5000,     6000,    1000,    0x3E4,    0x3E8,    0x10,    0x18,    0x20,        1,      5000,       0,      225,    175,    100,        0,       -1000,       0,       0,     0,    0,    25.0 },
    {LEVELID_DEPOT                              ,        10,      3000,    1600,     2000,     800,    0x3E4,    0x3E8,       0,       0,       8,        1,      7500,       0,       70,    199,    186,        0,       -1000,       1,       0,   255,  255,    25.0 },
    {LEVELID_COMPLEX                            ,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,       0,      220,      0,     20,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_DAM                                ,         5,     15000,    3333,     4444,     600,    0x3E3,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,       0,      255,    255,    255,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_DAM + ENVIRONMENTDATA_CINEMA       ,        30,     15000,    3333,     4444,     600,    0x3E3,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,       0,      255,    255,    255,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_FACILITY                           ,        10,      5000,       0,        0,       0,    0x3DE,    0x3E8,    0x10,    0x20,    0x10,        0,      5000,       0,      255,    255,    255,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_FACILITY + ENVIRONMENTDATA_ALT     ,        10,      1000,       0,        0,       0,    0x3DE,    0x3E8,    0x40,    0x80,    0x40,        0,      5000,       0,      255,    255,    255,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_RUNWAY                             ,        10,     15000,    6000,     8000,     800,    0x3E4,    0x3E8,    0x10,    0x30,    0x40,        1,      5000,       0,       25,     25,     25,        0,       -1000,       0,       0,     0,    0,     0.0 },
    {LEVELID_SURFACE                            ,         2,      2500,    4444,     5555,     800,    0x3E4,    0x3E8,    0x60,    0x60,    0x80,        1,     10000,       0,      240,    120,    30,         0,           0,       1,       0,   255,  255,     7.0 },
    {LEVELID_JUNGLE                             ,        10,      2500,    1500,     2500,    1000,    0x3E4,    0x3E8,    0x18,    0x20,       0,        0,      5000,       0,      255,    255,    255,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_TEMPLE                             ,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x18,    0x28,        1,     10000,       0,      160,    160,    190,        0,        -500,       0,       0,     0,    0,     0.0 },
    {LEVELID_CAVERNS                            ,        10,      6000,       0,        0,       0,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,       0,      255,    255,    255,        0,       -3000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CRADLE                             ,        10,      9500,    3333,     4444,     800,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,       0,      255,    255,      0,        0,      -10000,       1,       0,   255,  255,     0.0 },
    {LEVELID_SURFACE2                           ,         2,      2000,    2500,     3055,     750,    0x3BD,    0x3E8,    0x20,    0x10,    0x10,        1,      5000,       0,       58,     17,      0,        0,       -1000,       1,       0,   255,  255,    20.0 },
    {LEVELID_SURFACE2 + ENVIRONMENTDATA_CINEMA  ,         2,      8000,    6000,     8000,     800,    0x3DF,    0x3E8,    0x20,    0x10,    0x10,        1,      5000,       0,       58,     17,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_BUNKER2                            ,        10,     10000,    1000,    15000,     750,    0x3E4,    0x41A,    0x10,       0,       0,        1,      5000,       0,       58,     17,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_2,        10,      2500,       0,        0,       0,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,       0,      130,    120,    110,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_3,        10,      2000,       0,        0,       0,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,       0,      130,    120,    110,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_BUNKER1 + ENVIRONMENTDATA_PLAYERS_4,        10,      1500,       0,        0,       0,    0x3E4,    0x3E8,    0x80,    0x78,    0x70,        0,         0,       0,      130,    120,    110,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_2 ,        10,      7000,    3333,     4444,     800,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,       0,      255,    255,      0,        0,      -10000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_3 ,        10,      5500,    3333,     4444,     800,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,       0,      255,    255,      0,        0,      -10000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CRADLE + ENVIRONMENTDATA_PLAYERS_4 ,        10,      4000,    3333,     4444,     800,    0x3E4,    0x3E8,    0x60,    0x80,    0xA0,        1,      5000,       0,      255,    255,      0,        0,      -10000,       1,       0,   255,  255,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_2 ,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,       0,      120,    120,    120,        0,        -500,       0,       0,     0,    0,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_3 ,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,       0,      120,    120,    120,        0,        -500,       0,       0,     0,    0,     0.0 },
    {LEVELID_TEMPLE + ENVIRONMENTDATA_PLAYERS_4 ,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x18,    0x18,        1,     10000,       0,      120,    120,    120,        0,        -500,       0,       0,     0,    0,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_2,        10,      7500,       0,        0,       0,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,       0,      255,    255,    255,        0,       -3000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_3,        10,      6000,       0,        0,       0,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,       0,      255,    255,    255,        0,       -3000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CAVERNS + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,    0x3E1,    0x3E8,       8,       0,       8,        0,      5000,       0,      255,    255,    255,        0,       -3000,       1,       0,   255,  255,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_2,        10,      7500,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,       0,        0,      0,      0,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_3,        10,      6000,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,       0,        0,      0,      0,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_DEFAULT + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,       0,       0,       0,        0,         0,       0,        0,      0,      0,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_CITADEL                            ,        10,     20000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,       0,      255,    108,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_2,        10,     20000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,       0,      255,    108,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_3,        10,     20000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,       0,      255,    108,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_CITADEL + ENVIRONMENTDATA_PLAYERS_4,        10,     20000,       0,        0,       0,    0x3E4,    0x3E8,    0x18,    0x50,    0x38,        1,      5000,       0,      255,    108,      0,        0,       -1000,       1,       0,   255,  255,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_2,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,       0,      220,      0,     20,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_3,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,       0,      220,      0,     20,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_COMPLEX + ENVIRONMENTDATA_PLAYERS_4,        10,      5000,       0,        0,       0,    0x3E4,    0x3E8,    0x28,       0,       0,        1,     10000,       0,      220,      0,     20,        0,           0,       0,       0,     0,    0,     0.0 },
    {LEVELID_AZTEC                              ,        10,     15000,    3000,     4000,     600,    0x3E4,    0x3E8,       0,       0,       0,        1,      7500,       0,       83,     72,     65,        0,       -5000,       0,       0,     0,    0,     0.0 },
    {LEVELID_AZTEC + ENVIRONMENTDATA_ALT        ,        30,     15000,    3000,     4000,     600,    0x3E4,    0x3E8,       0,       0,       0,        1,      7500,       0,       83,     72,     65,        0,       -5000,       0,       0,     0,    0,     0.0 },
    {LEVELID_EGYPT                              ,        10,     20000,    3000,     4000,     600,    0x3E4,    0x3E8,    0x10,    0x30,    0x60,        1,      5000,       0,      255,    255,    255,        0,       -5000,       0,       0,     0,    0,     0.0 },
    {LEVELID_EGYPT + ENVIRONMENTDATA_ALT        ,        10,     10000,    3000,     4000,     600,    0x3CC,    0x3E8,       0,       0,       0,        1,      7500,       0,       83,     10,     10,        0,       -5000,       0,       0,     0,    0,     0.0 },
    {ENVIRONMENTDATA_END},
};
#else
/**
 * Address 0x80044E10.
*/
EnvironmentRecord fog_tables[] = {
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
#endif


EnvironmentFoglessRecord fog_tables2[] = {
    {LEVELID_NONE   ,    0,       0x10,    0x40,    0,        5000.0,        0,        0,        255.0,        255.0,        255.0,        0,        0,        0,        0,           0.0,        0,        0,          0.0,          0.0,          0.0,        0.0},
    {LEVELID_FRIGATE,    0x10,    0x30,    0x60,    1,        3000.0,        0,        0,        230.0,        230.0,        230.0,        1,        0,        0,        0,        -150.0,        2,        0,        255.0,        255.0,        150.0,        0.0},
    {LEVELID_CUBA   ,    0x30,    0x40,    0x10,    0,        5000.0,        0,        0,        255.0,        255.0,        255.0,        0,        0,        0,        0,           0.0,        0,        0,          0.0,          0.0,          0.0,        0.0},
    {ENVIRONMENTDATA_END}
};

// forward declarations

void fogLoadCurrentEnvironment(EnvironmentRecord *arg0);
void fogLoadFoglessCurrentEnvironment(EnvironmentFoglessRecord *arg0);

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

/**
* @return Pointer to Current Environment
*/
CurrentEnvironmentRecord *fogGetCurrentEnvironmentp(void)
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


/**
 * Address 0x7F0BA758.
*/
void fogLoadCurrentEnvironment(EnvironmentRecord *arg0)
{
    f32 zrange[2]; // 48
    f32 pk0;
    f32 pk4;
    f32 temp_f0;
    f32 sp20; // 32
    f32 sp1C; // 28

    viSetZRange(arg0->Visibility.BlendMultiplier, arg0->Visibility.FarFog);
    viGetZRange(&zrange);

    temp_f0 = bgGetLevelVisibilityScale();
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

    g_CurrentEnvironment.DifferenceFromFarIntensity = (s32) arg0->Fog.DifferenceFromFarIntensity;
    g_CurrentEnvironment.FarIntensity = arg0->Fog.FarIntensity;
    g_CurrentEnvironment.Red = arg0->Sky.Red;
    g_CurrentEnvironment.Green = arg0->Sky.Green;
    g_CurrentEnvironment.Blue = arg0->Sky.Blue;
    g_CurrentEnvironment.Clouds = arg0->Sky.Clouds;
    g_CurrentEnvironment.CloudRepeat = arg0->Sky.CloudRepeat;
    g_CurrentEnvironment.SkyImageId = (s16) arg0->Sky.SkyImageId;
    g_CurrentEnvironment.CloudRed = arg0->Sky.CloudRed;
    g_CurrentEnvironment.CloudGreen = arg0->Sky.CloudGreen;
    g_CurrentEnvironment.CloudBlue = arg0->Sky.CloudBlue;
    g_CurrentEnvironment.IsWater = arg0->Sky.IsWater;
    g_CurrentEnvironment.WaterRepeat = arg0->Sky.WaterRepeat;
    g_CurrentEnvironment.WaterImageId = (s16) arg0->Sky.WaterImageId;
    g_CurrentEnvironment.WaterRed = arg0->Sky.WaterRed;
    g_CurrentEnvironment.WaterGreen = arg0->Sky.WaterGreen;
    g_CurrentEnvironment.WaterBlue = arg0->Sky.WaterBlue;
    g_CurrentEnvironment.WaterConcavity = arg0->Sky.WaterConcavity;

#if defined(VERSION_EU)
    #define FOG_ZERO 0
#else
    #define FOG_ZERO 0.0f
#endif
    
    if (arg0->Visibility.Nfd.NearFog == FOG_ZERO)
    {
        g_NearFogValuesP = NULL;
    }
    else
    {
#if defined(VERSION_EU)
        dword_CODE_bss_800825F8.NearFog = arg0->Visibility.Nfd.NearFog;
        dword_CODE_bss_800825F8.MaxVisRange = arg0->Visibility.Nfd.MaxVisRange;
        dword_CODE_bss_800825F8.MaxObfuscationRange = arg0->Visibility.Nfd.MaxObfuscationRange;
        g_NearFogValuesP = &dword_CODE_bss_800825F8;
#else
        g_NearFogValuesP = &arg0->Visibility.Nfd;
#endif
    }

#undef FOG_ZERO

    g_FogSkyIsEnabled = 1;
}

/**
 * Address 0x7F0BA9D0.
*/
void fogLoadFoglessCurrentEnvironment(EnvironmentFoglessRecord *arg0)
{
    g_CurrentEnvironment.Red = arg0->Red;
    g_CurrentEnvironment.Green = arg0->Green;
    g_CurrentEnvironment.Blue = arg0->Blue;
    g_CurrentEnvironment.Clouds = arg0->Clouds;
    g_CurrentEnvironment.CloudRepeat = arg0->CloudRepeat;
    g_CurrentEnvironment.SkyImageId = arg0->SkyImageId;
    g_CurrentEnvironment.CloudRed = arg0->CloudRed;
    g_CurrentEnvironment.CloudGreen = arg0->CloudGreen;
    g_CurrentEnvironment.CloudBlue = arg0->CloudBlue;
    g_CurrentEnvironment.IsWater = arg0->IsWater;
    g_CurrentEnvironment.WaterRepeat = arg0->WaterRepeat;
    g_CurrentEnvironment.WaterImageId = arg0->WaterImageId;
    g_CurrentEnvironment.WaterRed = arg0->WaterRed;
    g_CurrentEnvironment.WaterGreen = arg0->WaterGreen;
    g_CurrentEnvironment.WaterBlue = arg0->WaterBlue;
    g_CurrentEnvironment.WaterConcavity = arg0->WaterConcavity;
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
    EnvironmentRecord *phi_v1;
    EnvironmentFoglessRecord *phi_v2;
    EnvironmentFoglessRecord *sp1C;
    s32 num_players;

    sp1C = NULL;

    num_players = getPlayerCount();
    
    if (num_players == 1)
    {
        num_players = 0;
    }

    g_ScaledFarFogIntensity = FLT_MAX;
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

#if defined(VERSION_US) || defined(VERSION_JP)
/**
 * Address 0x7F0BACA8.
 * Switch to next Environment. 
 * @param isTransition: Usually 0 for instant switch or 1 to transition gradually
 */
void fogSwitchToSolosky2(f32 arg0)
{
#if defined(VERSION_US) || defined(VERSION_JP)
    static EnvironmentRecord dword_CODE_bss_800825F8;
#endif

    dword_CODE_bss_800825F8 = *g_EnvironmentMainp;

    dword_CODE_bss_800825F8.Visibility.BlendMultiplier = 
        g_EnvironmentMainp->Visibility.BlendMultiplier
#if defined(VERSION_EU)
        + (arg0 * ((f32)g_EnvironmentAltp->Visibility.BlendMultiplier - (f32)g_EnvironmentMainp->Visibility.BlendMultiplier));
#else
        + (arg0 * (g_EnvironmentAltp->Visibility.BlendMultiplier - g_EnvironmentMainp->Visibility.BlendMultiplier));
#endif

    dword_CODE_bss_800825F8.Visibility.FarFog = 
        g_EnvironmentMainp->Visibility.FarFog
#if defined(VERSION_EU)
        + (arg0 * ((f32)g_EnvironmentAltp->Visibility.FarFog - (f32)g_EnvironmentMainp->Visibility.FarFog));
#else
        + (arg0 * (g_EnvironmentAltp->Visibility.FarFog - g_EnvironmentMainp->Visibility.FarFog));
#endif

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

#else

/**
 * 
 * .bss
glabel dword_CODE_bss_800825F8
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
 * 
*/
/**
 * hack:
 * variables referenced in the following asm are wrong, just used
 * to get matching addresses.
*/
GLOBAL_ASM(




.text
glabel fogSwitchToSolosky2
/* 0ECA68 7F0BA078 3C028007 */  lui   $v0, %hi(g_EnvironmentMainp) # $v0, 0x8007
/* 0ECA6C 7F0BA07C 8C42CF8C */  lw    $v0, %lo(g_EnvironmentMainp)($v0)
/* 0ECA70 7F0BA080 3C048007 */  lui   $a0, %hi(g_EnvironmentMainp + 0x1c) # $a0, 0x8007
/* 0ECA74 7F0BA084 2484CFA8 */  addiu $a0, %lo(g_EnvironmentMainp + 0x1c) # addiu $a0, $a0, -0x3058
/* 0ECA78 7F0BA088 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0ECA7C 7F0BA08C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0ECA80 7F0BA090 00804025 */  move  $t0, $a0
/* 0ECA84 7F0BA094 0040C825 */  move  $t9, $v0
/* 0ECA88 7F0BA098 24580024 */  addiu $t8, $v0, 0x24
.L7F0BA09C:
/* 0ECA8C 7F0BA09C 8B210000 */  lwl   $at, ($t9)
/* 0ECA90 7F0BA0A0 9B210003 */  lwr   $at, 3($t9)
/* 0ECA94 7F0BA0A4 2739000C */  addiu $t9, $t9, 0xc
/* 0ECA98 7F0BA0A8 2508000C */  addiu $t0, $t0, 0xc
/* 0ECA9C 7F0BA0AC AD01FFF4 */  sw    $at, -0xc($t0)
/* 0ECAA0 7F0BA0B0 8B21FFF8 */  lwl   $at, -8($t9)
/* 0ECAA4 7F0BA0B4 9B21FFFB */  lwr   $at, -5($t9)
/* 0ECAA8 7F0BA0B8 AD01FFF8 */  sw    $at, -8($t0)
/* 0ECAAC 7F0BA0BC 8B21FFFC */  lwl   $at, -4($t9)
/* 0ECAB0 7F0BA0C0 9B21FFFF */  lwr   $at, -1($t9)
/* 0ECAB4 7F0BA0C4 1738FFF5 */  bne   $t9, $t8, .L7F0BA09C
/* 0ECAB8 7F0BA0C8 AD01FFFC */   sw    $at, -4($t0)
/* 0ECABC 7F0BA0CC 3C038007 */  lui   $v1, %hi(g_EnvironmentMainp) # $v1, 0x8007
/* 0ECAC0 7F0BA0D0 8C63CF90 */  lw    $v1, %lo(g_EnvironmentMainp+4)($v1)
/* 0ECAC4 7F0BA0D4 84490002 */  lh    $t1, 2($v0)
/* 0ECAC8 7F0BA0D8 3C018007 */  lui   $at, %hi(g_EnvironmentMainp+4) # $at, 0x8007
/* 0ECACC 7F0BA0DC 846A0002 */  lh    $t2, 2($v1)
/* 0ECAD0 7F0BA0E0 44892000 */  mtc1  $t1, $f4
/* 0ECAD4 7F0BA0E4 448A3000 */  mtc1  $t2, $f6
/* 0ECAD8 7F0BA0E8 46802020 */  cvt.s.w $f0, $f4
/* 0ECADC 7F0BA0EC 46803220 */  cvt.s.w $f8, $f6
/* 0ECAE0 7F0BA0F0 46004281 */  sub.s $f10, $f8, $f0
/* 0ECAE4 7F0BA0F4 460A6102 */  mul.s $f4, $f12, $f10
/* 0ECAE8 7F0BA0F8 46040180 */  add.s $f6, $f0, $f4
/* 0ECAEC 7F0BA0FC 4600320D */  trunc.w.s $f8, $f6
/* 0ECAF0 7F0BA100 440C4000 */  mfc1  $t4, $f8
/* 0ECAF4 7F0BA104 00000000 */  nop   
/* 0ECAF8 7F0BA108 A42CCFAA */  sh    $t4, %lo(g_EnvironmentMainp+0x1e)($at)
/* 0ECAFC 7F0BA10C 844D0004 */  lh    $t5, 4($v0)
/* 0ECB00 7F0BA110 846F0004 */  lh    $t7, 4($v1)
/* 0ECB04 7F0BA114 448D5000 */  mtc1  $t5, $f10
/* 0ECB08 7F0BA118 448F2000 */  mtc1  $t7, $f4
/* 0ECB0C 7F0BA11C 468050A0 */  cvt.s.w $f2, $f10
/* 0ECB10 7F0BA120 468021A0 */  cvt.s.w $f6, $f4
/* 0ECB14 7F0BA124 46023201 */  sub.s $f8, $f6, $f2
/* 0ECB18 7F0BA128 46086282 */  mul.s $f10, $f12, $f8
/* 0ECB1C 7F0BA12C 460A1100 */  add.s $f4, $f2, $f10
/* 0ECB20 7F0BA130 4600218D */  trunc.w.s $f6, $f4
/* 0ECB24 7F0BA134 44183000 */  mfc1  $t8, $f6
/* 0ECB28 7F0BA138 00000000 */  nop   
/* 0ECB2C 7F0BA13C A438CFAC */  sh    $t8, %lo(g_EnvironmentMainp+0x20)($at)
/* 0ECB30 7F0BA140 8459000C */  lh    $t9, 0xc($v0)
/* 0ECB34 7F0BA144 8468000C */  lh    $t0, 0xc($v1)
/* 0ECB38 7F0BA148 3C018007 */  lui   $at, %hi(g_EnvironmentMainp+0x20) # $at, 0x8007
/* 0ECB3C 7F0BA14C 44994000 */  mtc1  $t9, $f8
/* 0ECB40 7F0BA150 44885000 */  mtc1  $t0, $f10
/* 0ECB44 7F0BA154 468043A0 */  cvt.s.w $f14, $f8
/* 0ECB48 7F0BA158 46805120 */  cvt.s.w $f4, $f10
/* 0ECB4C 7F0BA15C 460E2181 */  sub.s $f6, $f4, $f14
/* 0ECB50 7F0BA160 46066202 */  mul.s $f8, $f12, $f6
/* 0ECB54 7F0BA164 46087280 */  add.s $f10, $f14, $f8
/* 0ECB58 7F0BA168 4600510D */  trunc.w.s $f4, $f10
/* 0ECB5C 7F0BA16C 440A2000 */  mfc1  $t2, $f4
/* 0ECB60 7F0BA170 00000000 */  nop   
/* 0ECB64 7F0BA174 A42ACFB4 */  sh    $t2, %lo(g_EnvironmentMainp+0x28)($at)
/* 0ECB68 7F0BA178 844B000E */  lh    $t3, 0xe($v0)
/* 0ECB6C 7F0BA17C 846C000E */  lh    $t4, 0xe($v1)
/* 0ECB70 7F0BA180 448B3000 */  mtc1  $t3, $f6
/* 0ECB74 7F0BA184 448C4000 */  mtc1  $t4, $f8
/* 0ECB78 7F0BA188 46803420 */  cvt.s.w $f16, $f6
/* 0ECB7C 7F0BA18C 468042A0 */  cvt.s.w $f10, $f8
/* 0ECB80 7F0BA190 46105101 */  sub.s $f4, $f10, $f16
/* 0ECB84 7F0BA194 46046182 */  mul.s $f6, $f12, $f4
/* 0ECB88 7F0BA198 46068200 */  add.s $f8, $f16, $f6
/* 0ECB8C 7F0BA19C 4600428D */  trunc.w.s $f10, $f8
/* 0ECB90 7F0BA1A0 440F5000 */  mfc1  $t7, $f10
/* 0ECB94 7F0BA1A4 00000000 */  nop   
/* 0ECB98 7F0BA1A8 A42FCFB6 */  sh    $t7, %lo(g_EnvironmentMainp+0x2a)($at)
/* 0ECB9C 7F0BA1AC 904E0010 */  lbu   $t6, 0x10($v0)
/* 0ECBA0 7F0BA1B0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0ECBA4 7F0BA1B4 448E2000 */  mtc1  $t6, $f4
/* 0ECBA8 7F0BA1B8 05C10004 */  bgez  $t6, .L7F0BA1CC
/* 0ECBAC 7F0BA1BC 468024A0 */   cvt.s.w $f18, $f4
/* 0ECBB0 7F0BA1C0 44813000 */  mtc1  $at, $f6
/* 0ECBB4 7F0BA1C4 00000000 */  nop   
/* 0ECBB8 7F0BA1C8 46069480 */  add.s $f18, $f18, $f6
.L7F0BA1CC:
/* 0ECBBC 7F0BA1CC 90780010 */  lbu   $t8, 0x10($v1)
/* 0ECBC0 7F0BA1D0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0ECBC4 7F0BA1D4 44984000 */  mtc1  $t8, $f8
/* 0ECBC8 7F0BA1D8 07010004 */  bgez  $t8, .L7F0BA1EC
/* 0ECBCC 7F0BA1DC 468042A0 */   cvt.s.w $f10, $f8
/* 0ECBD0 7F0BA1E0 44812000 */  mtc1  $at, $f4
/* 0ECBD4 7F0BA1E4 00000000 */  nop   
/* 0ECBD8 7F0BA1E8 46045280 */  add.s $f10, $f10, $f4
.L7F0BA1EC:
/* 0ECBDC 7F0BA1EC 46125181 */  sub.s $f6, $f10, $f18
/* 0ECBE0 7F0BA1F0 24080001 */  li    $t0, 1
/* 0ECBE4 7F0BA1F4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0ECBE8 7F0BA1F8 46066202 */  mul.s $f8, $f12, $f6
/* 0ECBEC 7F0BA1FC 46089100 */  add.s $f4, $f18, $f8
/* 0ECBF0 7F0BA200 4459F800 */  cfc1  $t9, $31
/* 0ECBF4 7F0BA204 44C8F800 */  ctc1  $t0, $31
/* 0ECBF8 7F0BA208 00000000 */  nop   
/* 0ECBFC 7F0BA20C 460022A4 */  cvt.w.s $f10, $f4
/* 0ECC00 7F0BA210 4448F800 */  cfc1  $t0, $31
/* 0ECC04 7F0BA214 00000000 */  nop   
/* 0ECC08 7F0BA218 31080078 */  andi  $t0, $t0, 0x78
/* 0ECC0C 7F0BA21C 51000013 */  beql  $t0, $zero, .L7F0BA26C
/* 0ECC10 7F0BA220 44085000 */   mfc1  $t0, $f10
/* 0ECC14 7F0BA224 44815000 */  mtc1  $at, $f10
/* 0ECC18 7F0BA228 24080001 */  li    $t0, 1
/* 0ECC1C 7F0BA22C 460A2281 */  sub.s $f10, $f4, $f10
/* 0ECC20 7F0BA230 44C8F800 */  ctc1  $t0, $31
/* 0ECC24 7F0BA234 00000000 */  nop   
/* 0ECC28 7F0BA238 460052A4 */  cvt.w.s $f10, $f10
/* 0ECC2C 7F0BA23C 4448F800 */  cfc1  $t0, $31
/* 0ECC30 7F0BA240 00000000 */  nop   
/* 0ECC34 7F0BA244 31080078 */  andi  $t0, $t0, 0x78
/* 0ECC38 7F0BA248 15000005 */  bnez  $t0, .L7F0BA260
/* 0ECC3C 7F0BA24C 00000000 */   nop   
/* 0ECC40 7F0BA250 44085000 */  mfc1  $t0, $f10
/* 0ECC44 7F0BA254 3C018000 */  lui   $at, 0x8000
/* 0ECC48 7F0BA258 10000007 */  b     .L7F0BA278
/* 0ECC4C 7F0BA25C 01014025 */   or    $t0, $t0, $at
.L7F0BA260:
/* 0ECC50 7F0BA260 10000005 */  b     .L7F0BA278
/* 0ECC54 7F0BA264 2408FFFF */   li    $t0, -1
/* 0ECC58 7F0BA268 44085000 */  mfc1  $t0, $f10
.L7F0BA26C:
/* 0ECC5C 7F0BA26C 00000000 */  nop   
/* 0ECC60 7F0BA270 0500FFFB */  bltz  $t0, .L7F0BA260
/* 0ECC64 7F0BA274 00000000 */   nop   
.L7F0BA278:
/* 0ECC68 7F0BA278 3C018007 */  lui   $at, %hi(g_EnvironmentMainp+0x2c) # $at, 0x8007
/* 0ECC6C 7F0BA27C A028CFB8 */  sb    $t0, %lo(g_EnvironmentMainp+0x2c)($at)
/* 0ECC70 7F0BA280 90490011 */  lbu   $t1, 0x11($v0)
/* 0ECC74 7F0BA284 44D9F800 */  ctc1  $t9, $31
/* 0ECC78 7F0BA288 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0ECC7C 7F0BA28C 44893000 */  mtc1  $t1, $f6
/* 0ECC80 7F0BA290 05210004 */  bgez  $t1, .L7F0BA2A4
/* 0ECC84 7F0BA294 46803220 */   cvt.s.w $f8, $f6
/* 0ECC88 7F0BA298 44812000 */  mtc1  $at, $f4
/* 0ECC8C 7F0BA29C 00000000 */  nop   
/* 0ECC90 7F0BA2A0 46044200 */  add.s $f8, $f8, $f4
.L7F0BA2A4:
/* 0ECC94 7F0BA2A4 E7A80018 */  swc1  $f8, 0x18($sp)
/* 0ECC98 7F0BA2A8 906A0011 */  lbu   $t2, 0x11($v1)
/* 0ECC9C 7F0BA2AC C7A80018 */  lwc1  $f8, 0x18($sp)
/* 0ECCA0 7F0BA2B0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0ECCA4 7F0BA2B4 448A5000 */  mtc1  $t2, $f10
/* 0ECCA8 7F0BA2B8 310900F8 */  andi  $t1, $t0, 0xf8
/* 0ECCAC 7F0BA2BC 05410004 */  bgez  $t2, .L7F0BA2D0
/* 0ECCB0 7F0BA2C0 468051A0 */   cvt.s.w $f6, $f10
/* 0ECCB4 7F0BA2C4 44812000 */  mtc1  $at, $f4
/* 0ECCB8 7F0BA2C8 00000000 */  nop   
/* 0ECCBC 7F0BA2CC 46043180 */  add.s $f6, $f6, $f4
.L7F0BA2D0:
/* 0ECCC0 7F0BA2D0 46083281 */  sub.s $f10, $f6, $f8
/* 0ECCC4 7F0BA2D4 240C0001 */  li    $t4, 1
/* 0ECCC8 7F0BA2D8 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0ECCCC 7F0BA2DC 460A6102 */  mul.s $f4, $f12, $f10
/* 0ECCD0 7F0BA2E0 46044180 */  add.s $f6, $f8, $f4
/* 0ECCD4 7F0BA2E4 444BF800 */  cfc1  $t3, $31
/* 0ECCD8 7F0BA2E8 44CCF800 */  ctc1  $t4, $31
/* 0ECCDC 7F0BA2EC 00000000 */  nop   
/* 0ECCE0 7F0BA2F0 460032A4 */  cvt.w.s $f10, $f6
/* 0ECCE4 7F0BA2F4 444CF800 */  cfc1  $t4, $31
/* 0ECCE8 7F0BA2F8 00000000 */  nop   
/* 0ECCEC 7F0BA2FC 318C0078 */  andi  $t4, $t4, 0x78
/* 0ECCF0 7F0BA300 51800013 */  beql  $t4, $zero, .L7F0BA350
/* 0ECCF4 7F0BA304 440C5000 */   mfc1  $t4, $f10
/* 0ECCF8 7F0BA308 44815000 */  mtc1  $at, $f10
/* 0ECCFC 7F0BA30C 240C0001 */  li    $t4, 1
/* 0ECD00 7F0BA310 460A3281 */  sub.s $f10, $f6, $f10
/* 0ECD04 7F0BA314 44CCF800 */  ctc1  $t4, $31
/* 0ECD08 7F0BA318 00000000 */  nop   
/* 0ECD0C 7F0BA31C 460052A4 */  cvt.w.s $f10, $f10
/* 0ECD10 7F0BA320 444CF800 */  cfc1  $t4, $31
/* 0ECD14 7F0BA324 00000000 */  nop   
/* 0ECD18 7F0BA328 318C0078 */  andi  $t4, $t4, 0x78
/* 0ECD1C 7F0BA32C 15800005 */  bnez  $t4, .L7F0BA344
/* 0ECD20 7F0BA330 00000000 */   nop   
/* 0ECD24 7F0BA334 440C5000 */  mfc1  $t4, $f10
/* 0ECD28 7F0BA338 3C018000 */  lui   $at, 0x8000
/* 0ECD2C 7F0BA33C 10000007 */  b     .L7F0BA35C
/* 0ECD30 7F0BA340 01816025 */   or    $t4, $t4, $at
.L7F0BA344:
/* 0ECD34 7F0BA344 10000005 */  b     .L7F0BA35C
/* 0ECD38 7F0BA348 240CFFFF */   li    $t4, -1
/* 0ECD3C 7F0BA34C 440C5000 */  mfc1  $t4, $f10
.L7F0BA350:
/* 0ECD40 7F0BA350 00000000 */  nop   
/* 0ECD44 7F0BA354 0580FFFB */  bltz  $t4, .L7F0BA344
/* 0ECD48 7F0BA358 00000000 */   nop   
.L7F0BA35C:
/* 0ECD4C 7F0BA35C 3C018007 */  lui   $at, %hi(g_EnvironmentMainp+0x2d) # $at, 0x8007
/* 0ECD50 7F0BA360 A02CCFB9 */  sb    $t4, %lo(g_EnvironmentMainp+0x2d)($at)
/* 0ECD54 7F0BA364 904D0012 */  lbu   $t5, 0x12($v0)
/* 0ECD58 7F0BA368 44CBF800 */  ctc1  $t3, $31
/* 0ECD5C 7F0BA36C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0ECD60 7F0BA370 448D4000 */  mtc1  $t5, $f8
/* 0ECD64 7F0BA374 318B00F8 */  andi  $t3, $t4, 0xf8
/* 0ECD68 7F0BA378 05A10004 */  bgez  $t5, .L7F0BA38C
/* 0ECD6C 7F0BA37C 46804120 */   cvt.s.w $f4, $f8
/* 0ECD70 7F0BA380 44813000 */  mtc1  $at, $f6
/* 0ECD74 7F0BA384 00000000 */  nop   
/* 0ECD78 7F0BA388 46062100 */  add.s $f4, $f4, $f6
.L7F0BA38C:
/* 0ECD7C 7F0BA38C E7A4001C */  swc1  $f4, 0x1c($sp)
/* 0ECD80 7F0BA390 906F0012 */  lbu   $t7, 0x12($v1)
/* 0ECD84 7F0BA394 C7A4001C */  lwc1  $f4, 0x1c($sp)
/* 0ECD88 7F0BA398 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0ECD8C 7F0BA39C 448F5000 */  mtc1  $t7, $f10
/* 0ECD90 7F0BA3A0 05E10004 */  bgez  $t7, .L7F0BA3B4
/* 0ECD94 7F0BA3A4 46805220 */   cvt.s.w $f8, $f10
/* 0ECD98 7F0BA3A8 44813000 */  mtc1  $at, $f6
/* 0ECD9C 7F0BA3AC 00000000 */  nop   
/* 0ECDA0 7F0BA3B0 46064200 */  add.s $f8, $f8, $f6
.L7F0BA3B4:
/* 0ECDA4 7F0BA3B4 46044281 */  sub.s $f10, $f8, $f4
/* 0ECDA8 7F0BA3B8 24180001 */  li    $t8, 1
/* 0ECDAC 7F0BA3BC 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0ECDB0 7F0BA3C0 460A6182 */  mul.s $f6, $f12, $f10
/* 0ECDB4 7F0BA3C4 46062200 */  add.s $f8, $f4, $f6
/* 0ECDB8 7F0BA3C8 444EF800 */  cfc1  $t6, $31
/* 0ECDBC 7F0BA3CC 44D8F800 */  ctc1  $t8, $31
/* 0ECDC0 7F0BA3D0 00000000 */  nop   
/* 0ECDC4 7F0BA3D4 460042A4 */  cvt.w.s $f10, $f8
/* 0ECDC8 7F0BA3D8 4458F800 */  cfc1  $t8, $31
/* 0ECDCC 7F0BA3DC 00000000 */  nop   
/* 0ECDD0 7F0BA3E0 33180078 */  andi  $t8, $t8, 0x78
/* 0ECDD4 7F0BA3E4 53000013 */  beql  $t8, $zero, .L7F0BA434
/* 0ECDD8 7F0BA3E8 44185000 */   mfc1  $t8, $f10
/* 0ECDDC 7F0BA3EC 44815000 */  mtc1  $at, $f10
/* 0ECDE0 7F0BA3F0 24180001 */  li    $t8, 1
/* 0ECDE4 7F0BA3F4 460A4281 */  sub.s $f10, $f8, $f10
/* 0ECDE8 7F0BA3F8 44D8F800 */  ctc1  $t8, $31
/* 0ECDEC 7F0BA3FC 00000000 */  nop   
/* 0ECDF0 7F0BA400 460052A4 */  cvt.w.s $f10, $f10
/* 0ECDF4 7F0BA404 4458F800 */  cfc1  $t8, $31
/* 0ECDF8 7F0BA408 00000000 */  nop   
/* 0ECDFC 7F0BA40C 33180078 */  andi  $t8, $t8, 0x78
/* 0ECE00 7F0BA410 17000005 */  bnez  $t8, .L7F0BA428
/* 0ECE04 7F0BA414 00000000 */   nop   
/* 0ECE08 7F0BA418 44185000 */  mfc1  $t8, $f10
/* 0ECE0C 7F0BA41C 3C018000 */  lui   $at, 0x8000
/* 0ECE10 7F0BA420 10000007 */  b     .L7F0BA440
/* 0ECE14 7F0BA424 0301C025 */   or    $t8, $t8, $at
.L7F0BA428:
/* 0ECE18 7F0BA428 10000005 */  b     .L7F0BA440
/* 0ECE1C 7F0BA42C 2418FFFF */   li    $t8, -1
/* 0ECE20 7F0BA430 44185000 */  mfc1  $t8, $f10
.L7F0BA434:
/* 0ECE24 7F0BA434 00000000 */  nop   
/* 0ECE28 7F0BA438 0700FFFB */  bltz  $t8, .L7F0BA428
/* 0ECE2C 7F0BA43C 00000000 */   nop   
.L7F0BA440:
/* 0ECE30 7F0BA440 3C018007 */  lui   $at, %hi(g_EnvironmentMainp+0x2e) # $at, 0x8007
/* 0ECE34 7F0BA444 A038CFBA */  sb    $t8, %lo(g_EnvironmentMainp+0x2e)($at)
/* 0ECE38 7F0BA448 44CEF800 */  ctc1  $t6, $31
/* 0ECE3C 7F0BA44C 330F00F8 */  andi  $t7, $t8, 0xf8
/* 0ECE40 7F0BA450 A029CFB8 */  sb    $t1, %lo(g_EnvironmentMainp+0x2c)($at)
/* 0ECE44 7F0BA454 A02BCFB9 */  sb    $t3, %lo(g_EnvironmentMainp+0x2d)($at)
/* 0ECE48 7F0BA458 0FC2E67E */  jal   fogLoadCurrentEnvironment
/* 0ECE4C 7F0BA45C A02FCFBA */   sb    $t7, %lo(g_EnvironmentMainp+0x2e)($at)
/* 0ECE50 7F0BA460 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0ECE54 7F0BA464 27BD0020 */  addiu $sp, $sp, 0x20
/* 0ECE58 7F0BA468 03E00008 */  jr    $ra
/* 0ECE5C 7F0BA46C 00000000 */   nop   
)
#endif


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
        gDPSetFogColor(gdl++, g_CurrentEnvironment.Red, g_CurrentEnvironment.Green, g_CurrentEnvironment.Blue, 0xff);
        gSPFogPosition(gdl++, g_CurrentEnvironment.DifferenceFromFarIntensity, g_CurrentEnvironment.FarIntensity);
    }
    else
    {
        gDPSetFogColor(gdl++, g_CurrentEnvironment.Red, g_CurrentEnvironment.Green, g_CurrentEnvironment.Blue, 0xff);
        gSPFogPosition(gdl++, g_CurrentEnvironment.DifferenceFromFarIntensity, g_CurrentEnvironment.FarIntensity);
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
s32 fogPositionIsVisibleThroughFog(coord3d *pos, f32 range)
{
    coord3d sp24;
    f32 ff;
    coord3d *player_pos;
    Mtxf *player_mtx;

    if (g_FogSkyIsEnabled == 0)
    {
        return 1;
    }

    player_pos = bondviewGetCurrentPlayersPosition();
    player_mtx = camGetWorldToScreenMtxf();

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


NearFogRecord *fogGetNearFogValuesP(void)
{
    return g_NearFogValuesP;
}


/**
 * Address 0x7F0BB3A4.
*/
s32 fogGetPropDistColor(PropRecord *prop, rgba_f32 *color)
{
    if (g_FogSkyIsEnabled == 0)
    {
        return 2;
    }

    if (prop->Unk18 < 0.0f)
    {
        return 2;
    }

    color->rgba[0] = (f32) g_CurrentEnvironment.Red / 255.0f;
    color->rgba[1] = (f32) g_CurrentEnvironment.Green / 255.0f;
    color->rgba[2] = (f32) g_CurrentEnvironment.Blue / 255.0f;
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
