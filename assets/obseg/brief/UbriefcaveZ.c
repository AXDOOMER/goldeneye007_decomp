#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefcaveZ = {
    {                        /* Mission Briefing */
        0x1C00,              /* Background */
        0x1C01,              /* M Briefing */
        0x1C02,              /* Q Branch */
        0x1C03               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x1C04, DIFF_SA},   /* Destroy inlet pump controls */
        {0x1C05, DIFF_SA},   /* Destroy outlet pump controls */
        {0x1C06, DIFF_SA},   /* Destroy master control console */
        {0x1C07, DIFF_00A},  /* Use radio to contact Jack Wade */
     /* {0x1C08, DIFF_A}, */ /* Pursue Trevelyan */
        {0x1C09, DIFF_A},    /* Minimize scientist casualties */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
