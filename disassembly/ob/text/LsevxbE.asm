arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LsevxbE.bin", create

base $00000000
seg_LsevxbE_start:
seg_LsevxbE_header_start:

ptr_LsevxbE_string1:
 dw LsevxbE_string1

ptr_LsevxbE_string2:
 dw LsevxbE_string2

ptr_LsevxbE_string3:
 dw LsevxbE_string3

ptr_LsevxbE_string4:
 dw LsevxbE_string4

ptr_LsevxbE_string5:
 dw LsevxbE_string5

ptr_LsevxbE_string6:
 dw LsevxbE_string6

ptr_LsevxbE_string7:
 dw LsevxbE_string7

ptr_LsevxbE_string8:
 dw LsevxbE_string8

ptr_LsevxbE_string9:
 dw LsevxbE_string9

ptr_LsevxbE_string10:
 dw LsevxbE_string10

ptr_LsevxbE_string11:
 dw LsevxbE_string11

ptr_LsevxbE_string12:
 dw LsevxbE_string12

ptr_LsevxbE_string13:
 dw LsevxbE_string13

ptr_LsevxbE_string14:
 dw LsevxbE_string14

ptr_LsevxbE_string15:
 dw LsevxbE_string15

ptr_LsevxbE_string16:
 dw LsevxbE_string16

ptr_LsevxbE_string17:
 dw LsevxbE_string17

ptr_LsevxbE_string18:
 dw LsevxbE_string18

ptr_LsevxbE_string19:
 dw LsevxbE_string19

ptr_LsevxbE_string20:
 dw LsevxbE_string20

ptr_LsevxbE_string21:
 dw LsevxbE_string21

ptr_LsevxbE_string22:
 dw LsevxbE_string22

ptr_LsevxbE_string23:
 dw LsevxbE_string23

ptr_LsevxbE_string24:
 dw LsevxbE_string24

ptr_LsevxbE_string25:
 dw LsevxbE_string25

ptr_LsevxbE_string26:
 dw LsevxbE_string26

ptr_LsevxbE_string27:
 dw LsevxbE_string27

ptr_LsevxbE_string28:
 dw LsevxbE_string28

ptr_LsevxbE_string29:
 dw LsevxbE_string29

ptr_LsevxbE_string30:
 dw LsevxbE_string30

ptr_LsevxbE_string31:
 dw seg_LsevxbE_start

ptr_LsevxbE_string32:
 dw seg_LsevxbE_start

ptr_LsevxbE_string33:
 dw seg_LsevxbE_start

ptr_LsevxbE_string34:
 dw seg_LsevxbE_start

ptr_LsevxbE_string35:
 dw LsevxbE_string35

ptr_LsevxbE_string36:
 dw seg_LsevxbE_start

seg_LsevxbE_header_end:
seg_LsevxbE_strings_start:

LsevxbE_string1:
 db "The Pirate helicopter was tracked to Severnaya, where a Keyhole-1 ELINT satellite recorded a brief firefight.\nAfter the Pirate left, the same satellite observed a troop helicopter being made ready at a Spetznaz camp, 200 miles due south.\nThe only way that we can get you there quickly is to drop you from  a spy plane, and the Soviet Special Forces will be there before you. \n"; db $0
align(4)

LsevxbE_string2:
 db "You should remember this place, 007. We need any evidence of Janus' presence there, and fast. Disable the troop helicopter so that nothing can be removed from the scene, and destroy their surveillance cameras.\nThis had to be an inside job, Bond. Find out who their contact was - the macabre way to do it would be to use their casualty list. Of course, you'd have to know who was there first.\n"; db $0
align(4)

LsevxbE_string3:
 db "Right, I've altered a standard mine to take a ten-second fuse. There's only one, so don't play around with it. That should take care of their helicopter. This is a covert op, so I've fitted a silencer to your pistol. Satisfied? No? Well, tough; that's all you're getting. \n"; db $0
align(4)

LsevxbE_string4:
 db "Remember the saying, James? 'Never go back'? \n"; db $0
align(4)

LsevxbE_string5:
 db "Disrupt all surveillance equipment\n"; db $0
align(4)

LsevxbE_string6:
 db "Break communications link to bunker\n"; db $0
align(4)

LsevxbE_string7:
 db "Disable Spetznaz support aircraft\n"; db $0
align(4)

LsevxbE_string8:
 db "Gain entry to bunker\n"; db $0
align(4)

LsevxbE_string9:
 db "Communications link damaged.\n"; db $0
align(4)

LsevxbE_string10:
 db "<<Da? What is wrong, comrade?>>\n"; db $0
align(4)

LsevxbE_string11:
 db "Surveillance camera disabled.\n"; db $0
align(4)

LsevxbE_string12:
 db "Bomb placed on Hound MI-4.\n"; db $0
align(4)

LsevxbE_string13:
 db "Bomb incorrectly placed - inactive!\n"; db $0
align(4)

LsevxbE_string14:
 db "Hound MI-4 destroyed.\n"; db $0
align(4)

LsevxbE_string15:
 db "Welcome to Severnaya, comrade.\n"; db $0
align(4)

LsevxbE_string16:
 db "S E V E R N A Y A\n"; db $0
align(4)

LsevxbE_string17:
 db "the pirate helicopter was tracked to severnaya, where a keyhole-1 ELINT satellite recorded a brief firefight.\nafter the pirate left, the same satellite observed a troop helicopter being made ready at a spetznaz camp, 200 miles due south.\nthe only way we can get you there quickly is to drop you from a spy plane, and the soviet special forces will be there before you. \n"; db $0
align(4)

LsevxbE_string18:
 db "you should remember this place, 007. we need any evidence of janus' presence there, and fast. disable the troop helicopter so that nothing can be removed from the scene, and destroy their surveillance cameras.\nthis had to be an inside job, bond. find out who their contact was - the macabre way to do it would be to use their casualty list. of course, you'd have to know who was there first.\n"; db $0
align(4)

LsevxbE_string19:
 db "right, i've altered a standard mine to take a ten-second fuse. there's only one, so don't play around with it. that should take care of their helicopter. this is a covert operation, so i've fitted a silencer to your pistol. satisfied? no? well, tough; that's all you're getting. \n"; db $0
align(4)

LsevxbE_string20:
 db "remember the saying, james? 'never go back'? \n"; db $0
align(4)

LsevxbE_string21:
 db "disrupt all surveillance\n   equipment\n"; db $0
align(4)

LsevxbE_string22:
 db "break communications link\n   to bunker\n"; db $0
align(4)

LsevxbE_string23:
 db "disable spetznaz support\n   aircraft\n"; db $0
align(4)

LsevxbE_string24:
 db "gain entry to bunker\n"; db $0
align(4)

LsevxbE_string25:
 db "Severnaya Installation, Siberian Plateau\n"; db $0
align(4)

LsevxbE_string26:
 db "\n"; db $0
align(4)

LsevxbE_string27:
 db "comms room key\n"; db $0
align(4)

LsevxbE_string28:
 db "comms room key \n"; db $0
align(4)

LsevxbE_string29:
 db "comms room key \n"; db $0
align(4)

LsevxbE_string30:
db "Picked up comms room key.\n"; db $0
align(4)

LsevxbE_string35:
db "this access hatch has\nbeen welded shut.\n"; db $0
align(16)

seg_LsevxbE_strings_end:
seg_LsevxbE_end:

