#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefdestZ = {
    {                                  /* Mission Briefing */
        0x3400,                        /* Background */
        0x3401,                        /* M Briefing */
        0x3402,                        /* Q Branch */
        0x3403                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x3404, DIFFICULTY_AGENT},    /* Rescue Hostages */
        {0x3405, DIFFICULTY_SECRET},   /* Disarm bridge bomb */
        {0x3406, DIFFICULTY_SECRET},   /* Disarm engine room bomb */
        {0x3407, DIFFICULTY_AGENT},    /* Plant tracking bug on helicopter */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
