# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches


.section .music

.global _musicSbkSegmentRomStart
_musicSbkSegmentRomStart:
 .incbin "assets/audio/music.sbk"
.global _musicSbkSegmentRomEnd
_musicSbkSegmentRomEnd:


