#include"map_StageB.h"
#include"IMG_load.h"
#include"DxLib.h"
#include"GameManager.h"

extern GameManager* gamemanager;
extern IMG_load img;

/*敵がたくさんでてくるステージ*/
map_StageB::map_StageB(int back, int wall) {

	new Pop_EnemyB(t2k::Vector3(1024>>1,768>>1,0));
	
	gamemanager->map_stageB.emplace_back(this);
}

void map_StageB::update(const float deltatime) {
	if (gamemanager->GetTime_M() >= 1 && gamemanager->GetTime_M() <= 2) {
		if (!init_plus_pos_B) {
			new Pop_EnemyB(t2k::Vector3(-500, -300, 0));
			init_plus_pos_B = true;
		}
	}else if (gamemanager->GetTime_M() >= 3) {
		if (!init_plus_pos_B) {
			new Pop_EnemyB(t2k::Vector3(1520, -300, 0));
			init_plus_pos_B = true;
		}
	}
}
void map_StageB::render(const float deltatime) {
	img.img_back();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0, 0, img.back, true);
}