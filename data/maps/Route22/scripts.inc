# 1 "data/maps/Route22/scripts.pory"

# 2 "data/maps/Route22/scripts.pory"
Route22_MapScripts::
# 3 "data/maps/Route22/scripts.pory"
	.byte 0
# 4 "data/maps/Route22/scripts.pory"

# 5 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalTriggerTop::
# 6 "data/maps/Route22/scripts.pory"
	lockall
# 7 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 0
# 8 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_EarlyRival
# 9 "data/maps/Route22/scripts.pory"
	end
# 10 "data/maps/Route22/scripts.pory"

# 11 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalTriggerMid::
# 12 "data/maps/Route22/scripts.pory"
	lockall
# 13 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 1
# 14 "data/maps/Route22/scripts.pory"
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
# 15 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_EarlyRival
# 16 "data/maps/Route22/scripts.pory"
	end
# 17 "data/maps/Route22/scripts.pory"

# 18 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalTriggerBottom::
# 19 "data/maps/Route22/scripts.pory"
	lockall
# 20 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 2
# 21 "data/maps/Route22/scripts.pory"
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
# 22 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_EarlyRival
# 23 "data/maps/Route22/scripts.pory"
	end
# 24 "data/maps/Route22/scripts.pory"

# 25 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRival::
# 26 "data/maps/Route22/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 27 "data/maps/Route22/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 28 "data/maps/Route22/scripts.pory"
	addobject LOCALID_ROUTE22_RIVAL
# 29 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalApproach
# 30 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalApproach
# 31 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalApproachBottom
# 32 "data/maps/Route22/scripts.pory"
	delay 6
# 33 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_EarlyRivalIntro
# 34 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_EarlyRivalSquirtle
# 35 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_EarlyRivalBulbasaur
# 36 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_EarlyRivalCharmander
# 37 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_EarlyRivalPostBattle
# 38 "data/maps/Route22/scripts.pory"
	closemessage
# 39 "data/maps/Route22/scripts.pory"
	delay 10
# 40 "data/maps/Route22/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 41 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalExit
# 42 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalExit
# 43 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalExitBottom
# 44 "data/maps/Route22/scripts.pory"
	fadedefaultbgm
# 45 "data/maps/Route22/scripts.pory"
	removeobject LOCALID_ROUTE22_RIVAL
# 46 "data/maps/Route22/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 2
# 47 "data/maps/Route22/scripts.pory"
	releaseall
# 48 "data/maps/Route22/scripts.pory"
	end
# 49 "data/maps/Route22/scripts.pory"

# 50 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalApproach::
# 51 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
# 52 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 53 "data/maps/Route22/scripts.pory"
	return
# 54 "data/maps/Route22/scripts.pory"

# 55 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalApproachBottom::
# 56 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
# 57 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
# 58 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 59 "data/maps/Route22/scripts.pory"
	return
# 60 "data/maps/Route22/scripts.pory"

# 61 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalSquirtle::
# 62 "data/maps/Route22/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
# 63 "data/maps/Route22/scripts.pory"
	return
# 64 "data/maps/Route22/scripts.pory"

# 65 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalBulbasaur::
# 66 "data/maps/Route22/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
# 67 "data/maps/Route22/scripts.pory"
	return
# 68 "data/maps/Route22/scripts.pory"

# 69 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalCharmander::
# 70 "data/maps/Route22/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
# 71 "data/maps/Route22/scripts.pory"
	return
# 72 "data/maps/Route22/scripts.pory"

# 73 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalExit::
# 74 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExit
# 75 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 76 "data/maps/Route22/scripts.pory"
	return
# 77 "data/maps/Route22/scripts.pory"

# 78 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalExitBottom::
# 79 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExitBottom
# 80 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 81 "data/maps/Route22/scripts.pory"
	return
# 82 "data/maps/Route22/scripts.pory"

# 83 "data/maps/Route22/scripts.pory"
Route22_Movement_UnusedRivalExit:: @ 8
# 84 "data/maps/Route22/scripts.pory"
	walk_right
# 85 "data/maps/Route22/scripts.pory"
	walk_right
# 86 "data/maps/Route22/scripts.pory"
	walk_right
# 87 "data/maps/Route22/scripts.pory"
	walk_right
# 88 "data/maps/Route22/scripts.pory"
	walk_right
# 89 "data/maps/Route22/scripts.pory"
	walk_right
# 90 "data/maps/Route22/scripts.pory"
	walk_right
# 91 "data/maps/Route22/scripts.pory"
	step_end
# 92 "data/maps/Route22/scripts.pory"

# 93 "data/maps/Route22/scripts.pory"
Route22_Movement_EarlyRivalExit::
# 94 "data/maps/Route22/scripts.pory"
	walk_down
# 95 "data/maps/Route22/scripts.pory"
	walk_right
# 96 "data/maps/Route22/scripts.pory"
	walk_right
# 97 "data/maps/Route22/scripts.pory"
	walk_right
# 98 "data/maps/Route22/scripts.pory"
	walk_right
# 99 "data/maps/Route22/scripts.pory"
	walk_right
# 100 "data/maps/Route22/scripts.pory"
	walk_down
# 101 "data/maps/Route22/scripts.pory"
	walk_down
# 102 "data/maps/Route22/scripts.pory"
	walk_down
# 103 "data/maps/Route22/scripts.pory"
	walk_down
# 104 "data/maps/Route22/scripts.pory"
	walk_down
# 105 "data/maps/Route22/scripts.pory"
	walk_down
# 106 "data/maps/Route22/scripts.pory"
	step_end
# 107 "data/maps/Route22/scripts.pory"

# 108 "data/maps/Route22/scripts.pory"
Route22_Movement_EarlyRivalExitBottom::
# 109 "data/maps/Route22/scripts.pory"
	walk_right
# 110 "data/maps/Route22/scripts.pory"
	walk_right
# 111 "data/maps/Route22/scripts.pory"
	walk_right
# 112 "data/maps/Route22/scripts.pory"
	walk_right
# 113 "data/maps/Route22/scripts.pory"
	walk_down
# 114 "data/maps/Route22/scripts.pory"
	walk_down
# 115 "data/maps/Route22/scripts.pory"
	walk_down
# 116 "data/maps/Route22/scripts.pory"
	walk_down
# 117 "data/maps/Route22/scripts.pory"
	walk_down
# 118 "data/maps/Route22/scripts.pory"
	walk_down
# 119 "data/maps/Route22/scripts.pory"
	walk_down
# 120 "data/maps/Route22/scripts.pory"
	step_end
# 121 "data/maps/Route22/scripts.pory"

# 122 "data/maps/Route22/scripts.pory"
Route22_Movement_RivalApproach::
# 123 "data/maps/Route22/scripts.pory"
	walk_right
# 124 "data/maps/Route22/scripts.pory"
	walk_right
# 125 "data/maps/Route22/scripts.pory"
	walk_right
# 126 "data/maps/Route22/scripts.pory"
	walk_right
# 127 "data/maps/Route22/scripts.pory"
	walk_right
# 128 "data/maps/Route22/scripts.pory"
	walk_right
# 129 "data/maps/Route22/scripts.pory"
	walk_right
# 130 "data/maps/Route22/scripts.pory"
	step_end
# 131 "data/maps/Route22/scripts.pory"

# 132 "data/maps/Route22/scripts.pory"
Route22_Movement_RivalApproachBottom::
# 133 "data/maps/Route22/scripts.pory"
	walk_right
# 134 "data/maps/Route22/scripts.pory"
	walk_right
# 135 "data/maps/Route22/scripts.pory"
	walk_right
# 136 "data/maps/Route22/scripts.pory"
	walk_right
# 137 "data/maps/Route22/scripts.pory"
	walk_right
# 138 "data/maps/Route22/scripts.pory"
	walk_right
# 139 "data/maps/Route22/scripts.pory"
	walk_right
# 140 "data/maps/Route22/scripts.pory"
	walk_right
# 141 "data/maps/Route22/scripts.pory"
	walk_in_place_faster_down
# 142 "data/maps/Route22/scripts.pory"
	step_end
# 143 "data/maps/Route22/scripts.pory"

# 144 "data/maps/Route22/scripts.pory"
Route22_Movement_PlayerFaceRival::
# 145 "data/maps/Route22/scripts.pory"
	delay_16
# 146 "data/maps/Route22/scripts.pory"
	delay_16
# 147 "data/maps/Route22/scripts.pory"
	delay_16
# 148 "data/maps/Route22/scripts.pory"
	delay_16
# 149 "data/maps/Route22/scripts.pory"
	delay_16
# 150 "data/maps/Route22/scripts.pory"
	delay_16
# 151 "data/maps/Route22/scripts.pory"
	delay_16
# 152 "data/maps/Route22/scripts.pory"
	delay_8
# 153 "data/maps/Route22/scripts.pory"
	walk_in_place_faster_up
# 154 "data/maps/Route22/scripts.pory"
	step_end
# 155 "data/maps/Route22/scripts.pory"

# 156 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalTriggerTop::
# 157 "data/maps/Route22/scripts.pory"
	lockall
# 158 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 0
# 159 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_LateRival
# 160 "data/maps/Route22/scripts.pory"
	end
# 161 "data/maps/Route22/scripts.pory"

# 162 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalTriggerMid::
# 163 "data/maps/Route22/scripts.pory"
	lockall
# 164 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 1
# 165 "data/maps/Route22/scripts.pory"
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
# 166 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_LateRival
# 167 "data/maps/Route22/scripts.pory"
	end
# 168 "data/maps/Route22/scripts.pory"

# 169 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalTriggerBottom::
# 170 "data/maps/Route22/scripts.pory"
	lockall
# 171 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 2
# 172 "data/maps/Route22/scripts.pory"
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
# 173 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_LateRival
# 174 "data/maps/Route22/scripts.pory"
	end
# 175 "data/maps/Route22/scripts.pory"

# 176 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRival::
# 177 "data/maps/Route22/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 178 "data/maps/Route22/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 179 "data/maps/Route22/scripts.pory"
	addobject LOCALID_ROUTE22_RIVAL
# 180 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_LateRivalApproach
# 181 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_LateRivalApproach
# 182 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_LateRivalApproachBottom
# 183 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_LateRivalIntro
# 184 "data/maps/Route22/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ROUTE22_RIVAL
# 185 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_LateRivalSquirtle
# 186 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_LateRivalBulbasaur
# 187 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_LateRivalCharmander
# 188 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_LateRivalPostBattle
# 189 "data/maps/Route22/scripts.pory"
	closemessage
# 190 "data/maps/Route22/scripts.pory"
	delay 10
# 191 "data/maps/Route22/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 192 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_LateRivalExit
# 193 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 194 "data/maps/Route22/scripts.pory"
	fadedefaultbgm
# 195 "data/maps/Route22/scripts.pory"
	removeobject LOCALID_ROUTE22_RIVAL
# 196 "data/maps/Route22/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 4
# 197 "data/maps/Route22/scripts.pory"
	releaseall
# 198 "data/maps/Route22/scripts.pory"
	end
# 199 "data/maps/Route22/scripts.pory"

# 200 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalApproach::
# 201 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
# 202 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 203 "data/maps/Route22/scripts.pory"
	return
# 204 "data/maps/Route22/scripts.pory"

# 205 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalApproachBottom::
# 206 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
# 207 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
# 208 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 209 "data/maps/Route22/scripts.pory"
	return
# 210 "data/maps/Route22/scripts.pory"

# 211 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalSquirtle::
# 212 "data/maps/Route22/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE, Route22_Text_LateRivalDefeat
# 213 "data/maps/Route22/scripts.pory"
	return
# 214 "data/maps/Route22/scripts.pory"

# 215 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalBulbasaur::
# 216 "data/maps/Route22/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR, Route22_Text_LateRivalDefeat
# 217 "data/maps/Route22/scripts.pory"
	return
# 218 "data/maps/Route22/scripts.pory"

# 219 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalCharmander::
# 220 "data/maps/Route22/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER, Route22_Text_LateRivalDefeat
# 221 "data/maps/Route22/scripts.pory"
	return
# 222 "data/maps/Route22/scripts.pory"

# 223 "data/maps/Route22/scripts.pory"
Route22_Movement_LateRivalExit::
# 224 "data/maps/Route22/scripts.pory"
	walk_left
# 225 "data/maps/Route22/scripts.pory"
	walk_left
# 226 "data/maps/Route22/scripts.pory"
	walk_left
# 227 "data/maps/Route22/scripts.pory"
	walk_left
# 228 "data/maps/Route22/scripts.pory"
	walk_left
# 229 "data/maps/Route22/scripts.pory"
	walk_left
# 230 "data/maps/Route22/scripts.pory"
	walk_left
# 231 "data/maps/Route22/scripts.pory"
	step_end
# 232 "data/maps/Route22/scripts.pory"

# 233 "data/maps/Route22/scripts.pory"
Route22_EventScript_LeagueGateSign::
# 234 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_LeagueGateSign, MSGBOX_SIGN
# 235 "data/maps/Route22/scripts.pory"
	end
# 236 "data/maps/Route22/scripts.pory"

# 237 "data/maps/Route22/scripts.pory"
Route22_EventScript_TestHeptaNo::
# 238 "data/maps/Route22/scripts.pory"
	lockall
# 239 "data/maps/Route22/scripts.pory"
	faceplayer
# 240 "data/maps/Route22/scripts.pory"
	checkflag FLAG_BEAT_HEPTANO_TEST
# 241 "data/maps/Route22/scripts.pory"
	goto_if_eq Route22_EventScript_TestHeptaNo_AlreadyDone
# 242 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_TestHeptaNoIntro
# 243 "data/maps/Route22/scripts.pory"
	trainerbattle_no_intro TRAINER_HEPTANO_TEST, Route22_Text_TestHeptaNoDefeat
# 244 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_TestHeptaNoAfter
# 245 "data/maps/Route22/scripts.pory"
	setflag FLAG_BEAT_HEPTANO_TEST
# 246 "data/maps/Route22/scripts.pory"
	releaseall
# 247 "data/maps/Route22/scripts.pory"
	end
# 248 "data/maps/Route22/scripts.pory"

# 249 "data/maps/Route22/scripts.pory"
Route22_EventScript_TestHeptaNo_AlreadyDone::
# 250 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_TestHeptanoBeaten
# 251 "data/maps/Route22/scripts.pory"
	releaseall
# 252 "data/maps/Route22/scripts.pory"
	end
# 253 "data/maps/Route22/scripts.pory"

# 254 "data/maps/Route22/scripts.pory"
Route22_EventScript_HeptaNoBall::
# 255 "data/maps/Route22/scripts.pory"
	lock
# 256 "data/maps/Route22/scripts.pory"
	faceplayer
# 257 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HEPTANO
# 258 "data/maps/Route22/scripts.pory"
	givemon SPECIES_HEPTANO, 30
# 259 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route22_EventScript_GetHeptaNoParty
# 260 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route22_EventScript_GetHeptaNoPC
# 261 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 262 "data/maps/Route22/scripts.pory"
	release
# 263 "data/maps/Route22/scripts.pory"
	end
# 264 "data/maps/Route22/scripts.pory"

# 265 "data/maps/Route22/scripts.pory"
Route22_EventScript_GetHeptaNoParty::
# 266 "data/maps/Route22/scripts.pory"
	removeobject LOCALID_ROUTE22_HEPTANO_POKEBALL
# 267 "data/maps/Route22/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 268 "data/maps/Route22/scripts.pory"
	message Route22_Text_ObtainedAnHeptaNo
# 269 "data/maps/Route22/scripts.pory"
	waitmessage
# 270 "data/maps/Route22/scripts.pory"
	waitfanfare
# 271 "data/maps/Route22/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HEPTANO
# 272 "data/maps/Route22/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 273 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_EventScript_SetGotHeptaNo
# 274 "data/maps/Route22/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 275 "data/maps/Route22/scripts.pory"
	call EventScript_ChangePokemonNickname
# 276 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_SetGotHeptaNo
# 277 "data/maps/Route22/scripts.pory"
	end
# 278 "data/maps/Route22/scripts.pory"

# 279 "data/maps/Route22/scripts.pory"
Route22_EventScript_GetHeptaNoPC::
# 280 "data/maps/Route22/scripts.pory"
	removeobject LOCALID_ROUTE22_HEPTANO_POKEBALL
# 281 "data/maps/Route22/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 282 "data/maps/Route22/scripts.pory"
	message Route22_Text_ObtainedAnHeptaNo
# 283 "data/maps/Route22/scripts.pory"
	waitmessage
# 284 "data/maps/Route22/scripts.pory"
	waitfanfare
# 285 "data/maps/Route22/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_HEPTANO
# 286 "data/maps/Route22/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 287 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_EventScript_TransferHeptaNoToPC
# 288 "data/maps/Route22/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 289 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_TransferHeptaNoToPC
# 290 "data/maps/Route22/scripts.pory"
	end
# 291 "data/maps/Route22/scripts.pory"

# 292 "data/maps/Route22/scripts.pory"
Route22_EventScript_TransferHeptaNoToPC::
# 293 "data/maps/Route22/scripts.pory"
	call EventScript_TransferredToPC
# 294 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_SetGotHeptaNo
# 295 "data/maps/Route22/scripts.pory"
	end
# 296 "data/maps/Route22/scripts.pory"

# 297 "data/maps/Route22/scripts.pory"
Route22_EventScript_MalwaragonBall::
# 298 "data/maps/Route22/scripts.pory"
	lock
# 299 "data/maps/Route22/scripts.pory"
	faceplayer
# 300 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_MALWARAGON
# 301 "data/maps/Route22/scripts.pory"
	givemon SPECIES_MALWARAGON, 30
# 302 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Route22_EventScript_GetMalwaragonParty
# 303 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route22_EventScript_GetMalwaragonPC
# 304 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 305 "data/maps/Route22/scripts.pory"
	release
# 306 "data/maps/Route22/scripts.pory"
	end
# 307 "data/maps/Route22/scripts.pory"

# 308 "data/maps/Route22/scripts.pory"
Route22_EventScript_GetMalwaragonParty::
# 309 "data/maps/Route22/scripts.pory"
	removeobject LOCALID_ROUTE22_MALWARAGON_POKEBALL
# 310 "data/maps/Route22/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 311 "data/maps/Route22/scripts.pory"
	message Route22_Text_ObtainedAnMalwaragon
# 312 "data/maps/Route22/scripts.pory"
	waitmessage
# 313 "data/maps/Route22/scripts.pory"
	waitfanfare
# 314 "data/maps/Route22/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MALWARAGON
# 315 "data/maps/Route22/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 316 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_EventScript_SetGotMalwaragon
# 317 "data/maps/Route22/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 318 "data/maps/Route22/scripts.pory"
	call EventScript_ChangePokemonNickname
# 319 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_SetGotMalwaragon
# 320 "data/maps/Route22/scripts.pory"
	end
# 321 "data/maps/Route22/scripts.pory"

# 322 "data/maps/Route22/scripts.pory"
Route22_EventScript_GetMalwaragonPC::
# 323 "data/maps/Route22/scripts.pory"
	removeobject LOCALID_ROUTE22_MALWARAGON_POKEBALL
# 324 "data/maps/Route22/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 325 "data/maps/Route22/scripts.pory"
	message Route22_Text_ObtainedAnMalwaragon
# 326 "data/maps/Route22/scripts.pory"
	waitmessage
# 327 "data/maps/Route22/scripts.pory"
	waitfanfare
# 328 "data/maps/Route22/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MALWARAGON
# 329 "data/maps/Route22/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 330 "data/maps/Route22/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_EventScript_TransferMalwaragonToPC
# 331 "data/maps/Route22/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 332 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_TransferMalwaragonToPC
# 333 "data/maps/Route22/scripts.pory"
	end
# 334 "data/maps/Route22/scripts.pory"

# 335 "data/maps/Route22/scripts.pory"
Route22_EventScript_TransferMalwaragonToPC::
# 336 "data/maps/Route22/scripts.pory"
	call EventScript_TransferredToPC
# 337 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_SetGotMalwaragon
# 338 "data/maps/Route22/scripts.pory"
	end
# 339 "data/maps/Route22/scripts.pory"

# 340 "data/maps/Route22/scripts.pory"
Route22_EventScript_SetGotHeptaNo::
# 341 "data/maps/Route22/scripts.pory"
	setflag FLAG_GOT_HEPTANO
# 342 "data/maps/Route22/scripts.pory"
	release
# 343 "data/maps/Route22/scripts.pory"
	end
# 344 "data/maps/Route22/scripts.pory"

# 345 "data/maps/Route22/scripts.pory"
Route22_EventScript_SetGotMalwaragon::
# 346 "data/maps/Route22/scripts.pory"
	setflag FLAG_GOT_MALWARAGON
# 347 "data/maps/Route22/scripts.pory"
	release
# 348 "data/maps/Route22/scripts.pory"
	end
# 349 "data/maps/Route22/scripts.pory"

# 350 "data/maps/Route22/scripts.pory"
Route22_EventScript_TestSign::
# 351 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_TestSign, MSGBOX_SIGN
# 352 "data/maps/Route22/scripts.pory"
	end
