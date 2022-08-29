#ifndef _OB_H_
#define _OB_H_
#include <ultra64.h>

struct resource_lookup_data_entry {
    s32 rom_size;
    s32 poolRemaining;
    s32 pc_size;
    s32 rom_remaining;
    u8 loaded_bank;
    u8 unk_11;
    u16 reserved;
};

struct fileentry {
    s32 index;
    char *filename;
    u8 *hw_address;
};

typedef enum FILELOADMETHOD
{
    FILELOADMETHOD_EXTRAMEM,
    FILELOADMETHOD_DEFAULT,
    FILELOADMETHOD_UNK2
};
void obBlankResourcesLoadedInBank(u8 i);
void obBlankResourcesInBank5(void);
u8* load_resource_index_to_buffer(s32 index,s32 param_2,u8 *ptrdata,u32 bytes);
void *load_rom_resource_index_to_membank(s32 index, s32 loadMethod, s32 size, u8 bank);
void  resource_load_from_indy(void *ptrdata, s32 bytes, struct fileentry *srcfile, struct resource_lookup_data_entry *lookupdata);
void  load_resource(void *ptrdata, s32 bytes, struct fileentry *srcfile, struct resource_lookup_data_entry *lookupdata);

#endif
