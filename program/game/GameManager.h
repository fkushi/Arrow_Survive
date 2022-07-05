#pragma once
#include<list>
#include<unordered_map>
#include<string>
#include"../library/t2klib.h"

class Base;
class Arrow_Base;
class Player;
class OnAtachEnter;
class Arrow_Manager;
class Arrow_Type;
class Bullet_Player;
class Arrow_Wing;
class OnAtach_Arrow;
class Timer;
class map_StageA;
class map_StageB;
class map_Wall;
class Pop_EnemyB;
class Enemy_B;

class GameManager {
public:
	GameManager();

	//---------------------------------------------------------------------------------------------------
	/*クラスのリスト一覧*/
	//---------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------
	/*基底クラス*/
	//----------------------------------------------------------------
	/*Base*/
	std::list<Base*>			base;
	std::list<Arrow_Base*>		arrow_base;

	//---------------------------------------------------------------------------------------------------
	/*クラス　&　クラスのリスト一覧*/
	//---------------------------------------------------------------------------------------------------
	/*Player*/
	Player* player;

	/*当たり判定*/
	OnAtachEnter* atach = nullptr;

	/*Arrow*/
	std::list<Arrow_Manager*>	arrow_manager;
	std::list<Arrow_Type*>		arrow_type;
	std::list<Bullet_Player*>	bullet_player;
	std::list<Arrow_Wing*>		arrow_wing;
	std::list<OnAtach_Arrow*>	atach_arrow;

	/*Stage*/
	std::list<Timer*>			time;
	Timer* timer = nullptr;

	std::list<map_StageA*>		map_stageA;
	std::list<map_StageB*>		map_stageB;
	std::list<map_Wall*>		map_wall;

	/*Enemy*/
	std::list<Pop_EnemyB*>		pop_enemyB;
	std::list<Enemy_B*>			enemy_B;

	//---------------------------------------------------------------------------------------------------
	/*関数*/
	//---------------------------------------------------------------------------------------------------

	/*画像ハンドルの読み込み*/

	//読み込んだ画像ハンドルとパスを登録しておくマップ
	std::unordered_map<std::string, int>loadGh;

	//画像のロード,既ロードなら画像ハンドルを返す
	int LoadGraphEx(std::string ghPass);

	//タイマークラスのインスタンス生成
	void CreateTimer();

	//playerを作る関数
	void CreatePlayer();

	//今のシーンのID
	int nowSceneNum = 0;
	//今のシーンを取得する関数
	inline void GetNowScene(int nowScene) {
		nowSceneNum = nowScene;
	}


	//----------------------------------------------------------------
	/*KEYBOARD*/
	//----------------------------------------------------------------
	bool down_shift = false;
	bool relese_shift = false;
	bool down_up = false;
	bool down_down = false;
	bool down_right = false;
	bool trigger_right = false;
	bool down_left = false;
	bool trigger_left = false;
	bool trigger_enter = false;
	bool trigger_sapce = false;

	void Control_Keyboard();

	//----------------------------------------------------------------
	/*Fade*/
	//----------------------------------------------------------------
	void SetFade(bool fade);

	//----------------------------------------------------------------
	/*PLAYER*/
	//----------------------------------------------------------------
	//playerの描画座標を取得する関数
	t2k::Vector3 GetPosPlayer();
	//
	t2k::Vector3 GetPos_ChangedPlayer(int pos_x, int pos_y);

	//bool GetPlayerDir();

	bool GetPla_pla_dir();
	bool GetPla_triger_push_sift();
	int GetPlaSize_W();
	int GetPlaSize_H();
	int GetPlaHp_now();

	//----------------------------------------------------------------
	/*Arrow*/
	//----------------------------------------------------------------
	t2k::Vector3 GetArw_preve_Center();
	int GetArwTyp_arrow_type();
	bool GetArwWin_sequence_rotate();

	//----------------------------------------------------------------
	/*STAGE*/
	//----------------------------------------------------------------
	int GetCreSt_stage_type();
	int GetAtachWall();
	int GetTime_S();
	int GetTime_M();

	//----------------------------------------------------------------
	/*OnAtach*/
	//----------------------------------------------------------------
	int GetOnAt_Arw_arrow_type();

	//---------------------------------------------------------------------------------------------------
	/*CREATE_OBJECT*/
	//---------------------------------------------------------------------------------------------------
	void createEnemyB(t2k::Vector3 start, int speed);

	//---------------------------------------------------------------------------------------------------
	/*initialize*/
	//---------------------------------------------------------------------------------------------------
	void initialize();

	//---------------------------------------------------------------------------------------------------
	/*DELETE_CHECK*/
	//---------------------------------------------------------------------------------------------------
	void eraceCheck_Base();
	void eraceCheck();

	//---------------------------------------------------------------------------------------------------
	/*updata,render*/
	//---------------------------------------------------------------------------------------------------
	void update(float deltatime);
	void render(float deltatime);


	//debug
	int second = 0;

};