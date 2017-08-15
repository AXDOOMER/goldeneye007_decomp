arch n64.cpu
endian msb
include "../BASS.INC"
output "LarkE.bin", create

base $00000000
seg_LarkE_start:
seg_LarkE_header_start:

ptr_LarkE_string1:
 dw LarkE_string1

ptr_LarkE_string2:
 dw LarkE_string2

ptr_LarkE_string3:
 dw LarkE_string3

ptr_LarkE_string4:
 dw LarkE_string4

ptr_LarkE_string5:
 dw LarkE_string5

ptr_LarkE_string6:
 dw LarkE_string6

ptr_LarkE_string7:
 dw LarkE_string7

ptr_LarkE_string8:
 dw LarkE_string8

ptr_LarkE_string9:
 dw LarkE_string9

ptr_LarkE_string10:
 dw LarkE_string10

ptr_LarkE_string11:
 dw LarkE_string11

ptr_LarkE_string12:
 dw LarkE_string12

ptr_LarkE_string13:
 dw LarkE_string13

ptr_LarkE_string14:
 dw LarkE_string14

ptr_LarkE_string15:
 dw LarkE_string15

ptr_LarkE_string16:
 dw LarkE_string16

ptr_LarkE_string17:
 dw LarkE_string17

ptr_LarkE_string18:
 dw LarkE_string18

ptr_LarkE_string19:
 dw LarkE_string19

ptr_LarkE_string20:
 dw LarkE_string20

ptr_LarkE_string21:
 dw LarkE_string21

ptr_LarkE_string22:
 dw LarkE_string22

ptr_LarkE_string23:
 dw LarkE_string23

ptr_LarkE_string24:
 dw LarkE_string24

ptr_LarkE_string25:
 dw LarkE_string25

ptr_LarkE_string26:
 dw LarkE_string26

ptr_LarkE_string27:
 dw LarkE_string27

ptr_LarkE_string28:
 dw LarkE_string28

ptr_LarkE_string29:
 dw LarkE_string29

ptr_LarkE_string30:
 dw LarkE_string30

ptr_LarkE_string31:
 dw LarkE_string31

ptr_LarkE_string32:
 dw LarkE_string32

ptr_LarkE_string33:
 dw LarkE_string33

ptr_LarkE_string34:
 dw LarkE_string34

ptr_LarkE_string35:
 dw LarkE_string35

ptr_LarkE_string36:
 dw LarkE_string36

ptr_LarkE_string37:
 dw LarkE_string37

ptr_LarkE_string38:
 dw LarkE_string38

ptr_LarkE_string39:
 dw LarkE_string39

ptr_LarkE_string40:
 dw LarkE_string40

ptr_LarkE_string41:
 dw LarkE_string41

ptr_LarkE_string42:
 dw LarkE_string42

ptr_LarkE_string43:
 dw LarkE_string43

ptr_LarkE_string44:
 dw LarkE_string44

ptr_LarkE_string45:
 dw LarkE_string45

ptr_LarkE_string46:
 dw LarkE_string46

ptr_LarkE_string47:
 dw LarkE_string47

ptr_LarkE_string48:
 dw LarkE_string48

ptr_LarkE_string49:
 dw LarkE_string49

ptr_LarkE_string50:
 dw LarkE_string50

ptr_LarkE_string51:
 dw LarkE_string51

ptr_LarkE_string52:
 dw LarkE_string52

ptr_LarkE_string53:
 dw LarkE_string53

ptr_LarkE_string54:
 dw LarkE_string54

ptr_LarkE_string55:
 dw LarkE_string55

ptr_LarkE_string56:
 dw LarkE_string56

ptr_LarkE_string57:
 dw LarkE_string57

ptr_LarkE_string58:
 dw LarkE_string58

ptr_LarkE_string59:
 dw LarkE_string59

ptr_LarkE_string60:
 dw LarkE_string60

ptr_LarkE_string61:
 dw LarkE_string61

ptr_LarkE_string62:
 dw LarkE_string62

ptr_LarkE_string63:
 dw LarkE_string63

ptr_LarkE_string64:
 dw LarkE_string64

ptr_LarkE_string65:
 dw LarkE_string65

ptr_LarkE_string66:
 dw LarkE_string66

ptr_LarkE_string67:
 dw LarkE_string67

ptr_LarkE_string68:
 dw LarkE_string68

ptr_LarkE_string69:
 dw seg_LarkE_start

ptr_LarkE_string70:
 dw LarkE_string70

ptr_LarkE_string71:
 dw LarkE_string71

ptr_LarkE_string72:
 dw LarkE_string72

seg_LarkE_header_end:
seg_LarkE_strings_start:

LarkE_string1:
 db "Inside the chemical weapons facility you should quickly and efficiently proceed to the bottling area and place demolition charges on the main gas tanks.\nPolitical considerations demand that collateral damage is minimized on this mission. Non-military personnel should be disregarded.\n"; db $0
align(4)

LarkE_string2:
 db "You'll be working with 006 on this assignment, the bottling room is the rendezvous point. \nDon't forget to contact our double agent scientist before you leave, and warn him to get out. He will provide you with a decoder for the final security door. There are no women or casinos for a thousand miles, 007, so even you will be able to concentrate on this mission.\n"; db $0
align(4)

LarkE_string3:
 db "Now listen carefully, Bond. Those bombs will be armed as soon as the last one is set. Don't be too close when you set them off or you'll go up in flames as well, and while you're at it, please try and bring back that door-opener undamaged for once. Too much rough handling like the last mission and it might go wrong at a bad time.\nHonestly 007, sometimes I think you damage your equipment on purpose.\n"; db $0
align(4)

LarkE_string4:
 db "These chemicals could prove to be a match even for your pheromones, James. Don't take too many risks.\n"; db $0
align(4)

LarkE_string5:
 db "Gain entry to laboratory area\n"; db $0
align(4)

LarkE_string6:
 db "Contact double agent\n"; db $0
align(4)

LarkE_string7:
 db "Rendezvous with 006\n"; db $0
align(4)

LarkE_string8:
 db "Destroy all tanks in bottling room\n"; db $0
align(4)

LarkE_string9:
 db "Minimize scientist casualties\n"; db $0
align(4)

LarkE_string10:
 db "Trevelyan: Glad you could make it, 007.\n"; db $0
align(4)

LarkE_string11:
 db "Trevelyan: For England - James.\n"; db $0
align(4)

LarkE_string12:
 db "Bond: For England, Alec.\n"; db $0
align(4)

LarkE_string13:
 db "Bond: It was too easy, Alec.\n"; db $0
align(4)

LarkE_string14:
 db "Trevelyan: Half of everything is luck.\n"; db $0
align(4)

LarkE_string15:
 db "Bond: ...and the other half?\n"; db $0
align(4)

LarkE_string16:
 db "Trevelyan: Fate.\n"; db $0
align(4)

LarkE_string17:
 db "Trevelyan: Why, James?\n"; db $0
align(4)

LarkE_string18:
 db "Bond: Time to leave, Dr. Doak.\n"; db $0
align(4)

LarkE_string19:
 db "Dr. Doak: You'll need this decoder to\n            open the bottling room door.\n            Good luck, 007.\n"; db $0
align(4)

LarkE_string20:
 db "Ourumov: Throw down your weapons...\n              You are surrounded!\n"; db $0
align(4)

LarkE_string21:
 db "Trevelyan: Finish the job, James!\n"; db $0
align(4)

LarkE_string22:
 db "Trevelyan: So, you decided to come\n              back.\n"; db $0
align(4)

LarkE_string23:
 db "Trevelyan: There's a job to do here.\n              Don't neglect your duty,\n              James!\n"; db $0
align(4)

LarkE_string24:
 db "Bond: It was a bit tricky, Alec.\n"; db $0
align(4)

LarkE_string25:
 db "Bond: I almost killed myself getting\n        here, Alec.\n"; db $0
align(4)

LarkE_string26:
 db "Ourumov: Nine\n"; db $0
align(4)

LarkE_string27:
 db "Ourumov: Eight\n"; db $0
align(4)

LarkE_string28:
 db "Ourumov: Seven\n"; db $0
align(4)

LarkE_string29:
 db "Ourumov: Six\n"; db $0
align(4)

LarkE_string30:
 db "Ourumov: Five\n"; db $0
align(4)

LarkE_string31:
 db "Ourumov: Four\n"; db $0
align(4)

LarkE_string32:
 db "Ourumov: Three\n"; db $0
align(4)

LarkE_string33:
 db "Ourumov: Two\n"; db $0
align(4)

LarkE_string34:
 db "Ourumov: One...\n"; db $0
align(4)

LarkE_string35:
 db "Ourumov: 1\n"; db $0
align(4)

LarkE_string36:
 db "Ourumov: One... Kill him!\n"; db $0
align(4)

LarkE_string37:
 db "Ourumov: You have ten seconds...\n"; db $0
align(4)

LarkE_string38:
 db "Trevelyan: So, the golden boy is a traitor!\n              How ironic, James.\n"; db $0
align(4)

LarkE_string39:
 db "Trevelyan: Why can't you just be a \n              good boy and die, James?\n"; db $0
align(4)

LarkE_string40:
 db "Security door activated.\n"; db $0
align(4)

LarkE_string41:
 db "Gas leak detected - isolating area.\n"; db $0
align(4)

LarkE_string42:
 db "Security code accepted - access granted.\n"; db $0
align(4)

LarkE_string43:
 db "Mission Failure: Unacceptable non-military\ncasualties!\n"; db $0
align(4)

LarkE_string44:
 db "A R K A N G E L S K\n"; db $0
align(4)

LarkE_string45:
 db "inside the chemical weapons facility you should quickly and efficiently proceed to the bottling area and place demolition charges on the main gas tanks.\npolitical considerations demand that collateral damage is minimized on this mission. non-military personnel should be disregarded.\n"; db $0
align(4)

LarkE_string46:
 db "you'll be working with 006 on this assignment, the bottling room is the rendezvous point.\n\ndon't forget to contact our double agent scientist before you leave, and warn him to get out.\nhe will provide you with a decoder for the final security door.\n\nthere are no women or casinos for a thousand miles, 007, so even you will be able to concentrate on this mission.\n"; db $0
align(4)

LarkE_string47:
 db "now listen carefully, bond. those bombs will be armed as soon as the last one is set. don't be too close when you set them off or you'll go up in flames as well. and while you're at it, please try and bring back that door-opener undamaged for once. too much rough handling like the last mission and it might go wrong at a bad time.\nhonestly 007, sometimes i think you damage your equipment on purpose.\n"; db $0
align(4)

LarkE_string48:
 db "these chemicals could prove to be a match even for your pheromones, james. don't take too many risks.\n"; db $0
align(4)

LarkE_string49:
 db "gain entry to laboratory area\n"; db $0
align(4)

LarkE_string50:
 db "contact double agent\n"; db $0
align(4)

LarkE_string51:
 db "rendezvous with 006\n"; db $0
align(4)

LarkE_string52:
 db "destroy all tanks in bottling\n    room\n"; db $0
align(4)

LarkE_string53:
 db "minimize scientist casualties\n"; db $0
align(4)

LarkE_string54:
 db "\n"; db $0
align(4)

LarkE_string55:
 db "decoder\n"; db $0
align(4)

LarkE_string56:
 db "door decoder\n"; db $0
align(4)

LarkE_string57:
 db "Door Decoder\n"; db $0
align(4)

LarkE_string58:
 db "Picked up a door decoder.\n"; db $0
align(4)

LarkE_string59:
 db "\n"; db $0
align(4)

LarkE_string60:
 db "keycard A\n"; db $0
align(4)

LarkE_string61:
 db "keycard A\n"; db $0
align(4)

LarkE_string62:
 db "keycard A\n"; db $0
align(4)

LarkE_string63:
 db "Picked up a clearance A keycard.\n"; db $0
align(4)

LarkE_string64:
 db "\n"; db $0
align(4)

LarkE_string65:
 db "keycard B\n"; db $0
align(4)

LarkE_string66:
 db "keycard B\n"; db $0
align(4)

LarkE_string67:
 db "keycard B\n"; db $0
align(4)

LarkE_string68:
db "Picked up a clearance B keycard.\n"; db $0
align(4)

LarkE_string70:
 db "This is a remotely locked\nsecurity door.\n"; db $0
align(4)

LarkE_string71:
 db "Chemical Warfare Facility #2\n"; db $0
align(4)

LarkE_string72:
 db "Double agent contact has been killed!\n"; db $0
align(4)

db $0; align(16)
seg_LarkE_strings_end:
seg_LarkE_end:

