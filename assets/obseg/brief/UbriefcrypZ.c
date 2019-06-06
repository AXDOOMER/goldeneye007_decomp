#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefcrypZ = {
    {                        /* Mission Briefing */
        0x2800,              /* Background */
        0x2801,              /* M Briefing */
        0x2802,              /* Q Branch */
        0x2803               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x2804, DIFF_A},    /* Recover the golden gun */
        {0x2805, DIFF_A},    /* Defeat Baron Samedi? */
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
