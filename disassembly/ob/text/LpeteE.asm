arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LpeteE.bin", create

base $00000000
seg_LpeteE_start:
seg_LpeteE_header_start:

ptr_LpeteE_string1:
 dw LpeteE_string1

ptr_LpeteE_string2:
 dw LpeteE_string2

ptr_LpeteE_string3:
 dw LpeteE_string3

ptr_LpeteE_string4:
 dw LpeteE_string4

ptr_LpeteE_string5:
 dw LpeteE_string5

ptr_LpeteE_string6:
 dw LpeteE_string6

ptr_LpeteE_string7:
 dw LpeteE_string7

ptr_LpeteE_string8:
 dw LpeteE_string8

ptr_LpeteE_string9:
 dw LpeteE_string9

ptr_LpeteE_string10:
 dw LpeteE_string10

ptr_LpeteE_string11:
 dw LpeteE_string11

ptr_LpeteE_string12:
 dw LpeteE_string12

ptr_LpeteE_string13:
 dw LpeteE_string13

ptr_LpeteE_string14:
 dw LpeteE_string14

ptr_LpeteE_string15:
 dw LpeteE_string15

ptr_LpeteE_string16:
 dw LpeteE_string16

ptr_LpeteE_string17:
 dw LpeteE_string17

ptr_LpeteE_string18:
 dw LpeteE_string18

ptr_LpeteE_string19:
 dw LpeteE_string19

ptr_LpeteE_string20:
 dw LpeteE_string20

ptr_LpeteE_string21:
 dw LpeteE_string21

ptr_LpeteE_string22:
 dw LpeteE_string22

ptr_LpeteE_string23:
 dw LpeteE_string23

ptr_LpeteE_string24:
 dw LpeteE_string24

ptr_LpeteE_string25:
 dw LpeteE_string25

ptr_LpeteE_string26:
 dw LpeteE_string26

ptr_LpeteE_string27:
 dw LpeteE_string27

ptr_LpeteE_string28:
 dw LpeteE_string28

ptr_LpeteE_string29:
 dw LpeteE_string29

ptr_LpeteE_string30:
 dw seg_LpeteE_start

ptr_LpeteE_string31:
 dw seg_LpeteE_start

ptr_LpeteE_string32:
 dw seg_LpeteE_start

seg_LpeteE_header_end:
seg_LpeteE_strings_start:

LpeteE_string1:
 db "After escaping KGB interrogation at the military archives, Natalya has been recaptured by General Ourumov. She is being taken by car to the Janus operations base in St. Petersburg.\n"; db $0
align(4)

LpeteE_string2:
 db "Get after them, 007! We can't afford to let the trail go cold and the chances are they'll lead you straight to Trevelyan. Keep a clear head though, any civilian casualties on the streets of St. Petersburg could create an unfortunate international incident.\nWe believe that Valentin Zukovsky is still in the area - he may be able to help you.\n"; db $0
align(4)

LpeteE_string3:
 db "No gadgets this time, 007. Though you should be on the lookout for hardware the Russians may have left lying around. Keys in the ignition and all that, old chap.\n"; db $0
align(4)

LpeteE_string4:
 db "I don't think she's worth the trouble, James.\n\nPerhaps you should be looking closer to home for a more reliable woman?\n"; db $0
align(4)

LpeteE_string5:
 db "Pursue Ourumov and Natalya\n"; db $0
align(4)

LpeteE_string6:
 db "Minimize civilian casualties\n"; db $0
align(4)

LpeteE_string7:
 db "Contact Valentin\n"; db $0
align(4)

LpeteE_string8:
 db "Warning: Civilian casualties high.\n"; db $0
align(4)

LpeteE_string9:
 db "Warning: Civilian casualties critical!\n"; db $0
align(4)

LpeteE_string10:
 db "Mission Failure: Too many civilian\n                     casualties.\n"; db $0
align(4)

LpeteE_string11:
 db "Mission Failure: Ourumov has escaped\n                     with Natalya.\n"; db $0
align(4)

LpeteE_string12:
 db "Valentin: Ah, Mr. Bond, I see you have\n           eluded the clutches of Military\n           Intelligence.\n"; db $0
align(4)

LpeteE_string13:
 db "Bond: Yes, but General Ourumov has\n        taken Natalya!\n"; db $0
align(4)

LpeteE_string14:
 db "Valentin: I saw the car, he's taking the\n           girl to a disused military depot\n           not far from here.\n"; db $0
align(4)

LpeteE_string15:
 db "Valentin: The Janus base is there.\n           A simple phone call and my\n           men will delay them.\n"; db $0
align(4)

LpeteE_string16:
 db "Bond: What's in it for you, Valentin?\n"; db $0
align(4)

LpeteE_string17:
 db "Valentin: Business is business, Mr. Bond.\n           I'd like to see my competitors\n           out of action.\n"; db $0
align(4)

LpeteE_string18:
 db "Valentin: I'm trying to help you, Mr. Bond.\n           You could at least\n           be civil enough to listen to me.\n"; db $0
align(4)

LpeteE_string19:
 db "Valentin has left.\n"; db $0
align(4)

LpeteE_string20:
 db "Valentin has contacted his 'associates'.\n"; db $0
align(4)

LpeteE_string21:
 db "S T .  P E T E R S B U R G\n"; db $0
align(4)

LpeteE_string22:
 db "after escaping kgb interrogation at the military archives, natalya has been recaptured by general ourumov. she is being taken by car to the janus operations base in st. petersburg.\n"; db $0
align(4)

LpeteE_string23:
 db "get after them, 007! we can't afford to let the trail go cold and the chances are they'll lead you straight to trevelyan. keep a clear head though, any civilian casualties on the streets of st. petersburg could create an unfortunate international incident.\nwe believe that valentin zukovsky is still in the area - he may be able to help you.\n"; db $0
align(4)

LpeteE_string24:
 db "no gadgets this time, 007. though you should be on the lookout for hardware the russians may have left lying around. keys in the ignition and all that, old chap.\n"; db $0
align(4)

LpeteE_string25:
 db "i don't think she's worth the trouble, james.\n\nperhaps you should be looking closer to home for a more reliable woman?\n"; db $0
align(4)

LpeteE_string26:
 db "pursue ourumov and natalya\n"; db $0
align(4)

LpeteE_string27:
 db "minimize civilian casualties\n"; db $0
align(4)

LpeteE_string28:
 db "contact valentin\n"; db $0
align(4)

LpeteE_string29:
db "St. Petersburg\n"; db $0
align(16)

seg_LpeteE_strings_end:
seg_LpeteE_end:

