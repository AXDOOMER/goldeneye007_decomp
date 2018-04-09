.section .bss  

dword_80069440: .space 0x18
dword_80069458: .space 0xC0
dword_80069518: .space 0x20
ptr_animation_table: .space 4 #0x80069538
 .align 4
if_positive_last_mp_weapon_set_num: .space 4 #0x80069540
 .align 4
dword_80069550: .space 4
dword_80069554: .space 4
matrix_buffer_0: .space 4 #0x80069558
matrix_buffer_1: .space 4 #0x8006955C
matrix_buffer_2: .space 4 #0x80069560
matrix_buffer_3: .space 4 #0x80069564
matrix_buffer_4: .space 4 #0x80069568
matrix_buffer_5: .space 4 #0x8006956C
matrix_buffer_6: .space 4 #0x80069570
x: .space 4 #0x80069574
y: .space 4 #0x80069578
flt_8006957C: .space 4
dword_80069580: .space 4
word_80069584: .space 2
 .align 2
dword_80069588: .space 4
dword_8006958C: .space 4
virtualaddress: .space 4 #0x80069590
dword_80069594: .space 4
 .align 4
flt_800695A0: .space 4
flt_800695A4: .space 4
flt_800695A8: .space 4
flt_800695AC: .space 4
flt_800695B0: .space 4
flt_800695B4: .space 4
flt_800695B8: .space 4
flt_800695BC: .space 4
flt_800695C0: .space 4
 .align 3
flt_800695C8: .space 4
flt_800695CC: .space 4
flt_800695D0: .space 4
 .align 3
flt_800695D8: .space 4
flt_800695DC: .space 4
flt_800695E0: .space 4
dword_800695E4: .space 4
flt_800695E8: .space 4
flt_800695EC: .space 4
flt_800695F0: .space 4
 .align 3
flt_800695F8: .space 4
flt_800695FC: .space 4
flt_80069600: .space 4
 .align 3
flt_80069608: .space 4
flt_8006960C: .space 4
flt_80069610: .space 4
flt_80069614: .space 4
flt_80069618: .space 4
 .align 4
dword_80069620: .space 0x30
 .space 1
cheat_available: .space 3 #0x80069651
 .space 0x4C
cheat_activated: .space 1 #0x800696A0
CHEAT_AVAILABLE_EXTRA_CHARS: .space 1 #0x800696A1
cheat_activated_1: .space 1 #0x800696A2
cheat_activated_2: .space 1 #0x800696A3
 .space 0x44
 .space 3
byte_800696EB: .space 1
 .align 4
fav_weapon_right_player1: .space 4 #0x800696F0
fav_weapon_left_player1: .space 4 #0x800696F4
 .space 0x18
mp_char_cur_select_player1: .space 4 #0x80069710
mp_char_cur_select_player2: .space 4 #0x80069714
mp_char_cur_select_player3: .space 4 #0x80069718
mp_char_cur_select_player4: .space 4 #0x8006971C
mp_char_prev_select_player1: .space 4 #0x80069720
mp_char_prev_select_player2: .space 4 #0x80069724
mp_char_prev_select_player3: .space 4 #0x80069728
mp_char_prev_select_player4: .space 4 #0x8006972C
dword_80069730: .space 4
dword_80069734: .space 4
dword_80069738: .space 4
dword_8006973C: .space 4
has_selected_char_player1: .space 4 #0x80069740
has_selected_char_player2: .space 4 #0x80069744
has_selected_char_player3: .space 4 #0x80069748
has_selected_char_player4: .space 4 #0x8006974C
size_mp_select_image_player1: .space 4 #0x80069750
size_mp_select_image_player2: .space 4 #0x80069754
size_mp_select_image_player3: .space 4 #0x80069758
size_mp_select_image_player4: .space 4 #0x8006975C
dword_80069760: .space 4
dword_80069764: .space 4
dword_80069768: .space 4
dword_8006976C: .space 4
dword_80069770: .space 4
dword_80069774: .space 4
dword_80069778: .space 4
current_mp_stage_highlighted: .space 4 #0x8006977C
dword_80069780: .space 4
mission_difficulty_highlighted: .space 4 #0x80069784
dword_80069788: .space 4
dword_8006978C: .space 4
dword_80069790: .space 4
highlight_enemy_reaction: .space 4 #0x80069794
highlight_enemy_health: .space 4 #0x80069798
highlight_enemy_accuracy: .space 4 #0x8006979C
highlight_enemy_damage: .space 4 #0x800697A0
 .align 3
handicap_player1: .space 4 #0x800697A8
handicap_player2: .space 4 #0x800697AC
handicap_player3: .space 4 #0x800697B0
handicap_player4: .space 4 #0x800697B4
controlstyle_player1: .space 4 #0x800697B8
controlstyle_player2: .space 4 #0x800697BC
controlstyle_player3: .space 4 #0x800697C0
controlstyle_player4: .space 4 #0x800697C4
highlight_players: .space 4 #0x800697C8
highlight_scenario: .space 4 #0x800697CC
highlight_gameselect: .space 4 #0x800697D0
highlight_gamelength: .space 4 #0x800697D4
highlight_character: .space 4 #0x800697D8
highlight_weaponselect: .space 4 #0x800697DC
highlight_health: .space 4 #0x800697E0
highlight_controlstyle: .space 4 #0x800697E4
highlight_aimadjustment: .space 4 #0x800697E8
 .align 4
dword_800697F0: .space 0x130
save1: .space 8 #0x80069920
dword_80069928: .space 0x58
save2: .space 0x180 #0x80069980
dword_80069B00: .space 0x60
dword_80069B60: .space 4
 .align 4
sfx_related: .space 4 #0x80069B70
dword_80069B74: .space 4
dword_80069B78: .space 4
 .space 0xB4
ptr_list_object_lookup_indices: .space 4 #0x80069C30
num_obj_position_data_entries: .space 4 #0x80069C34
pos.data_entry: .space 0x24 #0x80069C38
dword_80069C5C: .space 4
 .space 0xC
dword_80069C6C: .space 0x24
dword_80069C90: .space 4
 .align 4
dword_80069CA0: .space 0x24
dword_80069CC4: .space 4
 .space 0xC
dword_80069CD4: .space 0x34
dword_80069D08: .space 0x34
dword_80069D3C: .space 0x34
dword_80069D70: .space 0x34
dword_80069DA4: .space 0x7874
ptr_room_lookup_buffer_maybe: .space 4 #0x80071618
dword_8007161C: .space 4
dword_80071620: .space 4
 .space 0x90
dword_800716B4: .space 0x73C
dword_80071DF0: .space 4
dword_80071DF4: .space 4
dword_80071DF8: .space 4
 .align 4
dword_80071E00: .space 4
dword_80071E04: .space 4
dword_80071E08: .space 0x70
gas_damage_flag: .space 4 #0x80071E78
gas_cutoff_flag: .space 4 #0x80071E7C
autogenerated_weapons: .space 0xFF0 #0x80071E80
dword_80072E70: .space 0x500
dword_80073370: .space 0xA50
dword_80073DC0: .space 0x1270
dword_80075030: .space 0xB40
dword_80075B70: .space 4
dword_80075B74: .space 4
flt_80075B78: .space 4
flt_80075B7C: .space 4
flt_80075B80: .space 4
 .align 3
flt_80075B88: .space 4
flt_80075B8C: .space 4
flt_80075B90: .space 4
 .align 3
dword_80075B98: .space 0x6C
dword_80075C04: .space 0xC
dword_80075C10: .space 0x78
dword_80075C88: .space 0x78
ptr_setup.path.tbl: .space 4 #0x80075D00
ptr_setup.path.link: .space 4 #0x80075D04
ptr_setup.intro: .space 4 #0x80075D08
ptr_setup.objects: .space 4 #0x80075D0C
ptr_setup.path.sets: .space 4 #0x80075D10
ptr_setup.actions: .space 4 #0x80075D14
ptr_0xxxpresets: .space 4 #0x80075D18
ptr_2xxxpresets: .space 4 #0x80075D1C
dword_80075D20: .space 4
dword_80075D24: .space 4
dword_80075D28: .space 4
 .align 4
objective_ptrs: .space 4 #0x80075D30
dword_80075D34: .space 4
dword_80075D38: .space 0x20
dword_80075D58: .space 4
dword_80075D5C: .space 4
dword_80075D60: .space 0x20
ptr_last_tag_entry_type16: .space 4 #0x80075D80
ptr_last_briefing_setup_entry_type23: .space 4 #0x80075D84
ptr_last_enter_room_subobject_entry_type20: .space 4 #0x80075D88
ptr_last_deposit_in_room_subobject_entry_type21: .space 4 #0x80075D8C
ptr_last_photo_obj_in_room_subobject_entry_type1E: .space 4 #0x80075D90
 .align 4
flt_80075DA0: .space 4
 .align 4
dword_80075DB0: .space 4
 .align 3
dword_80075DB8: .space 4
dword_80075DBC: .space 4
dword_80075DC0: .space 4
dword_80075DC4: .space 4
dword_80075DC8: .space 0x9C
dword_80075E64: .space 4
dword_80075E68: .space 0xBE0
dword_80076A48: .space 8
dword_80076A50: .space 0xC
dword_80076A5C: .space 4
 .space 4
dword_80076A64: .space 0xC
dword_80076A70: .space 4
dword_80076A74: .space 4
dword_80076A78: .space 0xC
dword_80076A84: .space 4
dword_80076A88: .space 4
dword_80076A8C: .space 0x14
dword_80076AA0: .space 0x14
dword_80076AB4: .space 0x14
dword_80076AC8: .space 0x14
dword_80076ADC: .space 0x2E2C
dword_80079908: .space 0x28
ptr_allocation_0: .space 4 #0x80079930
ptr_allocation_1: .space 4 #0x80079934
 .align 4
flt_80079940: .space 4
flt_80079944: .space 4
flt_80079948: .space 4
flt_8007994C: .space 4
flt_80079950: .space 4
flt_80079954: .space 4
flt_80079958: .space 4
flt_8007995C: .space 4
flt_80079960: .space 4
flt_80079964: .space 4
flt_80079968: .space 4
flt_8007996C: .space 4
flt_80079970: .space 4
flt_80079974: .space 4
flt_80079978: .space 4
flt_8007997C: .space 4
flt_80079980: .space 4
 .align 4
flt_80079990: .space 4
flt_80079994: .space 4
flt_80079998: .space 4
dword_8007999C: .space 4
dword_800799A0: .space 4
 .align 3
flt_800799A8: .space 4
flt_800799AC: .space 4
flt_800799B0: .space 4
dword_800799B4: .space 4
dword_800799B8: .space 4
flt_800799BC: .space 4
flt_800799C0: .space 4
flt_800799C4: .space 4
flt_800799C8: .space 4
 .align 4
flt_800799D0: .space 4
flt_800799D4: .space 4
flt_800799D8: .space 4
 .align 4
starting_right_weapon: .space 4 #0x800799E0
starting_left_weapon: .space 4 #0x800799E4
flt_800799E8: .space 4
flt_800799EC: .space 4
flt_800799F0: .space 4
dword_800799F4: .space 4
dword_800799F8: .space 4
dword_800799FC: .space 4
flt_80079A00: .space 4
flt_80079A04: .space 4
flt_80079A08: .space 4
flt_80079A0C: .space 4
flt_80079A10: .space 4
dword_80079A14: .space 4
dword_80079A18: .space 4
dword_80079A1C: .space 4
dword_80079A20: .space 4
watch_time_0: .space 4 #0x80079A24
dword_80079A28: .space 0x200
dword_80079C28: .space 4
 .space 0x3C
dword_80079C68: .space 4
 .align 4
dword_80079C70: .space 0x130
dword_80079DA0: .space 4
dword_80079DA4: .space 4
dword_80079DA8: .space 0x20
dword_80079DC8: .space 0x3C
flt_80079E04: .space 4
flt_80079E08: .space 4
flt_80079E0C: .space 4
flt_80079E10: .space 4
 .align 4
dword_80079E20: .space 4
 .align 4
byte_80079E30: .space 1
byte_80079E31: .space 1
byte_80079E32: .space 1
byte_80079E33: .space 1
 .space 0x44
 .space 3
byte_80079E7B: .space 1
 .align 4
flt_80079E80: .space 4
flt_80079E84: .space 4
flt_80079E88: .space 4
 .align 4
dword_80079E90: .space 4
 .align 3
dword_80079E98: .space 0x48
ptr_BONDdata_p1: .space 4 #0x80079EE0
ptr_BONDdata_p2: .space 4 #0x80079EE4
ptr_BONDdata_p3: .space 4 #0x80079EE8
ptr_BONDdata_p4: .space 4 #0x80079EEC
player1_playerdata: .space 0x24 #0x80079EF0
dword_80079F14: .space 4
 .space 0x30
dword_80079F48: .space 4
flt_80079F4C: .space 4
 .space 4
flt_80079F54: .space 4
 .space 1
byte_80079F59: .space 1
byte_80079F5A: .space 1
byte_80079F5B: .space 1
 .space 0x2C
dword_80079F88: .space 4
 .space 0x30
flt_80079FBC: .space 4
 .space 4
flt_80079FC4: .space 4
 .space 1
byte_80079FC9: .space 1
byte_80079FCA: .space 1
byte_80079FCB: .space 1
 .space 0x30
dword_80079FFC: .space 4
 .space 0x2C
flt_8007A02C: .space 4
 .space 4
flt_8007A034: .space 4
 .space 1
byte_8007A039: .space 1
byte_8007A03A: .space 1
byte_8007A03B: .space 1
 .space 0x34
dword_8007A070: .space 4
 .space 0x28
flt_8007A09C: .space 4
 .space 4
flt_8007A0A4: .space 4
 .space 1
byte_8007A0A9: .space 1
byte_8007A0AA: .space 1
byte_8007A0AB: .space 1
 .align 4
ptr_BONDdata: .space 4 #0x8007A0B0
cur_player_stat_ptr: .space 4 #0x8007A0B4
player_num: .space 4 #0x8007A0B8
random_byte: .space 4 #0x8007A0BC
dword_8007A0C0: .space 4
dword_8007A0C4: .space 4
dword_8007A0C8: .space 4
dword_8007A0CC: .space 4
dword_8007A0D0: .space 4
dword_8007A0D4: .space 4
dword_8007A0D8: .space 4
dword_8007A0DC: .space 4
dword_8007A0E0: .space 4
dword_8007A0E4: .space 4
dword_8007A0E8: .space 4
dword_8007A0EC: .space 4
word_8007A0F0: .space 2
word_8007A0F2: .space 2
 .align 4
dword_8007A100: .space 0x40
ptr_smoke_buf: .space 4 #0x8007A140
ptr_explosion_buf: .space 4 #0x8007A144
max_casings: .space 4 #0x8007A148
ptr_ejected_casing_buf: .space 4 #0x8007A14C
ptr_scorch_buf: .space 4 #0x8007A150
ptr_bullet_impact_buf: .space 4 #0x8007A154
 .align 4
dword_8007A160: .space 4
dword_8007A164: .space 4
 .align 4
dword_8007A170: .space 4
word_8007A174: .space 2
 .align 2
 .space 0x368
dword_8007A4E0: .space 4
word_8007A4E4: .space 2
 .align 2
 .space 0xBB0
dword_8007B098: .space 8
dword_8007B0A0: .space 0x40
dword_8007B0E0: .space 0x40
clippingfile: .space 4 #0x8007B120
 .align 3
dword_8007B128: .space 4
dword_8007B12C: .space 4
dword_8007B130: .space 4
dword_8007B134: .space 0x220
dword_8007B354: .space 4
dword_8007B358: .space 0x684
dword_8007B9DC: .space 4
 .space 4
dword_8007B9E4: .space 4
dword_8007B9E8: .space 4
 .align 4
flt_8007B9F0: .space 4
flt_8007B9F4: .space 4
flt_8007B9F8: .space 4
flt_8007B9FC: .space 4
flt_8007BA00: .space 4
dword_8007BA04: .space 4
 .space 4
dword_8007BA0C: .space 4
dword_8007BA10: .space 4
 .space 0x57C
ptr_bg_data: .space 4 #0x8007BF90
ptr_clipping: .space 4 #0x8007BF94
dword_8007BF98: .space 4
 .align 4
list_visible_rooms_in_cur_global.vis_packet: .space 1 #0x8007BFA0
 .align 2
 .space 0x94
num_visible_rooms_in_cur_global.vis_packet: .space 4 #0x8007C038
 .align 4
dword_8007C040: .space 0x60
dword_8007C0A0: .space 0x60
dword_8007C100: .space 0x38C0
dword_8007F9C0: .space 0x5C0
ptr_bgdata.portals: .space 4 #0x8007FF80
ptr_bgdata.offsets: .space 4 #0x8007FF84
dword_8007FF88: .space 4
ptr_bgdata.room_fileposition_list: .space 4 #0x8007FF8C
dword_8007FF90: .space 4
dword_8007FF94: .space 4
dword_8007FF98: .space 4
 .align 4
dword_8007FFA0: .space 4
dword_8007FFA4: .space 4
 .space 0x1658
dword_80081600: .space 0x10
dword_80081610: .space 4
 .align 3
table_for_portals: .space 0xFA0 #0x80081618
dword_800825B8: .space 8
sky_enabled: .space 4 #0x800825C0
ptr_nearfog_enviroment_values: .space 4 #0x800825C4
buffer_far_pervasiveness: .space 4 #0x800825C8
far_fog: .space 4 #0x800825CC
 .space 8
flt_800825D8: .space 4
flt_800825DC: .space 4
buffer_far_ambiant: .space 4 #0x800825E0
bg_dif.light: .space 4 #0x800825E4
env.table_hit: .space 4 #0x800825E8
env.table_match_start: .space 4 #0x800825EC
env.table_match_end: .space 4 #0x800825F0
 .align 3
dword_800825F8: .space 4
flt_800825FC: .space 4
flt_80082600: .space 4
 .space 0x14
dword_80082618: .space 4
dword_8008261C: .space 4
byte_80082620: .space 1
byte_80082621: .space 1
byte_80082622: .space 1
 .align 2
 .space 0x3C
light_fixture_table: .space 2 #0x80082660
 .align 3
dword_80082668: .space 4
 .space 0x4A4
cur_entry_lightfixture_table: .space 2 #0x80082B10
index_of_cur_entry_lightfixture_table: .space 2 #0x80082B12
 .align 3
word_80082B18: .space 2
 .align 2
 .space 0x7FC
dword_80083318: .space 8
dword_80083320: .space 0x130
dword_80083450: .space 4
 .space 0x4AC
dword_80083900: .space 4
 .space 0x4AC
dword_80083DB0: .space 0x4B00
ptr_resource_data: .space 4 #0x800888B0
dword_800888B4: .space 4
 .space 0xC
ptr_res.data.next: .space 0x10 #0x800888C4
byte_800888D4: .space 1
 .align 2
dword_800888D8: .space 0x3958
ptr_mgfx0_alloc_start: .space 4 #0x8008C230
ptr_mgfx1_alloc_start: .space 4 #0x8008C234
ptr_mgfx_end: .space 4 #0x8008C238
 .align 4
ptr_mvtx0_alloc_start: .space 4 #0x8008C240
ptr_mvtx1_alloc_start: .space 4 #0x8008C244
ptr_mvtx_end: .space 4 #0x8008C248
ptr_mvtx_cur_pos: .space 4 #0x8008C24C
bank_in_mgfx_alloc_table: .space 1 #0x8008C250
 .align 2
dword_8008C254: .space 4
 .align 4
ptr_jfont.DL: .space 4 #0x8008C260
 .align 4
ramrom_data_target: .space 0xC #0x8008C270
 .space 3
byte_8008C27F: .space 1
 .space 0x100
dword_8008C380: .space 0xE8
dword_8008C468: .space 0xC
 .space 3
byte_8008C477: .space 1
 .space 0x14
 .space 2
word_8008C48E: .space 2
 .space 0x160
record_slot_num: .space 4 #0x8008C5F0
addres_demo_loaded: .space 4 #0x8008C5F4
dword_8008C5F8: .space 4
 .align 4
dword_8008C600: .space 4
dword_8008C604: .space 4
dword_8008C608: .space 4
dword_8008C60C: .space 4
dword_8008C610: .space 4
dword_8008C614: .space 4
dword_8008C618: .space 4
dword_8008C61C: .space 4
dword_8008C620: .space 4
dword_8008C624: .space 4
dword_8008C628: .space 4
dword_8008C62C: .space 4
dword_8008C630: .space 4
dword_8008C634: .space 4
 .align 4
ptr_text: .space 4 #0x8008C640
table_text_pointers: .space 0x94 #0x8008C644
dword_8008C6D8: .space 4
dword_8008C6DC: .space 4
dword_8008C6E0: .space 4
dword_8008C6E4: .space 4
dword_8008C6E8: .space 4
dword_8008C6EC: .space 4
dword_8008C6F0: .space 4
ptr_j_char_data_buf: .space 4 #0x8008C6F4
ptr_j_char_registry: .space 4 #0x8008C6F8
 .align 4
stop_play: .space 4 #0x8008C700
is_gameover: .space 4 #0x8008C704
dword_8008C708: .space 4
dword_8008C70C: .space 4
time_trigger_alt_gameover_msg: .space 4 #0x8008C710
dword_8008C714: .space 4
is_paused: .space 4 #0x8008C718
who_paused: .space 4 #0x8008C71C
ptr_texture_alloc_start: .space 4 #0x8008C720
ptr_texture_alloc_end: .space 4 #0x8008C724
 .align 4
word_8008C730: .space 2
 .align 2
 .space 0x95C
dword_8008D090: .space 4
dword_8008D094: .space 4
 .align 4
dword_8008D0A0: .space 4
dword_8008D0A4: .space 4
dword_8008D0A8: .space 4
 .align 4
globalbank_rdram_offset: .space 4 #0x8008D0B0
ptr_explosionDL: .space 4 #0x8008D0B4
image: .space 4 #0x8008D0B8
dword_8008D0BC: .space 4
dword_8008D0C0: .space 4
dword_8008D0C4: .space 4
dword_8008D0C8: .space 4
dword_8008D0CC: .space 4
dword_8008D0D0: .space 4
dword_8008D0D4: .space 4
dword_8008D0D8: .space 4
dword_8008D0DC: .space 4
dword_8008D0E0: .space 4
dword_8008D0E4: .space 4
dword_8008D0E8: .space 4
dword_8008D0EC: .space 4
dword_8008D0F0: .space 4
dword_8008D0F4: .space 4
dword_8008D0F8: .space 4
dword_8008D0FC: .space 4
dword_8008D100: .space 4
dword_8008D104: .space 4
dword_8008D108: .space 4
dword_8008D10C: .space 4
dword_8008D110: .space 4
dword_8008D114: .space 4
dword_8008D118: .space 4
dword_8008D11C: .space 4
dword_8008D120: .space 4
dword_8008D124: .space 4
dword_8008D128: .space 4
dword_8008D12C: .space 4
dword_8008D130: .space 4
dword_8008D134: .space 4
 .align 4
dword_8008D140: .space 4
 .align 3
dword_8008D148: .space 0x160
dword_8008D2A8: .space 0xA0
dword_8008D348: .space 8
dword_8008D350: .space 4
dword_8008D354: .space 4
dword_8008D358: .space 4
dword_8008D35C: .space 4
dword_8008D360: .space 4
dword_8008D364: .space 4
dword_8008D368: .space 4
dword_8008D36C: .space 4
dword_8008D370: .space 0x400
dword_8008D770: .space 0xBA0
viewport.img.width: .space 4 #0x8008E310
viewport.img.height: .space 4 #0x8008E314
 .align 4
ptr_sectrum_monitor_data_temp_buf: .space 4 #0x8008E320
ptr_sectrum_game_data_temp_buf: .space 4 #0x8008E324
ptr_spectrum.roms: .space 4 #0x8008E328
ptr_300alloc: .space 4 #0x8008E32C
ptr_6000alloc: .space 4 #0x8008E330
ptr_pc_keyboard_table_alloc: .space 4 #0x8008E334
spectrum.header16_15: .space 1 #0x8008E338
byte_8008E339: .space 1
byte_8008E33A: .space 1
byte_8008E33B: .space 1
byte_8008E33C: .space 1
byte_8008E33D: .space 1
byte_8008E33E: .space 1
byte_8008E33F: .space 1
byte_8008E340: .space 1
byte_8008E341: .space 1
byte_8008E342: .space 1
byte_8008E343: .space 1
byte_8008E344: .space 1
byte_8008E345: .space 1
byte_8008E346: .space 1
byte_8008E347: .space 1
spec.I: .space 1 #0x8008E348
byte_8008E349: .space 1
spec.IFF2_lower: .space 1 #0x8008E34A
spec.IFF2_upper: .space 1 #0x8008E34B
spec.IM: .space 1 #0x8008E34C
byte_8008E34D: .space 1
spec.IX: .space 2 #0x8008E34E
spec.IY: .space 2 #0x8008E350
spec.SP: .space 2 #0x8008E352
spec.PC: .space 2 #0x8008E354
 .align 4  
.global _BSS_END   
_BSS_END:    

