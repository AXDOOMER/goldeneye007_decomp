#ifndef _EEPROM_H_
#define _EEPROM_H_
#include "ultra64.h"

struct save_data
{
  int chksum1;
  int chksum2;
  char completion_bitflags;
  char flag_007;
  char music_vol;
  char sfx_vol;
  char controller_config;
  char options;
  char unlocked_cheats_1;
  char unlocked_cheats_2;
  char unlocked_cheats_3;
  char field_11;
  unsigned agent_dam_time :10;
  unsigned agent_facility_time :10;
  unsigned agent_runway_time :10;
  unsigned agent_surface1_time :10;
  unsigned agent_bunker1_time :10;
  unsigned agent_silo_time :10;
  unsigned agent_frigate_time :10;
  unsigned agent_surface2_time :10;
  unsigned agent_bunker2_time :10;
  unsigned agent_statue_time :10;
  unsigned agent_archives_time :10;
  unsigned agent_streets_time :10;
  unsigned agent_depot_time :10;
  unsigned agent_train_time :10;
  unsigned agent_jungle_time :10;
  unsigned agent_control_time :10;
  unsigned agent_caverns_time :10;
  unsigned agent_cradle_time :10;
  unsigned agent_aztec_time :10;
  unsigned agent_egyptian_time :10;

  unsigned secretagent_dam_time :10;
  unsigned secretagent_facility_time :10;
  unsigned secretagent_runway_time :10;
  unsigned secretagent_surface1_time :10;
  unsigned secretagent_bunker1_time :10;
  unsigned secretagent_silo_time :10;
  unsigned secretagent_frigate_time :10;
  unsigned secretagent_surface2_time :10;
  unsigned secretagent_bunker2_time :10;
  unsigned secretagent_statue_time :10;
  unsigned secretagent_archives_time :10;
  unsigned secretagent_streets_time :10;
  unsigned secretagent_depot_time :10;
  unsigned secretagent_train_time :10;
  unsigned secretagent_jungle_time :10;
  unsigned secretagent_control_time :10;
  unsigned secretagent_caverns_time :10;
  unsigned secretagent_cradle_time :10;
  unsigned secretagent_aztec_time :10;
  unsigned secretagent_egyptian_time :10;

  unsigned agent00_dam_time :10;
  unsigned agent00_facility_time :10;
  unsigned agent00_runway_time :10;
  unsigned agent00_surface1_time :10;
  unsigned agent00_bunker1_time :10;
  unsigned agent00_silo_time :10;
  unsigned agent00_frigate_time :10;
  unsigned agent00_surface2_time :10;
  unsigned agent00_bunker2_time :10;
  unsigned agent00_statue_time :10;
  unsigned agent00_archives_time :10;
  unsigned agent00_streets_time :10;
  unsigned agent00_depot_time :10;
  unsigned agent00_train_time :10;
  unsigned agent00_jungle_time :10;
  unsigned agent00_control_time :10;
  unsigned agent00_caverns_time :10;
  unsigned agent00_cradle_time :10;
  unsigned agent00_aztec_time :10;
  unsigned agent00_egyptian_time :10;

  char unused1;
  char unused2;
  char unused3;
};

#endif