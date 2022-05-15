#include"Pop_EnemeyB.h"
#include"IMG_load.h"
#include"GameManager.h"
#include"DxLib.h"
#include<stdlib.h>
#include"../library/t2klib.h"

extern IMG_load img;
extern GameManager* gamemanager;

Pop_EnemyB::Pop_EnemyB() {
	pos.x = 1024 >> 1;
	pos.y = 768 >> 1;
	new Enemy_B(t2k::Vector3(pos.x, pos.y, 0), 3);
	gamemanager->pop_stB.emplace_back(this);
}

void Pop_EnemyB::update(const float deltatime) {
	count_enmB_Create += deltatime;
	if (count_enmB_Create > 2.0f) {
		int speed = rand() % 3 + 2;
		gamemanager->createEnemyB(t2k::Vector3(pos.x, pos.y, 0), speed);
		count_enmB_Create = 0;
	}
}
void Pop_EnemyB::render(const float deltatime) {
	img.img_pop();
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0, 0, img.pop, true);
}