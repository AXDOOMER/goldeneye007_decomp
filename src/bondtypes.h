#ifndef _BONDTYPES_H_
#define _BONDTYPES_H_
#include "ultra64.h"
#include "bondconstants.h"
#include "structs.h"
#include "snd.h"
#include "game/chrobjdata.h"

#define _mkshort(a, b) ((a << 8) | (b & 0xff))
#define _mkword(a, b) ((a << 16) | (b & 0xffff))

#define MAX_CHRWAYPOINTS 6

typedef s32 bool;

struct object_standard;
struct ChrRecord;
struct PropRecord;

typedef f32 vec3[3];

// Float version of a graphics matrix, which has higher precision than an Mtx.
// Matrices are stored as Mtxfs then converted to an Mtx when passed to the GPU.
// Mtxs use a union and a long long int to force alignments. Mtxfs are not
// aligned but still use the union for consistency with Mtx.
typedef union {
    f32 m[4][4];
    s32 unused;
} Mtxf;

// This hacky structure allows coords to be accessed using
// coord->x, coord->y and coord->z, but also as
// coord->f[0], coord->f[1] and coord->f[2].
// In some places code only matches when using the float array.
// from discord,
// "It tends to just be multiplications where the array 
//      style is needed for a match. Assigns and reads use the
//      same codegen for x/y/z and arrays"
struct coord3d {
    union {
        struct {
            f32 x;
            f32 y;
            f32 z;
        };
        f32 f[3];
    };
};

struct coord2d {
    union {
        struct {
            f32 x;
            f32 y;
        };
        f32 f[2];
    };
};

struct bbox2d
{
    union {
        struct {
            struct coord2d min;
            struct coord2d max;
        };
        f32 f[2][2];
    };
};

// Same hacky struct here for rgba groups
struct rgba_u8 {
    union {
        struct {
            u8 r;
            u8 g;
            u8 b;
            u8 a;
        };
        u8 rgba[4];
    };
};

struct rgba_f32 {
    union {
        struct {
            f32 r;
            f32 g;
            f32 b;
            f32 a;
        };
        f32 rgba[4];
    };
};

struct bbox
{
    float xmin;
    float xmax;
    float ymin;
    float ymax;
    float zmin;
    float zmax;
};

struct rect4f
{
    union {
        struct coord2d points[4];
        f32 f[8];
    };
};

struct pad
{
    struct coord3d pos;
    struct coord3d up;
    struct coord3d look;
    char *plink;
    struct StandTile *stan;
};

struct pad3d
{
    struct coord3d pos;
    struct coord3d up;
    struct coord3d look;
    char *plink;
    int unk;
    struct bbox bbox;
};

struct s_pathTbl {
    s16 pathtbl;
    s16 field_0x2;
    s32 (*field_0x4)[];
    s32 field_0x8;
    s32 field_0xc;
};

struct s_pathLink {
    void *pathlink;
    void *field_0x4;
    void *field_0x8;
};

struct s_pathSet {
    void *field_0x0;
    s32 field_0x4;
};

struct ailist {
    u32 (*script)[];
    s32 id;
};

// this is something in between struct s_pathTbl and struct waypoint.
// theory: s_pathTbl is correct, waypoint needs to be updated, and then this
// struct can be deprecated (replace with waypoint).
struct path_table_alt
{
    s32 id;
    s32 *neighbours;
    s32 unk08;
    s32 unk0c;
};

struct stagesetup {
    struct s_pathTbl (*pathtbl)[];
    struct s_pathLink (*pathlink)[];
    s32 (*intro)[];
    s32 (*objlist)[];
    struct s_pathSet (*paths)[];
    struct ailist (*ailists)[];
    struct pad (*padlist)[];
    struct pad3d (*pad3dlist)[];
    char *(*padnames)[];
    char *(*pad3dnames)[];
};

//
typedef struct AIRecord
{
    u8 cmd;
    u8 val[];
} AIRecord;

/*
 * Model Root Runtime Data (pos, heading, height etc)
 */
struct modeldata_root
{                       // type 0x01
    u16 unk00;          /*0*/
    u8 unk02;           /*2*/
    f32 ground;         /*4*/
    struct coord3d pos; //8, 12, 16 - this is the right poition for this, but no idea what this node actually is (used in extract_id_from_object_structure_microcode)
    f32 subroty;        //14 angle - this also happens to fit best for getsubroty
    f32 unk18;          /*18*/
    u32 unk1c;          /*1c*/
    f32 unk20;          //20 angle
    struct coord3d unk24;
    f32 unk30; // angle copy of 20
    struct coord3d unk34;
    struct coord3d unk40; // "2" version of unk24
    struct coord3d unk4c; // "2" version of unk34
    f32 unk58;
    f32 unk5c;
};

/**
 * I beleve that "datas" is actually " struct modeldata_root" and that 
 * unk1c is the model node data array
 */
typedef struct Model
{
    u8 unk00;                                               /*0x00*/
    u8 Type;                                               /*0x01*/
    struct ChrRecord *chr;                                    /*0x04*/
    ModelFileHeader *obj;                                /*0x08 GE Name confirmed*/
    Mtxf *unk0c;                                            /*0x0c*/
    void **datas; // array of pointers to modeldata structs /*0x10*/
    f32 scale;                                              /*0x14*/
    struct Model *attachedto;                               /*0x18*/
    ModelNode *unk1c;                                       /*0x1c*/

    // need `struct anim` definition from AI branch.
    void *anim;                                      /*0x20*/

    s8 unk24; // used by ACT_STAND
    s8 unk25;
    s8 unk26;
    s8 unk27;

    f32 unk28;
    s32 unk2c;
    // 0x30
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3c;
    // 0x40
    f32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4c;
    // 0x50
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5c;
    // 0x60
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6c;
    // 0x70
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7c;
    // 0x80
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8c;
    // 0x90
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9c;
    // 0xa0
    s32 unka0;
    f32 unka4; // used by ACT_STAND in chrlv
    s32 unka8;
    s32 unkac;
    // 0xb0
    s32 unkb0;
    s32 unkb4; 
    f32 unkb8; // used by ACT_ANIM in chrlv
    s32 unkbc;
    
} Model;

struct waypoint;

struct waygroup
{
    struct waygroup *neighbours; //offset to an array linking each waygroup
    struct waypoint *waypoints;  //offset to an array of waypoints in this set
    s32 unk08;                   // *set to zero*
};

struct waypoint
{
    s32 PadID;                   // 0xxx ID
    struct waypoint *neighbours; // most significant two bits are booleans, remaining bits are waypoint index.
                                 // points to a series of values connecting each table entry
    struct waygroup *groupnum;          // entry in the linkage table that contains this path entry
    s32 dist_tmp;                //used in game.  set to 0
};                      /*the table ends with a ID = -1*/

struct waydata
{
    /**
     * player.act_gopos.waydata starts at 0x5c.
    */

    s8 mode;                 /*0x00 */
    u8 unk01;                /*0x01 */
    u8 unk02;                /*0x02 */
    u8 unk03;                /*0x03 */

    struct coord3d pos;      /*0x04 */

    // from PD - unverified/unmatched
    struct coord3d pos2;     /*0x10 */

    u32 unk1c;               /*0x1c */
    u32 unk20;               /*0x20 */
    u32 unk24;               /*0x24 */

    // from PD - unverified/unmatched
    s32 age;                 /*0x28 */

    // from PD - unverified/unmatched
    struct coord3d pos_copy; /*0x2c */

    // These are the distances between the current waypoint and the previous
    // when using cheap mode.
    // from PD - unverified/unmatched
    f32 segdistdone;  /*0x38 */

    // from PD - unverified/unmatched
    f32 segdisttotal; /*0x3c */
};

#pragma region ACT_TYPES

struct act_init
{
    int padding[30];
};

struct act_stand
{
    s32 unk02c;                                                        /*0x2c*/
    u32 face_entitytype;                                               /*0x30*/
    s32 face_entityid;                                                 /*0x34*/
    u32 unk038;                                                        /*0x38*/
    s32 unk03c;                                                        /*0x3c*/
    u32 unk040;                                                        /*0x40*/
    u32 unk044;                                                        /*0x44*/
    f32 unk048;                                                        /*0x48*/
    s8 face_target;                                                    /*0x4c*/
};

struct act_kneel
{
    int padding[30];
};

struct act_anim
{
    u32 unk02c;                                                        /*0x2c*/
    u32 unk030;                                                        /*0x30*/
    u32 unk034;                                                        /*0x34*/
    u32 unk038;                                                        /*0x38*/
    u32 unk03c;                                                        /*0x3c*/
    u8 unk040;                                                         /*0x40*/
    u8 unk041;                                                         /*0x41*/
    u16 unk042;                                                        /*0x42*/
    u16 unk044;                                                        /*0x44*/
    u16 unk046;                                                        /*0x46*/
    s16 animnum;                                                       /*0x48*/
    u8 flip;                                                           /*0x4a*/
    f32 startframe;                                                    /*0x4c*/
    f32 endframe;                                                      /*0x50*/
    f32 unk054;                                                        /*0x54*/
    f32 unk058;                                                        /*0x58*/
};

struct act_die
{
    s32 notifychrindex;                                                /*0x2c*/
    f32 thudframe1;                                                    /*0x30*/
    f32 thudframe2;                                                    /*0x34*/
    f32 timeextra;              /* name from PD */                     /*0x38*/
    f32 elapseextra;            /* name from PD */                     /*0x3c*/
    struct coord3d extraspeed;  /* name from PD */                     /*0x40*/
    s16 drcarollimagedelay;                                            /*0x4c*/
};

struct act_dead
{
    bool allowfade;                                                    /*0x2c*/
    bool allowreap;                                                    /*0x30*/
    s32 reaptimer;                                                     /*0x34*/
    s32 fadetimer;                                                     /*0x38*/
    s32 notifychrindex;                                                /*0x3c*/
};

struct act_argh
{
    s32 notifychrindex;                                                /*0x2c*/
    s32 unk030;
};

struct act_preargh
{
    struct coord3d pos;                                                  /*0x2c vec*/
    f32 unk038;                                                        /*0x38 relshotangle*/
    s32 unk03c;                                                        /*0x3c hitpart*/
    s32 unk040;                                                        /*0x40 weaponid*/
    u32 unk044;                                                        /*0x44*/
};

struct act_attack
{
    f32 *unk02c;                                                       /*0x2c*/
    
    u16 unk030;                                                        /*0x30*/
    u8 unk032;                                                         /*0x32*/
    s8 unk033;                                                         /*0x33*/
    
    s8 unk034;                                                         /*0x34*/
    u8 unk035;                                                         /*0x35*/
    s8 unk036;                                                         /*0x36*/
    s8 unk037;

    u32 unk038;                                                        /*0x38*/
    u32 unk03c;                                                        /*0x3c*/
    u32 unk040;                                                        /*0x40*/
    u32 unk044;                                                        /*0x44*/
    u32 unk048;                                                        /*0x48*/
    u32 attacktype;                                                    /*0x4c*/
    u32 entityid;                                                      /*0x50*/
    u32 unk054;                                                        /*0x54*/
    bool type_of_motion;                                                /*0x58 reaim*/
};

struct act_attackwalk
{
    u32 unk02c;                                                        /*0x2c*/
    u32 unk030;                                                        /*0x30*/
    u32 unk034;                                                        /*0x34*/
    u32 unk038;                                                        /*0x38*/
    struct weapon_firing_animation_table *animfloats;                                     /*0x3c*/
    u32 unk040;                                                        /*0x40*/
    u32 unk044;                                                        /*0x44*/
    u32 unk048;                                                        /*0x48*/
    u16 unk04c;                                                        /*0x4c*/
    u8 flip;                                                           /*0x4e*/
};

struct act_attackroll
{
    struct weapon_firing_animation_table *animfloats;                                     /*0x2c*/
    u32 unk030;                                                        /*0x30*/
    u8 unk034;                                                         /*0x34*/
    s8 unk035;                                                         /*0x35*/
    s8 unk036;                                                         /*0x36*/
    u32 unk038;                                                        /*0x38*/
    u16 unk03c;                                                        /*0x3c*/
    s8 flip;                                                           /*0x3e*/
};

struct act_sidestep
{
    bool side;                                                         /*0x2c*/
};

struct act_jumpout
{
    bool side;                                                         /*0x2c*/
};

struct act_runpos
{
    struct coord3d pos;                                                  /*0x2c*/
    f32 unk038;                                                        /*0x38*/
    s32 unk03c;                                                        /*0x3c*/
    f32 unk040;                                                        /*0x40*/
};

struct act_patrol
{
    s32 *path;                                                /*0x02c*/
    s32 nextstep;                                                     /*0x030*/
    bool forward;                                                     /*0x034*/
    struct waydata waydata;                                           /*0x038*/
    s32 unk78;
    f32 unk7c;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8c;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9c;
    s32 unka0;
};

struct act_gopos
{
    struct coord3d targetpos;  // Target pos                           /*0x02c*/
    struct StandTile *target; // Target/final waypoint                  /*0x038*/

    struct path_table_alt * target_path;                                      /*0x03c*/

    // Array of pointers to the next couple of waypoints. Recalculated each time
    // a waypoint is reached, and probably even more frequently than that.
    struct path_table_alt *waypoints[MAX_CHRWAYPOINTS];         /*0x040*/

    // Index of the waypoint in the above array that the chr is running to. If
    // the chr has line of sight (through doors) to the next or next + 1 then
    // the index can be changed to that one and the chr will run straight to it.
    // This index will always be 0, 1 or 2. When it reaches 3 the pathfinding is
    // recalculated, the array replaced with a new one and index set to 0.
    /* player offset 0x58 */
    u8 curindex;
    u8 unk59;  // guess: room

    // g_ClockTimer related
    u16 unk5a;

    // offset 0x5c
    struct waydata waydata;

    s32 unk9c;

    f32 unka0;

    // PD reference below:

    // Array of pointers to the next couple of waypoints. Recalculated each time
    // a waypoint is reached, and probably even more frequently than that.
    // struct waypoint *waypoints[5]; // MAX_CHRWAYPOINTS];               /*0x040*/

    // Index of the waypoint in the above array that the chr is running to. If
    // the chr has line of sight (through doors) to the next or next + 1 then
    // the index can be changed to that one and the chr will run straight to it.
    // This index will always be 0, 1 or 2. When it reaches 3 the pathfinding is
    // recalculated, the array replaced with a new one and index set to 0.
    //u8 curindex;                                                       /*0x054*/

    // x....... = walking directly to pad due to PADFLAG_AIWALKDIRECT
    // .x...... = ducking due to PADFLAG_AIDUCK
    // ....x... = on preset path
    // ......xx = speed
    //u8 flags;                                                          /*0x055*/
    //u16 restartttl;                                                    /*0x056*/

    //struct waydata waydata;                                            /*0x058*/
    ///////////////////////////////////////////
    // u8 mode;                 /*0x00 58*/
    // u8 unk01;                /*0x01 59*/
    // u16 unk02;               /*0x02 5a*/
    // struct coord3d pos;      /*0x04 5c*/
    // struct coord3d pos2;     /*0x10 68*/
    // u32 unk1c;               /*0x1c 74*/
    // u32 unk20;               /*0x20 78*/
    // u32 unk24;               /*0x24 7c*/
    // s32 age;                 /*0x28 80*/
    // struct coord3d pos_copy; /*0x2c 84*/

    // // These are the distances between the current waypoint and the previous
    // // when using cheap mode.
    // f32 segdistdone;  /*0x38 90*/
    // f32 segdisttotal; /*0x3c 94*/
    ///////////////////////////////////////////

    //s32 cheapend60; // lvframe60 time that the chr exited cheap method of wayfinding /*0x098*/ 
    //f32 unk0ac;                                                        /*0x09c*/
};
struct act_surrender
{
    int padding[30];
};

struct act_lookattarget
{
    int padding[30];
};

struct act_surprised
{
    u32 type;                                                          /*0x2c*/
};

struct act_startalarm
{
    int padding[30];
};

struct act_throwgrenade
{
    u32 entitytype;                                                    /*0x2c*/
    u32 entityid;                                                      /*0x30*/
    u32 hand;                                                          /*0x34*/
    bool needsequip;                                                   /*0x38*/
};

struct act_turndir
{
    int padding[30];
};

struct act_test
{
    int padding[30];
};

struct act_bondintro
{
    int padding[30];
};

struct act_bonddie
{
    int padding[30];
};

struct act_bondmulti
{
    int padding[30];
};

struct act_null
{
    int padding[30];
};

struct act_bytes
{
    s8 padding[120];
};

struct act_ubytes
{
    u8 padding[120];
};

#pragma endregion


/******

 The following struct PropRecord was copied from AIListLogic branch
 and should be removed when merged

 note: only the necessary fields were copied in order to compile (not the full struct)

******/
typedef struct PropRecord
{
    // PROP_TYPE or PROPDEF_TYPE
    u8 type;         /*0x00*/
    u8 flags;        /*0x01*/
    s16 timetoregen; // ticks down /*0x02*/
    union
    {
        struct ChrRecord *chr;
        struct ObjectRecord *obj;
        struct DoorRecord *door;
        struct WeaponObjRecord *weapon;
        void *explosion;
        void *smoke;
        void *voidp;
    };                         /*0x04*/
    struct coord3d pos;                 /*0x08*/
    struct StandTile *stan;           /*0x14 name confirmed?*/
    void *Unk18;                 /*0x18*/
    struct PropRecord *parent;   /*0x1c*/
    struct PropRecord *child; /*0x20*/
    struct PropRecord *prev;   /*0x24*/
    struct PropRecord *next;  /*0x28*/
    s16 rooms[2];              /*0x2c* /
    u16 unk38;         /*0x38* /
    s16 unk3a;         /*0x3a* /
    u8 unk3c;          /*0x3c* /
    u8 propstateindex; /*0x3d* /
    u8 unk3e;          /*0x3e* /
    u8 unk3f_00 : 1;   /*0x3f* /
    u8 unk3f_01 : 1;   /*0x3f* /
    u8 unk3f_02 : 1;   /*0x3f* /
    u8 unk3f_03 : 1;   /*0x3f* /
    u8 unk3f_04 : 1;   /*0x3f* /
    u8 unk3f_05 : 1;   /*0x3f* /
    u8 unk3f_06 : 1;   /*0x3f* /
    u8 unk3f_07 : 1;   /*0x3f* /
    u32 unk40;         /*0x40* /
    u32 unk44;         /*0x44*/
} PropRecord;

/* unfinished struct, WIP */
typedef struct ChrRecord
{
    s16 chrnum;                           /* 0x0000 */
    s8 accuracyrating;                    /* 0x0002 */
    s8 speedrating;                       /* 0x0003 */          //0-100
    u8 firecount[2];                      /* 0x0004 */
    s8 headnum;                           /* 0x0006 */
    ACT_TYPE actiontype : 8; /* 0x0007 */ //force 8bit
    s8 sleep;                             /* 0x0008 */
    s8 invalidmove;                       /* 0x0009 */
    s8 numclosearghs;                     /* 0x000A */
    s8 numarghs;                          /* 0x000B */
    u8 fadealpha;                         /* 0x000C */
    s8 arghrating;                        /* 0x000D */
    s8 aimendcount;                       /* 0x000E */
    s8 bodynum;                           /* 0x000F */
    u8 grenadeprob;                       /* 0x0010 */
    s8 flinchcnt;                         /* 0x0011 */
    u16 hidden;                           /* 0x0012 */
    s32 chrflags;                     /* 0x0014 */
    PropRecord *prop;                     /* 0x0018 */
    Model *model;                         /* 0x001C */
    /* 0x0020 */
    void *field_20; /* 0x0020 */ //path?
    f32 chrwidth;                /* 0x0024 */
    f32 chrheight;               /* 0x0028 */
    union
    {
        struct act_init act_init;
        struct act_stand act_stand;
        struct act_kneel act_kneel;
        struct act_anim act_anim;
        struct act_die act_die;
        struct act_dead act_dead;
        struct act_argh act_argh;
        struct act_preargh act_preargh;
        struct act_attack act_attack;
        struct act_attackwalk act_attackwalk;
        struct act_attackroll act_attackroll;
        struct act_sidestep act_sidestep;
        struct act_jumpout act_jumpout;
        struct act_runpos act_runpos;
        struct act_patrol act_patrol;
        struct act_gopos act_gopos;
        struct act_surrender act_surrender;
        struct act_lookattarget act_lookattarget;
        struct act_surprised act_surprised;
        struct act_startalarm act_startalarm;
        struct act_throwgrenade act_throwgrenade;
        struct act_turndir act_turndir;
        struct act_test act_test;
        struct act_bondintro act_bondintro;
        struct act_bonddie act_bonddie;
        struct act_bondmulti act_bondmulti;
        struct act_null act_null;
        struct act_bytes act_bytes;
        struct act_ubytes act_ubytes;
    };
    f32 sumground;              /*0xA4*/
    f32 manground;              /*0xA8*/
    f32 ground;                 /*0xAC*/
    struct coord3d fallspeed;          /*0xB0 current pos*/
    struct coord3d prevpos;            /*0xBC*/
    s32 lastwalk60;             /*0xC8*/
    s32 lastmoveok60;           /*0xCC*/
    f32 visionrange;            /*0xD0*/
    s32 lastseetarget60;        /*0xD4*/
    struct coord3d lastknowntargetpos; /*0xD8 confirmed*/
    void *targetTile;           /*0xE4*/
    
    /*0xE8 */
    union {
        s32 seen_bond_time;
        struct {
            s16 lastshooter;            /*0xE8 */
            s16 timeshooter;            /*0xEA*/
        };
    };
    f32 hearingscale;           /*0xEC increases when shot at*/
    s32 lastheartarget60;       /*0xF0 increases after hearing bond (NOTE s32 not u32) */
    /* this next block MUST exist here */
    u8 shadecol[4];   /*0xF4 stan colour eg, white = 0,0,0,0, grey = 0,0,0,64, black = 0,0,0,128, red = 255,0,0,128*/
    u8 nextcol[4];    /*0xF8 (allows gradual transition) Stan colour is applied via "FOG" colour reg*/
    f32 damage;       /* 0x00FC confirmed*/
    f32 maxdamage;    /* 0x0100 confirmed*/
    AIRecord *ailist;       /* 0x0104 confirmed*/
    u16 aioffset;     /* 0x0108 confirmed*/
    s16 aireturnlist; /* 0x010A confirmed*/
    u8 morale;        /* used by ai commands 81-85 */
    u8 alertness;     /* used by ai commands 86-8A */
    u8 BITFIELD;
    u8 random;
    s32 timer60;      /* 0x0110 */
    s16 padpreset1;   /* ID PAD_PRESET */
    s16 chrpreset1;   /* ID CHR_PRESET */
    s16 chrseeshot;   /* ID CHR_SEE_SHOT - ignores invincible/armoured guards */
    s16 chrseedie;    /* ID CHR_SEE_DIE */
                      /* 0x011C */
    /**
     * Four pairs are:
     * - Stans? head
     * - yminmax
     * - xz
     * - width
     * Offset 0x011c.
     */
    struct rect4f collision_bounds;

    /* 0x013c */
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
    // this section needs work, see:
    // - sub_GAME_7F02BFE4
    // - disable_sounds_attached_to_player_then_something
    // there should be some ALSoundState * pointers in here.
    //
    PropRecord *weapons_held[3]; /* handle_positiondata 0x0160 0x0164  0x0168 Right, Left, Hat*/
    s8 fireslot[2];                          /* 0x016C 0x0170*/
    int *ptr_SEbuffer3;
    int *ptr_SEbuffer4;
    int field_178[2];
    //int field_17C;

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
    PropRecord *handle_positiondata_hat;
} ChrRecord;
// ChrRecord *pChrData; //not Global, local to Object or function





/******

 The following struct ObjHeaderData was copied from AIListLogic branch
 and should be removed when merged

******/
typedef struct ObjHeaderData
{
    u16 extrascale; /*0x0 Fixed-Point format u8.8 eg: 0x03.80 = 3.5*/
    u8 hidden2;     // state - Destroyed, respawn, defused etc /*0x2*/
                    /*
                    8x    destroyed
                    4x    datathief/defuser/decoder used on obj (activated?)
                    2x
                    1x
                    x8    external allocated collision block present
                    x4    respawn enabled
                    x2
                    x1    damaged*/
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
                    8x    indicates right-handed gun assignment
                    4x    08 weapon does not provide ammunition when collected
                    2x    indicates object in motion or special function is activated
                    1x    indicates left-handed normal pickup or opposite alignment
                    0x    indicates no control features set
                    x8
                    x4    (unknown) Jungle bushes
                    x2    (unknown) pete grenade
                    x1    indicates embedded crate or other object, creating a chain of boxes, for
                    example      x0    indicates normal preset, or beginning/end of chain
                    Doors:
                    8x    open by default
                    4x    area behind door is always visible (no blackouts for gates, lab doors, etc)
                    2x    open backwards
                    1x    same as 0 as far as I can tell
                    x8    always open away from the player regardless what side you're on
                    x4
                    x2    player can't activate door (spawn block or 16 type activation)
                    x1
                    0x9:
                    8x
                    4x    immobile
                    2x    (unknown) Silo DAT tape
                    1x    uncollectable
                    x8
                    x4    allows object pickup (chr_name objects only)
                    x2    invincibility
                    x1
                    0xA:
                    8x    indicates contained within another object (forward or back # objects = preset value)
                    4x    indicates object does not use normal presets but is assigned to guard #preset
                    2x    (unknown) part of forced collectable objects
                    1x    think this sets object to absolute position.  (similar to 2xxx type)
                    x8    something to do with free-standing glass (glass walls)
                    x4    (unknown) streets buildings/roadblocks
                    x2    seems to align image to preset values for glass
                    x1    force collisions (2xxx presets, mostly)
                    0xB:
                     0xxx presets:
                        00    default, on ground
                        x1    forced to ground
                        x2    room upper limit, rotated y 90 degrees.  top faces direction, front faces up
                        x4    room upper limit, upside-down
                        x8    room upper limit, right side up
                    2xxx presets:
                        x1    normal placement
                        x2    rotated y 90 degrees.  top faces direction, front faces up. (use on obj 68-6B)
                        x4    upside-down
                        x8    in-air
                        1x    scale object to fit completely within preset bounds
                        2x    x set to preset bounds
                        4x    y set to preset bounds
                        8x    z set to preset bounds
                    */
    u32 flags2;       /*0xC:
                    8x    force maximum explosion radius/disable detecting
                         player
                    4x    autoturrets: reset to default, not preset position
                    2x    no AI interaction
                    1x    1-way lock (back)
                    x8    1-way lock (front)
                    x4
                    x2    Objects (rockets, mines, etc) do not collide with object
                    x1    don't load 4 player
                    0xD:
                    8x    don't load 3 player
                    4x    don't load 2 player
                    2x    immune to explosions (only gunfire damages object)
                    1x    bulletproof
                    x8    invisible! can't shoot, but can hit with rockets, bugs, etc.  not counted as a hit
                    x4
                    x2    (unknown) streets buildings
                    x1
                    0xE:
                    8x    Can fire through object
                    4x    immune to gunfire (Only explosives damage object)
                    2x    Remove from game when destroyed (anything on top doesn't fall off!  Just Poof! gone)
                    1x
                    x8    only activate at close range
                    x4
                    x2    explode on contact with tank?
                    x1    (unknown) jungle bush
                    0xF:
                    8x    don't load on 007
                    4x    don't load on 00 agent
                    2x    don't load on secret agent
                    1x    don't load on agent
                    x8    don't load multiplayer (difficulty = -1)
                    x4    disable activation text
                    x2    lightweight (previous: 2xxx drops to ground when destroyed)
                    x1    used on stuff in egyptian, sevx
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
                            00060000    owner (0-3); used to attribute kills to players
                            00004000    activated
                            00000200    only set with disabled or destroyed doors
                            00000080    depositted (thrown)
                            00000004    removes object when set
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
// objtype 1
typedef struct DoorRecord
{
    ObjectRecord base;
   /* GE Door maybe different to PD?
    80:	linked with other doors (4 bytes)
        if used, uses # objects up/down to other door.
        when this object activates, targetted object also activates
        you usually want both doors to point at each other, obviously
    84:	distance door travels when opening/closing (total%)
    88:	distance before door loses collisions (total%)
    00150000 -> 41a80000
    8C:	open/close accelleration rate
    90:	rate used when someone activates a door as it opens/closes
    0100 -> 3B800000
    94:	open/close max speed
    1999 -> 3DCCC800
    note:	*speed sets the speed the door opens at.
        the two rate features affect how long it takes to reach this max speed.
    98:	open technique (2+2 bytes)
        0000 0000	slider (left/right) clears the door away as it slides, stopping visual problems when opening into a wall
        0004 0000	slider (left/right)
        0000 0004	shutter (up/down) clears the door as it slides
        0004 0004	shutter (up/down)
        0000 0005	special (swinging) defined here
        0000 0006	special (eye) defined here in block
        0000 0007	special (iris) defined here
    9F:	nonzero to lock
    A0:	amount of ms door remains open
    A7:	opening sound effect
    A8:	runtime - (float)
    AC:	runtime - (float)
    B0:	runtime - (float)
    B4:	runtime - (float) current distance travelled
    B8:	runtime - (float)
    BC:	runtime -
    BD:	runtime -
    C8:	runtime -
    CC:	runtime - p->vertex buffer when door does not clear
    F0:	runtime -
    F4:	runtime -
    F8:	runtime - */

    s32 linkedDoorOffset;    /*0x80*/

    /**
     * Distance door travels when opening/closing (total%).
     * Offset 0x84.
     */
    f32 maxFrac;

    /**
     * Distance before door loses collisions (total%) (vertical height % until Bond can walk through).
     * Offset 0x88.
     */
    f32 perimFrac;

    /**
     * Start moving acceleration rate (when a door is first opened/closed).
     * Offset 0x8c.
     */
    f32 accel;

    /**
     * Start slowing down acceleration rate (when a door is almost entirely opened/closed).
     * Offset 0x90.
     */
    f32 decel;

    /**
     * Maximum speed door can move on each update.
     * Offset 0x94.
     */
    f32 maxSpeed;

    /**
     * open technique (2+2 bytes).
     *
     *  0000 0000	slider (left/right) clears the door away as it slides, stopping visual problems when opening into a wall
     *  0004 0000	slider (left/right)
     *  0000 0004	shutter (up/down) clears the door as it slides
     *  0004 0004	shutter (up/down)
     *  0000 0005	special (swinging) defined here
     *  0000 0006	special (eye) defined here in block
     *  0000 0007	special (iris) defined here
     *
     * Offset 0x98.
     */
    u16 doorFlags;

    /**
     * See doorFlags.
     * Offset 0x9a.
     */
    u16 doorType;

    /**
     * nonzero to lock.
     * Offset 0x9c.
     */
    u32 keyflags;

    /**
     * Number of frames the door remains open before closing.
     * Offset 0xa0.
     */
    u32 autoCloseFrames;

    /**
     * Sound effect played when the door is opened.
     * (Actually sets the initial open, continued opening, and final open sounds).
     * Offset 0xa4.
     */
    u32 doorOpenSound;

    /**
     * Max fraction open, aka max displacement.
     * Offset 0xa8.
     */
    u32 frac;

    u32 unkac;               /*0xac*/
    u32 unkb0;               /*0xb0*/

    /**
     * Current distance travelled, aka displacement percent.
     * Offset 0xb4.
     */
    f32 openPosition;

    /**
     * Current speed of the door as it is opening or closing.
     * Offset 0xb8.
     */
    f32 speed;

    /**
     * Current open/close/other state of the door.
     * States are defined in enum DOORSTATE, but asm expects a single byte.
     * Offset 0xbc.
     */
    s8 state;

    u8 unkbd;                       /*0xbd*/
    s16 unkbe;                      /*0xbe*/
    s32 unkc0;                      /*0xc0*/
    s16 unkc4;                      /*0xc4*/
    s8 soundType;                   /*0xc6*/
    s8 fadeTime60;                  /*0xc7*/

    /**
    * Connected door. Opening/closing this door will also open the linkedDoor.
    * Offset 0xc8.
    */
    struct DoorRecord *linkedDoor;

    u8 laserFade;                   /*0xcc*/
    u8 unkcd;
    s16 unkce;
    u32 unkd0;
    u32 unkd4;
    u32 unkd8;
    u32 unkdc;
    u32 unke0;
    u32 unke4;
    u32 unke8;

    /**
     * When the door completely opens, the current global timer value is
     * copied into this property. Once autoCloseFrames have elapsed
     * (once the difference between the timer and this value has exceeded autoCloseFrames)
     * the door will start closing.
     * Offset 0xec.
     */
    u32 openedTime;

    /**
     * Portal number.
     * Offset 0xf0.
     */
    u32 portalNumber;

    /**
     * Unknown. Changes at runtime. Appears to be set to a pointer
     * while the door is moving, then cleared when the door is stationary.
     * If you reset this to 0 (NULL pointer), then the door opening
     * sound never stops playing.
     */
    u32* unkf4;

    u32 unkf8;

    /**
     * Copy of global timer value.
     * Offset 0xfc.
     */
    u32 timer;
} DoorRecord;




/******

 The following struct PropRecord was copied from AIListLogic branch
 and should be removed when merged

******/
typedef struct WeaponObjRecord
{
    ObjectRecord base;
    s8 weaponnum;        /*0x80*/
    s8 LinkedWeaponType; /*0x81*/
    s16 timer;           /*0x82*/
    //u8 thrown;        // Dragon and Laptop Gun /*0x83*/
    // s8 unk60;         /*0x60*/
    //s8 dualweaponnum; /*0x61*/

    /**
     * Appears to have multiple uses:
     * Grenades = timer?
     * Proxy mines = timer? Or isarmed
     * CTC briefcase = team index
     */
    //s16 unk62; /*0x62*/

    struct WeaponObjRecord *dualweapon; // other weapon when dual wielding /*0x84*/
} WeaponObjRecord;

typedef struct KeyRecord
{
    ObjectRecord base;
    u32 keyflags;
} KeyRecord;


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

typedef struct ExplosionDetailsRecord {
    s16 TypeID;
    s16 Seed[6];
} ExplosionDetailsRecord;

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

typedef struct CreditsEntry_s {
    u16 TextId1;
    u16 TextId2;
    s16 Position1;

    /**
     * See CREDITS_ALIGNMENT.
    */
    u16 Alignment1;

    s16 Position2;

    /**
     * See CREDITS_ALIGNMENT.
    */
    u16 Alignment2;

} CreditsEntry;

#endif
