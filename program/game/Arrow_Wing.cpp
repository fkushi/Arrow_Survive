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
	else preve_Center = { start.x - 100,start.y,0 };
	//–î‚Ì“–‚½‚è”»’è
	if (!gamemanager->GetPla_pla_dir()) {
		new OnAtach_Arrow(t2k::Vector3(start.x + (blt_pla_w >> 1) - 5, start.y, 0), dir, speed,2);
	}
	else new OnAtach_Arrow(t2k::Vector3(start.x - (blt_pla_w >> 1) + 5, start.y, 0), dir, speed,2);
	gamemanager->arw_win.emplace_back(this);
}

void Arrow_Wing::update(const float deltatime) {

	float add_x = cos(radius) * expand_speed;
	float add_y = sin(radius) * expand_speed;

	if ((!DIR && make_pos.x + 200 <= pos.x) || (DIR && make_pos.x - 200 >= pos.x))sequence_rotate = true;
	if (!sequence_rotate) {
		pos += SPEED * blt_dir;
		arw_rad = 0;
		init_arw_rad = false;
	}
	else {
		//–î‚ÌŠp“x•ÏX
		if (!init_arw_rad) {
			arw_rad = 1.57f;
			init_arw_rad = true;
		}

		//–î‚Ìü‰ñ”¼ŒaŠg‘å
		expand_speed++;

		//–î‚Ìü‰ñˆ—
		if (!DIR) {
			radius += 0.05f;
			arw_rad += 0.05f;
			pos.x = preve_Center.x + add_x;
			pos.y = preve_Center.y + add_y;
		}
		else {
			radius += 0.05f;
			arw_rad += 0.05f;
			pos.x = preve_Center.x - add_x;
			pos.y = preve_Center.y - add_y;
		}
	}

	if (pos.x < -150 || pos.x > 1124 || pos.y < -100 || pos.y > 1000) is_alive = false;

}
void Arrow_Wing::render(const float deltatime) {
	img.img_blt_player();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(0, 255, 0);
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, arw_rad , img.img_blt_Player, true, DIR);
}