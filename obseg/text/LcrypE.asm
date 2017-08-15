arch n64.cpu
endian msb
include "../BASS.INC"
output "LcrypE.bin", create

base $00000000
seg_LcrypE_start:
seg_LcrypE_header_start:

ptr_LcrypE_string1:
 dw LcrypE_string1

ptr_LcrypE_string2:
 dw LcrypE_string2

ptr_LcrypE_string3:
 dw LcrypE_string3

ptr_LcrypE_string4:
 dw LcrypE_string4

ptr_LcrypE_string5:
 dw LcrypE_string5

ptr_LcrypE_string6:
 dw LcrypE_string6

ptr_LcrypE_string7:
 dw LcrypE_string7

ptr_LcrypE_string8:
 dw LcrypE_string8

ptr_LcrypE_string9:
 dw LcrypE_string9

ptr_LcrypE_string10:
 dw LcrypE_string10

ptr_LcrypE_string11:
 dw LcrypE_string11

ptr_LcrypE_string12:
 dw LcrypE_string12

ptr_LcrypE_string13:
 dw LcrypE_string13

ptr_LcrypE_string14:
 dw LcrypE_string14

ptr_LcrypE_string15:
 dw LcrypE_string15

ptr_LcrypE_string16:
 dw seg_LcrypE_start

seg_LcrypE_header_end:
seg_LcrypE_strings_start:

LcrypE_string1:
 db "Scaramanga has passed into legend as the deadliest assassin of all time.\nThe current whereabouts of his golden gun are unknown...\n"; db $0
align(4)

LcrypE_string2:
 db "This is sinister, 007. We've received a message from someone claiming to be Baron Samedi, the voodoo sorcerer you crossed swords with back in Haiti. He claims to have the golden gun and wants to meet you in the ancient el-Saghira temple in the Valley of the Kings.\nObviously, it's a trap, but as a double-0 agent you know that goes with the territory.\n"; db $0
align(4)

LcrypE_string3:
 db "Keep your wits about you, 007. Remember, the golden gun is a powerful weapon, perhaps it could even defeat Samedi.\n"; db $0
align(4)

LcrypE_string4:
 db "Do you do voodoo, James?\n"; db $0
align(4)

LcrypE_string5:
 db "Recover the golden gun\n"; db $0
align(4)

LcrypE_string6:
 db "Defeat Baron Samedi?\n"; db $0
align(4)

LcrypE_string7:
 db "Baron Samedi: Ha Ha Ha Ha...\n"; db $0
align(4)

LcrypE_string8:
 db "C R Y P T\n"; db $0
align(4)

LcrypE_string9:
 db "scaramanga has passed into legend as the deadliest assassin of all time.\nthe current whereabouts of his golden gun are unknown...\n"; db $0
align(4)

LcrypE_string10:
 db "this is sinister, 007. we've received a message from someone claiming to be baron samedi, the voodoo sorcerer you crossed swords with back in haiti. he claims to have the golden gun and wants to meet you in the ancient el-saghira temple in the valley of the kings.\nobviously, it's a trap, but as a double-o agent you know that goes with the territory.\n"; db $0
align(4)

LcrypE_string11:
 db "keep your wits about you, 007. remember, the golden gun is a powerful weapon, perhaps it could even defeat samedi.\n"; db $0
align(4)

LcrypE_string12:
 db "do you do voodoo, james?\n"; db $0
align(4)

LcrypE_string13:
 db "recover the golden gun\n"; db $0
align(4)

LcrypE_string14:
 db "defeat baron samedi?\n"; db $0
align(4)

LcrypE_string15:
db "el-Saghira Temple, Egypt\n"; db $0
align(4)

db $0; align(32)

seg_LcrypE_strings_end:
seg_LcrypE_end:

