This is the inprogress rewrite that will be replacing the old one once a few bugs are worked out.


All code is disassembled!
Known functions are labeled. Addresses in .data have not been symbolically represented yet.

All of 21990 compressed data segment is decompressed and assigned to .data.
I think all strings are now represented by .asciiz statements.
Alot of labels made. Still have to do formatting and structuring of data.

Started Makefile and linker scripts.

KNOWN BUGS: (once these are completed, this will replace old disasm)
1. for some reason my mips64-elf-as is spitting out 0xOPCODE2D instead of 0xOPCODE25 for move instructions, I'm on 5.10, will be trying other versions soon

2. final rom is too big!!! It's because the extra non-compressed sections are still attached. No big deal to fix with a script which will take those sections, compress 'em, and shove 'em where they belong.

Also, still need to take the big series of includes making a single object, and split to many objects linked to right spot. Deconstruction of individual files in ob_seg will happened during or as a result of this.


This dissassembly rewrite was made possible thanks to queueRAM's sm64tools. I still need to add 1172 support to it, then I will submit a PR with my changes.
