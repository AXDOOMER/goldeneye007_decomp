#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbrieftraZ = {
    {                        /* Mission Briefing */
        0x9000,              /* Background */
        0x9001,              /* M Briefing */
        0x9002,              /* Q Branch */
        0x9003               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x9004, DIFF_A},    /* Destroy break units */
        {0x9005, DIFF_A},    /* Rescue Natalya */
        {0x9006, DIFF_SA},   /* Locate Janus secret base */
        {0x9007, DIFF_00A},  /* Crack Boris' password */
        {0x9008, DIFF_A},    /* Escape to safety */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
