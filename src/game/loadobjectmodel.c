#include <ultra64.h>
#include <bondtypes.h>
#include "chrai.h"
#include "chrobjdata.h"
#include "loadobjectmodel.h"
#include "stan.h"

/**
 * Address 0x7F056850.
*/
s32 sub_GAME_7F056850(PadRecord *arg0, StandTile *arg1, f32 arg2, PadRecord *arg3, StandTile **arg4)
{
    arg3->pos.f[0] = arg0->pos.f[0];
    arg3->pos.f[1] = arg0->pos.f[1];
    arg3->pos.f[2] = arg0->pos.f[2];
    
    *arg4 = arg1;
    
    if (arg1 == 0)
    {
        return 0;
    }
    
    if ((arg2 > 0.0f) && (sub_GAME_7F0B18B8(arg4, arg3->pos.f[0], arg3->pos.f[2], arg2, 0x1F, 0.0f, 1.0f) >= 0))
    {
        return 0;
    }
    
    return 1;
}

//Todo: finish this func
/**
 * Get Size of Prop Definition 
 * @param pdef:  Prop Defenition to get size of
 * @return Size of prop in Words (32bit)
*/
s32 sizepropdef(PropDefHeaderRecord *pdef)
{
    switch(pdef->type)
    {
        case PROPDEF_GUARD:
            return sizeof(GuardRecord) / 4;
        case PROPDEF_DOOR:
            return sizeof(DoorRecord) / 4;
        case PROPDEF_DOOR_SCALE:
            return sizeof(GlobalDoorScaleRecord) / 4;
        case PROPDEF_PROP:
            return sizeof(ObjectRecord) / 4;
        case PROPDEF_GLASS:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_TINTED_GLASS:
            return 0x25;//return sizeof(TintedGlassRecord) / 4;
        case PROPDEF_SAFE:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_GAS_RELEASING:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_KEY:
            return 0x21;//return sizeof(GlassRecord) / 4;
        case PROPDEF_ALARM:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_CCTV:
            return 0x3b;//return sizeof(GlassRecord) / 4;
        case PROPDEF_MAGAZINE:
            return 0x21;//return sizeof(GlassRecord) / 4;
        case PROPDEF_COLLECTABLE:
            return 0x22;//return sizeof(GlassRecord) / 4;
        case PROPDEF_MONITOR:
            return 0x40;//return sizeof(GlassRecord) / 4;
        case PROPDEF_MULTI_MONITOR:
            return 0x95;//return sizeof(GlassRecord) / 4;
        case PROPDEF_RACK:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_AUTOGUN:
            return 0x36;//return sizeof(GlassRecord) / 4;
        case PROPDEF_LINK:
            return 3;//return sizeof(GlassRecord) / 4;
        case PROPDEF_HAT:
            return 0x20;//return sizeof(GlassRecord) / 4;
        case PROPDEF_GUARD_ATTRIBUTE:
            return 3;//return sizeof(GlassRecord) / 4;
        case PROPDEF_SWITCH:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_SAFE_ITEM:
            return 5;//return sizeof(GlassRecord) / 4;
        case PROPDEF_AMMO:
            return 0x2d;//return sizeof(GlassRecord) / 4;
        case PROPDEF_ARMOUR:
            return 0x22;//return sizeof(GlassRecord) / 4;
        case PROPDEF_TAG:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_RENAME:
            return 10;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_START:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_END:
            return 1;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_DESTROY_OBJECT:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_COMPLETE_CONDITION:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_FAIL_CONDITION:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_COLLECT_OBJECT:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT:
            return 2;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_PHOTOGRAPH:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_NULL:
            return 1;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_ENTER_ROOM:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM:
            return 5;//return sizeof(GlassRecord) / 4;
        case PROPDEF_OBJECTIVE_COPY_ITEM:
            return 1;//return sizeof(GlassRecord) / 4;
        case PROPDEF_WATCH_MENU_OBJECTIVE_TEXT:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_LOCK_DOOR:
            return 4;//return sizeof(GlassRecord) / 4;
        case PROPDEF_VEHICHLE:
            return 0x2c;//return sizeof(GlassRecord) / 4;
        case PROPDEF_AIRCRAFT:
            return 0x2d;//return sizeof(GlassRecord) / 4;
        case PROPDEF_TANK:
            return 0x38;//return sizeof(GlassRecord) / 4;
        case PROPDEF_CAMERAPOS:
            return 7;//return sizeof(GlassRecord) / 4;
        default:
            return sizeof(PropDefHeaderRecord) / 4;;
    }
}




/*
 *Return Item by Setup index
 *Setup Array is most likley PropDefHeaderRecord since size was 4
 */
ObjectRecord *sub_GAME_7F056A88(s32 index) //#MATCH
{
    PropDefHeaderRecord *object = g_chraiCurrentSetup.propDefs; //wow, first use of header, cool
    if (index >= 0 && object)
    {
        s32 i;
        for (i = 0; object->type != PROPDEF_END; i++)
        {
            if (i == index)
            {
                return object;
            }
            object = sizepropdef(object) + object; //This is correct order, using += swaps t7/s1
        }
    }
    return NULL;
}




#ifdef NONMATCHING
s32 check_if_object_type_has_been_loaded(struct object_standard * arg0)
{
    struct object_standard *object;
    s32 i;
    
    if (g_chraiCurrentSetup.propDefs != 0)
    {
        for (object = g_chraiCurrentSetup.propDefs, i = 0; 0x30 != object->type; i++)
        {
            if (object == arg0)
            {
                return i;
            }
            object = (sizepropdef((u8 *)object) * 4) + object;
        }
    }
    return -1;
}

#else
GLOBAL_ASM(
.text
glabel check_if_object_type_has_been_loaded
/* 08B64C 7F056B1C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08B650 7F056B20 AFB00014 */  sw    $s0, 0x14($sp)
/* 08B654 7F056B24 3C108007 */  lui   $s0, %hi(g_chraiCurrentSetup+0x0c)
/* 08B658 7F056B28 8E105D0C */  lw    $s0, %lo(g_chraiCurrentSetup+0x0c)($s0)
/* 08B65C 7F056B2C AFB30020 */  sw    $s3, 0x20($sp)
/* 08B660 7F056B30 00809825 */  move  $s3, $a0
/* 08B664 7F056B34 AFBF0024 */  sw    $ra, 0x24($sp)
/* 08B668 7F056B38 AFB2001C */  sw    $s2, 0x1c($sp)
/* 08B66C 7F056B3C 12000012 */  beqz  $s0, .L7F056B88
/* 08B670 7F056B40 AFB10018 */   sw    $s1, 0x18($sp)
/* 08B674 7F056B44 920E0003 */  lbu   $t6, 3($s0)
/* 08B678 7F056B48 24120030 */  li    $s2, 48
/* 08B67C 7F056B4C 00008825 */  move  $s1, $zero
/* 08B680 7F056B50 524E000E */  beql  $s2, $t6, .L7F056B8C
/* 08B684 7F056B54 2402FFFF */   li    $v0, -1
.L7F056B58:
/* 08B688 7F056B58 16130003 */  bne   $s0, $s3, .L7F056B68
/* 08B68C 7F056B5C 00000000 */   nop   
/* 08B690 7F056B60 1000000A */  b     .L7F056B8C
/* 08B694 7F056B64 02201025 */   move  $v0, $s1
.L7F056B68:
/* 08B698 7F056B68 0FC15A3D */  jal   sizepropdef
/* 08B69C 7F056B6C 02002025 */   move  $a0, $s0
/* 08B6A0 7F056B70 00027880 */  sll   $t7, $v0, 2
/* 08B6A4 7F056B74 01F08021 */  addu  $s0, $t7, $s0
/* 08B6A8 7F056B78 92180003 */  lbu   $t8, 3($s0)
/* 08B6AC 7F056B7C 26310001 */  addiu $s1, $s1, 1
/* 08B6B0 7F056B80 1658FFF5 */  bne   $s2, $t8, .L7F056B58
/* 08B6B4 7F056B84 00000000 */   nop   
.L7F056B88:
/* 08B6B8 7F056B88 2402FFFF */  li    $v0, -1
.L7F056B8C:
/* 08B6BC 7F056B8C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 08B6C0 7F056B90 8FB00014 */  lw    $s0, 0x14($sp)
/* 08B6C4 7F056B94 8FB10018 */  lw    $s1, 0x18($sp)
/* 08B6C8 7F056B98 8FB2001C */  lw    $s2, 0x1c($sp)
/* 08B6CC 7F056B9C 8FB30020 */  lw    $s3, 0x20($sp)
/* 08B6D0 7F056BA0 03E00008 */  jr    $ra
/* 08B6D4 7F056BA4 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING

s32 sub_GAME_7F056BA8(s32 arg0)
{
    PropRecord *temp_s0;
    PropRecord *temp_s0_2;
    PropRecord *phi_s0;
    s32         phi_s1;

    temp_s0 = g_chraiCurrentSetup.props;
    phi_s0  = temp_s0;
    if (temp_s0 != 0)
    {
        phi_s1 = 0;
        if (temp_s0->unk3 != 0x30)
        {
loop_2:
            if (arg0 == phi_s0->pos.AsArray[2])
            {
                return phi_s1;
            }
            temp_s0_2 = (sizepropdef(phi_s0) * 4) + phi_s0;
            phi_s0    = temp_s0_2;
            phi_s1 += 1;
            if (temp_s0_2->unk3 == 0x30)
            {
                goto block_5;
            }
            goto loop_2;
        }
    }
block_5:
    return -1;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F056BA8
/* 08B6D8 7F056BA8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08B6DC 7F056BAC AFB00014 */  sw    $s0, 0x14($sp)
/* 08B6E0 7F056BB0 3C108007 */  lui   $s0, %hi(g_chraiCurrentSetup+0x0c)
/* 08B6E4 7F056BB4 8E105D0C */  lw    $s0, %lo(g_chraiCurrentSetup+0x0c)($s0)
/* 08B6E8 7F056BB8 AFB30020 */  sw    $s3, 0x20($sp)
/* 08B6EC 7F056BBC 00809825 */  move  $s3, $a0
/* 08B6F0 7F056BC0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 08B6F4 7F056BC4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 08B6F8 7F056BC8 12000013 */  beqz  $s0, .L7F056C18
/* 08B6FC 7F056BCC AFB10018 */   sw    $s1, 0x18($sp)
/* 08B700 7F056BD0 920E0003 */  lbu   $t6, 3($s0)
/* 08B704 7F056BD4 24120030 */  li    $s2, 48
/* 08B708 7F056BD8 00008825 */  move  $s1, $zero
/* 08B70C 7F056BDC 524E000F */  beql  $s2, $t6, .L7F056C1C
/* 08B710 7F056BE0 2402FFFF */   li    $v0, -1
/* 08B714 7F056BE4 8E0F0010 */  lw    $t7, 0x10($s0)
.L7F056BE8:
/* 08B718 7F056BE8 166F0003 */  bne   $s3, $t7, .L7F056BF8
/* 08B71C 7F056BEC 00000000 */   nop   
/* 08B720 7F056BF0 1000000A */  b     .L7F056C1C
/* 08B724 7F056BF4 02201025 */   move  $v0, $s1
.L7F056BF8:
/* 08B728 7F056BF8 0FC15A3D */  jal   sizepropdef
/* 08B72C 7F056BFC 02002025 */   move  $a0, $s0
/* 08B730 7F056C00 0002C080 */  sll   $t8, $v0, 2
/* 08B734 7F056C04 03108021 */  addu  $s0, $t8, $s0
/* 08B738 7F056C08 92190003 */  lbu   $t9, 3($s0)
/* 08B73C 7F056C0C 26310001 */  addiu $s1, $s1, 1
/* 08B740 7F056C10 5659FFF5 */  bnel  $s2, $t9, .L7F056BE8
/* 08B744 7F056C14 8E0F0010 */   lw    $t7, 0x10($s0)
.L7F056C18:
/* 08B748 7F056C18 2402FFFF */  li    $v0, -1
.L7F056C1C:
/* 08B74C 7F056C1C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 08B750 7F056C20 8FB00014 */  lw    $s0, 0x14($sp)
/* 08B754 7F056C24 8FB10018 */  lw    $s1, 0x18($sp)
/* 08B758 7F056C28 8FB2001C */  lw    $s2, 0x1c($sp)
/* 08B75C 7F056C2C 8FB30020 */  lw    $s3, 0x20($sp)
/* 08B760 7F056C30 03E00008 */  jr    $ra
/* 08B764 7F056C34 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif




s32 load_model(u32 modelid)
{
    if (PitemZ_entries[modelid].header->RootNode == NULL) 
    {
        load_object_into_memory(PitemZ_entries[modelid].header,PitemZ_entries[modelid].filename);
        set_objuse_flag_compute_grp_nums_set_obj_loaded(PitemZ_entries[modelid].header);
        return TRUE;
    }
    return FALSE;
}





#ifdef NONMATCHING
//https://decomp.me/scratch/FPpor
void sub_GAME_7F056CA0(ObjectRecord *obj)
{
    f32         sp48;
    f32         sp44;
    f32         sp40;
    f32         sp3C;
    f32         sp38;
    f32         sp34;
    s32         sp30;
    void      **sp28;
    PropRecord *temp_s1;
    StandTile  *temp_v0;
    f32         temp_f0;
    f32         temp_f12;
    f32         temp_f2;
    f32        *temp_a1_2;
    f32        *temp_a2;
    s32         temp_a0;
    s32         temp_cond;
    s32         temp_v0_2;
    void      **temp_a1;
    f32         phi_f20;
    f32         phi_f20_2;
    f32         phi_f20_3;
    f32         phi_f20_4;

    temp_s1 = obj->prop;
    sub_GAME_7F03E18C(temp_s1);
    phi_f20 = 0.0f;
    if (obj->flags2 & 0x20000)
    {
        temp_v0 = temp_s1->stan;
        if (temp_v0 != 0)
        {
            temp_s1->rooms[1] = (u8)-1;
            temp_s1->rooms[0] = temp_v0->RoomID;
        }
        else
        {
            temp_s1->rooms[0] = (u8)-1;
        }
    }
    else
    {
        temp_v0_2 = sub_GAME_7F040078(obj);
        temp_a0   = temp_v0_2;
        if (temp_v0_2 != 0)
        {
            temp_a1  = &obj->mtx;
            sp28     = temp_a1;
            sp30     = temp_v0_2;
            sp40     = sub_GAME_7F03E87C(temp_a0, temp_a1) - 30.0f;
            sp44     = sub_GAME_7F03E9BC(sp30, temp_a1);
            sp48     = sub_GAME_7F03EAFC(sp30, temp_a1) - 30.0f;
            sp34     = sub_GAME_7F03E91C(sp30, temp_a1) + 30.0f;
            sp38     = sub_GAME_7F03EA5C(sp30, temp_a1);
            temp_f2  = -sp40;
            temp_f12 = sub_GAME_7F03EB9C(sp30, temp_a1) + 30.0f;
            if (temp_f2 > 0.0f)
            {
                phi_f20 = temp_f2;
            }
            temp_f0   = -sp48;
            phi_f20_2 = phi_f20;
            if (phi_f20 < temp_f0)
            {
                phi_f20_2 = temp_f0;
            }
            phi_f20_3 = phi_f20_2;
            if (phi_f20_2 < sp34)
            {
                phi_f20_3 = sp34;
            }
            temp_cond = phi_f20_3 < temp_f12;
            sp3C      = temp_f12;
            phi_f20_4 = phi_f20_3;
            if (temp_cond)
            {
                sp3C      = temp_f12;
                phi_f20_4 = temp_f12;
            }
            temp_a1_2 = &sp40;
            sp40 += obj->mtx.m[0][0];
            temp_a2 = &sp34;
            sp44 += obj->mtx.m[0][1];
            sp48 += obj->mtx.m[0][2];
            sp34 += obj->mtx.m[0][0];
            sp38 += obj->mtx.m[0][1];
            sp3C += obj->mtx.m[0][2];
            sub_GAME_7F03E27C(temp_f12, temp_s1, temp_a1_2, temp_a2, phi_f20_4);
        }
    }
    sub_GAME_7F03E210(temp_s1);
}
#else
GLOBAL_ASM(
.late_rodata
/*hack for below*/
glabel jpt_8005354C
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EF4
.word .L7F056EF4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4

.text
glabel sub_GAME_7F056CA0
/* 08B7D0 7F056CA0 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 08B7D4 7F056CA4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 08B7D8 7F056CA8 AFB10020 */  sw    $s1, 0x20($sp)
/* 08B7DC 7F056CAC AFB0001C */  sw    $s0, 0x1c($sp)
/* 08B7E0 7F056CB0 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 08B7E4 7F056CB4 8C910010 */  lw    $s1, 0x10($a0)
/* 08B7E8 7F056CB8 00808025 */  move  $s0, $a0
/* 08B7EC 7F056CBC 4480A000 */  mtc1  $zero, $f20
/* 08B7F0 7F056CC0 0FC0F863 */  jal   sub_GAME_7F03E18C
/* 08B7F4 7F056CC4 02202025 */   move  $a0, $s1
/* 08B7F8 7F056CC8 8E0E000C */  lw    $t6, 0xc($s0)
/* 08B7FC 7F056CCC 000E7B80 */  sll   $t7, $t6, 0xe
/* 08B800 7F056CD0 05E1000C */  bgez  $t7, .L7F056D04
/* 08B804 7F056CD4 00000000 */   nop   
/* 08B808 7F056CD8 8E220014 */  lw    $v0, 0x14($s1)
/* 08B80C 7F056CDC 241900FF */  li    $t9, 255
/* 08B810 7F056CE0 240800FF */  li    $t0, 255
/* 08B814 7F056CE4 10400005 */  beqz  $v0, .L7F056CFC
/* 08B818 7F056CE8 00000000 */   nop   
/* 08B81C 7F056CEC 90580003 */  lbu   $t8, 3($v0)
/* 08B820 7F056CF0 A239002D */  sb    $t9, 0x2d($s1)
/* 08B824 7F056CF4 10000062 */  b     .L7F056E80
/* 08B828 7F056CF8 A238002C */   sb    $t8, 0x2c($s1)
.L7F056CFC:
/* 08B82C 7F056CFC 10000060 */  b     .L7F056E80
/* 08B830 7F056D00 A228002C */   sb    $t0, 0x2c($s1)
.L7F056D04:
/* 08B834 7F056D04 0FC1001E */  jal   sub_GAME_7F040078
/* 08B838 7F056D08 02002025 */   move  $a0, $s0
/* 08B83C 7F056D0C 1040005C */  beqz  $v0, .L7F056E80
/* 08B840 7F056D10 00402025 */   move  $a0, $v0
/* 08B844 7F056D14 26050018 */  addiu $a1, $s0, 0x18
/* 08B848 7F056D18 AFA50028 */  sw    $a1, 0x28($sp)
/* 08B84C 7F056D1C 0FC0FA1F */  jal   sub_GAME_7F03E87C
/* 08B850 7F056D20 AFA20030 */   sw    $v0, 0x30($sp)
/* 08B854 7F056D24 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 08B858 7F056D28 44812000 */  mtc1  $at, $f4
/* 08B85C 7F056D2C 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B860 7F056D30 8FA50028 */  lw    $a1, 0x28($sp)
/* 08B864 7F056D34 46040181 */  sub.s $f6, $f0, $f4
/* 08B868 7F056D38 0FC0FA6F */  jal   sub_GAME_7F03E9BC
/* 08B86C 7F056D3C E7A60040 */   swc1  $f6, 0x40($sp)
/* 08B870 7F056D40 E7A00044 */  swc1  $f0, 0x44($sp)
/* 08B874 7F056D44 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B878 7F056D48 0FC0FABF */  jal   sub_GAME_7F03EAFC
/* 08B87C 7F056D4C 8FA50028 */   lw    $a1, 0x28($sp)
/* 08B880 7F056D50 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 08B884 7F056D54 44814000 */  mtc1  $at, $f8
/* 08B888 7F056D58 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B88C 7F056D5C 8FA50028 */  lw    $a1, 0x28($sp)
/* 08B890 7F056D60 46080281 */  sub.s $f10, $f0, $f8
/* 08B894 7F056D64 0FC0FA47 */  jal   sub_GAME_7F03E91C
/* 08B898 7F056D68 E7AA0048 */   swc1  $f10, 0x48($sp)
/* 08B89C 7F056D6C 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 08B8A0 7F056D70 44818000 */  mtc1  $at, $f16
/* 08B8A4 7F056D74 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B8A8 7F056D78 8FA50028 */  lw    $a1, 0x28($sp)
/* 08B8AC 7F056D7C 46100480 */  add.s $f18, $f0, $f16
/* 08B8B0 7F056D80 0FC0FA97 */  jal   sub_GAME_7F03EA5C
/* 08B8B4 7F056D84 E7B20034 */   swc1  $f18, 0x34($sp)
/* 08B8B8 7F056D88 E7A00038 */  swc1  $f0, 0x38($sp)
/* 08B8BC 7F056D8C 8FA40030 */  lw    $a0, 0x30($sp)
/* 08B8C0 7F056D90 0FC0FAE7 */  jal   sub_GAME_7F03EB9C
/* 08B8C4 7F056D94 8FA50028 */   lw    $a1, 0x28($sp)
/* 08B8C8 7F056D98 C7A20040 */  lwc1  $f2, 0x40($sp)
/* 08B8CC 7F056D9C 44803000 */  mtc1  $zero, $f6
/* 08B8D0 7F056DA0 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 08B8D4 7F056DA4 46001087 */  neg.s $f2, $f2
/* 08B8D8 7F056DA8 44812000 */  mtc1  $at, $f4
/* 08B8DC 7F056DAC 4602303C */  c.lt.s $f6, $f2
/* 08B8E0 7F056DB0 C7A80034 */  lwc1  $f8, 0x34($sp)
/* 08B8E4 7F056DB4 46040300 */  add.s $f12, $f0, $f4
/* 08B8E8 7F056DB8 C7A00048 */  lwc1  $f0, 0x48($sp)
/* 08B8EC 7F056DBC 45020003 */  bc1fl .L7F056DCC
/* 08B8F0 7F056DC0 46000007 */   neg.s $f0, $f0
/* 08B8F4 7F056DC4 46001506 */  mov.s $f20, $f2
/* 08B8F8 7F056DC8 46000007 */  neg.s $f0, $f0
.L7F056DCC:
/* 08B8FC 7F056DCC 4600A03C */  c.lt.s $f20, $f0
/* 08B900 7F056DD0 00000000 */  nop   
/* 08B904 7F056DD4 45020003 */  bc1fl .L7F056DE4
/* 08B908 7F056DD8 4608A03C */   c.lt.s $f20, $f8
/* 08B90C 7F056DDC 46000506 */  mov.s $f20, $f0
/* 08B910 7F056DE0 4608A03C */  c.lt.s $f20, $f8
.L7F056DE4:
/* 08B914 7F056DE4 00000000 */  nop   
/* 08B918 7F056DE8 45020003 */  bc1fl .L7F056DF8
/* 08B91C 7F056DEC 460CA03C */   c.lt.s $f20, $f12
/* 08B920 7F056DF0 46004506 */  mov.s $f20, $f8
/* 08B924 7F056DF4 460CA03C */  c.lt.s $f20, $f12
.L7F056DF8:
/* 08B928 7F056DF8 E7AC003C */  swc1  $f12, 0x3c($sp)
/* 08B92C 7F056DFC 45020004 */  bc1fl .L7F056E10
/* 08B930 7F056E00 C7AA0040 */   lwc1  $f10, 0x40($sp)
/* 08B934 7F056E04 46006506 */  mov.s $f20, $f12
/* 08B938 7F056E08 E7AC003C */  swc1  $f12, 0x3c($sp)
/* 08B93C 7F056E0C C7AA0040 */  lwc1  $f10, 0x40($sp)
.L7F056E10:
/* 08B940 7F056E10 C6100058 */  lwc1  $f16, 0x58($s0)
/* 08B944 7F056E14 C7A40044 */  lwc1  $f4, 0x44($sp)
/* 08B948 7F056E18 4407A000 */  mfc1  $a3, $f20
/* 08B94C 7F056E1C 46105480 */  add.s $f18, $f10, $f16
/* 08B950 7F056E20 C7AA0048 */  lwc1  $f10, 0x48($sp)
/* 08B954 7F056E24 02202025 */  move  $a0, $s1
/* 08B958 7F056E28 27A50040 */  addiu $a1, $sp, 0x40
/* 08B95C 7F056E2C E7B20040 */  swc1  $f18, 0x40($sp)
/* 08B960 7F056E30 C606005C */  lwc1  $f6, 0x5c($s0)
/* 08B964 7F056E34 27A60034 */  addiu $a2, $sp, 0x34
/* 08B968 7F056E38 46062200 */  add.s $f8, $f4, $f6
/* 08B96C 7F056E3C C7A40034 */  lwc1  $f4, 0x34($sp)
/* 08B970 7F056E40 E7A80044 */  swc1  $f8, 0x44($sp)
/* 08B974 7F056E44 C6100060 */  lwc1  $f16, 0x60($s0)
/* 08B978 7F056E48 46105480 */  add.s $f18, $f10, $f16
/* 08B97C 7F056E4C C7AA0038 */  lwc1  $f10, 0x38($sp)
/* 08B980 7F056E50 E7B20048 */  swc1  $f18, 0x48($sp)
/* 08B984 7F056E54 C6060058 */  lwc1  $f6, 0x58($s0)
/* 08B988 7F056E58 46062200 */  add.s $f8, $f4, $f6
/* 08B98C 7F056E5C C7A4003C */  lwc1  $f4, 0x3c($sp)
/* 08B990 7F056E60 E7A80034 */  swc1  $f8, 0x34($sp)
/* 08B994 7F056E64 C610005C */  lwc1  $f16, 0x5c($s0)
/* 08B998 7F056E68 46105480 */  add.s $f18, $f10, $f16
/* 08B99C 7F056E6C E7B20038 */  swc1  $f18, 0x38($sp)
/* 08B9A0 7F056E70 C6060060 */  lwc1  $f6, 0x60($s0)
/* 08B9A4 7F056E74 46062200 */  add.s $f8, $f4, $f6
/* 08B9A8 7F056E78 0FC0F89F */  jal   sub_GAME_7F03E27C
/* 08B9AC 7F056E7C E7A8003C */   swc1  $f8, 0x3c($sp)
.L7F056E80:
/* 08B9B0 7F056E80 0FC0F884 */  jal   sub_GAME_7F03E210
/* 08B9B4 7F056E84 02202025 */   move  $a0, $s1
/* 08B9B8 7F056E88 8FBF0024 */  lw    $ra, 0x24($sp)
/* 08B9BC 7F056E8C D7B40010 */  ldc1  $f20, 0x10($sp)
/* 08B9C0 7F056E90 8FB0001C */  lw    $s0, 0x1c($sp)
/* 08B9C4 7F056E94 8FB10020 */  lw    $s1, 0x20($sp)
/* 08B9C8 7F056E98 03E00008 */  jr    $ra
/* 08B9CC 7F056E9C 27BD0050 */   addiu $sp, $sp, 0x50
)
#endif





#ifdef NONMATCHING
ObjectRecord *sub_GAME_7F056EA0(s32 arg0, s32 index)
{
    ObjectRecord *obj;

    obj = sub_GAME_7F056A88(index);
    if (obj != 0)
    {
        switch (obj->type)
        {
            case PROPDEF_DOOR_SCALE:      //2
            case PROPDEF_GUARD:           //9 :
            case PROPDEF_LINK:            //14:
            case PROPDEF_GUARD_ATTRIBUTE: //18:
            case PROPDEF_SWITCH:          //19:
            case PROPDEF_TAG:             //22:
            case PROPDEF_OBJECTIVE_START: //23
            case PROPDEF_OBJECTIVE_END:
            case PROPDEF_OBJECTIVE_DESTROY_OBJECT:
            case PROPDEF_OBJECTIVE_COMPLETE_CONDITION:
            case PROPDEF_OBJECTIVE_FAIL_CONDITION:
            case PROPDEF_OBJECTIVE_COLLECT_OBJECT:
            case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT:
            case PROPDEF_OBJECTIVE_PHOTOGRAPH:
            case PROPDEF_OBJECTIVE_NULL:
            case PROPDEF_OBJECTIVE_ENTER_ROOM:
            case PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM:
            case PROPDEF_OBJECTIVE_COPY_ITEM:
            case PROPDEF_WATCH_MENU_OBJECTIVE_TEXT: //35
            case PROPDEF_RENAME:                    //37:
            case PROPDEF_LOCK_DOOR:                 //38:
            case PROPDEF_SAFE_ITEM:                 //44:
            case PROPDEF_CAMERAPOS:                 //46:
                return NULL;
            default:
                break;
        }
    }
    return obj;
}

#else
GLOBAL_ASM(
.late_rodata
/*D:8005354C*/
/*glabel jpt_8005354C*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EDC*/
/*.word .L7F056EDC*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
/*.word .L7F056EEC*/
/*.word .L7F056EEC*/
/*.word .L7F056EE4*/
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4

/*D:80053608                     .align 4*/
.text
glabel sub_GAME_7F056EA0
/* 08B9D0 7F056EA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08B9D4 7F056EA4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08B9D8 7F056EA8 AFA40018 */  sw    $a0, 0x18($sp)
/* 08B9DC 7F056EAC 0FC15AA2 */  jal   sub_GAME_7F056A88
/* 08B9E0 7F056EB0 00A02025 */   move  $a0, $a1
/* 08B9E4 7F056EB4 1040000F */  beqz  $v0, .L7F056EF4
/* 08B9E8 7F056EB8 00401825 */   move  $v1, $v0
/* 08B9EC 7F056EBC 904E0003 */  lbu   $t6, 3($v0)
/* 08B9F0 7F056EC0 25CFFFFF */  addiu $t7, $t6, -1
/* 08B9F4 7F056EC4 2DE1002F */  sltiu $at, $t7, 0x2f
/* 08B9F8 7F056EC8 1020000A */  beqz  $at, .L7F056EF4
/* 08B9FC 7F056ECC 000F7880 */   sll   $t7, $t7, 2
/* 08BA00 7F056ED0 3C018005 */  lui   $at, %hi(jpt_8005354C)
/* 08BA04 7F056ED4 002F0821 */  addu  $at, $at, $t7
/* 08BA08 7F056ED8 8C2F354C */  lw    $t7, %lo(jpt_8005354C)($at)
.L7F056EDC:
/* 08BA0C 7F056EDC 01E00008 */  jr    $t7
/* 08BA10 7F056EE0 00000000 */   nop   
.L7F056EE4:
/* 08BA14 7F056EE4 10000004 */  b     .L7F056EF8
/* 08BA18 7F056EE8 00601025 */   move  $v0, $v1
.L7F056EEC:
/* 08BA1C 7F056EEC 10000002 */  b     .L7F056EF8
/* 08BA20 7F056EF0 00001025 */   move  $v0, $zero
def_7F056EDC:
.L7F056EF4:
/* 08BA24 7F056EF4 00601025 */  move  $v0, $v1
.L7F056EF8:
/* 08BA28 7F056EF8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08BA2C 7F056EFC 27BD0018 */  addiu $sp, $sp, 0x18
/* 08BA30 7F056F00 03E00008 */  jr    $ra
/* 08BA34 7F056F04 00000000 */   nop   
)
#endif





