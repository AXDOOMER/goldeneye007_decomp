#include "ultra64.h"
#include "game/chrobjdata.h"

void sub_GAME_7F000B60(void) {
  player_gait_object.RootNode = (int)&player_gait_hdr;
  return;
}

