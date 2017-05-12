arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LdepoE.bin", create

base $00000000
seg_LdepoE_start:
seg_LdepoE_header_start:

ptr_LdepoE_string1:
 dw LdepoE_string1

ptr_LdepoE_string2:
 dw LdepoE_string2

ptr_LdepoE_string3:
 dw LdepoE_string3

ptr_LdepoE_string4:
 dw LdepoE_string4

ptr_LdepoE_string5:
 dw LdepoE_string5

ptr_LdepoE_string6:
 dw LdepoE_string6

ptr_LdepoE_string7:
 dw LdepoE_string7

ptr_LdepoE_string8:
 dw LdepoE_string8

ptr_LdepoE_string9:
 dw LdepoE_string9

ptr_LdepoE_string10:
 dw LdepoE_string10

ptr_LdepoE_string11:
 dw LdepoE_string11

ptr_LdepoE_string12:
 dw LdepoE_string12

ptr_LdepoE_string13:
 dw LdepoE_string13

ptr_LdepoE_string14:
 dw LdepoE_string14

ptr_LdepoE_string15:
 dw LdepoE_string15

ptr_LdepoE_string16:
 dw LdepoE_string16

ptr_LdepoE_string17:
 dw LdepoE_string17

ptr_LdepoE_string18:
 dw LdepoE_string18

ptr_LdepoE_string19:
 dw LdepoE_string19

ptr_LdepoE_string20:
 dw LdepoE_string20

ptr_LdepoE_string21:
 dw seg_LdepoE_start

ptr_LdepoE_string22:
 dw seg_LdepoE_start

ptr_LdepoE_string23:
 dw seg_LdepoE_start

ptr_LdepoE_string24:
 dw seg_LdepoE_start

ptr_LdepoE_string25:
 dw LdepoE_string25

ptr_LdepoE_string26:
 dw LdepoE_string26

ptr_LdepoE_string27:
 dw LdepoE_string27

ptr_LdepoE_string28:
 dw LdepoE_string28

ptr_LdepoE_string29:
 dw seg_LdepoE_start

ptr_LdepoE_string30:
 dw LdepoE_string30

ptr_LdepoE_string31:
 dw LdepoE_string31

ptr_LdepoE_string32:
 dw LdepoE_string32

ptr_LdepoE_string33:
 dw LdepoE_string33

ptr_LdepoE_string34:
 dw LdepoE_string34

ptr_LdepoE_string35:
 dw LdepoE_string35

ptr_LdepoE_string36:
 dw seg_LdepoE_start

seg_LdepoE_header_end:
seg_LdepoE_strings_start:

LdepoE_string1:
 db "The Janus operations base in St. Petersburg is located in a disused military rail depot. From here the crime syndicate coordinates illegal arms deals, international terrorism and extortion.\n"; db $0
align(4)

LdepoE_string2:
 db "Quite a nest of vipers, 007 - do your best to disrupt the Janus operations. We'd be particularly interested if you could retrieve their blueprints for a modified version of the stealth helicopter, it seems they may be thinking of going into production. We also believe that Ourumov has taken Natalya to Trevelyan's converted missile train in the depot. You need to be on that train when it leaves. \n"; db $0
align(4)

LdepoE_string3:
 db "They've got a pretty sophisticated computer network hidden away somewhere in that depot, 007. Be a good chap and shut it down for them.\n\nOh, and don't forget to blow up the Janus arms cache - I'm just sorry I can't be there myself to enjoy the fireworks.\n"; db $0
align(4)

LdepoE_string4:
 db "Don't miss your train, James.\n"; db $0
align(4)

LdepoE_string5:
 db "Destroy illegal arms cache\n"; db $0
align(4)

LdepoE_string6:
 db "Destroy computer network\n"; db $0
align(4)

LdepoE_string7:
 db "Obtain safe key\n"; db $0
align(4)

LdepoE_string8:
 db "Recover helicopter blueprints\n"; db $0
align(4)

LdepoE_string9:
 db "Locate Trevelyan's train\n"; db $0
align(4)

LdepoE_string10:
 db "M I L I T A R Y   D E P O T\n"; db $0
align(4)

LdepoE_string11:
 db "the janus operations base in st. petersburg is located in a disused military rail depot. from here the crime syndicate coordinates illegal arms deals, international terrorism and extortion.\n"; db $0
align(4)

LdepoE_string12:
 db "quite a nest of vipers, 007 - do your best to disrupt the janus operations. we'd be particularly interested if you could retrieve their blueprints for a modified version of the stealth helicopter, it seems they may be thinking of going into production.\nwe also believe that ourumov has taken natalya to trevelyan's converted missile train in the depot. you need to be on that train when it leaves. \n"; db $0
align(4)

LdepoE_string13:
 db "they've got a pretty sophisticated computer network hidden away somewhere in that depot, 007. be a good chap and shut it down for them.\n\noh, and don't forget to blow up the janus arms cache - i'm just sorry i can't be there myself to enjoy the fireworks.\n"; db $0
align(4)

LdepoE_string14:
 db "don't miss your train, james.\n"; db $0
align(4)

LdepoE_string15:
 db "Disused Military Depot, St. Petersburg\n"; db $0
align(4)

LdepoE_string16:
 db "destroy illegal arms cache\n"; db $0
align(4)

LdepoE_string17:
 db "destroy computer network\n"; db $0
align(4)

LdepoE_string18:
 db "obtain safe key\n"; db $0
align(4)

LdepoE_string19:
 db "recover helicopter blueprints\n"; db $0
align(4)

LdepoE_string20:
db "locate trevelyan's train\n"; db $0
align(4)

LdepoE_string25:
 db "This safe is locked.\n"; db $0
align(4)

LdepoE_string26:
 db "\n"; db $0
align(4)

LdepoE_string27:
 db "helicopter blueprints\n"; db $0
align(4)

LdepoE_string28:
db "blueprints\n"; db $0
align(4)

LdepoE_string30:
 db "Picked up the blueprints\n"; db $0
align(4)

LdepoE_string31:
 db "\n"; db $0
align(4)

LdepoE_string32:
 db "safe key\n"; db $0
align(4)

LdepoE_string33:
 db "safe key\n"; db $0
align(4)

LdepoE_string34:
 db "Safe Key\n"; db $0
align(4)

LdepoE_string35:
db "Picked up a safe key.\n"; db $0
align(16)

seg_LdepoE_strings_end:
seg_LdepoE_end:

