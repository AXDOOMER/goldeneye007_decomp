#ifndef _MUSIC_H_
#define _MUSIC_H_

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

extern s32 music_unused;
extern s32 music1_track_num;
extern s32 music1len;
extern s32 music2_track_num;
extern s32 music2len;
extern s32 music3_track_num;
extern s32 music3len;
extern s32 music1_playing;
extern s32 music2_playing;
extern s32 music3_playing;

extern u32 hp[4];
extern u32 *ptr_sfx_buf;
extern s32 D_80063724;
extern s32 ptr_1st_music_ctrl_block;
extern s32 ptr_2nd_music_ctrl_block;
extern s32 ptr_3rd_music_ctrl_block;
extern void *ptr_musicdatatable;

extern char D_80063738[0x80];
extern char D_800637B8[0x7E];
extern s16 D_80063836;
extern s32 D_80063838;
extern s32 D_8006383C;
extern s32 D_80063840;
extern s16 D_80063844;
extern s16 D_80063846;
extern s16 D_80063848;
extern s16 music1_length;
extern s16 music2_length;
extern s16 music3_length;
extern s32 music1_rate;
extern s32 music2_rate;
extern s32 music3_rate;
extern s32 D_8006385C;
extern char D_80063860[0xF8];
extern char D_80063958[0xF8];
extern char D_80063A50[0x100];
extern char D_80063B50[0x54];
extern s32 D_80063BA4;
extern s32 D_80063BA8;

#endif
