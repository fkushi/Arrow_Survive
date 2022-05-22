#include"Arrow_Wing.h"
#include"IMG_load.h"
#include "../support/Support.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern IMG_load img;

Arrow_Wing::Arrow_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir) {
	pos = start;
	make_pos = start;
	blt_dir = dir;
	RAD = radian;
	SPEED = speed;
	DIR = pla_dir;

	sequence_rotate = false;
	if (!DIR)preve_Center = {start.x + 100,start.y,0 };
	else preve_Center = { start.x - 100,start.y + 100,0 };

	if (!gamemanager->GetPla_pla_dir()) {
		new OnAtach_Arrow(t2k::Vector3(start.x + (blt_pla_w >> 1) - 5, start.y, 0), dir, speed,2);
	}
	else new OnAtach_Arrow(t2k::Vector3(start.x - (blt_pla_w >> 1) + 5, start.y, 0), dir, speed,2);
	gamemanager->arw_win.emplace_back(this);
}

void Arrow_Wing::update(const float deltatime) {

	float add_x = cos(radius) * box_speed;
	float add_y = sin(radius) * box_speed;
	
	if ((!DIR && make_pos.x + 100 <= pos.x) || (DIR && make_pos.x - 100 >= pos.x))sequence_rotate = true;
	if (!sequence_rotate) {
		pos += SPEED * blt_dir;
		arw_rad = 0;
		init_arw_rad = false;
	}
	else {
		if (!init_arw_rad) {
			arw_rad = 1.57f;
			init_arw_rad = true;
		}

		if (!DIR) {
			radius += 0.05f;
			arw_rad += 0.05f;
			pos.x = preve_Center.x + add_x;
			pos.y = preve_Center.y + add_y;
		}
		else {
			radius -= 0.05f;
			arw_rad -= 0.05f;
			pos.x = preve_Center.x + add_x;
			pos.y = preve_Center.y + add_y;
		}
	}
}
void Arrow_Wing::render(const float deltatime) {
	img.img_blt_player();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(0, 255, 0);
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, arw_rad , img.img_blt_Player, true, DIR);
}