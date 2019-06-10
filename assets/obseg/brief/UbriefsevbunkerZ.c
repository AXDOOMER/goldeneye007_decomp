#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsevbunkerZ = {
    {                                  /* Mission Briefing */
        0x7800,                        /* Background */
        0x7801,                        /* M Briefing */
        0x7802,                        /* Q Branch */
        0x7803                         /* Moneypenny */
    },
    {                                  /* Objectives (Text and Difficult) */
        {0x7804, DIFFICULTY_SECRET},   /* Disrupt all surveillance equipment */
        {0x7805, DIFFICULTY_AGENT},    /* Copy Goldeneye key and leave original */
        {0x7806, DIFFICULTY_00},       /* Get personnel to activate computer */
        {0x7807, DIFFICULTY_00},       /* Download data from computer */
        {0x7808, DIFFICULTY_AGENT},    /* Photograph main video screen */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000},              /* Not assigned */
        {0x0000, 0x0000}               /* Not assigned */
    }
};
