base origin()
bg_rom_start:

//vaddr is unknown
//base $vaddr
//bg_vaddr:

insert bg_sev_all_p.seg, "bg_sev_all_p.seg", (origin() - $00438660)
insert bg_silo_all_p.seg, "bg_silo_all_p.seg", (origin() - $00449450)
insert bg_stat_all_p.seg, "bg_stat_all_p.seg", (origin() - $0049a390)
insert bg_arec_all_p.seg, "bg_arec_all_p.seg", (origin() - $004bc460)
insert bg_arch_all_p.seg, "bg_arch_all_p.seg", (origin() - $004ea7e0)
insert bg_tra_all_p.seg, "bg_tra_all_p.seg", (origin() - $005102d0)
insert bg_dest_all_p.seg, "bg_dest_all_p.seg", (origin() - $00530840)
insert bg_sevb_all_p.seg, "bg_sevb_all_p.seg", (origin() - $0055e200)
insert bg_azt_all_p.seg, "bg_azt_all_p.seg", (origin() - $00578fa0)
insert bg_pete_all_p.seg, "bg_pete_all_p.seg", (origin() - $0059a9f0)
insert bg_depo_all_p.seg, "bg_depo_all_p.seg", (origin() - $005b4620)
insert bg_ref_all_p.seg, "bg_ref_all_p.seg", (origin() - $005e0f90)
insert bg_cryp_all_p.seg, "bg_cryp_all_p.seg", (origin() - $005ea5a0)
insert bg_dam_all_p.seg, "bg_dam_all_p.seg", (origin() - $005ffc50)
insert bg_ark_all_p.seg, "bg_ark_all_p.seg", (origin() - $0062fdf0)
insert bg_run_all_p.seg, "bg_run_all_p.seg", (origin() - $00660d70)
insert bg_sevx_all_p.seg, "bg_sevx_all_p.seg", (origin() - $0066b140)
insert bg_jun_all_p.seg, "bg_jun_all_p.seg", (origin() - $00687710)
insert bg_dish_all_p.seg, "bg_dish_all_p.seg", (origin() - $0069c860)
insert bg_cave_all_p.seg, "bg_cave_all_p.seg", (origin() - $006a10d0)
insert bg_cat_all_p.seg, "bg_cat_all_p.seg", (origin() - $006c55c0)
insert bg_crad_all_p.seg, "bg_crad_all_p.seg", (origin() - $006caaf0)
insert bg_imp_all_p.seg, "bg_imp_all_p.seg", (origin() - $006dae40)
insert bg_ash_all_p.seg, "bg_ash_all_p.seg", (origin() - $006dae40)
insert bg_ame_all_p.seg, "bg_ame_all_p.seg", (origin() - $006dae40)
insert bg_oat_all_p.seg, "bg_oat_all_p.seg", (origin() - $006e4da0)
insert bg_len_all_p.seg, "bg_len_all_p.seg", (origin() - $006ebbf0)

bg_rom_end:
