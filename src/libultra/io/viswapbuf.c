#include "include/PR/os.h"
#include "ultra64.h"
#include "viint.h"

extern __OSViContext *__osViNext;

void osViSwapBuffer(void *vaddr) {
    u32 int_disabled = __osDisableInt();
    __osViNext->framep = vaddr;
    __osViNext->state |= 0x10; // TODO: figure out what this flag means
    __osRestoreInt(int_disabled);
}
