#include"Timer.h"
#include"GameManager.h"
#include"DxLib.h"
#include"../support/Support.h"

extern GameManager* gamemanager;

//-----------------------------------------------------------------------------------------------------------
/*生存時間計測をするクラス*/
//-----------------------------------------------------------------------------------------------------------

Timer::Timer(t2k::Vector3 start) {

	pos = start;

	//------------------------------------------------------------------
	/*描画ハンドルの読み込み*/
	//------------------------------------------------------------------
	img_timer = gamemanager->LoadGraphEx("graphics/Timer_cover.png");

	gamemanager->time.emplace_back(this);
}

void Timer::update(const float deltatime) {
	//------------------------------------------------------------------
	/*初期ステージ以外になったらタイマーを開始する*/
	//------------------------------------------------------------------
	if (gamemanager->GetCreSt_stage_type() > 0) {
		if (s < 59.5) s += deltatime;
		else {
			m++;
			for (auto pop_b : gamemanager->pop_enemyB)pop_b->add_speed++;
			for (auto mb : gamemanager->map_stageB)mb->init_plus_pos_B = false;
			s = 0;
		}
	}

	//------------------------------------------------------------------
	/*Playerが近づいたらtimerを透過する*/
	//------------------------------------------------------------------
	if (gamemanager->GetPosPlayer().y < pos.y + 70 && gamemanager->GetPosPlayer().x>pos.x - 50 &&
		gamemanager->GetPosPlayer().x < pos.x + 180)alpha = 80;
	else alpha = 225;

	//------------------------------------------------------------------
	/*DEBUGコマンド*/
	//------------------------------------------------------------------
	//30秒経過させる
	if (gamemanager->down_shift && t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_3))s = 30;
	//1分経過させる
	if (gamemanager->down_shift && 
		t2k::Input::isKeyDown(t2k::Input::KEYBORD_1) && t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_0)) {
		m = 1;
	}
	//3分経過
	if (gamemanager->down_shift && 
		t2k::Input::isKeyDown(t2k::Input::KEYBORD_3) &&	t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_0)) {
		m = 3;
		for (auto mb : gamemanager->map_stageB)mb->init_plus_pos_B = false;
	}

}
void Timer::render(const float deltatime) {
	
	//------------------------------------------------------------------
	/*playerが近づいたら画像のブレンドのアルファ値を変える*/
	//------------------------------------------------------------------
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

	//------------------------------------------------------------------
	/*timerの背景の描画*/
	//------------------------------------------------------------------
	DrawExtendGraph(static_cast<int>(pos.x) - 50, static_cast<int>(pos.y) - 20, static_cast<int>(pos.x) + 180 , 
		static_cast<int>(pos.y) + 70, img_timer, true);

	//------------------------------------------------------------------
	/*timerのカウント描画　m:分　s:秒*/
	//------------------------------------------------------------------
	SetFontSize(50);
	DrawStringEx(static_cast<int>(pos.x), static_cast<int>(pos.y), 255, "%02d:%02.0f", m, s);
}