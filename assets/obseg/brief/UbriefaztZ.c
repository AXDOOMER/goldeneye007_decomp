#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefaztZ = {
    {                        /* Mission Briefing */
        0x1400,              /* Background */
        0x1401,              /* M Briefing */
        0x1402,              /* Q Branch */
        0x1403               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x1404, DIFF_A},    /* Reprogram shuttle guidance */
        {0x1405, DIFF_A},    /* Launch shuttle */
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
