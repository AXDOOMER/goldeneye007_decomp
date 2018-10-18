#include "ultra64.h"

/* bss
CODE.bss:800888B0     ptr_resource_data:resource_lookup_data <?>
CODE.bss:800888B0                                              # DATA XREF: ob_c_debug_setup+44o
CODE.bss:800888B0                                              # load_bg_bytes_at_offset_to_membank+24r
CODE.bss:800888B0                                              # load_rom_resource_index_to_membank+3Co
CODE.bss:800888B0                                              # load_rom_resource_index_to_membank+108o
CODE.bss:800888B0                                              # load_resource_index_to_buffer+14o
CODE.bss:800888B0                                              # sub_CODE_7F0BD138+8o
CODE.bss:800888B0                                              # something_mem_bank_a0+24o
CODE.bss:800888B0                                              # get_index_num_of_named_resource+CCo
CODE.bss:800888B0                                              # sub_CODE_7F0BD410+20o
CODE.bss:800888B0                                              # sub_CODE_7F0BD188+20r
CODE.bss:800888C4     ptr_res_data_next:resource_lookup_data <?>
CODE.bss:800888C4                                              # DATA XREF: ob_c_debug_setup+54o
CODE.bss:800888C4                                              # something_mem_bank_a0+30o
CODE.bss:800888C4                                              # sub_CODE_7F0BD410+8o
CODE.bss:800888D8     dword_CODE_bss_800888D8:.space 0x3958    # DATA XREF: sub_CODE_7F0BD410+30o
*/

/* data
D:80046050     dword_D_80046050:.word 0                 # DATA XREF: ob_c_debug_setup+18o
D:80046054     resource_table: fileentry <0, aBgBg_NULLall_p_seg_0, 0>
D:80046054                                              # DATA XREF: load_bg_bytes_at_offset_to_membank+38o
D:80046054                                              # load_rom_resource_index_to_membank+80o
D:80046054                                              # load_rom_resource_index_to_membank+150o
D:80046054                                              # load_resource_index_to_buffer+70o
D:80046054                                              # load_resource_index_to_buffer+CCo
D:80046054                                              # get_index_num_of_named_resource+B4o
D:80046060     file_entry_offset:fileentry <1, aBgBg_sev_all_p_seg_0, 0x438660>
D:80046060                                              # DATA XREF: ob_c_debug_setup+24o
D:80046060                                              # get_index_num_of_named_resource+34o
D:80046060                                              # get_index_num_of_named_resource+3Cr
D:80046060                                              # "bg/bg_sev_all_p.seg"
D:8004606C                     fileentry <2, aBgBg_silo_all_p_seg_0, 0x449450>  # "bg/bg_silo_all_p.seg"
D:80046078                     fileentry <3, aBgBg_stat_all_p_seg_0, 0x49A390>  # "bg/bg_stat_all_p.seg"
D:80046084                     fileentry <4, aBgBg_arec_all_p_seg_0, 0x4BC460>  # "bg/bg_arec_all_p.seg"
D:80046090                     fileentry <5, aBgBg_arch_all_p_seg_0, 0x4EA7E0>  # "bg/bg_arch_all_p.seg"
D:8004609C                     fileentry <6, aBgBg_tra_all_p_seg_0, 0x5102D0>  # "bg/bg_tra_all_p.seg"
D:800460A8                     fileentry <7, aBgBg_dest_all_p_seg_0, 0x530840>  # "bg/bg_dest_all_p.seg"
D:800460B4                     fileentry <8, aBgBg_sevb_all_p_seg_0, 0x55E200>  # "bg/bg_sevb_all_p.seg"
D:800460C0                     fileentry <9, aBgBg_azt_all_p_seg_0, 0x578FA0>  # "bg/bg_azt_all_p.seg"
D:800460CC                     fileentry <0xA, aBgBg_pete_all_p_seg_0, 0x59A9F0>  # "bg/bg_pete_all_p.seg"
D:800460D8                     fileentry <0xB, aBgBg_depo_all_p_seg_0, 0x5B4620>  # "bg/bg_depo_all_p.seg"
D:800460E4                     fileentry <0xC, aBgBg_ref_all_p_seg_0, 0x5E0F90>  # "bg/bg_ref_all_p.seg"
D:800460F0                     fileentry <0xD, aBgBg_cryp_all_p_seg_0, 0x5EA5A0>  # "bg/bg_cryp_all_p.seg"
D:800460FC                     fileentry <0xE, aBgBg_dam_all_p_seg_0, 0x5FFC50>  # "bg/bg_dam_all_p.seg"
D:80046108                     fileentry <0xF, aBgBg_ark_all_p_seg_0, 0x62FDF0>  # "bg/bg_ark_all_p.seg"
D:80046114                     fileentry <0x10, aBgBg_run_all_p_seg_0, 0x660D70>  # "bg/bg_run_all_p.seg"
D:80046120                     fileentry <0x11, aBgBg_sevx_all_p_seg_1, 0x66B140>  # "bg/bg_sevx_all_p.seg"
D:8004612C                     fileentry <0x12, aBgBg_jun_all_p_seg_0, 0x687710>  # "bg/bg_jun_all_p.seg"
D:80046138                     fileentry <0x13, aBgBg_dish_all_p_seg_0, 0x69C860>  # "bg/bg_dish_all_p.seg"
D:80046144                     fileentry <0x14, aBgBg_cave_all_p_seg_0, 0x6A10D0>  # "bg/bg_cave_all_p.seg"
D:80046150                     fileentry <0x15, aBgBg_cat_all_p_seg_0, 0x6C55C0>  # "bg/bg_cat_all_p.seg"
D:8004615C                     fileentry <0x16, aBgBg_crad_all_p_seg_0, 0x6CAAF0>  # "bg/bg_crad_all_p.seg"
D:80046168                     fileentry <0x17, aBgBg_sho_all_p_seg_0, 0x6DAE40>  # "bg/bg_sho_all_p.seg"
D:80046174                     fileentry <0x18, aBgBg_eld_all_p_seg_0, 0x6DAE40>  # "bg/bg_eld_all_p.seg"
D:80046180                     fileentry <0x19, aBgBg_imp_all_p_seg, 0x6DAE40>  # "bg/bg_imp_all_p.seg"
D:8004618C                     fileentry <0x1A, aBgBg_ash_all_p_seg, 0x6DAE40>  # "bg/bg_ash_all_p.seg"
D:80046198                     fileentry <0x1B, aBgBg_lue_all_p_seg_0, 0x6DAE40>  # "bg/bg_lue_all_p.seg"
D:800461A4                     fileentry <0x1C, aBgBg_ame_all_p_seg_2, 0x6DAE40>  # "bg/bg_ame_all_p.seg"
D:800461B0                     fileentry <0x1D, aBgBg_rit_all_p_seg_0, 0x6E4DA0>  # "bg/bg_rit_all_p.seg"
D:800461BC                     fileentry <0x1E, aBgBg_oat_all_p_seg_0, 0x6E4DA0>  # "bg/bg_oat_all_p.seg"
D:800461C8                     fileentry <0x1F, aBgBg_ear_all_p_seg_0, 0x6EBBF0>  # "bg/bg_ear_all_p.seg"
D:800461D4                     fileentry <0x20, aBgBg_lee_all_p_seg_0, 0x6EBBF0>  # "bg/bg_lee_all_p.seg"
D:800461E0                     fileentry <0x21, aBgBg_lip_all_p_seg_0, 0x6EBBF0>  # "bg/bg_lip_all_p.seg"
D:800461EC                     fileentry <0x22, aBgBg_len_all_p_seg_0, 0x6EBBF0>  # "bg/bg_len_all_p.seg"
D:800461F8                     fileentry <0x23, aBgBg_wax_all_p_seg_0, 0x6ECB90>  # "bg/bg_wax_all_p.seg"
D:80046204                     fileentry <0x24, aBgBg_pam_all_p_seg_0, 0x6ECB90>  # "bg/bg_pam_all_p.seg"
D:80046210                     fileentry <0x25, aCarmourguardz_0, 0x6ECB90>  # "CarmourguardZ"
D:8004621C                     fileentry <0x26, aCbaronsamediz_0, 0x6EF010>  # "CbaronsamediZ"
D:80046228                     fileentry <0x27, aCbluecamguardz_0, 0x6F2700>  # "CbluecamguardZ"
D:80046234                     fileentry <0x28, aCbluemanz_0, 0x6F4DF0>  # "CbluemanZ"
D:80046240                     fileentry <0x29, aCbluewomanz_0, 0x6F6C00>  # "CbluewomanZ"
D:8004624C                     fileentry <0x2A, aCboilerbondz_0, 0x6F8AC0>  # "CboilerbondZ"
D:80046258                     fileentry <0x2B, aCboilertrevz_0, 0x6FB6D0>  # "CboilertrevZ"
D:80046264                     fileentry <0x2C, aCborisz_0, 0x6FED50>  # "CborisZ"
D:80046270                     fileentry <0x2D, aCcamguardz_0, 0x701E70>  # "CcamguardZ"
D:8004627C                     fileentry <0x2E, aCcardimanz_0, 0x704550>  # "CcardimanZ"
D:80046288                     fileentry <0x2F, aCcheckmanz_0, 0x706350>  # "CcheckmanZ"
D:80046294                     fileentry <0x30, aCcommguardz_0, 0x7081D0>  # "CcommguardZ"
D:800462A0                     fileentry <0x31, aCdjbondz_0, 0x70A7D0>  # "CdjbondZ"
D:800462AC                     fileentry <0x32, aCfattechwomanz_1, 0x70D660>  # "CfattechwomanZ"
D:800462B8                     fileentry <0x33, aCgreatguard2z_0, 0x70F580>  # "Cgreatguard2Z"
D:800462C4                     fileentry <0x34, aCgreatguardz_0, 0x711CA0>  # "CgreatguardZ"
D:800462D0                     fileentry <0x35, aCgreyguardz_0, 0x714320>  # "CgreyguardZ"
D:800462DC                     fileentry <0x36, aCgreymanz_0, 0x7169F0>  # "CgreymanZ"
D:800462E8                     fileentry <0x37, aCheadalanz_0, 0x7187B0>  # "CheadalanZ"
D:800462F4                     fileentry <0x38, aCheadbz_0, 0x718D80>  # "CheadbZ"
D:80046300                     fileentry <0x39, aCheadbalaclavaz_0, 0x7192F0>  # "CheadbalaclavaZ"
D:8004630C                     fileentry <0x3A, aCheadbikez_0, 0x7196C0>  # "CheadbikeZ"
D:80046318                     fileentry <0x3B, aCheadbrosnanz_0, 0x719D60>  # "CheadbrosnanZ"
D:80046324                     fileentry <0x3C, aCheadbrosnanboilerz_0, 0x71AAB0>  # "CheadbrosnanboilerZ"
D:80046330                     fileentry <0x3D, aCheadbrosnansnowz_0, 0x71B650>  # "CheadbrosnansnowZ"
D:8004633C                     fileentry <0x3E, aCheadbrosnansuitz_0, 0x71C4D0>  # "CheadbrosnansuitZ"
D:80046348                     fileentry <0x3F, aCheadbrosnantimberz_0, 0x71D250>  # "CheadbrosnantimberZ"
D:80046354                     fileentry <0x40, aCheadchrisz_0, 0x71DE10>  # "CheadchrisZ"
D:80046360                     fileentry <0x41, aCheaddavez_0, 0x71E350>  # "CheaddaveZ"
D:8004636C                     fileentry <0x42, aCheaddesz_0, 0x71E8D0>  # "CheaddesZ"
D:80046378                     fileentry <0x43, aCheadduncanz_0, 0x71EE00>  # "CheadduncanZ"
D:80046384                     fileentry <0x44, aCheaddwaynez_0, 0x71F320>  # "CheaddwayneZ"
D:80046390                     fileentry <0x45, aCheadgrahamz_0, 0x71F8A0>  # "CheadgrahamZ"
D:8004639C                     fileentry <0x46, aCheadgrantz_0, 0x71FE10>  # "CheadgrantZ"
D:800463A8                     fileentry <0x47, aCheadjimz_0, 0x720340>  # "CheadjimZ"
D:800463B4                     fileentry <0x48, aCheadjoe2z_0, 0x720870>  # "Cheadjoe2Z"
D:800463C0                     fileentry <0x49, aCheadjoez_0, 0x720C90>  # "CheadjoeZ"
D:800463CC                     fileentry <0x4A, aCheadjoelz_0, 0x721200>  # "CheadjoelZ"
D:800463D8                     fileentry <0x4B, aCheadkarlz_0, 0x721710>  # "CheadkarlZ"
D:800463E4                     fileentry <0x4C, aCheadkenz_0, 0x721C70>  # "CheadkenZ"
D:800463F0                     fileentry <0x4D, aCheadleez_0, 0x7221C0>  # "CheadleeZ"
D:800463FC                     fileentry <0x4E, aCheadmandyz_0, 0x722740>  # "CheadmandyZ"
D:80046408                     fileentry <0x4F, aCheadmarionz_0, 0x722B30>  # "CheadmarionZ"
D:80046414                     fileentry <0x50, aCheadmarkz_0, 0x722F40>  # "CheadmarkZ"
D:80046420                     fileentry <0x51, aCheadmartinz_0, 0x723470>  # "CheadmartinZ"
D:8004642C                     fileentry <0x52, aCheadmishkinz_0, 0x7239D0>  # "CheadmishkinZ"
D:80046438                     fileentry <0x53, aCheadneilz_0, 0x723F30>  # "CheadneilZ"
D:80046444                     fileentry <0x54, aCheadpetez_0, 0x724450>  # "CheadpeteZ"
D:80046450                     fileentry <0x55, aCheadrobinz_0, 0x7249E0>  # "CheadrobinZ"
D:8004645C                     fileentry <0x56, aCheadsallyz_0, 0x724EF0>  # "CheadsallyZ"
D:80046468                     fileentry <0x57, aCheadscottz_0, 0x7252F0>  # "CheadscottZ"
D:80046474                     fileentry <0x58, aCheadshaunz_0, 0x725870>  # "CheadshaunZ"
D:80046480                     fileentry <0x59, aCheadsteveez_0, 0x725E50>  # "CheadsteveeZ"
D:8004648C                     fileentry <0x5A, aCheadstevehz_0, 0x7263A0>  # "CheadstevehZ"
D:80046498                     fileentry <0x5B, aCheadvivienz_0, 0x7268F0>  # "CheadvivienZ"
D:800464A4                     fileentry <0x5C, aCjawsz_0, 0x726D80>  # "CjawsZ"
D:800464B0                     fileentry <0x5D, aCjeanwomanz_0, 0x7299C0>  # "CjeanwomanZ"
D:800464BC                     fileentry <0x5E, aCmaydayz_0, 0x72B9D0>  # "CmaydayZ"
D:800464C8                     fileentry <0x5F, aCmoonfemalez_0, 0x72E570>  # "CmoonfemaleZ"
D:800464D4                     fileentry <0x60, aCmoonguardz_0, 0x7306C0>  # "CmoonguardZ"
D:800464E0                     fileentry <0x61, aCnatalyaz_0, 0x732CB0>  # "CnatalyaZ"
D:800464EC                     fileentry <0x62, aCnavyguardz_0, 0x736570>  # "CnavyguardZ"
D:800464F8                     fileentry <0x63, aCoddjobz_0, 0x738C50>  # "CoddjobZ"
D:80046504                     fileentry <0x64, aColiveguardz_0, 0x73BD80>  # "ColiveguardZ"
D:80046510                     fileentry <0x65, aCorumovz_0, 0x73E3D0>  # "CorumovZ"
D:8004651C                     fileentry <0x66, aCpilotz_0, 0x741800>  # "CpilotZ"
D:80046528                     fileentry <0x67, aCredmanz_0, 0x744880>  # "CredmanZ"
D:80046534                     fileentry <0x68, aCrusguardz_0, 0x746FB0>  # "CrusguardZ"
D:80046540                     fileentry <0x69, aCsnowbondz_0, 0x748BE0>  # "CsnowbondZ"
D:8004654C                     fileentry <0x6A, aCsnowguardz_0, 0x74BF10>  # "CsnowguardZ"
D:80046558                     fileentry <0x6B, aCspicebondz_0, 0x74EB90>  # "CspicebondZ"
D:80046564                     fileentry <0x6C, aCsuit_lf_handz_1, 0x7524B0>  # "Csuit_lf_handZ"
D:80046570                     fileentry <0x6D, aCsuitbondz_0, 0x7556D0>  # "CsuitbondZ"
D:8004657C                     fileentry <0x6E, aCtechmanz_0, 0x758460>  # "CtechmanZ"
D:80046588                     fileentry <0x6F, aCtechwomanz_0, 0x75AB10>  # "CtechwomanZ"
D:80046594                     fileentry <0x70, aCtimberbondz_0, 0x75CB00>  # "CtimberbondZ"
D:800465A0                     fileentry <0x71, aCtrevelyanz_0, 0x75F830>  # "CtrevelyanZ"
D:800465AC                     fileentry <0x72, aCtrevguardz_0, 0x763000>  # "CtrevguardZ"
D:800465B8                     fileentry <0x73, aCvalentinz_0, 0x765610>  # "CvalentinZ"
D:800465C4                     fileentry <0x74, aCxeniaz_0, 0x768580>  # "CxeniaZ"
D:800465D0                     fileentry <0x75, aGak47z_0, 0x76BF70>  # "Gak47Z"
D:800465DC                     fileentry <0x76, aGaudiotapez_0, 0x76C980>  # "GaudiotapeZ"
D:800465E8                     fileentry <0x77, aGautoshotz_0, 0x76CD10>  # "GautoshotZ"
D:800465F4                     fileentry <0x78, aGblackboxz_0, 0x76E520>  # "GblackboxZ"
D:80046600                     fileentry <0x79, aGblueprintsz_0, 0x76EB20>  # "GblueprintsZ"
D:8004660C                     fileentry <0x7A, aGbombcasez_0, 0x76EC20>  # "GbombcaseZ"
D:80046618                     fileentry <0x7B, aGbombdefuserz_0, 0x76F3B0>  # "GbombdefuserZ"
D:80046624                     fileentry <0x7C, aGbriefcasez_0, 0x76F9A0>  # "GbriefcaseZ"
D:80046630                     fileentry <0x7D, aGbugz_0, 0x770130>  # "GbugZ"
D:8004663C                     fileentry <0x7E, aGbugdetectorz_0, 0x770AA0>  # "GbugdetectorZ"
D:80046648                     fileentry <0x7F, aGbungeez_0, 0x770DF0>  # "GbungeeZ"
D:80046654                     fileentry <0x80, aGcameraz_0, 0x771140>  # "GcameraZ"
D:80046660                     fileentry <0x81, aGcartbluez_0, 0x7715C0>  # "GcartblueZ"
D:8004666C                     fileentry <0x82, aGcartridgez_0, 0x771820>  # "GcartridgeZ"
D:80046678                     fileentry <0x83, aGcartriflez_0, 0x771950>  # "GcartrifleZ"
D:80046684                     fileentry <0x84, aGcartshellz_0, 0x771B60>  # "GcartshellZ"
D:80046690                     fileentry <0x85, aGcircuitboardz_0, 0x771D60>  # "GcircuitboardZ"
D:8004669C                     fileentry <0x86, aGclipboardz_0, 0x771EA0>  # "GclipboardZ"
D:800466A8                     fileentry <0x87, aGcreditcardz_0, 0x772090>  # "GcreditcardZ"
D:800466B4                     fileentry <0x88, aGdarkglassesz_0, 0x7723E0>  # "GdarkglassesZ"
D:800466C0                     fileentry <0x89, aGdatathiefz_0, 0x772730>  # "GdatathiefZ"
D:800466CC                     fileentry <0x8A, aGdattapez_0, 0x772870>  # "GdattapeZ"
D:800466D8                     fileentry <0x8B, aGdoordecoderz_0, 0x7729E0>  # "GdoordecoderZ"
D:800466E4                     fileentry <0x8C, aGdoorexploderz_0, 0x772F60>  # "GdoorexploderZ"
D:800466F0                     fileentry <0x8D, aGdossierredz_0, 0x7732B0>  # "GdossierredZ"
D:800466FC                     fileentry <0x8E, aGdynamitez, 0x773610>  # "GdynamiteZ"
D:80046708                     fileentry <0x8F, aGexplosivefloppyz_0, 0x773960>  # "GexplosivefloppyZ"
D:80046714                     fileentry <0x90, aGexplosivepenz, 0x773BB0>  # "GexplosivepenZ"
D:80046720                     fileentry <0x91, aGextinguisherz, 0x773F00>  # "GextinguisherZ"
D:8004672C                     fileentry <0x92, aGfingergunz, 0x7746F0>  # "GfingergunZ"
D:80046738                     fileentry <0x93, aGfistz_0, 0x774A40>  # "GfistZ"
D:80046744                     fileentry <0x94, aGflarepistolz_0, 0x776140>  # "GflarepistolZ"
D:80046750                     fileentry <0x95, aGfnp90z_0, 0x776490>  # "Gfnp90Z"
D:8004675C                     fileentry <0x96, aGgaskeyringz_0, 0x777130>  # "GgaskeyringZ"
D:80046768                     fileentry <0x97, aGgoldbarz_0, 0x777B60>  # "GgoldbarZ"
D:80046774                     fileentry <0x98, aGgoldeneyekeyz_0, 0x777EB0>  # "GgoldeneyekeyZ"
D:80046780                     fileentry <0x99, aGgoldengunz_0, 0x778860>  # "GgoldengunZ"
D:8004678C                     fileentry <0x9A, aGgoldwppkz_0, 0x77A040>  # "GgoldwppkZ"
D:80046798                     fileentry <0x9B, aGgrenadez_0, 0x77B9A0>  # "GgrenadeZ"
D:800467A4                     fileentry <0x9C, aGgrenadelaunchz_0, 0x77C3D0>  # "GgrenadelaunchZ"
D:800467B0                     fileentry <0x9D, aGheroinz_0, 0x77D450>  # "GheroinZ"
D:800467BC                     fileentry <0x9E, aGjoypadz_0, 0x77D7A0>  # "GjoypadZ"
D:800467C8                     fileentry <0x9F, aGkeyanalysercasez_0, 0x77F650>  # "GkeyanalysercaseZ"
D:800467D4                     fileentry <0xA0, aGkeyboltz_0, 0x77FDE0>  # "GkeyboltZ"
D:800467E0                     fileentry <0xA1, aGkeycardz_0, 0x7807D0>  # "GkeycardZ"
D:800467EC                     fileentry <0xA2, aGkeyyalez_0, 0x780900>  # "GkeyyaleZ"
D:800467F8                     fileentry <0xA3, aGknifez_0, 0x781650>  # "GknifeZ"
D:80046804                     fileentry <0xA4, aGlaserz_0, 0x783120>  # "GlaserZ"
D:80046810                     fileentry <0xA5, aGlectrez_0, 0x783F10>  # "GlectreZ"
D:8004681C                     fileentry <0xA6, aGlockexploderz_0, 0x784260>  # "GlockexploderZ"
D:80046828                     fileentry <0xA7, aGm16z_0, 0x7845B0>  # "Gm16Z"
D:80046834                     fileentry <0xA8, aGmapz_0, 0x784FD0>  # "GmapZ"
D:80046840                     fileentry <0xA9, aGmicrocameraz_0, 0x7850C0>  # "GmicrocameraZ"
D:8004684C                     fileentry <0xAA, aGmicrocodez_0, 0x785700>  # "GmicrocodeZ"
D:80046858                     fileentry <0xAB, aGmicrofilmz_0, 0x785A50>  # "GmicrofilmZ"
D:80046864                     fileentry <0xAC, aGmoneyz_0, 0x785DA0>  # "GmoneyZ"
D:80046870                     fileentry <0xAD, aGmp5kz_0, 0x7860F0>  # "Gmp5kZ"
D:8004687C                     fileentry <0xAE, aGmp5ksilz_0, 0x786CD0>  # "Gmp5ksilZ"
D:80046888                     fileentry <0xAF, aGpitongunz_0, 0x7879D0>  # "GpitongunZ"
D:80046894                     fileentry <0xB0, aGplansz_0, 0x787D20>  # "GplansZ"
D:800468A0                     fileentry <0xB1, aGplastiquez_0, 0x787EF0>  # "GplastiqueZ"
D:800468AC                     fileentry <0xB2, aGpolarizedglassesz_0, 0x788240>  # "GpolarizedglassesZ"
D:800468B8                     fileentry <0xB3, aGproximityminez_0, 0x7887A0>  # "GproximitymineZ"
D:800468C4                     fileentry <0xB4, aGremoteminez_0, 0x788F90>  # "GremotemineZ"
D:800468D0                     fileentry <0xB5, aGrocketlaunchz_0, 0x789950>  # "GrocketlaunchZ"
D:800468DC                     fileentry <0xB6, aGrugerz_0, 0x78AB70>  # "GrugerZ"
D:800468E8                     fileentry <0xB7, aGsafecrackercasez_0, 0x78C900>  # "GsafecrackercaseZ"
D:800468F4                     fileentry <0xB8, aGshotgunz_0, 0x78D090>  # "GshotgunZ"
D:80046900                     fileentry <0xB9, aGsilverwppkz_0, 0x78DF70>  # "GsilverwppkZ"
D:8004690C                     fileentry <0xBA, aGskorpionz_0, 0x78F8D0>  # "GskorpionZ"
D:80046918                     fileentry <0xBB, aGsniperriflez_0, 0x790AD0>  # "GsniperrifleZ"
D:80046924                     fileentry <0xBC, aGspectrez_0, 0x791B40>  # "GspectreZ"
D:80046930                     fileentry <0xBD, aGspooltapez_0, 0x7927C0>  # "GspooltapeZ"
D:8004693C                     fileentry <0xBE, aGspyfilez_0, 0x792B10>  # "GspyfileZ"
D:80046948                     fileentry <0xBF, aGstafflistz_0, 0x792E60>  # "GstafflistZ"
D:80046954                     fileentry <0xC0, aGtaserz_0, 0x793000>  # "GtaserZ"
D:80046960                     fileentry <0xC1, aGthrowknifez_0, 0x794E60>  # "GthrowknifeZ"
D:8004696C                     fileentry <0xC2, aGtimedminez_0, 0x796950>  # "GtimedmineZ"
D:80046978                     fileentry <0xC3, aGtriggerz_0, 0x797410>  # "GtriggerZ"
D:80046984                     fileentry <0xC4, aGtt33z_0, 0x79A810>  # "Gtt33Z"
D:80046990                     fileentry <0xC5, aGuziz_0, 0x79C330>  # "GuziZ"
D:8004699C                     fileentry <0xC6, aGvideotapez_0, 0x79CC40>  # "GvideotapeZ"
D:800469A8                     fileentry <0xC7, aGwatchcommunicatorz_0, 0x79CE50>  # "GwatchcommunicatorZ"
D:800469B4                     fileentry <0xC8, aGwatchgeigercounterz_0, 0x79E2B0>  # "GwatchgeigercounterZ"
D:800469C0                     fileentry <0xC9, aGwatchidentifierz_0, 0x79F710>  # "GwatchidentifierZ"
D:800469CC                     fileentry <0xCA, aGwatchlaserz_0, 0x7A0B70>  # "GwatchlaserZ"
D:800469D8                     fileentry <0xCB, aGwatchmagnetattractz_0, 0x7A3F70>  # "GwatchmagnetattractZ"
D:800469E4                     fileentry <0xCC, aGwatchmagnetrepelz_0, 0x7A53C0>  # "GwatchmagnetrepelZ"
D:800469F0                     fileentry <0xCD, aGweaponcasez_0, 0x7A6820>  # "GweaponcaseZ"
D:800469FC                     fileentry <0xCE, aGwppkz_0, 0x7A6FB0>  # "GwppkZ"
D:80046A08                     fileentry <0xCF, aGwppksilz_0, 0x7A8C40>  # "GwppksilZ"
D:80046A14                     fileentry <0xD0, aGwristdartz, 0x7AA980>  # "GwristdartZ"
D:80046A20                     fileentry <0xD1, aPicbmz_0, 0x7AACD0>  # "PICBMZ"
D:80046A2C                     fileentry <0xD2, aPicbm_nosez_0, 0x7AD250>  # "PICBM_noseZ"
D:80046A38                     fileentry <0xD3, aPak47magz_0, 0x7ADA00>  # "Pak47magZ"
D:80046A44                     fileentry <0xD4, aPalarm1z_0, 0x7ADBE0>  # "Palarm1Z"
D:80046A50                     fileentry <0xD5, aPalarm2z_0, 0x7ADD40>  # "Palarm2Z"
D:80046A5C                     fileentry <0xD6, aPammo_crate1z_0, 0x7ADEE0>  # "Pammo_crate1Z"
D:80046A68                     fileentry <0xD7, aPammo_crate2z_0, 0x7AE120>  # "Pammo_crate2Z"
D:80046A74                     fileentry <0xD8, aPammo_crate3z_0, 0x7AE360>  # "Pammo_crate3Z"
D:80046A80                     fileentry <0xD9, aPammo_crate4z_0, 0x7AE5B0>  # "Pammo_crate4Z"
D:80046A8C                     fileentry <0xDA, aPammo_crate5z_0, 0x7AE820>  # "Pammo_crate5Z"
D:80046A98                     fileentry <0xDB, aPapcz_0, 0x7AEAE0>  # "PapcZ"
D:80046AA4                     fileentry <0xDC, aParchsecdoor1z_0, 0x7B0740>  # "Parchsecdoor1Z"
D:80046AB0                     fileentry <0xDD, aParchsecdoor2z_0, 0x7B0920>  # "Parchsecdoor2Z"
D:80046ABC                     fileentry <0xDE, aParticz_0, 0x7B0AF0>  # "ParticZ"
D:80046AC8                     fileentry <0xDF, aPartictrailerz_0, 0x7B18F0>  # "PartictrailerZ"
D:80046AD4                     fileentry <0xE0, aPbarricadez_0, 0x7B2200>  # "PbarricadeZ"
D:80046AE0                     fileentry <0xE1, aPbin1z_0, 0x7B2440>  # "Pbin1Z"
D:80046AEC                     fileentry <0xE2, aPblotter1z_0, 0x7B2790>  # "Pblotter1Z"
D:80046AF8                     fileentry <0xE3, aPbodyarmourz_0, 0x7B2870>  # "PbodyarmourZ"
D:80046B04                     fileentry <0xE4, aPbodyarmourvestz_0, 0x7B2D10>  # "PbodyarmourvestZ"
D:80046B10                     fileentry <0xE5, aPbollardz_0, 0x7B3130>  # "PbollardZ"
D:80046B1C                     fileentry <0xE6, aPbombz_0, 0x7B3330>  # "PbombZ"
D:80046B28                     fileentry <0xE7, aPbook1z_0, 0x7B34A0>  # "Pbook1Z"
D:80046B34                     fileentry <0xE8, aPbookshelf1z_0, 0x7B3630>  # "Pbookshelf1Z"
D:80046B40                     fileentry <0xE9, aPborg_cratez_0, 0x7B3D20>  # "Pborg_crateZ"
D:80046B4C                     fileentry <0xEA, aPboxcartridgesz_0, 0x7B3E90>  # "PboxcartridgesZ"
D:80046B58                     fileentry <0xEB, aPboxes2x4z_0, 0x7B4090>  # "Pboxes2x4Z"
D:80046B64                     fileentry <0xEC, aPboxes3x4z_0, 0x7B44C0>  # "Pboxes3x4Z"
D:80046B70                     fileentry <0xED, aPboxes4x4z_0, 0x7B4900>  # "Pboxes4x4Z"
D:80046B7C                     fileentry <0xEE, aPbrakeunitz_0, 0x7B4F60>  # "PbrakeunitZ"
D:80046B88                     fileentry <0xEF, aPbridge_console1az_0, 0x7B52D0>  # "Pbridge_console1aZ"
D:80046B94                     fileentry <0xF0, aPbridge_console1bz_0, 0x7B5850>  # "Pbridge_console1bZ"
D:80046BA0                     fileentry <0xF1, aPbridge_console2az_0, 0x7B5DB0>  # "Pbridge_console2aZ"
D:80046BAC                     fileentry <0xF2, aPbridge_console2bz_0, 0x7B6330>  # "Pbridge_console2bZ"
D:80046BB8                     fileentry <0xF3, aPbridge_console3az_0, 0x7B6820>  # "Pbridge_console3aZ"
D:80046BC4                     fileentry <0xF4, aPbridge_console3bz_0, 0x7B6D70>  # "Pbridge_console3bZ"
D:80046BD0                     fileentry <0xF5, aPcarbmwz_0, 0x7B7300>  # "PcarbmwZ"
D:80046BDC                     fileentry <0xF6, aPcard_box1z_0, 0x7B7FE0>  # "Pcard_box1Z"
D:80046BE8                     fileentry <0xF7, aPcard_box2z_0, 0x7B81E0>  # "Pcard_box2Z"
D:80046BF4                     fileentry <0xF8, aPcard_box3z_0, 0x7B8420>  # "Pcard_box3Z"
D:80046C00                     fileentry <0xF9, aPcard_box4_lgz_0, 0x7B8610>  # "Pcard_box4_lgZ"
D:80046C0C                     fileentry <0xFA, aPcard_box5_lgz_0, 0x7B87C0>  # "Pcard_box5_lgZ"
D:80046C18                     fileentry <0xFB, aPcard_box6_lgz_0, 0x7B89C0>  # "Pcard_box6_lgZ"
D:80046C24                     fileentry <0xFC, aPcarescortz_0, 0x7B8BB0>  # "PcarescortZ"
D:80046C30                     fileentry <0xFD, aPcargolfz_0, 0x7B97B0>  # "PcargolfZ"
D:80046C3C                     fileentry <0xFE, aPcarweirdz_0, 0x7BA3E0>  # "PcarweirdZ"
D:80046C48                     fileentry <0xFF, aPcarzilz_0, 0x7BB520>  # "PcarzilZ"
D:80046C54                     fileentry <0x100, aPcctvz_0, 0x7BCB20>  # "PcctvZ"
D:80046C60                     fileentry <0x101, aPchraudiotapez_0, 0x7BCEA0>  # "PchraudiotapeZ"
D:80046C6C                     fileentry <0x102, aPchrautoshotz_0, 0x7BD400>  # "PchrautoshotZ"
D:80046C78                     fileentry <0x103, aPchrblackboxz_0, 0x7BD760>  # "PchrblackboxZ"
D:80046C84                     fileentry <0x104, aPchrblueprintsz_0, 0x7BDFE0>  # "PchrblueprintsZ"
D:80046C90                     fileentry <0x105, aPchrbombcasez_0, 0x7BE130>  # "PchrbombcaseZ"
D:80046C9C                     fileentry <0x106, aPchrbombdefuserz_0, 0x7BE320>  # "PchrbombdefuserZ"
D:80046CA8                     fileentry <0x107, aPchrbriefcasez_0, 0x7BEC00>  # "PchrbriefcaseZ"
D:80046CB4                     fileentry <0x108, aPchrbugz_0, 0x7BED90>  # "PchrbugZ"
D:80046CC0                     fileentry <0x109, aPchrbugdetectorz_0, 0x7BFB40>  # "PchrbugdetectorZ"
D:80046CCC                     fileentry <0x10A, aPchrbungeez_0, 0x7BFCB0>  # "PchrbungeeZ"
D:80046CD8                     fileentry <0x10B, aPchrcameraz_0, 0x7BFE20>  # "PchrcameraZ"
D:80046CE4                     fileentry <0x10C, aPchrcircuitboardz_0, 0x7C04B0>  # "PchrcircuitboardZ"
D:80046CF0                     fileentry <0x10D, aPchrclipboardz_0, 0x7C0650>  # "PchrclipboardZ"
D:80046CFC                     fileentry <0x10E, aPchrcreditcardz_0, 0x7C08D0>  # "PchrcreditcardZ"
D:80046D08                     fileentry <0x10F, aPchrdarkglassesz_0, 0x7C0A40>  # "PchrdarkglassesZ"
D:80046D14                     fileentry <0x110, aPchrdatathiefz_0, 0x7C0BB0>  # "PchrdatathiefZ"
D:80046D20                     fileentry <0x111, aPchrdattapez_0, 0x7C0D50>  # "PchrdattapeZ"
D:80046D2C                     fileentry <0x112, aPchrdoordecoderz_0, 0x7C0F40>  # "PchrdoordecoderZ"
D:80046D38                     fileentry <0x113, aPchrdoorexploderz_0, 0x7C17A0>  # "PchrdoorexploderZ"
D:80046D44                     fileentry <0x114, aPchrdossierredz_0, 0x7C1910>  # "PchrdossierredZ"
D:80046D50                     fileentry <0x115, aPchrdynamitez_0, 0x7C1DE0>  # "PchrdynamiteZ"
D:80046D5C                     fileentry <0x116, aPchrexplosivepenz_0, 0x7C1F50>  # "PchrexplosivepenZ"
D:80046D68                     fileentry <0x117, aPchrextinguisherz_0, 0x7C20C0>  # "PchrextinguisherZ"
D:80046D74                     fileentry <0x118, aPchrfingergunz_0, 0x7C25C0>  # "PchrfingergunZ"
D:80046D80                     fileentry <0x119, aPchrflarepistolz_0, 0x7C2730>  # "PchrflarepistolZ"
D:80046D8C                     fileentry <0x11A, aPchrfnp90z_0, 0x7C28A0>  # "Pchrfnp90Z"
D:80046D98                     fileentry <0x11B, aPchrgaskeyringz_0, 0x7C2D00>  # "PchrgaskeyringZ"
D:80046DA4                     fileentry <0x11C, aPchrgoldbarz_0, 0x7C3C10>  # "PchrgoldbarZ"
D:80046DB0                     fileentry <0x11D, aPchrgoldenz_0, 0x7C3D80>  # "PchrgoldenZ"
D:80046DBC                     fileentry <0x11E, aPchrgoldeneyekeyz_0, 0x7C3FF0>  # "PchrgoldeneyekeyZ"
D:80046DC8                     fileentry <0x11F, aPchrgoldwppkz_0, 0x7C4E90>  # "PchrgoldwppkZ"
D:80046DD4                     fileentry <0x120, aPchrgrenadez_0, 0x7C5000>  # "PchrgrenadeZ"
D:80046DE0                     fileentry <0x121, aPchrgrenadelaunchz_0, 0x7C5370>  # "PchrgrenadelaunchZ"
D:80046DEC                     fileentry <0x122, aPchrgrenaderoundz_0, 0x7C5700>  # "PchrgrenaderoundZ"
D:80046DF8                     fileentry <0x123, aPchrheroinz_0, 0x7C5970>  # "PchrheroinZ"
D:80046E04                     fileentry <0x124, aPchrkalashz_0, 0x7C5AE0>  # "PchrkalashZ"
D:80046E10                     fileentry <0x125, aPchrkeyanalysercasez_0, 0x7C5ED0>  # "PchrkeyanalysercaseZ"
D:80046E1C                     fileentry <0x126, aPchrkeyboltz_0, 0x7C60C0>  # "PchrkeyboltZ"
D:80046E28                     fileentry <0x127, aPchrkeyyalez_0, 0x7C6F60>  # "PchrkeyyaleZ"
D:80046E34                     fileentry <0x128, aPchrknifez_0, 0x7C83C0>  # "PchrknifeZ"
D:80046E40                     fileentry <0x129, aPchrlaserz_0, 0x7C85C0>  # "PchrlaserZ"
D:80046E4C                     fileentry <0x12A, aPchrlectrez_0, 0x7C8980>  # "PchrlectreZ"
D:80046E58                     fileentry <0x12B, aPchrlockexploderz_0, 0x7C8AF0>  # "PchrlockexploderZ"
D:80046E64                     fileentry <0x12C, aPchrm16z_0, 0x7C8C60>  # "Pchrm16Z"
D:80046E70                     fileentry <0x12D, aPchrmapz_0, 0x7C9030>  # "PchrmapZ"
D:80046E7C                     fileentry <0x12E, aPchrmicrocameraz_0, 0x7C9180>  # "PchrmicrocameraZ"
D:80046E88                     fileentry <0x12F, aPchrmicrocodez_0, 0x7C9A70>  # "PchrmicrocodeZ"
D:80046E94                     fileentry <0x130, aPchrmicrofilmz_0, 0x7C9BE0>  # "PchrmicrofilmZ"
D:80046EA0                     fileentry <0x131, aPchrmoneyz_0, 0x7C9D50>  # "PchrmoneyZ"
D:80046EAC                     fileentry <0x132, aPchrmp5kz_0, 0x7C9EC0>  # "Pchrmp5kZ"
D:80046EB8                     fileentry <0x133, aPchrmp5ksilz_0, 0x7CA240>  # "Pchrmp5ksilZ"
D:80046EC4                     fileentry <0x134, aPchrpitongunz_0, 0x7CA650>  # "PchrpitongunZ"
D:80046ED0                     fileentry <0x135, aPchrplansz_0, 0x7CA7C0>  # "PchrplansZ"
D:80046EDC                     fileentry <0x136, aPchrplastiquez_0, 0x7CAA50>  # "PchrplastiqueZ"
D:80046EE8                     fileentry <0x137, aPchrpolarizedglassesz_0, 0x7CAEB0>  # "PchrpolarizedglassesZ"
D:80046EF4                     fileentry <0x138, aPchrproximityminez_0, 0x7CB770>  # "PchrproximitymineZ"
D:80046F00                     fileentry <0x139, aPchrremoteminez_0, 0x7CBBD0>  # "PchrremotemineZ"
D:80046F0C                     fileentry <0x13A, aPchrrocketz_0, 0x7CC030>  # "PchrrocketZ"
D:80046F18                     fileentry <0x13B, aPchrrocketlaunchz_0, 0x7CC5E0>  # "PchrrocketlaunchZ"
D:80046F24                     fileentry <0x13C, aPchrrugerz_0, 0x7CC9C0>  # "PchrrugerZ"
D:80046F30                     fileentry <0x13D, aPchrsafecrackercasez_0, 0x7CCDA0>  # "PchrsafecrackercaseZ"
D:80046F3C                     fileentry <0x13E, aPchrshotgunz_0, 0x7CCF90>  # "PchrshotgunZ"
D:80046F48                     fileentry <0x13F, aPchrsilverwppkz_0, 0x7CD2E0>  # "PchrsilverwppkZ"
D:80046F54                     fileentry <0x140, aPchrskorpionz_0, 0x7CD450>  # "PchrskorpionZ"
D:80046F60                     fileentry <0x141, aPchrsniperriflez_0, 0x7CD7D0>  # "PchrsniperrifleZ"
D:80046F6C                     fileentry <0x142, aPchrspectrez_0, 0x7CDB60>  # "PchrspectreZ"
D:80046F78                     fileentry <0x143, aPchrspooltapez_0, 0x7CDED0>  # "PchrspooltapeZ"
D:80046F84                     fileentry <0x144, aPchrspyfilez_0, 0x7CE040>  # "PchrspyfileZ"
D:80046F90                     fileentry <0x145, aPchrstafflistz_0, 0x7CE1B0>  # "PchrstafflistZ"
D:80046F9C                     fileentry <0x146, aPchrtesttubez_0, 0x7CE3D0>  # "PchrtesttubeZ"
D:80046FA8                     fileentry <0x147, aPchrthrowknifez_0, 0x7CE590>  # "PchrthrowknifeZ"
D:80046FB4                     fileentry <0x148, aPchrtimedminez_0, 0x7CE7B0>  # "PchrtimedmineZ"
D:80046FC0                     fileentry <0x149, aPchrtt33z_0, 0x7CECE0>  # "Pchrtt33Z"
D:80046FCC                     fileentry <0x14A, aPchruziz_0, 0x7CEF70>  # "PchruziZ"
D:80046FD8                     fileentry <0x14B, aPchrvideotapez_0, 0x7CF240>  # "PchrvideotapeZ"
D:80046FE4                     fileentry <0x14C, aPchrweaponcasez_0, 0x7CF510>  # "PchrweaponcaseZ"
D:80046FF0                     fileentry <0x14D, aPchrwppkz_0, 0x7CF710>  # "PchrwppkZ"
D:80046FFC                     fileentry <0x14E, aPchrwppksilz_0, 0x7CF950>  # "PchrwppksilZ"
D:80047008                     fileentry <0x14F, aPchrwristdartz_0, 0x7CFC30>  # "PchrwristdartZ"
D:80047014                     fileentry <0x150, aPconsole1z_0, 0x7CFDA0>  # "Pconsole1Z"
D:80047020                     fileentry <0x151, aPconsole2z_0, 0x7D0420>  # "Pconsole2Z"
D:8004702C                     fileentry <0x152, aPconsole3z_0, 0x7D0AA0>  # "Pconsole3Z"
D:80047038                     fileentry <0x153, aPconsole_sev2az_0, 0x7D1130>  # "Pconsole_sev2aZ"
D:80047044                     fileentry <0x154, aPconsole_sev2bz_0, 0x7D1550>  # "Pconsole_sev2bZ"
D:80047050                     fileentry <0x155, aPconsole_sev2cz_0, 0x7D1A10>  # "Pconsole_sev2cZ"
D:8004705C                     fileentry <0x156, aPconsole_sev2dz_0, 0x7D1E50>  # "Pconsole_sev2dZ"
D:80047068                     fileentry <0x157, aPconsole_sev_geaz_0, 0x7D2280>  # "Pconsole_sev_GEaZ"
D:80047074                     fileentry <0x158, aPconsole_sev_gebz_0, 0x7D26B0>  # "Pconsole_sev_GEbZ"
D:80047080                     fileentry <0x159, aPconsole_sevaz_0, 0x7D2AE0>  # "Pconsole_sevaZ"
D:8004708C                     fileentry <0x15A, aPconsole_sevbz_0, 0x7D2F60>  # "Pconsole_sevbZ"
D:80047098                     fileentry <0x15B, aPconsole_sevcz_0, 0x7D33D0>  # "Pconsole_sevcZ"
D:800470A4                     fileentry <0x15C, aPconsole_sevdz_0, 0x7D3800>  # "Pconsole_sevdZ"
D:800470B0                     fileentry <0x15D, aPcryptdoor1az_0, 0x7D3C30>  # "Pcryptdoor1aZ"
D:800470BC                     fileentry <0x15E, aPcryptdoor1bz_0, 0x7D3DC0>  # "Pcryptdoor1bZ"
D:800470C8                     fileentry <0x15F, aPcryptdoor2az_0, 0x7D3F50>  # "Pcryptdoor2aZ"
D:800470D4                     fileentry <0x160, aPcryptdoor2bz_0, 0x7D40E0>  # "Pcryptdoor2bZ"
D:800470E0                     fileentry <0x161, aPcryptdoor3z_0, 0x7D4270>  # "Pcryptdoor3Z"
D:800470EC                     fileentry <0x162, aPcryptdoor4z_0, 0x7D44E0>  # "Pcryptdoor4Z"
D:800470F8                     fileentry <0x163, aPdamchaindoorz_0, 0x7D4660>  # "PdamchaindoorZ"
D:80047104                     fileentry <0x164, aPdamgatedoorz_0, 0x7D48E0>  # "PdamgatedoorZ"
D:80047110                     fileentry <0x165, aPdamtundoorz_0, 0x7D4B00>  # "PdamtundoorZ"
D:8004711C                     fileentry <0x166, aPdepot_door_steelz_0, 0x7D4E70>  # "Pdepot_door_steelZ"
D:80047128                     fileentry <0x167, aPdepot_gate_entryz_0, 0x7D5010>  # "Pdepot_gate_entryZ"
D:80047134                     fileentry <0x168, aPdesk1z_0, 0x7D5250>  # "Pdesk1Z"
D:80047140                     fileentry <0x169, aPdesk2z_0, 0x7D53D0>  # "Pdesk2Z"
D:8004714C                     fileentry <0x16A, aPdesk_arecibo1z_0, 0x7D5550>  # "Pdesk_arecibo1Z"
D:80047158                     fileentry <0x16B, aPdesk_lamp2z_0, 0x7D5790>  # "Pdesk_lamp2Z"
D:80047164                     fileentry <0x16C, aPdest_enginez_0, 0x7D5A90>  # "Pdest_engineZ"
D:80047170                     fileentry <0x16D, aPdest_exocetz_0, 0x7D7380>  # "Pdest_exocetZ"
D:8004717C                     fileentry <0x16E, aPdest_gunz_0, 0x7D79E0>  # "Pdest_gunZ"
D:80047188                     fileentry <0x16F, aPdest_harpoonz_0, 0x7D8050>  # "Pdest_harpoonZ"
D:80047194                     fileentry <0x170, aPdest_seawolfz_0, 0x7D88F0>  # "Pdest_seawolfZ"
D:800471A0                     fileentry <0x171, aPdisc_readerz_0, 0x7D98A0>  # "Pdisc_readerZ"
D:800471AC                     fileentry <0x172, aPdisk_drive1z_0, 0x7D9A60>  # "Pdisk_drive1Z"
D:800471B8                     fileentry <0x173, aPdoor_azt_chairz_0, 0x7D9BF0>  # "Pdoor_azt_chairZ"
D:800471C4                     fileentry <0x174, aPdoor_azt_deskz_0, 0x7D9D70>  # "Pdoor_azt_deskZ"
D:800471D0                     fileentry <0x175, aPdoor_azt_desk_topz_0, 0x7DA1B0>  # "Pdoor_azt_desk_topZ"
D:800471DC                     fileentry <0x176, aPdoor_aztecz_0, 0x7DA540>  # "Pdoor_aztecZ"
D:800471E8                     fileentry <0x177, aPdoor_dest1z_0, 0x7DA770>  # "Pdoor_dest1Z"
D:800471F4                     fileentry <0x178, aPdoor_dest2z_0, 0x7DAA70>  # "Pdoor_dest2Z"
D:80047200                     fileentry <0x179, aPdoor_eyelidz_0, 0x7DAE30>  # "Pdoor_eyelidZ"
D:8004720C                     fileentry <0x17A, aPdoor_irisz_0, 0x7DB390>  # "Pdoor_irisZ"
D:80047218                     fileentry <0x17B, aPdoor_mfz_0, 0x7DBDE0>  # "Pdoor_mfZ"
D:80047224                     fileentry <0x17C, aPdoor_roller1z_0, 0x7DC0D0>  # "Pdoor_roller1Z"
D:80047230                     fileentry <0x17D, aPdoor_roller2z_0, 0x7DC440>  # "Pdoor_roller2Z"
D:8004723C                     fileentry <0x17E, aPdoor_roller3z_0, 0x7DC680>  # "Pdoor_roller3Z"
D:80047248                     fileentry <0x17F, aPdoor_roller4z_0, 0x7DC8C0>  # "Pdoor_roller4Z"
D:80047254                     fileentry <0x180, aPdoor_rollertrainz_0, 0x7DCB20>  # "Pdoor_rollertrainZ"
D:80047260                     fileentry <0x181, aPdoor_st_arec1z_0, 0x7DCC50>  # "Pdoor_st_arec1Z"
D:8004726C                     fileentry <0x182, aPdoor_st_arec2z_0, 0x7DCEB0>  # "Pdoor_st_arec2Z"
D:80047278                     fileentry <0x183, aPdoor_winz_0, 0x7DD190>  # "Pdoor_winZ"
D:80047284                     fileentry <0x184, aPdoorconsolez_0, 0x7DD330>  # "PdoorconsoleZ"
D:80047290                     fileentry <0x185, aPdoorpanelz_0, 0x7DD7A0>  # "PdoorpanelZ"
D:8004729C                     fileentry <0x186, aPdoorprison1z_0, 0x7DDB10>  # "Pdoorprison1Z"
D:800472A8                     fileentry <0x187, aPdoorstatgatez_0, 0x7DDC60>  # "PdoorstatgateZ"
D:800472B4                     fileentry <0x188, aPexplosionbitz_0, 0x7DDE60>  # "PexplosionbitZ"
D:800472C0                     fileentry <0x189, aPfiling_cabinet1z_0, 0x7DDF80>  # "Pfiling_cabinet1Z"
D:800472CC                     fileentry <0x18A, aPflagz_0, 0x7DE100>  # "PflagZ"
D:800472D8                     fileentry <0x18B, aPfloppyz_0, 0x7DE230>  # "PfloppyZ"
D:800472E4                     fileentry <0x18C, aPfnp90magz_0, 0x7DE550>  # "Pfnp90magZ"
D:800472F0                     fileentry <0x18D, aPgas_plant_met1_do1z_0, 0x7DE6F0>  # "Pgas_plant_met1_do1Z"
D:800472FC                     fileentry <0x18E, aPgas_plant_sw2_do1z_0, 0x7DEA70>  # "Pgas_plant_sw2_do1Z"
D:80047308                     fileentry <0x18F, aPgas_plant_sw3_do1z_0, 0x7DEC50>  # "Pgas_plant_sw3_do1Z"
D:80047314                     fileentry <0x190, aPgas_plant_sw4_do1z_0, 0x7DEE50>  # "Pgas_plant_sw4_do1Z"
D:80047320                     fileentry <0x191, aPgas_plant_sw_do1z_0, 0x7DEFB0>  # "Pgas_plant_sw_do1Z"
D:8004732C                     fileentry <0x192, aPgas_plant_wc_cub1z_0, 0x7DF240>  # "Pgas_plant_wc_cub1Z"
D:80047338                     fileentry <0x193, aPgasbarrelz_0, 0x7DF450>  # "PgasbarrelZ"
D:80047344                     fileentry <0x194, aPgasbarrelsz_0, 0x7DF660>  # "PgasbarrelsZ"
D:80047350                     fileentry <0x195, aPgasplant_clear_doorz_0, 0x7DFBA0>  # "Pgasplant_clear_doorZ"
D:8004735C                     fileentry <0x196, aPgastankz_0, 0x7E0100>  # "PgastankZ"
D:80047368                     fileentry <0x197, aPglassware1z_0, 0x7E06B0>  # "Pglassware1Z"
D:80047374                     fileentry <0x198, aPglassware2z_0, 0x7E0810>  # "Pglassware2Z"
D:80047380                     fileentry <0x199, aPglassware3z_0, 0x7E0AA0>  # "Pglassware3Z"
D:8004738C                     fileentry <0x19A, aPglassware4z_0, 0x7E0CB0>  # "Pglassware4Z"
D:80047398                     fileentry <0x19B, aPgoldeneyelogoz_0, 0x7E1230>  # "PgoldeneyelogoZ"
D:800473A4                     fileentry <0x19C, aPgoldenshellsz_0, 0x7E20E0>  # "PgoldenshellsZ"
D:800473B0                     fileentry <0x19D, aPgroundgunz_0, 0x7E22E0>  # "PgroundgunZ"
D:800473BC                     fileentry <0x19E, aPgun_runway1z_0, 0x7E2AB0>  # "Pgun_runway1Z"
D:800473C8                     fileentry <0x19F, aPhatberetz_0, 0x7E31F0>  # "PhatberetZ"
D:800473D4                     fileentry <0x1A0, aPhatberetbluez_0, 0x7E3490>  # "PhatberetblueZ"
D:800473E0                     fileentry <0x1A1, aPhatberetredz_0, 0x7E3760>  # "PhatberetredZ"
D:800473EC                     fileentry <0x1A2, aPhatchboltz_0, 0x7E3A40>  # "PhatchboltZ"
D:800473F8                     fileentry <0x1A3, aPhatchdoorz_0, 0x7E3B10>  # "PhatchdoorZ"
D:80047404                     fileentry <0x1A4, aPhatchsevxz_0, 0x7E3D30>  # "PhatchsevxZ"
D:80047410                     fileentry <0x1A5, aPhatfurryz_0, 0x7E3EA0>  # "PhatfurryZ"
D:8004741C                     fileentry <0x1A6, aPhatfurryblackz_0, 0x7E40D0>  # "PhatfurryblackZ"
D:80047428                     fileentry <0x1A7, aPhatfurrybrownz_0, 0x7E42F0>  # "PhatfurrybrownZ"
D:80047434                     fileentry <0x1A8, aPhathelmetz_0, 0x7E4500>  # "PhathelmetZ"
D:80047440                     fileentry <0x1A9, aPhathelmetgreyz_0, 0x7E4730>  # "PhathelmetgreyZ"
D:8004744C                     fileentry <0x1AA, aPhatmoonz_0, 0x7E4960>  # "PhatmoonZ"
D:80047458                     fileentry <0x1AB, aPhatpeakedz_0, 0x7E4D40>  # "PhatpeakedZ"
D:80047464                     fileentry <0x1AC, aPhattbirdz_0, 0x7E5050>  # "PhattbirdZ"
D:80047470                     fileentry <0x1AD, aPhattbirdbrownz_0, 0x7E52A0>  # "PhattbirdbrownZ"
D:8004747C                     fileentry <0x1AE, aPhelicopterz_0, 0x7E5510>  # "PhelicopterZ"
D:80047488                     fileentry <0x1AF, aPhindz_0, 0x7E9730>  # "PhindZ"
D:80047494                     fileentry <0x1B0, aPjeepz_0, 0x7EAEA0>  # "PjeepZ"
D:800474A0                     fileentry <0x1B1, aPjerry_can1z_0, 0x7EC000>  # "Pjerry_can1Z"
D:800474AC                     fileentry <0x1B2, aPjungle3_treez_0, 0x7EC260>  # "Pjungle3_treeZ"
D:800474B8                     fileentry <0x1B3, aPjungle5_treez_0, 0x7EC9E0>  # "Pjungle5_treeZ"
D:800474C4                     fileentry <0x1B4, aPkey_holderz_0, 0x7ECF10>  # "Pkey_holderZ"
D:800474D0                     fileentry <0x1B5, aPkeyboard1z_0, 0x7ED260>  # "Pkeyboard1Z"
D:800474DC                     fileentry <0x1B6, aPkit_units1z_0, 0x7ED3D0>  # "Pkit_units1Z"
D:800474E8                     fileentry <0x1B7, aPlabbenchz_0, 0x7ED670>  # "PlabbenchZ"
D:800474F4                     fileentry <0x1B8, aPlandminez_0, 0x7EDA40>  # "PlandmineZ"
D:80047500                     fileentry <0x1B9, aPlegalpagez_0, 0x7EDCB0>  # "PlegalpageZ"
D:8004750C                     fileentry <0x1BA, aPletter_tray1z_0, 0x7EEC70>  # "Pletter_tray1Z"
D:80047518                     fileentry <0x1BB, aPlocker3z_0, 0x7EEDD0>  # "Plocker3Z"
D:80047524                     fileentry <0x1BC, aPlocker4z_0, 0x7EEF60>  # "Plocker4Z"
D:80047530                     fileentry <0x1BD, aPm16magz_0, 0x7EF0F0>  # "Pm16magZ"
D:8004753C                     fileentry <0x1BE, aPmagnumshellsz_0, 0x7EF230>  # "PmagnumshellsZ"
D:80047548                     fileentry <0x1BF, aPmainframe1z_0, 0x7EF430>  # "Pmainframe1Z"
D:80047554                     fileentry <0x1C0, aPmainframe2z_0, 0x7EF730>  # "Pmainframe2Z"
D:80047560                     fileentry <0x1C1, aPmetal_chair1z_0, 0x7EFA00>  # "Pmetal_chair1Z"
D:8004756C                     fileentry <0x1C2, aPmetal_crate1z_0, 0x7EFD40>  # "Pmetal_crate1Z"
D:80047578                     fileentry <0x1C3, aPmetal_crate2z_0, 0x7EFF00>  # "Pmetal_crate2Z"
D:80047584                     fileentry <0x1C4, aPmetal_crate3z_0, 0x7F00C0>  # "Pmetal_crate3Z"
D:80047590                     fileentry <0x1C5, aPmetal_crate4z_0, 0x7F0280>  # "Pmetal_crate4Z"
D:8004759C                     fileentry <0x1C6, aPmilcopterz_0, 0x7F0440>  # "PmilcopterZ"
D:800475A8                     fileentry <0x1C7, aPmiltruckz_0, 0x7F1D20>  # "PmiltruckZ"
D:800475B4                     fileentry <0x1C8, aPmissile_rack2z_0, 0x7F4020>  # "Pmissile_rack2Z"
D:800475C0                     fileentry <0x1C9, aPmissile_rackz_0, 0x7F4A30>  # "Pmissile_rackZ"
D:800475CC                     fileentry <0x1CA, aPmodemboxz_0, 0x7F4E10>  # "PmodemboxZ"
D:800475D8                     fileentry <0x1CB, aPmotorbikez_0, 0x7F5150>  # "PmotorbikeZ"
D:800475E4                     fileentry <0x1CC, aPmp5kmagz_0, 0x7F6010>  # "Pmp5kmagZ"
D:800475F0                     fileentry <0x1CD, aPnintendologoz_0, 0x7F6160>  # "PnintendologoZ"
D:800475FC                     fileentry <0x1CE, aPoil_drum1z_0, 0x7F8C40>  # "Poil_drum1Z"
D:80047608                     fileentry <0x1CF, aPoil_drum2z_0, 0x7F8EB0>  # "Poil_drum2Z"
D:80047614                     fileentry <0x1D0, aPoil_drum3z_0, 0x7F91A0>  # "Poil_drum3Z"
D:80047620                     fileentry <0x1D1, aPoil_drum5z_0, 0x7F9490>  # "Poil_drum5Z"
D:8004762C                     fileentry <0x1D2, aPoil_drum6z_0, 0x7F9780>  # "Poil_drum6Z"
D:80047638                     fileentry <0x1D3, aPoil_drum7z_0, 0x7F9A90>  # "Poil_drum7Z"
D:80047644                     fileentry <0x1D4, aPpadlockz_0, 0x7F9D90>  # "PpadlockZ"
D:80047650                     fileentry <0x1D5, aPpalmz_0, 0x7FA7E0>  # "PpalmZ"
D:8004765C                     fileentry <0x1D6, aPpalmtreez_0, 0x7FAC30>  # "PpalmtreeZ"
D:80047668                     fileentry <0x1D7, aPphone1z_0, 0x7FB100>  # "Pphone1Z"
D:80047674                     fileentry <0x1D8, aPplanez_0, 0x7FB240>  # "PplaneZ"
D:80047680                     fileentry <0x1D9, aPplant11z_0, 0x7FD820>  # "Pplant11Z"
D:8004768C                     fileentry <0x1DA, aPplant1z_0, 0x7FDBE0>  # "Pplant1Z"
D:80047698                     fileentry <0x1DB, aPplant2z_0, 0x7FDF70>  # "Pplant2Z"
D:800476A4                     fileentry <0x1DC, aPplant2bz_0, 0x7FE2D0>  # "Pplant2bZ"
D:800476B0                     fileentry <0x1DD, aPplant3z_0, 0x7FE6E0>  # "Pplant3Z"
D:800476BC                     fileentry <0x1DE, aPradio_unit1z_0, 0x7FEB30>  # "Pradio_unit1Z"
D:800476C8                     fileentry <0x1DF, aPradio_unit2z_0, 0x7FECE0>  # "Pradio_unit2Z"
D:800476D4                     fileentry <0x1E0, aPradio_unit3z_0, 0x7FEEA0>  # "Pradio_unit3Z"
D:800476E0                     fileentry <0x1E1, aPradio_unit4z_0, 0x7FF060>  # "Pradio_unit4Z"
D:800476EC                     fileentry <0x1E2, aProofgunz_0, 0x7FF220>  # "ProofgunZ"
D:800476F8                     fileentry <0x1E3, aPsafez_0, 0x7FF880>  # "PsafeZ"
D:80047704                     fileentry <0x1E4, aPsafedoorz_0, 0x7FFBD0>  # "PsafedoorZ"
D:80047710                     fileentry <0x1E5, aPsat1_reflectz_0, 0x8000C0>  # "Psat1_reflectZ"
D:8004771C                     fileentry <0x1E6, aPsatboxz_0, 0x801630>  # "PsatboxZ"
D:80047728                     fileentry <0x1E7, aPsatdishz_0, 0x801750>  # "PsatdishZ"
D:80047734                     fileentry <0x1E8, aPsec_panelz_0, 0x801BB0>  # "Psec_panelZ"
D:80047740                     fileentry <0x1E9, aPsev_door3z_0, 0x801D50>  # "Psev_door3Z"
D:8004774C                     fileentry <0x1EA, aPsev_door3_windz_0, 0x801FE0>  # "Psev_door3_windZ"
D:80047758                     fileentry <0x1EB, aPsev_door4_windz_0, 0x802370>  # "Psev_door4_windZ"
D:80047764                     fileentry <0x1EC, aPsev_doorz_0, 0x802750>  # "Psev_doorZ"
D:80047770                     fileentry <0x1ED, aPsev_door_v1z_0, 0x802AA0>  # "Psev_door_v1Z"
D:8004777C                     fileentry <0x1EE, aPsev_trislidez_0, 0x802DD0>  # "Psev_trislideZ"
D:80047788                     fileentry <0x1EF, aPsevdishz_0, 0x803180>  # "PsevdishZ"
D:80047794                     fileentry <0x1F0, aPsevdoormetslidez_0, 0x8040A0>  # "PsevdoormetslideZ"
D:800477A0                     fileentry <0x1F1, aPsevdoornowindz_0, 0x804380>  # "PsevdoornowindZ"
D:800477AC                     fileentry <0x1F2, aPsevdoorwindz_0, 0x8044F0>  # "PsevdoorwindZ"
D:800477B8                     fileentry <0x1F3, aPsevdoorwoodz_0, 0x804920>  # "PsevdoorwoodZ"
D:800477C4                     fileentry <0x1F4, aPshuttlez_0, 0x804CD0>  # "PshuttleZ"
D:800477D0                     fileentry <0x1F5, aPshuttle_door_lz_0, 0x8076D0>  # "Pshuttle_door_lZ"
D:800477DC                     fileentry <0x1F6, aPshuttle_door_rz_0, 0x808300>  # "Pshuttle_door_rZ"
D:800477E8                     fileentry <0x1F7, aPsilencerz_0, 0x809000>  # "PsilencerZ"
D:800477F4                     fileentry <0x1F8, aPsilo_lift_doorz_0, 0x8091A0>  # "Psilo_lift_doorZ"
D:80047800                     fileentry <0x1F9, aPsilotopdoorz_0, 0x8093E0>  # "PsilotopdoorZ"
D:8004780C                     fileentry <0x1FA, aPskorpionmagz_0, 0x8096D0>  # "PskorpionmagZ"
D:80047818                     fileentry <0x1FB, aPspectremagz_0, 0x809830>  # "PspectremagZ"
D:80047824                     fileentry <0x1FC, aPspeedboatz_0, 0x8099A0>  # "PspeedboatZ"
D:80047830                     fileentry <0x1FD, aPst_pete_room_1iz_0, 0x80A6E0>  # "Pst_pete_room_1iZ"
D:8004783C                     fileentry <0x1FE, aPst_pete_room_2iz_0, 0x80D820>  # "Pst_pete_room_2iZ"
D:80047848                     fileentry <0x1FF, aPst_pete_room_3tz_0, 0x810A00>  # "Pst_pete_room_3tZ"
D:80047854                     fileentry <0x200, aPst_pete_room_5cz_0, 0x813940>  # "Pst_pete_room_5cZ"
D:80047860                     fileentry <0x201, aPst_pete_room_6cz_0, 0x816ED0>  # "Pst_pete_room_6cZ"
D:8004786C                     fileentry <0x202, aPsteel_door1z_0, 0x81A2E0>  # "Psteel_door1Z"
D:80047878                     fileentry <0x203, aPsteel_door2z_0, 0x81A550>  # "Psteel_door2Z"
D:80047884                     fileentry <0x204, aPsteel_door2bz_0, 0x81A800>  # "Psteel_door2bZ"
D:80047890                     fileentry <0x205, aPsteel_door3z_0, 0x81AAD0>  # "Psteel_door3Z"
D:8004789C                     fileentry <0x206, aPstool1z_0, 0x81ADA0>  # "Pstool1Z"
D:800478A8                     fileentry <0x207, aPswipe_card2z_0, 0x81B060>  # "Pswipe_card2Z"
D:800478B4                     fileentry <0x208, aPswivel_chair1z_0, 0x81B1F0>  # "Pswivel_chair1Z"
D:800478C0                     fileentry <0x209, aPtankz_0, 0x81B480>  # "PtankZ"
D:800478CC                     fileentry <0x20A, aPtigerz_0, 0x81CF20>  # "PtigerZ"
D:800478D8                     fileentry <0x20B, aPtorpedo_rackz_0, 0x81EDB0>  # "Ptorpedo_rackZ"
D:800478E4                     fileentry <0x20C, aPtrain_door2z_0, 0x81F630>  # "Ptrain_door2Z"
D:800478F0                     fileentry <0x20D, aPtrain_door3z_0, 0x81FA00>  # "Ptrain_door3Z"
D:800478FC                     fileentry <0x20E, aPtrain_doorz_0, 0x81FE20>  # "Ptrain_doorZ"
D:80047908                     fileentry <0x20F, aPtrainextdoorz_0, 0x820090>  # "PtrainextdoorZ"
D:80047914                     fileentry <0x210, aPtt33magz_0, 0x8203D0>  # "Ptt33magZ"
D:80047920                     fileentry <0x211, aPtuning_console1z_0, 0x820510>  # "Ptuning_console1Z"
D:8004792C                     fileentry <0x212, aPtv1z_0, 0x820A30>  # "Ptv1Z"
D:80047938                     fileentry <0x213, aPtv4screenz_0, 0x820C00>  # "Ptv4screenZ"
D:80047944                     fileentry <0x214, aPtv_holderz_0, 0x820DA0>  # "Ptv_holderZ"
D:80047950                     fileentry <0x215, aPtvscreenz_1, 0x821470>  # "PtvscreenZ"
D:8004795C                     fileentry <0x216, aPuzimagz_0, 0x821540>  # "PuzimagZ"
D:80047968                     fileentry <0x217, aPvertdoorz_1, 0x821680>  # "PvertdoorZ"
D:80047974                     fileentry <0x218, aPwalletbondz_0, 0x821C90>  # "PwalletbondZ"
D:80047980                     fileentry <0x219, aPwindowz_0, 0x823240>  # "PwindowZ"
D:8004798C                     fileentry <0x21A, aPwindow_cor11z_1, 0x823330>  # "Pwindow_cor11Z"
D:80047998                     fileentry <0x21B, aPwindow_lib_lg1z_0, 0x823410>  # "Pwindow_lib_lg1Z"
D:800479A4                     fileentry <0x21C, aPwindow_lib_sm1z_0, 0x8234F0>  # "Pwindow_lib_sm1Z"
D:800479B0                     fileentry <0x21D, aPwood_lg_crate1z_0, 0x8235E0>  # "Pwood_lg_crate1Z"
D:800479BC                     fileentry <0x21E, aPwood_lg_crate2z_0, 0x823860>  # "Pwood_lg_crate2Z"
D:800479C8                     fileentry <0x21F, aPwood_md_crate3z_0, 0x823A80>  # "Pwood_md_crate3Z"
D:800479D4                     fileentry <0x220, aPwood_sm_crate4z_0, 0x823CA0>  # "Pwood_sm_crate4Z"
D:800479E0                     fileentry <0x221, aPwood_sm_crate5z_0, 0x823F00>  # "Pwood_sm_crate5Z"
D:800479EC                     fileentry <0x222, aPwood_sm_crate6z_0, 0x824160>  # "Pwood_sm_crate6Z"
D:800479F8                     fileentry <0x223, aPwooden_table1z_0, 0x824380>  # "Pwooden_table1Z"
D:80047A04                     fileentry <0x224, aPwppkmagz_0, 0x8246F0>  # "PwppkmagZ"
D:80047A10                     fileentry <0x225, aTbg_ame_all_p_stanz_2, 0x824830>  # "Tbg_ame_all_p_stanZ"
D:80047A1C                     fileentry <0x226, aTbg_arch_all_p_stanz_0, 0x826160>  # "Tbg_arch_all_p_stanZ"
D:80047A28                     fileentry <0x227, aTbg_arec_all_p_stanz_0, 0x82BE50>  # "Tbg_arec_all_p_stanZ"
D:80047A34                     fileentry <0x228, aTbg_ark_all_p_stanz_0, 0x8341A0>  # "Tbg_ark_all_p_stanZ"
D:80047A40                     fileentry <0x229, aTbg_ash_all_p_stanz, 0x83D160>  # "Tbg_ash_all_p_stanZ"
D:80047A4C                     fileentry <0x22A, aTbg_azt_all_p_stanz_0, 0x83EA90>  # "Tbg_azt_all_p_stanZ"
D:80047A58                     fileentry <0x22B, aTbg_cat_all_p_stanz_0, 0x844010>  # "Tbg_cat_all_p_stanZ"
D:80047A64                     fileentry <0x22C, aTbg_cave_all_p_stanz_0, 0x846740>  # "Tbg_cave_all_p_stanZ"
D:80047A70                     fileentry <0x22D, aTbg_crad_all_p_stanz_0, 0x84B630>  # "Tbg_crad_all_p_stanZ"
D:80047A7C                     fileentry <0x22E, aTbg_cryp_all_p_stanz_0, 0x84DF40>  # "Tbg_cryp_all_p_stanZ"
D:80047A88                     fileentry <0x22F, aTbg_dam_all_p_stanz_0, 0x850FB0>  # "Tbg_dam_all_p_stanZ"
D:80047A94                     fileentry <0x230, aTbg_depo_all_p_stanz_0, 0x85B390>  # "Tbg_depo_all_p_stanZ"
D:80047AA0                     fileentry <0x231, aTbg_dest_all_p_stanz_0, 0x8622D0>  # "Tbg_dest_all_p_stanZ"
D:80047AAC                     fileentry <0x232, aTbg_dish_all_p_stanz_0, 0x868BC0>  # "Tbg_dish_all_p_stanZ"
D:80047AB8                     fileentry <0x233, aTbg_ear_all_p_stanz_0, 0x8696D0>  # "Tbg_ear_all_p_stanZ"
D:80047AC4                     fileentry <0x234, aTbg_eld_all_p_stanz_0, 0x8696D0>  # "Tbg_eld_all_p_stanZ"
D:80047AD0                     fileentry <0x235, aTbg_imp_all_p_stanz, 0x8696D0>  # "Tbg_imp_all_p_stanZ"
D:80047ADC                     fileentry <0x236, aTbg_jun_all_p_stanz_0, 0x86B000>  # "Tbg_jun_all_p_stanZ"
D:80047AE8                     fileentry <0x237, aTbg_lee_all_p_stanz_0, 0x872150>  # "Tbg_lee_all_p_stanZ"
D:80047AF4                     fileentry <0x238, aTbg_len_all_p_stanz_0, 0x872150>  # "Tbg_len_all_p_stanZ"
D:80047B00                     fileentry <0x239, aTbg_lip_all_p_stanz_0, 0x872C10>  # "Tbg_lip_all_p_stanZ"
D:80047B0C                     fileentry <0x23A, aTbg_lue_all_p_stanz_0, 0x872C10>  # "Tbg_lue_all_p_stanZ"
D:80047B18                     fileentry <0x23B, aTbg_oat_all_p_stanz_0, 0x872C10>  # "Tbg_oat_all_p_stanZ"
D:80047B24                     fileentry <0x23C, aTbg_pam_all_p_stanz_0, 0x874510>  # "Tbg_pam_all_p_stanZ"
D:80047B30                     fileentry <0x23D, aTbg_pete_all_p_stanz_0, 0x874510>  # "Tbg_pete_all_p_stanZ"
D:80047B3C                     fileentry <0x23E, aTbg_ref_all_p_stanz_0, 0x878BA0>  # "Tbg_ref_all_p_stanZ"
D:80047B48                     fileentry <0x23F, aTbg_rit_all_p_stanz_0, 0x87A970>  # "Tbg_rit_all_p_stanZ"
D:80047B54                     fileentry <0x240, aTbg_run_all_p_stanz_0, 0x87A970>  # "Tbg_run_all_p_stanZ"
D:80047B60                     fileentry <0x241, aTbg_sev_all_p_stanz_0, 0x87C3F0>  # "Tbg_sev_all_p_stanZ"
D:80047B6C                     fileentry <0x242, aTbg_sevb_all_p_stanz_0, 0x8801C0>  # "Tbg_sevb_all_p_stanZ"
D:80047B78                     fileentry <0x243, aTbg_sevx_all_p_stanz_1, 0x885100>  # "Tbg_sevx_all_p_stanZ"
D:80047B84                     fileentry <0x244, aTbg_silo_all_p_stanz_0, 0x88E430>  # "Tbg_silo_all_p_stanZ"
D:80047B90                     fileentry <0x245, aTbg_stat_all_p_stanz_0, 0x8974D0>  # "Tbg_stat_all_p_stanZ"
D:80047B9C                     fileentry <0x246, aTbg_tra_all_p_stanz_0, 0x89C390>  # "Tbg_tra_all_p_stanZ"
D:80047BA8                     fileentry <0x247, aTbg_wax_all_p_stanz_0, 0x89E760>  # "Tbg_wax_all_p_stanZ"
D:80047BB4                     fileentry <0x248, aUbriefarchz, 0x89E760>  # "UbriefarchZ"
D:80047BC0                     fileentry <0x249, aUbriefarkz, 0x89E780>  # "UbriefarkZ"
D:80047BCC                     fileentry <0x24A, aUbriefaztz, 0x89E7A0>  # "UbriefaztZ"
D:80047BD8                     fileentry <0x24B, aUbriefcavez, 0x89E7C0>  # "UbriefcaveZ"
D:80047BE4                     fileentry <0x24C, aUbriefcontrolz, 0x89E7E0>  # "UbriefcontrolZ"
D:80047BF0                     fileentry <0x24D, aUbriefcradz, 0x89E800>  # "UbriefcradZ"
D:80047BFC                     fileentry <0x24E, aUbriefcrypz, 0x89E820>  # "UbriefcrypZ"
D:80047C08                     fileentry <0x24F, aUbriefdamz, 0x89E840>  # "UbriefdamZ"
D:80047C14                     fileentry <0x250, aUbriefdepoz, 0x89E860>  # "UbriefdepoZ"
D:80047C20                     fileentry <0x251, aUbriefdestz, 0x89E880>  # "UbriefdestZ"
D:80047C2C                     fileentry <0x252, aUbriefjunz, 0x89E8A0>  # "UbriefjunZ"
D:80047C38                     fileentry <0x253, aUbriefpetez, 0x89E8C0>  # "UbriefpeteZ"
D:80047C44                     fileentry <0x254, aUbriefrunz, 0x89E8E0>  # "UbriefrunZ"
D:80047C50                     fileentry <0x255, aUbriefsevbz, 0x89E900>  # "UbriefsevbZ"
D:80047C5C                     fileentry <0x256, aUbriefsevbunkerz, 0x89E920>  # "UbriefsevbunkerZ"
D:80047C68                     fileentry <0x257, aUbriefsevxz, 0x89E940>  # "UbriefsevxZ"
D:80047C74                     fileentry <0x258, aUbriefsevxbz, 0x89E960>  # "UbriefsevxbZ"
D:80047C80                     fileentry <0x259, aUbriefsiloz, 0x89E980>  # "UbriefsiloZ"
D:80047C8C                     fileentry <0x25A, aUbriefstatuez, 0x89E9A0>  # "UbriefstatueZ"
D:80047C98                     fileentry <0x25B, aUbrieftraz, 0x89E9C0>  # "UbrieftraZ"
D:80047CA4                     fileentry <0x25C, aUmp_setupamez, 0x89E9E0>  # "Ump_setupameZ"
D:80047CB0                     fileentry <0x25D, aUmp_setuparchz, 0x89F100>  # "Ump_setuparchZ"
D:80047CBC                     fileentry <0x25E, aUmp_setuparkz, 0x8A1EA0>  # "Ump_setuparkZ"
D:80047CC8                     fileentry <0x25F, aUmp_setupashz, 0x8A3BE0>  # "Ump_setupashZ"
D:80047CD4                     fileentry <0x260, aUmp_setupcavez, 0x8A42D0>  # "Ump_setupcaveZ"
D:80047CE0                     fileentry <0x261, aUmp_setupcradz, 0x8A6830>  # "Ump_setupcradZ"
D:80047CEC                     fileentry <0x262, aUmp_setupcrypz, 0x8A7190>  # "Ump_setupcrypZ"
D:80047CF8                     fileentry <0x263, aUmp_setupdishz, 0x8A7EF0>  # "Ump_setupdishZ"
D:80047D04                     fileentry <0x264, aUmp_setupimpz, 0x8A82E0>  # "Ump_setupimpZ"
D:80047D10                     fileentry <0x265, aUmp_setupoatz, 0x8A8920>  # "Ump_setupoatZ"
D:80047D1C                     fileentry <0x266, aUmp_setuprefz, 0x8A8C70>  # "Ump_setuprefZ"
D:80047D28                     fileentry <0x267, aUmp_setupsevbz, 0x8A9080>  # "Ump_setupsevbZ"
D:80047D34                     fileentry <0x268, aUmp_setupstatuez, 0x8AA390>  # "Ump_setupstatueZ"
D:80047D40                     fileentry <0x269, aUsetuparchz_0, 0x8AB210>  # "UsetuparchZ"
D:80047D4C                     fileentry <0x26A, aUsetuparkz_1, 0x8AF820>  # "UsetuparkZ"
D:80047D58                     fileentry <0x26B, aUsetupaztz_1, 0x8B33B0>  # "UsetupaztZ"
D:80047D64                     fileentry <0x26C, aUsetupcavez_0, 0x8B5CB0>  # "UsetupcaveZ"
D:80047D70                     fileentry <0x26D, aUsetupcontrolz_1, 0x8B9B10>  # "UsetupcontrolZ"
D:80047D7C                     fileentry <0x26E, aUsetupcradz_0, 0x8BD610>  # "UsetupcradZ"
D:80047D88                     fileentry <0x26F, aUsetupcrypz_0, 0x8BF240>  # "UsetupcrypZ"
D:80047D94                     fileentry <0x270, aUsetupdamz_1, 0x8C10D0>  # "UsetupdamZ"
D:80047DA0                     fileentry <0x271, aUsetupdepoz_0, 0x8C53A0>  # "UsetupdepoZ"
D:80047DAC                     fileentry <0x272, aUsetupdestz_0, 0x8C8330>  # "UsetupdestZ"
D:80047DB8                     fileentry <0x273, aUsetupjunz_1, 0x8CA680>  # "UsetupjunZ"
D:80047DC4                     fileentry <0x274, aUsetuplenz_1, 0x8CDD80>  # "UsetuplenZ"
D:80047DD0                     fileentry <0x275, aUsetuppetez_0, 0x8CE350>  # "UsetuppeteZ"
D:80047DDC                     fileentry <0x276, aUsetuprunz_1, 0x8D12D0>  # "UsetuprunZ"
D:80047DE8                     fileentry <0x277, aUsetupsevbz_0, 0x8D2B30>  # "UsetupsevbZ"
D:80047DF4                     fileentry <0x278, aUsetupsevbunkerz_1, 0x8D5190>  # "UsetupsevbunkerZ"
D:80047E00                     fileentry <0x279, aUsetupsevxz_0, 0x8D6BC0>  # "UsetupsevxZ"
D:80047E0C                     fileentry <0x27A, aUsetupsevxbz_0, 0x8DAED0>  # "UsetupsevxbZ"
D:80047E18                     fileentry <0x27B, aUsetupsiloz_0, 0x8DEFC0>  # "UsetupsiloZ"
D:80047E24                     fileentry <0x27C, aUsetupstatuez_0, 0x8E1A10>  # "UsetupstatueZ"
D:80047E30                     fileentry <0x27D, aUsetuptraz_1, 0x8E41E0>  # "UsetuptraZ"
D:80047E3C                     fileentry <0x27E, aLamee_0, 0x8E7410>  # "LameE"
D:80047E48                     fileentry <0x27F, aLamej_0, 0x8E7420>  # "LameJ"
D:80047E54                     fileentry <0x280, aLarche_1, 0x8E7430>  # "LarchE"
D:80047E60                     fileentry <0x281, aLarchj_1, 0x8E7A60>  # "LarchJ"
D:80047E6C                     fileentry <0x282, aLarece_1, 0x8E80C0>  # "LarecE"
D:80047E78                     fileentry <0x283, aLarecj_1, 0x8E8690>  # "LarecJ"
D:80047E84                     fileentry <0x284, aLarke_0, 0x8E8C20>  # "LarkE"
D:80047E90                     fileentry <0x285, aLarkj_0, 0x8E92C0>  # "LarkJ"
D:80047E9C                     fileentry <0x286, aLashe_0, 0x8E9970>  # "LashE"
D:80047EA8                     fileentry <0x287, aLashj_0, 0x8E9980>  # "LashJ"
D:80047EB4                     fileentry <0x288, aLazte_0, 0x8E9990>  # "LaztE"
D:80047EC0                     fileentry <0x289, aLaztj_0, 0x8E9DD0>  # "LaztJ"
D:80047ECC                     fileentry <0x28A, aLcate_0, 0x8EA280>  # "LcatE"
D:80047ED8                     fileentry <0x28B, aLcatj_0, 0x8EA290>  # "LcatJ"
D:80047EE4                     fileentry <0x28C, aLcavee_1, 0x8EA2A0>  # "LcaveE"
D:80047EF0                     fileentry <0x28D, aLcavej_1, 0x8EA6A0>  # "LcaveJ"
D:80047EFC                     fileentry <0x28E, aLcrade_1, 0x8EAB00>  # "LcradE"
D:80047F08                     fileentry <0x28F, aLcradj_1, 0x8EAFD0>  # "LcradJ"
D:80047F14                     fileentry <0x290, aLcrype_1, 0x8EB480>  # "LcrypE"
D:80047F20                     fileentry <0x291, aLcrypj_1, 0x8EB6D0>  # "LcrypJ"
D:80047F2C                     fileentry <0x292, aLdame_0, 0x8EB990>  # "LdamE"
D:80047F38                     fileentry <0x293, aLdamj_0, 0x8EBDE0>  # "LdamJ"
D:80047F44                     fileentry <0x294, aLdepoe_1, 0x8EC250>  # "LdepoE"
D:80047F50                     fileentry <0x295, aLdepoj_1, 0x8EC5C0>  # "LdepoJ"
D:80047F5C                     fileentry <0x296, aLdeste_1, 0x8EC900>  # "LdestE"
D:80047F68                     fileentry <0x297, aLdestj_1, 0x8ECD90>  # "LdestJ"
D:80047F74                     fileentry <0x298, aLdishe_1, 0x8ED1F0>  # "LdishE"
D:80047F80                     fileentry <0x299, aLdishj_1, 0x8ED200>  # "LdishJ"
D:80047F8C                     fileentry <0x29A, aLeare_0, 0x8ED210>  # "LearE"
D:80047F98                     fileentry <0x29B, aLearj_0, 0x8ED220>  # "LearJ"
D:80047FA4                     fileentry <0x29C, aLelde_0, 0x8ED230>  # "LeldE"
D:80047FB0                     fileentry <0x29D, aLeldj_0, 0x8ED240>  # "LeldJ"
D:80047FBC                     fileentry <0x29E, aLgune_0, 0x8ED250>  # "LgunE"
D:80047FC8                     fileentry <0x29F, aLgunj_0, 0x8ED970>  # "LgunJ"
D:80047FD4                     fileentry <0x2A0, aLimpe_0, 0x8EE0C0>  # "LimpE"
D:80047FE0                     fileentry <0x2A1, aLimpj_0, 0x8EE0D0>  # "LimpJ"
D:80047FEC                     fileentry <0x2A2, aLjune_0, 0x8EE0E0>  # "LjunE"
D:80047FF8                     fileentry <0x2A3, aLjunj_0, 0x8EE600>  # "LjunJ"
D:80048004                     fileentry <0x2A4, aLleee_0, 0x8EEB40>  # "LleeE"
D:80048010                     fileentry <0x2A5, aLleej_0, 0x8EEB50>  # "LleeJ"
D:8004801C                     fileentry <0x2A6, aLlene_0, 0x8EEB60>  # "LlenE"
D:80048028                     fileentry <0x2A7, aLlenj_0, 0x8EF1A0>  # "LlenJ"
D:80048034                     fileentry <0x2A8, aLlipe_0, 0x8EF450>  # "LlipE"
D:80048040                     fileentry <0x2A9, aLlipj_0, 0x8EF460>  # "LlipJ"
D:8004804C                     fileentry <0x2AA, aLluee_0, 0x8EF470>  # "LlueE"
D:80048058                     fileentry <0x2AB, aLluej_0, 0x8EF480>  # "LlueJ"
D:80048064                     fileentry <0x2AC, aLmisce_1, 0x8EF490>  # "LmiscE"
D:80048070                     fileentry <0x2AD, aLmiscj_1, 0x8EF730>  # "LmiscJ"
D:8004807C                     fileentry <0x2AE, aLmpmenue_0, 0x8EFA10>  # "LmpmenuE"
D:80048088                     fileentry <0x2AF, aLmpmenuj_0, 0x8EFBB0>  # "LmpmenuJ"
D:80048094                     fileentry <0x2B0, aLmpweaponse_0, 0x8EFD40>  # "LmpweaponsE"
D:800480A0                     fileentry <0x2B1, aLmpweaponsj_0, 0x8EFE00>  # "LmpweaponsJ"
D:800480AC                     fileentry <0x2B2, aLoate_0, 0x8EFEE0>  # "LoatE"
D:800480B8                     fileentry <0x2B3, aLoatj_0, 0x8EFEF0>  # "LoatJ"
D:800480C4                     fileentry <0x2B4, aLoptionse_0, 0x8EFF00>  # "LoptionsE"
D:800480D0                     fileentry <0x2B5, aLoptionsj_0, 0x8F0130>  # "LoptionsJ"
D:800480DC                     fileentry <0x2B6, aLpame_0, 0x8F0380>  # "LpamE"
D:800480E8                     fileentry <0x2B7, aLpamj_0, 0x8F0390>  # "LpamJ"
D:800480F4                     fileentry <0x2B8, aLpetee_1, 0x8F03A0>  # "LpeteE"
D:80048100                     fileentry <0x2B9, aLpetej_1, 0x8F0820>  # "LpeteJ"
D:8004810C                     fileentry <0x2BA, aLpropobje_0, 0x8F0C90>  # "LpropobjE"
D:80048118                     fileentry <0x2BB, aLpropobjj_0, 0x8F0F30>  # "LpropobjJ"
D:80048124                     fileentry <0x2BC, aLrefe_0, 0x8F11F0>  # "LrefE"
D:80048130                     fileentry <0x2BD, aLrefj_0, 0x8F1200>  # "LrefJ"
D:8004813C                     fileentry <0x2BE, aLrite_0, 0x8F1210>  # "LritE"
D:80048148                     fileentry <0x2BF, aLritj_0, 0x8F1220>  # "LritJ"
D:80048154                     fileentry <0x2C0, aLrune_0, 0x8F1230>  # "LrunE"
D:80048160                     fileentry <0x2C1, aLrunj_0, 0x8F14A0>  # "LrunJ"
D:8004816C                     fileentry <0x2C2, aLseve_0, 0x8F1730>  # "LsevE"
D:80048178                     fileentry <0x2C3, aLsevj_0, 0x8F1C90>  # "LsevJ"
D:80048184                     fileentry <0x2C4, aLsevbe_1, 0x8F21A0>  # "LsevbE"
D:80048190                     fileentry <0x2C5, aLsevbj_1, 0x8F28F0>  # "LsevbJ"
D:8004819C                     fileentry <0x2C6, aLsevxe_1, 0x8F30E0>  # "LsevxE"
D:800481A8                     fileentry <0x2C7, aLsevxj_1, 0x8F3540>  # "LsevxJ"
D:800481B4                     fileentry <0x2C8, aLsevxbe_0, 0x8F3900>  # "LsevxbE"
D:800481C0                     fileentry <0x2C9, aLsevxbj_0, 0x8F3D90>  # "LsevxbJ"
D:800481CC                     fileentry <0x2CA, aLshoe_0, 0x8F41E0>  # "LshoE"
D:800481D8                     fileentry <0x2CB, aLshoj_0, 0x8F41F0>  # "LshoJ"
D:800481E4                     fileentry <0x2CC, aLsiloe_1, 0x8F4200>  # "LsiloE"
D:800481F0                     fileentry <0x2CD, aLsiloj_1, 0x8F47B0>  # "LsiloJ"
D:800481FC                     fileentry <0x2CE, aLstate_1, 0x8F4D90>  # "LstatE"
D:80048208                     fileentry <0x2CF, aLstatj_1, 0x8F56B0>  # "LstatJ"
D:80048214                     fileentry <0x2D0, aLtitlee_0, 0x8F5F20>  # "LtitleE"
D:80048220                     fileentry <0x2D1, aLtitlej_0, 0x8F69E0>  # "LtitleJ"
D:8004822C                     fileentry <0x2D2, aLtrae_0, 0x8F7570>  # "LtraE"
D:80048238                     fileentry <0x2D3, aLtraj_0, 0x8F79A0>  # "LtraJ"
D:80048244                     fileentry <0x2D4, aLwaxe_0, 0x8F7DC0>  # "LwaxE"
D:80048250                     fileentry <0x2D5, aLwaxj_0, 0x8F7DD0>  # "LwaxJ"
D:8004825C                     fileentry <0x2D6, aObOb_end_seg, 0x8F7DE0>  # "ob/ob_end.seg"
D:80048268                     fileentry <0>
D:80048274                     fileentry <0>
D:80048280                     fileentry <0>
D:8004828C                     fileentry <0>
D:80048298                     fileentry <0>
D:800482A4                     fileentry <0>
D:800482B0                     fileentry <0>
D:800482BC                     fileentry <0>
D:800482C8                     fileentry <0>
D:800482D4     file_entry_max: .word 0x2D7              # DATA XREF: ob_c_debug_setup+1Cr
D:800482D4                                              # something_mem_bank_a0r
D:800482D4                                              # get_index_num_of_named_resource+8o
D:800482D4                                              # get_index_num_of_named_resource+10r
D:800482D4                                              # sub_CODE_7F0BD38C+8o
D:800482D4                                              # sub_CODE_7F0BD38C+10r
D:800482D4                                              # sub_CODE_7F0BD3E4r
D:800482D4                                              # sub_CODE_7F0BD410r
D:800482D8                     .word 0
D:800482DC                     .word 0
*/

/* rodata
D:80058DA0     aBgBg_NULLall_p_seg_0:.word 0            # DATA XREF: D:resource_tableo
D:80058DA4     aBgBg_sev_all_p_seg_0:.ascii "bg/bg_sev_all_p.seg"<0>
D:80058DA4                                              # DATA XREF: D:file_entry_offseto
D:80058DB8     aBgBg_silo_all_p_seg_0:.ascii "bg/bg_silo_all_p.seg"<0>
D:80058DB8                                              # DATA XREF: D:8004606Co
D:80058DCD                     .align 4
D:80058DD0     aBgBg_stat_all_p_seg_0:.ascii "bg/bg_stat_all_p.seg"<0>
D:80058DD0                                              # DATA XREF: D:80046078o
D:80058DE5                     .align 2
D:80058DE8     aBgBg_arec_all_p_seg_0:.ascii "bg/bg_arec_all_p.seg"<0>
D:80058DE8                                              # DATA XREF: D:80046084o
D:80058DFD                     .align 4
D:80058E00     aBgBg_arch_all_p_seg_0:.ascii "bg/bg_arch_all_p.seg"<0>
D:80058E00                                              # DATA XREF: D:80046090o
D:80058E15                     .align 2
D:80058E18     aBgBg_tra_all_p_seg_0:.ascii "bg/bg_tra_all_p.seg"<0>
D:80058E18                                              # DATA XREF: D:8004609Co
D:80058E2C     aBgBg_dest_all_p_seg_0:.ascii "bg/bg_dest_all_p.seg"<0>
D:80058E2C                                              # DATA XREF: D:800460A8o
D:80058E41                     .align 2
D:80058E44     aBgBg_sevb_all_p_seg_0:.ascii "bg/bg_sevb_all_p.seg"<0>
D:80058E44                                              # DATA XREF: D:800460B4o
D:80058E59                     .align 2
D:80058E5C     aBgBg_azt_all_p_seg_0:.ascii "bg/bg_azt_all_p.seg"<0>
D:80058E5C                                              # DATA XREF: D:800460C0o
D:80058E70     aBgBg_pete_all_p_seg_0:.ascii "bg/bg_pete_all_p.seg"<0><0><0><0>
D:80058E70                                              # DATA XREF: D:800460CCo
D:80058E88     aBgBg_depo_all_p_seg_0:.ascii "bg/bg_depo_all_p.seg"<0>
D:80058E88                                              # DATA XREF: D:800460D8o
D:80058E9D                     .byte 0, 0, 0
D:80058EA0     aBgBg_ref_all_p_seg_0:.ascii "bg/bg_ref_all_p.seg"<0>
D:80058EA0                                              # DATA XREF: D:800460E4o
D:80058EB4     aBgBg_cryp_all_p_seg_0:.ascii "bg/bg_cryp_all_p.seg"<0>
D:80058EB4                                              # DATA XREF: D:800460F0o
D:80058EC9                     .byte 0, 0, 0
D:80058ECC     aBgBg_dam_all_p_seg_0:.ascii "bg/bg_dam_all_p.seg"<0>
D:80058ECC                                              # DATA XREF: D:800460FCo
D:80058EE0     aBgBg_ark_all_p_seg_0:.ascii "bg/bg_ark_all_p.seg"<0>
D:80058EE0                                              # DATA XREF: D:80046108o
D:80058EF4     aBgBg_run_all_p_seg_0:.ascii "bg/bg_run_all_p.seg"<0>
D:80058EF4                                              # DATA XREF: D:80046114o
D:80058F08     aBgBg_sevx_all_p_seg_1:.ascii "bg/bg_sevx_all_p.seg"<0>
D:80058F08                                              # DATA XREF: D:80046120o
D:80058F1D                     .byte 0, 0, 0
D:80058F20     aBgBg_jun_all_p_seg_0:.ascii "bg/bg_jun_all_p.seg"<0>
D:80058F20                                              # DATA XREF: D:8004612Co
D:80058F34     aBgBg_dish_all_p_seg_0:.ascii "bg/bg_dish_all_p.seg"<0>
D:80058F34                                              # DATA XREF: D:80046138o
D:80058F49                     .byte 0, 0, 0
D:80058F4C     aBgBg_cave_all_p_seg_0:.ascii "bg/bg_cave_all_p.seg"<0>
D:80058F4C                                              # DATA XREF: D:80046144o
D:80058F61                     .byte 0, 0, 0
D:80058F64     aBgBg_cat_all_p_seg_0:.ascii "bg/bg_cat_all_p.seg"<0>
D:80058F64                                              # DATA XREF: D:80046150o
D:80058F78     aBgBg_crad_all_p_seg_0:.ascii "bg/bg_crad_all_p.seg"<0>
D:80058F78                                              # DATA XREF: D:8004615Co
D:80058F8D                     .byte 0, 0, 0
D:80058F90     aBgBg_sho_all_p_seg_0:.ascii "bg/bg_sho_all_p.seg"<0>
D:80058F90                                              # DATA XREF: D:80046168o
D:80058FA4     aBgBg_eld_all_p_seg_0:.ascii "bg/bg_eld_all_p.seg"<0>
D:80058FA4                                              # DATA XREF: D:80046174o
D:80058FB8     aBgBg_imp_all_p_seg:.ascii "bg/bg_imp_all_p.seg"<0>  # DATA XREF: D:80046180o
D:80058FCC     aBgBg_ash_all_p_seg:.ascii "bg/bg_ash_all_p.seg"<0>  # DATA XREF: D:8004618Co
D:80058FE0     aBgBg_lue_all_p_seg_0:.ascii "bg/bg_lue_all_p.seg"<0>
D:80058FE0                                              # DATA XREF: D:80046198o
D:80058FF4     aBgBg_ame_all_p_seg_2:.ascii "bg/bg_ame_all_p.seg"<0>
D:80058FF4                                              # DATA XREF: D:800461A4o
D:80059008     aBgBg_rit_all_p_seg_0:.ascii "bg/bg_rit_all_p.seg"<0>
D:80059008                                              # DATA XREF: D:800461B0o
D:8005901C     aBgBg_oat_all_p_seg_0:.ascii "bg/bg_oat_all_p.seg"<0>
D:8005901C                                              # DATA XREF: D:800461BCo
D:80059030     aBgBg_ear_all_p_seg_0:.ascii "bg/bg_ear_all_p.seg"<0>
D:80059030                                              # DATA XREF: D:800461C8o
D:80059044     aBgBg_lee_all_p_seg_0:.ascii "bg/bg_lee_all_p.seg"<0>
D:80059044                                              # DATA XREF: D:800461D4o
D:80059058     aBgBg_lip_all_p_seg_0:.ascii "bg/bg_lip_all_p.seg"<0>
D:80059058                                              # DATA XREF: D:800461E0o
D:8005906C     aBgBg_len_all_p_seg_0:.ascii "bg/bg_len_all_p.seg"<0>
D:8005906C                                              # DATA XREF: D:800461ECo
D:80059080     aBgBg_wax_all_p_seg_0:.ascii "bg/bg_wax_all_p.seg"<0>
D:80059080                                              # DATA XREF: D:800461F8o
D:80059094     aBgBg_pam_all_p_seg_0:.ascii "bg/bg_pam_all_p.seg"<0>
D:80059094                                              # DATA XREF: D:80046204o
D:800590A8     aCarmourguardz_0:.ascii "CarmourguardZ"<0>  # DATA XREF: D:80046210o
D:800590B6                     .half 0
D:800590B8     aCbaronsamediz_0:.ascii "CbaronsamediZ"<0>  # DATA XREF: D:8004621Co
D:800590C6                     .half 0
D:800590C8     aCbluecamguardz_0:.ascii "CbluecamguardZ"<0>  # DATA XREF: D:80046228o
D:800590D7                     .byte 0
D:800590D8     aCbluemanz_0:   .ascii "CbluemanZ"<0>    # DATA XREF: D:80046234o
D:800590E2                     .half 0
D:800590E4     aCbluewomanz_0: .ascii "CbluewomanZ"<0>  # DATA XREF: D:80046240o
D:800590F0     aCboilerbondz_0:.ascii "CboilerbondZ"<0>  # DATA XREF: D:8004624Co
D:800590FD                     .byte 0, 0, 0
D:80059100     aCboilertrevz_0:.ascii "CboilertrevZ"<0>  # DATA XREF: D:80046258o
D:8005910D                     .byte 0, 0, 0
D:80059110     aCborisz_0:     .ascii "CborisZ"<0>      # DATA XREF: D:80046264o
D:80059118     aCcamguardz_0:  .ascii "CcamguardZ"<0>   # DATA XREF: D:80046270o
D:80059123                     .byte 0
D:80059124     aCcardimanz_0:  .ascii "CcardimanZ"<0>   # DATA XREF: D:8004627Co
D:8005912F                     .byte 0
D:80059130     aCcheckmanz_0:  .ascii "CcheckmanZ"<0>   # DATA XREF: D:80046288o
D:8005913B                     .byte 0
D:8005913C     aCcommguardz_0: .ascii "CcommguardZ"<0>  # DATA XREF: D:80046294o
D:80059148     aCdjbondz_0:    .ascii "CdjbondZ"<0>     # DATA XREF: D:800462A0o
D:80059151                     .byte 0, 0, 0
D:80059154     aCfattechwomanz_1:.ascii "CfattechwomanZ"<0><0>  # DATA XREF: D:800462ACo
D:80059164     aCgreatguard2z_0:.ascii "Cgreatguard2Z"<0>  # DATA XREF: D:800462B8o
D:80059172                     .half 0
D:80059174     aCgreatguardz_0:.ascii "CgreatguardZ"<0>  # DATA XREF: D:800462C4o
D:80059181                     .byte 0, 0, 0
D:80059184     aCgreyguardz_0: .ascii "CgreyguardZ"<0>  # DATA XREF: D:800462D0o
D:80059190     aCgreymanz_0:   .ascii "CgreymanZ"<0>    # DATA XREF: D:800462DCo
D:8005919A                     .half 0
D:8005919C     aCheadalanz_0:  .ascii "CheadalanZ"<0>   # DATA XREF: D:800462E8o
D:800591A7                     .byte 0
D:800591A8     aCheadbz_0:     .ascii "CheadbZ"<0>      # DATA XREF: D:800462F4o
D:800591B0     aCheadbalaclavaz_0:.ascii "CheadbalaclavaZ"<0>  # DATA XREF: D:80046300o
D:800591C0     aCheadbikez_0:  .ascii "CheadbikeZ"<0>   # DATA XREF: D:8004630Co
D:800591CB                     .byte 0
D:800591CC     aCheadbrosnanz_0:.ascii "CheadbrosnanZ"<0>  # DATA XREF: D:80046318o
D:800591DA                     .half 0
D:800591DC     aCheadbrosnanboilerz_0:.ascii "CheadbrosnanboilerZ"<0>
D:800591DC                                              # DATA XREF: D:80046324o
D:800591F0     aCheadbrosnansnowz_0:.ascii "CheadbrosnansnowZ"<0>  # DATA XREF: D:80046330o
D:80059202                     .half 0
D:80059204     aCheadbrosnansuitz_0:.ascii "CheadbrosnansuitZ"<0>  # DATA XREF: D:8004633Co
D:80059216                     .half 0
D:80059218     aCheadbrosnantimberz_0:.ascii "CheadbrosnantimberZ"<0>
D:80059218                                              # DATA XREF: D:80046348o
D:8005922C     aCheadchrisz_0: .ascii "CheadchrisZ"<0>  # DATA XREF: D:80046354o
D:80059238     aCheaddavez_0:  .ascii "CheaddaveZ"<0>   # DATA XREF: D:80046360o
D:80059243                     .byte 0
D:80059244     aCheaddesz_0:   .ascii "CheaddesZ"<0>    # DATA XREF: D:8004636Co
D:8005924E                     .half 0
D:80059250     aCheadduncanz_0:.ascii "CheadduncanZ"<0>  # DATA XREF: D:80046378o
D:8005925D                     .byte 0, 0, 0
D:80059260     aCheaddwaynez_0:.ascii "CheaddwayneZ"<0>  # DATA XREF: D:80046384o
D:8005926D                     .byte 0, 0, 0
D:80059270     aCheadgrahamz_0:.ascii "CheadgrahamZ"<0>  # DATA XREF: D:80046390o
D:8005927D                     .byte 0, 0, 0
D:80059280     aCheadgrantz_0: .ascii "CheadgrantZ"<0>  # DATA XREF: D:8004639Co
D:8005928C     aCheadjimz_0:   .ascii "CheadjimZ"<0>    # DATA XREF: D:800463A8o
D:80059296                     .half 0
D:80059298     aCheadjoe2z_0:  .ascii "Cheadjoe2Z"<0>   # DATA XREF: D:800463B4o
D:800592A3                     .byte 0
D:800592A4     aCheadjoez_0:   .ascii "CheadjoeZ"<0>    # DATA XREF: D:800463C0o
D:800592AE                     .half 0
D:800592B0     aCheadjoelz_0:  .ascii "CheadjoelZ"<0>   # DATA XREF: D:800463CCo
D:800592BB                     .byte 0
D:800592BC     aCheadkarlz_0:  .ascii "CheadkarlZ"<0>   # DATA XREF: D:800463D8o
D:800592C7                     .byte 0
D:800592C8     aCheadkenz_0:   .ascii "CheadkenZ"<0>    # DATA XREF: D:800463E4o
D:800592D2                     .half 0
D:800592D4     aCheadleez_0:   .ascii "CheadleeZ"<0>    # DATA XREF: D:800463F0o
D:800592DE                     .half 0
D:800592E0     aCheadmandyz_0: .ascii "CheadmandyZ"<0>  # DATA XREF: D:800463FCo
D:800592EC     aCheadmarionz_0:.ascii "CheadmarionZ"<0>  # DATA XREF: D:80046408o
D:800592F9                     .byte 0, 0, 0
D:800592FC     aCheadmarkz_0:  .ascii "CheadmarkZ"<0>   # DATA XREF: D:80046414o
D:80059307                     .byte 0
D:80059308     aCheadmartinz_0:.ascii "CheadmartinZ"<0>  # DATA XREF: D:80046420o
D:80059315                     .byte 0, 0, 0
D:80059318     aCheadmishkinz_0:.ascii "CheadmishkinZ"<0>  # DATA XREF: D:8004642Co
D:80059326                     .half 0
D:80059328     aCheadneilz_0:  .ascii "CheadneilZ"<0>   # DATA XREF: D:80046438o
D:80059333                     .byte 0
D:80059334     aCheadpetez_0:  .ascii "CheadpeteZ"<0>   # DATA XREF: D:80046444o
D:8005933F                     .byte 0
D:80059340     aCheadrobinz_0: .ascii "CheadrobinZ"<0>  # DATA XREF: D:80046450o
D:8005934C     aCheadsallyz_0: .ascii "CheadsallyZ"<0>  # DATA XREF: D:8004645Co
D:80059358     aCheadscottz_0: .ascii "CheadscottZ"<0>  # DATA XREF: D:80046468o
D:80059364     aCheadshaunz_0: .ascii "CheadshaunZ"<0>  # DATA XREF: D:80046474o
D:80059370     aCheadsteveez_0:.ascii "CheadsteveeZ"<0>  # DATA XREF: D:80046480o
D:8005937D                     .byte 0, 0, 0
D:80059380     aCheadstevehz_0:.ascii "CheadstevehZ"<0>  # DATA XREF: D:8004648Co
D:8005938D                     .byte 0, 0, 0
D:80059390     aCheadvivienz_0:.ascii "CheadvivienZ"<0>  # DATA XREF: D:80046498o
D:8005939D                     .byte 0, 0, 0
D:800593A0     aCjawsz_0:      .ascii "CjawsZ"<0>       # DATA XREF: D:800464A4o
D:800593A7                     .byte 0
D:800593A8     aCjeanwomanz_0: .ascii "CjeanwomanZ"<0>  # DATA XREF: D:800464B0o
D:800593B4     aCmaydayz_0:    .ascii "CmaydayZ"<0>     # DATA XREF: D:800464BCo
D:800593BD                     .byte 0, 0, 0
D:800593C0     aCmoonfemalez_0:.ascii "CmoonfemaleZ"<0>  # DATA XREF: D:800464C8o
D:800593CD                     .byte 0, 0, 0
D:800593D0     aCmoonguardz_0: .ascii "CmoonguardZ"<0>  # DATA XREF: D:800464D4o
D:800593DC     aCnatalyaz_0:   .ascii "CnatalyaZ"<0>    # DATA XREF: D:800464E0o
D:800593E6                     .half 0
D:800593E8     aCnavyguardz_0: .ascii "CnavyguardZ"<0>  # DATA XREF: D:800464ECo
D:800593F4     aCoddjobz_0:    .ascii "CoddjobZ"<0>     # DATA XREF: D:800464F8o
D:800593FD                     .byte 0, 0, 0
D:80059400     aColiveguardz_0:.ascii "ColiveguardZ"<0>  # DATA XREF: D:80046504o
D:8005940D                     .byte 0, 0, 0
D:80059410     aCorumovz_0:    .ascii "CorumovZ"<0>     # DATA XREF: D:80046510o
D:80059419                     .byte 0, 0, 0
D:8005941C     aCpilotz_0:     .ascii "CpilotZ"<0>      # DATA XREF: D:8004651Co
D:80059424     aCredmanz_0:    .ascii "CredmanZ"<0>     # DATA XREF: D:80046528o
D:8005942D                     .byte 0, 0, 0
D:80059430     aCrusguardz_0:  .ascii "CrusguardZ"<0>   # DATA XREF: D:80046534o
D:8005943B                     .byte 0
D:8005943C     aCsnowbondz_0:  .ascii "CsnowbondZ"<0>   # DATA XREF: D:80046540o
D:80059447                     .byte 0
D:80059448     aCsnowguardz_0: .ascii "CsnowguardZ"<0>  # DATA XREF: D:8004654Co
D:80059454     aCspicebondz_0: .ascii "CspicebondZ"<0>  # DATA XREF: D:80046558o
D:80059460     aCsuit_lf_handz_1:.ascii "Csuit_lf_handZ"<0>  # DATA XREF: D:80046564o
D:8005946F                     .byte 0
D:80059470     aCsuitbondz_0:  .ascii "CsuitbondZ"<0>   # DATA XREF: D:80046570o
D:8005947B                     .byte 0
D:8005947C     aCtechmanz_0:   .ascii "CtechmanZ"<0>    # DATA XREF: D:8004657Co
D:80059486                     .half 0
D:80059488     aCtechwomanz_0: .ascii "CtechwomanZ"<0>  # DATA XREF: D:80046588o
D:80059494     aCtimberbondz_0:.ascii "CtimberbondZ"<0>  # DATA XREF: D:80046594o
D:800594A1                     .byte 0, 0, 0
D:800594A4     aCtrevelyanz_0: .ascii "CtrevelyanZ"<0>  # DATA XREF: D:800465A0o
D:800594B0     aCtrevguardz_0: .ascii "CtrevguardZ"<0>  # DATA XREF: D:800465ACo
D:800594BC     aCvalentinz_0:  .ascii "CvalentinZ"<0>   # DATA XREF: D:800465B8o
D:800594C7                     .byte 0
D:800594C8     aCxeniaz_0:     .ascii "CxeniaZ"<0>      # DATA XREF: D:800465C4o
D:800594D0     aGak47z_0:      .ascii "Gak47Z"<0>       # DATA XREF: D:800465D0o
D:800594D7                     .byte 0
D:800594D8     aGaudiotapez_0: .ascii "GaudiotapeZ"<0>  # DATA XREF: D:800465DCo
D:800594E4     aGautoshotz_0:  .ascii "GautoshotZ"<0>   # DATA XREF: D:800465E8o
D:800594EF                     .byte 0
D:800594F0     aGblackboxz_0:  .ascii "GblackboxZ"<0>   # DATA XREF: D:800465F4o
D:800594FB                     .byte 0
D:800594FC     aGblueprintsz_0:.ascii "GblueprintsZ"<0>  # DATA XREF: D:80046600o
D:80059509                     .byte 0, 0, 0
D:8005950C     aGbombcasez_0:  .ascii "GbombcaseZ"<0>   # DATA XREF: D:8004660Co
D:80059517                     .byte 0
D:80059518     aGbombdefuserz_0:.ascii "GbombdefuserZ"<0>  # DATA XREF: D:80046618o
D:80059526                     .half 0
D:80059528     aGbriefcasez_0: .ascii "GbriefcaseZ"<0>  # DATA XREF: D:80046624o
D:80059534     aGbugz_0:       .ascii "GbugZ"<0>        # DATA XREF: D:80046630o
D:8005953A                     .half 0
D:8005953C     aGbugdetectorz_0:.ascii "GbugdetectorZ"<0>  # DATA XREF: D:8004663Co
D:8005954A                     .half 0
D:8005954C     aGbungeez_0:    .ascii "GbungeeZ"<0>     # DATA XREF: D:80046648o
D:80059555                     .byte 0, 0, 0
D:80059558     aGcameraz_0:    .ascii "GcameraZ"<0>     # DATA XREF: D:80046654o
D:80059561                     .byte 0, 0, 0
D:80059564     aGcartbluez_0:  .ascii "GcartblueZ"<0>   # DATA XREF: D:80046660o
D:8005956F                     .byte 0
D:80059570     aGcartridgez_0: .ascii "GcartridgeZ"<0>  # DATA XREF: D:8004666Co
D:8005957C     aGcartriflez_0: .ascii "GcartrifleZ"<0>  # DATA XREF: D:80046678o
D:80059588     aGcartshellz_0: .ascii "GcartshellZ"<0>  # DATA XREF: D:80046684o
D:80059594     aGcircuitboardz_0:.ascii "GcircuitboardZ"<0>  # DATA XREF: D:80046690o
D:800595A3                     .byte 0
D:800595A4     aGclipboardz_0: .ascii "GclipboardZ"<0>  # DATA XREF: D:8004669Co
D:800595B0     aGcreditcardz_0:.ascii "GcreditcardZ"<0>  # DATA XREF: D:800466A8o
D:800595BD                     .byte 0, 0, 0
D:800595C0     aGdarkglassesz_0:.ascii "GdarkglassesZ"<0>  # DATA XREF: D:800466B4o
D:800595CE                     .half 0
D:800595D0     aGdatathiefz_0: .ascii "GdatathiefZ"<0>  # DATA XREF: D:800466C0o
D:800595DC     aGdattapez_0:   .ascii "GdattapeZ"<0>    # DATA XREF: D:800466CCo
D:800595E6                     .half 0
D:800595E8     aGdoordecoderz_0:.ascii "GdoordecoderZ"<0>  # DATA XREF: D:800466D8o
D:800595F6                     .half 0
D:800595F8     aGdoorexploderz_0:.ascii "GdoorexploderZ"<0>  # DATA XREF: D:800466E4o
D:80059607                     .byte 0
D:80059608     aGdossierredz_0:.ascii "GdossierredZ"<0>  # DATA XREF: D:800466F0o
D:80059615                     .byte 0, 0, 0
D:80059618     aGdynamitez:    .ascii "GdynamiteZ"<0>   # DATA XREF: D:800466FCo
D:80059623                     .byte 0
D:80059624     aGexplosivefloppyz_0:.ascii "GexplosivefloppyZ"<0>  # DATA XREF: D:80046708o
D:80059636                     .half 0
D:80059638     aGexplosivepenz:.ascii "GexplosivepenZ"<0>  # DATA XREF: D:80046714o
D:80059647                     .byte 0
D:80059648     aGextinguisherz:.ascii "GextinguisherZ"<0>  # DATA XREF: D:80046720o
D:80059657                     .byte 0
D:80059658     aGfingergunz:   .ascii "GfingergunZ"<0>  # DATA XREF: D:8004672Co
D:80059664     aGfistz_0:      .ascii "GfistZ"<0>       # DATA XREF: D:80046738o
D:8005966B                     .byte 0
D:8005966C     aGflarepistolz_0:.ascii "GflarepistolZ"<0>  # DATA XREF: D:80046744o
D:8005967A                     .half 0
D:8005967C     aGfnp90z_0:     .ascii "Gfnp90Z"<0>      # DATA XREF: D:80046750o
D:80059684     aGgaskeyringz_0:.ascii "GgaskeyringZ"<0>  # DATA XREF: D:8004675Co
D:80059691                     .byte 0, 0, 0
D:80059694     aGgoldbarz_0:   .ascii "GgoldbarZ"<0>    # DATA XREF: D:80046768o
D:8005969E                     .half 0
D:800596A0     aGgoldeneyekeyz_0:.ascii "GgoldeneyekeyZ"<0>  # DATA XREF: D:80046774o
D:800596AF                     .byte 0
D:800596B0     aGgoldengunz_0: .ascii "GgoldengunZ"<0>  # DATA XREF: D:80046780o
D:800596BC     aGgoldwppkz_0:  .ascii "GgoldwppkZ"<0>   # DATA XREF: D:8004678Co
D:800596C7                     .byte 0
D:800596C8     aGgrenadez_0:   .ascii "GgrenadeZ"<0>    # DATA XREF: D:80046798o
D:800596D2                     .half 0
D:800596D4     aGgrenadelaunchz_0:.ascii "GgrenadelaunchZ"<0>  # DATA XREF: D:800467A4o
D:800596E4     aGheroinz_0:    .ascii "GheroinZ"<0>     # DATA XREF: D:800467B0o
D:800596ED                     .byte 0, 0, 0
D:800596F0     aGjoypadz_0:    .ascii "GjoypadZ"<0>     # DATA XREF: D:800467BCo
D:800596F9                     .byte 0, 0, 0
D:800596FC     aGkeyanalysercasez_0:.ascii "GkeyanalysercaseZ"<0>  # DATA XREF: D:800467C8o
D:8005970E                     .half 0
D:80059710     aGkeyboltz_0:   .ascii "GkeyboltZ"<0>    # DATA XREF: D:800467D4o
D:8005971A                     .half 0
D:8005971C     aGkeycardz_0:   .ascii "GkeycardZ"<0>    # DATA XREF: D:800467E0o
D:80059726                     .half 0
D:80059728     aGkeyyalez_0:   .ascii "GkeyyaleZ"<0>    # DATA XREF: D:800467ECo
D:80059732                     .half 0
D:80059734     aGknifez_0:     .ascii "GknifeZ"<0>      # DATA XREF: D:800467F8o
D:8005973C     aGlaserz_0:     .ascii "GlaserZ"<0>      # DATA XREF: D:80046804o
D:80059744     aGlectrez_0:    .ascii "GlectreZ"<0>     # DATA XREF: D:80046810o
D:8005974D                     .byte 0, 0, 0
D:80059750     aGlockexploderz_0:.ascii "GlockexploderZ"<0>  # DATA XREF: D:8004681Co
D:8005975F                     .byte 0
D:80059760     aGm16z_0:       .ascii "Gm16Z"<0>        # DATA XREF: D:80046828o
D:80059766                     .half 0
D:80059768     aGmapz_0:       .ascii "GmapZ"<0>        # DATA XREF: D:80046834o
D:8005976E                     .half 0
D:80059770     aGmicrocameraz_0:.ascii "GmicrocameraZ"<0>  # DATA XREF: D:80046840o
D:8005977E                     .half 0
D:80059780     aGmicrocodez_0: .ascii "GmicrocodeZ"<0>  # DATA XREF: D:8004684Co
D:8005978C     aGmicrofilmz_0: .ascii "GmicrofilmZ"<0>  # DATA XREF: D:80046858o
D:80059798     aGmoneyz_0:     .ascii "GmoneyZ"<0>      # DATA XREF: D:80046864o
D:800597A0     aGmp5kz_0:      .ascii "Gmp5kZ"<0>       # DATA XREF: D:80046870o
D:800597A7                     .byte 0
D:800597A8     aGmp5ksilz_0:   .ascii "Gmp5ksilZ"<0>    # DATA XREF: D:8004687Co
D:800597B2                     .half 0
D:800597B4     aGpitongunz_0:  .ascii "GpitongunZ"<0>   # DATA XREF: D:80046888o
D:800597BF                     .byte 0
D:800597C0     aGplansz_0:     .ascii "GplansZ"<0>      # DATA XREF: D:80046894o
D:800597C8     aGplastiquez_0: .ascii "GplastiqueZ"<0>  # DATA XREF: D:800468A0o
D:800597D4     aGpolarizedglassesz_0:.ascii "GpolarizedglassesZ"<0>  # DATA XREF: D:800468ACo
D:800597E7                     .byte 0
D:800597E8     aGproximityminez_0:.ascii "GproximitymineZ"<0>  # DATA XREF: D:800468B8o
D:800597F8     aGremoteminez_0:.ascii "GremotemineZ"<0>  # DATA XREF: D:800468C4o
D:80059805                     .byte 0, 0, 0
D:80059808     aGrocketlaunchz_0:.ascii "GrocketlaunchZ"<0>  # DATA XREF: D:800468D0o
D:80059817                     .byte 0
D:80059818     aGrugerz_0:     .ascii "GrugerZ"<0>      # DATA XREF: D:800468DCo
D:80059820     aGsafecrackercasez_0:.ascii "GsafecrackercaseZ"<0>  # DATA XREF: D:800468E8o
D:80059832                     .half 0
D:80059834     aGshotgunz_0:   .ascii "GshotgunZ"<0>    # DATA XREF: D:800468F4o
D:8005983E                     .half 0
D:80059840     aGsilverwppkz_0:.ascii "GsilverwppkZ"<0>  # DATA XREF: D:80046900o
D:8005984D                     .byte 0, 0, 0
D:80059850     aGskorpionz_0:  .ascii "GskorpionZ"<0>   # DATA XREF: D:8004690Co
D:8005985B                     .byte 0
D:8005985C     aGsniperriflez_0:.ascii "GsniperrifleZ"<0>  # DATA XREF: D:80046918o
D:8005986A                     .half 0
D:8005986C     aGspectrez_0:   .ascii "GspectreZ"<0>    # DATA XREF: D:80046924o
D:80059876                     .half 0
D:80059878     aGspooltapez_0: .ascii "GspooltapeZ"<0>  # DATA XREF: D:80046930o
D:80059884     aGspyfilez_0:   .ascii "GspyfileZ"<0>    # DATA XREF: D:8004693Co
D:8005988E                     .half 0
D:80059890     aGstafflistz_0: .ascii "GstafflistZ"<0>  # DATA XREF: D:80046948o
D:8005989C     aGtaserz_0:     .ascii "GtaserZ"<0>      # DATA XREF: D:80046954o
D:800598A4     aGthrowknifez_0:.ascii "GthrowknifeZ"<0>  # DATA XREF: D:80046960o
D:800598B1                     .byte 0, 0, 0
D:800598B4     aGtimedminez_0: .ascii "GtimedmineZ"<0>  # DATA XREF: D:8004696Co
D:800598C0     aGtriggerz_0:   .ascii "GtriggerZ"<0>    # DATA XREF: D:80046978o
D:800598CA                     .half 0
D:800598CC     aGtt33z_0:      .ascii "Gtt33Z"<0>       # DATA XREF: D:80046984o
D:800598D3                     .byte 0
D:800598D4     aGuziz_0:       .ascii "GuziZ"<0>        # DATA XREF: D:80046990o
D:800598DA                     .half 0
D:800598DC     aGvideotapez_0: .ascii "GvideotapeZ"<0>  # DATA XREF: D:8004699Co
D:800598E8     aGwatchcommunicatorz_0:.ascii "GwatchcommunicatorZ"<0>
D:800598E8                                              # DATA XREF: D:800469A8o
D:800598FC     aGwatchgeigercounterz_0:.ascii "GwatchgeigercounterZ"<0>
D:800598FC                                              # DATA XREF: D:800469B4o
D:80059911                     .byte 0, 0, 0
D:80059914     aGwatchidentifierz_0:.ascii "GwatchidentifierZ"<0>  # DATA XREF: D:800469C0o
D:80059926                     .half 0
D:80059928     aGwatchlaserz_0:.ascii "GwatchlaserZ"<0>  # DATA XREF: D:800469CCo
D:80059935                     .byte 0, 0, 0
D:80059938     aGwatchmagnetattractz_0:.ascii "GwatchmagnetattractZ"<0>
D:80059938                                              # DATA XREF: D:800469D8o
D:8005994D                     .byte 0, 0, 0
D:80059950     aGwatchmagnetrepelz_0:.ascii "GwatchmagnetrepelZ"<0>  # DATA XREF: D:800469E4o
D:80059963                     .byte 0
D:80059964     aGweaponcasez_0:.ascii "GweaponcaseZ"<0>  # DATA XREF: D:800469F0o
D:80059971                     .byte 0, 0, 0
D:80059974     aGwppkz_0:      .ascii "GwppkZ"<0>       # DATA XREF: D:800469FCo
D:8005997B                     .byte 0
D:8005997C     aGwppksilz_0:   .ascii "GwppksilZ"<0>    # DATA XREF: D:80046A08o
D:80059986                     .half 0
D:80059988     aGwristdartz:   .ascii "GwristdartZ"<0>  # DATA XREF: D:80046A14o
D:80059994     aPicbmz_0:      .ascii "PICBMZ"<0>       # DATA XREF: D:80046A20o
D:8005999B                     .byte 0
D:8005999C     aPicbm_nosez_0: .ascii "PICBM_noseZ"<0>  # DATA XREF: D:80046A2Co
D:800599A8     aPak47magz_0:   .ascii "Pak47magZ"<0>    # DATA XREF: D:80046A38o
D:800599B2                     .half 0
D:800599B4     aPalarm1z_0:    .ascii "Palarm1Z"<0>     # DATA XREF: D:80046A44o
D:800599BD                     .byte 0, 0, 0
D:800599C0     aPalarm2z_0:    .ascii "Palarm2Z"<0>     # DATA XREF: D:80046A50o
D:800599C9                     .byte 0, 0, 0
D:800599CC     aPammo_crate1z_0:.ascii "Pammo_crate1Z"<0>  # DATA XREF: D:80046A5Co
D:800599DA                     .half 0
D:800599DC     aPammo_crate2z_0:.ascii "Pammo_crate2Z"<0>  # DATA XREF: D:80046A68o
D:800599EA                     .half 0
D:800599EC     aPammo_crate3z_0:.ascii "Pammo_crate3Z"<0>  # DATA XREF: D:80046A74o
D:800599FA                     .half 0
D:800599FC     aPammo_crate4z_0:.ascii "Pammo_crate4Z"<0>  # DATA XREF: D:80046A80o
D:80059A0A                     .half 0
D:80059A0C     aPammo_crate5z_0:.ascii "Pammo_crate5Z"<0>  # DATA XREF: D:80046A8Co
D:80059A1A                     .half 0
D:80059A1C     aPapcz_0:       .ascii "PapcZ"<0>        # DATA XREF: D:80046A98o
D:80059A22                     .half 0
D:80059A24     aParchsecdoor1z_0:.ascii "Parchsecdoor1Z"<0>  # DATA XREF: D:80046AA4o
D:80059A33                     .byte 0
D:80059A34     aParchsecdoor2z_0:.ascii "Parchsecdoor2Z"<0>  # DATA XREF: D:80046AB0o
D:80059A43                     .byte 0
D:80059A44     aParticz_0:     .ascii "ParticZ"<0>      # DATA XREF: D:80046ABCo
D:80059A4C     aPartictrailerz_0:.ascii "PartictrailerZ"<0>  # DATA XREF: D:80046AC8o
D:80059A5B                     .byte 0
D:80059A5C     aPbarricadez_0: .ascii "PbarricadeZ"<0>  # DATA XREF: D:80046AD4o
D:80059A68     aPbin1z_0:      .ascii "Pbin1Z"<0>       # DATA XREF: D:80046AE0o
D:80059A6F                     .byte 0
D:80059A70     aPblotter1z_0:  .ascii "Pblotter1Z"<0>   # DATA XREF: D:80046AECo
D:80059A7B                     .byte 0
D:80059A7C     aPbodyarmourz_0:.ascii "PbodyarmourZ"<0>  # DATA XREF: D:80046AF8o
D:80059A89                     .byte 0, 0, 0
D:80059A8C     aPbodyarmourvestz_0:.ascii "PbodyarmourvestZ"<0>  # DATA XREF: D:80046B04o
D:80059A9D                     .byte 0, 0, 0
D:80059AA0     aPbollardz_0:   .ascii "PbollardZ"<0>    # DATA XREF: D:80046B10o
D:80059AAA                     .half 0
D:80059AAC     aPbombz_0:      .ascii "PbombZ"<0>       # DATA XREF: D:80046B1Co
D:80059AB3                     .byte 0
D:80059AB4     aPbook1z_0:     .ascii "Pbook1Z"<0>      # DATA XREF: D:80046B28o
D:80059ABC     aPbookshelf1z_0:.ascii "Pbookshelf1Z"<0>  # DATA XREF: D:80046B34o
D:80059AC9                     .byte 0, 0, 0
D:80059ACC     aPborg_cratez_0:.ascii "Pborg_crateZ"<0>  # DATA XREF: D:80046B40o
D:80059AD9                     .byte 0, 0, 0
D:80059ADC     aPboxcartridgesz_0:.ascii "PboxcartridgesZ"<0>  # DATA XREF: D:80046B4Co
D:80059AEC     aPboxes2x4z_0:  .ascii "Pboxes2x4Z"<0>   # DATA XREF: D:80046B58o
D:80059AF7                     .byte 0
D:80059AF8     aPboxes3x4z_0:  .ascii "Pboxes3x4Z"<0>   # DATA XREF: D:80046B64o
D:80059B03                     .byte 0
D:80059B04     aPboxes4x4z_0:  .ascii "Pboxes4x4Z"<0>   # DATA XREF: D:80046B70o
D:80059B0F                     .byte 0
D:80059B10     aPbrakeunitz_0: .ascii "PbrakeunitZ"<0>  # DATA XREF: D:80046B7Co
D:80059B1C     aPbridge_console1az_0:.ascii "Pbridge_console1aZ"<0>  # DATA XREF: D:80046B88o
D:80059B2F                     .byte 0
D:80059B30     aPbridge_console1bz_0:.ascii "Pbridge_console1bZ"<0>  # DATA XREF: D:80046B94o
D:80059B43                     .byte 0
D:80059B44     aPbridge_console2az_0:.ascii "Pbridge_console2aZ"<0>  # DATA XREF: D:80046BA0o
D:80059B57                     .byte 0
D:80059B58     aPbridge_console2bz_0:.ascii "Pbridge_console2bZ"<0>  # DATA XREF: D:80046BACo
D:80059B6B                     .byte 0
D:80059B6C     aPbridge_console3az_0:.ascii "Pbridge_console3aZ"<0>  # DATA XREF: D:80046BB8o
D:80059B7F                     .byte 0
D:80059B80     aPbridge_console3bz_0:.ascii "Pbridge_console3bZ"<0>  # DATA XREF: D:80046BC4o
D:80059B93                     .byte 0
D:80059B94     aPcarbmwz_0:    .ascii "PcarbmwZ"<0>     # DATA XREF: D:80046BD0o
D:80059B9D                     .byte 0, 0, 0
D:80059BA0     aPcard_box1z_0: .ascii "Pcard_box1Z"<0>  # DATA XREF: D:80046BDCo
D:80059BAC     aPcard_box2z_0: .ascii "Pcard_box2Z"<0>  # DATA XREF: D:80046BE8o
D:80059BB8     aPcard_box3z_0: .ascii "Pcard_box3Z"<0>  # DATA XREF: D:80046BF4o
D:80059BC4     aPcard_box4_lgz_0:.ascii "Pcard_box4_lgZ"<0>  # DATA XREF: D:80046C00o
D:80059BD3                     .byte 0
D:80059BD4     aPcard_box5_lgz_0:.ascii "Pcard_box5_lgZ"<0>  # DATA XREF: D:80046C0Co
D:80059BE3                     .byte 0
D:80059BE4     aPcard_box6_lgz_0:.ascii "Pcard_box6_lgZ"<0>  # DATA XREF: D:80046C18o
D:80059BF3                     .byte 0
D:80059BF4     aPcarescortz_0: .ascii "PcarescortZ"<0>  # DATA XREF: D:80046C24o
D:80059C00     aPcargolfz_0:   .ascii "PcargolfZ"<0>    # DATA XREF: D:80046C30o
D:80059C0A                     .half 0
D:80059C0C     aPcarweirdz_0:  .ascii "PcarweirdZ"<0>   # DATA XREF: D:80046C3Co
D:80059C17                     .byte 0
D:80059C18     aPcarzilz_0:    .ascii "PcarzilZ"<0>     # DATA XREF: D:80046C48o
D:80059C21                     .byte 0, 0, 0
D:80059C24     aPcctvz_0:      .ascii "PcctvZ"<0>       # DATA XREF: D:80046C54o
D:80059C2B                     .byte 0
D:80059C2C     aPchraudiotapez_0:.ascii "PchraudiotapeZ"<0>  # DATA XREF: D:80046C60o
D:80059C3B                     .byte 0
D:80059C3C     aPchrautoshotz_0:.ascii "PchrautoshotZ"<0>  # DATA XREF: D:80046C6Co
D:80059C4A                     .half 0
D:80059C4C     aPchrblackboxz_0:.ascii "PchrblackboxZ"<0>  # DATA XREF: D:80046C78o
D:80059C5A                     .half 0
D:80059C5C     aPchrblueprintsz_0:.ascii "PchrblueprintsZ"<0>  # DATA XREF: D:80046C84o
D:80059C6C     aPchrbombcasez_0:.ascii "PchrbombcaseZ"<0>  # DATA XREF: D:80046C90o
D:80059C7A                     .half 0
D:80059C7C     aPchrbombdefuserz_0:.ascii "PchrbombdefuserZ"<0>  # DATA XREF: D:80046C9Co
D:80059C8D                     .byte 0, 0, 0
D:80059C90     aPchrbriefcasez_0:.ascii "PchrbriefcaseZ"<0>  # DATA XREF: D:80046CA8o
D:80059C9F                     .byte 0
D:80059CA0     aPchrbugz_0:    .ascii "PchrbugZ"<0>     # DATA XREF: D:80046CB4o
D:80059CA9                     .byte 0, 0, 0
D:80059CAC     aPchrbugdetectorz_0:.ascii "PchrbugdetectorZ"<0>  # DATA XREF: D:80046CC0o
D:80059CBD                     .byte 0, 0, 0
D:80059CC0     aPchrbungeez_0: .ascii "PchrbungeeZ"<0>  # DATA XREF: D:80046CCCo
D:80059CCC     aPchrcameraz_0: .ascii "PchrcameraZ"<0>  # DATA XREF: D:80046CD8o
D:80059CD8     aPchrcircuitboardz_0:.ascii "PchrcircuitboardZ"<0>  # DATA XREF: D:80046CE4o
D:80059CEA                     .half 0
D:80059CEC     aPchrclipboardz_0:.ascii "PchrclipboardZ"<0>  # DATA XREF: D:80046CF0o
D:80059CFB                     .byte 0
D:80059CFC     aPchrcreditcardz_0:.ascii "PchrcreditcardZ"<0>  # DATA XREF: D:80046CFCo
D:80059D0C     aPchrdarkglassesz_0:.ascii "PchrdarkglassesZ"<0>  # DATA XREF: D:80046D08o
D:80059D1D                     .byte 0, 0, 0
D:80059D20     aPchrdatathiefz_0:.ascii "PchrdatathiefZ"<0>  # DATA XREF: D:80046D14o
D:80059D2F                     .byte 0
D:80059D30     aPchrdattapez_0:.ascii "PchrdattapeZ"<0>  # DATA XREF: D:80046D20o
D:80059D3D                     .byte 0, 0, 0
D:80059D40     aPchrdoordecoderz_0:.ascii "PchrdoordecoderZ"<0>  # DATA XREF: D:80046D2Co
D:80059D51                     .byte 0, 0, 0
D:80059D54     aPchrdoorexploderz_0:.ascii "PchrdoorexploderZ"<0>  # DATA XREF: D:80046D38o
D:80059D66                     .half 0
D:80059D68     aPchrdossierredz_0:.ascii "PchrdossierredZ"<0>  # DATA XREF: D:80046D44o
D:80059D78     aPchrdynamitez_0:.ascii "PchrdynamiteZ"<0>  # DATA XREF: D:80046D50o
D:80059D86                     .half 0
D:80059D88     aPchrexplosivepenz_0:.ascii "PchrexplosivepenZ"<0>  # DATA XREF: D:80046D5Co
D:80059D9A                     .half 0
D:80059D9C     aPchrextinguisherz_0:.ascii "PchrextinguisherZ"<0>  # DATA XREF: D:80046D68o
D:80059DAE                     .half 0
D:80059DB0     aPchrfingergunz_0:.ascii "PchrfingergunZ"<0>  # DATA XREF: D:80046D74o
D:80059DBF                     .byte 0
D:80059DC0     aPchrflarepistolz_0:.ascii "PchrflarepistolZ"<0>  # DATA XREF: D:80046D80o
D:80059DD1                     .byte 0, 0, 0
D:80059DD4     aPchrfnp90z_0:  .ascii "Pchrfnp90Z"<0>   # DATA XREF: D:80046D8Co
D:80059DDF                     .byte 0
D:80059DE0     aPchrgaskeyringz_0:.ascii "PchrgaskeyringZ"<0>  # DATA XREF: D:80046D98o
D:80059DF0     aPchrgoldbarz_0:.ascii "PchrgoldbarZ"<0>  # DATA XREF: D:80046DA4o
D:80059DFD                     .byte 0, 0, 0
D:80059E00     aPchrgoldenz_0: .ascii "PchrgoldenZ"<0>  # DATA XREF: D:80046DB0o
D:80059E0C     aPchrgoldeneyekeyz_0:.ascii "PchrgoldeneyekeyZ"<0>  # DATA XREF: D:80046DBCo
D:80059E1E                     .half 0
D:80059E20     aPchrgoldwppkz_0:.ascii "PchrgoldwppkZ"<0>  # DATA XREF: D:80046DC8o
D:80059E2E                     .half 0
D:80059E30     aPchrgrenadez_0:.ascii "PchrgrenadeZ"<0>  # DATA XREF: D:80046DD4o
D:80059E3D                     .byte 0, 0, 0
D:80059E40     aPchrgrenadelaunchz_0:.ascii "PchrgrenadelaunchZ"<0>  # DATA XREF: D:80046DE0o
D:80059E53                     .byte 0
D:80059E54     aPchrgrenaderoundz_0:.ascii "PchrgrenaderoundZ"<0>  # DATA XREF: D:80046DECo
D:80059E66                     .half 0
D:80059E68     aPchrheroinz_0: .ascii "PchrheroinZ"<0>  # DATA XREF: D:80046DF8o
D:80059E74     aPchrkalashz_0: .ascii "PchrkalashZ"<0>  # DATA XREF: D:80046E04o
D:80059E80     aPchrkeyanalysercasez_0:.ascii "PchrkeyanalysercaseZ"<0>
D:80059E80                                              # DATA XREF: D:80046E10o
D:80059E95                     .byte 0, 0, 0
D:80059E98     aPchrkeyboltz_0:.ascii "PchrkeyboltZ"<0>  # DATA XREF: D:80046E1Co
D:80059EA5                     .byte 0, 0, 0
D:80059EA8     aPchrkeyyalez_0:.ascii "PchrkeyyaleZ"<0>  # DATA XREF: D:80046E28o
D:80059EB5                     .byte 0, 0, 0
D:80059EB8     aPchrknifez_0:  .ascii "PchrknifeZ"<0>   # DATA XREF: D:80046E34o
D:80059EC3                     .byte 0
D:80059EC4     aPchrlaserz_0:  .ascii "PchrlaserZ"<0>   # DATA XREF: D:80046E40o
D:80059ECF                     .byte 0
D:80059ED0     aPchrlectrez_0: .ascii "PchrlectreZ"<0>  # DATA XREF: D:80046E4Co
D:80059EDC     aPchrlockexploderz_0:.ascii "PchrlockexploderZ"<0>  # DATA XREF: D:80046E58o
D:80059EEE                     .half 0
D:80059EF0     aPchrm16z_0:    .ascii "Pchrm16Z"<0>     # DATA XREF: D:80046E64o
D:80059EF9                     .byte 0, 0, 0
D:80059EFC     aPchrmapz_0:    .ascii "PchrmapZ"<0>     # DATA XREF: D:80046E70o
D:80059F05                     .byte 0, 0, 0
D:80059F08     aPchrmicrocameraz_0:.ascii "PchrmicrocameraZ"<0>  # DATA XREF: D:80046E7Co
D:80059F19                     .byte 0, 0, 0
D:80059F1C     aPchrmicrocodez_0:.ascii "PchrmicrocodeZ"<0>  # DATA XREF: D:80046E88o
D:80059F2B                     .byte 0
D:80059F2C     aPchrmicrofilmz_0:.ascii "PchrmicrofilmZ"<0>  # DATA XREF: D:80046E94o
D:80059F3B                     .byte 0
D:80059F3C     aPchrmoneyz_0:  .ascii "PchrmoneyZ"<0>   # DATA XREF: D:80046EA0o
D:80059F47                     .byte 0
D:80059F48     aPchrmp5kz_0:   .ascii "Pchrmp5kZ"<0>    # DATA XREF: D:80046EACo
D:80059F52                     .half 0
D:80059F54     aPchrmp5ksilz_0:.ascii "Pchrmp5ksilZ"<0>  # DATA XREF: D:80046EB8o
D:80059F61                     .byte 0, 0, 0
D:80059F64     aPchrpitongunz_0:.ascii "PchrpitongunZ"<0>  # DATA XREF: D:80046EC4o
D:80059F72                     .half 0
D:80059F74     aPchrplansz_0:  .ascii "PchrplansZ"<0>   # DATA XREF: D:80046ED0o
D:80059F7F                     .byte 0
D:80059F80     aPchrplastiquez_0:.ascii "PchrplastiqueZ"<0>  # DATA XREF: D:80046EDCo
D:80059F8F                     .byte 0
D:80059F90     aPchrpolarizedglassesz_0:.ascii "PchrpolarizedglassesZ"<0>
D:80059F90                                              # DATA XREF: D:80046EE8o
D:80059FA6                     .half 0
D:80059FA8     aPchrproximityminez_0:.ascii "PchrproximitymineZ"<0>  # DATA XREF: D:80046EF4o
D:80059FBB                     .byte 0
D:80059FBC     aPchrremoteminez_0:.ascii "PchrremotemineZ"<0>  # DATA XREF: D:80046F00o
D:80059FCC     aPchrrocketz_0: .ascii "PchrrocketZ"<0>  # DATA XREF: D:80046F0Co
D:80059FD8     aPchrrocketlaunchz_0:.ascii "PchrrocketlaunchZ"<0>  # DATA XREF: D:80046F18o
D:80059FEA                     .half 0
D:80059FEC     aPchrrugerz_0:  .ascii "PchrrugerZ"<0>   # DATA XREF: D:80046F24o
D:80059FF7                     .byte 0
D:80059FF8     aPchrsafecrackercasez_0:.ascii "PchrsafecrackercaseZ"<0>
D:80059FF8                                              # DATA XREF: D:80046F30o
D:8005A00D                     .byte 0, 0, 0
D:8005A010     aPchrshotgunz_0:.ascii "PchrshotgunZ"<0>  # DATA XREF: D:80046F3Co
D:8005A01D                     .byte 0, 0, 0
D:8005A020     aPchrsilverwppkz_0:.ascii "PchrsilverwppkZ"<0>  # DATA XREF: D:80046F48o
D:8005A030     aPchrskorpionz_0:.ascii "PchrskorpionZ"<0>  # DATA XREF: D:80046F54o
D:8005A03E                     .half 0
D:8005A040     aPchrsniperriflez_0:.ascii "PchrsniperrifleZ"<0>  # DATA XREF: D:80046F60o
D:8005A051                     .byte 0, 0, 0
D:8005A054     aPchrspectrez_0:.ascii "PchrspectreZ"<0>  # DATA XREF: D:80046F6Co
D:8005A061                     .byte 0, 0, 0
D:8005A064     aPchrspooltapez_0:.ascii "PchrspooltapeZ"<0>  # DATA XREF: D:80046F78o
D:8005A073                     .byte 0
D:8005A074     aPchrspyfilez_0:.ascii "PchrspyfileZ"<0>  # DATA XREF: D:80046F84o
D:8005A081                     .byte 0, 0, 0
D:8005A084     aPchrstafflistz_0:.ascii "PchrstafflistZ"<0>  # DATA XREF: D:80046F90o
D:8005A093                     .byte 0
D:8005A094     aPchrtesttubez_0:.ascii "PchrtesttubeZ"<0>  # DATA XREF: D:80046F9Co
D:8005A0A2                     .half 0
D:8005A0A4     aPchrthrowknifez_0:.ascii "PchrthrowknifeZ"<0>  # DATA XREF: D:80046FA8o
D:8005A0B4     aPchrtimedminez_0:.ascii "PchrtimedmineZ"<0>  # DATA XREF: D:80046FB4o
D:8005A0C3                     .byte 0
D:8005A0C4     aPchrtt33z_0:   .ascii "Pchrtt33Z"<0>    # DATA XREF: D:80046FC0o
D:8005A0CE                     .half 0
D:8005A0D0     aPchruziz_0:    .ascii "PchruziZ"<0>     # DATA XREF: D:80046FCCo
D:8005A0D9                     .byte 0, 0, 0
D:8005A0DC     aPchrvideotapez_0:.ascii "PchrvideotapeZ"<0>  # DATA XREF: D:80046FD8o
D:8005A0EB                     .byte 0
D:8005A0EC     aPchrweaponcasez_0:.ascii "PchrweaponcaseZ"<0>  # DATA XREF: D:80046FE4o
D:8005A0FC     aPchrwppkz_0:   .ascii "PchrwppkZ"<0>    # DATA XREF: D:80046FF0o
D:8005A106                     .half 0
D:8005A108     aPchrwppksilz_0:.ascii "PchrwppksilZ"<0>  # DATA XREF: D:80046FFCo
D:8005A115                     .byte 0, 0, 0
D:8005A118     aPchrwristdartz_0:.ascii "PchrwristdartZ"<0>  # DATA XREF: D:80047008o
D:8005A127                     .byte 0
D:8005A128     aPconsole1z_0:  .ascii "Pconsole1Z"<0>   # DATA XREF: D:80047014o
D:8005A133                     .byte 0
D:8005A134     aPconsole2z_0:  .ascii "Pconsole2Z"<0>   # DATA XREF: D:80047020o
D:8005A13F                     .byte 0
D:8005A140     aPconsole3z_0:  .ascii "Pconsole3Z"<0>   # DATA XREF: D:8004702Co
D:8005A14B                     .byte 0
D:8005A14C     aPconsole_sev2az_0:.ascii "Pconsole_sev2aZ"<0>  # DATA XREF: D:80047038o
D:8005A15C     aPconsole_sev2bz_0:.ascii "Pconsole_sev2bZ"<0>  # DATA XREF: D:80047044o
D:8005A16C     aPconsole_sev2cz_0:.ascii "Pconsole_sev2cZ"<0>  # DATA XREF: D:80047050o
D:8005A17C     aPconsole_sev2dz_0:.ascii "Pconsole_sev2dZ"<0>  # DATA XREF: D:8004705Co
D:8005A18C     aPconsole_sev_geaz_0:.ascii "Pconsole_sev_GEaZ"<0>  # DATA XREF: D:80047068o
D:8005A19E                     .half 0
D:8005A1A0     aPconsole_sev_gebz_0:.ascii "Pconsole_sev_GEbZ"<0>  # DATA XREF: D:80047074o
D:8005A1B2                     .half 0
D:8005A1B4     aPconsole_sevaz_0:.ascii "Pconsole_sevaZ"<0>  # DATA XREF: D:80047080o
D:8005A1C3                     .byte 0
D:8005A1C4     aPconsole_sevbz_0:.ascii "Pconsole_sevbZ"<0>  # DATA XREF: D:8004708Co
D:8005A1D3                     .byte 0
D:8005A1D4     aPconsole_sevcz_0:.ascii "Pconsole_sevcZ"<0>  # DATA XREF: D:80047098o
D:8005A1E3                     .byte 0
D:8005A1E4     aPconsole_sevdz_0:.ascii "Pconsole_sevdZ"<0>  # DATA XREF: D:800470A4o
D:8005A1F3                     .byte 0
D:8005A1F4     aPcryptdoor1az_0:.ascii "Pcryptdoor1aZ"<0>  # DATA XREF: D:800470B0o
D:8005A202                     .half 0
D:8005A204     aPcryptdoor1bz_0:.ascii "Pcryptdoor1bZ"<0>  # DATA XREF: D:800470BCo
D:8005A212                     .half 0
D:8005A214     aPcryptdoor2az_0:.ascii "Pcryptdoor2aZ"<0>  # DATA XREF: D:800470C8o
D:8005A222                     .half 0
D:8005A224     aPcryptdoor2bz_0:.ascii "Pcryptdoor2bZ"<0>  # DATA XREF: D:800470D4o
D:8005A232                     .half 0
D:8005A234     aPcryptdoor3z_0:.ascii "Pcryptdoor3Z"<0>  # DATA XREF: D:800470E0o
D:8005A241                     .byte 0, 0, 0
D:8005A244     aPcryptdoor4z_0:.ascii "Pcryptdoor4Z"<0>  # DATA XREF: D:800470ECo
D:8005A251                     .byte 0, 0, 0
D:8005A254     aPdamchaindoorz_0:.ascii "PdamchaindoorZ"<0>  # DATA XREF: D:800470F8o
D:8005A263                     .byte 0
D:8005A264     aPdamgatedoorz_0:.ascii "PdamgatedoorZ"<0>  # DATA XREF: D:80047104o
D:8005A272                     .half 0
D:8005A274     aPdamtundoorz_0:.ascii "PdamtundoorZ"<0>  # DATA XREF: D:80047110o
D:8005A281                     .byte 0, 0, 0
D:8005A284     aPdepot_door_steelz_0:.ascii "Pdepot_door_steelZ"<0>  # DATA XREF: D:8004711Co
D:8005A297                     .byte 0
D:8005A298     aPdepot_gate_entryz_0:.ascii "Pdepot_gate_entryZ"<0>  # DATA XREF: D:80047128o
D:8005A2AB                     .byte 0
D:8005A2AC     aPdesk1z_0:     .ascii "Pdesk1Z"<0>      # DATA XREF: D:80047134o
D:8005A2B4     aPdesk2z_0:     .ascii "Pdesk2Z"<0>      # DATA XREF: D:80047140o
D:8005A2BC     aPdesk_arecibo1z_0:.ascii "Pdesk_arecibo1Z"<0>  # DATA XREF: D:8004714Co
D:8005A2CC     aPdesk_lamp2z_0:.ascii "Pdesk_lamp2Z"<0>  # DATA XREF: D:80047158o
D:8005A2D9                     .byte 0, 0, 0
D:8005A2DC     aPdest_enginez_0:.ascii "Pdest_engineZ"<0>  # DATA XREF: D:80047164o
D:8005A2EA                     .half 0
D:8005A2EC     aPdest_exocetz_0:.ascii "Pdest_exocetZ"<0>  # DATA XREF: D:80047170o
D:8005A2FA                     .half 0
D:8005A2FC     aPdest_gunz_0:  .ascii "Pdest_gunZ"<0>   # DATA XREF: D:8004717Co
D:8005A307                     .byte 0
D:8005A308     aPdest_harpoonz_0:.ascii "Pdest_harpoonZ"<0>  # DATA XREF: D:80047188o
D:8005A317                     .byte 0
D:8005A318     aPdest_seawolfz_0:.ascii "Pdest_seawolfZ"<0>  # DATA XREF: D:80047194o
D:8005A327                     .byte 0
D:8005A328     aPdisc_readerz_0:.ascii "Pdisc_readerZ"<0>  # DATA XREF: D:800471A0o
D:8005A336                     .half 0
D:8005A338     aPdisk_drive1z_0:.ascii "Pdisk_drive1Z"<0>  # DATA XREF: D:800471ACo
D:8005A346                     .half 0
D:8005A348     aPdoor_azt_chairz_0:.ascii "Pdoor_azt_chairZ"<0>  # DATA XREF: D:800471B8o
D:8005A359                     .byte 0, 0, 0
D:8005A35C     aPdoor_azt_deskz_0:.ascii "Pdoor_azt_deskZ"<0>  # DATA XREF: D:800471C4o
D:8005A36C     aPdoor_azt_desk_topz_0:.ascii "Pdoor_azt_desk_topZ"<0>
D:8005A36C                                              # DATA XREF: D:800471D0o
D:8005A380     aPdoor_aztecz_0:.ascii "Pdoor_aztecZ"<0>  # DATA XREF: D:800471DCo
D:8005A38D                     .byte 0, 0, 0
D:8005A390     aPdoor_dest1z_0:.ascii "Pdoor_dest1Z"<0>  # DATA XREF: D:800471E8o
D:8005A39D                     .byte 0, 0, 0
D:8005A3A0     aPdoor_dest2z_0:.ascii "Pdoor_dest2Z"<0>  # DATA XREF: D:800471F4o
D:8005A3AD                     .byte 0, 0, 0
D:8005A3B0     aPdoor_eyelidz_0:.ascii "Pdoor_eyelidZ"<0>  # DATA XREF: D:80047200o
D:8005A3BE                     .half 0
D:8005A3C0     aPdoor_irisz_0: .ascii "Pdoor_irisZ"<0>  # DATA XREF: D:8004720Co
D:8005A3CC     aPdoor_mfz_0:   .ascii "Pdoor_mfZ"<0>    # DATA XREF: D:80047218o
D:8005A3D6                     .half 0
D:8005A3D8     aPdoor_roller1z_0:.ascii "Pdoor_roller1Z"<0>  # DATA XREF: D:80047224o
D:8005A3E7                     .byte 0
D:8005A3E8     aPdoor_roller2z_0:.ascii "Pdoor_roller2Z"<0>  # DATA XREF: D:80047230o
D:8005A3F7                     .byte 0
D:8005A3F8     aPdoor_roller3z_0:.ascii "Pdoor_roller3Z"<0>  # DATA XREF: D:8004723Co
D:8005A407                     .byte 0
D:8005A408     aPdoor_roller4z_0:.ascii "Pdoor_roller4Z"<0>  # DATA XREF: D:80047248o
D:8005A417                     .byte 0
D:8005A418     aPdoor_rollertrainz_0:.ascii "Pdoor_rollertrainZ"<0>  # DATA XREF: D:80047254o
D:8005A42B                     .byte 0
D:8005A42C     aPdoor_st_arec1z_0:.ascii "Pdoor_st_arec1Z"<0>  # DATA XREF: D:80047260o
D:8005A43C     aPdoor_st_arec2z_0:.ascii "Pdoor_st_arec2Z"<0>  # DATA XREF: D:8004726Co
D:8005A44C     aPdoor_winz_0:  .ascii "Pdoor_winZ"<0>   # DATA XREF: D:80047278o
D:8005A457                     .byte 0
D:8005A458     aPdoorconsolez_0:.ascii "PdoorconsoleZ"<0>  # DATA XREF: D:80047284o
D:8005A466                     .half 0
D:8005A468     aPdoorpanelz_0: .ascii "PdoorpanelZ"<0>  # DATA XREF: D:80047290o
D:8005A474     aPdoorprison1z_0:.ascii "Pdoorprison1Z"<0>  # DATA XREF: D:8004729Co
D:8005A482                     .half 0
D:8005A484     aPdoorstatgatez_0:.ascii "PdoorstatgateZ"<0>  # DATA XREF: D:800472A8o
D:8005A493                     .byte 0
D:8005A494     aPexplosionbitz_0:.ascii "PexplosionbitZ"<0>  # DATA XREF: D:800472B4o
D:8005A4A3                     .byte 0
D:8005A4A4     aPfiling_cabinet1z_0:.ascii "Pfiling_cabinet1Z"<0>  # DATA XREF: D:800472C0o
D:8005A4B6                     .half 0
D:8005A4B8     aPflagz_0:      .ascii "PflagZ"<0>       # DATA XREF: D:800472CCo
D:8005A4BF                     .byte 0
D:8005A4C0     aPfloppyz_0:    .ascii "PfloppyZ"<0>     # DATA XREF: D:800472D8o
D:8005A4C9                     .byte 0, 0, 0
D:8005A4CC     aPfnp90magz_0:  .ascii "Pfnp90magZ"<0>   # DATA XREF: D:800472E4o
D:8005A4D7                     .byte 0
D:8005A4D8     aPgas_plant_met1_do1z_0:.ascii "Pgas_plant_met1_do1Z"<0>
D:8005A4D8                                              # DATA XREF: D:800472F0o
D:8005A4ED                     .byte 0, 0, 0
D:8005A4F0     aPgas_plant_sw2_do1z_0:.ascii "Pgas_plant_sw2_do1Z"<0>
D:8005A4F0                                              # DATA XREF: D:800472FCo
D:8005A504     aPgas_plant_sw3_do1z_0:.ascii "Pgas_plant_sw3_do1Z"<0>
D:8005A504                                              # DATA XREF: D:80047308o
D:8005A518     aPgas_plant_sw4_do1z_0:.ascii "Pgas_plant_sw4_do1Z"<0>
D:8005A518                                              # DATA XREF: D:80047314o
D:8005A52C     aPgas_plant_sw_do1z_0:.ascii "Pgas_plant_sw_do1Z"<0>  # DATA XREF: D:80047320o
D:8005A53F                     .byte 0
D:8005A540     aPgas_plant_wc_cub1z_0:.ascii "Pgas_plant_wc_cub1Z"<0>
D:8005A540                                              # DATA XREF: D:8004732Co
D:8005A554     aPgasbarrelz_0: .ascii "PgasbarrelZ"<0>  # DATA XREF: D:80047338o
D:8005A560     aPgasbarrelsz_0:.ascii "PgasbarrelsZ"<0>  # DATA XREF: D:80047344o
D:8005A56D                     .byte 0, 0, 0
D:8005A570     aPgasplant_clear_doorz_0:.ascii "Pgasplant_clear_doorZ"<0>
D:8005A570                                              # DATA XREF: D:80047350o
D:8005A586                     .half 0
D:8005A588     aPgastankz_0:   .ascii "PgastankZ"<0>    # DATA XREF: D:8004735Co
D:8005A592                     .half 0
D:8005A594     aPglassware1z_0:.ascii "Pglassware1Z"<0>  # DATA XREF: D:80047368o
D:8005A5A1                     .byte 0, 0, 0
D:8005A5A4     aPglassware2z_0:.ascii "Pglassware2Z"<0>  # DATA XREF: D:80047374o
D:8005A5B1                     .byte 0, 0, 0
D:8005A5B4     aPglassware3z_0:.ascii "Pglassware3Z"<0>  # DATA XREF: D:80047380o
D:8005A5C1                     .byte 0, 0, 0
D:8005A5C4     aPglassware4z_0:.ascii "Pglassware4Z"<0>  # DATA XREF: D:8004738Co
D:8005A5D1                     .byte 0, 0, 0
D:8005A5D4     aPgoldeneyelogoz_0:.ascii "PgoldeneyelogoZ"<0>  # DATA XREF: D:80047398o
D:8005A5E4     aPgoldenshellsz_0:.ascii "PgoldenshellsZ"<0>  # DATA XREF: D:800473A4o
D:8005A5F3                     .byte 0
D:8005A5F4     aPgroundgunz_0: .ascii "PgroundgunZ"<0>  # DATA XREF: D:800473B0o
D:8005A600     aPgun_runway1z_0:.ascii "Pgun_runway1Z"<0>  # DATA XREF: D:800473BCo
D:8005A60E                     .half 0
D:8005A610     aPhatberetz_0:  .ascii "PhatberetZ"<0>   # DATA XREF: D:800473C8o
D:8005A61B                     .byte 0
D:8005A61C     aPhatberetbluez_0:.ascii "PhatberetblueZ"<0>  # DATA XREF: D:800473D4o
D:8005A62B                     .byte 0
D:8005A62C     aPhatberetredz_0:.ascii "PhatberetredZ"<0>  # DATA XREF: D:800473E0o
D:8005A63A                     .half 0
D:8005A63C     aPhatchboltz_0: .ascii "PhatchboltZ"<0>  # DATA XREF: D:800473ECo
D:8005A648     aPhatchdoorz_0: .ascii "PhatchdoorZ"<0>  # DATA XREF: D:800473F8o
D:8005A654     aPhatchsevxz_0: .ascii "PhatchsevxZ"<0>  # DATA XREF: D:80047404o
D:8005A660     aPhatfurryz_0:  .ascii "PhatfurryZ"<0>   # DATA XREF: D:80047410o
D:8005A66B                     .byte 0
D:8005A66C     aPhatfurryblackz_0:.ascii "PhatfurryblackZ"<0>  # DATA XREF: D:8004741Co
D:8005A67C     aPhatfurrybrownz_0:.ascii "PhatfurrybrownZ"<0>  # DATA XREF: D:80047428o
D:8005A68C     aPhathelmetz_0: .ascii "PhathelmetZ"<0>  # DATA XREF: D:80047434o
D:8005A698     aPhathelmetgreyz_0:.ascii "PhathelmetgreyZ"<0>  # DATA XREF: D:80047440o
D:8005A6A8     aPhatmoonz_0:   .ascii "PhatmoonZ"<0>    # DATA XREF: D:8004744Co
D:8005A6B2                     .half 0
D:8005A6B4     aPhatpeakedz_0: .ascii "PhatpeakedZ"<0>  # DATA XREF: D:80047458o
D:8005A6C0     aPhattbirdz_0:  .ascii "PhattbirdZ"<0>   # DATA XREF: D:80047464o
D:8005A6CB                     .byte 0
D:8005A6CC     aPhattbirdbrownz_0:.ascii "PhattbirdbrownZ"<0>  # DATA XREF: D:80047470o
D:8005A6DC     aPhelicopterz_0:.ascii "PhelicopterZ"<0>  # DATA XREF: D:8004747Co
D:8005A6E9                     .byte 0, 0, 0
D:8005A6EC     aPhindz_0:      .ascii "PhindZ"<0>       # DATA XREF: D:80047488o
D:8005A6F3                     .byte 0
D:8005A6F4     aPjeepz_0:      .ascii "PjeepZ"<0>       # DATA XREF: D:80047494o
D:8005A6FB                     .byte 0
D:8005A6FC     aPjerry_can1z_0:.ascii "Pjerry_can1Z"<0>  # DATA XREF: D:800474A0o
D:8005A709                     .byte 0, 0, 0
D:8005A70C     aPjungle3_treez_0:.ascii "Pjungle3_treeZ"<0>  # DATA XREF: D:800474ACo
D:8005A71B                     .byte 0
D:8005A71C     aPjungle5_treez_0:.ascii "Pjungle5_treeZ"<0>  # DATA XREF: D:800474B8o
D:8005A72B                     .byte 0
D:8005A72C     aPkey_holderz_0:.ascii "Pkey_holderZ"<0>  # DATA XREF: D:800474C4o
D:8005A739                     .byte 0, 0, 0
D:8005A73C     aPkeyboard1z_0: .ascii "Pkeyboard1Z"<0>  # DATA XREF: D:800474D0o
D:8005A748     aPkit_units1z_0:.ascii "Pkit_units1Z"<0>  # DATA XREF: D:800474DCo
D:8005A755                     .byte 0, 0, 0
D:8005A758     aPlabbenchz_0:  .ascii "PlabbenchZ"<0>   # DATA XREF: D:800474E8o
D:8005A763                     .byte 0
D:8005A764     aPlandminez_0:  .ascii "PlandmineZ"<0>   # DATA XREF: D:800474F4o
D:8005A76F                     .byte 0
D:8005A770     aPlegalpagez_0: .ascii "PlegalpageZ"<0>  # DATA XREF: D:80047500o
D:8005A77C     aPletter_tray1z_0:.ascii "Pletter_tray1Z"<0>  # DATA XREF: D:8004750Co
D:8005A78B                     .byte 0
D:8005A78C     aPlocker3z_0:   .ascii "Plocker3Z"<0>    # DATA XREF: D:80047518o
D:8005A796                     .half 0
D:8005A798     aPlocker4z_0:   .ascii "Plocker4Z"<0>    # DATA XREF: D:80047524o
D:8005A7A2                     .half 0
D:8005A7A4     aPm16magz_0:    .ascii "Pm16magZ"<0>     # DATA XREF: D:80047530o
D:8005A7AD                     .byte 0, 0, 0
D:8005A7B0     aPmagnumshellsz_0:.ascii "PmagnumshellsZ"<0>  # DATA XREF: D:8004753Co
D:8005A7BF                     .byte 0
D:8005A7C0     aPmainframe1z_0:.ascii "Pmainframe1Z"<0>  # DATA XREF: D:80047548o
D:8005A7CD                     .byte 0, 0, 0
D:8005A7D0     aPmainframe2z_0:.ascii "Pmainframe2Z"<0>  # DATA XREF: D:80047554o
D:8005A7DD                     .byte 0, 0, 0
D:8005A7E0     aPmetal_chair1z_0:.ascii "Pmetal_chair1Z"<0>  # DATA XREF: D:80047560o
D:8005A7EF                     .byte 0
D:8005A7F0     aPmetal_crate1z_0:.ascii "Pmetal_crate1Z"<0>  # DATA XREF: D:8004756Co
D:8005A7FF                     .byte 0
D:8005A800     aPmetal_crate2z_0:.ascii "Pmetal_crate2Z"<0>  # DATA XREF: D:80047578o
D:8005A80F                     .byte 0
D:8005A810     aPmetal_crate3z_0:.ascii "Pmetal_crate3Z"<0>  # DATA XREF: D:80047584o
D:8005A81F                     .byte 0
D:8005A820     aPmetal_crate4z_0:.ascii "Pmetal_crate4Z"<0>  # DATA XREF: D:80047590o
D:8005A82F                     .byte 0
D:8005A830     aPmilcopterz_0: .ascii "PmilcopterZ"<0>  # DATA XREF: D:8004759Co
D:8005A83C     aPmiltruckz_0:  .ascii "PmiltruckZ"<0>   # DATA XREF: D:800475A8o
D:8005A847                     .byte 0
D:8005A848     aPmissile_rack2z_0:.ascii "Pmissile_rack2Z"<0>  # DATA XREF: D:800475B4o
D:8005A858     aPmissile_rackz_0:.ascii "Pmissile_rackZ"<0>  # DATA XREF: D:800475C0o
D:8005A867                     .byte 0
D:8005A868     aPmodemboxz_0:  .ascii "PmodemboxZ"<0>   # DATA XREF: D:800475CCo
D:8005A873                     .byte 0
D:8005A874     aPmotorbikez_0: .ascii "PmotorbikeZ"<0>  # DATA XREF: D:800475D8o
D:8005A880     aPmp5kmagz_0:   .ascii "Pmp5kmagZ"<0>    # DATA XREF: D:800475E4o
D:8005A88A                     .half 0
D:8005A88C     aPnintendologoz_0:.ascii "PnintendologoZ"<0>  # DATA XREF: D:800475F0o
D:8005A89B                     .byte 0
D:8005A89C     aPoil_drum1z_0: .ascii "Poil_drum1Z"<0>  # DATA XREF: D:800475FCo
D:8005A8A8     aPoil_drum2z_0: .ascii "Poil_drum2Z"<0>  # DATA XREF: D:80047608o
D:8005A8B4     aPoil_drum3z_0: .ascii "Poil_drum3Z"<0>  # DATA XREF: D:80047614o
D:8005A8C0     aPoil_drum5z_0: .ascii "Poil_drum5Z"<0>  # DATA XREF: D:80047620o
D:8005A8CC     aPoil_drum6z_0: .ascii "Poil_drum6Z"<0>  # DATA XREF: D:8004762Co
D:8005A8D8     aPoil_drum7z_0: .ascii "Poil_drum7Z"<0>  # DATA XREF: D:80047638o
D:8005A8E4     aPpadlockz_0:   .ascii "PpadlockZ"<0>    # DATA XREF: D:80047644o
D:8005A8EE                     .half 0
D:8005A8F0     aPpalmz_0:      .ascii "PpalmZ"<0>       # DATA XREF: D:80047650o
D:8005A8F7                     .byte 0
D:8005A8F8     aPpalmtreez_0:  .ascii "PpalmtreeZ"<0>   # DATA XREF: D:8004765Co
D:8005A903                     .byte 0
D:8005A904     aPphone1z_0:    .ascii "Pphone1Z"<0>     # DATA XREF: D:80047668o
D:8005A90D                     .byte 0, 0, 0
D:8005A910     aPplanez_0:     .ascii "PplaneZ"<0>      # DATA XREF: D:80047674o
D:8005A918     aPplant11z_0:   .ascii "Pplant11Z"<0>    # DATA XREF: D:80047680o
D:8005A922                     .half 0
D:8005A924     aPplant1z_0:    .ascii "Pplant1Z"<0>     # DATA XREF: D:8004768Co
D:8005A92D                     .byte 0, 0, 0
D:8005A930     aPplant2z_0:    .ascii "Pplant2Z"<0>     # DATA XREF: D:80047698o
D:8005A939                     .byte 0, 0, 0
D:8005A93C     aPplant2bz_0:   .ascii "Pplant2bZ"<0>    # DATA XREF: D:800476A4o
D:8005A946                     .half 0
D:8005A948     aPplant3z_0:    .ascii "Pplant3Z"<0>     # DATA XREF: D:800476B0o
D:8005A951                     .byte 0, 0, 0
D:8005A954     aPradio_unit1z_0:.ascii "Pradio_unit1Z"<0>  # DATA XREF: D:800476BCo
D:8005A962                     .half 0
D:8005A964     aPradio_unit2z_0:.ascii "Pradio_unit2Z"<0>  # DATA XREF: D:800476C8o
D:8005A972                     .half 0
D:8005A974     aPradio_unit3z_0:.ascii "Pradio_unit3Z"<0>  # DATA XREF: D:800476D4o
D:8005A982                     .half 0
D:8005A984     aPradio_unit4z_0:.ascii "Pradio_unit4Z"<0>  # DATA XREF: D:800476E0o
D:8005A992                     .half 0
D:8005A994     aProofgunz_0:   .ascii "ProofgunZ"<0>    # DATA XREF: D:800476ECo
D:8005A99E                     .half 0
D:8005A9A0     aPsafez_0:      .ascii "PsafeZ"<0>       # DATA XREF: D:800476F8o
D:8005A9A7                     .byte 0
D:8005A9A8     aPsafedoorz_0:  .ascii "PsafedoorZ"<0>   # DATA XREF: D:80047704o
D:8005A9B3                     .byte 0
D:8005A9B4     aPsat1_reflectz_0:.ascii "Psat1_reflectZ"<0>  # DATA XREF: D:80047710o
D:8005A9C3                     .byte 0
D:8005A9C4     aPsatboxz_0:    .ascii "PsatboxZ"<0>     # DATA XREF: D:8004771Co
D:8005A9CD                     .byte 0, 0, 0
D:8005A9D0     aPsatdishz_0:   .ascii "PsatdishZ"<0>    # DATA XREF: D:80047728o
D:8005A9DA                     .half 0
D:8005A9DC     aPsec_panelz_0: .ascii "Psec_panelZ"<0>  # DATA XREF: D:80047734o
D:8005A9E8     aPsev_door3z_0: .ascii "Psev_door3Z"<0>  # DATA XREF: D:80047740o
D:8005A9F4     aPsev_door3_windz_0:.ascii "Psev_door3_windZ"<0>  # DATA XREF: D:8004774Co
D:8005AA05                     .byte 0, 0, 0
D:8005AA08     aPsev_door4_windz_0:.ascii "Psev_door4_windZ"<0>  # DATA XREF: D:80047758o
D:8005AA19                     .byte 0, 0, 0
D:8005AA1C     aPsev_doorz_0:  .ascii "Psev_doorZ"<0>   # DATA XREF: D:80047764o
D:8005AA27                     .byte 0
D:8005AA28     aPsev_door_v1z_0:.ascii "Psev_door_v1Z"<0>  # DATA XREF: D:80047770o
D:8005AA36                     .half 0
D:8005AA38     aPsev_trislidez_0:.ascii "Psev_trislideZ"<0>  # DATA XREF: D:8004777Co
D:8005AA47                     .byte 0
D:8005AA48     aPsevdishz_0:   .ascii "PsevdishZ"<0>    # DATA XREF: D:80047788o
D:8005AA52                     .half 0
D:8005AA54     aPsevdoormetslidez_0:.ascii "PsevdoormetslideZ"<0>  # DATA XREF: D:80047794o
D:8005AA66                     .half 0
D:8005AA68     aPsevdoornowindz_0:.ascii "PsevdoornowindZ"<0>  # DATA XREF: D:800477A0o
D:8005AA78     aPsevdoorwindz_0:.ascii "PsevdoorwindZ"<0>  # DATA XREF: D:800477ACo
D:8005AA86                     .half 0
D:8005AA88     aPsevdoorwoodz_0:.ascii "PsevdoorwoodZ"<0>  # DATA XREF: D:800477B8o
D:8005AA96                     .half 0
D:8005AA98     aPshuttlez_0:   .ascii "PshuttleZ"<0>    # DATA XREF: D:800477C4o
D:8005AAA2                     .half 0
D:8005AAA4     aPshuttle_door_lz_0:.ascii "Pshuttle_door_lZ"<0>  # DATA XREF: D:800477D0o
D:8005AAB5                     .byte 0, 0, 0
D:8005AAB8     aPshuttle_door_rz_0:.ascii "Pshuttle_door_rZ"<0>  # DATA XREF: D:800477DCo
D:8005AAC9                     .byte 0, 0, 0
D:8005AACC     aPsilencerz_0:  .ascii "PsilencerZ"<0>   # DATA XREF: D:800477E8o
D:8005AAD7                     .byte 0
D:8005AAD8     aPsilo_lift_doorz_0:.ascii "Psilo_lift_doorZ"<0>  # DATA XREF: D:800477F4o
D:8005AAE9                     .byte 0, 0, 0
D:8005AAEC     aPsilotopdoorz_0:.ascii "PsilotopdoorZ"<0>  # DATA XREF: D:80047800o
D:8005AAFA                     .half 0
D:8005AAFC     aPskorpionmagz_0:.ascii "PskorpionmagZ"<0>  # DATA XREF: D:8004780Co
D:8005AB0A                     .half 0
D:8005AB0C     aPspectremagz_0:.ascii "PspectremagZ"<0>  # DATA XREF: D:80047818o
D:8005AB19                     .byte 0, 0, 0
D:8005AB1C     aPspeedboatz_0: .ascii "PspeedboatZ"<0>  # DATA XREF: D:80047824o
D:8005AB28     aPst_pete_room_1iz_0:.ascii "Pst_pete_room_1iZ"<0>  # DATA XREF: D:80047830o
D:8005AB3A                     .half 0
D:8005AB3C     aPst_pete_room_2iz_0:.ascii "Pst_pete_room_2iZ"<0>  # DATA XREF: D:8004783Co
D:8005AB4E                     .half 0
D:8005AB50     aPst_pete_room_3tz_0:.ascii "Pst_pete_room_3tZ"<0>  # DATA XREF: D:80047848o
D:8005AB62                     .half 0
D:8005AB64     aPst_pete_room_5cz_0:.ascii "Pst_pete_room_5cZ"<0>  # DATA XREF: D:80047854o
D:8005AB76                     .half 0
D:8005AB78     aPst_pete_room_6cz_0:.ascii "Pst_pete_room_6cZ"<0>  # DATA XREF: D:80047860o
D:8005AB8A                     .half 0
D:8005AB8C     aPsteel_door1z_0:.ascii "Psteel_door1Z"<0>  # DATA XREF: D:8004786Co
D:8005AB9A                     .half 0
D:8005AB9C     aPsteel_door2z_0:.ascii "Psteel_door2Z"<0>  # DATA XREF: D:80047878o
D:8005ABAA                     .half 0
D:8005ABAC     aPsteel_door2bz_0:.ascii "Psteel_door2bZ"<0>  # DATA XREF: D:80047884o
D:8005ABBB                     .byte 0
D:8005ABBC     aPsteel_door3z_0:.ascii "Psteel_door3Z"<0>  # DATA XREF: D:80047890o
D:8005ABCA                     .half 0
D:8005ABCC     aPstool1z_0:    .ascii "Pstool1Z"<0>     # DATA XREF: D:8004789Co
D:8005ABD5                     .byte 0, 0, 0
D:8005ABD8     aPswipe_card2z_0:.ascii "Pswipe_card2Z"<0>  # DATA XREF: D:800478A8o
D:8005ABE6                     .half 0
D:8005ABE8     aPswivel_chair1z_0:.ascii "Pswivel_chair1Z"<0>  # DATA XREF: D:800478B4o
D:8005ABF8     aPtankz_0:      .ascii "PtankZ"<0>       # DATA XREF: D:800478C0o
D:8005ABFF                     .byte 0
D:8005AC00     aPtigerz_0:     .ascii "PtigerZ"<0>      # DATA XREF: D:800478CCo
D:8005AC08     aPtorpedo_rackz_0:.ascii "Ptorpedo_rackZ"<0>  # DATA XREF: D:800478D8o
D:8005AC17                     .byte 0
D:8005AC18     aPtrain_door2z_0:.ascii "Ptrain_door2Z"<0>  # DATA XREF: D:800478E4o
D:8005AC26                     .half 0
D:8005AC28     aPtrain_door3z_0:.ascii "Ptrain_door3Z"<0>  # DATA XREF: D:800478F0o
D:8005AC36                     .half 0
D:8005AC38     aPtrain_doorz_0:.ascii "Ptrain_doorZ"<0>  # DATA XREF: D:800478FCo
D:8005AC45                     .byte 0, 0, 0
D:8005AC48     aPtrainextdoorz_0:.ascii "PtrainextdoorZ"<0>  # DATA XREF: D:80047908o
D:8005AC57                     .byte 0
D:8005AC58     aPtt33magz_0:   .ascii "Ptt33magZ"<0>    # DATA XREF: D:80047914o
D:8005AC62                     .half 0
D:8005AC64     aPtuning_console1z_0:.ascii "Ptuning_console1Z"<0><0><0>
D:8005AC64                                              # DATA XREF: D:80047920o
D:8005AC78     aPtv1z_0:       .ascii "Ptv1Z"<0><0><0>  # DATA XREF: D:8004792Co
D:8005AC80     aPtv4screenz_0: .ascii "Ptv4screenZ"<0>  # DATA XREF: D:80047938o
D:8005AC8C     aPtv_holderz_0: .ascii "Ptv_holderZ"<0>  # DATA XREF: D:80047944o
D:8005AC98     aPtvscreenz_1:  .ascii "PtvscreenZ"<0><0>  # DATA XREF: D:80047950o
D:8005ACA4     aPuzimagz_0:    .ascii "PuzimagZ"<0><0><0><0>  # DATA XREF: D:8004795Co
D:8005ACB0     aPvertdoorz_1:  .ascii "PvertdoorZ"<0><0>  # DATA XREF: D:80047968o
D:8005ACBC     aPwalletbondz_0:.ascii "PwalletbondZ"<0><0><0><0>  # DATA XREF: D:80047974o
D:8005ACCC     aPwindowz_0:    .ascii "PwindowZ"<0><0><0><0>  # DATA XREF: D:80047980o
D:8005ACD8     aPwindow_cor11z_1:.ascii "Pwindow_cor11Z"<0><0>  # DATA XREF: D:8004798Co
D:8005ACE8     aPwindow_lib_lg1z_0:.ascii "Pwindow_lib_lg1Z"<0><0><0><0>
D:8005ACE8                                              # DATA XREF: D:80047998o
D:8005ACFC     aPwindow_lib_sm1z_0:.ascii "Pwindow_lib_sm1Z"<0><0><0><0>
D:8005ACFC                                              # DATA XREF: D:800479A4o
D:8005AD10     aPwood_lg_crate1z_0:.ascii "Pwood_lg_crate1Z"<0><0><0><0>
D:8005AD10                                              # DATA XREF: D:800479B0o
D:8005AD24     aPwood_lg_crate2z_0:.ascii "Pwood_lg_crate2Z"<0><0><0><0>
D:8005AD24                                              # DATA XREF: D:800479BCo
D:8005AD38     aPwood_md_crate3z_0:.ascii "Pwood_md_crate3Z"<0><0><0><0>
D:8005AD38                                              # DATA XREF: D:800479C8o
D:8005AD4C     aPwood_sm_crate4z_0:.ascii "Pwood_sm_crate4Z"<0><0><0><0>
D:8005AD4C                                              # DATA XREF: D:800479D4o
D:8005AD60     aPwood_sm_crate5z_0:.ascii "Pwood_sm_crate5Z"<0><0><0><0>
D:8005AD60                                              # DATA XREF: D:800479E0o
D:8005AD74     aPwood_sm_crate6z_0:.ascii "Pwood_sm_crate6Z"<0><0><0><0>
D:8005AD74                                              # DATA XREF: D:800479ECo
D:8005AD88     aPwooden_table1z_0:.ascii "Pwooden_table1Z"<0>  # DATA XREF: D:800479F8o
D:8005AD98     aPwppkmagz_0:   .ascii "PwppkmagZ"<0><0><0>  # DATA XREF: D:80047A04o
D:8005ADA4     aTbg_ame_all_p_stanz_2:.ascii "Tbg_ame_all_p_stanZ"<0>
D:8005ADA4                                              # DATA XREF: D:80047A10o
D:8005ADB8     aTbg_arch_all_p_stanz_0:.ascii "Tbg_arch_all_p_stanZ"<0><0><0><0>
D:8005ADB8                                              # DATA XREF: D:80047A1Co
D:8005ADD0     aTbg_arec_all_p_stanz_0:.ascii "Tbg_arec_all_p_stanZ"<0><0><0><0>
D:8005ADD0                                              # DATA XREF: D:80047A28o
D:8005ADE8     aTbg_ark_all_p_stanz_0:.ascii "Tbg_ark_all_p_stanZ"<0>
D:8005ADE8                                              # DATA XREF: D:80047A34o
D:8005ADFC     aTbg_ash_all_p_stanz:.ascii "Tbg_ash_all_p_stanZ"<0>  # DATA XREF: D:80047A40o
D:8005AE10     aTbg_azt_all_p_stanz_0:.ascii "Tbg_azt_all_p_stanZ"<0>
D:8005AE10                                              # DATA XREF: D:80047A4Co
D:8005AE24     aTbg_cat_all_p_stanz_0:.ascii "Tbg_cat_all_p_stanZ"<0>
D:8005AE24                                              # DATA XREF: D:80047A58o
D:8005AE38     aTbg_cave_all_p_stanz_0:.ascii "Tbg_cave_all_p_stanZ"<0><0><0><0>
D:8005AE38                                              # DATA XREF: D:80047A64o
D:8005AE50     aTbg_crad_all_p_stanz_0:.ascii "Tbg_crad_all_p_stanZ"<0><0><0><0>
D:8005AE50                                              # DATA XREF: D:80047A70o
D:8005AE68     aTbg_cryp_all_p_stanz_0:.ascii "Tbg_cryp_all_p_stanZ"<0><0><0><0>
D:8005AE68                                              # DATA XREF: D:80047A7Co
D:8005AE80     aTbg_dam_all_p_stanz_0:.ascii "Tbg_dam_all_p_stanZ"<0>
D:8005AE80                                              # DATA XREF: D:80047A88o
D:8005AE94     aTbg_depo_all_p_stanz_0:.ascii "Tbg_depo_all_p_stanZ"<0><0><0><0>
D:8005AE94                                              # DATA XREF: D:80047A94o
D:8005AEAC     aTbg_dest_all_p_stanz_0:.ascii "Tbg_dest_all_p_stanZ"<0><0><0><0>
D:8005AEAC                                              # DATA XREF: D:80047AA0o
D:8005AEC4     aTbg_dish_all_p_stanz_0:.ascii "Tbg_dish_all_p_stanZ"<0><0><0><0>
D:8005AEC4                                              # DATA XREF: D:80047AACo
D:8005AEDC     aTbg_ear_all_p_stanz_0:.ascii "Tbg_ear_all_p_stanZ"<0>
D:8005AEDC                                              # DATA XREF: D:80047AB8o
D:8005AEF0     aTbg_eld_all_p_stanz_0:.ascii "Tbg_eld_all_p_stanZ"<0>
D:8005AEF0                                              # DATA XREF: D:80047AC4o
D:8005AF04     aTbg_imp_all_p_stanz:.ascii "Tbg_imp_all_p_stanZ"<0>  # DATA XREF: D:80047AD0o
D:8005AF18     aTbg_jun_all_p_stanz_0:.ascii "Tbg_jun_all_p_stanZ"<0>
D:8005AF18                                              # DATA XREF: D:80047ADCo
D:8005AF2C     aTbg_lee_all_p_stanz_0:.ascii "Tbg_lee_all_p_stanZ"<0>
D:8005AF2C                                              # DATA XREF: D:80047AE8o
D:8005AF40     aTbg_len_all_p_stanz_0:.ascii "Tbg_len_all_p_stanZ"<0>
D:8005AF40                                              # DATA XREF: D:80047AF4o
D:8005AF54     aTbg_lip_all_p_stanz_0:.ascii "Tbg_lip_all_p_stanZ"<0>
D:8005AF54                                              # DATA XREF: D:80047B00o
D:8005AF68     aTbg_lue_all_p_stanz_0:.ascii "Tbg_lue_all_p_stanZ"<0>
D:8005AF68                                              # DATA XREF: D:80047B0Co
D:8005AF7C     aTbg_oat_all_p_stanz_0:.ascii "Tbg_oat_all_p_stanZ"<0>
D:8005AF7C                                              # DATA XREF: D:80047B18o
D:8005AF90     aTbg_pam_all_p_stanz_0:.ascii "Tbg_pam_all_p_stanZ"<0>
D:8005AF90                                              # DATA XREF: D:80047B24o
D:8005AFA4     aTbg_pete_all_p_stanz_0:.ascii "Tbg_pete_all_p_stanZ"<0><0><0><0>
D:8005AFA4                                              # DATA XREF: D:80047B30o
D:8005AFBC     aTbg_ref_all_p_stanz_0:.ascii "Tbg_ref_all_p_stanZ"<0>
D:8005AFBC                                              # DATA XREF: D:80047B3Co
D:8005AFD0     aTbg_rit_all_p_stanz_0:.ascii "Tbg_rit_all_p_stanZ"<0>
D:8005AFD0                                              # DATA XREF: D:80047B48o
D:8005AFE4     aTbg_run_all_p_stanz_0:.ascii "Tbg_run_all_p_stanZ"<0>
D:8005AFE4                                              # DATA XREF: D:80047B54o
D:8005AFF8     aTbg_sev_all_p_stanz_0:.ascii "Tbg_sev_all_p_stanZ"<0>
D:8005AFF8                                              # DATA XREF: D:80047B60o
D:8005B00C     aTbg_sevb_all_p_stanz_0:.ascii "Tbg_sevb_all_p_stanZ"<0><0><0><0>
D:8005B00C                                              # DATA XREF: D:80047B6Co
D:8005B024     aTbg_sevx_all_p_stanz_1:.ascii "Tbg_sevx_all_p_stanZ"<0><0><0><0>
D:8005B024                                              # DATA XREF: D:80047B78o
D:8005B03C     aTbg_silo_all_p_stanz_0:.ascii "Tbg_silo_all_p_stanZ"<0><0><0><0>
D:8005B03C                                              # DATA XREF: D:80047B84o
D:8005B054     aTbg_stat_all_p_stanz_0:.ascii "Tbg_stat_all_p_stanZ"<0><0><0><0>
D:8005B054                                              # DATA XREF: D:80047B90o
D:8005B06C     aTbg_tra_all_p_stanz_0:.ascii "Tbg_tra_all_p_stanZ"<0>
D:8005B06C                                              # DATA XREF: D:80047B9Co
D:8005B080     aTbg_wax_all_p_stanz_0:.ascii "Tbg_wax_all_p_stanZ"<0>
D:8005B080                                              # DATA XREF: D:80047BA8o
D:8005B094     aUbriefarchz:   .ascii "UbriefarchZ"<0>  # DATA XREF: D:80047BB4o
D:8005B0A0     aUbriefarkz:    .ascii "UbriefarkZ"<0><0>  # DATA XREF: D:80047BC0o
D:8005B0AC     aUbriefaztz:    .ascii "UbriefaztZ"<0><0>  # DATA XREF: D:80047BCCo
D:8005B0B8     aUbriefcavez:   .ascii "UbriefcaveZ"<0>  # DATA XREF: D:80047BD8o
D:8005B0C4     aUbriefcontrolz:.ascii "UbriefcontrolZ"<0><0>  # DATA XREF: D:80047BE4o
D:8005B0D4     aUbriefcradz:   .ascii "UbriefcradZ"<0>  # DATA XREF: D:80047BF0o
D:8005B0E0     aUbriefcrypz:   .ascii "UbriefcrypZ"<0>  # DATA XREF: D:80047BFCo
D:8005B0EC     aUbriefdamz:    .ascii "UbriefdamZ"<0><0>  # DATA XREF: D:80047C08o
D:8005B0F8     aUbriefdepoz:   .ascii "UbriefdepoZ"<0>  # DATA XREF: D:80047C14o
D:8005B104     aUbriefdestz:   .ascii "UbriefdestZ"<0>  # DATA XREF: D:80047C20o
D:8005B110     aUbriefjunz:    .ascii "UbriefjunZ"<0><0>  # DATA XREF: D:80047C2Co
D:8005B11C     aUbriefpetez:   .ascii "UbriefpeteZ"<0>  # DATA XREF: D:80047C38o
D:8005B128     aUbriefrunz:    .ascii "UbriefrunZ"<0><0>  # DATA XREF: D:80047C44o
D:8005B134     aUbriefsevbz:   .ascii "UbriefsevbZ"<0>  # DATA XREF: D:80047C50o
D:8005B140     aUbriefsevbunkerz:.ascii "UbriefsevbunkerZ"<0><0><0><0>
D:8005B140                                              # DATA XREF: D:80047C5Co
D:8005B154     aUbriefsevxz:   .ascii "UbriefsevxZ"<0>  # DATA XREF: D:80047C68o
D:8005B160     aUbriefsevxbz:  .ascii "UbriefsevxbZ"<0><0><0><0>  # DATA XREF: D:80047C74o
D:8005B170     aUbriefsiloz:   .ascii "UbriefsiloZ"<0>  # DATA XREF: D:80047C80o
D:8005B17C     aUbriefstatuez: .ascii "UbriefstatueZ"<0><0><0>  # DATA XREF: D:80047C8Co
D:8005B18C     aUbrieftraz:    .ascii "UbrieftraZ"<0><0>  # DATA XREF: D:80047C98o
D:8005B198     aUmp_setupamez: .ascii "Ump_setupameZ"<0><0><0>  # DATA XREF: D:80047CA4o
D:8005B1A8     aUmp_setuparchz:.ascii "Ump_setuparchZ"<0><0>  # DATA XREF: D:80047CB0o
D:8005B1B8     aUmp_setuparkz: .ascii "Ump_setuparkZ"<0><0><0>  # DATA XREF: D:80047CBCo
D:8005B1C8     aUmp_setupashz: .ascii "Ump_setupashZ"<0><0><0>  # DATA XREF: D:80047CC8o
D:8005B1D8     aUmp_setupcavez:.ascii "Ump_setupcaveZ"<0><0>  # DATA XREF: D:80047CD4o
D:8005B1E8     aUmp_setupcradz:.ascii "Ump_setupcradZ"<0><0>  # DATA XREF: D:80047CE0o
D:8005B1F8     aUmp_setupcrypz:.ascii "Ump_setupcrypZ"<0><0>  # DATA XREF: D:80047CECo
D:8005B208     aUmp_setupdishz:.ascii "Ump_setupdishZ"<0><0>  # DATA XREF: D:80047CF8o
D:8005B218     aUmp_setupimpz: .ascii "Ump_setupimpZ"<0><0><0>  # DATA XREF: D:80047D04o
D:8005B228     aUmp_setupoatz: .ascii "Ump_setupoatZ"<0><0><0>  # DATA XREF: D:80047D10o
D:8005B238     aUmp_setuprefz: .ascii "Ump_setuprefZ"<0><0><0>  # DATA XREF: D:80047D1Co
D:8005B248     aUmp_setupsevbz:.ascii "Ump_setupsevbZ"<0><0>  # DATA XREF: D:80047D28o
D:8005B258     aUmp_setupstatuez:.ascii "Ump_setupstatueZ"<0><0><0><0>
D:8005B258                                              # DATA XREF: D:80047D34o
D:8005B26C     aUsetuparchz_0: .ascii "UsetuparchZ"<0>  # DATA XREF: D:80047D40o
D:8005B278     aUsetuparkz_1:  .ascii "UsetuparkZ"<0><0>  # DATA XREF: D:80047D4Co
D:8005B284     aUsetupaztz_1:  .ascii "UsetupaztZ"<0><0>  # DATA XREF: D:80047D58o
D:8005B290     aUsetupcavez_0: .ascii "UsetupcaveZ"<0>  # DATA XREF: D:80047D64o
D:8005B29C     aUsetupcontrolz_1:.ascii "UsetupcontrolZ"<0><0>  # DATA XREF: D:80047D70o
D:8005B2AC     aUsetupcradz_0: .ascii "UsetupcradZ"<0>  # DATA XREF: D:80047D7Co
D:8005B2B8     aUsetupcrypz_0: .ascii "UsetupcrypZ"<0>  # DATA XREF: D:80047D88o
D:8005B2C4     aUsetupdamz_1:  .ascii "UsetupdamZ"<0><0>  # DATA XREF: D:80047D94o
D:8005B2D0     aUsetupdepoz_0: .ascii "UsetupdepoZ"<0>  # DATA XREF: D:80047DA0o
D:8005B2DC     aUsetupdestz_0: .ascii "UsetupdestZ"<0>  # DATA XREF: D:80047DACo
D:8005B2E8     aUsetupjunz_1:  .ascii "UsetupjunZ"<0><0>  # DATA XREF: D:80047DB8o
D:8005B2F4     aUsetuplenz_1:  .ascii "UsetuplenZ"<0><0>  # DATA XREF: D:80047DC4o
D:8005B300     aUsetuppetez_0: .ascii "UsetuppeteZ"<0>  # DATA XREF: D:80047DD0o
D:8005B30C     aUsetuprunz_1:  .ascii "UsetuprunZ"<0><0>  # DATA XREF: D:80047DDCo
D:8005B318     aUsetupsevbz_0: .ascii "UsetupsevbZ"<0>  # DATA XREF: D:80047DE8o
D:8005B324     aUsetupsevbunkerz_1:.ascii "UsetupsevbunkerZ"<0><0><0><0>
D:8005B324                                              # DATA XREF: D:80047DF4o
D:8005B338     aUsetupsevxz_0: .ascii "UsetupsevxZ"<0>  # DATA XREF: D:80047E00o
D:8005B344     aUsetupsevxbz_0:.ascii "UsetupsevxbZ"<0><0><0><0>  # DATA XREF: D:80047E0Co
D:8005B354     aUsetupsiloz_0: .ascii "UsetupsiloZ"<0>  # DATA XREF: D:80047E18o
D:8005B360     aUsetupstatuez_0:.ascii "UsetupstatueZ"<0><0><0>  # DATA XREF: D:80047E24o
D:8005B370     aUsetuptraz_1:  .ascii "UsetuptraZ"<0><0>  # DATA XREF: D:80047E30o
D:8005B37C     aLamee_0:       .ascii "LameE"<0><0><0>  # DATA XREF: D:80047E3Co
D:8005B384     aLamej_0:       .ascii "LameJ"<0><0><0>  # DATA XREF: D:80047E48o
D:8005B38C     aLarche_1:      .ascii "LarchE"<0><0>    # DATA XREF: D:80047E54o
D:8005B394     aLarchj_1:      .ascii "LarchJ"<0><0>    # DATA XREF: D:80047E60o
D:8005B39C     aLarece_1:      .ascii "LarecE"<0><0>    # DATA XREF: D:80047E6Co
D:8005B3A4     aLarecj_1:      .ascii "LarecJ"<0><0>    # DATA XREF: D:80047E78o
D:8005B3AC     aLarke_0:       .ascii "LarkE"<0><0><0>  # DATA XREF: D:80047E84o
D:8005B3B4     aLarkj_0:       .ascii "LarkJ"<0><0><0>  # DATA XREF: D:80047E90o
D:8005B3BC     aLashe_0:       .ascii "LashE"<0><0><0>  # DATA XREF: D:80047E9Co
D:8005B3C4     aLashj_0:       .ascii "LashJ"<0><0><0>  # DATA XREF: D:80047EA8o
D:8005B3CC     aLazte_0:       .ascii "LaztE"<0><0><0>  # DATA XREF: D:80047EB4o
D:8005B3D4     aLaztj_0:       .ascii "LaztJ"<0><0><0>  # DATA XREF: D:80047EC0o
D:8005B3DC     aLcate_0:       .ascii "LcatE"<0><0><0>  # DATA XREF: D:80047ECCo
D:8005B3E4     aLcatj_0:       .ascii "LcatJ"<0><0><0>  # DATA XREF: D:80047ED8o
D:8005B3EC     aLcavee_1:      .ascii "LcaveE"<0><0>    # DATA XREF: D:80047EE4o
D:8005B3F4     aLcavej_1:      .ascii "LcaveJ"<0><0>    # DATA XREF: D:80047EF0o
D:8005B3FC     aLcrade_1:      .ascii "LcradE"<0><0>    # DATA XREF: D:80047EFCo
D:8005B404     aLcradj_1:      .ascii "LcradJ"<0><0>    # DATA XREF: D:80047F08o
D:8005B40C     aLcrype_1:      .ascii "LcrypE"<0><0>    # DATA XREF: D:80047F14o
D:8005B414     aLcrypj_1:      .ascii "LcrypJ"<0><0>    # DATA XREF: D:80047F20o
D:8005B41C     aLdame_0:       .ascii "LdamE"<0><0><0>  # DATA XREF: D:80047F2Co
D:8005B424     aLdamj_0:       .ascii "LdamJ"<0><0><0>  # DATA XREF: D:80047F38o
D:8005B42C     aLdepoe_1:      .ascii "LdepoE"<0><0>    # DATA XREF: D:80047F44o
D:8005B434     aLdepoj_1:      .ascii "LdepoJ"<0><0>    # DATA XREF: D:80047F50o
D:8005B43C     aLdeste_1:      .ascii "LdestE"<0><0>    # DATA XREF: D:80047F5Co
D:8005B444     aLdestj_1:      .ascii "LdestJ"<0><0>    # DATA XREF: D:80047F68o
D:8005B44C     aLdishe_1:      .ascii "LdishE"<0><0>    # DATA XREF: D:80047F74o
D:8005B454     aLdishj_1:      .ascii "LdishJ"<0><0>    # DATA XREF: D:80047F80o
D:8005B45C     aLeare_0:       .ascii "LearE"<0><0><0>  # DATA XREF: D:80047F8Co
D:8005B464     aLearj_0:       .ascii "LearJ"<0><0><0>  # DATA XREF: D:80047F98o
D:8005B46C     aLelde_0:       .ascii "LeldE"<0><0><0>  # DATA XREF: D:80047FA4o
D:8005B474     aLeldj_0:       .ascii "LeldJ"<0><0><0>  # DATA XREF: D:80047FB0o
D:8005B47C     aLgune_0:       .ascii "LgunE"<0><0><0>  # DATA XREF: D:80047FBCo
D:8005B484     aLgunj_0:       .ascii "LgunJ"<0><0><0>  # DATA XREF: D:80047FC8o
D:8005B48C     aLimpe_0:       .ascii "LimpE"<0><0><0>  # DATA XREF: D:80047FD4o
D:8005B494     aLimpj_0:       .ascii "LimpJ"<0><0><0>  # DATA XREF: D:80047FE0o
D:8005B49C     aLjune_0:       .ascii "LjunE"<0><0><0>  # DATA XREF: D:80047FECo
D:8005B4A4     aLjunj_0:       .ascii "LjunJ"<0><0><0>  # DATA XREF: D:80047FF8o
D:8005B4AC     aLleee_0:       .ascii "LleeE"<0><0><0>  # DATA XREF: D:80048004o
D:8005B4B4     aLleej_0:       .ascii "LleeJ"<0><0><0>  # DATA XREF: D:80048010o
D:8005B4BC     aLlene_0:       .ascii "LlenE"<0><0><0>  # DATA XREF: D:8004801Co
D:8005B4C4     aLlenj_0:       .ascii "LlenJ"<0><0><0>  # DATA XREF: D:80048028o
D:8005B4CC     aLlipe_0:       .ascii "LlipE"<0><0><0>  # DATA XREF: D:80048034o
D:8005B4D4     aLlipj_0:       .ascii "LlipJ"<0><0><0>  # DATA XREF: D:80048040o
D:8005B4DC     aLluee_0:       .ascii "LlueE"<0><0><0>  # DATA XREF: D:8004804Co
D:8005B4E4     aLluej_0:       .ascii "LlueJ"<0><0><0>  # DATA XREF: D:80048058o
D:8005B4EC     aLmisce_1:      .ascii "LmiscE"<0><0>    # DATA XREF: D:80048064o
D:8005B4F4     aLmiscj_1:      .ascii "LmiscJ"<0><0>    # DATA XREF: D:80048070o
D:8005B4FC     aLmpmenue_0:    .ascii "LmpmenuE"<0><0><0><0>  # DATA XREF: D:8004807Co
D:8005B508     aLmpmenuj_0:    .ascii "LmpmenuJ"<0><0><0><0>  # DATA XREF: D:80048088o
D:8005B514     aLmpweaponse_0: .ascii "LmpweaponsE"<0>  # DATA XREF: D:80048094o
D:8005B520     aLmpweaponsj_0: .ascii "LmpweaponsJ"<0>  # DATA XREF: D:800480A0o
D:8005B52C     aLoate_0:       .ascii "LoatE"<0><0><0>  # DATA XREF: D:800480ACo
D:8005B534     aLoatj_0:       .ascii "LoatJ"<0><0><0>  # DATA XREF: D:800480B8o
D:8005B53C     aLoptionse_0:   .ascii "LoptionsE"<0><0><0>  # DATA XREF: D:800480C4o
D:8005B548     aLoptionsj_0:   .ascii "LoptionsJ"<0><0><0>  # DATA XREF: D:800480D0o
D:8005B554     aLpame_0:       .ascii "LpamE"<0><0><0>  # DATA XREF: D:800480DCo
D:8005B55C     aLpamj_0:       .ascii "LpamJ"<0><0><0>  # DATA XREF: D:800480E8o
D:8005B564     aLpetee_1:      .ascii "LpeteE"<0><0>    # DATA XREF: D:800480F4o
D:8005B56C     aLpetej_1:      .ascii "LpeteJ"<0><0>    # DATA XREF: D:80048100o
D:8005B574     aLpropobje_0:   .ascii "LpropobjE"<0><0><0>  # DATA XREF: D:8004810Co
D:8005B580     aLpropobjj_0:   .ascii "LpropobjJ"<0><0><0>  # DATA XREF: D:80048118o
D:8005B58C     aLrefe_0:       .ascii "LrefE"<0><0><0>  # DATA XREF: D:80048124o
D:8005B594     aLrefj_0:       .ascii "LrefJ"<0><0><0>  # DATA XREF: D:80048130o
D:8005B59C     aLrite_0:       .ascii "LritE"<0><0><0>  # DATA XREF: D:8004813Co
D:8005B5A4     aLritj_0:       .ascii "LritJ"<0><0><0>  # DATA XREF: D:80048148o
D:8005B5AC     aLrune_0:       .ascii "LrunE"<0><0><0>  # DATA XREF: D:80048154o
D:8005B5B4     aLrunj_0:       .ascii "LrunJ"<0><0><0>  # DATA XREF: D:80048160o
D:8005B5BC     aLseve_0:       .ascii "LsevE"<0><0><0>  # DATA XREF: D:8004816Co
D:8005B5C4     aLsevj_0:       .ascii "LsevJ"<0><0><0>  # DATA XREF: D:80048178o
D:8005B5CC     aLsevbe_1:      .ascii "LsevbE"<0><0>    # DATA XREF: D:80048184o
D:8005B5D4     aLsevbj_1:      .ascii "LsevbJ"<0><0>    # DATA XREF: D:80048190o
D:8005B5DC     aLsevxe_1:      .ascii "LsevxE"<0><0>    # DATA XREF: D:8004819Co
D:8005B5E4     aLsevxj_1:      .ascii "LsevxJ"<0><0>    # DATA XREF: D:800481A8o
D:8005B5EC     aLsevxbe_0:     .ascii "LsevxbE"<0>      # DATA XREF: D:800481B4o
D:8005B5F4     aLsevxbj_0:     .ascii "LsevxbJ"<0>      # DATA XREF: D:800481C0o
D:8005B5FC     aLshoe_0:       .ascii "LshoE"<0><0><0>  # DATA XREF: D:800481CCo
D:8005B604     aLshoj_0:       .ascii "LshoJ"<0><0><0>  # DATA XREF: D:800481D8o
D:8005B60C     aLsiloe_1:      .ascii "LsiloE"<0><0>    # DATA XREF: D:800481E4o
D:8005B614     aLsiloj_1:      .ascii "LsiloJ"<0><0>    # DATA XREF: D:800481F0o
D:8005B61C     aLstate_1:      .ascii "LstatE"<0><0>    # DATA XREF: D:800481FCo
D:8005B624     aLstatj_1:      .ascii "LstatJ"<0><0>    # DATA XREF: D:80048208o
D:8005B62C     aLtitlee_0:     .ascii "LtitleE"<0>      # DATA XREF: D:80048214o
D:8005B634     aLtitlej_0:     .ascii "LtitleJ"<0>      # DATA XREF: D:80048220o
D:8005B63C     aLtrae_0:       .ascii "LtraE"<0><0><0>  # DATA XREF: D:8004822Co
D:8005B644     aLtraj_0:       .ascii "LtraJ"<0><0><0>  # DATA XREF: D:80048238o
D:8005B64C     aLwaxe_0:       .ascii "LwaxE"<0><0><0>  # DATA XREF: D:80048244o
D:8005B654     aLwaxj_0:       .ascii "LwaxJ"<0><0><0>  # DATA XREF: D:80048250o
D:8005B65C     aObOb_end_seg:  .ascii "ob/ob_end.seg"<0>  # DATA XREF: D:8004825Co
D:8005B66A                     .half 0
D:8005B66C     rz_header_1:    .word 0x11720000         # DATA XREF: load_resource_from_indy+8Cr
D:8005B670     rz_header_2:    .word 0x11720000         # DATA XREF: load_resource_from_indy+ACr
D:8005B674     aOb_c_debug:    .ascii "ob_c_debug"<0><0>  # DATA XREF: ob_c_debug_setup+Co
*/

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
/* 0F15E8 7F0BCAB8 0C001707 */  jal   load_bytes_from_hw_to_rdram
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
/* 0F1634 7F0BCB04 0C001707 */  jal   load_bytes_from_hw_to_rdram
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
/* 0F16FC 7F0BCBCC 3C0E8006 */  lui   $t6, %hi(D_8005B671) # $t6, 0x8006
/* 0F1700 7F0BCBD0 02002825 */  move  $a1, $s0
/* 0F1704 7F0BCBD4 156C000B */  bne   $t3, $t4, .L7F0BCC04
/* 0F1708 7F0BCBD8 00E02025 */   move  $a0, $a3
/* 0F170C 7F0BCBDC 90ED0001 */  lbu   $t5, 1($a3)
/* 0F1710 7F0BCBE0 91CEB671 */  lbu   $t6, %lo(D_8005B671)($t6)
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
void ob_c_debug_setup(void) {

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
/* 0F177C 7F0BCC4C 3C048004 */  lui   $a0, %hi(D_80046060) # $a0, 0x8004
/* 0F1780 7F0BCC50 24846060 */  addiu $a0, %lo(D_80046060) # addiu $a0, $a0, 0x6060
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
void _load_rom_index_to_membank(void) {

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
void _load_resource_named_to_membank(void) {

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
void _load_resource_named_to_buffer(void) {

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
/* 0F1924 7F0BCDF4 0C001707 */  jal   load_bytes_from_hw_to_rdram
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
void load_resource_index_to_buffer(void) {

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
void sub_GAME_7F0BD138(void) {

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
/* 0F1CD8 7F0BD1A8 3C028009 */  lui   $v0, 0x8009
/* 0F1CDC 7F0BD1AC 004E1021 */  addu  $v0, $v0, $t6
/* 0F1CE0 7F0BD1B0 8C4288B4 */  lw    $v0, -0x774c($v0)
/* 0F1CE4 7F0BD1B4 03E00008 */  jr    $ra
/* 0F1CE8 7F0BD1B8 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void something_mem_bank_a0(void) {

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
/* 0F1DB8 7F0BD288 3C108004 */  lui   $s0, %hi(D_80046060) # $s0, 0x8004
/* 0F1DBC 7F0BD28C 26106060 */  addiu $s0, %lo(D_80046060) # addiu $s0, $s0, 0x6060
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
void sub_GAME_7F0BD410(void) {

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


 
