#stan
$(BUILD_DIR)/$(OBSEG_DIR)/stan/%.rz: $(OBSEG_DIR)/stan/%.bin
	$(RZ_COMP) $< $@

STAN_RZ_FILES = \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_ame_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_arch_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_arec_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_ark_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_ash_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_azt_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_cat_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_cave_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_crad_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_cryp_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_dam_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_depo_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_dest_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_dish_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_imp_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_jun_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_len_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_oat_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_pete_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_ref_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_run_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_sev_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_sevb_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_sevx_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_silo_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_stat_all_p_stanZ.rz \
    $(BUILD_DIR)/$(OBSEG_DIR)/stan/Tbg_tra_all_p_stanZ.rz 

