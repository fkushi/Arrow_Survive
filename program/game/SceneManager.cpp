#include"SceneManager.h"
#include"Taitle.h"
#include"End.h"
#include"../library/t2klib.h"
#include"IMG_load.h"
#include"SONG_load.h"
#include"Create_Stage.h"
#include"GameManager.h"
#include"Dxlib.h"

extern GameManager* gamemanager;
extern IMG_load img;
SONG_load		song;
Taitle			taitle;
GameEnd			end;
Create_Stage	c_st;

//----------------------------------------------------------------------------------------
/*シーン制御*/
//----------------------------------------------------------------------------------------
/*タイトル*/
bool SceneManager::seqTitle(const float deltatime) {

	if (sequence_.isStart()) {
		//音源_load
		song.init_bgm = false;
		song.SONG_bgm();
		
		//音量調節
		ChangeVolumeSoundMem(100, song.bgm_taitle);

		//音_PLAY
		PlaySoundMem(song.bgm_taitle, DX_PLAYTYPE_LOOP, false);
	}
	//背景描画
	taitle.render(deltatime);

	//ENTER押したら次のシーンへ
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
		gamemanager->pla = new Player(t2k::Vector3(1024 >> 1, 768 >> 1, 0), 5);
		
		/*音源のload*/
		song.init_bgm = false;
		song.init_se = false;
		song.SONG_SE_Arrow();
		
		init_st1_sound = false;
	}

	if (gamemanager->GetCreSt_stage_type() == 1) {
		/*音源処理*/
		if (!init_st1_sound) {
			//音源_DELETE
			DeleteSoundMem(song.bgm_taitle);

			//音源_PLAY
			PlaySoundMem(song.bgm_stage, DX_PLAYTYPE_LOOP,false);

			init_st1_sound = true;
		}
	}

	//------------------------------------------------------------------------------
	/*player移動時のステージ生成*/
	c_st.create_Stage();

	//------------------------------------------------------------------------------
	/*GameEnd*/
	if (gamemanager->GetPlaHp_now() <= 0 || (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_Z) &&
		gamemanager->down_sift)){
		//生存時間記録
		preve_m = gamemanager->GetTime_M();
		preve_s = gamemanager->GetTime_S();

		//DELETE処理
		Del_END();
		gamemanager->eraceCheck();

		//STAGETYPEを初期化
		c_st.pla_next_pop = 0;

		//次のシーンに移動
		sequence_.change(&SceneManager::seqGameEnd);
	}

	return true;
}
/*ゲーム終了*/
bool SceneManager::seqGameEnd(const float deltatime) {

	if (sequence_.isStart()) {
		/*音源処理*/
		//loadした音源を消去する
		DeleteSoundMem(song.bgm_stage);
		DeleteSoundMem(song.bgm_taitle);
		DeleteSoundMem(song.se_atach);
		DeleteSoundMem(song.se_shot);

		//音_PLAY
		song.init_bgm = false;
		
		PlaySoundMem(song.bgm_end, DX_PLAYTYPE_LOOP, true);
	}

	//背景描画
	end.render(deltatime);
	
	//ENTERを押したら次のシーンへ
	if (gamemanager->triger_enter) {
		DeleteSoundMem(song.bgm_end);
		sequence_.change(&SceneManager::seqTitle);
	}

	return true;
}
/*全デリート*/
void SceneManager::Del_END() {
	/*player*/
	gamemanager->pla = nullptr;
	/*stage_type初期化*/
	c_st.stage_type = 0;
	/*背景変更*/
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