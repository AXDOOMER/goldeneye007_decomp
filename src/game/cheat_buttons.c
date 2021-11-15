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
    u16 * anonymous_1;

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
u16 dword_D_8003F430[] = {0x0032, 0x0028, 0x0230, 0x0120, 0x0410, 0x0032, 0x0028, 0x0130, 0x0034, 0x0420};
//D:8003F444
u16 dword_D_8003F444[] = {0x0420, 0x0011, 0x0018, 0x0120, 0x0024, 0x0018, 0x0120, 0x0410, 0x0220, 0x0031};
//D:8003F458
u16 dword_D_8003F458[] = {0x0430, 0x0022, 0x0021, 0x0032, 0x0420, 0x0024, 0x0012, 0x0031, 0x0810, 0x0022};
//D:8003F46C
u16 dword_D_8003F46C[] = {0x0031, 0x0810, 0x0410, 0x0410, 0x0031, 0x0230, 0x0410, 0x0810, 0x0031, 0x0210};
//D:8003F480
u16 dword_D_8003F480[] = {0x0820, 0x0011, 0x0014, 0x0032, 0x0230, 0x0130, 0x0410, 0x0018, 0x0011, 0x0430};
//D:8003F494
u16 dword_D_8003F494[] = {0x0110, 0x0220, 0x0220, 0x0810, 0x0420, 0x0014, 0x0022, 0x0031, 0x0420, 0x0028};
//D:8003F4A8
u16 dword_D_8003F4A8[] = {0x0014, 0x0430, 0x0120, 0x0018, 0x0031, 0x0810, 0x0420, 0x0120, 0x0012, 0x0018};
//D:8003F4BC
u16 dword_D_8003F4BC[] = {0x0012, 0x0038, 0x0230, 0x0830, 0x0810, 0x0022, 0x0018, 0x0024, 0x0230, 0x0110};
//D:8003F4D0
u16 dword_D_8003F4D0[] = {0x0028, 0x0032, 0x0810, 0x0021, 0x0012, 0x0120, 0x0032, 0x0021, 0x0820, 0x0034};
//D:8003F4E4
u16 dword_D_8003F4E4[] = {0x0038, 0x0210, 0x0014, 0x0024, 0x0810, 0x0420, 0x0011, 0x0120, 0x0130, 0x0014};
//D:8003F4F8
u16 dword_D_8003F4F8[] = {0x0038, 0x0012, 0x0220, 0x0018, 0x0220, 0x0014, 0x0021, 0x0110, 0x0038, 0x0120};
//D:8003F50C
u16 dword_D_8003F50C[] = {0x0230, 0x0210, 0x0028, 0x0220, 0x0018, 0x0014, 0x0011, 0x0110, 0x0420, 0x0012};
//D:8003F520
u16 dword_D_8003F520[] = {0x0012, 0x0038, 0x0220, 0x0810, 0x0210, 0x0820, 0x0014, 0x0120, 0x0021, 0x0430};
//D:8003F534
u16 dword_D_8003F534[] = {0x0024, 0x0110, 0x0021, 0x0012, 0x0024, 0x0230, 0x0021, 0x0830, 0x0011, 0x0820};
//D:8003F548
u16 dword_D_8003F548[] = {0x0820, 0x0014, 0x0220, 0x0410, 0x0022, 0x0031, 0x0028, 0x0110, 0x0110, 0x0011};
//D:8003F55C
u16 dword_D_8003F55C[] = {0x0018, 0x0420, 0x0011, 0x0220, 0x0830, 0x0034, 0x0011, 0x0810, 0x0034, 0x0810};
//D:8003F570
u16 dword_D_8003F570[] = {0x0024, 0x0031, 0x0011, 0x0018, 0x0012, 0x0120, 0x0038, 0x0028, 0x0430, 0x0021};
//D:8003F584
u16 dword_D_8003F584[] = {0x0420, 0x0410, 0x0038, 0x0220, 0x0130, 0x0022, 0x0110, 0x0028, 0x0220, 0x0024};
//D:8003F598
u16 dword_D_8003F598[] = {0x0034, 0x0034, 0x0120, 0x0230, 0x0210, 0x0011, 0x0230, 0x0018, 0x0014, 0x0110};
//D:8003F5AC
u16 dword_D_8003F5AC[] = {0x0210, 0x0830, 0x0034, 0x0210, 0x0031, 0x0220, 0x0130, 0x0034, 0x0820, 0x0014};
//D:8003F5C0
u16 dword_D_8003F5C0[] = {0x0032, 0x0021, 0x0820, 0x0034, 0x0011, 0x0014, 0x0210, 0x0014, 0x0018, 0x0420};
//D:8003F5D4
u16 dword_D_8003F5D4[] = {0x0420, 0x0420, 0x0014, 0x0021, 0x0130, 0x0012, 0x0420, 0x0022, 0x0021, 0x0820};
//D:8003F5E8
u16 dword_D_8003F5E8[] = {0x0210, 0x0014, 0x0011, 0x0230, 0x0120, 0x0014, 0x0220, 0x0032, 0x0820, 0x0028};
//D:8003F5FC
u16 dword_D_8003F5FC[] = {0x0014, 0x0210, 0x0830, 0x0110, 0x0410, 0x0410, 0x0810, 0x0012, 0x0018, 0x0230};
//D:8003F610
u16 dword_D_8003F610[] = {0x0024, 0x0410, 0x0120, 0x0011, 0x0014, 0x0210, 0x0210, 0x0018, 0x0210, 0x0038};
//D:8003F624
u16 dword_D_8003F624[] = {0x0420, 0x0014, 0x0830, 0x0120, 0x0018, 0x0012, 0x0810, 0x0022, 0x0820, 0x0012};
//D:8003F638
u16 dword_D_8003F638[] = {0x0038, 0x0220, 0x0410, 0x0420, 0x0028, 0x0420, 0x0110, 0x0018, 0x0022, 0x0110};
//D:8003F64C
u16 dword_D_8003F64C[] = {0x0014, 0x0210, 0x0120, 0x0031, 0x0420, 0x0038, 0x0220, 0x0038, 0x0130, 0x0022};
//D:8003F660
u16 dword_D_8003F660[] = {0x0830, 0x0031, 0x0420, 0x0110, 0x0810, 0x0420, 0x0220, 0x0021, 0x0031, 0x0220, 0x8030, 0x4030, 0x8030, 0x4030};
//D:8003F67C
u16 dword_D_8003F67C[] = {0x0820, 0x0008, 0x0110, 0x0032, 0x0820, 0x0014, 0x0024, 0x0034, 0x0830, 0x0024};
//D:8003F690
u16 dword_D_8003F690[] = {0x0210, 0x0420, 0x0200, 0x0800, 0x0400, 0x0012, 0x0022, 0x0230, 0x0130, 0x0022};
//D:8003F6A4
u16 dword_D_8003F6A4[] = {0x0830, 0x0001, 0x0210, 0x0810, 0x0800, 0x0110, 0x0800, 0x0034, 0x0430, 0x0032};
//D:8003F6B8
u16 dword_D_8003F6B8[] = {0x0410, 0x0810, 0x0100, 0x0034, 0x0120, 0x0210, 0x0200, 0x0400, 0x0800, 0x0014};
//D:8003F6CC
u16 dword_D_8003F6CC[] = {0x0110, 0x0820, 0x0400, 0x0400, 0x0014, 0x0220, 0x0022, 0x0810, 0x0410, 0x0012};
//D:8003F6E0
u16 dword_D_8003F6E0[] = {0x0420, 0x0024, 0x0830, 0x0014, 0x0200, 0x0410, 0x0024, 0x0800, 0x0410, 0x0120};
//D:8003F6F4
u16 dword_D_8003F6F4[] = {0x0810, 0x0004, 0x0002, 0x0008, 0x0420, 0x0810, 0x0002, 0x0100, 0x0210, 0x0110};
//D:8003F708
u16 dword_D_8003F708[] = {0x0430, 0x0410, 0x0024, 0x0200, 0x0012, 0x0034, 0x0100, 0x0400, 0x0014, 0x0110};
//D:8003F71C
u16 dword_D_8003F71C[] = {0x0012, 0x0220, 0x0800, 0x0130, 0x0100, 0x0032, 0x0032, 0x0410, 0x0210, 0x0012};
//D:8003F730
u16 dword_D_8003F730[] = {0x0024, 0x0022, 0x0004, 0x0001, 0x0002, 0x0130, 0x0001, 0x0830, 0x0012, 0x0220};
//D:8003F744
u16 dword_D_8003F744[] = {0x0032, 0x0034, 0x0022, 0x0012, 0x0110, 0x0230, 0x0120, 0x0200, 0x0032, 0x0420};
//D:8003F758
u16 dword_D_8003F758[] = {0x0034, 0x0002, 0x0014, 0x0004, 0x0004, 0x0034, 0x0830, 0x0004, 0x0810, 0x0820};
//D:8003F76C
u16 dword_D_8003F76C[] = {0x0230, 0x0230, 0x0430, 0x0230, 0x0001, 0x0430, 0x0430, 0x0420, 0x0002, 0x0008};
//D:8003F780
u16 dword_D_8003F780[] = {0x0220, 0x0830, 0x0120, 0x0830, 0x0032, 0x0230, 0x0430, 0x0004, 0x0130, 0x0230};
//D:8003F794
u16 dword_D_8003F794[] = {0x0014, 0x0120, 0x0012, 0x0110, 0x0130, 0x0830, 0x0420, 0x0210, 0x0120, 0x0022};
//D:8003F7A8
u16 dword_D_8003F7A8[] = {0x0022, 0x0130, 0x0001, 0x0002, 0x0210, 0x0024, 0x0230, 0x0034, 0x0820, 0x0001};
//D:8003F7BC
u16 dword_D_8003F7BC[] = {0x0800, 0x0100, 0x0220, 0x0410, 0x0820, 0x0022, 0x0220, 0x0001, 0x0008, 0x0430};
//D:8003F7D0
u16 dword_D_8003F7D0[] = {0x0130, 0x0430, 0x0820, 0x0430, 0x0008, 0x0810, 0x0130, 0x0220, 0x0400, 0x0024};
//D:8003F7E4
u16 dword_D_8003F7E4[] = {0x0120, 0x0032, 0x0420, 0x0210, 0x0410, 0x0120, 0x0008, 0x0100, 0x0110, 0x0830};
//D:8003F7F8
u16 dword_D_8003F7F8[] = {0x0400, 0x0200, 0x0008, 0x0100, 0x0420, 0x0220};

//D:8003F804
u32 D_8003F804 = 0x8200002;
//D:8003F808
u32 D_8003F808 = 0x2000004;

/**
 * Address 0x8003F80C.
 */
struct CheatInfo g_CheatInfo[] = {
    {          CHEAT_EXTRA_MP_CHARS,  0xA, 0, 0, dword_D_8003F430,       0, 0,  /* 0x31 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_1},
    {           CHEAT_INVINCIBILITY,  0xA, 0, 0, dword_D_8003F444,  0xB000, 0,  /* 0x06 */ CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                 CHEAT_ALLGUNS,  0xA, 0, 0, dword_D_8003F458,  0xB001, 0,  /* 0x02 */ CHEAT_MASK_2},
    {                 CHEAT_MAXAMMO,  0xA, 0, 0, dword_D_8003F46C,       0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                           0x5,  0xA, 0, 0, dword_D_8003F480,       0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {CHEAT_DEACTIVATE_INVINCIBILITY,  0xA, 0, 0, dword_D_8003F494,       0, 0,  /* 0x34 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER},
    {                CHEAT_LINEMODE,  0xA, 0, 0, dword_D_8003F4A8,  0xB037, 0,  /* 0x66 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {               CHEAT_2X_HEALTH,    0, 0, 0,                0,       0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                CHEAT_2X_ARMOR,    0, 0, 0,                0,       0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {            CHEAT_INVISIBILITY,  0xA, 0, 0, dword_D_8003F4BC,  0xB004, 0,  /* 0x62 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_2},
    {           CHEAT_INFINITE_AMMO,    0, 0, 0,                0,  0xB006, 0,  /* 0x66 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                 CHEAT_DK_MODE,    0, 0, 0,                0,  0xB007, 0,  /* 0x26 */ CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {           CHEAT_EXTRA_WEAPONS,    0, 0, 0,                0,       0, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {               CHEAT_TINY_BOND,    0, 0, 0,                0,  0xB008, 0,  /* 0x02 */ CHEAT_MASK_2},
    {               CHEAT_PAINTBALL,    0, 0, 0,                0,  0xB038, 0,  /* 0x66 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {              CHEAT_10X_HEALTH,    0, 0, 0,                0,       0, 0,  /* 0x16 */ CHEAT_MASK_16 | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {                  CHEAT_MAGNUM,    0, 0, 0,                0,  0xB00A, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                   CHEAT_LASER,    0, 0, 0,                0,  0xB00B, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {              CHEAT_GOLDEN_GUN,    0, 0, 0,                0,  0xB00C, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {              CHEAT_SILVER_PP7,    0, 0, 0,                0,  0xB00D, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                CHEAT_GOLD_PP7,    0, 0, 0,                0,  0xB00E, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                          0x16,  0xA, 0, 0, dword_D_8003F4D0,       0, 0,  /* 0x12 */ CHEAT_MASK_MULTIPLAYER},
    {             CHEAT_NO_RADAR_MP,    0, 0, 0,                0,  0xB043, 0,  /* 0x64 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER},
    {              CHEAT_TURBO_MODE,    0, 0, 0,                0,  0xB040, 0,  /* 0x66 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_MULTIPLAYER | CHEAT_MASK_2},
    {               CHEAT_DEBUG_POS,    0, 0, 0,                0,       0, 0,  /* 0x20 */ CHEAT_MASK_GLOBAL},
    {          CHEAT_FAST_ANIMATION,    0, 0, 0,                0,  0xB041, 0,  /* 0x72 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_2},
    {          CHEAT_SLOW_ANIMATION,    0, 0, 0,                0,  0xB042, 0,  /* 0x72 */ CHEAT_MASK_64 | CHEAT_MASK_GLOBAL | CHEAT_MASK_16 | CHEAT_MASK_2},
    {           CHEAT_ENEMY_ROCKETS,    0, 0, 0,                0,  0xB039, 0,  /* 0x01 */ CHEAT_MASK_1},
    {      CHEAT_2X_ROCKET_LAUNCHER,    0, 0, 0,                0,  0xB03A, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {     CHEAT_2X_GRENADE_LAUNCHER,    0, 0, 0,                0,  0xB03B, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                CHEAT_2X_RCP90,    0, 0, 0,                0,  0xB03C, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {       CHEAT_2X_THROWING_KNIFE,    0, 0, 0,                0,  0xB03D, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {        CHEAT_2X_HUNTING_KNIFE,    0, 0, 0,                0,  0xB03E, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                CHEAT_2X_LASER,    0, 0, 0,                0,  0xB03F, 0,  /* 0x12 */ CHEAT_MASK_16 | CHEAT_MASK_2},
    {                          0x23,  0xA, 0, 0, dword_D_8003F67C,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x24,  0xA, 0, 0, dword_D_8003F690,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x25,  0xA, 0, 0, dword_D_8003F6A4,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x26,  0xA, 0, 0, dword_D_8003F6B8,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x27,  0xA, 0, 0, dword_D_8003F6CC,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x28,  0xA, 0, 0, dword_D_8003F6E0,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x29,  0xA, 0, 0, dword_D_8003F6F4,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2A,  0xA, 0, 0, dword_D_8003F708,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2B,  0xA, 0, 0, dword_D_8003F71C,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2C,  0xA, 0, 0, dword_D_8003F730,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2D,  0xA, 0, 0, dword_D_8003F744,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2E,  0xA, 0, 0, dword_D_8003F758,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x2F,  0xA, 0, 0, dword_D_8003F76C,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x30,  0xA, 0, 0, dword_D_8003F780,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x31,  0xA, 0, 0, dword_D_8003F794,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x32,  0xA, 0, 0, dword_D_8003F7A8,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x33,  0xA, 0, 0, dword_D_8003F7BC,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x34,  0xA, 0, 0, dword_D_8003F7D0,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x35,  0xA, 0, 0, dword_D_8003F7E4,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {           CHEAT_UNLOCK_CHEATS,  0xA, 0, 0, dword_D_8003F7F8,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x37,  0xA, 0, 0, dword_D_8003F4E4,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x38,  0xA, 0, 0, dword_D_8003F4F8,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x39,  0xA, 0, 0, dword_D_8003F50C,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3A,  0xA, 0, 0, dword_D_8003F520,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3B,  0xA, 0, 0, dword_D_8003F534,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3C,  0xA, 0, 0, dword_D_8003F548,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3D,  0xA, 0, 0, dword_D_8003F55C,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3E,  0xA, 0, 0, dword_D_8003F570,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x3F,  0xA, 0, 0, dword_D_8003F584,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x40,  0xA, 0, 0, dword_D_8003F598,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x41,  0xA, 0, 0, dword_D_8003F5AC,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x42,  0xA, 0, 0, dword_D_8003F5C0,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x43,  0xA, 0, 0, dword_D_8003F5D4,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x44,  0xA, 0, 0, dword_D_8003F5E8,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x45,  0xA, 0, 0, dword_D_8003F5FC,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x46,  0xA, 0, 0, dword_D_8003F610,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x47,  0xA, 0, 0, dword_D_8003F624,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x48,  0xA, 0, 0, dword_D_8003F638,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {                          0x49,  0xA, 0, 0, dword_D_8003F64C,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
    {           CHEAT_UNLOCK_STAGES,  0xA, 0, 0, dword_D_8003F660,       0, 0,  /* 0x11 */ CHEAT_MASK_16 | CHEAT_MASK_1},
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
        bitmask = 1;
    }
    else
    {
        bitmask = (getPlayerCount() == 1) ? 2 : 4;
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
                    if (g_CurrentPlayer->cheat_display_text_related[id_index] == info->anonymous_1[find_index])
                    {
                        id_index = (s32) (id_index + 1) % CHEAT_20;
                        continue;
                    }

                    break;
                }

                if (find_index == info->count_of_something)
                {
                    g_CurrentPlayer->can_display_cheat_text = 0;

                    if ((cheatCheckIfOn((s32) info->cheat_id) == 0) || ((info->maskfield & 0x10) != 0))
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB010));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB010));
#endif
                set_BONDdata_allguns_flag(1);
                return;
            }
            return;

        case CHEAT_MAXAMMO:
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB014));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB014));
#endif
                bondviewSetVisibleToGuardsFlag(0);
                return;
            }
            return;

        case CHEAT_INFINITE_AMMO:
#if defined(VERSION_JP)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB016));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB016));
#endif
            /**
            * Note: the lvlRender in lvl.c checks if infinite ammo is on then calls set_max_ammo_for_cur_player
            */
            return;

        case CHEAT_DK_MODE:
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01A));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB01A));
#endif
            return;

        case CHEAT_10X_HEALTH:
            if ((g_CurrentPlayer->actual_health == 1.0f) || (g_CurrentPlayer->bondhealth < 1.0f))
            {
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
                jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB020));
#else
                display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB020));
#endif
                bondviewSetVisibleToGuardsFlag(1);
                return;
            }
            return;

        case CHEAT_INFINITE_AMMO:
#if defined(VERSION_JP)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB022));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB022));
#endif
            return;
            
        case CHEAT_DK_MODE:
#if defined(VERSION_JP)
            jp_display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB023));
#else
            display_string_in_lower_left_corner((char *)get_textptr_for_textID(0xB023));
#endif
            cheatButtonSetDkMode(0);
            return;

        case CHEAT_TINY_BOND:
            if ((player_count == 1) && (g_playerPerm->player_perspective_height != 1.0f))
            {
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
#if defined(VERSION_JP)
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
    struct chrdata* guard = ptr_guard_data;

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