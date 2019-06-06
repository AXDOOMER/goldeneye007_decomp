#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefstatueZ = {
    {                        /* Mission Briefing */
        0x8C00,              /* Background */
        0x8C01,              /* M Briefing */
        0x8C02,              /* Q Branch */
        0x8C03               /* Moneypenny */
    },
    {                        /* Objectives (Text and Difficult) */
        {0x8C04, DIFF_A},    /* Contact Valentin */
        {0x8C05, DIFF_A},    /* Confront and unmask Janus */
        {0x8C06, DIFF_A},    /* Locate helicopter */
        {0x8C07, DIFF_A},    /* Rescue Natalya */
        {0x8C08, DIFF_A},    /* Find flight recorder */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000},    /* Not assigned */
        {0x0000, 0x0000}     /* Not assigned */
    }
};
