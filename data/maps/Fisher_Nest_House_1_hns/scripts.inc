Fisher_Nest_House_1_hns_MapScripts::
	.byte 0

Fisher_Nest_House_1_hns_EventScript_Clerk::
	lock
	faceplayer
	msgbox Fisher_Nest_House_1_hns_Text_Clerk, MSGBOX_DEFAULT
	pokemart Fisher_Nest_House_1_hns_Mart
	goto_if_set FLAG_SEEN_FISHING_MAGNET_AD, Fisher_Nest_House_1_hns_EventScript_Magnet
	goto_if_unset FLAG_FISHER_NEST_CLERK_EGG, Fisher_Nest_House_1_hns_EventScript_ClerkEgg
	msgbox Fisher_Nest_House_1_hns_Text_ClerkEnd, MSGBOX_DEFAULT
	release
	end

Fisher_Nest_House_1_hns_EventScript_ClerkEnd::
	msgbox Fisher_Nest_House_1_hns_Text_ClerkEnd, MSGBOX_DEFAULT
	release
	end

Fisher_Nest_House_1_hns_EventScript_ClerkEgg::
	msgbox Fisher_Nest_House_1_hns_Text_ClerkEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Fisher_Nest_House_1_hns_EventScript_ClerkEggTake
	msgbox Fisher_Nest_House_1_hns_Text_ClerkEggRefuse, MSGBOX_DEFAULT
	release
	end

Fisher_Nest_House_1_hns_EventScript_ClerkEggTake::
	msgbox Fisher_Nest_House_1_hns_Text_ClerkEggTake, MSGBOX_DEFAULT
	setflag FLAG_FORCE_SHINY_HNS
	giveegg SPECIES_OSHAWOTT
	playfanfare MUS_HG_OBTAIN_EGG
	message Fisher_Nest_House_1_hns_Text_PlayerReceiveEgg
	setflag FLAG_FISHER_NEST_CLERK_EGG
	clearflag FLAG_FORCE_SHINY_HNS
	waitfanfare 
	msgbox Fisher_Nest_House_1_hns_Text_ClerkEnd, MSGBOX_DEFAULT
	release
	end

Fisher_Nest_House_1_hns_EventScript_Magnet::
	goto_if_set FLAG_GET_FISHING_MAGNET, Fisher_Nest_House_1_hns_EventScript_ClerkEnd
	playse SE_PIN
	applymovement LOCALID_FISHER, Common_Movement_ExclamationMark
	delay 55
	waitse
	msgbox Fisher_Nest_House_1_hns_Text_ClerkMagnet, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Fisher_Nest_House_1_hns_EventScript_ClerkMagnetTake
	msgbox Fisher_Nest_House_1_hns_Text_ClerkMagnetRefuse, MSGBOX_DEFAULT
	goto_if_unset FLAG_FISHER_NEST_CLERK_EGG, Fisher_Nest_House_1_hns_EventScript_ClerkEgg
	release
	end

Fisher_Nest_House_1_hns_EventScript_ClerkMagnetTake::
	giveitem ITEM_FISHING_MAGNET
	msgbox Fisher_Nest_House_1_hns_Text_ClerkExplainMagnet, MSGBOX_DEFAULT
	setflag FLAG_GET_FISHING_MAGNET
	release
	end

Fisher_Nest_House_1_hns_Sign_Brochure::
	msgbox Fisher_Nest_House_1_hns_Text_Brochure, MSGBOX_DEFAULT
	closemessage
	end

Fisher_Nest_House_1_hns_Sign_FishingMagnetAd::
	msgbox Fisher_Nest_House_1_hns_Text_Brochure, MSGBOX_DEFAULT
	delay 25
	msgbox Fisher_Nest_House_1_hns_Text_FishingMagnetAd, MSGBOX_DEFAULT
	setflag FLAG_SEEN_FISHING_MAGNET_AD
	closemessage
	end

Fisher_Nest_House_1_hns_Text_Clerk:
	.string "We're setting up a new\n"
	.string "shop here, but it'll take a\l"
	.string "while before everything is\l"
	.string "ready.\p"
	.string "In the meanwhile, I do have\n"
	.string "a few things to sell. Wanna\l"
	.string "look?$"

Fisher_Nest_House_1_hns_Text_ClerkEnd:
	.string "See 'ya!$"

Fisher_Nest_House_1_hns_Text_ClerkEgg:
	.string "Oh, by the way, we found\n"
	.string "this EGG while moving our\l"
	.string "stuff here. I'm not really\l"
	.string "up for it, so maybe you\l"
	.string "wanna take it?$"

Fisher_Nest_House_1_hns_Text_ClerkEggTake:
	.string "Great, there you go then.$"

Fisher_Nest_House_1_hns_Text_PlayerReceiveEgg:
	.string "{PLAYER} received an EGG.$"

Fisher_Nest_House_1_hns_Text_ClerkEggRefuse:
	.string "Alright, see 'ya then.$"

Fisher_Nest_House_1_hns_Text_Brochure:
	.string "There are a bunch of\n"
	.string "brochures about top-quality\l"
	.string "fishing gear.$"

Fisher_Nest_House_1_hns_Text_FishingMagnetAd:
	.string "...You also see an ad for\n"
	.string "something called a FISHING\l"
	.string "MAGNET.\p"
	.string "You take one with you.$"

Fisher_Nest_House_1_hns_Text_ClerkMagnet:
	.string "Oh, is that the ad for our\n"
	.string "FISHING MAGNET? You're lucky,\l"
	.string "because I still have one of\l"
	.string "those with me. Want it?$"

Fisher_Nest_House_1_hns_Text_ClerkExplainMagnet:
	.string "With this, you can now fish\n"
	.string "for items. Whenever a MOéMON\l"
	.string "doesn't bite, there's a chance\l"
	.string "you'll reel in something else\l"
	.string "instead.$"

Fisher_Nest_House_1_hns_Text_ClerkMagnetRefuse:
	.string "Oh... Alright then.$"

	.align 2
Fisher_Nest_House_1_hns_Mart:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_LURE
	.2byte ITEM_LEEK
	.2byte ITEM_HEART_SCALE
	.2byte ITEM_SHOAL_SHELL
	.2byte ITEM_SHOAL_SALT
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_WATER_STONE
	.2byte ITEM_NONE
	release
	end

