#ifndef _BONDVIEW_H_
#define _BONDVIEW_H_
#include "ultra64.h"

struct prop_pos_data {
    u16 x;
    u16 y;
    u16 z;
};

struct item_related {
    short num_entries_in_block;
    short field_2;
    struct prop_pos_data * ptr_block;
    short total_cmd_indexval;
    short field_A;
};

struct PitemZ_header {
    int microcode_entry_num;
    struct item_related * anonymous_1;
    short anonymous_2;
    short field_E;
    float drawdistance;
    int anonymous_4;
    int anonymous_5;
    int anonymous_6;
};

struct p_itementry {
    struct PitemZ_header * header;
    void * filename;
    float scale;
};

struct object_header {
    int offset_obj_table;
    void * ptr_archetype;
    int offset_obj_offset_block;
    short num_offset_entries;
    short num_object_grps;
    float anonymous_4;
    short num_table_entries;
    short num_image_entries;
    int offset_img_declaration;
    int is_loaded_in_mem;
};

struct c_itementry {
    struct object_header * header;
    void * filename;
    float anonymous_1;
    float anonymous_2;
    int anonymous_3;
};

struct model_data {
    u32  anonymous_0;
    u32 *propposdata;
    u32  anonymous_2;
};

struct player_gait_header {
    u8 field_0x0;
    u8 type;
    u16 field_0x2;
    void * field_0x4;
    struct player_gait_header * previous;
    void * field_0xc;
    void * field_0x10;
    struct player_gait_header * next;
};

struct player_gait_pos_header {
    u8 field_0x0;
    u8 type;
    u16 field_0x2;
    void * field_0x4;
    struct player_gait_header * previous;
    void * field_0xc;
    void * field_0x10;
    struct player_gait_header * next;
};

struct player_gait_object_entry {
    u32 field_0x0;
    struct player_gait_header * ptr_header;
    u32 field_0x8;
    u32 field_0xc;
};

struct player_gait_position_entry {
    float flt_1;
    float flt_2;
    float flt_3;
    u16 field_0xc;
    u16 field_0xe;
    u16 field_0x10;
    u16 field_0x12;
    struct player_gait_header * ptr_header;
    u32 field_0x18;
};
extern struct item_related prop_cctv_related;
extern struct item_related prop_console_one_screen_related;
extern struct item_related prop_console_four_screen_related;
extern struct item_related prop_tv_holder_related;
extern struct item_related prop_rotating_stuff_related;
extern struct item_related prop_eyelid_door_related;
extern struct item_related prop_iris_door_related;
extern struct item_related prop_walletbond_related;
extern struct item_related prop_car_related;
extern struct item_related prop_flying_related;
extern struct item_related prop_door_related;
extern struct item_related item_tank_related;
extern struct item_related item_hat_related;
extern struct item_related model_object_standard_object;
extern struct item_related prop_weapon_related;
extern struct model_data model_guard_character;
extern struct player_gait_header dword_D_8003C580;
extern struct player_gait_pos_header dword_D_8003C598;
extern struct player_gait_pos_header dword_D_8003C5B0;
extern struct player_gait_pos_header dword_D_8003C5C8;
extern struct player_gait_object_entry dword_D_8003C5E0;
extern struct player_gait_position_entry dword_D_8003C5F0;
extern struct player_gait_position_entry dword_D_8003C60C;
extern struct player_gait_position_entry dword_D_8003C628;

#endif
