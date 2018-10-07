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

void init(void);
void *set_stack_entry(u8 *stack, u32 size);
void set_hw_address_and_unknown(void);
void thread1_idle(void *arg);
void start_idle_thread(void);
void start_rmon_thread(void);
void init_scheduler(void);
void thread3_main(void *args);
void setuplastentryofdebughandler(void);

#endif
