#include"Bullet_Player.h"
#include"IMG_load.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern IMG_load img;

//--------------------------------------------------------------------------------------------------------------------------
/*矢の描画*/
//--------------------------------------------------------------------------------------------------------------------------*
Bullet_Player::Bullet_Player(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir) {
	pos = start;
	blt_dir = dir;
	RAD = (radian * 3.14f) / 180;
	SPEED = speed;
	DIR = pla_dir;

	//矢先の当たり判定
	if (!pla_dir) {
		new OnAtach_Arrow(t2k::Vector3(start.x + (blt_pla_w >> 1) - 5, start.y, 0), dir, speed, pla_dir,1);
	}
	else new OnAtach_Arrow(t2k::Vector3(start.x - (blt_pla_w >> 1) + 5, start.y, 0), dir, speed,pla_dir,1);

	gamemanager->bullet_player.emplace_back(this);
}

void Bullet_Player::update(const float deltatime) {
	//矢がX方向に進む処理
	pos += (float)SPEED * blt_dir;

	//画面外にでたらDELETE
	if (pos.x > 1024 >> 1 && gamemanager->down_shift)is_alive = false;
	if (pos.x < 0 || pos.x > 1024 || pos.y < 0 || pos.y > 768) is_alive = false;
} 
void Bullet_Player::render(const float deltatime) {
	img.img_blt_player();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, RAD, img.img_blt_Player, true, DIR);
}