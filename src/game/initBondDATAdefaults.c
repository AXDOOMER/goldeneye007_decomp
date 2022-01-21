#include <ultra64.h>
#include <math.h>
#include <bondtypes.h>
#include "chr.h"
#include "chrobjdata.h"
#include "initanitable.h"
#include "initBondDATAdefaults.h"
#include "objecthandler.h"
#include "player.h"
#include "unk_08DBB0.h"


//data
struct unk_joint_list D_8002A790 = {NULL, 1, 3, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, 0};

// forward declarations

void sub_GAME_7F0062C0(void *anim, s32 arg1, s32 arg2, s32 *arg3);

// end forward declarations





/**
 * @param anim:
 * @param arg1:
 * @param arg2:
 * @param arg3: unknown type.
 * 
 * Address 0x7F0062C0.
*/
void sub_GAME_7F0062C0(void *anim, s32 arg1, s32 arg2, s32 *arg3)
{
    // todo: is this a struct? see: sub_GAME_7F06D2E4
    s16 sp40[6];

    arg3[0] = 0;
    arg3[1] = 0;
    arg3[2] = 0;

    for (; arg1<arg2; arg1++)
    {
        sub_GAME_7F06D2E4(0, 0, &skeleton_guard, anim, arg1, &sp40[2]);
        arg3[0] += sp40[2];
        arg3[1] += sp40[3];
        arg3[2] += sp40[4];
    }
}






