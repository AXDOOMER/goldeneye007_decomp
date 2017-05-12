arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LpropobjE.bin", create

base $00000000
seg_LpropobjE_start:
seg_LpropobjE_header_start:

ptr_LpropobjE_string1:
 dw LpropobjE_string1

ptr_LpropobjE_string2:
 dw LpropobjE_string2

ptr_LpropobjE_string3:
 dw LpropobjE_string3

ptr_LpropobjE_string4:
 dw LpropobjE_string4

ptr_LpropobjE_string5:
 dw LpropobjE_string5

ptr_LpropobjE_string6:
 dw LpropobjE_string6

ptr_LpropobjE_string7:
 dw LpropobjE_string7

ptr_LpropobjE_string8:
 dw LpropobjE_string8

ptr_LpropobjE_string9:
 dw LpropobjE_string9

ptr_LpropobjE_string10:
 dw LpropobjE_string10

ptr_LpropobjE_string11:
 dw LpropobjE_string11

ptr_LpropobjE_string12:
 dw LpropobjE_string12

ptr_LpropobjE_string13:
 dw LpropobjE_string13

ptr_LpropobjE_string14:
 dw LpropobjE_string14

ptr_LpropobjE_string15:
 dw LpropobjE_string15

ptr_LpropobjE_string16:
 dw LpropobjE_string16

ptr_LpropobjE_string17:
 dw LpropobjE_string17

ptr_LpropobjE_string18:
 dw LpropobjE_string18

ptr_LpropobjE_string19:
 dw LpropobjE_string19

ptr_LpropobjE_string20:
 dw LpropobjE_string20

ptr_LpropobjE_string21:
 dw LpropobjE_string21

ptr_LpropobjE_string22:
 dw LpropobjE_string22

ptr_LpropobjE_string23:
 dw LpropobjE_string23

ptr_LpropobjE_string24:
 dw LpropobjE_string24

ptr_LpropobjE_string25:
 dw LpropobjE_string25

ptr_LpropobjE_string26:
 dw LpropobjE_string26

ptr_LpropobjE_string27:
 dw LpropobjE_string27

ptr_LpropobjE_string28:
 dw LpropobjE_string28

ptr_LpropobjE_string29:
 dw LpropobjE_string29

ptr_LpropobjE_string30:
 dw LpropobjE_string30

ptr_LpropobjE_string31:
 dw LpropobjE_string31

ptr_LpropobjE_string32:
 dw LpropobjE_string32

ptr_LpropobjE_string33:
 dw LpropobjE_string33

ptr_LpropobjE_string34:
 dw LpropobjE_string34

ptr_LpropobjE_string35:
 dw LpropobjE_string35

ptr_LpropobjE_string36:
 dw LpropobjE_string36

ptr_LpropobjE_string37:
 dw LpropobjE_string37

ptr_LpropobjE_string38:
 dw LpropobjE_string38

ptr_LpropobjE_string39:
 dw LpropobjE_string39

ptr_LpropobjE_string40:
 dw LpropobjE_string40

ptr_LpropobjE_string41:
 dw LpropobjE_string41

ptr_LpropobjE_string42:
 dw LpropobjE_string42

ptr_LpropobjE_string43:
 dw LpropobjE_string43

ptr_LpropobjE_string44:
 dw LpropobjE_string44

ptr_LpropobjE_string45:
 dw LpropobjE_string45

ptr_LpropobjE_string46:
 dw LpropobjE_string46

ptr_LpropobjE_string47:
 dw LpropobjE_string47

ptr_LpropobjE_string48:
 dw LpropobjE_string48

ptr_LpropobjE_string49:
 dw LpropobjE_string49

ptr_LpropobjE_string50:
 dw LpropobjE_string50

ptr_LpropobjE_string51:
 dw LpropobjE_string51

ptr_LpropobjE_string52:
 dw LpropobjE_string52

ptr_LpropobjE_string53:
 dw LpropobjE_string53

ptr_LpropobjE_string54:
 dw LpropobjE_string54

ptr_LpropobjE_string55:
 dw LpropobjE_string55

ptr_LpropobjE_string56:
 dw LpropobjE_string56

ptr_LpropobjE_string57:
 dw LpropobjE_string57

ptr_LpropobjE_string58:
 dw LpropobjE_string58

ptr_LpropobjE_string59:
 dw LpropobjE_string59

ptr_LpropobjE_string60:
 dw LpropobjE_string60

ptr_LpropobjE_string61:
 dw LpropobjE_string61

ptr_LpropobjE_string62:
 dw LpropobjE_string62

ptr_LpropobjE_string63:
 dw LpropobjE_string63

ptr_LpropobjE_string64:
 dw LpropobjE_string64

ptr_LpropobjE_string65:
 dw LpropobjE_string65

ptr_LpropobjE_string66:
 dw seg_LpropobjE_start

ptr_LpropobjE_string67:
 dw seg_LpropobjE_start

ptr_LpropobjE_string68:
 dw seg_LpropobjE_start

seg_LpropobjE_header_end:
seg_LpropobjE_strings_start:

LpropobjE_string1:
 db "Picked up "; db $0
align(4)

LpropobjE_string2:
 db "some "; db $0
align(4)

LpropobjE_string3:
 db "a "; db $0
align(4)

LpropobjE_string4:
 db "an "; db $0
align(4)

LpropobjE_string5:
 db "the "; db $0
align(4)

LpropobjE_string6:
 db "ammo"; db $0
align(4)

LpropobjE_string7:
 db "shotgun cartridge"; db $0
align(4)

LpropobjE_string8:
 db "magnum bullet"; db $0
align(4)

LpropobjE_string9:
 db "golden bullet"; db $0
align(4)

LpropobjE_string10:
 db "hand grenade"; db $0
align(4)

LpropobjE_string11:
 db "grenade round"; db $0
align(4)

LpropobjE_string12:
 db "rocket"; db $0
align(4)

LpropobjE_string13:
 db "remote mine"; db $0
align(4)

LpropobjE_string14:
 db "proximity mine"; db $0
align(4)

LpropobjE_string15:
 db "timed mine"; db $0
align(4)

LpropobjE_string16:
 db "throwing "; db $0
align(4)

LpropobjE_string17:
 db "knife"; db $0
align(4)

LpropobjE_string18:
 db "knives"; db $0
align(4)

LpropobjE_string19:
 db "s"; db $0
align(4)

LpropobjE_string20:
 db "dart"; db $0
align(4)

LpropobjE_string21:
 db "explosive pen"; db $0
align(4)

LpropobjE_string22:
 db "explosive case"; db $0
align(4)

LpropobjE_string23:
 db "flare"; db $0
align(4)

LpropobjE_string24:
 db "piton"; db $0
align(4)

LpropobjE_string25:
 db "of dynamite"; db $0
align(4)

LpropobjE_string26:
 db "stick "; db $0
align(4)

LpropobjE_string27:
 db "sticks "; db $0
align(4)

LpropobjE_string28:
 db "bug"; db $0
align(4)

LpropobjE_string29:
 db "micro camera"; db $0
align(4)

LpropobjE_string30:
 db "GoldenEye key"; db $0
align(4)

LpropobjE_string31:
 db "token"; db $0
align(4)

LpropobjE_string32:
 db "plastique"; db $0
align(4)

LpropobjE_string33:
 db "a hunting knife.\n"; db $0
align(4)

LpropobjE_string34:
 db "a PP7.\n"; db $0
align(4)

LpropobjE_string35:
 db "a silenced PP7.\n"; db $0
align(4)

LpropobjE_string36:
 db "a DD44 Dostovei.\n"; db $0
align(4)

LpropobjE_string37:
 db "a Klobb.\n"; db $0
align(4)

LpropobjE_string38:
 db "a KF7 Soviet.\n"; db $0
align(4)

LpropobjE_string39:
 db "a ZMG (9mm).\n"; db $0
align(4)

LpropobjE_string40:
 db "a D5K Deutsche.\n"; db $0
align(4)

LpropobjE_string41:
 db "a silenced D5K.\n"; db $0
align(4)

LpropobjE_string42:
 db "a Phantom.\n"; db $0
align(4)

LpropobjE_string43:
 db "an AR33 assault rifle.\n"; db $0
align(4)

LpropobjE_string44:
 db "an RC-P90.\n"; db $0
align(4)

LpropobjE_string45:
 db "a shotgun.\n"; db $0
align(4)

LpropobjE_string46:
 db "an automatic shotgun.\n"; db $0
align(4)

LpropobjE_string47:
 db "a sniper rifle.\n"; db $0
align(4)

LpropobjE_string48:
 db "a grenade launcher.\n"; db $0
align(4)

LpropobjE_string49:
 db "a rocket launcher.\n"; db $0
align(4)

LpropobjE_string50:
 db "a Cougar Magnum.\n"; db $0
align(4)

LpropobjE_string51:
 db "the Golden Gun.\n"; db $0
align(4)

LpropobjE_string52:
 db "a Moonraker laser.\n"; db $0
align(4)

LpropobjE_string53:
 db "a flare pistol.\n"; db $0
align(4)

LpropobjE_string54:
 db "a piton gun.\n"; db $0
align(4)

LpropobjE_string55:
 db "a silver PP7.\n"; db $0
align(4)

LpropobjE_string56:
 db "a gold PP7.\n"; db $0
align(4)

LpropobjE_string57:
 db "a keycard.\n"; db $0
align(4)

LpropobjE_string58:
 db "a yale key.\n"; db $0
align(4)

LpropobjE_string59:
 db "a bolt key.\n"; db $0
align(4)

LpropobjE_string60:
 db "a new weapon.\n"; db $0
align(4)

LpropobjE_string61:
 db "Picked up a key.\n"; db $0
align(4)

LpropobjE_string62:
 db "Picked up some body armor.\n"; db $0
align(4)

LpropobjE_string63:
 db "body armor.\n"; db $0
align(4)

LpropobjE_string64:
 db "Picked up something.\n"; db $0
align(4)

LpropobjE_string65:
 db "This door is locked.\n"; db $0
align(16)

seg_LpropobjE_strings_end:
seg_LpropobjE_end:

