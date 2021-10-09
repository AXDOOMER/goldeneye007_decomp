#include "ultra64.h"

#include "tlb_manage.h"

/**
 * @file unused_fp.c
 * Contains some floating point utility functions.
 * These methods are not referenced in the rest of the code base.
 * 
 * Split from deb_video.c, based on previous comment:
 * //maybe newfile, falls on 0 address and logically does different things.
 */

#define IEEE_FLOAT_FRACTION_BITMASK   0x7FFFFF
#define IEEE_FLOAT_FRACTION_BIT_COUNT       23
#define IEEE_FLOAT_EXPONENT_BITMASK 0x7F800000
#define IEEE_FLOAT_EXPONENT_BIT_COUNT        8
#define IEEE_FLOAT_SIGN_BITMASK     0x80000000
#define IEEE_FLOAT_SIGN_BIT_COUNT            1


/**
 * 6160	70005560
 *     V0= TRUE if F12 a normal single precision float
 *     accepts: F12= single-precision float
 */
s32 crashIsDouble(f32 value)
{
    u32 bits = *(u32*)&value;
    u32 fraction = bits & IEEE_FLOAT_FRACTION_BITMASK;
    u8 exponent = (u8)(bits >> IEEE_FLOAT_FRACTION_BIT_COUNT);
    
    return (fraction == 0) || (exponent != 0 && (exponent != 0xff));
}

/**
 * 61A4	700055A4
 *     V0= TRUE if A1 a normal single precision float; would have set result as short at A0
 *     accepts: A0=(unused) p->target, A1=single-precision float
 */
s32 crashPrintFloat(s32 index, f32 value)
{
    return crashIsDouble(value);
}

/**
 * 61C8	700055C8
 *     removed: set normality of single-precision floats A1, A2, A3, SP+10 in table at A0
 */
void crashPrint4Floats(s32 index, f32 value1, f32 value2, f32 value3, f32 value4)
{
    crashPrintFloat(index, value1);
    crashPrintFloat((index + 2), value2);
    crashPrintFloat((index + 4), value3);
    crashPrintFloat((index + 6), value4);

    return;
}

/**
 * 6228	70005628
 *     unconditional return
 */
void unused_fp_removed(void) {
    return;
}


