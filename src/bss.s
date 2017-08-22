.section .bss
.global _BSS_START
_BSS_START:
/*.space 0x31080*/
rmonthread: .space 0x1B0
idlethread: .space 0x1B0
mainthread: .space 0x1B0
shedthread: .space 0x1B0
msgQ_Q_8005D9A0: .space 0x18
msgQ_buf_8005D9B8: .space 0x80
dword_8005DA38: .space 4
                .align 4
dword_8005DA40: .space 0xD8
dword_8005DB18: .space 0x18
dword_8005DB30: .space 0x10
dword_8005DB40: .space 0xB0
dword_8005DBF0: .space 0x800
byte_8005E3F0:  .space 1
byte_8005E3F1:  .space 1
byte_8005E3F2:  .space 1
byte_8005E3F3:  .space 1
dword_8005E3F4: .space 0xB0
dword_8005E4A4: .space 4
dword_8005E4A8: .space 4
                .space 0xC
dword_8005E4B8: .space 8
dword_8005E4C0: .space 4
dword_8005E4C4: .space 4
dword_8005E4C8: .space 4
dword_8005E4CC: .space 4
dword_8005E4D0: .space 8
dword_8005E4D8: .space 8
dword_8005E4E0: .space 0x38
dword_8005E518: .space 8
dword_8005E520: .space 4
dword_8005E524: .space 0xC
dword_8005E530: .space 0x1B0
dword_8005E6E0: .space 0x18
dword_8005E6F8: .space 0x20
dword_8005E718: .space 0x18
dword_8005E730: .space 0x20
dword_8005E750: .space 0x50
dword_8005E7A0: .space 0x10
byte_8005E7B0:  .space 1
                .align 2
dword_8005E7B4: .space 4
dword_8005E7B8: .space 4
                .align 4
dword_8005E7C0: .space 4
dword_8005E7C4: .space 4
                .space 0xC
dword_8005E7D4: .space 0x4EC
dword_8005ECC0: .space 4
dword_8005ECC4: .space 4
dword_8005ECC8: .space 4
dword_8005ECCC: .space 4
dword_8005ECD0: .space 0x600
dword_8005F2D0: .space 0x18
dword_8005F2E8: .space 0x108
dword_8005F3F0: .space 4
                .align 4
dword_8005F400: .space 4
dword_8005F404: .space 4
                .space 0x848
dword_8005FC50: .space 4
dword_8005FC54: .space 4
                .space 0x848
dword_800604A0: .space 4
dword_800604A4: .space 4
dword_800604A8: .space 4
                .align 4
dword_800604B0: .space 0x300
dword_800607B0: .space 0x10
dword_800607C0: .space 0xC
dword_800607CC: .space 4
dword_800607D0: .space 0xC
dword_800607DC: .space 4
dword_800607E0: .space 0x40
dword_80060820: .space 4
word_80060824:  .space 2
                .align 2
dword_80060828: .space 0x1C
dword_80060844: .space 4
                .space 0x10
dword_80060858: .space 4
                .space 0x10
dword_8006086C: .space 4
                .space 8
byte_80060878:  .space 1
byte_80060879:  .space 1
                .align 2
dword_8006087C: .space 4
dword_80060880: .space 4
dword_80060884: .space 4
dword_80060888: .space 4
                .align 4
dword_80060890: .space 0x400
dword_80060C90: .space 0x6B0
dword_80061340: .space 0x2300
dword_80063640: .space 0x18
dword_80063658: .space 4
dword_8006365C: .space 4
dword_80063660: .space 4
dword_80063664: .space 4
dword_80063668: .space 4
dword_8006366C: .space 4
dword_80063670: .space 4
dword_80063674: .space 0x5C
dword_800636D0: .space 0x18
dword_800636E8: .space 8
dword_800636F0: .space 0x20
dword_80063710: .space 0x10
dword_80063720: .space 4
dword_80063724: .space 4
dword_80063728: .space 4
dword_8006372C: .space 4
dword_80063730: .space 4
dword_80063734: .space 4
dword_80063738: .space 0x80
word_800637B8:  .space 2
                .align 2
                .space 0x78
                .space 2
word_80063836:  .space 2
dword_80063838: .space 4
dword_8006383C: .space 4
dword_80063840: .space 4
word_80063844:  .space 2
word_80063846:  .space 2
word_80063848:  .space 2
word_8006384A:  .space 2
word_8006384C:  .space 2
word_8006384E:  .space 2
dword_80063850: .space 4
dword_80063854: .space 4
dword_80063858: .space 4
                .align 4
dword_80063860: .space 0xF8
dword_80063958: .space 0xF8
dword_80063A50: .space 0x100
dword_80063B50: .space 0x54
dword_80063BA4: .space 4
dword_80063BA8: .space 4
                .align 4
dword_80063BB0: .space 4
                .align 3
dword_80063BB8: .space 4
                .align 4
dword_80063BC0: .space 4
dword_80063BC4: .space 4
dword_80063BC8: .space 4
                .align 4
dword_80063BD0: .space 4
dword_80063BD4: .space 4
dword_80063BD8: .space 4
                .space 0x14
dword_80063BF0: .space 4
                .align 3
dword_80063BF8: .space 4
                .space 0x20
dword_80063C1C: .space 4
dword_80063C20: .space 4
dword_80063C24: .space 4
dword_80063C28: .space 4
dword_80063C2C: .space 4
dword_80063C30: .space 4
dword_80063C34: .space 4
dword_80063C38: .space 4
dword_80063C3C: .space 4
                .space 8
dword_80063C48: .space 0xFC0
dword_80064C08: .space 8
dword_80064C10: .space 8
dword_80064C18: .space 4
dword_80064C1C: .space 4
dword_80064C20: .space 4
dword_80064C24: .space 4
                .align 4
dword_80064C30: .space 4
                .space 0x27C
dword_80064EB0: .space 0x20
dword_80064ED0: .space 0x20
dword_80064EF0: .space 0x20
dword_80064F10: .space 0x20
dword_80064F30: .space 0x1E0
dword_80065110: .space 4
dword_80065114: .space 4
dword_80065118: .space 4
dword_8006511C: .space 4
                .space 0xC
dword_8006512C: .space 0x1E0
dword_8006530C: .space 4
                .space 4
dword_80065314: .space 4
                .space 0xC
dword_80065324: .space 4
dword_80065328: .space 0x28
dword_80065350: .space 0x18
dword_80065368: .space 8
dword_80065370: .space 0x18
dword_80065388: .space 8
dword_80065390: .space 0x18
dword_800653A8: .space 8
dword_800653B0: .space 0x18
dword_800653C8: .space 8
dword_800653D0: .space 0x18
byte_800653E8:  .space 3
byte_800653EB:  .space 1
                .space 3
byte_800653EF:  .space 1
                .space 3
byte_800653F3:  .space 1
                .space 3
byte_800653F7:  .space 1
dword_800653F8: .space 0x1A8
dword_800655A0: .space 0x100
dword_800656A0: .space 0x100
dword_800657A0: .space 0x20
dword_800657C0: .space 0x20
dword_800657E0: .space 4
                .align 4
dword_800657F0: .space 0x1B0
dword_800659A0: .space 0x1000
dword_800669A0: .space 0x18
dword_800669B8: .space 0x18
word_800669D0:  .space 2
byte_800669D2:  .space 1
                .align 2
dword_800669D4: .space 4
                .space 0x10
word_800669E8:  .space 2
byte_800669EA:  .space 1
                .align 2
dword_800669EC: .space 4
                .align 5
word_80066A00:  .space 2
                .align 4
dword_80066A10: .space 0x40
dword_80066A50: .space 4
                .space 0x3C
dword_80066A90: .space 0x40
dword_80066AD0: .space 0x1B0
dword_80066C80: .space 0x1000
dword_80067C80: .space 0x18
dword_80067C98: .space 8
dword_80067CA0: .space 0x3C
dword_80067CDC: .space 4
byte_80067CE0:  .space 1
byte_80067CE1:  .space 1
                .align 3
dword_80067CE8: .space 0x20
dword_80067D08: .space 0x18
dword_80067D20: .space 0x10
dword_80067D30: .space 0x3C
dword_80067D6C: .space 4
dword_80067D70: .space 0x3C
dword_80067DAC: .space 4
dword_80067DB0: .space 8
dword_80067DB8: .space 0x18
flt_80067DD0:   .space 4
                .align 4
flt_80067DE0:   .space 4
                .space 0x100C
dword_80068DF0: .space 0x20
dword_80068E10: .space 4
dword_80068E14: .space 4
dword_80068E18: .space 4
dword_80068E1C: .space 4
dword_80068E20: .space 4
                .align 4
dword_80068E30: .space 0x18
dword_80068E48: .space 4
                .align 4
qword_80068E50: .space 8
                .space 0x30
qword_80068E88: .space 8
qword_80068E90: .space 8
qword_80068E98: .space 8
                .space 0xA8
qword_80068F48: .space 8
                .space 0x90
dword_80068FE0: .space 8
dword_80068FE8: .space 0x18
dword_80069000: .space 4
byte_80069004:  .space 1
byte_80069005:  .space 1
byte_80069006:  .space 1
byte_80069007:  .space 1
byte_80069008:  .space 1
                .align 2
dword_8006900C: .space 4
                .space 4
dword_80069014: .space 0x60
dword_80069074: .space 4
                .space 0xF8
dword_80069170: .space 0x2D0
dword_80069440: .space 0x18
dword_80069458: .space 0xC0
dword_80069518: .space 0x20
dword_80069538: .space 4
                .align 4
dword_80069540: .space 4
                .align 4
dword_80069550: .space 4
dword_80069554: .space 4
dword_80069558: .space 4
dword_8006955C: .space 4
dword_80069560: .space 4
dword_80069564: .space 4
dword_80069568: .space 4
dword_8006956C: .space 4
dword_80069570: .space 4
flt_80069574:   .space 4
dword_80069578: .space 4
flt_8006957C:   .space 4
dword_80069580: .space 4
word_80069584:  .space 2
                .align 2
dword_80069588: .space 4
dword_8006958C: .space 4
dword_80069590: .space 4
dword_80069594: .space 4
                .align 4
flt_800695A0:   .space 4
flt_800695A4:   .space 4
flt_800695A8:   .space 4
flt_800695AC:   .space 4
flt_800695B0:   .space 4
flt_800695B4:   .space 4
flt_800695B8:   .space 4
flt_800695BC:   .space 4
flt_800695C0:   .space 4
                .align 3
flt_800695C8:   .space 4
flt_800695CC:   .space 4
flt_800695D0:   .space 4
                .align 3
flt_800695D8:   .space 4
flt_800695DC:   .space 4
flt_800695E0:   .space 4
dword_800695E4: .space 4
flt_800695E8:   .space 4
flt_800695EC:   .space 4
flt_800695F0:   .space 4
                .align 3
flt_800695F8:   .space 4
flt_800695FC:   .space 4
flt_80069600:   .space 4
                .align 3
flt_80069608:   .space 4
flt_8006960C:   .space 4
flt_80069610:   .space 4
flt_80069614:   .space 4
flt_80069618:   .space 4
                .align 4
dword_80069620: .space 0x30
                .space 1
byte_80069651:  .space 3
                .space 0x4C
byte_800696A0:  .space 1
byte_800696A1:  .space 1
byte_800696A2:  .space 1
byte_800696A3:  .space 1
                .space 0x44
                .space 3
byte_800696EB:  .space 1
                .align 4
dword_800696F0: .space 4
dword_800696F4: .space 4
                .space 0x18
dword_80069710: .space 4
dword_80069714: .space 4
dword_80069718: .space 4
dword_8006971C: .space 4
dword_80069720: .space 4
dword_80069724: .space 4
dword_80069728: .space 4
dword_8006972C: .space 4
dword_80069730: .space 4
dword_80069734: .space 4
dword_80069738: .space 4
dword_8006973C: .space 4
dword_80069740: .space 4
dword_80069744: .space 4
dword_80069748: .space 4
dword_8006974C: .space 4
dword_80069750: .space 4
dword_80069754: .space 4
dword_80069758: .space 4
dword_8006975C: .space 4
dword_80069760: .space 4
dword_80069764: .space 4
dword_80069768: .space 4
dword_8006976C: .space 4
dword_80069770: .space 4
dword_80069774: .space 4
dword_80069778: .space 4
dword_8006977C: .space 4
dword_80069780: .space 4
dword_80069784: .space 4
dword_80069788: .space 4
dword_8006978C: .space 4
dword_80069790: .space 4
dword_80069794: .space 4
dword_80069798: .space 4
dword_8006979C: .space 4
dword_800697A0: .space 4
                .align 3
dword_800697A8: .space 4
dword_800697AC: .space 4
dword_800697B0: .space 4
dword_800697B4: .space 4
dword_800697B8: .space 4
dword_800697BC: .space 4
dword_800697C0: .space 4
dword_800697C4: .space 4
dword_800697C8: .space 4
dword_800697CC: .space 4
dword_800697D0: .space 4
dword_800697D4: .space 4
dword_800697D8: .space 4
dword_800697DC: .space 4
dword_800697E0: .space 4
dword_800697E4: .space 4
dword_800697E8: .space 4
                .align 4
dword_800697F0: .space 0x130
dword_80069920: .space 8
dword_80069928: .space 0x58
dword_80069980: .space 0x180
dword_80069B00: .space 0x60
dword_80069B60: .space 4
                .align 4
dword_80069B70: .space 4
dword_80069B74: .space 4
dword_80069B78: .space 4
                .space 0xB4
dword_80069C30: .space 4
dword_80069C34: .space 4
dword_80069C38: .space 0x24
dword_80069C5C: .space 4
                .space 0xC
dword_80069C6C: .space 0x24
dword_80069C90: .space 4
                .align 4
dword_80069CA0: .space 0x24
dword_80069CC4: .space 4
                .space 0xC
dword_80069CD4: .space 0x34
dword_80069D08: .space 0x34
dword_80069D3C: .space 0x34
dword_80069D70: .space 0x34
dword_80069DA4: .space 0x7874
dword_80071618: .space 4
dword_8007161C: .space 4
dword_80071620: .space 4
                .space 0x90
dword_800716B4: .space 0x73C
dword_80071DF0: .space 4
dword_80071DF4: .space 4
dword_80071DF8: .space 4
                .align 4
dword_80071E00: .space 4
dword_80071E04: .space 4
dword_80071E08: .space 0x70
flt_80071E78:   .space 4
dword_80071E7C: .space 4
dword_80071E80: .space 0xFF0
dword_80072E70: .space 0x500
dword_80073370: .space 0xA50
dword_80073DC0: .space 0x1270
dword_80075030: .space 0xB40
dword_80075B70: .space 4
dword_80075B74: .space 4
flt_80075B78:   .space 4
flt_80075B7C:   .space 4
flt_80075B80:   .space 4
                .align 3
flt_80075B88:   .space 4
flt_80075B8C:   .space 4
flt_80075B90:   .space 4
                .align 3
dword_80075B98: .space 0x6C
dword_80075C04: .space 0xC
dword_80075C10: .space 0x78
dword_80075C88: .space 0x78
dword_80075D00: .space 4
dword_80075D04: .space 4
dword_80075D08: .space 4
dword_80075D0C: .space 4
dword_80075D10: .space 4
dword_80075D14: .space 4
dword_80075D18: .space 4
dword_80075D1C: .space 4
dword_80075D20: .space 4
dword_80075D24: .space 4
dword_80075D28: .space 4
                .align 4
dword_80075D30: .space 4
dword_80075D34: .space 4
dword_80075D38: .space 0x20
dword_80075D58: .space 4
dword_80075D5C: .space 4
dword_80075D60: .space 0x20
dword_80075D80: .space 4
dword_80075D84: .space 4
dword_80075D88: .space 4
dword_80075D8C: .space 4
dword_80075D90: .space 4
                .align 4
flt_80075DA0:   .space 4
                .align 4
dword_80075DB0: .space 4
                .align 3
dword_80075DB8: .space 4
dword_80075DBC: .space 4
dword_80075DC0: .space 4
dword_80075DC4: .space 4
dword_80075DC8: .space 0x9C
dword_80075E64: .space 4
dword_80075E68: .space 0xBE0
dword_80076A48: .space 8
dword_80076A50: .space 0xC
dword_80076A5C: .space 4
                .space 4
dword_80076A64: .space 0xC
dword_80076A70: .space 4
dword_80076A74: .space 4
dword_80076A78: .space 0xC
dword_80076A84: .space 4
dword_80076A88: .space 4
dword_80076A8C: .space 0x14
dword_80076AA0: .space 0x14
dword_80076AB4: .space 0x14
dword_80076AC8: .space 0x14
dword_80076ADC: .space 0x2E2C
dword_80079908: .space 0x28
dword_80079930: .space 4
dword_80079934: .space 4
                .align 4
flt_80079940:   .space 4
flt_80079944:   .space 4
flt_80079948:   .space 4
flt_8007994C:   .space 4
flt_80079950:   .space 4
flt_80079954:   .space 4
flt_80079958:   .space 4
flt_8007995C:   .space 4
flt_80079960:   .space 4
flt_80079964:   .space 4
flt_80079968:   .space 4
flt_8007996C:   .space 4
flt_80079970:   .space 4
flt_80079974:   .space 4
flt_80079978:   .space 4
flt_8007997C:   .space 4
flt_80079980:   .space 4
                .align 4
flt_80079990:   .space 4
flt_80079994:   .space 4
flt_80079998:   .space 4
dword_8007999C: .space 4
dword_800799A0: .space 4
                .align 3
flt_800799A8:   .space 4
flt_800799AC:   .space 4
flt_800799B0:   .space 4
dword_800799B4: .space 4
dword_800799B8: .space 4
flt_800799BC:   .space 4
flt_800799C0:   .space 4
flt_800799C4:   .space 4
flt_800799C8:   .space 4
                .align 4
flt_800799D0:   .space 4
flt_800799D4:   .space 4
flt_800799D8:   .space 4
                .align 4
dword_800799E0: .space 4
dword_800799E4: .space 4
flt_800799E8:   .space 4
flt_800799EC:   .space 4
flt_800799F0:   .space 4
dword_800799F4: .space 4
dword_800799F8: .space 4
dword_800799FC: .space 4
flt_80079A00:   .space 4
flt_80079A04:   .space 4
flt_80079A08:   .space 4
flt_80079A0C:   .space 4
flt_80079A10:   .space 4
dword_80079A14: .space 4
dword_80079A18: .space 4
dword_80079A1C: .space 4
dword_80079A20: .space 4
dword_80079A24: .space 4
dword_80079A28: .space 0x200
dword_80079C28: .space 4
                .space 0x3C
dword_80079C68: .space 4
                .align 4
dword_80079C70: .space 0x130
dword_80079DA0: .space 4
dword_80079DA4: .space 4
dword_80079DA8: .space 0x20
dword_80079DC8: .space 0x3C
flt_80079E04:   .space 4
flt_80079E08:   .space 4
flt_80079E0C:   .space 4
flt_80079E10:   .space 4
                .align 4
dword_80079E20: .space 4
                .align 4
byte_80079E30:  .space 1
byte_80079E31:  .space 1
byte_80079E32:  .space 1
byte_80079E33:  .space 1
                .space 0x44
                .space 3
byte_80079E7B:  .space 1
                .align 4
flt_80079E80:   .space 4
flt_80079E84:   .space 4
flt_80079E88:   .space 4
                .align 4
dword_80079E90: .space 4
                .align 3
dword_80079E98: .space 0x48
dword_80079EE0: .space 4
dword_80079EE4: .space 4
dword_80079EE8: .space 4
dword_80079EEC: .space 4
dword_80079EF0: .space 0x24
dword_80079F14: .space 4
                .space 0x30
dword_80079F48: .space 4
flt_80079F4C:   .space 4
                .space 4
flt_80079F54:   .space 4
                .space 1
byte_80079F59:  .space 1
byte_80079F5A:  .space 1
byte_80079F5B:  .space 1
                .space 0x2C
dword_80079F88: .space 4
                .space 0x30
flt_80079FBC:   .space 4
                .space 4
flt_80079FC4:   .space 4
                .space 1
byte_80079FC9:  .space 1
byte_80079FCA:  .space 1
byte_80079FCB:  .space 1
                .space 0x30
dword_80079FFC: .space 4
                .space 0x2C
flt_8007A02C:   .space 4
                .space 4
flt_8007A034:   .space 4
                .space 1
byte_8007A039:  .space 1
byte_8007A03A:  .space 1
byte_8007A03B:  .space 1
                .space 0x34
dword_8007A070: .space 4
                .space 0x28
flt_8007A09C:   .space 4
                .space 4
flt_8007A0A4:   .space 4
                .space 1
byte_8007A0A9:  .space 1
byte_8007A0AA:  .space 1
byte_8007A0AB:  .space 1
                .align 4
dword_8007A0B0: .space 4
dword_8007A0B4: .space 4
dword_8007A0B8: .space 4
dword_8007A0BC: .space 4
dword_8007A0C0: .space 4
dword_8007A0C4: .space 4
dword_8007A0C8: .space 4
dword_8007A0CC: .space 4
dword_8007A0D0: .space 4
dword_8007A0D4: .space 4
dword_8007A0D8: .space 4
dword_8007A0DC: .space 4
dword_8007A0E0: .space 4
dword_8007A0E4: .space 4
dword_8007A0E8: .space 4
dword_8007A0EC: .space 4
word_8007A0F0:  .space 2
word_8007A0F2:  .space 2
                .align 4
dword_8007A100: .space 0x40
dword_8007A140: .space 4
dword_8007A144: .space 4
dword_8007A148: .space 4
dword_8007A14C: .space 4
dword_8007A150: .space 4
dword_8007A154: .space 4
                .align 4
dword_8007A160: .space 4
dword_8007A164: .space 4
                .align 4
dword_8007A170: .space 4
word_8007A174:  .space 2
                .align 2
                .space 0x368
dword_8007A4E0: .space 4
word_8007A4E4:  .space 2
                .align 2
                .space 0xBB0
dword_8007B098: .space 8
dword_8007B0A0: .space 0x40
dword_8007B0E0: .space 0x40
dword_8007B120: .space 4
                .align 3
dword_8007B128: .space 4
dword_8007B12C: .space 4
dword_8007B130: .space 4
dword_8007B134: .space 0x220
dword_8007B354: .space 4
dword_8007B358: .space 0x684
dword_8007B9DC: .space 4
                .space 4
dword_8007B9E4: .space 4
dword_8007B9E8: .space 4
                .align 4
flt_8007B9F0:   .space 4
flt_8007B9F4:   .space 4
flt_8007B9F8:   .space 4
flt_8007B9FC:   .space 4
flt_8007BA00:   .space 4
dword_8007BA04: .space 4
                .space 4
dword_8007BA0C: .space 4
dword_8007BA10: .space 4
                .space 0x57C
dword_8007BF90: .space 4
dword_8007BF94: .space 4
dword_8007BF98: .space 4
                .align 4
byte_8007BFA0:  .space 1
                .align 2
                .space 0x94
dword_8007C038: .space 4
                .align 4
dword_8007C040: .space 0x60
dword_8007C0A0: .space 0x60
dword_8007C100: .space 0x38C0
dword_8007F9C0: .space 0x5C0
dword_8007FF80: .space 4
dword_8007FF84: .space 4
dword_8007FF88: .space 4
dword_8007FF8C: .space 4
dword_8007FF90: .space 4
dword_8007FF94: .space 4
dword_8007FF98: .space 4
                .align 4
dword_8007FFA0: .space 4
dword_8007FFA4: .space 4
                .space 0x1658
dword_80081600: .space 0x10
dword_80081610: .space 4
                .align 3
dword_80081618: .space 0xFA0
dword_800825B8: .space 8
dword_800825C0: .space 4
dword_800825C4: .space 4
flt_800825C8:   .space 4
flt_800825CC:   .space 4
                .space 8
flt_800825D8:   .space 4
flt_800825DC:   .space 4
flt_800825E0:   .space 4
flt_800825E4:   .space 4
dword_800825E8: .space 4
dword_800825EC: .space 4
dword_800825F0: .space 4
                .align 3
dword_800825F8: .space 4
flt_800825FC:   .space 4
flt_80082600:   .space 4
                .space 0x14
dword_80082618: .space 4
dword_8008261C: .space 4
byte_80082620:  .space 1
byte_80082621:  .space 1
byte_80082622:  .space 1
                .align 2
                .space 0x3C
word_80082660:  .space 2
                .align 3
dword_80082668: .space 4
                .space 0x4A4
word_80082B10:  .space 2
word_80082B12:  .space 2
                .align 3
word_80082B18:  .space 2
                .align 2
                .space 0x7FC
dword_80083318: .space 8
dword_80083320: .space 0x130
dword_80083450: .space 4
                .space 0x4AC
dword_80083900: .space 4
                .space 0x4AC
dword_80083DB0: .space 0x4B00
dword_800888B0: .space 4
dword_800888B4: .space 4
                .space 0xC
dword_800888C4: .space 0x10
byte_800888D4:  .space 1
                .align 2
dword_800888D8: .space 0x3958
dword_8008C230: .space 4
dword_8008C234: .space 4
dword_8008C238: .space 4
                .align 4
dword_8008C240: .space 4
dword_8008C244: .space 4
dword_8008C248: .space 4
dword_8008C24C: .space 4
byte_8008C250:  .space 1
                .align 2
dword_8008C254: .space 4
                .align 4
dword_8008C260: .space 4
                .align 4
dword_8008C270: .space 0xC
                .space 3
byte_8008C27F:  .space 1
                .space 0x100
dword_8008C380: .space 0xE8
dword_8008C468: .space 0xC
                .space 3
byte_8008C477:  .space 1
                .space 0x14
                .space 2
word_8008C48E:  .space 2
                .space 0x160
dword_8008C5F0: .space 4
dword_8008C5F4: .space 4
dword_8008C5F8: .space 4
                .align 4
dword_8008C600: .space 4
dword_8008C604: .space 4
dword_8008C608: .space 4
dword_8008C60C: .space 4
dword_8008C610: .space 4
dword_8008C614: .space 4
dword_8008C618: .space 4
dword_8008C61C: .space 4
dword_8008C620: .space 4
dword_8008C624: .space 4
dword_8008C628: .space 4
dword_8008C62C: .space 4
dword_8008C630: .space 4
dword_8008C634: .space 4
                .align 4
dword_8008C640: .space 4
dword_8008C644: .space 0x94
dword_8008C6D8: .space 4
dword_8008C6DC: .space 4
dword_8008C6E0: .space 4
dword_8008C6E4: .space 4
dword_8008C6E8: .space 4
dword_8008C6EC: .space 4
dword_8008C6F0: .space 4
dword_8008C6F4: .space 4
dword_8008C6F8: .space 4
                .align 4
dword_8008C700: .space 4
dword_8008C704: .space 4
dword_8008C708: .space 4
dword_8008C70C: .space 4
dword_8008C710: .space 4
dword_8008C714: .space 4
dword_8008C718: .space 4
dword_8008C71C: .space 4
dword_8008C720: .space 4
dword_8008C724: .space 4
                .align 4
word_8008C730:  .space 2
                .align 2
                .space 0x95C
dword_8008D090: .space 4
dword_8008D094: .space 4
                .align 4
dword_8008D0A0: .space 4
dword_8008D0A4: .space 4
dword_8008D0A8: .space 4
                .align 4
dword_8008D0B0: .space 4
dword_8008D0B4: .space 4
dword_8008D0B8: .space 4
dword_8008D0BC: .space 4
dword_8008D0C0: .space 4
dword_8008D0C4: .space 4
dword_8008D0C8: .space 4
dword_8008D0CC: .space 4
dword_8008D0D0: .space 4
dword_8008D0D4: .space 4
dword_8008D0D8: .space 4
dword_8008D0DC: .space 4
dword_8008D0E0: .space 4
dword_8008D0E4: .space 4
dword_8008D0E8: .space 4
dword_8008D0EC: .space 4
dword_8008D0F0: .space 4
dword_8008D0F4: .space 4
dword_8008D0F8: .space 4
dword_8008D0FC: .space 4
dword_8008D100: .space 4
dword_8008D104: .space 4
dword_8008D108: .space 4
dword_8008D10C: .space 4
dword_8008D110: .space 4
dword_8008D114: .space 4
dword_8008D118: .space 4
dword_8008D11C: .space 4
dword_8008D120: .space 4
dword_8008D124: .space 4
dword_8008D128: .space 4
dword_8008D12C: .space 4
dword_8008D130: .space 4
dword_8008D134: .space 4
                .align 4
dword_8008D140: .space 4
                .align 3
dword_8008D148: .space 0x160
dword_8008D2A8: .space 0xA0
dword_8008D348: .space 8
dword_8008D350: .space 4
dword_8008D354: .space 4
dword_8008D358: .space 4
dword_8008D35C: .space 4
dword_8008D360: .space 4
dword_8008D364: .space 4
dword_8008D368: .space 4
dword_8008D36C: .space 4
dword_8008D370: .space 0x400
dword_8008D770: .space 0xBA0
dword_8008E310: .space 4
dword_8008E314: .space 4
                .align 4
dword_8008E320: .space 4
dword_8008E324: .space 4
dword_8008E328: .space 4
dword_8008E32C: .space 4
dword_8008E330: .space 4
dword_8008E334: .space 4
byte_8008E338:  .space 1
byte_8008E339:  .space 1
byte_8008E33A:  .space 1
byte_8008E33B:  .space 1
byte_8008E33C:  .space 1
byte_8008E33D:  .space 1
byte_8008E33E:  .space 1
byte_8008E33F:  .space 1
byte_8008E340:  .space 1
byte_8008E341:  .space 1
byte_8008E342:  .space 1
byte_8008E343:  .space 1
byte_8008E344:  .space 1
byte_8008E345:  .space 1
byte_8008E346:  .space 1
byte_8008E347:  .space 1
byte_8008E348:  .space 1
byte_8008E349:  .space 1
byte_8008E34A:  .space 1
byte_8008E34B:  .space 1
byte_8008E34C:  .space 1
byte_8008E34D:  .space 1
word_8008E34E:  .space 2
word_8008E350:  .space 2
word_8008E352:  .space 2
word_8008E354:  .space 2
                .align 4

_BSS_END:

