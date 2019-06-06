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

#define MAX_OBJECTIVES 10

enum MISSION_BRIEFING_ENUM {BRIEF_BG = 0, BRIEF_M, BRIEF_Q, BRIEF_MP};
enum MISSION_DIFFICULTY_ENUM {DIFF_A = 0, DIFF_SA, DIFF_00A, DIFF_007};

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
    LEVELID_NONE = 0xFFFFFFFF
} LEVELID;

typedef enum GENDER {
    FEMALE=0,
    MALE=1
} GENDER;

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
    MISSION_HEADER=1,
    MISSION_PART=0
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
    GAMEMODE_CHEATS=2,
    GAMEMODE_INTRO=-1,
    GAMEMODE_MULTI=1,
    GAMEMODE_SOLO=0
} GAMEMODE;

typedef enum MP_STAGE_SELECTED {
    MP_STAGE_ARCHIVES=9,
    MP_STAGE_BASEMENT=5,
    MP_STAGE_BUNKER=8,
    MP_STAGE_CAVERNS=10,
    MP_STAGE_CAVES=3,
    MP_STAGE_COMPLEX=2,
    MP_STAGE_EGYPT=11,
    MP_STAGE_FACILITY=7,
    MP_STAGE_LIBRARY=4,
    MP_STAGE_RANDOM=0,
    MP_STAGE_STACK=6,
    MP_STAGE_TEMPLE=1
} MP_STAGE_SELECTED;

typedef enum MPSCENARIOS {
    SCENARIO_2v1=7,
    SCENARIO_2v2=5,
    SCENARIO_3v1=6,
    SCENARIO_LTK=4,
    SCENARIO_MWTGG=3,
    SCENARIO_NORMAL=0,
    SCENARIO_TLD=2,
    SCENARIO_YOLT=1
} MPSCENARIOS;

typedef enum WATCH_BRIEFING_PAGE {
    BRIEFING_M=2,
    BRIEFING_MONEYPENNY=4,
    BRIEFING_OVERVIEW=1,
    BRIEFING_Q=3,
    BRIEFING_TITLE=0
} WATCH_BRIEFING_PAGE;

typedef enum MENU {
    MENU_007_OPTIONS=9,
    MENU_BRIEFING=10,
    MENU_CHEAT=21,
    MENU_DIFFICULTY=8,
    MENU_DISPLAY_CAST=24,
    MENU_EYE_INTRO=3,
    MENU_FILE_SELECT=5,
    MENU_GOLDENEYE_LOGO=4,
    MENU_LEGAL_SCREEN=0,
    MENU_MISSION_COMPLETE=13,
    MENU_MISSION_FAILED=12,
    MENU_MISSION_SELECT=7,
    MENU_MODE_SELECT=6,
    MENU_MP_CHAR_SELECT=15,
    MENU_MP_CONTROL_STYLE=17,
    MENU_MP_HANDICAP=16,
    MENU_MP_OPTIONS=14,
    MENU_MP_SCENARIO_SELECT=19,
    MENU_MP_STAGE_SELECT=18,
    MENU_MP_TEAMS=20,
    MENU_NINTENDO_LOGO=1,
    MENU_NO_CONTROLLERS=22,
    MENU_RAREWARE_LOGO=2,
    MENU_RUN_STAGE=11,
    MENU_SPECTRUM_EMU=25,
    MENU_SWITCH_SCREENS=23
} MENU;

#endif
