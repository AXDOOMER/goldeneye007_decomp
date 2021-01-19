#ifndef _DEBUG_PRINT_H_
#define _DEBUG_PRINT_H_

#include "ultra64.h"

struct debug_processor_error_entry
{
  u32 val1;
  u32 val2;
  void *string;
};

extern struct debug_processor_error_entry debug_processor_error_table[];
extern void *stack_ptrs_1[];
extern void *stack_ptrs_2[];
extern void *stack_ptrs_3[];

void deboutWriteChar(unsigned char c);
void deboutScrollUp(s32 numlines);
void deboutInitBuffers();
void deboutDrawToBuffer(u16 *buffer);

#endif
