#pragma once
#include"Base.h"
#include"../library/t2klib.h"

//--------------------------------------------------------------------------------------------------------------------------
/*Enemy_B�𐶐�����ꏊ�̃N���X*/
//--------------------------------------------------------------------------------------------------------------------------
class Pop_EnemyB : public Base {
private:
	bool init_count_time_cretate = false;
	bool init_count_enB_Create = false;

	//�G�l�~�[�̐����Ԋu�̕ϐ�
	float count_enmB_Create = 0;

	//Enemy_B�̃X�s�[�h
	int speed = 0;

	//�`��n���h��
	int img_Pop_enemyB = 0;
	int count_create_enmB = 1;
public:

	Pop_EnemyB(t2k::Vector3 start);

	//�`��n���h���̃T�C�Y
	int size_w = 35;
	int size_h = 32;

	int add_speed = 2;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};