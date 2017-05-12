arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LdestE.bin", create

base $00000000
seg_LdestE_start:
seg_LdestE_header_start:

ptr_LdestE_string1:
 dw LdestE_string1

ptr_LdestE_string2:
 dw LdestE_string2

ptr_LdestE_string3:
 dw LdestE_string3

ptr_LdestE_string4:
 dw LdestE_string4

ptr_LdestE_string5:
 dw LdestE_string5

ptr_LdestE_string6:
 dw LdestE_string6

ptr_LdestE_string7:
 dw LdestE_string7

ptr_LdestE_string8:
 dw LdestE_string8

ptr_LdestE_string9:
 dw LdestE_string9

ptr_LdestE_string10:
 dw LdestE_string10

ptr_LdestE_string11:
 dw LdestE_string11

ptr_LdestE_string12:
 dw LdestE_string12

ptr_LdestE_string13:
 dw LdestE_string13

ptr_LdestE_string14:
 dw LdestE_string14

ptr_LdestE_string15:
 dw LdestE_string15

ptr_LdestE_string16:
 dw LdestE_string16

ptr_LdestE_string17:
 dw LdestE_string17

ptr_LdestE_string18:
 dw LdestE_string18

ptr_LdestE_string19:
 dw LdestE_string19

ptr_LdestE_string20:
 dw LdestE_string20

ptr_LdestE_string21:
 dw LdestE_string21

ptr_LdestE_string22:
 dw LdestE_string22

ptr_LdestE_string23:
 dw LdestE_string23

ptr_LdestE_string24:
 dw LdestE_string24

ptr_LdestE_string25:
 dw LdestE_string25

ptr_LdestE_string26:
 dw LdestE_string26

ptr_LdestE_string27:
 dw LdestE_string27

ptr_LdestE_string28:
 dw LdestE_string28

ptr_LdestE_string29:
 dw LdestE_string29

ptr_LdestE_string30:
 dw LdestE_string30

ptr_LdestE_string31:
 dw LdestE_string31

ptr_LdestE_string32:
 dw seg_LdestE_start

seg_LdestE_header_end:
seg_LdestE_strings_start:

LdestE_string1:
 db "A demonstration of the Pirate stealth helicopter by the French military has been unexpectedly postponed. Official channels insist that nothing is wrong but unofficially MI6 has been asked to help salvage a very tricky hostage situation on board the frigate La Fayette. It seems that the Janus crime syndicate will stop at nothing in its attempt to hijack the helicopter.\n"; db $0
align(4)

LdestE_string2:
 db "This is the best chance we've had in years to get a lead on Janus. The French are prepared to play along with an entrapment scenario. We need you to place a tracker on the Pirate so that we can trace its movements after Janus steals it.\n\nThis must go smoothly, 007. If the press get a sniff of this, we'll all have egg on our faces.\n"; db $0
align(4)

LdestE_string3:
 db "The French have kindly given us technical details of the Pirate so I've managed to convert this tracker bug into quite a clever little chap. It's undetectable and it locks out all weapon firing commands.\nJanus is also threatening to blow up the ship. They are most likely to have placed explosives on the bridge and in the engine room. Take care, 007, and be certain to use the bomb defuser correctly.\n"; db $0
align(4)

LdestE_string4:
 db "Xenia Onatopp, one of Janus' main operatives, may be on board the La Fayette.\n\nThey say she has thighs of steel, James. Just be sure to stay out of their grasp.\n"; db $0
align(4)

LdestE_string5:
 db "Rescue hostages\n"; db $0
align(4)

LdestE_string6:
 db "Disarm bridge bomb\n"; db $0
align(4)

LdestE_string7:
 db "Disarm engine room bomb\n"; db $0
align(4)

LdestE_string8:
 db "Plant tracking bug on helicopter\n"; db $0
align(4)

LdestE_string9:
 db "Hostage executed!\n"; db $0
align(4)

LdestE_string10:
 db "Hostage released!\n"; db $0
align(4)

LdestE_string11:
 db "Hostage escaped!\n"; db $0
align(4)

LdestE_string12:
 db "Tracker bug successfully planted on Pirate\n"; db $0
align(4)

LdestE_string13:
 db "Oops! Careful with those bugs, James.\n"; db $0
align(4)

LdestE_string14:
 db "Bridge bomb successfully defused.\n"; db $0
align(4)

LdestE_string15:
 db "Engine room bomb successfully defused.\n"; db $0
align(4)

LdestE_string16:
 db "F R I G A T E\n"; db $0
align(4)

LdestE_string17:
 db "a demonstration of the pirate stealth helicopter by the french military has been unexpectedly postponed. official channels insist that nothing is wrong but unofficially MI6 has been asked to help salvage a very tricky hostage situation on board the frigate la fayette. it seems that the janus crime syndicate will stop at nothing in its attempt  to hijack the helicopter.\n"; db $0
align(4)

LdestE_string18:
 db "this is the best chance we've had in years to get a lead on janus. the french are prepared to play along with an entrapment scenario. we need you to place a tracker on the pirate so that we can trace its movements after janus steals it.\n\nthis must go smoothly, 007. if the press get a sniff of this, we'll all have egg on our faces.\n"; db $0
align(4)

LdestE_string19:
 db "the french have kindly given us technical details of the pirate so i've managed to convert this tracker bug into quite a clever little chap. it's undetectable and it locks out all weapon firing commands.\njanus is also threatening to blow up the ship. they are most likely to have placed explosives on the bridge and in the engine room. take care, 007, and be certain to use the bomb defuser correctly.\n"; db $0
align(4)

LdestE_string20:
 db "xenia onatopp, one of janus' main operatives, may be on board the la fayette.\n\nthey say she has thighs of steel, james. just be sure to stay out of their grasp.\n"; db $0
align(4)

LdestE_string21:
 db "rescue hostages\n"; db $0
align(4)

LdestE_string22:
 db "disarm bridge bomb\n"; db $0
align(4)

LdestE_string23:
 db "disarm engine room bomb\n"; db $0
align(4)

LdestE_string24:
 db "plant tracking bug on helicopter\n"; db $0
align(4)

LdestE_string25:
 db "Frigate 'La Fayette', Monte Carlo\n"; db $0
align(4)

LdestE_string26:
 db "\n"; db $0
align(4)

LdestE_string27:
 db "tracker bug\n"; db $0
align(4)

LdestE_string28:
 db "tracker bug\n"; db $0
align(4)

LdestE_string29:
 db "tracker bug\n"; db $0
align(4)

LdestE_string30:
 db "Picked up a tracker bug.\n"; db $0
align(4)

LdestE_string31:
db "Mission Failure: Unacceptable hostage\ncasualties!\n"; db $0
align(16)

seg_LdestE_strings_end:
seg_LdestE_end:

