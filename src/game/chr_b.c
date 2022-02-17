#include <ultra64.h>
#include <bondtypes.h>
#include "cheat_buttons.h"
#include "chr.h"
#include "chr_b.h"
#include "chrobjdata.h"
#include "objecthandler.h"

s32 load_body_head_if_not_loaded(s32 model)
{
    if (c_item_entries[model].header->RootNode == 0)
    {
        load_object_into_memory(c_item_entries[model].header, c_item_entries[model].filename);
        return 1;
    }
    return 0;
}


/**
 * Address 0x7F0232E8 (VERSION_US)
 * Address 0x7F0235D8 (other version)
*/
struct Model *makeonebody(s32 arg0, s32 arg1, struct ModelFileHeader *arg2, struct ModelFileHeader *arg3, s32 arg4, struct Model *arg5)
{
    f32 sp34;
    f32 sp30;
    s32 sp2C;
    struct ModelNode_HeaderRecord *temp_a1;

    sp34 = c_item_entries[arg0].scale * 0.10000001f;
    sp2C = 0;
    sp30 = c_item_entries[arg0].pov;

    if (
#ifndef VERSION_US
    (cheatIsActive(CHEAT_DK_MODE) != 0) && (not_in_us_7F0209EC(arg0, arg1) != 0)
#else
    cheatIsActive(CHEAT_DK_MODE)
#endif
    )
    {
        sp34 *= 0.8f;
    }

    if (arg2->RootNode == 0)
    {
        load_object_into_memory(arg2, c_item_entries[arg0].filename);
    }

    set_objuse_flag_compute_grp_nums_set_obj_loaded(arg2);

    if ((c_item_entries[arg0].hasHead == 0) && (arg1 >= 0))
    {
        sp2C = &arg2->Switches[4]->Opcode;
        if (sp2C != 0)
        {
            if (arg3->RootNode == 0)
            {
                load_object_into_memory(arg3, c_item_entries[arg1].filename);
#ifdef XBLADEBUG
    #error fix XBLADEBUG
      //sprintf("makeonebody: no head attachment for body number %d!\n",lVar3);
#endif
            }

            set_objuse_flag_compute_grp_nums_set_obj_loaded(arg3);

            arg2->numRecords += arg3->numRecords;
        }
    }

    if (arg5 == 0)
    {
        arg5 = get_aircraft_obj_instance_controller(arg2);
    }

#ifdef XBLADEBUG
    #error fix XBLADEBUG
  //
  //        if (*&pMStack0000003c->field_0x2 < pMStack00000024->numRecords) {
  //        assertPrint_8291E690
  //                  (".\\ported\\chrlv.cpp",0xc4,
  //                   "Assertion failed: chrsub->inst.savesize>=bodyobj->savesize");
  //        }
  //
  //
#endif

    if (arg5 != 0)
    {
        set_obj_instance_controller_scale(arg5, sp34);
        sub_GAME_7F06CE84(arg5, sp30);

        if ((arg3 != 0) && (c_item_entries[arg0].hasHead == 0))
        {
            arg2->numRecords -= arg3->numRecords;
            sub_GAME_7F06C3B4(arg5, sp2C, arg3);

            if ((arg4 == 0) && ((s32) arg3->numSwitches > 0))
            {
                if (arg3->Switches[0] != 0)
                {
                    temp_a1 = extract_id_from_object_structure_microcode(arg5, arg3->Switches[0]);
                    temp_a1->ModelType = 0;
                }
            }
        }
    }

    return arg5;
}

//sub_GAME_7F0234A8
Model *setup_chr_instance(int body,int head,ModelFileHeader *body_header, ModelFileHeader *head_header,int sunglasses)
{
  return makeonebody(body,head,body_header,head_header,sunglasses,0x0);
}
