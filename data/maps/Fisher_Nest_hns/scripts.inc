Fisher_Nest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Fisher_Nest_hns_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Fisher_Nest_hns_OnTransition:
	callnative SetTimeBasedEncounters
	end

Fisher_Nest_hns_EventScript_Foongus::
	lock
	setwildbattleshiny SPECIES_FOONGUS, 12, ITEM_BIG_MUSHROOM
	playmoncry SPECIES_FOONGUS, CRY_MODE_NORMAL
	msgbox Fisher_Nest_hns_Text_Foongus
	waitmoncry
	closemessage
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Fisher_Nest_hns_EventScript_FoongusDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Fisher_Nest_hns_EventScript_FoongusDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Fisher_Nest_hns_EventScript_FoongusDefeated
	release
	end

Fisher_Nest_hns_EventScript_FoongusDefeated::
	setflag FLAG_FISHER_NEST_OW_FOONGUS
	removeobject LOCALID_FAKE_POKE_BALL 
	release
	end

Fisher_Nest_hns_Text_Foongus:
	.string "Fooooooooo!$"