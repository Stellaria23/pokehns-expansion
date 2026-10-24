ChallengePlaza_hns_MapScripts::
	.byte 0

ChallengePlaza_hns_SageTrainer::
	lock
	faceplayer
	goto_if_eq VAR_SAGE_TRAINER, 0, ChallengePlaza_hns_SageTrainer_0
	goto_if_eq VAR_SAGE_TRAINER, 1, ChallengePlaza_hns_SageTrainer_1
	goto_if_eq VAR_SAGE_TRAINER, 2, ChallengePlaza_hns_SageTrainer_2
	goto_if_eq VAR_SAGE_TRAINER, 3, ChallengePlaza_hns_SageTrainer_3
	msgbox ChallengePlaza_hns_Text_SageTrainer_SomethingNew, MSGBOX_DEFAULT
	release
	end


ChallengePlaza_hns_SageTrainer_0::
	msgbox ChallengePlaza_hns_Text_SageTrainer_0_Intro, MSGBOX_DEFAULT
	setvar VAR_SAGE_TRAINER, 1
	goto_if_set FLAG_BADGE03_GET, ChallengePlaza_hns_SageTrainer_1
	goto ChallengePlaza_hns_SageTrainer_NotReady
	release
	end

ChallengePlaza_hns_SageTrainer_1::
	goto_if_unset FLAG_BADGE03_GET, ChallengePlaza_hns_SageTrainer_NotReady
	msgbox ChallengePlaza_hns_Text_SageTrainer_1_Intro, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_SageTrainer_1_Battle
	case NO, ChallengePlaza_hns_SageTrainer_ComeBackAgain
	release
	end

ChallengePlaza_hns_SageTrainer_1_Battle::
	msgbox ChallengePlaza_hns_Text_SageTrainer_1_Battle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAGE_TRAINER_1_HNS, ChallengePlaza_hns_Text_SageTrainer_1_BattleEnd
	setvar VAR_SAGE_TRAINER, 2
	msgbox ChallengePlaza_hns_Text_SageTrainer_1_AfterBattle1, MSGBOX_DEFAULT
	applymovement SageTrainer, ChallengePlaza_hns_SageTrainer_Movement_0
	waitmovement 0
	delay 55
	msgbox ChallengePlaza_hns_Text_SageTrainer_1_AfterBattle2, MSGBOX_DEFAULT
	applymovement SageTrainer, ChallengePlaza_hns_SageTrainer_Movement_1
	waitmovement 0
	delay 55
	msgbox ChallengePlaza_hns_Text_SageTrainer_1_AfterBattle3, MSGBOX_DEFAULT
	giveitem ITEM_NUGGET
	msgbox ChallengePlaza_hns_Text_SageTrainer_1_End
	release
	end

ChallengePlaza_hns_SageTrainer_2::
	goto_if_unset FLAG_BADGE08_GET, ChallengePlaza_hns_SageTrainer_NotReady
	msgbox ChallengePlaza_hns_Text_SageTrainer_2_Intro, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_SageTrainer_2_Battle
	case NO, ChallengePlaza_hns_SageTrainer_ComeBackAgain
	release
	end

ChallengePlaza_hns_SageTrainer_2_Battle::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, 1, ChallengePlaza_hns_SageTrainer_2_TooManyMons
	msgbox ChallengePlaza_hns_Text_SageTrainer_1_Battle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAGE_TRAINER_2_HNS, ChallengePlaza_hns_Text_SageTrainer_1_BattleEnd
	setvar VAR_SAGE_TRAINER, 3
	msgbox ChallengePlaza_hns_Text_SageTrainer_2_AfterBattle1, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	msgbox ChallengePlaza_hns_Text_SageTrainer_Ellipsis, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_PARTY_RELEARNER_HNS
	delay 16
	fadescreen FADE_FROM_BLACK
	msgbox ChallengePlaza_hns_Text_SageTrainer_2_AfterBattle2, MSGBOX_DEFAULT
	release
	end


ChallengePlaza_hns_SageTrainer_2_TooManyMons::
	msgbox ChallengePlaza_hns_Text_SageTrainer_2_TooManyMons, MSGBOX_DEFAULT
	release
	end

ChallengePlaza_hns_SageTrainer_3::
	goto_if_unset FLAG_IS_CHAMPION, ChallengePlaza_hns_SageTrainer_NotReady
	msgbox ChallengePlaza_hns_Text_SageTrainer_3_Intro, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_SageTrainer_3_Battle
	case NO, ChallengePlaza_hns_SageTrainer_ComeBackAgain
	release
	end

ChallengePlaza_hns_SageTrainer_3_Battle::
	msgbox ChallengePlaza_hns_Text_SageTrainer_1_Battle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAGE_TRAINER_3_HNS, ChallengePlaza_hns_Text_SageTrainer_1_BattleEnd
	setvar VAR_SAGE_TRAINER, 4
	msgbox ChallengePlaza_hns_Text_SageTrainer_3_AfterBattle1, MSGBOX_DEFAULT
	setflag FLAG_MEGA_RING_GET_HNS
	giveitem ITEM_MEGA_RING
	msgbox ChallengePlaza_hns_Text_SageTrainer_3_AfterBattle2, MSGBOX_DEFAULT
	release
	end

ChallengePlaza_hns_SageTrainer_NotReady::
	msgbox ChallengePlaza_hns_Text_SageTrainer_NotReady, MSGBOX_DEFAULT
	release
	end

ChallengePlaza_hns_SageTrainer_ComeBackAgain::
	msgbox ChallengePlaza_hns_Text_SageTrainer_ComeBackAgain, MSGBOX_DEFAULT
	release
	end

ChallengePlaza_hns_SageTrainer_Movement_0::
	face_away_player
	step_end

ChallengePlaza_hns_SageTrainer_Movement_1::
	face_player
	step_end


ChallengePlaza_hns_Mareep::
	lock
	faceplayer
	playmoncry SPECIES_MAREEP, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Mareep, MSGBOX_DEFAULT
	waitmoncry
	release
	end


ChallengePlaza_hns_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	goto_if_unset FLAG_MEGA_RING_GET_HNS, ChallengePlaza_hns_PokeEnd
	goto_if_set FLAG_MEGA_STEELIX_GET_HNS, ChallengePlaza_hns_PokeEnd
	playse SE_PIN
	applymovement LOCALID_CHALLENGE_STEELIX, Common_Movement_ExclamationMark
	delay 55
	waitse
	bufferspeciesname STR_VAR_1, SPECIES_STEELIX
	msgbox ChallengePlaza_hns_Text_MegaBattle, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_SteelixBattle
	case NO, ChallengePlaza_hns_PokeEnd
	release
	end

ChallengePlaza_hns_SteelixBattle::
	closemessage
	setwildbattle SPECIES_STEELIX_MEGA, 65, ITEM_NONE
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ChallengePlaza_hns_SteelixBattleWon
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ChallengePlaza_hns_MegaBattleLost
	release
	end

ChallengePlaza_hns_SteelixBattleWon::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	bufferspeciesname STR_VAR_1, SPECIES_STEELIX
	bufferitemname STR_VAR_2, ITEM_STEELIXITE
	msgbox ChallengePlaza_hns_Text_MegaAfterBattle, MSGBOX_DEFAULT
	setflag FLAG_MEGA_STEELIX_GET_HNS
	giveitem ITEM_STEELIXITE
	release
	end

ChallengePlaza_hns_Ampharos::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Ampharos, MSGBOX_DEFAULT
	waitmoncry
	goto_if_unset FLAG_MEGA_RING_GET_HNS, ChallengePlaza_hns_PokeEnd
	goto_if_set FLAG_MEGA_AMPHAROS_GET_HNS, ChallengePlaza_hns_PokeEnd
	playse SE_PIN
	applymovement LOCALID_CHALLENGE_AMPHAROS, Common_Movement_ExclamationMark
	delay 55
	waitse
	bufferspeciesname STR_VAR_1, SPECIES_AMPHAROS
	msgbox ChallengePlaza_hns_Text_MegaBattle, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_AmpharosBattle
	case NO, ChallengePlaza_hns_PokeEnd
	release
	end

ChallengePlaza_hns_AmpharosBattle::
	closemessage
	setwildbattle SPECIES_AMPHAROS_MEGA, 65, ITEM_NONE
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ChallengePlaza_hns_AmpharosBattleWon
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ChallengePlaza_hns_MegaBattleLost
	release
	end

ChallengePlaza_hns_AmpharosBattleWon::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	waitse
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Ampharos, MSGBOX_DEFAULT
	waitmoncry
	bufferspeciesname STR_VAR_1, SPECIES_AMPHAROS
	bufferitemname STR_VAR_2, ITEM_AMPHAROSITE
	msgbox ChallengePlaza_hns_Text_MegaAfterBattle, MSGBOX_DEFAULT
	setflag FLAG_MEGA_AMPHAROS_GET_HNS
	giveitem ITEM_AMPHAROSITE
	release
	end

ChallengePlaza_hns_Heracross::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HERACROSS, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Heracross, MSGBOX_DEFAULT
	waitmoncry
	goto_if_unset FLAG_MEGA_RING_GET_HNS, ChallengePlaza_hns_PokeEnd
	goto_if_set FLAG_MEGA_HERACROSS_GET_HNS, ChallengePlaza_hns_PokeEnd
	playse SE_PIN
	applymovement LOCALID_CHALLENGE_HERACROSS, Common_Movement_ExclamationMark
	delay 55
	waitse
	bufferspeciesname STR_VAR_1, SPECIES_HERACROSS
	msgbox ChallengePlaza_hns_Text_MegaBattle, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_HeracrossBattle
	case NO, ChallengePlaza_hns_PokeEnd
	release
	end

ChallengePlaza_hns_HeracrossBattle::
	closemessage
	setwildbattle SPECIES_HERACROSS_MEGA, 65, ITEM_NONE
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ChallengePlaza_hns_HeracrossBattleWon
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ChallengePlaza_hns_MegaBattleLost
	release
	end

ChallengePlaza_hns_HeracrossBattleWon::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	waitse
	playmoncry SPECIES_HERACROSS, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Heracross, MSGBOX_DEFAULT
	waitmoncry
	bufferspeciesname STR_VAR_1, SPECIES_HERACROSS
	bufferitemname STR_VAR_2, ITEM_HERACRONITE
	msgbox ChallengePlaza_hns_Text_MegaAfterBattle, MSGBOX_DEFAULT
	setflag FLAG_MEGA_HERACROSS_GET_HNS
	giveitem ITEM_HERACRONITE
	release
	end

ChallengePlaza_hns_Houndoom::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Houndoom, MSGBOX_DEFAULT
	waitmoncry
	goto_if_unset FLAG_MEGA_RING_GET_HNS, ChallengePlaza_hns_PokeEnd
	goto_if_set FLAG_MEGA_HOUNDOOM_GET_HNS, ChallengePlaza_hns_PokeEnd
	playse SE_PIN
	applymovement LOCALID_CHALLENGE_HOUNDOOM, Common_Movement_ExclamationMark
	delay 55
	waitse
	bufferspeciesname STR_VAR_1, SPECIES_HOUNDOOM
	msgbox ChallengePlaza_hns_Text_MegaBattle, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_HoundoomBattle
	case NO, ChallengePlaza_hns_PokeEnd
	release
	end

ChallengePlaza_hns_HoundoomBattle::
	closemessage
	setwildbattle SPECIES_HOUNDOOM_MEGA, 65, ITEM_NONE
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ChallengePlaza_hns_HoundoomBattleWon
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ChallengePlaza_hns_MegaBattleLost
	release
	end

ChallengePlaza_hns_HoundoomBattleWon::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	waitse
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Houndoom, MSGBOX_DEFAULT
	waitmoncry
	bufferspeciesname STR_VAR_1, SPECIES_HOUNDOOM
	bufferitemname STR_VAR_2, ITEM_HOUNDOOMINITE
	msgbox ChallengePlaza_hns_Text_MegaAfterBattle, MSGBOX_DEFAULT
	setflag FLAG_MEGA_HOUNDOOM_GET_HNS
	giveitem ITEM_HOUNDOOMINITE
	release
	end

ChallengePlaza_hns_Scizor::
	lock
	msgbox ChallengePlaza_hns_Text_Scizor, MSGBOX_DEFAULT
	goto_if_unset FLAG_MEGA_RING_GET_HNS, ChallengePlaza_hns_PokeEnd
	goto_if_set FLAG_MEGA_SCIZOR_GET_HNS, ChallengePlaza_hns_PokeEnd
	applymovement LOCALID_CHALLENGE_SCIZOR, Common_Movement_FacePlayer
	playse SE_PIN
	applymovement LOCALID_CHALLENGE_SCIZOR, Common_Movement_ExclamationMark
	delay 55
	waitse
	bufferspeciesname STR_VAR_1, SPECIES_SCIZOR
	msgbox ChallengePlaza_hns_Text_MegaBattle, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_ScizorBattle
	case NO, ChallengePlaza_hns_PokeEnd
	release
	end

ChallengePlaza_hns_ScizorBattle::
	closemessage
	setwildbattle SPECIES_SCIZOR_MEGA, 65, ITEM_NONE
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ChallengePlaza_hns_ScizorBattleWon
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ChallengePlaza_hns_MegaBattleLost
	release
	end

ChallengePlaza_hns_ScizorBattleWon::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	msgbox ChallengePlaza_hns_Text_Scizor, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_SCIZOR
	bufferitemname STR_VAR_2, ITEM_SCIZORITE
	msgbox ChallengePlaza_hns_Text_MegaAfterBattle, MSGBOX_DEFAULT
	setflag FLAG_MEGA_SCIZOR_GET_HNS
	giveitem ITEM_SCIZORITE
	release
	end

ChallengePlaza_hns_Tyranitar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TYRANITAR, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Tyranitar, MSGBOX_DEFAULT
	waitmoncry
	goto_if_unset FLAG_MEGA_RING_GET_HNS, ChallengePlaza_hns_PokeEnd
	goto_if_set FLAG_MEGA_TYRANITAR_GET_HNS, ChallengePlaza_hns_PokeEnd
	playse SE_PIN
	applymovement LOCALID_CHALLENGE_TYRANITAR, Common_Movement_ExclamationMark
	delay 55
	waitse
	bufferspeciesname STR_VAR_1, SPECIES_TYRANITAR
	msgbox ChallengePlaza_hns_Text_MegaBattle, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, ChallengePlaza_hns_TyranitarBattle
	case NO, ChallengePlaza_hns_PokeEnd
	release
	end

ChallengePlaza_hns_TyranitarBattle::
	closemessage
	setwildbattle SPECIES_TYRANITAR_MEGA, 65, ITEM_NONE
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_WILD_RUNNING
	setflag FLAG_SMART_WILD_AI
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ChallengePlaza_hns_TyranitarBattleWon
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ChallengePlaza_hns_MegaBattleLost
	release
	end

ChallengePlaza_hns_TyranitarBattleWon::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	waitse
	playmoncry SPECIES_TYRANITAR, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Tyranitar, MSGBOX_DEFAULT
	waitmoncry
	bufferspeciesname STR_VAR_1, SPECIES_TYRANITAR
	bufferitemname STR_VAR_2, ITEM_TYRANITARITE
	msgbox ChallengePlaza_hns_Text_MegaAfterBattle, MSGBOX_DEFAULT
	setflag FLAG_MEGA_TYRANITAR_GET_HNS
	giveitem ITEM_TYRANITARITE
	release
	end


ChallengePlaza_hns_Politoed::
	lock
	faceplayer
	playmoncry SPECIES_POLITOED, CRY_MODE_NORMAL
	msgbox ChallengePlaza_hns_Text_Politoed, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 55
	setflag FLAG_POLITOED_SHOP
	msgbox ChallengePlaza_hns_Text_PolitoedShop, MSGBOX_DEFAULT
	pokemart ChallengePlaza_hns_PolitoedShop
	msgbox ChallengePlaza_hns_Text_PolitoedEnd, MSGBOX_DEFAULT
	release
	end

