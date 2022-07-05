#pragma once
#include"Base.h"
#include"../library/t2klib.h"

class SceneManager {
private:


public:

	t2k::Sequence<SceneManager*> sequence_ =
		t2k::Sequence<SceneManager*>(this, &SceneManager::seqTitle);

	//titleシーン
	bool seqTitle(const float deltatime);
	//プレイシーン
	bool seqStage(const float deltatime);
	//結果発表シーン
	bool seqGameEnd(const float deltatime);

	enum class SCENE:uint32_t {
		TITLE,
		STAGE,
		END,
		MAX
	};

	SCENE nowScene = SCENE::TITLE;

	/*inline int GetNowScene() {
		return static_cast<uint32_t>(nowScene);
	}*/



	bool init_st1_sound = false;
	
	//trueなら結果発表シーンに移る
	bool init_move_seqGameEnd = false;

	//playerが死亡アニメーションが終了したら1秒間だけシーン移動を待つ
	float count_move_seqGameEnd_interval = 1.0f;
	
	int preve_m = 0;
	int preve_s = 0;

	void Del_END();

};