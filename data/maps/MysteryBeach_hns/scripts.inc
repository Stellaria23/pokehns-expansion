MysteryBeach_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MysteryBeach_hns_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MysteryBeach_hns_OnTransition:
	callnative SetTimeBasedEncounters
	end
