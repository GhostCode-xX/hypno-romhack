.equ CHECKED_MUSHROOMS,  FLAG_TEMP_1
.equ HAS_BIG_MUSHROOM,   FLAG_TEMP_2
.equ HAS_TINY_MUSHROOMS, FLAG_TEMP_3
.equ HAS_BOTH_MUSHROOMS, FLAG_TEMP_4

Route22_TestZone_MapScripts::
    .byte 0

Route22_TestZone_EventScript_TestHeptaNo::
	lockall
    faceplayer
	checkflag FLAG_BEAT_HEPTANO_TEST
	goto_if_eq Route22_TestZone_EventScript_TestHeptaNo_AlreadyDone
	msgbox Route22_TestZone_Text_TestHeptaNoIntro
	trainerbattle_no_intro TRAINER_HEPTANO_TEST, Route22_Text_TestHeptaNoDefeat
	msgbox Route22_TestZone_Text_TestHeptaNoAfter
	setflag FLAG_BEAT_HEPTANO_TEST
	releaseall
	end

Route22_TestZone_EventScript_TestHeptaNo_AlreadyDone::
    msgbox Route22_TestZone_Text_TestHeptanoBeaten
	releaseall
	end

Route22_TestZone_EventScript_HeptaNoBall::
	lock
	faceplayer
	setvar VAR_TEMP_1, SPECIES_HEPTANO
	givemon SPECIES_HEPTANO, 30
	goto_if_eq VAR_RESULT, 0, Route22_TestZone_EventScript_GetHeptaNoParty
	goto_if_eq VAR_RESULT, 1, Route22_TestZone_EventScript_GetHeptaNoPC
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	release
	end

Route22_TestZone_EventScript_GetHeptaNoParty::
	removeobject LOCALID_ROUTE22_TESTZONE_HEPTANO_POKEBALL
	playfanfare MUS_LEVEL_UP
	message Route22_TestZone_Text_ObtainedAnHeptaNo
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HEPTANO
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route22_TestZone_EventScript_SetGotHeptaNo
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto Route22_TestZone_EventScript_SetGotHeptaNo
	end

Route22_TestZone_EventScript_GetHeptaNoPC::
	removeobject LOCALID_ROUTE22_TESTZONE_HEPTANO_POKEBALL
	playfanfare MUS_LEVEL_UP
	message Route22_TestZone_Text_ObtainedAnHeptaNo
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HEPTANO
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route22_TestZone_EventScript_TransferHeptaNoToPC
	call EventScript_NameReceivedBoxMon
	goto Route22_TestZone_EventScript_TransferHeptaNoToPC
	end

Route22_TestZone_EventScript_TransferHeptaNoToPC::
	call EventScript_TransferredToPC
	goto Route22_TestZone_EventScript_SetGotHeptaNo
	end

Route22_TestZone_EventScript_MalwaragonBall::
	lock
	faceplayer
	setvar VAR_TEMP_1, SPECIES_MALWARAGON
	givemon SPECIES_MALWARAGON, 30
	goto_if_eq VAR_RESULT, 0, Route22_TestZone_EventScript_GetMalwaragonParty
	goto_if_eq VAR_RESULT, 1, Route22_TestZone_EventScript_GetMalwaragonPC
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	release
	end

Route22_TestZone_EventScript_GetMalwaragonParty::
	removeobject LOCALID_ROUTE22_TESTZONE_MALWARAGON_POKEBALL
	playfanfare MUS_LEVEL_UP
	message Route22_TestZone_Text_ObtainedAnMalwaragon
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MALWARAGON
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route22_TestZone_EventScript_SetGotMalwaragon
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto Route22_TestZone_EventScript_SetGotMalwaragon
	end

Route22_TestZone_EventScript_GetMalwaragonPC::
	removeobject LOCALID_ROUTE22_TESTZONE_MALWARAGON_POKEBALL
	playfanfare MUS_LEVEL_UP
	message Route22_TestZone_Text_ObtainedAnMalwaragon
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MALWARAGON
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route22_TestZone_EventScript_TransferMalwaragonToPC
	call EventScript_NameReceivedBoxMon
	goto Route22_TestZone_EventScript_TransferMalwaragonToPC
	end

Route22_TestZone_EventScript_TransferMalwaragonToPC::
	call EventScript_TransferredToPC
	goto Route22_TestZone_EventScript_SetGotMalwaragon
	end

Route22_TestZone_EventScript_SetGotHeptaNo::
	setflag FLAG_GOT_HEPTANO
	release
	end

Route22_TestZone_EventScript_SetGotMalwaragon::
	setflag FLAG_GOT_MALWARAGON
	release
	end

Route22_TestZone_EventScript_TestSign::
	msgbox Route22_Text_TestSign, MSGBOX_SIGN
	end

Route22_TestZone_EventScript_Healer::
    msgbox Route22_TestZone_Text_Healer
    closemessage
    call EventScript_OutOfCenterPartyHeal
    release
    end

Route22_TestZone_EventScript_Tutor::
	lock
	faceplayer
	clearflag HAS_BIG_MUSHROOM
	clearflag HAS_TINY_MUSHROOMS
	clearflag HAS_BOTH_MUSHROOMS
	goto_if_set CHECKED_MUSHROOMS, TwoIsland_House_EventScript_CheckPlayerHasMushrooms
	msgbox TwoIsland_House_Text_TeachMonMoveForMushroom
	setflag CHECKED_MUSHROOMS
	goto TwoIsland_House_EventScript_CheckPlayerHasMushrooms
	end
