#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsevxbZ = {
    {                        /* Mission Briefing */
        0x8000,              /* Background */
        0x8001,              /* M Briefing */
        0x8002,              /* Q Branch */
        0x8003               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x8004, DIFF_00A},  /* Disrupt all surveillance equipment */
        {0x8005, DIFF_A},    /* Break communications link to bunker */
        {0x8006, DIFF_SA},   /* Disable Spetznaz support aircraft */
        {0x8007, DIFF_A},    /* Gain entry to bunker */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
