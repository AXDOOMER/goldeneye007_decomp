# Image Build System

## Overview

The image build system uses `assets/images.def` as the **ground truth** for all texture images in GoldenEye. The system automatically:
- Generates image ordering and offsets from images.def
- Calculates sizes from actual .bin files
- Supports adding new images by simply editing images.def
- Auto-updates size mismatches between .def and actual files

## Key Files

- **`assets/images.def`** - Ground truth defining all images, their order, and properties
  - Format: `IMAGE(NAME, SIZE, HIT_SOUND, HIT_TYPE, F3, F4, F5, F6)`
  - Order in this file determines position in combined binary
  - SIZE field is auto-updated if it doesn't match actual file size

- **`assets/images/split/*.bin`** - Individual texture files
  - Named using IMAGE_ enum name (e.g., `COPYICON.bin`)
  - Must match names in images.def

- **`build/u/imagelist.csv`** - Generated file mapping offsets/sizes/paths
  - Auto-generated from images.def
  - Format: `offset,size,path,0,1`

## Scripts

### `scripts/make/generate_imagelist.py`

Primary script that generates the imagelist from images.def.

**Features:**
- Reads images.def to get image names and order
- Calculates offsets based on cumulative sizes
- Gets actual sizes from .bin files
- Auto-updates images.def if sizes don't match
- Warns about missing files

**Usage:**
```bash
python3 scripts/make/generate_imagelist.py build/u/imagelist.csv
```

### `scripts/make/combine_images_named.sh`

Combines individual .bin files into single combined.bin.

**Features:**
- Reads imagelist.csv for correct ordering
- Concatenates files in exact order
- Warns about missing files (skips them)

**Usage:**
```bash
scripts/make/combine_images_named.sh build/u/imagelist.csv assets/images/combined
```

## Makefile Integration

```makefile
# Generate imagelist from images.def (ground truth) and actual image files
$(BUILD_DIR)/imagelist.csv: assets/images.def
	@mkdir -p $(BUILD_DIR)
	python3 scripts/make/generate_imagelist.py $@

assets/images/combined/combined.bin: $(BUILD_DIR)/imagelist.csv
	scripts/make/combine_images_named.sh $(BUILD_DIR)/imagelist.csv assets/images/combined
```

**Dependency Chain:**
1. `assets/images.def` (ground truth) + actual .bin files
2. → `build/u/imagelist.csv` (generated)
3. → `assets/images/combined/combined.bin` (final combined texture)

## Workflow

### Adding a New Image

1. Create the .bin file:
   ```bash
   cp my_texture.bin assets/images/split/MY_NEW_TEXTURE.bin
   ```

2. Add entry to `assets/images.def` at desired position:
   ```c
   IMAGE(MY_NEW_TEXTURE, 0x1000, HIT_DEFAULT, HIT_DEFAULT, 0, 0, 0, 0)
   ```
   - SIZE (0x1000) will be auto-updated if it doesn't match actual file size
   - Position in file determines position in combined binary

3. Rebuild:
   ```bash
   make assets/images/combined/combined.bin
   ```

The system will automatically:
- Generate the imagelist with correct offsets
- Update SIZE in images.def if needed
- Combine all images in the correct order

### Updating an Existing Image

1. Replace the .bin file:
   ```bash
   cp new_version.bin assets/images/split/COPYICON.bin
   ```

2. Rebuild:
   ```bash
   make assets/images/combined/combined.bin
   ```

If the size changed, images.def will be auto-updated.

### Checking for Issues

The generate_imagelist.py script will report:
- Missing .bin files (warns but continues)
- Size mismatches (auto-updates images.def)
- Total combined size

## Key Differences from Old System

**Old System:**
- Relied on `imagelist.u.csv` as intermediate ground truth
- Required manual coordination between multiple files
- Sizes had to be manually updated with update_image_sizes.py
- Numbered images (image0.bin, image1.bin)

**New System:**
- `images.def` is the single ground truth
- No dependency on imagelist.u.csv
- Sizes auto-updated on every build
- Named images (COPYICON.bin, DELICON.bin)
- Easy to add new images - just edit images.def

## C Code Integration

The `images.def` file is included in C code to generate:

1. **Image ID enum** (`src/bondconstants.h`):
   ```c
   #define IMAGE(NAME, SZ, HS, HT, F3, F4, F5, F6) IMAGE_ ## NAME,
   typedef enum IMAGEIDS {
       #include <assets/images.def>
       IMAGEIDS_COUNT
   } IMAGEIDS;
   ```

2. **Image size enum** (`src/bondconstants.h`):
   ```c
   #define IMAGE(NAME, SZ, HS, HT, F3, F4, F5, F6) IMAGE_ ## NAME ## _SIZE = SZ,
   typedef enum IMGAGESIZES {
       #include <assets/images.def>
       IMGAGESIZES_COUNT
   } IMGAGESIZES;
   ```

3. **Image properties table** (`src/game/image.c`):
   ```c
   #define IMAGE(NAME, SZ, HS, HT, F3, F4, F5, F6) {HS, HT, SZ, F3, F4, F5, F6 },
   struct image_entry g_Textures[] = {
       #include <assets/images.def>
       {HIT_DEFAULT, HIT_DEFAULT,0xFFFF,0,0,0,0}
   };
   ```

This is why the SIZE field must remain in images.def (it's used by C code), but it's now automatically maintained.

## Testing

To verify the system works:

```bash
# Clean and rebuild
make dataclean
make assets/images/combined/combined.bin

# Check output
ls -lh assets/images/combined/combined.bin
head build/u/imagelist.csv
```

Expected output:
- combined.bin should be ~3MB (3075864 bytes)
- imagelist.csv should show correct offsets and paths
- No errors about missing files (unless images are actually missing)
