#ifndef _BG_H_
#define _BG_H_
#include "ultra64.h"

#define LEVELID_BUNKER1 0x9
#define LEVELID_SILO 0x14
#define LEVELID_STATUE 0x16
#define LEVELID_CONTROL 0x17
#define LEVELID_ARCHIVES 0x18
#define LEVELID_TRAIN 0x19
#define LEVELID_FRIGATE 0x1A
#define LEVELID_BUNKER2 0x1B
#define LEVELID_AZTEC 0x1C
#define LEVELID_STREETS 0x1D
#define LEVELID_DEPOT 0x1E
#define LEVELID_COMPLEX 0x1F
#define LEVELID_EGYPT 0x20
#define LEVELID_DAM 0x21
#define LEVELID_FACILITY 0x22
#define LEVELID_RUNWAY 0x23
#define LEVELID_SURFACE 0x24
#define LEVELID_JUNGLE 0x25
#define LEVELID_TEMPLE 0x26
#define LEVELID_CAVERNS 0x27
#define LEVELID_CITADEL 0x28
#define LEVELID_CRADLE 0x29
#define LEVELID_SHO 0x2A
#define LEVELID_SURFACE2 0x2B
#define LEVELID_ELD 0x2C
#define LEVELID_BASEMENT 0x2D
#define LEVELID_STACK 0x2E
#define LEVELID_LUE 0x2F
#define LEVELID_LIBRARY 0x30
#define LEVELID_RIT 0x31
#define LEVELID_CAVES 0x32
#define LEVELID_EAR 0x33
#define LEVELID_LEE 0x34
#define LEVELID_LIP 0x35
#define LEVELID_CUBA 0x36
#define LEVELID_WAX 0x37
#define LEVELID_PAM 0x38
#define LEVELID_MAX 0x39
#define LEVELID_NONE 0xFFFFFFFF

struct levelentry
{
  int levelID;
  void *bg_seg_filename;
  void *bg_stan_filename;
  float levelscale;
  float visibility;
  float unknownfloat;
};
#pragma pack(pop)

#endif
