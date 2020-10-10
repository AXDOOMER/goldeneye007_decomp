#include "ultra64.h"
#include "game/unk_09C250.h"

void set_gu_scale(void) {
    float default_gu_scale = 0.1f;

    guScale((Mtx *)&dword_CODE_bss_8007A100, default_gu_scale, default_gu_scale, default_gu_scale);
}

