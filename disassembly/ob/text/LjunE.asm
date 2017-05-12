arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LjunE.bin", create

base $00000000
seg_LjunE_start:
seg_LjunE_header_start:

ptr_LjunE_string1:
 dw LjunE_string1

ptr_LjunE_string2:
 dw LjunE_string2

ptr_LjunE_string3:
 dw LjunE_string3

ptr_LjunE_string4:
 dw LjunE_string4

ptr_LjunE_string5:
 dw LjunE_string5

ptr_LjunE_string6:
 dw LjunE_string6

ptr_LjunE_string7:
 dw LjunE_string7

ptr_LjunE_string8:
 dw LjunE_string8

ptr_LjunE_string9:
 dw LjunE_string9

ptr_LjunE_string10:
 dw LjunE_string10

ptr_LjunE_string11:
 dw LjunE_string11

ptr_LjunE_string12:
 dw LjunE_string12

ptr_LjunE_string13:
 dw LjunE_string13

ptr_LjunE_string14:
 dw LjunE_string14

ptr_LjunE_string15:
 dw LjunE_string15

ptr_LjunE_string16:
 dw LjunE_string16

ptr_LjunE_string17:
 dw LjunE_string17

ptr_LjunE_string18:
 dw LjunE_string18

ptr_LjunE_string19:
 dw LjunE_string19

ptr_LjunE_string20:
 dw LjunE_string20

ptr_LjunE_string21:
 dw LjunE_string21

ptr_LjunE_string22:
 dw LjunE_string22

ptr_LjunE_string23:
 dw LjunE_string23

ptr_LjunE_string24:
 dw LjunE_string24

ptr_LjunE_string25:
 dw LjunE_string25

ptr_LjunE_string26:
 dw LjunE_string26

ptr_LjunE_string27:
 dw LjunE_string27

ptr_LjunE_string28:
 dw LjunE_string28

ptr_LjunE_string29:
 dw LjunE_string29

ptr_LjunE_string30:
 dw LjunE_string30

ptr_LjunE_string31:
 dw LjunE_string31

ptr_LjunE_string32:
 dw LjunE_string32

ptr_LjunE_string33:
 dw LjunE_string33

ptr_LjunE_string34:
 dw LjunE_string34

ptr_LjunE_string35:
 dw LjunE_string35

ptr_LjunE_string36:
 dw LjunE_string36

ptr_LjunE_string37:
 dw LjunE_string37

ptr_LjunE_string38:
 dw LjunE_string38

ptr_LjunE_string39:
 dw LjunE_string39

ptr_LjunE_string40:
 dw LjunE_string40

ptr_LjunE_string41:
 dw LjunE_string41

ptr_LjunE_string42:
 dw LjunE_string42

ptr_LjunE_string43:
 dw seg_LjunE_start

ptr_LjunE_string44:
 dw seg_LjunE_start

seg_LjunE_header_end:
seg_LjunE_strings_start:

LjunE_string1:
 db "Satellite reconnaissance has been unable to locate any installation near the coordinates recovered from the Janus computers in St. Petersburg. It seems likely that a ground search will be necessary. The CIA has provided you with a light aircraft. Underfly Janus radar and parachute in to the drop, proceed through the jungle eliminating any opposition and attempt to locate the Janus base.\n"; db $0
align(4)

LjunE_string2:
 db "Miss Simonova will be with you on this mission. If Janus is operating a Goldeneye satellite, her computing skills will be essential when you try to disable their systems.\nJack Wade has given her some basic firearms training and he thinks she'll be able to carry her weight in a combat situation. Be careful though, 007, remember she isn't an experienced operative like yourself.\n"; db $0
align(4)

LjunE_string3:
 db "You'll know you're on the right trail if you encounter Janus troops or automated defenses. Be especially wary of their robotic drone guns. I'm giving you some triggered mines for their ammo dump, try not to waste them on silly things. Oh, and look out for that Xenia woman, 007, I think she's after you. You lucky devil.\n"; db $0
align(4)

LjunE_string4:
 db "A hot date in the rainforest? With two women!\nShame on you James.\n"; db $0
align(4)

LjunE_string5:
 db "Destroy drone guns\n"; db $0
align(4)

