arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LdamE.bin", create

base $00000000
seg_LdamE_start:
seg_LdamE_header_start:

ptr_LdamE_string1:
 dw LdamE_string1

ptr_LdamE_string2:
 dw LdamE_string2

ptr_LdamE_string3:
 dw LdamE_string3

ptr_LdamE_string4:
 dw LdamE_string4

ptr_LdamE_string5:
 dw LdamE_string5

ptr_LdamE_string6:
 dw LdamE_string6

ptr_LdamE_string7:
 dw LdamE_string7

ptr_LdamE_string8:
 dw LdamE_string8

ptr_LdamE_string9:
 dw LdamE_string9

ptr_LdamE_string10:
 dw LdamE_string10

ptr_LdamE_string11:
 dw LdamE_string11

ptr_LdamE_string12:
 dw LdamE_string12

ptr_LdamE_string13:
 dw LdamE_string13

ptr_LdamE_string14:
 dw LdamE_string14

ptr_LdamE_string15:
 dw LdamE_string15

ptr_LdamE_string16:
 dw LdamE_string16

ptr_LdamE_string17:
 dw LdamE_string17

ptr_LdamE_string18:
 dw LdamE_string18

ptr_LdamE_string19:
 dw LdamE_string19

ptr_LdamE_string20:
 dw LdamE_string20

ptr_LdamE_string21:
 dw LdamE_string21

ptr_LdamE_string22:
 dw LdamE_string22

ptr_LdamE_string23:
 dw LdamE_string23

ptr_LdamE_string24:
 dw LdamE_string24

ptr_LdamE_string25:
 dw LdamE_string25

ptr_LdamE_string26:
 dw LdamE_string26

ptr_LdamE_string27:
 dw LdamE_string27

ptr_LdamE_string28:
 dw LdamE_string28

ptr_LdamE_string29:
 dw LdamE_string29

ptr_LdamE_string30:
 dw LdamE_string30

ptr_LdamE_string31:
 dw LdamE_string31

ptr_LdamE_string32:
 dw LdamE_string32

ptr_LdamE_string33:
 dw LdamE_string33

ptr_LdamE_string34:
 dw LdamE_string34

ptr_LdamE_string35:
 dw seg_LdamE_start

ptr_LdamE_string36:
 dw seg_LdamE_start

seg_LdamE_header_end:
seg_LdamE_strings_start:

LdamE_string1:
 db "MI6 has confirmed the existence of a secret chemical warfare facility at the Byelomorye dam, USSR. Its heavily guarded location and workings are a cause for major concern. Nerve gas produced there has been turning up in the hands of hostile regimes around the world and deals with international terrorists have been rumored. This facility should be destroyed with extreme prejudice.\n"; db $0
align(4)

LdamE_string2:
 db "The area around the dam is well defended against full scale military attack but a lone agent stands a much better chance. The easiest way to gain entrance to the weapons factory will be to get down the face of the dam. \nQ had an idea about that.\n"; db $0
align(4)

LdamE_string3:
 db "Information concerning shipping and contacts is stored on a computer system in a secret ops room within the dam. With this covert modem connected to their satellite link we can intercept the data when a backup is carried out.\nAs for getting down the dam, use the bungee rope. At the bottom of the jump, use the piton gun. Simple."; db $0
align(4)

LdamE_string4:
 db "Hardly a lover's leap, James. Be careful though, I hate to think of you falling for anyone else.\n"; db $0
align(4)

LdamE_string5:
 db "Neutralize all alarms\n"; db $0
align(4)

LdamE_string6:
 db "Install covert modem\n"; db $0
align(4)

LdamE_string7:
 db "Intercept data backup\n"; db $0
align(4)

LdamE_string8:
 db "Bungee jump from platform\n"; db $0
align(4)

LdamE_string9:
 db "Covert modem installed.\n"; db $0
align(4)

LdamE_string10:
 db "Off-site data backup initiated.\n"; db $0
align(4)

LdamE_string11:
 db "Off-site data backup completed.\n"; db $0
align(4)

LdamE_string12:
 db "... backup failed.\n"; db $0
align(4)

LdamE_string13:
 db "Main computer systems damaged.\nOperational data lost.\n"; db $0
align(4)

LdamE_string14:
 db "Covert modem not installed.\nData cannot be intercepted by MI6!\n"; db $0
align(4)

LdamE_string15:
 db "Satellite communications link destroyed.\nData cannot be intercepted by MI6!\n"; db $0
align(4)

LdamE_string16:
 db "Security gate A closing\n- please wait...\n"; db $0
align(4)

LdamE_string17:
 db "Security gate B closing\n- please wait...\n"; db $0
align(4)

LdamE_string18:
 db "B Y E L O M O R Y E  D A M\n"; db $0
align(4)

LdamE_string19:
 db "mi6 has confirmed the existence of a secret chemical warfare facility at the byelomorye dam, ussr. its heavily guarded location and workings are a cause for major concern. nerve gas produced there has been turning up in the hands of hostile regimes around the world and deals with international terrorists have been rumored. this facility should be destroyed with extreme prejudice.\n"; db $0
align(4)

LdamE_string20:
 db "the area around the dam is well defended against a full scale military attack but a lone agent stands a much better chance.the easiest way to gain entrance to the weapons factory will be to get down the face of the dam. \nq had an idea about that.\n"; db $0
align(4)

LdamE_string21:
 db "information concerning shipping and contacts is stored on a computer system in a secret ops room within the dam. with this covert modem connected to their satellite link we can intercept the data when a backup is carried out.\nas for getting down the dam, use the bungee rope. at the bottom of the jump, use the piton gun. simple."; db $0
align(4)

LdamE_string22:
 db "hardly a lover's leap, james. be careful though, i hate to think of you falling for anyone else.\n"; db $0
align(4)

LdamE_string23:
 db "neutralize all alarms\n"; db $0
align(4)

LdamE_string24:
 db "install covert modem\n"; db $0
align(4)

LdamE_string25:
 db "intercept data backup\n"; db $0
align(4)

LdamE_string26:
 db "bungee jump from platform\n"; db $0
align(4)

LdamE_string27:
 db "Byelomorye Dam, Arkangelsk, USSR\n"; db $0
align(4)

LdamE_string28:
 db "Nine years ago\n"; db $0
align(4)

LdamE_string29:
 db "\n"; db $0
align(4)

LdamE_string30:
 db "covert modem\n"; db $0
align(4)

LdamE_string31:
 db "covert modem\n"; db $0
align(4)

LdamE_string32:
 db "covert modem\n"; db $0
align(4)

LdamE_string33:
 db "Picked up a covert modem.\n"; db $0
align(4)

LdamE_string34:
db "Covert modem incorrectly installed.\n"; db $0
align(16)

seg_LdamE_strings_end:
seg_LdamE_end:

