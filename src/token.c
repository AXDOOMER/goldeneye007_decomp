#include "ultra64.h"
#include "pi.h"
#include "snd.h"
#include "game/lvl_text.h"
#include "rmon.h"
#include "str.h"

u32 boot_token_from_indy[160];
s32 strstr_numstings = 1;
const char *strstr_ptrcurrent_string[35] = {0};

unsigned char *check_string_something(unsigned char *str)
{
    unsigned char c;
    strstr_ptrcurrent_string[0] = "";
    strstr_numstings = 1;
    while ((s32)*str) {
        while (*str == ' ') {
            *str++ = '\0';
        }
        strstr_ptrcurrent_string[strstr_numstings++] = str;
        while (*str > ' ') {
            str++; 
        }
    }
    return str;
}

void strtok(const char *arg0) {
    strcpy(&boot_token_from_indy, arg0);
    check_string_something(&boot_token_from_indy);
}

const char *check_token(s32 arg0, const char *str);
s32 check_boot_switches(void)
{
    u32 *data;
    u32* end;
    uintptr_t devAddr;
    s32 isDebug = 0;
    devAddr = 0xFFB000;
    if (rmon_debug_is_final_build()) {
        boot_token_from_indy[0] = 0;
    } else {
        for (data = boot_token_from_indy, end = (boot_token_from_indy + 160); data != end; data++) {
            osPiReadIo(devAddr, data);
            devAddr += sizeof(u32);
        }
    }
    check_string_something(boot_token_from_indy);

    if (check_token(1, "-d") != NULL) {
        isDebug = 1;
    }

    if (check_token(1, "-s") != NULL) {
        bootswitch_sound = 1;
    }

    if (check_token(1, "-j") != NULL) {
        j_text_trigger = 1;
    }

    return isDebug;
}

const char *check_token(s32 arg0, const char *str)
{
    s32 length = strlen(str);
    s32 i = 1;
    for (; i < strstr_numstings; i++) {
        if (strncmp(str, strstr_ptrcurrent_string[i], length) == 0) {
            if (--arg0 == 0) {
                return (strstr_ptrcurrent_string[i] + length);
            }
        }
    }
    return NULL;
}