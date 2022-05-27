#pragma once
#include<list>
#include"Base.h"
/*Player*/
#include"Player.h"
/*Arrow*/
#include"Arrow_Type.h"
#include"Bullet_Player.h"
#include"Arrow_Wing.h"
/*Stage*/
#include"Timer.h"
#include"map_StageA.h"
#include"map_StageB.h"
/*Enemy*/
#include"Pop_EnemeyB.h"
#include"Enemy_B.h"
#include"map_Wall.h"
/*当たり判定*/
#include"OnAtachEnter.h"
#include"OnAtach_Arrow.h"

class GameManager {
public:
	GameManager();

	//---------------------------------------------------------------------------------------------------
	/*クラスのリスト一覧*/
	//---------------------------------------------------------------------------------------------------
	/*Player*/
	Player*						pla;
	/*当たり判定*/
	OnAtachEnter				atach;
	/*Base*/
	std::list<Base*>			base;
	/*Arrow*/
	std::list<Arrow_Type*>		arw_typ;
	std::list<Bullet_Player*>	blt_pla;
	std::list<Arrow_Wing*>		arw_win;
	std::list<OnAtach_Arrow*>	atach_arw;
	/*Stage*/
	std::list<Timer*>			time;
	std::list<map_StageA*>		m_stA;
	std::list<map_StageB*>		m_stB;
	std::list<map_Wall*>		m_wal;
	/*Enemy*/
	std::list<Pop_EnemyB*>		pop_stB;
	std::list<Enemy_B*>			enm_B;
	
	//---------------------------------------------------------------------------------------------------
	/*関数*/
	//---------------------------------------------------------------------------------------------------
	bool down_sift = false;
	bool relese_sift = false;
	bool down_up = false;
	bool down_down = false;
	bool down_right = false;
	bool down_left = false;
	bool triger_enter = false;
	bool triger_sapce = false;

	void Control_Keyboard();

	//PLAYER
	t2k::Vector3 GetPosPlayer();
	t2k::Vector3 GetPos_ChangedPlayer(int pos_x,int pos_y);
	bool GetPla_pla_dir();
	bool GetPla_triger_push_sift();
	int GetPlaSize_W();
	int GetPlaSize_H();
	int GetPlaHp_now();
	int GetAtachWall();
	//Arrow
	t2k::Vector3 GetArw_preve_Center();
	int GetArwTyp_arrow_type();
	bool GetArwWin_sequence_rotate();
	//STAGE
	int GetCreSt_stage_type();
	int GetTime_S();
	int GetTime_M();
	//OnAtach
	int GetOnAt_Arw_arrow_type();
	//Vector
	t2k::Vector3 FixVector(float pos_x, float pos_y);
	
	//---------------------------------------------------------------------------------------------------
	/*CREATE_OBJECT*/
	//---------------------------------------------------------------------------------------------------
	void createBullet_Player(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed);
	void createArrwo_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed);
	void createEnemyB(t2k::Vector3 start, int speed);
	
	//---------------------------------------------------------------------------------------------------
	/*initialize*/
	//---------------------------------------------------------------------------------------------------
	void initialize();

	//---------------------------------------------------------------------------------------------------
	/*DELETE_CHECK*/
	//---------------------------------------------------------------------------------------------------
	void eraceCheck();

	//---------------------------------------------------------------------------------------------------
	/*updata,render*/
	//---------------------------------------------------------------------------------------------------
	void update(float deltatime);
	void render(float deltatime);
};