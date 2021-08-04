#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"

//D:8003C4D0
ModelJoint JOINTLIST(standard_object)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C4D8
MODELSKELETON(standard_object, 1, 3)

//FIXME for rest of this skelton/joint section, the extra s32 between are file split padding most likely, and should be located in source model folder
//FIXME File split likely
//D:8003C4E4
s32 D_8003C4E4 = 0;
//D:8003C4E8
s32 D_8003C4E8 = 0;
//D:8003C4EC
s32 D_8003C4EC = 0;

//D:8003C4F0
ModelJoint JOINTLIST(prop_weapon)[] = {
    {0x0015, 0x0000, 0x0000},
    {0x0015, 0x0001, 0x0001}
};
//D:8003C4FC
MODELSKELETON(prop_weapon, 2, 0)

//FIXME File split likely
//D:8003C508
s32 D_8003C508 = 0;
//D:8003C50C
s32 D_8003C50C = 0;

//D:8003C510
ModelJoint JOINTLIST(player_gait_object)[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x000C},
    {0x0002, 0x000C, 0x0009},
    {0x0002, 0x000F, 0x0012},
    {0x0002, 0x0012, 0x000F},
    {0x0002, 0x0015, 0x0018},
    {0x0002, 0x0018, 0x0015},
    {0x0002, 0x001B, 0x001E},
    {0x0002, 0x001E, 0x001B},
    {0x0002, 0x0021, 0x0024},
    {0x0002, 0x0024, 0x0021},
    {0x0002, 0x0027, 0x002A},
    {0x0002, 0x002A, 0x0027}
};
//D:8003C570
MODELSKELETON(player_gait_object, 16, 45)

//FIXME File split likely
//D:8003C57C
s32 D_8003C57C = 0;


//D:8003C580
ModelNode player_gait_hdr = {1, &player_gait_obj, 0, 0, 0, &player_gait_pos_hdr_1};
//D:8003C598
ModelNode player_gait_pos_hdr_1 = {2,&player_gait_pos_1, &player_gait_hdr, 0, 0, &player_gait_pos_hdr_2};
//D:8003C5B0
ModelNode player_gait_pos_hdr_2 = {2, &player_gait_pos_2, &player_gait_pos_hdr_1, 0, 0, &player_gait_pos_hdr_3};
//D:8003C5C8
ModelNode player_gait_pos_hdr_3 = {2, &player_gait_pos_3, &player_gait_pos_hdr_2, 0, 0, 0};
//D:8003C5E0
ModelNode_HeaderRecord player_gait_obj = {1, &player_gait_pos_hdr_1, 0, 0, 0, 0};
//D:8003C5F0
ModelNode_GroupRecord player_gait_pos_1 = {{0.0, 0.0, 0.0}, 0x0001, 0x0002, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_2, 0};
//D:8003C60C
ModelNode_GroupRecord player_gait_pos_2 = {{1.177982, 41.14437, 0.0}, 0x0002, 0x0003, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_3, 0};
//D:8003C628
ModelNode_GroupRecord player_gait_pos_3 = {{-2.576027, 480.42902, 0.0}, 0x0003, 0x0000, 0xFFFF, 0xFFFF, NULL, 0};

//FIXME File split likely
//D:8003C644
s32 D_8003C644 = 0;
//D:8003C648
s32 D_8003C648 = 0;
//D:8003C64C
s32 D_8003C64C = 0;


//D:8003C650
FILEHEADER(player_gait_object, 0, &SKELETON(player_gait_object), 0, 0, 4, 41.16123, 0, 0)

//FIXME File split likely
//D:8003C670
ModelJoint JOINTLIST(suit_lf_hand)[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x000C},
    {0x0002, 0x000C, 0x0009},
    {0x0002, 0x000F, 0x0012},
    {0x0002, 0x0012, 0x000F},
    {0x0002, 0x0015, 0x0018},
    {0x0002, 0x0018, 0x0015},
    {0x0002, 0x001B, 0x001E},
    {0x0002, 0x001E, 0x001B},
    {0x0002, 0x0021, 0x0024},
    {0x0002, 0x0024, 0x0021},
    {0x0002, 0x0027, 0x002A},
    {0x0002, 0x002A, 0x0027},
    {0x0015, 0x002D, 0x002D},
    {0x0015, 0x002E, 0x002E},
    {0x0015, 0x002F, 0x002F},
};
//D:8003C6E4
MODELSKELETON(suit_lf_hand, 19, 45)

//FIXME File split likely
//D:8003C6F0
ModelJoint JOINTLIST(standard_gun)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0015, 0x000F, 0x000F},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003C714
MODELSKELETON(standard_gun, 6, 15)

//FIXME File split likely
//D:8003C720
ModelJoint JOINTLIST(gun_unassigned)[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C728
MODELSKELETON(gun_unassigned, 1, 3)

//FIXME File split likely
//D:8003C734
s32 D_8003C734 = 0;
//D:8003C738
s32 D_8003C738 = 0;
//D:8003C73C
s32 D_8003C73C = 0;
//D:8003C740
ModelJoint JOINTLIST(gun_revolver)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012}
};
//D:8003C76C
MODELSKELETON(gun_revolver, 7, 21)

//FIXME File split likely
//D:8003C778
s32 D_8003C778 = 0;
//D:8003C77C
s32 D_8003C77C = 0;
//D:8003C780
ModelJoint JOINTLIST(gun_kf7)[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0015, 0x0012, 0x0012},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003C7AC
MODELSKELETON(gun_kf7, 7, 0x12)

//FIXME File split likely
//D:8003C7B8
s32 D_8003C7B8 = 0;
//D:8003C7BC
s32 D_8003C7BC = 0;

//D:8003C7C0
#include "assets/obseg/gun/gunModelFileHeaders.inc.c"

//FIXME File split likely
//D:8003D340
//ModelJoint 
ModelJoint JOINTLIST(g_weapon)[] = {
    {0x02, 0x00, 0x00}, 
    {0x02, 0x03, 0x03}, 
    {0x02, 0x06, 0x06}, 
    {0x02, 0x09, 0x09}, 
    {0x02, 0x0C, 0x0C}, 
    {0x02, 0x0F, 0x0F}, 
    {0x02, 0x12, 0x12}, 
    {0x02, 0x15, 0x15}, 
    {0x02, 0x18, 0x18}, 
    {0x02, 0x1B, 0x1B}, 
    {0x02, 0x1E, 0x1E}, 
    {0x02, 0x21, 0x21}, 
    {0x02, 0x24, 0x24}
};


//D:8003D390
MODELSKELETON(g_weapon, 0xD, 0x27)

//FIXME File split likely
//D:8003D39C
s32 D_8003D39C = 0;

ModelJoint JOINTLIST(guard)[] = {
    {0x401, 0x0, 0x0}, 
    {0x02, 0x00, 0x00},
    {0x02, 0x03, 0x03}, 
    {0x02, 0x06, 0x06}, 
    {0x02, 0x09, 0x0C},
    {0x02, 0x0C, 0x09},
    {0x02, 0x0F, 0x12},
    {0x02, 0x12, 0x0F},
    {0x02, 0x15, 0x18},
    {0x02, 0x18, 0x15},
    {0x02, 0x1B, 0x1E},
    {0x02, 0x1E, 0x1B},
    {0x02, 0x21, 0x24},
    {0x02, 0x24, 0x21},
    {0x02, 0x27, 0x2A},
    {0x02, 0x2A, 0x27}
};


//D:8003D400
MODELSKELETON(guard, 0x10, 0x2D)
//D:8003D40C



