#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class SceneManager {
public:

	t2k::Sequence<SceneManager*> sequence_ =
		t2k::Sequence<SceneManager*>(this, &SceneManager::seqTitle);

	//titleシーン
	bool seqTitle(const float deltatime);
	//プレイシーン
	bool seqStage(const float deltatime);
	//結果発表シーン
	bool seqGameEnd(const float deltatime);

	bool init_st1_sound = false;
	
	int preve_m = 0;
	int preve_s = 0;

	void Del_END();

};