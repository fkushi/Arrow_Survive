#include"Timer.h"
#include"IMG_load.h"
#include"GameManager.h"
#include"DxLib.h"
#include"../support/Support.h"

extern GameManager* gamemanager;
extern IMG_load img;

/*生存時間計測をするクラス*/
Timer::Timer(t2k::Vector3 start) {
	pos = start;
	gamemanager->time.emplace_back(this);
}

void Timer::update(const float deltatime) {
	/*Playerが近づいたらtimerを透過する*/
	if (gamemanager->GetPosPlayer().y < pos.y + 70 && gamemanager->GetPosPlayer().x>pos.x - 50 &&
		gamemanager->GetPosPlayer().x < pos.x + 180)alpha = 80;
	else alpha = 225;

	/*DEBUGコマンド*/
	if (gamemanager->down_shift && t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_3))s = 30;
	if (gamemanager->down_shift && t2k::Input::isKeyDown(t2k::Input::KEYBORD_1) &&
		t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_0))m = 1;
	if (gamemanager->down_shift && t2k::Input::isKeyDown(t2k::Input::KEYBORD_3) &&
		t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_0)) {
		m = 3;
		for (auto mb : gamemanager->map_stageB)mb->init_plus_pos_B = false;
	}

}
void Timer::render(const float deltatime) {
	if(gamemanager->GetCreSt_stage_type() > 0) {
		if (s < 59.5) s += deltatime;
		else {
			m++;
			for (auto pop_b : gamemanager->pop_enemyB)pop_b->add_speed++;
			for (auto mb : gamemanager->map_stageB)mb->init_plus_pos_B = false;
			s = 0;
		}
	}
	
	img.img_time_back();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawExtendGraph((int)pos.x - 50, (int)pos.y - 20, (int)pos.x + 180 , (int)pos.y + 70, img.time_back, true);
	SetFontSize(50);
	DrawStringEx((int)pos.x, (int)pos.y, 255, "%02d:%02.0f", m, s);
}