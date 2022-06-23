#pragma once
#include<list>
#include<unordered_map>
#include<string>
#include"Base.h"
/*Player*/
#include"Player.h"
/*Arrow*/
#include"Arrow_Manager.h"
#include"Arrow_Base.h"
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
/*�����蔻��*/
#include"OnAtachEnter.h"
#include"OnAtach_Arrow.h"

class GameManager {
public:
	GameManager();

	//---------------------------------------------------------------------------------------------------
	/*�N���X�̃��X�g�ꗗ*/
	//---------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------
	/*���N���X*/
	//----------------------------------------------------------------
	/*Base*/
	std::list<Base*>			base;
	std::list<Arrow_Base*>		arrow_base;

	//---------------------------------------------------------------------------------------------------
	/*�N���X�@&�@�N���X�̃��X�g�ꗗ*/
	//---------------------------------------------------------------------------------------------------
	/*Player*/
	Player* player;

	/*�����蔻��*/
	OnAtachEnter*				atach;

	/*Arrow*/
	std::list<Arrow_Manager*>	arrow_manager;
	std::list<Arrow_Type*>		arrow_type;
	std::list<Bullet_Player*>	bullet_player;
	std::list<Arrow_Wing*>		arrow_wing;
	std::list<OnAtach_Arrow*>	atach_arrow;

	/*Stage*/
	std::list<Timer*>			time;
	std::list<map_StageA*>		map_stageA;
	std::list<map_StageB*>		map_stageB;
	std::list<map_Wall*>		map_wall;

	/*Enemy*/
	std::list<Pop_EnemyB*>		pop_enemyB;
	std::list<Enemy_B*>			enemy_B;

	//---------------------------------------------------------------------------------------------------
	/*�֐�*/
	//---------------------------------------------------------------------------------------------------

	/*�摜�n���h���̓ǂݍ���*/

	//�ǂݍ��񂾉摜�n���h���ƃp�X��o�^���Ă����}�b�v
	std::unordered_map<std::string, int>loadGh;

	//�摜�̃��[�h,�����[�h�Ȃ�摜�n���h����Ԃ�
	int LoadGraphEx(std::string ghPass);

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
	/*PLAYER*/
	//----------------------------------------------------------------
	//player�̕`����W���擾����֐�
	t2k::Vector3 GetPosPlayer();
	//
	t2k::Vector3 GetPos_ChangedPlayer(int pos_x,int pos_y);

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
};