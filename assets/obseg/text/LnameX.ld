/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   _LnameXDataStart = ADDR(.data);
   _LnameXDataRomStart = 0x0000;
   .data 0x00000000 : AT(0x0000) {
      assets/obseg/text/LnameX.o (.data);
   }
   _LnameEDataEnd = ADDR(.data) + SIZEOF(.data);
   _LnameEDataRomEnd = 0x0000 + SIZEOF(.data);



   _LnameXRODataStart = ADDR(.rodata);
   _LnameXRODataRomStart = _LnameEHeaderRomEnd;
   .rodata : AT(_LnameEHeaderRomEnd) {
      assets/obseg/text/LnameX.o (.rodata);
   }
   _LnameXRODataEnd = ADDR( .rodata) + SIZEOF( .rodata);
   _LnameXRODataRomEnd = _LnameEHeaderRomEnd + SIZEOF( .rodata);

      /DISCARD/ : {
      * (.MIPS.abiflags);
      * (.options);
      * (.gnu.attributes);
      * (.pdr);
      * (.mdebug);
      * (.gptab.bss);
      * (.gptab.data);
      * (.reginfo);
}
}
