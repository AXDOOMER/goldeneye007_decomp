#ifndef _INDY_COMMANDS_H_
#define _INDY_COMMANDS_H_
#include "ultra64.h"

struct indy_resource_entry {
    u32 resourceID;
    s32 type;
    s32 size;
    s32 readsize;
    s32 writesize;
};

struct indy_resource_entry_type3 {
    struct indy_resource_entry entry;
    u8 strbuffer[256];
};

struct indy_resource_entry_type4 {
    struct indy_resource_entry entry;
    u32 data;
};

struct indy_resource_entry_type6 {
    struct indy_resource_entry entry;
    u32 data1;
    u32 data2;
};

struct indy_resource_entry_type7 {
    struct indy_resource_entry entry;
    u8 strbuffer[256];
    u32 size;
};

struct indy_resource_entry_type8 {
    struct indy_resource_entry entry;
    u32 data1;
    u32 data2;
    u32 size;
};

struct indy_resource_entry_typeF {
    struct indy_resource_entry entry;
    u8 strbuffer[256];
    u32 size;
    u8* hwaddress;
};

struct indy_resource_entry_type10 {
    struct indy_resource_entry entry;
    u32 data1;
    u32 data2;
    u32 data3;
};

struct indy_resource_entry_typeB {
    struct indy_resource_entry entry;
    u8 strbuffer[1024];
};

extern s32 indy_ready;

u32 postindyresourcecommand(struct indy_resource_entry *param_1,u32 param_2);

#endif
