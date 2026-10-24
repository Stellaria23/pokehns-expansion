MysteryBrink_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MysteryBrink_hns_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MysteryBrink_hns_OnTransition::
	callnative SetTimeBasedEncounters
	end

MysteryKindle_hns_EventScript_ArticunoGalar::
	lock
	faceplayer
	playmoncry SPECIES_ARTICUNO_GALAR, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_ARTICUNO_GALAR, 70
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MysteryKindle_hns_EventScript_ArticunoRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MYSTERY_ARTICUNO_GALAR
	setflag FLAG_HIDE_ARTICUNO_GALAR
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MysteryKindle_hns_EventScript_ArticunoRan::
	release
	end