ChallengePlaza_hns_PokeEnd::
	release
	end

ChallengePlaza_hns_MegaBattleLost::
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_WILD_RUNNING
	clearflag FLAG_SMART_WILD_AI
	release
	end

ChallengePlaza_hns_Text_SageTrainer_0_Intro:
	.string "Zzz.......\p"
	.string "Zzz.......\p"
	.string "....Hrgn?\p"
	.string "O-Oh! A TRAINER!\n"
	.string "Ahem...\p"
	.string "Welcome, young TRAINER!\p"
	.string "This is the CHALLENGE PLAZA,\n"
	.string "where the top of the top\l"
	.string "train endlessly!\p"
	.string "...Well, it will be, one\n"
	.string "day.\p"
	.string "But no matter! You're here,\n"
	.string "so you can take part in\l"
	.string "my training! But first,\l"
	.string "let me gauge your power level.$"

ChallengePlaza_hns_Text_SageTrainer_1_Intro:
	.string "Hmm...\p"
	.string "Ah, yes...\p"
	.string "It seems like you are ready\n"
	.string "for the first part of my\l"
	.string "training regimen!\p"
	.string "We will have a standard MOéMON\n"
	.string "battle, each one of us will\l"
	.string "give it their all! Are you\l"
	.string "ready?$"

ChallengePlaza_hns_Text_SageTrainer_1_Battle:
	.string "Then it's on!$"

ChallengePlaza_hns_Text_SageTrainer_1_BattleEnd:
	.string "That's a wrap!$"

ChallengePlaza_hns_Text_SageTrainer_1_AfterBattle1:
	.string "Huh... I wasn't expecting to\n"
	.string "lose so quickly...\p"
	.string "Hm, young TRAINER!\p"
	.string "You have shown a great amount\n"
	.string "of effort in this battle!\p"
	.string "As a reward, I bestow you...$"

ChallengePlaza_hns_Text_SageTrainer_1_AfterBattle2:
	.string "...Do I even have something\n"
	.string "to give? I didn't prepare\l"
	.string "for this...\p"
	.string "I guess I can get rid of\n"
	.string "that old thing...$"

ChallengePlaza_hns_Text_SageTrainer_1_AfterBattle3:
	.string "As a reward you for your\n"
	.string "efforts, you may receive this.$"

ChallengePlaza_hns_Text_SageTrainer_1_DexNav:
	.string "{PLAYER} obtained the DEXNAV.$"

ChallengePlaza_hns_Text_SageTrainer_1_End:
	.string "Now, shoo! I gotta think of\n"
	.string "something new.$"

ChallengePlaza_hns_Text_SageTrainer_2_Intro:
	.string "Hmm...\p"
	.string "Ah, yes...\p"
	.string "It seems like you are ready\n"
	.string "for the second part of my\l"
	.string "training regimen!\p"
	.string "You will face me using only\n"
	.string "one MOéMON in your party.\p"
	.string "I won't go easy on you, are\n"
	.string "you ready?$"

ChallengePlaza_hns_Text_SageTrainer_2_AfterBattle1:
	.string "Oh come on! It was four\n"
	.string "against one! Man...\p"
	.string "Ahem. Young TRAINER.\p"
	.string "You have shown a great amount\n"
	.string "of effort during this battle!\p"
	.string "As a reward, I bestow you my\n"
	.string "knowledge.$"

ChallengePlaza_hns_Text_SageTrainer_2_AfterBattle2:
	.string "Alright, now you can\n"
	.string "teach your MOéMON moves\l"
	.string "they've already learned.\p"
	.string "You now have the strength to\n"
	.string "become a CHAMPION. Fight on!$"

ChallengePlaza_hns_Text_SageTrainer_2_TooManyMons:
	.string "Then it's... Huh?\p"
	.string "Hey, no cheating! You\n"
	.string "can't have more than one\l"
	.string "MOéMON!$"

ChallengePlaza_hns_Text_SageTrainer_3_Intro:
	.string "Wow, you're already a\n"
	.string "CHAMPION! Then I guess\l"
	.string "you're ready for the third\l"
	.string "part of my training regimen!\p"
	.string "I've seen how the ELITE fight,\n"
	.string "so be ready to face the top\l"
	.string "of the top. Are you ready?$"

ChallengePlaza_hns_Text_SageTrainer_3_AfterBattle1:
	.string "......\p"
	.string "......\p"
	.string "Ahem. Young TRAINER.\p"
	.string "You have shown a great amount\n"
	.string "of effort during this battle.\p"
	.string "As a reward, I bestow you...\p"
	.string "......\p"
	.string "...Just take this.$"

ChallengePlaza_hns_Text_SageTrainer_3_AfterBattle2:
	.string "This is a MEGA RING.\p"
	.string "It lets you MEGA EVOLVE your\n"
	.string "MOéMON. Think of it as some\l"
	.string "kind of temporary evolution.\p"
	.string "It only works on some species,\n"
	.string "and you'll need the associated\l"
	.string "MEGA STONES with it.\p"
	.string "I didn't have any with me, so\n"
	.string "it's kind of useless to me.$"

ChallengePlaza_hns_Text_SageTrainer_3_MegaRing:
	.string "{PLAYER} obtained the MEGA RING.$"

ChallengePlaza_hns_Text_SageTrainer_NotReady:
	.string "Hm, you don't seem to\n"
	.string "be ready yet. Come back\l"
	.string "with more experience.$"

ChallengePlaza_hns_Text_SageTrainer_SomethingNew:
	.string "I have to think of something\n"
	.string "new...$"

ChallengePlaza_hns_Text_SageTrainer_ComeBackAgain:
	.string "Oh, well, if you change\n"
	.string "your mind, you know where\l"
	.string "to find me.$"

ChallengePlaza_hns_Text_SageTrainer_Ellipsis:
	.string "...............\p"
	.string "...............\p"
	.string "...............\p"
	.string "...............$"

ChallengePlaza_hns_Text_Mareep:
	.string "MAREEP: Reeep!$"

ChallengePlaza_hns_Text_Steelix:
	.string "STEELIX: GRRRIND!$"

ChallengePlaza_hns_Text_Ampharos:
	.string "AMPHAROS: Phaaaa!$"

ChallengePlaza_hns_Text_Heracross:
	.string "HERACROSS: Hurk!$"

ChallengePlaza_hns_Text_Scizor:
	.string "SCIZOR: ......$"

ChallengePlaza_hns_Text_Tyranitar:
	.string "TYRANITAR: RAAAAAA!$"

ChallengePlaza_hns_Text_Houndoom:
	.string "HOUNDOOM: WOOF! WOOF!$"

ChallengePlaza_hns_Text_MegaBattle:
	.string "The {STR_VAR_1} reacted to your\n"
	.string "MEGA RING!\p"
	.string "It seems like {STR_VAR_1} wants\n"
	.string "to battle you. Do you accept?$"

ChallengePlaza_hns_Text_MegaAfterBattle:
	.string "{STR_VAR_1} has\n"
	.string "recognized your strength.\p"
	.string "It seems to have something\n"
	.string "in its mouth...$"

ChallengePlaza_hns_Text_MegaStone:
	.string "{PLAYER} received the\n"
	.string "{STR_VAR_2}.$"

ChallengePlaza_hns_Text_Politoed:
	.string "Croa! Croa!$"

ChallengePlaza_hns_Text_PolitoedShop:
	.string "It seems that the POLITOED\n"
	.string "wants to trade with you.\p"
	.string "Take a look at his wares?$"

ChallengePlaza_hns_Text_PolitoedEnd:
	.string "Croaaaaaa!$"

	.align 2
ChallengePlaza_hns_PolitoedShop::
	.2byte ITEM_CHILAN_BERRY
	.2byte ITEM_LIECHI_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_LANSAT_BERRY
	.2byte ITEM_MICLE_BERRY
	release
	end
