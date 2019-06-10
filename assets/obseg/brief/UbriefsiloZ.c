#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsiloZ = {
    {                                  /* Mission Briefing */
        0x8800,                        /* Background */
        0x8801,                        /* M Briefing */
        0x8802,                        /* Q Branch */
        0x8803                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x8804, DIFFICULTY_00},       /* Plant bombs in fuel rooms */
        {0x8805, DIFFICULTY_AGENT},    /* Photograph satellite */
        {0x8806, DIFFICULTY_SECRET},   /* Obtain telemetric data */
        {0x8807, DIFFICULTY_SECRET},   /* Retrieve satellite circuitry */
        {0x8808, DIFFICULTY_AGENT},    /* Minimize scientist casualties */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
