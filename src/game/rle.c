#include <ultra64.h>



#ifdef NONMATCHING
void rle_expand_8bit(void *src, u8 *dst)
{
    u8 *p;
    u16 w;
    u16 h;
    u32 remaining;
    u8 *run;
    u8 count;
    u8 value;
    u32 i;

    p = (u8 *)src;
    w = *(u16 *)(p + 0);
    h = *(u16 *)(p + 2);
    remaining = (u32)w * (u32)h;
    run = p + 0xA;

    while (remaining > 0) {
        count = run[0];
        value = run[1];
        run += 2;
        remaining -= (u32)count;
        i = (u32)count;
        while (i > 0) {
            *dst++ = value;
            i--;
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel rle_expand_8bit
/* 04FC10 7F01B0E0 94820000 */  lhu   $v0, ($a0)
/* 04FC14 7F01B0E4 94830002 */  lhu   $v1, 2($a0)
/* 04FC18 7F01B0E8 2487000A */  addiu $a3, $a0, 0xa
/* 04FC1C 7F01B0EC 00430019 */  multu $v0, $v1
/* 04FC20 7F01B0F0 00003012 */  mflo  $a2
/* 04FC24 7F01B0F4 00000000 */  nop   
/* 04FC28 7F01B0F8 00000000 */  nop   
/* 04FC2C 7F01B0FC 90E20000 */  lbu   $v0, ($a3)
.L7F01B100:
/* 04FC30 7F01B100 90E30001 */  lbu   $v1, 1($a3)
/* 04FC34 7F01B104 24E70002 */  addiu $a3, $a3, 2
/* 04FC38 7F01B108 00C23023 */  subu  $a2, $a2, $v0
/* 04FC3C 7F01B10C 2442FFFF */  addiu $v0, $v0, -1
.L7F01B110:
/* 04FC40 7F01B110 0002202A */  slt   $a0, $zero, $v0
/* 04FC44 7F01B114 2442FFFF */  addiu $v0, $v0, -1
/* 04FC48 7F01B118 A0A30000 */  sb    $v1, ($a1)
/* 04FC4C 7F01B11C 1480FFFC */  bnez  $a0, .L7F01B110
/* 04FC50 7F01B120 24A50001 */   addiu $a1, $a1, 1
/* 04FC54 7F01B124 5CC0FFF6 */  bgtzl $a2, .L7F01B100
/* 04FC58 7F01B128 90E20000 */   lbu   $v0, ($a3)
/* 04FC5C 7F01B12C 03E00008 */  jr    $ra
/* 04FC60 7F01B130 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void rle_expand_rgb_to_u16_5551(void *src, u16 *dst)
{
    u8 *p;
    u16 w;
    u16 h;
    u32 remaining;
    u8 *run;
    u8 count;
    u8 c1;
    u8 c2;
    u8 c3;
    u16 packed;
    u32 i;

    p = (u8 *)src;
    w = *(u16 *)(p + 0);
    h = *(u16 *)(p + 2);
    remaining = (u32)w * (u32)h;
    run = p + 0xA;

    while (remaining > 0) {
        count = run[0];
        c1 = run[1];
        c2 = run[2];
        c3 = run[3];
        run += 4;
        remaining -= (u32)count;

        packed = (u16)((((u32)(c3 >> 3)) << 11) |
                       (((u32)(c2 >> 3)) << 6) |
                       (((u32)(c1 >> 3)) << 1) |
                       1u);
        i = (u32)count;
        while (i > 0) {
            *dst++ = packed;
            i--;
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel rle_expand_rgb_to_u16_5551
/* 04FC64 7F01B134 27BDFFF8 */  addiu $sp, $sp, -8
/* 04FC68 7F01B138 AFB00004 */  sw    $s0, 4($sp)
/* 04FC6C 7F01B13C 94820000 */  lhu   $v0, ($a0)
/* 04FC70 7F01B140 94830002 */  lhu   $v1, 2($a0)
/* 04FC74 7F01B144 00A08025 */  move  $s0, $a1
/* 04FC78 7F01B148 2487000A */  addiu $a3, $a0, 0xa
/* 04FC7C 7F01B14C 00430019 */  multu $v0, $v1
/* 04FC80 7F01B150 00003012 */  mflo  $a2
/* 04FC84 7F01B154 00000000 */  nop   
/* 04FC88 7F01B158 00000000 */  nop   
/* 04FC8C 7F01B15C 90E40002 */  lbu   $a0, 2($a3)
.L7F01B160:
/* 04FC90 7F01B160 90E50003 */  lbu   $a1, 3($a3)
/* 04FC94 7F01B164 90E30001 */  lbu   $v1, 1($a3)
/* 04FC98 7F01B168 0004C0C3 */  sra   $t8, $a0, 3
/* 04FC9C 7F01B16C 000570C3 */  sra   $t6, $a1, 3
/* 04FCA0 7F01B170 90E20000 */  lbu   $v0, ($a3)
/* 04FCA4 7F01B174 000E7AC0 */  sll   $t7, $t6, 0xb
/* 04FCA8 7F01B178 0018C980 */  sll   $t9, $t8, 6
/* 04FCAC 7F01B17C 000350C3 */  sra   $t2, $v1, 3
/* 04FCB0 7F01B180 000A5840 */  sll   $t3, $t2, 1
/* 04FCB4 7F01B184 01F94825 */  or    $t1, $t7, $t9
/* 04FCB8 7F01B188 012B4025 */  or    $t0, $t1, $t3
/* 04FCBC 7F01B18C 350C0001 */  ori   $t4, $t0, 1
/* 04FCC0 7F01B190 00C23023 */  subu  $a2, $a2, $v0
/* 04FCC4 7F01B194 24E70004 */  addiu $a3, $a3, 4
/* 04FCC8 7F01B198 01804025 */  move  $t0, $t4
/* 04FCCC 7F01B19C 2442FFFF */  addiu $v0, $v0, -1
.L7F01B1A0:
/* 04FCD0 7F01B1A0 0002182A */  slt   $v1, $zero, $v0
/* 04FCD4 7F01B1A4 2442FFFF */  addiu $v0, $v0, -1
/* 04FCD8 7F01B1A8 A6080000 */  sh    $t0, ($s0)
/* 04FCDC 7F01B1AC 1460FFFC */  bnez  $v1, .L7F01B1A0
/* 04FCE0 7F01B1B0 26100002 */   addiu $s0, $s0, 2
/* 04FCE4 7F01B1B4 5CC0FFEA */  bgtzl $a2, .L7F01B160
/* 04FCE8 7F01B1B8 90E40002 */   lbu   $a0, 2($a3)
/* 04FCEC 7F01B1BC 8FB00004 */  lw    $s0, 4($sp)
/* 04FCF0 7F01B1C0 03E00008 */  jr    $ra
/* 04FCF4 7F01B1C4 27BD0008 */   addiu $sp, $sp, 8
)
#endif

/**
 * Decode RLE-compressed RGB data into RGBA32.
 */
void rle_expand_rgb_to_rgba32(u8 *src, u8 *dst)
{
    u8 *in;
    u8 *out;
    s32 remaining;
    s32 count;
    u8 r, g, b;
    u16 w, h;
    
    out = dst;
    w = *(u16 *)&src[0];
    h = *(u16 *)&src[2];
    remaining = w * h;
    in = &src[10]; // Start of RLE stream.

    do {
        count = in[0];
        r = in[1];
        g = in[2];
        remaining -= count;
        b = in[3];
        in += 4;
        count--;
        do {
            out[0] = b;
            out[1] = g;
            out[2] = r;
            out[3] = 0xFF; 
            out += 4;
        } while (count-- > 0);
    } while (remaining > 0);
}