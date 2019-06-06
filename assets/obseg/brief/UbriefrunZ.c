#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefrunZ = {
    {                        /* Mission Briefing */
        0x7000,              /* Background */
        0x7001,              /* M Briefing */
        0x7002,              /* Q Branch */
        0x7003               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x7004, DIFF_A},    /* Find plane ignition key */
        {0x7005, DIFF_00A},  /* Destroy heavy gun emplacements */
        {0x7006, DIFF_SA},   /* Destroy missile battery */
        {0x7007, DIFF_A},    /* Escape in plane */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
