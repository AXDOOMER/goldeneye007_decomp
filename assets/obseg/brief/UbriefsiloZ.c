#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsiloZ = {
    {                        /* Mission Briefing */
        0x8800,              /* Background */
        0x8801,              /* M Briefing */
        0x8802,              /* Q Branch */
        0x8803               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x8804, DIFF_00A},  /* Plant bombs in fuel rooms */
        {0x8805, DIFF_A},    /* Photograph satellite */
        {0x8806, DIFF_SA},   /* Obtain telemetric data */
        {0x8807, DIFF_SA},   /* Retrieve satellite circuitry */
        {0x8808, DIFF_A},    /* Minimize scientist casualties */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
