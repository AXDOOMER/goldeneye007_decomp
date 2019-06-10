#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsevbZ = {
    {                                  /* Mission Briefing */
        0x7400,                        /* Background */
        0x7401,                        /* M Briefing */
        0x7402,                        /* Q Branch */
        0x7403                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x7404, DIFFICULTY_SECRET},   /* Compare staff / casualty lists */
        {0x7405, DIFFICULTY_AGENT},    /* Recover CCTV tape */
        {0x7406, DIFFICULTY_SECRET},   /* Disable all security cameras */
        {0x7407, DIFFICULTY_00},       /* Recover Goldeneye operations manual */
        {0x7408, DIFFICULTY_AGENT},    /* Escape with Natalya */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
