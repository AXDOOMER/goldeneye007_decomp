This is a project to split GoldenEye 007 n64 rom down to the raw assembly code and files to required fully mod the game. Similar to what the pokered and pokecrystal projects achieved.

The first goal was to split the rom into code segments and files. Thats now complete. 


The current goal is to turn code binaries into assembly one function at a time, at the same time look into a tool to mass disassemble into a bass friendly syntax. The tool would greatly speed up development as it becomes more of a labeling game.

To build use https://github.com/ARM9/bass and:


cd disassembly 


bass -sym GE007.sym GE007.rom.asm 



I use vbindiff while developing to quickly see what changes where if have a typo.


vbindiff GE007.n64 /path/to/retail_ntsc_rom.z64

Then press enter once loaded to jump to first change


SPECIAL THANKS TO: Subdrag, Wreck, and Zoinkity. Without your hard work documenting this game, this project wouldn't exist.



Not sure what to do about compressed rodata yet. There is a chicken and egg problem pertaining to full relocatability, the best course of action I can think of its to preparse it when the rest of data is compiled/compressed, and create a matching rodata.inc with label to vaddr's defined. During disassembly phase this won't be too big of an issue as everythings vaddr is known.

This will eventually make compilation a multi step process to have relocation: 

1) create gamedata bins and compress to rz where needed

2) build code referencing previous rodata.rz and rodata.inc for filesize and offsets

3) build rodata.asm into rodata.bin using vaddrs exported from roms symbols, then compress rodata.bin into rodata.rz

4) rebuild code with new compressed rodata.rz and rodata.inc

As long as the new compressed rodata.rz isn't bigger than space allocated (currently 944 bytes extra) this approach should work fine.

Ignore elf related files for now, eventually I intend to make an elf build to use with retdec to maybe eventually decompile this back to C. Elf as intermediary could also be a solution to the chicken and egg problem...


