#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsevxZ = {
    {                        /* Mission Briefing */
        0x7C00,              /* Background */
        0x7C01,              /* M Briefing */
        0x7C02,              /* Q Branch */
        0x7C03               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x7C04, DIFF_A},    /* Power down communications dish */
        {0x7C05, DIFF_SA},   /* Obtain safe key */
        {0x7C06, DIFF_SA},   /* Steal building plans */
        {0x7C07, DIFF_A},    /* Enter base via ventilation tower */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
