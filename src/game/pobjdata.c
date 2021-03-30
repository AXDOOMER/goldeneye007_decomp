#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"

//D:800375D0
struct ModelFileHeader Palarm1z_header = {0, &model_object_standard_object, 0, 0, 1, 304.6402, 0, 2, 0, 0};
//D:800375F0
struct ModelFileHeader Palarm2Z_header = {0, &model_object_standard_object, 0, 0, 1, 208.22205, 0, 3, 0, 0};
//D:80037610
struct ModelFileHeader PexplosionbitZ_header = {0, &model_object_standard_object, 0, 0, 1, 208.22205, 0, 0, 0, 0};
//D:80037630
struct ModelFileHeader Pammo_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 3, 0, 0};
//D:80037650
struct ModelFileHeader Pammo_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 4, 0, 0};
//D:80037670
struct ModelFileHeader Pammo_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 4, 0, 0};
//D:80037690
struct ModelFileHeader Pammo_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 5, 0, 0};
//D:800376B0
struct ModelFileHeader Pammo_crate5Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 5, 0, 0};
//D:800376D0
struct ModelFileHeader Pbin1Z_header = {0, &model_object_standard_object, 0, 0, 1, 3027.6262,0, 2, 0, 0};
//D:800376F0
struct ModelFileHeader Pblotter1Z_header = {0, &model_object_standard_object, 0, 0, 1, 432.46707, 0, 1, 0, 0};
//D:80037710
struct ModelFileHeader Pbook1Z_header = {0, &model_object_standard_object, 0, 0, 1, 171.37482, 0, 2, 0, 0};
//D:80037730
struct ModelFileHeader Pbookshelf1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1166.7578, 0, 0xD, 0, 0};
//D:80037750
struct ModelFileHeader Pbridge_console1aZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:80037770
struct ModelFileHeader Pbridge_console1bZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 788.03992, 0, 0x10, 0, 0};
//D:80037790
struct ModelFileHeader Pbridge_console2aZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:800377B0
struct ModelFileHeader Pbridge_console2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 788.03992, 0, 0xF, 0, 0};
//D:800377D0
struct ModelFileHeader Pbridge_console3aZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:800377F0
struct ModelFileHeader Pbridge_console3bZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 788.03992, 0, 0x10, 0, 0};
//D:80037810
struct ModelFileHeader Pcard_box1Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 5, 0, 0};
//D:80037830
struct ModelFileHeader Pcard_box2Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 6, 0, 0};
//D:80037850
struct ModelFileHeader Pcard_box3Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 5, 0, 0};
//D:80037870
struct ModelFileHeader Pcard_box4_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 0, 4, 0, 0};
//D:80037890
struct ModelFileHeader Pcard_box5_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 0, 5, 0, 0};
//D:800378B0
struct ModelFileHeader Pcard_box6_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 0, 5, 0, 0};
//D:800378D0
struct ModelFileHeader PcctvZ_header = {0, &prop_cctv_related, 0, 0x4, 0x2, 558.90094, 0, 6, 0, 0};
//D:800378F0
struct ModelFileHeader Pconsole1Z_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037910
struct ModelFileHeader Pconsole2Z_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037930
struct ModelFileHeader Pconsole3Z_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037950
struct ModelFileHeader Pconsole_sevaZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xE, 0, 0};
//D:80037970
struct ModelFileHeader Pconsole_sevbZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 994.23688, 0, 0xB, 0, 0};
//D:80037990
struct ModelFileHeader Pconsole_sevcZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xF, 0, 0};
//D:800379B0
struct ModelFileHeader Pconsole_sevdZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:800379D0
struct ModelFileHeader Pconsole_sev2aZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:800379F0
struct ModelFileHeader Pconsole_sev2bZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 994.23688, 0, 0xD, 0, 0};
//D:80037A10
struct ModelFileHeader Pconsole_sev2cZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xF, 0, 0};
//D:80037A30
struct ModelFileHeader Pconsole_sev2dZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A50
struct ModelFileHeader Pconsole_sev_GEaZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A70
struct ModelFileHeader Pconsole_sev_GEbZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A90
struct ModelFileHeader Pdesk1Z_header = {0, &model_object_standard_object, 0, 0, 1, 957.18225, 0, 3, 0, 0};
//D:80037AB0
struct ModelFileHeader Pdesk2Z_header = {0, &model_object_standard_object, 0, 0, 1, 957.18225, 0, 3, 0, 0};
//D:80037AD0
struct ModelFileHeader Pdesk_lamp2Z_header = {0, &model_object_standard_object, 0, 0, 1, 804.59833, 0, 4, 0, 0};
//D:80037AF0
struct ModelFileHeader Pdisc_readerZ_header = {0, &model_object_standard_object, 0, 0, 1, 214.33035, 0, 6, 0, 0};
//D:80037B10
struct ModelFileHeader Pdisk_drive1Z_header = {0, &model_object_standard_object, 0, 0, 1, 191.85779, 0, 4, 0, 0};
//D:80037B30
struct ModelFileHeader Pfiling_cabinet1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1055.5693, 0, 2, 0, 0};
//D:80037B50
struct ModelFileHeader Pjerry_can1Z_header = {0, &model_object_standard_object, 0, 0, 1, 366.61932, 0, 4, 0, 0};
//D:80037B70
struct ModelFileHeader Pkeyboard1Z_header = {0, &model_object_standard_object, 0, 0, 1, 278.23227, 0, 2, 0, 0};
//D:80037B90
struct ModelFileHeader Pkit_units1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1661.4763, 0, 4, 0, 0};
//D:80037BB0
struct ModelFileHeader Pletter_tray1Z_header = {0, &model_object_standard_object, 0, 0, 1, 252.06836, 0, 1, 0, 0};
//D:80037BD0
struct ModelFileHeader Pmainframe1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1119.4073, 0, 7, 0, 0};
//D:80037BF0
struct ModelFileHeader Pmainframe2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1119.4073, 0, 7, 0, 0};
//D:80037C10
struct ModelFileHeader Pmetal_chair1Z_header = {0, &model_object_standard_object, 0, 0, 1, 639.18097, 0, 2, 0, 0};
//D:80037C30
struct ModelFileHeader Pmetal_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037C50
struct ModelFileHeader Pmetal_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037C70
struct ModelFileHeader Pmetal_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 2, 0, 0};
//D:80037C90
struct ModelFileHeader Pmetal_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037CB0
struct ModelFileHeader Pmissile_rackZ_header = {0, &model_object_standard_object, 0, 0, 1, 964.16296, 0, 4, 0, 0};
//D:80037CD0
struct ModelFileHeader Pmissile_rack2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1148.4724, 0, 4, 0, 0};
//D:80037CF0
struct ModelFileHeader Poil_drum1Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 2, 0, 0};
//D:80037D10
struct ModelFileHeader Poil_drum2Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037D30
struct ModelFileHeader Poil_drum3Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037D50
struct ModelFileHeader Poil_drum5Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 3, 0, 0};
//D:80037D70
struct ModelFileHeader Poil_drum6Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 3, 0, 0};
//D:80037D90
struct ModelFileHeader Poil_drum7Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037DB0
struct ModelFileHeader PpadlockZ_header = {0, &model_object_standard_object, 0, 0, 1, 225.64145, 0, 4, 0, 0};
//D:80037DD0
struct ModelFileHeader Pphone1Z_header = {0, &model_object_standard_object, 0, 0, 1, 166.03481, 0, 2, 0, 0};
//D:80037DF0
struct ModelFileHeader Pradio_unit1Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E10
struct ModelFileHeader Pradio_unit2Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E30
struct ModelFileHeader Pradio_unit3Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E50
struct ModelFileHeader Pradio_unit4Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E70
struct ModelFileHeader Psat1_reflectZ_header = {0, &model_object_standard_object, 0, 0, 1, 5185.9409, 0, 0xD, 0, 0};
//D:80037E90
struct ModelFileHeader PsatdishZ_header = {0, &model_object_standard_object, 0, 0, 1, 2437.468, 0, 2, 0, 0};
//D:80037EB0
struct ModelFileHeader PsatboxZ_header = {0, &model_object_standard_object, 0, 0, 1, 89.935875, 0, 1, 0, 0};
//D:80037ED0
struct ModelFileHeader Pstool1Z_header = {0, &model_object_standard_object, 0, 0, 1, 353.11398, 0, 2, 0, 0};
//D:80037EF0
struct ModelFileHeader Pswivel_chair1Z_header = {0, &model_object_standard_object, 0, 0, 1, 581.16394, 0, 3, 0, 0};
//D:80037F10
struct ModelFileHeader Ptorpedo_rackZ_header = {0, &model_object_standard_object, 0, 0, 1, 765.61725, 0, 3, 0, 0};
//D:80037F30
struct ModelFileHeader Ptv1Z_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 347.0235, 0, 5, 0, 0};
//D:80037F50
struct ModelFileHeader Ptv_holderZ_header = {0, &prop_tv_holder_related, 0, 0x4, 0x5, 1352.4841, 0, 2, 0, 0};
//D:80037F70
struct ModelFileHeader PtvscreenZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 211.74477, 0, 1, 0, 0};
//D:80037F90
struct ModelFileHeader Ptv4screenZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 211.74477, 0, 1, 0, 0};
//D:80037FB0
struct ModelFileHeader Pwood_lg_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037FD0
struct ModelFileHeader Pwood_lg_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 2, 0, 0};
//D:80037FF0
struct ModelFileHeader Pwood_md_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 909.32666, 0, 2, 0, 0};
//D:80038010
struct ModelFileHeader Pwood_sm_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 3, 0, 0};
//D:80038030
struct ModelFileHeader Pwood_sm_crate5Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 4, 0, 0};
//D:80038050
struct ModelFileHeader Pwood_sm_crate6Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 4, 0, 0};
//D:80038070
struct ModelFileHeader Pwooden_table1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1095.1365, 0, 2, 0, 0};
//D:80038090
struct ModelFileHeader Pswipe_card2Z_header = {0, &model_object_standard_object, 0, 0, 1, 123.088844, 0, 2, 0, 0};
//D:800380B0
struct ModelFileHeader Pborg_crateZ_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 1, 0, 0};
//D:800380D0
struct ModelFileHeader Pboxes4x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2424.8711, 0, 7, 0, 0};
//D:800380F0
struct ModelFileHeader Pboxes3x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2241.0935, 0, 6, 0, 0};
//D:80038110
struct ModelFileHeader Pboxes2x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2100.0, 0, 6, 0, 0};
//D:80038130
struct ModelFileHeader Psec_panelZ_header = {0, &model_object_standard_object, 0, 0, 1, 1567.2454, 0, 3, 0, 0};
//D:80038150
struct ModelFileHeader PICBM_noseZ_header = {0, &model_object_standard_object, 0, 0, 1, 2782.7126, 0, 8, 0, 0};
//D:80038170
struct ModelFileHeader PICBMZ_header = {0, &model_object_standard_object, 0, 0, 1, 14790.535, 0, 0xE, 0, 0};
//D:80038190
struct ModelFileHeader Ptuning_console1Z_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 1139.5872, 0, 0xE, 0, 0};
//D:800381B0
struct ModelFileHeader Pdesk_arecibo1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1829.1477, 0, 3, 0, 0};
//D:800381D0
struct ModelFileHeader Plocker3Z_header = {0, &model_object_standard_object, 0, 0, 1, 916.99805, 0, 3, 0, 0};
//D:800381F0
struct ModelFileHeader Plocker4Z_header = {0, &model_object_standard_object, 0, 0, 1, 916.99805, 0, 3, 0, 0};
//D:80038210
struct ModelFileHeader ProofgunZ_header = {0, &prop_rotating_stuff_related, 0, 0x8, 0x5, 1910.908, 0, 0xE, 0, 0};
//D:80038230
struct ModelFileHeader Pdest_engineZ_header = {0, &model_object_standard_object, 0, 0, 1, 6459.439, 0, 0xA, 0, 0};
//D:80038250
struct ModelFileHeader Pdest_exocetZ_header = {0, &model_object_standard_object, 0, 0, 1, 1644.8435, 0, 8, 0, 0};
//D:80038270
struct ModelFileHeader Pdest_gunZ_header = {0, &model_object_standard_object, 0, 0, 1, 2124.0735, 0, 5, 0, 0};
//D:80038290
struct ModelFileHeader Pdest_harpoonZ_header = {0, &model_object_standard_object, 0, 0, 1, 1798.7655, 0, 5, 0, 0};
//D:800382B0
struct ModelFileHeader Pdest_seawolfZ_header = {0, &model_object_standard_object, 0, 0, 1, 2282.0623, 0, 0xA, 0, 0};
//D:800382D0
struct ModelFileHeader PwindowZ_header = {0, &model_object_standard_object, 0, 0, 1, 423.48956, 0, 1, 0, 0};
//D:800382F0
struct ModelFileHeader Pwindow_lib_lg1Z_header = {0, &model_object_standard_object, 0, 0, 1, 835.20624, 0, 1, 0, 0};
//D:80038310
struct ModelFileHeader Pwindow_lib_sm1Z_header = {0, &model_object_standard_object, 0, 0, 1, 601.28625, 0, 1, 0, 0};
//D:80038330
struct ModelFileHeader Pwindow_cor11Z_header = {0, &model_object_standard_object, 0, 0, 1, 414.53622, 0, 1, 0, 0};
//D:80038350
struct ModelFileHeader Pjungle3_treeZ_header = {0, &model_object_standard_object, 0, 0, 1, 28729.467, 0, 5, 0, 0};
//D:80038370
struct ModelFileHeader PpalmZ_header = {0, &model_object_standard_object, 0, 0, 1, 15501.406, 0, 3, 0, 0};
//D:80038390
struct ModelFileHeader PpalmtreeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1781.4542, 0, 2, 0, 0};
//D:800383B0
struct ModelFileHeader Pplant2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 1252.9539, 0, 2, 0, 0};
//D:800383D0
struct ModelFileHeader PlabbenchZ_header = {0, &model_object_standard_object, 0, 0, 1, 844.09717, 0, 4, 0, 0};
//D:800383F0
struct ModelFileHeader PgasbarrelZ_header = {0, &model_object_standard_object, 0, 0, 1, 725.94379, 0, 2, 0, 0};
//D:80038410
struct ModelFileHeader PgasbarrelsZ_header = {0, &model_object_standard_object, 0, 0, 1, 1174.1927, 0, 2, 0, 0};
//D:80038430
struct ModelFileHeader PbodyarmourZ_header = {0, &model_object_standard_object, 0, 0, 1, 246.94099, 0, 7, 0, 0};
//D:80038450
struct ModelFileHeader PbodyarmourvestZ_header = {0, &model_object_standard_object, 0, 0, 1, 241.82211, 0, 2, 0, 0};
//D:80038470
struct ModelFileHeader PgastankZ_header = {0, &model_object_standard_object, 0, 0, 1, 1130.0691, 0, 5, 0, 0};
//D:80038490
struct ModelFileHeader Pglassware1Z_header = {0, &model_object_standard_object, 0, 0, 1, 72.111031, 0, 1, 0, 0};
//D:800384B0
struct ModelFileHeader PhatchboltZ_header = {0, &model_object_standard_object, 0, 0, 1, 2236.0679, 0, 1, 0, 0};
//D:800384D0
struct ModelFileHeader PbrakeunitZ_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 0, 4, 0, 0};
//D:800384F0
struct ModelFileHeader Pak47magZ_header = {0, &model_object_standard_object, 0, 0, 1, 107.11019, 0, 2, 0, 0};
//D:80038510
struct ModelFileHeader Pm16magZ_header = {0, &model_object_standard_object, 0, 0, 1, 87.934891, 0, 2, 0, 0};
//D:80038530
struct ModelFileHeader Pmp5kmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 119.547295, 0, 2, 0, 0};
//D:80038550
struct ModelFileHeader PskorpionmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 58.428444, 0, 2, 0, 0};
//D:80038570
struct ModelFileHeader PspectremagZ_header = {0, &model_object_standard_object, 0, 0, 1, 99.01432, 0, 2, 0, 0};
//D:80038590
struct ModelFileHeader PuzimagZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:800385B0
struct ModelFileHeader PsilencerZ_header = {0, &model_object_standard_object, 0, 0, 1, 63.915436, 0, 3, 0, 0};
//D:800385D0
struct ModelFileHeader PchrextinguisherZ_header = {0, &model_object_standard_object, 0, 0, 1, 425.50903, 0, 2, 0, 0};
//D:800385F0
struct ModelFileHeader PboxcartridgesZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038610
struct ModelFileHeader Pfnp90magZ_header = {0, &model_object_standard_object, 0, 0, 1, 176.28201, 0, 2, 0, 0};
//D:80038630
struct ModelFileHeader PgoldenshellsZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038650
struct ModelFileHeader PmagnumshellsZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038670
struct ModelFileHeader PwppkmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:80038690
struct ModelFileHeader Ptt33magZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:800386B0
struct ModelFileHeader Psev_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 1143.7695, 0, 3, 0, 0};
//D:800386D0
struct ModelFileHeader Psev_door3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1143.5603, 0, 6, 0, 0};
//D:800386F0
struct ModelFileHeader Psev_door3_windZ_header = {0, &model_object_standard_object, 0, 0, 1, 1143.5603, 0, 5, 0, 0};
//D:80038710
struct ModelFileHeader Psev_door4_windZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 1143.5603, 0, 8, 0, 0};
//D:80038730
struct ModelFileHeader Psev_trislideZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 950.54327, 0, 2, 0, 0};
//D:80038750
struct ModelFileHeader Psev_door_v1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 6, 0, 0};
//D:80038770
struct ModelFileHeader Psteel_door1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 4, 0, 0};
//D:80038790
struct ModelFileHeader Psteel_door2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:800387B0
struct ModelFileHeader Psteel_door3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:800387D0
struct ModelFileHeader Psilo_lift_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 600.71082, 0, 4, 0, 0};
//D:800387F0
struct ModelFileHeader Psteel_door2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:80038810
struct ModelFileHeader Pdoor_roller1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038830
struct ModelFileHeader Pdoor_roller2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038850
struct ModelFileHeader Pdoor_roller3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038870
struct ModelFileHeader Pdoor_roller4Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038890
struct ModelFileHeader Pdoor_st_arec1Z_header = {0, &model_object_standard_object, 0, 0, 1, 763.03589, 0, 3, 0, 0};
//D:800388B0
struct ModelFileHeader Pdoor_st_arec2Z_header = {0, &model_object_standard_object, 0, 0, 1, 763.03589, 0, 3, 0, 0};
//D:800388D0
struct ModelFileHeader Pdoor_dest1Z_header = {0, &model_object_standard_object, 0, 0, 1, 461.3873, 0, 3, 0, 0};
//D:800388F0
struct ModelFileHeader Pdoor_dest2Z_header = {0, &model_object_standard_object, 0, 0, 1, 461.3873, 0, 5, 0, 0};
//D:80038910
struct ModelFileHeader Pgas_plant_sw_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.29706, 0, 4, 0, 0};
//D:80038930
struct ModelFileHeader Pgas_plant_sw2_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 0, 2, 0, 0};
//D:80038950
struct ModelFileHeader Pgas_plant_sw3_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 0, 2, 0, 0};
//D:80038970
struct ModelFileHeader Pgas_plant_sw4_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 0, 1, 0, 0};
//D:80038990
struct ModelFileHeader Pgas_plant_met1_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 0, 5, 0, 0};
//D:800389B0
struct ModelFileHeader Pgas_plant_wc_cub1Z_header = {0, &model_object_standard_object, 0, 0, 1, 783.8501, 0, 3, 0, 0};
//D:800389D0
struct ModelFileHeader Pgasplant_clear_doorZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 1025.0952, 0, 2, 0, 0};
//D:800389F0
struct ModelFileHeader Ptrain_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 456.99615, 0, 3, 0, 0};
//D:80038A10
struct ModelFileHeader Ptrain_door2Z_header = {0, &prop_door_related, 0, 0x4, 0x1, 445.98541, 0, 3, 0, 0};
//D:80038A30
struct ModelFileHeader Ptrain_door3Z_header = {0, &prop_door_related, 0, 0x4, 0x1, 445.98541, 0, 4, 0, 0};
//D:80038A50
struct ModelFileHeader Pdoor_eyelidZ_header = {0, &prop_eyelid_door_related, 0, 0x3, 0x3, 3165.4348, 0, 3, 0, 0};
//D:80038A70
struct ModelFileHeader Pdoor_irisZ_header = {0, &prop_iris_door_related, 0, 0xD, 0xD, 1621.3601, 0, 5, 0, 0};
//D:80038A90
struct ModelFileHeader PsevdoorwoodZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 851.62671, 0, 3, 0, 0};
//D:80038AB0
struct ModelFileHeader PsevdoorwindZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 851.62671, 0, 5, 0, 0};
//D:80038AD0
struct ModelFileHeader PsevdoornowindZ_header = {0, &model_object_standard_object, 0, 0, 1, 863.03766, 0, 2, 0, 0};
//D:80038AF0
struct ModelFileHeader PsevdoormetslideZ_header = {0, &model_object_standard_object, 0, 0, 1, 863.74707, 0, 2, 0, 0};
//D:80038B10
struct ModelFileHeader Pcryptdoor1aZ_header = {0, &model_object_standard_object, 0, 0, 1, 502.64923, 0, 2, 0, 0};
//D:80038B30
struct ModelFileHeader Pcryptdoor1bZ_header = {0, &model_object_standard_object, 0, 0, 1, 400.97537, 0, 2, 0, 0};
//D:80038B50
struct ModelFileHeader Pcryptdoor2aZ_header = {0, &model_object_standard_object, 0, 0, 1, 502.64923, 0, 2, 0, 0};
//D:80038B70
struct ModelFileHeader Pcryptdoor2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 400.97537, 0, 2, 0, 0};
//D:80038B90
struct ModelFileHeader Pcryptdoor3Z_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 0, 3, 0, 0};
//D:80038BB0
struct ModelFileHeader Pcryptdoor4Z_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 0, 1, 0, 0};
//D:80038BD0
struct ModelFileHeader PvertdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 1997.2246, 0, 5, 0, 0};
//D:80038BF0
struct ModelFileHeader PhatchdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 192.1653, 0, 1, 0, 0};
//D:80038C10
struct ModelFileHeader PdamgatedoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 308.36456, 0, 3, 0, 0};
//D:80038C30
struct ModelFileHeader PdamtundoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 127.89996, 0, 4, 0, 0};
//D:80038C50
struct ModelFileHeader PdamchaindoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 171.36655, 0, 2, 0, 0};
//D:80038C70
struct ModelFileHeader PsilotopdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 2675.3958, 0, 5, 0, 0};
//D:80038C90
struct ModelFileHeader Pdoorprison1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1062.0833, 0, 1, 0, 0};
//D:80038CB0
struct ModelFileHeader PdoorstatgateZ_header = {0, &model_object_standard_object, 0, 0, 1, 1503.9503, 0, 3, 0, 0};
//D:80038CD0
struct ModelFileHeader PchrkalashZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 403.53766, 0, 8, 0, 0};
//D:80038CF0
struct ModelFileHeader PchrgrenadelaunchZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 422.48355, 0, 7, 0, 0};
//D:80038D10
struct ModelFileHeader PchrknifeZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 245.14619, 0, 2, 0, 0};
//D:80038D30
struct ModelFileHeader PchrlaserZ_header = {0, &prop_weapon_related, 0, 0x3, 0x2, 444.66241, 0, 8, 0, 0};
//D:80038D50
struct ModelFileHeader Pchrm16Z_header = {0, &prop_weapon_related, 0, 0x3, 0x2, 964.01367, 0, 6, 0, 0};
//D:80038D70
struct ModelFileHeader Pchrmp5kZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 277.32227, 0, 9, 0, 0};
//D:80038D90
struct ModelFileHeader PchrrugerZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 246.72643, 0, 5, 0, 0};
//D:80038DB0
struct ModelFileHeader PchrwppkZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 125.79879, 0, 5, 0, 0};
//D:80038DD0
struct ModelFileHeader PchrshotgunZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 488.88385, 0, 8, 0, 0};
//D:80038DF0
struct ModelFileHeader PchrskorpionZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 183.37708, 0, 7, 0, 0};
//D:80038E10
struct ModelFileHeader PchrspectreZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 351.26923, 0, 6, 0, 0};
//D:80038E30
struct ModelFileHeader PchruziZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 265.11813, 0, 7, 0, 0};
//D:80038E50
struct ModelFileHeader PchrgrenadeZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 118.18749, 0, 2, 0, 0};
//D:80038E70
struct ModelFileHeader Pchrfnp90Z_header = {0, &prop_weapon_related, 0, 0x3, 0x2, 470.04633, 0, 7, 0, 0};
//D:80038E90
struct ModelFileHeader PchrbriefcaseZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80038EB0
struct ModelFileHeader PchrremotemineZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 87.434036, 0, 2, 0, 0};
//D:80038ED0
struct ModelFileHeader PchrproximitymineZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 87.196609, 0, 2, 0, 0};
//D:80038EF0
struct ModelFileHeader PchrtimedmineZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 87.245888, 0, 3, 0, 0};
//D:80038F10
struct ModelFileHeader PchrrocketZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.8634, 0, 3, 0, 0};
//D:80038F30
struct ModelFileHeader PchrgrenaderoundZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 96.976593, 0, 1, 0, 0};
//D:80038F50
struct ModelFileHeader PchrwppksilZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 219.44571, 0, 6, 0, 0};
//D:80038F70
struct ModelFileHeader Pchrtt33Z_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 142.11539, 0, 5, 0, 0};
//D:80038F90
struct ModelFileHeader Pchrmp5ksilZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 406.18033, 0, 0xA, 0, 0};
//D:80038FB0
struct ModelFileHeader PchrautoshotZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 375.50247, 0, 8, 0, 0};
//D:80038FD0
struct ModelFileHeader PchrgoldenZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 157.98299, 0, 2, 0, 0};
//D:80038FF0
struct ModelFileHeader PchrthrowknifeZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 217.61888, 0, 2, 0, 0};
//D:80039010
struct ModelFileHeader PchrsniperrifleZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 616.93939, 0, 5, 0, 0};
//D:80039030
struct ModelFileHeader PchrrocketlaunchZ_header = {0, &prop_weapon_related, 0, 0x3, 0x2, 501.55179, 0, 6, 0, 0};
//D:80039050
struct ModelFileHeader PhatfurryZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:80039070
struct ModelFileHeader PhatfurrybrownZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:80039090
struct ModelFileHeader PhatfurryblackZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:800390B0
struct ModelFileHeader PhattbirdZ_header = {0, &item_hat_related, 0, 0, 1, 114.45274, 0, 1, 0, 0};
//D:800390D0
struct ModelFileHeader PhattbirdbrownZ_header = {0, &item_hat_related, 0, 0, 1, 122.7013, 0, 1, 0, 0};
//D:800390F0
struct ModelFileHeader PhathelmetZ_header = {0, &item_hat_related, 0, 0, 1, 163.84476, 0, 1, 0, 0};
//D:80039110
struct ModelFileHeader PhathelmetgreyZ_header = {0, &item_hat_related, 0, 0, 1, 163.84476, 0, 1, 0, 0};
//D:80039130
struct ModelFileHeader PhatmoonZ_header = {0, &item_hat_related, 0, 0, 1, 138.25751, 0, 2, 0, 0};
//D:80039150
struct ModelFileHeader PhatberetZ_header = {0, &item_hat_related, 0, 0, 1, 116.16043, 0, 1, 0, 0};
//D:80039170
struct ModelFileHeader PhatberetblueZ_header = {0, &item_hat_related, 0, 0, 1, 116.16043, 0, 2, 0, 0};
//D:80039190
struct ModelFileHeader PhatberetredZ_header = {0, &item_hat_related, 0, 0, 1, 115.46455, 0, 2, 0, 0};
//D:800391B0
struct ModelFileHeader PhatpeakedZ_header = {0, &item_hat_related, 0, 0, 1, 148.39027, 0, 1, 0, 0};
//D:800391D0
struct ModelFileHeader PchrwristdartZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800391F0
struct ModelFileHeader PchrexplosivepenZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039210
struct ModelFileHeader PchrbombcaseZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039230
struct ModelFileHeader PchrflarepistolZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039250
struct ModelFileHeader PchrpitongunZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039270
struct ModelFileHeader PchrfingergunZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039290
struct ModelFileHeader PchrsilverwppkZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392B0
struct ModelFileHeader PchrgoldwppkZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392D0
struct ModelFileHeader PchrdynamiteZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392F0
struct ModelFileHeader PchrbungeeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039310
struct ModelFileHeader PchrdoordecoderZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 180.27969, 0, 0x10, 0, 0};
//D:80039330
struct ModelFileHeader PchrbombdefuserZ_header = {0, &model_object_standard_object, 0, 0, 1, 84.370705, 0, 0xC, 0, 0};
//D:80039350
struct ModelFileHeader PchrbugdetectorZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039370
struct ModelFileHeader PchrsafecrackercaseZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039390
struct ModelFileHeader PchrcameraZ_header = {0, &model_object_standard_object, 0, 0, 1, 52.775627, 0, 0xB, 0, 0};
//D:800393B0
struct ModelFileHeader PchrlockexploderZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800393D0
struct ModelFileHeader PchrdoorexploderZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800393F0
struct ModelFileHeader PchrkeyanalysercaseZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039410
struct ModelFileHeader PchrweaponcaseZ_header = {0, &model_object_standard_object, 0, 0, 1, 274.2905, 0, 5, 0, 0};
//D:80039430
struct ModelFileHeader PchrkeyyaleZ_header = {0, &model_object_standard_object, 0, 0, 1, 82.850311, 0, 1, 0, 0};
//D:80039450
struct ModelFileHeader PchrkeyboltZ_header = {0, &model_object_standard_object, 0, 0, 1, 151.85315, 0, 1, 0, 0};
//D:80039470
struct ModelFileHeader PchrbugZ_header = {0, &model_object_standard_object, 0, 0, 1, 104.7203, 0, 6, 0, 0};
//D:80039490
struct ModelFileHeader PchrmicrocameraZ_header = {0, &model_object_standard_object, 0, 0, 1, 126.49728, 0, 7, 0, 0};
//D:800394B0
struct ModelFileHeader PfloppyZ_header = {0, &model_object_standard_object, 0, 0, 1, 60.902443, 0, 5, 0, 0};
//D:800394D0
struct ModelFileHeader PchrgoldeneyekeyZ_header = {0, &model_object_standard_object, 0, 0, 1, 98.987083, 0, 5, 0, 0};
//D:800394F0
struct ModelFileHeader PchrpolarizedglassesZ_header = {0, &model_object_standard_object, 0, 0, 1, 53.776386, 0, 2, 0, 0};
//D:80039510
struct ModelFileHeader PchrcreditcardZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039530
struct ModelFileHeader PchrdarkglassesZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039550
struct ModelFileHeader PchrgaskeyringZ_header = {0, &model_object_standard_object, 0, 0, 1, 111.59859, 0, 9, 0, 0};
//D:80039570
struct ModelFileHeader PchrdatathiefZ_header = {0, &model_object_standard_object, 0, 0, 1, 119.78231, 0, 3, 0, 0};
//D:80039590
struct ModelFileHeader PsafeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1011.18744, 0, 3, 0, 0};
//D:800395B0
struct ModelFileHeader PbombZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800395D0
struct ModelFileHeader PchrplansZ_header = {0, &model_object_standard_object, 0, 0, 1, 384.74649, 0, 5, 0, 0};
//D:800395F0
struct ModelFileHeader PchrspyfileZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039610
struct ModelFileHeader PchrblueprintsZ_header = {0, &model_object_standard_object, 0, 0, 1, 588.65448, 0, 4, 0, 0};
//D:80039630
struct ModelFileHeader PchrcircuitboardZ_header = {0, &model_object_standard_object, 0, 0, 1, 138.90285, 0, 3, 0, 0};
//D:80039650
struct ModelFileHeader PchrmapZ_header = {0, &model_object_standard_object, 0, 0, 1, 588.65448, 0, 4, 0, 0};
//D:80039670
struct ModelFileHeader PchrspooltapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039690
struct ModelFileHeader PchraudiotapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 97.531075, 0, 9, 0, 0};
//D:800396B0
struct ModelFileHeader PchrmicrofilmZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800396D0
struct ModelFileHeader PchrmicrocodeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800396F0
struct ModelFileHeader PchrlectreZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039710
struct ModelFileHeader PchrmoneyZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039730
struct ModelFileHeader PchrgoldbarZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039750
struct ModelFileHeader PchrheroinZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039770
struct ModelFileHeader PchrclipboardZ_header = {0, &model_object_standard_object, 0, 0, 1, 190.41742, 0, 3, 0, 0};
//D:80039790
struct ModelFileHeader PchrdossierredZ_header = {0, &model_object_standard_object, 0, 0, 1, 183.54231, 0, 4, 0, 0};
//D:800397B0
struct ModelFileHeader PchrstafflistZ_header = {0, &model_object_standard_object, 0, 0, 1, 215.17534, 0, 4, 0, 0};
//D:800397D0
struct ModelFileHeader PchrdattapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 79.868584, 0, 4, 0, 0};
//D:800397F0
struct ModelFileHeader PchrplastiqueZ_header = {0, &model_object_standard_object, 0, 0, 1, 143.86052, 0, 3, 0, 0};
//D:80039810
struct ModelFileHeader PchrblackboxZ_header = {0, &model_object_standard_object, 0, 0, 1, 128.31796, 0, 5, 0, 0};
//D:80039830
struct ModelFileHeader PchrvideotapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 122.69632, 0, 9, 0, 0};
//D:80039850
struct ModelFileHeader PnintendologoZ_header = {0, &model_object_standard_object, 0, 0, 1, 1868.335, 0, 1, 0, 0};
//D:80039870
struct ModelFileHeader PgoldeneyelogoZ_header = {0, &model_object_standard_object, 0, 0, 1, 1287.1866, 0, 2, 0, 0};
//D:80039890
struct ModelFileHeader PwalletbondZ_header = {0, &prop_walletbond_related, 0, 0x2B, 0x1, 3504.53, 0, 0x54, 0, 0};
//D:800398B0
struct ModelFileHeader PmiltruckZ_header = {0, &prop_car_related, 0, 0xB, 0x5, 4589.7188, 0, 0x16, 0, 0};
//D:800398D0
struct ModelFileHeader PjeepZ_header = {0, &prop_car_related, 0, 0xB, 0x5, 2107.8105, 0, 0x10, 0, 0};
//D:800398F0
struct ModelFileHeader ParticZ_header = {0, &prop_car_related, 0, 0xB, 0x5, 2678.5667, 0x0, 0x11, 0, 0};
//D:80039910
struct ModelFileHeader PhelicopterZ_header = {0, &prop_flying_related, 0, 0x6, 0x4, 4955.271, 0, 0x18, 0, 0};
//D:80039930
struct ModelFileHeader PtigerZ_header = {0, &prop_flying_related, 0, 0x6, 0x4, 4072.0291, 0, 0xE, 0, 0};
//D:80039950
struct ModelFileHeader PmilcopterZ_header = {0, &prop_flying_related, 0, 0x6, 0x4, 5316.9155, 0, 0xF, 0, 0};
//D:80039970
struct ModelFileHeader PhindZ_header = {0, &prop_flying_related, 0, 0x6, 0x5, 5315.314, 0, 0xB, 0, 0};
//D:80039990
struct ModelFileHeader PartictrailerZ_header = {0, &model_object_standard_object, 0, 0, 1, 4014.6265, 0, 0xB, 0, 0};
//D:800399B0
struct ModelFileHeader PmotorbikeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1610.8706, 0, 6, 0, 0};
//D:800399D0
struct ModelFileHeader PtankZ_header = {0, &item_tank_related, 0, 0x9, 0x5, 6290.8398, 0, 0x18, 0, 0};
//D:800399F0
struct ModelFileHeader PapcZ_header = {0, &model_object_standard_object, 0, 0, 1, 3611.1035, 0, 0xE, 0, 0};
//D:80039A10
struct ModelFileHeader PspeedboatZ_header = {0, &model_object_standard_object, 0, 0, 1, 1799.4586, 0, 0xD, 0, 0};
//D:80039A30
struct ModelFileHeader PplaneZ_header = {0, &prop_flying_related, 0, 0x6, 0x3, 9285.4492, 0, 0x1C, 0, 0};
//D:80039A50
struct ModelFileHeader Pgun_runway1Z_header = {0, &prop_rotating_stuff_related, 0, 0x8, 0x5, 1927.5205, 0, 6, 0, 0};
//D:80039A70
struct ModelFileHeader PsafedoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 714.14612, 0, 4, 0, 0};
//D:80039A90
struct ModelFileHeader Pkey_holderZ_header = {0, &model_object_standard_object, 0, 0, 1, 223.87097, 0, 7, 0, 0};
//D:80039AB0
struct ModelFileHeader PhatchsevxZ_header = {0, &model_object_standard_object, 0, 0, 1, 1224.7664, 0, 2, 0, 0};
//D:80039AD0
struct ModelFileHeader PsevdishZ_header = {0, &prop_rotating_stuff_related, 0, 0x8, 0x3, 14350.1, 0, 7, 0, 0};
//D:80039AF0
struct ModelFileHeader Parchsecdoor1Z_header = {0, &model_object_standard_object, 0, 0, 1, 455.81409, 0, 3, 0, 0};
//D:80039B10
struct ModelFileHeader Parchsecdoor2Z_header = {0, &model_object_standard_object, 0, 0, 1, 496.99292, 0, 3, 0, 0};
//D:80039B30
struct ModelFileHeader PgroundgunZ_header = {0, &prop_rotating_stuff_related, 0, 0x8, 0x5, 2182.6472, 0, 4, 0, 0};
//D:80039B50
struct ModelFileHeader PtrainextdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 587.70111, 0, 5, 0, 0};
//D:80039B70
struct ModelFileHeader PcarbmwZ_header = {0, &model_object_standard_object, 0, 0, 1, 553.08728, 0, 0xB, 0, 0};
//D:80039B90
struct ModelFileHeader PcarescortZ_header = {0, &model_object_standard_object, 0, 0, 1, 1110.5665, 0, 9, 0, 0};
//D:80039BB0
struct ModelFileHeader PcargolfZ_header = {0, &model_object_standard_object, 0, 0, 1, 1121.6409, 0, 0xA, 0, 0};
//D:80039BD0
struct ModelFileHeader PcarweirdZ_header = {0, &model_object_standard_object, 0, 0, 1, 984.03931, 0, 0xD, 0, 0};
//D:80039BF0
struct ModelFileHeader PcarzilZ_header = {0, &prop_car_related, 0, 0xB, 0x5, 1044.5764, 0, 0xD, 0, 0};
//D:80039C10
struct ModelFileHeader Pshuttle_door_lZ_header = {0, &model_object_standard_object, 0, 0, 1, 706.56641, 0, 7, 0, 0};
//D:80039C30
struct ModelFileHeader Pshuttle_door_rZ_header = {0, &model_object_standard_object, 0, 0, 1, 706.56641, 0, 8, 0, 0};
//D:80039C50
struct ModelFileHeader Pdepot_gate_entryZ_header = {0, &model_object_standard_object, 0, 0, 1, 811.28949, 0, 3, 0, 0};
//D:80039C70
struct ModelFileHeader Pdepot_door_steelZ_header = {0, &model_object_standard_object, 0, 0, 1, 574.79651, 0, 3, 0, 0};
//D:80039C90
struct ModelFileHeader Pglassware2Z_header = {0, &model_object_standard_object, 0, 0, 1, 98.488579, 0, 3, 0, 0};
//D:80039CB0
struct ModelFileHeader Pglassware3Z_header = {0, &model_object_standard_object, 0, 0, 1, 137.92715, 0, 1, 0, 0};
//D:80039CD0
struct ModelFileHeader Pglassware4Z_header = {0, &model_object_standard_object, 0, 0, 1, 177.48241, 0, 2, 0, 0};
//D:80039CF0
struct ModelFileHeader PlandmineZ_header = {0, &model_object_standard_object, 0, 0, 1, 440.03009, 0, 2, 0, 0};
//D:80039D10
struct ModelFileHeader Pplant1Z_header = {0, &model_object_standard_object, 0, 0, 1, 2704.1086, 0, 1, 0, 0};
//D:80039D30
struct ModelFileHeader Pplant11Z_header = {0, &model_object_standard_object, 0, 0, 1, 2704.1086, 0, 1, 0, 0};
//D:80039D50
struct ModelFileHeader Pplant2Z_header = {0, &model_object_standard_object, 0, 0, 1, 3416.248, 0, 2, 0, 0};
//D:80039D70
struct ModelFileHeader Pplant3Z_header = {0, &model_object_standard_object, 0, 0, 1, 2986.0405, 0, 1, 0, 0};
//D:80039D90
struct ModelFileHeader Pjungle5_treeZ_header = {0, &model_object_standard_object, 0, 0, 1, 3277.6123, 0, 4, 0, 0};
//D:80039DB0
struct ModelFileHeader PlegalpageZ_header = {0, &model_object_standard_object, 0, 0, 1, 2711.7573, 0, 5, 0, 0};
//D:80039DD0
struct ModelFileHeader Pst_pete_room_1iZ_header = {0, &model_object_standard_object, 0, 0, 1, 8437.5137, 0, 0x17, 0, 0};
//D:80039DF0
struct ModelFileHeader Pst_pete_room_2iZ_header = {0, &model_object_standard_object, 0, 0, 1, 8515.8164, 0, 0x19, 0, 0};
//D:80039E10
struct ModelFileHeader Pst_pete_room_3tZ_header = {0, &model_object_standard_object, 0, 0, 1, 4561.9766, 0, 0x1B, 0, 0};
//D:80039E30
struct ModelFileHeader Pst_pete_room_5cZ_header = {0, &model_object_standard_object, 0, 0, 1, 4561.9766, 0, 0x19, 0, 0};
//D:80039E50
struct ModelFileHeader Pst_pete_room_6cZ_header = {0, &model_object_standard_object, 0, 0, 1, 5006.2896, 0, 0x17, 0, 0};
//D:80039E70
struct ModelFileHeader Pdoor_rollertrainZ_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 2, 0, 0};
//D:80039E90
struct ModelFileHeader Pdoor_winZ_header = {0, &model_object_standard_object, 0, 0, 1, 211.90215, 0, 1, 0, 0};
//D:80039EB0
struct ModelFileHeader Pdoor_aztecZ_header = {0, &model_object_standard_object, 0, 0, 1, 632.48639, 0, 1, 0, 0};
//D:80039ED0
struct ModelFileHeader PshuttleZ_header = {0, &model_object_standard_object, 0, 0, 1, 4475.1494, 0, 9, 0, 0};
//D:80039EF0
struct ModelFileHeader Pdoor_azt_deskZ_header = {0, &model_object_standard_object, 0, 0, 1, 860.41669, 0, 2, 0, 0};
//D:80039F10
struct ModelFileHeader Pdoor_azt_desk_topZ_header = {0, &model_object_standard_object, 0, 0, 1, 565.93268, 0, 3, 0, 0};
//D:80039F30
struct ModelFileHeader Pdoor_azt_chairZ_header = {0, &model_object_standard_object, 0, 0, 1, 94.510803, 0, 3, 0, 0};
//D:80039F50
struct ModelFileHeader Pdoor_mfZ_header = {0, &model_object_standard_object, 0, 0, 1, 559.70367, 0, 7, 0, 0};
//D:80039F70
struct ModelFileHeader PflagZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 862.30865, 0, 2, 0, 0};
//D:80039F90
struct ModelFileHeader PbarricadeZ_header = {0, &model_object_standard_object, 0, 0, 1, 2047.3016, 0, 2, 0, 0};
//D:80039FB0
struct ModelFileHeader PmodemboxZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 338.28839, 0, 4, 0, 0};
//D:80039FD0
struct ModelFileHeader PdoorpanelZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 338.28839, 0, 4, 0, 0};
//D:80039FF0
struct ModelFileHeader PdoorconsoleZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 994.23688, 0, 0xD, 0, 0};
//D:8003A010
struct ModelFileHeader PchrtesttubeZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 136.25925, 0, 2, 0, 0};
//D:8003A030
struct ModelFileHeader Pbollardz_header = {0, &model_object_standard_object, 0, 0, 1, 628.78754, 0, 1, 0, 0};

//D:8003A050
ModelJoint word_D_8003A050[2] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003}
};
//D:8003A05C
ModelSkeleton prop_cctv_related = {2, 0, word_D_8003A050, 6, 0};

//D:8003A068
ModelJoint word_D_8003A068[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A06E                     .half 0

//D:8003A070
ModelSkeleton prop_console_one_screen_related = {1, 0, word_D_8003A068, 3, 0};

//D:8003A07C
ModelJoint word_D_8003A07C[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A082                     .half 0

//D:8003A084
ModelSkeleton prop_console_four_screen_related = {1, 0, word_D_8003A07C, 3, 0};

//D:8003A090
ModelJoint word_D_8003A090[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A0AE                     .half 0

//D:8003A0B0
ModelSkeleton prop_tv_holder_related = {5, 0, word_D_8003A090, 0xF, 0};

//D:8003A0BC
ModelJoint word_D_8003A0BC[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003A0E0
ModelSkeleton prop_rotating_stuff_related = {6, 0, word_D_8003A0BC, 0x12, 0};

//D:8003A0EC
ModelJoint word_D_8003A0EC[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006}
};
//D:8003A0FE                     .half 0
//D:8003A100
ModelSkeleton prop_eyelid_door_related = {3, 0, word_D_8003A0EC, 9, 0};

//D:8003A10C
ModelJoint word_D_8003A10C[] = {
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
ModelSkeleton prop_iris_door_related = {0xD, 0, word_D_8003A10C, 0x27, 0};

//D:8003A168
ModelJoint word_D_8003A168[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A16E                     .half 0
//D:8003A170
ModelSkeleton prop_walletbond_related = {1, 0, word_D_8003A168, 3, 0};

//D:8003A17C
ModelJoint word_D_8003A17C[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A19C
ModelSkeleton prop_car_related = {5, 0, word_D_8003A17C, 0xF, 0};

//D:8003A1A8
ModelJoint word_D_8003A1A8[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0015, 0x0003, 0x0003},
    {0x0015, 0x0004, 0x0004},
    {0x0015, 0x0005, 0x0005}
};
//D:8003A1C6                     .half 0
//D:8003A1C8
ModelSkeleton prop_flying_related = {5, 0, word_D_8003A1A8, 3, 0};

//D:8003A1D4
ModelJoint word_D_8003A1D4[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A1DA                     .half 0
//D:8003A1DC
ModelSkeleton prop_door_related = {1, 0, word_D_8003A1D4, 3, 0};

//D:8003A1E8
ModelJoint word_D_8003A1E8[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A206                     .half 0
//D:8003A208
ModelSkeleton item_tank_related = {5, 0, word_D_8003A1E8, 0xF, 0};

//D:8003A214
ModelJoint word_D_8003A214[] = {
    {0x0015, 0x0000, 0x0000},
};
//D:8003A21A                     .half 0
//D:8003A21C
ModelSkeleton item_hat_related = {1, 0, word_D_8003A214, 0, 0};

//D:8003A228                     .globl PitemZ_entries
ItemModelFileRecord PitemZ_entries[] = {
    {&Palarm1z_header, "Palarm1Z", 0.1},
    {&Palarm2Z_header, "Palarm2Z", 0.1},
    {&PexplosionbitZ_header, "PexplosionbitZ", 0.1},
    {&Pammo_crate1Z_header, "Pammo_crate1Z", 0.1},
    {&Pammo_crate2Z_header, "Pammo_crate2Z", 0.1},
    {&Pammo_crate3Z_header, "Pammo_crate3Z", 0.1},
    {&Pammo_crate4Z_header, "Pammo_crate4Z", 0.1},
    {&Pammo_crate5Z_header, "Pammo_crate5Z", 0.1},
    {&Pbin1Z_header, "Pbin1Z", 0.1},
    {&Pblotter1Z_header, "Pblotter1Z", 0.1},
    {&Pbook1Z_header, "Pbook1Z", 0.1},
    {&Pbookshelf1Z_header, "Pbookshelf1Z", 0.1},
    {&Pbridge_console1aZ_header, "Pbridge_console1aZ", 0.1},
    {&Pbridge_console1bZ_header, "Pbridge_console1bZ", 0.1},
    {&Pbridge_console2aZ_header, "Pbridge_console2aZ", 0.1},
    {&Pbridge_console2bZ_header, "Pbridge_console2bZ", 0.1},
    {&Pbridge_console3aZ_header, "Pbridge_console3aZ", 0.1},
    {&Pbridge_console3bZ_header, "Pbridge_console3bZ", 0.1},
    {&Pcard_box1Z_header, "Pcard_box1Z", 0.1},
    {&Pcard_box2Z_header, "Pcard_box2Z", 0.1},
    {&Pcard_box3Z_header, "Pcard_box3Z", 0.1},
    {&Pcard_box4_lgZ_header, "Pcard_box4_lgZ", 0.1},
    {&Pcard_box5_lgZ_header, "Pcard_box5_lgZ", 0.1},
    {&Pcard_box6_lgZ_header, "Pcard_box6_lgZ", 0.1},
    {&PcctvZ_header, "PcctvZ", 0.1},
    {&Pconsole1Z_header, "Pconsole1Z", 0.1},
    {&Pconsole2Z_header, "Pconsole2Z", 0.1},
    {&Pconsole3Z_header, "Pconsole3Z", 0.1},
    {&Pconsole_sevaZ_header, "Pconsole_sevaZ", 0.1},
    {&Pconsole_sevbZ_header, "Pconsole_sevbZ", 0.1},
    {&Pconsole_sevcZ_header, "Pconsole_sevcZ", 0.1},
    {&Pconsole_sevdZ_header, "Pconsole_sevdZ", 0.1},
    {&Pconsole_sev2aZ_header, "Pconsole_sev2aZ", 0.1},
    {&Pconsole_sev2bZ_header, "Pconsole_sev2bZ", 0.1},
    {&Pconsole_sev2cZ_header, "Pconsole_sev2cZ", 0.1},
    {&Pconsole_sev2dZ_header, "Pconsole_sev2dZ", 0.1},
    {&Pconsole_sev_GEaZ_header, "Pconsole_sev_GEaZ", 0.1},
    {&Pconsole_sev_GEbZ_header, "Pconsole_sev_GEbZ", 0.1},
    {&Pdesk1Z_header, "Pdesk1Z", 0.1},
    {&Pdesk2Z_header, "Pdesk2Z", 0.1},
    {&Pdesk_lamp2Z_header, "Pdesk_lamp2Z", 0.1},
    {&Pdisc_readerZ_header, "Pdisc_readerZ", 0.1},
    {&Pdisk_drive1Z_header, "Pdisk_drive1Z", 0.1},
    {&Pfiling_cabinet1Z_header, "Pfiling_cabinet1Z", 0.1},
    {&Pjerry_can1Z_header, "Pjerry_can1Z", 0.1},
    {&Pkeyboard1Z_header, "Pkeyboard1Z", 0.1},
    {&Pkit_units1Z_header, "Pkit_units1Z", 0.1},
    {&Pletter_tray1Z_header, "Pletter_tray1Z", 0.1},
    {&Pmainframe1Z_header, "Pmainframe1Z", 0.1},
    {&Pmainframe2Z_header, "Pmainframe2Z", 0.1},
    {&Pmetal_chair1Z_header, "Pmetal_chair1Z", 0.1},
    {&Pmetal_crate1Z_header, "Pmetal_crate1Z", 0.1},
    {&Pmetal_crate2Z_header, "Pmetal_crate2Z", 0.1},
    {&Pmetal_crate3Z_header, "Pmetal_crate3Z", 0.1},
    {&Pmetal_crate4Z_header, "Pmetal_crate4Z", 0.1},
    {&Pmissile_rackZ_header, "Pmissile_rackZ", 0.1},
    {&Pmissile_rack2Z_header, "Pmissile_rack2Z", 0.1},
    {&Poil_drum1Z_header, "Poil_drum1Z", 0.1},
    {&Poil_drum2Z_header, "Poil_drum2Z", 0.1},
    {&Poil_drum3Z_header, "Poil_drum3Z", 0.1},
    {&Poil_drum5Z_header, "Poil_drum5Z", 0.1},
    {&Poil_drum6Z_header, "Poil_drum6Z", 0.1},
    {&Poil_drum7Z_header, "Poil_drum7Z", 0.1},
    {&PpadlockZ_header, "PpadlockZ", 0.1},
    {&Pphone1Z_header, "Pphone1Z", 0.1},
    {&Pradio_unit1Z_header, "Pradio_unit1Z", 0.1},
    {&Pradio_unit2Z_header, "Pradio_unit2Z", 0.1},
    {&Pradio_unit3Z_header, "Pradio_unit3Z", 0.1},
    {&Pradio_unit4Z_header, "Pradio_unit4Z", 0.1},
    {&Psat1_reflectZ_header, "Psat1_reflectZ", 0.1},
    {&PsatdishZ_header, "PsatdishZ", 0.1},
    {&PsatboxZ_header, "PsatboxZ", 0.1},
    {&Pstool1Z_header, "Pstool1Z", 0.1},
    {&Pswivel_chair1Z_header, "Pswivel_chair1Z", 0.1},
    {&Ptorpedo_rackZ_header, "Ptorpedo_rackZ", 0.1},
    {&Ptv1Z_header, "Ptv1Z", 0.1},
    {&Ptv_holderZ_header, "Ptv_holderZ", 0.1},
    {&PtvscreenZ_header, "PtvscreenZ", 0.1},
    {&Ptv4screenZ_header, "Ptv4screenZ", 0.1},
    {&Pwood_lg_crate1Z_header, "Pwood_lg_crate1Z", 0.1},
    {&Pwood_lg_crate2Z_header, "Pwood_lg_crate2Z", 0.1},
    {&Pwood_md_crate3Z_header, "Pwood_md_crate3Z", 0.1},
    {&Pwood_sm_crate4Z_header, "Pwood_sm_crate4Z", 0.1},
    {&Pwood_sm_crate5Z_header, "Pwood_sm_crate5Z", 0.1},
    {&Pwood_sm_crate6Z_header, "Pwood_sm_crate6Z", 0.1},
    {&Pwooden_table1Z_header, "Pwooden_table1Z", 0.1},
    {&Pswipe_card2Z_header, "Pswipe_card2Z", 0.1},
    {&Pborg_crateZ_header, "Pborg_crateZ", 0.1},
    {&Pboxes4x4Z_header, "Pboxes4x4Z", 0.1},
    {&Pboxes3x4Z_header, "Pboxes3x4Z", 0.1},
    {&Pboxes2x4Z_header, "Pboxes2x4Z", 0.1},
    {&Psec_panelZ_header, "Psec_panelZ", 0.1},
    {&PICBM_noseZ_header, "PICBM_noseZ", 0.1},
    {&PICBMZ_header, "PICBMZ", 0.1},
    {&Ptuning_console1Z_header, "Ptuning_console1Z", 0.1},
    {&Pdesk_arecibo1Z_header, "Pdesk_arecibo1Z", 0.1},
    {&Plocker3Z_header, "Plocker3Z", 0.1},
    {&Plocker4Z_header, "Plocker4Z", 0.1},
    {&ProofgunZ_header, "ProofgunZ", 0.1},
    {&Pdest_engineZ_header, "Pdest_engineZ", 0.1},
    {&Pdest_exocetZ_header, "Pdest_exocetZ", 0.1},
    {&Pdest_gunZ_header, "Pdest_gunZ", 0.1},
    {&Pdest_harpoonZ_header, "Pdest_harpoonZ", 0.1},
    {&Pdest_seawolfZ_header, "Pdest_seawolfZ", 0.1},
    {&PwindowZ_header, "PwindowZ", 0.1},
    {&Pwindow_lib_lg1Z_header, "Pwindow_lib_lg1Z", 0.1},
    {&Pwindow_lib_sm1Z_header, "Pwindow_lib_sm1Z", 0.1},
    {&Pwindow_cor11Z_header, "Pwindow_cor11Z", 0.1},
    {&Pjungle3_treeZ_header, "Pjungle3_treeZ", 0.1},
    {&PpalmZ_header, "PpalmZ", 0.1},
    {&PpalmtreeZ_header, "PpalmtreeZ", 0.1},
    {&Pplant2bZ_header, "Pplant2bZ", 0.1},
    {&PlabbenchZ_header, "PlabbenchZ", 0.1},
    {&PgasbarrelZ_header, "PgasbarrelZ", 0.1},
    {&PgasbarrelsZ_header, "PgasbarrelsZ", 0.1},
    {&PbodyarmourZ_header, "PbodyarmourZ", 0.1},
    {&PbodyarmourvestZ_header, "PbodyarmourvestZ", 0.1},
    {&PgastankZ_header, "PgastankZ", 0.1},
    {&Pglassware1Z_header, "Pglassware1Z", 0.1},
    {&PhatchboltZ_header, "PhatchboltZ", 0.1},
    {&PbrakeunitZ_header, "PbrakeunitZ", 0.1},
    {&Pak47magZ_header, "Pak47magZ", 0.1},
    {&Pm16magZ_header, "Pm16magZ", 0.1},
    {&Pmp5kmagZ_header, "Pmp5kmagZ", 0.1},
    {&PskorpionmagZ_header, "PskorpionmagZ", 0.1},
    {&PspectremagZ_header, "PspectremagZ", 0.1},
    {&PuzimagZ_header, "PuzimagZ", 0.1},
    {&PsilencerZ_header, "PsilencerZ", 0.1},
    {&PchrextinguisherZ_header, "PchrextinguisherZ", 0.1},
    {&PboxcartridgesZ_header, "PboxcartridgesZ", 0.1},
    {&Pfnp90magZ_header, "Pfnp90magZ", 0.1},
    {&PgoldenshellsZ_header, "PgoldenshellsZ", 0.1},
    {&PmagnumshellsZ_header, "PmagnumshellsZ", 0.1},
    {&PwppkmagZ_header, "PwppkmagZ", 0.1},
    {&Ptt33magZ_header, "Ptt33magZ", 0.1},
    {&Psev_doorZ_header, "Psev_doorZ", 1.0},
    {&Psev_door3Z_header, "Psev_door3Z", 1.0},
    {&Psev_door3_windZ_header, "Psev_door3_windZ", 1.0},
    {&Psev_door4_windZ_header, "Psev_door4_windZ", 1.0},
    {&Psev_trislideZ_header, "Psev_trislideZ", 1.0},
    {&Psev_door_v1Z_header, "Psev_door_v1Z", 1.0},
    {&Psteel_door1Z_header, "Psteel_door1Z", 1.0},
    {&Psteel_door2Z_header, "Psteel_door2Z", 1.0},
    {&Psteel_door3Z_header, "Psteel_door3Z", 1.0},
    {&Psilo_lift_doorZ_header, "Psilo_lift_doorZ", 1.0},
    {&Psteel_door2bZ_header, "Psteel_door2bZ", 1.0},
    {&Pdoor_roller1Z_header, "Pdoor_roller1Z", 1.0},
    {&Pdoor_roller2Z_header, "Pdoor_roller2Z", 1.0},
    {&Pdoor_roller3Z_header, "Pdoor_roller3Z", 1.0},
    {&Pdoor_roller4Z_header, "Pdoor_roller4Z", 1.0},
    {&Pdoor_st_arec1Z_header, "Pdoor_st_arec1Z", 1.0},
    {&Pdoor_st_arec2Z_header, "Pdoor_st_arec2Z", 1.0},
    {&Pdoor_dest1Z_header, "Pdoor_dest1Z", 1.0},
    {&Pdoor_dest2Z_header, "Pdoor_dest2Z", 1.0},
    {&Pgas_plant_sw_do1Z_header, "Pgas_plant_sw_do1Z", 1.0},
    {&Pgas_plant_sw2_do1Z_header, "Pgas_plant_sw2_do1Z", 1.0},
    {&Pgas_plant_sw3_do1Z_header, "Pgas_plant_sw3_do1Z", 1.0},
    {&Pgas_plant_sw4_do1Z_header, "Pgas_plant_sw4_do1Z", 1.0},
    {&Pgas_plant_met1_do1Z_header, "Pgas_plant_met1_do1Z", 1.0},
    {&Pgas_plant_wc_cub1Z_header, "Pgas_plant_wc_cub1Z", 1.0},
    {&Pgasplant_clear_doorZ_header, "Pgasplant_clear_doorZ", 1.0},
    {&Ptrain_doorZ_header, "Ptrain_doorZ", 1.0},
    {&Ptrain_door2Z_header, "Ptrain_door2Z", 1.0},
    {&Ptrain_door3Z_header, "Ptrain_door3Z", 1.0},
    {&Pdoor_eyelidZ_header, "Pdoor_eyelidZ", 1.0},
    {&Pdoor_irisZ_header, "Pdoor_irisZ", 1.0},
    {&PsevdoorwoodZ_header, "PsevdoorwoodZ", 1.0},
    {&PsevdoorwindZ_header, "PsevdoorwindZ", 1.0},
    {&PsevdoornowindZ_header, "PsevdoornowindZ", 1.0},
    {&PsevdoormetslideZ_header, "PsevdoormetslideZ", 1.0},
    {&Pcryptdoor1aZ_header, "Pcryptdoor1aZ", 1.0},
    {&Pcryptdoor1bZ_header, "Pcryptdoor1bZ", 1.0},
    {&Pcryptdoor2aZ_header, "Pcryptdoor2aZ", 1.0},
    {&Pcryptdoor2bZ_header, "Pcryptdoor2bZ", 1.0},
    {&Pcryptdoor3Z_header, "Pcryptdoor3Z", 1.0},
    {&Pcryptdoor4Z_header, "Pcryptdoor4Z", 1.0},
    {&PvertdoorZ_header, "PvertdoorZ", 1.0},
    {&PhatchdoorZ_header, "PhatchdoorZ", 1.0},
    {&PdamgatedoorZ_header, "PdamgatedoorZ", 1.0},
    {&PdamtundoorZ_header, "PdamtundoorZ", 1.0},
    {&PdamchaindoorZ_header, "PdamchaindoorZ", 1.0},
    {&PsilotopdoorZ_header, "PsilotopdoorZ", 1.0},
    {&Pdoorprison1Z_header, "Pdoorprison1Z", 1.0},
    {&PdoorstatgateZ_header, "PdoorstatgateZ", 1.0},
    {&PchrkalashZ_header, "PchrkalashZ", 0.1},
    {&PchrgrenadelaunchZ_header, "PchrgrenadelaunchZ", 0.1},
    {&PchrknifeZ_header, "PchrknifeZ", 0.1},
    {&PchrlaserZ_header, "PchrlaserZ", 0.1},
    {&Pchrm16Z_header, "Pchrm16Z", 0.1},
    {&Pchrmp5kZ_header, "Pchrmp5kZ", 0.1},
    {&PchrrugerZ_header, "PchrrugerZ", 0.1},
    {&PchrwppkZ_header, "PchrwppkZ", 0.1},
    {&PchrshotgunZ_header, "PchrshotgunZ", 0.1},
    {&PchrskorpionZ_header, "PchrskorpionZ", 0.1},
    {&PchrspectreZ_header, "PchrspectreZ", 0.1},
    {&PchruziZ_header, "PchruziZ", 0.1},
    {&PchrgrenadeZ_header, "PchrgrenadeZ", 0.1},
    {&Pchrfnp90Z_header, "Pchrfnp90Z", 0.1},
    {&PchrbriefcaseZ_header, "PchrbriefcaseZ", 0.1},
    {&PchrremotemineZ_header, "PchrremotemineZ", 0.1},
    {&PchrproximitymineZ_header, "PchrproximitymineZ", 0.1},
    {&PchrtimedmineZ_header, "PchrtimedmineZ", 0.1},
    {&PchrrocketZ_header, "PchrrocketZ", 0.1},
    {&PchrgrenaderoundZ_header, "PchrgrenaderoundZ", 0.1},
    {&PchrwppksilZ_header, "PchrwppksilZ", 0.1},
    {&Pchrtt33Z_header, "Pchrtt33Z", 0.1},
    {&Pchrmp5ksilZ_header, "Pchrmp5ksilZ", 0.1},
    {&PchrautoshotZ_header, "PchrautoshotZ", 0.1},
    {&PchrgoldenZ_header, "PchrgoldenZ", 0.1},
    {&PchrthrowknifeZ_header, "PchrthrowknifeZ", 0.1},
    {&PchrsniperrifleZ_header, "PchrsniperrifleZ", 0.1},
    {&PchrrocketlaunchZ_header, "PchrrocketlaunchZ", 0.1},
    {&PhatfurryZ_header, "PhatfurryZ", 0.1},
    {&PhatfurrybrownZ_header, "PhatfurrybrownZ", 0.1},
    {&PhatfurryblackZ_header, "PhatfurryblackZ", 0.1},
    {&PhattbirdZ_header, "PhattbirdZ", 0.1},
    {&PhattbirdbrownZ_header, "PhattbirdbrownZ", 0.1},
    {&PhathelmetZ_header, "PhathelmetZ", 0.1},
    {&PhathelmetgreyZ_header, "PhathelmetgreyZ", 0.1},
    {&PhatmoonZ_header, "PhatmoonZ", 0.1},
    {&PhatberetZ_header, "PhatberetZ", 0.1},
    {&PhatberetblueZ_header, "PhatberetblueZ", 0.1},
    {&PhatberetredZ_header, "PhatberetredZ", 0.1},
    {&PhatpeakedZ_header, "PhatpeakedZ", 0.1},
    {&PchrwristdartZ_header, "PchrwristdartZ", 0.1},
    {&PchrexplosivepenZ_header, "PchrexplosivepenZ", 0.1},
    {&PchrbombcaseZ_header, "PchrbombcaseZ", 0.1},
    {&PchrflarepistolZ_header, "PchrflarepistolZ", 0.1},
    {&PchrpitongunZ_header, "PchrpitongunZ", 0.1},
    {&PchrfingergunZ_header, "PchrfingergunZ", 0.1},
    {&PchrsilverwppkZ_header, "PchrsilverwppkZ", 0.1},
    {&PchrgoldwppkZ_header, "PchrgoldwppkZ", 0.1},
    {&PchrdynamiteZ_header, "PchrdynamiteZ", 0.1},
    {&PchrbungeeZ_header, "PchrbungeeZ", 0.1},
    {&PchrdoordecoderZ_header, "PchrdoordecoderZ", 0.1},
    {&PchrbombdefuserZ_header, "PchrbombdefuserZ", 0.1},
    {&PchrbugdetectorZ_header, "PchrbugdetectorZ", 0.1},
    {&PchrsafecrackercaseZ_header, "PchrsafecrackercaseZ", 0.1},
    {&PchrcameraZ_header, "PchrcameraZ", 0.1},
    {&PchrlockexploderZ_header, "PchrlockexploderZ", 0.1},
    {&PchrdoorexploderZ_header, "PchrdoorexploderZ", 0.1},
    {&PchrkeyanalysercaseZ_header, "PchrkeyanalysercaseZ", 0.1},
    {&PchrweaponcaseZ_header, "PchrweaponcaseZ", 0.1},
    {&PchrkeyyaleZ_header, "PchrkeyyaleZ", 0.1},
    {&PchrkeyboltZ_header, "PchrkeyboltZ", 0.1},
    {&PchrbugZ_header, "PchrbugZ", 0.1},
    {&PchrmicrocameraZ_header, "PchrmicrocameraZ", 0.1},
    {&PfloppyZ_header, "PfloppyZ", 0.1},
    {&PchrgoldeneyekeyZ_header, "PchrgoldeneyekeyZ", 0.1},
    {&PchrpolarizedglassesZ_header, "PchrpolarizedglassesZ", 0.1},
    {&PchrcreditcardZ_header, "PchrcreditcardZ", 0.1},
    {&PchrdarkglassesZ_header, "PchrdarkglassesZ", 0.1},
    {&PchrgaskeyringZ_header, "PchrgaskeyringZ", 0.1},
    {&PchrdatathiefZ_header, "PchrdatathiefZ", 0.1},
    {&PsafeZ_header, "PsafeZ", 0.1},
    {&PbombZ_header, "PbombZ", 0.1},
    {&PchrplansZ_header, "PchrplansZ", 0.1},
    {&PchrspyfileZ_header, "PchrspyfileZ", 0.1},
    {&PchrblueprintsZ_header, "PchrblueprintsZ", 0.1},
    {&PchrcircuitboardZ_header, "PchrcircuitboardZ", 0.1},
    {&PchrmapZ_header, "PchrmapZ", 0.1},
    {&PchrspooltapeZ_header, "PchrspooltapeZ", 0.1},
    {&PchraudiotapeZ_header, "PchraudiotapeZ", 0.1},
    {&PchrmicrofilmZ_header, "PchrmicrofilmZ", 0.1},
    {&PchrmicrocodeZ_header, "PchrmicrocodeZ", 0.1},
    {&PchrlectreZ_header, "PchrlectreZ", 0.1},
    {&PchrmoneyZ_header, "PchrmoneyZ", 0.1},
    {&PchrgoldbarZ_header, "PchrgoldbarZ", 0.1},
    {&PchrheroinZ_header, "PchrheroinZ", 0.1},
    {&PchrclipboardZ_header, "PchrclipboardZ", 0.1},
    {&PchrdossierredZ_header, "PchrdossierredZ", 0.1},
    {&PchrstafflistZ_header, "PchrstafflistZ", 0.1},
    {&PchrdattapeZ_header, "PchrdattapeZ", 0.1},
    {&PchrplastiqueZ_header, "PchrplastiqueZ", 0.1},
    {&PchrblackboxZ_header, "PchrblackboxZ", 0.1},
    {&PchrvideotapeZ_header, "PchrvideotapeZ", 0.1},
    {&PnintendologoZ_header, "PnintendologoZ", 0.1},
    {&PgoldeneyelogoZ_header, "PgoldeneyelogoZ", 0.1},
    {&PwalletbondZ_header, "PwalletbondZ", 0.1},
    {&PmiltruckZ_header, "PmiltruckZ", 0.1},
    {&PjeepZ_header, "PjeepZ", 0.1},
    {&ParticZ_header, "ParticZ", 0.1},
    {&PhelicopterZ_header, "PhelicopterZ", 0.1},
    {&PtigerZ_header, "PtigerZ", 0.1},
    {&PmilcopterZ_header, "PmilcopterZ", 0.1},
    {&PhindZ_header, "PhindZ", 0.1},
    {&PartictrailerZ_header, "PartictrailerZ", 0.1},
    {&PmotorbikeZ_header, "PmotorbikeZ", 0.1},
    {&PtankZ_header, "PtankZ", 0.1},
    {&PapcZ_header, "PapcZ", 0.1},
    {&PspeedboatZ_header, "PspeedboatZ", 0.1},
    {&PplaneZ_header, "PplaneZ", 0.1},
    {&Pgun_runway1Z_header, "Pgun_runway1Z", 0.1},
    {&PsafedoorZ_header, "PsafedoorZ", 1.0},
    {&Pkey_holderZ_header, "Pkey_holderZ", 1.0},
    {&PhatchsevxZ_header, "PhatchsevxZ", 1.0},
    {&PsevdishZ_header, "PsevdishZ", 1.0},
    {&Parchsecdoor1Z_header, "Parchsecdoor1Z", 1.0},
    {&Parchsecdoor2Z_header, "Parchsecdoor2Z", 1.0},
    {&PgroundgunZ_header, "PgroundgunZ", 0.1},
    {&PtrainextdoorZ_header, "PtrainextdoorZ", 1.0},
    {&PcarbmwZ_header, "PcarbmwZ", 0.1},
    {&PcarescortZ_header, "PcarescortZ", 0.1},
    {&PcargolfZ_header, "PcargolfZ", 0.1},
    {&PcarweirdZ_header, "PcarweirdZ", 0.1},
    {&PcarzilZ_header, "PcarzilZ", 0.1},
    {&Pshuttle_door_lZ_header, "Pshuttle_door_lZ", 1.0},
    {&Pshuttle_door_rZ_header, "Pshuttle_door_rZ", 1.0},
    {&Pdepot_gate_entryZ_header, "Pdepot_gate_entryZ", 0.1},
    {&Pdepot_door_steelZ_header, "Pdepot_door_steelZ", 0.1},
    {&Pglassware2Z_header, "Pglassware2Z", 0.1},
    {&Pglassware3Z_header, "Pglassware3Z", 0.1},
    {&Pglassware4Z_header, "Pglassware4Z", 0.1},
    {&PlandmineZ_header, "PlandmineZ", 0.1},
    {&Pplant1Z_header, "Pplant1Z", 0.1},
    {&Pplant11Z_header, "Pplant11Z", 0.1},
    {&Pplant2Z_header, "Pplant2Z", 0.1},
    {&Pplant3Z_header, "Pplant3Z", 0.1},
    {&Pjungle5_treeZ_header, "Pjungle5_treeZ", 0.1},
    {&PlegalpageZ_header, "PlegalpageZ", 0.1},
    {&Pst_pete_room_1iZ_header, "Pst_pete_room_1iZ", 0.1},
    {&Pst_pete_room_2iZ_header, "Pst_pete_room_2iZ", 0.1},
    {&Pst_pete_room_3tZ_header, "Pst_pete_room_3tZ", 0.1},
    {&Pst_pete_room_5cZ_header, "Pst_pete_room_5cZ", 0.1},
    {&Pst_pete_room_6cZ_header, "Pst_pete_room_6cZ", 0.1},
    {&Pdoor_rollertrainZ_header, "Pdoor_rollertrainZ", 1.0},
    {&Pdoor_winZ_header, "Pdoor_winZ", 1.0},
    {&Pdoor_aztecZ_header, "Pdoor_aztecZ", 1.0},
    {&PshuttleZ_header, "PshuttleZ", 0.1},
    {&Pdoor_azt_deskZ_header, "Pdoor_azt_deskZ", 1.0},
    {&Pdoor_azt_desk_topZ_header, "Pdoor_azt_desk_topZ", 1.0},
    {&Pdoor_azt_chairZ_header, "Pdoor_azt_chairZ", 1.0},
    {&Pdoor_mfZ_header, "Pdoor_mfZ", 1.0},
    {&PflagZ_header, "PflagZ", 0.1},
    {&PbarricadeZ_header, "PbarricadeZ", 0.1},
    {&PmodemboxZ_header, "PmodemboxZ", 0.1},
    {&PdoorpanelZ_header, "PdoorpanelZ", 0.1},
    {&PdoorconsoleZ_header, "PdoorconsoleZ", 0.1},
    {&PchrtesttubeZ_header, "PchrtesttubeZ", 0.1},
    {&Pbollardz_header, "PbollardZ", 0.1},
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

