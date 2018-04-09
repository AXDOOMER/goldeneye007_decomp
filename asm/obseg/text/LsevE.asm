arch n64.cpu
endian msb
include "../BASS.INC"
output "LsevE.bin", create

base $00000000
seg_LsevE_start:
seg_LsevE_header_start:

ptr_LsevE_string1:
 dw LsevE_string1

ptr_LsevE_string2:
 dw LsevE_string2

ptr_LsevE_string3:
 dw LsevE_string3

ptr_LsevE_string4:
 dw LsevE_string4

ptr_LsevE_string5:
 dw LsevE_string5

ptr_LsevE_string6:
 dw LsevE_string6

ptr_LsevE_string7:
 dw LsevE_string7

ptr_LsevE_string8:
 dw LsevE_string8

ptr_LsevE_string9:
 dw LsevE_string9

ptr_LsevE_string10:
 dw LsevE_string10

ptr_LsevE_string11:
 dw LsevE_string11

ptr_LsevE_string12:
 dw LsevE_string12

ptr_LsevE_string13:
 dw LsevE_string13

ptr_LsevE_string14:
 dw LsevE_string14

ptr_LsevE_string15:
 dw LsevE_string15

ptr_LsevE_string16:
 dw LsevE_string16

ptr_LsevE_string17:
 dw LsevE_string17

ptr_LsevE_string18:
 dw LsevE_string18

ptr_LsevE_string19:
 dw LsevE_string19

ptr_LsevE_string20:
 dw LsevE_string20

ptr_LsevE_string21:
 dw LsevE_string21

ptr_LsevE_string22:
 dw LsevE_string22

ptr_LsevE_string23:
 dw LsevE_string23

ptr_LsevE_string24:
 dw LsevE_string24

ptr_LsevE_string25:
 dw LsevE_string25

ptr_LsevE_string26:
 dw LsevE_string26

ptr_LsevE_string27:
 dw LsevE_string27

ptr_LsevE_string28:
 dw LsevE_string28

ptr_LsevE_string29:
 dw LsevE_string29

ptr_LsevE_string30:
 dw LsevE_string30

ptr_LsevE_string31:
 dw LsevE_string31

ptr_LsevE_string32:
 dw LsevE_string32

ptr_LsevE_string33:
 dw LsevE_string33

ptr_LsevE_string34:
 dw LsevE_string34

ptr_LsevE_string35:
 dw LsevE_string35

ptr_LsevE_string36:
 dw LsevE_string36

ptr_LsevE_string37:
 dw LsevE_string37

ptr_LsevE_string38:
 dw LsevE_string38

ptr_LsevE_string39:
 dw LsevE_string39

ptr_LsevE_string40:
 dw LsevE_string40

ptr_LsevE_string41:
 dw LsevE_string41

ptr_LsevE_string42:
 dw LsevE_string42

ptr_LsevE_string43:
 dw LsevE_string43

ptr_LsevE_string44:
 dw LsevE_string44

ptr_LsevE_string45:
 dw LsevE_string45

ptr_LsevE_string46:
 dw LsevE_string46

ptr_LsevE_string47:
 dw LsevE_string47

ptr_LsevE_string48:
 dw seg_LsevE_start

seg_LsevE_header_end:
seg_LsevE_strings_start:

LsevE_string1:
 db "A spy satellite has detected increased levels of activity at an old observatory complex near Severnaya (62.08n, 102.58e) in Russia.\n\nOther sources have confirmed the shipment of a large amount of computer hardware to that location, and an influx of skilled personnel.\n"; db $0
align(4)

LsevE_string2:
 db "007, I want you to infiltrate this base and find out what the devil's going on there. The satellite photographs reveal that there has been recent underground excavation. We'd like to know the exact nature and planned extent of the workings.\n\nBy the way, this is a covert operation. You may have to neutralize the security, but try not to be too obvious about it.\n"; db $0
align(4)

LsevE_string3:
 db "You'll be doing some computer hacking on this mission, 007. I know you'd rather be cracking open a bottle of bubbly than cracking passwords, so I've taken the liberty of putting together a little gadget which will do the hard work for you. If you attach the data thief to their mainframe it should override any computer security measures and download the information we require.\n"; db $0
align(4)

LsevE_string4:
 db "Underground in Siberia, James? Some of us don't get further than the Northern Line.\n"; db $0
align(4)

LsevE_string5:
 db "Disrupt all surveillance equipment\n"; db $0
align(4)

LsevE_string6:
 db "Copy Goldeneye key and leave original\n"; db $0
align(4)

LsevE_string7:
 db "Get personnel to activate computer\n"; db $0
align(4)

LsevE_string8:
 db "Download data from computer\n"; db $0
align(4)

LsevE_string9:
 db "Photograph main video screen\n"; db $0
align(4)

LsevE_string10:
 db "hello\n"; db $0
align(4)

LsevE_string11:
 db "Bond: Take me to the mainframe terminal!\n"; db $0
align(4)

LsevE_string12:
 db "Programmer: Don't shoot! It's this way.\n"; db $0
align(4)

LsevE_string13:
 db "Programmer: Just through here.\n"; db $0
align(4)

LsevE_string14:
 db "Programmer: Let me see.\n"; db $0
align(4)

LsevE_string15:
 db "Programmer: Shouldn't take long.\n"; db $0
align(4)

LsevE_string16:
 db "Programmer: Hmmh, the root password\n                  has been changed.\n"; db $0
align(4)

LsevE_string17:
 db "Programmer: 'K' 'N' 'O' 'C' 'K' 'E' 'R' 'S'\n                  <return>\n"; db $0
align(4)

LsevE_string18:
 db "Programmer: Oops!\n"; db $0
align(4)

LsevE_string19:
 db "Bond: Disable the security!\n"; db $0
align(4)

LsevE_string20:
 db "The programmer has escaped without\nactivating the computer!\n"; db $0
align(4)

LsevE_string21:
 db "The computer has not been\n activated.\n"; db $0
align(4)

LsevE_string22:
 db "Downloading data...\n"; db $0
align(4)

LsevE_string23:
 db "Finished download.\n"; db $0
align(4)

LsevE_string24:
 db "Programmer: There's no way I can fix\n                  this!\n"; db $0
align(4)

LsevE_string25:
 db "S E V E R N A Y A\n"; db $0
align(4)

LsevE_string26:
 db "a spy satellite has detected increased levels of activity at an old observatory complex near severnaya (62.08n, 102.58e) in russia.\n\nother sources have confirmed the shipment of a large amount of computer hardware to that location, and an influx of skilled personnel.\n"; db $0
align(4)

LsevE_string27:
 db "007, i want you to infiltrate this base and find out what the devil's going on there. the satellite photographs reveal that there has been recent underground excavation we'd like to know the exact nature and planned extent of the workings.\n\nby the way, this is a covert operation. you may have to neutralize the security, but try not to be too obvious about it.\n"; db $0
align(4)

LsevE_string28:
 db "you'll be doing some computer hacking on this mission, 007. i know you'd rather be cracking open a bottle of bubbly than cracking passwords, so i've taken the liberty of putting together a little gadget which will do the hard work for you.\nif you attach the data thief to their mainframe it should override any computer security measures and download the information we require.\n"; db $0
align(4)

LsevE_string29:
 db "underground in siberia, james? some of us don't get further than the northern line.\n"; db $0
align(4)

LsevE_string30:
 db "disrupt all surveillance\n    equipment\n"; db $0
align(4)

LsevE_string31:
 db "copy goldeneye key and leave\n    original\n"; db $0
align(4)

LsevE_string32:
 db "get personnel to activate\n    computer\n"; db $0
align(4)

LsevE_string33:
 db "download data from computer\n"; db $0
align(4)

LsevE_string34:
 db "photograph main video screen\n"; db $0
align(4)

LsevE_string35:
 db "\n"; db $0
align(4)

LsevE_string36:
 db "keycard\n"; db $0
align(4)

LsevE_string37:
 db "computer room keycard\n"; db $0
align(4)

LsevE_string38:
 db "Computer Room Keycard\n"; db $0
align(4)

LsevE_string39:
 db "Picked up a computer room\n keycard.\n"; db $0
align(4)

LsevE_string40:
 db "\n"; db $0
align(4)

LsevE_string41:
 db "keycard\n"; db $0
align(4)

LsevE_string42:
 db "security keycard\n"; db $0
align(4)

LsevE_string43:
 db "Security Keycard\n"; db $0
align(4)

LsevE_string44:
 db "Picked up a security keycard.\n"; db $0
align(4)

LsevE_string45:
 db "Satellite Control Bunker\n"; db $0
align(4)

LsevE_string46:
 db "Present day\n"; db $0
align(4)

LsevE_string47:
db "Mainframe destroyed!\nData cannot be downloaded.\n"; db $0
align(16)

seg_LsevE_strings_end:
seg_LsevE_end:

