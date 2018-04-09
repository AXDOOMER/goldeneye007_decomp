arch n64.cpu
endian msb
include "../BASS.INC"
output "LsevxE.bin", create

base $00000000
seg_LsevxE_start:
seg_LsevxE_header_start:

ptr_LsevxE_string1:
 dw LsevxE_string1

ptr_LsevxE_string2:
 dw LsevxE_string2

ptr_LsevxE_string3:
 dw LsevxE_string3

ptr_LsevxE_string4:
 dw LsevxE_string4

ptr_LsevxE_string5:
 dw LsevxE_string5

ptr_LsevxE_string6:
 dw LsevxE_string6

ptr_LsevxE_string7:
 dw LsevxE_string7

ptr_LsevxE_string8:
 dw LsevxE_string8

ptr_LsevxE_string9:
 dw LsevxE_string9

ptr_LsevxE_string10:
 dw LsevxE_string10

ptr_LsevxE_string11:
 dw LsevxE_string11

ptr_LsevxE_string12:
 dw LsevxE_string12

ptr_LsevxE_string13:
 dw LsevxE_string13

ptr_LsevxE_string14:
 dw LsevxE_string14

ptr_LsevxE_string15:
 dw LsevxE_string15

ptr_LsevxE_string16:
 dw LsevxE_string16

ptr_LsevxE_string17:
 dw LsevxE_string17

ptr_LsevxE_string18:
 dw LsevxE_string18

ptr_LsevxE_string19:
 dw LsevxE_string19

ptr_LsevxE_string20:
 dw LsevxE_string20

ptr_LsevxE_string21:
 dw LsevxE_string21

ptr_LsevxE_string22:
 dw LsevxE_string22

ptr_LsevxE_string23:
 dw seg_LsevxE_start

ptr_LsevxE_string24:
 dw seg_LsevxE_start

ptr_LsevxE_string25:
 dw seg_LsevxE_start

ptr_LsevxE_string26:
 dw seg_LsevxE_start

ptr_LsevxE_string27:
 dw LsevxE_string27

ptr_LsevxE_string28:
 dw LsevxE_string28

ptr_LsevxE_string29:
 dw LsevxE_string29

ptr_LsevxE_string30:
 dw LsevxE_string30

ptr_LsevxE_string31:
 dw LsevxE_string31

ptr_LsevxE_string32:
 dw LsevxE_string32

ptr_LsevxE_string33:
 dw LsevxE_string33

ptr_LsevxE_string34:
 dw LsevxE_string34

ptr_LsevxE_string35:
 dw LsevxE_string35

ptr_LsevxE_string36:
 dw LsevxE_string36

ptr_LsevxE_string37:
 dw LsevxE_string37

ptr_LsevxE_string38:
 dw LsevxE_string38

ptr_LsevxE_string39:
 dw LsevxE_string39

ptr_LsevxE_string40:
 dw LsevxE_string40

ptr_LsevxE_string41:
 dw LsevxE_string41

ptr_LsevxE_string42:
 dw LsevxE_string42

ptr_LsevxE_string43:
 dw seg_LsevxE_start

ptr_LsevxE_string44:
 dw seg_LsevxE_start

seg_LsevxE_header_end:
seg_LsevxE_strings_start:

LsevxE_string1:
 db "A spy satellite has detected increased levels of activity at an old observatory complex near Severnaya (62.08n, 102.58e) in Russia.\n\nOther sources have confirmed the shipment of a large amount of computer hardware to that location, and an influx of skilled personnel.\n"; db $0
align(4)

LsevxE_string2:
 db "It might be coincidence that there is a new head of the Soviet Space Weapons Division, your old friend General Ourumov, or it might not. Penetrate the base and find out what is going on. Building plans for the underground section would be ideal. They're unlikely to be just lying around so look for a safe - there's bound to be someone you can borrow a key from. \n"; db $0
align(4)

LsevxE_string3:
 db "I've looked over the recon photographs and I advise you to stay clear of the main bunker entrance by the helipad. However, there seems to be a ventilation tower nearby which would make an excellent spot for a covert entry.\nYou ought to power down the comms dish too, no point in letting them tell the whole of Russia you've dropped in.\n"; db $0
align(4)

LsevxE_string4:
 db "It's cold in Siberia, James.\n\nMake sure you wrap up warm and take care to protect your extremities.\n"; db $0
align(4)

LsevxE_string5:
 db "Power down communications dish\n"; db $0
align(4)

LsevxE_string6:
 db "Obtain safe key\n"; db $0
align(4)

LsevxE_string7:
 db "Steal building plans\n"; db $0
align(4)

LsevxE_string8:
 db "Enter base via ventilation tower\n"; db $0
align(4)

LsevxE_string9:
 db "Communications dish powered down.\n"; db $0
align(4)

LsevxE_string10:
 db "Dish controls destroyed!\nEmergency power systems engaged\n"; db $0
align(4)

LsevxE_string11:
 db "Access Denied!\n"; db $0
align(4)

LsevxE_string12:
 db "S E V E R N A Y A\n"; db $0
align(4)

LsevxE_string13:
 db "a spy satellite has detected increased levels of activity at an old observatory complex near severnaya (62.08n, 102.58e) in russia.\n\nother sources have confirmed the shipment of a large amount of computer hardware to that location, and an influx of skilled personnel.\n"; db $0
align(4)

LsevxE_string14:
 db "it might be coincidence that there is a new head of the soviet space weapons division, your old friend general ourumov, or it might not. penetrate the base and find out what is going on. building plans for the underground section would be ideal. they're unlikely to be just lying around so look for a safe - there's bound to be someone you can borrow a key from. \n"; db $0
align(4)

LsevxE_string15:
 db "i've looked over the recon photographs and i advise you to stay clear of the main bunker entrance by the helipad. however, there seems to be a ventilation tower nearby which would make an excellent spot for a covert entry.\nyou ought to power down the comms dish too, no point in letting them tell the whole of russia you've dropped in.\n"; db $0
align(4)

LsevxE_string16:
 db "it's cold in siberia, james.\n\nmake sure you wrap up warm and take care to protect your extremities.\n"; db $0
align(4)

LsevxE_string17:
 db "power down communications dish\n"; db $0
align(4)

LsevxE_string18:
 db "obtain safe key\n"; db $0
align(4)

LsevxE_string19:
 db "steal building plans\n"; db $0
align(4)

LsevxE_string20:
 db "enter base via ventilation tower\n"; db $0
align(4)

LsevxE_string21:
 db "Severnaya Installation, Siberian Plateau\n"; db $0
align(4)

LsevxE_string22:
db "Four years ago\n"; db $0
align(4)

LsevxE_string27:
 db "This safe is locked.\n"; db $0
align(4)

LsevxE_string28:
 db "severnaya\n"; db $0
align(4)

LsevxE_string29:
 db "bunker plans\n"; db $0
align(4)

LsevxE_string30:
 db "bunker plans\n"; db $0
align(4)

LsevxE_string31:
 db "Bunker Plans\n"; db $0
align(4)

LsevxE_string32:
 db "Picked up Bunker plans.\n"; db $0
align(4)

LsevxE_string33:
 db "\n"; db $0
align(4)

LsevxE_string34:
 db "safe key\n"; db $0
align(4)

LsevxE_string35:
 db "safe key\n"; db $0
align(4)

LsevxE_string36:
 db "Safe Key\n"; db $0
align(4)

LsevxE_string37:
 db "Picked up a safe key.\n"; db $0
align(4)

LsevxE_string38:
 db "\n"; db $0
align(4)

LsevxE_string39:
 db "hut door key\n"; db $0
align(4)

LsevxE_string40:
 db "hut door key\n"; db $0
align(4)

LsevxE_string41:
 db "Hut Door Key\n"; db $0
align(4)

LsevxE_string42:
db "Picked up a large key.\n"; db $0
align(16)

seg_LsevxE_strings_end:
seg_LsevxE_end:

