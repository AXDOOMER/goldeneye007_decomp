arch n64.cpu
endian msb
include "../BASS.INC"
output "LmpweaponsE.bin", create

base $00000000
seg_LmpweaponsE_start:
seg_LmpweaponsE_header_start:

ptr_LmpweaponsE_string1:
 dw LmpweaponsE_string1

ptr_LmpweaponsE_string2:
 dw LmpweaponsE_string2

ptr_LmpweaponsE_string3:
 dw LmpweaponsE_string3

ptr_LmpweaponsE_string4:
 dw LmpweaponsE_string4

ptr_LmpweaponsE_string5:
 dw LmpweaponsE_string5

ptr_LmpweaponsE_string6:
 dw LmpweaponsE_string6

ptr_LmpweaponsE_string7:
 dw LmpweaponsE_string7

ptr_LmpweaponsE_string8:
 dw LmpweaponsE_string8

ptr_LmpweaponsE_string9:
 dw LmpweaponsE_string9

ptr_LmpweaponsE_string10:
 dw LmpweaponsE_string10

ptr_LmpweaponsE_string11:
 dw LmpweaponsE_string11

ptr_LmpweaponsE_string12:
 dw LmpweaponsE_string12

ptr_LmpweaponsE_string13:
 dw LmpweaponsE_string13

ptr_LmpweaponsE_string14:
 dw LmpweaponsE_string14

ptr_LmpweaponsE_string15:
 dw seg_LmpweaponsE_start

ptr_LmpweaponsE_string16:
 dw seg_LmpweaponsE_start

seg_LmpweaponsE_header_end:
seg_LmpweaponsE_strings_start:

LmpweaponsE_string1:
 db "Slappers only!"; db $0
align(4)

LmpweaponsE_string2:
 db "Pistols"; db $0
align(4)

LmpweaponsE_string3:
 db "Automatics"; db $0
align(4)

LmpweaponsE_string4:
 db "Power Weapons"; db $0
align(4)

LmpweaponsE_string5:
 db "Sniper Rifles"; db $0
align(4)

LmpweaponsE_string6:
 db "Grenades"; db $0
align(4)

LmpweaponsE_string7:
 db "Remote Mines"; db $0
align(4)

LmpweaponsE_string8:
 db "Grenade Launchers"; db $0
align(4)

LmpweaponsE_string9:
 db "Timed Mines"; db $0
align(4)

LmpweaponsE_string10:
 db "Proximity Mines"; db $0
align(4)

LmpweaponsE_string11:
 db "Rockets"; db $0
align(4)

LmpweaponsE_string12:
 db "Lasers"; db $0
align(4)

LmpweaponsE_string13:
 db "Golden Gun"; db $0
align(4)

LmpweaponsE_string14:
db "Throwing Knives"; db $0
align(16)

seg_LmpweaponsE_strings_end:
seg_LmpweaponsE_end:

