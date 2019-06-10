#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsevxbZ = {
    {                                  /* Mission Briefing */
        0x8000,                        /* Background */
        0x8001,                        /* M Briefing */
        0x8002,                        /* Q Branch */
        0x8003                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x8004, DIFFICULTY_00},       /* Disrupt all surveillance equipment */
        {0x8005, DIFFICULTY_AGENT},    /* Break communications link to bunker */
        {0x8006, DIFFICULTY_SECRET},   /* Disable Spetznaz support aircraft */
        {0x8007, DIFFICULTY_AGENT},    /* Gain entry to bunker */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
