#include <ultra64.h>
#include "zlib.h"

#define GETBYTE()   (rz_inbuf[rz_inptr++])
#define NEXTBYTE()  (u8)GETBYTE()
#define NEEDBITS(n) {while(k<(n)){b|=((u32)NEXTBYTE())<<k;k+=8;}}
#define DUMPBITS(n) {b>>=(n);k-=(n);}

#define BMAX 16
#define N_MAX 288

//.bss

//bss:8008D350
u8 *rz_inbuf;
//bss:8008D354
u8 *rz_outbuf;
//bss:8008D358
u32 rz_inptr;
//bss:8008D35C
u32 rz_wp;
//bss:8008D360
struct huft *rz_hlist;
//bss:8008D364
u32 rz_bb;
//bss:8008D368
u32 rz_bk;
//bss:8008D36C
u32 rz_hufts;


//.data
u8 rz_border[] = {
    0x10,0x11,0x12,   0,   8,   7,   9,   6, 0xA,   5, 0xB,   4, 0xC,   3,
    0xD,   2, 0xE,   1, 0xF,   0
};

s16 rz_cplens[] = {
    3,     4,     5,     6,     7,     8,     9,   0xA,   0xB,   0xD,
    0xF,  0x11,  0x13,  0x17,  0x1B,  0x1F,  0x23,  0x2B,  0x33,  0x3B,
    0x43,  0x53,  0x63,  0x73,  0x83,  0xA3,  0xC3,  0xE3, 0x102,     0,
   0,     0
};

u32 rz_cplext[] = {
    0, 0, 0x1010101, 0x2020202, 0x3030303, 0x4040404, 0x5050505, 0x636300
};

s16 rz_cpdist[] = {
    1 , 2, 3, 4, 5, 7, 9, 0xD, 0x11, 0x19, 0x21, 0x31, 0x41, 0x61,
    0x81, 0xC1, 0x101, 0x181, 0x201, 0x301, 0x401, 0x601, 0x801, 
    0xC01, 0x1001, 0x1801, 0x2001, 0x3001, 0x4001, 0x6001
};

u16 rz_cpdext[] = {
    0, 0, 0x101, 0x202, 0x303, 0x404, 0x505, 0x606,
    0x707, 0x808, 0x909, 0xA0A, 0xB0B, 0xC0C, 0xD0D, 0
};

u16 rz_mask_bits[] = {
    0, 1, 3, 7, 0xF, 0x1F, 0x3F, 0x7F, 0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF, 0
};

s32 rz_lbits = 9;
s32 rz_dbits = 6;

//.rodata


#ifdef NONMATCHING

s32 sub_GAME_7F0CE8B0(u32 *b, u32 n, u32 s, u16 *d, u8 *e, struct huft **t, s32 *m)
{
	u32 a;                   /* counter for codes of length k */
	u32 c[BMAX+1];           /* bit length count table */
	u32 f;                   /* i repeats in table every f entries */
	s32 g;                   /* maximum code length */
	s32 h;                   /* table level */
	register u32 i;          /* counter, current code */
	register u32 j;          /* counter */
	register s32 k;          /* number of bits in current code */
	s32 l;                   /* bits per table (returned in m) */
	register u32 *p;         /* pointer into c[], b[], or v[] */
	register struct huft *q; /* points to current table */
	struct huft r;           /* table entry for structure assignment */
	struct huft *u[BMAX];    /* table stack */
	u32 v[N_MAX];            /* values in order of bit length */
	register s32 w;          /* bits before this table == (l * h) */
	u32 x[BMAX+1];           /* bit offsets, then code stack */
	u32 *xp;                 /* pointer into x */
	s32 y;                   /* number of dummy codes added */
	u32 z;                   /* number of entries in current table */
	u32 i2;

	/* Generate counts for each bit length */
	for (i2 = 0; i2 != BMAX + 1; i2++) {
		c[i2] = 0;
	}

	p = b;
	i = n;

	do {
		c[*p]++;                  /* assume all entries <= BMAX */
		p++;                      /* Can't combine with above line (Solaris bug) */
	} while (--i);

	if (c[0] == n) {              /* null input--all zero length codes */
		*t = NULL;
		*m = 0;
		return 0;
	}

	/* Find minimum and maximum length, bound *m by those */
	l = *m;

	for (j = 1; j <= BMAX; j++) {
		if (c[j]) {
			break;
		}
	}

	k = j;                        /* minimum code length */

	if (l < j) {
		l = j;
	}

	for (i = BMAX; i; i--) {
		if (c[i]) {
			break;
		}
	}

	g = i;                        /* maximum code length */

	if (l > i) {
		l = i;
	}

	*m = l;

	/* Adjust last length count to fill out codes, if needed */
	for (y = 1 << j; j < i; j++, y <<= 1) {
		y -= c[j];
	}

	y -= c[i];
	c[i] += y;

	/* Generate starting offsets into the value table for each length */
	x[1] = j = 0;
	p = c + 1;
	xp = x + 2;

	while (--i) {                 /* note that i == g from above */
		*xp++ = (j += *p++);
	}

	/* Make a table of values in order of bit lengths */
	p = b;
	i = 0;

	do {
		if ((j = *p++) != 0) {
			v[x[j]++] = i;
		}
	} while (++i < n);

	/* Generate the Huffman codes and for each, make the table entries */
	x[0] = i = 0;                 /* first Huffman code is zero */
	p = v;                        /* grab values in bit order */
	h = -1;                       /* no tables yet--level -1 */
	w = -l;                       /* bits decoded == (l * h) */
	u[0] = (struct huft *)NULL;   /* just to keep compilers happy */
	q = (struct huft *)NULL;      /* ditto */
	z = 0;                        /* ditto */

	/* go through the bit lengths (k already is bits in shortest code) */
	for (; k <= g; k++) {
		a = c[k];

		while (a--) {
			/* here i is the Huffman code of length k bits for value *p */
			/* make tables up to required level */
			while (k > w + l) {
				h++;
				w += l;                 /* previous table always l bits */

				/* compute minimum size table less than or equal to l bits */
				z = (z = g - w) > l ? l : z;  /* upper limit on table size */

				if ((f = 1 << (j = k - w)) > a + 1) {   /* try a k-w bit table */
				                          /* too few codes for k-w bit table */
					f -= a + 1;           /* deduct codes from patterns left */
					xp = c + k;

					while (++j < z) {     /* try smaller tables up to z bits */
						if ((f <<= 1) <= *++xp) {
							break;            /* enough codes to use up j bits */
						}

						f -= *xp;           /* else deduct codes from patterns */
					}
				}

				z = 1 << j;             /* table entries for j-bit table */

				/* allocate and link in new table */
				q = &rz_hlist[rz_hufts];

				rz_hufts += z + 1;         /* track memory usage */
				*t = q + 1;             /* link to list for huft_free() */
				*(t = &(q->v.t)) = (struct huft *)NULL;
				u[h] = ++q;             /* table starts after link */

				/* connect to last table, if there is one */
				if (h) {
					x[h] = i;             /* save pattern for backing up */
					r.b = l;              /* bits to dump before this table */
					r.e = 16 + j;         /* bits in this table */
					r.v.t = q;            /* pointer to this table */
					j = i >> (w - l);     /* (get around Turbo C bug) */
					u[h-1][j] = r;        /* connect to last table */
				}
			}

			/* set up table entry in r */
			r.b = (k - w);

			if (p >= v + n) {
				r.e = 99;               /* out of values--invalid code */
			} else if (*p < s) {
				r.e = (*p < 256 ? 16 : 15);    /* 256 is end-of-block code */
				r.v.n = *p;             /* simple code is just the value */
				p++;                    /* one compiler does not like *p++ */
			} else {
				r.e = e[*p - s];   /* non-simple--look up in lists */
				r.v.n = d[*p++ - s];
			}

			/* fill code-like entries with r */
			f = 1 << (k - w);

			for (j = i >> w; j < z; j += f) {
				q[j] = r;
			}

			/* backwards increment the k-bit code i */
			for (j = 1 << (k - 1); i & j; j >>= 1) {
				i ^= j;
			}

			i ^= j;

			/* backup over finished tables */
			while ((i & ((1 << w) - 1)) != x[h]) {
				h--;                    /* don't need to update q */
				w -= l;
			}
		}
	}

	/* Return true (1) if we were given an incomplete table */
	return y != 0 && g != 1;
}


#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CE8B0
/* 1033E0 7F0CE8B0 27BDFA08 */  addiu $sp, $sp, -0x5f8
/* 1033E4 7F0CE8B4 AFB20020 */  sw    $s2, 0x20($sp)
/* 1033E8 7F0CE8B8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1033EC 7F0CE8BC 27B105B0 */  addiu $s1, $sp, 0x5b0
/* 1033F0 7F0CE8C0 00809025 */  move  $s2, $a0
/* 1033F4 7F0CE8C4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 1033F8 7F0CE8C8 AFA505FC */  sw    $a1, 0x5fc($sp)
/* 1033FC 7F0CE8CC AFBE0038 */  sw    $fp, 0x38($sp)
/* 103400 7F0CE8D0 AFB70034 */  sw    $s7, 0x34($sp)
/* 103404 7F0CE8D4 AFB60030 */  sw    $s6, 0x30($sp)
/* 103408 7F0CE8D8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 10340C 7F0CE8DC AFB40028 */  sw    $s4, 0x28($sp)
/* 103410 7F0CE8E0 AFB30024 */  sw    $s3, 0x24($sp)
/* 103414 7F0CE8E4 AFB00018 */  sw    $s0, 0x18($sp)
/* 103418 7F0CE8E8 AFA60600 */  sw    $a2, 0x600($sp)
/* 10341C 7F0CE8EC AFA70604 */  sw    $a3, 0x604($sp)
/* 103420 7F0CE8F0 24050044 */  li    $a1, 68
/* 103424 7F0CE8F4 0C005F10 */  jal   bzero
/* 103428 7F0CE8F8 02202025 */   move  $a0, $s1
/* 10342C 7F0CE8FC 8FAE05FC */  lw    $t6, 0x5fc($sp)
/* 103430 7F0CE900 0240F025 */  move  $fp, $s2
/* 103434 7F0CE904 24070001 */  li    $a3, 1
/* 103438 7F0CE908 31C20003 */  andi  $v0, $t6, 3
/* 10343C 7F0CE90C 00021023 */  negu  $v0, $v0
/* 103440 7F0CE910 1040000D */  beqz  $v0, .L7F0CE948
/* 103444 7F0CE914 01C0F825 */   move  $ra, $t6
/* 103448 7F0CE918 004E1821 */  addu  $v1, $v0, $t6
.L7F0CE91C:
/* 10344C 7F0CE91C 8FCF0000 */  lw    $t7, ($fp)
/* 103450 7F0CE920 27FFFFFF */  addiu $ra, $ra, -1
/* 103454 7F0CE924 27DE0004 */  addiu $fp, $fp, 4
/* 103458 7F0CE928 000FC080 */  sll   $t8, $t7, 2
/* 10345C 7F0CE92C 02381021 */  addu  $v0, $s1, $t8
/* 103460 7F0CE930 8C590000 */  lw    $t9, ($v0)
/* 103464 7F0CE934 272E0001 */  addiu $t6, $t9, 1
/* 103468 7F0CE938 147FFFF8 */  bne   $v1, $ra, .L7F0CE91C
/* 10346C 7F0CE93C AC4E0000 */   sw    $t6, ($v0)
/* 103470 7F0CE940 53E0001D */  beql  $ra, $zero, .L7F0CE9B8
/* 103474 7F0CE944 8FAF05FC */   lw    $t7, 0x5fc($sp)
.L7F0CE948:
/* 103478 7F0CE948 8FCF0000 */  lw    $t7, ($fp)
/* 10347C 7F0CE94C 27FFFFFC */  addiu $ra, $ra, -4
/* 103480 7F0CE950 27DE0010 */  addiu $fp, $fp, 0x10
/* 103484 7F0CE954 000FC080 */  sll   $t8, $t7, 2
/* 103488 7F0CE958 02381021 */  addu  $v0, $s1, $t8
/* 10348C 7F0CE95C 8C590000 */  lw    $t9, ($v0)
/* 103490 7F0CE960 272E0001 */  addiu $t6, $t9, 1
/* 103494 7F0CE964 AC4E0000 */  sw    $t6, ($v0)
/* 103498 7F0CE968 8FCFFFF4 */  lw    $t7, -0xc($fp)
/* 10349C 7F0CE96C 000FC080 */  sll   $t8, $t7, 2
/* 1034A0 7F0CE970 02381021 */  addu  $v0, $s1, $t8
/* 1034A4 7F0CE974 8C590000 */  lw    $t9, ($v0)
/* 1034A8 7F0CE978 272E0001 */  addiu $t6, $t9, 1
/* 1034AC 7F0CE97C AC4E0000 */  sw    $t6, ($v0)
/* 1034B0 7F0CE980 8FCFFFF8 */  lw    $t7, -8($fp)
/* 1034B4 7F0CE984 000FC080 */  sll   $t8, $t7, 2
/* 1034B8 7F0CE988 02381021 */  addu  $v0, $s1, $t8
/* 1034BC 7F0CE98C 8C590000 */  lw    $t9, ($v0)
/* 1034C0 7F0CE990 272E0001 */  addiu $t6, $t9, 1
/* 1034C4 7F0CE994 AC4E0000 */  sw    $t6, ($v0)
/* 1034C8 7F0CE998 8FCFFFFC */  lw    $t7, -4($fp)
/* 1034CC 7F0CE99C 000FC080 */  sll   $t8, $t7, 2
/* 1034D0 7F0CE9A0 02381021 */  addu  $v0, $s1, $t8
/* 1034D4 7F0CE9A4 8C590000 */  lw    $t9, ($v0)
/* 1034D8 7F0CE9A8 272E0001 */  addiu $t6, $t9, 1
/* 1034DC 7F0CE9AC 17E0FFE6 */  bnez  $ra, .L7F0CE948
/* 1034E0 7F0CE9B0 AC4E0000 */   sw    $t6, ($v0)
/* 1034E4 7F0CE9B4 8FAF05FC */  lw    $t7, 0x5fc($sp)
.L7F0CE9B8:
/* 1034E8 7F0CE9B8 8FB805B0 */  lw    $t8, 0x5b0($sp)
/* 1034EC 7F0CE9BC 8FA50610 */  lw    $a1, 0x610($sp)
/* 1034F0 7F0CE9C0 27A305B4 */  addiu $v1, $sp, 0x5b4
/* 1034F4 7F0CE9C4 15F80007 */  bne   $t7, $t8, .L7F0CE9E4
/* 1034F8 7F0CE9C8 24020011 */   li    $v0, 17
/* 1034FC 7F0CE9CC 8FB5060C */  lw    $s5, 0x60c($sp)
/* 103500 7F0CE9D0 8FA50610 */  lw    $a1, 0x610($sp)
/* 103504 7F0CE9D4 00001025 */  move  $v0, $zero
/* 103508 7F0CE9D8 AEA00000 */  sw    $zero, ($s5)
/* 10350C 7F0CE9DC 10000138 */  b     .L7F0CEEC0
/* 103510 7F0CE9E0 ACA00000 */   sw    $zero, ($a1)
.L7F0CE9E4:
/* 103514 7F0CE9E4 8CB00000 */  lw    $s0, ($a1)
.L7F0CE9E8:
/* 103518 7F0CE9E8 8C790000 */  lw    $t9, ($v1)
/* 10351C 7F0CE9EC 57200005 */  bnezl $t9, .L7F0CEA04
/* 103520 7F0CE9F0 0207082B */   sltu  $at, $s0, $a3
/* 103524 7F0CE9F4 24E70001 */  addiu $a3, $a3, 1
/* 103528 7F0CE9F8 14E2FFFB */  bne   $a3, $v0, .L7F0CE9E8
/* 10352C 7F0CE9FC 24630004 */   addiu $v1, $v1, 4
/* 103530 7F0CEA00 0207082B */  sltu  $at, $s0, $a3
.L7F0CEA04:
/* 103534 7F0CEA04 10200002 */  beqz  $at, .L7F0CEA10
/* 103538 7F0CEA08 00E0A025 */   move  $s4, $a3
/* 10353C 7F0CEA0C 00E08025 */  move  $s0, $a3
.L7F0CEA10:
/* 103540 7F0CEA10 241F0010 */  li    $ra, 16
/* 103544 7F0CEA14 27A205F0 */  addiu $v0, $sp, 0x5f0
.L7F0CEA18:
/* 103548 7F0CEA18 8C4E0000 */  lw    $t6, ($v0)
/* 10354C 7F0CEA1C 55C00005 */  bnezl $t6, .L7F0CEA34
/* 103550 7F0CEA20 03F0082B */   sltu  $at, $ra, $s0
/* 103554 7F0CEA24 27FFFFFF */  addiu $ra, $ra, -1
/* 103558 7F0CEA28 17E0FFFB */  bnez  $ra, .L7F0CEA18
/* 10355C 7F0CEA2C 2442FFFC */   addiu $v0, $v0, -4
/* 103560 7F0CEA30 03F0082B */  sltu  $at, $ra, $s0
.L7F0CEA34:
/* 103564 7F0CEA34 10200002 */  beqz  $at, .L7F0CEA40
/* 103568 7F0CEA38 AFBF05A8 */   sw    $ra, 0x5a8($sp)
/* 10356C 7F0CEA3C 03E08025 */  move  $s0, $ra
.L7F0CEA40:
/* 103570 7F0CEA40 240F0001 */  li    $t7, 1
/* 103574 7F0CEA44 00FF082B */  sltu  $at, $a3, $ra
/* 103578 7F0CEA48 ACB00000 */  sw    $s0, ($a1)
/* 10357C 7F0CEA4C 1020000B */  beqz  $at, .L7F0CEA7C
/* 103580 7F0CEA50 00EF2004 */   sllv  $a0, $t7, $a3
/* 103584 7F0CEA54 001FC080 */  sll   $t8, $ra, 2
/* 103588 7F0CEA58 27B905B0 */  addiu $t9, $sp, 0x5b0
/* 10358C 7F0CEA5C 03192821 */  addu  $a1, $t8, $t9
.L7F0CEA60:
/* 103590 7F0CEA60 8C6E0000 */  lw    $t6, ($v1)
/* 103594 7F0CEA64 24630004 */  addiu $v1, $v1, 4
/* 103598 7F0CEA68 0065082B */  sltu  $at, $v1, $a1
/* 10359C 7F0CEA6C 008E2023 */  subu  $a0, $a0, $t6
/* 1035A0 7F0CEA70 00047840 */  sll   $t7, $a0, 1
/* 1035A4 7F0CEA74 1420FFFA */  bnez  $at, .L7F0CEA60
/* 1035A8 7F0CEA78 01E02025 */   move  $a0, $t7
.L7F0CEA7C:
/* 1035AC 7F0CEA7C 8C430000 */  lw    $v1, ($v0)
/* 1035B0 7F0CEA80 27FFFFFF */  addiu $ra, $ra, -1
/* 1035B4 7F0CEA84 00003825 */  move  $a3, $zero
/* 1035B8 7F0CEA88 00832023 */  subu  $a0, $a0, $v1
/* 1035BC 7F0CEA8C 0064C021 */  addu  $t8, $v1, $a0
/* 1035C0 7F0CEA90 AC580000 */  sw    $t8, ($v0)
/* 1035C4 7F0CEA94 AFA00080 */  sw    $zero, 0x80($sp)
/* 1035C8 7F0CEA98 27BE05B4 */  addiu $fp, $sp, 0x5b4
/* 1035CC 7F0CEA9C 27A60084 */  addiu $a2, $sp, 0x84
/* 1035D0 7F0CEAA0 13E00022 */  beqz  $ra, .L7F0CEB2C
/* 1035D4 7F0CEAA4 2442FFFC */   addiu $v0, $v0, -4
/* 1035D8 7F0CEAA8 33E80003 */  andi  $t0, $ra, 3
/* 1035DC 7F0CEAAC 00084023 */  negu  $t0, $t0
/* 1035E0 7F0CEAB0 1100000D */  beqz  $t0, .L7F0CEAE8
/* 1035E4 7F0CEAB4 011F1821 */   addu  $v1, $t0, $ra
/* 1035E8 7F0CEAB8 0003C880 */  sll   $t9, $v1, 2
/* 1035EC 7F0CEABC 27AE05B0 */  addiu $t6, $sp, 0x5b0
/* 1035F0 7F0CEAC0 032E2821 */  addu  $a1, $t9, $t6
.L7F0CEAC4:
/* 1035F4 7F0CEAC4 8FCF0000 */  lw    $t7, ($fp)
/* 1035F8 7F0CEAC8 2442FFFC */  addiu $v0, $v0, -4
/* 1035FC 7F0CEACC 24C60004 */  addiu $a2, $a2, 4
/* 103600 7F0CEAD0 00EF3821 */  addu  $a3, $a3, $t7
/* 103604 7F0CEAD4 ACC7FFFC */  sw    $a3, -4($a2)
/* 103608 7F0CEAD8 14A2FFFA */  bne   $a1, $v0, .L7F0CEAC4
/* 10360C 7F0CEADC 27DE0004 */   addiu $fp, $fp, 4
/* 103610 7F0CEAE0 27B805B0 */  addiu $t8, $sp, 0x5b0
/* 103614 7F0CEAE4 10580011 */  beq   $v0, $t8, .L7F0CEB2C
.L7F0CEAE8:
/* 103618 7F0CEAE8 27A305B0 */   addiu $v1, $sp, 0x5b0
.L7F0CEAEC:
/* 10361C 7F0CEAEC 8FD90000 */  lw    $t9, ($fp)
/* 103620 7F0CEAF0 2442FFF0 */  addiu $v0, $v0, -0x10
/* 103624 7F0CEAF4 24C60010 */  addiu $a2, $a2, 0x10
/* 103628 7F0CEAF8 00F93821 */  addu  $a3, $a3, $t9
/* 10362C 7F0CEAFC ACC7FFF0 */  sw    $a3, -0x10($a2)
/* 103630 7F0CEB00 8FCE0004 */  lw    $t6, 4($fp)
/* 103634 7F0CEB04 27DE0010 */  addiu $fp, $fp, 0x10
/* 103638 7F0CEB08 00EE3821 */  addu  $a3, $a3, $t6
/* 10363C 7F0CEB0C ACC7FFF4 */  sw    $a3, -0xc($a2)
/* 103640 7F0CEB10 8FCFFFF8 */  lw    $t7, -8($fp)
/* 103644 7F0CEB14 00EF3821 */  addu  $a3, $a3, $t7
/* 103648 7F0CEB18 ACC7FFF8 */  sw    $a3, -8($a2)
/* 10364C 7F0CEB1C 8FD8FFFC */  lw    $t8, -4($fp)
/* 103650 7F0CEB20 00F83821 */  addu  $a3, $a3, $t8
/* 103654 7F0CEB24 1443FFF1 */  bne   $v0, $v1, .L7F0CEAEC
/* 103658 7F0CEB28 ACC7FFFC */   sw    $a3, -4($a2)
.L7F0CEB2C:
/* 10365C 7F0CEB2C 0240F025 */  move  $fp, $s2
/* 103660 7F0CEB30 0000F825 */  move  $ra, $zero
/* 103664 7F0CEB34 27A6007C */  addiu $a2, $sp, 0x7c
/* 103668 7F0CEB38 27A500C4 */  addiu $a1, $sp, 0xc4
/* 10366C 7F0CEB3C 8FC70000 */  lw    $a3, ($fp)
.L7F0CEB40:
/* 103670 7F0CEB40 27DE0004 */  addiu $fp, $fp, 4
/* 103674 7F0CEB44 10E00008 */  beqz  $a3, .L7F0CEB68
/* 103678 7F0CEB48 0007C880 */   sll   $t9, $a3, 2
/* 10367C 7F0CEB4C 00D91021 */  addu  $v0, $a2, $t9
/* 103680 7F0CEB50 8C430000 */  lw    $v1, ($v0)
/* 103684 7F0CEB54 00037080 */  sll   $t6, $v1, 2
/* 103688 7F0CEB58 00AE7821 */  addu  $t7, $a1, $t6
/* 10368C 7F0CEB5C ADFF0000 */  sw    $ra, ($t7)
/* 103690 7F0CEB60 24780001 */  addiu $t8, $v1, 1
/* 103694 7F0CEB64 AC580000 */  sw    $t8, ($v0)
.L7F0CEB68:
/* 103698 7F0CEB68 8FB905FC */  lw    $t9, 0x5fc($sp)
/* 10369C 7F0CEB6C 27FF0001 */  addiu $ra, $ra, 1
/* 1036A0 7F0CEB70 03F9082B */  sltu  $at, $ra, $t9
/* 1036A4 7F0CEB74 5420FFF2 */  bnezl $at, .L7F0CEB40
/* 1036A8 7F0CEB78 8FC70000 */   lw    $a3, ($fp)
/* 1036AC 7F0CEB7C 8FAE05A8 */  lw    $t6, 0x5a8($sp)
/* 1036B0 7F0CEB80 AFA40074 */  sw    $a0, 0x74($sp)
/* 1036B4 7F0CEB84 0000F825 */  move  $ra, $zero
/* 1036B8 7F0CEB88 01D4082A */  slt   $at, $t6, $s4
/* 1036BC 7F0CEB8C AFA0007C */  sw    $zero, 0x7c($sp)
/* 1036C0 7F0CEB90 00A0F025 */  move  $fp, $a1
/* 1036C4 7F0CEB94 240CFFFF */  li    $t4, -1
/* 1036C8 7F0CEB98 00105023 */  negu  $t2, $s0
/* 1036CC 7F0CEB9C AFA00544 */  sw    $zero, 0x544($sp)
/* 1036D0 7F0CEBA0 00003025 */  move  $a2, $zero
/* 1036D4 7F0CEBA4 142000BF */  bnez  $at, .L7F0CEEA4
/* 1036D8 7F0CEBA8 00004025 */   move  $t0, $zero
/* 1036DC 7F0CEBAC 00147880 */  sll   $t7, $s4, 2
/* 1036E0 7F0CEBB0 27B805B0 */  addiu $t8, $sp, 0x5b0
/* 1036E4 7F0CEBB4 01F8C821 */  addu  $t9, $t7, $t8
/* 1036E8 7F0CEBB8 3C178009 */  lui   $s7, %hi(rz_hlist) 
/* 1036EC 7F0CEBBC 3C128009 */  lui   $s2, %hi(rz_hufts)
/* 1036F0 7F0CEBC0 2652D36C */  addiu $s2, %lo(rz_hufts) # addiu $s2, $s2, -0x2c94
/* 1036F4 7F0CEBC4 26F7D360 */  addiu $s7, %lo(rz_hlist) # addiu $s7, $s7, -0x2ca0
/* 1036F8 7F0CEBC8 AFB9005C */  sw    $t9, 0x5c($sp)
/* 1036FC 7F0CEBCC 8FB5060C */  lw    $s5, 0x60c($sp)
/* 103700 7F0CEBD0 27B30584 */  addiu $s3, $sp, 0x584
.L7F0CEBD4:
/* 103704 7F0CEBD4 8FAE005C */  lw    $t6, 0x5c($sp)
/* 103708 7F0CEBD8 8FB805FC */  lw    $t8, 0x5fc($sp)
/* 10370C 7F0CEBDC 000C6880 */  sll   $t5, $t4, 2
/* 103710 7F0CEBE0 8DD60000 */  lw    $s6, ($t6)
/* 103714 7F0CEBE4 27AF007C */  addiu $t7, $sp, 0x7c
/* 103718 7F0CEBE8 0018C880 */  sll   $t9, $t8, 2
/* 10371C 7F0CEBEC 02C02825 */  move  $a1, $s6
/* 103720 7F0CEBF0 12C000A4 */  beqz  $s6, .L7F0CEE84
/* 103724 7F0CEBF4 26D6FFFF */   addiu $s6, $s6, -1
/* 103728 7F0CEBF8 01AF5821 */  addu  $t3, $t5, $t7
/* 10372C 7F0CEBFC 27AE00C4 */  addiu $t6, $sp, 0xc4
/* 103730 7F0CEC00 032E7821 */  addu  $t7, $t9, $t6
/* 103734 7F0CEC04 24190001 */  li    $t9, 1
/* 103738 7F0CEC08 2698001F */  addiu $t8, $s4, 0x1f
/* 10373C 7F0CEC0C 03197004 */  sllv  $t6, $t9, $t8
/* 103740 7F0CEC10 AFAE0040 */  sw    $t6, 0x40($sp)
/* 103744 7F0CEC14 AFAF0044 */  sw    $t7, 0x44($sp)
.L7F0CEC18:
/* 103748 7F0CEC18 01501821 */  addu  $v1, $t2, $s0
/* 10374C 7F0CEC1C 0074082A */  slt   $at, $v1, $s4
/* 103750 7F0CEC20 10200047 */  beqz  $at, .L7F0CED40
/* 103754 7F0CEC24 26D10001 */   addiu $s1, $s6, 1
/* 103758 7F0CEC28 27AF0544 */  addiu $t7, $sp, 0x544
/* 10375C 7F0CEC2C 01AF4821 */  addu  $t1, $t5, $t7
/* 103760 7F0CEC30 8FB905A8 */  lw    $t9, 0x5a8($sp)
.L7F0CEC34:
/* 103764 7F0CEC34 258C0001 */  addiu $t4, $t4, 1
/* 103768 7F0CEC38 25AD0004 */  addiu $t5, $t5, 4
/* 10376C 7F0CEC3C 03234023 */  subu  $t0, $t9, $v1
/* 103770 7F0CEC40 0208082B */  sltu  $at, $s0, $t0
/* 103774 7F0CEC44 25290004 */  addiu $t1, $t1, 4
/* 103778 7F0CEC48 256B0004 */  addiu $t3, $t3, 4
/* 10377C 7F0CEC4C 10200002 */  beqz  $at, .L7F0CEC58
/* 103780 7F0CEC50 00605025 */   move  $t2, $v1
/* 103784 7F0CEC54 02004025 */  move  $t0, $s0
.L7F0CEC58:
/* 103788 7F0CEC58 028A1023 */  subu  $v0, $s4, $t2
/* 10378C 7F0CEC5C 24180001 */  li    $t8, 1
/* 103790 7F0CEC60 00582004 */  sllv  $a0, $t8, $v0
/* 103794 7F0CEC64 0224082B */  sltu  $at, $s1, $a0
/* 103798 7F0CEC68 10200013 */  beqz  $at, .L7F0CECB8
/* 10379C 7F0CEC6C 00403825 */   move  $a3, $v0
/* 1037A0 7F0CEC70 24470001 */  addiu $a3, $v0, 1
/* 1037A4 7F0CEC74 00961823 */  subu  $v1, $a0, $s6
/* 1037A8 7F0CEC78 00147080 */  sll   $t6, $s4, 2
/* 1037AC 7F0CEC7C 27AF05B0 */  addiu $t7, $sp, 0x5b0
/* 1037B0 7F0CEC80 00E8082B */  sltu  $at, $a3, $t0
/* 1037B4 7F0CEC84 2463FFFF */  addiu $v1, $v1, -1
/* 1037B8 7F0CEC88 1020000B */  beqz  $at, .L7F0CECB8
/* 1037BC 7F0CEC8C 01CF3021 */   addu  $a2, $t6, $t7
.L7F0CEC90:
/* 1037C0 7F0CEC90 8CC40004 */  lw    $a0, 4($a2)
/* 1037C4 7F0CEC94 00031040 */  sll   $v0, $v1, 1
/* 1037C8 7F0CEC98 24C60004 */  addiu $a2, $a2, 4
/* 1037CC 7F0CEC9C 0082082B */  sltu  $at, $a0, $v0
/* 1037D0 7F0CECA0 50200006 */  beql  $at, $zero, .L7F0CECBC
/* 1037D4 7F0CECA4 8E430000 */   lw    $v1, ($s2)
/* 1037D8 7F0CECA8 24E70001 */  addiu $a3, $a3, 1
/* 1037DC 7F0CECAC 00E8082B */  sltu  $at, $a3, $t0
/* 1037E0 7F0CECB0 1420FFF7 */  bnez  $at, .L7F0CEC90
/* 1037E4 7F0CECB4 00441823 */   subu  $v1, $v0, $a0
.L7F0CECB8:
/* 1037E8 7F0CECB8 8E430000 */  lw    $v1, ($s2)
.L7F0CECBC:
/* 1037EC 7F0CECBC 8EEE0000 */  lw    $t6, ($s7)
/* 1037F0 7F0CECC0 24190001 */  li    $t9, 1
/* 1037F4 7F0CECC4 00F94004 */  sllv  $t0, $t9, $a3
/* 1037F8 7F0CECC8 0003C0C0 */  sll   $t8, $v1, 3
/* 1037FC 7F0CECCC 00687821 */  addu  $t7, $v1, $t0
/* 103800 7F0CECD0 25F90001 */  addiu $t9, $t7, 1
/* 103804 7F0CECD4 030E3021 */  addu  $a2, $t8, $t6
/* 103808 7F0CECD8 AE590000 */  sw    $t9, ($s2)
/* 10380C 7F0CECDC 24C40008 */  addiu $a0, $a2, 8
/* 103810 7F0CECE0 AEA40000 */  sw    $a0, ($s5)
/* 103814 7F0CECE4 ACC00004 */  sw    $zero, 4($a2)
/* 103818 7F0CECE8 24D50004 */  addiu $s5, $a2, 4
/* 10381C 7F0CECEC 00803025 */  move  $a2, $a0
/* 103820 7F0CECF0 1180000F */  beqz  $t4, .L7F0CED30
/* 103824 7F0CECF4 AD240000 */   sw    $a0, ($t1)
/* 103828 7F0CECF8 AD7F0000 */  sw    $ra, ($t3)
/* 10382C 7F0CECFC 24F80010 */  addiu $t8, $a3, 0x10
/* 103830 7F0CED00 A3B00585 */  sb    $s0, 0x585($sp)
/* 103834 7F0CED04 A3B80584 */  sb    $t8, 0x584($sp)
/* 103838 7F0CED08 AFA40588 */  sw    $a0, 0x588($sp)
/* 10383C 7F0CED0C 8D2EFFFC */  lw    $t6, -4($t1)
/* 103840 7F0CED10 01507823 */  subu  $t7, $t2, $s0
/* 103844 7F0CED14 8E610000 */  lw    $at, ($s3)
/* 103848 7F0CED18 01FFC806 */  srlv  $t9, $ra, $t7
/* 10384C 7F0CED1C 0019C0C0 */  sll   $t8, $t9, 3
/* 103850 7F0CED20 01D87821 */  addu  $t7, $t6, $t8
/* 103854 7F0CED24 ADE10000 */  sw    $at, ($t7)
/* 103858 7F0CED28 8E780004 */  lw    $t8, 4($s3)
/* 10385C 7F0CED2C ADF80004 */  sw    $t8, 4($t7)
.L7F0CED30:
/* 103860 7F0CED30 01501821 */  addu  $v1, $t2, $s0
/* 103864 7F0CED34 0074082A */  slt   $at, $v1, $s4
/* 103868 7F0CED38 5420FFBE */  bnezl $at, .L7F0CEC34
/* 10386C 7F0CED3C 8FB905A8 */   lw    $t9, 0x5a8($sp)
.L7F0CED40:
/* 103870 7F0CED40 8FB90044 */  lw    $t9, 0x44($sp)
/* 103874 7F0CED44 240E0001 */  li    $t6, 1
/* 103878 7F0CED48 028A1823 */  subu  $v1, $s4, $t2
/* 10387C 7F0CED4C 014E2804 */  sllv  $a1, $t6, $t2
/* 103880 7F0CED50 03D9082B */  sltu  $at, $fp, $t9
/* 103884 7F0CED54 A3A30585 */  sb    $v1, 0x585($sp)
/* 103888 7F0CED58 14200004 */  bnez  $at, .L7F0CED6C
/* 10388C 7F0CED5C 24A5FFFF */   addiu $a1, $a1, -1
/* 103890 7F0CED60 240F0063 */  li    $t7, 99
/* 103894 7F0CED64 10000020 */  b     .L7F0CEDE8
/* 103898 7F0CED68 A3AF0584 */   sb    $t7, 0x584($sp)
.L7F0CED6C:
/* 10389C 7F0CED6C 8FC20000 */  lw    $v0, ($fp)
/* 1038A0 7F0CED70 8FB80600 */  lw    $t8, 0x600($sp)
/* 1038A4 7F0CED74 8FA40600 */  lw    $a0, 0x600($sp)
/* 1038A8 7F0CED78 8FAE0608 */  lw    $t6, 0x608($sp)
/* 1038AC 7F0CED7C 0058082B */  sltu  $at, $v0, $t8
/* 1038B0 7F0CED80 1020000B */  beqz  $at, .L7F0CEDB0
/* 1038B4 7F0CED84 2C410100 */   sltiu $at, $v0, 0x100
/* 1038B8 7F0CED88 10200004 */  beqz  $at, .L7F0CED9C
/* 1038BC 7F0CED8C 2419000F */   li    $t9, 15
/* 1038C0 7F0CED90 240E0010 */  li    $t6, 16
/* 1038C4 7F0CED94 10000002 */  b     .L7F0CEDA0
/* 1038C8 7F0CED98 A3AE0584 */   sb    $t6, 0x584($sp)
.L7F0CED9C:
/* 1038CC 7F0CED9C A3B90584 */  sb    $t9, 0x584($sp)
.L7F0CEDA0:
/* 1038D0 7F0CEDA0 8FCF0000 */  lw    $t7, ($fp)
/* 1038D4 7F0CEDA4 27DE0004 */  addiu $fp, $fp, 4
/* 1038D8 7F0CEDA8 1000000F */  b     .L7F0CEDE8
/* 1038DC 7F0CEDAC A7AF0588 */   sh    $t7, 0x588($sp)
.L7F0CEDB0:
/* 1038E0 7F0CEDB0 0044C023 */  subu  $t8, $v0, $a0
/* 1038E4 7F0CEDB4 030EC821 */  addu  $t9, $t8, $t6
/* 1038E8 7F0CEDB8 932F0000 */  lbu   $t7, ($t9)
/* 1038EC 7F0CEDBC 8FB80604 */  lw    $t8, 0x604($sp)
/* 1038F0 7F0CEDC0 27DE0004 */  addiu $fp, $fp, 4
/* 1038F4 7F0CEDC4 A3AF0584 */  sb    $t7, 0x584($sp)
/* 1038F8 7F0CEDC8 8FCEFFFC */  lw    $t6, -4($fp)
/* 1038FC 7F0CEDCC 000EC840 */  sll   $t9, $t6, 1
/* 103900 7F0CEDD0 00047040 */  sll   $t6, $a0, 1
/* 103904 7F0CEDD4 03197821 */  addu  $t7, $t8, $t9
/* 103908 7F0CEDD8 000EC023 */  negu  $t8, $t6
/* 10390C 7F0CEDDC 01F8C821 */  addu  $t9, $t7, $t8
/* 103910 7F0CEDE0 972E0000 */  lhu   $t6, ($t9)
/* 103914 7F0CEDE4 A7AE0588 */  sh    $t6, 0x588($sp)
.L7F0CEDE8:
/* 103918 7F0CEDE8 015F3806 */  srlv  $a3, $ra, $t2
/* 10391C 7F0CEDEC 00E8082B */  sltu  $at, $a3, $t0
/* 103920 7F0CEDF0 1020000B */  beqz  $at, .L7F0CEE20
/* 103924 7F0CEDF4 240F0001 */   li    $t7, 1
/* 103928 7F0CEDF8 006F1004 */  sllv  $v0, $t7, $v1
.L7F0CEDFC:
/* 10392C 7F0CEDFC 8E610000 */  lw    $at, ($s3)
/* 103930 7F0CEE00 0007C0C0 */  sll   $t8, $a3, 3
/* 103934 7F0CEE04 00D8C821 */  addu  $t9, $a2, $t8
/* 103938 7F0CEE08 AF210000 */  sw    $at, ($t9)
/* 10393C 7F0CEE0C 8E6F0004 */  lw    $t7, 4($s3)
/* 103940 7F0CEE10 00E23821 */  addu  $a3, $a3, $v0
/* 103944 7F0CEE14 00E8082B */  sltu  $at, $a3, $t0
/* 103948 7F0CEE18 1420FFF8 */  bnez  $at, .L7F0CEDFC
/* 10394C 7F0CEE1C AF2F0004 */   sw    $t7, 4($t9)
.L7F0CEE20:
/* 103950 7F0CEE20 8FA70040 */  lw    $a3, 0x40($sp)
/* 103954 7F0CEE24 8D620000 */  lw    $v0, ($t3)
/* 103958 7F0CEE28 03E7C024 */  and   $t8, $ra, $a3
/* 10395C 7F0CEE2C 13000005 */  beqz  $t8, .L7F0CEE44
.L7F0CEE30:
/* 103960 7F0CEE30 00077042 */   srl   $t6, $a3, 1
/* 103964 7F0CEE34 03E7F826 */  xor   $ra, $ra, $a3
/* 103968 7F0CEE38 03EEC824 */  and   $t9, $ra, $t6
/* 10396C 7F0CEE3C 1720FFFC */  bnez  $t9, .L7F0CEE30
/* 103970 7F0CEE40 01C03825 */   move  $a3, $t6
.L7F0CEE44:
/* 103974 7F0CEE44 03E7F826 */  xor   $ra, $ra, $a3
/* 103978 7F0CEE48 03E57824 */  and   $t7, $ra, $a1
/* 10397C 7F0CEE4C 11E2000B */  beq   $t7, $v0, .L7F0CEE7C
/* 103980 7F0CEE50 02C02825 */   move  $a1, $s6
.L7F0CEE54:
/* 103984 7F0CEE54 01505023 */  subu  $t2, $t2, $s0
/* 103988 7F0CEE58 24180001 */  li    $t8, 1
/* 10398C 7F0CEE5C 01587004 */  sllv  $t6, $t8, $t2
/* 103990 7F0CEE60 8D78FFFC */  lw    $t8, -4($t3)
/* 103994 7F0CEE64 25D9FFFF */  addiu $t9, $t6, -1
/* 103998 7F0CEE68 03F97824 */  and   $t7, $ra, $t9
/* 10399C 7F0CEE6C 258CFFFF */  addiu $t4, $t4, -1
/* 1039A0 7F0CEE70 25ADFFFC */  addiu $t5, $t5, -4
/* 1039A4 7F0CEE74 15F8FFF7 */  bne   $t7, $t8, .L7F0CEE54
/* 1039A8 7F0CEE78 256BFFFC */   addiu $t3, $t3, -4
.L7F0CEE7C:
/* 1039AC 7F0CEE7C 16C0FF66 */  bnez  $s6, .L7F0CEC18
/* 1039B0 7F0CEE80 26D6FFFF */   addiu $s6, $s6, -1
.L7F0CEE84:
/* 1039B4 7F0CEE84 8FAE005C */  lw    $t6, 0x5c($sp)
/* 1039B8 7F0CEE88 8FAF05A8 */  lw    $t7, 0x5a8($sp)
/* 1039BC 7F0CEE8C 26940001 */  addiu $s4, $s4, 1
/* 1039C0 7F0CEE90 25D90004 */  addiu $t9, $t6, 4
/* 1039C4 7F0CEE94 01F4082A */  slt   $at, $t7, $s4
/* 1039C8 7F0CEE98 1020FF4E */  beqz  $at, .L7F0CEBD4
/* 1039CC 7F0CEE9C AFB9005C */   sw    $t9, 0x5c($sp)
/* 1039D0 7F0CEEA0 AFB5060C */  sw    $s5, 0x60c($sp)
.L7F0CEEA4:
/* 1039D4 7F0CEEA4 8FA20074 */  lw    $v0, 0x74($sp)
/* 1039D8 7F0CEEA8 0002C02B */  sltu  $t8, $zero, $v0
/* 1039DC 7F0CEEAC 13000004 */  beqz  $t8, .L7F0CEEC0
/* 1039E0 7F0CEEB0 03001025 */   move  $v0, $t8
/* 1039E4 7F0CEEB4 8FA205A8 */  lw    $v0, 0x5a8($sp)
/* 1039E8 7F0CEEB8 384E0001 */  xori  $t6, $v0, 1
/* 1039EC 7F0CEEBC 000E102B */  sltu  $v0, $zero, $t6
.L7F0CEEC0:
/* 1039F0 7F0CEEC0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 1039F4 7F0CEEC4 8FB00018 */  lw    $s0, 0x18($sp)
/* 1039F8 7F0CEEC8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1039FC 7F0CEECC 8FB20020 */  lw    $s2, 0x20($sp)
/* 103A00 7F0CEED0 8FB30024 */  lw    $s3, 0x24($sp)
/* 103A04 7F0CEED4 8FB40028 */  lw    $s4, 0x28($sp)
/* 103A08 7F0CEED8 8FB5002C */  lw    $s5, 0x2c($sp)
/* 103A0C 7F0CEEDC 8FB60030 */  lw    $s6, 0x30($sp)
/* 103A10 7F0CEEE0 8FB70034 */  lw    $s7, 0x34($sp)
/* 103A14 7F0CEEE4 8FBE0038 */  lw    $fp, 0x38($sp)
/* 103A18 7F0CEEE8 03E00008 */  jr    $ra
/* 103A1C 7F0CEEEC 27BD05F8 */   addiu $sp, $sp, 0x5f8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CEEF0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CEEF0
/* 103A20 7F0CEEF0 27BDFF90 */  addiu $sp, $sp, -0x70
/* 103A24 7F0CEEF4 3C098005 */  lui   $t1, %hi(rz_mask_bits) 
/* 103A28 7F0CEEF8 2529E9B0 */  addiu $t1, %lo(rz_mask_bits) # addiu $t1, $t1, -0x1650
/* 103A2C 7F0CEEFC AFBE0038 */  sw    $fp, 0x38($sp)
/* 103A30 7F0CEF00 AFB70034 */  sw    $s7, 0x34($sp)
/* 103A34 7F0CEF04 AFB5002C */  sw    $s5, 0x2c($sp)
/* 103A38 7F0CEF08 AFB40028 */  sw    $s4, 0x28($sp)
/* 103A3C 7F0CEF0C AFB30024 */  sw    $s3, 0x24($sp)
/* 103A40 7F0CEF10 AFB1001C */  sw    $s1, 0x1c($sp)
/* 103A44 7F0CEF14 00067840 */  sll   $t7, $a2, 1
/* 103A48 7F0CEF18 0007C840 */  sll   $t9, $a3, 1
/* 103A4C 7F0CEF1C AFBF003C */  sw    $ra, 0x3c($sp)
/* 103A50 7F0CEF20 AFA7007C */  sw    $a3, 0x7c($sp)
/* 103A54 7F0CEF24 3C148009 */  lui   $s4, %hi(rz_bb)
/* 103A58 7F0CEF28 3C118009 */  lui   $s1, %hi(rz_bk)
/* 103A5C 7F0CEF2C 3C158009 */  lui   $s5, %hi(rz_wp)
/* 103A60 7F0CEF30 012F6021 */  addu  $t4, $t1, $t7
/* 103A64 7F0CEF34 01396821 */  addu  $t5, $t1, $t9
/* 103A68 7F0CEF38 3C138009 */  lui   $s3, %hi(rz_inptr)
/* 103A6C 7F0CEF3C 3C178009 */  lui   $s7, %hi(rz_outbuf) 
/* 103A70 7F0CEF40 3C1E8009 */  lui   $fp, %hi(rz_inbuf) 
/* 103A74 7F0CEF44 AFB60030 */  sw    $s6, 0x30($sp)
/* 103A78 7F0CEF48 AFB20020 */  sw    $s2, 0x20($sp)
/* 103A7C 7F0CEF4C AFB00018 */  sw    $s0, 0x18($sp)
/* 103A80 7F0CEF50 AFA40070 */  sw    $a0, 0x70($sp)
/* 103A84 7F0CEF54 AFA50074 */  sw    $a1, 0x74($sp)
/* 103A88 7F0CEF58 AFA60078 */  sw    $a2, 0x78($sp)
/* 103A8C 7F0CEF5C 8E94D364 */  lw    $s4, %lo(rz_bb)($s4)
/* 103A90 7F0CEF60 8E31D368 */  lw    $s1, %lo(rz_bk)($s1)
/* 103A94 7F0CEF64 8EB5D35C */  lw    $s5, %lo(rz_wp)($s5)
/* 103A98 7F0CEF68 958A0000 */  lhu   $t2, ($t4)
/* 103A9C 7F0CEF6C 95AB0000 */  lhu   $t3, ($t5)
/* 103AA0 7F0CEF70 27DED350 */  addiu $fp, %lo(rz_inbuf) # addiu $fp, $fp, -0x2cb0
/* 103AA4 7F0CEF74 26F7D354 */  addiu $s7, %lo(rz_outbuf) # addiu $s7, $s7, -0x2cac
/* 103AA8 7F0CEF78 2673D358 */  addiu $s3, %lo(rz_inptr) # addiu $s3, $s3, -0x2ca8
/* 103AAC 7F0CEF7C 34078000 */  li    $a3, 32768
/* 103AB0 7F0CEF80 00C0F825 */  move  $ra, $a2
.L7F0CEF84:
/* 103AB4 7F0CEF84 023F082B */  sltu  $at, $s1, $ra
.L7F0CEF88:
/* 103AB8 7F0CEF88 5020000D */  beql  $at, $zero, .L7F0CEFC0
/* 103ABC 7F0CEF8C 8FB90070 */   lw    $t9, 0x70($sp)
/* 103AC0 7F0CEF90 8FC30000 */  lw    $v1, ($fp)
.L7F0CEF94:
/* 103AC4 7F0CEF94 8E620000 */  lw    $v0, ($s3)
/* 103AC8 7F0CEF98 00627821 */  addu  $t7, $v1, $v0
/* 103ACC 7F0CEF9C 91F80000 */  lbu   $t8, ($t7)
/* 103AD0 7F0CEFA0 244E0001 */  addiu $t6, $v0, 1
/* 103AD4 7F0CEFA4 AE6E0000 */  sw    $t6, ($s3)
/* 103AD8 7F0CEFA8 0238C804 */  sllv  $t9, $t8, $s1
/* 103ADC 7F0CEFAC 26310008 */  addiu $s1, $s1, 8
/* 103AE0 7F0CEFB0 023F082B */  sltu  $at, $s1, $ra
/* 103AE4 7F0CEFB4 1420FFF7 */  bnez  $at, .L7F0CEF94
/* 103AE8 7F0CEFB8 0299A025 */   or    $s4, $s4, $t9
/* 103AEC 7F0CEFBC 8FB90070 */  lw    $t9, 0x70($sp)
.L7F0CEFC0:
/* 103AF0 7F0CEFC0 028A7824 */  and   $t7, $s4, $t2
/* 103AF4 7F0CEFC4 000FC0C0 */  sll   $t8, $t7, 3
/* 103AF8 7F0CEFC8 03193021 */  addu  $a2, $t8, $t9
/* 103AFC 7F0CEFCC 90D20000 */  lbu   $s2, ($a2)
/* 103B00 7F0CEFD0 2E410011 */  sltiu $at, $s2, 0x11
/* 103B04 7F0CEFD4 5420001E */  bnezl $at, .L7F0CF050
/* 103B08 7F0CEFD8 90C20001 */   lbu   $v0, 1($a2)
/* 103B0C 7F0CEFDC 90C20001 */  lbu   $v0, 1($a2)
.L7F0CEFE0:
/* 103B10 7F0CEFE0 2652FFF0 */  addiu $s2, $s2, -0x10
/* 103B14 7F0CEFE4 02228823 */  subu  $s1, $s1, $v0
/* 103B18 7F0CEFE8 0232082B */  sltu  $at, $s1, $s2
/* 103B1C 7F0CEFEC 1020000C */  beqz  $at, .L7F0CF020
/* 103B20 7F0CEFF0 0054A006 */   srlv  $s4, $s4, $v0
/* 103B24 7F0CEFF4 8FC30000 */  lw    $v1, ($fp)
.L7F0CEFF8:
/* 103B28 7F0CEFF8 8E620000 */  lw    $v0, ($s3)
/* 103B2C 7F0CEFFC 00627021 */  addu  $t6, $v1, $v0
/* 103B30 7F0CF000 91CF0000 */  lbu   $t7, ($t6)
/* 103B34 7F0CF004 24590001 */  addiu $t9, $v0, 1
/* 103B38 7F0CF008 AE790000 */  sw    $t9, ($s3)
/* 103B3C 7F0CF00C 022FC004 */  sllv  $t8, $t7, $s1
/* 103B40 7F0CF010 26310008 */  addiu $s1, $s1, 8
/* 103B44 7F0CF014 0232082B */  sltu  $at, $s1, $s2
/* 103B48 7F0CF018 1420FFF7 */  bnez  $at, .L7F0CEFF8
/* 103B4C 7F0CF01C 0298A025 */   or    $s4, $s4, $t8
.L7F0CF020:
/* 103B50 7F0CF020 00127040 */  sll   $t6, $s2, 1
/* 103B54 7F0CF024 012E7821 */  addu  $t7, $t1, $t6
/* 103B58 7F0CF028 95F80000 */  lhu   $t8, ($t7)
/* 103B5C 7F0CF02C 8CCF0004 */  lw    $t7, 4($a2)
/* 103B60 7F0CF030 0314C824 */  and   $t9, $t8, $s4
/* 103B64 7F0CF034 001970C0 */  sll   $t6, $t9, 3
/* 103B68 7F0CF038 01CF3021 */  addu  $a2, $t6, $t7
/* 103B6C 7F0CF03C 90D20000 */  lbu   $s2, ($a2)
/* 103B70 7F0CF040 2E410011 */  sltiu $at, $s2, 0x11
/* 103B74 7F0CF044 5020FFE6 */  beql  $at, $zero, .L7F0CEFE0
/* 103B78 7F0CF048 90C20001 */   lbu   $v0, 1($a2)
/* 103B7C 7F0CF04C 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF050:
/* 103B80 7F0CF050 24010010 */  li    $at, 16
/* 103B84 7F0CF054 0054A006 */  srlv  $s4, $s4, $v0
/* 103B88 7F0CF058 16410013 */  bne   $s2, $at, .L7F0CF0A8
/* 103B8C 7F0CF05C 02228823 */   subu  $s1, $s1, $v0
/* 103B90 7F0CF060 8EF80000 */  lw    $t8, ($s7)
/* 103B94 7F0CF064 8FD90000 */  lw    $t9, ($fp)
/* 103B98 7F0CF068 8E6E0000 */  lw    $t6, ($s3)
/* 103B9C 7F0CF06C 03152821 */  addu  $a1, $t8, $s5
/* 103BA0 7F0CF070 00A01025 */  move  $v0, $a1
/* 103BA4 7F0CF074 032E2021 */  addu  $a0, $t9, $t6
/* 103BA8 7F0CF078 00A4082B */  sltu  $at, $a1, $a0
/* 103BAC 7F0CF07C 14200006 */  bnez  $at, .L7F0CF098
/* 103rz_bb0 7F0CF080 00447823 */   subu  $t7, $v0, $a0
/* 103rz_bb4 7F0CF084 01E7082B */  sltu  $at, $t7, $a3
/* 103rz_bb8 7F0CF088 50200004 */  beql  $at, $zero, .L7F0CF09C
/* 103rz_bbC 7F0CF08C 94D80004 */   lhu   $t8, 4($a2)
.L7F0CF090:
/* 103BC0 7F0CF090 1000FFFF */  b     .L7F0CF090
/* 103BC4 7F0CF094 00000000 */   nop   
.L7F0CF098:
/* 103BC8 7F0CF098 94D80004 */  lhu   $t8, 4($a2)
.L7F0CF09C:
/* 103BCC 7F0CF09C 26B50001 */  addiu $s5, $s5, 1
/* 103BD0 7F0CF0A0 1000FFB8 */  b     .L7F0CEF84
/* 103BD4 7F0CF0A4 A0B80000 */   sb    $t8, ($a1)
.L7F0CF0A8:
/* 103BD8 7F0CF0A8 2401000F */  li    $at, 15
/* 103BDC 7F0CF0AC 124100A4 */  beq   $s2, $at, .L7F0CF340
/* 103BE0 7F0CF0B0 0232082B */   sltu  $at, $s1, $s2
/* 103BE4 7F0CF0B4 5020000D */  beql  $at, $zero, .L7F0CF0EC
/* 103BE8 7F0CF0B8 0012C840 */   sll   $t9, $s2, 1
/* 103BEC 7F0CF0BC 8FC30000 */  lw    $v1, ($fp)
.L7F0CF0C0:
/* 103BF0 7F0CF0C0 8E620000 */  lw    $v0, ($s3)
/* 103BF4 7F0CF0C4 0062C821 */  addu  $t9, $v1, $v0
/* 103BF8 7F0CF0C8 932E0000 */  lbu   $t6, ($t9)
/* 103BFC 7F0CF0CC 24580001 */  addiu $t8, $v0, 1
/* 103C00 7F0CF0D0 AE780000 */  sw    $t8, ($s3)
/* 103C04 7F0CF0D4 022E7804 */  sllv  $t7, $t6, $s1
/* 103C08 7F0CF0D8 26310008 */  addiu $s1, $s1, 8
/* 103C0C 7F0CF0DC 0232082B */  sltu  $at, $s1, $s2
/* 103C10 7F0CF0E0 1420FFF7 */  bnez  $at, .L7F0CF0C0
/* 103C14 7F0CF0E4 028FA025 */   or    $s4, $s4, $t7
/* 103C18 7F0CF0E8 0012C840 */  sll   $t9, $s2, 1
.L7F0CF0EC:
/* 103C1C 7F0CF0EC 01397021 */  addu  $t6, $t1, $t9
/* 103C20 7F0CF0F0 95CF0000 */  lhu   $t7, ($t6)
/* 103C24 7F0CF0F4 8FAE007C */  lw    $t6, 0x7c($sp)
/* 103C28 7F0CF0F8 94D90004 */  lhu   $t9, 4($a2)
/* 103C2C 7F0CF0FC 02328823 */  subu  $s1, $s1, $s2
/* 103C30 7F0CF100 01F4C024 */  and   $t8, $t7, $s4
/* 103C34 7F0CF104 022E082B */  sltu  $at, $s1, $t6
/* 103C38 7F0CF108 0254A006 */  srlv  $s4, $s4, $s2
/* 103C3C 7F0CF10C 1020000D */  beqz  $at, .L7F0CF144
/* 103C40 7F0CF110 03194021 */   addu  $t0, $t8, $t9
/* 103C44 7F0CF114 8FC30000 */  lw    $v1, ($fp)
/* 103C48 7F0CF118 01C02025 */  move  $a0, $t6
.L7F0CF11C:
/* 103C4C 7F0CF11C 8E620000 */  lw    $v0, ($s3)
/* 103C50 7F0CF120 00627821 */  addu  $t7, $v1, $v0
/* 103C54 7F0CF124 91F80000 */  lbu   $t8, ($t7)
/* 103C58 7F0CF128 244E0001 */  addiu $t6, $v0, 1
/* 103C5C 7F0CF12C AE6E0000 */  sw    $t6, ($s3)
/* 103C60 7F0CF130 0238C804 */  sllv  $t9, $t8, $s1
/* 103C64 7F0CF134 26310008 */  addiu $s1, $s1, 8
/* 103C68 7F0CF138 0224082B */  sltu  $at, $s1, $a0
/* 103C6C 7F0CF13C 1420FFF7 */  bnez  $at, .L7F0CF11C
/* 103C70 7F0CF140 0299A025 */   or    $s4, $s4, $t9
.L7F0CF144:
/* 103C74 7F0CF144 8FB90074 */  lw    $t9, 0x74($sp)
/* 103C78 7F0CF148 028B7824 */  and   $t7, $s4, $t3
/* 103C7C 7F0CF14C 000FC0C0 */  sll   $t8, $t7, 3
/* 103C80 7F0CF150 03193021 */  addu  $a2, $t8, $t9
/* 103C84 7F0CF154 90D20000 */  lbu   $s2, ($a2)
/* 103C88 7F0CF158 2E410011 */  sltiu $at, $s2, 0x11
/* 103C8C 7F0CF15C 5420001E */  bnezl $at, .L7F0CF1D8
/* 103C90 7F0CF160 90C20001 */   lbu   $v0, 1($a2)
/* 103C94 7F0CF164 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF168:
/* 103C98 7F0CF168 2652FFF0 */  addiu $s2, $s2, -0x10
/* 103C9C 7F0CF16C 02228823 */  subu  $s1, $s1, $v0
/* 103CA0 7F0CF170 0232082B */  sltu  $at, $s1, $s2
/* 103CA4 7F0CF174 1020000C */  beqz  $at, .L7F0CF1A8
/* 103CA8 7F0CF178 0054A006 */   srlv  $s4, $s4, $v0
/* 103CAC 7F0CF17C 8FC30000 */  lw    $v1, ($fp)
.L7F0CF180:
/* 103CB0 7F0CF180 8E620000 */  lw    $v0, ($s3)
/* 103CB4 7F0CF184 00627021 */  addu  $t6, $v1, $v0
/* 103CB8 7F0CF188 91CF0000 */  lbu   $t7, ($t6)
/* 103CBC 7F0CF18C 24590001 */  addiu $t9, $v0, 1
/* 103CC0 7F0CF190 AE790000 */  sw    $t9, ($s3)
/* 103CC4 7F0CF194 022FC004 */  sllv  $t8, $t7, $s1
/* 103CC8 7F0CF198 26310008 */  addiu $s1, $s1, 8
/* 103CCC 7F0CF19C 0232082B */  sltu  $at, $s1, $s2
/* 103CD0 7F0CF1A0 1420FFF7 */  bnez  $at, .L7F0CF180
/* 103CD4 7F0CF1A4 0298A025 */   or    $s4, $s4, $t8
.L7F0CF1A8:
/* 103CD8 7F0CF1A8 00127040 */  sll   $t6, $s2, 1
/* 103CDC 7F0CF1AC 012E7821 */  addu  $t7, $t1, $t6
/* 103CE0 7F0CF1B0 95F80000 */  lhu   $t8, ($t7)
/* 103CE4 7F0CF1B4 8CCF0004 */  lw    $t7, 4($a2)
/* 103CE8 7F0CF1B8 0314C824 */  and   $t9, $t8, $s4
/* 103CEC 7F0CF1BC 001970C0 */  sll   $t6, $t9, 3
/* 103CF0 7F0CF1C0 01CF3021 */  addu  $a2, $t6, $t7
/* 103CF4 7F0CF1C4 90D20000 */  lbu   $s2, ($a2)
/* 103CF8 7F0CF1C8 2E410011 */  sltiu $at, $s2, 0x11
/* 103CFC 7F0CF1CC 5020FFE6 */  beql  $at, $zero, .L7F0CF168
/* 103D00 7F0CF1D0 90C20001 */   lbu   $v0, 1($a2)
/* 103D04 7F0CF1D4 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF1D8:
/* 103D08 7F0CF1D8 02228823 */  subu  $s1, $s1, $v0
/* 103D0C 7F0CF1DC 0232082B */  sltu  $at, $s1, $s2
/* 103D10 7F0CF1E0 1020000C */  beqz  $at, .L7F0CF214
/* 103D14 7F0CF1E4 0054A006 */   srlv  $s4, $s4, $v0
/* 103D18 7F0CF1E8 8FC30000 */  lw    $v1, ($fp)
.L7F0CF1EC:
/* 103D1C 7F0CF1EC 8E620000 */  lw    $v0, ($s3)
/* 103D20 7F0CF1F0 0062C021 */  addu  $t8, $v1, $v0
/* 103D24 7F0CF1F4 93190000 */  lbu   $t9, ($t8)
/* 103D28 7F0CF1F8 244F0001 */  addiu $t7, $v0, 1
/* 103D2C 7F0CF1FC AE6F0000 */  sw    $t7, ($s3)
/* 103D30 7F0CF200 02397004 */  sllv  $t6, $t9, $s1
/* 103D34 7F0CF204 26310008 */  addiu $s1, $s1, 8
/* 103D38 7F0CF208 0232082B */  sltu  $at, $s1, $s2
/* 103D3C 7F0CF20C 1420FFF7 */  bnez  $at, .L7F0CF1EC
/* 103D40 7F0CF210 028EA025 */   or    $s4, $s4, $t6
.L7F0CF214:
/* 103D44 7F0CF214 94D80004 */  lhu   $t8, 4($a2)
/* 103D48 7F0CF218 00127040 */  sll   $t6, $s2, 1
/* 103D4C 7F0CF21C 012E7821 */  addu  $t7, $t1, $t6
/* 103D50 7F0CF220 02B8C823 */  subu  $t9, $s5, $t8
/* 103D54 7F0CF224 95F80000 */  lhu   $t8, ($t7)
/* 103D58 7F0CF228 02328823 */  subu  $s1, $s1, $s2
/* 103D5C 7F0CF22C 03147024 */  and   $t6, $t8, $s4
/* 103D60 7F0CF230 032E8023 */  subu  $s0, $t9, $t6
/* 103D64 7F0CF234 0254A006 */  srlv  $s4, $s4, $s2
/* 103D68 7F0CF238 01009025 */  move  $s2, $t0
.L7F0CF23C:
/* 103D6C 7F0CF23C 02B07823 */  subu  $t7, $s5, $s0
/* 103D70 7F0CF240 01F2082B */  sltu  $at, $t7, $s2
/* 103D74 7F0CF244 14200025 */  bnez  $at, .L7F0CF2DC
/* 103D78 7F0CF248 00004025 */   move  $t0, $zero
/* 103D7C 7F0CF24C 8EE30000 */  lw    $v1, ($s7)
/* 103D80 7F0CF250 8FD80000 */  lw    $t8, ($fp)
/* 103D84 7F0CF254 8E790000 */  lw    $t9, ($s3)
/* 103D88 7F0CF258 02B2B021 */  addu  $s6, $s5, $s2
/* 103D8C 7F0CF25C 02C31021 */  addu  $v0, $s6, $v1
/* 103D90 7F0CF260 2442FFFF */  addiu $v0, $v0, -1
/* 103D94 7F0CF264 03192021 */  addu  $a0, $t8, $t9
/* 103D98 7F0CF268 0044082B */  sltu  $at, $v0, $a0
/* 103D9C 7F0CF26C 14200006 */  bnez  $at, .L7F0CF288
/* 103DA0 7F0CF270 00447023 */   subu  $t6, $v0, $a0
/* 103DA4 7F0CF274 01C7082B */  sltu  $at, $t6, $a3
/* 103DA8 7F0CF278 50200004 */  beql  $at, $zero, .L7F0CF28C
/* 103DAC 7F0CF27C 00752021 */   addu  $a0, $v1, $s5
.L7F0CF280:
/* 103DB0 7F0CF280 1000FFFF */  b     .L7F0CF280
/* 103DB4 7F0CF284 00000000 */   nop   
.L7F0CF288:
/* 103DB8 7F0CF288 00752021 */  addu  $a0, $v1, $s5
.L7F0CF28C:
/* 103DBC 7F0CF28C 00702821 */  addu  $a1, $v1, $s0
/* 103DC0 7F0CF290 02403025 */  move  $a2, $s2
/* 103DC4 7F0CF294 AFA80068 */  sw    $t0, 0x68($sp)
/* 103DC8 7F0CF298 AFAA0058 */  sw    $t2, 0x58($sp)
/* 103DCC 7F0CF29C AFAB0054 */  sw    $t3, 0x54($sp)
/* 103DD0 7F0CF2A0 AFAC0044 */  sw    $t4, 0x44($sp)
/* 103DD4 7F0CF2A4 0C004E14 */  jal   memcpy
/* 103DD8 7F0CF2A8 AFAD0040 */   sw    $t5, 0x40($sp)
/* 103DDC 7F0CF2AC 3C098005 */  lui   $t1, %hi(rz_mask_bits) 
/* 103DE0 7F0CF2B0 2529E9B0 */  addiu $t1, %lo(rz_mask_bits) # addiu $t1, $t1, -0x1650
/* 103DE4 7F0CF2B4 34078000 */  li    $a3, 32768
/* 103DE8 7F0CF2B8 8FA80068 */  lw    $t0, 0x68($sp)
/* 103DEC 7F0CF2BC 8FAA0058 */  lw    $t2, 0x58($sp)
/* 103DF0 7F0CF2C0 8FAB0054 */  lw    $t3, 0x54($sp)
/* 103DF4 7F0CF2C4 8FAC0044 */  lw    $t4, 0x44($sp)
/* 103DF8 7F0CF2C8 8FAD0040 */  lw    $t5, 0x40($sp)
/* 103DFC 7F0CF2CC 8FBF0078 */  lw    $ra, 0x78($sp)
/* 103E00 7F0CF2D0 02C0A825 */  move  $s5, $s6
/* 103E04 7F0CF2D4 10000016 */  b     .L7F0CF330
/* 103E08 7F0CF2D8 02128021 */   addu  $s0, $s0, $s2
.L7F0CF2DC:
/* 103E0C 7F0CF2DC 8EE30000 */  lw    $v1, ($s7)
/* 103E10 7F0CF2E0 8FCF0000 */  lw    $t7, ($fp)
/* 103E14 7F0CF2E4 8E780000 */  lw    $t8, ($s3)
/* 103E18 7F0CF2E8 00752821 */  addu  $a1, $v1, $s5
/* 103E1C 7F0CF2EC 00A01025 */  move  $v0, $a1
/* 103E20 7F0CF2F0 01F82021 */  addu  $a0, $t7, $t8
/* 103E24 7F0CF2F4 00A4082B */  sltu  $at, $a1, $a0
/* 103E28 7F0CF2F8 14200006 */  bnez  $at, .L7F0CF314
/* 103E2C 7F0CF2FC 0044C823 */   subu  $t9, $v0, $a0
/* 103E30 7F0CF300 0327082B */  sltu  $at, $t9, $a3
/* 103E34 7F0CF304 50200004 */  beql  $at, $zero, .L7F0CF318
/* 103E38 7F0CF308 02037021 */   addu  $t6, $s0, $v1
.L7F0CF30C:
/* 103E3C 7F0CF30C 1000FFFF */  b     .L7F0CF30C
/* 103E40 7F0CF310 00000000 */   nop   
.L7F0CF314:
/* 103E44 7F0CF314 02037021 */  addu  $t6, $s0, $v1
.L7F0CF318:
/* 103E48 7F0CF318 91CF0000 */  lbu   $t7, ($t6)
/* 103E4C 7F0CF31C 2652FFFF */  addiu $s2, $s2, -1
/* 103E50 7F0CF320 26100001 */  addiu $s0, $s0, 1
/* 103E54 7F0CF324 26B50001 */  addiu $s5, $s5, 1
/* 103E58 7F0CF328 1640FFEC */  bnez  $s2, .L7F0CF2DC
/* 103E5C 7F0CF32C A0AF0000 */   sb    $t7, ($a1)
.L7F0CF330:
/* 103E60 7F0CF330 5500FFC2 */  bnezl $t0, .L7F0CF23C
/* 103E64 7F0CF334 01009025 */   move  $s2, $t0
/* 103E68 7F0CF338 1000FF13 */  b     .L7F0CEF88
/* 103E6C 7F0CF33C 023F082B */   sltu  $at, $s1, $ra
.L7F0CF340:
/* 103E70 7F0CF340 3C018009 */  lui   $at, %hi(rz_wp)
/* 103E74 7F0CF344 AC35D35C */  sw    $s5, %lo(rz_wp)($at)
/* 103E78 7F0CF348 3C018009 */  lui   $at, %hi(rz_bb)
/* 103E7C 7F0CF34C AC34D364 */  sw    $s4, %lo(rz_bb)($at)
/* 103E80 7F0CF350 8FBF003C */  lw    $ra, 0x3c($sp)
/* 103E84 7F0CF354 3C018009 */  lui   $at, %hi(rz_bk)
/* 103E88 7F0CF358 AC31D368 */  sw    $s1, %lo(rz_bk)($at)
/* 103E8C 7F0CF35C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 103E90 7F0CF360 8FB40028 */  lw    $s4, 0x28($sp)
/* 103E94 7F0CF364 8FB5002C */  lw    $s5, 0x2c($sp)
/* 103E98 7F0CF368 8FB00018 */  lw    $s0, 0x18($sp)
/* 103E9C 7F0CF36C 8FB20020 */  lw    $s2, 0x20($sp)
/* 103EA0 7F0CF370 8FB30024 */  lw    $s3, 0x24($sp)
/* 103EA4 7F0CF374 8FB60030 */  lw    $s6, 0x30($sp)
/* 103EA8 7F0CF378 8FB70034 */  lw    $s7, 0x34($sp)
/* 103EAC 7F0CF37C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 103EB0 7F0CF380 27BD0070 */  addiu $sp, $sp, 0x70
/* 103EB4 7F0CF384 03E00008 */  jr    $ra
/* 103EB8 7F0CF388 00001025 */   move  $v0, $zero
)
#endif






