#include"map_StageA.h"
#include"GameManager.h"
#include"DxLib.h"
#include"IMG_load.h"

extern GameManager* gamemanager;
IMG_load img;

/*操作を把握するための初期ステージ*/
map_StageA::map_StageA() {
	gamemanager->m_stA.emplace_back(this);
}

void map_StageA::update(const float deltatime) {

}
void map_StageA::render(const float deltatime) {
	img.img_back();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0, 0, img.back, true);
}