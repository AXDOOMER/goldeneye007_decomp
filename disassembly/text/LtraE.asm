arch n64.cpu
endian msb
include "../lib/N64.INC"
output "LtraE.bin", create

base $00000000
seg_LtraE_start:
seg_LtraE_header_start:
ptr_LtraE_background:
 dw LtraE_background

ptr_LtraE_m_briefing:
 dw LtraE_m_briefing

ptr_LtraE_q_branch:
 dw LtraE_q_branch

ptr_LtraE_moneypenny:
 dw LtraE_moneypenny

ptr_LtraE_objective1:
 dw LtraE_objective1

ptr_LtraE_objective2:
 dw LtraE_objective2

ptr_LtraE_objective3:
 dw LtraE_objective3

ptr_LtraE_objective4:
 dw LtraE_objective4

ptr_LtraE_objective5:
 dw LtraE_objective5

ptr_LtraE_trevelyan01:
 dw LtraE_trevelyan01

ptr_LtraE_trevelyan02:
 dw LtraE_trevelyan02

ptr_LtraE_bond01:
 dw LtraE_bond01

ptr_LtraE_trevelyan03:
 dw LtraE_trevelyan03

ptr_LtraE_trevelyan04:
 dw LtraE_trevelyan04

ptr_LtraE_xenia01:
 dw LtraE_xenia01

ptr_LtraE_trevelyan05:
 dw LtraE_trevelyan05

ptr_LtraE_trevelyan06:
 dw LtraE_trevelyan06

ptr_LtraE_trevelyan07:
 dw LtraE_trevelyan07

ptr_LtraE_trevelyan08:
 dw LtraE_trevelyan08

ptr_LtraE_trevelyan09:
 dw LtraE_trevelyan09

ptr_LtraE_natalya01:
 dw LtraE_natalya01

ptr_LtraE_natalya02:
 dw LtraE_natalya02

ptr_LtraE_natalya03:
 dw LtraE_natalya03

ptr_LtraE_natalya04:
 dw LtraE_natalya04

ptr_LtraE_natalya05:
 dw LtraE_natalya05

ptr_LtraE_trevelyan0A:
 dw LtraE_trevelyan0A

ptr_LtraE_natalya06:
 dw LtraE_natalya06

ptr_LtraE_natalya07:
 dw LtraE_natalya07

ptr_LtraE_missionfailure1:
 dw LtraE_missionfailure1

ptr_LtraE_watch_name:
 dw LtraE_watch_name

ptr_LtraE_watch_background:
 dw LtraE_watch_background

ptr_LtraE_watch_m_briefing:
 dw LtraE_watch_m_briefing

ptr_LtraE_watch_q_branch:
 dw LtraE_watch_q_branch

ptr_LtraE_watch_moneypenny:
 dw LtraE_watch_moneypenny

ptr_LtraE_watch_objective1:
 dw LtraE_watch_objective1

ptr_LtraE_watch_objective2:
 dw LtraE_watch_objective2

ptr_LtraE_watch_objective3:
 dw LtraE_watch_objective3

ptr_LtraE_watch_objective4:
 dw LtraE_watch_objective4

ptr_LtraE_watch_objective5:
 dw LtraE_watch_objective5

ptr_LtraE_watch_nullstring:
 dw LtraE_watch_nullstring

ptr_LtraE_watch_item1:
 dw LtraE_watch_item1

ptr_LtraE_watch_item2:
 dw LtraE_watch_item2

ptr_LtraE_watch_item3:
 dw LtraE_watch_item3

ptr_LtraE_item_pickup1:
 dw LtraE_item_pickup1

ptr_LtraE_string2D:
 dw LtraE_string2D

ptr_LtraE_null1:
 dw $00000000

ptr_LtraE_null2:
 dw $00000000

ptr_LtraE_null3:
 dw $00000000
seg_LtraE_header_end:

seg_LtraE_strings_start:
LtraE_background:
db "The leader of Janus, Alec Trevelyan, is holding Natalya hostage on his armored train.\n";db 0x00
align(4)

LtraE_m_briefing:
db "We've lost experienced agents before in hostage situations. Keep a clear head, 007, and don't get sidetracked settling old scores.\n";db 0x00
align(4)

LtraE_q_branch:
db "A train, 007, pretty simple. Destroy the braking units in each carriage and the emergency \n"
db "systems should bring it to a halt.\n";db 0x00
align(4)

LtraE_moneypenny:
db "That girl again, James? \n";db 0x00
align(4)

LtraE_objective1:
db "Destroy brake units\n";db 0x00
align(4)

LtraE_objective2:
db "Rescue Natalya\n";db 0x00
align(4)

LtraE_objective3:
db "Locate Janus secret base\n";db 0x00
align(4)

LtraE_objective4:
db "Crack Boris' password\n";db 0x00
align(4)

LtraE_objective5:
db "Escape to safety\n";db 0x00
align(4)

LtraE_trevelyan01:
db "Trevelyan: That's close enough!\n";db 0x00
align(4)

LtraE_trevelyan02:
db "Trevelyan: Come on James, don't try\n"
db "              to be clever. Make your move.\n";db 0x00
align(4)

LtraE_bond01:
db "Bond: You first.\n";db 0x00
align(4)

LtraE_trevelyan03:
db "Trevelyan: Two targets. Time for one shot.\n"
db "              The girl or the mission?\n";db 0x00
align(4)

LtraE_trevelyan04:
db "Trevelyan: You'll never win, James.\n";db 0x00
align(4)

LtraE_xenia01:
db "Xenia: Wait for me Alec, I'm hit!\n";db 0x00
align(4)

LtraE_trevelyan05:
db "Trevelyan: Kill them!\n";db 0x00
align(4)

LtraE_trevelyan06:
db "Trevelyan: James, what an unpleasant\n"
db "              surprise. Do come in.\n";db 0x00
align(4)

LtraE_trevelyan07:
db "Trevelyan: Leaving already, James?\n"
db "              I don't think so.\n";db 0x00
align(4)

LtraE_trevelyan08:
db "Trevelyan: Good luck with the floor, \n"
db "              James.\n";db 0x00
align(4)

LtraE_trevelyan09:
db "Trevelyan: It shouldn't take more than\n"
db "              a minute.\n";db 0x00
align(4)

LtraE_natalya01:
db "Natalya: Boris is still backing up his files.\n"
db "           I can find out where they're\n"
db "           going.\n";db 0x00
align(4)

LtraE_natalya02:
db "Natalya: He's in Cuba!\n";db 0x00;
align(4)

LtraE_natalya03:
db "Natalya: Now, if I just had time to crack \n"
db "           his password...\n";db 0x00
align(4)

LtraE_natalya04:
db "Natalya: Got it!\n"
db "           You're a slug-head, Boris!\n";db 0x00
align(4)

LtraE_natalya05:
db "Natalya: I'm coming, James!\n";db 0x00
align(4)

LtraE_trevelyan0A:
db "Trevelyan: Too slow, 007.\n";db 0x00
align(4)

LtraE_natalya06:
db "Natalya: Well done, James, that's the\n"
db "           computer out of action.\n";db 0x00
align(4)

LtraE_natalya07:
db "Natalya: Just how am I supposed to\n"
db "           locate the Janus base?\n";db 0x00
align(4)

LtraE_missionfailure1:
db "Mission failure. Natalya has been killed.\n";db 0x00
align(4)

LtraE_watch_name:
db "T R A I N\n";db 0x00
align(4)

LtraE_watch_background:
db "the leader of janus, alec trevelyan, is holding natalya hostage on his armored train.\n";db 0x00
align(4)

LtraE_watch_m_briefing:
db "we've lost experienced agents before in hostage situations. Keep a clear head, 007, and don't get sidetracked settling old scores.\n";db 0x00
align(4)

LtraE_watch_q_branch:
db "a train, 007, pretty simple. destroy the braking units in each carriage and the emergency \n"
db "systems should bring it to a halt.\n";db 0x00
align(4)

LtraE_watch_moneypenny:
db "that girl again, james? \n";db 0x00
align(4)

LtraE_watch_objective1:
db "destroy brake units\n";db 0x00
align(4)

LtraE_watch_objective2:
db "rescue natalya\n";db 0x00
align(4)

LtraE_watch_objective3:
db "locate janus secret base\n";db 0x00
align(4)

LtraE_watch_objective4:
db "crack boris' password\n";db 0x00
align(4)

LtraE_watch_objective5:
db "escape to safety\n";db 0x00
align(4)

LtraE_watch_nullstring:
db "\n";db 0x00
align(4)

LtraE_watch_item1:
db "door key\n";db 0x00
align(4)

LtraE_watch_item2:
db "train door key\n";db 0x00
align(4)

LtraE_watch_item3:
db "train door key\n";db 0x00
align(4)

LtraE_item_pickup1:
db "Picked up a door key.\n";db 0x00
align(4)

LtraE_string2D:
db "Converted Missile Train, heading east\n";db 0x00
align(8)
seg_LtraE_strings_end:
seg_LtraE_end:
