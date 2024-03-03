#include <ultra64.h>
#include "unk_0C0A70.h"
#include "unk_0A1DA0.h"
#include "debugmenu.h"

/**
* Used in speedGraphDisplay to check if speedgraphframes and g_speedGraphCountAccumulator are
* over the threshold for output.
*/
#define COUNT_REQUIRED_FOR_OUTPUT 20

/**
 * Used in speedGraphDisplay to calculate display Hz.
 */
#ifdef REFRESH_PAL
#define VICLOCK 50
#else
#define VICLOCK 60
#endif

#if defined(LEFTOVERDEBUG)
s32 dword_CODE_bss_8005F3F0[3];
Gfx g_speedGraphDisplayList[2][266];
s32 g_speedGraphDisplayListBank;
u32 g_speedGraphLastOsCount;
u32 g_speedGraphCurrentOsCount;
u32 dword_CODE_bss_800604AC;
#endif

typedef struct {
    u32 unk0;
    u32 osCount;
} unknown_s;

#if defined(LEFTOVERDEBUG)
unknown_s dword_CODE_bss_800604B0[3][32];
s32 dword_CODE_bss_800607B0[3];
s32 dword_CODE_bss_800607C0[3];
s32 dword_CODE_bss_800607D0[3];

#endif
s32 D_800231D0 = 0;

typedef struct {
    s32 color;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} s_800231D4;

#if defined(LEFTOVERDEBUG)
s_800231D4 D_800231D4[5] = {
    {0x00000000, 0x00000000, 0x00000002, 0x00000000},
    {0x00000001, 0x00000000, 0x00000002, 0x00000000},
    {0x00000002, 0xFF000000, 0x00000002, 0x00000000},
    {0x00000003, 0x00009200, 0x00000004, 0xFFFFFFFF},
    {0x00000004, 0xDB000000, 0x00000004, 0xFFFFFFFF}
};

/**
 * 80023224. Seems to accumulate speedgraphframes in speedGraphDisplay. Once above the threshold COUNT_REQUIRED_FOR_OUTPUT,
 * the value COUNT_REQUIRED_FOR_OUTPUT is repeatedly subtracted until below the threshold.
 */
u32 g_speedGraphCountAccumulator = 0;

/**
 * 80023228. Stores max value of speedgraphframes seen in speedGraphDisplay. Resets to zero once
 * output is rendered.
 */
s32 g_speedGraphMaxSeenCount = 0;

#endif

// forward declarations
void speedGraphVideoRelated_2(void);

int sprintf(char *dst, const char *fmt, ...);
u32 *get_counters(void);
/////

void speedGraphDisplayListRelated(void)
{
    #if defined(LEFTOVERDEBUG)
    s32 i;

    gSPEndDisplayList(g_speedGraphDisplayList[0]);
    gSPEndDisplayList(g_speedGraphDisplayList[1]);
    g_speedGraphDisplayListBank = 0;

    for (i = 0; i < 3; i++)
    {
        dword_CODE_bss_800607B0[i] = 0;
        dword_CODE_bss_800607D0[i] = 1;
    }

    speedGraphVideoRelated_2();
    #endif
}

void speedGraphVideoRelated_1(void) {
    #if defined(LEFTOVERDEBUG)
    s32 i;

    g_speedGraphCurrentOsCount = osGetCount();

    for (i = 0; i < 3; i++)
    {        
        dword_CODE_bss_800607C0[i] = ((dword_CODE_bss_800607D0[i] + 31) % 32);
    }
    #endif
}

void speedGraphVideoRelated_2(void) {
    #if defined(LEFTOVERDEBUG)
    s32 i;

    g_speedGraphLastOsCount = g_speedGraphCurrentOsCount;

    for (i = 0; i < 3; i++)
    {
        dword_CODE_bss_800607B0[i] = dword_CODE_bss_800607C0[i];
    }
    #endif
}

#if defined(LEFTOVERDEBUG)
void profileSetMarker(s32 arg0)
{
    s32 index;
    s32 mf;
    OSIntMask mask;
    s32 index2;
    unknown_s *pp;

    index = arg0 & 0xFFFF;
    mask = osSetIntMask(OS_IM_NONE);
    mf = arg0 >> 16;
    index2 = dword_CODE_bss_800607D0[index];

    if (mf == 3)
    {
        // set highest bit
        mf = dword_CODE_bss_8005F3F0[index] | 0x8000;
    }
    else if (mf == 6)
    {
        // clear highest bit
        mf = dword_CODE_bss_8005F3F0[index] & 0x7FFF;
    }

    pp = &dword_CODE_bss_800604B0[index][index2];
    pp->unk0 = mf;
    pp->osCount = osGetCount();
    dword_CODE_bss_8005F3F0[index] = mf;

    index2++;
    
    if (index2 >= 32)
    {
        index2 = 0;
    }

    dword_CODE_bss_800607D0[index] = index2;

    osSetIntMask(mask);
}
#else
void profileSetMarker(void)
{
}
#endif

Gfx *speedGraphDisplay(Gfx *gdl)
{
    #if defined(LEFTOVERDEBUG)
    u32 *counters;
    u32 localCountAccumulator = g_speedGraphCountAccumulator;
    s32 *pmaxSeenCount = &g_speedGraphMaxSeenCount;
    char buffer[12];
    volatile u32 *pcountAccumulator = &g_speedGraphCountAccumulator;
    
    localCountAccumulator += speedgraphframes;

    if (*pmaxSeenCount < speedgraphframes)
    {
        *pmaxSeenCount = speedgraphframes;
    }

    *pcountAccumulator = localCountAccumulator;
    
    if (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT)
    {
        *pcountAccumulator = localCountAccumulator;

        if (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT)
        {
            do
            {
                localCountAccumulator -= COUNT_REQUIRED_FOR_OUTPUT;
            }
            while (localCountAccumulator > COUNT_REQUIRED_FOR_OUTPUT);

            *pcountAccumulator = localCountAccumulator;
        }
        
        counters = get_counters();

        debmenuSetFgColour(255, 255, 255, 255);
        debmenuSetEnvColor(0, 0, 0, 255);

        // utz %
        debmenuSetPos(8, 5);
        sprintf(buffer, "utz %2.0f%%\n", (((counters[1] - counters[3]) * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // rsp %
        debmenuSetPos(8, 6);
        sprintf(buffer, "rsp %2.0f%%\n", (((counters[0] - counters[1]) * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // tex %
        debmenuSetPos(8, 7);
        sprintf(buffer, "tex %2.0f%%", ((counters[3] * 100.0f) / counters[0]));
        debmenuPrintString(buffer);

        // hz (60 / framerate)
        // -- or 50 for PAL
        debmenuSetPos(28, 5);
        sprintf(buffer, "%2d hz", ((speedgraphframes == 0) ? 0 : (VICLOCK / speedgraphframes)));
        debmenuPrintString(buffer);

        // framerate
        debmenuSetPos(28, 6);
        sprintf(buffer, "%2d frames", speedgraphframes);
        debmenuPrintString(buffer);

        // (continues framerate output)
        if (speedgraphframes != g_speedGraphMaxSeenCount)
        {
            sprintf(buffer, " [%2d]", *pmaxSeenCount);
        }
        else
        {
            sprintf(buffer, "     ");
        }

        debmenuPrintString(buffer);
        
        g_speedGraphMaxSeenCount = 0;
    }

    gSPDisplayList(gdl++, g_speedGraphDisplayList[g_speedGraphDisplayListBank ^ 1]);

    return gdl;
    #endif
}


#if defined(LEFTOVERDEBUG)
void video_DL_related_4(void)
{
    s32 var_s1;
    s32 i; // sp 0xc8
    f32 f20;
    s32 phi_s2;
    u32 var_v1;
    Gfx *gdl;
    s32 spAC[3];
    u32 spA0[3];
    Gfx *head;
    s_800231D4 *temp;
    u32 temp_s0;

    static s32 D_8002322C = 0;
    static u32 g_speedGraphCounterForFrames = 0;
    static s32 D_80023234 = 1;

    g_speedGraphCounterForFrames += speedgraphframes;
    if (g_speedGraphCounterForFrames > 200)
    {
        D_80023234 ^= 1;
        g_speedGraphCounterForFrames -= 200;
    }

    if (D_80023234 != (D_8002322C++ & 1))
    {
        gdl = sub_GAME_7F0D1AC0(g_speedGraphDisplayList[g_speedGraphDisplayListBank]);
        
        for (i = 0; i < 3; i++)
        {
            spAC[i] = 0;
        }

        for (i = 0; i < 3; i++)
        {
            spA0[i] = g_speedGraphLastOsCount;
        }
        
        for (i = 0; i < 3; i++)
        {
            var_s1 = dword_CODE_bss_800607B0[i];
                        
            if(1);
            f20 = 0;
            
            while (var_s1 != dword_CODE_bss_800607D0[i])
            {          
                phi_s2 = dword_CODE_bss_800604B0[i][var_s1].unk0;
                
                if (phi_s2 & 0x8000)
                {
                    phi_s2 = 3;
                }
                
                temp_s0 = dword_CODE_bss_800604B0[i][var_s1].osCount; 
                
                if(var_s1);
                //if(1);
                
                var_v1 = spA0[i];
                if (var_v1 < g_speedGraphLastOsCount)
                {
                    var_v1 = g_speedGraphLastOsCount;
                }
                
                if (temp_s0 >= g_speedGraphLastOsCount && temp_s0 >= var_v1)
                {
                    if ((spAC[i] != 1) && (spAC[i] != 3) && ((spAC[i] & 0x8000) == 0))
                    {
                        f20 += (temp_s0 - var_v1) / 775875.0f;
                    }

                    temp = &D_800231D4[spAC[i]];
                    
                    if (spAC[i] == 1)
                    {
                        sub_GAME_7F0D1DCC((temp_s0 - var_v1) / 775875.0f);
                    }
                    else
                    {
                        gdl = sub_GAME_7F0D1BD0(
                            gdl++,
                            (temp_s0 - var_v1) / 775875.0f, 
                            ((temp->unk4 >> 0x18) & 0xFF), 
                            ((temp->unk4 >> 0x10) & 0xFF), 
                            ((temp->unk4 >> 0x8) & 0xFF), 
                            temp->unk8, 
                            temp->unkC);
                    }

                    head = gdl++;
                    gDPPipeSync(head);
                    //gDPPipeSync(gdl++);
                }
                
                spAC[i] = phi_s2;
                spA0[i] = temp_s0;
                var_s1 = ((var_s1 + 1) % 32);
            }
            
            if (i < 2)
            {
                sub_GAME_7F0D2320();
            }
        }
        
        gdl = sub_GAME_7F0D1E98(gdl++, 0, 0, 0);
        gDPPipeSync(gdl++);
        gSPEndDisplayList(gdl);
        
        g_speedGraphDisplayListBank ^= 1;
    }

}
#else
Gfx* video_DL_related_4(Gfx* param_1)
{
  return param_1;
}
#endif

