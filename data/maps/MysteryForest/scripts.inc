MysteryForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MysteryForest_hns_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MysteryForest_hns_OnTransition::
	callnative SetTimeBasedEncounters
	end

MysteryForest_hns_EventScript_ZapdosGalar::
	lock
	faceplayer
	playmoncry SPECIES_ZAPDOS_GALAR, CRY_MODE_ENCOUNTER
	msgbox SeafoamIslands_B1F_Text_ArticunoBattle
	delay 40
	waitmoncry
	seteventmon SPECIES_ZAPDOS_GALAR, 70
	special BattleSetup_StartLegendaryBattle
waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MysteryForest_hns_EventScript_ZapdosRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MYSTERY_ZAPDOS_GALAR
	setflag FLAG_HIDE_ZAPDOS_GALAR
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MysteryForest_hns_EventScript_ZapdosRan::
	release
	end
	
