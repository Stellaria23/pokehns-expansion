MysteryOneTwoTunnel_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MysteryOneTwoTunnel_hns_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MysteryOneTwoTunnel_hns_OnTransition::
	callnative SetTimeBasedEncounters
	end
