/*
 COMPILE
/usr/bin/qemu-irix -silent -L tools/irix/root tools/irix/root/usr/bin/cc -Wab,-r4300_mul -non_shared -Olimit 2000 -G 0 -Xcpluscomm -woff 609,649,819,820,852,821,838 -I . -I include -I src -I src/game -I src/rarezip -mips2 -c build/test.c -o build/test.o -O2

PRE-COMPILE
 -E > build/testpre.c

 DISASSEMBLE
gdis -S build/test.o > build/test.txt

mips-linux-gnu-objdump --all-headers --disassemble --debugging --source --full-contents build/test.o > build/test1.mips

single regex for diff
  braces   |   non asm  |     addr     |       jal target                        |     Other targets         | Blank lines
((\{|\})\n)|(^.[^:]*$\n)|(^.*:.{11}\d?)|((?<=jal\t)([\d a b c d e f]{1,4} <.*\n))|([\d a b c d e f]{1,4} <.*)|(^$\n)
*/
111
#if 0

#    define TARGET_N64
/* #include "../src/game/chrobjdata.c"* /
#include "../src/bondconstants.h"
#include "../src/bondtypes.h" */
#    define DEB2UG 1
#    include "../src/ASSERT.H"
#    include "../src/bondgame.h"
#    include <limits.h>
#    include <math.h>

#    if 0 
 int aiAsTypedStructTest(char *ailist)
{

     //Variable array val
    {
         volatile struct
         {
             char cmd;
             char val[];
         } *ai = (ailist + 3);
        //8bit loa
        assert(*(char*)ai->val<=100); //# MATCH Assert Text

        //32 bit load (manual) - MATCH
        testflags(ai->cmd, ai->val[0] << 24 | ai->val[1] << 16 | ai->val[2] << 8 | ai->val[3]);

        //!32bit load (Compiler) - NOT MATCH
        testflags(ai->cmd, *(long *)ai->val);

        //16bit load (Compiler) - MATCH
        testflags(ai->cmd, *(unsigned short *)ai->val);

        //16bit load (manual) - MATCH
        testflags(ai->cmd, ai->val[0] << 8 | ai->val[1]);
    }
    //static char val
    {
        volatile struct
        {
            char cmd;
            char val;
        } *ai = (ailist + 3);

        assert(ai->val<=100); //MATCH

        //!32 bit load (manual) - NOT MATCH
        testflags(ai->cmd, *(((char*)ai->val)+0) << 24 | *(((char*)ai->val)+1) << 16 | *(((char*)ai->val)+2) << 8 | *(((char*)ai->val)+3));

        //!32bit load (Compiler) -  NOT MATCH
        testflags(ai->cmd, *(((unsigned long*)(char**)ai->val)));

        //!16bit load (Compiler) - NOT MATCH
        testflags(ai->cmd, *(unsigned short *)(char**)ai->val);

        //!16bit load (manual) - NOT MATCH
        //testflags(ai->cmd, ai->val[0] << 8 | ai->val[1]);

    }
    //typed struct
    {
        volatile struct
        {
            char cmd;
            short val;
            int val2;
            char val3;
        } *ai = (ailist[3]);
        assert(ai->val <= 100); //MATCH

        //32 bit load () - 
        testflags(ai->cmd, ai->val2);

        //16bit load () - 
        testflags(ai->cmd, ai->val);

        //8bit load () - 
        testflags(ai->cmd, ai->val3);

    }
    {
        volatile struct
        {
            char cmd;
            char val;
            char val2[2];
            char val4[1];
            char val3[4];
        } *ai6 = (ailist[3]);

        assert(ai6->val == 100);
        assert(*(unsigned short *)&ai6->val3 == 100);
        assert(*(short *)&ai6->val3 == 100);
        assert(*(unsigned int *)&ai6->val3 == 100);
        assert(*(int *)&ai6->val3 == 100);
        assert(*(float *)&ai6->val3 == 100);
    }
    return 0;
}
#    endif

#    define Debu2gAIExecute

#    ifdef DebugEnvironment
#        include <fog.h>
// CODE.bss:800825C0
s32 gEnvironmentHasFog;
// CODE.bss:800825C4
u32 ptr_nearfog_enviroment_values;
// CODE.bss:800825C8
sfarfogdetails
{
    s32 buffer_far_pervasiveness; // 0
    // CODE.bss:800825CC
    s32 far_fog; // 4
    // CODE.bss:800825D0
    s16 D_800825D0; // 8
    // CODE.bss:800825D4
    s32 D_800825D4; // c
    // CODE.bss:800825D8
    s32 flt_CODE_bss_800825D8; // 10
    // CODE.bss:800825DC
    s32 flt_CODE_bss_800825DC; // 14
}
Curfarfogdetails;
// CODE.bss:800825E0
s32 buffer_far_ambiant;
// CODE.bss:800825E4
s32 bg_dif_light;
// CODE.bss:800825E8
EnvironmentRecord *gEnvironmentFoundp;
// CODE.bss:800825EC
EnvironmentRecord *gEnvironmentMainp;
// CODE.bss:800825F0
EnvironmentRecord *gEnvironmentAltp;
// CODE.bss:800825F4
s32 D_800825F4;
// CODE.bss:800825F8
// u32 dword_CODE_bss_800825F8;
// static EnvironmentRecord PreviousEnvironment; //tempCurrentEnvp
u32 TransitionEnvironmentID;        // 0 22 during fac gas = Fac Previous ID
f32 TransitionEnvironmentBlendMult; // 4 4120 during fac gas blendmult /
                                    // buffer_far_pervasiveness2
f32 TransitionEnvironmentFarFog;    // 8 ScaledFarFogDist2 (447A0000)
f32 DAT_80082604;                   // near
f32 DAT_80082608;                   // maxvis
f32 DAT_8008260c;                   // max obf
f32 DAT_80082610;                   // minvis
u32 DAT_80082614;                   // 3e7 intens

s32 TransitionEnvironmentDiffFarFog;   // 3de diff
s32 TransitionEnvironmentFarIntensity; // 3e8 far
                                       /* Nope
                                        * typedef struct Row
                                           {
                                               u8 val : 5;
                                           } colour; */
vu8 TransitionEnvironmentSkyRed;       // r
vu8 TransitionEnvironmentSkyGreen;     // g
vu8 TransitionEnvironmentSkyBlue;      // b
u8 byte_CODE_bss_80082623;             // clouds
u8 byte_CODE_bss_80082624;             //{
u8 byte_CODE_bss_80082625;             // |
u8 byte_CODE_bss_80082626;             // | cldrep
u8 byte_CODE_bss_80082627;             //}
u8 byte_CODE_bss_80082628;             //{ skyimg
u8 byte_CODE_bss_80082629;             //}
u8 byte_CODE_bss_8008262a;             //{ res
u8 byte_CODE_bss_8008262b;             //}
u8 byte_CODE_bss_8008262c;
u8 byte_CODE_bss_8008262d;
u8 byte_CODE_bss_8008262e;
u8 byte_CODE_bss_8008262f;
u8 byte_CODE_bss_80082630;
u8 byte_CODE_bss_80082631;
u8 byte_CODE_bss_80082632;
u8 byte_CODE_bss_80082633;
u8 byte_CODE_bss_80082634;
u8 byte_CODE_bss_80082635;
u8 byte_CODE_bss_80082636;
u8 byte_CODE_bss_80082637;
u8 byte_CODE_bss_80082638;

// data
// D:80044DC0
s32 D_80044DC0 = 0;
// D:80044DC4
f32 near_fog_value = 3.4028235e38;
// D:80044DC8
f32 near_fog_times_intensity = 0.0;
// D:80044DCC
// Default Environment
CurrentEnvironmentRecord CurrentEnvironment = {
    0x384, // 0 dif_in_light
    0x3E8, // 4 far_ambiantlight
    0,     // 8,9,a,b RGBC
    0,     // ccloudrepeat
    0,     // 10skyimageid
    0,     // 14cloudred
    0,     // 18cloudgreen
    0,     // 1ccloudblue
    0,     // 20iswater
    0,     // 24waterrepeat
    0,     // 28waterimageid
    0,     // 2cwaterred
    0,     // 30watergreen
    0,     // 34 waterblue
    0,     // 38 waterconcavity
    0,     // 3c* extra?
    0      // 40*
};

EnvironmentRecord fog_tables[] = {

    {0x16, 15.0, 3500.0,  2000.0, 2500.0, 2000.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0,
     0,    8,    1,       5000.0, 0,      0,      170.0, 100.0, 40.0,  0,     0,
     0,    0,    -1000.0, 0,      0,      0.0,    0.0,   0.0,   30.0},
    {0x10, 15.0, 3500.0,  2000.0, 2500.0, 2000.0, 0.0,   1,     2,    3, 0,
     0,    8,    12,      5000.0, 0,      0,      170.0, 100.0, 40.0, 0, 0,
     0,    0,    -1000.0, 0,      0,      0.0,    0.0,   0.0,   30.0},
    {ENVIRONMENTDATA_END}

};

CurrentEnvironmentRecord *get_ptr_currentdata(void)
{
    return &CurrentEnvironment;
}

f32 get_near_fog_value(void)
{
    return near_fog_value;
}

f32 square_near_fog_value(void)
{
    return near_fog_value * near_fog_value;
}
extern void set_page_height();
extern void video_related_27();
extern int bgGetLevelVisibilityScale();

void copy_table1_env_to_current(EnvironmentRecord *fog_tables_Entry)
{
    f32 sp34;
    f32 sp30;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 temp_f14;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;
    f32 temp_ret;

    set_page_height(fog_tables_Entry->Visibility.blendmultiplier,
                    fog_tables_Entry->Visibility.farfog); // 30, 15000
    video_related_27(&sp30);
    temp_ret = bgGetLevelVisibilityScale();
    temp_f6  = sp30 / temp_ret;
    sp30     = temp_f6;
    sp34     = (f32)(sp34 / temp_ret);

    // arg1 = agr0;

    bg_dif_light =
        (f32)((f32)fog_tables_Entry->Fog.DifferenceFromFarIntensity / 1000.0f);

    temp_f14 = sp34 - temp_f6;

    buffer_far_ambiant =
        (f32)((f32)fog_tables_Entry->Fog.FarIntensity / 1000.0f);

    near_fog_value = (f32)(temp_f6 + (temp_f14 * buffer_far_ambiant));

    near_fog_times_intensity = (f32)(temp_f6 + (temp_f14 * bg_dif_light));

    Curfarfogdetails.buffer_far_pervasiveness =
        (f32)(fog_tables_Entry->Visibility.blendmultiplier / temp_ret);

    sp18    = (f32)(buffer_far_ambiant - bg_dif_light);
    temp_f4 = sp18;

    Curfarfogdetails.far_fog =
        (f32)(fog_tables_Entry->Visibility.farfog / temp_ret);
    sp20 = (f32)(128.0f / temp_f4);
    temp_f8 =
        Curfarfogdetails.far_fog - Curfarfogdetails.buffer_far_pervasiveness;
    sp18 = temp_f8;
    sp1C = (f32)(((0.5f - bg_dif_light) * 256.0f) / temp_f4);
    Curfarfogdetails.flt_CODE_bss_800825D8 =
        (f32)((((-sp20 * Curfarfogdetails.far_fog) *
                (Curfarfogdetails.buffer_far_pervasiveness + 1.0f)) /
               temp_f8) /
              255.0f);
    Curfarfogdetails.flt_CODE_bss_800825DC =
        (f32)(((((Curfarfogdetails.far_fog + 1.0f) * sp20) / temp_f8) + sp1C) /
              255.0f);

    CurrentEnvironment.Fog.DifferenceFromFarIntensity =
        (f32)fog_tables_Entry->Fog.DifferenceFromFarIntensity;
    CurrentEnvironment.Fog.FarIntensity = fog_tables_Entry->Fog.FarIntensity;
    CurrentEnvironment.Sky.red          = fog_tables_Entry->Sky.red;
    CurrentEnvironment.Sky.green        = fog_tables_Entry->Sky.green;
    CurrentEnvironment.Sky.blue         = fog_tables_Entry->Sky.blue;
    CurrentEnvironment.Sky.clouds       = fog_tables_Entry->Sky.clouds;
    CurrentEnvironment.Sky.cloudrepeat  = fog_tables_Entry->Sky.cloudrepeat;
    CurrentEnvironment.Sky.skyimageid   = fog_tables_Entry->Sky.skyimageid;
    CurrentEnvironment.Sky.cloudred     = fog_tables_Entry->Sky.cloudred;
    CurrentEnvironment.Sky.cloudgreen   = fog_tables_Entry->Sky.cloudgreen;
    CurrentEnvironment.Sky.cloudblue    = fog_tables_Entry->Sky.cloudblue;
    CurrentEnvironment.Sky.iswater      = fog_tables_Entry->Sky.iswater;
    CurrentEnvironment.Sky.waterrepeat  = fog_tables_Entry->Sky.waterrepeat;
    CurrentEnvironment.Sky.waterimageid = fog_tables_Entry->Sky.waterimageid;
    CurrentEnvironment.Sky.waterred     = fog_tables_Entry->Sky.waterred;
    CurrentEnvironment.Sky.watergreen   = fog_tables_Entry->Sky.watergreen;
    CurrentEnvironment.Sky.waterblue    = fog_tables_Entry->Sky.waterblue;
    CurrentEnvironment.Sky.waterconcavity =
        fog_tables_Entry->Sky.waterconcavity;

    // Simplify Above to:
    // CurrentEnvironment.Fog = fog_tables_Entry->Fog;
    // CurrentEnvironment.Sky = fog_tables_Entry->Sky;
    if (fog_tables_Entry->Visibility.nearfog = 0)
    {
        ptr_nearfog_enviroment_values = 0;
    }
    else
    {
        ptr_nearfog_enviroment_values =
            (s32)(fog_tables_Entry->Visibility.nearfog); // not a pointer
    }
    gEnvironmentHasFog = 1;
    // return &CurrentEnvironment;
}
void load_enviroment(int StageID, int param_2)
{
    s32 NumPlayers;
    u32 EnvironmentUID;
    EnvironmentRecord *FogTablep;
    EnvironmentFoglessRecord *FogTableFoglessp;
    EnvironmentFoglessRecord *FogTableFoglessFoundp;

    NumPlayers = get_num_players();
    if (NumPlayers == 1)
    {
        NumPlayers = 0;
    }

    ScaledFarFogIntensity               = default_near_fog;
    ScaledDifferenceFromFarFogIntensity = 0.00000000;

    if (isCutscene)
    {
        FogTablep      = fog_tables;
        EnvironmentUID = fog_tables[0].ID;
        while (EnvironmentUID != ENVIRONMENTDATA_END)
        {
            if (StageID + ENVIRONMENTDATA_CINEMA == EnvironmentUID)
            {
                gEnvironmentFoundp = FogTablep;
                gEnvironmentMainp  = FogTablep;
                gEnvironmentAltp   = FogTablep + 1;
                copy_table1_env_to_current(gEnvironmentFoundp);
                return;
            }
            EnvironmentUID = FogTablep[1].ID; // Next ID
            FogTablep++;
        }
    }

    EnvironmentUID = fog_tables[0].ID;
    FogTablep      = fog_tables;
    while (EnvironmentUID != ENVIRONMENTDATA_END)
    {
        if (StageID + NumPlayers * 100 == EnvironmentUID)
        {
            gEnvironmentFoundp = FogTablep;
            gEnvironmentMainp  = FogTablep;
            gEnvironmentAltp   = FogTablep + 1;
            copy_table1_env_to_current(gEnvironmentFoundp);
            return;
        }
        EnvironmentUID = FogTablep[1].ID;
        FogTablep++;
    }

    // default MP Skies
    if (NumPlayers > 1)
    {
        EnvironmentUID = fog_tables[0].ID;
        while (EnvironmentUID != ENVIRONMENTDATA_END)
        {
            if (NumPlayers * 100 == EnvironmentUID)
            {
                gEnvironmentFoundp = FogTablep;
                gEnvironmentMainp  = FogTablep;
                gEnvironmentAltp   = FogTablep + 1;
                copy_table1_env_to_current(gEnvironmentFoundp);
                return;
            }
            EnvironmentUID = FogTablep[1].ID;
            FogTablep++;
        }
    }

    // still no Environment, Assume Fogless
    set_page_height(15.00000000, (f32)flt_80058D74);
    gEnvironmentHasFog = 0;
    FogTableFoglessp   = fog_tables2;
    EnvironmentUID     = fog_tables2[0].ID;
    while (EnvironmentUID != ENVIRONMENTDATA_END)
    {
        if (StageID == EnvironmentUID)
        {
            FogTableFoglessFoundp = FogTableFoglessp;
        }
        EnvironmentUID = FogTableFoglessp[1].ID;
        FogTableFoglessp++;
    }

    // still No Environment?
    if (FogTableFoglessFoundp == NULL)
    {
        FogTableFoglessFoundp = fog_tables2; // Use first Fogless as default
    }
    copy_table2_env_to_current((int)FogTableFoglessFoundp);
    gEnvironmentFoundp = NULL; // Why bother, its never used again
    return;
}

void switch_to_solosky2(f32 Opacity)
{
    /*
     * called by 7f055f64
     Arg0 value table on activation
     0.000278
     0.1000
     0.105278 (1 frame = 0.000278)
     0.130278
     0.130556
     ...
     0.998889
     1
     1
     loop forever?
     */

    // cast static variables to EnvData
    EnvironmentRecord *TransitionEnvironmentp =
        (EnvironmentRecord *)&TransitionEnvironmentID;

    // EnvironmentRecord *gEnvironmentAltp = 0;

    *TransitionEnvironmentp = *gEnvironmentMainp; // copy values from 1st sky

    // NextEnvironmentp = gEnvironmentAltp; //dont name or assign, use directly

    // now alter some parts for transitioning to 2nd sky
    TransitionEnvironmentBlendMult =
        (gEnvironmentMainp->Visibility.blendmultiplier +
         (Opacity * (gEnvironmentAltp->Visibility.blendmultiplier -
                     gEnvironmentMainp->Visibility.blendmultiplier)));

    TransitionEnvironmentFarFog =
        (gEnvironmentMainp->Visibility.farfog +
         (Opacity * (gEnvironmentAltp->Visibility.farfog -
                     gEnvironmentMainp->Visibility.farfog)));

    TransitionEnvironmentDiffFarFog =
        (gEnvironmentMainp->Fog.DifferenceFromFarIntensity +
         (Opacity * ((f32)gEnvironmentAltp->Fog.DifferenceFromFarIntensity -
                     gEnvironmentMainp->Fog.DifferenceFromFarIntensity)));
    /*Match down to here--*/
    /*has extra lui	at,0x HI TransitionEnvironmentFarIntensity*/
    TransitionEnvironmentFarIntensity =
        (gEnvironmentMainp->Fog.FarIntensity +
         (Opacity * ((f32)gEnvironmentAltp->Fog.FarIntensity -
                     gEnvironmentMainp->Fog.FarIntensity)));

    {
#        if 0
        volatile f32 aa, bb, cc;
        volatile f32 a, b, c;
        a   = (Opacity * ((f32)gEnvironmentAltp->Sky.red -
                      gEnvironmentMainp->Sky.red));
        TransitionEnvironmentSkyRed =
            (gEnvironmentMainp->Sky.red + (u8)a) & 0xf8;
        b  = (Opacity * ((f32)gEnvironmentAltp->Sky.green -
                      gEnvironmentMainp->Sky.green));
        TransitionEnvironmentSkyGreen =
            (gEnvironmentMainp->Sky.green + (u8)b) & 0xf8;
        c = (Opacity * ((f32)gEnvironmentAltp->Sky.blue -
                      gEnvironmentMainp->Sky.blue));
        TransitionEnvironmentSkyBlue =
            (gEnvironmentMainp->Sky.blue + (u8)c) & 0xf8;
#        endif
        /*Closest to match but with andi order difference */
        TransitionEnvironmentSkyRed =
            (u32)(gEnvironmentMainp->Sky.red +
                  (Opacity * ((f32)gEnvironmentAltp->Sky.red -
                              gEnvironmentMainp->Sky.red))) &
            248;

        TransitionEnvironmentSkyGreen =
            (u32)(gEnvironmentMainp->Sky
                      .green + /*& f8 for Red happens round here*/
                  (Opacity * ((f32)gEnvironmentAltp->Sky.green -
                              gEnvironmentMainp->Sky.green))) &
            248;

        TransitionEnvironmentSkyBlue =
            (u32)(gEnvironmentMainp->Sky.blue +
                  /*& f8 for Green happens round here*/
                  (Opacity * ((f32)gEnvironmentAltp->Sky.blue -
                              gEnvironmentMainp->Sky.blue))) &
            248;

        /*& f8 for Blue happens round here*/
        // Store Bytes happen here but
        // cannot be repeated like below otherwise a1-a3 are produced
        // TransitionEnvironmentSkyRed &= 248;
        // TransitionEnvironmentSkyGreen &= 248;
        // TransitionEnvironmentSkyBlue &= 248;
        copy_table1_env_to_current(TransitionEnvironmentp);
    }
}
#    endif

#    ifdef DebugAIExecute

#        include "../src/bondaicommands.h" //make sure this is after constants
#        include "../src/game/chrai.h"
#        if 0
extern AIListRecord *g_chraiCurrentSetup.ailists;
extern AIListRecord *GlobalAILists;


// AI Test Data
char ailist1[] = {2, 3, 1, 2, 56, 3, 4};
u8 ailist3[]   = {1, 2, 3};
u8 ailist4[]   = {2, 3, 1, 2, 56, 3, 4};
// ailist *ailist1p = ailist1, *ailist2p = ailist2, *ailist3p =
// ailist3, *ailist4p = ailist4;
AIListRecord setup_actions[] = {{&ailist1, 1}};
// ailist *g_chraiCurrentSetup.ailists = &setup_actions;
#            if 0

//SetupPtrs
//{
    /*0x80075D00*/ u32 *g_chraiCurrentSetup.pathwaypoints;
    /*0x80075D04*/ u32 *g_chraiCurrentSetup.waypointgroups;
    /*0x80075D08*/ u32 *g_chraiCurrentSetup.intro;
    /*0x80075D0C*/ ObjectRecord *g_chraiCurrentSetup.propDefs;
    /*0x80075D10*/ u32 *g_chraiCurrentSetup.patrolpaths;
    /*0x80075D14*/ AIListRecord *g_chraiCurrentSetup.ailists; //*g_Lvailists;
    /*0x80075D18*/ u32 *g_chraiCurrentSetup.pads;
    /*0x80075D1C*/ u32 *g_chraiCurrentSetup.boundpads;
    /*0x80075D20*/ u32 *g_chraiCurrentSetup.padnames;
    /*0x80075D24*/ u32 *g_chraiCurrentSetup.boundpadnames;
    /*0x80075D28*/ u32 *dword_CODE_bss_80075D28;
    /*0x80075D30*/ u32 *objective_ptrs[3];
    /*0x80075D34*/
    /*0x80075D38*/
    /*0x80075D58*/ u32 *dword_CODE_bss_80075D58;
    /*0x80075D5C*/ u32 *dword_CODE_bss_80075D5C;
    /*0x80075D60*/ u32 *dword_CODE_bss_80075D60;
//} SetupTable;
#            endif
// SetupPtrs SetupTable = {0,0,0,0,0,setup_actions,0,0,0,0,0,{0,0,0 },0,
// 0,0};

//extern u8 *ailistFindById(u32 ailistID) {}
//extern ChrRecord *chrFindById(ChrRecord *ChrData, u8 ChrNum) {}

#            if 1

#            endif
//#        i f 1 



 }
}

#        endif

/*
possible struct
16 fe
16 0
32 1a
63x32 0
32 ptr
16 d
16 -1
3x32 0
32 -1
48x32 0

*/

#        if 0

/******************************************************************************
 * this is a brief description of func
 * with a new line
 * @param thing1 = number of theory
 * @param thing2 = thing21
 * @returns nothing
 *****************************************************************************/
void cstyle(int theory, int theory2) {}

/**
 * this is a brief description of func
 * with a new line
 * @param thing1 = number of theory
 * @param thing2 = thing21
 * @return nothing
 */
void cstyle2(int theory, int theory2) {}

/// <summary>
/// this is a test
/// </summary>
/// <param name="theory"> number of therory</param>
/// <param name="theory2"> thing2</param>
/// <returns>nothing</returns>
void cstyle43(int theory, int theory2) {}
#        endif

#        pragma region ExternStubs
extern ChrRecord *chrFindByLiteralId(s32 ID);
extern ChrRecord *chrFindById(ChrRecord *self, s32 chrnum);
extern void audioPlayFromProp2(s32 slot);
extern void loop_set_sound_effect_all_slots();
extern void audioPlayFromProp(s32 slot, s16 arg1);
extern void sub_GAME_7F0349BC(s32 slot);
extern s32 chraiitemsize(AIRecord *AIList, s32 offset);
extern s32 chraiGetAIListID(AIRecord *AIList, bool *isGlobalAIList);
extern s32 chraiGoToLabel(AIRecord *AIList, s32 Offset, s32 LabelNum);
extern AIRecord *ailistFindById(s32 ID);
extern PathRecord *pathFindById(s32 ID);


extern bool actor_aim_at_actor                               (ChrRecord *self, s32 targettype, s32 targetid);
extern bool actor_draws_throws_grenade_at_player_if_possible (ChrRecord *self);
extern bool actor_fire_or_aim_at_target_update               (ChrRecord *self, s32 targettype, s32 targetid);
extern bool actor_hops_sideways                              (ChrRecord *self);
extern bool actor_steps_sideways                             (ChrRecord *self);
extern bool actor_jogs_sideways                              (ChrRecord *self);
extern bool actor_kneel_aim_at_actor                         (ChrRecord *self, s32 targettype, s32 targetid);
extern bool actor_rolls_fires_crouched                       (ChrRecord *self);
extern bool actor_runs_and_fires                             (ChrRecord *self);
extern bool actor_walks_and_fires                            (ChrRecord *self);
extern bool alarmIsActive                                    ();                                                                                  // alarmIsActive
extern bool cheatIsActive                                    (s32 CheatID);                                                                       // cheatIsActive
extern bool check_2328_preset_set_with_method                (ChrRecord *basechr, u8 padid);
extern bool check_if_able_to_then_kneel                      (ChrRecord *self);
extern bool check_if_able_to_then_perform_animation          (ChrRecord *self, s32 animID, s32 b,s32 c, u8 d, u8 e);
extern bool check_if_actor_is_at_preset                      (ChrRecord *self, s32 padid);
extern bool check_if_position_in_same_room                   (ChrRecord *self,coord3d *pos,StandTile *stan);
extern bool check_if_room_for_preset_loaded                  (ChrRecord *self, s32 padid);                                                        //padid must be s32 to match
extern bool check_if_toxic_gas_activated                     ();
extern bool check_set_actor_standing_still                   (ChrRecord *self, s32 targettype, s32 targetid);
extern bool chraiStopAnimation                               (ChrRecord *self);
extern bool chrCanHearAlarm                                  (ChrRecord *self);                                                                   // alarm_timer_related
extern bool chrCanSeeBond                                    (ChrRecord *self);                                                                   // sub_GAME_7F0294BC
extern bool chrCheckTargetInSight                            (ChrRecord *self);                                                                   // sub_GAME_7F029D70
extern bool chrDropItem                                      (ChrRecord *self, s32 modelnum, ITEM_IDS weaponid);                                                     // actor_drops_itemtype_setting_timer
extern bool chrFadeOut                                       (ChrRecord *self);                                                                   // sub_GAME_7F0333A0
extern bool chrGoToBond                                      (ChrRecord *self, SPEED speed);                                                        // chrGoToBond
extern bool chrGoToChr                                       (ChrRecord *self, s32 chrid, SPEED speed);                                             // chrGoToChr
extern bool chrGoToPad                                       (ChrRecord *self, s32 padid, SPEED speed);                                             // actor_moves_to_preset_at_speed - MUST be s32 for padid
extern bool chrHasFlag                                       (ChrRecord *self, u8 flags);                                                        // chrHasFlag
extern bool chrHasFlagById                                   (ChrRecord *self, s32 ID, u8 flags);                                                 // sub_GAME_7F0332C0
extern bool chrHasStageFlag                                  (ChrRecord *self, s32 flags);                                                        // check_if_objective_bitflags_set
extern bool chrHeardTargetRecently                           (ChrRecord *self);                                                                   // sub_GAME_7F032BA0
extern bool chrIfInPadRoom                                   (ChrRecord *self, s32 chrnum, s32 padnum);                                           // chrIfInPadRoom
extern bool chrIfNearMiss                                    (ChrRecord *self);                                                                   // check_if_actor_invisible
extern bool chrIsDead                                        (ChrRecord *self);                                                                   // true_if_actor_dying_fading
extern bool chrIsHearingBond                                 (ChrRecord *self);                                                                   // check_if_actor_02_flag_set
extern bool chrIsStopped                                     (ChrRecord *self);                                                                   // check_if_actor_stationary
extern bool chrIsTargetNearlyInSight                         (ChrRecord *self);                                                                   // chrIsTargetNearlyInSight
extern bool chrSawDeath                                      (ChrRecord *self);                                                                   // check_if_actor_FB_target_set
extern bool chrSawInjury                                     (ChrRecord *self);                                                                   // check_if_actor_FA_target_set
extern bool chrSawTargetRecently                             (ChrRecord *self);                                                                   // sub_GAME_7F032B68
extern PropRecord *chrTryEquipHat                            (ChrRecord *self, s32 index, s32 flags);                                             // chrTryEquipHat
extern bool chrTryStartAlarm                                 (ChrRecord *self, s32 pad);                                                          // sub_GAME_7F034514
extern bool chrTrySurprisedLookAround                        (ChrRecord *self);                                                                   // check_if_able_to_then_look_flustered
extern bool chrTrySurprisedSurrender                         (ChrRecord *self);                                                                   //check_if_able_to_then_fawn_on_shoulder
extern bool chrTrySurprisedOneHand                           (ChrRecord *self);
extern bool countdownTimerIsRunning                          ();                                                                                  // get_clock_enable
extern bool handles_shot_actors                              (ChrRecord *self, s32 hitpart, vec3d *vector, ITEM_IDS weaponID, bool isPlayer);
extern bool isBondInTank                                     ();                                                                                  // get_intank_flag
extern bool objectiveIsAllComplete                           ();                                                                                  // check_objectives_complete
extern bool objIsHealthy                                     (ObjectRecord *self);                                                                 // check_if_object_has_not_been_destroyed
extern bool removed_animation_routine_27                     (ChrRecord *self);
extern bool removed_animation_routine_2B                     (ChrRecord *self);
extern bool sub_GAME_7F0333F8                                (ChrRecord *self);
extern bool sub_GAME_7F033AAC                                (ChrRecord *self, u8 padnum);
extern bool sub_GAME_7F033B38                                (ChrRecord *self, f32 distance);
extern bool sub_GAME_7F033F48                                (coord3d *coord3d, void *stantile, f32 facing, bool b);
extern bool sub_GAME_7F051E1C                                (WeaponObjRecord *prop, ChrRecord *chr);
extern bool is_prop_in_inventory                                (PropRecord *prop);
extern ObjectRecord* weaponFindThrown                                 (s32 ID);                                                                            // check_if_item_deposited
extern char *langGet                                         (s32 textID);                                                                        // get_textptr_for_textID
extern DIFFICULTY lvlGetSelectedDifficulty                              ();                                                                                  // get_current_difficulty
extern f32 chrGetAngleFromBond                               (ChrRecord *self);                                                                   //F03 2D70
extern f32 chrGetAngleToBond                                 (ChrRecord *self);
extern f32 chrGetDistanceToChr                               (ChrRecord *self, s32 chrID);                                                        // get_distance_between_actor_and_actorID
extern f32 chrGetDistanceToPad                               (ChrRecord *self, s32 padid);                                                        // sub_GAME_7F032E48
extern f32 chrGetTimer                                       (ChrRecord *self);                                                                   // get_loop_counter_time_in_seconds
extern f32 countdownTimerGetValue                            ();                                                                                  // get_clock_time
extern f32 bondviewGetCurrentPlayerHealth                         ();
extern f32 lvlGetCurrentMultiPlayerSec                                    ();                                                                                  // lvlGetCurrentMultiPlayerSec
extern f32 getsubroty                                        (Model *objinst);
extern f32 lvlGetCurrentMultiPlayerMin                                         ();                                                                                  // get_cur_mp_min
extern f32 chrGetDistanceFromBondToPad                     (ChrRecord *self, s32 padid);                                                        // get_distance_between_actor_and_preset
extern f32 chrGetDistanceToBond                            (ChrRecord *self);                                                                   // distToBond3D
extern s8 chrGetNumArghs                                    (ChrRecord *self);                                                                   // get_times_actor_shot
extern s8 chrGetNumCloseArghs                               (ChrRecord *self);                                                                   // get_num_shots_near_actor
extern int collect_or_interact_object                        (PropRecord *prop, bool showstring);
extern int objectiveGetCount                                 ();
extern u32 randomGetNext();
extern ObjectRecord *objFindByTagId                          (int TagID);                                                                          // get_handle_to_tagged_object
extern ObjectRecord *sub_GAME_7F056A88                       (int setupindex);
extern PropRecord *chrGetEquippedWeaponProp                  (ChrRecord *self, GUNHAND hand);                                                     // something_with_weaponpos_of_guarddata_hand
extern PropRecord *chrGetEquippedWeaponPropWithCheck         (ChrRecord *self, GUNHAND hand);                                                     // is_weapon_in_guarddata_hand
extern PropRecord *chrGiveWeapon                             (ChrRecord *self, s32 PropID, ITEM_IDS ItemID, s32 flags);                                // actor_draws_weapon_with_model
extern PropRecord *chrSpawnAtChr                             (ChrRecord *self, s32 bodynum, s32 headnum, s32 chrnum, AIRecord *ailist, s32 flags);// guard_constructor_BE
extern PropRecord *chrSpawnAtPad                             (ChrRecord *self, s32 bodynum, s32 headnum, s32 padid, AIRecord *ailist, s32 flags); // guard_constructor_BD
extern PropRecord *get_curplayer_positiondata                (); //bondGetProp
extern u8 getROOMID_Bitflags                        (int roomnum);
extern LEVELID bossGetStageNum                                   ();
extern s32 check_if_object_type_has_been_loaded              (ObjectRecord *obj);                                                                 //getObjIndex
extern s32 chrResolvePadId                                   (ChrRecord *self, s32 padID);                                                        // convertPadIf9000
extern s32 currentPlayerGetAmmoCount                         (AMMOTYPE type);                                                                         //check_cur_player_ammo_amount_total
extern s32 do_something_if_object_destroyed                  (ObjectRecord *obj);
extern s32 get_camera_mode                                   ();
extern s32 get_civilian_casualties                           ();
extern s32 getCurrentPlayerWeaponId                          (GUNHAND hand);                                                                      // get_item_in_hand
extern s32 getPlayerCount                                    ();
extern u8 getSelectedFolderBond                             ();
extern OBJECTIVESTATUS objectiveGetStatus(s32 objective); // get_status_of_objective
extern bool propobjInteract                                   (PropRecord *prop);                                                                  // sub_GAME_7F04F170
extern s32 sub_GAME_7F0539B8                                 (f32 vol);                                                                           ////
extern TagObjectRecord *sub_GAME_7F057080                    (s32 ID);                                                                             //
extern s32 propGetPlayerNum                                  ();      //get_cur_playernum                                                                            //
extern u8 getTileRoom                                        (StandTile *stan);                                                                    // 
extern void alarmActivate                                    ();                                                                                  // start_alarm
extern void alarmDeactivate                                  ();                                                                                  // stop_alarm
extern void attachNewChild                                   (PropRecord *child, PropRecord *parent);
extern void chrAddHealth                                     (ChrRecord *self, f32 amount);
extern void chrDropItems                                     (ChrRecord *self);                                                                   // sub_GAME_7F021B20
extern void chrRestartTimer                                  (ChrRecord *self);                                                                   // reset_and_start_loop_counter//
// PD extern void chrSetChrnum                                     (ChrRecord *self, int a) ;                                                            //
extern void chrSetChrPreset                                  (ChrRecord *self, s32 id);                                                           // sub_GAME_7F033CF4
extern void chrSetChrPreset2                                 (ChrRecord *self, int id, int id2);                                                  // sub_GAME_7F033D1C
extern void chrSetFlags                                      (ChrRecord *self, u8 flags);                                                        // sub_GAME_7F033218
extern void chrUnsetFlags                                    (ChrRecord *self, u8 flags);                                                        // sub_GAME_7F03322C
extern void chrUnsetFlagsById                                (ChrRecord *self, s32 chrid, u8 flags);                                             // sub_GAME_7F033290
extern void chrSetFlagsById                                  (ChrRecord *self, s32 flags, u8 id);                                                // sub_GAME_7F033260
extern void chrSetMaxDamage                                  (ChrRecord *self, f32 amount);
extern void chrSetPadPreset                                  (ChrRecord *self, s32 padid);                                                        // sub_GAME_7F033D5C
extern void chrSetPadPresetByChrnum                          (ChrRecord *self, s32 chrnum, s32 id);                                               // sub_GAME_7F033D84
extern void chrSetStageFlags                                 (ChrRecord *self, s32 flags);                                                        // toggle_objective_bitflags
extern void chrUnsetStageFlags                               (ChrRecord *self, s32 flags);                                                        // untoggle_objective_bitflags
extern void chrSetWeaponFlag4                                (ChrRecord *self, GUNHAND hand);                                                     // set_0x4_in_runtime_flags_for_item_in_guards_hand
extern void chrTrySurrender                                  (ChrRecord *self);                                                                   // check_if_able_to_then_surrender
extern void countdownTimerSetRunning                         (bool isRunning);                                                                    // set_clock_enable
extern void countdownTimerSetValue                           (f32 minutes);                                                                       // set_clock_time
extern void countdownTimerSetVisible                         (int clocklockbits, bool unset);                                                 // set_unset_clock_lock_bits
extern void currentPlayerEquipWeaponWrapper                  (GUNHAND hand, s32 next_weapon);                                                     // draw_item_in_hand_has_more_ammo
extern void currentPlayerSetFadeColour                       (s32 r, s32 g, s32 b, f32 frac);
extern void currentPlayerSetFadeFrac                         (f32 frames, f32 frac);
extern void bondviewSetIntroCameraFlags                             (PLAYERFLAG flag);                                                                   // set_flags_in_BONDdata_stationary_intro_cam () ;
extern void bondviewUnsetIntroCameraFlags                           (PLAYERFLAG flag);                                                                   // unset_flags_in_BONDdata_stationary_intro_cam() ;
extern void currentPlayerUnEquipWeaponWrapper                (GUNHAND hand, s8 WeapID);                                                           // remove_hands_item
extern void doorActivate                                     (DoorRecord *door, DOORSTATE State);                                                 // set_door_state
extern void doorActivateWrapper                              (PropRecord *prop);                                                                  // sub_GAME_7F05599C
extern void hudmsgBottomShow                                 (char *Text);                                                                        // display_string_in_lower_left_corner
extern void hudmsgTopShow                                    (char *Text);                                                                        // display_string_at_top_of_screen
extern void if_actor_able_set_on_path                        (ChrRecord *self, int pathid);
extern void imageSlotSetImage                                (MonitorRecord* mon, s32 monAnimID);                                                        // set_ptr_monitor_img_to_obj_ani_slot
extern void init_trigger_toxic_gas_effect                    (coord3d *colour);
extern void matrix_4x4_7F059908                              (Mtxf * matrix, f32 a, f32 b, f32 c, f32 lx, f32 ly, f32 lz, f32 ux, f32 uy, f32 uz);
extern void matrix_scalar_multiply                        (f32 scale, Mtxf *matrix);
extern void musicSetXReason                                  (int slot, int min, int sec);//set_musicslot_time
extern void musicUnsetXReason                                (int slot);//reset_music_in_slot
extern void propHide                                         (PropRecord *prop);                                                                  //propHide
extern void propobjSetDropped                                (PropRecord *prop, int a);                                                           // sub_GAME_7F04BFD0
extern void propweaponSetDual                                (WeaponObjRecord *leftweapon, WeaponObjRecord *rightweapon);                         // link_objects
extern void remove_item_in_hand                              (GUNHAND hand);
extern void bossReturnTitleStage                   () ;
extern void set_camera_mode                                  (s32 mode);
extern void set_unset_ammo_on_screen_setting                 (s32 flags, bool unset);
extern void set_unset_bitflags                               (s32 flags, bool unset);
extern void setsuboffset                                     (Model *Objinst, coord3d *pos);
extern void setsubroty                                       (Model *Objinst, f32 direction);
extern void sub_GAME_7F020D94                                (ChrRecord *self);                                                                   //
extern void sub_GAME_7F03A538                                (PropRecord *prop);                                                                  //add to proptree
extern void sub_GAME_7F03C2BC                                (PropRecord *prop, int type);
extern void sub_GAME_7F03D058                                (PropRecord *prop, bool a);
extern void sub_GAME_7F03E18C                                (PropRecord *prop);
extern void sub_GAME_7F03FDA8                                (PropRecord *prop);
extern void sub_GAME_7F03FE14                                (PropRecord *prop);
extern void sub_GAME_7F04088C                                (ObjectRecord *obj, PadRecord *pad, Mtxf *matrix, StandTile *stan, PadRecord *pad2);
extern void sub_GAME_7F04C044                                (PropRecord *prop);
extern void sub_GAME_7F052B00                                (DoorRecord *door);
extern void sub_GAME_7F053598                                (DoorRecord *door);                                                                  // doorActivatePortal
extern void sub_GAME_7F053B10                                (DoorRecord *door);
extern void sub_GAME_7F056CA0                                (ObjectRecord *obj);
extern void modelSetAnimation                                (Model *model, AnimTable2 *anim, int b, f32 startframe, float half, float e);
extern void modelSetAnimEndFrame                                (Model *model, float endframe);
extern void sub_GAME_7F08A928                                (int a);
extern void sub_GAME_7F08A944                                (PLAYERFLAG flag);
extern void maybe_detonate_object                            (ObjectRecord *baseobj, f32 damage, coord3d *pos, s32 flag, s32 flag2);
extern void SurroundWithExplosions                           (int delay);
extern void switch_to_solosky2                               (f32 Opacity);

#        include "../src/game/matrixmath.h"
extern void matrix_4x4_set_identity                          (Mtxf *matrix);

extern Player *pPlayer;
extern s32 stop_time_flag;               //bond.c
extern s32 g_GlobalTimer;                 //lvl.c
extern bool g_PlayerInvincible;          //bond.c disable_player_pickups_flag
extern bool g_isBondKIA;                 //mainmenu.c mission_kia_flag; 
extern f32 flt_CODE_bss_80079A00;        //bond.c
extern f32 flt_CODE_bss_80079A04;        //bond.c
extern f32 flt_CODE_bss_80079A08;        //bond.c
extern f32 flt_CODE_bss_80079A0C;        //bond.c
extern f32 flt_CODE_bss_80079A10;        //bond.c
extern s32 dword_CODE_bss_80079A14;      //bond.c
extern s32 D_8003643C;                   //bond.c credits state? 0=none, 1 = role 2 = done

extern s32 camera_8003642C;              //bond.c
extern s32 camera_80036434;              //bond.c
extern PadRecord *dword_CODE_bss_800799F8; //bond.c
extern CutsceneRecord *gBondViewCutscene; //bond.c 
extern s32 dword_CODE_bss_80079A18;      //bond.c
extern s32 dword_CODE_bss_80079A1C;      //bond.c
extern bool D_800364B0;                  //bond.c
extern ChrRecord *ptr_guard_data;        //chr.c(Not an array,(although it is) must be a pointer)
extern coord3d flt_CODE_bss_80079990;      //bond.c
extern s32 animation_table_ptrs1[];      // initanimtable.c Character Animations
extern AnimTable2* animation_table_ptrs2[];      // initanimtable.c Aircraft Animations
//extern coord3d gvector0;                 // D_80030A70 //Always 0 doesnt  seem to affect anything
//extern coord3d gvector2;                 // D_80030A7C //Always 0 never used?
extern s32 g_musicSfxBufferPtr;
extern void sndPlaySfx(s32 buffp, s32 vol, sfxRecord *sfx);
extern void sfxDeactivate(s32 sfxp);
//extern AIListRecord *GlobalAILists; // chrobjdata.c
AIListRecord GlobalAILists[] = { // Global AI Lists (GAILISTs)
    {1, "test"},
    {    2,    "test"}};
extern bool sndGetPlayingState(s32 a);
extern int sub_GAME_7F0539E4(PadRecord *pad); //getVolume?
extern int get_controls_locked_flag();
extern int sfx_c_70009184(s32 a0, s32 a1);

waypoint setup_path_tbl[];
waygroup setup_path_link[];
s32 setup_intro[];
ObjectRecord setup_objects[];
PathRecord setup_path_sets[];
AIListRecord setup_actions[]; //*g_LvAilists;
PadRecord pads[];             //0xxxpresets[];
BoundPadRecord boundpads[];   // 2xxxpresets[];
struct stagesetup setup = {
    setup_path_tbl,
    setup_path_link,
    setup_intro,
    setup_objects,
    setup_path_sets,
    setup_actions, //*g_LvAilists;
    pads,
    boundpads,
};
waypoint *g_chraiCurrentSetup.pathwaypoints;
waygroup* g_chraiCurrentSetup.waypointgroups;
s32 *g_chraiCurrentSetup.intro;
ObjectRecord *g_chraiCurrentSetup.propDefs;
PathRecord *g_chraiCurrentSetup.patrolpaths;
AIListRecord *g_chraiCurrentSetup.ailists; // *g_LvAilists;
PadRecord *g_chraiCurrentSetup.pads;
BoundPadRecord *g_chraiCurrentSetup.boundpads;
extern int gclock_timer;

#        pragma endregion

/*
enum SPEED
{
    SPEED_WALK,
    SPEED_JOG,
    SPEED_RUN
};

#        define PROP_TYPES(TYPE) \
            TYPE NUL TYPE OBJ TYPE DOOR TYPE CHR TYPE WEAPON TYPE PLAYER

typedef enum PROP_TYPE
{
    CREATE_TYPES(ENUM, PROP_TYPE, PROP_TYPES) PROPTYPE_COUNT
} PROP_TYPE;

#        ifdef DEBUG
char *PROPTYPE_ToString[] = {CREATE_TYPES(STRINGS, PROP_TYPE, PROP_TYPES)};
#        endif
*/
//coord3d gpos   = {0, 0, 0}; //D_80030A70

//near confirm
void *ptr_80030A88_3words[3];
// f32 D_80052974 = 0.016666666; Use literal
// f32 D_80052978 = 0.29166666; Use literal

//confirmed stuff below this line
//coord3d g_vector = {0, 0, 0};//D_80030A7C
/*0x80075D18*/ //PadRecord *g_chraiCurrentSetup.pads;      //=&stage[x].pads
/*0x80075D1C*/ //BoundPadRecord *g_chraiCurrentSetup.boundpads; //=&stage[x].boundpads
sfxRecord sfx_related[8];        //NOT Volatile
s32 num_guards           = 0;    //chr.c
s32 objectiveregisters1  = 0;    //objectiveregisters1
ChrRecord *g_ChrnumsB    = NULL; //objectiveregisters2
s32 g_NumChrsB           = 0;    //objectiveregisters3
extern s32 get_numguards();             //chr.c

#        define isNotBoundPad(pad)  pad < 10000
#        define getBoundPadNum(pad) pad - 10000
#        define ByteToRadian(Byte)  ((Byte * M_TAU) * (1.0f / 256.0f))
// Slightly wrong value. Why not use M_PI from gu.h?
#        define M_TAU               (3.14159275f * 2.0f)
// #    define each(Item, List) ()

#        if 0
int assertTest(void *Entityp, s32 EntityType)
{
    // initialise to 0
    VehichleRecord *VehichleEntityp = NULL; // a2
    AircraftRecord *AircraftEntityp = NULL; // v1
    ChrRecord *ChrEntityp           = NULL; // s7
    s32 regs1                       = 1;
    s32 regs2                       = 2;
    s32 regs3                       = 3;
    s32 regs4                       = 4;
    s32 regs5                       = 5;
    s32 regs6                       = 6;
    s32 regs7                       = 7;
    s32 regs8                       = 8;
    s32 regs9                       = 9;
    s32 regs10                       = 10;
    s32 regs11                       = 11;
    s32 regs0                       = 0; // s2 save/load tofrom sp7a4


    if (EntityType == PROP_TYPE_CHR) //ra,116  f20 48sp  f22 52sp
    {
        ChrEntityp = Entityp;
    }

    if (EntityType == PROP_TYPE_OBJ) //not elseif to stop double li,at,1
    {
        if (((ObjectRecord *)Entityp)->type == PROPDEF_VEHICHLE)
        {
            VehichleEntityp = Entityp;
        }
        else if (((ObjectRecord *)Entityp)->type == PROPDEF_AIRCRAFT)
        {
            AircraftEntityp = Entityp;
        }
    }
    // Load ailist
    if (ChrEntityp)
    {
        regs1   = ChrEntityp->accuracyrating;
        regs2   = ChrEntityp->speedrating;
        regs3   = ChrEntityp->sleep;
        regs4   = ChrEntityp->headnum;
        regs5    = ChrEntityp->invalidmove;
        regs6    = ChrEntityp->numarghs;
        regs7    = ChrEntityp->numclosearghs;
        regs8    = ChrEntityp->chrnum;
        regs0    = ChrEntityp->aioffset; // offset 0x108 264
        regs9    = ChrEntityp->chrwidth;
        regs10    = ChrEntityp->fadealpha;
        regs11    = ChrEntityp->field_184;
   }
    else if (VehichleEntityp) // truck
    {
        regs1   = ChrEntityp->accuracyrating;
        regs2   = ChrEntityp->speedrating;
        regs3   = ChrEntityp->sleep;
        regs4   = ChrEntityp->headnum;
        regs5   = ChrEntityp->invalidmove;
        regs6   = ChrEntityp->numarghs;
        regs7   = ChrEntityp->numclosearghs;
        regs8   = ChrEntityp->chrnum;

        regs0 = VehichleEntityp->aioffset; // offset 0x84 132
        regs9  = ChrEntityp->chrwidth;
        regs10 = ChrEntityp->fadealpha;
        regs11 = ChrEntityp->field_184;
    }
    else if (AircraftEntityp) // heli
    {
        regs1   = ChrEntityp->accuracyrating;
        regs2   = ChrEntityp->speedrating;
        regs3   = ChrEntityp->sleep;
        regs4   = ChrEntityp->headnum;
        regs5   = ChrEntityp->invalidmove;
        regs6   = ChrEntityp->numarghs;
        regs7   = ChrEntityp->numclosearghs;
        regs8   = ChrEntityp->chrnum;

        regs0 = AircraftEntityp->aioffset; // offset 0x84 132
        regs9  = ChrEntityp->chrwidth;
        regs10 = ChrEntityp->fadealpha;
        regs11 = ChrEntityp->field_184;
    }

    {
        for (;;) // loop forever (or until broken)
        {
            AIRecord *ai = ((AIRecord *)regs0 + regs6);
            switch (ai->cmd)
            {
                case AI_GOTO_NEXT:
                {
                    switch (((AIRecord *)regs3)->cmd)
                    {
                        case 0:
                            return;
                        case 1:
                            return;
                    }
                    regs0 = chraiGoT2oLabel(ChrEntityp, ai,regs0, regs1, regs2, regs3, regs4, regs5, regs6, regs7, regs8, regs9, regs10, regs11);
                    break;
                }
                case AI_GOTO_FIRST:
                {
                    switch (((AIRecord *)regs3)->cmd)
                    {
                        case 0:
                            return;
                        case 1:
                            return;
                    }
                    regs0 = chraiGoT2oLabel(ChrEntityp, ai, regs0, regs1, regs2, regs3, regs4, regs5, regs6, regs7, regs8, regs9, regs10, regs11);
                    break;
                }
            }
        }
    }
}
#        endif
#        pragma region MatchingRelatedFuncs
  extern s32 chrResolveId(ChrRecord *self, s32 ID);
#        if 0
  ChrRecord *chrFindByLiteralId(s32 ID) //#MATCH check_if_guardnum_loaded_get_ptr_GUARDdata chr.c
{
    s32 i;

    for (i = 0; i < num_guards; i++)
    {
        if ((ptr_guard_data[i].model != 0) && (ID == ptr_guard_data[i].chrnum))
        {
            return &ptr_guard_data[i];
        }
    }

    return NULL;
}
  
  ChrRecord *chrFindById(ChrRecord *self, s32 chrnum) //#MATCHchr2.c
  {
      ChrRecord *chr;
      s32 i;

      chrnum = chrResolveId(self, chrnum); //detect special IDs
      chr    = chrFindByLiteralId(chrnum);

      if (!chr) //cant find chr in ptr_guard_data
      {
          for (i = 0; i < g_NumChrsB; i++)
          {
              if (chrnum == g_ChrnumsB[i].chrnum) //check another array
              {
                  chr= &g_ChrnumsB[i]; //direct return didnt work
                  break;
              }
          }
      }

      return chr;
  }
//chrai.c below

void audioPlayFromProp2(s32 slot)//#MATCH :
{
    int tempvol;
    sfxRecord *sfx= &sfx_related[slot]; //always added to stack anyway, cleaner to use
    int clock_timer;

    if ((sfx->state ) && (sndGetPlayingState(sfx->state) ))
    {
    
        if (sfx->pad )
        {
            sfx->Volume = sub_GAME_7F0539E4(sfx->pad);   
        }
        else
        {
            if (sfx->Obj && sfx->Obj->prop)
            {
                //override pad with a co-ord,
                sfx->Volume = sub_GAME_7F0539E4(&sfx->Obj->runtime_pos);
            }
        }

        tempvol = sfx->Volume;
        if (sfx->sfxID >= 0)
        {
            clock_timer = gclock_timer;
            if (clock_timer < sfx->sfxID)
            {
                tempvol = (((sfx->Volume - sfx->Volume2) * clock_timer) / sfx->sfxID) + sfx->Volume2;
            }
            sfx->sfxID = sfx->sfxID - clock_timer;
        }
        if (get_controls_locked_flag() != 0)
        {
            tempvol = 0;
        }
        if (tempvol != sfx->Volume2)
        {
            sfx_c_70009184(sfx->state, 8);
            sfx->Volume2 = tempvol;
            return;
        }
        return;
    }
    sfx->Volume2 = 0;
}

void loop_set_sound_effect_all_slots() //# :match
{
    int i;
    for ( i = 0; i < 8; i++)
    {
        audioPlayFromProp2(i);
    }
}

void audioPlayFromProp(s32 slot, s16 arg1) //#MATCH  set_sound_effect_to_slot:
{
    sfxRecord *sfx = NULL; //always added to stack anyway, cleaner to use

    if (slot >= 0 && slot < 8)
    {
        //NOT Volatile
        if (!sfx_related[slot].state || !sndGetPlayingState(sfx_related[slot].state))
        {
            sfx = &sfx_related[slot];

            sfx->Volume  = SHRT_MAX;
            sfx->Volume2 = SHRT_MAX;
            sfx->sfxID   = -1;
            sfx->pad     = NULL;
            sfx->Obj     = NULL;
        }
    }
    sndPlaySfx(g_musicSfxBufferPtr, arg1, sfx);
}

void sub_GAME_7F0349BC(s32 slot) //# : MATCH
{
    if ((slot >= 0) && (slot < 8))
    {
        sfxDeactivate(sfx_related[slot].state);
    }
}

s32 chraiitemsize(AIRecord *AIList, s32 offset) // :case re-ordering (2 from 19 from end moved to near beginning)
{
    s32 pos;

    switch ((AIList+offset)->cmd)
    {
#            ifndef _SYNHILITE
#                define _AI_CMD(CODE)       /* : CMDNAME \
                                             */          \
                    case CAT(AI_, CMDNAME): /*           \
                                             */          \
                        return CAT(CAT(AI_, CMDNAME), _LENGTH);
#                define _AI_DEBUG(CODE)
#                define _AI_CMD_POLYMORPH(CMD, ALIAS, CMDPARAM, POLYPARAM, DESC)
#                include "../src/aicommands.def"
#            endif
        case AI_PRINT:

            pos = offset+1;
            //p = AIList;
            while (*(char*)(AIList + pos) != 0)
            {
                //offset++;
                pos++;
            }
            return (pos - offset) + 1;

        default:
#            ifdef DEBUG
            osSyncPrintf("chraiitemsize: unknown type %d!\n", (AIList + offset)->cmd);
#            endif
            return 1;
    }
}

s32 chraiGetAIListID(AIRecord *AIList, int *isGlobalAIList) //#MATCH :
{
    s32 i;

    if (setup.ailists ) //yes
    {
        for (i = 0; setup.ailists[i].ailist; i++)
        {
            if (setup.ailists[i].ailist == AIList)
            {
                *isGlobalAIList = FALSE;
                return setup.ailists[i].ID;
            }
        }
    }
    for (i = 0; GlobalAILists[i].ailist; i++)
    {
        if (GlobalAILists[i].ailist == AIList)
        {
            *isGlobalAIList = TRUE;
            return GlobalAILists[i].ID;
        }
    }
    return -1;    
}

s32 chraiGoToLabel(AIRecord *AIList, s32 Offset, s32 LabelNum) //#MATCH :
{
    s32 listID;
    char *debAIListTypeString;
    bool isGlobalAIList;

    for (;;)
    {
        if (AIList[Offset].cmd == AI_LABEL)
        {
            if (AIList[Offset].val[0] == LabelNum)
            {
                // exit loop and return offset to label number
                return Offset;
            }
        }
        else if (AIList[Offset].cmd == AI_ENDLIST)
        {
            // restart ai list PC if next label not found
            listID = chraiGetAIListID(AIList, &isGlobalAIList);
#            ifdef DEBUG
            if (isGlobalAIList)
            {
                debAIListTypeString = "global";
            }
            else
            {
                debAIListTypeString = "local";
            }
            osSyncPrintf("AI error: endlist reached jump label=%d %s list=%d!\n", LabelNum, debAIListTypeString, listID);
#            endif
            return 0;
        }

        Offset += chraiitemsize(AIList, Offset);
    }
}

AIRecord *ailistFindById(s32 ID) //#MATCH :
{
    int i;

    if (ID >= 0x401)
    {
        if (setup.ailists)
        {
            for (i = 0; setup.ailists[i].ailist; i++)
            {
                if (ID == setup.ailists[i].ID)
                {
                    return setup.ailists[i].ailist;
                }
            }
        }
    }
    else
    {
        for ( i = 0; GlobalAILists[i].ailist; i++)
        {
            if (ID == GlobalAILists[i].ID)
            {
                return GlobalAILists[i].ailist;
            }
        }
    }
    return NULL;
}

PathRecord *pathFindById(s32 ID) //#MATCH :get_ptr_path_for_pathnum
{
    int i;

        for  (i=0;setup.paths[i].waypoints;i++)
        {
            if ( ID == setup.paths[i].ID )
            {
                return &setup.paths[i];
            }
           
        }

    return NULL;
}
#        endif
#        pragma endregion
/**
 Execute AI List from Character, Stage, Vehichle(truck) or Aircraft(heli)
 Note: GE has little error checking (eg, using a chr action on aircraft) - this was fixed in PD
 @param *Entityp: Pointer to Entity (non-typed)
 @param EntityType: PROPTYPE_CHR or PROPTYPE_OBJ
 @param         PROPTYPE_CHR = Character (Guard or Stage)
 @param         PROPTYPE_OBJ = Object (Vehichle or Aircraft)
*/
void ai(PropDefHeaderRecord *Entityp, PROP_TYPE EntityType) //sp,sp,-1976
{
    /*
    * (void *Param, int ParamType) is the correct way to pass a variable
    *  "object" eg Param can be Either ChrRecord or VehichleRecord
    *
    *  Function Name derived from internal strings:
    *    ai(void) enery tune on (%d, %d, %d)
    *    ai(void) enery tune off (%d)
    */

    ChrRecord      *ChrEntityp      = NULL; // s7 [7b4 1974]
    VehichleRecord *VehichleEntityp = NULL; // a2 7b0 1968
    AircraftRecord *AircraftEntityp = NULL; // v1 7ac 1964
    AIRecord       *AiListp         = NULL; // s6 [7a8 1960]
    s32             Offset;                 // s2 7a4 1956 (good stack pos)

    if (EntityType == PROP_TYPE_CHR) //ra,116  f20 48sp  f22 52sp
    {
        ChrEntityp = Entityp;
    }
    else if (EntityType == PROP_TYPE_OBJ)
    {
        if (Entityp->type == PROPDEF_VEHICHLE)
        {
            VehichleEntityp = Entityp;
        }
        else if (Entityp->type == PROPDEF_AIRCRAFT)
        {
            AircraftEntityp = Entityp;
        }
    }

    // Load ailist
    if (ChrEntityp)
    {
        Offset  = ChrEntityp->aioffset; // offset 0x108 264
        AiListp = ChrEntityp->ailist;   // pointer 0x104 260
    }
    else if (VehichleEntityp) // truck
    {
        Offset  = VehichleEntityp->aioffset; // offset 0x84 132
        AiListp = VehichleEntityp->ailist;   // pointer 0x80 128
    }
    else if (AircraftEntityp) // heli
    {
        Offset  = AircraftEntityp->aioffset; // offset 0x84 132
        AiListp = AircraftEntityp->ailist;   // pointer 0x80 128
    }

    if (AiListp) // Has ailist (check once)
    {
        // loop forever (or until broken)
        for (;;)
        {
            /* 
            * GE uses long Switch/case while PD uses Bool functions and tests 
            * for TRUE/FALSE if(funcpointer[ai]) break; 
            */
            switch ((AiListp + Offset)->cmd)
            {
                //unfortunatly we cannot use the cmdbuilder as the ordering is different
#        ifdef USECMDBUILDER
#            define _AI_DEBUG_ID(CMD, AI_NUMBER_OF_PARAMS, PARAM, DESC)
#            define _AI_CMD_POLYMORPH(C, N, P1, P2, D)
#            define _AI_CMD_ID(CMD, AI_NUMBER_OF_PARAMS, PARAM, DESC, CODE) /* HACK: Multiline Comments make Newlines in macro */ \
                case CAT(CAT(AI_, CMD), ):                                  /*                                                    \
                                                                             */                                                   \
                    CODE
#            include "aicommands.def"
#        else
                case AI_GOTO_NEXT:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    Offset        = chraiGoToLabel(AiListp, Offset, ai->val);
#            ifdef DEBUG
                    osSyncPrintf(" (%d)\n", ai->val);
#            endif
                    break; //AI_GOTO_NEXT:
                }
                case AI_GOTO_FIRST:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    Offset        = chraiGoToLabel(AiListp, 0, ai->val);
#            ifdef DEBUG
                    osSyncPrintf(" (%d)\n", ai->val);
#            endif
                    break; //AI_GOTO_FIRST:
                }
                case AI_LABEL:
                {
                    Offset += 2;
                    break; //AI_LABEL:
                }
                case AI_SLEEP:
                {
                    Offset += 1;
                    if (ChrEntityp)
                    {
                        ChrEntityp->ailist   = AiListp;
                        ChrEntityp->aioffset = Offset;
                    }
                    else if (VehichleEntityp)
                    {
                        VehichleEntityp->ailist   = AiListp;
                        VehichleEntityp->aioffset = Offset;
                    }
                    else if (AircraftEntityp)
                    {
                        AircraftEntityp->ailist   = AiListp;
                        AircraftEntityp->aioffset = Offset;
                    }
                    return; //AI_SLEEP:
                }
                case AI_ENDLIST:
                {
#            ifdef DEBUG
                    osSyncPrintf("AI error endlist reached!\n");
#            endif
                    return; //AI_ENDLIST:
                }
                case AI_JUMP_TO_AI_LIST:
                {
                    AIRecord * ai = AiListp + Offset; /*needed for stack count inflation*/
                    ChrRecord *chr;                   //ok, so mips does not hoist vars in stack, they are in order so must be declaired here
                    /* removed to match 
                u8 AiListType  = ai->val[1];
                u8 AiListIndex = ai->val[2];
                */
                    u16        AI_LIST_ID = CharArrayTo16(ai->val,1); /*This is the only way to match despite assetrs below*/
                    u8         CHR_NUM    = ai->val[0];
                    if (CHR_NUM == ((u8)CHR_SELF))
                    {
                        AiListp = ailistFindById(AI_LIST_ID); /*Deliberate implied cast to s32*/
                        Offset  = 0;
                    }
                    else
                    {
                        chr = chrFindById(ChrEntityp, CHR_NUM);
                        if (chr)
                        {
                            chr->ailist   = ailistFindById(AI_LIST_ID);
                            chr->aioffset = 0;
                            chr->sleep    = 0;
                        }
                        Offset += 4;
                    }
                    break; //AI_JUMP_TO_AI_LIST:
                }
                case AI_SET_RETURN_AI_LIST:
                {
                    AIRecord *ai         = AiListp + Offset;
                    u16       AI_LIST_ID = CharArrayTo16(ai->val,0);
                    if (ChrEntityp)
                    {
                        ChrEntityp->aireturnlist = AI_LIST_ID;
                    }
                    else if (VehichleEntityp)
                    {
                        VehichleEntityp->aireturnlist = AI_LIST_ID;
                    }
                    else if (AircraftEntityp)
                    {
                        AircraftEntityp->aireturnlist = AI_LIST_ID;
                    }

                    Offset += 3;
                    break; //AI_SET_RETURN_AI_LIST:
                }
                case AI_JUMP_TO_RETURN_AI_LIST:
                {
                    if (ChrEntityp)
                    {
                        AiListp = ailistFindById(ChrEntityp->aireturnlist);
                    }
                    else if (VehichleEntityp)
                    {
                        AiListp = ailistFindById(VehichleEntityp->aireturnlist);
                    }
                    else if (AircraftEntityp)
                    {
                        AiListp = ailistFindById(AircraftEntityp->aireturnlist);
                    }
                    Offset = 0;
                    break; //AI_JUMP_TO_RETURN_AI_LIST:
                }
                case AI_GUARD_ANIMATION_STOP:
                {
                    chraiStopAnimation(ChrEntityp);
                    Offset += 1;
                    break; //AI_GUARD_ANIMATION_STOP:
                }
                case AI_GUARD_KNEEL:
                {
                    check_if_able_to_then_kneel(ChrEntityp);
                    Offset += 1;
                    break; //AI_GUARD_KNEEL:
                }
                case AI_GUARD_PLAY_ANIMATION:
                {
                    AIRecord *ai = AiListp + Offset;
                    s32       startframe, anim_id, zero, endframe;
                    anim_id    = CharArrayTo16(ai->val,0);
                    startframe = CharArrayTo16(ai->val,2);
                    endframe   = CharArrayTo16(ai->val,4);

                    if (startframe == (u16)-1)
                    {
                        startframe = 0;
                    }
                    if (endframe == (u16)-1)
                    {
                        endframe = -1;
                    }

                    if (ChrEntityp)
                    {
                        check_if_able_to_then_perform_animation(ChrEntityp, anim_id, startframe, endframe, ai->val[6], ai->val[7]);
                    }
                    else if (AircraftEntityp)
                    {
                        zero = 0; //debug value maybe?
                        modelSetAnimation(AircraftEntityp->model, animation_table_ptrs2[anim_id], zero, startframe, 0.5f, (s32)ai->val[7]);
                        if (endframe >= 0)
                        {
                            modelSetAnimEndFrame(AircraftEntityp->model, endframe);
                        }
                    }
                    Offset += 9;
                    break; //AI_GUARD_PLAY_ANIMATION:
                }
                case AI_IF_GUARD_PLAYING_ANIMATION:
                {
                    AIRecord1 *ai = (AiListp + Offset);
                    if (ChrEntityp->actiontype == ACT_ANIM)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_PLAYING_ANIMATION:
                }
                case AI_GUARD_POINTS_AT_BOND:
                {
                    chrTrySurprisedOneHand(ChrEntityp);
                    Offset += 1;
                    break; //AI_GUARD_POINTS_AT_BOND:
                }
                case AI_GUARD_LOOKS_AROUND_SELF:
                {
                    chrTrySurprisedLookAround(ChrEntityp);
                    Offset += 1;
                    break; //AI_GUARD_LOOKS_AROUND_SELF:
                }

                case AI_IF_GUARD_HAS_STOPPED_MOVING:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (chrIsStopped(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_HAS_STOPPED_MOVING:
                }
                case AI_IF_CHR_DYING_OR_DEAD:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);

                    if (!chr || chrIsDead(chr))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_CHR_DYING_OR_DEAD:
                }
                case AI_IF_CHR_DOES_NOT_EXIST:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);

                    if (!chr || !chr->model)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_CHR_DOES_NOT_EXIST:
                }
                case AI_IF_GUARD_SEES_BOND:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (chrCheckTargetInSight(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_SEES_BOND:
                }

                case AI_GUARD_TRY_SIDESTEPPING:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_steps_sideways(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_SIDESTEPPING:
                }
                case AI_GUARD_TRY_HOPPING_SIDEWAYS:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_hops_sideways(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_HOPPING_SIDEWAYS:
                }
                case AI_GUARD_TRY_JOGGING_TO_SIDE:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_jogs_sideways(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_JOGGING_TO_SIDE:
                }
                case AI_GUARD_TRY_FIRING_WALK:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_walks_and_fires(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_FIRING_WALK:
                }
                case AI_GUARD_TRY_FIRING_JOG:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_runs_and_fires(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_FIRING_JOG:
                }
                case AI_GUARD_TRY_FIRING_ROLL:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_rolls_fires_crouched(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_FIRING_ROLL:
                }
                case AI_GUARD_TRY_FIRE_OR_AIM_AT_TARGET:
                {
                    AIRecord *ai         = AiListp + Offset;
                    s32       targetid   = CharArrayTo16(ai->val,2);
                    s32       targettype = CharArrayTo16(ai->val,0);
                    if (actor_aim_at_actor(ChrEntityp, targettype, targetid))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += 6;
                    }
                    break; //AI_GUARD_TRY_FIRE_OR_AIM_AT_TARGET:
                }
                case AI_GUARD_TRY_FIRE_OR_AIM_AT_TARGET_KNEEL:
                {
                    AIRecord *ai         = AiListp + Offset;
                    s32       targetid   = CharArrayTo16(ai->val,2);
                    s32       targettype = CharArrayTo16(ai->val,0);
                    if (actor_kneel_aim_at_actor(ChrEntityp, targettype, targetid))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += 6;
                    }
                    break; //AI_GUARD_TRY_FIRE_OR_AIM_AT_TARGET_KNEEL:
                }

                case AI_IF_GUARD_IS_FIRING_AND_TARGET_180_RANGE:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (ChrEntityp->actiontype == ACT_ATTACK && !ChrEntityp->act_attack.type_of_motion && ChrEntityp->act_attack.attacktype & ATTACKTYPE_DONTTURN)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_IS_FIRING_AND_TARGET_180_RANGE:
                }
                case AI_IF_GUARD_IS_FIRING:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (ChrEntityp->actiontype == ACT_ATTACK)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_IS_FIRING:
                }

                case AI_GUARD_TRY_FIRE_OR_AIM_AT_TARGET_UPDATE:
                {
                    AIRecord *ai         = AiListp + Offset;
                    s32       targetid   = CharArrayTo16(ai->val,2);
                    s32       targettype = CharArrayTo16(ai->val,0);
                    if (actor_fire_or_aim_at_target_update(ChrEntityp, targettype, targetid))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += 6;
                    }
                    break; //AI_GUARD_TRY_FIRE_OR_AIM_AT_TARGET_UPDATE:
                }
                case AI_GUARD_TRY_FACING_TARGET:
                {
                    AIRecord *ai         = AiListp + Offset;
                    s32       targetid   = CharArrayTo16(ai->val,2);
                    s32       targettype = CharArrayTo16(ai->val,0);
                    if (check_set_actor_standing_still(ChrEntityp, targettype, targetid))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += 6;
                    }
                    break; //AI_GUARD_TRY_FACING_TARGET:
                }
                case AI_CHR_HIT_BODY_PART_WITH_ITEM_DAMAGE:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    vec3d      vec = New_Vector(); //gvector0;

                    if (chr && chr->prop)
                    {
                        handles_shot_actors(chr, (s8)ai->val[1], &vec, ai->val[2], NULL);
                    }

                    Offset += 4;
                    break; //AI_CHR_HIT_BODY_PART_WITH_ITEM_DAMAGE:
                }
                case AI_CHR_HIT_CHR_BODY_PART_WITH_HELD_ITEM:
                {
                    AIRecord * ai   = AiListp + Offset;
                    ChrRecord *chr1 = chrFindById(ChrEntityp, ai->val[0]);
                    ChrRecord *chr2 = chrFindById(ChrEntityp, ai->val[1]);

                    if (chr1 && chr2 && chr1->prop && chr2->prop)
                    {
                        PropRecord *     prop = chrGetEquippedWeaponPropWithCheck(chr1, GUNRIGHT);
                        WeaponObjRecord *weapon;
                        vec3d            vec = New_Vector();

                        if (!prop) //not Left hand? try left
                        {
                            prop = chrGetEquippedWeaponPropWithCheck(chr1, GUNLEFT);
                        }

                        if (prop) //hopefully have gun else exit
                        {
                            vec.x = chr2->prop->pos.x - chr1->prop->pos.x;
                            vec.y = chr2->prop->pos.y - chr1->prop->pos.y;
                            vec.z = chr2->prop->pos.z - chr1->prop->pos.z;
                            guNormalize(&vec.x, &vec.y, &vec.z);
                            if (prop)
                            {
                            } //prop needs upgrading to v1 instead of t
                            weapon = prop->weapon;
                            handles_shot_actors(chr2, (s8)ai->val[2], &vec, weapon->weaponnum, 0);
                        }
                    }
                    Offset += 4; //    CAT(CAT(AI_, CMDNAME), _LENGTH);
                    break;       //AI_CHR_HIT_CHR_BODY_PART_WITH_HELD_ITEM:
                }
                case AI_GUARD_TRY_THROWING_GRENADE:
                {
                    AIRecord1 *ai = AiListp + Offset;

                    if (actor_draws_throws_grenade_at_player_if_possible(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_THROWING_GRENADE:
                }
                case AI_GUARD_TRY_DROPPING_ITEM:
                {
                    AIRecord *ai       = AiListp + Offset;
                    u16       modelnum = CharArrayTo16(ai->val,0);
                    if (chrDropItem(ChrEntityp, modelnum, ai->val[2]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_GUARD_TRY_DROPPING_ITEM:
                }

                case AI_GUARD_SURRENDERS:
                {
                    chrTrySurrender(ChrEntityp);
                    Offset += 1;
                    break; //AI_GUARD_SURRENDERS:
                }
                case AI_GUARD_REMOVE_FADE:
                {
                    chrFadeOut(ChrEntityp);
                    Offset += 1;
                    break; //AI_GUARD_REMOVE_FADE:
                }
                case AI_CHR_REMOVE_INSTANT:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && chr->prop)
                    {
                        chr->hidden |= CHRHIDDEN_REMOVE;
                    }
                    Offset += 2;
                    break; //AI_CHR_REMOVE_INSTANT:
                }
                case AI_GUARD_TRY_TRIGGERING_ALARM_AT_PAD:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,0);
                    if (chrTryStartAlarm(ChrEntityp, pad_id))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_GUARD_TRY_TRIGGERING_ALARM_AT_PAD:
                }
                case AI_ALARM_ON:
                {
                    alarmActivate();
                    Offset += 1;
                    break; //AI_ALARM_ON:
                }
                case AI_ALARM_OFF:
                {
                    alarmDeactivate();
                    Offset += 1;
                    break; //AI_ALARM_OFF:
                }
                case AI_REMOVED_COMMAND27:
                { // run from bond
                    AIRecord1 *ai = AiListp + Offset;
                    if (removed_animation_routine_27(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_REMOVED_COMMAND27:
                }
                case AI_GUARD_TRY_JOGGING_TO_BOND_POSITION:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (chrGoToBond(ChrEntityp, SPEED_JOG))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_JOGGING_TO_BOND_POSITION:
                }
                case AI_GUARD_TRY_WALKING_TO_BOND_POSITION:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrGoToBond(ChrEntityp, SPEED_WALK))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_WALKING_TO_BOND_POSITION:
                }
                case AI_GUARD_TRY_RUNNING_TO_BOND_POSITION:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrGoToBond(ChrEntityp, SPEED_RUN))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_GUARD_TRY_RUNNING_TO_BOND_POSITION:
                }
                case AI_REMOVED_COMMAND2B:
                { //Find Cover
                    AIRecord *ai = AiListp + Offset;
                    if (removed_animation_routine_2B(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_REMOVED_COMMAND2B:
                }
                case AI_GUARD_TRY_JOGGING_TO_CHR_POSITION:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrGoToChr(ChrEntityp, ai->val[0], SPEED_JOG))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_GUARD_TRY_JOGGING_TO_CHR_POSITION:
                }
                case AI_GUARD_TRY_WALKING_TO_CHR_POSITION:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrGoToChr(ChrEntityp, ai->val[0], SPEED_WALK))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_GUARD_TRY_WALKING_TO_CHR_POSITION:
                }
                case AI_GUARD_TRY_RUNNING_TO_CHR_POSITION:
                {
                    AIRecord *ai = AiListp + Offset;

                    if (chrGoToChr(ChrEntityp, ai->val[0] & 0xff, SPEED_RUN)) // &0xff is here to increase t reg by 1
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_GUARD_TRY_RUNNING_TO_CHR_POSITION:
                }

                case AI_RANDOM_GENERATE_SEED:
                {
                    ChrEntityp->random = randomGetNext();
                    Offset += 1;
                    break; //AI_RANDOM_GENERATE_SEED:
                }
                case AI_IF_RANDOM_SEED_LESS_THAN:
                {
                    AIRecord *ai = AiListp + Offset;

                    if (ai->val[0] > ChrEntityp->random)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_RANDOM_SEED_LESS_THAN:
                }
                case AI_IF_RANDOM_SEED_GREATER_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < ChrEntityp->random)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_RANDOM_SEED_GREATER_THAN:
                }

                case AI_GUARD_JOGS_TO_PAD:
                {
                    AIRecord *ai  = AiListp + Offset;
                    u16       pad = CharArrayTo16(ai->val,0);
                    chrGoToPad(ChrEntityp, pad, SPEED_JOG);
                    Offset += 3;
                    break; //AI_GUARD_JOGS_TO_PAD:
                }
                case AI_GUARD_JOGS_TO_PAD_PRESET:
                { /* PD uses GoTo Pad (speed) which seems better
                switch (ai->val[0]) 
                { 
                    case SPEED_WALK: 
                        chrGoToPad(ChrEntityp, ChrEntityp->padpreset1, SPEED_WALK);
                        break; //AI_GUARD_JOGS_TO_PAD_PRESET: 
                    case SPEED_JOG: 
                        etc...
                */
                    chrGoToPad(ChrEntityp, ChrEntityp->padpreset1, SPEED_JOG);
                    Offset += 1;
                    break; //AI_GUARD_JOGS_TO_PAD_PRESET:
                }
                case AI_GUARD_WALKS_TO_PAD:
                {
                    AIRecord *ai  = AiListp + Offset;
                    u16       pad = CharArrayTo16(ai->val,0);
                    chrGoToPad(ChrEntityp, pad, SPEED_WALK);
                    Offset += 3;
                    break; //AI_GUARD_WALKS_TO_PAD:
                }
                case AI_GUARD_RUNS_TO_PAD:
                {
                    AIRecord *ai  = AiListp + Offset;
                    u16       pad = CharArrayTo16(ai->val,0);
                    chrGoToPad(ChrEntityp, pad, SPEED_RUN);
                    Offset += 3;
                    break; //AI_GUARD_RUNS_TO_PAD:
                }
                case AI_GUARD_START_PATROL:
                {
                    AIRecord *  ai   = AiListp + Offset;
                    PathRecord *path = pathFindById(ai->val[0]);
                    if_actor_able_set_on_path(ChrEntityp, path);
                    Offset += 2;
                    break; //AI_GUARD_START_PATROL:
                }
                case AI_IF_ALARM_IS_ON_UNUSED: // aiIfCanHearAlarm
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrCanHearAlarm(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_ALARM_IS_ON_UNUSED:
                }
                case AI_IF_ALARM_IS_ON:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (alarmIsActive())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_ALARM_IS_ON:
                }
                case AI_IF_GAS_IS_LEAKING:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (check_if_toxic_gas_activated())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GAS_IS_LEAKING:
                }
                case AI_IF_GUARD_HEARD_BOND:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrIsHearingBond(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_HEARD_BOND:
                }
                case AI_IF_GUARD_SEE_ANOTHER_GUARD_SHOT:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrSawInjury(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_SEE_ANOTHER_GUARD_SHOT:
                }
                case AI_IF_GUARD_SEE_ANOTHER_GUARD_DIE:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrSawDeath(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_SEE_ANOTHER_GUARD_DIE:
                }
                case AI_IF_GUARD_AND_BOND_WITHIN_LINE_OF_SIGHT:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrCanSeeBond(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_AND_BOND_WITHIN_LINE_OF_SIGHT:
                }
                case AI_IF_GUARD_AND_BOND_WITHIN_PARTIAL_LINE_OF_SIGHT:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrIsTargetNearlyInSight(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_AND_BOND_WITHIN_PARTIAL_LINE_OF_SIGHT:
                }
                case AI_IF_GUARD_WAS_SHOT_OR_SEEN_WITHIN_LAST_10_SECS:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrSawTargetRecently(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_WAS_SHOT_OR_SEEN_WITHIN_LAST_10_SECS:
                }
                case AI_IF_GUARD_HEARD_BOND_WITHIN_LAST_10_SECS:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrHeardTargetRecently(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_HEARD_BOND_WITHIN_LAST_10_SECS:
                }
                case AI_IF_GUARD_IN_ROOM_WITH_CHR:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, *ai->val);
                    if (chr && chr->prop && check_if_position_in_same_room(ChrEntityp, &chr->prop->pos, chr->prop->stan))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_IN_ROOM_WITH_CHR:
                }
                case AI_IF_GUARD_HAS_NOT_BEEN_SEEN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (!(ChrEntityp->chrflags & CHRFLAG_HAS_BEEN_ON_SCREEN))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_HAS_NOT_BEEN_SEEN:
                }
                case AI_IF_GUARD_IS_ON_SCREEN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if ((ChrEntityp->prop->flags & PROPFLAG_ONSCREEN))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_IS_ON_SCREEN:
                }
                case AI_IF_GUARD_ROOM_CONTAINING_SELF_IS_ON_SCREEN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (getROOMID_Bitflags(getTileRoom(ChrEntityp->prop->stan))) //this is not the cause of stack +8
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_ROOM_CONTAINING_SELF_IS_ON_SCREEN:
                }
                case AI_IF_ROOM_CONTAINING_PAD_IS_ON_SCREEN:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,0);
                    if (check_if_room_for_preset_loaded(ChrEntityp, pad_id))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_ROOM_CONTAINING_PAD_IS_ON_SCREEN:
                }
                case AI_IF_GUARD_IS_TARGETED_BY_BOND:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (sub_GAME_7F0333F8(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_IS_TARGETED_BY_BOND:
                }
                case AI_IF_GUARD_SHOT_FROM_BOND_MISSED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrIfNearMiss(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_GUARD_SHOT_FROM_BOND_MISSED:
                }
                case AI_IF_GUARD_COUNTER_CLOCKWISE_DIRECTION_TO_BOND_LESS_THAN:
                {
                    AIRecord *ai  = AiListp + Offset;
                    // Alternative Names?
                    // aiIfTargetInFovLeft or aiIfBondOutOfFov
                    float     rad = chrGetAngleToBond(ChrEntityp); //must use float to save "hidden var"
                    if (ByteToRadian((ai->val[0])) > rad)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_COUNTER_CLOCKWISE_DIRECTION_TO_BOND_LESS_THAN:
                }
                case AI_IF_GUARD_COUNTER_CLOCKWISE_DIRECTION_TO_BOND_GREATER_THAN:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     rad = chrGetAngleToBond(ChrEntityp);
                    if (ByteToRadian((ai->val[0])) < rad)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_COUNTER_CLOCKWISE_DIRECTION_TO_BOND_GREATER_THAN:
                }
                case AI_IF_GUARD_COUNTER_CLOCKWISE_DIRECTION_FROM_BOND_LESS_THAN:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     rad = chrGetAngleFromBond(ChrEntityp);
                    if (ByteToRadian((ai->val[0])) > rad)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_COUNTER_CLOCKWISE_DIRECTION_FROM_BOND_LESS_THAN:
                }
                case AI_IF_GUARD_COUNTER_CLOCKWISE_DIRECTION_FROM_BOND_GREATER_THAN:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     rad = chrGetAngleFromBond(ChrEntityp);
                    if (ByteToRadian((ai->val[0])) < rad)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_COUNTER_CLOCKWISE_DIRECTION_FROM_BOND_GREATER_THAN:
                }
                case AI_IF_GUARD_DISTANCE_TO_BOND_LESS_THAN:
                {
                    AIRecord *ai       = AiListp + Offset;
                    f32       distance = CharArrayTo16(ai->val,0)) * 10.0f;
                    if (distance > chrGetDistanceToBond(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_GUARD_DISTANCE_TO_BOND_LESS_THAN:
                }
                case AI_IF_GUARD_DISTANCE_TO_BOND_GREATER_THAN:
                {
                    AIRecord *ai       = AiListp + Offset;
                    f32       distance = CharArrayTo16(ai->val,0)) * 10.0f;
                    if (distance < chrGetDistanceToBond(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_GUARD_DISTANCE_TO_BOND_GREATER_THAN:
                }
                case AI_IF_CHR_DISTANCE_TO_PAD_LESS_THAN:
                {
                    AIRecord * ai     = AiListp + Offset;
                    ChrRecord *chr    = chrFindById(ChrEntityp, ai->val[0]);
                    u16        padnum = CharArrayTo16(ai->val,3));
                    f32        value  = CharArrayTo16(ai->val,1)) * 10.0f;
                    if (chr && (value > chrGetDistanceToPad(chr, padnum)))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += 7;
                    }
                    break; //AI_IF_CHR_DISTANCE_TO_PAD_LESS_THAN:
                }
                case AI_IF_CHR_DISTANCE_TO_PAD_GREATER_THAN:
                {
                    AIRecord * ai     = AiListp + Offset;
                    ChrRecord *chr    = chrFindById(ChrEntityp, ai->val[0]);
                    u16        padnum = CharArrayTo16(ai->val,3));
                    f32        value  = CharArrayTo16(ai->val,1)) * 10.0f;
                    if (chr && (value < chrGetDistanceToPad(chr, padnum)))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += 7;
                    }
                    break; //AI_IF_CHR_DISTANCE_TO_PAD_GREATER_THAN:
                }
                case AI_IF_GUARD_DISTANCE_TO_CHR_LESS_THAN:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       cutoff = CharArrayTo16(ai->val,0)) * 10.0f;
                    if (cutoff > chrGetDistanceToChr(ChrEntityp, ai->val[2]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_IF_GUARD_DISTANCE_TO_CHR_LESS_THAN:
                }
                case AI_IF_GUARD_DISTANCE_TO_CHR_GREATER_THAN:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       cutoff = CharArrayTo16(ai->val,0)) * 10.0f;
                    if (cutoff < chrGetDistanceToChr(ChrEntityp, ai->val[2]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_IF_GUARD_DISTANCE_TO_CHR_GREATER_THAN:
                }
                case AI_GUARD_TRY_SETTING_CHR_PRESET_TO_GUARD_WITHIN_DISTANCE:
                {
                    AIRecord *ai       = AiListp + Offset;
                    f32       distance = CharArrayTo16(ai->val,0)) * 10.0f;
                    if (sub_GAME_7F033B38(ChrEntityp, distance))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_GUARD_TRY_SETTING_CHR_PRESET_TO_GUARD_WITHIN_DISTANCE:
                }
                case AI_IF_BOND_DISTANCE_TO_PAD_LESS_THAN:
                {
                    AIRecord *ai    = AiListp + Offset;
                    u16       pad   = CharArrayTo16(ai->val,2));
                    f32       value = CharArrayTo16(ai->val,0)) * 10.0f;
                    if (value > chrGetDistanceFromBondToPad(ChrEntityp, pad))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += 6;
                    }
                    break; //AI_IF_BOND_DISTANCE_TO_PAD_LESS_THAN:
                }
                case AI_IF_BOND_DISTANCE_TO_PAD_GREATER_THAN:
                {
                    AIRecord *ai    = AiListp + Offset;
                    u16       pad   = CharArrayTo16(ai->val,2));
                    f32       value = CharArrayTo16(ai->val,0)) * 10.0f;
                    if (value < chrGetDistanceFromBondToPad(ChrEntityp, pad))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += 6;
                    }
                    break; //AI_IF_BOND_DISTANCE_TO_PAD_GREATER_THAN:
                }
                case AI_IF_CHR_IN_ROOM_WITH_PAD:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,1));
                    if (chrIfInPadRoom(ChrEntityp, ai->val[0], pad_id))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_IF_CHR_IN_ROOM_WITH_PAD:
                }
                case AI_IF_BOND_IN_ROOM_WITH_PAD:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,0);
                    if (check_if_actor_is_at_preset(ChrEntityp, pad_id))
                    {
#            if DEBUG
                        osSyncPrintf("BOND IN ROOM\n");
#            endif
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
#            if DEBUG
                        osSyncPrintf("bond not in room\n");
#            endif
                        Offset += 4;
                    }
                    break; //AI_IF_BOND_IN_ROOM_WITH_PAD:
                }
                case AI_IF_BOND_COLLECTED_OBJECT:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && is_prop_in_inventory(obj->prop))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_BOND_COLLECTED_OBJECT:
                }
                case AI_IF_ITEM_IS_STATIONARY_WITHIN_LEVEL:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (weaponFindThrown(ai->val[0]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_ITEM_IS_STATIONARY_WITHIN_LEVEL:
                }
                case AI_IF_ITEM_IS_ATTACHED_TO_OBJECT:
                {
                    struct
                    {
                        u8 cmd;
                        u8 val;
                        u8 val1;
                        u8 val2;
                    } *ai              = AiListp + Offset;
                    ObjectRecord *obj  = objFindByTagId(ai->val1);
                    bool          pass = FALSE;
                    if (obj && obj->prop)
                    {
                        PropRecord *prop = obj->prop->child;
                        while (prop)
                        {
                            if (prop->type == PROP_TYPE_WEAPON)
                            {
                                WeaponObjRecord *weapon = prop->weapon;
                                if (weapon->weaponnum == ai->val) //! need to swap t3 and t4 grrr
                                {
                                    pass = TRUE;
                                    break; //AI_IF_ITEM_IS_ATTACHED_TO_OBJECT:
                                }
                            }
                            prop = prop->prev;
                        }
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val2);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break;
                }
                case AI_IF_BOND_HAS_ITEM_EQUIPPED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] == getCurrentPlayerWeaponId(GUNRIGHT) || ai->val[0] == getCurrentPlayerWeaponId(GUNLEFT)) //order matters
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_BOND_HAS_ITEM_EQUIPPED:
                }
                case AI_IF_OBJECT_EXISTS: // aiIfGunUnclaimed
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_OBJECT_EXISTS:
                }
                case AI_IF_OBJECT_NOT_DESTROYED:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && objIsHealthy(obj))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_OBJECT_NOT_DESTROYED:
                }
                case AI_IF_OBJECT_WAS_ACTIVATED:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && (obj->runtime_bitflags & RUNTIMEBITFLAG_ACTIVATED))
                    {
                        obj->runtime_bitflags &= ~RUNTIMEBITFLAG_ACTIVATED;
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_OBJECT_WAS_ACTIVATED:
                }
                case AI_IF_BOND_USED_GADGET_ON_OBJECT:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && (obj->state & PROPSTATE_ACTIVATED))
                    {
                        obj->state &= ~PROPSTATE_ACTIVATED;
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_BOND_USED_GADGET_ON_OBJECT:
                }
                case AI_OBJECT_ACTIVATE:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        if (obj->prop->type == PROP_TYPE_DOOR)
                        {
                            doorActivateWrapper(obj->prop);
                        }
                        else if (obj->prop->type == PROP_TYPE_OBJ || obj->prop->type == PROP_TYPE_WEAPON)
                        {
                            propobjInteract(obj->prop);
                        }
                    }
                    Offset += 2;
                    break; //AI_OBJECT_ACTIVATE:
                }
                case AI_OBJECT_DESTROY:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        if (!do_something_if_object_destroyed(obj))
                        {
                            f32 damage = ((obj->damage - obj->maxdamage) + 1) / 250.0f;
                            maybe_detonate_object(obj, damage, &obj->runtime_pos, 29, -1);
                        }
                    }
                    Offset += 2;
                    break; //AI_OBJECT_DESTROY:
                }
                case AI_OBJECT_DROP_FROM_CHR:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->parent && obj->prop->parent->type == PROP_TYPE_CHR)
                    {
                        ChrRecord *chr = obj->prop->parent->chr;
                        propobjSetDropped(obj->prop, 2);
                        chr->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
                    }
                    Offset += 2;
                    break; //AI_OBJECT_DROP_FROM_CHR:
                }
                case AI_CHR_DROP_ALL_CONCEALED_ITEMS:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && chr->prop)
                    {
                        chrDropItems(chr);
                    }
                    Offset += 2;
                    break; //AI_CHR_DROP_ALL_CONCEALED_ITEMS:
                }
                case AI_CHR_DROP_ALL_HELD_ITEMS:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && chr->prop)
                    {
                        if (chr->weapons_held[GUNRIGHT])
                        {
                            propobjSetDropped(chr->weapons_held[GUNRIGHT], 1);
                            chr->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
                        }
                        if (chr->weapons_held[GUNLEFT])
                        {
                            propobjSetDropped(chr->weapons_held[GUNLEFT], 1);
                            chr->hidden |= CHRHIDDEN_DROP_HELD_ITEMS;
                        }
                    }
                    Offset += 2;
                    break; //AI_CHR_DROP_ALL_HELD_ITEMS:
                }
                case AI_BOND_COLLECT_OBJECT:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        bool a = collect_or_interact_object(obj->prop, 0);
                        sub_GAME_7F03C2BC(obj->prop, a);
                    }
                    Offset += 2;
                    break; //AI_BOND_COLLECT_OBJECT:
                }
                case AI_CHR_EQUIP_OBJECT:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    ChrRecord *   chr = chrFindById(ChrEntityp, ai->val[1]);
                    if (obj && obj->prop && chr)
                    {
                        if (obj->prop->parent)
                        {
                            sub_GAME_7F04C044(obj->prop);
                        }
                        else
                        {
                            sub_GAME_7F03E18C(obj->prop);
                            sub_GAME_7F03A538(obj->prop);
                            propHide(obj->prop);
                        }
                        if (obj->type != PROPDEF_COLLECTABLE || !sub_GAME_7F051E1C(obj, chr))
                        {
                            attachNewChild(obj->prop, chr->prop);
                        }
                    }
                    Offset += 3;
                    break; //AI_CHR_EQUIP_OBJECT:
                }
                case AI_OBJECT_MOVE_TO_PAD:
                {
                    AIRecord *          ai  = AiListp + Offset;
                    ObjectRecord *      obj = objFindByTagId(ai->val[0]);
                    volatile PadRecord *pad;
                    u16                 padnum = CharArrayTo16(ai->val,1));
                    Mtxf                matrix;

                    if (obj && obj->prop)
                    {
                        if (isNotBoundPad(padnum))
                        {
                            pad = &g_chraiCurrentSetup.pads[padnum];
                        }
                        else
                        {
                            pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padnum)];
                        }
                        matrix_4x4_7F059908(&matrix, 0, 0, 0, -pad->target.x, -pad->target.y, -pad->target.z, pad->up.x, pad->up.y, pad->up.z);
                        if (obj->model)
                        {
                            matrix_scalar_multiply(obj->model->scale, &matrix);
                        }
                        sub_GAME_7F04088C(obj, pad, &matrix, pad->stan, pad);
                        sub_GAME_7F056CA0(obj);
                    }
                    Offset += 4;
                    break; //AI_OBJECT_MOVE_TO_PAD:
                }
                case AI_DOOR_OPEN:
                {
                    AIRecord *  ai  = AiListp + Offset;
                    DoorRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        // DoorRecord *door = (DoorRecord *)obj;
                        doorActivate(obj, DOORSTATE_OPENING);
                    }
                    Offset += 2;
                    break; //AI_DOOR_OPEN:
                }
                case AI_DOOR_CLOSE:
                {
                    AIRecord *  ai  = AiListp + Offset;
                    DoorRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        //DoorRecord *door = (DoorRecord *)obj;
                        doorActivate(obj, DOORSTATE_CLOSING);
                    }
                    Offset += 2;
                    break; //AI_DOOR_CLOSE:
                }
                case AI_IF_DOOR_STATE_EQUAL:
                {
                    AIRecord *    ai   = AiListp + Offset;
                    ObjectRecord *obj  = objFindByTagId(ai->val[0]);
                    bool          pass = FALSE;
                    if (obj && obj->prop && obj->type == PROPDEF_DOOR)
                    {
                        DoorRecord *door = (DoorRecord *)obj;
                        if (door->openstate == DOORSTATE_STATIONARY)
                        {
                            if (door->openPosition <= 0)
                            {
                                pass = (ai->val[1] & DOOR_STATE_CLOSED) != 0;
                            }
                            else
                            {
                                pass = (ai->val[1] & DOOR_STATE_OPEN) != 0;
                            }
                        }
                        else if (door->openstate == DOORSTATE_OPENING || door->openstate == DOORSTATE_WAITING)
                        {
                            pass = (ai->val[1] & DOOR_STATE_OPENING) != 0;
                        }
                        else if (door->openstate == DOORSTATE_CLOSING)
                        {
                            pass = (ai->val[1] & DOOR_STATE_CLOSING) != 0;
                        }
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_DOOR_STATE_EQUAL:
                }
                case AI_IF_DOOR_HAS_BEEN_OPENED_BEFORE:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->type == PROPDEF_DOOR && (obj->runtime_bitflags & RUNTIMEBITFLAG_BEENOPENED))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_DOOR_HAS_BEEN_OPENED_BEFORE:
                }
                case AI_DOOR_SET_LOCK:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        DoorRecord *door = (DoorRecord *)obj;
                        u8          bits = ai->val[1];
                        door->keyflags   = door->keyflags | bits;
                    }
                    Offset += 3;
                    break; //AI_DOOR_SET_LOCK:
                }
                case AI_DOOR_UNSET_LOCK:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        DoorRecord *door = (DoorRecord *)obj;
                        u8          bits = ai->val[1];
                        door->keyflags &= ~bits;
                    }
                    Offset += 3;
                    break; //AI_DOOR_UNSET_LOCK:
                }
                case AI_IF_DOOR_LOCK_EQUAL:
                {
                    AIRecord *    ai   = AiListp + Offset;
                    ObjectRecord *obj  = objFindByTagId(ai->val[0]);
                    bool          pass = FALSE;
                    if (obj && obj->prop && obj->prop->type == PROP_TYPE_DOOR)
                    {
                        DoorRecord *door = (DoorRecord *)obj;
                        s32         bits = ai->val[1];
                        if ((door->keyflags & bits) == bits)
                        {
                            pass = TRUE;
                        }
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_DOOR_LOCK_EQUAL:
                }
                case AI_IF_OBJECTIVE_NUM_COMPLETE:
                {
                    struct
                    {
                        u8 cmd;
                        u8 val;
                        u8 label;
                    } *ai = AiListp + Offset;
                    /* additional PD code for dificulty filtering 
                    == OBJECTIVE_COMPLETE && objectivelvlGetSelectedDifficultyBits(ai->val[0]) & (1 << lvlGetSelectedDifficulty()))* 
                    */
                    if ((ai->val < objectiveGetCount()) && (objectiveGetStatus(ai->val) == OBJECTIVESTATUS_COMPLETE))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->label);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_OBJECTIVE_NUM_COMPLETE:
                }
                case AI_GUARD_TRY_UNKNOWN6E:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (check_2328_preset_set_with_method(ChrEntityp, ai->val[0]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_GUARD_TRY_UNKNOWN6E:
                }
                case AI_GUARD_TRY_UNKNOWN6F:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (sub_GAME_7F033AAC(ChrEntityp, ai->val[0]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_GUARD_TRY_UNKNOWN6F:
                }

                case AI_IF_GUARD_HITS_LESS_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > chrGetNumArghs(ChrEntityp)) //order matter
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_HITS_LESS_THAN:
                }
                case AI_IF_GUARD_HITS_GREATER_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < chrGetNumArghs(ChrEntityp)) //order matter
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_HITS_GREATER_THAN:
                }
                case AI_IF_GUARD_HITS_MISSED_LESS_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > chrGetNumCloseArghs(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_HITS_MISSED_LESS_THAN:
                }
                case AI_IF_GUARD_HITS_MISSED_GREATER_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < chrGetNumCloseArghs(ChrEntityp))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_HITS_MISSED_GREATER_THAN:
                }
                case AI_IF_CHR_HEALTH_LESS_THAN:
                {
                    AIRecord * ai    = AiListp + Offset;
                    f32        value = (ai->val[1]) * 0.1f;
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);

                    if (chr && ((chr->maxdamage - chr->damage) < value))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_CHR_HEALTH_LESS_THAN:
                }
                case AI_IF_CHR_HEALTH_GREATER_THAN:
                {
                    AIRecord * ai    = AiListp + Offset;
                    f32        value = (ai->val[1]) * 0.1f;
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);

                    if (chr && ((chr->maxdamage - chr->damage) > value))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_CHR_HEALTH_GREATER_THAN:
                }
                case AI_IF_CHR_WAS_DAMAGED_SINCE_LAST_CHECK:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && (chr->chrflags & CHRFLAG_WAS_DAMAGED))
                    {
                        chr->chrflags &= ~CHRFLAG_WAS_DAMAGED; // disable flag
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_CHR_WAS_DAMAGED_SINCE_LAST_CHECK:
                }
                case AI_IF_BOND_HEALTH_LESS_THAN:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     val = (ai->val[0]) / 255.0f;
                    if (val > bondviewGetCurrentPlayerHealth())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_BOND_HEALTH_LESS_THAN:
                }
                case AI_IF_BOND_HEALTH_GREATER_THAN:
                {
                    AIRecord *ai  = AiListp + Offset;
                    float     val = (ai->val[0]) / 255.0f;
                    if (val < bondviewGetCurrentPlayerHealth())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_BOND_HEALTH_GREATER_THAN:
                }
                case AI_IF_GAME_DIFFICULTY_LESS_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > lvlGetSelectedDifficulty())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GAME_DIFFICULTY_LESS_THAN:
                }
                case AI_IF_GAME_DIFFICULTY_GREATER_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < lvlGetSelectedDifficulty())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GAME_DIFFICULTY_GREATER_THAN:
                }
                case AI_IF_MISSION_TIME_LESS_THAN:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       target = CharArrayTo16(ai->val,0));
                    if (target > lvlGetCurrentMultiPlayerSec())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_MISSION_TIME_LESS_THAN:
                }
                case AI_IF_MISSION_TIME_GREATER_THAN:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       target = CharArrayTo16(ai->val,0));
                    if (target < lvlGetCurrentMultiPlayerSec())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_MISSION_TIME_GREATER_THAN:
                }
                case AI_IF_SYSTEM_POWER_TIME_LESS_THAN:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       target = CharArrayTo16(ai->val,0)) * 60.0f;
                    if (target > lvlGetCurrentMultiPlayerMin())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_SYSTEM_POWER_TIME_LESS_THAN:
                }
                case AI_IF_SYSTEM_POWER_TIME_GREATER_THAN:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       target = CharArrayTo16(ai->val,0)) * 60.0f;
                    if (target < lvlGetCurrentMultiPlayerMin())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_SYSTEM_POWER_TIME_GREATER_THAN:
                }
                case AI_IF_LEVEL_ID_LESS_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > bossGetStageNum())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_LEVEL_ID_LESS_THAN:
                }
                case AI_IF_LEVEL_ID_GREATER_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < bossGetStageNum())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_LEVEL_ID_GREATER_THAN:
                }
                case AI_LOCAL_BYTE_1_SET:
                {
                    AIRecord1 *ai      = AiListp + Offset;
                    ChrEntityp->morale = ai->val;
                    Offset += 2;
                    break; //AI_LOCAL_BYTE_1_SET:
                }
                case AI_LOCAL_BYTE_1_ADD:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (255 - ai->val < ChrEntityp->morale) //clamp to 255
                    {
                        ChrEntityp->morale = 255; //max
                    }
                    else
                    {
                        ChrEntityp->morale += ai->val;
                    }
                    Offset += 2;
                    break; //AI_LOCAL_BYTE_1_ADD:
                }
                case AI_LOCAL_BYTE_1_SUBTRACT:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (ai->val > ChrEntityp->morale) //clamp to 0
                    {
                        ChrEntityp->morale = 0;
                    }
                    else
                    {
                        ChrEntityp->morale -= ai->val;
                    }
                    Offset += 2;
                    break; //AI_LOCAL_BYTE_1_SUBTRACT:
                }
                case AI_IF_LOCAL_BYTE_1_LESS_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > ChrEntityp->morale)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_LOCAL_BYTE_1_LESS_THAN:
                }
                case AI_IF_LOCAL_BYTE_1_LESS_THAN_RANDOM_SEED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ChrEntityp->morale < ChrEntityp->random)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_LOCAL_BYTE_1_LESS_THAN_RANDOM_SEED:
                }
                case AI_LOCAL_BYTE_2_SET:
                {
                    AIRecord1 *ai         = AiListp + Offset;
                    ChrEntityp->alertness = ai->val;
                    Offset += 2;
                    break; //AI_LOCAL_BYTE_2_SET:
                }
                case AI_LOCAL_BYTE_2_ADD:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (255 - ai->val < ChrEntityp->alertness) //clamp to 255
                    {
                        ChrEntityp->alertness = 255; //max
                    }
                    else
                    {
                        ChrEntityp->alertness += ai->val;
                    }
                    Offset += 2;
                    break; //AI_LOCAL_BYTE_2_ADD:
                }
                case AI_LOCAL_BYTE_2_SUBTRACT:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    if (ai->val > ChrEntityp->alertness) //clamp to 0
                    {
                        ChrEntityp->alertness = 0;
                    }
                    else
                    {
                        ChrEntityp->alertness -= ai->val;
                    }
                    Offset += 2;
                    break; //AI_LOCAL_BYTE_2_SUBTRACT:
                }
                case AI_IF_LOCAL_BYTE_2_LESS_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] > ChrEntityp->alertness)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_LOCAL_BYTE_2_LESS_THAN:
                }
                case AI_IF_LOCAL_BYTE_2_LESS_THAN_RANDOM_SEED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ChrEntityp->alertness < ChrEntityp->random)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_LOCAL_BYTE_2_LESS_THAN_RANDOM_SEED:
                }
                case AI_GUARD_SET_HEARING_SCALE:
                {
                    AIRecord *ai             = AiListp + Offset;
                    f32       distance       = CharArrayTo16(ai->val,0)) / 1000.0f;
                    ChrEntityp->hearingscale = distance;
                    Offset += 3;
                    break; //AI_GUARD_SET_HEARING_SCALE:
                }
                case AI_GUARD_SET_VISION_RANGE:
                {
                    AIRecord *ai            = AiListp + Offset;
                    ChrEntityp->visionrange = (ai->val[0]);
                    Offset += 2;
                    break; //AI_GUARD_SET_VISION_RANGE:
                }
                case AI_GUARD_SET_GRENADE_PROBABILITY:
                {
                    AIRecord *ai            = AiListp + Offset;
                    ChrEntityp->grenadeprob = ai->val[0];
                    Offset += 2;
                    break; //AI_GUARD_SET_GRENADE_PROBABILITY:
                }
                case AI_GUARD_SET_CHR_NUM:
                {
                    AIRecord *ai       = AiListp + Offset;
                    ChrEntityp->chrnum = ai->val[0];
                    Offset += 2;
                    break; //AI_GUARD_SET_CHR_NUM:
                }
                case AI_GUARD_SET_HEALTH_TOTAL:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       amount = CharArrayTo16(ai->val,0)) * 0.1f;
                    chrSetMaxDamage(ChrEntityp, amount);
                    Offset += 3;
                    break; //AI_GUARD_SET_HEALTH_TOTAL:
                }
                case AI_GUARD_SET_ARMOUR:
                {
                    AIRecord *ai     = AiListp + Offset;
                    f32       amount = CharArrayTo16(ai->val,0)) * 0.1f; /*if (cheatIsActive(CHEAT_ENEMYSHIELDS)) { amount = amount < 8 ? 8 : amount; }*/
                    chrAddHealth(ChrEntityp, amount);
                    Offset += 3;
                    break; //AI_GUARD_SET_ARMOUR:
                }
                case AI_GUARD_SET_SPEED_RATING:
                {
                    struct
                    {
                        u8 cmd;
                        s8 val;
                    } *ai = AiListp + Offset;
#            ifdef DEBUG
                    /*
                    ".\\ported\\chrai.c", 2258, "Assertion failed: ai->val>=0"
                    ".\\ported\\chrai.c", 2259, "Assertion failed: ai->val<=100"
                    * Note: there are 10 lines between these 2 asserts meaning either no ifdef or no allman.
                    */
                    assert(ai->val >= 0);
                    assert(ai->val <= 100);
#            endif
                    ChrEntityp->speedrating = ai->val;
                    Offset += 2;
                    break; //AI_GUARD_SET_SPEED_RATING:
                }
                case AI_GUARD_SET_ARGH_RATING:
                {
                    struct
                    {
                        u8 cmd;
                        s8 val;
                    } *ai = AiListp + Offset;
#            ifdef DEBUG
                    /*
                    ".\\ported\\chrai.c", 2268, "Assertion failed: ai->val>=0"
                    ".\\ported\\chrai.c", 2269, "Assertion failed: ai->val<=100"
                    */
                    assert(ai->val >= 0);
                    assert(ai->val <= 100);
#            endif
                    ChrEntityp->arghrating = ai->val;
                    Offset += 2;
                    break; //AI_GUARD_SET_ARGH_RATING:
                }
                case AI_GUARD_SET_ACCURACY_RATING:
                {
                    struct
                    {
                        u8 cmd;
                        s8 val;
                    } *ai                      = AiListp + Offset;
                    ChrEntityp->accuracyrating = ai->val;
                    Offset += 2;
                    break; //AI_GUARD_SET_ACCURACY_RATING:
                }
                case AI_GUARD_BITFIELD_SET_ON:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrSetFlags(ChrEntityp, ai->val[0]);
                    Offset += 2;
                    break; //AI_GUARD_BITFIELD_SET_ON:
                }
                case AI_GUARD_BITFIELD_SET_OFF:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrUnsetFlags(ChrEntityp, ai->val[0]);
                    Offset += 2;
                    break; //AI_GUARD_BITFIELD_SET_OFF:
                }
                case AI_IF_GUARD_BITFIELD_IS_SET_ON:
                {
                    AIRecord *ai = AiListp + Offset;
                    /*bool result;
            result =  if (ai->val[4] == 0) { result = !result; }*/
                    if (chrHasFlag(ChrEntityp, ai->val[0]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_GUARD_BITFIELD_IS_SET_ON:
                }
                case AI_CHR_BITFIELD_SET_ON:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrSetFlagsById(ChrEntityp, ai->val[0], ai->val[1]);
                    Offset += 3;
                    break; //AI_CHR_BITFIELD_SET_ON:
                }
                case AI_CHR_BITFIELD_SET_OFF:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrUnsetFlagsById(ChrEntityp, ai->val[0], ai->val[1]);
                    Offset += 3;
                    break; //AI_CHR_BITFIELD_SET_OFF:
                }
                case AI_IF_CHR_BITFIELD_IS_SET_ON:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (chrHasFlagById(ChrEntityp, ai->val[0], ai->val[1]))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_CHR_BITFIELD_IS_SET_ON:
                }
                case AI_OBJECTIVE_BITFIELD_SET_ON:
                {
                    AIRecord *ai    = AiListp + Offset;
                    s32       flags = CharArrayTo32(ai->val,0);
                    chrSetStageFlags(ChrEntityp, flags);
                    Offset += 5;
                    break; //AI_OBJECTIVE_BITFIELD_SET_ON:
                }
                case AI_OBJECTIVE_BITFIELD_SET_OFF:
                {
                    AIRecord *ai    = AiListp + Offset;
                    s32       flags = CharArrayTo32(ai->val,0);
                    chrUnsetStageFlags(ChrEntityp, flags);
                    Offset += 5;
                    break; //AI_OBJECTIVE_BITFIELD_SET_OFF:
                }
                case AI_IF_OBJECTIVE_BITFIELD_IS_SET_ON:
                {
                    AIRecord *ai    = AiListp + Offset;
                    s32       flags = CharArrayTo32(ai->val,0);
                    if (chrHasStageFlag(ChrEntityp, flags)) /* PD && ai->val[4] == 1) || (!chrHasStageFlag(ChrEntityp, flags) && ai->val[4] == 0* */
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += 6;
                    }
                    break; //AI_IF_OBJECTIVE_BITFIELD_IS_SET_ON:
                }
                case AI_GUARD_FLAGS_SET_ON:
                {
                    AIRecord *ai    = AiListp + Offset;
                    CHRFLAG   flags = CharArrayTo32(ai->val,0);
                    ChrEntityp->chrflags |= flags;
                    Offset += 5;
                    break; //AI_GUARD_FLAGS_SET_ON:
                }
                case AI_GUARD_FLAGS_SET_OFF:
                {
                    AIRecord *ai    = AiListp + Offset;
                    CHRFLAG   flags = CharArrayTo32(ai->val,0);
                    ChrEntityp->chrflags &= ~flags;
                    Offset += 5;
                    break; //AI_GUARD_FLAGS_SET_OFF:
                }
                case AI_IF_GUARD_FLAGS_IS_SET_ON:
                {
                    AIRecord *ai    = AiListp + Offset;
                    CHRFLAG   flags = CharArrayTo32(ai->val,0);
                    if ((ChrEntityp->chrflags & flags) == flags)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[4]);
                    }
                    else
                    {
                        Offset += 6;
                    }
                    break; //AI_IF_GUARD_FLAGS_IS_SET_ON:
                }
                case AI_CHR_FLAGS_SET_ON:
                {
                    AIRecord * ai    = AiListp + Offset;
                    /*What an odd order for bytestream but its the only way that matches...*/
                    CHRFLAG    flags = CharArrayTo32(ai->val,1);
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr)
                    {
                        chr->chrflags |= flags;
                    }
                    Offset += 6;
                    break; //AI_CHR_FLAGS_SET_ON:
                }
                case AI_CHR_FLAGS_SET_OFF:
                {
                    AIRecord * ai    = AiListp + Offset;
                    CHRFLAG    flags = CharArrayTo32(ai->val,1);
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr)
                    {
                        chr->chrflags &= ~flags;
                    }
                    Offset += 6;
                    break; //AI_CHR_FLAGS_SET_OFF:
                }
                case AI_IF_CHR_FLAGS_IS_SET_ON:
                {
                    AIRecord * ai    = AiListp + Offset;
                    CHRFLAG    flags = CharArrayTo32(ai->val,1);
                    ChrRecord *chr   = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && (chr->chrflags & flags) == flags)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += 7;
                    }
                    break; //AI_IF_CHR_FLAGS_IS_SET_ON:
                }
                case AI_OBJECT_FLAGS_1_SET_ON:
                {
                    AIRecord *    ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        obj->flags |= flags;
                    }
                    Offset += 6;
                    break; //AI_OBJECT_FLAGS_1_SET_ON:
                }
                case AI_OBJECT_FLAGS_1_SET_OFF:
                {
                    AIRecord *    ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        obj->flags &= ~flags;
                    }
                    Offset += 6;
                    break; //AI_OBJECT_FLAGS_1_SET_OFF:
                }
                case AI_IF_OBJECT_FLAGS_1_IS_SET_ON:
                {
                    AIRecord *    ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && (obj->flags & flags) == flags)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += 7;
                    }
                    break; //AI_IF_OBJECT_FLAGS_1_IS_SET_ON:
                }
                case AI_OBJECT_FLAGS_2_SET_ON:
                {
                    AIRecord *    ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        obj->flags2 |= flags;
                    }
                    Offset += 6;
                    break; //AI_OBJECT_FLAGS_2_SET_ON:
                }
                case AI_OBJECT_FLAGS_2_SET_OFF:
                {
                    AIRecord *    ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        obj->flags2 &= ~flags;
                    }
                    Offset += 6;
                    break; //AI_OBJECT_FLAGS_2_SET_OFF:
                }
                case AI_IF_OBJECT_FLAGS_2_IS_SET_ON:
                {
                    AIRecord *    ai    = AiListp + Offset;
                    s32           flags = CharArrayTo32(ai->val,1);
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop && ((obj->flags2 & flags) == flags))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[5]);
                    }
                    else
                    {
                        Offset += 7;
                    }
                    break; //AI_IF_OBJECT_FLAGS_2_IS_SET_ON:
                }
                case AI_GUARD_SET_CHR_PRESET:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrSetChrPreset(ChrEntityp, ai->val[0]);
                    Offset += 2;
                    break; //AI_GUARD_SET_CHR_PRESET:
                }
                case AI_CHR_SET_CHR_PRESET:
                {
                    AIRecord *ai = AiListp + Offset;
                    chrSetChrPreset2(ChrEntityp, ai->val[0], ai->val[1]);
                    Offset += 3;
                    break; //AI_CHR_SET_CHR_PRESET:
                }
                case AI_GUARD_SET_PAD_PRESET:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,0);
                    if (ChrEntityp)
                    {
                        chrSetPadPreset(ChrEntityp, pad_id);
                    }
                    else if (AircraftEntityp)
                    {
                        AircraftEntityp->pad = pad_id;
                    }
                    Offset += 3;
                    break; //AI_GUARD_SET_PAD_PRESET:
                }
                case AI_CHR_SET_PAD_PRESET:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       pad_id = CharArrayTo16(ai->val,1);
                    chrSetPadPresetByChrnum(ChrEntityp, ai->val[0], pad_id);
                    Offset += 4;
                    break; //AI_CHR_SET_PAD_PRESET:
                }
                case AI_PRINT:
                {
#            if DEBUG
                    AIRecord *ai = AiListp + Offset;
                    //PD = osSyncPrintf("AI_PRINT(void) (%d)\n", chraiitemsize(AiListp, Offset));
                    osSyncPrintf("AI_PRINT: %s\n", ai->val);
#            endif
                    Offset += chraiitemsize(AiListp, Offset);
                    break; //AI_PRINT:
                }
                case AI_LOCAL_TIMER_RESET_START:
                {
                    chrRestartTimer(ChrEntityp);
                    Offset += 1;
                    break; //AI_LOCAL_TIMER_RESET_START:
                }
                case AI_LOCAL_TIMER_RESET:
                {
                    ChrEntityp->timer60 = 0;
                    Offset += 1;
                    break; //AI_LOCAL_TIMER_RESET:
                }
                case AI_LOCAL_TIMER_STOP:
                {
                    ChrEntityp->hidden &= ~CHRHIDDEN_TIMER_ACTIVE;
                    Offset += 1;
                    break; //AI_LOCAL_TIMER_STOP:
                }
                case AI_LOCAL_TIMER_START:
                {
                    ChrEntityp->hidden |= CHRHIDDEN_TIMER_ACTIVE;
                    Offset += 1;
                    break; //AI_LOCAL_TIMER_START:
                }
                case AI_IF_LOCAL_TIMER_HAS_STOPPED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (((ChrEntityp->hidden & CHRHIDDEN_TIMER_ACTIVE) == 0))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_LOCAL_TIMER_HAS_STOPPED:
                }
                case AI_IF_LOCAL_TIMER_LESS_THAN:
                {
                    AIRecord *ai   = AiListp + Offset;
                    f32       valf = ((unsigned)CharArrayTo24(ai->val,0)) / 60.0f;

                    if (chrGetTimer(ChrEntityp) < valf)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_IF_LOCAL_TIMER_LESS_THAN:
                }          //18 (6c-54) [1b8] 15c (+3)
                case AI_IF_LOCAL_TIMER_GREATER_THAN:
                {
                    AIRecord *ai   = AiListp + Offset;
                    f32       valf = ((unsigned)CharArrayTo24(ai->val,0)) / 60.0f;
                    if (chrGetTimer(ChrEntityp) > valf)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_IF_LOCAL_TIMER_GREATER_THAN:
                }
                case AI_HUD_COUNTDOWN_SHOW:
                {
                    countdownTimerSetVisible(1, TRUE);
                    Offset += 1;
                    break; //AI_HUD_COUNTDOWN_SHOW:
                }
                case AI_HUD_COUNTDOWN_HIDE:
                {
                    countdownTimerSetVisible(1, FALSE);
                    Offset += 1;
                    break; //AI_HUD_COUNTDOWN_HIDE:
                }
                case AI_HUD_COUNTDOWN_SET:
                {
                    AIRecord *ai      = AiListp + Offset;
                    f32       seconds = CharArrayTo16(ai->val,0);
                    countdownTimerSetValue(seconds * 60.0f);
                    Offset += 3;
                    break; //AI_HUD_COUNTDOWN_SET:
                }
                case AI_HUD_COUNTDOWN_STOP:
                {
                    countdownTimerSetRunning(FALSE);
                    Offset += 1;
                    break; //AI_HUD_COUNTDOWN_STOP:
                }
                case AI_HUD_COUNTDOWN_START:
                {
                    countdownTimerSetRunning(TRUE);
                    Offset += 1;
                    break; //AI_HUD_COUNTDOWN_START:
                }
                case AI_IF_HUD_COUNTDOWN_HAS_STOPPED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (!countdownTimerIsRunning())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_HUD_COUNTDOWN_HAS_STOPPED:
                }
                case AI_IF_HUD_COUNTDOWN_LESS_THAN:
                {
                    AIRecord *ai    = AiListp + Offset;
                    f32       value = CharArrayTo16(ai->val,0);
                    if (countdownTimerGetValue() < value * 60.0f)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_HUD_COUNTDOWN_LESS_THAN:
                }
                case AI_IF_HUD_COUNTDOWN_GREATER_THAN:
                {
                    AIRecord *ai    = AiListp + Offset;
                    f32       value = CharArrayTo16(ai->val,0);
                    if (countdownTimerGetValue() > value * 60.0f)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_HUD_COUNTDOWN_GREATER_THAN:
                }
                case AI_CHR_TRY_SPAWNING_AT_PAD:
                {
                    AIRecord *ai       = AiListp + Offset;
                    u16       pad      = CharArrayTo16(ai->val,2);
                    CHRFLAG   flags    = CharArrayTo32(ai->val,6);
                    u16       ailistid = CharArrayTo16(ai->val,4);
                    AIRecord *ailist   = ailistFindById(ailistid);
                    if (chrSpawnAtPad(ChrEntityp, ai->val[0], (s8)ai->val[1], pad, ailist, flags))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[10]);
                    }
                    else
                    {
                        Offset += 12;
                    }
                    break; //AI_CHR_TRY_SPAWNING_AT_PAD:
                }
                case AI_CHR_TRY_SPAWNING_NEXT_TO_UNSEEN_CHR:
                {
                    AIRecord *ai       = AiListp + Offset;
                    CHRFLAG   flags    = CharArrayTo32(ai->val,5);
                    u16       ailistid = CharArrayTo16(ai->val,3);
                    AIRecord *ailist   = ailistFindById(ailistid);
                    if (chrSpawnAtChr(ChrEntityp, ai->val[0], (s8)ai->val[1], ai->val[2], ailist, flags))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[9]);
                    }
                    else
                    {
                        Offset += 11;
                    }
                    break; //AI_CHR_TRY_SPAWNING_NEXT_TO_UNSEEN_CHR:
                }
                case AI_GUARD_TRY_SPAWNING_ITEM:
                {
                    AIRecord *  ai    = AiListp + Offset;
                    s32         flags = (ai->val[4] << 16) | (ai->val[5] << 8) | ai->val[6] | (ai->val[3] << 24);
                    s32         model = CharArrayTo16(ai->val,0); // propID
                    PropRecord *prop  = NULL;

                    if (ChrEntityp && ChrEntityp->prop && ChrEntityp->model)
                    {
                        /* more nice PD code that might be usefull in future
                if (cheatIsActive(CHEAT_MARQUIS))
                {
                    flags &= ~0x10000000;
                    flags |= 0x20000000;
                    prop = chrGiveWeapon(ChrEntityp, model, ai->val[2], flags);
                }
                else
                */
                        if (cheatIsActive(28)) // CHEAT_ENEMYROCKETS
                        {
                            switch (ai->val[2]) // ITEM_IDS
                            {
                                case ITEM_KNIFE:
                                case ITEM_THROWKNIFE:
                                case ITEM_WPPK:
                                case ITEM_WPPKSIL:
                                case ITEM_TT33:
                                case ITEM_SKORPION:
                                case ITEM_AK47:
                                case ITEM_UZI:
                                case ITEM_MP5K:
                                case ITEM_MP5KSIL:
                                case ITEM_SPECTRE:
                                case ITEM_M16:
                                case ITEM_FNP90:
                                case ITEM_SHOTGUN:
                                case ITEM_AUTOSHOT:
                                case ITEM_SNIPERRIFLE:
                                case ITEM_RUGER:
                                case ITEM_GOLDENGUN:
                                case ITEM_SILVERWPPK:
                                case ITEM_GOLDWPPK:
                                case ITEM_LASER:
                                case ITEM_WATCHLASER:
                                case ITEM_TIMEDMINE:
                                case ITEM_PROXIMITYMINE:
                                case ITEM_REMOTEMINE:
                                case ITEM_TRIGGER:
                                case ITEM_TASER:

                                    prop = chrGiveWeapon(ChrEntityp, PROP_CHRROCKETLAUNCH, ITEM_ROCKETLAUNCH, flags);
                                    //!Bug, No Break! relying on chrGiveWeapon checking weapon already given
                                default:
                                    prop = chrGiveWeapon(ChrEntityp, model, ai->val[2], flags);
                                    break;
                            }
                        }
                        else
                        {
                            prop = chrGiveWeapon(ChrEntityp, model, ai->val[2], flags);
                        }
                    }
                    if (prop)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[7]);
                    }
                    else
                    {
                        Offset += 9;
                    }
                    break; //AI_GUARD_TRY_SPAWNING_ITEM:
                }
                case AI_GUARD_TRY_SPAWNING_HAT:
                {
                    AIRecord *ai       = AiListp + Offset;
                    s32       flags    = (ai->val[3] << 16) | (ai->val[4] << 8) | ai->val[5] | (ai->val[2] << 24);
                    s32       modelnum = CharArrayTo16(ai->val,0);
                    bool      ok       = FALSE;
                    if (ChrEntityp && ChrEntityp->prop && ChrEntityp->model)
                    {
                        ok = chrTryEquipHat(ChrEntityp, modelnum, flags);
                    }
                    if (ok)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[6]);
                    }
                    else
                    {
                        Offset += 8;
                    }
                    break; //AI_GUARD_TRY_SPAWNING_HAT:
                }
                case AI_CHR_TRY_SPAWNING_CLONE:
                {
                    AIRecord *       ai       = AiListp + Offset;
                    //int zero                      ;//= 0; //on stack in xbla, but matches without
                    u16              ailistid = CharArrayTo16(ai->val,1);
                    u8 *             ailist   = ailistFindById((u16)ailistid);
                    ChrRecord *      chr      = chrFindById(ChrEntityp, ai->val[0]);
                    bool             pass     = FALSE; //564
                    int              chrnum;
                    PropRecord *     srcweaponLprop   = NULL;
                    PropRecord *     srcweaponRprop   = NULL;
                    PropRecord *     cloneweaponRprop = NULL;
                    PropRecord *     cloneweaponLprop = NULL;
                    PropRecord *     cloneprop        = NULL;
                    ChrRecord *      clone            = NULL; //536
                    WeaponObjRecord *srcweaponL       = NULL;
                    WeaponObjRecord *cloneweaponL     = NULL; //528
                    WeaponObjRecord *cloneweaponR     = NULL; //524
                    WeaponObjRecord *srcweaponR       = NULL;
                    PropRecord *     hatprop;
                    ObjectRecord *   hatobj;
                    //bool tryhat;
                    if (chr && (chr->chrflags & CHRFLAG_CLONE))
                    {
                        cloneprop = chrSpawnAtChr(ChrEntityp, chr->bodynum, -1, chr->chrnum, ailist, 0);
                        if (cloneprop)
                        {
                            clone  = cloneprop->chr;
                            chrnum = chr->chrnum + 10000;
                            if (!chrFindById(ChrEntityp, chrnum))
                            {
                                clone->chrnum = chrnum;
                            }
                            // chrSetChrnum(clone, getLowestUnusedChrId());
                            // chr->chrdup = clone->chrnum;
                            srcweaponRprop = chrGetEquippedWeaponProp(chr, GUNRIGHT);
                            if (srcweaponRprop)
                            {
                                srcweaponR       = srcweaponRprop->weapon;
                                cloneweaponRprop = chrGiveWeapon(clone, srcweaponR->obj, srcweaponR->weaponnum, 0);
                                if (cloneweaponRprop)
                                {
                                    cloneweaponR = cloneweaponRprop->weapon;
                                }
                            }

                            srcweaponLprop = chrGetEquippedWeaponProp(chr, GUNLEFT);
                            if (srcweaponLprop)
                            {
                                srcweaponL       = srcweaponLprop->weapon;
                                cloneweaponLprop = chrGiveWeapon(clone, srcweaponL->obj, srcweaponL->weaponnum, 0x10000000);
                                if (cloneweaponLprop)
                                {
                                    cloneweaponL = cloneweaponLprop->weapon;
                                }
                            }

                            if (srcweaponL && srcweaponR && cloneweaponL && cloneweaponR && srcweaponR == srcweaponL->dualweapon && srcweaponL == srcweaponR->dualweapon)
                            {
                                propweaponSetDual(cloneweaponL, cloneweaponR);
                            }
                            {
                                hatprop = chr->handle_positiondata_hat;
                                if (hatprop)
                                {
                                    hatobj = hatprop->obj;

                                    chrTryEquipHat(clone, hatobj->obj, 0);
                                }
                            }
                            //clone->morale     = chr->morale;
                            //clone->alertness  = chr->alertness;
                            //clone->padpreset1 = chr->padpreset1;
                            pass = TRUE;
                        }
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_CHR_TRY_SPAWNING_CLONE:
                }          //18 (64-4c) [238] 1d4 (+)
                case AI_TEXT_PRINT_BOTTOM:
                {
                    AIRecord *ai   = AiListp + Offset;
                    char *    text = langGet(CharArrayTo16(ai->val,0));
#            ifdef VERSION_JP
                    jp_hudmsgBottomShow(text);
#            else
                    hudmsgBottomShow(text);
#            endif
                    Offset += 3;
                    break; //AI_TEXT_PRINT_BOTTOM:
                }
                case AI_TEXT_PRINT_TOP:
                {
                    AIRecord *ai   = AiListp + Offset;
                    char *    text = langGet(CharArrayTo16(ai->val,0));

#            if DEBUG
                    osSyncPrintf("ptop =  %f \n", text);
#            endif

                    hudmsgTopShow(text);
                    Offset += 3;
                    break; //AI_TEXT_PRINT_TOP:
                }
                case AI_SFX_PLAY:
                {
                    AIRecord *ai       = AiListp + Offset;
                    s16       audio_id = CharArrayTo16(ai->val,0);
                    audioPlayFromProp((s8)ai->val[2], audio_id);
                    Offset += 4;
                    break; //AI_SFX_PLAY:
                }

                case AI_SFX_STOP_CHANNEL:
                {
                    AIRecord1s *ai = AiListp + Offset;
                    sub_GAME_7F0349BC(ai->val);
                    Offset += 2;
                    break; //AI_SFX_STOP_CHANNEL:
                }
                case AI_SFX_SET_CHANNEL_VOLUME:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai     = AiListp + Offset;
                    s16 vol   = CharArrayTo16(ai->val,0);
                    u16 sfxID = CharArrayTo16(ai->val,2);
                    if (ai->slotID >= 0 && ai->slotID < 8)
                    {
                        sfx_related[ai->slotID].sfxID  = sfxID;
                        sfx_related[ai->slotID].Volume = vol;
                        sfx_related[ai->slotID].pad    = NULL;
                        sfx_related[ai->slotID].Obj    = NULL;
                        if (sfxID == 0)
                        {
                            audioPlayFromProp2(ai->slotID);
                        }
                    }
                    Offset += 6;
                    break; //AI_SFX_SET_CHANNEL_VOLUME:
                }
                case AI_SFX_FADE_CHANNEL_VOLUME:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai     = AiListp + Offset;
                    f32 vol   = CharArrayTo16(ai->val,0);
                    u16 sfxID = CharArrayTo16(ai->val,2);
                    if (ai->slotID >= 0 && ai->slotID < 8)
                    {
                        sfx_related[ai->slotID].sfxID  = sfxID;
                        sfx_related[ai->slotID].Volume = sub_GAME_7F0539B8(vol);
                        sfx_related[ai->slotID].pad    = NULL;
                        sfx_related[ai->slotID].Obj    = NULL;
                        if (sfxID == 0)
                        {
                            audioPlayFromProp2(ai->slotID);
                        }
                    }
                    Offset += 6;
                    break; //AI_SFX_FADE_CHANNEL_VOLUME:
                }          //1c (60-44) [1c8] 168 (+3)
                case AI_SFX_EMIT_FROM_OBJECT:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai               = AiListp + Offset;
                    ObjectRecord *obj   = objFindByTagId(ai->val[0]);
                    u16           sfxID = CharArrayTo16(ai->val,1);
                    if (ai->slotID >= 0 && ai->slotID < 8 && obj)
                    {
                        sfx_related[ai->slotID].sfxID = sfxID;
                        sfx_related[ai->slotID].pad   = NULL;
                        sfx_related[ai->slotID].Obj   = obj;
                        if (sfxID == 0)
                        {
                            audioPlayFromProp2(ai->slotID);
                        }
                    }
                    Offset += 5;
                    break; //AI_SFX_EMIT_FROM_OBJECT:
                }          //18 (5c-44) [1b8] 15c (+3)
                case AI_SFX_EMIT_FROM_PAD:
                {
                    struct
                    {
                        u8 cmd;
                        s8 SlotID;
                        u8 val[];
                    } *ai             = AiListp + Offset;
                    u16        padnum = CharArrayTo16(ai->val,0);
                    PadRecord *pad;
                    u16        sfxID = CharArrayTo16(ai->val,2);
                    if (isNotBoundPad(padnum))
                    {
                        pad = &g_chraiCurrentSetup.pads[padnum];
                    }
                    else
                    {
                        pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padnum)];
                    }
                    if (ai->SlotID >= 0 && ai->SlotID < 8 && pad)
                    {
                        sfx_related[ai->SlotID].sfxID = sfxID;
                        sfx_related[ai->SlotID].pad   = pad;
                        sfx_related[ai->SlotID].Obj   = NULL;
                        if (sfxID == 0)
                        {
                            audioPlayFromProp2(ai->SlotID);
                        }
                    }
                    Offset += 6;
                    break; //AI_SFX_EMIT_FROM_PAD:
                }          //1c (58-3c) [1a8] 150 (+4)

                case AI_IF_SFX_CHANNEL_VOLUME_LESS_THAN:
                {
                    struct
                    {
                        u8 cmd;
                        s8 slotID;
                        u8 val[];
                    } *ai   = AiListp + Offset;
                    s16 vol = CharArrayTo16(ai->val,0);
                    if ((ai->slotID >= 0) && (ai->slotID < 8) && (sfx_related[ai->slotID].Volume2 < vol))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_IF_SFX_CHANNEL_VOLUME_LESS_THAN:
                }          //1c (58-3c) [198] 140 (+2)
                case AI_VEHICLE_START_PATH:
                {
                    AIRecord *  ai   = AiListp + Offset;
                    PathRecord *path = pathFindById(ai->val[0]);
                    if (VehichleEntityp)
                    {
                        VehichleEntityp->path     = path;
                        VehichleEntityp->nextstep = 0;
                    }
                    Offset += 2;
                    break; //AI_VEHICLE_START_PATH:
                }          //1c (58-3c) [190] 138 (+2)
                case AI_VEHICLE_SPEED:
                {
                    AIRecord *ai        = AiListp + Offset;
                    f32       speedtime = CharArrayTo16(ai->val,2);
                    f32       speedaim  = CharArrayTo16(ai->val,0)) * 100.0f / 15360.0f;
                    if (VehichleEntityp)
                    {
                        VehichleEntityp->speedaim    = speedaim;
                        VehichleEntityp->speedtime60 = speedtime;
                    }
                    Offset += 5;
                    break; //AI_VEHICLE_SPEED:
                }          //1c (58-3c) [188] 130 (+3)
                case AI_AIRCRAFT_ROTOR_SPEED:
                {
                    AIRecord *ai        = AiListp + Offset;
                    f32       speedtime = CharArrayTo16(ai->val,2);
                    f32       speedaim  = CharArrayTo16(ai->val,0)) * M_TAU / 3600.0f;
                    if (AircraftEntityp)
                    {
                        AircraftEntityp->rotaryspeedaim  = speedaim;
                        AircraftEntityp->rotaryspeedtime = speedtime;
                    }
                    Offset += 5;
                    break; //AI_AIRCRAFT_ROTOR_SPEED:
                }          //18 (54-3c) [178] 124 (+3)
                case AI_IF_CAMERA_IS_IN_INTRO:
                {
                    AIRecord *ai = AiListp + Offset;
                    if ((get_camera_mode() == 1) || (get_camera_mode() == 2))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_CAMERA_IS_IN_INTRO:
                }          //1c (58-3c) [170] 118 (+1)
                case AI_IF_CAMERA_IS_IN_BOND_SWIRL:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (get_camera_mode() == 3)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_CAMERA_IS_IN_BOND_SWIRL:
                }          //18 (54-3c) [168] 114 (+1)
                case AI_TV_CHANGE_SCREEN_BANK:
                {
                    AIRecord *    ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);
                    if (obj && obj->prop)
                    {
                        if (obj->type == PROPDEF_MONITOR)
                        {
                            MonitorObjRecord *sm = (MonitorObjRecord *)obj;
                            imageSlotSetImage(&sm->Monitor.image, ai->val[2]);
                        }
                        else if (obj->type == PROPDEF_MULTI_MONITOR)
                        {
                            u8 slot = ai->val[1];
                            if (slot < 4)
                            {
                                multimonitorobj *mm = (multimonitorobj *)obj; //need new size here 0x74 (116) + 0x80 (so monitor is obj + 74)
                                imageSlotSetImage(&mm->Monitor[slot].image, ai->val[2]);
                            }
                        }
                    }
                    Offset += 4;
                    break; //AI_TV_CHANGE_SCREEN_BANK:
                }          //1c (58-3c) [168] 110 (+5)
                case AI_IF_BOND_IN_TANK:
                { /* 
                    # if DEBUG && PD 
                    osSyncPrintf("ai_ifbondintank: tank code has been removed.\n"); 
                    # endif 
                    */
                    AIRecord *ai = AiListp + Offset;
                    if (isBondInTank() == TRUE)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_BOND_IN_TANK:
                }          //18 (54-3c) [150] fc (+1)
                case AI_EXIT_LEVEL:
                {
                    if (camera_8003642C)
                    {
                        if (camera_80036434 == FALSE)
                        {
                            camera_80036434 = TRUE;
                        }
                    }
                    else
                    {
                        bossReturnTitleStage();
                    }
                    Offset += 1;
                    break; //AI_EXIT_LEVEL:
                }          //1c (58-3c) [150] f8 (+0)
                case AI_CAMERA_RETURN_TO_BOND:
                {
                    set_camera_mode(CAMERAMODE_FP_NOINPUT);
                    Offset += 1;
                    break; //AI_CAMERA_RETURN_TO_BOND:
                }          //1c (58-3c) [150] f8 (+0)
                case AI_CAMERA_LOOK_AT_BOND_FROM_PAD:
                {
                    AIRecord *ai     = AiListp + Offset;
                    u16       padnum = CharArrayTo16(ai->val,0);
                    if (isNotBoundPad(padnum))
                    {
                        dword_CODE_bss_800799F8 = &g_chraiCurrentSetup.pads[padnum];
                    }
                    else
                    {
                        dword_CODE_bss_800799F8 = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padnum)];
                    }
                    set_camera_mode(CAMERAMODE_POSEND);
                    Offset += 3;
                    break; //AI_CAMERA_LOOK_AT_BOND_FROM_PAD:
                }          //1c (58-3c) [150] f8 (+2)
                case AI_CAMERA_SWITCH:
                {
                    AIRecord *       ai  = AiListp + Offset;
                    TagObjectRecord *tag = sub_GAME_7F057080(ai->val[0]);
                    if (tag)
                    {
                        int TagIndex = check_if_object_type_has_been_loaded(tag); //get index
                        if (TagIndex >= 0)
                        {
                            CutsceneRecord *cdef = sub_GAME_7F056A88(tag->OffsetToObj + TagIndex); //get obj

#            ifdef DEBUG
                            /*".\\ported\\chrai.c", 0xc2b, "Assertion failed: cdef->type==PROPDEF_CAMERAPOS")                             */
                            assert(cdef->type == PROPDEF_CAMERAPOS);
#            endif
                            dword_CODE_bss_800799F8 = NULL;
                            gBondViewCutscene = cdef;
                            dword_CODE_bss_80079A18 = CharArrayTo16(ai->val,1);
                            dword_CODE_bss_80079A1C = CharArrayTo16(ai->val,3);
                            set_camera_mode(CAMERAMODE_POSEND);
                        }
                    }
                    Offset += 6;
                    break; //AI_CAMERA_SWITCH:
                }          //1c (58-3c) [148] f0 (+4)
                case AI_IF_BOND_Y_POS_LESS_THAN:
                {
                    AIRecord *ai      = AiListp + Offset;
                    f32       bondpos = (s16)CharArrayTo16(ai->val,0);
                    if (get_curplayer_positiondata()->pos.y < bondpos)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_BOND_Y_POS_LESS_THAN:
                }          //1c (58-3c) [138] e0 (+2)
                case AI_HUD_HIDE_AND_LOCK_CONTROLS_AND_PAUSE_MISSION_TIME:
                {
                    AIRecord1 *ai = AiListp + Offset;
                    //u8 thing = ;
                    set_unset_bitflags(4, FALSE);
                    set_unset_ammo_on_screen_setting(2, FALSE);
                    if (!(ai->val & PLAYERFLAG_NOCONTROL))
                    {
                        bondviewSetIntroCameraFlags(PLAYERFLAG_NOCONTROL);
                    }
                    if (!(ai->val & PLAYERFLAG_LOCKCONTROLS))
                    {
                        sub_GAME_7F08A944(PLAYERFLAG_NOCONTROL);
                    }
                    if (!(ai->val & PLAYERFLAG_NOTIMER))
                    {
                        countdownTimerSetVisible(16, FALSE);
                    }
                    D_800364B0 = FALSE;
                    Offset += 2;
                    break; //AI_HUD_HIDE_AND_LOCK_CONTROLS_AND_PAUSE_MISSION_TIME:
                }          //1c (58-3c) [130] d8 (+1)
                case AI_HUD_SHOW_ALL_AND_UNLOCK_CONTROLS_AND_RESUME_MISSION_TIME:
                {
#            if DEBUG
                    osSyncPrintf("AI_BONDENABLECONTROL\n");
#            endif
                    set_unset_bitflags(4, TRUE);
                    set_unset_ammo_on_screen_setting(2, TRUE);
                    bondviewUnsetIntroCameraFlags(PLAYERFLAG_NOCONTROL);
                    sub_GAME_7F08A928(2);
                    countdownTimerSetVisible(16, TRUE);
                    D_800364B0 = TRUE;
                    Offset += 1;
                    break; //AI_HUD_SHOW_ALL_AND_UNLOCK_CONTROLS_AND_RESUME_MISSION_TIME:
                }          //18 (5c-44) [130] d4 (+0)
                case AI_CHR_TRY_TELEPORTING_TO_PAD:
                {
                    AIRecord * ai     = AiListp + Offset;
                    s32        padnum = CharArrayTo16(ai->val,1);
                    ChrRecord *chr    = chrFindById(ChrEntityp, ai->val[0]);
                    bool       pass   = FALSE;
                    PadRecord *pad;
                    f32        FacingDirection;
                    coord3d    pos;
                    StandTile *stan;

                    if (chr)
                    {
                        padnum = chrResolvePadId(ChrEntityp, padnum);
                        if (isNotBoundPad(padnum))
                        {
                            pad = &g_chraiCurrentSetup.pads[padnum];
                        }
                        else
                        {
                            pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padnum)];
                        }

                        FacingDirection = atan2f(pad->target.x, pad->target.z);
                        pos.x           = pad->pos.x;
                        pos.y           = pad->pos.y;
                        pos.z           = pad->pos.z;
                        //pos  = pad->pos; <-uses lw instead of lwc1
                        stan            = pad->stan;
                        sub_GAME_7F03D058(chr->prop, FALSE);

                        if (sub_GAME_7F033F48(&pos, &stan, FacingDirection, TRUE))
                        {
                            {
                                chr->prop->pos.x = pos.x;
                                chr->prop->pos.y = pos.y;
                                chr->prop->pos.z = pos.z;
                            }
                            //chr->prop->pos  = pos;
                            chr->prop->stan = stan;
                            chr->chrflags   = chr->chrflags | CHRFLAG_INIT;
                            setsubroty(chr->model, FacingDirection);
                            setsuboffset(chr->model, &pos);
                            sub_GAME_7F020D94(chr);
                            if (chr->prop == pPlayer->prop)
                            {
                                pPlayer->pos4.x = pos.x;
                                pPlayer->pos4.y = pos.y;
                                pPlayer->pos4.z = pos.z;

                                //pPlayer->pos = pos;
                                pPlayer->current_tile_ptr = stan;
                            }
                            pass = TRUE;
                        }
                        sub_GAME_7F03D058(chr->prop, TRUE);
                    }
                    if (pass)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_CHR_TRY_TELEPORTING_TO_PAD:
                }          //18 (54-3c) [128] d4 (+10)
                case AI_SCREEN_FADE_TO_BLACK:
                {
                    if (stop_time_flag != 2)
                    {
                        currentPlayerSetFadeColour(0, 0, 0, 0);
                        currentPlayerSetFadeFrac(60.0f, 1);
                    }
                    Offset += 1;
                    break; //AI_SCREEN_FADE_TO_BLACK:
                }          //18 (4c-34) [f8] ac (+0)
                case AI_SCREEN_FADE_FROM_BLACK:
                {
                    if (stop_time_flag != 2)
                    {
                        currentPlayerSetFadeColour(0, 0, 0, 1);
                        currentPlayerSetFadeFrac(60.0f, 0);
                    }
                    Offset += 1;
                    break; //AI_SCREEN_FADE_FROM_BLACK:
                }          //18 (4c-34) [f8] ac (+0)
                case AI_IF_SCREEN_FADE_COMPLETED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (pPlayer->colourfadetimemax60 < 0)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_SCREEN_FADE_COMPLETED:
                }          //18 (4c-34) [f8] ac (+1)
                case AI_CHR_HIDE_ALL:
                {
                    s32 num;
                    for (num = get_numguards() - 1; num >= 0; num--)
                    {
                        if (ptr_guard_data[num].model != NULL)
                        {
                            ptr_guard_data[num].chrflags |= CHRFLAG_HIDDEN;
                        }
                    }
                    Offset += 1;
                    break; //AI_CHR_HIDE_ALL:
                }          //1c (50-34) [f8] a8 (+1)
                case AI_CHR_SHOW_ALL:
                {
                    s32 num;
                    for (num = get_numguards() - 1; num >= 0; num--)
                    {
                        ptr_guard_data[num].chrflags &= ~CHRFLAG_HIDDEN;
                    }

                    Offset += 1;
                    break; //AI_CHR_SHOW_ALL:
                }          //18 (54-3c) [f8] a4 (+1)
                case AI_DOOR_OPEN_INSTANT:
                {
                    AIRecord *  ai   = AiListp + Offset;
                    DoorRecord *door = objFindByTagId(ai->val[0]);
                    if (door && door->prop)
                    {
                        //DoorRecord *door   = (DoorRecord *)obj;
                        door->speed        = 0;
                        door->openPosition = door->maxFrac;
                        door->openedTime   = g_GlobalTimer;
                        door->openstate        = DOORSTATE_STATIONARY;
                        sub_GAME_7F052B00(door);
                        sub_GAME_7F053598(door); // doorActivatePortal
                        sub_GAME_7F053B10(door);
                    }
                    Offset += 2;
                    break; //AI_DOOR_OPEN_INSTANT:
                }          //1c (50-34) [f0] a0 (+2)
                case AI_CHR_REMOVE_ITEM_IN_HAND:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr)
                    {
                        chrSetWeaponFlag4(chr, ai->val[1]);
                    }
                    Offset += 3;
                    break; //AI_CHR_REMOVE_ITEM_IN_HAND:
                }          //1c (48-2c) [e0] 98 (+2)
                case AI_IF_NUMBER_OF_ACTIVE_PLAYERS_LESS_THAN:
                {
                    struct
                    {
                        u8 cmd;
                        s8 val;
                        u8 label;
                    } *ai = AiListp + Offset;
                    if (getPlayerCount() < ai->val)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->label);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_NUMBER_OF_ACTIVE_PLAYERS_LESS_THAN:
                }          //1c (48-2c) [d8] 90 (+1)
                case AI_IF_BOND_ITEM_TOTAL_AMMO_LESS_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (currentPlayerGetAmmoCount((s8)ai->val[0]) < (s8)ai->val[1])
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[2]);
                    }
                    else
                    {
                        Offset += 4;
                    }
                    break; //AI_IF_BOND_ITEM_TOTAL_AMMO_LESS_THAN:
                }          //18 (4c-34) [d8] 8c (+1)
                case AI_BOND_EQUIP_ITEM:
                {
                    AIRecord *ai = AiListp + Offset;
                    currentPlayerEquipWeaponWrapper(GUNRIGHT, (s8)ai->val[0]);
                    currentPlayerEquipWeaponWrapper(GUNLEFT, 0);
                    Offset += 2;
                    break; //AI_BOND_EQUIP_ITEM:
                }          //1c (50-34) [d8] 88 (+1)
                case AI_BOND_EQUIP_ITEM_CINEMA:
                {
                    AIRecord *ai = AiListp + Offset;
                    currentPlayerUnEquipWeaponWrapper(GUNRIGHT, ai->val[0]);
                    currentPlayerUnEquipWeaponWrapper(GUNLEFT, 0);
                    Offset += 2;
                    break; //AI_BOND_EQUIP_ITEM_CINEMA:
                }          //18 (4c-34) [d0] 84 (+1)
                case AI_BOND_SET_LOCKED_VELOCITY:
                {
                    /*
                    g_Vars.currentplayer->bondforcespeed.x = (s8)ai->val[1];
                    g_Vars.currentplayer->bondforcespeed.y = 0;
                    g_Vars.currentplayer->bondforcespeed.z = (s8)ai->val[2];
                    */
                    AIRecord *ai            = AiListp + Offset;
                    flt_CODE_bss_80079990.x = (s8)ai->val[0];
                    flt_CODE_bss_80079990.y = 0;
                    flt_CODE_bss_80079990.z = (s8)ai->val[1];
                    Offset += 3;
                    break; //AI_BOND_SET_LOCKED_VELOCITY:
                }          //1c (50-34) [d0] 80 (+1)
                case AI_IF_OBJECT_IN_ROOM_WITH_PAD:
                {
                    AIRecord *    ai     = AiListp + Offset;
                    u16           padnum = CharArrayTo16(ai->val,1);
                    PadRecord *   pad;
                    ObjectRecord *obj = objFindByTagId(ai->val[0]);

                    if (isNotBoundPad(padnum))
                    {
                        pad = &g_chraiCurrentSetup.pads[padnum * 1]; //needs a mult by 1 to correct s0/v1
                    }
                    else
                    {
                        pad = (PadRecord *)&g_chraiCurrentSetup.boundpads[getBoundPadNum(padnum)];
                    }

                    if (pad->stan && obj && obj->prop && (pad->stan->RoomID == obj->prop->stan->RoomID))
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[3]);
                    }
                    else
                    {
                        Offset += 5;
                    }
                    break; //AI_IF_OBJECT_IN_ROOM_WITH_PAD:
                }          //18 (44-2c) [c0] 7c (+4)
                case AI_SWITCH_SKY:
                { // SWITCHENVIRONMENT
                    switch_to_solosky2(1.0);
                    Offset += 1;
                    break; //AI_SWITCH_SKY:
                }          //10 (3c-2c) [a8] 6c (+0)
                case AI_TRIGGER_FADE_AND_EXIT_LEVEL_ON_BUTTON_PRESS:
                {
                    if (stop_time_flag == FALSE)
                    {
                        stop_time_flag = TRUE;
                    }
                    Offset += 1;
                    break; //AI_TRIGGER_FADE_AND_EXIT_LEVEL_ON_BUTTON_PRESS:
                }          //10 (44-34) [b0] 6c (+0)
                case AI_IF_BOND_IS_DEAD:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (pPlayer->bonddead)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_BOND_IS_DEAD:
                }          //10 (44-34) [b0] 6c (+1)
                case AI_BOND_DISABLE_DAMAGE_AND_PICKUPS:
                {
                    g_PlayerInvincible = TRUE;
                    Offset += 1;
                    break; //AI_BOND_DISABLE_DAMAGE_AND_PICKUPS:
                }          //14 (48-34) [b0] 68 (+0)
                case AI_BOND_HIDE_WEAPONS:
                {
                    remove_item_in_hand(GUNRIGHT);
                    remove_item_in_hand(GUNLEFT);
                    Offset += 1;
                    break;                //AI_BOND_HIDE_WEAPONS:
                }                         //14 (40-2c) [a8] 68 (+0)
                case AI_CAMERA_ORBIT_PAD: //sp order from xbla
                {
                    AIRecord *ai = AiListp + Offset;
                    s32       padnum;
                    s32       a;
                    s32       b;
                    s32       c;
                    s32       height;
                    s32       speed;
                    b                       = CharArrayTo16(ai->val,0);
                    height                  = (s16)CharArrayTo16(ai->val,2);
                    a                       = (s16)CharArrayTo16(ai->val,4);
                    padnum                  = CharArrayTo16(ai->val,6);
                    c                       = (s16)CharArrayTo16(ai->val,8);
                    speed                   = ai->val[11] | ai->val[10] << 8;
                    dword_CODE_bss_800799F8 = NULL;
                    gBondViewCutscene = NULL;
                    flt_CODE_bss_80079A00   = (speed * M_TAU) / 65536.0f; //speed
                    flt_CODE_bss_80079A04   = (a * M_TAU) / 65536.0f;
                    flt_CODE_bss_80079A08   = b;
                    flt_CODE_bss_80079A0C   = height; //height
                    flt_CODE_bss_80079A10   = c;
                    dword_CODE_bss_80079A14 = padnum;   //padtoorbit
                    set_camera_mode(CAMERAMODE_POSEND); //, speed, padnum, height);
                    Offset += 13;
                    break; //AI_CAMERA_ORBIT_PAD:
                }          //14 (58-44) [c0] 68 (+7)
                case AI_CREDITS_ROLL:
                {
                    D_8003643C = TRUE;
                    Offset += 1;
                    break; //AI_CREDITS_ROLL:
                }          //10 (44-34) [90] 4c (+0)
                case AI_IF_CREDITS_HAS_COMPLETED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (D_8003643C == 2)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_CREDITS_HAS_COMPLETED:
                }          //10 (44-34) [90] 4c (+1)
                case AI_IF_OBJECTIVE_ALL_COMPLETED:
                {
                    AIRecord *ai = AiListp + Offset;
                    //bool a = objectiveIsAllComplete();
                    if (objectiveIsAllComplete())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_OBJECTIVE_ALL_COMPLETED:
                }          //14 (48-34) [90] 48 (+1)
                case AI_IF_FOLDER_ACTOR_IS_EQUAL:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (getSelectedFolderBond() == (s8)ai->val[0])
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_FOLDER_ACTOR_IS_EQUAL:
                }          //10 (44-34) [88] 44 (+1)
                case AI_IF_BOND_DAMAGE_AND_PICKUPS_DISABLED:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (g_PlayerInvincible)
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[0]);
                    }
                    else
                    {
                        Offset += 2;
                    }
                    break; //AI_IF_BOND_DAMAGE_AND_PICKUPS_DISABLED:
                }          //c (40-34) [80] 40 (+1)
                case AI_MUSIC_XTRACK_PLAY:
                {
                    AIRecord *ai = AiListp + Offset;
                    Offset += 4;
                    musicSetXReason((s8)ai->val[0], ai->val[1], ai->val[2]);
#            if DEBUG
                    osSyncPrintf("ai: enery tune on (%d, %d, %d)\n", ai->val[0], ai->val[1], ai->val[2]);
#            endif
                    break; //AI_MUSIC_XTRACK_PLAY:
                }          //10 (44-34) [80] 3c (+1)
                case AI_MUSIC_XTRACK_STOP:
                {
                    AIRecord *ai = AiListp + Offset;
                    Offset += 2;
                    musicUnsetXReason((s8)ai->val[0]);
#            if DEBUG
                    osSyncPrintf("ai: enery tune off (%d)\n", ai->val[0]);
#            endif
                    break; //AI_MUSIC_XTRACK_STOP:
                }          //c (40-34) [78] 38 (+1)
                case AI_TRIGGER_EXPLOSIONS_AROUND_BOND:
                {
                    SurroundWithExplosions(0);
                    Offset += 1;
                    break; //AI_TRIGGER_EXPLOSIONS_AROUND_BOND:
                }          //10 (44-34) [78] 34 (+0)
                case AI_IF_KILLED_CIVILIANS_GREATER_THAN:
                {
                    AIRecord *ai = AiListp + Offset;
                    if (ai->val[0] < get_civilian_casualties())
                    {
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_KILLED_CIVILIANS_GREATER_THAN:
                }          //10 (44-34) [78] 34 (+1)
                case AI_IF_CHR_WAS_SHOT_SINCE_LAST_CHECK:
                {
                    AIRecord * ai  = AiListp + Offset;
                    ChrRecord *chr = chrFindById(ChrEntityp, ai->val[0]);
                    if (chr && chr->chrflags & CHRFLAG_WAS_HIT)
                    {
                        chr->chrflags &= ~CHRFLAG_WAS_HIT;
                        Offset = chraiGoToLabel(AiListp, Offset, ai->val[1]);
                    }
                    else
                    {
                        Offset += 3;
                    }
                    break; //AI_IF_CHR_WAS_SHOT_SINCE_LAST_CHECK:
                }          //c (40-34) [70] 30 (+2)
                case AI_BOND_KILLED_IN_ACTION:
                {
                    g_isBondKIA = TRUE;
                    Offset += 1;
                    break; //AI_BOND_KILLED_IN_ACTION:
                }          //c (60-54) [88] 28 (+0)
                case AI_GUARD_RAISES_ARMS:
                {
                    chrTrySurprisedSurrender(ChrEntityp);
                    Offset += 1;
                    break; //AI_GUARD_RAISES_ARMS:
                }          //c (60-54) [88] 28 (+0)
                case AI_GAS_LEAK_AND_FADE_FOG:
                {
                    void *p[3] = ptr_80030A88_3words;
                    init_trigger_toxic_gas_effect(p); //do something with p
                    Offset += 1;
                    break; //AI_GAS_LEAK_AND_FADE_FOG:
                }          //c (60-54) [88] 28 (+3)
                case AI_OBJECT_ROCKET_LAUNCH:
                {
                    AIRecord1 *   ai  = AiListp + Offset;
                    ObjectRecord *obj = objFindByTagId(ai->val);

                    if (obj && obj->prop)
                    {
                        sub_GAME_7F03FDA8(obj->prop);

                        if (obj->runtime_bitflags & RUNTIMEBITFLAG_LAUNCHING)
                        {
                            obj->unk6C->id |= 0x601;
                            sub_GAME_7F03FE14(obj->prop);
                            matrix_4x4_set_identity(&obj->unk6C->m);
                            obj->unk6C->pos.x = 0;
                            obj->unk6C->pos.y = 0.016666666; //step height?
                            obj->unk6C->pos.z = 0;
                            obj->unk6C->vec.x = 0;
                            obj->unk6C->vec.y = 0.29166666f; //direction to move?
                            obj->unk6C->vec.z = 0;
                        }
                    }
                    Offset += 2;
                    break; //AI_OBJECT_ROCKET_LAUNCH:
                }          //============================================================================================================
#        endif
                default:
                    /* 
                    * No Command found, advance ailist by 1. 
                    * This is attempting to handle situations where the command 
                    * type is invalid by passing over them and continuing 
                    * execution.  
                    * chraiitemsize returns 1 which is pointless really 
                    * could have done it here without a jump 
                    * 
                    * Outcome:crash 
                    */
                    {
                        Offset += chraiitemsize(AiListp, Offset);
                    }
            } // switch
        }     // for
    }         // Has ailist
}             //ai()

#        ifdef DebugAIExecuteSUBS
//Matching stubs                                                                                29 / 175
//____



//needed stubs for above stubs to match
extern bool chrIsNotDeadOrShot(ChrRecord *self);                                 //match
extern WeaponObjRecord *create_new_item_instance_of_model(s32 a, s32 b);
extern void set_obj_instance_controller_scale(Model *m, f32 s);
extern void sub_GAME_7F025560(ChrRecord *self, s32 a, s32 b); 
extern throw_weapon_in_guard_hand(ChrRecord*self, PropRecord*obj, GUNHAND hand, bool a);
extern f32 atan2f(f32 y, f32 x);
extern bool sub_GAME_7F02A1E8(ChrRecord *self, GUNHAND side, float distance); //chrIsClear
extern bool sub_GAME_7F02A0EC(ChrRecord *self, GUNHAND side, float distance); //chrIsClearLow
extern void sub_GAME_7F024A84(ChrRecord *self, GUNHAND side);                 //chrHopToSide
extern void sub_GAME_7F024800(ChrRecord *self, GUNHAND side);                 //chrStepToSide
extern void sub_GAME_7F025C40(ChrRecord *self, GUNHAND side);                 //chrRollToSide
extern void sub_GAME_7F02A044(ChrRecord *self, GUNHAND side,vec3d *vec); //get vector to run on
extern bool sub_GAME_7F02982C(PropRecord *prop, coord3d *target, vec3d *vec);
extern void sub_GAME_7F024CF8(ChrRecord *self, coord3d *target); // run to coord
extern void sub_GAME_7F02587C(ChrRecord *self, SPEED speed); // run forward shooting
extern char off_CODE_bss_80079E30[76];
extern s32 get_cur_playernum();