#ifdef NONMATCHING
s32 zlib_decompressor_type0(void)
{
	s32 n;           /* number of bytes in block */
	s32 w;           /* current window position */
	register u32 b; /* bit buffer */
	register u32 k;  /* number of bits in bit buffer */

	/* make local copies of globals */
	b = rz_bb;                       /* initialize bit buffer */
	k = rz_bk;
	w = rz_wp;                       /* initialize window position */

	/* go to byte boundary */
	n = k & 7;
	DUMPBITS(n);

	/* get the length and its complement */
	NEEDBITS(16)
	n = (b & 0xffff);
	DUMPBITS(16)

	NEEDBITS(16)
	DUMPBITS(16)

	/* read and output the compressed data */
	while (n--) {
		NEEDBITS(8)
		rz_outbuf[w++] = (u8)b;

		DUMPBITS(8)
	}

	/* restore the globals from the locals */
	rz_wp = w;                       /* restore global window pointer */
	rz_bb = b;                       /* restore global bit buffer */
	rz_bk = k;
	return 0;
}
//#ifdef NONMATCHING
#else
GLOBAL_ASM(
.text
glabel zlib_decompressor_type0
/* 103EBC 7F0CF38C 3C0B8009 */  lui   $t3, %hi(rz_bk) 
/* 103EC0 7F0CF390 256BD368 */  addiu $t3, %lo(rz_bk) # addiu $t3, $t3, -0x2c98
/* 103EC4 7F0CF394 8D640000 */  lw    $a0, ($t3)
/* 103EC8 7F0CF398 3C0A8009 */  lui   $t2, %hi(rz_bb) 
/* 103ECC 7F0CF39C 254AD364 */  addiu $t2, %lo(rz_bb) # addiu $t2, $t2, -0x2c9c
/* 103ED0 7F0CF3A0 30820007 */  andi  $v0, $a0, 7
/* 103ED4 7F0CF3A4 8D430000 */  lw    $v1, ($t2)
/* 103ED8 7F0CF3A8 3C0C8009 */  lui   $t4, %hi(rz_wp) 
/* 103EDC 7F0CF3AC 00822023 */  subu  $a0, $a0, $v0
/* 103EE0 7F0CF3B0 258CD35C */  addiu $t4, %lo(rz_wp) # addiu $t4, $t4, -0x2ca4
/* 103EE4 7F0CF3B4 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 103EE8 7F0CF3B8 2C810010 */  sltiu $at, $a0, 0x10
/* 103EEC 7F0CF3BC AFB1000C */  sw    $s1, 0xc($sp)
/* 103EF0 7F0CF3C0 AFB00008 */  sw    $s0, 8($sp)
/* 103EF4 7F0CF3C4 8D850000 */  lw    $a1, ($t4)
/* 103EF8 7F0CF3C8 1020000F */  beqz  $at, .L7F0CF408
/* 103EFC 7F0CF3CC 00431806 */   srlv  $v1, $v1, $v0
/* 103F00 7F0CF3D0 3C068009 */  lui   $a2, %hi(rz_inbuf)
/* 103F04 7F0CF3D4 3C0D8009 */  lui   $t5, %hi(rz_inptr) 
/* 103F08 7F0CF3D8 25ADD358 */  addiu $t5, %lo(rz_inptr) # addiu $t5, $t5, -0x2ca8
/* 103F0C 7F0CF3DC 8CC6D350 */  lw    $a2, %lo(rz_inbuf)($a2)
.L7F0CF3E0:
/* 103F10 7F0CF3E0 8DA70000 */  lw    $a3, ($t5)
/* 103F14 7F0CF3E4 00C77021 */  addu  $t6, $a2, $a3
/* 103F18 7F0CF3E8 91CF0000 */  lbu   $t7, ($t6)
/* 103F1C 7F0CF3EC 24F90001 */  addiu $t9, $a3, 1
/* 103F20 7F0CF3F0 ADB90000 */  sw    $t9, ($t5)
/* 103F24 7F0CF3F4 008FC004 */  sllv  $t8, $t7, $a0
/* 103F28 7F0CF3F8 24840008 */  addiu $a0, $a0, 8
/* 103F2C 7F0CF3FC 2C810010 */  sltiu $at, $a0, 0x10
/* 103F30 7F0CF400 1420FFF7 */  bnez  $at, .L7F0CF3E0
/* 103F34 7F0CF404 00781825 */   or    $v1, $v1, $t8
.L7F0CF408:
/* 103F38 7F0CF408 2484FFF0 */  addiu $a0, $a0, -0x10
/* 103F3C 7F0CF40C 3C0D8009 */  lui   $t5, %hi(rz_inptr) 
/* 103F40 7F0CF410 3062FFFF */  andi  $v0, $v1, 0xffff
/* 103F44 7F0CF414 00037402 */  srl   $t6, $v1, 0x10
/* 103F48 7F0CF418 2C810010 */  sltiu $at, $a0, 0x10
/* 103F4C 7F0CF41C 25ADD358 */  addiu $t5, %lo(rz_inptr) # addiu $t5, $t5, -0x2ca8
/* 103F50 7F0CF420 1020000D */  beqz  $at, .L7F0CF458
/* 103F54 7F0CF424 01C01825 */   move  $v1, $t6
/* 103F58 7F0CF428 3C068009 */  lui   $a2, %hi(rz_inbuf)
/* 103F5C 7F0CF42C 8CC6D350 */  lw    $a2, %lo(rz_inbuf)($a2)
.L7F0CF430:
/* 103F60 7F0CF430 8DA70000 */  lw    $a3, ($t5)
/* 103F64 7F0CF434 00C77821 */  addu  $t7, $a2, $a3
/* 103F68 7F0CF438 91F80000 */  lbu   $t8, ($t7)
/* 103F6C 7F0CF43C 24EE0001 */  addiu $t6, $a3, 1
/* 103F70 7F0CF440 ADAE0000 */  sw    $t6, ($t5)
/* 103F74 7F0CF444 0098C804 */  sllv  $t9, $t8, $a0
/* 103F78 7F0CF448 24840008 */  addiu $a0, $a0, 8
/* 103F7C 7F0CF44C 2C810010 */  sltiu $at, $a0, 0x10
/* 103F80 7F0CF450 1420FFF7 */  bnez  $at, .L7F0CF430
/* 103F84 7F0CF454 00791825 */   or    $v1, $v1, $t9
.L7F0CF458:
/* 103F88 7F0CF458 00403025 */  move  $a2, $v0
/* 103F8C 7F0CF45C 00037C02 */  srl   $t7, $v1, 0x10
/* 103F90 7F0CF460 01E01825 */  move  $v1, $t7
/* 103F94 7F0CF464 2484FFF0 */  addiu $a0, $a0, -0x10
/* 103F98 7F0CF468 10400027 */  beqz  $v0, .L7F0CF508
/* 103F9C 7F0CF46C 2442FFFF */   addiu $v0, $v0, -1
/* 103FA0 7F0CF470 3C108009 */  lui   $s0, %hi(rz_outbuf)
/* 103FA4 7F0CF474 2610D354 */  addiu $s0, %lo(rz_outbuf) # addiu $s0, $s0, -0x2cac
/* 103FA8 7F0CF478 34118000 */  li    $s1, 32768
.L7F0CF47C:
/* 103FAC 7F0CF47C 3C068009 */  lui   $a2, %hi(rz_inbuf)
/* 103FB0 7F0CF480 2C810008 */  sltiu $at, $a0, 8
/* 103FB4 7F0CF484 1020000B */  beqz  $at, .L7F0CF4B4
/* 103FB8 7F0CF488 8CC6D350 */   lw    $a2, %lo(rz_inbuf)($a2)
.L7F0CF48C:
/* 103FBC 7F0CF48C 8DA70000 */  lw    $a3, ($t5)
/* 103FC0 7F0CF490 00C7C021 */  addu  $t8, $a2, $a3
/* 103FC4 7F0CF494 93190000 */  lbu   $t9, ($t8)
/* 103FC8 7F0CF498 24EF0001 */  addiu $t7, $a3, 1
/* 103FCC 7F0CF49C ADAF0000 */  sw    $t7, ($t5)
/* 103FD0 7F0CF4A0 00997004 */  sllv  $t6, $t9, $a0
/* 103FD4 7F0CF4A4 24840008 */  addiu $a0, $a0, 8
/* 103FD8 7F0CF4A8 2C810008 */  sltiu $at, $a0, 8
/* 103FDC 7F0CF4AC 1420FFF7 */  bnez  $at, .L7F0CF48C
/* 103FE0 7F0CF4B0 006E1825 */   or    $v1, $v1, $t6
.L7F0CF4B4:
/* 103FE4 7F0CF4B4 8E180000 */  lw    $t8, ($s0)
/* 103FE8 7F0CF4B8 8DB90000 */  lw    $t9, ($t5)
/* 103FEC 7F0CF4BC 00037A02 */  srl   $t7, $v1, 8
/* 103FF0 7F0CF4C0 03053821 */  addu  $a3, $t8, $a1
/* 103FF4 7F0CF4C4 00D94821 */  addu  $t1, $a2, $t9
/* 103FF8 7F0CF4C8 00E9082B */  sltu  $at, $a3, $t1
/* 103FFC 7F0CF4CC 14200007 */  bnez  $at, .L7F0CF4EC
/* 104000 7F0CF4D0 00E04025 */   move  $t0, $a3
/* 104004 7F0CF4D4 01097023 */  subu  $t6, $t0, $t1
/* 104008 7F0CF4D8 01D1082B */  sltu  $at, $t6, $s1
/* 10400C 7F0CF4DC 50200004 */  beql  $at, $zero, .L7F0CF4F0
/* 104010 7F0CF4E0 00403025 */   move  $a2, $v0
.L7F0CF4E4:
/* 104014 7F0CF4E4 1000FFFF */  b     .L7F0CF4E4
/* 104018 7F0CF4E8 00000000 */   nop   
.L7F0CF4EC:
/* 10401C 7F0CF4EC 00403025 */  move  $a2, $v0
.L7F0CF4F0:
/* 104020 7F0CF4F0 A0E30000 */  sb    $v1, ($a3)
/* 104024 7F0CF4F4 24A50001 */  addiu $a1, $a1, 1
/* 104028 7F0CF4F8 01E01825 */  move  $v1, $t7
/* 10402C 7F0CF4FC 2484FFF8 */  addiu $a0, $a0, -8
/* 104030 7F0CF500 1440FFDE */  bnez  $v0, .L7F0CF47C
/* 104034 7F0CF504 2442FFFF */   addiu $v0, $v0, -1
.L7F0CF508:
/* 104038 7F0CF508 8FB00008 */  lw    $s0, 8($sp)
/* 10403C 7F0CF50C 8FB1000C */  lw    $s1, 0xc($sp)
/* 104040 7F0CF510 AD850000 */  sw    $a1, ($t4)
/* 104044 7F0CF514 AD430000 */  sw    $v1, ($t2)
/* 104048 7F0CF518 AD640000 */  sw    $a0, ($t3)
/* 10404C 7F0CF51C 27BD0010 */  addiu $sp, $sp, 0x10
/* 104050 7F0CF520 03E00008 */  jr    $ra
/* 104054 7F0CF524 00001025 */   move  $v0, $zero
)
#endif






s32 zlib_decompressor_type1(void)
{
	s32 i;                /* temporary variable */
	struct huft *tl;      /* literal/length code table */
	struct huft *td;      /* distance code table */
	s32 bl;               /* lookup bits for tl */
	s32 bd;               /* lookup bits for td */
	u32 l[288];           /* length list for sub_GAME_7F0CE8B0 */

	/* set up literal table */
	for (i = 0; i < 144; i++) {
		l[i] = 8;
	}
	for (; i < 256; i++) {
		l[i] = 9;
	}
	for (; i < 280; i++) {
		l[i] = 7;
	}
	for (; i < 288; i++) {
		l[i] = 8;
	}

	bl = 7;

	sub_GAME_7F0CE8B0(l, 288, 257, rz_cplens, rz_cplext, &tl, &bl);

	/* set up distance table */
	for (i = 0; i < 30; i++) {
		l[i] = 5;
	}

	bd = 5;

	/* decompress until an end-of-block code */
	sub_GAME_7F0CE8B0(l, 30, 0, rz_cpdist, rz_cpdext, &td, &bd);

	sub_GAME_7F0CEEF0(tl, td, bl, bd);

	return 0;
}


s32 zlib_decompressor_type2(void)
{
	s32 i;                /* temporary variables */
	u32 j;
	u32 l;           /* last length */
	u32 m;           /* mask for bit lengths table */
	u32 n;           /* number of lengths to get */
	struct huft *tl;      /* literal/length code table */
	struct huft *td;      /* distance code table */
	s32 bl;               /* lookup bits for tl */
	s32 bd;               /* lookup bits for td */
	u32 nb;          /* number of bit length codes */
	u32 nl;          /* number of literal/length codes */
	u32 nd;          /* number of distance codes */
	register u32 k;  /* number of bits in bit buffer */
	register u32 b;  /* bit buffer */
	u32 ll[286+30];  /* literal/length and distance code lengths */

	/* make local bit buffer */
	b = rz_bb;
	k = rz_bk;

	/* read in table lengths */
	NEEDBITS(5)
	nl = 257 + (b & 0x1f);      /* number of literal/length codes */
	DUMPBITS(5)
	NEEDBITS(5)
	nd = 1 + (b & 0x1f);        /* number of distance codes */
	DUMPBITS(5)
	NEEDBITS(4)
	nb = 4 + (b & 0xf);         /* number of bit length codes */
	DUMPBITS(4)

	/* read in bit-length-code lengths */
	for (j = 0; j < nb; j++) {
		NEEDBITS(3)
		ll[rz_border[j]] = b & 7;
		DUMPBITS(3)
	}

	for (; j < 19; j++) {
		ll[rz_border[j]] = 0;
	}

	/* build decoding table for trees--single level, 7 bit lookup */
	bl = 7;

	sub_GAME_7F0CE8B0(ll, 19, 19, NULL, NULL, &tl, &bl);

	/* read in literal and distance code lengths */
	n = nl + nd;
	m = rz_mask_bits[bl];
	i = l = 0;

	while (i < n) {
		NEEDBITS(bl)
		j = (td = tl + (b & m))->b;
		DUMPBITS(j)

		j = td->v.n;

		if (j < 16) {                 /* length of code in bits (0..15) */
			ll[i++] = l = j;          /* save last length in l */
		} else if (j == 16) {         /* repeat last length 3 to 6 times */
			NEEDBITS(2)
			j = 3 + (b & 3);
			DUMPBITS(2)

			while (j--) {
				ll[i++] = l;
			}
		} else if (j == 17) {         /* 3 to 10 zero length codes */
			NEEDBITS(3)
			j = 3 + (b & 7);
			DUMPBITS(3)

			while (j--) {
				ll[i++] = 0;
			}

			l = 0;
		} else {                      /* j == 18: 11 to 138 zero length codes */
			NEEDBITS(7)
			j = 11 + (b & 0x7f);
			DUMPBITS(7)

			while (j--) {
				ll[i++] = 0;
			}

			l = 0;
		}
	}

	/* restore the global bit buffer */
	rz_bb = b;
	rz_bk = k;

	/* build the decoding tables for literal/length and distance codes */
	bl = rz_lbits;

	sub_GAME_7F0CE8B0(ll, nl, 257, rz_cplens, rz_cplext, &tl, &bl);

	bd = rz_dbits;

	sub_GAME_7F0CE8B0(ll + nl, nd, 0, rz_cpdist, rz_cpdext, &td, &bd);

	/* decompress until an end-of-block code */
	sub_GAME_7F0CEEF0(tl, td, bl, bd);

	return 0;
}


s32 select_zlib_decompression_routine(s32 *e)
{
	u32 t;                /* block type */
	register u32 b = rz_bb;  /* bit buffer */
	register u32 k = rz_bk;  /* number of bits in bit buffer */

	/* make local bit buffer */
	b = rz_bb;
	k = rz_bk;

	/* read in last block bit */
	NEEDBITS(1)
	*e = b & 1;
	DUMPBITS(1)

	/* read in last block type */
	NEEDBITS(2)
	t = b & 3;
	DUMPBITS(2)

	/* restore the global bit buffer */
	rz_bb = b;
	rz_bk = k;

	/* inflate that block type */
	if (t == 2) {
		return zlib_decompressor_type2();
	}

	if (t == 0) {
		return zlib_decompressor_type0();
	}

	if (t == 1) {
		return zlib_decompressor_type1();
	}

	/* bad block type */
	return 2;
}



int loop_to_decompress_entire_file(void) {
  int e;
  int r;
  unsigned h;
  
  rz_wp = 0;
  rz_bk = 0;
  rz_bb = 0;

  h = 0;

  do {
    rz_hufts = 0;
    
    if ((r = select_zlib_decompression_routine(&e)) != 0) 
      return r;
    if (rz_hufts > h) 
      h = rz_hufts;
  } while (!e);

  while (rz_bk >= 8) {
    rz_bk -= 8;
    rz_inptr--;
  }

  return 0;
}
