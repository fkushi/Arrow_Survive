#include"Arrow_Wing.h"
#include"IMG_load.h"
#include "../support/Support.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern IMG_load img;

//--------------------------------------------------------------------------------------------------------------------------
/*風属性の回る矢*/
//--------------------------------------------------------------------------------------------------------------------------*
Arrow_Wing::Arrow_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir) {
	pos = start;
	make_pos = start;
	blt_dir = dir;
	RAD = radian;
	SPEED = speed;
	DIR = pla_dir;

	//回転時の中心座標
	if (!DIR)preve_Center = {start.x + 100,start.y,0 };
	else preve_Center = { start.x - 100,start.y,0 };

	//矢先の当たり判定
	if (!pla_dir) {
		new OnAtach_Arrow(t2k::Vector3(start.x + (blt_pla_w >> 1) - 5, start.y, 0), dir, speed,pla_dir,2);
	}
	else new OnAtach_Arrow(t2k::Vector3(start.x - (blt_pla_w >> 1) + 5, start.y, 0), dir, speed,pla_dir,2);

	sequence_rotate = false;

	gamemanager->arrow_wing.emplace_back(this);
}

void Arrow_Wing::update(const float deltatime) {

	float add_x = cos(radius) * expand_speed;
	float add_y = sin(radius) * expand_speed;

	//真っ直ぐ飛ばし終えたら周回移動にするflah
	if ((!DIR && make_pos.x + 200 <= pos.x) || (DIR && make_pos.x - 200 >= pos.x))sequence_rotate = true;

	//回転させる処理
	if (!sequence_rotate) {
		pos += (float)SPEED * blt_dir;
		arw_rad = 0;
		init_arw_rad = false;
	}
	else {
		//矢の角度変更
		if (!init_arw_rad) {
			arw_rad = 1.57f;
			init_arw_rad = true;
		}

		//矢の周回半径拡大
		expand_speed++;

		//矢の周回処理
		if (!DIR) {
			pos.x = preve_Center.x + add_x;
			pos.y = preve_Center.y + add_y;
		}
		else {
			pos.x = preve_Center.x - add_x;
			pos.y = preve_Center.y - add_y;
		}

		radius += 0.05f;
		arw_rad += 0.05f;

	}
	//画面外にでたら消去
	if (pos.x < -150 || pos.x > 1124 || pos.y < -100 || pos.y > 1000) is_alive = false;

}
void Arrow_Wing::render(const float deltatime) {
	img.img_blt_player();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(0, 255, 0);
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, arw_rad , img.img_blt_Player, true, DIR);
}