#ifdef NONMATCHING

PropRecord *sub_GAME_7F056F08(s32 arg0, PropRecord **arg1, PropRecord **arg2, s32 arg3, s32 arg4, s32 arg5)
{
    PropRecord *temp_s0;
    PropRecord *temp_s0_2;
    u8          temp_v1;
    u8          temp_v1_2;
    void *      temp_v0;
    u8          phi_v1;
    PropRecord *phi_s0;
    PropRecord *phi_s2;
    PropRecord *phi_s3;
    PropRecord *phi_s2_2;
    PropRecord *phi_s3_2;
    PropRecord *phi_s2_3;
    PropRecord *phi_s3_3;

    temp_s0  = g_chraiCurrentSetup.props;
    phi_s0   = temp_s0;
    phi_s2   = NULL;
    phi_s3   = NULL;
    phi_s2_2 = NULL;
    phi_s3_2 = NULL;
    if (temp_s0 != 0)
    {
        temp_v1 = temp_s0->unk3;
        phi_v1  = temp_v1;
        if (temp_v1 != 0x30)
        {
loop_3:
            phi_s2_3 = phi_s2;
            phi_s3_3 = phi_s3;
            phi_s2_3 = phi_s2;
            if ((arg0 & 0xFF) == phi_v1)
            {
                temp_v0 = phi_s0->pos.AsArray[2];
                if (temp_v0 == 0)
                {
                    if ((arg3 == 0) && (arg4 == 0))
                    {
                        return phi_s0;
                    }
                    goto block_19;
                }
                if ((arg0 != 8) && ((phi_s0->unk64 & 0x80) == 0) && ((phi_s0->unk2 & 4) == 0) && (temp_v0->unk1C == 0) && ((arg4 == 0) || (sub_GAME_7F06C060(phi_s0->stan, arg5) != 0)))
                {
                    if ((phi_s2 == 0) && ((phi_s0->pos.AsArray[2]->unk1 & 2) == 0))
                    {
                        phi_s2_3 = phi_s0;
                    }
                    if (phi_s3 == 0)
                    {
                        phi_s3_3 = phi_s0;
                    }
                }
                goto block_19;
            }
block_19:
            temp_s0_2 = (sizepropdef(phi_s0) * 4) + phi_s0;
            temp_v1_2 = temp_s0_2->unk3;
            phi_v1    = temp_v1_2;
            phi_s0    = temp_s0_2;
            phi_s2    = phi_s2_3;
            phi_s3    = phi_s3_3;
            phi_s2_2  = phi_s2_3;
            phi_s3_2  = phi_s3_3;
            if (temp_v1_2 == 0x30)
            {
                goto block_20;
            }
            goto loop_3;
        }
    }
block_20:
    *arg1 = phi_s2_2;
    *arg2 = phi_s3_2;
    return NULL;
}


#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F056F08
/* 08BA38 7F056F08 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 08BA3C 7F056F0C AFB00018 */  sw    $s0, 0x18($sp)
/* 08BA40 7F056F10 3C108007 */  lui   $s0, %hi(g_chraiCurrentSetup+0x0c)
/* 08BA44 7F056F14 8E105D0C */  lw    $s0, %lo(g_chraiCurrentSetup+0x0c)($s0)
/* 08BA48 7F056F18 AFBE0038 */  sw    $fp, 0x38($sp)
/* 08BA4C 7F056F1C AFB70034 */  sw    $s7, 0x34($sp)
/* 08BA50 7F056F20 AFB30024 */  sw    $s3, 0x24($sp)
/* 08BA54 7F056F24 AFB20020 */  sw    $s2, 0x20($sp)
/* 08BA58 7F056F28 0080B825 */  move  $s7, $a0
/* 08BA5C 7F056F2C 00E0F025 */  move  $fp, $a3
/* 08BA60 7F056F30 AFBF003C */  sw    $ra, 0x3c($sp)
/* 08BA64 7F056F34 AFB60030 */  sw    $s6, 0x30($sp)
/* 08BA68 7F056F38 AFB5002C */  sw    $s5, 0x2c($sp)
/* 08BA6C 7F056F3C AFB40028 */  sw    $s4, 0x28($sp)
/* 08BA70 7F056F40 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08BA74 7F056F44 AFA50044 */  sw    $a1, 0x44($sp)
/* 08BA78 7F056F48 AFA60048 */  sw    $a2, 0x48($sp)
/* 08BA7C 7F056F4C 00009025 */  move  $s2, $zero
/* 08BA80 7F056F50 12000039 */  beqz  $s0, .L7F057038
/* 08BA84 7F056F54 00009825 */   move  $s3, $zero
/* 08BA88 7F056F58 92030003 */  lbu   $v1, 3($s0)
/* 08BA8C 7F056F5C 24010030 */  li    $at, 48
/* 08BA90 7F056F60 309400FF */  andi  $s4, $a0, 0xff
/* 08BA94 7F056F64 10610034 */  beq   $v1, $at, .L7F057038
/* 08BA98 7F056F68 24160008 */   li    $s6, 8
/* 08BA9C 7F056F6C 8FB50054 */  lw    $s5, 0x54($sp)
/* 08BAA0 7F056F70 8FB10050 */  lw    $s1, 0x50($sp)
.L7F056F74:
/* 08BAA4 7F056F74 16830028 */  bne   $s4, $v1, .L7F057018
/* 08BAA8 7F056F78 00000000 */   nop   
/* 08BAAC 7F056F7C 8E020010 */  lw    $v0, 0x10($s0)
/* 08BAB0 7F056F80 14400007 */  bnez  $v0, .L7F056FA0
/* 08BAB4 7F056F84 00000000 */   nop   
/* 08BAB8 7F056F88 17C00023 */  bnez  $fp, .L7F057018
/* 08BABC 7F056F8C 00000000 */   nop   
/* 08BAC0 7F056F90 16200021 */  bnez  $s1, .L7F057018
/* 08BAC4 7F056F94 00000000 */   nop   
/* 08BAC8 7F056F98 1000002C */  b     .L7F05704C
/* 08BACC 7F056F9C 02001025 */   move  $v0, $s0
.L7F056FA0:
/* 08BAD0 7F056FA0 12F6001D */  beq   $s7, $s6, .L7F057018
/* 08BAD4 7F056FA4 00000000 */   nop   
/* 08BAD8 7F056FA8 8E0E0064 */  lw    $t6, 0x64($s0)
/* 08BADC 7F056FAC 31CF0080 */  andi  $t7, $t6, 0x80
/* 08BAE0 7F056FB0 15E00019 */  bnez  $t7, .L7F057018
/* 08BAE4 7F056FB4 00000000 */   nop   
/* 08BAE8 7F056FB8 92180002 */  lbu   $t8, 2($s0)
/* 08BAEC 7F056FBC 33190004 */  andi  $t9, $t8, 4
/* 08BAF0 7F056FC0 17200015 */  bnez  $t9, .L7F057018
/* 08BAF4 7F056FC4 00000000 */   nop   
/* 08BAF8 7F056FC8 8C48001C */  lw    $t0, 0x1c($v0)
/* 08BAFC 7F056FCC 15000012 */  bnez  $t0, .L7F057018
/* 08BB00 7F056FD0 00000000 */   nop   
/* 08BB04 7F056FD4 12200005 */  beqz  $s1, .L7F056FEC
/* 08BB08 7F056FD8 02A02825 */   move  $a1, $s5
/* 08BB0C 7F056FDC 0FC1B018 */  jal   sub_GAME_7F06C060
/* 08BB10 7F056FE0 8E040014 */   lw    $a0, 0x14($s0)
/* 08BB14 7F056FE4 1040000C */  beqz  $v0, .L7F057018
/* 08BB18 7F056FE8 00000000 */   nop   
.L7F056FEC:
/* 08BB1C 7F056FEC 16400007 */  bnez  $s2, .L7F05700C
/* 08BB20 7F056FF0 00000000 */   nop   
/* 08BB24 7F056FF4 8E090010 */  lw    $t1, 0x10($s0)
/* 08BB28 7F056FF8 912A0001 */  lbu   $t2, 1($t1)
/* 08BB2C 7F056FFC 314B0002 */  andi  $t3, $t2, 2
/* 08BB30 7F057000 15600002 */  bnez  $t3, .L7F05700C
/* 08BB34 7F057004 00000000 */   nop   
/* 08BB38 7F057008 02009025 */  move  $s2, $s0
.L7F05700C:
/* 08BB3C 7F05700C 16600002 */  bnez  $s3, .L7F057018
/* 08BB40 7F057010 00000000 */   nop   
/* 08BB44 7F057014 02009825 */  move  $s3, $s0
.L7F057018:
/* 08BB48 7F057018 0FC15A3D */  jal   sizepropdef
/* 08BB4C 7F05701C 02002025 */   move  $a0, $s0
/* 08BB50 7F057020 00026080 */  sll   $t4, $v0, 2
/* 08BB54 7F057024 01908021 */  addu  $s0, $t4, $s0
/* 08BB58 7F057028 92030003 */  lbu   $v1, 3($s0)
/* 08BB5C 7F05702C 24010030 */  li    $at, 48
/* 08BB60 7F057030 1461FFD0 */  bne   $v1, $at, .L7F056F74
/* 08BB64 7F057034 00000000 */   nop   
.L7F057038:
/* 08BB68 7F057038 8FAD0044 */  lw    $t5, 0x44($sp)
/* 08BB6C 7F05703C 00001025 */  move  $v0, $zero
/* 08BB70 7F057040 ADB20000 */  sw    $s2, ($t5)
/* 08BB74 7F057044 8FAE0048 */  lw    $t6, 0x48($sp)
/* 08BB78 7F057048 ADD30000 */  sw    $s3, ($t6)
.L7F05704C:
/* 08BB7C 7F05704C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 08BB80 7F057050 8FB00018 */  lw    $s0, 0x18($sp)
/* 08BB84 7F057054 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08BB88 7F057058 8FB20020 */  lw    $s2, 0x20($sp)
/* 08BB8C 7F05705C 8FB30024 */  lw    $s3, 0x24($sp)
/* 08BB90 7F057060 8FB40028 */  lw    $s4, 0x28($sp)
/* 08BB94 7F057064 8FB5002C */  lw    $s5, 0x2c($sp)
/* 08BB98 7F057068 8FB60030 */  lw    $s6, 0x30($sp)
/* 08BB9C 7F05706C 8FB70034 */  lw    $s7, 0x34($sp)
/* 08BBA0 7F057070 8FBE0038 */  lw    $fp, 0x38($sp)
/* 08BBA4 7F057074 03E00008 */  jr    $ra
/* 08BBA8 7F057078 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif



