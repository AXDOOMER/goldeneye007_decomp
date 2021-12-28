#include "include/os_extension.h"
#include "ultra64.h"
#include "bondgame.h"
#include "bondconstants.h"
#include "joy.h"
#include "music.h"
#include "snd.h"
#include "game/bondinv.h"
#include "game/bondview.h"
#include "game/cheat_buttons.h"
#include "game/chr.h"
#include "game/debugmenu_handler.h"
#include "game/file2.h"
#include "game/front.h"
#include "game/gun.h"
#include "game/lvl_text.h"
#include "game/objecthandler.h"
#include "game/player.h"
#include "game/player_2.h"
//#include "game/chraicommands.h" /* needed for ai list commands, remove when moving global ai lists to chraicommands/chrai */
// bss

// This shows up a lot but not quite sure what it represents.
#define CHEAT_20    20

struct CheatInfo {
    /**
     * Offset 0x0.
     */
    u8 cheat_id;

    /**
     * Offset 0x1.
     */
    u8 count_of_something;

    /**
     * Offset 0x2.
     */
    u8 field_2;

    /**
     * Offset 0x3.
     */
    u8 field_3;

    /**
     * Seems to be pointer to u16 array.
     * Offset 0x4.
     */
    u16 * cheatbuttons;

    /**
     * Offset 0x8.
     */
    u16 text_bank_id;

    /**
     * Offset 0xa.
     */
    u16 unk_a;

    /**
     * Offset 0xc.
     */
    int maskfield;
};


u8 g_CheatPlayerTextRelated[CHEAT_INVALID + 1];



//D:8003F430
u16 btncheat_extrampchars[] = {
    L_CBUTTONS | R_TRIG | L_TRIG, 
    U_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    L_TRIG | R_JPAD,
    R_TRIG | D_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG,
    U_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | R_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | D_JPAD
};

//D:8003F444
u16 btncheat_invincibility[] = {
   L_TRIG | D_JPAD,
   R_CBUTTONS | R_TRIG,
   U_CBUTTONS | R_TRIG,
   L_TRIG | R_JPAD,
   D_CBUTTONS | L_TRIG,
   U_CBUTTONS | R_TRIG,
   L_TRIG | R_JPAD,
   R_TRIG | D_JPAD,
   L_TRIG | L_JPAD,
   R_CBUTTONS | R_TRIG | L_TRIG
};

//D:8003F458
u16 btncheat_allguns[] = {
    R_TRIG | L_TRIG | D_JPAD,
    L_CBUTTONS | L_TRIG,
    R_CBUTTONS | L_TRIG,
    L_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | D_JPAD,
    D_CBUTTONS | L_TRIG,
    L_CBUTTONS | R_TRIG,
    R_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | U_JPAD,
    L_CBUTTONS | L_TRIG

};
//D:8003F46C
u16 btncheat_maxammo[] = {
    R_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | U_JPAD,
    R_TRIG | D_JPAD,
    R_TRIG | D_JPAD,
    R_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | D_JPAD,
    R_TRIG | U_JPAD,
    R_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_JPAD

};
//D:8003F480
u16 btncheat_0x5[] = {
    L_TRIG | U_JPAD,
    R_CBUTTONS | R_TRIG,
    D_CBUTTONS | R_TRIG,
    L_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | R_JPAD,
    R_TRIG | D_JPAD,
    U_CBUTTONS | R_TRIG,
    R_CBUTTONS | R_TRIG,
    R_TRIG | L_TRIG | D_JPAD

};
//D:8003F494
u16 btncheat_removeinvincibility[] = {
    R_TRIG | R_JPAD,
    L_TRIG | L_JPAD,
    L_TRIG | L_JPAD,
    R_TRIG | U_JPAD,
    L_TRIG | D_JPAD,
    D_CBUTTONS | R_TRIG,
    L_CBUTTONS | L_TRIG,
    R_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | D_JPAD,
    U_CBUTTONS | L_TRIG
};
//D:8003F4A8
u16 btncheat_linemode[] = {
    D_CBUTTONS | R_TRIG,
    R_TRIG | L_TRIG | D_JPAD,
    L_TRIG | R_JPAD,
    U_CBUTTONS | R_TRIG,
    R_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | U_JPAD,
    L_TRIG | D_JPAD,
    L_TRIG | R_JPAD,
    L_CBUTTONS | R_TRIG,
    U_CBUTTONS | R_TRIG

};
//D:8003F4BC
u16 btncheat_invisibility[] = {
    L_CBUTTONS | R_TRIG,
    U_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | U_JPAD,
    R_TRIG | U_JPAD,
    L_CBUTTONS | L_TRIG,
    U_CBUTTONS | R_TRIG,
    D_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | R_JPAD
};
//D:8003F4D0
u16 btncheat_0x16[] = {
    U_CBUTTONS | L_TRIG,
    L_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | U_JPAD,
    R_CBUTTONS | L_TRIG,
    L_CBUTTONS | R_TRIG,
    L_TRIG | R_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG,
    R_CBUTTONS | L_TRIG,
    L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG
};
//D:8003F4E4
u16 btncheat_0x37[] = {
    U_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_JPAD,
    D_CBUTTONS | R_TRIG,
    D_CBUTTONS | L_TRIG,
    R_TRIG | U_JPAD,
    L_TRIG | D_JPAD,
    R_CBUTTONS | R_TRIG,
    L_TRIG | R_JPAD,
    R_TRIG | L_TRIG | R_JPAD,
    D_CBUTTONS | R_TRIG
};
//D:8003F4F8
u16 btncheat_0x38[] = {
    U_CBUTTONS | R_TRIG | L_TRIG,
    L_CBUTTONS | R_TRIG,
    L_TRIG | L_JPAD,
    U_CBUTTONS | R_TRIG,
    L_TRIG | L_JPAD,
    D_CBUTTONS | R_TRIG,
    R_CBUTTONS | L_TRIG,
    R_TRIG | R_JPAD,
    U_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | R_JPAD
};
//D:8003F50C
u16 btncheat_0x39[] = {
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | L_JPAD,
    U_CBUTTONS | L_TRIG,
    L_TRIG | L_JPAD,
    U_CBUTTONS | R_TRIG,
    D_CBUTTONS | R_TRIG,
    R_CBUTTONS | R_TRIG,
    R_TRIG | R_JPAD,
    L_TRIG | D_JPAD,
    L_CBUTTONS | R_TRIG
};
//D:8003F520
u16 btncheat_0x3A[] = {
    L_CBUTTONS | R_TRIG,
    U_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | L_JPAD,
    R_TRIG | U_JPAD,
    R_TRIG | L_JPAD,
    L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG,
    L_TRIG | R_JPAD,
    R_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | D_JPAD,
};
//D:8003F534
u16 btncheat_0x3B[] = {
    D_CBUTTONS | L_TRIG,
    R_TRIG | R_JPAD,
    R_CBUTTONS | L_TRIG,
    L_CBUTTONS | R_TRIG,
    D_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    R_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | U_JPAD,
    R_CBUTTONS | R_TRIG,
    L_TRIG | U_JPAD,
};
//D:8003F548
u16 btncheat_0x3C[] = {
    L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG,
    L_TRIG | L_JPAD,
    R_TRIG | D_JPAD,
    L_CBUTTONS | L_TRIG,
    R_CBUTTONS | R_TRIG | L_TRIG,
    U_CBUTTONS | L_TRIG,
    R_TRIG | R_JPAD,
    R_TRIG | R_JPAD,
    R_CBUTTONS | R_TRIG
};
//D:8003F55C
u16 btncheat_0x3D[] = {
    U_CBUTTONS | R_TRIG,
    L_TRIG | D_JPAD,
    R_CBUTTONS | R_TRIG,
    L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    R_CBUTTONS | R_TRIG,
    R_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | U_JPAD
};
//D:8003F570
u16 btncheat_0x3E[] = {
    D_CBUTTONS | L_TRIG,
    R_CBUTTONS | R_TRIG | L_TRIG,
    R_CBUTTONS | R_TRIG,
    U_CBUTTONS | R_TRIG,
    L_CBUTTONS | R_TRIG,
    L_TRIG | R_JPAD,
    U_CBUTTONS | R_TRIG | L_TRIG,
    U_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | D_JPAD,
    R_CBUTTONS | L_TRIG
};
//D:8003F584
u16 btncheat_0x3F[] = {
    L_TRIG | D_JPAD,
    R_TRIG | D_JPAD,
    U_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | R_JPAD,
    L_CBUTTONS | L_TRIG,
    R_TRIG | R_JPAD,
    U_CBUTTONS | L_TRIG,
    L_TRIG | L_JPAD,
    D_CBUTTONS | L_TRIG
};
//D:8003F598
u16 btncheat_0x40[] = {
    D_CBUTTONS | R_TRIG | L_TRIG,
    D_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | R_JPAD,
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | L_JPAD,
    R_CBUTTONS | R_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    U_CBUTTONS | R_TRIG,
    D_CBUTTONS | R_TRIG,
    R_TRIG | R_JPAD
};
//D:8003F5AC
u16 btncheat_0x41[] = {
    R_TRIG | L_JPAD,
    R_TRIG | L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_JPAD,
    R_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | R_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG
};
//D:8003F5C0
u16 btncheat_0x42[] = {
    L_CBUTTONS | R_TRIG | L_TRIG,
    R_CBUTTONS | L_TRIG,
    L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    R_CBUTTONS | R_TRIG,
    D_CBUTTONS | R_TRIG,
    R_TRIG | L_JPAD,
    D_CBUTTONS | R_TRIG,
    U_CBUTTONS | R_TRIG,
    L_TRIG | D_JPAD
};
//D:8003F5D4
u16 btncheat_0x43[] = {
    L_TRIG | D_JPAD,
    L_TRIG | D_JPAD,
    D_CBUTTONS | R_TRIG,
    R_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | R_JPAD,
    L_CBUTTONS | R_TRIG,
    L_TRIG | D_JPAD,
    L_CBUTTONS | L_TRIG,
    R_CBUTTONS | L_TRIG,
    L_TRIG | U_JPAD
};
//D:8003F5E8
u16 btncheat_0x44[] = {
    R_TRIG | L_JPAD,
    D_CBUTTONS | R_TRIG,
    R_CBUTTONS | R_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    L_TRIG | R_JPAD,
    D_CBUTTONS | R_TRIG,
    L_TRIG | L_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | U_JPAD,
    U_CBUTTONS | L_TRIG
};
//D:8003F5FC
u16 btncheat_0x45[] = {
    D_CBUTTONS | R_TRIG,
    R_TRIG | L_JPAD,
    R_TRIG | L_TRIG | U_JPAD,
    R_TRIG | R_JPAD,
    R_TRIG | D_JPAD,
    R_TRIG | D_JPAD,
    R_TRIG | U_JPAD,
    L_CBUTTONS | R_TRIG,
    U_CBUTTONS | R_TRIG,
    R_TRIG | L_TRIG | L_JPAD
};
//D:8003F610
u16 btncheat_0x46[] = {
    D_CBUTTONS | L_TRIG,
    R_TRIG | D_JPAD,
    L_TRIG | R_JPAD,
    R_CBUTTONS | R_TRIG,
    D_CBUTTONS | R_TRIG,
    R_TRIG | L_JPAD,
    R_TRIG | L_JPAD,
    U_CBUTTONS | R_TRIG,
    R_TRIG | L_JPAD,
    U_CBUTTONS | R_TRIG | L_TRIG
};
//D:8003F624
u16 btncheat_0x47[] = {
    L_TRIG | D_JPAD,
    D_CBUTTONS | R_TRIG,
    R_TRIG | L_TRIG | U_JPAD,
    L_TRIG | R_JPAD,
    U_CBUTTONS | R_TRIG,
    L_CBUTTONS | R_TRIG,
    R_TRIG | U_JPAD,
    L_CBUTTONS | L_TRIG,
    L_TRIG | U_JPAD,
    L_CBUTTONS | R_TRIG
};
//D:8003F638
u16 btncheat_0x48[] = {
    U_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | L_JPAD,
    R_TRIG | D_JPAD,
    L_TRIG | D_JPAD,
    U_CBUTTONS | L_TRIG,
    L_TRIG | D_JPAD,
    R_TRIG | R_JPAD,
    U_CBUTTONS | R_TRIG,
    L_CBUTTONS | L_TRIG,
    R_TRIG | R_JPAD
};
//D:8003F64C
u16 btncheat_0x49[] = {
    D_CBUTTONS | R_TRIG,
    R_TRIG | L_JPAD,
    L_TRIG | R_JPAD,
    R_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | D_JPAD,
    U_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | L_JPAD,
    U_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_TRIG | R_JPAD,
    L_CBUTTONS | L_TRIG
};
//D:8003F660
u16 btncheat_unlockstages[] = {
    R_TRIG | L_TRIG | U_JPAD,
    R_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | D_JPAD,
    R_TRIG | R_JPAD,
    R_TRIG | U_JPAD,
    L_TRIG | D_JPAD,
    L_TRIG | L_JPAD,
    R_CBUTTONS | L_TRIG,
    R_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | A_BUTTON,
    R_TRIG | L_TRIG | B_BUTTON,
    R_TRIG | L_TRIG | A_BUTTON,
    R_TRIG | L_TRIG | B_BUTTON
};
//D:8003F67C
u16 btncheat_0x23[] = {
    L_TRIG | U_JPAD,
    U_CBUTTONS,
    R_TRIG | R_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG,
    D_CBUTTONS | L_TRIG,
    D_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_TRIG | U_JPAD,
    D_CBUTTONS | L_TRIG
};
//D:8003F690
u16 btncheat_0x24[] = {
    R_TRIG | L_JPAD,
    L_TRIG | D_JPAD,
    L_JPAD,
    U_JPAD,
    D_JPAD,
    L_CBUTTONS | R_TRIG,
    L_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | R_JPAD,
    L_CBUTTONS | L_TRIG
};
//D:8003F6A4
u16 btncheat_0x25[] = {
    R_TRIG | L_TRIG | U_JPAD,
    R_CBUTTONS,
    R_TRIG | L_JPAD,
    R_TRIG | U_JPAD,
    U_JPAD,
    R_TRIG | R_JPAD,
    U_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_TRIG | D_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG
};
//D:8003F6B8
u16 btncheat_0x26[] = {
    R_TRIG | D_JPAD,
    R_TRIG | U_JPAD,
    R_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | R_JPAD,
    R_TRIG | L_JPAD,
    L_JPAD,
    D_JPAD,
    U_JPAD,
    D_CBUTTONS | R_TRIG
};
//D:8003F6CC
u16 btncheat_0x27[] = {
    R_TRIG | R_JPAD,
    L_TRIG | U_JPAD,
    D_JPAD,
    D_JPAD,
    D_CBUTTONS | R_TRIG,
    L_TRIG | L_JPAD,
    L_CBUTTONS | L_TRIG,
    R_TRIG | U_JPAD,
    R_TRIG | D_JPAD,
    L_CBUTTONS | R_TRIG
};
//D:8003F6E0
u16 btncheat_0x28[] = {
    L_TRIG | D_JPAD,
    D_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | U_JPAD,
    D_CBUTTONS | R_TRIG,
    L_JPAD,
    R_TRIG | D_JPAD,
    D_CBUTTONS | L_TRIG,
    U_JPAD,
    R_TRIG | D_JPAD,
    L_TRIG | R_JPAD
};
//D:8003F6F4
u16 btncheat_0x29[] = {
    R_TRIG | U_JPAD,
    D_CBUTTONS,
    L_CBUTTONS,
    U_CBUTTONS,
    L_TRIG | D_JPAD,
    R_TRIG | U_JPAD,
    L_CBUTTONS,
    R_JPAD,
    R_TRIG | L_JPAD,
    R_TRIG | R_JPAD
};
//D:8003F708
u16 btncheat_0x2A[] = {
    R_TRIG | L_TRIG | D_JPAD,
    R_TRIG | D_JPAD,
    D_CBUTTONS | L_TRIG,
    L_JPAD,
    L_CBUTTONS | R_TRIG,
    D_CBUTTONS | R_TRIG | L_TRIG,
    R_JPAD,
    D_JPAD,
    D_CBUTTONS | R_TRIG,
    R_TRIG | R_JPAD
};
//D:8003F71C
u16 btncheat_0x2B[] = {
    L_CBUTTONS | R_TRIG,
    L_TRIG | L_JPAD,
    U_JPAD,
    R_TRIG | L_TRIG | R_JPAD,
    R_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG,
    L_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | D_JPAD,
    R_TRIG | L_JPAD,
    L_CBUTTONS | R_TRIG
};
//D:8003F730
u16 btncheat_0x2C[] = {
    D_CBUTTONS | L_TRIG,
    L_CBUTTONS | L_TRIG,
    D_CBUTTONS,
    R_CBUTTONS,
    L_CBUTTONS,
    R_TRIG | L_TRIG | R_JPAD,
    R_CBUTTONS,
    R_TRIG | L_TRIG | U_JPAD,
    L_CBUTTONS | R_TRIG,
    L_TRIG | L_JPAD
};
//D:8003F744
u16 btncheat_0x2D[] = {
    L_CBUTTONS | R_TRIG | L_TRIG,
    D_CBUTTONS | R_TRIG | L_TRIG,
    L_CBUTTONS | L_TRIG,
    L_CBUTTONS | R_TRIG,
    R_TRIG | R_JPAD,
    R_TRIG | L_TRIG | L_JPAD,
    L_TRIG | R_JPAD,
    L_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | D_JPAD
};
//D:8003F758
u16 btncheat_0x2E[] = {
    D_CBUTTONS | R_TRIG | L_TRIG,
    L_CBUTTONS,
    D_CBUTTONS | R_TRIG,
    D_CBUTTONS,
    D_CBUTTONS,
    D_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_TRIG | U_JPAD,
    D_CBUTTONS,
    R_TRIG | U_JPAD,
    L_TRIG | U_JPAD
};
//D:8003F76C
u16 btncheat_0x2F[] = {
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | D_JPAD,
    R_TRIG | L_TRIG | L_JPAD,
    R_CBUTTONS,
    R_TRIG | L_TRIG | D_JPAD,
    R_TRIG | L_TRIG | D_JPAD,
    L_TRIG | D_JPAD,
    L_CBUTTONS,
    U_CBUTTONS
};
//D:8003F780
u16 btncheat_0x30[] = {
    L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | U_JPAD,
    L_TRIG | R_JPAD,
    R_TRIG | L_TRIG | U_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    R_TRIG | L_TRIG | D_JPAD,
    D_CBUTTONS,
    R_TRIG | L_TRIG | R_JPAD,
    R_TRIG | L_TRIG | L_JPAD
};
//D:8003F794
u16 btncheat_0x31[] = {
    D_CBUTTONS | R_TRIG,
    L_TRIG | R_JPAD,
    L_CBUTTONS | R_TRIG,
    R_TRIG | R_JPAD,
    R_TRIG | L_TRIG | R_JPAD,
    R_TRIG | L_TRIG | U_JPAD,
    L_TRIG | D_JPAD,
    R_TRIG | L_JPAD,
    L_TRIG | R_JPAD,
    L_CBUTTONS | L_TRIG
};
//D:8003F7A8
u16 btncheat_0x32[] = {
    L_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | R_JPAD,
    R_CBUTTONS,
    L_CBUTTONS,
    R_TRIG | L_JPAD,
    D_CBUTTONS | L_TRIG,
    R_TRIG | L_TRIG | L_JPAD,
    D_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | U_JPAD,
    R_CBUTTONS
};
//D:8003F7BC
u16 btncheat_0x33[] = {
    U_JPAD,
    R_JPAD,
    L_TRIG | L_JPAD,
    R_TRIG | D_JPAD,
    L_TRIG | U_JPAD,
    L_CBUTTONS | L_TRIG,
    L_TRIG | L_JPAD,
    R_CBUTTONS,
    U_CBUTTONS,
    R_TRIG | L_TRIG | D_JPAD
};
//D:8003F7D0
u16 btncheat_0x34[] = {
    R_TRIG | L_TRIG | R_JPAD,
    R_TRIG | L_TRIG | D_JPAD,
    L_TRIG | U_JPAD,
    R_TRIG | L_TRIG | D_JPAD,
    U_CBUTTONS,
    R_TRIG | U_JPAD,
    R_TRIG | L_TRIG | R_JPAD,
    L_TRIG | L_JPAD,
    D_JPAD,
    D_CBUTTONS | L_TRIG
};
//D:8003F7E4
u16 btncheat_0x35[] = {
    L_TRIG | R_JPAD,
    L_CBUTTONS | R_TRIG | L_TRIG,
    L_TRIG | D_JPAD,
    R_TRIG | L_JPAD,
    R_TRIG | D_JPAD,
    L_TRIG | R_JPAD,
    U_CBUTTONS,
    R_JPAD,
    R_TRIG | R_JPAD,
    R_TRIG | L_TRIG | U_JPAD
};
//D:8003F7F8
u16 btncheat_unlockcheats[] = {
    D_JPAD,
    L_JPAD,
    U_CBUTTONS,
    R_JPAD,
    L_TRIG | D_JPAD,
    L_TRIG | L_JPAD
};

