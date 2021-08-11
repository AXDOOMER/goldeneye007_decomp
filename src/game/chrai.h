#ifndef _CHRAI_H_
#define _CHRAI_H_
#include "ultra64.h"



/*
Stop Scolling:
00000000
Sets both scroll timers to zero
*/
#define MONSTOPSCROLL() 0x0
/*
Horizontal Scroll:
00000001	xxxxxxxx	tttttttt
[x] 'width' value like in image mapping to shift the image; short hex percent
[t]ime the move occurs in
*/
#define MONHORZSCROLL(x,t) 0x1, x, t
/*
Vertical Scroll:
00000002	yyyyyyyy	tttttttt
[y] 'height' value like in image mapping to shift image; short hex percent
[t]ime the move occurs in
*/
#define MONVERTSCROLL(y,t) 0x2, y, t
/*
Horizontal Scroll Nonadditive:
00000003	xxxxxxxx	tttttttt
[x] 'width' value shifting the image from original position; short hex percent
[t]ime the move occurs in
*/
#define MONHORZSCROLLNA(x,t) 0x3, x, t
/*
Vertical Scroll Nonadditive:
00000004	yyyyyyyy	tttttttt
[y] 'height' value shifting the image from original position; short hex percent
[t]ime the move occurs in
*/
#define MONVERTSCROLLNA(y,t) 0x4, y, t
/*
Zoom Width:
00000005	xxxxxxxx	tttttttt
[x] zoom factor as a short hex percentage
[t]ime for complete zoom
*/
#define MONZOOMWIDTH(x,t) 0x5, x, t
/*
Zoom Height:
00000006	yyyyyyyy	tttttttt
[x] zoom factor as a short hex percentage
[t]ime for complete zoom
*/
#define MONZOOMHEIGHT(y,t) 0x6, y, t

#define MONZOOMSQUARE(w,t) MONZOOMWIDTH(w, t), MONZOOMHEIGHT(w, t)

/*
Use image:
00000007	000000xx
xx is image number in global image list, starting with 0=BOND
*/
#define MONUSEIMAGE(x) 0x7, x
/*
Hold for Time:
00000008	tttttttt
[t]ime to hold; necessary to break loops, like the 03 action command
*/
#define MONHOLDTIME(t) 0x8, t
/*
Jump to Routine:
00000009	pppppppp
[p]ointer to another animation routine where processing resumes
*/
#define MONJUMPTO(p) 0x9, p
/*
Jump on Chance:
0000000A	pppppppp	0000xxxx
[p]ointer to another animation routine where processing resumes
[x] value to test against a random value.  Jump if rand < xxxx
*/
#define MONJUMPCHANCE(p,x) 0xA, p, x
/*
Loop:
0000000B
restarts group from the beginning of the current animation
*/
#define MONLOOP() 0xB
/*
Stop Animation:
0000000C
Unconditionally stops the animation using the S1 flag.
*/
#define MONSTOPANIM() 0xC
/*
RGBA:
0000000D	RRGGBBAA	tttttttt
New [R]ed, [G]reen, [B]lue, and [A]lpha components
[t]ime for complete transition
*/
#define MONRGBA(rgba, t) 0xD, rgba, t
/*
Set Rotation:
0000000E	rrrrrrrr
set image [r]otation; 0x2000 rotates 360 degrees
primarily used to reset rotation to 0
*/
#define MONSETROTATION(r) 0xE, r
/*
Rotate Image:
0000000F	rrrr.rrrr
[r]otate image incrementally rrrr.rrrr%; 
0x2000 rotates approximately 45 degrees, 0x1555 to mimic a clock
*/
#define MONROTATEIMAGE(r) 0xF, r



struct sfx_register_struct {
    u32 field_0x0;
    u32 field_0x4;
    u32 field_0x8;
    u32 field_0xc;
    u32 field_0x10;
    u32 field_0x14;
};


struct Pad {
    u32 padNumber;
    s32* neighbours;
    u32 pathSetIndex;
    s32 dist_tmp;
};

extern struct Pad * ptr_setup_path_tbl;
extern u32 D_800312A0[];
extern u32 D_800312B4[];
extern u32 D_800312C8[];
extern u32 D_800312F4[];
extern u32 D_80031310[];
extern u32 D_80031950[];
extern u32 D_800319D4[];
extern u32 D_800319F0[];
extern u32 D_80031A0C[];
extern u32 D_80031A28[];
extern u32 D_80031A44[];
extern u32 D_80031A60[];
extern u32 D_80031A7C[];
extern u32 D_80031A98[];
extern u32 D_80031AB4[];
extern u32 D_80031AD0[];
extern u32 D_80031AEC[];
extern u32 D_80031B10[];
extern u32 D_80031B24[];
extern u32 D_80031B38[];
extern u32 D_80031B4C[];
extern u32 D_80031B60[];
extern u32 D_80031BB4[];
extern u32 D_80031BD0[];
extern u32 D_80031BEC[];
extern u32 D_80031C08[];
extern u32 D_80031C80[];
extern u32 D_80031D30[];
extern u32 D_80031D58[];
extern u32 monitor_animation_microcode[];
extern u32 dword_D_80031F00[];
extern u32 dword_D_80031F44[];
extern u32 temp_mine_table[30];
extern f32 gas_damage_flag;
extern u32 gas_cutoff_flag;
extern struct object_standard * ptr_setup_objects;
void stop_alarm(void);

void check_deactivate_gas_sound(void);

#endif
