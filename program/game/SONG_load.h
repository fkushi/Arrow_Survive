#pragma once
class SONG_load {
private:

public:

	bool init_bgm = false;
	bool init_se = false;

	int bgm_taitle;
	int bgm_stage;
	int se_atach;
	int se_shot;

	void SONG_taitle();
	void SONG_stage();
	void SONG_SE_Arrow();

};