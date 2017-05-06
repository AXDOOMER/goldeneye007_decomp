Not sure what to do about compressed rodata yet. There is a chicken and egg problem pertaining to full relocatability, the best course of action I can think of its to preparse it when the rest of data is compiled/compressed, and create a matching rodata.inc with label to vaddr's defined. During disassembly phase this won't be too big of an issue as everythings vaddr is known.

This will eventually make compilation a multi step process to have relocation: 
1) create gamedata bins and compress to rz where needed
2) build code referencing previous rodata.rz and rodata.inc for filesize and offsets
3) build rodata using updated vaddrs from code build
4) rebuild code with new compressed rodata

As long as the new compressed rodata.rz isn't bigger than space allocated this approach should work fine.


To build:


cd disassembly 


bass -sym GE007.sym GE007.rom.asm 



I use vbindiff while developing to see what changes where if I have somethign wrong quickly:


vbindiff GE007.n64 /path/to/retail_ntsc_rom.z64

then press enter
