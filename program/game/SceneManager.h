#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class SceneManager {
public:

	t2k::Sequence<SceneManager*> sequence_ =
		t2k::Sequence<SceneManager*>(this, &SceneManager::seqTitle);

	//titleä÷êî
	bool seqTitle(const float deltatime);
	bool seqStage(const float deltatime);
	bool seqGameEnd(const float deltatime);

	bool init_bgm = false;
	bool init_st1_sound = false;
	int bgm_stage = 0;

	int preve_m = 0;
	int preve_s = 0;

	void Init_Stage();
	void Del_END();

};