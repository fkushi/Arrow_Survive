#include"Arrow_Wing.h"
#include"IMG_load.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern IMG_load img;

Arrow_Wing::Arrow_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir) {
	pos = start;
	blt_dir = dir;
	RAD = radian;
	SPEED = speed;
	DIR = pla_dir;
	if (!gamemanager->GetPla_pla_dir()) {
		new OnAtach_Arrow(t2k::Vector3(start.x + (blt_pla_w >> 1) - 5, start.y, 0), dir, speed,2);
	}
	else new OnAtach_Arrow(t2k::Vector3(start.x - (blt_pla_w >> 1) + 5, start.y, 0), dir, speed,2);
	gamemanager->arw_win.emplace_back(this);
}

void Arrow_Wing::update(const float deltatime) {
	
}
void Arrow_Wing::render(const float deltatime) {
	img.img_blt_player();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(0, 255, 0);
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f,0, img.img_blt_Player, true, DIR);
}