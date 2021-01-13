#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "ultra64.h"

void strtok(const char *str);
s32 check_boot_switches(void);
const char *check_token(s32 arg0, const char *str);

#endif
