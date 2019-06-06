#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefarchZ = {
    {                        /* Mission Briefing */
        0x0800,              /* Background */
        0x0801,              /* M Briefing */
        0x0802,              /* Q Branch */
        0x0803               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x0804, DIFF_A},    /* Escape from interrogation room */
        {0x0805, DIFF_A},    /* Find Natalya */
        {0x0806, DIFF_SA},   /* Recover helicopter black box */
        {0x0807, DIFF_A},    /* Escape with Natalya */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
