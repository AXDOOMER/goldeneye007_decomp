#ifndef _CHR2_H_
#define _CHR2_H_
#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"





s32 load_body_head_if_not_loaded(s32 model);

Model * makeonebody(int body,int head, ModelFileHeader *bodyheader,ModelFileHeader *headheader, int sunglasses,Model *model);

Model * setup_chr_instance(int body,int head, ModelFileHeader *body_header, ModelFileHeader *head_header,int sunglasses);

Model * retrieve_header_for_body_and_head(s32 body, s32 head, u32 bitflags);

s32 get_current_random_body(void);

s32 select_psuedorandom_heads(s32 id);

s32 get_random_head(s32 id);
f32 distToBond3D(struct ChrRecord *guardData);

void chrlvAlertGuardToPlayerPosition(struct ChrRecord *);
void chrlvIdleAnimationRelated7F023A94(struct ChrRecord *arg0, f32 arg1);
f32 sub_GAME_7F032C4C(struct ChrRecord *arg0);
s32 check_if_actor_stationary(struct ChrRecord *);
s32 convertPadIf9000(struct ChrRecord *guardData,s32 padNo);
void chrlvCoordinateTransformSomething(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *arg2, struct coord3d *arg3, struct coord3d *result);
void chrlvStanCollisionRelated(struct coord3d *arg0, struct coord3d *arg1, struct coord3d *result);


#endif
