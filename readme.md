This is a working Goldeneye 007 decompilation! 

[![NTSC-Status](https://github.com/kholdfuzion/goldeneye_src/workflows/NTSC-Status/badge.svg)](https://kholdfuzion.github.io/goldeneyestatus/)
[![JP-Status](https://github.com/kholdfuzion/goldeneye_src/workflows/JP-Status/badge.svg)](https://kholdfuzion.github.io/goldeneyestatus/JPN.htm)

This repo builds a matching USA. JPN or PAL ROM.

This repo does not include all assets necessary for compiling the ROMs. A prior copy of the game is required to extract the assets.

## Setup
The only requirements for Ubuntu 16.04 and 18.04 should be 
```
sudo apt install binutils-mips-linux-gnu make
```
Make sure you cloned the repo with git otherwise it won't build!!

Place an unmodified USA rom in project root named 
```
baserom.u.z64
```
followed by
```
./extract_baserom.u.sh && make
```
or
``` bash
./extract_baserom.u.sh /path_to/rom.n64 && make
Example (Rom located on EverDrive):
    ./extract_baserom.u.sh /mnt/e/Goldeneye.n64 && make
```
For J support also place a baserom.j.z64 in root and run:
```
./extract_baserom.u.sh && ./extract_diff.j.sh && make VERSION=JP
```

If you are upgrading from an old repo, run:
```
./clean_baserom.sh && ./extract_baserom.u.sh && make clean && make
```

The extract and clean scripts support switches:
```
name_baserom.sh files
name_baserom.sh images
```
to do just one or the other, default is both

## Build the ROM
Run make to build the ROM (defaults to VERSION=us). Other examples:
``` bash
make VERSION=jp -j4       # build (J) version instead with 4 jobs
make VERSION=eu COMPARE=0 # build (EU) version but do not compare ROM hashes
```


Resulting artifacts can be found in the build directory.


The full list of configurable variables are listed below, with the default being the first listed:

VERSION: us, jp, eu

## Project Structure

```
goldeneye_src
├── assets: game assets
│   ├── font: font data
│   ├── images: image data
│   │   └── split: split image data
│   ├── music: music data
│   ├── obseg: animation data
│   │   ├── bg: bg data
│   │   ├── brief: briefing data
│   │   ├── chr: c model data
│   │   ├── gun: g model data
│   │   ├── prop: p model data
│   │   ├── setup: setup data
│   │   ├── stan: stan data
│   │   └── text: text data
│   └── ramrom: demo data
├── bin: files that haven't been touched
├── build: output directory
├── ge007_libultra: to be merged with libreultra
├── include: header files
├── lib: SDK library code
├── notes: documentation
├── src: C source code for game
│   ├── game: core ge specific code 0x7f000000 range
│   ├── libultra: currently used libultra.s
│   └── inflate: statically linked initial decompression code
└── tools: build tools
```

This decompilation was only made possible thanks to many awesome 00 Agents who will be revealed only if they wish.

GE and PD documentation made by Zoinkity
