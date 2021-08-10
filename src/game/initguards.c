#include "ultra64.h"
#include "memp.h"
#include "game/chr.h"
#include "game/chrobjdata.h"

void init_guards(void) {
    animation_rate = 1.0f;
    D_8002C904 = 0;
    D_8002C908 = 0;
    D_8002C90C = 0;
    D_8002C910 = 0;
    D_8002CC58 = 0;
    show_patrols_flag = 0;
    player1_guardID = 0x1388;
    ptr_guard_data = 0;
    num_guards = 0;
    init_obj_register_difficulty_vals();
}


void alloc_init_GUARDdata_entries(s32 count)
{
    s32 i;
    
    num_guards = count + 0xA;
    ptr_guard_data = mempAllocBytesInBank((((num_guards * 0x1DC) + 0xF) | 0xF) ^ 0xF, 4);
    for(i = 0; num_guards > i; i++)
    {
        ptr_guard_data[i].model = 0;
    }
}



void set_new_rand_head_bodies(u32 stagenum)
{
    s32 i;
  
    for (i=0; c_item_entries[i].header!=0; i++)
    {
        c_item_entries[i].header->RootNode = (ModelNode*)0;
    }

    current_random_male_head = randomGetNext() % num_male_heads;
    current_random_female_head = randomGetNext() % num_female_heads;
    current_random_body = randomGetNext() % num_bodies;
}
