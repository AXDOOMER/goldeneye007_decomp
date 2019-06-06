#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefcontrolZ = {
    {                        /* Mission Briefing */
        0x2000,              /* Background */
        0x2001,              /* M Briefing */
        0x2002,              /* Q Branch */
        0x2003               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x2004, DIFF_A},    /* Protect Natalya */
        {0x2005, DIFF_A},    /* Disable Goldeneye satellite */
        {0x2006, DIFF_A},    /* Destroy armored mainframes */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
