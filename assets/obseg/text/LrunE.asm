arch n64.cpu
endian msb
include "../BASS.INC"
output "LrunE.bin", create

base $00000000
seg_LrunE_start:
seg_LrunE_header_start:

ptr_LrunE_string1:
 dw LrunE_string1

ptr_LrunE_string2:
 dw LrunE_string2

ptr_LrunE_string3:
 dw LrunE_string3

ptr_LrunE_string4:
 dw LrunE_string4

ptr_LrunE_string5:
 dw LrunE_string5

ptr_LrunE_string6:
 dw LrunE_string6

ptr_LrunE_string7:
 dw LrunE_string7

ptr_LrunE_string8:
 dw LrunE_string8

ptr_LrunE_string9:
 dw LrunE_string9

ptr_LrunE_string10:
 dw LrunE_string10

ptr_LrunE_string11:
 dw LrunE_string11

ptr_LrunE_string12:
 dw LrunE_string12

ptr_LrunE_string13:
 dw LrunE_string13

ptr_LrunE_string14:
 dw LrunE_string14

ptr_LrunE_string15:
 dw LrunE_string15

ptr_LrunE_string16:
 dw LrunE_string16

ptr_LrunE_string17:
 dw LrunE_string17

ptr_LrunE_string18:
 dw LrunE_string18

ptr_LrunE_string19:
 dw LrunE_string19

ptr_LrunE_string20:
 dw LrunE_string20

ptr_LrunE_string21:
 dw LrunE_string21

ptr_LrunE_string22:
 dw LrunE_string22

ptr_LrunE_string23:
 dw LrunE_string23

ptr_LrunE_string24:
 dw LrunE_string24

ptr_LrunE_string25:
 dw LrunE_string25

ptr_LrunE_string26:
 dw seg_LrunE_start

ptr_LrunE_string27:
 dw seg_LrunE_start

ptr_LrunE_string28:
 dw seg_LrunE_start

ptr_LrunE_string29:
 dw seg_LrunE_start

ptr_LrunE_string30:
 dw LrunE_string30

ptr_LrunE_string31:
 dw seg_LrunE_start

ptr_LrunE_string32:
 dw seg_LrunE_start

seg_LrunE_header_end:
seg_LrunE_strings_start:

LrunE_string1:
 db "The service runway is the obvious escape route from the Arkangelsk chemical weapons facility.\n"; db $0
align(4)

LrunE_string2:
 db "006 knew this was going to be a risky mission. His sacrifice should give you enough time to find an aircraft.\n\nKeep a cool head and you'll get out alive. Just be certain to knock out the heavy gun emplacements and missile battery or they'll swat you out of the air like a silly fly.\n"; db $0
align(4)

LrunE_string3:
 db "No time for gadgets here, 007. Just improvise with what you can find close to hand.\n"; db $0
align(4)

LrunE_string4:
 db "Grace under pressure, as always, James. \n"; db $0
align(4)

LrunE_string5:
 db "Find plane ignition key\n"; db $0
align(4)

LrunE_string6:
 db "Destroy heavy gun emplacements\n"; db $0
align(4)

LrunE_string7:
 db "Destroy missile battery\n"; db $0
align(4)

LrunE_string8:
 db "Escape in plane\n"; db $0
align(4)

LrunE_string9:
 db "You do not have the aircraft ignition key.\n"; db $0
align(4)

LrunE_string10:
 db "Plane destroyed!\n"; db $0
align(4)

LrunE_string11:
 db "R U N W A Y\n"; db $0
align(4)

LrunE_string12:
 db "the service runway is the obvious escape route from the arkangelsk chemical weapons facility.\n"; db $0
align(4)

LrunE_string13:
 db "006 knew this was going to be a risky mission. his sacrifice should give you enough time to find an aircraft.\n\nkeep a cool head and you'll get out alive. just be certain to knock out the heavy gun emplacements and missile battery or they'll swat you out of the air like a silly fly.\n"; db $0
align(4)

LrunE_string14:
 db "no time for gadgets here, 007. just improvise with what you can find close to hand.\n"; db $0
align(4)

LrunE_string15:
 db "grace under pressure, as always, james. \n"; db $0
align(4)

LrunE_string16:
 db "find plane ignition key\n"; db $0
align(4)

LrunE_string17:
 db "destroy heavy gun emplacements\n"; db $0
align(4)

LrunE_string18:
 db "destroy missile battery\n"; db $0
align(4)

LrunE_string19:
 db "escape in plane\n"; db $0
align(4)

LrunE_string20:
 db "Runway, Chemical Weapons Facility#2\n"; db $0
align(4)

LrunE_string21:
 db "\n"; db $0
align(4)

LrunE_string22:
 db "ignition key\n"; db $0
align(4)

LrunE_string23:
 db "ignition key\n"; db $0
align(4)

LrunE_string24:
 db "ignition key\n"; db $0
align(4)

LrunE_string25:
db "Picked up an ignition key.\n"; db $0
align(4)

LrunE_string30:
db "This door leads back\ninto the gasplant!\n"; db $0
align(16)


seg_LrunE_strings_end:
seg_LrunE_end:

