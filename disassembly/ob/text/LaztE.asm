arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LaztE.bin", create

base $00000000
seg_LaztE_start:
seg_LaztE_header_start:

ptr_LaztE_string1:
 dw LaztE_string1

ptr_LaztE_string2:
 dw LaztE_string2

ptr_LaztE_string3:
 dw LaztE_string3

ptr_LaztE_string4:
 dw LaztE_string4

ptr_LaztE_string5:
 dw LaztE_string5

ptr_LaztE_string6:
 dw LaztE_string6

ptr_LaztE_string7:
 dw LaztE_string7

ptr_LaztE_string8:
 dw LaztE_string8

ptr_LaztE_string9:
 dw LaztE_string9

ptr_LaztE_string10:
 dw LaztE_string10

ptr_LaztE_string11:
 dw LaztE_string11

ptr_LaztE_string12:
 dw LaztE_string12

ptr_LaztE_string13:
 dw LaztE_string13

ptr_LaztE_string14:
 dw LaztE_string14

ptr_LaztE_string15:
 dw LaztE_string15

ptr_LaztE_string16:
 dw LaztE_string16

ptr_LaztE_string17:
 dw LaztE_string17

ptr_LaztE_string18:
 dw LaztE_string18

ptr_LaztE_string19:
 dw LaztE_string19

ptr_LaztE_string20:
 dw LaztE_string20

ptr_LaztE_string21:
 dw LaztE_string21

ptr_LaztE_string22:
 dw LaztE_string22

ptr_LaztE_string23:
 dw LaztE_string23

ptr_LaztE_string24:
 dw LaztE_string24

ptr_LaztE_string25:
 dw LaztE_string25

ptr_LaztE_string26:
 dw LaztE_string26

ptr_LaztE_string27:
 dw LaztE_string27

ptr_LaztE_string28:
 dw LaztE_string28

ptr_LaztE_string29:
 dw LaztE_string29

ptr_LaztE_string30:
 dw LaztE_string30

ptr_LaztE_string31:
 dw LaztE_string31

ptr_LaztE_string32:
 dw LaztE_string32

ptr_LaztE_string33:
 dw LaztE_string33

ptr_LaztE_string34:
 dw LaztE_string34

ptr_LaztE_string35:
 dw seg_LaztE_start

ptr_LaztE_string36:
 dw seg_LaztE_start

ptr_LaztE_string37:
 dw seg_LaztE_start

ptr_LaztE_string38:
 dw seg_LaztE_start

ptr_LaztE_string39:
 dw LaztE_string39

ptr_LaztE_string40:
 dw seg_LaztE_start

ptr_LaztE_string41:
 dw seg_LaztE_start

ptr_LaztE_string42:
 dw seg_LaztE_start

ptr_LaztE_string43:
 dw seg_LaztE_start

ptr_LaztE_string44:
 dw LaztE_string44

seg_LaztE_header_end:
seg_LaztE_strings_start:

LaztE_string1:
 db "The Drax Corporation continues to be involved in unlicensed space exploration. Many of their projects are of a military nature and constitute a threat to the new world political order."; db $0
align(4)

LaztE_string2:
 db "The Drax launch facility is located in a South American Aztec ruin. They are scheduled to launch a stolen Nasa shuttle with an unknown military payload. We're sending you in alone, 007. Penetrating the base security will be tricky, but once you're in, we believe you will be able to recover the shuttle right out from under their noses. \n"; db $0
align(4)

LaztE_string3:
 db "Simple plan, 007. Reprogram the guidance computer with the information on this floppy - then we can take control as soon as the old girl reaches orbit. Now pay attention, one thing we don't know is the Drax launch protocol - you'll have to find that data and install it to initiate the launch. Can't be too difficult to spot, it'll be lying around in some high security area.\n"; db $0
align(4)

LaztE_string4:
 db "Quetzacoatl ring any bells, James? No, I didn't think so...\n"; db $0
align(4)

LaztE_string5:
 db "Reprogram shuttle guidance\n"; db $0
align(4)

LaztE_string6:
 db "Launch shuttle\n"; db $0
align(4)

LaztE_string7:
 db "Exhaust bay opening.\n"; db $0
align(4)

LaztE_string8:
 db "Exhaust bay closing.\n"; db $0
align(4)

LaztE_string9:
 db "Q's guidance data has been uploaded.\n"; db $0
align(4)

LaztE_string10:
 db "This disk drive is connected to the\nguidance computer systems.\n"; db $0
align(4)

LaztE_string11:
 db "This mainframe controls the shuttle\nlaunch sequence.\n"; db $0
align(4)

LaztE_string12:
 db "The launch protocol data has been\nuploaded.\n"; db $0
align(4)

LaztE_string13:
 db "Shuttle launch sequence initiated.\n"; db $0
align(4)

LaztE_string14:
 db "Final checks cleared. Shuttle launch is go.\n"; db $0
align(4)

LaztE_string15:
 db "Shuttle exhaust bay closed!\nLaunch holding at T minus 10 seconds.\n"; db $0
align(4)

LaztE_string16:
 db "The exhaust bay is secured for shuttle\nlaunch!\n"; db $0
align(4)

LaztE_string17:
 db "A Z T E C\n"; db $0
align(4)

LaztE_string18:
 db "the drax corporation continues to be involved in unlicensed space exploration. many of their projects are of a military nature and constitute a threat to the new world political order."; db $0
align(4)

LaztE_string19:
 db "the drax launch facility is located in a south american aztec ruin. they are scheduled to launch a stolen nasa shuttle with an unknown military payload. we're sending you in alone, 007. penetrating the base security will be tricky, but once you're in, we believe you will be able to recover the shuttle right out from under their noses. \n"; db $0
align(4)

LaztE_string20:
 db "simple plan, 007. reprogram the guidance computer with the information on this floppy - then we can take control as soon as the old girl reaches orbit. now pay attention, one thing we don't know is the drax launch protocol - you'll have to find that data and install it to initiate the launch. can't be too difficult to spot, it'll be lying around in some high security area.\n"; db $0
align(4)

LaztE_string21:
 db "quetzacoatl ring any bells, james? no, i didn't think so...\n"; db $0
align(4)

LaztE_string22:
 db "reprogram shuttle guidance\n"; db $0
align(4)

LaztE_string23:
 db "launch shuttle\n"; db $0
align(4)

LaztE_string24:
 db "Aztec Complex, Teotihuaca'n\n"; db $0
align(4)

LaztE_string25:
 db "\n"; db $0
align(4)

LaztE_string26:
 db "DAT\n"; db $0
align(4)

LaztE_string27:
 db "launch protocol data\n"; db $0
align(4)

LaztE_string28:
 db "launch protocol data\n"; db $0
align(4)

LaztE_string29:
 db "picked up a DAT\n"; db $0
align(4)

LaztE_string30:
 db "\n"; db $0
align(4)

LaztE_string31:
 db "smart card\n"; db $0
align(4)

LaztE_string32:
 db "security smart card\n"; db $0
align(4)

LaztE_string33:
 db "-\n"; db $0
align(4)

LaztE_string34:
db "Picked up a smart card.\n"; db $0
align(4)

LaztE_string39:
db "This mainframe is inoperative.\n"; db $0
align(4)

LaztE_string44:
 db "This door requires\na security smart card.\n"; db $0
align(4)
dw $0; align(16)

seg_LaztE_strings_end:
seg_LaztE_end:

