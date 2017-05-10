base origin()
mp_setup_rom_start:

//vaddr is unknown
//base $vaddr
//setup_vaddr:

insert Ump_setupameZ, "setup/Ump_setupameZ", (origin() - $0089e9e0)
insert Ump_setuparchZ, "setup/Ump_setuparchZ", (origin() - $0089f100)
insert Ump_setuparkZ, "setup/Ump_setuparkZ", (origin() - $008a1ea0)
insert Ump_setupashZ, "setup/Ump_setupashZ", (origin() - $008a3be0)
insert Ump_setupcaveZ, "setup/Ump_setupcaveZ", (origin() - $008a42d0)
insert Ump_setupcradZ, "setup/Ump_setupcradZ", (origin() - $008a6830)
insert Ump_setupcrypZ, "setup/Ump_setupcrypZ", (origin() - $008a7190)
insert Ump_setupdishZ, "setup/Ump_setupdishZ", (origin() - $008a7ef0)
insert Ump_setupimpZ, "setup/Ump_setupimpZ", (origin() - $008a82e0)
insert Ump_setupoatZ, "setup/Ump_setupoatZ", (origin() - $008a8920)
insert Ump_setuprefZ, "setup/Ump_setuprefZ", (origin() - $008a8c70)
insert Ump_setupsevbZ, "setup/Ump_setupsevbZ", (origin() - $008a9080)
insert Ump_setupstatueZ, "setup/Ump_setupstatueZ", (origin() - $008aa390)
mp_setup_rom_end:

setup_rom_start:
insert UsetuparchZ, "setup/UsetuparchZ", (origin() - $008ab210)
insert UsetuparkZ, "setup/UsetuparkZ", (origin() - $008af820)
insert UsetupaztZ, "setup/UsetupaztZ", (origin() - $008b33b0)
insert UsetupcaveZ, "setup/UsetupcaveZ", (origin() - $008b5cb0)
insert UsetupcontrolZ, "setup/UsetupcontrolZ", (origin() - $008b9b10)
insert UsetupcradZ, "setup/UsetupcradZ", (origin() - $008bd610)
insert UsetupcrypZ, "setup/UsetupcrypZ", (origin() - $008bf240)
insert UsetupdamZ, "setup/UsetupdamZ", (origin() - $008c10d0)
insert UsetupdepoZ, "setup/UsetupdepoZ", (origin() - $008c53a0)
insert UsetupdestZ, "setup/UsetupdestZ", (origin() - $008c8330)
insert UsetupjunZ, "setup/UsetupjunZ", (origin() - $008ca680)
insert UsetuplenZ, "setup/UsetuplenZ", (origin() - $008cdd80)
insert UsetuppeteZ, "setup/UsetuppeteZ", (origin() - $008ce350)
insert UsetuprunZ, "setup/UsetuprunZ", (origin() - $008d12d0)
insert UsetupsevbZ, "setup/UsetupsevbZ", (origin() - $008d2b30)
insert UsetupsevbunkerZ, "setup/UsetupsevbunkerZ", (origin() - $008d5190)
insert UsetupsevxZ, "setup/UsetupsevxZ", (origin() - $008d6bc0)
insert UsetupsevxbZ, "setup/UsetupsevxbZ", (origin() - $008daed0)
insert UsetupsiloZ, "setup/UsetupsiloZ", (origin() - $008defc0)
insert UsetupstatueZ, "setup/UsetupstatueZ", (origin() - $008e1a10)
insert UsetuptraZ, "setup/UsetuptraZ", (origin() - $008e41e0)

setup_rom_end:
