.section .data, "a"

.global _jfontdlSegmentStart
_jfontdlSegmentStart:
.incbin "assets/ge007.u.117880.jfont_dl.bin"
.global _jfontdlSegmentEnd
_jfontdlSegmentEnd:

.global _jfontcharSegmentStart
_jfontcharSegmentStart:
.ifdef VERSION_US
.incbin "assets/ge007.u.117940.jfont_chardata.bin"
.endif
.ifdef VERSION_JP
.incbin "assets/ge007.j.118660.jfont_chardata.bin"
.endif
.global _jfontcharSegmentEnd
_jfontcharSegmentEnd:

.global _efontcharSegmentStart
_efontcharSegmentStart:
.incbin "assets/ge007.u.123040.efont_chardata.bin"
.global _efontcharSegmentEnd
_efontcharSegmentEnd:



