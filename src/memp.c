#include "ultra64.h"
#include "memp.h"
#include "game/lvl_text.h"
/**
 * @file memp.c
 * This file contains code for memp.
 */

//bss
struct s_mempBANK memory_bank_ptrs[7];

//data
void *ptr_memp_c_debug_debug_notice_list = 0;
s32 needmemallocation = 0;
s32 D_80024408 = 0;
s32 D_8002440C = 0;
s32 D_80024410 = 0;

struct s_mempMVALS sdefaultmvals = {
    2, //D_80024414
    0, //mf
    4, //D_8002441C
    0x52, //ml
    6, //D_80024424
    0xF, //me
    0, //D_8002442C
    0
};

struct s_mempMEMSTARTS sdefaultmemstarts = {
    0, //bank1start
    0, //bank2start
    0, //bank3start
    0, //bank4start
    0, //bank5start
    0, //bank6start
    0  //bank7start
};






/**
 * 9F80	70009380
 *     V0=p->debug.notice.list entry for memp_c_debug
 */
void mempInitDebugNoticeList(void)
{
    debCheckAddDebugNoticeListEntry(&ptr_memp_c_debug_debug_notice_list, "memp_c_debug"); //should be "memp_c_debug"
}

void mempSetBankStarts(s_mempMVALS *starts);
const char *check_token(s32 arg0, const char *arg1);
long int strtol(const char *str, char **endptr, int base);
void mempCheckMemflagTokens(s32 bstart, s32 bsize)
{
    s_mempMVALS sp20;
    
    memory_bank_ptrs[0].bankstart = bstart;
    memory_bank_ptrs[0].bankend = bstart + bsize;
    
    sp20 = sdefaultmvals;

    if (check_token(1, "-mf")) {
        sp20.var2 = strtol(check_token(1, "-mf"), NULL, 0);
    }
    if (check_token(1, "-ml")) {
        sp20.var4 = strtol(check_token(1, "-ml"), NULL, 0);
    }
    if (check_token(1, "-me")) {
        sp20.var6 = strtol(check_token(1, "-me"), NULL, 0);
    }
    if (sp20.var6 == 0) {
        sp20.var2 = 0;
        sp20.var6 = ((j_text_trigger ? 308 : 296) * 1024);
        sp20.var4 = bsize - sp20.var6;
    }

    mempSetBankStarts(&sp20);
}

/**
 * A114	70009514
 *     initialize allocations using table A0
 *     accepts: A0=p->allocation sizes
 */
#ifdef NONMATCHING
void mempSetBankStarts(int *banks)
{
    int *piVar1;
    int right_l;
    longlong lVar2;
    longlong lVar3;
    int iVar4;
    int iVar5;
    s_memstarts *psVar6;
    s_memstarts *psVar7;
    s_memstarts bankstarts;
    undefined auStack4 [4];
    
    bankstarts.bank1start = sdefaultmemstarts.bank1start;
    bankstarts.bank2start = sdefaultmemstarts.bank2start;
    psVar6 = &bankstarts;
    bankstarts.bank3start = sdefaultmemstarts.bank3start;
    bankstarts.bank4start = sdefaultmemstarts.bank4start;
    bankstarts.bank5start = sdefaultmemstarts.bank5start;
    bankstarts.bank6start = sdefaultmemstarts.bank6start;
    bankstarts.bank7start = sdefaultmemstarts.bank7start;
    right_l = *banks;
    iVar4 = banks[1];
    while( true ) {
        (&bankstarts.bank1start)[right_l] = iVar4;
        right_l = banks[2];
        if (right_l == 0) break;
        iVar4 = banks[3];
        banks = banks + 2;
    }
    right_l = bankstarts.bank1start;
    do {
        piVar1 = &psVar6->bank2start;
        psVar6 = (s_memstarts *)&psVar6->bank2start;
        right_l = *piVar1 + right_l;
        psVar6->bank1start = right_l;
        iVar4 = bankstarts.bank7start;
    } while (psVar6 < (s_memstarts *)&bankstarts.bank7start);
    right_l = memory_bank_ptrs[0].bankend - memory_bank_ptrs[0].bankstart;
    lVar3 = (longlong)right_l;
    iVar5 = bankstarts.bank7start >> 0x1f;
    psVar6 = &bankstarts;
    do {
        lVar2 = __ll_mul((int)psVar6->bank1start >> 0x1f,psVar6->bank1start,right_l >> 0x1f,right_l)
        ;
        __ll_div((int)lVar2,(int)lVar3,iVar5,iVar4);
        psVar7 = (s_memstarts *)&psVar6->bank2start;
        psVar6->bank1start = (int)lVar3;
        psVar6 = psVar7;
    } while (psVar7 < (s_memstarts *)auStack4);
    psVar6 = &bankstarts;
    do {
        psVar7 = (s_memstarts *)&psVar6->bank2start;
        psVar6->bank1start = (psVar6->bank1start | 0xf) ^ 0xf;
        psVar6 = psVar7;
    } while (psVar7 < (s_memstarts *)auStack4);
    memory_bank_ptrs[1].bankstart = bankstarts.bank1start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[1].nextentry = 0;
    memory_bank_ptrs[1].bankend = bankstarts.bank2start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[2].bankstart = bankstarts.bank2start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[2].nextentry = 0;
    memory_bank_ptrs[2].bankend = bankstarts.bank3start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[3].bankstart = bankstarts.bank3start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[3].nextentry = 0;
    memory_bank_ptrs[3].bankend = bankstarts.bank4start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[4].bankstart = bankstarts.bank4start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[4].nextentry = 0;
    memory_bank_ptrs[4].bankend = bankstarts.bank5start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[5].bankstart = bankstarts.bank5start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[5].nextentry = 0;
    memory_bank_ptrs[5].bankend = bankstarts.bank6start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[6].bankstart = bankstarts.bank6start + memory_bank_ptrs[0].bankstart;
    memory_bank_ptrs[6].nextentry = 0;
    memory_bank_ptrs[6].bankend = bankstarts.bank7start + memory_bank_ptrs[0].bankstart;
}
#else
GLOBAL_ASM(
.text
glabel mempSetBankStarts
/* 00A114 70009514 27BDFF80 */  addiu $sp, $sp, -0x80
/* 00A118 70009518 3C0E8002 */  lui   $t6, %hi(sdefaultmemstarts) 
/* 00A11C 7000951C AFBF0024 */  sw    $ra, 0x24($sp)
/* 00A120 70009520 AFB30020 */  sw    $s3, 0x20($sp)
/* 00A124 70009524 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00A128 70009528 AFB10018 */  sw    $s1, 0x18($sp)
/* 00A12C 7000952C AFB00014 */  sw    $s0, 0x14($sp)
/* 00A130 70009530 25CE4434 */  addiu $t6, %lo(sdefaultmemstarts) # addiu $t6, $t6, 0x4434
/* 00A134 70009534 8DC10000 */  lw    $at, ($t6)
/* 00A138 70009538 27B20060 */  addiu $s2, $sp, 0x60
/* 00A13C 7000953C 3C138006 */  lui   $s3, %hi(memory_bank_ptrs)
/* 00A140 70009540 AE410000 */  sw    $at, ($s2)
/* 00A144 70009544 8DD90004 */  lw    $t9, 4($t6)
/* 00A148 70009548 00801025 */  move  $v0, $a0
/* 00A14C 7000954C 26733BB0 */  addiu $s3, %lo(memory_bank_ptrs) # addiu $s3, $s3, 0x3bb0
/* 00A150 70009550 AE590004 */  sw    $t9, 4($s2)
/* 00A154 70009554 8DC10008 */  lw    $at, 8($t6)
/* 00A158 70009558 27B00060 */  addiu $s0, $sp, 0x60
/* 00A15C 7000955C 27B1007C */  addiu $s1, $sp, 0x7c
/* 00A160 70009560 AE410008 */  sw    $at, 8($s2)
/* 00A164 70009564 8DD9000C */  lw    $t9, 0xc($t6)
/* 00A168 70009568 AE59000C */  sw    $t9, 0xc($s2)
/* 00A16C 7000956C 8DC10010 */  lw    $at, 0x10($t6)
/* 00A170 70009570 AE410010 */  sw    $at, 0x10($s2)
/* 00A174 70009574 8DD90014 */  lw    $t9, 0x14($t6)
/* 00A178 70009578 AE590014 */  sw    $t9, 0x14($s2)
/* 00A17C 7000957C 8DC10018 */  lw    $at, 0x18($t6)
/* 00A180 70009580 AE410018 */  sw    $at, 0x18($s2)
/* 00A184 70009584 8C830000 */  lw    $v1, ($a0)
/* 00A188 70009588 8C480004 */  lw    $t0, 4($v0)
.L7000958C:
/* 00A18C 7000958C 00034880 */  sll   $t1, $v1, 2
/* 00A190 70009590 02495021 */  addu  $t2, $s2, $t1
/* 00A194 70009594 AD480000 */  sw    $t0, ($t2)
/* 00A198 70009598 8C430008 */  lw    $v1, 8($v0)
/* 00A19C 7000959C 24420008 */  addiu $v0, $v0, 8
/* 00A1A0 700095A0 5460FFFA */  bnezl $v1, .L7000958C
/* 00A1A4 700095A4 8C480004 */   lw    $t0, 4($v0)
/* 00A1A8 700095A8 8E030000 */  lw    $v1, ($s0)
/* 00A1AC 700095AC 27A40078 */  addiu $a0, $sp, 0x78
.L700095B0:
/* 00A1B0 700095B0 8E0C0004 */  lw    $t4, 4($s0)
/* 00A1B4 700095B4 26100004 */  addiu $s0, $s0, 4
/* 00A1B8 700095B8 0204082B */  sltu  $at, $s0, $a0
/* 00A1BC 700095BC 01831021 */  addu  $v0, $t4, $v1
/* 00A1C0 700095C0 00401825 */  move  $v1, $v0
/* 00A1C4 700095C4 1420FFFA */  bnez  $at, .L700095B0
/* 00A1C8 700095C8 AE020000 */   sw    $v0, ($s0)
/* 00A1CC 700095CC 8E6D0008 */  lw    $t5, 8($s3)
/* 00A1D0 700095D0 8E780000 */  lw    $t8, ($s3)
/* 00A1D4 700095D4 8FA20078 */  lw    $v0, 0x78($sp)
/* 00A1D8 700095D8 27B00060 */  addiu $s0, $sp, 0x60
/* 00A1DC 700095DC 01B81823 */  subu  $v1, $t5, $t8
/* 00A1E0 700095E0 000377C3 */  sra   $t6, $v1, 0x1f
/* 00A1E4 700095E4 000247C3 */  sra   $t0, $v0, 0x1f
/* 00A1E8 700095E8 AFA80030 */  sw    $t0, 0x30($sp)
/* 00A1EC 700095EC AFAE0038 */  sw    $t6, 0x38($sp)
/* 00A1F0 700095F0 AFA3003C */  sw    $v1, 0x3c($sp)
/* 00A1F4 700095F4 AFA20034 */  sw    $v0, 0x34($sp)
.L700095F8:
/* 00A1F8 700095F8 8E050000 */  lw    $a1, ($s0)
/* 00A1FC 700095FC 8FA60038 */  lw    $a2, 0x38($sp)
/* 00A200 70009600 8FA7003C */  lw    $a3, 0x3c($sp)
/* 00A204 70009604 0C003B6A */  jal   __ll_mul
/* 00A208 70009608 000527C3 */   sra   $a0, $a1, 0x1f
/* 00A20C 7000960C 00402025 */  move  $a0, $v0
/* 00A210 70009610 00602825 */  move  $a1, $v1
/* 00A214 70009614 8FA60030 */  lw    $a2, 0x30($sp)
/* 00A218 70009618 0C003B53 */  jal   __ll_div
/* 00A21C 7000961C 8FA70034 */   lw    $a3, 0x34($sp)
/* 00A220 70009620 26100004 */  addiu $s0, $s0, 4
/* 00A224 70009624 0211082B */  sltu  $at, $s0, $s1
/* 00A228 70009628 1420FFF3 */  bnez  $at, .L700095F8
/* 00A22C 7000962C AE03FFFC */   sw    $v1, -4($s0)
/* 00A230 70009630 27B00060 */  addiu $s0, $sp, 0x60
/* 00A234 70009634 27A2007C */  addiu $v0, $sp, 0x7c
.L70009638:
/* 00A238 70009638 8E0B0000 */  lw    $t3, ($s0)
/* 00A23C 7000963C 26100004 */  addiu $s0, $s0, 4
/* 00A240 70009640 0202082B */  sltu  $at, $s0, $v0
/* 00A244 70009644 356C000F */  ori   $t4, $t3, 0xf
/* 00A248 70009648 398D000F */  xori  $t5, $t4, 0xf
/* 00A24C 7000964C 1420FFFA */  bnez  $at, .L70009638
/* 00A250 70009650 AE0DFFFC */   sw    $t5, -4($s0)
/* 00A254 70009654 8E660000 */  lw    $a2, ($s3)
/* 00A258 70009658 8FB80060 */  lw    $t8, 0x60($sp)
/* 00A25C 7000965C 8FAF0064 */  lw    $t7, 0x64($sp)
/* 00A260 70009660 3C018006 */  lui   $at, %hi(memory_bank_ptrs+0x14)
/* 00A264 70009664 03067021 */  addu  $t6, $t8, $a2
/* 00A268 70009668 AC2E3BC0 */  sw    $t6, %lo(memory_bank_ptrs+0x10)($at)
/* 00A26C 7000966C AC203BC4 */  sw    $zero, %lo(memory_bank_ptrs+0x14)($at)
/* 00A270 70009670 3C018006 */  lui   $at, %hi(memory_bank_ptrs+0x18)
/* 00A274 70009674 01E61021 */  addu  $v0, $t7, $a2
/* 00A278 70009678 AC223BC8 */  sw    $v0, %lo(memory_bank_ptrs+0x18)($at)
/* 00A27C 7000967C 8FA80068 */  lw    $t0, 0x68($sp)
/* 00A280 70009680 3C018006 */  lui   $at, %hi(memory_bank_ptrs+0x24)
/* 00A284 70009684 AC223BD0 */  sw    $v0, %lo(memory_bank_ptrs+0x20)($at)
/* 00A288 70009688 AC203BD4 */  sw    $zero, %lo(memory_bank_ptrs+0x24)($at)
/* 00A28C 7000968C 3C018006 */  lui   $at, %hi(memory_bank_ptrs+0x28)
/* 00A290 70009690 01064821 */  addu  $t1, $t0, $a2
/* 00A294 70009694 AC293BD8 */  sw    $t1, %lo(memory_bank_ptrs+0x28)($at)
/* 00A298 70009698 24070002 */  li    $a3, 2
/* 00A29C 7000969C 0007C900 */  sll   $t9, $a3, 4
/* 00A2A0 700096A0 02791021 */  addu  $v0, $s3, $t9
/* 00A2A4 700096A4 00075080 */  sll   $t2, $a3, 2
/* 00A2A8 700096A8 024A8021 */  addu  $s0, $s2, $t2
/* 00A2AC 700096AC 8E180008 */  lw    $t8, 8($s0)
/* 00A2B0 700096B0 8E0E000C */  lw    $t6, 0xc($s0)
/* 00A2B4 700096B4 8E0D0004 */  lw    $t5, 4($s0)
/* 00A2B8 700096B8 8E0F0010 */  lw    $t7, 0x10($s0)
/* 00A2BC 700096BC 8E0B0000 */  lw    $t3, ($s0)
/* 00A2C0 700096C0 03062021 */  addu  $a0, $t8, $a2
/* 00A2C4 700096C4 01C62821 */  addu  $a1, $t6, $a2
/* 00A2C8 700096C8 01A61821 */  addu  $v1, $t5, $a2
/* 00A2CC 700096CC 01E64021 */  addu  $t0, $t7, $a2
/* 00A2D0 700096D0 01666021 */  addu  $t4, $t3, $a2
/* 00A2D4 700096D4 AC480048 */  sw    $t0, 0x48($v0)
/* 00A2D8 700096D8 AC430020 */  sw    $v1, 0x20($v0)
/* 00A2DC 700096DC AC450038 */  sw    $a1, 0x38($v0)
/* 00A2E0 700096E0 AC450040 */  sw    $a1, 0x40($v0)
/* 00A2E4 700096E4 AC440028 */  sw    $a0, 0x28($v0)
/* 00A2E8 700096E8 AC440030 */  sw    $a0, 0x30($v0)
/* 00A2EC 700096EC AC400024 */  sw    $zero, 0x24($v0)
/* 00A2F0 700096F0 AC400034 */  sw    $zero, 0x34($v0)
/* 00A2F4 700096F4 AC400044 */  sw    $zero, 0x44($v0)
/* 00A2F8 700096F8 AC4C0010 */  sw    $t4, 0x10($v0)
/* 00A2FC 700096FC AC400014 */  sw    $zero, 0x14($v0)
/* 00A300 70009700 AC430018 */  sw    $v1, 0x18($v0)
/* 00A304 70009704 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00A308 70009708 8FB30020 */  lw    $s3, 0x20($sp)
/* 00A30C 7000970C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00A310 70009710 8FB10018 */  lw    $s1, 0x18($sp)
/* 00A314 70009714 8FB00014 */  lw    $s0, 0x14($sp)
/* 00A318 70009718 03E00008 */  jr    $ra
/* 00A31C 7000971C 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif



/**
 * A320	70009720
 *     V0=p->A0 bytes of memory allocated in bank A1; fries: AT,V0,V1,A0,A1,A2,A3,T0,T2,T5,T6,T7,T8,T9
 *     accepts: A0=size, A1=bank
 */
#ifdef NONMATCHING
u32 mempAllocBytesInBank(u32 bytes, u8 bank)
{
    s32 temp_v0_2;
    u32 next;
    while (TRUE) {
        if (memory_bank_ptrs[bank].nextentry == 0) {
            while (TRUE) {}
            needmemallocation = 1;
        }
        if (memory_bank_ptrs[bank].bankend < memory_bank_ptrs[bank].nextentry) {
            nulled_mempLoopAllMemBanks();
            while (TRUE) {}
        }
        if ((memory_bank_ptrs[bank].nextentry + bytes) >= memory_bank_ptrs[bank].bankend) {
            break;
        }
        if (memory_bank_ptrs[6].bankend >= (memory_bank_ptrs[6].nextentry + bytes)) {
            temp_v0_2 = needmemallocation;
            needmemallocation = 1;
            bank = 6;
            if (temp_v0_2 == 0) {
                continue;
            }        
        } else {
            nulled_mempLoopAllMemBanks();
            while (TRUE) {}
        }
    }

    next = memory_bank_ptrs[bank].nextentry;
    memory_bank_ptrs[bank].nextentry += bytes;
    memory_bank_ptrs[bank].data2 = next;

    return next;
}
#else
GLOBAL_ASM(
.text
glabel mempAllocBytesInBank
/* 00A320 70009720 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A324 70009724 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00A328 70009728 30A700FF */  andi  $a3, $a1, 0xff
/* 00A32C 7000972C 3C058006 */  lui   $a1, %hi(memory_bank_ptrs)
/* 00A330 70009730 3C0A8002 */  lui   $t2, %hi(needmemallocation) 
/* 00A334 70009734 254A4404 */  addiu $t2, %lo(needmemallocation) # addiu $t2, $t2, 0x4404
/* 00A338 70009738 24A53BB0 */  addiu $a1, %lo(memory_bank_ptrs) # addiu $a1, $a1, 0x3bb0
/* 00A33C 7000973C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A340 70009740 00803025 */  move  $a2, $a0
/* 00A344 70009744 0007C100 */  sll   $t8, $a3, 4
.L70009748:
/* 00A348 70009748 00B81821 */  addu  $v1, $a1, $t8
/* 00A34C 7000974C 8C620004 */  lw    $v0, 4($v1)
/* 00A350 70009750 14400006 */  bnez  $v0, .L7000976C
/* 00A354 70009754 00404025 */   move  $t0, $v0
/* 00A358 70009758 24190001 */  li    $t9, 1
/* 00A35C 7000975C 3C018002 */  lui   $at, %hi(needmemallocation)
/* 00A360 70009760 AC394404 */  sw    $t9, %lo(needmemallocation)($at)
.L70009764:
/* 00A364 70009764 1000FFFF */  b     .L70009764
/* 00A368 70009768 00000000 */   nop   
.L7000976C:
/* 00A36C 7000976C 8C640008 */  lw    $a0, 8($v1)
/* 00A370 70009770 00466821 */  addu  $t5, $v0, $a2
/* 00A374 70009774 0082082B */  sltu  $at, $a0, $v0
/* 00A378 70009778 50200006 */  beql  $at, $zero, .L70009794
/* 00A37C 7000977C 008D082B */   sltu  $at, $a0, $t5
/* 00A380 70009780 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 00A384 70009784 24070006 */   li    $a3, 6
.L70009788:
/* 00A388 70009788 1000FFFF */  b     .L70009788
/* 00A38C 7000978C 00000000 */   nop   
/* 00A390 70009790 008D082B */  sltu  $at, $a0, $t5
.L70009794:
/* 00A394 70009794 50200014 */  beql  $at, $zero, .L700097E8
/* 00A398 70009798 00466821 */   addu  $t5, $v0, $a2
/* 00A39C 7000979C 8CAF0064 */  lw    $t7, 0x64($a1)
/* 00A3A0 700097A0 8CAE0068 */  lw    $t6, 0x68($a1)
/* 00A3A4 700097A4 24070006 */  li    $a3, 6
/* 00A3A8 700097A8 01E6C021 */  addu  $t8, $t7, $a2
/* 00A3AC 700097AC 01D8082B */  sltu  $at, $t6, $t8
/* 00A3B0 700097B0 14200008 */  bnez  $at, .L700097D4
/* 00A3B4 700097B4 00000000 */   nop   
/* 00A3B8 700097B8 8D420000 */  lw    $v0, ($t2)
/* 00A3BC 700097BC 24190001 */  li    $t9, 1
/* 00A3C0 700097C0 AD590000 */  sw    $t9, ($t2)
/* 00A3C4 700097C4 5440FFE0 */  bnezl $v0, .L70009748
/* 00A3C8 700097C8 0007C100 */   sll   $t8, $a3, 4
/* 00A3CC 700097CC 1000FFDE */  b     .L70009748
/* 00A3D0 700097D0 0007C100 */   sll   $t8, $a3, 4
.L700097D4:
/* 00A3D4 700097D4 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 00A3D8 700097D8 00000000 */   nop   
.L700097DC:
/* 00A3DC 700097DC 1000FFFF */  b     .L700097DC
/* 00A3E0 700097E0 00000000 */   nop   
/* 00A3E4 700097E4 00466821 */  addu  $t5, $v0, $a2
.L700097E8:
/* 00A3E8 700097E8 AC6D0004 */  sw    $t5, 4($v1)
/* 00A3EC 700097EC AC68000C */  sw    $t0, 0xc($v1)
/* 00A3F0 700097F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A3F4 700097F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A3F8 700097F8 01001025 */  move  $v0, $t0
/* 00A3FC 700097FC 03E00008 */  jr    $ra
/* 00A400 70009800 00000000 */   nop   
)
#endif

#ifdef NONMATCHING
// Mostly regalloc
s32 mempAddEntryOfSizeToBank(u8* ptrdata, u32 newsize, u8 bank)
{
    s32 oldsize;
    s32 diffsize;
    
    if (needmemallocation && (ptrdata == (u8*)memory_bank_ptrs[6].data2)) {
        bank = 6;
    }

    if (memory_bank_ptrs[bank].nextentry == 0) {
        while(TRUE) {}
    }

    if (ptrdata != (u8*)memory_bank_ptrs[bank].data2) {
        return 2;
    }

    oldsize = (memory_bank_ptrs[bank].nextentry - memory_bank_ptrs[bank].data2);
    diffsize = (newsize - oldsize);

    if (diffsize <= 0) {
        memory_bank_ptrs[bank].nextentry += diffsize;
        return 1;
    }

    if (memory_bank_ptrs[bank].nextentry > memory_bank_ptrs[bank].bankend) {
        nulled_mempLoopAllMemBanks();
        while(TRUE) {}
    }

    if (memory_bank_ptrs[bank].nextentry + diffsize > memory_bank_ptrs[bank].bankend) {
        nulled_mempLoopAllMemBanks();
        while(TRUE) {}
    }
    
    memory_bank_ptrs[bank].nextentry += diffsize;
    
    return 1;
}
#else
GLOBAL_ASM(
.text
glabel mempAddEntryOfSizeToBank
/* 00A404 70009804 3C0F8002 */  lui   $t7, %hi(needmemallocation) 
/* 00A408 70009808 8DEF4404 */  lw    $t7, %lo(needmemallocation)($t7)
/* 00A40C 7000980C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A410 70009810 AFA60020 */  sw    $a2, 0x20($sp)
/* 00A414 70009814 30CE00FF */  andi  $t6, $a2, 0xff
/* 00A418 70009818 01C03025 */  move  $a2, $t6
/* 00A41C 7000981C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A420 70009820 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00A424 70009824 11E00006 */  beqz  $t7, .L70009840
/* 00A428 70009828 00803825 */   move  $a3, $a0
/* 00A42C 7000982C 3C188006 */  lui   $t8, %hi(memory_bank_ptrs+0x6C) 
/* 00A430 70009830 8F183C1C */  lw    $t8, %lo(memory_bank_ptrs+0x6C)($t8)
/* 00A434 70009834 14980002 */  bne   $a0, $t8, .L70009840
/* 00A438 70009838 00000000 */   nop   
/* 00A43C 7000983C 24060006 */  li    $a2, 6
.L70009840:
/* 00A440 70009840 3C0A8006 */  lui   $t2, %hi(memory_bank_ptrs) 
/* 00A444 70009844 254A3BB0 */  addiu $t2, %lo(memory_bank_ptrs) # addiu $t2, $t2, 0x3bb0
/* 00A448 70009848 0006C900 */  sll   $t9, $a2, 4
/* 00A44C 7000984C 032A2821 */  addu  $a1, $t9, $t2
/* 00A450 70009850 8CA40004 */  lw    $a0, 4($a1)
/* 00A454 70009854 54800004 */  bnezl $a0, .L70009868
/* 00A458 70009858 8CA6000C */   lw    $a2, 0xc($a1)
.L7000985C:
/* 00A45C 7000985C 1000FFFF */  b     .L7000985C
/* 00A460 70009860 00000000 */   nop   
/* 00A464 70009864 8CA6000C */  lw    $a2, 0xc($a1)
.L70009868:
/* 00A468 70009868 8FAB001C */  lw    $t3, 0x1c($sp)
/* 00A46C 7000986C 50E60004 */  beql  $a3, $a2, .L70009880
/* 00A470 70009870 00861023 */   subu  $v0, $a0, $a2
/* 00A474 70009874 1000001A */  b     .L700098E0
/* 00A478 70009878 24020002 */   li    $v0, 2
/* 00A47C 7000987C 00861023 */  subu  $v0, $a0, $a2
.L70009880:
/* 00A480 70009880 01621823 */  subu  $v1, $t3, $v0
/* 00A484 70009884 1C600004 */  bgtz  $v1, .L70009898
/* 00A488 70009888 00836021 */   addu  $t4, $a0, $v1
/* 00A48C 7000988C ACAC0004 */  sw    $t4, 4($a1)
/* 00A490 70009890 10000013 */  b     .L700098E0
/* 00A494 70009894 24020001 */   li    $v0, 1
.L70009898:
/* 00A498 70009898 8CA20008 */  lw    $v0, 8($a1)
/* 00A49C 7000989C 00836821 */  addu  $t5, $a0, $v1
/* 00A4A0 700098A0 0044082B */  sltu  $at, $v0, $a0
/* 00A4A4 700098A4 50200006 */  beql  $at, $zero, .L700098C0
/* 00A4A8 700098A8 004D082B */   sltu  $at, $v0, $t5
/* 00A4AC 700098AC 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 00A4B0 700098B0 24060006 */   li    $a2, 6
.L700098B4:
/* 00A4B4 700098B4 1000FFFF */  b     .L700098B4
/* 00A4B8 700098B8 00000000 */   nop   
/* 00A4BC 700098BC 004D082B */  sltu  $at, $v0, $t5
.L700098C0:
/* 00A4C0 700098C0 10200005 */  beqz  $at, .L700098D8
/* 00A4C4 700098C4 00837021 */   addu  $t6, $a0, $v1
/* 00A4C8 700098C8 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 00A4CC 700098CC 24060006 */   li    $a2, 6
.L700098D0:
/* 00A4D0 700098D0 1000FFFF */  b     .L700098D0
/* 00A4D4 700098D4 00000000 */   nop   
.L700098D8:
/* 00A4D8 700098D8 ACAE0004 */  sw    $t6, 4($a1)
/* 00A4DC 700098DC 24020001 */  li    $v0, 1
.L700098E0:
/* 00A4E0 700098E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A4E4 700098E4 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A4E8 700098E8 03E00008 */  jr    $ra
/* 00A4EC 700098EC 00000000 */   nop   
)
#endif



/**
 * A4F0	700098F0
 *     V0=8 -- loop eight times, needlessly; fries AT,T6
 *     used by "show mem use", step 1; probably originally listed all eight memory allocations
 */

void nulled_mempLoopAllMemBanks(void)
{
    u8 bank;
    for (bank = 1; bank < 7; bank++)
    {
        ;
    };
}

/**
 * A510	70009910
 *     V0= total allocated size of bank A0
 *     accepts: A0=bank#
 */
s32 mempGetBankSizeLeft(u8 bank)
{
    if (needmemallocation != 0) {
        bank = 6;
    }
    if ((bank == 4) && (memory_bank_ptrs[4].bankstart == memory_bank_ptrs[4].bankend)) {
        bank = 6;
    }
    return memory_bank_ptrs[bank].bankend - memory_bank_ptrs[bank].nextentry;
}





/**
 * A570	70009970
 *     allocate A0 coded #bytes in bank
 *     accepts: A0=size/bank# entry (ssssssss ssssssss sssssssss sssssbbb)
 */

u32 mempAllocPackedBytesInBank(u32 param_1)
{
    return mempAllocBytesInBank((param_1 >> 3),(param_1 & 7));
}




/**
 * A59C	7000999C
 *     reset memory bank A0 [0-6]
 *     copies base address for memory bank A0 to +4, fry +C
 */
void mempResetBank(u8 bank)
{
    memory_bank_ptrs[bank].data2 = 0;
    memory_bank_ptrs[bank].nextentry = memory_bank_ptrs[bank].bankstart;
}

/**
 * A5C4	700099C4
 *     accepts: A0=bank#
 */
void mempNullNextEntryInBank(u8 bank)
{
    nulled_mempLoopAllMemBanks();
    if (memory_bank_ptrs[bank].nextentry != 0) {
        memory_bank_ptrs[bank].nextentry = 0;
    }
}
