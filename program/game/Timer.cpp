#include"Timer.h"
#include"IMG_load.h"
#include"GameManager.h"
#include"DxLib.h"
#include"../support/Support.h"

extern GameManager* gamemanager;
extern IMG_load img;

Timer::Timer(t2k::Vector3 start) {
	pos = start;
	gamemanager->time.emplace_back(this);
}

void Timer::update(const float deltatime) {
	if (gamemanager->GetPosPlayer().y < pos.y + 70 && gamemanager->GetPosPlayer().x>pos.x - 50 &&
		gamemanager->GetPosPlayer().x < pos.x + 180)alpha = 80;
	else alpha = 225;

	if (gamemanager->down_sift && t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_3))s = 30;

}
void Timer::render(const float deltatime) {
	if(gamemanager->GetCreSt_stage_type() > 0) {
		if (s < 59.5) s += deltatime;
		else {
			m++;
			s = 0;
		}
	}
	
	img.img_time_back();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawExtendGraph((int)pos.x - 50, (int)pos.y - 20, (int)pos.x + 180 , (int)pos.y + 70, img.time_back, true);
	SetFontSize(50);
	DrawStringEx((int)pos.x, (int)pos.y, 255, "%02d:%02.0f", m, s);
}