MysteryTwo_hns_MapScripts::
	.byte 0

MysteryTwo_hns_EventScript_Woman::
	lock
	faceplayer
	msgbox MysteryTwo_hns_Text_Woman, MSGBOX_DEFAULT
	release
	end

MysteryTwo_hns_EventScript_Nerd::
	lock
	faceplayer
	msgbox MysteryTwo_hns_Text_Nerd, MSGBOX_DEFAULT
	release
	end

MysteryTwo_hns_EventScript_Chef::
	lock
	faceplayer
	msgbox MysteryTwo_hns_Text_Chef, MSGBOX_DEFAULT
	pokemart MysteryTwo_hns_SweetMart
	msgbox MysteryTwo_hns_Text_ChefBye, MSGBOX_DEFAULT
	release
	end

MysteryTwo_hns_EventScript_EvoGirl::
	lock
	faceplayer
	msgbox MysteryOne_hns_Text_EvoGirl, MSGBOX_DEFAULT
	pokemart MysteryTwo_hns_EvoMart
	msgbox MysteryTwo_hns_Text_ChefBye, MSGBOX_DEFAULT
	release
	end

MysteryTwo_hns_Text_Woman:
	.string "A lot of MOéMON here\n"
	.string "come from the GALAR region.\p"
	.string "I wonder if something\n"
	.string "here reminds them of their\l"
	.string "usual habitat...$"

MysteryTwo_hns_Text_Nerd:
	.string "There's a lot we don't\n"
	.string "know about these ISLANDS.\p"
	.string "Did you know that there's\n"
	.string "an archipelago near KANTO\l"
	.string "that looks just like this?\p"
	.string "It really makes you think...$"

MysteryTwo_hns_Text_Chef:
	.string "Hi! I have a lot of sweet\n"
	.string "fruits to sell! Come check\l"
	.string "it out!$"

MysteryTwo_hns_Text_ChefBye:
	.string "Come again!$"

MysteryOne_hns_Text_EvoGirl:
	.string "Hey, I got some cool\n"
	.string "items to sell! Interested?$"

	.align 2
MysteryTwo_hns_SweetMart:
	.2byte ITEM_STRAWBERRY_SWEET
	.2byte ITEM_LOVE_SWEET
	.2byte ITEM_BERRY_SWEET
	.2byte ITEM_CLOVER_SWEET
	.2byte ITEM_FLOWER_SWEET
	.2byte ITEM_STAR_SWEET
	.2byte ITEM_RIBBON_SWEET
	.2byte ITEM_NONE
	release
	end

MysteryTwo_hns_EvoMart:
	.2byte ITEM_SWEET_APPLE
	.2byte ITEM_TART_APPLE
	.2byte ITEM_SYRUPY_APPLE
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_NONE
	release
	end
