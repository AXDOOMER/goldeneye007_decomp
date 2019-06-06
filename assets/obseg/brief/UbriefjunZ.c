#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefjunZ = {
    {                        /* Mission Briefing */
        0x4800,              /* Background */
        0x4801,              /* M Briefing */
        0x4802,              /* Q Branch */
        0x4803               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x4804, DIFF_A},    /* Destroy drone guns */
        {0x4805, DIFF_A},    /* Eliminate Xenia */
        {0x4806, DIFF_SA},   /* Blow up ammo dump */
        {0x4807, DIFF_A},    /* Escort Natalya to Janus Base */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
