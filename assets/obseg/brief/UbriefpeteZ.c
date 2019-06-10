#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefpeteZ = {
    {                                  /* Mission Briefing */
        0x6400,                        /* Background */
        0x6401,                        /* M Briefing */
        0x6402,                        /* Q Branch */
        0x6403                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x6406, DIFFICULTY_SECRET},   /* Contact Valentin */
        {0x6404, DIFFICULTY_AGENT},    /* Pursue Ourumov and Natalya */
        {0x6405, DIFFICULTY_AGENT},    /* Minimize civilian casualties */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
