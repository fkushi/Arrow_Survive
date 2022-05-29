#include"SONG_load.h"
#include"DxLib.h"

void SONG_load::SONG_taitle() {
	if (!init_bgm) {
		bgm_taitle = LoadSoundMem("sound/taitle.mp3");
		init_bgm = true;
	}
}

void SONG_load::SONG_stage() {
	if (!init_bgm) {
		bgm_stage = LoadSoundMem("sound/Stage_play.mp3");
		init_bgm = true;
	}
}

void SONG_load::SONG_SE_Arrow() {
	if (!init_se) {
		se_atach = LoadSoundMem("sound/shot_2.mp3");
		se_shot = LoadSoundMem("sound/arrow_Atach.mp3");
		init_se = true;
	}
}