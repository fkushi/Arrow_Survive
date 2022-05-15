#pragma once
#include<list>
#include"Base.h"
#include"Timer.h"
#include"Player.h"
#include"Bullet_Player.h"
#include"map_StageA.h"
#include"map_StageB.h"
#include"Pop_EnemeyB.h"
#include"Enemy_B.h"
#include"map_Wall.h"
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
	std::list<Bullet_Player*>	blt_pla;
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
	//PLAYER
	t2k::Vector3 GetPosPlayer();
	t2k::Vector3 GetPos_ChangedPlayer(int pos_x,int pos_y);
	int GetPlaSize_W();
	int GetPlaSize_H();
	int GetPlaHp_now();
	int GetAtachWall();
	//STAGE
	int GetBase_Backtype();
	int GetBase_Changetype(int back_type);
	int GetTime_S();
	int GetTime_M();
	
	//---------------------------------------------------------------------------------------------------
	/*CREATE_OBJECT*/
	//---------------------------------------------------------------------------------------------------
	void createBullet_Player(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed);
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