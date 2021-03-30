#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"

//D:800375D0
struct ModelFileHeader alarm1_header = {0, &skeleton_standard_object, 0, 0, 1, 304.6402, 0, 2, 0, 0};
//D:800375F0
struct ModelFileHeader alarm2_header = {0, &skeleton_standard_object, 0, 0, 1, 208.22205, 0, 3, 0, 0};
//D:80037610
struct ModelFileHeader explosionbit_header = {0, &skeleton_standard_object, 0, 0, 1, 208.22205, 0, 0, 0, 0};
//D:80037630
struct ModelFileHeader ammo_crate1_header = {0, &skeleton_standard_object, 0, 0, 1, 691.83429, 0, 3, 0, 0};
//D:80037650
struct ModelFileHeader ammo_crate2_header = {0, &skeleton_standard_object, 0, 0, 1, 691.83429, 0, 4, 0, 0};
//D:80037670
struct ModelFileHeader ammo_crate3_header = {0, &skeleton_standard_object, 0, 0, 1, 691.83429, 0, 4, 0, 0};
//D:80037690
struct ModelFileHeader ammo_crate4_header = {0, &skeleton_standard_object, 0, 0, 1, 691.83429, 0, 5, 0, 0};
//D:800376B0
struct ModelFileHeader ammo_crate5_header = {0, &skeleton_standard_object, 0, 0, 1, 691.83429, 0, 5, 0, 0};
//D:800376D0
struct ModelFileHeader bin1_header = {0, &skeleton_standard_object, 0, 0, 1, 3027.6262,0, 2, 0, 0};
//D:800376F0
struct ModelFileHeader blotter1_header = {0, &skeleton_standard_object, 0, 0, 1, 432.46707, 0, 1, 0, 0};
//D:80037710
struct ModelFileHeader book1_header = {0, &skeleton_standard_object, 0, 0, 1, 171.37482, 0, 2, 0, 0};
//D:80037730
struct ModelFileHeader bookshelf1_header = {0, &skeleton_standard_object, 0, 0, 1, 1166.7578, 0, 0xD, 0, 0};
//D:80037750
struct ModelFileHeader bridge_console1a_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:80037770
struct ModelFileHeader bridge_console1b_header = {0, &skeleton_console_one_screen, 0, 0x1, 0x1, 788.03992, 0, 0x10, 0, 0};
//D:80037790
struct ModelFileHeader bridge_console2a_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:800377B0
struct ModelFileHeader bridge_console2b_header = {0, &skeleton_standard_object, 0, 0, 1, 788.03992, 0, 0xF, 0, 0};
//D:800377D0
struct ModelFileHeader bridge_console3a_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:800377F0
struct ModelFileHeader bridge_console3b_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 788.03992, 0, 0x10, 0, 0};
//D:80037810
struct ModelFileHeader card_box1_header = {0, &skeleton_standard_object, 0, 0, 1, 727.4613, 0, 5, 0, 0};
//D:80037830
struct ModelFileHeader card_box2_header = {0, &skeleton_standard_object, 0, 0, 1, 727.4613, 0, 6, 0, 0};
//D:80037850
struct ModelFileHeader card_box3_header = {0, &skeleton_standard_object, 0, 0, 1, 727.4613, 0, 5, 0, 0};
//D:80037870
struct ModelFileHeader card_box4_lg_header = {0, &skeleton_standard_object, 0, 0, 1, 800.2074, 0, 4, 0, 0};
//D:80037890
struct ModelFileHeader card_box5_lg_header = {0, &skeleton_standard_object, 0, 0, 1, 800.2074, 0, 5, 0, 0};
//D:800378B0
struct ModelFileHeader card_box6_lg_header = {0, &skeleton_standard_object, 0, 0, 1, 800.2074, 0, 5, 0, 0};
//D:800378D0
struct ModelFileHeader cctv_header = {0, &skeleton_cctv, 0, 0x4, 0x2, 558.90094, 0, 6, 0, 0};
//D:800378F0
struct ModelFileHeader console1_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037910
struct ModelFileHeader console2_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037930
struct ModelFileHeader console3_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037950
struct ModelFileHeader console_seva_header = {0, &skeleton_standard_object, 0, 0, 1, 994.23688, 0, 0xE, 0, 0};
//D:80037970
struct ModelFileHeader console_sevb_header = {0, &skeleton_console_one_screen, 0, 0x1, 0x1, 994.23688, 0, 0xB, 0, 0};
//D:80037990
struct ModelFileHeader console_sevc_header = {0, &skeleton_standard_object, 0, 0, 1, 994.23688, 0, 0xF, 0, 0};
//D:800379B0
struct ModelFileHeader console_sevd_header = {0, &skeleton_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:800379D0
struct ModelFileHeader console_sev2a_header = {0, &skeleton_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:800379F0
struct ModelFileHeader console_sev2b_header = {0, &skeleton_console_one_screen, 0, 0x1, 0x1, 994.23688, 0, 0xD, 0, 0};
//D:80037A10
struct ModelFileHeader console_sev2c_header = {0, &skeleton_standard_object, 0, 0, 1, 994.23688, 0, 0xF, 0, 0};
//D:80037A30
struct ModelFileHeader console_sev2d_header = {0, &skeleton_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A50
struct ModelFileHeader console_sev_GEa_header = {0, &skeleton_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A70
struct ModelFileHeader console_sev_GEb_header = {0, &skeleton_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A90
struct ModelFileHeader desk1_header = {0, &skeleton_standard_object, 0, 0, 1, 957.18225, 0, 3, 0, 0};
//D:80037AB0
struct ModelFileHeader desk2_header = {0, &skeleton_standard_object, 0, 0, 1, 957.18225, 0, 3, 0, 0};
//D:80037AD0
struct ModelFileHeader desk_lamp2_header = {0, &skeleton_standard_object, 0, 0, 1, 804.59833, 0, 4, 0, 0};
//D:80037AF0
struct ModelFileHeader disc_reader_header = {0, &skeleton_standard_object, 0, 0, 1, 214.33035, 0, 6, 0, 0};
//D:80037B10
struct ModelFileHeader disk_drive1_header = {0, &skeleton_standard_object, 0, 0, 1, 191.85779, 0, 4, 0, 0};
//D:80037B30
struct ModelFileHeader filing_cabinet1_header = {0, &skeleton_standard_object, 0, 0, 1, 1055.5693, 0, 2, 0, 0};
//D:80037B50
struct ModelFileHeader jerry_can1_header = {0, &skeleton_standard_object, 0, 0, 1, 366.61932, 0, 4, 0, 0};
//D:80037B70
struct ModelFileHeader keyboard1_header = {0, &skeleton_standard_object, 0, 0, 1, 278.23227, 0, 2, 0, 0};
//D:80037B90
struct ModelFileHeader kit_units1_header = {0, &skeleton_standard_object, 0, 0, 1, 1661.4763, 0, 4, 0, 0};
//D:80037BB0
struct ModelFileHeader letter_tray1_header = {0, &skeleton_standard_object, 0, 0, 1, 252.06836, 0, 1, 0, 0};
//D:80037BD0
struct ModelFileHeader mainframe1_header = {0, &skeleton_standard_object, 0, 0, 1, 1119.4073, 0, 7, 0, 0};
//D:80037BF0
struct ModelFileHeader mainframe2_header = {0, &skeleton_standard_object, 0, 0, 1, 1119.4073, 0, 7, 0, 0};
//D:80037C10
struct ModelFileHeader metal_chair1_header = {0, &skeleton_standard_object, 0, 0, 1, 639.18097, 0, 2, 0, 0};
//D:80037C30
struct ModelFileHeader metal_crate1_header = {0, &skeleton_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037C50
struct ModelFileHeader metal_crate2_header = {0, &skeleton_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037C70
struct ModelFileHeader metal_crate3_header = {0, &skeleton_standard_object, 0, 0, 1, 1010.363, 0, 2, 0, 0};
//D:80037C90
struct ModelFileHeader metal_crate4_header = {0, &skeleton_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037CB0
struct ModelFileHeader missile_rack_header = {0, &skeleton_standard_object, 0, 0, 1, 964.16296, 0, 4, 0, 0};
//D:80037CD0
struct ModelFileHeader missile_rack2_header = {0, &skeleton_standard_object, 0, 0, 1, 1148.4724, 0, 4, 0, 0};
//D:80037CF0
struct ModelFileHeader oil_drum1_header = {0, &skeleton_standard_object, 0, 0, 1, 745.45892, 0, 2, 0, 0};
//D:80037D10
struct ModelFileHeader oil_drum2_header = {0, &skeleton_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037D30
struct ModelFileHeader oil_drum3_header = {0, &skeleton_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037D50
struct ModelFileHeader oil_drum5_header = {0, &skeleton_standard_object, 0, 0, 1, 745.45892, 0, 3, 0, 0};
//D:80037D70
struct ModelFileHeader oil_drum6_header = {0, &skeleton_standard_object, 0, 0, 1, 745.45892, 0, 3, 0, 0};
//D:80037D90
struct ModelFileHeader oil_drum7_header = {0, &skeleton_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037DB0
struct ModelFileHeader padlock_header = {0, &skeleton_standard_object, 0, 0, 1, 225.64145, 0, 4, 0, 0};
//D:80037DD0
struct ModelFileHeader phone1_header = {0, &skeleton_standard_object, 0, 0, 1, 166.03481, 0, 2, 0, 0};
//D:80037DF0
struct ModelFileHeader radio_unit1_header = {0, &skeleton_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E10
struct ModelFileHeader radio_unit2_header = {0, &skeleton_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E30
struct ModelFileHeader radio_unit3_header = {0, &skeleton_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E50
struct ModelFileHeader radio_unit4_header = {0, &skeleton_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E70
struct ModelFileHeader sat1_reflect_header = {0, &skeleton_standard_object, 0, 0, 1, 5185.9409, 0, 0xD, 0, 0};
//D:80037E90
struct ModelFileHeader satdish_header = {0, &skeleton_standard_object, 0, 0, 1, 2437.468, 0, 2, 0, 0};
//D:80037EB0
struct ModelFileHeader satbox_header = {0, &skeleton_standard_object, 0, 0, 1, 89.935875, 0, 1, 0, 0};
//D:80037ED0
struct ModelFileHeader stool1_header = {0, &skeleton_standard_object, 0, 0, 1, 353.11398, 0, 2, 0, 0};
//D:80037EF0
struct ModelFileHeader swivel_chair1_header = {0, &skeleton_standard_object, 0, 0, 1, 581.16394, 0, 3, 0, 0};
//D:80037F10
struct ModelFileHeader torpedo_rack_header = {0, &skeleton_standard_object, 0, 0, 1, 765.61725, 0, 3, 0, 0};
//D:80037F30
struct ModelFileHeader tv1_header = {0, &skeleton_console_one_screen, 0, 0x1, 0x1, 347.0235, 0, 5, 0, 0};
//D:80037F50
struct ModelFileHeader tv_holder_header = {0, &skeleton_tv_holder, 0, 0x4, 0x5, 1352.4841, 0, 2, 0, 0};
//D:80037F70
struct ModelFileHeader tvscreen_header = {0, &skeleton_console_one_screen, 0, 0x1, 0x1, 211.74477, 0, 1, 0, 0};
//D:80037F90
struct ModelFileHeader tv4screen_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 211.74477, 0, 1, 0, 0};
//D:80037FB0
struct ModelFileHeader wood_lg_crate1_header = {0, &skeleton_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037FD0
struct ModelFileHeader wood_lg_crate2_header = {0, &skeleton_standard_object, 0, 0, 1, 1010.363, 0, 2, 0, 0};
//D:80037FF0
struct ModelFileHeader wood_md_crate3_header = {0, &skeleton_standard_object, 0, 0, 1, 909.32666, 0, 2, 0, 0};
//D:80038010
struct ModelFileHeader wood_sm_crate4_header = {0, &skeleton_standard_object, 0, 0, 1, 727.4613, 0, 3, 0, 0};
//D:80038030
struct ModelFileHeader wood_sm_crate5_header = {0, &skeleton_standard_object, 0, 0, 1, 727.4613, 0, 4, 0, 0};
//D:80038050
struct ModelFileHeader wood_sm_crate6_header = {0, &skeleton_standard_object, 0, 0, 1, 727.4613, 0, 4, 0, 0};
//D:80038070
struct ModelFileHeader wooden_table1_header = {0, &skeleton_standard_object, 0, 0, 1, 1095.1365, 0, 2, 0, 0};
//D:80038090
struct ModelFileHeader swipe_card2_header = {0, &skeleton_standard_object, 0, 0, 1, 123.088844, 0, 2, 0, 0};
//D:800380B0
struct ModelFileHeader borg_crate_header = {0, &skeleton_standard_object, 0, 0, 1, 1010.363, 0, 1, 0, 0};
//D:800380D0
struct ModelFileHeader boxes4x4_header = {0, &skeleton_standard_object, 0, 0, 1, 2424.8711, 0, 7, 0, 0};
//D:800380F0
struct ModelFileHeader boxes3x4_header = {0, &skeleton_standard_object, 0, 0, 1, 2241.0935, 0, 6, 0, 0};
//D:80038110
struct ModelFileHeader boxes2x4_header = {0, &skeleton_standard_object, 0, 0, 1, 2100.0, 0, 6, 0, 0};
//D:80038130
struct ModelFileHeader sec_panel_header = {0, &skeleton_standard_object, 0, 0, 1, 1567.2454, 0, 3, 0, 0};
//D:80038150
struct ModelFileHeader ICBM_nose_header = {0, &skeleton_standard_object, 0, 0, 1, 2782.7126, 0, 8, 0, 0};
//D:80038170
struct ModelFileHeader ICBM_header = {0, &skeleton_standard_object, 0, 0, 1, 14790.535, 0, 0xE, 0, 0};
//D:80038190
struct ModelFileHeader tuning_console1_header = {0, &skeleton_console_one_screen, 0, 0x1, 0x1, 1139.5872, 0, 0xE, 0, 0};
//D:800381B0
struct ModelFileHeader desk_arecibo1_header = {0, &skeleton_standard_object, 0, 0, 1, 1829.1477, 0, 3, 0, 0};
//D:800381D0
struct ModelFileHeader locker3_header = {0, &skeleton_standard_object, 0, 0, 1, 916.99805, 0, 3, 0, 0};
//D:800381F0
struct ModelFileHeader locker4_header = {0, &skeleton_standard_object, 0, 0, 1, 916.99805, 0, 3, 0, 0};
//D:80038210
struct ModelFileHeader roofgun_header = {0, &skeleton_rotating_stuff, 0, 0x8, 0x5, 1910.908, 0, 0xE, 0, 0};
//D:80038230
struct ModelFileHeader dest_engine_header = {0, &skeleton_standard_object, 0, 0, 1, 6459.439, 0, 0xA, 0, 0};
//D:80038250
struct ModelFileHeader dest_exocet_header = {0, &skeleton_standard_object, 0, 0, 1, 1644.8435, 0, 8, 0, 0};
//D:80038270
struct ModelFileHeader dest_gun_header = {0, &skeleton_standard_object, 0, 0, 1, 2124.0735, 0, 5, 0, 0};
//D:80038290
struct ModelFileHeader dest_harpoon_header = {0, &skeleton_standard_object, 0, 0, 1, 1798.7655, 0, 5, 0, 0};
//D:800382B0
struct ModelFileHeader dest_seawolf_header = {0, &skeleton_standard_object, 0, 0, 1, 2282.0623, 0, 0xA, 0, 0};
//D:800382D0
struct ModelFileHeader window_header = {0, &skeleton_standard_object, 0, 0, 1, 423.48956, 0, 1, 0, 0};
//D:800382F0
struct ModelFileHeader window_lib_lg1_header = {0, &skeleton_standard_object, 0, 0, 1, 835.20624, 0, 1, 0, 0};
//D:80038310
struct ModelFileHeader window_lib_sm1_header = {0, &skeleton_standard_object, 0, 0, 1, 601.28625, 0, 1, 0, 0};
//D:80038330
struct ModelFileHeader window_cor11_header = {0, &skeleton_standard_object, 0, 0, 1, 414.53622, 0, 1, 0, 0};
//D:80038350
struct ModelFileHeader jungle3_tree_header = {0, &skeleton_standard_object, 0, 0, 1, 28729.467, 0, 5, 0, 0};
//D:80038370
struct ModelFileHeader palm_header = {0, &skeleton_standard_object, 0, 0, 1, 15501.406, 0, 3, 0, 0};
//D:80038390
struct ModelFileHeader palmtree_header = {0, &skeleton_standard_object, 0, 0, 1, 1781.4542, 0, 2, 0, 0};
//D:800383B0
struct ModelFileHeader plant2b_header = {0, &skeleton_standard_object, 0, 0, 1, 1252.9539, 0, 2, 0, 0};
//D:800383D0
struct ModelFileHeader labbench_header = {0, &skeleton_standard_object, 0, 0, 1, 844.09717, 0, 4, 0, 0};
//D:800383F0
struct ModelFileHeader gasbarrel_header = {0, &skeleton_standard_object, 0, 0, 1, 725.94379, 0, 2, 0, 0};
//D:80038410
struct ModelFileHeader gasbarrels_header = {0, &skeleton_standard_object, 0, 0, 1, 1174.1927, 0, 2, 0, 0};
//D:80038430
struct ModelFileHeader bodyarmour_header = {0, &skeleton_standard_object, 0, 0, 1, 246.94099, 0, 7, 0, 0};
//D:80038450
struct ModelFileHeader bodyarmourvest_header = {0, &skeleton_standard_object, 0, 0, 1, 241.82211, 0, 2, 0, 0};
//D:80038470
struct ModelFileHeader gastank_header = {0, &skeleton_standard_object, 0, 0, 1, 1130.0691, 0, 5, 0, 0};
//D:80038490
struct ModelFileHeader glassware1_header = {0, &skeleton_standard_object, 0, 0, 1, 72.111031, 0, 1, 0, 0};
//D:800384B0
struct ModelFileHeader hatchbolt_header = {0, &skeleton_standard_object, 0, 0, 1, 2236.0679, 0, 1, 0, 0};
//D:800384D0
struct ModelFileHeader brakeunit_header = {0, &skeleton_standard_object, 0, 0, 1, 801.95074, 0, 4, 0, 0};
//D:800384F0
struct ModelFileHeader ak47mag_header = {0, &skeleton_standard_object, 0, 0, 1, 107.11019, 0, 2, 0, 0};
//D:80038510
struct ModelFileHeader m16mag_header = {0, &skeleton_standard_object, 0, 0, 1, 87.934891, 0, 2, 0, 0};
//D:80038530
struct ModelFileHeader mp5kmag_header = {0, &skeleton_standard_object, 0, 0, 1, 119.547295, 0, 2, 0, 0};
//D:80038550
struct ModelFileHeader skorpionmag_header = {0, &skeleton_standard_object, 0, 0, 1, 58.428444, 0, 2, 0, 0};
//D:80038570
struct ModelFileHeader spectremag_header = {0, &skeleton_standard_object, 0, 0, 1, 99.01432, 0, 2, 0, 0};
//D:80038590
struct ModelFileHeader uzimag_header = {0, &skeleton_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:800385B0
struct ModelFileHeader silencer_header = {0, &skeleton_standard_object, 0, 0, 1, 63.915436, 0, 3, 0, 0};
//D:800385D0
struct ModelFileHeader chrextinguisher_header = {0, &skeleton_standard_object, 0, 0, 1, 425.50903, 0, 2, 0, 0};
//D:800385F0
struct ModelFileHeader boxcartridges_header = {0, &skeleton_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038610
struct ModelFileHeader fnp90mag_header = {0, &skeleton_standard_object, 0, 0, 1, 176.28201, 0, 2, 0, 0};
//D:80038630
struct ModelFileHeader goldenshells_header = {0, &skeleton_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038650
struct ModelFileHeader magnumshells_header = {0, &skeleton_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038670
struct ModelFileHeader wppkmag_header = {0, &skeleton_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:80038690
struct ModelFileHeader tt33mag_header = {0, &skeleton_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:800386B0
struct ModelFileHeader sev_door_header = {0, &skeleton_standard_object, 0, 0, 1, 1143.7695, 0, 3, 0, 0};
//D:800386D0
struct ModelFileHeader sev_door3_header = {0, &skeleton_standard_object, 0, 0, 1, 1143.5603, 0, 6, 0, 0};
//D:800386F0
struct ModelFileHeader sev_door3_wind_header = {0, &skeleton_standard_object, 0, 0, 1, 1143.5603, 0, 5, 0, 0};
//D:80038710
struct ModelFileHeader sev_door4_wind_header = {0, &skeleton_door, 0, 0x4, 0x1, 1143.5603, 0, 8, 0, 0};
//D:80038730
struct ModelFileHeader sev_trislide_header = {0, &skeleton_door, 0, 0x4, 0x1, 950.54327, 0, 2, 0, 0};
//D:80038750
struct ModelFileHeader sev_door_v1_header = {0, &skeleton_standard_object, 0, 0, 1, 1137.8739, 0, 6, 0, 0};
//D:80038770
struct ModelFileHeader steel_door1_header = {0, &skeleton_standard_object, 0, 0, 1, 1137.8739, 0, 4, 0, 0};
//D:80038790
struct ModelFileHeader steel_door2_header = {0, &skeleton_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:800387B0
struct ModelFileHeader steel_door3_header = {0, &skeleton_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:800387D0
struct ModelFileHeader silo_lift_door_header = {0, &skeleton_standard_object, 0, 0, 1, 600.71082, 0, 4, 0, 0};
//D:800387F0
struct ModelFileHeader steel_door2b_header = {0, &skeleton_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:80038810
struct ModelFileHeader door_roller1_header = {0, &skeleton_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038830
struct ModelFileHeader door_roller2_header = {0, &skeleton_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038850
struct ModelFileHeader door_roller3_header = {0, &skeleton_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038870
struct ModelFileHeader door_roller4_header = {0, &skeleton_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038890
struct ModelFileHeader door_st_arec1_header = {0, &skeleton_standard_object, 0, 0, 1, 763.03589, 0, 3, 0, 0};
//D:800388B0
struct ModelFileHeader door_st_arec2_header = {0, &skeleton_standard_object, 0, 0, 1, 763.03589, 0, 3, 0, 0};
//D:800388D0
struct ModelFileHeader door_dest1_header = {0, &skeleton_standard_object, 0, 0, 1, 461.3873, 0, 3, 0, 0};
//D:800388F0
struct ModelFileHeader door_dest2_header = {0, &skeleton_standard_object, 0, 0, 1, 461.3873, 0, 5, 0, 0};
//D:80038910
struct ModelFileHeader gas_plant_sw_do1_header = {0, &skeleton_standard_object, 0, 0, 1, 862.29706, 0, 4, 0, 0};
//D:80038930
struct ModelFileHeader gas_plant_sw2_do1_header = {0, &skeleton_standard_object, 0, 0, 1, 862.88489, 0, 2, 0, 0};
//D:80038950
struct ModelFileHeader gas_plant_sw3_do1_header = {0, &skeleton_standard_object, 0, 0, 1, 862.88489, 0, 2, 0, 0};
//D:80038970
struct ModelFileHeader gas_plant_sw4_do1_header = {0, &skeleton_standard_object, 0, 0, 1, 862.88489, 0, 1, 0, 0};
//D:80038990
struct ModelFileHeader gas_plant_met1_do1_header = {0, &skeleton_standard_object, 0, 0, 1, 862.88489, 0, 5, 0, 0};
//D:800389B0
struct ModelFileHeader gas_plant_wc_cub1_header = {0, &skeleton_standard_object, 0, 0, 1, 783.8501, 0, 3, 0, 0};
//D:800389D0
struct ModelFileHeader gasplant_clear_door_header = {0, &skeleton_door, 0, 0x4, 0x1, 1025.0952, 0, 2, 0, 0};
//D:800389F0
struct ModelFileHeader train_door_header = {0, &skeleton_standard_object, 0, 0, 1, 456.99615, 0, 3, 0, 0};
//D:80038A10
struct ModelFileHeader train_door2_header = {0, &skeleton_door, 0, 0x4, 0x1, 445.98541, 0, 3, 0, 0};
//D:80038A30
struct ModelFileHeader train_door3_header = {0, &skeleton_door, 0, 0x4, 0x1, 445.98541, 0, 4, 0, 0};
//D:80038A50
struct ModelFileHeader door_eyelid_header = {0, &skeleton_eyelid_door, 0, 0x3, 0x3, 3165.4348, 0, 3, 0, 0};
//D:80038A70
struct ModelFileHeader door_iris_header = {0, &skeleton_iris_door, 0, 0xD, 0xD, 1621.3601, 0, 5, 0, 0};
//D:80038A90
struct ModelFileHeader sevdoorwood_header = {0, &skeleton_door, 0, 0x4, 0x1, 851.62671, 0, 3, 0, 0};
//D:80038AB0
struct ModelFileHeader sevdoorwind_header = {0, &skeleton_door, 0, 0x4, 0x1, 851.62671, 0, 5, 0, 0};
//D:80038AD0
struct ModelFileHeader sevdoornowind_header = {0, &skeleton_standard_object, 0, 0, 1, 863.03766, 0, 2, 0, 0};
//D:80038AF0
struct ModelFileHeader sevdoormetslide_header = {0, &skeleton_standard_object, 0, 0, 1, 863.74707, 0, 2, 0, 0};
//D:80038B10
struct ModelFileHeader cryptdoor1a_header = {0, &skeleton_standard_object, 0, 0, 1, 502.64923, 0, 2, 0, 0};
//D:80038B30
struct ModelFileHeader cryptdoor1b_header = {0, &skeleton_standard_object, 0, 0, 1, 400.97537, 0, 2, 0, 0};
//D:80038B50
struct ModelFileHeader cryptdoor2a_header = {0, &skeleton_standard_object, 0, 0, 1, 502.64923, 0, 2, 0, 0};
//D:80038B70
struct ModelFileHeader cryptdoor2b_header = {0, &skeleton_standard_object, 0, 0, 1, 400.97537, 0, 2, 0, 0};
//D:80038B90
struct ModelFileHeader cryptdoor3_header = {0, &skeleton_standard_object, 0, 0, 1, 801.95074, 0, 3, 0, 0};
//D:80038BB0
struct ModelFileHeader cryptdoor4_header = {0, &skeleton_standard_object, 0, 0, 1, 801.95074, 0, 1, 0, 0};
//D:80038BD0
struct ModelFileHeader vertdoor_header = {0, &skeleton_standard_object, 0, 0, 1, 1997.2246, 0, 5, 0, 0};
//D:80038BF0
struct ModelFileHeader hatchdoor_header = {0, &skeleton_standard_object, 0, 0, 1, 192.1653, 0, 1, 0, 0};
//D:80038C10
struct ModelFileHeader damgatedoor_header = {0, &skeleton_standard_object, 0, 0, 1, 308.36456, 0, 3, 0, 0};
//D:80038C30
struct ModelFileHeader damtundoor_header = {0, &skeleton_standard_object, 0, 0, 1, 127.89996, 0, 4, 0, 0};
//D:80038C50
struct ModelFileHeader damchaindoor_header = {0, &skeleton_standard_object, 0, 0, 1, 171.36655, 0, 2, 0, 0};
//D:80038C70
struct ModelFileHeader silotopdoor_header = {0, &skeleton_standard_object, 0, 0, 1, 2675.3958, 0, 5, 0, 0};
//D:80038C90
struct ModelFileHeader doorprison1_header = {0, &skeleton_standard_object, 0, 0, 1, 1062.0833, 0, 1, 0, 0};
//D:80038CB0
struct ModelFileHeader doorstatgate_header = {0, &skeleton_standard_object, 0, 0, 1, 1503.9503, 0, 3, 0, 0};
//D:80038CD0
struct ModelFileHeader chrkalash_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 403.53766, 0, 8, 0, 0};
//D:80038CF0
struct ModelFileHeader chrgrenadelaunch_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 422.48355, 0, 7, 0, 0};
//D:80038D10
struct ModelFileHeader chrknife_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 245.14619, 0, 2, 0, 0};
//D:80038D30
struct ModelFileHeader chrlaser_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x2, 444.66241, 0, 8, 0, 0};
//D:80038D50
struct ModelFileHeader chrm16_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x2, 964.01367, 0, 6, 0, 0};
//D:80038D70
struct ModelFileHeader chrmp5k_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 277.32227, 0, 9, 0, 0};
//D:80038D90
struct ModelFileHeader chrruger_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 246.72643, 0, 5, 0, 0};
//D:80038DB0
struct ModelFileHeader chrwppk_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 125.79879, 0, 5, 0, 0};
//D:80038DD0
struct ModelFileHeader chrshotgun_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 488.88385, 0, 8, 0, 0};
//D:80038DF0
struct ModelFileHeader chrskorpion_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 183.37708, 0, 7, 0, 0};
//D:80038E10
struct ModelFileHeader chrspectre_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 351.26923, 0, 6, 0, 0};
//D:80038E30
struct ModelFileHeader chruzi_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 265.11813, 0, 7, 0, 0};
//D:80038E50
struct ModelFileHeader chrgrenade_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 118.18749, 0, 2, 0, 0};
//D:80038E70
struct ModelFileHeader chrfnp90_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x2, 470.04633, 0, 7, 0, 0};
//D:80038E90
struct ModelFileHeader chrbriefcase_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80038EB0
struct ModelFileHeader chrremotemine_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 87.434036, 0, 2, 0, 0};
//D:80038ED0
struct ModelFileHeader chrproximitymine_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 87.196609, 0, 2, 0, 0};
//D:80038EF0
struct ModelFileHeader chrtimedmine_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 87.245888, 0, 3, 0, 0};
//D:80038F10
struct ModelFileHeader chrrocket_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 342.8634, 0, 3, 0, 0};
//D:80038F30
struct ModelFileHeader chrgrenaderound_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 96.976593, 0, 1, 0, 0};
//D:80038F50
struct ModelFileHeader chrwppksil_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 219.44571, 0, 6, 0, 0};
//D:80038F70
struct ModelFileHeader chrtt33_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 142.11539, 0, 5, 0, 0};
//D:80038F90
struct ModelFileHeader chrmp5ksil_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 406.18033, 0, 0xA, 0, 0};
//D:80038FB0
struct ModelFileHeader chrautoshot_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 375.50247, 0, 8, 0, 0};
//D:80038FD0
struct ModelFileHeader chrgolden_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 157.98299, 0, 2, 0, 0};
//D:80038FF0
struct ModelFileHeader chrthrowknife_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 217.61888, 0, 2, 0, 0};
//D:80039010
struct ModelFileHeader chrsniperrifle_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 616.93939, 0, 5, 0, 0};
//D:80039030
struct ModelFileHeader chrrocketlaunch_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x2, 501.55179, 0, 6, 0, 0};
//D:80039050
struct ModelFileHeader hatfurry_header = {0, &skeleton_hat, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:80039070
struct ModelFileHeader hatfurrybrown_header = {0, &skeleton_hat, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:80039090
struct ModelFileHeader hatfurryblack_header = {0, &skeleton_hat, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:800390B0
struct ModelFileHeader hattbird_header = {0, &skeleton_hat, 0, 0, 1, 114.45274, 0, 1, 0, 0};
//D:800390D0
struct ModelFileHeader hattbirdbrown_header = {0, &skeleton_hat, 0, 0, 1, 122.7013, 0, 1, 0, 0};
//D:800390F0
struct ModelFileHeader hathelmet_header = {0, &skeleton_hat, 0, 0, 1, 163.84476, 0, 1, 0, 0};
//D:80039110
struct ModelFileHeader hathelmetgrey_header = {0, &skeleton_hat, 0, 0, 1, 163.84476, 0, 1, 0, 0};
//D:80039130
struct ModelFileHeader hatmoon_header = {0, &skeleton_hat, 0, 0, 1, 138.25751, 0, 2, 0, 0};
//D:80039150
struct ModelFileHeader hatberet_header = {0, &skeleton_hat, 0, 0, 1, 116.16043, 0, 1, 0, 0};
//D:80039170
struct ModelFileHeader hatberetblue_header = {0, &skeleton_hat, 0, 0, 1, 116.16043, 0, 2, 0, 0};
//D:80039190
struct ModelFileHeader hatberetred_header = {0, &skeleton_hat, 0, 0, 1, 115.46455, 0, 2, 0, 0};
//D:800391B0
struct ModelFileHeader hatpeaked_header = {0, &skeleton_hat, 0, 0, 1, 148.39027, 0, 1, 0, 0};
//D:800391D0
struct ModelFileHeader chrwristdart_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800391F0
struct ModelFileHeader chrexplosivepen_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039210
struct ModelFileHeader chrbombcase_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039230
struct ModelFileHeader chrflarepistol_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039250
struct ModelFileHeader chrpitongun_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039270
struct ModelFileHeader chrfingergun_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039290
struct ModelFileHeader chrsilverwppk_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392B0
struct ModelFileHeader chrgoldwppk_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392D0
struct ModelFileHeader chrdynamite_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392F0
struct ModelFileHeader chrbungee_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039310
struct ModelFileHeader chrdoordecoder_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 180.27969, 0, 0x10, 0, 0};
//D:80039330
struct ModelFileHeader chrbombdefuser_header = {0, &skeleton_standard_object, 0, 0, 1, 84.370705, 0, 0xC, 0, 0};
//D:80039350
struct ModelFileHeader chrbugdetector_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039370
struct ModelFileHeader chrsafecrackercase_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039390
struct ModelFileHeader chrcamera_header = {0, &skeleton_standard_object, 0, 0, 1, 52.775627, 0, 0xB, 0, 0};
//D:800393B0
struct ModelFileHeader chrlockexploder_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800393D0
struct ModelFileHeader chrdoorexploder_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800393F0
struct ModelFileHeader chrkeyanalysercase_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039410
struct ModelFileHeader chrweaponcase_header = {0, &skeleton_standard_object, 0, 0, 1, 274.2905, 0, 5, 0, 0};
//D:80039430
struct ModelFileHeader chrkeyyale_header = {0, &skeleton_standard_object, 0, 0, 1, 82.850311, 0, 1, 0, 0};
//D:80039450
struct ModelFileHeader chrkeybolt_header = {0, &skeleton_standard_object, 0, 0, 1, 151.85315, 0, 1, 0, 0};
//D:80039470
struct ModelFileHeader chrbug_header = {0, &skeleton_standard_object, 0, 0, 1, 104.7203, 0, 6, 0, 0};
//D:80039490
struct ModelFileHeader chrmicrocamera_header = {0, &skeleton_standard_object, 0, 0, 1, 126.49728, 0, 7, 0, 0};
//D:800394B0
struct ModelFileHeader floppy_header = {0, &skeleton_standard_object, 0, 0, 1, 60.902443, 0, 5, 0, 0};
//D:800394D0
struct ModelFileHeader chrgoldeneyekey_header = {0, &skeleton_standard_object, 0, 0, 1, 98.987083, 0, 5, 0, 0};
//D:800394F0
struct ModelFileHeader chrpolarizedglasses_header = {0, &skeleton_standard_object, 0, 0, 1, 53.776386, 0, 2, 0, 0};
//D:80039510
struct ModelFileHeader chrcreditcard_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039530
struct ModelFileHeader chrdarkglasses_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039550
struct ModelFileHeader chrgaskeyring_header = {0, &skeleton_standard_object, 0, 0, 1, 111.59859, 0, 9, 0, 0};
//D:80039570
struct ModelFileHeader chrdatathief_header = {0, &skeleton_standard_object, 0, 0, 1, 119.78231, 0, 3, 0, 0};
//D:80039590
struct ModelFileHeader safe_header = {0, &skeleton_standard_object, 0, 0, 1, 1011.18744, 0, 3, 0, 0};
//D:800395B0
struct ModelFileHeader bomb_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800395D0
struct ModelFileHeader chrplans_header = {0, &skeleton_standard_object, 0, 0, 1, 384.74649, 0, 5, 0, 0};
//D:800395F0
struct ModelFileHeader chrspyfile_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039610
struct ModelFileHeader chrblueprints_header = {0, &skeleton_standard_object, 0, 0, 1, 588.65448, 0, 4, 0, 0};
//D:80039630
struct ModelFileHeader chrcircuitboard_header = {0, &skeleton_standard_object, 0, 0, 1, 138.90285, 0, 3, 0, 0};
//D:80039650
struct ModelFileHeader chrmap_header = {0, &skeleton_standard_object, 0, 0, 1, 588.65448, 0, 4, 0, 0};
//D:80039670
struct ModelFileHeader chrspooltape_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039690
struct ModelFileHeader chraudiotape_header = {0, &skeleton_standard_object, 0, 0, 1, 97.531075, 0, 9, 0, 0};
//D:800396B0
struct ModelFileHeader chrmicrofilm_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800396D0
struct ModelFileHeader chrmicrocode_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800396F0
struct ModelFileHeader chrlectre_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039710
struct ModelFileHeader chrmoney_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039730
struct ModelFileHeader chrgoldbar_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039750
struct ModelFileHeader chrheroin_header = {0, &skeleton_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039770
struct ModelFileHeader chrclipboard_header = {0, &skeleton_standard_object, 0, 0, 1, 190.41742, 0, 3, 0, 0};
//D:80039790
struct ModelFileHeader chrdossierred_header = {0, &skeleton_standard_object, 0, 0, 1, 183.54231, 0, 4, 0, 0};
//D:800397B0
struct ModelFileHeader chrstafflist_header = {0, &skeleton_standard_object, 0, 0, 1, 215.17534, 0, 4, 0, 0};
//D:800397D0
struct ModelFileHeader chrdattape_header = {0, &skeleton_standard_object, 0, 0, 1, 79.868584, 0, 4, 0, 0};
//D:800397F0
struct ModelFileHeader chrplastique_header = {0, &skeleton_standard_object, 0, 0, 1, 143.86052, 0, 3, 0, 0};
//D:80039810
struct ModelFileHeader chrblackbox_header = {0, &skeleton_standard_object, 0, 0, 1, 128.31796, 0, 5, 0, 0};
//D:80039830
struct ModelFileHeader chrvideotape_header = {0, &skeleton_standard_object, 0, 0, 1, 122.69632, 0, 9, 0, 0};
//D:80039850
struct ModelFileHeader nintendologo_header = {0, &skeleton_standard_object, 0, 0, 1, 1868.335, 0, 1, 0, 0};
//D:80039870
struct ModelFileHeader goldeneyelogo_header = {0, &skeleton_standard_object, 0, 0, 1, 1287.1866, 0, 2, 0, 0};
//D:80039890
struct ModelFileHeader walletbond_header = {0, &skeleton_walletbond, 0, 0x2B, 0x1, 3504.53, 0, 0x54, 0, 0};
//D:800398B0
struct ModelFileHeader miltruck_header = {0, &skeleton_car, 0, 0xB, 0x5, 4589.7188, 0, 0x16, 0, 0};
//D:800398D0
struct ModelFileHeader jeep_header = {0, &skeleton_car, 0, 0xB, 0x5, 2107.8105, 0, 0x10, 0, 0};
//D:800398F0
struct ModelFileHeader artic_header = {0, &skeleton_car, 0, 0xB, 0x5, 2678.5667, 0x0, 0x11, 0, 0};
//D:80039910
struct ModelFileHeader helicopter_header = {0, &skeleton_flying, 0, 0x6, 0x4, 4955.271, 0, 0x18, 0, 0};
//D:80039930
struct ModelFileHeader tiger_header = {0, &skeleton_flying, 0, 0x6, 0x4, 4072.0291, 0, 0xE, 0, 0};
//D:80039950
struct ModelFileHeader milcopter_header = {0, &skeleton_flying, 0, 0x6, 0x4, 5316.9155, 0, 0xF, 0, 0};
//D:80039970
struct ModelFileHeader hind_header = {0, &skeleton_flying, 0, 0x6, 0x5, 5315.314, 0, 0xB, 0, 0};
//D:80039990
struct ModelFileHeader artictrailer_header = {0, &skeleton_standard_object, 0, 0, 1, 4014.6265, 0, 0xB, 0, 0};
//D:800399B0
struct ModelFileHeader motorbike_header = {0, &skeleton_standard_object, 0, 0, 1, 1610.8706, 0, 6, 0, 0};
//D:800399D0
struct ModelFileHeader tank_header = {0, &skeleton_tank, 0, 0x9, 0x5, 6290.8398, 0, 0x18, 0, 0};
//D:800399F0
struct ModelFileHeader apc_header = {0, &skeleton_standard_object, 0, 0, 1, 3611.1035, 0, 0xE, 0, 0};
//D:80039A10
struct ModelFileHeader speedboat_header = {0, &skeleton_standard_object, 0, 0, 1, 1799.4586, 0, 0xD, 0, 0};
//D:80039A30
struct ModelFileHeader plane_header = {0, &skeleton_flying, 0, 0x6, 0x3, 9285.4492, 0, 0x1C, 0, 0};
//D:80039A50
struct ModelFileHeader gun_runway1_header = {0, &skeleton_rotating_stuff, 0, 0x8, 0x5, 1927.5205, 0, 6, 0, 0};
//D:80039A70
struct ModelFileHeader safedoor_header = {0, &skeleton_standard_object, 0, 0, 1, 714.14612, 0, 4, 0, 0};
//D:80039A90
struct ModelFileHeader key_holder_header = {0, &skeleton_standard_object, 0, 0, 1, 223.87097, 0, 7, 0, 0};
//D:80039AB0
struct ModelFileHeader hatchsevx_header = {0, &skeleton_standard_object, 0, 0, 1, 1224.7664, 0, 2, 0, 0};
//D:80039AD0
struct ModelFileHeader sevdish_header = {0, &skeleton_rotating_stuff, 0, 0x8, 0x3, 14350.1, 0, 7, 0, 0};
//D:80039AF0
struct ModelFileHeader archsecdoor1_header = {0, &skeleton_standard_object, 0, 0, 1, 455.81409, 0, 3, 0, 0};
//D:80039B10
struct ModelFileHeader archsecdoor2_header = {0, &skeleton_standard_object, 0, 0, 1, 496.99292, 0, 3, 0, 0};
//D:80039B30
struct ModelFileHeader groundgun_header = {0, &skeleton_rotating_stuff, 0, 0x8, 0x5, 2182.6472, 0, 4, 0, 0};
//D:80039B50
struct ModelFileHeader trainextdoor_header = {0, &skeleton_standard_object, 0, 0, 1, 587.70111, 0, 5, 0, 0};
//D:80039B70
struct ModelFileHeader carbmw_header = {0, &skeleton_standard_object, 0, 0, 1, 553.08728, 0, 0xB, 0, 0};
//D:80039B90
struct ModelFileHeader carescort_header = {0, &skeleton_standard_object, 0, 0, 1, 1110.5665, 0, 9, 0, 0};
//D:80039BB0
struct ModelFileHeader cargolf_header = {0, &skeleton_standard_object, 0, 0, 1, 1121.6409, 0, 0xA, 0, 0};
//D:80039BD0
struct ModelFileHeader carweird_header = {0, &skeleton_standard_object, 0, 0, 1, 984.03931, 0, 0xD, 0, 0};
//D:80039BF0
struct ModelFileHeader carzil_header = {0, &skeleton_car, 0, 0xB, 0x5, 1044.5764, 0, 0xD, 0, 0};
//D:80039C10
struct ModelFileHeader shuttle_door_l_header = {0, &skeleton_standard_object, 0, 0, 1, 706.56641, 0, 7, 0, 0};
//D:80039C30
struct ModelFileHeader shuttle_door_r_header = {0, &skeleton_standard_object, 0, 0, 1, 706.56641, 0, 8, 0, 0};
//D:80039C50
struct ModelFileHeader depot_gate_entry_header = {0, &skeleton_standard_object, 0, 0, 1, 811.28949, 0, 3, 0, 0};
//D:80039C70
struct ModelFileHeader depot_door_steel_header = {0, &skeleton_standard_object, 0, 0, 1, 574.79651, 0, 3, 0, 0};
//D:80039C90
struct ModelFileHeader glassware2_header = {0, &skeleton_standard_object, 0, 0, 1, 98.488579, 0, 3, 0, 0};
//D:80039CB0
struct ModelFileHeader glassware3_header = {0, &skeleton_standard_object, 0, 0, 1, 137.92715, 0, 1, 0, 0};
//D:80039CD0
struct ModelFileHeader glassware4_header = {0, &skeleton_standard_object, 0, 0, 1, 177.48241, 0, 2, 0, 0};
//D:80039CF0
struct ModelFileHeader landmine_header = {0, &skeleton_standard_object, 0, 0, 1, 440.03009, 0, 2, 0, 0};
//D:80039D10
struct ModelFileHeader plant1_header = {0, &skeleton_standard_object, 0, 0, 1, 2704.1086, 0, 1, 0, 0};
//D:80039D30
struct ModelFileHeader plant11_header = {0, &skeleton_standard_object, 0, 0, 1, 2704.1086, 0, 1, 0, 0};
//D:80039D50
struct ModelFileHeader plant2_header = {0, &skeleton_standard_object, 0, 0, 1, 3416.248, 0, 2, 0, 0};
//D:80039D70
struct ModelFileHeader plant3_header = {0, &skeleton_standard_object, 0, 0, 1, 2986.0405, 0, 1, 0, 0};
//D:80039D90
struct ModelFileHeader jungle5_tree_header = {0, &skeleton_standard_object, 0, 0, 1, 3277.6123, 0, 4, 0, 0};
//D:80039DB0
struct ModelFileHeader legalpage_header = {0, &skeleton_standard_object, 0, 0, 1, 2711.7573, 0, 5, 0, 0};
//D:80039DD0
struct ModelFileHeader st_pete_room_1i_header = {0, &skeleton_standard_object, 0, 0, 1, 8437.5137, 0, 0x17, 0, 0};
//D:80039DF0
struct ModelFileHeader st_pete_room_2i_header = {0, &skeleton_standard_object, 0, 0, 1, 8515.8164, 0, 0x19, 0, 0};
//D:80039E10
struct ModelFileHeader st_pete_room_3t_header = {0, &skeleton_standard_object, 0, 0, 1, 4561.9766, 0, 0x1B, 0, 0};
//D:80039E30
struct ModelFileHeader st_pete_room_5c_header = {0, &skeleton_standard_object, 0, 0, 1, 4561.9766, 0, 0x19, 0, 0};
//D:80039E50
struct ModelFileHeader st_pete_room_6c_header = {0, &skeleton_standard_object, 0, 0, 1, 5006.2896, 0, 0x17, 0, 0};
//D:80039E70
struct ModelFileHeader door_rollertrain_header = {0, &skeleton_standard_object, 0, 0, 1, 1032.125, 0, 2, 0, 0};
//D:80039E90
struct ModelFileHeader door_win_header = {0, &skeleton_standard_object, 0, 0, 1, 211.90215, 0, 1, 0, 0};
//D:80039EB0
struct ModelFileHeader door_aztec_header = {0, &skeleton_standard_object, 0, 0, 1, 632.48639, 0, 1, 0, 0};
//D:80039ED0
struct ModelFileHeader shuttle_header = {0, &skeleton_standard_object, 0, 0, 1, 4475.1494, 0, 9, 0, 0};
//D:80039EF0
struct ModelFileHeader door_azt_desk_header = {0, &skeleton_standard_object, 0, 0, 1, 860.41669, 0, 2, 0, 0};
//D:80039F10
struct ModelFileHeader door_azt_desk_top_header = {0, &skeleton_standard_object, 0, 0, 1, 565.93268, 0, 3, 0, 0};
//D:80039F30
struct ModelFileHeader door_azt_chair_header = {0, &skeleton_standard_object, 0, 0, 1, 94.510803, 0, 3, 0, 0};
//D:80039F50
struct ModelFileHeader door_mf_header = {0, &skeleton_standard_object, 0, 0, 1, 559.70367, 0, 7, 0, 0};
//D:80039F70
struct ModelFileHeader flag_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 862.30865, 0, 2, 0, 0};
//D:80039F90
struct ModelFileHeader barricade_header = {0, &skeleton_standard_object, 0, 0, 1, 2047.3016, 0, 2, 0, 0};
//D:80039FB0
struct ModelFileHeader modembox_header = {0, &skeleton_console_one_screen, 0, 0x1, 0x1, 338.28839, 0, 4, 0, 0};
//D:80039FD0
struct ModelFileHeader doorpanel_header = {0, &skeleton_console_four_screen, 0, 0x4, 0x1, 338.28839, 0, 4, 0, 0};
//D:80039FF0
struct ModelFileHeader doorconsole_header = {0, &skeleton_console_one_screen, 0, 0x1, 0x1, 994.23688, 0, 0xD, 0, 0};
//D:8003A010
struct ModelFileHeader chrtesttube_header = {0, &skeleton_prop_weapon, 0, 0x3, 0x1, 136.25925, 0, 2, 0, 0};
//D:8003A030
struct ModelFileHeader bollard_header = {0, &skeleton_standard_object, 0, 0, 1, 628.78754, 0, 1, 0, 0};

//D:8003A050
ModelJoint jointlist_cctv[2] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003}
};
//D:8003A05C
ModelSkeleton skeleton_cctv = {2, 0, jointlist_cctv, 6, 0};

//D:8003A068
ModelJoint jointlist_console_one_screen[1] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A070
ModelSkeleton skeleton_console_one_screen = {1, 0, jointlist_console_one_screen, 3, 0};

//D:8003A07C
ModelJoint jointlist_console_four_screen[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A084
ModelSkeleton skeleton_console_four_screen = {1, 0, jointlist_console_four_screen, 3, 0};

//D:8003A090
ModelJoint jointlist_tv_holder[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A0B0
ModelSkeleton skeleton_tv_holder = {5, 0, jointlist_tv_holder, 0xF, 0};

//D:8003A0BC
ModelJoint jointlist_rotating_stuff[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003A0E0
ModelSkeleton skeleton_rotating_stuff = {6, 0, jointlist_rotating_stuff, 0x12, 0};

//D:8003A0EC
ModelJoint jointlist_eyelid_door[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006}
};
//D:8003A100
ModelSkeleton skeleton_eyelid_door = {3, 0, jointlist_eyelid_door, 9, 0};

//D:8003A10C
ModelJoint jointlist_iris_door[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012},
    {0x0002, 0x0015, 0x0015},
    {0x0002, 0x0018, 0x0018},
    {0x0002, 0x001B, 0x001B},
    {0x0002, 0x001E, 0x001E},
    {0x0002, 0x0021, 0x0021},
    {0x0002, 0x0024, 0x0024}
};
//D:8003A15C
ModelSkeleton skeleton_iris_door = {0xD, 0, jointlist_iris_door, 0x27, 0};

//D:8003A168
ModelJoint jointlist_walletbond[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A170
ModelSkeleton skeleton_walletbond = {1, 0, jointlist_walletbond, 3, 0};

//D:8003A17C
ModelJoint jointlist_car[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A19C
ModelSkeleton skeleton_car = {5, 0, jointlist_car, 0xF, 0};

//D:8003A1A8
ModelJoint jointlist_flying[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0015, 0x0003, 0x0003},
    {0x0015, 0x0004, 0x0004},
    {0x0015, 0x0005, 0x0005}
};
//D:8003A1C8
ModelSkeleton skeleton_flying = {5, 0, jointlist_flying, 3, 0};

//D:8003A1D4
ModelJoint jointlist_door[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A1DC
ModelSkeleton skeleton_door = {1, 0, jointlist_door, 3, 0};

//D:8003A1E8
ModelJoint jointlist_tank[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A208
ModelSkeleton skeleton_tank = {5, 0, jointlist_tank, 0xF, 0};

//D:8003A214
ModelJoint jointlist_hat[] = {
    {0x0015, 0x0000, 0x0000},
};
//D:8003A21C
ModelSkeleton skeleton_hat = {1, 0, jointlist_hat, 0, 0};

//D:8003A228                     .globl PitemZ_entries
ItemModelFileRecord PitemZ_entries[] = {
    {&alarm1_header, "Palarm1Z", 0.1},
    {&alarm2_header, "Palarm2Z", 0.1},
    {&explosionbit_header, "PexplosionbitZ", 0.1},
    {&ammo_crate1_header, "Pammo_crate1Z", 0.1},
    {&ammo_crate2_header, "Pammo_crate2Z", 0.1},
    {&ammo_crate3_header, "Pammo_crate3Z", 0.1},
    {&ammo_crate4_header, "Pammo_crate4Z", 0.1},
    {&ammo_crate5_header, "Pammo_crate5Z", 0.1},
    {&bin1_header, "Pbin1Z", 0.1},
    {&blotter1_header, "Pblotter1Z", 0.1},
    {&book1_header, "Pbook1Z", 0.1},
    {&bookshelf1_header, "Pbookshelf1Z", 0.1},
    {&bridge_console1a_header, "Pbridge_console1aZ", 0.1},
    {&bridge_console1b_header, "Pbridge_console1bZ", 0.1},
    {&bridge_console2a_header, "Pbridge_console2aZ", 0.1},
    {&bridge_console2b_header, "Pbridge_console2bZ", 0.1},
    {&bridge_console3a_header, "Pbridge_console3aZ", 0.1},
    {&bridge_console3b_header, "Pbridge_console3bZ", 0.1},
    {&card_box1_header, "Pcard_box1Z", 0.1},
    {&card_box2_header, "Pcard_box2Z", 0.1},
    {&card_box3_header, "Pcard_box3Z", 0.1},
    {&card_box4_lg_header, "Pcard_box4_lgZ", 0.1},
    {&card_box5_lg_header, "Pcard_box5_lgZ", 0.1},
    {&card_box6_lg_header, "Pcard_box6_lgZ", 0.1},
    {&cctv_header, "PcctvZ", 0.1},
    {&console1_header, "Pconsole1Z", 0.1},
    {&console2_header, "Pconsole2Z", 0.1},
    {&console3_header, "Pconsole3Z", 0.1},
    {&console_seva_header, "Pconsole_sevaZ", 0.1},
    {&console_sevb_header, "Pconsole_sevbZ", 0.1},
    {&console_sevc_header, "Pconsole_sevcZ", 0.1},
    {&console_sevd_header, "Pconsole_sevdZ", 0.1},
    {&console_sev2a_header, "Pconsole_sev2aZ", 0.1},
    {&console_sev2b_header, "Pconsole_sev2bZ", 0.1},
    {&console_sev2c_header, "Pconsole_sev2cZ", 0.1},
    {&console_sev2d_header, "Pconsole_sev2dZ", 0.1},
    {&console_sev_GEa_header, "Pconsole_sev_GEaZ", 0.1},
    {&console_sev_GEb_header, "Pconsole_sev_GEbZ", 0.1},
    {&desk1_header, "Pdesk1Z", 0.1},
    {&desk2_header, "Pdesk2Z", 0.1},
    {&desk_lamp2_header, "Pdesk_lamp2Z", 0.1},
    {&disc_reader_header, "Pdisc_readerZ", 0.1},
    {&disk_drive1_header, "Pdisk_drive1Z", 0.1},
    {&filing_cabinet1_header, "Pfiling_cabinet1Z", 0.1},
    {&jerry_can1_header, "Pjerry_can1Z", 0.1},
    {&keyboard1_header, "Pkeyboard1Z", 0.1},
    {&kit_units1_header, "Pkit_units1Z", 0.1},
    {&letter_tray1_header, "Pletter_tray1Z", 0.1},
    {&mainframe1_header, "Pmainframe1Z", 0.1},
    {&mainframe2_header, "Pmainframe2Z", 0.1},
    {&metal_chair1_header, "Pmetal_chair1Z", 0.1},
    {&metal_crate1_header, "Pmetal_crate1Z", 0.1},
    {&metal_crate2_header, "Pmetal_crate2Z", 0.1},
    {&metal_crate3_header, "Pmetal_crate3Z", 0.1},
    {&metal_crate4_header, "Pmetal_crate4Z", 0.1},
    {&missile_rack_header, "Pmissile_rackZ", 0.1},
    {&missile_rack2_header, "Pmissile_rack2Z", 0.1},
    {&oil_drum1_header, "Poil_drum1Z", 0.1},
    {&oil_drum2_header, "Poil_drum2Z", 0.1},
    {&oil_drum3_header, "Poil_drum3Z", 0.1},
    {&oil_drum5_header, "Poil_drum5Z", 0.1},
    {&oil_drum6_header, "Poil_drum6Z", 0.1},
    {&oil_drum7_header, "Poil_drum7Z", 0.1},
    {&padlock_header, "PpadlockZ", 0.1},
    {&phone1_header, "Pphone1Z", 0.1},
    {&radio_unit1_header, "Pradio_unit1Z", 0.1},
    {&radio_unit2_header, "Pradio_unit2Z", 0.1},
    {&radio_unit3_header, "Pradio_unit3Z", 0.1},
    {&radio_unit4_header, "Pradio_unit4Z", 0.1},
    {&sat1_reflect_header, "Psat1_reflectZ", 0.1},
    {&satdish_header, "PsatdishZ", 0.1},
    {&satbox_header, "PsatboxZ", 0.1},
    {&stool1_header, "Pstool1Z", 0.1},
    {&swivel_chair1_header, "Pswivel_chair1Z", 0.1},
    {&torpedo_rack_header, "Ptorpedo_rackZ", 0.1},
    {&tv1_header, "Ptv1Z", 0.1},
    {&tv_holder_header, "Ptv_holderZ", 0.1},
    {&tvscreen_header, "PtvscreenZ", 0.1},
    {&tv4screen_header, "Ptv4screenZ", 0.1},
    {&wood_lg_crate1_header, "Pwood_lg_crate1Z", 0.1},
    {&wood_lg_crate2_header, "Pwood_lg_crate2Z", 0.1},
    {&wood_md_crate3_header, "Pwood_md_crate3Z", 0.1},
    {&wood_sm_crate4_header, "Pwood_sm_crate4Z", 0.1},
    {&wood_sm_crate5_header, "Pwood_sm_crate5Z", 0.1},
    {&wood_sm_crate6_header, "Pwood_sm_crate6Z", 0.1},
    {&wooden_table1_header, "Pwooden_table1Z", 0.1},
    {&swipe_card2_header, "Pswipe_card2Z", 0.1},
    {&borg_crate_header, "Pborg_crateZ", 0.1},
    {&boxes4x4_header, "Pboxes4x4Z", 0.1},
    {&boxes3x4_header, "Pboxes3x4Z", 0.1},
    {&boxes2x4_header, "Pboxes2x4Z", 0.1},
    {&sec_panel_header, "Psec_panelZ", 0.1},
    {&ICBM_nose_header, "PICBM_noseZ", 0.1},
    {&ICBM_header, "PICBMZ", 0.1},
    {&tuning_console1_header, "Ptuning_console1Z", 0.1},
    {&desk_arecibo1_header, "Pdesk_arecibo1Z", 0.1},
    {&locker3_header, "Plocker3Z", 0.1},
    {&locker4_header, "Plocker4Z", 0.1},
    {&roofgun_header, "ProofgunZ", 0.1},
    {&dest_engine_header, "Pdest_engineZ", 0.1},
    {&dest_exocet_header, "Pdest_exocetZ", 0.1},
    {&dest_gun_header, "Pdest_gunZ", 0.1},
    {&dest_harpoon_header, "Pdest_harpoonZ", 0.1},
    {&dest_seawolf_header, "Pdest_seawolfZ", 0.1},
    {&window_header, "PwindowZ", 0.1},
    {&window_lib_lg1_header, "Pwindow_lib_lg1Z", 0.1},
    {&window_lib_sm1_header, "Pwindow_lib_sm1Z", 0.1},
    {&window_cor11_header, "Pwindow_cor11Z", 0.1},
    {&jungle3_tree_header, "Pjungle3_treeZ", 0.1},
    {&palm_header, "PpalmZ", 0.1},
    {&palmtree_header, "PpalmtreeZ", 0.1},
    {&plant2b_header, "Pplant2bZ", 0.1},
    {&labbench_header, "PlabbenchZ", 0.1},
    {&gasbarrel_header, "PgasbarrelZ", 0.1},
    {&gasbarrels_header, "PgasbarrelsZ", 0.1},
    {&bodyarmour_header, "PbodyarmourZ", 0.1},
    {&bodyarmourvest_header, "PbodyarmourvestZ", 0.1},
    {&gastank_header, "PgastankZ", 0.1},
    {&glassware1_header, "Pglassware1Z", 0.1},
    {&hatchbolt_header, "PhatchboltZ", 0.1},
    {&brakeunit_header, "PbrakeunitZ", 0.1},
    {&ak47mag_header, "Pak47magZ", 0.1},
    {&m16mag_header, "Pm16magZ", 0.1},
    {&mp5kmag_header, "Pmp5kmagZ", 0.1},
    {&skorpionmag_header, "PskorpionmagZ", 0.1},
    {&spectremag_header, "PspectremagZ", 0.1},
    {&uzimag_header, "PuzimagZ", 0.1},
    {&silencer_header, "PsilencerZ", 0.1},
    {&chrextinguisher_header, "PchrextinguisherZ", 0.1},
    {&boxcartridges_header, "PboxcartridgesZ", 0.1},
    {&fnp90mag_header, "Pfnp90magZ", 0.1},
    {&goldenshells_header, "PgoldenshellsZ", 0.1},
    {&magnumshells_header, "PmagnumshellsZ", 0.1},
    {&wppkmag_header, "PwppkmagZ", 0.1},
    {&tt33mag_header, "Ptt33magZ", 0.1},
    {&sev_door_header, "Psev_doorZ", 1.0},
    {&sev_door3_header, "Psev_door3Z", 1.0},
    {&sev_door3_wind_header, "Psev_door3_windZ", 1.0},
    {&sev_door4_wind_header, "Psev_door4_windZ", 1.0},
    {&sev_trislide_header, "Psev_trislideZ", 1.0},
    {&sev_door_v1_header, "Psev_door_v1Z", 1.0},
    {&steel_door1_header, "Psteel_door1Z", 1.0},
    {&steel_door2_header, "Psteel_door2Z", 1.0},
    {&steel_door3_header, "Psteel_door3Z", 1.0},
    {&silo_lift_door_header, "Psilo_lift_doorZ", 1.0},
    {&steel_door2b_header, "Psteel_door2bZ", 1.0},
    {&door_roller1_header, "Pdoor_roller1Z", 1.0},
    {&door_roller2_header, "Pdoor_roller2Z", 1.0},
    {&door_roller3_header, "Pdoor_roller3Z", 1.0},
    {&door_roller4_header, "Pdoor_roller4Z", 1.0},
    {&door_st_arec1_header, "Pdoor_st_arec1Z", 1.0},
    {&door_st_arec2_header, "Pdoor_st_arec2Z", 1.0},
    {&door_dest1_header, "Pdoor_dest1Z", 1.0},
    {&door_dest2_header, "Pdoor_dest2Z", 1.0},
    {&gas_plant_sw_do1_header, "Pgas_plant_sw_do1Z", 1.0},
    {&gas_plant_sw2_do1_header, "Pgas_plant_sw2_do1Z", 1.0},
    {&gas_plant_sw3_do1_header, "Pgas_plant_sw3_do1Z", 1.0},
    {&gas_plant_sw4_do1_header, "Pgas_plant_sw4_do1Z", 1.0},
    {&gas_plant_met1_do1_header, "Pgas_plant_met1_do1Z", 1.0},
    {&gas_plant_wc_cub1_header, "Pgas_plant_wc_cub1Z", 1.0},
    {&gasplant_clear_door_header, "Pgasplant_clear_doorZ", 1.0},
    {&train_door_header, "Ptrain_doorZ", 1.0},
    {&train_door2_header, "Ptrain_door2Z", 1.0},
    {&train_door3_header, "Ptrain_door3Z", 1.0},
    {&door_eyelid_header, "Pdoor_eyelidZ", 1.0},
    {&door_iris_header, "Pdoor_irisZ", 1.0},
    {&sevdoorwood_header, "PsevdoorwoodZ", 1.0},
    {&sevdoorwind_header, "PsevdoorwindZ", 1.0},
    {&sevdoornowind_header, "PsevdoornowindZ", 1.0},
    {&sevdoormetslide_header, "PsevdoormetslideZ", 1.0},
    {&cryptdoor1a_header, "Pcryptdoor1aZ", 1.0},
    {&cryptdoor1b_header, "Pcryptdoor1bZ", 1.0},
    {&cryptdoor2a_header, "Pcryptdoor2aZ", 1.0},
    {&cryptdoor2b_header, "Pcryptdoor2bZ", 1.0},
    {&cryptdoor3_header, "Pcryptdoor3Z", 1.0},
    {&cryptdoor4_header, "Pcryptdoor4Z", 1.0},
    {&vertdoor_header, "PvertdoorZ", 1.0},
    {&hatchdoor_header, "PhatchdoorZ", 1.0},
    {&damgatedoor_header, "PdamgatedoorZ", 1.0},
    {&damtundoor_header, "PdamtundoorZ", 1.0},
    {&damchaindoor_header, "PdamchaindoorZ", 1.0},
    {&silotopdoor_header, "PsilotopdoorZ", 1.0},
    {&doorprison1_header, "Pdoorprison1Z", 1.0},
    {&doorstatgate_header, "PdoorstatgateZ", 1.0},
    {&chrkalash_header, "PchrkalashZ", 0.1},
    {&chrgrenadelaunch_header, "PchrgrenadelaunchZ", 0.1},
    {&chrknife_header, "PchrknifeZ", 0.1},
    {&chrlaser_header, "PchrlaserZ", 0.1},
    {&chrm16_header, "Pchrm16Z", 0.1},
    {&chrmp5k_header, "Pchrmp5kZ", 0.1},
    {&chrruger_header, "PchrrugerZ", 0.1},
    {&chrwppk_header, "PchrwppkZ", 0.1},
    {&chrshotgun_header, "PchrshotgunZ", 0.1},
    {&chrskorpion_header, "PchrskorpionZ", 0.1},
    {&chrspectre_header, "PchrspectreZ", 0.1},
    {&chruzi_header, "PchruziZ", 0.1},
    {&chrgrenade_header, "PchrgrenadeZ", 0.1},
    {&chrfnp90_header, "Pchrfnp90Z", 0.1},
    {&chrbriefcase_header, "PchrbriefcaseZ", 0.1},
    {&chrremotemine_header, "PchrremotemineZ", 0.1},
    {&chrproximitymine_header, "PchrproximitymineZ", 0.1},
    {&chrtimedmine_header, "PchrtimedmineZ", 0.1},
    {&chrrocket_header, "PchrrocketZ", 0.1},
    {&chrgrenaderound_header, "PchrgrenaderoundZ", 0.1},
    {&chrwppksil_header, "PchrwppksilZ", 0.1},
    {&chrtt33_header, "Pchrtt33Z", 0.1},
    {&chrmp5ksil_header, "Pchrmp5ksilZ", 0.1},
    {&chrautoshot_header, "PchrautoshotZ", 0.1},
    {&chrgolden_header, "PchrgoldenZ", 0.1},
    {&chrthrowknife_header, "PchrthrowknifeZ", 0.1},
    {&chrsniperrifle_header, "PchrsniperrifleZ", 0.1},
    {&chrrocketlaunch_header, "PchrrocketlaunchZ", 0.1},
    {&hatfurry_header, "PhatfurryZ", 0.1},
    {&hatfurrybrown_header, "PhatfurrybrownZ", 0.1},
    {&hatfurryblack_header, "PhatfurryblackZ", 0.1},
    {&hattbird_header, "PhattbirdZ", 0.1},
    {&hattbirdbrown_header, "PhattbirdbrownZ", 0.1},
    {&hathelmet_header, "PhathelmetZ", 0.1},
    {&hathelmetgrey_header, "PhathelmetgreyZ", 0.1},
    {&hatmoon_header, "PhatmoonZ", 0.1},
    {&hatberet_header, "PhatberetZ", 0.1},
    {&hatberetblue_header, "PhatberetblueZ", 0.1},
    {&hatberetred_header, "PhatberetredZ", 0.1},
    {&hatpeaked_header, "PhatpeakedZ", 0.1},
    {&chrwristdart_header, "PchrwristdartZ", 0.1},
    {&chrexplosivepen_header, "PchrexplosivepenZ", 0.1},
    {&chrbombcase_header, "PchrbombcaseZ", 0.1},
    {&chrflarepistol_header, "PchrflarepistolZ", 0.1},
    {&chrpitongun_header, "PchrpitongunZ", 0.1},
    {&chrfingergun_header, "PchrfingergunZ", 0.1},
    {&chrsilverwppk_header, "PchrsilverwppkZ", 0.1},
    {&chrgoldwppk_header, "PchrgoldwppkZ", 0.1},
    {&chrdynamite_header, "PchrdynamiteZ", 0.1},
    {&chrbungee_header, "PchrbungeeZ", 0.1},
    {&chrdoordecoder_header, "PchrdoordecoderZ", 0.1},
    {&chrbombdefuser_header, "PchrbombdefuserZ", 0.1},
    {&chrbugdetector_header, "PchrbugdetectorZ", 0.1},
    {&chrsafecrackercase_header, "PchrsafecrackercaseZ", 0.1},
    {&chrcamera_header, "PchrcameraZ", 0.1},
    {&chrlockexploder_header, "PchrlockexploderZ", 0.1},
    {&chrdoorexploder_header, "PchrdoorexploderZ", 0.1},
    {&chrkeyanalysercase_header, "PchrkeyanalysercaseZ", 0.1},
    {&chrweaponcase_header, "PchrweaponcaseZ", 0.1},
    {&chrkeyyale_header, "PchrkeyyaleZ", 0.1},
    {&chrkeybolt_header, "PchrkeyboltZ", 0.1},
    {&chrbug_header, "PchrbugZ", 0.1},
    {&chrmicrocamera_header, "PchrmicrocameraZ", 0.1},
    {&floppy_header, "PfloppyZ", 0.1},
    {&chrgoldeneyekey_header, "PchrgoldeneyekeyZ", 0.1},
    {&chrpolarizedglasses_header, "PchrpolarizedglassesZ", 0.1},
    {&chrcreditcard_header, "PchrcreditcardZ", 0.1},
    {&chrdarkglasses_header, "PchrdarkglassesZ", 0.1},
    {&chrgaskeyring_header, "PchrgaskeyringZ", 0.1},
    {&chrdatathief_header, "PchrdatathiefZ", 0.1},
    {&safe_header, "PsafeZ", 0.1},
    {&bomb_header, "PbombZ", 0.1},
    {&chrplans_header, "PchrplansZ", 0.1},
    {&chrspyfile_header, "PchrspyfileZ", 0.1},
    {&chrblueprints_header, "PchrblueprintsZ", 0.1},
    {&chrcircuitboard_header, "PchrcircuitboardZ", 0.1},
    {&chrmap_header, "PchrmapZ", 0.1},
    {&chrspooltape_header, "PchrspooltapeZ", 0.1},
    {&chraudiotape_header, "PchraudiotapeZ", 0.1},
    {&chrmicrofilm_header, "PchrmicrofilmZ", 0.1},
    {&chrmicrocode_header, "PchrmicrocodeZ", 0.1},
    {&chrlectre_header, "PchrlectreZ", 0.1},
    {&chrmoney_header, "PchrmoneyZ", 0.1},
    {&chrgoldbar_header, "PchrgoldbarZ", 0.1},
    {&chrheroin_header, "PchrheroinZ", 0.1},
    {&chrclipboard_header, "PchrclipboardZ", 0.1},
    {&chrdossierred_header, "PchrdossierredZ", 0.1},
    {&chrstafflist_header, "PchrstafflistZ", 0.1},
    {&chrdattape_header, "PchrdattapeZ", 0.1},
    {&chrplastique_header, "PchrplastiqueZ", 0.1},
    {&chrblackbox_header, "PchrblackboxZ", 0.1},
    {&chrvideotape_header, "PchrvideotapeZ", 0.1},
    {&nintendologo_header, "PnintendologoZ", 0.1},
    {&goldeneyelogo_header, "PgoldeneyelogoZ", 0.1},
    {&walletbond_header, "PwalletbondZ", 0.1},
    {&miltruck_header, "PmiltruckZ", 0.1},
    {&jeep_header, "PjeepZ", 0.1},
    {&artic_header, "ParticZ", 0.1},
    {&helicopter_header, "PhelicopterZ", 0.1},
    {&tiger_header, "PtigerZ", 0.1},
    {&milcopter_header, "PmilcopterZ", 0.1},
    {&hind_header, "PhindZ", 0.1},
    {&artictrailer_header, "PartictrailerZ", 0.1},
    {&motorbike_header, "PmotorbikeZ", 0.1},
    {&tank_header, "PtankZ", 0.1},
    {&apc_header, "PapcZ", 0.1},
    {&speedboat_header, "PspeedboatZ", 0.1},
    {&plane_header, "PplaneZ", 0.1},
    {&gun_runway1_header, "Pgun_runway1Z", 0.1},
    {&safedoor_header, "PsafedoorZ", 1.0},
    {&key_holder_header, "Pkey_holderZ", 1.0},
    {&hatchsevx_header, "PhatchsevxZ", 1.0},
    {&sevdish_header, "PsevdishZ", 1.0},
    {&archsecdoor1_header, "Parchsecdoor1Z", 1.0},
    {&archsecdoor2_header, "Parchsecdoor2Z", 1.0},
    {&groundgun_header, "PgroundgunZ", 0.1},
    {&trainextdoor_header, "PtrainextdoorZ", 1.0},
    {&carbmw_header, "PcarbmwZ", 0.1},
    {&carescort_header, "PcarescortZ", 0.1},
    {&cargolf_header, "PcargolfZ", 0.1},
    {&carweird_header, "PcarweirdZ", 0.1},
    {&carzil_header, "PcarzilZ", 0.1},
    {&shuttle_door_l_header, "Pshuttle_door_lZ", 1.0},
    {&shuttle_door_r_header, "Pshuttle_door_rZ", 1.0},
    {&depot_gate_entry_header, "Pdepot_gate_entryZ", 0.1},
    {&depot_door_steel_header, "Pdepot_door_steelZ", 0.1},
    {&glassware2_header, "Pglassware2Z", 0.1},
    {&glassware3_header, "Pglassware3Z", 0.1},
    {&glassware4_header, "Pglassware4Z", 0.1},
    {&landmine_header, "PlandmineZ", 0.1},
    {&plant1_header, "Pplant1Z", 0.1},
    {&plant11_header, "Pplant11Z", 0.1},
    {&plant2_header, "Pplant2Z", 0.1},
    {&plant3_header, "Pplant3Z", 0.1},
    {&jungle5_tree_header, "Pjungle5_treeZ", 0.1},
    {&legalpage_header, "PlegalpageZ", 0.1},
    {&st_pete_room_1i_header, "Pst_pete_room_1iZ", 0.1},
    {&st_pete_room_2i_header, "Pst_pete_room_2iZ", 0.1},
    {&st_pete_room_3t_header, "Pst_pete_room_3tZ", 0.1},
    {&st_pete_room_5c_header, "Pst_pete_room_5cZ", 0.1},
    {&st_pete_room_6c_header, "Pst_pete_room_6cZ", 0.1},
    {&door_rollertrain_header, "Pdoor_rollertrainZ", 1.0},
    {&door_win_header, "Pdoor_winZ", 1.0},
    {&door_aztec_header, "Pdoor_aztecZ", 1.0},
    {&shuttle_header, "PshuttleZ", 0.1},
    {&door_azt_desk_header, "Pdoor_azt_deskZ", 1.0},
    {&door_azt_desk_top_header, "Pdoor_azt_desk_topZ", 1.0},
    {&door_azt_chair_header, "Pdoor_azt_chairZ", 1.0},
    {&door_mf_header, "Pdoor_mfZ", 1.0},
    {&flag_header, "PflagZ", 0.1},
    {&barricade_header, "PbarricadeZ", 0.1},
    {&modembox_header, "PmodemboxZ", 0.1},
    {&doorpanel_header, "PdoorpanelZ", 0.1},
    {&doorconsole_header, "PdoorconsoleZ", 0.1},
    {&chrtesttube_header, "PchrtesttubeZ", 0.1},
    {&bollard_header, "PbollardZ", 0.1},
    {0, "", 1.0}
};

//D:8003b224
u32 object_explosion_details[] = {
    0x0006315c, 0x7b6cdbff, 0x5126fb59, 0x7ca70006,
    0x2afecb3e, 0x73f4278f, 0x6d3a44c8, 0x00050000,
    0x00000000, 0x00000000, 0x0000000b, 0xb9b03eba,
    0xad6275c8, 0xb70ff06e, 0x000b17d9, 0xdfcc57cd,
    0x82547345, 0xe011000b, 0x3779ed72, 0x688df67b,
    0x37e54f89, 0x000be277, 0x0474dd1e, 0x0c48486c,
    0xf87d000b, 0x7c3f16bc, 0x44a91a58, 0xe4129297,
    0x00003dc2, 0x16b6e30d, 0xbcabc592, 0xf9b50002,
    0x719c7024, 0x9ee0c175, 0xa5ddc933, 0x00028e16,
    0xbbca05c0, 0x1a7381be, 0xf8210000, 0x00000000,
    0x00000000, 0x00000000, 0x00082716, 0xf5440d35,
    0xc20e83d7, 0x7d730008, 0x81a1b772, 0x1b57437a,
    0x85fab6c1, 0x000827eb, 0x5a7abd1a, 0x27eb5a7a,
    0xbd1a0008, 0x98de8c36, 0xddd5f74b, 0x4f0a1f14,
    0x000834f5, 0xf199a9f2, 0x3d27c707, 0xb9ad0008,
    0x678fdb91, 0x2a2e8d91, 0x6eee925e, 0x0004d82f,
    0xf4d7546f, 0xd6c787d9, 0x01430004, 0x100eadf2,
    0x1fdd45f1, 0x4772f8c6, 0x0004ef0b, 0x71bbb7f7,
    0xbfa303b8, 0xe44e0004, 0xdfd1676a, 0x8597e8ac,
    0xe2109a4d, 0x0004ab48, 0xdd9b4343, 0x04b80dcc,
    0x3b3d0004, 0x836b6bbf, 0x9dbb3db7, 0x59577341,
    0x00070000, 0x00000000, 0x00000000, 0x00000009,
    0xb1cc19e2, 0x0ea5b1cc, 0x19e20ea5, 0x0009f093,
    0xb2df1409, 0x271ee0b3, 0x418a0009, 0x3ac20102,
    0xbf013ac2, 0x0102bf01, 0x00093ac6, 0xe449a56e,
    0xa4cfeda0, 0x17190009, 0x9bcfc333, 0x63844298,
    0xd4557bfa, 0x0009839e, 0x0ba71466, 0xdb6dd1b3,
    0x12330009, 0x3f677a70, 0x83de7052, 0x07d236ff,
    0x0009a409, 0x692de286, 0xc63c82d0, 0x5d070009,
    0xd6ca1866, 0x839cbc6a, 0x86ad4dc6, 0x000996fc,
    0xa1efa9e6, 0xb9d2a3c5, 0xa0450009, 0x7d2be7dc,
    0x55db378e, 0x4765b09c, 0x0009e2af, 0x2d4371fe,
    0xe39093b3, 0x57e30009, 0x9367098a, 0x3b68d6f8,
    0x4eaf7b83, 0x000f0000, 0x00000000, 0x00000000,
    0x0000000f, 0x00000000, 0x00000000, 0x00000000,
    0x0007993d, 0xa2b25028, 0x825e25b8, 0xd8ef0006,
    0x6553024d, 0xfd22d469, 0x18e432f6, 0x0006f742,
    0x0cb58ed2, 0x60216ad5, 0xaa880004, 0x06d882ef,
    0x5b194147, 0x5ae1374e, 0x0004284d, 0x3e7c9330,
    0xcf1e013f, 0x4e290006, 0xe339c0b6, 0xe5fc7054,
    0x83a8c118, 0x0004b49f, 0x00024ef6, 0x88490002,
    0x070b0002, 0x2d56a1ee, 0x41058ae6, 0x6a2a60dd,
    0x000979b2, 0xbc78b9b9, 0xc76a97a1, 0x3da30009,
    0x3292ddc3, 0x926512a6, 0xe935b9bc, 0x000304db,
    0x3cfddb5c, 0x3b2950b7, 0x83d10004, 0xbe6408ad,
    0x150d6aed, 0x542e63b3, 0x0004d7e5, 0x13695acc,
    0x535a2105, 0x1bf70004, 0x72223cee, 0x1a15122a,
    0xadec5ef3, 0x0004927f, 0x10b05125, 0x7f4ebbc5,
    0x8088000b, 0xe89d7502, 0x9003469d, 0x19f0a5e6,
    0x000b3771, 0xc00280ff, 0xdbf61705, 0x497a000e,
    0xa954afde, 0xbb6cd4a6, 0x9883fa27, 0x000ede9f,
    0xcef06346, 0x80fba382, 0x14d1000e, 0x448ed4cc,
    0xc1b5442f, 0xc1d1ee05, 0x000ec7c0, 0xf918095e,
    0xece206d4, 0xc64d000e, 0xc49116ec, 0xdea75a19,
    0x9de7ff28, 0x000ee889, 0x2da62775, 0x153cbae6,
    0xcb1b0000, 0x2d56a1ee, 0x41058ae6, 0x6a2a60dd,
    0x0006e5e6, 0x8fb7d5fe, 0xe959d656, 0xfb820007,
    0x58763a4f, 0xd115a10d, 0x265d2c02, 0x0007787e,
    0xc128d96a, 0x60c918e7, 0x99ad0007, 0x879a90e4,
    0xc20f35fe, 0xc80791d8, 0x000740ae, 0x62b6d240,
    0xac8d47c5, 0x17d10000, 0x00000000, 0x00000000,
    0x00000000, 0x000715c6, 0xb37d118a, 0x4e615d02,
    0x7d500006, 0x15c6b37d, 0x118a4e61, 0x5d027d50,
    0x00030000, 0x00000000, 0x00000000, 0x00000003,
    0x24698ae5, 0x524fe5f6, 0xbe4ac865, 0x00052957,
    0x1b2227c7, 0x96630ddf, 0x411f0007, 0x15c6b37d,
    0x118a4e61, 0x5d027d50, 0x00040000, 0x00000000,
    0x00000000, 0x00000006, 0xf8f4f1e0, 0x473f41dd,
    0xa510c9c6, 0x00080000, 0x00000000, 0x00000000,
    0x00000004, 0x7a512382, 0x9b3629e5, 0x5921017a,
    0x00048666, 0x3dd9e619, 0x6134cc94, 0x1a5c0004,
    0x7f3931c5, 0x9ac370ab, 0x0551b069, 0x0003d727,
    0x7ab2786b, 0xf5ad3fc4, 0xd6ce0003, 0x4548d59e,
    0x1edce88d, 0xe9e4af76, 0x0003262f, 0x491bfd57,
    0x6715e7ed, 0x2626000f, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000004, 0xbcae0bd1, 0x0ff73a30, 0x724083b7,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000006, 0xb2c6170a,
    0x0a236bbe, 0xb59382db, 0x0005275b, 0x8ad3002c,
    0x27b58ad3, 0x002c0005, 0x00000000, 0x00000000,
    0x00000000, 0x000833a1, 0x8a014d42, 0xd9cbb865,
    0xb3360004, 0x8c0678fc, 0x8f9a4df5, 0x4d5322f9,
    0x000399e9, 0x0107ef5e, 0x0560e6df, 0x4b360003,
    0x31e70023, 0xb2aea2d7, 0xe54090b2, 0x00080000,
    0x00000000, 0x00000000, 0x0000000d, 0x00000000,
    0x00000000, 0x00000000, 0x000833a1, 0x8a014d42,
    0xd9cbb865, 0xb3360008, 0x33a18a01, 0x4d42d9cb,
    0xb865b336, 0x000833a1, 0x8a014d42, 0xd9cbb865,
    0xb3360008, 0x33a18a01, 0x4d42d9cb, 0xb865b336,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000002, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00060000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000c0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000d0000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00030000, 0x00000000, 0x00000000,
    0x0000000d, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x000d0000,
    0x00000000, 0x00000000, 0x0000000d, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000006, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000006, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000000,
    0x00040000, 0x00000000, 0x00000000, 0x00000004,
    0x00000000, 0x00000000, 0x00000000, 0x00040000,
    0x00000000, 0x00000000, 0x00000004, 0x00000000,
    0x00000000, 0x00000000, 0x000d0000, 0x00000000,
    0x00000000, 0x00000004, 0x00000000, 0x00000000,
    0x00000000, 0x00040000, 0x00000000, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000000,
    0x00040000, 0x00000000, 0x00000000, 0x00000004,
    0x00000000, 0x00000000, 0x00000000, 0x00040000,
    0x00000000, 0x00000000, 0x00000004, 0x00000000,
    0x00000000, 0x00000000, 0x00040000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000007, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000d, 0x00000000, 0x00000000,
    0x00000000, 0x000d0000, 0x00000000, 0x00000000,
    0x0000000d, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000006, 0x00000000, 0x00000000, 0x00000000,
    0x00060000, 0x00000000, 0x00000000, 0x00000009,
    0x00000000, 0x00000000, 0x00000000, 0x000d0000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000ffff, 0xffffffff,
    0xffffffff, 0xffff0000, 0x00000000
};

