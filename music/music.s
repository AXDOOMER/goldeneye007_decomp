.section .music

.global music_sfx.ptr
music_sfx.ptr:
 .incbin "music/music_sfx.ptr.bin"
music_sfx.ptr_end:

.global music_sfx.bnk
music_sfx.bnk:
 .incbin "music/music_sfx.bnk.bin"
music_sfx.bnk_end:

.global music_somethinginmusic
music_somethinginmusic:
 .incbin "music/music_somethinginmusic.bin"
music_somethinginmusic_end:

.global music_moresomethinginmusic
music_moresomethinginmusic:
 .incbin "music/music_moresomethinginmusic.bin"
music_moresomethinginmusic_end:

.global music_sounds.ptr
music_sounds.ptr:
 .incbin "music/music_sounds.ptr.bin"
music_sounds.ptr_end:

.global music_sounds.bnk
music_sounds.bnk:
 .incbin "music/music_sounds.bnk.bin"
music_sounds.bnk_end:

.global number_music_samples
number_music_samples:
 .half 0x003F, 0x0000
number_music_samples_end:


.macro music_table_entry name sized
 .word \name - number_music_samples
 .half end_d_\name - d_\name
 .half end_\name - \name
.endm

.global music_table_music_data
music_table_music_data:
 music_table_entry music_no_music
 music_table_entry music_solo_death_abrev
 music_table_entry music_intro_eye
 music_table_entry music_train
 music_table_entry music_depot
 music_table_entry music_jungle_unused
 music_table_entry music_citadel
 music_table_entry music_facility
 music_table_entry music_control
 music_table_entry music_dam
 music_table_entry music_frigate
 music_table_entry music_archives
 music_table_entry music_silo
 music_table_entry music_jungle_perimeter_unused
 music_table_entry music_streets
 music_table_entry music_bunker1
 music_table_entry music_bunker2
 music_table_entry music_statue
 music_table_entry music_elevator_control
 music_table_entry music_cradle
 music_table_entry music_null1
 music_table_entry music_elevator_wc
 music_table_entry music_egyptian
 music_table_entry music_folders
 music_table_entry music_watchmusic
 music_table_entry music_aztec
 music_table_entry music_watercaverns
 music_table_entry music_deathsolo
 music_table_entry music_surface2
 music_table_entry music_trainx
 music_table_entry music_null2
 music_table_entry music_facilityx
 music_table_entry music_depotx
 music_table_entry music_controlx
 music_table_entry music_watercavernsx
 music_table_entry music_damx
 music_table_entry music_frigatex
 music_table_entry music_archivesx
 music_table_entry music_silox
 music_table_entry music_null3
 music_table_entry music_streetsx
 music_table_entry music_bunker1x
 music_table_entry music_bunker2x
 music_table_entry music_junglex
 music_table_entry music_nint_rare_logo
 music_table_entry music_statuex
 music_table_entry music_aztecx
 music_table_entry music_egyptianx
 music_table_entry music_cradlex
 music_table_entry music_cuba
 music_table_entry music_runway
 music_table_entry music_runway_plane
 music_table_entry music_surface2x
 music_table_entry music_windblowing
 music_table_entry music_multideath_alt
 music_table_entry music_jungle
 music_table_entry music_runwayx
 music_table_entry music_surface1
 music_table_entry music_multiplayerdeath
 music_table_entry music_surface1x
 music_table_entry music_surface2_ending
 music_table_entry music_statue_ending
 music_table_entry music_frigate_outro
music_table_music_data_end:

.global music_no_music
music_no_music:
 .incbin "music/music_no_music.rz"
end_music_no_music:

.global music_solo_death_abrev
music_solo_death_abrev:
 .incbin "music/music_solo_death_abrev.rz"
.byte 0xA
end_music_solo_death_abrev:

.global music_intro_eye
music_intro_eye:
 .incbin "music/music_intro_eye.rz"
end_music_intro_eye:

.global music_train
music_train:
 .incbin "music/music_train.rz"
.byte 0xA
end_music_train:

.global music_depot
music_depot:
 .incbin "music/music_depot.rz"
.byte 0xA
end_music_depot:

.global music_jungle_unused
music_jungle_unused:
 .incbin "music/music_jungle_unused.rz"
end_music_jungle_unused:

.global music_citadel
music_citadel:
 .incbin "music/music_citadel.rz"
.byte 0xA
end_music_citadel:

.global music_facility
music_facility:
 .incbin "music/music_facility.rz"
end_music_facility:

.global music_control
music_control:
 .incbin "music/music_control.rz"
end_music_control:

.global music_dam
music_dam:
 .incbin "music/music_dam.rz"
.byte 0xA
end_music_dam:

.global music_frigate
music_frigate:
 .incbin "music/music_frigate.rz"
end_music_frigate:

.global music_archives
music_archives:
 .incbin "music/music_archives.rz"
end_music_archives:

.global music_silo
music_silo:
 .incbin "music/music_silo.rz"
end_music_silo:

.global music_jungle_perimeter_unused
music_jungle_perimeter_unused:
 .incbin "music/music_jungle_perimeter_unused.rz"
.byte 0xA
end_music_jungle_perimeter_unused:

.global music_streets
music_streets:
 .incbin "music/music_streets.rz"
.byte 0xA
end_music_streets:

.global music_bunker1
music_bunker1:
 .incbin "music/music_bunker1.rz"
.byte 0xA
end_music_bunker1:

.global music_bunker2
music_bunker2:
 .incbin "music/music_bunker2.rz"
.byte 0xA
end_music_bunker2:

.global music_statue
music_statue:
 .incbin "music/music_statue.rz"
end_music_statue:

.global music_elevator_control
music_elevator_control:
 .incbin "music/music_elevator_control.rz"
.byte 0xA
end_music_elevator_control:

.global music_cradle
music_cradle:
 .incbin "music/music_cradle.rz"
.byte 0xA
end_music_cradle:

.global music_null1
music_null1:
 .incbin "music/music_null.rz"
.byte 0xA
end_music_null1:

.global music_elevator_wc
music_elevator_wc:
 .incbin "music/music_elevator_wc.rz"
.byte 0xA
end_music_elevator_wc:

.global music_egyptian
music_egyptian:
 .incbin "music/music_egyptian.rz"
end_music_egyptian:

.global music_folders
music_folders:
 .incbin "music/music_folders.rz"
end_music_folders:

.global music_watchmusic
music_watchmusic:
 .incbin "music/music_watchmusic.rz"
.byte 0xA
end_music_watchmusic:

.global music_aztec
music_aztec:
 .incbin "music/music_aztec.rz"
end_music_aztec:

.global music_watercaverns
music_watercaverns:
 .incbin "music/music_watercaverns.rz"
.byte 0xA
end_music_watercaverns:

.global music_deathsolo
music_deathsolo:
 .incbin "music/music_deathsolo.rz"
.byte 0xA
end_music_deathsolo:

.global music_surface2
music_surface2:
 .incbin "music/music_surface2.rz"
.byte 0xA
end_music_surface2:

.global music_trainx
music_trainx:
 .incbin "music/music_trainx.rz"
.byte 0xA
end_music_trainx:

.global music_null2
music_null2:
 .incbin "music/music_null.rz"
.byte 0xA
end_music_null2:

.global music_facilityx
music_facilityx:
 .incbin "music/music_facilityx.rz"
end_music_facilityx:

.global music_depotx
music_depotx:
 .incbin "music/music_depotx.rz"
end_music_depotx:

.global music_controlx
music_controlx:
 .incbin "music/music_controlx.rz"
end_music_controlx:

.global music_watercavernsx
music_watercavernsx:
 .incbin "music/music_watercavernsx.rz"
end_music_watercavernsx:

.global music_damx
music_damx:
 .incbin "music/music_damx.rz"
.byte 0xA
end_music_damx:

.global music_frigatex
music_frigatex:
 .incbin "music/music_frigatex.rz"
end_music_frigatex:

.global music_archivesx
music_archivesx:
 .incbin "music/music_archivesx.rz"
.byte 0xA
end_music_archivesx:

.global music_silox
music_silox:
 .incbin "music/music_silox.rz"
end_music_silox:

.global music_null3
music_null3:
 .incbin "music/music_null.rz"
.byte 0xA
end_music_null3:

.global music_streetsx
music_streetsx:
 .incbin "music/music_streetsx.rz"
end_music_streetsx:

.global music_bunker1x
music_bunker1x:
 .incbin "music/music_bunker1x.rz"
end_music_bunker1x:

.global music_bunker2x
music_bunker2x:
 .incbin "music/music_bunker2x.rz"
.byte 0xA
end_music_bunker2x:

.global music_junglex
music_junglex:
 .incbin "music/music_junglex.rz"
.byte 0xA
end_music_junglex:

.global music_nint_rare_logo
music_nint_rare_logo:
 .incbin "music/music_nint_rare_logo.rz"
end_music_nint_rare_logo:

.global music_statuex
music_statuex:
 .incbin "music/music_statuex.rz"
.byte 0xA
end_music_statuex:

.global music_aztecx
music_aztecx:
 .incbin "music/music_aztecx.rz"
end_music_aztecx:

.global music_egyptianx
music_egyptianx:
 .incbin "music/music_egyptianx.rz"
end_music_egyptianx:

.global music_cradlex
music_cradlex:
 .incbin "music/music_cradlex.rz"
.byte 0xA
end_music_cradlex:

.global music_cuba
music_cuba:
 .incbin "music/music_cuba.rz"
.byte 0xA
end_music_cuba:

.global music_runway
music_runway:
 .incbin "music/music_runway.rz"
end_music_runway:

.global music_runway_plane
music_runway_plane:
 .incbin "music/music_runway_plane.rz"
end_music_runway_plane:

.global music_surface2x
music_surface2x:
 .incbin "music/music_surfacex.rz"
end_music_surface2x:

.global music_windblowing
music_windblowing:
 .incbin "music/music_windblowing.rz"
.byte 0xA
end_music_windblowing:

.global music_multideath_alt
music_multideath_alt:
 .incbin "music/music_multideath_alt.rz"
end_music_multideath_alt:

.global music_jungle
music_jungle:
 .incbin "music/music_jungle.rz"
end_music_jungle:

.global music_runwayx
music_runwayx:
 .incbin "music/music_runwayx.rz"
end_music_runwayx:

.global music_surface1
music_surface1:
 .incbin "music/music_surface1.rz"
.byte 0xA
end_music_surface1:

.global music_multiplayerdeath
music_multiplayerdeath:
 .incbin "music/music_multiplayerdeath.rz"
end_music_multiplayerdeath:

.global music_surface1x
music_surface1x:
 .incbin "music/music_surfacex.rz"
end_music_surface1x:

.global music_surface2_ending
music_surface2_ending:
 .incbin "music/music_surface2_ending.rz"
.byte 0xA
end_music_surface2_ending:

.global music_statue_ending
music_statue_ending:
 .incbin "music/music_statue_ending.rz"
end_music_statue_ending:

.global music_frigate_outro
music_frigate_outro:
 .incbin "music/music_frigate_outro.rz"
.byte 0xA
end_music_frigate_outro:

.half 0
.word 0

.section .musicdiscard
d_music_no_music:
 .incbin "music/music_no_music.bin"
end_d_music_no_music:

.global d_music_solo_death_abrev
d_music_solo_death_abrev:
 .incbin "music/music_solo_death_abrev.bin"
end_d_music_solo_death_abrev:

.global d_music_intro_eye
d_music_intro_eye:
 .incbin "music/music_intro_eye.bin"
