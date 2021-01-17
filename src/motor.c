#include "ultra64.h"
#include "libultra/controller.h"

OSPifRam  _MotorStopData[MAXCONTROLLERS];
OSPifRam  _MotorStartData[MAXCONTROLLERS];
u8 _motorstopbuf[32];
u8 _motorstartbuf[32];

s32 osMotorStop(OSPfs *pfs)
{
    int i;
    s32 ret;
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;

    ptr = (u8*)&__osPfsPifRam;

    __osSiGetAccess();

    __osContLastCmd = CONT_CMD_WRITE_MEMPACK;
    __osSiRawStartDma(OS_WRITE, &_MotorStopData[pfs->channel]);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    ptr = (u8*)&__osPfsPifRam;

    if (pfs->channel != 0)
        for (i = 0; i < pfs->channel; i++)
            ptr++;

    ramreadformat = *(__OSContRamReadFormat*)ptr;
    ret = CHNL_ERR(ramreadformat);
    if (ret == 0 && ramreadformat.datacrc != 0) {
        ret = PFS_ERR_CONTRFAIL;
    }
    __osSiRelAccess();
    return ret;
}

s32 osMotorStart(OSPfs *pfs)
{
    int i;
    s32 ret;
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;

    ptr = (u8 *)&__osPfsPifRam;

    __osSiGetAccess();

    __osContLastCmd = CONT_CMD_WRITE_MEMPACK;
    __osSiRawStartDma(OS_WRITE, &_MotorStartData[pfs->channel]);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    ptr = (u8 *)&__osPfsPifRam;

    if (pfs->channel != 0)
        for (i = 0; i < pfs->channel; i++)
            ptr++;

    ramreadformat = *(__OSContRamReadFormat *)ptr;
    ret = CHNL_ERR(ramreadformat);
    if (ret == 0 && ramreadformat.datacrc != 0xEB)
    {
        ret = PFS_ERR_CONTRFAIL;
    }
    __osSiRelAccess();
    return ret;
}

void _MakeMotorData(int channel, u16 address, u8 *buffer, OSPifRam *mdata)
{
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;
    int i;

    ptr = (u8 *)mdata->ramarray;
    for (i = 0; i < ARRLEN(mdata->ramarray); i++)
        mdata->ramarray[i] = 0;
    mdata->pifstatus = CONT_CMD_EXE;
    ramreadformat.dummy = CONT_CMD_NOP;
    ramreadformat.txsize = CONT_CMD_WRITE_MEMPACK_TX;
    ramreadformat.rxsize = CONT_CMD_WRITE_MEMPACK_RX;
    ramreadformat.cmd = CONT_CMD_WRITE_MEMPACK;
    ramreadformat.address = (address << 0x5) | __osContAddressCrc(address);
    ramreadformat.datacrc = CONT_CMD_NOP;
    for (i = 0; i < ARRLEN(ramreadformat.data); i++)
        ramreadformat.data[i] = *buffer++;
    if (channel != 0)
    {
        for (i = 0; i < channel; i++)
        {
            *ptr++ = 0;
        }
    }
    *(__OSContRamReadFormat *)ptr = ramreadformat;
    ptr += sizeof(__OSContRamReadFormat);
    ptr[0] = CONT_CMD_END;
}

#ifdef NONMATCHING
s32 osMotorInit(OSMesgQueue *mq,OSPfs *pfs,int channel) {
    s32 sp2C;
    ? sp30;
    ? sp50;
    u32 temp_v0;
    ? temp_ret;
    void *temp_v1;
    s32 temp_v0_2;

    // Node 0
    arg1->unk4 = arg0;
    arg1->unk8 = arg2;
    *arg1 = 0;
    arg1->unk65 = (u8)0x80;
    // Node 1
    temp_v0 = (&sp30 + 1);
    temp_v0->unk-1 = (u8)0x80;
    if (temp_v0 < &sp50)
    {
        goto loop_1;
    }
    // Node 2
    temp_ret = __osContRamWrite(arg2, 0x400, &sp30, 0);
    if (temp_ret == 2)
    {
        // Node 3
        __osContRamWrite(arg16, arg2, 0x400, &sp30, 0);
    }
    // Node 4
    if (temp_ret != 0)
    {
        // Node 5
    }
    else
    {
        // Node 6
        if (__osContRamRead(arg16, arg2, 0x400, &sp30) != 0)
        {
            // Node 7
            return;
            // (possible return value: __osContRamRead(arg16, arg2, 0x400, &sp30))
        }
        // Node 8
        if (sp4F != 0x80)
        {
            // Node 9
        }
        else
        {
            // Node 10
            // Node 11
            temp_v1 = (&_motorstopbuf + 4);
            _motorstartbuf.unk1 = (u8)1;
            temp_v1->unk-3 = (u8)0;
            _motorstartbuf.unk2 = (u8)1;
            temp_v1->unk-2 = (u8)0;
            _motorstartbuf.unk3 = (u8)1;
            temp_v1->unk-1 = (u8)0;
            (&_motorstartbuf + 4)->unk-4 = (u8)1;
            temp_v1->unk-4 = (u8)0;
            if (temp_v1 != &_motorstartbuf)
            {
                goto loop_11;
            }
            // Node 12
            temp_v0_2 = (arg2 << 6);
            sp2C = temp_v0_2;
            _MakeMotorData(arg2, 0x600, &_motorstartbuf, (temp_v0_2 + &_MotorStartData));
            _MakeMotorData(arg2, 0x600, &_motorstopbuf, (sp2C + &_MotorStopData));
        }
    }
    // Node 13
    return;
    // (possible return value: 0)
}
#else
GLOBAL_ASM(
.text
glabel osMotorInit
/* 00D938 7000CD38 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 00D93C 7000CD3C AFB00020 */  sw    $s0, 0x20($sp)
/* 00D940 7000CD40 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00D944 7000CD44 24070080 */  li    $a3, 128
/* 00D948 7000CD48 00C08025 */  move  $s0, $a2
/* 00D94C 7000CD4C ACA40004 */  sw    $a0, 4($a1)
/* 00D950 7000CD50 ACA60008 */  sw    $a2, 8($a1)
/* 00D954 7000CD54 ACA00000 */  sw    $zero, ($a1)
/* 00D958 7000CD58 A0A70065 */  sb    $a3, 0x65($a1)
/* 00D95C 7000CD5C 27A20030 */  addiu $v0, $sp, 0x30
/* 00D960 7000CD60 27A30050 */  addiu $v1, $sp, 0x50
.L7000CD64:
/* 00D964 7000CD64 24420001 */  addiu $v0, $v0, 1
/* 00D968 7000CD68 0043082B */  sltu  $at, $v0, $v1
/* 00D96C 7000CD6C 1420FFFD */  bnez  $at, .L7000CD64
/* 00D970 7000CD70 A047FFFF */   sb    $a3, -1($v0)
/* 00D974 7000CD74 02002825 */  move  $a1, $s0
/* 00D978 7000CD78 24060400 */  li    $a2, 1024
/* 00D97C 7000CD7C 27A70030 */  addiu $a3, $sp, 0x30
/* 00D980 7000CD80 AFA00010 */  sw    $zero, 0x10($sp)
/* 00D984 7000CD84 0C005840 */  jal   __osContRamWrite
/* 00D988 7000CD88 AFA40058 */   sw    $a0, 0x58($sp)
/* 00D98C 7000CD8C 24010002 */  li    $at, 2
/* 00D990 7000CD90 14410008 */  bne   $v0, $at, .L7000CDB4
/* 00D994 7000CD94 00401825 */   move  $v1, $v0
/* 00D998 7000CD98 8FA40058 */  lw    $a0, 0x58($sp)
/* 00D99C 7000CD9C 02002825 */  move  $a1, $s0
/* 00D9A0 7000CDA0 24060400 */  li    $a2, 1024
/* 00D9A4 7000CDA4 27A70030 */  addiu $a3, $sp, 0x30
/* 00D9A8 7000CDA8 0C005840 */  jal   __osContRamWrite
/* 00D9AC 7000CDAC AFA00010 */   sw    $zero, 0x10($sp)
/* 00D9B0 7000CDB0 00401825 */  move  $v1, $v0
.L7000CDB4:
/* 00D9B4 7000CDB4 10400003 */  beqz  $v0, .L7000CDC4
/* 00D9B8 7000CDB8 8FA40058 */   lw    $a0, 0x58($sp)
/* 00D9BC 7000CDBC 10000033 */  b     .L7000CE8C
/* 00D9C0 7000CDC0 00601025 */   move  $v0, $v1
.L7000CDC4:
/* 00D9C4 7000CDC4 02002825 */  move  $a1, $s0
/* 00D9C8 7000CDC8 24060400 */  li    $a2, 1024
/* 00D9CC 7000CDCC 0C00592C */  jal   __osContRamRead
/* 00D9D0 7000CDD0 27A70030 */   addiu $a3, $sp, 0x30
/* 00D9D4 7000CDD4 10400003 */  beqz  $v0, .L7000CDE4
/* 00D9D8 7000CDD8 93AE004F */   lbu   $t6, 0x4f($sp)
/* 00D9DC 7000CDDC 1000002C */  b     .L7000CE90
/* 00D9E0 7000CDE0 8FBF0024 */   lw    $ra, 0x24($sp)
.L7000CDE4:
/* 00D9E4 7000CDE4 24010080 */  li    $at, 128
/* 00D9E8 7000CDE8 11C10003 */  beq   $t6, $at, .L7000CDF8
/* 00D9EC 7000CDEC 3C048006 */   lui   $a0, %hi(_motorstartbuf)
/* 00D9F0 7000CDF0 10000026 */  b     .L7000CE8C
/* 00D9F4 7000CDF4 2402000B */   li    $v0, 11
.L7000CDF8:
/* 00D9F8 7000CDF8 3C038006 */  lui   $v1, %hi(_motorstopbuf)
/* 00D9FC 7000CDFC 3C058006 */  lui   $a1, %hi(_motorstartbuf)
/* 00DA00 7000CE00 24A557C0 */  addiu $a1, %lo(_motorstartbuf) # addiu $a1, $a1, 0x57c0
/* 00DA04 7000CE04 246357A0 */  addiu $v1, %lo(_motorstopbuf) # addiu $v1, $v1, 0x57a0
/* 00DA08 7000CE08 248457C0 */  addiu $a0, %lo(_motorstartbuf) # addiu $a0, $a0, 0x57c0
/* 00DA0C 7000CE0C 24020001 */  li    $v0, 1
.L7000CE10:
/* 00DA10 7000CE10 24630004 */  addiu $v1, $v1, 4
/* 00DA14 7000CE14 A0820001 */  sb    $v0, 1($a0)
/* 00DA18 7000CE18 A060FFFD */  sb    $zero, -3($v1)
/* 00DA1C 7000CE1C A0820002 */  sb    $v0, 2($a0)
/* 00DA20 7000CE20 A060FFFE */  sb    $zero, -2($v1)
/* 00DA24 7000CE24 A0820003 */  sb    $v0, 3($a0)
/* 00DA28 7000CE28 A060FFFF */  sb    $zero, -1($v1)
/* 00DA2C 7000CE2C 24840004 */  addiu $a0, $a0, 4
/* 00DA30 7000CE30 A082FFFC */  sb    $v0, -4($a0)
/* 00DA34 7000CE34 1465FFF6 */  bne   $v1, $a1, .L7000CE10
/* 00DA38 7000CE38 A060FFFC */   sb    $zero, -4($v1)
/* 00DA3C 7000CE3C 3C0F8006 */  lui   $t7, %hi(_MotorStartData) 
/* 00DA40 7000CE40 25EF56A0 */  addiu $t7, %lo(_MotorStartData) # addiu $t7, $t7, 0x56a0
/* 00DA44 7000CE44 3C068006 */  lui   $a2, %hi(_motorstartbuf)
/* 00DA48 7000CE48 00101180 */  sll   $v0, $s0, 6
/* 00DA4C 7000CE4C 004F3821 */  addu  $a3, $v0, $t7
/* 00DA50 7000CE50 AFA2002C */  sw    $v0, 0x2c($sp)
/* 00DA54 7000CE54 24C657C0 */  addiu $a2, %lo(_motorstartbuf) # addiu $a2, $a2, 0x57c0
/* 00DA58 7000CE58 02002025 */  move  $a0, $s0
/* 00DA5C 7000CE5C 0C0032F7 */  jal   _MakeMotorData
/* 00DA60 7000CE60 24050600 */   li    $a1, 1536
/* 00DA64 7000CE64 8FA2002C */  lw    $v0, 0x2c($sp)
/* 00DA68 7000CE68 3C188006 */  lui   $t8, %hi(_MotorStopData) 
/* 00DA6C 7000CE6C 271855A0 */  addiu $t8, %lo(_MotorStopData) # addiu $t8, $t8, 0x55a0
/* 00DA70 7000CE70 3C068006 */  lui   $a2, %hi(_motorstopbuf)
/* 00DA74 7000CE74 24C657A0 */  addiu $a2, %lo(_motorstopbuf) # addiu $a2, $a2, 0x57a0
/* 00DA78 7000CE78 02002025 */  move  $a0, $s0
/* 00DA7C 7000CE7C 24050600 */  li    $a1, 1536
/* 00DA80 7000CE80 0C0032F7 */  jal   _MakeMotorData
/* 00DA84 7000CE84 00583821 */   addu  $a3, $v0, $t8
/* 00DA88 7000CE88 00001025 */  move  $v0, $zero
.L7000CE8C:
/* 00DA8C 7000CE8C 8FBF0024 */  lw    $ra, 0x24($sp)
.L7000CE90:
/* 00DA90 7000CE90 8FB00020 */  lw    $s0, 0x20($sp)
/* 00DA94 7000CE94 27BD0058 */  addiu $sp, $sp, 0x58
/* 00DA98 7000CE98 03E00008 */  jr    $ra
/* 00DA9C 7000CE9C 00000000 */   nop   
)
#endif
