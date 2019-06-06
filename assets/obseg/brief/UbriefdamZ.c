#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefdamZ = {
    {                        /* Mission Briefing */
        0x2C00,              /* Background */
        0x2C01,              /* M Briefing */
        0x2C02,              /* Q Branch */
        0x2C03               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x2C04, DIFF_SA},   /* Neutralize all alarms */
        {0x2C05, DIFF_00A},  /* Install covert modem */
        {0x2C06, DIFF_00A},  /* Intercept data backup */
        {0x2C07, DIFF_A},    /* Bungee jump from platform */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
