# Makefile to rebuild Goldeneye 007

### Default target ###
default: all

#(call DrawProgressBar,Percent)
# OR
#(call DrawProgressBar,NumberOfItemsDone,TotalNumberOfItems)
# If second param is given, use it to work out a percentage.
# divide the percentage into a 80 char long bar
# paint the whole bar grey
# paint the first half, then text, then second half.
# clear colour codes
DrawProgressBar =                                       \
	{                                                   \
		$(if $(2),                                      \
			if [ "$(1)" -ne "$(2)" ];                   \
			then                                        \
				_pdone=`expr 100 / $(2) \* $(1)`;       \
			else                                        \
				_pdone=100;                             \
			fi                                          \
			,_pdone=$(1)                                \
		);                                              \
		                                                \
		pdone=`expr $$_pdone \* 76 / 100`;              \
		pdoneb=0;                                       \
		printf "\033[1;97;100m%80s\r\033[1;44m" " ";    \
		if [ "$$pdone" -lt "40" ];                      \
		then                                            \
			printf "%$${pdone}s";                       \
			printf "\033[100m";                         \
			pdoneb=`expr 38 - $$pdone`;                 \
			printf "%$${pdoneb}s%3d%% \r" "" $$_pdone;  \
		else                                            \
			pdoneb=`expr $$pdone - 38`;                 \
			printf "%38s%3d%%%$${pdoneb}s" "" $$_pdone; \
			printf "\r";                                \
		fi;                                             \
		printf "\033[0m";                               \
	}                                                   \

OrigDrawProgressBar =\
	{\
		pbar="[";\
		$(if $(2), if [ "$(1)" -ne "$(2)" ]; then percent=`expr 100 / $(2) `; _pdone=`expr $$percent \* $(1)`; else _pdone=100; fi ,_pdone=$(1));\
		pdone=`expr $$_pdone / 4`;\
		for i in $$(seq 0 $$pdone);\
		do \
			pbar="$${pbar}=";\
		done;\
		for i in $$(seq $$pdone 24);\
		do \
			pbar="$$pbar ";\
		done;\
		printf "$$pbar]%3d%%\r" "" "$$_pdone";\
	}


### Build Options ###
# Version of the game to build
FINAL := YES
VERSION := US
IDO_RECOMP := NO
VERBOSE := 0
# If COMPARE is 1, check the output sha1sum when building 'all'
COMPARE := 1

ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  TOOLCHAIN := mips-linux-gnu-
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  TOOLCHAIN := mips64-linux-gnu-
else
  TOOLCHAIN := mips64-elf-
endif

ifeq ($(IDO_RECOMP), NO)
  QEMU_IRIX := $(shell which qemu-irix 2>/dev/null)
  ifeq (, $(QEMU_IRIX))
    $(error Using the IDO compiler requires qemu-irix. Please install qemu-irix package or set the QEMU_IRIX environment variable to the full qemu-irix binary path)
  endif
  IRIX_ROOT := tools/irix/root
else
  IRIX_ROOT := tools/ido5.3_recomp
endif
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
 OUTCODE := $(COUNTRYCODE)
 LCDEFS := -DVERSION_US -DLANG_US -DREFRESH_NTSC -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM -DBUGFIX_R0
 ASMDEFS := --defsym VERSION_US=1 --defsym LANG_US=1 --defsym REFRESH_NTSC=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1 --defsym BUGFIX_R0=1
endif

ifeq ($(VERSION), EU)
 COUNTRYCODE := e
 OUTCODE := $(COUNTRYCODE)
 LCDEFS := -DVERSION_EU -DLANG_EU -DREFRESH_PAL -DBUGFIX_R1 -DBUGFIX_R2 
 ASMDEFS := --defsym VERSION_EU=1 --defsym LANG_EU=1 --defsym REFRESH_PAL=1 --defsym BUGFIX_R1=1 --defsym BUGFIX_R2=1
endif

ifeq ($(VERSION), JP)
 COUNTRYCODE := j
 OUTCODE := $(COUNTRYCODE)
 LCDEFS := -DVERSION_JP -DLANG_JP -DREFRESH_NTSC -DBUGFIX_R1 -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM
 ASMDEFS := --defsym VERSION_JP=1 --defsym LANG_JP=1 --defsym REFRESH_NTSC=1 --defsym BUGFIX_R1=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1
endif

ifeq ($(VERSION), DEBUG)
 COUNTRYCODE := u
 OUTCODE := d
 LCDEFS := -DVERSION_US -DLANG_US -DREFRESH_NTSC -DLEFTOVERDEBUG -DLEFTOVERSPECTRUM -DBUGFIX_R0 -DDEBUGMENU
 ASMDEFS := --defsym VERSION_DEBUG=1 --defsym LANG_US=1 --defsym REFRESH_NTSC=1 --defsym LEFTOVERDEBUG=1 --defsym LEFTOVERSPECTRUM=1 --defsym BUGFIX_R0=1 --defsym DEBUGMENU=1
 COMPARE := 0
endif

ALLOWED_VERSIONS := US EU JP DEBUG
ifneq ($(filter $(VERSION),$(ALLOWED_VERSIONS)),)
 $(info VERSION=$(VERSION))
else
 $(error VERSION "$(VERSION)" not supported")
endif

BUILD_DIR_BASE := build
# BUILD_DIR is the location where all build artifacts are placed
BUILD_DIR      := $(BUILD_DIR_BASE)/$(OUTCODE)
include assets/Makefile.obseg
include assets/Makefile.music
BUILD_SUB_DIRS := \
	rsp src src/game src/inflate \
	src/libultra src/libultra/audio src/libultra/gt src/libultra/gu src/libultra/io \
	src/libultra/libc src/libultra/os src/libultra/rg src/libultra/sched src/libultra/sp \
	src/libultrare src/libultrare/audio src/libultrare/gt src/libultrare/gu src/libultrare/io \
	src/libultrare/libc src/libultrare/os src/libultrare/rg src/libultrare/sched src/libultrare/sp \
	assets assets/obseg \
	assets/obseg/brief assets/obseg/chr assets/obseg/gun assets/obseg/prop \
	assets/obseg/text assets/obseg/bg assets/obseg/setup assets/obseg/setup/$(COUNTRYCODE) assets/obseg/stan \
	assets/music assets/ramrom assets/images assets/images/split assets/font \
	assets/embedded assets/embedded/skeletons assets/embedded/player_gait_object
# create build directories
$(shell mkdir -p $(BUILD_DIR))
$(foreach subdir,$(BUILD_SUB_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(subdir)))

APPELF := $(BUILD_DIR)/ge007.$(OUTCODE).elf
APPROM := $(BUILD_DIR)/ge007.$(OUTCODE).z64
APPBIN := $(BUILD_DIR)/ge007.$(OUTCODE).bin

HEADERFILES := $(foreach dir,src,$(wildcard $(dir)/*.s))
HEADEROBJECTS := $(foreach file,$(HEADERFILES),$(BUILD_DIR)/$(file:.s=.o))

RSPCODE := $(foreach dir,rsp,$(wildcard $(dir)/*.s))
RSPOBJECTS := $(foreach file,$(RSPCODE),$(BUILD_DIR)/$(file:.s=.bin))

CODEFILES := $(foreach dir,src,$(wildcard $(dir)/*.c))
CODEOBJECTS := $(foreach file,$(CODEFILES),$(BUILD_DIR)/$(file:.c=.o))

GAMEFILES_C := $(foreach dir,src/game,$(wildcard $(dir)/*.c))
GAMEFILES_S := $(foreach dir,src/game,$(wildcard $(dir)/*.s))
GAMEOBJECTS := $(foreach file,$(GAMEFILES_S),$(BUILD_DIR)/$(file:.s=.o)) \
				$(foreach file,$(GAMEFILES_C),$(BUILD_DIR)/$(file:.c=.o))


ASSET_DATAFILES := assets/GlobalImageTable.c assets/animationtable_data.c assets/animationtable_entries.c assets/font_dl.c assets/font_chardataj.c assets/font_chardatae.c assets/Globalimagetable_commandblock.c
ASSET_DATAOBJECTS := $(foreach file,$(ASSET_DATAFILES),$(BUILD_DIR)/$(file:.c=.o))

ROMFILES2 := assets/romfiles2.s
ROMOBJECTS2 := $(BUILD_DIR)/assets/romfiles2.o

RAMROM_FILES := assets/ramrom/ramrom.s
RAMROM_OBJECTS := $(BUILD_DIR)/assets/ramrom/ramrom.o


FONTFILES_C := $(foreach dir,assets/font,$(wildcard $(dir)/*.c))
FONTOBJECTS := $(foreach file,$(FONTFILES_C),$(BUILD_DIR)/$(file:.c=.o))


MUSIC_FILES := $(foreach dir,assets/music,$(wildcard $(dir)/*.s))
MUSIC_OBJECTS := $(foreach file,$(MUSIC_FILES),$(BUILD_DIR)/$(file:.s=.o))

OBSEG_FILES := assets/obseg/ob_seg.s
OBSEG_OBJECTS := $(BUILD_DIR)/assets/obseg/ob_seg.o
OBSEG_RZ := $(BG_SEG_FILES) $(CHR_RZ_FILES) $(GUN_RZ_FILES) $(PROP_RZ_FILES) $(STAN_RZ_FILES) $(BRIEF_RZ_FILES) $(SETUP_RZ_FILES) $(TEXT_RZ_FILES)

IMAGE_BINS := $(foreach dir,assets/images/split,$(wildcard $(dir)/*.bin))
IMAGE_OBJS := $(foreach file,$(IMAGE_BINS),$(BUILD_DIR)/$(file:.bin=.o))

RZFILES := inflate/inflate.c
RZOBJECTS := $(foreach file,$(RZFILES),$(BUILD_DIR)/src/$(file:.c=.o))

OBJECTS := $(RSPOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(OBSEGMENT) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS)

MIPSISET := -mips2 -32

INCLUDE := -I . -I include -I include/ultra64 -I include/PR -I src -I src/game -I src/inflate
# ignore warnings:
# 609 : The number of arguments in the macro invocation does not match the definition - disabled because CPPLib uses "VarArgs" which wasnt invented till c99
# 649 : Missing member name in structure / union                                      - used for "Inheritance"
# 709 : Incompatible pointer type assignment                                          - could be fixed by casting, but implicit is fine.
# 712 : illegal combination of pointer and integer                                    - could be fixed by casting, but implicit is fine.
# 807 : member cannot be of function or incomplete type                               - Variable length structs
# 838 : Microsoft extension (unnamed structs)                                         - used for "Inheritance" and member/array call swapping
WOFF :=  -woff 609,649,709,712,807,838

ifeq ($(IDO_RECOMP), NO)
  CC := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
else
  CC := $(IRIX_ROOT)/cc
endif

CFLAGS := -Wab,-r4300_mul -non_shared -Olimit 2000 -G 0 -Xcpluscomm $(CFLAGWARNING) $(WOFF) -signed $(INCLUDE) $(MIPSISET) $(LCDEFS) -DTARGET_N64

LD := $(TOOLCHAIN)ld
LD_SCRIPT := ge007.$(OUTCODE).ld

# --no-warn-mismatch is needed to link -mips3 object files (some libultra math) with the regular files compiled with -mips2
LDFLAGS := -T undefined_syms.txt -T $(LD_SCRIPT) -Map build/ge007.$(OUTCODE).map --no-warn-mismatch

AS := $(TOOLCHAIN)as
ASFLAGS := -march=vr4300 -mabi=32 $(INCLUDE) $(ASMDEFS)
ARMIPS	:= $(TOOLS_DIR)/armips
ASM_PREPROC := python3 tools/asmpreproc/asm-processor.py

OBJCOPY := $(TOOLCHAIN)objcopy

all: $(APPROM)
ifeq ($(COMPARE),1)
	@echo "\n"
#Now using cursor commands for better look  original was //"\033[5;42;97m%80s\r\n%43s%37s\r\n%80s\007\033[0;0m\n"
#                                      if fail          Rsrv   Up 3   Flash  Wht  80  Dn 1 Return      Dn 1 Ret 80ch                  Red                                                                              Reset Colour
#   Calculate Checksum                 Else complete    Lines Lines     Red/Grn   ch  Line SoL midway  Line SoL     Bell Reset Colour                                          Which File failed
	@$(SHA1SUM) -c ge007.$(OUTCODE).sha1 || (printf "\n\n\033[3A\033[5;41;97m%80s\033[1B\r%45s%35s\033[1B\r%80s\007\033[0;0m\033[91m\n\n\n" "" "NOT MATCH!" "" "" && $(SHA1SUM) --quiet -c checksums.txt && printf "\033[0;0m")
	@printf                                           "\n\n\n\033[3A\033[5;42;97m%80s\033[1B\r%43s%37s\033[1B\r%80s\007\033[0;0m\n\n\n" "" "MATCH!" "" "" 
endif
	@echo "\n Rom File Generated in Build Directory. \n\n"

.SECONDARY:
	$(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES) 

ifeq ($(filter clean dataclean codeclean cmdbuilder test stanclean setupclean print-%,$(MAKECMDGOALS)),)
  # Make tools if out of date
  $(info Building tools...)
  DUMMY != make -s -C tools >&2 || echo FAIL
    ifeq ($(DUMMY),FAIL)
      $(error Failed to build tools)
    endif
  $(info Building ROM...)
endif

# this file references variables defined above: BUILD_DIR, CFLAGWARNING, INCLUDE, LCDEFS
# this file defines $(ULTRAOBJECTS)
include src/libultrare/Makefile.libultrare

setupclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(SETUP_BUILD_FILES)

stanclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(STAN_BUILD_FILES)

libultraclean:
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(ULTRAOBJECTS)


codeclean:
ifeq ($(VERBOSE),1)
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(RSPOBJECTS)
else
	@clear
	@echo Deleting All Code Binaries Only (Assets will be left from previous compile)
	@rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map
	@$(call DrawProgressBar,50)
	@rm -f $(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(RSPOBJECTS)
	@$(call DrawProgressBar,100)
endif
	@echo "\n\n Code Binaries Cleared! Make will Re-Build these next time.\n"

dataclean: 
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES) \
	$(STAN_BUILD_FILES) $(SETUP_BUILD_FILES)

clean:
ifeq ($(VERBOSE),1)
	rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map \
	$(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) \
	$(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(IMAGE_OBJS) $(MUSIC_RZ_FILES) $(RSPOBJECTS) \
	$(STAN_BUILD_FILES) $(SETUP_BUILD_FILES)
else
	@clear
	@echo Deleting All Code and Asset Binaries
	@$(call DrawProgressBar,0)
	@rm -f $(APPELF) $(APPROM) $(APPBIN) $(ULTRAOBJECTS) $(BUILD_DIR)/ge007.$(OUTCODE).map
	@$(call DrawProgressBar,1,4)
	@rm -f $(HEADEROBJECTS) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS)
	@$(call DrawProgressBar,2,4)
	@rm -f $(OBSEG_OBJECTS) $(OBSEG_RZ) $(ROMOBJECTS) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS)
	@$(call DrawProgressBar,3,4)
	@rm -f $(IMAGE_OBJS) $(MUSIC_RZ_FILES) $(RSPOBJECTS) $(STAN_BUILD_FILES) $(SETUP_BUILD_FILES)
	@$(call DrawProgressBar,100)
endif
	@echo "\n\n All Code and Asset Binaries Cleared! Make will Re-Build these next time.\n"


$(BUILD_DIR)/rsp/%.bin: rsp/*.s
	$(ARMIPS) -sym $@.sym -strequ CODE_FILE $(BUILD_DIR)/rsp/$*.bin -strequ DATA_FILE $(BUILD_DIR)/rsp/$*_data.bin $<
# @$(call DrawProgressBar,1,15)

$(BUILD_DIR)/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<
# @$(call DrawProgressBar,2,15)

$(BUILD_DIR)/src/%.o: src/%.s
	$(AS) $(ASFLAGS) -o $@ $<
# @$(call DrawProgressBar,3,15)

$(BUILD_DIR)/assets/%.o: assets/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s
# @$(call DrawProgressBar,4,15)

$(BUILD_DIR)/assets/%.o: assets/%.s
	$(AS) $(ASFLAGS) -o $@ $<
# @$(call DrawProgressBar,5,15)

$(BUILD_DIR)/src/rspboot.o: $(BUILD_DIR)/rsp/rspboot.bin 
# @$(call DrawProgressBar,6,15)

$(BUILD_DIR)/assets/ramrom/%.o: assets/ramrom/%.s
	$(AS) $(ASFLAGS) -o $@ $<
# @$(call DrawProgressBar,7,15)

$(BUILD_DIR)/assets/font/%.o: assets/font/%.c
	$(CC) -c $(CFLAGS) -o $@ $(OPTIMIZATION) $<
# @$(call DrawProgressBar,8,15)

$(BUILD_DIR)/assets/obseg/%.o: assets/obseg/%.s $(OBSEG_RZ)
	$(AS) $(ASFLAGS) -o $@ $<
# @$(call DrawProgressBar,9,15)

$(BUILD_DIR)/assets/images/split/%.o: assets/images/split/%.bin
	$(LD) -r -b binary $< -o $@
#	@printf "\033[40B\r"
#	@$(call DrawProgressBar,10,15)
#	@printf "\033[40A\r"

#$(BUILD_DIR)/src/random.o: OPTIMIZATION := -O3
#$(BUILD_DIR)/src/random.o: INCLUDE := -I . -I include -I include/PR
#$(BUILD_DIR)/src/random.o: MIPSISET := -mips3 -o32
#$(BUILD_DIR)/src/random.o: src/random.c
#	$(CC) -c -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm $(CFLAGWARNING) -woff 819,820,852,821,838,649 -signed $(INCLUDE) $(MIPSISET) $(LCDEFS) -DTARGET_N64 $(OPTIMIZATION) -o $@ $<

$(BUILD_DIR)/%.o: src/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s
# @$(call DrawProgressBar,11,15)

$(BUILD_DIR)/src/%.o: src/%.c
	$(ASM_PREPROC) $(OPTIMIZATION) $< | $(CC) -c $(CFLAGS) tools/asmpreproc/include-stdin.c -o $@ $(OPTIMIZATION)
	$(ASM_PREPROC) $(OPTIMIZATION) $< --post-process $@ --assembler "$(AS) $(ASFLAGS)" --asm-prelude tools/asmpreproc/prelude.s
# @$(call DrawProgressBar,12,15)

$(BUILD_DIR)/$(OBSEGMENT): $(OBSEG_RZ) $(IMAGE_OBJS)
# @$(call DrawProgressBar,13,15)
	

$(APPELF): $(RSPOBJECTS) $(ULTRAOBJECTS) $(HEADEROBJECTS) $(OBSEG_RZ) $(BUILD_DIR)/$(OBSEGMENT) $(MUSIC_RZ_FILES) $(BOOTOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) $(RZOBJECTS) $(ROMOBJECTS) $(ASSET_DATAOBJECTS) $(ROMOBJECTS2) $(RAMROM_OBJECTS) $(FONTOBJECTS) $(MUSIC_OBJECTS) $(OBSEG_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ 

$(APPBIN): $(APPELF)
	$(OBJCOPY) $< $@ -O binary --gap-fill=0xff
	
$(APPROM):	$(APPBIN)
	$(DATASEG_COMP) $< $(OUTCODE)
	$(N64CKSUM) $< $@
	rm header.tmp

.PRECIOUS: %.bin  %.o

.PHONY: all default codeclean dataclean clean cmdbuidler test

#CMD Builder tools
AI_CMD_BUILDER := $(TOOLS_DIR)/cmdbuilder.c
AI_CMD_LIST_DEFINITIONS := src/aicommands.def
AI_CMD_LIST_TEMP := $(BUILD_DIR)/aicommands.temp
AI_CMD_LIST_H2 := src/aicommands2.h
#Format Newlines and Comment tags
AI_CMD_BUILDER_CONVERT := sed -E
AI_CMD_BUILDER_CONVERT += -e 's/\\n/\n/g;' #                add newlines
AI_CMD_BUILDER_CONVERT += -e 's/\?{2}\=/\#/g;' #            replace ??= with hash for defines
AI_CMD_BUILDER_CONVERT += -e 's/\?{2}\\/\//g;' #            replace ??\ with /
AI_CMD_BUILDER_CONVERT += -e 's/\\.*/\\/g;' #               replace \... with \ (line continuation)
AI_CMD_BUILDER_CONVERT += -e 's/\*\(\*/\*/g;' #             replace *(* with *
AI_CMD_BUILDER_CONVERT += -e 's/\*\)\*/\*/g;' #             replace *)* with *
AI_CMD_BUILDER_CONVERT += -e 's/MAKE_EXPAND\(([^\n]*)MAKE_EXPAND_END\)/\1/g;' #replace MAKE_EXPAND(CONTENTS) with CONTENTS
AI_CMD_BUILDER_CONVERT += -e 's/\?{2}x27/\x27/g;' #         replace ??x27 with '
AI_CMD_BUILDER_CONVERT += -e 's/\x27\/n\x27/\x27\\n\x27/g;' # replace '/n' with '\n'
AI_CMD_BUILDER_CONVERT += -e '/^ *$$/d'
#Pre-Format encoding newlines and tags
AI_CMD_BUILDER_PRECONVERT := sed -E
AI_CMD_BUILDER_PRECONVERT += -e 's/\x27\\n\x27/\x27\/n\x27/g;' #                encode '\n' as '/n'
AI_CMD_BUILDER_PRECONVERT += -e '/^\s*\*/ s/\x27/\?\?x27/g;' #                  encode DocBlock(/**...**/) quotes
#AI_CMD_BUILDER_PRECONVERT += -e 's/[^/]\*\n/\\BOO\\/g;' #      encode DocBlock newlines as \n\ 
AI_CMD_BUILDER_PRECONVERT += -e 's/[^/]\*$$/\\n\\/g; s/^(\s*)\*[^/]/\1 /g;' #   remove DocBlock sides (causes problems with tooltips) fixed to check for ordinary comment
AI_CMD_BUILDER_PRECONVERT += -e '/^_AI_CMD_POLYMORPH\(CMDNAME,\n(.|\n)*?\s{19}DESCRIPTION(\)| DESCRIPTION2\))/ s/[^,]\n/\\n\\/g;' #      Newlines in POLYMORPHS 
AI_CMD_BUILDER_PRECONVERT += -e 's/\/\*\*/\?\?\\\*\(\*\*/g;' #                  encode /** as ??\*(**
AI_CMD_BUILDER_PRECONVERT += -e 's/\*\*\//\*\*\)\*\?\?\\ /g;' #                 encode **/ as **)*??\ 
#AI_CMD_BUILDER_PRECONVERT += -e 's/asterix! --> \*\//asterix! --> \x27\//g;' # Comment Syntax Highlighter - Dont need this now

AI_CMD_LIST_H2_HEADER := \
"/******************************************************************************\n\
*                                                                            *\n\
*                                                                            *\n\
*  Do not edit this file.  It was automatically generated by \"cmdbuilder\"    *\n\
*  from the file \"$(AI_CMD_LIST_DEFINITIONS)\".                                       *\n\
*  To Add/Remove/Modify AI Commands please edit \"$(AI_CMD_LIST_DEFINITIONS)\"         *\n\
*  and then run                                                              *\n\
*     make cmdbuilder                                                        *\n\
*                                                                            *\n\
*                                                                            *\n\
*****************************************************************************/\n\n"


cmdbuilder:
	@clear
	@echo
	@echo Building AI Command Macros...
	@echo
	@$(call DrawProgressBar,0,6)
	@ # copy command definitions to temp
	@cp $(AI_CMD_LIST_DEFINITIONS) $(AI_CMD_LIST_TEMP)
	@$(call DrawProgressBar,1,6)
	@ # Preformat Definitions for builder (encode documentation tags)
	@$(AI_CMD_BUILDER_PRECONVERT) $(AI_CMD_LIST_TEMP) > $(AI_CMD_LIST_DEFINITIONS)
	@$(call DrawProgressBar,2,6)
	@ # Print Header
	@echo $(AI_CMD_LIST_H2_HEADER) > $(AI_CMD_LIST_H2)
	@$(call DrawProgressBar,3,6)
	@ # Execute Builder and format (re-add newlines, documentation tags etc) -C keeps /**/ comments
	@$(CC) -Xcpluscomm -c $(AI_CMD_BUILDER) $(INCLUDE) -w 581 -E | $(AI_CMD_BUILDER_CONVERT) >> $(AI_CMD_LIST_H2)
	@$(call DrawProgressBar,4,6)
	@ # restore command def from temp (no encoding)
	@cp $(AI_CMD_LIST_TEMP) $(AI_CMD_LIST_DEFINITIONS)
	@$(call DrawProgressBar,5,6)
	@rm $(AI_CMD_LIST_TEMP)
	@$(call DrawProgressBar,100)
	@echo
	@printf "%32s\n" "Done!"
	@echo
	@echo Rebuild AI Command Macros whenever changing aicommands.def.
	@echo

test:
	@$(SHA1SUM) --quiet -c checksums.txt
	@printf "\033[1;92m All Checked Files Match\033[0m\n\n"
#	@$(SHA1SUM) $(BG_SEG_FILES) $(BRIEF_RZ_FILES) $(CHR_RZ_FILES) $(GUN_RZ_FILES) \
	$(PROP_RZ_FILES) $(SETUP_BIN_FILES) $(STAN_RZ_FILES) $(TEXT_RZ_FILES) \
	$(ULTRAOBJECTS) $(CODEOBJECTS) $(GAMEOBJECTS) > checksums.txt