extern PadRecord *sub_GAME_7F027CD4(coord3d *pos, void *stan);
extern StandTile *sub_GAME_7F0B2718(StandTile *srcTile, void *tilePred);
extern PadRecord *get_ptrpreset_in_table_matching_tile(StandTile *stan);
//extern int waypointFindRoute( PadRecord *a, PadRecord *b, coord3d*pos, int dist);
extern int sub_GAME_7F08FB90(PadRecord *a, PadRecord *b, int padid);
extern void set_or_unset_GUARDdata_flag(ChrRecord *self, bool unset);
extern int sub_GAME_7F0B0E24(struct StandTile **pTile, float p_x, float p_z, float dest_x, float dest_z, int objFlags, float unkHeight, float unkA, float unkB, float unkC);
f32 toxic_gas_sound_timer = 0;
extern void actor_fade_away(ChrRecord *self);
s32 setting_007_5;
extern bool plot_course_for_actor(ChrRecord *, coord3d *, StandTile *, SPEED);
extern bool sub_GAME_7F0B0BE4(StandTile *, float, float, float, float);
/*
((\{|\})\n)|(^.[^:]*$\n)|(^.*:.{11}\d?)|((?<=jal\t)([\d a b c d e f]{1,4} <.*\n))|([\d a b c d e f]{1,4} <.*)|(^$\n)

format for notepad++
(/\*.*\*\/\s*)|(\$(?=[^f]))
*/
#            define getVector(vec, a, b) \
                vec.x = b.x - a.x;       \
                vec.y = b.y - a.y;       \
                vec.z = b.z - a.z
#            define getDistanceSquared(vec)             (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)
#            define isVectorDistanceLessThan(dist, vec) (dist * dist) <= vec

    /*0x80075D28*/ u32 *dword_CODE_bss_80075D28;
MissionObjectiveRecord *objective_ptrs[10];
OBJECTIVESTATUS *dword_CODE_bss_80075D58[10]; //objective states
//---
//s32 dword_CODE_bss_80075D58; //objective states
//u32 dword_CODE_bss_80075D5C;
//char dword_CODE_bss_80075D60[0x20];
//----
//CODE.bss:80075D80
u32 *ptr_last_tag_entry_type16;
//CODE.bss:80075D84
u32 *ptr_last_briefing_setup_entry_type23;
//CODE.bss:80075D88
u32 *ptr_last_enter_room_subobject_entry_type20;
//CODE.bss:80075D8C
u32 *ptr_last_deposit_in_room_subobject_entry_type21;
//CODE.bss:80075D90
u32 *ptr_last_photo_obj_in_room_subobject_entry_type1E;

// data
s32 num_objective_ptrs[] = {0xFFFFFFFF, 0};

OBJECTIVESTATUS get_status_of_objective(s32 objectiveNum); //#MATCH

void something_with_stage_objectives()
{
    s32 i;

    if (bossGetStageNum() != LEVELID_TITLE)
    {
        num_objective_ptrs[0] = -1;
        //dword_CODE_bss_80075D58 = NULL;
        //dword_CODE_bss_80075D5C = NULL;
        // *dword_CODE_bss_80075D60 = *clear2;
        //dword_CODE_bss_80075D58[0] = OBJECTIVESTATUS_INCOMPLETE;
        for (i = 1; i <= 10; i++)
        {
            dword_CODE_bss_80075D58[i] = OBJECTIVESTATUS_INCOMPLETE;
        }
    }

    for (i = 1; i <= 10; i++)
    {
        objective_ptrs[i] = NULL;
    }
    ptr_last_tag_entry_type16                         = NULL;
    ptr_last_briefing_setup_entry_type23              = NULL;
    ptr_last_enter_room_subobject_entry_type20        = NULL;
    ptr_last_deposit_in_room_subobject_entry_type21   = NULL;
    ptr_last_photo_obj_in_room_subobject_entry_type1E = NULL;
}
#        endif



typedef struct bitdesc //0xc long
{
    u16 start;  //   <= bit offset to the data within one frame?
    u8  num;    //   <= number of bits per value?
    s16 offset; //   <= an offset value for all stored data values - so need to add this to values obtained from the following transroty data
} bitdesc;

typedef struct AnimationKeyframe  //0xcc long
{
    s16 keyframeTranslationX;
    s16 keyframeTranslationY;
    s16 keyframeTranslationZ;
    f32 keyframeYRotation;
    vec3d partRotations[0x10];
} AnimationKeyframe;

typedef struct AnimationHeader //0x18 long
{
    AnimationKeyframe *motion;        //   <= joint rotation data stored on rom
    u16                numframes;     //   <= number of frames of animation data
    u8                 rotbits;       //   <= number of bits per x, y, z rotation?
    u8                 flags;         //   <= for looping or forcing a gun to drop on death
    bitdesc           *bitsrel;       //   <= points to bitsdesc array at start
    u16                bitssizerel;   //   <= number of bits in one frame of transroty data
    u16                bitssize;      //   <= number of bits in one frame of joint rotation data
    u8 *               bitsmotionrel; //   <= points to transroty data (following the bitsdesc array)
} AnimationHeader;
#        define PTR_ANIM_ENTRY_idle 0x0000
// this is a sample of Idle Pose (_animation_dataSegmentRomStart)
u32 ANIM_DATA_idle[] =
    {
        {PTR_ANIM_ENTRY_idle, 0x00a3, 0x0c, 0x00, 0x00000000, 0x0000, 0x0220, 0x00000018},
        {0x0000, 0x06, 0x0000}, //x
        (0x0100, 0x06, 0x0700}, //y
        (0x0412, 0x00, 0x0d06}. //z
        (0x00ff, 0xff, 0x0013}, //rot
    {0x0000, 0x00, 0x0019},
    {0x6864, 0xae, 0xf0b5},
    {0x9e14, 0xb0, 0x1516},
    {0x763a, 0xa0, 0x0552},
    {0x202a, 0x42, 0x0148},
    {0x422a, 0x17, 0xf501},
    {0x7e98, 0x1f, 0x520d},
    {0xea85, 0x7e, 0x4e58},
    {0x6748, 0x20, 0xb0a5},
    {0x8c2c, 0x60, 0xe310},
    {0x14d2, 0x02, 0xa038},
    {0x7446, 0x10, 0x70a2},
    {0x1134, 0x13, 0x84fb},
    {0x401f, 0x42, 0x0bd0},
    {0xb0f8, 0x8e, 0x7643},
    {0xc8b4, 0x40, 0x1683},
    {0xfae0, 0x7e, 0x6523},
    {0xcd63, 0xf9, 0xb84e},
    {0xfb8b, 0xdf, 0xb17d},
    {0xf81f, 0x7f, 0x84f7},
    {0xf89f, 0x7c, 0x07ff},
    {0x807f, 0xec, 0x1ffd},
    {0x03ff, 0xb0, 0x40f6},
    {0x081e, 0x82, 0x03d8},
    {0x3ffa, 0x07, 0xff80},
    {0xfff8, 0x1f, 0xff04},
    {0x07e0, 0x81, 0xf80f},
    {0xff01, 0xff, 0xf03f},
    {0xfd07, 0xff, 0xa0fd},
    {0xf41f, 0xfe, 0x83ff},
    {0xc07f, 0xf8, 0x0fff},
    {0x01ff, 0xe0, 0x5ffd},
    {0x07ef, 0xc0, 0xfffc},
    {0x1fff, 0x83, 0xfff0},
    {0xbffe, 0x0f, 0xff43},
    {0xfbe0, 0xff, 0xf81b},
    {0xff00, 0xff, 0xe010},
    {0x3c03, 0xff, 0x707f},
    {0xf00f, 0xdd, 0x81fb},
    {0xb01e, 0x77, 0xf79f},
    {0x5ee8, 0x03, 0xae7d},
    {0x79f7, 0xc0, 0x3ef7},
    {0xff5d, 0xb7, 0xe3af},
    {0x55ed, 0xb3, 0x3cf7},
    {0xe186, 0xdb, 0xae57},
    {0x9d99, 0xf3, 0xa515},
    {0x74a4, 0xda, 0xcd99},
    {0xe0cb, 0x3c, 0xb8fd},
    {0xc72f, 0x82, 0x03f1},
    {0x707e, 0x40, 0x0fcb},
    {0x41f9, 0x60, 0x3f2c},
    0x04
}
;

//blob for animation data, variable length keyframes (_animation_tableSegmentRomStart) bitArry cannot be made into structs
u32 ANIM_ENTRY_idle[] =
    {
        {0xfa0f7f00,
         0x8034029f,
         0xfb06805c,
         0x03607a01,
         0xfc99a817,
         0x57c8d000},

        {
            0xd5d00000,
            0x0239000a,
            0x86f68fb5,
            0xf57fcb12,
            0x6fe203fc,
            0x040e6fe2,
            0x3bd00003,
            0xe000000f
        },
        0xb8000f7f,
        0xfe8ff4fb,
        0xd01f0390,
        0xfa0f7f00,
        0x8033029f,
        0xfb06805c,
        0x03507a01,
        0xfc99a827,
        0x56c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00003,
        0xf000000f,
        0xbb000f7f,
        0xfe8ff4fc,
        0x101d03b0,
        0xfa0f7f00,
        0x8033029f,
        0xfb06805c,
        0x03507a01,
        0xfc99a827,
        0x56c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00003,
        0xe000000f,
        0xba000f80,
        0xfe8ff4fb,
        0xe01e03a0,
        0xfa0f7f00,
        0x8033029f,
        0xfb06805a,
        0x03407a01,
        0xfc99a827,
        0x56c8d000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00003,
        0xd000000f,
        0xb9000f80,
        0xfe8ff4fb,
        0xb01f0380,
        0xf9ff7f00,
        0x7033029f,
        0xfb069059,
        0x03407a01,
        0xfc99a817,
        0x57c8d000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00003,
        0xf000000f,
        0xba000f7f,
        0xfe8ff4fb,
        0xe01e0390,
        0xf9df7f00,
        0x703302af,
        0xfb06a059,
        0x03407a01,
        0xfc99a837,
        0x56c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xb9000f7f,
        0xfe8ff4fc,
        0x101d03b0,
        0xf9cf7f00,
        0x7032029f,
        0xfb06a059,
        0x03407a01,
        0xfc99a837,
        0x55c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xb9000f7f,
        0xfe8ff4fc,
        0x201d03c0,
        0xf99f7e00,
        0x7033029f,
        0xfb06a05a,
        0x03407a01,
        0xfc99a847,
        0x55c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x3000000f,
        0xb9000f7f,
        0xfe8ff4fc,
        0x501c03d0,
        0xf96f7e00,
        0x7034029f,
        0xfb06b05a,
        0x03407a01,
        0xfc99a847,
        0x55c8d000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xbb000f7e,
        0xfe8ff4fc,
        0xa01a0400,
        0xf97f7e00,
        0x7034029f,
        0xfb06b05a,
        0x03407a01,
        0xfc99a857,
        0x55c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xbb000f7e,
        0xfe8ff4fc,
        0xa01a0410,
        0xf98f7e00,
        0x7034028f,
        0xfb06b05a,
        0x03507a01,
        0xfc99a877,
        0x54c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x6000000f,
        0xbb000f7e,
        0xfe8ff4fc,
        0x801b0400,
        0xf99f7e00,
        0x7034028f,
        0xfb06b05b,
        0x03607a01,
        0xfc99a877,
        0x55c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x7000000f,
        0xbb000f7e,
        0xfe8ff4fc,
        0x901a0400,
        0xf9af7e00,
        0x7034027f,
        0xfb06c05b,
        0x03607a01,
        0xfc99a887,
        0x55c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x7000000f,
        0xbc000f7e,
        0xfe8ff4fc,
        0xa01a0400,
        0xf9bf7e00,
        0x7034026f,
        0xfb06c05b,
        0x03607a01,
        0xfc99a887,
        0x56c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x6000000f,
        0xbd000f7e,
        0xfe8ff4fc,
        0x601b03e0,
        0xf9af7e00,
        0x7034026f,
        0xfb06c05b,
        0x03607a01,
        0xfc99a867,
        0x56c8c000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x7000000f,
        0xbf000f7e,
        0xfe8ff4fc,
        0x501b03d0,
        0xf9af7e00,
        0x7035027f,
        0xfb06b05b,
        0x03607a01,
        0xfc99a857,
        0x57c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xc0000f7e,
        0xfe8ff4fc,
        0x701a03e0,
        0xf9cf7e00,
        0x7035027f,
        0xfb06c05b,
        0x03707a01,
        0xfc99a847,
        0x58c8c000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xc1000f7e,
        0xfe8ff4fc,
        0x801a03e0,
        0xf9cf7e00,
        0x7035027f,
        0xfb06c05b,
        0x03707a01,
        0xfc99a847,
        0x58c8c000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x8000000f,
        0xc1000f7e,
        0xfe8ff4fc,
        0x801a03e0,
        0xf9cf7e00,
        0x7035027f,
        0xfb06c05c,
        0x03707a01,
        0xfc99a857,
        0x57c8b000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x6000000f,
        0xc0000f7e,
        0xfe8ff4fc,
        0x601b03d0,
        0xf9cf7e00,
        0x7034026f,
        0xfb06c05c,
        0x03807a01,
        0xfc99a877,
        0x55c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbf000f7f,
        0xfe8ff4fc,
        0x301c03c0,
        0xf9bf7e00,
        0x7034027f,
        0xfb06b05c,
        0x03807a01,
        0xfc99a867,
        0x55c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xbf000f7f,
        0xfe8ff4fc,
        0x401b03d0,
        0xf9bf7e00,
        0x7035027f,
        0xfb06b05c,
        0x03807a01,
        0xfc99a857,
        0x55c8d000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe2,
        0x3bd00004,
        0x7000000f,
        0xc0000f7e,
        0xfe8ff4fc,
        0x401b03d0,
        0xf9ef7e00,
        0x7034028f,
        0xfb06a05b,
        0x03907a01,
        0xfc99a847,
        0x55c8c000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xc0000f7f,
        0xfe8ff4fc,
        0x001d03a0,
        0xfa1f7e00,
        0x7033026f,
        0xfa06b05c,
        0x03a07a01,
        0xfc99a887,
        0x53c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xc0000f7f,
        0xfe8ff4fb,
        0xd01e0380,
        0xfa1f7e00,
        0x8033026f,
        0xfa06c05d,
        0x03c07a01,
        0xfc99a8b7,
        0x51c8a000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xc1000f7f,
        0xfe8ff4fb,
        0xf01e0390,
        0xfa2f7f00,
        0x8033025f,
        0xfa06c05d,
        0x03d07a01,
        0xfc99a8d7,
        0x50c89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xc0000f7f,
        0xfe8ff4fb,
        0xd01e0390,
        0xfa2f7f00,
        0x8033025f,
        0xfa06d05d,
        0x03c07a01,
        0xfc99a8e7,
        0x50c89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xb01f0370,
        0xfa3f7e00,
        0x8034026f,
        0xfa06d05d,
        0x03d07a01,
        0xfc99a8d7,
        0x50c8a000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xe01e0390,
        0xfa4f7e00,
        0x8035027f,
        0xfa06d05d,
        0x03d07a01,
        0xfc99a8e7,
        0x50c8a000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x5000000f,
        0xbe000f7f,
        0xfe8ff4fc,
        0x101d03b0,
        0xfa8f7e00,
        0x8036026f,
        0xfa06e05d,
        0x03c07a01,
        0xfc99a907,
        0x4fc89000,
        0xd5d00000,
        0x023c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xf01d03a0,
        0xfa8f7e00,
        0x8036025f,
        0xfa06f05d,
        0x03c07a01,
        0xfc99a907,
        0x4fc89000,
        0xd5d00000,
        0x023c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xf01c03a0,
        0xfa7f7e00,
        0x8037025f,
        0xfa06f05d,
        0x03d07a01,
        0xfc99a907,
        0x50c89000,
        0xd5d00000,
        0x023d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x4000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xf01c03a0,
        0xfa8f7f00,
        0x8036025f,
        0xfa06f05d,
        0x03d07a01,
        0xfc99a8f7,
        0x50c89000,
        0xd5d00000,
        0x023d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xba000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa7f7f00,
        0x8037025f,
        0xfa06f05e,
        0x03d07a01,
        0xfc99a8e7,
        0x50c8a000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xba000f7f,
        0xfe8ff4fb,
        0xc01d0390,
        0xfa6f7f00,
        0x8038025f,
        0xfb06f05f,
        0x03c07a01,
        0xfc99a8d7,
        0x4fc8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xbb000f7f,
        0xfe8ff4fb,
        0xe01d03a0,
        0xfa6f7f00,
        0x8038025f,
        0xfb06f05f,
        0x03c07a01,
        0xfc99a8d7,
        0x4fc8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xbb000f7f,
        0xfe8ff4fb,
        0xe01d03a0,
        0xfa6f7f00,
        0x8038027f,
        0xfb06e05d,
        0x03c07a01,
        0xfc99a897,
        0x51c8c000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbb000f80,
        0xfe8ff3fb,
        0xc01d0390,
        0xfa6f7f00,
        0x8038028f,
        0xfb06e05c,
        0x03c07a01,
        0xfc99a877,
        0x52c8c000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbb000f80,
        0xfe8ff3fb,
        0xc01d0380,
        0xfa6f7f00,
        0x8038027f,
        0xfb06e05d,
        0x03d07a01,
        0xfc99a887,
        0x51c8b000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbb000f80,
        0xfe8ff3fb,
        0xc01d0380,
        0xfa7f7f00,
        0x8037026f,
        0xfb06e060,
        0x03f07a01,
        0xfc99a8b7,
        0x4fc8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbb000f80,
        0xfe8ff3fb,
        0xb01e0380,
        0xfa7f7f00,
        0x8037026f,
        0xfb06e061,
        0x04107a01,
        0xfc99a8b7,
        0x4ec8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbc000f80,
        0xfe8ff3fb,
        0xb01e0380,
        0xfa7f7f00,
        0x8037026f,
        0xfb06e062,
        0x04107a01,
        0xfc99a8c7,
        0x4ec8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbc000f80,
        0xfe8ff3fb,
        0xb01e0380,
        0xfa6f7f00,
        0x8036026f,
        0xfb06e062,
        0x04107a01,
        0xfc99a8d7,
        0x4dc8a000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xbc000f80,
        0xfe8ff3fb,
        0xb01e0380,
        0xfa6f7f00,
        0x8036026f,
        0xfb06e062,
        0x04107a01,
        0xfc99a8e7,
        0x4dc8a000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbc000f80,
        0xfe8ff3fb,
        0xc01e0380,
        0xfa4f7f00,
        0x8037027f,
        0xfb06e062,
        0x04207a01,
        0xfc99a8e7,
        0x4dc8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa4f7f00,
        0x8037027f,
        0xfb06e063,
        0x04307a01,
        0xfc99a8f7,
        0x4dc8a000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xe01d03a0,
        0xfa5f7f00,
        0x8037026f,
        0xfa06e063,
        0x04407a01,
        0xfc99a907,
        0x4dc8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa5f7f00,
        0x8037026f,
        0xfa06f064,
        0x04507a01,
        0xfc99a907,
        0x4dc8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xbc000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa4f7f00,
        0x8038026f,
        0xfb071065,
        0x04607a01,
        0xfc99a917,
        0x4dc8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xe01d03a0,
        0xfa5f7f00,
        0x8038026f,
        0xfa071065,
        0x04707a01,
        0xfc99a927,
        0x4dc89000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa5f7f00,
        0x8038026f,
        0xfa071065,
        0x04707a01,
        0xfc99a917,
        0x4ec8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbd000f7f,
        0xfe8ff4fb,
        0xb01d0380,
        0xfa5f7f00,
        0x8038026f,
        0xfb072065,
        0x04707a01,
        0xfc99a907,
        0x4ec8a000,
        0xd5d00000,
        0x023a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xb01d0380,
        0xfa5f7f00,
        0x8038027f,
        0xfb072066,
        0x04807a01,
        0xfc99a8f7,
        0x4fc89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x2000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xd01d0390,
        0xfa5f7f00,
        0x8037027f,
        0xfa072066,
        0x04807a01,
        0xfc99a8f7,
        0x4fc89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0xd01c0390,
        0xfa5f7f00,
        0x8037027f,
        0xfa072066,
        0x04807a01,
        0xfc99a8f7,
        0x4fc89000,
        0xd5d00000,
        0x023b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xbf000f7f,
        0xfe8ff4fb,
        0xd01c0390,
        0xfa4f7f00,
        0x8038027f,
        0xfb071066,
        0x04607a01,
        0xfc99a8c7,
        0x4fc8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xbf000f80,
        0xfe8ff4fb,
        0xb01d0390,
        0xfa4f7f00,
        0x8038027f,
        0xfb071066,
        0x04707a01,
        0xfc99a8c7,
        0x4fc8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0xb01d0380,
        0xfa5f7f00,
        0x8037027f,
        0xfb071066,
        0x04607a01,
        0xfc99a8c7,
        0x4fc8a000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xc1000f80,
        0xfe7ff3fb,
        0x901e0370,
        0xfa7f7f00,
        0x8036028f,
        0xfb071065,
        0x04607a01,
        0xfc99a8b7,
        0x50c8b000,
        0xd5d00000,
        0x0239000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xc1000f80,
        0xfe7ff3fb,
        0x50200340,
        0xfa8f7f00,
        0x8035029f,
        0xfb070063,
        0x04507a01,
        0xfc99a887,
        0x52c8c000,
        0xd5d00000,
        0x0238000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe103fc,
        0x040e6fe2,
        0x3be00003,
        0xf000000f,
        0xc0000f80,
        0xfe7ff3fb,
        0x10220310,
        0xfa7f7f00,
        0x803602af,
        0xfb070063,
        0x04407a01,
        0xfc99a897,
        0x53c8c000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe103fc,
        0x040e6fe2,
        0x3bd00003,
        0xf000000f,
        0xc0000f80,
        0xfe7ff3fb,
        0x20210320,
        0xfa7f7f00,
        0x803602af,
        0xfb071063,
        0x04407a01,
        0xfc99a8d7,
        0x52c8c000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xc1000f80,
        0xfe7ff3fb,
        0x60200350,
        0xfa6f7f00,
        0x803602bf,
        0xfb071063,
        0x04407a01,
        0xfc99a907,
        0x51c8d000,
        0xd5d00000,
        0x0234000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x0000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x701f0360,
        0xfa5f7f00,
        0x803702cf,
        0xfb072063,
        0x04407a01,
        0xfc99a927,
        0x51c8d000,
        0xd5d00000,
        0x0233000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe2,
        0x3bd00004,
        0x1000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0xa01d0380,
        0xfa6f7f00,
        0x803702cf,
        0xfb072063,
        0x04407a01,
        0xfc99a937,
        0x52c8c000,
        0xd5d00000,
        0x0234000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc0000f7f,
        0xfe8ff4fb,
        0xc01c03a0,
        0xfa8f7f00,
        0x803702cf,
        0xfb073063,
        0x04507a01,
        0xfc99a957,
        0x53c8c000,
        0xd5d00000,
        0x0235000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0xa01c0390,
        0xfa8f7f00,
        0x803602bf,
        0xfb073064,
        0x04507a01,
        0xfc99a947,
        0x55c8c000,
        0xd5d00000,
        0x0235000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x701d0370,
        0xfa7f7f00,
        0x803702bf,
        0xfb074064,
        0x04507a01,
        0xfc99a957,
        0x56c8c000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xbf000f7f,
        0xfe8ff4fb,
        0xa01b0390,
        0xfa8f7f00,
        0x803602af,
        0xfb075065,
        0x04607a01,
        0xfc99a967,
        0x56c8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xbe000f7f,
        0xfe8ff4fb,
        0x901b0390,
        0xfaaf8000,
        0x8034027f,
        0xfb075064,
        0x04607a01,
        0xfc99a957,
        0x58c8c000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xe000000f,
        0xbd000f80,
        0xfe8ff3fb,
        0x001e0330,
        0xfa9f8000,
        0x8033025f,
        0xfb074064,
        0x04607a01,
        0xfc99a947,
        0x59c8d000,
        0xd5d00000,
        0x0235000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe103fc,
        0x040e6fe3,
        0x3be00003,
        0xd000000f,
        0xbf000f81,
        0xfe8ff3fa,
        0xe01f0310,
        0xfa7f8000,
        0x8034026f,
        0xfb074064,
        0x04707a01,
        0xfc99a957,
        0x59c8c000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xe000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x201d0350,
        0xfa6f8000,
        0x8034026f,
        0xfb074064,
        0x04807a01,
        0xfc99a977,
        0x58c8b000,
        0xd5d00000,
        0x0237000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xd000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x401b0360,
        0xfa5f8000,
        0x8034026f,
        0xfb074064,
        0x04907a01,
        0xfc99a987,
        0x58c8b000,
        0xd5d00000,
        0x0236000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xd000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x401b0360,
        0xfa3f7f00,
        0x8035026f,
        0xfc073065,
        0x04807a01,
        0xfc99a997,
        0x57c8c000,
        0xd5d00000,
        0x0234000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x70190380,
        0xfa4f7f00,
        0x8035026f,
        0xfc073065,
        0x04807a01,
        0xfc99a9b7,
        0x56c8c000,
        0xd5d00000,
        0x0234000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x70190380,
        0xfa6f8000,
        0x8034025f,
        0xfb073065,
        0x04707a01,
        0xfc99a9d7,
        0x55c8c000,
        0xd5d00000,
        0x0233000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xe000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x401a0350,
        0xfa5f8000,
        0x8034025f,
        0xfc074064,
        0x04707a01,
        0xfc99a9d7,
        0x55c8c000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xe000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x401a0360,
        0xfa5f8000,
        0x8034025f,
        0xfc074064,
        0x04707a01,
        0xfc99a9e7,
        0x55c8c000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00003,
        0xf000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x501a0360,
        0xfa4f8000,
        0x8034025f,
        0xfc078063,
        0x04707a01,
        0xfc99aa17,
        0x54c8a000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x60190370,
        0xfa4f8000,
        0x8034024f,
        0xfc078062,
        0x04707a01,
        0xfc99aa37,
        0x54c8a000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x60190370,
        0xfa5f8000,
        0x8035024f,
        0xfc079061,
        0x04707a01,
        0xfc99aa37,
        0x54c8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x50190370,
        0xfa5f8000,
        0x8036025f,
        0xfc07b061,
        0x04707a01,
        0xfc99aa47,
        0x54c8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x80180380,
        0xfa7f8000,
        0x8037025f,
        0xfc07c060,
        0x04707a01,
        0xfc99aa57,
        0x54c89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x80170380,
        0xfa8f8000,
        0x8037026f,
        0xfb07c05e,
        0x04607a01,
        0xfc99aa47,
        0x54c89000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xe000000f,
        0xbd000f80,
        0xfe8ff3fb,
        0x50180360,
        0xfa7f8000,
        0x8038026f,
        0xfc07b05e,
        0x04707a01,
        0xfc99aa27,
        0x55c8a000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x60180370,
        0xfa4f8000,
        0x803a026f,
        0xfc07a05d,
        0x04707a01,
        0xfc99a9f7,
        0x56c8a000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x90160390,
        0xfa5f8000,
        0x803a026f,
        0xfc07b05d,
        0x04807a01,
        0xfc99aa07,
        0x55c8a000,
        0xd5d00000,
        0x0233000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x80160390,
        0xfa5f8000,
        0x803a026f,
        0xfc07a05d,
        0x04807a01,
        0xfc99aa17,
        0x52c89000,
        0xd5d00000,
        0x0233000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x60170380,
        0xfa4f8000,
        0x803b027f,
        0xfc07905d,
        0x04807a01,
        0xfc99aa17,
        0x50c8a000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x60170370,
        0xfa3f8000,
        0x803c028f,
        0xfc07805b,
        0x04807a01,
        0xfc99a9e7,
        0x51c8c000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x70160380,
        0xfa4f8000,
        0x803c029f,
        0xfc07805a,
        0x04807a01,
        0xfc99a9c7,
        0x51c8c000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x50170370,
        0xfa3f8000,
        0x803b029f,
        0xfb07905a,
        0x04a07a01,
        0xfc99a9f7,
        0x4fc8b000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xe000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x50170360,
        0xfa2f8000,
        0x803c028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00003,
        0xf000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x70170380,
        0xfa3f8000,
        0x803d028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa07,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x80170380,
        0xfa3f8000,
        0x803d028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa07,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x80170390,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8c000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x50180360,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8c000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00003,
        0xf000000f,
        0xbe000f80,
        0xfe8ff3fb,
        0x40180350,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8c000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x50180360,
        0xfa4f8000,
        0x803d028f,
        0xfb079059,
        0x04a07a01,
        0xfc99aa17,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3bd00004,
        0x1000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x60180370,
        0xfa4f8000,
        0x803d028f,
        0xfb079059,
        0x04b07a01,
        0xfc99aa17,
        0x4dc8b000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00004,
        0x0000000f,
        0xbf000f80,
        0xfe8ff3fb,
        0x40180360,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04b07a01,
        0xfc99aa27,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00004,
        0x1000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x30190350,
        0xfa3f8000,
        0x803d028f,
        0xfb07905a,
        0x04b07a01,
        0xfc99aa27,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe4,
        0x3be00004,
        0x2000000f,
        0xc0000f80,
        0xfe8ff3fb,
        0x40180360,
        0xfa4f8000,
        0x803c028f,
        0xfb07905a,
        0x04b07a01,
        0xfc99aa27,
        0x4dc8b000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe4,
        0x3be00004,
        0x2000000f,
        0xc1000f80,
        0xfe8ff3fb,
        0x30180360,
        0xfa4f8100,
        0x803c028f,
        0xfb07905a,
        0x04b07a01,
        0xfc99aa27,
        0x4ec8b000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc1000f80,
        0xfe8ff3fb,
        0x20190350,
        0xfa3f8000,
        0x803c028f,
        0xfb07805a,
        0x04c07a01,
        0xfc99aa17,
        0x4ec8b000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc2000f80,
        0xfe8ff3fb,
        0x20190350,
        0xfa0f8000,
        0x803d028f,
        0xfb07805a,
        0x04d07a01,
        0xfc99aa07,
        0x4fc8b000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x60170380,
        0xf9ff8000,
        0x803e029f,
        0xfb07705a,
        0x04c07a01,
        0xfc99aa17,
        0x4ec8b000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x4000000f,
        0xc4000f7f,
        0xfe8ff3fb,
        0x80160390,
        0xfa0f8000,
        0x803d029f,
        0xfb07605a,
        0x04c07a01,
        0xfc99aa17,
        0x4ec8a000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc4000f7f,
        0xfe8ff3fb,
        0x70170380,
        0xf9ff8000,
        0x803c028f,
        0xfc07705b,
        0x04d07a01,
        0xfc99aa17,
        0x4fc8b000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x70170370,
        0xfa0f8000,
        0x803b028f,
        0xfc07705b,
        0x04e07a01,
        0xfc99aa17,
        0x50c8c000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x70170370,
        0xfa1f8000,
        0x8037025f,
        0xfb07a05d,
        0x05007a01,
        0xfc99aa87,
        0x4fc89000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x50180360,
        0xfa1f8000,
        0x8034024f,
        0xfb07c05e,
        0x05107a01,
        0xfc99aac7,
        0x4ec88000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x40190360,
        0xfa0f8000,
        0x8034023f,
        0xfb07d05f,
        0x05007a01,
        0xfc99aad7,
        0x4ec89000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc3000f80,
        0xfe8ff3fb,
        0x40190360,
        0xfa0f8000,
        0x8034023f,
        0xfb07d05f,
        0x05007a01,
        0xfc99aad7,
        0x4fc89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x2000000f,
        0xc3000f80,
        0xfe8ff3fb,
        0x40190360,
        0xf9ff8000,
        0x8034022f,
        0xfb07d05f,
        0x04f07a01,
        0xfc99aa97,
        0x53c8b000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x70170370,
        0xfa0f8000,
        0x8034022f,
        0xfb07e05f,
        0x04f07a01,
        0xfc99aab7,
        0x53c8a000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x70170370,
        0xfa0f8000,
        0x8033022f,
        0xfb07e060,
        0x04f07a01,
        0xfc99aac7,
        0x52c89000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x70100370,
        0xfa0f8000,
        0x8032021f,
        0xfb07f060,
        0x04f07a01,
        0xfc99aad7,
        0x52c88000,
        0xd5d00000,
        0x0232000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc4000f80,
        0xfe8ff3fb,
        0x50120360,
        0xf9ff8000,
        0x803101ff,
        0xfb080060,
        0x04e07a01,
        0xfc99aad7,
        0x53c89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x400c0360,
        0xfa0f8100,
        0x802f01ef,
        0xfc080060,
        0x04d07a01,
        0xfc99aac7,
        0x54c89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x200a0340,
        0xfa1f8100,
        0x802e01df,
        0xfb081061,
        0x04d07a01,
        0xfc99aac7,
        0x54c88000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fa,
        0xe00b0320,
        0xfa0f8100,
        0x802e01df,
        0xfc081062,
        0x04e07a01,
        0xfc99aac7,
        0x54c89000,
        0xd5d00000,
        0x0231000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fa,
        0xe00a0320,
        0xfa1f8100,
        0x802e01cf,
        0xfc082063,
        0x04e07a01,
        0xfc99aad7,
        0x54c88000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc7000f80,
        0xfe8ff3fa,
        0xf00a0330,
        0xfa1f8100,
        0x802e01cf,
        0xfc083064,
        0x04f07a01,
        0xfc99aae7,
        0x53c88000,
        0xd5d00000,
        0x0230000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc6000f80,
        0xfe8ff3fa,
        0xf00a0330,
        0xfa0f8100,
        0x802d01cf,
        0xfc085064,
        0x05007a01,
        0xfc99aad7,
        0x54c88000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc6000f80,
        0xfe8ff3fa,
        0xf0080330,
        0xfa0f8100,
        0x802e01df,
        0xfc086062,
        0x05007a01,
        0xfc99aac7,
        0x54c88000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x000c0330,
        0xfa0f8100,
        0x802d01df,
        0xfc087060,
        0x04f07a01,
        0xfc99aad7,
        0x54c88000,
        0xd5d00000,
        0x022f000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x000d0330,
        0xfa0f8100,
        0x802d01df,
        0xfc089060,
        0x05007a01,
        0xfc99aae7,
        0x53c88000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x000c0330,
        0xfa0f8100,
        0x802c01cf,
        0xfc08d060,
        0x05307a01,
        0xfc99ab07,
        0x51c88000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100d0340,
        0xfa0f8100,
        0x802c01cf,
        0xfc08d060,
        0x05307a01,
        0xfc99ab17,
        0x51c88000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100c0350,
        0xfa1f8100,
        0x802c01cf,
        0xfc08e060,
        0x05307a01,
        0xfc99ab27,
        0x50c88000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100c0350,
        0xfa1f8100,
        0x802c01cf,
        0xfc08e060,
        0x05207a01,
        0xfc99ab37,
        0x50c88000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100e0350,
        0xfa0f8100,
        0x802d01cf,
        0xfc08f060,
        0x05207a01,
        0xfc99ab37,
        0x4fc88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100b0340,
        0xfa0f8100,
        0x802d01df,
        0xfc090060,
        0x05207a01,
        0xfc99ab37,
        0x4fc88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x200d0350,
        0xfa0f8100,
        0x802d01cf,
        0xfc091060,
        0x05207a01,
        0xfc99ab47,
        0x4ec88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x200c0350,
        0xfa1f8100,
        0x802d01cf,
        0xfc093060,
        0x05207a01,
        0xfc99ab57,
        0x4ec87000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100d0340,
        0xfa1f8100,
        0x802e01cf,
        0xfc09405f,
        0x05207a01,
        0xfc99ab57,
        0x4ec87000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc5000f80,
        0xfe8ff3fb,
        0x100e0340,
        0xfa0f8100,
        0x802e01cf,
        0xfc09505f,
        0x05307a01,
        0xfc99ab57,
        0x4ec87000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x200d0350,
        0xfa1f8100,
        0x802e01cf,
        0xfc09505f,
        0x05307a01,
        0xfc99ab57,
        0x4ec87000,
        0xd5d00000,
        0x022e000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x100a0350,
        0xfa1f8100,
        0x802f01cf,
        0xfc095060,
        0x05307a01,
        0xfc99ab47,
        0x4ec87000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3be00004,
        0x2000000f,
        0xc7000f80,
        0xfe8ff3fb,
        0x000d0340,
        0xfa0f8100,
        0x802f01df,
        0xfc095060,
        0x05407a01,
        0xfc99ab27,
        0x4ec88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x4000000f,
        0xc9000f80,
        0xfe8ff3fb,
        0x10090340,
        0xfa1f8100,
        0x802f01ef,
        0xfc095060,
        0x05407a01,
        0xfc99ab17,
        0x4ec87000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xc9000f80,
        0xfe8ff3fb,
        0x00090330,
        0xfa1f8100,
        0x802f01ff,
        0xfc09305f,
        0x05407a01,
        0xfc99aaf7,
        0x4fc88000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc8000f80,
        0xfe8ff3fa,
        0xd00c0320,
        0xfa1f8100,
        0x802f020f,
        0xfc09305f,
        0x05307a01,
        0xfc99aab7,
        0x50c8b000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc8000f81,
        0xfe8ff3fa,
        0xc0080310,
        0xfa1f8100,
        0x8030021f,
        0xfc09305f,
        0x05307a01,
        0xfc99aaa7,
        0x50c8b000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc8000f80,
        0xfe8ff3fa,
        0xe0090330,
        0xfa1f8100,
        0x8030021f,
        0xfc09205f,
        0x05307a01,
        0xfc99aab7,
        0x50c8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc8000f80,
        0xfe8ff3fb,
        0x00080330,
        0xfa2f8100,
        0x8030021f,
        0xfc09105f,
        0x05307a01,
        0xfc99aab7,
        0x50c8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc7000f80,
        0xfe8ff3fa,
        0xe00b0320,
        0xfa3f8100,
        0x8030021f,
        0xfc09105f,
        0x05307a01,
        0xfc99aab7,
        0x50c8b000,
        0xd5d00000,
        0x0229000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xd00a0320,
        0xfa3f8100,
        0x8030021f,
        0xfc09105f,
        0x05207a01,
        0xfc99aab7,
        0x50c8b000,
        0xd5d00000,
        0x0229000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xd00c0320,
        0xfa3f8100,
        0x8030022f,
        0xfc09105f,
        0x05207a01,
        0xfc99aab7,
        0x50c8b000,
        0xd5d00000,
        0x0229000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xd00c0320,
        0xfa3f8100,
        0x8031022f,
        0xfc09105f,
        0x05207a01,
        0xfc99aab7,
        0x4fc8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x1000000f,
        0xc7000f80,
        0xfe8ff3fa,
        0xe00b0320,
        0xfa3f8100,
        0x8031022f,
        0xfc09205f,
        0x05207a01,
        0xfc99aab7,
        0x4fc8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xf00c0320,
        0xfa3f8100,
        0x8030021f,
        0xfc09205f,
        0x05307a01,
        0xfc99aac7,
        0x4fc8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x0000000f,
        0xc7000f81,
        0xfe8ff3fa,
        0xe00b0320,
        0xfa3f8100,
        0x8030021f,
        0xfc09205f,
        0x05307a01,
        0xfc99aad7,
        0x4ec8a000,
        0xd5d00000,
        0x022a000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x1000000f,
        0xc8000f80,
        0xfe8ff3fa,
        0xd00a0320,
        0xfa2f8100,
        0x8030020f,
        0xfc092060,
        0x05307a01,
        0xfc99aad7,
        0x4fc8a000,
        0xd5d00000,
        0x022b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xca000f80,
        0xfe7ff3fa,
        0xe0060320,
        0xfa1f8100,
        0x802f01ff,
        0xfc092060,
        0x05307a01,
        0xfc99aad7,
        0x4fc8a000,
        0xd5d00000,
        0x022b000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x3000000f,
        0xca000f80,
        0xfe7ff3fa,
        0xc0070310,
        0xfa1f8100,
        0x803001ff,
        0xfc09105f,
        0x05407a01,
        0xfc99aac7,
        0x4fc8a000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x3000000f,
        0xc9000f80,
        0xfe7ff3fa,
        0xa0070300,
        0xfa1f8100,
        0x803001ff,
        0xfc09105f,
        0x05407a01,
        0xfc99aab7,
        0x50c8a000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3be00004,
        0x3000000f,
        0xca000f80,
        0xfe7ff3fa,
        0xb0060310,
        0xfa1f8100,
        0x8030020f,
        0xfc09105f,
        0x05407a01,
        0xfc99aac7,
        0x50c89000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x3000000f,
        0xca000f80,
        0xfe7ff3fa,
        0xc0070320,
        0xfa1f8100,
        0x8030020f,
        0xfc092060,
        0x05407a01,
        0xfc99aac7,
        0x4fc89000,
        0xd5d00000,
        0x022d000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe203fc,
        0x040e6fe3,
        0x3be00004,
        0x2000000f,
        0xc9000f80,
        0xfe8ff3fa,
        0xc0060320,
        0xf9ff8100,
        0x8032021f,
        0xfc091060,
        0x05507a01,
        0xfc99aac7,
        0x4fc8a000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe3,
        0x3bd00004,
        0x2000000f,
        0xc7000f80,
        0xfe8ff3fb,
        0x00070340,
        0xfa8f7e00,
        0x8036025f,
        0xfa092060,
        0x05507a01,
        0xfc99aac7,
        0x4fc89000,
        0xd5d00000,
        0x022c000a,
        0x86f68fb5,
        0xf57fcb12,
        0x6fe303fc,
        0x040e6fe4,
        0x3bd00004,
        0x2000000f,
        0xc6000f80,
        0xfe8ff3fb,
        0x50070380};

void ReadAnimationSet(Animation *animations, int numberAnimations, unsigned long animationTable, int numParts)
{
    //&_animation_dataSegmentRomStart;
    //&_animation_tableSegmentRomStart; //0x124AC0;

    animations.clear();

    for (int animationNumber = 0; animationNumber < numberAnimations; animationNumber++)
    {
        int animationOffset = &animationTable + (animationNumber * 4);
        AnimationHeader animation;
        AnimationHeader animationHeaderTemp;

        animation.numframes = numParts;
        animation.motion.clear();

        animationHeaderTemp.motion        = &_animation_tableSegmentRomStart + *(&_animation_dataSegmentRomStart + animationOffset + 0); //0x124AC0 AKA &ANIM_DATA_empty[] + ANIM_ENTRY_Idle.motion
        animationHeaderTemp.numframes     = &_animation_dataSegmentRomStart + animationOffset + 4;
        animationHeaderTemp.rotbits       = &_animation_dataSegmentRomStart + animationOffset + 6;
        animationHeaderTemp.flags         = &_animation_dataSegmentRomStart + animationOffset + 7;
        animationHeaderTemp.bitsrel       = &_animation_dataSegmentRomStart + *(&_animation_dataSegmentRomStart + animationOffset + 8);
        animationHeaderTemp.bitssizerel   = &_animation_dataSegmentRomStart + animationOffset + 0xC;
        animationHeaderTemp.bitssize      = &_animation_dataSegmentRomStart + animationOffset + 0xE;
        animationHeaderTemp.bitsmotionrel = &_animation_dataSegmentRomStart + *(&_animation_dataSegmentRomStart + animationOffset + 0x10);

        for (int r = 0; r < 4; r++)
        {
            animation.bitsrel[r].start            = ([animationHeaderTemp.bitsrel + (0x6 * r)]);
            animation.bitsrel[r].num              = [animationHeaderTemp.bitsrel + (0x6 * r) + 2];
            animation.bitsrel[r].offset           = ([animationHeaderTemp.bitsrel + (0x6 * r + 4)]);
        }

        animation.flags                      = animationHeaderTemp.flags;
        animation.rotbits = animationHeaderTemp.rotbits;
        animation.bitssize      = animationHeaderTemp.bitssize;
        animation.bitssizerel                = animationHeaderTemp.bitssizerel;

        animation.motion.clear();

        for (int keyframeIndex = 0; keyframeIndex < animationHeaderTemp.numframes; keyframeIndex++) //eg idle is 0 to 163, bitssizerel = 0, bitsise = 544, robits = 12, start = 0, num = 6
        {
            AnimationKeyframe keyframe;
            unsigned long     transRotYROMOffset = animationHeaderTemp.bitsmotionrel; //eg idle = 0x18

            unsigned short    valueRead   = GetBitsFromIndex(keyframeIndex, [transRotYROMOffset], animationHeaderTemp.bitssizerel, animation.animationBitsDesc[0].start, animation.animationBitsDesc[0].num);
            keyframe.keyframeTranslationX = SignExtend(animation.animationBitsDesc[0].num, valueRead) + (signed short)animation.animationBitsDesc[0].offset;

            valueRead                     = GetBitsFromIndex(keyframeIndex, [transRotYROMOffset], animationHeaderTemp.bitssizerel, animation.animationBitsDesc[1].start, animation.animationBitsDesc[1].num);
            keyframe.keyframeTranslationY = SignExtend(animation.animationBitsDesc[1].num, valueRead) + (signed short)animation.animationBitsDesc[1].offset;

            valueRead                     = GetBitsFromIndex(keyframeIndex, [transRotYROMOffset], animationHeaderTemp.bitssizerel, animation.animationBitsDesc[2].start, animation.animationBitsDesc[2].num);
            keyframe.keyframeTranslationZ = SignExtend(animation.animationBitsDesc[2].num, valueRead) + (signed short)animation.animationBitsDesc[2].offset;

            valueRead                  = GetBitsFromIndex(keyframeIndex, [transRotYROMOffset], animationHeaderTemp.bitssizerel, animation.animationBitsDesc[3].start, animation.animationBitsDesc[3].num);
            unsigned short valueRot    = SignExtend(animation.animationBitsDesc[3].num, valueRead) + (unsigned short)animation.animationBitsDesc[3].offset;
            keyframe.keyframeYRotation = D3DXToDegree((valueRot * TWOPI) / 65536.0f);

            unsigned long motion = animationHeaderTemp.motion + (animationHeaderTemp.bitssize >> 3) * keyframeIndex;

            for (int x = 0; x < numParts; x++)
            {
                unsigned long xrotMapOffset1 = GetBitsFromIndex(x * 3, [motion], animationHeaderTemp.rotbits, 0, animationHeaderTemp.rotbits) << 4;
                float         xcoordRot      = (xrotMapOffset1 * TWOPI) / 65536.0f;
                keyframe.partRotations[x].x  = D3DXToDegree(xcoordRot);

                unsigned long yrotMapOffset1 = GetBitsFromIndex(x * 3, [motion], animationHeaderTemp.rotbits, animationHeaderTemp.rotbits, animationHeaderTemp.rotbits) << 4;
                float         ycoordRot      = (yrotMapOffset1 * TWOPI) / 65536.0f;
                keyframe.partRotations[x].y  = D3DXToDegree(ycoordRot);

                unsigned long zrotMapOffset1 = GetBitsFromIndex(x * 3, [motion], animationHeaderTemp.rotbits, animationHeaderTemp.rotbits * 2, animationHeaderTemp.rotbits) << 4;
                float         zcoordRot      = (zrotMapOffset1 * TWOPI) / 65536.0f;
                keyframe.partRotations[x].z  = D3DXToDegree(zcoordRot);
            }

            animation.motion.push_back(keyframe);
        }

        animations.push_back(animation);
    }
}
#    endif
#endif

#if 0

#    include "../include/CPPLib.h"
#    include "../src/bondaicommands.h" //make sure this is after constants
#    include "../src/bondconstants.h"
#    include "../src/game/chrai.h"
#    define IFNOT(COND) EVAL2(PUSH_ARGS(INC(GNUM), IF_##COND)) \
    _AI_IF
#    define _AI_IF(a)             a _AI_IF_ELSE
#    define _AI_IF_ELSE(a)        a
#    define _SWAPSTATEMENTS(A, B) B A
#    define ELSEIIF(COND)         IF_##COND
#    define GNUM                  0
        DO( //D O(GAILIST LOOP1)

            IFNOT(GUARD_HAS_STOPPED_MOVING(INCGNUM)) 
            (
                 /*ELSE*/ CONTINUE(GAILIST_LOOP1)
            )
            (
                LABEL(GAILIST_STOPPED_MOVING)
                IF_GUARD_SEES_BOND(INC(GNUM))
                /*ELSE*/ IF_GUARD_WAS_SHOT_OR_SEEN_WITHIN_LAST_10_SECS(GAILIST_DONE)
                /*ELSE*/ IF_GUARD_HEARD_BOND_WITHIN_LAST_10_SECS(GAILIST_DONE)
                /*ELSEIF*/ RANDOM_GENERATE_GREATER_THAN(1, GAILIST_NEXT) // 1/255 chance of playing idle animation
                /*ELSE*/
                    SETRETURNAILIST(GAILIST_ID_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
                    JUMP(CHR_SELF, GAILIST_ID_IDLE_RAND_ANIM_SUBROUTINE) // play idle animation and return to list
                /*ENDIF*/
            )
            LABEL(GAILIST_NEXT)
        )
#endif

/* The circumference of a circle with diameter 1, PI.*/
#define M_PI_F       3.1415927f
/* The circumference of a circle with diameter 1, PI.*/
#define M_MINUS_PI_F -3.1415927f

/* The circumference of a circle with radius 1, PI*2.*/
#define M_TAU              6.28318530717958647692
/* The circumference of a circle with radius 1, PI*2.*/
#define M_TAU_F            6.2831855f
// Converts radians to degrees.
#define DEG2BYTE(DEG)      (char)(256.0f / 360.0f * (DEG))
#define RAD2BYTE(RAD)      (char)(256.0f / M_TAU_F * (RAD))
#define DegToRad(DEG)      (float)((DEG)*M_TAU / 360.0)
#define RadToDeg(RAD)      (float)((RAD) / M_TAU_F * 360.0f)
#define ByteToRadian(Byte) ((Byte * M_TAU_F) * (1.0f / 256.0f))

float M_45_DEG_IN_RAD  = 0.7853982f;
float M45              = DegToRad(45);
float M_90_DEG_IN_RAD  = 1.5707964f;
float M90              = DegToRad(90);
float M_100_DEG_IN_RAD = 1.7453293f;
float M100             = DegToRad(100);
float M_110_DEG_IN_RAD = 1.9198622f;
float M110             = DegToRad(110);
float M_135_DEG_IN_RAD = 2.3561945f;
float M135             = DegToRad(135);
float M_225_DEG_IN_RAD = 3.926991f;
float M225             = DegToRad(225.00001);
float M_250_DEG_IN_RAD = 4.363323f;
float M250             = DegToRad(250);
float M_260_DEG_IN_RAD = 4.537856f;
float M260             = DegToRad(260);
float M_270_DEG_IN_RAD = 4.712389f;
float M270             = DegToRad(270);
float M_315_DEG_IN_RAD = 5.4977875f;
float M315             = DegToRad(315.00001);

#define TARGET_N64
#include <PR/ultratypes.h>
#include <PR/os.h>
#include <PR/r4300.h>
u16 * g_DebugOutputVideoBuffer1 = NULL;
u16 * g_DebugOutputVideoBuffer2 = NULL;

void  deboutSetBuffers(u16 *buffer1, u16 *buffer2)
{
    g_DebugOutputVideoBuffer1 = (void*)K0_TO_K1(buffer1);
    g_DebugOutputVideoBuffer2 = (void*)K0_TO_K1(buffer2);
}
void deboutSetBuffers2(u16 *buffer1, u16 *buffer2)
{
    g_DebugOutputVideoBuffer1 = OS_PHYSICAL_TO_K1(buffer1);
    g_DebugOutputVideoBuffer2 = OS_PHYSICAL_TO_K1(buffer2);
}
