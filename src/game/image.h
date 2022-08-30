#ifndef _IMAGE_H_
#define _IMAGE_H_
#include <ultra64.h>
#include <bondconstants.h>

#define TEXFORMAT_RGBA32     0x00 // 32-bit RGBA (8/8/8/8)
#define TEXFORMAT_RGBA16     0x01 // 16-bit RGBA (5/5/5/1)
#define TEXFORMAT_RGB24      0x02 // 24-bit RGB (8/8/8)
#define TEXFORMAT_RGB15      0x03 // 15-bit RGB (5/5/5)
#define TEXFORMAT_IA16       0x04 // 16-bit grayscale+alpha
#define TEXFORMAT_IA8        0x05 // 8-bit grayscale+alpha (4/4)
#define TEXFORMAT_IA4        0x06 // 4-bit grayscale+alpha (3/1)
#define TEXFORMAT_I8         0x07 // 8-bit grayscale
#define TEXFORMAT_I4         0x08 // 4-bit grayscale
#define TEXFORMAT_RGBA16_CI8 0x09 // 16-bit 5551 paletted colour with 8-bit palette indexes
#define TEXFORMAT_RGBA16_CI4 0x0a // 16-bit 5551 paletted colour with 4-bit palette indexes
#define TEXFORMAT_IA16_CI8   0x0b // 16-bit 88 paletted greyscale+alpha with 8-bit palette indexes
#define TEXFORMAT_0C         0x0c

#define TEXCOMPMETHOD_UNCOMPRESSED0      0
#define TEXCOMPMETHOD_UNCOMPRESSED1      1
#define TEXCOMPMETHOD_HUFFMAN            2
#define TEXCOMPMETHOD_HUFFMANPERHCHANNEL 3
#define TEXCOMPMETHOD_RLE                4
#define TEXCOMPMETHOD_LOOKUP             5
#define TEXCOMPMETHOD_HUFFMANLOOKUP      6
#define TEXCOMPMETHOD_RLELOOKUP          7
#define TEXCOMPMETHOD_HUFFMANBLUR        8
#define TEXCOMPMETHOD_RLEBLUR            9

struct texturething {
	struct texloadthing *unk00;
	struct texloadthing *unk04;
	struct texloadthing *unk08;
	struct texloadthing *unk0c;
};

struct texloadthing {
	/*0x00*/ u16 texturenum : 12;
	/*0x00*/ u16 unk00_0c : 4;
	/*0x04*/ u32 unk04;
	/*0x08*/ u8 width;
	/*0x09*/ u8 height;
	/*0x0a*/ u8 unk0a;
	/*0x0b*/ u8 maxlod : 3;
	/*0x0b*/ u8 gbiformat : 3;
	/*0x0b*/ u8 depth : 2;
	/*0x0c*/ u32 lutmodeindex : 2;
	/*0x0c*/ u32 unk0c_02 : 1;
	/*0x0c*/ u32 unk0c_03 : 1;
	/*0x0c*/ u32 unk0c_04 : 24;
};

struct image_entry
{
    HIT_TYPE hitSound : 4;  //HitType-Sound
    HIT_TYPE hitTexture : 4;  //HitType-Texture
    s32  dataoffset    : 24; //this is u32 Size:24 - 24bit size/address
    char flag3; //Detailflag1 used once with value 0x38D2 (S/T offset of detail)
    char flag4; //DetailFlag2  difference from detail image, to large image, in terms of 2 to the power of value. It is subtracted from the small one, and absolute value or something. (Zoinkity)
    char flag5; //padding
    char flag6; //padding
};

struct texcacheitem {
    s16 texturenum;
    u8 widths[7];
    u8 heights[7];
};

extern struct texturething *ptr_texture_alloc_start;
extern struct image_entry g_Textures[];
extern s32 g_TexCacheCount;
extern u32 bytes;

void nullsub_41(s32 arg0);

void texInflateHuffman(u8 *dst, s32 numiterations, s32 chansize);
void texInflateRle(u8 *dst, s32 blockstotal);
void texReadAlphaBits(u8 *image,s32 count);
void texSwapAltRowBytes(u8 *dst, s32 width, s32 height, s32 format);
void texBlur(u8 *pixels, s32 width, s32 height, s32 method, s32 chansize);
s32 texAlignIndices(u8 *src, s32 width, s32 height, s32 format, u8 *dst);

s32 sub_GAME_7F0C6C70(u8 *src, u8 *dst, s32 srcwidth, s32 srcheight, s32 format, u16 *palette, s32 numcolours);

#endif
