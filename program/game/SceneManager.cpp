#include"SceneManager.h"
#include"Taitle.h"
#include"End.h"
#include"../library/t2klib.h"
#include"GameManager.h"
#include"Base.h"
#include"Arrow_Base.h"
#include"SONG_load.h"
#include"Player.h"
#include"Create_Stage.h"
#include"map_StageA.h"
#include"map_StageB.h"
#include"map_Wall.h"
#include"Arrow_Manager.h"
#include"Bullet_Player.h"
#include"Arrow_Wing.h"
#include"OnAtach_Arrow.h"
#include"Arrow_Type.h"
#include"Pop_EnemeyB.h"
#include"Enemy_B.h"
#include"OnAtachEnter.h"
#include"Fade_Manager.h"
#include"Dxlib.h"

extern GameManager* gamemanager;
extern Create_Stage	c_st;
extern Fade_Manager fade_manager;
SONG_load		song;
Taitle			taitle;
GameEnd			end;

//-------------------------------------------------------------------------------------------------------------------
/*シーン制御*/
//-------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
/*タイトル*/
//----------------------------------------------------------------------------------------
bool SceneManager::seqTitle(const float deltatime) {

	if (sequence_.isStart()) {
		//------------------------------------------------------------------
		/*音源_load*/
		//------------------------------------------------------------------
		song.init_bgm = false;
		song.SONG_bgm();

		//------------------------------------------------------------------
		/*音量調節*/
		//------------------------------------------------------------------
		ChangeVolumeSoundMem(100, song.bgm_taitle);

		//------------------------------------------------------------------
		/*音_PLAY*/
		//------------------------------------------------------------------
		PlaySoundMem(song.bgm_taitle, DX_PLAYTYPE_LOOP, false);

		//フェード処理
		fade_manager.init_fade = false;
		init_move_seqGameEnd = false;
	}

	//------------------------------------------------------------------
	/*背景描画*/
	//------------------------------------------------------------------
	taitle.render(deltatime);

	//------------------------------------------------------------------
	/*ENTER押したら次のプレイステージ_シーンへ*/
	//------------------------------------------------------------------
	if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_SPACE))fade_manager.FadeOut(5);
	else if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_B))fade_manager.FadeIn(5);

	//------------------------------------------------------------------
	//フェード処理 & シーン移動
	// Enterをおしたらフェードアウトする、フェードアウトし終えたらシーン移動
	//------------------------------------------------------------------
	fade_manager.Fade();

	//-----------------------------------
	//フェード処理flag
	//-----------------------------------
	if (gamemanager->trigger_enter) {
		fade_manager.init_fade = true;
	}
	if (fade_manager.FadeOut(0)) {
		sequence_.change(&SceneManager::seqStage);
		nowScene = SCENE::STAGE;
		gamemanager->GetNowScene(static_cast<uint32_t>(nowScene));

		/*if (gamemanager->atach->pla_enemyB_check)t2k::debugTrace("\n当たってるよ\n");
		else t2k::debugTrace("\n当たってないよ\n");*/
	}

	return true;
}

//----------------------------------------------------------------------------------------
/*プレイステージ*/
//----------------------------------------------------------------------------------------
bool SceneManager::seqStage(const float deltatime) {

	if (sequence_.isStart()) {

		//-----------------------------------
		//フェード処理flag
		//-----------------------------------
		fade_manager.init_fade = false;

		//------------------------------------------------------------------
		/*最初のステージ*/
		//------------------------------------------------------------------
		new map_StageA();
		new map_Wall();
		//new Timer(t2k::Vector3(450, 90, 0));
		gamemanager->CreateTimer();
		if (gamemanager->atach == nullptr) {
			gamemanager->atach = new OnAtachEnter();
		}

		if (gamemanager->atach->pla_enemyB_check)t2k::debugTrace("\n当たってるよ\n");
		else t2k::debugTrace("\n当たってないよ\n");

		gamemanager->CreatePlayer();
		//gamemanager->player = new Player(t2k::Vector3(1024 >> 1, 768 >> 1, 0), 5);
		new Arrow_Manager();

		//-----------------------------------------------
		/*Playerの死亡時のシーン移動インターバル初期化*/
		//-----------------------------------------------
		count_move_seqGameEnd_interval = 1.0f;

		//------------------------------------------------------------------
		/*音源のload*/
		//------------------------------------------------------------------
		song.init_bgm = false;
		song.init_se = false;
		song.SONG_SE_Arrow();
		init_st1_sound = false;
	}

	//------------------------------------------------------------------
	//フェード処理
	//------------------------------------------------------------------
	fade_manager.Fade();

	if (gamemanager->GetCreSt_stage_type() == 1) {
		//------------------------------------------------------------------
		/*音源処理*/
		//------------------------------------------------------------------
		if (!init_st1_sound) {
			//-----------------------------------------------------
			//音源_DELETE
			//-----------------------------------------------------
			DeleteSoundMem(song.bgm_taitle);

			//-----------------------------------------------------
			//音源_PLAY
			//-----------------------------------------------------
			PlaySoundMem(song.bgm_stage, DX_PLAYTYPE_LOOP, false);

			//-----------------------------------------------------
			//フェード処理flag
			//-----------------------------------------------------
			init_st1_sound = true;
		}
	}

	//----------------------------------------------------------------------------------------
	/*player移動時のステージ生成*/
	//----------------------------------------------------------------------------------------
	c_st.create_Stage();

	//----------------------------------------------------------------------------------------
	/*GameEnd*/
	//----------------------------------------------------------------------------------------
	if (count_move_seqGameEnd_interval < 0) {

		//------------------------------------------------------------------
		/*生存時間記録*/
		//------------------------------------------------------------------
		preve_m = gamemanager->GetTime_M();
		preve_s = gamemanager->GetTime_S();

		//------------------------------------------------------------------
		/*DELETE処理*/
		//------------------------------------------------------------------
		Del_END();
		gamemanager->eraceCheck();
		gamemanager->eraceCheck_Base();

		//------------------------------------------------------------------
		/*STAGETYPEを初期化*/
		//------------------------------------------------------------------
		c_st.pla_next_pop = 0;

		//-----------------------------------
		//fade処理flag
		//-----------------------------------
		init_move_seqGameEnd = true;
		fade_manager.init_fade = true;
	}

	//------------------------------------------------------------------
	/*次のシーンに移動*/
	//------------------------------------------------------------------
	if (fade_manager.FadeOut(0) && init_move_seqGameEnd) {

		nowScene = SCENE::END;
		gamemanager->GetNowScene(static_cast<uint32_t>(nowScene));
		sequence_.change(&SceneManager::seqGameEnd);

	}

	return true;
}
/*ゲーム終了*/
bool SceneManager::seqGameEnd(const float deltatime) {

	if (sequence_.isStart()) {

		fade_manager.init_fade = false;

		//------------------------------------------------------------------
		/*音源処理*/
		//loadした音源を消去する
		//------------------------------------------------------------------
		DeleteSoundMem(song.bgm_stage);
		DeleteSoundMem(song.bgm_taitle);
		DeleteSoundMem(song.se_atach);
		DeleteSoundMem(song.se_shot);

		//------------------------------------------------------------------
		/*音_PLAY*/
		//------------------------------------------------------------------
		song.init_bgm = false;
		PlaySoundMem(song.bgm_end, DX_PLAYTYPE_LOOP, true);
	}

	//------------------------------------------------------------------
	//フェード処理
	//------------------------------------------------------------------
	fade_manager.Fade();

	//------------------------------------------------------------------
	/*背景描画*/
	//------------------------------------------------------------------
	end.render(deltatime);

	//------------------------------------------------------------------
	/*ENTERを押したら次のシーンへ*/
	//------------------------------------------------------------------
	if (gamemanager->trigger_enter) {

		gamemanager->player->Reset();
		DeleteSoundMem(song.bgm_end);

		nowScene = SCENE::TITLE;
		gamemanager->GetNowScene(static_cast<uint32_t>(nowScene));

		if (gamemanager->atach->pla_enemyB_check)t2k::debugTrace("\n当たってるよ\n");
		else t2k::debugTrace("\n当たってないよ\n");

		sequence_.change(&SceneManager::seqTitle);
	}

	return true;
}

//----------------------------------------------------------------------------------------
/*全デリート*/
//----------------------------------------------------------------------------------------
void SceneManager::Del_END() {
	//------------------------------------------------------------------
	/*player*/
	//------------------------------------------------------------------
	//gamemanager->player = nullptr;

	//------------------------------------------------------------------
	/*stage_type初期化*/
	//------------------------------------------------------------------
	c_st.stage_type = 0;

	//------------------------------------------------------------------
	/*arrow*/
	//------------------------------------------------------------------
	for (auto bp : gamemanager->bullet_player)bp->arrow_alive = false;
	for (auto arw_w : gamemanager->arrow_wing)arw_w->arrow_alive = false;
	for (auto ataw : gamemanager->atach_arrow)ataw->arrow_alive = false;
	for (auto arw_t : gamemanager->arrow_type)arw_t->arrow_alive = false;
	for (auto arw_b : gamemanager->arrow_base)arw_b->arrow_alive = false;
	for (auto arw_m : gamemanager->arrow_manager)arw_m->is_alive = false;

	//------------------------------------------------------------------
	/*stage*/
	//------------------------------------------------------------------
	for (auto st_a : gamemanager->map_stageA)st_a->is_alive = false;
	for (auto st_b : gamemanager->map_stageB)st_b->is_alive = false;
	for (auto p_b : gamemanager->pop_enemyB)p_b->is_alive = false;

	//------------------------------------------------------------------
	/*enemy*/
	//------------------------------------------------------------------
	for (auto eb : gamemanager->enemy_B)eb->is_alive = false;

	//------------------------------------------------------------------
	/*base*/
	//------------------------------------------------------------------
	//for (auto ba : gamemanager->base)ba->is_alive = false;
}