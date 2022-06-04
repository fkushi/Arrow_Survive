#include"Arrow_Wing.h"
#include "../support/Support.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;

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

	//矢先の当たり判定の新規インスタンス生成
	if (!pla_dir) {
		new OnAtach_Arrow(t2k::Vector3(start.x + (blt_pla_w >> 1) - 5, start.y, 0), dir, speed,pla_dir,2);
	}
	else new OnAtach_Arrow(t2k::Vector3(start.x - (blt_pla_w >> 1) + 5, start.y, 0), dir, speed,pla_dir,2);

	//画像ハンドルの読み込み
	img_arrow = gamemanager->LoadGraphEx("graphics/Player/Arrow.png");

	//矢の直線移動のflag初期化
	sequence_rotate = false;

	gamemanager->arrow_wing.emplace_back(this);
}

void Arrow_Wing::update(const float deltatime) {

	//真っ直ぐ飛ばし終えたら周回移動に移行するflag
	if ((!DIR && make_pos.x + 200 <= pos.x) || (DIR && make_pos.x - 200 >= pos.x))sequence_rotate = true;

	//矢を周回する処理
	if (!sequence_rotate) {
		pos += (float)SPEED * blt_dir;
		arw_rad = 0;
		init_arw_rad = false;
	}
	else {

		//周回させる場合の座標
		float add_x = cos(radius) * expand_speed;
		float add_y = sin(radius) * expand_speed;

		//矢が直線移動後、矢の描画角度を９０度に角度変更する処理
		if (!init_arw_rad) {
			arw_rad = 1.57f;
			init_arw_rad = true;
		}

		//矢の周回半径が徐々に拡大していく
		expand_speed++;

		//矢が周回する処理
		//DIR = falseが右を向いた場合、DIR = trueが左を向いた場合の周回する中心座標の設定
		if (!DIR) {
			pos.x = preve_Center.x + add_x;
			pos.y = preve_Center.y + add_y;
		}
		else {
			pos.x = preve_Center.x - add_x;
			pos.y = preve_Center.y - add_y;
		}

		//矢を周回させる
		radius += 0.05f;
		//矢の画像を回す
		arw_rad += 0.05f;

	}
	//画面外にでたら消去
	if (pos.x < -150 || pos.x > 1124 || pos.y < -100 || pos.y > 1000) is_alive = false;

}
void Arrow_Wing::render(const float deltatime) {
	
	//画像のブレンド処理を変更させないようにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//同じ矢の画像ハンドルを使用するため、区別をつけるため緑色にする
	SetDrawBright(0, 255, 0);
	DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, arw_rad , img_arrow, true, DIR);
}