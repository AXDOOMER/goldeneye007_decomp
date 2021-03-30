#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"

//D:8003C4D0
struct prop_pos_data word_D_8003C4D0[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C4D6                     .half 0
//D:8003C4D8
struct item_related model_object_standard_object = {1, 0, word_D_8003C4D0, 3, 0};

//FIXME for rest of this skelton/joint section, the extra s32 between are file split padding most likely, and should be located in source model folder
//FIXME File split likely
//D:8003C4E4
s32 D_8003C4E4 = 0;
//D:8003C4E8
s32 D_8003C4E8 = 0;
//D:8003C4EC
s32 D_8003C4EC = 0;

//D:8003C4F0
struct prop_pos_data word_D_8003C4F0[] = {
    {0x0015, 0x0000, 0x0000},
    {0x0015, 0x0001, 0x0001}
};
//D:8003C4FC
struct item_related prop_weapon_related = {2, 0, word_D_8003C4F0, 0, 0};

//FIXME File split likely
//D:8003C508
s32 D_8003C508 = 0;
//D:8003C50C
s32 D_8003C50C = 0;

//D:8003C510
struct prop_pos_data dword_D_8003C510[] = {
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
struct item_related dword_D_8003C570 = {0x10, 0x0000, dword_D_8003C510, 0x2D, 0x0000};

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
struct object_header player_gait_object = {0, &dword_D_8003C570,0,0, 4, 41.16123,0,0,0,0};

//FIXME File split likely
//D:8003C670
struct prop_pos_data dword_D_8003C670[] = {
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
struct item_related model_suit_lf_hand = {0x13, 0x0000, dword_D_8003C670, 0x2D, 0x0000};

//FIXME File split likely
//D:8003C6F0
struct prop_pos_data dword_D_8003C6F0[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0015, 0x000F, 0x000F},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003C714
struct item_related weapon_gun_standard_gun = {0x6, 0x0000, dword_D_8003C6F0, 0xF, 0x0000};

//FIXME File split likely
//D:8003C720
struct prop_pos_data dword_D_8003C720[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C728
struct item_related weapon_gun_unassigned = {0x1, 0x0000, dword_D_8003C720, 0x3, 0x0000};

//FIXME File split likely
//D:8003C734
s32 D_8003C734 = 0;
//D:8003C738
s32 D_8003C738 = 0;
//D:8003C73C
s32 D_8003C73C = 0;
//D:8003C740
struct prop_pos_data dword_D_8003C740[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012}
};
//D:8003C76C
struct item_related weapon_gun_revolver = {0x7, 0x0000, dword_D_8003C740, 0x15, 0x0000};

//FIXME File split likely
//D:8003C778
s32 D_8003C778 = 0;
//D:8003C77C
s32 D_8003C77C = 0;
//D:8003C780
struct prop_pos_data dword_D_8003C780[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0015, 0x0012, 0x0012},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003C7AC
struct item_related weapon_gun_kf7 = {0x7, 0x0000, dword_D_8003C780, 0x12, 0x0000};

//FIXME File split likely
//D:8003C7B8
s32 D_8003C7B8 = 0;
//D:8003C7BC
s32 D_8003C7BC = 0;

//D:8003C7C0
struct Gitemheader GwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xC, 0, 0};
//D:8003C7E0
struct Gitemheader GwppksilZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 438.66476, 0, 0xC, 0, 0};
//D:8003C800
struct Gitemheader Gtt33Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 438.16788, 0, 0xF, 0, 0};
//D:8003C820
struct Gitemheader GskorpianZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 390.40039, 0, 0xC, 0, 0};
//D:8003C840
struct Gitemheader Gak47Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 941.9339, 0, 0x12, 0, 0};
//D:8003C860
struct Gitemheader GuziZ_struct = {0, &weapon_gun_kf7, 0, 0x24, 5, 436.95404, 0, 0xC, 0, 0};
//D:8003C880
struct Gitemheader Gmp5kZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 499.24536, 0, 9, 0, 0};
//D:8003C8A0
struct Gitemheader Gmp5ksilZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 655.97717, 0, 9, 0, 0};
//D:8003C8C0
struct Gitemheader Gm16Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 1096.2413, 0, 8, 0, 0};
//D:8003C8E0
struct Gitemheader Gfnp90Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 460.81909, 0, 0xA, 0, 0};
//D:8003C900
struct Gitemheader G8003C900_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 238.62167, 0, 4, 0, 0};
//D:8003C920
struct Gitemheader GrugerZ_struct = {0, &weapon_gun_revolver, 0, 0x24, 6, 553.44312, 0, 0xE, 0, 0};
//D:8003C940
struct Gitemheader GgoldengunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 5, 384.92172, 0, 0xB, 0, 0};
//D:8003C960
struct Gitemheader GshotgunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 4, 919.33038, 0, 0xD, 0, 0};
//D:8003C980
struct Gitemheader GautoshotZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 840.15125, 0, 0x10, 0, 0};
//D:8003C9A0
struct Gitemheader GgrenadelaunchZ_struct = {0, &weapon_gun_revolver, 0, 0x24, 5, 768.33496, 0, 0xF, 0, 0};
//D:8003C9C0
struct Gitemheader GspectreZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 598.42865, 0, 0xB, 0, 0};
//D:8003C9E0
struct Gitemheader GlaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 442.81848, 0, 0xD, 0, 0};
//D:8003CA00
struct Gitemheader GrocketlaunchZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 566.51208, 0, 0xA, 0, 0};
//D:8003CA20
struct Gitemheader GknifeZ_header = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 376.97263, 0, 9, 0, 0};
//D:8003CA40
struct Gitemheader GthrowknifeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 373.31387, 0, 9, 0, 0};
//D:8003CA60
struct Gitemheader GtaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 182.78622, 0, 0x11, 0, 0};
//D:8003CA80
struct Gitemheader GremotemineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 50.999378, 0, 3, 0, 0};
//D:8003CAA0
struct Gitemheader GproximitymineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 51.00029, 0, 3, 0, 0};
//D:8003CAC0
struct Gitemheader GtimedmineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 49.368877, 0, 4, 0, 0};
//D:8003CAE0
struct Gitemheader GtriggerZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003CB00
struct Gitemheader GgrenadeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 427.27081, 0, 5, 0, 0};
//D:8003CB20
struct Gitemheader GfistZ_header = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 243.84764, 0, 0xE, 0, 0};
//D:8003CB40
struct Gitemheader GsniperrifleZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 808.03253, 0, 7, 0, 0};
//D:8003CB60
struct Gitemheader GcartridgeZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 14.128822, 0, 2, 0, 0};
//D:8003CB80
struct Gitemheader GcartrifleZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBA0
struct Gitemheader GcartblueZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBC0
struct Gitemheader GcartshellZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 29.8451, 0, 2, 0, 0};
//D:8003CBE0
struct Gitemheader GjoypadZ_struct = {0, &weapon_gun_controller, 0, 0xE, 0xD, 523.96826, 0, 4, 0, 0};
//D:8003CC00
struct Gitemheader G8003CC00_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC20
struct Gitemheader G8003CC20_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC40
struct Gitemheader GbombcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CC60
struct Gitemheader GflarepistolZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC80
struct Gitemheader GpitongunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCA0
struct Gitemheader G8003CCA0_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCC0
struct Gitemheader GsilverwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CCE0
struct Gitemheader GgoldwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CD00
struct Gitemheader G8003CD00_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD20
struct Gitemheader GbungeeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD40
struct Gitemheader GdoordecoderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 60.850407, 0, 0x10, 0, 0};
//D:8003CD60
struct Gitemheader GbombdefuserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 84.370705, 0, 0xC, 0, 0};
//D:8003CD80
struct Gitemheader GbugdetectorZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CDA0
struct Gitemheader GsafecrackercaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CDC0
struct Gitemheader GcameraZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 52.775627, 0, 0xB, 0, 0};
//D:8003CDE0
struct Gitemheader GlockexploderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE00
struct Gitemheader GdoorexploderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE20
struct Gitemheader GkeyanalysercaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE40
struct Gitemheader GweaponcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE60
struct Gitemheader GkeycardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 123.088844, 0, 2, 0, 0};
//D:8003CE80
struct Gitemheader GkeyyaleZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 414.25156, 0, 1, 0, 0};
//D:8003CEA0
struct Gitemheader GkeyboltZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 759.26581, 0, 1, 0, 0};
//D:8003CEC0
struct Gitemheader GbugZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 106.2163, 0, 6, 0, 0};
//D:8003CEE0
struct Gitemheader GmicrocameraZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 70.039436, 0, 7, 0, 0};
//D:8003CF00
struct Gitemheader GexplosivefloppyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 60.902443, 0, 5, 0, 0};
//D:8003CF20
struct Gitemheader GgoldeneyekeyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 98.987083, 0, 5, 0, 0};
//D:8003CF40
struct Gitemheader GpolarizedglassesZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 53.776386, 0, 2, 0, 0};
//D:8003CF60
struct Gitemheader GcreditcardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CF80
struct Gitemheader GdarkglassesZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CFA0
struct Gitemheader GwatchidentifierZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFC0
struct Gitemheader GwatchcommunicatorZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFE0
struct Gitemheader GwatchlaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003D000
struct Gitemheader GwatchgeigercounterZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D020
struct Gitemheader GwatchmagnetrepelZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D040
struct Gitemheader GwatchmagnetattractZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1D, 3, 384.9288, 0, 9, 0, 0};
//D:8003D060
struct Gitemheader GgaskeyringZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 111.59859, 0, 9, 0, 0};
//D:8003D080
struct Gitemheader GdatathiefZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 119.78231, 0, 3, 0, 0};
//D:8003D0A0
struct Gitemheader GbriefcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003D0C0
struct Gitemheader GblackboxZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 128.31796, 0, 5, 0, 0};
//D:8003D0E0
struct Gitemheader GplastiqueZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 255.35242, 0, 3, 0, 0};
//D:8003D100
struct Gitemheader GvideotapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 122.69632, 0, 9, 0, 0};
//D:8003D120
struct Gitemheader GclipboardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 190.41742, 0, 3, 0, 0};
//D:8003D140
struct Gitemheader GstafflistZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 215.17534, 0, 4, 0, 0};
//D:8003D160
struct Gitemheader GdossierredZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 183.54231, 0, 4, 0, 0};
//D:8003D180
struct Gitemheader GaudiotapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 97.531075, 0, 9, 0, 0};
//D:8003D1A0
struct Gitemheader GdattapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 79.868584, 0, 4, 0, 0};
//D:8003D1C0
struct Gitemheader GplansZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 81.950996, 0, 5, 0, 0};
//D:8003D1E0
struct Gitemheader GspyfileZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D200
struct Gitemheader GblueprintsZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 125.3834, 0, 4, 0, 0};
//D:8003D220
struct Gitemheader GcircuitboardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 138.90285, 0, 3, 0, 0};
//D:8003D240
struct Gitemheader GmapZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 125.3834, 0, 4, 0, 0};
//D:8003D260
struct Gitemheader GspooltapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D280
struct Gitemheader GmicrofilmZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2A0
struct Gitemheader GmicrocodeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2C0
struct Gitemheader GlectreZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2E0
struct Gitemheader GmoneyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D300
struct Gitemheader GgoldbarZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D320
struct Gitemheader GheroinZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};

//FIXME File split likely
//D:8003D340
u32 dword_D_8003D340[] = {0x20000,         2,   0x30003,   0x20006,
                          0x60002,   0x90009,   0x2000C,   0xC0002,
                          0xF000F,   0x20012,  0x120002,  0x150015,
                          0x20018,  0x180002,  0x1B001B,   0x2001E,
                          0x1E0002,  0x210021,   0x20024,  0x240000};


//D:8003D390
struct model_data weapon_gun_controller = {0xD0000, dword_D_8003D340, 0x270000};

//FIXME File split likely
//D:8003D39C
s32 D_8003D39C = 0;

u32 dword_D_8003D3A0[] = {0x4010000,         2,         0,   0x20003,
                          0x30002,   0x60006,   0x20009,   0xC0002,
                          0xC0009,   0x2000F,  0x120002,  0x12000F,
                          0x20015,  0x180002,  0x180015,   0x2001B,
                          0x1E0002,  0x1E001B,   0x20021,  0x240002,
                          0x240021,   0x20027,  0x2A0002,  0x2A0027};


//D:8003D400
     struct model_data model_guard_character = {0x100000, dword_D_8003D3A0, 0x2D0000};
//D:8003D40C

//FIXME File split likely
s32 D_8003D40C = 0;

//D:8003D410
struct object_header CcamguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xE, 0, 0};
//D:8003D430
struct object_header CgreyguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1292.6892, 0, 0xD, 0, 0};
//D:8003D450
struct object_header ColiveguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0x10, 0, 0};
//D:8003D470
struct object_header CrusguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xD, 0, 0};
//D:8003D490
struct object_header CtrevguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x12, 0, 0};
//D:8003D4B0
struct object_header CborisZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1223.1553, 0, 0x15, 0, 0};
//D:8003D4D0
struct object_header CorumovZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1347.004, 0, 0x15, 0, 0};
//D:8003D4F0
struct object_header CtrevelyanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1263.2534, 0, 0x10, 0, 0};
//D:8003D510
struct object_header CboilertrevZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1263.2534, 0, 0x10, 0, 0};
//D:8003D530
struct object_header CvalentinZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1208.6277, 0, 0x10, 0, 0};
//D:8003D550
struct object_header CxeniaZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1285.4487, 0, 0x13, 0, 0};
//D:8003D570
struct object_header CbaronsamediZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.5995, 0, 0x19, 0, 0};
//D:8003D590
struct object_header CjawsZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1550.059, 0, 0x14, 0, 0};
//D:8003D5B0
struct object_header CmaydayZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.657, 0, 0x10, 0, 0};
//D:8003D5D0
struct object_header CoddjobZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1082.4603, 0, 0x12, 0, 0};
//D:8003D5F0
struct object_header CnatalyaZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1226.1493, 0, 0x10, 0, 0};
//D:8003D610
struct object_header CarmourguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x11, 0, 0};
//D:8003D630
struct object_header CcommguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xF, 0, 0};
//D:8003D650
struct object_header CgreatguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1283.0787, 0, 0xB, 0, 0};
//D:8003D670
struct object_header CnavyguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xF, 0, 0};
//D:8003D690
struct object_header CsnowguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1261.1731, 0, 0x11, 0, 0};
//D:8003D6B0
struct object_header CbluewomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1148.2167, 0, 0xD, 0, 0};
//D:8003D6D0
struct object_header CfattechwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1149.4025, 0, 0xC, 0, 0};
//D:8003D6F0
struct object_header CtechwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1158.2109, 0, 0xC, 0, 0};
//D:8003D710
struct object_header CjeanwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1124.0725, 0, 0xF, 0, 0};
//D:8003D730
struct object_header CgreymanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1293.0195, 0, 0xF, 0, 0};
//D:8003D750
struct object_header CbluemanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xF, 0, 0};
//D:8003D770
struct object_header CredmanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xF, 0, 0};
//D:8003D790
struct object_header CcardimanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xE, 0, 0};
//D:8003D7B0
struct object_header CcheckmanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0x10, 0, 0};
//D:8003D7D0
struct object_header CtechmanZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1292.6892, 0, 0xC, 0, 0};
//D:8003D7F0
struct object_header CpilotZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x18, 0, 0};
//D:8003D810
struct object_header Cgreatguard2Z_struct = {0, &model_guard_character, 0, 7, 0x14, 1283.0787, 0, 0x10, 0, 0};
//D:8003D830
struct object_header CbluecamguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xE, 0, 0};
//D:8003D850
struct object_header CmoonguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0xD, 0, 0};
//D:8003D870
struct object_header CmoonfemaleZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1124.0725, 0, 0xB, 0, 0};
//D:8003D890
struct object_header CboilerbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1273.6262, 0, 0xD, 0, 0};
//D:8003D8B0
struct object_header CsuitbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.3391, 0, 0xE, 0, 0};
//D:8003D8D0
struct object_header CtimberbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1282.7715, 0, 0x10, 0, 0};
//D:8003D8F0
struct object_header CsnowbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1299.1359, 0, 0xE, 0, 0};
//D:8003D910
struct object_header CdjbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1285.0543, 0, 0xD, 0, 0};
//D:8003D930
struct object_header Csuit_lf_handz_struct = {0, &model_suit_lf_hand, 0, 0xA, 9, 12231.949, 0, 0x16, 0, 0};
//D:8003D950
struct object_header CheadkarlZ_struct = {0, NULL, 0, 2, 1, 218.15375, 0, 6, 0, 0};
//D:8003D970
struct object_header CheadalanZ_struct = {0, NULL, 0, 2, 1, 215.03685, 0, 4, 0, 0};
//D:8003D990
struct object_header CheadpeteZ_struct = {0, NULL, 0, 2, 1, 216.28949, 0, 4, 0, 0};
//D:8003D9B0
struct object_header CheadmartinZ_struct = {0, NULL, 0, 2, 1, 222.34796, 0, 6, 0, 0};
//D:8003D9D0
struct object_header stru_D_8003D9D0 = {0, NULL, 0, 2, 1, 220.2446, 0, 5, 0, 0};
//D:8003D9F0
struct object_header stru_D_8003D9F0 = {0, NULL, 0, 2, 1, 201.51955, 0, 5, 0, 0};
//D:8003DA10
struct object_header stru_D_8003DA10 = {0, NULL, 0, 2, 1, 212.62949, 0, 5, 0, 0};
//D:8003DA30
struct object_header stru_D_8003DA30 = {0, NULL, 0, 2, 1, 218.35564, 0, 4, 0, 0};
//D:8003DA50
struct object_header stru_D_8003DA50 = {0, NULL, 0, 2, 1, 192.53412, 0, 4, 0, 0};
//D:8003DA70
struct object_header stru_D_8003DA70 = {0, NULL, 0, 2, 1, 218.35564, 0, 4, 0, 0};
//D:8003DA90
struct object_header stru_D_8003DA90 = {0, NULL, 0, 2, 1, 227.52234, 0, 4, 0, 0};
//D:8003DAB0
struct object_header stru_D_8003DAB0 = {0, NULL, 0, 2, 1, 228.29831, 0, 4, 0, 0};
//D:8003DAD0
struct object_header stru_D_8003DAD0 = {0, NULL, 0, 2, 1, 235.64778, 0, 6, 0, 0};
//D:8003DAF0
struct object_header stru_D_8003DAF0 = {0, NULL, 0, 2, 1, 218.35564, 0, 5, 0, 0};
//D:8003DB10
struct object_header stru_D_8003DB10 = {0, NULL, 0, 2, 1, 240.50017, 0, 4, 0, 0};
//D:8003DB30
struct object_header stru_D_8003DB30 = {0, NULL, 0, 2, 1, 234.83342, 0, 4, 0, 0};
//D:8003DB50
struct object_header stru_D_8003DB50 = {0, NULL, 0, 2, 1, 228.24614, 0, 4, 0, 0};
//D:8003DB70
struct object_header stru_D_8003DB70 = {0, NULL, 0, 2, 1, 228.55029, 0, 4, 0, 0};
//D:8003DB90
struct object_header stru_D_8003DB90 = {0, NULL, 0, 2, 1, 212.62949, 0, 2, 0, 0};
//D:8003DBB0
struct object_header stru_D_8003DBB0 = {0, NULL, 0, 2, 1, 219.82707, 0, 6, 0, 0};
//D:8003DBD0
struct object_header stru_D_8003DBD0 = {0, NULL, 0, 2, 1, 193.20615, 0, 5, 0, 0};
//D:8003DBF0
struct object_header stru_D_8003DBF0 = {0, NULL, 0, 2, 1, 235.64778, 0, 4, 0, 0};
//D:8003DC10
struct object_header stru_D_8003DC10 = {0, NULL, 0, 2, 1, 223.18559, 0, 4, 0, 0};
//D:8003DC30
struct object_header stru_D_8003DC30 = {0, NULL, 0, 2, 1, 218.35564, 0, 5, 0, 0};
//D:8003DC50
struct object_header stru_D_8003DC50 = {0, NULL, 0, 2, 1, 193.20615, 0, 4, 0, 0};
//D:8003DC70
struct object_header stru_D_8003DC70 = {0, NULL, 0, 2, 1, 235.64778, 0, 5, 0, 0};
//D:8003DC90
struct object_header stru_D_8003DC90 = {0, NULL, 0, 2, 1, 193.20615, 0, 3, 0, 0};
//D:8003DCB0
struct object_header stru_D_8003DCB0 = {0, NULL, 0, 2, 1, 224.83139, 0, 3, 0, 0};
//D:8003DCD0
struct object_header stru_D_8003DCD0 = {0, NULL, 0, 2, 1, 219.97256, 0, 3, 0, 0};
//D:8003DCF0
struct object_header stru_D_8003DCF0 = {0, NULL, 0, 2, 1, 203.44904, 0, 3, 0, 0};
//D:8003DD10
struct object_header stru_D_8003DD10 = {0, NULL, 0, 2, 1, 196.83067, 0, 3, 0, 0};
//D:8003DD30
struct object_header stru_D_8003DD30 = {0, NULL, 0, 2, 1, 176.67717, 0, 1, 0, 0};
//D:8003DD50
struct object_header stru_D_8003DD50 = {0, NULL, 0, 2, 1, 190.61967, 0, 4, 0, 0};
//D:8003DD70
struct object_header CheadbrosnansuitZ_struct = {0, NULL, 0, 2, 1, 212.45657, 0, 5, 0, 0};
//D:8003DD90
struct object_header CheadbrosnantimberZ_struct = {0, NULL, 0, 2, 1, 179.28358, 0, 4, 0, 0};
//D:8003DDB0
struct object_header CheadbrosnansnowZ_struct = {0, NULL, 0, 2, 1, 225.0605, 0, 6, 0, 0};
//D:8003DDD0
struct object_header CheadbrosnanZ_struct = {0, NULL, 0, 2, 1, 189.48112, 0, 5, 0, 0};
//D:8003DDF0
struct object_header CspicebondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1208.6448, 0, 0x11, 0, 0};

