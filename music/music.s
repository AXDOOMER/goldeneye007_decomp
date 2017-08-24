.section .music

.global sfx.ctl
sfx.ctl:
 .incbin "music/sfx.ctl"
sfx.ctl_end:

.global sfx.tbl
sfx.tbl:
 .incbin "music/sfx.tbl"
sfx.tbl_end:

.global music_sounds.ptr
music_sounds.ptr:
 .incbin "music/instruments.ctl"
music_sounds.ptr_end:

.global music_sounds.bnk
music_sounds.bnk:
 .incbin "music/instruments.tbl"
music_sounds.bnk_end:

.global number_music_samples
number_music_samples:
 .half (music_table_music_data_end - music_table_music_data)/8
 .half 0x0000
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


.macro music_file name
\name:
 .incbin "music\/\name\.rz"
end_\name:
.endm

/*
music_fileA is used for the entries that end with A....the A doesn't seem to be from compression
*/

.macro music_fileA name
\name:
 .incbin "music\/\name\.rz"
 .byte 0xA
end_\name:
.endm

music_file music_no_music
music_fileA music_solo_death_abrev
music_file music_intro_eye
music_fileA music_train
music_fileA music_depot
music_file music_jungle_unused
music_fileA music_citadel
music_file music_facility
music_file music_control
music_fileA music_dam
music_file music_frigate
music_file music_archives
music_file music_silo
music_fileA music_jungle_perimeter_unused
music_fileA music_streets
music_fileA music_bunker1
music_fileA music_bunker2
music_file music_statue
music_fileA music_elevator_control
music_fileA music_cradle
music_fileA music_null1
music_fileA music_elevator_wc
music_file music_egyptian
music_file music_folders
music_fileA music_watchmusic
music_file music_aztec
music_fileA music_watercaverns
music_fileA music_deathsolo
music_fileA music_surface2
music_fileA music_trainx
music_fileA music_null2
music_file music_facilityx
music_file music_depotx
music_file music_controlx
music_file music_watercavernsx
music_fileA music_damx
music_file music_frigatex
music_fileA music_archivesx
music_file music_silox
music_fileA music_null3
music_file music_streetsx
music_file music_bunker1x
music_fileA music_bunker2x
music_fileA music_junglex
music_file music_nint_rare_logo
music_fileA music_statuex
music_file music_aztecx
music_file music_egyptianx
music_fileA music_cradlex
music_fileA music_cuba
music_file music_runway
music_file music_runway_plane
music_file music_surface2x
music_fileA music_windblowing
music_file music_multideath_alt
music_file music_jungle
music_file music_runwayx
music_fileA music_surface1
music_file music_multiplayerdeath
music_file music_surface1x
music_fileA music_surface2_ending
music_file music_statue_ending
music_fileA music_frigate_outro

.half 0
.word 0

.section .musicdiscard
/*
This sections sole purpose is to provide the decompressed size to the music table entry
*/
.macro d_music_file name
d_\name:
 .incbin "music\/\name\.bin"
end_d_\name:
.endm

d_music_file music_no_music
d_music_file music_solo_death_abrev
d_music_file music_intro_eye
d_music_file music_train
d_music_file music_depot
d_music_file music_jungle_unused
d_music_file music_citadel
d_music_file music_facility
d_music_file music_control
d_music_file music_dam
d_music_file music_frigate
d_music_file music_archives
d_music_file music_silo
d_music_file music_jungle_perimeter_unused
d_music_file music_streets
d_music_file music_bunker1
d_music_file music_bunker2
d_music_file music_statue
d_music_file music_elevator_control
d_music_file music_cradle
d_music_file music_null1
d_music_file music_elevator_wc
d_music_file music_egyptian
d_music_file music_folders
d_music_file music_watchmusic
d_music_file music_aztec
d_music_file music_watercaverns
d_music_file music_deathsolo
d_music_file music_surface2
d_music_file music_trainx
d_music_file music_null2
d_music_file music_facilityx
d_music_file music_depotx
d_music_file music_controlx
d_music_file music_watercavernsx
d_music_file music_damx
d_music_file music_frigatex
d_music_file music_archivesx
d_music_file music_silox
d_music_file music_null3
d_music_file music_streetsx
d_music_file music_bunker1x
d_music_file music_bunker2x
d_music_file music_junglex
d_music_file music_nint_rare_logo
d_music_file music_statuex
d_music_file music_aztecx
d_music_file music_egyptianx
d_music_file music_cradlex
d_music_file music_cuba
d_music_file music_runway
d_music_file music_runway_plane
d_music_file music_surface2x
d_music_file music_windblowing
d_music_file music_multideath_alt
d_music_file music_jungle
d_music_file music_runwayx
d_music_file music_surface1
d_music_file music_multiplayerdeath
d_music_file music_surface1x
d_music_file music_surface2_ending
d_music_file music_statue_ending
d_music_file music_frigate_outro

