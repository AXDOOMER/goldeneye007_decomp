#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"

//D:8003C4D0
struct ModelJoint word_D_8003C4D0[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C4D6                     .half 0
//D:8003C4D8
ModelSkeleton model_object_standard_object = {1, 0, word_D_8003C4D0, 3, 0};

//FIXME for rest of this skelton/joint section, the extra s32 between are file split padding most likely, and should be located in source model folder
//FIXME File split likely
//D:8003C4E4
s32 D_8003C4E4 = 0;
//D:8003C4E8
s32 D_8003C4E8 = 0;
//D:8003C4EC
s32 D_8003C4EC = 0;

//D:8003C4F0
struct ModelJoint word_D_8003C4F0[] = {
    {0x0015, 0x0000, 0x0000},
    {0x0015, 0x0001, 0x0001}
};
//D:8003C4FC
ModelSkeleton prop_weapon_related = {2, 0, word_D_8003C4F0, 0, 0};

//FIXME File split likely
//D:8003C508
s32 D_8003C508 = 0;
//D:8003C50C
s32 D_8003C50C = 0;

//D:8003C510
struct ModelJoint dword_D_8003C510[] = {
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


//item_related struct
//D:8003C570
ModelSkeleton dword_D_8003C570 = {0x10, 0x0000, dword_D_8003C510, 0x2D, 0x0000};

//FIXME File split likely
//D:8003C57C
s32 D_8003C57C = 0;


//D:8003C580
struct player_gait_header player_gait_hdr = {0, 1, 0, &player_gait_obj, NULL, 0, 0, &player_gait_pos_hdr_1};
//D:8003C598
struct player_gait_pos_header player_gait_pos_hdr_1 = {0, 2, 0, &player_gait_pos_1, (struct player_gait_pos_header *)&player_gait_hdr, 0, 0, &player_gait_pos_hdr_2};
//D:8003C5B0
struct player_gait_pos_header player_gait_pos_hdr_2 = {0, 2, 0, &player_gait_pos_2, &player_gait_pos_hdr_1, 0, 0, &player_gait_pos_hdr_3};
//D:8003C5C8
struct player_gait_pos_header player_gait_pos_hdr_3 = {0, 2, 0, &player_gait_pos_3, &player_gait_pos_hdr_2, 0, 0, 0};
//D:8003C5E0
struct player_gait_object_entry player_gait_obj = {1, &player_gait_pos_hdr_1, 0, 0};
//D:8003C5F0
struct player_gait_position_entry player_gait_pos_1 = {0.0, 0.0, 0.0, 0x0001, 0x0002, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_2, 0};
//D:8003C60C
struct player_gait_position_entry player_gait_pos_2 = {1.177982, 41.14437, 0, 0x0002, 0x0003, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_3, 0};
//D:8003C628
struct player_gait_position_entry player_gait_pos_3 = {-2.576027, 480.42902, 0, 0x0003, 0x0000, 0xFFFF, 0xFFFF, NULL, 0};

//FIXME File split likely
//D:8003C644
s32 D_8003C644 = 0;
//D:8003C648
s32 D_8003C648 = 0;
//D:8003C64C
s32 D_8003C64C = 0;


//D:8003C650
ModelFileHeader player_gait_object = {0, &dword_D_8003C570,0,0, 4, 41.16123,0,0,0,0};

//FIXME File split likely
//D:8003C670
struct ModelJoint dword_D_8003C670[] = {
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
ModelSkeleton model_suit_lf_hand = {0x13, 0x0000, dword_D_8003C670, 0x2D, 0x0000};

//FIXME File split likely
//D:8003C6F0
struct ModelJoint dword_D_8003C6F0[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0015, 0x000F, 0x000F},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003C714
ModelSkeleton weapon_gun_standard_gun = {0x6, 0x0000, dword_D_8003C6F0, 0xF, 0x0000};

//FIXME File split likely
//D:8003C720
struct ModelJoint dword_D_8003C720[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C728
ModelSkeleton weapon_gun_unassigned = {0x1, 0x0000, dword_D_8003C720, 0x3, 0x0000};

//FIXME File split likely
//D:8003C734
s32 D_8003C734 = 0;
//D:8003C738
s32 D_8003C738 = 0;
//D:8003C73C
s32 D_8003C73C = 0;
//D:8003C740
struct ModelJoint dword_D_8003C740[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012}
};
//D:8003C76C
ModelSkeleton weapon_gun_revolver = {0x7, 0x0000, dword_D_8003C740, 0x15, 0x0000};

//FIXME File split likely
//D:8003C778
s32 D_8003C778 = 0;
//D:8003C77C
s32 D_8003C77C = 0;
//D:8003C780
struct ModelJoint dword_D_8003C780[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0015, 0x0012, 0x0012},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003C7AC
ModelSkeleton weapon_gun_kf7 = {0x7, 0x0000, dword_D_8003C780, 0x12, 0x0000};

//FIXME File split likely
//D:8003C7B8
s32 D_8003C7B8 = 0;
//D:8003C7BC
s32 D_8003C7BC = 0;

//D:8003C7C0
struct ModelFileHeader GwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xC, 0, 0};
//D:8003C7E0
struct ModelFileHeader GwppksilZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 438.66476, 0, 0xC, 0, 0};
//D:8003C800
struct ModelFileHeader Gtt33Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 438.16788, 0, 0xF, 0, 0};
//D:8003C820
struct ModelFileHeader GskorpianZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 390.40039, 0, 0xC, 0, 0};
//D:8003C840
struct ModelFileHeader Gak47Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 941.9339, 0, 0x12, 0, 0};
//D:8003C860
struct ModelFileHeader GuziZ_struct = {0, &weapon_gun_kf7, 0, 0x24, 5, 436.95404, 0, 0xC, 0, 0};
//D:8003C880
struct ModelFileHeader Gmp5kZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 499.24536, 0, 9, 0, 0};
//D:8003C8A0
struct ModelFileHeader Gmp5ksilZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 655.97717, 0, 9, 0, 0};
//D:8003C8C0
struct ModelFileHeader Gm16Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 1096.2413, 0, 8, 0, 0};
//D:8003C8E0
struct ModelFileHeader Gfnp90Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 460.81909, 0, 0xA, 0, 0};
//D:8003C900
struct ModelFileHeader G8003C900_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 238.62167, 0, 4, 0, 0};
//D:8003C920
struct ModelFileHeader GrugerZ_struct = {0, &weapon_gun_revolver, 0, 0x24, 6, 553.44312, 0, 0xE, 0, 0};
//D:8003C940
struct ModelFileHeader GgoldengunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 5, 384.92172, 0, 0xB, 0, 0};
//D:8003C960
struct ModelFileHeader GshotgunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 4, 919.33038, 0, 0xD, 0, 0};
//D:8003C980
struct ModelFileHeader GautoshotZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 840.15125, 0, 0x10, 0, 0};
//D:8003C9A0
struct ModelFileHeader GgrenadelaunchZ_struct = {0, &weapon_gun_revolver, 0, 0x24, 5, 768.33496, 0, 0xF, 0, 0};
//D:8003C9C0
struct ModelFileHeader GspectreZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 598.42865, 0, 0xB, 0, 0};
//D:8003C9E0
struct ModelFileHeader GlaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 442.81848, 0, 0xD, 0, 0};
//D:8003CA00
struct ModelFileHeader GrocketlaunchZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 566.51208, 0, 0xA, 0, 0};
//D:8003CA20
struct ModelFileHeader GknifeZ_header = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 376.97263, 0, 9, 0, 0};
//D:8003CA40
struct ModelFileHeader GthrowknifeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 373.31387, 0, 9, 0, 0};
//D:8003CA60
struct ModelFileHeader GtaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 182.78622, 0, 0x11, 0, 0};
//D:8003CA80
struct ModelFileHeader GremotemineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 50.999378, 0, 3, 0, 0};
//D:8003CAA0
struct ModelFileHeader GproximitymineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 51.00029, 0, 3, 0, 0};
//D:8003CAC0
struct ModelFileHeader GtimedmineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 49.368877, 0, 4, 0, 0};
//D:8003CAE0
struct ModelFileHeader GtriggerZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003CB00
struct ModelFileHeader GgrenadeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 427.27081, 0, 5, 0, 0};
//D:8003CB20
struct ModelFileHeader GfistZ_header = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 243.84764, 0, 0xE, 0, 0};
//D:8003CB40
struct ModelFileHeader GsniperrifleZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 808.03253, 0, 7, 0, 0};
//D:8003CB60
struct ModelFileHeader GcartridgeZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 14.128822, 0, 2, 0, 0};
//D:8003CB80
struct ModelFileHeader GcartrifleZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBA0
struct ModelFileHeader GcartblueZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBC0
struct ModelFileHeader GcartshellZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 29.8451, 0, 2, 0, 0};
//D:8003CBE0
struct ModelFileHeader GjoypadZ_struct = {0, &weapon_gun_controller, 0, 0xE, 0xD, 523.96826, 0, 4, 0, 0};
//D:8003CC00
struct ModelFileHeader G8003CC00_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC20
struct ModelFileHeader G8003CC20_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC40
struct ModelFileHeader GbombcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CC60
struct ModelFileHeader GflarepistolZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC80
struct ModelFileHeader GpitongunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCA0
struct ModelFileHeader G8003CCA0_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCC0
struct ModelFileHeader GsilverwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CCE0
struct ModelFileHeader GgoldwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CD00
struct ModelFileHeader G8003CD00_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD20
struct ModelFileHeader GbungeeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD40
struct ModelFileHeader GdoordecoderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 60.850407, 0, 0x10, 0, 0};
//D:8003CD60
struct ModelFileHeader GbombdefuserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 84.370705, 0, 0xC, 0, 0};
//D:8003CD80
struct ModelFileHeader GbugdetectorZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CDA0
struct ModelFileHeader GsafecrackercaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CDC0
struct ModelFileHeader GcameraZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 52.775627, 0, 0xB, 0, 0};
//D:8003CDE0
struct ModelFileHeader GlockexploderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE00
struct ModelFileHeader GdoorexploderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE20
struct ModelFileHeader GkeyanalysercaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE40
struct ModelFileHeader GweaponcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE60
struct ModelFileHeader GkeycardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 123.088844, 0, 2, 0, 0};
//D:8003CE80
struct ModelFileHeader GkeyyaleZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 414.25156, 0, 1, 0, 0};
//D:8003CEA0
struct ModelFileHeader GkeyboltZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 759.26581, 0, 1, 0, 0};
//D:8003CEC0
struct ModelFileHeader GbugZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 106.2163, 0, 6, 0, 0};
//D:8003CEE0
struct ModelFileHeader GmicrocameraZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 70.039436, 0, 7, 0, 0};
//D:8003CF00
struct ModelFileHeader GexplosivefloppyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 60.902443, 0, 5, 0, 0};
//D:8003CF20
struct ModelFileHeader GgoldeneyekeyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 98.987083, 0, 5, 0, 0};
//D:8003CF40
struct ModelFileHeader GpolarizedglassesZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 53.776386, 0, 2, 0, 0};
//D:8003CF60
struct ModelFileHeader GcreditcardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CF80
struct ModelFileHeader GdarkglassesZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CFA0
struct ModelFileHeader GwatchidentifierZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFC0
struct ModelFileHeader GwatchcommunicatorZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFE0
struct ModelFileHeader GwatchlaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003D000
struct ModelFileHeader GwatchgeigercounterZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D020
struct ModelFileHeader GwatchmagnetrepelZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D040
struct ModelFileHeader GwatchmagnetattractZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1D, 3, 384.9288, 0, 9, 0, 0};
//D:8003D060
struct ModelFileHeader GgaskeyringZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 111.59859, 0, 9, 0, 0};
//D:8003D080
struct ModelFileHeader GdatathiefZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 119.78231, 0, 3, 0, 0};
//D:8003D0A0
struct ModelFileHeader GbriefcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003D0C0
struct ModelFileHeader GblackboxZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 128.31796, 0, 5, 0, 0};
//D:8003D0E0
struct ModelFileHeader GplastiqueZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 255.35242, 0, 3, 0, 0};
//D:8003D100
struct ModelFileHeader GvideotapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 122.69632, 0, 9, 0, 0};
//D:8003D120
struct ModelFileHeader GclipboardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 190.41742, 0, 3, 0, 0};
//D:8003D140
struct ModelFileHeader GstafflistZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 215.17534, 0, 4, 0, 0};
//D:8003D160
struct ModelFileHeader GdossierredZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 183.54231, 0, 4, 0, 0};
//D:8003D180
struct ModelFileHeader GaudiotapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 97.531075, 0, 9, 0, 0};
//D:8003D1A0
struct ModelFileHeader GdattapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 79.868584, 0, 4, 0, 0};
//D:8003D1C0
struct ModelFileHeader GplansZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 81.950996, 0, 5, 0, 0};
//D:8003D1E0
struct ModelFileHeader GspyfileZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D200
struct ModelFileHeader GblueprintsZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 125.3834, 0, 4, 0, 0};
//D:8003D220
struct ModelFileHeader GcircuitboardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 138.90285, 0, 3, 0, 0};
//D:8003D240
struct ModelFileHeader GmapZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 125.3834, 0, 4, 0, 0};
//D:8003D260
struct ModelFileHeader GspooltapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D280
struct ModelFileHeader GmicrofilmZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2A0
struct ModelFileHeader GmicrocodeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2C0
struct ModelFileHeader GlectreZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2E0
struct ModelFileHeader GmoneyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D300
struct ModelFileHeader GgoldbarZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D320
struct ModelFileHeader GheroinZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};

//FIXME File split likely
//D:8003D340
//ModelJoint 
ModelJoint dword_D_8003D340[] = {
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
ModelSkeleton weapon_gun_controller = {0xD, 0x0, dword_D_8003D340, 0x27, 0x0};

//FIXME File split likely
//D:8003D39C
s32 D_8003D39C = 0;

ModelJoint dword_D_8003D3A0[] = {
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
ModelSkeleton model_guard_character = {0x10, 0x0000, dword_D_8003D3A0, 0x2D, 0x0000};
//D:8003D40C



