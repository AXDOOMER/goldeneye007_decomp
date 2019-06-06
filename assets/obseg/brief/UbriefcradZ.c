#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefcradZ = {
    {                        /* Mission Briefing */
        0x2400,              /* Background */
        0x2401,              /* M Briefing */
        0x2402,              /* Q Branch */
        0x2403               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x2404, DIFF_A},    /* Destroy control console */
        {0x2405, DIFF_A},    /* Settle the score with Trevelyan */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
