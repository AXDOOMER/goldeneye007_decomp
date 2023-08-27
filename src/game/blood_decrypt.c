#include "blood_decrypt.h"

// address 0x7F01CAE0 NTSC
u8 *decrypt_bleeding_animation_data(u8 *arg0, u8 arg1, u8 arg2, u8 *arg3, u8 *arg4)
{
    u8 var_a2;
    u8 var_a3;
    u8 temp_v0;
    u8 var_v1;
    u8 next;

    temp_v0 = *arg0++;
    *arg4 = temp_v0;

    do
    {
        s32 unused;
        var_v1 = *arg0++;
        unused = var_v1;
        
        var_a2 = 0xFF;

        if (var_v1 == 0xFF)
        {
            var_a3 = 0;
            for (var_v1 = *arg0++; var_v1 != 0xFF; var_a2 ^= 0xff, var_v1 = *arg0++ )
            {
                var_a3 += var_v1;

                while (var_v1-- > 0)
                {
                    *arg3++ = var_a2;
                }
            }
            
            while (var_a3++ < arg1)
            {
                *arg3++ = var_a2;
            }
            
            arg2--;
        }
        else
        {
            var_a3 = temp_v0 + (var_v1 & 0x1f);
            var_v1 = (var_v1 >> 5) + 1;
            arg2 -= var_v1;
            
            do
            {
                var_a2 = var_a3;
                while (var_a2-- > 0)
                {
                    *arg3++ = 0xff;
                }
                
                var_a2 = arg1 - var_a3;
                while (var_a2-- > 0)
                {
                    *arg3++ = 0;
                }
            } while (--var_v1 > 0);
        }
    } while (arg2 > 0);
    
    return arg0;
}




void sub_GAME_7F01CC94(u8* arg0, u16 arg1, u8* arg2)
{
    while (arg1-- > 0)
    {
        *arg2++ = (arg0[0] & 0xF0) | (arg0[1] >> 4);
        arg0 += 2;
    }
}

// Address 0x7F01CCEC NTSC
void sub_GAME_7F01CCEC(u8 *arg0, u8 arg1, u8 arg2, u8 *arg3, u8 arg4)
{
    s16 i;
    s16 j;

    u32 var_t0;
    u32 var_t1;
    
    s16 var_t5;

    s16 var_s4;

    u8 tempt9;

    for (i = 0; i < arg2; i++)
    {
        for (j = 0; j < arg1; j++)
        {
            var_t0 = 0;
            var_t1 = 0;
            
            var_t5 = ((i - arg4) < 0) ? 0 : (i - arg4);

            while ((((arg2 - 1) < (i + arg4)) ? (arg2 - 1) : (i + arg4)) >= var_t5)
            {
                var_s4 = ((j - arg4) < 0) ? 0 : (j - arg4);
                
                while ((((arg1 - 1) < (j + arg4)) ? (arg1 - 1) : (j + arg4)) >= var_s4)
                {
                    var_t1 += arg0[var_s4 + (var_t5 * arg1)];
                    
                    var_s4 += 1;
                    var_t0 += 1;
                }

                var_t5 += 1;
            }

            tempt9  = (u8) ((u32) ((var_t0 >> 1) + var_t1) / var_t0);
            arg3[j + (i * arg1)] = tempt9;
        }
    }
}



// Averages 4 pixel data, ending on "second" row.
// Address 0x7F01CEEC NTSC
// https://decomp.me/scratch/J5ivR 55% ... or 90%?
void sub_GAME_7F01CEEC(u8 *arg0, s32 arg1, u8 *arg2)
{
    s32 i;
    s32 j;

    arg0 += 0x61;
    arg2 += 0x61;

    for (i = 1; i < arg1 - 1; i++, arg2 += 2, arg0 += 2) {
        for (j = 1; j < 0x5f; j++, arg2++, arg0++) {
            *arg2 = (arg0[-1] + arg0[0] + arg0[-0x61] + arg0[-0x60] + 2) >> 2;
        }
    }
}



#ifdef NONMATCHING
// Averages 4 pixel data, ending on "first" row.
void sub_GAME_7F01D02C(u8*, s32, u8*) {

// implementation looks to be the same as sub_GAME_7F01CEEC, but with row look ahead instead of look behind.

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01D02C
/* 051B5C 7F01D02C 24A3FFFF */  addiu $v1, $a1, -1
/* 051B60 7F01D030 28610002 */  slti  $at, $v1, 2
/* 051B64 7F01D034 24840061 */  addiu $a0, $a0, 0x61
/* 051B68 7F01D038 24C60061 */  addiu $a2, $a2, 0x61
/* 051B6C 7F01D03C 14200049 */  bnez  $at, .L7F01D164
/* 051B70 7F01D040 24020001 */   li    $v0, 1
/* 051B74 7F01D044 2407005F */  li    $a3, 95
.L7F01D048:
/* 051B78 7F01D048 908E0060 */  lbu   $t6, 0x60($a0)
/* 051B7C 7F01D04C 908F0001 */  lbu   $t7, 1($a0)
/* 051B80 7F01D050 90990000 */  lbu   $t9, ($a0)
/* 051B84 7F01D054 90890061 */  lbu   $t1, 0x61($a0)
/* 051B88 7F01D058 01CFC021 */  addu  $t8, $t6, $t7
/* 051B8C 7F01D05C 03194021 */  addu  $t0, $t8, $t9
/* 051B90 7F01D060 01095021 */  addu  $t2, $t0, $t1
/* 051B94 7F01D064 254B0002 */  addiu $t3, $t2, 2
/* 051B98 7F01D068 000B6083 */  sra   $t4, $t3, 2
/* 051B9C 7F01D06C A0CC0000 */  sb    $t4, ($a2)
/* 051BA0 7F01D070 908E0002 */  lbu   $t6, 2($a0)
/* 051BA4 7F01D074 908D0061 */  lbu   $t5, 0x61($a0)
/* 051BA8 7F01D078 90980001 */  lbu   $t8, 1($a0)
/* 051BAC 7F01D07C 90880062 */  lbu   $t0, 0x62($a0)
/* 051BB0 7F01D080 01AE7821 */  addu  $t7, $t5, $t6
/* 051BB4 7F01D084 01F8C821 */  addu  $t9, $t7, $t8
/* 051BB8 7F01D088 03284821 */  addu  $t1, $t9, $t0
/* 051BBC 7F01D08C 252A0002 */  addiu $t2, $t1, 2
/* 051BC0 7F01D090 000A5883 */  sra   $t3, $t2, 2
/* 051BC4 7F01D094 A0CB0001 */  sb    $t3, 1($a2)
/* 051BC8 7F01D098 24050003 */  li    $a1, 3
/* 051BCC 7F01D09C 24C60002 */  addiu $a2, $a2, 2
/* 051BD0 7F01D0A0 24840002 */  addiu $a0, $a0, 2
.L7F01D0A4:
/* 051BD4 7F01D0A4 908C0060 */  lbu   $t4, 0x60($a0)
/* 051BD8 7F01D0A8 908D0001 */  lbu   $t5, 1($a0)
/* 051BDC 7F01D0AC 908F0000 */  lbu   $t7, ($a0)
/* 051BE0 7F01D0B0 90990061 */  lbu   $t9, 0x61($a0)
/* 051BE4 7F01D0B4 018D7021 */  addu  $t6, $t4, $t5
/* 051BE8 7F01D0B8 01CFC021 */  addu  $t8, $t6, $t7
/* 051BEC 7F01D0BC 03194021 */  addu  $t0, $t8, $t9
/* 051BF0 7F01D0C0 25090002 */  addiu $t1, $t0, 2
/* 051BF4 7F01D0C4 00095083 */  sra   $t2, $t1, 2
/* 051BF8 7F01D0C8 A0CA0000 */  sb    $t2, ($a2)
/* 051BFC 7F01D0CC 908C0002 */  lbu   $t4, 2($a0)
/* 051C00 7F01D0D0 908B0061 */  lbu   $t3, 0x61($a0)
/* 051C04 7F01D0D4 908E0001 */  lbu   $t6, 1($a0)
/* 051C08 7F01D0D8 90980062 */  lbu   $t8, 0x62($a0)
/* 051C0C 7F01D0DC 016C6821 */  addu  $t5, $t3, $t4
/* 051C10 7F01D0E0 01AE7821 */  addu  $t7, $t5, $t6
/* 051C14 7F01D0E4 01F8C821 */  addu  $t9, $t7, $t8
/* 051C18 7F01D0E8 27280002 */  addiu $t0, $t9, 2
/* 051C1C 7F01D0EC 00084883 */  sra   $t1, $t0, 2
/* 051C20 7F01D0F0 A0C90001 */  sb    $t1, 1($a2)
/* 051C24 7F01D0F4 908B0003 */  lbu   $t3, 3($a0)
/* 051C28 7F01D0F8 908A0062 */  lbu   $t2, 0x62($a0)
/* 051C2C 7F01D0FC 908D0002 */  lbu   $t5, 2($a0)
/* 051C30 7F01D100 908F0063 */  lbu   $t7, 0x63($a0)
/* 051C34 7F01D104 014B6021 */  addu  $t4, $t2, $t3
/* 051C38 7F01D108 018D7021 */  addu  $t6, $t4, $t5
/* 051C3C 7F01D10C 01CFC021 */  addu  $t8, $t6, $t7
/* 051C40 7F01D110 27190002 */  addiu $t9, $t8, 2
/* 051C44 7F01D114 00194083 */  sra   $t0, $t9, 2
/* 051C48 7F01D118 A0C80002 */  sb    $t0, 2($a2)
/* 051C4C 7F01D11C 908A0004 */  lbu   $t2, 4($a0)
/* 051C50 7F01D120 90890063 */  lbu   $t1, 0x63($a0)
/* 051C54 7F01D124 908C0003 */  lbu   $t4, 3($a0)
/* 051C58 7F01D128 908E0064 */  lbu   $t6, 0x64($a0)
/* 051C5C 7F01D12C 012A5821 */  addu  $t3, $t1, $t2
/* 051C60 7F01D130 016C6821 */  addu  $t5, $t3, $t4
/* 051C64 7F01D134 01AE7821 */  addu  $t7, $t5, $t6
/* 051C68 7F01D138 25F80002 */  addiu $t8, $t7, 2
/* 051C6C 7F01D13C 0018C883 */  sra   $t9, $t8, 2
/* 051C70 7F01D140 24A50004 */  addiu $a1, $a1, 4
/* 051C74 7F01D144 A0D90003 */  sb    $t9, 3($a2)
/* 051C78 7F01D148 24C60004 */  addiu $a2, $a2, 4
/* 051C7C 7F01D14C 14A7FFD5 */  bne   $a1, $a3, .L7F01D0A4
/* 051C80 7F01D150 24840004 */   addiu $a0, $a0, 4
/* 051C84 7F01D154 24420001 */  addiu $v0, $v0, 1
/* 051C88 7F01D158 24C60002 */  addiu $a2, $a2, 2
/* 051C8C 7F01D15C 1443FFBA */  bne   $v0, $v1, .L7F01D048
/* 051C90 7F01D160 24840002 */   addiu $a0, $a0, 2
.L7F01D164:
/* 051C94 7F01D164 03E00008 */  jr    $ra
/* 051C98 7F01D168 00000000 */   nop   
)
#endif


// Address 0x7F01D16C NTSC
void sub_GAME_7F01D16C(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3)
{
    s32 temp_lo;
    u32 temp_a0;
    u32 var_t2;
    u8 *var_t0;
    u8 *var_v1;
    u32 t1;

    temp_lo = arg1 * arg2;
    var_v1 = arg0;
    var_t0 = arg3;
    t1 = arg0 + temp_lo;
    var_t2 = arg0 + arg1;

    do
    {
        temp_a0 = var_t2;

        do
        {
            *var_t0 = *var_v1++;
            var_t2 += 1;
            var_t0 += arg2;
            
        } while ((u32) var_v1 < temp_a0);

        var_t0 = (var_t0 - (temp_lo)) + 1;
        
    } while ((u32) var_v1 < (u32) t1);
}



#ifdef NONMATCHING
void sub_GAME_7F01D1C0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01D1C0
/* 051CF0 7F01D1C0 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 051CF4 7F01D1C4 240C00FF */  li    $t4, 255
/* 051CF8 7F01D1C8 90880000 */  lbu   $t0, ($a0)
/* 051CFC 7F01D1CC 24840001 */  addiu $a0, $a0, 1
.L7F01D1D0:
/* 051D00 7F01D1D0 90890000 */  lbu   $t1, ($a0)
/* 051D04 7F01D1D4 24840001 */  addiu $a0, $a0, 1
/* 051D08 7F01D1D8 152C001A */  bne   $t1, $t4, .L7F01D244
/* 051D0C 7F01D1DC 240B00FF */   li    $t3, 255
/* 051D10 7F01D1E0 90890000 */  lbu   $t1, ($a0)
/* 051D14 7F01D1E4 240A0000 */  li    $t2, 0
/* 051D18 7F01D1E8 112C000C */  beq   $t1, $t4, .L7F01D21C
/* 051D1C 7F01D1EC 24840001 */   addiu $a0, $a0, 1
.L7F01D1F0:
/* 051D20 7F01D1F0 01495021 */  addu  $t2, $t2, $t1
/* 051D24 7F01D1F4 19200005 */  blez  $t1, .L7F01D20C
/* 051D28 7F01D1F8 2529FFFF */   addiu $t1, $t1, -1
.L7F01D1FC:
/* 051D2C 7F01D1FC A0EB0000 */  sb    $t3, ($a3)
/* 051D30 7F01D200 24E70001 */  addiu $a3, $a3, 1
/* 051D34 7F01D204 1D20FFFD */  bgtz  $t1, .L7F01D1FC
/* 051D38 7F01D208 2529FFFF */   addiu $t1, $t1, -1
.L7F01D20C:
/* 051D3C 7F01D20C 90890000 */  lbu   $t1, ($a0)
/* 051D40 7F01D210 396B00FF */  xori  $t3, $t3, 0xff
/* 051D44 7F01D214 152CFFF6 */  bne   $t1, $t4, .L7F01D1F0
/* 051D48 7F01D218 24840001 */   addiu $a0, $a0, 1
.L7F01D21C:
/* 051D4C 7F01D21C 0145082A */  slt   $at, $t2, $a1
/* 051D50 7F01D220 10200006 */  beqz  $at, .L7F01D23C
/* 051D54 7F01D224 254A0001 */   addiu $t2, $t2, 1
.L7F01D228:
/* 051D58 7F01D228 A0EB0000 */  sb    $t3, ($a3)
/* 051D5C 7F01D22C 24E70001 */  addiu $a3, $a3, 1
/* 051D60 7F01D230 0145082A */  slt   $at, $t2, $a1
/* 051D64 7F01D234 1420FFFC */  bnez  $at, .L7F01D228
/* 051D68 7F01D238 254A0001 */   addiu $t2, $t2, 1
.L7F01D23C:
/* 051D6C 7F01D23C 0BC074A7 */  j     .L7F01D29C
/* 051D70 7F01D240 24C6FFFF */   addiu $a2, $a2, -1

.L7F01D244:
/* 051D74 7F01D244 312A001F */  andi  $t2, $t1, 0x1f
/* 051D78 7F01D248 01485021 */  addu  $t2, $t2, $t0
/* 051D7C 7F01D24C 00094942 */  srl   $t1, $t1, 5
/* 051D80 7F01D250 25290001 */  addiu $t1, $t1, 1
/* 051D84 7F01D254 00C93023 */  subu  $a2, $a2, $t1
.L7F01D258:
/* 051D88 7F01D258 01405825 */  move  $t3, $t2
/* 051D8C 7F01D25C 19600005 */  blez  $t3, .L7F01D274
/* 051D90 7F01D260 256BFFFF */   addiu $t3, $t3, -1
.L7F01D264:
/* 051D94 7F01D264 A0EC0000 */  sb    $t4, ($a3)
/* 051D98 7F01D268 24E70001 */  addiu $a3, $a3, 1
/* 051D9C 7F01D26C 1D60FFFD */  bgtz  $t3, .L7F01D264
/* 051DA0 7F01D270 256BFFFF */   addiu $t3, $t3, -1
.L7F01D274:
/* 051DA4 7F01D274 00AA5823 */  subu  $t3, $a1, $t2
/* 051DA8 7F01D278 19600005 */  blez  $t3, .L7F01D290
/* 051DAC 7F01D27C 256BFFFF */   addiu $t3, $t3, -1
.L7F01D280:
/* 051DB0 7F01D280 A0E00000 */  sb    $zero, ($a3)
/* 051DB4 7F01D284 24E70001 */  addiu $a3, $a3, 1
/* 051DB8 7F01D288 1D60FFFD */  bgtz  $t3, .L7F01D280
/* 051DBC 7F01D28C 256BFFFF */   addiu $t3, $t3, -1
.L7F01D290:
/* 051DC0 7F01D290 2529FFFF */  addiu $t1, $t1, -1
/* 051DC4 7F01D294 1D20FFF0 */  bgtz  $t1, .L7F01D258
/* 051DC8 7F01D298 00000000 */   nop   
.L7F01D29C:
/* 051DCC 7F01D29C 1CC0FFCC */  bgtz  $a2, .L7F01D1D0
/* 051DD0 7F01D2A0 00801025 */   move  $v0, $a0
/* 051DD4 7F01D2A4 03E00008 */  jr    $ra
/* 051DD8 7F01D2A8 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif


