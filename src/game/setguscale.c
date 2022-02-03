#include <ultra64.h>
#include "unk_09C250.h"

void set_gu_scale(void) {
    guScale((Mtx *)&dword_CODE_bss_8007A100, 0.1f, 0.1f, 0.1f);
}

