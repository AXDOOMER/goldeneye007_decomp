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

struct Gitemheader {
    int offset_objtable;
    struct model_data * guntype_modeldata;
    int offset_objblock;
    short num05soffset_entries;
    short num_objgroups;
    float drawdistance;
    u16 num_entries;
    u16 num_images;
    int offset_imgdecl;
    u32 isloaded;
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

struct struct_13 {
    void * anonymous_0;
    int anonymous_1;
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

extern struct Gitemheader GwppkZ_struct;
extern struct Gitemheader GwppksilZ_struct;
extern struct Gitemheader Gtt33Z_struct;
extern struct Gitemheader GskorpianZ_struct;
extern struct Gitemheader Gak47Z_struct;
extern struct Gitemheader GuziZ_struct;
extern struct Gitemheader Gmp5kZ_struct;
extern struct Gitemheader Gmp5ksilZ_struct;
extern struct Gitemheader Gm16Z_struct;
extern struct Gitemheader Gfnp90Z_struct;
extern struct Gitemheader G8003C900_struct;
extern struct Gitemheader GrugerZ_struct;
extern struct Gitemheader GgoldengunZ_struct;
extern struct Gitemheader GshotgunZ_struct;
extern struct Gitemheader GautoshotZ_struct;
extern struct Gitemheader GgrenadelaunchZ_struct;
extern struct Gitemheader GspectreZ_struct;
extern struct Gitemheader GlaserZ_struct;
extern struct Gitemheader GrocketlaunchZ_struct;
extern struct Gitemheader GknifeZ_header;
extern struct Gitemheader GthrowknifeZ_struct;
extern struct Gitemheader GtaserZ_struct;
extern struct Gitemheader GremotemineZ_struct;
extern struct Gitemheader GproximitymineZ_struct;
extern struct Gitemheader GtimedmineZ_struct;
extern struct Gitemheader GtriggerZ_struct;
extern struct Gitemheader GgrenadeZ_struct;
extern struct Gitemheader GfistZ_header;
extern struct Gitemheader GsniperrifleZ_struct;
extern struct Gitemheader GcartridgeZ_struct;
extern struct Gitemheader GcartrifleZ_struct;
extern struct Gitemheader GcartblueZ_struct;
extern struct Gitemheader GcartshellZ_struct;
extern struct Gitemheader GjoypadZ_struct;
extern struct Gitemheader G8003CC00_struct;
extern struct Gitemheader G8003CC20_struct;
extern struct Gitemheader GbombcaseZ_struct;
extern struct Gitemheader GflarepistolZ_struct;
extern struct Gitemheader GpitongunZ_struct;
extern struct Gitemheader G8003CCA0_struct;
extern struct Gitemheader GsilverwppkZ_struct;
extern struct Gitemheader GgoldwppkZ_struct;
extern struct Gitemheader G8003CD00_struct;
extern struct Gitemheader GbungeeZ_struct;
extern struct Gitemheader GdoordecoderZ_struct;
extern struct Gitemheader GbombdefuserZ_struct;
extern struct Gitemheader GbugdetectorZ_struct;
extern struct Gitemheader GsafecrackercaseZ_struct;
extern struct Gitemheader GcameraZ_struct;
extern struct Gitemheader GlockexploderZ_struct;
extern struct Gitemheader GdoorexploderZ_struct;
extern struct Gitemheader GkeyanalysercaseZ_struct;
extern struct Gitemheader GweaponcaseZ_struct;
extern struct Gitemheader GkeycardZ_struct;
extern struct Gitemheader GkeyyaleZ_struct;
extern struct Gitemheader GkeyboltZ_struct;
extern struct Gitemheader GbugZ_struct;
extern struct Gitemheader GmicrocameraZ_struct;
extern struct Gitemheader GexplosivefloppyZ_struct;
extern struct Gitemheader GgoldeneyekeyZ_struct;
extern struct Gitemheader GpolarizedglassesZ_struct;
extern struct Gitemheader GcreditcardZ_struct;
extern struct Gitemheader GdarkglassesZ_struct;
extern struct Gitemheader GwatchidentifierZ_struct;
extern struct Gitemheader GwatchcommunicatorZ_struct;
extern struct Gitemheader GwatchlaserZ_struct;
extern struct Gitemheader GwatchgeigercounterZ_struct;
extern struct Gitemheader GwatchmagnetrepelZ_struct;
extern struct Gitemheader GwatchmagnetattractZ_struct;
extern struct Gitemheader GgaskeyringZ_struct;
extern struct Gitemheader GdatathiefZ_struct;
extern struct Gitemheader GbriefcaseZ_struct;
extern struct Gitemheader GblackboxZ_struct;
extern struct Gitemheader GplastiqueZ_struct;
extern struct Gitemheader GvideotapeZ_struct;
extern struct Gitemheader GclipboardZ_struct;
extern struct Gitemheader GstafflistZ_struct;
extern struct Gitemheader GdossierredZ_struct;
extern struct Gitemheader GaudiotapeZ_struct;
extern struct Gitemheader GdattapeZ_struct;
extern struct Gitemheader GplansZ_struct;
extern struct Gitemheader GspyfileZ_struct;
extern struct Gitemheader GblueprintsZ_struct;
extern struct Gitemheader GcircuitboardZ_struct;
extern struct Gitemheader GmapZ_struct;
extern struct Gitemheader GspooltapeZ_struct;
extern struct Gitemheader GmicrofilmZ_struct;
extern struct Gitemheader GmicrocodeZ_struct;
extern struct Gitemheader GlectreZ_struct;
extern struct Gitemheader GmoneyZ_struct;
extern struct Gitemheader GgoldbarZ_struct;
extern struct Gitemheader GheroinZ_struct;
extern struct model_data weapon_gun_controller;

#endif
