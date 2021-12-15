#ifndef _FOG_H_
#define _FOG_H_

#include "ultra64.h"
#include "bondtypes.h"

struct NearFogData {
    f32 NearFog;
    f32 MaxVisRange;
    f32 MaxObfuscationRange;
};

//New Definitions below
// SubRecords

// Skybox and Water Plane
typedef struct SkyBoxData
{
    u8 Red;
    u8 Green;
    u8 Blue;
    u8 Clouds;
    f32 CloudRepeat;
    s16 SkyImageId;
    u16 Reserved;
    f32 CloudRed;
    f32 CloudGreen;
    f32 CloudBlue;
    u8 IsWater;
    u8 Padding[3];
    f32 WaterRepeat;
    s16 WaterImageId;
    u16 Reserved2;
    f32 WaterRed;
    f32 WaterGreen;
    f32 WaterBlue;
    f32 WaterConcavity;
} SkyBoxData;

// Fog intensity
typedef struct FogData
{
    /**
     * Inverse NearFog
    */
    s32 DifferenceFromFarIntensity;
    s32 FarIntensity;

} FogData;

// Visibility distances and Z-Buffer accuriacy
typedef struct VisibilityData
{
    f32 BlendMultiplier;
    f32 FarFog;
    struct NearFogData Nfd;
    f32 MinVisrange;
    u32 Intensity;
} VisibilityData;

//Main Records

// Current Environment for rendering
typedef struct CurrentEnvData
{
    FogData Fog;
    SkyBoxData Sky;
} CurrentEnvData;

// Environment Record, Holds Visibility, Fog and Skybox
typedef struct EnvironmentData
{
    /**
     * ID = StageID + Token eg, Bunker Cinema is 9 + 900 = 909
    */
    u32 Id;
    VisibilityData Visibility;
    FogData Fog;
    SkyBoxData Sky;
} EnvironmentData;

// Environment Record, Holds only Skybox
typedef struct EnvironmentData_Fogless
{
    /**
     * ID = StageID + Token eg, Bunker Cinema is 9 + 900 = 909
    */
    u32 Id;
    SkyBoxData Sky;
} EnvironmentData_Fogless;

extern s32 g_FogSkyIsEnabled;

struct CurrentEnvData *fogGetCurrentEnvironmentp(void);
f32 fogGetScaledFarFogIntensitySquared(void);
void fogLoadLevelEnvironment(s32 level_id, s32 arg1);
s32 fogPositionIsVisibleThroughFog(struct coord3d *pos, f32 range);
Gfx *fogSetRenderFogColor(Gfx *arg0, s32 arg1);
Gfx *fogRenderClearFogMode(Gfx *gdl);
s32 fogGetPropDistColor(PropRecord *prop, struct rgba_f32 *color);
void fogSwitchToSolosky2(f32 arg0);
void fogRemoved7F0BAA5C(s32 a);
struct NearFogData *fogGetNearFogValuesP(void);

#endif
