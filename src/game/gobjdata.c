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
struct ModelFileHeader wppk_header = {0, &skeleton_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xC, 0, 0};
//D:8003C7E0
struct ModelFileHeader wppksil_header = {0, &skeleton_standard_gun, 0, 0x24, 6, 438.66476, 0, 0xC, 0, 0};
//D:8003C800
struct ModelFileHeader tt33_header = {0, &skeleton_standard_gun, 0, 0x24, 6, 438.16788, 0, 0xF, 0, 0};
//D:8003C820
struct ModelFileHeader skorpian_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 390.40039, 0, 0xC, 0, 0};
//D:8003C840
struct ModelFileHeader ak47_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 941.9339, 0, 0x12, 0, 0};
//D:8003C860
struct ModelFileHeader uzi_header = {0, &skeleton_gun_kf7, 0, 0x24, 5, 436.95404, 0, 0xC, 0, 0};
//D:8003C880
struct ModelFileHeader mp5k_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 499.24536, 0, 9, 0, 0};
//D:8003C8A0
struct ModelFileHeader mp5ksil_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 655.97717, 0, 9, 0, 0};
//D:8003C8C0
struct ModelFileHeader m16_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 1096.2413, 0, 8, 0, 0};
//D:8003C8E0
struct ModelFileHeader fnp90_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 460.81909, 0, 0xA, 0, 0};
//D:8003C900
struct ModelFileHeader G8003C900_struct = {0, &skeleton_standard_gun, 0, 0x1C, 3, 238.62167, 0, 4, 0, 0};
//D:8003C920
struct ModelFileHeader ruger_header = {0, &skeleton_gun_revolver, 0, 0x24, 6, 553.44312, 0, 0xE, 0, 0};
//D:8003C940
struct ModelFileHeader goldengun_header = {0, &skeleton_standard_gun, 0, 0x24, 5, 384.92172, 0, 0xB, 0, 0};
//D:8003C960
struct ModelFileHeader shotgun_header = {0, &skeleton_standard_gun, 0, 0x1C, 4, 919.33038, 0, 0xD, 0, 0};
//D:8003C980
struct ModelFileHeader autoshot_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 840.15125, 0, 0x10, 0, 0};
//D:8003C9A0
struct ModelFileHeader grenadelaunch_header = {0, &skeleton_gun_revolver, 0, 0x24, 5, 768.33496, 0, 0xF, 0, 0};
//D:8003C9C0
struct ModelFileHeader spectre_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 598.42865, 0, 0xB, 0, 0};
//D:8003C9E0
struct ModelFileHeader laser_header = {0, &skeleton_standard_gun, 0, 0x24, 3, 442.81848, 0, 0xD, 0, 0};
//D:8003CA00
struct ModelFileHeader rocketlaunch_header = {0, &skeleton_standard_gun, 0, 0x24, 3, 566.51208, 0, 0xA, 0, 0};
//D:8003CA20
struct ModelFileHeader knife_header = {0, &skeleton_standard_gun, 0, 0x24, 3, 376.97263, 0, 9, 0, 0};
//D:8003CA40
struct ModelFileHeader throwknife_header = {0, &skeleton_standard_gun, 0, 0x24, 3, 373.31387, 0, 9, 0, 0};
//D:8003CA60
struct ModelFileHeader taser_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 182.78622, 0, 0x11, 0, 0};
//D:8003CA80
struct ModelFileHeader remotemine_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 50.999378, 0, 3, 0, 0};
//D:8003CAA0
struct ModelFileHeader proximitymine_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 51.00029, 0, 3, 0, 0};
//D:8003CAC0
struct ModelFileHeader timedmine_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 49.368877, 0, 4, 0, 0};
//D:8003CAE0
struct ModelFileHeader trigger_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003CB00
struct ModelFileHeader grenade_header = {0, &skeleton_standard_gun, 0, 0x24, 3, 427.27081, 0, 5, 0, 0};
//D:8003CB20
struct ModelFileHeader fist_header = {0, &skeleton_standard_gun, 0, 0x24, 3, 243.84764, 0, 0xE, 0, 0};
//D:8003CB40
struct ModelFileHeader sniperrifle_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 808.03253, 0, 7, 0, 0};
//D:8003CB60
struct ModelFileHeader cartridge_header = {0, &skeleton_gun_unassigned, 0, 0, 1, 14.128822, 0, 2, 0, 0};
//D:8003CB80
struct ModelFileHeader cartrifle_header = {0, &skeleton_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBA0
struct ModelFileHeader cartblue_header = {0, &skeleton_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBC0
struct ModelFileHeader cartshell_header = {0, &skeleton_gun_unassigned, 0, 0, 1, 29.8451, 0, 2, 0, 0};
//D:8003CBE0
struct ModelFileHeader joypad_header = {0, &skeleton_g_weapon, 0, 0xE, 0xD, 523.96826, 0, 4, 0, 0};
//D:8003CC00
struct ModelFileHeader G8003CC00_struct = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC20
struct ModelFileHeader G8003CC20_struct = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC40
struct ModelFileHeader bombcase_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CC60
struct ModelFileHeader flarepistol_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC80
struct ModelFileHeader pitongun_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCA0
struct ModelFileHeader G8003CCA0_struct = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCC0
struct ModelFileHeader silverwppk_header = {0, &skeleton_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CCE0
struct ModelFileHeader goldwppk_header = {0, &skeleton_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CD00
struct ModelFileHeader G8003CD00_struct = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD20
struct ModelFileHeader bungee_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD40
struct ModelFileHeader doordecoder_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 60.850407, 0, 0x10, 0, 0};
//D:8003CD60
struct ModelFileHeader bombdefuser_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 84.370705, 0, 0xC, 0, 0};
//D:8003CD80
struct ModelFileHeader bugdetector_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CDA0
struct ModelFileHeader safecrackercase_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CDC0
struct ModelFileHeader camera_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 52.775627, 0, 0xB, 0, 0};
//D:8003CDE0
struct ModelFileHeader lockexploder_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE00
struct ModelFileHeader doorexploder_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE20
struct ModelFileHeader keyanalysercase_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE40
struct ModelFileHeader weaponcase_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE60
struct ModelFileHeader keycard_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 123.088844, 0, 2, 0, 0};
//D:8003CE80
struct ModelFileHeader keyyale_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 414.25156, 0, 1, 0, 0};
//D:8003CEA0
struct ModelFileHeader keybolt_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 759.26581, 0, 1, 0, 0};
//D:8003CEC0
struct ModelFileHeader bug_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 106.2163, 0, 6, 0, 0};
//D:8003CEE0
struct ModelFileHeader microcamera_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 70.039436, 0, 7, 0, 0};
//D:8003CF00
struct ModelFileHeader explosivefloppy_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 60.902443, 0, 5, 0, 0};
//D:8003CF20
struct ModelFileHeader goldeneyekey_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 98.987083, 0, 5, 0, 0};
//D:8003CF40
struct ModelFileHeader polarizedglasses_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 53.776386, 0, 2, 0, 0};
//D:8003CF60
struct ModelFileHeader creditcard_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CF80
struct ModelFileHeader darkglasses_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CFA0
struct ModelFileHeader watchidentifier_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFC0
struct ModelFileHeader watchcommunicator_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFE0
struct ModelFileHeader watchlaser_header = {0, &skeleton_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003D000
struct ModelFileHeader watchgeigercounter_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D020
struct ModelFileHeader watchmagnetrepel_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D040
struct ModelFileHeader watchmagnetattract_header = {0, &skeleton_standard_gun, 0, 0x1D, 3, 384.9288, 0, 9, 0, 0};
//D:8003D060
struct ModelFileHeader gaskeyring_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 111.59859, 0, 9, 0, 0};
//D:8003D080
struct ModelFileHeader datathief_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 119.78231, 0, 3, 0, 0};
//D:8003D0A0
struct ModelFileHeader briefcase_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003D0C0
struct ModelFileHeader blackbox_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 128.31796, 0, 5, 0, 0};
//D:8003D0E0
struct ModelFileHeader plastique_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 255.35242, 0, 3, 0, 0};
//D:8003D100
struct ModelFileHeader videotape_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 122.69632, 0, 9, 0, 0};
//D:8003D120
struct ModelFileHeader clipboard_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 190.41742, 0, 3, 0, 0};
//D:8003D140
struct ModelFileHeader stafflist_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 215.17534, 0, 4, 0, 0};
//D:8003D160
struct ModelFileHeader dossierred_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 183.54231, 0, 4, 0, 0};
//D:8003D180
struct ModelFileHeader audiotape_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 97.531075, 0, 9, 0, 0};
//D:8003D1A0
struct ModelFileHeader dattape_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 79.868584, 0, 4, 0, 0};
//D:8003D1C0
struct ModelFileHeader plans_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 81.950996, 0, 5, 0, 0};
//D:8003D1E0
struct ModelFileHeader spyfile_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D200
struct ModelFileHeader blueprints_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 125.3834, 0, 4, 0, 0};
//D:8003D220
struct ModelFileHeader circuitboard_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 138.90285, 0, 3, 0, 0};
//D:8003D240
struct ModelFileHeader map_header = {0, &skeleton_standard_gun, 0, 0x23, 3, 125.3834, 0, 4, 0, 0};
//D:8003D260
struct ModelFileHeader spooltape_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D280
struct ModelFileHeader microfilm_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2A0
struct ModelFileHeader microcode_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2C0
struct ModelFileHeader lectre_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2E0
struct ModelFileHeader money_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D300
struct ModelFileHeader goldbar_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D320
struct ModelFileHeader heroin_header = {0, &skeleton_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};

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



