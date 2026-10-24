MysteryOne_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MysteryOne_hns_EventScript_OnFrame
	.byte 0

MysteryOne_hns_EventScript_OnFrame::
	map_script_2 VAR_MYSTERY_ISLANDS, 0, MysteryOne_hns_DisplayHelp
	end

MysteryOne_hns_DisplayHelp::
	lock
	playse SE_PIN
	applymovement LOCALID_MYSTERY_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 55
	waitse
	applymovement LOCALID_MYSTERY_HELPER, MysteryOne_hns_Helper_Movement_0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MysteryOne_hns_Helper_Movement_left
	waitmovement 0
	msgbox MysteryOne_hns_Text_Helper1, MSGBOX_DEFAULT
	closemessage
	delay 55
	applymovement LOCALID_MYSTERY_HELPER, MysteryOne_hns_Helper_Movement_down
	waitmovement 0
	delay 55
	applymovement LOCALID_MYSTERY_HELPER, MysteryOne_hns_Helper_Movement_right
	waitmovement 0
	msgbox MysteryOne_hns_Text_Helper2, MSGBOX_DEFAULT
	closemessage
	delay 55
	applymovement LOCALID_MYSTERY_HELPER, MysteryOne_hns_Helper_Movement_1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MysteryOne_hns_Helper_Movement_down
	waitmovement 0
	delay 55
	helpwindow HELP_MYSTERY_ISLES
	setvar VAR_MYSTERY_ISLANDS, 1
	release
	end

MysteryOne_hns_OldMan::
	lock
	faceplayer
	msgbox MysteryOne_hns_Text_OldMan, MSGBOX_DEFAULT
	release
	end

MysteryOne_hns_EventScript_Sign::
	msgbox MysteryOne_hns_Text_Sign
	closemessage
	end

MysteryOne_hns_EventScript_Sign2::
	msgbox MysteryOne_hns_Text_Residence
	closemessage
	end

MysteryOne_hns_EventScript_DoorLocked::
	msgbox MysteryOne_hns_Text_DoorLocked
	closemessage
	end

MysteryOne_hns_Helper_Movement_0::
	walk_up
	walk_up
	walk_up
	walk_right
	face_right
	step_end

MysteryOne_hns_Helper_Movement_1::
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end

MysteryOne_hns_Helper_Movement_down::
	face_down
	step_end

MysteryOne_hns_Helper_Movement_right::
	face_right
	step_end

MysteryOne_hns_Helper_Movement_left::
	face_left
	step_end

MysteryOne_hns_Text_Sign:
	.string "WELCOME TO THE MYSTERY\n"
	.string "ISLANDS.\p"
	.string "MYSTERY ONE.$"


MysteryOne_hns_Text_Residence:
	.string "HOME OF ???$"

MysteryOne_hns_Text_DoorLocked:
	.string "The door is locked...$"

MysteryOne_hns_Text_Helper1:
	.string "Oh, hello! it's rare\n"
	.string "to see a new face here.\p"
	.string "Did you come through the\n"
	.string "TELEPORTER? I didn't even\l"
	.string "know it was working!\p"
	.string "Me and a few people moved\n"
	.string "here a while ago, I was\l"
	.string "working on a way to get\l"
	.string "to other places.$"

MysteryOne_hns_Text_Helper2:
	.string "This place doesn't appear\n"
	.string "on any map, and the MOéMON\l"
	.string "found here seem to come\l"
	.string "from another region than\l"
	.string "KANTO or JOHTO. For now,\l"
	.string "we call it the the\l"
	.string "MYSTERY ISLANDS.\p"
	.string "Anyway, have fun!$"

MysteryOne_hns_Text_OldMan:
	.string "My house is just down\n"
	.string "there.\p"
	.string "Hm? Why am I staying\n"
	.string "outside? I lost my keys!$"





