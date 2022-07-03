#include"Create_Stage.h"
#include"GameManager.h"
#include"Fade_Manager.h"
#include"DxLib.h"

extern GameManager* gamemanager;
extern Fade_Manager fade_manager;

//--------------------------------------------------------------------------------------------------------------------------
/*StageManagerクラス*/
//橋を渡ったあとのステージ生成のクラス
//--------------------------------------------------------------------------------------------------------------------------

Create_Stage::Create_Stage() {

}

void Create_Stage::create_Stage() {
	//-----------------------------------------------------------------------------------------
	/*フェードフラグ*/
	//-----------------------------------------------------------------------------------------
	fade_manager.Fade();
	if (gamemanager->GetPosPlayer().y < 0 || gamemanager->GetPosPlayer().x < 0 ||
		gamemanager->GetPosPlayer().y > 768 || gamemanager->GetPosPlayer().x > 1024) {
		fade_manager.init_fade = true;
	}
	if (fade_manager.FadeOut(0)) {
		init_change = false;
		Changed_Delete();
	}

	//-----------------------------------------------------------------------------------------
	/*BRIDGEフラグ*/
	//どの橋を渡ったかの確認
	//-----------------------------------------------------------------------------------------
	auto choose_right = static_cast<uint32_t>(CHOOSEWAY::RIGHT);
	auto choose_left = static_cast<uint32_t>(CHOOSEWAY::LEFT);
	auto choose_up = static_cast<uint32_t>(CHOOSEWAY::UP);
	auto choose_down = static_cast<uint32_t>(CHOOSEWAY::DOWN);

	if (gamemanager->GetPosPlayer().y < 0 && !init_change)pla_next_pop = choose_up;
	else if (gamemanager->GetPosPlayer().y > 768 && !init_change)pla_next_pop = choose_down;
	else if (gamemanager->GetPosPlayer().x < 0 && !init_change)pla_next_pop = choose_left;
	else if (gamemanager->GetPosPlayer().x > 1024 && !init_change)pla_next_pop = choose_right;
	
	//-----------------------------------------------------------------------------------------
	/*ステージ生成、プレイヤー移動*/
	//橋を渡った後のplayerのステージの移動処理＆ステージ生成
	//-----------------------------------------------------------------------------------------
	if (!init_change) {
		stage_type = 1;
		if (pla_next_pop == choose_up)gamemanager->GetPos_ChangedPlayer(512, 679);
		if (pla_next_pop == choose_down)gamemanager->GetPos_ChangedPlayer(512, 89);
		if (pla_next_pop == choose_right)gamemanager->GetPos_ChangedPlayer(92, 384);
		if (pla_next_pop == choose_left)gamemanager->GetPos_ChangedPlayer(942, 384);
		if (stage_type == 0)new map_StageA();
		if(stage_type == 1)new map_StageB(0, 0);

		fade_manager.init_fade = false;

		init_change = true;
	}

	//-----------------------------------------------------------------------------------------
	/*DELETE_CHECK*/
	//-----------------------------------------------------------------------------------------
	gamemanager->eraceCheck();

}

/*DELETE*/
void Create_Stage::Changed_Delete() {
	init_change = false;
	/*Stage*/
	for (auto st_a : gamemanager->map_stageA)st_a->is_alive = false;
	for (auto st_b : gamemanager->map_stageB)st_b->is_alive = false;
	/*Enemy*/
	for (auto p_b : gamemanager->pop_enemyB)p_b->is_alive = false;
	for (auto eb : gamemanager->enemy_B)eb->is_alive = false;
	/*Arrow*/
	for (auto arw : gamemanager->bullet_player)arw->arrow_alive = false;
	for (auto arw_w : gamemanager->arrow_wing)arw_w->arrow_alive = false;
	for (auto arw_at : gamemanager->atach_arrow)arw_at->arrow_alive = false;
}