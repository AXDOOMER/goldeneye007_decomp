arch n64.cpu
endian msb
output "rodata.bin", create
base origin()
include "../code/stack.inc"
include "../code/bss.inc"
include "../lib/N64.INC"
include "../lib/enums.inc"
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

macro debughandler(name, location, string) {
{name}:
 scope {name} {
 base $0
 ptr_addr:
  dw {location}
 string:
  dw {string}
 size:
 base ({name}+{name}.size)
 }
}

debug_handler_table:
 debughandler(dh_boot, sp_boot, aBoot)
 debughandler(dh_rmon, sp_rmon, aRmon)
 debughandler(dh_idle, sp_idle, aIdle)
 debughandler(dh_shed, sp_shed, aShed)
 debughandler(dh_main, sp_main, aMain)
 debughandler(dh_audi, sp_audi, aAudi)

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

 float32 1.0
 float32 1.0

flt_800230BC:
 float32 1.0
 float32 1.0
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

macro video_settings(name ,var1, width1, height1, fov1, aspect, fov2, var2, width2, height2, width3, height3, var3, var4, var5) {
{name}:
 scope {name} {
 base $0
 var1:
  dw {var1}
 width1:
  dh {width1}
 height1:
  dh {height1}
 fov1:
  float32 {fov1}
 aspect:
  float32 {aspect}
 fov2:
  float32 {fov2}
 var2:
  float32 {var2}
 width2:
  dh {width2}
 height2:
  dh {height2}
 width3:
  dh {width3}
 height3:
  dh {height3}
 var3:
  dw {var3}
 var4:
  dw {var4}
 var5:
  dw {var5}
 size:
 base ({name}+{name}.size)
 }
}

video_settings(video1_settings,0, 320, 240, 60.0, 1.3333334, 30.0, 10000.0, 320, 240, 320, 240, 0, 1, 0)

video_settings(video2_settings,0, 320, 240, 60.0, 1.3333334, 30.0, 10000.0, 320, 240, 320, 240, 0, 1, 0)


rodata_8002329C:
 dw 0

rodata_800232A0:
 dw 0

ptr_video1_settings:
 dw video1_settings

ptr_video2_settings:
 dw video1_settings

coloroutputmode:
 dw 1

rodata_800232B0:
 dw 1

rodata_800232B4:
 dw 0

rodata_800232B8:
 dw 0

rodata_800232BC:
 db 0
 db 0
 db 0

rodata_800232BF:
 db 3

rodata_800232C0:
 dw 0

jpg_16bit_grabnum:
 dw 1

jpg_32bit_grabnum:
 dw 1

rgb_16bit_grabnum:
 dw 1

rgb_32bit_grabnum:
 dw 1
align(16)

rodata_800232E0:
 dw 0
 dw 0

rodata_800232E8:
 dw 0
 dw 0
 dw 0
 dw 0

rodata_800232F8:
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
 exception(0x7C, 4, aTlbmod) // "TLBmod"
 exception(0x7C, 8, aTlbload) // "TLBload"
 exception(0x7C, 0xC, aTlbstore) // "TLBstore"
 exception(0x7C, 0x10, aAddressErrorOnLoadOrInstructionFet) // "Address error on load or instruction fe"...
 exception(0x7C, 0x14, aAddressErrorOnStore) // "Address error on store"
 exception(0x7C, 0x18, aBusErrorExceptionOnInstructionFetc) // "Bus error exception on instruction fetc"...
 exception(0x7C, 0x1C, aBusErrorExceptionOnDataReference) // "Bus error exception on data reference"
 exception(0x7C, 0x20, aSyscall) // "Syscall"
 exception(0x7C, 0x24, aBrk) // "Brk"
 exception(0x7C, 0x28, aReservedInstruction) // "Reserved instruction"
 exception(0x7C, 0x2C, aCopUnusable) // "Cop unusable"
 exception(0x7C, 0x30, aOverflow) // "Overflow"
 exception(0x7C, 0x34, aTrap) // "Trap"
 exception(0x7C, 0x38, aVirtualCoherencyExceptionOnIntruct) // "Virtual coherency exception on intructi"...
 exception(0x7C, 0x3C, aFpException) // "Fp exception"
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
 exception(0x400000, 0x400000, aBev) // "BEV"
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
 exception(0x18, 0x10, aUsr) // "USR"
 exception(0x18, 8, aSup) // "SUP"
 exception(0x18, 0, aKer) // "KER"
 exception(4, 4, aErl) // "ERL"
 exception(2, 2, aExl) // "EXL"
 exception(1, 1, aIe) // "IE"
 exception(0, 0, aExceptionNULL_1) // ""
 exception(0x1000000, 0x1000000, aFs) // "FS"
 exception(0x800000, 0x800000, aC_1) // "C"
 exception(0x20000, 0x20000, aUnimplemented) // "Unimplemented"
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

rodata_800236DC:
 dw sp_rmon

rodata_800236E0:
 dw sp_idle

rodata_800236E4:
 dw sp_shed

rodata_800236E8:
 dw sp_main

rodata_800236EC:
 dw sp_audi

rodata_800236F0:
 dw sp_idle

rodata_800236F4:
 dw sp_shed

rodata_800236F8:
 dw sp_main

rodata_800236FC:
 dw sp_audi

rodata_80023700:
 dw sp_unknown

rodata_80023704:
 dw sp_rmon

rodata_80023708:
 dw sp_idle

rodata_8002370C:
 dw sp_shed

rodata_80023710:
 dw sp_main

rodata_80023714:
 dw sp_audi

stderr_buffer:
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0


rodata_80023ED8:
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0

rodata_80023FB0:
 db 0

rodata_80023FB1:
 db 0
 db 0
 db 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0

rodata_80023FF8:
 dw 0

rodata_80023FFC:
 dw 0

std_error_font_bitcode:
 db    0,   0,   0,   0,0x22,0x22,   2,   0,0x55,   0
 db    0,   0,   5,0xF5,0xF5,   0,0x27,0x42,0x72,   0
 db    5,0x12,0x45,   0,0x34,0x25,0x53,   0,0x22,   0
 db    0,   0,0x24,0x44,0x44,0x20,0x42,0x22,0x22,0x40
 db    6,0xF6,0xF6,   0,   0,0x27,0x20,   0,   0,   0
 db    2,0x40,   0,   7,   0,   0,   0,   0,   2,   0
 db 0x11,0x22,0x44,0x80,0x25,0x55,0x52,   0,0x26,0x22
 db 0x27,   0,0x25,0x12,0x57,   0,0x61,0x21,0x16,   0
 db 0x33,0x55,0x73,   0,0x64,0x61,0x16,   0,0x24,0x65
 db 0x52,   0,0x71,0x11,0x22,   0,0x25,0x75,0x52,   0
 db 0x25,0x53,0x16,   0,   0,0x20,   2,   0,   0,0x20
 db    6,0x40,   1,0x24,0x21,   0,   0,0x70,0x70,   0
 db    4,0x21,0x24,   0,   7,0x12,   2,   0,0x25,0xFF
 db 0x57,   0,   2,0x55,0x7D,   0,   6,0x57,0x5E,   0
 db    7,0x44,0x53,   0,   7,0x55,0x56,   0,   7,0x56
 db 0x57,   0,   7,0x56,0x44,   0,   7,0xC9,0x57,   0
 db    5,0x57,0x55,   0,   7,0x22,0x27,   0,   3,0x11
 db 0x16,   0,   5,0x66,0x55,   0,   4,0x44,0x5F,   0
 db  0xD,0xFF,0x9D,   0, 0xF,0x77,0x7D,   0,   7,0xDD
 db 0x57,   0,   7,0x56,0x46,   0,   7,0x99,0x57,0x70
 db    7,0x56,0x55,   0,   7,0x46,0x1E,   0,   7,0x22
 db 0x22,   0, 0xD,0x99,0x96,   0, 0xD,0x55,0x22,   0
 db  0xD,0xF7,0x75,   0, 0xD,0x62,0x55,   0,   5,0x62
 db 0x26,   0,   7,0x12,0x57,   0,0x32,0x22,0x22,0x30
 db 0x44,0x22,0x21,0x10,0x62,0x22,0x22,0x60,0x25,   0
 db    0,   0,   0,   0,   7,   0,0x42,0x20,   0,   0
 db    0,0x67,0xD7,   0,0x44,0x75,0x57,   0,   0,0x78
 db 0x86,   0,0x11,0x7D,0xD7,   0,   0,0x6F,0xC7,   0
 db 0x32,0x72,0x27,   0,   0,0x7D,0xD7,0x30,0x44,0x75
 db 0x55,   0,   2,0x62,0x27,   0,   2,0x71,0x11,0x30
 db 0x44,0x76,0x65,   0,0x62,0x22,0x27,   0,   0,0xFF
 db 0xFF,   0,   0,0x75,0x5D,   0,   0,0x6D,0xD6,   0
 db    0,0x75,0x57,0x40,   0,0x79,0x97,0x10,   0,0x74
 db 0x46,   0,   0,0x77,0x57,   0,   2,0x72,0x23,   0
 db    0,0x55,0x57,   0,   0,0x55,0x22,   0,   0,0x57
 db 0x75,   0,   0,0x56,0x25,   0,   0,0x55,0x22,0x20
 db    0,0x70,0x37,   0,0x12,0x24,0x22,0x10,   2,0x22
 db 0x22,0x20,0x42,0x21,0x22,0x40,   0,0x5A,   0,   0

ptr_videobuffer1:
 dw 0

ptr_videobuffer2:
 dw 0


 dw 0,0,0,0,0,0,0

rodata_800241A0:
 dw 0

debug_and_update_stage_flag:
 dw 0

current_stage_num:
 dw 0x5A

current_m_malloc_value:
 dw 0x234800

// *current_ma_malloc_value
current_ma_malloc_value:
 dw 0x4B000

show_mem_use_flag:
 dw 0

show_mem_bars_flag:
 dw 0

macro memoryallocation(id, string) {
 dw {id}, {string}
}

memallocstringtable:
 memoryallocation(0x21, aMl0Me0Mgfx70Mvtx50Mt625Ma275) // "-ml0 -me0 -mgfx70  -mvtx50 -mt625 -ma27"...
 memoryallocation(0x22, aMl0Me0Mgfx70Mvtx50Mt650Ma160) // "-ml0 -me0 -mgfx70  -mvtx50 -mt650 -ma16"...
 memoryallocation(0x23, aMl0Me0Mgfx100Mvtx50Mt610Ma300) // "-ml0 -me0 -mgfx100 -mvtx50 -mt610 -ma30"...
 memoryallocation(0x24, aMl0Me0Mgfx70Mvtx50Mt600Ma300) // "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma30"...
 memoryallocation(9, aMl0Me0Mgfx100Mvtx50Mt700Ma150) // "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma15"...
 memoryallocation(0x14, aMl0Me0Mgfx70Mvtx50Mt660Ma150) // "-ml0 -me0 -mgfx70  -mvtx50 -mt660 -ma15"...
 memoryallocation(0x1A, aMl0Me0Mgfx70Mvtx50Mt750Ma225) // "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma22"...
 memoryallocation(0x2B, aMl0Me0Mgfx100Mvtx50Mt550Ma350) // "-ml0 -me0 -mgfx100 -mvtx50 -mt550 -ma35"...
 memoryallocation(0x1B, aMl0Me0Mgfx100Mvtx50Mt725Ma150) // "-ml0 -me0 -mgfx100 -mvtx50 -mt725 -ma15"...
 memoryallocation(0x16, aMl0Me0Mgfx70Mvtx50Mt750Ma220) // "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma22"...
 memoryallocation(0x18, aMl0Me0Mgfx70Mvtx50Mt600Ma250) // "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma25"...
 memoryallocation(0x1D, aMl0Me0Mgfx60Mvtx40Mt635Ma290) // "-ml0 -me0 -mgfx60  -mvtx40 -mt635 -ma29"...
 memoryallocation(0x1E, aMl0Me0Mgfx60Mvtx50Mt710Ma300) // "-ml0 -me0 -mgfx60  -mvtx50 -mt710 -ma30"...
 memoryallocation(0x19, aMl0Me0Mgfx100Mvtx50Mt600Ma200) // "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma20"...
 memoryallocation(0x25, aMl0Me0Mgfx70Mvtx50Mt500Ma200) // "-ml0 -me0 -mgfx70  -mvtx50 -mt500 -ma20"...
 memoryallocation(0x17, aMl0Me0Mgfx70Mvtx50Mt671Ma200) // "-ml0 -me0 -mgfx70  -mvtx50 -mt671 -ma20"...
 memoryallocation(0x29, aMl0Me0Mgfx100Mvtx50Mt650Ma250) // "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma25"...
 memoryallocation(0x27, aMl0Me0Mgfx100Mvtx50Mt530Ma250) // "-ml0 -me0 -mgfx100 -mvtx50 -mt530 -ma25"...
 memoryallocation(0x1C, aMl0Me0Mgfx60Mvtx40Mt855Ma135) // "-ml0 -me0 -mgfx60  -mvtx40 -mt855 -ma13"...
 memoryallocation(0x20, aMl0Me0Mgfx100Mvtx50Mt600Ma250) // "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma25"...
 memoryallocation(0x28, aMl0Me0Mgfx100Mvtx50Mt650Ma150) // "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma15"...
 memoryallocation(0x36, aMl0Me0Mgfx100Mvtx50Mt300Ma300) // "-ml0 -me0 -mgfx100 -mvtx50 -mt300 -ma30"...
 memoryallocation(0x5A, aMl0Me0Mgfx80Mvtx20Mt646Ma001) // "-ml0 -me0 -mgfx80 -mvtx20 -mt646 -ma001"
 memoryallocation(0x5B, aMl0Me0Mgfx60Mvtx20Mt500Ma001) // "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001"
 memoryallocation(0x63, aMl0Me0Mgfx60Mvtx20Mt500Ma001_0) // "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001"
 memoryallocation(0x26, aMl0Me0Mgfx130Mvtx100Mt390Ma100) // "-ml0 -me0 -mgfx130 -mvtx100 -mt390 -ma1"...
 memoryallocation(0x1F, aMl0Me0Mgfx130Mvtx100Mt400Ma100) // "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma1"...
 memoryallocation(0x30, aMl0Me0Mgfx130Mvtx100Mt400Ma100_0) // "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma1"...
 memoryallocation(0x2D, aMl0Me0Mgfx130Mvtx100Mt400Ma100_1) // "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma1"...
 memoryallocation(0x2E, aMl0Me0Mgfx130Mvtx100Mt400Ma100_2) // "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma1"...
 memoryallocation(0x32, aMl0Me0Mgfx130Mvtx100Mt400Ma300) // "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma3"...
 memoryallocation(0x1AB, aMl0Me0Mgfx130Mvtx100Mt550Ma170) // "-ml0 -me0 -mgfx130 -mvtx100 -mt550 -ma1"...
 memoryallocation(0x1A8, aMl0Me0Mgfx80Mvtx100Mt550Ma250) // "-ml0 -me0 -mgfx80  -mvtx100 -mt550 -ma2"...
 memoryallocation(0x1B7, aMl0Me0Mgfx130Mvtx100Mt440Ma220) // "-ml0 -me0 -mgfx130 -mvtx100 -mt440 -ma2"...
 memoryallocation(0x1B2, aMl0Me0Mgfx90Mvtx100Mt550Ma230) // "-ml0 -me0 -mgfx90  -mvtx100 -mt550 -ma2"...
 memoryallocation(0x1B0, aMl0Me0Mgfx110Mvtx100Mt350Ma400) // "-ml0 -me0 -mgfx110 -mvtx100 -mt350 -ma4"...
 memoryallocation(0, aMl0Me0Mgfx100Mvtx50Mt700Ma400) // "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma40"...
 memoryallocation(0,0)
 memoryallocation(0,0)
 memoryallocation(0,0)


loadedstage:
 dw 0xFFFFFFFF

activate_debug_feature_parsing:
 dw 0

rodata_80024304:
 dw 0x20000

rodata_80024308:
 dw 0

rodata_8002430C:
 dw 0

rodata_80024310:
 dw 0

rodata_80024314:
 dw 0

rodata_80024318:
 dw 0

rodata_8002431C:
 dw 0

rodata_80024320:
 dw 0

u64_taskgrab_num_core_ramdump_num:
 dw 1
 dw 0
 dw 0
 dw 0

music_track_num:
 dw 0

music1:
 dw 0x7FFF0000

rodata_8002433C:
 dw 0

music2:
 dw 0x7FFF0000

rodata_80024344:
 dw 0

rodata_80024348:
 dw 0x7FFF0000

rodata_8002434C:
 dw 0

rodata_80024350:
 dw 0

rodata_80024354:
 dw 0

music3:
 dh 0x6665

rodata_8002435A:
 dh 0x7332
 dh 0x7332
 dh 0x7998
 dh 0x7332
 dh 0x5998
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x7332
 dh 0x6665
 dh 0x7332
 dh 0x6665
 dh 0x6665
 dh 0x7332
 dh 0x7332
 dh 0x6665
 dh 0x3FFF
 dh 0x6665
 dh 0x6665
 dh 0x3FFF
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x7998
 dh 0x6665
 dh 0x5998
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x5998
 dh 0x6665
 dh 0x3332
 dh 0x6665
 dh 0x7332
 dh 0x7332
 dh 0x5998
 dh 0x7332
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6CCB
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x6665
 dh 0x7332
 dh 0x6665
 dh 0x7332
 dh 0x7998
 dh 0xFFFF
 dh 0
 dw 0
 dw 0

rodata_800243E4:
 dw 0

rodata_800243E8:
 dw 0

rodata_800243EC:
 dw 0

rodata_800243F0:
 dw 0x80063B50

rodata_800243F4:
 dw 0

rodata_800243F8:
 dw 0

rodata_800243FC:
 float32 1.0

rodata_80024400:
 dw 0

tied_to_mem_management:
 dw 0
 dw 0
 dw 0
 dw 0

rodata_80024414:
 dw 2

rodata_80024418:
 dw 0

rodata_8002441C:
 dw 4

rodata_80024420:
 dw 0x52

rodata_80024424:
 dw 6

rodata_80024428:
 dw 0xF

rodata_8002442C:
 dw 0

rodata_80024430:
 dw 0

rodata_80024434:
 dw 0

rodata_80024438:
 dw 0

rodata_8002443C:
 dw 0

rodata_80024440:
 dw 0

rodata_80024444:
 dw 0

rodata_80024448:
 dw 0

rodata_8002444C:
 dw 0

rodata_80024450:
 dw 0
align(16)

randseed:
 dd 0xAB8D9F7781280783
align(16)

strstr_numstings:
 dw 1

strstr_ptrcurrent_string:
 dw 0

rodata_80024478:
 dw 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0
 dw 0
 dw 0

rodata_80024500:
 dw 0, 0, 0, 0, 0, 0



start_resource:
 dw 0xB8000000,         0,         0,  0x227A00,  0x7A348B,  0x223434,  0x115811,  0x696900,         0,    0x9C00
 dw     0x4600,  0x460000,    0x4600,         0,         0,         0,         0,      0x46,  0x229C11,  0x346900
 dw   0x229C11,  0x699C11,    0x5834,  0xADAD34,  0x118B34,  0x9CAD7A,  0x229C11,  0x229C11,         0,         0
 dw          0,         0,         0,  0x113411,         0,  0x46CE00,  0xAD58DE,  0x466969,  0x9C9C69,  0x8B8B00
 dw   0x469C00,  0x22CE00,  0x583400,  0x345800,  0x7ACE69,    0x5800,         0,         0,         0,    0x3446
 dw   0x8B007A,  0x588B00,  0x8B008B,  0x22007A,  0x119C69,  0x8B0000,  0x9C1100,  0x22008B,  0x8B007A,  0x8B007A
 dw          0,         0,  0x225869,         0,0x69582200,  0x9C698B,         0,  0x46CE00,  0x222258,  0xDEEF7A
 dw   0xAD1111,  0x69EF9C,  0x8B0000,  0x460000,  0x8B0000,    0x8B00,  0x58CE34,    0x8B00,         0,         0
 dw          0,    0x8B00,  0x8B008B,    0x8B00,  0x11007A,  0x118B46,  0x58467A,  0xCEAD22,  0x9C8B00,    0x117A
 dw   0x698B46,  0x8B00AD,  0x34AD00,  0x34AD00,0x228B4600,0x8B8B8B8B,  0x468B22,  0x11008B,         0,    0x7A00
 dw          0,  0x9C9C00,  0x118B34,0x22ADBD46,  0x8B8B34,         0,  0x8B0000,    0x8B00,  0x7A2269,0x22ADEF9C
 dw          0,0x22ADADAD,         0,  0x226900,  0x8B008B,    0x8B00,    0x7A00,    0x117A,  0x9C347A,      0x8B
 dw   0xCE117A,    0x2269,  0x8B227A,  0x229C8B,    0x1100,    0x1100,0xAD580000,0x34343434,    0x58AD,    0xBD34
 dw          0,  0x112200,         0,0x22DEDE22,  0xCE5858,  0x46468B,  0x8BAD00,         0,  0x8B0000,    0x8B00
 dw          0,    0x8B00,    0x3400,         0,    0x2200,  0x691100,  0x8B008B,    0x8B00,  0x691158,  0x11008B
 dw   0x7A9CAD,0x1122008B,  0x8B008B,    0x8B00,  0x8B008B,    0x227A,    0x2200,    0x2200,0x228B4600,0x8B8B8B8B
 dw   0x468B22,    0x6900,         0,  0x228B00,         0,  0x8B8B00,  0x34BD00,  0x119C46,  0x7A6969,         0
 dw   0x583400,  0x345800,         0,    0x5800,  0x11FF00,         0,  0x228B00,  0x8B0000,  0x349C22,  0x8BCE69
 dw 0x22BDAD8B,  0x7A9C11,    0x8B8B,0x118B9C11,  0x349C22,    0x5800,  0x349C11,  0x588B11,  0x228B00,  0x69AD00
 dw   0x225869,         0,0x69582200,    0xBD00,         0,         0,         0,  0x464600,    0x4600,         0
 dw          0,         0,    0x4600,  0x460000,         0,         0,  0x583400,         0,         0,0x58340000
 dw          0,         0,         0,         0,         0,         0,         0,         0,         0,         0
 dw          0,  0x8B0000,         0,         0,         0,         0,  0x229C11,  0x221100,0x11223400,    0x3411
 dw 0x11342200,  0x343422,  0x343422,    0x2222,  0x220022,  0x342222,    0x3434,  0x341122,0x22341100,0x11110022
 dw 0x22221134,    0x2200,  0x343411,    0x3400,  0x343411,  0x113411,  0x343434,0x11341134,0x11220034,0x34220034
 dw 0x11340022,0x11220034,  0x223422,    0x8B34,  0x460000,  0x587A00,    0x5800,         0,0x348B008B,  0x69BD00
 dw 0x11DE7A58,  0xAD69DE,0x22CE7A9C,0x11CE7AAD,0x11CE7AAD,  0xAD7ADE,0x22CE00CE,  0x69CE58,    0x8BCE,0x22CE22CE
 dw 0x46CE4600,0x7ABD00FF,0x58FF46CE,  0xAD7A9C,0x11CE7A7A,  0xAD7A8B,0x22CE7A7A,0x118B7ABD,0x469CCECE,0x8B8B34CE
 dw 0x8B8B00BD,0xBD8B22BD,0x58CE00CE,0x22BD00CE,  0xBD7AAD,    0x8B00,  0x7A1100,    0x8B00,  0x694658,         0
 dw 0x468B7ABD,  0x588B22,  0x8B008B,0x46460011,  0x8B007A,0x118B3458,  0x8B3458,0x46460011,  0x8B008B,    0x8B00
 dw     0x117A,  0x8B7A11,  0x8B0000,0x589C58BD,0x11AD698B,0x4646007A,0x118B007A,0x5846007A,0x118B007A,0x46580011
 dw 0x34228B46,0x6934008B,  0x7A008B,0x58348B7A,0x11696946,  0x695846,  0x113458,    0x8B00,  0x116900,    0x8B00
 dw   0x110011,         0,0x468B8B9C,  0x9C228B,  0xDEAD7A,0x58340000,  0x8B007A,0x11DEAD00,  0xDEAD00,0x583400AD
 dw 0x46DEADBD,    0x8B00,0x3411117A,  0xDEAD00,  0x8B0000,0x5846AD7A,0x118B8B8B,0x5834007A,0x11DEAD34,0x5834007A
 dw 0x11DEDE46,  0x58AD34,    0x8B00,0x5834008B,  0x8B117A,  0xBDDE8B,  0x22AD00,  0x11BD00,  0x226900,    0x8B00
 dw     0x8B00,    0x8B00,         0,         0,0x348B348B,0x469C8BAD,  0x8B007A,0x347A0058,  0x8B009C,  0x8B008B
 dw   0x8B0000,0x228B007A,  0x8B008B,    0x8B00,0x46462269,  0x8B117A,  0x8B007A,0x6934347A,0x118B34DE,0x118B009C
 dw   0x8B0000,0x228B009C,  0x8B117A,0x3434008B,    0x8B00,0x4646008B,  0x22CE00,  0xADBD8B,  0x8B007A,    0x8B00
 dw   0x8B0058,    0x8B00,    0x3446,    0x8B00,         0,         0,  0x697A9C,0x7A9C00BD,0x69CEAD58,  0x58AD58
 dw 0x22BDAD34,0x22CEAD8B,0x22BD2200,  0x58AD58,0x22AD00CE,  0x8BBD7A,  0x7A7A00,0x22BD228B,0x69BDADBD,0x8B9C00BD
 dw 0x69CE227A,  0x58AD34,0x22CE6900,  0x9CEF69,0x22BD2258,0x7A9C9C22,  0x46CE34,  0x7AAD11,    0x5800,  0x580058
 dw 0x22AD00CE,  0x58BD34,  0xAD9C9C,    0x8B00,      0x8B,    0x8B00,         0,0x22222222,    0x2211,         0
 dw          0,         0,         0,         0,         0,         0,         0,         0,         0,         0
 dw          0,         0,         0,         0,         0,  0x58588B,         0,         0,         0,         0
 dw          0,         0,         0,         0,         0,    0xCE34,      0x7A,0x1158AD00,         0,0x7A7A7A7A
 dw   0x693400,         0,0x22690000,         0,      0x8B,         0,    0x589C,0x11000000,0x22690000,    0x1100
 dw     0x1100,0x22690000,  0x8B7A00,         0,         0,         0,         0,         0,         0,         0
 dw          0,         0,         0,         0,         0,         0,         0,    0x4646,    0x4600,  0x464600
 dw          0,         0,  0x46AD00,         0,  0x8B0000,         0,      0x8B,         0,  0x116900,         0
 dw   0x8B0000,    0x6900,    0x6900,  0x8B0000,    0x8B00,         0,         0,         0,         0,         0
 dw          0,         0,  0x226900,         0,         0,         0,         0,         0,         0,    0x8B00
 dw     0x8B00,    0x8B00,         0,         0,    0x5800,  0x8B9C34,  0xCEAD69,  0x7AAD9C,  0x8BADBD,  0x7AAD34
 dw   0x9CDE7A,  0x8B9CCE,0x11CEAD69,  0x589C00,  0x8BAD69,  0x8BAD69,    0x8B00,0x7AAD9C9C,0x22CEAD69,  0x7AAD34
 dw 0x22CEAD69,  0x8B9CDE,0x22DE9C69,  0x7AAD9C,  0x9CDE7A,0x118B00AD,0x11CE00DE,0x34CE00DE,0x22CE34AD,0x22CE00DE
 dw   0xBD9CAD,    0x8B00,    0x8B00,    0x8B00,0x229C347A,         0,         0,  0x9CAD7A,  0x8B007A,0x69340034
 dw 0x4634009C,0x46CE9CBD,  0x226900,0x4646008B,  0x8B008B,    0x8B00,      0x7A,  0xDE7A00,    0x8B00,0x46468B69
 dw 0x119C008B,0x4646008B,  0x8B0069,0x5846008B,  0x8B0000,  0x8B7A58,  0x226900,  0x8B008B,  0x7A117A,  0x8B8B8B
 dw   0x58BD00,  0x8B008B,  0x464646,  0x467A00,    0x8B00,    0x8B46,0x7A349C22,         0,         0,0x4634227A
 dw   0x9C007A,0x58460022,0x4646009C,0x34460034,  0x226900,0x3446009C,  0x8B008B,    0x8B00,      0x7A,  0x8B6911
 dw     0x8B00,0x46468B69,0x118B008B,0x3458008B,  0xAD0069,0x584600AD,  0x8B0000,  0x69348B,  0x226911,  0x8B009C
 dw   0x11DE00,  0xADBD8B,  0x699C11,  0x469C34,  0x225858,    0x8B00,    0x8B00,    0x8B00,         0,         0
 dw          0,0x119C8BCE,0x22ADAD58,  0x7A9C46,  0x69ADAD,0x1169AD46,  0x8BBD7A,  0x69ADAD,0x22AD00BD,0x118BCE69
 dw       0x7A,0x227A34CE,  0x8BBD7A,0x7A699C46,0x69BD00CE,  0x7A9C22,  0xBD9C58,  0x69ADAD,0x22CE9C34,  0x8BAD58
 dw     0x9C8B,  0x699CAD,0x11005800,  0x580069,0x11BD349C,    0x9C00,  0xADAD9C,    0x8B00,    0x8B00,    0x8B00
 dw          0,         0,         0,         0,         0,         0,         0,         0,         0,      0x8B
 dw          0,         0,    0x4646,         0,         0,         0,         0,         0,  0x8B0000,      0x8B
 dw          0,         0,         0,         0,         0,         0,         0,  0x226900,         0,    0x8B46
 dw     0x8B00,  0x467A00,         0,         0



debug_menu_x_pos_offset:
 dw 5

debug_menu_y_pos_offset:
 dw 1

debug_menu_x_text_pos:
 dw 0x18

debug_menu_y_text_pos:
 dw 0x10

stdout_display_list:
 dw 0xE7000000
 dw 0
 dw 0xBA001402, 0
 dw 0xBA000602, 0xC0, 0xB900031D, 0x500A4240, 0xFC30B261
 dw 0x5566DB6D, 0xBA001301, 0
 dw 0xB9000002, 0
 dw 0xFD700000, 0x80024520, 0xF5700000, 0x7000000, 0xE6000000
 dw 0
 dw 0xF3000000, 0x753F080, 0xE7000000, 0
 dw 0xF5682000, 0
 dw 0xF2000000, 0x1FC050, 0xE6000000, 0
 dw 0xB8000000
 dw 0

stdout_debug_menu_screen_buffer:
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0

stdout_primary_color_table:
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

stdout_environment_color_table:
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

num_enviroment_colors:
 dw 0
 dw a31m40m // 0x1B, "[31m", 0x1B, "[40m"
 dw a37m40m // 0x1B, "[37m", 0x1B, "[40m"
 dw a32m40m // 0x1B, "[32m", 0x1B, "[40m"
 dw a33m40m // 0x1B, "[33m", 0x1B, "[40m"
 dw a34m40m // 0x1B, "[34m", 0x1B, "[40m"
 dw a35m40m // 0x1B, "[35m", 0x1B, "[40m"
 dw a36m40m // 0x1B, "[36m", 0x1B, "[40m"
 dw a37m44m // 0x1B, "[37m", 0x1B, "[44m"
 dw a31m44m // 0x1B, "[31m", 0x1B, "[44m"
 dw a32m44m // 0x1B, "[32m", 0x1B, "[44m"
 dw a33m44m // 0x1B, "[33m", 0x1B, "[44m"
 dw a30m44m // 0x1B, "[30m", 0x1B, "[44m"
 dw a35m44m // 0x1B, "[35m", 0x1B, "[44m"
 dw a36m44m // 0x1B, "[36m", 0x1B, "[44m"
 dw a37m41m // 0x1B, "[37m", 0x1B, "[41m"
 dw a30m41m // 0x1B, "[30m", 0x1B, "[41m"
 dw a32m41m // 0x1B, "[32m", 0x1B, "[41m"
 dw a33m41m // 0x1B, "[33m", 0x1B, "[41m"
 dw a34m41m // 0x1B, "[34m", 0x1B, "[41m"
 dw a35m41m // 0x1B, "[35m", 0x1B, "[41m"
 dw a36m41m // 0x1B, "[36m", 0x1B, "[41m"
 dw a37m45m // 0x1B, "[37m", 0x1B, "[45m"
 dw a31m45m // 0x1B, "[31m", 0x1B, "[45m"
 dw a32m45m // 0x1B, "[32m", 0x1B, "[45m"
 dw a33m45m // 0x1B, "[33m", 0x1B, "[45m"
 dw a34m45m // 0x1B, "[34m", 0x1B, "[45m"
 dw a30m45m // 0x1B, "[30m", 0x1B, "[45m"
 dw a36m45m // 0x1B, "[36m", 0x1B, "[45m"
 dw a37m42m // 0x1B, "[37m", 0x1B, "[42m"
 dw a31m42m // 0x1B, "[31m", 0x1B, "[42m"
 dw a30m42m // 0x1B, "[30m", 0x1B, "[42m"
 dw a33m42m // 0x1B, "[33m", 0x1B, "[42m"
 dw 0

end_displaylist_command:
 dw 0xB8000000
 dw 0

blank_C0_command:
 dw 0xC0000000
 dw 0

stdout_primary_color:
 dw 0xFA000000

stdout_environment_color:
 dw 0xFFFFFF00

rodata_800268B0:
 dw 0xFB000000

rodata_800268B4:
 dw 0

rodata_800268B8:
 dw 0xFF
 dw 0

rodata_800268C0:
 dw 0

ptr_current_point_in_controller_input_index:
 dw 0x80064F30

rodata_800268C8:
 dw 0

rodata_800268CC:
 dw 0

num_controller_plugged_in_flags:
 dw 0

num_controller_plugged_in_flags_0:
 dw 0

controller_1_rumble_inserted:
 dw 0

controller_2_rumble_inserted:
 dw 0

controller_3_rumble_inserted:
 dw 0

controller_4_rumble_inserted:
 dw 0

controller_1_rumble_state:
 dw 0

controller_2_rumble_state:
 dw 0

controller_3_rumble_state:
 dw 0

controller_4_rumble_state:
 dw 0

controller_1_rumble_duration:
 dw 0

controller_2_rumble_duration:
 dw 0

controller_3_rumble_duration:
 dw 0

controller_4_rumble_duration:
 dw 0

controller_1_rumble_pulse:
 dw 0

controller_2_rumble_pulse:
 dw 0

controller_3_rumble_pulse:
 dw 0

controller_4_rumble_pulse:
 dw 0

rodata_80026918:
 dw 0

rodata_8002691C:
 dw 0

rodata_80026920:
 dw 0

disable_all_rumble:
 dw 0

ptr_to_tlb_ramrom_record:
 dw 0

rodata_8002692C:
 dw 1

pl1_controller_failure_lr:
 dw 0

pl2_controller_failure_lr:
 dw 0

pl3_controller_failure_lr:
 dw 0

pl4_controller_failure_lr:
 dw 0

pl1_controller_failure_ud:
 dw 0

pl2_controller_failure_ud:
 dw 0

pl3_controller_failure_ud:
 dw 0

pl4_controller_failure_ud:
 dw 0

pl1_controller_failure_held:
 dw 0

pl2_controller_failure_held:
 dw 0

pl3_controller_failure_held:
 dw 0

pl4_controller_failure_held:
 dw 0

pl1_controller_failure_pressed:
 dw 0

pl2_controller_failure_pressed:
 dw 0

pl3_controller_failure_pressed:
 dw 0

pl4_controller_failure_pressed:
 dw 0

rodata_80026970:
 dw 0
align(16)

osClockRate:
 dd 0x3B9ACA0

__osShutdown:
 dw 0

__OSGlobalIntMask:
 dw 0x3FFF01

osDiskExist:
 dw 0
align(16)

__osViDevMgr:
 dw 0

rodata_800269A4:
 dw 0

rodata_800269A8:
 dw 0

rodata_800269AC:
 dw 0

rodata_800269B0:
 dw 0

rodata_800269B4:
 dw 0

rodata_800269B8:
 dw 0
align(16)

macro displaymode(num,var2,var3,var4,var5,var6,var7,var8,var9,varA,varB,varC,varD,varE,varF,var10,var11,var12,var13,var14,var15,var16) {
 db {num}, {var2}
 dh {var3}
 dw {var4}, {var5}, {var6}, {var7}, {var8}, {var9}, {varA}, {varB}
 dw {varC}, {varD}, {varE}, {varF}, {var10}, {var11}, {var12}, {var13}
 dw {var14}, {var15}, {var16}
}

rodata_800269C0:
 displaymode(0x0, 0, 0, 0x320E, 320, 0x3E52239, 0x20D, 0xC15, 0xC150C15, 0x6C02EC, 0x200, 0, 0x280, 0x400, 0x2501FF, 0xE0204, 2, 0x280, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x1, 0, 0, 0x324E, 320, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x200, 0, 0x280, 0x1000400, 0x2301FD, 0xE0204, 2, 0x280, 0x3000400, 0x2501FF, 0xE0204, 2)
rodata_80026A60:
 displaymode(0x2, 0, 0, 0x311E, 320, 0x3E52239, 0x20D, 0xC15, 0xC150C15, 0x6C02EC, 0x200, 0, 0x280, 0x400, 0x2501FF, 0xE0204, 2, 0x280, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x3, 0, 0, 0x305E, 320, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x200, 0, 0x280, 0x1000400, 0x2301FD, 0xE0204, 2, 0x280, 0x3000400, 0x2501FF, 0xE0204, 2)
 displaymode(0x4, 0, 0, 0x330F, 320, 0x3E52239, 0x20D, 0xC15, 0xC150C15, 0x6C02EC, 0x200, 0, 0x500, 0x400, 0x2501FF, 0xE0204, 2, 0x500, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x5, 0, 0, 0x324F, 320, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x200, 0, 0x500, 0x1000400, 0x2301FD, 0xE0204, 2, 0x500, 0x3000400, 0x2501FF, 0xE0204, 2)
rodata_80026BA0:
 displaymode(0x6, 0, 0, 0x301F, 320, 0x3E52239, 0x20D, 0xC15, 0xC150C15, 0x6C02EC, 0x200, 0, 0x500, 0x400, 0x2501FF, 0xE0204, 2, 0x500, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x7, 0, 0, 0x305F, 320, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x200, 0, 0x500, 0x1000400, 0x2301FD, 0xE0204, 2, 0x500, 0x3000400, 0x2501FF, 0xE0204, 2)
 displaymode(0x8, 0, 0, 0x324E, 1280, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x400, 0, 0x500, 0x400, 0x2301FD, 0xE0204, 2, 0xA00, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x9, 0, 0, 0x324E, 640, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x400, 0, 0x500, 0x2000800, 0x2301FD, 0xE0204, 2, 0xA00, 0x2000800, 0x2501FF, 0xE0204, 2)
 displaymode(0xA, 0, 0, 0x305E, 1280, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x400, 0, 0x500, 0x400, 0x2301FD, 0xE0204, 2, 0xA00, 0x400, 0x2501FF, 0xE0204, 2)
rodata_80026D30:
 displaymode(0xB, 0, 0, 0x305E, 640, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x400, 0, 0x500, 0x2000800, 0x2301FD, 0xE0204, 2, 0xA00, 0x2000800, 0x2501FF, 0xE0204, 2)
 displaymode(0xC, 0, 0, 0x334F, 1280, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x400, 0, 0xA00, 0x400, 0x2301FD, 0xE0204, 2, 0x1400, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0xD, 0, 0, 0x324F, 640, 0x3E52239, 0x20C, 0xC15, 0xC150C15, 0x6C02EC, 0x400, 0, 0xA00, 0x2000800, 0x2301FD, 0xE0204, 2, 0x1400, 0x2000800, 0x2501FF, 0xE0204, 2)
 displaymode(0xE, 0, 0, 0x320E, 320, 0x404233A, 0x271, 0x150C69, 0xC6F0C6E, 0x800300, 0x200, 0, 0x280, 0x400, 0x5F0239, 0x9026B, 2, 0x280, 0x400, 0x5F0239, 0x9026B, 2)
 displaymode(0xF, 0, 0, 0x324E, 320, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x200, 0, 0x280, 0x1000400, 0x5D0237, 0x9026B, 2, 0x280, 0x3000400, 0x5F0239, 0xD0269, 2)
 displaymode(0x10, 0, 0, 0x311E, 320, 0x404233A, 0x271, 0x150C69, 0xC6F0C6E, 0x800300, 0x200, 0, 0x280, 0x400, 0x5F0239, 0x9026B, 2, 0x280, 0x400, 0x5F0239, 0x9026B, 2)
 displaymode(0x11, 0, 0, 0x305E, 320, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x200, 0, 0x280, 0x1000400, 0x5D0237, 0x9026B, 2, 0x280, 0x3000400, 0x5F0239, 0xD0269, 2)
 displaymode(0x12, 0, 0, 0x330F, 320, 0x404233A, 0x271, 0x150C69, 0xC6F0C6E, 0x800300, 0x200, 0, 0x500, 0x400, 0x5F0239, 0x9026B, 2, 0x500, 0x400, 0x5F0239, 0x9026B, 2)
 displaymode(0x13, 0, 0, 0x324F, 320, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x200, 0, 0x500, 0x1000400, 0x5D0237, 0x9026B, 2, 0x500, 0x3000400, 0x5F0239, 0xD0269, 2)
 displaymode(0x14, 0, 0, 0x301F, 320, 0x404233A, 0x271, 0x150C69, 0xC6F0C6E, 0x800300, 0x200, 0, 0x500, 0x400, 0x5F0239, 0x9026B, 2, 0x500, 0x400, 0x5F0239, 0x9026B, 2)
 displaymode(0x15, 0, 0, 0x305F, 320, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x200, 0, 0x500, 0x1000400, 0x5D0237, 0x9026B, 2, 0x500, 0x3000400, 0x5F0239, 0xD0269, 2)
 displaymode(0x16, 0, 0, 0x324E, 1280, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x400, 0, 0x500, 0x400, 0x5D0237, 0x9026B, 2, 0xA00, 0x400, 0x5F0239, 0xD0269, 2)
 displaymode(0x17, 0, 0, 0x324E, 640, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x400, 0, 0x500, 0x2000800, 0x5D0237, 0x9026B, 2, 0xA00, 0x2000800, 0x5F0239, 0xD0269, 2)
 displaymode(0x18, 0, 0, 0x305E, 1280, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x400, 0, 0x500, 0x400, 0x5D0237, 0x9026B, 2, 0xA00, 0x400, 0x5F0239, 0xD0269, 2)
 displaymode(0x19, 0, 0, 0x305E, 640, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x400, 0, 0x500, 0x2000800, 0x5D0237, 0x9026B, 2, 0xA00, 0x2000800, 0x5F0239, 0xD0269, 2)
 displaymode(0x1A, 0, 0, 0x334F, 1280, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x400, 0, 0xA00, 0x400, 0x5D0237, 0x9026B, 2, 0x1400, 0x400, 0x5F0239, 0xD0269, 2)
 displaymode(0x1B, 0, 0, 0x324F, 640, 0x404233A, 0x270, 0x150C69, 0xC6F0C6E, 0x800300, 0x400, 0, 0xA00, 0x2000800, 0x5D0237, 0x9026B, 2, 0x1400, 0x2000800, 0x5F0239, 0xD0269, 2)
 displaymode(0x1C, 0, 0, 0x320E, 320, 0x4651E39, 0x20D, 0x40C11, 0xC190C1A, 0x6C02EC, 0x200, 0, 0x280, 0x400, 0x2501FF, 0xE0204, 2, 0x280, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x1D, 0, 0, 0x324E, 320, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x200, 0, 0x280, 0x1000400, 0x2301FD, 0xB0202, 2, 0x280, 0x3000400, 0x2501FF, 0xE0204, 2)
rodata_80027320:
 displaymode(0x1E, 0, 0, 0x311E, 320, 0x4651E39, 0x20D, 0x40C11, 0xC190C1A, 0x6C02EC, 0x200, 0, 0x280, 0x400, 0x2501FF, 0xE0204, 2, 0x280, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x1F, 0, 0, 0x305E, 320, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x200, 0, 0x280, 0x1000400, 0x2301FD, 0xB0202, 2, 0x280, 0x3000400, 0x2501FF, 0xE0204, 2)
 displaymode(0x20, 0, 0, 0x330F, 320, 0x4651E39, 0x20D, 0x40C11, 0xC190C1A, 0x6C02EC, 0x200, 0, 0x500, 0x400, 0x2501FF, 0xE0204, 2, 0x500, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x21, 0, 0, 0x324F, 320, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x200, 0, 0x500, 0x1000400, 0x2301FD, 0xB0202, 2, 0x500, 0x3000400, 0x2501FF, 0xE0204, 2)
rodata_80027460:
 displaymode(0x22, 0, 0, 0x301F, 320, 0x4651E39, 0x20D, 0x40C11, 0xC190C1A, 0x6C02EC, 0x200, 0, 0x500, 0x400, 0x2501FF, 0xE0204, 2, 0x500, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x23, 0, 0, 0x305F, 320, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x200, 0, 0x500, 0x1000400, 0x2301FD, 0xB0202, 2, 0x500, 0x3000400, 0x2501FF, 0xE0204, 2)
 displaymode(0x24, 0, 0, 0x324E, 1280, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x400, 0, 0x500, 0x400, 0x2301FD, 0xB0202, 2, 0xA00, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x25, 0, 0, 0x324E, 640, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x400, 0, 0x500, 0x2000800, 0x2301FD, 0xB0202, 2, 0xA00, 0x2000800, 0x2501FF, 0xE0204, 2)
 displaymode(0x26, 0, 0, 0x305E, 1280, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x400, 0, 0x500, 0x400, 0x2301FD, 0xB0202, 2, 0xA00, 0x400, 0x2501FF, 0xE0204, 2)
rodata_800275F0:
 displaymode(0x27, 0, 0, 0x305E, 640, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x400, 0, 0x500, 0x2000800, 0x2301FD, 0xB0202, 2, 0xA00, 0x2000800, 0x2501FF, 0xE0204, 2)
 displaymode(0x28, 0, 0, 0x334F, 1280, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x400, 0, 0xA00, 0x400, 0x2301FD, 0xB0202, 2, 0x1400, 0x400, 0x2501FF, 0xE0204, 2)
 displaymode(0x29, 0, 0, 0x324F, 640, 0x4651E39, 0x20C, 0xC10, 0xC1C0C1C, 0x6C02EC, 0x400, 0, 0xA00, 0x2000800, 0x2301FD, 0xB0202, 2, 0x1400, 0x2000800, 0x2501FF, 0xE0204, 2)

CODE_rodata_800276E0:
 dw 0
 dw 0
 dw 0
 dw 0

CODE_rodata_800276F0:
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0

CODE_rodata_80027704:
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0

__osThreadTail:
 dw 0

CODE_rodata_80027724:
 dw 0xFFFFFFFF

__osRunQueue:
 dw __osThreadTail

__osActiveQueue:
 dw __osThreadTail

__osRunningThread:
 dw 0

__osFaultedThread_0:
 dw 0
align(16)

stdout_bg_alpha:
 db "                                ", 0; align(4)

a00000000000000000000000000000000:
 db "00000000000000000000000000000000", 0; align(16)

__osPiDevMgr:
 dw 0

CODE_rodata_80027794:
 dw 0

CODE_rodata_80027798:
 dw 0

CODE_rodata_8002779C:
 dw 0

CODE_rodata_800277A0:
 dw 0

CODE_rodata_800277A4:
 dw 0

CODE_rodata_800277A8:
 dw 0

CODE_rodata_800277AC:
 dw 0

__osContinitialized:
 dw 0
align(16)

CODE_rodata_800277C0:
 dw 0
align(16)

sin_table:
 dh  0,0x32,0x64,0x96 //0
 dh 0xC9,0xFB,0x12D,0x160 //4
 dh 0x192,0x1C4,0x1F7,0x229 //8
 dh 0x25B,0x28E,0x2C0,0x2F2 //0xC
 dh 0x324,0x357,0x389,0x3BB //0x10
 dh 0x3EE,0x420,0x452,0x484 //0x14
 dh 0x4B7,0x4E9,0x51B,0x54E //0x18
 dh 0x580,0x5B2,0x5E4,0x617 //0x1C
 dh 0x649,0x67B,0x6AD,0x6E0 //0x20
 dh 0x712,0x744,0x776,0x7A9 //0x24
 dh 0x7DB,0x80D,0x83F,0x871 //0x28
 dh 0x8A4,0x8D6,0x908,0x93A //0x2C
 dh 0x96C,0x99F,0x9D1,0xA03 //0x30
 dh 0xA35,0xA67,0xA99,0xACB //0x34
 dh 0xAFE,0xB30,0xB62,0xB94 //0x38
 dh 0xBC6,0xBF8,0xC2A,0xC5C //0x3C
 dh 0xC8E,0xCC0,0xCF2,0xD25 //0x40
 dh 0xD57,0xD89,0xDBB,0xDED //0x44
 dh 0xE1F,0xE51,0xE83,0xEB5 //0x48
 dh 0xEE7,0xF19,0xF4B,0xF7C //0x4C
 dh 0xFAE,0xFE0,0x1012,0x1044//0x50
 dh 0x1076,0x10A8,0x10DA,0x110C //0x54
 dh 0x113E,0x116F,0x11A1,0x11D3 //0x58
 dh 0x1205,0x1237,0x1269,0x129A //0x5C
 dh 0x12CC,0x12FE,0x1330,0x1361 //0x60
 dh 0x1393,0x13C5,0x13F6,0x1428 //0x64
 dh 0x145A,0x148C,0x14BD,0x14EF //0x68
 dh 0x1520,0x1552,0x1584,0x15B5 //0x6C
 dh 0x15E7,0x1618,0x164A,0x167B //0x70
 dh 0x16AD,0x16DF,0x1710,0x1741 //0x74
 dh 0x1773,0x17A4,0x17D6,0x1807 //0x78
 dh 0x1839,0x186A,0x189B,0x18CD //0x7C
 dh 0x18FE,0x1930,0x1961,0x1992 //0x80
 dh 0x19C3,0x19F5,0x1A26,0x1A57 //0x84
 dh 0x1A88,0x1ABA,0x1AEB,0x1B1C //0x88
 dh 0x1B4D,0x1B7E,0x1BAF,0x1BE1 //0x8C
 dh 0x1C12,0x1C43,0x1C74,0x1CA5 //0x90
 dh 0x1CD6,0x1D07,0x1D38,0x1D69 //0x94
 dh 0x1D9A,0x1DCB,0x1DFC,0x1E2D //0x98
 dh 0x1E5D,0x1E8E,0x1EBF,0x1EF0 //0x9C
 dh 0x1F21,0x1F52,0x1F82,0x1FB3 //0xA0
 dh 0x1FE4,0x2015,0x2045,0x2076 //0xA4
 dh 0x20A7,0x20D7,0x2108,0x2139 //0xA8
 dh 0x2169,0x219A,0x21CA,0x21FB //0xAC
 dh 0x222B,0x225C,0x228C,0x22BD //0xB0
 dh 0x22ED,0x231D,0x234E,0x237E //0xB4
 dh 0x23AE,0x23DF,0x240F,0x243F //0xB8
 dh 0x2470,0x24A0,0x24D0,0x2500 //0xBC
 dh 0x2530,0x2560,0x2591,0x25C1 //0xC0
 dh 0x25F1,0x2621,0x2651,0x2681 //0xC4
 dh 0x26B1,0x26E1,0x2711,0x2740 //0xC8
 dh 0x2770,0x27A0,0x27D0,0x2800 //0xCC
 dh 0x2830,0x285F,0x288F,0x28BF //0xD0
 dh 0x28EE,0x291E,0x294E,0x297D //0xD4
 dh 0x29AD,0x29DD,0x2A0C,0x2A3C //0xD8
 dh 0x2A6B,0x2A9B,0x2ACA,0x2AF9 //0xDC
 dh 0x2B29,0x2B58,0x2B87,0x2BB7 //0xE0
 dh 0x2BE6,0x2C15,0x2C44,0x2C74 //0xE4
 dh 0x2CA3,0x2CD2,0x2D01,0x2D30 //0xE8
 dh 0x2D5F,0x2D8E,0x2DBD,0x2DEC //0xEC
 dh 0x2E1B,0x2E4A,0x2E79,0x2EA8 //0xF0
 dh 0x2ED7,0x2F06,0x2F34,0x2F63 //0xF4
 dh 0x2F92,0x2FC0,0x2FEF,0x301E //0xF8
 dh 0x304C,0x307B,0x30A9,0x30D8 //0xFC
 dh 0x3107,0x3135,0x3163,0x3192 //0x100
 dh 0x31C0,0x31EF,0x321D,0x324B //0x104
 dh 0x3279,0x32A8,0x32D6,0x3304 //0x108
 dh 0x3332,0x3360,0x338E,0x33BC //0x10C
 dh 0x33EA,0x3418,0x3446,0x3474 //0x110
 dh 0x34A2,0x34D0,0x34FE,0x352B //0x114
 dh 0x3559,0x3587,0x35B5,0x35E2 //0x118
 dh 0x3610,0x363D,0x366B,0x3698 //0x11C
 dh 0x36C6,0x36F3,0x3721,0x374E //0x120
 dh 0x377C,0x37A9,0x37D6,0x3803 //0x124
 dh 0x3831,0x385E,0x388B,0x38B8 //0x128
 dh 0x38E5,0x3912,0x393F,0x396C //0x12C
 dh 0x3999,0x39C6,0x39F3,0x3A20 //0x130
 dh 0x3A4D,0x3A79,0x3AA6,0x3AD3 //0x134
 dh 0x3B00,0x3B2C,0x3B59,0x3B85 //0x138
 dh 0x3BB2,0x3BDE,0x3C0B,0x3C37 //0x13C
 dh 0x3C64,0x3C90,0x3CBC,0x3CE9 //0x140
 dh 0x3D15,0x3D41,0x3D6D,0x3D99 //0x144
 dh 0x3DC5,0x3DF1,0x3E1D,0x3E49 //0x148
 dh 0x3E75,0x3EA1,0x3ECD,0x3EF9 //0x14C
 dh 0x3F25,0x3F50,0x3F7C,0x3FA8 //0x150
 dh 0x3FD3,0x3FFF,0x402B,0x4056 //0x154
 dh 0x4082,0x40AD,0x40D8,0x4104 //0x158
 dh 0x412F,0x415A,0x4186,0x41B1 //0x15C
 dh 0x41DC,0x4207,0x4232,0x425D //0x160
 dh 0x4288,0x42B3,0x42DE,0x4309 //0x164
 dh 0x4334,0x435F,0x4389,0x43B4 //0x168
 dh 0x43DF,0x4409,0x4434,0x445F //0x16C
 dh 0x4489,0x44B4,0x44DE,0x4508 //0x170
 dh 0x4533,0x455D,0x4587,0x45B1 //0x174
 dh 0x45DC,0x4606,0x4630,0x465A //0x178
 dh 0x4684,0x46AE,0x46D8,0x4702 //0x17C
 dh 0x472C,0x4755,0x477F,0x47A9 //0x180
 dh 0x47D2,0x47FC,0x4826,0x484F //0x184
 dh 0x4879,0x48A2,0x48CC,0x48F5 //0x188
 dh 0x491E,0x4948,0x4971,0x499A //0x18C
 dh 0x49C3,0x49EC,0x4A15,0x4A3E //0x190
 dh 0x4A67,0x4A90,0x4AB9,0x4AE2 //0x194
 dh 0x4B0B,0x4B33,0x4B5C,0x4B85 //0x198
 dh 0x4BAD,0x4BD6,0x4BFE,0x4C27 //0x19C
 dh 0x4C4F,0x4C78,0x4CA0,0x4CC8 //0x1A0
 dh 0x4CF0,0x4D19,0x4D41,0x4D69 //0x1A4
 dh 0x4D91,0x4DB9,0x4DE1,0x4E09 //0x1A8
 dh 0x4E31,0x4E58,0x4E80,0x4EA8 //0x1AC
 dh 0x4ED0,0x4EF7,0x4F1F,0x4F46 //0x1B0
 dh 0x4F6E,0x4F95,0x4FBD,0x4FE4 //0x1B4
 dh 0x500B,0x5032,0x505A,0x5081 //0x1B8
 dh 0x50A8,0x50CF,0x50F6,0x511D //0x1BC
 dh 0x5144,0x516B,0x5191,0x51B8 //0x1C0
 dh 0x51DF,0x5205,0x522C,0x5253 //0x1C4
 dh 0x5279,0x52A0,0x52C6,0x52EC //0x1C8
 dh 0x5313,0x5339,0x535F,0x5385 //0x1CC
 dh 0x53AB,0x53D1,0x53F7,0x541D //0x1D0
 dh 0x5443,0x5469,0x548F,0x54B5 //0x1D4
 dh 0x54DA,0x5500,0x5525,0x554B //0x1D8
 dh 0x5571,0x5596,0x55BB,0x55E1 //0x1DC
 dh 0x5606,0x562B,0x5650,0x5675 //0x1E0
 dh 0x569B,0x56C0,0x56E5,0x5709 //0x1E4
 dh 0x572E,0x5753,0x5778,0x579D //0x1E8
 dh 0x57C1,0x57E6,0x580A,0x582F //0x1EC
 dh 0x5853,0x5878,0x589C,0x58C0 //0x1F0
 dh 0x58E5,0x5909,0x592D,0x5951 //0x1F4
 dh 0x5975,0x5999,0x59BD,0x59E1 //0x1F8
 dh 0x5A04,0x5A28,0x5A4C,0x5A6F //0x1FC
 dh 0x5A93,0x5AB7,0x5ADA,0x5AFD //0x200
 dh 0x5B21,0x5B44,0x5B67,0x5B8B //0x204
 dh 0x5BAE,0x5BD1,0x5BF4,0x5C17 //0x208
 dh 0x5C3A,0x5C5D,0x5C7F,0x5CA2 //0x20C
 dh 0x5CC5,0x5CE7,0x5D0A,0x5D2D //0x210
 dh 0x5D4F,0x5D71,0x5D94,0x5DB6 //0x214
 dh 0x5DD8,0x5DFA,0x5E1D,0x5E3F //0x218
 dh 0x5E61,0x5E83,0x5EA5,0x5EC6 //0x21C
 dh 0x5EE8,0x5F0A,0x5F2C,0x5F4D //0x220
 dh 0x5F6F,0x5F90,0x5FB2,0x5FD3 //0x224
 dh 0x5FF4,0x6016,0x6037,0x6058 //0x228
 dh 0x6079,0x609A,0x60BB,0x60DC //0x22C
 dh 0x60FD,0x611E,0x613E,0x615F //0x230
 dh 0x6180,0x61A0,0x61C1,0x61E1 //0x234
 dh 0x6202,0x6222,0x6242,0x6263 //0x238
 dh 0x6283,0x62A3,0x62C3,0x62E3 //0x23C
 dh 0x6303,0x6323,0x6342,0x6362 //0x240
 dh 0x6382,0x63A1,0x63C1,0x63E0 //0x244
 dh 0x6400,0x641F,0x643F,0x645E //0x248
 dh 0x647D,0x649C,0x64BB,0x64DA //0x24C
 dh 0x64F9,0x6518,0x6537,0x6556 //0x250
 dh 0x6574,0x6593,0x65B2,0x65D0 //0x254
 dh 0x65EF,0x660D,0x662B,0x664A //0x258
 dh 0x6668,0x6686,0x66A4,0x66C2 //0x25C
 dh 0x66E0,0x66FE,0x671C,0x673A //0x260
 dh 0x6757,0x6775,0x6792,0x67B0 //0x264
 dh 0x67CD,0x67EB,0x6808,0x6825 //0x268
 dh 0x6843,0x6860,0x687D,0x689A //0x26C
 dh 0x68B7,0x68D4,0x68F1,0x690D //0x270
 dh 0x692A,0x6947,0x6963,0x6980 //0x274
 dh 0x699C,0x69B9,0x69D5,0x69F1 //0x278
 dh 0x6A0E,0x6A2A,0x6A46,0x6A62 //0x27C
 dh 0x6A7E,0x6A9A,0x6AB5,0x6AD1 //0x280
 dh 0x6AED,0x6B08,0x6B24,0x6B40 //0x284
 dh 0x6B5B,0x6B76,0x6B92,0x6BAD //0x288
 dh 0x6BC8,0x6BE3,0x6BFE,0x6C19 //0x28C
 dh 0x6C34,0x6C4F,0x6C6A,0x6C84 //0x290
 dh 0x6C9F,0x6CBA,0x6CD4,0x6CEF //0x294
 dh 0x6D09,0x6D23,0x6D3E,0x6D58 //0x298
 dh 0x6D72,0x6D8C,0x6DA6,0x6DC0 //0x29C
 dh 0x6DDA,0x6DF3,0x6E0D,0x6E27 //0x2A0
 dh 0x6E40,0x6E5A,0x6E73,0x6E8D //0x2A4
 dh 0x6EA6,0x6EBF,0x6ED9,0x6EF2 //0x2A8
 dh 0x6F0B,0x6F24,0x6F3D,0x6F55 //0x2AC
 dh 0x6F6E,0x6F87,0x6FA0,0x6FB8 //0x2B0
 dh 0x6FD1,0x6FE9,0x7002,0x701A //0x2B4
 dh 0x7032,0x704A,0x7062,0x707A //0x2B8
 dh 0x7092,0x70AA,0x70C2,0x70DA //0x2BC
 dh 0x70F2,0x7109,0x7121,0x7138 //0x2C0
 dh 0x7150,0x7167,0x717E,0x7196 //0x2C4
 dh 0x71AD,0x71C4,0x71DB,0x71F2 //0x2C8
 dh 0x7209,0x7220,0x7236,0x724D //0x2CC
 dh 0x7264,0x727A,0x7291,0x72A7 //0x2D0
 dh 0x72BD,0x72D4,0x72EA,0x7300 //0x2D4
 dh 0x7316,0x732C,0x7342,0x7358 //0x2D8
 dh 0x736E,0x7383,0x7399,0x73AE //0x2DC
 dh 0x73C4,0x73D9,0x73EF,0x7404 //0x2E0
 dh 0x7419,0x742E,0x7443,0x7458 //0x2E4
 dh 0x746D,0x7482,0x7497,0x74AC //0x2E8
 dh 0x74C0,0x74D5,0x74EA,0x74FE //0x2EC
 dh 0x7512,0x7527,0x753B,0x754F //0x2F0
 dh 0x7563,0x7577,0x758B,0x759F //0x2F4
 dh 0x75B3,0x75C7,0x75DA,0x75EE //0x2F8
 dh 0x7601,0x7615,0x7628,0x763B //0x2FC
 dh 0x764F,0x7662,0x7675,0x7688 //0x300
 dh 0x769B,0x76AE,0x76C1,0x76D3 //0x304
 dh 0x76E6,0x76F9,0x770B,0x771E //0x308
 dh 0x7730,0x7742,0x7754,0x7767 //0x30C
 dh 0x7779,0x778B,0x779D,0x77AF //0x310
 dh 0x77C0,0x77D2,0x77E4,0x77F5 //0x314
 dh 0x7807,0x7818,0x782A,0x783B //0x318
 dh 0x784C,0x785D,0x786E,0x787F //0x31C
 dh 0x7890,0x78A1,0x78B2,0x78C3 //0x320
 dh 0x78D3,0x78E4,0x78F4,0x7905 //0x324
 dh 0x7915,0x7925,0x7936,0x7946 //0x328
 dh 0x7956,0x7966,0x7976,0x7985 //0x32C
 dh 0x7995,0x79A5,0x79B5,0x79C4 //0x330
 dh 0x79D4,0x79E3,0x79F2,0x7A02 //0x334
 dh 0x7A11,0x7A20,0x7A2F,0x7A3E //0x338
 dh 0x7A4D,0x7A5B,0x7A6A,0x7A79 //0x33C
 dh 0x7A87,0x7A96,0x7AA4,0x7AB3 //0x340
 dh 0x7AC1,0x7ACF,0x7ADD,0x7AEB //0x344
 dh 0x7AF9,0x7B07,0x7B15,0x7B23 //0x348
 dh 0x7B31,0x7B3E,0x7B4C,0x7B59 //0x34C
 dh 0x7B67,0x7B74,0x7B81,0x7B8E //0x350
 dh 0x7B9B,0x7BA8,0x7BB5,0x7BC2 //0x354
 dh 0x7BCF,0x7BDC,0x7BE8,0x7BF5 //0x358
 dh 0x7C02,0x7C0E,0x7C1A,0x7C27 //0x35C
 dh 0x7C33,0x7C3F,0x7C4B,0x7C57 //0x360
 dh 0x7C63,0x7C6F,0x7C7A,0x7C86 //0x364
 dh 0x7C92,0x7C9D,0x7CA9,0x7CB4 //0x368
 dh 0x7CBF,0x7CCB,0x7CD6,0x7CE1 //0x36C
 dh 0x7CEC,0x7CF7,0x7D02,0x7D0C //0x370
 dh 0x7D17,0x7D22,0x7D2C,0x7D37 //0x374
 dh 0x7D41,0x7D4B,0x7D56,0x7D60 //0x378
 dh 0x7D6A,0x7D74,0x7D7E,0x7D88 //0x37C
 dh 0x7D91,0x7D9B,0x7DA5,0x7DAE //0x380
 dh 0x7DB8,0x7DC1,0x7DCB,0x7DD4 //0x384
 dh 0x7DDD,0x7DE6,0x7DEF,0x7DF8 //0x388
 dh 0x7E01,0x7E0A,0x7E13,0x7E1B //0x38C
 dh 0x7E24,0x7E2C,0x7E35,0x7E3D //0x390
 dh 0x7E45,0x7E4D,0x7E56,0x7E5E //0x394
 dh 0x7E66,0x7E6D,0x7E75,0x7E7D //0x398
 dh 0x7E85,0x7E8C,0x7E94,0x7E9B //0x39C
 dh 0x7EA3,0x7EAA,0x7EB1,0x7EB8 //0x3A0
 dh 0x7EBF,0x7EC6,0x7ECD,0x7ED4 //0x3A4
 dh 0x7EDB,0x7EE1,0x7EE8,0x7EEE //0x3A8
 dh 0x7EF5,0x7EFB,0x7F01,0x7F08 //0x3AC
 dh 0x7F0E,0x7F14,0x7F1A,0x7F20 //0x3B0
 dh 0x7F25,0x7F2B,0x7F31,0x7F36 //0x3B4
 dh 0x7F3C,0x7F41,0x7F47,0x7F4C //0x3B8
 dh 0x7F51,0x7F56,0x7F5B,0x7F60 //0x3BC
 dh 0x7F65,0x7F6A,0x7F6F,0x7F74 //0x3C0
 dh 0x7F78,0x7F7D,0x7F81,0x7F85 //0x3C4
 dh 0x7F8A,0x7F8E,0x7F92,0x7F96 //0x3C8
 dh 0x7F9A,0x7F9E,0x7FA2,0x7FA6 //0x3CC
 dh 0x7FA9,0x7FAD,0x7FB0,0x7FB4 //0x3D0
 dh 0x7FB7,0x7FBA,0x7FBE,0x7FC1 //0x3D4
 dh 0x7FC4,0x7FC7,0x7FCA,0x7FCC //0x3D8
 dh 0x7FCF,0x7FD2,0x7FD4,0x7FD7 //0x3DC
 dh 0x7FD9,0x7FDC,0x7FDE,0x7FE0 //0x3E0
 dh 0x7FE2,0x7FE4,0x7FE6,0x7FE8 //0x3E4
 dh 0x7FEA,0x7FEC,0x7FED,0x7FEF //0x3E8
 dh 0x7FF1,0x7FF2,0x7FF3,0x7FF5 //0x3EC
 dh 0x7FF6,0x7FF7,0x7FF8,0x7FF9 //0x3F0
 dh 0x7FFA,0x7FFB,0x7FFB,0x7FFC //0x3F4
 dh 0x7FFD,0x7FFD,0x7FFE,0x7FFE //0x3F8
 dh 0x7FFE,0x7FFE,0x7FFE,0x7FFF //0x3FC

__osTimerList:
 dw __osBaseTimer
align(16)

buffer1:
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0

buffer2:
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0
 dw 0

__osViCurr:
 dw buffer1

__osViNext:
 dw buffer2

CODE_rodata_80028048:
 dw 1

osViClock:
 dw 0x2E6D354

soundtable1:
 dw 3, 0xFA0, 0, 0x870, 0x2666, 0xFFFFD99A, 0, 0, 0, 0

soundtable2:
 dw 0x2F8, 0x5F0, 0xCCC, 0xFFFFF334, 0x3FFF, 0, 0, 0, 0, 0x960

soundtable3:
 dw 0x1388, 0, 0, 0, 0, 0x5000, 4, 0xFA0, 0, 0xA50

soundtable4:
 dw 0x2666, 0xFFFFD99A, 0, 0, 0, 0, 0x370, 0x870, 0xCCC, 0xFFFFF334

soundtable5:
 dw 0x3FFF, 0, 0, 0, 0xA50, 0xE38, 0xCCC, 0xFFFFF334, 0x3FFF, 0

soundtable6:
 dw 0, 0, 0, 0xEB0, 0x1F40, 0, 0, 0, 0, 0x5000

soundtable7:
 dw 1, 0x1F40, 0, 0x1BF8, 0x2EE0, 0, 0x7FFF, 0, 0, 0

soundtable8:
 dw 1, 0x320, 0, 0xC8, 0x4000, 0, 0x7FFF, 0x1DB0, 0x2BC, 0

soundtable9:
 dw 1, 0x320, 0, 0xC8, 0, 0x5FFF, 0x7FFF, 0x17C, 0x1F4, 0

soundtableA:
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dh 0x7FFF
 dh 0x7FFC
 dh 0x7FF5
 dh 0x7FE8
 dh 0x7FD7
 dh 0x7FC0
 dh 0x7FA5
 dh 0x7F84
 dh 0x7F5F
 dh 0x7F34
 dh 0x7F05
 dh 0x7ED0
 dh 0x7E97
 dh 0x7E58
 dh 0x7E15
 dh 0x7DCD
 dh 0x7D7F
 dh 0x7D2D
 dh 0x7CD6
 dh 0x7C7A
 dh 0x7C1A
 dh 0x7BB4
 dh 0x7B49
 dh 0x7ADA
 dh 0x7A66
 dh 0x79ED
 dh 0x796F
 dh 0x78ED
 dh 0x7866
 dh 0x77DA
 dh 0x7749
 dh 0x76B4
 dh 0x761A
 dh 0x757B
 dh 0x74D8
 dh 0x7430
 dh 0x7384
 dh 0x72D3
 dh 0x721E
 dh 0x7164
 dh 0x70A6
 dh 0x6FE3
 dh 0x6F1C
 dh 0x6E51
 dh 0x6D81
 dh 0x6CAD
 dh 0x6BD5
 dh 0x6AF9
 dh 0x6A18
 dh 0x6933
 dh 0x684A
 dh 0x675D
 dh 0x666C
 dh 0x6577
 dh 0x647E
 dh 0x6381
 dh 0x6280
 dh 0x617C
 dh 0x6073
 dh 0x5F67
 dh 0x5E57
 dh 0x5D43
 dh 0x5C2C
 dh 0x5B11
 dh 0x59F2
 dh 0x58D0
 dh 0x57AA
 dh 0x5681
 dh 0x5555
 dh 0x5425
 dh 0x52F2
 dh 0x51BC
 dh 0x5082
 dh 0x4F46
 dh 0x4E06
 dh 0x4CC3
 dh 0x4B7D
 dh 0x4A35
 dh 0x48E9
 dh 0x479B
 dh 0x4649
 dh 0x44F5
 dh 0x439E
 dh 0x4245
 dh 0x40E9
 dh 0x3F8A
 dh 0x3E29
 dh 0x3CC6
 dh 0x3B60
 dh 0x39F8
 dh 0x388D
 dh 0x3721
 dh 0x35B2
 dh 0x3441
 dh 0x32CE
 dh 0x3159
 dh 0x2FE2
 dh 0x2E69
 dh 0x2CEF
 dh 0x2B72
 dh 0x29F4
 dh 0x2875
 dh 0x26F3
 dh 0x2570
 dh 0x23EC
 dh 0x2266
 dh 0x20DF
 dh 0x1F57
 dh 0x1DCE
 dh 0x1C43
 dh 0x1AB7
 dh 0x192A
 dh 0x179C
 dh 0x160E
 dh 0x147E
 dh 0x12ED
 dh 0x115C
 dh 0xFCA
 dh 0xE38
 dh 0xCA5
 dh 0xB11
 dh 0x97D
 dh 0x7E9
 dh 0x654
 dh 0x4C0
 dh 0x32A
 dh 0x195
 dh 0

__osPiAccessQueueEnabled:
 dw 0
align(16)

alowercase_hex_char:
 db "0123456789abcdef", 0;align(4)

auppercase_hex_char:
 db "0123456789ABCDEF", 0;align(16)

vi_settings_1:
 dw 0x2000000
 dw 0x311E
 dw 0x140
 dw 0x3E52239
 dw 0x20D
 dw 0xC15
 dw 0xC150C15
 dw 0x6C02EC
 dw 0x200
 dw 0
 dw 0x280
 dw 0x400
 dw 0x2501FF
 dw 0xE0204
 dw 2
 dw 0x280
 dw 0x400
 dw 0x2501FF
 dw 0xE0204
 dw 2

vi_settings_2:
 dw 0x10000000
 dw 0x311E
 dw 0x140
 dw 0x404233A
 dw 0x271
 dw 0x150C69
 dw 0xC6F0C6E
 dw 0x800300
 dw 0x200
 dw 0
 dw 0x280
 dw 0x400
 dw 0x5F0239
 dw 0x9026B
 dw 2
 dw 0x280
 dw 0x400
 dw 0x5F0239
 dw 0x9026B
 dw 2
 dw 0x10
 dw 0x10
 dw 0x20
 dw 0

base $800283D0
aBoot:
 db "boot", 0x0;align(4)

//base $800283D8
aRmon:
 db "rmon", 0x0;align(4)

//base $800283E0
aIdle:
 db "idle", 0x0;align(4)

//base $800283E8
aShed:
 db "shed", 0x0;align(4)

//base $800283F0
aMain:
 db "main", 0x0;align(4)

//base $800283F8
aAudi:
 db "audi", 0x0;align(4)

jpt_80001674:
 dw 0x70001758
 dw 0x70001704
 dw 0x7000167C
 dw 0x70001758
 dw 0x70001758
 dw 0x70001704
 dw 0x70001704
 align(16)

aUtz2_0f:
 db "utz %2.0f%%\n", 0;align(4)

aRsp2_0f:
 db "rsp %2.0f%%\n", 0;align(4)

aTex2_0f:
 db "tex %2.0f%%", 0;align(4)

a2dHz:
 db "%2d hz", 0;align(4)

a2dFrames:
 db "%2d frames", 0;align(4)

a2d:
 db " [%2d]", 0;align(4)

CODE_rodata_80028468:
 db "     ", 0;align(4)

CODE_rodata_80028470:
 db "I=l0", 0;align(16)
 dw 0x1400140
 dw 0x2800000

CODE_rodata_80028488:
 dw 0xF000F0
 dw 0x1E00000

aGrab_D_jpeg_1:
 db "grab.%d.jpeg", 0;align(4)

aGrab_D_temp_uix:
 db "grab.%d.temp.uix", 0;align(4)

aUix2pixGrab_D_temp_uix:
 db "uix2pix grab.%d.temp.uix", 0;align(4)

aFromaliasGrab_D_temp_pixGrab_D_tem:
 db "fromalias grab.%d.temp.pix grab.%d.temp.rgb", 0;align(4)

aImgcopyFjfifGrab_D_temp_rgbGrab_D_:
 db "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg", 0;align(4)

aRmGrab_D_temp_uixGrab_D_temp_pixGr:
 db "rm grab.%d.temp.uix grab.%d.temp.pix grab.%d.temp.rgb", 0;align(4)

aImgviewGrab_D_jpeg:
 db "imgview grab.%d.jpeg", 0;align(4)

aGrab_D_jpeg:
 db "grab.%d.jpeg", 0;align(4)

aGrab_D_temp_uix_0:
 db "grab.%d.temp.Uix", 0;align(4)

aUix2pixXsDGrab_D_temp_uix:
 db "Uix2pix -xs%d grab.%d.temp.Uix", 0;align(4)

aFromaliasGrab_D_temp_pixGrab_D_t_0:
 db "fromalias grab.%d.temp.pix grab.%d.temp.rgb", 0;align(4)

aImgcopyFjfifGrab_D_temp_rgbGrab__0:
 db "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg", 0;align(4)

aRmGrab_D_temp_uixGrab_D_temp_pix_0:
 db "rm grab.%d.temp.Uix grab.%d.temp.pix grab.%d.temp.rgb", 0;align(4)

aImgviewGrab_D_jpeg_0:
 db "imgview grab.%d.jpeg", 0;align(4)

aGrab_D_rgb:
 db "grab.%d.rgb", 0;align(4)

aGrab_D_temp_uix_1:
 db "grab.%d.temp.uix", 0;align(4)

aUix2pixGrab_D_temp_uix_0:
 db "uix2pix grab.%d.temp.uix", 0;align(4)

aFromaliasGrab_D_temp_pixGrab_D_rgb:
 db "fromalias grab.%d.temp.pix grab.%d.rgb", 0;align(4)

aRmGrab_D_temp_uixGrab_D_temp_pix:
 db "rm grab.%d.temp.uix grab.%d.temp.pix", 0;align(4)

aImgviewGrab_D_rgb:
 db "imgview grab.%d.rgb", 0;align(4)

aGrab_D_rgb_0:
 db "grab.%d.rgb", 0;align(4)

aGrab_D_temp_uix_2:
 db "grab.%d.temp.Uix", 0;align(4)

aUix2pixXsDGrab_D_temp_uix_0:
 db "Uix2pix -xs%d grab.%d.temp.Uix", 0;align(4)

aFromaliasGrab_D_temp_pixGrab_D_r_0:
 db "fromalias grab.%d.temp.pix grab.%d.rgb", 0;align(4)

aRmGrab_D_temp_uixGrab_D_temp_pix_1:
 db "rm grab.%d.temp.Uix grab.%d.temp.pix", 0;align(4)

aImgviewGrab_D_rgb_0:
 db "imgview grab.%d.rgb", 0;align(4)

aDeb_c_debug:
 db "deb_c_debug", 0;align(4)
 align(16)

aBd:
 db "BD", 0;align(4)

aIp8:
 db "IP8", 0;align(4)

aIp7:
 db "IP7", 0;align(4)

aIp6:
 db "IP6", 0;align(4)

aIp5:
 db "IP5", 0;align(4)

aIp4:
 db "IP4", 0;align(4)

aIp3:
 db "IP3", 0;align(4)

aIp2:
 db "IP2", 0;align(4)

aIp1:
 db "IP1", 0;align(4)

aInt:
 db "Int", 0;align(4)

aTlbmod:
 db "TLBmod", 0;align(4)

aTlbload:
 db "TLBload", 0;align(4)

aTlbstore:
 db "TLBstore", 0;align(4)

aAddressErrorOnLoadOrInstructionFet:
 db "Address error on load or instruction fetch", 0;align(4)

aAddressErrorOnStore:
 db "Address error on store", 0;align(4)

aBusErrorExceptionOnInstructionFetc:
 db "Bus error exception on instruction fetch", 0;align(4)

aBusErrorExceptionOnDataReference:
 db "Bus error exception on data reference", 0;align(4)

aSyscall:
 db "Syscall", 0;align(4)

aBrk:
 db "Brk", 0;align(4)

aReservedInstruction:
 db "Reserved instruction", 0;align(4)

aCopUnusable:
 db "Cop unusable", 0;align(4)

aOverflow:
 db "Overflow", 0;align(4)

aTrap:
 db "Trap", 0;align(4)

aVirtualCoherencyExceptionOnIntruct:
 db "Virtual coherency exception on intruction fetch", 0;align(4)

aFpException:
 db "Fp exception", 0;align(4)

aWatchpoint:
 db "Watchpoint", 0;align(4)

aVirtualCoherencyExceptionOnDataRef:
 db "Virtual coherency exception on data reference", 0;align(4)

aExceptionNULL_0:
 db 0;align(4)

aCu3:
 db "CU3", 0;align(4)

aCu2:
 db "CU2", 0;align(4)

aCu1:
 db "CU1", 0;align(4)

aCu0:
 db "CU0", 0;align(4)

aRp:
 db "RP", 0;align(4)

aFr:
 db "FR", 0;align(4)

aRe:
 db "RE", 0;align(4)

aBev:
 db "BEV", 0;align(4)

aTs:
 db "TS", 0;align(4)

aSr:
 db "SR", 0;align(4)

aCh:
 db "CH", 0;align(4)

aCe:
 db "CE", 0;align(4)

aDe:
 db "DE", 0;align(4)

aIm8:
 db "IM8", 0;align(4)

aIm7:
 db "IM7", 0;align(4)

aIm6:
 db "IM6", 0;align(4)

aIm5:
 db "IM5", 0;align(4)

aIm4:
 db "IM4", 0;align(4)

aIm3:
 db "IM3", 0;align(4)

aIm2:
 db "IM2", 0;align(4)

aIm1:
 db "IM1", 0;align(4)

aKx:
 db "KX", 0;align(4)

aSx:
 db "SX", 0;align(4)

aUx:
 db "UX", 0;align(4)

aUsr:
 db "USR", 0;align(4)

aSup:
 db "SUP", 0;align(4)

aKer:
 db "KER", 0;align(4)

aErl:
 db "ERL", 0;align(4)

aExl:
 db "EXL", 0;align(4)

aIe:
 db "IE", 0;align(4)

aExceptionNULL_1:
 db 0;align(4)

aFs:
 db "FS", 0;align(4)

aC_1:
 db "C", 0;align(4)

aUnimplemented:
 db "Unimplemented", 0;align(4)

aInvalidOp:
 db "Invalid op", 0;align(4)

aBy0_0:
 db "/ by 0.0", 0;align(4)

aOverflow_0:
 db "Overflow", 0;align(4)

aUnderflow:
 db "Underflow", 0;align(4)

aInexactOp:
 db "Inexact op", 0;align(4)

aEv:
 db "EV", 0;align(4)

aEz:
 db "EZ", 0;align(4)

aEo:
 db "EO", 0;align(4)

aEu:
 db "EU", 0;align(4)

aEi:
 db "EI", 0;align(4)

aFv:
 db "FV", 0;align(4)

aFz:
 db "FZ", 0;align(4)

aFo:
 db "FO", 0;align(4)

aFu:
 db "FU", 0;align(4)

aFi:
 db "FI", 0;align(4)

aRn:
 db "RN", 0;align(4)

aRz:
 db "RZ", 0;align(4)

aRp_1:
 db "RP", 0;align(4)

aRm:
 db "RM", 0;align(4)

aExceptionNULL:
 db 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt625Ma275:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt625 -ma275", 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt650Ma160:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt650 -ma160", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt610Ma300:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt610 -ma300", 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt600Ma300:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma300", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt700Ma150:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma150", 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt660Ma150:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt660 -ma150", 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt750Ma225:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma225", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt550Ma350:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt550 -ma350", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt725Ma150:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt725 -ma150", 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt750Ma220:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma220", 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt600Ma250:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma250", 0;align(4)

aMl0Me0Mgfx60Mvtx40Mt635Ma290:
 db "-ml0 -me0 -mgfx60  -mvtx40 -mt635 -ma290", 0;align(4)

aMl0Me0Mgfx60Mvtx50Mt710Ma300:
 db "-ml0 -me0 -mgfx60  -mvtx50 -mt710 -ma300", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt600Ma200:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma200", 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt500Ma200:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt500 -ma200", 0;align(4)

aMl0Me0Mgfx70Mvtx50Mt671Ma200:
 db "-ml0 -me0 -mgfx70  -mvtx50 -mt671 -ma200", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt650Ma250:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma250", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt530Ma250:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt530 -ma250", 0;align(4)

aMl0Me0Mgfx60Mvtx40Mt855Ma135:
 db "-ml0 -me0 -mgfx60  -mvtx40 -mt855 -ma135", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt600Ma250:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma250", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt650Ma150:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma150", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt300Ma300:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt300 -ma300", 0;align(4)

aMl0Me0Mgfx80Mvtx20Mt646Ma001:
 db "-ml0 -me0 -mgfx80 -mvtx20 -mt646 -ma001", 0;align(4)

aMl0Me0Mgfx60Mvtx20Mt500Ma001:
 db "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001", 0;align(4)

aMl0Me0Mgfx60Mvtx20Mt500Ma001_0:
 db "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001", 0;align(4)

aMl0Me0Mgfx130Mvtx100Mt390Ma100:
 db "-ml0 -me0 -mgfx130 -mvtx100 -mt390 -ma100", 0;align(4)

aMl0Me0Mgfx130Mvtx100Mt400Ma100:
 db "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100", 0;align(4)

aMl0Me0Mgfx130Mvtx100Mt400Ma100_0:
 db "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100", 0;align(4)

aMl0Me0Mgfx130Mvtx100Mt400Ma100_1:
 db "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100", 0;align(4)

aMl0Me0Mgfx130Mvtx100Mt400Ma100_2:
 db "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100", 0;align(4)

aMl0Me0Mgfx130Mvtx100Mt400Ma300:
 db "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma300", 0;align(4)

aMl0Me0Mgfx130Mvtx100Mt550Ma170:
 db "-ml0 -me0 -mgfx130 -mvtx100 -mt550 -ma170", 0;align(4)

aMl0Me0Mgfx80Mvtx100Mt550Ma250:
 db "-ml0 -me0 -mgfx80  -mvtx100 -mt550 -ma250", 0;align(4)

aMl0Me0Mgfx130Mvtx100Mt440Ma220:
 db "-ml0 -me0 -mgfx130 -mvtx100 -mt440 -ma220", 0;align(4)

aMl0Me0Mgfx90Mvtx100Mt550Ma230:
 db "-ml0 -me0 -mgfx90  -mvtx100 -mt550 -ma230", 0;align(4)

aMl0Me0Mgfx110Mvtx100Mt350Ma400:
 db "-ml0 -me0 -mgfx110 -mvtx100 -mt350 -ma400", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt700Ma400:
 db "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400", 0;align(4)

aLevel_:
 db "-level_", 0;align(4)

aMl0Me0Mgfx100Mvtx50Mt700Ma400_1:
 db "          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400", 0;align(4)

aM:
 db "-m", 0;align(4)

aM_1:
 db "-m", 0;align(4)

aLevel__0:
 db "-level_", 0;align(4)

aLevel__1:
 db "-level_", 0;align(4)

aHard:
 db "-hard", 0;align(4)

aHard_1:
 db "-hard", 0;align(4)

aHard_2:
 db "-hard", 0;align(4)

aMa:
 db "-ma", 0;align(4)

aMa_0:
 db "-ma", 0;align(4)

aU64_taskgrab_D_core:
 db "u64.taskgrab.%d.core", 0;align(4)

aBoss_c_debug:
 db "boss_c_debug", 0;align(8)
 
jpt_80007FB4:
 dw 0x70007FBC
 dw 0x70008388
 dw 0x700088D4
 dw 0x7000847C
 dw 0x700088D4
 dw 0x700088D4
 dw 0x700088D4
 dw 0x700085C8
 dw 0x700088D4
 dw 0x700088D4
 dw 0x700088D4
 dw 0x700088D4
 dw 0x700088D4
 dw 0x700088D4
 dw 0x700088D4
 dw 0x700084F0

aMemp_c_debug:
 db "memp_c_debug", 0;align(4)

aMf:
 db "-mf", 0;align(4)

aMf_0:
 db "-mf", 0;align(4)

aMl:
 db "-ml", 0;align(4)

aMl_0:
 db "-ml", 0;align(4)

aMe:
 db "-me", 0;align(4)

aMe_0:
 db "-me", 0;align(16)

aMema_c_debug:
 db "mema_c_debug", 0;align(4)

aD_3:
 db "%d ", 0;align(4)

a___:
 db "...", 0;align(4)

aD_5:
 db "[%d]", 0;align(4)

rodata_800291F0:
 db 0;align(4)

aD_6:
 db "-d", 0;align(4)

aS_2:
 db "-s", 0;align(4)

aJ:
 db "-j", 0;align(16)

aVi_c_debug:
 db "vi_c_debug", 0;align(16)

a31m40m:
 db 0x1B, "[31m", 0x1B, "[40m", 0;align(4)

a37m40m:
 db 0x1B, "[37m", 0x1B, "[40m", 0;align(4)

a32m40m:
 db 0x1B, "[32m", 0x1B, "[40m", 0;align(4)

a33m40m:
 db 0x1B, "[33m", 0x1B, "[40m", 0;align(4)

a34m40m:
 db 0x1B, "[34m", 0x1B, "[40m", 0;align(4)

a35m40m:
 db 0x1B, "[35m", 0x1B, "[40m", 0;align(4)

a36m40m:
 db 0x1B, "[36m", 0x1B, "[40m", 0;align(4)

a37m44m:
 db 0x1B, "[37m", 0x1B, "[44m", 0;align(4)

a31m44m:
 db 0x1B, "[31m", 0x1B, "[44m", 0;align(4)

a32m44m:
 db 0x1B, "[32m", 0x1B, "[44m", 0;align(4)

a33m44m:
 db 0x1B, "[33m", 0x1B, "[44m", 0;align(4)

a30m44m:
 db 0x1B, "[30m", 0x1B, "[44m", 0;align(4)

a35m44m:
 db 0x1B, "[35m", 0x1B, "[44m", 0;align(4)

a36m44m:
 db 0x1B, "[36m", 0x1B, "[44m", 0;align(4)

a37m41m:
 db 0x1B, "[37m", 0x1B, "[41m", 0;align(4)

a30m41m:
 db 0x1B, "[30m", 0x1B, "[41m", 0;align(4)

a32m41m:
 db 0x1B, "[32m", 0x1B, "[41m", 0;align(4)

a33m41m:
 db 0x1B, "[33m", 0x1B, "[41m", 0;align(4)

a34m41m:
 db 0x1B, "[34m", 0x1B, "[41m", 0;align(4)

a35m41m:
 db 0x1B, "[35m", 0x1B, "[41m", 0;align(4)

a36m41m:
 db 0x1B, "[36m", 0x1B, "[41m", 0;align(4)

a37m45m:
 db 0x1B, "[37m", 0x1B, "[45m", 0;align(4)

a31m45m:
 db 0x1B, "[31m", 0x1B, "[45m", 0;align(4)

a32m45m:
 db 0x1B, "[32m", 0x1B, "[45m", 0;align(4)

a33m45m:
 db 0x1B, "[33m", 0x1B, "[45m", 0;align(4)

a34m45m:
 db 0x1B, "[34m", 0x1B, "[45m", 0;align(4)

a30m45m:
 db 0x1B, "[30m", 0x1B, "[45m", 0;align(4)

a36m45m:
 db 0x1B, "[36m", 0x1B, "[45m", 0;align(4)

a37m42m:
 db 0x1B, "[37m", 0x1B, "[42m", 0;align(4)

a31m42m:
 db 0x1B, "[31m", 0x1B, "[42m", 0;align(4)

a30m42m:
 db 0x1B, "[30m", 0x1B, "[42m", 0;align(4)

a33m42m:
 db 0x1B, "[33m", 0x1B, "[42m", 0;align(4)


aJoy_c_debug:
 db "joy_c_debug", 0;align(16)

__osRcpImTable:
 dh 0x555
 dh 0x556
 dh 0x559
 dh 0x55A
 dh 0x565
 dh 0x566
 dh 0x569
 dh 0x56A
 dh 0x595
 dh 0x596
 dh 0x599
 dh 0x59A
 dh 0x5A5
 dh 0x5A6
 dh 0x5A9
 dh 0x5AA
 dh 0x655
 dh 0x656
 dh 0x659
 dh 0x65A
 dh 0x665
 dh 0x666
 dh 0x669
 dh 0x66A
 dh 0x695
 dh 0x696
 dh 0x699
 dh 0x69A
 dh 0x6A5
 dh 0x6A6
 dh 0x6A9
 dh 0x6AA
 dh 0x955
 dh 0x956
 dh 0x959
 dh 0x95A
 dh 0x965
 dh 0x966
 dh 0x969
 dh 0x96A
 dh 0x995
 dh 0x996
 dh 0x999
 dh 0x99A
 dh 0x9A5
 dh 0x9A6
 dh 0x9A9
 dh 0x9AA
 dh 0xA55
 dh 0xA56
 dh 0xA59
 dh 0xA5A
 dh 0xA65
 dh 0xA66
 dh 0xA69
 dh 0xA6A
 dh 0xA95
 dh 0xA96
 dh 0xA99
 dh 0xA9A
 dh 0xAA5
 dh 0xAA6
 dh 0xAA9
 dh 0xAAA

rodata_80029420:
 float64 1000000.0

rodata_80029428:
 float64 1000000.0

rodata_80029430:
 float64 0.017453292222222222
align(16)

rodata_80029440:
 db 0
 db 0x14
 db 0x18
 db 0x18
 db 0x1C
 db 0x1C
 db 0x1C
 db 0x1C
 db 0x20
 db 0x20
 db 0x20
 db 0x20
 db 0x20
 db 0x20
 db 0x20
 db 0x20
 db 0
 db 4
 db 8
 db 8
 db 0xC
 db 0xC
 db 0xC
 db 0xC
 db 0x10
 db 0x10
 db 0x10
 db 0x10
 db 0x10
 db 0x10
 db 0x10
 db 0x10

rodata_80029460:
 dw 0x70010648 //redispatch
 dw 0x70010610 //swl
 dw 0x700105F0 //sw2
 dw 0x70010454 //rcp
 dw 0x70010400 //cart
 dw 0x70010594 //prenmi
 dw 0x700103C8 //IP6_Hdlr
 dw 0x700103D4 //IP7_Hdlr
 dw 0x700103E0 //counter
align(16)



jpt_80011278:
 dw 0x70011620, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011280, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011678, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011750, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011988, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x700116DC, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x70011A54, 0x70011A54, 0x70011A54, 0x70011A54
 dw 0x700119BC
jpt_80011AC8:
 dw 0x70011AD0
 dw 0x7001202C
 dw 0x70011E00
 dw 0x7001202C
 dw 0x7001202C
 dw 0x70011BBC
 dw 0x70011C08
 dw 0x70011E1C
 dw 0x7001202C
 dw 0x70011B9C
 dw 0x70011E3C
 dw 0x7001202C
 dw 0x70011FCC
 dw 0x70011FE8
 dw 0x7001201C
 dw 0x70011EA0
 dw 0x70011EC4
 dw 0x70011F30
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x70011E00
 dw 0x70011C6C
 dw 0x70011D78
jpt_80011B04:
 dw 0x70011B0C
 dw 0x7001202C
 dw 0x70011B34
 dw 0x70011B60
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x7001202C
 dw 0x70011B8C
 dw 0x70011B8C
 dw 0x70011B8C


rodata_800296C4:
 float32 500000.0
align(16)

rodata_800296D0:
 float64 1000000.0

rodata_800296D8:
 float64 1000000.0

rodata_800296E0:
 float32 1.0005778

rodata_800296E4:
 float32 0.99942255
align(16)

aHll:
 db "hlL", 0;align(4)

rodata_800296F4:
 db " +-#0", 0;align(4)

byteshiftleft_lookup:
 dw 1
 dw 2
 dw 4
 dw 8
 dw 0x10
 dw 0

jpt_80013944:
 dw 0x70013C58, 0x70013F38, 0x70013C58, 0x70013F38
 dw 0x70013F38, 0x70013F38, 0x70013F38, 0x70013F38
 dw 0x70013F38, 0x70013F38, 0x70013F38, 0x70013F38
 dw 0x70013F38, 0x70013F38, 0x70013F38, 0x70013F38
 dw 0x70013F38, 0x70013F38, 0x70013F38, 0x70013B08
 dw 0x70013F38, 0x70013F38, 0x70013F38, 0x70013F38
 dw 0x70013F38, 0x70013F38, 0x70013F38, 0x70013F38
 dw 0x70013F38, 0x70013F38, 0x70013960, 0x70013998
 dw 0x70013C58, 0x70013C58, 0x70013C58, 0x70013F38
 dw 0x70013998, 0x70013F38, 0x70013F38, 0x70013F38
 dw 0x70013F38, 0x70013DBC, 0x70013B08, 0x70013E8C
 dw 0x70013F38, 0x70013F38, 0x70013ED4, 0x70013F38
 dw 0x70013B08, 0x70013F38, 0x70013F38, 0x70013B08
align(16)

rodata_800297F0:
 float32 0.017453292
align(16)

rodata_80029800:
 float64 127.0
align(16)

rodata_80029810:
 float32 0.017453292
align(16)

rodata_80029820:
 dw 0x80000000
align(8)

rodata_80029828:
 dw 0x80000000
align(8)

jpt_80019520:
 dw 0x70019528
 dw 0x70019534
 dw 0x7001954C
 dw 0x70019558
 dw 0x70019540
 dw 0x70019564

rodata_80029848:
 float64 173123.404906676

jpt_8001A628:
 dw 0x7001A630
 dw 0x7001A6C0
 dw 0x7001A6C0
 dw 0x7001A638
 dw 0x7001A6C0
 dw 0x7001A6C0
 dw 0x7001A6A4
 dw 0x7001A6B4
 dw 0x7001A674
 align(8)

rodata_80029878:
 float64  1.99996
 float32 1.9999599
 dw 0
 dw 0
 dw 0


aAssertionFaultSSLineD:
 db "\n--- ASSERTION FAULT - %s - %s, line %d\n\n", 0;align(4)

aSamples0:
 db "samples >= 0",0;align(4)

aEnv_c:
 db "env.c",0;align(4)

aAssertionFaultSSLineD_0:
 db "\n--- ASSERTION FAULT - %s - %s, line %d\n\n", 0;align(4)

aSamplesAl_max_rsp_samples:
 db "samples <= AL_MAX_RSP_SAMPLES",0;align(4)

aEnv_c_0:
 db "env.c",0;align(4)

aAssertionFaultSSLineD_1:
 db "\n--- ASSERTION FAULT - %s - %s, line %d\n\n", 0;align(4)

aSource:
 db "source",0;align(4)

aEnv_c_1:
 db "env.c",0;align(4)

rodata_80029964:
 float32 65535.0


jpt_8001AF6C:
 dw 0x7001B398  //jump table for switch statement
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B3B8
 dw 0x7001B0B4
 dw 0x7001B0B4
 dw 0x7001AF74
 dw 0x7001B304
 dw 0x7001B358
 dw 0x7001B0B4
align(16)

rodata_800299B0:
 float64  1.0

rodata_800299B8:
 float64  -0.16666659550427756

rodata_800299C0:
 float64  0.008333066246082155

rodata_800299C8:
 float64  -0.0001980960290193795

rodata_800299D0:
 float64  0.000002605780637968037

rodata_800299D8:
 float64  0.3183098861837907

rodata_800299E0:
 float64  3.1415926218032839

rodata_800299E8:
 float64  3.178650954705639e-8

rodata_800299F0:
 float64  0.0
align(16)

rodata_80029A00:
 float64  1.0

rodata_80029A08:
 float64  -0.16666659550427756

rodata_80029A10:
 float64  0.008333066246082155

rodata_80029A18:
 float64  -0.0001980960290193795

rodata_80029A20:
 float64  0.000002605780637968037

rodata_80029A28:
 float64  0.3183098861837907

rodata_80029A30:
 float64  3.1415926218032839

rodata_80029A38:
 float64  3.178650954705639e-8

rodata_80029A40:
 float64  0.0
align(16)

jpt_8001C498:
 dw 0x7001C7F4, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001C4A0, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001C84C, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001C92C, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CB98, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001C8B4, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CC64, 0x7001CC64, 0x7001CC64, 0x7001CC64
 dw 0x7001CBCC

jpt_8001C98C:
 dw 0x7001C9F0
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001C994
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CA84
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64
 dw 0x7001CC64

jpt_8001CCD8:
 dw 0x7001CCE0
 dw 0x7001D24C
 dw 0x7001CFF4
 dw 0x7001D24C
 dw 0x7001D24C
 dw 0x7001CDAC
 dw 0x7001CDF8
 dw 0x7001D014
 dw 0x7001D24C
 dw 0x7001CD8C
 dw 0x7001D14C
 dw 0x7001D1B4
 dw 0x7001D1D0
 dw 0x7001D1EC
 dw 0x7001D23C
 dw 0x7001D028
 dw 0x7001D04C
 dw 0x7001D0BC
 dw 0x7001D24C
 dw 0x7001D24C
 dw 0x7001D24C
 dw 0x7001D24C
 dw 0x7001CE5C
 dw 0x7001CF6C


rodata_80029C88:
 float32 500000.0
align(16)

digits:
 float64 10.0
 float64 100.0
 float64 10000.0
 float64 1.0e8
 float64 1.0e16
 float64 1.0e32
 float64 1.0e64
 float64 1.0e128
 float64 1.0e256


aNan:
 db "NaN",0;align(4)

aInf:
 db "Inf",0;align(4)

rodata_80029CE0:
db "0",0;align(8)


rodata_80029CE8:
 float64  1.0e8

jpt_8001E80C:
 dw 0x7001E920
 dw 0x7001E814
 dw 0x7001E854
 dw 0x7001E940
 dw 0x7001E940
 dw 0x7001E890
 dw 0x7001E8D8
align(16)

jpt_8001FFCC:
 dw 0x7001FFD4
 dw 0x70020004
 dw 0x70020064
 dw 0x70020034
 dw 0x70020094
 dw 0x700200C4
 dw 0x70020108
 dw 0x70020184

rodata_80029D30:
 float64 4.9039833923682244e55

rodata_80029D38:
 float64  173123.404906676

rodata_80029D40:
 float64 1.4922257467118834e306
align(16)

rodata_80029D50:
 float64  1000000.0

rodata_80029D58:
 float64  1000000.0

rodata_80029D60:
 dw 0
 dw bss_80069170
 dw bss_80069170

animation_table_ptrs1:
 dw 0x1C, 0x144, 0x214, 0x318, 0x3C4, 0x610, 0x814, 0x990
 dw 0xB84, 0xDB4, 0x1028, 0x1334, 0x1578, 0x17B4, 0x186C
 dw 0x1984, 0x1A6C, 0x1B54, 0x1C9C, 0x1E40, 0x1F84, 0x2134
 dw 0x282C, 0x299C, 0x2E64, 0x2F94, 0x30B8, 0x31DC, 0x32C8
 dw 0x33AC, 0x34D4, 0x35C8, 0x36D8, 0x384C, 0x39C0, 0x3AF0
 dw 0x3C10, 0x3D04, 0x3D9C, 0x3FA0, 0x4018, 0x4070, 0x40D4
 dw 0x4144, 0x4298, 0x42C8, 0x4384, 0x4504, 0x4574, 0x45CC
 dw 1, 1, 0x47BC, 0x4A40, 0x4CE0, 0x4F14, 0x51C4, 0x540C
 dw 0x54A0, 0x5554, 0x5684, 0x5744, 0x5964, 0x5D10, 0x5EF0
 dw 0x60D4, 0x6254, 0x637C, 0x6484, 0x6554, 0x6644, 0x6738
 dw 0x6808, 0x694C, 0x6A18, 0x6C18, 0x6D50, 0x6F08, 0x700C
 dw 0x71D0, 0x7304, 0x7430, 0x74A4, 0x7514, 0x7588, 0x75EC
 dw 0x7650, 0x76B8, 0x7714, 0x777C, 0x77D4, 1, 1, 1
 dw 1, 1, 1, 0x78C8, 0x7AA8, 0x7C4C, 0x7D04, 0x7DD8
 dw 0x7F0C, 0x7FB4, 0x8080, 0x8164, 0x8194, 0x8204, 0x8274
 dw 0x82E0, 0x8340, 0x83A4, 0x8404, 0x845C, 0x84C4, 0x8520
 dw 0x8698, 0x8800, 0x8978, 0x8AAC, 0x8BF0, 0x8D28, 0x8E1C
 dw 0x8F2C, 0x9084, 0x9194, 0x92EC, 0x9444, 0x95FC, 0x97BC
 dw 0x98C8, 0x9A2C, 0x9B48, 0x9C4C, 0x9D5C, 0x9E44, 0x9F48
 dw 0xA094, 0xA1B8, 0xA2F8, 0xA424, 0xA538, 0xA650, 1
 dw 1, 1, 1, 0xA6B0, 0xA704, 0xA8BC, 0xA94C, 0xA9DC
 dw 0xACAC, 0xB174, 0xB2AC, 0xB528, 0xB6B0, 0xB7C8, 0xB854
 dw 0xB9A8, 0xBC40, 0xBF80, 0xC224, 0xC410, 0xC544, 0xC838
 dw 0xCB78, 0xCE6C, 0xD0A8, 1, 0xD348, 0xD54C, 0xD5E4
 dw 0xD668, 0xD6F8, 0xD728, 0xD89C, 0xDBE4, 0xDD20, 0xE05C
 dw 0xE08C, 0xE0BC, 0xE18C, 0

animation_table_ptrs2:
 dw 0xE470

rodata_8002A050:
 dw 0xE5F4
 dw 0xE7C0
 dw 0
 dw 0

global_action_block_temp_buffer:
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

weapon_models_for_weapon_load:
 dw 0xBA, 0xC4, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xFFFFFFFF
 dw 0

ptr_monitorimageobjectanimationcontroller:
 dw monitor_animation_microcode
 dw 0xFFFF
 dw 0
 dw 0
 dw 0x3F800000, 0, 0
 dw 0x3F800000, 0x3F800000, 0x3F800000, 0, 0
 dw 0x3F800000, 0x3F800000, 0x3F000000, 0, 0
 dw 0x3F000000, 0x3F000000, 0x3F000000, 0, 0

rodata_8002A2B8:
 dw 0x3F000000, 0x3F000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF
 dw 0x3F800000, 0

unknown_object_animation_controller:
 dw rodata_80031F00
 dw 0xFFFF
 dw 0
 dw 0
 dw 0x3F800000, 0, 0
 dw 0x3F800000, 0x3F800000, 0x3F800000, 0, 0
 dw 0x3F800000, 0x3F800000, 0x3F000000, 0, 0
 dw 0x3F000000, 0x3F000000, 0x3F000000, 0, 0

rodata_8002A32C:
 dw 0x3F000000, 0x3F000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF
 dw 0x3F800000, 0

taser_object_animation_controller:
 dw 0x80031F44
 dw 0xFFFF
 dw 0
 dw 0
 dw 0x3F800000, 0, 0
 dw 0x3F800000, 0x3F800000, 0x3F800000, 0, 0
 dw 0x3F800000, 0x3F800000, 0x3F000000, 0, 0
 dw 0x3F000000, 0x3F000000, 0x3F000000, 0, 0

rodata_8002A3A0:
 dw 0x3F000000, 0x3F000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF
 dw 0x3F800000, 0, 0

rodata_8002A3C0:
 dw 0x3F800000
 dw 0
 dw 0
 dw 0

BONDdata_item_control_blocks_initdata:
 dw 0
 dw 0xFFFFFFFF, 0
 dw 0x100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0x3F800000, 0, 0, 0, 0
 dw 0x3F800000, 0, 0, 0, 0
 dw 0x3F800000, 0, 0, 0, 0
 dw 0x3F800000, 0, 0, 0, 0, 0, 0
 dw 0xBF800000, 0
 dw 0x3F800000, 0, 0, 0, 0, 0, 0
 dw 0xC19FFFFE, 0
 dw 0x419FFFFE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0
 dw 0xBF800000, 0, 0
 dw 0xBF800000, 0, 0
 dw 0xBF800000, 0, 0
 dw 0xBF800000, 0
 dw 0x3F800000, 0, 0
 dw 0x3F800000, 0, 0
 dw 0x3F800000, 0, 0
 dw 0x3F800000, 0, 0, 0
 dw 0x3F800000, 0x3F800000, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0
 dw 0x447A0000, 0, 0, 0, 0
 dw 0xFF000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
 dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

rodata_8002A778:
 dw 0
align(16)

rodata_8002A780:
 dw 0

rodata_8002A784:
 dw 0

rodata_8002A788:
 dw 0
align(16)

rodata_8002A790:
 dw 0

rodata_8002A794:
 dw 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

rodata_8002A7D4:
 dw 0x3000000, 0, 0, 0, 0

rodata_8002A7E8:
 dw 0xFF, 0xFF, 0xFF, 0, 0, 0

rodata_8002A800:
 dw 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

rodata_8002A83C:
 dw 0x44DBC976, 0x435C0000, 0x442B1203, 0xBF7851EC, 0

rodata_8002A850:
 float32 0.23999999

rodata_8002A854:
 dw 0

rodata_8002A858:
 dw 0x3F800000

rodata_8002A85C:
 dw 0x80000000

rodata_8002A860:
 db 0xDC, 0xDC, 0xDC, 0

rodata_8002A864:
 db 0xDC, 0xDC, 0xDC, 0

rodata_8002A868:
 db 0xFF, 0xFF, 0xFF, 0
 db 0xFF, 0xFF, 0xFF, 0
 dw 0x7F0000
 dw 0

rodata_8002A878:
 dw 0

rodata_8002A87C:
 dw 0

rodata_8002A880:
 dw 0x45989800, 0, 0

rodata_8002A88C:
 float32 -1.0

rodata_8002A890:
 dw 0

rodata_8002A894:
 float32 1.0

rodata_8002A898:
 dw 0

rodata_8002A89C:
 dw 0

intro_eye_counter:
 dw 0

intro_state_blood_animation:
 dw 0

rodata_8002A8A8:
 dw 0

rodata_8002A8AC:
 dw 0

rodata_8002A8B0:
 dw 0
 dw 0
 dw 0
 dw 0

current_menu:
 dw 0xFFFFFFFF

menu_update:
 dw 0xFFFFFFFF

maybe_prev_menu:
 dw 0xFFFFFFFF

folder_select_timer:
 dw 0

tab_1_selected:
 dw 0

tab_2_selected:
 dw 0

tab_3_selected:
 dw 0

tab_1_highlight:
 dw 0

tab_2_highlight:
 dw 0

tab_3_highlight:
 dw 0

selected_folder_num:
 dw 0

selected_folder_num_copy:
 dw 0



gamemode:
 dw GAMEMODE_INTRO
selected_stage:
 dw 0xFFFFFFFF
ptr_briefingdata:
 dw 0xFFFFFFFF
selected_difficulty:
 dw DIFFICULTY_MULTI
append_cheat_sp:
 dw 0
append_cheat_mp:
 dw 0
cursor_h_pos:
 float32 220.0
cursor_v_pos:
 float32 165.0
final_menu_briefing_page:
 dw 2
current_menu_briefing_page:
 dw 0
folder_selection_screen_option_icon:
 dw 0
folder_selected_for_deletion:
 dw 0xFFFFFFFF
folder_selected_for_deletion_choice:
 dw 1
mission_failed_or_aborted:
 dw 0
mission_kia:
 dw 0
is_first_time_on_legal_screen:
 dw TRUE
is_first_time_on_main_menu:
 dw TRUE
prev_keypresses:
 dw 0
rodata_8002A938:
 dw 0
rodata_8002A93C:
 dw 1
screen_size:
 dw SCREEN_SIZE_320x240
rodata_8002A944:
 dw 0
is_emulating_spectrum:
 dw FALSE
is_cheat_menu_available:
 dw FALSE
ptr_logo_and_walletbond_DL:
 dw 0
ptr_menu_videobuffer:
 dw 0
something_legalscreen_constructor:
 dw 0
ptr_folder_object_instance:
 dw 0
rodata_8002A960:
 dw 0
rodata_8002A964:
 dw 0
rodata_8002A968:
 dw 0
rodata_8002A96C:
 dw 0


insert rodata.bin_raw, "021990.bin", origin()

//temporary
base $80030B74
monitor_animation_microcode:
base $80031F00
rodata_80031F00:


base $8005D2E0
rodata_end:

