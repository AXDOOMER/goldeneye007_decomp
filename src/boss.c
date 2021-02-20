#include "ultra64.h"
#include "ramrom.h"
#include "boss.h"
#include "bondgame.h"
#include "game/debugmenu_090490.h"
#include "game/room_model_buffer.h"
#include "deb.h"
#include "game/stan.h"
#include "game/rsp.h"
#include "bondconstants.h"
#include "token.h"
#include "init.h"
#include "sched.h"
#include "game/unk_0C0A70.h"
#include "joy.h"
#include "dyn.h"
#include "debugmenu.h"
#include "speed_graph.h"
#include "video.h"
#include "bond.h"
#include "lvl.h"

/**
 * @file boss.c
 * This file contains the main game loop code. 
 */

/**
 * Copied from n64devkit\ultra\usr\src\pr\demos_old\simple\gfx.h
 */
typedef union {    

    struct {
        short   type;
    } gen;
    
    struct {
        short   type;
    } done;
    
    OSScMsg      app;
    
} GFXMsg;

// forward declarations
void mainloop(void);

/* data */
u32 boss_c_ptr_debug_notice_list_entry = 0;
s32 debug_and_update_stage_flag = 0;
LEVELID current_stage_num = LEVELID_TITLE;
u32 current_m_malloc_value = 0x234800;
u32 current_ma_malloc_value = 0x4B000;
s32 show_mem_use_flag = 0;
s32 show_mem_bars_flag = 0;