void sets_a_bunch_of_BONDdata_values_to_default(void)
{
    s32 i;
    s32 spD0[3];
    struct unk_joint_list sp90;
    Mtxf sp50;

#ifndef VERSION_EU
    if ((s32) player_gait_object_header.numRecords >= 0x1F)
    {
        return_null();
    }
#endif

    sub_GAME_7F075FAC(&g_CurrentPlayer->field_598, &player_gait_object_header, &g_CurrentPlayer->field_654);
    set_obj_instance_controller_scale(&g_CurrentPlayer->field_598, IDO_POINT_ONE);

#ifdef VERSION_JP
    sub_GAME_7F06FF18(&g_CurrentPlayer->field_598, 1.0f, 0.0f);
#endif
#ifdef VERSION_EU
    sub_GAME_7F06FF18(&g_CurrentPlayer->field_598, 1.2f, 0.0f);
#endif

    g_CurrentPlayer->field_4E8 = 0;

#ifdef VERSION_EU
    g_CurrentPlayer->headdamp = 0.9166f;
#else
    g_CurrentPlayer->headdamp = 0.93f;
#endif

    g_CurrentPlayer->field_4F0 = 0;
    g_CurrentPlayer->field_4F4 = 1.0f;
    g_CurrentPlayer->field_4F8 = 1.0f;
    g_CurrentPlayer->headpos[0] = 0.0f;
    g_CurrentPlayer->headpos[1] = 0.0f;
    g_CurrentPlayer->headpos[2] = 0.0f;
    g_CurrentPlayer->headlook[0] = 0.0f;
    g_CurrentPlayer->headlook[1] = 0.0f;
    g_CurrentPlayer->headlook[2] = 0.0f;
    g_CurrentPlayer->headup[0] = 0.0f;
    g_CurrentPlayer->headup[1] = 0.0f;
    g_CurrentPlayer->headup[2] = 0.0f;
    g_CurrentPlayer->headpossum[0] = 0.0f;
    g_CurrentPlayer->headpossum[1] = 0.0f;
    g_CurrentPlayer->headpossum[2] = 0.0f;
    g_CurrentPlayer->headlooksum[0] = 0.0f;
    g_CurrentPlayer->headlooksum[1] = 0.0f;

#ifdef VERSION_EU
    g_CurrentPlayer->headlooksum[2] = 11.990406f; /* NTSC->PAL conversion rate: 5/6 */
#else
    g_CurrentPlayer->headlooksum[2] = 14.285716f;
#endif

    g_CurrentPlayer->headupsum[0] = 0.0f;

#ifdef VERSION_EU
    g_CurrentPlayer->headupsum[1] = 11.990406f; /* NTSC->PAL conversion rate: 5/6 */
#else
    g_CurrentPlayer->headupsum[1] = 14.285716f;
#endif

    g_CurrentPlayer->headupsum[2] = 0.0f;
    g_CurrentPlayer->resetheadpos = 1;
    g_CurrentPlayer->resetheadrot = 1;
    g_CurrentPlayer->field_4E4 = 1;
    g_CurrentPlayer->field_544[0] = 0.0f;
    g_CurrentPlayer->field_544[1] = 0.0f;
    g_CurrentPlayer->field_544[2] = 0.0f;
    g_CurrentPlayer->stationary_ground_offset = 0.0f;
    g_CurrentPlayer->field_554 = 0.0f;
    g_CurrentPlayer->field_558 = 0.0f;
    g_CurrentPlayer->field_55C = 0.0f;
    g_CurrentPlayer->field_560 = 0.0f;
    g_CurrentPlayer->standlook[0][0] = 0.0f;
    g_CurrentPlayer->standlook[0][1] = 0.0f;
    g_CurrentPlayer->standlook[0][2] = 1.0f;
    g_CurrentPlayer->standlook[1][0] = 0.0f;
    g_CurrentPlayer->standlook[1][1] = 0.0f;
    g_CurrentPlayer->standlook[1][2] = 1.0f;
    g_CurrentPlayer->standup[0][0] = 0.0f;
    g_CurrentPlayer->standup[0][1] = 1.0f;
    g_CurrentPlayer->standup[0][2] = 0.0f;
    g_CurrentPlayer->standup[1][0] = 0.0f;
    g_CurrentPlayer->standup[1][1] = 1.0f;
    g_CurrentPlayer->standup[1][2] = 0.0f;
    g_CurrentPlayer->standcnt = 0;

    for (i=0; i<2; i++)
    {
        sub_GAME_7F0062C0(
            // match hack: addu address calculated backwards
            (void*)((s32)g_BondMoveAnimationSetup[i].anim_id + (s32)&ptr_animation_table->data),
            (s32)g_BondMoveAnimationSetup[i].unk04,
            (s32)g_BondMoveAnimationSetup[i].unk08,
            &spD0);

        g_BondMoveAnimationSetup[i].unk0C = (f32) (((f32) spD0[2] * IDO_POINT_ONE) / (g_BondMoveAnimationSetup[i].unk08 - g_BondMoveAnimationSetup[i].unk04));
    }

    sp90 = D_8002A790;

    objecthandlerAnimationRelated7F06FCA8(&g_CurrentPlayer->field_598, (struct ModelAnimation *)&ptr_animation_table->data[(s32)&ANIM_DATA_idle], 0, 0.0f, 0.5f, 0.0f);

    subcalcpos(&g_CurrentPlayer->field_598);
    matrix_4x4_set_identity(&sp50);

    sp90.unk_matrix = &sp50;
    sp90.mtxlist = &g_CurrentPlayer->field_6D0;

    subcalcmatrices(&sp90, &g_CurrentPlayer->field_598);

    g_CurrentPlayer->stationary_ground_offset = g_CurrentPlayer->field_704;
    g_CurrentPlayer->field_554 = 0.0f;
    g_CurrentPlayer->field_558 = g_CurrentPlayer->field_744 - g_CurrentPlayer->field_704;
    g_CurrentPlayer->field_55C = g_CurrentPlayer->field_748 - g_CurrentPlayer->field_708;

    objecthandlerAnimationRelated7F06FCA8(
        &g_CurrentPlayer->field_598,
        // match hack: addu address calculated backwards
        (struct ModelAnimation *) ((s32)g_BondMoveAnimationSetup[g_CurrentPlayer->field_4E8].anim_id + (s32)&ptr_animation_table->data),
        0,
        g_BondMoveAnimationSetup[g_CurrentPlayer->field_4E8].unk04,
        0.5f,
        0.0f);

    sub_GAME_7F06FDCC(&g_CurrentPlayer->field_598, g_BondMoveAnimationSetup[g_CurrentPlayer->field_4E8].unk04, 0.0f);
    sub_GAME_7F06FDE8(&g_CurrentPlayer->field_598, g_BondMoveAnimationSetup[g_CurrentPlayer->field_4E8].unk08);
    sub_GAME_7F06FE3C(&g_CurrentPlayer->field_598, currentPlayerToggle5BC);

    currentPlayerUpdateIdleHeadRoll();
}
