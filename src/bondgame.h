#ifndef _BOND_H_
#define _BOND_H_
#include "ultra64.h"

extern u16 cfb_16_a[];
extern u16 cfb_16_b[];

extern u32 *_codeSegmentStart;
extern u32 *_codeSegmentEnd;
extern u32 *_codeSegmentRomStart;
extern u32 *_codeSegmentRomEnd;

extern u32 *_csegmentSegmentStart;
extern u32 *_csegmentSegmentEnd;
extern u32 *_cdataSegmentRomStart;
extern u32 *_cdataSegmentRomEnd;

extern u32 *_rarezipSegmentVaddrStart;
extern u32 *_rarezipSegmentVaddrEnd;
extern u32 *_rarezipSegmentRomStart;
extern u32 *_rarezipSegmentRomEnd;

extern u32 *_gameSegmentVaddrStart;
extern u32 *_gameSegmentVaddrEnd;
extern u32 *_gameSegmentRomStart;
extern u32 *_gameSegmentRomEnd;


extern u8 sp_boot[];
extern u8 sp_rmon[];
extern u8 sp_idle[];
extern u8 sp_shed[];
extern u8 sp_main[];
extern u8 sp_audi[];
extern u8 sp_debug[];

struct rgba_val{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

typedef u16 PAD;

#define SECS_TO_TICK60(SECS) (SECS * 60)
#define MINS_TO_TICK60(MINS) (SECS_TO_TICK60(MINS * 60))

#define OBJECTIVES_MAX 10

typedef enum MISSION_BRIEFING {
    BRIEF_OVERVIEW = 0,
    BRIEF_M,
    BRIEF_Q,
    BRIEF_MONEYPENNY
} MISSION_BRIEFING;

typedef enum DIFFICULTY {
    DIFFICULTY_AGENT = 0,
    DIFFICULTY_SECRET,
    DIFFICULTY_00,
    DIFFICULTY_007,
    DIFFICULTY_MULTI = 0xFFFFFFFF
} DIFFICULTY;

typedef enum LEVELID {
    LEVELID_BUNKER1 = 0x9,
    LEVELID_SILO = 0x14,
    LEVELID_STATUE = 0x16,
    LEVELID_CONTROL = 0x17,
    LEVELID_ARCHIVES = 0x18,
    LEVELID_TRAIN = 0x19,
    LEVELID_FRIGATE = 0x1A,
    LEVELID_BUNKER2 = 0x1B,
    LEVELID_AZTEC = 0x1C,
    LEVELID_STREETS = 0x1D,
    LEVELID_DEPOT = 0x1E,
    LEVELID_COMPLEX = 0x1F,
    LEVELID_EGYPT = 0x20,
    LEVELID_DAM = 0x21,
    LEVELID_FACILITY = 0x22,
    LEVELID_RUNWAY = 0x23,
    LEVELID_SURFACE = 0x24,
    LEVELID_JUNGLE = 0x25,
    LEVELID_TEMPLE = 0x26,
    LEVELID_CAVERNS = 0x27,
    LEVELID_CITADEL = 0x28,
    LEVELID_CRADLE = 0x29,
    LEVELID_SHO = 0x2A,
    LEVELID_SURFACE2 = 0x2B,
    LEVELID_ELD = 0x2C,
    LEVELID_BASEMENT = 0x2D,
    LEVELID_STACK = 0x2E,
    LEVELID_LUE = 0x2F,
    LEVELID_LIBRARY = 0x30,
    LEVELID_RIT = 0x31,
    LEVELID_CAVES = 0x32,
    LEVELID_EAR = 0x33,
    LEVELID_LEE = 0x34,
    LEVELID_LIP = 0x35,
    LEVELID_CUBA = 0x36,
    LEVELID_WAX = 0x37,
    LEVELID_PAM = 0x38,
    LEVELID_MAX = 0x39,
    LEVELID_TITLE = 0x5A,
    LEVELID_NONE = 0xFFFFFFFF
} LEVELID;

typedef enum LEVEL_SOLO_SEQUENCE
{
    SP_LEVEL_DAM = 0x1,
    SP_LEVEL_FACILITY,
    SP_LEVEL_RUNWAY,
    SP_LEVEL_SURFACE1,
    SP_LEVEL_BUNKER1,
    SP_LEVEL_SILO,
    SP_LEVEL_FRIGATE,
    SP_LEVEL_SURFACE2,
    SP_LEVEL_BUNKER2,
    SP_LEVEL_STATUE,
    SP_LEVEL_ARCHIVES,
    SP_LEVEL_STREETS,
    SP_LEVEL_DEPOT,
    SP_LEVEL_TRAIN,
    SP_LEVEL_JUNGLE,
    SP_LEVEL_CONTROL,
    SP_LEVEL_CAVERNS,
    SP_LEVEL_CRADLE,
    SP_LEVEL_AZTEC,
    SP_LEVEL_EGYPT
} LEVEL_SOLO_SEQUENCE;

typedef enum LEVEL_INDEX
{
    LEVEL_INDEX_SEVBUNKER = 0x0,
    LEVEL_INDEX_SILO = 0x1,
    LEVEL_INDEX_STATUE = 0x2,
    LEVEL_INDEX_CONTROL = 0x3,
    LEVEL_INDEX_ARCH = 0x4,
    LEVEL_INDEX_TRA = 0x5,
    LEVEL_INDEX_DEST = 0x6,
    LEVEL_INDEX_SEVB = 0x7,
    LEVEL_INDEX_AZT = 0x8,
    LEVEL_INDEX_PETE = 0x9,
    LEVEL_INDEX_DEPO = 0xA,
    LEVEL_INDEX_REF = 0xB,
    LEVEL_INDEX_CRYP = 0xC,
    LEVEL_INDEX_DAM = 0xD,
    LEVEL_INDEX_ARK = 0xE,
    LEVEL_INDEX_RUN = 0xF,
    LEVEL_INDEX_SEVX = 0x10,
    LEVEL_INDEX_JUN = 0x11,
    LEVEL_INDEX_DISH = 0x12,
    LEVEL_INDEX_CAVE = 0x13,
    LEVEL_INDEX_CAT = 0x14,
    LEVEL_INDEX_CRAD = 0x15,
    LEVEL_INDEX_SHO = 0x16,
    LEVEL_INDEX_SEVXB = 0x17,
    LEVEL_INDEX_ELD = 0x18,
    LEVEL_INDEX_IMP = 0x19,
    LEVEL_INDEX_ASH = 0x1A,
    LEVEL_INDEX_LUE = 0x1B,
    LEVEL_INDEX_AME = 0x1C,
    LEVEL_INDEX_RIT = 0x1D,
    LEVEL_INDEX_OAT = 0x1E,
    LEVEL_INDEX_EAR = 0x1F,
    LEVEL_INDEX_LEE = 0x20,
    LEVEL_INDEX_LIP = 0x21,
    LEVEL_INDEX_LEN = 0x22,
    LEVEL_INDEX_WAX = 0x23,
    LEVEL_INDEX_PAM = 0x24,
    LEVEL_INDEX_X = 0x25
} LEVEL_INDEX;

/* language file to slot allocation */
#define TEXT(TEXTBANK, TEXTSLOT) ((TEXTBANK * 0x0400U) + TEXTSLOT)

typedef enum TEXTBANK_LEVEL_INDEX
{
    LNULL = 0,   /* Null (unused) */
    LAME,        /* Library (multi) */
    LARCH,       /* Archives */
    LARK,        /* Facility */
    LASH,        /* Stack (multi) */
    LAZT,        /* Aztec */
    LCAT,        /* Citadel (multi) */
    LCAVE,       /* Caverns */
    LAREC,       /* Control */
    LCRAD,       /* Cradle */
    LCRYP,       /* Egypt */
    LDAM,        /* Dam */
    LDEPO,       /* Depot */
    LDEST,       /* Frigate */
    LDISH,       /* Temple (multi) */
    LEAR,        /* Ear (unused) */
    LELD,        /* Eld (unused) */
    LIMP,        /* Basement (multi) */
    LJUN,        /* Jungle */
    LLEE,        /* Lee (unused) */
    LLEN,        /* Cuba */
    LLIP,        /* Lip (unused) */
    LLUE,        /* Lue (unused) */
    LOAT,        /* Cave (multi) */
    LPAM,        /* Pam (unused) */
    LPETE,       /* Streets */
    LREF,        /* Complex (multi) */
    LRIT,        /* Rit (unused) */
    LRUN,        /* Runway */
    LSEVB,       /* Bunker 2 */
    LSEV,        /* Bunker 1 */
    LSEVX,       /* Surface 1 */
    LSEVXB,      /* Surface 2 */
    LSHO,        /* Sho (unused) */
    LSILO,       /* Silo */
    LSTAT,       /* Statue */
    LTRA,        /* Train */
    LWAX,        /* Wax (unused) */
    LGUN,        /* Guns */
    LTITLE,      /* Stage and menu titles */
    LMPMENU,     /* Multi menus */
    LPROPOBJ,    /* In-game pickups */
    LMPWEAPONS,  /* Multi weapon select */
    LOPTIONS,    /* Solo in-game menus */
    LMISC        /* Cheat options */
} TEXTBANK_LEVEL_INDEX;

typedef enum MP_STAGE_SELECTED {
    MP_STAGE_RANDOM = 0x0,
    MP_STAGE_TEMPLE = 0x1,
    MP_STAGE_COMPLEX = 0x2,
    MP_STAGE_CAVES = 0x3,
    MP_STAGE_LIBRARY = 0x4,
    MP_STAGE_BASEMENT = 0x5,
    MP_STAGE_STACK = 0x6,
    MP_STAGE_FACILITY = 0x7,
    MP_STAGE_BUNKER = 0x8,
    MP_STAGE_ARCHIVES = 0x9,
    MP_STAGE_CAVERNS = 0xA,
    MP_STAGE_EGYPT = 0xB
} MP_STAGE_SELECTED;

typedef enum GENDER {FEMALE=0, MALE } GENDER;

typedef enum BODIES {
    BODY_Jungle_Commando = 0x0,
    BODY_St_Petersburg_Guard = 0x1,
    BODY_Russian_Soldier = 0x2,
    BODY_Russian_Infantry = 0x3,
    BODY_Janus_Special_Forces = 0x4,
    BODY_Tuxedo = 0x5,
    BODY_Boris = 0x6,
    BODY_Ourumov = 0x7,
    BODY_Trevelyan_Janus = 0x8,
    BODY_Trevelyan_006 = 0x9,
    BODY_Valentin_ = 0xA,
    BODY_Xenia = 0xB,
    BODY_Baron_Samedi = 0xC,
    BODY_Jaws = 0xD,
    BODY_Mayday = 0xE,
    BODY_Oddjob = 0xF,
    BODY_Natalya_Skirt = 0x10,
    BODY_Janus_Marine = 0x11,
    BODY_Russian_Commandant = 0x12,
    BODY_Siberian_Guard_1_Mishkin = 0x13,
    BODY_Naval_Officer = 0x14,
    BODY_Siberian_Special_Forces = 0x15,
    BODY_Special_Operations_Uniform = 0x16,
    BODY_Formal_Wear = 0x17,
    BODY_Jungle_Fatigues = 0x18,
    BODY_Parka = 0x19,
    BODY_Unused_Female = 0x1A,
    BODY_Rosika = 0x1B,
    BODY_Scientist_2_Female = 0x1C,
    BODY_Civilian_1_Female = 0x1D,
    BODY_Unused_Male_1 = 0x1E,
    BODY_Unused_Male_2 = 0x1F,
    BODY_Civilian_4 = 0x20,
    BODY_Civilian_2 = 0x21,
    BODY_Civilian_3 = 0x22,
    BODY_Scientist_1_Male = 0x23,
    BODY_Helicopter_Pilot = 0x24,
    BODY_Siberian_Guard_2 = 0x25,
    BODY_Arctic_Commando = 0x26,
    BODY_Moonraker_Elite_1_Male = 0x27,
    BODY_Moonraker_Elite_2_Female = 0x28,
    BODY_Left_Suit_Hand_Floating_Arm = 0x29,
    BODY_Male_Karl = 0x2A,
    BODY_Male_Alan = 0x2B,
    BODY_Male_Pete = 0x2C,
    BODY_Male_Martin = 0x2D,
    BODY_Male_Mark = 0x2E,
    BODY_Male_Duncan = 0x2F,
    BODY_Male_Shaun = 0x30,
    BODY_Male_Dwayne = 0x31,
    BODY_Male_B = 0x32,
    BODY_Male_Dave_Dr_Doak = 0x33,
    BODY_Male_Grant = 0x34,
    BODY_Male_Des = 0x35,
    BODY_Male_Chris = 0x36,
    BODY_Male_Lee = 0x37,
    BODY_Male_Neil = 0x38,
    BODY_Male_Jim = 0x39,
    BODY_Male_Robin = 0x3A,
    BODY_Male_Steve_H = 0x3B,
    BODY_Male_Terrorist = 0x3C,
    BODY_Male_Biker = 0x3D,
    BODY_Male_Graeme = 0x3E,
    BODY_Male_Steve_Ellis = 0x3F,
    BODY_Male_Joel = 0x40,
    BODY_Male_Scott = 0x41,
    BODY_Male_Joe_Altered = 0x42,
    BODY_Male_Ken = 0x43,
    BODY_Male_Joe = 0x44,
    BODY_Male_Mishkin = 0x45,
    BODY_Female_Sally = 0x46,
    BODY_Female_Marion_Rosika = 0x47,
    BODY_Female_Mandy = 0x48,
    BODY_Female_Vivien = 0x49,
    BODY_Male_Pierce_Bond_1 = 0x4A,
    BODY_Male_Pierce_Bond_2 = 0x4B,
    BODY_Male_Pierce_Bond_3 = 0x4C,
    BODY_Male_Pierce_Bond_Parka = 0x4D,
    BODY_Male_Pierce_Bond_Tuxedo = 0x4E,
    BODY_Natalya_Jungle_Fatigues = 0x4F
} BODIES;

typedef enum HEADS {
    HEAD_Male_Karl = 0x2A,
    HEAD_Male_Alan = 0x2B,
    HEAD_Male_Pete = 0x2C,
    HEAD_Male_Martin = 0x2D,
    HEAD_Male_Mark = 0x2E,
    HEAD_Male_Duncan = 0x2F,
    HEAD_Male_Shaun = 0x30,
    HEAD_Male_Dwayne = 0x31,
    HEAD_Male_B = 0x32,
    HEAD_Male_Dave_Dr_Doak = 0x33,
    HEAD_Male_Grant = 0x34,
    HEAD_Male_Des = 0x35,
    HEAD_Male_Chris = 0x36,
    HEAD_Male_Lee = 0x37,
    HEAD_Male_Neil = 0x38,
    HEAD_Male_Jim = 0x39,
    HEAD_Male_Robin = 0x3A,
    HEAD_Male_Steve_H = 0x3B,
    HEAD_Male_Terrorist = 0x3C,
    HEAD_Male_Biker = 0x3D,
    HEAD_Male_Graeme = 0x3E,
    HEAD_Male_Steve_Ellis = 0x3F,
    HEAD_Male_Joel = 0x40,
    HEAD_Male_Scott = 0x41,
    HEAD_Male_Joe_Altered = 0x42,
    HEAD_Male_Ken = 0x43,
    HEAD_Male_Joe = 0x44,
    HEAD_Male_Mishkin = 0x45,
    HEAD_Female_Sally = 0x46,
    HEAD_Female_Marion_Rosika = 0x47,
    HEAD_Female_Mandy = 0x48,
    HEAD_Female_Vivien = 0x49,
    HEAD_Male_Pierce_Bond_1 = 0x4A,
    HEAD_Male_Pierce_Bond_2 = 0x4B,
    HEAD_Male_Pierce_Bond_3 = 0x4C,
    HEAD_Male_Pierce_Bond_Parka = 0x4D,
    HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT = 0x4E,
    HEAD_Natalya_Jungle_Fatigues = 0x4F
} HEADS;

typedef enum mission_setup_type {
    MISSION_PART = 0,
    MISSION_HEADER
} mission_setup_type;

typedef enum MUSIC_TRACKS {
    M_ARCHIVES=11,
    M_ARCHIVESX=37,
    M_AZTEC=25,
    M_AZTECX=46,
    M_BUNKER1=15,
    M_BUNKER1X=41,
    M_BUNKER2=16,
    M_BUNKER2X=42,
    M_CITADEL=6,
    M_CONTROL=8,
    M_CONTROLX=33,
    M_CRADLE=19,
    M_CRADLEX=48,
    M_CUBA=49,
    M_DAM=9,
    M_DAMX=35,
    M_DEATHSOLO=27,
    M_DEPOT=4,
    M_DEPOTX=32,
    M_EGYPTIAN=22,
    M_EGYPTIANX=39,
    M_EGYPTX=47,
    M_ELEVATOR_CONTROL=18,
    M_ELEVATOR_WC=21,
    M_END_SOMETHING=62,
    M_FACILITY=7,
    M_FACILITYX=31,
    M_FOLDERS=23,
    M_FRIGATE=10,
    M_FRIGATEX=36,
    M_GUITARGLISS=54,
    M_INTRO=2,
    M_INTROSWOOSH=44,
    M_JUNGLE=55,
    M_JUNGLEX=43,
    M_MPDEATH=58,
    M_MPTHEME=5,
    M_MPTHEME2=13,
    M_MPTHEME3=52,
    M_NONE=0,
    M_RUNWAY=50,
    M_RUNWAYPLANE=51,
    M_RUNWAYX=56,
    M_SHORT_SOLO_DEATH=1,
    M_SILO=12,
    M_SILOX=38,
    M_STATUE=17,
    M_STATUEPART=61,
    M_STATUEX=45,
    M_STREETS=14,
    M_STREETSX=40,
    M_SURFACE1=57,
    M_SURFACE2=28,
    M_SURFACE2END=60,
    M_SURFACE2X=59,
    M_TRAIN=3,
    M_TRAINX=29,
    M_UNK=20,
    M_UNK2=30,
    M_WATCH=24,
    M_WATERCAVERNS=26,
    M_WATERCAVERNSX=34,
    M_WIND=53
} MUSIC_TRACKS;

typedef enum GAMEMODE {
    GAMEMODE_SOLO = 0x0,
    GAMEMODE_MULTI,
    GAMEMODE_CHEATS,
    GAMEMODE_INTRO = 0xFFFFFFFF
} GAMEMODE;

typedef enum MPSCENARIOS {
    SCENARIO_NORMAL=0,
    SCENARIO_YOLT,
    SCENARIO_TLD,
    SCENARIO_MWTGG,
    SCENARIO_LTK,
    SCENARIO_2v2,
    SCENARIO_3v1,
    SCENARIO_2v1
} MPSCENARIOS;

typedef enum WATCH_BRIEFING_PAGE {
    BRIEFING_TITLE = 0x0,
    BRIEFING_OVERVIEW,
    BRIEFING_M,
    BRIEFING_Q,
    BRIEFING_MONEYPENNY
} WATCH_BRIEFING_PAGE;

typedef enum MENU {
    MENU_LEGAL_SCREEN = 0x0,
    MENU_NINTENDO_LOGO,
    MENU_RAREWARE_LOGO,
    MENU_EYE_INTRO,
    MENU_GOLDENEYE_LOGO,
    MENU_FILE_SELECT,
    MENU_MODE_SELECT,
    MENU_MISSION_SELECT,
    MENU_DIFFICULTY,
    MENU_007_OPTIONS,
    MENU_BRIEFING,
    MENU_RUN_STAGE,
    MENU_MISSION_FAILED,
    MENU_MISSION_COMPLETE,
    MENU_MP_OPTIONS,
    MENU_MP_CHAR_SELECT,
    MENU_MP_HANDICAP,
    MENU_MP_CONTROL_STYLE,
    MENU_MP_STAGE_SELECT,
    MENU_MP_SCENARIO_SELECT,
    MENU_MP_TEAMS,
    MENU_CHEAT,
    MENU_NO_CONTROLLERS,
    MENU_SWITCH_SCREENS,
    MENU_DISPLAY_CAST,
    MENU_SPECTRUM_EMU
} MENU;

typedef enum CONTROLLER_CONFIG
{
    CONTROLLER_CONFIG_HONEY = 0x0,
    CONTROLLER_CONFIG_SOLITARE,
    CONTROLLER_CONFIG_KISSY,
    CONTROLLER_CONFIG_GOODNIGHT,
    CONTROLLER_CONFIG_PLENTY,
    CONTROLLER_CONFIG_GALORE,
    CONTROLLER_CONFIG_DOMINO,
    CONTROLLER_CONFIG_GOODHEAD,
    CONTROLLER_CONFIG_CINEMA
} CONTROLLER_CONFIG;

typedef enum CUFF_TYPES
{
    CUFF_BLUE = 0x0,
    CUFF_TUX,
    CUFF_JUNGLE,
    CUFF_BOILER,
    CUFF_SNOW,
    CUFF_WHITE,
    CUFF_TUX6,
    CUFF_TUX7,
    CUFF_TUX8
} CUFF_TYPES;

typedef enum ITEM_IDS
{
    ITEM_UNARMED = 0x0,
    ITEM_FIST = 0x1,
    ITEM_KNIFE = 0x2,
    ITEM_THROWKNIFE = 0x3,
    ITEM_WPPK = 0x4,
    ITEM_WPPKSIL = 0x5,
    ITEM_TT33 = 0x6,
    ITEM_SKORPION = 0x7,
    ITEM_AK47 = 0x8,
    ITEM_UZI = 0x9,
    ITEM_MP5K = 0xA,
    ITEM_MP5KSIL = 0xB,
    ITEM_SPECTRE = 0xC,
    ITEM_M16 = 0xD,
    ITEM_FNP90 = 0xE,
    ITEM_SHOTGUN = 0xF,
    ITEM_AUTOSHOT = 0x10,
    ITEM_SNIPERRIFLE = 0x11,
    ITEM_RUGER = 0x12,
    ITEM_GOLDENGUN = 0x13,
    ITEM_SILVERWPPK = 0x14,
    ITEM_GOLDWPPK = 0x15,
    ITEM_LASER = 0x16,
    ITEM_WATCHLASER = 0x17,
    ITEM_GRENADELAUNCH = 0x18,
    ITEM_ROCKETLAUNCH = 0x19,
    ITEM_GRENADE = 0x1A,
    ITEM_TIMEDMINE = 0x1B,
    ITEM_PROXIMITYMINE = 0x1C,
    ITEM_REMOTEMINE = 0x1D,
    ITEM_TRIGGER = 0x1E,
    ITEM_TASER = 0x1F,
    ITEM_TANKSHELLS = 0x20,
    ITEM_BOMBCASE = 0x21,
    ITEM_PLASTIQUE = 0x22,
    ITEM_FLAREPISTOL = 0x23,
    ITEM_PITONGUN = 0x24,
    ITEM_BUNGEE = 0x25,
    ITEM_DOORDECODER = 0x26,
    ITEM_BOMBDEFUSER = 0x27,
    ITEM_CAMERA = 0x28,
    ITEM_LOCKEXPLODER = 0x29,
    ITEM_DOOREXPLODER = 0x2A,
    ITEM_BRIEFCASE = 0x2B,
    ITEM_WEAPONCASE = 0x2C,
    ITEM_SAFECRACKERCASE = 0x2D,
    ITEM_KEYANALYSERCASE = 0x2E,
    ITEM_BUG = 0x2F,
    ITEM_MICROCAMERA = 0x30,
    ITEM_BUGDETECTOR = 0x31,
    ITEM_EXPLOSIVEFLOPPY = 0x32,
    ITEM_POLARIZEDGLASSES = 0x33,
    ITEM_DARKGLASSES = 0x34,
    ITEM_CREDITCARD = 0x35,
    ITEM_GASKEYRING = 0x36,
    ITEM_DATATHIEF = 0x37,
    ITEM_WATCHIDENTIFIER = 0x38,
    ITEM_WATCHCOMMUNICATOR = 0x39,
    ITEM_WATCHGEIGERCOUNTER = 0x3A,
    ITEM_WATCHMAGNETREPEL = 0x3B,
    ITEM_WATCHMAGNETATTRACT = 0x3C,
    ITEM_GOLDENEYEKEY = 0x3D,
    ITEM_BLACKBOX = 0x3E,
    ITEM_CIRCUITBOARD = 0x3F,
    ITEM_CLIPBOARD = 0x40,
    ITEM_STAFFLIST = 0x41,
    ITEM_DOSSIERRED = 0x42,
    ITEM_PLANS = 0x43,
    ITEM_SPYFILE = 0x44,
    ITEM_BLUEPRINTS = 0x45,
    ITEM_MAP = 0x46,
    ITEM_AUDIOTAPE = 0x47,
    ITEM_VIDEOTAPE = 0x48,
    ITEM_DATTAPE = 0x49,
    ITEM_SPOOLTAPE = 0x4A,
    ITEM_MICROFILM = 0x4B,
    ITEM_MICROCODE = 0x4C,
    ITEM_LECTRE = 0x4D,
    ITEM_MONEY = 0x4E,
    ITEM_GOLDBAR = 0x4F,
    ITEM_HEROIN = 0x50,
    ITEM_KEYCARD = 0x51,
    ITEM_KEYYALE = 0x52,
    ITEM_KEYBOLT = 0x53,
    ITEM_SUIT_LF_HAND = 0x54,
    ITEM_JOYPAD = 0x55,
    ITEM_56 = 0x56,
    ITEM_57 = 0x57,
    ITEM_TOKEN = 0x58
} ITEM_IDS;

typedef enum PROPS
{
    PROP_alarm1Z               = 0000, /* Beta Alarm / Default Multi Weapon */
    PROP_alarm2Z               = 0001, /* Alarm */
    PROP_explosionbitZ         = 0002, /* White Pyramid (Explosion Bit) */
    PROP_ammo_crate1Z          = 0003, /* Ammo Crate (Brown w/ Edge Brace, 6x240 Black) */
    PROP_ammo_crate2Z          = 0004, /* Ammo Crate (Brown w/ Center Brace, 12x8 Black) */
    PROP_ammo_crate3Z          = 0005, /* Ammo Crate (Green w/ Center Brace, 12x8 Brown) */
    PROP_ammo_crate4Z          = 0006, /* Ammo Crate (Green w/ Edge Brace, 6x8 White) */
    PROP_ammo_crate5Z          = 0007, /* Ammo Crate (Green w/ Double Brace, 24x60 Black) */
    PROP_bin1Z                 = 0008, /* Rusted Trash Bin */
    PROP_blotter1Z             = 0009, /* Desk Blotter */
    PROP_book1Z                = 0010, /* Red Book */
    PROP_bookshelf1Z           = 0011, /* Bookshelf */
    PROP_bridge_console1aZ     = 0012, /* Bridge Console w/ Monitor, Navigation + Keyboard 1A */
    PROP_bridge_console1bZ     = 0013, /* Bridge Console w/ Navigation 1B */
    PROP_bridge_console2aZ     = 0014, /* Bridge Console w/ Navigation, Monitor + Keyboard 2A */
    PROP_bridge_console2bZ     = 0015, /* Bridge Console w/ Various Controls 2B */
    PROP_bridge_console3aZ     = 0016, /* Bridge Console w/ Monitor, Navigation + Keyboard 3A */
    PROP_bridge_console3bZ     = 0017, /* Bridge Console w/ Monitor, Keyboard + Navigation 3B */
    PROP_card_box1Z            = 0018, /* Cardboard Box, Kapto|Enb */
    PROP_card_box2Z            = 0019, /* Cardboard Box, Red Arrow, Bahko */
    PROP_card_box3Z            = 0020, /* Cardboard Box, Scrawled Text, Bahah */
    PROP_card_box4_lgZ         = 0021, /* Cardboard Box, Three Seams */
    PROP_card_box5_lgZ         = 0022, /* Cardboard Box, Two Seams, Bahah */
    PROP_card_box6_lgZ         = 0023, /* Cardboard Box, Bahko */
    PROP_cctvZ                 = 0024, /* Surveillance Camera */
    PROP_console1Z             = 0025, /* Double Screen Consoles w/ Keyboards */
    PROP_console2Z             = 0026, /* Double Screen Consoles w/ Left Keyboard */
    PROP_console3Z             = 0027, /* Double Screen Consoles w/ Right Keyboard */
    PROP_console_sevaZ         = 0028, /* Console w/ Keyboard */
    PROP_console_sevbZ         = 0029, /* Console w/ Monitor + Keyboard */
    PROP_console_sevcZ         = 0030, /* Console w/ Switches */
    PROP_console_sevdZ         = 0031, /* Console w/ Five Gauges */
    PROP_console_sev2aZ        = 0032, /* Console w/ Four Faders */
    PROP_console_sev2bZ        = 0033, /* Console w/ Monitor, Keyboard + Switches */
    PROP_console_sev2cZ        = 0034, /* Console w/ Three Gauges */
    PROP_console_sev2dZ        = 0035, /* Console w/ Pressure Gauge */
    PROP_console_sev_GEaZ      = 0036, /* Console w/ GoldenEye Key Slot */
    PROP_console_sev_GEbZ      = 0037, /* Console w/ Faders + Pressure Gauge */
    PROP_desk1Z                = 0038, /* Desk w/ Kickplate */
    PROP_desk2Z                = 0039, /* Desk */
    PROP_desk_lamp2Z           = 0040, /* Desk Lamp */
    PROP_disc_readerZ          = 0041, /* External Hard Drive */
    PROP_disk_drive1Z          = 0042, /* Floppy Disc Drive */
    PROP_filing_cabinet1Z      = 0043, /* Filing Cabinet */
    PROP_jerry_can1Z           = 0044, /* Jerrycan (Fuel Container) */
    PROP_keyboard1Z            = 0045, /* Computer Keyboard */
    PROP_kit_units1Z           = 0046, /* Kitchen Cabinets */
    PROP_letter_tray1Z         = 0047, /* Letter Tray */
    PROP_mainframe1Z           = 0048, /* Mainframe, Basic */
    PROP_mainframe2Z           = 0049, /* Mainframe, Advanced */
    PROP_metal_chair1Z         = 0050, /* Chair (Metal) */
    PROP_metal_crate1Z         = 0051, /* Metal Crate, 6 Top Corner */
    PROP_metal_crate2Z         = 0052, /* Metal Crate, 6 Bottom Corner */
    PROP_metal_crate3Z         = 0053, /* Metal Crate, Toxic Materials */
    PROP_metal_crate4Z         = 0054, /* Metal Crate, Double Stripe - Class D1 Hazard */
    PROP_missile_rackZ         = 0055, /* Naval Harpoon Missile in Containment Rack */
    PROP_missile_rack2Z        = 0056, /* Naval Harpoon Missiles in Containment Racks x4 */
    PROP_oil_drum1Z            = 0057, /* Oil Drum, Single Stripe, Ribbed */
    PROP_oil_drum2Z            = 0058, /* Oil Drum, Single Stripe, Ribbed - Class D1 Hazard */
    PROP_oil_drum3Z            = 0059, /* Oil Drum, Single Stripe, Ribbed - Toxic Materials */
    PROP_oil_drum5Z            = 0060, /* Oil Drum, Double Stripe - Toxic Materials */
    PROP_oil_drum6Z            = 0061, /* Oil Drum - Toxic Materials */
    PROP_oil_drum7Z            = 0062, /* Oil Drum, Double Dashes - Class D1 Hazard */
    PROP_padlockZ              = 0063, /* Padlock */
    PROP_phone1Z               = 0064, /* Telephone */
    PROP_radio_unit1Z          = 0065, /* Radio Tuner w/ 1 Knob + 2 Gauges */
    PROP_radio_unit2Z          = 0066, /* Radio Tuner w/ 1 Knob + 5 Gauges */
    PROP_radio_unit3Z          = 0067, /* Radio Tuner w/ 3 Knobs + 5 Gauges */
    PROP_radio_unit4Z          = 0068, /* Radio Tuner w/ 3 Knobs + 2 Gauges */
    PROP_sat1_reflectZ         = 0069, /* GoldenEye Satellite */
    PROP_satdishZ              = 0070, /* Satellite Dish (Arkangelsk) */
    PROP_satboxZ               = 0071, /* Uplink Box */
    PROP_stool1Z               = 0072, /* Wooden Stool */
    PROP_swivel_chair1Z        = 0073, /* Swivel Chair */
    PROP_torpedo_rackZ         = 0074, /* Naval Torpedo Rack x3 */
    PROP_tv1Z                  = 0075, /* Television Monitor */
    PROP_tv_holderZ            = 0076, /* Hanging Monitor Rack */
    PROP_tvscreenZ             = 0077, /* Wall Monitor Screen */
    PROP_tv4screenZ            = 0078, /* Wall Monitor Screens, 4-in-1 */
    PROP_wood_lg_crate1Z       = 0079, /* Wooden Crate w/ #4 Label, Bahah */
    PROP_wood_lg_crate2Z       = 0080, /* Wooden Crate, Darker Shading, Kapto|Enb */
    PROP_wood_md_crate3Z       = 0081, /* Wooden Crates x8, Bahko */
    PROP_wood_sm_crate4Z       = 0082, /* Wooden Crate w/ #2 Label, Bahko */
    PROP_wood_sm_crate5Z       = 0083, /* Wooden Crate w/ #4 Label, Darker Shading, Bahah */
    PROP_wood_sm_crate6Z       = 0084, /* Wooden Crate w/ UP Arrow, Kapto|Enb */
    PROP_wooden_table1Z        = 0085, /* Wooden Table */
    PROP_swipe_card2Z          = 0086, /* Keycard */
    PROP_borg_crateZ           = 0087, /* Blue and Gold Printed Circuit Cube (Borg Crate) */
    PROP_boxes4x4Z             = 0088, /* Metal Crate Stack, 4x4 */
    PROP_boxes3x4Z             = 0089, /* Metal Crate Stack, 3x4 */
    PROP_boxes2x4Z             = 0090, /* Metal Crate Stack, 2x4 */
    PROP_sec_panelZ            = 0091, /* Security Card Panel */
    PROP_ICBM_noseZ            = 0092, /* Silo Missile (ICBM), Nose Cone Only */
    PROP_ICBMZ                 = 0093, /* Silo Missile (ICBM) */
    PROP_tuning_console1Z      = 0094, /* Dual Consoles on Castors */
    PROP_desk_arecibo1Z        = 0095, /* Computer Work Desk */
    PROP_locker3Z              = 0096, /* Lockers, Single Venting */
    PROP_locker4Z              = 0097, /* Lockers, Double Venting */
    PROP_roofgunZ              = 0098, /* Ceiling Mounted Drone Gun */
    PROP_dest_engineZ          = 0099, /* Frigate Engine */
    PROP_dest_exocetZ          = 0100, /* Naval MK 29 Missile Launcher (Exocet) */
    PROP_dest_gunZ             = 0101, /* Naval 100 mm Gun Turret (TR 100) */
    PROP_dest_harpoonZ         = 0102, /* Naval MK 141 Launch Canisters (Harpoon) */
    PROP_dest_seawolfZ         = 0103, /* Naval MK 26 Dual Missile Launcher (Seawolf) */
    PROP_windowZ               = 0104, /* Window Glass */
    PROP_window_lib_lg1Z       = 0105, /* Window Glass, Lattice Frame, 4x10 (single-sided) */
    PROP_window_lib_sm1Z       = 0106, /* Window Glass, Lattice Frame, 4x3 (double-sided) */
    PROP_window_cor11Z         = 0107, /* Window Glass, Lattice Frame, 4x4 (single-sided) */
    PROP_jungle3_treeZ         = 0108, /* Jungle Large Tree */
    PROP_palmZ                 = 0109, /* Jungle Palm Tree */
    PROP_palmtreeZ             = 0110, /* Jungle Palm Tree, Resprouting After Loss of Fronds */
    PROP_plant2bZ              = 0111, /* Jungle Plant, Low Shrub */
    PROP_labbenchZ             = 0112, /* Laboratory Table w/ Sink Drains */
    PROP_gasbarrelZ            = 0113, /* White Bin */
    PROP_gasbarrelsZ           = 0114, /* White Bins x4 */
    PROP_bodyarmourZ           = 0115, /* Body Armor */
    PROP_bodyarmourvestZ       = 0116, /* Body Armor (Vest) */
    PROP_gastankZ              = 0117, /* Bottling Tank */
    PROP_glassware1Z           = 0118, /* Glass Cup */
    PROP_hatchboltZ            = 0119, /* Metallic Securing Strip (Hatch Bolt) */
    PROP_brakeunitZ            = 0120, /* Train Brake Controller */
    PROP_ak47magZ              = 0121, /* Gun Magazine (KF7 Soviet) */
    PROP_m16magZ               = 0122, /* Gun Magazine (AR33 Assault Rifle) */
    PROP_mp5kmagZ              = 0123, /* Gun Magazine (D5K Deutsche) */
    PROP_skorpionmagZ          = 0124, /* Gun Magazine (Klobb) */
    PROP_spectremagZ           = 0125, /* Gun Magazine (Phantom) */
    PROP_uzimagZ               = 0126, /* Gun Magazine (ZMG (9mm)) */
    PROP_silencerZ             = 0127, /* Silencer */
    PROP_chrextinguisherZ      = 0128, /* Fire Extinguisher */
    PROP_boxcartridgesZ        = 0129, /* Box of Shells (Shotgun Cartridges) */
    PROP_fnp90magZ             = 0130, /* Gun Magazine (RC-P90) */
    PROP_goldenshellsZ         = 0131, /* Box of Shells (Golden Gun Bullets) */
    PROP_magnumshellsZ         = 0132, /* Box of Shells (Magnum Rounds) */
    PROP_wppkmagZ              = 0133, /* Gun Magazine (PP7) */
    PROP_tt33magZ              = 0134, /* Gun Magazine (DD44 Dostovei) */
    PROP_sev_doorZ             = 0135, /* Grey Containment Door w/ Caution Stripes and Window */
    PROP_sev_door3Z            = 0136, /* Grey Electronic Door w/ LEFT Arrow */
    PROP_sev_door3_windZ       = 0137, /* BETA Electronic Door w/ LEFT Arrow and Fake Window */
    PROP_sev_door4_windZ       = 0138, /* Grey Electronic Door w/ LEFT Arrow and Window */
    PROP_sev_trislideZ         = 0139, /* Glass Door w/ Stone Frame */
    PROP_sev_door_v1Z          = 0140, /* Grey Electronic Door w/ UP Arrow */
    PROP_steel_door1Z          = 0141, /* Silver Corrugated Door w/ Caution Stripes */
    PROP_steel_door2Z          = 0142, /* Rusty Door w/ Handle */
    PROP_steel_door3Z          = 0143, /* Double Cross Brace Door */
    PROP_silo_lift_doorZ       = 0144, /* Elevator Door */
    PROP_steel_door2bZ         = 0145, /* Rusty Door w/o Handle */
    PROP_door_roller1Z         = 0146, /* Blue Bay Door w/ Caution Stripes */
    PROP_door_roller2Z         = 0147, /* Blue Bay Door w/ Venting and Caution Stripes */
    PROP_door_roller3Z         = 0148, /* Blue Bay Door w/ Venting and Caution Stripes */
    PROP_door_roller4Z         = 0149, /* Cargo Bay Door w/ UP Arrow and Transportation Stripes */
    PROP_door_st_arec1Z        = 0150, /* Blue Corrugated Door w/ Transportation Stripes */
    PROP_door_st_arec2Z        = 0151, /* Blue Reversed Corrugated Door w/ Transportation Stripes */
    PROP_door_dest1Z           = 0152, /* Grey Frigate Door w/ Indents and Caution Stripes */
    PROP_door_dest2Z           = 0153, /* Grey Frigate Door w/ Indents, Caution Stripes and KEEP CLEAR Label */
    PROP_gas_plant_sw_do1Z     = 0154, /* Grey Swinging Door w/ Blue Stripe */
    PROP_gas_plant_sw2_do1Z    = 0155, /* Grey Swinging Door, Darker */
    PROP_gas_plant_sw3_do1Z    = 0156, /* Grey Swinging Door, Lighter */
    PROP_gas_plant_sw4_do1Z    = 0157, /* Light Wooden Door (Looks Like Sand) */
    PROP_gas_plant_met1_do1Z   = 0158, /* Brown Electronic Door */
    PROP_gas_plant_wc_cub1Z    = 0159, /* Bathroom Stall Door */
    PROP_gasplant_clear_doorZ  = 0160, /* Laboratory Glass Door */
    PROP_train_doorZ           = 0161, /* Dark Wooden Door */
    PROP_train_door2Z          = 0162, /* Dark Wooden Door w/ Window */
    PROP_train_door3Z          = 0163, /* Dark Wooden Door w/ Window + Shutter */
    PROP_door_eyelidZ          = 0164, /* Eyelid Door */
    PROP_door_irisZ            = 0165, /* Iris Door */
    PROP_sevdoorwoodZ          = 0166, /* Cabin Door */
    PROP_sevdoorwindZ          = 0167, /* Weathered Swinging Door w/ Window */
    PROP_sevdoornowindZ        = 0168, /* Weathered Swinging Door */
    PROP_sevdoormetslideZ      = 0169, /* Brown Corrugated Electronic Door */
    PROP_cryptdoor1aZ          = 0170, /* Stone Door w/ Prints (Set A) */
    PROP_cryptdoor1bZ          = 0171, /* Sand Door w/ Damage (Set A) */
    PROP_cryptdoor2aZ          = 0172, /* Stone Door w/ Prints, Darker (Set B) */
    PROP_cryptdoor2bZ          = 0173, /* Sand Door w/ Damage, Darker (Set B) */
    PROP_cryptdoor3Z           = 0174, /* Egyptian Moving Wall */
    PROP_cryptdoor4Z           = 0175, /* Brown Sand Door (Temple) */
    PROP_vertdoorZ             = 0176, /* Blast Door (Control) */
    PROP_hatchdoorZ            = 0177, /* Train Floor Hatch */
    PROP_damgatedoorZ          = 0178, /* Security Gate (Dam) */
    PROP_damtundoorZ           = 0179, /* Tunnel Flood Door (Dam) */
    PROP_damchaindoorZ         = 0180, /* Mesh Gate */
    PROP_silotopdoorZ          = 0181, /* Launch Tube Ceiling Shutter (Silo) */
    PROP_doorprison1Z          = 0182, /* Cell Door */
    PROP_doorstatgateZ         = 0183, /* Park Gate */
    PROP_chrkalashZ            = 0184, /* KF7 Soviet */
    PROP_chrgrenadelaunchZ     = 0185, /* Grenade Launcher */
    PROP_chrknifeZ             = 0186, /* Hunting Knife */
    PROP_chrlaserZ             = 0187, /* Moonraker Laser */
    PROP_chrm16Z               = 0188, /* AR33 Assault Rifle */
    PROP_chrmp5kZ              = 0189, /* D5K Deutsche */
    PROP_chrrugerZ             = 0190, /* Cougar Magnum */
    PROP_chrwppkZ              = 0191, /* PP7 Special Issue */
    PROP_chrshotgunZ           = 0192, /* Shotgun */
    PROP_chrskorpionZ          = 0193, /* Klobb */
    PROP_chrspectreZ           = 0194, /* Phantom */
    PROP_chruziZ               = 0195, /* ZMG (9mm) */
    PROP_chrgrenadeZ           = 0196, /* Hand Grenade */
    PROP_chrfnp90Z             = 0197, /* RC-P90 */
    PROP_chrbriefcaseZ         = 0198, /* Briefcase */
    PROP_chrremotemineZ        = 0199, /* Remote Mine */
    PROP_chrproximitymineZ     = 0200, /* Proximity Mine */
    PROP_chrtimedmineZ         = 0201, /* Timed Mine */
    PROP_chrrocketZ            = 0202, /* Rocket */
    PROP_chrgrenaderoundZ      = 0203, /* Grenade Round */
    PROP_chrwppksilZ           = 0204, /* PP7 (Silenced) */
    PROP_chrtt33Z              = 0205, /* DD44 Dostovei */
    PROP_chrmp5ksilZ           = 0206, /* D5K (Silenced) */
    PROP_chrautoshotZ          = 0207, /* Automatic Shotgun */
    PROP_chrgoldenZ            = 0208, /* Golden Gun */
    PROP_chrthrowknifeZ        = 0209, /* Throwing Knife */
    PROP_chrsniperrifleZ       = 0210, /* Sniper Rifle */
    PROP_chrrocketlaunchZ      = 0211, /* Rocket Launcher */
    PROP_hatfurryZ             = 0212, /* Fur Hat, Blue */
    PROP_hatfurrybrownZ        = 0213, /* Fur Hat, Brown */
    PROP_hatfurryblackZ        = 0214, /* Fur Hat, Black */
    PROP_hattbirdZ             = 0215, /* Side Cap, Light Green */
    PROP_hattbirdbrownZ        = 0216, /* Side Cap, Dark Green */
    PROP_hathelmetZ            = 0217, /* Combat Helmet, Green */
    PROP_hathelmetgreyZ        = 0218, /* Combat Helmet, Grey */
    PROP_hatmoonZ              = 0219, /* Elite Headgear */
    PROP_hatberetZ             = 0220, /* Special Forces Beret, Black */
    PROP_hatberetblueZ         = 0221, /* Special Forces Beret, Navy */
    PROP_hatberetredZ          = 0222, /* Special Forces Beret, Burgundy */
    PROP_hatpeakedZ            = 0223, /* Officer's Peaked Visor Cap */
    PROP_chrwristdartZ         = 0224, /* Pchrwristdartz (BETA) */
    PROP_chrexplosivepenZ      = 0225, /* Pchrexplosivepenz (BETA) */
    PROP_chrbombcaseZ          = 0226, /* Bomb Case (Briefcase Laying Down) */
    PROP_chrflarepistolZ       = 0227, /* Pchrflarepistolz (BETA Pickup) */
    PROP_chrpitongunZ          = 0228, /* Pchrpitongunz (BETA Pickup) */
    PROP_chrfingergunZ         = 0229, /* Pchrfingergunz (BETA Pickup) */
    PROP_chrsilverwppkZ        = 0230, /* Pchrsilverwppkz (BETA Pickup) */
    PROP_chrgoldwppkZ          = 0231, /* Pchrgoldwppkz (BETA Pickup) */
    PROP_chrdynamiteZ          = 0232, /* Pchrdynamitez (BETA Pickup) */
    PROP_chrbungeeZ            = 0233, /* Pchrbungeez (BETA Pickup) */
    PROP_chrdoordecoderZ       = 0234, /* Door Decoder */
    PROP_chrbombdefuserZ       = 0235, /* Bomb Defuser */
    PROP_chrbugdetectorZ       = 0236, /* Pchrbugdetectorz (BETA Pickup) */
    PROP_chrsafecrackercaseZ   = 0237, /* Safe Cracker Case (Briefcase Laying Down) */
    PROP_chrcameraZ            = 0238, /* Photo Camera (007) */
    PROP_chrlockexploderZ      = 0239, /* Pchrlockexploderz (BETA Pickup) */
    PROP_chrdoorexploderZ      = 0240, /* Pchrdoorexploderz (BETA Pickup) */
    PROP_chrkeyanalysercaseZ   = 0241, /* Key Analyzer Case (Briefcase Laying Down) */
    PROP_chrweaponcaseZ        = 0242, /* Weapon Case (Briefcase Standing Up) */
    PROP_chrkeyyaleZ           = 0243, /* Yale Key */
    PROP_chrkeyboltZ           = 0244, /* Bolt Key */
    PROP_chrbugZ               = 0245, /* Covert Modem / Tracker Bug */
    PROP_chrmicrocameraZ       = 0246, /* Micro Camera */
    PROP_floppyZ               = 0247, /* Floppy Disc */
    PROP_chrgoldeneyekeyZ      = 0248, /* GoldenEye Key */
    PROP_chrpolarizedglassesZ  = 0249, /* Polarized Glasses */
    PROP_chrcreditcardZ        = 0250, /* Pchrcreditcardz (BETA Pickup) */
    PROP_chrdarkglassesZ       = 0251, /* Pchrdarkglassesz (BETA Pickup) */
    PROP_chrgaskeyringZ        = 0252, /* Gas Keyring */
    PROP_chrdatathiefZ         = 0253, /* Datathief */
    PROP_safeZ                 = 0254, /* Safe Body */
    PROP_bombZ                 = 0255, /* Pbombz (BETA Pickup) */
    PROP_chrplansZ             = 0256, /* Plans (Briefing Folder) */
    PROP_chrspyfileZ           = 0257, /* Pchrspyfilez (BETA Pickup) */
    PROP_chrblueprintsZ        = 0258, /* Pirate Blueprints */
    PROP_chrcircuitboardZ      = 0259, /* Circuitboard */
    PROP_chrmapZ               = 0260, /* Bunker Expansion Plans */
    PROP_chrspooltapeZ         = 0261, /* Pchrspooltapez (BETA Pickup) */
    PROP_chraudiotapeZ         = 0262, /* Audiotape */
    PROP_chrmicrofilmZ         = 0263, /* Pchrmicrofilmz (BETA Pickup) */
    PROP_chrmicrocodeZ         = 0264, /* Pchrmicrocodez (BETA Pickup) */
    PROP_chrlectreZ            = 0265, /* Pchrlectrez (BETA Pickup) */
    PROP_chrmoneyZ             = 0266, /* Pchrmoneyz (BETA Pickup) */
    PROP_chrgoldbarZ           = 0267, /* Pchrgoldbarz (BETA Pickup) */
    PROP_chrheroinZ            = 0268, /* Pchrheroinz (BETA Pickup) */
    PROP_chrclipboardZ         = 0269, /* Clipboard */
    PROP_chrdossierredZ        = 0270, /* Red Dossier */
    PROP_chrstafflistZ         = 0271, /* Staff List */
    PROP_chrdattapeZ           = 0272, /* DAT */
    PROP_chrplastiqueZ         = 0273, /* Plastique */
    PROP_chrblackboxZ          = 0274, /* Black Box (Orange Flight Recorder) */
    PROP_chrvideotapeZ         = 0275, /* CCTV Tape (GoldenEye VHS) */
    PROP_nintendologoZ         = 0276, /* Nintendo Logo */
    PROP_goldeneyelogoZ        = 0277, /* GoldenEye Logo */
    PROP_walletbondZ           = 0278, /* Classified Folder w/ Royal Crest (Folder Menus) */
    PROP_miltruckZ             = 0279, /* Supply Truck */
    PROP_jeepZ                 = 0280, /* Military Jeep */
    PROP_articZ                = 0281, /* Red Prime Mover */
    PROP_helicopterZ           = 0282, /* Transport Helicopter w/ Natalya */
    PROP_tigerZ                = 0283, /* Pirate Euro Chopper */
    PROP_milcopterZ            = 0284, /* Hound Helicopter */
    PROP_hindZ                 = 0285, /* Soviet Camouflage Chopper */
    PROP_artictrailerZ         = 0286, /* Black Trailer */
    PROP_motorbikeZ            = 0287, /* Motorbike */
    PROP_tankZ                 = 0288, /* Tank */
    PROP_apcZ                  = 0289, /* Armored Personnel Carrier */
    PROP_speedboatZ            = 0290, /* Speedboat */
    PROP_planeZ                = 0291, /* Aeroplane */
    PROP_gun_runway1Z          = 0292, /* Heavy Gun Emplacement */
    PROP_safedoorZ             = 0293, /* Safe Door */
    PROP_key_holderZ           = 0294, /* Key Rack */
    PROP_hatchsevxZ            = 0295, /* Grating (Ventshaft Hatch) */
    PROP_sevdishZ              = 0296, /* Satellite Dish (Severnaya) */
    PROP_archsecdoor1Z         = 0297, /* Archives Moving Wall (Dark) */
    PROP_archsecdoor2Z         = 0298, /* Archives Moving Wall (Light) */
    PROP_groundgunZ            = 0299, /* Free Standing Drone Gun */
    PROP_trainextdoorZ         = 0300, /* Train Exterior Door */
    PROP_carbmwZ               = 0301, /* White Car #1 (BMW) */
    PROP_carescortZ            = 0302, /* White Car #2 (Escort) */
    PROP_cargolfZ              = 0303, /* White Car #3 (Golf) */
    PROP_carweirdZ             = 0304, /* Red Car (Cadillac) */
    PROP_carzilZ               = 0305, /* Ourumov's Car (ZIL) */
    PROP_shuttle_door_lZ       = 0306, /* Exhaust Bay Doors, Left Side */
    PROP_shuttle_door_rZ       = 0307, /* Exhaust Bay Doors, Right Side */
    PROP_depot_gate_entryZ     = 0308, /* Metallic Gate w/ Red Star */
    PROP_depot_door_steelZ     = 0309, /* Rusty Door w/ Handle (Lo-Res) */
    PROP_glassware2Z           = 0310, /* Beaker w/ Blue Topper */
    PROP_glassware3Z           = 0311, /* Erlenmeyer Flask */
    PROP_glassware4Z           = 0312, /* Set of Five Beakers */
    PROP_landmineZ             = 0313, /* Land Mine */
    PROP_plant1Z               = 0314, /* Jungle Plant, Withered and Dying */
    PROP_plant11Z              = 0315, /* Jungle Plant, Turning Colour */
    PROP_plant2Z               = 0316, /* Jungle Plant, Healthy and Thick */
    PROP_plant3Z               = 0317, /* Jungle Plant, Tall Leaves */
    PROP_jungle5_treeZ         = 0318, /* Jungle Tree, Moss Covered */
    PROP_legalpageZ            = 0319, /* GoldenEye Certification Screen */
    PROP_st_pete_room_1iZ      = 0320, /* Roads and Buildings #1 (stretch of road) */
    PROP_st_pete_room_2iZ      = 0321, /* Roads and Buildings #2 (stretch of road) */
    PROP_st_pete_room_3tZ      = 0322, /* Roads and Buildings #3 (intersection) */
    PROP_st_pete_room_5cZ      = 0323, /* Roads and Buildings #4 (street corner) */
    PROP_st_pete_room_6cZ      = 0324, /* Roads and Buildings #5 (street corner) */
    PROP_door_rollertrainZ     = 0325, /* Roller Door */
    PROP_door_winZ             = 0326, /* Glass Sliding Door (Aztec) */
    PROP_door_aztecZ           = 0327, /* Stone Sliding Door (Aztec) */
    PROP_shuttleZ              = 0328, /* Moonraker Shuttle */
    PROP_door_azt_deskZ        = 0329, /* Boardroom Table (Aztec Exhaust Bay) */
    PROP_door_azt_desk_topZ    = 0330, /* Boardroom Table Extension (Aztec Exhaust Bay) */
    PROP_door_azt_chairZ       = 0331, /* Boardroom Chair (Aztec Exhaust Bay) */
    PROP_door_mfZ              = 0332, /* Mainframe Door */
    PROP_flagZ                 = 0333, /* Flag Tag Token */
    PROP_barricadeZ            = 0334, /* Road Barricade */
    PROP_modemboxZ             = 0335, /* Covert Modem Connection Screen */
    PROP_doorpanelZ            = 0336, /* Sliding Door Activation Switch */
    PROP_doorconsoleZ          = 0337, /* Console w/ Activation Light */
    PROP_chrtesttubeZ          = 0338, /* Glass Test Tube */
    PROP_bollardZ              = 0339 /* Bollard */
} PROPS;

typedef enum PROJECTILES
{
  PROJECTILES_MAX = 0x2E,
  PROJECTILES_TYPE_KNIFE = PROP_chrknifeZ,
  PROJECTILES_TYPE_GRENADE = PROP_chrgrenadeZ,
  PROJECTILES_TYPE_REMOTE_MINE = PROP_chrremotemineZ,
  PROJECTILES_TYPE_PROX_MINE = PROP_chrproximitymineZ,
  PROJECTILES_TYPE_TIMED_MINE = PROP_chrtimedmineZ,
  PROJECTILES_TYPE_ROCKET_ROUND = PROP_chrrocketZ,
  PROJECTILES_TYPE_ROCKET_ROUND2 = PROP_chrrocketZ,
  PROJECTILES_TYPE_GLAUNCH_ROUND = PROP_chrgrenaderoundZ,
  PROJECTILES_TYPE_BOMBCASE = PROP_chrbombcaseZ,
  PROJECTILES_TYPE_BUG = PROP_chrbugZ,
  PROJECTILES_TYPE_MICROCAMERA = PROP_chrmicrocameraZ,
  PROJECTILES_TYPE_GE_KEY = PROP_chrgoldeneyekeyZ,
  PROJECTILES_TYPE_PLASTIQUE = PROP_chrplastiqueZ
} PROJECTILES;

typedef enum AMMOTYPES {
    AMMO_9MM=1,
    AMMO_9MM_2=2,
    AMMO_RIFLE=3,
    AMMO_SHOTGUN=4,
    AMMO_GRENADE=5,
    AMMO_ROCKETS=6,
    AMMO_REMOTEMINE=7,
    AMMO_PROXMINE=8,
    AMMO_TIMEDMINE=9,
    AMMO_KNIFE=10,
    AMMO_GRENADEROUND=11,
    AMMO_MAGNUM=12,
    AMMO_GGUN=13,
    AMMO_DARTS=14,
    AMMO_EXPLOSIVEPEN=15,
    AMMO_BOMBCASE=16,
    AMMO_FLARE=17,
    AMMO_PITON=18,
    AMMO_DYNAMITE=19,
    AMMO_BUG=20,
    AMMO_MICRO_CAMERA=21,
    AMMO_GEKEY=22,
    AMMO_PLASTIQUE=23,
    AMMO_WATCH_LASER=24,
    AMMO_WATCH_MAGNET=25,
    AMMO_UNK=26,
    AMMO_CAMERA=27,
    AMMO_TANK=28,
    AMMO_TOKEN=29
} AMMOTYPES;

typedef enum DOORSTATE
{
  OPEN = 0x1,
  CLOSED = 0x2
} DOORSTATE;

typedef enum SCREEN_SIZE
{
  SCREEN_SIZE_320x240 = 0x0,
  SCREEN_SIZE_440x330 = 0x1
} SCREEN_SIZE;

typedef enum COLORMODE
{
  MODE_32BIT = 0x0,
  MODE_16BIT = 0x1
} COLORMODE;

typedef enum CAMERAMODE {
    INTRO_CAM=1,
    FADESWIRL_CAM,
    SWIRL_CAM,
    FP_CAM,
    UNK5_CAM,
    UNK6_CAM,
    POSEND_CAM,
    FP_NOINPUT_CAM,
    MP_CAM,
    UNK10_CAM
} CAMERAMODE;

#endif
