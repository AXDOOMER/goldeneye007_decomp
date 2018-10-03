#include "ultra64.h"

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


GLOBAL_ASM(
glabel load_ramrom_file
/* 006844 70005C44 00A03825 */  move  $a3, $a1
/* 006848 70005C48 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 00684C 70005C4C 34A50001 */  ori   $a1, $a1, 1
/* 006850 70005C50 38B80001 */  xori  $t8, $a1, 1
/* 006854 70005C54 AFA40030 */  sw    $a0, 0x30($sp)
/* 006858 70005C58 AFA60038 */  sw    $a2, 0x38($sp)
/* 00685C 70005C5C 00F81823 */  subu  $v1, $a3, $t8
/* 006860 70005C60 00663021 */  addu  $a2, $v1, $a2
/* 006864 70005C64 2484000F */  addiu $a0, $a0, 0xf
/* 006868 70005C68 348E000F */  ori   $t6, $a0, 0xf
/* 00686C 70005C6C 24C6000F */  addiu $a2, $a2, 0xf
/* 006870 70005C70 AFBF0014 */  sw    $ra, 0x14($sp)
/* 006874 70005C74 34C8000F */  ori   $t0, $a2, 0xf
/* 006878 70005C78 39C4000F */  xori  $a0, $t6, 0xf
/* 00687C 70005C7C AFA4001C */  sw    $a0, 0x1c($sp)
/* 006880 70005C80 3906000F */  xori  $a2, $t0, 0xf
/* 006884 70005C84 AFA30018 */  sw    $v1, 0x18($sp)
/* 006888 70005C88 0C001707 */  jal   load_bytes_from_hw_to_rdram
/* 00688C 70005C8C 03002825 */   move  $a1, $t8
/* 006890 70005C90 8FBF0014 */  lw    $ra, 0x14($sp)
/* 006894 70005C94 8FA30018 */  lw    $v1, 0x18($sp)
/* 006898 70005C98 8FA4001C */  lw    $a0, 0x1c($sp)
/* 00689C 70005C9C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0068A0 70005CA0 03E00008 */  jr    $ra
/* 0068A4 70005CA4 00831021 */   addu  $v0, $a0, $v1
)
/* target,source, size */
/* close but no cigar
s32 load_ramrom_file(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp18;
    s32 sp1C;
    s32 temp_t8;
    s32 temp_v1;

    // Node 0
    temp_t8 = ((arg1 | 1) ^ 1);
    temp_v1 = (arg1 - temp_t8);
    sp18 = temp_v1;
    sp1C = (((arg0 + 0xf) | 0xf) ^ 0xf);
    load_bytes_from_hw_to_rdram(sp1C, temp_t8, ((((temp_v1 + arg2) + 0xf) | 0xf) ^ 0xf));
    return (sp1C + sp18);
}
*/

void write_rdram_to_hw(void *source, void *target, u32 size) {
    osWritebackDCache(source, size);
    osPiStartDma(&memoryMesgMB, 0, 1, target, source, size, &memoryMesgQueue);
}

void load_rdram_to_hw(void *source, void *target, u32 size) {
    write_rdram_to_hw(source, target, size);
    receive_memoryMesg();
}
