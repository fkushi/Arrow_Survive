#pragma once
class SONG_load {
private:

public:

	bool init_bgm = false;
	bool init_se = false;

	int bgm_taitle;
	int bgm_stage;
	int bgm_end;
	int se_atach;
	int se_shot;

	void SONG_bgm();
	void SONG_SE_Arrow();
};