//D:8003F804
u32 D_8003F804 = 0x8200002;
//D:8003F808
u32 D_8003F808 = 0x2000004;

/**
 * Address 0x8003F80C.
 */
struct CheatInfo g_CheatInfo[] = {
    {          CHEAT_EXTRA_MP_CHARS,  0xA, 0, 0, btncheat_extrampchars,             0, 0,  /* 0x31 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_1},
    {           CHEAT_INVINCIBILITY,  0xA, 0, 0, btncheat_invincibility,       0xB000, 0,  /* 0x06 */ CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                 CHEAT_ALLGUNS,  0xA, 0, 0, btncheat_allguns,             0xB001, 0,  /* 0x02 */ CHEAT_MASK_2},
    {                 CHEAT_MAXAMMO,  0xA, 0, 0, btncheat_maxammo,                  0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                           0x5,  0xA, 0, 0, btncheat_0x5,                      0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {CHEAT_DEACTIVATE_INVINCIBILITY,  0xA, 0, 0, btncheat_removeinvincibility,      0, 0,  /* 0x34 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER},
    {                CHEAT_LINEMODE,  0xA, 0, 0, btncheat_linemode,            0xB037, 0,  /* 0x66 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {               CHEAT_2X_HEALTH,    0, 0, 0,                0,                  0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                CHEAT_2X_ARMOR,    0, 0, 0,                0,                  0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {            CHEAT_INVISIBILITY,  0xA, 0, 0, btncheat_invisibility,        0xB004, 0,  /* 0x62 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_2},
    {           CHEAT_INFINITE_AMMO,    0, 0, 0,                0,             0xB006, 0,  /* 0x66 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                 CHEAT_DK_MODE,    0, 0, 0,                0,             0xB007, 0,  /* 0x26 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {           CHEAT_EXTRA_WEAPONS,    0, 0, 0,                0,                  0, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {               CHEAT_TINY_BOND,    0, 0, 0,                0,             0xB008, 0,  /* 0x02 */ CHEAT_MASK_2},
    {               CHEAT_PAINTBALL,    0, 0, 0,                0,             0xB038, 0,  /* 0x66 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {              CHEAT_10X_HEALTH,    0, 0, 0,                0,                  0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                  CHEAT_MAGNUM,    0, 0, 0,                0,             0xB00A, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                   CHEAT_LASER,    0, 0, 0,                0,             0xB00B, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {              CHEAT_GOLDEN_GUN,    0, 0, 0,                0,             0xB00C, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {              CHEAT_SILVER_PP7,    0, 0, 0,                0,             0xB00D, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                CHEAT_GOLD_PP7,    0, 0, 0,                0,             0xB00E, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                          0x16,  0xA, 0, 0, btncheat_0x16,                     0, 0,  /* 0x12 */ CHEAT_MASK_MULTIPLAYER},
    {             CHEAT_NO_RADAR_MP,    0, 0, 0,                0,             0xB043, 0,  /* 0x64 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER},
    {              CHEAT_TURBO_MODE,    0, 0, 0,                0,             0xB040, 0,  /* 0x66 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {               CHEAT_DEBUG_POS,    0, 0, 0,                0,                  0, 0,  /* 0x20 */ CHEAT_MASK_GLOBAL},
    {          CHEAT_FAST_ANIMATION,    0, 0, 0,                0,             0xB041, 0,  /* 0x72 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_2},
    {          CHEAT_SLOW_ANIMATION,    0, 0, 0,                0,             0xB042, 0,  /* 0x72 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_2},
    {           CHEAT_ENEMY_ROCKETS,    0, 0, 0,                0,             0xB039, 0,  /* 0x01 */ CHEAT_MASK_1},
    {      CHEAT_2X_ROCKET_LAUNCHER,    0, 0, 0,                0,             0xB03A, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {     CHEAT_2X_GRENADE_LAUNCHER,    0, 0, 0,                0,             0xB03B, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                CHEAT_2X_RCP90,    0, 0, 0,                0,             0xB03C, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {       CHEAT_2X_THROWING_KNIFE,    0, 0, 0,                0,             0xB03D, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {        CHEAT_2X_HUNTING_KNIFE,    0, 0, 0,                0,             0xB03E, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                CHEAT_2X_LASER,    0, 0, 0,                0,             0xB03F, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                          0x23,  0xA, 0, 0, btncheat_0x23,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x24,  0xA, 0, 0, btncheat_0x24,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x25,  0xA, 0, 0, btncheat_0x25,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x26,  0xA, 0, 0, btncheat_0x26,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x27,  0xA, 0, 0, btncheat_0x27,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x28,  0xA, 0, 0, btncheat_0x28,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x29,  0xA, 0, 0, btncheat_0x29,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2A,  0xA, 0, 0, btncheat_0x2A,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2B,  0xA, 0, 0, btncheat_0x2B,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2C,  0xA, 0, 0, btncheat_0x2C,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2D,  0xA, 0, 0, btncheat_0x2D,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2E,  0xA, 0, 0, btncheat_0x2E,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2F,  0xA, 0, 0, btncheat_0x2F,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x30,  0xA, 0, 0, btncheat_0x30,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x31,  0xA, 0, 0, btncheat_0x31,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x32,  0xA, 0, 0, btncheat_0x32,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x33,  0xA, 0, 0, btncheat_0x33,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x34,  0xA, 0, 0, btncheat_0x34,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x35,  0xA, 0, 0, btncheat_0x35,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {           CHEAT_UNLOCK_CHEATS,  0xA, 0, 0, btncheat_unlockcheats,             0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x37,  0xA, 0, 0, btncheat_0x37,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x38,  0xA, 0, 0, btncheat_0x38,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x39,  0xA, 0, 0, btncheat_0x39,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3A,  0xA, 0, 0, btncheat_0x3A,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3B,  0xA, 0, 0, btncheat_0x3B,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3C,  0xA, 0, 0, btncheat_0x3C,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3D,  0xA, 0, 0, btncheat_0x3D,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3E,  0xA, 0, 0, btncheat_0x3E,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3F,  0xA, 0, 0, btncheat_0x3F,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x40,  0xA, 0, 0, btncheat_0x40,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x41,  0xA, 0, 0, btncheat_0x41,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x42,  0xA, 0, 0, btncheat_0x42,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x43,  0xA, 0, 0, btncheat_0x43,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x44,  0xA, 0, 0, btncheat_0x44,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x45,  0xA, 0, 0, btncheat_0x45,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x46,  0xA, 0, 0, btncheat_0x46,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x47,  0xA, 0, 0, btncheat_0x47,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x48,  0xA, 0, 0, btncheat_0x48,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x49,  0xA, 0, 0, btncheat_0x49,                     0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {           CHEAT_UNLOCK_STAGES,  0xA, 0, 0, btncheat_unlockstages,             0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {0}
};



// rodata

// forward declarations

s32 cheatButtonCountBitsSet(u16 param_1);
void cheatButtonActivateRelated(void);
void cheatButtonHandleCheatsTurnedOn(CHEAT_ID cheat);
void cheatButtonHandleCheatsTurnedOff(s32 cheat_id);
s32 cheatCheckIfMPCheat(s32 cheat_id);
void cheatButtonSetDkMode(s32 cheat_id);
void cheatButtonHandleCheatsTurnedOff(s32 cheat);

// end forward declarations





s32 cheatButtonCountBitsSet(u16 param_1)
{
    s32 count;

    for (count = 0; (u32)param_1 != 0; param_1 >>= 1)
    {
        if (param_1 & 1)
        {
            count++;
        }
    }

    return count;
}





/**
 * Address 0x7F09177C.
 */
void cheatButtonActivateRelated(void)
{
    struct CheatInfo *info = &g_CheatInfo[0];
    s32 bitmask;
    s32 id_index;
    s32 find_index;
    s32 not_done = 0;
    
    if (lvlGetCurrentStageToLoad() == LEVELID_TITLE)
    {
        bitmask = CHEAT_MASK_1;
    }
    else
    {
        bitmask = (getPlayerCount() == 1) ? CHEAT_MASK_2 : CHEAT_MASK_MULTIPLAYER;
    }

    for (; info->cheat_id != 0 && not_done == 0; info++)
    {
        if (info->count_of_something > 0)
        {
            if ((g_CurrentPlayer->can_display_cheat_text >= info->count_of_something) && ((info->maskfield & bitmask) != 0))
            {
                id_index = ((g_CurrentPlayer->something_with_cheat_text - info->count_of_something) + CHEAT_20) % CHEAT_20;

                find_index=0;
                for (; find_index < info->count_of_something; find_index++)
                {
                    if (g_CurrentPlayer->cheat_display_text_related[id_index] == info->cheatbuttons[find_index])
                    {
                        id_index = (s32) (id_index + 1) % CHEAT_20;
                        continue;
                    }

                    break;
                }

                if (find_index == info->count_of_something)
                {
                    g_CurrentPlayer->can_display_cheat_text = 0;

                    if ((cheatCheckIfOn((s32) info->cheat_id) == 0) || ((info->maskfield & CHEAT_MASK_16) != 0))
                    {
                        cheatButtonHandleCheatsTurnedOn(info->cheat_id);
                    }
                    else
                    {
                        cheatButtonHandleCheatsTurnedOff(info->cheat_id);
                    }
                }
            }
        }
    }
}





#ifdef NONMATCHING
/**
 * Address 0x7F09193C.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * notes: the u16/bit operators are not playing nicely, just a few misordered instructions there.
 */
void cheat_buttons_mp_related(void)
{
    u16 jgb;
    u16 jgbptf;
    u16 jgb_trig;

    jgb = joyGetButtons(get_cur_playernum(), ANY_BUTTON);
    jgbptf = joyGetButtonsPressedThisFrame(get_cur_playernum(), ANY_BUTTON);
    jgb_trig = (jgb & (L_TRIG | R_TRIG));
    jgbptf &= ~(jgb_trig & ANY_BUTTON);
    jgb &= ~(jgb & (L_TRIG | R_TRIG));

    if (jgbptf != 0)
    {
        if ((cheatButtonCountBitsSet(jgbptf) == 1) && ((cheatButtonCountBitsSet(jgb) == 1)))
        {
            g_CurrentPlayer->cheat_display_text_related[g_CurrentPlayer->something_with_cheat_text] = jgbptf | jgb_trig;
            g_CurrentPlayer->something_with_cheat_text = (u8) ((g_CurrentPlayer->something_with_cheat_text + 1) % CHEAT_20);

            if ((s32) g_CurrentPlayer->can_display_cheat_text < CHEAT_20)
            {
                g_CurrentPlayer->can_display_cheat_text += 1;
            }
        }
        else
        {
            g_CurrentPlayer->can_display_cheat_text = 0;
        }
    }

    cheatButtonActivateRelated();
}
#else

#if defined(VERSION_US) || defined(VERSION_JP)
GLOBAL_ASM(
.text
glabel cheat_buttons_mp_related
/* 0C646C 7F09193C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C6470 7F091940 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6474 7F091944 0FC26C54 */  jal   get_cur_playernum
/* 0C6478 7F091948 00000000 */   nop
/* 0C647C 7F09194C 00022600 */  sll   $a0, $v0, 0x18
/* 0C6480 7F091950 00047603 */  sra   $t6, $a0, 0x18
/* 0C6484 7F091954 01C02025 */  move  $a0, $t6
/* 0C6488 7F091958 0C0030C3 */  jal   joyGetButtons
/* 0C648C 7F09195C 3405FFFF */   li    $a1, 65535
/* 0C6490 7F091960 0FC26C54 */  jal   get_cur_playernum
/* 0C6494 7F091964 A7A20026 */   sh    $v0, 0x26($sp)
/* 0C6498 7F091968 00022600 */  sll   $a0, $v0, 0x18
/* 0C649C 7F09196C 00047E03 */  sra   $t7, $a0, 0x18
/* 0C64A0 7F091970 01E02025 */  move  $a0, $t7
/* 0C64A4 7F091974 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0C64A8 7F091978 3405FFFF */   li    $a1, 65535
/* 0C64AC 7F09197C 97A30026 */  lhu   $v1, 0x26($sp)
/* 0C64B0 7F091980 30780030 */  andi  $t8, $v1, 0x30
/* 0C64B4 7F091984 3306FFFF */  andi  $a2, $t8, 0xffff
/* 0C64B8 7F091988 00C04827 */  not   $t1, $a2
/* 0C64BC 7F09198C 0300C827 */  not   $t9, $t8
/* 0C64C0 7F091990 00492824 */  and   $a1, $v0, $t1
/* 0C64C4 7F091994 30AAFFFF */  andi  $t2, $a1, 0xffff
/* 0C64C8 7F091998 00794024 */  and   $t0, $v1, $t9
/* 0C64CC 7F09199C A7A80026 */  sh    $t0, 0x26($sp)
/* 0C64D0 7F0919A0 11400028 */  beqz  $t2, .L7F091A44
/* 0C64D4 7F0919A4 A7A50024 */   sh    $a1, 0x24($sp)
/* 0C64D8 7F0919A8 30A4FFFF */  andi  $a0, $a1, 0xffff
/* 0C64DC 7F0919AC 0FC245D0 */  jal   cheatButtonCountBitsSet
/* 0C64E0 7F0919B0 AFA60018 */   sw    $a2, 0x18($sp)
/* 0C64E4 7F0919B4 24010001 */  li    $at, 1
/* 0C64E8 7F0919B8 1441001E */  bne   $v0, $at, .L7F091A34
/* 0C64EC 7F0919BC 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C64F0 7F0919C0 97A40026 */  lhu   $a0, 0x26($sp)
/* 0C64F4 7F0919C4 0FC245D0 */  jal   cheatButtonCountBitsSet
/* 0C64F8 7F0919C8 AFA70018 */   sw    $a3, 0x18($sp)
/* 0C64FC 7F0919CC 24010001 */  li    $at, 1
/* 0C6500 7F0919D0 14410018 */  bne   $v0, $at, .L7F091A34
/* 0C6504 7F0919D4 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C6508 7F0919D8 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0C650C 7F0919DC 2484A0B0 */  addiu $a0, %lo(g_CurrentPlayer) # addiu $a0, $a0, -0x5f50
/* 0C6510 7F0919E0 8C820000 */  lw    $v0, ($a0)
/* 0C6514 7F0919E4 97AB0024 */  lhu   $t3, 0x24($sp)
/* 0C6518 7F0919E8 24010014 */  li    $at, 20
/* 0C651C 7F0919EC 904D12B4 */  lbu   $t5, 0x12b4($v0)
/* 0C6520 7F0919F0 01676025 */  or    $t4, $t3, $a3
/* 0C6524 7F0919F4 000D7040 */  sll   $t6, $t5, 1
/* 0C6528 7F0919F8 004E7821 */  addu  $t7, $v0, $t6
/* 0C652C 7F0919FC A5EC128C */  sh    $t4, 0x128c($t7)
/* 0C6530 7F091A00 8C820000 */  lw    $v0, ($a0)
/* 0C6534 7F091A04 905812B4 */  lbu   $t8, 0x12b4($v0)
/* 0C6538 7F091A08 27190001 */  addiu $t9, $t8, 1
/* 0C653C 7F091A0C 0321001A */  div   $zero, $t9, $at
/* 0C6540 7F091A10 00004010 */  mfhi  $t0
/* 0C6544 7F091A14 A04812B4 */  sb    $t0, 0x12b4($v0)
/* 0C6548 7F091A18 8C820000 */  lw    $v0, ($a0)
/* 0C654C 7F091A1C 904312B5 */  lbu   $v1, 0x12b5($v0)
/* 0C6550 7F091A20 28610014 */  slti  $at, $v1, 0x14
/* 0C6554 7F091A24 10200007 */  beqz  $at, .L7F091A44
/* 0C6558 7F091A28 24690001 */   addiu $t1, $v1, 1
/* 0C655C 7F091A2C 10000005 */  b     .L7F091A44
/* 0C6560 7F091A30 A04912B5 */   sb    $t1, 0x12b5($v0)
.L7F091A34:
/* 0C6564 7F091A34 3C048008 */  lui   $a0, %hi(g_CurrentPlayer)
/* 0C6568 7F091A38 2484A0B0 */  addiu $a0, %lo(g_CurrentPlayer) # addiu $a0, $a0, -0x5f50
/* 0C656C 7F091A3C 8C8A0000 */  lw    $t2, ($a0)
/* 0C6570 7F091A40 A14012B5 */  sb    $zero, 0x12b5($t2)
.L7F091A44:
/* 0C6574 7F091A44 0FC245DF */  jal   cheatButtonActivateRelated
/* 0C6578 7F091A48 00000000 */   nop
/* 0C657C 7F091A4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C6580 7F091A50 27BD0028 */  addiu $sp, $sp, 0x28
/* 0C6584 7F091A54 03E00008 */  jr    $ra
/* 0C6588 7F091A58 00000000 */   nop
)
#endif

#if defined(VERSION_EU)
GLOBAL_ASM(
.text
glabel cheat_buttons_mp_related
/* 0C37AC 7F090DBC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C37B0 7F090DC0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C37B4 7F090DC4 0FC269A4 */  jal   get_cur_playernum
/* 0C37B8 7F090DC8 00000000 */   nop   
/* 0C37BC 7F090DCC 00022600 */  sll   $a0, $v0, 0x18
/* 0C37C0 7F090DD0 00047603 */  sra   $t6, $a0, 0x18
/* 0C37C4 7F090DD4 01C02025 */  move  $a0, $t6
/* 0C37C8 7F090DD8 0C002C20 */  jal   joyGetButtons
/* 0C37CC 7F090DDC 3405FFFF */   li    $a1, 65535
/* 0C37D0 7F090DE0 0FC269A4 */  jal   get_cur_playernum
/* 0C37D4 7F090DE4 A7A20026 */   sh    $v0, 0x26($sp)
/* 0C37D8 7F090DE8 00022600 */  sll   $a0, $v0, 0x18
/* 0C37DC 7F090DEC 00047E03 */  sra   $t7, $a0, 0x18
/* 0C37E0 7F090DF0 01E02025 */  move  $a0, $t7
/* 0C37E4 7F090DF4 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0C37E8 7F090DF8 3405FFFF */   li    $a1, 65535
/* 0C37EC 7F090DFC 97A30026 */  lhu   $v1, 0x26($sp)
/* 0C37F0 7F090E00 30780030 */  andi  $t8, $v1, 0x30
/* 0C37F4 7F090E04 3306FFFF */  andi  $a2, $t8, 0xffff
/* 0C37F8 7F090E08 00C04827 */  not   $t1, $a2
/* 0C37FC 7F090E0C 0300C827 */  not   $t9, $t8
/* 0C3800 7F090E10 00492824 */  and   $a1, $v0, $t1
/* 0C3804 7F090E14 30AAFFFF */  andi  $t2, $a1, 0xffff
/* 0C3808 7F090E18 00794024 */  and   $t0, $v1, $t9
/* 0C380C 7F090E1C A7A80026 */  sh    $t0, 0x26($sp)
/* 0C3810 7F090E20 11400028 */  beqz  $t2, .L7F090EC4
/* 0C3814 7F090E24 A7A50024 */   sh    $a1, 0x24($sp)
/* 0C3818 7F090E28 30A4FFFF */  andi  $a0, $a1, 0xffff
/* 0C381C 7F090E2C 0FC242F0 */  jal   cheatButtonCountBitsSet
/* 0C3820 7F090E30 AFA60018 */   sw    $a2, 0x18($sp)
/* 0C3824 7F090E34 24010001 */  li    $at, 1
/* 0C3828 7F090E38 1441001E */  bne   $v0, $at, .L7F090EB4
/* 0C382C 7F090E3C 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C3830 7F090E40 97A40026 */  lhu   $a0, 0x26($sp)
/* 0C3834 7F090E44 0FC242F0 */  jal   cheatButtonCountBitsSet
/* 0C3838 7F090E48 AFA70018 */   sw    $a3, 0x18($sp)
/* 0C383C 7F090E4C 24010001 */  li    $at, 1
/* 0C3840 7F090E50 14410018 */  bne   $v0, $at, .L7F090EB4
/* 0C3844 7F090E54 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C3848 7F090E58 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0C384C 7F090E5C 24848BC0 */  addiu $a0, %lo(g_CurrentPlayer) # addiu $a0, $a0, -0x7440
/* 0C3850 7F090E60 8C820000 */  lw    $v0, ($a0)
/* 0C3854 7F090E64 97AB0024 */  lhu   $t3, 0x24($sp)
/* 0C3858 7F090E68 24010014 */  li    $at, 20
/* 0C385C 7F090E6C 904D12AC */  lbu   $t5, 0x12ac($v0)
/* 0C3860 7F090E70 01676025 */  or    $t4, $t3, $a3
/* 0C3864 7F090E74 000D7040 */  sll   $t6, $t5, 1
/* 0C3868 7F090E78 004E7821 */  addu  $t7, $v0, $t6
/* 0C386C 7F090E7C A5EC1284 */  sh    $t4, 0x1284($t7)
/* 0C3870 7F090E80 8C820000 */  lw    $v0, ($a0)
/* 0C3874 7F090E84 905812AC */  lbu   $t8, 0x12ac($v0)
/* 0C3878 7F090E88 27190001 */  addiu $t9, $t8, 1
/* 0C387C 7F090E8C 0321001A */  div   $zero, $t9, $at
/* 0C3880 7F090E90 00004010 */  mfhi  $t0
/* 0C3884 7F090E94 A04812AC */  sb    $t0, 0x12ac($v0)
/* 0C3888 7F090E98 8C820000 */  lw    $v0, ($a0)
/* 0C388C 7F090E9C 904312AD */  lbu   $v1, 0x12ad($v0)
/* 0C3890 7F090EA0 28610014 */  slti  $at, $v1, 0x14
/* 0C3894 7F090EA4 10200007 */  beqz  $at, .L7F090EC4
/* 0C3898 7F090EA8 24690001 */   addiu $t1, $v1, 1
/* 0C389C 7F090EAC 10000005 */  b     .L7F090EC4
/* 0C38A0 7F090EB0 A04912AD */   sb    $t1, 0x12ad($v0)
.L7F090EB4:
/* 0C38A4 7F090EB4 3C048007 */  lui   $a0, %hi(g_CurrentPlayer) # $a0, 0x8007
/* 0C38A8 7F090EB8 24848BC0 */  addiu $a0, %lo(g_CurrentPlayer) # addiu $a0, $a0, -0x7440
/* 0C38AC 7F090EBC 8C8A0000 */  lw    $t2, ($a0)
/* 0C38B0 7F090EC0 A14012AD */  sb    $zero, 0x12ad($t2)
.L7F090EC4:
/* 0C38B4 7F090EC4 0FC242FF */  jal   cheatButtonActivateRelated
/* 0C38B8 7F090EC8 00000000 */   nop   
/* 0C38BC 7F090ECC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C38C0 7F090ED0 27BD0028 */  addiu $sp, $sp, 0x28
/* 0C38C4 7F090ED4 03E00008 */  jr    $ra
/* 0C38C8 7F090ED8 00000000 */   nop   
)
#endif
#endif






u32 cheatIsEnemyRockets(u32 cheatindex)
{
    if (cheatindex == CHEAT_ENEMY_ROCKETS) {
        return 1;
    }
    return 0;
}






/**
 * @param cheat_id: 1 based index.
 * 
 * Address 0x7F091A78.
 */
s32 cheatCheckIfMPCheat(s32 cheat_id)
{
    if ((g_CheatInfo[cheat_id - 1].maskfield & CHEAT_MASK_MULTIPLAYER) == CHEAT_MASK_MULTIPLAYER)
    {
        return 1;
    }

    return 0;
}




/**
 * Address 0x7F091AAC.
 */
void cheatButtonTurnOnCheatForPlayers(u32 cheatindex)
{
    u32 cheat_mask;
    s32 starting_player_number;
    s32 numplayers;
    s32 i;

    cheat_mask = g_CheatInfo[cheatindex - 1].maskfield;
    starting_player_number = get_cur_playernum();
    numplayers = getPlayerCount();

    if (numplayers == 1)
    {
        cheatButtonHandleCheatsTurnedOn(cheatindex);
    }
    else
    {
        if (cheat_mask & CHEAT_MASK_MULTIPLAYER)
        {
            if (cheat_mask & CHEAT_MASK_GLOBAL)
            {
                cheatButtonHandleCheatsTurnedOn(cheatindex);
            }
            else
            {
                for(i=0; i<numplayers; i++)
                {
                    set_cur_player(i);
                    cheatButtonHandleCheatsTurnedOn(cheatindex);
                }

                set_cur_player(starting_player_number);
            }
        }
    }

    return;
}


#if defined(VERSION_US) || defined(VERSION_JP)
/**
 * Address 0x7F091B64 (VERSION_US)
 * Address 0x7F092644 (VERSION_JP)
 */
void cheatButtonHandleCheatsTurnedOn(CHEAT_ID cheat_id)
{
    s32 mask;
    s32 current_player_number;
    s32 player_count;
    
    mask = g_CheatInfo[cheat_id - 1].maskfield;
    current_player_number = get_cur_playernum();
    player_count = getPlayerCount();

    if ((mask & CHEAT_MASK_16) == 0)
    {
        if ((mask & CHEAT_MASK_GLOBAL) == 0)
        {
            g_CheatPlayerTextRelated[cheat_id] |= (1 << current_player_number);
        }
        else
        {
            g_CheatPlayerTextRelated[cheat_id] = (1 << player_count) - 1;
        }
    }

    switch (cheat_id)
    {
        case CHEAT_EXTRA_MP_CHARS:
            unlock_all_mp_chars();
            return;

        case CHEAT_INVINCIBILITY:
            if (get_bondata_invincible_flag() == 0)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB00F));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB00F));
#endif
                set_bondata_invincible_flag(1);
                return;
            }
            return;

        case CHEAT_ALLGUNS:
            if (get_BONDdata_allguns_flag() == 0)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB010));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB010));
#endif
                set_BONDdata_allguns_flag(1);
                return;
            }
            return;

        case CHEAT_MAXAMMO:
#if defined(VERSION_JP) || defined(VERSION_EU)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB011));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB011));
#endif
            set_max_ammo_for_cur_player();
            return;

        case CHEAT_DEACTIVATE_INVINCIBILITY:
            {
                s32 i;
                s32 flag=0;
                if (player_count >= 2)
                {
                    i=0;
                    for (; i<player_count; i++)
                    {
                        if (i != current_player_number)
                        {
                            set_cur_player(i);
                            if (get_bondata_invincible_flag() != 0)
                            {
                                set_bondata_invincible_flag(0);
                                flag = 1;
                            }
                        }

                        set_cur_player(current_player_number);
                    }

                    if (flag != 0)
                    {
                        sndPlaySfx(g_musicSfxBufferPtr, 0x9F, 0);
                        return;
                    }

                    return;
                }
            }
            return;

        case CHEAT_LINEMODE:
            set_debug_VisCVG_flag(1);
            return;

        case CHEAT_2X_HEALTH:
            if ((g_CurrentPlayer->actual_health == 1.0f) || (g_CurrentPlayer->bondhealth < 1.0f))
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB012));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB012));
#endif
                g_CurrentPlayer->bondhealth = 1.0f;
                g_CurrentPlayer->actual_health = 2.0f;
            }
            return;

        case CHEAT_2X_ARMOR:
            if ((g_CurrentPlayer->actual_armor == 1.0f) || (g_CurrentPlayer->bondarmour < 1.0f))
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB013));
                if(1)
                {
                    // removed
                }
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB013));
#endif
                g_CurrentPlayer->bondarmour = 1.0f;
                g_CurrentPlayer->actual_armor = 2.0f;
            }
            return;

        case CHEAT_INVISIBILITY:
            if (bondviewGetVisibleToGuardsFlag() != 0)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB014));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB014));
#endif
                bondviewSetVisibleToGuardsFlag(0);
                return;
            }
            return;

        case CHEAT_INFINITE_AMMO:
#if defined(VERSION_JP) || defined(VERSION_EU)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB016));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB016));
#endif
            /**
            * Note: the lvlRender in lvl.c checks if infinite ammo is on then calls set_max_ammo_for_cur_player
            */
            return;

        case CHEAT_DK_MODE:
#if defined(VERSION_JP) || defined(VERSION_EU)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB017));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB017));
#endif
            cheatButtonSetDkMode(1);
            return;

        case CHEAT_EXTRA_WEAPONS:
            if (player_count == 1)
            {
                s32 vvv;

                vvv = add_item_to_inventory(ITEM_RUGER);
                vvv += add_item_to_inventory(ITEM_LASER);
                vvv += add_item_to_inventory(ITEM_GOLDENGUN);
                vvv += add_item_to_inventory(ITEM_SILVERWPPK);
                vvv += add_item_to_inventory(ITEM_GOLDWPPK);

                give_cur_player_ammo(AMMO_MAGNUM, get_max_ammo_for_type(AMMO_MAGNUM));
                give_cur_player_ammo(AMMO_GGUN, get_max_ammo_for_type(AMMO_GGUN));
                give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));

                if (vvv > 0)
                {
#if defined(VERSION_JP) || defined(VERSION_EU)
                    jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB018));
#else
                    display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB018));
#endif
                }
                return;
            }
            return;

        case CHEAT_TINY_BOND:
            if ((player_count == 1) && (g_playerPerm->player_perspective_height == 1.0f))
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB019));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB019));
#endif
                g_playerPerm->player_perspective_height = 0.5f;

                if (g_CurrentPlayer->ptr_char_objectinstance != NULL)
                {
                    set_obj_instance_controller_scale((struct Model *)g_CurrentPlayer->ptr_char_objectinstance, ((struct Model *)g_CurrentPlayer->ptr_char_objectinstance)->scale * 0.5f);
                }
                return;
            }
            return;

        case CHEAT_PAINTBALL:
#if defined(VERSION_JP) || defined(VERSION_EU)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01A));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01A));
#endif
            return;

        case CHEAT_10X_HEALTH:
            if ((g_CurrentPlayer->actual_health == 1.0f) || (g_CurrentPlayer->bondhealth < 1.0f))
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01B));
                if(1)
                {
                    // removed
                }
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01B));
#endif
                g_CurrentPlayer->bondhealth = 1.0f;
                g_CurrentPlayer->actual_health = 10.0f;
                return;
            }
            return;

        case CHEAT_MAGNUM:
            if (player_count == 1)
            {
                add_item_to_inventory(ITEM_RUGER);
                give_cur_player_ammo(AMMO_MAGNUM, get_max_ammo_for_type(AMMO_MAGNUM));
                return;
            }
            return;

        case CHEAT_LASER:
            if (player_count == 1)
            {
                add_item_to_inventory(ITEM_LASER);
                return;
            }
            return;

        case CHEAT_GOLDEN_GUN:
            if (player_count == 1)
            {
                add_item_to_inventory(ITEM_GOLDENGUN);
                give_cur_player_ammo(AMMO_GGUN, get_max_ammo_for_type(AMMO_GGUN));
                return;
            }
            return;

        case CHEAT_SILVER_PP7:
            if (player_count == 1)
            {
                add_item_to_inventory(ITEM_SILVERWPPK);
                give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
                return;
            }
            return;

        case CHEAT_GOLD_PP7:
            if (player_count == 1)
            {
                add_item_to_inventory(ITEM_GOLDWPPK);
                give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
                return;
            }
            return;

        case 0x16: /* unknown */
            currentPlayerStartChrFade(300.0f, 0.05f);
            return;

        case CHEAT_TURBO_MODE:
            if (get_debug_fast_bond_flag() == 0)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01D));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01D));
#endif
                set_debug_fast_bond_flag(1);
                return;
            }
            return;

        case CHEAT_DEBUG_POS:
            if (get_debug_testingmanpos_flag() == 0)
            {
                set_debug_testingmanpos_flag(1);
                return;
            }
            return;

        case CHEAT_FAST_ANIMATION:
            if (get_animation_rate() < 4.0f)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB034));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB034));
#endif
                animation_speed_related(4.0f);
                return;
            }
            return;

        case CHEAT_SLOW_ANIMATION:
            if (get_animation_rate() > 0.25f)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB032));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB032));
#endif
                animation_speed_related(0.25);
                return;
            }
            return;

        case CHEAT_2X_ROCKET_LAUNCHER:
            if (player_count == 1)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                add_item_to_inventory(ITEM_ROCKETLAUNCH);
#endif
                add_doubles_item_to_inventory(ITEM_ROCKETLAUNCH, ITEM_ROCKETLAUNCH);
                give_cur_player_ammo(AMMO_ROCKETS, get_max_ammo_for_type(AMMO_ROCKETS));
                return;
            }
            return;

        case CHEAT_2X_GRENADE_LAUNCHER:
            if (player_count == 1)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                add_item_to_inventory(ITEM_GRENADELAUNCH);
#endif
                add_doubles_item_to_inventory(ITEM_GRENADELAUNCH, ITEM_GRENADELAUNCH);
                give_cur_player_ammo(AMMO_GRENADEROUND, get_max_ammo_for_type(AMMO_GRENADEROUND));
                return;
            }
            return;

        case CHEAT_2X_RCP90:
            if (player_count == 1)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                add_item_to_inventory(ITEM_FNP90);
#endif
                add_doubles_item_to_inventory(ITEM_FNP90, ITEM_FNP90);
                give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
                return;
            }
            return;

        case CHEAT_2X_THROWING_KNIFE:
            if (player_count == 1)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                add_item_to_inventory(ITEM_THROWKNIFE);
#endif
                add_doubles_item_to_inventory(ITEM_THROWKNIFE, ITEM_THROWKNIFE);
                give_cur_player_ammo(AMMO_KNIFE, get_max_ammo_for_type(AMMO_KNIFE));
                return;
            }
            return;

        case CHEAT_2X_HUNTING_KNIFE:
            if (player_count == 1)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                if (j_text_trigger != 0)
                {
                    add_item_to_inventory(ITEM_ROCKETLAUNCH);
                    add_item_to_inventory(ITEM_SNIPERRIFLE);
                    add_doubles_item_to_inventory(ITEM_SNIPERRIFLE, ITEM_ROCKETLAUNCH);
                    give_cur_player_ammo(AMMO_ROCKETS, get_max_ammo_for_type(AMMO_ROCKETS));
                    give_cur_player_ammo(ITEM_THROWKNIFE, get_max_ammo_for_type(ITEM_THROWKNIFE));
                    return;
                }
                add_item_to_inventory(ITEM_KNIFE);
#endif
                add_doubles_item_to_inventory(ITEM_KNIFE, ITEM_KNIFE);
                return;
            }
            return;

        case CHEAT_2X_LASER:
            if (player_count == 1)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                add_item_to_inventory(ITEM_LASER);
#endif
                add_doubles_item_to_inventory(ITEM_LASER, ITEM_LASER);
                return;
            }
            return;

        case 0x23: /* fall through */
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
            {
                s32 val = cheat_id - 0x23;
                if ((selected_folder_num >= 0) && (selected_folder_num < 4))
                {
                    sub_GAME_7F01E760(selected_folder_num, val);
                    sndPlaySfx(g_musicSfxBufferPtr, 0x9F, 0);
                    return;
                }
            }
            return;
            
        case 0x37:  /* fall through */
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4A:
            {
                s32 max = cheat_id - 0x37;
                s32 i;
                s32 unlock_count;
                if (selected_folder_num >= 0 && selected_folder_num < 4)
                {
                    unlock_count = 0; // move v1, zero
                    i = 0; // move a1, zero
                    for (; i < max; i++)
                    {
                        if (fileIsStageUnlockedAtDifficulty(selected_folder_num, i, 0) == 3)
                        {
                            unlock_count++;
                        }
                    }

                    if (max - 1 == (unlock_count))
                    {
                        fileUnlockStageInFolderAtDifficulty(selected_folder_num, max - 1, 0, 0x5F5E0FF);
                        sndPlaySfx(g_musicSfxBufferPtr, 0x9F, 0);
                    }
                }
            }
            return;     
        
        default:
            return;   
    }
}
#endif
#if defined(VERSION_EU)
GLOBAL_ASM(
.late_rodata
/*D:800572B0*/
glabel jpt_cheats_cheat
.word cheats_cheat_extra_mp_chars
.word cheats_cheat_invincibility
.word cheats_cheat_allguns
.word cheats_cheat_max_ammo
.word cheats_debug_return_saved_ra
.word cheats_cheat_deactivate_invincibility
.word cheats_cheat_linemode
.word CHEAT_2X_HEALTH
.word CHEAT_2X_ARMOR
.word CHEAT_INVISIBILITY
.word cheats_cheat_infinite_ammo
.word cheats_cheat_dk_mode
.word cheats_cheat_extra_weapons
.word cheats_cheat_tiny_bond
.word cheats_cheat_paintball
.word cheats_cheat_10x_health
.word cheats_cheat_magnum
.word cheats_cheat_laser
.word cheats_cheat_goldengun
.word cheats_cheat_silverpp7
.word cheats_cheat_goldpp7
.word CHEAT_INVISIBILITY_mp
.word cheats_debug_return_saved_ra
.word CHEAT_TURBO_MODE
.word CHEAT_DEBUG_POS
.word CHEAT_FAST_ANIMATION
.word CHEAT_SLOW_ANIMATION
.word cheats_debug_return_saved_ra
.word CHEAT_2X_ROCKET_LAUNCHER
.word CHEAT_2X_GRENADE_LAUNCHER
.word CHEAT_2X_RCP90
.word CHEAT_2X_THROWING_KNIFE
.word CHEAT_2X_HUNTING_KNIFE
.word CHEAT_2X_LASER
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel

/*800573D8*/
glabel finalamount
.word 0x3d4ccccd /*0.050000001*/

.text
glabel cheatButtonHandleCheatsTurnedOn
/* 0C39D4 7F090FE4 00047100 */  sll   $t6, $a0, 4
/* 0C39D8 7F090FE8 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C39DC 7F090FEC 01EE7821 */  addu  $t7, $t7, $t6
/* 0C39E0 7F090FF0 8DEF9458 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C39E4 7F090FF4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0C39E8 7F090FF8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C39EC 7F090FFC AFA40040 */  sw    $a0, 0x40($sp)
/* 0C39F0 7F091000 0FC269A4 */  jal   get_cur_playernum
/* 0C39F4 7F091004 AFAF003C */   sw    $t7, 0x3c($sp)
/* 0C39F8 7F091008 0FC26669 */  jal   getPlayerCount
/* 0C39FC 7F09100C AFA20038 */   sw    $v0, 0x38($sp)
/* 0C3A00 7F091010 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C3A04 7F091014 8FA60040 */  lw    $a2, 0x40($sp)
/* 0C3A08 7F091018 AFA20034 */  sw    $v0, 0x34($sp)
/* 0C3A0C 7F09101C 30780010 */  andi  $t8, $v1, 0x10
/* 0C3A10 7F091020 17000012 */  bnez  $t8, .L7F09106C
/* 0C3A14 7F091024 30790020 */   andi  $t9, $v1, 0x20
/* 0C3A18 7F091028 1720000A */  bnez  $t9, .L7F091054
/* 0C3A1C 7F09102C 8FA50038 */   lw    $a1, 0x38($sp)
/* 0C3A20 7F091030 3C098007 */  lui   $t1, %hi(g_CheatPlayerTextRelated) # $t1, 0x8007
/* 0C3A24 7F091034 25298940 */  addiu $t1, %lo(g_CheatPlayerTextRelated) # addiu $t1, $t1, -0x76c0
/* 0C3A28 7F091038 00C91821 */  addu  $v1, $a2, $t1
/* 0C3A2C 7F09103C 906A0000 */  lbu   $t2, ($v1)
/* 0C3A30 7F091040 240B0001 */  li    $t3, 1
/* 0C3A34 7F091044 00AB6004 */  sllv  $t4, $t3, $a1
/* 0C3A38 7F091048 014C6825 */  or    $t5, $t2, $t4
/* 0C3A3C 7F09104C 10000007 */  b     .L7F09106C
/* 0C3A40 7F091050 A06D0000 */   sb    $t5, ($v1)
.L7F091054:
/* 0C3A44 7F091054 240E0001 */  li    $t6, 1
/* 0C3A48 7F091058 004E7804 */  sllv  $t7, $t6, $v0
/* 0C3A4C 7F09105C 3C018007 */  lui   $at, %hi(g_CheatPlayerTextRelated)
/* 0C3A50 7F091060 00260821 */  addu  $at, $at, $a2
/* 0C3A54 7F091064 25F8FFFF */  addiu $t8, $t7, -1
/* 0C3A58 7F091068 A0388940 */  sb    $t8, %lo(g_CheatPlayerTextRelated)($at)
.L7F09106C:
/* 0C3A5C 7F09106C 24D9FFFF */  addiu $t9, $a2, -1
/* 0C3A60 7F091070 2F21004A */  sltiu $at, $t9, 0x4a
/* 0C3A64 7F091074 10200234 */  beqz  $at, .L7F091948
/* 0C3A68 7F091078 0019C880 */   sll   $t9, $t9, 2
/* 0C3A6C 7F09107C 3C018005 */  lui   $at, %hi(jpt_cheats_cheat)
/* 0C3A70 7F091080 00390821 */  addu  $at, $at, $t9
/* 0C3A74 7F091084 8C39C970 */  lw    $t9, %lo(jpt_cheats_cheat)($at)
/* 0C3A78 7F091088 03200008 */  jr    $t9
/* 0C3A7C 7F09108C 00000000 */   nop   
cheats_cheat_extra_mp_chars:
/* 0C3A80 7F091090 0FC0405C */  jal   unlock_all_mp_chars
/* 0C3A84 7F091094 00000000 */   nop   
/* 0C3A88 7F091098 1000022C */  b     .L7F09194C
/* 0C3A8C 7F09109C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invincibility:
/* 0C3A90 7F0910A0 0FC22849 */  jal   get_bondata_invincible_flag
/* 0C3A94 7F0910A4 00000000 */   nop   
/* 0C3A98 7F0910A8 54400228 */  bnezl $v0, .L7F09194C
/* 0C3A9C 7F0910AC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3AA0 7F0910B0 0FC304AE */  jal   get_textptr_for_textID
/* 0C3AA4 7F0910B4 3404B00F */   li    $a0, 45071
/* 0C3AA8 7F0910B8 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3AAC 7F0910BC 00402025 */   move  $a0, $v0
/* 0C3AB0 7F0910C0 0FC22845 */  jal   set_bondata_invincible_flag
/* 0C3AB4 7F0910C4 24040001 */   li    $a0, 1
/* 0C3AB8 7F0910C8 10000220 */  b     .L7F09194C
/* 0C3ABC 7F0910CC 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_allguns:
/* 0C3AC0 7F0910D0 0FC2316F */  jal   get_BONDdata_allguns_flag
/* 0C3AC4 7F0910D4 00000000 */   nop   
/* 0C3AC8 7F0910D8 5440021C */  bnezl $v0, .L7F09194C
/* 0C3ACC 7F0910DC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3AD0 7F0910E0 0FC304AE */  jal   get_textptr_for_textID
/* 0C3AD4 7F0910E4 3404B010 */   li    $a0, 45072
/* 0C3AD8 7F0910E8 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3ADC 7F0910EC 00402025 */   move  $a0, $v0
/* 0C3AE0 7F0910F0 0FC2316B */  jal   set_BONDdata_allguns_flag
/* 0C3AE4 7F0910F4 24040001 */   li    $a0, 1
/* 0C3AE8 7F0910F8 10000214 */  b     .L7F09194C
/* 0C3AEC 7F0910FC 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_max_ammo:
/* 0C3AF0 7F091100 0FC304AE */  jal   get_textptr_for_textID
/* 0C3AF4 7F091104 3404B011 */   li    $a0, 45073
/* 0C3AF8 7F091108 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3AFC 7F09110C 00402025 */   move  $a0, $v0
/* 0C3B00 7F091110 0FC1A6A1 */  jal   set_max_ammo_for_cur_player
/* 0C3B04 7F091114 00000000 */   nop   
/* 0C3B08 7F091118 1000020C */  b     .L7F09194C
/* 0C3B0C 7F09111C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_deactivate_invincibility:
/* 0C3B10 7F091120 28410002 */  slti  $at, $v0, 2
/* 0C3B14 7F091124 14200208 */  bnez  $at, .L7F091948
/* 0C3B18 7F091128 AFA0002C */   sw    $zero, 0x2c($sp)
/* 0C3B1C 7F09112C 18400015 */  blez  $v0, .L7F091184
/* 0C3B20 7F091130 AFA00030 */   sw    $zero, 0x30($sp)
.L7F091134:
/* 0C3B24 7F091134 8FA50038 */  lw    $a1, 0x38($sp)
/* 0C3B28 7F091138 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C3B2C 7F09113C 1125000A */  beq   $t1, $a1, .L7F091168
/* 0C3B30 7F091140 00000000 */   nop   
/* 0C3B34 7F091144 0FC26993 */  jal   set_cur_player
/* 0C3B38 7F091148 01202025 */   move  $a0, $t1
/* 0C3B3C 7F09114C 0FC22849 */  jal   get_bondata_invincible_flag
/* 0C3B40 7F091150 00000000 */   nop   
/* 0C3B44 7F091154 10400004 */  beqz  $v0, .L7F091168
/* 0C3B48 7F091158 00002025 */   move  $a0, $zero
/* 0C3B4C 7F09115C 240B0001 */  li    $t3, 1
/* 0C3B50 7F091160 0FC22845 */  jal   set_bondata_invincible_flag
/* 0C3B54 7F091164 AFAB002C */   sw    $t3, 0x2c($sp)
.L7F091168:
/* 0C3B58 7F091168 0FC26993 */  jal   set_cur_player
/* 0C3B5C 7F09116C 8FA40038 */   lw    $a0, 0x38($sp)
/* 0C3B60 7F091170 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0C3B64 7F091174 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0C3B68 7F091178 254C0001 */  addiu $t4, $t2, 1
/* 0C3B6C 7F09117C 158DFFED */  bne   $t4, $t5, .L7F091134
/* 0C3B70 7F091180 AFAC0030 */   sw    $t4, 0x30($sp)
.L7F091184:
/* 0C3B74 7F091184 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0C3B78 7F091188 3C048005 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 0C3B7C 7F09118C 2405009F */  li    $a1, 159
/* 0C3B80 7F091190 11C001ED */  beqz  $t6, .L7F091948
/* 0C3B84 7F091194 00003025 */   move  $a2, $zero
/* 0C3B88 7F091198 0C00209A */  jal   sndPlaySfx
/* 0C3B8C 7F09119C 8C846900 */   lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0C3B90 7F0911A0 100001EA */  b     .L7F09194C
/* 0C3B94 7F0911A4 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_linemode:
/* 0C3B98 7F0911A8 0FC2411F */  jal   set_debug_VisCVG_flag
/* 0C3B9C 7F0911AC 24040001 */   li    $a0, 1
/* 0C3BA0 7F0911B0 100001E6 */  b     .L7F09194C
/* 0C3BA4 7F0911B4 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_2X_HEALTH:
/* 0C3BA8 7F0911B8 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0C3BAC 7F0911BC 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0C3BB0 7F0911C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3BB4 7F0911C4 44812000 */  mtc1  $at, $f4
/* 0C3BB8 7F0911C8 C4462A34 */  lwc1  $f6, 0x2a34($v0)
/* 0C3BBC 7F0911CC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3BC0 7F0911D0 46062032 */  c.eq.s $f4, $f6
/* 0C3BC4 7F0911D4 00000000 */  nop   
/* 0C3BC8 7F0911D8 45010008 */  bc1t  .L7F0911FC
/* 0C3BCC 7F0911DC 00000000 */   nop   
/* 0C3BD0 7F0911E0 C44800DC */  lwc1  $f8, 0xdc($v0)
/* 0C3BD4 7F0911E4 44815000 */  mtc1  $at, $f10
/* 0C3BD8 7F0911E8 00000000 */  nop   
/* 0C3BDC 7F0911EC 460A403C */  c.lt.s $f8, $f10
/* 0C3BE0 7F0911F0 00000000 */  nop   
/* 0C3BE4 7F0911F4 450201D5 */  bc1fl .L7F09194C
/* 0C3BE8 7F0911F8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0911FC:
/* 0C3BEC 7F0911FC 0FC304AE */  jal   get_textptr_for_textID
/* 0C3BF0 7F091200 3404B012 */   li    $a0, 45074
/* 0C3BF4 7F091204 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3BF8 7F091208 00402025 */   move  $a0, $v0
/* 0C3BFC 7F09120C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3C00 7F091210 3C0F8007 */  lui   $t7, %hi(g_CurrentPlayer) # $t7, 0x8007
/* 0C3C04 7F091214 8DEF8BC0 */  lw    $t7, %lo(g_CurrentPlayer)($t7)
/* 0C3C08 7F091218 44818000 */  mtc1  $at, $f16
/* 0C3C0C 7F09121C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C3C10 7F091220 3C188007 */  lui   $t8, %hi(g_CurrentPlayer) # $t8, 0x8007
/* 0C3C14 7F091224 E5F000DC */  swc1  $f16, 0xdc($t7)
/* 0C3C18 7F091228 8F188BC0 */  lw    $t8, %lo(g_CurrentPlayer)($t8)
/* 0C3C1C 7F09122C 44819000 */  mtc1  $at, $f18
/* 0C3C20 7F091230 100001C5 */  b     .L7F091948
/* 0C3C24 7F091234 E7122A34 */   swc1  $f18, 0x2a34($t8)
CHEAT_2X_ARMOR:
/* 0C3C28 7F091238 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0C3C2C 7F09123C 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0C3C30 7F091240 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3C34 7F091244 44810000 */  mtc1  $at, $f0
/* 0C3C38 7F091248 C4442A38 */  lwc1  $f4, 0x2a38($v0)
/* 0C3C3C 7F09124C 46040032 */  c.eq.s $f0, $f4
/* 0C3C40 7F091250 00000000 */  nop   
/* 0C3C44 7F091254 45010006 */  bc1t  .L7F091270
/* 0C3C48 7F091258 00000000 */   nop   
/* 0C3C4C 7F09125C C44600E0 */  lwc1  $f6, 0xe0($v0)
/* 0C3C50 7F091260 4600303C */  c.lt.s $f6, $f0
/* 0C3C54 7F091264 00000000 */  nop   
/* 0C3C58 7F091268 450201B8 */  bc1fl .L7F09194C
/* 0C3C5C 7F09126C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F091270:
/* 0C3C60 7F091270 0FC304AE */  jal   get_textptr_for_textID
/* 0C3C64 7F091274 3404B013 */   li    $a0, 45075
/* 0C3C68 7F091278 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3C6C 7F09127C 00402025 */   move  $a0, $v0
/* 0C3C70 7F091280 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0C3C74 7F091284 24428BC0 */  addiu $v0, %lo(g_CurrentPlayer) # addiu $v0, $v0, -0x7440
/* 0C3C78 7F091288 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3C7C 7F09128C 44814000 */  mtc1  $at, $f8
/* 0C3C80 7F091290 8C590000 */  lw    $t9, ($v0)
/* 0C3C84 7F091294 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C3C88 7F091298 44815000 */  mtc1  $at, $f10
/* 0C3C8C 7F09129C E72800E0 */  swc1  $f8, 0xe0($t9)
/* 0C3C90 7F0912A0 8C490000 */  lw    $t1, ($v0)
/* 0C3C94 7F0912A4 100001A8 */  b     .L7F091948
/* 0C3C98 7F0912A8 E52A2A38 */   swc1  $f10, 0x2a38($t1)
CHEAT_INVISIBILITY:
/* 0C3C9C 7F0912AC 0FC22850 */  jal   bondviewGetVisibleToGuardsFlag
/* 0C3CA0 7F0912B0 00000000 */   nop   
/* 0C3CA4 7F0912B4 504001A5 */  beql  $v0, $zero, .L7F09194C
/* 0C3CA8 7F0912B8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3CAC 7F0912BC 0FC304AE */  jal   get_textptr_for_textID
/* 0C3CB0 7F0912C0 3404B014 */   li    $a0, 45076
/* 0C3CB4 7F0912C4 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3CB8 7F0912C8 00402025 */   move  $a0, $v0
/* 0C3CBC 7F0912CC 0FC2284D */  jal   bondviewSetVisibleToGuardsFlag
/* 0C3CC0 7F0912D0 00002025 */   move  $a0, $zero
/* 0C3CC4 7F0912D4 1000019D */  b     .L7F09194C
/* 0C3CC8 7F0912D8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_infinite_ammo:
/* 0C3CCC 7F0912DC 0FC304AE */  jal   get_textptr_for_textID
/* 0C3CD0 7F0912E0 3404B016 */   li    $a0, 45078
/* 0C3CD4 7F0912E4 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3CD8 7F0912E8 00402025 */   move  $a0, $v0
/* 0C3CDC 7F0912EC 10000197 */  b     .L7F09194C
/* 0C3CE0 7F0912F0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_dk_mode:
/* 0C3CE4 7F0912F4 0FC304AE */  jal   get_textptr_for_textID
/* 0C3CE8 7F0912F8 3404B017 */   li    $a0, 45079
/* 0C3CEC 7F0912FC 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3CF0 7F091300 00402025 */   move  $a0, $v0
/* 0C3CF4 7F091304 0FC24745 */  jal   cheatButtonSetDkMode
/* 0C3CF8 7F091308 24040001 */   li    $a0, 1
/* 0C3CFC 7F09130C 1000018F */  b     .L7F09194C
/* 0C3D00 7F091310 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_extra_weapons:
/* 0C3D04 7F091314 24010001 */  li    $at, 1
/* 0C3D08 7F091318 5441018C */  bnel  $v0, $at, .L7F09194C
/* 0C3D0C 7F09131C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3D10 7F091320 0FC231FA */  jal   add_item_to_inventory
/* 0C3D14 7F091324 24040012 */   li    $a0, 18
/* 0C3D18 7F091328 AFA20028 */  sw    $v0, 0x28($sp)
/* 0C3D1C 7F09132C 0FC231FA */  jal   add_item_to_inventory
/* 0C3D20 7F091330 24040016 */   li    $a0, 22
/* 0C3D24 7F091334 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0C3D28 7F091338 24040013 */  li    $a0, 19
/* 0C3D2C 7F09133C 01625021 */  addu  $t2, $t3, $v0
/* 0C3D30 7F091340 0FC231FA */  jal   add_item_to_inventory
/* 0C3D34 7F091344 AFAA0028 */   sw    $t2, 0x28($sp)
/* 0C3D38 7F091348 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0C3D3C 7F09134C 24040014 */  li    $a0, 20
/* 0C3D40 7F091350 01826821 */  addu  $t5, $t4, $v0
/* 0C3D44 7F091354 0FC231FA */  jal   add_item_to_inventory
/* 0C3D48 7F091358 AFAD0028 */   sw    $t5, 0x28($sp)
/* 0C3D4C 7F09135C 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0C3D50 7F091360 24040015 */  li    $a0, 21
/* 0C3D54 7F091364 01C27821 */  addu  $t7, $t6, $v0
/* 0C3D58 7F091368 0FC231FA */  jal   add_item_to_inventory
/* 0C3D5C 7F09136C AFAF0028 */   sw    $t7, 0x28($sp)
/* 0C3D60 7F091370 8FB80028 */  lw    $t8, 0x28($sp)
/* 0C3D64 7F091374 2404000C */  li    $a0, 12
/* 0C3D68 7F091378 0302C821 */  addu  $t9, $t8, $v0
/* 0C3D6C 7F09137C 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C3D70 7F091380 AFB90028 */   sw    $t9, 0x28($sp)
/* 0C3D74 7F091384 2404000C */  li    $a0, 12
/* 0C3D78 7F091388 0FC1A631 */  jal   give_cur_player_ammo
/* 0C3D7C 7F09138C 00402825 */   move  $a1, $v0
/* 0C3D80 7F091390 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C3D84 7F091394 2404000D */   li    $a0, 13
/* 0C3D88 7F091398 2404000D */  li    $a0, 13
/* 0C3D8C 7F09139C 0FC1A631 */  jal   give_cur_player_ammo
/* 0C3D90 7F0913A0 00402825 */   move  $a1, $v0
/* 0C3D94 7F0913A4 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C3D98 7F0913A8 24040001 */   li    $a0, 1
/* 0C3D9C 7F0913AC 24040001 */  li    $a0, 1
/* 0C3DA0 7F0913B0 0FC1A631 */  jal   give_cur_player_ammo
/* 0C3DA4 7F0913B4 00402825 */   move  $a1, $v0
/* 0C3DA8 7F0913B8 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C3DAC 7F0913BC 59200163 */  blezl $t1, .L7F09194C
/* 0C3DB0 7F0913C0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3DB4 7F0913C4 0FC304AE */  jal   get_textptr_for_textID
/* 0C3DB8 7F0913C8 3404B018 */   li    $a0, 45080
/* 0C3DBC 7F0913CC 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3DC0 7F0913D0 00402025 */   move  $a0, $v0
/* 0C3DC4 7F0913D4 1000015D */  b     .L7F09194C
/* 0C3DC8 7F0913D8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_tiny_bond:
/* 0C3DCC 7F0913DC 24010001 */  li    $at, 1
/* 0C3DD0 7F0913E0 14410159 */  bne   $v0, $at, .L7F091948
/* 0C3DD4 7F0913E4 3C0B8007 */   lui   $t3, %hi(g_playerPerm) # $t3, 0x8007
/* 0C3DD8 7F0913E8 8D6B8BC4 */  lw    $t3, %lo(g_playerPerm)($t3)
/* 0C3DDC 7F0913EC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3DE0 7F0913F0 44818000 */  mtc1  $at, $f16
/* 0C3DE4 7F0913F4 C5720064 */  lwc1  $f18, 0x64($t3)
/* 0C3DE8 7F0913F8 46128032 */  c.eq.s $f16, $f18
/* 0C3DEC 7F0913FC 00000000 */  nop   
/* 0C3DF0 7F091400 45020152 */  bc1fl .L7F09194C
/* 0C3DF4 7F091404 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3DF8 7F091408 0FC304AE */  jal   get_textptr_for_textID
/* 0C3DFC 7F09140C 3404B019 */   li    $a0, 45081
/* 0C3E00 7F091410 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3E04 7F091414 00402025 */   move  $a0, $v0
/* 0C3E08 7F091418 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C3E0C 7F09141C 3C0A8007 */  lui   $t2, %hi(g_playerPerm) # $t2, 0x8007
/* 0C3E10 7F091420 44810000 */  mtc1  $at, $f0
/* 0C3E14 7F091424 8D4A8BC4 */  lw    $t2, %lo(g_playerPerm)($t2)
/* 0C3E18 7F091428 3C0C8007 */  lui   $t4, %hi(g_CurrentPlayer) # $t4, 0x8007
/* 0C3E1C 7F09142C E5400064 */  swc1  $f0, 0x64($t2)
/* 0C3E20 7F091430 8D8C8BC0 */  lw    $t4, %lo(g_CurrentPlayer)($t4)
/* 0C3E24 7F091434 8D8400D4 */  lw    $a0, 0xd4($t4)
/* 0C3E28 7F091438 50800144 */  beql  $a0, $zero, .L7F09194C
/* 0C3E2C 7F09143C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3E30 7F091440 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C3E34 7F091444 46002182 */  mul.s $f6, $f4, $f0
/* 0C3E38 7F091448 44053000 */  mfc1  $a1, $f6
/* 0C3E3C 7F09144C 0FC1B4CF */  jal   set_obj_instance_controller_scale
/* 0C3E40 7F091450 00000000 */   nop   
/* 0C3E44 7F091454 1000013D */  b     .L7F09194C
/* 0C3E48 7F091458 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_paintball:
/* 0C3E4C 7F09145C 0FC304AE */  jal   get_textptr_for_textID
/* 0C3E50 7F091460 3404B01A */   li    $a0, 45082
/* 0C3E54 7F091464 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3E58 7F091468 00402025 */   move  $a0, $v0
/* 0C3E5C 7F09146C 10000137 */  b     .L7F09194C
/* 0C3E60 7F091470 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_10x_health:
/* 0C3E64 7F091474 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0C3E68 7F091478 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0C3E6C 7F09147C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3E70 7F091480 44810000 */  mtc1  $at, $f0
/* 0C3E74 7F091484 C4482A34 */  lwc1  $f8, 0x2a34($v0)
/* 0C3E78 7F091488 46080032 */  c.eq.s $f0, $f8
/* 0C3E7C 7F09148C 00000000 */  nop   
/* 0C3E80 7F091490 45010006 */  bc1t  .L7F0914AC
/* 0C3E84 7F091494 00000000 */   nop   
/* 0C3E88 7F091498 C44A00DC */  lwc1  $f10, 0xdc($v0)
/* 0C3E8C 7F09149C 4600503C */  c.lt.s $f10, $f0
/* 0C3E90 7F0914A0 00000000 */  nop   
/* 0C3E94 7F0914A4 45020129 */  bc1fl .L7F09194C
/* 0C3E98 7F0914A8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0914AC:
/* 0C3E9C 7F0914AC 0FC304AE */  jal   get_textptr_for_textID
/* 0C3EA0 7F0914B0 3404B01B */   li    $a0, 45083
/* 0C3EA4 7F0914B4 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3EA8 7F0914B8 00402025 */   move  $a0, $v0
/* 0C3EAC 7F0914BC 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0C3EB0 7F0914C0 24428BC0 */  addiu $v0, %lo(g_CurrentPlayer) # addiu $v0, $v0, -0x7440
/* 0C3EB4 7F0914C4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3EB8 7F0914C8 44818000 */  mtc1  $at, $f16
/* 0C3EBC 7F0914CC 8C4D0000 */  lw    $t5, ($v0)
/* 0C3EC0 7F0914D0 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0C3EC4 7F0914D4 44819000 */  mtc1  $at, $f18
/* 0C3EC8 7F0914D8 E5B000DC */  swc1  $f16, 0xdc($t5)
/* 0C3ECC 7F0914DC 8C4E0000 */  lw    $t6, ($v0)
/* 0C3ED0 7F0914E0 10000119 */  b     .L7F091948
/* 0C3ED4 7F0914E4 E5D22A34 */   swc1  $f18, 0x2a34($t6)
cheats_cheat_magnum:
/* 0C3ED8 7F0914E8 24010001 */  li    $at, 1
/* 0C3EDC 7F0914EC 54410117 */  bnel  $v0, $at, .L7F09194C
/* 0C3EE0 7F0914F0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3EE4 7F0914F4 0FC231FA */  jal   add_item_to_inventory
/* 0C3EE8 7F0914F8 24040012 */   li    $a0, 18
/* 0C3EEC 7F0914FC 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C3EF0 7F091500 2404000C */   li    $a0, 12
/* 0C3EF4 7F091504 2404000C */  li    $a0, 12
/* 0C3EF8 7F091508 0FC1A631 */  jal   give_cur_player_ammo
/* 0C3EFC 7F09150C 00402825 */   move  $a1, $v0
/* 0C3F00 7F091510 1000010E */  b     .L7F09194C
/* 0C3F04 7F091514 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_laser:
/* 0C3F08 7F091518 24010001 */  li    $at, 1
/* 0C3F0C 7F09151C 5441010B */  bnel  $v0, $at, .L7F09194C
/* 0C3F10 7F091520 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3F14 7F091524 0FC231FA */  jal   add_item_to_inventory
/* 0C3F18 7F091528 24040016 */   li    $a0, 22
/* 0C3F1C 7F09152C 10000107 */  b     .L7F09194C
/* 0C3F20 7F091530 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldengun:
/* 0C3F24 7F091534 24010001 */  li    $at, 1
/* 0C3F28 7F091538 54410104 */  bnel  $v0, $at, .L7F09194C
/* 0C3F2C 7F09153C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3F30 7F091540 0FC231FA */  jal   add_item_to_inventory
/* 0C3F34 7F091544 24040013 */   li    $a0, 19
/* 0C3F38 7F091548 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C3F3C 7F09154C 2404000D */   li    $a0, 13
/* 0C3F40 7F091550 2404000D */  li    $a0, 13
/* 0C3F44 7F091554 0FC1A631 */  jal   give_cur_player_ammo
/* 0C3F48 7F091558 00402825 */   move  $a1, $v0
/* 0C3F4C 7F09155C 100000FB */  b     .L7F09194C
/* 0C3F50 7F091560 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_silverpp7:
/* 0C3F54 7F091564 24010001 */  li    $at, 1
/* 0C3F58 7F091568 544100F8 */  bnel  $v0, $at, .L7F09194C
/* 0C3F5C 7F09156C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3F60 7F091570 0FC231FA */  jal   add_item_to_inventory
/* 0C3F64 7F091574 24040014 */   li    $a0, 20
/* 0C3F68 7F091578 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C3F6C 7F09157C 24040001 */   li    $a0, 1
/* 0C3F70 7F091580 24040001 */  li    $a0, 1
/* 0C3F74 7F091584 0FC1A631 */  jal   give_cur_player_ammo
/* 0C3F78 7F091588 00402825 */   move  $a1, $v0
/* 0C3F7C 7F09158C 100000EF */  b     .L7F09194C
/* 0C3F80 7F091590 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldpp7:
/* 0C3F84 7F091594 24010001 */  li    $at, 1
/* 0C3F88 7F091598 544100EC */  bnel  $v0, $at, .L7F09194C
/* 0C3F8C 7F09159C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3F90 7F0915A0 0FC231FA */  jal   add_item_to_inventory
/* 0C3F94 7F0915A4 24040015 */   li    $a0, 21
/* 0C3F98 7F0915A8 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C3F9C 7F0915AC 24040001 */   li    $a0, 1
/* 0C3FA0 7F0915B0 24040001 */  li    $a0, 1
/* 0C3FA4 7F0915B4 0FC1A631 */  jal   give_cur_player_ammo
/* 0C3FA8 7F0915B8 00402825 */   move  $a1, $v0
/* 0C3FAC 7F0915BC 100000E3 */  b     .L7F09194C
/* 0C3FB0 7F0915C0 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_INVISIBILITY_mp:
/* 0C3FB4 7F0915C4 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C3FB8 7F0915C8 44816000 */  mtc1  $at, $f12
/* 0C3FBC 7F0915CC 3C018005 */  lui   $at, %hi(finalamount) # $at, 0x8005
/* 0C3FC0 7F0915D0 0FC202AD */  jal   currentPlayerStartChrFade
/* 0C3FC4 7F0915D4 C42ECA98 */   lwc1  $f14, %lo(finalamount)($at)
/* 0C3FC8 7F0915D8 100000DC */  b     .L7F09194C
/* 0C3FCC 7F0915DC 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_TURBO_MODE:
/* 0C3FD0 7F0915E0 0FC24134 */  jal   get_debug_fast_bond_flag
/* 0C3FD4 7F0915E4 00000000 */   nop   
/* 0C3FD8 7F0915E8 544000D8 */  bnezl $v0, .L7F09194C
/* 0C3FDC 7F0915EC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C3FE0 7F0915F0 0FC304AE */  jal   get_textptr_for_textID
/* 0C3FE4 7F0915F4 3404B01D */   li    $a0, 45085
/* 0C3FE8 7F0915F8 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C3FEC 7F0915FC 00402025 */   move  $a0, $v0
/* 0C3FF0 7F091600 0FC24137 */  jal   set_debug_fast_bond_flag
/* 0C3FF4 7F091604 24040001 */   li    $a0, 1
/* 0C3FF8 7F091608 100000D0 */  b     .L7F09194C
/* 0C3FFC 7F09160C 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_DEBUG_POS:
/* 0C4000 7F091610 0FC2410E */  jal   get_debug_testingmanpos_flag
/* 0C4004 7F091614 00000000 */   nop   
/* 0C4008 7F091618 544000CC */  bnezl $v0, .L7F09194C
/* 0C400C 7F09161C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C4010 7F091620 0FC24110 */  jal   set_debug_testingmanpos_flag
/* 0C4014 7F091624 24040001 */   li    $a0, 1
/* 0C4018 7F091628 100000C8 */  b     .L7F09194C
/* 0C401C 7F09162C 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_FAST_ANIMATION:
/* 0C4020 7F091630 0FC0811D */  jal   get_animation_rate
/* 0C4024 7F091634 00000000 */   nop   
/* 0C4028 7F091638 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C402C 7F09163C 44812000 */  mtc1  $at, $f4
/* 0C4030 7F091640 00000000 */  nop   
/* 0C4034 7F091644 4604003C */  c.lt.s $f0, $f4
/* 0C4038 7F091648 00000000 */  nop   
/* 0C403C 7F09164C 450200BF */  bc1fl .L7F09194C
/* 0C4040 7F091650 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C4044 7F091654 0FC304AE */  jal   get_textptr_for_textID
/* 0C4048 7F091658 3404B034 */   li    $a0, 45108
/* 0C404C 7F09165C 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C4050 7F091660 00402025 */   move  $a0, $v0
/* 0C4054 7F091664 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C4058 7F091668 44816000 */  mtc1  $at, $f12
/* 0C405C 7F09166C 0FC080ED */  jal   animation_speed_related
/* 0C4060 7F091670 00000000 */   nop   
/* 0C4064 7F091674 100000B5 */  b     .L7F09194C
/* 0C4068 7F091678 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_SLOW_ANIMATION:
/* 0C406C 7F09167C 0FC0811D */  jal   get_animation_rate
/* 0C4070 7F091680 00000000 */   nop   
/* 0C4074 7F091684 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C4078 7F091688 44813000 */  mtc1  $at, $f6
/* 0C407C 7F09168C 00000000 */  nop   
/* 0C4080 7F091690 4600303C */  c.lt.s $f6, $f0
/* 0C4084 7F091694 00000000 */  nop   
/* 0C4088 7F091698 450200AC */  bc1fl .L7F09194C
/* 0C408C 7F09169C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C4090 7F0916A0 0FC304AE */  jal   get_textptr_for_textID
/* 0C4094 7F0916A4 3404B032 */   li    $a0, 45106
/* 0C4098 7F0916A8 0FC229B5 */  jal   jp_display_string_in_lower_left_corner
/* 0C409C 7F0916AC 00402025 */   move  $a0, $v0
/* 0C40A0 7F0916B0 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C40A4 7F0916B4 44816000 */  mtc1  $at, $f12
/* 0C40A8 7F0916B8 0FC080ED */  jal   animation_speed_related
/* 0C40AC 7F0916BC 00000000 */   nop   
/* 0C40B0 7F0916C0 100000A2 */  b     .L7F09194C
/* 0C40B4 7F0916C4 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_2X_ROCKET_LAUNCHER:
/* 0C40B8 7F0916C8 24010001 */  li    $at, 1
/* 0C40BC 7F0916CC 5441009F */  bnel  $v0, $at, .L7F09194C
/* 0C40C0 7F0916D0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C40C4 7F0916D4 0FC231FA */  jal   add_item_to_inventory
/* 0C40C8 7F0916D8 24040019 */   li    $a0, 25
/* 0C40CC 7F0916DC 24040019 */  li    $a0, 25
/* 0C40D0 7F0916E0 0FC23221 */  jal   add_doubles_item_to_inventory
/* 0C40D4 7F0916E4 24050019 */   li    $a1, 25
/* 0C40D8 7F0916E8 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C40DC 7F0916EC 24040006 */   li    $a0, 6
/* 0C40E0 7F0916F0 24040006 */  li    $a0, 6
/* 0C40E4 7F0916F4 0FC1A631 */  jal   give_cur_player_ammo
/* 0C40E8 7F0916F8 00402825 */   move  $a1, $v0
/* 0C40EC 7F0916FC 10000093 */  b     .L7F09194C
/* 0C40F0 7F091700 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_2X_GRENADE_LAUNCHER:
/* 0C40F4 7F091704 24010001 */  li    $at, 1
/* 0C40F8 7F091708 54410090 */  bnel  $v0, $at, .L7F09194C
/* 0C40FC 7F09170C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C4100 7F091710 0FC231FA */  jal   add_item_to_inventory
/* 0C4104 7F091714 24040018 */   li    $a0, 24
/* 0C4108 7F091718 24040018 */  li    $a0, 24
/* 0C410C 7F09171C 0FC23221 */  jal   add_doubles_item_to_inventory
/* 0C4110 7F091720 24050018 */   li    $a1, 24
/* 0C4114 7F091724 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C4118 7F091728 2404000B */   li    $a0, 11
/* 0C411C 7F09172C 2404000B */  li    $a0, 11
/* 0C4120 7F091730 0FC1A631 */  jal   give_cur_player_ammo
/* 0C4124 7F091734 00402825 */   move  $a1, $v0
/* 0C4128 7F091738 10000084 */  b     .L7F09194C
/* 0C412C 7F09173C 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_2X_RCP90:
/* 0C4130 7F091740 24010001 */  li    $at, 1
/* 0C4134 7F091744 54410081 */  bnel  $v0, $at, .L7F09194C
/* 0C4138 7F091748 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C413C 7F09174C 0FC231FA */  jal   add_item_to_inventory
/* 0C4140 7F091750 2404000E */   li    $a0, 14
/* 0C4144 7F091754 2404000E */  li    $a0, 14
/* 0C4148 7F091758 0FC23221 */  jal   add_doubles_item_to_inventory
/* 0C414C 7F09175C 2405000E */   li    $a1, 14
/* 0C4150 7F091760 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C4154 7F091764 24040001 */   li    $a0, 1
/* 0C4158 7F091768 24040001 */  li    $a0, 1
/* 0C415C 7F09176C 0FC1A631 */  jal   give_cur_player_ammo
/* 0C4160 7F091770 00402825 */   move  $a1, $v0
/* 0C4164 7F091774 10000075 */  b     .L7F09194C
/* 0C4168 7F091778 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_2X_THROWING_KNIFE:
/* 0C416C 7F09177C 24010001 */  li    $at, 1
/* 0C4170 7F091780 54410072 */  bnel  $v0, $at, .L7F09194C
/* 0C4174 7F091784 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C4178 7F091788 0FC231FA */  jal   add_item_to_inventory
/* 0C417C 7F09178C 24040003 */   li    $a0, 3
/* 0C4180 7F091790 24040003 */  li    $a0, 3
/* 0C4184 7F091794 0FC23221 */  jal   add_doubles_item_to_inventory
/* 0C4188 7F091798 24050003 */   li    $a1, 3
/* 0C418C 7F09179C 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C4190 7F0917A0 2404000A */   li    $a0, 10
/* 0C4194 7F0917A4 2404000A */  li    $a0, 10
/* 0C4198 7F0917A8 0FC1A631 */  jal   give_cur_player_ammo
/* 0C419C 7F0917AC 00402825 */   move  $a1, $v0
/* 0C41A0 7F0917B0 10000066 */  b     .L7F09194C
/* 0C41A4 7F0917B4 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_2X_HUNTING_KNIFE:
/* 0C41A8 7F0917B8 24010001 */  li    $at, 1
/* 0C41AC 7F0917BC 14410062 */  bne   $v0, $at, .L7F091948
/* 0C41B0 7F0917C0 3C0F8004 */   lui   $t7, %hi(j_text_trigger) # $t7, 0x8004
/* 0C41B4 7F0917C4 8DEF1150 */  lw    $t7, %lo(j_text_trigger)($t7)
/* 0C41B8 7F0917C8 11E00014 */  beqz  $t7, .CHEAT_2X_HUNTING_KNIFE_en
/* 0C41BC 7F0917CC 00000000 */   nop   
/* 0C41C0 7F0917D0 0FC231FA */  jal   add_item_to_inventory
/* 0C41C4 7F0917D4 24040019 */   li    $a0, 25
/* 0C41C8 7F0917D8 0FC231FA */  jal   add_item_to_inventory
/* 0C41CC 7F0917DC 24040011 */   li    $a0, 17
/* 0C41D0 7F0917E0 24040011 */  li    $a0, 17
/* 0C41D4 7F0917E4 0FC23221 */  jal   add_doubles_item_to_inventory
/* 0C41D8 7F0917E8 24050019 */   li    $a1, 25
/* 0C41DC 7F0917EC 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C41E0 7F0917F0 24040006 */   li    $a0, 6
/* 0C41E4 7F0917F4 24040006 */  li    $a0, 6
/* 0C41E8 7F0917F8 0FC1A631 */  jal   give_cur_player_ammo
/* 0C41EC 7F0917FC 00402825 */   move  $a1, $v0
/* 0C41F0 7F091800 0FC1A69A */  jal   get_max_ammo_for_type
/* 0C41F4 7F091804 24040003 */   li    $a0, 3
/* 0C41F8 7F091808 24040003 */  li    $a0, 3
/* 0C41FC 7F09180C 0FC1A631 */  jal   give_cur_player_ammo
/* 0C4200 7F091810 00402825 */   move  $a1, $v0
/* 0C4204 7F091814 1000004D */  b     .L7F09194C
/* 0C4208 7F091818 8FBF0014 */   lw    $ra, 0x14($sp)
.CHEAT_2X_HUNTING_KNIFE_en:
/* 0C420C 7F09181C 0FC231FA */  jal   add_item_to_inventory
/* 0C4210 7F091820 24040002 */   li    $a0, 2
/* 0C4214 7F091824 24040002 */  li    $a0, 2
/* 0C4218 7F091828 0FC23221 */  jal   add_doubles_item_to_inventory
/* 0C421C 7F09182C 24050002 */   li    $a1, 2
/* 0C4220 7F091830 10000046 */  b     .L7F09194C
/* 0C4224 7F091834 8FBF0014 */   lw    $ra, 0x14($sp)
CHEAT_2X_LASER:
/* 0C4228 7F091838 24010001 */  li    $at, 1
/* 0C422C 7F09183C 54410043 */  bnel  $v0, $at, .L7F09194C
/* 0C4230 7F091840 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C4234 7F091844 0FC231FA */  jal   add_item_to_inventory
/* 0C4238 7F091848 24040016 */   li    $a0, 22
/* 0C423C 7F09184C 24040016 */  li    $a0, 22
/* 0C4240 7F091850 0FC23221 */  jal   add_doubles_item_to_inventory
/* 0C4244 7F091854 24050016 */   li    $a1, 22
/* 0C4248 7F091858 1000003C */  b     .L7F09194C
/* 0C424C 7F09185C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlockcheat:
/* 0C4250 7F091860 3C048002 */  lui   $a0, %hi(selected_folder_num) # $a0, 0x8002
/* 0C4254 7F091864 8C845E38 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 0C4258 7F091868 24C5FFDD */  addiu $a1, $a2, -0x23
/* 0C425C 7F09186C 04800036 */  bltz  $a0, .L7F091948
/* 0C4260 7F091870 28810004 */   slti  $at, $a0, 4
/* 0C4264 7F091874 50200035 */  beql  $at, $zero, .L7F09194C
/* 0C4268 7F091878 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C426C 7F09187C 0FC07970 */  jal   sub_GAME_7F01E760
/* 0C4270 7F091880 00000000 */   nop   
/* 0C4274 7F091884 3C048005 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 0C4278 7F091888 8C846900 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0C427C 7F09188C 2405009F */  li    $a1, 159
/* 0C4280 7F091890 0C00209A */  jal   sndPlaySfx
/* 0C4284 7F091894 00003025 */   move  $a2, $zero
/* 0C4288 7F091898 1000002C */  b     .L7F09194C
/* 0C428C 7F09189C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlocklevel:
/* 0C4290 7F0918A0 3C028002 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8002
/* 0C4294 7F0918A4 24425E38 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, 0x5e38
/* 0C4298 7F0918A8 8C440000 */  lw    $a0, ($v0)
/* 0C429C 7F0918AC 24C8FFC9 */  addiu $t0, $a2, -0x37
/* 0C42A0 7F0918B0 04800025 */  bltz  $a0, .L7F091948
/* 0C42A4 7F0918B4 28810004 */   slti  $at, $a0, 4
/* 0C42A8 7F0918B8 10200023 */  beqz  $at, .L7F091948
/* 0C42AC 7F0918BC 00001825 */   move  $v1, $zero
/* 0C42B0 7F0918C0 19000014 */  blez  $t0, .L7F091914
/* 0C42B4 7F0918C4 00002825 */   move  $a1, $zero
.L7F0918C8:
/* 0C42B8 7F0918C8 3C028002 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8002
/* 0C42BC 7F0918CC 24425E38 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, 0x5e38
/* 0C42C0 7F0918D0 8C440000 */  lw    $a0, ($v0)
/* 0C42C4 7F0918D4 00003025 */  move  $a2, $zero
/* 0C42C8 7F0918D8 AFA30018 */  sw    $v1, 0x18($sp)
/* 0C42CC 7F0918DC AFA5001C */  sw    $a1, 0x1c($sp)
/* 0C42D0 7F0918E0 0FC07848 */  jal   fileIsStageUnlockedAtDifficulty
/* 0C42D4 7F0918E4 AFA80020 */   sw    $t0, 0x20($sp)
/* 0C42D8 7F0918E8 24010003 */  li    $at, 3
/* 0C42DC 7F0918EC 8FA30018 */  lw    $v1, 0x18($sp)
/* 0C42E0 7F0918F0 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0C42E4 7F0918F4 14410002 */  bne   $v0, $at, .L7F091900
/* 0C42E8 7F0918F8 8FA80020 */   lw    $t0, 0x20($sp)
/* 0C42EC 7F0918FC 24630001 */  addiu $v1, $v1, 1
.L7F091900:
/* 0C42F0 7F091900 24A50001 */  addiu $a1, $a1, 1
/* 0C42F4 7F091904 14A8FFF0 */  bne   $a1, $t0, .L7F0918C8
/* 0C42F8 7F091908 00000000 */   nop   
/* 0C42FC 7F09190C 3C028002 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8002
/* 0C4300 7F091910 24425E38 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, 0x5e38
.L7F091914:
/* 0C4304 7F091914 24780001 */  addiu $t8, $v1, 1
/* 0C4308 7F091918 1518000B */  bne   $t0, $t8, .L7F091948
/* 0C430C 7F09191C 2505FFFF */   addiu $a1, $t0, -1
/* 0C4310 7F091920 3C0705F5 */  lui   $a3, (0x05F5E0FF >> 16) # lui $a3, 0x5f5
/* 0C4314 7F091924 34E7E0FF */  ori   $a3, (0x05F5E0FF & 0xFFFF) # ori $a3, $a3, 0xe0ff
/* 0C4318 7F091928 8C440000 */  lw    $a0, ($v0)
/* 0C431C 7F09192C 0FC07916 */  jal   fileUnlockStageInFolderAtDifficulty
/* 0C4320 7F091930 00003025 */   move  $a2, $zero
/* 0C4324 7F091934 3C048005 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 0C4328 7F091938 8C846900 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0C432C 7F09193C 2405009F */  li    $a1, 159
/* 0C4330 7F091940 0C00209A */  jal   sndPlaySfx
/* 0C4334 7F091944 00003025 */   move  $a2, $zero
cheats_debug_return_saved_ra:
.L7F091948:
/* 0C4338 7F091948 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F09194C:
/* 0C433C 7F09194C 27BD0040 */  addiu $sp, $sp, 0x40
/* 0C4340 7F091950 03E00008 */  jr    $ra
/* 0C4344 7F091954 00000000 */   nop   
)
#endif

/**
 * Address 0x7F092438 (all versions)
 */
void cheatButtonHandleCheatsTurnedOff(s32 cheat_id)
{
    s32 mask;
    s32 current_player_number;
    s32 player_count;

    mask = g_CheatInfo[cheat_id - 1].maskfield;
    current_player_number = get_cur_playernum();
    player_count = getPlayerCount();

    if ((mask & CHEAT_MASK_16) == 0)
    {
        if ((mask & CHEAT_MASK_GLOBAL) == 0)
        {
            g_CheatPlayerTextRelated[cheat_id] &= ~(1 << current_player_number);
        }
        else
        {
            g_CheatPlayerTextRelated[cheat_id] = 0;
        }
    }

    switch (cheat_id)
    {
        case CHEAT_INVINCIBILITY:
            if (get_bondata_invincible_flag() != 0)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01E));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01E));
#endif
                set_bondata_invincible_flag(0);
                return;
            }
            return;
            
        case CHEAT_ALLGUNS:
            if (get_BONDdata_allguns_flag() != 0)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01F));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01F));
#endif
                set_BONDdata_allguns_flag(0);
                return;
            }
            return;

        case CHEAT_LINEMODE:
            set_debug_VisCVG_flag(0);
            return;

        case CHEAT_INVISIBILITY:
            if (bondviewGetVisibleToGuardsFlag() == 0)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB020));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB020));
#endif
                bondviewSetVisibleToGuardsFlag(1);
                return;
            }
            return;

        case CHEAT_INFINITE_AMMO:
#if defined(VERSION_JP) || defined(VERSION_EU)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB022));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB022));
#endif
            return;
            
        case CHEAT_DK_MODE:
#if defined(VERSION_JP) || defined(VERSION_EU)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB023));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB023));
#endif
            cheatButtonSetDkMode(0);
            return;

        case CHEAT_TINY_BOND:
            if ((player_count == 1) && (g_playerPerm->player_perspective_height != 1.0f))
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB024));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB024));
#endif
                g_playerPerm->player_perspective_height = 1.0f;
                if (g_CurrentPlayer->ptr_char_objectinstance != 0)
                {
                    set_obj_instance_controller_scale(g_CurrentPlayer->ptr_char_objectinstance, 2.0f * ((struct Model *)g_CurrentPlayer->ptr_char_objectinstance)->scale);
                }
                return;
            }
            return;

        case CHEAT_PAINTBALL:
#if defined(VERSION_JP) || defined(VERSION_EU)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB025));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB025));
#endif
            return;

        case 0x16: /* multiplayer? but the function call is for "fade"? */
            currentPlayerStartChrFade(300.0f, 1.0f);
            return;

        case CHEAT_TURBO_MODE:
            if (get_debug_fast_bond_flag() != 0)
            {
#if defined(VERSION_JP) || defined(VERSION_EU)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB027));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB027));
#endif
                set_debug_fast_bond_flag(0);
                return;
            }
            return;

        case CHEAT_DEBUG_POS:
            if (get_debug_testingmanpos_flag() != 0)
            {
                set_debug_testingmanpos_flag(0);
            }
            return;

        
        case CHEAT_EXTRA_MP_CHARS:
        case CHEAT_MAXAMMO:
        case CHEAT_DEBUG_RETURN_SAVED_RA:
        case CHEAT_DEACTIVATE_INVINCIBILITY:
        case CHEAT_2X_HEALTH:
        case CHEAT_2X_ARMOR:
        case CHEAT_EXTRA_WEAPONS:
        case CHEAT_10X_HEALTH:
        case CHEAT_MAGNUM:
        case CHEAT_LASER:
        case CHEAT_GOLDEN_GUN:
        case CHEAT_SILVER_PP7:
        case CHEAT_GOLD_PP7:
        case CHEAT_NO_RADAR_MP:
        case CHEAT_FAST_ANIMATION:
        case CHEAT_SLOW_ANIMATION:
        case CHEAT_ENEMY_ROCKETS:
        case CHEAT_2X_ROCKET_LAUNCHER:
        case CHEAT_2X_GRENADE_LAUNCHER:
        case CHEAT_2X_RCP90:
        case CHEAT_2X_THROWING_KNIFE:
        case CHEAT_2X_HUNTING_KNIFE:
        case CHEAT_2X_LASER:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case CHEAT_UNLOCK_CHEATS:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case CHEAT_UNLOCK_STAGES:
        
        default:
        break;
    }
    
}




/**
 * Address 0x7F0926C0.
 */
void cheatDisableAllCheats(void)
{
    s32 numplayers;
    s32 starting_player_number;
    s32 i;
    s32 j;

    numplayers = getPlayerCount();
    starting_player_number = get_cur_playernum();

    for (i=0; i<numplayers; i++)
    {
        set_cur_player(i);

        for (j=1; j<CHEAT_INVALID; j++)
        {
            if ((g_CheatInfo[j - 1].maskfield & CHEAT_MASK_64) && (cheatCheckIfOn(j) != 0))
            {
                cheatButtonHandleCheatsTurnedOff(j);
            }
        }
    }

    set_cur_player(starting_player_number);
}





/**
 * Address 0x7F092774.
 */
char *cheatGetMenuTextPointer(s32 cheat_id)
{
    u16 temp_v0;

    temp_v0 = g_CheatInfo[cheat_id - 1].text_bank_id;

    if (temp_v0 != 0)
    {
        return get_textptr_for_textID((s32) temp_v0);
    }

    return get_textptr_for_textID(0xB028);
}



/**
 * Address 0x7F0927BC.
 */
s32 cheatCheckIfOn(CHEAT_ID cheat)
{
    return ((s32) (u8) g_CheatPlayerTextRelated[cheat] >> get_cur_playernum()) & 1;
}





void cheatButtonSetDkMode(s32 cheat_id)
{
    s32 num_guards;
    s32 i;
    f32 scale;
    struct Model *model;
    struct ChrRecord* guard = ptr_guard_data;

    num_guards = get_numguards();

    if (cheat_id != 0)
    {
        scale = 0.8f;
    }
    else
    {
        scale = 1.25f;
    }

    for (i=0; i<num_guards; i++, guard++)
    {

#if defined(VERSION_US)
        model = (struct Model*)guard->model;
        if (model != NULL)
        {
            set_obj_instance_controller_scale(model, model->scale * scale);
        }
#else
        if (guard->model != NULL && (not_in_us_7F0209EC(guard->bodynum, guard->headnum) != 0))
        {
            model = (struct Model*)guard->model;
            set_obj_instance_controller_scale(model, model->scale * scale);
        }
#endif
    }
}