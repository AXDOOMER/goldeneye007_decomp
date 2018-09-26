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

extern u8 sp_boot[];
extern u8 sp_rmon[];
extern u8 sp_idle[];
extern u8 sp_shed[];
extern u8 sp_main[];
extern u8 sp_audi[];
