#include "ultra64.h"
#include "bondgame.h"
#include "ramrom.h"
#include "deb.h"
#include "str.h"
#include "memp.h"

/**
 * @file deb.c
 * This file contains debug related code. 
 * 
 * In particular, it seems to handle debug_notice_list
 */

struct entry
{
    u32 next;
    u32 data;
    const char *name;
    s32 var4;
};

/* bss */
extern char dword_CODE_bss_80060890[0x400];



/* data */
u32 D_800232E0[] = {0, 0};
struct entry *debug_notice_list[] = {NULL, NULL, NULL, NULL};
char * debug_notice_list_data = &dword_CODE_bss_80060890;

struct entry *debFind(const char *name)
{
    struct entry *entry = debug_notice_list[0];
    while (entry != NULL) {
        if (strcmp(entry->name, name) == 0) {
            return entry;
        }
        entry = entry->next; 
    }
    return NULL;
}

#ifdef NONMATCHING
// 5980:    lui     v0,0x8002                        r 5980:    lui     a1,0x8002
// 5984:    lw      v0,0x32f8(v0)                    r 5984:    lw      a1,0x32e8(a1)
// 5988:    lui     t6,0x8006                          5988:    lui     t6,0x8006
// 598c:    addiu   t6,t6,0xc90                      i 598c:    addiu   t6,t6,0xc80
// 5990:    move    v1,v0                            <
// 5994:    addu    v0,v0,a0                         r 5990:    addu    v1,a1,a0
// 5998:    addiu   sp,sp,-0x18                        5994:    addiu   sp,sp,-0x18
// 599c:    sltu    at,t6,v0                         r 5998:    sltu    at,t6,v1
// 59a0:    beqz    at,0x59c4 ~>                       599c:    beqz    at,0x59c0 ~>
// 59a4:    sw      ra,0x14(sp)                        59a0:    sw      ra,0x14(sp)
// 59a8:    subu    v0,v0,a0                         r 59a4:    subu    t7,v1,a0
// 59ac:    lui     at,0x8002                          59a8:    lui     at,0x8002
// 59b0:    sw      v0,0x32f8(at)                    r 59ac:    sw      t7,0x32e8(at)
// 59b4:    jal     0x9720                           i 59b0:    jal     0x9710
// 59b8:    li      a1,6                               59b4:    li      a1,6
// 59bc:    b       0x59d4 ~>                          59b8:    b       0x59d0 ~>
// 59c0:    lw      ra,0x14(sp)                        59bc:    lw      ra,0x14(sp)
// 59c4:    lui     at,0x8002                          59c0:    lui     at,0x8002
// 59c8:    sw      v0,0x32f8(at)                    r 59c4:    sw      v1,0x32e8(at)
// 59cc:    move    v0,v1                            r 59c8:    move    v0,a1
extern char tlbthread[0x6B0];
u32 debAllocate(u32 size)
{
    u32 temp_v0 = debug_notice_list_data;
    u32 temp_v0_2 = temp_v0 + size;
    if ((u32)&tlbthread < temp_v0_2) {
        debug_notice_list_data = (temp_v0_2 - size);
        return mempAllocBytesInBank(size, 6);
    }
    debug_notice_list_data = temp_v0_2;
    return temp_v0;
}
#else
u32 debAllocate(u32);
GLOBAL_ASM(
.text
glabel debAllocate
/* 005980 70004D80 3C028002 */  lui   $v0, %hi(debug_notice_list_data)
/* 005984 70004D84 8C4232F8 */  lw    $v0, %lo(debug_notice_list_data)($v0)
/* 005988 70004D88 3C0E8006 */  lui   $t6, %hi(tlbthread) 
/* 00598C 70004D8C 25CE0C90 */  addiu $t6, %lo(tlbthread) # addiu $t6, $t6, 0xc90
/* 005990 70004D90 00401825 */  move  $v1, $v0
/* 005994 70004D94 00441021 */  addu  $v0, $v0, $a0
/* 005998 70004D98 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00599C 70004D9C 01C2082B */  sltu  $at, $t6, $v0
/* 0059A0 70004DA0 10200008 */  beqz  $at, .L70004DC4
/* 0059A4 70004DA4 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0059A8 70004DA8 00441023 */  subu  $v0, $v0, $a0
/* 0059AC 70004DAC 3C018002 */  lui   $at, %hi(debug_notice_list_data)
/* 0059B0 70004DB0 AC2232F8 */  sw    $v0, %lo(debug_notice_list_data)($at)
/* 0059B4 70004DB4 0C0025C8 */  jal   mempAllocBytesInBank
/* 0059B8 70004DB8 24050006 */   li    $a1, 6
/* 0059BC 70004DBC 10000005 */  b     .L70004DD4
/* 0059C0 70004DC0 8FBF0014 */   lw    $ra, 0x14($sp)
.L70004DC4:
/* 0059C4 70004DC4 3C018002 */  lui   $at, %hi(debug_notice_list_data)
/* 0059C8 70004DC8 AC2232F8 */  sw    $v0, %lo(debug_notice_list_data)($at)
/* 0059CC 70004DCC 00601025 */  move  $v0, $v1
/* 0059D0 70004DD0 8FBF0014 */  lw    $ra, 0x14($sp)
.L70004DD4:
/* 0059D4 70004DD4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0059D8 70004DD8 03E00008 */  jr    $ra
/* 0059DC 70004DDC 00000000 */   nop   
)
#endif

void debAdd(const char *name, u32 data) {
    struct entry *entry = debAllocate(sizeof(struct entry));
    entry->next = (u32)debug_notice_list[0];
    entry->data = data;
    entry->name = name;
    debug_notice_list[0] = entry;
}

void debInit(void) {
    debCheckAddDebugNoticeListEntry(&D_800232E0, "deb_c_debug");
    init_tlb();
}

void debCheckAddDebugNoticeListEntry(void* data, const char *name) {
    if (debFind(name) == NULL) {
        debAdd(name, data);
    }
}

void deb70004E98(void) {
    struct entry *entry = debug_notice_list[0];
    while (entry != NULL) {
        // Removed
        entry = entry->next; 
    }
}

void deb70004EBC(void) {
    // Removed
}

void deb70004EC4(s32 arg0, s32 arg1, s32 arg2) {
    // Removed
}
