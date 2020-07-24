#include "ultra64.h"
#include "game/mp_weapon.h"

// data
//D:80048670
struct s_mp_weapon_set mp_weapon_set_slaps[] = {
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1},
    {0, 0xCD, 1.0, 1, 0, 1}
};

//D:80048730
struct s_mp_weapon_set mp_weapon_set_pistols[] = {
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1}
};

//D:800487F0
struct s_mp_weapon_set mp_weapon_set_knife[] = {
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0},
    {3, 0xD1, 1.0, 0xA, 0xA, 0}
};

//D:800488B0
struct s_mp_weapon_set mp_weapon_set_auto[] = {
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {6, 0xCD, 1.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {0xA, 0xBD, 1.0, 1, 0x64, 1},
    {0xA, 0xBD, 1.0, 1, 0x64, 1}
};

//D:80048970
struct s_mp_weapon_set mp_weapon_set_power[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {0xE, 0xC5, 1.0, 1, 0x64, 1},
    {0xE, 0xC5, 1.0, 1, 0x64, 1},
    {0x10, 0xCF, 1.0, 4, 0x1E, 1},
    {0x10, 0xCF, 1.0, 4, 0x1E, 1}
};

//D:80048A30
struct s_mp_weapon_set mp_weapon_set_sniper[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {0x12, 0xBE, 1.0, 0xC, 0x32, 1},
    {7, 0xC1, 1.0, 1, 0x64, 1},
    {7, 0xC1, 1.0, 1, 0x64, 1},
    {0x11, 0xD2, 1.0, 3, 0x32, 1},
    {0x11, 0xD2, 1.0, 3, 0x32, 1}
};

//D:80048AF0
struct s_mp_weapon_set mp_weapon_set_grenade[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {0x1A, 0xC4, 1.5, 5, 5, 0},
    {0x1A, 0xC4, 1.5, 5, 5, 0}
};

//D:80048BB0
#ifdef VERSION_US
struct s_mp_weapon_set mp_weapon_set_remote_m[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xB8, 1.5, 3, 0x64, 1},
    {0xD, 0xB8, 1.5, 3, 0x64, 1},
    {0x1D, 0xC7, 1.5, 7, 5, 0},
    {0x1D, 0xC7, 1.5, 7, 5, 0}
};
#endif
#ifdef VERSION_EU
//!FIXME temp copy of us data
struct s_mp_weapon_set mp_weapon_set_remote_m[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0x1D, 0xC7, 1.5, 7, 5, 0},
    {0x1D, 0xC7, 1.5, 7, 5, 0}
};
#endif
#ifdef VERSION_JP
struct s_mp_weapon_set mp_weapon_set_remote_m[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0x1D, 0xC7, 1.5, 7, 5, 0},
    {0x1D, 0xC7, 1.5, 7, 5, 0}
};
#endif

//D:80048C70
struct s_mp_weapon_set mp_weapon_set_glaunch[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {0x18, 0xB9, 1.0, 0xB, 6, 1},
    {0x18, 0xB9, 1.0, 0xB, 6, 1}
};

//D:80048D30
#ifdef VERSION_US
struct s_mp_weapon_set mp_weapon_set_timed_m[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xB8, 1.5, 3, 0x64, 1},
    {0xD, 0xB8, 1.5, 3, 0x64, 1},
    {0x1B, 0xC9, 1.5, 9, 5, 0},
    {0x1B, 0xC9, 1.5, 9, 5, 0}
};
#endif
#ifdef VERSION_EU
//!FIXME temp copy of us data
struct s_mp_weapon_set mp_weapon_set_timed_m[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0x1B, 0xC9, 1.5, 9, 5, 0},
    {0x1B, 0xC9, 1.5, 9, 5, 0}
};
#endif
#ifdef VERSION_JP
struct s_mp_weapon_set mp_weapon_set_timed_m[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0x1B, 0xC9, 1.5, 9, 5, 0},
    {0x1B, 0xC9, 1.5, 9, 5, 0}
};
#endif

//D:80048DF0 
struct s_mp_weapon_set mp_weapon_set_prox_m[] = {
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {4, 0xBF, 3.0, 1, 0x32, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {9, 0xC3, 1.5, 1, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0xD, 0xBC, 1.5, 3, 0x64, 1},
    {0x1C, 0xC8, 1.5, 8, 5, 0},
    {0x1C, 0xC8, 1.5, 8, 5, 0}
};

//D:80048EB0
struct s_mp_weapon_set mp_weapon_set_rockets[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {0x19, 0xD3, 1.5, 6, 6, 1},
    {0x19, 0xD3, 1.5, 6, 6, 1}
};

//D:80048F70
struct s_mp_weapon_set mp_weapon_set_lasers[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {0x16, 0xBB, 1.5, 0, 0, 1},
    {0x16, 0xBB, 1.5, 0, 0, 1}
};

//D:80049030
struct s_mp_weapon_set mp_weapon_set_golden[] = {
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {6, 0xCD, 3.0, 1, 0x32, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {7, 0xC1, 1.5, 1, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {8, 0xB8, 1.5, 3, 0x64, 1},
    {5, 0xCC, 1.0, 1, 0x32, 1},
    {0x13, 0xD0, 1.5, 0xD, 0xA, 1}
};

//D:800490F0
struct struct_8 mp_weapon_set_text_table[] = {
    {0xA8, 0, 0, 0, mp_weapon_set_slaps},
    {0xA8, 1, 0, 0, mp_weapon_set_pistols},
    {0xA8, 0xD, 0, 0, mp_weapon_set_knife},
    {0xA8, 2, 0, 0, mp_weapon_set_auto},
    {0xA8, 3, 0, 0, mp_weapon_set_power},
    {0xA8, 4, 0, 0, mp_weapon_set_sniper},
    {0xA8, 5, 0, 0, mp_weapon_set_grenade},
    {0xA8, 6, 0, 0, mp_weapon_set_remote_m},
    {0xA8, 7, 0, 0, mp_weapon_set_glaunch},
    {0xA8, 8, 0, 0, mp_weapon_set_timed_m},
    {0xA8, 9, 0, 0, mp_weapon_set_prox_m},
    {0xA8, 0xA, 0, 0, mp_weapon_set_rockets},
    {0xA8, 0xB, 0, 0, mp_weapon_set_lasers},
    {0xA8, 0xC, 0, 0, mp_weapon_set_golden}
};

s32 mp_weapon_set = 0xB;



void advance_mp_weapon_set_by_one_save_value(void)
{
    mp_weapon_set = (mp_weapon_set + 1) % 0xe;
}

struct struct_8 *get_ptr_current_mp_weapon_set_text_code(void) {
    return &mp_weapon_set_text_table[mp_weapon_set];
}

struct s_mp_weapon_set * get_ptr_mp_weapon_set_data(void) {
    return mp_weapon_set_text_table[mp_weapon_set].anonymous_1;
}

void set_mp_weapon_set(s32 arg0) {
    mp_weapon_set = arg0;
}

s32 get_mp_weapon_set(void) {
    return mp_weapon_set;
}





