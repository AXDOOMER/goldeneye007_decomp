#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefdepoZ = {
    {                                  /* Mission Briefing */
        0x3000,                        /* Background */
        0x3001,                        /* M Briefing */
        0x3002,                        /* Q Branch */
        0x3003                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x3004, DIFFICULTY_00},       /* Destroy illegal arms cache */
        {0x3005, DIFFICULTY_SECRET},   /* Destroy computer network */
        {0x3006, DIFFICULTY_SECRET},   /* Obtain safe key */
        {0x3007, DIFFICULTY_SECRET},   /* Recover helicopter blueprints */
        {0x3008, DIFFICULTY_AGENT},    /* Locate Trevelyan's train */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
