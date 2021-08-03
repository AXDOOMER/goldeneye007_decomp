#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"

//D:8003C4D0
ModelJoint jointlist_standard_object[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C4D8
ModelSkeleton skeleton_standard_object = {1, 0, jointlist_standard_object, 3, 0};

//FIXME for rest of this skelton/joint section, the extra s32 between are file split padding most likely, and should be located in source model folder
//FIXME File split likely
//D:8003C4E4
s32 D_8003C4E4 = 0;
//D:8003C4E8
s32 D_8003C4E8 = 0;
//D:8003C4EC
s32 D_8003C4EC = 0;

//D:8003C4F0
ModelJoint jointlist_prop_weapon[] = {
    {0x0015, 0x0000, 0x0000},
    {0x0015, 0x0001, 0x0001}
};
//D:8003C4FC
ModelSkeleton skeleton_prop_weapon = {2, 0, jointlist_prop_weapon, 0, 0};

//FIXME File split likely
//D:8003C508
s32 D_8003C508 = 0;
//D:8003C50C
s32 D_8003C50C = 0;

//D:8003C510
ModelJoint dword_D_8003C510[] = {
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
ModelSkeleton jointlist_player_gait_object = {0x10, 0x0000, dword_D_8003C510, 0x2D, 0x0000};

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
ModelFileHeader player_gait_object_header = {0, &jointlist_player_gait_object,0,0, 4, 41.16123,0,0,0,0};

//FIXME File split likely
//D:8003C670
ModelJoint jointlist_suit_lf_hand[] = {
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
ModelSkeleton skeleton_suit_lf_hand = {0x13, 0x0000, jointlist_suit_lf_hand, 0x2D, 0x0000};

//FIXME File split likely
//D:8003C6F0
ModelJoint jointlist_standard_gun[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0015, 0x000F, 0x000F},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003C714
ModelSkeleton skeleton_standard_gun = {0x6, 0x0000, jointlist_standard_gun, 0xF, 0x0000};

//FIXME File split likely
//D:8003C720
ModelJoint jointlist_gun_unassigned[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C728
ModelSkeleton skeleton_gun_unassigned = {0x1, 0x0000, jointlist_gun_unassigned, 0x3, 0x0000};

//FIXME File split likely
//D:8003C734
s32 D_8003C734 = 0;
//D:8003C738
s32 D_8003C738 = 0;
//D:8003C73C
s32 D_8003C73C = 0;
//D:8003C740
ModelJoint jointlist_gun_revolver[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012}
};
//D:8003C76C
ModelSkeleton skeleton_gun_revolver = {0x7, 0x0000, jointlist_gun_revolver, 0x15, 0x0000};

//FIXME File split likely
//D:8003C778
s32 D_8003C778 = 0;
//D:8003C77C
s32 D_8003C77C = 0;
//D:8003C780
ModelJoint jointlist_gun_kf7[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0015, 0x0012, 0x0012},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003C7AC
ModelSkeleton skeleton_gun_kf7 = {0x7, 0x0000, jointlist_gun_kf7, 0x12, 0x0000};

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
ModelJoint jointlist_g_weapon[] = {
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
ModelSkeleton skeleton_g_weapon = {0xD, 0x0, jointlist_g_weapon, 0x27, 0x0};

//FIXME File split likely
//D:8003D39C
s32 D_8003D39C = 0;

ModelJoint jointlist_guard[] = {
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
ModelSkeleton skeleton_guard = {0x10, 0x0000, jointlist_guard, 0x2D, 0x0000};
//D:8003D40C



