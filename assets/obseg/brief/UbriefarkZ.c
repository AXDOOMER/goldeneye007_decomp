#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefarkZ = {
    {                                  /* Mission Briefing */
        0x0C00,                        /* Background */
        0x0C01,                        /* M Briefing */
        0x0C02,                        /* Q Branch */
        0x0C03                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x0C04, DIFFICULTY_AGENT},    /* Gain entry to lab area */
        {0x0C05, DIFFICULTY_SECRET},   /* Contact double agent */
        {0x0C06, DIFFICULTY_AGENT},    /* Rendezvous with 006 */
        {0x0C07, DIFFICULTY_AGENT},    /* Destroy all tanks in bottling room */
        {0x0C08, DIFFICULTY_AGENT},    /* Minimize scientist casualties */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
