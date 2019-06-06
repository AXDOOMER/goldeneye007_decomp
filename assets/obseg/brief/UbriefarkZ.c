#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefarkZ = {
    {                        /* Mission Briefing */
        0x0C00,              /* Background */
        0x0C01,              /* M Briefing */
        0x0C02,              /* Q Branch */
        0x0C03               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x0C04, DIFF_A},    /* Gain entry to lab area */
        {0x0C05, DIFF_SA},   /* Contact double agent */
        {0x0C06, DIFF_A},    /* Rendezvous with 006 */
        {0x0C07, DIFF_A},    /* Destroy all tanks in bottling room */
        {0x0C08, DIFF_A},    /* Minimize scientist casualties */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
