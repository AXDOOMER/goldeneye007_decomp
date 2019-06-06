#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefpeteZ = {
    {                        /* Mission Briefing */
        0x6400,              /* Background */
        0x6401,              /* M Briefing */
        0x6402,              /* Q Branch */
        0x6403               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x6406, DIFF_SA},   /* Contact Valentin */
        {0x6404, DIFF_A},    /* Pursue Ourumov and Natalya */
        {0x6405, DIFF_A},    /* Minimize civilian casualties */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
