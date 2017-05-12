arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LmpmenuE.bin", create

base $00000000
seg_LmpmenuE_start:
seg_LmpmenuE_header_start:

ptr_LmpmenuE_string1:
 dw LmpmenuE_string1

ptr_LmpmenuE_string2:
 dw LmpmenuE_string2

ptr_LmpmenuE_string3:
 dw LmpmenuE_string3

ptr_LmpmenuE_string4:
 dw LmpmenuE_string4

ptr_LmpmenuE_string5:
 dw LmpmenuE_string5

ptr_LmpmenuE_string6:
 dw LmpmenuE_string6

ptr_LmpmenuE_string7:
 dw LmpmenuE_string7

ptr_LmpmenuE_string8:
 dw LmpmenuE_string8

ptr_LmpmenuE_string9:
 dw LmpmenuE_string9

ptr_LmpmenuE_string10:
 dw LmpmenuE_string10

ptr_LmpmenuE_string11:
 dw LmpmenuE_string11

ptr_LmpmenuE_string12:
 dw LmpmenuE_string12

ptr_LmpmenuE_string13:
 dw LmpmenuE_string13

ptr_LmpmenuE_string14:
 dw LmpmenuE_string14

ptr_LmpmenuE_string15:
 dw LmpmenuE_string15

ptr_LmpmenuE_string16:
 dw LmpmenuE_string16

ptr_LmpmenuE_string17:
 dw LmpmenuE_string17

ptr_LmpmenuE_string18:
 dw LmpmenuE_string18

ptr_LmpmenuE_string19:
 dw LmpmenuE_string19

ptr_LmpmenuE_string20:
 dw LmpmenuE_string20

ptr_LmpmenuE_string21:
 dw LmpmenuE_string21

ptr_LmpmenuE_string22:
 dw LmpmenuE_string22

ptr_LmpmenuE_string23:
 dw LmpmenuE_string23

ptr_LmpmenuE_string24:
 dw LmpmenuE_string24

ptr_LmpmenuE_string25:
 dw LmpmenuE_string25

ptr_LmpmenuE_string26:
 dw LmpmenuE_string26

ptr_LmpmenuE_string27:
 dw LmpmenuE_string27

ptr_LmpmenuE_string28:
 dw LmpmenuE_string28

ptr_LmpmenuE_string29:
 dw LmpmenuE_string29

ptr_LmpmenuE_string30:
 dw LmpmenuE_string30

ptr_LmpmenuE_string31:
 dw LmpmenuE_string31

ptr_LmpmenuE_string32:
 dw LmpmenuE_string32

ptr_LmpmenuE_string33:
 dw LmpmenuE_string33

ptr_LmpmenuE_string34:
 dw LmpmenuE_string34

ptr_LmpmenuE_string35:
 dw LmpmenuE_string35

ptr_LmpmenuE_string36:
 dw LmpmenuE_string36

seg_LmpmenuE_header_end:
seg_LmpmenuE_strings_start:

LmpmenuE_string1:
 db "Lemming Award"; db $0
align(4)

LmpmenuE_string2:
 db "Where's the Ammo?"; db $0
align(4)

LmpmenuE_string3:
 db "Where's the Armor?"; db $0
align(4)

LmpmenuE_string4:
 db "AC -10 Award"; db $0
align(4)

LmpmenuE_string5:
 db "Marksmanship Award"; db $0
align(4)

LmpmenuE_string6:
 db "Most Professional"; db $0
align(4)

LmpmenuE_string7:
 db "Most Deadly"; db $0
align(4)

LmpmenuE_string8:
 db "Mostly Harmless"; db $0
align(4)

LmpmenuE_string9:
 db "Most Cowardly"; db $0
align(4)

LmpmenuE_string10:
 db "Most Frantic"; db $0
align(4)

LmpmenuE_string11:
 db "Most Honorable"; db $0
align(4)

LmpmenuE_string12:
 db "Most Dishonorable"; db $0
align(4)

LmpmenuE_string13:
 db "Shortest Innings"; db $0
align(4)

LmpmenuE_string14:
 db "Longest Innings"; db $0
align(4)

LmpmenuE_string15:
 db "Double Kill"; db $0
align(4)

LmpmenuE_string16:
 db "Triple Kill"; db $0
align(4)

LmpmenuE_string17:
 db "Quad Kill (Doh!)"; db $0
align(4)

LmpmenuE_string18:
 db "Rank: 1st"; db $0
align(4)

LmpmenuE_string19:
 db "Rank: 2nd"; db $0
align(4)

LmpmenuE_string20:
 db "Rank: 3rd"; db $0
align(4)

LmpmenuE_string21:
 db "Rank: 4th"; db $0
align(4)

LmpmenuE_string22:
 db "PLAY"; db $0
align(4)

LmpmenuE_string23:
 db "GAME OVER"; db $0
align(4)

LmpmenuE_string24:
 db "START TO EXIT"; db $0
align(4)

LmpmenuE_string25:
 db "PAUSED"; db $0
align(4)

LmpmenuE_string26:
 db "PAUSE"; db $0
align(4)

LmpmenuE_string27:
 db "EXIT"; db $0
align(4)

LmpmenuE_string28:
 db "SCORES"; db $0
align(4)

LmpmenuE_string29:
 db "P"; db $0
align(4)

LmpmenuE_string30:
 db "KILLS"; db $0
align(4)

LmpmenuE_string31:
 db "LOSSES"; db $0
align(4)

LmpmenuE_string32:
 db "Weapon of choice:"; db $0
align(4)

LmpmenuE_string33:
 db "cancel"; db $0
align(4)

LmpmenuE_string34:
 db "confirm"; db $0
align(4)

LmpmenuE_string35:
 db "press start\n"; db $0
align(4)

LmpmenuE_string36:
 db "to continue\n"; db $0
align(16)

seg_LmpmenuE_strings_end:
seg_LmpmenuE_end:

