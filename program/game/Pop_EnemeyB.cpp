#include"Pop_EnemeyB.h"
#include"IMG_load.h"
#include"GameManager.h"
#include"DxLib.h"
#include<stdlib.h>
#include"../library/t2klib.h"
#include "../support/Support.h"

extern IMG_load img;
extern GameManager* gamemanager;

/*Enemy_B‚ð¶¬‚·‚éêŠ‚ÌƒNƒ‰ƒX*/
Pop_EnemyB::Pop_EnemyB(t2k::Vector3 start) {
	pos = start;
	new Enemy_B(t2k::Vector3(pos.x, pos.y, 0), 3);
	gamemanager->pop_enemyB.emplace_back(this);
}

void Pop_EnemyB::update(const float deltatime) {
	count_enmB_Create += deltatime;

	//-------------------------------------------------
	/*30•b‚²‚Æ‚É“G‚Ì¶¬”‚ð‘‚â‚·*/
	//-------------------------------------------------
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
	/*2•b‚²‚Æ‚ÉEnemy_B‚ð¶¬‚·‚é*/
	//-------------------------------------------------S
	if (count_enmB_Create > 2.0f) {

		speed = rand() % 3 + add_speed;
		gamemanager->createEnemyB(t2k::Vector3(pos.x, pos.y, 0), speed);
		
		count_enmB_Create = 0;
	}

}
void Pop_EnemyB::render(const float deltatime) {
	img.img_pop();

	/*DEBUG*/
	/*SetFontSize(50);
	DrawStringEx(100, 100, 255, "%d", count_create_enmB);*/

	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0, 0, img.pop, true);
}