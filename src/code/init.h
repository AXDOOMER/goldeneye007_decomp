#ifndef _INIT_H_
#define _INIT_H_
#include <ultra64.h>

extern OSThread rmonThread;
extern OSThread idleThread;
extern OSThread mainThread;
extern OSThread shedThread;
extern OSMesgQueue gfxFrameMsgQ;
extern OSMesg gfxFrameMsgBuf[32];
extern OSMesgQueue *sched_cmdQ;
extern OSSched sc;
extern OSScClient gfxClient;

extern u32 unknown_init_val;
extern u32 cart_hw_address;

#endif
