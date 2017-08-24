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

.global music_number_music_samples
music_number_music_samples:
 .half 0x003F, 0x0000
music_number_music_samples_end:

.global music_table_music_data
music_table_music_data:
 .word music_no_music - music_number_music_samples
 .half 0x61
 .half music_no_music_end - music_no_music

 .word music_solo_death_abrev - music_number_music_samples
 .half 0x2DB
 .half music_solo_death_abrev_end - music_solo_death_abrev

 .word music_intro_eye - music_number_music_samples
 .half 0xEF2
 .half music_intro_eye_end - music_intro_eye

 .word music_train - music_number_music_samples
 .half 0x149E
 .half music_train_end - music_train

 .word music_depot - music_number_music_samples
 .half 0x1784
 .half music_depot_end - music_depot

 .word music_jungle_unused - music_number_music_samples
 .half 0x17DD
 .half music_jungle_unused_end - music_jungle_unused

 .word music_citadel - music_number_music_samples
 .half 0x171F
 .half music_citadel_end - music_citadel

 .word music_facility - music_number_music_samples
 .half 0xFEE
 .half music_facility_end - music_facility

 .word music_control - music_number_music_samples
 .half 0x1220
 .half music_control_end - music_control

 .word music_dam - music_number_music_samples
 .half 0x16C3
 .half music_dam_end - music_dam

 .word music_frigate - music_number_music_samples
 .half 0x1457
 .half music_frigate_end - music_frigate

 .word music_archives - music_number_music_samples
 .half 0xDB8
 .half music_archives_end - music_archives

 .word music_silo - music_number_music_samples
 .half 0x17BB
 .half music_silo_end - music_silo

 .word music_jungle_perimeter_unused - music_number_music_samples
 .half 0x172B
 .half music_jungle_perimeter_unused_end - music_jungle_perimeter_unused

 .word music_streets - music_number_music_samples
 .half 0x155D
 .half music_streets_end - music_streets

 .word music_bunker1 - music_number_music_samples
 .half 0xAAD
 .half music_bunker1_end - music_bunker1

 .word music_bunker2 - music_number_music_samples
 .half 0x95F
 .half music_bunker2_end - music_bunker2

 .word music_statue - music_number_music_samples
 .half 0xE37
 .half music_statue_end - music_statue

 .word music_elevator_control - music_number_music_samples
 .half 0xDC9
 .half music_elevator_control_end - music_elevator_control

 .word music_cradle - music_number_music_samples
 .half 0x1692
 .half music_cradle_end - music_cradle

 .word music_null1 - music_number_music_samples
 .half 0x60
 .half music_null1_end - music_null1

 .word music_elevator_wc - music_number_music_samples
 .half 0x9D8
 .half music_elevator_wc_end - music_elevator_wc

 .word music_egyptian - music_number_music_samples
 .half 0x15EA
 .half music_egyptian_end - music_egyptian

 .word music_folders - music_number_music_samples
 .half 0x5D8
 .half music_folders_end - music_folders

 .word music_watchmusic - music_number_music_samples
 .half 0x2FE
 .half music_watchmusic_end - music_watchmusic

 .word music_aztec - music_number_music_samples
 .half 0x1484
 .half music_aztec_end - music_aztec

 .word music_watercaverns - music_number_music_samples
 .half 0x1748
 .half music_watercaverns_end - music_watercaverns

 .word music_deathsolo - music_number_music_samples
 .half 0x560
 .half music_deathsolo_end - music_deathsolo

 .word music_surface2 - music_number_music_samples
 .half 0x1782
 .half music_surface2_end - music_surface2

 .word music_trainx - music_number_music_samples
 .half 0xE79
 .half music_trainx_end - music_trainx

 .word music_null2 - music_number_music_samples
 .half 0x60
 .half music_null2_end - music_null2

 .word music_facilityx - music_number_music_samples
 .half 0xE8A
 .half music_facilityx_end - music_facilityx

 .word music_depotx - music_number_music_samples
 .half 0xD1D
 .half music_depotx_end - music_depotx

 .word music_controlx - music_number_music_samples
 .half 0x933
 .half music_controlx_end - music_controlx

 .word music_watercavernsx - music_number_music_samples
 .half 0xCC0
 .half music_watercavernsx_end - music_watercavernsx

 .word music_damx - music_number_music_samples
 .half 0x94B
 .half music_damx_end - music_damx

 .word music_frigatex - music_number_music_samples
 .half 0x9CE
 .half music_frigatex_end - music_frigatex

 .word music_archivesx - music_number_music_samples
 .half 0xC8A
 .half music_archivesx_end - music_archivesx

 .word music_silox - music_number_music_samples
 .half 0xE82
 .half music_silox_end - music_silox

 .word music_null3 - music_number_music_samples
 .half 0x60
 .half music_null3_end - music_null3

 .word music_streetsx - music_number_music_samples
 .half 0xAC2
 .half music_streetsx_end - music_streetsx

 .word music_bunker1x - music_number_music_samples
 .half 0xD30
 .half music_bunker1x_end - music_bunker1x

 .word music_bunker2x - music_number_music_samples
 .half 0xAC6
 .half music_bunker2x_end - music_bunker2x

 .word music_junglex - music_number_music_samples
 .half 0xE60
 .half music_junglex_end - music_junglex

 .word music_nint_rare_logo - music_number_music_samples
 .half 0x5DA
 .half music_nint_rare_logo_end - music_nint_rare_logo

 .word music_statuex - music_number_music_samples
 .half 0xBE5
 .half music_statuex_end - music_statuex

 .word music_aztecx - music_number_music_samples
 .half 0xEC5
 .half music_aztecx_end - music_aztecx

 .word music_egyptianx - music_number_music_samples
 .half 0xF14
 .half music_egyptianx_end - music_egyptianx

 .word music_cradlex - music_number_music_samples
 .half 0xC36
 .half music_cradlex_end - music_cradlex

 .word music_cuba - music_number_music_samples
 .half 0xE0D
 .half music_cuba_end - music_cuba

 .word music_runway - music_number_music_samples
 .half 0x1616
 .half music_runway_end - music_runway

 .word music_runway_plane - music_number_music_samples
 .half 0x4F3
 .half music_runway_plane_end - music_runway_plane

 .word music_surface2x - music_number_music_samples
 .half 0xCA1
 .half music_surface2x_end - music_surface2x

 .word music_windblowing - music_number_music_samples
 .half 0x6BB
 .half music_windblowing_end - music_windblowing

 .word music_multideath_alt - music_number_music_samples
 .half 0x2ED
 .half music_multideath_alt_end - music_multideath_alt

 .word music_jungle - music_number_music_samples
 .half 0x997
 .half music_jungle_end - music_jungle

 .word music_runwayx - music_number_music_samples
 .half 0xB07
 .half music_runwayx_end - music_runwayx

 .word music_surface1 - music_number_music_samples
 .half 0x170C
 .half music_surface1_end - music_surface1

 .word music_multiplayerdeath - music_number_music_samples
 .half 0x446
 .half music_multiplayerdeath_end - music_multiplayerdeath

 .word music_surface1x - music_number_music_samples
 .half 0xCA1
 .half music_surface1x_end - music_surface1x

 .word music_surface2_ending - music_number_music_samples
 .half 0x37B
 .half music_surface2_ending_end - music_surface2_ending

 .word music_statue_ending - music_number_music_samples
 .half 0x1DB
 .half music_statue_ending_end - music_statue_ending

 .word music_frigate_outro - music_number_music_samples
 .half 0x35B
 .half music_frigate_outro_end - music_frigate_outro
music_table_music_data_end:

.global music_no_music
music_no_music:
 .incbin "music/music_no_music.bin"
music_no_music_end:

.global music_solo_death_abrev
music_solo_death_abrev:
 .incbin "music/music_solo_death_abrev.bin"
music_solo_death_abrev_end:

.global music_intro_eye
music_intro_eye:
 .incbin "music/music_intro_eye.bin"
music_intro_eye_end:

.global music_train
music_train:
 .incbin "music/music_train.bin"
music_train_end:

.global music_depot
music_depot:
 .incbin "music/music_depot.bin"
music_depot_end:

.global music_jungle_unused
music_jungle_unused:
 .incbin "music/music_jungle_unused.bin"
music_jungle_unused_end:

.global music_citadel
music_citadel:
 .incbin "music/music_citadel.bin"
music_citadel_end:

.global music_facility
music_facility:
 .incbin "music/music_facility.bin"
music_facility_end:

.global music_control
music_control:
 .incbin "music/music_control.bin"
music_control_end:

.global music_dam
music_dam:
 .incbin "music/music_dam.bin"
music_dam_end:

.global music_frigate
music_frigate:
 .incbin "music/music_frigate.bin"
music_frigate_end:

.global music_archives
music_archives:
 .incbin "music/music_archives.bin"
music_archives_end:

.global music_silo
music_silo:
 .incbin "music/music_silo.bin"
music_silo_end:

.global music_jungle_perimeter_unused
music_jungle_perimeter_unused:
 .incbin "music/music_jungle_perimeter_unused.bin"
music_jungle_perimeter_unused_end:

.global music_streets
music_streets:
 .incbin "music/music_streets.bin"
music_streets_end:

.global music_bunker1
music_bunker1:
 .incbin "music/music_bunker1.bin"
music_bunker1_end:

.global music_bunker2
music_bunker2:
 .incbin "music/music_bunker2.bin"
music_bunker2_end:

.global music_statue
music_statue:
 .incbin "music/music_statue.bin"
music_statue_end:

.global music_elevator_control
music_elevator_control:
 .incbin "music/music_elevator_control.bin"
music_elevator_control_end:

.global music_cradle
music_cradle:
 .incbin "music/music_cradle.bin"
music_cradle_end:

.global music_null1
music_null1:
 .incbin "music/music_null.bin"
music_null1_end:

.global music_elevator_wc
music_elevator_wc:
 .incbin "music/music_elevator_wc.bin"
music_elevator_wc_end:

.global music_egyptian
music_egyptian:
 .incbin "music/music_egyptian.bin"
music_egyptian_end:

.global music_folders
music_folders:
 .incbin "music/music_folders.bin"
music_folders_end:

.global music_watchmusic
music_watchmusic:
 .incbin "music/music_watchmusic.bin"
music_watchmusic_end:

.global music_aztec
music_aztec:
 .incbin "music/music_aztec.bin"
music_aztec_end:

.global music_watercaverns
music_watercaverns:
 .incbin "music/music_watercaverns.bin"
music_watercaverns_end:

.global music_deathsolo
music_deathsolo:
 .incbin "music/music_deathsolo.bin"
music_deathsolo_end:

.global music_surface2
music_surface2:
 .incbin "music/music_surface2.bin"
music_surface2_end:

.global music_trainx
music_trainx:
 .incbin "music/music_trainx.bin"
music_trainx_end:

.global music_null2
music_null2:
 .incbin "music/music_null.bin"
music_null2_end:

.global music_facilityx
music_facilityx:
 .incbin "music/music_facilityx.bin"
music_facilityx_end:

.global music_depotx
music_depotx:
 .incbin "music/music_depotx.bin"
music_depotx_end:

.global music_controlx
music_controlx:
 .incbin "music/music_controlx.bin"
music_controlx_end:

.global music_watercavernsx
music_watercavernsx:
 .incbin "music/music_watercavernsx.bin"
music_watercavernsx_end:

.global music_damx
music_damx:
 .incbin "music/music_damx.bin"
music_damx_end:

.global music_frigatex
music_frigatex:
 .incbin "music/music_frigatex.bin"
music_frigatex_end:

.global music_archivesx
music_archivesx:
 .incbin "music/music_archivesx.bin"
music_archivesx_end:

.global music_silox
music_silox:
 .incbin "music/music_silox.bin"
music_silox_end:

.global music_null3
music_null3:
 .incbin "music/music_null.bin"
music_null3_end:

.global music_streetsx
music_streetsx:
 .incbin "music/music_streetsx.bin"
music_streetsx_end:

.global music_bunker1x
music_bunker1x:
 .incbin "music/music_bunker1x.bin"
music_bunker1x_end:

.global music_bunker2x
music_bunker2x:
 .incbin "music/music_bunker2x.bin"
music_bunker2x_end:

.global music_junglex
music_junglex:
 .incbin "music/music_junglex.bin"
music_junglex_end:

.global music_nint_rare_logo
music_nint_rare_logo:
 .incbin "music/music_nint_rare_logo.bin"
music_nint_rare_logo_end:

.global music_statuex
music_statuex:
 .incbin "music/music_statuex.bin"
music_statuex_end:

.global music_aztecx
music_aztecx:
 .incbin "music/music_aztecx.bin"
music_aztecx_end:

.global music_egyptianx
music_egyptianx:
 .incbin "music/music_egyptianx.bin"
music_egyptianx_end:

.global music_cradlex
music_cradlex:
 .incbin "music/music_cradlex.bin"
music_cradlex_end:

.global music_cuba
music_cuba:
 .incbin "music/music_cuba.bin"
music_cuba_end:

.global music_runway
music_runway:
 .incbin "music/music_runway.bin"
music_runway_end:

.global music_runway_plane
music_runway_plane:
 .incbin "music/music_runway_plane.bin"
music_runway_plane_end:

.global music_surface2x
music_surface2x:
 .incbin "music/music_surface2x.bin"
music_surface2x_end:

.global music_windblowing
music_windblowing:
 .incbin "music/music_windblowing.bin"
music_windblowing_end:

.global music_multideath_alt
music_multideath_alt:
 .incbin "music/music_multideath_alt.bin"
music_multideath_alt_end:

.global music_jungle
music_jungle:
 .incbin "music/music_jungle.bin"
music_jungle_end:

.global music_runwayx
music_runwayx:
 .incbin "music/music_runwayx.bin"
music_runwayx_end:

.global music_surface1
music_surface1:
 .incbin "music/music_surface1.bin"
music_surface1_end:

.global music_multiplayerdeath
music_multiplayerdeath:
 .incbin "music/music_multiplayerdeath.bin"
music_multiplayerdeath_end:

.global music_surface1x
music_surface1x:
 .incbin "music/music_surface1x.bin"
music_surface1x_end:

.global music_surface2_ending
music_surface2_ending:
 .incbin "music/music_surface2_ending.bin"
music_surface2_ending_end:

.global music_statue_ending
music_statue_ending:
 .incbin "music/music_statue_ending.bin"
music_statue_ending_end:

.global music_frigate_outro
music_frigate_outro:
 .incbin "music/music_frigate_outro.bin"
music_frigate_outro_end:

.half 0
.word 0
