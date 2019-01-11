#include "ultra64.h"
#include "game/ob.h"

//bss
u8 ptr_resource_data[0x14];
u8 ptr_res_data_next[0x14];
u8 dword_CODE_bss_800888D8[0x3958];

// data
//D:80046050
s32 D_80046050 = 0;

struct fileentry file_resource_table[] = {
    {0, "", 0},
    {1, "bg/bg_sev_all_p.seg", 0x438660},
    {2, "bg/bg_silo_all_p.seg", 0x449450},
    {3, "bg/bg_stat_all_p.seg", 0x49A390},
    {4, "bg/bg_arec_all_p.seg", 0x4BC460},
    {5, "bg/bg_arch_all_p.seg", 0x4EA7E0},
    {6, "bg/bg_tra_all_p.seg", 0x5102D0},
    {7, "bg/bg_dest_all_p.seg", 0x530840},
    {8, "bg/bg_sevb_all_p.seg", 0x55E200},
    {9, "bg/bg_azt_all_p.seg", 0x578FA0},
    {0xA, "bg/bg_pete_all_p.seg", 0x59A9F0},
    {0xB, "bg/bg_depo_all_p.seg", 0x5B4620},
    {0xC, "bg/bg_ref_all_p.seg", 0x5E0F90},
    {0xD, "bg/bg_cryp_all_p.seg", 0x5EA5A0},
    {0xE, "bg/bg_dam_all_p.seg", 0x5FFC50},
    {0xF, "bg/bg_ark_all_p.seg", 0x62FDF0},
    {0x10, "bg/bg_run_all_p.seg", 0x660D70},
    {0x11, "bg/bg_sevx_all_p.seg", 0x66B140},
    {0x12, "bg/bg_jun_all_p.seg", 0x687710},
    {0x13, "bg/bg_dish_all_p.seg", 0x69C860},
    {0x14, "bg/bg_cave_all_p.seg", 0x6A10D0},
    {0x15, "bg/bg_cat_all_p.seg", 0x6C55C0},
    {0x16, "bg/bg_crad_all_p.seg", 0x6CAAF0},
    {0x17, "bg/bg_sho_all_p.seg", 0x6DAE40},
    {0x18, "bg/bg_eld_all_p.seg", 0x6DAE40},
    {0x19, "bg/bg_imp_all_p.seg", 0x6DAE40},
    {0x1A, "bg/bg_ash_all_p.seg", 0x6DAE40},
    {0x1B, "bg/bg_lue_all_p.seg", 0x6DAE40},
    {0x1C, "bg/bg_ame_all_p.seg", 0x6DAE40},
    {0x1D, "bg/bg_rit_all_p.seg", 0x6E4DA0},
    {0x1E, "bg/bg_oat_all_p.seg", 0x6E4DA0},
    {0x1F, "bg/bg_ear_all_p.seg", 0x6EBBF0},
    {0x20, "bg/bg_lee_all_p.seg", 0x6EBBF0},
    {0x21, "bg/bg_lip_all_p.seg", 0x6EBBF0},
    {0x22, "bg/bg_len_all_p.seg", 0x6EBBF0},
    {0x23, "bg/bg_wax_all_p.seg", 0x6ECB90},
    {0x24, "bg/bg_pam_all_p.seg", 0x6ECB90},
    {0x25, "CarmourguardZ", 0x6ECB90},
    {0x26, "CbaronsamediZ", 0x6EF010},
    {0x27, "CbluecamguardZ", 0x6F2700},
    {0x28, "CbluemanZ", 0x6F4DF0},
    {0x29, "CbluewomanZ", 0x6F6C00},
    {0x2A, "CboilerbondZ", 0x6F8AC0},
    {0x2B, "CboilertrevZ", 0x6FB6D0},
    {0x2C, "CborisZ", 0x6FED50},
    {0x2D, "CcamguardZ", 0x701E70},
    {0x2E, "CcardimanZ", 0x704550},
    {0x2F, "CcheckmanZ", 0x706350},
    {0x30, "CcommguardZ", 0x7081D0},
    {0x31, "CdjbondZ", 0x70A7D0},
    {0x32, "CfattechwomanZ", 0x70D660},
    {0x33, "Cgreatguard2Z", 0x70F580},
    {0x34, "CgreatguardZ", 0x711CA0},
    {0x35, "CgreyguardZ", 0x714320},
    {0x36, "CgreymanZ", 0x7169F0},
    {0x37, "CheadalanZ", 0x7187B0},
    {0x38, "CheadbZ", 0x718D80},
    {0x39, "CheadbalaclavaZ", 0x7192F0},
    {0x3A, "CheadbikeZ", 0x7196C0},
    {0x3B, "CheadbrosnanZ", 0x719D60},
    {0x3C, "CheadbrosnanboilerZ", 0x71AAB0},
    {0x3D, "CheadbrosnansnowZ", 0x71B650},
    {0x3E, "CheadbrosnansuitZ", 0x71C4D0},
    {0x3F, "CheadbrosnantimberZ", 0x71D250},
    {0x40, "CheadchrisZ", 0x71DE10},
    {0x41, "CheaddaveZ", 0x71E350},
    {0x42, "CheaddesZ", 0x71E8D0},
    {0x43, "CheadduncanZ", 0x71EE00},
    {0x44, "CheaddwayneZ", 0x71F320},
    {0x45, "CheadgrahamZ", 0x71F8A0},
    {0x46, "CheadgrantZ", 0x71FE10},
    {0x47, "CheadjimZ", 0x720340},
    {0x48, "Cheadjoe2Z", 0x720870},
    {0x49, "CheadjoeZ", 0x720C90},
    {0x4A, "CheadjoelZ", 0x721200},
    {0x4B, "CheadkarlZ", 0x721710},
    {0x4C, "CheadkenZ", 0x721C70},
    {0x4D, "CheadleeZ", 0x7221C0},
    {0x4E, "CheadmandyZ", 0x722740},
    {0x4F, "CheadmarionZ", 0x722B30},
    {0x50, "CheadmarkZ", 0x722F40},
    {0x51, "CheadmartinZ", 0x723470},
    {0x52, "CheadmishkinZ", 0x7239D0},
    {0x53, "CheadneilZ", 0x723F30},
    {0x54, "CheadpeteZ", 0x724450},
    {0x55, "CheadrobinZ", 0x7249E0},
    {0x56, "CheadsallyZ", 0x724EF0},
    {0x57, "CheadscottZ", 0x7252F0},
    {0x58, "CheadshaunZ", 0x725870},
    {0x59, "CheadsteveeZ", 0x725E50},
    {0x5A, "CheadstevehZ", 0x7263A0},
    {0x5B, "CheadvivienZ", 0x7268F0},
    {0x5C, "CjawsZ", 0x726D80},
    {0x5D, "CjeanwomanZ", 0x7299C0},
    {0x5E, "CmaydayZ", 0x72B9D0},
    {0x5F, "CmoonfemaleZ", 0x72E570},
    {0x60, "CmoonguardZ", 0x7306C0},
    {0x61, "CnatalyaZ", 0x732CB0},
    {0x62, "CnavyguardZ", 0x736570},
    {0x63, "CoddjobZ", 0x738C50},
    {0x64, "ColiveguardZ", 0x73BD80},
    {0x65, "CorumovZ", 0x73E3D0},
    {0x66, "CpilotZ", 0x741800},
    {0x67, "CredmanZ", 0x744880},
    {0x68, "CrusguardZ", 0x746FB0},
    {0x69, "CsnowbondZ", 0x748BE0},
    {0x6A, "CsnowguardZ", 0x74BF10},
    {0x6B, "CspicebondZ", 0x74EB90},
    {0x6C, "Csuit_lf_handZ", 0x7524B0},
    {0x6D, "CsuitbondZ", 0x7556D0},
    {0x6E, "CtechmanZ", 0x758460},
    {0x6F, "CtechwomanZ", 0x75AB10},
    {0x70, "CtimberbondZ", 0x75CB00},
    {0x71, "CtrevelyanZ", 0x75F830},
    {0x72, "CtrevguardZ", 0x763000},
    {0x73, "CvalentinZ", 0x765610},
    {0x74, "CxeniaZ", 0x768580},
    {0x75, "Gak47Z", 0x76BF70},
    {0x76, "GaudiotapeZ", 0x76C980},
    {0x77, "GautoshotZ", 0x76CD10},
    {0x78, "GblackboxZ", 0x76E520},
    {0x79, "GblueprintsZ", 0x76EB20},
    {0x7A, "GbombcaseZ", 0x76EC20},
    {0x7B, "GbombdefuserZ", 0x76F3B0},
    {0x7C, "GbriefcaseZ", 0x76F9A0},
    {0x7D, "GbugZ", 0x770130},
    {0x7E, "GbugdetectorZ", 0x770AA0},
    {0x7F, "GbungeeZ", 0x770DF0},
    {0x80, "GcameraZ", 0x771140},
    {0x81, "GcartblueZ", 0x7715C0},
    {0x82, "GcartridgeZ", 0x771820},
    {0x83, "GcartrifleZ", 0x771950},
    {0x84, "GcartshellZ", 0x771B60},
    {0x85, "GcircuitboardZ", 0x771D60},
    {0x86, "GclipboardZ", 0x771EA0},
    {0x87, "GcreditcardZ", 0x772090},
    {0x88, "GdarkglassesZ", 0x7723E0},
    {0x89, "GdatathiefZ", 0x772730},
    {0x8A, "GdattapeZ", 0x772870},
    {0x8B, "GdoordecoderZ", 0x7729E0},
    {0x8C, "GdoorexploderZ", 0x772F60},
    {0x8D, "GdossierredZ", 0x7732B0},
    {0x8E, "GdynamiteZ", 0x773610},
    {0x8F, "GexplosivefloppyZ", 0x773960},
    {0x90, "GexplosivepenZ", 0x773BB0},
    {0x91, "GextinguisherZ", 0x773F00},
    {0x92, "GfingergunZ", 0x7746F0},
    {0x93, "GfistZ", 0x774A40},
    {0x94, "GflarepistolZ", 0x776140},
    {0x95, "Gfnp90Z", 0x776490},
    {0x96, "GgaskeyringZ", 0x777130},
    {0x97, "GgoldbarZ", 0x777B60},
    {0x98, "GgoldeneyekeyZ", 0x777EB0},
    {0x99, "GgoldengunZ", 0x778860},
    {0x9A, "GgoldwppkZ", 0x77A040},
    {0x9B, "GgrenadeZ", 0x77B9A0},
    {0x9C, "GgrenadelaunchZ", 0x77C3D0},
    {0x9D, "GheroinZ", 0x77D450},
    {0x9E, "GjoypadZ", 0x77D7A0},
    {0x9F, "GkeyanalysercaseZ", 0x77F650},
    {0xA0, "GkeyboltZ", 0x77FDE0},
    {0xA1, "GkeycardZ", 0x7807D0},
    {0xA2, "GkeyyaleZ", 0x780900},
    {0xA3, "GknifeZ", 0x781650},
    {0xA4, "GlaserZ", 0x783120},
    {0xA5, "GlectreZ", 0x783F10},
    {0xA6, "GlockexploderZ", 0x784260},
    {0xA7, "Gm16Z", 0x7845B0},
    {0xA8, "GmapZ", 0x784FD0},
    {0xA9, "GmicrocameraZ", 0x7850C0},
    {0xAA, "GmicrocodeZ", 0x785700},
    {0xAB, "GmicrofilmZ", 0x785A50},
    {0xAC, "GmoneyZ", 0x785DA0},
    {0xAD, "Gmp5kZ", 0x7860F0},
    {0xAE, "Gmp5ksilZ", 0x786CD0},
    {0xAF, "GpitongunZ", 0x7879D0},
    {0xB0, "GplansZ", 0x787D20},
    {0xB1, "GplastiqueZ", 0x787EF0},
    {0xB2, "GpolarizedglassesZ", 0x788240},
    {0xB3, "GproximitymineZ", 0x7887A0},
    {0xB4, "GremotemineZ", 0x788F90},
    {0xB5, "GrocketlaunchZ", 0x789950},
    {0xB6, "GrugerZ", 0x78AB70},
    {0xB7, "GsafecrackercaseZ", 0x78C900},
    {0xB8, "GshotgunZ", 0x78D090},
    {0xB9, "GsilverwppkZ", 0x78DF70},
    {0xBA, "GskorpionZ", 0x78F8D0},
    {0xBB, "GsniperrifleZ", 0x790AD0},
    {0xBC, "GspectreZ", 0x791B40},
    {0xBD, "GspooltapeZ", 0x7927C0},
    {0xBE, "GspyfileZ", 0x792B10},
    {0xBF, "GstafflistZ", 0x792E60},
    {0xC0, "GtaserZ", 0x793000},
    {0xC1, "GthrowknifeZ", 0x794E60},
    {0xC2, "GtimedmineZ", 0x796950},
    {0xC3, "GtriggerZ", 0x797410},
    {0xC4, "Gtt33Z", 0x79A810},
    {0xC5, "GuziZ", 0x79C330},
    {0xC6, "GvideotapeZ", 0x79CC40},
    {0xC7, "GwatchcommunicatorZ", 0x79CE50},
    {0xC8, "GwatchgeigercounterZ", 0x79E2B0},
    {0xC9, "GwatchidentifierZ", 0x79F710},
    {0xCA, "GwatchlaserZ", 0x7A0B70},
    {0xCB, "GwatchmagnetattractZ", 0x7A3F70},
    {0xCC, "GwatchmagnetrepelZ", 0x7A53C0},
    {0xCD, "GweaponcaseZ", 0x7A6820},
    {0xCE, "GwppkZ", 0x7A6FB0},
    {0xCF, "GwppksilZ", 0x7A8C40},
    {0xD0, "GwristdartZ", 0x7AA980},
    {0xD1, "PICBMZ", 0x7AACD0},
    {0xD2, "PICBM_noseZ", 0x7AD250},
    {0xD3, "Pak47magZ", 0x7ADA00},
    {0xD4, "Palarm1Z", 0x7ADBE0},
    {0xD5, "Palarm2Z", 0x7ADD40},
    {0xD6, "Pammo_crate1Z", 0x7ADEE0},
    {0xD7, "Pammo_crate2Z", 0x7AE120},
    {0xD8, "Pammo_crate3Z", 0x7AE360},
    {0xD9, "Pammo_crate4Z", 0x7AE5B0},
    {0xDA, "Pammo_crate5Z", 0x7AE820},
    {0xDB, "PapcZ", 0x7AEAE0},
    {0xDC, "Parchsecdoor1Z", 0x7B0740},
    {0xDD, "Parchsecdoor2Z", 0x7B0920},
    {0xDE, "ParticZ", 0x7B0AF0},
    {0xDF, "PartictrailerZ", 0x7B18F0},
    {0xE0, "PbarricadeZ", 0x7B2200},
    {0xE1, "Pbin1Z", 0x7B2440},
    {0xE2, "Pblotter1Z", 0x7B2790},
    {0xE3, "PbodyarmourZ", 0x7B2870},
    {0xE4, "PbodyarmourvestZ", 0x7B2D10},
    {0xE5, "PbollardZ", 0x7B3130},
    {0xE6, "PbombZ", 0x7B3330},
    {0xE7, "Pbook1Z", 0x7B34A0},
    {0xE8, "Pbookshelf1Z", 0x7B3630},
    {0xE9, "Pborg_crateZ", 0x7B3D20},
    {0xEA, "PboxcartridgesZ", 0x7B3E90},
    {0xEB, "Pboxes2x4Z", 0x7B4090},
    {0xEC, "Pboxes3x4Z", 0x7B44C0},
    {0xED, "Pboxes4x4Z", 0x7B4900},
    {0xEE, "PbrakeunitZ", 0x7B4F60},
    {0xEF, "Pbridge_console1aZ", 0x7B52D0},
    {0xF0, "Pbridge_console1bZ", 0x7B5850},
    {0xF1, "Pbridge_console2aZ", 0x7B5DB0},
    {0xF2, "Pbridge_console2bZ", 0x7B6330},
    {0xF3, "Pbridge_console3aZ", 0x7B6820},
    {0xF4, "Pbridge_console3bZ", 0x7B6D70},
    {0xF5, "PcarbmwZ", 0x7B7300},
    {0xF6, "Pcard_box1Z", 0x7B7FE0},
    {0xF7, "Pcard_box2Z", 0x7B81E0},
    {0xF8, "Pcard_box3Z", 0x7B8420},
    {0xF9, "Pcard_box4_lgZ", 0x7B8610},
    {0xFA, "Pcard_box5_lgZ", 0x7B87C0},
    {0xFB, "Pcard_box6_lgZ", 0x7B89C0},
    {0xFC, "PcarescortZ", 0x7B8BB0},
    {0xFD, "PcargolfZ", 0x7B97B0},
    {0xFE, "PcarweirdZ", 0x7BA3E0},
    {0xFF, "PcarzilZ", 0x7BB520},
    {0x100, "PcctvZ", 0x7BCB20},
    {0x101, "PchraudiotapeZ", 0x7BCEA0},
    {0x102, "PchrautoshotZ", 0x7BD400},
    {0x103, "PchrblackboxZ", 0x7BD760},
    {0x104, "PchrblueprintsZ", 0x7BDFE0},
    {0x105, "PchrbombcaseZ", 0x7BE130},
    {0x106, "PchrbombdefuserZ", 0x7BE320},
    {0x107, "PchrbriefcaseZ", 0x7BEC00},
    {0x108, "PchrbugZ", 0x7BED90},
    {0x109, "PchrbugdetectorZ", 0x7BFB40},
    {0x10A, "PchrbungeeZ", 0x7BFCB0},
    {0x10B, "PchrcameraZ", 0x7BFE20},
    {0x10C, "PchrcircuitboardZ", 0x7C04B0},
    {0x10D, "PchrclipboardZ", 0x7C0650},
    {0x10E, "PchrcreditcardZ", 0x7C08D0},
    {0x10F, "PchrdarkglassesZ", 0x7C0A40},
    {0x110, "PchrdatathiefZ", 0x7C0BB0},
    {0x111, "PchrdattapeZ", 0x7C0D50},
    {0x112, "PchrdoordecoderZ", 0x7C0F40},
    {0x113, "PchrdoorexploderZ", 0x7C17A0},
    {0x114, "PchrdossierredZ", 0x7C1910},
    {0x115, "PchrdynamiteZ", 0x7C1DE0},
    {0x116, "PchrexplosivepenZ", 0x7C1F50},
    {0x117, "PchrextinguisherZ", 0x7C20C0},
    {0x118, "PchrfingergunZ", 0x7C25C0},
    {0x119, "PchrflarepistolZ", 0x7C2730},
    {0x11A, "Pchrfnp90Z", 0x7C28A0},
    {0x11B, "PchrgaskeyringZ", 0x7C2D00},
    {0x11C, "PchrgoldbarZ", 0x7C3C10},
    {0x11D, "PchrgoldenZ", 0x7C3D80},
    {0x11E, "PchrgoldeneyekeyZ", 0x7C3FF0},
    {0x11F, "PchrgoldwppkZ", 0x7C4E90},
    {0x120, "PchrgrenadeZ", 0x7C5000},
    {0x121, "PchrgrenadelaunchZ", 0x7C5370},
    {0x122, "PchrgrenaderoundZ", 0x7C5700},
    {0x123, "PchrheroinZ", 0x7C5970},
    {0x124, "PchrkalashZ", 0x7C5AE0},
    {0x125, "PchrkeyanalysercaseZ", 0x7C5ED0},
    {0x126, "PchrkeyboltZ", 0x7C60C0},
    {0x127, "PchrkeyyaleZ", 0x7C6F60},
    {0x128, "PchrknifeZ", 0x7C83C0},
    {0x129, "PchrlaserZ", 0x7C85C0},
    {0x12A, "PchrlectreZ", 0x7C8980},
    {0x12B, "PchrlockexploderZ", 0x7C8AF0},
    {0x12C, "Pchrm16Z", 0x7C8C60},
    {0x12D, "PchrmapZ", 0x7C9030},
    {0x12E, "PchrmicrocameraZ", 0x7C9180},
    {0x12F, "PchrmicrocodeZ", 0x7C9A70},
    {0x130, "PchrmicrofilmZ", 0x7C9BE0},
    {0x131, "PchrmoneyZ", 0x7C9D50},
    {0x132, "Pchrmp5kZ", 0x7C9EC0},
    {0x133, "Pchrmp5ksilZ", 0x7CA240},
    {0x134, "PchrpitongunZ", 0x7CA650},
    {0x135, "PchrplansZ", 0x7CA7C0},
    {0x136, "PchrplastiqueZ", 0x7CAA50},
    {0x137, "PchrpolarizedglassesZ", 0x7CAEB0},
    {0x138, "PchrproximitymineZ", 0x7CB770},
    {0x139, "PchrremotemineZ", 0x7CBBD0},
    {0x13A, "PchrrocketZ", 0x7CC030},
    {0x13B, "PchrrocketlaunchZ", 0x7CC5E0},
    {0x13C, "PchrrugerZ", 0x7CC9C0},
    {0x13D, "PchrsafecrackercaseZ", 0x7CCDA0},
    {0x13E, "PchrshotgunZ", 0x7CCF90},
    {0x13F, "PchrsilverwppkZ", 0x7CD2E0},
    {0x140, "PchrskorpionZ", 0x7CD450},
    {0x141, "PchrsniperrifleZ", 0x7CD7D0},
    {0x142, "PchrspectreZ", 0x7CDB60},
    {0x143, "PchrspooltapeZ", 0x7CDED0},
    {0x144, "PchrspyfileZ", 0x7CE040},
    {0x145, "PchrstafflistZ", 0x7CE1B0},
    {0x146, "PchrtesttubeZ", 0x7CE3D0},
    {0x147, "PchrthrowknifeZ", 0x7CE590},
    {0x148, "PchrtimedmineZ", 0x7CE7B0},
    {0x149, "Pchrtt33Z", 0x7CECE0},
    {0x14A, "PchruziZ", 0x7CEF70},
    {0x14B, "PchrvideotapeZ", 0x7CF240},
    {0x14C, "PchrweaponcaseZ", 0x7CF510},
    {0x14D, "PchrwppkZ", 0x7CF710},
    {0x14E, "PchrwppksilZ", 0x7CF950},
    {0x14F, "PchrwristdartZ", 0x7CFC30},
    {0x150, "Pconsole1Z", 0x7CFDA0},
    {0x151, "Pconsole2Z", 0x7D0420},
    {0x152, "Pconsole3Z", 0x7D0AA0},
    {0x153, "Pconsole_sev2aZ", 0x7D1130},
    {0x154, "Pconsole_sev2bZ", 0x7D1550},
    {0x155, "Pconsole_sev2cZ", 0x7D1A10},
    {0x156, "Pconsole_sev2dZ", 0x7D1E50},
    {0x157, "Pconsole_sev_GEaZ", 0x7D2280},
    {0x158, "Pconsole_sev_GEbZ", 0x7D26B0},
    {0x159, "Pconsole_sevaZ", 0x7D2AE0},
    {0x15A, "Pconsole_sevbZ", 0x7D2F60},
    {0x15B, "Pconsole_sevcZ", 0x7D33D0},
    {0x15C, "Pconsole_sevdZ", 0x7D3800},
    {0x15D, "Pcryptdoor1aZ", 0x7D3C30},
    {0x15E, "Pcryptdoor1bZ", 0x7D3DC0},
    {0x15F, "Pcryptdoor2aZ", 0x7D3F50},
    {0x160, "Pcryptdoor2bZ", 0x7D40E0},
    {0x161, "Pcryptdoor3Z", 0x7D4270},
    {0x162, "Pcryptdoor4Z", 0x7D44E0},
    {0x163, "PdamchaindoorZ", 0x7D4660},
    {0x164, "PdamgatedoorZ", 0x7D48E0},
    {0x165, "PdamtundoorZ", 0x7D4B00},
    {0x166, "Pdepot_door_steelZ", 0x7D4E70},
    {0x167, "Pdepot_gate_entryZ", 0x7D5010},
    {0x168, "Pdesk1Z", 0x7D5250},
    {0x169, "Pdesk2Z", 0x7D53D0},
    {0x16A, "Pdesk_arecibo1Z", 0x7D5550},
    {0x16B, "Pdesk_lamp2Z", 0x7D5790},
    {0x16C, "Pdest_engineZ", 0x7D5A90},
    {0x16D, "Pdest_exocetZ", 0x7D7380},
    {0x16E, "Pdest_gunZ", 0x7D79E0},
    {0x16F, "Pdest_harpoonZ", 0x7D8050},
    {0x170, "Pdest_seawolfZ", 0x7D88F0},
    {0x171, "Pdisc_readerZ", 0x7D98A0},
    {0x172, "Pdisk_drive1Z", 0x7D9A60},
    {0x173, "Pdoor_azt_chairZ", 0x7D9BF0},
    {0x174, "Pdoor_azt_deskZ", 0x7D9D70},
    {0x175, "Pdoor_azt_desk_topZ", 0x7DA1B0},
    {0x176, "Pdoor_aztecZ", 0x7DA540},
    {0x177, "Pdoor_dest1Z", 0x7DA770},
    {0x178, "Pdoor_dest2Z", 0x7DAA70},
    {0x179, "Pdoor_eyelidZ", 0x7DAE30},
    {0x17A, "Pdoor_irisZ", 0x7DB390},
    {0x17B, "Pdoor_mfZ", 0x7DBDE0},
    {0x17C, "Pdoor_roller1Z", 0x7DC0D0},
    {0x17D, "Pdoor_roller2Z", 0x7DC440},
    {0x17E, "Pdoor_roller3Z", 0x7DC680},
    {0x17F, "Pdoor_roller4Z", 0x7DC8C0},
    {0x180, "Pdoor_rollertrainZ", 0x7DCB20},
    {0x181, "Pdoor_st_arec1Z", 0x7DCC50},
    {0x182, "Pdoor_st_arec2Z", 0x7DCEB0},
    {0x183, "Pdoor_winZ", 0x7DD190},
    {0x184, "PdoorconsoleZ", 0x7DD330},
    {0x185, "PdoorpanelZ", 0x7DD7A0},
    {0x186, "Pdoorprison1Z", 0x7DDB10},
    {0x187, "PdoorstatgateZ", 0x7DDC60},
    {0x188, "PexplosionbitZ", 0x7DDE60},
    {0x189, "Pfiling_cabinet1Z", 0x7DDF80},
    {0x18A, "PflagZ", 0x7DE100},
    {0x18B, "PfloppyZ", 0x7DE230},
    {0x18C, "Pfnp90magZ", 0x7DE550},
    {0x18D, "Pgas_plant_met1_do1Z", 0x7DE6F0},
    {0x18E, "Pgas_plant_sw2_do1Z", 0x7DEA70},
    {0x18F, "Pgas_plant_sw3_do1Z", 0x7DEC50},
    {0x190, "Pgas_plant_sw4_do1Z", 0x7DEE50},
    {0x191, "Pgas_plant_sw_do1Z", 0x7DEFB0},
    {0x192, "Pgas_plant_wc_cub1Z", 0x7DF240},
    {0x193, "PgasbarrelZ", 0x7DF450},
    {0x194, "PgasbarrelsZ", 0x7DF660},
    {0x195, "Pgasplant_clear_doorZ", 0x7DFBA0},
    {0x196, "PgastankZ", 0x7E0100},
    {0x197, "Pglassware1Z", 0x7E06B0},
    {0x198, "Pglassware2Z", 0x7E0810},
    {0x199, "Pglassware3Z", 0x7E0AA0},
    {0x19A, "Pglassware4Z", 0x7E0CB0},
    {0x19B, "PgoldeneyelogoZ", 0x7E1230},
    {0x19C, "PgoldenshellsZ", 0x7E20E0},
    {0x19D, "PgroundgunZ", 0x7E22E0},
    {0x19E, "Pgun_runway1Z", 0x7E2AB0},
    {0x19F, "PhatberetZ", 0x7E31F0},
    {0x1A0, "PhatberetblueZ", 0x7E3490},
    {0x1A1, "PhatberetredZ", 0x7E3760},
    {0x1A2, "PhatchboltZ", 0x7E3A40},
    {0x1A3, "PhatchdoorZ", 0x7E3B10},
    {0x1A4, "PhatchsevxZ", 0x7E3D30},
    {0x1A5, "PhatfurryZ", 0x7E3EA0},
    {0x1A6, "PhatfurryblackZ", 0x7E40D0},
    {0x1A7, "PhatfurrybrownZ", 0x7E42F0},
    {0x1A8, "PhathelmetZ", 0x7E4500},
    {0x1A9, "PhathelmetgreyZ", 0x7E4730},
    {0x1AA, "PhatmoonZ", 0x7E4960},
    {0x1AB, "PhatpeakedZ", 0x7E4D40},
    {0x1AC, "PhattbirdZ", 0x7E5050},
    {0x1AD, "PhattbirdbrownZ", 0x7E52A0},
    {0x1AE, "PhelicopterZ", 0x7E5510},
    {0x1AF, "PhindZ", 0x7E9730},
    {0x1B0, "PjeepZ", 0x7EAEA0},
    {0x1B1, "Pjerry_can1Z", 0x7EC000},
    {0x1B2, "Pjungle3_treeZ", 0x7EC260},
    {0x1B3, "Pjungle5_treeZ", 0x7EC9E0},
    {0x1B4, "Pkey_holderZ", 0x7ECF10},
    {0x1B5, "Pkeyboard1Z", 0x7ED260},
    {0x1B6, "Pkit_units1Z", 0x7ED3D0},
    {0x1B7, "PlabbenchZ", 0x7ED670},
    {0x1B8, "PlandmineZ", 0x7EDA40},
    {0x1B9, "PlegalpageZ", 0x7EDCB0},
    {0x1BA, "Pletter_tray1Z", 0x7EEC70},
    {0x1BB, "Plocker3Z", 0x7EEDD0},
    {0x1BC, "Plocker4Z", 0x7EEF60},
    {0x1BD, "Pm16magZ", 0x7EF0F0},
    {0x1BE, "PmagnumshellsZ", 0x7EF230},
    {0x1BF, "Pmainframe1Z", 0x7EF430},
    {0x1C0, "Pmainframe2Z", 0x7EF730},
    {0x1C1, "Pmetal_chair1Z", 0x7EFA00},
    {0x1C2, "Pmetal_crate1Z", 0x7EFD40},
    {0x1C3, "Pmetal_crate2Z", 0x7EFF00},
    {0x1C4, "Pmetal_crate3Z", 0x7F00C0},
    {0x1C5, "Pmetal_crate4Z", 0x7F0280},
    {0x1C6, "PmilcopterZ", 0x7F0440},
    {0x1C7, "PmiltruckZ", 0x7F1D20},
    {0x1C8, "Pmissile_rack2Z", 0x7F4020},
    {0x1C9, "Pmissile_rackZ", 0x7F4A30},
    {0x1CA, "PmodemboxZ", 0x7F4E10},
    {0x1CB, "PmotorbikeZ", 0x7F5150},
    {0x1CC, "Pmp5kmagZ", 0x7F6010},
    {0x1CD, "PnintendologoZ", 0x7F6160},
    {0x1CE, "Poil_drum1Z", 0x7F8C40},
    {0x1CF, "Poil_drum2Z", 0x7F8EB0},
    {0x1D0, "Poil_drum3Z", 0x7F91A0},
    {0x1D1, "Poil_drum5Z", 0x7F9490},
    {0x1D2, "Poil_drum6Z", 0x7F9780},
    {0x1D3, "Poil_drum7Z", 0x7F9A90},
    {0x1D4, "PpadlockZ", 0x7F9D90},
    {0x1D5, "PpalmZ", 0x7FA7E0},
    {0x1D6, "PpalmtreeZ", 0x7FAC30},
    {0x1D7, "Pphone1Z", 0x7FB100},
    {0x1D8, "PplaneZ", 0x7FB240},
    {0x1D9, "Pplant11Z", 0x7FD820},
    {0x1DA, "Pplant1Z", 0x7FDBE0},
    {0x1DB, "Pplant2Z", 0x7FDF70},
    {0x1DC, "Pplant2bZ", 0x7FE2D0},
    {0x1DD, "Pplant3Z", 0x7FE6E0},
    {0x1DE, "Pradio_unit1Z", 0x7FEB30},
    {0x1DF, "Pradio_unit2Z", 0x7FECE0},
    {0x1E0, "Pradio_unit3Z", 0x7FEEA0},
    {0x1E1, "Pradio_unit4Z", 0x7FF060},
    {0x1E2, "ProofgunZ", 0x7FF220},
    {0x1E3, "PsafeZ", 0x7FF880},
    {0x1E4, "PsafedoorZ", 0x7FFBD0},
    {0x1E5, "Psat1_reflectZ", 0x8000C0},
    {0x1E6, "PsatboxZ", 0x801630},
    {0x1E7, "PsatdishZ", 0x801750},
    {0x1E8, "Psec_panelZ", 0x801BB0},
    {0x1E9, "Psev_door3Z", 0x801D50},
    {0x1EA, "Psev_door3_windZ", 0x801FE0},
    {0x1EB, "Psev_door4_windZ", 0x802370},
    {0x1EC, "Psev_doorZ", 0x802750},
    {0x1ED, "Psev_door_v1Z", 0x802AA0},
    {0x1EE, "Psev_trislideZ", 0x802DD0},
    {0x1EF, "PsevdishZ", 0x803180},
    {0x1F0, "PsevdoormetslideZ", 0x8040A0},
    {0x1F1, "PsevdoornowindZ", 0x804380},
    {0x1F2, "PsevdoorwindZ", 0x8044F0},
    {0x1F3, "PsevdoorwoodZ", 0x804920},
    {0x1F4, "PshuttleZ", 0x804CD0},
    {0x1F5, "Pshuttle_door_lZ", 0x8076D0},
    {0x1F6, "Pshuttle_door_rZ", 0x808300},
    {0x1F7, "PsilencerZ", 0x809000},
    {0x1F8, "Psilo_lift_doorZ", 0x8091A0},
    {0x1F9, "PsilotopdoorZ", 0x8093E0},
    {0x1FA, "PskorpionmagZ", 0x8096D0},
    {0x1FB, "PspectremagZ", 0x809830},
    {0x1FC, "PspeedboatZ", 0x8099A0},
    {0x1FD, "Pst_pete_room_1iZ", 0x80A6E0},
    {0x1FE, "Pst_pete_room_2iZ", 0x80D820},
    {0x1FF, "Pst_pete_room_3tZ", 0x810A00},
    {0x200, "Pst_pete_room_5cZ", 0x813940},
    {0x201, "Pst_pete_room_6cZ", 0x816ED0},
    {0x202, "Psteel_door1Z", 0x81A2E0},
    {0x203, "Psteel_door2Z", 0x81A550},
    {0x204, "Psteel_door2bZ", 0x81A800},
    {0x205, "Psteel_door3Z", 0x81AAD0},
    {0x206, "Pstool1Z", 0x81ADA0},
    {0x207, "Pswipe_card2Z", 0x81B060},
    {0x208, "Pswivel_chair1Z", 0x81B1F0},
    {0x209, "PtankZ", 0x81B480},
    {0x20A, "PtigerZ", 0x81CF20},
    {0x20B, "Ptorpedo_rackZ", 0x81EDB0},
    {0x20C, "Ptrain_door2Z", 0x81F630},
    {0x20D, "Ptrain_door3Z", 0x81FA00},
    {0x20E, "Ptrain_doorZ", 0x81FE20},
    {0x20F, "PtrainextdoorZ", 0x820090},
    {0x210, "Ptt33magZ", 0x8203D0},
    {0x211, "Ptuning_console1Z", 0x820510},
    {0x212, "Ptv1Z", 0x820A30},
    {0x213, "Ptv4screenZ", 0x820C00},
    {0x214, "Ptv_holderZ", 0x820DA0},
    {0x215, "PtvscreenZ", 0x821470},
    {0x216, "PuzimagZ", 0x821540},
    {0x217, "PvertdoorZ", 0x821680},
    {0x218, "PwalletbondZ", 0x821C90},
    {0x219, "PwindowZ", 0x823240},
    {0x21A, "Pwindow_cor11Z", 0x823330},
    {0x21B, "Pwindow_lib_lg1Z", 0x823410},
    {0x21C, "Pwindow_lib_sm1Z", 0x8234F0},
    {0x21D, "Pwood_lg_crate1Z", 0x8235E0},
    {0x21E, "Pwood_lg_crate2Z", 0x823860},
    {0x21F, "Pwood_md_crate3Z", 0x823A80},
    {0x220, "Pwood_sm_crate4Z", 0x823CA0},
    {0x221, "Pwood_sm_crate5Z", 0x823F00},
    {0x222, "Pwood_sm_crate6Z", 0x824160},
    {0x223, "Pwooden_table1Z", 0x824380},
    {0x224, "PwppkmagZ", 0x8246F0},
    {0x225, "Tbg_ame_all_p_stanZ", 0x824830},
    {0x226, "Tbg_arch_all_p_stanZ", 0x826160},
    {0x227, "Tbg_arec_all_p_stanZ", 0x82BE50},
    {0x228, "Tbg_ark_all_p_stanZ", 0x8341A0},
    {0x229, "Tbg_ash_all_p_stanZ", 0x83D160},
    {0x22A, "Tbg_azt_all_p_stanZ", 0x83EA90},
    {0x22B, "Tbg_cat_all_p_stanZ", 0x844010},
    {0x22C, "Tbg_cave_all_p_stanZ", 0x846740},
    {0x22D, "Tbg_crad_all_p_stanZ", 0x84B630},
    {0x22E, "Tbg_cryp_all_p_stanZ", 0x84DF40},
    {0x22F, "Tbg_dam_all_p_stanZ", 0x850FB0},
    {0x230, "Tbg_depo_all_p_stanZ", 0x85B390},
    {0x231, "Tbg_dest_all_p_stanZ", 0x8622D0},
    {0x232, "Tbg_dish_all_p_stanZ", 0x868BC0},
    {0x233, "Tbg_ear_all_p_stanZ", 0x8696D0},
    {0x234, "Tbg_eld_all_p_stanZ", 0x8696D0},
    {0x235, "Tbg_imp_all_p_stanZ", 0x8696D0},
    {0x236, "Tbg_jun_all_p_stanZ", 0x86B000},
    {0x237, "Tbg_lee_all_p_stanZ", 0x872150},
    {0x238, "Tbg_len_all_p_stanZ", 0x872150},
    {0x239, "Tbg_lip_all_p_stanZ", 0x872C10},
    {0x23A, "Tbg_lue_all_p_stanZ", 0x872C10},
    {0x23B, "Tbg_oat_all_p_stanZ", 0x872C10},
    {0x23C, "Tbg_pam_all_p_stanZ", 0x874510},
    {0x23D, "Tbg_pete_all_p_stanZ", 0x874510},
    {0x23E, "Tbg_ref_all_p_stanZ", 0x878BA0},
    {0x23F, "Tbg_rit_all_p_stanZ", 0x87A970},
    {0x240, "Tbg_run_all_p_stanZ", 0x87A970},
    {0x241, "Tbg_sev_all_p_stanZ", 0x87C3F0},
    {0x242, "Tbg_sevb_all_p_stanZ", 0x8801C0},
    {0x243, "Tbg_sevx_all_p_stanZ", 0x885100},
    {0x244, "Tbg_silo_all_p_stanZ", 0x88E430},
    {0x245, "Tbg_stat_all_p_stanZ", 0x8974D0},
    {0x246, "Tbg_tra_all_p_stanZ", 0x89C390},
    {0x247, "Tbg_wax_all_p_stanZ", 0x89E760},
    {0x248, "UbriefarchZ", 0x89E760},
    {0x249, "UbriefarkZ", 0x89E780},
    {0x24A, "UbriefaztZ", 0x89E7A0},
    {0x24B, "UbriefcaveZ", 0x89E7C0},
    {0x24C, "UbriefcontrolZ", 0x89E7E0},
    {0x24D, "UbriefcradZ", 0x89E800},
    {0x24E, "UbriefcrypZ", 0x89E820},
    {0x24F, "UbriefdamZ", 0x89E840},
    {0x250, "UbriefdepoZ", 0x89E860},
    {0x251, "UbriefdestZ", 0x89E880},
    {0x252, "UbriefjunZ", 0x89E8A0},
    {0x253, "UbriefpeteZ", 0x89E8C0},
    {0x254, "UbriefrunZ", 0x89E8E0},
    {0x255, "UbriefsevbZ", 0x89E900},
    {0x256, "UbriefsevbunkerZ", 0x89E920},
    {0x257, "UbriefsevxZ", 0x89E940},
    {0x258, "UbriefsevxbZ", 0x89E960},
    {0x259, "UbriefsiloZ", 0x89E980},
    {0x25A, "UbriefstatueZ", 0x89E9A0},
    {0x25B, "UbrieftraZ", 0x89E9C0},
    {0x25C, "Ump_setupameZ", 0x89E9E0},
    {0x25D, "Ump_setuparchZ", 0x89F100},
    {0x25E, "Ump_setuparkZ", 0x8A1EA0},
    {0x25F, "Ump_setupashZ", 0x8A3BE0},
    {0x260, "Ump_setupcaveZ", 0x8A42D0},
    {0x261, "Ump_setupcradZ", 0x8A6830},
    {0x262, "Ump_setupcrypZ", 0x8A7190},
    {0x263, "Ump_setupdishZ", 0x8A7EF0},
    {0x264, "Ump_setupimpZ", 0x8A82E0},
    {0x265, "Ump_setupoatZ", 0x8A8920},
    {0x266, "Ump_setuprefZ", 0x8A8C70},
    {0x267, "Ump_setupsevbZ", 0x8A9080},
    {0x268, "Ump_setupstatueZ", 0x8AA390},
    {0x269, "UsetuparchZ", 0x8AB210},
    {0x26A, "UsetuparkZ", 0x8AF820},
    {0x26B, "UsetupaztZ", 0x8B33B0},
    {0x26C, "UsetupcaveZ", 0x8B5CB0},
    {0x26D, "UsetupcontrolZ", 0x8B9B10},
    {0x26E, "UsetupcradZ", 0x8BD610},
    {0x26F, "UsetupcrypZ", 0x8BF240},
    {0x270, "UsetupdamZ", 0x8C10D0},
    {0x271, "UsetupdepoZ", 0x8C53A0},
    {0x272, "UsetupdestZ", 0x8C8330},
    {0x273, "UsetupjunZ", 0x8CA680},
    {0x274, "UsetuplenZ", 0x8CDD80},
    {0x275, "UsetuppeteZ", 0x8CE350},
    {0x276, "UsetuprunZ", 0x8D12D0},
    {0x277, "UsetupsevbZ", 0x8D2B30},
    {0x278, "UsetupsevbunkerZ", 0x8D5190},
    {0x279, "UsetupsevxZ", 0x8D6BC0},
    {0x27A, "UsetupsevxbZ", 0x8DAED0},
    {0x27B, "UsetupsiloZ", 0x8DEFC0},
    {0x27C, "UsetupstatueZ", 0x8E1A10},
    {0x27D, "UsetuptraZ", 0x8E41E0},
    {0x27E, "LameE", 0x8E7410},
    {0x27F, "LameJ", 0x8E7420},
    {0x280, "LarchE", 0x8E7430},
    {0x281, "LarchJ", 0x8E7A60},
    {0x282, "LarecE", 0x8E80C0},
    {0x283, "LarecJ", 0x8E8690},
    {0x284, "LarkE", 0x8E8C20},
    {0x285, "LarkJ", 0x8E92C0},
    {0x286, "LashE", 0x8E9970},
    {0x287, "LashJ", 0x8E9980},
    {0x288, "LaztE", 0x8E9990},
    {0x289, "LaztJ", 0x8E9DD0},
    {0x28A, "LcatE", 0x8EA280},
    {0x28B, "LcatJ", 0x8EA290},
    {0x28C, "LcaveE", 0x8EA2A0},
    {0x28D, "LcaveJ", 0x8EA6A0},
    {0x28E, "LcradE", 0x8EAB00},
    {0x28F, "LcradJ", 0x8EAFD0},
    {0x290, "LcrypE", 0x8EB480},
    {0x291, "LcrypJ", 0x8EB6D0},
    {0x292, "LdamE", 0x8EB990},
    {0x293, "LdamJ", 0x8EBDE0},
    {0x294, "LdepoE", 0x8EC250},
    {0x295, "LdepoJ", 0x8EC5C0},
    {0x296, "LdestE", 0x8EC900},
    {0x297, "LdestJ", 0x8ECD90},
    {0x298, "LdishE", 0x8ED1F0},
    {0x299, "LdishJ", 0x8ED200},
    {0x29A, "LearE", 0x8ED210},
    {0x29B, "LearJ", 0x8ED220},
    {0x29C, "LeldE", 0x8ED230},
    {0x29D, "LeldJ", 0x8ED240},
    {0x29E, "LgunE", 0x8ED250},
    {0x29F, "LgunJ", 0x8ED970},
    {0x2A0, "LimpE", 0x8EE0C0},
    {0x2A1, "LimpJ", 0x8EE0D0},
    {0x2A2, "LjunE", 0x8EE0E0},
    {0x2A3, "LjunJ", 0x8EE600},
    {0x2A4, "LleeE", 0x8EEB40},
    {0x2A5, "LleeJ", 0x8EEB50},
    {0x2A6, "LlenE", 0x8EEB60},
    {0x2A7, "LlenJ", 0x8EF1A0},
    {0x2A8, "LlipE", 0x8EF450},
    {0x2A9, "LlipJ", 0x8EF460},
    {0x2AA, "LlueE", 0x8EF470},
    {0x2AB, "LlueJ", 0x8EF480},
    {0x2AC, "LmiscE", 0x8EF490},
    {0x2AD, "LmiscJ", 0x8EF730},
    {0x2AE, "LmpmenuE", 0x8EFA10},
    {0x2AF, "LmpmenuJ", 0x8EFBB0},
    {0x2B0, "LmpweaponsE", 0x8EFD40},
    {0x2B1, "LmpweaponsJ", 0x8EFE00},
    {0x2B2, "LoatE", 0x8EFEE0},
    {0x2B3, "LoatJ", 0x8EFEF0},
    {0x2B4, "LoptionsE", 0x8EFF00},
    {0x2B5, "LoptionsJ", 0x8F0130},
    {0x2B6, "LpamE", 0x8F0380},
    {0x2B7, "LpamJ", 0x8F0390},
    {0x2B8, "LpeteE", 0x8F03A0},
    {0x2B9, "LpeteJ", 0x8F0820},
    {0x2BA, "LpropobjE", 0x8F0C90},
    {0x2BB, "LpropobjJ", 0x8F0F30},
    {0x2BC, "LrefE", 0x8F11F0},
    {0x2BD, "LrefJ", 0x8F1200},
    {0x2BE, "LritE", 0x8F1210},
    {0x2BF, "LritJ", 0x8F1220},
    {0x2C0, "LrunE", 0x8F1230},
    {0x2C1, "LrunJ", 0x8F14A0},
    {0x2C2, "LsevE", 0x8F1730},
    {0x2C3, "LsevJ", 0x8F1C90},
    {0x2C4, "LsevbE", 0x8F21A0},
    {0x2C5, "LsevbJ", 0x8F28F0},
    {0x2C6, "LsevxE", 0x8F30E0},
    {0x2C7, "LsevxJ", 0x8F3540},
    {0x2C8, "LsevxbE", 0x8F3900},
    {0x2C9, "LsevxbJ", 0x8F3D90},
    {0x2CA, "LshoE", 0x8F41E0},
    {0x2CB, "LshoJ", 0x8F41F0},
    {0x2CC, "LsiloE", 0x8F4200},
    {0x2CD, "LsiloJ", 0x8F47B0},
    {0x2CE, "LstatE", 0x8F4D90},
    {0x2CF, "LstatJ", 0x8F56B0},
    {0x2D0, "LtitleE", 0x8F5F20},
    {0x2D1, "LtitleJ", 0x8F69E0},
    {0x2D2, "LtraE", 0x8F7570},
    {0x2D3, "LtraJ", 0x8F79A0},
    {0x2D4, "LwaxE", 0x8F7DC0},
    {0x2D5, "LwaxJ", 0x8F7DD0},
    {0x2D6, "ob/ob_end.seg", 0x8F7DE0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0}
};

//D:800482D4
s32 file_entry_max = 0x2D7;


// rodata
//D:8005B66C
const u32 rz_header_1 = 0x11720000;
//D:8005B670
const u32 rz_header_2 = 0x11720000;
//D:8005B674
const char aOb_c_debug[] = "ob_c_debug";


#ifdef NONMATCHING
void load_resource(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_resource
/* 0F15D0 7F0BCAA0 27BDDED8 */  addiu $sp, $sp, -0x2128
/* 0F15D4 7F0BCAA4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F15D8 7F0BCAA8 AFA42128 */  sw    $a0, 0x2128($sp)
/* 0F15DC 7F0BCAAC 14A00006 */  bnez  $a1, .L7F0BCAC8
/* 0F15E0 7F0BCAB0 AFA62130 */   sw    $a2, 0x2130($sp)
/* 0F15E4 7F0BCAB4 8CC50008 */  lw    $a1, 8($a2)
/* 0F15E8 7F0BCAB8 0C001707 */  jal   romCopy
/* 0F15EC 7F0BCABC 8CE60000 */   lw    $a2, ($a3)
/* 0F15F0 7F0BCAC0 10000019 */  b     .L7F0BCB28
/* 0F15F4 7F0BCAC4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BCAC8:
/* 0F15F8 7F0BCAC8 8CE60000 */  lw    $a2, ($a3)
/* 0F15FC 7F0BCACC 8FAF2128 */  lw    $t7, 0x2128($sp)
/* 0F1600 7F0BCAD0 2401FFF8 */  li    $at, -8
/* 0F1604 7F0BCAD4 24D90007 */  addiu $t9, $a2, 7
/* 0F1608 7F0BCAD8 03214024 */  and   $t0, $t9, $at
/* 0F160C 7F0BCADC 01E5C021 */  addu  $t8, $t7, $a1
/* 0F1610 7F0BCAE0 03082023 */  subu  $a0, $t8, $t0
/* 0F1614 7F0BCAE4 008F4823 */  subu  $t1, $a0, $t7
/* 0F1618 7F0BCAE8 2D210008 */  sltiu $at, $t1, 8
/* 0F161C 7F0BCAEC 10200003 */  beqz  $at, .L7F0BCAFC
/* 0F1620 7F0BCAF0 8FAA2130 */   lw    $t2, 0x2130($sp)
/* 0F1624 7F0BCAF4 1000000B */  b     .L7F0BCB24
/* 0F1628 7F0BCAF8 ACE00004 */   sw    $zero, 4($a3)
.L7F0BCAFC:
/* 0F162C 7F0BCAFC 8D450008 */  lw    $a1, 8($t2)
/* 0F1630 7F0BCB00 AFA72134 */  sw    $a3, 0x2134($sp)
/* 0F1634 7F0BCB04 0C001707 */  jal   romCopy
/* 0F1638 7F0BCB08 AFA42124 */   sw    $a0, 0x2124($sp)
/* 0F163C 7F0BCB0C 8FA42124 */  lw    $a0, 0x2124($sp)
/* 0F1640 7F0BCB10 8FA52128 */  lw    $a1, 0x2128($sp)
/* 0F1644 7F0BCB14 0FC339FC */  jal   decompressdata
/* 0F1648 7F0BCB18 27A60024 */   addiu $a2, $sp, 0x24
/* 0F164C 7F0BCB1C 8FA72134 */  lw    $a3, 0x2134($sp)
/* 0F1650 7F0BCB20 ACE20004 */  sw    $v0, 4($a3)
.L7F0BCB24:
/* 0F1654 7F0BCB24 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BCB28:
/* 0F1658 7F0BCB28 27BD2128 */  addiu $sp, $sp, 0x2128
/* 0F165C 7F0BCB2C 03E00008 */  jr    $ra
/* 0F1660 7F0BCB30 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void resource_load_from_indy(void) {

}
#else
GLOBAL_ASM(
.text
glabel resource_load_from_indy
/* 0F1664 7F0BCB34 27BDDED8 */  addiu $sp, $sp, -0x2128
/* 0F1668 7F0BCB38 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F166C 7F0BCB3C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1670 7F0BCB40 00808025 */  move  $s0, $a0
/* 0F1674 7F0BCB44 00E08825 */  move  $s1, $a3
/* 0F1678 7F0BCB48 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F167C 7F0BCB4C 14A00006 */  bnez  $a1, .L7F0BCB68
/* 0F1680 7F0BCB50 AFA5212C */   sw    $a1, 0x212c($sp)
/* 0F1684 7F0BCB54 8CC40004 */  lw    $a0, 4($a2)
/* 0F1688 7F0BCB58 0FC33FE7 */  jal   load_resource_on_indy
/* 0F168C 7F0BCB5C 02002825 */   move  $a1, $s0
/* 0F1690 7F0BCB60 1000002D */  b     .L7F0BCC18
/* 0F1694 7F0BCB64 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BCB68:
/* 0F1698 7F0BCB68 8CC40004 */  lw    $a0, 4($a2)
/* 0F169C 7F0BCB6C AFA62130 */  sw    $a2, 0x2130($sp)
/* 0F16A0 7F0BCB70 0FC34026 */  jal   check_file_found_on_indy
/* 0F16A4 7F0BCB74 26250008 */   addiu $a1, $s1, 8
/* 0F16A8 7F0BCB78 8E390008 */  lw    $t9, 8($s1)
/* 0F16AC 7F0BCB7C 8FAF212C */  lw    $t7, 0x212c($sp)
/* 0F16B0 7F0BCB80 2401FFF8 */  li    $at, -8
/* 0F16B4 7F0BCB84 27280007 */  addiu $t0, $t9, 7
/* 0F16B8 7F0BCB88 01014824 */  and   $t1, $t0, $at
/* 0F16BC 7F0BCB8C 020FC021 */  addu  $t8, $s0, $t7
/* 0F16C0 7F0BCB90 03093823 */  subu  $a3, $t8, $t1
/* 0F16C4 7F0BCB94 00F05023 */  subu  $t2, $a3, $s0
/* 0F16C8 7F0BCB98 2D410008 */  sltiu $at, $t2, 8
/* 0F16CC 7F0BCB9C 10200003 */  beqz  $at, .L7F0BCBAC
/* 0F16D0 7F0BCBA0 8FA62130 */   lw    $a2, 0x2130($sp)
/* 0F16D4 7F0BCBA4 1000001B */  b     .L7F0BCC14
/* 0F16D8 7F0BCBA8 AE200004 */   sw    $zero, 4($s1)
.L7F0BCBAC:
/* 0F16DC 7F0BCBAC 8CC40004 */  lw    $a0, 4($a2)
/* 0F16E0 7F0BCBB0 AFA72124 */  sw    $a3, 0x2124($sp)
/* 0F16E4 7F0BCBB4 0FC33FE7 */  jal   load_resource_on_indy
/* 0F16E8 7F0BCBB8 00E02825 */   move  $a1, $a3
/* 0F16EC 7F0BCBBC 8FA72124 */  lw    $a3, 0x2124($sp)
/* 0F16F0 7F0BCBC0 3C0C8006 */  lui   $t4, %hi(rz_header_1) # $t4, 0x8006
/* 0F16F4 7F0BCBC4 918CB66C */  lbu   $t4, %lo(rz_header_1)($t4)
/* 0F16F8 7F0BCBC8 90EB0000 */  lbu   $t3, ($a3)
/* 0F16FC 7F0BCBCC 3C0E8006 */  lui   $t6, %hi(rz_header_2 + 0x1) # $t6, 0x8006
/* 0F1700 7F0BCBD0 02002825 */  move  $a1, $s0
/* 0F1704 7F0BCBD4 156C000B */  bne   $t3, $t4, .L7F0BCC04
/* 0F1708 7F0BCBD8 00E02025 */   move  $a0, $a3
/* 0F170C 7F0BCBDC 90ED0001 */  lbu   $t5, 1($a3)
/* 0F1710 7F0BCBE0 91CEB671 */  lbu   $t6, %lo(rz_header_2 + 0x1)($t6)
/* 0F1714 7F0BCBE4 27A60024 */  addiu $a2, $sp, 0x24
/* 0F1718 7F0BCBE8 15AE0006 */  bne   $t5, $t6, .L7F0BCC04
/* 0F171C 7F0BCBEC 00000000 */   nop   
/* 0F1720 7F0BCBF0 00E02025 */  move  $a0, $a3
/* 0F1724 7F0BCBF4 0FC339FC */  jal   decompressdata
/* 0F1728 7F0BCBF8 02002825 */   move  $a1, $s0
/* 0F172C 7F0BCBFC 10000004 */  b     .L7F0BCC10
/* 0F1730 7F0BCC00 00401825 */   move  $v1, $v0
.L7F0BCC04:
/* 0F1734 7F0BCC04 0C003E5C */  jal   _bcopy
/* 0F1738 7F0BCC08 8E260008 */   lw    $a2, 8($s1)
/* 0F173C 7F0BCC0C 8E230008 */  lw    $v1, 8($s1)
.L7F0BCC10:
/* 0F1740 7F0BCC10 AE230004 */  sw    $v1, 4($s1)
.L7F0BCC14:
/* 0F1744 7F0BCC14 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BCC18:
/* 0F1748 7F0BCC18 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F174C 7F0BCC1C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1750 7F0BCC20 03E00008 */  jr    $ra
/* 0F1754 7F0BCC24 27BD2128 */   addiu $sp, $sp, 0x2128
)
#endif





#ifdef NONMATCHING
void *ob_c_debug_setup(void) {
    s32 temp_v1;
    u32 temp_v0;
    void *phi_a0;
    u32 phi_v0;

    // Node 0
    get_ptr_debug_notice_list_entry(&D_80046050, &aOb_c_debug);
    temp_v1 = (file_entry_max + -1);
    if (temp_v1 >= 2)
    {
        // Node 1
        phi_a0 = (void *) (file_resource_table + 0xc);
        phi_v0 = &ptr_res_data_next;
loop_2:
        // Node 2
        temp_v0 = (phi_v0 + 0x14);
        temp_v0->unk-14 = (s32) (phi_a0->unk14 - phi_a0->unk8);
        temp_v0->unk-10 = 0;
        temp_v0->unk-C = 0;
        temp_v0->unk-8 = 0;
        phi_a0 = (phi_a0 + 0xc);
        phi_v0 = temp_v0;
        if (temp_v0 < (u32) ((temp_v1 * 0x14) + &ptr_resource_data))
        {
            goto loop_2;
        }
    }
    // Node 3
    return &ptr_res_data_next;
}
#else
GLOBAL_ASM(
.text
glabel ob_c_debug_setup
/* 0F1758 7F0BCC28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F175C 7F0BCC2C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1760 7F0BCC30 3C048004 */  lui   $a0, %hi(D_80046050) # $a0, 0x8004
/* 0F1764 7F0BCC34 3C058006 */  lui   $a1, %hi(aOb_c_debug) # $a1, 0x8006
/* 0F1768 7F0BCC38 24A5B674 */  addiu $a1, %lo(aOb_c_debug) # addiu $a1, $a1, -0x498c
/* 0F176C 7F0BCC3C 0C001398 */  jal   get_ptr_debug_notice_list_entry
/* 0F1770 7F0BCC40 24846050 */   addiu $a0, %lo(D_80046050) # addiu $a0, $a0, 0x6050
/* 0F1774 7F0BCC44 3C038005 */  lui   $v1, %hi(file_entry_max) # $v1, 0x8005
/* 0F1778 7F0BCC48 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F177C 7F0BCC4C 3C048004 */  lui   $a0, %hi(file_resource_table + 0xC) # $a0, 0x8004
/* 0F1780 7F0BCC50 24846060 */  addiu $a0, %lo(file_resource_table + 0xC) # addiu $a0, $a0, 0x6060
/* 0F1784 7F0BCC54 2463FFFF */  addiu $v1, $v1, -1
/* 0F1788 7F0BCC58 28610002 */  slti  $at, $v1, 2
/* 0F178C 7F0BCC5C 14200013 */  bnez  $at, .L7F0BCCAC
/* 0F1790 7F0BCC60 3C028009 */   lui   $v0, %hi(ptr_res_data_next) # $v0, 0x8009
/* 0F1794 7F0BCC64 00037080 */  sll   $t6, $v1, 2
/* 0F1798 7F0BCC68 01C37021 */  addu  $t6, $t6, $v1
/* 0F179C 7F0BCC6C 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) # $t7, 0x8009
/* 0F17A0 7F0BCC70 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F17A4 7F0BCC74 000E7080 */  sll   $t6, $t6, 2
/* 0F17A8 7F0BCC78 01CF2821 */  addu  $a1, $t6, $t7
/* 0F17AC 7F0BCC7C 244288C4 */  addiu $v0, %lo(ptr_res_data_next) # addiu $v0, $v0, -0x773c
.L7F0BCC80:
/* 0F17B0 7F0BCC80 8C980014 */  lw    $t8, 0x14($a0)
/* 0F17B4 7F0BCC84 8C990008 */  lw    $t9, 8($a0)
/* 0F17B8 7F0BCC88 24420014 */  addiu $v0, $v0, 0x14
/* 0F17BC 7F0BCC8C 0045082B */  sltu  $at, $v0, $a1
/* 0F17C0 7F0BCC90 03191823 */  subu  $v1, $t8, $t9
/* 0F17C4 7F0BCC94 2484000C */  addiu $a0, $a0, 0xc
/* 0F17C8 7F0BCC98 AC43FFEC */  sw    $v1, -0x14($v0)
/* 0F17CC 7F0BCC9C AC40FFF0 */  sw    $zero, -0x10($v0)
/* 0F17D0 7F0BCCA0 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 0F17D4 7F0BCCA4 1420FFF6 */  bnez  $at, .L7F0BCC80
/* 0F17D8 7F0BCCA8 AC40FFF8 */   sw    $zero, -8($v0)
.L7F0BCCAC:
/* 0F17DC 7F0BCCAC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F17E0 7F0BCCB0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F17E4 7F0BCCB4 03E00008 */  jr    $ra
/* 0F17E8 7F0BCCB8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void _load_rom_index_to_membank(s32 arg3) {
    load_rom_resource_index_to_membank((arg3 & 0xff));
}

#else
GLOBAL_ASM(
.text
glabel _load_rom_index_to_membank
/* 0F17EC 7F0BCCBC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F17F0 7F0BCCC0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F17F4 7F0BCCC4 AFA70024 */  sw    $a3, 0x24($sp)
/* 0F17F8 7F0BCCC8 30EE00FF */  andi  $t6, $a3, 0xff
/* 0F17FC 7F0BCCCC 0FC2F383 */  jal   load_rom_resource_index_to_membank
/* 0F1800 7F0BCCD0 01C03825 */   move  $a3, $t6
/* 0F1804 7F0BCCD4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1808 7F0BCCD8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F180C 7F0BCCDC 03E00008 */  jr    $ra
/* 0F1810 7F0BCCE0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void _load_resource_index_to_membank(void) {
    load_resource_index_to_buffer();
}
#else
GLOBAL_ASM(
.text
glabel _load_resource_index_to_membank
/* 0F1814 7F0BCCE4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1818 7F0BCCE8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F181C 7F0BCCEC 0FC2F3F8 */  jal   load_resource_index_to_buffer
/* 0F1820 7F0BCCF0 00000000 */   nop   
/* 0F1824 7F0BCCF4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1828 7F0BCCF8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F182C 7F0BCCFC 03E00008 */  jr    $ra
/* 0F1830 7F0BCD00 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void _load_resource_named_to_membank(s32 arg1, ? arg2, ? arg3, ? arg_unalignedF) {
    // Node 0
    return load_rom_resource_index_to_membank(get_index_num_of_named_resource(), arg1, arg2, arg_unalignedF);
}
#else
GLOBAL_ASM(
.text
glabel _load_resource_named_to_membank
/* 0F1834 7F0BCD04 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1838 7F0BCD08 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F183C 7F0BCD0C AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F1840 7F0BCD10 AFA60020 */  sw    $a2, 0x20($sp)
/* 0F1844 7F0BCD14 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0F1848 7F0BCD18 AFA70024 */   sw    $a3, 0x24($sp)
/* 0F184C 7F0BCD1C 00402025 */  move  $a0, $v0
/* 0F1850 7F0BCD20 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0F1854 7F0BCD24 8FA60020 */  lw    $a2, 0x20($sp)
/* 0F1858 7F0BCD28 0FC2F383 */  jal   load_rom_resource_index_to_membank
/* 0F185C 7F0BCD2C 93A70027 */   lbu   $a3, 0x27($sp)
/* 0F1860 7F0BCD30 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1864 7F0BCD34 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F1868 7F0BCD38 03E00008 */  jr    $ra
/* 0F186C 7F0BCD3C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void _load_resource_named_to_buffer(s32 arg1, ? arg2, ? arg3) {
    load_resource_index_to_buffer(get_index_num_of_named_resource(), arg1, arg2, arg3);
}

#else
GLOBAL_ASM(
.text
glabel _load_resource_named_to_buffer
/* 0F1870 7F0BCD40 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1874 7F0BCD44 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1878 7F0BCD48 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F187C 7F0BCD4C AFA60020 */  sw    $a2, 0x20($sp)
/* 0F1880 7F0BCD50 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0F1884 7F0BCD54 AFA70024 */   sw    $a3, 0x24($sp)
/* 0F1888 7F0BCD58 00402025 */  move  $a0, $v0
/* 0F188C 7F0BCD5C 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0F1890 7F0BCD60 8FA60020 */  lw    $a2, 0x20($sp)
/* 0F1894 7F0BCD64 0FC2F3F8 */  jal   load_resource_index_to_buffer
/* 0F1898 7F0BCD68 8FA70024 */   lw    $a3, 0x24($sp)
/* 0F189C 7F0BCD6C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F18A0 7F0BCD70 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F18A4 7F0BCD74 03E00008 */  jr    $ra
/* 0F18A8 7F0BCD78 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void load_bg_bytes_at_offset_to_membank(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_bg_bytes_at_offset_to_membank
/* 0F18AC 7F0BCD7C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F18B0 7F0BCD80 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F18B4 7F0BCD84 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F18B8 7F0BCD88 AFA60020 */  sw    $a2, 0x20($sp)
/* 0F18BC 7F0BCD8C 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0F18C0 7F0BCD90 AFA70024 */   sw    $a3, 0x24($sp)
/* 0F18C4 7F0BCD94 0002C080 */  sll   $t8, $v0, 2
/* 0F18C8 7F0BCD98 0302C021 */  addu  $t8, $t8, $v0
/* 0F18CC 7F0BCD9C 0018C080 */  sll   $t8, $t8, 2
/* 0F18D0 7F0BCDA0 3C038009 */  lui   $v1, 0x8009
/* 0F18D4 7F0BCDA4 00781821 */  addu  $v1, $v1, $t8
/* 0F18D8 7F0BCDA8 8C6388B0 */  lw    $v1, -0x7750($v1)
/* 0F18DC 7F0BCDAC 00027080 */  sll   $t6, $v0, 2
/* 0F18E0 7F0BCDB0 01C27023 */  subu  $t6, $t6, $v0
/* 0F18E4 7F0BCDB4 3C0F8004 */  lui   $t7, %hi(file_resource_table) # $t7, 0x8004
/* 0F18E8 7F0BCDB8 25EF6054 */  addiu $t7, %lo(file_resource_table) # addiu $t7, $t7, 0x6054
/* 0F18EC 7F0BCDBC 000E7080 */  sll   $t6, $t6, 2
/* 0F18F0 7F0BCDC0 8FA60024 */  lw    $a2, 0x24($sp)
/* 0F18F4 7F0BCDC4 8FA80020 */  lw    $t0, 0x20($sp)
/* 0F18F8 7F0BCDC8 1060000C */  beqz  $v1, .L7F0BCDFC
/* 0F18FC 7F0BCDCC 01CF3821 */   addu  $a3, $t6, $t7
/* 0F1900 7F0BCDD0 0106C821 */  addu  $t9, $t0, $a2
/* 0F1904 7F0BCDD4 2469000F */  addiu $t1, $v1, 0xf
/* 0F1908 7F0BCDD8 0139082B */  sltu  $at, $t1, $t9
/* 0F190C 7F0BCDDC 50200004 */  beql  $at, $zero, .L7F0BCDF0
/* 0F1910 7F0BCDE0 8CEA0008 */   lw    $t2, 8($a3)
.L7F0BCDE4:
/* 0F1914 7F0BCDE4 1000FFFF */  b     .L7F0BCDE4
/* 0F1918 7F0BCDE8 00000000 */   nop   
/* 0F191C 7F0BCDEC 8CEA0008 */  lw    $t2, 8($a3)
.L7F0BCDF0:
/* 0F1920 7F0BCDF0 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0F1924 7F0BCDF4 0C001707 */  jal   romCopy
/* 0F1928 7F0BCDF8 01482821 */   addu  $a1, $t2, $t0
.L7F0BCDFC:
/* 0F192C 7F0BCDFC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1930 7F0BCE00 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F1934 7F0BCE04 03E00008 */  jr    $ra
/* 0F1938 7F0BCE08 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void load_rom_resource_index_to_membank(void) {

}
#else
GLOBAL_ASM(
.text
glabel load_rom_resource_index_to_membank
/* 0F193C 7F0BCE0C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F1940 7F0BCE10 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1944 7F0BCE14 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1948 7F0BCE18 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F194C 7F0BCE1C AFA40030 */  sw    $a0, 0x30($sp)
/* 0F1950 7F0BCE20 AFA50034 */  sw    $a1, 0x34($sp)
/* 0F1954 7F0BCE24 AFA60038 */  sw    $a2, 0x38($sp)
/* 0F1958 7F0BCE28 10A00006 */  beqz  $a1, .L7F0BCE44
/* 0F195C 7F0BCE2C AFA7003C */   sw    $a3, 0x3c($sp)
/* 0F1960 7F0BCE30 24010001 */  li    $at, 1
/* 0F1964 7F0BCE34 10A10003 */  beq   $a1, $at, .L7F0BCE44
/* 0F1968 7F0BCE38 24010002 */   li    $at, 2
/* 0F196C 7F0BCE3C 14A10033 */  bne   $a1, $at, .L7F0BCF0C
/* 0F1970 7F0BCE40 8FAD0030 */   lw    $t5, 0x30($sp)
.L7F0BCE44:
/* 0F1974 7F0BCE44 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0F1978 7F0BCE48 3C198009 */  lui   $t9, %hi(ptr_resource_data) # $t9, 0x8009
/* 0F197C 7F0BCE4C 273988B0 */  addiu $t9, %lo(ptr_resource_data) # addiu $t9, $t9, -0x7750
/* 0F1980 7F0BCE50 000FC080 */  sll   $t8, $t7, 2
/* 0F1984 7F0BCE54 030FC021 */  addu  $t8, $t8, $t7
/* 0F1988 7F0BCE58 0018C080 */  sll   $t8, $t8, 2
/* 0F198C 7F0BCE5C 03198821 */  addu  $s1, $t8, $t9
/* 0F1990 7F0BCE60 8E300004 */  lw    $s0, 4($s1)
/* 0F1994 7F0BCE64 56000006 */  bnezl $s0, .L7F0BCE80
/* 0F1998 7F0BCE68 02002025 */   move  $a0, $s0
/* 0F199C 7F0BCE6C 0C002644 */  jal   memp_related_3
/* 0F19A0 7F0BCE70 93A4003F */   lbu   $a0, 0x3f($sp)
/* 0F19A4 7F0BCE74 AE220004 */  sw    $v0, 4($s1)
/* 0F19A8 7F0BCE78 00408025 */  move  $s0, $v0
/* 0F19AC 7F0BCE7C 02002025 */  move  $a0, $s0
.L7F0BCE80:
/* 0F19B0 7F0BCE80 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0F19B4 7F0BCE84 93A5003F */   lbu   $a1, 0x3f($sp)
/* 0F19B8 7F0BCE88 8E300004 */  lw    $s0, 4($s1)
/* 0F19BC 7F0BCE8C 3C0A8004 */  lui   $t2, %hi(file_resource_table) # $t2, 0x8004
/* 0F19C0 7F0BCE90 254A6054 */  addiu $t2, %lo(file_resource_table) # addiu $t2, $t2, 0x6054
/* 0F19C4 7F0BCE94 AE30000C */  sw    $s0, 0xc($s1)
/* 0F19C8 7F0BCE98 8FA80030 */  lw    $t0, 0x30($sp)
/* 0F19CC 7F0BCE9C 00402025 */  move  $a0, $v0
/* 0F19D0 7F0BCEA0 02203825 */  move  $a3, $s1
/* 0F19D4 7F0BCEA4 00084880 */  sll   $t1, $t0, 2
/* 0F19D8 7F0BCEA8 01284823 */  subu  $t1, $t1, $t0
/* 0F19DC 7F0BCEAC 00094880 */  sll   $t1, $t1, 2
/* 0F19E0 7F0BCEB0 012A3021 */  addu  $a2, $t1, $t2
/* 0F19E4 7F0BCEB4 8CCB0008 */  lw    $t3, 8($a2)
/* 0F19E8 7F0BCEB8 02002825 */  move  $a1, $s0
/* 0F19EC 7F0BCEBC 15600007 */  bnez  $t3, .L7F0BCEDC
/* 0F19F0 7F0BCEC0 00000000 */   nop   
/* 0F19F4 7F0BCEC4 02002825 */  move  $a1, $s0
/* 0F19F8 7F0BCEC8 02203825 */  move  $a3, $s1
/* 0F19FC 7F0BCECC 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1A00 7F0BCED0 AFA20024 */   sw    $v0, 0x24($sp)
/* 0F1A04 7F0BCED4 10000004 */  b     .L7F0BCEE8
/* 0F1A08 7F0BCED8 8FB00024 */   lw    $s0, 0x24($sp)
.L7F0BCEDC:
/* 0F1A0C 7F0BCEDC 0FC2F2A8 */  jal   load_resource
/* 0F1A10 7F0BCEE0 AFA40024 */   sw    $a0, 0x24($sp)
/* 0F1A14 7F0BCEE4 8FB00024 */  lw    $s0, 0x24($sp)
.L7F0BCEE8:
/* 0F1A18 7F0BCEE8 8FAC0034 */  lw    $t4, 0x34($sp)
/* 0F1A1C 7F0BCEEC 02002025 */  move  $a0, $s0
/* 0F1A20 7F0BCEF0 93A6003F */  lbu   $a2, 0x3f($sp)
/* 0F1A24 7F0BCEF4 51800035 */  beql  $t4, $zero, .L7F0BCFCC
/* 0F1A28 7F0BCEF8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0F1A2C 7F0BCEFC 0C002601 */  jal   memp_related_1
/* 0F1A30 7F0BCF00 8E250004 */   lw    $a1, 4($s1)
/* 0F1A34 7F0BCF04 10000031 */  b     .L7F0BCFCC
/* 0F1A38 7F0BCF08 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BCF0C:
/* 0F1A3C 7F0BCF0C 000D7080 */  sll   $t6, $t5, 2
/* 0F1A40 7F0BCF10 01CD7021 */  addu  $t6, $t6, $t5
/* 0F1A44 7F0BCF14 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) # $t7, 0x8009
/* 0F1A48 7F0BCF18 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F1A4C 7F0BCF1C 000E7080 */  sll   $t6, $t6, 2
/* 0F1A50 7F0BCF20 01CF8821 */  addu  $s1, $t6, $t7
/* 0F1A54 7F0BCF24 8E300004 */  lw    $s0, 4($s1)
/* 0F1A58 7F0BCF28 56000009 */  bnezl $s0, .L7F0BCF50
/* 0F1A5C 7F0BCF2C 02002025 */   move  $a0, $s0
/* 0F1A60 7F0BCF30 8E220000 */  lw    $v0, ($s1)
/* 0F1A64 7F0BCF34 10400003 */  beqz  $v0, .L7F0BCF44
/* 0F1A68 7F0BCF38 00408025 */   move  $s0, $v0
/* 0F1A6C 7F0BCF3C 10000003 */  b     .L7F0BCF4C
/* 0F1A70 7F0BCF40 AE220004 */   sw    $v0, 4($s1)
.L7F0BCF44:
/* 0F1A74 7F0BCF44 8E300008 */  lw    $s0, 8($s1)
/* 0F1A78 7F0BCF48 AE300004 */  sw    $s0, 4($s1)
.L7F0BCF4C:
/* 0F1A7C 7F0BCF4C 02002025 */  move  $a0, $s0
.L7F0BCF50:
/* 0F1A80 7F0BCF50 0C0025C8 */  jal   allocate_bytes_in_bank
/* 0F1A84 7F0BCF54 93A5003F */   lbu   $a1, 0x3f($sp)
/* 0F1A88 7F0BCF58 8E390004 */  lw    $t9, 4($s1)
/* 0F1A8C 7F0BCF5C 3C0A8004 */  lui   $t2, %hi(file_resource_table) # $t2, 0x8004
/* 0F1A90 7F0BCF60 254A6054 */  addiu $t2, %lo(file_resource_table) # addiu $t2, $t2, 0x6054
/* 0F1A94 7F0BCF64 AE39000C */  sw    $t9, 0xc($s1)
/* 0F1A98 7F0BCF68 8FA80030 */  lw    $t0, 0x30($sp)
/* 0F1A9C 7F0BCF6C 00408025 */  move  $s0, $v0
/* 0F1AA0 7F0BCF70 02203825 */  move  $a3, $s1
/* 0F1AA4 7F0BCF74 00084880 */  sll   $t1, $t0, 2
/* 0F1AA8 7F0BCF78 01284823 */  subu  $t1, $t1, $t0
/* 0F1AAC 7F0BCF7C 00094880 */  sll   $t1, $t1, 2
/* 0F1AB0 7F0BCF80 012A3021 */  addu  $a2, $t1, $t2
/* 0F1AB4 7F0BCF84 8CCB0008 */  lw    $t3, 8($a2)
/* 0F1AB8 7F0BCF88 02002025 */  move  $a0, $s0
/* 0F1ABC 7F0BCF8C 00002825 */  move  $a1, $zero
/* 0F1AC0 7F0BCF90 15600006 */  bnez  $t3, .L7F0BCFAC
/* 0F1AC4 7F0BCF94 00000000 */   nop   
/* 0F1AC8 7F0BCF98 00402025 */  move  $a0, $v0
/* 0F1ACC 7F0BCF9C 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1AD0 7F0BCFA0 00002825 */   move  $a1, $zero
/* 0F1AD4 7F0BCFA4 10000004 */  b     .L7F0BCFB8
/* 0F1AD8 7F0BCFA8 8FAC0038 */   lw    $t4, 0x38($sp)
.L7F0BCFAC:
/* 0F1ADC 7F0BCFAC 0FC2F2A8 */  jal   load_resource
/* 0F1AE0 7F0BCFB0 02203825 */   move  $a3, $s1
/* 0F1AE4 7F0BCFB4 8FAC0038 */  lw    $t4, 0x38($sp)
.L7F0BCFB8:
/* 0F1AE8 7F0BCFB8 93AD003F */  lbu   $t5, 0x3f($sp)
/* 0F1AEC 7F0BCFBC 55800003 */  bnezl $t4, .L7F0BCFCC
/* 0F1AF0 7F0BCFC0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0F1AF4 7F0BCFC4 A22D0010 */  sb    $t5, 0x10($s1)
/* 0F1AF8 7F0BCFC8 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BCFCC:
/* 0F1AFC 7F0BCFCC 02001025 */  move  $v0, $s0
/* 0F1B00 7F0BCFD0 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1B04 7F0BCFD4 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1B08 7F0BCFD8 03E00008 */  jr    $ra
/* 0F1B0C 7F0BCFDC 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void load_resource_index_to_buffer(s32 arg0, s32 arg1, ? arg2, ?32 arg3) {
    void *temp_s0;
    void *temp_a2;
    void *temp_a2_2;

    // Node 0
    temp_s0 = ((arg0 * 0x14) + &ptr_resource_data);
    if (temp_s0->unk4 == 0)
    {
        // Node 1
        if (*temp_s0 != 0)
        {
            // Node 2
            temp_s0->unk4 = (s32) *temp_s0;
        }
        else
        {
            // Node 3
            temp_s0->unk4 = (s32) temp_s0->unk8;
        }
    }
    // Node 4
    if (((arg1 == 0) || (arg1 == 2)) || (arg1 == 2))
    {
        // Node 7
        temp_a2_2 = ((arg0 * 0xc) + &file_resource_table);
        if (temp_a2_2->unk8 == 0)
        {
            // Node 8
            temp_s0->unkC = arg3;
            resource_load_from_indy(arg2, arg3, temp_a2_2, temp_s0);
        }
        else
        {
            // Node 9
            temp_s0->unkC = arg3;
            load_resource(arg2, arg3, temp_a2_2, temp_s0);
        }
    }
    else
    {
        // Node 10
        temp_a2 = ((arg0 * 0xc) + &file_resource_table);
        if (temp_a2->unk8 == 0)
        {
            // Node 11
            resource_load_from_indy(arg2, 0, temp_a2, temp_s0);
        }
        else
        {
            // Node 12
            load_resource(arg2, 0, temp_a2, temp_s0);
        }
    }
    // Node 13
    return arg2;
}
#else
GLOBAL_ASM(
.text
glabel load_resource_index_to_buffer
/* 0F1B10 7F0BCFE0 00047080 */  sll   $t6, $a0, 2
/* 0F1B14 7F0BCFE4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1B18 7F0BCFE8 01C47021 */  addu  $t6, $t6, $a0
/* 0F1B1C 7F0BCFEC 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) # $t7, 0x8009
/* 0F1B20 7F0BCFF0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F1B24 7F0BCFF4 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F1B28 7F0BCFF8 000E7080 */  sll   $t6, $t6, 2
/* 0F1B2C 7F0BCFFC 01CF8021 */  addu  $s0, $t6, $t7
/* 0F1B30 7F0BD000 8E180004 */  lw    $t8, 4($s0)
/* 0F1B34 7F0BD004 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1B38 7F0BD008 AFA60028 */  sw    $a2, 0x28($sp)
/* 0F1B3C 7F0BD00C 17000008 */  bnez  $t8, .L7F0BD030
/* 0F1B40 7F0BD010 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0F1B44 7F0BD014 8E020000 */  lw    $v0, ($s0)
/* 0F1B48 7F0BD018 50400004 */  beql  $v0, $zero, .L7F0BD02C
/* 0F1B4C 7F0BD01C 8E190008 */   lw    $t9, 8($s0)
/* 0F1B50 7F0BD020 10000003 */  b     .L7F0BD030
/* 0F1B54 7F0BD024 AE020004 */   sw    $v0, 4($s0)
/* 0F1B58 7F0BD028 8E190008 */  lw    $t9, 8($s0)
.L7F0BD02C:
/* 0F1B5C 7F0BD02C AE190004 */  sw    $t9, 4($s0)
.L7F0BD030:
/* 0F1B60 7F0BD030 10A00005 */  beqz  $a1, .L7F0BD048
/* 0F1B64 7F0BD034 24010001 */   li    $at, 1
/* 0F1B68 7F0BD038 10A10003 */  beq   $a1, $at, .L7F0BD048
/* 0F1B6C 7F0BD03C 24010002 */   li    $at, 2
/* 0F1B70 7F0BD040 14A10019 */  bne   $a1, $at, .L7F0BD0A8
/* 0F1B74 7F0BD044 00046880 */   sll   $t5, $a0, 2
.L7F0BD048:
/* 0F1B78 7F0BD048 00044080 */  sll   $t0, $a0, 2
/* 0F1B7C 7F0BD04C 01044023 */  subu  $t0, $t0, $a0
/* 0F1B80 7F0BD050 3C098004 */  lui   $t1, %hi(file_resource_table) # $t1, 0x8004
/* 0F1B84 7F0BD054 25296054 */  addiu $t1, %lo(file_resource_table) # addiu $t1, $t1, 0x6054
/* 0F1B88 7F0BD058 00084080 */  sll   $t0, $t0, 2
/* 0F1B8C 7F0BD05C 01093021 */  addu  $a2, $t0, $t1
/* 0F1B90 7F0BD060 8CCA0008 */  lw    $t2, 8($a2)
/* 0F1B94 7F0BD064 8FAB002C */  lw    $t3, 0x2c($sp)
/* 0F1B98 7F0BD068 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0F1B9C 7F0BD06C 15400008 */  bnez  $t2, .L7F0BD090
/* 0F1BA0 7F0BD070 02003825 */   move  $a3, $s0
/* 0F1BA4 7F0BD074 AE0B000C */  sw    $t3, 0xc($s0)
/* 0F1BA8 7F0BD078 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1BAC 7F0BD07C 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0F1BB0 7F0BD080 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1BB4 7F0BD084 02003825 */   move  $a3, $s0
/* 0F1BB8 7F0BD088 10000019 */  b     .L7F0BD0F0
/* 0F1BBC 7F0BD08C 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD090:
/* 0F1BC0 7F0BD090 AE0C000C */  sw    $t4, 0xc($s0)
/* 0F1BC4 7F0BD094 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0F1BC8 7F0BD098 0FC2F2A8 */  jal   load_resource
/* 0F1BCC 7F0BD09C 8FA40028 */   lw    $a0, 0x28($sp)
/* 0F1BD0 7F0BD0A0 10000013 */  b     .L7F0BD0F0
/* 0F1BD4 7F0BD0A4 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD0A8:
/* 0F1BD8 7F0BD0A8 01A46823 */  subu  $t5, $t5, $a0
/* 0F1BDC 7F0BD0AC 3C0E8004 */  lui   $t6, %hi(file_resource_table) # $t6, 0x8004
/* 0F1BE0 7F0BD0B0 25CE6054 */  addiu $t6, %lo(file_resource_table) # addiu $t6, $t6, 0x6054
/* 0F1BE4 7F0BD0B4 000D6880 */  sll   $t5, $t5, 2
/* 0F1BE8 7F0BD0B8 01AE3021 */  addu  $a2, $t5, $t6
/* 0F1BEC 7F0BD0BC 8CCF0008 */  lw    $t7, 8($a2)
/* 0F1BF0 7F0BD0C0 02003825 */  move  $a3, $s0
/* 0F1BF4 7F0BD0C4 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1BF8 7F0BD0C8 15E00006 */  bnez  $t7, .L7F0BD0E4
/* 0F1BFC 7F0BD0CC 00002825 */   move  $a1, $zero
/* 0F1C00 7F0BD0D0 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1C04 7F0BD0D4 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1C08 7F0BD0D8 00002825 */   move  $a1, $zero
/* 0F1C0C 7F0BD0DC 10000004 */  b     .L7F0BD0F0
/* 0F1C10 7F0BD0E0 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD0E4:
/* 0F1C14 7F0BD0E4 0FC2F2A8 */  jal   load_resource
/* 0F1C18 7F0BD0E8 02003825 */   move  $a3, $s0
/* 0F1C1C 7F0BD0EC 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BD0F0:
/* 0F1C20 7F0BD0F0 8FA20028 */  lw    $v0, 0x28($sp)
/* 0F1C24 7F0BD0F4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F1C28 7F0BD0F8 03E00008 */  jr    $ra
/* 0F1C2C 7F0BD0FC 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void get_temp_remaining_buffer_for_index(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_temp_remaining_buffer_for_index
/* 0F1C30 7F0BD100 00047080 */  sll   $t6, $a0, 2
/* 0F1C34 7F0BD104 01C47021 */  addu  $t6, $t6, $a0
/* 0F1C38 7F0BD108 000E7080 */  sll   $t6, $t6, 2
/* 0F1C3C 7F0BD10C 3C028009 */  lui   $v0, 0x8009
/* 0F1C40 7F0BD110 004E1021 */  addu  $v0, $v0, $t6
/* 0F1C44 7F0BD114 03E00008 */  jr    $ra
/* 0F1C48 7F0BD118 8C4288B4 */   lw    $v0, -0x774c($v0)
)
#endif





#ifdef NONMATCHING
void get_remaining_buffer_for_index(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_remaining_buffer_for_index
/* 0F1C4C 7F0BD11C 00047080 */  sll   $t6, $a0, 2
/* 0F1C50 7F0BD120 01C47021 */  addu  $t6, $t6, $a0
/* 0F1C54 7F0BD124 000E7080 */  sll   $t6, $t6, 2
/* 0F1C58 7F0BD128 3C028009 */  lui   $v0, 0x8009
/* 0F1C5C 7F0BD12C 004E1021 */  addu  $v0, $v0, $t6
/* 0F1C60 7F0BD130 03E00008 */  jr    $ra
/* 0F1C64 7F0BD134 8C4288BC */   lw    $v0, -0x7744($v0)
)
#endif





#ifdef NONMATCHING
void *sub_GAME_7F0BD138(s32 arg0, s32 arg1, ?32 arg2, s32 arg3) {
    void *temp_v0;

    // Node 0
    temp_v0 = ((arg0 * 0x14) + &ptr_resource_data);
    temp_v0->unk4 = arg2;
    temp_v0->unkC = arg2;
    if (arg3 != 0)
    {
        // Node 1
        memp_related_1(arg1, arg2, 4);
        return;
        // (possible return value: memp_related_1(arg1, arg2, 4))
    }
    // (possible return value: temp_v0)
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD138
/* 0F1C68 7F0BD138 00047080 */  sll   $t6, $a0, 2
/* 0F1C6C 7F0BD13C 01C47021 */  addu  $t6, $t6, $a0
/* 0F1C70 7F0BD140 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) # $t7, 0x8009
/* 0F1C74 7F0BD144 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F1C78 7F0BD148 000E7080 */  sll   $t6, $t6, 2
/* 0F1C7C 7F0BD14C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1C80 7F0BD150 01CF1021 */  addu  $v0, $t6, $t7
/* 0F1C84 7F0BD154 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1C88 7F0BD158 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F1C8C 7F0BD15C AC460004 */  sw    $a2, 4($v0)
/* 0F1C90 7F0BD160 10E00005 */  beqz  $a3, .L7F0BD178
/* 0F1C94 7F0BD164 AC46000C */   sw    $a2, 0xc($v0)
/* 0F1C98 7F0BD168 00A02025 */  move  $a0, $a1
/* 0F1C9C 7F0BD16C 00C02825 */  move  $a1, $a2
/* 0F1CA0 7F0BD170 0C002601 */  jal   memp_related_1
/* 0F1CA4 7F0BD174 24060004 */   li    $a2, 4
.L7F0BD178:
/* 0F1CA8 7F0BD178 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1CAC 7F0BD17C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F1CB0 7F0BD180 03E00008 */  jr    $ra
/* 0F1CB4 7F0BD184 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD188(void) {
    // Node 0
    get_index_num_of_named_resource();
    return;
    // (possible return value: *((ptr_resource_data + 4) + (((get_index_num_of_named_resource() * 4) + get_index_num_of_named_resource()) * 4)))
}


#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD188
/* 0F1CB8 7F0BD188 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1CBC 7F0BD18C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1CC0 7F0BD190 0FC2F495 */  jal   get_index_num_of_named_resource
/* 0F1CC4 7F0BD194 00000000 */   nop   
/* 0F1CC8 7F0BD198 00027080 */  sll   $t6, $v0, 2
/* 0F1CCC 7F0BD19C 01C27021 */  addu  $t6, $t6, $v0
/* 0F1CD0 7F0BD1A0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1CD4 7F0BD1A4 000E7080 */  sll   $t6, $t6, 2
/* 0F1CD8 7F0BD1A8 3C028009 */  lui   $v0, %hi(ptr_resource_data+4)
/* 0F1CDC 7F0BD1AC 004E1021 */  addu  $v0, $v0, $t6
/* 0F1CE0 7F0BD1B0 8C4288B4 */  lw    $v0, %lo(ptr_resource_data+4)($v0)
/* 0F1CE4 7F0BD1B4 03E00008 */  jr    $ra
/* 0F1CE8 7F0BD1B8 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
s32 something_mem_bank_a0(s32 arg0) {
    s32 temp_t6;
    u32 temp_a1;
    void *phi_a1;

    // Node 0
    temp_t6 = (arg0 & 0xff);
    if (file_entry_max >= 2)
    {
        // Node 1
        phi_a1 = &ptr_res_data_next;
        // Node 2
        if (temp_t6 >= phi_a1->unk10)
        {
            // Node 3
            phi_a1->unk10 = (u8)0;
        }
        // Node 4
        if (4 == temp_t6)
        {
            // Node 5
            phi_a1->unk4 = 0;
        }
        // Node 6
        temp_a1 = (phi_a1 + 0x14);
        phi_a1 = temp_a1;
        if (temp_a1 < (u32) ((file_entry_max * 0x14) + &ptr_resource_data))
        {
            goto loop_2;
        }
    }
    // Node 7
    return temp_t6;
}
#else
GLOBAL_ASM(
.text
glabel something_mem_bank_a0
/* 0F1CEC 7F0BD1BC 3C038005 */  lui   $v1, %hi(file_entry_max) # $v1, 0x8005
/* 0F1CF0 7F0BD1C0 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F1CF4 7F0BD1C4 308E00FF */  andi  $t6, $a0, 0xff
/* 0F1CF8 7F0BD1C8 AFA40000 */  sw    $a0, ($sp)
/* 0F1CFC 7F0BD1CC 28610002 */  slti  $at, $v1, 2
/* 0F1D00 7F0BD1D0 14200016 */  bnez  $at, .L7F0BD22C
/* 0F1D04 7F0BD1D4 01C01025 */   move  $v0, $t6
/* 0F1D08 7F0BD1D8 00037880 */  sll   $t7, $v1, 2
/* 0F1D0C 7F0BD1DC 01E37821 */  addu  $t7, $t7, $v1
/* 0F1D10 7F0BD1E0 3C188009 */  lui   $t8, %hi(ptr_resource_data) # $t8, 0x8009
/* 0F1D14 7F0BD1E4 271888B0 */  addiu $t8, %lo(ptr_resource_data) # addiu $t8, $t8, -0x7750
/* 0F1D18 7F0BD1E8 000F7880 */  sll   $t7, $t7, 2
/* 0F1D1C 7F0BD1EC 3C058009 */  lui   $a1, %hi(ptr_res_data_next) # $a1, 0x8009
/* 0F1D20 7F0BD1F0 24A588C4 */  addiu $a1, %lo(ptr_res_data_next) # addiu $a1, $a1, -0x773c
/* 0F1D24 7F0BD1F4 01F83021 */  addu  $a2, $t7, $t8
/* 0F1D28 7F0BD1F8 24030004 */  li    $v1, 4
/* 0F1D2C 7F0BD1FC 90B90010 */  lbu   $t9, 0x10($a1)
.L7F0BD200:
/* 0F1D30 7F0BD200 0059082A */  slt   $at, $v0, $t9
/* 0F1D34 7F0BD204 14200002 */  bnez  $at, .L7F0BD210
/* 0F1D38 7F0BD208 00000000 */   nop   
/* 0F1D3C 7F0BD20C A0A00010 */  sb    $zero, 0x10($a1)
.L7F0BD210:
/* 0F1D40 7F0BD210 54620003 */  bnel  $v1, $v0, .L7F0BD220
/* 0F1D44 7F0BD214 24A50014 */   addiu $a1, $a1, 0x14
/* 0F1D48 7F0BD218 ACA00004 */  sw    $zero, 4($a1)
/* 0F1D4C 7F0BD21C 24A50014 */  addiu $a1, $a1, 0x14
.L7F0BD220:
/* 0F1D50 7F0BD220 00A6082B */  sltu  $at, $a1, $a2
/* 0F1D54 7F0BD224 5420FFF6 */  bnezl $at, .L7F0BD200
/* 0F1D58 7F0BD228 90B90010 */   lbu   $t9, 0x10($a1)
.L7F0BD22C:
/* 0F1D5C 7F0BD22C 03E00008 */  jr    $ra
/* 0F1D60 7F0BD230 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD234(void) {
    // Node 0
    something_mem_bank_a0(5);
    return;
    // (possible return value: something_mem_bank_a0(5))
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD234
/* 0F1D64 7F0BD234 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1D68 7F0BD238 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1D6C 7F0BD23C 0FC2F46F */  jal   something_mem_bank_a0
/* 0F1D70 7F0BD240 24040005 */   li    $a0, 5
/* 0F1D74 7F0BD244 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1D78 7F0BD248 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F1D7C 7F0BD24C 03E00008 */  jr    $ra
/* 0F1D80 7F0BD250 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void get_index_num_of_named_resource(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_index_num_of_named_resource
/* 0F1D84 7F0BD254 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F1D88 7F0BD258 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F1D8C 7F0BD25C 3C128005 */  lui   $s2, %hi(file_entry_max) # $s2, 0x8005
/* 0F1D90 7F0BD260 265282D4 */  addiu $s2, %lo(file_entry_max) # addiu $s2, $s2, -0x7d2c
/* 0F1D94 7F0BD264 8E420000 */  lw    $v0, ($s2)
/* 0F1D98 7F0BD268 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F1D9C 7F0BD26C AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1DA0 7F0BD270 28410002 */  slti  $at, $v0, 2
/* 0F1DA4 7F0BD274 00809825 */  move  $s3, $a0
/* 0F1DA8 7F0BD278 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F1DAC 7F0BD27C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1DB0 7F0BD280 14200012 */  bnez  $at, .L7F0BD2CC
/* 0F1DB4 7F0BD284 24110001 */   li    $s1, 1
/* 0F1DB8 7F0BD288 3C108004 */  lui   $s0, %hi(file_resource_table + 0xC) # $s0, 0x8004
/* 0F1DBC 7F0BD28C 26106060 */  addiu $s0, %lo(file_resource_table + 0xC) # addiu $s0, $s0, 0x6060
/* 0F1DC0 7F0BD290 8E050004 */  lw    $a1, 4($s0)
.L7F0BD294:
/* 0F1DC4 7F0BD294 50A00008 */  beql  $a1, $zero, .L7F0BD2B8
/* 0F1DC8 7F0BD298 8E420000 */   lw    $v0, ($s2)
/* 0F1DCC 7F0BD29C 0C002A13 */  jal   something_with_strings_0
/* 0F1DD0 7F0BD2A0 02602025 */   move  $a0, $s3
/* 0F1DD4 7F0BD2A4 54400004 */  bnezl $v0, .L7F0BD2B8
/* 0F1DD8 7F0BD2A8 8E420000 */   lw    $v0, ($s2)
/* 0F1DDC 7F0BD2AC 1000002E */  b     .L7F0BD368
/* 0F1DE0 7F0BD2B0 02201025 */   move  $v0, $s1
/* 0F1DE4 7F0BD2B4 8E420000 */  lw    $v0, ($s2)
.L7F0BD2B8:
/* 0F1DE8 7F0BD2B8 26310001 */  addiu $s1, $s1, 1
/* 0F1DEC 7F0BD2BC 2610000C */  addiu $s0, $s0, 0xc
/* 0F1DF0 7F0BD2C0 0222082A */  slt   $at, $s1, $v0
/* 0F1DF4 7F0BD2C4 5420FFF3 */  bnezl $at, .L7F0BD294
/* 0F1DF8 7F0BD2C8 8E050004 */   lw    $a1, 4($s0)
.L7F0BD2CC:
/* 0F1DFC 7F0BD2CC 284102E0 */  slti  $at, $v0, 0x2e0
/* 0F1E00 7F0BD2D0 14200003 */  bnez  $at, .L7F0BD2E0
/* 0F1E04 7F0BD2D4 00408825 */   move  $s1, $v0
/* 0F1E08 7F0BD2D8 10000023 */  b     .L7F0BD368
/* 0F1E0C 7F0BD2DC 00001025 */   move  $v0, $zero
.L7F0BD2E0:
/* 0F1E10 7F0BD2E0 244E0001 */  addiu $t6, $v0, 1
/* 0F1E14 7F0BD2E4 AE4E0000 */  sw    $t6, ($s2)
/* 0F1E18 7F0BD2E8 02602025 */  move  $a0, $s3
/* 0F1E1C 7F0BD2EC 0FC34026 */  jal   check_file_found_on_indy
/* 0F1E20 7F0BD2F0 27A50034 */   addiu $a1, $sp, 0x34
/* 0F1E24 7F0BD2F4 14400003 */  bnez  $v0, .L7F0BD304
/* 0F1E28 7F0BD2F8 00117880 */   sll   $t7, $s1, 2
/* 0F1E2C 7F0BD2FC 1000001A */  b     .L7F0BD368
/* 0F1E30 7F0BD300 00001025 */   move  $v0, $zero
.L7F0BD304:
/* 0F1E34 7F0BD304 01F17823 */  subu  $t7, $t7, $s1
/* 0F1E38 7F0BD308 3C188004 */  lui   $t8, %hi(file_resource_table) # $t8, 0x8004
/* 0F1E3C 7F0BD30C 27186054 */  addiu $t8, %lo(file_resource_table) # addiu $t8, $t8, 0x6054
/* 0F1E40 7F0BD310 000F7880 */  sll   $t7, $t7, 2
/* 0F1E44 7F0BD314 0011C880 */  sll   $t9, $s1, 2
/* 0F1E48 7F0BD318 01F88021 */  addu  $s0, $t7, $t8
/* 0F1E4C 7F0BD31C 0331C821 */  addu  $t9, $t9, $s1
/* 0F1E50 7F0BD320 3C088009 */  lui   $t0, %hi(ptr_resource_data) # $t0, 0x8009
/* 0F1E54 7F0BD324 250888B0 */  addiu $t0, %lo(ptr_resource_data) # addiu $t0, $t0, -0x7750
/* 0F1E58 7F0BD328 0019C880 */  sll   $t9, $t9, 2
/* 0F1E5C 7F0BD32C AE110000 */  sw    $s1, ($s0)
/* 0F1E60 7F0BD330 AE130004 */  sw    $s3, 4($s0)
/* 0F1E64 7F0BD334 03281821 */  addu  $v1, $t9, $t0
/* 0F1E68 7F0BD338 A0600011 */  sb    $zero, 0x11($v1)
/* 0F1E6C 7F0BD33C AE000008 */  sw    $zero, 8($s0)
/* 0F1E70 7F0BD340 AC600000 */  sw    $zero, ($v1)
/* 0F1E74 7F0BD344 AC600004 */  sw    $zero, 4($v1)
/* 0F1E78 7F0BD348 8FA90034 */  lw    $t1, 0x34($sp)
/* 0F1E7C 7F0BD34C AC60000C */  sw    $zero, 0xc($v1)
/* 0F1E80 7F0BD350 A0600010 */  sb    $zero, 0x10($v1)
/* 0F1E84 7F0BD354 252A000F */  addiu $t2, $t1, 0xf
/* 0F1E88 7F0BD358 354B000F */  ori   $t3, $t2, 0xf
/* 0F1E8C 7F0BD35C 396C000F */  xori  $t4, $t3, 0xf
/* 0F1E90 7F0BD360 AC6C0008 */  sw    $t4, 8($v1)
/* 0F1E94 7F0BD364 02201025 */  move  $v0, $s1
.L7F0BD368:
/* 0F1E98 7F0BD368 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F1E9C 7F0BD36C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1EA0 7F0BD370 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1EA4 7F0BD374 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F1EA8 7F0BD378 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F1EAC 7F0BD37C 03E00008 */  jr    $ra
/* 0F1EB0 7F0BD380 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD384(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD384
/* 0F1EB4 7F0BD384 03E00008 */  jr    $ra
/* 0F1EB8 7F0BD388 AFA40000 */   sw    $a0, ($sp)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD38C(void) {
    s32 temp_s0;
    s32 phi_s0;

    // Node 0
    phi_s0 = 1;
    if (file_entry_max >= 2)
    {
loop_1:
        // Node 1
        sub_GAME_7F0BD384(phi_s0);
        temp_s0 = (phi_s0 + 1);
        phi_s0 = temp_s0;
        if (temp_s0 < file_entry_max)
        {
            goto loop_1;
        }
    }
    // Node 2
    return;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD38C
/* 0F1EBC 7F0BD38C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1EC0 7F0BD390 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1EC4 7F0BD394 3C118005 */  lui   $s1, %hi(file_entry_max) # $s1, 0x8005
/* 0F1EC8 7F0BD398 263182D4 */  addiu $s1, %lo(file_entry_max) # addiu $s1, $s1, -0x7d2c
/* 0F1ECC 7F0BD39C 8E2E0000 */  lw    $t6, ($s1)
/* 0F1ED0 7F0BD3A0 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1ED4 7F0BD3A4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1ED8 7F0BD3A8 29C10002 */  slti  $at, $t6, 2
/* 0F1EDC 7F0BD3AC 14200008 */  bnez  $at, .L7F0BD3D0
/* 0F1EE0 7F0BD3B0 24100001 */   li    $s0, 1
.L7F0BD3B4:
/* 0F1EE4 7F0BD3B4 0FC2F4E1 */  jal   sub_GAME_7F0BD384
/* 0F1EE8 7F0BD3B8 02002025 */   move  $a0, $s0
/* 0F1EEC 7F0BD3BC 8E2F0000 */  lw    $t7, ($s1)
/* 0F1EF0 7F0BD3C0 26100001 */  addiu $s0, $s0, 1
/* 0F1EF4 7F0BD3C4 020F082A */  slt   $at, $s0, $t7
/* 0F1EF8 7F0BD3C8 1420FFFA */  bnez  $at, .L7F0BD3B4
/* 0F1EFC 7F0BD3CC 00000000 */   nop   
.L7F0BD3D0:
/* 0F1F00 7F0BD3D0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1F04 7F0BD3D4 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1F08 7F0BD3D8 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1F0C 7F0BD3DC 03E00008 */  jr    $ra
/* 0F1F10 7F0BD3E0 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0BD3E4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD3E4
/* 0F1F14 7F0BD3E4 3C038005 */  lui   $v1, %hi(file_entry_max) # $v1, 0x8005
/* 0F1F18 7F0BD3E8 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F1F1C 7F0BD3EC 24020001 */  li    $v0, 1
/* 0F1F20 7F0BD3F0 28610002 */  slti  $at, $v1, 2
/* 0F1F24 7F0BD3F4 14200004 */  bnez  $at, .L7F0BD408
/* 0F1F28 7F0BD3F8 24420001 */   addiu $v0, $v0, 1
.L7F0BD3FC:
/* 0F1F2C 7F0BD3FC 0043082A */  slt   $at, $v0, $v1
/* 0F1F30 7F0BD400 5420FFFE */  bnezl $at, .L7F0BD3FC
/* 0F1F34 7F0BD404 24420001 */   addiu $v0, $v0, 1
.L7F0BD408:
/* 0F1F38 7F0BD408 03E00008 */  jr    $ra
/* 0F1F3C 7F0BD40C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void *sub_GAME_7F0BD410(void) {
    u32 temp_v0;
    u32 phi_v0;

    // Node 0
    if (file_entry_max >= 2)
    {
        // Node 1
        phi_v0 = &ptr_res_data_next;
loop_2:
        // Node 2
        temp_v0 = (phi_v0 + 0x14);
        phi_v0 = temp_v0;
        if (temp_v0 < (u32) ((file_entry_max * 0x14) + &ptr_resource_data))
        {
            goto loop_2;
        }
    }
    // Node 3
    return &ptr_res_data_next;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD410
/* 0F1F40 7F0BD410 3C038005 */  lui   $v1, %hi(file_entry_max) # $v1, 0x8005
/* 0F1F44 7F0BD414 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F1F48 7F0BD418 3C028009 */  lui   $v0, %hi(ptr_res_data_next) # $v0, 0x8009
/* 0F1F4C 7F0BD41C 244288C4 */  addiu $v0, %lo(ptr_res_data_next) # addiu $v0, $v0, -0x773c
/* 0F1F50 7F0BD420 28610002 */  slti  $at, $v1, 2
/* 0F1F54 7F0BD424 1420000A */  bnez  $at, .L7F0BD450
/* 0F1F58 7F0BD428 00037080 */   sll   $t6, $v1, 2
/* 0F1F5C 7F0BD42C 01C37021 */  addu  $t6, $t6, $v1
/* 0F1F60 7F0BD430 3C0F8009 */  lui   $t7, %hi(ptr_resource_data) # $t7, 0x8009
/* 0F1F64 7F0BD434 25EF88B0 */  addiu $t7, %lo(ptr_resource_data) # addiu $t7, $t7, -0x7750
/* 0F1F68 7F0BD438 000E7080 */  sll   $t6, $t6, 2
/* 0F1F6C 7F0BD43C 01CF2021 */  addu  $a0, $t6, $t7
/* 0F1F70 7F0BD440 24420014 */  addiu $v0, $v0, 0x14
.L7F0BD444:
/* 0F1F74 7F0BD444 0044082B */  sltu  $at, $v0, $a0
/* 0F1F78 7F0BD448 5420FFFE */  bnezl $at, .L7F0BD444
/* 0F1F7C 7F0BD44C 24420014 */   addiu $v0, $v0, 0x14
.L7F0BD450:
/* 0F1F80 7F0BD450 03E00008 */  jr    $ra
/* 0F1F84 7F0BD454 00000000 */   nop   
)
#endif


 
