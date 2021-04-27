#ifndef _BONDTYPES_H_
#define _BONDTYPES_H_
#include "ultra64.h"
#include "bondconstants.h"
#include "structs.h"

struct rgba_val{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

struct rgba_valf32{
    f32 r;
    f32 g;
    f32 b;
    f32 a;
};

typedef struct ChrRecord
{
    u16 chrnum;          /* 0x0000 */
    s8 accuracyrating;   /* 0x0002 */
    s8 speedrating;      /* 0x0003 */
} ChrRecord;

typedef struct Model
{
    u8 unk00;       /*0x00*/
    u8 unk01;       /*0x01*/
    ChrRecord *chr;   /*0x04*/
} Model;


/******

 The following struct ObjHeaderData was copied from AIListLogic branch
 and should be removed when merged

******/
typedef struct ObjHeaderData
{
    u16 extrascale; /*0x0 Fixed-Point format u8.8 eg: 0x03.80 = 3.5*/
    u8 hidden2;     // state - Destroyed, respawn, defused etc /*0x2*/
                    /*
                    8x	destroyed
                    4x	datathief/defuser/decoder used on obj (activated?)
                    2x
                    1x
                    x8	external allocated collision block present
                    x4	respawn enabled
                    x2
                    x1	damaged*/
    u8 type;        /*0x3*/
} ObjHeaderData;

/******

 The following struct ObjectRecord was copied from AIListLogic branch
 and should be removed when merged

 note: only the necessary fields were copied in order to compile (not the full struct)

******/
typedef struct ObjectRecord
{
    ObjHeaderData head;
    s16 obj;
    s16 pad;        /* ID 0x6 
                    0000+ or 2710+ (10,000+) to use standard presets.
                    -1 to -256 to set this object
                        inside the previous object.(solo only)
                    if control nibble 4x is set at 0xB,
                    then this number matches the ID of a guard 
                    */
    u32 flags;      /*0x8
                    8x	indicates right-handed gun assignment
                    4x	08 weapon does not provide ammunition when collected
                    2x	indicates object in motion or special function is activated
                    1x	indicates left-handed normal pickup or opposite alignment
                    0x	indicates no control features set
                    x8
                    x4	(unknown) Jungle bushes
                    x2	(unknown) pete grenade
                    x1	indicates embedded crate or other object, creating a chain of boxes, for
                    example      x0	indicates normal preset, or beginning/end of chain
                    Doors:
                    8x	open by default
                    4x	area behind door is always visible (no blackouts for gates, lab doors, etc)
                    2x	open backwards
                    1x	same as 0 as far as I can tell
                    x8	always open away from the player regardless what side you're on
                    x4	
                    x2	player can't activate door (spawn block or 16 type activation)
                    x1
                    0x9:
                    8x	
                    4x	immobile
                    2x	(unknown) Silo DAT tape
                    1x	uncollectable
                    x8	
                    x4	allows object pickup (chr_name objects only)
                    x2	invincibility
                    x1	
                    0xA:
                    8x	indicates contained within another object (forward or back # objects = preset value)
                    4x	indicates object does not use normal presets but is assigned to guard #preset
                    2x	(unknown) part of forced collectable objects
                    1x	think this sets object to absolute position.  (similar to 2xxx type)
                    x8	something to do with free-standing glass (glass walls)
                    x4	(unknown) streets buildings/roadblocks
                    x2	seems to align image to preset values for glass
                    x1	force collisions (2xxx presets, mostly)
                    0xB:
                     0xxx presets:
                        00	default, on ground
                        x1	forced to ground
                        x2	room upper limit, rotated y 90 degrees.  top faces direction, front faces up
                        x4	room upper limit, upside-down
                        x8	room upper limit, right side up
                    2xxx presets:
                        x1	normal placement
                        x2	rotated y 90 degrees.  top faces direction, front faces up. (use on obj 68-6B)
                        x4	upside-down
                        x8	in-air
                        1x	scale object to fit completely within preset bounds
                        2x	x set to preset bounds
                        4x	y set to preset bounds
                        8x	z set to preset bounds
                    */
    u32 flags2;       /*0xC:
                    8x	force maximum explosion radius/disable detecting
                         player
                    4x	autoturrets: reset to default, not preset position
                    2x	no AI interaction
                    1x	1-way lock (back)
                    x8	1-way lock (front)
                    x4
                    x2	Objects (rockets, mines, etc) do not collide with object
                    x1	don't load 4 player
                    0xD:
                    8x	don't load 3 player
                    4x	don't load 2 player
                    2x	immune to explosions (only gunfire damages object)
                    1x	bulletproof
                    x8	invisible! can't shoot, but can hit with rockets, bugs, etc.  not counted as a hit
                    x4 
                    x2	(unknown) streets buildings
                    x1
                    0xE:
                    8x	Can fire through object
                    4x	immune to gunfire (Only explosives damage object)
                    2x	Remove from game when destroyed (anything on top doesn't fall off!  Just Poof! gone)
                    1x
                    x8	only activate at close range
                    x4
                    x2	explode on contact with tank?
                    x1	(unknown) jungle bush
                    0xF:
                    8x	don't load on 007
                    4x	don't load on 00 agent
                    2x	don't load on secret agent
                    1x	don't load on agent
                    x8	don't load multiplayer (difficulty = -1)
                    x4	disable activation text
                    x2	lightweight (previous: 2xxx drops to ground when destroyed)
                    x1	used on stuff in egyptian, sevx
                    */
    struct PropRecord *prop;     /*0x10*/
    struct Model *model; /*0x14*/
    // mtx realrot;
    void *runtime_MATRIX0;
    void *runtime_MATRIX1;
    void *runtime_MATRIX2;
    void *runtime_MATRIX3;
    void *runtime_MATRIX4;
    void *runtime_MATRIX5;
    void *runtime_MATRIX6;
    void *runtime_MATRIX7;
    void *runtime_MATRIX8;
    void *runtime_MATRIX9;
    void *runtime_MATRIXA;
    void *runtime_MATRIXB;
    void *runtime_MATRIXC;
    void *runtime_MATRIXD;
    void *runtime_MATRIXE;
    void *runtime_MATRIXF;
    f32 runtime_x_pos;
    f32 runtime_y_pos;
    f32 runtime_z_pos;
    int runtime_bitflags; /*0x64* 
                            10000000	
                            00060000	owner (0-3); used to attribute kills to players
                            00004000	activated
                            00000200	only set with disabled or destroyed doors
                            00000080	depositted (thrown)
                            00000004	removes object when set 
                            */
    int ptr_allocated_collisiondata_block;
    int field_6C;
    float field_70;
    short damage;
    short maxdamage;
    char field_78;
    char field_79;
    char field_7A;
    char field_7B;
    char field_7C;
    char field_7D;
    char field_7E;
    char field_7F;
} ObjectRecord;

/******

 The following struct PropRecord was copied from AIListLogic branch
 and should be removed when merged

 note: only the necessary fields were copied in order to compile (not the full struct)

******/
typedef struct PropRecord
{
  u8 type;
  union
  {
    ObjectRecord *obj;
  } Entityp;
} PropRecord;

typedef struct KeyRecord
{
    ObjectRecord base;
    u32 keyflags;
} KeyRecord;

/* unfinished struct, WIP */
struct chrdata {
    u16 chrnum;
    s8 accuracyrating;
    s8 speedrating;
    u8 firecountleft;
    u8 firecountright;
    s8 headnum;
    s8 actiontype;
    s8 sleep;
    s8 invalidmove;
    s8 numclosearghs;
    s8 numarghs;
    u8 fadealpha;
    s8 arghrating;
    s8 aimendcount;
    s8 bodynum;
    /* 0x0010 */
    u8 grenadeprob;
    s8 flinchcnt;
    u16 hidden;
    s32 chrflags;
    struct prop* posdata;
    void * model;
    /* 0x0020 */
    void * field_20;
    f32 chrwidth;
    f32 chrheight;
    void * bondpos; /* HACK - reused as fadeout counter on death, checks if pointer at 7F02B774 */
    /* 0x0030 */
    int field_30;
    short field_34;
    char field_36;
    char field_37;
    char field_38;
    char field_39;
    char field_3A;
    char field_3B;
    int path_target_position;
    /* 0x0040 */
    int field_40;
    int field_44;
    int field_48;
    int targetflag;
    /* 0x0050 */
    int targettoshoot;
    int field_54;
    char type_of_motion;
    char distance_counter_or_something;
    short distance_to_target;
    int field_5C;
    /* 0x0060 */
    int target_position;
    int field_64;
    int field_68;
    int field_6C;
    /* 0x0070 */
    int path_segment_coverage;
    int path_segment_length;
    int field_78;
    int field_7C;
    /* 0x0080 */
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    /* 0x0090 */
    int field_90;
    int segment_coverage;
    int segment_length;
    int field_9C;
    /* 0x00A0 */
    int field_A0;
    f32 sumground;
    f32 manground;
    f32 ground;
    /* 0x00B0 */
    f32 fallspeed[3];
    f32 prevpos[3];
    /* 0x00B8 */
    s32 lastwalk60;
    s32 lastmoveok60;
    /* 0x00D0 */
    f32 visionrange;
    s32 lastseetarget60;
    f32 lastvisibletarg[3];
    /* 0x00E4 */
    void * field_E4;
    s32 timeshooter;
    f32 hearingscale;
    /* 0x00F0 */
    s32 lastheartarget60;
    u8 shadecol[4];
    u8 nextcol[4];
    f32 damage;
    /* 0x0100 */
    f32 maxdamage;
    void * ailist;
    u16 aioffset;
    u16 aireturnlist;
    u8 flags; /* used by ai commands 81-85 */
    u8 flags2; /* used by ai commands 86-8A */
    u8 BITFIELD;
    u8 random;
    /* 0x0110 */
    s32 timer60;
    s16 padpreset1; /* ID PAD_PRESET */
    u16 chrpreset1; /* ID CHR_PRESET */
    u16 chrseeshot; /* ID CHR_SEE_SHOT - ignores invincible/armoured guards */
    u16 chrseedie; /* ID CHR_SEE_DIE */
    /* 0x011C */
    f32 field_11C[2];
    f32 field_124[2];
    f32 field_12C[2];
    /* 0x0134 */
    int field_134;
    int field_138;
    f32 shotbondsum;
    /* 0x0140 */
    f32 aimuplshoulder;
    f32 aimuprshoulder;
    f32 aimupback;
    f32 aimsideback;
    /* 0x0150 */
    f32 aimendlshoulder;
    f32 aimendrshoulder;
    f32 aimendback;
    f32 aimendsideback;
    /* 0x0160 */
    int * handle_positiondata[2];
    int * ptr_SEbuffer1;
    int * ptr_SEbuffer2;
    /* 0x0170 */
    int * ptr_SEbuffer3;
    int * ptr_SEbuffer4;
    int field_178;
    int field_17C;
    /* 0x0180 */
    char field_180;
    char field_181;
    char field_182;
    char field_183;
    int field_184;
    int field_188;
    int field_18C;
    /* 0x0190 */
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    /* 0x01A0 */
    int field_1A0;
    int field_1A4;
    int field_1A8;
    char field_1AC;
    char field_1AD;
    char field_1AE;
    char field_1AF;
    /* 0x01B0 */
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    /* 0x01C0 */
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    /* 0x01D0 */
    int field_1D0;
    int field_1D4;
    int * handle_positiondata_hat;
};

typedef struct object_standard {
    s16 scale;
    u8 state;
    u8 type;
    u16 objectID;
    u16 presetID;
    u32 flags1;
    u32 flags2;
    void* ptrPOSData;
    void* ptrObjInstanceController;
    f32 runtime_MATRIX[4][4];
    f32 xPOS;
    f32 yPOS;
    f32 zPOS;
    int bitflags;
    int ptrCollisionblock;
    int field_6C;
    float field_70;
    short damage;
    short maxdamage;
    int field_78;
    int field_7C;
} object_standard;

typedef struct object_weapon {
    object_standard object;
    u8 gun_pickup;
    u8 linked_item;
    s16 timer;
    void* ptr_linkeditem;
} object_weapon;

struct watchMenuObjectiveText {
    u32 id;
    enum WATCH_BRIEFING_PAGE menu;
    u16 reserved;
    u16 text;
    struct watchMenuObjectiveText * nextentry;
};
//!FIXME all but text field cannot be trusted
struct objective_entry {
    u32 id;
    enum WATCH_BRIEFING_PAGE menu;
    u16 reserved;
    u16 text;
    struct watchMenuObjectiveText * nextentry;
};

typedef struct sImageTableEntry {
    u32 index;
    u8 width;
    u8 height;
    u8 level;
    u8 format;
    u8 depth;
    u8 flagsS;
    u8 flagsT;
    u8 pad;
} sImageTableEntry;

typedef struct sGlobalImageTable {
    u32 globalDL_0x000[30];
    u32 globalDL_0x078[42];
    u32 globalDL_0x120[42];
    u32 globalDL_0x1c8[42];
    u32 globalDL_0x270[42];
    u32 globalDL_0x318[42];
    u32 globalDL_0x3c0[42];
    u32 globalDL_0x468[42];
    u32 globalDL_0x510[42];
    u32 globalDL_0x5b8[42];
    u32 globalDL_0x660[42];
    u32 globalDL_0x708[42];
    u32 globalDL_0x7b0[42];
    u32 globalDL_0x858[42];
    u32 globalDL_0x900[42];
    u32 globalDL_0x9a8[42];
    u32 globalDL_0xa50[30];
    struct sImageTableEntry s_genericimage[1];
    struct sImageTableEntry s_impactimages[20];
    struct sImageTableEntry s_explosion_smokeimages[6];
    struct sImageTableEntry s_scattered_explosions[5];
    struct sImageTableEntry s_flareimage1[1];
    struct sImageTableEntry s_flareimage2[1];
    struct sImageTableEntry s_flareimage3[1];
    struct sImageTableEntry s_flareimage4[1];
    struct sImageTableEntry s_flareimage5[1];
    struct sImageTableEntry s_ammo9mmimage[1];
    struct sImageTableEntry s_rifleammoimage[1];
    struct sImageTableEntry s_shotgunammoimage[1];
    struct sImageTableEntry s_knifeammoimage[1];
    struct sImageTableEntry s_glammoimage[1];
    struct sImageTableEntry s_rocketammoimage[1];
    struct sImageTableEntry s_genericmineammoimage[1];
    struct sImageTableEntry s_grenadeammoimage[1];
    struct sImageTableEntry s_magnumammoimage[1];
    struct sImageTableEntry s_goldengunammoimage[1];
    struct sImageTableEntry s_remotemineammoimage[1];
    struct sImageTableEntry s_timedmineammoimage[1];
    struct sImageTableEntry s_proxmineammoimage[1];
    struct sImageTableEntry s_tankammoimage[1];
    struct sImageTableEntry s_crosshairimage[1];
    struct sImageTableEntry s_betacrosshairimage[1];
    struct sImageTableEntry s_glassoverlayimage[2];
    struct sImageTableEntry s_monitorimages[50];
    struct sImageTableEntry s_skywaterimages[3];
    struct sImageTableEntry s_mainfolderimages[6];
    struct sImageTableEntry s_mpradarimages[1];
    struct sImageTableEntry s_mpcharselimages[64];
    struct sImageTableEntry s_mpstageselimages[17];
} sGlobalImageTable;



#endif
