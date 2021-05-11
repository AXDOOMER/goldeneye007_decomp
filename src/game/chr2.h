#ifndef _CHR2_H_
#define _CHR2_H_
#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"





s32 load_body_head_if_not_loaded(s32 model);

Model * maybe_load_models_for_guards(int body,int head, ModelFileHeader *bodyheader,ModelFileHeader *headheader, int sunglasses,Model *model);

Model * setup_chr_instance(int body,int head, ModelFileHeader *body_header, ModelFileHeader *head_header,int sunglasses);

Model *retrieve_header_for_body_and_head(s32 body, s32 head, u32 bitflags);

s32 get_current_random_body(void);

s32 select_psuedorandom_heads(s32 id);

s32 get_random_head(s32 id);




#endif
