# 1 "data/maps/Route22_TestZone/scripts.pory"

# 2 "data/maps/Route22_TestZone/scripts.pory"
.equ CHECKED_MUSHROOMS,  FLAG_TEMP_1
# 3 "data/maps/Route22_TestZone/scripts.pory"
.equ HAS_BIG_MUSHROOM,   FLAG_TEMP_2
# 4 "data/maps/Route22_TestZone/scripts.pory"
.equ HAS_TINY_MUSHROOMS, FLAG_TEMP_3
# 5 "data/maps/Route22_TestZone/scripts.pory"
.equ HAS_BOTH_MUSHROOMS, FLAG_TEMP_4
# 6 "data/maps/Route22_TestZone/scripts.pory"

# 7 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_MapScripts::
# 8 "data/maps/Route22_TestZone/scripts.pory"
    .byte 0
# 9 "data/maps/Route22_TestZone/scripts.pory"

# 10 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_TestHeptaNo::
# 11 "data/maps/Route22_TestZone/scripts.pory"
	lockall
# 12 "data/maps/Route22_TestZone/scripts.pory"
    faceplayer
# 13 "data/maps/Route22_TestZone/scripts.pory"
	checkflag FLAG_BEAT_HEPTANO_TEST
# 14 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq Route22_TestZone_EventScript_TestHeptaNo_AlreadyDone
# 15 "data/maps/Route22_TestZone/scripts.pory"
	msgbox Route22_TestZone_Text_TestHeptaNoIntro
# 16 "data/maps/Route22_TestZone/scripts.pory"
	trainerbattle_no_intro TRAINER_HEPTANO_TEST, Route22_Text_TestHeptaNoDefeat
# 17 "data/maps/Route22_TestZone/scripts.pory"
	msgbox Route22_TestZone_Text_TestHeptaNoAfter
# 18 "data/maps/Route22_TestZone/scripts.pory"
	setflag FLAG_BEAT_HEPTANO_TEST
# 19 "data/maps/Route22_TestZone/scripts.pory"
	releaseall
# 20 "data/maps/Route22_TestZone/scripts.pory"
	end
# 21 "data/maps/Route22_TestZone/scripts.pory"

# 22 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_TestHeptaNo_AlreadyDone::
# 23 "data/maps/Route22_TestZone/scripts.pory"
    msgbox Route22_TestZone_Text_TestHeptanoBeaten
# 24 "data/maps/Route22_TestZone/scripts.pory"
	releaseall
# 25 "data/maps/Route22_TestZone/scripts.pory"
	end
# 26 "data/maps/Route22_TestZone/scripts.pory"

# 27 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_HeptaNoBall::
# 28 "data/maps/Route22_TestZone/scripts.pory"
	lock
# 29 "data/maps/Route22_TestZone/scripts.pory"
	faceplayer
# 30 "data/maps/Route22_TestZone/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HEPTANO
# 31 "data/maps/Route22_TestZone/scripts.pory"
	givemon SPECIES_HEPTANO, 30
# 32 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route22_TestZone_EventScript_GetHeptaNoParty
# 33 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route22_TestZone_EventScript_GetHeptaNoPC
# 34 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 35 "data/maps/Route22_TestZone/scripts.pory"
	release
# 36 "data/maps/Route22_TestZone/scripts.pory"
	end
# 37 "data/maps/Route22_TestZone/scripts.pory"

# 38 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_GetHeptaNoParty::
# 39 "data/maps/Route22_TestZone/scripts.pory"
	removeobject LOCALID_ROUTE22_TESTZONE_HEPTANO_POKEBALL
# 40 "data/maps/Route22_TestZone/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 41 "data/maps/Route22_TestZone/scripts.pory"
	message Route22_TestZone_Text_ObtainedAnHeptaNo
# 42 "data/maps/Route22_TestZone/scripts.pory"
	waitmessage
# 43 "data/maps/Route22_TestZone/scripts.pory"
	waitfanfare
# 44 "data/maps/Route22_TestZone/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HEPTANO
# 45 "data/maps/Route22_TestZone/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 46 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_TestZone_EventScript_SetGotHeptaNo
# 47 "data/maps/Route22_TestZone/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 48 "data/maps/Route22_TestZone/scripts.pory"
	call EventScript_ChangePokemonNickname
# 49 "data/maps/Route22_TestZone/scripts.pory"
	goto Route22_TestZone_EventScript_SetGotHeptaNo
# 50 "data/maps/Route22_TestZone/scripts.pory"
	end
# 51 "data/maps/Route22_TestZone/scripts.pory"

# 52 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_GetHeptaNoPC::
# 53 "data/maps/Route22_TestZone/scripts.pory"
	removeobject LOCALID_ROUTE22_TESTZONE_HEPTANO_POKEBALL
# 54 "data/maps/Route22_TestZone/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 55 "data/maps/Route22_TestZone/scripts.pory"
	message Route22_TestZone_Text_ObtainedAnHeptaNo
# 56 "data/maps/Route22_TestZone/scripts.pory"
	waitmessage
# 57 "data/maps/Route22_TestZone/scripts.pory"
	waitfanfare
# 58 "data/maps/Route22_TestZone/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HEPTANO
# 59 "data/maps/Route22_TestZone/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 60 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_TestZone_EventScript_TransferHeptaNoToPC
# 61 "data/maps/Route22_TestZone/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 62 "data/maps/Route22_TestZone/scripts.pory"
	goto Route22_TestZone_EventScript_TransferHeptaNoToPC
# 63 "data/maps/Route22_TestZone/scripts.pory"
	end
# 64 "data/maps/Route22_TestZone/scripts.pory"

# 65 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_TransferHeptaNoToPC::
# 66 "data/maps/Route22_TestZone/scripts.pory"
	call EventScript_TransferredToPC
# 67 "data/maps/Route22_TestZone/scripts.pory"
	goto Route22_TestZone_EventScript_SetGotHeptaNo
# 68 "data/maps/Route22_TestZone/scripts.pory"
	end
# 69 "data/maps/Route22_TestZone/scripts.pory"

# 70 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_MalwaragonBall::
# 71 "data/maps/Route22_TestZone/scripts.pory"
	lock
# 72 "data/maps/Route22_TestZone/scripts.pory"
	faceplayer
# 73 "data/maps/Route22_TestZone/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MALWARAGON
# 74 "data/maps/Route22_TestZone/scripts.pory"
	givemon SPECIES_MALWARAGON, 30
# 75 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route22_TestZone_EventScript_GetMalwaragonParty
# 76 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route22_TestZone_EventScript_GetMalwaragonPC
# 77 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 78 "data/maps/Route22_TestZone/scripts.pory"
	release
# 79 "data/maps/Route22_TestZone/scripts.pory"
	end
# 80 "data/maps/Route22_TestZone/scripts.pory"

# 81 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_GetMalwaragonParty::
# 82 "data/maps/Route22_TestZone/scripts.pory"
	removeobject LOCALID_ROUTE22_TESTZONE_MALWARAGON_POKEBALL
# 83 "data/maps/Route22_TestZone/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 84 "data/maps/Route22_TestZone/scripts.pory"
	message Route22_TestZone_Text_ObtainedAnMalwaragon
# 85 "data/maps/Route22_TestZone/scripts.pory"
	waitmessage
# 86 "data/maps/Route22_TestZone/scripts.pory"
	waitfanfare
# 87 "data/maps/Route22_TestZone/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MALWARAGON
# 88 "data/maps/Route22_TestZone/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 89 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_TestZone_EventScript_SetGotMalwaragon
# 90 "data/maps/Route22_TestZone/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 91 "data/maps/Route22_TestZone/scripts.pory"
	call EventScript_ChangePokemonNickname
# 92 "data/maps/Route22_TestZone/scripts.pory"
	goto Route22_TestZone_EventScript_SetGotMalwaragon
# 93 "data/maps/Route22_TestZone/scripts.pory"
	end
# 94 "data/maps/Route22_TestZone/scripts.pory"

# 95 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_GetMalwaragonPC::
# 96 "data/maps/Route22_TestZone/scripts.pory"
	removeobject LOCALID_ROUTE22_TESTZONE_MALWARAGON_POKEBALL
# 97 "data/maps/Route22_TestZone/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 98 "data/maps/Route22_TestZone/scripts.pory"
	message Route22_TestZone_Text_ObtainedAnMalwaragon
