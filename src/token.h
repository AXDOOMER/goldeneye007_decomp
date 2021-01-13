#ifndef _TOKEN_H_
#define _TOKEN_H_

#include "ultra64.h"

void tokenSetString(const char *str);
s32 tokenReadIo(void);
const char *tokenFind(s32 index, const char *token);

#endif
