arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LmiscE.bin", create

base $00000000
seg_LmiscE_start:
seg_LmiscE_header_start:

ptr_LmiscE_string1:
 dw LmiscE_string1

ptr_LmiscE_string2:
 dw LmiscE_string2

ptr_LmiscE_string3:
 dw LmiscE_string3

ptr_LmiscE_string4:
 dw LmiscE_string4

ptr_LmiscE_string5:
 dw LmiscE_string5

ptr_LmiscE_string6:
 dw LmiscE_string6

ptr_LmiscE_string7:
 dw LmiscE_string7

ptr_LmiscE_string8:
 dw LmiscE_string8

ptr_LmiscE_string9:
 dw LmiscE_string9

ptr_LmiscE_string10:
 dw LmiscE_string10

ptr_LmiscE_string11:
 dw LmiscE_string11

ptr_LmiscE_string12:
 dw LmiscE_string12

ptr_LmiscE_string13:
 dw LmiscE_string13

ptr_LmiscE_string14:
 dw LmiscE_string14

ptr_LmiscE_string15:
 dw LmiscE_string15

ptr_LmiscE_string16:
 dw LmiscE_string16

ptr_LmiscE_string17:
 dw LmiscE_string17

ptr_LmiscE_string18:
 dw LmiscE_string18

ptr_LmiscE_string19:
 dw LmiscE_string19

ptr_LmiscE_string20:
 dw LmiscE_string20

ptr_LmiscE_string21:
 dw LmiscE_string21

ptr_LmiscE_string22:
 dw LmiscE_string22

ptr_LmiscE_string23:
 dw LmiscE_string23

ptr_LmiscE_string24:
 dw LmiscE_string24

ptr_LmiscE_string25:
 dw LmiscE_string25

ptr_LmiscE_string26:
 dw LmiscE_string26

ptr_LmiscE_string27:
 dw LmiscE_string27

ptr_LmiscE_string28:
 dw LmiscE_string28

ptr_LmiscE_string29:
 dw LmiscE_string29

ptr_LmiscE_string30:
 dw LmiscE_string30

ptr_LmiscE_string31:
 dw LmiscE_string31

ptr_LmiscE_string32:
 dw LmiscE_string32

ptr_LmiscE_string33:
 dw LmiscE_string33

ptr_LmiscE_string34:
 dw LmiscE_string34

ptr_LmiscE_string35:
 dw LmiscE_string35

ptr_LmiscE_string36:
 dw LmiscE_string36

ptr_LmiscE_string37:
 dw LmiscE_string37

ptr_LmiscE_string38:
 dw LmiscE_string38

ptr_LmiscE_string39:
 dw LmiscE_string39

ptr_LmiscE_string40:
 dw LmiscE_string40

ptr_LmiscE_string41:
 dw LmiscE_string41

ptr_LmiscE_string42:
 dw LmiscE_string42

ptr_LmiscE_string43:
 dw LmiscE_string43

ptr_LmiscE_string44:
 dw LmiscE_string44

ptr_LmiscE_string45:
 dw LmiscE_string45

ptr_LmiscE_string46:
 dw LmiscE_string46

ptr_LmiscE_string47:
 dw LmiscE_string47

ptr_LmiscE_string48:
 dw LmiscE_string48

ptr_LmiscE_string49:
 dw LmiscE_string49

ptr_LmiscE_string50:
 dw LmiscE_string50

ptr_LmiscE_string51:
 dw LmiscE_string51

ptr_LmiscE_string52:
 dw LmiscE_string52

ptr_LmiscE_string53:
 dw LmiscE_string53

ptr_LmiscE_string54:
 dw LmiscE_string54

ptr_LmiscE_string55:
 dw LmiscE_string55

ptr_LmiscE_string56:
 dw LmiscE_string56

ptr_LmiscE_string57:
 dw LmiscE_string57

ptr_LmiscE_string58:
 dw LmiscE_string58

ptr_LmiscE_string59:
 dw LmiscE_string59

ptr_LmiscE_string60:
 dw LmiscE_string60

ptr_LmiscE_string61:
 dw LmiscE_string61

ptr_LmiscE_string62:
 dw LmiscE_string62

ptr_LmiscE_string63:
 dw LmiscE_string63

ptr_LmiscE_string64:
 dw LmiscE_string64

ptr_LmiscE_string65:
 dw LmiscE_string65

ptr_LmiscE_string66:
 dw LmiscE_string66

ptr_LmiscE_string67:
 dw LmiscE_string67

ptr_LmiscE_string68:
 dw LmiscE_string68

seg_LmiscE_header_end:
seg_LmiscE_strings_start:

LmiscE_string1:
 db "Invincible"; db $0
align(4)

LmiscE_string2:
 db "All Guns"; db $0
align(4)

LmiscE_string3:
 db "Super x2 Health"; db $0
align(4)

LmiscE_string4:
 db "Super x2 Armor"; db $0
align(4)

LmiscE_string5:
 db "Bond Invisible"; db $0
align(4)

LmiscE_string6:
 db "Bond Phase"; db $0
align(4)

LmiscE_string7:
 db "Infinite Ammo"; db $0
align(4)

LmiscE_string8:
 db "DK Mode"; db $0
align(4)

LmiscE_string9:
 db "Tiny Bond"; db $0
align(4)

LmiscE_string10:
 db "Super x10 Health"; db $0
align(4)

LmiscE_string11:
 db "Magnum"; db $0
align(4)

LmiscE_string12:
 db "Laser"; db $0
align(4)

LmiscE_string13:
 db "Golden Gun"; db $0
align(4)

LmiscE_string14:
 db "Silver PP7"; db $0
align(4)

LmiscE_string15:
 db "Gold PP7"; db $0
align(4)

LmiscE_string16:
 db "invincibility on\n"; db $0
align(4)

LmiscE_string17:
 db "all guns on\n"; db $0
align(4)

LmiscE_string18:
 db "maximum ammo\n"; db $0
align(4)

LmiscE_string19:
 db "super x2 health\n"; db $0
align(4)

LmiscE_string20:
 db "super x2 armor\n"; db $0
align(4)

LmiscE_string21:
 db "invisibility on\n"; db $0
align(4)

LmiscE_string22:
 db "bond phase on\n"; db $0
align(4)

LmiscE_string23:
 db "infinite ammo on\n"; db $0
align(4)

LmiscE_string24:
 db "dk mode on\n"; db $0
align(4)

LmiscE_string25:
 db "extra weapons\n"; db $0
align(4)

LmiscE_string26:
 db "tiny bond on\n"; db $0
align(4)

LmiscE_string27:
 db "paintball mode on\n"; db $0
align(4)

LmiscE_string28:
 db "super x10 health\n"; db $0
align(4)

LmiscE_string29:
 db "happy now karl?\n"; db $0
align(4)

LmiscE_string30:
 db "fast mode on\n"; db $0
align(4)

LmiscE_string31:
 db "invincibility off\n"; db $0
align(4)

LmiscE_string32:
 db "all guns off\n"; db $0
align(4)

LmiscE_string33:
 db "invisibility off\n"; db $0
align(4)

LmiscE_string34:
 db "bond phase off\n"; db $0
align(4)

LmiscE_string35:
 db "infinite ammo off\n"; db $0
align(4)

LmiscE_string36:
 db "dk mode off\n"; db $0
align(4)

LmiscE_string37:
 db "tiny bond off\n"; db $0
align(4)

LmiscE_string38:
 db "paintball mode off\n"; db $0
align(4)

LmiscE_string39:
 db "radar on\n"; db $0
align(4)

LmiscE_string40:
 db "fast mode off\n"; db $0
align(4)

LmiscE_string41:
 db "NO NAME"; db $0
align(4)

LmiscE_string42:
 db "E R R O R\n"; db $0
align(4)

LmiscE_string43:
 db "no briefing for this mission\n"; db $0
align(4)

LmiscE_string44:
 db "\n"; db $0
align(4)

LmiscE_string45:
 db "objective"; db $0
align(4)

LmiscE_string46:
 db "completed\n"; db $0
align(4)

LmiscE_string47:
 db "incomplete\n"; db $0
align(4)

LmiscE_string48:
 db "failed\n"; db $0
align(4)

LmiscE_string49:
 db "slowest motion\n"; db $0
align(4)

LmiscE_string50:
 db "very slow motion\n"; db $0
align(4)

LmiscE_string51:
 db "slow motion\n"; db $0
align(4)

LmiscE_string52:
 db "normal motion\n"; db $0
align(4)

LmiscE_string53:
 db "fast motion\n"; db $0
align(4)

LmiscE_string54:
 db "very fast motion\n"; db $0
align(4)

LmiscE_string55:
 db "fastest motion\n"; db $0
align(4)

LmiscE_string56:
 db "Line Mode"; db $0
align(4)

LmiscE_string57:
 db "Paintball Mode"; db $0
align(4)

LmiscE_string58:
 db "Enemy Rockets"; db $0
align(4)

LmiscE_string59:
 db "2x Rocket L."; db $0
align(4)

LmiscE_string60:
 db "2x Grenade L."; db $0
align(4)

LmiscE_string61:
 db "2x RC-P90"; db $0
align(4)

LmiscE_string62:
 db "2x Throwing Knife"; db $0
align(4)

LmiscE_string63:
 db "2x Hunting Knife"; db $0
align(4)

LmiscE_string64:
 db "2x Laser"; db $0
align(4)

LmiscE_string65:
 db "Turbo Mode"; db $0
align(4)

LmiscE_string66:
 db "Fast Animation"; db $0
align(4)

LmiscE_string67:
 db "Slow Animation"; db $0
align(4)

LmiscE_string68:
 db "No Radar [Multi]"; db $0
align(16)

seg_LmiscE_strings_end:
seg_LmiscE_end:

