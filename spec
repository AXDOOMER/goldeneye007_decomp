/*
 * ROM spec file
 */

beginseg
    name "makerom"
    include "build/baserom/makerom.o"
    address 0x80000000
endseg

beginseg
    name "boot"
    include "build/asm/boot.o"
    address 0x80000450
endseg

beginseg
    name "code"
    include "build/asm/code.o"
    address 0x70000510
endseg

beginseg
    name "compresseddata"
    include "build/compressed/compresseddata.o"
	//address 0x00021990
endseg

beginseg
    name "rarezip"
    include "build/asm/rarezip.o"
    address 0x70200000
endseg

beginseg
    name "game"
    include "build/asm/game.o"
    address 0x7f000000
endseg

beginseg
    name "unknown117880"
    include "build/baserom/unknown117880.o"
    //address 0x004bf790
endseg

beginseg
    name "unknown117940"
    include "build/baserom/unknown117940.o"
    //address 0x004bf790
endseg

beginseg
    name "unknown123040"
    include "build/baserom/unknown123040.o"
    //address 0x004bf790
endseg
\\\

beginseg
	name "animation_table"
	include "build/baserom/animation_table.o"
	//address 0x00124ac0
endseg

beginseg
	name "animation_data"
	include "build/baserom/animation_data.o"
	//address 0x0028e980
endseg

beginseg
	name "Globalimagetable"
	include "build/baserom/Globalimagetable.o"
	//address 0x0029D160
endseg

beginseg
	name "Globalimagetable_commandblock"
	include "build/baserom/Globalimagetable_commandblock.o"
	//address 0x0029E560
endseg

beginseg
	name "unknown2A4D50"
	include "build/baserom/unknown2A4D50.o"
	//address 0x002A4D50
endseg

beginseg
	name "ramrom_Dam_1"
	include "build/baserom/ramrom_Dam_1.o"
	//address 0x002bf2d0
endseg

beginseg
	name "ramrom_Dam_2"
	include "build/baserom/ramrom_Dam_2.o"
	//address 0x002C44D0
endseg

beginseg
	name "ramrom_Facility_1"
	include "build/baserom/ramrom_Facility_1.o"
	//address 0x002C64A0
endseg

beginseg
	name "ramrom_Facility_2"
	include "build/baserom/ramrom_Facility_2.o"
	//address 0x002C7F50
endseg

beginseg
	name "ramrom_Facility_3"
	include "build/baserom/ramrom_Facility_3.o"
	//address 0x002CA330
endseg

beginseg
	name "ramrom_Runway_1"
	include "build/baserom/ramrom_Runway_1.o"
	//address 0x002CBFA0
endseg

beginseg
	name "ramrom_Runway_2"
	include "build/baserom/ramrom_Runway_2.o"
	//address 0x002CE6F0
endseg

beginseg
	name "ramrom_BunkerI_1"
	include "build/baserom/ramrom_BunkerI_1.o"
	//address 0x002D1000
endseg

beginseg
	name "ramrom_BunkerI_2"
	include "build/baserom/ramrom_BunkerI_2.o"
	//address 0x002D4390
endseg

beginseg
	name "ramrom_Silo_1"
	include "build/baserom/ramrom_Silo_1.o"
	//address 0x002D9610
endseg

beginseg
	name "ramrom_Silo_2"
	include "build/baserom/ramrom_Silo_2.o"
	//address 0x002DB7A0
endseg

beginseg
	name "ramrom_Frigate_1"
	include "build/baserom/ramrom_Frigate_1.o"
	//address 0x002DD770
endseg

beginseg
	name "ramrom_Frigate_2"
	include "build/baserom/ramrom_Frigate_2.o"
	//address 0x002DF120
endseg

beginseg
	name "ramrom_Train"
	include "build/baserom/ramrom_Train.o"
	//address 0x002E2600
endseg

beginseg
	name "font_first_font_table_controller_small"
	include "build/baserom/font_first_font_table_controller_small.o"
	//address 0x002E63F0
endseg

beginseg
	name "font_second_font_table_controller_small"
	include "build/baserom/font_second_font_table_controller_small.o"
	//address 0x002E6694
endseg

beginseg
	name "font_first_font_table_controller_large"
	include "build/baserom/font_first_font_table_controller_large.o"
	//address 0x002E88A0
endseg

beginseg
	name "font_second_font_table_controller_large"
	include "build/baserom/font_second_font_table_controller_large.o"
	//address 0x002E8B44
endseg

beginseg
	name "sfx.ctl"
	include "build/baserom/sfx.ctl.o"
	//address 0x002EBDE0
endseg

beginseg
	name "sfx.tbl"
	include "build/baserom/sfx.tbl.o"
	//address 0x002F19A0
endseg

beginseg
	name "music_somethinginmusic"
	include "build/baserom/music_somethinginmusic.o"
	//address 0x00392BBD
endseg

beginseg
	name "music_moresomethinginmusic"
	include "build/baserom/music_moresomethinginmusic.o"
	//address 0x003A045B
endseg

beginseg
	name "music_sounds.ptr"
	include "build/baserom/music_sounds.ptr"
	//address 0x003B4450
endseg

beginseg
	name "music_sounds.bnk"
	include "build/baserom/music_sounds.bnk"
	//address 0x003B87F0
endseg

beginseg
	name "music_number_music_samples"
	include "build/baserom/music_number_music_samples.o"
	//address 0x00419790
endseg

beginseg
	name "music_table_music_data"
	include "build/baserom/music_table_music_data.o"
	//address 0x00419794
endseg

beginseg
	name "Mno_musicZ"
	include "build/baserom/Mno_musicZ.o"
	//address 0x41998c
endseg

beginseg
	name "Msolo_death_abrevZ"
	include "build/baserom/Msolo_death_abrevZ.o"
	//address 0x4199b6
endseg

beginseg
	name "Mintro_eyeZ"
	include "build/baserom/Mintro_eyeZ.o"
	//address 0x419b8c
endseg

beginseg
	name "MtrainZ"
	include "build/baserom/MtrainZ.o"
	//address 0x41a43a
endseg

beginseg
	name "MdepotZ"
	include "build/baserom/MdepotZ.o"
	//address 0x41b024
endseg

beginseg
	name "Mjungle_unusedZ"
	include "build/baserom/Mjungle_unusedZ.o"
	//address 0x41bdc4
endseg

beginseg
	name "McitadelZ"
	include "build/baserom/McitadelZ.o"
	//address 0x41cb5c
endseg

beginseg
	name "MfacilityZ"
	include "build/baserom/MfacilityZ.o"
	//address 0x41d91c
endseg

beginseg
	name "McontrolZ"
	include "build/baserom/McontrolZ.o"
	//address 0x41e3ea
endseg

beginseg
	name "MdamZ"
	include "build/baserom/MdamZ.o"
	//address 0x41ef48
endseg

beginseg
	name "MfrigateZ"
	include "build/baserom/MfrigateZ.o"
	//address 0x41fd4c
endseg

beginseg
	name "MarchivesZ"
	include "build/baserom/MarchivesZ.o"
	//address 0x420b2c
endseg

beginseg
	name "MsiloZ"
	include "build/baserom/MsiloZ.o"
	//address 0x421480
endseg

beginseg
	name "Mjungle_perimeter_unusedZ"
	include "build/baserom/Mjungle_perimeter_unusedZ.o"
	//address 0x4222f0
endseg

beginseg
	name "MstreetsZ"
	include "build/baserom/MstreetsZ.o"
	//address 0x42325c
endseg

beginseg
	name "Mbunker1Z"
	include "build/baserom/Mbunker1Z.o"
	//address 0x423f5e
endseg

beginseg
	name "Mbunker2Z"
	include "build/baserom/Mbunker2Z.o"
	//address 0x4245d0
endseg

beginseg
	name "MstatueZ"
	include "build/baserom/MstatueZ.o"
	//address 0x424c50
endseg

beginseg
	name "Melevator_controlZ"
	include "build/baserom/Melevator_controlZ.o"
	//address 0x4255e8
endseg

beginseg
	name "McradleZ"
	include "build/baserom/McradleZ.o"
	//address 0x425fc2
endseg

beginseg
	name "Mnull1Z"
	include "build/baserom/Mnull1Z.o"
	//address 0x426d22
endseg

beginseg
	name "Melevator_wcZ"
	include "build/baserom/Melevator_wcZ.o"
	//address 0x426d4c
endseg

beginseg
	name "MegyptianZ"
	include "build/baserom/MegyptianZ.o"
	//address 0x427392
endseg

beginseg
	name "MfoldersZ"
	include "build/baserom/MfoldersZ.o"
	//address 0x42812c
endseg

beginseg
	name "MwatchmusicZ"
	include "build/baserom/MwatchmusicZ.o"
	//address 0x42850e
endseg

beginseg
	name "MaztecZ"
	include "build/baserom/MaztecZ.o"
	//address 0x428700
endseg

beginseg
	name "MwatercavernsZ"
	include "build/baserom/MwatercavernsZ.o"
	//address 0x429372
endseg

beginseg
	name "MdeathsoloZ"
	include "build/baserom/MdeathsoloZ.o"
	//address 0x42a19e
endseg

beginseg
	name "Msurface2Z"
	include "build/baserom/Msurface2Z.o"
	//address 0x42a504
endseg

beginseg
	name "MtrainxZ"
	include "build/baserom/MtrainxZ.o"
	//address 0x42b2ba
endseg

beginseg
	name "Mnull2Z"
	include "build/baserom/Mnull2Z.o"
	//address 0x42bb5a
endseg

beginseg
	name "MfacilityxZ"
	include "build/baserom/MfacilityxZ.o"
	//address 0x42bb84
endseg

beginseg
	name "MdepotxZ"
	include "build/baserom/MdepotxZ.o"
	//address 0x42c4dc
endseg

beginseg
	name "McontrolxZ"
	include "build/baserom/McontrolxZ.o"
	//address 0x42cc98
endseg

beginseg
	name "MwatercavernsxZ"
	include "build/baserom/MwatercavernsxZ.o"
	//address 0x42d1e0
endseg

beginseg
	name "MdamxZ"
	include "build/baserom/MdamxZ.o"
	//address 0x42d934
endseg

beginseg
	name "MfrigatexZ"
	include "build/baserom/MfrigatexZ.o"
	//address 0x42de54
endseg

beginseg
	name "MarchivesxZ"
	include "build/baserom/MarchivesxZ.o"
	//address 0x42e416
endseg

beginseg
	name "MsiloxZ"
	include "build/baserom/MsiloxZ.o"
	//address 0x42eb3a
endseg

beginseg
	name "Mnull3Z"
	include "build/baserom/Mnull3Z.o"
	//address 0x42f42e
endseg

beginseg
	name "MstreetsxZ"
	include "build/baserom/MstreetsxZ.o"
	//address 0x42f458
endseg

beginseg
	name "Mbunker1xZ"
	include "build/baserom/Mbunker1xZ.o"
	//address 0x42fac4
endseg

beginseg
	name "Mbunker2xZ"
	include "build/baserom/Mbunker2xZ.o"
	//address 0x43026a
endseg

beginseg
	name "MjunglexZ"
	include "build/baserom/MjunglexZ.o"
	//address 0x4308b8
endseg

beginseg
	name "Mnint_rare_logoZ"
	include "build/baserom/Mnint_rare_logoZ.o"
	//address 0x4310ce
endseg

beginseg
	name "MstatuexZ"
	include "build/baserom/MstatuexZ.o"
	//address 0x431500
endseg

beginseg
	name "MaztecxZ"
	include "build/baserom/MaztecxZ.o"
	//address 0x431bb8
endseg

beginseg
	name "MegyptianxZ"
	include "build/baserom/MegyptianxZ.o"
	//address 0x43248e
endseg

beginseg
	name "McradlexZ"
	include "build/baserom/McradlexZ.o"
	//address 0x432d3e
endseg

beginseg
	name "McubaZ"
	include "build/baserom/McubaZ.o"
	//address 0x433408
endseg

beginseg
	name "MrunwayZ"
	include "build/baserom/MrunwayZ.o"
	//address 0x433c52
endseg

beginseg
	name "Mrunway_planeZ"
	include "build/baserom/Mrunway_planeZ.o"
	//address 0x434970
endseg

beginseg
	name "Msurface2xZ"
	include "build/baserom/Msurface2xZ.o"
	//address 0x434c4a
endseg

beginseg
	name "MwindblowingZ"
	include "build/baserom/MwindblowingZ.o"
	//address 0x435372
endseg

beginseg
	name "Mmultideath_altZ"
	include "build/baserom/Mmultideath_altZ.o"
	//address 0x435894
endseg

beginseg
	name "MjungleZ"
	include "build/baserom/MjungleZ.o"
	//address 0x435aa0
endseg

beginseg
	name "MrunwayxZ"
	include "build/baserom/MrunwayxZ.o"
	//address 0x436228
endseg

beginseg
	name "Msurface1Z"
	include "build/baserom/Msurface1Z.o"
	//address 0x43684a
endseg

beginseg
	name "MmultiplayerdeathZ"
	include "build/baserom/MmultiplayerdeathZ.o"
	//address 0x4375b2
endseg

beginseg
	name "Msurface1xZ"
	include "build/baserom/Msurface1xZ.o"
	//address 0x43787a
endseg

beginseg
	name "Msurface2_endingZ"
	include "build/baserom/Msurface2_endingZ.o"
	//address 0x437fa2
endseg

beginseg
	name "Mstatue_endingZ"
	include "build/baserom/Mstatue_endingZ.o"
	//address 0x43823e
endseg

beginseg
	name "Mfrigate_outroZ"
	include "build/baserom/Mfrigate_outroZ.o"
	//address 0x4383a4
endseg

beginseg
    name "obseg"
    include "build/baserom/obseg.o"
    //address 0x004bf790
endseg

beginseg
    name "images"
    include "build/baserom/images.o"
    //address 0x008f7df0
endseg