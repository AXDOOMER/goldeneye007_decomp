#ifndef _DEBUGMENU_H_
#define _DEBUGMENU_H_

#include <ultra64.h>
void blank_debug_buffer_chars(void);
void debugmenuInit_REMOVED(void);
void set_final_debug_text_positions(s32 xadjust,s32 yadjust);
void set_debug_text_color(s32 red,s32 blue,s32 green,s32 alpha);
void set_color_speedgraph(s32 red,s32 green,s32 blue,s32 alpha);
#endif
