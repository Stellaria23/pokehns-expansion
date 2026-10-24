MysteryOne_TeleporterHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MysteryOne_TeleporterHouse_hns_OnTransition
	.byte 0

MysteryOne_TeleporterHouse_hns_OnTransition::
	setflag FLAG_TEMP_3
	end

MysteryOne_TeleporterHouse_hns_SetPlayerMale::
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_GOLD_NORMAL_HNS
	return

MysteryOne_TeleporterHouse_hns_SetPlayerFemale::
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_KRIS_NORMAL_HNS
	return

MysteryOne_TeleporterHouse_hns_EventScript_TeleporterTest::
	lockall
	msgbox MysteryOne_TeleporterHouse_hns_Text_Teleporter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25_BillsHouse_hns_EndChoice
	closemessage
	goto MysteryOne_TeleporterHouse_hns_CutsceneSetup
	releaseall
	end

MysteryOne_TeleporterHouse_hns_CutsceneSetup::
	fadescreen FADE_TO_BLACK
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route25_BillsHouse_SetPlayerMale
	call_if_eq VAR_RESULT, FEMALE, Route25_BillsHouse_SetPlayerFemale
	addobject LOCALID_TELEPORT_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Route25_BillsHouse_Movement_HidePlayer
	hidefollower
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Route25_BillsHouse_Movement_CameraPanUp
	waitmovement 0
	delay 60
	fadescreen FADE_FROM_BLACK

MysteryOne_TeleporterHouse_hns_CutsceneBeforeTeleport::
	delay 60
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_TELEPORT_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	turnobject LOCALID_TELEPORT_PLAYER, DIR_SOUTH
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 10, 3
	delay 10
	removeobject LOCALID_TELEPORT_PLAYER
	waitdooranim
	
MysteryOne_TeleporterHouse_hns_CutsceneTeleport::
	delay 35
	playse SE_PIN
	waitse
	setvar VAR_0x8004, 0
	special AnimateTeleporterHousing
	delay 10
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	call Route25_BillsHouse_hns_BeepSE
	setvar VAR_0x8004, 1
	playse SE_WARP_IN
	waitse
	delay 30
	fadescreen FADE_TO_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, Route25_BillsHouse_Movement_ShowPlayer
	warp MAP_ROUTE25_BILLS_HOUSE_HNS, 3, 3
	waitstate
	fadescreen FADE_FROM_BLACK
	release
	end

MysteryOne_TeleporterHouse_hns_Text_Teleporter:
	.string "The teleporter seems to be \n"
	.string "working.\p"
	.string "Enter it?$"
