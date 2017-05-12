arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LtraE.bin", create

base $00000000
seg_LtraE_start:
seg_LtraE_header_start:

ptr_LtraE_string1:
 dw LtraE_string1

ptr_LtraE_string2:
 dw LtraE_string2

ptr_LtraE_string3:
 dw LtraE_string3

ptr_LtraE_string4:
 dw LtraE_string4

ptr_LtraE_string5:
 dw LtraE_string5

ptr_LtraE_string6:
 dw LtraE_string6

ptr_LtraE_string7:
 dw LtraE_string7

ptr_LtraE_string8:
 dw LtraE_string8

ptr_LtraE_string9:
 dw LtraE_string9

ptr_LtraE_string10:
 dw LtraE_string10

ptr_LtraE_string11:
 dw LtraE_string11

ptr_LtraE_string12:
 dw LtraE_string12

ptr_LtraE_string13:
 dw LtraE_string13

ptr_LtraE_string14:
 dw LtraE_string14

ptr_LtraE_string15:
 dw LtraE_string15

ptr_LtraE_string16:
 dw LtraE_string16

ptr_LtraE_string17:
 dw LtraE_string17

ptr_LtraE_string18:
 dw LtraE_string18

ptr_LtraE_string19:
 dw LtraE_string19

ptr_LtraE_string20:
 dw LtraE_string20

ptr_LtraE_string21:
 dw LtraE_string21

ptr_LtraE_string22:
 dw LtraE_string22

ptr_LtraE_string23:
 dw LtraE_string23

ptr_LtraE_string24:
 dw LtraE_string24

ptr_LtraE_string25:
 dw LtraE_string25

ptr_LtraE_string26:
 dw LtraE_string26

ptr_LtraE_string27:
 dw LtraE_string27

ptr_LtraE_string28:
 dw LtraE_string28

ptr_LtraE_string29:
 dw LtraE_string29

ptr_LtraE_string30:
 dw LtraE_string30

ptr_LtraE_string31:
 dw LtraE_string31

ptr_LtraE_string32:
 dw LtraE_string32

ptr_LtraE_string33:
 dw LtraE_string33

ptr_LtraE_string34:
 dw LtraE_string34

ptr_LtraE_string35:
 dw LtraE_string35

ptr_LtraE_string36:
 dw LtraE_string36

ptr_LtraE_string37:
 dw LtraE_string37

ptr_LtraE_string38:
 dw LtraE_string38

ptr_LtraE_string39:
 dw LtraE_string39

ptr_LtraE_string40:
 dw LtraE_string40

ptr_LtraE_string41:
 dw LtraE_string41

ptr_LtraE_string42:
 dw LtraE_string42

ptr_LtraE_string43:
 dw LtraE_string43

ptr_LtraE_string44:
 dw LtraE_string44

ptr_LtraE_string45:
 dw LtraE_string45

ptr_LtraE_string46:
 dw seg_LtraE_start

ptr_LtraE_string47:
 dw seg_LtraE_start

ptr_LtraE_string48:
 dw seg_LtraE_start

seg_LtraE_header_end:
seg_LtraE_strings_start:

LtraE_string1:
 db "The leader of Janus, Alec Trevelyan, is holding Natalya hostage on his armored train.\n"; db $0
align(4)

LtraE_string2:
 db "We've lost experienced agents before in hostage situations. Keep a clear head, 007, and don't get sidetracked settling old scores.\n"; db $0
align(4)

LtraE_string3:
 db "A train, 007, pretty simple. Destroy the braking units in each carriage and the emergency \nsystems should bring it to a halt.\n"; db $0
align(4)

LtraE_string4:
 db "That girl again, James? \n"; db $0
align(4)

LtraE_string5:
 db "Destroy brake units\n"; db $0
align(4)

LtraE_string6:
 db "Rescue Natalya\n"; db $0
align(4)

LtraE_string7:
 db "Locate Janus secret base\n"; db $0
align(4)

LtraE_string8:
 db "Crack Boris' password\n"; db $0
align(4)

LtraE_string9:
 db "Escape to safety\n"; db $0
align(4)

LtraE_string10:
 db "Trevelyan: That's close enough!\n"; db $0
align(4)

LtraE_string11:
 db "Trevelyan: Come on James, don't try\n              to be clever. Make your move.\n"; db $0
align(4)

LtraE_string12:
 db "Bond: You first.\n"; db $0
align(4)

LtraE_string13:
 db "Trevelyan: Two targets. Time for one shot.\n              The girl or the mission?\n"; db $0
align(4)

LtraE_string14:
 db "Trevelyan: You'll never win, James.\n"; db $0
align(4)

LtraE_string15:
 db "Xenia: Wait for me Alec, I'm hit!\n"; db $0
align(4)

LtraE_string16:
 db "Trevelyan: Kill them!\n"; db $0
align(4)

LtraE_string17:
 db "Trevelyan: James, what an unpleasant\n              surprise. Do come in.\n"; db $0
align(4)

LtraE_string18:
 db "Trevelyan: Leaving already, James?\n              I don't think so.\n"; db $0
align(4)

LtraE_string19:
 db "Trevelyan: Good luck with the floor, \n              James.\n"; db $0
align(4)

LtraE_string20:
 db "Trevelyan: It shouldn't take more than\n              a minute.\n"; db $0
align(4)

LtraE_string21:
 db "Natalya: Boris is still backing up his files.\n           I can find out where they're\n           going.\n"; db $0
align(4)

LtraE_string22:
 db "Natalya: He's in Cuba!\n"; db $0
align(4)

LtraE_string23:
 db "Natalya: Now, if I just had time to crack \n           his password...\n"; db $0
align(4)

LtraE_string24:
 db "Natalya: Got it!\n           You're a slug-head, Boris!\n"; db $0
align(4)

LtraE_string25:
 db "Natalya: I'm coming, James!\n"; db $0
align(4)

LtraE_string26:
 db "Trevelyan: Too slow, 007.\n"; db $0
align(4)

LtraE_string27:
 db "Natalya: Well done, James, that's the\n           computer out of action.\n"; db $0
align(4)

LtraE_string28:
 db "Natalya: Just how am I supposed to\n           locate the Janus base?\n"; db $0
align(4)

LtraE_string29:
 db "Mission failure. Natalya has been killed.\n"; db $0
align(4)

LtraE_string30:
 db "T R A I N\n"; db $0
align(4)

LtraE_string31:
 db "the leader of janus, alec trevelyan, is holding natalya hostage on his armored train.\n"; db $0
align(4)

LtraE_string32:
 db "we've lost experienced agents before in hostage situations. Keep a clear head, 007, and don't get sidetracked settling old scores.\n"; db $0
align(4)

LtraE_string33:
 db "a train, 007, pretty simple. destroy the braking units in each carriage and the emergency \nsystems should bring it to a halt.\n"; db $0
align(4)

LtraE_string34:
 db "that girl again, james? \n"; db $0
align(4)

LtraE_string35:
 db "destroy brake units\n"; db $0
align(4)

LtraE_string36:
 db "rescue natalya\n"; db $0
align(4)

LtraE_string37:
 db "locate janus secret base\n"; db $0
align(4)

LtraE_string38:
 db "crack boris' password\n"; db $0
align(4)

LtraE_string39:
 db "escape to safety\n"; db $0
align(4)

LtraE_string40:
 db "\n"; db $0
align(4)

LtraE_string41:
 db "door key\n"; db $0
align(4)

LtraE_string42:
 db "train door key\n"; db $0
align(4)

LtraE_string43:
 db "train door key\n"; db $0
align(4)

LtraE_string44:
 db "Picked up a door key.\n"; db $0
align(4)

LtraE_string45:
db "Converted Missile Train, heading east\n"; db $0
align(16)

seg_LtraE_strings_end:
seg_LtraE_end:

