# Makefile to rebuild Goldeneye 007
include assets/Makefile.obseg
include assets/Makefile.music

QEMU_IRIX := tools/irix/qemu-irix
IRIX_ROOT := tools/irix/root

FINAL := YES
VERSION := US
TOOLCHAIN := mips-linux-gnu-
COMPARE := 1

BUILD_DIR := build
BUILD_SUB_DIRS := \
	game rarezip libultra assets assets/obseg \
	assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop \
	assets/obseg/text assets/obseg/bg assets/obseg/setup assets/obseg/stan \
	assets/music assets/ramrom assets/images assets/font
# create build directories
$(shell mkdir -p $(BUILD_DIR))
$(foreach subdir,$(BUILD_SUB_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(subdir)))

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


APPELF := ge007.$(COUNTRYCODE).elf
APPROM := ge007.$(COUNTRYCODE).z64
APPBIN := ge007.$(COUNTRYCODE).bin

HFILES := $(foreach dir,$(CODE_DIRS),$(wildcard $(dir)/*.h))

HEADERFILES := rom_header.s bootcode.s _start.s rspboot.s gspboot.s aspboot.s
HEADEROBJECTS := build/rom_header.o build/bootcode.o build/_start.o build/rspboot.o build/gspboot.o build/aspboot.o


BOOTFILES := boot.c
BOOTOBJECTS := build/boot.o build/cfb.o
BOOTSEGMENT := bootsegment.o

CODEFILES := init.c sched.c osMapTLB.c tlb_manage.c tlb_random.c tlb_resolve.c tlb_hardware.c audi.c \
			   speed_graph.c video.c deb.c debug_stuff_split.c debug_getlastRA.c ramrom.c boss.c music.c \
			   sfx.c memp.c mema.c random.c token.c stringhandler.c sprintf.c pi.c vi.c \
			   debugmenu.c joy.c joy_rumble.c rmon.c c_data_filler.c
CODEOBJECTS := $(foreach file,$(CODEFILES),$(BUILD_DIR)/$(file:.c=.o))
CODESEGMENT := codesegment.o

LIBULTRA := lib/libultra_rom.a
ULTRAFILES := libultra/libultra.s
ULTRAOBJECTS := build/libultra/libultra.o


GAMEFILES := game/initgamedata.c game/initweaponanigroups.c game/initactorpropstuff.c game/initnull_0009D0.c \
			game/initunk_0009E0.c game/initanitable.c game/initunk_000B60.c game/setguscale.c game/initnull_000BC0.c \
			game/initimages.c game/initintromatrices.c game/initmenus.c game/initguards.c game/deb_loadallmodels.c \
			game/initobjects.c game/prop.c game/objective.c game/ejectedcartridges.c game/initBondDATA.c \
			game/initunk_005450.c game/initunk_005520.c game/initcameraandthrown.c game/inititemslots.c \
			game/initBondDATAdefaults.c game/initpathtablesomething.c game/initpathtablelinks.c game/initexplosioncasing.c \
			game/initunk_007180.c game/initunk_007290.c game/initunk_0072B0.c game/initmttex.c game/initunk_0073B0.c \
			game/initunk_007460.c game/cleanup_alarms.c game/cleanup_objects.c game/cleanup_objectives.c game/cleanupSFXRelated.c \
			game/playerstats_007770.c game/unk_007800.c game/unk_007920.c game/null_007970.c game/unk_007980.c \
			game/intro_logos.c game/mainmenu.c game/unk_01B0E0.c game/unk_01B240.c game/unk_01BAE0.c game/blood_animation.c \
			game/blood_decrypt.c game/eeprom.c game/actor.c game/actionblock.c game/loadobjectmodel.c game/objective_status.c \
			game/sin.c game/unk_057FD0.c game/unk_05A9E0.c game/convertangleusinginverse.c game/unk_05AB70.c game/unk_05ACB0.c \
			game/unk_05AE00.c game/unk_05B1E0.c game/truncf.c game/unk_05C440.c game/bondview.c game/objecthandler.c game/objecthandler_2.c \
			game/othermodemicrocode.c game/bond.c game/unk_08DBB0.c game/debugmenu_08FE00.c game/debugmenu_090490.c game/unk_091080.c \
			game/cheat_buttons_objectrelated.c game/unk_092890.c game/unk_092E50.c game/unk_093880.c game/unk_09B600.c game/unk_09B740.c \
			game/unk_09B7A0.c game/unk_09C250.c game/unk_0A1DA0.c game/watch.c game/textrelated.c game/stan.c game/unk_0B3200.c \
			game/bg.c game/fog.c game/lightfixture.c game/unk_0BC530.c game/ob.c game/dyn.c game/lvl.c game/lvl_2.c game/unk_0C0A70.c \
			game/mp_music.c game/lvl_text.c game/mp_watch.c game/radar.c game/mp_weapon.c game/image.c game/image_bank.c \
			game/unk_0CC4C0.c game/decompress.c game/zlib.c game/rsp.c game/indy_comms.c game/indy_0D0180.c game/game_debug.c \
			game/compiletime.c game/unk_0D1AC0.c game/viewport.c game/music_0D2720.c game/spectrum.c
GAMEOBJECTS := $(foreach file,$(GAMEFILES),$(BUILD_DIR)/$(file:.c=.o))
GAMESEGMENT := gamesegment.o

ROMFILES := assets/romfiles.s
ROMOBJECTS := build/assets/romfiles.o


RAMROM_FILES := assets/ramrom/ramrom.s
RAMROM_OBJECTS := build/assets/ramrom/ramrom.o

FONT_FILES := assets/font/font.s
FONT_OBJECTS := build/assets/font/font.o

MUSIC_FILES := assets/music/music.s
MUSIC_OBJECTS := build/assets/music/music.o

OBSEG_FILES := assets/obseg/ob_seg.s
OBSEG_OBJECTS := build/assets/obseg/ob_seg.o

IMAGES_FILES := assets/images/images.s
IMAGES_OBJECTS := build/assets/images/images.o

RZFILES := rarezip/rarezip.c
RZOBJECTS := build/rarezip/rarezip.o
RZSEGMENT := rzsegment.o

#DATAFILES := static.c zbuffer.c cfb.c
#DATAOBJECTS := $(DATAFILES:.c=.o)

OBJECTS := $(BOOTSEGMENT) $(CODESEGMENT) $(GAMESEGMENT) $(RZSEGMENT) $(OBSEGMENT) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGES_OBJECTS)

# other tools
TOOLS_DIR := tools
DATASEG_COMP := $(TOOLS_DIR)/data_compress.sh
RZ_COMP := $(TOOLS_DIR)/1172compress.sh
N64CKSUM := $(TOOLS_DIR)/n64cksum
MAKEBG := $(TOOLS_DIR)/makebg.sh
SHA1SUM = sha1sum

INCLUDE := -I . -I include -I include/libultra -I src -I src/game -I src/rarezip

CC := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
CFLAGS := -Wo,-loopunroll,0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -fullwarn -wlint -woff 819,820,852,821 -signed $(INCLUDE) -mips2

LD := $(TOOLCHAIN)ld
LD_SCRIPT := ge007.$(COUNTRYCODE).ld
LDFLAGS := -T undefined_syms.txt -T $(LD_SCRIPT) -Map $(BUILD_DIR)/ge007.$(COUNTRYCODE).map

AS := $(TOOLCHAIN)as
ASFLAGS := -march=vr4300 -mabi=32 $(INCLUDE)
ASM_PREPROC := python3 tools/asmpreproc/asm-processor.py

OBJCOPY := $(TOOLCHAIN)objcopy

all: $(APPROM)
ifeq ($(COMPARE),1)
	@$(SHA1SUM) -c ge007.$(COUNTRYCODE).sha1
endif

default:	$(APPROM)

codeclean:
	rm -f $(BUILD_DIR)/ge007.$(COUNTRYCODE).map $(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS)
	git checkout build/assets/obseg/setup/UsetuparchZ.rz
	git checkout build/assets/obseg/setup/UsetupjunZ.rz
	git checkout build/assets/obseg/setup/UsetupsevbZ.rz
	git checkout build/assets/obseg/text/LcradE.rz

dataclean: 
	rm -f $(BUILD_DIR)/ge007.$(COUNTRYCODE).map \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGES_OBJECTS) $(MUSIC_RZ_FILES)
	git checkout build/assets/obseg/setup/UsetuparchZ.rz
	git checkout build/assets/obseg/setup/UsetupjunZ.rz
	git checkout build/assets/obseg/setup/UsetupsevbZ.rz
	git checkout build/assets/obseg/text/LcradE.rz

clean:
	rm -f $(BUILD_DIR)/ge007.$(COUNTRYCODE).map $(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(IMAGES_OBJECTS) $(MUSIC_RZ_FILES
	git checkout build/assets/obseg/setup/UsetuparchZ.rz
	git checkout build/assets/obseg/setup/UsetupjunZ.rz
	git checkout build/assets/obseg/setup/UsetupsevbZ.rz
	git checkout build/assets/obseg/text/LcradE.rz

build/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<

build/assets/%.o: assets/%.s
	$(AS) $(ASFLAGS) -o $@ $<

build/assets/ramrom/%.o: assets/ramrom/%.s
	$(AS) $(ASFLAGS) -o $@ $<

build/assets/font/%.o: assets/font/%.s
	$(AS) $(ASFLAGS) -o $@ $<

build/assets/obseg/%.o: assets/obseg/%.s
	$(AS) $(ASFLAGS) -o $@ $<

build/assets/images/%.o: assets/images/%.s
	$(AS) $(ASFLAGS) -o $@ $<

build/%.o: src/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s

build/$(OBSEGMENT): $(OBSEG_RZ) $(IMAGES_OBJECTS)
	

$(APPELF): $(ULTRAOBJECTS) $(HEADEROBJECTS) build/$(OBSEGMENT) $(MUSIC_RZ_FILES) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONT_OBJECTS) $(MUSIC_OBJECTS) $(OBSEG_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ 

$(APPBIN): $(APPELF)
	$(OBJCOPY) $< $@ -O binary --gap-fill=0xff
	
$(APPROM):	$(APPBIN)
	$(DATASEG_COMP) $<
	$(N64CKSUM) $< $@

.PHONY: all default codeclean dataclean clean



