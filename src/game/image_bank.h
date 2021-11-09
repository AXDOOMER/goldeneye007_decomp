#ifndef _IMAGE_BANK_H_
#define _IMAGE_BANK_H_
#include "ultra64.h"
#include "game/bondview.h"

extern struct sImageTableEntry *crosshairimage;

extern struct sImageTableEntry *mainfolderimages;

void load_prepare_global_image_bank(void);

#endif
