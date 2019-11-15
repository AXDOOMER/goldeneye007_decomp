# Makefile to rebuild Goldeneye 007

### Default target ###
default: all

### Build Options ###
# Version of the game to build
FINAL := YES
VERSION := US
# If COMPARE is 1, check the output sha1sum when building 'all'
COMPARE := 1



TOOLCHAIN := mips-linux-gnu-
QEMU_IRIX := tools/irix/qemu-irix
IRIX_ROOT := tools/irix/root
# other tools
TOOLS_DIR := tools
DATASEG_COMP := $(TOOLS_DIR)/data_compress.sh
RZ_COMP := $(TOOLS_DIR)/1172compress.sh
N64CKSUM := $(TOOLS_DIR)/n64cksum
MAKEBG := $(TOOLS_DIR)/makebg.sh
SHA1SUM = sha1sum

ifeq ($(FINAL), YES)
 OPTIMIZATION := -O2
 LCDEFS :=
 CFLAGWARNING :=
else
 OPTIMIZATION := -g
 LCDEFS := -DDEBUG
 CFLAGWARNING :=-fullwarn -wlint
endif

ifeq ($(VERSION), US)
COUNTRYCODE := u
LCDEFS := -DVERSION_US
ASMDEFS := --defsym VERSION_US=1
endif

ifeq ($(VERSION), EU)
COUNTRYCODE := e
LCDEFS := -DVERSION_EU
ASMDEFS := --defsym VERSION_EU=1
endif

ifeq ($(VERSION), JP)
COUNTRYCODE := j
LCDEFS := -DVERSION_JP
ASMDEFS := --defsym VERSION_JP=1
endif

BUILD_DIR := build/$(COUNTRYCODE)
include assets/Makefile.obseg
include assets/Makefile.music
BUILD_SUB_DIRS := \
	src src/game src/rarezip libultra assets assets/obseg \
	assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop \
	assets/obseg/text assets/obseg/bg assets/obseg/setup assets/obseg/stan \
	assets/music assets/ramrom assets/images assets/images/split assets/font
# create build directories
$(shell mkdir -p $(BUILD_DIR))
$(foreach subdir,$(BUILD_SUB_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(subdir)))







APPELF := ge007.$(COUNTRYCODE).elf
APPROM := ge007.$(COUNTRYCODE).z64
APPBIN := ge007.$(COUNTRYCODE).bin

HEADERFILES := $(foreach dir,src,$(wildcard $(dir)/*.s))
HEADEROBJECTS := $(foreach file,$(HEADERFILES),$(BUILD_DIR)/$(file:.s=.o))

CODEFILES := $(foreach dir,src,$(wildcard $(dir)/*.c))
CODEOBJECTS := $(foreach file,$(CODEFILES),$(BUILD_DIR)/$(file:.c=.o))

LIBULTRA := lib/libultra_rom.a
ULTRAFILES := libultra/libultra.s
ULTRAOBJECTS := $(BUILD_DIR)/libultra/osPiRawStartDma.o \
$(BUILD_DIR)/libultra/osPiGetStatus.o \
$(BUILD_DIR)/libultra/osInitialize.o \
$(BUILD_DIR)/libultra/osWritebackDCacheAll.o \
$(BUILD_DIR)/libultra/osInvalICache.o \
$(BUILD_DIR)/libultra/osUnmapTLB.o \
$(BUILD_DIR)/libultra/__osGetFpcCsr.o \
$(BUILD_DIR)/libultra/__osSetFpcCsr.o \
$(BUILD_DIR)/libultra/osCreateThread.o \
$(BUILD_DIR)/libultra/osStartThread.o \
$(BUILD_DIR)/libultra/osCreateMesgQueue.o \
$(BUILD_DIR)/libultra/osStopThread.o \
$(BUILD_DIR)/libultra/osSetThreadPri.o \
$(BUILD_DIR)/libultra/osGetCount.o \
$(BUILD_DIR)/libultra/osCreateViManager.o \
$(BUILD_DIR)/libultra/osViModeTable.o \
$(BUILD_DIR)/libultra/osSetEventMesg.o \
$(BUILD_DIR)/libultra/osViSetEvent.o \
$(BUILD_DIR)/libultra/osSetIntMask.o \
$(BUILD_DIR)/libultra/osRecvMesg.o \
$(BUILD_DIR)/libultra/osSendMesg.o \
$(BUILD_DIR)/libultra/osViSetMode.o \
$(BUILD_DIR)/libultra/osViSetXScale.o \
$(BUILD_DIR)/libultra/osViSetYScale.o \
$(BUILD_DIR)/libultra/osViRepeatLine.o \
$(BUILD_DIR)/libultra/osViBlack.o \
$(BUILD_DIR)/libultra/osSpTaskYielded.o \
$(BUILD_DIR)/libultra/osDpGetCounters.o \
$(BUILD_DIR)/libultra/osViGetCurrentFramebuffer.o \
$(BUILD_DIR)/libultra/osViGetNextFramebuffer.o \
$(BUILD_DIR)/libultra/osViSwapBuffer.o \
$(BUILD_DIR)/libultra/osDpSetStatus.o \
$(BUILD_DIR)/libultra/osSpTaskLoad.o \
$(BUILD_DIR)/libultra/osDpSetNextBuffer.o \
$(BUILD_DIR)/libultra/osSpTaskYield.o \
$(BUILD_DIR)/libultra/__osGetTLBHi.o \
$(BUILD_DIR)/libultra/osVirtualToPhysical.o \
$(BUILD_DIR)/libultra/osAiSetFrequency.o \
$(BUILD_DIR)/libultra/alInit.o \
$(BUILD_DIR)/libultra/osGetTime.o \
$(BUILD_DIR)/libultra/ll.o \
$(BUILD_DIR)/libultra/osAiGetLength.o \
$(BUILD_DIR)/libultra/syn.o \
$(BUILD_DIR)/libultra/osPiStartDma.o \
$(BUILD_DIR)/libultra/osViSetSpecialFeatures.o \
$(BUILD_DIR)/libultra/_bcopy.o \
$(BUILD_DIR)/libultra/guPerspective.o \
$(BUILD_DIR)/libultra/Mtx.o \
$(BUILD_DIR)/libultra/__osGetCurrFaultedThread.o \
$(BUILD_DIR)/libultra/exception.o \
$(BUILD_DIR)/libultra/__osDequeueThread.o \
$(BUILD_DIR)/libultra/osYieldThread.o \
$(BUILD_DIR)/libultra/osInvalDCache.o \
$(BUILD_DIR)/libultra/osWritebackDCache.o \
$(BUILD_DIR)/libultra/osSetTimer.o \
$(BUILD_DIR)/libultra/alHeapInit.o \
$(BUILD_DIR)/libultra/libultra.o

GAMEFILES := $(foreach dir,src/game,$(wildcard $(dir)/*.c))
GAMEOBJECTS := $(foreach file,$(GAMEFILES),$(BUILD_DIR)/$(file:.c=.o))

ROMFILES := assets/romfiles.s
ROMOBJECTS := $(BUILD_DIR)/assets/romfiles.o

RAMROM_FILES := assets/ramrom/ramrom.s
RAMROM_OBJECTS := $(BUILD_DIR)/assets/ramrom/ramrom.o

FONT_FILES := assets/font/font.s
FONT_OBJECTS := $(BUILD_DIR)/assets/font/font.o

MUSIC_FILES := assets/music/music.s
MUSIC_OBJECTS := $(BUILD_DIR)/assets/music/music.o

OBSEG_FILES := assets/obseg/ob_seg.s
OBSEG_OBJECTS := $(BUILD_DIR)/assets/obseg/ob_seg.o
OBSEG_RZ := $(BG_SEG_FILES) $(CHR_RZ_FILES) $(GUN_RZ_FILES) $(PROP_RZ_FILES) $(STAN_RZ_FILES) $(BRIEF_RZ_FILES) $(SETUP_RZ_FILES) $(TEXT_RZ_FILES)

IMAGE_BINS := $(foreach dir,assets/images/split,$(wildcard $(dir)/*.bin))
IMAGE_OBJS := $(foreach file,$(IMAGE_BINS),$(BUILD_DIR)/$(file:.bin=.o))

RZFILES := rarezip/rarezip.c
RZOBJECTS := $(foreach file,$(RZFILES),$(BUILD_DIR)/src/$(file:.c=.o))

OBJECTS := $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(OBSEGMENT) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS)



INCLUDE := -I . -I include -I include/libultra -I src -I src/game -I src/rarezip

CC := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
CFLAGS := -Wo,-loopunroll,0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(CFLAGWARNING) -woff 819,820,852,821,838 -signed $(INCLUDE) -mips2 $(LCDEFS)

LD := $(TOOLCHAIN)ld
LD_SCRIPT := ge007.$(COUNTRYCODE).ld
LDFLAGS := -T undefined_syms.txt -T $(LD_SCRIPT) -Map build/ge007.$(COUNTRYCODE).map

AS := $(TOOLCHAIN)as
ASFLAGS := -march=vr4300 -mabi=32 $(INCLUDE) $(ASMDEFS)
ASM_PREPROC := python3 tools/asmpreproc/asm-processor.py

OBJCOPY := $(TOOLCHAIN)objcopy

all: $(APPROM)
ifeq ($(COMPARE),1)
	@$(SHA1SUM) -c ge007.$(COUNTRYCODE).sha1
endif


codeclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(COUNTRYCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS)

dataclean: 
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(COUNTRYCODE).map \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES)

clean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(COUNTRYCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES)

$(BUILD_DIR)/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/src/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/%.o: assets/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/ramrom/%.o: assets/ramrom/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/font/%.o: assets/font/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/obseg/%.o: assets/obseg/%.s $(OBSEG_RZ)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/assets/images/split/%.o: assets/images/split/%.bin
	$(LD) -r -b binary $< -o $@

$(BUILD_DIR)/%.o: src/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s

$(BUILD_DIR)/src/%.o: src/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s

$(BUILD_DIR)/$(OBSEGMENT): $(OBSEG_RZ) $(IMAGE_OBJS)
	

$(APPELF): $(ULTRAOBJECTS) $(HEADEROBJECTS) $(OBSEG_RZ) $(BUILD_DIR)/$(OBSEGMENT) $(MUSIC_RZ_FILES) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(OBSEG_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ 

$(APPBIN): $(APPELF)
	$(OBJCOPY) $< $@ -O binary --gap-fill=0xff
	
$(APPROM):	$(APPBIN)
	$(DATASEG_COMP) $< $(COUNTRYCODE)
	$(N64CKSUM) $< $@
	rm header.tmp

.PHONY: all default codeclean dataclean clean



