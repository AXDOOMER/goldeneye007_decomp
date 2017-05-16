arch n64.cpu
endian msb
output "rodata.bin", create
base origin()
include "../code/stack.inc"
include "../lib/N64.INC"
base $80020D90
rodata_start:

rspcode_start:
insert rsp.bin, "rsp.bin"
rspcode_end:

dword_80023040:
dw $00

dword_80023044:
dw $02

cart_hw_address:
dw $10000000

debug_handler_table:
dw sp_boot, aBoot
dw sp_rmon, aRmon
dw sp_idle, aIdle
dw sp_shed, aShed
dw sp_main, aMain
dw sp_audi, aAudi

dword_8002307C:
dw $00

dw $00, $00, $00, $00, $00

display_stderror:
dw $00

stderr_event_enabled:
dw $00

display_stderr_event:
dw 0

dword_800230A0:
dw 0x2AEA540

dword_800230A4:
dw 0

dword_800230A8:
dw 0

dword_800230AC:
dw 0

dword_800230B0:
dw 0

dw 0x3F800000 //float
dw 0x3F800000 //float

flt_800230BC:
dw 0x3F800000 //float
dw 0x3F800000 //float
dw 0
dw 0

dword_800230CC:
dw 1

dword_800230D0:
dw 0

tlb_segment_num:
dw 0
dw 0
dw 0

qword_800230E0:
dd 0xAB8D9F7781280783
dw 0
dw 0
dw 0

dword_800230F4:
dw 0

dword_800230F8:
dw 0

dword_800230FC:
dw 0

dword_80023100:
dw 6
dw 0x00001900, 0x00000000, 0xA0, 0x2666, 0xFFFFD99A, 0x0, 0x0, 0x0
dw 0x0, 0xA0, 0x140, 0x2666, 0xFFFFD99A, 0x2B84, 0x0, 0x0
dw  0x2500, 0x320, 0xA00, 0x4000, 0xFFFFC000, 0x11EB, 0x0, 0x0
dw 0x3000, 0xC80, 0x15E0, 0x4000, 0xFFFFC000, 0x11EB, 0x0, 0x0
dw 0x3500, 0xD20, 0x12C0, 0x2000, 0xFFFFE000, 0x0, 0x0, 0x0

stru_800231A4:
dw 0x4000, 0, 0x1720, 0x32C8, 0xFFFFCD38, 0, 0x17C, 0xA
dw 0x4500

dword_800231C8:
dw 1
dw 0
dw 0

stru_800231D4:
 dw 0, 0
 dw 2, 0
 dw 1, 0
 dw 2, 0
 dw 2, 0xFF000000
 dw 2, 0
 dw 3, 0x9200
 dw 4, 0xFFFFFFFF
 dw 4, 0xDB000000
 dw 4, 0xFFFFFFFF

dword_80023224:
 dw 0

dword_80023228:
 dw 0

dword_8002322C:
 dw 0

counterforframes:
 dw 0

dword_80023234:
 dw 1
 dw 0
 dw 0
 dw 0

macro video_settings(var1, width1, height1, fov1, aspect, fov2, var2, width2, height2, width3, height3, var3, var4, var5) {
 dw {var1}
 dh {width1}
 dh {height1}
 float32 {fov1}
 float32 {aspect}
 float32 {fov2}
 float32 {var2}
 dh {width2}
 dh {height2}
 dh {width3}
 dh {height3}
 dw {var3}
 dw {var4}
 dw {var5}
}

video1_settings:
 video_settings(0, 320, 240, 60.0, 1.3333334, 30.0, 10000.0, 320, 240, 320, 240, 0, 1, 0)
video2_settings:
 video_settings(0, 320, 240, 60.0, 1.3333334, 30.0, 10000.0, 320, 240, 320, 240, 0, 1, 0)


CODE_rodata_8002329C:
 dw 0

CODE_rodata_800232A0:
 dw 0

ptr_video1_settings:
 dw video1_settings

ptr_video2_settings:
 dw video1_settings

coloroutputmode:
 dw 1

CODE_rodata_800232B0:
 dw 1

CODE_rodata_800232B4:
 dw 0

CODE_rodata_800232B8:
 dw 0

CODE_rodata_800232BC:
 db 0
 db 0
 db 0

CODE_rodata_800232BF:
 db 3

CODE_rodata_800232C0:
 dw 0

jpg_16bit_grabnum:
 dw	1

jpg_32bit_grabnum:
 dw	1

rgb_16bit_grabnum:
 dw	1

rgb_32bit_grabnum:
 dw	1
 dw 0
 dw 0
 dw 0

CODE_rodata_800232E0:
 dw 0
 dw 0

CODE_rodata_800232E8:
 dw 0
 dw 0
 dw 0
 dw 0

CODE_rodata_800232F8:
 dw 0x80060890
 dw 0
 dw 0

macro exception(var1, var2, label) {
dw {var1}, {var2}, {label}
}

debug_processor_eror_table:
exception(0x80000000, 0x80000000, aBd) // "BD"
exception(0x8000, 0x8000, aIp8) // "IP8"
exception(0x4000, 0x4000, aIp7) // "IP7"
exception(0x2000, 0x2000, aIp6) // "IP6"
exception(0x1000, 0x1000, aIp5) // "IP5"
exception(0x800, 0x800, aIp4) // "IP4"
exception(0x400, 0x400, aIp3) // "IP3"
exception(0x200, 0x200, aIp2) // "IP2"
exception(0x100, 0x100, aIp1) // "IP1"
exception(0x7C, 0, aInt) // "Int"
exception(0x7C, 4, aTlbmod) //	"TLBmod"
exception(0x7C, 8, aTlbload) // "TLBload"
exception(0x7C, 0xC, aTlbstore) // "TLBstore"
exception(0x7C, 0x10, aAddressErrorOnLoadOrInstructionFet) // "Address error on load or instruction fe"...
exception(0x7C, 0x14, aAddressErrorOnStore) //	"Address error on store"
exception(0x7C, 0x18, aBusErrorExceptionOnInstructionFetc) // "Bus error exception on instruction fetc"...
exception(0x7C, 0x1C, aBusErrorExceptionOnDataReference) // "Bus error exception on data reference"
exception(0x7C, 0x20, aSyscall) // "Syscall"
exception(0x7C, 0x24, aBrk) //	"Brk"
exception(0x7C, 0x28, aReservedInstruction) //	"Reserved instruction"
exception(0x7C, 0x2C, aCopUnusable) //	"Cop unusable"
exception(0x7C, 0x30, aOverflow) // "Overflow"
exception(0x7C, 0x34, aTrap) // "Trap"
exception(0x7C, 0x38, aVirtualCoherencyExceptionOnIntruct) // "Virtual coherency exception on intructi"...
exception(0x7C, 0x3C, aFpException) //	"Fp exception"
exception(0x7C, 0x5C, aWatchpoint) // "Watchpoint"
exception(0x7C, 0x7C, aVirtualCoherencyExceptionOnDataRef) // "Virtual coherency exception on data ref"...
exception(0, 0, aExceptionNULL_0) // ""
exception(0x80000000, 0x80000000, aCu3) // "CU3"
exception(0x40000000, 0x40000000, aCu2) // "CU2"
exception(0x20000000, 0x20000000, aCu1) // "CU1"
exception(0x10000000, 0x10000000, aCu0) // "CU0"
exception(0x8000000, 0x8000000, aRp) // "RP"
exception(0x4000000, 0x4000000, aFr) // "FR"
exception(0x2000000, 0x2000000, aRe) // "RE"
exception(0x400000, 0x400000, aBev) //	"BEV"
exception(0x200000, 0x200000, aTs) // "TS"
exception(0x100000, 0x100000, aSr) // "SR"
exception(0x40000, 0x40000, aCh) // "CH"
exception(0x20000, 0x20000, aCe) // "CE"
exception(0x10000, 0x10000, aDe) // "DE"
exception(0x8000, 0x8000, aIm8) // "IM8"
exception(0x4000, 0x4000, aIm7) // "IM7"
exception(0x2000, 0x2000, aIm6) // "IM6"
exception(0x1000, 0x1000, aIm5) // "IM5"
exception(0x800, 0x800, aIm4) // "IM4"
exception(0x400, 0x400, aIm3) // "IM3"
exception(0x200, 0x200, aIm2) // "IM2"
exception(0x100, 0x100, aIm1) // "IM1"
exception(0x80, 0x80, aKx) // "KX"
exception(0x40, 0x40, aSx) // "SX"
exception(0x20, 0x20, aUx) // "UX"
exception(0x18, 0x10, aUsr) //	"USR"
exception(0x18, 8, aSup) // "SUP"
exception(0x18, 0, aKer) // "KER"
exception(4, 4, aErl) // "ERL"
exception(2, 2, aExl) // "EXL"
exception(1, 1, aIe) // "IE"
exception(0, 0, aExceptionNULL_1) // ""
exception(0x1000000, 0x1000000, aFs) // "FS"
exception(0x800000, 0x800000, aC_1) //	"C"
exception(0x20000, 0x20000, aUnimplemented) //	"Unimplemented"
exception(0x10000, 0x10000, aInvalidOp) // "Invalid op"
exception(0x8000, 0x8000, aBy0_0) // "/ by 0.0"
exception(0x4000, 0x4000, aOverflow_0) // "Overflow"
exception(0x2000, 0x2000, aUnderflow) // "Underflow"
exception(0x1000, 0x1000, aInexactOp) // "Inexact op"
exception(0x800, 0x800, aEv) // "EV"
exception(0x400, 0x400, aEz) // "EZ"
exception(0x200, 0x200, aEo) // "EO"
exception(0x100, 0x100, aEu) // "EU"
exception(0x80, 0x80, aEi) // "EI"
exception(0x40, 0x40, aFv) // "FV"
exception(0x20, 0x20, aFz) // "FZ"
exception(0x10, 0x10, aFo) // "FO"
exception(8, 8, aFu) // "FU"
exception(4, 4, aFi) // "FI"
exception(3, 0, aRn) // "RN"
exception(3, 1, aRz) // "RZ"
exception(3, 2, aRp_1) // "RP"
exception(3, 3, aRm) // "RM"
exception(0, 0, aExceptionNULL)

CODE_rodata_800236DC:
dw sp_rmon
CODE_rodata_800236E0:
dw sp_idle
CODE_rodata_800236E4:
dw sp_shed
CODE_rodata_800236E8:
dw sp_main
CODE_rodata_800236EC:
dw sp_audi
CODE_rodata_800236F0:
dw sp_idle
CODE_rodata_800236F4:
dw sp_shed
CODE_rodata_800236F8:
dw sp_main
CODE_rodata_800236FC:
dw sp_audi
CODE_rodata_80023700:
dw sp_unknown
CODE_rodata_80023704:
dw sp_rmon
CODE_rodata_80023708:
dw sp_idle
CODE_rodata_8002370C:
dw sp_shed
CODE_rodata_80023710:
dw sp_main
CODE_rodata_80023714:
dw sp_audi

insert rodata.bin_filler, "021990.bin", origin(), ($800283D0 - $80023718)

base $800283D0
aBoot:
 db "boot", 0x0
 align(8)

//base $800283D8
aRmon:
 db "rmon", 0x0
 align(8)

//base $800283E0
aIdle:
 db "idle", 0x0
 align(8)

//base $800283E8
aShed:
 db "shed", 0x0
 align(8)

//base $800283F0
aMain:
 db "main", 0x0
 align(8)

//base $800283F8
aAudi:
 db "audi", 0x0
 align(8)


insert rodata.bin_filler2, "021990.bin", origin(), ($800287C0 - $80028400)

base $800287C0
aBd:
db "BD", 0, 0
aIp8:
db "IP8", 0
aIp7:
db "IP7", 0
aIp6:
db "IP6", 0
aIp5:
db "IP5", 0
aIp4:
db "IP4", 0
aIp3:
db "IP3", 0
aIp2:
db "IP2", 0
aIp1:
db "IP1", 0
aInt:
db "Int", 0
aTlbmod:
db "TLBmod", 0, 0
aTlbload:
db "TLBload", 0
aTlbstore:
db "TLBstore", 0, 0, 0, 0
aAddressErrorOnLoadOrInstructionFet:
db "Address error on load or instruction fetch", 0, 0
aAddressErrorOnStore:
db "Address error on store", 0, 0
aBusErrorExceptionOnInstructionFetc:
db "Bus error exception on instruction fetch", 0, 0, 0, 0
aBusErrorExceptionOnDataReference:
db "Bus error exception on data reference", 0, 0, 0
aSyscall:
db "Syscall", 0
aBrk:
db "Brk", 0
aReservedInstruction:
db "Reserved instruction", 0, 0, 0, 0
aCopUnusable:
db "Cop unusable", 0, 0, 0, 0
aOverflow:
db "Overflow", 0, 0, 0, 0
aTrap:
db "Trap", 0, 0, 0, 0
aVirtualCoherencyExceptionOnIntruct:
db "Virtual coherency exception on intruction fetch", 0
aFpException:
db "Fp exception", 0, 0, 0, 0
aWatchpoint:
db "Watchpoint", 0, 0
aVirtualCoherencyExceptionOnDataRef:
db "Virtual coherency exception on data reference", 0, 0, 0
aExceptionNULL_0:
db	0, 0, 0, 0
aCu3:
db "CU3", 0
aCu2:
db "CU2", 0
aCu1:
db "CU1", 0
aCu0:
db "CU0", 0
aRp:
db "RP", 0, 0
aFr:
db "FR", 0, 0
aRe:
db "RE", 0, 0
aBev:
db "BEV", 0
aTs:
db "TS", 0, 0
aSr:
db "SR", 0, 0
aCh:
db "CH", 0, 0
aCe:
db "CE", 0, 0
aDe:
db "DE", 0, 0
aIm8:
db "IM8", 0
aIm7:
db "IM7", 0
aIm6:
db "IM6", 0
aIm5:
db "IM5", 0
aIm4:
db "IM4", 0
aIm3:
db "IM3", 0
aIm2:
db "IM2", 0
aIm1:
db "IM1", 0
aKx:
db "KX", 0, 0
aSx:
db "SX", 0, 0
aUx:
db "UX", 0, 0
aUsr:
db "USR", 0
aSup:
db "SUP", 0
aKer:
db "KER", 0
aErl:
db "ERL", 0
aExl:
db "EXL", 0
aIe:
db "IE", 0, 0
aExceptionNULL_1:
db	0, 0, 0, 0
aFs:
db "FS", 0, 0
aC_1:
db "C", 0, 0, 0
aUnimplemented:
db "Unimplemented", 0, 0, 0
aInvalidOp:
db "Invalid op", 0, 0
aBy0_0:
db "/ by 0.0", 0, 0, 0, 0
aOverflow_0:
db "Overflow", 0, 0, 0, 0
aUnderflow:
db "Underflow", 0, 0, 0
aInexactOp:
db "Inexact op", 0, 0
aEv:
db "EV", 0, 0
aEz:
db "EZ", 0, 0
aEo:
db "EO", 0, 0
aEu:
db "EU", 0, 0
aEi:
db "EI", 0, 0
aFv:
db "FV", 0, 0
aFz:
db "FZ", 0, 0
aFo:
db "FO", 0, 0
aFu:
db "FU", 0, 0
aFi:
db "FI", 0, 0
aRn:
db "RN", 0, 0
aRz:
db "RZ", 0, 0
aRp_1:
db "RP", 0, 0
aRm:
db "RM", 0, 0
aExceptionNULL:
	dw 0

insert rodata.bin_raw, "021990.bin", origin()

base $8005D2E0
rodata_end:

