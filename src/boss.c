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
#include "indy_comms.h"

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
s32 g_StageNum = LEVELID_TITLE;
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

s32 g_MainStageNum = LEVELID_NONE;
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
        osRecvMesg(&bossmq, &bossmsg, OS_MESG_BLOCK);
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
    
    GFXMsg *localGfxFrameMsg; // sp 468
    struct D_80024304_s localD_80024304; // sp 436

    s32 stringIndex;
    s32 toggleFlag; // sp 428
    Gfx *gdl;
    Gfx *firstGdl;


    s32 i;
    s32 count;

    s8 joyStickXPos;
    s8 joyStickYPos;
    u16 joyButtons;

    //struct D_80024304_s* ppp = &localD_80024304;

    struct player *localPlayer;

    s32 localMainStageNum;

    const unsigned char *tokenFindLevel;

    u32 stackpadding[52];
    u32 unknownVal;

    done = 0;
    reset_mem_bank_5();

    if (tokenFind(1, "-level_") != 0)
    {
        tokenFindLevel = (const unsigned char *)tokenFind(1, "-level_");

        // quick hack strltolon, converts the two digit ASCII level to 32bit int
        g_StageNum = (s32) (((s32)tokenFindLevel[1] + (s32)(tokenFindLevel[0] * 10)) - 0x210);
    }

    if (g_StageNum != LEVELID_TITLE)
    {
        sub_GAME_7F01DF90();
        set_selected_folder_num(0);
        set_selected_difficulty(DIFFICULTY_AGENT);
        set_solo_and_ptr_briefing(g_StageNum);

        if (tokenFind(1, "-hard") != 0)
        {
            // convert ASCII difficulty value to int in set difficulty calls
            set_selected_difficulty(*(const unsigned char*)tokenFind(1, "-hard") - '0');
            set_difficulty(*(const unsigned char*)tokenFind(1, "-hard") - '0');
        }
    }

    randomSetSeed(osGetCount());

    while (!done)
    {
        u32 stackpaddingaa[8];
        localGfxFrameMsg = NULL;
        localD_80024304 = D_80024304;

        toggleFlag = 0;
        unknownVal = 0;

        test_if_recording_demos_this_stage_load(g_StageNum, get_current_difficulty());
        if (debug_and_update_stage_flag != 0)
        {
            stringIndex = -1;

            if (g_StageNum != LEVELID_TITLE && get_selected_num_players() >= 2)
            {
                stringIndex = 0;

                while(memallocstringtable[stringIndex].id)
                {
                    if (memallocstringtable[stringIndex].id == (g_StageNum + 400))
                    {
                        break;
                    }

                    stringIndex++;
                }
                
                if (memallocstringtable[stringIndex].id == 0)
                {
                    stringIndex = -1;
                }
            }

            if (stringIndex)
            {
                // empty
            }

            if (stringIndex < 0)
            {
                stringIndex = 0;

                while(memallocstringtable[stringIndex].id)
                {
                    if (memallocstringtable[stringIndex].id == g_StageNum)
                    {
                        break;
                    }

                    stringIndex++;
                }
            }

            tokenSetString(memallocstringtable[stringIndex].string);
        }

        mempResetBank(4);
        obBlankResourcesLoadedInBank(4);
        if (tokenFind(1, "-ma") != 0)
        {
            current_ma_malloc_value = (s32) (strtol(tokenFind(1, "-ma"), NULL, 0) * 1024);
        }

        memaSetBuffer(mempAllocBytesInBank(current_ma_malloc_value, 4), current_ma_malloc_value);
        reset_play_data_ptrs();

        localSelectedNumPlayers = 0;
        if (g_StageNum != LEVELID_TITLE)
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
        stage_load(g_StageNum);
        viInitBuffers();
        debmenuInit();
        sub_GAME_7F0C0B4C();
        speedGraphVideoRelated_2();

        while (osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&localGfxFrameMsg, OS_MESG_NOBLOCK) == 0)
        {
            // empty
        }

        while (g_MainStageNum < 0 || unknownVal != 0)
        {
            osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&localGfxFrameMsg, OS_MESG_BLOCK);
            
            if (1)
            {
                // removed
            }
            
            switch (localGfxFrameMsg->gen.type)
            {
                case 1:
                {
                    if ((u32) (osGetCount() - copy_of_osgetcount_value_1) < 0x5eb61U)
                    {
                        // nothing to do.
                    }
                    else
                    {
                        if (g_MainStageNum < 0 && unknownVal < 2U)
                        {
                            localD_80024304.unk0 = gdl;

                            if (get_is_ramrom_flag())
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
                            gdl = firstGdl = dynGetMasterDisplayList();

                            if (debug_feature_flag != 0)
                            {
                                joyStickXPos = joyGetStickX(0);
                                joyStickYPos = joyGetStickY(0);
                                joyButtons = joyGetButtons(0, ANY_BUTTON);
                                debug_feature_flag = debug_menu_processor(joyStickXPos, joyStickYPos, joyButtons, joyGetButtonsPressedThisFrame(0, ANY_BUTTON));
                            }

                            manage_mp_game();
                            sub_GAME_7F09B41C();

                            if (g_StageNum != LEVELID_TITLE)
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

                            // Lets Visualise the Coverage Value used for Scilohete Anti-Ailising (edges)
                            // (done on the VI), also produces a cool looking linemode - providing AA is working.
                            if (get_debug_VisCVG_flag() != 0)
                            {
                                gDPPipeSync(gdl++); // 0xe7000000, 0x00000000
                                gDPSetCycleType(gdl++, G_CYC_1CYCLE); // 0xba001402, 0x00000000
                                gDPSetBlendColor(gdl++, 0xff, 0xff, 0xff, 0xff); // 0xf9000000, 0xffffffff
                                gDPSetPrimDepth(gdl++, 0xffff, 0xffff); // 0xee000000, 0xffffffff
                                gDPSetDepthSource(gdl++, G_ZS_PRIM); // 0xb9000201, 0x00000004
                                gDPSetRenderMode(gdl++, G_RM_VISCVG, G_RM_VISCVG2); // 0xb900031d, 0x0fa54040
                                gDPFillRectangle(gdl++, 0, 0, viGetX() - 1, viGetY() - 1);
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

                            gDPFullSync(gdl++); // 0xe9000000, 0x00000000
                            gSPEndDisplayList(gdl++); // 0xb8000000, 0x00000000

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
                                && (joyGetButtonsPressedThisFrame(0, (A_BUTTON | B_BUTTON)) != 0)
                                && (joyGetButtons(0, (A_BUTTON | B_BUTTON)) == (A_BUTTON | B_BUTTON)))
                            {
                                static s32 taskgrab_ramdump_num = 1;
                                char taskGrabBuffer[24];
                                s32 taskGrabFileSize;

                                while (1)
                                {
                                    sprintf(taskGrabBuffer, "u64.taskgrab.%d.core", taskgrab_ramdump_num);

                                    if (check_file_found_on_indy(taskGrabBuffer, &taskGrabFileSize) != NULL)
                                    {
                                        taskgrab_ramdump_num++;
                                        continue;
                                    }

                                    break;
                                }

                                indy_send_capture_data(taskGrabBuffer, 0x80000000, 0x400000);
                            }

                            if (1){
                                load_rsp_microcode(firstGdl, gdl, 0, localD_80024304.unk0);
                            }
                            unknownVal++;
                            memaIterateAndMerge();
                            toggleFlag ^= 1;
                            speedGraphVideoRelated_3(0x10000);
                        }
                    }
                }
                break;

                case 2:
                    unknownVal--;
                    break;

                case 5:
                    unknownVal = 4U;
                    break;
            
            }

        }

        unload_stage_text_data();
        stop_demo_playback();
        mempNullNextEntryInBank(4);
        obBlankResourcesLoadedInBank(4);

        g_StageNum = g_MainStageNum;
        g_MainStageNum = -1;
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
    g_MainStageNum = stage;
}

/**
 * 755C	7000695C
 *     V0= stage# [800241A8]
 */
LEVELID get_stage_num(){
    return g_StageNum;
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


