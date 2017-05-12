arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LcaveE.bin", create

base $00000000
seg_LcaveE_start:
seg_LcaveE_header_start:

ptr_LcaveE_string1:
 dw LcaveE_string1

ptr_LcaveE_string2:
 dw LcaveE_string2

ptr_LcaveE_string3:
 dw LcaveE_string3

ptr_LcaveE_string4:
 dw LcaveE_string4

ptr_LcaveE_string5:
 dw LcaveE_string5

ptr_LcaveE_string6:
 dw LcaveE_string6

ptr_LcaveE_string7:
 dw LcaveE_string7

ptr_LcaveE_string8:
 dw LcaveE_string8

ptr_LcaveE_string9:
 dw LcaveE_string9

ptr_LcaveE_string10:
 dw LcaveE_string10

ptr_LcaveE_string11:
 dw LcaveE_string11

ptr_LcaveE_string12:
 dw LcaveE_string12

ptr_LcaveE_string13:
 dw LcaveE_string13

ptr_LcaveE_string14:
 dw LcaveE_string14

ptr_LcaveE_string15:
 dw LcaveE_string15

ptr_LcaveE_string16:
 dw LcaveE_string16

ptr_LcaveE_string17:
 dw LcaveE_string17

ptr_LcaveE_string18:
 dw LcaveE_string18

ptr_LcaveE_string19:
 dw LcaveE_string19

ptr_LcaveE_string20:
 dw LcaveE_string20

ptr_LcaveE_string21:
 dw LcaveE_string21

ptr_LcaveE_string22:
 dw LcaveE_string22

ptr_LcaveE_string23:
 dw LcaveE_string23

ptr_LcaveE_string24:
 dw LcaveE_string24

ptr_LcaveE_string25:
 dw LcaveE_string25

ptr_LcaveE_string26:
 dw LcaveE_string26

ptr_LcaveE_string27:
 dw LcaveE_string27

ptr_LcaveE_string28:
 dw LcaveE_string28

ptr_LcaveE_string29:
 dw LcaveE_string29

ptr_LcaveE_string30:
 dw LcaveE_string30

ptr_LcaveE_string31:
 dw LcaveE_string31

ptr_LcaveE_string32:
 dw LcaveE_string32

ptr_LcaveE_string33:
 dw LcaveE_string33

ptr_LcaveE_string34:
 dw LcaveE_string34

ptr_LcaveE_string35:
 dw LcaveE_string35

ptr_LcaveE_string36:
 dw LcaveE_string36

ptr_LcaveE_string37:
 dw LcaveE_string37

ptr_LcaveE_string38:
 dw LcaveE_string38

ptr_LcaveE_string39:
 dw LcaveE_string39

ptr_LcaveE_string40:
 dw LcaveE_string40

ptr_LcaveE_string41:
 dw LcaveE_string41

ptr_LcaveE_string42:
 dw seg_LcaveE_start

ptr_LcaveE_string43:
 dw seg_LcaveE_start

ptr_LcaveE_string44:
 dw seg_LcaveE_start

seg_LcaveE_header_end:
seg_LcaveE_strings_start:

LcaveE_string1:
 db "The Janus Control Center communicates with the Goldeneye weapons system via a large satellite dish which is usually concealed underwater. The pumps which allow Janus to flood the communications dish are housed in a subterranean cave complex defended by crack Janus troops.\n"; db $0
align(4)

LcaveE_string2:
 db "Don't jeopardize the mission by going for the man, Bond - nobody needs a dead hero. You'll be on your own but CIA combat support will be waiting. Find a radio and inform Jack Wade of the exact location of the dish and he'll send in the cavalry.\n"; db $0
align(4)

LcaveE_string3:
 db "The satellite communication dish is exposed. If you remove the water pumps, Janus will be unable to hide it again.\nDestroy the servo control consoles close to the pumps and be sure to disable the master console.\n"; db $0
align(4)

LcaveE_string4:
 db "Doing a spot of spelunking?\nWell, don't mess your trousers up, James.\n"; db $0
align(4)

LcaveE_string5:
 db "Destroy inlet pump controls\n"; db $0
align(4)

LcaveE_string6:
 db "Destroy outlet pump controls\n"; db $0
align(4)

LcaveE_string7:
 db "Destroy master control console\n"; db $0
align(4)

LcaveE_string8:
 db "Use radio to contact Jack Wade\n"; db $0
align(4)

LcaveE_string9:
 db "Pursue Trevelyan\n"; db $0
align(4)

LcaveE_string10:
 db "Minimize scientist casualties\n"; db $0
align(4)

LcaveE_string11:
 db "Trevelyan: So slow, James.\n              ... yet again.\n"; db $0
align(4)

LcaveE_string12:
 db "Radio damaged:\n      Cannot contact Jack Wade!\n"; db $0
align(4)

LcaveE_string13:
 db "Jack Wade: Got your bearings Jimbo!\n                Me and my boys are on\n                our way.\n"; db $0
align(4)

LcaveE_string14:
 db "Mission Failure: Unacceptable non-military\ncasualties!\n"; db $0
align(4)

LcaveE_string15:
 db "W A T E R   C A V E R N S\n"; db $0
align(4)

LcaveE_string16:
 db "the janus control center communicates with the goldeneye weapons system via a large satellite dish which is usually concealed underwater. the pumps which allow janus to flood the communications dish are housed in a subterranean cave complex  defended by crack janus troops.\n"; db $0
align(4)

LcaveE_string17:
 db "don't jeopardize the mission by going for the man, 007 - nobody needs a dead hero. you'll be on your own but CIA combat support will be waiting. find a radio and inform jack wade of the exact location of the dish and he'll send in the cavalry.\n"; db $0
align(4)

LcaveE_string18:
 db "the satellite communication dish is exposed. if you shut down the water pumps, janus will be unable to hide it again.\ndestroy the servo control consoles close to the pumps and be sure to disable the master console.\n"; db $0
align(4)

LcaveE_string19:
 db "doing a spot of spelunking?\nwell, don't come back with your trousers all messed up.\n"; db $0
align(4)

LcaveE_string20:
 db "destroy inlet pump controls\n"; db $0
align(4)

LcaveE_string21:
 db "destroy outlet pump controls\n"; db $0
align(4)

LcaveE_string22:
 db "destroy master control console\n"; db $0
align(4)

LcaveE_string23:
 db "use radio to contact jack wade\n"; db $0
align(4)

LcaveE_string24:
 db "pursue trevelyan\n"; db $0
align(4)

LcaveE_string25:
 db "minimize scientist casualties\n"; db $0
align(4)

LcaveE_string26:
 db "Subterranean Caverns\n"; db $0
align(4)

LcaveE_string27:
 db "\n"; db $0
align(4)

LcaveE_string28:
 db "code card\n"; db $0
align(4)

LcaveE_string29:
 db "code card a\n"; db $0
align(4)

LcaveE_string30:
 db "code card (blast door a)\n"; db $0
align(4)

LcaveE_string31:
 db "Picked up a code card\n"; db $0
align(4)

LcaveE_string32:
 db "\n"; db $0
align(4)

LcaveE_string33:
 db "code card\n"; db $0
align(4)

LcaveE_string34:
 db "code card b\n"; db $0
align(4)

LcaveE_string35:
 db "code card (blast door b)\n"; db $0
align(4)

LcaveE_string36:
 db "Picked up a code card\n"; db $0
align(4)

LcaveE_string37:
 db "\n"; db $0
align(4)

LcaveE_string38:
 db "code card\n"; db $0
align(4)

LcaveE_string39:
 db "code card c\n"; db $0
align(4)

LcaveE_string40:
 db "code card (blast door c)\n"; db $0
align(4)

LcaveE_string41:
db "Picked up a code card\n"; db $0
align(4)

LcaveE_string44:
 db ""; db $0
align(4)

db $0; align(16)

seg_LcaveE_strings_end:
seg_LcaveE_end:

