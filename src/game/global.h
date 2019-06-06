#ifndef _GLOBAL_H_
#define _GLOBAL_H_

/*

   This is a temp file until we figure out if a global header is a good
   idea. Might be better to create mode specific headers (briefing, mission)
   instead of cramming everything into one header.

*/

#define MAX_OBJECTIVES 10

enum MISSION_BRIEFING_ENUM {BRIEF_BG = 0, BRIEF_M, BRIEF_Q, BRIEF_MP};
enum MISSION_DIFFICULTY_ENUM {DIFF_A = 0, DIFF_SA, DIFF_00A, DIFF_007};

#endif
