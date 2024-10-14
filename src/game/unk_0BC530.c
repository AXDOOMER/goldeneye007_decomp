#include <ultra64.h>
#include "player.h"
#include "bg.h"
#include "unk_0BC530.h"
#include "matrixmath.h"

#ifdef VERSION_EU
#define AMT300 100
#else
#define AMT300 300 
#endif

// bss
/**
 * EU .bss 8007DC90
*/
u8 roomStatusFlags[AMT300];

s32 roomIndices[AMT300];
s32 roomOwners[AMT300];
Mtx roomMatrices[AMT300];


/**
 * Initialize room and player-related data structures.
 * Sets all rooms and players to an initial state.
 *
 * Address: 0x7F0BC530
 */
void initializeRoomData(void) 
{
    int i;
      
    for (i=0; i<getPlayerCount(); i++)
    {
        g_playerPointers[i]->curRoomIndex = -1;
    }

    for (i=0; i<AMT300; i++)
    {
      roomIndices[i] = -1;
      roomStatusFlags[i] = 2;
      
      roomOwners[i] = -1;
      
      
    }

    for (i=0; i<getMaxNumRooms(); ++i)
    {
        array_room_info[i].field_36 = -1;
    }
}


/**
 * Set the player's room field.
 *
 * Address: 0x7F0BC624
 */
void setPlayerRoomField(s32 roomIndex) {
  g_CurrentPlayer->curRoomIndex = roomIndex;
}


/**
 * Assigns a room index to a specific room ID.
 *
 * Address: 0x7F0BC634
 */
void assignRoomIndexToRoomID(int roomIndex,int roomID)
{
    array_room_info[roomID].field_36 = roomIndex;
    roomIndices[roomIndex] = roomID;
}


/**
 * Removes the room index assignment for a specific room ID.
 *
 * Address: 0x7F0BC660
 */
void removeRoomIndexFromRoomID(int roomIndex,int roomID)
{
    array_room_info[roomID].field_36 = -1;
    roomIndices[roomIndex] = -1;
}


/**
 * Resets a room's state to its initial condition.
 *
 * Address: 0x7F0BC690
 */
void resetRoomState(int roomIndex)
{
    if (roomIndices[roomIndex] != -1) {
        removeRoomIndexFromRoomID(roomIndex,roomIndices[roomIndex]);
    }
    roomStatusFlags[roomIndex] = 2;
    roomOwners[roomIndex] = -1;
}


/**
 * Finds and returns the first available room index.
 * Returns 0 if no available room is found.
 *
 * Address: 0x7F0BC6F0
 */
s32 findAvailableRoomIndex(void)
{
    s32 i;

    for (i = 0; i<AMT300; i++)
    {
        if (((s32) roomStatusFlags[i] >= 2) && (roomOwners[i] == -1))
        {
            return i;
        }
    }
    return 0;
}


/**
 * Updates the status flags for rooms, resetting those that are inactive.
 *
 * NTSC address 0x7F0BC7D4.
 */
void updateRoomStatusFlags(void)
{
    s32 i;

    for(i = 0; i<AMT300; ++i)
    {
        if (roomOwners[i] > -1)
        {
            roomStatusFlags[i]++;
            
            if (roomStatusFlags[i] >= 2)
            {
                resetRoomState(i);
            }            
        } 
    }
}




/**
 * Manages room index allocation and matrix setup for a given room.
 *
 * NTSC address 0x7F0BC85C.
 */
s32 setupRoomTransformationMatrix(s32 roomID)
{
    s32 roomIndex;
    Mtxf roomTransformMatrix;

    roomIndex = array_room_info[roomID].field_36;
    
    if ((roomIndex == -1) || (g_CurrentPlayer->curRoomIndex != roomOwners[roomIndex]))
    {
        if (roomIndex != -1)
        {
            removeRoomIndexFromRoomID(roomIndex, roomID);
        }

        roomIndex = findAvailableRoomIndex();
        assignRoomIndexToRoomID(roomIndex, roomID);
        
        roomStatusFlags[roomIndex] = 0;
    }
    else
    {
        roomStatusFlags[roomIndex] = 0;
        
        return roomIndex;
    }

    roomOwners[roomIndex] = g_CurrentPlayer->curRoomIndex;

    matrix_4x4_set_identity(&roomTransformMatrix);
    
    roomTransformMatrix.m[0][0] = room_data_float2;
    roomTransformMatrix.m[1][1] = room_data_float2;
    roomTransformMatrix.m[2][2] = room_data_float2;
    
    roomTransformMatrix.m[3][0] = (ptr_bgdata_room_fileposition_list[roomID].pos.f[0] * room_data_float2) - g_CurrentPlayer->current_model_pos.f[0];
    roomTransformMatrix.m[3][1] = (ptr_bgdata_room_fileposition_list[roomID].pos.f[1] * room_data_float2) - g_CurrentPlayer->current_model_pos.f[1];
    roomTransformMatrix.m[3][2] = (ptr_bgdata_room_fileposition_list[roomID].pos.f[2] * room_data_float2) - g_CurrentPlayer->current_model_pos.f[2];
    
    matrix_4x4_f32_to_s32(&roomTransformMatrix, &roomMatrices[roomIndex]);
    
    return roomIndex;
}



/**
 * Updates the display list with the room matrix for a specific room roomID.
 *
 * Address: 0x7F0BC9C4
 */
Gfx * applyRoomMatrixToDisplayList(Gfx *gdl,int roomID)
{
    s32 roomIndex;
    
    roomIndex = setupRoomTransformationMatrix(roomID);
    gSPMatrix(gdl++, &roomMatrices[roomIndex], G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
    return gdl;
}


/**
 * Returns the position of a room by its roomID.
 *
 * Address: 0x7f0bca14
 */
struct coord3d* getRoomPositionByIndex(s32 roomID)
{
    return &ptr_bgdata_room_fileposition_list[roomID].pos;
}

/**
 * Retrieves and scales the position of a room by its roomID.
 *
 * Address: 0x7F0BCA34
 */
void getRoomPositionScaledByIndex(s32 roomID, coord3d *scaledPos)
{
    scaledPos->x = ptr_bgdata_room_fileposition_list[roomID].pos.x * room_data_float2;
    scaledPos->y = ptr_bgdata_room_fileposition_list[roomID].pos.y * room_data_float2;
    scaledPos->z = ptr_bgdata_room_fileposition_list[roomID].pos.z * room_data_float2;
}

