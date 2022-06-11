#include"Bullet_Player.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;

//--------------------------------------------------------------------------------------------------------------------------
/*Arrowのクラス*/
//--------------------------------------------------------------------------------------------------------------------------
Bullet_Player::Bullet_Player(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir) {
	pos = start;
	blt_dir = dir;
	RAD = (radian * 3.14f) / 180;
	SPEED = speed;
	DIR = pla_dir;

	//-----------------------------------------------------------------
	/*矢先の当たり判定の新規インスタンス生成*/
	//-----------------------------------------------------------------
	if (!pla_dir) {
		new OnAtach_Arrow(t2k::Vector3(start.x + (blt_pla_w >> 1) - 5, start.y, 0), dir, speed, pla_dir, 1);
	}
	else new OnAtach_Arrow(t2k::Vector3(start.x - (blt_pla_w >> 1) + 5, start.y, 0), dir, speed, pla_dir, 1);

	//-----------------------------------------------------------------
	/*画像ハンドルの読み込み*/
	//-----------------------------------------------------------------
	img_arrow = gamemanager->LoadGraphEx("graphics/Player/Arrow.png");

	gamemanager->bullet_player.emplace_back(this);
}

void Bullet_Player::update_arrow(const float deltatime) {
	//-----------------------------------------------------------------
	/*矢がX方向に進む処理*/
	//-----------------------------------------------------------------
	pos += (float)SPEED * blt_dir;

	//-----------------------------------------------------------------
	/*画面外にでたらDELETE*/
	//-----------------------------------------------------------------
	if (pos.x > 1024 >> 1 && gamemanager->down_shift)arrow_alive = false;
	if (pos.x < 0 || pos.x > 1024 || pos.y < 0 || pos.y > 768) arrow_alive = false;
} 
void Bullet_Player::render_arrow(const float deltatime) {
	
	//-----------------------------------------------------------------
	/*画像のブレンド処理を変更させないようにする*/
	//-----------------------------------------------------------------
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(255, 255, 255);

	//-----------------------------------------------------------------
	/*描画*/
	//-----------------------------------------------------------------
	DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, RAD, img_arrow, true, DIR);
}