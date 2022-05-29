#include"Player.h"
#include"Anim_Player.h"
#include"IMG_load.h"
#include"SONG_load.h"
#include"GameManager.h"
#include"DxLib.h"
#include "../support/Support.h"

#define PLA_DEBUG 0

extern GameManager* gamemanager;
extern IMG_load img;
extern SONG_load		song;
Anim_Player anim_pla;

Player::Player(t2k::Vector3 start,int speed) {
	pos = start;
	pla_speed = speed;
	gamemanager->atach.pla_enemyB_check = 0;

	//矢の属性選択クラス
	new Arrow_Type();
}

void Player::update(const float deltatime) {
	//--------------------------------------------------------------------------------------------------
	/*アニメーション*/
	//--------------------------------------------------------------------------------------------------
	anim_pla.anim_Player_Controll(deltatime);
	
	//--------------------------------------------------------------------------------------------------
	/*当たり判定*/
	//--------------------------------------------------------------------------------------------------
	gamemanager->atach.Atach_Pla_Wall();
	gamemanager->atach.Atach_Pla_Pop();
	//gamemanager->atach.Atach_Pla_Enemy();
	int check = gamemanager->atach.pla_enemyB_check;
	preve_pos = pos;
	
	//--------------------------------------------------------------------------------------------------
	/*操作*/
	//--------------------------------------------------------------------------------------------------
	if (gamemanager->down_sift) {
		triger_push_sift = true;
		anim_pla.init_anim_pla = false;
	}
	else if (gamemanager->relese_sift) {
		triger_push_sift = false;
	}

	//矢印キーを押した場合、座標を動く処理
	if (gamemanager->atach.pla_up && !triger_push_sift && gamemanager->down_up)pos.y -= pla_speed;
	if (gamemanager->atach.pla_down && !triger_push_sift && gamemanager->down_down)pos.y += pla_speed;
	if (gamemanager->atach.pla_right && !triger_push_sift && gamemanager->down_right) {
			pla_dir= false;
			pos.x += pla_speed;
	}
	if (gamemanager->atach.pla_left && !triger_push_sift && gamemanager->down_left) {
			pla_dir = true;
			pos.x -= pla_speed;
	}

	//--------------------------------------------------------------------------------------------------
	/*Arrow*/
	//--------------------------------------------------------------------------------------------------
	//spaceを押したとき、その時の矢の属性を発射する
	if (gamemanager->triger_sapce && gamemanager->GetArwTyp_arrow_type() == 1) {
		PlaySoundMem(song.se_shot, DX_PLAYTYPE_BACK, true);
		if (!pla_dir) {
			gamemanager->createBullet_Player(pos, t2k::Vector3(1, 0, 0), 0, 8);
		}
		else {
			gamemanager->createBullet_Player(pos, t2k::Vector3(-1, 0, 0), 0, 8);
		}
	}
	else if (gamemanager->triger_sapce && gamemanager->GetArwTyp_arrow_type() == 2) {
		PlaySoundMem(song.se_shot, DX_PLAYTYPE_BACK, true);
		if (!pla_dir) {
			gamemanager->createArrwo_Wing(pos, t2k::Vector3(1, 0, 0), 0, 8);
		}
		else {
			gamemanager->createArrwo_Wing(pos, t2k::Vector3(-1, 0, 0), 0, 8);
		}
	}

	//--------------------------------------------------------------------------------------------------
	/*HP*/
	//enemyの攻撃力:5
	//--------------------------------------------------------------------------------------------------
	if((check == 1 || check == 2 || check == 3 || check == 4) && hp_frame % 2 == 0 && 
		gezi_now_num > gezi_min_num)gezi_now_num -= 5;
}

void Player::render(const float deltatime) {
	//--------------------------------------------------------------------------------------------------
	/*HP*/
	//HP_max:300
	//--------------------------------------------------------------------------------------------------
	//HP画像_load
	img.img_hp();

	int gezi_min_x = (int)pos.x - (pla_w >> 1) - 5;
	int gezi_min_y = (int)pos.y + (pla_h >> 1) + 5;
	int gezi_max_x = (int)pos.x + (pla_w >> 1) + 5;
	int gezi_max_y = (int)pos.y + (pla_h >> 1) + 10;
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255, 255, 255);
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
	//Player画像Load
	img.img_player();
	
	//------------------------------------------------------------------------------
	/*当たった時のPlayerの赤色に変わる処理*/
	//-------------------------------------------------------------------------------
	if(atach == 1 || atach == 2 || atach == 3 || atach == 4)SetDrawBright(255, 0, 0);
	else SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//-------------------------------------------------------------------------------
	/*playerの描画*/
	//-------------------------------------------------------------------------------
	if (!anim_pla.init_anim_pla) DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, img.img_pla, true, pla_dir);
	else DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0, img.anim_pla[anim_pla.anim_move][anim_pla.anim_frame], true, pla_dir);

#if PLA_DEBUG
	//-------------------------------------------------------------------------------
	/*Debug*/
	//-------------------------------------------------------------------------------
	SetFontSize(20);
	DrawStringEx(100, 100, 255, "posX:%1.0f,posY:%1.0f", pos.x, pos.y);
	DrawStringEx(100, 120, 255, "grand_atach = %d", gamemanager->GetAtachWall());
#endif
}