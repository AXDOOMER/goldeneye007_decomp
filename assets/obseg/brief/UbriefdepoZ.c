#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefdepoZ = {
    {                        /* Mission Briefing */
        0x3000,              /* Background */
        0x3001,              /* M Briefing */
        0x3002,              /* Q Branch */
        0x3003               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x3004, DIFF_00A},  /* Destroy illegal arms cache */
        {0x3005, DIFF_SA},   /* Destroy computer network */
        {0x3006, DIFF_SA},   /* Obtain safe key */
        {0x3007, DIFF_SA},   /* Recover helicopter blueprints */
        {0x3008, DIFF_A},    /* Locate Trevelyan's train */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
