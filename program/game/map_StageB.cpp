#include"map_StageB.h"
#include"IMG_load.h"
#include"DxLib.h"
#include"GameManager.h"

extern GameManager* gamemanager;
extern IMG_load img;

map_StageB::map_StageB(int back, int wall) {
	new Pop_EnemyB(t2k::Vector3(1024>>1,768>>1,0));
	
	gamemanager->m_stB.emplace_back(this);
}

void map_StageB::update(const float deltatime) {

}
void map_StageB::render(const float deltatime) {
	img.img_back();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0, 0, img.back, true);
}