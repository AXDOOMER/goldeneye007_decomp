#include <ultra64.h>
#include "padhalllv.h"
#include "bondtypes.h"
#include "chrai.h"
#include "random.h"

//pd decomp has a filesplit here
//all ge versions align properly 


waypoint *sub_GAME_7F08EBD0(coord3d *pos, s32 arg1)
{
    waypoint *head;
    PadRecord *pad;
    f32 sqrdist;
    f32 compare;
    waypoint *node;
    waypoint *ret;

    head = g_CurrentSetup.pathwaypoints;
    ret = NULL;

    if (head)
    {
        node = head;
        compare = -1.0f;
        while (node->padID >= 0)
        {
            pad = &g_CurrentSetup.pads[node->padID];
            sqrdist = ((pos->z - pad->pos.z) * (pos->z - pad->pos.z))
                    + ((pos->x - pad->pos.x) * (pos->x - pad->pos.x));

            if ((compare < 0.0f) || (sqrdist < compare))
            {
                compare = sqrdist;
                ret = node;
            }

            node++;
        }
    }

    return ret;
}


waypoint* sub_GAME_7F08EC8C(coord3d* pos, s32 arg1, waypoint* arg2)
{
    PadRecord* pad;
    f32 sqrdist2;
    f32 sqrdist;
    s32* neighbor;
    waypoint* node;
    waypoint* ret;
    waypoint* waypoints;

    neighbor = arg2->neighbours;
    ret = arg2;

    if (neighbor != NULL)
    {
        pad = &g_CurrentSetup.pads[arg2->padID];
        sqrdist = ((pos->z - pad->pos.z) * (pos->z - pad->pos.z))
                + ((pos->x - pad->pos.x) * (pos->x - pad->pos.x));
        waypoints = g_CurrentSetup.pathwaypoints;

        while (*neighbor >= 0)
        {
            node = &waypoints[*neighbor];
            pad = &g_CurrentSetup.pads[node->padID];
            sqrdist2 = ((pos->z - pad->pos.z) * (pos->z - pad->pos.z))
                     + ((pos->x - pad->pos.x) * (pos->x - pad->pos.x));

            if (sqrdist2 < sqrdist)
            {
                sqrdist = sqrdist2;
                ret = node;
            }
            neighbor++;
        }
    }
    return ret;
}


waygroup *sub_GAME_7F08ED60(s32 *groupnums, s32 value)
{
    waygroup *groups = g_CurrentSetup.waypointgroups;

    while (*groupnums >= 0)
    {
        waygroup *group = &groups[*groupnums];

        if (group->dist == value)
        {
            return group;
        }
        *groupnums++;
    }

    return NULL;
}


/**
 * For each group number in the given list assign value to their
 * dist if their dist has no value (ie. is negative).
 */
void sub_GAME_7F08EDB4(s32 *groupnums, s32 value)
{
    waygroup *groups = g_CurrentSetup.waypointgroups;

    while (*groupnums >= 0)
    {
        waygroup *group = &groups[*groupnums];

        if (group->dist < 0)
        {
            group->dist = value;
        }

        groupnums++;
    }
}


/**
 * Iterate the given groups and find any with an dist matching arg1.
 * For all groups that match, iterate their neighbouring groups and set their
 * dist to arg1 + 1, but only if their they have no existing dist value.
 *
 * Return true if any matched.
 */
bool sub_GAME_7F08EE00(struct waygroup *group, s32 arg1)
{
    bool result = FALSE;

    while (group->neighbours)
    {
        if (group->dist == arg1)
        {
            result = TRUE;
            sub_GAME_7F08EDB4(group->neighbours, arg1 + 1);
        }

        group++;
    }

    return result;
}


bool sub_GAME_7F08EE70(struct waygroup *from, struct waygroup *to, struct waygroup *groups, s32 arg3)
{
    bool result = TRUE;
    struct waygroup *group;
    s32 i;

    for (group = groups; group->neighbours; group++)
    {
        group->dist = -1;
    }

    from->dist = 0;

    for (i = 0; (arg3 || to->dist < 0) && result; i++)
    {
        result = sub_GAME_7F08EE00(groups, i);
    }

    return result;
}


bool sub_GAME_7F08EF1C(waygroup *from, waygroup *to, waygroup *groups)
{
    u32 stack[2];
    bool result = sub_GAME_7F08EE70(from, to, groups, 0);

    if (result)
    {
        waygroup *curto = to;
        s32 i = curto->dist - 1;

        while (i >= 0)
        {
            curto->dist += 10000;
            curto = sub_GAME_7F08ED60(curto->neighbours, i);
            i--;
        }

        curto->dist += 10000;
    }

    return result;
}


#ifdef NONMATCHING
// unused and similar to waypointFindRoute
void sub_GAME_7F08EFA0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EFA0
/* 0C3AD0 7F08EFA0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C3AD4 7F08EFA4 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C3AD8 7F08EFA8 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C3ADC 7F08EFAC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C3AE0 7F08EFB0 28E10002 */  slti  $at, $a3, 2
/* 0C3AE4 7F08EFB4 00E09825 */  move  $s3, $a3
/* 0C3AE8 7F08EFB8 00A0A025 */  move  $s4, $a1
/* 0C3AEC 7F08EFBC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C3AF0 7F08EFC0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C3AF4 7F08EFC4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C3AF8 7F08EFC8 AFA60038 */  sw    $a2, 0x38($sp)
/* 0C3AFC 7F08EFCC 14200022 */  bnez  $at, .L7F08F058
/* 0C3B00 7F08EFD0 00C08825 */   move  $s1, $a2
/* 0C3B04 7F08EFD4 3C068007 */  lui   $a2, %hi(g_CurrentSetup+4)
/* 0C3B08 7F08EFD8 8CC65D04 */  lw    $a2, %lo(g_CurrentSetup+4)($a2)
/* 0C3B0C 7F08EFDC 50C0001F */  beql  $a2, $zero, .L7F08F05C
/* 0C3B10 7F08EFE0 AE200000 */   sw    $zero, ($s1)
/* 0C3B14 7F08EFE4 0FC23BC7 */  jal   sub_GAME_7F08EF1C
/* 0C3B18 7F08EFE8 AFA40030 */   sw    $a0, 0x30($sp)
/* 0C3B1C 7F08EFEC 1040001A */  beqz  $v0, .L7F08F058
/* 0C3B20 7F08EFF0 8FA40030 */   lw    $a0, 0x30($sp)
/* 0C3B24 7F08EFF4 8FA20038 */  lw    $v0, 0x38($sp)
/* 0C3B28 7F08EFF8 00809025 */  move  $s2, $a0
/* 0C3B2C 7F08EFFC 2673270F */  addiu $s3, $s3, 0x270f
/* 0C3B30 7F08F000 AC440000 */  sw    $a0, ($v0)
/* 0C3B34 7F08F004 8E8E0008 */  lw    $t6, 8($s4)
/* 0C3B38 7F08F008 24102711 */  li    $s0, 10001
/* 0C3B3C 7F08F00C 24510004 */  addiu $s1, $v0, 4
/* 0C3B40 7F08F010 29C12711 */  slti  $at, $t6, 0x2711
/* 0C3B44 7F08F014 14200010 */  bnez  $at, .L7F08F058
/* 0C3B48 7F08F018 2A612712 */   slti  $at, $s3, 0x2712
/* 0C3B4C 7F08F01C 5420000F */  bnezl $at, .L7F08F05C
/* 0C3B50 7F08F020 AE200000 */   sw    $zero, ($s1)
/* 0C3B54 7F08F024 8E440000 */  lw    $a0, ($s2)
.L7F08F028:
/* 0C3B58 7F08F028 0FC23B58 */  jal   sub_GAME_7F08ED60
/* 0C3B5C 7F08F02C 02002825 */   move  $a1, $s0
/* 0C3B60 7F08F030 AE220000 */  sw    $v0, ($s1)
/* 0C3B64 7F08F034 8E8F0008 */  lw    $t7, 8($s4)
/* 0C3B68 7F08F038 26100001 */  addiu $s0, $s0, 1
/* 0C3B6C 7F08F03C 00409025 */  move  $s2, $v0
/* 0C3B70 7F08F040 01F0082A */  slt   $at, $t7, $s0
/* 0C3B74 7F08F044 14200004 */  bnez  $at, .L7F08F058
/* 0C3B78 7F08F048 26310004 */   addiu $s1, $s1, 4
/* 0C3B7C 7F08F04C 0213082A */  slt   $at, $s0, $s3
/* 0C3B80 7F08F050 5420FFF5 */  bnezl $at, .L7F08F028
/* 0C3B84 7F08F054 8E440000 */   lw    $a0, ($s2)
.L7F08F058:
/* 0C3B88 7F08F058 AE200000 */  sw    $zero, ($s1)
.L7F08F05C:
/* 0C3B8C 7F08F05C 8FB80038 */  lw    $t8, 0x38($sp)
/* 0C3B90 7F08F060 26310004 */  addiu $s1, $s1, 4
/* 0C3B94 7F08F064 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C3B98 7F08F068 02381023 */  subu  $v0, $s1, $t8
/* 0C3B9C 7F08F06C 0002C883 */  sra   $t9, $v0, 2
/* 0C3BA0 7F08F070 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C3BA4 7F08F074 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C3BA8 7F08F078 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C3BAC 7F08F07C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C3BB0 7F08F080 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C3BB4 7F08F084 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C3BB8 7F08F088 03E00008 */  jr    $ra
/* 0C3BBC 7F08F08C 03201025 */   move  $v0, $t9
)
#endif


waypoint *findPadWithDistAndSet(s32 *pointnums, s32 arg1, s32 groupnum)
{
    waypoint *points = g_CurrentSetup.pathwaypoints;

    while (*pointnums >= 0)
    {
        waypoint *point = &points[*pointnums];

        if (point->groupNum == groupnum && point->dist == arg1)
        {
            return point;
        }

        *pointnums++;
    }

    return NULL;
}


void sub_GAME_7F08F0E8(s32 *pointnums, s32 value, s32 groupnum)
{
    waypoint *waypoints = g_CurrentSetup.pathwaypoints;

    while (*pointnums >= 0)
    {
        waypoint *waypoint = &waypoints[*pointnums];

        if (waypoint->groupNum == groupnum && waypoint->dist < 0)
        {
            waypoint->dist = value;
        }

        *pointnums++;
    }
}


bool sub_GAME_7F08F138(s32 *pointnums, s32 arg1, s32 groupnum)
{
    bool result = FALSE;
    waypoint *points = g_CurrentSetup.pathwaypoints;

    while (*pointnums >= 0)
    {
        waypoint *point = &points[*pointnums];

        if (arg1 == point->dist && point->neighbours)
        {
            result = TRUE;
            sub_GAME_7F08F0E8(point->neighbours, arg1 + 1, groupnum);
        }

        pointnums++;
    }

    return result;
}


void do_BFS_withinPathSet(waypoint *from, waypoint *to, s32 arg2)
{
    waygroup *groups = g_CurrentSetup.waypointgroups;
    waypoint *points = g_CurrentSetup.pathwaypoints;
    waypoint *point;
    s32 *pointnums = groups[from->groupNum].waypoints;
    s32 i;
    bool more;

    while (*pointnums >= 0)
    {
        point = &points[*pointnums];
        point->dist = -1;
        pointnums++;
    }

    from->dist = 0;

    more = TRUE;

    for (i = 0; (arg2 || to->dist < 0) && more; i++)
    {
        more = sub_GAME_7F08F138(groups[from->groupNum].waypoints, i, from->groupNum);
    }
}


void sub_GAME_7F08F2CC(waypoint *from, waypoint *to)
{
    waypoint *curto;
    s32 value;

    do_BFS_withinPathSet(from, to, 0);

    value = to->dist - 1;
    curto = to;

    while (value >= 0)
    {
        curto->dist += 10000;
        curto = findPadWithDistAndSet(curto->neighbours, value, from->groupNum);

        value--;
    }

    curto->dist += 10000;
}


s32 sub_GAME_7F08F350(waypoint *from, waypoint *to, waypoint **arr, s32 arrlen)
{
    waypoint **arrptr = arr;
    waypoint *curfrom;
    s32 i;

    if (arrlen >= 2)
    {
        sub_GAME_7F08F2CC(from, to);

        *arr = from;
        arrptr++;

        curfrom = from;
        arrlen += 9999;
        i = 10001;

        while (i <= to->dist && i < arrlen)
        {
            curfrom = findPadWithDistAndSet(curfrom->neighbours, i, from->groupNum);
            *arrptr = curfrom;
            arrptr++;
            i++;
        }
    }

    *arrptr = NULL;
    arrptr++;

    return arrptr - arr;
}


void sub_GAME_7F08F438(waygroup *groupa, waygroup *groupb, waypoint **pointa, waypoint **pointb)
{
    waypoint *points = g_CurrentSetup.pathwaypoints;
    waygroup *groups = g_CurrentSetup.waypointgroups;
    s32 *groupapointnums = groupa->waypoints;
    s32 stack;

    while (*groupapointnums >= 0)
    {
        waypoint *groupapoint = &points[*groupapointnums];
        s32 *neighbournums = groupapoint->neighbours;

        while (*neighbournums >= 0)
        {
            waypoint *neighbour = &points[*neighbournums];

            if (groupb == &groups[neighbour->groupNum])
            {
                *pointa = groupapoint;
                *pointb = neighbour;
                return;
            }

            neighbournums++;
        }

        groupapointnums++;
    }
    *pointb = NULL;
    *pointa = NULL;
}


/**
 * Find a route from frompoint to topoint. The arr argument will be populated
 * with pointers to the route's waypoints. If arr is not big enough then only
 * the first part of the route will be populated into the array.
 *
 * The return value is the number of elements populated into the array.
 */
s32 waypointFindRoute(waypoint *frompoint, waypoint *topoint, waypoint **arr, s32 arrlen)
{
    waypoint **arrptr = arr;
    waygroup *groups = g_CurrentSetup.waypointgroups;

    if (groups)
    {
        waygroup *fromgroup = &groups[frompoint->groupNum];
        waygroup *togroup = &groups[topoint->groupNum];

        if (sub_GAME_7F08EF1C(fromgroup, togroup, groups))
        {
            waypoint *curfrompoint = frompoint;
            waygroup *curfromgroup = fromgroup;
            s32 i;

            for (i = fromgroup->dist + 1; i <= togroup->dist && arrlen >= 2; i++)
            {
                s32 numwritten;
                waygroup *nextfromgroup = sub_GAME_7F08ED60(curfromgroup->neighbours, i);
                waypoint *tmppoint;
                waypoint *nextfrompoint;

                sub_GAME_7F08F438(curfromgroup, nextfromgroup, &tmppoint, &nextfrompoint);
                numwritten = sub_GAME_7F08F350(curfrompoint, tmppoint, arrptr, arrlen) - 1;

                arrlen -= numwritten;
                arrptr += numwritten;

                curfrompoint = nextfrompoint;
                curfromgroup = nextfromgroup;
            }

            arrptr += sub_GAME_7F08F350(curfrompoint, topoint, arrptr, arrlen) - 1;
        }
    }

    *arrptr = NULL;
    arrptr++;

    return arrptr - arr;
}


void resetWaypointDistances(void)
{
    waypoint * waypoint;
    waypoint = g_CurrentSetup.pathwaypoints;

    while (waypoint->padID >= 0)
    {
        waypoint->dist = -1;
        waypoint++;
    }
}


waypoint *sub_GAME_7F08F6B0(s32 *pointnums, s32 arg1)
{
	s32 len = 0;
	s32 randomindex;
	s32 i;

	while (pointnums[len] >= 0)
    {
		len++;
	}

	// This is effectively randomly dividing the pointnums list into two,
	// then checking the upper portion before the lower portion. Both loops
	// have the same logic so this seems unusual, but there is reason to do
	// this if they want the returned waypoint to be any random waypoint that
	// meets the arg1 criteria, with equal weighting.

	randomindex = randomGetNext() % len;

	for (i = randomindex; i < len; i++)
    {
		waypoint *point = &g_CurrentSetup.pathwaypoints[pointnums[i]];

		if (point->dist == arg1)
        {
			return point;
		}
	}

	for (i = 0; i < randomindex; i++)
    {
		waypoint *point = &g_CurrentSetup.pathwaypoints[pointnums[i]];

		if (point->dist == arg1)
        {
			return point;
		}
	}

	return NULL;
}


waygroup *sub_GAME_7F08F908(s32 *groupnums, s32 arg1)
{
    s32 len = 0;
    s32 randomindex;
    s32 i;

    while (groupnums[len] >= 0)
    {
        len++;
    }

    // Similar to the above function, return a random waygroup
    // which matches the arg1 criteria.
    randomindex = randomGetNext() % len;

    for (i = randomindex; i < len; i++)
    {
        waygroup *group = &g_CurrentSetup.waypointgroups[groupnums[i]];

        if (group->dist == arg1)
        {
            return group;
        }
    }

    for (i = 0; i < randomindex; i++)
    {
        waygroup *group = &g_CurrentSetup.waypointgroups[groupnums[i]];

        if (group->dist == arg1)
        {
            return group;
        }
    }

    return NULL;
}


waypoint *sub_GAME_7F08FB90(waypoint *pointa, waypoint *pointb)
{
    if (g_CurrentSetup.waypointgroups)
    {
        waygroup *groupa = &g_CurrentSetup.waypointgroups[pointa->groupNum];
        waygroup *groupb = &g_CurrentSetup.waypointgroups[pointb->groupNum];
        waypoint *result;
        s32 stack;

        if (groupa == groupb)
        {
            resetWaypointDistances();
            do_BFS_withinPathSet(pointb, pointa, 1);

            result = sub_GAME_7F08F6B0(pointa->neighbours, -1);

            if (result)
            {
                return result;
            }

            result = sub_GAME_7F08F6B0(pointa->neighbours, pointa->dist + 1);

            if (result)
            {
                return result;
            }
        }
        else
        {
            sub_GAME_7F08EE70(groupb, groupa, g_CurrentSetup.waypointgroups, 0);

            if (groupa->dist >= 0)
            {
                waygroup *tmpgroup = sub_GAME_7F08F908(groupa->neighbours, -1);

                if (tmpgroup)
                {
                    waypoint *sp48;
                    waypoint *sp44;
                    waypoint *arr[3];

                    sub_GAME_7F08F438(groupa, tmpgroup, &sp48, &sp44);

                    if (sp48 == pointa)
                    {
                        return sp44;
                    }

                    if (sub_GAME_7F08F350(pointa, sp48, arr, 3) >= 3)
                    {
                        return arr[1];
                    }
                }
                else
                {
                    waygroup *tmpgroup = sub_GAME_7F08ED60(groupa->neighbours, groupa->dist - 1);

                    if (tmpgroup)
                    {
                        waypoint *sp30;
                        waypoint *sp2c;

                        sub_GAME_7F08F438(groupa, tmpgroup, &sp30, &sp2c);
                        do_BFS_withinPathSet(sp30, pointa, 1);
                        result = findPadWithDistAndSet(pointa->neighbours, pointa->dist + 1, pointa->groupNum);

                        if (result)
                        {
                            return result;
                        }
                    }
                }
            }
        }
    }

    return NULL;
}


void sub_GAME_7F08FD1C(void)
{
    waypoint* waypoints;
    s32 count;
    waypoint* entry;
    waypoint* from;
    waypoint* to;
    waypoint** arr_entry;
    u32 unused[0x30];

    waypoints = g_CurrentSetup.pathwaypoints;

    if (waypoints != NULL)
    {
        waypoint *arr;
        count = 0;
        entry = waypoints;

        while (entry->padID >= 0)
        {
            entry++;
            count++;
        }

        from = &waypoints[randomGetNext() % count];
        to = &waypoints[randomGetNext() % count];

        if (waypointFindRoute(from, to, &arr, 0x32) != 0)
        {
            for (arr_entry = &arr; *arr_entry; arr_entry++)
            {
                // do nothing
            }
        }
    }
}
