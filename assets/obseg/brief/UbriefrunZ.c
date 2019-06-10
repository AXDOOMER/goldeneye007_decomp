#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefrunZ = {
    {                                  /* Mission Briefing */
        0x7000,                        /* Background */
        0x7001,                        /* M Briefing */
        0x7002,                        /* Q Branch */
        0x7003                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x7004, DIFFICULTY_AGENT},    /* Find plane ignition key */
        {0x7005, DIFFICULTY_00},       /* Destroy heavy gun emplacements */
        {0x7006, DIFFICULTY_SECRET},   /* Destroy missile battery */
        {0x7007, DIFFICULTY_AGENT},    /* Escape in plane */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
