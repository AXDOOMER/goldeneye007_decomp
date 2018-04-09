arch n64.cpu
endian msb
include "../BASS.INC"
output "LcradE.bin", create

base $00000000
seg_LcradE_start:
seg_LcradE_header_start:

ptr_LcradE_string1:
 dw LcradE_string1

ptr_LcradE_string2:
 dw LcradE_string2

ptr_LcradE_string3:
 dw LcradE_string3

ptr_LcradE_string4:
 dw LcradE_string4

ptr_LcradE_string5:
 dw LcradE_string5

ptr_LcradE_string6:
 dw LcradE_string6

ptr_LcradE_string7:
 dw LcradE_string7

ptr_LcradE_string8:
 dw LcradE_string8

ptr_LcradE_string9:
 dw LcradE_string9

ptr_LcradE_string10:
 dw LcradE_string10

ptr_LcradE_string11:
 dw LcradE_string11

ptr_LcradE_string12:
 dw LcradE_string12

ptr_LcradE_string13:
 dw LcradE_string13

ptr_LcradE_string14:
 dw LcradE_string14

ptr_LcradE_string15:
 dw LcradE_string15

ptr_LcradE_string16:
 dw LcradE_string16

ptr_LcradE_string17:
 dw LcradE_string17

ptr_LcradE_string18:
 dw LcradE_string18

ptr_LcradE_string19:
 dw LcradE_string19

ptr_LcradE_string20:
 dw LcradE_string20

ptr_LcradE_string21:
 dw LcradE_string21

ptr_LcradE_string22:
 dw LcradE_string22

ptr_LcradE_string23:
 dw LcradE_string23

ptr_LcradE_string24:
 dw LcradE_string24

ptr_LcradE_string25:
 dw LcradE_string25

ptr_LcradE_string26:
 dw LcradE_string26

ptr_LcradE_string27:
 dw LcradE_string27

ptr_LcradE_string28:
 dw LcradE_string28

ptr_LcradE_string29:
 dw LcradE_string29

ptr_LcradE_string30:
 dw LcradE_string30

ptr_LcradE_string31:
 dw LcradE_string31

ptr_LcradE_string32:
 dw LcradE_string32

ptr_LcradE_string33:
 dw LcradE_string33

ptr_LcradE_string34:
 dw LcradE_string34

ptr_LcradE_string35:
 dw LcradE_string35

ptr_LcradE_string36:
 dw seg_LcradE_start

seg_LcradE_header_end:
seg_LcradE_strings_start:

LcradE_string1:
 db "Janus control communications have been jammed and the Goldeneye satellite orbit is decaying. Only Trevelyan and his personal bodyguard remain unaccounted for.\n"; db $0
align(4)

LcradE_string2:
 db "You know my feelings about personal vendettas interfering with mission success, 007. However, in this case, I think we can turn a blind eye to whatever happens out there. \n\nBe careful, and remember,\n                   - you are licensed to kill.\n"; db $0
align(4)

LcradE_string3:
 db "Would you believe it, 007? There's another blasted control thingy actually on the antenna cradle. Trevelyan might be able to realign the antenna and get one last firing message through to the satellite. Get out there and destroy it! We don't want things going pear-shaped at the last minute.\n"; db $0
align(4)

LcradE_string4:
 db "The hand that rocks the cradle rules the world, James.\nYou know I won't sleep soundly until you get back to England in one piece.\n"; db $0
align(4)

LcradE_string5:
 db "Destroy control console\n"; db $0
align(4)

LcradE_string6:
 db "Settle the score with Trevelyan\n"; db $0
align(4)

LcradE_string7:
 db "Trevelyan has activated the antenna\ncontrol console!\n"; db $0
align(4)

LcradE_string8:
 db "3 minutes until antenna realigns!\n"; db $0
align(4)

LcradE_string9:
 db "Control console destroyed!\nAntenna inoperative.\n"; db $0
align(4)

LcradE_string10:
 db "Antenna will signal satellite in 15 seconds!\n"; db $0
align(4)

LcradE_string11:
 db "Mission failure: Goldeneye satellite has\nbeen reactivated!\n"; db $0
align(4)

LcradE_string12:
 db "Trevelyan: Closing time, James. Last call.\n"; db $0
align(4)

LcradE_string13:
 db "Trevelyan: You haven't won yet!\n"; db $0
align(4)

LcradE_string14:
 db "Trevelyan: From the cradle to the grave\n              - your grave, James.\n"; db $0
align(4)

LcradE_string15:
 db "Trevelyan: You could have joined me,\n              James, but you had to side\n              with the pen pushers.\n"; db $0
align(4)

LcradE_string16:
 db "Trevelyan: Always loyal to the mission\n              - never to your friends.\n"; db $0
align(4)

LcradE_string17:
 db "Trevelyan: James Bond. Her Majesty's\n              loyal terrier - you sicken me.\n"; db $0
align(4)

LcradE_string18:
 db "Trevelyan: What's the matter, James?\n              No glib remark?\n              No pithy comeback?\n"; db $0
align(4)

LcradE_string19:
 db "Trevelyan: Come on! Is that the best\n              you can do?\n"; db $0
align(4)

LcradE_string20:
 db "Trevelyan: You never give up, do you?\n              Pathetic really.\n"; db $0
align(4)

LcradE_string21:
 db "Trevelyan: You'll never win, James.\n"; db $0
align(4)

LcradE_string22:
 db "Trevelyan: Finish the job, James\n                - if you can.\n"; db $0
align(4)

LcradE_string23:
 db "Trevelyan: I was always better, James.\n"; db $0
align(4)

LcradE_string24:
 db "Trevelyan: For England, James?\n"; db $0
align(4)

LcradE_string25:
 db "Bond: No. For me.\n"; db $0
align(4)

LcradE_string26:
 db "Trevelyan: You're not looking so well, \n              James - can't take the pace?\n"; db $0
align(4)

LcradE_string27:
 db "A N T E N N A   C R A D L E\n"; db $0
align(4)

LcradE_string28:
 db "janus control communications have been jammed and the goldeneye satellite orbit is decaying. only trevelyan and his personal bodyguard remain unaccounted for.\n"; db $0
align(4)

LcradE_string29:
 db "you know my feelings about personal vendettas interfering with mission success, 007. however, in this case, i think we can turn a blind eye to whatever happens out there. \n\nbe careful, and remember,\n    -you are licensed to kill.\n"; db $0
align(4)

LcradE_string30:
 db "would you believe it, 007? there's another blasted control thingy actually on the antenna cradle. trevelyan might be able to realign the antenna and get one last firing message through to the satellite. get out there and destroy it! we don't want things going pear-shaped at the last minute.\n"; db $0
align(4)

LcradE_string31:
 db "the hand that rocks the cradle rules the world, james.\nyou know i won't sleep soundly until you get back to england in one piece.\n"; db $0
align(4)

LcradE_string32:
 db "destroy control console\n"; db $0
align(4)

LcradE_string33:
 db "settle the score with trevelyan\n"; db $0
align(4)

LcradE_string34:
 db "\n"; db $0
align(4)

LcradE_string35:
db "Antenna Cradle, Janus Base, Cuba\n"; db $0
align(4)

LcradE_string36:
 db ""; db $0
align(4)

db $0; align(16)

seg_LcradE_strings_end:
seg_LcradE_end:

