#include <ultra64.h>
#include <bondgame.h>
#include <memp.h>
#include "lvl_text.h"
#include "ob.h"

// bss
//CODE.bss:8008C640
s32 g_LangBanks[45];


//CODE.bss:8008C6F4
struct jpncharpixels* g_JpnCharCachePixels;
//CODE.bss:8008C6F8
struct  jpncacheitem *g_JpnCacheCacheItems;


#ifdef LANG_JP
s32 j_text_trigger = 1;
#else
/**
 * EU .data 80041150
*/
s32 j_text_trigger = 0;
#endif


#if defined(LANG_US) || defined(LANG_JP)

void *LnameX_lookuptable[45][2] = {
    {NULL, NULL},                    /* Null (unused) */
    {"LameE", "LameJ"},              /* Library (multi) */
    {"LarchE", "LarchJ"},            /* Archives */
    {"LarkE", "LarkJ"},              /* Facility */
    {"LashE", "LashJ"},              /* Stack (multi) */
    {"LaztE", "LaztJ"},              /* Aztec */
    {"LcatE", "LcatJ"},              /* Citadel (multi) */
    {"LcaveE", "LcaveJ"},            /* Caverns */
    {"LarecE", "LarecJ"},            /* Control */
    {"LcradE", "LcradJ"},            /* Cradle */
    {"LcrypE", "LcrypJ"},            /* Egypt */
    {"LdamE", "LdamJ"},              /* Dam */
    {"LdepoE", "LdepoJ"},            /* Depot */
    {"LdestE", "LdestJ"},            /* Frigate */
    {"LdishE", "LdishJ"},            /* Temple (multi) */
    {"LearE", "LearJ"},              /* Ear (unused) */
    {"LeldE", "LeldJ"},              /* Eld (unused) */
    {"LimpE", "LimpJ"},              /* Basement (multi) */
    {"LjunE", "LjunJ"},              /* Jungle */
    {"LleeE", "LleeJ"},              /* Lee (unused) */
    {"LlenE", "LlenJ"},              /* Cuba */
    {"LlipE", "LlipJ"},              /* Lip (unused) */
    {"LlueE", "LlueJ"},              /* Lue (unused) */
    {"LoatE", "LoatJ"},              /* Cave (multi) */
    {"LpamE", "LpamJ"},              /* Pam (unused) */
    {"LpeteE", "LpeteJ"},            /* Streets */
    {"LrefE", "LrefJ"},              /* Complex (multi) */
    {"LritE", "LritJ"},              /* Rit (unused) */
    {"LrunE", "LrunJ"},              /* Runway */
    {"LsevbE", "LsevbJ"},            /* Bunker 2 */
    {"LsevE", "LsevJ"},              /* Bunker 1 */
    {"LsevxE", "LsevxJ"},            /* Surface 1 */
    {"LsevxbE", "LsevxbJ"},          /* Surface 2 */
    {"LshoE", "LshoJ"},              /* Shooting Range (unused) */
    {"LsiloE", "LsiloJ"},            /* Silo */
    {"LstatE", "LstatJ"},            /* Statue */
    {"LtraE", "LtraJ"},              /* Train */
    {"LwaxE", "LwaxJ"},              /* Wax (unused) */
    {"LgunE", "LgunJ"},              /* Guns */
    {"LtitleE", "LtitleJ"},          /* Stage and menu titles */
    {"LmpmenuE", "LmpmenuJ"},        /* Multi menus */
    {"LpropobjE", "LpropobjJ"},      /* In-game pickups */
    {"LmpweaponsE", "LmpweaponsJ"},  /* Multi weapon select */
    {"LoptionsE", "LoptionsJ"},      /* Solo in-game menus */
    {"LmiscE", "LmiscJ"}};           /* Cheat options */

#endif

#if defined(LANG_EU)
void *LnameX_lookuptable[45][2] = {
    {NULL, NULL},                    /* Null (unused) */
    {"LameP", "LameJ"},              /* Library (multi) */
    {"LarchP", "LarchJ"},            /* Archives */
    {"LarkP", "LarkJ"},              /* Facility */
    {"LashP", "LashJ"},              /* Stack (multi) */
    {"LaztP", "LaztJ"},              /* Aztec */
    {"LcatP", "LcatJ"},              /* Citadel (multi) */
    {"LcaveP", "LcaveJ"},            /* Caverns */
    {"LarecP", "LarecJ"},            /* Control */
    {"LcradP", "LcradJ"},            /* Cradle */
    {"LcrypP", "LcrypJ"},            /* Egypt */
    {"LdamP", "LdamJ"},              /* Dam */
    {"LdepoP", "LdepoJ"},            /* Depot */
    {"LdestP", "LdestJ"},            /* Frigate */
    {"LdishP", "LdishJ"},            /* Temple (multi) */
    {"LearP", "LearJ"},              /* Ear (unused) */
    {"LeldP", "LeldJ"},              /* Eld (unused) */
    {"LimpP", "LimpJ"},              /* Basement (multi) */
    {"LjunP", "LjunJ"},              /* Jungle */
    {"LleeP", "LleeJ"},              /* Lee (unused) */
    {"LlenP", "LlenJ"},              /* Cuba */
    {"LlipP", "LlipJ"},              /* Lip (unused) */
    {"LlueP", "LlueJ"},              /* Lue (unused) */
    {"LoatP", "LoatJ"},              /* Cave (multi) */
    {"LpamP", "LpamJ"},              /* Pam (unused) */
    {"LpeteP", "LpeteJ"},            /* Streets */
    {"LrefP", "LrefJ"},              /* Complex (multi) */
    {"LritP", "LritJ"},              /* Rit (unused) */
    {"LrunP", "LrunJ"},              /* Runway */
    {"LsevbP", "LsevbJ"},            /* Bunker 2 */
    {"LsevP", "LsevJ"},              /* Bunker 1 */
    {"LsevxP", "LsevxJ"},            /* Surface 1 */
    {"LsevxbP", "LsevxbJ"},          /* Surface 2 */
    {"LshoP", "LshoJ"},              /* Shooting Range (unused) */
    {"LsiloP", "LsiloJ"},            /* Silo */
    {"LstatP", "LstatJ"},            /* Statue */
    {"LtraP", "LtraJ"},              /* Train */
    {"LwaxP", "LwaxJ"},              /* Wax (unused) */
    {"LgunP", "LgunJ"},              /* Guns */
    {"LtitleP", "LtitleJ"},          /* Stage and menu titles */
    {"LmpmenuP", "LmpmenuJ"},        /* Multi menus */
    {"LpropobjP", "LpropobjJ"},      /* In-game pickups */
    {"LmpweaponsP", "LmpweaponsJ"},  /* Multi weapon select */
    {"LoptionsP", "LoptionsJ"},      /* Solo in-game menus */
    {"LmiscP", "LmiscJ"}};           /* Cheat options */
#endif

LEVELID get_textbank_number_for_stagenum(LEVELID level)
{
    LEVELID return_id;

    switch(level)
    {
        case LEVELID_DAM:
            return_id = LDAM;
            break;
        case LEVELID_FACILITY:
            return_id = LARK;
            break;
        case LEVELID_RUNWAY:
            return_id = LRUN;
            break;
        case LEVELID_SURFACE:
            return_id = LSEVX;
            break;
        case LEVELID_BUNKER1:
            return_id = LSEV;
            break;
        case LEVELID_SILO:
            return_id = LSILO;
            break;
        case LEVELID_FRIGATE:
            return_id = LDEST;
            break;
        case LEVELID_SURFACE2:
            return_id = LSEVXB;
            break;
        case LEVELID_BUNKER2:
            return_id = LSEVB;
            break;
        case LEVELID_STATUE:
            return_id = LSTAT;
            break;
        case LEVELID_ARCHIVES:
            return_id = LARCH;
            break;
        case LEVELID_STREETS:
            return_id = LPETE;
            break;
        case LEVELID_DEPOT:
            return_id = LDEPO;
            break;
        case LEVELID_TRAIN:
            return_id = LTRA;
            break;
        case LEVELID_JUNGLE:
            return_id = LJUN;
            break;
        case LEVELID_CONTROL:
            return_id = LAREC;
            break;
        case LEVELID_CAVERNS:
            return_id = LCAVE;
            break;
        case LEVELID_CRADLE:
            return_id = LCRAD;
            break;
        case LEVELID_AZTEC:
            return_id = LAZT;
            break;
        case LEVELID_EGYPT:
            return_id = LCRYP;
            break;
        case LEVELID_TEMPLE:
            return_id = LDISH;
            break;
        case LEVELID_COMPLEX:
            return_id = LREF;
            break;
        case LEVELID_LIBRARY:
            return_id = LAME;
            break;
        case LEVELID_BASEMENT:
            return_id = LIMP;
            break;
        case LEVELID_STACK:
            return_id = LASH;
            break;
        case LEVELID_CAVES:
            return_id = LOAT;
            break;
        case LEVELID_CUBA:
            return_id = LLEN;
            break;
        default:
        {
            /* infinite loop on invalid text bank */
            while(1) {};
        }
    }

    return return_id;
}


void init_LnameX(void) {
    s32 i;

    if (j_text_trigger) {
        g_JpnCharCachePixels = mempAllocBytesInBank(0x2E80, MEMPOOL_PERMANENT);
        g_JpnCacheCacheItems = mempAllocBytesInBank(0x100, MEMPOOL_PERMANENT);
        for(i = 0;i != 124;i++) {
            g_JpnCacheCacheItems[i].ttl =0;
            g_JpnCacheCacheItems[i].codepoint =-1;
        }
    }

	for (i = 0; i < 45; i++) {
		g_LangBanks[i] = 0;
	}
    g_LangBanks[LGUN] = _fileNameLoadToBank(LnameX_lookuptable[LGUN][j_text_trigger], FILELOADMETHOD_DEFAULT, 0x100, MEMPOOL_PERMANENT);
    g_LangBanks[LTITLE] = _fileNameLoadToBank(LnameX_lookuptable[LTITLE][j_text_trigger], FILELOADMETHOD_DEFAULT, 0x100, MEMPOOL_PERMANENT);
    g_LangBanks[LMPMENU] = _fileNameLoadToBank(LnameX_lookuptable[LMPMENU][j_text_trigger], FILELOADMETHOD_DEFAULT, 0x100, MEMPOOL_PERMANENT);
    g_LangBanks[LPROPOBJ] = _fileNameLoadToBank(LnameX_lookuptable[LPROPOBJ][j_text_trigger], FILELOADMETHOD_DEFAULT, 0x100, MEMPOOL_PERMANENT);
    g_LangBanks[LMPWEAPONS] = _fileNameLoadToBank(LnameX_lookuptable[LMPWEAPONS][j_text_trigger], FILELOADMETHOD_DEFAULT, 0x100, MEMPOOL_PERMANENT);
    g_LangBanks[LOPTIONS] = _fileNameLoadToBank(LnameX_lookuptable[LOPTIONS][j_text_trigger], FILELOADMETHOD_DEFAULT, 0x100, MEMPOOL_PERMANENT);
    g_LangBanks[LMISC] = _fileNameLoadToBank(LnameX_lookuptable[LMISC][j_text_trigger], FILELOADMETHOD_DEFAULT, 0x100, MEMPOOL_PERMANENT);
}





#ifdef NONMATCHING
void something_with_LnameJ(void)
{
    ushort uVar1;
    ushort *puVar2;
    int iVar3;
    
    iVar3 = 0;
    if (j_text_trigger != 0) {
        do {
            puVar2 = (ushort *)(g_JpnCacheCacheItems + iVar3);
            if (*puVar2 >> 0xe == 0) {
                uVar1 = puVar2[1];
            }
            else {
                *(byte *)puVar2 = ((byte)(*puVar2 >> 0xe) - 1) * '@' | *(byte *)puVar2 & 0x3f;
                puVar2 = (ushort *)(g_JpnCacheCacheItems + iVar3);
                uVar1 = puVar2[1];
            }
            if (uVar1 >> 0xe == 0) {
                uVar1 = puVar2[2];
            }
            else {
                *(byte *)(puVar2 + 1) =
                     ((byte)(uVar1 >> 0xe) - 1) * '@' | *(byte *)(puVar2 + 1) & 0x3f;
                puVar2 = (ushort *)(g_JpnCacheCacheItems + iVar3);
                uVar1 = puVar2[2];
            }
            if (uVar1 >> 0xe == 0) {
                uVar1 = puVar2[3];
            }
            else {
                *(byte *)(puVar2 + 2) =
                     ((byte)(uVar1 >> 0xe) - 1) * '@' | *(byte *)(puVar2 + 2) & 0x3f;
                puVar2 = (ushort *)(g_JpnCacheCacheItems + iVar3);
                uVar1 = puVar2[3];
            }
            iVar3 += 8;
            if (uVar1 >> 0xe != 0) {
                *(byte *)(puVar2 + 3) =
                     ((byte)(uVar1 >> 0xe) - 1) * '@' | *(byte *)(puVar2 + 3) & 0x3f;
            }
        } while (iVar3 != 0xf8);
    }
    return;
}
#else
GLOBAL_ASM(
.text
glabel something_with_LnameJ
/* 0F6470 7F0C1940 3C0E8005 */  lui   $t6, %hi(j_text_trigger) 
/* 0F6474 7F0C1944 8DCE84D0 */  lw    $t6, %lo(j_text_trigger)($t6)
/* 0F6478 7F0C1948 00001825 */  move  $v1, $zero
/* 0F647C 7F0C194C 240600F8 */  li    $a2, 248
/* 0F6480 7F0C1950 11C00035 */  beqz  $t6, .L7F0C1A28
/* 0F6484 7F0C1954 3C058009 */   lui   $a1, %hi(g_JpnCacheCacheItems)
/* 0F6488 7F0C1958 24A5C6F8 */  addiu $a1, %lo(g_JpnCacheCacheItems) # addiu $a1, $a1, -0x3908
/* 0F648C 7F0C195C 8CAF0000 */  lw    $t7, ($a1)
.L7F0C1960:
/* 0F6490 7F0C1960 01E31021 */  addu  $v0, $t7, $v1
/* 0F6494 7F0C1964 94440000 */  lhu   $a0, ($v0)
/* 0F6498 7F0C1968 0004C382 */  srl   $t8, $a0, 0xe
/* 0F649C 7F0C196C 5300000A */  beql  $t8, $zero, .L7F0C1998
/* 0F64A0 7F0C1970 94440002 */   lhu   $a0, 2($v0)
/* 0F64A4 7F0C1974 904A0000 */  lbu   $t2, ($v0)
/* 0F64A8 7F0C1978 2719FFFF */  addiu $t9, $t8, -1
/* 0F64AC 7F0C197C 00194980 */  sll   $t1, $t9, 6
/* 0F64B0 7F0C1980 314BFF3F */  andi  $t3, $t2, 0xff3f
/* 0F64B4 7F0C1984 012B6025 */  or    $t4, $t1, $t3
/* 0F64B8 7F0C1988 A04C0000 */  sb    $t4, ($v0)
/* 0F64BC 7F0C198C 8CAD0000 */  lw    $t5, ($a1)
/* 0F64C0 7F0C1990 01A31021 */  addu  $v0, $t5, $v1
/* 0F64C4 7F0C1994 94440002 */  lhu   $a0, 2($v0)
.L7F0C1998:
/* 0F64C8 7F0C1998 00047382 */  srl   $t6, $a0, 0xe
/* 0F64CC 7F0C199C 51C0000A */  beql  $t6, $zero, .L7F0C19C8
/* 0F64D0 7F0C19A0 94440004 */   lhu   $a0, 4($v0)
/* 0F64D4 7F0C19A4 90480002 */  lbu   $t0, 2($v0)
/* 0F64D8 7F0C19A8 25CFFFFF */  addiu $t7, $t6, -1
/* 0F64DC 7F0C19AC 000FC980 */  sll   $t9, $t7, 6
/* 0F64E0 7F0C19B0 310AFF3F */  andi  $t2, $t0, 0xff3f
/* 0F64E4 7F0C19B4 032A4825 */  or    $t1, $t9, $t2
/* 0F64E8 7F0C19B8 A0490002 */  sb    $t1, 2($v0)
/* 0F64EC 7F0C19BC 8CAB0000 */  lw    $t3, ($a1)
/* 0F64F0 7F0C19C0 01631021 */  addu  $v0, $t3, $v1
/* 0F64F4 7F0C19C4 94440004 */  lhu   $a0, 4($v0)
.L7F0C19C8:
/* 0F64F8 7F0C19C8 00046382 */  srl   $t4, $a0, 0xe
/* 0F64FC 7F0C19CC 5180000A */  beql  $t4, $zero, .L7F0C19F8
/* 0F6500 7F0C19D0 94440006 */   lhu   $a0, 6($v0)
/* 0F6504 7F0C19D4 90580004 */  lbu   $t8, 4($v0)
/* 0F6508 7F0C19D8 258DFFFF */  addiu $t5, $t4, -1
/* 0F650C 7F0C19DC 000D7980 */  sll   $t7, $t5, 6
/* 0F6510 7F0C19E0 3308FF3F */  andi  $t0, $t8, 0xff3f
/* 0F6514 7F0C19E4 01E8C825 */  or    $t9, $t7, $t0
/* 0F6518 7F0C19E8 A0590004 */  sb    $t9, 4($v0)
/* 0F651C 7F0C19EC 8CAA0000 */  lw    $t2, ($a1)
/* 0F6520 7F0C19F0 01431021 */  addu  $v0, $t2, $v1
/* 0F6524 7F0C19F4 94440006 */  lhu   $a0, 6($v0)
.L7F0C19F8:
/* 0F6528 7F0C19F8 24630008 */  addiu $v1, $v1, 8
/* 0F652C 7F0C19FC 00044B82 */  srl   $t1, $a0, 0xe
/* 0F6530 7F0C1A00 11200007 */  beqz  $t1, .L7F0C1A20
/* 0F6534 7F0C1A04 00000000 */   nop   
/* 0F6538 7F0C1A08 904E0006 */  lbu   $t6, 6($v0)
/* 0F653C 7F0C1A0C 252BFFFF */  addiu $t3, $t1, -1
/* 0F6540 7F0C1A10 000B6980 */  sll   $t5, $t3, 6
/* 0F6544 7F0C1A14 31D8FF3F */  andi  $t8, $t6, 0xff3f
/* 0F6548 7F0C1A18 01B87825 */  or    $t7, $t5, $t8
/* 0F654C 7F0C1A1C A04F0006 */  sb    $t7, 6($v0)
.L7F0C1A20:
/* 0F6550 7F0C1A20 5466FFCF */  bnel  $v1, $a2, .L7F0C1960
/* 0F6554 7F0C1A24 8CAF0000 */   lw    $t7, ($a1)
.L7F0C1A28:
/* 0F6558 7F0C1A28 03E00008 */  jr    $ra
/* 0F655C 7F0C1A2C 00000000 */   nop   
)
#endif



extern u8 _efontchardataSegmentRomStart;
extern u8 _jfontchardataSegmentRomStart;
void romCopy(void *target, void *source, u32 size);

struct jpncharpixels *langGetJpnCharPixels(s32 codepoint)
{
	s32 i;
	s32 freeindexsingle = -1;
	s32 freeindexmulti = -1;
	s32 multibyte = 0;


	if (codepoint & 0x2000) {
		multibyte = 1;
	}


#define SHIFTAMOUNT 1
#define TMUL 8

	for (i = 0; i < 0x7C; i++) {
		if (!multibyte && (codepoint >> SHIFTAMOUNT) == g_JpnCacheCacheItems[i].codepoint) {
			break;
		}

		if (multibyte && i + 1 < 0x7C
				&& (codepoint >> SHIFTAMOUNT) == g_JpnCacheCacheItems[i].codepoint
				&& (codepoint >> SHIFTAMOUNT) == g_JpnCacheCacheItems[i + 1].codepoint) {
			break;
		}

		if (g_JpnCacheCacheItems[i].ttl == 0) {
			freeindexsingle = i;
		}

		if (g_JpnCacheCacheItems[i].ttl == 0 && g_JpnCacheCacheItems[i + 1].ttl == 0 && i + 1 < 0x7C) {
			freeindexmulti = i;
		}
	}

	if (i < 0x7C) {
		if (!multibyte) {
			g_JpnCacheCacheItems[i].ttl = 2;

			return &g_JpnCharCachePixels[i * TMUL];
		} else {
			g_JpnCacheCacheItems[i + 0].ttl = 2;
			g_JpnCacheCacheItems[i + 1].ttl = 2;

			return &g_JpnCharCachePixels[TMUL * i];
		}
	}


	if (!multibyte && freeindexsingle >= 0) {
		g_JpnCacheCacheItems[freeindexsingle].ttl = 2;
		g_JpnCacheCacheItems[freeindexsingle].codepoint = codepoint >> 1;

		romCopy(&g_JpnCharCachePixels[freeindexsingle * 8], (romptr_t) &_jfontchardataSegmentRomStart + (codepoint >> SHIFTAMOUNT) * 0x60, 0x60);

		return &g_JpnCharCachePixels[freeindexsingle * 8];
	}

	if (multibyte && freeindexmulti >= 0) {
		g_JpnCacheCacheItems[freeindexmulti + 0].ttl = 2;
		g_JpnCacheCacheItems[freeindexmulti + 1].ttl = 2;
		g_JpnCacheCacheItems[freeindexmulti + 0].codepoint = codepoint >> 1;
		g_JpnCacheCacheItems[freeindexmulti + 1].codepoint = codepoint >> 1;

		romCopy(&g_JpnCharCachePixels[freeindexmulti * 8], (romptr_t) &_efontchardataSegmentRomStart + ((codepoint & 0x1fff) >> SHIFTAMOUNT) * 0x80, 0x80);

		return &g_JpnCharCachePixels[freeindexmulti * 8];
	}

	return &g_JpnCharCachePixels[0];
}


void briefingLoadToBank(u32 id)
{
    g_LangBanks[id] = _fileNameLoadToBank(LnameX_lookuptable[id][j_text_trigger],1,0x100,MEMPOOL_STAGE);
}


void briefingLoadToAddr(int id,u8 *target,int size)
{
    g_LangBanks[id] = _fileNameLoadToAddr(LnameX_lookuptable[id][j_text_trigger],1,target,size);
}


void langClearBank(s32 textBank) {
    g_LangBanks[textBank] = 0;
}


u8 * langGet(s32 slotID)
{
    u32 * textbank_ptr = g_LangBanks[slotID >> 10]; /* get the text file bank ID index the text ptr table */
    u32 textslot_offset = textbank_ptr[slotID & 0x03FF]; /* load the textbank ptr table then get the slot's offset */

    u32 output_slot = textslot_offset; /* add the text slot offset to the base ptr to get the ptr to text file's slot */
    output_slot += (u32)textbank_ptr;
    return (textslot_offset != 0) ? (u8*)output_slot : NULL;
}
