#include"SceneManager.h"
#include"Taitle.h"
#include"End.h"
#include"../library/t2klib.h"
#include"IMG_load.h"
#include"Create_Stage.h"
#include"GameManager.h"

extern GameManager* gamemanager;
extern IMG_load img;
Taitle			taitle;
GameEnd			end;
Create_Stage	c_st;
//----------------------------------------------------------------------------------------
/*シーン制御*/
//----------------------------------------------------------------------------------------
/*タイトル*/
bool SceneManager::seqTitle(const float deltatime) {
	taitle.render(deltatime);
	if (gamemanager->triger_enter)sequence_.change(&SceneManager::seqStage);
	return true;
}
/*プレイステージ*/
bool SceneManager::seqStage(const float deltatime) {
	if (sequence_.isStart()) {
		/*最初のステージ*/
		new map_StageA();
		new map_Wall();
		new Timer(t2k::Vector3(450, 90, 0));
		gamemanager->pla = new Player(t2k::Vector3(1024 >> 1, 768 >> 1, 0),5);
	}
	//------------------------------------------------------------------------------
	/*player移動時のステージ生成*/
	c_st.create_Stage();
	//------------------------------------------------------------------------------
	/*GameEnd*/
	//if (gamemanager->GetPlaHp_now() <= 0){
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_Z) && 
		gamemanager->down_sift) {
		preve_m = gamemanager->GetTime_M();
		preve_s = gamemanager->GetTime_S();
		Del_END();
		c_st.pla_next_pop = 0;
		gamemanager->eraceCheck();
		sequence_.change(&SceneManager::seqGameEnd);
	}
	return true;
}
/*ゲーム終了*/
bool SceneManager::seqGameEnd(const float deltatime) {
	end.render(deltatime);
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_NUMPADENTER))sequence_.change(&SceneManager::seqTitle);
	return true;
}
/*全デリート*/
void SceneManager::Del_END() {
	gamemanager->pla = nullptr;
	c_st.stage_type = 0;
	img.init_img_back = false;
	/*arrow*/
	for (auto bp : gamemanager->blt_pla)bp->is_alive = false;
	for (auto ataw : gamemanager->atach_arw)ataw->is_alive = false;
	/*stage*/
	for (auto st_a : gamemanager->m_stA)st_a->is_alive = false;
	for (auto st_b : gamemanager->m_stB)st_b->is_alive = false;
	for (auto p_b : gamemanager->pop_stB)p_b->is_alive = false;
	/*enemy*/
	for (auto eb : gamemanager->enm_B)eb->is_alive = false;
	/*base*/
	for (auto ba : gamemanager->base)ba->is_alive = false;
}