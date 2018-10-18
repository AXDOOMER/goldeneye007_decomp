#include "ultra64.h"

/* bss
CODE.bss:80079E30     off_CODE_bss_80079E30:.space 1           # DATA XREF: sub_CODE_7F0072B0w
CODE.bss:80079E30                                              # sub_CODE_7F091B64+4Co
CODE.bss:80079E30                                              # sub_CODE_7F092438+4Co
CODE.bss:80079E30                                              # sub_CODE_7F092438:loc_CODE_7F0924A8w
CODE.bss:80079E31     byte_CODE_bss_80079E31:.space 1          # DATA XREF: sub_CODE_7F0072B0+8w
CODE.bss:80079E32     byte_CODE_bss_80079E32:.space 1          # DATA XREF: sub_CODE_7F0072B0+24w
CODE.bss:80079E33     byte_CODE_bss_80079E33:.space 1          # DATA XREF: sub_CODE_7F0072B0+20o
CODE.bss:80079E34                     .space 0x44
CODE.bss:80079E78                     .space 3
CODE.bss:80079E7B     byte_CODE_bss_80079E7B:.space 1          # DATA XREF: sub_CODE_7F0072B0+18o
*/

/* data
D:80037070     dword_D_80037070:.word 0x14002100        # DATA XREF: D:stru_D_8003744Co
D:80037074                     .word 0x10201, 0x3010104
D:8003707C     dword_D_8003707C:.word 0x2110301         # DATA XREF: D:80037454o
D:80037080                     .word 0x11040000
D:80037084     dword_D_80037084:.word 0x2010330         # DATA XREF: D:8003745Co
D:80037088                     .word 0xFD112F06
D:8003708C                     .word 0x1010206
D:80037090                     .word 0x32073E0D
D:80037094                     .word 0x3F0E4610
D:80037098                     .word 0x3A0D3B0D
D:8003709C                     .word 0xB033335
D:800370A0                     .word 0x1030600
D:800370A4                     .word 0x205FD00, 0x3020301, 0x1021033, 0x357F0706, 0x205FD, 0xA0207, 0x6000205
D:800370A4                     .word 0xFD000602, 0xD060002, 0x5FD0008, 0x20E0600, 0x205FD00, 0xB021105, 0xFD000104
D:800370DC     dword_D_800370DC:.word 0x33353203, 0xA009A00, 0xC118, 0x10000202, 0x3356403, 0xA009B00, 0x12618
D:800370DC                                              # DATA XREF: D:80037464o
D:800370DC                     .word 0x10000202, 0x3359603, 0xA009C00, 0xB718, 0x10000202, 0x335C803, 0xA009D00
D:800370DC                     .word 0x7B18, 0x10000202, 0x335FA03, 0xA009E00, 0x3818, 0x10000202, 0x30A009F
D:800370DC                     .word 0x89, 0x18100002, 0x2020704
D:8003713C     dword_D_8003713C:.word 0x33353C03, 0xA00AC00, 0x4500, 0x10000202, 0x3357803, 0xA00AD00, 0x4A00
D:8003713C                                              # DATA XREF: D:8003746Co
D:8003713C                     .word 0x10000202, 0x335B403, 0xA00AE00, 0x4F00, 0x10000202, 0x30A00AF, 0x59
D:8003713C                     .word 0x100002, 0x2020704
D:8003717C     dword_D_8003717C:.word 0x201032F, 0x6010102, 0x632073E, 0xD46103A, 0xD3B0D01, 0x1021033, 0x357F0706
D:8003717C                                              # DATA XREF: D:80037474o
D:8003717C                     .word 0x205FD, 0xA0207, 0x6000205, 0xFD000602, 0xD060002, 0x5FD0008, 0x4000000
D:800371B4     dword_D_800371B4:.word 0x96010333, 0x3520030C, 0x94010702, 0x394011A, 0x2020333, 0x350A0313
D:800371B4                                              # DATA XREF: D:8003747Co
D:800371B4                     .word 0x2020333, 0x350A030F, 0x2020333, 0x3519030E, 0x2020333, 0x35320310
D:800371B4                     .word 0x2020333, 0x35400311, 0x2020335, 0x7F031202, 0x2033335, 0x7F0B1400
D:800371B4                     .word 0x1000002, 0x20B1500, 0x1000002, 0x2020704
D:8003720C     dword_D_8003720C:.word 0x94012801, 0x7020103, 0x2F063207, 0x1010207, 0x5FD0006, 0x2060704
D:8003720C                                              # DATA XREF: D:8003748Co
D:80037224     dword_D_80037224:.word 0x9401410E, 0x5FD0008, 0x20E31F9, 0xE05FD00, 0x2020EC1, 0xFD000C03, 0x5FD0008
D:80037224                                              # DATA XREF: D:800374A4o
D:80037224                     .word 0x20305FD, 0x20400
D:80037248     dword_D_80037248:.word 0x6000205, 0xFD000804  # DATA XREF: D:800374ACo
D:80037250     dword_D_80037250:.word 0x2010332, 0x73E0D3F, 0xD460D3A, 0xD3B0D01, 0x1020706, 0x205FD, 0x6020D
D:80037250                                              # DATA XREF: D:80037484o
D:80037250                     .word 0x6000205, 0xFD000802, 0xE060002, 0x5FD000B, 0x4000000
D:80037280     dword_D_80037280:.word 0x201032F, 0x6010102, 0x6320F7B, 0x103F10, 0x3A103B10, 0x1010210, 0x79000F0D
D:80037280                                              # DATA XREF: D:80037494o
D:80037280                     .word 0x204032F, 0xF010402, 0xF1C2328, 0x203032F, 0x2010302, 0x24EFD00, 0xA232802
D:80037280                     .word 0x24232805, 0x20205, 0x32F0201, 0x5020206, 0x205FD, 0x80400
D:800372D0     dword_D_800372D0:.word 0xD020103, 0x2F020101, 0x20205FD, 0x80400
D:800372D0                                              # DATA XREF: D:8003749Co
D:800372E0     dword_D_800372E0:.word 0x228281B, 0xAD6E6F20, 0x676F210A, 0x21B03, 0x3C062F02, 0x11B0201, 0x378062D
D:800372E0                                              # DATA XREF: D:800374B4o
D:800372E0                     .word 0x9F000000, 0x102F022D, 0x2F064C00, 0xC8030101, 0x2030128, 0x2063C03
D:800372E0                     .word 0x20224, 0x34B0032, 0x32F0301, 0x2802039F, 0x10, 0x2F022B33, 0x350A031A
D:800372E0                     .word 0x2020335, 0x32030E02, 0x203353C, 0x3130202, 0x3355003, 0x13020203, 0x35640311
D:800372E0                     .word 0x2020335, 0x96031202, 0x20335C8, 0x3140001, 0x202, 0x3150001, 0x202
D:800372E0                     .word 0x23C0300, 0x1B021B03, 0x3335A003, 0x1C0203, 0x3010102, 0x1CAE281D, 0x21D032F
D:800372E0                     .word 0x3B40000, 0x3C03011D, 0x20308AD, 0x77616974, 0xA009504, 0x3335A003
D:800372E0                     .word 0x94040203, 0xAE021E03, 0x3C034603, 0x3B30002, 0x58049604, 0x5012802
D:800372E0                     .word 0x5011C02, 0x4011E02, 0x3010102, 0x2F780603, 0x9E000000, 0x10020301
D:800372E0                     .word 0x2B040000
D:800373D0     dword_D_800373D0:.word 0xAE021B03, 0xB400003C, 0x3011B02, 0x3070400
D:800373D0                                              # DATA XREF: D:800374BCo
D:800373E0     dword_D_800373E0:.word 0xD205FD00, 0x1040000  # DATA XREF: D:800374C4o
D:800373E8     dword_D_800373E8:.word 0x91289332, 0x2031700, 0x1000003, 0x203AE02, 0x1B03B400, 0x140301, 0x1B02030A
D:800373E8                                              # DATA XREF: D:800374CCo
D:800373E8                     .word 0x420000, 0x140410, 0x21C032F, 0x3011C02, 0x3BF00CD, 0x6000000, 0x30203
D:800373E8                     .word 0x14002100, 0x30203, 0x16000100, 0x30203, 0x21E032F, 0x3011E02, 0x3060002
D:800373E8                     .word 0x5FD0008, 0x4000000
D:80037444     dword_D_80037444:.word 0x23FD05FD        # DATA XREF: D:800374D4o
D:80037448                     .word 0x10400
D:8003744C     stru_D_8003744C:struct_13 <dword_D_80037070, 0>
D:8003744C                                              # DATA XREF: sub_CODE_7F035244+6Co
D:8003744C                                              # sub_CODE_7F035244+78r
D:8003744C                                              # sub_CODE_7F035398:loc_CODE_7F0353F0r
D:8003744C                                              # sub_CODE_7F035398+5Co
D:8003744C                                              # sub_CODE_7F035398+6Cr
D:80037454                     struct_13 <dword_D_8003707C, 1>
D:8003745C                     struct_13 <dword_D_80037084, 2>
D:80037464                     struct_13 <dword_D_800370DC, 3>
D:8003746C                     struct_13 <dword_D_8003713C, 4>
D:80037474                     struct_13 <dword_D_8003717C, 5>
D:8003747C                     struct_13 <dword_D_800371B4, 6>
D:80037484                     struct_13 <dword_D_80037250, 7>
D:8003748C                     struct_13 <dword_D_8003720C, 8>
D:80037494                     struct_13 <dword_D_80037280, 9>
D:8003749C                     struct_13 <dword_D_800372D0, 0xA>
D:800374A4                     struct_13 <dword_D_80037224, 0xB>
D:800374AC                     struct_13 <dword_D_80037248, 0xC>
D:800374B4                     struct_13 <dword_D_800372E0, 0xD>
D:800374BC                     struct_13 <dword_D_800373D0, 0xE>
D:800374C4                     struct_13 <dword_D_800373E0, 0xF>
D:800374CC                     struct_13 <dword_D_800373E8, 0x10>
D:800374D4                     struct_13 <dword_D_80037444, 0x11>
D:800374DC                     struct_13 <0>
D:800374E4     setup_text_pointers:.word 0,0,0,0,0,0,0,0,0,aUsetupsevbunkerz,0,0,0,0,0,0,0,0,0,0,aUsetupsiloz
D:800374E4                                              # DATA XREF: stage_loading_setup_objparse_cleanupafter+D4o
D:800374E4                     .word aUsetupsevbunkerz_0,aUsetupstatuez,aUsetupcontrolz,aUsetuparchz,aUsetuptraz  # "UsetupsevbunkerZ"
D:800374E4                     .word aUsetupdestz,aUsetupsevbz,aUsetupaztz,aUsetuppetez,aUsetupdepoz,aUsetuprefz
D:800374E4                     .word aUsetupcrypz,aUsetupdamz,aUsetuparkz,aUsetuprunz,aUsetupsevxz,aUsetupjunz
D:800374E4                     .word aUsetupdishz,aUsetupcavez,aUsetupcatz,aUsetupcradz,aUsetupshoz,aUsetupsevxbz
D:800374E4                     .word aUsetupeldz,aUsetupimpz,aUsetupashz,aUsetupluez,aUsetupamez,aUsetupritz
D:800374E4                     .word aUsetupoatz,aUsetupearz,aUsetupleez,aUsetuplipz,aUsetuplenz,aUsetupwaxz
D:800374E4                     .word aUsetuppamz,0,0
D:800375D0     Palarm1z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 304.6402, 2, 0, 0>
D:800375D0                                              # DATA XREF: D:PitemZ_entrieso
D:800375F0     Palarm2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 208.22205, 3, 0, 0>
D:800375F0                                              # DATA XREF: D:8003A234o
D:80037610     PexplosionbitZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 208.22205, 0, 0, 0>
D:80037610                                              # DATA XREF: D:8003A240o
D:80037630     Pammo_crate1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 691.83429, 3, 0, 0>
D:80037630                                              # DATA XREF: D:8003A24Co
D:80037650     Pammo_crate2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 691.83429, 4, 0, 0>
D:80037650                                              # DATA XREF: D:8003A258o
D:80037670     Pammo_crate3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 691.83429, 4, 0, 0>
D:80037670                                              # DATA XREF: D:8003A264o
D:80037690     Pammo_crate4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 691.83429, 5, 0, 0>
D:80037690                                              # DATA XREF: D:8003A270o
D:800376B0     Pammo_crate5Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 691.83429, 5, 0, 0>
D:800376B0                                              # DATA XREF: D:8003A27Co
D:800376D0     Pbin1Z_header:  PitemZ_header <0, model_object_standard_object, 0, 1, 3027.6262, 2, 0, 0>
D:800376D0                                              # DATA XREF: D:8003A288o
D:800376F0     Pblotter1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 432.46707, 1, 0, 0>
D:800376F0                                              # DATA XREF: D:8003A294o
D:80037710     Pbook1Z_header: PitemZ_header <0, model_object_standard_object, 0, 1, 171.37482, 2, 0, 0>
D:80037710                                              # DATA XREF: D:8003A2A0o
D:80037730     Pbookshelf1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1166.7578, 0xD, 0, 0>
D:80037730                                              # DATA XREF: D:8003A2ACo
D:80037750     Pbridge_console1aZ_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 788.03992, 0xF, 0, 0>
D:80037750                                              # DATA XREF: D:8003A2B8o
D:80037770     Pbridge_console1bZ_header:PitemZ_header <0, prop_console_one_screen_related, 1, 1, 788.03992, 0x10, 0, 0>
D:80037770                                              # DATA XREF: D:8003A2C4o
D:80037790     Pbridge_console2aZ_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 788.03992, 0xF, 0, 0>
D:80037790                                              # DATA XREF: D:8003A2D0o
D:800377B0     Pbridge_console2bZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 788.03992, 0xF, 0, 0>
D:800377B0                                              # DATA XREF: D:8003A2DCo
D:800377D0     Pbridge_console3aZ_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 788.03992, 0xF, 0, 0>
D:800377D0                                              # DATA XREF: D:8003A2E8o
D:800377F0     Pbridge_console3bZ_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 788.03992, 0x10, 0, 0>
D:800377F0                                              # DATA XREF: D:8003A2F4o
D:80037810     Pcard_box1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 727.4613, 5, 0, 0>
D:80037810                                              # DATA XREF: D:8003A300o
D:80037830     Pcard_box2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 727.4613, 6, 0, 0>
D:80037830                                              # DATA XREF: D:8003A30Co
D:80037850     Pcard_box3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 727.4613, 5, 0, 0>
D:80037850                                              # DATA XREF: D:8003A318o
D:80037870     Pcard_box4_lgZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 800.2074, 4, 0, 0>
D:80037870                                              # DATA XREF: D:8003A324o
D:80037890     Pcard_box5_lgZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 800.2074, 5, 0, 0>
D:80037890                                              # DATA XREF: D:8003A330o
D:800378B0     Pcard_box6_lgZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 800.2074, 5, 0, 0>
D:800378B0                                              # DATA XREF: D:8003A33Co
D:800378D0     PcctvZ_header:  PitemZ_header <0, prop_cctv_related, 4, 2, 558.90094, 6, 0, 0>
D:800378D0                                              # DATA XREF: D:8003A348o
D:800378F0     Pconsole1Z_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 1611.2357, 0xA, 0, 0>
D:800378F0                                              # DATA XREF: D:8003A354o
D:80037910     Pconsole2Z_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 1611.2357, 0xA, 0, 0>
D:80037910                                              # DATA XREF: D:8003A360o
D:80037930     Pconsole3Z_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 1611.2357, 0xA, 0, 0>
D:80037930                                              # DATA XREF: D:8003A36Co
D:80037950     Pconsole_sevaZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 994.23688, 0xE, 0, 0>
D:80037950                                              # DATA XREF: D:8003A378o
D:80037970     Pconsole_sevbZ_header:PitemZ_header <0, prop_console_one_screen_related, 1, 1, 994.23688, 0xB, 0, 0>
D:80037970                                              # DATA XREF: D:8003A384o
D:80037990     Pconsole_sevcZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 994.23688, 0xF, 0, 0>
D:80037990                                              # DATA XREF: D:8003A390o
D:800379B0     Pconsole_sevdZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 994.23688, 0xD, 0, 0>
D:800379B0                                              # DATA XREF: D:8003A39Co
D:800379D0     Pconsole_sev2aZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 994.23688, 0xD, 0, 0>
D:800379D0                                              # DATA XREF: D:8003A3A8o
D:800379F0     Pconsole_sev2bZ_header:PitemZ_header <0, prop_console_one_screen_related, 1, 1, 994.23688, 0xD, 0, 0>
D:800379F0                                              # DATA XREF: D:8003A3B4o
D:80037A10     Pconsole_sev2cZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 994.23688, 0xF, 0, 0>
D:80037A10                                              # DATA XREF: D:8003A3C0o
D:80037A30     Pconsole_sev2dZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 994.23688, 0xD, 0, 0>
D:80037A30                                              # DATA XREF: D:8003A3CCo
D:80037A50     Pconsole_sev_GEaZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 994.23688, 0xD, 0, 0>
D:80037A50                                              # DATA XREF: D:8003A3D8o
D:80037A70     Pconsole_sev_GEbZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 994.23688, 0xD, 0, 0>
D:80037A70                                              # DATA XREF: D:8003A3E4o
D:80037A90     Pdesk1Z_header: PitemZ_header <0, model_object_standard_object, 0, 1, 957.18225, 3, 0, 0>
D:80037A90                                              # DATA XREF: D:8003A3F0o
D:80037AB0     Pdesk2Z_header: PitemZ_header <0, model_object_standard_object, 0, 1, 957.18225, 3, 0, 0>
D:80037AB0                                              # DATA XREF: D:8003A3FCo
D:80037AD0     Pdesk_lamp2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 804.59833, 4, 0, 0>
D:80037AD0                                              # DATA XREF: D:8003A408o
D:80037AF0     Pdisc_readerZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 214.33035, 6, 0, 0>
D:80037AF0                                              # DATA XREF: D:8003A414o
D:80037B10     Pdisk_drive1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 191.85779, 4, 0, 0>
D:80037B10                                              # DATA XREF: D:8003A420o
D:80037B30     Pfiling_cabinet1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1055.5693, 2, 0, 0>
D:80037B30                                              # DATA XREF: D:8003A42Co
D:80037B50     Pjerry_can1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 366.61932, 4, 0, 0>
D:80037B50                                              # DATA XREF: D:8003A438o
D:80037B70     Pkeyboard1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 278.23227, 2, 0, 0>
D:80037B70                                              # DATA XREF: D:8003A444o
D:80037B90     Pkit_units1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1661.4763, 4, 0, 0>
D:80037B90                                              # DATA XREF: D:8003A450o
D:80037BB0     Pletter_tray1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 252.06836, 1, 0, 0>
D:80037BB0                                              # DATA XREF: D:8003A45Co
D:80037BD0     Pmainframe1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1119.4073, 7, 0, 0>
D:80037BD0                                              # DATA XREF: D:8003A468o
D:80037BF0     Pmainframe2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1119.4073, 7, 0, 0>
D:80037BF0                                              # DATA XREF: D:8003A474o
D:80037C10     Pmetal_chair1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 639.18097, 2, 0, 0>
D:80037C10                                              # DATA XREF: D:8003A480o
D:80037C30     Pmetal_crate1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1010.363, 3, 0, 0>
D:80037C30                                              # DATA XREF: D:8003A48Co
D:80037C50     Pmetal_crate2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1010.363, 3, 0, 0>
D:80037C50                                              # DATA XREF: D:8003A498o
D:80037C70     Pmetal_crate3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1010.363, 2, 0, 0>
D:80037C70                                              # DATA XREF: D:8003A4A4o
D:80037C90     Pmetal_crate4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1010.363, 3, 0, 0>
D:80037C90                                              # DATA XREF: D:8003A4B0o
D:80037CB0     Pmissile_rackZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 964.16296, 4, 0, 0>
D:80037CB0                                              # DATA XREF: D:8003A4BCo
D:80037CD0     Pmissile_rack2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1148.4724, 4, 0, 0>
D:80037CD0                                              # DATA XREF: D:8003A4C8o
D:80037CF0     Poil_drum1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 745.45892, 2, 0, 0>
D:80037CF0                                              # DATA XREF: D:8003A4D4o
D:80037D10     Poil_drum2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 745.45892, 4, 0, 0>
D:80037D10                                              # DATA XREF: D:8003A4E0o
D:80037D30     Poil_drum3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 745.45892, 4, 0, 0>
D:80037D30                                              # DATA XREF: D:8003A4ECo
D:80037D50     Poil_drum5Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 745.45892, 3, 0, 0>
D:80037D50                                              # DATA XREF: D:8003A4F8o
D:80037D70     Poil_drum6Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 745.45892, 3, 0, 0>
D:80037D70                                              # DATA XREF: D:8003A504o
D:80037D90     Poil_drum7Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 745.45892, 4, 0, 0>
D:80037D90                                              # DATA XREF: D:8003A510o
D:80037DB0     PpadlockZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 225.64145, 4, 0, 0>
D:80037DB0                                              # DATA XREF: D:8003A51Co
D:80037DD0     Pphone1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 166.03481, 2, 0, 0>
D:80037DD0                                              # DATA XREF: D:8003A528o
D:80037DF0     Pradio_unit1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 354.59534, 5, 0, 0>
D:80037DF0                                              # DATA XREF: D:8003A534o
D:80037E10     Pradio_unit2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 354.59534, 5, 0, 0>
D:80037E10                                              # DATA XREF: D:8003A540o
D:80037E30     Pradio_unit3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 354.59534, 5, 0, 0>
D:80037E30                                              # DATA XREF: D:8003A54Co
D:80037E50     Pradio_unit4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 354.59534, 5, 0, 0>
D:80037E50                                              # DATA XREF: D:8003A558o
D:80037E70     Psat1_reflectZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 5185.9409, 0xD, 0, 0>
D:80037E70                                              # DATA XREF: D:8003A564o
D:80037E90     PsatdishZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2437.468, 2, 0, 0>
D:80037E90                                              # DATA XREF: D:8003A570o
D:80037EB0     PsatboxZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 89.935875, 1, 0, 0>
D:80037EB0                                              # DATA XREF: D:8003A57Co
D:80037ED0     Pstool1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 353.11398, 2, 0, 0>
D:80037ED0                                              # DATA XREF: D:8003A588o
D:80037EF0     Pswivel_chair1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 581.16394, 3, 0, 0>
D:80037EF0                                              # DATA XREF: D:8003A594o
D:80037F10     Ptorpedo_rackZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 765.61725, 3, 0, 0>
D:80037F10                                              # DATA XREF: D:8003A5A0o
D:80037F30     Ptv1Z_header:   PitemZ_header <0, prop_console_one_screen_related, 1, 1, 347.0235, 5, 0, 0>
D:80037F30                                              # DATA XREF: D:8003A5ACo
D:80037F50     Ptv_holderZ_header:PitemZ_header <0, prop_tv_holder_related, 4, 5, 1352.4841, 2, 0, 0>
D:80037F50                                              # DATA XREF: D:8003A5B8o
D:80037F70     PtvscreenZ_header:PitemZ_header <0, prop_console_one_screen_related, 1, 1, 211.74477, 1, 0, 0>
D:80037F70                                              # DATA XREF: D:8003A5C4o
D:80037F90     Ptv4screenZ_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 211.74477, 1, 0, 0>
D:80037F90                                              # DATA XREF: D:8003A5D0o
D:80037FB0     Pwood_lg_crate1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1010.363, 3, 0, 0>
D:80037FB0                                              # DATA XREF: D:8003A5DCo
D:80037FD0     Pwood_lg_crate2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1010.363, 2, 0, 0>
D:80037FD0                                              # DATA XREF: D:8003A5E8o
D:80037FF0     Pwood_md_crate3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 909.32666, 2, 0, 0>
D:80037FF0                                              # DATA XREF: D:8003A5F4o
D:80038010     Pwood_sm_crate4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 727.4613, 3, 0, 0>
D:80038010                                              # DATA XREF: D:8003A600o
D:80038030     Pwood_sm_crate5Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 727.4613, 4, 0, 0>
D:80038030                                              # DATA XREF: D:8003A60Co
D:80038050     Pwood_sm_crate6Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 727.4613, 4, 0, 0>
D:80038050                                              # DATA XREF: D:8003A618o
D:80038070     Pwooden_table1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1095.1365, 2, 0, 0>
D:80038070                                              # DATA XREF: D:8003A624o
D:80038090     Pswipe_card2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 123.08884, 2, 0, 0>
D:80038090                                              # DATA XREF: D:8003A630o
D:800380B0     Pborg_crateZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1010.363, 1, 0, 0>
D:800380B0                                              # DATA XREF: D:8003A63Co
D:800380D0     Pboxes4x4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2424.8711, 7, 0, 0>
D:800380D0                                              # DATA XREF: D:8003A648o
D:800380F0     Pboxes3x4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2241.0935, 6, 0, 0>
D:800380F0                                              # DATA XREF: D:8003A654o
D:80038110     Pboxes2x4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2100.0, 6, 0, 0>
D:80038110                                              # DATA XREF: D:8003A660o
D:80038130     Psec_panelZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1567.2454, 3, 0, 0>
D:80038130                                              # DATA XREF: D:8003A66Co
D:80038150     PICBM_noseZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2782.7126, 8, 0, 0>
D:80038150                                              # DATA XREF: D:8003A678o
D:80038170     PICBMZ_header:  PitemZ_header <0, model_object_standard_object, 0, 1, 14790.535, 0xE, 0, 0>
D:80038170                                              # DATA XREF: D:8003A684o
D:80038190     Ptuning_console1Z_header:PitemZ_header <0, prop_console_one_screen_related, 1, 1, 1139.5872, 0xE, 0, 0>
D:80038190                                              # DATA XREF: D:8003A690o
D:800381B0     Pdesk_arecibo1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1829.1477, 3, 0, 0>
D:800381B0                                              # DATA XREF: D:8003A69Co
D:800381D0     Plocker3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 916.99805, 3, 0, 0>
D:800381D0                                              # DATA XREF: D:8003A6A8o
D:800381F0     Plocker4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 916.99805, 3, 0, 0>
D:800381F0                                              # DATA XREF: D:8003A6B4o
D:80038210     ProofgunZ_header:PitemZ_header <0, prop_rotating_stuff_related, 8, 5, 1910.908, 0xE, 0, 0>
D:80038210                                              # DATA XREF: D:8003A6C0o
D:80038230     Pdest_engineZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 6459.439, 0xA, 0, 0>
D:80038230                                              # DATA XREF: D:8003A6CCo
D:80038250     Pdest_exocetZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1644.8435, 8, 0, 0>
D:80038250                                              # DATA XREF: D:8003A6D8o
D:80038270     Pdest_gunZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2124.0735, 5, 0, 0>
D:80038270                                              # DATA XREF: D:8003A6E4o
D:80038290     Pdest_harpoonZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1798.7655, 5, 0, 0>
D:80038290                                              # DATA XREF: D:8003A6F0o
D:800382B0     Pdest_seawolfZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2282.0623, 0xA, 0, 0>
D:800382B0                                              # DATA XREF: D:8003A6FCo
D:800382D0     PwindowZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 423.48956, 1, 0, 0>
D:800382D0                                              # DATA XREF: D:8003A708o
D:800382F0     Pwindow_lib_lg1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 835.20624, 1, 0, 0>
D:800382F0                                              # DATA XREF: D:8003A714o
D:80038310     Pwindow_lib_sm1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 601.28625, 1, 0, 0>
D:80038310                                              # DATA XREF: D:8003A720o
D:80038330     Pwindow_cor11Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 414.53622, 1, 0, 0>
D:80038330                                              # DATA XREF: D:8003A72Co
D:80038350     Pjungle3_treeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 28729.467, 5, 0, 0>
D:80038350                                              # DATA XREF: D:8003A738o
D:80038370     PpalmZ_header:  PitemZ_header <0, model_object_standard_object, 0, 1, 15501.406, 3, 0, 0>
D:80038370                                              # DATA XREF: D:8003A744o
D:80038390     PpalmtreeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1781.4542, 2, 0, 0>
D:80038390                                              # DATA XREF: D:8003A750o
D:800383B0     Pplant2bZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1252.9539, 2, 0, 0>
D:800383B0                                              # DATA XREF: D:8003A75Co
D:800383D0     PlabbenchZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 844.09717, 4, 0, 0>
D:800383D0                                              # DATA XREF: D:8003A768o
D:800383F0     PgasbarrelZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 725.94379, 2, 0, 0>
D:800383F0                                              # DATA XREF: D:8003A774o
D:80038410     PgasbarrelsZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1174.1927, 2, 0, 0>
D:80038410                                              # DATA XREF: D:8003A780o
D:80038430     PbodyarmourZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 246.94099, 7, 0, 0>
D:80038430                                              # DATA XREF: D:8003A78Co
D:80038450     PbodyarmourvestZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 241.82211, 2, 0, 0>
D:80038450                                              # DATA XREF: D:8003A798o
D:80038470     PgastankZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1130.0691, 5, 0, 0>
D:80038470                                              # DATA XREF: D:8003A7A4o
D:80038490     Pglassware1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 72.111031, 1, 0, 0>
D:80038490                                              # DATA XREF: D:8003A7B0o
D:800384B0     PhatchboltZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2236.0679, 1, 0, 0>
D:800384B0                                              # DATA XREF: D:8003A7BCo
D:800384D0     PbrakeunitZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 801.95074, 4, 0, 0>
D:800384D0                                              # DATA XREF: D:8003A7C8o
D:800384F0     Pak47magZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 107.11019, 2, 0, 0>
D:800384F0                                              # DATA XREF: D:8003A7D4o
D:80038510     Pm16magZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 87.934891, 2, 0, 0>
D:80038510                                              # DATA XREF: D:8003A7E0o
D:80038530     Pmp5kmagZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 119.54729, 2, 0, 0>
D:80038530                                              # DATA XREF: D:8003A7ECo
D:80038550     PskorpionmagZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 58.428444, 2, 0, 0>
D:80038550                                              # DATA XREF: D:8003A7F8o
D:80038570     PspectremagZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 99.01432, 2, 0, 0>
D:80038570                                              # DATA XREF: D:8003A804o
D:80038590     PuzimagZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 74.28373, 2, 0, 0>
D:80038590                                              # DATA XREF: D:8003A810o
D:800385B0     PsilencerZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 63.915436, 3, 0, 0>
D:800385B0                                              # DATA XREF: D:8003A81Co
D:800385D0     PchrextinguisherZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 425.50903, 2, 0, 0>
D:800385D0                                              # DATA XREF: D:8003A828o
D:800385F0     PboxcartridgesZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 66.81916, 3, 0, 0>
D:800385F0                                              # DATA XREF: D:8003A834o
D:80038610     Pfnp90magZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 176.28201, 2, 0, 0>
D:80038610                                              # DATA XREF: D:8003A840o
D:80038630     PgoldenshellsZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 66.81916, 3, 0, 0>
D:80038630                                              # DATA XREF: D:8003A84Co
D:80038650     PmagnumshellsZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 66.81916, 3, 0, 0>
D:80038650                                              # DATA XREF: D:8003A858o
D:80038670     PwppkmagZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 74.28373, 2, 0, 0>
D:80038670                                              # DATA XREF: D:8003A864o
D:80038690     Ptt33magZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 74.28373, 2, 0, 0>
D:80038690                                              # DATA XREF: D:8003A870o
D:800386B0     Psev_doorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1143.7695, 3, 0, 0>
D:800386B0                                              # DATA XREF: D:8003A87Co
D:800386D0     Psev_door3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1143.5603, 6, 0, 0>
D:800386D0                                              # DATA XREF: D:8003A888o
D:800386F0     Psev_door3_windZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1143.5603, 5, 0, 0>
D:800386F0                                              # DATA XREF: D:8003A894o
D:80038710     Psev_door4_windZ_header:PitemZ_header <0, prop_door_related, 4, 1, 1143.5603, 8, 0, 0>
D:80038710                                              # DATA XREF: D:8003A8A0o
D:80038730     Psev_trislideZ_header:PitemZ_header <0, prop_door_related, 4, 1, 950.54327, 2, 0, 0>
D:80038730                                              # DATA XREF: D:8003A8ACo
D:80038750     Psev_door_v1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1137.8739, 6, 0, 0>
D:80038750                                              # DATA XREF: D:8003A8B8o
D:80038770     Psteel_door1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1137.8739, 4, 0, 0>
D:80038770                                              # DATA XREF: D:8003A8C4o
D:80038790     Psteel_door2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1137.8739, 9, 0, 0>
D:80038790                                              # DATA XREF: D:8003A8D0o
D:800387B0     Psteel_door3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1137.8739, 9, 0, 0>
D:800387B0                                              # DATA XREF: D:8003A8DCo
D:800387D0     Psilo_lift_doorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 600.71082, 4, 0, 0>
D:800387D0                                              # DATA XREF: D:8003A8E8o
D:800387F0     Psteel_door2bZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1137.8739, 9, 0, 0>
D:800387F0                                              # DATA XREF: D:8003A8F4o
D:80038810     Pdoor_roller1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1032.125, 4, 0, 0>
D:80038810                                              # DATA XREF: D:8003A900o
D:80038830     Pdoor_roller2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1032.125, 4, 0, 0>
D:80038830                                              # DATA XREF: D:8003A90Co
D:80038850     Pdoor_roller3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1032.125, 4, 0, 0>
D:80038850                                              # DATA XREF: D:8003A918o
D:80038870     Pdoor_roller4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1032.125, 4, 0, 0>
D:80038870                                              # DATA XREF: D:8003A924o
D:80038890     Pdoor_st_arec1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 763.03589, 3, 0, 0>
D:80038890                                              # DATA XREF: D:8003A930o
D:800388B0     Pdoor_st_arec2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 763.03589, 3, 0, 0>
D:800388B0                                              # DATA XREF: D:8003A93Co
D:800388D0     Pdoor_dest1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 461.3873, 3, 0, 0>
D:800388D0                                              # DATA XREF: D:8003A948o
D:800388F0     Pdoor_dest2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 461.3873, 5, 0, 0>
D:800388F0                                              # DATA XREF: D:8003A954o
D:80038910     Pgas_plant_sw_do1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 862.29706, 4, 0, 0>
D:80038910                                              # DATA XREF: D:8003A960o
D:80038930     Pgas_plant_sw2_do1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 862.88489, 2, 0, 0>
D:80038930                                              # DATA XREF: D:8003A96Co
D:80038950     Pgas_plant_sw3_do1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 862.88489, 2, 0, 0>
D:80038950                                              # DATA XREF: D:8003A978o
D:80038970     Pgas_plant_sw4_do1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 862.88489, 1, 0, 0>
D:80038970                                              # DATA XREF: D:8003A984o
D:80038990     Pgas_plant_met1_do1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 862.88489, 5, 0, 0>
D:80038990                                              # DATA XREF: D:8003A990o
D:800389B0     Pgas_plant_wc_cub1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 783.8501, 3, 0, 0>
D:800389B0                                              # DATA XREF: D:8003A99Co
D:800389D0     Pgasplant_clear_doorZ_header:PitemZ_header <0, prop_door_related, 4, 1, 1025.0952, 2, 0, 0>
D:800389D0                                              # DATA XREF: D:8003A9A8o
D:800389F0     Ptrain_doorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 456.99615, 3, 0, 0>
D:800389F0                                              # DATA XREF: D:8003A9B4o
D:80038A10     Ptrain_door2Z_header:PitemZ_header <0, prop_door_related, 4, 1, 445.98541, 3, 0, 0>
D:80038A10                                              # DATA XREF: D:8003A9C0o
D:80038A30     Ptrain_door3Z_header:PitemZ_header <0, prop_door_related, 4, 1, 445.98541, 4, 0, 0>
D:80038A30                                              # DATA XREF: D:8003A9CCo
D:80038A50     Pdoor_eyelidZ_header:PitemZ_header <0, prop_eyelid_door_related, 3, 3, 3165.4348, 3, 0, 0>
D:80038A50                                              # DATA XREF: D:8003A9D8o
D:80038A70     Pdoor_irisZ_header:PitemZ_header <0, prop_iris_door_related, 0xD, 0xD, 1621.3601, 5, 0, 0>
D:80038A70                                              # DATA XREF: D:8003A9E4o
D:80038A90     PsevdoorwoodZ_header:PitemZ_header <0, prop_door_related, 4, 1, 851.62671, 3, 0, 0>
D:80038A90                                              # DATA XREF: D:8003A9F0o
D:80038AB0     PsevdoorwindZ_header:PitemZ_header <0, prop_door_related, 4, 1, 851.62671, 5, 0, 0>
D:80038AB0                                              # DATA XREF: D:8003A9FCo
D:80038AD0     PsevdoornowindZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 863.03766, 2, 0, 0>
D:80038AD0                                              # DATA XREF: D:8003AA08o
D:80038AF0     PsevdoormetslideZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 863.74707, 2, 0, 0>
D:80038AF0                                              # DATA XREF: D:8003AA14o
D:80038B10     Pcryptdoor1aZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 502.64923, 2, 0, 0>
D:80038B10                                              # DATA XREF: D:8003AA20o
D:80038B30     Pcryptdoor1bZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 400.97537, 2, 0, 0>
D:80038B30                                              # DATA XREF: D:8003AA2Co
D:80038B50     Pcryptdoor2aZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 502.64923, 2, 0, 0>
D:80038B50                                              # DATA XREF: D:8003AA38o
D:80038B70     Pcryptdoor2bZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 400.97537, 2, 0, 0>
D:80038B70                                              # DATA XREF: D:8003AA44o
D:80038B90     Pcryptdoor3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 801.95074, 3, 0, 0>
D:80038B90                                              # DATA XREF: D:8003AA50o
D:80038BB0     Pcryptdoor4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 801.95074, 1, 0, 0>
D:80038BB0                                              # DATA XREF: D:8003AA5Co
D:80038BD0     PvertdoorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1997.2246, 5, 0, 0>
D:80038BD0                                              # DATA XREF: D:8003AA68o
D:80038BF0     PhatchdoorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 192.1653, 1, 0, 0>
D:80038BF0                                              # DATA XREF: D:8003AA74o
D:80038C10     PdamgatedoorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 308.36456, 3, 0, 0>
D:80038C10                                              # DATA XREF: D:8003AA80o
D:80038C30     PdamtundoorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 127.89996, 4, 0, 0>
D:80038C30                                              # DATA XREF: D:8003AA8Co
D:80038C50     PdamchaindoorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 171.36655, 2, 0, 0>
D:80038C50                                              # DATA XREF: D:8003AA98o
D:80038C70     PsilotopdoorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2675.3958, 5, 0, 0>
D:80038C70                                              # DATA XREF: D:8003AAA4o
D:80038C90     Pdoorprison1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1062.0833, 1, 0, 0>
D:80038C90                                              # DATA XREF: D:8003AAB0o
D:80038CB0     PdoorstatgateZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1503.9503, 3, 0, 0>
D:80038CB0                                              # DATA XREF: D:8003AABCo
D:80038CD0     PchrkalashZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 403.53766, 8, 0, 0>
D:80038CD0                                              # DATA XREF: D:8003AAC8o
D:80038CF0     PchrgrenadelaunchZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 422.48355, 7, 0, 0>
D:80038CF0                                              # DATA XREF: D:8003AAD4o
D:80038D10     PchrknifeZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 245.14619, 2, 0, 0>
D:80038D10                                              # DATA XREF: D:8003AAE0o
D:80038D30     PchrlaserZ_header:PitemZ_header <0, prop_weapon_related, 3, 2, 444.66241, 8, 0, 0>
D:80038D30                                              # DATA XREF: D:8003AAECo
D:80038D50     Pchrm16Z_header:PitemZ_header <0, prop_weapon_related, 3, 2, 964.01367, 6, 0, 0>
D:80038D50                                              # DATA XREF: D:8003AAF8o
D:80038D70     Pchrmp5kZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 277.32227, 9, 0, 0>
D:80038D70                                              # DATA XREF: D:8003AB04o
D:80038D90     PchrrugerZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 246.72643, 5, 0, 0>
D:80038D90                                              # DATA XREF: D:8003AB10o
D:80038DB0     PchrwppkZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 125.79879, 5, 0, 0>
D:80038DB0                                              # DATA XREF: D:PchrwppkZ_entryo
D:80038DD0     PchrshotgunZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 488.88385, 8, 0, 0>
D:80038DD0                                              # DATA XREF: D:8003AB28o
D:80038DF0     PchrskorpionZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 183.37708, 7, 0, 0>
D:80038DF0                                              # DATA XREF: D:8003AB34o
D:80038E10     PchrspectreZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 351.26923, 6, 0, 0>
D:80038E10                                              # DATA XREF: D:8003AB40o
D:80038E30     PchruziZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 265.11813, 7, 0, 0>
D:80038E30                                              # DATA XREF: D:8003AB4Co
D:80038E50     PchrgrenadeZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 118.18749, 2, 0, 0>
D:80038E50                                              # DATA XREF: D:8003AB58o
D:80038E70     Pchrfnp90Z_header:PitemZ_header <0, prop_weapon_related, 3, 2, 470.04633, 7, 0, 0>
D:80038E70                                              # DATA XREF: D:8003AB64o
D:80038E90     PchrbriefcaseZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 342.23688, 5, 0, 0>
D:80038E90                                              # DATA XREF: D:8003AB70o
D:80038EB0     PchrremotemineZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 87.434036, 2, 0, 0>
D:80038EB0                                              # DATA XREF: D:8003AB7Co
D:80038ED0     PchrproximitymineZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 87.196609, 2, 0, 0>
D:80038ED0                                              # DATA XREF: D:8003AB88o
D:80038EF0     PchrtimedmineZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 87.245888, 3, 0, 0>
D:80038EF0                                              # DATA XREF: D:8003AB94o
D:80038F10     PchrrocketZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 342.8634, 3, 0, 0>
D:80038F10                                              # DATA XREF: D:8003ABA0o
D:80038F30     PchrgrenaderoundZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 96.976593, 1, 0, 0>
D:80038F30                                              # DATA XREF: D:8003ABACo
D:80038F50     PchrwppksilZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 219.44571, 6, 0, 0>
D:80038F50                                              # DATA XREF: D:8003ABB8o
D:80038F70     Pchrtt33Z_header:PitemZ_header <0, prop_weapon_related, 3, 1, 142.11539, 5, 0, 0>
D:80038F70                                              # DATA XREF: D:8003ABC4o
D:80038F90     Pchrmp5ksilZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 406.18033, 0xA, 0, 0>
D:80038F90                                              # DATA XREF: D:8003ABD0o
D:80038FB0     PchrautoshotZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 375.50247, 8, 0, 0>
D:80038FB0                                              # DATA XREF: D:8003ABDCo
D:80038FD0     PchrgoldenZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 157.98299, 2, 0, 0>
D:80038FD0                                              # DATA XREF: D:8003ABE8o
D:80038FF0     PchrthrowknifeZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 217.61888, 2, 0, 0>
D:80038FF0                                              # DATA XREF: D:8003ABF4o
D:80039010     PchrsniperrifleZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 616.93939, 5, 0, 0>
D:80039010                                              # DATA XREF: D:8003AC00o
D:80039030     PchrrocketlaunchZ_header:PitemZ_header <0, prop_weapon_related, 3, 2, 501.55179, 6, 0, 0>
D:80039030                                              # DATA XREF: D:8003AC0Co
D:80039050     PhatfurryZ_header:PitemZ_header <0, item_hat_related, 0, 1, 152.53136, 3, 0, 0>
D:80039050                                              # DATA XREF: D:8003AC18o
D:80039070     PhatfurrybrownZ_header:PitemZ_header <0, item_hat_related, 0, 1, 152.53136, 3, 0, 0>
D:80039070                                              # DATA XREF: D:8003AC24o
D:80039090     PhatfurryblackZ_header:PitemZ_header <0, item_hat_related, 0, 1, 152.53136, 3, 0, 0>
D:80039090                                              # DATA XREF: D:8003AC30o
D:800390B0     PhattbirdZ_header:PitemZ_header <0, item_hat_related, 0, 1, 114.45274, 1, 0, 0>
D:800390B0                                              # DATA XREF: D:8003AC3Co
D:800390D0     PhattbirdbrownZ_header:PitemZ_header <0, item_hat_related, 0, 1, 122.7013, 1, 0, 0>
D:800390D0                                              # DATA XREF: D:8003AC48o
D:800390F0     PhathelmetZ_header:PitemZ_header <0, item_hat_related, 0, 1, 163.84476, 1, 0, 0>
D:800390F0                                              # DATA XREF: D:8003AC54o
D:80039110     PhathelmetgreyZ_header:PitemZ_header <0, item_hat_related, 0, 1, 163.84476, 1, 0, 0>
D:80039110                                              # DATA XREF: D:8003AC60o
D:80039130     PhatmoonZ_header:PitemZ_header <0, item_hat_related, 0, 1, 138.25751, 2, 0, 0>
D:80039130                                              # DATA XREF: D:8003AC6Co
D:80039150     PhatberetZ_header:PitemZ_header <0, item_hat_related, 0, 1, 116.16043, 1, 0, 0>
D:80039150                                              # DATA XREF: D:8003AC78o
D:80039170     PhatberetblueZ_header:PitemZ_header <0, item_hat_related, 0, 1, 116.16043, 2, 0, 0>
D:80039170                                              # DATA XREF: D:8003AC84o
D:80039190     PhatberetredZ_header:PitemZ_header <0, item_hat_related, 0, 1, 115.46455, 2, 0, 0>
D:80039190                                              # DATA XREF: D:8003AC90o
D:800391B0     PhatpeakedZ_header:PitemZ_header <0, item_hat_related, 0, 1, 148.39027, 1, 0, 0>
D:800391B0                                              # DATA XREF: D:8003AC9Co
D:800391D0     PchrwristdartZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800391D0                                              # DATA XREF: D:8003ACA8o
D:800391F0     PchrexplosivepenZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800391F0                                              # DATA XREF: D:8003ACB4o
D:80039210     PchrbombcaseZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 342.23688, 5, 0, 0>
D:80039210                                              # DATA XREF: D:8003ACC0o
D:80039230     PchrflarepistolZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039230                                              # DATA XREF: D:8003ACCCo
D:80039250     PchrpitongunZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039250                                              # DATA XREF: D:8003ACD8o
D:80039270     PchrfingergunZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039270                                              # DATA XREF: D:8003ACE4o
D:80039290     PchrsilverwppkZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039290                                              # DATA XREF: D:8003ACF0o
D:800392B0     PchrgoldwppkZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800392B0                                              # DATA XREF: D:8003ACFCo
D:800392D0     PchrdynamiteZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800392D0                                              # DATA XREF: D:8003AD08o
D:800392F0     PchrbungeeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800392F0                                              # DATA XREF: D:8003AD14o
D:80039310     PchrdoordecoderZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 180.27969, 0x10, 0, 0>
D:80039310                                              # DATA XREF: D:8003AD20o
D:80039330     PchrbombdefuserZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 84.370705, 0xC, 0, 0>
D:80039330                                              # DATA XREF: D:8003AD2Co
D:80039350     PchrbugdetectorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039350                                              # DATA XREF: D:8003AD38o
D:80039370     PchrsafecrackercaseZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 342.23688, 5, 0, 0>
D:80039370                                              # DATA XREF: D:8003AD44o
D:80039390     PchrcameraZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 52.775627, 0xB, 0, 0>
D:80039390                                              # DATA XREF: D:8003AD50o
D:800393B0     PchrlockexploderZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800393B0                                              # DATA XREF: D:8003AD5Co
D:800393D0     PchrdoorexploderZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800393D0                                              # DATA XREF: D:8003AD68o
D:800393F0     PchrkeyanalysercaseZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 342.23688, 5, 0, 0>
D:800393F0                                              # DATA XREF: D:8003AD74o
D:80039410     PchrweaponcaseZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 274.2905, 5, 0, 0>
D:80039410                                              # DATA XREF: D:8003AD80o
D:80039430     PchrkeyyaleZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 82.850311, 1, 0, 0>
D:80039430                                              # DATA XREF: D:8003AD8Co
D:80039450     PchrkeyboltZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 151.85315, 1, 0, 0>
D:80039450                                              # DATA XREF: D:8003AD98o
D:80039470     PchrbugZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 104.7203, 6, 0, 0>
D:80039470                                              # DATA XREF: D:8003ADA4o
D:80039490     PchrmicrocameraZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 126.49728, 7, 0, 0>
D:80039490                                              # DATA XREF: D:8003ADB0o
D:800394B0     PfloppyZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 60.902443, 5, 0, 0>
D:800394B0                                              # DATA XREF: D:8003ADBCo
D:800394D0     PchrgoldeneyekeyZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 98.987083, 5, 0, 0>
D:800394D0                                              # DATA XREF: D:8003ADC8o
D:800394F0     PchrpolarizedglassesZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 53.776386, 2, 0, 0>
D:800394F0                                              # DATA XREF: D:8003ADD4o
D:80039510     PchrcreditcardZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039510                                              # DATA XREF: D:8003ADE0o
D:80039530     PchrdarkglassesZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039530                                              # DATA XREF: D:8003ADECo
D:80039550     PchrgaskeyringZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 111.59859, 9, 0, 0>
D:80039550                                              # DATA XREF: D:8003ADF8o
D:80039570     PchrdatathiefZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 119.78231, 3, 0, 0>
D:80039570                                              # DATA XREF: D:8003AE04o
D:80039590     PsafeZ_header:  PitemZ_header <0, model_object_standard_object, 0, 1, 1011.1874, 3, 0, 0>
D:80039590                                              # DATA XREF: D:8003AE10o
D:800395B0     PbombZ_header:  PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800395B0                                              # DATA XREF: D:8003AE1Co
D:800395D0     PchrplansZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 384.74649, 5, 0, 0>
D:800395D0                                              # DATA XREF: D:8003AE28o
D:800395F0     PchrspyfileZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800395F0                                              # DATA XREF: D:8003AE34o
D:80039610     PchrblueprintsZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 588.65448, 4, 0, 0>
D:80039610                                              # DATA XREF: D:8003AE40o
D:80039630     PchrcircuitboardZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 138.90285, 3, 0, 0>
D:80039630                                              # DATA XREF: D:8003AE4Co
D:80039650     PchrmapZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 588.65448, 4, 0, 0>
D:80039650                                              # DATA XREF: D:8003AE58o
D:80039670     PchrspooltapeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039670                                              # DATA XREF: D:8003AE64o
D:80039690     PchraudiotapeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 97.531075, 9, 0, 0>
D:80039690                                              # DATA XREF: D:8003AE70o
D:800396B0     PchrmicrofilmZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800396B0                                              # DATA XREF: D:8003AE7Co
D:800396D0     PchrmicrocodeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800396D0                                              # DATA XREF: D:8003AE88o
D:800396F0     PchrlectreZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:800396F0                                              # DATA XREF: D:8003AE94o
D:80039710     PchrmoneyZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039710                                              # DATA XREF: D:8003AEA0o
D:80039730     PchrgoldbarZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039730                                              # DATA XREF: D:8003AEACo
D:80039750     PchrheroinZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 288.67514, 1, 0, 0>
D:80039750                                              # DATA XREF: D:8003AEB8o
D:80039770     PchrclipboardZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 190.41742, 3, 0, 0>
D:80039770                                              # DATA XREF: D:8003AEC4o
D:80039790     PchrdossierredZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 183.54231, 4, 0, 0>
D:80039790                                              # DATA XREF: D:8003AED0o
D:800397B0     PchrstafflistZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 215.17534, 4, 0, 0>
D:800397B0                                              # DATA XREF: D:8003AEDCo
D:800397D0     PchrdattapeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 79.868584, 4, 0, 0>
D:800397D0                                              # DATA XREF: D:8003AEE8o
D:800397F0     PchrplastiqueZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 143.86052, 3, 0, 0>
D:800397F0                                              # DATA XREF: D:8003AEF4o
D:80039810     PchrblackboxZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 128.31796, 5, 0, 0>
D:80039810                                              # DATA XREF: D:8003AF00o
D:80039830     PchrvideotapeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 122.69632, 9, 0, 0>
D:80039830                                              # DATA XREF: D:8003AF0Co
D:80039850     PnintendologoZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1868.335, 1, 0, 0>
D:80039850                                              # DATA XREF: D:PnintendologoZ_entryo
D:80039870     PgoldeneyelogoZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1287.1866, 2, 0, 0>
D:80039870                                              # DATA XREF: D:PgoldeneyelogoZ_entryo
D:80039890     PwalletbondZ_header:PitemZ_header <0, prop_walletbond_related, 0x2B, 1, 3504.53, 0x54, 0, 0>
D:80039890                                              # DATA XREF: D:PwalletbondZ_entryo
D:800398B0     PmiltruckZ_header:PitemZ_header <0, prop_car_related, 0xB, 5, 4589.7188, 0x16, 0, 0>
D:800398B0                                              # DATA XREF: D:8003AF3Co
D:800398D0     PjeepZ_header:  PitemZ_header <0, prop_car_related, 0xB, 5, 2107.8105, 0x10, 0, 0>
D:800398D0                                              # DATA XREF: D:8003AF48o
D:800398F0     ParticZ_header: PitemZ_header <0, prop_car_related, 0xB, 5, 2678.5667, 0x11, 0, 0>
D:800398F0                                              # DATA XREF: D:8003AF54o
D:80039910     PhelicopterZ_header:PitemZ_header <0, prop_flying_related, 6, 4, 4955.271, 0x18, 0, 0>
D:80039910                                              # DATA XREF: D:8003AF60o
D:80039930     PtigerZ_header: PitemZ_header <0, prop_flying_related, 6, 4, 4072.0291, 0xE, 0, 0>
D:80039930                                              # DATA XREF: D:8003AF6Co
D:80039950     PmilcopterZ_header:PitemZ_header <0, prop_flying_related, 6, 4, 5316.9155, 0xF, 0, 0>
D:80039950                                              # DATA XREF: D:8003AF78o
D:80039970     PhindZ_header:  PitemZ_header <0, prop_flying_related, 6, 5, 5315.314, 0xB, 0, 0>
D:80039970                                              # DATA XREF: D:8003AF84o
D:80039990     PartictrailerZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 4014.6265, 0xB, 0, 0>
D:80039990                                              # DATA XREF: D:8003AF90o
D:800399B0     PmotorbikeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1610.8706, 6, 0, 0>
D:800399B0                                              # DATA XREF: D:8003AF9Co
D:800399D0     PtankZ_header:  PitemZ_header <0, item_tank_related, 9, 5, 6290.8398, 0x18, 0, 0>
D:800399D0                                              # DATA XREF: D:8003AFA8o
D:800399F0     PapcZ_header:   PitemZ_header <0, model_object_standard_object, 0, 1, 3611.1035, 0xE, 0, 0>
D:800399F0                                              # DATA XREF: D:8003AFB4o
D:80039A10     PspeedboatZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1799.4586, 0xD, 0, 0>
D:80039A10                                              # DATA XREF: D:8003AFC0o
D:80039A30     PplaneZ_header: PitemZ_header <0, prop_flying_related, 6, 3, 9285.4492, 0x1C, 0, 0>
D:80039A30                                              # DATA XREF: D:8003AFCCo
D:80039A50     Pgun_runway1Z_header:PitemZ_header <0, prop_rotating_stuff_related, 8, 5, 1927.5205, 6, 0, 0>
D:80039A50                                              # DATA XREF: D:8003AFD8o
D:80039A70     PsafedoorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 714.14612, 4, 0, 0>
D:80039A70                                              # DATA XREF: D:8003AFE4o
D:80039A90     Pkey_holderZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 223.87097, 7, 0, 0>
D:80039A90                                              # DATA XREF: D:8003AFF0o
D:80039AB0     PhatchsevxZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1224.7664, 2, 0, 0>
D:80039AB0                                              # DATA XREF: D:8003AFFCo
D:80039AD0     PsevdishZ_header:PitemZ_header <0, prop_rotating_stuff_related, 8, 3, 14350.1, 7, 0, 0>
D:80039AD0                                              # DATA XREF: D:8003B008o
D:80039AF0     Parchsecdoor1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 455.81409, 3, 0, 0>
D:80039AF0                                              # DATA XREF: D:8003B014o
D:80039B10     Parchsecdoor2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 496.99292, 3, 0, 0>
D:80039B10                                              # DATA XREF: D:8003B020o
D:80039B30     PgroundgunZ_header:PitemZ_header <0, prop_rotating_stuff_related, 8, 5, 2182.6472, 4, 0, 0>
D:80039B30                                              # DATA XREF: D:8003B02Co
D:80039B50     PtrainextdoorZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 587.70111, 5, 0, 0>
D:80039B50                                              # DATA XREF: D:8003B038o
D:80039B70     PcarbmwZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 553.08728, 0xB, 0, 0>
D:80039B70                                              # DATA XREF: D:8003B044o
D:80039B90     PcarescortZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1110.5665, 9, 0, 0>
D:80039B90                                              # DATA XREF: D:8003B050o
D:80039BB0     PcargolfZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1121.6409, 0xA, 0, 0>
D:80039BB0                                              # DATA XREF: D:8003B05Co
D:80039BD0     PcarweirdZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 984.03931, 0xD, 0, 0>
D:80039BD0                                              # DATA XREF: D:8003B068o
D:80039BF0     PcarzilZ_header:PitemZ_header <0, prop_car_related, 0xB, 5, 1044.5764, 0xD, 0, 0>
D:80039BF0                                              # DATA XREF: D:8003B074o
D:80039C10     Pshuttle_door_lZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 706.56641, 7, 0, 0>
D:80039C10                                              # DATA XREF: D:8003B080o
D:80039C30     Pshuttle_door_rZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 706.56641, 8, 0, 0>
D:80039C30                                              # DATA XREF: D:8003B08Co
D:80039C50     Pdepot_gate_entryZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 811.28949, 3, 0, 0>
D:80039C50                                              # DATA XREF: D:8003B098o
D:80039C70     Pdepot_door_steelZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 574.79651, 3, 0, 0>
D:80039C70                                              # DATA XREF: D:8003B0A4o
D:80039C90     Pglassware2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 98.488579, 3, 0, 0>
D:80039C90                                              # DATA XREF: D:8003B0B0o
D:80039CB0     Pglassware3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 137.92715, 1, 0, 0>
D:80039CB0                                              # DATA XREF: D:8003B0BCo
D:80039CD0     Pglassware4Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 177.48241, 2, 0, 0>
D:80039CD0                                              # DATA XREF: D:8003B0C8o
D:80039CF0     PlandmineZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 440.03009, 2, 0, 0>
D:80039CF0                                              # DATA XREF: D:8003B0D4o
D:80039D10     Pplant1Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2704.1086, 1, 0, 0>
D:80039D10                                              # DATA XREF: D:8003B0E0o
D:80039D30     Pplant11Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2704.1086, 1, 0, 0>
D:80039D30                                              # DATA XREF: D:8003B0ECo
D:80039D50     Pplant2Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 3416.248, 2, 0, 0>
D:80039D50                                              # DATA XREF: D:8003B0F8o
D:80039D70     Pplant3Z_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2986.0405, 1, 0, 0>
D:80039D70                                              # DATA XREF: D:8003B104o
D:80039D90     Pjungle5_treeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 3277.6123, 4, 0, 0>
D:80039D90                                              # DATA XREF: D:8003B110o
D:80039DB0     PlegalpageZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2711.7573, 5, 0, 0>
D:80039DB0                                              # DATA XREF: D:PlegalpageZ_entryo
D:80039DD0     Pst_pete_room_1iZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 8437.5137, 0x17, 0, 0>
D:80039DD0                                              # DATA XREF: D:8003B128o
D:80039DF0     Pst_pete_room_2iZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 8515.8164, 0x19, 0, 0>
D:80039DF0                                              # DATA XREF: D:8003B134o
D:80039E10     Pst_pete_room_3tZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 4561.9766, 0x1B, 0, 0>
D:80039E10                                              # DATA XREF: D:8003B140o
D:80039E30     Pst_pete_room_5cZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 4561.9766, 0x19, 0, 0>
D:80039E30                                              # DATA XREF: D:8003B14Co
D:80039E50     Pst_pete_room_6cZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 5006.2896, 0x17, 0, 0>
D:80039E50                                              # DATA XREF: D:8003B158o
D:80039E70     Pdoor_rollertrainZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 1032.125, 2, 0, 0>
D:80039E70                                              # DATA XREF: D:8003B164o
D:80039E90     Pdoor_winZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 211.90215, 1, 0, 0>
D:80039E90                                              # DATA XREF: D:8003B170o
D:80039EB0     Pdoor_aztecZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 632.48639, 1, 0, 0>
D:80039EB0                                              # DATA XREF: D:8003B17Co
D:80039ED0     PshuttleZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 4475.1494, 9, 0, 0>
D:80039ED0                                              # DATA XREF: D:8003B188o
D:80039EF0     Pdoor_azt_deskZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 860.41669, 2, 0, 0>
D:80039EF0                                              # DATA XREF: D:8003B194o
D:80039F10     Pdoor_azt_desk_topZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 565.93268, 3, 0, 0>
D:80039F10                                              # DATA XREF: D:8003B1A0o
D:80039F30     Pdoor_azt_chairZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 94.510803, 3, 0, 0>
D:80039F30                                              # DATA XREF: D:8003B1ACo
D:80039F50     Pdoor_mfZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 559.70367, 7, 0, 0>
D:80039F50                                              # DATA XREF: D:8003B1B8o
D:80039F70     PflagZ_header:  PitemZ_header <0, prop_weapon_related, 3, 1, 862.30865, 2, 0, 0>
D:80039F70                                              # DATA XREF: D:8003B1C4o
D:80039F90     PbarricadeZ_header:PitemZ_header <0, model_object_standard_object, 0, 1, 2047.3016, 2, 0, 0>
D:80039F90                                              # DATA XREF: D:8003B1D0o
D:80039FB0     PmodemboxZ_header:PitemZ_header <0, prop_console_one_screen_related, 1, 1, 338.28839, 4, 0, 0>
D:80039FB0                                              # DATA XREF: D:8003B1DCo
D:80039FD0     PdoorpanelZ_header:PitemZ_header <0, prop_console_four_screen_related, 4, 1, 338.28839, 4, 0, 0>
D:80039FD0                                              # DATA XREF: D:8003B1E8o
D:80039FF0     PdoorconsoleZ_header:PitemZ_header <0, prop_console_one_screen_related, 1, 1, 994.23688, 0xD, 0, 0>
D:80039FF0                                              # DATA XREF: D:8003B1F4o
D:8003A010     PchrtesttubeZ_header:PitemZ_header <0, prop_weapon_related, 3, 1, 136.25925, 2, 0, 0>
D:8003A010                                              # DATA XREF: D:8003B200o
D:8003A030     Pbollardz_header:PitemZ_header <0, model_object_standard_object, 0, 1, 628.78754, 1, 0, 0>
D:8003A030                                              # DATA XREF: D:8003B20Co
D:8003A050     word_D_8003A050:.half 2                  # DATA XREF: D:prop_cctv_relatedo
D:8003A052                     .half 0
D:8003A054                     .half 0
D:8003A056                     .half 2
D:8003A058                     .half 3
D:8003A05A                     .half 3
D:8003A05C     prop_cctv_related:item_related <2, 0, word_D_8003A050, 6, 0>
D:8003A05C                                              # DATA XREF: sub_CODE_7F04EA68+2C8o
D:8003A05C                                              # sub_CODE_7F04EA68+358o
D:8003A05C                                              # D:PcctvZ_headero
D:8003A068     word_D_8003A068:.half 2                  # DATA XREF: D:prop_console_one_screen_relatedo
D:8003A06A                     .half 0
D:8003A06C                     .half 0
D:8003A06E                     .half 0
D:8003A070     prop_console_one_screen_related:item_related <1, 0, word_D_8003A068, 3, 0>
D:8003A070                                              # DATA XREF: sub_CODE_7F04B590+4o
D:8003A070                                              # D:Pbridge_console1bZ_headero
D:8003A070                                              # D:Pconsole_sevbZ_headero
D:8003A070                                              # D:Pconsole_sev2bZ_headero
D:8003A070                                              # D:Ptv1Z_headero
D:8003A070                                              # D:PtvscreenZ_headero
D:8003A070                                              # D:Ptuning_console1Z_headero
D:8003A070                                              # D:PmodemboxZ_headero
D:8003A070                                              # D:PdoorconsoleZ_headero
D:8003A07C     word_D_8003A07C:.half 2                  # DATA XREF: D:prop_console_four_screen_relatedo
D:8003A07E                     .half 0
D:8003A080                     .half 0
D:8003A082                     .half 0
D:8003A084     prop_console_four_screen_related:item_related <1, 0, word_D_8003A07C, 3, 0>
D:8003A084                                              # DATA XREF: sub_CODE_7F04B590:loc_CODE_7F04B5BCo
D:8003A084                                              # D:Pbridge_console1aZ_headero
D:8003A084                                              # D:Pbridge_console2aZ_headero
D:8003A084                                              # D:Pbridge_console3aZ_headero
D:8003A084                                              # D:Pbridge_console3bZ_headero
D:8003A084                                              # D:Pconsole1Z_headero
D:8003A084                                              # D:Pconsole2Z_headero
D:8003A084                                              # D:Pconsole3Z_headero
D:8003A084                                              # D:Ptv4screenZ_headero
D:8003A084                                              # D:PdoorpanelZ_headero
D:8003A090     word_D_8003A090:.half 2                  # DATA XREF: D:prop_tv_holder_relatedo
D:8003A092                     .half 0
D:8003A094                     .half 0
D:8003A096                     .half 2
D:8003A098                     .half 3
D:8003A09A                     .half 3
D:8003A09C                     .half 2
D:8003A09E                     .half 6
D:8003A0A0                     .half 6
D:8003A0A2                     .half 2
D:8003A0A4                     .half 9
D:8003A0A6                     .half 9
D:8003A0A8                     .half 2
D:8003A0AA                     .half 0xC
D:8003A0AC                     .half 0xC
D:8003A0AE                     .half 0
D:8003A0B0     prop_tv_holder_related:item_related <5, 0, word_D_8003A090, 0xF, 0>
D:8003A0B0                                              # DATA XREF: D:Ptv_holderZ_headero
D:8003A0BC     word_D_8003A0BC:.half 2                  # DATA XREF: D:prop_rotating_stuff_relatedo
D:8003A0BE                     .half 0
D:8003A0C0                     .half 0
D:8003A0C2                     .half 2
D:8003A0C4                     .half 3
D:8003A0C6                     .half 3
D:8003A0C8                     .half 2
D:8003A0CA                     .half 6
D:8003A0CC                     .half 6
D:8003A0CE                     .half 2
D:8003A0D0                     .half 9
D:8003A0D2                     .half 9
D:8003A0D4                     .half 2
D:8003A0D6                     .half 0xC
D:8003A0D8                     .half 0xC
D:8003A0DA                     .half 2
D:8003A0DC                     .half 0xF
D:8003A0DE                     .half 0xF
D:8003A0E0     prop_rotating_stuff_related:item_related <6, 0, word_D_8003A0BC, 0x12, 0>
D:8003A0E0                                              # DATA XREF: D:ProofgunZ_headero
D:8003A0E0                                              # D:Pgun_runway1Z_headero
D:8003A0E0                                              # D:PsevdishZ_headero
D:8003A0E0                                              # D:PgroundgunZ_headero
D:8003A0EC     word_D_8003A0EC:.half 2                  # DATA XREF: D:prop_eyelid_door_relatedo
D:8003A0EE                     .half 0
D:8003A0F0                     .half 0
D:8003A0F2                     .half 2
D:8003A0F4                     .half 3
D:8003A0F6                     .half 3
D:8003A0F8                     .half 2
D:8003A0FA                     .half 6
D:8003A0FC                     .half 6
D:8003A0FE                     .half 0
D:8003A100     prop_eyelid_door_related:item_related <3, 0, word_D_8003A0EC, 9, 0>
D:8003A100                                              # DATA XREF: object_interaction+31D0o
D:8003A100                                              # D:Pdoor_eyelidZ_headero
D:8003A10C     word_D_8003A10C:.half 2                  # DATA XREF: D:prop_iris_door_relatedo
D:8003A10E                     .half 0
D:8003A110                     .word 2
D:8003A114                     .half 3
D:8003A116                     .half 3
D:8003A118                     .half 2
D:8003A11A                     .half 6
D:8003A11C                     .half 6
D:8003A11E                     .half 2
D:8003A120                     .half 9
D:8003A122                     .half 9
D:8003A124                     .half 2
D:8003A126                     .half 0xC
D:8003A128                     .half 0xC
D:8003A12A                     .half 2
D:8003A12C                     .half 0xF
D:8003A12E                     .half 0xF
D:8003A130                     .half 2
D:8003A132                     .half 0x12
D:8003A134                     .half 0x12
D:8003A136                     .half 2
D:8003A138                     .half 0x15
D:8003A13A                     .half 0x15
D:8003A13C                     .half 2
D:8003A13E                     .half 0x18
D:8003A140                     .half 0x18
D:8003A142                     .half 2
D:8003A144                     .half 0x1B
D:8003A146                     .half 0x1B
D:8003A148                     .half 2
D:8003A14A                     .half 0x1E
D:8003A14C                     .half 0x1E
D:8003A14E                     .half 2
D:8003A150                     .half 0x21
D:8003A152                     .half 0x21
D:8003A154                     .half 2
D:8003A156                     .half 0x24
D:8003A158                     .half 0x24
D:8003A15A                     .half 0
D:8003A15C     prop_iris_door_related:item_related <0xD, 0, word_D_8003A10C, 0x27, 0>
D:8003A15C                                              # DATA XREF: object_interaction+31E8o
D:8003A15C                                              # D:Pdoor_irisZ_headero
D:8003A168     word_D_8003A168:.half 2                  # DATA XREF: D:prop_walletbond_relatedo
D:8003A16A                     .half 0
D:8003A16C                     .half 0
D:8003A16E                     .half 0
D:8003A170     prop_walletbond_related:item_related <1, 0, word_D_8003A168, 3, 0>
D:8003A170                                              # DATA XREF: D:PwalletbondZ_headero
D:8003A17C     word_D_8003A17C:.half 2                  # DATA XREF: D:prop_car_relatedo
D:8003A17E                     .half 0
D:8003A180                     .word 2
D:8003A184                     .half 3
D:8003A186                     .half 3
D:8003A188                     .half 2
D:8003A18A                     .half 6
D:8003A18C                     .half 6
D:8003A18E                     .half 2
D:8003A190                     .half 9
D:8003A192                     .half 9
D:8003A194                     .half 2
D:8003A196                     .half 0xC
D:8003A198                     .half 0xC
D:8003A19A                     .half 0
D:8003A19C     prop_car_related:item_related <5, 0, word_D_8003A17C, 0xF, 0>
D:8003A19C                                              # DATA XREF: D:PmiltruckZ_headero
D:8003A19C                                              # D:PjeepZ_headero
D:8003A19C                                              # D:ParticZ_headero
D:8003A19C                                              # D:PcarzilZ_headero
D:8003A1A8     word_D_8003A1A8:.half 0x401              # DATA XREF: D:prop_flying_relatedo
D:8003A1AA                     .half 0
D:8003A1AC                     .half 0
D:8003A1AE                     .half 2
D:8003A1B0                     .half 0
D:8003A1B2                     .half 0
D:8003A1B4                     .half 0x15
D:8003A1B6                     .half 3
D:8003A1B8                     .half 3
D:8003A1BA                     .half 0x15
D:8003A1BC                     .half 4
D:8003A1BE                     .half 4
D:8003A1C0                     .half 0x15
D:8003A1C2                     .half 5
D:8003A1C4                     .half 5
D:8003A1C6                     .half 0
D:8003A1C8     prop_flying_related:item_related <5, 0, word_D_8003A1A8, 3, 0>
D:8003A1C8                                              # DATA XREF: D:PhelicopterZ_headero
D:8003A1C8                                              # D:PtigerZ_headero
D:8003A1C8                                              # D:PmilcopterZ_headero
D:8003A1C8                                              # D:PhindZ_headero
D:8003A1C8                                              # D:PplaneZ_headero
D:8003A1D4     word_D_8003A1D4:.half 2                  # DATA XREF: D:prop_door_relatedo
D:8003A1D6                     .half 0
D:8003A1D8                     .half 0
D:8003A1DA                     .half 0
D:8003A1DC     prop_door_related:item_related <1, 0, word_D_8003A1D4, 3, 0>
D:8003A1DC                                              # DATA XREF: object_interaction:loc_CODE_7F048350o
D:8003A1DC                                              # sub_CODE_7F04E720:loc_CODE_7F04E92Co
D:8003A1DC                                              # sub_CODE_7F04EA68+1B0o
D:8003A1DC                                              # sub_CODE_7F04EA68+288o
D:8003A1DC                                              # sub_CODE_7F04EA68+3DCo
D:8003A1DC                                              # D:Psev_door4_windZ_headero
D:8003A1DC                                              # D:Psev_trislideZ_headero
D:8003A1DC                                              # D:Pgasplant_clear_doorZ_headero
D:8003A1DC                                              # D:Ptrain_door2Z_headero
D:8003A1DC                                              # D:Ptrain_door3Z_headero
D:8003A1DC                                              # D:PsevdoorwoodZ_headero
D:8003A1DC                                              # D:PsevdoorwindZ_headero
D:8003A1E8     word_D_8003A1E8:.half 2                  # DATA XREF: D:item_tank_relatedo
D:8003A1EA                     .half 0
D:8003A1EC                     .half 0
D:8003A1EE                     .half 2
D:8003A1F0                     .half 3
D:8003A1F2                     .half 3
D:8003A1F4                     .half 2
D:8003A1F6                     .half 6
D:8003A1F8                     .half 6
D:8003A1FA                     .half 2
D:8003A1FC                     .half 9
D:8003A1FE                     .half 9
D:8003A200                     .half 2
D:8003A202                     .half 0xC
D:8003A204                     .half 0xC
D:8003A206                     .half 0
D:8003A208     item_tank_related:item_related <5, 0, word_D_8003A1E8, 0xF, 0>
D:8003A208                                              # DATA XREF: D:PtankZ_headero
D:8003A214     word_D_8003A214:.half 0x15               # DATA XREF: D:item_hat_relatedo
D:8003A216                     .half 0
D:8003A218                     .half 0
D:8003A21A                     .half 0
D:8003A21C     item_hat_related:item_related <1, 0, word_D_8003A214, 0, 0>
D:8003A21C                                              # DATA XREF: D:PhatfurryZ_headero
D:8003A21C                                              # D:PhatfurrybrownZ_headero
D:8003A21C                                              # D:PhatfurryblackZ_headero
D:8003A21C                                              # D:PhattbirdZ_headero
D:8003A21C                                              # D:PhattbirdbrownZ_headero
D:8003A21C                                              # D:PhathelmetZ_headero
D:8003A21C                                              # D:PhathelmetgreyZ_headero
D:8003A21C                                              # D:PhatmoonZ_headero
D:8003A21C                                              # D:PhatberetZ_headero
D:8003A21C                                              # D:PhatberetblueZ_headero
D:8003A21C                                              # D:PhatberetredZ_headero
D:8003A21C                                              # D:PhatpeakedZ_headero
D:8003A228                     .globl PitemZ_entries
D:8003A228     PitemZ_entries: p_itementry <Palarm1z_header, aPalarm1z, 0.1>
D:8003A228                                              # DATA XREF: prepare_load_objects+14Cr
D:8003A228                                              # prepare_load_objects+1FCr
D:8003A228                                              # prepare_load_objects+590r
D:8003A228                                              # stage_loading_setup_objparse_cleanupafter+A4o
D:8003A228                                              # sub_CODE_7F008E80+2D0o
D:8003A228                                              # init_menu00_legalscreen+4Co
D:8003A228                                              # init_menu01_nintendo+38o
D:8003A228                                              # init_menu04_goldeneyelogo+38o
D:8003A228                                              # load_walletbond+24o
D:8003A228                                              # init_menu18_displaycast+4E0o
D:8003A228                                              # maybe_detonate_object+3DCr
D:8003A228                                              # sub_CODE_7F0510C0+10r
D:8003A228                                              # create_new_item_instance_of_model+10r
D:8003A228                                              # something_with_generating_object+38r
D:8003A228                                              # load_model+8o
D:8003A228                                              # solo_char_load+664o
D:8003A228                                              # "Palarm1Z"
D:8003A234                     p_itementry <Palarm2Z_header, aPalarm2z, 0.1>  # "Palarm2Z"
D:8003A240                     p_itementry <PexplosionbitZ_header, aPexplosionbitz, 0.1>  # "PexplosionbitZ"
D:8003A24C                     p_itementry <Pammo_crate1Z_header, aPammo_crate1z, 0.1>  # "Pammo_crate1Z"
D:8003A258                     p_itementry <Pammo_crate2Z_header, aPammo_crate2z, 0.1>  # "Pammo_crate2Z"
D:8003A264                     p_itementry <Pammo_crate3Z_header, aPammo_crate3z, 0.1>  # "Pammo_crate3Z"
D:8003A270                     p_itementry <Pammo_crate4Z_header, aPammo_crate4z, 0.1>  # "Pammo_crate4Z"
D:8003A27C                     p_itementry <Pammo_crate5Z_header, aPammo_crate5z, 0.1>  # "Pammo_crate5Z"
D:8003A288                     p_itementry <Pbin1Z_header, aPbin1z, 0.1>  # "Pbin1Z"
D:8003A294                     p_itementry <Pblotter1Z_header, aPblotter1z, 0.1>  # "Pblotter1Z"
D:8003A2A0                     p_itementry <Pbook1Z_header, aPbook1z, 0.1>  # "Pbook1Z"
D:8003A2AC                     p_itementry <Pbookshelf1Z_header, aPbookshelf1z, 0.1>  # "Pbookshelf1Z"
D:8003A2B8                     p_itementry <Pbridge_console1aZ_header, aPbridge_console1az, 0.1>  # "Pbridge_console1aZ"
D:8003A2C4                     p_itementry <Pbridge_console1bZ_header, aPbridge_console1bz, 0.1>  # "Pbridge_console1bZ"
D:8003A2D0                     p_itementry <Pbridge_console2aZ_header, aPbridge_console2az, 0.1>  # "Pbridge_console2aZ"
D:8003A2DC                     p_itementry <Pbridge_console2bZ_header, aPbridge_console2bz, 0.1>  # "Pbridge_console2bZ"
D:8003A2E8                     p_itementry <Pbridge_console3aZ_header, aPbridge_console3az, 0.1>  # "Pbridge_console3aZ"
D:8003A2F4                     p_itementry <Pbridge_console3bZ_header, aPbridge_console3bz, 0.1>  # "Pbridge_console3bZ"
D:8003A300                     p_itementry <Pcard_box1Z_header, aPcard_box1z, 0.1>  # "Pcard_box1Z"
D:8003A30C                     p_itementry <Pcard_box2Z_header, aPcard_box2z, 0.1>  # "Pcard_box2Z"
D:8003A318                     p_itementry <Pcard_box3Z_header, aPcard_box3z, 0.1>  # "Pcard_box3Z"
D:8003A324                     p_itementry <Pcard_box4_lgZ_header, aPcard_box4_lgz, 0.1>  # "Pcard_box4_lgZ"
D:8003A330                     p_itementry <Pcard_box5_lgZ_header, aPcard_box5_lgz, 0.1>  # "Pcard_box5_lgZ"
D:8003A33C                     p_itementry <Pcard_box6_lgZ_header, aPcard_box6_lgz, 0.1>  # "Pcard_box6_lgZ"
D:8003A348                     p_itementry <PcctvZ_header, aPcctvz, 0.1>  # "PcctvZ"
D:8003A354                     p_itementry <Pconsole1Z_header, aPconsole1z, 0.1>  # "Pconsole1Z"
D:8003A360                     p_itementry <Pconsole2Z_header, aPconsole2z, 0.1>  # "Pconsole2Z"
D:8003A36C                     p_itementry <Pconsole3Z_header, aPconsole3z, 0.1>  # "Pconsole3Z"
D:8003A378                     p_itementry <Pconsole_sevaZ_header, aPconsole_sevaz, 0.1>  # "Pconsole_sevaZ"
D:8003A384                     p_itementry <Pconsole_sevbZ_header, aPconsole_sevbz, 0.1>  # "Pconsole_sevbZ"
D:8003A390                     p_itementry <Pconsole_sevcZ_header, aPconsole_sevcz, 0.1>  # "Pconsole_sevcZ"
D:8003A39C                     p_itementry <Pconsole_sevdZ_header, aPconsole_sevdz, 0.1>  # "Pconsole_sevdZ"
D:8003A3A8                     p_itementry <Pconsole_sev2aZ_header, aPconsole_sev2az, 0.1>  # "Pconsole_sev2aZ"
D:8003A3B4                     p_itementry <Pconsole_sev2bZ_header, aPconsole_sev2bz, 0.1>  # "Pconsole_sev2bZ"
D:8003A3C0                     p_itementry <Pconsole_sev2cZ_header, aPconsole_sev2cz, 0.1>  # "Pconsole_sev2cZ"
D:8003A3CC                     p_itementry <Pconsole_sev2dZ_header, aPconsole_sev2dz, 0.1>  # "Pconsole_sev2dZ"
D:8003A3D8                     p_itementry <Pconsole_sev_GEaZ_header, aPconsole_sev_geaz, 0.1>  # "Pconsole_sev_GEaZ"
D:8003A3E4                     p_itementry <Pconsole_sev_GEbZ_header, aPconsole_sev_gebz, 0.1>  # "Pconsole_sev_GEbZ"
D:8003A3F0                     p_itementry <Pdesk1Z_header, aPdesk1z, 0.1>  # "Pdesk1Z"
D:8003A3FC                     p_itementry <Pdesk2Z_header, aPdesk2z, 0.1>  # "Pdesk2Z"
D:8003A408                     p_itementry <Pdesk_lamp2Z_header, aPdesk_lamp2z, 0.1>  # "Pdesk_lamp2Z"
D:8003A414                     p_itementry <Pdisc_readerZ_header, aPdisc_readerz, 0.1>  # "Pdisc_readerZ"
D:8003A420                     p_itementry <Pdisk_drive1Z_header, aPdisk_drive1z, 0.1>  # "Pdisk_drive1Z"
D:8003A42C                     p_itementry <Pfiling_cabinet1Z_header, aPfiling_cabinet1z, 0.1>  # "Pfiling_cabinet1Z"
D:8003A438                     p_itementry <Pjerry_can1Z_header, aPjerry_can1z, 0.1>  # "Pjerry_can1Z"
D:8003A444                     p_itementry <Pkeyboard1Z_header, aPkeyboard1z, 0.1>  # "Pkeyboard1Z"
D:8003A450                     p_itementry <Pkit_units1Z_header, aPkit_units1z, 0.1>  # "Pkit_units1Z"
D:8003A45C                     p_itementry <Pletter_tray1Z_header, aPletter_tray1z, 0.1>  # "Pletter_tray1Z"
D:8003A468                     p_itementry <Pmainframe1Z_header, aPmainframe1z, 0.1>  # "Pmainframe1Z"
D:8003A474                     p_itementry <Pmainframe2Z_header, aPmainframe2z, 0.1>  # "Pmainframe2Z"
D:8003A480                     p_itementry <Pmetal_chair1Z_header, aPmetal_chair1z, 0.1>  # "Pmetal_chair1Z"
D:8003A48C                     p_itementry <Pmetal_crate1Z_header, aPmetal_crate1z, 0.1>  # "Pmetal_crate1Z"
D:8003A498                     p_itementry <Pmetal_crate2Z_header, aPmetal_crate2z, 0.1>  # "Pmetal_crate2Z"
D:8003A4A4                     p_itementry <Pmetal_crate3Z_header, aPmetal_crate3z, 0.1>  # "Pmetal_crate3Z"
D:8003A4B0                     p_itementry <Pmetal_crate4Z_header, aPmetal_crate4z, 0.1>  # "Pmetal_crate4Z"
D:8003A4BC                     p_itementry <Pmissile_rackZ_header, aPmissile_rackz, 0.1>  # "Pmissile_rackZ"
D:8003A4C8                     p_itementry <Pmissile_rack2Z_header, aPmissile_rack2z, 0.1>  # "Pmissile_rack2Z"
D:8003A4D4                     p_itementry <Poil_drum1Z_header, aPoil_drum1z, 0.1>  # "Poil_drum1Z"
D:8003A4E0                     p_itementry <Poil_drum2Z_header, aPoil_drum2z, 0.1>  # "Poil_drum2Z"
D:8003A4EC                     p_itementry <Poil_drum3Z_header, aPoil_drum3z, 0.1>  # "Poil_drum3Z"
D:8003A4F8                     p_itementry <Poil_drum5Z_header, aPoil_drum5z, 0.1>  # "Poil_drum5Z"
D:8003A504                     p_itementry <Poil_drum6Z_header, aPoil_drum6z, 0.1>  # "Poil_drum6Z"
D:8003A510                     p_itementry <Poil_drum7Z_header, aPoil_drum7z, 0.1>  # "Poil_drum7Z"
D:8003A51C                     p_itementry <PpadlockZ_header, aPpadlockz, 0.1>  # "PpadlockZ"
D:8003A528                     p_itementry <Pphone1Z_header, aPphone1z, 0.1>  # "Pphone1Z"
D:8003A534                     p_itementry <Pradio_unit1Z_header, aPradio_unit1z, 0.1>  # "Pradio_unit1Z"
D:8003A540                     p_itementry <Pradio_unit2Z_header, aPradio_unit2z, 0.1>  # "Pradio_unit2Z"
D:8003A54C                     p_itementry <Pradio_unit3Z_header, aPradio_unit3z, 0.1>  # "Pradio_unit3Z"
D:8003A558                     p_itementry <Pradio_unit4Z_header, aPradio_unit4z, 0.1>  # "Pradio_unit4Z"
D:8003A564                     p_itementry <Psat1_reflectZ_header, aPsat1_reflectz, 0.1>  # "Psat1_reflectZ"
D:8003A570                     p_itementry <PsatdishZ_header, aPsatdishz, 0.1>  # "PsatdishZ"
D:8003A57C                     p_itementry <PsatboxZ_header, aPsatboxz, 0.1>  # "PsatboxZ"
D:8003A588                     p_itementry <Pstool1Z_header, aPstool1z, 0.1>  # "Pstool1Z"
D:8003A594                     p_itementry <Pswivel_chair1Z_header, aPswivel_chair1z, 0.1>  # "Pswivel_chair1Z"
D:8003A5A0                     p_itementry <Ptorpedo_rackZ_header, aPtorpedo_rackz, 0.1>  # "Ptorpedo_rackZ"
D:8003A5AC                     p_itementry <Ptv1Z_header, aPtv1z, 0.1>  # "Ptv1Z"
D:8003A5B8                     p_itementry <Ptv_holderZ_header, aPtv_holderz, 0.1>  # "Ptv_holderZ"
D:8003A5C4                     p_itementry <PtvscreenZ_header, aPtvscreenz, 0.1>  # "PtvscreenZ"
D:8003A5D0                     p_itementry <Ptv4screenZ_header, aPtv4screenz, 0.1>  # "Ptv4screenZ"
D:8003A5DC                     p_itementry <Pwood_lg_crate1Z_header, aPwood_lg_crate1z, 0.1>  # "Pwood_lg_crate1Z"
D:8003A5E8                     p_itementry <Pwood_lg_crate2Z_header, aPwood_lg_crate2z, 0.1>  # "Pwood_lg_crate2Z"
D:8003A5F4                     p_itementry <Pwood_md_crate3Z_header, aPwood_md_crate3z, 0.1>  # "Pwood_md_crate3Z"
D:8003A600                     p_itementry <Pwood_sm_crate4Z_header, aPwood_sm_crate4z, 0.1>  # "Pwood_sm_crate4Z"
D:8003A60C                     p_itementry <Pwood_sm_crate5Z_header, aPwood_sm_crate5z, 0.1>  # "Pwood_sm_crate5Z"
D:8003A618                     p_itementry <Pwood_sm_crate6Z_header, aPwood_sm_crate6z, 0.1>  # "Pwood_sm_crate6Z"
D:8003A624                     p_itementry <Pwooden_table1Z_header, aPwooden_table1z, 0.1>  # "Pwooden_table1Z"
D:8003A630                     p_itementry <Pswipe_card2Z_header, aPswipe_card2z, 0.1>  # "Pswipe_card2Z"
D:8003A63C                     p_itementry <Pborg_crateZ_header, aPborg_cratez, 0.1>  # "Pborg_crateZ"
D:8003A648                     p_itementry <Pboxes4x4Z_header, aPboxes4x4z, 0.1>  # "Pboxes4x4Z"
D:8003A654                     p_itementry <Pboxes3x4Z_header, aPboxes3x4z, 0.1>  # "Pboxes3x4Z"
D:8003A660                     p_itementry <Pboxes2x4Z_header, aPboxes2x4z, 0.1>  # "Pboxes2x4Z"
D:8003A66C                     p_itementry <Psec_panelZ_header, aPsec_panelz, 0.1>  # "Psec_panelZ"
D:8003A678                     p_itementry <PICBM_noseZ_header, aPicbm_nosez, 0.1>  # "PICBM_noseZ"
D:8003A684                     p_itementry <PICBMZ_header, aPicbmz, 0.1>  # "PICBMZ"
D:8003A690                     p_itementry <Ptuning_console1Z_header, aPtuning_console1z, 0.1>  # "Ptuning_console1Z"
D:8003A69C                     p_itementry <Pdesk_arecibo1Z_header, aPdesk_arecibo1z, 0.1>  # "Pdesk_arecibo1Z"
D:8003A6A8                     p_itementry <Plocker3Z_header, aPlocker3z, 0.1>  # "Plocker3Z"
D:8003A6B4                     p_itementry <Plocker4Z_header, aPlocker4z, 0.1>  # "Plocker4Z"
D:8003A6C0                     p_itementry <ProofgunZ_header, aProofgunz, 0.1>  # "ProofgunZ"
D:8003A6CC                     p_itementry <Pdest_engineZ_header, aPdest_enginez, 0.1>  # "Pdest_engineZ"
D:8003A6D8                     p_itementry <Pdest_exocetZ_header, aPdest_exocetz, 0.1>  # "Pdest_exocetZ"
D:8003A6E4                     p_itementry <Pdest_gunZ_header, aPdest_gunz, 0.1>  # "Pdest_gunZ"
D:8003A6F0                     p_itementry <Pdest_harpoonZ_header, aPdest_harpoonz, 0.1>  # "Pdest_harpoonZ"
D:8003A6FC                     p_itementry <Pdest_seawolfZ_header, aPdest_seawolfz, 0.1>  # "Pdest_seawolfZ"
D:8003A708                     p_itementry <PwindowZ_header, aPwindowz, 0.1>  # "PwindowZ"
D:8003A714                     p_itementry <Pwindow_lib_lg1Z_header, aPwindow_lib_lg1z, 0.1>  # "Pwindow_lib_lg1Z"
D:8003A720                     p_itementry <Pwindow_lib_sm1Z_header, aPwindow_lib_sm1z, 0.1>  # "Pwindow_lib_sm1Z"
D:8003A72C                     p_itementry <Pwindow_cor11Z_header, aPwindow_cor11z, 0.1>  # "Pwindow_cor11Z"
D:8003A738                     p_itementry <Pjungle3_treeZ_header, aPjungle3_treez, 0.1>  # "Pjungle3_treeZ"
D:8003A744                     p_itementry <PpalmZ_header, aPpalmz, 0.1>  # "PpalmZ"
D:8003A750                     p_itementry <PpalmtreeZ_header, aPpalmtreez, 0.1>  # "PpalmtreeZ"
D:8003A75C                     p_itementry <Pplant2bZ_header, aPplant2bz, 0.1>  # "Pplant2bZ"
D:8003A768                     p_itementry <PlabbenchZ_header, aPlabbenchz, 0.1>  # "PlabbenchZ"
D:8003A774                     p_itementry <PgasbarrelZ_header, aPgasbarrelz, 0.1>  # "PgasbarrelZ"
D:8003A780                     p_itementry <PgasbarrelsZ_header, aPgasbarrelsz, 0.1>  # "PgasbarrelsZ"
D:8003A78C                     p_itementry <PbodyarmourZ_header, aPbodyarmourz, 0.1>  # "PbodyarmourZ"
D:8003A798                     p_itementry <PbodyarmourvestZ_header, aPbodyarmourvestz, 0.1>  # "PbodyarmourvestZ"
D:8003A7A4                     p_itementry <PgastankZ_header, aPgastankz, 0.1>  # "PgastankZ"
D:8003A7B0                     p_itementry <Pglassware1Z_header, aPglassware1z, 0.1>  # "Pglassware1Z"
D:8003A7BC                     p_itementry <PhatchboltZ_header, aPhatchboltz, 0.1>  # "PhatchboltZ"
D:8003A7C8                     p_itementry <PbrakeunitZ_header, aPbrakeunitz, 0.1>  # "PbrakeunitZ"
D:8003A7D4                     p_itementry <Pak47magZ_header, aPak47magz, 0.1>  # "Pak47magZ"
D:8003A7E0                     p_itementry <Pm16magZ_header, aPm16magz, 0.1>  # "Pm16magZ"
D:8003A7EC                     p_itementry <Pmp5kmagZ_header, aPmp5kmagz, 0.1>  # "Pmp5kmagZ"
D:8003A7F8                     p_itementry <PskorpionmagZ_header, aPskorpionmagz, 0.1>  # "PskorpionmagZ"
D:8003A804                     p_itementry <PspectremagZ_header, aPspectremagz, 0.1>  # "PspectremagZ"
D:8003A810                     p_itementry <PuzimagZ_header, aPuzimagz, 0.1>  # "PuzimagZ"
D:8003A81C                     p_itementry <PsilencerZ_header, aPsilencerz, 0.1>  # "PsilencerZ"
D:8003A828                     p_itementry <PchrextinguisherZ_header, aPchrextinguisherz, 0.1>  # "PchrextinguisherZ"
D:8003A834                     p_itementry <PboxcartridgesZ_header, aPboxcartridgesz, 0.1>  # "PboxcartridgesZ"
D:8003A840                     p_itementry <Pfnp90magZ_header, aPfnp90magz, 0.1>  # "Pfnp90magZ"
D:8003A84C                     p_itementry <PgoldenshellsZ_header, aPgoldenshellsz, 0.1>  # "PgoldenshellsZ"
D:8003A858                     p_itementry <PmagnumshellsZ_header, aPmagnumshellsz, 0.1>  # "PmagnumshellsZ"
D:8003A864                     p_itementry <PwppkmagZ_header, aPwppkmagz, 0.1>  # "PwppkmagZ"
D:8003A870                     p_itementry <Ptt33magZ_header, aPtt33magz, 0.1>  # "Ptt33magZ"
D:8003A87C                     p_itementry <Psev_doorZ_header, aPsev_doorz, 1.0>  # "Psev_doorZ"
D:8003A888                     p_itementry <Psev_door3Z_header, aPsev_door3z, 1.0>  # "Psev_door3Z"
D:8003A894                     p_itementry <Psev_door3_windZ_header, aPsev_door3_windz, 1.0>  # "Psev_door3_windZ"
D:8003A8A0                     p_itementry <Psev_door4_windZ_header, aPsev_door4_windz, 1.0>  # "Psev_door4_windZ"
D:8003A8AC                     p_itementry <Psev_trislideZ_header, aPsev_trislidez, 1.0>  # "Psev_trislideZ"
D:8003A8B8                     p_itementry <Psev_door_v1Z_header, aPsev_door_v1z, 1.0>  # "Psev_door_v1Z"
D:8003A8C4                     p_itementry <Psteel_door1Z_header, aPsteel_door1z, 1.0>  # "Psteel_door1Z"
D:8003A8D0                     p_itementry <Psteel_door2Z_header, aPsteel_door2z, 1.0>  # "Psteel_door2Z"
D:8003A8DC                     p_itementry <Psteel_door3Z_header, aPsteel_door3z, 1.0>  # "Psteel_door3Z"
D:8003A8E8                     p_itementry <Psilo_lift_doorZ_header, aPsilo_lift_doorz, 1.0>  # "Psilo_lift_doorZ"
D:8003A8F4                     p_itementry <Psteel_door2bZ_header, aPsteel_door2bz, 1.0>  # "Psteel_door2bZ"
D:8003A900                     p_itementry <Pdoor_roller1Z_header, aPdoor_roller1z, 1.0>  # "Pdoor_roller1Z"
D:8003A90C                     p_itementry <Pdoor_roller2Z_header, aPdoor_roller2z, 1.0>  # "Pdoor_roller2Z"
D:8003A918                     p_itementry <Pdoor_roller3Z_header, aPdoor_roller3z, 1.0>  # "Pdoor_roller3Z"
D:8003A924                     p_itementry <Pdoor_roller4Z_header, aPdoor_roller4z, 1.0>  # "Pdoor_roller4Z"
D:8003A930                     p_itementry <Pdoor_st_arec1Z_header, aPdoor_st_arec1z, 1.0>  # "Pdoor_st_arec1Z"
D:8003A93C                     p_itementry <Pdoor_st_arec2Z_header, aPdoor_st_arec2z, 1.0>  # "Pdoor_st_arec2Z"
D:8003A948                     p_itementry <Pdoor_dest1Z_header, aPdoor_dest1z, 1.0>  # "Pdoor_dest1Z"
D:8003A954                     p_itementry <Pdoor_dest2Z_header, aPdoor_dest2z, 1.0>  # "Pdoor_dest2Z"
D:8003A960                     p_itementry <Pgas_plant_sw_do1Z_header, aPgas_plant_sw_do1z, 1.0>  # "Pgas_plant_sw_do1Z"
D:8003A96C                     p_itementry <Pgas_plant_sw2_do1Z_header, aPgas_plant_sw2_do1z, 1.0>  # "Pgas_plant_sw2_do1Z"
D:8003A978                     p_itementry <Pgas_plant_sw3_do1Z_header, aPgas_plant_sw3_do1z, 1.0>  # "Pgas_plant_sw3_do1Z"
D:8003A984                     p_itementry <Pgas_plant_sw4_do1Z_header, aPgas_plant_sw4_do1z, 1.0>  # "Pgas_plant_sw4_do1Z"
D:8003A990                     p_itementry <Pgas_plant_met1_do1Z_header, aPgas_plant_met1_do1z, 1.0>  # "Pgas_plant_met1_do1Z"
D:8003A99C                     p_itementry <Pgas_plant_wc_cub1Z_header, aPgas_plant_wc_cub1z, 1.0>  # "Pgas_plant_wc_cub1Z"
D:8003A9A8                     p_itementry <Pgasplant_clear_doorZ_header, aPgasplant_clear_doorz, 1.0>  # "Pgasplant_clear_doorZ"
D:8003A9B4                     p_itementry <Ptrain_doorZ_header, aPtrain_doorz, 1.0>  # "Ptrain_doorZ"
D:8003A9C0                     p_itementry <Ptrain_door2Z_header, aPtrain_door2z, 1.0>  # "Ptrain_door2Z"
D:8003A9CC                     p_itementry <Ptrain_door3Z_header, aPtrain_door3z, 1.0>  # "Ptrain_door3Z"
D:8003A9D8                     p_itementry <Pdoor_eyelidZ_header, aPdoor_eyelidz, 1.0>  # "Pdoor_eyelidZ"
D:8003A9E4                     p_itementry <Pdoor_irisZ_header, aPdoor_irisz, 1.0>  # "Pdoor_irisZ"
D:8003A9F0                     p_itementry <PsevdoorwoodZ_header, aPsevdoorwoodz, 1.0>  # "PsevdoorwoodZ"
D:8003A9FC                     p_itementry <PsevdoorwindZ_header, aPsevdoorwindz, 1.0>  # "PsevdoorwindZ"
D:8003AA08                     p_itementry <PsevdoornowindZ_header, aPsevdoornowindz, 1.0>  # "PsevdoornowindZ"
D:8003AA14                     p_itementry <PsevdoormetslideZ_header, aPsevdoormetslidez, 1.0>  # "PsevdoormetslideZ"
D:8003AA20                     p_itementry <Pcryptdoor1aZ_header, aPcryptdoor1az, 1.0>  # "Pcryptdoor1aZ"
D:8003AA2C                     p_itementry <Pcryptdoor1bZ_header, aPcryptdoor1bz, 1.0>  # "Pcryptdoor1bZ"
D:8003AA38                     p_itementry <Pcryptdoor2aZ_header, aPcryptdoor2az, 1.0>  # "Pcryptdoor2aZ"
D:8003AA44                     p_itementry <Pcryptdoor2bZ_header, aPcryptdoor2bz, 1.0>  # "Pcryptdoor2bZ"
D:8003AA50                     p_itementry <Pcryptdoor3Z_header, aPcryptdoor3z, 1.0>  # "Pcryptdoor3Z"
D:8003AA5C                     p_itementry <Pcryptdoor4Z_header, aPcryptdoor4z, 1.0>  # "Pcryptdoor4Z"
D:8003AA68                     p_itementry <PvertdoorZ_header, aPvertdoorz, 1.0>  # "PvertdoorZ"
D:8003AA74                     p_itementry <PhatchdoorZ_header, aPhatchdoorz, 1.0>  # "PhatchdoorZ"
D:8003AA80                     p_itementry <PdamgatedoorZ_header, aPdamgatedoorz, 1.0>  # "PdamgatedoorZ"
D:8003AA8C                     p_itementry <PdamtundoorZ_header, aPdamtundoorz, 1.0>  # "PdamtundoorZ"
D:8003AA98                     p_itementry <PdamchaindoorZ_header, aPdamchaindoorz, 1.0>  # "PdamchaindoorZ"
D:8003AAA4                     p_itementry <PsilotopdoorZ_header, aPsilotopdoorz, 1.0>  # "PsilotopdoorZ"
D:8003AAB0                     p_itementry <Pdoorprison1Z_header, aPdoorprison1z, 1.0>  # "Pdoorprison1Z"
D:8003AABC                     p_itementry <PdoorstatgateZ_header, aPdoorstatgatez, 1.0>  # "PdoorstatgateZ"
D:8003AAC8                     p_itementry <PchrkalashZ_header, aPchrkalashz, 0.1>  # "PchrkalashZ"
D:8003AAD4                     p_itementry <PchrgrenadelaunchZ_header, aPchrgrenadelaunchz, 0.1>  # "PchrgrenadelaunchZ"
D:8003AAE0                     p_itementry <PchrknifeZ_header, aPchrknifez, 0.1>  # "PchrknifeZ"
D:8003AAEC                     p_itementry <PchrlaserZ_header, aPchrlaserz, 0.1>  # "PchrlaserZ"
D:8003AAF8                     p_itementry <Pchrm16Z_header, aPchrm16z, 0.1>  # "Pchrm16Z"
D:8003AB04                     p_itementry <Pchrmp5kZ_header, aPchrmp5kz, 0.1>  # "Pchrmp5kZ"
D:8003AB10                     p_itementry <PchrrugerZ_header, aPchrrugerz, 0.1>  # "PchrrugerZ"
D:8003AB1C     PchrwppkZ_entry:p_itementry <PchrwppkZ_header, aPchrwppkz, 0.1>
D:8003AB1C                                              # DATA XREF: sub_CODE_7F008E80+2E0r
D:8003AB1C                                              # sub_CODE_7F008E80+324r
D:8003AB1C                                              # sub_CODE_7F008E80+32Cr
D:8003AB1C                                              # sub_CODE_7F008E80+2E4r
D:8003AB1C                                              # sub_CODE_7F008E80+2F8r
D:8003AB1C                                              # "PchrwppkZ"
D:8003AB28                     p_itementry <PchrshotgunZ_header, aPchrshotgunz, 0.1>  # "PchrshotgunZ"
D:8003AB34                     p_itementry <PchrskorpionZ_header, aPchrskorpionz, 0.1>  # "PchrskorpionZ"
D:8003AB40                     p_itementry <PchrspectreZ_header, aPchrspectrez, 0.1>  # "PchrspectreZ"
D:8003AB4C                     p_itementry <PchruziZ_header, aPchruziz, 0.1>  # "PchruziZ"
D:8003AB58                     p_itementry <PchrgrenadeZ_header, aPchrgrenadez, 0.1>  # "PchrgrenadeZ"
D:8003AB64                     p_itementry <Pchrfnp90Z_header, aPchrfnp90z, 0.1>  # "Pchrfnp90Z"
D:8003AB70                     p_itementry <PchrbriefcaseZ_header, aPchrbriefcasez, 0.1>  # "PchrbriefcaseZ"
D:8003AB7C                     p_itementry <PchrremotemineZ_header, aPchrremoteminez, 0.1>  # "PchrremotemineZ"
D:8003AB88                     p_itementry <PchrproximitymineZ_header, aPchrproximityminez, 0.1>  # "PchrproximitymineZ"
D:8003AB94                     p_itementry <PchrtimedmineZ_header, aPchrtimedminez, 0.1>  # "PchrtimedmineZ"
D:8003ABA0                     p_itementry <PchrrocketZ_header, aPchrrocketz, 0.1>  # "PchrrocketZ"
D:8003ABAC                     p_itementry <PchrgrenaderoundZ_header, aPchrgrenaderoundz, 0.1>  # "PchrgrenaderoundZ"
D:8003ABB8                     p_itementry <PchrwppksilZ_header, aPchrwppksilz, 0.1>  # "PchrwppksilZ"
D:8003ABC4                     p_itementry <Pchrtt33Z_header, aPchrtt33z, 0.1>  # "Pchrtt33Z"
D:8003ABD0                     p_itementry <Pchrmp5ksilZ_header, aPchrmp5ksilz, 0.1>  # "Pchrmp5ksilZ"
D:8003ABDC                     p_itementry <PchrautoshotZ_header, aPchrautoshotz, 0.1>  # "PchrautoshotZ"
D:8003ABE8                     p_itementry <PchrgoldenZ_header, aPchrgoldenz, 0.1>  # "PchrgoldenZ"
D:8003ABF4                     p_itementry <PchrthrowknifeZ_header, aPchrthrowknifez, 0.1>  # "PchrthrowknifeZ"
D:8003AC00                     p_itementry <PchrsniperrifleZ_header, aPchrsniperriflez, 0.1>  # "PchrsniperrifleZ"
D:8003AC0C                     p_itementry <PchrrocketlaunchZ_header, aPchrrocketlaunchz, 0.1>  # "PchrrocketlaunchZ"
D:8003AC18                     p_itementry <PhatfurryZ_header, aPhatfurryz, 0.1>  # "PhatfurryZ"
D:8003AC24                     p_itementry <PhatfurrybrownZ_header, aPhatfurrybrownz, 0.1>  # "PhatfurrybrownZ"
D:8003AC30                     p_itementry <PhatfurryblackZ_header, aPhatfurryblackz, 0.1>  # "PhatfurryblackZ"
D:8003AC3C                     p_itementry <PhattbirdZ_header, aPhattbirdz, 0.1>  # "PhattbirdZ"
D:8003AC48                     p_itementry <PhattbirdbrownZ_header, aPhattbirdbrownz, 0.1>  # "PhattbirdbrownZ"
D:8003AC54                     p_itementry <PhathelmetZ_header, aPhathelmetz, 0.1>  # "PhathelmetZ"
D:8003AC60                     p_itementry <PhathelmetgreyZ_header, aPhathelmetgreyz, 0.1>  # "PhathelmetgreyZ"
D:8003AC6C                     p_itementry <PhatmoonZ_header, aPhatmoonz, 0.1>  # "PhatmoonZ"
D:8003AC78                     p_itementry <PhatberetZ_header, aPhatberetz, 0.1>  # "PhatberetZ"
D:8003AC84                     p_itementry <PhatberetblueZ_header, aPhatberetbluez, 0.1>  # "PhatberetblueZ"
D:8003AC90                     p_itementry <PhatberetredZ_header, aPhatberetredz, 0.1>  # "PhatberetredZ"
D:8003AC9C                     p_itementry <PhatpeakedZ_header, aPhatpeakedz, 0.1>  # "PhatpeakedZ"
D:8003ACA8                     p_itementry <PchrwristdartZ_header, aPchrwristdartz, 0.1>  # "PchrwristdartZ"
D:8003ACB4                     p_itementry <PchrexplosivepenZ_header, aPchrexplosivepenz, 0.1>  # "PchrexplosivepenZ"
D:8003ACC0                     p_itementry <PchrbombcaseZ_header, aPchrbombcasez, 0.1>  # "PchrbombcaseZ"
D:8003ACCC                     p_itementry <PchrflarepistolZ_header, aPchrflarepistolz, 0.1>  # "PchrflarepistolZ"
D:8003ACD8                     p_itementry <PchrpitongunZ_header, aPchrpitongunz, 0.1>  # "PchrpitongunZ"
D:8003ACE4                     p_itementry <PchrfingergunZ_header, aPchrfingergunz, 0.1>  # "PchrfingergunZ"
D:8003ACF0                     p_itementry <PchrsilverwppkZ_header, aPchrsilverwppkz, 0.1>  # "PchrsilverwppkZ"
D:8003ACFC                     p_itementry <PchrgoldwppkZ_header, aPchrgoldwppkz, 0.1>  # "PchrgoldwppkZ"
D:8003AD08                     p_itementry <PchrdynamiteZ_header, aPchrdynamitez, 0.1>  # "PchrdynamiteZ"
D:8003AD14                     p_itementry <PchrbungeeZ_header, aPchrbungeez, 0.1>  # "PchrbungeeZ"
D:8003AD20                     p_itementry <PchrdoordecoderZ_header, aPchrdoordecoderz, 0.1>  # "PchrdoordecoderZ"
D:8003AD2C                     p_itementry <PchrbombdefuserZ_header, aPchrbombdefuserz, 0.1>  # "PchrbombdefuserZ"
D:8003AD38                     p_itementry <PchrbugdetectorZ_header, aPchrbugdetectorz, 0.1>  # "PchrbugdetectorZ"
D:8003AD44                     p_itementry <PchrsafecrackercaseZ_header, aPchrsafecrackercasez, 0.1>  # "PchrsafecrackercaseZ"
D:8003AD50                     p_itementry <PchrcameraZ_header, aPchrcameraz, 0.1>  # "PchrcameraZ"
D:8003AD5C                     p_itementry <PchrlockexploderZ_header, aPchrlockexploderz, 0.1>  # "PchrlockexploderZ"
D:8003AD68                     p_itementry <PchrdoorexploderZ_header, aPchrdoorexploderz, 0.1>  # "PchrdoorexploderZ"
D:8003AD74                     p_itementry <PchrkeyanalysercaseZ_header, aPchrkeyanalysercasez, 0.1>  # "PchrkeyanalysercaseZ"
D:8003AD80                     p_itementry <PchrweaponcaseZ_header, aPchrweaponcasez, 0.1>  # "PchrweaponcaseZ"
D:8003AD8C                     p_itementry <PchrkeyyaleZ_header, aPchrkeyyalez, 0.1>  # "PchrkeyyaleZ"
D:8003AD98                     p_itementry <PchrkeyboltZ_header, aPchrkeyboltz, 0.1>  # "PchrkeyboltZ"
D:8003ADA4                     p_itementry <PchrbugZ_header, aPchrbugz, 0.1>  # "PchrbugZ"
D:8003ADB0                     p_itementry <PchrmicrocameraZ_header, aPchrmicrocameraz, 0.1>  # "PchrmicrocameraZ"
D:8003ADBC                     p_itementry <PfloppyZ_header, aPfloppyz, 0.1>  # "PfloppyZ"
D:8003ADC8                     p_itementry <PchrgoldeneyekeyZ_header, aPchrgoldeneyekeyz, 0.1>  # "PchrgoldeneyekeyZ"
D:8003ADD4                     p_itementry <PchrpolarizedglassesZ_header, aPchrpolarizedglassesz, 0.1>  # "PchrpolarizedglassesZ"
D:8003ADE0                     p_itementry <PchrcreditcardZ_header, aPchrcreditcardz, 0.1>  # "PchrcreditcardZ"
D:8003ADEC                     p_itementry <PchrdarkglassesZ_header, aPchrdarkglassesz, 0.1>  # "PchrdarkglassesZ"
D:8003ADF8                     p_itementry <PchrgaskeyringZ_header, aPchrgaskeyringz, 0.1>  # "PchrgaskeyringZ"
D:8003AE04                     p_itementry <PchrdatathiefZ_header, aPchrdatathiefz, 0.1>  # "PchrdatathiefZ"
D:8003AE10                     p_itementry <PsafeZ_header, aPsafez, 0.1>  # "PsafeZ"
D:8003AE1C                     p_itementry <PbombZ_header, aPbombz, 0.1>  # "PbombZ"
D:8003AE28                     p_itementry <PchrplansZ_header, aPchrplansz, 0.1>  # "PchrplansZ"
D:8003AE34                     p_itementry <PchrspyfileZ_header, aPchrspyfilez, 0.1>  # "PchrspyfileZ"
D:8003AE40                     p_itementry <PchrblueprintsZ_header, aPchrblueprintsz, 0.1>  # "PchrblueprintsZ"
D:8003AE4C                     p_itementry <PchrcircuitboardZ_header, aPchrcircuitboardz, 0.1>  # "PchrcircuitboardZ"
D:8003AE58                     p_itementry <PchrmapZ_header, aPchrmapz, 0.1>  # "PchrmapZ"
D:8003AE64                     p_itementry <PchrspooltapeZ_header, aPchrspooltapez, 0.1>  # "PchrspooltapeZ"
D:8003AE70                     p_itementry <PchraudiotapeZ_header, aPchraudiotapez, 0.1>  # "PchraudiotapeZ"
D:8003AE7C                     p_itementry <PchrmicrofilmZ_header, aPchrmicrofilmz, 0.1>  # "PchrmicrofilmZ"
D:8003AE88                     p_itementry <PchrmicrocodeZ_header, aPchrmicrocodez, 0.1>  # "PchrmicrocodeZ"
D:8003AE94                     p_itementry <PchrlectreZ_header, aPchrlectrez, 0.1>  # "PchrlectreZ"
D:8003AEA0                     p_itementry <PchrmoneyZ_header, aPchrmoneyz, 0.1>  # "PchrmoneyZ"
D:8003AEAC                     p_itementry <PchrgoldbarZ_header, aPchrgoldbarz, 0.1>  # "PchrgoldbarZ"
D:8003AEB8                     p_itementry <PchrheroinZ_header, aPchrheroinz, 0.1>  # "PchrheroinZ"
D:8003AEC4                     p_itementry <PchrclipboardZ_header, aPchrclipboardz, 0.1>  # "PchrclipboardZ"
D:8003AED0                     p_itementry <PchrdossierredZ_header, aPchrdossierredz, 0.1>  # "PchrdossierredZ"
D:8003AEDC                     p_itementry <PchrstafflistZ_header, aPchrstafflistz, 0.1>  # "PchrstafflistZ"
D:8003AEE8                     p_itementry <PchrdattapeZ_header, aPchrdattapez, 0.1>  # "PchrdattapeZ"
D:8003AEF4                     p_itementry <PchrplastiqueZ_header, aPchrplastiquez, 0.1>  # "PchrplastiqueZ"
D:8003AF00                     p_itementry <PchrblackboxZ_header, aPchrblackboxz, 0.1>  # "PchrblackboxZ"
D:8003AF0C                     p_itementry <PchrvideotapeZ_header, aPchrvideotapez, 0.1>  # "PchrvideotapeZ"
D:8003AF18      # int *PnintendologoZ_entry
D:8003AF18     PnintendologoZ_entry:p_itementry <PnintendologoZ_header, aPnintendologoz, 0.1>
D:8003AF18                                              # DATA XREF: init_menu01_nintendo+4Cr
D:8003AF18                                              # init_menu01_nintendo+64r
D:8003AF18                                              # init_menu01_nintendo+70r
D:8003AF18                                              # init_menu01_nintendo+50r
D:8003AF18                                              # "PnintendologoZ"
D:8003AF24      # int *PgoldeneyelogoZ_entry
D:8003AF24     PgoldeneyelogoZ_entry:p_itementry <PgoldeneyelogoZ_header, aPgoldeneyelogoz, 0.1>
D:8003AF24                                              # DATA XREF: init_menu04_goldeneyelogo+4Cr
D:8003AF24                                              # init_menu04_goldeneyelogo+64r
D:8003AF24                                              # init_menu04_goldeneyelogo+70r
D:8003AF24                                              # init_menu04_goldeneyelogo+50r
D:8003AF24                                              # "PgoldeneyelogoZ"
D:8003AF30     PwalletbondZ_entry:p_itementry <PwalletbondZ_header, aPwalletbondz, 0.1>
D:8003AF30                                              # DATA XREF: load_walletbond+34r
D:8003AF30                                              # load_walletbond+4Cr
D:8003AF30                                              # load_walletbond+38r
D:8003AF30                                              # "PwalletbondZ"
D:8003AF3C                     p_itementry <PmiltruckZ_header, aPmiltruckz, 0.1>  # "PmiltruckZ"
D:8003AF48                     p_itementry <PjeepZ_header, aPjeepz, 0.1>  # "PjeepZ"
D:8003AF54                     p_itementry <ParticZ_header, aParticz, 0.1>  # "ParticZ"
D:8003AF60                     p_itementry <PhelicopterZ_header, aPhelicopterz, 0.1>  # "PhelicopterZ"
D:8003AF6C                     p_itementry <PtigerZ_header, aPtigerz, 0.1>  # "PtigerZ"
D:8003AF78                     p_itementry <PmilcopterZ_header, aPmilcopterz, 0.1>  # "PmilcopterZ"
D:8003AF84                     p_itementry <PhindZ_header, aPhindz, 0.1>  # "PhindZ"
D:8003AF90                     p_itementry <PartictrailerZ_header, aPartictrailerz, 0.1>  # "PartictrailerZ"
D:8003AF9C                     p_itementry <PmotorbikeZ_header, aPmotorbikez, 0.1>  # "PmotorbikeZ"
D:8003AFA8                     p_itementry <PtankZ_header, aPtankz, 0.1>  # "PtankZ"
D:8003AFB4                     p_itementry <PapcZ_header, aPapcz, 0.1>  # "PapcZ"
D:8003AFC0                     p_itementry <PspeedboatZ_header, aPspeedboatz, 0.1>  # "PspeedboatZ"
D:8003AFCC                     p_itementry <PplaneZ_header, aPplanez, 0.1>  # "PplaneZ"
D:8003AFD8                     p_itementry <Pgun_runway1Z_header, aPgun_runway1z, 0.1>  # "Pgun_runway1Z"
D:8003AFE4                     p_itementry <PsafedoorZ_header, aPsafedoorz, 1.0>  # "PsafedoorZ"
D:8003AFF0                     p_itementry <Pkey_holderZ_header, aPkey_holderz, 1.0>  # "Pkey_holderZ"
D:8003AFFC                     p_itementry <PhatchsevxZ_header, aPhatchsevxz, 1.0>  # "PhatchsevxZ"
D:8003B008                     p_itementry <PsevdishZ_header, aPsevdishz, 1.0>  # "PsevdishZ"
D:8003B014                     p_itementry <Parchsecdoor1Z_header, aParchsecdoor1z, 1.0>  # "Parchsecdoor1Z"
D:8003B020                     p_itementry <Parchsecdoor2Z_header, aParchsecdoor2z, 1.0>  # "Parchsecdoor2Z"
D:8003B02C                     p_itementry <PgroundgunZ_header, aPgroundgunz, 0.1>  # "PgroundgunZ"
D:8003B038                     p_itementry <PtrainextdoorZ_header, aPtrainextdoorz, 1.0>  # "PtrainextdoorZ"
D:8003B044                     p_itementry <PcarbmwZ_header, aPcarbmwz, 0.1>  # "PcarbmwZ"
D:8003B050                     p_itementry <PcarescortZ_header, aPcarescortz, 0.1>  # "PcarescortZ"
D:8003B05C                     p_itementry <PcargolfZ_header, aPcargolfz, 0.1>  # "PcargolfZ"
D:8003B068                     p_itementry <PcarweirdZ_header, aPcarweirdz, 0.1>  # "PcarweirdZ"
D:8003B074                     p_itementry <PcarzilZ_header, aPcarzilz, 0.1>  # "PcarzilZ"
D:8003B080                     p_itementry <Pshuttle_door_lZ_header, aPshuttle_door_lz, 1.0>  # "Pshuttle_door_lZ"
D:8003B08C                     p_itementry <Pshuttle_door_rZ_header, aPshuttle_door_rz, 1.0>  # "Pshuttle_door_rZ"
D:8003B098                     p_itementry <Pdepot_gate_entryZ_header, aPdepot_gate_entryz, 0.1>  # "Pdepot_gate_entryZ"
D:8003B0A4                     p_itementry <Pdepot_door_steelZ_header, aPdepot_door_steelz, 0.1>  # "Pdepot_door_steelZ"
D:8003B0B0                     p_itementry <Pglassware2Z_header, aPglassware2z, 0.1>  # "Pglassware2Z"
D:8003B0BC                     p_itementry <Pglassware3Z_header, aPglassware3z, 0.1>  # "Pglassware3Z"
D:8003B0C8                     p_itementry <Pglassware4Z_header, aPglassware4z, 0.1>  # "Pglassware4Z"
D:8003B0D4                     p_itementry <PlandmineZ_header, aPlandminez, 0.1>  # "PlandmineZ"
D:8003B0E0                     p_itementry <Pplant1Z_header, aPplant1z, 0.1>  # "Pplant1Z"
D:8003B0EC                     p_itementry <Pplant11Z_header, aPplant11z, 0.1>  # "Pplant11Z"
D:8003B0F8                     p_itementry <Pplant2Z_header, aPplant2z, 0.1>  # "Pplant2Z"
D:8003B104                     p_itementry <Pplant3Z_header, aPplant3z, 0.1>  # "Pplant3Z"
D:8003B110                     p_itementry <Pjungle5_treeZ_header, aPjungle5_treez, 0.1>  # "Pjungle5_treeZ"
D:8003B11C      # int *PlegalpageZ_entry
D:8003B11C     PlegalpageZ_entry:p_itementry <PlegalpageZ_header, aPlegalpagez, 0.1>
D:8003B11C                                              # DATA XREF: init_menu00_legalscreen+60r
D:8003B11C                                              # init_menu00_legalscreen+78r
D:8003B11C                                              # init_menu00_legalscreen+84r
D:8003B11C                                              # init_menu00_legalscreen+64r
D:8003B11C                                              # "PlegalpageZ"
D:8003B128                     p_itementry <Pst_pete_room_1iZ_header, aPst_pete_room_1iz, 0.1>  # "Pst_pete_room_1iZ"
D:8003B134                     p_itementry <Pst_pete_room_2iZ_header, aPst_pete_room_2iz, 0.1>  # "Pst_pete_room_2iZ"
D:8003B140                     p_itementry <Pst_pete_room_3tZ_header, aPst_pete_room_3tz, 0.1>  # "Pst_pete_room_3tZ"
D:8003B14C                     p_itementry <Pst_pete_room_5cZ_header, aPst_pete_room_5cz, 0.1>  # "Pst_pete_room_5cZ"
D:8003B158                     p_itementry <Pst_pete_room_6cZ_header, aPst_pete_room_6cz, 0.1>  # "Pst_pete_room_6cZ"
D:8003B164                     p_itementry <Pdoor_rollertrainZ_header, aPdoor_rollertrainz, 1.0>  # "Pdoor_rollertrainZ"
D:8003B170                     p_itementry <Pdoor_winZ_header, aPdoor_winz, 1.0>  # "Pdoor_winZ"
D:8003B17C                     p_itementry <Pdoor_aztecZ_header, aPdoor_aztecz, 1.0>  # "Pdoor_aztecZ"
D:8003B188                     p_itementry <PshuttleZ_header, aPshuttlez, 0.1>  # "PshuttleZ"
D:8003B194                     p_itementry <Pdoor_azt_deskZ_header, aPdoor_azt_deskz, 1.0>  # "Pdoor_azt_deskZ"
D:8003B1A0                     p_itementry <Pdoor_azt_desk_topZ_header, aPdoor_azt_desk_topz, 1.0>  # "Pdoor_azt_desk_topZ"
D:8003B1AC                     p_itementry <Pdoor_azt_chairZ_header, aPdoor_azt_chairz, 1.0>  # "Pdoor_azt_chairZ"
D:8003B1B8                     p_itementry <Pdoor_mfZ_header, aPdoor_mfz, 1.0>  # "Pdoor_mfZ"
D:8003B1C4                     p_itementry <PflagZ_header, aPflagz, 0.1>  # "PflagZ"
D:8003B1D0                     p_itementry <PbarricadeZ_header, aPbarricadez, 0.1>  # "PbarricadeZ"
D:8003B1DC                     p_itementry <PmodemboxZ_header, aPmodemboxz, 0.1>  # "PmodemboxZ"
D:8003B1E8                     p_itementry <PdoorpanelZ_header, aPdoorpanelz, 0.1>  # "PdoorpanelZ"
D:8003B1F4                     p_itementry <PdoorconsoleZ_header, aPdoorconsolez, 0.1>  # "PdoorconsoleZ"
D:8003B200                     p_itementry <PchrtesttubeZ_header, aPchrtesttubez, 0.1>  # "PchrtesttubeZ"
D:8003B20C                     p_itementry <Pbollardz_header, aPbollardz, 0.1>  # "PbollardZ"
D:8003B218     PitemZ_entry_end:p_itementry <0, aPnullZ, 1.0>
D:8003B218                                              # DATA XREF: stage_loading_setup_objparse_cleanupafter+ACo
D:8003B218                                              # ""
D:8003B224                     .word 0x6315C
D:8003B228                     .word 0x7B6CDBFF
D:8003B22C                     .word 0x5126FB59
D:8003B230                     .word 0x7CA70006
D:8003B234                     .word 0x2AFECB3E
D:8003B238                     .word 0x73F4278F
D:8003B23C                     .word 0x6D3A44C8
D:8003B240                     .word 0x50000
D:8003B244                     .word 0
D:8003B248                     .word 0
D:8003B24C                     .word 0xB, 0xB9B03EBA, 0xAD6275C8, 0xB70FF06E, 0xB17D9, 0xDFCC57CD, 0x82547345
D:8003B24C                     .word 0xE011000B, 0x3779ED72, 0x688DF67B, 0x37E54F89, 0xBE277, 0x474DD1E, 0xC48486C
D:8003B24C                     .word 0xF87D000B, 0x7C3F16BC, 0x44A91A58, 0xE4129297, 0x3DC2, 0x16B6E30D, 0xBCABC592
D:8003B24C                     .word 0xF9B50002, 0x719C7024, 0x9EE0C175, 0xA5DDC933, 0x28E16, 0xBBCA05C0
D:8003B24C                     .word 0x1A7381BE, 0xF8210000, 0, 0, 0
D:8003B2CC                     .word 0x82716, 0xF5440D35, 0xC20E83D7, 0x7D730008, 0x81A1B772, 0x1B57437A
D:8003B2CC                     .word 0x85FAB6C1, 0x827EB, 0x5A7ABD1A, 0x27EB5A7A, 0xBD1A0008, 0x98DE8C36
D:8003B2CC                     .word 0xDDD5F74B, 0x4F0A1F14, 0x834F5, 0xF199A9F2, 0x3D27C707, 0xB9AD0008
D:8003B2CC                     .word 0x678FDB91, 0x2A2E8D91, 0x6EEE925E, 0x4D82F, 0xF4D7546F, 0xD6C787D9
D:8003B2CC                     .word 0x1430004, 0x100EADF2, 0x1FDD45F1, 0x4772F8C6, 0x4EF0B, 0x71BBB7F7, 0xBFA303B8
D:8003B2CC                     .word 0xE44E0004, 0xDFD1676A, 0x8597E8AC, 0xE2109A4D, 0x4AB48, 0xDD9B4343
D:8003B2CC                     .word 0x4B80DCC, 0x3B3D0004, 0x836B6BBF, 0x9DBB3DB7, 0x59577341, 0x70000, 0
D:8003B2CC                     .word 0
D:8003B380                     .word 9, 0xB1CC19E2, 0xEA5B1CC, 0x19E20EA5, 0x9F093, 0xB2DF1409, 0x271EE0B3
D:8003B380                     .word 0x418A0009, 0x3AC20102, 0xBF013AC2, 0x102BF01, 0x93AC6, 0xE449A56E, 0xA4CFEDA0
D:8003B380                     .word 0x17190009, 0x9BCFC333, 0x63844298, 0xD4557BFA, 0x9839E, 0xBA71466, 0xDB6DD1B3
D:8003B380                     .word 0x12330009, 0x3F677A70, 0x83DE7052, 0x7D236FF, 0x9A409, 0x692DE286, 0xC63C82D0
D:8003B380                     .word 0x5D070009, 0xD6CA1866, 0x839CBC6A, 0x86AD4DC6, 0x996FC, 0xA1EFA9E6
D:8003B380                     .word 0xB9D2A3C5, 0xA0450009, 0x7D2BE7DC, 0x55DB378E, 0x4765B09C, 0x9E2AF
D:8003B380                     .word 0x2D4371FE, 0xE39093B3, 0x57E30009, 0x9367098A, 0x3B68D6F8, 0x4EAF7B83
D:8003B380                     .word 0xF0000, 0, 0
D:8003B444                     .word 0xF, 0, 0, 0
D:8003B454                     .word 0x7993D, 0xA2B25028, 0x825E25B8, 0xD8EF0006, 0x6553024D, 0xFD22D469
D:8003B454                     .word 0x18E432F6, 0x6F742, 0xCB58ED2, 0x60216AD5, 0xAA880004, 0x6D882EF, 0x5B194147
D:8003B454                     .word 0x5AE1374E, 0x4284D, 0x3E7C9330, 0xCF1E013F, 0x4E290006, 0xE339C0B6
D:8003B454                     .word 0xE5FC7054, 0x83A8C118, 0x4B49F, 0x24EF6, 0x88490002, 0x70B0002, 0x2D56A1EE
D:8003B454                     .word 0x41058AE6, 0x6A2A60DD, 0x979B2, 0xBC78B9B9, 0xC76A97A1, 0x3DA30009
D:8003B454                     .word 0x3292DDC3, 0x926512A6, 0xE935B9BC, 0x304DB, 0x3CFDDB5C, 0x3B2950B7
D:8003B454                     .word 0x83D10004, 0xBE6408AD, 0x150D6AED, 0x542E63B3, 0x4D7E5, 0x13695ACC
D:8003B454                     .word 0x535A2105, 0x1BF70004, 0x72223CEE, 0x1A15122A, 0xADEC5EF3, 0x4927F
D:8003B454                     .word 0x10B05125, 0x7F4EBBC5, 0x8088000B, 0xE89D7502, 0x9003469D, 0x19F0A5E6
D:8003B454                     .word 0xB3771, 0xC00280FF, 0xDBF61705, 0x497A000E, 0xA954AFDE, 0xBB6CD4A6
D:8003B454                     .word 0x9883FA27, 0xEDE9F, 0xCEF06346, 0x80FBA382, 0x14D1000E, 0x448ED4CC
D:8003B454                     .word 0xC1B5442F, 0xC1D1EE05, 0xEC7C0, 0xF918095E, 0xECE206D4, 0xC64D000E
D:8003B454                     .word 0xC49116EC, 0xDEA75A19, 0x9DE7FF28, 0xEE889, 0x2DA62775, 0x153CBAE6
D:8003B454                     .word 0xCB1B0000, 0x2D56A1EE, 0x41058AE6, 0x6A2A60DD, 0x6E5E6, 0x8FB7D5FE
D:8003B454                     .word 0xE959D656, 0xFB820007, 0x58763A4F, 0xD115A10D, 0x265D2C02, 0x7787E
D:8003B454                     .word 0xC128D96A, 0x60C918E7, 0x99AD0007, 0x879A90E4, 0xC20F35FE, 0xC80791D8
D:8003B454                     .word 0x740AE, 0x62B6D240, 0xAC8D47C5, 0x17D10000, 0, 0, 0
D:8003B5F8                     .word 0x715C6, 0xB37D118A, 0x4E615D02, 0x7D500006, 0x15C6B37D, 0x118A4E61
D:8003B5F8                     .word 0x5D027D50, 0x30000, 0, 0
D:8003B620                     .word 3, 0x24698AE5, 0x524FE5F6, 0xBE4AC865, 0x52957, 0x1B2227C7, 0x96630DDF
D:8003B620                     .word 0x411F0007, 0x15C6B37D, 0x118A4E61, 0x5D027D50, 0x40000, 0, 0
D:8003B658                     .word 6, 0xF8F4F1E0, 0x473F41DD, 0xA510C9C6, 0x80000, 0, 0
D:8003B674                     .word 4, 0x7A512382, 0x9B3629E5, 0x5921017A, 0x48666, 0x3DD9E619, 0x6134CC94
D:8003B674                     .word 0x1A5C0004, 0x7F3931C5, 0x9AC370AB, 0x551B069, 0x3D727, 0x7AB2786B, 0xF5AD3FC4
D:8003B674                     .word 0xD6CE0003, 0x4548D59E, 0x1EDCE88D, 0xE9E4AF76, 0x3262F, 0x491BFD57
D:8003B674                     .word 0x6715E7ED, 0x2626000F, 0, 0, 0, 0, 0, 0
D:8003B6E4                     .word 4, 0xBCAE0BD1, 0xFF73A30, 0x724083B7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B71C                     .word 6, 0xB2C6170A, 0xA236BBE, 0xB59382DB, 0x5275B, 0x8AD3002C, 0x27B58AD3
D:8003B71C                     .word 0x2C0005, 0, 0, 0
D:8003B748                     .word 0x833A1, 0x8A014D42, 0xD9CBB865, 0xB3360004, 0x8C0678FC, 0x8F9A4DF5
D:8003B748                     .word 0x4D5322F9, 0x399E9, 0x107EF5E, 0x560E6DF, 0x4B360003, 0x31E70023, 0xB2AEA2D7
D:8003B748                     .word 0xE54090B2, 0x80000, 0, 0
D:8003B78C                     .word 0xD, 0, 0, 0
D:8003B79C                     .word 0x833A1, 0x8A014D42, 0xD9CBB865, 0xB3360008, 0x33A18A01, 0x4D42D9CB
D:8003B79C                     .word 0xB865B336, 0x833A1, 0x8A014D42, 0xD9CBB865, 0xB3360008, 0x33A18A01
D:8003B79C                     .word 0x4D42D9CB, 0xB865B336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B79C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B79C                     .word 0, 0, 0, 0, 0, 0, 0
D:8003B888                     .word 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B8B4                     .word 0x60000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B8B4                     .word 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0xC0000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003B924                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BCDC                     .word 0xD0000, 0, 0, 0, 0, 0, 0
D:8003BCF8                     .word 0x30000, 0, 0
D:8003BD04                     .word 0xD, 0, 0, 0
D:8003BD14                     .word 0xD0000, 0, 0
D:8003BD20                     .word 0xD, 0, 0, 0
D:8003BD30                     .word 0xD0000, 0, 0
D:8003BD3C                     .word 0xD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BD3C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BD3C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BD3C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BD3C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BD3C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BD3C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BD3C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003BFF8                     .word 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C04C                     .word 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C04C                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C04C                     .word 0, 0, 0
D:8003C110                     .word 0xD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C164                     .word 4, 0, 0, 0
D:8003C174                     .word 0x40000, 0, 0
D:8003C180                     .word 4, 0, 0, 0
D:8003C190                     .word 0x40000, 0, 0
D:8003C19C                     .word 4, 0, 0, 0
D:8003C1AC                     .word 0xD0000, 0, 0
D:8003C1B8                     .word 4, 0, 0, 0
D:8003C1C8                     .word 0x40000, 0, 0
D:8003C1D4                     .word 4, 0, 0, 0
D:8003C1E4                     .word 0x40000, 0, 0
D:8003C1F0                     .word 4, 0, 0, 0
D:8003C200                     .word 0x40000, 0, 0
D:8003C20C                     .word 4, 0, 0, 0
D:8003C21C                     .word 0x40000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C254                     .word 0xD0000, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C27C                     .word 7, 0, 0, 0, 0, 0, 0
D:8003C298                     .word 0xD, 0, 0, 0
D:8003C2A8                     .word 0xD0000, 0, 0
D:8003C2B4                     .word 0xD, 0, 0, 0
D:8003C2C4                     .word 0xD0000, 0, 0
D:8003C2D0                     .word 0xD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C2D0                     .word 0, 0, 0, 0, 0
D:8003C340                     .word 0xD, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C340                     .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C340                     .word 0, 0, 0, 0, 0, 0, 0
D:8003C414                     .word 0xD0000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
D:8003C414                     .word 0, 0, 0
D:8003C474                     .word 6, 0, 0, 0
D:8003C484                     .word 0x60000, 0, 0
D:8003C490                     .byte 0, 0, 0, 9
D:8003C494                     .align 4
D:8003C4A0                     .byte 0, 0xD, 0, 0
D:8003C4A4                     .word 0, 0, 0, 0, 0
D:8003C4B8                     .word 0
D:8003C4BC                     .word 0xFFFF
D:8003C4C0                     .word 0xFFFFFFFF
D:8003C4C4                     .word 0xFFFFFFFF
D:8003C4C8                     .word 0xFFFF0000
D:8003C4CC                     .word 0
D:8003C4D0     word_D_8003C4D0:.half 2                  # DATA XREF: D:model_object_standard_objecto
D:8003C4D2                     .half 0
D:8003C4D4                     .half 0
D:8003C4D6                     .half 0
D:8003C4D8     model_object_standard_object:item_related <1, 0, word_D_8003C4D0, 3, 0>
D:8003C4D8                                              # DATA XREF: D:Palarm1z_headero
D:8003C4D8                                              # D:Palarm2Z_headero
D:8003C4D8                                              # D:PexplosionbitZ_headero
D:8003C4D8                                              # D:Pammo_crate1Z_headero
D:8003C4D8                                              # D:Pammo_crate2Z_headero
D:8003C4D8                                              # D:Pammo_crate3Z_headero
D:8003C4D8                                              # D:Pammo_crate4Z_headero
D:8003C4D8                                              # D:Pammo_crate5Z_headero
D:8003C4D8                                              # D:Pbin1Z_headero
D:8003C4D8                                              # D:Pblotter1Z_headero
D:8003C4D8                                              # D:Pbook1Z_headero
D:8003C4D8                                              # D:Pbookshelf1Z_headero
D:8003C4D8                                              # D:Pbridge_console2bZ_headero
D:8003C4D8                                              # D:Pcard_box1Z_headero
D:8003C4D8                                              # D:Pcard_box2Z_headero
D:8003C4D8                                              # D:Pcard_box3Z_headero
D:8003C4D8                                              # D:Pcard_box4_lgZ_headero
D:8003C4D8                                              # D:Pcard_box5_lgZ_headero
D:8003C4D8                                              # D:Pcard_box6_lgZ_headero
D:8003C4D8                                              # D:Pconsole_sevaZ_headero
D:8003C4D8                                              # D:Pconsole_sevcZ_headero
D:8003C4D8                                              # D:Pconsole_sevdZ_headero
D:8003C4D8                                              # D:Pconsole_sev2aZ_headero
D:8003C4D8                                              # D:Pconsole_sev2cZ_headero
D:8003C4D8                                              # D:Pconsole_sev2dZ_headero
D:8003C4D8                                              # D:Pconsole_sev_GEaZ_headero
D:8003C4D8                                              # D:Pconsole_sev_GEbZ_headero
D:8003C4D8                                              # D:Pdesk1Z_headero
D:8003C4D8                                              # D:Pdesk2Z_headero
D:8003C4D8                                              # D:Pdesk_lamp2Z_headero
D:8003C4D8                                              # D:Pdisc_readerZ_headero
D:8003C4D8                                              # D:Pdisk_drive1Z_headero
D:8003C4D8                                              # D:Pfiling_cabinet1Z_headero
D:8003C4D8                                              # D:Pjerry_can1Z_headero
D:8003C4D8                                              # D:Pkeyboard1Z_headero
D:8003C4D8                                              # D:Pkit_units1Z_headero
D:8003C4D8                                              # D:Pletter_tray1Z_headero
D:8003C4D8                                              # D:Pmainframe1Z_headero
D:8003C4D8                                              # D:Pmainframe2Z_headero
D:8003C4D8                                              # D:Pmetal_chair1Z_headero
D:8003C4D8                                              # D:Pmetal_crate1Z_headero
D:8003C4D8                                              # D:Pmetal_crate2Z_headero
D:8003C4D8                                              # D:Pmetal_crate3Z_headero
D:8003C4D8                                              # D:Pmetal_crate4Z_headero
D:8003C4D8                                              # D:Pmissile_rackZ_headero
D:8003C4D8                                              # D:Pmissile_rack2Z_headero
D:8003C4D8                                              # D:Poil_drum1Z_headero
D:8003C4D8                                              # D:Poil_drum2Z_headero
D:8003C4D8                                              # D:Poil_drum3Z_headero
D:8003C4D8                                              # D:Poil_drum5Z_headero
D:8003C4D8                                              # D:Poil_drum6Z_headero
D:8003C4D8                                              # D:Poil_drum7Z_headero
D:8003C4D8                                              # D:PpadlockZ_headero
D:8003C4D8                                              # D:Pphone1Z_headero
D:8003C4D8                                              # D:Pradio_unit1Z_headero
D:8003C4D8                                              # D:Pradio_unit2Z_headero
D:8003C4D8                                              # D:Pradio_unit3Z_headero
D:8003C4D8                                              # D:Pradio_unit4Z_headero
D:8003C4D8                                              # D:Psat1_reflectZ_headero
D:8003C4D8                                              # D:PsatdishZ_headero
D:8003C4D8                                              # D:PsatboxZ_headero
D:8003C4D8                                              # D:Pstool1Z_headero
D:8003C4D8                                              # D:Pswivel_chair1Z_headero
D:8003C4D8                                              # D:Ptorpedo_rackZ_headero
D:8003C4D8                                              # D:Pwood_lg_crate1Z_headero
D:8003C4D8                                              # D:Pwood_lg_crate2Z_headero
D:8003C4D8                                              # D:Pwood_md_crate3Z_headero
D:8003C4D8                                              # D:Pwood_sm_crate4Z_headero
D:8003C4D8                                              # D:Pwood_sm_crate5Z_headero
D:8003C4D8                                              # D:Pwood_sm_crate6Z_headero
D:8003C4D8                                              # D:Pwooden_table1Z_headero
D:8003C4D8                                              # D:Pswipe_card2Z_headero
D:8003C4D8                                              # D:Pborg_crateZ_headero
D:8003C4D8                                              # D:Pboxes4x4Z_headero
D:8003C4D8                                              # D:Pboxes3x4Z_headero
D:8003C4D8                                              # D:Pboxes2x4Z_headero
D:8003C4D8                                              # D:Psec_panelZ_headero
D:8003C4D8                                              # D:PICBM_noseZ_headero
D:8003C4D8                                              # D:PICBMZ_headero
D:8003C4D8                                              # D:Pdesk_arecibo1Z_headero
D:8003C4D8                                              # D:Plocker3Z_headero
D:8003C4D8                                              # D:Plocker4Z_headero
D:8003C4D8                                              # D:Pdest_engineZ_headero
D:8003C4D8                                              # D:Pdest_exocetZ_headero
D:8003C4D8                                              # D:Pdest_gunZ_headero
D:8003C4D8                                              # D:Pdest_harpoonZ_headero
D:8003C4D8                                              # D:Pdest_seawolfZ_headero
D:8003C4D8                                              # D:PwindowZ_headero
D:8003C4D8                                              # D:Pwindow_lib_lg1Z_headero
D:8003C4D8                                              # D:Pwindow_lib_sm1Z_headero
D:8003C4D8                                              # D:Pwindow_cor11Z_headero
D:8003C4D8                                              # D:Pjungle3_treeZ_headero
D:8003C4D8                                              # D:PpalmZ_headero
D:8003C4D8                                              # D:PpalmtreeZ_headero
D:8003C4D8                                              # D:Pplant2bZ_headero
D:8003C4D8                                              # D:PlabbenchZ_headero
D:8003C4D8                                              # D:PgasbarrelZ_headero
D:8003C4D8                                              # D:PgasbarrelsZ_headero
D:8003C4D8                                              # D:PbodyarmourZ_headero
D:8003C4D8                                              # D:PbodyarmourvestZ_headero
D:8003C4D8                                              # D:PgastankZ_headero
D:8003C4D8                                              # D:Pglassware1Z_headero
D:8003C4D8                                              # D:PhatchboltZ_headero
D:8003C4D8                                              # D:PbrakeunitZ_headero
D:8003C4D8                                              # D:Pak47magZ_headero
D:8003C4D8                                              # D:Pm16magZ_headero
D:8003C4D8                                              # D:Pmp5kmagZ_headero
D:8003C4D8                                              # D:PskorpionmagZ_headero
D:8003C4D8                                              # D:PspectremagZ_headero
D:8003C4D8                                              # D:PuzimagZ_headero
D:8003C4D8                                              # D:PsilencerZ_headero
D:8003C4D8                                              # D:PchrextinguisherZ_headero
D:8003C4D8                                              # D:PboxcartridgesZ_headero
D:8003C4D8                                              # D:Pfnp90magZ_headero
D:8003C4D8                                              # D:PgoldenshellsZ_headero
D:8003C4D8                                              # D:PmagnumshellsZ_headero
D:8003C4D8                                              # D:PwppkmagZ_headero
D:8003C4D8                                              # D:Ptt33magZ_headero
D:8003C4D8                                              # D:Psev_doorZ_headero
D:8003C4D8                                              # D:Psev_door3Z_headero
D:8003C4D8                                              # D:Psev_door3_windZ_headero
D:8003C4D8                                              # D:Psev_door_v1Z_headero
D:8003C4D8                                              # D:Psteel_door1Z_headero
D:8003C4D8                                              # D:Psteel_door2Z_headero
D:8003C4D8                                              # D:Psteel_door3Z_headero
D:8003C4D8                                              # D:Psilo_lift_doorZ_headero
D:8003C4D8                                              # D:Psteel_door2bZ_headero
D:8003C4D8                                              # D:Pdoor_roller1Z_headero
D:8003C4D8                                              # D:Pdoor_roller2Z_headero
D:8003C4D8                                              # D:Pdoor_roller3Z_headero
D:8003C4D8                                              # D:Pdoor_roller4Z_headero
D:8003C4D8                                              # D:Pdoor_st_arec1Z_headero
D:8003C4D8                                              # D:Pdoor_st_arec2Z_headero
D:8003C4D8                                              # D:Pdoor_dest1Z_headero
D:8003C4D8                                              # D:Pdoor_dest2Z_headero
D:8003C4D8                                              # D:Pgas_plant_sw_do1Z_headero
D:8003C4D8                                              # D:Pgas_plant_sw2_do1Z_headero
D:8003C4D8                                              # D:Pgas_plant_sw3_do1Z_headero
D:8003C4D8                                              # D:Pgas_plant_sw4_do1Z_headero
D:8003C4D8                                              # D:Pgas_plant_met1_do1Z_headero
D:8003C4D8                                              # D:Pgas_plant_wc_cub1Z_headero
D:8003C4D8                                              # D:Ptrain_doorZ_headero
D:8003C4D8                                              # D:PsevdoornowindZ_headero
D:8003C4D8                                              # D:PsevdoormetslideZ_headero
D:8003C4D8                                              # D:Pcryptdoor1aZ_headero
D:8003C4D8                                              # D:Pcryptdoor1bZ_headero
D:8003C4D8                                              # D:Pcryptdoor2aZ_headero
D:8003C4D8                                              # D:Pcryptdoor2bZ_headero
D:8003C4D8                                              # D:Pcryptdoor3Z_headero
D:8003C4D8                                              # D:Pcryptdoor4Z_headero
D:8003C4D8                                              # D:PvertdoorZ_headero
D:8003C4D8                                              # D:PhatchdoorZ_headero
D:8003C4D8                                              # D:PdamgatedoorZ_headero
D:8003C4D8                                              # D:PdamtundoorZ_headero
D:8003C4D8                                              # D:PdamchaindoorZ_headero
D:8003C4D8                                              # D:PsilotopdoorZ_headero
D:8003C4D8                                              # D:Pdoorprison1Z_headero
D:8003C4D8                                              # D:PdoorstatgateZ_headero
D:8003C4D8                                              # D:PchrwristdartZ_headero
D:8003C4D8                                              # D:PchrexplosivepenZ_headero
D:8003C4D8                                              # D:PchrflarepistolZ_headero
D:8003C4D8                                              # D:PchrpitongunZ_headero
D:8003C4D8                                              # D:PchrfingergunZ_headero
D:8003C4D8                                              # D:PchrsilverwppkZ_headero
D:8003C4D8                                              # D:PchrgoldwppkZ_headero
D:8003C4D8                                              # D:PchrdynamiteZ_headero
D:8003C4D8                                              # D:PchrbungeeZ_headero
D:8003C4D8                                              # D:PchrbombdefuserZ_headero
D:8003C4D8                                              # D:PchrbugdetectorZ_headero
D:8003C4D8                                              # D:PchrcameraZ_headero
D:8003C4D8                                              # D:PchrlockexploderZ_headero
D:8003C4D8                                              # D:PchrdoorexploderZ_headero
D:8003C4D8                                              # D:PchrweaponcaseZ_headero
D:8003C4D8                                              # D:PchrkeyyaleZ_headero
D:8003C4D8                                              # D:PchrkeyboltZ_headero
D:8003C4D8                                              # D:PchrbugZ_headero
D:8003C4D8                                              # D:PchrmicrocameraZ_headero
D:8003C4D8                                              # D:PfloppyZ_headero
D:8003C4D8                                              # D:PchrgoldeneyekeyZ_headero
D:8003C4D8                                              # D:PchrpolarizedglassesZ_headero
D:8003C4D8                                              # D:PchrcreditcardZ_headero
D:8003C4D8                                              # D:PchrdarkglassesZ_headero
D:8003C4D8                                              # D:PchrgaskeyringZ_headero
D:8003C4D8                                              # D:PchrdatathiefZ_headero
D:8003C4D8                                              # D:PsafeZ_headero
D:8003C4D8                                              # D:PbombZ_headero
D:8003C4D8                                              # D:PchrplansZ_headero
D:8003C4D8                                              # D:PchrspyfileZ_headero
D:8003C4D8                                              # D:PchrblueprintsZ_headero
D:8003C4D8                                              # D:PchrcircuitboardZ_headero
D:8003C4D8                                              # D:PchrmapZ_headero
D:8003C4D8                                              # D:PchrspooltapeZ_headero
D:8003C4D8                                              # D:PchraudiotapeZ_headero
D:8003C4D8                                              # D:PchrmicrofilmZ_headero
D:8003C4D8                                              # D:PchrmicrocodeZ_headero
D:8003C4D8                                              # D:PchrlectreZ_headero
D:8003C4D8                                              # D:PchrmoneyZ_headero
D:8003C4D8                                              # D:PchrgoldbarZ_headero
D:8003C4D8                                              # D:PchrheroinZ_headero
D:8003C4D8                                              # D:PchrclipboardZ_headero
D:8003C4D8                                              # D:PchrdossierredZ_headero
D:8003C4D8                                              # D:PchrstafflistZ_headero
D:8003C4D8                                              # D:PchrdattapeZ_headero
D:8003C4D8                                              # D:PchrplastiqueZ_headero
D:8003C4D8                                              # D:PchrblackboxZ_headero
D:8003C4D8                                              # D:PchrvideotapeZ_headero
D:8003C4D8                                              # D:PnintendologoZ_headero
D:8003C4D8                                              # D:PgoldeneyelogoZ_headero
D:8003C4D8                                              # D:PartictrailerZ_headero
D:8003C4D8                                              # D:PmotorbikeZ_headero
D:8003C4D8                                              # D:PapcZ_headero
D:8003C4D8                                              # D:PspeedboatZ_headero
D:8003C4D8                                              # D:PsafedoorZ_headero
D:8003C4D8                                              # D:Pkey_holderZ_headero
D:8003C4D8                                              # D:PhatchsevxZ_headero
D:8003C4D8                                              # D:Parchsecdoor1Z_headero
D:8003C4D8                                              # D:Parchsecdoor2Z_headero
D:8003C4D8                                              # D:PtrainextdoorZ_headero
D:8003C4D8                                              # D:PcarbmwZ_headero
D:8003C4D8                                              # D:PcarescortZ_headero
D:8003C4D8                                              # D:PcargolfZ_headero
D:8003C4D8                                              # D:PcarweirdZ_headero
D:8003C4D8                                              # D:Pshuttle_door_lZ_headero
D:8003C4D8                                              # D:Pshuttle_door_rZ_headero
D:8003C4D8                                              # D:Pdepot_gate_entryZ_headero
D:8003C4D8                                              # D:Pdepot_door_steelZ_headero
D:8003C4D8                                              # D:Pglassware2Z_headero
D:8003C4D8                                              # D:Pglassware3Z_headero
D:8003C4D8                                              # D:Pglassware4Z_headero
D:8003C4D8                                              # D:PlandmineZ_headero
D:8003C4D8                                              # D:Pplant1Z_headero
D:8003C4D8                                              # D:Pplant11Z_headero
D:8003C4D8                                              # D:Pplant2Z_headero
D:8003C4D8                                              # D:Pplant3Z_headero
D:8003C4D8                                              # D:Pjungle5_treeZ_headero
D:8003C4D8                                              # D:PlegalpageZ_headero
D:8003C4D8                                              # D:Pst_pete_room_1iZ_headero
D:8003C4D8                                              # D:Pst_pete_room_2iZ_headero
D:8003C4D8                                              # D:Pst_pete_room_3tZ_headero
D:8003C4D8                                              # D:Pst_pete_room_5cZ_headero
D:8003C4D8                                              # D:Pst_pete_room_6cZ_headero
D:8003C4D8                                              # D:Pdoor_rollertrainZ_headero
D:8003C4D8                                              # D:Pdoor_winZ_headero
D:8003C4D8                                              # D:Pdoor_aztecZ_headero
D:8003C4D8                                              # D:PshuttleZ_headero
D:8003C4D8                                              # D:Pdoor_azt_deskZ_headero
D:8003C4D8                                              # D:Pdoor_azt_desk_topZ_headero
D:8003C4D8                                              # D:Pdoor_azt_chairZ_headero
D:8003C4D8                                              # D:Pdoor_mfZ_headero
D:8003C4D8                                              # D:PbarricadeZ_headero
D:8003C4D8                                              # D:Pbollardz_headero
D:8003C4E4                     .word 0
D:8003C4E8                     .word 0
D:8003C4EC                     .word 0
D:8003C4F0     word_D_8003C4F0:.half 0x15               # DATA XREF: D:prop_weapon_relatedo
D:8003C4F2                     .half 0
D:8003C4F4                     .half 0
D:8003C4F6                     .half 0x15
D:8003C4F8                     .half 1
D:8003C4FA                     .half 1
D:8003C4FC     prop_weapon_related:item_related <2, 0, word_D_8003C4F0, 0, 0>
D:8003C4FC                                              # DATA XREF: sub_CODE_7F052574+20o
D:8003C4FC                                              # sub_CODE_7F052604+1Co
D:8003C4FC                                              # D:PchrkalashZ_headero
D:8003C4FC                                              # D:PchrgrenadelaunchZ_headero
D:8003C4FC                                              # D:PchrknifeZ_headero
D:8003C4FC                                              # D:PchrlaserZ_headero
D:8003C4FC                                              # D:Pchrm16Z_headero
D:8003C4FC                                              # D:Pchrmp5kZ_headero
D:8003C4FC                                              # D:PchrrugerZ_headero
D:8003C4FC                                              # D:PchrwppkZ_headero
D:8003C4FC                                              # D:PchrshotgunZ_headero
D:8003C4FC                                              # D:PchrskorpionZ_headero
D:8003C4FC                                              # D:PchrspectreZ_headero
D:8003C4FC                                              # D:PchruziZ_headero
D:8003C4FC                                              # D:PchrgrenadeZ_headero
D:8003C4FC                                              # D:Pchrfnp90Z_headero
D:8003C4FC                                              # D:PchrbriefcaseZ_headero
D:8003C4FC                                              # D:PchrremotemineZ_headero
D:8003C4FC                                              # D:PchrproximitymineZ_headero
D:8003C4FC                                              # D:PchrtimedmineZ_headero
D:8003C4FC                                              # D:PchrrocketZ_headero
D:8003C4FC                                              # D:PchrgrenaderoundZ_headero
D:8003C4FC                                              # D:PchrwppksilZ_headero
D:8003C4FC                                              # D:Pchrtt33Z_headero
D:8003C4FC                                              # D:Pchrmp5ksilZ_headero
D:8003C4FC                                              # D:PchrautoshotZ_headero
D:8003C4FC                                              # D:PchrgoldenZ_headero
D:8003C4FC                                              # D:PchrthrowknifeZ_headero
D:8003C4FC                                              # D:PchrsniperrifleZ_headero
D:8003C4FC                                              # D:PchrrocketlaunchZ_headero
D:8003C4FC                                              # D:PchrbombcaseZ_headero
D:8003C4FC                                              # D:PchrdoordecoderZ_headero
D:8003C4FC                                              # D:PchrsafecrackercaseZ_headero
D:8003C4FC                                              # D:PchrkeyanalysercaseZ_headero
D:8003C4FC                                              # D:PflagZ_headero
D:8003C4FC                                              # D:PchrtesttubeZ_headero
D:8003C508                     .word 0
D:8003C50C                     .word 0
D:8003C510     dword_D_8003C510:.word 0x4010000, 2, 0   # DATA XREF: D:8003C574o
D:8003C51C     dword_D_8003C51C:.word 0x20003
D:8003C520                     .word 0x30002
D:8003C524                     .word 0x60006
D:8003C528                     .word 0x20009
D:8003C52C                     .word 0xC0002
D:8003C530                     .word 0xC0009
D:8003C534                     .word 0x2000F
D:8003C538                     .word 0x120002
D:8003C53C                     .word 0x12000F
D:8003C540                     .word 0x20015
D:8003C544                     .word 0x180002
D:8003C548                     .word 0x180015
D:8003C54C                     .word 0x2001B
D:8003C550                     .word 0x1E0002
D:8003C554                     .word 0x1E001B
D:8003C558                     .word 0x20021
D:8003C55C                     .word 0x240002
D:8003C560                     .word 0x240021
D:8003C564                     .word 0x20027
D:8003C568                     .word 0x2A0002
D:8003C56C                     .word 0x2A0027
D:8003C570     dword_D_8003C570:.word 0x100000          # DATA XREF: D:8003C654o
D:8003C574                     .word dword_D_8003C510
D:8003C578                     .word 0x2D0000
D:8003C57C                     .word 0
D:8003C580     dword_D_8003C580:.word 0x10000           # DATA XREF: sub_CODE_7F000B60o
D:8003C580                                              # D:8003C5A0o
D:8003C584                     .word dword_D_8003C5E0
D:8003C588                     .word 0
D:8003C58C                     .word 0
D:8003C590                     .word 0
D:8003C594                     .word dword_D_8003C598
D:8003C598     dword_D_8003C598:.word 0x20000           # DATA XREF: D:8003C594o
D:8003C598                                              # D:8003C5B8o
D:8003C598                                              # D:8003C5E4o
D:8003C59C                     .word dword_D_8003C5F0
D:8003C5A0                     .word dword_D_8003C580
D:8003C5A4                     .word 0
D:8003C5A8                     .word 0
D:8003C5AC                     .word dword_D_8003C5B0
D:8003C5B0     dword_D_8003C5B0:.word 0x20000           # DATA XREF: D:8003C5ACo
D:8003C5B0                                              # D:8003C5D0o
D:8003C5B0                                              # D:8003C604o
D:8003C5B4                     .word dword_D_8003C60C
D:8003C5B8                     .word dword_D_8003C598
D:8003C5BC                     .word 0
D:8003C5C0                     .word 0
D:8003C5C4                     .word dword_D_8003C5C8
D:8003C5C8     dword_D_8003C5C8:.word 0x20000           # DATA XREF: D:8003C5C4o
D:8003C5C8                                              # D:8003C620o
D:8003C5CC                     .word dword_D_8003C628
D:8003C5D0                     .word dword_D_8003C5B0
D:8003C5D4                     .word 0
D:8003C5D8                     .word 0
D:8003C5DC                     .word 0
D:8003C5E0     dword_D_8003C5E0:.word 1                 # DATA XREF: D:8003C584o
D:8003C5E4                     .word dword_D_8003C598
D:8003C5E8                     .word 0
D:8003C5EC                     .word 0
D:8003C5F0     dword_D_8003C5F0:.word 0                 # DATA XREF: D:8003C59Co
D:8003C5F4                     .word 0
D:8003C5F8                     .word 0
D:8003C5FC                     .word 0x10002
D:8003C600                     .word 0xFFFFFFFF
D:8003C604                     .word dword_D_8003C5B0
D:8003C608                     .word 0
D:8003C60C     dword_D_8003C60C:.word 0x3F96C81D, 0x422493D6, 0  # DATA XREF: D:8003C5B4o
D:8003C618                     .word 0x20003
D:8003C61C                     .word 0xFFFFFFFF
D:8003C620                     .word dword_D_8003C5C8
D:8003C624                     .word 0
D:8003C628     dword_D_8003C628:.word 0xC024DDA0, 0x43F036EA, 0  # DATA XREF: D:8003C5CCo
D:8003C634     dword_D_8003C634:.word 0x30000
D:8003C638                     .word 0xFFFFFFFF
D:8003C63C                     .word 0
D:8003C640                     .word 0
D:8003C644                     .word 0
D:8003C648                     .word 0
D:8003C64C                     .word 0
D:8003C650     dword_D_8003C650:.word 0                 # DATA XREF: sub_CODE_7F000B60+10w
D:8003C650                                              # sets_a_bunch_of_BONDdata_values_to_default+8o
D:8003C654                     .word dword_D_8003C570, 0
D:8003C65C     dword_D_8003C65C:.word 4
D:8003C660                     .word 0x4224A519
D:8003C664     dword_D_8003C664:.word 0                 # DATA XREF: sets_a_bunch_of_BONDdata_values_to_default+10r
D:8003C668                     .word 0
D:8003C66C                     .word 0
D:8003C670     dword_D_8003C670:.word 0x4010000, 2, 0   # DATA XREF: D:model_suit_lf_hando
D:8003C67C     dword_D_8003C67C:.word 0x20003
D:8003C680                     .word 0x30002
D:8003C684                     .word 0x60006
D:8003C688                     .word 0x20009
D:8003C68C                     .word 0xC0002
D:8003C690                     .word 0xC0009
D:8003C694                     .word 0x2000F
D:8003C698                     .word 0x120002
D:8003C69C                     .word 0x12000F
D:8003C6A0                     .word 0x20015
D:8003C6A4                     .word 0x180002
D:8003C6A8                     .word 0x180015
D:8003C6AC                     .word 0x2001B
D:8003C6B0                     .word 0x1E0002
D:8003C6B4                     .word 0x1E001B
D:8003C6B8                     .word 0x20021
D:8003C6BC                     .word 0x240002
D:8003C6C0                     .word 0x240021
D:8003C6C4                     .word 0x20027
D:8003C6C8                     .word 0x2A0002
D:8003C6CC                     .word 0x2A0027
D:8003C6D0                     .word 0x15002D
D:8003C6D4                     .word 0x2D0015
D:8003C6D8                     .word 0x2E002E
D:8003C6DC                     .word 0x15002F
D:8003C6E0                     .word 0x2F0000
D:8003C6E4     model_suit_lf_hand:model_data <0x130000, dword_D_8003C670, 0x2D0000>
D:8003C6E4                                              # DATA XREF: D:Csuit_lf_handz_structo
D:8003C6F0     dword_D_8003C6F0:.word 0x20000           # DATA XREF: D:weapon_gun_standard_guno
D:8003C6F4                     .word 2
D:8003C6F8                     .word 0x30003
D:8003C6FC                     .word 0x20006
D:8003C700                     .word 0x60015
D:8003C704                     .word 0xF000F
D:8003C708                     .word 0x20009
D:8003C70C                     .word 0x90002
D:8003C710                     .word 0xC000C
D:8003C714     weapon_gun_standard_gun:model_data <0x60000, dword_D_8003C6F0, 0xF0000>
D:8003C714                                              # DATA XREF: D:GwppkZ_structo
D:8003C714                                              # D:GwppksilZ_structo
D:8003C714                                              # D:Gtt33Z_structo
D:8003C714                                              # D:GskorpianZ_structo
D:8003C714                                              # D:Gak47Z_structo
D:8003C714                                              # D:Gmp5kZ_structo
D:8003C714                                              # D:Gmp5ksilZ_structo
D:8003C714                                              # D:Gm16Z_structo
D:8003C714                                              # D:Gfnp90Z_structo
D:8003C714                                              # D:8003C900o
D:8003C714                                              # D:GgoldengunZ_structo
D:8003C714                                              # D:GshotgunZ_structo
D:8003C714                                              # D:GautoshotZ_structo
D:8003C714                                              # D:GspectreZ_structo
D:8003C714                                              # D:GlaserZ_structo
D:8003C714                                              # D:GrocketlaunchZ_structo
D:8003C714                                              # D:GknifeZ_headero
D:8003C714                                              # D:GthrowknifeZ_structo
D:8003C714                                              # D:GtaserZ_structo
D:8003C714                                              # D:GremotemineZ_structo
D:8003C714                                              # D:GproximitymineZ_structo
D:8003C714                                              # D:GtimedmineZ_structo
D:8003C714                                              # D:GtriggerZ_structo
D:8003C714                                              # D:GgrenadeZ_structo
D:8003C714                                              # D:GfistZ_headero
D:8003C714                                              # D:GsniperrifleZ_structo
D:8003C714                                              # D:8003CC00o
D:8003C714                                              # D:8003CC20o
D:8003C714                                              # D:GbombcaseZ_structo
D:8003C714                                              # D:GflarepistolZ_structo
D:8003C714                                              # D:GpitongunZ_structo
D:8003C714                                              # D:8003CCA0o
D:8003C714                                              # D:GsilverwppkZ_structo
D:8003C714                                              # D:GgoldwppkZ_structo
D:8003C714                                              # D:8003CD00o
D:8003C714                                              # D:GbungeeZ_structo
D:8003C714                                              # D:GdoordecoderZ_structo
D:8003C714                                              # D:GbombdefuserZ_structo
D:8003C714                                              # D:GbugdetectorZ_structo
D:8003C714                                              # D:GsafecrackercaseZ_structo
D:8003C714                                              # D:GcameraZ_structo
D:8003C714                                              # D:GlockexploderZ_structo
D:8003C714                                              # D:GdoorexploderZ_structo
D:8003C714                                              # D:GkeyanalysercaseZ_structo
D:8003C714                                              # D:GweaponcaseZ_structo
D:8003C714                                              # D:GkeycardZ_structo
D:8003C714                                              # D:GkeyyaleZ_structo
D:8003C714                                              # D:GkeyboltZ_structo
D:8003C714                                              # D:GbugZ_structo
D:8003C714                                              # D:GmicrocameraZ_structo
D:8003C714                                              # D:GexplosivefloppyZ_structo
D:8003C714                                              # D:GgoldeneyekeyZ_structo
D:8003C714                                              # D:GpolarizedglassesZ_structo
D:8003C714                                              # D:GcreditcardZ_structo
D:8003C714                                              # D:GdarkglassesZ_structo
D:8003C714                                              # D:GwatchidentifierZ_structo
D:8003C714                                              # D:GwatchcommunicatorZ_structo
D:8003C714                                              # D:GwatchlaserZ_structo
D:8003C714                                              # D:GwatchgeigercounterZ_structo
D:8003C714                                              # D:GwatchmagnetrepelZ_structo
D:8003C714                                              # D:GwatchmagnetattractZ_structo
D:8003C714                                              # D:GgaskeyringZ_structo
D:8003C714                                              # D:GdatathiefZ_structo
D:8003C714                                              # D:GbriefcaseZ_structo
D:8003C714                                              # D:GblackboxZ_structo
D:8003C714                                              # D:GplastiqueZ_structo
D:8003C714                                              # D:GvideotapeZ_structo
D:8003C714                                              # D:GclipboardZ_structo
D:8003C714                                              # D:GstafflistZ_structo
D:8003C714                                              # D:GdossierredZ_structo
D:8003C714                                              # D:GaudiotapeZ_structo
D:8003C714                                              # D:GdattapeZ_structo
D:8003C714                                              # D:GplansZ_structo
D:8003C714                                              # D:GspyfileZ_structo
D:8003C714                                              # D:GblueprintsZ_structo
D:8003C714                                              # D:GcircuitboardZ_structo
D:8003C714                                              # D:GmapZ_structo
D:8003C714                                              # D:GspooltapeZ_structo
D:8003C714                                              # D:GmicrofilmZ_structo
D:8003C714                                              # D:GmicrocodeZ_structo
D:8003C714                                              # D:GlectreZ_structo
D:8003C714                                              # D:GmoneyZ_structo
D:8003C714                                              # D:GgoldbarZ_structo
D:8003C714                                              # D:GheroinZ_structo
D:8003C720     dword_D_8003C720:.word 0x20000           # DATA XREF: D:weapon_gun_unassignedo
D:8003C724                     .half 0
D:8003C726                     .half 0
D:8003C728     weapon_gun_unassigned:model_data <0x10000, dword_D_8003C720, 0x30000>
D:8003C728                                              # DATA XREF: D:GcartridgeZ_structo
D:8003C728                                              # D:GcartrifleZ_structo
D:8003C728                                              # D:GcartblueZ_structo
D:8003C728                                              # D:GcartshellZ_structo
D:8003C734                     .word 0
D:8003C738                     .word 0
D:8003C73C                     .word 0
D:8003C740     dword_D_8003C740:.word 0x20000           # DATA XREF: D:weapon_gun_revolvero
D:8003C744                     .word 2
D:8003C748                     .word 0x30003
D:8003C74C                     .word 0x20006
D:8003C750                     .word 0x60002
D:8003C754                     .word 0x90009
D:8003C758                     .word 0x2000C
D:8003C75C                     .word 0xC0002
D:8003C760                     .word 0xF000F
D:8003C764                     .word 0x20012
D:8003C768                     .word 0x120000
D:8003C76C     weapon_gun_revolver:model_data <0x70000, dword_D_8003C740, 0x150000>
D:8003C76C                                              # DATA XREF: handles_firing_or_throwing_weapon_in_hand+E20o
D:8003C76C                                              # set_enviro_fog_for_items_in_solo_watch_menu+184o
D:8003C76C                                              # D:GrugerZ_structo
D:8003C76C                                              # D:GgrenadelaunchZ_structo
D:8003C778                     .word 0
D:8003C77C                     .word 0
D:8003C780     dword_D_8003C780:.word 0x20000           # DATA XREF: D:weapon_gun_kf7o
D:8003C784                     .word 2
D:8003C788                     .word 0x30003
D:8003C78C                     .word 0x20006
D:8003C790                     .word 0x60002
D:8003C794                     .word 0x90009
D:8003C798                     .word 0x150012
D:8003C79C                     .word 0x120002
D:8003C7A0                     .word 0xC000C
D:8003C7A4                     .word 0x2000F
D:8003C7A8                     .word 0xF0000
D:8003C7AC     weapon_gun_kf7: model_data <0x70000, dword_D_8003C780, 0x120000>
D:8003C7AC                                              # DATA XREF: handles_firing_or_throwing_weapon_in_hand:loc_CODE_7F061308o
D:8003C7AC                                              # D:GuziZ_structo
D:8003C7B8                     .word 0
D:8003C7BC                     .word 0
D:8003C7C0     GwppkZ_struct:  itemheader <0, weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0xC, 0, 0>
D:8003C7C0                                              # DATA XREF: D:80033A04o
D:8003C7E0     GwppksilZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 6, 438.66476, 0xC, 0, 0>
D:8003C7E0                                              # DATA XREF: D:80033A3Co
D:8003C800     Gtt33Z_struct:  itemheader <0, weapon_gun_standard_gun, 0, 0x24, 6, 438.16788, 0xF, 0, 0>
D:8003C800                                              # DATA XREF: D:80033A74o
D:8003C820     GskorpianZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 390.40039, 0xC, 0, 0>
D:8003C820                                              # DATA XREF: D:80033AACo
D:8003C840     Gak47Z_struct:  itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 941.9339, 0x12, 0, 0>
D:8003C840                                              # DATA XREF: D:80033AE4o
D:8003C860     GuziZ_struct:   itemheader <0, weapon_gun_kf7, 0, 0x24, 5, 436.95404, 0xC, 0, 0>
D:8003C860                                              # DATA XREF: D:80033B1Co
D:8003C880     Gmp5kZ_struct:  itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 499.24536, 9, 0, 0>
D:8003C880                                              # DATA XREF: D:80033B54o
D:8003C8A0     Gmp5ksilZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 655.97717, 9, 0, 0>
D:8003C8A0                                              # DATA XREF: D:80033B8Co
D:8003C8C0     Gm16Z_struct:   itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 1096.2413, 8, 0, 0>
D:8003C8C0                                              # DATA XREF: D:80033BFCo
D:8003C8E0     Gfnp90Z_struct: itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 460.81909, 0xA, 0, 0>
D:8003C8E0                                              # DATA XREF: D:80033C34o
D:8003C900                     itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 238.62167, 4, 0, 0>
D:8003C920     GrugerZ_struct: itemheader <0, weapon_gun_revolver, 0, 0x24, 6, 553.44312, 0xE, 0, 0>
D:8003C920                                              # DATA XREF: D:80033D14o
D:8003C940     GgoldengunZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 5, 384.92172, 0xB, 0, 0>
D:8003C940                                              # DATA XREF: D:80033D4Co
D:8003C960     GshotgunZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 4, 919.33038, 0xD, 0, 0>
D:8003C960                                              # DATA XREF: D:80033C6Co
D:8003C980     GautoshotZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 840.15125, 0x10, 0, 0>
D:8003C980                                              # DATA XREF: D:80033CA4o
D:8003C9A0     GgrenadelaunchZ_struct:itemheader <0, weapon_gun_revolver, 0, 0x24, 5, 768.33496, 0xF, 0, 0>
D:8003C9A0                                              # DATA XREF: D:80033E64o
D:8003C9C0     GspectreZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 598.42865, 0xB, 0, 0>
D:8003C9C0                                              # DATA XREF: D:80033BC4o
D:8003C9E0     GlaserZ_struct: itemheader <0, weapon_gun_standard_gun, 0, 0x24, 3, 442.81848, 0xD, 0, 0>
D:8003C9E0                                              # DATA XREF: D:80033DF4o
D:8003CA00     GrocketlaunchZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 3, 566.51208, 0xA, 0, 0>
D:8003CA00                                              # DATA XREF: D:80033E9Co
D:8003CA20     GknifeZ_header: itemheader <0, weapon_gun_standard_gun, 0, 0x24, 3, 376.97263, 9, 0, 0>
D:8003CA20                                              # DATA XREF: D:80033994o
D:8003CA40     GthrowknifeZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 3, 373.31387, 9, 0, 0>
D:8003CA40                                              # DATA XREF: D:800339CCo
D:8003CA60     GtaserZ_struct: itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 182.78622, 0x11, 0, 0>
D:8003CA60                                              # DATA XREF: D:80033FECo
D:8003CA80     GremotemineZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 50.999378, 3, 0, 0>
D:8003CA80                                              # DATA XREF: D:80033F7Co
D:8003CAA0     GproximitymineZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 51.00029, 3, 0, 0>
D:8003CAA0                                              # DATA XREF: D:80033F44o
D:8003CAC0     GtimedmineZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 49.368877, 4, 0, 0>
D:8003CAC0                                              # DATA XREF: D:80033F0Co
D:8003CAE0     GtriggerZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0x16, 0, 0>
D:8003CAE0                                              # DATA XREF: D:80033FB4o
D:8003CB00     GgrenadeZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 3, 427.27081, 5, 0, 0>
D:8003CB00                                              # DATA XREF: D:80033ED4o
D:8003CB20     GfistZ_header:  itemheader <0, weapon_gun_standard_gun, 0, 0x24, 3, 243.84764, 0xE, 0, 0>
D:8003CB20                                              # DATA XREF: D:8003395Co
D:8003CB40     GsniperrifleZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 808.03253, 7, 0, 0>
D:8003CB40                                              # DATA XREF: D:80033CDCo
D:8003CB60     GcartridgeZ_struct:itemheader <0, weapon_gun_unassigned, 0, 0, 1, 14.128822, 2, 0, 0>
D:8003CB60                                              # DATA XREF: D:ejected_cartridgeo
D:8003CB60                                              # D:GwppkZ_statso
D:8003CB60                                              # D:GwppksilZ_statso
D:8003CB60                                              # D:Gtt33Z_statso
D:8003CB60                                              # D:GskorpianZ_statso
D:8003CB60                                              # D:GuziZ_statso
D:8003CB60                                              # D:Gmp5kZ_statso
D:8003CB60                                              # D:Gmp5ksilZ_statso
D:8003CB60                                              # D:GspectreZ_statso
D:8003CB60                                              # D:Gfnp90Z_statso
D:8003CB60                                              # D:GsilverwppkZ_statso
D:8003CB60                                              # D:GgoldwppkZ_statso
D:8003CB80     GcartrifleZ_struct:itemheader <0, weapon_gun_unassigned, 0, 0, 1, 30.122747, 2, 0, 0>
D:8003CB80                                              # DATA XREF: D:80032474o
D:8003CB80                                              # D:Gak47Z_statso
D:8003CBA0     GcartblueZ_struct:itemheader <0, weapon_gun_unassigned, 0, 0, 1, 30.122747, 2, 0, 0>
D:8003CBA0                                              # DATA XREF: D:8003247Co
D:8003CBA0                                              # D:Gm16Z_statso
D:8003CBA0                                              # D:GsniperrifleZ_statso
D:8003CBC0     GcartshellZ_struct:itemheader <0, weapon_gun_unassigned, 0, 0, 1, 29.8451, 2, 0, 0>
D:8003CBC0                                              # DATA XREF: D:80032484o
D:8003CBC0                                              # D:GshotgunZ_statso
D:8003CBE0     GjoypadZ_struct:itemheader <0, weapon_gun_controller, 0, 0xE, 0xD, 523.96826, 4, 0, 0>
D:8003CBE0                                              # DATA XREF: D:80034BBCo
D:8003CC00                     itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CC20                     itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CC40     GbombcaseZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 6, 0, 0>
D:8003CC40                                              # DATA XREF: D:8003405Co
D:8003CC60     GflarepistolZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CC60                                              # DATA XREF: D:800340CCo
D:8003CC80     GpitongunZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CC80                                              # DATA XREF: D:80034104o
D:8003CCA0                     itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CCC0     GsilverwppkZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0xB, 0, 0>
D:8003CCC0                                              # DATA XREF: D:80033D84o
D:8003CCE0     GgoldwppkZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0xB, 0, 0>
D:8003CCE0                                              # DATA XREF: D:80033DBCo
D:8003CD00                     itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CD20     GbungeeZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CD20                                              # DATA XREF: D:8003413Co
D:8003CD40     GdoordecoderZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 60.850407, 0x10, 0, 0>
D:8003CD40                                              # DATA XREF: D:80034174o
D:8003CD60     GbombdefuserZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 84.370705, 0xC, 0, 0>
D:8003CD60                                              # DATA XREF: D:800341ACo
D:8003CD80     GbugdetectorZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CD80                                              # DATA XREF: D:800343DCo
D:8003CDA0     GsafecrackercaseZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 6, 0, 0>
D:8003CDA0                                              # DATA XREF: D:800342FCo
D:8003CDC0     GcameraZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 52.775627, 0xB, 0, 0>
D:8003CDC0                                              # DATA XREF: D:800341E4o
D:8003CDE0     GlockexploderZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CDE0                                              # DATA XREF: D:8003421Co
D:8003CE00     GdoorexploderZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CE00                                              # DATA XREF: D:80034254o
D:8003CE20     GkeyanalysercaseZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 6, 0, 0>
D:8003CE20                                              # DATA XREF: D:80034334o
D:8003CE40     GweaponcaseZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 6, 0, 0>
D:8003CE40                                              # DATA XREF: D:800342C4o
D:8003CE60     GkeycardZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 123.08884, 2, 0, 0>
D:8003CE60                                              # DATA XREF: D:80034ADCo
D:8003CE80     GkeyyaleZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 414.25156, 1, 0, 0>
D:8003CE80                                              # DATA XREF: D:80034B14o
D:8003CEA0     GkeyboltZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 759.26581, 1, 0, 0>
D:8003CEA0                                              # DATA XREF: D:80034B4Co
D:8003CEC0     GbugZ_struct:   itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 106.2163, 6, 0, 0>
D:8003CEC0                                              # DATA XREF: D:8003436Co
D:8003CEE0     GmicrocameraZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 70.039436, 7, 0, 0>
D:8003CEE0                                              # DATA XREF: D:800343A4o
D:8003CF00     GexplosivefloppyZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 60.902443, 5, 0, 0>
D:8003CF00                                              # DATA XREF: D:80034414o
D:8003CF20     GgoldeneyekeyZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 98.987083, 5, 0, 0>
D:8003CF20                                              # DATA XREF: D:8003467Co
D:8003CF40     GpolarizedglassesZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 53.776386, 2, 0, 0>
D:8003CF40                                              # DATA XREF: D:8003444Co
D:8003CF60     GcreditcardZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CF60                                              # DATA XREF: D:800344BCo
D:8003CF80     GdarkglassesZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003CF80                                              # DATA XREF: D:80034484o
D:8003CFA0     GwatchidentifierZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 9, 0, 0>
D:8003CFA0                                              # DATA XREF: D:80034564o
D:8003CFC0     GwatchcommunicatorZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 9, 0, 0>
D:8003CFC0                                              # DATA XREF: D:8003459Co
D:8003CFE0     GwatchlaserZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0x16, 0, 0>
D:8003CFE0                                              # DATA XREF: D:80033E2Co
D:8003D000     GwatchgeigercounterZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 9, 0, 0>
D:8003D000                                              # DATA XREF: D:800345D4o
D:8003D020     GwatchmagnetrepelZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 9, 0, 0>
D:8003D020                                              # DATA XREF: D:8003460Co
D:8003D040     GwatchmagnetattractZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1D, 3, 384.9288, 9, 0, 0>
D:8003D040                                              # DATA XREF: D:80034644o
D:8003D060     GgaskeyringZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 111.59859, 9, 0, 0>
D:8003D060                                              # DATA XREF: D:800344F4o
D:8003D080     GdatathiefZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 119.78231, 3, 0, 0>
D:8003D080                                              # DATA XREF: D:8003452Co
D:8003D0A0     GbriefcaseZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 6, 0, 0>
D:8003D0A0                                              # DATA XREF: D:8003428Co
D:8003D0C0     GblackboxZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 128.31796, 5, 0, 0>
D:8003D0C0                                              # DATA XREF: D:800346B4o
D:8003D0E0     GplastiqueZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 255.35242, 3, 0, 0>
D:8003D0E0                                              # DATA XREF: D:80034094o
D:8003D100     GvideotapeZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 122.69632, 9, 0, 0>
D:8003D100                                              # DATA XREF: D:800348E4o
D:8003D120     GclipboardZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 190.41742, 3, 0, 0>
D:8003D120                                              # DATA XREF: D:80034724o
D:8003D140     GstafflistZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 215.17534, 4, 0, 0>
D:8003D140                                              # DATA XREF: D:8003475Co
D:8003D160     GdossierredZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 183.54231, 4, 0, 0>
D:8003D160                                              # DATA XREF: D:80034794o
D:8003D180     GaudiotapeZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 97.531075, 9, 0, 0>
D:8003D180                                              # DATA XREF: D:800348ACo
D:8003D1A0     GdattapeZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 79.868584, 4, 0, 0>
D:8003D1A0                                              # DATA XREF: D:8003491Co
D:8003D1C0     GplansZ_struct: itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 81.950996, 5, 0, 0>
D:8003D1C0                                              # DATA XREF: D:800347CCo
D:8003D1E0     GspyfileZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003D1E0                                              # DATA XREF: D:80034804o
D:8003D200     GblueprintsZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 125.3834, 4, 0, 0>
D:8003D200                                              # DATA XREF: D:8003483Co
D:8003D220     GcircuitboardZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 138.90285, 3, 0, 0>
D:8003D220                                              # DATA XREF: D:800346ECo
D:8003D240     GmapZ_struct:   itemheader <0, weapon_gun_standard_gun, 0, 0x23, 3, 125.3834, 4, 0, 0>
D:8003D240                                              # DATA XREF: D:80034874o
D:8003D260     GspooltapeZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003D260                                              # DATA XREF: D:80034954o
D:8003D280     GmicrofilmZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003D280                                              # DATA XREF: D:8003498Co
D:8003D2A0     GmicrocodeZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003D2A0                                              # DATA XREF: D:800349C4o
D:8003D2C0     GlectreZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003D2C0                                              # DATA XREF: D:800349FCo
D:8003D2E0     GmoneyZ_struct: itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003D2E0                                              # DATA XREF: D:80034A34o
D:8003D300     GgoldbarZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003D300                                              # DATA XREF: D:80034A6Co
D:8003D320     GheroinZ_struct:itemheader <0, weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 2, 0, 0>
D:8003D320                                              # DATA XREF: D:80034AA4o
D:8003D340     dword_D_8003D340:.word    0x20000,         2,   0x30003,   0x20006
D:8003D340                                              # DATA XREF: D:8003D394o
D:8003D340                     .word    0x60002,   0x90009,   0x2000C,   0xC0002
D:8003D340                     .word    0xF000F,   0x20012,  0x120002,  0x150015
D:8003D340                     .word    0x20018,  0x180002,  0x1B001B,   0x2001E
D:8003D340                     .word   0x1E0002,  0x210021,   0x20024,  0x240000
D:8003D390     weapon_gun_controller:.word 0xD0000      # DATA XREF: D:GjoypadZ_structo
D:8003D394                     .word dword_D_8003D340
D:8003D398                     .word 0x270000
D:8003D39C                     .word 0
D:8003D3A0     dword_D_8003D3A0:.word  0x4010000,         2,         0,   0x20003
D:8003D3A0                                              # DATA XREF: D:model_guard_charactero
D:8003D3A0                     .word    0x30002,   0x60006,   0x20009,   0xC0002
D:8003D3A0                     .word    0xC0009,   0x2000F,  0x120002,  0x12000F
D:8003D3A0                     .word    0x20015,  0x180002,  0x180015,   0x2001B
D:8003D3A0                     .word   0x1E0002,  0x1E001B,   0x20021,  0x240002
D:8003D3A0                     .word   0x240021,   0x20027,  0x2A0002,  0x2A0027
D:8003D400     model_guard_character:model_data <0x100000, dword_D_8003D3A0, 0x2D0000>
D:8003D400                                              # DATA XREF: sub_CODE_7F0001F0+38o
D:8003D400                                              # sub_CODE_7F000290+38o
D:8003D400                                              # sub_CODE_7F0062C0+44o
D:8003D400                                              # D:CcamguardZ_structo
D:8003D400                                              # D:CgreyguardZ_structo
D:8003D400                                              # D:ColiveguardZ_structo
D:8003D400                                              # D:CrusguardZ_structo
D:8003D400                                              # D:CtrevguardZ_structo
D:8003D400                                              # D:CborisZ_structo
D:8003D400                                              # D:CorumovZ_structo
D:8003D400                                              # D:CtrevelyanZ_structo
D:8003D400                                              # D:CboilertrevZ_structo
D:8003D400                                              # D:CvalentinZ_structo
D:8003D400                                              # D:CxeniaZ_structo
D:8003D400                                              # D:CbaronsamediZ_structo
D:8003D400                                              # D:CjawsZ_structo
D:8003D400                                              # D:CmaydayZ_structo
D:8003D400                                              # D:CoddjobZ_structo
D:8003D400                                              # D:CnatalyaZ_structo
D:8003D400                                              # D:CarmourguardZ_structo
D:8003D400                                              # D:CcommguardZ_structo
D:8003D400                                              # D:CgreatguardZ_structo
D:8003D400                                              # D:CnavyguardZ_structo
D:8003D400                                              # D:CsnowguardZ_structo
D:8003D400                                              # D:CbluewomanZ_structo
D:8003D400                                              # D:CfattechwomanZ_structo
D:8003D400                                              # D:CtechwomanZ_structo
D:8003D400                                              # D:CjeanwomanZ_structo
D:8003D400                                              # D:CgreymanZ_structo
D:8003D400                                              # D:CbluemanZ_structo
D:8003D400                                              # D:CredmanZ_structo
D:8003D400                                              # D:CcardimanZ_structo
D:8003D400                                              # D:CcheckmanZ_structo
D:8003D400                                              # D:CtechmanZ_structo
D:8003D400                                              # D:CpilotZ_structo
D:8003D400                                              # D:Cgreatguard2Z_structo
D:8003D400                                              # D:CbluecamguardZ_structo
D:8003D400                                              # D:CmoonguardZ_structo
D:8003D400                                              # D:CmoonfemaleZ_structo
D:8003D400                                              # D:CboilerbondZ_structo
D:8003D400                                              # D:CsuitbondZ_structo
D:8003D400                                              # D:CtimberbondZ_structo
D:8003D400                                              # D:CsnowbondZ_structo
D:8003D400                                              # D:CdjbondZ_structo
D:8003D400                                              # D:CspicebondZ_structo
D:8003D40C                     .word 0
D:8003D410     CcamguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xE, 0, 0>
D:8003D410                                              # DATA XREF: D:c_item_entrieso
D:8003D430     CgreyguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1292.6892, 0, 0xD, 0, 0>
D:8003D430                                              # DATA XREF: D:8003DE24o
D:8003D450     ColiveguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0x10, 0, 0>
D:8003D450                                              # DATA XREF: D:8003DE38o
D:8003D470     CrusguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xD, 0, 0>
D:8003D470                                              # DATA XREF: D:8003DE4Co
D:8003D490     CtrevguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x12, 0, 0>
D:8003D490                                              # DATA XREF: D:8003DE60o
D:8003D4B0     CborisZ_struct: object_header <0, model_guard_character, 0, 7, 0x14, 1223.1553, 0, 0x15, 0, 0>
D:8003D4B0                                              # DATA XREF: D:8003DE88o
D:8003D4D0     CorumovZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1347.004, 0, 0x15, 0, 0>
D:8003D4D0                                              # DATA XREF: D:8003DE9Co
D:8003D4F0     CtrevelyanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1263.2534, 0, 0x10, 0, 0>
D:8003D4F0                                              # DATA XREF: D:8003DEB0o
D:8003D510     CboilertrevZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1263.2534, 0, 0x10, 0, 0>
D:8003D510                                              # DATA XREF: D:8003DEC4o
D:8003D530     CvalentinZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1208.6277, 0, 0x10, 0, 0>
D:8003D530                                              # DATA XREF: D:8003DED8o
D:8003D550     CxeniaZ_struct: object_header <0, model_guard_character, 0, 7, 0x15, 1285.4487, 0, 0x13, 0, 0>
D:8003D550                                              # DATA XREF: D:8003DEECo
D:8003D570     CbaronsamediZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1292.5995, 0, 0x19, 0, 0>
D:8003D570                                              # DATA XREF: D:8003DF00o
D:8003D590     CjawsZ_struct:  object_header <0, model_guard_character, 0, 7, 0x15, 1550.059, 0, 0x14, 0, 0>
D:8003D590                                              # DATA XREF: D:8003DF14o
D:8003D5B0     CmaydayZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1260.657, 0, 0x10, 0, 0>
D:8003D5B0                                              # DATA XREF: D:8003DF28o
D:8003D5D0     CoddjobZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1082.4603, 0, 0x12, 0, 0>
D:8003D5D0                                              # DATA XREF: D:8003DF3Co
D:8003D5F0     CnatalyaZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1226.1493, 0, 0x10, 0, 0>
D:8003D5F0                                              # DATA XREF: D:8003DF50o
D:8003D610     CarmourguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x11, 0, 0>
D:8003D610                                              # DATA XREF: D:8003DF64o
D:8003D630     CcommguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xF, 0, 0>
D:8003D630                                              # DATA XREF: D:8003DF78o
D:8003D650     CgreatguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1283.0787, 0, 0xB, 0, 0>
D:8003D650                                              # DATA XREF: D:8003DF8Co
D:8003D670     CnavyguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xF, 0, 0>
D:8003D670                                              # DATA XREF: D:8003DFA0o
D:8003D690     CsnowguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1261.1731, 0, 0x11, 0, 0>
D:8003D690                                              # DATA XREF: D:8003DFB4o
D:8003D6B0     CbluewomanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1148.2167, 0, 0xD, 0, 0>
D:8003D6B0                                              # DATA XREF: D:8003E018o
D:8003D6D0     CfattechwomanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1149.4025, 0, 0xC, 0, 0>
D:8003D6D0                                              # DATA XREF: D:8003E02Co
D:8003D6F0     CtechwomanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1158.2109, 0, 0xC, 0, 0>
D:8003D6F0                                              # DATA XREF: D:8003E040o
D:8003D710     CjeanwomanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1124.0725, 0, 0xF, 0, 0>
D:8003D710                                              # DATA XREF: D:8003E054o
D:8003D730     CgreymanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1293.0195, 0, 0xF, 0, 0>
D:8003D730                                              # DATA XREF: D:8003E068o
D:8003D750     CbluemanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xF, 0, 0>
D:8003D750                                              # DATA XREF: D:8003E07Co
D:8003D770     CredmanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xF, 0, 0>
D:8003D770                                              # DATA XREF: D:8003E090o
D:8003D790     CcardimanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xE, 0, 0>
D:8003D790                                              # DATA XREF: D:8003E0A4o
D:8003D7B0     CcheckmanZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0x10, 0, 0>
D:8003D7B0                                              # DATA XREF: D:8003E0B8o
D:8003D7D0     CtechmanZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1292.6892, 0, 0xC, 0, 0>
D:8003D7D0                                              # DATA XREF: D:8003E0CCo
D:8003D7F0     CpilotZ_struct: object_header <0, model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x18, 0, 0>
D:8003D7F0                                              # DATA XREF: D:8003E0E0o
D:8003D810     Cgreatguard2Z_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1283.0787, 0, 0x10, 0, 0>
D:8003D810                                              # DATA XREF: D:8003E0F4o
D:8003D830     CbluecamguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xE, 0, 0>
D:8003D830                                              # DATA XREF: D:8003E108o
D:8003D850     CmoonguardZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0xD, 0, 0>
D:8003D850                                              # DATA XREF: D:8003E11Co
D:8003D870     CmoonfemaleZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1124.0725, 0, 0xB, 0, 0>
D:8003D870                                              # DATA XREF: D:8003E130o
D:8003D890     CboilerbondZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1273.6262, 0, 0xD, 0, 0>
D:8003D890                                              # DATA XREF: D:8003DFC8o
D:8003D8B0     CsuitbondZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1292.3391, 0, 0xE, 0, 0>
D:8003D8B0                                              # DATA XREF: D:8003DFDCo
D:8003D8D0     CtimberbondZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1282.7715, 0, 0x10, 0, 0>
D:8003D8D0                                              # DATA XREF: D:8003DFF0o
D:8003D8F0     CsnowbondZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1299.1359, 0, 0xE, 0, 0>
D:8003D8F0                                              # DATA XREF: D:8003E004o
D:8003D910     CdjbondZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1285.0543, 0, 0xD, 0, 0>
D:8003D910                                              # DATA XREF: D:stru_D_8003DE74o
D:8003D930     Csuit_lf_handz_struct:object_header <0, model_suit_lf_hand, 0, 0xA, 9, 12231.949, 0, 0x16, 0, 0>
D:8003D930                                              # DATA XREF: D:80034B84o
D:8003D930                                              # D:stru_D_8003E144o
D:8003D950     CheadkarlZ_struct:object_header <0, 0, 0, 2, 1, 218.15375, 0, 6, 0, 0>
D:8003D950                                              # DATA XREF: D:8003E158o
D:8003D970     CheadalanZ_struct:object_header <0, 0, 0, 2, 1, 215.03685, 0, 4, 0, 0>
D:8003D970                                              # DATA XREF: D:8003E16Co
D:8003D990     CheadpeteZ_struct:object_header <0, 0, 0, 2, 1, 216.28949, 0, 4, 0, 0>
D:8003D990                                              # DATA XREF: D:8003E180o
D:8003D9B0     CheadmartinZ_struct:object_header <0, 0, 0, 2, 1, 222.34796, 0, 6, 0, 0>
D:8003D9B0                                              # DATA XREF: D:8003E194o
D:8003D9D0     stru_D_8003D9D0:object_header <0, 0, 0, 2, 1, 220.2446, 0, 5, 0, 0>
D:8003D9D0                                              # DATA XREF: D:8003E1A8o
D:8003D9F0     stru_D_8003D9F0:object_header <0, 0, 0, 2, 1, 201.51955, 0, 5, 0, 0>
D:8003D9F0                                              # DATA XREF: D:8003E1BCo
D:8003DA10     stru_D_8003DA10:object_header <0, 0, 0, 2, 1, 212.62949, 0, 5, 0, 0>
D:8003DA10                                              # DATA XREF: D:8003E1F8o
D:8003DA30     stru_D_8003DA30:object_header <0, 0, 0, 2, 1, 218.35564, 0, 4, 0, 0>
D:8003DA30                                              # DATA XREF: D:8003E1D0o
D:8003DA50     stru_D_8003DA50:object_header <0, 0, 0, 2, 1, 192.53412, 0, 4, 0, 0>
D:8003DA50                                              # DATA XREF: D:8003E1E4o
D:8003DA70     stru_D_8003DA70:object_header <0, 0, 0, 2, 1, 218.35564, 0, 4, 0, 0>
D:8003DA70                                              # DATA XREF: D:8003E20Co
D:8003DA90     stru_D_8003DA90:object_header <0, 0, 0, 2, 1, 227.52234, 0, 4, 0, 0>
D:8003DA90                                              # DATA XREF: D:8003E220o
D:8003DAB0     stru_D_8003DAB0:object_header <0, 0, 0, 2, 1, 228.29831, 0, 4, 0, 0>
D:8003DAB0                                              # DATA XREF: D:8003E234o
D:8003DAD0     stru_D_8003DAD0:object_header <0, 0, 0, 2, 1, 235.64778, 0, 6, 0, 0>
D:8003DAD0                                              # DATA XREF: D:8003E248o
D:8003DAF0     stru_D_8003DAF0:object_header <0, 0, 0, 2, 1, 218.35564, 0, 5, 0, 0>
D:8003DAF0                                              # DATA XREF: D:8003E25Co
D:8003DB10     stru_D_8003DB10:object_header <0, 0, 0, 2, 1, 240.50017, 0, 4, 0, 0>
D:8003DB10                                              # DATA XREF: D:8003E270o
D:8003DB30     stru_D_8003DB30:object_header <0, 0, 0, 2, 1, 234.83342, 0, 4, 0, 0>
D:8003DB30                                              # DATA XREF: D:8003E284o
D:8003DB50     stru_D_8003DB50:object_header <0, 0, 0, 2, 1, 228.24614, 0, 4, 0, 0>
D:8003DB50                                              # DATA XREF: D:8003E298o
D:8003DB70     stru_D_8003DB70:object_header <0, 0, 0, 2, 1, 228.55029, 0, 4, 0, 0>
D:8003DB70                                              # DATA XREF: D:8003E2ACo
D:8003DB90     stru_D_8003DB90:object_header <0, 0, 0, 2, 1, 212.62949, 0, 2, 0, 0>
D:8003DB90                                              # DATA XREF: D:8003E2C0o
D:8003DBB0     stru_D_8003DBB0:object_header <0, 0, 0, 2, 1, 219.82707, 0, 6, 0, 0>
D:8003DBB0                                              # DATA XREF: D:8003E2D4o
D:8003DBD0     stru_D_8003DBD0:object_header <0, 0, 0, 2, 1, 193.20615, 0, 5, 0, 0>
D:8003DBD0                                              # DATA XREF: D:8003E2E8o
D:8003DBF0     stru_D_8003DBF0:object_header <0, 0, 0, 2, 1, 235.64778, 0, 4, 0, 0>
D:8003DBF0                                              # DATA XREF: D:8003E2FCo
D:8003DC10     stru_D_8003DC10:object_header <0, 0, 0, 2, 1, 223.18559, 0, 4, 0, 0>
D:8003DC10                                              # DATA XREF: D:8003E310o
D:8003DC30     stru_D_8003DC30:object_header <0, 0, 0, 2, 1, 218.35564, 0, 5, 0, 0>
D:8003DC30                                              # DATA XREF: D:8003E324o
D:8003DC50     stru_D_8003DC50:object_header <0, 0, 0, 2, 1, 193.20615, 0, 4, 0, 0>
D:8003DC50                                              # DATA XREF: D:8003E338o
D:8003DC70     stru_D_8003DC70:object_header <0, 0, 0, 2, 1, 235.64778, 0, 5, 0, 0>
D:8003DC70                                              # DATA XREF: D:8003E34Co
D:8003DC90     stru_D_8003DC90:object_header <0, 0, 0, 2, 1, 193.20615, 0, 3, 0, 0>
D:8003DC90                                              # DATA XREF: D:8003E360o
D:8003DCB0     stru_D_8003DCB0:object_header <0, 0, 0, 2, 1, 224.83139, 0, 3, 0, 0>
D:8003DCB0                                              # DATA XREF: D:8003E374o
D:8003DCD0     stru_D_8003DCD0:object_header <0, 0, 0, 2, 1, 219.97256, 0, 3, 0, 0>
D:8003DCD0                                              # DATA XREF: D:8003E388o
D:8003DCF0     stru_D_8003DCF0:object_header <0, 0, 0, 2, 1, 203.44904, 0, 3, 0, 0>
D:8003DCF0                                              # DATA XREF: D:8003E39Co
D:8003DD10     stru_D_8003DD10:object_header <0, 0, 0, 2, 1, 196.83067, 0, 3, 0, 0>
D:8003DD10                                              # DATA XREF: D:8003E3B0o
D:8003DD30     stru_D_8003DD30:object_header <0, 0, 0, 2, 1, 176.67717, 0, 1, 0, 0>
D:8003DD30                                              # DATA XREF: D:8003E3C4o
D:8003DD50     stru_D_8003DD50:object_header <0, 0, 0, 2, 1, 190.61967, 0, 4, 0, 0>
D:8003DD50                                              # DATA XREF: D:8003E3D8o
D:8003DD70     CheadbrosnansuitZ_struct:object_header <0, 0, 0, 2, 1, 212.45657, 0, 5, 0, 0>
D:8003DD70                                              # DATA XREF: D:8003E3ECo
D:8003DD90     CheadbrosnantimberZ_struct:object_header <0, 0, 0, 2, 1, 179.28358, 0, 4, 0, 0>
D:8003DD90                                              # DATA XREF: D:8003E400o
D:8003DDB0     CheadbrosnansnowZ_struct:object_header <0, 0, 0, 2, 1, 225.0605, 0, 6, 0, 0>
D:8003DDB0                                              # DATA XREF: D:8003E414o
D:8003DDD0     CheadbrosnanZ_struct:object_header <0, 0, 0, 2, 1, 189.48112, 0, 5, 0, 0>
D:8003DDD0                                              # DATA XREF: D:stru_D_8003E428o
D:8003DDF0     CspicebondZ_struct:object_header <0, model_guard_character, 0, 7, 0x15, 1208.6448, 0, 0x11, 0, 0>
D:8003DDF0                                              # DATA XREF: D:8003E43Co
D:8003DE10     c_item_entries: c_itementry <CcamguardZ_struct, aCcamguardz, 1.0, 1.0, 0x1000000>
D:8003DE10                                              # DATA XREF: set_new_rand_head_bodiesr
D:8003DE10                                              # set_new_rand_head_bodies+1Co
D:8003DE10                                              # set_new_rand_head_bodies+20r
D:8003DE10                                              # sub_CODE_7F008E80+170o
D:8003DE10                                              # init_menu18_displaycast+2A0o
D:8003DE10                                              # init_menu18_displaycast+318o
D:8003DE10                                              # load_body_head_if_not_loaded+8o
D:8003DE10                                              # maybe_load_models_for_guards+8o
D:8003DE10                                              # retrieve_header_for_body_and_head+8o
D:8003DE10                                              # retrieve_header_for_body_and_head+90r
D:8003DE10                                              # solo_char_load+2F0o
D:8003DE10                                              # solo_char_load+380o
D:8003DE10                                              # solo_char_load+4D4o
D:8003DE10                                              # solo_char_load:loc_CODE_7F07A1F8o
D:8003DE10                                              # "CcamguardZ"
D:8003DE24                     c_itementry <CgreyguardZ_struct, aCgreyguardz, 1.0, 1.0, 0x1000000>  # "CgreyguardZ"
D:8003DE38                     c_itementry <ColiveguardZ_struct, aColiveguardz, 1.0, 1.0, 0x1000000>  # "ColiveguardZ"
D:8003DE4C                     c_itementry <CrusguardZ_struct, aCrusguardz, 1.0, 1.0, 0x1000000>  # "CrusguardZ"
D:8003DE60                     c_itementry <CtrevguardZ_struct, aCtrevguardz, 1.0, 1.0, 0x1000000>  # "CtrevguardZ"
D:8003DE74     stru_D_8003DE74:c_itementry <CdjbondZ_struct, aCdjbondz, 1.0, 1.0446, 0x1000000>
D:8003DE74                                              # DATA XREF: sub_CODE_7F008E80+190r
D:8003DE74                                              # sub_CODE_7F008E80+210r
D:8003DE74                                              # sub_CODE_7F008E80+198r
D:8003DE74                                              # sub_CODE_7F008E80+1A0r
D:8003DE74                                              # "CdjbondZ"
D:8003DE88                     c_itementry <CborisZ_struct, aCborisz, 1.0, 0.9702, 0x1010000>  # "CborisZ"
D:8003DE9C                     c_itementry <CorumovZ_struct, aCorumovz, 1.0, 1.0778, 0x1010000>  # "CorumovZ"
D:8003DEB0                     c_itementry <CtrevelyanZ_struct, aCtrevelyanz, 1.0, 1.0, 0x1010000>  # "CtrevelyanZ"
D:8003DEC4                     c_itementry <CboilertrevZ_struct, aCboilertrevz, 1.0, 1.0, 0x1010000>  # "CboilertrevZ"
D:8003DED8                     c_itementry <CvalentinZ_struct, aCvalentinz, 1.0, 0.93239999, 0x1010000>  # "CvalentinZ"
D:8003DEEC                     c_itementry <CxeniaZ_struct, aCxeniaz, 1.0, 1.0, 0x10000>  # "CxeniaZ"
D:8003DF00                     c_itementry <CbaronsamediZ_struct, aCbaronsamediz, 1.0, 1.0, 0x1010000>  # "CbaronsamediZ"
D:8003DF14                     c_itementry <CjawsZ_struct, aCjawsz, 1.0, 1.199, 0x1010000>  # "CjawsZ"
D:8003DF28                     c_itementry <CmaydayZ_struct, aCmaydayz, 1.0, 1.0, 0x10000>  # "CmaydayZ"
D:8003DF3C                     c_itementry <CoddjobZ_struct, aCoddjobz, 1.0, 0.78780001, 0x1010000>  # "CoddjobZ"
D:8003DF50                     c_itementry <CnatalyaZ_struct, aCnatalyaz, 1.0, 0.96609998, 0x10000>  # "CnatalyaZ"
D:8003DF64                     c_itementry <CarmourguardZ_struct, aCarmourguardz, 1.0, 1.0, 0x1000000>  # "CarmourguardZ"
D:8003DF78                     c_itementry <CcommguardZ_struct, aCcommguardz, 1.0, 1.0, 0x1000000>  # "CcommguardZ"
D:8003DF8C                     c_itementry <CgreatguardZ_struct, aCgreatguardz, 1.0, 1.0, 0x1000000>  # "CgreatguardZ"
D:8003DFA0                     c_itementry <CnavyguardZ_struct, aCnavyguardz, 1.0, 1.0, 0x1000000>  # "CnavyguardZ"
D:8003DFB4                     c_itementry <CsnowguardZ_struct, aCsnowguardz, 1.0, 1.0, 0x1010000>  # "CsnowguardZ"
D:8003DFC8                     c_itementry <CboilerbondZ_struct, aCboilerbondz, 1.0, 1.0403, 0x1000000>  # "CboilerbondZ"
D:8003DFDC                     c_itementry <CsuitbondZ_struct, aCsuitbondz, 1.0, 1.058, 0x1000000>  # "CsuitbondZ"
D:8003DFF0                     c_itementry <CtimberbondZ_struct, aCtimberbondz, 1.0, 1.0438, 0x1000000>  # "CtimberbondZ"
D:8003E004                     c_itementry <CsnowbondZ_struct, aCsnowbondz, 1.0, 1.0438, 0x1000000>  # "CsnowbondZ"
D:8003E018                     c_itementry <CbluewomanZ_struct, aCbluewomanz, 1.0, 0.88529998, 0>  # "CbluewomanZ"
D:8003E02C                     c_itementry <CfattechwomanZ_struct, aCfattechwomanz, 1.0, 0.88529998, 0>  # "CfattechwomanZ"
D:8003E040                     c_itementry <CtechwomanZ_struct, aCtechwomanz, 1.0, 0.91600001, 0>  # "CtechwomanZ"
D:8003E054                     c_itementry <CjeanwomanZ_struct, aCjeanwomanz, 1.0, 0.88529998, 0>  # "CjeanwomanZ"
D:8003E068                     c_itementry <CgreymanZ_struct, aCgreymanz, 1.0, 1.0, 0x1000000>  # "CgreymanZ"
D:8003E07C                     c_itementry <CbluemanZ_struct, aCbluemanz, 1.0, 1.0, 0x1000000>  # "CbluemanZ"
D:8003E090                     c_itementry <CredmanZ_struct, aCredmanz, 1.0, 1.0, 0x1000000>  # "CredmanZ"
D:8003E0A4                     c_itementry <CcardimanZ_struct, aCcardimanz, 1.0, 1.0, 0x1000000>  # "CcardimanZ"
D:8003E0B8                     c_itementry <CcheckmanZ_struct, aCcheckmanz, 1.0, 1.0, 0x1000000>  # "CcheckmanZ"
D:8003E0CC                     c_itementry <CtechmanZ_struct, aCtechmanz, 1.0, 1.0, 0x1000000>  # "CtechmanZ"
D:8003E0E0                     c_itementry <CpilotZ_struct, aCpilotz, 1.0, 1.0, 0x1010000>  # "CpilotZ"
D:8003E0F4                     c_itementry <Cgreatguard2Z_struct, aCgreatguard2z, 1.0, 1.0, 0x1000000>  # "Cgreatguard2Z"
D:8003E108                     c_itementry <CbluecamguardZ_struct, aCbluecamguardz, 1.0, 1.0, 0x1000000>  # "CbluecamguardZ"
D:8003E11C                     c_itementry <CmoonguardZ_struct, aCmoonguardz, 1.0, 1.0, 0x1000000>  # "CmoonguardZ"
D:8003E130                     c_itementry <CmoonfemaleZ_struct, aCmoonfemalez, 1.0, 0.88529998, 0>  # "CmoonfemaleZ"
D:8003E144     stru_D_8003E144:c_itementry <Csuit_lf_handz_struct, aCsuit_lf_handz_0, 0.1, 1.0, 0x1000000>
D:8003E144                                              # DATA XREF: sub_CODE_7F07E7CC+50r
D:8003E144                                              # "Csuit_lf_handZ"
D:8003E158                     c_itementry <CheadkarlZ_struct, aCheadkarlz, 1.0, 1.0, 0x1010000>  # "CheadkarlZ"
D:8003E16C                     c_itementry <CheadalanZ_struct, aCheadalanz, 1.0, 1.0, 0x1010000>  # "CheadalanZ"
D:8003E180                     c_itementry <CheadpeteZ_struct, aCheadpetez, 1.0, 1.0, 0x1010000>  # "CheadpeteZ"
D:8003E194                     c_itementry <CheadmartinZ_struct, aCheadmartinz, 1.0, 1.0, 0x1010000>  # "CheadmartinZ"
D:8003E1A8                     c_itementry <stru_D_8003D9D0, aCheadmarkz, 1.0, 1.0, 0x1010000>  # "CheadmarkZ"
D:8003E1BC                     c_itementry <stru_D_8003D9F0, aCheadduncanz, 1.0, 1.0, 0x1010000>  # "CheadduncanZ"
D:8003E1D0                     c_itementry <stru_D_8003DA30, aCheadshaunz, 1.0, 1.0, 0x1010000>  # "CheadshaunZ"
D:8003E1E4                     c_itementry <stru_D_8003DA50, aCheaddwaynez, 1.0, 1.0, 0x1010000>  # "CheaddwayneZ"
D:8003E1F8                     c_itementry <stru_D_8003DA10, aCheadbz, 1.0, 1.0, 0x1010000>  # "CheadbZ"
D:8003E20C                     c_itementry <stru_D_8003DA70, aCheaddavez, 1.0, 1.0, 0x1010000>  # "CheaddaveZ"
D:8003E220                     c_itementry <stru_D_8003DA90, aCheadgrantz, 1.0, 1.0, 0x1010000>  # "CheadgrantZ"
D:8003E234                     c_itementry <stru_D_8003DAB0, aCheaddesz, 1.0, 1.0, 0x1010000>  # "CheaddesZ"
D:8003E248                     c_itementry <stru_D_8003DAD0, aCheadchrisz, 1.0, 1.0, 0x1010000>  # "CheadchrisZ"
D:8003E25C                     c_itementry <stru_D_8003DAF0, aCheadleez, 1.0, 1.0, 0x1010000>  # "CheadleeZ"
D:8003E270                     c_itementry <stru_D_8003DB10, aCheadneilz, 1.0, 1.0, 0x1010000>  # "CheadneilZ"
D:8003E284                     c_itementry <stru_D_8003DB30, aCheadjimz, 1.0, 1.0, 0x1010000>  # "CheadjimZ"
D:8003E298                     c_itementry <stru_D_8003DB50, aCheadrobinz, 1.0, 1.0, 0x1010000>  # "CheadrobinZ"
D:8003E2AC                     c_itementry <stru_D_8003DB70, aCheadstevehz, 1.0, 1.0, 0x1010000>  # "CheadstevehZ"
D:8003E2C0                     c_itementry <stru_D_8003DB90, aCheadbalaclavaz, 1.0, 1.0, 0x1010000>  # "CheadbalaclavaZ"
D:8003E2D4                     c_itementry <stru_D_8003DBB0, aCheadbikez, 1.0, 1.0, 0x1010000>  # "CheadbikeZ"
D:8003E2E8                     c_itementry <stru_D_8003DBD0, aCheadgrahamz, 1.0, 1.0, 0x1010000>  # "CheadgrahamZ"
D:8003E2FC                     c_itementry <stru_D_8003DBF0, aCheadsteveez, 1.0, 1.0, 0x1010000>  # "CheadsteveeZ"
D:8003E310                     c_itementry <stru_D_8003DC10, aCheadjoelz, 1.0, 1.0, 0x1010000>  # "CheadjoelZ"
D:8003E324                     c_itementry <stru_D_8003DC30, aCheadscottz, 1.0, 1.0, 0x1010000>  # "CheadscottZ"
D:8003E338                     c_itementry <stru_D_8003DC50, aCheadjoez, 1.0, 1.0, 0x1010000>  # "CheadjoeZ"
D:8003E34C                     c_itementry <stru_D_8003DC70, aCheadkenz, 1.0, 1.0, 0x1010000>  # "CheadkenZ"
D:8003E360                     c_itementry <stru_D_8003DC90, aCheadjoe2z, 1.0, 1.0, 0x1010000>  # "Cheadjoe2Z"
D:8003E374                     c_itementry <stru_D_8003DCB0, aCheadmishkinz, 1.0, 1.0, 0x1010000>  # "CheadmishkinZ"
D:8003E388                     c_itementry <stru_D_8003DCD0, aCheadsallyz, 1.0, 1.0, 0x10000>  # "CheadsallyZ"
D:8003E39C                     c_itementry <stru_D_8003DCF0, aCheadmarionz, 1.0, 1.0, 0x10000>  # "CheadmarionZ"
D:8003E3B0                     c_itementry <stru_D_8003DD10, aCheadmandyz, 1.0, 1.0, 0x10000>  # "CheadmandyZ"
D:8003E3C4                     c_itementry <stru_D_8003DD30, aCheadvivienz, 1.0, 1.0, 0x10000>  # "CheadvivienZ"
D:8003E3D8                     c_itementry <stru_D_8003DD50, aCheadbrosnanboilerz, 1.0, 1.0, 0x1010000>  # "CheadbrosnanboilerZ"
D:8003E3EC                     c_itementry <CheadbrosnansuitZ_struct, aCheadbrosnansuitz, 1.0, 1.0, 0x1010000>  # "CheadbrosnansuitZ"
D:8003E400                     c_itementry <CheadbrosnantimberZ_struct, aCheadbrosnantimberz, 1.0, 1.0, 0x1010000>  # "CheadbrosnantimberZ"
D:8003E414                     c_itementry <CheadbrosnansnowZ_struct, aCheadbrosnansnowz, 1.0, 1.0, 0x1010000>  # "CheadbrosnansnowZ"
D:8003E428     stru_D_8003E428:c_itementry <CheadbrosnanZ_struct, aCheadbrosnanz, 1.0, 1.0, 0x1010000>
D:8003E428                                              # DATA XREF: sub_CODE_7F008E80+1D0r
D:8003E428                                              # sub_CODE_7F008E80+214r
D:8003E428                                              # sub_CODE_7F008E80+1D8r
D:8003E428                                              # sub_CODE_7F008E80+1E0r
D:8003E428                                              # "CheadbrosnanZ"
D:8003E43C                     c_itementry <CspicebondZ_struct, aCspicebondz, 0.94999999, 0.96609998, 0x10000>  # "CspicebondZ"
D:8003E450                     .word 0, 0
D:8003E458                     .float 1.0
D:8003E45C                     .word 0
D:8003E460                     .word 0
D:8003E464     flt_D_8003E464: .float -0.076300003, 0.77999997,-1.2696    , 1.1694109 
D:8003E464                                              # DATA XREF: sub_CODE_7F020EF0+738o
D:8003E464                     .float  1.120654  , 1.05959   ,-0.25760001,-0.47319999
D:8003E464                     .float -1.5686001 , 1.132916  , 1.0       , 1.080207
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.039999999, 0.74000001
D:8003E464                     .float -0.63999999, 1.132795  , 1.167207  , 1.035167
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.033500001, 0.24959999
D:8003E464                     .float  0.16599999, 1.115045  , 0.94169998, 1.042492
D:8003E464                     .float -0.070299998, 0.4919    ,-0.83359998, 1.072812
D:8003E464                     .float  1.088326  , 0.926121  ,-0.1       , 0.42750001
D:8003E464                     .float -0.48249999, 1.033368  , 0.96552098, 0.929905
D:8003E464                     .float  0.18000001, 0.0       , 0.0       , 1.072214
D:8003E464                     .float  1.0       , 1.0       , 0.237     , 0.977
D:8003E464                     .float -0.44      , 1.178463  , 1.14061   , 1.143465
D:8003E464                     .float -0.090300001, 0.23190001, 0.12639999, 0.99080002
D:8003E464                     .float  1.02      , 0.8466    , 0.0       , 0.1485
D:8003E464                     .float  0.3793    , 1.1548001 , 0.99190003, 0.95139998
D:8003E464                     .float -0.14820001, 0.44100001, 0.1727    , 1.050034
D:8003E464                     .float  1.0       , 1.05445   ,-0.4941    ,-0.26409999
D:8003E464                     .float -0.18000001, 0.90368301, 0.72551203, 1.001314
D:8003E464                     .float  0.1318    , 0.30100101, 1.572699  , 0.98799503
D:8003E464                     .float  1.0       , 1.05445   , 0.0       , 0.73019999
D:8003E464                     .float  0.71740001, 1.1923    , 1.1834    , 1.091924
D:8003E464                     .float -0.0942    ,-0.74190003, 0.94260001, 0.98659998
D:8003E464                     .float  0.91689998, 0.94760001, 0.0535    , 0.61510003
D:8003E464                     .float  1.076     , 1.05092   , 0.90002   , 1.122508
D:8003E464                     .float -0.079999998, 0.1085    ,-0.56629997, 1.192598
D:8003E464                     .float  1.079134  , 1.199971  ,-0.35640001,-0.28709999
D:8003E464                     .float -0.36950001, 1.035176  , 0.838543  , 1.121092
D:8003E464                     .float  0.065300003,-0.4664    , 0.72000003, 1.050106
D:8003E464                     .float  1.0       , 1.11042   ,-0.079999998, 0.4885
D:8003E464                     .float  0.093699999, 1.158567  , 1.2356189 , 1.194388
D:8003E464                     .float -0.0942    ,-0.3017    , 0.59450001, 1.0671999
D:8003E464                     .float  1.0218    , 1.0174    , 0.12      ,-0.1515
D:8003E464                     .float  0.95370001, 1.124017  , 0.966048  , 1.206121
D:8003E464                     .float -0.19310001, 0.2334    ,-0.64850003, 1.1800359
D:8003E464                     .float  1.0401829 , 1.154537  ,-0.36230001,-0.133
D:8003E464                     .float -0.486     , 1.0536211 , 1.0       , 1.1495841
D:8003E464                     .float  0.0955    , 0.68099999, 0.78799999, 1.0152
D:8003E464                     .float  1.1926    , 1.1308    ,-0.0823    , 0.36700001
D:8003E464                     .float  0.37400001, 1.311748  , 1.115972  , 1.166244
D:8003E464                     .float -0.0942    , 0.1768    , 0.5248    , 1.0470001
D:8003E464                     .float  1.0218    , 0.99800003, 0.0       ,-0.0964
D:8003E464                     .float  0.82999998, 1.1109999 , 0.85180199, 1.180503
D:8003E464                     .float -0.1832    , 0.32120001,-1.2381001 , 1.125683
D:8003E464                     .float  1.091681  , 0.98079097,-0.55049998,-0.60839999
D:8003E464                     .float -1.189499  , 1.023566  , 0.8326    , 1.0637
D:8003E464                     .float  0.076800004, 0.32120001,-0.118101  , 1.059677
D:8003E464                     .float  1.091681  , 1.000479  , 0.0       , 0.29890001
D:8003E464                     .float -0.67299998, 1.1367    , 1.0526    , 0.99227399
D:8003E464                     .float -0.0942    , 0.032000002,-0.29699999, 1.0402
D:8003E464                     .float  0.92860001, 0.88690001, 0.0       , 0.26879999
D:8003E464                     .float  0.057399999, 1.041842  , 0.81959999, 0.99637401
D:8003E464                     .float  0.079700001, 0.3511    , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0835    , 0.14      , 0.1965
D:8003E464                     .float -0.058398999, 1.012674  , 0.96799999, 1.098917
D:8003E464                     .float  0.1629    , 0.78799999, 1.0746    , 0.92205501
D:8003E464                     .float  1.0688    , 1.055297  ,-0.074500002, 0.8477
D:8003E464                     .float  0.71810001, 1.154819  , 1.177258  , 1.031684
D:8003E464                     .float -0.0145    , 0.047699999, 0.89810002, 1.0404
D:8003E464                     .float  1.0       , 0.94309998, 0.32550001, 0.36770001
D:8003E464                     .float  0.93809998, 1.044217  , 0.97841102, 1.127771
D:8003E464                     .float -0.1832    ,-0.058800001,-1.5781    , 1.095929
D:8003E464                     .float  0.96300697, 0.92348999,-0.4411    ,-0.64840001
D:8003E464                     .float -1.839099  , 1.059271  , 0.8326    , 0.96849501
D:8003E464                     .float  0.19679999,-0.3188    ,-0.43810099, 1.070675
D:8003E464                     .float  1.053777  , 0.88628101, 0.0       , 0.29890001
D:8003E464                     .float -0.83139998, 1.1154    , 1.0328    , 1.0036
D:8003E464                     .float -0.0942    ,-0.1275    ,-0.52109998, 1.0402
D:8003E464                     .float  0.92180002, 0.8617    , 0.079999998,-0.2383
D:8003E464                     .float -0.22940101, 1.063022  , 0.80879998, 0.90789998
D:8003E464                     .float  0.1165    , 0.58780003,-1.3096    , 1.136481
D:8003E464                     .float  1.0409    , 1.065612  ,-0.070600003, 0.0152
D:8003E464                     .float -1.2391    , 1.002256  , 0.76669598, 1.029659
D:8003E464                     .float  0.2218    , 0.0       , 0.0       , 1.0852
D:8003E464                     .float  1.0       , 1.0       , 0.063000001, 0.7561
D:8003E464                     .float -0.45269999, 1.2085    , 1.1014    , 1.0664001
D:8003E464                     .float  0.065499999,-0.1097    ,-0.3497    , 1.0404
D:8003E464                     .float  0.90915602, 0.94940001, 0.0       , 0.336
D:8003E464                     .float  0.082999997, 1.150862  , 0.94169998, 1.0
D:8003E464                     .float -0.054200001, 0.27079999,-0.082099997, 1.0367
D:8003E464                     .float  1.0367    , 1.0367    , 0.34119999,-0.55879998
D:8003E464                     .float -0.3044    , 1.113436  , 0.96799999, 1.076647
D:8003E464                     .float  0.0495    , 0.63980001, 1.2178    , 0.95099998
D:8003E464                     .float  1.1126    , 1.0413001 , 0.0       , 0.53640002
D:8003E464                     .float  0.75220001, 1.1976    , 1.1463    , 1.1374
D:8003E464                     .float -0.0145    ,-0.64749998, 1.0477999 , 0.95289999
D:8003E464                     .float  0.92180002, 0.90579998, 0.16      , 0.61830002
D:8003E464                     .float  1.128299  , 1.083438  , 0.91670603, 1.0666929
D:8003E464                     .float -0.2586    , 0.93580002,-0.2463    , 1.1057
D:8003E464                     .float  1.0116    , 1.0927    ,-0.1788    ,-0.31310001
D:8003E464                     .float -0.55299997, 1.1071    , 1.0       , 1.071945
D:8003E464                     .float  0.0955    , 0.16230001, 0.50150001, 1.0506001
D:8003E464                     .float  1.0       , 1.1032    , 0.081200004, 0.2269
D:8003E464                     .float  0.50700003, 1.1071    , 1.178908  , 1.189239
D:8003E464                     .float -0.0145    ,-0.68440002, 0.54070002, 1.0470001
D:8003E464                     .float  0.92699999, 1.027078  , 0.0       ,-0.0164
D:8003E464                     .float  0.66399997, 1.2108999 , 1.0       , 1.0729001
D:8003E464                     .float -0.1487    , 0.88779998,-0.41060001, 1.110018
D:8003E464                     .float  0.98460901, 1.110518  , 0.0012000001,-0.61879998
D:8003E464                     .float -0.34439901, 1.099178  , 0.916071  , 1.054984
D:8003E464                     .float  0.0429    , 0.2149    , 0.4298    , 1.0455
D:8003E464                     .float  1.0688    , 1.1514    , 0.0012000001,-0.0188
D:8003E464                     .float  0.65560102, 1.1957231 , 1.079964  , 1.200996
D:8003E464                     .float -0.0145    ,-0.48769999, 0.44909999, 1.003074
D:8003E464                     .float  1.0       , 0.98259997, 0.0       , 0.396
D:8003E464                     .float  0.8362    , 1.1622    , 0.91339999, 1.066853
D:8003E464                     .float -0.29030001, 1.0714999 ,-0.3504    , 1.125893
D:8003E464                     .float  1.127159  , 1.177758  , 0.0       ,-0.079999998
D:8003E464                     .float -0.373     , 1.099718  , 1.0       , 1.0947551
D:8003E464                     .float  0.0       , 0.78799999, 0.64469999, 1.0
D:8003E464                     .float  1.0       , 1.0963    ,-0.074699998, 1.5436
D:8003E464                     .float  0.1979    , 1.1497999 , 1.1835999 , 1.0791
D:8003E464                     .float -0.090300001,-0.1085    , 0.68959999, 1.024099
D:8003E464                     .float  1.0       , 0.98965299, 0.0       , 0.63230002
D:8003E464                     .float  0.7913    , 1.1081001 , 0.93440002, 1.0779999
D:8003E464                     .float  0.12      , 0.40000001, 0.039999999, 1.022947
D:8003E464                     .float  0.92226201, 1.004824  , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0429    , 0.75889999, 1.2895    , 0.94440001
D:8003E464                     .float  1.0       , 1.0551    , 0.0       , 0.546
D:8003E464                     .float  0.79729998, 1.1483001 , 1.1267999 , 1.1388
D:8003E464                     .float  0.065099999,-0.54320002, 1.1224999 , 0.93949997
D:8003E464                     .float  0.92699999, 0.93040001, 0.1265    , 0.36359999
D:8003E464                     .float  1.079     , 1.1109999 , 1.0       , 1.1166
D:8003E464                     .float -0.278     , 1.272301  ,-0.55269998, 1.24701
D:8003E464                     .float  1.0737129 , 1.118222  ,-0.23639999, 0.58200002
D:8003E464                     .float -0.30950001, 1.225595  , 1.077682  , 1.066005
D:8003E464                     .float -0.0845    , 0.68099999, 0.64469999, 1.1204081
D:8003E464                     .float  1.1927    , 1.1308    ,-0.1364    , 1.021999
D:8003E464                     .float  0.5905    , 1.153587  , 1.226897  , 1.2252491
D:8003E464                     .float -0.2534    , 0.57560003, 0.3856    , 1.0405
D:8003E464                     .float  1.0405    , 1.0585999 ,-0.1265    , 0.6081
D:8003E464                     .float  0.71200001, 1.222     , 1.0       , 1.111666
D:8003E464                     .float -0.4637    , 1.3971    ,-0.49270001, 1.1752
D:8003E464                     .float  1.0116    , 1.1762    ,-0.2976    ,-0.1049
D:8003E464                     .float -0.49649999, 1.2345999 , 0.86470801, 1.077117
D:8003E464                     .float -0.1151    , 0.7353    , 0.57309997, 1.0759
D:8003E464                     .float  1.0       , 1.1308    ,-0.189     , 0.99910003
D:8003E464                     .float  0.2396    , 1.2269    , 1.2039    , 1.1698999
D:8003E464                     .float -0.2534    ,-0.0647    , 0.30070001, 1.0470001
D:8003E464                     .float  0.92699999, 1.0124    ,-0.1265    , 0.61260003
D:8003E464                     .float  0.76700002, 1.2108999 , 1.0       , 1.096216
D:8003E464                     .float -0.51429999, 1.0894001 ,-0.082099997, 1.1003
D:8003E464                     .float  1.0316    , 1.0278    ,-0.53280002,-0.13060001
D:8003E464                     .float -0.25999999, 1.080464  , 1.0       , 1.019003
D:8003E464                     .float -0.1969    , 0.45930001, 0.64469999, 0.96219999
D:8003E464                     .float  1.0       , 1.0895    ,-0.32690001, 1.1438
D:8003E464                     .float  0.46720001, 1.1339    , 1.1339    , 1.0436
D:8003E464                     .float -0.29879999, 0.0       , 0.41429999, 0.96219999
D:8003E464                     .float  1.0       , 0.95630002,-0.17640001, 0.39500001
D:8003E464                     .float  0.86699998, 1.0972    , 0.94625998, 1.0529979
D:8003E464                     .float  0.02      , 0.56910002,-0.25299999, 1.1205291
D:8003E464                     .float  0.999475  , 1.072994  ,-0.0823    ,-0.3784
D:8003E464                     .float -0.38249999, 1.077682  , 1.0       , 1.066239
D:8003E464                     .float  0.02      ,-0.1909    , 0.90700001, 1.049657
D:8003E464                     .float  0.999475  , 1.072994  , 0.0       , 0.60549998
D:8003E464                     .float  0.47510001, 1.1236    , 1.1236    , 1.1236
D:8003E464                     .float -0.0942    , 0.077600002, 0.5248    , 1.0403
D:8003E464                     .float  0.95950001, 0.98580003, 0.0       , 0.20550001
D:8003E464                     .float  0.8951    , 1.1519721 , 0.92378497, 1.0316401
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0836    ,-0.66259998, 0.14210001, 0.95139998
D:8003E464                     .float  1.090098  , 0.92760003, 0.1141    ,-1.1931
D:8003E464                     .float -0.25400001, 0.98102301, 0.83667898, 0.88798702
D:8003E464                     .float  0.1481    ,-0.15360001, 1.1461999 , 0.91399997
D:8003E464                     .float  1.0       , 0.94489998, 0.0       ,-0.53250003
D:8003E464                     .float  0.3563    , 1.0727    , 1.0526    , 1.0228
D:8003E464                     .float -0.0942    ,-0.6857    , 1.1224999 , 0.95959997
D:8003E464                     .float  0.92860001, 0.88690001, 0.079999998,-0.7396
D:8003E464                     .float  0.963     , 1.1032    , 0.875673  , 0.97771698
D:8003E464                     .float -0.29030001, 1.0714999 ,-0.3504    , 1.125893
D:8003E464                     .float  1.127159  , 1.177758  , 0.0       ,-0.079999998
D:8003E464                     .float -0.373     , 1.099718  , 1.0       , 1.0947551
D:8003E464                     .float  0.0       , 0.78799999, 0.64469999, 1.0
D:8003E464                     .float  1.0       , 1.0963    ,-0.074699998, 1.5436
D:8003E464                     .float  0.1979    , 1.1497999 , 1.1835999 , 1.0791
D:8003E464                     .float -0.090300001,-0.1085    , 0.68959999, 1.024099
D:8003E464                     .float  1.0       , 0.98965299, 0.0       , 0.63230002
D:8003E464                     .float  0.7913    , 1.1081001 , 0.93440002, 1.0779999
D:8003E464                     .float -0.13699999, 0.286001  ,-0.32229999, 1.142894
D:8003E464                     .float  0.89638299, 1.15      ,-0.16680001,-0.1365
D:8003E464                     .float -0.43650001, 1.1452    , 1.0       , 1.061306
D:8003E464                     .float  0.1376    , 0.0       , 0.71600002, 1.05312
D:8003E464                     .float  1.0       , 1.0687751 ,-0.074699998, 0.9393
D:8003E464                     .float  0.2658    , 1.1815    , 1.1216    , 1.0822999
D:8003E464                     .float -0.103     ,-0.2269    , 0.5722    , 0.99080002
D:8003E464                     .float  1.02      , 1.0034    , 0.0       , 0.1373
D:8003E464                     .float  0.79430002, 1.1813999 , 0.86186302, 1.0998
D:8003E464                     .float  0.12      , 0.40000001, 0.039999999, 1.022947
D:8003E464                     .float  0.92226201, 1.004824  , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0429    , 0.75889999, 1.2895    , 0.94440001
D:8003E464                     .float  1.0       , 1.0551    , 0.0       , 0.546
D:8003E464                     .float  0.79729998, 1.1483001 , 1.1267999 , 1.1388
D:8003E464                     .float  0.065099999,-0.54320002, 1.1224999 , 0.93949997
D:8003E464                     .float  0.92699999, 0.93040001, 0.1265    , 0.36359999
D:8003E464                     .float  1.079     , 1.1109999 , 1.0       , 1.1166
D:8003E464                     .float  0.0836    ,-0.66259998, 0.14210001, 0.95139998
D:8003E464                     .float  1.090098  , 0.92760003, 0.1141    ,-1.1931
D:8003E464                     .float -0.25400001, 0.98102301, 0.83667898, 0.88798702
D:8003E464                     .float  0.1481    ,-0.15360001, 1.1461999 , 0.91399997
D:8003E464                     .float  1.0       , 0.94489998, 0.0       ,-0.53250003
D:8003E464                     .float  0.3563    , 1.0727    , 1.0526    , 1.0228
D:8003E464                     .float -0.0942    ,-0.6857    , 1.1224999 , 0.95959997
D:8003E464                     .float  0.92860001, 0.88690001, 0.079999998,-0.7396
D:8003E464                     .float  0.963     , 1.1032    , 0.875673  , 0.97771698
D:8003E464                     .float -0.29030001, 1.0714999 ,-0.3504    , 1.125893
D:8003E464                     .float  1.127159  , 1.177758  , 0.0       ,-0.079999998
D:8003E464                     .float -0.373     , 1.099718  , 1.0       , 1.0947551
D:8003E464                     .float  0.0       , 0.78799999, 0.64469999, 1.0
D:8003E464                     .float  1.0       , 1.0963    ,-0.074699998, 1.5436
D:8003E464                     .float  0.1979    , 1.1497999 , 1.1835999 , 1.0791
D:8003E464                     .float -0.090300001,-0.1085    , 0.68959999, 1.024099
D:8003E464                     .float  1.0       , 0.98965299, 0.0       , 0.63230002
D:8003E464                     .float  0.7913    , 1.1081001 , 0.93440002, 1.0779999
D:8003E464                     .float  0.0836    ,-0.66259998, 0.14210001, 0.95139998
D:8003E464                     .float  1.090098  , 0.92760003, 0.1141    ,-1.1931
D:8003E464                     .float -0.25400001, 0.98102301, 0.83667898, 0.88798702
D:8003E464                     .float  0.1481    ,-0.15360001, 1.1461999 , 0.91399997
D:8003E464                     .float  1.0       , 0.94489998, 0.0       ,-0.53250003
D:8003E464                     .float  0.3563    , 1.0727    , 1.0526    , 1.0228
D:8003E464                     .float -0.0942    ,-0.6857    , 1.1224999 , 0.95959997
D:8003E464                     .float  0.92860001, 0.88690001, 0.079999998,-0.7396
D:8003E464                     .float  0.963     , 1.1032    , 0.875673  , 0.97771698
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0       , 0.0       , 0.0       , 1.0
D:8003E464                     .float  1.0       , 1.0       , 0.0       , 0.0
D:8003E464                     .float  0.0       , 1.0       , 1.0       , 1.0
D:8003E464                     .float  0.0       , 0.0       , 0.0
D:8003F430     dword_D_8003F430:.word 0x320028          # DATA XREF: D:stru_D_8003F80Co
D:8003F434                     .word 0x2300120
D:8003F438                     .word 0x4100032
D:8003F43C                     .word 0x280130
D:8003F440                     .word 0x340420
D:8003F444     dword_D_8003F444:.word 0x4200011         # DATA XREF: D:stru_D_8003F81Co
D:8003F448                     .word 0x180120
D:8003F44C                     .word 0x240018
D:8003F450                     .word 0x1200410
D:8003F454                     .word 0x2200031
D:8003F458     dword_D_8003F458:.word 0x4300022         # DATA XREF: D:8003F82Co
D:8003F45C                     .word 0x210032
D:8003F460                     .word 0x4200024
D:8003F464                     .word 0x120031
D:8003F468                     .word 0x8100022
D:8003F46C     dword_D_8003F46C:.word 0x310810          # DATA XREF: D:8003F83Co
D:8003F470                     .word 0x4100410
D:8003F474                     .word 0x310230
D:8003F478                     .word 0x4100810
D:8003F47C                     .word 0x310210
D:8003F480     dword_D_8003F480:.word 0x8200011         # DATA XREF: D:8003F84Co
D:8003F484                     .word 0x140032
D:8003F488                     .word 0x2300130
D:8003F48C                     .word 0x4100018
D:8003F490                     .word 0x110430
D:8003F494     dword_D_8003F494:.word 0x1100220         # DATA XREF: D:8003F85Co
D:8003F498                     .word 0x2200810
D:8003F49C                     .word 0x4200014
D:8003F4A0                     .word 0x220031
D:8003F4A4                     .word 0x4200028
D:8003F4A8     dword_D_8003F4A8:.word 0x140430          # DATA XREF: D:8003F86Co
D:8003F4AC                     .word 0x1200018
D:8003F4B0                     .word 0x310810
D:8003F4B4                     .word 0x4200120
D:8003F4B8                     .word 0x120018
D:8003F4BC     dword_D_8003F4BC:.word 0x120038          # DATA XREF: D:8003F89Co
D:8003F4C0                     .word 0x2300830
D:8003F4C4                     .word 0x8100022
D:8003F4C8                     .word 0x180024
D:8003F4CC                     .word 0x2300110
D:8003F4D0     dword_D_8003F4D0:.word 0x280032          # DATA XREF: D:8003F95Co
D:8003F4D4                     .word 0x8100021
D:8003F4D8                     .word 0x120120
D:8003F4DC                     .word 0x320021
D:8003F4E0                     .word 0x8200034
D:8003F4E4     dword_D_8003F4E4:.word 0x380210          # DATA XREF: D:8003FB6Co
D:8003F4E8                     .word 0x140024
D:8003F4EC                     .word 0x8100420
D:8003F4F0                     .word 0x110120
D:8003F4F4                     .word 0x1300014
D:8003F4F8     dword_D_8003F4F8:.word 0x380012          # DATA XREF: D:8003FB7Co
D:8003F4FC                     .word 0x2200018
D:8003F500                     .word 0x2200014
D:8003F504                     .word 0x210110
D:8003F508                     .word 0x380120
D:8003F50C     dword_D_8003F50C:.word 0x2300210         # DATA XREF: D:8003FB8Co
D:8003F510                     .word 0x280220
D:8003F514                     .word 0x180014
D:8003F518                     .word 0x110110
D:8003F51C                     .word 0x4200012
D:8003F520     dword_D_8003F520:.word 0x120038          # DATA XREF: D:8003FB9Co
D:8003F524                     .word 0x2200810
D:8003F528                     .word 0x2100820
D:8003F52C                     .word 0x140120
D:8003F530                     .word 0x210430
D:8003F534     dword_D_8003F534:.word 0x240110          # DATA XREF: D:8003FBACo
D:8003F538                     .word 0x210012
D:8003F53C                     .word 0x240230
D:8003F540                     .word 0x210830
D:8003F544                     .word 0x110820
D:8003F548     dword_D_8003F548:.word 0x8200014         # DATA XREF: D:8003FBBCo
D:8003F54C                     .word 0x2200410
D:8003F550                     .word 0x220031
D:8003F554                     .word 0x280110
D:8003F558                     .word 0x1100011
D:8003F55C     dword_D_8003F55C:.word 0x180420          # DATA XREF: D:8003FBCCo
D:8003F560                     .word 0x110220
D:8003F564                     .word 0x8300034
D:8003F568                     .word 0x110810
D:8003F56C                     .word 0x340810
D:8003F570     dword_D_8003F570:.word 0x240031, 0x110018, 0x120120, 0x380028, 0x4300021
D:8003F570                                              # DATA XREF: D:8003FBDCo
D:8003F584     dword_D_8003F584:.word 0x4200410, 0x380220, 0x1300022, 0x1100028, 0x2200024
D:8003F584                                              # DATA XREF: D:8003FBECo
D:8003F598     dword_D_8003F598:.word 0x340034, 0x1200230, 0x2100011, 0x2300018, 0x140110
D:8003F598                                              # DATA XREF: D:8003FBFCo
D:8003F5AC     dword_D_8003F5AC:.word 0x2100830, 0x340210, 0x310220, 0x1300034, 0x8200014
D:8003F5AC                                              # DATA XREF: D:8003FC0Co
D:8003F5C0     dword_D_8003F5C0:.word 0x320021, 0x8200034, 0x110014, 0x2100014, 0x180420
D:8003F5C0                                              # DATA XREF: D:8003FC1Co
D:8003F5D4     dword_D_8003F5D4:.word 0x4200420, 0x140021, 0x1300012, 0x4200022, 0x210820
D:8003F5D4                                              # DATA XREF: D:8003FC2Co
D:8003F5E8     dword_D_8003F5E8:.word 0x2100014, 0x110230, 0x1200014, 0x2200032, 0x8200028
D:8003F5E8                                              # DATA XREF: D:8003FC3Co
D:8003F5FC     dword_D_8003F5FC:.word 0x140210, 0x8300110, 0x4100410, 0x8100012, 0x180230
D:8003F5FC                                              # DATA XREF: D:8003FC4Co
D:8003F610     dword_D_8003F610:.word 0x240410, 0x1200011, 0x140210, 0x2100018, 0x2100038
D:8003F610                                              # DATA XREF: D:8003FC5Co
D:8003F624     dword_D_8003F624:.word 0x4200014, 0x8300120, 0x180012, 0x8100022, 0x8200012
D:8003F624                                              # DATA XREF: D:8003FC6Co
D:8003F638     dword_D_8003F638:.word 0x380220, 0x4100420, 0x280420, 0x1100018, 0x220110
D:8003F638                                              # DATA XREF: D:8003FC7Co
D:8003F64C     dword_D_8003F64C:.word 0x140210          # DATA XREF: D:8003FC8Co
D:8003F650                     .word 0x1200031
D:8003F654                     .word 0x4200038
D:8003F658                     .word 0x2200038
D:8003F65C                     .word 0x1300022
D:8003F660     dword_D_8003F660:.word 0x8300031         # DATA XREF: D:8003FC9Co
D:8003F664                     .word 0x4200110
D:8003F668                     .word 0x8100420
D:8003F66C                     .word 0x2200021
D:8003F670                     .word 0x310220
D:8003F674                     .word dword_stack_80304030
D:8003F678                     .word dword_stack_80304030
D:8003F67C     dword_D_8003F67C:.word 0x8200008         # DATA XREF: D:8003FA2Co
D:8003F680                     .word 0x1100032
D:8003F684                     .word 0x8200014
D:8003F688                     .word 0x240034
D:8003F68C                     .word 0x8300024
D:8003F690     dword_D_8003F690:.word 0x2100420         # DATA XREF: D:8003FA3Co
D:8003F694                     .word 0x2000800
D:8003F698                     .word 0x4000012
D:8003F69C                     .word 0x220230
D:8003F6A0                     .word 0x1300022
D:8003F6A4     dword_D_8003F6A4:.word 0x8300001, 0x2100810, 0x8000110, 0x8000034, 0x4300032
D:8003F6A4                                              # DATA XREF: D:8003FA4Co
D:8003F6B8     dword_D_8003F6B8:.word 0x4100810, 0x1000034, 0x1200210, 0x2000400, 0x8000014
D:8003F6B8                                              # DATA XREF: D:8003FA5Co
D:8003F6CC     dword_D_8003F6CC:.word 0x1100820, 0x4000400, 0x140220, 0x220810, 0x4100012
D:8003F6CC                                              # DATA XREF: D:8003FA6Co
D:8003F6E0     dword_D_8003F6E0:.word 0x4200024, 0x8300014, 0x2000410, 0x240800, 0x4100120
D:8003F6E0                                              # DATA XREF: D:8003FA7Co
D:8003F6F4     dword_D_8003F6F4:.word 0x8100004, 0x20008, 0x4200810, 0x20100, 0x2100110
D:8003F6F4                                              # DATA XREF: D:8003FA8Co
D:8003F708     dword_D_8003F708:.word 0x4300410, 0x240200, 0x120034, 0x1000400, 0x140110
D:8003F708                                              # DATA XREF: D:8003FA9Co
D:8003F71C     dword_D_8003F71C:.word 0x120220, 0x8000130, 0x1000032, 0x320410, 0x2100012
D:8003F71C                                              # DATA XREF: D:8003FAACo
D:8003F730     dword_D_8003F730:.word 0x240022, 0x40001, 0x20130, 0x10830, 0x120220
D:8003F730                                              # DATA XREF: D:8003FABCo
D:8003F744     dword_D_8003F744:.word 0x320034, 0x220012, 0x1100230, 0x1200200, 0x320420
D:8003F744                                              # DATA XREF: D:8003FACCo
D:8003F758     dword_D_8003F758:.word 0x340002, 0x140004, 0x40034, 0x8300004, 0x8100820
D:8003F758                                              # DATA XREF: D:8003FADCo
D:8003F76C     dword_D_8003F76C:.word 0x2300230, 0x4300230, 0x10430, 0x4300420, 0x20008
D:8003F76C                                              # DATA XREF: D:8003FAECo
D:8003F780     dword_D_8003F780:.word 0x2200830, 0x1200830, 0x320230, 0x4300004, 0x1300230
D:8003F780                                              # DATA XREF: D:8003FAFCo
D:8003F794     dword_D_8003F794:.word 0x140120, 0x120110, 0x1300830, 0x4200210, 0x1200022
D:8003F794                                              # DATA XREF: D:8003FB0Co
D:8003F7A8     dword_D_8003F7A8:.word 0x220130, 0x10002, 0x2100024, 0x2300034, 0x8200001
D:8003F7A8                                              # DATA XREF: D:8003FB1Co
D:8003F7BC     dword_D_8003F7BC:.word 0x8000100, 0x2200410, 0x8200022, 0x2200001, 0x80430
D:8003F7BC                                              # DATA XREF: D:8003FB2Co
D:8003F7D0     dword_D_8003F7D0:.word 0x1300430, 0x8200430, 0x80810, 0x1300220, 0x4000024
D:8003F7D0                                              # DATA XREF: D:8003FB3Co
D:8003F7E4     dword_D_8003F7E4:.word 0x1200032, 0x4200210, 0x4100120, 0x80100, 0x1100830
D:8003F7E4                                              # DATA XREF: D:8003FB4Co
D:8003F7F8     dword_D_8003F7F8:.word 0x4000200, 0x80100  # DATA XREF: D:8003FB5Co
D:8003F800                     .word 0x4200220
D:8003F804     dword_D_8003F804:.word 0x8200002         # DATA XREF: sub_CODE_7F092774+4r
D:8003F808     dword_D_8003F808:.word 0x2000004         # DATA XREF: sub_CODE_7F091A78+4r
D:8003F808                                              # sub_CODE_7F091B64+4r
D:8003F808                                              # sub_CODE_7F092438+4r
D:8003F80C     stru_D_8003F80C:struct_15 <1, 0xA, 0, 0, dword_D_8003F430, 0, 0x31>
D:8003F80C                                              # DATA XREF: sub_CODE_7F09177C+20o
D:8003F80C                                              # sub_CODE_7F09177C:loc_CODE_7F0917D8r
D:8003F80C                                              # sub_CODE_7F09177C+74r
D:8003F81C     stru_D_8003F81C:struct_15 <2, 0xA, 0, 0, dword_D_8003F444, 0xB0000000, 6>
D:8003F81C                                              # DATA XREF: sub_CODE_7F0926C0+40o
D:8003F82C                     struct_15 <3, 0xA, 0, 0, dword_D_8003F458, 0xB0010000, 2>
D:8003F83C                     struct_15 <4, 0xA, 0, 0, dword_D_8003F46C, 0, 0x16>
D:8003F84C                     struct_15 <5, 0xA, 0, 0, dword_D_8003F480, 0, 0x16>
D:8003F85C                     struct_15 <6, 0xA, 0, 0, dword_D_8003F494, 0, 0x34>
D:8003F86C                     struct_15 <7, 0xA, 0, 0, dword_D_8003F4A8, 0xB0370000, 0x66>
D:8003F87C                     struct_15 <8, 0, 0, 0, 0, 0, 0x16>
D:8003F88C                     struct_15 <9, 0, 0, 0, 0, 0, 0x16>
D:8003F89C                     struct_15 <0xA, 0xA, 0, 0, dword_D_8003F4BC, 0xB0040000, 0x62>
D:8003F8AC                     struct_15 <0xB, 0, 0, 0, 0, 0xB0060000, 0x66>
D:8003F8BC                     struct_15 <0xC, 0, 0, 0, 0, 0xB0070000, 0x26>
D:8003F8CC                     struct_15 <0xD, 0, 0, 0, 0, 0, 0x12>
D:8003F8DC                     struct_15 <0xE, 0, 0, 0, 0, 0xB0080000, 2>
D:8003F8EC                     struct_15 <0xF, 0, 0, 0, 0, 0xB0380000, 0x66>
D:8003F8FC                     struct_15 <0x10, 0, 0, 0, 0, 0, 0x16>
D:8003F90C                     struct_15 <0x11, 0, 0, 0, 0, 0xB00A0000, 0x12>
D:8003F91C                     struct_15 <0x12, 0, 0, 0, 0, 0xB00B0000, 0x12>
D:8003F92C                     struct_15 <0x13, 0, 0, 0, 0, 0xB00C0000, 0x12>
D:8003F93C                     struct_15 <0x14, 0, 0, 0, 0, 0xB00D0000, 0x12>
D:8003F94C                     struct_15 <0x15, 0, 0, 0, 0, 0xB00E0000, 0x12>
D:8003F95C                     struct_15 <0x16, 0xA, 0, 0, dword_D_8003F4D0, 0, 4>
D:8003F96C                     struct_15 <0x17, 0, 0, 0, 0, 0xB0430000, 0x64>
D:8003F97C                     struct_15 <0x18, 0, 0, 0, 0, 0xB0400000, 0x66>
D:8003F98C                     struct_15 <0x19, 0, 0, 0, 0, 0, 0x20>
D:8003F99C                     struct_15 <0x1A, 0, 0, 0, 0, 0xB0410000, 0x72>
D:8003F9AC                     struct_15 <0x1B, 0, 0, 0, 0, 0xB0420000, 0x72>
D:8003F9BC                     struct_15 <0x1C, 0, 0, 0, 0, 0xB0390000, 1>
D:8003F9CC                     struct_15 <0x1D, 0, 0, 0, 0, 0xB03A0000, 0x12>
D:8003F9DC                     struct_15 <0x1E, 0, 0, 0, 0, 0xB03B0000, 0x12>
D:8003F9EC                     struct_15 <0x1F, 0, 0, 0, 0, 0xB03C0000, 0x12>
D:8003F9FC                     struct_15 <0x20, 0, 0, 0, 0, 0xB03D0000, 0x12>
D:8003FA0C                     struct_15 <0x21, 0, 0, 0, 0, 0xB03E0000, 0x12>
D:8003FA1C                     struct_15 <0x22, 0, 0, 0, 0, 0xB03F0000, 0x12>
D:8003FA2C                     struct_15 <0x23, 0xA, 0, 0, dword_D_8003F67C, 0, 0x11>
D:8003FA3C                     struct_15 <0x24, 0xA, 0, 0, dword_D_8003F690, 0, 0x11>
D:8003FA4C                     struct_15 <0x25, 0xA, 0, 0, dword_D_8003F6A4, 0, 0x11>
D:8003FA5C                     struct_15 <0x26, 0xA, 0, 0, dword_D_8003F6B8, 0, 0x11>
D:8003FA6C                     struct_15 <0x27, 0xA, 0, 0, dword_D_8003F6CC, 0, 0x11>
D:8003FA7C                     struct_15 <0x28, 0xA, 0, 0, dword_D_8003F6E0, 0, 0x11>
D:8003FA8C                     struct_15 <0x29, 0xA, 0, 0, dword_D_8003F6F4, 0, 0x11>
D:8003FA9C                     struct_15 <0x2A, 0xA, 0, 0, dword_D_8003F708, 0, 0x11>
D:8003FAAC                     struct_15 <0x2B, 0xA, 0, 0, dword_D_8003F71C, 0, 0x11>
D:8003FABC                     struct_15 <0x2C, 0xA, 0, 0, dword_D_8003F730, 0, 0x11>
D:8003FACC                     struct_15 <0x2D, 0xA, 0, 0, dword_D_8003F744, 0, 0x11>
D:8003FADC                     struct_15 <0x2E, 0xA, 0, 0, dword_D_8003F758, 0, 0x11>
D:8003FAEC                     struct_15 <0x2F, 0xA, 0, 0, dword_D_8003F76C, 0, 0x11>
D:8003FAFC                     struct_15 <0x30, 0xA, 0, 0, dword_D_8003F780, 0, 0x11>
D:8003FB0C                     struct_15 <0x31, 0xA, 0, 0, dword_D_8003F794, 0, 0x11>
D:8003FB1C                     struct_15 <0x32, 0xA, 0, 0, dword_D_8003F7A8, 0, 0x11>
D:8003FB2C                     struct_15 <0x33, 0xA, 0, 0, dword_D_8003F7BC, 0, 0x11>
D:8003FB3C                     struct_15 <0x34, 0xA, 0, 0, dword_D_8003F7D0, 0, 0x11>
D:8003FB4C                     struct_15 <0x35, 0xA, 0, 0, dword_D_8003F7E4, 0, 0x11>
D:8003FB5C                     struct_15 <0x36, 0xA, 0, 0, dword_D_8003F7F8, 0, 0x11>
D:8003FB6C                     struct_15 <0x37, 0xA, 0, 0, dword_D_8003F4E4, 0, 0x11>
D:8003FB7C                     struct_15 <0x38, 0xA, 0, 0, dword_D_8003F4F8, 0, 0x11>
D:8003FB8C                     struct_15 <0x39, 0xA, 0, 0, dword_D_8003F50C, 0, 0x11>
D:8003FB9C                     struct_15 <0x3A, 0xA, 0, 0, dword_D_8003F520, 0, 0x11>
D:8003FBAC                     struct_15 <0x3B, 0xA, 0, 0, dword_D_8003F534, 0, 0x11>
D:8003FBBC                     struct_15 <0x3C, 0xA, 0, 0, dword_D_8003F548, 0, 0x11>
D:8003FBCC                     struct_15 <0x3D, 0xA, 0, 0, dword_D_8003F55C, 0, 0x11>
D:8003FBDC                     struct_15 <0x3E, 0xA, 0, 0, dword_D_8003F570, 0, 0x11>
D:8003FBEC                     struct_15 <0x3F, 0xA, 0, 0, dword_D_8003F584, 0, 0x11>
D:8003FBFC                     struct_15 <0x40, 0xA, 0, 0, dword_D_8003F598, 0, 0x11>
D:8003FC0C                     struct_15 <0x41, 0xA, 0, 0, dword_D_8003F5AC, 0, 0x11>
D:8003FC1C                     struct_15 <0x42, 0xA, 0, 0, dword_D_8003F5C0, 0, 0x11>
D:8003FC2C                     struct_15 <0x43, 0xA, 0, 0, dword_D_8003F5D4, 0, 0x11>
D:8003FC3C                     struct_15 <0x44, 0xA, 0, 0, dword_D_8003F5E8, 0, 0x11>
D:8003FC4C                     struct_15 <0x45, 0xA, 0, 0, dword_D_8003F5FC, 0, 0x11>
D:8003FC5C                     struct_15 <0x46, 0xA, 0, 0, dword_D_8003F610, 0, 0x11>
D:8003FC6C                     struct_15 <0x47, 0xA, 0, 0, dword_D_8003F624, 0, 0x11>
D:8003FC7C                     struct_15 <0x48, 0xA, 0, 0, dword_D_8003F638, 0, 0x11>
D:8003FC8C                     struct_15 <0x49, 0xA, 0, 0, dword_D_8003F64C, 0, 0x11>
D:8003FC9C                     struct_15 <0x4A, 0xA, 0, 0, dword_D_8003F660, 0, 0x11>
D:8003FCAC                     struct_15 <0>
D:8003FCBC                     .word 0
*/

/* rodata
D:80055870     aUsetupsevbunkerz:.ascii "UsetupsevbunkerZ"<0><0><0><0>
D:80055870                                              # DATA XREF: D:setup_text_pointerso
D:80055884     aUsetupsiloz:   .ascii "UsetupsiloZ"<0>  # DATA XREF: D:setup_text_pointerso
D:80055890     aUsetupsevbunkerz_0:.ascii "UsetupsevbunkerZ"<0><0><0><0>
D:80055890                                              # DATA XREF: D:setup_text_pointerso
D:800558A4     aUsetupstatuez: .ascii "UsetupstatueZ"<0><0><0>
D:800558A4                                              # DATA XREF: D:setup_text_pointerso
D:800558B4     aUsetupcontrolz:.ascii "UsetupcontrolZ"<0><0>
D:800558B4                                              # DATA XREF: D:setup_text_pointerso
D:800558C4     aUsetuparchz:   .ascii "UsetuparchZ"<0>  # DATA XREF: D:setup_text_pointerso
D:800558D0     aUsetuptraz:    .ascii "UsetuptraZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:800558DC     aUsetupdestz:   .ascii "UsetupdestZ"<0>  # DATA XREF: D:setup_text_pointerso
D:800558E8     aUsetupsevbz:   .ascii "UsetupsevbZ"<0>  # DATA XREF: D:setup_text_pointerso
D:800558F4     aUsetupaztz:    .ascii "UsetupaztZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055900     aUsetuppetez:   .ascii "UsetuppeteZ"<0>  # DATA XREF: D:setup_text_pointerso
D:8005590C     aUsetupdepoz:   .ascii "UsetupdepoZ"<0>  # DATA XREF: D:setup_text_pointerso
D:80055918     aUsetuprefz:    .ascii "UsetuprefZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055924     aUsetupcrypz:   .ascii "UsetupcrypZ"<0>  # DATA XREF: D:setup_text_pointerso
D:80055930     aUsetupdamz:    .ascii "UsetupdamZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:8005593C     aUsetuparkz:    .ascii "UsetuparkZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055948     aUsetuprunz:    .ascii "UsetuprunZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055954     aUsetupsevxz:   .ascii "UsetupsevxZ"<0>  # DATA XREF: D:setup_text_pointerso
D:80055960     aUsetupjunz:    .ascii "UsetupjunZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:8005596C     aUsetupdishz:   .ascii "UsetupdishZ"<0>  # DATA XREF: D:setup_text_pointerso
D:80055978     aUsetupcavez:   .ascii "UsetupcaveZ"<0>  # DATA XREF: D:setup_text_pointerso
D:80055984     aUsetupcatz:    .ascii "UsetupcatZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055990     aUsetupcradz:   .ascii "UsetupcradZ"<0>  # DATA XREF: D:setup_text_pointerso
D:8005599C     aUsetupshoz:    .ascii "UsetupshoZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:800559A8     aUsetupsevxbz:  .ascii "UsetupsevxbZ"<0><0><0><0>
D:800559A8                                              # DATA XREF: D:setup_text_pointerso
D:800559B8     aUsetupeldz:    .ascii "UsetupeldZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:800559C4     aUsetupimpz:    .ascii "UsetupimpZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:800559D0     aUsetupashz:    .ascii "UsetupashZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:800559DC     aUsetupluez:    .ascii "UsetuplueZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:800559E8     aUsetupamez:    .ascii "UsetupameZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:800559F4     aUsetupritz:    .ascii "UsetupritZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055A00     aUsetupoatz:    .ascii "UsetupoatZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055A0C     aUsetupearz:    .ascii "UsetupearZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055A18     aUsetupleez:    .ascii "UsetupleeZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055A24     aUsetuplipz:    .ascii "UsetuplipZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055A30     aUsetuplenz:    .ascii "UsetuplenZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055A3C     aUsetupwaxz:    .ascii "UsetupwaxZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055A48     aUsetuppamz:    .ascii "UsetuppamZ"<0><0>  # DATA XREF: D:setup_text_pointerso
D:80055A54                     .align 4
D:80055A60     aPalarm1z:      .ascii "Palarm1Z"<0><0><0><0>  # DATA XREF: D:PitemZ_entrieso
D:80055A6C     aPalarm2z:      .ascii "Palarm2Z"<0><0><0><0>  # DATA XREF: D:8003A234o
D:80055A78     aPexplosionbitz:.ascii "PexplosionbitZ"<0><0>  # DATA XREF: D:8003A240o
D:80055A88     aPammo_crate1z: .ascii "Pammo_crate1Z"<0><0><0>  # DATA XREF: D:8003A24Co
D:80055A98     aPammo_crate2z: .ascii "Pammo_crate2Z"<0><0><0>  # DATA XREF: D:8003A258o
D:80055AA8     aPammo_crate3z: .ascii "Pammo_crate3Z"<0><0><0>  # DATA XREF: D:8003A264o
D:80055AB8     aPammo_crate4z: .ascii "Pammo_crate4Z"<0><0><0>  # DATA XREF: D:8003A270o
D:80055AC8     aPammo_crate5z: .ascii "Pammo_crate5Z"<0><0><0>  # DATA XREF: D:8003A27Co
D:80055AD8     aPbin1z:        .ascii "Pbin1Z"<0><0>    # DATA XREF: D:8003A288o
D:80055AE0     aPblotter1z:    .ascii "Pblotter1Z"<0><0>  # DATA XREF: D:8003A294o
D:80055AEC     aPbook1z:       .ascii "Pbook1Z"<0>      # DATA XREF: D:8003A2A0o
D:80055AF4     aPbookshelf1z:  .ascii "Pbookshelf1Z"<0><0><0><0>  # DATA XREF: D:8003A2ACo
D:80055B04     aPbridge_console1az:.ascii "Pbridge_console1aZ"<0><0>
D:80055B04                                              # DATA XREF: D:8003A2B8o
D:80055B18     aPbridge_console1bz:.ascii "Pbridge_console1bZ"<0><0>
D:80055B18                                              # DATA XREF: D:8003A2C4o
D:80055B2C     aPbridge_console2az:.ascii "Pbridge_console2aZ"<0><0>
D:80055B2C                                              # DATA XREF: D:8003A2D0o
D:80055B40     aPbridge_console2bz:.ascii "Pbridge_console2bZ"<0><0>
D:80055B40                                              # DATA XREF: D:8003A2DCo
D:80055B54     aPbridge_console3az:.ascii "Pbridge_console3aZ"<0><0>
D:80055B54                                              # DATA XREF: D:8003A2E8o
D:80055B68     aPbridge_console3bz:.ascii "Pbridge_console3bZ"<0><0>
D:80055B68                                              # DATA XREF: D:8003A2F4o
D:80055B7C     aPcard_box1z:   .ascii "Pcard_box1Z"<0>  # DATA XREF: D:8003A300o
D:80055B88     aPcard_box2z:   .ascii "Pcard_box2Z"<0>  # DATA XREF: D:8003A30Co
D:80055B94     aPcard_box3z:   .ascii "Pcard_box3Z"<0>  # DATA XREF: D:8003A318o
D:80055BA0     aPcard_box4_lgz:.ascii "Pcard_box4_lgZ"<0><0>  # DATA XREF: D:8003A324o
D:80055BB0     aPcard_box5_lgz:.ascii "Pcard_box5_lgZ"<0><0>  # DATA XREF: D:8003A330o
D:80055BC0     aPcard_box6_lgz:.ascii "Pcard_box6_lgZ"<0><0>  # DATA XREF: D:8003A33Co
D:80055BD0     aPcctvz:        .ascii "PcctvZ"<0><0>    # DATA XREF: D:8003A348o
D:80055BD8     aPconsole1z:    .ascii "Pconsole1Z"<0><0>  # DATA XREF: D:8003A354o
D:80055BE4     aPconsole2z:    .ascii "Pconsole2Z"<0><0>  # DATA XREF: D:8003A360o
D:80055BF0     aPconsole3z:    .ascii "Pconsole3Z"<0><0>  # DATA XREF: D:8003A36Co
D:80055BFC     aPconsole_sevaz:.ascii "Pconsole_sevaZ"<0><0>  # DATA XREF: D:8003A378o
D:80055C0C     aPconsole_sevbz:.ascii "Pconsole_sevbZ"<0><0>  # DATA XREF: D:8003A384o
D:80055C1C     aPconsole_sevcz:.ascii "Pconsole_sevcZ"<0><0>  # DATA XREF: D:8003A390o
D:80055C2C     aPconsole_sevdz:.ascii "Pconsole_sevdZ"<0><0>  # DATA XREF: D:8003A39Co
D:80055C3C     aPconsole_sev2az:.ascii "Pconsole_sev2aZ"<0>  # DATA XREF: D:8003A3A8o
D:80055C4C     aPconsole_sev2bz:.ascii "Pconsole_sev2bZ"<0>  # DATA XREF: D:8003A3B4o
D:80055C5C     aPconsole_sev2cz:.ascii "Pconsole_sev2cZ"<0>  # DATA XREF: D:8003A3C0o
D:80055C6C     aPconsole_sev2dz:.ascii "Pconsole_sev2dZ"<0>  # DATA XREF: D:8003A3CCo
D:80055C7C     aPconsole_sev_geaz:.ascii "Pconsole_sev_GEaZ"<0><0><0>
D:80055C7C                                              # DATA XREF: D:8003A3D8o
D:80055C90     aPconsole_sev_gebz:.ascii "Pconsole_sev_GEbZ"<0><0><0>
D:80055C90                                              # DATA XREF: D:8003A3E4o
D:80055CA4     aPdesk1z:       .ascii "Pdesk1Z"<0>      # DATA XREF: D:8003A3F0o
D:80055CAC     aPdesk2z:       .ascii "Pdesk2Z"<0>      # DATA XREF: D:8003A3FCo
D:80055CB4     aPdesk_lamp2z:  .ascii "Pdesk_lamp2Z"<0>  # DATA XREF: D:8003A408o
D:80055CC1                     .byte 0, 0, 0
D:80055CC4     aPdisc_readerz: .ascii "Pdisc_readerZ"<0>  # DATA XREF: D:8003A414o
D:80055CD2                     .half 0
D:80055CD4     aPdisk_drive1z: .ascii "Pdisk_drive1Z"<0>  # DATA XREF: D:8003A420o
D:80055CE2                     .half 0
D:80055CE4     aPfiling_cabinet1z:.ascii "Pfiling_cabinet1Z"<0>  # DATA XREF: D:8003A42Co
D:80055CF6                     .half 0
D:80055CF8     aPjerry_can1z:  .ascii "Pjerry_can1Z"<0>  # DATA XREF: D:8003A438o
D:80055D05                     .byte 0, 0, 0
D:80055D08     aPkeyboard1z:   .ascii "Pkeyboard1Z"<0>  # DATA XREF: D:8003A444o
D:80055D14     aPkit_units1z:  .ascii "Pkit_units1Z"<0>  # DATA XREF: D:8003A450o
D:80055D21                     .byte 0, 0, 0
D:80055D24     aPletter_tray1z:.ascii "Pletter_tray1Z"<0><0>  # DATA XREF: D:8003A45Co
D:80055D34     aPmainframe1z:  .ascii "Pmainframe1Z"<0>  # DATA XREF: D:8003A468o
D:80055D41                     .byte 0, 0, 0
D:80055D44     aPmainframe2z:  .ascii "Pmainframe2Z"<0>  # DATA XREF: D:8003A474o
D:80055D51                     .byte 0, 0, 0
D:80055D54     aPmetal_chair1z:.ascii "Pmetal_chair1Z"<0><0>  # DATA XREF: D:8003A480o
D:80055D64     aPmetal_crate1z:.ascii "Pmetal_crate1Z"<0><0>  # DATA XREF: D:8003A48Co
D:80055D74     aPmetal_crate2z:.ascii "Pmetal_crate2Z"<0><0>  # DATA XREF: D:8003A498o
D:80055D84     aPmetal_crate3z:.ascii "Pmetal_crate3Z"<0><0>  # DATA XREF: D:8003A4A4o
D:80055D94     aPmetal_crate4z:.ascii "Pmetal_crate4Z"<0><0>  # DATA XREF: D:8003A4B0o
D:80055DA4     aPmissile_rackz:.ascii "Pmissile_rackZ"<0><0>  # DATA XREF: D:8003A4BCo
D:80055DB4     aPmissile_rack2z:.ascii "Pmissile_rack2Z"<0>  # DATA XREF: D:8003A4C8o
D:80055DC4     aPoil_drum1z:   .ascii "Poil_drum1Z"<0>  # DATA XREF: D:8003A4D4o
D:80055DD0     aPoil_drum2z:   .ascii "Poil_drum2Z"<0>  # DATA XREF: D:8003A4E0o
D:80055DDC     aPoil_drum3z:   .ascii "Poil_drum3Z"<0>  # DATA XREF: D:8003A4ECo
D:80055DE8     aPoil_drum5z:   .ascii "Poil_drum5Z"<0>  # DATA XREF: D:8003A4F8o
D:80055DF4     aPoil_drum6z:   .ascii "Poil_drum6Z"<0>  # DATA XREF: D:8003A504o
D:80055E00     aPoil_drum7z:   .ascii "Poil_drum7Z"<0>  # DATA XREF: D:8003A510o
D:80055E0C     aPpadlockz:     .ascii "PpadlockZ"<0>    # DATA XREF: D:8003A51Co
D:80055E16                     .half 0
D:80055E18     aPphone1z:      .ascii "Pphone1Z"<0>     # DATA XREF: D:8003A528o
D:80055E21                     .byte 0, 0, 0
D:80055E24     aPradio_unit1z: .ascii "Pradio_unit1Z"<0>  # DATA XREF: D:8003A534o
D:80055E32                     .half 0
D:80055E34     aPradio_unit2z: .ascii "Pradio_unit2Z"<0>  # DATA XREF: D:8003A540o
D:80055E42                     .half 0
D:80055E44     aPradio_unit3z: .ascii "Pradio_unit3Z"<0>  # DATA XREF: D:8003A54Co
D:80055E52                     .half 0
D:80055E54     aPradio_unit4z: .ascii "Pradio_unit4Z"<0>  # DATA XREF: D:8003A558o
D:80055E62                     .half 0
D:80055E64     aPsat1_reflectz:.ascii "Psat1_reflectZ"<0><0>  # DATA XREF: D:8003A564o
D:80055E74     aPsatdishz:     .ascii "PsatdishZ"<0>    # DATA XREF: D:8003A570o
D:80055E7E                     .half 0
D:80055E80     aPsatboxz:      .ascii "PsatboxZ"<0>     # DATA XREF: D:8003A57Co
D:80055E89                     .byte 0, 0, 0
D:80055E8C     aPstool1z:      .ascii "Pstool1Z"<0>     # DATA XREF: D:8003A588o
D:80055E95                     .byte 0, 0, 0
D:80055E98     aPswivel_chair1z:.ascii "Pswivel_chair1Z"<0>  # DATA XREF: D:8003A594o
D:80055EA8     aPtorpedo_rackz:.ascii "Ptorpedo_rackZ"<0><0>  # DATA XREF: D:8003A5A0o
D:80055EB8     aPtv1z:         .ascii "Ptv1Z"<0>        # DATA XREF: D:8003A5ACo
D:80055EBE                     .half 0
D:80055EC0     aPtv_holderz:   .ascii "Ptv_holderZ"<0>  # DATA XREF: D:8003A5B8o
D:80055ECC     aPtvscreenz:    .ascii "PtvscreenZ"<0><0>  # DATA XREF: D:8003A5C4o
D:80055ED8     aPtv4screenz:   .ascii "Ptv4screenZ"<0>  # DATA XREF: D:8003A5D0o
D:80055EE4     aPwood_lg_crate1z:.ascii "Pwood_lg_crate1Z"<0>  # DATA XREF: D:8003A5DCo
D:80055EF5                     .byte 0, 0, 0
D:80055EF8     aPwood_lg_crate2z:.ascii "Pwood_lg_crate2Z"<0>  # DATA XREF: D:8003A5E8o
D:80055F09                     .byte 0, 0, 0
D:80055F0C     aPwood_md_crate3z:.ascii "Pwood_md_crate3Z"<0>  # DATA XREF: D:8003A5F4o
D:80055F1D                     .byte 0, 0, 0
D:80055F20     aPwood_sm_crate4z:.ascii "Pwood_sm_crate4Z"<0>  # DATA XREF: D:8003A600o
D:80055F31                     .byte 0, 0, 0
D:80055F34     aPwood_sm_crate5z:.ascii "Pwood_sm_crate5Z"<0>  # DATA XREF: D:8003A60Co
D:80055F45                     .byte 0, 0, 0
D:80055F48     aPwood_sm_crate6z:.ascii "Pwood_sm_crate6Z"<0>  # DATA XREF: D:8003A618o
D:80055F59                     .byte 0, 0, 0
D:80055F5C     aPwooden_table1z:.ascii "Pwooden_table1Z"<0>  # DATA XREF: D:8003A624o
D:80055F6C     aPswipe_card2z: .ascii "Pswipe_card2Z"<0>  # DATA XREF: D:8003A630o
D:80055F7A                     .half 0
D:80055F7C     aPborg_cratez:  .ascii "Pborg_crateZ"<0>  # DATA XREF: D:8003A63Co
D:80055F89                     .byte 0, 0, 0
D:80055F8C     aPboxes4x4z:    .ascii "Pboxes4x4Z"<0><0>  # DATA XREF: D:8003A648o
D:80055F98     aPboxes3x4z:    .ascii "Pboxes3x4Z"<0><0>  # DATA XREF: D:8003A654o
D:80055FA4     aPboxes2x4z:    .ascii "Pboxes2x4Z"<0><0>  # DATA XREF: D:8003A660o
D:80055FB0     aPsec_panelz:   .ascii "Psec_panelZ"<0>  # DATA XREF: D:8003A66Co
D:80055FBC     aPicbm_nosez:   .ascii "PICBM_noseZ"<0>  # DATA XREF: D:8003A678o
D:80055FC8     aPicbmz:        .ascii "PICBMZ"<0><0>    # DATA XREF: D:8003A684o
D:80055FD0     aPtuning_console1z:.ascii "Ptuning_console1Z"<0>  # DATA XREF: D:8003A690o
D:80055FE2                     .half 0
D:80055FE4     aPdesk_arecibo1z:.ascii "Pdesk_arecibo1Z"<0>  # DATA XREF: D:8003A69Co
D:80055FF4     aPlocker3z:     .ascii "Plocker3Z"<0>    # DATA XREF: D:8003A6A8o
D:80055FFE                     .half 0
D:80056000     aPlocker4z:     .ascii "Plocker4Z"<0>    # DATA XREF: D:8003A6B4o
D:8005600A                     .half 0
D:8005600C     aProofgunz:     .ascii "ProofgunZ"<0>    # DATA XREF: D:8003A6C0o
D:80056016                     .half 0
D:80056018     aPdest_enginez: .ascii "Pdest_engineZ"<0>  # DATA XREF: D:8003A6CCo
D:80056026                     .half 0
D:80056028     aPdest_exocetz: .ascii "Pdest_exocetZ"<0>  # DATA XREF: D:8003A6D8o
D:80056036                     .half 0
D:80056038     aPdest_gunz:    .ascii "Pdest_gunZ"<0>   # DATA XREF: D:8003A6E4o
D:80056043                     .byte 0
D:80056044     aPdest_harpoonz:.ascii "Pdest_harpoonZ"<0>  # DATA XREF: D:8003A6F0o
D:80056053                     .byte 0
D:80056054     aPdest_seawolfz:.ascii "Pdest_seawolfZ"<0>  # DATA XREF: D:8003A6FCo
D:80056063                     .byte 0
D:80056064     aPwindowz:      .ascii "PwindowZ"<0>     # DATA XREF: D:8003A708o
D:8005606D                     .byte 0, 0, 0
D:80056070     aPwindow_lib_lg1z:.ascii "Pwindow_lib_lg1Z"<0>  # DATA XREF: D:8003A714o
D:80056081                     .byte 0, 0, 0
D:80056084     aPwindow_lib_sm1z:.ascii "Pwindow_lib_sm1Z"<0>  # DATA XREF: D:8003A720o
D:80056095                     .byte 0, 0, 0
D:80056098     aPwindow_cor11z:.ascii "Pwindow_cor11Z"<0>  # DATA XREF: D:8003A72Co
D:800560A7                     .byte 0
D:800560A8     aPjungle3_treez:.ascii "Pjungle3_treeZ"<0>  # DATA XREF: D:8003A738o
D:800560B7                     .byte 0
D:800560B8     aPpalmz:        .ascii "PpalmZ"<0>       # DATA XREF: D:8003A744o
D:800560BF                     .byte 0
D:800560C0     aPpalmtreez:    .ascii "PpalmtreeZ"<0>   # DATA XREF: D:8003A750o
D:800560CB                     .byte 0
D:800560CC     aPplant2bz:     .ascii "Pplant2bZ"<0>    # DATA XREF: D:8003A75Co
D:800560D6                     .half 0
D:800560D8     aPlabbenchz:    .ascii "PlabbenchZ"<0>   # DATA XREF: D:8003A768o
D:800560E3                     .byte 0
D:800560E4     aPgasbarrelz:   .ascii "PgasbarrelZ"<0>  # DATA XREF: D:8003A774o
D:800560F0     aPgasbarrelsz:  .ascii "PgasbarrelsZ"<0>  # DATA XREF: D:8003A780o
D:800560FD                     .byte 0, 0, 0
D:80056100     aPbodyarmourz:  .ascii "PbodyarmourZ"<0>  # DATA XREF: D:8003A78Co
D:8005610D                     .byte 0, 0, 0
D:80056110     aPbodyarmourvestz:.ascii "PbodyarmourvestZ"<0>  # DATA XREF: D:8003A798o
D:80056121                     .byte 0, 0, 0
D:80056124     aPgastankz:     .ascii "PgastankZ"<0>    # DATA XREF: D:8003A7A4o
D:8005612E                     .half 0
D:80056130     aPglassware1z:  .ascii "Pglassware1Z"<0>  # DATA XREF: D:8003A7B0o
D:8005613D                     .byte 0, 0, 0
D:80056140     aPhatchboltz:   .ascii "PhatchboltZ"<0>  # DATA XREF: D:8003A7BCo
D:8005614C     aPbrakeunitz:   .ascii "PbrakeunitZ"<0>  # DATA XREF: D:8003A7C8o
D:80056158     aPak47magz:     .ascii "Pak47magZ"<0>    # DATA XREF: D:8003A7D4o
D:80056162                     .half 0
D:80056164     aPm16magz:      .ascii "Pm16magZ"<0>     # DATA XREF: D:8003A7E0o
D:8005616D                     .byte 0, 0, 0
D:80056170     aPmp5kmagz:     .ascii "Pmp5kmagZ"<0>    # DATA XREF: D:8003A7ECo
D:8005617A                     .half 0
D:8005617C     aPskorpionmagz: .ascii "PskorpionmagZ"<0>  # DATA XREF: D:8003A7F8o
D:8005618A                     .half 0
D:8005618C     aPspectremagz:  .ascii "PspectremagZ"<0>  # DATA XREF: D:8003A804o
D:80056199                     .byte 0, 0, 0
D:8005619C     aPuzimagz:      .ascii "PuzimagZ"<0>     # DATA XREF: D:8003A810o
D:800561A5                     .byte 0, 0, 0
D:800561A8     aPsilencerz:    .ascii "PsilencerZ"<0>   # DATA XREF: D:8003A81Co
D:800561B3                     .byte 0
D:800561B4     aPchrextinguisherz:.ascii "PchrextinguisherZ"<0>  # DATA XREF: D:8003A828o
D:800561C6                     .half 0
D:800561C8     aPboxcartridgesz:.ascii "PboxcartridgesZ"<0>  # DATA XREF: D:8003A834o
D:800561D8     aPfnp90magz:    .ascii "Pfnp90magZ"<0>   # DATA XREF: D:8003A840o
D:800561E3                     .byte 0
D:800561E4     aPgoldenshellsz:.ascii "PgoldenshellsZ"<0>  # DATA XREF: D:8003A84Co
D:800561F3                     .byte 0
D:800561F4     aPmagnumshellsz:.ascii "PmagnumshellsZ"<0>  # DATA XREF: D:8003A858o
D:80056203                     .byte 0
D:80056204     aPwppkmagz:     .ascii "PwppkmagZ"<0>    # DATA XREF: D:8003A864o
D:8005620E                     .half 0
D:80056210     aPtt33magz:     .ascii "Ptt33magZ"<0>    # DATA XREF: D:8003A870o
D:8005621A                     .half 0
D:8005621C     aPsev_doorz:    .ascii "Psev_doorZ"<0>   # DATA XREF: D:8003A87Co
D:80056227                     .byte 0
D:80056228     aPsev_door3z:   .ascii "Psev_door3Z"<0>  # DATA XREF: D:8003A888o
D:80056234     aPsev_door3_windz:.ascii "Psev_door3_windZ"<0>  # DATA XREF: D:8003A894o
D:80056245                     .byte 0, 0, 0
D:80056248     aPsev_door4_windz:.ascii "Psev_door4_windZ"<0>  # DATA XREF: D:8003A8A0o
D:80056259                     .byte 0, 0, 0
D:8005625C     aPsev_trislidez:.ascii "Psev_trislideZ"<0>  # DATA XREF: D:8003A8ACo
D:8005626B                     .byte 0
D:8005626C     aPsev_door_v1z: .ascii "Psev_door_v1Z"<0>  # DATA XREF: D:8003A8B8o
D:8005627A                     .half 0
D:8005627C     aPsteel_door1z: .ascii "Psteel_door1Z"<0>  # DATA XREF: D:8003A8C4o
D:8005628A                     .half 0
D:8005628C     aPsteel_door2z: .ascii "Psteel_door2Z"<0>  # DATA XREF: D:8003A8D0o
D:8005629A                     .half 0
D:8005629C     aPsteel_door3z: .ascii "Psteel_door3Z"<0>  # DATA XREF: D:8003A8DCo
D:800562AA                     .half 0
D:800562AC     aPsilo_lift_doorz:.ascii "Psilo_lift_doorZ"<0>  # DATA XREF: D:8003A8E8o
D:800562BD                     .byte 0, 0, 0
D:800562C0     aPsteel_door2bz:.ascii "Psteel_door2bZ"<0>  # DATA XREF: D:8003A8F4o
D:800562CF                     .byte 0
D:800562D0     aPdoor_roller1z:.ascii "Pdoor_roller1Z"<0>  # DATA XREF: D:8003A900o
D:800562DF                     .byte 0
D:800562E0     aPdoor_roller2z:.ascii "Pdoor_roller2Z"<0>  # DATA XREF: D:8003A90Co
D:800562EF                     .byte 0
D:800562F0     aPdoor_roller3z:.ascii "Pdoor_roller3Z"<0>  # DATA XREF: D:8003A918o
D:800562FF                     .byte 0
D:80056300     aPdoor_roller4z:.ascii "Pdoor_roller4Z"<0>  # DATA XREF: D:8003A924o
D:8005630F                     .byte 0
D:80056310     aPdoor_st_arec1z:.ascii "Pdoor_st_arec1Z"<0>  # DATA XREF: D:8003A930o
D:80056320     aPdoor_st_arec2z:.ascii "Pdoor_st_arec2Z"<0>  # DATA XREF: D:8003A93Co
D:80056330     aPdoor_dest1z:  .ascii "Pdoor_dest1Z"<0>  # DATA XREF: D:8003A948o
D:8005633D                     .byte 0, 0, 0
D:80056340     aPdoor_dest2z:  .ascii "Pdoor_dest2Z"<0>  # DATA XREF: D:8003A954o
D:8005634D                     .byte 0, 0, 0
D:80056350     aPgas_plant_sw_do1z:.ascii "Pgas_plant_sw_do1Z"<0>  # DATA XREF: D:8003A960o
D:80056363                     .byte 0
D:80056364     aPgas_plant_sw2_do1z:.ascii "Pgas_plant_sw2_do1Z"<0>  # DATA XREF: D:8003A96Co
D:80056378     aPgas_plant_sw3_do1z:.ascii "Pgas_plant_sw3_do1Z"<0>  # DATA XREF: D:8003A978o
D:8005638C     aPgas_plant_sw4_do1z:.ascii "Pgas_plant_sw4_do1Z"<0>  # DATA XREF: D:8003A984o
D:800563A0     aPgas_plant_met1_do1z:.ascii "Pgas_plant_met1_do1Z"<0>
D:800563A0                                              # DATA XREF: D:8003A990o
D:800563B5                     .byte 0, 0, 0
D:800563B8     aPgas_plant_wc_cub1z:.ascii "Pgas_plant_wc_cub1Z"<0>  # DATA XREF: D:8003A99Co
D:800563CC     aPgasplant_clear_doorz:.ascii "Pgasplant_clear_doorZ"<0>
D:800563CC                                              # DATA XREF: D:8003A9A8o
D:800563E2                     .half 0
D:800563E4     aPtrain_doorz:  .ascii "Ptrain_doorZ"<0>  # DATA XREF: D:8003A9B4o
D:800563F1                     .byte 0, 0, 0
D:800563F4     aPtrain_door2z: .ascii "Ptrain_door2Z"<0>  # DATA XREF: D:8003A9C0o
D:80056402                     .half 0
D:80056404     aPtrain_door3z: .ascii "Ptrain_door3Z"<0>  # DATA XREF: D:8003A9CCo
D:80056412                     .half 0
D:80056414     aPdoor_eyelidz: .ascii "Pdoor_eyelidZ"<0>  # DATA XREF: D:8003A9D8o
D:80056422                     .half 0
D:80056424     aPdoor_irisz:   .ascii "Pdoor_irisZ"<0>  # DATA XREF: D:8003A9E4o
D:80056430     aPsevdoorwoodz: .ascii "PsevdoorwoodZ"<0>  # DATA XREF: D:8003A9F0o
D:8005643E                     .half 0
D:80056440     aPsevdoorwindz: .ascii "PsevdoorwindZ"<0>  # DATA XREF: D:8003A9FCo
D:8005644E                     .half 0
D:80056450     aPsevdoornowindz:.ascii "PsevdoornowindZ"<0>  # DATA XREF: D:8003AA08o
D:80056460     aPsevdoormetslidez:.ascii "PsevdoormetslideZ"<0>  # DATA XREF: D:8003AA14o
D:80056472                     .half 0
D:80056474     aPcryptdoor1az: .ascii "Pcryptdoor1aZ"<0>  # DATA XREF: D:8003AA20o
D:80056482                     .half 0
D:80056484     aPcryptdoor1bz: .ascii "Pcryptdoor1bZ"<0>  # DATA XREF: D:8003AA2Co
D:80056492                     .half 0
D:80056494     aPcryptdoor2az: .ascii "Pcryptdoor2aZ"<0>  # DATA XREF: D:8003AA38o
D:800564A2                     .half 0
D:800564A4     aPcryptdoor2bz: .ascii "Pcryptdoor2bZ"<0>  # DATA XREF: D:8003AA44o
D:800564B2                     .half 0
D:800564B4     aPcryptdoor3z:  .ascii "Pcryptdoor3Z"<0>  # DATA XREF: D:8003AA50o
D:800564C1                     .byte 0, 0, 0
D:800564C4     aPcryptdoor4z:  .ascii "Pcryptdoor4Z"<0>  # DATA XREF: D:8003AA5Co
D:800564D1                     .byte 0, 0, 0
D:800564D4     aPvertdoorz:    .ascii "PvertdoorZ"<0>   # DATA XREF: D:8003AA68o
D:800564DF                     .byte 0
D:800564E0     aPhatchdoorz:   .ascii "PhatchdoorZ"<0>  # DATA XREF: D:8003AA74o
D:800564EC     aPdamgatedoorz: .ascii "PdamgatedoorZ"<0>  # DATA XREF: D:8003AA80o
D:800564FA                     .half 0
D:800564FC     aPdamtundoorz:  .ascii "PdamtundoorZ"<0>  # DATA XREF: D:8003AA8Co
D:80056509                     .byte 0, 0, 0
D:8005650C     aPdamchaindoorz:.ascii "PdamchaindoorZ"<0>  # DATA XREF: D:8003AA98o
D:8005651B                     .byte 0
D:8005651C     aPsilotopdoorz: .ascii "PsilotopdoorZ"<0>  # DATA XREF: D:8003AAA4o
D:8005652A                     .half 0
D:8005652C     aPdoorprison1z: .ascii "Pdoorprison1Z"<0>  # DATA XREF: D:8003AAB0o
D:8005653A                     .half 0
D:8005653C     aPdoorstatgatez:.ascii "PdoorstatgateZ"<0>  # DATA XREF: D:8003AABCo
D:8005654B                     .byte 0
D:8005654C     aPchrkalashz:   .ascii "PchrkalashZ"<0>  # DATA XREF: D:8003AAC8o
D:80056558     aPchrgrenadelaunchz:.ascii "PchrgrenadelaunchZ"<0>  # DATA XREF: D:8003AAD4o
D:8005656B                     .byte 0
D:8005656C     aPchrknifez:    .ascii "PchrknifeZ"<0>   # DATA XREF: D:8003AAE0o
D:80056577                     .byte 0
D:80056578     aPchrlaserz:    .ascii "PchrlaserZ"<0>   # DATA XREF: D:8003AAECo
D:80056583                     .byte 0
D:80056584     aPchrm16z:      .ascii "Pchrm16Z"<0>     # DATA XREF: D:8003AAF8o
D:8005658D                     .byte 0, 0, 0
D:80056590     aPchrmp5kz:     .ascii "Pchrmp5kZ"<0>    # DATA XREF: D:8003AB04o
D:8005659A                     .half 0
D:8005659C     aPchrrugerz:    .ascii "PchrrugerZ"<0>   # DATA XREF: D:8003AB10o
D:800565A7                     .byte 0
D:800565A8     aPchrwppkz:     .ascii "PchrwppkZ"<0>    # DATA XREF: D:PchrwppkZ_entryo
D:800565B2                     .half 0
D:800565B4     aPchrshotgunz:  .ascii "PchrshotgunZ"<0>  # DATA XREF: D:8003AB28o
D:800565C1                     .byte 0, 0, 0
D:800565C4     aPchrskorpionz: .ascii "PchrskorpionZ"<0>  # DATA XREF: D:8003AB34o
D:800565D2                     .half 0
D:800565D4     aPchrspectrez:  .ascii "PchrspectreZ"<0>  # DATA XREF: D:8003AB40o
D:800565E1                     .byte 0, 0, 0
D:800565E4     aPchruziz:      .ascii "PchruziZ"<0>     # DATA XREF: D:8003AB4Co
D:800565ED                     .byte 0, 0, 0
D:800565F0     aPchrgrenadez:  .ascii "PchrgrenadeZ"<0>  # DATA XREF: D:8003AB58o
D:800565FD                     .byte 0, 0, 0
D:80056600     aPchrfnp90z:    .ascii "Pchrfnp90Z"<0>   # DATA XREF: D:8003AB64o
D:8005660B                     .byte 0
D:8005660C     aPchrbriefcasez:.ascii "PchrbriefcaseZ"<0>  # DATA XREF: D:8003AB70o
D:8005661B                     .byte 0
D:8005661C     aPchrremoteminez:.ascii "PchrremotemineZ"<0>  # DATA XREF: D:8003AB7Co
D:8005662C     aPchrproximityminez:.ascii "PchrproximitymineZ"<0>  # DATA XREF: D:8003AB88o
D:8005663F                     .byte 0
D:80056640     aPchrtimedminez:.ascii "PchrtimedmineZ"<0>  # DATA XREF: D:8003AB94o
D:8005664F                     .byte 0
D:80056650     aPchrrocketz:   .ascii "PchrrocketZ"<0>  # DATA XREF: D:8003ABA0o
D:8005665C     aPchrgrenaderoundz:.ascii "PchrgrenaderoundZ"<0>  # DATA XREF: D:8003ABACo
D:8005666E                     .half 0
D:80056670     aPchrwppksilz:  .ascii "PchrwppksilZ"<0>  # DATA XREF: D:8003ABB8o
D:8005667D                     .byte 0, 0, 0
D:80056680     aPchrtt33z:     .ascii "Pchrtt33Z"<0>    # DATA XREF: D:8003ABC4o
D:8005668A                     .half 0
D:8005668C     aPchrmp5ksilz:  .ascii "Pchrmp5ksilZ"<0>  # DATA XREF: D:8003ABD0o
D:80056699                     .byte 0, 0, 0
D:8005669C     aPchrautoshotz: .ascii "PchrautoshotZ"<0>  # DATA XREF: D:8003ABDCo
D:800566AA                     .half 0
D:800566AC     aPchrgoldenz:   .ascii "PchrgoldenZ"<0>  # DATA XREF: D:8003ABE8o
D:800566B8     aPchrthrowknifez:.ascii "PchrthrowknifeZ"<0>  # DATA XREF: D:8003ABF4o
D:800566C8     aPchrsniperriflez:.ascii "PchrsniperrifleZ"<0>  # DATA XREF: D:8003AC00o
D:800566D9                     .byte 0, 0, 0
D:800566DC     aPchrrocketlaunchz:.ascii "PchrrocketlaunchZ"<0>  # DATA XREF: D:8003AC0Co
D:800566EE                     .half 0
D:800566F0     aPhatfurryz:    .ascii "PhatfurryZ"<0>   # DATA XREF: D:8003AC18o
D:800566FB                     .byte 0
D:800566FC     aPhatfurrybrownz:.ascii "PhatfurrybrownZ"<0>  # DATA XREF: D:8003AC24o
D:8005670C     aPhatfurryblackz:.ascii "PhatfurryblackZ"<0>  # DATA XREF: D:8003AC30o
D:8005671C     aPhattbirdz:    .ascii "PhattbirdZ"<0>   # DATA XREF: D:8003AC3Co
D:80056727                     .byte 0
D:80056728     aPhattbirdbrownz:.ascii "PhattbirdbrownZ"<0>  # DATA XREF: D:8003AC48o
D:80056738     aPhathelmetz:   .ascii "PhathelmetZ"<0>  # DATA XREF: D:8003AC54o
D:80056744     aPhathelmetgreyz:.ascii "PhathelmetgreyZ"<0>  # DATA XREF: D:8003AC60o
D:80056754     aPhatmoonz:     .ascii "PhatmoonZ"<0>    # DATA XREF: D:8003AC6Co
D:8005675E                     .half 0
D:80056760     aPhatberetz:    .ascii "PhatberetZ"<0>   # DATA XREF: D:8003AC78o
D:8005676B                     .byte 0
D:8005676C     aPhatberetbluez:.ascii "PhatberetblueZ"<0>  # DATA XREF: D:8003AC84o
D:8005677B                     .byte 0
D:8005677C     aPhatberetredz: .ascii "PhatberetredZ"<0>  # DATA XREF: D:8003AC90o
D:8005678A                     .half 0
D:8005678C     aPhatpeakedz:   .ascii "PhatpeakedZ"<0>  # DATA XREF: D:8003AC9Co
D:80056798     aPchrwristdartz:.ascii "PchrwristdartZ"<0>  # DATA XREF: D:8003ACA8o
D:800567A7                     .byte 0
D:800567A8     aPchrexplosivepenz:.ascii "PchrexplosivepenZ"<0>  # DATA XREF: D:8003ACB4o
D:800567BA                     .half 0
D:800567BC     aPchrbombcasez: .ascii "PchrbombcaseZ"<0>  # DATA XREF: D:8003ACC0o
D:800567CA                     .half 0
D:800567CC     aPchrflarepistolz:.ascii "PchrflarepistolZ"<0>  # DATA XREF: D:8003ACCCo
D:800567DD                     .byte 0, 0, 0
D:800567E0     aPchrpitongunz: .ascii "PchrpitongunZ"<0>  # DATA XREF: D:8003ACD8o
D:800567EE                     .half 0
D:800567F0     aPchrfingergunz:.ascii "PchrfingergunZ"<0>  # DATA XREF: D:8003ACE4o
D:800567FF                     .byte 0
D:80056800     aPchrsilverwppkz:.ascii "PchrsilverwppkZ"<0>  # DATA XREF: D:8003ACF0o
D:80056810     aPchrgoldwppkz: .ascii "PchrgoldwppkZ"<0>  # DATA XREF: D:8003ACFCo
D:8005681E                     .half 0
D:80056820     aPchrdynamitez: .ascii "PchrdynamiteZ"<0>  # DATA XREF: D:8003AD08o
D:8005682E                     .half 0
D:80056830     aPchrbungeez:   .ascii "PchrbungeeZ"<0>  # DATA XREF: D:8003AD14o
D:8005683C     aPchrdoordecoderz:.ascii "PchrdoordecoderZ"<0>  # DATA XREF: D:8003AD20o
D:8005684D                     .byte 0, 0, 0
D:80056850     aPchrbombdefuserz:.ascii "PchrbombdefuserZ"<0>  # DATA XREF: D:8003AD2Co
D:80056861                     .byte 0, 0, 0
D:80056864     aPchrbugdetectorz:.ascii "PchrbugdetectorZ"<0>  # DATA XREF: D:8003AD38o
D:80056875                     .byte 0, 0, 0
D:80056878     aPchrsafecrackercasez:.ascii "PchrsafecrackercaseZ"<0>
D:80056878                                              # DATA XREF: D:8003AD44o
D:8005688D                     .byte 0, 0, 0
D:80056890     aPchrcameraz:   .ascii "PchrcameraZ"<0>  # DATA XREF: D:8003AD50o
D:8005689C     aPchrlockexploderz:.ascii "PchrlockexploderZ"<0>  # DATA XREF: D:8003AD5Co
D:800568AE                     .half 0
D:800568B0     aPchrdoorexploderz:.ascii "PchrdoorexploderZ"<0>  # DATA XREF: D:8003AD68o
D:800568C2                     .half 0
D:800568C4     aPchrkeyanalysercasez:.ascii "PchrkeyanalysercaseZ"<0>
D:800568C4                                              # DATA XREF: D:8003AD74o
D:800568D9                     .byte 0, 0, 0
D:800568DC     aPchrweaponcasez:.ascii "PchrweaponcaseZ"<0>  # DATA XREF: D:8003AD80o
D:800568EC     aPchrkeyyalez:  .ascii "PchrkeyyaleZ"<0>  # DATA XREF: D:8003AD8Co
D:800568F9                     .byte 0, 0, 0
D:800568FC     aPchrkeyboltz:  .ascii "PchrkeyboltZ"<0>  # DATA XREF: D:8003AD98o
D:80056909                     .byte 0, 0, 0
D:8005690C     aPchrbugz:      .ascii "PchrbugZ"<0>     # DATA XREF: D:8003ADA4o
D:80056915                     .byte 0, 0, 0
D:80056918     aPchrmicrocameraz:.ascii "PchrmicrocameraZ"<0>  # DATA XREF: D:8003ADB0o
D:80056929                     .byte 0, 0, 0
D:8005692C     aPfloppyz:      .ascii "PfloppyZ"<0>     # DATA XREF: D:8003ADBCo
D:80056935                     .byte 0, 0, 0
D:80056938     aPchrgoldeneyekeyz:.ascii "PchrgoldeneyekeyZ"<0>  # DATA XREF: D:8003ADC8o
D:8005694A                     .half 0
D:8005694C     aPchrpolarizedglassesz:.ascii "PchrpolarizedglassesZ"<0>
D:8005694C                                              # DATA XREF: D:8003ADD4o
D:80056962                     .half 0
D:80056964     aPchrcreditcardz:.ascii "PchrcreditcardZ"<0>  # DATA XREF: D:8003ADE0o
D:80056974     aPchrdarkglassesz:.ascii "PchrdarkglassesZ"<0>  # DATA XREF: D:8003ADECo
D:80056985                     .byte 0, 0, 0
D:80056988     aPchrgaskeyringz:.ascii "PchrgaskeyringZ"<0>  # DATA XREF: D:8003ADF8o
D:80056998     aPchrdatathiefz:.ascii "PchrdatathiefZ"<0>  # DATA XREF: D:8003AE04o
D:800569A7                     .byte 0
D:800569A8     aPsafez:        .ascii "PsafeZ"<0>       # DATA XREF: D:8003AE10o
D:800569AF                     .byte 0
D:800569B0     aPbombz:        .ascii "PbombZ"<0>       # DATA XREF: D:8003AE1Co
D:800569B7                     .byte 0
D:800569B8     aPchrplansz:    .ascii "PchrplansZ"<0>   # DATA XREF: D:8003AE28o
D:800569C3                     .byte 0
D:800569C4     aPchrspyfilez:  .ascii "PchrspyfileZ"<0>  # DATA XREF: D:8003AE34o
D:800569D1                     .byte 0, 0, 0
D:800569D4     aPchrblueprintsz:.ascii "PchrblueprintsZ"<0>  # DATA XREF: D:8003AE40o
D:800569E4     aPchrcircuitboardz:.ascii "PchrcircuitboardZ"<0>  # DATA XREF: D:8003AE4Co
D:800569F6                     .half 0
D:800569F8     aPchrmapz:      .ascii "PchrmapZ"<0>     # DATA XREF: D:8003AE58o
D:80056A01                     .byte 0, 0, 0
D:80056A04     aPchrspooltapez:.ascii "PchrspooltapeZ"<0>  # DATA XREF: D:8003AE64o
D:80056A13                     .byte 0
D:80056A14     aPchraudiotapez:.ascii "PchraudiotapeZ"<0>  # DATA XREF: D:8003AE70o
D:80056A23                     .byte 0
D:80056A24     aPchrmicrofilmz:.ascii "PchrmicrofilmZ"<0>  # DATA XREF: D:8003AE7Co
D:80056A33                     .byte 0
D:80056A34     aPchrmicrocodez:.ascii "PchrmicrocodeZ"<0>  # DATA XREF: D:8003AE88o
D:80056A43                     .byte 0
D:80056A44     aPchrlectrez:   .ascii "PchrlectreZ"<0>  # DATA XREF: D:8003AE94o
D:80056A50     aPchrmoneyz:    .ascii "PchrmoneyZ"<0>   # DATA XREF: D:8003AEA0o
D:80056A5B                     .byte 0
D:80056A5C     aPchrgoldbarz:  .ascii "PchrgoldbarZ"<0>  # DATA XREF: D:8003AEACo
D:80056A69                     .byte 0, 0, 0
D:80056A6C     aPchrheroinz:   .ascii "PchrheroinZ"<0>  # DATA XREF: D:8003AEB8o
D:80056A78     aPchrclipboardz:.ascii "PchrclipboardZ"<0>  # DATA XREF: D:8003AEC4o
D:80056A87                     .byte 0
D:80056A88     aPchrdossierredz:.ascii "PchrdossierredZ"<0>  # DATA XREF: D:8003AED0o
D:80056A98     aPchrstafflistz:.ascii "PchrstafflistZ"<0>  # DATA XREF: D:8003AEDCo
D:80056AA7                     .byte 0
D:80056AA8     aPchrdattapez:  .ascii "PchrdattapeZ"<0>  # DATA XREF: D:8003AEE8o
D:80056AB5                     .byte 0, 0, 0
D:80056AB8     aPchrplastiquez:.ascii "PchrplastiqueZ"<0>  # DATA XREF: D:8003AEF4o
D:80056AC7                     .byte 0
D:80056AC8     aPchrblackboxz: .ascii "PchrblackboxZ"<0>  # DATA XREF: D:8003AF00o
D:80056AD6                     .half 0
D:80056AD8     aPchrvideotapez:.ascii "PchrvideotapeZ"<0>  # DATA XREF: D:8003AF0Co
D:80056AE7                     .byte 0
D:80056AE8     aPnintendologoz:.ascii "PnintendologoZ"<0>
D:80056AE8                                              # DATA XREF: D:PnintendologoZ_entryo
D:80056AF7                     .byte 0
D:80056AF8     aPgoldeneyelogoz:.ascii "PgoldeneyelogoZ"<0>
D:80056AF8                                              # DATA XREF: D:PgoldeneyelogoZ_entryo
D:80056B08     aPwalletbondz:  .ascii "PwalletbondZ"<0>  # DATA XREF: D:PwalletbondZ_entryo
D:80056B15                     .byte 0, 0, 0
D:80056B18     aPmiltruckz:    .ascii "PmiltruckZ"<0>   # DATA XREF: D:8003AF3Co
D:80056B23                     .byte 0
D:80056B24     aPjeepz:        .ascii "PjeepZ"<0>       # DATA XREF: D:8003AF48o
D:80056B2B                     .byte 0
D:80056B2C     aParticz:       .ascii "ParticZ"<0>      # DATA XREF: D:8003AF54o
D:80056B34     aPhelicopterz:  .ascii "PhelicopterZ"<0>  # DATA XREF: D:8003AF60o
D:80056B41                     .byte 0, 0, 0
D:80056B44     aPtigerz:       .ascii "PtigerZ"<0>      # DATA XREF: D:8003AF6Co
D:80056B4C     aPmilcopterz:   .ascii "PmilcopterZ"<0>  # DATA XREF: D:8003AF78o
D:80056B58     aPhindz:        .ascii "PhindZ"<0>       # DATA XREF: D:8003AF84o
D:80056B5F                     .byte 0
D:80056B60     aPartictrailerz:.ascii "PartictrailerZ"<0>  # DATA XREF: D:8003AF90o
D:80056B6F                     .byte 0
D:80056B70     aPmotorbikez:   .ascii "PmotorbikeZ"<0>  # DATA XREF: D:8003AF9Co
D:80056B7C     aPtankz:        .ascii "PtankZ"<0>       # DATA XREF: D:8003AFA8o
D:80056B83                     .byte 0
D:80056B84     aPapcz:         .ascii "PapcZ"<0>        # DATA XREF: D:8003AFB4o
D:80056B8A                     .half 0
D:80056B8C     aPspeedboatz:   .ascii "PspeedboatZ"<0>  # DATA XREF: D:8003AFC0o
D:80056B98     aPplanez:       .ascii "PplaneZ"<0>      # DATA XREF: D:8003AFCCo
D:80056BA0     aPgun_runway1z: .ascii "Pgun_runway1Z"<0>  # DATA XREF: D:8003AFD8o
D:80056BAE                     .half 0
D:80056BB0     aPsafedoorz:    .ascii "PsafedoorZ"<0>   # DATA XREF: D:8003AFE4o
D:80056BBB                     .byte 0
D:80056BBC     aPkey_holderz:  .ascii "Pkey_holderZ"<0>  # DATA XREF: D:8003AFF0o
D:80056BC9                     .byte 0, 0, 0
D:80056BCC     aPhatchsevxz:   .ascii "PhatchsevxZ"<0>  # DATA XREF: D:8003AFFCo
D:80056BD8     aPsevdishz:     .ascii "PsevdishZ"<0>    # DATA XREF: D:8003B008o
D:80056BE2                     .half 0
D:80056BE4     aParchsecdoor1z:.ascii "Parchsecdoor1Z"<0>  # DATA XREF: D:8003B014o
D:80056BF3                     .byte 0
D:80056BF4     aParchsecdoor2z:.ascii "Parchsecdoor2Z"<0>  # DATA XREF: D:8003B020o
D:80056C03                     .byte 0
D:80056C04     aPgroundgunz:   .ascii "PgroundgunZ"<0>  # DATA XREF: D:8003B02Co
D:80056C10     aPtrainextdoorz:.ascii "PtrainextdoorZ"<0>  # DATA XREF: D:8003B038o
D:80056C1F                     .byte 0
D:80056C20     aPcarbmwz:      .ascii "PcarbmwZ"<0>     # DATA XREF: D:8003B044o
D:80056C29                     .byte 0, 0, 0
D:80056C2C     aPcarescortz:   .ascii "PcarescortZ"<0>  # DATA XREF: D:8003B050o
D:80056C38     aPcargolfz:     .ascii "PcargolfZ"<0>    # DATA XREF: D:8003B05Co
D:80056C42                     .half 0
D:80056C44     aPcarweirdz:    .ascii "PcarweirdZ"<0>   # DATA XREF: D:8003B068o
D:80056C4F                     .byte 0
D:80056C50     aPcarzilz:      .ascii "PcarzilZ"<0>     # DATA XREF: D:8003B074o
D:80056C59                     .byte 0, 0, 0
D:80056C5C     aPshuttle_door_lz:.ascii "Pshuttle_door_lZ"<0>  # DATA XREF: D:8003B080o
D:80056C6D                     .byte 0, 0, 0
D:80056C70     aPshuttle_door_rz:.ascii "Pshuttle_door_rZ"<0>  # DATA XREF: D:8003B08Co
D:80056C81                     .byte 0, 0, 0
D:80056C84     aPdepot_gate_entryz:.ascii "Pdepot_gate_entryZ"<0>  # DATA XREF: D:8003B098o
D:80056C97                     .byte 0
D:80056C98     aPdepot_door_steelz:.ascii "Pdepot_door_steelZ"<0>  # DATA XREF: D:8003B0A4o
D:80056CAB                     .byte 0
D:80056CAC     aPglassware2z:  .ascii "Pglassware2Z"<0>  # DATA XREF: D:8003B0B0o
D:80056CB9                     .byte 0, 0, 0
D:80056CBC     aPglassware3z:  .ascii "Pglassware3Z"<0>  # DATA XREF: D:8003B0BCo
D:80056CC9                     .byte 0, 0, 0
D:80056CCC     aPglassware4z:  .ascii "Pglassware4Z"<0>  # DATA XREF: D:8003B0C8o
D:80056CD9                     .byte 0, 0, 0
D:80056CDC     aPlandminez:    .ascii "PlandmineZ"<0>   # DATA XREF: D:8003B0D4o
D:80056CE7                     .byte 0
D:80056CE8     aPplant1z:      .ascii "Pplant1Z"<0>     # DATA XREF: D:8003B0E0o
D:80056CF1                     .byte 0, 0, 0
D:80056CF4     aPplant11z:     .ascii "Pplant11Z"<0>    # DATA XREF: D:8003B0ECo
D:80056CFE                     .half 0
D:80056D00     aPplant2z:      .ascii "Pplant2Z"<0>     # DATA XREF: D:8003B0F8o
D:80056D09                     .byte 0, 0, 0
D:80056D0C     aPplant3z:      .ascii "Pplant3Z"<0>     # DATA XREF: D:8003B104o
D:80056D15                     .byte 0, 0, 0
D:80056D18     aPjungle5_treez:.ascii "Pjungle5_treeZ"<0>  # DATA XREF: D:8003B110o
D:80056D27                     .byte 0
D:80056D28     aPlegalpagez:   .ascii "PlegalpageZ"<0>  # DATA XREF: D:PlegalpageZ_entryo
D:80056D34     aPst_pete_room_1iz:.ascii "Pst_pete_room_1iZ"<0>  # DATA XREF: D:8003B128o
D:80056D46                     .half 0
D:80056D48     aPst_pete_room_2iz:.ascii "Pst_pete_room_2iZ"<0>  # DATA XREF: D:8003B134o
D:80056D5A                     .half 0
D:80056D5C     aPst_pete_room_3tz:.ascii "Pst_pete_room_3tZ"<0>  # DATA XREF: D:8003B140o
D:80056D6E                     .half 0
D:80056D70     aPst_pete_room_5cz:.ascii "Pst_pete_room_5cZ"<0>  # DATA XREF: D:8003B14Co
D:80056D82                     .half 0
D:80056D84     aPst_pete_room_6cz:.ascii "Pst_pete_room_6cZ"<0>  # DATA XREF: D:8003B158o
D:80056D96                     .half 0
D:80056D98     aPdoor_rollertrainz:.ascii "Pdoor_rollertrainZ"<0>  # DATA XREF: D:8003B164o
D:80056DAB                     .byte 0
D:80056DAC     aPdoor_winz:    .ascii "Pdoor_winZ"<0>   # DATA XREF: D:8003B170o
D:80056DB7                     .byte 0
D:80056DB8     aPdoor_aztecz:  .ascii "Pdoor_aztecZ"<0>  # DATA XREF: D:8003B17Co
D:80056DC5                     .byte 0, 0, 0
D:80056DC8     aPshuttlez:     .ascii "PshuttleZ"<0>    # DATA XREF: D:8003B188o
D:80056DD2                     .half 0
D:80056DD4     aPdoor_azt_deskz:.ascii "Pdoor_azt_deskZ"<0>  # DATA XREF: D:8003B194o
D:80056DE4     aPdoor_azt_desk_topz:.ascii "Pdoor_azt_desk_topZ"<0>  # DATA XREF: D:8003B1A0o
D:80056DF8     aPdoor_azt_chairz:.ascii "Pdoor_azt_chairZ"<0><0><0><0>
D:80056DF8                                              # DATA XREF: D:8003B1ACo
D:80056E0C     aPdoor_mfz:     .ascii "Pdoor_mfZ"<0>    # DATA XREF: D:8003B1B8o
D:80056E16                     .half 0
D:80056E18     aPflagz:        .ascii "PflagZ"<0>       # DATA XREF: D:8003B1C4o
D:80056E1F                     .byte 0
D:80056E20     aPbarricadez:   .ascii "PbarricadeZ"<0>  # DATA XREF: D:8003B1D0o
D:80056E2C     aPmodemboxz:    .ascii "PmodemboxZ"<0>   # DATA XREF: D:8003B1DCo
D:80056E37                     .byte 0
D:80056E38     aPdoorpanelz:   .ascii "PdoorpanelZ"<0>  # DATA XREF: D:8003B1E8o
D:80056E44     aPdoorconsolez: .ascii "PdoorconsoleZ"<0>  # DATA XREF: D:8003B1F4o
D:80056E52                     .half 0
D:80056E54     aPchrtesttubez: .ascii "PchrtesttubeZ"<0>  # DATA XREF: D:8003B200o
D:80056E62                     .half 0
D:80056E64     aPbollardz:     .ascii "PbollardZ"<0><0><0>  # DATA XREF: D:8003B20Co
D:80056E70     aPnullZ:        .ascii <0><0><0><0><0><0><0><0><0><0><0><0><0><0><0><0>
D:80056E70                                              # DATA XREF: D:PitemZ_entry_endo
D:80056E80     aCcamguardz:    .ascii "CcamguardZ"<0><0>  # DATA XREF: D:c_item_entrieso
D:80056E8C     aCgreyguardz:   .ascii "CgreyguardZ"<0>  # DATA XREF: D:8003DE24o
D:80056E98     aColiveguardz:  .ascii "ColiveguardZ"<0><0><0><0>  # DATA XREF: D:8003DE38o
D:80056EA8     aCrusguardz:    .ascii "CrusguardZ"<0>   # DATA XREF: D:8003DE4Co
D:80056EB3                     .byte 0
D:80056EB4     aCtrevguardz:   .ascii "CtrevguardZ"<0>  # DATA XREF: D:8003DE60o
D:80056EC0     aCdjbondz:      .ascii "CdjbondZ"<0>     # DATA XREF: D:stru_D_8003DE74o
D:80056EC9                     .byte 0, 0, 0
D:80056ECC     aCborisz:       .ascii "CborisZ"<0>      # DATA XREF: D:8003DE88o
D:80056ED4     aCorumovz:      .ascii "CorumovZ"<0>     # DATA XREF: D:8003DE9Co
D:80056EDD                     .byte 0, 0, 0
D:80056EE0     aCtrevelyanz:   .ascii "CtrevelyanZ"<0>  # DATA XREF: D:8003DEB0o
D:80056EEC     aCboilertrevz:  .ascii "CboilertrevZ"<0>  # DATA XREF: D:8003DEC4o
D:80056EF9                     .byte 0, 0, 0
D:80056EFC     aCvalentinz:    .ascii "CvalentinZ"<0>   # DATA XREF: D:8003DED8o
D:80056F07                     .byte 0
D:80056F08     aCxeniaz:       .ascii "CxeniaZ"<0>      # DATA XREF: D:8003DEECo
D:80056F10     aCbaronsamediz: .ascii "CbaronsamediZ"<0>  # DATA XREF: D:8003DF00o
D:80056F1E                     .half 0
D:80056F20     aCjawsz:        .ascii "CjawsZ"<0>       # DATA XREF: D:8003DF14o
D:80056F27                     .byte 0
D:80056F28     aCmaydayz:      .ascii "CmaydayZ"<0>     # DATA XREF: D:8003DF28o
D:80056F31                     .byte 0, 0, 0
D:80056F34     aCoddjobz:      .ascii "CoddjobZ"<0>     # DATA XREF: D:8003DF3Co
D:80056F3D                     .byte 0, 0, 0
D:80056F40     aCnatalyaz:     .ascii "CnatalyaZ"<0>    # DATA XREF: D:8003DF50o
D:80056F4A                     .half 0
D:80056F4C     aCarmourguardz: .ascii "CarmourguardZ"<0>  # DATA XREF: D:8003DF64o
D:80056F5A                     .half 0
D:80056F5C     aCcommguardz:   .ascii "CcommguardZ"<0>  # DATA XREF: D:8003DF78o
D:80056F68     aCgreatguardz:  .ascii "CgreatguardZ"<0>  # DATA XREF: D:8003DF8Co
D:80056F75                     .byte 0, 0, 0
D:80056F78     aCnavyguardz:   .ascii "CnavyguardZ"<0>  # DATA XREF: D:8003DFA0o
D:80056F84     aCsnowguardz:   .ascii "CsnowguardZ"<0>  # DATA XREF: D:8003DFB4o
D:80056F90     aCboilerbondz:  .ascii "CboilerbondZ"<0>  # DATA XREF: D:8003DFC8o
D:80056F9D                     .byte 0, 0, 0
D:80056FA0     aCsuitbondz:    .ascii "CsuitbondZ"<0>   # DATA XREF: D:8003DFDCo
D:80056FAB                     .byte 0
D:80056FAC     aCtimberbondz:  .ascii "CtimberbondZ"<0>  # DATA XREF: D:8003DFF0o
D:80056FB9                     .byte 0, 0, 0
D:80056FBC     aCsnowbondz:    .ascii "CsnowbondZ"<0>   # DATA XREF: D:8003E004o
D:80056FC7                     .byte 0
D:80056FC8     aCbluewomanz:   .ascii "CbluewomanZ"<0>  # DATA XREF: D:8003E018o
D:80056FD4     aCfattechwomanz:.ascii "CfattechwomanZ"<0>  # DATA XREF: D:8003E02Co
D:80056FE3                     .byte 0
D:80056FE4     aCtechwomanz:   .ascii "CtechwomanZ"<0>  # DATA XREF: D:8003E040o
D:80056FF0     aCjeanwomanz:   .ascii "CjeanwomanZ"<0>  # DATA XREF: D:8003E054o
D:80056FFC     aCgreymanz:     .ascii "CgreymanZ"<0>    # DATA XREF: D:8003E068o
D:80057006                     .half 0
D:80057008     aCbluemanz:     .ascii "CbluemanZ"<0>    # DATA XREF: D:8003E07Co
D:80057012                     .half 0
D:80057014     aCredmanz:      .ascii "CredmanZ"<0>     # DATA XREF: D:8003E090o
D:8005701D                     .byte 0, 0, 0
D:80057020     aCcardimanz:    .ascii "CcardimanZ"<0>   # DATA XREF: D:8003E0A4o
D:8005702B                     .byte 0
D:8005702C     aCcheckmanz:    .ascii "CcheckmanZ"<0>   # DATA XREF: D:8003E0B8o
D:80057037                     .byte 0
D:80057038     aCtechmanz:     .ascii "CtechmanZ"<0>    # DATA XREF: D:8003E0CCo
D:80057042                     .half 0
D:80057044     aCpilotz:       .ascii "CpilotZ"<0>      # DATA XREF: D:8003E0E0o
D:8005704C     aCgreatguard2z: .ascii "Cgreatguard2Z"<0>  # DATA XREF: D:8003E0F4o
D:8005705A                     .half 0
D:8005705C     aCbluecamguardz:.ascii "CbluecamguardZ"<0>  # DATA XREF: D:8003E108o
D:8005706B                     .byte 0
D:8005706C     aCmoonguardz:   .ascii "CmoonguardZ"<0>  # DATA XREF: D:8003E11Co
D:80057078     aCmoonfemalez:  .ascii "CmoonfemaleZ"<0>  # DATA XREF: D:8003E130o
D:80057085                     .byte 0, 0, 0
D:80057088     aCsuit_lf_handz_0:.ascii "Csuit_lf_handZ"<0>  # DATA XREF: D:stru_D_8003E144o
D:80057097                     .byte 0
D:80057098     aCheadkarlz:    .ascii "CheadkarlZ"<0>   # DATA XREF: D:8003E158o
D:800570A3                     .byte 0
D:800570A4     aCheadalanz:    .ascii "CheadalanZ"<0>   # DATA XREF: D:8003E16Co
D:800570AF                     .byte 0
D:800570B0     aCheadpetez:    .ascii "CheadpeteZ"<0>   # DATA XREF: D:8003E180o
D:800570BB                     .byte 0
D:800570BC     aCheadmartinz:  .ascii "CheadmartinZ"<0>  # DATA XREF: D:8003E194o
D:800570C9                     .byte 0, 0, 0
D:800570CC     aCheadmarkz:    .ascii "CheadmarkZ"<0>   # DATA XREF: D:8003E1A8o
D:800570D7                     .byte 0
D:800570D8     aCheadduncanz:  .ascii "CheadduncanZ"<0>  # DATA XREF: D:8003E1BCo
D:800570E5                     .byte 0, 0, 0
D:800570E8     aCheadshaunz:   .ascii "CheadshaunZ"<0>  # DATA XREF: D:8003E1D0o
D:800570F4     aCheaddwaynez:  .ascii "CheaddwayneZ"<0>  # DATA XREF: D:8003E1E4o
D:80057101                     .byte 0, 0, 0
D:80057104     aCheadbz:       .ascii "CheadbZ"<0>      # DATA XREF: D:8003E1F8o
D:8005710C     aCheaddavez:    .ascii "CheaddaveZ"<0>   # DATA XREF: D:8003E20Co
D:80057117                     .byte 0
D:80057118     aCheadgrantz:   .ascii "CheadgrantZ"<0>  # DATA XREF: D:8003E220o
D:80057124     aCheaddesz:     .ascii "CheaddesZ"<0>    # DATA XREF: D:8003E234o
D:8005712E                     .half 0
D:80057130     aCheadchrisz:   .ascii "CheadchrisZ"<0>  # DATA XREF: D:8003E248o
D:8005713C     aCheadleez:     .ascii "CheadleeZ"<0>    # DATA XREF: D:8003E25Co
D:80057146                     .half 0
D:80057148     aCheadneilz:    .ascii "CheadneilZ"<0>   # DATA XREF: D:8003E270o
D:80057153                     .byte 0
D:80057154     aCheadjimz:     .ascii "CheadjimZ"<0>    # DATA XREF: D:8003E284o
D:8005715E                     .half 0
D:80057160     aCheadrobinz:   .ascii "CheadrobinZ"<0>  # DATA XREF: D:8003E298o
D:8005716C     aCheadstevehz:  .ascii "CheadstevehZ"<0>  # DATA XREF: D:8003E2ACo
D:80057179                     .byte 0, 0, 0
D:8005717C     aCheadbalaclavaz:.ascii "CheadbalaclavaZ"<0>  # DATA XREF: D:8003E2C0o
D:8005718C     aCheadbikez:    .ascii "CheadbikeZ"<0>   # DATA XREF: D:8003E2D4o
D:80057197                     .byte 0
D:80057198     aCheadgrahamz:  .ascii "CheadgrahamZ"<0>  # DATA XREF: D:8003E2E8o
D:800571A5                     .byte 0, 0, 0
D:800571A8     aCheadsteveez:  .ascii "CheadsteveeZ"<0>  # DATA XREF: D:8003E2FCo
D:800571B5                     .byte 0, 0, 0
D:800571B8     aCheadjoelz:    .ascii "CheadjoelZ"<0>   # DATA XREF: D:8003E310o
D:800571C3                     .byte 0
D:800571C4     aCheadscottz:   .ascii "CheadscottZ"<0>  # DATA XREF: D:8003E324o
D:800571D0     aCheadjoez:     .ascii "CheadjoeZ"<0>    # DATA XREF: D:8003E338o
D:800571DA                     .half 0
D:800571DC     aCheadkenz:     .ascii "CheadkenZ"<0>    # DATA XREF: D:8003E34Co
D:800571E6                     .half 0
D:800571E8     aCheadjoe2z:    .ascii "Cheadjoe2Z"<0>   # DATA XREF: D:8003E360o
D:800571F3                     .byte 0
D:800571F4     aCheadmishkinz: .ascii "CheadmishkinZ"<0>  # DATA XREF: D:8003E374o
D:80057202                     .half 0
D:80057204     aCheadsallyz:   .ascii "CheadsallyZ"<0>  # DATA XREF: D:8003E388o
D:80057210     aCheadmarionz:  .ascii "CheadmarionZ"<0>  # DATA XREF: D:8003E39Co
D:8005721D                     .byte 0, 0, 0
D:80057220     aCheadmandyz:   .ascii "CheadmandyZ"<0>  # DATA XREF: D:8003E3B0o
D:8005722C     aCheadvivienz:  .ascii "CheadvivienZ"<0>  # DATA XREF: D:8003E3C4o
D:80057239                     .byte 0, 0, 0
D:8005723C     aCheadbrosnanboilerz:.ascii "CheadbrosnanboilerZ"<0>  # DATA XREF: D:8003E3D8o
D:80057250     aCheadbrosnansuitz:.ascii "CheadbrosnansuitZ"<0>  # DATA XREF: D:8003E3ECo
D:80057262                     .half 0
D:80057264     aCheadbrosnantimberz:.ascii "CheadbrosnantimberZ"<0>  # DATA XREF: D:8003E400o
D:80057278     aCheadbrosnansnowz:.ascii "CheadbrosnansnowZ"<0>  # DATA XREF: D:8003E414o
D:8005728A                     .half 0
D:8005728C     aCheadbrosnanz: .ascii "CheadbrosnanZ"<0>  # DATA XREF: D:stru_D_8003E428o
D:8005729A                     .half 0
D:8005729C     aCspicebondz:   .ascii "CspicebondZ"<0>  # DATA XREF: D:8003E43Co
D:800572A8                     .align 4
D:800572B0     jpt_700C5B38:   .word cheats_cheat_extra_mp_chars, cheats_cheat_invincibility, cheats_cheat_allguns
D:800572B0                                              # DATA XREF: sub_CODE_7F091B64+98r
D:800572B0                     .word cheats_cheat_max_ammo, cheats_debug_return_saved_ra, cheats_cheat_deactivate_invincibility  # jump table for switch statement
D:800572B0                     .word cheats_cheat_linemode, cheats_cheat_2x_health, cheats_cheat_2x_armor
D:800572B0                     .word cheats_cheat_invisibility, cheats_cheat_infinite_ammo, cheats_cheat_dk_mode
D:800572B0                     .word cheats_cheat_extra_weapons, cheats_cheat_tiny_bond, cheats_cheat_paintball
D:800572B0                     .word cheats_cheat_10x_health, cheats_cheat_magnum, cheats_cheat_laser, cheats_cheat_goldengun
D:800572B0                     .word cheats_cheat_silverpp7, cheats_cheat_goldpp7, cheats_cheat_invisibility_mp
D:800572B0                     .word cheats_debug_return_saved_ra, cheats_cheat_fast, cheats_debug_pos, cheats_debug_fast_ani
D:800572B0                     .word cheats_debug_slow_ani, cheats_debug_return_saved_ra, cheats_debug_2x_rockets
D:800572B0                     .word cheats_debug_2x_grenade_launch, cheats_debug_2x_rcp90, cheats_debug_2x_throwing_knife
D:800572B0                     .word cheats_debug_2x_hunting_knife, cheats_debug_2x_laser, cheats_debug_unlockcheat
D:800572B0                     .word cheats_debug_unlockcheat, cheats_debug_unlockcheat, cheats_debug_unlockcheat
D:800572B0                     .word cheats_debug_unlockcheat, cheats_debug_unlockcheat, cheats_debug_unlockcheat
D:800572B0                     .word cheats_debug_unlockcheat, cheats_debug_unlockcheat, cheats_debug_unlockcheat
D:800572B0                     .word cheats_debug_unlockcheat, cheats_debug_unlockcheat, cheats_debug_unlockcheat
D:800572B0                     .word cheats_debug_unlockcheat, cheats_debug_unlockcheat, cheats_debug_unlockcheat
D:800572B0                     .word cheats_debug_unlockcheat, cheats_debug_unlockcheat, cheats_debug_unlockcheat
D:800572B0                     .word cheats_debug_unlockcheat, cheats_debug_unlocklevel, cheats_debug_unlocklevel
D:800572B0                     .word cheats_debug_unlocklevel, cheats_debug_unlocklevel, cheats_debug_unlocklevel
D:800572B0                     .word cheats_debug_unlocklevel, cheats_debug_unlocklevel, cheats_debug_unlocklevel
D:800572B0                     .word cheats_debug_unlocklevel, cheats_debug_unlocklevel, cheats_debug_unlocklevel
D:800572B0                     .word cheats_debug_unlocklevel, cheats_debug_unlocklevel, cheats_debug_unlocklevel
D:800572B0                     .word cheats_debug_unlocklevel, cheats_debug_unlocklevel, cheats_debug_unlocklevel
D:800572B0                     .word cheats_debug_unlocklevel, cheats_debug_unlocklevel, cheats_debug_unlocklevel
D:800573D8      # f32 finalamount
D:800573D8     finalamount:    .float 0.050000001       # DATA XREF: sub_CODE_7F091B64+5F0r
D:800573DC     jpt_700C6400:   .word cheat_button_default, cheat_button_invincibility, cheat_button_all_guns
D:800573DC                                              # DATA XREF: sub_CODE_7F092438+8Cr
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_line_mode  # jump table for switch statement
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_unknown, cheat_button_infinite_ammo
D:800573DC                     .word cheat_button_dkmode, cheat_button_default, cheat_button_unknown_0, cheat_button_paintball
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_mp_invis, cheat_button_default
D:800573DC                     .word cheat_button_fast_mode, cheat_button_debug_mode, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:800573DC                     .word cheat_button_default, cheat_button_default, cheat_button_default, cheat_button_default
D:80057504     flt_D_80057504: .float 0.80000001        # DATA XREF: sub_CODE_7F0927F4+38r
*/





#ifdef NONMATCHING
void sub_GAME_7F091740(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091740
/* 0C6270 7F091740 AFA40000 */  sw    $a0, ($sp)
/* 0C6274 7F091744 308EFFFF */  andi  $t6, $a0, 0xffff
/* 0C6278 7F091748 01C02025 */  move  $a0, $t6
/* 0C627C 7F09174C 11C00009 */  beqz  $t6, .L7F091774
/* 0C6280 7F091750 00001825 */   move  $v1, $zero
.L7F091754:
/* 0C6284 7F091754 308F0001 */  andi  $t7, $a0, 1
/* 0C6288 7F091758 11E00002 */  beqz  $t7, .L7F091764
/* 0C628C 7F09175C 00801025 */   move  $v0, $a0
/* 0C6290 7F091760 24630001 */  addiu $v1, $v1, 1
.L7F091764:
/* 0C6294 7F091764 00022042 */  srl   $a0, $v0, 1
/* 0C6298 7F091768 3098FFFF */  andi  $t8, $a0, 0xffff
/* 0C629C 7F09176C 1700FFF9 */  bnez  $t8, .L7F091754
/* 0C62A0 7F091770 03002025 */   move  $a0, $t8
.L7F091774:
/* 0C62A4 7F091774 03E00008 */  jr    $ra
/* 0C62A8 7F091778 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09177C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09177C
/* 0C62AC 7F09177C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C62B0 7F091780 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C62B4 7F091784 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C62B8 7F091788 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C62BC 7F09178C 3C118004 */  lui   $s1, %hi(D_8003F80C) # $s1, 0x8004
/* 0C62C0 7F091790 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C62C4 7F091794 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C62C8 7F091798 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C62CC 7F09179C 2631F80C */  addiu $s1, %lo(D_8003F80C) # addiu $s1, $s1, -0x7f4
/* 0C62D0 7F0917A0 0FC2F7C1 */  jal   sub_GAME_7F0BDF04
/* 0C62D4 7F0917A4 0000A025 */   move  $s4, $zero
/* 0C62D8 7F0917A8 2401005A */  li    $at, 90
/* 0C62DC 7F0917AC 14410003 */  bne   $v0, $at, .L7F0917BC
/* 0C62E0 7F0917B0 00000000 */   nop   
/* 0C62E4 7F0917B4 10000008 */  b     .L7F0917D8
/* 0C62E8 7F0917B8 24130001 */   li    $s3, 1
.L7F0917BC:
/* 0C62EC 7F0917BC 0FC26919 */  jal   get_num_players
/* 0C62F0 7F0917C0 00000000 */   nop   
/* 0C62F4 7F0917C4 24010001 */  li    $at, 1
/* 0C62F8 7F0917C8 14410003 */  bne   $v0, $at, .L7F0917D8
/* 0C62FC 7F0917CC 24130004 */   li    $s3, 4
/* 0C6300 7F0917D0 10000001 */  b     .L7F0917D8
/* 0C6304 7F0917D4 24130002 */   li    $s3, 2
.L7F0917D8:
/* 0C6308 7F0917D8 3C0E8004 */  lui   $t6, %hi(D_8003F80C) # $t6, 0x8004
/* 0C630C 7F0917DC 91CEF80C */  lbu   $t6, %lo(D_8003F80C)($t6)
/* 0C6310 7F0917E0 3C128008 */  lui   $s2, %hi(ptr_BONDdata) # $s2, 0x8008
/* 0C6314 7F0917E4 2652A0B0 */  addiu $s2, %lo(ptr_BONDdata) # addiu $s2, $s2, -0x5f50
/* 0C6318 7F0917E8 11C0004C */  beqz  $t6, .L7F09191C
/* 0C631C 7F0917EC 24100014 */   li    $s0, 20
/* 0C6320 7F0917F0 92250001 */  lbu   $a1, 1($s1)
.L7F0917F4:
/* 0C6324 7F0917F4 58A00044 */  blezl $a1, .L7F091908
/* 0C6328 7F0917F8 92280010 */   lbu   $t0, 0x10($s1)
/* 0C632C 7F0917FC 8E460000 */  lw    $a2, ($s2)
/* 0C6330 7F091800 90CF12B5 */  lbu   $t7, 0x12b5($a2)
/* 0C6334 7F091804 01E5082A */  slt   $at, $t7, $a1
/* 0C6338 7F091808 5420003F */  bnezl $at, .L7F091908
/* 0C633C 7F09180C 92280010 */   lbu   $t0, 0x10($s1)
/* 0C6340 7F091810 8E38000C */  lw    $t8, 0xc($s1)
/* 0C6344 7F091814 0313C824 */  and   $t9, $t8, $s3
/* 0C6348 7F091818 5320003B */  beql  $t9, $zero, .L7F091908
/* 0C634C 7F09181C 92280010 */   lbu   $t0, 0x10($s1)
/* 0C6350 7F091820 90C812B4 */  lbu   $t0, 0x12b4($a2)
/* 0C6354 7F091824 00002025 */  move  $a0, $zero
/* 0C6358 7F091828 01054823 */  subu  $t1, $t0, $a1
/* 0C635C 7F09182C 252A0014 */  addiu $t2, $t1, 0x14
/* 0C6360 7F091830 0150001A */  div   $zero, $t2, $s0
/* 0C6364 7F091834 00001010 */  mfhi  $v0
/* 0C6368 7F091838 16000002 */  bnez  $s0, .L7F091844
/* 0C636C 7F09183C 00000000 */   nop   
/* 0C6370 7F091840 0007000D */  break 7
.L7F091844:
/* 0C6374 7F091844 2401FFFF */  li    $at, -1
/* 0C6378 7F091848 16010004 */  bne   $s0, $at, .L7F09185C
/* 0C637C 7F09184C 3C018000 */   lui   $at, 0x8000
/* 0C6380 7F091850 15410002 */  bne   $t2, $at, .L7F09185C
/* 0C6384 7F091854 00000000 */   nop   
/* 0C6388 7F091858 0006000D */  break 6
.L7F09185C:
/* 0C638C 7F09185C 18A00018 */  blez  $a1, .L7F0918C0
/* 0C6390 7F091860 00000000 */   nop   
/* 0C6394 7F091864 8E230004 */  lw    $v1, 4($s1)
.L7F091868:
/* 0C6398 7F091868 00025840 */  sll   $t3, $v0, 1
/* 0C639C 7F09186C 00CB6021 */  addu  $t4, $a2, $t3
/* 0C63A0 7F091870 958D128C */  lhu   $t5, 0x128c($t4)
/* 0C63A4 7F091874 946E0000 */  lhu   $t6, ($v1)
/* 0C63A8 7F091878 244F0001 */  addiu $t7, $v0, 1
/* 0C63AC 7F09187C 15AE0010 */  bne   $t5, $t6, .L7F0918C0
/* 0C63B0 7F091880 00000000 */   nop   
/* 0C63B4 7F091884 01F0001A */  div   $zero, $t7, $s0
/* 0C63B8 7F091888 16000002 */  bnez  $s0, .L7F091894
/* 0C63BC 7F09188C 00000000 */   nop   
/* 0C63C0 7F091890 0007000D */  break 7
.L7F091894:
/* 0C63C4 7F091894 2401FFFF */  li    $at, -1
/* 0C63C8 7F091898 16010004 */  bne   $s0, $at, .L7F0918AC
/* 0C63CC 7F09189C 3C018000 */   lui   $at, 0x8000
/* 0C63D0 7F0918A0 15E10002 */  bne   $t7, $at, .L7F0918AC
/* 0C63D4 7F0918A4 00000000 */   nop   
/* 0C63D8 7F0918A8 0006000D */  break 6
.L7F0918AC:
/* 0C63DC 7F0918AC 24840001 */  addiu $a0, $a0, 1
/* 0C63E0 7F0918B0 00001010 */  mfhi  $v0
/* 0C63E4 7F0918B4 0085082A */  slt   $at, $a0, $a1
/* 0C63E8 7F0918B8 1420FFEB */  bnez  $at, .L7F091868
/* 0C63EC 7F0918BC 24630002 */   addiu $v1, $v1, 2
.L7F0918C0:
/* 0C63F0 7F0918C0 54850011 */  bnel  $a0, $a1, .L7F091908
/* 0C63F4 7F0918C4 92280010 */   lbu   $t0, 0x10($s1)
/* 0C63F8 7F0918C8 A0C012B5 */  sb    $zero, 0x12b5($a2)
/* 0C63FC 7F0918CC 0FC249EF */  jal   sub_GAME_7F0927BC
/* 0C6400 7F0918D0 92240000 */   lbu   $a0, ($s1)
/* 0C6404 7F0918D4 10400005 */  beqz  $v0, .L7F0918EC
/* 0C6408 7F0918D8 00000000 */   nop   
/* 0C640C 7F0918DC 8E38000C */  lw    $t8, 0xc($s1)
/* 0C6410 7F0918E0 33190010 */  andi  $t9, $t8, 0x10
/* 0C6414 7F0918E4 13200005 */  beqz  $t9, .L7F0918FC
/* 0C6418 7F0918E8 00000000 */   nop   
.L7F0918EC:
/* 0C641C 7F0918EC 0FC246D9 */  jal   sub_GAME_7F091B64
/* 0C6420 7F0918F0 92240000 */   lbu   $a0, ($s1)
/* 0C6424 7F0918F4 10000004 */  b     .L7F091908
/* 0C6428 7F0918F8 92280010 */   lbu   $t0, 0x10($s1)
.L7F0918FC:
/* 0C642C 7F0918FC 0FC2490E */  jal   sub_GAME_7F092438
/* 0C6430 7F091900 92240000 */   lbu   $a0, ($s1)
/* 0C6434 7F091904 92280010 */  lbu   $t0, 0x10($s1)
.L7F091908:
/* 0C6438 7F091908 26310010 */  addiu $s1, $s1, 0x10
/* 0C643C 7F09190C 51000004 */  beql  $t0, $zero, .L7F091920
/* 0C6440 7F091910 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0C6444 7F091914 5280FFB7 */  beql  $s4, $zero, .L7F0917F4
/* 0C6448 7F091918 92250001 */   lbu   $a1, 1($s1)
.L7F09191C:
/* 0C644C 7F09191C 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F091920:
/* 0C6450 7F091920 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C6454 7F091924 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C6458 7F091928 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C645C 7F09192C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C6460 7F091930 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C6464 7F091934 03E00008 */  jr    $ra
/* 0C6468 7F091938 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09193C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09193C
/* 0C646C 7F09193C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C6470 7F091940 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6474 7F091944 0FC26C54 */  jal   get_cur_playernum
/* 0C6478 7F091948 00000000 */   nop   
/* 0C647C 7F09194C 00022600 */  sll   $a0, $v0, 0x18
/* 0C6480 7F091950 00047603 */  sra   $t6, $a0, 0x18
/* 0C6484 7F091954 01C02025 */  move  $a0, $t6
/* 0C6488 7F091958 0C0030C3 */  jal   get_controller_buttons_held
/* 0C648C 7F09195C 3405FFFF */   li    $a1, 65535
/* 0C6490 7F091960 0FC26C54 */  jal   get_cur_playernum
/* 0C6494 7F091964 A7A20026 */   sh    $v0, 0x26($sp)
/* 0C6498 7F091968 00022600 */  sll   $a0, $v0, 0x18
/* 0C649C 7F09196C 00047E03 */  sra   $t7, $a0, 0x18
/* 0C64A0 7F091970 01E02025 */  move  $a0, $t7
/* 0C64A4 7F091974 0C0030EB */  jal   get_controller_buttons_pressed
/* 0C64A8 7F091978 3405FFFF */   li    $a1, 65535
/* 0C64AC 7F09197C 97A30026 */  lhu   $v1, 0x26($sp)
/* 0C64B0 7F091980 30780030 */  andi  $t8, $v1, 0x30
/* 0C64B4 7F091984 3306FFFF */  andi  $a2, $t8, 0xffff
/* 0C64B8 7F091988 00C04827 */  not   $t1, $a2
/* 0C64BC 7F09198C 0300C827 */  not   $t9, $t8
/* 0C64C0 7F091990 00492824 */  and   $a1, $v0, $t1
/* 0C64C4 7F091994 30AAFFFF */  andi  $t2, $a1, 0xffff
/* 0C64C8 7F091998 00794024 */  and   $t0, $v1, $t9
/* 0C64CC 7F09199C A7A80026 */  sh    $t0, 0x26($sp)
/* 0C64D0 7F0919A0 11400028 */  beqz  $t2, .L7F091A44
/* 0C64D4 7F0919A4 A7A50024 */   sh    $a1, 0x24($sp)
/* 0C64D8 7F0919A8 30A4FFFF */  andi  $a0, $a1, 0xffff
/* 0C64DC 7F0919AC 0FC245D0 */  jal   sub_GAME_7F091740
/* 0C64E0 7F0919B0 AFA60018 */   sw    $a2, 0x18($sp)
/* 0C64E4 7F0919B4 24010001 */  li    $at, 1
/* 0C64E8 7F0919B8 1441001E */  bne   $v0, $at, .L7F091A34
/* 0C64EC 7F0919BC 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C64F0 7F0919C0 97A40026 */  lhu   $a0, 0x26($sp)
/* 0C64F4 7F0919C4 0FC245D0 */  jal   sub_GAME_7F091740
/* 0C64F8 7F0919C8 AFA70018 */   sw    $a3, 0x18($sp)
/* 0C64FC 7F0919CC 24010001 */  li    $at, 1
/* 0C6500 7F0919D0 14410018 */  bne   $v0, $at, .L7F091A34
/* 0C6504 7F0919D4 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C6508 7F0919D8 3C048008 */  lui   $a0, %hi(ptr_BONDdata) # $a0, 0x8008
/* 0C650C 7F0919DC 2484A0B0 */  addiu $a0, %lo(ptr_BONDdata) # addiu $a0, $a0, -0x5f50
/* 0C6510 7F0919E0 8C820000 */  lw    $v0, ($a0)
/* 0C6514 7F0919E4 97AB0024 */  lhu   $t3, 0x24($sp)
/* 0C6518 7F0919E8 24010014 */  li    $at, 20
/* 0C651C 7F0919EC 904D12B4 */  lbu   $t5, 0x12b4($v0)
/* 0C6520 7F0919F0 01676025 */  or    $t4, $t3, $a3
/* 0C6524 7F0919F4 000D7040 */  sll   $t6, $t5, 1
/* 0C6528 7F0919F8 004E7821 */  addu  $t7, $v0, $t6
/* 0C652C 7F0919FC A5EC128C */  sh    $t4, 0x128c($t7)
/* 0C6530 7F091A00 8C820000 */  lw    $v0, ($a0)
/* 0C6534 7F091A04 905812B4 */  lbu   $t8, 0x12b4($v0)
/* 0C6538 7F091A08 27190001 */  addiu $t9, $t8, 1
/* 0C653C 7F091A0C 0321001A */  div   $zero, $t9, $at
/* 0C6540 7F091A10 00004010 */  mfhi  $t0
/* 0C6544 7F091A14 A04812B4 */  sb    $t0, 0x12b4($v0)
/* 0C6548 7F091A18 8C820000 */  lw    $v0, ($a0)
/* 0C654C 7F091A1C 904312B5 */  lbu   $v1, 0x12b5($v0)
/* 0C6550 7F091A20 28610014 */  slti  $at, $v1, 0x14
/* 0C6554 7F091A24 10200007 */  beqz  $at, .L7F091A44
/* 0C6558 7F091A28 24690001 */   addiu $t1, $v1, 1
/* 0C655C 7F091A2C 10000005 */  b     .L7F091A44
/* 0C6560 7F091A30 A04912B5 */   sb    $t1, 0x12b5($v0)
.L7F091A34:
/* 0C6564 7F091A34 3C048008 */  lui   $a0, %hi(ptr_BONDdata) # $a0, 0x8008
/* 0C6568 7F091A38 2484A0B0 */  addiu $a0, %lo(ptr_BONDdata) # addiu $a0, $a0, -0x5f50
/* 0C656C 7F091A3C 8C8A0000 */  lw    $t2, ($a0)
/* 0C6570 7F091A40 A14012B5 */  sb    $zero, 0x12b5($t2)
.L7F091A44:
/* 0C6574 7F091A44 0FC245DF */  jal   sub_GAME_7F09177C
/* 0C6578 7F091A48 00000000 */   nop   
/* 0C657C 7F091A4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C6580 7F091A50 27BD0028 */  addiu $sp, $sp, 0x28
/* 0C6584 7F091A54 03E00008 */  jr    $ra
/* 0C6588 7F091A58 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091A5C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091A5C
/* 0C658C 7F091A5C 2401001C */  li    $at, 28
/* 0C6590 7F091A60 14810003 */  bne   $a0, $at, .L7F091A70
/* 0C6594 7F091A64 00001025 */   move  $v0, $zero
/* 0C6598 7F091A68 03E00008 */  jr    $ra
/* 0C659C 7F091A6C 24020001 */   li    $v0, 1

.L7F091A70:
/* 0C65A0 7F091A70 03E00008 */  jr    $ra
/* 0C65A4 7F091A74 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091A78(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091A78
/* 0C65A8 7F091A78 00047100 */  sll   $t6, $a0, 4
/* 0C65AC 7F091A7C 3C0F8004 */  lui   $t7, 0x8004
/* 0C65B0 7F091A80 01EE7821 */  addu  $t7, $t7, $t6
/* 0C65B4 7F091A84 8DEFF808 */  lw    $t7, -0x7f8($t7)
/* 0C65B8 7F091A88 24010004 */  li    $at, 4
/* 0C65BC 7F091A8C 00001025 */  move  $v0, $zero
/* 0C65C0 7F091A90 31F80004 */  andi  $t8, $t7, 4
/* 0C65C4 7F091A94 17010003 */  bne   $t8, $at, .L7F091AA4
/* 0C65C8 7F091A98 00000000 */   nop   
/* 0C65CC 7F091A9C 03E00008 */  jr    $ra
/* 0C65D0 7F091AA0 24020001 */   li    $v0, 1

.L7F091AA4:
/* 0C65D4 7F091AA4 03E00008 */  jr    $ra
/* 0C65D8 7F091AA8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091AAC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091AAC
/* 0C65DC 7F091AAC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C65E0 7F091AB0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C65E4 7F091AB4 3C108004 */  lui   $s0, 0x8004
/* 0C65E8 7F091AB8 00047100 */  sll   $t6, $a0, 4
/* 0C65EC 7F091ABC AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C65F0 7F091AC0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C65F4 7F091AC4 020E8021 */  addu  $s0, $s0, $t6
/* 0C65F8 7F091AC8 00809025 */  move  $s2, $a0
/* 0C65FC 7F091ACC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C6600 7F091AD0 0FC26C54 */  jal   get_cur_playernum
/* 0C6604 7F091AD4 8E10F808 */   lw    $s0, -0x7f8($s0)
/* 0C6608 7F091AD8 0FC26919 */  jal   get_num_players
/* 0C660C 7F091ADC AFA20028 */   sw    $v0, 0x28($sp)
/* 0C6610 7F091AE0 24010001 */  li    $at, 1
/* 0C6614 7F091AE4 14410005 */  bne   $v0, $at, .L7F091AFC
/* 0C6618 7F091AE8 00408825 */   move  $s1, $v0
/* 0C661C 7F091AEC 0FC246D9 */  jal   sub_GAME_7F091B64
/* 0C6620 7F091AF0 02402025 */   move  $a0, $s2
/* 0C6624 7F091AF4 10000016 */  b     .L7F091B50
/* 0C6628 7F091AF8 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F091AFC:
/* 0C662C 7F091AFC 320F0004 */  andi  $t7, $s0, 4
/* 0C6630 7F091B00 11E00012 */  beqz  $t7, .L7F091B4C
/* 0C6634 7F091B04 32180020 */   andi  $t8, $s0, 0x20
/* 0C6638 7F091B08 13000005 */  beqz  $t8, .L7F091B20
/* 0C663C 7F091B0C 00000000 */   nop   
/* 0C6640 7F091B10 0FC246D9 */  jal   sub_GAME_7F091B64
/* 0C6644 7F091B14 02402025 */   move  $a0, $s2
/* 0C6648 7F091B18 1000000D */  b     .L7F091B50
/* 0C664C 7F091B1C 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F091B20:
/* 0C6650 7F091B20 18400008 */  blez  $v0, .L7F091B44
/* 0C6654 7F091B24 00008025 */   move  $s0, $zero
.L7F091B28:
/* 0C6658 7F091B28 0FC26C43 */  jal   set_cur_player
/* 0C665C 7F091B2C 02002025 */   move  $a0, $s0
/* 0C6660 7F091B30 0FC246D9 */  jal   sub_GAME_7F091B64
/* 0C6664 7F091B34 02402025 */   move  $a0, $s2
/* 0C6668 7F091B38 26100001 */  addiu $s0, $s0, 1
/* 0C666C 7F091B3C 1611FFFA */  bne   $s0, $s1, .L7F091B28
/* 0C6670 7F091B40 00000000 */   nop   
.L7F091B44:
/* 0C6674 7F091B44 0FC26C43 */  jal   set_cur_player
/* 0C6678 7F091B48 8FA40028 */   lw    $a0, 0x28($sp)
.L7F091B4C:
/* 0C667C 7F091B4C 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F091B50:
/* 0C6680 7F091B50 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C6684 7F091B54 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C6688 7F091B58 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C668C 7F091B5C 03E00008 */  jr    $ra
/* 0C6690 7F091B60 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F091B64(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F091B64
/* 0C6694 7F091B64 00047100 */  sll   $t6, $a0, 4
/* 0C6698 7F091B68 3C0F8004 */  lui   $t7, 0x8004
/* 0C669C 7F091B6C 01EE7821 */  addu  $t7, $t7, $t6
/* 0C66A0 7F091B70 8DEFF808 */  lw    $t7, -0x7f8($t7)
/* 0C66A4 7F091B74 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0C66A8 7F091B78 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C66AC 7F091B7C AFA40040 */  sw    $a0, 0x40($sp)
/* 0C66B0 7F091B80 0FC26C54 */  jal   get_cur_playernum
/* 0C66B4 7F091B84 AFAF003C */   sw    $t7, 0x3c($sp)
/* 0C66B8 7F091B88 0FC26919 */  jal   get_num_players
/* 0C66BC 7F091B8C AFA20038 */   sw    $v0, 0x38($sp)
/* 0C66C0 7F091B90 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C66C4 7F091B94 8FA60040 */  lw    $a2, 0x40($sp)
/* 0C66C8 7F091B98 AFA20034 */  sw    $v0, 0x34($sp)
/* 0C66CC 7F091B9C 30780010 */  andi  $t8, $v1, 0x10
/* 0C66D0 7F091BA0 17000012 */  bnez  $t8, .L7F091BEC
/* 0C66D4 7F091BA4 30790020 */   andi  $t9, $v1, 0x20
/* 0C66D8 7F091BA8 1720000A */  bnez  $t9, .L7F091BD4
/* 0C66DC 7F091BAC 8FA50038 */   lw    $a1, 0x38($sp)
/* 0C66E0 7F091BB0 3C098008 */  lui   $t1, %hi(off_CODE_bss_80079E30) # $t1, 0x8008
/* 0C66E4 7F091BB4 25299E30 */  addiu $t1, %lo(off_CODE_bss_80079E30) # addiu $t1, $t1, -0x61d0
/* 0C66E8 7F091BB8 00C91821 */  addu  $v1, $a2, $t1
/* 0C66EC 7F091BBC 906A0000 */  lbu   $t2, ($v1)
/* 0C66F0 7F091BC0 240B0001 */  li    $t3, 1
/* 0C66F4 7F091BC4 00AB6004 */  sllv  $t4, $t3, $a1
/* 0C66F8 7F091BC8 014C6825 */  or    $t5, $t2, $t4
/* 0C66FC 7F091BCC 10000007 */  b     .L7F091BEC
/* 0C6700 7F091BD0 A06D0000 */   sb    $t5, ($v1)
.L7F091BD4:
/* 0C6704 7F091BD4 240E0001 */  li    $t6, 1
/* 0C6708 7F091BD8 004E7804 */  sllv  $t7, $t6, $v0
/* 0C670C 7F091BDC 3C018008 */  lui   $at, 0x8008
/* 0C6710 7F091BE0 00260821 */  addu  $at, $at, $a2
/* 0C6714 7F091BE4 25F8FFFF */  addiu $t8, $t7, -1
/* 0C6718 7F091BE8 A0389E30 */  sb    $t8, -0x61d0($at)
.L7F091BEC:
/* 0C671C 7F091BEC 24D9FFFF */  addiu $t9, $a2, -1
/* 0C6720 7F091BF0 2F21004A */  sltiu $at, $t9, 0x4a
/* 0C6724 7F091BF4 1020020C */  beqz  $at, .L7F092428
/* 0C6728 7F091BF8 0019C880 */   sll   $t9, $t9, 2
/* 0C672C 7F091BFC 3C018005 */  lui   $at, 0x8005
/* 0C6730 7F091C00 00390821 */  addu  $at, $at, $t9
/* 0C6734 7F091C04 8C3972B0 */  lw    $t9, 0x72b0($at)
/* 0C6738 7F091C08 03200008 */  jr    $t9
/* 0C673C 7F091C0C 00000000 */   nop   
cheats_cheat_extra_mp_chars:
/* 0C6740 7F091C10 0FC040A0 */  jal   unlock_all_mp_chars
/* 0C6744 7F091C14 00000000 */   nop   
/* 0C6748 7F091C18 10000204 */  b     .L7F09242C
/* 0C674C 7F091C1C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invincibility:
/* 0C6750 7F091C20 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C6754 7F091C24 00000000 */   nop   
/* 0C6758 7F091C28 54400200 */  bnezl $v0, .L7F09242C
/* 0C675C 7F091C2C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6760 7F091C30 0FC30776 */  jal   get_textptr_for_textID
/* 0C6764 7F091C34 3404B00F */   li    $a0, 45071
/* 0C6768 7F091C38 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C676C 7F091C3C 00402025 */   move  $a0, $v0
/* 0C6770 7F091C40 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C6774 7F091C44 24040001 */   li    $a0, 1
/* 0C6778 7F091C48 100001F8 */  b     .L7F09242C
/* 0C677C 7F091C4C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_allguns:
/* 0C6780 7F091C50 0FC230AB */  jal   get_BONDdata_allguns_flag
/* 0C6784 7F091C54 00000000 */   nop   
/* 0C6788 7F091C58 544001F4 */  bnezl $v0, .L7F09242C
/* 0C678C 7F091C5C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6790 7F091C60 0FC30776 */  jal   get_textptr_for_textID
/* 0C6794 7F091C64 3404B010 */   li    $a0, 45072
/* 0C6798 7F091C68 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C679C 7F091C6C 00402025 */   move  $a0, $v0
/* 0C67A0 7F091C70 0FC230A7 */  jal   set_BONDdata_allguns_flag
/* 0C67A4 7F091C74 24040001 */   li    $a0, 1
/* 0C67A8 7F091C78 100001EC */  b     .L7F09242C
/* 0C67AC 7F091C7C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_max_ammo:
/* 0C67B0 7F091C80 0FC30776 */  jal   get_textptr_for_textID
/* 0C67B4 7F091C84 3404B011 */   li    $a0, 45073
/* 0C67B8 7F091C88 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C67BC 7F091C8C 00402025 */   move  $a0, $v0
/* 0C67C0 7F091C90 0FC1A4BC */  jal   set_max_ammo_for_cur_player
/* 0C67C4 7F091C94 00000000 */   nop   
/* 0C67C8 7F091C98 100001E4 */  b     .L7F09242C
/* 0C67CC 7F091C9C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_deactivate_invincibility:
/* 0C67D0 7F091CA0 28410002 */  slti  $at, $v0, 2
/* 0C67D4 7F091CA4 142001E0 */  bnez  $at, .L7F092428
/* 0C67D8 7F091CA8 AFA0002C */   sw    $zero, 0x2c($sp)
/* 0C67DC 7F091CAC 18400015 */  blez  $v0, .L7F091D04
/* 0C67E0 7F091CB0 AFA00030 */   sw    $zero, 0x30($sp)
.L7F091CB4:
/* 0C67E4 7F091CB4 8FA50038 */  lw    $a1, 0x38($sp)
/* 0C67E8 7F091CB8 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C67EC 7F091CBC 1125000A */  beq   $t1, $a1, .L7F091CE8
/* 0C67F0 7F091CC0 00000000 */   nop   
/* 0C67F4 7F091CC4 0FC26C43 */  jal   set_cur_player
/* 0C67F8 7F091CC8 01202025 */   move  $a0, $t1
/* 0C67FC 7F091CCC 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C6800 7F091CD0 00000000 */   nop   
/* 0C6804 7F091CD4 10400004 */  beqz  $v0, .L7F091CE8
/* 0C6808 7F091CD8 00002025 */   move  $a0, $zero
/* 0C680C 7F091CDC 240B0001 */  li    $t3, 1
/* 0C6810 7F091CE0 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C6814 7F091CE4 AFAB002C */   sw    $t3, 0x2c($sp)
.L7F091CE8:
/* 0C6818 7F091CE8 0FC26C43 */  jal   set_cur_player
/* 0C681C 7F091CEC 8FA40038 */   lw    $a0, 0x38($sp)
/* 0C6820 7F091CF0 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0C6824 7F091CF4 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0C6828 7F091CF8 254C0001 */  addiu $t4, $t2, 1
/* 0C682C 7F091CFC 158DFFED */  bne   $t4, $t5, .L7F091CB4
/* 0C6830 7F091D00 AFAC0030 */   sw    $t4, 0x30($sp)
.L7F091D04:
/* 0C6834 7F091D04 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0C6838 7F091D08 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C683C 7F091D0C 2405009F */  li    $a1, 159
/* 0C6840 7F091D10 11C001C5 */  beqz  $t6, .L7F092428
/* 0C6844 7F091D14 00003025 */   move  $a2, $zero
/* 0C6848 7F091D18 0C002382 */  jal   play_sfx_a1
/* 0C684C 7F091D1C 8C843720 */   lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6850 7F091D20 100001C2 */  b     .L7F09242C
/* 0C6854 7F091D24 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_linemode:
/* 0C6858 7F091D28 0FC243FA */  jal   set_linemode_flag
/* 0C685C 7F091D2C 24040001 */   li    $a0, 1
/* 0C6860 7F091D30 100001BE */  b     .L7F09242C
/* 0C6864 7F091D34 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_2x_health:
/* 0C6868 7F091D38 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C686C 7F091D3C 8C42A0B0 */  lw    $v0, %lo(ptr_BONDdata)($v0)
/* 0C6870 7F091D40 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6874 7F091D44 44812000 */  mtc1  $at, $f4
/* 0C6878 7F091D48 C4462A3C */  lwc1  $f6, 0x2a3c($v0)
/* 0C687C 7F091D4C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6880 7F091D50 46062032 */  c.eq.s $f4, $f6
/* 0C6884 7F091D54 00000000 */  nop   
/* 0C6888 7F091D58 45010008 */  bc1t  .L7F091D7C
/* 0C688C 7F091D5C 00000000 */   nop   
/* 0C6890 7F091D60 C44800DC */  lwc1  $f8, 0xdc($v0)
/* 0C6894 7F091D64 44815000 */  mtc1  $at, $f10
/* 0C6898 7F091D68 00000000 */  nop   
/* 0C689C 7F091D6C 460A403C */  c.lt.s $f8, $f10
/* 0C68A0 7F091D70 00000000 */  nop   
/* 0C68A4 7F091D74 450201AD */  bc1fl .L7F09242C
/* 0C68A8 7F091D78 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F091D7C:
/* 0C68AC 7F091D7C 0FC30776 */  jal   get_textptr_for_textID
/* 0C68B0 7F091D80 3404B012 */   li    $a0, 45074
/* 0C68B4 7F091D84 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C68B8 7F091D88 00402025 */   move  $a0, $v0
/* 0C68BC 7F091D8C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C68C0 7F091D90 3C0F8008 */  lui   $t7, %hi(ptr_BONDdata) # $t7, 0x8008
/* 0C68C4 7F091D94 8DEFA0B0 */  lw    $t7, %lo(ptr_BONDdata)($t7)
/* 0C68C8 7F091D98 44818000 */  mtc1  $at, $f16
/* 0C68CC 7F091D9C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C68D0 7F091DA0 3C188008 */  lui   $t8, %hi(ptr_BONDdata) # $t8, 0x8008
/* 0C68D4 7F091DA4 E5F000DC */  swc1  $f16, 0xdc($t7)
/* 0C68D8 7F091DA8 8F18A0B0 */  lw    $t8, %lo(ptr_BONDdata)($t8)
/* 0C68DC 7F091DAC 44819000 */  mtc1  $at, $f18
/* 0C68E0 7F091DB0 1000019D */  b     .L7F092428
/* 0C68E4 7F091DB4 E7122A3C */   swc1  $f18, 0x2a3c($t8)
cheats_cheat_2x_armor:
/* 0C68E8 7F091DB8 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C68EC 7F091DBC 8C42A0B0 */  lw    $v0, %lo(ptr_BONDdata)($v0)
/* 0C68F0 7F091DC0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C68F4 7F091DC4 44810000 */  mtc1  $at, $f0
/* 0C68F8 7F091DC8 C4442A40 */  lwc1  $f4, 0x2a40($v0)
/* 0C68FC 7F091DCC 46040032 */  c.eq.s $f0, $f4
/* 0C6900 7F091DD0 00000000 */  nop   
/* 0C6904 7F091DD4 45010006 */  bc1t  .L7F091DF0
/* 0C6908 7F091DD8 00000000 */   nop   
/* 0C690C 7F091DDC C44600E0 */  lwc1  $f6, 0xe0($v0)
/* 0C6910 7F091DE0 4600303C */  c.lt.s $f6, $f0
/* 0C6914 7F091DE4 00000000 */  nop   
/* 0C6918 7F091DE8 45020190 */  bc1fl .L7F09242C
/* 0C691C 7F091DEC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F091DF0:
/* 0C6920 7F091DF0 0FC30776 */  jal   get_textptr_for_textID
/* 0C6924 7F091DF4 3404B013 */   li    $a0, 45075
/* 0C6928 7F091DF8 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C692C 7F091DFC 00402025 */   move  $a0, $v0
/* 0C6930 7F091E00 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C6934 7F091E04 2442A0B0 */  addiu $v0, %lo(ptr_BONDdata) # addiu $v0, $v0, -0x5f50
/* 0C6938 7F091E08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C693C 7F091E0C 44814000 */  mtc1  $at, $f8
/* 0C6940 7F091E10 8C590000 */  lw    $t9, ($v0)
/* 0C6944 7F091E14 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C6948 7F091E18 44815000 */  mtc1  $at, $f10
/* 0C694C 7F091E1C E72800E0 */  swc1  $f8, 0xe0($t9)
/* 0C6950 7F091E20 8C490000 */  lw    $t1, ($v0)
/* 0C6954 7F091E24 10000180 */  b     .L7F092428
/* 0C6958 7F091E28 E52A2A40 */   swc1  $f10, 0x2a40($t1)
cheats_cheat_invisibility:
/* 0C695C 7F091E2C 0FC227DD */  jal   get_invisible_to_guards_flag
/* 0C6960 7F091E30 00000000 */   nop   
/* 0C6964 7F091E34 5040017D */  beql  $v0, $zero, .L7F09242C
/* 0C6968 7F091E38 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C696C 7F091E3C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6970 7F091E40 3404B014 */   li    $a0, 45076
/* 0C6974 7F091E44 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6978 7F091E48 00402025 */   move  $a0, $v0
/* 0C697C 7F091E4C 0FC227DA */  jal   set_invisible_to_guards_flag
/* 0C6980 7F091E50 00002025 */   move  $a0, $zero
/* 0C6984 7F091E54 10000175 */  b     .L7F09242C
/* 0C6988 7F091E58 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_infinite_ammo:
/* 0C698C 7F091E5C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6990 7F091E60 3404B016 */   li    $a0, 45078
/* 0C6994 7F091E64 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6998 7F091E68 00402025 */   move  $a0, $v0
/* 0C699C 7F091E6C 1000016F */  b     .L7F09242C
/* 0C69A0 7F091E70 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_dk_mode:
/* 0C69A4 7F091E74 0FC30776 */  jal   get_textptr_for_textID
/* 0C69A8 7F091E78 3404B017 */   li    $a0, 45079
/* 0C69AC 7F091E7C 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C69B0 7F091E80 00402025 */   move  $a0, $v0
/* 0C69B4 7F091E84 0FC249FD */  jal   sub_GAME_7F0927F4
/* 0C69B8 7F091E88 24040001 */   li    $a0, 1
/* 0C69BC 7F091E8C 10000167 */  b     .L7F09242C
/* 0C69C0 7F091E90 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_extra_weapons:
/* 0C69C4 7F091E94 24010001 */  li    $at, 1
/* 0C69C8 7F091E98 54410164 */  bnel  $v0, $at, .L7F09242C
/* 0C69CC 7F091E9C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C69D0 7F091EA0 0FC23122 */  jal   add_item_to_inventory
/* 0C69D4 7F091EA4 24040012 */   li    $a0, 18
/* 0C69D8 7F091EA8 AFA20028 */  sw    $v0, 0x28($sp)
/* 0C69DC 7F091EAC 0FC23122 */  jal   add_item_to_inventory
/* 0C69E0 7F091EB0 24040016 */   li    $a0, 22
/* 0C69E4 7F091EB4 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0C69E8 7F091EB8 24040013 */  li    $a0, 19
/* 0C69EC 7F091EBC 01625021 */  addu  $t2, $t3, $v0
/* 0C69F0 7F091EC0 0FC23122 */  jal   add_item_to_inventory
/* 0C69F4 7F091EC4 AFAA0028 */   sw    $t2, 0x28($sp)
/* 0C69F8 7F091EC8 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0C69FC 7F091ECC 24040014 */  li    $a0, 20
/* 0C6A00 7F091ED0 01826821 */  addu  $t5, $t4, $v0
/* 0C6A04 7F091ED4 0FC23122 */  jal   add_item_to_inventory
/* 0C6A08 7F091ED8 AFAD0028 */   sw    $t5, 0x28($sp)
/* 0C6A0C 7F091EDC 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0C6A10 7F091EE0 24040015 */  li    $a0, 21
/* 0C6A14 7F091EE4 01C27821 */  addu  $t7, $t6, $v0
/* 0C6A18 7F091EE8 0FC23122 */  jal   add_item_to_inventory
/* 0C6A1C 7F091EEC AFAF0028 */   sw    $t7, 0x28($sp)
/* 0C6A20 7F091EF0 8FB80028 */  lw    $t8, 0x28($sp)
/* 0C6A24 7F091EF4 2404000C */  li    $a0, 12
/* 0C6A28 7F091EF8 0302C821 */  addu  $t9, $t8, $v0
/* 0C6A2C 7F091EFC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A30 7F091F00 AFB90028 */   sw    $t9, 0x28($sp)
/* 0C6A34 7F091F04 2404000C */  li    $a0, 12
/* 0C6A38 7F091F08 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A3C 7F091F0C 00402825 */   move  $a1, $v0
/* 0C6A40 7F091F10 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A44 7F091F14 2404000D */   li    $a0, 13
/* 0C6A48 7F091F18 2404000D */  li    $a0, 13
/* 0C6A4C 7F091F1C 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A50 7F091F20 00402825 */   move  $a1, $v0
/* 0C6A54 7F091F24 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A58 7F091F28 24040001 */   li    $a0, 1
/* 0C6A5C 7F091F2C 24040001 */  li    $a0, 1
/* 0C6A60 7F091F30 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A64 7F091F34 00402825 */   move  $a1, $v0
/* 0C6A68 7F091F38 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C6A6C 7F091F3C 5920013B */  blezl $t1, .L7F09242C
/* 0C6A70 7F091F40 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6A74 7F091F44 0FC30776 */  jal   get_textptr_for_textID
/* 0C6A78 7F091F48 3404B018 */   li    $a0, 45080
/* 0C6A7C 7F091F4C 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6A80 7F091F50 00402025 */   move  $a0, $v0
/* 0C6A84 7F091F54 10000135 */  b     .L7F09242C
/* 0C6A88 7F091F58 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_tiny_bond:
/* 0C6A8C 7F091F5C 24010001 */  li    $at, 1
/* 0C6A90 7F091F60 14410131 */  bne   $v0, $at, .L7F092428
/* 0C6A94 7F091F64 3C0B8008 */   lui   $t3, %hi(cur_player_stat_ptr) # $t3, 0x8008
/* 0C6A98 7F091F68 8D6BA0B4 */  lw    $t3, %lo(cur_player_stat_ptr)($t3)
/* 0C6A9C 7F091F6C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6AA0 7F091F70 44818000 */  mtc1  $at, $f16
/* 0C6AA4 7F091F74 C5720064 */  lwc1  $f18, 0x64($t3)
/* 0C6AA8 7F091F78 46128032 */  c.eq.s $f16, $f18
/* 0C6AAC 7F091F7C 00000000 */  nop   
/* 0C6AB0 7F091F80 4502012A */  bc1fl .L7F09242C
/* 0C6AB4 7F091F84 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6AB8 7F091F88 0FC30776 */  jal   get_textptr_for_textID
/* 0C6ABC 7F091F8C 3404B019 */   li    $a0, 45081
/* 0C6AC0 7F091F90 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6AC4 7F091F94 00402025 */   move  $a0, $v0
/* 0C6AC8 7F091F98 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C6ACC 7F091F9C 3C0A8008 */  lui   $t2, %hi(cur_player_stat_ptr) # $t2, 0x8008
/* 0C6AD0 7F091FA0 44810000 */  mtc1  $at, $f0
/* 0C6AD4 7F091FA4 8D4AA0B4 */  lw    $t2, %lo(cur_player_stat_ptr)($t2)
/* 0C6AD8 7F091FA8 3C0C8008 */  lui   $t4, %hi(ptr_BONDdata) # $t4, 0x8008
/* 0C6ADC 7F091FAC E5400064 */  swc1  $f0, 0x64($t2)
/* 0C6AE0 7F091FB0 8D8CA0B0 */  lw    $t4, %lo(ptr_BONDdata)($t4)
/* 0C6AE4 7F091FB4 8D8400D4 */  lw    $a0, 0xd4($t4)
/* 0C6AE8 7F091FB8 5080011C */  beql  $a0, $zero, .L7F09242C
/* 0C6AEC 7F091FBC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6AF0 7F091FC0 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C6AF4 7F091FC4 46002182 */  mul.s $f6, $f4, $f0
/* 0C6AF8 7F091FC8 44053000 */  mfc1  $a1, $f6
/* 0C6AFC 7F091FCC 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C6B00 7F091FD0 00000000 */   nop   
/* 0C6B04 7F091FD4 10000115 */  b     .L7F09242C
/* 0C6B08 7F091FD8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_paintball:
/* 0C6B0C 7F091FDC 0FC30776 */  jal   get_textptr_for_textID
/* 0C6B10 7F091FE0 3404B01A */   li    $a0, 45082
/* 0C6B14 7F091FE4 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6B18 7F091FE8 00402025 */   move  $a0, $v0
/* 0C6B1C 7F091FEC 1000010F */  b     .L7F09242C
/* 0C6B20 7F091FF0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_10x_health:
/* 0C6B24 7F091FF4 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C6B28 7F091FF8 8C42A0B0 */  lw    $v0, %lo(ptr_BONDdata)($v0)
/* 0C6B2C 7F091FFC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6B30 7F092000 44810000 */  mtc1  $at, $f0
/* 0C6B34 7F092004 C4482A3C */  lwc1  $f8, 0x2a3c($v0)
/* 0C6B38 7F092008 46080032 */  c.eq.s $f0, $f8
/* 0C6B3C 7F09200C 00000000 */  nop   
/* 0C6B40 7F092010 45010006 */  bc1t  .L7F09202C
/* 0C6B44 7F092014 00000000 */   nop   
/* 0C6B48 7F092018 C44A00DC */  lwc1  $f10, 0xdc($v0)
/* 0C6B4C 7F09201C 4600503C */  c.lt.s $f10, $f0
/* 0C6B50 7F092020 00000000 */  nop   
/* 0C6B54 7F092024 45020101 */  bc1fl .L7F09242C
/* 0C6B58 7F092028 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F09202C:
/* 0C6B5C 7F09202C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6B60 7F092030 3404B01B */   li    $a0, 45083
/* 0C6B64 7F092034 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6B68 7F092038 00402025 */   move  $a0, $v0
/* 0C6B6C 7F09203C 3C028008 */  lui   $v0, %hi(ptr_BONDdata) # $v0, 0x8008
/* 0C6B70 7F092040 2442A0B0 */  addiu $v0, %lo(ptr_BONDdata) # addiu $v0, $v0, -0x5f50
/* 0C6B74 7F092044 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6B78 7F092048 44818000 */  mtc1  $at, $f16
/* 0C6B7C 7F09204C 8C4D0000 */  lw    $t5, ($v0)
/* 0C6B80 7F092050 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0C6B84 7F092054 44819000 */  mtc1  $at, $f18
/* 0C6B88 7F092058 E5B000DC */  swc1  $f16, 0xdc($t5)
/* 0C6B8C 7F09205C 8C4E0000 */  lw    $t6, ($v0)
/* 0C6B90 7F092060 100000F1 */  b     .L7F092428
/* 0C6B94 7F092064 E5D22A3C */   swc1  $f18, 0x2a3c($t6)
cheats_cheat_magnum:
/* 0C6B98 7F092068 24010001 */  li    $at, 1
/* 0C6B9C 7F09206C 544100EF */  bnel  $v0, $at, .L7F09242C
/* 0C6BA0 7F092070 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BA4 7F092074 0FC23122 */  jal   add_item_to_inventory
/* 0C6BA8 7F092078 24040012 */   li    $a0, 18
/* 0C6BAC 7F09207C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6BB0 7F092080 2404000C */   li    $a0, 12
/* 0C6BB4 7F092084 2404000C */  li    $a0, 12
/* 0C6BB8 7F092088 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6BBC 7F09208C 00402825 */   move  $a1, $v0
/* 0C6BC0 7F092090 100000E6 */  b     .L7F09242C
/* 0C6BC4 7F092094 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_laser:
/* 0C6BC8 7F092098 24010001 */  li    $at, 1
/* 0C6BCC 7F09209C 544100E3 */  bnel  $v0, $at, .L7F09242C
/* 0C6BD0 7F0920A0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BD4 7F0920A4 0FC23122 */  jal   add_item_to_inventory
/* 0C6BD8 7F0920A8 24040016 */   li    $a0, 22
/* 0C6BDC 7F0920AC 100000DF */  b     .L7F09242C
/* 0C6BE0 7F0920B0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldengun:
/* 0C6BE4 7F0920B4 24010001 */  li    $at, 1
/* 0C6BE8 7F0920B8 544100DC */  bnel  $v0, $at, .L7F09242C
/* 0C6BEC 7F0920BC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BF0 7F0920C0 0FC23122 */  jal   add_item_to_inventory
/* 0C6BF4 7F0920C4 24040013 */   li    $a0, 19
/* 0C6BF8 7F0920C8 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6BFC 7F0920CC 2404000D */   li    $a0, 13
/* 0C6C00 7F0920D0 2404000D */  li    $a0, 13
/* 0C6C04 7F0920D4 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C08 7F0920D8 00402825 */   move  $a1, $v0
/* 0C6C0C 7F0920DC 100000D3 */  b     .L7F09242C
/* 0C6C10 7F0920E0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_silverpp7:
/* 0C6C14 7F0920E4 24010001 */  li    $at, 1
/* 0C6C18 7F0920E8 544100D0 */  bnel  $v0, $at, .L7F09242C
/* 0C6C1C 7F0920EC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6C20 7F0920F0 0FC23122 */  jal   add_item_to_inventory
/* 0C6C24 7F0920F4 24040014 */   li    $a0, 20
/* 0C6C28 7F0920F8 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6C2C 7F0920FC 24040001 */   li    $a0, 1
/* 0C6C30 7F092100 24040001 */  li    $a0, 1
/* 0C6C34 7F092104 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C38 7F092108 00402825 */   move  $a1, $v0
/* 0C6C3C 7F09210C 100000C7 */  b     .L7F09242C
/* 0C6C40 7F092110 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldpp7:
/* 0C6C44 7F092114 24010001 */  li    $at, 1
/* 0C6C48 7F092118 544100C4 */  bnel  $v0, $at, .L7F09242C
/* 0C6C4C 7F09211C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6C50 7F092120 0FC23122 */  jal   add_item_to_inventory
/* 0C6C54 7F092124 24040015 */   li    $a0, 21
/* 0C6C58 7F092128 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6C5C 7F09212C 24040001 */   li    $a0, 1
/* 0C6C60 7F092130 24040001 */  li    $a0, 1
/* 0C6C64 7F092134 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C68 7F092138 00402825 */   move  $a1, $v0
/* 0C6C6C 7F09213C 100000BB */  b     .L7F09242C
/* 0C6C70 7F092140 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invisibility_mp:
/* 0C6C74 7F092144 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C6C78 7F092148 44816000 */  mtc1  $at, $f12
/* 0C6C7C 7F09214C 3C018005 */  lui   $at, %hi(D_800573D8) # $at, 0x8005
/* 0C6C80 7F092150 0FC20284 */  jal   set_curplayer_fade
/* 0C6C84 7F092154 C42E73D8 */   lwc1  $f14, %lo(D_800573D8)($at)
/* 0C6C88 7F092158 100000B4 */  b     .L7F09242C
/* 0C6C8C 7F09215C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_fast:
/* 0C6C90 7F092160 0FC24406 */  jal   get_debug_fast_bond_flag
/* 0C6C94 7F092164 00000000 */   nop   
/* 0C6C98 7F092168 544000B0 */  bnezl $v0, .L7F09242C
/* 0C6C9C 7F09216C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6CA0 7F092170 0FC30776 */  jal   get_textptr_for_textID
/* 0C6CA4 7F092174 3404B01D */   li    $a0, 45085
/* 0C6CA8 7F092178 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6CAC 7F09217C 00402025 */   move  $a0, $v0
/* 0C6CB0 7F092180 0FC24409 */  jal   set_debug_fast_bond_flag
/* 0C6CB4 7F092184 24040001 */   li    $a0, 1
/* 0C6CB8 7F092188 100000A8 */  b     .L7F09242C
/* 0C6CBC 7F09218C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_pos:
/* 0C6CC0 7F092190 0FC243E2 */  jal   get_debug_testingmanpos_flag
/* 0C6CC4 7F092194 00000000 */   nop   
/* 0C6CC8 7F092198 544000A4 */  bnezl $v0, .L7F09242C
/* 0C6CCC 7F09219C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6CD0 7F0921A0 0FC243E5 */  jal   set_debug_testingmanpos_flag
/* 0C6CD4 7F0921A4 24040001 */   li    $a0, 1
/* 0C6CD8 7F0921A8 100000A0 */  b     .L7F09242C
/* 0C6CDC 7F0921AC 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_fast_ani:
/* 0C6CE0 7F0921B0 0FC08179 */  jal   get_animation_rate
/* 0C6CE4 7F0921B4 00000000 */   nop   
/* 0C6CE8 7F0921B8 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C6CEC 7F0921BC 44812000 */  mtc1  $at, $f4
/* 0C6CF0 7F0921C0 00000000 */  nop   
/* 0C6CF4 7F0921C4 4604003C */  c.lt.s $f0, $f4
/* 0C6CF8 7F0921C8 00000000 */  nop   
/* 0C6CFC 7F0921CC 45020097 */  bc1fl .L7F09242C
/* 0C6D00 7F0921D0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6D04 7F0921D4 0FC30776 */  jal   get_textptr_for_textID
/* 0C6D08 7F0921D8 3404B034 */   li    $a0, 45108
/* 0C6D0C 7F0921DC 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6D10 7F0921E0 00402025 */   move  $a0, $v0
/* 0C6D14 7F0921E4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C6D18 7F0921E8 44816000 */  mtc1  $at, $f12
/* 0C6D1C 7F0921EC 0FC08150 */  jal   animation_speed_related
/* 0C6D20 7F0921F0 00000000 */   nop   
/* 0C6D24 7F0921F4 1000008D */  b     .L7F09242C
/* 0C6D28 7F0921F8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_slow_ani:
/* 0C6D2C 7F0921FC 0FC08179 */  jal   get_animation_rate
/* 0C6D30 7F092200 00000000 */   nop   
/* 0C6D34 7F092204 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C6D38 7F092208 44813000 */  mtc1  $at, $f6
/* 0C6D3C 7F09220C 00000000 */  nop   
/* 0C6D40 7F092210 4600303C */  c.lt.s $f6, $f0
/* 0C6D44 7F092214 00000000 */  nop   
/* 0C6D48 7F092218 45020084 */  bc1fl .L7F09242C
/* 0C6D4C 7F09221C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6D50 7F092220 0FC30776 */  jal   get_textptr_for_textID
/* 0C6D54 7F092224 3404B032 */   li    $a0, 45106
/* 0C6D58 7F092228 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6D5C 7F09222C 00402025 */   move  $a0, $v0
/* 0C6D60 7F092230 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C6D64 7F092234 44816000 */  mtc1  $at, $f12
/* 0C6D68 7F092238 0FC08150 */  jal   animation_speed_related
/* 0C6D6C 7F09223C 00000000 */   nop   
/* 0C6D70 7F092240 1000007A */  b     .L7F09242C
/* 0C6D74 7F092244 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_rockets:
/* 0C6D78 7F092248 24010001 */  li    $at, 1
/* 0C6D7C 7F09224C 14410076 */  bne   $v0, $at, .L7F092428
/* 0C6D80 7F092250 24040019 */   li    $a0, 25
/* 0C6D84 7F092254 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6D88 7F092258 24050019 */   li    $a1, 25
/* 0C6D8C 7F09225C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6D90 7F092260 24040006 */   li    $a0, 6
/* 0C6D94 7F092264 24040006 */  li    $a0, 6
/* 0C6D98 7F092268 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6D9C 7F09226C 00402825 */   move  $a1, $v0
/* 0C6DA0 7F092270 1000006E */  b     .L7F09242C
/* 0C6DA4 7F092274 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_grenade_launch:
/* 0C6DA8 7F092278 24010001 */  li    $at, 1
/* 0C6DAC 7F09227C 1441006A */  bne   $v0, $at, .L7F092428
/* 0C6DB0 7F092280 24040018 */   li    $a0, 24
/* 0C6DB4 7F092284 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6DB8 7F092288 24050018 */   li    $a1, 24
/* 0C6DBC 7F09228C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6DC0 7F092290 2404000B */   li    $a0, 11
/* 0C6DC4 7F092294 2404000B */  li    $a0, 11
/* 0C6DC8 7F092298 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6DCC 7F09229C 00402825 */   move  $a1, $v0
/* 0C6DD0 7F0922A0 10000062 */  b     .L7F09242C
/* 0C6DD4 7F0922A4 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_rcp90:
/* 0C6DD8 7F0922A8 24010001 */  li    $at, 1
/* 0C6DDC 7F0922AC 1441005E */  bne   $v0, $at, .L7F092428
/* 0C6DE0 7F0922B0 2404000E */   li    $a0, 14
/* 0C6DE4 7F0922B4 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6DE8 7F0922B8 2405000E */   li    $a1, 14
/* 0C6DEC 7F0922BC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6DF0 7F0922C0 24040001 */   li    $a0, 1
/* 0C6DF4 7F0922C4 24040001 */  li    $a0, 1
/* 0C6DF8 7F0922C8 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6DFC 7F0922CC 00402825 */   move  $a1, $v0
/* 0C6E00 7F0922D0 10000056 */  b     .L7F09242C
/* 0C6E04 7F0922D4 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_throwing_knife:
/* 0C6E08 7F0922D8 24010001 */  li    $at, 1
/* 0C6E0C 7F0922DC 14410052 */  bne   $v0, $at, .L7F092428
/* 0C6E10 7F0922E0 24040003 */   li    $a0, 3
/* 0C6E14 7F0922E4 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E18 7F0922E8 24050003 */   li    $a1, 3
/* 0C6E1C 7F0922EC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6E20 7F0922F0 2404000A */   li    $a0, 10
/* 0C6E24 7F0922F4 2404000A */  li    $a0, 10
/* 0C6E28 7F0922F8 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6E2C 7F0922FC 00402825 */   move  $a1, $v0
/* 0C6E30 7F092300 1000004A */  b     .L7F09242C
/* 0C6E34 7F092304 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_hunting_knife:
/* 0C6E38 7F092308 24010001 */  li    $at, 1
/* 0C6E3C 7F09230C 14410046 */  bne   $v0, $at, .L7F092428
/* 0C6E40 7F092310 24040002 */   li    $a0, 2
/* 0C6E44 7F092314 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E48 7F092318 24050002 */   li    $a1, 2
/* 0C6E4C 7F09231C 10000043 */  b     .L7F09242C
/* 0C6E50 7F092320 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_laser:
/* 0C6E54 7F092324 24010001 */  li    $at, 1
/* 0C6E58 7F092328 1441003F */  bne   $v0, $at, .L7F092428
/* 0C6E5C 7F09232C 24040016 */   li    $a0, 22
/* 0C6E60 7F092330 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E64 7F092334 24050016 */   li    $a1, 22
/* 0C6E68 7F092338 1000003C */  b     .L7F09242C
/* 0C6E6C 7F09233C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlockcheat:
/* 0C6E70 7F092340 3C048003 */  lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
/* 0C6E74 7F092344 8C84A8E8 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 0C6E78 7F092348 24C5FFDD */  addiu $a1, $a2, -0x23
/* 0C6E7C 7F09234C 04800036 */  bltz  $a0, .L7F092428
/* 0C6E80 7F092350 28810004 */   slti  $at, $a0, 4
/* 0C6E84 7F092354 50200035 */  beql  $at, $zero, .L7F09242C
/* 0C6E88 7F092358 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6E8C 7F09235C 0FC079D8 */  jal   sub_GAME_7F01E760
/* 0C6E90 7F092360 00000000 */   nop   
/* 0C6E94 7F092364 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C6E98 7F092368 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6E9C 7F09236C 2405009F */  li    $a1, 159
/* 0C6EA0 7F092370 0C002382 */  jal   play_sfx_a1
/* 0C6EA4 7F092374 00003025 */   move  $a2, $zero
/* 0C6EA8 7F092378 1000002C */  b     .L7F09242C
/* 0C6EAC 7F09237C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlocklevel:
/* 0C6EB0 7F092380 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C6EB4 7F092384 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
/* 0C6EB8 7F092388 8C440000 */  lw    $a0, ($v0)
/* 0C6EBC 7F09238C 24C8FFC9 */  addiu $t0, $a2, -0x37
/* 0C6EC0 7F092390 04800025 */  bltz  $a0, .L7F092428
/* 0C6EC4 7F092394 28810004 */   slti  $at, $a0, 4
/* 0C6EC8 7F092398 10200023 */  beqz  $at, .L7F092428
/* 0C6ECC 7F09239C 00001825 */   move  $v1, $zero
/* 0C6ED0 7F0923A0 19000014 */  blez  $t0, .L7F0923F4
/* 0C6ED4 7F0923A4 00002825 */   move  $a1, $zero
.L7F0923A8:
/* 0C6ED8 7F0923A8 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C6EDC 7F0923AC 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
/* 0C6EE0 7F0923B0 8C440000 */  lw    $a0, ($v0)
/* 0C6EE4 7F0923B4 00003025 */  move  $a2, $zero
/* 0C6EE8 7F0923B8 AFA30018 */  sw    $v1, 0x18($sp)
/* 0C6EEC 7F0923BC AFA5001C */  sw    $a1, 0x1c($sp)
/* 0C6EF0 7F0923C0 0FC078B0 */  jal   check_unlock_complete_for_eeprom_stagecomplete_difficulty
/* 0C6EF4 7F0923C4 AFA80020 */   sw    $t0, 0x20($sp)
/* 0C6EF8 7F0923C8 24010003 */  li    $at, 3
/* 0C6EFC 7F0923CC 8FA30018 */  lw    $v1, 0x18($sp)
/* 0C6F00 7F0923D0 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0C6F04 7F0923D4 14410002 */  bne   $v0, $at, .L7F0923E0
/* 0C6F08 7F0923D8 8FA80020 */   lw    $t0, 0x20($sp)
/* 0C6F0C 7F0923DC 24630001 */  addiu $v1, $v1, 1
.L7F0923E0:
/* 0C6F10 7F0923E0 24A50001 */  addiu $a1, $a1, 1
/* 0C6F14 7F0923E4 14A8FFF0 */  bne   $a1, $t0, .L7F0923A8
/* 0C6F18 7F0923E8 00000000 */   nop   
/* 0C6F1C 7F0923EC 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C6F20 7F0923F0 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
.L7F0923F4:
/* 0C6F24 7F0923F4 246F0001 */  addiu $t7, $v1, 1
/* 0C6F28 7F0923F8 150F000B */  bne   $t0, $t7, .L7F092428
/* 0C6F2C 7F0923FC 2505FFFF */   addiu $a1, $t0, -1
/* 0C6F30 7F092400 3C0705F5 */  lui   $a3, (0x05F5E0FF >> 16) # lui $a3, 0x5f5
/* 0C6F34 7F092404 34E7E0FF */  ori   $a3, (0x05F5E0FF & 0xFFFF) # ori $a3, $a3, 0xe0ff
/* 0C6F38 7F092408 8C440000 */  lw    $a0, ($v0)
/* 0C6F3C 7F09240C 0FC0797E */  jal   unlock_stage_in_folder_on_difficulty
/* 0C6F40 7F092410 00003025 */   move  $a2, $zero
/* 0C6F44 7F092414 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C6F48 7F092418 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6F4C 7F09241C 2405009F */  li    $a1, 159
/* 0C6F50 7F092420 0C002382 */  jal   play_sfx_a1
/* 0C6F54 7F092424 00003025 */   move  $a2, $zero
cheats_debug_return_saved_ra:
.L7F092428:
/* 0C6F58 7F092428 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F09242C:
/* 0C6F5C 7F09242C 27BD0040 */  addiu $sp, $sp, 0x40
/* 0C6F60 7F092430 03E00008 */  jr    $ra
/* 0C6F64 7F092434 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F092438(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F092438
/* 0C6F68 7F092438 00047100 */  sll   $t6, $a0, 4
/* 0C6F6C 7F09243C 3C0F8004 */  lui   $t7, 0x8004
/* 0C6F70 7F092440 01EE7821 */  addu  $t7, $t7, $t6
/* 0C6F74 7F092444 8DEFF808 */  lw    $t7, -0x7f8($t7)
/* 0C6F78 7F092448 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C6F7C 7F09244C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6F80 7F092450 AFA40020 */  sw    $a0, 0x20($sp)
/* 0C6F84 7F092454 0FC26C54 */  jal   get_cur_playernum
/* 0C6F88 7F092458 AFAF001C */   sw    $t7, 0x1c($sp)
/* 0C6F8C 7F09245C 0FC26919 */  jal   get_num_players
/* 0C6F90 7F092460 AFA20018 */   sw    $v0, 0x18($sp)
/* 0C6F94 7F092464 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0C6F98 7F092468 8FA40020 */  lw    $a0, 0x20($sp)
/* 0C6F9C 7F09246C 30780010 */  andi  $t8, $v1, 0x10
/* 0C6FA0 7F092470 17000010 */  bnez  $t8, .L7F0924B4
/* 0C6FA4 7F092474 30790020 */   andi  $t9, $v1, 0x20
/* 0C6FA8 7F092478 1720000B */  bnez  $t9, .L7F0924A8
/* 0C6FAC 7F09247C 3C088008 */   lui   $t0, %hi(off_CODE_bss_80079E30) # $t0, 0x8008
/* 0C6FB0 7F092480 8FAA0018 */  lw    $t2, 0x18($sp)
/* 0C6FB4 7F092484 25089E30 */  addiu $t0, %lo(off_CODE_bss_80079E30) # addiu $t0, $t0, -0x61d0
/* 0C6FB8 7F092488 00881821 */  addu  $v1, $a0, $t0
/* 0C6FBC 7F09248C 90690000 */  lbu   $t1, ($v1)
/* 0C6FC0 7F092490 240B0001 */  li    $t3, 1
/* 0C6FC4 7F092494 014B6004 */  sllv  $t4, $t3, $t2
/* 0C6FC8 7F092498 01806827 */  not   $t5, $t4
/* 0C6FCC 7F09249C 012D7024 */  and   $t6, $t1, $t5
/* 0C6FD0 7F0924A0 10000004 */  b     .L7F0924B4
/* 0C6FD4 7F0924A4 A06E0000 */   sb    $t6, ($v1)
.L7F0924A8:
/* 0C6FD8 7F0924A8 3C018008 */  lui   $at, 0x8008
/* 0C6FDC 7F0924AC 00240821 */  addu  $at, $at, $a0
/* 0C6FE0 7F0924B0 A0209E30 */  sb    $zero, -0x61d0($at)
.L7F0924B4:
/* 0C6FE4 7F0924B4 248FFFFF */  addiu $t7, $a0, -1
/* 0C6FE8 7F0924B8 2DE1004A */  sltiu $at, $t7, 0x4a
/* 0C6FEC 7F0924BC 1020007C */  beqz  $at, .L7F0926B0
/* 0C6FF0 7F0924C0 000F7880 */   sll   $t7, $t7, 2
/* 0C6FF4 7F0924C4 3C018005 */  lui   $at, 0x8005
/* 0C6FF8 7F0924C8 002F0821 */  addu  $at, $at, $t7
/* 0C6FFC 7F0924CC 8C2F73DC */  lw    $t7, 0x73dc($at)
/* 0C7000 7F0924D0 01E00008 */  jr    $t7
/* 0C7004 7F0924D4 00000000 */   nop   
cheat_button_invincibility:
/* 0C7008 7F0924D8 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C700C 7F0924DC 00000000 */   nop   
/* 0C7010 7F0924E0 50400074 */  beql  $v0, $zero, .L7F0926B4
/* 0C7014 7F0924E4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7018 7F0924E8 0FC30776 */  jal   get_textptr_for_textID
/* 0C701C 7F0924EC 3404B01E */   li    $a0, 45086
/* 0C7020 7F0924F0 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7024 7F0924F4 00402025 */   move  $a0, $v0
/* 0C7028 7F0924F8 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C702C 7F0924FC 00002025 */   move  $a0, $zero
/* 0C7030 7F092500 1000006C */  b     .L7F0926B4
/* 0C7034 7F092504 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_all_guns:
/* 0C7038 7F092508 0FC230AB */  jal   get_BONDdata_allguns_flag
/* 0C703C 7F09250C 00000000 */   nop   
/* 0C7040 7F092510 50400068 */  beql  $v0, $zero, .L7F0926B4
/* 0C7044 7F092514 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7048 7F092518 0FC30776 */  jal   get_textptr_for_textID
/* 0C704C 7F09251C 3404B01F */   li    $a0, 45087
/* 0C7050 7F092520 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7054 7F092524 00402025 */   move  $a0, $v0
/* 0C7058 7F092528 0FC230A7 */  jal   set_BONDdata_allguns_flag
/* 0C705C 7F09252C 00002025 */   move  $a0, $zero
/* 0C7060 7F092530 10000060 */  b     .L7F0926B4
/* 0C7064 7F092534 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_line_mode:
/* 0C7068 7F092538 0FC243FA */  jal   set_linemode_flag
/* 0C706C 7F09253C 00002025 */   move  $a0, $zero
/* 0C7070 7F092540 1000005C */  b     .L7F0926B4
/* 0C7074 7F092544 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_unknown:
/* 0C7078 7F092548 0FC227DD */  jal   get_invisible_to_guards_flag
/* 0C707C 7F09254C 00000000 */   nop   
/* 0C7080 7F092550 54400058 */  bnezl $v0, .L7F0926B4
/* 0C7084 7F092554 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7088 7F092558 0FC30776 */  jal   get_textptr_for_textID
/* 0C708C 7F09255C 3404B020 */   li    $a0, 45088
/* 0C7090 7F092560 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7094 7F092564 00402025 */   move  $a0, $v0
/* 0C7098 7F092568 0FC227DA */  jal   set_invisible_to_guards_flag
/* 0C709C 7F09256C 24040001 */   li    $a0, 1
/* 0C70A0 7F092570 10000050 */  b     .L7F0926B4
/* 0C70A4 7F092574 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_infinite_ammo:
/* 0C70A8 7F092578 0FC30776 */  jal   get_textptr_for_textID
/* 0C70AC 7F09257C 3404B022 */   li    $a0, 45090
/* 0C70B0 7F092580 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C70B4 7F092584 00402025 */   move  $a0, $v0
/* 0C70B8 7F092588 1000004A */  b     .L7F0926B4
/* 0C70BC 7F09258C 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_dkmode:
/* 0C70C0 7F092590 0FC30776 */  jal   get_textptr_for_textID
/* 0C70C4 7F092594 3404B023 */   li    $a0, 45091
/* 0C70C8 7F092598 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C70CC 7F09259C 00402025 */   move  $a0, $v0
/* 0C70D0 7F0925A0 0FC249FD */  jal   sub_GAME_7F0927F4
/* 0C70D4 7F0925A4 00002025 */   move  $a0, $zero
/* 0C70D8 7F0925A8 10000042 */  b     .L7F0926B4
/* 0C70DC 7F0925AC 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_unknown_0:
/* 0C70E0 7F0925B0 24010001 */  li    $at, 1
/* 0C70E4 7F0925B4 1441003E */  bne   $v0, $at, .L7F0926B0
/* 0C70E8 7F0925B8 3C188008 */   lui   $t8, %hi(cur_player_stat_ptr) # $t8, 0x8008
/* 0C70EC 7F0925BC 8F18A0B4 */  lw    $t8, %lo(cur_player_stat_ptr)($t8)
/* 0C70F0 7F0925C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C70F4 7F0925C4 44812000 */  mtc1  $at, $f4
/* 0C70F8 7F0925C8 C7060064 */  lwc1  $f6, 0x64($t8)
/* 0C70FC 7F0925CC 46062032 */  c.eq.s $f4, $f6
/* 0C7100 7F0925D0 00000000 */  nop   
/* 0C7104 7F0925D4 45030037 */  bc1tl .L7F0926B4
/* 0C7108 7F0925D8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C710C 7F0925DC 0FC30776 */  jal   get_textptr_for_textID
/* 0C7110 7F0925E0 3404B024 */   li    $a0, 45092
/* 0C7114 7F0925E4 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7118 7F0925E8 00402025 */   move  $a0, $v0
/* 0C711C 7F0925EC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7120 7F0925F0 3C198008 */  lui   $t9, %hi(cur_player_stat_ptr) # $t9, 0x8008
/* 0C7124 7F0925F4 8F39A0B4 */  lw    $t9, %lo(cur_player_stat_ptr)($t9)
/* 0C7128 7F0925F8 44814000 */  mtc1  $at, $f8
/* 0C712C 7F0925FC 3C088008 */  lui   $t0, %hi(ptr_BONDdata) # $t0, 0x8008
/* 0C7130 7F092600 E7280064 */  swc1  $f8, 0x64($t9)
/* 0C7134 7F092604 8D08A0B0 */  lw    $t0, %lo(ptr_BONDdata)($t0)
/* 0C7138 7F092608 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0C713C 7F09260C 50800029 */  beql  $a0, $zero, .L7F0926B4
/* 0C7140 7F092610 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7144 7F092614 C4800014 */  lwc1  $f0, 0x14($a0)
/* 0C7148 7F092618 46000280 */  add.s $f10, $f0, $f0
/* 0C714C 7F09261C 44055000 */  mfc1  $a1, $f10
/* 0C7150 7F092620 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C7154 7F092624 00000000 */   nop   
/* 0C7158 7F092628 10000022 */  b     .L7F0926B4
/* 0C715C 7F09262C 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_paintball:
/* 0C7160 7F092630 0FC30776 */  jal   get_textptr_for_textID
/* 0C7164 7F092634 3404B025 */   li    $a0, 45093
/* 0C7168 7F092638 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C716C 7F09263C 00402025 */   move  $a0, $v0
/* 0C7170 7F092640 1000001C */  b     .L7F0926B4
/* 0C7174 7F092644 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_mp_invis:
/* 0C7178 7F092648 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C717C 7F09264C 44816000 */  mtc1  $at, $f12
/* 0C7180 7F092650 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7184 7F092654 44817000 */  mtc1  $at, $f14
/* 0C7188 7F092658 0FC20284 */  jal   set_curplayer_fade
/* 0C718C 7F09265C 00000000 */   nop   
/* 0C7190 7F092660 10000014 */  b     .L7F0926B4
/* 0C7194 7F092664 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_fast_mode:
/* 0C7198 7F092668 0FC24406 */  jal   get_debug_fast_bond_flag
/* 0C719C 7F09266C 00000000 */   nop   
/* 0C71A0 7F092670 50400010 */  beql  $v0, $zero, .L7F0926B4
/* 0C71A4 7F092674 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C71A8 7F092678 0FC30776 */  jal   get_textptr_for_textID
/* 0C71AC 7F09267C 3404B027 */   li    $a0, 45095
/* 0C71B0 7F092680 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C71B4 7F092684 00402025 */   move  $a0, $v0
/* 0C71B8 7F092688 0FC24409 */  jal   set_debug_fast_bond_flag
/* 0C71BC 7F09268C 00002025 */   move  $a0, $zero
/* 0C71C0 7F092690 10000008 */  b     .L7F0926B4
/* 0C71C4 7F092694 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_debug_mode:
/* 0C71C8 7F092698 0FC243E2 */  jal   get_debug_testingmanpos_flag
/* 0C71CC 7F09269C 00000000 */   nop   
/* 0C71D0 7F0926A0 50400004 */  beql  $v0, $zero, .L7F0926B4
/* 0C71D4 7F0926A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C71D8 7F0926A8 0FC243E5 */  jal   set_debug_testingmanpos_flag
/* 0C71DC 7F0926AC 00002025 */   move  $a0, $zero
cheat_button_default:
.L7F0926B0:
/* 0C71E0 7F0926B0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0926B4:
/* 0C71E4 7F0926B4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C71E8 7F0926B8 03E00008 */  jr    $ra
/* 0C71EC 7F0926BC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0926C0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0926C0
/* 0C71F0 7F0926C0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C71F4 7F0926C4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C71F8 7F0926C8 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C71FC 7F0926CC AFB30024 */  sw    $s3, 0x24($sp)
/* 0C7200 7F0926D0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C7204 7F0926D4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C7208 7F0926D8 0FC26919 */  jal   get_num_players
/* 0C720C 7F0926DC AFB00018 */   sw    $s0, 0x18($sp)
/* 0C7210 7F0926E0 0FC26C54 */  jal   get_cur_playernum
/* 0C7214 7F0926E4 0040A025 */   move  $s4, $v0
/* 0C7218 7F0926E8 AFA20030 */  sw    $v0, 0x30($sp)
/* 0C721C 7F0926EC 1A800017 */  blez  $s4, .L7F09274C
/* 0C7220 7F0926F0 00009825 */   move  $s3, $zero
/* 0C7224 7F0926F4 2412004B */  li    $s2, 75
.L7F0926F8:
/* 0C7228 7F0926F8 0FC26C43 */  jal   set_cur_player
/* 0C722C 7F0926FC 02602025 */   move  $a0, $s3
/* 0C7230 7F092700 3C118004 */  lui   $s1, %hi(D_8003F81C) # $s1, 0x8004
/* 0C7234 7F092704 2631F81C */  addiu $s1, %lo(D_8003F81C) # addiu $s1, $s1, -0x7e4
/* 0C7238 7F092708 24100001 */  li    $s0, 1
.L7F09270C:
/* 0C723C 7F09270C 8E2EFFFC */  lw    $t6, -4($s1)
/* 0C7240 7F092710 31CF0040 */  andi  $t7, $t6, 0x40
/* 0C7244 7F092714 51E00008 */  beql  $t7, $zero, .L7F092738
/* 0C7248 7F092718 26100001 */   addiu $s0, $s0, 1
/* 0C724C 7F09271C 0FC249EF */  jal   sub_GAME_7F0927BC
/* 0C7250 7F092720 02002025 */   move  $a0, $s0
/* 0C7254 7F092724 50400004 */  beql  $v0, $zero, .L7F092738
/* 0C7258 7F092728 26100001 */   addiu $s0, $s0, 1
/* 0C725C 7F09272C 0FC2490E */  jal   sub_GAME_7F092438
/* 0C7260 7F092730 02002025 */   move  $a0, $s0
/* 0C7264 7F092734 26100001 */  addiu $s0, $s0, 1
.L7F092738:
/* 0C7268 7F092738 1612FFF4 */  bne   $s0, $s2, .L7F09270C
/* 0C726C 7F09273C 26310010 */   addiu $s1, $s1, 0x10
/* 0C7270 7F092740 26730001 */  addiu $s3, $s3, 1
/* 0C7274 7F092744 1674FFEC */  bne   $s3, $s4, .L7F0926F8
/* 0C7278 7F092748 00000000 */   nop   
.L7F09274C:
/* 0C727C 7F09274C 0FC26C43 */  jal   set_cur_player
/* 0C7280 7F092750 8FA40030 */   lw    $a0, 0x30($sp)
/* 0C7284 7F092754 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C7288 7F092758 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C728C 7F09275C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C7290 7F092760 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C7294 7F092764 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C7298 7F092768 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C729C 7F09276C 03E00008 */  jr    $ra
/* 0C72A0 7F092770 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F092774(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F092774
/* 0C72A4 7F092774 00047100 */  sll   $t6, $a0, 4
/* 0C72A8 7F092778 3C028004 */  lui   $v0, 0x8004
/* 0C72AC 7F09277C 004E1021 */  addu  $v0, $v0, $t6
/* 0C72B0 7F092780 9442F804 */  lhu   $v0, -0x7fc($v0)
/* 0C72B4 7F092784 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C72B8 7F092788 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C72BC 7F09278C 10400005 */  beqz  $v0, .L7F0927A4
/* 0C72C0 7F092790 00000000 */   nop   
/* 0C72C4 7F092794 0FC30776 */  jal   get_textptr_for_textID
/* 0C72C8 7F092798 00402025 */   move  $a0, $v0
/* 0C72CC 7F09279C 10000004 */  b     .L7F0927B0
/* 0C72D0 7F0927A0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0927A4:
/* 0C72D4 7F0927A4 0FC30776 */  jal   get_textptr_for_textID
/* 0C72D8 7F0927A8 3404B028 */   li    $a0, 45096
/* 0C72DC 7F0927AC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0927B0:
/* 0C72E0 7F0927B0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C72E4 7F0927B4 03E00008 */  jr    $ra
/* 0C72E8 7F0927B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0927BC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0927BC
/* 0C72EC 7F0927BC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C72F0 7F0927C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C72F4 7F0927C4 0FC26C54 */  jal   get_cur_playernum
/* 0C72F8 7F0927C8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C72FC 7F0927CC 8FAE0018 */  lw    $t6, 0x18($sp)
/* 0C7300 7F0927D0 3C0F8008 */  lui   $t7, 0x8008
/* 0C7304 7F0927D4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C7308 7F0927D8 01EE7821 */  addu  $t7, $t7, $t6
/* 0C730C 7F0927DC 91EF9E30 */  lbu   $t7, -0x61d0($t7)
/* 0C7310 7F0927E0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C7314 7F0927E4 004F1007 */  srav  $v0, $t7, $v0
/* 0C7318 7F0927E8 30580001 */  andi  $t8, $v0, 1
/* 0C731C 7F0927EC 03E00008 */  jr    $ra
/* 0C7320 7F0927F0 03001025 */   move  $v0, $t8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0927F4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0927F4
/* 0C7324 7F0927F4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C7328 7F0927F8 AFB10024 */  sw    $s1, 0x24($sp)
/* 0C732C 7F0927FC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C7330 7F092800 AFB00020 */  sw    $s0, 0x20($sp)
/* 0C7334 7F092804 3C118003 */  lui   $s1, %hi(ptr_guard_data) # $s1, 0x8003
/* 0C7338 7F092808 00808025 */  move  $s0, $a0
/* 0C733C 7F09280C AFB20028 */  sw    $s2, 0x28($sp)
/* 0C7340 7F092810 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0C7344 7F092814 0FC07D4C */  jal   get_numguards
/* 0C7348 7F092818 8E31CC64 */   lw    $s1, %lo(ptr_guard_data)($s1)
/* 0C734C 7F09281C 12000004 */  beqz  $s0, .L7F092830
/* 0C7350 7F092820 00409025 */   move  $s2, $v0
/* 0C7354 7F092824 3C018005 */  lui   $at, %hi(D_80057504) # $at, 0x8005
/* 0C7358 7F092828 10000004 */  b     .L7F09283C
/* 0C735C 7F09282C C4347504 */   lwc1  $f20, %lo(D_80057504)($at)
.L7F092830:
/* 0C7360 7F092830 3C013FA0 */  li    $at, 0x3FA00000 # 1.250000
/* 0C7364 7F092834 4481A000 */  mtc1  $at, $f20
/* 0C7368 7F092838 00000000 */  nop   
.L7F09283C:
/* 0C736C 7F09283C 1840000C */  blez  $v0, .L7F092870
/* 0C7370 7F092840 00008025 */   move  $s0, $zero
.L7F092844:
/* 0C7374 7F092844 8E24001C */  lw    $a0, 0x1c($s1)
/* 0C7378 7F092848 50800007 */  beql  $a0, $zero, .L7F092868
/* 0C737C 7F09284C 26100001 */   addiu $s0, $s0, 1
/* 0C7380 7F092850 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C7384 7F092854 46142182 */  mul.s $f6, $f4, $f20
/* 0C7388 7F092858 44053000 */  mfc1  $a1, $f6
/* 0C738C 7F09285C 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C7390 7F092860 00000000 */   nop   
/* 0C7394 7F092864 26100001 */  addiu $s0, $s0, 1
.L7F092868:
/* 0C7398 7F092868 1612FFF6 */  bne   $s0, $s2, .L7F092844
/* 0C739C 7F09286C 263101DC */   addiu $s1, $s1, 0x1dc
.L7F092870:
/* 0C73A0 7F092870 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C73A4 7F092874 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0C73A8 7F092878 8FB00020 */  lw    $s0, 0x20($sp)
/* 0C73AC 7F09287C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0C73B0 7F092880 8FB20028 */  lw    $s2, 0x28($sp)
/* 0C73B4 7F092884 03E00008 */  jr    $ra
/* 0C73B8 7F092888 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif


