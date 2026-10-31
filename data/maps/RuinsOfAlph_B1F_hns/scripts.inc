RuinsOfAlph_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_B1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_B1F_OnFrame
	.byte 0

RuinsOfAlph_B1F_OnLoad::
	call_if_set FLAG_FIND_SECRET_RUINS, RuinsOfAlph_B1F_EventScript_TestOpenNewRoom2
	end

RuinsOfAlph_B1F_OnFrame::
	map_script_2 VAR_RUINSOFALPH_STATE, 1, RuinsOfAlph_B1F_EventScript_Presence
	.2byte 0

RuinsOfAlph_B1F_EventScript_Presence::
	lock
	msgbox RuinsOfAlph_B1F_Text_Presence, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUINSOFALPH_STATE, 0
	release
	end


RuinsOfAlph_B1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Teacher, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Hiker::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Hiker, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Gramps::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Gramps, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HelixFossil::
	finditem ITEM_HELIX_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_DomeFossil::
	finditem ITEM_DOME_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OldAmber::
	finditem ITEM_OLD_AMBER
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_GSBALL::
	finditem ITEM_GS_BALL
	end

RuinsOfAlph_B1F_Sign_SecretRoomStatue::
	lock
	goto_if_set FLAG_FIND_SECRET_RUINS, RuinsOfAlph_B1F_Sign_SecretRoomStatue2
	msgbox RuinsOfAlph_B1F_Text_SecretRoomStatue, MSGBOX_DEFAULT
	closemessage
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, RuinsOfAlph_B1F_CheckUnownParty
	release
	end

RuinsOfAlph_B1F_Sign_SecretRoomStatue2::
	msgbox RuinsOfAlph_B1F_Text_SecretRoomStatue2, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_CheckUnownParty::
	specialvar VAR_RESULT, GetSecretCode
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_B1F_EventScript_TestOpenNewRoom
	release
	end

RuinsOfAlph_B1F_EventScript_TestOpenNewRoom::
	playse SE_BANG
	setflag FLAG_FIND_SECRET_RUINS
	setmetatile 15, 1, 0x307, FALSE
	special DrawWholeMapView
	release
	end

RuinsOfAlph_B1F_EventScript_TestOpenNewRoom2::
	setmetatile 15, 1, 0x307, FALSE
	end

RuinsOfAlph_B1F_Text_Presence:
	.string "There is a strange presence here.$"

RuinsOfAlph_B1F_Text_Hiker:
	.string "This is a big room, but there's\n"
	.string "nothing here.$"

RuinsOfAlph_B1F_Text_Teacher:
	.string "This place has a mystical\n"
	.string "quality to it.\p"
	.string "It feels sort of ethereal\n"
	.string "even.$"

RuinsOfAlph_B1F_Text_Gramps:
	.string "Ancient buildings are often\n"
	.string "tombs of kings.\p"
	.string "Like the pyramids, for\n"
	.string "instance.$"

RuinsOfAlph_B1F_Text_SecretRoomStatue:
	.string "There is a note here.\p"
	.string "THERE IS A SECRET ROOM\n"
	.string "HIDDEN FROM SIGHT\p"
	.string "ONLY THE CODE CAN REVEAL\n"
	.string "ITS ENTRANCE.\p"
	.string "...There is a smaller\n"
	.string "note near the bottom.\p"
	.string "THE CODE IS 'SECRET'.$"

RuinsOfAlph_B1F_Text_SecretRoomStatue2:
	.string "The code was SECRET.$"

