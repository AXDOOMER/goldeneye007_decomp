#include "ultra64.h"
#include "joy.h"
#include "libultra/os.h"

struct contsample {
	OSContPad pads[MAXCONTROLLERS];
};

struct contdata {
    /* 0x000 */ struct contsample samples[20];
    /* 0x1E0 */ s32 curlast; 
	/* 0x1E4 */ s32 curstart;
	/* 0x1E8 */ s32 nextlast;
	/* 0x1EC */ s32 nextsecondlast;
    /* 0x1F0 */ u16 buttonspressed[4];
	/* 0x1F8 */ s32 unk1f8;
};

struct contdata g_ContData[2];
//80065328
char contdemoMesg[0x28];
//80065350
OSMesgQueue contdemoMesgMQ;

//80065368
OSMesg cont1Mesg;
OSMesgQueue cont1MesgMQ;

//80065388
OSMesg cont2Mesg;
OSMesgQueue cont2MesgMQ;

//800653a8
OSMesg cont3Mesg;
OSMesgQueue cont3MesgMQ;

//800653c8
OSMesg cont4Mesg;
OSMesgQueue cont4MesgMQ;

//800653e8
OSContStatus g_ContStatus[MAXCONTROLLERS];
OSPfs player1_controller_packet[MAXCONTROLLERS];

s32 D_800268C0 = 0;
struct contdata *g_ContDataPtr = &g_ContData[0];
s32 g_ContBusy = 0;
s32 D_800268CC = 0;
u8 g_ConnectedControllers = 0;
u8 D_800268D4 = 0;
s32 controller_1_rumble_inserted[MAXCONTROLLERS] = {0};
s32 controller_1_rumble_state[MAXCONTROLLERS] = {0};
s32 controller_1_rumble_duration[MAXCONTROLLERS] = {0};
s32 controller_1_rumble_pulse[MAXCONTROLLERS] = {0};
s32 g_ContQueuesCreated = 0;
s32 g_ContInitDone = 0;
s32 D_80026920 = 0;
s32 (*D_80026924)(struct contsample *samples, s32 samplenum) = NULL;
void (*D_80026928)(struct contsample *samples, s32 samplenum, s32 samplenum2) = NULL;
s32 g_ContNeedsInit = 1;
u32 g_ContBadReadsStickX[4] = {0};
u32 g_ContBadReadsStickY[4] = {0};
u32 g_ContBadReadsButtons[4] = {0};
u32 g_ContBadReadsButtonsPressed[4] = {0};
s32 D_80026970 = 0;

void contSystemInit(void) {
    s32 i;
    s32 j;

    debTryAdd(&D_800268C0, "joy_c_debug");

    osCreateMesgQueue(&cont1MesgMQ, &cont1Mesg, 1);
    osCreateMesgQueue(&cont2MesgMQ, &cont2Mesg, 1);
    osCreateMesgQueue(&cont3MesgMQ, &cont3Mesg, 1);
    osCreateMesgQueue(&cont4MesgMQ, &cont4Mesg, 1);
    osCreateMesgQueue(&contdemoMesgMQ, &contdemoMesg, 10);

    osSetEventMesg(OS_EVENT_SI, &contdemoMesgMQ, NULL);

    g_ContQueuesCreated = 1;

    D_80026924 = 0;
    D_80026928 = 0;

    for (i = 0; i < 2; i++) {
        g_ContData[i].curlast = 0;
		g_ContData[i].curstart = 0;
		g_ContData[i].nextlast = 0;
		g_ContData[i].nextsecondlast = 0;
		g_ContData[i].unk1f8 = -1;

		for (j = 0; j < 4; j++) {
			g_ContData[i].samples[0].pads[j].button = 0;
			g_ContData[i].samples[0].pads[j].stick_x = 0;
			g_ContData[i].samples[0].pads[j].stick_y = 0;
			g_ContData[i].samples[0].pads[j].errnum = 0;
		}

    }
}

void test_controller_presence(void) {
    OSMesg  msg;

    if (g_ContQueuesCreated) {
        osSendMesg(&cont1MesgMQ, &msg, OS_MESG_NOBLOCK);
        osRecvMesg(&cont2MesgMQ, &msg, OS_MESG_BLOCK);
        
        controller_check_for_rumble_maybe();

        osSendMesg(&cont3MesgMQ, &msg, OS_MESG_NOBLOCK);
        osRecvMesg(&cont4MesgMQ, &msg, OS_MESG_BLOCK);
    }
}

s32 osPfsChecker(OSPfs *arg0) {
    return 3;
}

void controller_7000B734(s32 index)
{
    s32 ret;
    if (controller_1_rumble_inserted[index] >= 0) {
        if ((g_ContStatus[index].type & CONT_JOYPORT) && (g_ContStatus[index].status & CONT_CARD_ON)) {        
            ret = osPfsInit(&contdemoMesgMQ, &player1_controller_packet[index], index);
            if ((ret == PFS_ERR_ID_FATAL) || (ret == PFS_ERR_DEVICE)) {
                if (osMotorInit(&contdemoMesgMQ, &player1_controller_packet[index], index) == 0) {
                    controller_1_rumble_inserted[index] = 1;
                } else {
                    controller_1_rumble_inserted[index] = -1;
                }
            }
        }
    }
}

#ifdef NONMATCHING
// Regalloc + Needs 4 extra bytes on the stack
void controller_check_for_rumble_maybe(void)
{
    s8 i;
    if (g_ContNeedsInit) {
        g_ContNeedsInit = FALSE;
        osContInit(&contdemoMesgMQ, &g_ConnectedControllers, g_ContStatus);
        g_ContInitDone = TRUE;
    } else {
        u32 slots = 0xF;
        s32 i;

        osContStartQuery(&contdemoMesgMQ);
        osRecvMesg(&contdemoMesgMQ, NULL, OS_MESG_BLOCK);
        osContGetQuery(g_ContStatus);

        for (i = 0; i < MAXCONTROLLERS; i++) {
			if (g_ContStatus[i].errnum & CONT_NO_RESPONSE_ERROR) {
				slots -= 1 << i;
			}
		}

        g_ConnectedControllers = slots;
    }

    for (i = 0; i < MAXCONTROLLERS; i++) {
        // Removed
    }

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if ((g_ConnectedControllers & (1 << i)) && (g_ContStatus[i].type & (CONT_ABSOLUTE | CONT_RELATIVE)) && (g_ContStatus[i].errnum == 0)) {             
            if (((D_800268D4 == 0) & (1 << i)) || (controller_1_rumble_inserted[i] <= 0)) {
                controller_7000B734(i);
            }
            D_800268D4 |= (1 << i);
        } else if (D_800268D4 & (1 << i)) {
            D_800268D4 ^= (1 << i);
            controller_1_rumble_inserted[i] = 0;                
        }
    }

    if (0);
}
#else
GLOBAL_ASM(
.text
glabel controller_check_for_rumble_maybe
/* 00C410 7000B810 3C028002 */  lui   $v0, %hi(g_ContNeedsInit)
/* 00C414 7000B814 2442692C */  addiu $v0, %lo(g_ContNeedsInit) # addiu $v0, $v0, 0x692c
/* 00C418 7000B818 8C4E0000 */  lw    $t6, ($v0)
/* 00C41C 7000B81C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00C420 7000B820 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00C424 7000B824 11C0000D */  beqz  $t6, .L7000B85C
/* 00C428 7000B828 AFB00018 */   sw    $s0, 0x18($sp)
/* 00C42C 7000B82C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C430 7000B830 3C058002 */  lui   $a1, %hi(g_ConnectedControllers)
/* 00C434 7000B834 3C068006 */  lui   $a2, %hi(g_ContStatus)
/* 00C438 7000B838 AC400000 */  sw    $zero, ($v0)
/* 00C43C 7000B83C 24C653E8 */  addiu $a2, %lo(g_ContStatus) # addiu $a2, $a2, 0x53e8
/* 00C440 7000B840 24A568D0 */  addiu $a1, %lo(g_ConnectedControllers) # addiu $a1, $a1, 0x68d0
/* 00C444 7000B844 0C005240 */  jal   osContInit
/* 00C448 7000B848 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C44C 7000B84C 240F0001 */  li    $t7, 1
/* 00C450 7000B850 3C018002 */  lui   $at, %hi(g_ContInitDone)
/* 00C454 7000B854 10000026 */  b     .L7000B8F0
/* 00C458 7000B858 AC2F691C */   sw    $t7, %lo(g_ContInitDone)($at)
.L7000B85C:
/* 00C45C 7000B85C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C460 7000B860 2410000F */  li    $s0, 15
/* 00C464 7000B864 0C005330 */  jal   osContStartQuery
/* 00C468 7000B868 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C46C 7000B86C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C470 7000B870 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C474 7000B874 00002825 */  move  $a1, $zero
/* 00C478 7000B878 0C003774 */  jal   osRecvMesg
/* 00C47C 7000B87C 24060001 */   li    $a2, 1
/* 00C480 7000B880 3C048006 */  lui   $a0, %hi(g_ContStatus)
/* 00C484 7000B884 0C005351 */  jal   osContGetQuery
/* 00C488 7000B888 248453E8 */   addiu $a0, %lo(g_ContStatus) # addiu $a0, $a0, 0x53e8
/* 00C48C 7000B88C 3C188006 */  lui   $t8, %hi(g_ContStatus+3) 
/* 00C490 7000B890 931853EB */  lbu   $t8, %lo(g_ContStatus+3)($t8)
/* 00C494 7000B894 3C088006 */  lui   $t0, %hi(g_ContStatus+7) 
/* 00C498 7000B898 3C0A8006 */  lui   $t2, %hi(g_ContStatus+11) 
/* 00C49C 7000B89C 33190008 */  andi  $t9, $t8, 8
/* 00C4A0 7000B8A0 13200002 */  beqz  $t9, .L7000B8AC
/* 00C4A4 7000B8A4 3C0C8006 */   lui   $t4, %hi(g_ContStatus+15) 
/* 00C4A8 7000B8A8 2410000E */  li    $s0, 14
.L7000B8AC:
/* 00C4AC 7000B8AC 910853EF */  lbu   $t0, %lo(g_ContStatus+7)($t0)
/* 00C4B0 7000B8B0 3C018002 */  lui   $at, %hi(g_ConnectedControllers)
/* 00C4B4 7000B8B4 31090008 */  andi  $t1, $t0, 8
/* 00C4B8 7000B8B8 11200002 */  beqz  $t1, .L7000B8C4
/* 00C4BC 7000B8BC 00000000 */   nop   
/* 00C4C0 7000B8C0 2610FFFE */  addiu $s0, $s0, -2
.L7000B8C4:
/* 00C4C4 7000B8C4 914A53F3 */  lbu   $t2, %lo(g_ContStatus+11)($t2)
/* 00C4C8 7000B8C8 314B0008 */  andi  $t3, $t2, 8
/* 00C4CC 7000B8CC 11600002 */  beqz  $t3, .L7000B8D8
/* 00C4D0 7000B8D0 00000000 */   nop   
/* 00C4D4 7000B8D4 2610FFFC */  addiu $s0, $s0, -4
.L7000B8D8:
/* 00C4D8 7000B8D8 918C53F7 */  lbu   $t4, %lo(g_ContStatus+15)($t4)
/* 00C4DC 7000B8DC 318D0008 */  andi  $t5, $t4, 8
/* 00C4E0 7000B8E0 11A00002 */  beqz  $t5, .L7000B8EC
/* 00C4E4 7000B8E4 00000000 */   nop   
/* 00C4E8 7000B8E8 2610FFF8 */  addiu $s0, $s0, -8
.L7000B8EC:
/* 00C4EC 7000B8EC A03068D0 */  sb    $s0, %lo(g_ConnectedControllers)($at)
.L7000B8F0:
/* 00C4F0 7000B8F0 00008025 */  move  $s0, $zero
/* 00C4F4 7000B8F4 26100001 */  addiu $s0, $s0, 1
.L7000B8F8:
/* 00C4F8 7000B8F8 00107600 */  sll   $t6, $s0, 0x18
/* 00C4FC 7000B8FC 000E8603 */  sra   $s0, $t6, 0x18
/* 00C500 7000B900 2A010004 */  slti  $at, $s0, 4
/* 00C504 7000B904 5420FFFC */  bnezl $at, .L7000B8F8
/* 00C508 7000B908 26100001 */   addiu $s0, $s0, 1
/* 00C50C 7000B90C 3C078002 */  lui   $a3, %hi(D_800268D4)
/* 00C510 7000B910 3C068002 */  lui   $a2, %hi(controller_1_rumble_inserted)
/* 00C514 7000B914 24C668D8 */  addiu $a2, %lo(controller_1_rumble_inserted) # addiu $a2, $a2, 0x68d8
/* 00C518 7000B918 24E768D4 */  addiu $a3, %lo(D_800268D4) # addiu $a3, $a3, 0x68d4
/* 00C51C 7000B91C 00008025 */  move  $s0, $zero
.L7000B920:
/* 00C520 7000B920 3C198002 */  lui   $t9, %hi(g_ConnectedControllers) 
/* 00C524 7000B924 933968D0 */  lbu   $t9, %lo(g_ConnectedControllers)($t9)
/* 00C528 7000B928 24180001 */  li    $t8, 1
/* 00C52C 7000B92C 02182804 */  sllv  $a1, $t8, $s0
/* 00C530 7000B930 03254024 */  and   $t0, $t9, $a1
/* 00C534 7000B934 1100001E */  beqz  $t0, .L7000B9B0
/* 00C538 7000B938 90E30000 */   lbu   $v1, ($a3)
/* 00C53C 7000B93C 3C098006 */  lui   $t1, %hi(g_ContStatus) 
/* 00C540 7000B940 252953E8 */  addiu $t1, %lo(g_ContStatus) # addiu $t1, $t1, 0x53e8
/* 00C544 7000B944 00102080 */  sll   $a0, $s0, 2
/* 00C548 7000B948 00891021 */  addu  $v0, $a0, $t1
/* 00C54C 7000B94C 944A0000 */  lhu   $t2, ($v0)
/* 00C550 7000B950 314B0003 */  andi  $t3, $t2, 3
/* 00C554 7000B954 51600017 */  beql  $t3, $zero, .L7000B9B4
/* 00C558 7000B958 0065C824 */   and   $t9, $v1, $a1
/* 00C55C 7000B95C 904C0003 */  lbu   $t4, 3($v0)
/* 00C560 7000B960 2C620001 */  sltiu $v0, $v1, 1
/* 00C564 7000B964 00456824 */  and   $t5, $v0, $a1
/* 00C568 7000B968 55800012 */  bnezl $t4, .L7000B9B4
/* 00C56C 7000B96C 0065C824 */   and   $t9, $v1, $a1
/* 00C570 7000B970 15A00003 */  bnez  $t5, .L7000B980
/* 00C574 7000B974 00C47021 */   addu  $t6, $a2, $a0
/* 00C578 7000B978 8DCF0000 */  lw    $t7, ($t6)
/* 00C57C 7000B97C 1DE00009 */  bgtz  $t7, .L7000B9A4
.L7000B980:
/* 00C580 7000B980 02002025 */   move  $a0, $s0
/* 00C584 7000B984 0C002DCD */  jal   controller_7000B734
/* 00C588 7000B988 AFA50024 */   sw    $a1, 0x24($sp)
/* 00C58C 7000B98C 3C078002 */  lui   $a3, %hi(D_800268D4)
/* 00C590 7000B990 24E768D4 */  addiu $a3, %lo(D_800268D4) # addiu $a3, $a3, 0x68d4
/* 00C594 7000B994 3C068002 */  lui   $a2, %hi(controller_1_rumble_inserted)
/* 00C598 7000B998 24C668D8 */  addiu $a2, %lo(controller_1_rumble_inserted) # addiu $a2, $a2, 0x68d8
/* 00C59C 7000B99C 90E30000 */  lbu   $v1, ($a3)
/* 00C5A0 7000B9A0 8FA50024 */  lw    $a1, 0x24($sp)
.L7000B9A4:
/* 00C5A4 7000B9A4 0065C025 */  or    $t8, $v1, $a1
/* 00C5A8 7000B9A8 10000008 */  b     .L7000B9CC
/* 00C5AC 7000B9AC A0F80000 */   sb    $t8, ($a3)
.L7000B9B0:
/* 00C5B0 7000B9B0 0065C824 */  and   $t9, $v1, $a1
.L7000B9B4:
/* 00C5B4 7000B9B4 13200005 */  beqz  $t9, .L7000B9CC
/* 00C5B8 7000B9B8 00654026 */   xor   $t0, $v1, $a1
/* 00C5BC 7000B9BC 00104880 */  sll   $t1, $s0, 2
/* 00C5C0 7000B9C0 00C95021 */  addu  $t2, $a2, $t1
/* 00C5C4 7000B9C4 A0E80000 */  sb    $t0, ($a3)
/* 00C5C8 7000B9C8 AD400000 */  sw    $zero, ($t2)
.L7000B9CC:
/* 00C5CC 7000B9CC 26100001 */  addiu $s0, $s0, 1
/* 00C5D0 7000B9D0 00105E00 */  sll   $t3, $s0, 0x18
/* 00C5D4 7000B9D4 000B8603 */  sra   $s0, $t3, 0x18
/* 00C5D8 7000B9D8 2A010004 */  slti  $at, $s0, 4
/* 00C5DC 7000B9DC 1420FFD0 */  bnez  $at, .L7000B920
/* 00C5E0 7000B9E0 00000000 */   nop   
/* 00C5E4 7000B9E4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00C5E8 7000B9E8 8FB00018 */  lw    $s0, 0x18($sp)
/* 00C5EC 7000B9EC 27BD0038 */  addiu $sp, $sp, 0x38
/* 00C5F0 7000B9F0 03E00008 */  jr    $ra
/* 00C5F4 7000B9F4 00000000 */   nop   
)
#endif

s8 get_attached_controller_count(void) {
    s32 i;

	if (g_ContDataPtr->unk1f8 >= 0) {
		return g_ContDataPtr->unk1f8;
	}

	for (i = 0; i < 4; i++) {
		if ((g_ConnectedControllers & (1 << i)) == 0) {
			return i;
		}
	}

	return 4;
}

u8 get_num_controllers_plugged_in(void) {
    return g_ConnectedControllers;
}

#ifdef NONMATCHING
// controller_1_rumble_inserted loaded only once instead of twice + regalloc
void controller_rumble_related(void) {
    s32 i;
    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (controller_1_rumble_state[i] != controller_1_rumble_pulse[i]) {
            if (controller_1_rumble_pulse[i] == 1) { // enum/define?
                if (osMotorStart(&player1_controller_packet[i]) == 0) {
                    controller_1_rumble_state[i] = 1;
                } else {
                    controller_1_rumble_inserted[i] = FALSE;
                }
#ifdef VERSION_JP
            } else if (controller_1_rumble_pulse[i] == 2) {
                if (osMotorInit(&contdemosMesgMQ, &player1_controller_packet[i], i) != 0) {
                    controller_1_rumble_inserted[i] = FALSE;                    
                }
                osMotorStop(&player1_controller_packet[i]);
                controller_1_rumble_state[i] = 0;
                controller_1_rumble_pack[i] = 0;
#endif
            } else {
                if (osMotorStop(&player1_controller_packet[i]) == 0) {
                    controller_1_rumble_state[i] = 0;
                } else {
                    controller_1_rumble_inserted[i] = FALSE;
                }
            } 
        }
        if (controller_1_rumble_duration[i] <= 0) {
            controller_1_rumble_duration[i] = 0;
        } else {
            controller_1_rumble_duration[i]--;
            if (controller_1_rumble_duration[i] <= 0) {
                controller_1_rumble_duration[i] = 0;
                controller_1_rumble_pulse[i] = 0;
            }
        }
    }
}
#else 
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel controller_rumble_related
/* 00C67C 7000BA7C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 00C680 7000BA80 AFB40028 */  sw    $s4, 0x28($sp)
/* 00C684 7000BA84 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00C688 7000BA88 AFB00018 */  sw    $s0, 0x18($sp)
/* 00C68C 7000BA8C AFB60030 */  sw    $s6, 0x30($sp)
/* 00C690 7000BA90 AFB5002C */  sw    $s5, 0x2c($sp)
/* 00C694 7000BA94 AFB30024 */  sw    $s3, 0x24($sp)
/* 00C698 7000BA98 AFB20020 */  sw    $s2, 0x20($sp)
/* 00C69C 7000BA9C 3C108002 */  lui   $s0, %hi(controller_1_rumble_duration)
/* 00C6A0 7000BAA0 3C118002 */  lui   $s1, %hi(controller_1_rumble_state)
/* 00C6A4 7000BAA4 3C148002 */  lui   $s4, %hi(controller_1_rumble_pulse)
/* 00C6A8 7000BAA8 AFBF0034 */  sw    $ra, 0x34($sp)
/* 00C6AC 7000BAAC 26946908 */  addiu $s4, %lo(controller_1_rumble_pulse) # addiu $s4, $s4, 0x6908
/* 00C6B0 7000BAB0 263168E8 */  addiu $s1, %lo(controller_1_rumble_state) # addiu $s1, $s1, 0x68e8
/* 00C6B4 7000BAB4 261068F8 */  addiu $s0, %lo(controller_1_rumble_duration) # addiu $s0, $s0, 0x68f8
/* 00C6B8 7000BAB8 00009025 */  move  $s2, $zero
/* 00C6BC 7000BABC 00009825 */  move  $s3, $zero
/* 00C6C0 7000BAC0 24150001 */  li    $s5, 1
/* 00C6C4 7000BAC4 24160004 */  li    $s6, 4
.L7000BAC8:
/* 00C6C8 7000BAC8 8E820000 */  lw    $v0, ($s4)
/* 00C6CC 7000BACC 8E2E0000 */  lw    $t6, ($s1)
/* 00C6D0 7000BAD0 00127880 */  sll   $t7, $s2, 2
/* 00C6D4 7000BAD4 01F27823 */  subu  $t7, $t7, $s2
/* 00C6D8 7000BAD8 11C2001A */  beq   $t6, $v0, .L7000BB44
/* 00C6DC 7000BADC 000F7880 */   sll   $t7, $t7, 2
/* 00C6E0 7000BAE0 01F27821 */  addu  $t7, $t7, $s2
/* 00C6E4 7000BAE4 3C188006 */  lui   $t8, %hi(player1_controller_packet) 
/* 00C6E8 7000BAE8 271853F8 */  addiu $t8, %lo(player1_controller_packet) # addiu $t8, $t8, 0x53f8
/* 00C6EC 7000BAEC 000F78C0 */  sll   $t7, $t7, 3
/* 00C6F0 7000BAF0 16A2000B */  bne   $s5, $v0, .L7000BB20
/* 00C6F4 7000BAF4 01F82021 */   addu  $a0, $t7, $t8
/* 00C6F8 7000BAF8 0C0032AB */  jal   osMotorStart
/* 00C6FC 7000BAFC 00000000 */   nop   
/* 00C700 7000BB00 14400003 */  bnez  $v0, .L7000BB10
/* 00C704 7000BB04 3C198002 */   lui   $t9, %hi(controller_1_rumble_inserted) 
/* 00C708 7000BB08 1000000E */  b     .L7000BB44
/* 00C70C 7000BB0C AE350000 */   sw    $s5, ($s1)
.L7000BB10:
/* 00C710 7000BB10 273968D8 */  addiu $t9, %lo(controller_1_rumble_inserted) # addiu $t9, $t9, 0x68d8
/* 00C714 7000BB14 02791021 */  addu  $v0, $s3, $t9
/* 00C718 7000BB18 1000000A */  b     .L7000BB44
/* 00C71C 7000BB1C AC400000 */   sw    $zero, ($v0)
.L7000BB20:
/* 00C720 7000BB20 0C003260 */  jal   osMotorStop
/* 00C724 7000BB24 00000000 */   nop   
/* 00C728 7000BB28 14400003 */  bnez  $v0, .L7000BB38
/* 00C72C 7000BB2C 3C088002 */   lui   $t0, %hi(controller_1_rumble_inserted) 
/* 00C730 7000BB30 10000004 */  b     .L7000BB44
/* 00C734 7000BB34 AE200000 */   sw    $zero, ($s1)
.L7000BB38:
/* 00C738 7000BB38 250868D8 */  addiu $t0, %lo(controller_1_rumble_inserted) # addiu $t0, $t0, 0x68d8
/* 00C73C 7000BB3C 02681021 */  addu  $v0, $s3, $t0
/* 00C740 7000BB40 AC400000 */  sw    $zero, ($v0)
.L7000BB44:
/* 00C744 7000BB44 8E020000 */  lw    $v0, ($s0)
/* 00C748 7000BB48 26520001 */  addiu $s2, $s2, 1
/* 00C74C 7000BB4C 26730004 */  addiu $s3, $s3, 4
/* 00C750 7000BB50 1C400003 */  bgtz  $v0, .L7000BB60
/* 00C754 7000BB54 26310004 */   addiu $s1, $s1, 4
/* 00C758 7000BB58 10000006 */  b     .L7000BB74
/* 00C75C 7000BB5C AE000000 */   sw    $zero, ($s0)
.L7000BB60:
/* 00C760 7000BB60 2449FFFF */  addiu $t1, $v0, -1
/* 00C764 7000BB64 1D200003 */  bgtz  $t1, .L7000BB74
/* 00C768 7000BB68 AE090000 */   sw    $t1, ($s0)
/* 00C76C 7000BB6C AE000000 */  sw    $zero, ($s0)
/* 00C770 7000BB70 AE800000 */  sw    $zero, ($s4)
.L7000BB74:
/* 00C774 7000BB74 26940004 */  addiu $s4, $s4, 4
/* 00C778 7000BB78 1656FFD3 */  bne   $s2, $s6, .L7000BAC8
/* 00C77C 7000BB7C 26100004 */   addiu $s0, $s0, 4
/* 00C780 7000BB80 8FBF0034 */  lw    $ra, 0x34($sp)
/* 00C784 7000BB84 8FB00018 */  lw    $s0, 0x18($sp)
/* 00C788 7000BB88 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00C78C 7000BB8C 8FB20020 */  lw    $s2, 0x20($sp)
/* 00C790 7000BB90 8FB30024 */  lw    $s3, 0x24($sp)
/* 00C794 7000BB94 8FB40028 */  lw    $s4, 0x28($sp)
/* 00C798 7000BB98 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00C79C 7000BB9C 8FB60030 */  lw    $s6, 0x30($sp)
/* 00C7A0 7000BBA0 03E00008 */  jr    $ra
/* 00C7A4 7000BBA4 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif
#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel controller_rumble_related
/* 00C68C 7000BA8C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 00C690 7000BA90 AFB5002C */  sw    $s5, 0x2c($sp)
/* 00C694 7000BA94 AFB20020 */  sw    $s2, 0x20($sp)
/* 00C698 7000BA98 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00C69C 7000BA9C AFBE0038 */  sw    $fp, 0x38($sp)
/* 00C6A0 7000BAA0 AFB70034 */  sw    $s7, 0x34($sp)
/* 00C6A4 7000BAA4 AFB60030 */  sw    $s6, 0x30($sp)
/* 00C6A8 7000BAA8 AFB40028 */  sw    $s4, 0x28($sp)
/* 00C6AC 7000BAAC AFB30024 */  sw    $s3, 0x24($sp)
/* 00C6B0 7000BAB0 3C118002 */  lui   $s1, %hi(controller_1_rumble_duration) # $s1, 0x8002
/* 00C6B4 7000BAB4 3C128002 */  lui   $s2, %hi(controller_1_rumble_state) # $s2, 0x8002
/* 00C6B8 7000BAB8 3C158002 */  lui   $s5, %hi(controller_1_rumble_pulse) # $s5, 0x8002
/* 00C6BC 7000BABC AFBF003C */  sw    $ra, 0x3c($sp)
/* 00C6C0 7000BAC0 AFB00018 */  sw    $s0, 0x18($sp)
/* 00C6C4 7000BAC4 26B56948 */  addiu $s5, %lo(controller_1_rumble_pulse) # addiu $s5, $s5, 0x6948
/* 00C6C8 7000BAC8 26526928 */  addiu $s2, %lo(controller_1_rumble_state) # addiu $s2, $s2, 0x6928
/* 00C6CC 7000BACC 26316938 */  addiu $s1, %lo(controller_1_rumble_duration) # addiu $s1, $s1, 0x6938
/* 00C6D0 7000BAD0 00009825 */  move  $s3, $zero
/* 00C6D4 7000BAD4 0000A025 */  move  $s4, $zero
/* 00C6D8 7000BAD8 24160001 */  li    $s6, 1
/* 00C6DC 7000BADC 24170004 */  li    $s7, 4
/* 00C6E0 7000BAE0 241E0002 */  li    $fp, 2
.Ljp7000BAE4:
/* 00C6E4 7000BAE4 8EA20000 */  lw    $v0, ($s5)
/* 00C6E8 7000BAE8 8E4E0000 */  lw    $t6, ($s2)
/* 00C6EC 7000BAEC 00137880 */  sll   $t7, $s3, 2
/* 00C6F0 7000BAF0 01F37823 */  subu  $t7, $t7, $s3
/* 00C6F4 7000BAF4 11C2002A */  beq   $t6, $v0, .Ljp7000BBA0
/* 00C6F8 7000BAF8 000F7880 */   sll   $t7, $t7, 2
/* 00C6FC 7000BAFC 01F37821 */  addu  $t7, $t7, $s3
/* 00C700 7000BB00 3C188006 */  lui   $t8, %hi(player1_controller_packet) # $t8, 0x8006
/* 00C704 7000BB04 27185438 */  addiu $t8, %lo(player1_controller_packet) # addiu $t8, $t8, 0x5438
/* 00C708 7000BB08 000F78C0 */  sll   $t7, $t7, 3
/* 00C70C 7000BB0C 16C2000B */  bne   $s6, $v0, .Ljp7000BB3C
/* 00C710 7000BB10 01F88021 */   addu  $s0, $t7, $t8
/* 00C714 7000BB14 0C0032BB */  jal   osMotorStart
/* 00C718 7000BB18 02002025 */   move  $a0, $s0
/* 00C71C 7000BB1C 14400003 */  bnez  $v0, .Ljp7000BB2C
/* 00C720 7000BB20 3C198002 */   lui   $t9, %hi(controller_1_rumble_inserted) # $t9, 0x8002
/* 00C724 7000BB24 1000001E */  b     .Ljp7000BBA0
/* 00C728 7000BB28 AE560000 */   sw    $s6, ($s2)
.Ljp7000BB2C:
/* 00C72C 7000BB2C 27396918 */  addiu $t9, %lo(controller_1_rumble_inserted) # addiu $t9, $t9, 0x6918
/* 00C730 7000BB30 02991021 */  addu  $v0, $s4, $t9
/* 00C734 7000BB34 1000001A */  b     .Ljp7000BBA0
/* 00C738 7000BB38 AC400000 */   sw    $zero, ($v0)
.Ljp7000BB3C:
/* 00C73C 7000BB3C 17C2000F */  bne   $fp, $v0, .Ljp7000BB7C
/* 00C740 7000BB40 3C048006 */   lui   $a0, %hi(contdemoMesgMQ) # $a0, 0x8006
/* 00C744 7000BB44 24845390 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5390
/* 00C748 7000BB48 02002825 */  move  $a1, $s0
/* 00C74C 7000BB4C 0C00335E */  jal   osMotorInit
/* 00C750 7000BB50 02603025 */   move  $a2, $s3
/* 00C754 7000BB54 10400004 */  beqz  $v0, .Ljp7000BB68
/* 00C758 7000BB58 3C088002 */   lui   $t0, %hi(controller_1_rumble_inserted) # $t0, 0x8002
/* 00C75C 7000BB5C 25086918 */  addiu $t0, %lo(controller_1_rumble_inserted) # addiu $t0, $t0, 0x6918
/* 00C760 7000BB60 02881021 */  addu  $v0, $s4, $t0
/* 00C764 7000BB64 AC400000 */  sw    $zero, ($v0)
.Ljp7000BB68:
/* 00C768 7000BB68 0C003270 */  jal   osMotorStop
/* 00C76C 7000BB6C 02002025 */   move  $a0, $s0
/* 00C770 7000BB70 AE400000 */  sw    $zero, ($s2)
/* 00C774 7000BB74 1000000A */  b     .Ljp7000BBA0
/* 00C778 7000BB78 AEA00000 */   sw    $zero, ($s5)
.Ljp7000BB7C:
/* 00C77C 7000BB7C 0C003270 */  jal   osMotorStop
/* 00C780 7000BB80 02002025 */   move  $a0, $s0
/* 00C784 7000BB84 14400003 */  bnez  $v0, .Ljp7000BB94
/* 00C788 7000BB88 3C098002 */   lui   $t1, %hi(controller_1_rumble_inserted) # $t1, 0x8002
/* 00C78C 7000BB8C 10000004 */  b     .Ljp7000BBA0
/* 00C790 7000BB90 AE400000 */   sw    $zero, ($s2)
.Ljp7000BB94:
/* 00C794 7000BB94 25296918 */  addiu $t1, %lo(controller_1_rumble_inserted) # addiu $t1, $t1, 0x6918
/* 00C798 7000BB98 02891021 */  addu  $v0, $s4, $t1
/* 00C79C 7000BB9C AC400000 */  sw    $zero, ($v0)
.Ljp7000BBA0:
/* 00C7A0 7000BBA0 8E220000 */  lw    $v0, ($s1)
/* 00C7A4 7000BBA4 26730001 */  addiu $s3, $s3, 1
/* 00C7A8 7000BBA8 26940004 */  addiu $s4, $s4, 4
/* 00C7AC 7000BBAC 1C400003 */  bgtz  $v0, .Ljp7000BBBC
/* 00C7B0 7000BBB0 26520004 */   addiu $s2, $s2, 4
/* 00C7B4 7000BBB4 10000006 */  b     .Ljp7000BBD0
/* 00C7B8 7000BBB8 AE200000 */   sw    $zero, ($s1)
.Ljp7000BBBC:
/* 00C7BC 7000BBBC 244AFFFF */  addiu $t2, $v0, -1
/* 00C7C0 7000BBC0 1D400003 */  bgtz  $t2, .Ljp7000BBD0
/* 00C7C4 7000BBC4 AE2A0000 */   sw    $t2, ($s1)
/* 00C7C8 7000BBC8 AE200000 */  sw    $zero, ($s1)
/* 00C7CC 7000BBCC AEA00000 */  sw    $zero, ($s5)
.Ljp7000BBD0:
/* 00C7D0 7000BBD0 26B50004 */  addiu $s5, $s5, 4
/* 00C7D4 7000BBD4 1677FFC3 */  bne   $s3, $s7, .Ljp7000BAE4
/* 00C7D8 7000BBD8 26310004 */   addiu $s1, $s1, 4
/* 00C7DC 7000BBDC 8FBF003C */  lw    $ra, 0x3c($sp)
/* 00C7E0 7000BBE0 8FB00018 */  lw    $s0, 0x18($sp)
/* 00C7E4 7000BBE4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00C7E8 7000BBE8 8FB20020 */  lw    $s2, 0x20($sp)
/* 00C7EC 7000BBEC 8FB30024 */  lw    $s3, 0x24($sp)
/* 00C7F0 7000BBF0 8FB40028 */  lw    $s4, 0x28($sp)
/* 00C7F4 7000BBF4 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00C7F8 7000BBF8 8FB60030 */  lw    $s6, 0x30($sp)
/* 00C7FC 7000BBFC 8FB70034 */  lw    $s7, 0x34($sp)
/* 00C800 7000BC00 8FBE0038 */  lw    $fp, 0x38($sp)
/* 00C804 7000BC04 03E00008 */  jr    $ra
/* 00C808 7000BC08 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif
#endif

void set_disable_all_rumble_and_something(s32 arg0, s32 arg1) {
    D_80026924 = arg0;
    g_ContData[1].unk1f8 = arg1;
}

void set_ptr_tlb_ramrom_record(s32 arg0){
    D_80026928 = arg0;
}

void joyConsumeSamples(struct contdata *contdata) {
    s8 i;
    s32 samplenum;
    u16 buttons1;
    u16 buttons2;
    contdata->curstart = contdata->curlast;
    contdata->curlast = contdata->nextlast;
    for (i = 0; i < 4; i++) {
        contdata->buttonspressed[i] = 0;
        if (contdata->curlast != contdata->curstart) {
            samplenum = ((contdata->curstart + 1) % 20); while (TRUE) {
                buttons1 = contdata->samples[samplenum].pads[i].button;
                buttons2 = contdata->samples[(samplenum + 19) % 20].pads[i].button;
                contdata->buttonspressed[i] |= buttons1 & ~buttons2;
                if (samplenum == contdata->curlast) {
                    break;
                }
                samplenum = ((samplenum + 1) % 20);
            }
        }
    }
}

void redirect_to_ramrom_replay_and_record_handlers_if_set(void) {
    if (D_80026924) {
        g_ContData[1].nextlast = D_80026924(g_ContData[1].samples, g_ContData[1].curlast);
        joyConsumeSamples(&g_ContData[1]);
    }
    joyConsumeSamples(&g_ContData[0]);
    if (D_80026928) {
        D_80026928(g_ContData[0].samples, g_ContData[0].curstart, g_ContData[0].curlast);
    }
}

#ifdef NONMATCHING
// Stack + Regalloc
void controllerSchedulerRelated(void)
{
    OSMesg msg;
    if (osRecvMesg(&cont1MesgMQ, &msg, OS_MESG_NOBLOCK) == 0) {
        if (g_ContBusy) {
            osRecvMesg(&contdemoMesgMQ, &msg, OS_MESG_BLOCK);
            g_ContBusy = FALSE;
        }
        osSendMesg(&cont2MesgMQ, &msg, OS_MESG_NOBLOCK);
        D_800268CC++;
        return;
    }
    if (osRecvMesg(&cont3MesgMQ, &msg, OS_MESG_NOBLOCK) == 0) {
        osContStartReadData(&contdemoMesgMQ);
        g_ContBusy = TRUE;
        osSendMesg(&cont4MesgMQ, &msg, OS_MESG_NOBLOCK);
        D_800268CC--;
        return;
    }
    if ((D_800268CC == 0) && g_ContInitDone) {
        if (osRecvMesg(&contdemoMesgMQ, &msg, OS_MESG_NOBLOCK) == 0) {
            static s32 count = 0;
            s32 index;
            s8 i;
            g_ContBusy = FALSE;
            index = ((g_ContData[0].nextlast + 1) % 20);
            if (index == g_ContData[0].curstart) {
                index = g_ContData[0].nextlast;
            }
            osContGetReadData(g_ContData[0].samples[index].pads);
            g_ContData[0].nextlast = index;
            g_ContData[0].nextsecondlast = ((g_ContData[0].nextlast + 19) % 20);
            D_80026920++;
            if ((D_80026920 % 120) == 0) {
                controller_check_for_rumble_maybe();
            }
            for (i = 0; i < MAXCONTROLLERS; i++) {
                if (((g_ContData[0].samples[g_ContData[0].nextlast].pads[i].errnum == 0) && (g_ContData[0].samples[g_ContData[0].nextsecondlast].pads[i].errnum != 0)) || 
                    ((g_ContData[0].samples[g_ContData[0].nextlast].pads[i].errnum != 0) && (g_ContData[0].samples[g_ContData[0].nextsecondlast].pads[i].errnum == 0))) {
					controller_check_for_rumble_maybe();
					break;
				}
            }
            controller_rumble_related();
            osContStartReadData(&contdemoMesgMQ);
            g_ContBusy = TRUE;
            count++;
            if (count >= 60) {
                s32 i;
                for (i = 0; i < MAXCONTROLLERS; i++) {
                    if (g_ContBadReadsStickX[i] || g_ContBadReadsStickY[i] || g_ContBadReadsButtons[i] || g_ContBadReadsButtonsPressed[i]) {
						g_ContBadReadsStickX[i] = 0;
						g_ContBadReadsStickY[i] = 0;
						g_ContBadReadsButtons[i] = 0;
						g_ContBadReadsButtonsPressed[i] = 0;
					}
                }
                count = 0;
            }
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel controllerSchedulerRelated
/* 00C988 7000BD88 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 00C98C 7000BD8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00C990 7000BD90 3C048006 */  lui   $a0, %hi(cont1MesgMQ)
/* 00C994 7000BD94 24845370 */  addiu $a0, %lo(cont1MesgMQ) # addiu $a0, $a0, 0x5370
/* 00C998 7000BD98 27A5004C */  addiu $a1, $sp, 0x4c
/* 00C99C 7000BD9C 0C003774 */  jal   osRecvMesg
/* 00C9A0 7000BDA0 00003025 */   move  $a2, $zero
/* 00C9A4 7000BDA4 14400015 */  bnez  $v0, .L7000BDFC
/* 00C9A8 7000BDA8 3C0E8002 */   lui   $t6, %hi(g_ContBusy) 
/* 00C9AC 7000BDAC 8DCE68C8 */  lw    $t6, %lo(g_ContBusy)($t6)
/* 00C9B0 7000BDB0 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00C9B4 7000BDB4 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00C9B8 7000BDB8 11C00005 */  beqz  $t6, .L7000BDD0
/* 00C9BC 7000BDBC 27A5004C */   addiu $a1, $sp, 0x4c
/* 00C9C0 7000BDC0 0C003774 */  jal   osRecvMesg
/* 00C9C4 7000BDC4 24060001 */   li    $a2, 1
/* 00C9C8 7000BDC8 3C018002 */  lui   $at, %hi(g_ContBusy)
/* 00C9CC 7000BDCC AC2068C8 */  sw    $zero, %lo(g_ContBusy)($at)
.L7000BDD0:
/* 00C9D0 7000BDD0 3C048006 */  lui   $a0, %hi(cont2MesgMQ)
/* 00C9D4 7000BDD4 24845390 */  addiu $a0, %lo(cont2MesgMQ) # addiu $a0, $a0, 0x5390
/* 00C9D8 7000BDD8 27A5004C */  addiu $a1, $sp, 0x4c
/* 00C9DC 7000BDDC 0C0037C4 */  jal   osSendMesg
/* 00C9E0 7000BDE0 00003025 */   move  $a2, $zero
/* 00C9E4 7000BDE4 3C038002 */  lui   $v1, %hi(D_800268CC)
/* 00C9E8 7000BDE8 246368CC */  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
/* 00C9EC 7000BDEC 8C6F0000 */  lw    $t7, ($v1)
/* 00C9F0 7000BDF0 25F80001 */  addiu $t8, $t7, 1
/* 00C9F4 7000BDF4 100000B9 */  b     .L7000C0DC
/* 00C9F8 7000BDF8 AC780000 */   sw    $t8, ($v1)
.L7000BDFC:
/* 00C9FC 7000BDFC 3C048006 */  lui   $a0, %hi(cont3MesgMQ)
/* 00CA00 7000BE00 248453B0 */  addiu $a0, %lo(cont3MesgMQ) # addiu $a0, $a0, 0x53b0
/* 00CA04 7000BE04 27A5004C */  addiu $a1, $sp, 0x4c
/* 00CA08 7000BE08 0C003774 */  jal   osRecvMesg
/* 00CA0C 7000BE0C 00003025 */   move  $a2, $zero
/* 00CA10 7000BE10 14400011 */  bnez  $v0, .L7000BE58
/* 00CA14 7000BE14 3C048006 */   lui   $a0, %hi(contdemoMesgMQ)
/* 00CA18 7000BE18 0C00535C */  jal   osContStartReadData
/* 00CA1C 7000BE1C 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00CA20 7000BE20 24190001 */  li    $t9, 1
/* 00CA24 7000BE24 3C018002 */  lui   $at, %hi(g_ContBusy)
/* 00CA28 7000BE28 3C048006 */  lui   $a0, %hi(cont4MesgMQ)
/* 00CA2C 7000BE2C AC3968C8 */  sw    $t9, %lo(g_ContBusy)($at)
/* 00CA30 7000BE30 248453D0 */  addiu $a0, %lo(cont4MesgMQ) # addiu $a0, $a0, 0x53d0
/* 00CA34 7000BE34 27A5004C */  addiu $a1, $sp, 0x4c
/* 00CA38 7000BE38 0C0037C4 */  jal   osSendMesg
/* 00CA3C 7000BE3C 00003025 */   move  $a2, $zero
/* 00CA40 7000BE40 3C038002 */  lui   $v1, %hi(D_800268CC)
/* 00CA44 7000BE44 246368CC */  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
/* 00CA48 7000BE48 8C6B0000 */  lw    $t3, ($v1)
/* 00CA4C 7000BE4C 256CFFFF */  addiu $t4, $t3, -1
/* 00CA50 7000BE50 100000A2 */  b     .L7000C0DC
/* 00CA54 7000BE54 AC6C0000 */   sw    $t4, ($v1)
.L7000BE58:
/* 00CA58 7000BE58 3C038002 */  lui   $v1, %hi(D_800268CC)
/* 00CA5C 7000BE5C 246368CC */  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
/* 00CA60 7000BE60 8C6D0000 */  lw    $t5, ($v1)
/* 00CA64 7000BE64 3C0E8002 */  lui   $t6, %hi(g_ContInitDone) 
/* 00CA68 7000BE68 55A0009D */  bnezl $t5, .L7000C0E0
/* 00CA6C 7000BE6C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 00CA70 7000BE70 8DCE691C */  lw    $t6, %lo(g_ContInitDone)($t6)
/* 00CA74 7000BE74 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00CA78 7000BE78 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00CA7C 7000BE7C 11C00097 */  beqz  $t6, .L7000C0DC
/* 00CA80 7000BE80 27A5004C */   addiu $a1, $sp, 0x4c
/* 00CA84 7000BE84 0C003774 */  jal   osRecvMesg
/* 00CA88 7000BE88 00003025 */   move  $a2, $zero
/* 00CA8C 7000BE8C 14400093 */  bnez  $v0, .L7000C0DC
/* 00CA90 7000BE90 3C058006 */   lui   $a1, %hi(g_ContData)
/* 00CA94 7000BE94 3C018002 */  lui   $at, %hi(g_ContBusy)
/* 00CA98 7000BE98 24A54F30 */  addiu $a1, %lo(g_ContData) # addiu $a1, $a1, 0x4f30
/* 00CA9C 7000BE9C AC2068C8 */  sw    $zero, %lo(g_ContBusy)($at)
/* 00CAA0 7000BEA0 8CA201E8 */  lw    $v0, 0x1e8($a1)
/* 00CAA4 7000BEA4 24010014 */  li    $at, 20
/* 00CAA8 7000BEA8 8CB801E4 */  lw    $t8, 0x1e4($a1)
/* 00CAAC 7000BEAC 24430001 */  addiu $v1, $v0, 1
/* 00CAB0 7000BEB0 0061001A */  div   $zero, $v1, $at
/* 00CAB4 7000BEB4 00001810 */  mfhi  $v1
/* 00CAB8 7000BEB8 54780003 */  bnel  $v1, $t8, .L7000BEC8
/* 00CABC 7000BEBC 0003C880 */   sll   $t9, $v1, 2
/* 00CAC0 7000BEC0 00401825 */  move  $v1, $v0
/* 00CAC4 7000BEC4 0003C880 */  sll   $t9, $v1, 2
.L7000BEC8:
/* 00CAC8 7000BEC8 0323C823 */  subu  $t9, $t9, $v1
/* 00CACC 7000BECC 0019C8C0 */  sll   $t9, $t9, 3
/* 00CAD0 7000BED0 00B92021 */  addu  $a0, $a1, $t9
/* 00CAD4 7000BED4 0C00538D */  jal   osContGetReadData
/* 00CAD8 7000BED8 AFA30040 */   sw    $v1, 0x40($sp)
/* 00CADC 7000BEDC 8FA20040 */  lw    $v0, 0x40($sp)
/* 00CAE0 7000BEE0 24010014 */  li    $at, 20
/* 00CAE4 7000BEE4 3C048002 */  lui   $a0, %hi(D_80026920)
/* 00CAE8 7000BEE8 244B0013 */  addiu $t3, $v0, 0x13
/* 00CAEC 7000BEEC 0161001A */  div   $zero, $t3, $at
/* 00CAF0 7000BEF0 24846920 */  addiu $a0, %lo(D_80026920) # addiu $a0, $a0, 0x6920
/* 00CAF4 7000BEF4 8C8D0000 */  lw    $t5, ($a0)
/* 00CAF8 7000BEF8 00006010 */  mfhi  $t4
/* 00CAFC 7000BEFC 24010078 */  li    $at, 120
/* 00CB00 7000BF00 25AE0001 */  addiu $t6, $t5, 1
/* 00CB04 7000BF04 01C1001A */  div   $zero, $t6, $at
/* 00CB08 7000BF08 3C058006 */  lui   $a1, %hi(g_ContData)
/* 00CB0C 7000BF0C 24A54F30 */  addiu $a1, %lo(g_ContData) # addiu $a1, $a1, 0x4f30
/* 00CB10 7000BF10 0000C010 */  mfhi  $t8
/* 00CB14 7000BF14 ACAC01EC */  sw    $t4, 0x1ec($a1)
/* 00CB18 7000BF18 AC8E0000 */  sw    $t6, ($a0)
/* 00CB1C 7000BF1C 17000006 */  bnez  $t8, .L7000BF38
/* 00CB20 7000BF20 ACA201E8 */   sw    $v0, 0x1e8($a1)
/* 00CB24 7000BF24 0C002E04 */  jal   controller_check_for_rumble_maybe
/* 00CB28 7000BF28 00000000 */   nop   
/* 00CB2C 7000BF2C 3C058006 */  lui   $a1, %hi(g_ContData)
/* 00CB30 7000BF30 24A54F30 */  addiu $a1, %lo(g_ContData) # addiu $a1, $a1, 0x4f30
/* 00CB34 7000BF34 8CA201E8 */  lw    $v0, 0x1e8($a1)
.L7000BF38:
/* 00CB38 7000BF38 0002C880 */  sll   $t9, $v0, 2
/* 00CB3C 7000BF3C 0322C823 */  subu  $t9, $t9, $v0
/* 00CB40 7000BF40 0019C8C0 */  sll   $t9, $t9, 3
/* 00CB44 7000BF44 00B93021 */  addu  $a2, $a1, $t9
/* 00CB48 7000BF48 00002025 */  move  $a0, $zero
/* 00CB4C 7000BF4C 24070006 */  li    $a3, 6
.L7000BF50:
/* 00CB50 7000BF50 00870019 */  multu $a0, $a3
/* 00CB54 7000BF54 00001012 */  mflo  $v0
/* 00CB58 7000BF58 00C25821 */  addu  $t3, $a2, $v0
/* 00CB5C 7000BF5C 91630004 */  lbu   $v1, 4($t3)
/* 00CB60 7000BF60 1460000A */  bnez  $v1, .L7000BF8C
/* 00CB64 7000BF64 00000000 */   nop   
/* 00CB68 7000BF68 8CAC01EC */  lw    $t4, 0x1ec($a1)
/* 00CB6C 7000BF6C 000C6880 */  sll   $t5, $t4, 2
/* 00CB70 7000BF70 01AC6823 */  subu  $t5, $t5, $t4
/* 00CB74 7000BF74 000D68C0 */  sll   $t5, $t5, 3
/* 00CB78 7000BF78 00AD7021 */  addu  $t6, $a1, $t5
/* 00CB7C 7000BF7C 01C27821 */  addu  $t7, $t6, $v0
/* 00CB80 7000BF80 91F80004 */  lbu   $t8, 4($t7)
/* 00CB84 7000BF84 1700000C */  bnez  $t8, .L7000BFB8
/* 00CB88 7000BF88 00000000 */   nop   
.L7000BF8C:
/* 00CB8C 7000BF8C 1060000E */  beqz  $v1, .L7000BFC8
/* 00CB90 7000BF90 24840001 */   addiu $a0, $a0, 1
/* 00CB94 7000BF94 8CB901EC */  lw    $t9, 0x1ec($a1)
/* 00CB98 7000BF98 00195880 */  sll   $t3, $t9, 2
/* 00CB9C 7000BF9C 01795823 */  subu  $t3, $t3, $t9
/* 00CBA0 7000BFA0 000B58C0 */  sll   $t3, $t3, 3
/* 00CBA4 7000BFA4 00AB6021 */  addu  $t4, $a1, $t3
/* 00CBA8 7000BFA8 01826821 */  addu  $t5, $t4, $v0
/* 00CBAC 7000BFAC 91AE0004 */  lbu   $t6, 4($t5)
/* 00CBB0 7000BFB0 55C00006 */  bnezl $t6, .L7000BFCC
/* 00CBB4 7000BFB4 00047E00 */   sll   $t7, $a0, 0x18
.L7000BFB8:
/* 00CBB8 7000BFB8 0C002E04 */  jal   controller_check_for_rumble_maybe
/* 00CBBC 7000BFBC 00000000 */   nop   
/* 00CBC0 7000BFC0 10000006 */  b     .L7000BFDC
/* 00CBC4 7000BFC4 00000000 */   nop   
.L7000BFC8:
/* 00CBC8 7000BFC8 00047E00 */  sll   $t7, $a0, 0x18
.L7000BFCC:
/* 00CBCC 7000BFCC 000F2603 */  sra   $a0, $t7, 0x18
/* 00CBD0 7000BFD0 28810004 */  slti  $at, $a0, 4
/* 00CBD4 7000BFD4 1420FFDE */  bnez  $at, .L7000BF50
/* 00CBD8 7000BFD8 00000000 */   nop   
.L7000BFDC:
/* 00CBDC 7000BFDC 0C002E9F */  jal   controller_rumble_related
/* 00CBE0 7000BFE0 00000000 */   nop   
/* 00CBE4 7000BFE4 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00CBE8 7000BFE8 0C00535C */  jal   osContStartReadData
/* 00CBEC 7000BFEC 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00CBF0 7000BFF0 3C038002 */  lui   $v1, %hi(D_80026970)
/* 00CBF4 7000BFF4 8C636970 */  lw    $v1, %lo(D_80026970)($v1)
/* 00CBF8 7000BFF8 24190001 */  li    $t9, 1
/* 00CBFC 7000BFFC 3C018002 */  lui   $at, %hi(g_ContBusy)
/* 00CC00 7000C000 AC3968C8 */  sw    $t9, %lo(g_ContBusy)($at)
/* 00CC04 7000C004 3C018002 */  lui   $at, %hi(D_80026970)
/* 00CC08 7000C008 24630001 */  addiu $v1, $v1, 1
/* 00CC0C 7000C00C AC236970 */  sw    $v1, %lo(D_80026970)($at)
/* 00CC10 7000C010 2861003C */  slti  $at, $v1, 0x3c
/* 00CC14 7000C014 14200031 */  bnez  $at, .L7000C0DC
/* 00CC18 7000C018 3C098002 */   lui   $t1, %hi(g_ContBadReadsStickX) 
/* 00CC1C 7000C01C 3C048002 */  lui   $a0, %hi(g_ContBadReadsStickY)
/* 00CC20 7000C020 3C058002 */  lui   $a1, %hi(g_ContBadReadsButtons)
/* 00CC24 7000C024 3C038002 */  lui   $v1, %hi(g_ContBadReadsButtonsPressed)
/* 00CC28 7000C028 3C0A8002 */  lui   $t2, %hi(D_80026970) 
/* 00CC2C 7000C02C 254A6970 */  addiu $t2, %lo(D_80026970) # addiu $t2, $t2, 0x6970
/* 00CC30 7000C030 24636960 */  addiu $v1, %lo(g_ContBadReadsButtonsPressed) # addiu $v1, $v1, 0x6960
/* 00CC34 7000C034 24A56950 */  addiu $a1, %lo(g_ContBadReadsButtons) # addiu $a1, $a1, 0x6950
/* 00CC38 7000C038 24846940 */  addiu $a0, %lo(g_ContBadReadsStickY) # addiu $a0, $a0, 0x6940
/* 00CC3C 7000C03C 25296930 */  addiu $t1, %lo(g_ContBadReadsStickX) # addiu $t1, $t1, 0x6930
.L7000C040:
/* 00CC40 7000C040 8D220000 */  lw    $v0, ($t1)
/* 00CC44 7000C044 5440000B */  bnezl $v0, .L7000C074
/* 00CC48 7000C048 AD200000 */   sw    $zero, ($t1)
/* 00CC4C 7000C04C 8C8B0000 */  lw    $t3, ($a0)
/* 00CC50 7000C050 55600008 */  bnezl $t3, .L7000C074
/* 00CC54 7000C054 AD200000 */   sw    $zero, ($t1)
/* 00CC58 7000C058 8CAC0000 */  lw    $t4, ($a1)
/* 00CC5C 7000C05C 55800005 */  bnezl $t4, .L7000C074
/* 00CC60 7000C060 AD200000 */   sw    $zero, ($t1)
/* 00CC64 7000C064 8C6D0000 */  lw    $t5, ($v1)
/* 00CC68 7000C068 51A00006 */  beql  $t5, $zero, .L7000C084
/* 00CC6C 7000C06C 8D220004 */   lw    $v0, 4($t1)
/* 00CC70 7000C070 AD200000 */  sw    $zero, ($t1)
.L7000C074:
/* 00CC74 7000C074 AC800000 */  sw    $zero, ($a0)
/* 00CC78 7000C078 ACA00000 */  sw    $zero, ($a1)
/* 00CC7C 7000C07C AC600000 */  sw    $zero, ($v1)
/* 00CC80 7000C080 8D220004 */  lw    $v0, 4($t1)
.L7000C084:
/* 00CC84 7000C084 5440000B */  bnezl $v0, .L7000C0B4
/* 00CC88 7000C088 AD200004 */   sw    $zero, 4($t1)
/* 00CC8C 7000C08C 8C8E0004 */  lw    $t6, 4($a0)
/* 00CC90 7000C090 55C00008 */  bnezl $t6, .L7000C0B4
/* 00CC94 7000C094 AD200004 */   sw    $zero, 4($t1)
/* 00CC98 7000C098 8CAF0004 */  lw    $t7, 4($a1)
/* 00CC9C 7000C09C 55E00005 */  bnezl $t7, .L7000C0B4
/* 00CCA0 7000C0A0 AD200004 */   sw    $zero, 4($t1)
/* 00CCA4 7000C0A4 8C780004 */  lw    $t8, 4($v1)
/* 00CCA8 7000C0A8 53000006 */  beql  $t8, $zero, .L7000C0C4
/* 00CCAC 7000C0AC 24630008 */   addiu $v1, $v1, 8
/* 00CCB0 7000C0B0 AD200004 */  sw    $zero, 4($t1)
.L7000C0B4:
/* 00CCB4 7000C0B4 AC800004 */  sw    $zero, 4($a0)
/* 00CCB8 7000C0B8 ACA00004 */  sw    $zero, 4($a1)
/* 00CCBC 7000C0BC AC600004 */  sw    $zero, 4($v1)
/* 00CCC0 7000C0C0 24630008 */  addiu $v1, $v1, 8
.L7000C0C4:
/* 00CCC4 7000C0C4 25290008 */  addiu $t1, $t1, 8
/* 00CCC8 7000C0C8 24840008 */  addiu $a0, $a0, 8
/* 00CCCC 7000C0CC 146AFFDC */  bne   $v1, $t2, .L7000C040
/* 00CCD0 7000C0D0 24A50008 */   addiu $a1, $a1, 8
/* 00CCD4 7000C0D4 3C018002 */  lui   $at, %hi(D_80026970)
/* 00CCD8 7000C0D8 AC206970 */  sw    $zero, %lo(D_80026970)($at)
.L7000C0DC:
/* 00CCDC 7000C0DC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7000C0E0:
/* 00CCE0 7000C0E0 27BD0050 */  addiu $sp, $sp, 0x50
/* 00CCE4 7000C0E4 03E00008 */  jr    $ra
/* 00CCE8 7000C0E8 00000000 */   nop   
)
#endif

s8 joyGetStickX(s8 contpadnum)
{
    if (g_ContDataPtr->unk1f8 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		g_ContBadReadsStickX[contpadnum]++;
		return 0;
	}
	return g_ContDataPtr->samples[g_ContDataPtr->curlast].pads[contpadnum].stick_x;

}

s8 joy7000C174(s8 contpadnum) {
    if (g_ContDataPtr->unk1f8 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		g_ContBadReadsStickX[contpadnum]++;
		return 0;
	}
	return g_ContDataPtr->samples[g_ContDataPtr->curstart].pads[contpadnum].stick_x;
}

s8 joyGetStickY(s8 contpadnum) {
    if (g_ContDataPtr->unk1f8 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		g_ContBadReadsStickY[contpadnum]++;
		return 0;
	}
	return g_ContDataPtr->samples[g_ContDataPtr->curlast].pads[contpadnum].stick_y;
}

s8 joy7000C284(s8 contpadnum) {
    if (g_ContDataPtr->unk1f8 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		g_ContBadReadsStickY[contpadnum]++;
		return 0;
	}
	return g_ContDataPtr->samples[g_ContDataPtr->curstart].pads[contpadnum].stick_y;
}

u16 joyGetButtons(s8 contpadnum, u16 mask) {
	if (g_ContDataPtr->unk1f8 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		g_ContBadReadsButtons[contpadnum]++;
		return 0;
	}
	return g_ContDataPtr->samples[g_ContDataPtr->curlast].pads[contpadnum].button & mask;

}

