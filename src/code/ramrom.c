#include "ultra64.h"

#define align_addr_zero(X) ((((X) + 0xF) | 0xF) ^ 0xF)
#define align_addr_even(X) (((X) | 1) ^ 1)

OSIoMesg memoryMesgMB;
OSMesg ptr_memorymsg;
OSMesgQueue memoryMesgQueue;


void creates_a_message_queue_for_memory(void) {
    osCreateMesgQueue(&memoryMesgQueue, &ptr_memorymsg, 1);
}


void read_bytes_from_hw_to_rdram(void *target, void *source, u32 size) {
    osInvalDCache(target, size);
    osPiStartDma(&memoryMesgMB, 0, 0, source, target, size, &memoryMesgQueue);
}

void receive_memoryMesg(void) {
    osRecvMesg(&memoryMesgQueue, 0, 1);
}

void load_bytes_from_hw_to_rdram(void *target, void *source, u32 size) {
    read_bytes_from_hw_to_rdram(target, source, size);
    receive_memoryMesg();
}

s32 load_ramrom_file(void *target, void *source, s32 length) {
    s32 sp18;
    s32 *sp1C;
    s32 *temp_t8;
    s32 *temp_v1;

    // Node 0
    temp_t8 = align_addr_even((s32)source);
    temp_v1 = (s32)source - (s32)temp_t8;
    sp1C = align_addr_zero((s32)target);
    sp18 = temp_v1;
    load_bytes_from_hw_to_rdram(sp1C, temp_t8, align_addr_zero((s32)temp_v1 + length));
    return ((s32)sp1C + sp18);
}

void write_rdram_to_hw(void *source, void *target, u32 size) {
    osWritebackDCache(source, size);
    osPiStartDma(&memoryMesgMB, 0, 1, target, source, size, &memoryMesgQueue);
}

void load_rdram_to_hw(void *source, void *target, u32 size) {
    write_rdram_to_hw(source, target, size);
    receive_memoryMesg();
}
