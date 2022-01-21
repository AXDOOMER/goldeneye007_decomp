#include <ultra64.h>

#if defined(VERSION_US) || defined(VERSION_JP)
u8 _decompressBuffer[0xAB400];
#endif

#if defined(VERSION_EU)
u8 _decompressBuffer[0xA1AB0];
#endif