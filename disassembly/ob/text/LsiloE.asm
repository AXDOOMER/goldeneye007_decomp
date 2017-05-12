arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LsiloE.bin", create

base $00000000
seg_LsiloE_start:
seg_LsiloE_header_start:

ptr_LsiloE_string1:
 dw LsiloE_string1

ptr_LsiloE_string2:
 dw LsiloE_string2

ptr_LsiloE_string3:
 dw LsiloE_string3

ptr_LsiloE_string4:
 dw LsiloE_string4

ptr_LsiloE_string5:
 dw LsiloE_string5

ptr_LsiloE_string6:
 dw LsiloE_string6

ptr_LsiloE_string7:
 dw LsiloE_string7

ptr_LsiloE_string8:
 dw LsiloE_string8

ptr_LsiloE_string9:
 dw LsiloE_string9

ptr_LsiloE_string10:
 dw LsiloE_string10

ptr_LsiloE_string11:
 dw LsiloE_string11

ptr_LsiloE_string12:
 dw LsiloE_string12

ptr_LsiloE_string13:
 dw LsiloE_string13

ptr_LsiloE_string14:
 dw LsiloE_string14

ptr_LsiloE_string15:
 dw LsiloE_string15

ptr_LsiloE_string16:
 dw LsiloE_string16

ptr_LsiloE_string17:
 dw LsiloE_string17

ptr_LsiloE_string18:
 dw LsiloE_string18

ptr_LsiloE_string19:
 dw LsiloE_string19

ptr_LsiloE_string20:
 dw LsiloE_string20

ptr_LsiloE_string21:
 dw LsiloE_string21

ptr_LsiloE_string22:
 dw LsiloE_string22

ptr_LsiloE_string23:
 dw LsiloE_string23

ptr_LsiloE_string24:
 dw LsiloE_string24

ptr_LsiloE_string25:
 dw LsiloE_string25

ptr_LsiloE_string26:
 dw LsiloE_string26

ptr_LsiloE_string27:
 dw LsiloE_string27

ptr_LsiloE_string28:
 dw LsiloE_string28

ptr_LsiloE_string29:
 dw LsiloE_string29

ptr_LsiloE_string30:
 dw LsiloE_string30

ptr_LsiloE_string31:
 dw LsiloE_string31

ptr_LsiloE_string32:
 dw LsiloE_string32

ptr_LsiloE_string33:
 dw LsiloE_string33

ptr_LsiloE_string34:
 dw LsiloE_string34

ptr_LsiloE_string35:
 dw LsiloE_string35

ptr_LsiloE_string36:
 dw LsiloE_string36

ptr_LsiloE_string37:
 dw LsiloE_string37

ptr_LsiloE_string38:
 dw LsiloE_string38

ptr_LsiloE_string39:
 dw LsiloE_string39

ptr_LsiloE_string40:
 dw LsiloE_string40

ptr_LsiloE_string41:
 dw LsiloE_string41

ptr_LsiloE_string42:
 dw LsiloE_string42

ptr_LsiloE_string43:
 dw LsiloE_string43

ptr_LsiloE_string44:
 dw LsiloE_string44

ptr_LsiloE_string45:
 dw LsiloE_string45

ptr_LsiloE_string46:
 dw LsiloE_string46

ptr_LsiloE_string47:
 dw LsiloE_string47

ptr_LsiloE_string48:
 dw LsiloE_string48

ptr_LsiloE_string49:
 dw LsiloE_string49

ptr_LsiloE_string50:
 dw LsiloE_string50

ptr_LsiloE_string51:
 dw LsiloE_string51

ptr_LsiloE_string52:
 dw LsiloE_string52

ptr_LsiloE_string53:
 dw LsiloE_string53

ptr_LsiloE_string54:
 dw LsiloE_string54

ptr_LsiloE_string55:
 dw LsiloE_string55

ptr_LsiloE_string56:
 dw LsiloE_string56

ptr_LsiloE_string57:
 dw LsiloE_string57

ptr_LsiloE_string58:
 dw LsiloE_string58

ptr_LsiloE_string59:
 dw LsiloE_string59

ptr_LsiloE_string60:
 dw LsiloE_string60

ptr_LsiloE_string61:
 dw LsiloE_string61

ptr_LsiloE_string62:
 dw LsiloE_string62

ptr_LsiloE_string63:
 dw LsiloE_string63

ptr_LsiloE_string64:
 dw LsiloE_string64

ptr_LsiloE_string65:
 dw LsiloE_string65

ptr_LsiloE_string66:
 dw LsiloE_string66

ptr_LsiloE_string67:
 dw LsiloE_string67

ptr_LsiloE_string68:
 dw LsiloE_string68

ptr_LsiloE_string69:
 dw LsiloE_string69

ptr_LsiloE_string70:
 dw LsiloE_string70

ptr_LsiloE_string71:
 dw LsiloE_string71

ptr_LsiloE_string72:
 dw seg_LsiloE_start

seg_LsiloE_header_end:
seg_LsiloE_strings_start:

LsiloE_string1:
 db "MI6 has become concerned that unscheduled test firings from a missile silo in Kirghizstan are being used to cover the launch of Goldeneye weapons satellites.\n\nDeep intelligence reports suggest that this operation may well be outside the control of the former Soviet powers in the region."; db $0
align(4)

LsiloE_string2:
 db "Infiltrate the silo and ascertain what is being placed into orbit; if it is the satellites, recover their control circuitry and sabotage the launches. You are authorized to destroy the base if necessary.\n\nThis is a matter of international security, 007. Consider the military personnel expendable.\n"; db $0
align(4)

LsiloE_string3:
 db "The layout of the missile silo means that a few carefully placed explosive charges will destroy the entire complex - concentrate on the fuel rooms (H4, C3, K2 and A1). 007, remember to treat the timed explosives with respect - you know what happened to 004 in Beirut.\n\nOh, and get me a picture of the satellite, there's a good chap.\n"; db $0
align(4)

LsiloE_string4:
 db "You leave at 1800 hours for Bishkek.\n\nJames, just imagine those romantic nights in the steppes. Lying beneath the stars, the campfires twinkling on the hills - sounds like heaven. When you're in the arms of some dusky maiden, spare a thought for poor old me cooped up behind a desk in rainy London."; db $0
align(4)

LsiloE_string5:
 db "Plant bombs in fuel rooms\n"; db $0
align(4)

LsiloE_string6:
 db "Photograph satellite\n"; db $0
align(4)

LsiloE_string7:
 db "Obtain telemetric data\n"; db $0
align(4)

LsiloE_string8:
 db "Retrieve satellite circuitry\n"; db $0
align(4)

LsiloE_string9:
 db "Minimize scientist casualties\n"; db $0
align(4)

LsiloE_string10:
 db "Explosive charge placed -\n              6 minutes to detonation!\n"; db $0
align(4)

LsiloE_string11:
 db "Ourumov: Kill him!\n"; db $0
align(4)

LsiloE_string12:
 db "Caution: Detonation imminent!\n"; db $0
align(4)

LsiloE_string13:
 db "Mission Failure: Unacceptable non-military\ncasualties!\n"; db $0
align(4)

LsiloE_string14:
 db "K I R G H I Z S T A N\n"; db $0
align(4)

LsiloE_string15:
 db "MI6 has become concerned that unscheduled test firings from a missile silo in kirghizstan are being used to cover the launch of goldeneye weapons satellites.\n\ndeep intelligence reports suggest that this operation may well be outside the control of the former soviet powers in the region."; db $0
align(4)

LsiloE_string16:
 db "infiltrate the silo and ascertain what is being placed into orbit;\nif it is the satellites, recover their control circuitry and sabotage the launches. you are authorized to destroy the base if necessary.\n\nthis is a matter of international security, 007. consider the military personnel expendable.\n"; db $0
align(4)

LsiloE_string17:
 db "the layout of the missile silo means that a few carefully placed explosive charges will destroy the entire complex -\nconcentrate on the fuel rooms\n      (H4, C3, K2 and A1).\n\n007, remember to treat the timed explosives with respect - you know what happened to 004 in beirut.\n\noh, and get me a picture of the satellite, there's a good chap.\n"; db $0
align(4)

LsiloE_string18:
 db "you leave at 1800 hours for bishkek.\n\njames, just imagine those romantic nights in the steppes. lying beneath the stars, the campfires twinkling on the hills - sounds like heaven. when you're in the arms of some dusky maiden, spare a thought for poor old me cooped up behind a desk in rainy london."; db $0
align(4)

LsiloE_string19:
 db "plant bombs in fuel rooms\n"; db $0
align(4)

LsiloE_string20:
 db "photograph satellite\n"; db $0
align(4)

LsiloE_string21:
 db "obtain telemetric data\n"; db $0
align(4)

LsiloE_string22:
 db "retrieve satellite circuitry\n"; db $0
align(4)

LsiloE_string23:
 db "minimize scientist casualties\n"; db $0
align(4)

LsiloE_string24:
 db "\n"; db $0
align(4)

LsiloE_string25:
 db "cpu circuitry\n"; db $0
align(4)

LsiloE_string26:
 db "cpu circuit board\n"; db $0
align(4)

LsiloE_string27:
 db "CPU Circuit Board\n"; db $0
align(4)

LsiloE_string28:
 db "Picked up a circuit board\n"; db $0
align(4)

LsiloE_string29:
 db "\n"; db $0
align(4)

LsiloE_string30:
 db "i/o circuitry\n"; db $0
align(4)

LsiloE_string31:
 db "i/o circuit board\n"; db $0
align(4)

LsiloE_string32:
 db "I/O Circuit Board\n"; db $0
align(4)

LsiloE_string33:
 db "Picked up a circuit board\n"; db $0
align(4)

LsiloE_string34:
 db "\n"; db $0
align(4)

LsiloE_string35:
 db "rsp circuitry\n"; db $0
align(4)

LsiloE_string36:
 db "rsp circuit board\n"; db $0
align(4)

LsiloE_string37:
 db "RSP Circuit Board\n"; db $0
align(4)

LsiloE_string38:
 db "Picked up a circuit board\n"; db $0
align(4)

LsiloE_string39:
 db "\n"; db $0
align(4)

LsiloE_string40:
 db "rdp circuitry\n"; db $0
align(4)

LsiloE_string41:
 db "rdp circuit board\n"; db $0
align(4)

LsiloE_string42:
 db "RDP Circuit Board\n"; db $0
align(4)

LsiloE_string43:
 db "Picked up a circuit board\n"; db $0
align(4)

LsiloE_string44:
 db "\n"; db $0
align(4)

LsiloE_string45:
 db "DAT\n"; db $0
align(4)

LsiloE_string46:
 db "telemetry data DAT\n"; db $0
align(4)

LsiloE_string47:
 db "DAT - Telemetry Data\n"; db $0
align(4)

LsiloE_string48:
 db "Picked up a DAT\n"; db $0
align(4)

LsiloE_string49:
 db "\n"; db $0
align(4)

LsiloE_string50:
 db "keycard\n"; db $0
align(4)

LsiloE_string51:
 db "keycard 4-H4\n"; db $0
align(4)

LsiloE_string52:
 db "Keycard (Level 4-H4)\n"; db $0
align(4)

LsiloE_string53:
 db "Picked up a keycard.\n"; db $0
align(4)

LsiloE_string54:
 db "\n"; db $0
align(4)

LsiloE_string55:
 db "keycard\n"; db $0
align(4)

LsiloE_string56:
 db "keycard 4-C3\n"; db $0
align(4)

LsiloE_string57:
 db "Keycard (Level 4-C3)\n"; db $0
align(4)

LsiloE_string58:
 db "Picked up a keycard.\n"; db $0
align(4)

LsiloE_string59:
 db "\n"; db $0
align(4)

LsiloE_string60:
 db "keycard\n"; db $0
align(4)

LsiloE_string61:
 db "keycard 4-K2\n"; db $0
align(4)

LsiloE_string62:
 db "Keycard (Level 4-K2)\n"; db $0
align(4)

LsiloE_string63:
 db "Picked up a keycard.\n"; db $0
align(4)

LsiloE_string64:
 db "Ourumov's\n"; db $0
align(4)

LsiloE_string65:
 db "briefcase\n"; db $0
align(4)

LsiloE_string66:
 db "ourumov's briefcase\n"; db $0
align(4)

LsiloE_string67:
 db "Ourumov's Briefcase\n"; db $0
align(4)

LsiloE_string68:
 db "Picked up Ourumov's briefcase.\n"; db $0
align(4)

LsiloE_string69:
 db "Soviet Missile Silo, Kirghizstan\n"; db $0
align(4)

LsiloE_string70:
 db "Two years ago\n"; db $0
align(4)

LsiloE_string71:
db "Silo infiltrated -\nexplosive charges automatically primed!\n"; db $0
align(16)

seg_LsiloE_strings_end:
seg_LsiloE_end:

