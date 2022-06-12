#include"Player.h"
#include"Anim_Player.h"
#include"SONG_load.h"
#include"GameManager.h"
#include"DxLib.h"
#include "../support/Support.h"

#define PLA_DEBUG 0

extern GameManager* gamemanager;
extern SONG_load	song;
Anim_Player*		anim_player;

Player::Player(t2k::Vector3 start,int speed) {
	pos = start;
	pla_speed = speed;
	gamemanager->atach->pla_enemyB_check = false;

	//--------------------------------------------------------------------------------------------------
	/*画像ハンドルの読み込み*/
	//--------------------------------------------------------------------------------------------------
	img_player_stand = gamemanager->LoadGraphEx("graphics/Player/player_Stand.png");
	hp_green = gamemanager->LoadGraphEx("graphics/Player/hp_green.png");
	hp_red = gamemanager->LoadGraphEx("graphics/Player/hp_red.png");
	hp_cover = gamemanager->LoadGraphEx("graphics/Player/hp_gold.png");

	anim_player = new Anim_Player();
}

void Player::update(const float deltatime) {
	//--------------------------------------------------------------------------------------------------
	/*アニメーション*/
	//--------------------------------------------------------------------------------------------------
	anim_player->anim_Player_Controll(deltatime);
	
	//--------------------------------------------------------------------------------------------------
	/*当たり判定*/
	//--------------------------------------------------------------------------------------------------
	gamemanager->atach->Atach_Pla_Wall();
	gamemanager->atach->Atach_Pla_Pop();
	preve_pos = pos;
	
	//--------------------------------------------------------------------------------------------------
	/*操作*/
	//--------------------------------------------------------------------------------------------------
	//shiftを押している間動きを止めるflag
	if (gamemanager->down_shift) {
		triger_push_sift = true;
		anim_player->init_anim_pla = false;
	}
	//shiftを押上たとき、動けるflag
	else if (gamemanager->relese_shift) {
		triger_push_sift = false;
	}

	//矢印キーを押した場合、座標を動く処理
	/*if (gamemanager->isAttach()) {

	}*/
	//右を向いたらpla_dir = false、左を向いたらpla_dir = true;
	if (gamemanager->atach->pla_up && !triger_push_sift && gamemanager->down_up)pos.y -= pla_speed;
	if (gamemanager->atach->pla_down && !triger_push_sift && gamemanager->down_down)pos.y += pla_speed;
	if (gamemanager->atach->pla_right && !triger_push_sift && gamemanager->down_right) {
			pla_dir= false;
			pos.x += pla_speed;
	}
	if (gamemanager->atach->pla_left && !triger_push_sift && gamemanager->down_left) {
			pla_dir = true;
			pos.x -= pla_speed;
	}

	//--------------------------------------------------------------------------------------------------
	/*Arrow*/
	//--------------------------------------------------------------------------------------------------
	
	//spaceを押したとき、その時の矢の属性を発射する
	if (gamemanager->trigger_sapce) {
		for (auto arw_m : gamemanager->arrow_manager)arw_m->Create_Arrow(pos,pla_dir);
	}

	//--------------------------------------------------------------------------------------------------
	/*HPゲージのあった場合、HPが減る処理*/
	//enemyの攻撃力:3,enemyに当たった場合、HPがへる
	//--------------------------------------------------------------------------------------------------
	bool check = gamemanager->atach->pla_enemyB_check;

	if (check && count_interval == 0) {
		flag_atack_EnemyB = true;
		count_interval = 1.0f;
		count_atack_Enemy_interval = 0.5f;
	}

	if (flag_atack_EnemyB) {
		count_atack_Enemy_interval -= deltatime;
		if (count_atack_Enemy_interval >= 0 && hp_frame % 2 == 0 && gezi_now_num > hp_min_num) {
			gezi_now_num -= 3;
			t2k::debugTrace("\nダメージを受けた:[%d]\n", 3);
		}
		else {
			flag_atack_EnemyB = false;
		}
	}
	else {
		count_interval -= deltatime;
		if (count_interval <= 0) {
			count_interval = 0;
		}
	}
}

void Player::render(const float deltatime) {
	//--------------------------------------------------------------------------------------------------
	/*HPゲージの描画*/
	//HP_max値:300
	//--------------------------------------------------------------------------------------------------
	int gezi_min_x = static_cast<int>(pos.x) - (pla_w >> 1) - 5;
	int gezi_min_y = static_cast<int>(pos.y) + (pla_h >> 1) + 5;
	int gezi_max_x = static_cast<int>(pos.x) + (pla_w >> 1) + 5;
	int gezi_max_y = static_cast<int>(pos.y) + (pla_h >> 1) + 10;
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255, 255, 255);
	//HP_CORVER
	DrawExtendGraph(gezi_min_x - 1, gezi_min_y - 2, gezi_max_x + 2, gezi_max_y + 2, hp_cover, true);
	//HP_RED
	DrawExtendGraph(gezi_min_x, gezi_min_y, gezi_max_x, gezi_max_y, hp_red, true);
	//HP
	DrawExtendGraph(gezi_min_x, gezi_min_y,
		gezi_min_x + (gezi_max_x - gezi_min_x) * (gezi_now_num - hp_min_num) / (hp_max_num - hp_min_num),
		gezi_max_y, hp_green, true);

	//--------------------------------------------------------------------------------------------------
	/*描画処理*/
	//Playerのアニメーションの画像ハンドルの読み込み
	//--------------------------------------------------------------------------------------------------
	anim_player->anim_Player_render();
	
	//------------------------------------------------------------------------------
	/*当たった時のPlayerの赤色に変わる処理*/
	//-------------------------------------------------------------------------------
	bool atach = gamemanager->atach->pla_enemyB_check;
	if(atach)SetDrawBright(255, 0, 0);
	else SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//-------------------------------------------------------------------------------
	/*playerの描画*/
	//-------------------------------------------------------------------------------
	if (!anim_player->init_anim_pla) DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, 0, img_player_stand, true, pla_dir);
	else DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, 0, anim_player->anim_pla[anim_player->anim_move][anim_player->anim_frame], true, pla_dir);

#if PLA_DEBUG
	//-------------------------------------------------------------------------------
	/*Debug*/
	//-------------------------------------------------------------------------------
	SetFontSize(20);
	DrawStringEx(100, 100, 255, "posX:%1.0f,posY:%1.0f", pos.x, pos.y);
	DrawStringEx(100, 120, 255, "grand_atach = %d", gamemanager->GetAtachWall());
	DrawStringEx(100, 140, 255, "count_atack_Enemy_interval = %.1f", count_atack_Enemy_interval);
	DrawStringEx(100, 160, 255, "count_interval = %.1f", count_interval);
#endif
}