u16 joyGetButtonsPressedThisFrame(s8 contpadnum, u16 mask) {
	if (g_ContDataPtr->unk1f8 < 0 && (g_ConnectedControllers >> contpadnum & 1) == 0) {
		g_ContBadReadsButtonsPressed[contpadnum]++;
		return 0;
	}
    return g_ContDataPtr->buttonspressed[contpadnum] & mask;
}

void joy7000C430(s8 *arg0, u16 arg1) {
    s32 i;
    for (i = 15; i >= 0; i--) {
        *arg0++ = (((((arg1 >> i) & 1) > 0) * 17) + 32);
    }
}

void joy7000C470(void) {
    s32 i = 0;
    for (i = 0; i < get_attached_controller_count(); i++) {
        // Removed
    }
}

s32 joyGetStickXInRange(s8 contpadnum, s32 rangemin, s32 rangemax) {
    s32 range;
    s32 stick_x = joyGetStickX(contpadnum) + 60;
    if (stick_x > 120) {
        stick_x = 120;
    }
    if (stick_x < 0) {
        stick_x = 0;
    }
    range = (rangemax - rangemin);
    return (((stick_x * range) / 120) + rangemin);
}

s32 joyGetStickYInRange(s8 contpadnum, s32 rangemin, s32 rangemax) {
    s32 range;
    s32 stick_y = joyGetStickY(contpadnum) + 60;
    if (stick_y > 120) {
        stick_y = 120;
    }
    if (stick_y < 0) {
        stick_y = 0;
    }
    range = (rangemax - rangemin);
    return (((stick_y * range) / 120) + rangemin);
}

#ifdef NONMATCHING
f32 controller_7000C59C(s8 contpadnum, f32 rangemin, f32 rangemax) {
    s8 stick_x = joyGetStickX(contpadnum) + 60;
    if (stick_x > 120) {
        stick_x = 120;
    }
    if (stick_x < 0) {
        stick_x = 0;
    }
    return (((stick_x / 120.0f) * (rangemax - rangemin)) + rangemin);
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C59C
/* 00D19C 7000C59C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00D1A0 7000C5A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D1A4 7000C5A4 AFA40018 */  sw    $a0, 0x18($sp)
/* 00D1A8 7000C5A8 00047600 */  sll   $t6, $a0, 0x18
/* 00D1AC 7000C5AC 000E2603 */  sra   $a0, $t6, 0x18
/* 00D1B0 7000C5B0 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00D1B4 7000C5B4 0C00303B */  jal   joyGetStickX
/* 00D1B8 7000C5B8 AFA60020 */   sw    $a2, 0x20($sp)
/* 00D1BC 7000C5BC 2444003C */  addiu $a0, $v0, 0x3c
/* 00D1C0 7000C5C0 28810079 */  slti  $at, $a0, 0x79
/* 00D1C4 7000C5C4 14200002 */  bnez  $at, .L7000C5D0
/* 00D1C8 7000C5C8 C7A2001C */   lwc1  $f2, 0x1c($sp)
/* 00D1CC 7000C5CC 24040078 */  li    $a0, 120
.L7000C5D0:
/* 00D1D0 7000C5D0 04830003 */  bgezl $a0, .L7000C5E0
/* 00D1D4 7000C5D4 44842000 */   mtc1  $a0, $f4
/* 00D1D8 7000C5D8 00002025 */  move  $a0, $zero
/* 00D1DC 7000C5DC 44842000 */  mtc1  $a0, $f4
.L7000C5E0:
/* 00D1E0 7000C5E0 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 00D1E4 7000C5E4 44814000 */  mtc1  $at, $f8
/* 00D1E8 7000C5E8 468021A0 */  cvt.s.w $f6, $f4
/* 00D1EC 7000C5EC C7B00020 */  lwc1  $f16, 0x20($sp)
/* 00D1F0 7000C5F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D1F4 7000C5F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 00D1F8 7000C5F8 46028481 */  sub.s $f18, $f16, $f2
/* 00D1FC 7000C5FC 46083283 */  div.s $f10, $f6, $f8
/* 00D200 7000C600 46125102 */  mul.s $f4, $f10, $f18
/* 00D204 7000C604 03E00008 */  jr    $ra
/* 00D208 7000C608 46022000 */   add.s $f0, $f4, $f2
)
#endif





#ifdef NONMATCHING
f32 controller_7000C60C(s8 contpadnum, f32 rangemin, f32 rangemax) {
    s8 stick_y = joyGetStickY(contpadnum) + 60;
    if (stick_y > 120) {
        stick_y = 120;
    }
    if (stick_y < 0) {
        stick_y = 0;
    }
    return (((stick_y / 120.0f) * (rangemax - rangemin)) + rangemin);
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C60C
/* 00D20C 7000C60C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00D210 7000C610 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D214 7000C614 AFA40018 */  sw    $a0, 0x18($sp)
/* 00D218 7000C618 00047600 */  sll   $t6, $a0, 0x18
/* 00D21C 7000C61C 000E2603 */  sra   $a0, $t6, 0x18
/* 00D220 7000C620 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00D224 7000C624 0C00307F */  jal   joyGetStickY
/* 00D228 7000C628 AFA60020 */   sw    $a2, 0x20($sp)
/* 00D22C 7000C62C 2444003C */  addiu $a0, $v0, 0x3c
/* 00D230 7000C630 28810079 */  slti  $at, $a0, 0x79
/* 00D234 7000C634 14200002 */  bnez  $at, .L7000C640
/* 00D238 7000C638 C7A2001C */   lwc1  $f2, 0x1c($sp)
/* 00D23C 7000C63C 24040078 */  li    $a0, 120
.L7000C640:
/* 00D240 7000C640 04830003 */  bgezl $a0, .L7000C650
/* 00D244 7000C644 44842000 */   mtc1  $a0, $f4
/* 00D248 7000C648 00002025 */  move  $a0, $zero
/* 00D24C 7000C64C 44842000 */  mtc1  $a0, $f4
.L7000C650:
/* 00D250 7000C650 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 00D254 7000C654 44814000 */  mtc1  $at, $f8
/* 00D258 7000C658 468021A0 */  cvt.s.w $f6, $f4
/* 00D25C 7000C65C C7B00020 */  lwc1  $f16, 0x20($sp)
/* 00D260 7000C660 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D264 7000C664 27BD0018 */  addiu $sp, $sp, 0x18
/* 00D268 7000C668 46028481 */  sub.s $f18, $f16, $f2
/* 00D26C 7000C66C 46083283 */  div.s $f10, $f6, $f8
/* 00D270 7000C670 46125102 */  mul.s $f4, $f10, $f18
/* 00D274 7000C674 03E00008 */  jr    $ra
/* 00D278 7000C678 46022000 */   add.s $f0, $f4, $f2
)
#endif





#ifdef NONMATCHING
void controller_7000C67C(void) {
    OSMesg msg;
    osSendMesg(&cont1MesgMQ, &msg, OS_MESG_NOBLOCK);
    osRecvMesg(&cont2MesgMQ, &msg, OS_MESG_BLOCK);
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C67C
/* 00D27C 7000C67C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D280 7000C680 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D284 7000C684 3C048006 */  lui   $a0, %hi(cont1MesgMQ)
/* 00D288 7000C688 24845370 */  addiu $a0, %lo(cont1MesgMQ) # addiu $a0, $a0, 0x5370
/* 00D28C 7000C68C 27A5001C */  addiu $a1, $sp, 0x1c
/* 00D290 7000C690 0C0037C4 */  jal   osSendMesg
/* 00D294 7000C694 00003025 */   move  $a2, $zero
/* 00D298 7000C698 3C048006 */  lui   $a0, %hi(cont2MesgMQ)
/* 00D29C 7000C69C 24845390 */  addiu $a0, %lo(cont2MesgMQ) # addiu $a0, $a0, 0x5390
/* 00D2A0 7000C6A0 27A5001C */  addiu $a1, $sp, 0x1c
/* 00D2A4 7000C6A4 0C003774 */  jal   osRecvMesg
/* 00D2A8 7000C6A8 24060001 */   li    $a2, 1
/* 00D2AC 7000C6AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D2B0 7000C6B0 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D2B4 7000C6B4 03E00008 */  jr    $ra
/* 00D2B8 7000C6B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void controller_7000C6BC(void) {
    OSMesg msg;
    osSendMesg(&cont3MesgMQ, &msg, OS_MESG_NOBLOCK);
    osRecvMesg(&cont4MesgMQ, &msg, OS_MESG_BLOCK);
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C6BC
/* 00D2BC 7000C6BC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D2C0 7000C6C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D2C4 7000C6C4 3C048006 */  lui   $a0, %hi(cont3MesgMQ)
/* 00D2C8 7000C6C8 248453B0 */  addiu $a0, %lo(cont3MesgMQ) # addiu $a0, $a0, 0x53b0
/* 00D2CC 7000C6CC 27A5001C */  addiu $a1, $sp, 0x1c
/* 00D2D0 7000C6D0 0C0037C4 */  jal   osSendMesg
/* 00D2D4 7000C6D4 00003025 */   move  $a2, $zero
/* 00D2D8 7000C6D8 3C048006 */  lui   $a0, %hi(cont4MesgMQ)
/* 00D2DC 7000C6DC 248453D0 */  addiu $a0, %lo(cont4MesgMQ) # addiu $a0, $a0, 0x53d0
/* 00D2E0 7000C6E0 27A5001C */  addiu $a1, $sp, 0x1c
/* 00D2E4 7000C6E4 0C003774 */  jal   osRecvMesg
/* 00D2E8 7000C6E8 24060001 */   li    $a2, 1
/* 00D2EC 7000C6EC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D2F0 7000C6F0 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D2F4 7000C6F4 03E00008 */  jr    $ra
/* 00D2F8 7000C6F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C6FC(void) {
    s32 type;
    controller_7000C67C();
    type = osEepromProbe(&contdemoMesgMQ);
    controller_7000C6BC();
    return type;
}
#else
GLOBAL_ASM(
.text
glabel save_7000C6FC
/* 00D2FC 7000C6FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D300 7000C700 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D304 7000C704 0C00319F */  jal   controller_7000C67C
/* 00D308 7000C708 00000000 */   nop   
/* 00D30C 7000C70C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D310 7000C710 0C0053F4 */  jal   osEepromProbe
/* 00D314 7000C714 24845350 */   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D318 7000C718 0C0031AF */  jal   controller_7000C6BC
/* 00D31C 7000C71C AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D320 7000C720 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D324 7000C724 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D328 7000C728 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D32C 7000C72C 03E00008 */  jr    $ra
/* 00D330 7000C730 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C734(u8 address, u8 *buffer)
    s32 ret;
    controller_7000C67C();
    ret = osEepromRead(&contdemoMesgMQ, address, buffer);
    controller_7000C6BC();
    return ret;
}
#else
GLOBAL_ASM(
.text
glabel save_7000C734
/* 00D334 7000C734 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D338 7000C738 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D33C 7000C73C AFA40020 */  sw    $a0, 0x20($sp)
/* 00D340 7000C740 0C00319F */  jal   controller_7000C67C
/* 00D344 7000C744 AFA50024 */   sw    $a1, 0x24($sp)
/* 00D348 7000C748 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D34C 7000C74C 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D350 7000C750 93A50023 */  lbu   $a1, 0x23($sp)
/* 00D354 7000C754 0C005410 */  jal   osEepromRead
/* 00D358 7000C758 8FA60024 */   lw    $a2, 0x24($sp)
/* 00D35C 7000C75C 0C0031AF */  jal   controller_7000C6BC
/* 00D360 7000C760 AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D364 7000C764 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D368 7000C768 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D36C 7000C76C 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D370 7000C770 03E00008 */  jr    $ra
/* 00D374 7000C774 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C778(u8 address, u8 *buffer) {
    s32 ret;
    controller_7000C67C();
    ret = osEepromWrite(&contdemoMesgMQ, address, buffer);
    controller_7000C6BC();
    return ret;
}
#else
GLOBAL_ASM(
.text
glabel save_7000C778
/* 00D378 7000C778 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D37C 7000C77C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D380 7000C780 AFA40020 */  sw    $a0, 0x20($sp)
/* 00D384 7000C784 0C00319F */  jal   controller_7000C67C
/* 00D388 7000C788 AFA50024 */   sw    $a1, 0x24($sp)
/* 00D38C 7000C78C 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D390 7000C790 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D394 7000C794 93A50023 */  lbu   $a1, 0x23($sp)
/* 00D398 7000C798 0C0054D0 */  jal   osEepromWrite
/* 00D39C 7000C79C 8FA60024 */   lw    $a2, 0x24($sp)
/* 00D3A0 7000C7A0 0C0031AF */  jal   controller_7000C6BC
/* 00D3A4 7000C7A4 AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D3A8 7000C7A8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D3AC 7000C7AC 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D3B0 7000C7B0 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D3B4 7000C7B4 03E00008 */  jr    $ra
/* 00D3B8 7000C7B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C7BC(u8 address, u8 *buffer, s32 nbytes) {
    s32 ret;
    controller_7000C67C();
    ret = osEepromLongRead(&contdemoMesgMQ, address, buffer, nbytes);
    controller_7000C6BC();
    return ret;
}
#else
GLOBAL_ASM(
.text
glabel save_7000C7BC
/* 00D3BC 7000C7BC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D3C0 7000C7C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D3C4 7000C7C4 AFA40020 */  sw    $a0, 0x20($sp)
/* 00D3C8 7000C7C8 AFA50024 */  sw    $a1, 0x24($sp)
/* 00D3CC 7000C7CC 0C00319F */  jal   controller_7000C67C
/* 00D3D0 7000C7D0 AFA60028 */   sw    $a2, 0x28($sp)
/* 00D3D4 7000C7D4 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D3D8 7000C7D8 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D3DC 7000C7DC 93A50023 */  lbu   $a1, 0x23($sp)
/* 00D3E0 7000C7E0 8FA60024 */  lw    $a2, 0x24($sp)
/* 00D3E4 7000C7E4 0C005608 */  jal   osEepromLongRead
/* 00D3E8 7000C7E8 8FA70028 */   lw    $a3, 0x28($sp)
/* 00D3EC 7000C7EC 0C0031AF */  jal   controller_7000C6BC
/* 00D3F0 7000C7F0 AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D3F4 7000C7F4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D3F8 7000C7F8 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D3FC 7000C7FC 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D400 7000C800 03E00008 */  jr    $ra
/* 00D404 7000C804 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 save_7000C808(u8 address, u8 *buffer, s32 nbytes) {
    s32 ret;
    controller_7000C67C();
    ret = osEepromLongWrite(&contdemoMesgMQ, address, buffer, nbytes);
    controller_7000C6BC();
    return ret;
}
#else
GLOBAL_ASM(
.text
glabel save_7000C808
/* 00D408 7000C808 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00D40C 7000C80C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D410 7000C810 AFA40020 */  sw    $a0, 0x20($sp)
/* 00D414 7000C814 AFA50024 */  sw    $a1, 0x24($sp)
/* 00D418 7000C818 0C00319F */  jal   controller_7000C67C
/* 00D41C 7000C81C AFA60028 */   sw    $a2, 0x28($sp)
/* 00D420 7000C820 3C048006 */  lui   $a0, %hi(contdemoMesgMQ)
/* 00D424 7000C824 24845350 */  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
/* 00D428 7000C828 93A50023 */  lbu   $a1, 0x23($sp)
/* 00D42C 7000C82C 8FA60024 */  lw    $a2, 0x24($sp)
/* 00D430 7000C830 0C005658 */  jal   osEepromLongWrite
/* 00D434 7000C834 8FA70028 */   lw    $a3, 0x28($sp)
/* 00D438 7000C838 0C0031AF */  jal   controller_7000C6BC
/* 00D43C 7000C83C AFA2001C */   sw    $v0, 0x1c($sp)
/* 00D440 7000C840 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D444 7000C844 8FA2001C */  lw    $v0, 0x1c($sp)
/* 00D448 7000C848 27BD0020 */  addiu $sp, $sp, 0x20
/* 00D44C 7000C84C 03E00008 */  jr    $ra
/* 00D450 7000C850 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void controller_7000C854(s32 arg0, f32 arg1) {
    s32 var1;
    if ((D_80026924 == NULL) && (controller_1_rumble_inserted[arg0] > 0)) {
        var1 = (arg1 * 60.0f);
        if (controller_1_rumble_duration[arg0] < var1) {
            controller_1_rumble_duration[arg0] = var1;
        }
        if (controller_1_rumble_state[arg0]) == 0) {
            controller_1_rumble_pulse[arg0]) = 1;
        }
    }
}

#else
GLOBAL_ASM(
.text
glabel controller_7000C854
/* 00D454 7000C854 3C0E8002 */  lui   $t6, %hi(D_80026924) 
/* 00D458 7000C858 8DCE6924 */  lw    $t6, %lo(D_80026924)($t6)
/* 00D45C 7000C85C 44856000 */  mtc1  $a1, $f12
/* 00D460 7000C860 00041880 */  sll   $v1, $a0, 2
/* 00D464 7000C864 15C0001B */  bnez  $t6, .L7000C8D4
/* 00D468 7000C868 3C0F8002 */   lui   $t7, %hi(controller_1_rumble_inserted)
/* 00D46C 7000C86C 01E37821 */  addu  $t7, $t7, $v1
/* 00D470 7000C870 8DEF68D8 */  lw    $t7, %lo(controller_1_rumble_inserted)($t7)
/* 00D474 7000C874 3C098002 */  lui   $t1, %hi(controller_1_rumble_state)
/* 00D478 7000C878 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 00D47C 7000C87C 19E00015 */  blez  $t7, .L7000C8D4
/* 00D480 7000C880 01234821 */   addu  $t1, $t1, $v1
/* 00D484 7000C884 44812000 */  mtc1  $at, $f4
/* 00D488 7000C888 3C188002 */  lui   $t8, %hi(controller_1_rumble_duration) 
/* 00D48C 7000C88C 271868F8 */  addiu $t8, %lo(controller_1_rumble_duration) # addiu $t8, $t8, 0x68f8
/* 00D490 7000C890 46046182 */  mul.s $f6, $f12, $f4
/* 00D494 7000C894 00782021 */  addu  $a0, $v1, $t8
/* 00D498 7000C898 8C880000 */  lw    $t0, ($a0)
/* 00D49C 7000C89C 240A0001 */  li    $t2, 1
/* 00D4A0 7000C8A0 4600320D */  trunc.w.s $f8, $f6
/* 00D4A4 7000C8A4 44024000 */  mfc1  $v0, $f8
/* 00D4A8 7000C8A8 00000000 */  nop   
/* 00D4AC 7000C8AC 0102082A */  slt   $at, $t0, $v0
/* 00D4B0 7000C8B0 10200002 */  beqz  $at, .L7000C8BC
/* 00D4B4 7000C8B4 00000000 */   nop   
/* 00D4B8 7000C8B8 AC820000 */  sw    $v0, ($a0)
.L7000C8BC:
/* 00D4BC 7000C8BC 8D2968E8 */  lw    $t1, %lo(controller_1_rumble_state)($t1)
/* 00D4C0 7000C8C0 3C018002 */  lui   $at, %hi(controller_1_rumble_pulse)
/* 00D4C4 7000C8C4 00230821 */  addu  $at, $at, $v1
/* 00D4C8 7000C8C8 15200002 */  bnez  $t1, .L7000C8D4
/* 00D4CC 7000C8CC 00000000 */   nop   
/* 00D4D0 7000C8D0 AC2A6908 */  sw    $t2, %lo(controller_1_rumble_pulse)($at)
.L7000C8D4:
/* 00D4D4 7000C8D4 03E00008 */  jr    $ra
/* 00D4D8 7000C8D8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void reset_cont_rumble_detect(void) { // Loop?
#ifdef VERION_US
    controller_1_rumble_state[0] = 1;
    controller_1_rumble_pulse[0] = 0;
    controller_1_rumble_state[1] = 1;
    controller_1_rumble_pulse[1] = 0;
    controller_1_rumble_state[2] = 1;
    controller_1_rumble_pulse[2] = 0;
    controller_1_rumble_state[3] = 1;
    controller_1_rumble_pulse[3] = 0;
#endif
#ifdef VERSION_JP
    controller_1_rumble_pulse[0] = 2;
    controller_1_rumble_pulse[1] = 2;
    controller_1_rumble_pulse[2] = 2;
    controller_1_rumble_pulse[3] = 2;
#endif
}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel reset_cont_rumble_detect
/* 00D4DC 7000C8DC 240E0001 */  li    $t6, 1
/* 00D4E0 7000C8E0 3C018002 */  lui   $at, %hi(controller_1_rumble_state)
/* 00D4E4 7000C8E4 AC2E68E8 */  sw    $t6, %lo(controller_1_rumble_state)($at)
/* 00D4E8 7000C8E8 3C018002 */  lui   $at, %hi(controller_1_rumble_pulse)
/* 00D4EC 7000C8EC AC206908 */  sw    $zero, %lo(controller_1_rumble_pulse)($at)
/* 00D4F0 7000C8F0 3C018002 */  lui   $at, %hi(controller_1_rumble_state+0x4)
/* 00D4F4 7000C8F4 240F0001 */  li    $t7, 1
/* 00D4F8 7000C8F8 AC2F68EC */  sw    $t7, %lo(controller_1_rumble_state+0x4)($at)
/* 00D4FC 7000C8FC 3C018002 */  lui   $at, %hi(controller_1_rumble_pulse+0x4)
/* 00D500 7000C900 AC20690C */  sw    $zero, %lo(controller_1_rumble_pulse+0x4)($at)
/* 00D504 7000C904 3C018002 */  lui   $at, %hi(controller_1_rumble_state+0x8)
/* 00D508 7000C908 24180001 */  li    $t8, 1
/* 00D50C 7000C90C AC3868F0 */  sw    $t8, %lo(controller_1_rumble_state+0x8)($at)
/* 00D510 7000C910 3C018002 */  lui   $at, %hi(controller_1_rumble_pulse+0x8)
/* 00D514 7000C914 AC206910 */  sw    $zero, %lo(controller_1_rumble_pulse+0x8)($at)
/* 00D518 7000C918 3C018002 */  lui   $at, %hi(controller_1_rumble_state+0xC)
/* 00D51C 7000C91C 24190001 */  li    $t9, 1
/* 00D520 7000C920 AC3968F4 */  sw    $t9, %lo(controller_1_rumble_state+0xC)($at)
/* 00D524 7000C924 3C018002 */  lui   $at, %hi( controller_1_rumble_pulse+0xC)
/* 00D528 7000C928 03E00008 */  jr    $ra
/* 00D52C 7000C92C AC206914 */   sw    $zero, %lo( controller_1_rumble_pulse+0xC)($at)
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel reset_cont_rumble_detect
/* 00D4E8 7000C8E8 3C018002 */  lui   $at, %hi(controller_1_rumble_pulse)
/* 00D4F4 7000C8F4 240F0001 */  li    $t7, 2
/* 00D4DC 7000C8DC 240E0001 */  li    $t6, 2
/* 00D500 7000C900 AC20690C */  sw    $t7, %lo(controller_2_rumble_pulse)($at)
/* 00D4EC 7000C8EC AC206908 */  sw    $t6, %lo(controller_1_rumble_pulse)($at)
/* 00D510 7000C910 3C018002 */  lui   $at, %hi(controller_3_rumble_pulse)
/* 00D508 7000C908 24180001 */  li    $t8, 2
/* 00D51C 7000C91C 24190001 */  li    $t9, 2
/* 00D514 7000C914 AC206910 */  sw    $t9, %lo(controller_4_rumble_pulse)($at)
/* 00D528 7000C928 03E00008 */  jr    $ra
/* 00D52C 7000C92C AC206914 */   sw    $t8, %lo( controller_3_rumble_pulse)($at)
)
#endif

#endif





#ifdef NONMATCHING
void controller_7000C930(s32 arg0) {
    g_ContDataPtr = &g_ContData[arg0];
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C930
/* 00D530 7000C930 000471C0 */  sll   $t6, $a0, 7
/* 00D534 7000C934 01C47023 */  subu  $t6, $t6, $a0
/* 00D538 7000C938 3C0F8006 */  lui   $t7, %hi(g_ContData) 
/* 00D53C 7000C93C 25EF4F30 */  addiu $t7, %lo(g_ContData) # addiu $t7, $t7, 0x4f30
/* 00D540 7000C940 000E7080 */  sll   $t6, $t6, 2
/* 00D544 7000C944 01CFC021 */  addu  $t8, $t6, $t7
/* 00D548 7000C948 3C018002 */  lui   $at, %hi(g_ContDataPtr)
/* 00D54C 7000C94C 03E00008 */  jr    $ra
/* 00D550 7000C950 AC3868C4 */   sw    $t8, %lo(g_ContDataPtr)($at)
)
#endif





#ifdef NONMATCHING
s32 controller_7000C954(void) {
    return (g_ContDataPtr - g_ContData);
    //return (s32) (g_ContDataPtr - &g_ContData) / 0x1FC;
}
#else
GLOBAL_ASM(
.text
glabel controller_7000C954
/* 00D554 7000C954 3C0E8002 */  lui   $t6, %hi(g_ContDataPtr) 
/* 00D558 7000C958 8DCE68C4 */  lw    $t6, %lo(g_ContDataPtr)($t6)
/* 00D55C 7000C95C 3C0F8006 */  lui   $t7, %hi(g_ContData) 
/* 00D560 7000C960 25EF4F30 */  addiu $t7, %lo(g_ContData) # addiu $t7, $t7, 0x4f30
/* 00D564 7000C964 240101FC */  li    $at, 508
/* 00D568 7000C968 01CF1023 */  subu  $v0, $t6, $t7
/* 00D56C 7000C96C 0041001A */  div   $zero, $v0, $at
/* 00D570 7000C970 00001012 */  mflo  $v0
/* 00D574 7000C974 03E00008 */  jr    $ra
/* 00D578 7000C978 00000000 */   nop   
)  
#endif