struct memallocstring memallocstringtable[] = {
{ LEVELID_DAM,          "-ml0 -me0 -mgfx70  -mvtx50 -mt625 -ma275"},
{ LEVELID_FACILITY,     "-ml0 -me0 -mgfx70  -mvtx50 -mt650 -ma160"},
{ LEVELID_RUNWAY,       "-ml0 -me0 -mgfx100 -mvtx50 -mt610 -ma300"},
{ LEVELID_SURFACE,      "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma300"},
{ LEVELID_BUNKER1,      "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma150"},
{ LEVELID_SILO,         "-ml0 -me0 -mgfx70  -mvtx50 -mt660 -ma150"},
{ LEVELID_FRIGATE,      "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma225"},
{ LEVELID_SURFACE2,     "-ml0 -me0 -mgfx100 -mvtx50 -mt550 -ma350"},
{ LEVELID_BUNKER2,      "-ml0 -me0 -mgfx100 -mvtx50 -mt725 -ma150"},
{ LEVELID_STATUE,       "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma220"},
{ LEVELID_ARCHIVES,     "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma250"},
{ LEVELID_STREETS,      "-ml0 -me0 -mgfx60  -mvtx40 -mt635 -ma290"},
{ LEVELID_DEPOT,        "-ml0 -me0 -mgfx60  -mvtx50 -mt710 -ma300"},
{ LEVELID_TRAIN,        "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma200"},
{ LEVELID_JUNGLE,       "-ml0 -me0 -mgfx70  -mvtx50 -mt500 -ma200"},
{ LEVELID_CONTROL,      "-ml0 -me0 -mgfx70  -mvtx50 -mt671 -ma200"},
{ LEVELID_CRADLE,       "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma250"},
{ LEVELID_CAVERNS,      "-ml0 -me0 -mgfx100 -mvtx50 -mt530 -ma250"},
{ LEVELID_AZTEC,        "-ml0 -me0 -mgfx60  -mvtx40 -mt855 -ma135"},
{ LEVELID_EGYPT,        "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma250"},
{ LEVELID_CITADEL,      "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma150"},
{ LEVELID_CUBA,         "-ml0 -me0 -mgfx100 -mvtx50 -mt300 -ma300"},
{ LEVELID_TITLE,        "-ml0 -me0 -mgfx80 -mvtx20 -mt646 -ma001"},
{ 0x5B,                 "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001"},
{ 0x63,                 "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001"},
{ LEVELID_TEMPLE,       "-ml0 -me0 -mgfx130 -mvtx100 -mt390 -ma100"},
{ LEVELID_COMPLEX,      "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
{ LEVELID_LIBRARY,      "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
{ LEVELID_BASEMENT,     "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
{ LEVELID_STACK,        "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
{ LEVELID_CAVES,        "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma300"},
{ 0x1AB,                "-ml0 -me0 -mgfx130 -mvtx100 -mt550 -ma170"},
{ 0x1A8,                "-ml0 -me0 -mgfx80  -mvtx100 -mt550 -ma250"},
{ 0x1B7,                "-ml0 -me0 -mgfx130 -mvtx100 -mt440 -ma220"},
{ 0x1B2,                "-ml0 -me0 -mgfx90  -mvtx100 -mt550 -ma230"},
{ 0x1B0,                "-ml0 -me0 -mgfx110 -mvtx100 -mt350 -ma400"},
{   0x0,                "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400"},
{ 0x0, },
{ 0x0, },
{ 0x0, }
};

LEVELID loadedstage = LEVELID_NONE;
s32 debug_feature_flag = 0;

// s32 D_80024304 = 0x20000;
// s32 D_80024308 = 0;
// s32 D_8002430C = 0;
// s32 D_80024310 = 0;
// s32 D_80024314 = 0;
// s32 D_80024318 = 0;
// s32 D_8002431C = 0;
// s32 D_80024320 = 0;

struct D_80024304_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkc;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1c;
} D_80024304 = { 0x20000 };

//s32 taskgrab_ramdump_num = 1;

// extern declarations
extern struct player *pPlayer;


/* rodata */

//const char aLevel_[] = "-level_";
//const char aMl0Me0Mgfx100Mvtx50Mt700Ma400_1[] = "          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400";
//const char aM[] = "-m";
//const char aM_1[] = "-m";

//***moved to mainloop
//const char aLevel__0[] = "-level_";
//const char aLevel__1[] = "-level_";
//const char aHard[] = "-hard";
//const char aHard_1[] = "-hard";
//const char aHard_2[] = "-hard";
//const char aMa[] = "-ma";
//const char aMa_0[] = "-ma";
//const char aU64_taskgrab_D_core[] = "u64.taskgrab.%d.core";

/**
 * 6930	70005D30
 *     ??? - uses "-level_", "-m" strings
 */
#define OS_USEC_TO_CYCLES(n)	(((u64)(n)*(osClockRate))/1000000LL)

void init_mainthread_data(void)
{
    OSMesg bossmsg;
    OSTimer bosstimer;
    OSMesgQueue bossmq;
    u32 temp_s0;
    u32 unused;
    s32 i;


    debInit();
    romCreateMesgQueue();
    establish_TLB_buffer_management_table();
    image_entries_load();
    mempInitDebugNoticeList();
    memaInit();
    bgInitDebugNoticeList();
    viInitDebugNoticeList();
    init_video_settings();
    init_indy_if_not_ready();
    debug_and_update_stage_flag = rmonIsFinalBuild();
    obInitDebugNoticeList();
    rspInitDebugNoticeList();
    dynInitDebugNoticeList();
    joyInit();
    osCreateMesgQueue(&bossmq, &bossmsg, 1);

    for (i = 0; i != MAXCONTROLLERS; i++)
    {
        osSetTimer(&bosstimer, OS_USEC_TO_CYCLES(100000), 0, &bossmq, &bossmsg);
        osRecvMesg(&bossmq, &bossmsg, 1);
        if (i == 1)
        {
            joyCheckStatusThreadSafe();
        }
        else if (i >= 2)
        {
            joyConsumeSamplesWrapper();
        }
    }

    if (tokenFind(1, "-level_") == 0)
    {
        debug_and_update_stage_flag = 1;
    }
    stanInitDebugNoticeList();
    gameInitDebugNoticeList();
    if (debug_and_update_stage_flag != 0)
    {
        tokenSetString("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
    }
    if (tokenFind(1, "-m") != 0)
    {
        current_m_malloc_value = (s32) (strtol(tokenFind(1, "-m"), 0, 0) << 0xa);
    }
    temp_s0 = (osVirtualToPhysical(&room_model_buffer) | 0x80000000);
    mempCheckMemflagTokens(temp_s0, (return_ptr_TLBallocatedblock() - temp_s0));
    mempResetBank(6);
    init_LnameX();
    lvInitDebugNoticeList();
    bossInitDebugNoticeList();
    textrelatedInit_REMOVED();
    debmenu7000ADA8();
    default_player_perspective_and_height();
    store_osgetcount();
    null_init_main_1();
    speedGraphDisplayListRelated();
    set_gu_scale();
    null_init_main_2();
    sub_GAME_7F000980();
    alloc_load_expand_ani_table();
    init_weapon_animation_groups_maybe();
    reset_counter_rand_body_head();
    null_init_main_3();
    sub_GAME_7F000B60();
    initGameData();
    sub_GAME_7F01D6E0();
    clear_ramrom_block_buffer_heading_ptrs();
}

/**
 * 6BF4	70005FF4
 *     1 ->"show mem use" debug memory display [800241B4]; fry AT,T6
 */
void enable_show_mem_use_flag(void) {
    show_mem_use_flag=TRUE;
}

/**
 * 6C04	70006004
 *     toggle "show mem bars" [800241B8]; fries V0,T6,T7
 */
void mem_bars_flag_toggle(void) {
    show_mem_bars_flag = show_mem_bars_flag ^ 1;
}

/**
 * 6C1C	7000601C
 *     loads primary resources and starts main program loop
 *     this is infinite.  Loops unconditionally: JAL 70006060
 */
void bossEntry(void) {
    init_mainthread_data();
    allocate_init_rsp_buffers();
    setupaudio();
    while(1){
       mainloop();
    }    
}



/**
 * 6C60	70006060
 *     main program loop
 *         70006090 tests memstring for "-level_##"
 *         700060DC if not title, tests memstring for "-hard#"
 *         70006160 follows...
 *         700061FC test if debug console unconnected [800241A4]
 *         700062EC follows...
 *         700062FC tests memstring for "-ma"
 *         7000633C allocates "-ma" bytes to mem bank 4
 *         7000635C reset player data pointers
 *         70006364 offsets stage number based on number of players unless main menu
 *         700063A0 parses and sets memory allocation, loads stage, etc.
 *         ...
 *         70006708 displays memory usage when active
 *         70006724 displays in-game debugger when active
 *         7000674C writes a full sync, end display list combo
 *         7000676C display mem use when active	[800241B4]
 *         700067A8 display mem bars when active	[800241B8]
 *         700067C0 follows...
 *         700067D8 tests if "u64.taskgrab.#.core" activated and dumps memory
 *         70006854 follows... (700068BC - stop demos)
 */
void mainloop(void)
{
    s32 done;
    s32 localSelectedNumPlayers;
    //////GFXMsg *localGfxFrameMsg;
    //OSMesg localGfxFrameMsg;

    s32 toggleFlag;
    s32 count;
    s32 stringIndex;
    s32 i;
    f32 f;
    u32 unknownVal;

    struct memallocstring *pallocStringIndex;

    s8 joyStickXPos;
    s8 joyStickYPos;
    u16 joyButtons;

    Gfx *gdl;
    Gfx *firstGdl;

    struct player *localPlayer;

    s32 localLoadedStage;

    //struct D_80024304_s localD_80024304;

    const unsigned char *tokenFindLevel;
    char taskGrabBuffer[20];
    char taskGrabFilename[20];

    done = 0;
    reset_mem_bank_5();

    if (tokenFind(1, "-level_") != 0)
    {
        tokenFindLevel = (const unsigned char *)tokenFind(1, "-level_");

        // quick hack strltolon, converts the two digit ASCII level to 32bit int
        current_stage_num = (s32) (((s32)tokenFindLevel[1] + (s32)(tokenFindLevel[0] * 10)) - 0x210);
    }

    if (current_stage_num != LEVELID_TITLE)
    {
        sub_GAME_7F01DF90();
        set_selected_folder_num(0);
        set_selected_difficulty(DIFFICULTY_AGENT);
        set_solo_and_ptr_briefing(current_stage_num);

        if (tokenFind(1, "-hard") != 0)
        {
            // convert ASCII difficulty value to int in set difficulty calls
            set_selected_difficulty(*tokenFind(1, "-hard") - '0');
            set_difficulty(*tokenFind(1, "-hard") - '0');
        }
    }

    randomSetSeed(osGetCount());

    while (!done)
    {
        GFXMsg *localGfxFrameMsg = NULL;

        struct D_80024304_s localD_80024304 = D_80024304;
        struct D_80024304_s *plocalD_80024304;

        // sp1B4.unk0 = (?32) D_80024304.unk0;
        // sp1B4.unk4 = (?32) D_80024304.unk4;
        // sp1B4.unkC = (?32) D_80024304.unkC;
        // sp1B4.unk8 = (?32) D_80024304.unk8;
        // sp1B4.unk10 = (?32) D_80024304.unk10;
        // sp1B4.unk14 = (?32) D_80024304.unk14;
        // sp1B4.unk1C = (?32) D_80024304.unk1C;
        // sp1B4.unk18 = (?32) D_80024304.unk18;

        toggleFlag = 0;

        test_if_recording_demos_this_stage_load(current_stage_num, get_current_difficulty());
        if (debug_and_update_stage_flag != 0)
        {
            stringIndex = -1;

            if (current_stage_num != LEVELID_TITLE && get_selected_num_players() >= 2)
            {
                stringIndex = 0;
                if (memallocstringtable != 0)
                {
                    pallocStringIndex = &memallocstringtable[0];
                    while(pallocStringIndex->id)
                    {
                        if (pallocStringIndex->id == (current_stage_num + 400))
                        {
                            break;
                        }

                        stringIndex++;
                        pallocStringIndex++;
                    }
                    
                    if (memallocstringtable[stringIndex].id == 0)
                    {
                        stringIndex = -1;
                    }
                }
            }

            if (stringIndex) {
                // empty
            }


            if (stringIndex < 0)
            {
                stringIndex = 0;

                if (memallocstringtable != 0)
                {
                    pallocStringIndex = &memallocstringtable[0];
                    while(pallocStringIndex->id)
                    {
                        if (pallocStringIndex->id == current_stage_num)
                        {
                            break;
                        }

                        stringIndex++;
                        pallocStringIndex++;
                    }
                }
            }

            tokenSetString(memallocstringtable[stringIndex].string);
        }

        // instruction padding, remove
        do {
            *((s32*)(0x80000000)) = 65;
        } while (0);
        do {
            *((s32*)(0x80010001)) = 66;
        } while (0);
        do {
            *((s32*)(0x80020002)) = 67;
        } while (0);
        // end instruction padding

        mempResetBank(4);
        obBlankResourcesLoadedInBank(4);
        if (tokenFind(1, "-ma") != 0)
        {
            current_ma_malloc_value = (s32) (strtol(tokenFind(1, "-ma"), NULL, 0) * 1024);
        }

        memaSetBuffer(mempAllocBytesInBank(current_ma_malloc_value, 4), current_ma_malloc_value);
        reset_play_data_ptrs();

        localSelectedNumPlayers = 0;
        if (current_stage_num != LEVELID_TITLE)
        {
            localSelectedNumPlayers = 1;
            if (get_selected_num_players() >= 2)
            {
                localSelectedNumPlayers = get_selected_num_players();
            }
        }

        init_player_data_ptrs_construct_viewports(localSelectedNumPlayers);
        dynInitMemory();
        joyCheckStatusThreadSafe();
        stage_load(current_stage_num);
        viInitBuffers();
        debmenuInit();
        sub_GAME_7F0C0B4C();
        speedGraphVideoRelated_2();

        while (osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&localGfxFrameMsg, 0) == 0)
        {
            // empty
        }

        unknownVal = 0;
        if (loadedstage < 0)
        {
            // loop29
            while (1)
            {
                osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&localGfxFrameMsg, 1);

                switch (localGfxFrameMsg->gen.type)
                {
                    default:
                        localLoadedStage = loadedstage;
                        break;

                    case 5:
                        localLoadedStage = *(s32 *)(0x800242FC);
                        unknownVal = 4U;
                        break;

                    case 2:
                        localLoadedStage = *(s32 *)(0x800242FC);
                        break;

                    case 1:
                    {
                        if ((u32) (osGetCount() - copy_of_osgetcount_value_1) < 0x5eb61U)
                        {
                            localLoadedStage = loadedstage;
                        }
                        else
                        {
                            localLoadedStage = loadedstage;

                            if (loadedstage < 0 && unknownVal < 2U)
                            {
                                plocalD_80024304 = &localD_80024304;

                                if (get_is_ramrom_flag() != 0)
                                {
                                    iterate_ramrom_entries_handle_camera_out();
                                }
                                else
                                {
                                    sub_GAME_7F0C0B4C();
                                }

                                video_DL_related_4();
                                speedGraphVideoRelated_2();
                                speedGraphVideoRelated_3(0x20000);
                                joyConsumeSamplesWrapper();
                                permit_stderr(0);
                                gdl = dynGetMasterDisplayList();
                                firstGdl = gdl;

                                if (debug_feature_flag != 0)
                                {
                                    joyStickXPos = joyGetStickX(0);
                                    joyStickYPos = joyGetStickY(0);
                                    joyButtons = joyGetButtons(0, 0xFFFF) & 0xFFFF;
                                    debug_feature_flag = debug_menu_processor(joyStickXPos, joyStickYPos, joyButtons & 0xFFFF, joyGetButtonsPressedThisFrame(0, 0xFFFF) & 0xFFFF);
                                }

                                manage_mp_game();
                                sub_GAME_7F09B41C();

                                if (current_stage_num != LEVELID_TITLE)
                                {
                                    for (i=0; i<getPlayerCount(); i++)
                                    {
                                        set_cur_player(sub_GAME_7F09B528(i));

                                        localPlayer = pPlayer;
                                        viSetViewSize(localPlayer->viewx, localPlayer->viewy);

                                        localPlayer = pPlayer;
                                        viSetViewPosition(localPlayer->viewleft, localPlayer->viewtop);

                                        sub_GAME_7F0BF800();
                                    }
                                }

                                gdl = sub_GAME_7F0BE30C(gdl);

                                if (get_debug_VisCVG_flag() != 0)
                                {
                                    // begin gbi macro calls.

                                    // temp_s3_2 = temp_s3 + 8;
                                    // temp_s3->unk0 = 0xE7000000;
                                    // temp_s3->unk4 = 0;
                                    // temp_s3_3 = temp_s3_2 + 8;
                                    // temp_s3_4 = temp_s3_3 + 8;
                                    // temp_s3_2->unk0 = 0xBA001402;
                                    // temp_s3_2->unk4 = 0;
                                    // temp_s3_5 = temp_s3_4 + 8;
                                    // temp_s3_3->unk0 = 0xF9000000;
                                    // temp_s3_3->unk4 = -1;
                                    // temp_s3_6 = temp_s3_5 + 8;
                                    // temp_s3_4->unk0 = 0xEE000000;
                                    // temp_s3_4->unk4 = -1;
                                    // temp_s3_7 = temp_s3_6 + 8;
                                    // temp_s3_5->unk4 = 4;
                                    // temp_s3_5->unk0 = 0xB9000201;
                                    // temp_s3_6->unk0 = 0xB900031D;
                                    // temp_s3_6->unk4 = 0xFA54040;
                                    // temp_s1_3 = viGetX(temp_s3_3, temp_s3_4, temp_s3_5, -1);
                                    // temp_s3_7->unk0 = (s32) ((((viGetY() - 1) & 0x3FF) * 4) | 0xF6000000 | (((temp_s1_3 - 1) & 0x3FF) << 0xE));
                                    // temp_s3_7->unk4 = 0;
                                    // phi_s3 = temp_s3_7 + 8;

                                    // these are filler / random guess.
                                    gDPPipeSync(gdl++);
                                    gDPSetCycleType(gdl++, G_CYC_2CYCLE);
                                    gDPSetAlphaCompare(gdl++, G_AC_NONE);
                                    gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
                                    gDPFillRectangle(gdl++, 0, 0, viGetX() - 1, viGetY() - 1);

                                    // end gbi macro calls.
                                }

                                gdl = debmenuDraw(gdl);

                                if (get_memusage_display_flag() != 0)
                                {
                                    gdl = speedGraphDisplay(gdl);
                                }

                                if (debug_feature_flag != 0)
                                {
                                    display_debug_menu_text_onscreen();
                                    gdl = print_debug_mcm_to_stdout(gdl);
                                }

                                // begin gbi macro calls.

                                // temp_v0_4 = phi_s3_3;
                                // temp_s3_9 = phi_s3_3 + 8;
                                // temp_v0_4->unk0 = 0xE9000000;
                                // temp_v0_4->unk4 = 0;
                                // temp_s3_9->unk0 = 0xB8000000;
                                // temp_s3_9->unk4 = 0;
                                // temp_s3_10 = temp_s3_9 + 8;

                                // these are filler / random guess.
                                gDPFullSync(gdl++);
                                gDPSetAlphaCompare(gdl++, G_AC_NONE);

                                // end gbi macro calls.

                                if (show_mem_use_flag != 0)
                                {
                                    nulled_mempLoopAllMemBanks();
                                    memaDumpPrePostMerge();
                                    dynRemovedFunc(gdl);
                                    nullsub_41(0);
                                    show_mem_use_flag = 0;
                                }

                                if (show_mem_bars_flag != 0)
                                {
                                    dynDrawMembars(gdl);
                                }

                                dynGetFreeGfx2(gdl);
                                dynSwapBuffers();
                                video_related_8();

                                if ((get_debug_taskgrab_val() != 0)
                                    && (joyGetButtonsPressedThisFrame(0, 0xC000) != 0)
                                    && (joyGetButtons(0, 0xC000) == 0xC000))
                                {
                                    static s32 taskgrab_ramdump_num = 1;

                                    while (1)
                                    {
                                        sprintf(taskGrabBuffer, "u64.taskgrab.%d.core", taskgrab_ramdump_num);

                                        if (check_file_found_on_indy(taskGrabBuffer, taskGrabFilename) != 0)
                                        {
                                            taskgrab_ramdump_num++;
                                            continue;
                                        }

                                        break;
                                    }

                                    indy_send_capture_data(taskGrabBuffer, 0x80000000, 0x400000);
                                }

                                load_rsp_microcode(firstGdl, gdl, 0, plocalD_80024304);
                                memaIterateAndMerge();
                                toggleFlag ^= 1;
                                speedGraphVideoRelated_3(0x10000);
                                unknownVal++;
                            }
                        }
                    }
                    break;

                    if (loadedstage >= 0)
                    {
                        break;
                    }

                    if (unknownVal == 0)
                    {
                        break;
                    }
                }
            }
        }

        unload_stage_text_data();
        stop_demo_playback();
        mempNullNextEntryInBank(4);
        obBlankResourcesLoadedInBank(4);
        current_stage_num = loadedstage;
        loadedstage = -1;
    }

    sub_GAME_7F0D1A7C();
}

/**
 * 7530	70006930
 *     run title [0x5A->loaded stage#]; fry AT
 *     redirect to 70006950: A0=0x5A
 */
void run_title_stage(void) {
    set_loaded_stage(LEVELID_TITLE);
}

/**
 * 7550	70006950
 *     A0->loaded stage# [800242FC]; fry AT
 *     0x5A jumps to folder select
 *     0x5B 
 *     0x63 
 */
void set_loaded_stage(LEVELID stage){
    loadedstage = stage;
}

/**
 * 755C	7000695C
 *     V0= stage# [800241A8]
 */
LEVELID get_stage_num(){
    return current_stage_num;
}

/**
 * 7568	70006968
 *     return to title screen from stage
 */
void return_to_title_from_level_end(void) {
#ifdef VERSION_JP
    display_objective_status_text_on_status_change();
    FUN_7f057a40();
#endif
    if ((get_stage_num() != LEVELID_CUBA) && (check_objectives_complete() != 0x0)) {
        end_of_mission_briefing();
    }
    run_title_stage();
}

/**
 * 75B4	700069B4
 *     V0=state of debug menu (1:on; 0:off) [80024300]
 */
s32 get_debug_parse_flag(void) {
    return debug_feature_flag;
}

/**
 * 75C0	700069C0
 *     V0= p->debug.notice.list entry for boss_c_debug using data at 800241A0
 */
void bossInitDebugNoticeList(void) {
    debTryAdd(&boss_c_ptr_debug_notice_list_entry, "boss_c_debug");
}


