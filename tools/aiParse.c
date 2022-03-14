
#include <stdio.h>

#define CharArrayTo16(val, index) (val[index + 1] | val[index] << 8)
#define CharArrayTo24(val, index) (val[index + 1] << 8 | val[index + 2] | val[index] << 16)
#define CharArrayTo32(val, index) (val[index + 1] << 16 | val[index + 2] << 8 | val[index + 3] | val[index] << 24)

#define isNotBoundPad(pad)  pad < 10000
#define getBoundPadNum(pad) pad - 10000
#define setBoundPadNum(pad) pad + 10000

#define M_TAU_F            6.2831855f
#define ByteToRadian(Byte) ((Byte * M_TAU_F) * (1.0f / 256.0f))
#define RadToDeg(RAD)      (float)((RAD) / M_TAU_F * 360.0f)

#define TARGET_BOND         0x0001 /* Set target to bond (ignores target argument)*/
#define TARGET_FRONT_OF_CHR 0x0002 /* Set target to front of chr*/
#define TARGET_CHR          0x0004 /* Set target type to chr_num*/
#define TARGET_PAD          0x0008 /* Set target type to pad*/
#define TARGET_COMPASS      0x0010 /* Set target to compass direction (hex) N: 0000 E: C000 S: 8000: W: 4000*/
#define TARGET_AIM_ONLY     0x0020 /* Aim at target instead of firing*/
#define TARGET_DONTTURN     0x0040 /* Limits target to 180 degrees in front of guard (cannot be used with TARGET_BOND flag)*/

// command 68 - door states
char *DOORSTATE_ToString[] = {
    " DOOR_STATE_CLOSED",  /* Closed*/
    " DOOR_STATE_OPEN",    /* Opened*/
    " DOOR_STATE_CLOSING", /* Closing*/
    " DOOR_STATE_OPENING" /* Opening*/};

// command D7 - hud flags
#define HUD_HIDE_ALL           0x00 /* Hide all*/
#define HUD_SHOW_TEXT_TOP      0x01 /* Don't hide top text*/
#define HUD_SHOW_TEXT_BOTTOM   0x02 /* Don't hide bottom text*/
#define HUD_SHOW_HUD_COUNTDOWN 0x04 /* Don't hide hud countdown*/

/* special chr num IDs */
#define CHR_BOND_CINEMA -8 /* only works when bond has a third person model (intro/exit cutscene) */
#define CHR_CLONE       -7
#define CHR_SEE_SHOT    -6 /* stored as chr->chrseeshot */
#define CHR_SEE_DIE     -5 /* stored as chr->chrseedie */
#define CHR_PRESET      -4 /* stored as chr->chrpreset1 */
#define CHR_SELF        -3

/* private chr ID, cannot be accessed with ai commands */
#define CHR_OBJECTIVE        -2    /* objective ai list chr ID */
#define CHR_FREE             -1    /* chr IDs when free'd (killed or removed from level) */
#define CHR_SPAWN_NUM_START  5000  /* default chr num for spawned guards with ai command BD/BE */
#define CHR_CLONED_NUM_START 10000 /* default chr num for cloed guards with ai command C1 */
/* Special ID for selecting PadPreset in AI list */
#define PAD_PRESET1          9000 /* stored as chr->padpreset1 */

#define isGlobalAIListID(ID)  ((ID) < 18)
#define isBGAIListID(ID)      ((ID) > 4097)
#define isChrAIListID(ID)     (!isGlobalAIListID(ID) && !isBGAIListID(ID))
#define setGlobalAIListID(ID) ((ID) + 0)
#define setChrAIListID(ID)    ((ID) + 1025)
#define setBGAIListID(ID)     ((ID) + 4097)
#define getGlobalAIListID(ID) ((ID)-0)
#define getChrAIListID(ID)    ((ID)-1025)
#define getBGAIListID(ID)     ((ID)-4097)

char *GAILIST_ToString[] = {
    "GAILIST_AIM_AT_BOND",
    "GAILIST_DEAD_AI",
    "GAILIST_STANDARD_GUARD",
    "GAILIST_PLAY_IDLE_ANIMATION",
    "GAILIST_BASH_KEYBOARD",
    "GAILIST_SIMPLE_GUARD_DEAF",
    "GAILIST_ATTACK_BOND",
    "GAILIST_SIMPLE_GUARD",
    "GAILIST_RUN_TO_BOND",
    "GAILIST_SIMPLE_GUARD_ALARM_RAISER",
    "GAILIST_STARTLE_AND_RUN_TO_BOND",
    "GAILIST_TRY_CLONE_SEND_OR_RUN_TO_BOND",
    "GAILIST_STANDARD_CLONE",
    "GAILIST_PERSISTENTLY_CHASE_AND_ATTACK_BOND",
    "GAILIST_WAIT_ONE_SECOND",
    "GAILIST_END_LEVEL",
    "GAILIST_DRAW_TT33_AND_ATTCK_BOND",
    "GAILIST_REMOVE_CHR"};

#define AI_GotoNext_LENGTH                                       2
#define AI_GotoFirst_LENGTH                                      2
#define AI_Label_LENGTH                                          2
#define AI_Yield_LENGTH                                          1
#define AI_EndList_LENGTH                                        /*canonical name*/ 1
#define AI_SetChrAiList_LENGTH                                   4
#define AI_SetReturnAiList_LENGTH                                3
#define AI_Return_LENGTH                                         1
#define AI_Stop_LENGTH                                           1
#define AI_Kneel_LENGTH                                          1
#define AI_PlayAnimation_LENGTH                                  9
#define AI_IFPlayingAnimation_LENGTH                             2
#define AI_PointAtBond_LENGTH                                    1
#define AI_LookSurprised_LENGTH                                  1
#define AI_TRYSidestepping_LENGTH                                2
#define AI_TRYSideHopping_LENGTH                                 2
#define AI_TRYSideRunning_LENGTH                                 2
#define AI_TRYFiringWalk_LENGTH                                  2
#define AI_TRYFiringRun_LENGTH                                   2
#define AI_TRYFiringRoll_LENGTH                                  2
#define AI_TRYFireOrAimAtTarget_LENGTH                           6
#define AI_TRYFireOrAimAtTargetKneel_LENGTH                      6
#define AI_IFImFiring_LENGTH                                     2
#define AI_IFImFiringAndLockedForward_LENGTH                     2
#define AI_TRYFireOrAimAtTargetUpdate_LENGTH                     6
#define AI_TRYFacingTarget_LENGTH                                6
#define AI_HitChrWithItem_LENGTH                                 4
#define AI_ChrHitChr_LENGTH                                      4
#define AI_TRYThrowingGrenade_LENGTH                             2
#define AI_TRYDroppingItem_LENGTH                                5
#define AI_RunToPad_LENGTH                                       3
#define AI_RunToPadPreset_LENGTH                                 1
#define AI_WalkToPad_LENGTH                                      3
#define AI_SprintToPad_LENGTH                                    3
#define AI_StartPatrol_LENGTH                                    2
#define AI_Surrender_LENGTH                                      1
#define AI_RemoveMe_LENGTH                                       1
#define AI_ChrRemoveInstant_LENGTH                               2
#define AI_TRYTriggeringAlarmAtPad_LENGTH                        4
#define AI_AlarmOn_LENGTH                                        1
#define AI_AlarmOff_LENGTH                                       1
#define AI_TRYRunFromBond_LENGTH                                 2
#define AI_TRYRunToBond_LENGTH                                   2
#define AI_TRYWalkToBond_LENGTH                                  2
#define AI_TRYSprintToBond_LENGTH                                2
#define AI_TRYFindCover_LENGTH                                   2
#define AI_TRYRunToChr_LENGTH                                    3
#define AI_TRYWalkToChr_LENGTH                                   3
#define AI_TRYSprintToChr_LENGTH                                 3
#define AI_IFImOnPatrolOrStopped_LENGTH                          2
#define AI_IFChrDyingOrDead_LENGTH                               3
#define AI_IFChrDoesNotExist_LENGTH                              3
#define AI_IFISeeBond_LENGTH                                     2
#define AI_SetNewRandom_LENGTH                                   1
#define AI_IFRandomLessThan_LENGTH                               3
#define AI_IFRandomGreaterThan_LENGTH                            3
#define AI_IFICanHearAlarm_LENGTH                                2
#define AI_IFAlarmIsOn_LENGTH                                    2
#define AI_IFGasIsLeaking_LENGTH                                 2
#define AI_IFIHeardBond_LENGTH                                   2
#define AI_IFISeeSomeoneShot_LENGTH                              2
#define AI_IFISeeSomeoneDie_LENGTH                               2
#define AI_IFICouldSeeBond_LENGTH                                2
#define AI_IFICouldSeeBondsStan_LENGTH                           2
#define AI_IFIWasShotRecently_LENGTH                             2
#define AI_IFIHeardBondRecently_LENGTH                           2
#define AI_IFImInRoomWithChr_LENGTH                              3
#define AI_IFIveNotBeenSeen_LENGTH                               2
#define AI_IFImOnScreen_LENGTH                                   2
#define AI_IFMyRoomIsOnScreen_LENGTH                             2
#define AI_IFRoomWithPadIsOnScreen_LENGTH                        4
#define AI_IFImTargetedByBond_LENGTH                             2
#define AI_IFBondMissedMe_LENGTH                                 2
#define AI_IFMyAngleToBondLessThan_LENGTH                        3
#define AI_IFMyAngleToBondGreaterThan_LENGTH                     3
#define AI_IFMyAngleFromBondLessThan_LENGTH                      3
#define AI_IFMyAngleFromBondGreaterThan_LENGTH                   3
#define AI_IFMyDistanceToBondLessThanDecimeter_LENGTH            4
#define AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH         4
#define AI_IFChrDistanceToPadLessThanDecimeter_LENGTH            7
#define AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH         7
#define AI_IFMyDistanceToChrLessThanDecimeter_LENGTH             5
#define AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH          5
#define AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH 4
#define AI_IFBondDistanceToPadLessThanDecimeter_LENGTH           6
#define AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH        6
#define AI_IFChrInRoomWithPad_LENGTH                             5
#define AI_IFBondInRoomWithPad_LENGTH                            4
#define AI_IFBondCollectedObject_LENGTH                          3
#define AI_IFItemIsStationaryWithinLevel_LENGTH                  3
#define AI_IFItemIsAttachedToObject_LENGTH                       4
#define AI_IFBondHasItemEquipped_LENGTH                          3
#define AI_IFObjectExists_LENGTH                                 3
#define AI_IFObjectNotDestroyed_LENGTH                           3
#define AI_IFObjectWasActivated_LENGTH                           3
#define AI_IFBondUsedGadgetOnObject_LENGTH                       3
#define AI_ActivateObject_LENGTH                                 2
#define AI_DestroyObject_LENGTH                                  2
#define AI_DropObjectFromChr_LENGTH                              2
#define AI_ChrDropAllConcealedItems_LENGTH                       2
#define AI_ChrDropAllHeldItems_LENGTH                            2
#define AI_BondCollectObject_LENGTH                              2
#define AI_ChrEquipObject_LENGTH                                 3
#define AI_MoveObject_LENGTH                                     4
#define AI_DoorOpen_LENGTH                                       2
#define AI_DoorClose_LENGTH                                      2
#define AI_IFDoorStateEqual_LENGTH                               4
#define AI_IFDoorHasBeenOpenedBefore_LENGTH                      3
#define AI_DoorSetLock_LENGTH                                    3
#define AI_DoorUnsetLock_LENGTH                                  3
#define AI_IFDoorLockEqual_LENGTH                                4
#define AI_IFObjectiveNumComplete_LENGTH                         3
#define AI_TRYUnknown6e_LENGTH                                   3
#define AI_TRYUnknown6f_LENGTH                                   3
#define AI_IFGameDifficultyLessThan_LENGTH                       3
#define AI_IFGameDifficultyGreaterThan_LENGTH                    3
#define AI_IFMissionTimeLessThan_LENGTH                          4
#define AI_IFMissionTimeGreaterThan_LENGTH                       4
#define AI_IFSystemPowerTimeLessThan_LENGTH                      4
#define AI_IFSystemPowerTimeGreaterThan_LENGTH                   4
#define AI_IFLevelIdLessThan_LENGTH                              3
#define AI_IFLevelIdGreaterThan_LENGTH                           3
#define AI_IFMyNumArghsLessThan_LENGTH                           3
#define AI_IFMyNumArghsGreaterThan_LENGTH                        3
#define AI_IFMyNumCloseArghsLessThan_LENGTH                      3
#define AI_IFMyNumCloseArghsGreaterThan_LENGTH                   3
#define AI_IFChrHealthLessThan_LENGTH                            4
#define AI_IFChrHealthGreaterThan_LENGTH                         4
#define AI_IFChrWasDamagedSinceLastCheck_LENGTH                  3
#define AI_IFBondHealthLessThan_LENGTH                           3
#define AI_IFBondHealthGreaterThan_LENGTH                        3
#define AI_SetMyMorale_LENGTH                                    2
#define AI_AddToMyMorale_LENGTH                                  2
#define AI_SubtractFromMyMorale_LENGTH                           2
#define AI_IFMyMoraleLessThan_LENGTH                             3
#define AI_IFMyMoraleLessThanRandom_LENGTH                       2
#define AI_SetMyAlertness_LENGTH                                 2
#define AI_AddToMyAlertness_LENGTH                               2
#define AI_SubtractFromMyAlertness_LENGTH                        2
#define AI_IFMyAlertnessLessThan_LENGTH                          3
#define AI_IFMyAlertnessLessThanRandom_LENGTH                    2
#define AI_SetMyHearingScale_LENGTH                              3
#define AI_SetMyVisionRange_LENGTH                               2
#define AI_SetMyGrenadeProbability_LENGTH                        2
#define AI_SetMyChrNum_LENGTH                                    2
#define AI_SetMyHealthTotal_LENGTH                               3
#define AI_SetMyArmour_LENGTH                                    3
#define AI_SetMySpeedRating_LENGTH                               2
#define AI_SetMyArghRating_LENGTH                                2
#define AI_SetMyAccuracyRating_LENGTH                            2
#define AI_SetMyFlags2_LENGTH                                    2
#define AI_UnsetMyFlags2_LENGTH                                  2
#define AI_IFMyFlags2Has_LENGTH                                  3
#define AI_SetChrBitfield_LENGTH                                 3
#define AI_UnsetChrBitfield_LENGTH                               3
#define AI_IFChrBitfieldHas_LENGTH                               4
#define AI_SetObjectiveBitfield_LENGTH                           5
#define AI_UnsetObjectiveBitfield_LENGTH                         5
#define AI_IFObjectiveBitfieldHas_LENGTH                         6
#define AI_SetMychrflags_LENGTH                                  5
#define AI_UnsetMychrflags_LENGTH                                5
#define AI_IFMychrflagsHas_LENGTH                                6
#define AI_SetChrchrflags_LENGTH                                 6
#define AI_UnsetChrchrflags_LENGTH                               6
#define AI_IFChrchrflagsHas_LENGTH                               7
#define AI_SetObjectFlags_LENGTH                                 6
#define AI_UnsetObjectFlags_LENGTH                               6
#define AI_IFObjectFlagsHas_LENGTH                               7
#define AI_SetObjectFlags2_LENGTH                                6
#define AI_UnsetObjectFlags2_LENGTH                              6
#define AI_IFObjectFlags2Has_LENGTH                              7
#define AI_SetMyChrPreset_LENGTH                                 2
#define AI_SetChrChrPreset_LENGTH                                3
#define AI_SetMyPadPreset_LENGTH                                 3
#define AI_SetChrPadPreset_LENGTH                                4
#define AI_MyTimerStart_LENGTH                                   1
#define AI_MyTimerReset_LENGTH                                   1
#define AI_MyTimerPause_LENGTH                                   1
#define AI_MyTimerResume_LENGTH                                  1
#define AI_IFMyTimerIsNotRunning_LENGTH                          2
#define AI_IFMyTimerLessThanTicks_LENGTH                         5
#define AI_IFMyTimerGreaterThanTicks_LENGTH                      5
#define AI_HudCountdownShow_LENGTH                               1
#define AI_HudCountdownHide_LENGTH                               1
#define AI_HudCountdownSet_LENGTH                                3
#define AI_HudCountdownStop_LENGTH                               1
#define AI_HudCountdownStart_LENGTH                              1
#define AI_IFHudCountdownIsNotRunning_LENGTH                     2
#define AI_IFHudCountdownLessThan_LENGTH                         4
#define AI_IFHudCountdownGreaterThan_LENGTH                      4
#define AI_TRYSpawningChrAtPad_LENGTH                            12
#define AI_TRYSpawningChrNextToChr_LENGTH                        11
#define AI_TRYGiveMeItem_LENGTH                                  9
#define AI_TRYGiveMeHat_LENGTH                                   8
#define AI_TRYCloningChr_LENGTH                                  5
#define AI_TextPrintBottom_LENGTH                                3
#define AI_TextPrintTop_LENGTH                                   3
#define AI_SfxPlay_LENGTH                                        4
#define AI_SfxEmitFromObject_LENGTH                              5
#define AI_SfxEmitFromPad_LENGTH                                 6
#define AI_SfxSetChannelVolume_LENGTH                            6
#define AI_SfxFadeChannelVolume_LENGTH                           6
#define AI_SfxStopChannel_LENGTH                                 2
#define AI_IFSfxChannelVolumeLessThan_LENGTH                     5
#define AI_VehicleStartPath_LENGTH                               2
#define AI_VehicleSpeed_LENGTH                                   5
#define AI_AircraftRotorSpeed_LENGTH                             5
#define AI_IFCameraIsInIntro_LENGTH                              2
#define AI_IFCameraIsInBondSwirl_LENGTH                          2
#define AI_TvChangeScreenBank_LENGTH                             4
#define AI_IFBondInTank_LENGTH                                   /*canonical name*/ 2
#define AI_EndLevel_LENGTH                                       /* canonical name */ 1
#define AI_CameraReturnToBond_LENGTH                             1
#define AI_CameraLookAtBondFromPad_LENGTH                        3
#define AI_CameraSwitch_LENGTH                                   6
#define AI_IFBondYPosLessThan_LENGTH                             4
#define AI_BondDisableControl_LENGTH                             2
#define AI_BondEnableControl_LENGTH                              1
#define AI_TRYTeleportingChrToPad_LENGTH                         5
#define AI_ScreenFadeToBlack_LENGTH                              1
#define AI_ScreenFadeFromBlack_LENGTH                            1
#define AI_IFScreenFadeCompleted_LENGTH                          2
#define AI_HideAllChrs_LENGTH                                    1
#define AI_ShowAllChrs_LENGTH                                    1
#define AI_DoorOpenInstant_LENGTH                                2
#define AI_ChrRemoveItemInHand_LENGTH                            3
#define AI_IfNumberOfActivePlayersLessThan_LENGTH                3
#define AI_IFBondItemTotalAmmoLessThan_LENGTH                    4
#define AI_BondEquipItem_LENGTH                                  2
#define AI_BondEquipItemCinema_LENGTH                            2
#define AI_BondSetLockedVelocity_LENGTH                          3
#define AI_IFObjectInRoomWithPad_LENGTH                          5
#define AI_SwitchSky_LENGTH                                      1
#define AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH           1
#define AI_IFBondIsDead_LENGTH                                   2
#define AI_BondDisableDamageAndPickups_LENGTH                    1
#define AI_BondHideWeapons_LENGTH                                1
#define AI_CameraOrbitPad_LENGTH                                 13
#define AI_CreditsRoll_LENGTH                                    1
#define AI_IFCreditsHasCompleted_LENGTH                          2
#define AI_IFObjectiveAllCompleted_LENGTH                        2
#define AI_IFFolderActorIsEqual_LENGTH                           3
#define AI_IFBondDamageAndPickupsDisabled_LENGTH                 2
#define AI_MusicPlaySlot_LENGTH                                  4
#define AI_MusicStopSlot_LENGTH                                  2
#define AI_TriggerExplosionsAroundBond_LENGTH                    1
#define AI_IFKilledCiviliansGreaterThan_LENGTH                   3
#define AI_IFChrWasShotSinceLastCheck_LENGTH                     3
#define AI_BondKilledInAction_LENGTH                             1
#define AI_RaiseArms_LENGTH                                      1
#define AI_GasLeakAndFadeFog_LENGTH                              1
#define AI_ObjectRocketLaunch_LENGTH                             2

int AI_CMD_LENGTHS_ToInt[] = {
    AI_GotoNext_LENGTH,
    AI_GotoFirst_LENGTH,
    AI_Label_LENGTH,
    AI_Yield_LENGTH,
    AI_EndList_LENGTH,
    AI_SetChrAiList_LENGTH,
    AI_SetReturnAiList_LENGTH,
    AI_Return_LENGTH,
    AI_Stop_LENGTH,
    AI_Kneel_LENGTH,
    AI_PlayAnimation_LENGTH,
    AI_IFPlayingAnimation_LENGTH,
    AI_PointAtBond_LENGTH,
    AI_LookSurprised_LENGTH,
    AI_TRYSidestepping_LENGTH,
    AI_TRYSideHopping_LENGTH,
    AI_TRYSideRunning_LENGTH,
    AI_TRYFiringWalk_LENGTH,
    AI_TRYFiringRun_LENGTH,
    AI_TRYFiringRoll_LENGTH,
    AI_TRYFireOrAimAtTarget_LENGTH,
    AI_TRYFireOrAimAtTargetKneel_LENGTH,
    AI_TRYFireOrAimAtTargetUpdate_LENGTH,
    AI_TRYFacingTarget_LENGTH,
    AI_HitChrWithItem_LENGTH,
    AI_ChrHitChr_LENGTH,
    AI_TRYThrowingGrenade_LENGTH,
    AI_TRYDroppingItem_LENGTH,
    AI_RunToPad_LENGTH,
    AI_RunToPadPreset_LENGTH,
    AI_WalkToPad_LENGTH,
    AI_SprintToPad_LENGTH,
    AI_StartPatrol_LENGTH,
    AI_Surrender_LENGTH,
    AI_RemoveMe_LENGTH,
    AI_ChrRemoveInstant_LENGTH,
    AI_TRYTriggeringAlarmAtPad_LENGTH,
    AI_AlarmOn_LENGTH,
    AI_AlarmOff_LENGTH,
    AI_TRYRunFromBond_LENGTH,
    AI_TRYRunToBond_LENGTH,
    AI_TRYWalkToBond_LENGTH,
    AI_TRYSprintToBond_LENGTH,
    AI_TRYFindCover_LENGTH,
    AI_TRYRunToChr_LENGTH,
    AI_TRYWalkToChr_LENGTH,
    AI_TRYSprintToChr_LENGTH,
    AI_IFImOnPatrolOrStopped_LENGTH,
    AI_IFChrDyingOrDead_LENGTH,
    AI_IFChrDoesNotExist_LENGTH,
    AI_IFISeeBond_LENGTH,
    AI_SetNewRandom_LENGTH,
    AI_IFRandomLessThan_LENGTH,
    AI_IFRandomGreaterThan_LENGTH,
    AI_IFICanHearAlarm_LENGTH,
    AI_IFAlarmIsOn_LENGTH,
    AI_IFGasIsLeaking_LENGTH,
    AI_IFIHeardBond_LENGTH,
    AI_IFISeeSomeoneShot_LENGTH,
    AI_IFISeeSomeoneDie_LENGTH,
    AI_IFICouldSeeBond_LENGTH,
    AI_IFICouldSeeBondsStan_LENGTH,
    AI_IFIWasShotRecently_LENGTH,
    AI_IFIHeardBondRecently_LENGTH,
    AI_IFImInRoomWithChr_LENGTH,
    AI_IFIveNotBeenSeen_LENGTH,
    AI_IFImOnScreen_LENGTH,
    AI_IFMyRoomIsOnScreen_LENGTH,
    AI_IFRoomWithPadIsOnScreen_LENGTH,
    AI_IFImTargetedByBond_LENGTH,
    AI_IFBondMissedMe_LENGTH,
    AI_IFMyAngleToBondLessThan_LENGTH,
    AI_IFMyAngleToBondGreaterThan_LENGTH,
    AI_IFMyAngleFromBondLessThan_LENGTH,
    AI_IFMyAngleFromBondGreaterThan_LENGTH,
    AI_IFMyDistanceToBondLessThanDecimeter_LENGTH,
    AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH,
    AI_IFChrDistanceToPadLessThanDecimeter_LENGTH,
    AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH,
    AI_IFMyDistanceToChrLessThanDecimeter_LENGTH,
    AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH,
    AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH,
    AI_IFBondDistanceToPadLessThanDecimeter_LENGTH,
    AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH,
    AI_IFChrInRoomWithPad_LENGTH,
    AI_IFBondInRoomWithPad_LENGTH,
    AI_IFBondCollectedObject_LENGTH,
    AI_IFItemIsStationaryWithinLevel_LENGTH,
    AI_IFItemIsAttachedToObject_LENGTH,
    AI_IFBondHasItemEquipped_LENGTH,
    AI_IFObjectExists_LENGTH,
    AI_IFObjectNotDestroyed_LENGTH,
    AI_IFObjectWasActivated_LENGTH,
    AI_IFBondUsedGadgetOnObject_LENGTH,
    AI_ActivateObject_LENGTH,
    AI_DestroyObject_LENGTH,
    AI_DropObjectFromChr_LENGTH,
    AI_ChrDropAllConcealedItems_LENGTH,
    AI_ChrDropAllHeldItems_LENGTH,
    AI_BondCollectObject_LENGTH,
    AI_ChrEquipObject_LENGTH,
    AI_MoveObject_LENGTH,
    AI_DoorOpen_LENGTH,
    AI_DoorClose_LENGTH,
    AI_IFDoorStateEqual_LENGTH,
    AI_IFDoorHasBeenOpenedBefore_LENGTH,
    AI_DoorSetLock_LENGTH,
    AI_DoorUnsetLock_LENGTH,
    AI_IFDoorLockEqual_LENGTH,
    AI_IFObjectiveNumComplete_LENGTH,
    AI_TRYUnknown6e_LENGTH,
    AI_TRYUnknown6f_LENGTH,
    AI_IFGameDifficultyLessThan_LENGTH,
    AI_IFGameDifficultyGreaterThan_LENGTH,
    AI_IFMissionTimeLessThan_LENGTH,
    AI_IFMissionTimeGreaterThan_LENGTH,
    AI_IFSystemPowerTimeLessThan_LENGTH,
    AI_IFSystemPowerTimeGreaterThan_LENGTH,
    AI_IFLevelIdLessThan_LENGTH,
    AI_IFLevelIdGreaterThan_LENGTH,
    AI_IFMyNumArghsLessThan_LENGTH,
    AI_IFMyNumArghsGreaterThan_LENGTH,
    AI_IFMyNumCloseArghsLessThan_LENGTH,
    AI_IFMyNumCloseArghsGreaterThan_LENGTH,
    AI_IFChrHealthLessThan_LENGTH,
    AI_IFChrHealthGreaterThan_LENGTH,
    AI_IFChrWasDamagedSinceLastCheck_LENGTH,
    AI_IFBondHealthLessThan_LENGTH,
    AI_IFBondHealthGreaterThan_LENGTH,
    AI_SetMyMorale_LENGTH,
    AI_AddToMyMorale_LENGTH,
    AI_SubtractFromMyMorale_LENGTH,
    AI_IFMyMoraleLessThan_LENGTH,
    AI_IFMyMoraleLessThanRandom_LENGTH,
    AI_SetMyAlertness_LENGTH,
    AI_AddToMyAlertness_LENGTH,
    AI_SubtractFromMyAlertness_LENGTH,
    AI_IFMyAlertnessLessThan_LENGTH,
    AI_IFMyAlertnessLessThanRandom_LENGTH,
    AI_SetMyHearingScale_LENGTH,
    AI_SetMyVisionRange_LENGTH,
    AI_SetMyGrenadeProbability_LENGTH,
    AI_SetMyChrNum_LENGTH,
    AI_SetMyHealthTotal_LENGTH,
    AI_SetMyArmour_LENGTH,
    AI_SetMySpeedRating_LENGTH,
    AI_SetMyArghRating_LENGTH,
    AI_SetMyAccuracyRating_LENGTH,
    AI_SetMyFlags2_LENGTH,
    AI_UnsetMyFlags2_LENGTH,
    AI_IFMyFlags2Has_LENGTH,
    AI_SetChrBitfield_LENGTH,
    AI_UnsetChrBitfield_LENGTH,
    AI_IFChrBitfieldHas_LENGTH,
    AI_SetObjectiveBitfield_LENGTH,
    AI_UnsetObjectiveBitfield_LENGTH,
    AI_IFObjectiveBitfieldHas_LENGTH,
    AI_SetMychrflags_LENGTH,
    AI_UnsetMychrflags_LENGTH,
    AI_IFMychrflagsHas_LENGTH,
    AI_SetChrchrflags_LENGTH,
    AI_UnsetChrchrflags_LENGTH,
    AI_IFChrchrflagsHas_LENGTH,
    AI_SetObjectFlags_LENGTH,
    AI_UnsetObjectFlags_LENGTH,
    AI_IFObjectFlagsHas_LENGTH,
    AI_SetObjectFlags2_LENGTH,
    AI_UnsetObjectFlags2_LENGTH,
    AI_IFObjectFlags2Has_LENGTH,
    AI_SetMyChrPreset_LENGTH,
    AI_SetChrChrPreset_LENGTH,
    AI_SetMyPadPreset_LENGTH,
    AI_SetChrPadPreset_LENGTH,
    0,
    AI_MyTimerStart_LENGTH,
    AI_MyTimerReset_LENGTH,
    AI_MyTimerPause_LENGTH,
    AI_MyTimerResume_LENGTH,
    AI_IFMyTimerIsNotRunning_LENGTH,
    AI_IFMyTimerLessThanTicks_LENGTH,
    AI_IFMyTimerGreaterThanTicks_LENGTH,
    AI_HudCountdownShow_LENGTH,
    AI_HudCountdownHide_LENGTH,
    AI_HudCountdownSet_LENGTH,
    AI_HudCountdownStop_LENGTH,
    AI_HudCountdownStart_LENGTH,
    AI_IFHudCountdownIsNotRunning_LENGTH,
    AI_IFHudCountdownLessThan_LENGTH,
    AI_IFHudCountdownGreaterThan_LENGTH,
    AI_TRYSpawningChrAtPad_LENGTH,
    AI_TRYSpawningChrNextToChr_LENGTH,
    AI_TRYGiveMeItem_LENGTH,
    AI_TRYGiveMeHat_LENGTH,
    AI_TRYCloningChr_LENGTH,
    AI_TextPrintBottom_LENGTH,
    AI_TextPrintTop_LENGTH,
    AI_SfxPlay_LENGTH,
    AI_SfxEmitFromObject_LENGTH,
    AI_SfxEmitFromPad_LENGTH,
    AI_SfxSetChannelVolume_LENGTH,
    AI_SfxFadeChannelVolume_LENGTH,
    AI_SfxStopChannel_LENGTH,
    AI_IFSfxChannelVolumeLessThan_LENGTH,
    AI_VehicleStartPath_LENGTH,
    AI_VehicleSpeed_LENGTH,
    AI_AircraftRotorSpeed_LENGTH,
    AI_IFCameraIsInIntro_LENGTH,
    AI_IFCameraIsInBondSwirl_LENGTH,
    AI_TvChangeScreenBank_LENGTH,
    AI_IFBondInTank_LENGTH,
    AI_EndLevel_LENGTH,
    AI_CameraReturnToBond_LENGTH,
    AI_CameraLookAtBondFromPad_LENGTH,
    AI_CameraSwitch_LENGTH,
    AI_IFBondYPosLessThan_LENGTH,
    AI_BondDisableControl_LENGTH,
    AI_BondEnableControl_LENGTH,
    AI_TRYTeleportingChrToPad_LENGTH,
    AI_ScreenFadeToBlack_LENGTH,
    AI_ScreenFadeFromBlack_LENGTH,
    AI_IFScreenFadeCompleted_LENGTH,
    AI_HideAllChrs_LENGTH,
    AI_ShowAllChrs_LENGTH,
    AI_DoorOpenInstant_LENGTH,
    AI_ChrRemoveItemInHand_LENGTH,
    AI_IfNumberOfActivePlayersLessThan_LENGTH,
    AI_IFBondItemTotalAmmoLessThan_LENGTH,
    AI_BondEquipItem_LENGTH,
    AI_BondEquipItemCinema_LENGTH,
    AI_BondSetLockedVelocity_LENGTH,
    AI_IFObjectInRoomWithPad_LENGTH,
    AI_IFImFiringAndLockedForward_LENGTH,
    AI_IFImFiring_LENGTH,
    AI_SwitchSky_LENGTH,
    AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH,
    AI_IFBondIsDead_LENGTH,
    AI_BondDisableDamageAndPickups_LENGTH,
    AI_BondHideWeapons_LENGTH,
    AI_CameraOrbitPad_LENGTH,
    AI_CreditsRoll_LENGTH,
    AI_IFCreditsHasCompleted_LENGTH,
    AI_IFObjectiveAllCompleted_LENGTH,
    AI_IFFolderActorIsEqual_LENGTH,
    AI_IFBondDamageAndPickupsDisabled_LENGTH,
    AI_MusicPlaySlot_LENGTH,
    AI_MusicStopSlot_LENGTH,
    AI_TriggerExplosionsAroundBond_LENGTH,
    AI_IFKilledCiviliansGreaterThan_LENGTH,
    AI_IFChrWasShotSinceLastCheck_LENGTH,
    AI_BondKilledInAction_LENGTH,
    AI_RaiseArms_LENGTH,
    AI_GasLeakAndFadeFog_LENGTH,
    AI_ObjectRocketLaunch_LENGTH};

typedef enum AI_CMD
{
    AI_GotoNext,
    AI_GotoFirst,
    AI_Label,
    AI_Yield,
    AI_EndList,
    AI_SetChrAiList,
    AI_SetReturnAiList,
    AI_Return,
    AI_Stop,
    AI_Kneel,
    AI_PlayAnimation,
    AI_IFPlayingAnimation,
    AI_PointAtBond,
    AI_LookSurprised,
    AI_TRYSidestepping,
    AI_TRYSideHopping,
    AI_TRYSideRunning,
    AI_TRYFiringWalk,
    AI_TRYFiringRun,
    AI_TRYFiringRoll,
    AI_TRYFireOrAimAtTarget,
    AI_TRYFireOrAimAtTargetKneel,
    AI_TRYFireOrAimAtTargetUpdate,
    AI_TRYFacingTarget,
    AI_HitChrWithItem,
    AI_ChrHitChr,
    AI_TRYThrowingGrenade,
    AI_TRYDroppingItem,
    AI_RunToPad,
    AI_RunToPadPreset,
    AI_WalkToPad,
    AI_SprintToPad,
    AI_StartPatrol,
    AI_Surrender,
    AI_RemoveMe,
    AI_ChrRemoveInstant,
    AI_TRYTriggeringAlarmAtPad,
    AI_AlarmOn,
    AI_AlarmOff,
    AI_TRYRunFromBond,
    AI_TRYRunToBond,
    AI_TRYWalkToBond,
    AI_TRYSprintToBond,
    AI_TRYFindCover,
    AI_TRYRunToChr,
    AI_TRYWalkToChr,
    AI_TRYSprintToChr,
    AI_IFImOnPatrolOrStopped,
    AI_IFChrDyingOrDead,
    AI_IFChrDoesNotExist,
    AI_IFISeeBond,
    AI_SetNewRandom,
    AI_IFRandomLessThan,
    AI_IFRandomGreaterThan,
    AI_IFICanHearAlarm,
    AI_IFAlarmIsOn,
    AI_IFGasIsLeaking,
    AI_IFIHeardBond,
    AI_IFISeeSomeoneShot,
    AI_IFISeeSomeoneDie,
    AI_IFICouldSeeBond,
    AI_IFICouldSeeBondsStan,
    AI_IFIWasShotRecently,
    AI_IFIHeardBondRecently,
    AI_IFImInRoomWithChr,
    AI_IFIveNotBeenSeen,
    AI_IFImOnScreen,
    AI_IFMyRoomIsOnScreen,
    AI_IFRoomWithPadIsOnScreen,
    AI_IFImTargetedByBond,
    AI_IFBondMissedMe,
    AI_IFMyAngleToBondLessThan,
    AI_IFMyAngleToBondGreaterThan,
    AI_IFMyAngleFromBondLessThan,
    AI_IFMyAngleFromBondGreaterThan,
    AI_IFMyDistanceToBondLessThanDecimeter,
    AI_IFMyDistanceToBondGreaterThanDecimeter,
    AI_IFChrDistanceToPadLessThanDecimeter,
    AI_IFChrDistanceToPadGreaterThanDecimeter,
    AI_IFMyDistanceToChrLessThanDecimeter,
    AI_IFMyDistanceToChrGreaterThanDecimeter,
    AI_TRYSettingMyPresetToChrWithinDistanceDecimeter,
    AI_IFBondDistanceToPadLessThanDecimeter,
    AI_IFBondDistanceToPadGreaterThanDecimeter,
    AI_IFChrInRoomWithPad,
    AI_IFBondInRoomWithPad,
    AI_IFBondCollectedObject,
    AI_IFItemIsStationaryWithinLevel,
    AI_IFItemIsAttachedToObject,
    AI_IFBondHasItemEquipped,
    AI_IFObjectExists,
    AI_IFObjectNotDestroyed,
    AI_IFObjectWasActivated,
    AI_IFBondUsedGadgetOnObject,
    AI_ActivateObject,
    AI_DestroyObject,
    AI_DropObjectFromChr,
    AI_ChrDropAllConcealedItems,
    AI_ChrDropAllHeldItems,
    AI_BondCollectObject,
    AI_ChrEquipObject,
    AI_MoveObject,
    AI_DoorOpen,
    AI_DoorClose,
    AI_IFDoorStateEqual,
    AI_IFDoorHasBeenOpenedBefore,
    AI_DoorSetLock,
    AI_DoorUnsetLock,
    AI_IFDoorLockEqual,
    AI_IFObjectiveNumComplete,
    AI_TRYUnknown6e,
    AI_TRYUnknown6f,
    AI_IFGameDifficultyLessThan,
    AI_IFGameDifficultyGreaterThan,
    AI_IFMissionTimeLessThan,
    AI_IFMissionTimeGreaterThan,
    AI_IFSystemPowerTimeLessThan,
    AI_IFSystemPowerTimeGreaterThan,
    AI_IFLevelIdLessThan,
    AI_IFLevelIdGreaterThan,
    AI_IFMyNumArghsLessThan,
    AI_IFMyNumArghsGreaterThan,
    AI_IFMyNumCloseArghsLessThan,
    AI_IFMyNumCloseArghsGreaterThan,
    AI_IFChrHealthLessThan,
    AI_IFChrHealthGreaterThan,
    AI_IFChrWasDamagedSinceLastCheck,
    AI_IFBondHealthLessThan,
    AI_IFBondHealthGreaterThan,
    AI_SetMyMorale,
    AI_AddToMyMorale,
    AI_SubtractFromMyMorale,
    AI_IFMyMoraleLessThan,
    AI_IFMyMoraleLessThanRandom,
    AI_SetMyAlertness,
    AI_AddToMyAlertness,
    AI_SubtractFromMyAlertness,
    AI_IFMyAlertnessLessThan,
    AI_IFMyAlertnessLessThanRandom,
    AI_SetMyHearingScale,
    AI_SetMyVisionRange,
    AI_SetMyGrenadeProbability,
    AI_SetMyChrNum,
    AI_SetMyHealthTotal,
    AI_SetMyArmour,
    AI_SetMySpeedRating,
    AI_SetMyArghRating,
    AI_SetMyAccuracyRating,
    AI_SetMyFlags2,
    AI_UnsetMyFlags2,
    AI_IFMyFlags2Has,
    AI_SetChrBitfield,
    AI_UnsetChrBitfield,
    AI_IFChrBitfieldHas,
    AI_SetObjectiveBitfield,
    AI_UnsetObjectiveBitfield,
    AI_IFObjectiveBitfieldHas,
    AI_SetMychrflags,
    AI_UnsetMychrflags,
    AI_IFMychrflagsHas,
    AI_SetChrchrflags,
    AI_UnsetChrchrflags,
    AI_IFChrchrflagsHas,
    AI_SetObjectFlags,
    AI_UnsetObjectFlags,
    AI_IFObjectFlagsHas,
    AI_SetObjectFlags2,
    AI_UnsetObjectFlags2,
    AI_IFObjectFlags2Has,
    AI_SetMyChrPreset,
    AI_SetChrChrPreset,
    AI_SetMyPadPreset,
    AI_SetChrPadPreset,
    AI_PRINT,
    AI_MyTimerStart,
    AI_MyTimerReset,
    AI_MyTimerPause,
    AI_MyTimerResume,
    AI_IFMyTimerIsNotRunning,
    AI_IFMyTimerLessThanTicks,
    AI_IFMyTimerGreaterThanTicks,
    AI_HudCountdownShow,
    AI_HudCountdownHide,
    AI_HudCountdownSet,
    AI_HudCountdownStop,
    AI_HudCountdownStart,
    AI_IFHudCountdownIsNotRunning,
    AI_IFHudCountdownLessThan,
    AI_IFHudCountdownGreaterThan,
    AI_TRYSpawningChrAtPad,
    AI_TRYSpawningChrNextToChr,
    AI_TRYGiveMeItem,
    AI_TRYGiveMeHat,
    AI_TRYCloningChr,
    AI_TextPrintBottom,
    AI_TextPrintTop,
    AI_SfxPlay,
    AI_SfxEmitFromObject,
    AI_SfxEmitFromPad,
    AI_SfxSetChannelVolume,
    AI_SfxFadeChannelVolume,
    AI_SfxStopChannel,
    AI_IFSfxChannelVolumeLessThan,
    AI_VehicleStartPath,
    AI_VehicleSpeed,
    AI_AircraftRotorSpeed,
    AI_IFCameraIsInIntro,
    AI_IFCameraIsInBondSwirl,
    AI_TvChangeScreenBank,
    AI_IFBondInTank,
    AI_EndLevel,
    AI_CameraReturnToBond,
    AI_CameraLookAtBondFromPad,
    AI_CameraSwitch,
    AI_IFBondYPosLessThan,
    AI_BondDisableControl,
    AI_BondEnableControl,
    AI_TRYTeleportingChrToPad,
    AI_ScreenFadeToBlack,
    AI_ScreenFadeFromBlack,
    AI_IFScreenFadeCompleted,
    AI_HideAllChrs,
    AI_ShowAllChrs,
    AI_DoorOpenInstant,
    AI_ChrRemoveItemInHand,
    AI_IfNumberOfActivePlayersLessThan,
    AI_IFBondItemTotalAmmoLessThan,
    AI_BondEquipItem,
    AI_BondEquipItemCinema,
    AI_BondSetLockedVelocity,
    AI_IFObjectInRoomWithPad,
    AI_IFImFiringAndLockedForward,
    AI_IFImFiring,
    AI_SwitchSky,
    AI_TriggerFadeAndExitLevelOnButtonPress,
    AI_IFBondIsDead,
    AI_BondDisableDamageAndPickups,
    AI_BondHideWeapons,
    AI_CameraOrbitPad,
    AI_CreditsRoll,
    AI_IFCreditsHasCompleted,
    AI_IFObjectiveAllCompleted,
    AI_IFFolderActorIsEqual,
    AI_IFBondDamageAndPickupsDisabled,
    AI_MusicPlaySlot,
    AI_MusicStopSlot,
    AI_TriggerExplosionsAroundBond,
    AI_IFKilledCiviliansGreaterThan,
    AI_IFChrWasShotSinceLastCheck,
    AI_BondKilledInAction,
    AI_RaiseArms,
    AI_GasLeakAndFadeFog,
    AI_ObjectRocketLaunch,
    AI_CMD_COUNT
} AI_CMD;

char *AI_CMD_ToString[] = {
    "GotoNext",
    "GotoFirst",
    "Label",
    "Yield",
    "EndList",
    "SetChrAiList",
    "SetReturnAiList",
    "Return",
    "Stop",
    "Kneel",
    "PlayAnimation",
    "IFPlayingAnimation",
    "PointAtBond",
    "LookSurprised",
    "TRYSidestepping",
    "TRYSideHopping",
    "TRYSideRunning",
    "TRYFiringWalk",
    "TRYFiringRun",
    "TRYFiringRoll",
    "TRYFireOrAimAtTarget",
    "TRYFireOrAimAtTargetKneel",
    "TRYFireOrAimAtTargetUpdate",
    "TRYFacingTarget",
    "HitChrWithItem",
    "ChrHitChr",
    "TRYThrowingGrenade",
    "TRYDroppingItem",
    "RunToPad",
    "RunToPadPreset",
    "WalkToPad",
    "SprintToPad",
    "StartPatrol",
    "Surrender",
    "RemoveMe",
    "ChrRemoveInstant",
    "TRYTriggeringAlarmAtPad",
    "AlarmOn",
    "AlarmOff",
    "TRYRunFromBond",
    "TRYRunToBond",
    "TRYWalkToBond",
    "TRYSprintToBond",
    "TRYFindCover",
    "TRYRunToChr",
    "TRYWalkToChr",
    "TRYSprintToChr",
    "IFImOnPatrolOrStopped",
    "IFChrDyingOrDead",
    "IFChrDoesNotExist",
    "IFISeeBond",
    "SetNewRandom",
    "IFRandomLessThan",
    "IFRandomGreaterThan",
    "IFICanHearAlarm",
    "IFAlarmIsOn",
    "IFGasIsLeaking",
    "IFIHeardBond",
    "IFISeeSomeoneShot",
    "IFISeeSomeoneDie",
    "IFICouldSeeBond",
    "IFICouldSeeBondsStan",
    "IFIWasShotRecently",
    "IFIHeardBondRecently",
    "IFImInRoomWithChr",
    "IFIveNotBeenSeen",
    "IFImOnScreen",
    "IFMyRoomIsOnScreen",
    "IFRoomWithPadIsOnScreen",
    "IFImTargetedByBond",
    "IFBondMissedMe",
    "IFMyAngleToBondLessThan",
    "IFMyAngleToBondGreaterThan",
    "IFMyAngleFromBondLessThan",
    "IFMyAngleFromBondGreaterThan",
    "IFMyDistanceToBondLessThanDecimeter",
    "IFMyDistanceToBondGreaterThanDecimeter",
    "IFChrDistanceToPadLessThanDecimeter",
    "IFChrDistanceToPadGreaterThanDecimeter",
    "IFMyDistanceToChrLessThanDecimeter",
    "IFMyDistanceToChrGreaterThanDecimeter",
    "TRYSettingMyPresetToChrWithinDistanceDecimeter",
    "IFBondDistanceToPadLessThanDecimeter",
    "IFBondDistanceToPadGreaterThanDecimeter",
    "IFChrInRoomWithPad",
    "IFBondInRoomWithPad",
    "IFBondCollectedObject",
    "IFItemIsStationaryWithinLevel",
    "IFItemIsAttachedToObject",
    "IFBondHasItemEquipped",
    "IFObjectExists",
    "IFObjectNotDestroyed",
    "IFObjectWasActivated",
    "IFBondUsedGadgetOnObject",
    "ActivateObject",
    "DestroyObject",
    "DropObjectFromChr",
    "ChrDropAllConcealedItems",
    "ChrDropAllHeldItems",
    "BondCollectObject",
    "ChrEquipObject",
    "MoveObject",
    "DoorOpen",
    "DoorClose",
    "IFDoorStateEqual",
    "IFDoorHasBeenOpenedBefore",
    "DoorSetLock",
    "DoorUnsetLock",
    "IFDoorLockEqual",
    "IFObjectiveNumComplete",
    "TRYUnknown6e",
    "TRYUnknown6f",
    "IFGameDifficultyLessThan",
    "IFGameDifficultyGreaterThan",
    "IFMissionTimeLessThan",
    "IFMissionTimeGreaterThan",
    "IFSystemPowerTimeLessThan",
    "IFSystemPowerTimeGreaterThan",
    "IFLevelIdLessThan",
    "IFLevelIdGreaterThan",
    "IFMyNumArghsLessThan",
    "IFMyNumArghsGreaterThan",
    "IFMyNumCloseArghsLessThan",
    "IFMyNumCloseArghsGreaterThan",
    "IFChrHealthLessThan",
    "IFChrHealthGreaterThan",
    "IFChrWasDamagedSinceLastCheck",
    "IFBondHealthLessThan",
    "IFBondHealthGreaterThan",
    "SetMyMorale",
    "AddToMyMorale",
    "SubtractFromMyMorale",
    "IFMyMoraleLessThan",
    "IFMyMoraleLessThanRandom",
    "SetMyAlertness",
    "AddToMyAlertness",
    "SubtractFromMyAlertness",
    "IFMyAlertnessLessThan",
    "IFMyAlertnessLessThanRandom",
    "SetMyHearingScale",
    "SetMyVisionRange",
    "SetMyGrenadeProbability",
    "SetMyChrNum",
    "SetMyHealthTotal",
    "SetMyArmour",
    "SetMySpeedRating",
    "SetMyArghRating",
    "SetMyAccuracyRating",
    "SetMyFlags2",
    "UnsetMyFlags2",
    "IFMyFlags2Has",
    "SetChrBitfield",
    "UnsetChrBitfield",
    "IFChrBitfieldHas",
    "SetObjectiveBitfield",
    "UnsetObjectiveBitfield",
    "IFObjectiveBitfieldHas",
    "SetMychrflags",
    "UnsetMychrflags",
    "IFMychrflagsHas",
    "SetChrchrflags",
    "UnsetChrchrflags",
    "IFChrchrflagsHas",
    "SetObjectFlags",
    "UnsetObjectFlags",
    "IFObjectFlagsHas",
    "SetObjectFlags2",
    "UnsetObjectFlags2",
    "IFObjectFlags2Has",
    "SetMyChrPreset",
    "SetChrChrPreset",
    "SetMyPadPreset",
    "SetChrPadPreset",
    "PRINT",
    "MyTimerStart",
    "MyTimerReset",
    "MyTimerPause",
    "MyTimerResume",
    "IFMyTimerIsNotRunning",
    "IFMyTimerLessThanTicks",
    "IFMyTimerGreaterThanTicks",
    "HudCountdownShow",
    "HudCountdownHide",
    "HudCountdownSet",
    "HudCountdownStop",
    "HudCountdownStart",
    "IFHudCountdownIsNotRunning",
    "IFHudCountdownLessThan",
    "IFHudCountdownGreaterThan",
    "TRYSpawningChrAtPad",
    "TRYSpawningChrNextToChr",
    "TRYGiveMeItem",
    "TRYGiveMeHat",
    "TRYCloningChr",
    "TextPrintBottom",
    "TextPrintTop",
    "SfxPlay",
    "SfxEmitFromObject",
    "SfxEmitFromPad",
    "SfxSetChannelVolume",
    "SfxFadeChannelVolume",
    "SfxStopChannel",
    "IFSfxChannelVolumeLessThan",
    "VehicleStartPath",
    "VehicleSpeed",
    "AircraftRotorSpeed",
    "IFCameraIsInIntro",
    "IFCameraIsInBondSwirl",
    "TvChangeScreenBank",
    "IFBondInTank",
    "EndLevel",
    "CameraReturnToBond",
    "CameraLookAtBondFromPad",
    "CameraSwitch",
    "IFBondYPosLessThan",
    "BondDisableControl",
    "BondEnableControl",
    "TRYTeleportingChrToPad",
    "ScreenFadeToBlack",
    "ScreenFadeFromBlack",
    "IFScreenFadeCompleted",
    "HideAllChrs",
    "ShowAllChrs",
    "DoorOpenInstant",
    "ChrRemoveItemInHand",
    "IfNumberOfActivePlayersLessThan",
    "IFBondItemTotalAmmoLessThan",
    "BondEquipItem",
    "BondEquipItemCinema",
    "BondSetLockedVelocity",
    "IFObjectInRoomWithPad",
    "IFImFiringAndLockedForward",
    "IFImFiring",
    "SwitchSky",
    "TriggerFadeAndExitLevelOnButtonPress",
    "IFBondIsDead",
    "BondDisableDamageAndPickups",
    "BondHideWeapons",
    "CameraOrbitPad",
    "CreditsRoll",
    "IFCreditsHasCompleted",
    "IFObjectiveAllCompleted",
    "IFFolderActorIsEqual",
    "IFBondDamageAndPickupsDisabled",
    "MusicPlaySlot",
    "MusicStopSlot",
    "TriggerExplosionsAroundBond",
    "IFKilledCiviliansGreaterThan",
    "IFChrWasShotSinceLastCheck",
    "BondKilledInAction",
    "RaiseArms",
    "GasLeakAndFadeFog",
    "ObjectRocketLaunch"};

#define MAX 10

int  top = -1;
char stack[MAX];

/*PUSH FUNCTION*/
int  push(int item)
{
    if (top == (MAX - 1))
    {
        return 0;
    }
    else
    {
        ++top;
        stack[top] = item;
        return 1;
    }
}

/*POP */
int pop()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        --top;
        return stack[top + 1];
    }
}

/*Sniff */
int sniff()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        return stack[top];
    }
}

void displayStack()
{
    int i;

    printf("\nThe label Stack is: ");

    if (top == -1)
    {
        printf("empty");
    }
    else
    {
        for (i = top; i >= 0; --i)
        {
            printf("\n%3d", stack[i]);
        }
    }

    printf("\n---------------\n\n");
}

/**
 * @brief Parse AI list and print out C Macros
 * @param AiList: Bytestream for ai
 * @param ID: List ID
 */
void ai(unsigned char *AiList, short ID)
{
    for (int Offset = 0;;)
    {
        char tabs[MAX + 1];
        for (int k = 0; k < MAX; k++)
        {
            tabs[k] = 0;
        }
        for (int k = 0; k < top + 2 && k < MAX; k++)
        {
            tabs[k] = '\t';
        }

        switch (AiList[Offset])
        {
            case AI_GotoNext:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n\n");
                Offset += AI_GotoNext_LENGTH;
                break;
            }
            case AI_GotoFirst:
            {
                if (AiList[Offset + 1] == sniff())
                {
                    pop();
                    for (int k = top + 2; k < MAX; k++)
                    {
                        tabs[k] = 0;
                    }
                    printf("%sLOOP(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                }

                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n\n");
                Offset += AI_GotoFirst_LENGTH;
                break;
            }
            case AI_Label:
            {
                if (AiList[Offset + 2] == AI_Yield)
                {
                    if (AiList[Offset + 3] != AI_GotoFirst)
                    {
                        push(AiList[Offset + 1]);
                        printf("\n%sDO(", tabs);
                        printf("lbl%d", AiList[Offset + 1]);
                        Offset += AI_Yield_LENGTH;
                    }
                    else
                    {
                        printf("\n%sYIELD_FOREVER(", tabs);
                        printf("lbl%d", AiList[Offset + 1]);
                        Offset += AI_Yield_LENGTH + AI_GotoFirst_LENGTH;
                    }
                }
                else
                {
                    printf("\n%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("lbl%d", AiList[Offset + 1]);
                }
                printf(")\n");
                Offset += AI_Label_LENGTH;
                break;
            }
            case AI_Yield:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Yield_LENGTH;
                break;
            }
            case AI_EndList:
            {
                printf("\n%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n\n");
                return;
            }
            case AI_SetChrAiList:
            {
                unsigned short AI_LIST_ID = CharArrayTo16(AiList, (Offset + 1 + 1)); /* This is the only way to match despite assetrs below */
                signed char    CHR_NUM    = AiList[Offset + 1];

                if (CHR_NUM == CHR_SELF)
                {
                    if (AiList[Offset - AI_SetReturnAiList_LENGTH] == AI_SetReturnAiList &&
                        CharArrayTo16(AiList, Offset + 1 - AI_SetReturnAiList_LENGTH) == ID)
                    {
                        printf("%sCALL(", tabs);
                    }
                    else
                    {
                        printf("%sJumpTo(", tabs);
                    }
                }
                else if (CHR_NUM == CHR_BOND_CINEMA)
                {
                    printf("%sSetBondsAiList(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,", CHR_NUM);
                }

                if (isGlobalAIListID(AI_LIST_ID))
                {
                    printf("%s", GAILIST_ToString[AI_LIST_ID]);
                }
                else if (isBGAIListID(AI_LIST_ID))
                {
                    printf("setBGAIListID(%d)", getBGAIListID(AI_LIST_ID));
                }
                else
                {
                    printf("setChrAIListID(%d)", getChrAIListID(AI_LIST_ID));
                }
                printf(")\n");
                Offset += AI_SetChrAiList_LENGTH;
                break;
            }
            case AI_SetReturnAiList:
            {
                unsigned short AI_LIST_ID = CharArrayTo16(AiList, (Offset + 1));

                if (!(AiList[Offset + AI_SetReturnAiList_LENGTH] == AI_SetChrAiList &&
                      AI_LIST_ID == ID &&
                      (signed char)AiList[Offset + AI_SetReturnAiList_LENGTH + 1] == CHR_SELF))
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d", AI_LIST_ID);
                    printf(")\n");
                }
                Offset += AI_SetReturnAiList_LENGTH;
                break;
            }
            case AI_Return:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Return_LENGTH;
                ;
                break;
            }
            case AI_Stop:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Stop_LENGTH;
                break;
            }
            case AI_Kneel:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Kneel_LENGTH;
                break;
            }
            case AI_PlayAnimation:
            {
                int startframe, anim_id, zero, endframe;

                anim_id    = CharArrayTo16(AiList, Offset + 1 + 0);
                startframe = CharArrayTo16(AiList, Offset + 1 + 2);
                endframe   = CharArrayTo16(AiList, Offset + 1 + 4);
                if (startframe == -1 && endframe == -1 && AiList[Offset + 1 + 6] == 6 && AiList[Offset + 1 + 7] == 16)
                {
                    printf("%sPlayAnimationSimple(", tabs);
                    printf("%d", anim_id);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,%d,%d,%d", anim_id, startframe, endframe, AiList[Offset + 1 + 6], AiList[Offset + 1 + 7]);
                }
                printf(")\n");
                Offset += AI_PlayAnimation_LENGTH;
                break;
            }
            case AI_IFPlayingAnimation:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFPlayingAnimation_LENGTH;
                break;
            }
            case AI_PointAtBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_PointAtBond_LENGTH;
                break;
            }
            case AI_LookSurprised:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_LookSurprised_LENGTH;
                break;
            }
            case AI_IFImOnPatrolOrStopped:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImOnPatrolOrStopped_LENGTH;
                break;
            }
            case AI_IFChrDyingOrDead:
            {
                signed char chr = AiList[Offset + 1];
                if (chr == CHR_SELF)
                {
                    printf("%sIFImDyingOrDead(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,", chr);
                }
                printf("lbl%d", AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFChrDyingOrDead_LENGTH;
                break;
            }
            case AI_IFChrDoesNotExist:
            {
                signed char chr = AiList[Offset + 1];
                if (chr == CHR_SELF)
                {
                    printf("%sIFIDoNotExist(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,", chr);
                }
                printf("lbl%d", AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFChrDoesNotExist_LENGTH;
                break;
            }
            case AI_IFISeeBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFISeeBond_LENGTH;
                break;
            }

            case AI_TRYSidestepping:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYSidestepping_LENGTH;
                break;
            }
            case AI_TRYSideHopping:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYSideHopping_LENGTH;

                break;
            }
            case AI_TRYSideRunning:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYSideRunning_LENGTH;
                break;
            }
            case AI_TRYFiringWalk:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYFiringWalk_LENGTH;
                break;
            }
            case AI_TRYFiringRun:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYFiringRun_LENGTH;
                break;
            }
            case AI_TRYFiringRoll:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYFiringRoll_LENGTH;
                break;
            }
            case AI_TRYFireOrAimAtTarget:
            {
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == 1)
                {
                    printf("%sTRYFireAtBond(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 4)
                {
                    printf("%sTRYFireAtPad(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 33)
                {
                    printf("%sTRYAimAtBond(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 36)
                {
                    printf("%sTRYAimAtPad(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,lbl%d", targettype, targetid, AiList[Offset + 5]);
                }
                printf(")\n");
                Offset += AI_TRYFireOrAimAtTarget_LENGTH;
                break;
            }
            case AI_TRYFireOrAimAtTargetKneel:
            {
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == 1)
                {
                    printf("%sTRYFireAtBondKneeling(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 4)
                {
                    printf("%sTRYFireAtPadKneeling(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 33)
                {
                    printf("%sTRYAimAtBondKneeling(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 36)
                {
                    printf("%sTRYAimAtPadKneeling(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,lbl%d", targettype, targetid, AiList[Offset + 5]);
                }
                printf(")\n");
                Offset += AI_TRYFireOrAimAtTargetKneel_LENGTH;
                break;
            }
            case AI_IFImFiringAndLockedForward:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImFiringAndLockedForward_LENGTH;
                break;
            }
            case AI_IFImFiring:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImFiring_LENGTH;
                break;
            }

            case AI_TRYFireOrAimAtTargetUpdate:
            {
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == 1)
                {
                    printf("%sTRYFireAtBondUpdate(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 4)
                {
                    printf("%sTRYFireAtPadUpdate(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 33)
                {
                    printf("%sTRYAimAtBondUpdate(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 36)
                {
                    printf("%sTRYAimAtPadUpdate(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,lbl%d", targettype, targetid, AiList[Offset + 5]);
                }
                printf(")\n");
                Offset += AI_TRYFireOrAimAtTargetUpdate_LENGTH;
                break;
            }
            case AI_TRYFacingTarget:
            {
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == 1)
                {
                    printf("%sTRYFacingBond(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 4)
                {
                    printf("%sTRYFacingPad(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,lbl%d", targettype, targetid, AiList[Offset + 5]);
                }
                printf(")\n");
                Offset += AI_TRYFacingTarget_LENGTH;
                break;
            }
            case AI_HitChrWithItem:
            {
                if (AiList[Offset + 1] == CHR_SELF)
                {
                    printf("%sHitMeWithItem(", tabs);
                    printf("%d,%d", AiList[Offset + 2], AiList[Offset + 1 + 2]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,%d", AiList[Offset + 1], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);
                }
                printf(")\n");

                Offset += AI_HitChrWithItem_LENGTH;
                break;
            }
            case AI_ChrHitChr:
            {
                if ((signed char)AiList[Offset + 1] == CHR_SELF)
                {
                    printf("%sIHitChr(", tabs);
                    printf("%d,%d", AiList[Offset + 2], AiList[Offset + 1 + 2]);
                }
                else if ((signed char)AiList[Offset + 2] == CHR_SELF)
                {
                    printf("%sChrHitMe(", tabs);
                    printf("%d,%d", AiList[Offset + 1], AiList[Offset + 1 + 2]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,%d", AiList[Offset + 1], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);
                }
                printf(")\n");

                Offset += AI_ChrHitChr_LENGTH;
                break;
            }
            case AI_TRYThrowingGrenade:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_TRYThrowingGrenade_LENGTH;
                break;
            }
            case AI_TRYDroppingItem:
            {
                unsigned short modelnum = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,lbl%d", modelnum, AiList[Offset + 1 + 2], AiList[Offset + 1 + 3]);
                printf(")\n");
                Offset += AI_TRYDroppingItem_LENGTH;
                break;
            }

            case AI_Surrender:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Surrender_LENGTH;
                break;
            }
            case AI_RemoveMe:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_RemoveMe_LENGTH;
                break;
            }
            case AI_ChrRemoveInstant:
            {
                if ((signed char)AiList[Offset + 1] == CHR_SELF)
                {
                    printf("%sRemoveMeInstantly(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d", AiList[Offset + 1]);
                }
                printf(")\n");
                Offset += AI_ChrRemoveInstant_LENGTH;
                break;
            }
            case AI_TRYTriggeringAlarmAtPad:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d", AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_TRYTriggeringAlarmAtPad_LENGTH;
                break;
            }
            case AI_AlarmOn:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_AlarmOn_LENGTH;
                break;
            }
            case AI_AlarmOff:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_AlarmOff_LENGTH;
                break;
            }
            case AI_TRYRunFromBond:
            { // run from bond

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYRunFromBond_LENGTH;
                break;
            }
            case AI_TRYRunToBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYRunToBond_LENGTH;
                break;
            }
            case AI_TRYWalkToBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_TRYWalkToBond_LENGTH;
                break;
            }
            case AI_TRYSprintToBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYSprintToBond_LENGTH;
                break;
            }
            case AI_TRYFindCover:
            { // Find Cover
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYFindCover_LENGTH;
                break;
            }
            case AI_TRYRunToChr:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYRunToChr_LENGTH;
                break;
            }
            case AI_TRYWalkToChr:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYWalkToChr_LENGTH;
                break;
            }
            case AI_TRYSprintToChr:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYSprintToChr_LENGTH;
                break;
            }

            case AI_SetNewRandom:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_SetNewRandom_LENGTH;
                break;
            }
            case AI_IFRandomLessThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFRandomLessThan_LENGTH;
                break;
            }
            case AI_IFRandomGreaterThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFRandomGreaterThan_LENGTH;
                break;
            }

            case AI_RunToPad:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_RunToPad_LENGTH;
                break;
            }
            case AI_RunToPadPreset:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_RunToPadPreset_LENGTH;
                break;
            }
            case AI_WalkToPad:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_WalkToPad_LENGTH;
                break;
            }
            case AI_SprintToPad:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_SprintToPad_LENGTH;
                break;
            }
            case AI_StartPatrol:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_StartPatrol_LENGTH;
                break;
            }
            case AI_IFICanHearAlarm:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFICanHearAlarm_LENGTH;
                break;
            }
            case AI_IFAlarmIsOn:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFAlarmIsOn_LENGTH;
                break;
            }
            case AI_IFGasIsLeaking:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFGasIsLeaking_LENGTH;
                break;
            }
            case AI_IFIHeardBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFIHeardBond_LENGTH;
                break;
            }
            case AI_IFISeeSomeoneShot:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFISeeSomeoneShot_LENGTH;
                break;
            }
            case AI_IFISeeSomeoneDie:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFISeeSomeoneDie_LENGTH;
                break;
            }
            case AI_IFICouldSeeBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFICouldSeeBond_LENGTH;
                break;
            }
            case AI_IFICouldSeeBondsStan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFICouldSeeBondsStan_LENGTH;
                break;
            }
            case AI_IFIWasShotRecently:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFIWasShotRecently_LENGTH;
                break;
            }
            case AI_IFIHeardBondRecently:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFIHeardBondRecently_LENGTH;
                break;
            }
            case AI_IFImInRoomWithChr:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFImInRoomWithChr_LENGTH;
                break;
            }
            case AI_IFIveNotBeenSeen:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFIveNotBeenSeen_LENGTH;
                break;
            }
            case AI_IFImOnScreen:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImOnScreen_LENGTH;
                break;
            }
            case AI_IFMyRoomIsOnScreen:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFMyRoomIsOnScreen_LENGTH;
                break;
            }
            case AI_IFRoomWithPadIsOnScreen:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 3]);
                Offset += AI_IFRoomWithPadIsOnScreen_LENGTH;
                break;
            }
            case AI_IFImTargetedByBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImTargetedByBond_LENGTH;
                break;
            }
            case AI_IFBondMissedMe:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFBondMissedMe_LENGTH;
                break;
            }
            case AI_IFMyAngleToBondLessThan:
            {
                printf("%s%sDeg(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))), AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAngleToBondLessThan_LENGTH;
                break;
            }
            case AI_IFMyAngleToBondGreaterThan:
            {
                printf("%s%sDeg(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))), AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAngleToBondGreaterThan_LENGTH;
                break;
            }
            case AI_IFMyAngleFromBondLessThan:
            {
                printf("%s%sDeg(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))), AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAngleFromBondLessThan_LENGTH;
                break;
            }
            case AI_IFMyAngleFromBondGreaterThan:
            {
                printf("%s%sDeg(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))), AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAngleFromBondGreaterThan_LENGTH;
                break;
            }
            case AI_IFMyDistanceToBondLessThanDecimeter:
            {
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "IFMyDistanceToBondLessThanMeter");
                printf("%f,lbl%d", distance / 100, AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFMyDistanceToBondLessThanDecimeter_LENGTH;
                break;
            }
            case AI_IFMyDistanceToBondGreaterThanDecimeter:
            {
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "IFMyDistanceToBondGreaterThanMeter");
                printf("%f,lbl%d", distance / 100, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH;
                break;
            }
            case AI_IFChrDistanceToPadLessThanDecimeter:
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 3);
                float          value = CharArrayTo16(AiList, Offset + 1 + 1) * 10.0f;

                if ((signed char)AiList[Offset + 1 + 0] == CHR_SELF)
                {
                    printf("%sIFMyDistanceToPadLessThanMeter(", tabs);
                    printf("%f,", value / 100);
                }
                else
                {
                    printf("%sIFChrDistanceToPadLessThanMeter(", tabs);
                    printf("%d,%f,", AiList[Offset + 1 + 0], value / 100);
                }
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d", AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFChrDistanceToPadLessThanDecimeter_LENGTH;
                break;
            }
            case AI_IFChrDistanceToPadGreaterThanDecimeter:
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 3);
                float          value = CharArrayTo16(AiList, Offset + 1 + 1) * 10.0f;

                if ((signed char)AiList[Offset + 1 + 0] == CHR_SELF)
                {
                    printf("%sIFMyDistanceToPadGreaterThanMeter(", tabs);
                    printf("%f,", value / 100);
                }
                else
                {
                    printf("%sIFChrDistanceToPadGreaterThanMeter(", tabs);
                    printf("%d,%f,", AiList[Offset + 1 + 0], value / 100);
                }
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d", AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH;
                break;
            }
            case AI_IFMyDistanceToChrLessThanDecimeter:
            {
                float cutoff = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "AIFMyDistanceToChrLessThanMeter");
                printf("%f,%d,lbl%d", cutoff / 100, AiList[Offset + 3], AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFMyDistanceToChrLessThanDecimeter_LENGTH;
                break;
            }
            case AI_IFMyDistanceToChrGreaterThanDecimeter:
            {
                float cutoff = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "AIFMyDistanceToChrGreaterThanMeter");
                printf("%f,%d,lbl%d", cutoff / 100, AiList[Offset + 3], AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH;
                break;
            }
            case AI_TRYSettingMyPresetToChrWithinDistanceDecimeter:
            {
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "TRYSettingMyPresetToChrWithinDistanceMeter");
                printf("%f,lbl%d", distance / 100, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH;
                break;
            }
            case AI_IFBondDistanceToPadLessThanDecimeter:
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 2);
                float          value = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "IFBondDistanceToPadLessThanMeter");
                printf("%f,", value / 100);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 5]);
                Offset += AI_IFBondDistanceToPadLessThanDecimeter_LENGTH;
                break;
            }
            case AI_IFBondDistanceToPadGreaterThanDecimeter:
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 2);
                float          value = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "IFBondDistanceToPadGreaterThanMeter");
                printf("%f,", value / 100);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 5]);
                Offset += AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH;
                break;
            }
            case AI_IFChrInRoomWithPad:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1 + 0]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 4]);
                Offset += AI_IFChrInRoomWithPad_LENGTH;
                break;
            }
            case AI_IFBondInRoomWithPad:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 3]);
                Offset += AI_IFBondInRoomWithPad_LENGTH;
                break;
            }
            case AI_IFBondCollectedObject:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFBondCollectedObject_LENGTH;
                break;
            }
            case AI_IFItemIsStationaryWithinLevel:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFItemIsStationaryWithinLevel_LENGTH;
                break;
            }
            case AI_IFItemIsAttachedToObject:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFItemIsAttachedToObject_LENGTH;
                break;
            }
            case AI_IFBondHasItemEquipped:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFBondHasItemEquipped_LENGTH;
                break;
            }
            case AI_IFObjectExists:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFObjectExists_LENGTH;
                break;
            }
            case AI_IFObjectNotDestroyed:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_IFObjectNotDestroyed_LENGTH;
                break;
            }
            case AI_IFObjectWasActivated:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_IFObjectWasActivated_LENGTH;
                break;
            }
            case AI_IFBondUsedGadgetOnObject:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_IFBondUsedGadgetOnObject_LENGTH;
                break;
            }
            case AI_ActivateObject:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_ActivateObject_LENGTH;
                break;
            }
            case AI_DestroyObject: // canonicly destroyobj
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_DestroyObject_LENGTH;
                break;
            }
            case AI_DropObjectFromChr:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_DropObjectFromChr_LENGTH;
                break;
            }
            case AI_ChrDropAllConcealedItems:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_ChrDropAllConcealedItems_LENGTH;
                break;
            }
            case AI_ChrDropAllHeldItems:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_ChrDropAllHeldItems_LENGTH;
                break;
            }
            case AI_BondCollectObject:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_BondCollectObject_LENGTH;
                break;
            }
            case AI_ChrEquipObject:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_ChrEquipObject_LENGTH;
                break;
            }
            case AI_MoveObject: // canonicly aiMoveObj
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                Offset += AI_MoveObject_LENGTH;
                break;
            }
            case AI_DoorOpen:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_DoorOpen_LENGTH;
                break;
            }
            case AI_DoorClose:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_DoorClose_LENGTH;
                break;
            }
            case AI_IFDoorStateEqual:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%s,lbl%d", AiList[Offset + 1], DOORSTATE_ToString[AiList[Offset + 2] >> 1], AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFDoorStateEqual_LENGTH;
                break;
            }
            case AI_IFDoorHasBeenOpenedBefore:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFDoorHasBeenOpenedBefore_LENGTH;
                break;
            }
            case AI_DoorSetLock:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_DoorSetLock_LENGTH;
                break;
            }
            case AI_DoorUnsetLock:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_DoorUnsetLock_LENGTH;
                break;
            }
            case AI_IFDoorLockEqual:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFDoorLockEqual_LENGTH;
                break;
            }
            case AI_IFObjectiveNumComplete:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFObjectiveNumComplete_LENGTH;
                break;
            }
            case AI_TRYUnknown6e:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYUnknown6e_LENGTH;
                break;
            }
            case AI_TRYUnknown6f:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYUnknown6f_LENGTH;
                break;
            }

            case AI_IFMyNumArghsLessThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyNumArghsLessThan_LENGTH;
                break;
            }
            case AI_IFMyNumArghsGreaterThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyNumArghsGreaterThan_LENGTH;
                break;
            }
            case AI_IFMyNumCloseArghsLessThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyNumCloseArghsLessThan_LENGTH;
                break;
            }
            case AI_IFMyNumCloseArghsGreaterThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyNumCloseArghsGreaterThan_LENGTH;
                break;
            }
            case AI_IFChrHealthLessThan:
            {
                float value = (AiList[Offset + 1 + 1]) * 0.1f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%f,lbl%d", AiList[Offset + 1], value * 10, AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFChrHealthLessThan_LENGTH;
                break;
            }
            case AI_IFChrHealthGreaterThan:
            {
                float value = (AiList[Offset + 1 + 1]) * 0.1f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%f,lbl%d", AiList[Offset + 1], value * 10, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFChrHealthGreaterThan_LENGTH;
                break;
            }
            case AI_IFChrWasDamagedSinceLastCheck:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFChrWasDamagedSinceLastCheck_LENGTH;
                break;
            }
            case AI_IFBondHealthLessThan:
            {
                float val = (AiList[Offset + 1 + 0]) / 255.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", val * 255, AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFBondHealthLessThan_LENGTH;
                break;
            }
            case AI_IFBondHealthGreaterThan:
            {
                float val = (AiList[Offset + 1 + 0]) / 255.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", val * 255, AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFBondHealthGreaterThan_LENGTH;
                break;
            }
            case AI_IFGameDifficultyLessThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFGameDifficultyLessThan_LENGTH;
                break;
            }
            case AI_IFGameDifficultyGreaterThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFGameDifficultyGreaterThan_LENGTH;
                break;
            }
            case AI_IFMissionTimeLessThan:
            {
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", target, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFMissionTimeLessThan_LENGTH;
                break;
            }
            case AI_IFMissionTimeGreaterThan:
            {
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", target, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFMissionTimeGreaterThan_LENGTH;
                break;
            }
            case AI_IFSystemPowerTimeLessThan:
            {
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,%d", target, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFSystemPowerTimeLessThan_LENGTH;
                break;
            }
            case AI_IFSystemPowerTimeGreaterThan:
            {
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", target, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFSystemPowerTimeGreaterThan_LENGTH;
                break;
            }
            case AI_IFLevelIdLessThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFLevelIdLessThan_LENGTH;
                break;
            }
            case AI_IFLevelIdGreaterThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFLevelIdGreaterThan_LENGTH;
                break;
            }
            case AI_SetMyMorale:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyMorale_LENGTH;
                break;
            }
            case AI_AddToMyMorale:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_AddToMyMorale_LENGTH;
                break;
            }
            case AI_SubtractFromMyMorale:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SubtractFromMyMorale_LENGTH;
                break;
            }
            case AI_IFMyMoraleLessThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_IFMyMoraleLessThan_LENGTH;
                break;
            }
            case AI_IFMyMoraleLessThanRandom:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFMyMoraleLessThanRandom_LENGTH;
                break;
            }
            case AI_SetMyAlertness:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyAlertness_LENGTH;
                break;
            }
            case AI_AddToMyAlertness:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_AddToMyAlertness_LENGTH;
                break;
            }
            case AI_SubtractFromMyAlertness:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SubtractFromMyAlertness_LENGTH;
                break;
            }
            case AI_IFMyAlertnessLessThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAlertnessLessThan_LENGTH;
                break;
            }
            case AI_IFMyAlertnessLessThanRandom:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFMyAlertnessLessThanRandom_LENGTH;
                break;
            }
            case AI_SetMyHearingScale:
            {
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) / 1000.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f", distance * 1000);
                printf(")\n");
                Offset += AI_SetMyHearingScale_LENGTH;
                break;
            }
            case AI_SetMyVisionRange:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyVisionRange_LENGTH;
                break;
            }
            case AI_SetMyGrenadeProbability:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyGrenadeProbability_LENGTH;
                break;
            }
            case AI_SetMyChrNum:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyChrNum_LENGTH;
                break;
            }
            case AI_SetMyHealthTotal:
            {
                float amount = CharArrayTo16(AiList, Offset + 1 + 0) * 0.1f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f", amount * 10);
                printf(")\n");
                Offset += AI_SetMyHealthTotal_LENGTH;
                break;
            }
            case AI_SetMyArmour:
            {
                float amount = CharArrayTo16(AiList, Offset + 1 + 0) * 0.1f; /*if (cheatIsActive(CHEAT_ENEMYSHIELDS)) { amount = amount < 8 ? 8 : amount; } */

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f", amount * 10);
                printf(")\n");
                Offset += AI_SetMyArmour_LENGTH;
                break;
            }
            case AI_SetMySpeedRating:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMySpeedRating_LENGTH;
                break;
            }
            case AI_SetMyArghRating:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyArghRating_LENGTH;
                break;
            }
            case AI_SetMyAccuracyRating:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyAccuracyRating_LENGTH;
                break;
            }
            case AI_SetMyFlags2:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyFlags2_LENGTH;
                break;
            }
            case AI_UnsetMyFlags2:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_UnsetMyFlags2_LENGTH;
                break;
            }
            case AI_IFMyFlags2Has:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyFlags2Has_LENGTH;
                break;
            }
            case AI_SetChrBitfield:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_SetChrBitfield_LENGTH;
                break;
            }
            case AI_UnsetChrBitfield:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_UnsetChrBitfield_LENGTH;
                break;
            }
            case AI_IFChrBitfieldHas:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFChrBitfieldHas_LENGTH;
                break;
            }
            case AI_SetObjectiveBitfield:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", flags);
                printf(")\n");
                Offset += AI_SetObjectiveBitfield_LENGTH;
                break;
            }
            case AI_UnsetObjectiveBitfield:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", flags);
                printf(")\n");
                Offset += AI_UnsetObjectiveBitfield_LENGTH;
                break;
            }
            case AI_IFObjectiveBitfieldHas:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x,lbl%d", flags, AiList[Offset + 5]);
                printf(")\n");
                Offset += AI_IFObjectiveBitfieldHas_LENGTH;
                break;
            }
            case AI_SetMychrflags:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", flags);
                printf(")\n");
                Offset += AI_SetMychrflags_LENGTH;
                break;
            }
            case AI_UnsetMychrflags:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", flags);
                printf(")\n");
                Offset += AI_UnsetMychrflags_LENGTH;
                break;
            }
            case AI_IFMychrflagsHas:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x,lbl%d", flags, AiList[Offset + 5]);
                printf(")\n");
                Offset += AI_IFMychrflagsHas_LENGTH;
                break;
            }
            case AI_SetChrchrflags:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_SetChrchrflags_LENGTH;
                break;
            }
            case AI_UnsetChrchrflags:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_UnsetChrchrflags_LENGTH;
                break;
            }
            case AI_IFChrchrflagsHas:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", AiList[Offset + 1], flags, AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFChrchrflagsHas_LENGTH;
                break;
            }
            case AI_SetObjectFlags:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_SetObjectFlags_LENGTH;
                break;
            }
            case AI_UnsetObjectFlags:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_UnsetObjectFlags_LENGTH;
                break;
            }
            case AI_IFObjectFlagsHas:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", AiList[Offset + 1], flags, AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFObjectFlagsHas_LENGTH;
                break;
            }
            case AI_SetObjectFlags2:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_SetObjectFlags2_LENGTH;
                break;
            }
            case AI_UnsetObjectFlags2:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_UnsetObjectFlags2_LENGTH;
                break;
            }
            case AI_IFObjectFlags2Has:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", AiList[Offset + 1], flags, AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFObjectFlags2Has_LENGTH;
                break;
            }
            case AI_SetMyChrPreset:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyChrPreset_LENGTH;
                break;
            }
            case AI_SetChrChrPreset:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_SetChrChrPreset_LENGTH;
                break;
            }
            case AI_SetMyPadPreset:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_SetMyPadPreset_LENGTH;
                break;
            }
            case AI_SetChrPadPreset:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s(%d,", AI_CMD_ToString[AiList[Offset]], AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_SetChrPadPreset_LENGTH;
                break;
            }
            case AI_PRINT:
            {
                int j = 1;
                printf("PRINT(\"");

                for (; AiList[Offset + j] != 0; j++)
                {
                    printf("%c", AiList[Offset + j]);
                }
                Offset += j + 1;
                printf("\")\n");
                break;
            }
            case AI_MyTimerStart:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_MyTimerStart_LENGTH;
                break;
            }
            case AI_MyTimerReset:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_MyTimerReset_LENGTH;
                break;
            }
            case AI_MyTimerPause:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_MyTimerPause_LENGTH;
                break;
            }
            case AI_MyTimerResume:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_MyTimerResume_LENGTH;
                break;
            }
            case AI_IFMyTimerIsNotRunning:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFMyTimerIsNotRunning_LENGTH;
                break;
            }
            case AI_IFMyTimerLessThanTicks:
            {
                float valf = ((unsigned)CharArrayTo24(AiList, Offset + 1 + 0));

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", valf, AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFMyTimerLessThanTicks_LENGTH;
                break;
            }
            case AI_IFMyTimerGreaterThanTicks:
            {
                float valf = ((unsigned)CharArrayTo24(AiList, Offset + 1 + 0));

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", valf, AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFMyTimerGreaterThanTicks_LENGTH;
                break;
            }
            case AI_HudCountdownShow:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HudCountdownShow_LENGTH;
                break;
            }
            case AI_HudCountdownHide:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HudCountdownHide_LENGTH;
                break;
            }
            case AI_HudCountdownSet:
            {
                float seconds = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f", seconds);
                printf(")\n");
                Offset += AI_HudCountdownSet_LENGTH;
                break;
            }
            case AI_HudCountdownStop:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HudCountdownStop_LENGTH;
                break;
            }
            case AI_HudCountdownStart:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HudCountdownStart_LENGTH;
                break;
            }
            case AI_IFHudCountdownIsNotRunning:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFHudCountdownIsNotRunning_LENGTH;
                break;
            }
            case AI_IFHudCountdownLessThan:
            {
                float value = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", value, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFHudCountdownLessThan_LENGTH;
                break;
            }
            case AI_IFHudCountdownGreaterThan:
            {
                float value = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", value, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFHudCountdownGreaterThan_LENGTH;
                break;
            }
            case AI_TRYSpawningChrAtPad:
            {
                unsigned short pad      = CharArrayTo16(AiList, Offset + 1 + 2);
                int            flags    = CharArrayTo32(AiList, Offset + 1 + 6);
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 4);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("%d,0x%x,%d,lbl%d", ailistid, flags, AiList[Offset + 10], AiList[Offset + 11]);
                printf(")\n");
                Offset += AI_TRYSpawningChrAtPad_LENGTH;
                break;
            }
            case AI_TRYSpawningChrNextToChr:
            {
                int            flags    = CharArrayTo32(AiList, Offset + 1 + 5);
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 3);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d,%d,0x%x,lbl%d", AiList[Offset + 1], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2], ailistid, flags, AiList[Offset + 10]);
                printf(")\n");
                Offset += AI_TRYSpawningChrNextToChr_LENGTH;
                break;
            }
            case AI_TRYGiveMeItem:
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 3);
                int model = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,0x%x,lbl%d", model, AiList[Offset + 1 + 2], flags, AiList[Offset + 8]);
                printf(")\n");
                Offset += AI_TRYGiveMeItem_LENGTH;
                break;
            }
            case AI_TRYGiveMeHat:
            {
                int flags    = CharArrayTo32(AiList, Offset + 1 + 2);
                int modelnum = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", modelnum, flags, AiList[Offset + 7]);
                printf(")\n");
                Offset += AI_TRYGiveMeHat_LENGTH;
                break;
            }
            case AI_TRYCloningChr:
            {
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,lbl%d", AiList[Offset + 4], ailistid, AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_TRYCloningChr_LENGTH;
                break;
            }
            case AI_TextPrintBottom:
            {
                printf("//USING HUD MESSAGE Stringy = %d, ai->txt = %d\n", 0, CharArrayTo16(AiList, Offset + 1 + 0));
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("TEXT(%d,%d)", (CharArrayTo16(AiList, Offset + 1 + 0)) / 1024, (CharArrayTo16(AiList, Offset + 1 + 0)) % 1024);
                printf(")\n");
                Offset += AI_TextPrintBottom_LENGTH;
                break;
            }
            case AI_TextPrintTop:
            {
                printf("//USING HUD MESSAGE Stringy = %d, ai->txt = %d\n", 0, CharArrayTo16(AiList, Offset + 1 + 0));
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("TEXT(%d,%d)", (CharArrayTo16(AiList, Offset + 1 + 0)) / 1024, (CharArrayTo16(AiList, Offset + 1 + 0)) % 1024);
                printf(")\n");
                Offset += AI_TextPrintTop_LENGTH;
                break;
            }
            case AI_SfxPlay:
            {
                short audio_id = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", audio_id, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_SfxPlay_LENGTH;
                break;
            }

            case AI_SfxStopChannel:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_SfxStopChannel_LENGTH;
                break;
            }
            case AI_SfxSetChannelVolume:
            {
                short          vol   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d, %d,%d", AiList[Offset + 1], vol, sfxID);
                printf(")\n");
                Offset += AI_SfxSetChannelVolume_LENGTH;
                break;
            }
            case AI_SfxFadeChannelVolume:
            {
                short          vol   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d, %d,%d", AiList[Offset + 1], vol, sfxID);
                printf(")\n");

                Offset += AI_SfxFadeChannelVolume_LENGTH;
                break;
            }
            case AI_SfxEmitFromObject:
            {
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d, %d,%d", AiList[Offset + 1], AiList[Offset + 2], sfxID);
                printf(")\n");
                Offset += AI_SfxEmitFromObject_LENGTH;
                break;
            }
            case AI_SfxEmitFromPad:
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("%d", sfxID);
                printf(")\n");
                Offset += AI_SfxEmitFromPad_LENGTH;
                break;
            }

            case AI_IFSfxChannelVolumeLessThan:
            {
                short vol = CharArrayTo16(AiList, Offset + 2 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d, %d,lbl%d", AiList[Offset + 1], vol, AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFSfxChannelVolumeLessThan_LENGTH;
                break;
            }
            case AI_VehicleStartPath:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1 + 0]);
                printf(")\n");
                Offset += AI_VehicleStartPath_LENGTH;
                break;
            }
            case AI_VehicleSpeed:
            {
                float speedtime = CharArrayTo16(AiList, Offset + 1 + 2);
                float speedaim  = CharArrayTo16(AiList, Offset + 1 + 0) * 100.0f / 15360.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%f", CharArrayTo16(AiList, Offset + 1 + 0), speedtime);
                printf(")\n");
                Offset += AI_VehicleSpeed_LENGTH;
                break;
            }
            case AI_AircraftRotorSpeed:
            {
                float speedtime = CharArrayTo16(AiList, Offset + 1 + 2);
                float speedaim  = CharArrayTo16(AiList, Offset + 1 + 0) * M_TAU_F / 3600.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%f", CharArrayTo16(AiList, Offset + 1 + 0), speedtime);
                printf(")\n");
                Offset += AI_AircraftRotorSpeed_LENGTH;
                break;
            }
            case AI_IFCameraIsInIntro:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1 + 0]);
                printf(")\n");
                Offset += AI_IFCameraIsInIntro_LENGTH;
                break;
            }
            case AI_IFCameraIsInBondSwirl:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1 + 0]);
                printf(")\n");
                Offset += AI_IFCameraIsInBondSwirl_LENGTH;
                break;
            }
            case AI_TvChangeScreenBank:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,$d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_TvChangeScreenBank_LENGTH;
                break;
            }
            case AI_IFBondInTank: // canonical name
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1 + 0]);
                printf(")\n");

                Offset += AI_IFBondInTank_LENGTH;
                break;
            }
            case AI_EndLevel: // canonical name
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_EndLevel_LENGTH;
                break;
            }
            case AI_CameraReturnToBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_CameraReturnToBond_LENGTH;
                break;
            }
            case AI_CameraLookAtBondFromPad:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_CameraLookAtBondFromPad_LENGTH;
                break;
            }
            case AI_CameraSwitch:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d", AiList[Offset + 1 + 0], CharArrayTo16(AiList, Offset + 1 + 1), CharArrayTo16(AiList, Offset + 1 + 3));
                printf(")\n");
                break;
            }
            case AI_IFBondYPosLessThan:
            {
                float bondpos = (short)CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,%d", bondpos, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFBondYPosLessThan_LENGTH;
                break;
            }
            case AI_BondDisableControl:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_BondDisableControl_LENGTH;
                break;
            }
            case AI_BondEnableControl:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_BondEnableControl_LENGTH;
                break;
            }
            case AI_TRYTeleportingChrToPad:
            {
                int pad = CharArrayTo16(AiList, Offset + 1 + 1);
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("lbl%d", AiList[Offset + 4]);
                printf(")\n");

                Offset += AI_TRYTeleportingChrToPad_LENGTH;
                break;
            }
            case AI_ScreenFadeToBlack:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_ScreenFadeToBlack_LENGTH;
                break;
            }
            case AI_ScreenFadeFromBlack:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_ScreenFadeFromBlack_LENGTH;
                break;
            }
            case AI_IFScreenFadeCompleted:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFScreenFadeCompleted_LENGTH;
                break;
            }
            case AI_HideAllChrs:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HideAllChrs_LENGTH;
                break;
            }
            case AI_ShowAllChrs:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_ShowAllChrs_LENGTH;
                break;
            }
            case AI_DoorOpenInstant:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_DoorOpenInstant_LENGTH;
                break;
            }
            case AI_ChrRemoveItemInHand:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%s", AiList[Offset + 1], AiList[Offset + 2] == 0 ? "GUNRIGHT" : "GUNLEFT");
                printf(")\n");
                Offset += AI_ChrRemoveItemInHand_LENGTH;
                break;
            }
            case AI_IfNumberOfActivePlayersLessThan:
            {
                if (AiList[Offset + 1] == 2)
                {
                    printf("%sIFSinglePlayer(", tabs);
                    printf("lbl%d", AiList[Offset + 2]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                }
                printf(")\n");
                Offset += AI_IfNumberOfActivePlayersLessThan_LENGTH;
                break;
            }
            case AI_IFBondItemTotalAmmoLessThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFBondItemTotalAmmoLessThan_LENGTH;
                break;
            }
            case AI_BondEquipItem:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_BondEquipItem_LENGTH;
                break;
            }
            case AI_BondEquipItemCinema:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_BondEquipItemCinema_LENGTH;
                break;
            }
            case AI_BondSetLockedVelocity:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_BondSetLockedVelocity_LENGTH;
                break;
            }
            case AI_IFObjectInRoomWithPad:
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("lbl%d", AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFObjectInRoomWithPad_LENGTH;
                break;
            }
            case AI_SwitchSky:
            { // SWITCHENVIRONMENT
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_SwitchSky_LENGTH;
                break;
            }
            case AI_TriggerFadeAndExitLevelOnButtonPress:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH;
                break;
            }
            case AI_IFBondIsDead:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFBondIsDead_LENGTH;
                break;
            }
            case AI_BondDisableDamageAndPickups:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_BondDisableDamageAndPickups_LENGTH;
                break;
            }
            case AI_BondHideWeapons:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_BondHideWeapons_LENGTH;
                break;
            }
            case AI_CameraOrbitPad: // sp order from xbla
            {
                int pad;
                int speed60;
                int camDististance;
                int targetHeight;
                int camHeight;
                int start;
                camDististance = CharArrayTo16(AiList, Offset + 1 + 0);
                camHeight      = (short)CharArrayTo16(AiList, Offset + 1 + 2);
                speed60        = (short)CharArrayTo16(AiList, Offset + 1 + 4);
                pad            = CharArrayTo16(AiList, Offset + 1 + 6);
                targetHeight   = (short)CharArrayTo16(AiList, Offset + 1 + 8);
                start          = CharArrayTo16(AiList, Offset + 1 + 10);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d,", camDististance, camHeight, speed60);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("%d,%d", targetHeight, start);
                printf(")\n");
                Offset += AI_CameraOrbitPad_LENGTH;
                break;
            }
            case AI_CreditsRoll:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_CreditsRoll_LENGTH;
                break;
            }
            case AI_IFCreditsHasCompleted:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFCreditsHasCompleted_LENGTH;
                break;
            }
            case AI_IFObjectiveAllCompleted:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFObjectiveAllCompleted_LENGTH;
                break;
            }
            case AI_IFFolderActorIsEqual:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFFolderActorIsEqual_LENGTH;
                break;
            }
            case AI_IFBondDamageAndPickupsDisabled:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFBondDamageAndPickupsDisabled_LENGTH;
                break;
            }
            case AI_MusicPlaySlot:
            {
                Offset += AI_MusicPlaySlot_LENGTH;
                printf("//ai: enery tune on (%d, %d, %d)\n", AiList[Offset + 1 + 0], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d", AiList[Offset + 1 + 0], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);
                printf(")\n");
                break;
            }
            case AI_MusicStopSlot:
            {
                Offset += AI_MusicStopSlot_LENGTH;
                printf("//ai: enery tune off (%d)\n", AiList[Offset + 1 + 0]);
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1 + 0]);
                printf(")\n");
                break;
            }
            case AI_TriggerExplosionsAroundBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_TriggerExplosionsAroundBond_LENGTH;
                break;
            }
            case AI_IFKilledCiviliansGreaterThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFKilledCiviliansGreaterThan_LENGTH;
                break;
            }
            case AI_IFChrWasShotSinceLastCheck:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFChrWasShotSinceLastCheck_LENGTH;
                break;
            }
            case AI_BondKilledInAction:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_BondKilledInAction_LENGTH;
                break;
            }
            case AI_RaiseArms:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_RaiseArms_LENGTH;
                break;
            }
            case AI_GasLeakAndFadeFog:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_GasLeakAndFadeFog_LENGTH;
                break;
            }
            case AI_ObjectRocketLaunch:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_ObjectRocketLaunch_LENGTH;
                break;
            } //============================================================================================================

            default:
                /*
                 * No Command found, advance ailist by 1.
                 * This is attempting to handle situations where the command
                 * type is invalid by passing over them and continuing
                 * execution.
                 * chraiitemsize returns 1 which is pointless really
                 * could have done it here without a jump
                 *
                 * Outcome:crash
                 */
                {
                    Offset++;
                }
        } // switch
    }
}
enum chrAIListIDs
{
    chrai_0 = setChrAIListID(0),
    chrai_1,
    chrai_2,
    chrai_3,
    chrai_4,
    chrai_5,
    chrai_6,
    chrai_7,
    chrai_8,
    chrai_9,
    chrai_10,
    chrai_11,
    chrai_12,
    chrai_13,
    chrai_14,
    chrai_15,
    chrai_16,
    chrai_17,
    chrai_18
};
int main()
{
    unsigned char
          ai_0[] = {0x02, 0x04, 0x1c, 0x00, 0x9e, 0x00, 0x2a, 0x02, 0x2a, 0x03, 0x2f, 0x08, 0x01, 0x2a, 0x02, 0x08, 0x4d, 0xfd, 0x00, 0x32, 0x00, 0x9e, 0x05, 0x45, 0x09, 0x07, 0x02, 0x09, 0x01, 0x04, 0x02, 0x05, 0x08, 0x94, 0x20, 0x95, 0x80, 0x07, 0x04, 0x00};
    short ID     = chrai_10;

    // char          str[999];
    // printf("Enter a string: ");
    // gets(str);

    printf("/*\n");
    if (isChrAIListID(ID))
    {
        printf("u8 chrAi_%d[] = {\n #define THIS chrai_%d\n", getChrAIListID(ID), getChrAIListID(ID));
    }
    else
    {
        printf("u8 bgAi_%d[] = {\n #define THIS bgai_%d\n", getBGAIListID(ID), getBGAIListID(ID));
    }
    ai(ai_0, ID);
    // un-closed loops
    if (top != -1) displayStack();

    printf("#undef THIS \n};\n*/");

    return 0;
}
