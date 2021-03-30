#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"

//D:800375D0
struct PitemZ_header Palarm1z_header = {0, &model_object_standard_object, 0, 0, 1, 304.6402, 0, 2, 0, 0};
//D:800375F0
struct PitemZ_header Palarm2Z_header = {0, &model_object_standard_object, 0, 0, 1, 208.22205, 0, 3, 0, 0};
//D:80037610
struct PitemZ_header PexplosionbitZ_header = {0, &model_object_standard_object, 0, 0, 1, 208.22205, 0, 0, 0, 0};
//D:80037630
struct PitemZ_header Pammo_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 3, 0, 0};
//D:80037650
struct PitemZ_header Pammo_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 4, 0, 0};
//D:80037670
struct PitemZ_header Pammo_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 4, 0, 0};
//D:80037690
struct PitemZ_header Pammo_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 5, 0, 0};
//D:800376B0
struct PitemZ_header Pammo_crate5Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 0, 5, 0, 0};
//D:800376D0
struct PitemZ_header Pbin1Z_header = {0, &model_object_standard_object, 0, 0, 1, 3027.6262,0, 2, 0, 0};
//D:800376F0
struct PitemZ_header Pblotter1Z_header = {0, &model_object_standard_object, 0, 0, 1, 432.46707, 0, 1, 0, 0};
//D:80037710
struct PitemZ_header Pbook1Z_header = {0, &model_object_standard_object, 0, 0, 1, 171.37482, 0, 2, 0, 0};
//D:80037730
struct PitemZ_header Pbookshelf1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1166.7578, 0, 0xD, 0, 0};
//D:80037750
struct PitemZ_header Pbridge_console1aZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:80037770
struct PitemZ_header Pbridge_console1bZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 788.03992, 0, 0x10, 0, 0};
//D:80037790
struct PitemZ_header Pbridge_console2aZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:800377B0
struct PitemZ_header Pbridge_console2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 788.03992, 0, 0xF, 0, 0};
//D:800377D0
struct PitemZ_header Pbridge_console3aZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 788.03992, 0, 0xF, 0, 0};
//D:800377F0
struct PitemZ_header Pbridge_console3bZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 788.03992, 0, 0x10, 0, 0};
//D:80037810
struct PitemZ_header Pcard_box1Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 5, 0, 0};
//D:80037830
struct PitemZ_header Pcard_box2Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 6, 0, 0};
//D:80037850
struct PitemZ_header Pcard_box3Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 5, 0, 0};
//D:80037870
struct PitemZ_header Pcard_box4_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 0, 4, 0, 0};
//D:80037890
struct PitemZ_header Pcard_box5_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 0, 5, 0, 0};
//D:800378B0
struct PitemZ_header Pcard_box6_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 0, 5, 0, 0};
//D:800378D0
struct PitemZ_header PcctvZ_header = {0, &prop_cctv_related, 0, 0x4, 0x2, 558.90094, 0, 6, 0, 0};
//D:800378F0
struct PitemZ_header Pconsole1Z_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037910
struct PitemZ_header Pconsole2Z_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037930
struct PitemZ_header Pconsole3Z_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 1611.2357, 0, 0xA, 0, 0};
//D:80037950
struct PitemZ_header Pconsole_sevaZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xE, 0, 0};
//D:80037970
struct PitemZ_header Pconsole_sevbZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 994.23688, 0, 0xB, 0, 0};
//D:80037990
struct PitemZ_header Pconsole_sevcZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xF, 0, 0};
//D:800379B0
struct PitemZ_header Pconsole_sevdZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:800379D0
struct PitemZ_header Pconsole_sev2aZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:800379F0
struct PitemZ_header Pconsole_sev2bZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 994.23688, 0, 0xD, 0, 0};
//D:80037A10
struct PitemZ_header Pconsole_sev2cZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xF, 0, 0};
//D:80037A30
struct PitemZ_header Pconsole_sev2dZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A50
struct PitemZ_header Pconsole_sev_GEaZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A70
struct PitemZ_header Pconsole_sev_GEbZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0, 0xD, 0, 0};
//D:80037A90
struct PitemZ_header Pdesk1Z_header = {0, &model_object_standard_object, 0, 0, 1, 957.18225, 0, 3, 0, 0};
//D:80037AB0
struct PitemZ_header Pdesk2Z_header = {0, &model_object_standard_object, 0, 0, 1, 957.18225, 0, 3, 0, 0};
//D:80037AD0
struct PitemZ_header Pdesk_lamp2Z_header = {0, &model_object_standard_object, 0, 0, 1, 804.59833, 0, 4, 0, 0};
//D:80037AF0
struct PitemZ_header Pdisc_readerZ_header = {0, &model_object_standard_object, 0, 0, 1, 214.33035, 0, 6, 0, 0};
//D:80037B10
struct PitemZ_header Pdisk_drive1Z_header = {0, &model_object_standard_object, 0, 0, 1, 191.85779, 0, 4, 0, 0};
//D:80037B30
struct PitemZ_header Pfiling_cabinet1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1055.5693, 0, 2, 0, 0};
//D:80037B50
struct PitemZ_header Pjerry_can1Z_header = {0, &model_object_standard_object, 0, 0, 1, 366.61932, 0, 4, 0, 0};
//D:80037B70
struct PitemZ_header Pkeyboard1Z_header = {0, &model_object_standard_object, 0, 0, 1, 278.23227, 0, 2, 0, 0};
//D:80037B90
struct PitemZ_header Pkit_units1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1661.4763, 0, 4, 0, 0};
//D:80037BB0
struct PitemZ_header Pletter_tray1Z_header = {0, &model_object_standard_object, 0, 0, 1, 252.06836, 0, 1, 0, 0};
//D:80037BD0
struct PitemZ_header Pmainframe1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1119.4073, 0, 7, 0, 0};
//D:80037BF0
struct PitemZ_header Pmainframe2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1119.4073, 0, 7, 0, 0};
//D:80037C10
struct PitemZ_header Pmetal_chair1Z_header = {0, &model_object_standard_object, 0, 0, 1, 639.18097, 0, 2, 0, 0};
//D:80037C30
struct PitemZ_header Pmetal_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037C50
struct PitemZ_header Pmetal_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037C70
struct PitemZ_header Pmetal_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 2, 0, 0};
//D:80037C90
struct PitemZ_header Pmetal_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037CB0
struct PitemZ_header Pmissile_rackZ_header = {0, &model_object_standard_object, 0, 0, 1, 964.16296, 0, 4, 0, 0};
//D:80037CD0
struct PitemZ_header Pmissile_rack2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1148.4724, 0, 4, 0, 0};
//D:80037CF0
struct PitemZ_header Poil_drum1Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 2, 0, 0};
//D:80037D10
struct PitemZ_header Poil_drum2Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037D30
struct PitemZ_header Poil_drum3Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037D50
struct PitemZ_header Poil_drum5Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 3, 0, 0};
//D:80037D70
struct PitemZ_header Poil_drum6Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 3, 0, 0};
//D:80037D90
struct PitemZ_header Poil_drum7Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 0, 4, 0, 0};
//D:80037DB0
struct PitemZ_header PpadlockZ_header = {0, &model_object_standard_object, 0, 0, 1, 225.64145, 0, 4, 0, 0};
//D:80037DD0
struct PitemZ_header Pphone1Z_header = {0, &model_object_standard_object, 0, 0, 1, 166.03481, 0, 2, 0, 0};
//D:80037DF0
struct PitemZ_header Pradio_unit1Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E10
struct PitemZ_header Pradio_unit2Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E30
struct PitemZ_header Pradio_unit3Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E50
struct PitemZ_header Pradio_unit4Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 0, 5, 0, 0};
//D:80037E70
struct PitemZ_header Psat1_reflectZ_header = {0, &model_object_standard_object, 0, 0, 1, 5185.9409, 0, 0xD, 0, 0};
//D:80037E90
struct PitemZ_header PsatdishZ_header = {0, &model_object_standard_object, 0, 0, 1, 2437.468, 0, 2, 0, 0};
//D:80037EB0
struct PitemZ_header PsatboxZ_header = {0, &model_object_standard_object, 0, 0, 1, 89.935875, 0, 1, 0, 0};
//D:80037ED0
struct PitemZ_header Pstool1Z_header = {0, &model_object_standard_object, 0, 0, 1, 353.11398, 0, 2, 0, 0};
//D:80037EF0
struct PitemZ_header Pswivel_chair1Z_header = {0, &model_object_standard_object, 0, 0, 1, 581.16394, 0, 3, 0, 0};
//D:80037F10
struct PitemZ_header Ptorpedo_rackZ_header = {0, &model_object_standard_object, 0, 0, 1, 765.61725, 0, 3, 0, 0};
//D:80037F30
struct PitemZ_header Ptv1Z_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 347.0235, 0, 5, 0, 0};
//D:80037F50
struct PitemZ_header Ptv_holderZ_header = {0, &prop_tv_holder_related, 0, 0x4, 0x5, 1352.4841, 0, 2, 0, 0};
//D:80037F70
struct PitemZ_header PtvscreenZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 211.74477, 0, 1, 0, 0};
//D:80037F90
struct PitemZ_header Ptv4screenZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 211.74477, 0, 1, 0, 0};
//D:80037FB0
struct PitemZ_header Pwood_lg_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 3, 0, 0};
//D:80037FD0
struct PitemZ_header Pwood_lg_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 2, 0, 0};
//D:80037FF0
struct PitemZ_header Pwood_md_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 909.32666, 0, 2, 0, 0};
//D:80038010
struct PitemZ_header Pwood_sm_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 3, 0, 0};
//D:80038030
struct PitemZ_header Pwood_sm_crate5Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 4, 0, 0};
//D:80038050
struct PitemZ_header Pwood_sm_crate6Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 0, 4, 0, 0};
//D:80038070
struct PitemZ_header Pwooden_table1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1095.1365, 0, 2, 0, 0};
//D:80038090
struct PitemZ_header Pswipe_card2Z_header = {0, &model_object_standard_object, 0, 0, 1, 123.088844, 0, 2, 0, 0};
//D:800380B0
struct PitemZ_header Pborg_crateZ_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 0, 1, 0, 0};
//D:800380D0
struct PitemZ_header Pboxes4x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2424.8711, 0, 7, 0, 0};
//D:800380F0
struct PitemZ_header Pboxes3x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2241.0935, 0, 6, 0, 0};
//D:80038110
struct PitemZ_header Pboxes2x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2100.0, 0, 6, 0, 0};
//D:80038130
struct PitemZ_header Psec_panelZ_header = {0, &model_object_standard_object, 0, 0, 1, 1567.2454, 0, 3, 0, 0};
//D:80038150
struct PitemZ_header PICBM_noseZ_header = {0, &model_object_standard_object, 0, 0, 1, 2782.7126, 0, 8, 0, 0};
//D:80038170
struct PitemZ_header PICBMZ_header = {0, &model_object_standard_object, 0, 0, 1, 14790.535, 0, 0xE, 0, 0};
//D:80038190
struct PitemZ_header Ptuning_console1Z_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 1139.5872, 0, 0xE, 0, 0};
//D:800381B0
struct PitemZ_header Pdesk_arecibo1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1829.1477, 0, 3, 0, 0};
//D:800381D0
struct PitemZ_header Plocker3Z_header = {0, &model_object_standard_object, 0, 0, 1, 916.99805, 0, 3, 0, 0};
//D:800381F0
struct PitemZ_header Plocker4Z_header = {0, &model_object_standard_object, 0, 0, 1, 916.99805, 0, 3, 0, 0};
//D:80038210
struct PitemZ_header ProofgunZ_header = {0, &prop_rotating_stuff_related, 0, 0x8, 0x5, 1910.908, 0, 0xE, 0, 0};
//D:80038230
struct PitemZ_header Pdest_engineZ_header = {0, &model_object_standard_object, 0, 0, 1, 6459.439, 0, 0xA, 0, 0};
//D:80038250
struct PitemZ_header Pdest_exocetZ_header = {0, &model_object_standard_object, 0, 0, 1, 1644.8435, 0, 8, 0, 0};
//D:80038270
struct PitemZ_header Pdest_gunZ_header = {0, &model_object_standard_object, 0, 0, 1, 2124.0735, 0, 5, 0, 0};
//D:80038290
struct PitemZ_header Pdest_harpoonZ_header = {0, &model_object_standard_object, 0, 0, 1, 1798.7655, 0, 5, 0, 0};
//D:800382B0
struct PitemZ_header Pdest_seawolfZ_header = {0, &model_object_standard_object, 0, 0, 1, 2282.0623, 0, 0xA, 0, 0};
//D:800382D0
struct PitemZ_header PwindowZ_header = {0, &model_object_standard_object, 0, 0, 1, 423.48956, 0, 1, 0, 0};
//D:800382F0
struct PitemZ_header Pwindow_lib_lg1Z_header = {0, &model_object_standard_object, 0, 0, 1, 835.20624, 0, 1, 0, 0};
//D:80038310
struct PitemZ_header Pwindow_lib_sm1Z_header = {0, &model_object_standard_object, 0, 0, 1, 601.28625, 0, 1, 0, 0};
//D:80038330
struct PitemZ_header Pwindow_cor11Z_header = {0, &model_object_standard_object, 0, 0, 1, 414.53622, 0, 1, 0, 0};
//D:80038350
struct PitemZ_header Pjungle3_treeZ_header = {0, &model_object_standard_object, 0, 0, 1, 28729.467, 0, 5, 0, 0};
//D:80038370
struct PitemZ_header PpalmZ_header = {0, &model_object_standard_object, 0, 0, 1, 15501.406, 0, 3, 0, 0};
//D:80038390
struct PitemZ_header PpalmtreeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1781.4542, 0, 2, 0, 0};
//D:800383B0
struct PitemZ_header Pplant2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 1252.9539, 0, 2, 0, 0};
//D:800383D0
struct PitemZ_header PlabbenchZ_header = {0, &model_object_standard_object, 0, 0, 1, 844.09717, 0, 4, 0, 0};
//D:800383F0
struct PitemZ_header PgasbarrelZ_header = {0, &model_object_standard_object, 0, 0, 1, 725.94379, 0, 2, 0, 0};
//D:80038410
struct PitemZ_header PgasbarrelsZ_header = {0, &model_object_standard_object, 0, 0, 1, 1174.1927, 0, 2, 0, 0};
//D:80038430
struct PitemZ_header PbodyarmourZ_header = {0, &model_object_standard_object, 0, 0, 1, 246.94099, 0, 7, 0, 0};
//D:80038450
struct PitemZ_header PbodyarmourvestZ_header = {0, &model_object_standard_object, 0, 0, 1, 241.82211, 0, 2, 0, 0};
//D:80038470
struct PitemZ_header PgastankZ_header = {0, &model_object_standard_object, 0, 0, 1, 1130.0691, 0, 5, 0, 0};
//D:80038490
struct PitemZ_header Pglassware1Z_header = {0, &model_object_standard_object, 0, 0, 1, 72.111031, 0, 1, 0, 0};
//D:800384B0
struct PitemZ_header PhatchboltZ_header = {0, &model_object_standard_object, 0, 0, 1, 2236.0679, 0, 1, 0, 0};
//D:800384D0
struct PitemZ_header PbrakeunitZ_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 0, 4, 0, 0};
//D:800384F0
struct PitemZ_header Pak47magZ_header = {0, &model_object_standard_object, 0, 0, 1, 107.11019, 0, 2, 0, 0};
//D:80038510
struct PitemZ_header Pm16magZ_header = {0, &model_object_standard_object, 0, 0, 1, 87.934891, 0, 2, 0, 0};
//D:80038530
struct PitemZ_header Pmp5kmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 119.547295, 0, 2, 0, 0};
//D:80038550
struct PitemZ_header PskorpionmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 58.428444, 0, 2, 0, 0};
//D:80038570
struct PitemZ_header PspectremagZ_header = {0, &model_object_standard_object, 0, 0, 1, 99.01432, 0, 2, 0, 0};
//D:80038590
struct PitemZ_header PuzimagZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:800385B0
struct PitemZ_header PsilencerZ_header = {0, &model_object_standard_object, 0, 0, 1, 63.915436, 0, 3, 0, 0};
//D:800385D0
struct PitemZ_header PchrextinguisherZ_header = {0, &model_object_standard_object, 0, 0, 1, 425.50903, 0, 2, 0, 0};
//D:800385F0
struct PitemZ_header PboxcartridgesZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038610
struct PitemZ_header Pfnp90magZ_header = {0, &model_object_standard_object, 0, 0, 1, 176.28201, 0, 2, 0, 0};
//D:80038630
struct PitemZ_header PgoldenshellsZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038650
struct PitemZ_header PmagnumshellsZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 0, 3, 0, 0};
//D:80038670
struct PitemZ_header PwppkmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:80038690
struct PitemZ_header Ptt33magZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 0, 2, 0, 0};
//D:800386B0
struct PitemZ_header Psev_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 1143.7695, 0, 3, 0, 0};
//D:800386D0
struct PitemZ_header Psev_door3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1143.5603, 0, 6, 0, 0};
//D:800386F0
struct PitemZ_header Psev_door3_windZ_header = {0, &model_object_standard_object, 0, 0, 1, 1143.5603, 0, 5, 0, 0};
//D:80038710
struct PitemZ_header Psev_door4_windZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 1143.5603, 0, 8, 0, 0};
//D:80038730
struct PitemZ_header Psev_trislideZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 950.54327, 0, 2, 0, 0};
//D:80038750
struct PitemZ_header Psev_door_v1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 6, 0, 0};
//D:80038770
struct PitemZ_header Psteel_door1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 4, 0, 0};
//D:80038790
struct PitemZ_header Psteel_door2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:800387B0
struct PitemZ_header Psteel_door3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:800387D0
struct PitemZ_header Psilo_lift_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 600.71082, 0, 4, 0, 0};
//D:800387F0
struct PitemZ_header Psteel_door2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 0, 9, 0, 0};
//D:80038810
struct PitemZ_header Pdoor_roller1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038830
struct PitemZ_header Pdoor_roller2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038850
struct PitemZ_header Pdoor_roller3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038870
struct PitemZ_header Pdoor_roller4Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 4, 0, 0};
//D:80038890
struct PitemZ_header Pdoor_st_arec1Z_header = {0, &model_object_standard_object, 0, 0, 1, 763.03589, 0, 3, 0, 0};
//D:800388B0
struct PitemZ_header Pdoor_st_arec2Z_header = {0, &model_object_standard_object, 0, 0, 1, 763.03589, 0, 3, 0, 0};
//D:800388D0
struct PitemZ_header Pdoor_dest1Z_header = {0, &model_object_standard_object, 0, 0, 1, 461.3873, 0, 3, 0, 0};
//D:800388F0
struct PitemZ_header Pdoor_dest2Z_header = {0, &model_object_standard_object, 0, 0, 1, 461.3873, 0, 5, 0, 0};
//D:80038910
struct PitemZ_header Pgas_plant_sw_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.29706, 0, 4, 0, 0};
//D:80038930
struct PitemZ_header Pgas_plant_sw2_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 0, 2, 0, 0};
//D:80038950
struct PitemZ_header Pgas_plant_sw3_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 0, 2, 0, 0};
//D:80038970
struct PitemZ_header Pgas_plant_sw4_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 0, 1, 0, 0};
//D:80038990
struct PitemZ_header Pgas_plant_met1_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 0, 5, 0, 0};
//D:800389B0
struct PitemZ_header Pgas_plant_wc_cub1Z_header = {0, &model_object_standard_object, 0, 0, 1, 783.8501, 0, 3, 0, 0};
//D:800389D0
struct PitemZ_header Pgasplant_clear_doorZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 1025.0952, 0, 2, 0, 0};
//D:800389F0
struct PitemZ_header Ptrain_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 456.99615, 0, 3, 0, 0};
//D:80038A10
struct PitemZ_header Ptrain_door2Z_header = {0, &prop_door_related, 0, 0x4, 0x1, 445.98541, 0, 3, 0, 0};
//D:80038A30
struct PitemZ_header Ptrain_door3Z_header = {0, &prop_door_related, 0, 0x4, 0x1, 445.98541, 0, 4, 0, 0};
//D:80038A50
struct PitemZ_header Pdoor_eyelidZ_header = {0, &prop_eyelid_door_related, 0, 0x3, 0x3, 3165.4348, 0, 3, 0, 0};
//D:80038A70
struct PitemZ_header Pdoor_irisZ_header = {0, &prop_iris_door_related, 0, 0xD, 0xD, 1621.3601, 0, 5, 0, 0};
//D:80038A90
struct PitemZ_header PsevdoorwoodZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 851.62671, 0, 3, 0, 0};
//D:80038AB0
struct PitemZ_header PsevdoorwindZ_header = {0, &prop_door_related, 0, 0x4, 0x1, 851.62671, 0, 5, 0, 0};
//D:80038AD0
struct PitemZ_header PsevdoornowindZ_header = {0, &model_object_standard_object, 0, 0, 1, 863.03766, 0, 2, 0, 0};
//D:80038AF0
struct PitemZ_header PsevdoormetslideZ_header = {0, &model_object_standard_object, 0, 0, 1, 863.74707, 0, 2, 0, 0};
//D:80038B10
struct PitemZ_header Pcryptdoor1aZ_header = {0, &model_object_standard_object, 0, 0, 1, 502.64923, 0, 2, 0, 0};
//D:80038B30
struct PitemZ_header Pcryptdoor1bZ_header = {0, &model_object_standard_object, 0, 0, 1, 400.97537, 0, 2, 0, 0};
//D:80038B50
struct PitemZ_header Pcryptdoor2aZ_header = {0, &model_object_standard_object, 0, 0, 1, 502.64923, 0, 2, 0, 0};
//D:80038B70
struct PitemZ_header Pcryptdoor2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 400.97537, 0, 2, 0, 0};
//D:80038B90
struct PitemZ_header Pcryptdoor3Z_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 0, 3, 0, 0};
//D:80038BB0
struct PitemZ_header Pcryptdoor4Z_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 0, 1, 0, 0};
//D:80038BD0
struct PitemZ_header PvertdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 1997.2246, 0, 5, 0, 0};
//D:80038BF0
struct PitemZ_header PhatchdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 192.1653, 0, 1, 0, 0};
//D:80038C10
struct PitemZ_header PdamgatedoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 308.36456, 0, 3, 0, 0};
//D:80038C30
struct PitemZ_header PdamtundoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 127.89996, 0, 4, 0, 0};
//D:80038C50
struct PitemZ_header PdamchaindoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 171.36655, 0, 2, 0, 0};
//D:80038C70
struct PitemZ_header PsilotopdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 2675.3958, 0, 5, 0, 0};
//D:80038C90
struct PitemZ_header Pdoorprison1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1062.0833, 0, 1, 0, 0};
//D:80038CB0
struct PitemZ_header PdoorstatgateZ_header = {0, &model_object_standard_object, 0, 0, 1, 1503.9503, 0, 3, 0, 0};
//D:80038CD0
struct PitemZ_header PchrkalashZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 403.53766, 0, 8, 0, 0};
//D:80038CF0
struct PitemZ_header PchrgrenadelaunchZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 422.48355, 0, 7, 0, 0};
//D:80038D10
struct PitemZ_header PchrknifeZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 245.14619, 0, 2, 0, 0};
//D:80038D30
struct PitemZ_header PchrlaserZ_header = {0, &prop_weapon_related, 0, 0x3, 0x2, 444.66241, 0, 8, 0, 0};
//D:80038D50
struct PitemZ_header Pchrm16Z_header = {0, &prop_weapon_related, 0, 0x3, 0x2, 964.01367, 0, 6, 0, 0};
//D:80038D70
struct PitemZ_header Pchrmp5kZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 277.32227, 0, 9, 0, 0};
//D:80038D90
struct PitemZ_header PchrrugerZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 246.72643, 0, 5, 0, 0};
//D:80038DB0
struct PitemZ_header PchrwppkZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 125.79879, 0, 5, 0, 0};
//D:80038DD0
struct PitemZ_header PchrshotgunZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 488.88385, 0, 8, 0, 0};
//D:80038DF0
struct PitemZ_header PchrskorpionZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 183.37708, 0, 7, 0, 0};
//D:80038E10
struct PitemZ_header PchrspectreZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 351.26923, 0, 6, 0, 0};
//D:80038E30
struct PitemZ_header PchruziZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 265.11813, 0, 7, 0, 0};
//D:80038E50
struct PitemZ_header PchrgrenadeZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 118.18749, 0, 2, 0, 0};
//D:80038E70
struct PitemZ_header Pchrfnp90Z_header = {0, &prop_weapon_related, 0, 0x3, 0x2, 470.04633, 0, 7, 0, 0};
//D:80038E90
struct PitemZ_header PchrbriefcaseZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80038EB0
struct PitemZ_header PchrremotemineZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 87.434036, 0, 2, 0, 0};
//D:80038ED0
struct PitemZ_header PchrproximitymineZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 87.196609, 0, 2, 0, 0};
//D:80038EF0
struct PitemZ_header PchrtimedmineZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 87.245888, 0, 3, 0, 0};
//D:80038F10
struct PitemZ_header PchrrocketZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.8634, 0, 3, 0, 0};
//D:80038F30
struct PitemZ_header PchrgrenaderoundZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 96.976593, 0, 1, 0, 0};
//D:80038F50
struct PitemZ_header PchrwppksilZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 219.44571, 0, 6, 0, 0};
//D:80038F70
struct PitemZ_header Pchrtt33Z_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 142.11539, 0, 5, 0, 0};
//D:80038F90
struct PitemZ_header Pchrmp5ksilZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 406.18033, 0, 0xA, 0, 0};
//D:80038FB0
struct PitemZ_header PchrautoshotZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 375.50247, 0, 8, 0, 0};
//D:80038FD0
struct PitemZ_header PchrgoldenZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 157.98299, 0, 2, 0, 0};
//D:80038FF0
struct PitemZ_header PchrthrowknifeZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 217.61888, 0, 2, 0, 0};
//D:80039010
struct PitemZ_header PchrsniperrifleZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 616.93939, 0, 5, 0, 0};
//D:80039030
struct PitemZ_header PchrrocketlaunchZ_header = {0, &prop_weapon_related, 0, 0x3, 0x2, 501.55179, 0, 6, 0, 0};
//D:80039050
struct PitemZ_header PhatfurryZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:80039070
struct PitemZ_header PhatfurrybrownZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:80039090
struct PitemZ_header PhatfurryblackZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 0, 3, 0, 0};
//D:800390B0
struct PitemZ_header PhattbirdZ_header = {0, &item_hat_related, 0, 0, 1, 114.45274, 0, 1, 0, 0};
//D:800390D0
struct PitemZ_header PhattbirdbrownZ_header = {0, &item_hat_related, 0, 0, 1, 122.7013, 0, 1, 0, 0};
//D:800390F0
struct PitemZ_header PhathelmetZ_header = {0, &item_hat_related, 0, 0, 1, 163.84476, 0, 1, 0, 0};
//D:80039110
struct PitemZ_header PhathelmetgreyZ_header = {0, &item_hat_related, 0, 0, 1, 163.84476, 0, 1, 0, 0};
//D:80039130
struct PitemZ_header PhatmoonZ_header = {0, &item_hat_related, 0, 0, 1, 138.25751, 0, 2, 0, 0};
//D:80039150
struct PitemZ_header PhatberetZ_header = {0, &item_hat_related, 0, 0, 1, 116.16043, 0, 1, 0, 0};
//D:80039170
struct PitemZ_header PhatberetblueZ_header = {0, &item_hat_related, 0, 0, 1, 116.16043, 0, 2, 0, 0};
//D:80039190
struct PitemZ_header PhatberetredZ_header = {0, &item_hat_related, 0, 0, 1, 115.46455, 0, 2, 0, 0};
//D:800391B0
struct PitemZ_header PhatpeakedZ_header = {0, &item_hat_related, 0, 0, 1, 148.39027, 0, 1, 0, 0};
//D:800391D0
struct PitemZ_header PchrwristdartZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800391F0
struct PitemZ_header PchrexplosivepenZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039210
struct PitemZ_header PchrbombcaseZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039230
struct PitemZ_header PchrflarepistolZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039250
struct PitemZ_header PchrpitongunZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039270
struct PitemZ_header PchrfingergunZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039290
struct PitemZ_header PchrsilverwppkZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392B0
struct PitemZ_header PchrgoldwppkZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392D0
struct PitemZ_header PchrdynamiteZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800392F0
struct PitemZ_header PchrbungeeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039310
struct PitemZ_header PchrdoordecoderZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 180.27969, 0, 0x10, 0, 0};
//D:80039330
struct PitemZ_header PchrbombdefuserZ_header = {0, &model_object_standard_object, 0, 0, 1, 84.370705, 0, 0xC, 0, 0};
//D:80039350
struct PitemZ_header PchrbugdetectorZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039370
struct PitemZ_header PchrsafecrackercaseZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039390
struct PitemZ_header PchrcameraZ_header = {0, &model_object_standard_object, 0, 0, 1, 52.775627, 0, 0xB, 0, 0};
//D:800393B0
struct PitemZ_header PchrlockexploderZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800393D0
struct PitemZ_header PchrdoorexploderZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800393F0
struct PitemZ_header PchrkeyanalysercaseZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 342.23688, 0, 5, 0, 0};
//D:80039410
struct PitemZ_header PchrweaponcaseZ_header = {0, &model_object_standard_object, 0, 0, 1, 274.2905, 0, 5, 0, 0};
//D:80039430
struct PitemZ_header PchrkeyyaleZ_header = {0, &model_object_standard_object, 0, 0, 1, 82.850311, 0, 1, 0, 0};
//D:80039450
struct PitemZ_header PchrkeyboltZ_header = {0, &model_object_standard_object, 0, 0, 1, 151.85315, 0, 1, 0, 0};
//D:80039470
struct PitemZ_header PchrbugZ_header = {0, &model_object_standard_object, 0, 0, 1, 104.7203, 0, 6, 0, 0};
//D:80039490
struct PitemZ_header PchrmicrocameraZ_header = {0, &model_object_standard_object, 0, 0, 1, 126.49728, 0, 7, 0, 0};
//D:800394B0
struct PitemZ_header PfloppyZ_header = {0, &model_object_standard_object, 0, 0, 1, 60.902443, 0, 5, 0, 0};
//D:800394D0
struct PitemZ_header PchrgoldeneyekeyZ_header = {0, &model_object_standard_object, 0, 0, 1, 98.987083, 0, 5, 0, 0};
//D:800394F0
struct PitemZ_header PchrpolarizedglassesZ_header = {0, &model_object_standard_object, 0, 0, 1, 53.776386, 0, 2, 0, 0};
//D:80039510
struct PitemZ_header PchrcreditcardZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039530
struct PitemZ_header PchrdarkglassesZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039550
struct PitemZ_header PchrgaskeyringZ_header = {0, &model_object_standard_object, 0, 0, 1, 111.59859, 0, 9, 0, 0};
//D:80039570
struct PitemZ_header PchrdatathiefZ_header = {0, &model_object_standard_object, 0, 0, 1, 119.78231, 0, 3, 0, 0};
//D:80039590
struct PitemZ_header PsafeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1011.18744, 0, 3, 0, 0};
//D:800395B0
struct PitemZ_header PbombZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800395D0
struct PitemZ_header PchrplansZ_header = {0, &model_object_standard_object, 0, 0, 1, 384.74649, 0, 5, 0, 0};
//D:800395F0
struct PitemZ_header PchrspyfileZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039610
struct PitemZ_header PchrblueprintsZ_header = {0, &model_object_standard_object, 0, 0, 1, 588.65448, 0, 4, 0, 0};
//D:80039630
struct PitemZ_header PchrcircuitboardZ_header = {0, &model_object_standard_object, 0, 0, 1, 138.90285, 0, 3, 0, 0};
//D:80039650
struct PitemZ_header PchrmapZ_header = {0, &model_object_standard_object, 0, 0, 1, 588.65448, 0, 4, 0, 0};
//D:80039670
struct PitemZ_header PchrspooltapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039690
struct PitemZ_header PchraudiotapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 97.531075, 0, 9, 0, 0};
//D:800396B0
struct PitemZ_header PchrmicrofilmZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800396D0
struct PitemZ_header PchrmicrocodeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:800396F0
struct PitemZ_header PchrlectreZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039710
struct PitemZ_header PchrmoneyZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039730
struct PitemZ_header PchrgoldbarZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039750
struct PitemZ_header PchrheroinZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 0, 1, 0, 0};
//D:80039770
struct PitemZ_header PchrclipboardZ_header = {0, &model_object_standard_object, 0, 0, 1, 190.41742, 0, 3, 0, 0};
//D:80039790
struct PitemZ_header PchrdossierredZ_header = {0, &model_object_standard_object, 0, 0, 1, 183.54231, 0, 4, 0, 0};
//D:800397B0
struct PitemZ_header PchrstafflistZ_header = {0, &model_object_standard_object, 0, 0, 1, 215.17534, 0, 4, 0, 0};
//D:800397D0
struct PitemZ_header PchrdattapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 79.868584, 0, 4, 0, 0};
//D:800397F0
struct PitemZ_header PchrplastiqueZ_header = {0, &model_object_standard_object, 0, 0, 1, 143.86052, 0, 3, 0, 0};
//D:80039810
struct PitemZ_header PchrblackboxZ_header = {0, &model_object_standard_object, 0, 0, 1, 128.31796, 0, 5, 0, 0};
//D:80039830
struct PitemZ_header PchrvideotapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 122.69632, 0, 9, 0, 0};
//D:80039850
struct PitemZ_header PnintendologoZ_header = {0, &model_object_standard_object, 0, 0, 1, 1868.335, 0, 1, 0, 0};
//D:80039870
struct PitemZ_header PgoldeneyelogoZ_header = {0, &model_object_standard_object, 0, 0, 1, 1287.1866, 0, 2, 0, 0};
//D:80039890
struct PitemZ_header PwalletbondZ_header = {0, &prop_walletbond_related, 0, 0x2B, 0x1, 3504.53, 0, 0x54, 0, 0};
//D:800398B0
struct PitemZ_header PmiltruckZ_header = {0, &prop_car_related, 0, 0xB, 0x5, 4589.7188, 0, 0x16, 0, 0};
//D:800398D0
struct PitemZ_header PjeepZ_header = {0, &prop_car_related, 0, 0xB, 0x5, 2107.8105, 0, 0x10, 0, 0};
//D:800398F0
struct PitemZ_header ParticZ_header = {0, &prop_car_related, 0, 0xB, 0x5, 2678.5667, 0x0, 0x11, 0, 0};
//D:80039910
struct PitemZ_header PhelicopterZ_header = {0, &prop_flying_related, 0, 0x6, 0x4, 4955.271, 0, 0x18, 0, 0};
//D:80039930
struct PitemZ_header PtigerZ_header = {0, &prop_flying_related, 0, 0x6, 0x4, 4072.0291, 0, 0xE, 0, 0};
//D:80039950
struct PitemZ_header PmilcopterZ_header = {0, &prop_flying_related, 0, 0x6, 0x4, 5316.9155, 0, 0xF, 0, 0};
//D:80039970
struct PitemZ_header PhindZ_header = {0, &prop_flying_related, 0, 0x6, 0x5, 5315.314, 0, 0xB, 0, 0};
//D:80039990
struct PitemZ_header PartictrailerZ_header = {0, &model_object_standard_object, 0, 0, 1, 4014.6265, 0, 0xB, 0, 0};
//D:800399B0
struct PitemZ_header PmotorbikeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1610.8706, 0, 6, 0, 0};
//D:800399D0
struct PitemZ_header PtankZ_header = {0, &item_tank_related, 0, 0x9, 0x5, 6290.8398, 0, 0x18, 0, 0};
//D:800399F0
struct PitemZ_header PapcZ_header = {0, &model_object_standard_object, 0, 0, 1, 3611.1035, 0, 0xE, 0, 0};
//D:80039A10
struct PitemZ_header PspeedboatZ_header = {0, &model_object_standard_object, 0, 0, 1, 1799.4586, 0, 0xD, 0, 0};
//D:80039A30
struct PitemZ_header PplaneZ_header = {0, &prop_flying_related, 0, 0x6, 0x3, 9285.4492, 0, 0x1C, 0, 0};
//D:80039A50
struct PitemZ_header Pgun_runway1Z_header = {0, &prop_rotating_stuff_related, 0, 0x8, 0x5, 1927.5205, 0, 6, 0, 0};
//D:80039A70
struct PitemZ_header PsafedoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 714.14612, 0, 4, 0, 0};
//D:80039A90
struct PitemZ_header Pkey_holderZ_header = {0, &model_object_standard_object, 0, 0, 1, 223.87097, 0, 7, 0, 0};
//D:80039AB0
struct PitemZ_header PhatchsevxZ_header = {0, &model_object_standard_object, 0, 0, 1, 1224.7664, 0, 2, 0, 0};
//D:80039AD0
struct PitemZ_header PsevdishZ_header = {0, &prop_rotating_stuff_related, 0, 0x8, 0x3, 14350.1, 0, 7, 0, 0};
//D:80039AF0
struct PitemZ_header Parchsecdoor1Z_header = {0, &model_object_standard_object, 0, 0, 1, 455.81409, 0, 3, 0, 0};
//D:80039B10
struct PitemZ_header Parchsecdoor2Z_header = {0, &model_object_standard_object, 0, 0, 1, 496.99292, 0, 3, 0, 0};
//D:80039B30
struct PitemZ_header PgroundgunZ_header = {0, &prop_rotating_stuff_related, 0, 0x8, 0x5, 2182.6472, 0, 4, 0, 0};
//D:80039B50
struct PitemZ_header PtrainextdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 587.70111, 0, 5, 0, 0};
//D:80039B70
struct PitemZ_header PcarbmwZ_header = {0, &model_object_standard_object, 0, 0, 1, 553.08728, 0, 0xB, 0, 0};
//D:80039B90
struct PitemZ_header PcarescortZ_header = {0, &model_object_standard_object, 0, 0, 1, 1110.5665, 0, 9, 0, 0};
//D:80039BB0
struct PitemZ_header PcargolfZ_header = {0, &model_object_standard_object, 0, 0, 1, 1121.6409, 0, 0xA, 0, 0};
//D:80039BD0
struct PitemZ_header PcarweirdZ_header = {0, &model_object_standard_object, 0, 0, 1, 984.03931, 0, 0xD, 0, 0};
//D:80039BF0
struct PitemZ_header PcarzilZ_header = {0, &prop_car_related, 0, 0xB, 0x5, 1044.5764, 0, 0xD, 0, 0};
//D:80039C10
struct PitemZ_header Pshuttle_door_lZ_header = {0, &model_object_standard_object, 0, 0, 1, 706.56641, 0, 7, 0, 0};
//D:80039C30
struct PitemZ_header Pshuttle_door_rZ_header = {0, &model_object_standard_object, 0, 0, 1, 706.56641, 0, 8, 0, 0};
//D:80039C50
struct PitemZ_header Pdepot_gate_entryZ_header = {0, &model_object_standard_object, 0, 0, 1, 811.28949, 0, 3, 0, 0};
//D:80039C70
struct PitemZ_header Pdepot_door_steelZ_header = {0, &model_object_standard_object, 0, 0, 1, 574.79651, 0, 3, 0, 0};
//D:80039C90
struct PitemZ_header Pglassware2Z_header = {0, &model_object_standard_object, 0, 0, 1, 98.488579, 0, 3, 0, 0};
//D:80039CB0
struct PitemZ_header Pglassware3Z_header = {0, &model_object_standard_object, 0, 0, 1, 137.92715, 0, 1, 0, 0};
//D:80039CD0
struct PitemZ_header Pglassware4Z_header = {0, &model_object_standard_object, 0, 0, 1, 177.48241, 0, 2, 0, 0};
//D:80039CF0
struct PitemZ_header PlandmineZ_header = {0, &model_object_standard_object, 0, 0, 1, 440.03009, 0, 2, 0, 0};
//D:80039D10
struct PitemZ_header Pplant1Z_header = {0, &model_object_standard_object, 0, 0, 1, 2704.1086, 0, 1, 0, 0};
//D:80039D30
struct PitemZ_header Pplant11Z_header = {0, &model_object_standard_object, 0, 0, 1, 2704.1086, 0, 1, 0, 0};
//D:80039D50
struct PitemZ_header Pplant2Z_header = {0, &model_object_standard_object, 0, 0, 1, 3416.248, 0, 2, 0, 0};
//D:80039D70
struct PitemZ_header Pplant3Z_header = {0, &model_object_standard_object, 0, 0, 1, 2986.0405, 0, 1, 0, 0};
//D:80039D90
struct PitemZ_header Pjungle5_treeZ_header = {0, &model_object_standard_object, 0, 0, 1, 3277.6123, 0, 4, 0, 0};
//D:80039DB0
struct PitemZ_header PlegalpageZ_header = {0, &model_object_standard_object, 0, 0, 1, 2711.7573, 0, 5, 0, 0};
//D:80039DD0
struct PitemZ_header Pst_pete_room_1iZ_header = {0, &model_object_standard_object, 0, 0, 1, 8437.5137, 0, 0x17, 0, 0};
//D:80039DF0
struct PitemZ_header Pst_pete_room_2iZ_header = {0, &model_object_standard_object, 0, 0, 1, 8515.8164, 0, 0x19, 0, 0};
//D:80039E10
struct PitemZ_header Pst_pete_room_3tZ_header = {0, &model_object_standard_object, 0, 0, 1, 4561.9766, 0, 0x1B, 0, 0};
//D:80039E30
struct PitemZ_header Pst_pete_room_5cZ_header = {0, &model_object_standard_object, 0, 0, 1, 4561.9766, 0, 0x19, 0, 0};
//D:80039E50
struct PitemZ_header Pst_pete_room_6cZ_header = {0, &model_object_standard_object, 0, 0, 1, 5006.2896, 0, 0x17, 0, 0};
//D:80039E70
struct PitemZ_header Pdoor_rollertrainZ_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 0, 2, 0, 0};
//D:80039E90
struct PitemZ_header Pdoor_winZ_header = {0, &model_object_standard_object, 0, 0, 1, 211.90215, 0, 1, 0, 0};
//D:80039EB0
struct PitemZ_header Pdoor_aztecZ_header = {0, &model_object_standard_object, 0, 0, 1, 632.48639, 0, 1, 0, 0};
//D:80039ED0
struct PitemZ_header PshuttleZ_header = {0, &model_object_standard_object, 0, 0, 1, 4475.1494, 0, 9, 0, 0};
//D:80039EF0
struct PitemZ_header Pdoor_azt_deskZ_header = {0, &model_object_standard_object, 0, 0, 1, 860.41669, 0, 2, 0, 0};
//D:80039F10
struct PitemZ_header Pdoor_azt_desk_topZ_header = {0, &model_object_standard_object, 0, 0, 1, 565.93268, 0, 3, 0, 0};
//D:80039F30
struct PitemZ_header Pdoor_azt_chairZ_header = {0, &model_object_standard_object, 0, 0, 1, 94.510803, 0, 3, 0, 0};
//D:80039F50
struct PitemZ_header Pdoor_mfZ_header = {0, &model_object_standard_object, 0, 0, 1, 559.70367, 0, 7, 0, 0};
//D:80039F70
struct PitemZ_header PflagZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 862.30865, 0, 2, 0, 0};
//D:80039F90
struct PitemZ_header PbarricadeZ_header = {0, &model_object_standard_object, 0, 0, 1, 2047.3016, 0, 2, 0, 0};
//D:80039FB0
struct PitemZ_header PmodemboxZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 338.28839, 0, 4, 0, 0};
//D:80039FD0
struct PitemZ_header PdoorpanelZ_header = {0, &prop_console_four_screen_related, 0, 0x4, 0x1, 338.28839, 0, 4, 0, 0};
//D:80039FF0
struct PitemZ_header PdoorconsoleZ_header = {0, &prop_console_one_screen_related, 0, 0x1, 0x1, 994.23688, 0, 0xD, 0, 0};
//D:8003A010
struct PitemZ_header PchrtesttubeZ_header = {0, &prop_weapon_related, 0, 0x3, 0x1, 136.25925, 0, 2, 0, 0};
//D:8003A030
struct PitemZ_header Pbollardz_header = {0, &model_object_standard_object, 0, 0, 1, 628.78754, 0, 1, 0, 0};

//D:8003A050
struct prop_pos_data word_D_8003A050[2] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003}
};
//D:8003A05C
struct item_related prop_cctv_related = {2, 0, word_D_8003A050, 6, 0};

//D:8003A068
struct prop_pos_data word_D_8003A068[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A06E                     .half 0

//D:8003A070
struct item_related prop_console_one_screen_related = {1, 0, word_D_8003A068, 3, 0};

//D:8003A07C
struct prop_pos_data word_D_8003A07C[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A082                     .half 0

//D:8003A084
struct item_related prop_console_four_screen_related = {1, 0, word_D_8003A07C, 3, 0};

//D:8003A090
struct prop_pos_data word_D_8003A090[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A0AE                     .half 0

//D:8003A0B0
struct item_related prop_tv_holder_related = {5, 0, word_D_8003A090, 0xF, 0};

//D:8003A0BC
struct prop_pos_data word_D_8003A0BC[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003A0E0
struct item_related prop_rotating_stuff_related = {6, 0, word_D_8003A0BC, 0x12, 0};

//D:8003A0EC
struct prop_pos_data word_D_8003A0EC[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006}
};
//D:8003A0FE                     .half 0
//D:8003A100
struct item_related prop_eyelid_door_related = {3, 0, word_D_8003A0EC, 9, 0};

//D:8003A10C
struct prop_pos_data word_D_8003A10C[] = {
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
struct item_related prop_iris_door_related = {0xD, 0, word_D_8003A10C, 0x27, 0};

//D:8003A168
struct prop_pos_data word_D_8003A168[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A16E                     .half 0
//D:8003A170
struct item_related prop_walletbond_related = {1, 0, word_D_8003A168, 3, 0};

//D:8003A17C
struct prop_pos_data word_D_8003A17C[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A19C
struct item_related prop_car_related = {5, 0, word_D_8003A17C, 0xF, 0};

//D:8003A1A8
struct prop_pos_data word_D_8003A1A8[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0015, 0x0003, 0x0003},
    {0x0015, 0x0004, 0x0004},
    {0x0015, 0x0005, 0x0005}
};
//D:8003A1C6                     .half 0
//D:8003A1C8
struct item_related prop_flying_related = {5, 0, word_D_8003A1A8, 3, 0};

//D:8003A1D4
struct prop_pos_data word_D_8003A1D4[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A1DA                     .half 0
//D:8003A1DC
struct item_related prop_door_related = {1, 0, word_D_8003A1D4, 3, 0};

//D:8003A1E8
struct prop_pos_data word_D_8003A1E8[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A206                     .half 0
//D:8003A208
struct item_related item_tank_related = {5, 0, word_D_8003A1E8, 0xF, 0};

//D:8003A214
struct prop_pos_data word_D_8003A214[] = {
    {0x0015, 0x0000, 0x0000},
};
//D:8003A21A                     .half 0
//D:8003A21C
struct item_related item_hat_related = {1, 0, word_D_8003A214, 0, 0};

//D:8003A228                     .globl PitemZ_entries
struct p_itementry PitemZ_entries[] = {
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

//FIXME File split likely

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

