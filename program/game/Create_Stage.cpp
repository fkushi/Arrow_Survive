#include"Create_Stage.h"
#include"GameManager.h"
#include"Fade.h"
#include"IMG_load.h"
#include"DxLib.h"

Fade fade;
extern IMG_load img;
extern GameManager* gamemanager;

Create_Stage::Create_Stage() {

}

void Create_Stage::create_Stage() {
	/*フェードアウトフラグ*/
	if (gamemanager->GetPosPlayer().y < 0 || gamemanager->GetPosPlayer().x < 0 ||
		gamemanager->GetPosPlayer().y > 768 || gamemanager->GetPosPlayer().x > 1024) {
		init_fade = true;
	}
	//-----------------------------------------------------------------------------------------
	/*BRIDGEフラグ*/
	if (gamemanager->GetPosPlayer().y < 0 && !init_change)pla_next_pop = up;
	else if (gamemanager->GetPosPlayer().y > 768 && !init_change)pla_next_pop = down;
	else if (gamemanager->GetPosPlayer().x < 0 && !init_change)pla_next_pop = left;
	else if (gamemanager->GetPosPlayer().x > 1024 && !init_change)pla_next_pop = right;
	//else pla_next_pop = fast;
	//-----------------------------------------------------------------------------------------
	/*ステージ生成、プレイヤー移動*/
	if (!init_change) {
		//stage_type = GetRand(1);
		stage_type = 1;
		img.init_img_back = false;
		img.init_img_pop = false;
		if (pla_next_pop == up)gamemanager->GetPos_ChangedPlayer(512, 679);
		if (pla_next_pop == down)gamemanager->GetPos_ChangedPlayer(512, 89);
		if (pla_next_pop == right)gamemanager->GetPos_ChangedPlayer(92, 384);
		if (pla_next_pop == left)gamemanager->GetPos_ChangedPlayer(942, 384);
		if (stage_type == 0)new map_StageA();
		if(stage_type == 1)new map_StageB(0, 0);
		init_change = true;
	}
	//-----------------------------------------------------------------------------------------
	/*フェードアウト、フェードイン*/
	if (!init_fade) fade.FadeIn(5);
	else fade.FadeOut(5);
	//-----------------------------------------------------------------------------------------
	/*DELETE_CHECK*/
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_B)) {
		//for (auto p_b : gamemanager->pop_stB)p_b->is_alive = false;
		//for (auto eb : gamemanager->enm_B)eb->is_alive = false;
	}
	gamemanager->eraceCheck();
}
/*DELETE*/
void Create_Stage::Changed_Delete() {
	init_change = false;
	/*Stage*/
	for (auto st_a : gamemanager->m_stA)st_a->is_alive = false;
	for (auto st_b : gamemanager->m_stB)st_b->is_alive = false;
	/*Enemy*/
	for (auto p_b : gamemanager->pop_stB)p_b->is_alive = false;
	for (auto eb : gamemanager->enm_B)eb->is_alive = false;
	/*Arrow*/
	for (auto arw : gamemanager->blt_pla)arw->is_alive = false;
	for (auto arw_w : gamemanager->arw_win)arw_w->is_alive = false;
}