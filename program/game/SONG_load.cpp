#include"SONG_load.h"
#include"DxLib.h"

//-------------------------------------------------------------------------------------------------------------------------
/*‚·‚×‚Ä‚Ì‰¹Œ¹‚ð‚Ü‚Æ‚ß‚Ä‚¢‚éƒNƒ‰ƒX*/
//-------------------------------------------------------------------------------------------------------------------------

void SONG_load::SONG_bgm() {
	if (!init_bgm) {
		bgm_taitle = LoadSoundMem("sound/taitle.mp3");
		bgm_stage = LoadSoundMem("sound/Stage_play.mp3");
		bgm_end = LoadSoundMem("sound/game_end.mp3");
		init_bgm = true;
	}
}

void SONG_load::SONG_SE_Arrow() {
	if (!init_se) {
		se_atach = LoadSoundMem("sound/arrow_Atach.mp3");
		se_shot = LoadSoundMem("sound/shot_2.mp3");
		init_se = true;
	}
}