# 99 "data/maps/Route22_TestZone/scripts.pory"
	waitmessage
# 100 "data/maps/Route22_TestZone/scripts.pory"
	waitfanfare
# 101 "data/maps/Route22_TestZone/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MALWARAGON
# 102 "data/maps/Route22_TestZone/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 103 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_TestZone_EventScript_TransferMalwaragonToPC
# 104 "data/maps/Route22_TestZone/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 105 "data/maps/Route22_TestZone/scripts.pory"
	goto Route22_TestZone_EventScript_TransferMalwaragonToPC
# 106 "data/maps/Route22_TestZone/scripts.pory"
	end
# 107 "data/maps/Route22_TestZone/scripts.pory"

# 108 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_TransferMalwaragonToPC::
# 109 "data/maps/Route22_TestZone/scripts.pory"
	call EventScript_TransferredToPC
# 110 "data/maps/Route22_TestZone/scripts.pory"
	goto Route22_TestZone_EventScript_SetGotMalwaragon
# 111 "data/maps/Route22_TestZone/scripts.pory"
	end
# 112 "data/maps/Route22_TestZone/scripts.pory"

# 113 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_SetGotHeptaNo::
# 114 "data/maps/Route22_TestZone/scripts.pory"
	setflag FLAG_GOT_HEPTANO
# 115 "data/maps/Route22_TestZone/scripts.pory"
	release
# 116 "data/maps/Route22_TestZone/scripts.pory"
	end
# 117 "data/maps/Route22_TestZone/scripts.pory"

# 118 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_SetGotMalwaragon::
# 119 "data/maps/Route22_TestZone/scripts.pory"
	setflag FLAG_GOT_MALWARAGON
# 120 "data/maps/Route22_TestZone/scripts.pory"
	release
# 121 "data/maps/Route22_TestZone/scripts.pory"
	end
# 122 "data/maps/Route22_TestZone/scripts.pory"

# 123 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_TestSign::
# 124 "data/maps/Route22_TestZone/scripts.pory"
	msgbox Route22_Text_TestSign, MSGBOX_SIGN
# 125 "data/maps/Route22_TestZone/scripts.pory"
	end
# 126 "data/maps/Route22_TestZone/scripts.pory"

# 127 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_Healer::
# 128 "data/maps/Route22_TestZone/scripts.pory"
    msgbox Route22_TestZone_Text_Healer
# 129 "data/maps/Route22_TestZone/scripts.pory"
    closemessage
# 130 "data/maps/Route22_TestZone/scripts.pory"
    call EventScript_OutOfCenterPartyHeal
# 131 "data/maps/Route22_TestZone/scripts.pory"
    release
# 132 "data/maps/Route22_TestZone/scripts.pory"
    end
# 133 "data/maps/Route22_TestZone/scripts.pory"

# 134 "data/maps/Route22_TestZone/scripts.pory"
Route22_TestZone_EventScript_Tutor::
# 135 "data/maps/Route22_TestZone/scripts.pory"
	lock
# 136 "data/maps/Route22_TestZone/scripts.pory"
	faceplayer
# 137 "data/maps/Route22_TestZone/scripts.pory"
	clearflag HAS_BIG_MUSHROOM
# 138 "data/maps/Route22_TestZone/scripts.pory"
	clearflag HAS_TINY_MUSHROOMS
# 139 "data/maps/Route22_TestZone/scripts.pory"
	clearflag HAS_BOTH_MUSHROOMS
# 140 "data/maps/Route22_TestZone/scripts.pory"
	goto_if_set CHECKED_MUSHROOMS, TwoIsland_House_EventScript_CheckPlayerHasMushrooms
# 141 "data/maps/Route22_TestZone/scripts.pory"
	msgbox TwoIsland_House_Text_TeachMonMoveForMushroom
# 142 "data/maps/Route22_TestZone/scripts.pory"
	setflag CHECKED_MUSHROOMS
# 143 "data/maps/Route22_TestZone/scripts.pory"
	goto TwoIsland_House_EventScript_CheckPlayerHasMushrooms
# 144 "data/maps/Route22_TestZone/scripts.pory"
	end
