#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefarchZ = {
    {                                  /* Mission Briefing */
        0x0800,                        /* Background */
        0x0801,                        /* M Briefing */
        0x0802,                        /* Q Branch */
        0x0803                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x0804, DIFFICULTY_AGENT},    /* Escape from interrogation room */
        {0x0805, DIFFICULTY_AGENT},    /* Find Natalya */
        {0x0806, DIFFICULTY_SECRET},   /* Recover helicopter black box */
        {0x0807, DIFFICULTY_AGENT},    /* Escape with Natalya */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
