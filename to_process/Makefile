# Makefile to rebuild Goldeneye 007 split image
# Modified from sm64tools generated buildfile

# BUILD_DIR is location where all build artifacts are placed
BUILD_DIR := build

# Directories containing source files
SRC_DIRS := src src/libultra
ASM_DIRS := asm asm/code asm/game asm/rarezip asm/libultra

# If COMPARE is 1, check the output sha1sum when building 'all'
COMPARE = 1

# source code
C_FILES       := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES       := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))

#Objects
O_FILES       := $(foreach f,$(S_FILES:.s=.o),build/$f) \
                 $(foreach f,$(C_FILES:.c=.o),build/$f) \
                 $(foreach f,$(BASEROM_FILES),build/$f.o)



















#### Tools ####
AS         := $(MIPS_BINUTILS_PREFIX)as
LD         := $(MIPS_BINUTILS_PREFIX)ld
OBJCOPY    := $(MIPS_BINUTILS_PREFIX)objcopy
OBJDUMP    := $(MIPS_BINUTILS_PREFIX)objdump
CC         := $(QEMU_IRIX) -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
CPP        := cpp
MKLDSCRIPT := tools/mkldscript
ELF2ROM    := tools/elf2rom
MONO       := mono

OPTIMIZATION := -O2
ASFLAGS := -march=vr4300 -32 -I include
CFLAGS  := -mips2 -G 0 -non_shared -Xfullwarn -Xcpluscomm -I include

# ROM image
ROM := goldeneye007.u.z64
ELF := $(ROM:.z64=.elf)
# description of ROM segments
SPEC := spec

# baserom files
include baserom_files.mk




# create build directories
$(shell mkdir -p build/baserom)
$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(TEXTURE_DIRS),$(shell mkdir -p build/$(dir)))

build/src/libultra/%.o: OPTIMIZATION := -O1


#### Main Targets ###

compare: $(ROM)
	@md5sum -c checksum.md5

$(ROM): $(ELF)
	$(ELF2ROM) -cic 6102 $< $@

$(ELF): $(O_FILES) ./ge007.u.ld
	$(LD) -T undefined_syms.txt -T ./ge007.u.ld --no-check-sections --accept-unknown-input-arch -o $@

build/ldscript.txt: $(SPEC)
	$(CPP) -P $< > build/spec
	$(MKLDSCRIPT) build/spec $@

clean:
	$(RM) $(ROM) $(ELF) -r build


#### Various Recipes ####

build/baserom/%.o: baserom/%
	$(OBJCOPY) -I binary -O elf32-big $< $@

build/asm/%.o: asm/%.s
	$(AS) $(ASFLAGS) $^ -o $@

build/src/%.o: src/%.c
	$(CC) -c $(CFLAGS) $(OPTIMIZATION) $^ -o $@

build/textures/%.o: textures/%.zdata
	$(OBJCOPY) -I binary -O elf32-big $< $@

textures/%.zdata: textures/%
	$(MONO) $(ZAP) $<.xml b