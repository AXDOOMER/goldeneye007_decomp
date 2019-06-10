#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbrieftraZ = {
    {                                  /* Mission Briefing */
        0x9000,                        /* Background */
        0x9001,                        /* M Briefing */
        0x9002,                        /* Q Branch */
        0x9003                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x9004, DIFFICULTY_AGENT},    /* Destroy break units */
        {0x9005, DIFFICULTY_AGENT},    /* Rescue Natalya */
        {0x9006, DIFFICULTY_SECRET},   /* Locate Janus secret base */
        {0x9007, DIFFICULTY_00},       /* Crack Boris' password */
        {0x9008, DIFFICULTY_AGENT},    /* Escape to safety */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
