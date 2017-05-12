arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LoptionsE.bin", create

base $00000000
seg_LoptionsE_start:
seg_LoptionsE_header_start:

ptr_LoptionsE_string1:
 dw LoptionsE_string1

ptr_LoptionsE_string2:
 dw LoptionsE_string2

ptr_LoptionsE_string3:
 dw LoptionsE_string3

ptr_LoptionsE_string4:
 dw LoptionsE_string4

ptr_LoptionsE_string5:
 dw LoptionsE_string5

ptr_LoptionsE_string6:
 dw LoptionsE_string6

ptr_LoptionsE_string7:
 dw LoptionsE_string7

ptr_LoptionsE_string8:
 dw LoptionsE_string8

ptr_LoptionsE_string9:
 dw LoptionsE_string9

ptr_LoptionsE_string10:
 dw LoptionsE_string10

ptr_LoptionsE_string11:
 dw LoptionsE_string11

ptr_LoptionsE_string12:
 dw LoptionsE_string12

ptr_LoptionsE_string13:
 dw LoptionsE_string13

ptr_LoptionsE_string14:
 dw LoptionsE_string14

ptr_LoptionsE_string15:
 dw LoptionsE_string15

ptr_LoptionsE_string16:
 dw LoptionsE_string16

ptr_LoptionsE_string17:
 dw LoptionsE_string17

ptr_LoptionsE_string18:
 dw LoptionsE_string18

ptr_LoptionsE_string19:
 dw LoptionsE_string19

ptr_LoptionsE_string20:
 dw LoptionsE_string20

ptr_LoptionsE_string21:
 dw LoptionsE_string21

ptr_LoptionsE_string22:
 dw LoptionsE_string22

ptr_LoptionsE_string23:
 dw LoptionsE_string23

ptr_LoptionsE_string24:
 dw LoptionsE_string24

ptr_LoptionsE_string25:
 dw LoptionsE_string25

ptr_LoptionsE_string26:
 dw LoptionsE_string26

ptr_LoptionsE_string27:
 dw LoptionsE_string27

ptr_LoptionsE_string28:
 dw LoptionsE_string28

ptr_LoptionsE_string29:
 dw LoptionsE_string29

ptr_LoptionsE_string30:
 dw LoptionsE_string30

ptr_LoptionsE_string31:
 dw LoptionsE_string31

ptr_LoptionsE_string32:
 dw LoptionsE_string32

ptr_LoptionsE_string33:
 dw LoptionsE_string33

ptr_LoptionsE_string34:
 dw LoptionsE_string34

ptr_LoptionsE_string35:
 dw LoptionsE_string35

ptr_LoptionsE_string36:
 dw LoptionsE_string36

ptr_LoptionsE_string37:
 dw LoptionsE_string37

ptr_LoptionsE_string38:
 dw LoptionsE_string38

ptr_LoptionsE_string39:
 dw LoptionsE_string39

ptr_LoptionsE_string40:
 dw LoptionsE_string40

ptr_LoptionsE_string41:
 dw LoptionsE_string41

ptr_LoptionsE_string42:
 dw LoptionsE_string42

ptr_LoptionsE_string43:
 dw LoptionsE_string43

ptr_LoptionsE_string44:
 dw LoptionsE_string44

ptr_LoptionsE_string45:
 dw LoptionsE_string45

ptr_LoptionsE_string46:
 dw LoptionsE_string46

ptr_LoptionsE_string47:
 dw LoptionsE_string47

ptr_LoptionsE_string48:
 dw LoptionsE_string48

ptr_LoptionsE_string49:
 dw LoptionsE_string49

ptr_LoptionsE_string50:
 dw LoptionsE_string50

ptr_LoptionsE_string51:
 dw LoptionsE_string51

ptr_LoptionsE_string52:
 dw LoptionsE_string52

ptr_LoptionsE_string53:
 dw LoptionsE_string53

ptr_LoptionsE_string54:
 dw LoptionsE_string54

ptr_LoptionsE_string55:
 dw LoptionsE_string55

ptr_LoptionsE_string56:
 dw LoptionsE_string56

ptr_LoptionsE_string57:
 dw LoptionsE_string57

ptr_LoptionsE_string58:
 dw LoptionsE_string58

ptr_LoptionsE_string59:
 dw LoptionsE_string59

ptr_LoptionsE_string60:
 dw LoptionsE_string60

ptr_LoptionsE_string61:
 dw LoptionsE_string61

ptr_LoptionsE_string62:
 dw seg_LoptionsE_start

ptr_LoptionsE_string63:
 dw seg_LoptionsE_start

ptr_LoptionsE_string64:
 dw seg_LoptionsE_start

seg_LoptionsE_header_end:
seg_LoptionsE_strings_start:

LoptionsE_string1:
 db "fire\n"; db $0
align(4)

LoptionsE_string2:
 db "aim\n"; db $0
align(4)

LoptionsE_string3:
 db "action\n"; db $0
align(4)

LoptionsE_string4:
 db "weapon\n"; db $0
align(4)

LoptionsE_string5:
 db "pause\n"; db $0
align(4)

LoptionsE_string6:
 db "move\n"; db $0
align(4)

LoptionsE_string7:
 db "look\n"; db $0
align(4)

LoptionsE_string8:
 db "?\n"; db $0
align(4)

LoptionsE_string9:
 db "move sight\n"; db $0
align(4)

LoptionsE_string10:
 db "1.1 honey\n"; db $0
align(4)

LoptionsE_string11:
 db "1.2 solitaire\n"; db $0
align(4)

LoptionsE_string12:
 db "1.3 kissy\n"; db $0
align(4)

LoptionsE_string13:
 db "1.4 goodnight\n"; db $0
align(4)

LoptionsE_string14:
 db "2.1 plenty\n"; db $0
align(4)

LoptionsE_string15:
 db "2.2 galore\n"; db $0
align(4)

LoptionsE_string16:
 db "2.3 domino\n"; db $0
align(4)

LoptionsE_string17:
 db "2.4 goodhead\n"; db $0
align(4)

LoptionsE_string18:
 db "look up/down\n"; db $0
align(4)

LoptionsE_string19:
 db "auto-aim\n"; db $0
align(4)

LoptionsE_string20:
 db "look ahead\n"; db $0
align(4)

LoptionsE_string21:
 db "aim control\n"; db $0
align(4)

LoptionsE_string22:
 db "sight on-screen\n"; db $0
align(4)

LoptionsE_string23:
 db "ammo on-screen\n"; db $0
align(4)

LoptionsE_string24:
 db "screen\n"; db $0
align(4)

LoptionsE_string25:
 db "ratio\n"; db $0
align(4)

LoptionsE_string26:
 db "on\n"; db $0
align(4)

LoptionsE_string27:
 db "off\n"; db $0
align(4)

LoptionsE_string28:
 db "upright\n"; db $0
align(4)

LoptionsE_string29:
 db "reverse\n"; db $0
align(4)

LoptionsE_string30:
 db "toggle\n"; db $0
align(4)

LoptionsE_string31:
 db "hold\n"; db $0
align(4)

LoptionsE_string32:
 db "full\n"; db $0
align(4)

LoptionsE_string33:
 db "wide\n"; db $0
align(4)

LoptionsE_string34:
 db "cinema\n"; db $0
align(4)

LoptionsE_string35:
 db "normal\n"; db $0
align(4)

LoptionsE_string36:
 db "16:9\n"; db $0
align(4)

LoptionsE_string37:
 db "abort:\n"; db $0
align(4)

LoptionsE_string38:
 db "confirm\n"; db $0
align(4)

LoptionsE_string39:
 db "cancel\n"; db $0
align(4)

LoptionsE_string40:
 db "mission status:\n"; db $0
align(4)

LoptionsE_string41:
 db "complete\n"; db $0
align(4)

LoptionsE_string42:
 db "incomplete\n"; db $0
align(4)

LoptionsE_string43:
 db "Left Hand\n"; db $0
align(4)

LoptionsE_string44:
 db "q watch v2.01 beta\n"; db $0
align(4)

LoptionsE_string45:
 db "down\n"; db $0
align(4)

LoptionsE_string46:
 db "up\n"; db $0
align(4)

LoptionsE_string47:
 db "sidestep\n"; db $0
align(4)

LoptionsE_string48:
 db "sidestep\n"; db $0
align(4)

LoptionsE_string49:
 db "forward\n"; db $0
align(4)

LoptionsE_string50:
 db "back\n"; db $0
align(4)

LoptionsE_string51:
 db "control style\n"; db $0
align(4)

LoptionsE_string52:
 db "controller\n"; db $0
align(4)

LoptionsE_string53:
 db "controllers\n"; db $0
align(4)

LoptionsE_string54:
 db "music\n"; db $0
align(4)

LoptionsE_string55:
 db "fx\n"; db $0
align(4)

LoptionsE_string56:
 db "failed\n"; db $0
align(4)

LoptionsE_string57:
 db "2. background\n"; db $0
align(4)

LoptionsE_string58:
 db "3. M briefing\n"; db $0
align(4)

LoptionsE_string59:
 db "4. Q branch\n"; db $0
align(4)

LoptionsE_string60:
 db "5. moneypenny\n"; db $0
align(4)

LoptionsE_string61:
db "1. mission objectives\n"; db $0
align(4)

db $0; align(16)

seg_LoptionsE_strings_end:
seg_LoptionsE_end:

