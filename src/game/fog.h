#ifndef _FOG_H_
#define _FOG_H_

#include "ultra64.h"
#include "bondtypes.h"

struct fog_element {
    u32 stageID;
    f32 blendmultiplier;
    f32 farfog;
    f32 nearfog;
    f32 maxvisrange;
    f32 maxobfuscationrange;
    f32 minvisrange;
    u32 intensity;
    s32 dif_in_light;
    s32 far_ambiantlight;
    u8 red;
    u8 green;
    u8 blue;
    u8 clouds;
    f32 cloudrepeat;
    s16 skyimageid;
    u16 reserved;
    f32 cloudred;
    f32 cloudgreen;
    f32 cloudblue;
    u8 iswater;
    u8 padding[3];
    f32 waterrepeat;
    s16 waterimageid;
    u16 reserved2;
    f32 waterred;
    f32 watergreen;
    f32 waterblue;
    f32 waterconcavity;
};

struct fog_element2 {
    u32 stageID;
    u8 red;
    u8 green;
    u8 blue;
    u8 clouds;
    f32 cloudrepeat;
    s16 skyimageid;
    u16 reserved;
    f32 cloudred;
    f32 cloudgreen;
    f32 cloudblue;
    u8 iswater;
    u8 padding[3];
    f32 waterrepeat;
    s16 waterimageid;
    u16 reserved2;
    f32 waterred;
    f32 watergreen;
    f32 waterblue;
    f32 waterconcavity;
};

struct fog_loaded { 
    s32 dif_in_light;
    s32 far_ambiantlight;
    u8 red;
    u8 green;
    u8 blue;
    u8 clouds;
    f32 cloudrepeat;
    s16 skyimageid;
    f32 cloudred;
    f32 cloudgreen;
    f32 cloudblue;
    u8 iswater;
    f32 waterrepeat;
    s16 waterimageid;
    f32 waterred;
    f32 watergreen;
    f32 waterblue;
    f32 waterconcavity;
    u32 unk3c;
    u32 unk40;
};

struct fog_loaded *get_ptr_currentdata(void);
f32 square_near_fog_value(void);
void load_enviroment(s32 level_id, s32 arg1);
s32 fogPositionIsVisibleThroughFog(struct coord3d *pos, f32 range);
Gfx *sub_GAME_7F0BB070(Gfx *arg0, s32 arg1);
Gfx *sub_GAME_7F0BB298(Gfx *arg0);
s32 if_sky_present_convert_values(PropRecord *prop, struct rgba_f32 *color);

#endif
