#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefdamZ = {
    {                                  /* Mission Briefing */
        0x2C00,                        /* Background */
        0x2C01,                        /* M Briefing */
        0x2C02,                        /* Q Branch */
        0x2C03                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x2C04, DIFFICULTY_SECRET},   /* Neutralize all alarms */
        {0x2C05, DIFFICULTY_00},       /* Install covert modem */
        {0x2C06, DIFFICULTY_00},       /* Intercept data backup */
        {0x2C07, DIFFICULTY_AGENT},    /* Bungee jump from platform */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