LjunE_string6:
 db "Eliminate Xenia\n"; db $0
align(4)

LjunE_string7:
 db "Blow up ammo dump\n"; db $0
align(4)

LjunE_string8:
 db "Escort Natalya to Janus base\n"; db $0
align(4)

LjunE_string9:
 db "Natalya: Got one!\n"; db $0
align(4)

LjunE_string10:
 db "Natalya: That looked painful.\n"; db $0
align(4)

LjunE_string11:
 db "Natalya: Too slow.\n"; db $0
align(4)

LjunE_string12:
 db "Natalya: Gotcha!\n"; db $0
align(4)

LjunE_string13:
 db "Natalya: Did you see that?\n"; db $0
align(4)

LjunE_string14:
 db "Natalya: This is fun.\n"; db $0
align(4)

LjunE_string15:
 db "Natalya: Close, but no cigar.\n"; db $0
align(4)

LjunE_string16:
 db "Natalya: Oh, that's a nice plant.\n"; db $0
align(4)

LjunE_string17:
 db "Natalya: This gun's quite powerful.\n"; db $0
align(4)

LjunE_string18:
 db "Natalya: Who was that guy?\n"; db $0
align(4)

LjunE_string19:
 db "Natalya: I like this game.\n"; db $0
align(4)

LjunE_string20:
 db "Natalya: Cover me.\n"; db $0
align(4)

LjunE_string21:
 db "Natalya: Naughty boy.\n"; db $0
align(4)

LjunE_string22:
 db "Natalya: Unlucky.\n"; db $0
align(4)

LjunE_string23:
 db "Natalya: Oh, messy.\n"; db $0
align(4)

LjunE_string24:
 db "Natalya: Advantage, Natalya Simonova.\n"; db $0
align(4)

LjunE_string25:
 db "Natalya: That's one more for me.\n"; db $0
align(4)

LjunE_string26:
 db "Natalya: Loser.\n"; db $0
align(4)

LjunE_string27:
 db "Natalya: Just like the movies.\n"; db $0
align(4)

LjunE_string28:
 db "Natalya: \n"; db $0
align(4)

LjunE_string29:
 db "Natalya: Let's go to work.\n"; db $0
align(4)

LjunE_string30:
 db "Natalya: Be careful, James!\n"; db $0
align(4)

LjunE_string31:
 db "Xenia: This time, Mr. Bond, the pleasure\n          will be all mine.\n"; db $0
align(4)

LjunE_string32:
 db "Mission failure. Natalya has been killed.\n"; db $0
align(4)

LjunE_string33:
 db "C U B A N   J U N G L E\n"; db $0
align(4)

LjunE_string34:
 db "satellite reconnaissance has been unable to locate any installation near the coordinates recovered from the janus computers in st. petersburg. it seems likely that a ground search will be necessary. the cia has provided you with a light aircraft. underfly janus radar and parachute in to the drop, proceed through the jungle eliminating any opposition and attempt to locate the janus base.\n"; db $0
align(4)

LjunE_string35:
 db "miss simonova will be with you on this mission. if janus is operating a goldeneye satellite, her computing skills will be essential when you try to disable their systems.\njack wade has given her some basic firearms training and he thinks she'll be able to carry her weight in a combat situation. be careful though, 007, \nremember she isn't an experienced operative like yourself.\n"; db $0
align(4)

LjunE_string36:
 db "you'll know you're on the right trail if you encounter janus troops or automated defenses. be especially wary of their robotic drone guns. i'm giving you some triggered mines for their ammo dump, try not to waste them on silly things. oh, and look out for that xenia woman, 007, i think she's after you. you lucky devil.\n"; db $0
align(4)

LjunE_string37:
 db "a hot date in the rainforest? \nwith two women!\nshame on you james.\n"; db $0
align(4)

LjunE_string38:
 db "destroy drone guns\n"; db $0
align(4)

LjunE_string39:
 db "eliminate xenia\n"; db $0
align(4)

LjunE_string40:
 db "blow up ammo dump\n"; db $0
align(4)

LjunE_string41:
 db "escort natalya to janus base\n"; db $0
align(4)

LjunE_string42:
db "Cuban Jungle\n"; db $0
align(32)

seg_LjunE_strings_end:
seg_LjunE_end:

