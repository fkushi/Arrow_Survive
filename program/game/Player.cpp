#include"Player.h"
#include"IMG_load.h"
#include"Anim_Player.h"
#include"DxLib.h"
#include"GameManager.h"
#include "../support/Support.h"

#define PLA_DEBUG 1

extern GameManager* gamemanager;
extern IMG_load img;
Anim_Player anim_pla;

Player::Player(t2k::Vector3 start,int speed) {
	pos = start;
	pla_speed = speed;
}

void Player::update(const float deltatime) {
	//--------------------------------------------------------------------------------------------------
	/*アニメーション*/
	anim_pla.anim_Player_Controll(deltatime);
	//--------------------------------------------------------------------------------------------------
	/*当たり判定*/
	gamemanager->atach.Atach_Pla_Wall();
	gamemanager->atach.Atach_Pla_Pop();
	gamemanager->atach.Atach_Pla_Enemy();
	preve_pos = pos;
	//--------------------------------------------------------------------------------------------------
	/*操作*/
	if (gamemanager->atach.pla_up)if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_UP))pos.y -= pla_speed;
	if (gamemanager->atach.pla_down)if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_DOWN))pos.y += pla_speed;
	if (gamemanager->atach.pla_right) {
		if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_RIGHT)) {
			pla_dir = false;
			pos.x += pla_speed;
		}
	}
	if (gamemanager->atach.pla_left) {
		if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_LEFT)) {
			pla_dir = true;
			pos.x -= pla_speed;
		}
	}
	//--------------------------------------------------------------------------------------------------
	/*Bullet*/
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_N)) {
		if (!pla_dir) {
			gamemanager->createBullet_Player(t2k::Vector3(pos.x, pos.y, 0), t2k::Vector3(1, 0, 0), 0, 8);
			//gamemanager->createBullet_Player(t2k::Vector3(pos.x, pos.y, 0), t2k::Vector3(1, 1, 0), 45, 8);
			//gamemanager->createBullet_Player(t2k::Vector3(pos.x, pos.y, 0), t2k::Vector3(1, -1, 0), -45, 8);
		}
		else {
			gamemanager->createBullet_Player(t2k::Vector3(pos.x, pos.y, 0), t2k::Vector3(-1, 0, 0), 0, 8);
			//gamemanager->createBullet_Player(t2k::Vector3(pos.x, pos.y, 0), t2k::Vector3(-1, -1, 0), 45, 8);
			//gamemanager->createBullet_Player(t2k::Vector3(pos.x, pos.y, 0), t2k::Vector3(-1, 1, 0), -45, 8);
		}
	}
	//--------------------------------------------------------------------------------------------------
	/*HP_test*/
	int check = gamemanager->atach.pla_enemyB_check;
	if((check == 1 || check == 2 || check == 3 || check == 4) && hp_frame % 2 == 0 
		&& gezi_now_num > gezi_min_num)gezi_now_num--;
	//if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_W) && hp_frame % 2 == 0 && gezi_now_num < gezi_max_num)gezi_now_num++;
	//if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_S) && hp_frame % 2 == 0 && gezi_now_num > gezi_min_num)gezi_now_num--;
}
void Player::render(const float deltatime) {
	//--------------------------------------------------------------------------------------------------
	/*HP*/
	//--------------------------------------------------------------------------------------------------
	img.img_hp();
	int gezi_min_x = (int)pos.x - (pla_w >> 1) - 5;
	int gezi_min_y = (int)pos.y + (pla_h >> 1) + 5;
	int gezi_max_x = (int)pos.x + (pla_w >> 1) + 5;
	int gezi_max_y = (int)pos.y + (pla_h >> 1) + 10;
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//HP_CORVER
	DrawExtendGraph(gezi_min_x - 1, gezi_min_y - 2, gezi_max_x + 2, gezi_max_y + 2, img.hp_cover, true);
	//HP_RED
	DrawExtendGraph(gezi_min_x, gezi_min_y, gezi_max_x, gezi_max_y, img.hp_red, true);
	//HP
	DrawExtendGraph(gezi_min_x, gezi_min_y,
		gezi_min_x + (gezi_max_x - gezi_min_x) * (gezi_now_num - gezi_min_num) / (gezi_max_num - gezi_min_num),
		gezi_max_y, img.hp_green, true);
	//--------------------------------------------------------------------------------------------------
	/*描画処理*/
	//--------------------------------------------------------------------------------------------------
	int atach = gamemanager->atach.pla_enemyB_check;
	img.img_player();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//-------------------------------------------------------------------------------
	/*当たった時のPlayerの赤色に変わる処理*/
	if(atach == 1 || atach == 2 || atach == 3 || atach == 4)SetDrawBright(255, 0, 0);
	else SetDrawBright(255, 255, 255);
	//-------------------------------------------------------------------------------
	/*playerの描画*/
	if (!anim_pla.init_anim_pla) DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, img.img_pla, true, pla_dir);
	else DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, img.anim_pla[anim_pla.anim_move][anim_pla.anim_frame], true, pla_dir);

#if PLA_DEBUG
	/*Debug*/
	SetFontSize(20);
	DrawStringEx(100, 100, 255, "posX:%1.0f,posY:%1.0f", pos.x, pos.y);
	DrawStringEx(100, 120, 255, "grand_atach = %d", gamemanager->GetAtachWall());
#endif
}