#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefcontrolZ = {
    {                                  /* Mission Briefing */
        0x2000,                        /* Background */
        0x2001,                        /* M Briefing */
        0x2002,                        /* Q Branch */
        0x2003                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x2004, DIFFICULTY_AGENT},    /* Protect Natalya */
        {0x2005, DIFFICULTY_AGENT},    /* Disable Goldeneye satellite */
        {0x2006, DIFFICULTY_AGENT},    /* Destroy armored mainframes */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
