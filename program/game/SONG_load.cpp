#include"SONG_load.h"
#include"DxLib.h"

void SONG_load::SONG_taitle() {
	if (!init_bgm) {
		bgm_taitle = LoadSoundMem("sound/taitle.mp3");
	}
}