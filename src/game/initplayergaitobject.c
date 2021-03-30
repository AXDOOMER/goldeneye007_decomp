#include "ultra64.h"
#include "game/chrobjdata.h"

void init_player_gait_object(void) {
  player_gait_object_header.RootNode = (int)&player_gait_hdr;
  return;
}