end_d_music_intro_eye:

.global d_music_train
d_music_train:
 .incbin "music/music_train.bin"
end_d_music_train:

.global d_music_depot
d_music_depot:
 .incbin "music/music_depot.bin"
end_d_music_depot:

.global d_music_jungle_unused
d_music_jungle_unused:
 .incbin "music/music_jungle_unused.bin"
end_d_music_jungle_unused:

.global d_music_citadel
d_music_citadel:
 .incbin "music/music_citadel.bin"
end_d_music_citadel:

.global d_music_facility
d_music_facility:
 .incbin "music/music_facility.bin"
end_d_music_facility:

.global d_music_control
d_music_control:
 .incbin "music/music_control.bin"
end_d_music_control:

.global d_music_dam
d_music_dam:
 .incbin "music/music_dam.bin"
end_d_music_dam:

.global d_music_frigate
d_music_frigate:
 .incbin "music/music_frigate.bin"
end_d_music_frigate:

.global d_music_archives
d_music_archives:
 .incbin "music/music_archives.bin"
end_d_music_archives:

.global d_music_silo
d_music_silo:
 .incbin "music/music_silo.bin"
end_d_music_silo:

.global d_music_jungle_perimeter_unused
d_music_jungle_perimeter_unused:
 .incbin "music/music_jungle_perimeter_unused.bin"
end_d_music_jungle_perimeter_unused:

.global d_music_streets
d_music_streets:
 .incbin "music/music_streets.bin"
end_d_music_streets:

.global d_music_bunker1
d_music_bunker1:
 .incbin "music/music_bunker1.bin"
end_d_music_bunker1:

.global d_music_bunker2
d_music_bunker2:
 .incbin "music/music_bunker2.bin"
end_d_music_bunker2:

.global d_music_statue
d_music_statue:
 .incbin "music/music_statue.bin"
end_d_music_statue:

.global d_music_elevator_control
d_music_elevator_control:
 .incbin "music/music_elevator_control.bin"
end_d_music_elevator_control:

.global d_music_cradle
d_music_cradle:
 .incbin "music/music_cradle.bin"
end_d_music_cradle:

.global d_music_null1
d_music_null1:
 .incbin "music/music_null.bin"
end_d_music_null1:

.global d_music_elevator_wc
d_music_elevator_wc:
 .incbin "music/music_elevator_wc.bin"
end_d_music_elevator_wc:

.global d_music_egyptian
d_music_egyptian:
 .incbin "music/music_egyptian.bin"
end_d_music_egyptian:

.global d_music_folders
d_music_folders:
 .incbin "music/music_folders.bin"
end_d_music_folders:

.global d_music_watchmusic
d_music_watchmusic:
 .incbin "music/music_watchmusic.bin"
end_d_music_watchmusic:

.global d_music_aztec
d_music_aztec:
 .incbin "music/music_aztec.bin"
end_d_music_aztec:

.global d_music_watercaverns
d_music_watercaverns:
 .incbin "music/music_watercaverns.bin"
end_d_music_watercaverns:

.global d_music_deathsolo
d_music_deathsolo:
 .incbin "music/music_deathsolo.bin"
end_d_music_deathsolo:

.global d_music_surface2
d_music_surface2:
 .incbin "music/music_surface2.bin"
end_d_music_surface2:

.global d_music_trainx
d_music_trainx:
 .incbin "music/music_trainx.bin"
end_d_music_trainx:

.global d_music_null2
d_music_null2:
 .incbin "music/music_null.bin"
end_d_music_null2:

.global d_music_facilityx
d_music_facilityx:
 .incbin "music/music_facilityx.bin"
end_d_music_facilityx:

.global d_music_depotx
d_music_depotx:
 .incbin "music/music_depotx.bin"
end_d_music_depotx:

.global d_music_controlx
d_music_controlx:
 .incbin "music/music_controlx.bin"
end_d_music_controlx:

.global d_music_watercavernsx
d_music_watercavernsx:
 .incbin "music/music_watercavernsx.bin"
end_d_music_watercavernsx:

.global d_music_damx
d_music_damx:
 .incbin "music/music_damx.bin"
end_d_music_damx:

.global d_music_frigatex
d_music_frigatex:
 .incbin "music/music_frigatex.bin"
end_d_music_frigatex:

.global d_music_archivesx
d_music_archivesx:
 .incbin "music/music_archivesx.bin"
end_d_music_archivesx:

.global d_music_silox
d_music_silox:
 .incbin "music/music_silox.bin"
end_d_music_silox:

.global d_music_null3
d_music_null3:
 .incbin "music/music_null.bin"
end_d_music_null3:

.global d_music_streetsx
d_music_streetsx:
 .incbin "music/music_streetsx.bin"
end_d_music_streetsx:

.global d_music_bunker1x
d_music_bunker1x:
 .incbin "music/music_bunker1x.bin"
end_d_music_bunker1x:

.global d_music_bunker2x
d_music_bunker2x:
 .incbin "music/music_bunker2x.bin"
end_d_music_bunker2x:

.global d_music_junglex
d_music_junglex:
 .incbin "music/music_junglex.bin"
end_d_music_junglex:

.global d_music_nint_rare_logo
d_music_nint_rare_logo:
 .incbin "music/music_nint_rare_logo.bin"
end_d_music_nint_rare_logo:

.global d_music_statuex
d_music_statuex:
 .incbin "music/music_statuex.bin"
end_d_music_statuex:

.global d_music_aztecx
d_music_aztecx:
 .incbin "music/music_aztecx.bin"
end_d_music_aztecx:

.global d_music_egyptianx
d_music_egyptianx:
 .incbin "music/music_egyptianx.bin"
end_d_music_egyptianx:

.global d_music_cradlex
d_music_cradlex:
 .incbin "music/music_cradlex.bin"
end_d_music_cradlex:

.global d_music_cuba
d_music_cuba:
 .incbin "music/music_cuba.bin"
end_d_music_cuba:

.global d_music_runway
d_music_runway:
 .incbin "music/music_runway.bin"
end_d_music_runway:

.global d_music_runway_plane
d_music_runway_plane:
 .incbin "music/music_runway_plane.bin"
end_d_music_runway_plane:

.global d_music_surface2x
d_music_surface2x:
 .incbin "music/music_surfacex.bin"
end_d_music_surface2x:

.global d_music_windblowing
d_music_windblowing:
 .incbin "music/music_windblowing.bin"
end_d_music_windblowing:

.global d_music_multideath_alt
d_music_multideath_alt:
 .incbin "music/music_multideath_alt.bin"
end_d_music_multideath_alt:

.global d_music_jungle
d_music_jungle:
 .incbin "music/music_jungle.bin"
end_d_music_jungle:

.global d_music_runwayx
d_music_runwayx:
 .incbin "music/music_runwayx.bin"
end_d_music_runwayx:

.global d_music_surface1
d_music_surface1:
 .incbin "music/music_surface1.bin"
end_d_music_surface1:

.global d_music_multiplayerdeath
d_music_multiplayerdeath:
 .incbin "music/music_multiplayerdeath.bin"
end_d_music_multiplayerdeath:

.global d_music_surface1x
d_music_surface1x:
 .incbin "music/music_surfacex.bin"
end_d_music_surface1x:

.global d_music_surface2_ending
d_music_surface2_ending:
 .incbin "music/music_surface2_ending.bin"
end_d_music_surface2_ending:

.global d_music_statue_ending
d_music_statue_ending:
 .incbin "music/music_statue_ending.bin"
end_d_music_statue_ending:

.global d_music_frigate_outro
d_music_frigate_outro:
 .incbin "music/music_frigate_outro.bin"
end_d_music_frigate_outro:
