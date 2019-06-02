/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   _LnameEHeaderStart = ADDR(.header);
   _LnameEHeaderRomStart = 0x0000;
   .header 0x00000000 : AT(0x0000) {
      assets/obseg/text/LnameE.o (.data);
   }
   _LnameEHeaderEnd = ADDR(.header) + SIZEOF(.header);
   _LnameEHeaderRomEnd = 0x0000 + SIZEOF(.header);



   _LnameETextStart = ADDR( .payload);
   _LnameETextRomStart = _LnameEHeaderRomEnd;
   .payload : AT(_LnameEHeaderRomEnd) {
      assets/obseg/text/LnameE.o (.rodata);
   }
   _LnameETextEnd = ADDR( .payload) + SIZEOF( .payload);
   _LnameETextRomEnd = _LnameEHeaderRomEnd + SIZEOF( .payload);
}
