arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LarchE.bin", create

base $00000000
seg_LarchE_start:
seg_LarchE_header_start:

ptr_LarchE_string1:
 dw LarchE_string1

ptr_LarchE_string2:
 dw LarchE_string2

ptr_LarchE_string3:
 dw LarchE_string3

ptr_LarchE_string4:
 dw LarchE_string4

ptr_LarchE_string5:
 dw LarchE_string5

ptr_LarchE_string6:
 dw LarchE_string6

ptr_LarchE_string7:
 dw LarchE_string7

ptr_LarchE_string8:
 dw LarchE_string8

ptr_LarchE_string9:
 dw LarchE_string9

ptr_LarchE_string10:
 dw LarchE_string10

ptr_LarchE_string11:
 dw LarchE_string11

ptr_LarchE_string12:
 dw LarchE_string12

ptr_LarchE_string13:
 dw LarchE_string13

ptr_LarchE_string14:
 dw LarchE_string14

ptr_LarchE_string15:
 dw LarchE_string15

ptr_LarchE_string16:
 dw LarchE_string16

ptr_LarchE_string17:
 dw LarchE_string17

ptr_LarchE_string18:
 dw LarchE_string18

ptr_LarchE_string19:
 dw LarchE_string19

ptr_LarchE_string20:
 dw LarchE_string20

ptr_LarchE_string21:
 dw LarchE_string21

ptr_LarchE_string22:
 dw LarchE_string22

ptr_LarchE_string23:
 dw LarchE_string23

ptr_LarchE_string24:
 dw LarchE_string24

ptr_LarchE_string25:
 dw LarchE_string25

ptr_LarchE_string26:
 dw LarchE_string26

ptr_LarchE_string27:
 dw LarchE_string27

ptr_LarchE_string28:
 dw LarchE_string28

ptr_LarchE_string29:
 dw LarchE_string29

ptr_LarchE_string30:
 dw LarchE_string30

ptr_LarchE_string31:
 dw LarchE_string31

ptr_LarchE_string32:
 dw LarchE_string32

ptr_LarchE_string33:
 dw LarchE_string33

ptr_LarchE_string34:
 dw LarchE_string34

ptr_LarchE_string35:
 dw LarchE_string35

ptr_LarchE_string36:
 dw LarchE_string36

ptr_LarchE_string37:
 dw LarchE_string37

ptr_LarchE_string38:
 dw LarchE_string38

ptr_LarchE_string39:
 dw LarchE_string39

ptr_LarchE_string40:
 dw LarchE_string40

ptr_LarchE_string41:
 dw LarchE_string41

ptr_LarchE_string42:
 dw LarchE_string42

ptr_LarchE_string43:
 dw LarchE_string43

ptr_LarchE_string44:
 dw LarchE_string44

ptr_LarchE_string45:
 dw LarchE_string45

ptr_LarchE_string46:
 dw LarchE_string46

ptr_LarchE_string47:
 dw LarchE_string47

ptr_LarchE_string48:
 dw LarchE_string48

ptr_LarchE_string49:
 dw LarchE_string49

ptr_LarchE_string50:
 dw LarchE_string50

ptr_LarchE_string51:
 dw LarchE_string51

ptr_LarchE_string52:
 dw seg_LarchE_start

ptr_LarchE_string53:
 dw LarchE_string53

ptr_LarchE_string54:
 dw LarchE_string54

ptr_LarchE_string55:
 dw LarchE_string55

ptr_LarchE_string56:
 dw LarchE_string56

ptr_LarchE_string57:
 dw LarchE_string57

ptr_LarchE_string58:
 dw LarchE_string58

ptr_LarchE_string59:
 dw LarchE_string59

ptr_LarchE_string60:
 dw LarchE_string60

ptr_LarchE_string61:
 dw LarchE_string61

ptr_LarchE_string62:
 dw LarchE_string62

ptr_LarchE_string63:
 dw LarchE_string63

ptr_LarchE_string64:
 dw seg_LarchE_start

seg_LarchE_header_end:
seg_LarchE_strings_start:

LarchE_string1:
 db "Captured by the Russians, Bond must escape their military prison.\n"; db $0
align(4)

LarchE_string2:
 db "Again? Captured again? I hope you can defend your performance, 007, because there isn't a lawyer in the land who'd take on the case.\nYour only chance is to speak directly to Defense Minister Mishkin. He's a reasonable man, for a member of the Politburo.\nFailure is not an option, Bond.\n"; db $0
align(4)

LarchE_string3:
 db "Up to you to get out of this one, 007. I can't hold your hand all the time. By the way, get that flight recorder for me, would you? Thanks.\n"; dw 0
align(4)

LarchE_string4:
 db "Banged up again, James? Now you know what it's like to be trapped behind a desk, and I'm off out to the theatre with a gentleman tonight. How times change!\n"; dw 0
align(4)

LarchE_string5:
 db "Escape from interrogation room\n"; db $0
align(4)

LarchE_string6:
 db "Find Natalya\n"; db $0
align(4)

LarchE_string7:
 db "Recover helicopter black box\n"; db $0
align(4)

LarchE_string8:
 db "Escape with Natalya\n"; db 0
align(4)

LarchE_string9:
 db "Natalya: James!\n"; db 0
align(4)

LarchE_string10:
 db "Natalya: Be careful with that gun!\n"; db $0
align(4)

LarchE_string11:
 db "Natalya: We could escape through the\n           library windows.\n"; db $0
align(4)

LarchE_string12:
 db "Natalya: I'm scared, I'm getting out of here.\n"; db $0
align(4)

LarchE_string13:
 db "Natalya: Aaaaargh!\n"; db $0
align(4)

LarchE_string14:
 db "Guard: So Mr. Bond, what do you know\n         about the theft of the\n         Goldeneye?\n"; db $0
align(4)

LarchE_string15:
 db "Guard: Nonsense, Mr. Bond,\n         General Ourumov is a hero\n         of the Soviet Union.\n"; db $0
align(4)

LarchE_string16:
 db "Bond: Ourumov stole it - he's a traitor.\n"; db $0
align(4)

LarchE_string17:
 db "Guard: Drop that weapon NOW!\n"; db $0
align(4)

LarchE_string18:
 db "Bond: Perhaps, he was once, but he has\n        betrayed you now.\n"; db $0
align(4)

LarchE_string19:
 db "Guard: All lies, Mr. Bond.\n         You are nothing but a terrorist.\n"; db $0
align(4)

LarchE_string20:
 db "Guard: You will be executed along with\n         that foolish girl.\n"; db $0
align(4)

LarchE_string21:
 db "Bond: Natalya has done nothing wrong.\n        She knows what happened at\n        Severnaya.\n"; db $0
align(4)

LarchE_string22:
 db "Guard: Really? Well, we shall have to\n         ask her about that.\n"; db $0
align(4)

LarchE_string23:
 db "Guard: I'm sure she can be persuaded\n         to answer our questions more\n         fully.\n"; db $0
align(4)

LarchE_string24:
 db "Guard: HALT!\n         You're going nowhere, Mr.Bond!\n"; db $0
align(4)

LarchE_string25:
 db "Soldier: New orders from General\n           Ourumov.\n           Kill the spy at once!\n"; db $0
align(4)

LarchE_string26:
 db "Mishkin: It appears you were correct,\n           Mr. Bond\n"; db $0
align(4)

LarchE_string27:
 db "Mishkin: General Ourumov is our traitor.\n"; db $0
align(4)

LarchE_string28:
 db "Bond: Even trusted friends are capable\n        of betrayal.\n"; db $0
align(4)

LarchE_string29:
 db "Mishkin: A costly lesson.\n"; db $0
align(4)

LarchE_string30:
 db "Mishkin: Do you need the black box\n           from the stolen helicopter?\n"; db $0
align(4)

LarchE_string31:
 db "Bond: Yes, it proves that Janus was\n        involved in the Severnaya incident.\n"; db $0
align(4)

LarchE_string32:
 db "Mishkin: It is in the safe.\n"; db $0
align(4)

LarchE_string33:
 db "Mishkin: I must inform the Politburo\n           of Ourumov's deceit.\n"; db $0
align(4)

LarchE_string34:
 db "Mishkin: Good-bye, Mr. Bond\n"; db $0
align(4)

LarchE_string35:
 db "Natalya: We need to talk to Defense\n           Minister Mishkin.\n"; db $0
align(4)

LarchE_string36:
 db "Got safe key\n"; db $0
align(4)

LarchE_string37:
 db "A R C H I V E S\n"; db $0
align(4)

LarchE_string38:
 db "captured by the russians, bond must escape their military prison.\n"; db $0
align(4)

LarchE_string39:
 db "again? captured again? i hope you can defend your performance, 007, because there isn't a lawyer in the land who'd take on the case.\nyour only chance is to speak directly to defense minister mishkin. he's a reasonable man, for a member of the politburo.\nfailure is not an option, bond.\n"; db $0
align(4)

LarchE_string40:
 db "up to you to get out of this one, 007. i can't hold your hand all the time. by the way, get that flight recorder for me, would you? thanks.\n"; db $0
align(4)

LarchE_string41:
 db "banged up again, james? now you know what it's like to be trapped behind a desk, and i'm off out to the theatre with a gentleman tonight. how times change!\n"; db $0
align(4)

LarchE_string42:
 db "escape from interrogation room\n"; db $0
align(4)

LarchE_string43:
 db "find natalya\n"; db $0
align(4)

LarchE_string44:
 db "recover helicopter black box\n"; db $0
align(4)

LarchE_string45:
 db "escape with natalya\n"; db $0
align(4)

LarchE_string46:
 db "GRU Military Intelligence Archives,\nSt. Petersburg\n"; db $0
align(4)

LarchE_string47:
 db "\n"; db $0
align(4)

LarchE_string48:
 db "door key\n"; db $0
align(4)

LarchE_string49:
 db "interrogation room key\n"; db $0
align(4)

LarchE_string50:
 db "interrogation room key\n"; db $0
align(4)

LarchE_string51:
db "Picked up a door key.\n"; db $0
align(4)

LarchE_string53:
 db "This safe is locked.\n"; db $0
align(4)

LarchE_string54:
 db "flight\n"; db $0
align(4)

LarchE_string55:
 db "recorder\n"; db $0
align(4)

LarchE_string56:
 db "flight recorder\n"; db $0
align(4)

LarchE_string57:
 db "pirate flight recorder\n"; db $0
align(4)

LarchE_string58:
 db "Picked up the flight recorder.\n"; db $0
align(4)

LarchE_string59:
 db "\n"; db $0
align(4)

LarchE_string60:
 db "safe key\n"; db $0
align(4)

LarchE_string61:
 db "safe key\n"; db $0
align(4)

LarchE_string62:
 db "Safe Key\n"; db $0
align(4)

LarchE_string63:
db "Picked up a safe key.\n"; db $0
db $0; align(32)

seg_LarchE_strings_end:
seg_LarchE_end:

