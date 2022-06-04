#include"Pop_EnemeyB.h"
#include"GameManager.h"
#include"DxLib.h"
#include"../library/t2klib.h"
#include "../support/Support.h"

extern GameManager* gamemanager;

//--------------------------------------------------------------------------------------------------------------------------
/*Enemy_B�𐶐�����ꏊ�̃N���X*/
//--------------------------------------------------------------------------------------------------------------------------
Pop_EnemyB::Pop_EnemyB(t2k::Vector3 start) {
	pos = start;

	//Enemy_B�̐V�K�C���X�^���X����
	new Enemy_B(t2k::Vector3(pos.x, pos.y, 0), 3);

	//�摜�n���h���̓ǂݍ���
	img_Pop_enemyB = gamemanager->LoadGraphEx("graphics/Enemy/Pop/pop_B.png");

	gamemanager->pop_enemyB.emplace_back(this);
}

void Pop_EnemyB::update(const float deltatime) {
	
	/*30�b���ƂɓG�̐������𑝂₷*/
	if (gamemanager->GetTime_S() > 30)init_count_time_cretate = true;
	else if (gamemanager->GetTime_S() < 5)init_count_enB_Create = false;

	if (init_count_time_cretate) {

		if (!init_count_enB_Create) {
			count_create_enmB++;
			init_count_enB_Create = true;
		}
		
		init_count_time_cretate = false;
	}

	//-------------------------------------------------
	/*2�b���Ƃ�Enemy_B�𐶐�����*/
	//-------------------------------------------------
	count_enmB_Create += deltatime;

	if (count_enmB_Create > 2.0f) {

		speed = rand() % 3 + add_speed;
		gamemanager->createEnemyB(t2k::Vector3(pos.x, pos.y, 0), speed);
		
		count_enmB_Create = 0;
	}

}
void Pop_EnemyB::render(const float deltatime) {
	
	DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0, 0, img_Pop_enemyB, true);

}