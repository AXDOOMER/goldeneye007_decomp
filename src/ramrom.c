#include "ultra64.h"
#include "ramrom.h"

#define align_addr_zero(X) ((((X) + 0xF) | 0xF) ^ 0xF)
#define align_addr_even(X) (((X) | 1) ^ 1)

OSIoMesg memoryMesgMB;
OSMesg memoryMesg;
OSMesgQueue memoryMesgQueue;

/* external */
/* romCreateMesgQueue */
/* creates a message queue */
void romCreateMesgQueue(void) {
    osCreateMesgQueue(&memoryMesgQueue, &memoryMesg, 1);
}


/* doRomCopy*/
/* invalidate cache and do pi dma */
void doRomCopy(void *target, void *source, u32 size) {
    osInvalDCache(target, size);
    osPiStartDma(&memoryMesgMB, 0, 0, source, target, size, &memoryMesgQueue);
}

/* romReceiveMesg */
/* receives a message queue */
void romReceiveMesg(void) {
    osRecvMesg(&memoryMesgQueue, 0, 1);
}

/* external */
/* romCopy */
/* copy from rom to ram */
void romCopy(void *target, void *source, u32 size) {
    doRomCopy(target, source, size);
    romReceiveMesg();
}

/* external */
/* romCopyAligned */
/* aligns data, does a romCopy(), then returns aligned pointer to target */
s32 romCopyAligned(void *target, void *source, s32 length) {
    s32 target_offset;
    s32 *target_aligned;
    s32 *source_aligned;
    s32 *source_offset;

    source_aligned = align_addr_even((s32)source);
    source_offset = (s32)source - (s32)source_aligned;
    target_aligned = align_addr_zero((s32)target);
    target_offset = source_offset;
    romCopy(target_aligned, source_aligned, align_addr_zero((s32)source_offset + length));
    return ((s32)target_aligned + target_offset);
}

/* doRomWrite*/
/* actually writes to rom (buffer on Indy) */
void doRomWrite(void *source, void *target, u32 size) {
    osWritebackDCache(source, size);
    osPiStartDma(&memoryMesgMB, 0, 1, target, source, size, &memoryMesgQueue);
}

/* external */
/* romWrite */
/* let's write to the rom (buffer on Indy) */
void romWrite(void *source, void *target, u32 size) {
    doRomWrite(source, target, size);
    romReceiveMesg();
}
