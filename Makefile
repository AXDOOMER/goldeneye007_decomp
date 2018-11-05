# Makefile to rebuild Goldeneye 007
include Makefile.obseg
include Makefile.music

FINAL := YES
VERSION := US
TOOLCHAIN := mips-linux-gnu-

BUILD_DIR := build
BUILD_SUB_DIRS := \
	code game rarezip libultra \
	assets \
	assets/obseg \
	assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop assets/obseg/text \
	assets/obseg/bg assets/obseg/setup assets/obseg/stan \
	assets/music \
	assets/ramrom \
	assets/images \
	assets/font
# create build directories
$(shell mkdir -p $(BUILD_DIR))
$(foreach dir,$(BUILD_SUB_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

ifeq ($(FINAL), YES)
 OPTIMIZATION := -O2
 LCDEFS :=
else
 OPTIMIZATION := -g
 LCDEFS := -DDEBUG
endif

ifeq ($(VERSION), EU)
COUNTRYCODE := e
LCDEFS := -DVERSION_EU
else 
ifeq ($(VERSION), JP)
COUNTRYCODE := j
LCDEFS := -DVERSION_JP
else
COUNTRYCODE := u
LCDEFS := -DVERSION_US
endif
endif


APP := ge007.$(COUNTRYCODE).elf
TARGET := ge007.$(COUNTRYCODE).z64
TARGETBIN := ge007.$(COUNTRYCODE).bin

HFILES := $(foreach dir,$(CODE_DIRS),$(wildcard $(dir)/*.h))

HEADERFILES := rom_header.s bootcode.s _start.s rspboot.s gspboot.s aspboot.s
HEADEROBJECTS := build/rom_header.o build/bootcode.o build/_start.o build/rspboot.o build/gspboot.o build/aspboot.o


BOOTFILES := boot.c
BOOTOBJECTS := build/boot.o
BOOTSEGMENT := bootsegment.o

CODEFILES := code/init.c code/sched.c code/osMapTLB.c code/tlb_manage.c code/tlb_random.c code/tlb_resolve.c code/audi.o \
			   code/speed_graph.c code/video.c code/deb.c code/debug_getlastRA.c code/ramrom.c code/boss.c code/music.o \
			   code/sfx.c code/memp.c code/mema.c code/random.c code/token.c code/stringhandler.c code/sprintf.c code/pi.c code/vi.o \
			   code/debugmenu.c code/joy.c code/joy_rumble.c code/rmon.c
CODEOBJECTS := build/code/init.o build/code/sched.o build/code/osMapTLB.o build/code/tlb_manage.o build/code/tlb_random.o build/code/tlb_resolve.o build/code/audi.o \
			   build/code/speed_graph.o build/code/video.o build/code/deb.o build/code/debug_getlastRA.o build/code/ramrom.o build/code/boss.o build/code/music.o \
			   build/code/sfx.o build/code/memp.o build/code/mema.o build/code/random.o build/code/token.o build/code/stringhandler.o build/code/sprintf.o build/code/pi.o build/code/vi.o \
			   build/code/debugmenu.o build/code/joy.o build/code/joy_rumble.o build/code/rmon.o
CODESEGMENT := codesegment.o

#ULTRAFILES := libultra/pirawstartdma.c libultra/pigetstatus.c libultra/initialize.c libultra/writebackdcacheall.c \
#			  libultra/invalicache.c libultra/unmaptlb.c libultra/getfpccsr.c libultra/setfpccsr.c libultra/createthread.c \
#			  libultra/startthread.c libultra/createmesgqueue.c libultra/stopthread.c libultra/setthreadpri.c libultra/getcount.c \
#			  libultra/createvimanager.c libultra/vimodetable.c libultra/seteventmesg.c libultra/visetevent.c libultra/setintmask.c \
#			  libultra/recvmesg.c libultra/sendmesg.c libultra/visetmode.c libultra/visetxscale.c libultra/visetyscale.c \
#			  libultra/virepeatline.c libultra/viblack.c libultra/sptaskyielded.c libultra/dpgetcounters.c libultra/vigetcurrentframebuffer.c \
#			  libultra/vigetnextframebuffer.c libultra/viswapbuffer.c libultra/dpsetstatus.c libultra/sptask.c libultra/dpsetnextbuffer.c \
#			  libultra/
#ULTRAOBJECTS :=
#ULTRASEGMENT := libultra.a
ULTRAFILES := libultra/libultra.s
ULTRAOBJECTS := build/libultra/libultra.o


GAMEFILES := game/initgamedata.c game/initweaponanigroups.c game/initactorpropstuff.c game/initnull_0009D0.c \
			game/initunk_0009E0.c game/initanitable.c game/initunk_000B60.c game/setguscale.c game/initnull_000BC0.c \
			game/initimages.c game/initintromatrices.c game/initmenus.c game/initguards.c game/deb_loadallmodels.c \
			game/initobjects.c game/prop.c game/objective.c game/ejectedcartridges.c game/initBondDATA.c \
			game/initunk_005450.c game/initunk_005520.c game/initcameraandthrown.c game/inititemslots.c \
			game/initBondDATAdefaults.c game/initpathtablesomething.c game/initpathtablelinks.c game/initexplosioncasing.c \
			game/initunk_007180.c game/initunk_007290.c game/initunk_0072B0.c game/initmttex.c game/initunk_0073B0.c \
			game/initunk_007460.c game/cleanup_alarms.c game/cleanup_objects.c game/cleanup_objectives.c game/sfxunk_007700.c \
			game/playerstats_007770.c game/unk_007800.c game/unk_007920.c game/null_007970.c game/unk_007980.c \
			game/intro_logos.c game/mainmenu.c game/blood_animation.c \
			game/blood_decrypt.c game/eeprom.c game/actor.c game/actionblock.c game/loadobjectmodel.c game/objective_status.c \
			game/sin.c game/unk_057FD0.c game/unk_05A9E0.c game/convertangleusinginverse.c game/unk_05AB70.c game/unk_05ACB0.c \
			game/unk_05AE00.c game/unk_05B1E0.c game/truncf.c game/unk_05C440.c game/bondview.c game/objecthandler.c \
			game/othermodemicrocode.c game/bond.c game/unk_08DBB0.c game/debugmenu_08FE00.c game/unk_091080.c \
			game/cheat_buttons_objectrelated.c game/unk_092890.c game/unk_092E50.c game/unk_093880.c game/unk_09B600.c game/unk_09B740.c \
			game/unk_09B7A0.c game/unk_09C250.c game/unk_0A1DA0.c game/watch.c game/textrelated.c game/stan.c game/unk_0B3200.c \
			game/bg.c game/fog.c game/lightfixture.c game/unk_0BC530.c game/ob.c game/dyn.c game/lvl.c game/unk_0C0A70.c \
			game/mp_music.c game/lvl_text.c game/mp_watch.c game/radar.c game/mp_weapon.c game/image.c game/image_bank.c \
			game/unk_0CC4C0.c game/decompress.c game/zlib.c game/rsp.c game/indy_comms.c game/indy_0D0180.c game/game_debug.c \
			game/compiletime.c game/unk_0D1AC0.c game/viewport.c game/music_0D2720.c game/spectrum.c
GAMEOBJECTS := build/game/initgamedata.o build/game/initweaponanigroups.o build/game/initactorpropstuff.o \
			build/game/initnull_0009D0.o build/game/initunk_0009E0.o build/game/initanitable.o build/game/initunk_000B60.o \
			build/game/setguscale.o build/game/initnull_000BC0.o build/game/initimages.o build/game/initintromatrices.o \
			build/game/initmenus.o build/game/initguards.o build/game/deb_loadallmodels.o build/game/initobjects.o \
			build/game/prop.o build/game/objective.o build/game/ejectedcartridges.o build/game/initBondDATA.o \
			build/game/initunk_005450.o build/game/initunk_005520.o build/game/initcameraandthrown.o \
			build/game/inititemslots.o build/game/initBondDATAdefaults.o build/game/initpathtablesomething.o \
			build/game/initpathtablelinks.o build/game/initexplosioncasing.o build/game/initunk_007180.o \
			build/game/initunk_007290.o build/game/initunk_0072B0.o build/game/initmttex.o build/game/initunk_0073B0.o \
			build/game/initunk_007460.o build/game/cleanup_alarms.o build/game/cleanup_objects.o \
			build/game/cleanup_objectives.o build/game/sfxunk_007700.o build/game/playerstats_007770.o \
			build/game/unk_007800.o build/game/unk_007920.o build/game/null_007970.o build/game/unk_007980.o \
			build/game/intro_logos.o build/game/mainmenu.o \
			build/game/blood_animation.o build/game/blood_decrypt.o build/game/eeprom.o \
			build/game/actor.o build/game/actionblock.o build/game/loadobjectmodel.o build/game/objective_status.o \
			build/game/sin.o build/game/unk_057FD0.o build/game/unk_05A9E0.o build/game/convertangleusinginverse.o \
			build/game/unk_05AB70.o build/game/unk_05ACB0.o build/game/unk_05AE00.o build/game/unk_05B1E0.o \
			build/game/truncf.o build/game/unk_05C440.o build/game/bondview.o build/game/objecthandler.o \
			build/game/othermodemicrocode.o build/game/bond.o build/game/unk_08DBB0.o build/game/debugmenu_08FE00.o \
			build/game/unk_091080.o build/game/cheat_buttons_objectrelated.o build/game/unk_092890.o build/game/unk_092E50.o \
			build/game/unk_093880.o build/game/unk_09B600.o build/game/unk_09B740.o build/game/unk_09B7A0.o \
			build/game/unk_09C250.o build/game/unk_0A1DA0.o build/game/watch.o build/game/textrelated.o build/game/stan.o \
			build/game/unk_0B3200.o build/game/bg.o build/game/fog.o build/game/lightfixture.o build/game/unk_0BC530.o \
			build/game/ob.o build/game/dyn.o build/game/lvl.o build/game/unk_0C0A70.o build/game/mp_music.o \
			build/game/lvl_text.o build/game/mp_watch.o build/game/radar.o build/game/mp_weapon.o build/game/image.o \
			build/game/image_bank.o build/game/unk_0CC4C0.o build/game/decompress.o build/game/zlib.o build/game/rsp.o \
			build/game/indy_comms.o build/game/indy_0D0180.o build/game/game_debug.o build/game/compiletime.o \
			build/game/unk_0D1AC0.o build/game/viewport.o build/game/music_0D2720.o build/game/spectrum.o
GAMESEGMENT := gamesegment.o

RZFILES := rarezip/rarezip.c
RZOBJECTS := build/rarezip/rarezip.o
RZSEGMENT := rzsegment.o

#DATAFILES := static.c zbuffer.c cfb.c
#DATAOBJECTS := $(DATAFILES:.c=.o)

OBJECTS := $(BOOTSEGMENT) $(CODESEGMENT) $(GAMESEGMENT) $(RZSEGMENT) $(OBSEGMENT)

# other tools
TOOLS_DIR := tools
DATASEG_COMP := $(TOOLS_DIR)/data_compress.sh
RZ_COMP := $(TOOLS_DIR)/1172compress.sh
N64CKSUM := $(TOOLS_DIR)/n64cksum
MAKEBG := $(TOOLS_DIR)/makebg.sh

INCLUDE := -I include -I include/code -I include/game -I include/rarezip -I include/libultra

CC := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
CFLAGS := -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -fullwarn -wlint -woff 819,820,852,821 -signed $(INCLUDE) -mips2

LD := $(TOOLCHAIN)ld
LD_SCRIPT := $(TARGET).ld
LDFLAGS := -T $(LD_SCRIPT) -Map $(BUILD_DIR)/ge007.map

AS := $(TOOLCHAIN)as
ASFLAGS := -march=vr4300 -mabi=32 $(INCLUDE)
ASM_PREPROC := python3 tools/asmpreproc/asm-processor.py

OBJCOPY := $(TOOLCHAIN)objcopy

default:	$(TARGET)

clean:
	rm -f $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(BG_SEG_FILES) $(CHR_RZ_FILES) $(GUN_RZ_FILES) $(PROP_RZ_FILES) \
	$(STAN_RZ_FILES) $(BRIEF_RZ_FILES) $(SETUP_RZ_FILES) $(TEXT_RZ_FILES) \
	$(MUSIC_RZ_FILES)

install: default
		$(INSTALL) -m 444 -F /usr/src/PR/ge007 \
			README $(HFILES) $(BOOTFILES) $(CODEFILES) $(GAMEFILES) $(RZFILES) \
			Makefile 

build/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

build/%.o: src/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s

build/$(BOOTOBJECTS): src/$(BOOTFILES)
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s

build/$(OBSEGMENT): $(BG_SEG_FILES) $(CHR_RZ_FILES) $(GUN_RZ_FILES) $(PROP_RZ_FILES) $(STAN_RZ_FILES) $(BRIEF_RZ_FILES) $(SETUP_RZ_FILES) $(TEXT_RZ_FILES)
	
build/$(BOOTSEGMENT): $(BOOTOBJECTS)
	$(LD) -o build/$(BOOTSEGMENT) -r $(BOOTOBJECTS)
build/$(CODESEGMENT): $(CODEOBJECTS)
	$(LD) -o build/$(CODESEGMENT) -r $(CODEOBJECTS)
build/$(GAMESEGMENT): $(GAMEOBJECTS)
	$(LD) -o build/$(GAMESEGMENT) -r $(GAMEOBJECTS)
build/$(RZSEGMENT): $(RZOBJECTS)
	$(LD) -o build/$(RZSEGMENT) -r $(RZOBJECTS)

$(APP): $(ULTRAOBJECTS) $(HEADEROBJECTS) build/$(OBSEGMENT) $(MUSIC_RZ_FILES) build/$(BOOTSEGMENT) build/$(CODESEGMENT) build/$(GAMESEGMENT) build/$(RZSEGMENT)
	$(LD) $(LDFLAGS) -o $@ 

$(TARGETBIN): $(APP)
	$(OBJCOPY) $< $@ -O binary

$(TARGET):	$(TARGETBIN)
	$(DATASEG_COMP) $<
	$(N64CKSUM) $< $@





