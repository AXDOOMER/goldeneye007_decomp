arch n64.cpu
endian msb
include "../../lib/N64.INC"
output "LstatE.bin", create

base $00000000
seg_LstatE_start:
seg_LstatE_header_start:

ptr_LstatE_string1:
 dw LstatE_string1

ptr_LstatE_string2:
 dw LstatE_string2

ptr_LstatE_string3:
 dw LstatE_string3

ptr_LstatE_string4:
 dw LstatE_string4

ptr_LstatE_string5:
 dw LstatE_string5

ptr_LstatE_string6:
 dw LstatE_string6

ptr_LstatE_string7:
 dw LstatE_string7

ptr_LstatE_string8:
 dw LstatE_string8

ptr_LstatE_string9:
 dw LstatE_string9

ptr_LstatE_string10:
 dw LstatE_string10

ptr_LstatE_string11:
 dw LstatE_string11

ptr_LstatE_string12:
 dw LstatE_string12

ptr_LstatE_string13:
 dw LstatE_string13

ptr_LstatE_string14:
 dw LstatE_string14

ptr_LstatE_string15:
 dw LstatE_string15

ptr_LstatE_string16:
 dw LstatE_string16

ptr_LstatE_string17:
 dw LstatE_string17

ptr_LstatE_string18:
 dw LstatE_string18

ptr_LstatE_string19:
 dw LstatE_string19

ptr_LstatE_string20:
 dw LstatE_string20

ptr_LstatE_string21:
 dw LstatE_string21

ptr_LstatE_string22:
 dw LstatE_string22

ptr_LstatE_string23:
 dw LstatE_string23

ptr_LstatE_string24:
 dw LstatE_string24

ptr_LstatE_string25:
 dw LstatE_string25

ptr_LstatE_string26:
 dw LstatE_string26

ptr_LstatE_string27:
 dw LstatE_string27

ptr_LstatE_string28:
 dw LstatE_string28

ptr_LstatE_string29:
 dw LstatE_string29

ptr_LstatE_string30:
 dw LstatE_string30

ptr_LstatE_string31:
 dw LstatE_string31

ptr_LstatE_string32:
 dw LstatE_string32

ptr_LstatE_string33:
 dw LstatE_string33

ptr_LstatE_string34:
 dw LstatE_string34

ptr_LstatE_string35:
 dw LstatE_string35

ptr_LstatE_string36:
 dw LstatE_string36

ptr_LstatE_string37:
 dw LstatE_string37

ptr_LstatE_string38:
 dw LstatE_string38

ptr_LstatE_string39:
 dw LstatE_string39

ptr_LstatE_string40:
 dw LstatE_string40

ptr_LstatE_string41:
 dw LstatE_string41

ptr_LstatE_string42:
 dw LstatE_string42

ptr_LstatE_string43:
 dw LstatE_string43

ptr_LstatE_string44:
 dw LstatE_string44

ptr_LstatE_string45:
 dw LstatE_string45

ptr_LstatE_string46:
 dw LstatE_string46

ptr_LstatE_string47:
 dw LstatE_string47

ptr_LstatE_string48:
 dw LstatE_string48

ptr_LstatE_string49:
 dw LstatE_string49

ptr_LstatE_string50:
 dw LstatE_string50

ptr_LstatE_string51:
 dw LstatE_string51

ptr_LstatE_string52:
 dw LstatE_string52

ptr_LstatE_string53:
 dw LstatE_string53

ptr_LstatE_string54:
 dw LstatE_string54

ptr_LstatE_string55:
 dw LstatE_string55

ptr_LstatE_string56:
 dw LstatE_string56

ptr_LstatE_string57:
 dw LstatE_string57

ptr_LstatE_string58:
 dw LstatE_string58

ptr_LstatE_string59:
 dw LstatE_string59

ptr_LstatE_string60:
 dw LstatE_string60

ptr_LstatE_string61:
 dw LstatE_string61

ptr_LstatE_string62:
 dw LstatE_string62

ptr_LstatE_string63:
 dw LstatE_string63

ptr_LstatE_string64:
 dw LstatE_string64

ptr_LstatE_string65:
 dw LstatE_string65

ptr_LstatE_string66:
 dw LstatE_string66

ptr_LstatE_string67:
 dw LstatE_string67

ptr_LstatE_string68:
 dw LstatE_string68

seg_LstatE_header_end:
seg_LstatE_strings_start:

LstatE_string1:
 db "Following the Severnaya incident, MI6 has lost track of the Pirate helicopter. Presumably the bugging device has been located and destroyed. Natalya Simonova, who returned to St. Petersburg against our advice, has gone missing. We can only assume that she has been abducted by the Janus syndicate in a belated attempt to cover their tracks.\n"; db $0
align(4)

LstatE_string2:
 db "The situation is critical, 007. Janus know we're on to them and they're taking control. We're going to circumvent the usual channels on this one. I've arranged contact with an ex-KGB agent, Valentin Zukovsky, in Statue Park, St. Petersburg. He claims he can set up a meeting with Janus. Apparently, the head of Janus wants to see you in person. Frankly, I'm uneasy about this but it's all we've got to go on.\n"; db $0
align(4)

LstatE_string3:
 db "No gizmos this time, old boy.\n"; db $0
align(4)

LstatE_string4:
 db "Hmm, a damsel in distress.\n\nJust be careful with that chopper, James.\n"; db $0
align(4)

LstatE_string5:
 db "Contact Valentin\n"; db $0
align(4)

LstatE_string6:
 db "Confront and unmask Janus\n"; db $0
align(4)

LstatE_string7:
 db "Locate helicopter\n"; db $0
align(4)

LstatE_string8:
 db "Rescue Natalya\n"; db $0
align(4)

LstatE_string9:
 db "Find flight recorder\n"; db $0
align(4)

LstatE_string10:
 db "Valentin: Good evening, Mr. Bond.\n           These are strange times...\n"; db $0
align(4)

LstatE_string11:
 db "Bond: With an ex-KGB agent meeting\n        an MI6 operative in the middle\n        of St. Petersburg?\n"; db $0
align(4)

LstatE_string12:
 db "Valentin: Ha! I never thought I'd find\n           myself helping you, but things\n           have changed in Russia.\n"; db $0
align(4)

LstatE_string13:
 db "Valentin: Janus will meet you by Lenin's\n           statue. Beware him, he's a Lienz\n           Cossack traitor.\n"; db $0
align(4)

LstatE_string14:
 db "Valentin: Now I must leave - the guards\n           are out in force and I fear they\n           may mistake me for a spy!\n"; db $0
align(4)

LstatE_string15:
 db "Valentin: I'm risking my life being here,\n           Mr Bond! You could at least\n           be civil enough to listen to me.\n"; db $0
align(4)

LstatE_string16:
 db "Valentin has left. Contact failed!\n"; db $0
align(4)

LstatE_string17:
 db "null\n"; db $0
align(4)

LstatE_string18:
 db "null\n"; db $0
align(4)

LstatE_string19:
 db "Janus: Good evening, 007.\n"; db $0
align(4)

LstatE_string20:
 db "Janus: Put the gun away.\n         It's insulting to think I haven't\n         anticipated your every move.\n"; db $0
align(4)

LstatE_string21:
 db "Janus: There's a good fellow.\n"; db $0
align(4)

LstatE_string22:
 db "Trevelyan: So stubborn, James.\n              You always did think you\n              knew best.\n"; db $0
align(4)

LstatE_string23:
 db "Bond: Alec? You're Janus?\n"; db $0
align(4)

LstatE_string24:
 db "Trevelyan: Yes, the MI6 'hero',\n              back from the dead.\n"; db $0
align(4)

LstatE_string25:
 db "Bond: But why, Alec? I trusted you.\n"; db $0
align(4)

LstatE_string26:
 db "Trevelyan: Trust can be misplaced,\n              James. My parents trusted\n              the British government.\n"; db $0
align(4)

LstatE_string27:
 db "Trevelyan: They were betrayed with all\n              the other Lienz Cossacks.\n              I will have my revenge.\n"; db $0
align(4)

LstatE_string28:
 db "Bond: What have you done with Natalya?\n"; db $0
align(4)

LstatE_string29:
 db "Trevelyan: The girl? I've left her with\n              the Pirate helicopter at the\n              park gates.\n"; db $0
align(4)

LstatE_string30:
 db "Trevelyan: We've finished with them.\n              I have the Goldeneye\n              firing key now.\n"; db $0
align(4)

LstatE_string31:
 db "Trevelyan: By the way, the helicopter's\n              rigged to blow in 3 minutes.\n              I doubt she'll survive.\n"; db $0
align(4)

LstatE_string32:
 db "3 Minutes until helicopter bomb explodes.\n"; db $0
align(4)

LstatE_string33:
 db "Helicopter destroyed.\n"; db $0
align(4)

LstatE_string34:
 db "Janus: If he won't drop the gun kill him!\n"; db $0
align(4)

LstatE_string35:
 db "Janus: You're an impatient fool, 007, \n         and now you'll die for it.\n"; db $0
align(4)

LstatE_string36:
 db "Natalya: James!\n"; db $0
align(4)

LstatE_string37:
 db "Bond: Quickly, this way!\n        The helicopter's about to explode.\n"; db $0
align(4)

LstatE_string38:
 db "Bond: I have to find the helicopter flight\n        recorder. Wait for me at the gates.\n"; db $0
align(4)

LstatE_string39:
 db "Bond: Natalya!\n"; db $0
align(4)

LstatE_string40:
 db "The flight recorder could not have been\nthrown this far from the helicopter\nexplosion!\n"; db $0
align(4)

LstatE_string41:
 db "Mishkin: Ah, Mr Bond. I see you've taken\n           it upon yourself to liven up the\n           nightlife in St. Petersburg.\n"; db $0
align(4)

LstatE_string42:
 db "Mishkin: Blowing up helicopters,\n           shooting guards\n           - quite a jolly little soiree.\n"; db $0
align(4)

LstatE_string43:
 db "Mishkin: Well, it's time to stop now,\n           before any more people get\n           hurt.\n"; db $0
align(4)

LstatE_string44:
 db "Mishkin: I'd like to ask you and Miss\n           Simonova some questions\n           about the Severnaya incident.\n"; db $0
align(4)

LstatE_string45:
 db "Mishkin: Perhaps you'd care to lead the\n           way to Military Intelligence HQ.\n"; db $0
align(4)

LstatE_string46:
 db "Mishkin: There's a truck waiting outside.\n"; db $0
align(4)

LstatE_string47:
 db "Mishkin: Come back Mr. Bond,\n           there's no other way out!\n"; db $0
align(4)

LstatE_string48:
 db "Mishkin: Come along Mr. Bond, just step\n           through the gates and we can\n           clear up this misunderstanding.\n"; db $0
align(4)

LstatE_string49:
 db "Valentin is dead - mission failure!\n"; db $0
align(4)

LstatE_string50:
 db "Trevelyan: Closing time, James\n              - last call.\n"; db $0
align(4)

LstatE_string51:
 db "Proximity fuse triggered.\n15 seconds to helicopter detonation!\n"; db $0
align(4)

LstatE_string52:
 db "Janus: No gun, 007? \n         MI6 must be cutting their budget\n         these days.\n"; db $0
align(4)

LstatE_string53:
 db "S T A T U E   P A R K\n"; db $0
align(4)

LstatE_string54:
 db "following the severnaya incident, MI6 has lost track of the pirate helicopter. presumably the bugging device has been located and destroyed. natalya simonova, who returned to st. petersburg against our advice, has gone missing. we can only assume that she has been abducted by the janus syndicate in a belated attempt to cover their tracks.\n"; db $0
align(4)

LstatE_string55:
 db "the situation is critical, 007. janus know we're on to them and they're taking control. we're going to circumvent the usual channels on this one. i've arranged contact with an ex-kgb agent, valentin zukovsky, in statue park, st. petersburg. he claims he can set up a meeting with janus. apparently, the head of janus wants to see you in person. frankly, i'm uneasy about this but it's all we've got to go on.\n"; db $0
align(4)

LstatE_string56:
 db "no gizmos this time, old boy.\n"; db $0
align(4)

LstatE_string57:
 db "hmm, a damsel in distress, james.\njust be careful with that chopper.\n"; db $0
align(4)

LstatE_string58:
 db "contact valentin\n"; db $0
align(4)

LstatE_string59:
 db "confront and unmask janus\n"; db $0
align(4)

LstatE_string60:
 db "locate helicopter\n"; db $0
align(4)

LstatE_string61:
 db "rescue natalya\n"; db $0
align(4)

LstatE_string62:
 db "find flight recorder\n"; db $0
align(4)

LstatE_string63:
 db "Statue Park, St. Petersburg\n"; db $0
align(4)

LstatE_string64:
 db "flight\n"; db $0
align(4)

LstatE_string65:
 db "recorder\n"; db $0
align(4)

LstatE_string66:
 db "flight recorder\n"; db $0
align(4)

LstatE_string67:
 db "pirate flight recorder\n"; db $0
align(4)

LstatE_string68:
 db "Recovered the flight recorder.\n"; db $0
align(16)

seg_LstatE_strings_end:
seg_LstatE_end:

