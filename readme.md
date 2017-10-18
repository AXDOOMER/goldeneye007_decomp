This is a working Goldeneye 007 disassembly!


To compile you will need a mips gcc compiler, I use n64 chain from https://cen64.com/
You will also need ARM9's fork of bass, https://github.com/ARM9/bass 


All code is disassembled!
Known functions are labeled with meaningful names.
Not all raw addresses in code have been converted to labels.


I think all strings are now represented by .asciiz statements.
Alot of the compressed data has meaningful names, just have to organize it now.


Makefile and linker scripts are hacky but they work.



KNOWN BUGS:
In playing with C conversion, I've discovered that gcc likes to be different than the SGI compiler Rare originally used.
This means that gcc will never be able to produce byte identicle code, which won't stop, just slow down the C decompile.
If you know of a way to make gcc produce exact code, please tell me, or submit a pr when I start pushing C code.


Side note: I am on the hunt for a reasonably priced (or remotely accessible) SGI Indy to be able to test C code on original compilers.



This dissassembly was only made possible thanks to Zoinkity's awesome documentation, and Subdrag's wonderful GEedit.



Not sure how to license the actual disassembled/decompiled code side of this project, but anything I am able to put a license on in this repo is public domain.
