#include <ultra64.h>
#include "lightfixture.h"
#include "bg.h"
#include "unk_0A1DA0.h"
#include <bondconstants.h>
#include <assets/image_externs.h>
#include <PR/gbi.h>

#define LIGHTFIXTURE_TABLE_MAX 0x64
#define BSS_80082B18_MAX 0x200

// bss
//CODE.bss:80082660
s_lightfixture light_fixture_table[LIGHTFIXTURE_TABLE_MAX];
//CODE.bss:80082B10
s16 cur_entry_lightfixture_table;
//CODE.bss:80082B12
s16 index_of_cur_entry_lightfixture_table;
//CODE.bss:80082B14                     .align 3
//CODE.bss:80082B18
struct bondstruct_unk_80082B18 word_CODE_bss_80082B18[BSS_80082B18_MAX];
//CODE.bss:80083318
s32 dword_CODE_bss_80083318;

// data
//D:80046030
s32 D_80046030 = 0; 

s32 D_80046034[] = {0, 0, 0, 0, 0, 0, 0};


void init_lightfixture_tables(void)
{
    s32 i;

    for (i = 0; i < LIGHTFIXTURE_TABLE_MAX; i++)
    {
        light_fixture_table[i].index = 0;
    }

    for (i = 0; i < BSS_80082B18_MAX; i++)
    {
        word_CODE_bss_80082B18[i].unk00 = 0;
    }

    D_80046030 = 0;
}


s32 get_index_of_current_entry_in_init_lightfixture_table(void)
{
    s32 i;

    for (i = 0; i != LIGHTFIXTURE_TABLE_MAX; i++)
    {
        if (light_fixture_table[i].index == 0)
        {
            return i;
        }
    }
    return LIGHTFIXTURE_TABLE_MAX;
}


void add_entry_to_init_lightfixture_table(Gfx *DL)
{
  cur_entry_lightfixture_table = get_index_of_current_entry_in_init_lightfixture_table();
  if (cur_entry_lightfixture_table != 100) {
    light_fixture_table[cur_entry_lightfixture_table].index = index_of_cur_entry_lightfixture_table;
    light_fixture_table[cur_entry_lightfixture_table].ptr_start_pertinent_DL = DL;
  }
}


void save_ptrDL_enpoint_to_current_init_lightfixture_table(Gfx *param_1)
{
  if (cur_entry_lightfixture_table != 100) {
    light_fixture_table[cur_entry_lightfixture_table].ptr_end_pertinent_DL = param_1;
  }
}


s32 check_if_imageID_is_light(s32 imageID)
{
    if ((imageID == IMAGE_WALL_LAMP)     ||
        (imageID == IMAGE_203_LIGHT)     ||
        (imageID == IMAGE_205_LIGHT)     ||
        (imageID == IMAGE_252_LIGHT)     ||
        (imageID == IMAGE_PANEL_LAMP)    ||
        (imageID == IMAGE_255_LIGHT)     ||
        (imageID == IMAGE_256_LIGHT)     ||
        (imageID == IMAGE_HANGING_LAMP)  ||
        (imageID == IMAGE_NEON_LAMP)     ||
        (imageID == IMAGE_LINEAR_LAMP))
    {
        // Will darken when shot
        return 1;
    } 
    else
    {
        return 0;
    }
}


Vtx * return_ptr_vertex_of_entry_room(Gfx * gfx, s32 arg1)
{
    Vtx * ret;

    while (gfx->dma.cmd != G_VTX ){ gfx--; }

    ret = gfx->dma.addr;

    // weird memory checking, not sure what's going on here
    if (((s32) ret & 0xFF000000) == 0x0E000000) {
        ret = (s32)array_room_info[arg1].ptr_point_index + ((s32) ret & 0xFFFFFF);
    }

    return ret;
}


void sub_GAME_7F0BB6F4(Gfx* gfx, u32 type, s32* idx1, s32* idx2, s32* idx3)
{
    switch (type) {
        case 0:
            *idx1 = (s32) gfx->tri.tri.v[0] / 10;
            *idx2 = (s32) gfx->tri.tri.v[1] / 10;
            *idx3 = (s32) gfx->tri.tri.v[2] / 10;
            break;
        // unsure of how to cleanly access the below versions
        case 1:
            *idx1 = ((u32*)gfx)[1] & 0xF;
            *idx2 = ((((u8*)gfx)[7]) & 0xFFFFFFFFu) >> 4;
            *idx3 = ((s32*)gfx)[0] & 0xF;
            break;
        case 2:
            *idx1 = ((u8*)gfx)[6] & 0xF;
            *idx2 = ((((u16*)gfx)[3]) & 0xFFFFFFFFu) >> 0xC;
            *idx3 = ((((u8*)gfx)[3]) & 0xFFFFFFFFu) >> 4;
            break;
        case 3:
            *idx1 = ((u16*)gfx)[2] & 0xF;
            *idx2 = ((((u8*)gfx)[5]) & 0xFFFFFFFFu) >> 4;
            *idx3 = ((u8*)gfx)[2] & 0xF;
            break;
        case 4:
            *idx1 = ((u8*)gfx)[4] & 0xF;
            *idx2 = ((u32*)gfx)[1] >> 0x1C;
            *idx3 = ((((u16*)gfx)[1]) & 0xFFFFFFFFu) >> 0xC;
            break;
    }
}


void sub_GAME_7F0BB874(Gfx * gfx, u32 arg1, s32 arg2, coord16 * out1, coord16 * out2, coord16 * out3)
{
    s32 idx1;
    s32 idx2;
    s32 idx3;
    Vtx * vertices;

    sub_GAME_7F0BB6F4(gfx, arg1, &idx1, &idx2, &idx3);
    vertices = return_ptr_vertex_of_entry_room(gfx, arg2);

    out1->AsArray[0] = (s16) vertices[idx1].v.ob[0];
    out1->AsArray[1] = (s16) vertices[idx1].v.ob[1];
    out1->AsArray[2] = (s16) vertices[idx1].v.ob[2];

    out2->AsArray[0] = (s16) vertices[idx2].v.ob[0];
    out2->AsArray[1] = (s16) vertices[idx2].v.ob[1];
    out2->AsArray[2] = (s16) vertices[idx2].v.ob[2];

    out3->AsArray[0] = (s16) vertices[idx3].v.ob[0];
    out3->AsArray[1] = (s16) vertices[idx3].v.ob[1];
    out3->AsArray[2] = (s16) vertices[idx3].v.ob[2];
}


void sub_GAME_7F0BB978(s32 arg0)
{
    Vtx * vertices;
    s32 i;
    struct bondstruct_unk_80082B18* unk;


    vertices = array_room_info[arg0].ptr_point_index;

    for (i = 0; i < BSS_80082B18_MAX; i++)
    {
        unk = &word_CODE_bss_80082B18[i];

        if (arg0 != unk->unk00) { continue; }

        vertices[unk->unk02].v.cn[0] >>= 2;
        vertices[unk->unk02].v.cn[1] >>= 2;
        vertices[unk->unk02].v.cn[2] >>= 2;
        vertices[unk->unk02].v.cn[3] >>= 2;
    }
}


void sub_GAME_7F0BBA20(Vtx * vertices, s32 arg1)
{
    s32 room_index;

    if (sub_GAME_7F0BBADC(vertices, arg1) != 0) { return; }

    // weird memory stuff going on here
    room_index = ((u32)vertices - (u32)array_room_info[arg1].ptr_point_index) >> 4;

    word_CODE_bss_80082B18[D_80046030].unk00 = (u16) arg1;
    word_CODE_bss_80082B18[D_80046030].unk02 = room_index;

    vertices->v.cn[0] >>= 2;
    vertices->v.cn[1] >>= 2;
    vertices->v.cn[2] >>= 2;
    vertices->v.cn[3] >>= 2;

    D_80046030++;

    if (D_80046030 >= 0x200)
    {
        D_80046030 = 0;
    }
}


s32 sub_GAME_7F0BBADC(Vtx * vertices, s32 arg1)
{
    u32 value;
    s32 i;

    // weird memory stuff going on here
    value = ((u32)vertices - (u32)array_room_info[arg1].ptr_point_index) >> 4;

    for (i = 0; i < BSS_80082B18_MAX; i++)
    {
        if ((arg1 == word_CODE_bss_80082B18[i].unk00) && ((s32)value == word_CODE_bss_80082B18[i].unk02))
        {
            return 1;
        }
    }

    return 0;
}


void sub_GAME_7F0BBBA8(Gfx *gfx, u32 arg1, s32 arg2)
{
    Vtx * vertices_2;
    s32 idx1;
    s32 idx2;
    s32 idx3;
    Vtx * vertices;

    sub_GAME_7F0BB6F4(gfx, arg1, &idx1, &idx2, &idx3);
    vertices = return_ptr_vertex_of_entry_room(gfx, arg2);

    sub_GAME_7F0BBA20(&vertices[idx1], arg2);
    sub_GAME_7F0BBA20(&vertices[idx2], arg2);

    vertices_2 = &vertices[idx3];
    sub_GAME_7F0BBA20(vertices_2, arg2);
}


s32 sub_GAME_7F0BBC30(Gfx * gfx, u32 arg1, s32 arg2)
{
    s32 out3;
    s32 idx1;
    s32 idx2;
    s32 idx3;
    Vtx * vertices;
    s32 out2;
    s32 out1;

    sub_GAME_7F0BB6F4(gfx, arg1, &idx1, &idx2, &idx3);
    vertices = return_ptr_vertex_of_entry_room(gfx, arg2);
    out1 = sub_GAME_7F0BBADC(&vertices[idx2], arg2);
    out2 = sub_GAME_7F0BBADC(&vertices[idx1], arg2);
    out3 = sub_GAME_7F0BBADC(&vertices[idx3], arg2);
    return out3 + out2 + out1;
}


s32 sub_GAME_7F0BBCCC(coord16 * coord, s32 arg1)
{
    s32 var_s0;
    s32 var_s1;
    s32 i;
    s32 var_s2;
    Vtx * vertices;

    i = 0;
    do
    {
        if (arg1 == word_CODE_bss_80082B18[i].unk00)
        {
            vertices = &array_room_info[arg1].ptr_point_index[word_CODE_bss_80082B18[i].unk02];

            var_s0 = vertices->v.ob[0] - coord->AsArray[0];
            var_s1 = vertices->v.ob[1] - coord->AsArray[1];
            var_s2 = vertices->v.ob[2] - coord->AsArray[2];

            if (var_s0 < 0) { var_s0 = -var_s0; }
            if (var_s1 < 0) { var_s1 = -var_s1; }
            if (var_s2 < 0) { var_s2 = -var_s2; }

            if ((var_s0 + var_s1 + var_s2) < (s32) (get_room_data_float1() * 100.0f))
            {
                return 1;
            }
        }
    } while (++i < BSS_80082B18_MAX);

    return 0;
}


void sub_GAME_7F0BBE0C(Gfx * gfx, u32 arg1, s32 arg2)
{
    s16 diff_z_12;
    coord16 coord1;
    coord16 coord2;
    coord16 coord3;
    coord16 coord4;
    coord16 coord5;
    coord16 coord6;
    s16 diff_x_13;
    s16 diff_x_12;
    Gfx *gfx2;
    f32 dist_tween;
    s32 j;
    s8 exec;
    s8 exec2;
    s16 diff_y_13;
    s16 diff_y_12;
    s16 diff_x_23;
    s16 diff_z_13;
    f32 inv_dist_12;
    f32 inv_dist_23;
    f32 inv_dist_13;
    coord3d origin;
    coord3d calc_coord;
    s32 i;
    s16 diff_z_23;
    f32 dist_nn;
    s16 diff_y_23;

    for (i = 0; i < LIGHTFIXTURE_TABLE_MAX; i++)
    {
        if (arg2 != light_fixture_table[i].index) { continue; }

        if (gfx < light_fixture_table[i].ptr_start_pertinent_DL) { continue; }
        if (gfx >= light_fixture_table[i].ptr_end_pertinent_DL) { continue; }

        if (sub_GAME_7F0BBC30(gfx, arg1, light_fixture_table[i].index) != 0) { return; }

        sub_GAME_7F0BBBA8(gfx, arg1, light_fixture_table[i].index);
        sub_GAME_7F0BB874(gfx, arg1, light_fixture_table[i].index, &coord1, &coord2, &coord3);

		diff_x_12 = coord1.AsArray[0] - coord2.AsArray[0];
		diff_x_23 = coord1.AsArray[0] - coord3.AsArray[0];
		diff_x_13 = coord2.AsArray[0] - coord3.AsArray[0];

		diff_y_12 = coord1.AsArray[1] - coord2.AsArray[1];
		diff_y_23 = coord1.AsArray[1] - coord3.AsArray[1];
		diff_y_13 = coord2.AsArray[1] - coord3.AsArray[1];

		diff_z_12 = coord1.AsArray[2] - coord2.AsArray[2];
		diff_z_23 = coord1.AsArray[2] - coord3.AsArray[2];
		diff_z_13 = coord2.AsArray[2] - coord3.AsArray[2];

        dist_nn = sqrtf((diff_x_12 * diff_x_12) + (diff_y_12 * diff_y_12) + (diff_z_12 * diff_z_12));
        inv_dist_12 = 10.0f / (get_room_data_float2() * dist_nn);

        dist_nn = sqrtf((diff_x_23 * diff_x_23) + (diff_y_23 * diff_y_23) + (diff_z_23 * diff_z_23));
        inv_dist_23 = 10.0f / (get_room_data_float2() * dist_nn);

        dist_nn = sqrtf((diff_x_13 * diff_x_13) + (diff_y_13 * diff_y_13) + (diff_z_13 * diff_z_13));
        inv_dist_13 = 10.0f / (get_room_data_float2() * dist_nn);

        sub_GAME_7F0BCA34(light_fixture_table[i].index, &origin);

        for (dist_tween = 0.0f; dist_tween < 1.0f; dist_tween += inv_dist_12)
        {
            calc_coord.x = ((coord2.AsArray[0] + (diff_x_12 * dist_tween)) * get_room_data_float2()) + origin.f[0];
            calc_coord.y = ((coord2.AsArray[1] + (diff_y_12 * dist_tween)) * get_room_data_float2()) + origin.f[1];
            calc_coord.z = ((coord2.AsArray[2] + (diff_z_12 * dist_tween)) * get_room_data_float2()) + origin.f[2];
            sub_GAME_7F0A2160(&calc_coord, 0.0f, 10.0f);
        }

        for (dist_tween = 0.0f; dist_tween < 1.0f; dist_tween += inv_dist_23)
        {
            calc_coord.x = ((coord3.AsArray[0] + (diff_x_23 * dist_tween)) * get_room_data_float2()) + origin.f[0];
            calc_coord.y = ((coord3.AsArray[1] + (diff_y_23 * dist_tween)) * get_room_data_float2()) + origin.f[1];
            calc_coord.z = ((coord3.AsArray[2] + (diff_z_23 * dist_tween)) * get_room_data_float2()) + origin.f[2];
            sub_GAME_7F0A2160(&calc_coord, 0.0f, 10.0f);
        }

        for (dist_tween = 0.0f; dist_tween < 1.0f; dist_tween += inv_dist_13)
        {
            calc_coord.x = ((coord3.AsArray[0] + (diff_x_13 * dist_tween)) * get_room_data_float2()) + origin.f[0];
            calc_coord.y = ((coord3.AsArray[1] + (diff_y_13 * dist_tween)) * get_room_data_float2()) + origin.f[1];
            calc_coord.z = ((coord3.AsArray[2] + (diff_z_13 * dist_tween)) * get_room_data_float2()) + origin.f[2];
            sub_GAME_7F0A2160(&calc_coord, 0.0f, 10.0f);
        }

        for (gfx2 = light_fixture_table[i].ptr_start_pertinent_DL; gfx2 < light_fixture_table[i].ptr_end_pertinent_DL; gfx2++)
        {
            if (gfx2->dma.cmd == G_TRI1)
            {
                exec = 0;

                sub_GAME_7F0BB874(gfx2, 0U, light_fixture_table[i].index, &coord4, &coord5, &coord6);

                if (sub_GAME_7F0BBCCC(&coord4, light_fixture_table[i].index) != 0)
                {
                    exec = 1;
                }
                else if (sub_GAME_7F0BBCCC(&coord5, light_fixture_table[i].index) != 0)
                {
                    exec = 1;
                }
                else if (sub_GAME_7F0BBCCC(&coord6, light_fixture_table[i].index) != 0)
                {
                    exec = 1;
                }

                if (exec != 0)
                {
                    sub_GAME_7F0BBBA8(gfx2, 0U, light_fixture_table[i].index);
                }
            }
            else if (gfx2->dma.cmd == -0x4f /* G_TRI2 ? */)
            {
                for (j = 0; j < 4; j++)
                {
                    exec2 = 0;

                    sub_GAME_7F0BB874(gfx2, j + 1, light_fixture_table[i].index, &coord4, &coord5, &coord6);

                    if (sub_GAME_7F0BBCCC(&coord4, light_fixture_table[i].index) != 0)
                    {
                        exec2 = 1;
                    }
                    else if (sub_GAME_7F0BBCCC(&coord5, light_fixture_table[i].index) != 0)
                    {
                        exec2 = 1;
                    }
                    else if (sub_GAME_7F0BBCCC(&coord6, light_fixture_table[i].index) != 0)
                    {
                        exec2 = 1;
                    }

                    if (exec2 != 0)
                    {
                        sub_GAME_7F0BBBA8(gfx2, j + 1, light_fixture_table[i].index);
                    }
                }
            }
        }
        return;
    }
}


void sub_GAME_7F0BC4C4(s32 arg0)
{
    s32 i;
    for (i = 0; i < LIGHTFIXTURE_TABLE_MAX; i++)
    {
        if (arg0 == light_fixture_table[i].index)
        {
            light_fixture_table[i].index = 0;
        }
    }
    index_of_cur_entry_lightfixture_table = arg0;
}

