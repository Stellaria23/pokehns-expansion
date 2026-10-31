CeruleanCity_BikeShop_hns_MapScripts::
	.byte 0

CeruleanCity_BikeShop_hns_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_GET_RIDE_FLUTE, CeruleanCity_BikeShop_hns_EventScript_BaldingMan2
	msgbox CeruleanCity_BikeShop_hns_Text_BaldingManGreet, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CeruleanCity_BikeShop_hns_EventScript_BaldingManDeny
	msgbox CeruleanCity_BikeShop_hns_Text_Training, MSGBOX_DEFAULT
	showmoneybox 0, 0
	msgbox CeruleanCity_BikeShop_hns_Text_ConfirmPrice, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq CeruleanCity_BikeShop_hns_EventScript_BaldingManAccept
	goto CeruleanCity_BikeShop_hns_EventScript_BaldingManDeny
	release
	end

CeruleanCity_BikeShop_hns_EventScript_BaldingMan2::
	msgbox CeruleanCity_BikeShop_hns_Text_BaldingManGreet2, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_hns_EventScript_BaldingManAccept::
	checkmoney 200000
	goto_if_eq VAR_RESULT, 0, CeruleanCity_BikeShop_hns_EventScript_NotEnoughMoney
	removemoney 200000
	playse SE_SHOP
	updatemoneybox
	waitse
	hidemoneybox
	msgbox CeruleanCity_BikeShop_hns_Text_Training2, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 55
	msgbox CeruleanCity_BikeShop_hns_Text_Ellipses, MSGBOX_DEFAULT
	closemessage
	delay 55
	fadescreen FADE_FROM_BLACK
	delay 16
	msgbox CeruleanCity_BikeShop_hns_Text_EndTraining, MSGBOX_DEFAULT
	setflag FLAG_GET_RIDE_FLUTE
	setflag FLAG_SYS_POKERIDE_JUMP
	giveitem ITEM_RIDE_FLUTE
	msgbox CeruleanCity_BikeShop_hns_Text_ExplainFlute, MSGBOX_DEFAULT
	release
	end


CeruleanCity_BikeShop_hns_EventScript_BaldingManDeny::
	msgbox CeruleanCity_BikeShop_hns_Text_DenyRiding, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_hns_EventScript_NotEnoughMoney::
	msgbox CeruleanCity_BikeShop_hns_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_hns_EventScript_Charizard::
	lock
	faceplayer
	playmoncry SPECIES_CHARIZARD, CRY_MODE_NORMAL
	msgbox CeruleanCity_BikeShop_hns_Text_Charizard, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_BikeShop_hns_EventScript_Venusaur::
	lock
	faceplayer
	playmoncry SPECIES_VENUSAUR, CRY_MODE_NORMAL
	msgbox CeruleanCity_BikeShop_hns_Text_Venusaur, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_BikeShop_hns_EventScript_Blastoise::
	lock
	faceplayer
	playmoncry SPECIES_BLASTOISE, CRY_MODE_NORMAL
	msgbox CeruleanCity_BikeShop_hns_Text_Blastoise, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_BikeShop_hns_EventScript_Clerk::
	lock
	faceplayer
	msgbox CeruleanCity_BikeShop_hns_Text_Clerk, MSGBOX_DEFAULT
	release
	end

CeruleanCity_BikeShop_hns_Text_BaldingManGreet:
	.string "Hello! Welcome to our\n"
	.string "new riding school!\p"
	.string "Ever dreamt of travelling\n"
	.string "on the back of your MOéMON?\l"
	.string "With us, you can! Are you\l"
	.string "interested?$"

CeruleanCity_BikeShop_hns_Text_DenyRiding:
	.string "Oh, okay. Come back\n"
	.string "whenever!$"

CeruleanCity_BikeShop_hns_Text_BaldingManGreet2:
	.string "You can only ride MOéMON\n"
	.string "that are big enough, so\l"
	.string "there won't be any travelling\l"
	.string "on a CATERPIE any type soon,\l"
	.string "ha!\p"
	.string "Also, some can jump and\n"
	.string "climb ledges with no\l"
	.string "problem.$"

CeruleanCity_BikeShop_hns_Text_Training:
	.string "Great! Now, this is a\n"
	.string "very intensive training\l"
	.string "course, and I would usually\l"
	.string "charge around ¥1'000'000...\p"
	.string "But since you're my first\n"
	.string "student, I can give you a\l"
	.string "discount of ¥800'000.$"

CeruleanCity_BikeShop_hns_Text_ConfirmPrice:
	.string "So, ¥200'000. What do you\n"
	.string "say?$"

CeruleanCity_BikeShop_hns_Text_NotEnoughMoney:
	.string "...Sorry, but you don't have\n"
	.string "enough money.$"

CeruleanCity_BikeShop_hns_Text_Training2:
	.string "Perrrrfect. Now...$"

CeruleanCity_BikeShop_hns_Text_Ellipses:
	.string "......   ......\n"
	.string "......   ......$"

CeruleanCity_BikeShop_hns_Text_EndTraining:
	.string "...Alright! You're now\n"
	.string "ready to ride any MOéMON\l"
	.string "in your team!\p"
	.string "And as proof of your\n"
	.string "competences, take this!$"

CeruleanCity_BikeShop_hns_Text_ExplainFlute:
	.string "This RIDE FLUTE calls\n"
	.string "a MOéMON from your team\l"
	.string "to ride. Note that you\l"
	.string "can only ride MOéMON that\l"
	.string "are big enough.$"


CeruleanCity_BikeShop_hns_Text_Charizard:
	.string "CHARIZARD: Graa!$"

CeruleanCity_BikeShop_hns_Text_Venusaur:
	.string "VENUSAUR: Groaa!$"

CeruleanCity_BikeShop_hns_Text_Blastoise:
	.string "BLASTOISE: Raaa!$"

CeruleanCity_BikeShop_hns_Text_Clerk:
	.string "We first wanted to set\n"
	.string "up shop in ALOLA, but\l"
	.string "we realised people there\l"
	.string "were already used to riding\l"
	.string "MOéMON, so there wasn't\l"
	.string "much demand for our course.$"