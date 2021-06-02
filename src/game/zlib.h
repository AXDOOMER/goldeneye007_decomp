#ifndef _ZLIB_H_
#define _ZLIB_H_
#include "ultra64.h"

extern u8 *rz_inbuf;
extern u8 *rz_outbuf;
extern u32 rz_inptr;
extern u32 rz_wp;
extern struct huft *rz_hlist;
struct huft {
	u8 e;                /* number of extra bits or operation */
	u8 b;                /* number of bits in this code or subcode */
	union {
		u16 n;            /* literal, length base, or distance base */
		struct huft *t;   /* pointer to next level of table */
	} v;
};
#endif
