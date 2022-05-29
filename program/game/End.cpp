#include"End.h"
#include"SceneManager.h"
#include"IMG_load.h"
#include"DxLib.h"
#include"GameManager.h"
#include "../support/Support.h"

extern GameManager* gamemanager;
extern SceneManager scene;
extern IMG_load img;

//playerが生き残った結果をみせるシーン
GameEnd::GameEnd() {

}

void GameEnd::update(const float deltatime) {

}
void GameEnd::render(const float deltatime) {
	img.img_end();
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0f, 0, img.end, true);
	SetFontSize(100);
	DrawStringEx((1024 >> 1) - 150, 200, GetColor(255, 100, 100), "%02d:%02d", 
		scene.preve_m, scene.preve_s);
	//DrawStringEx(500, 300, GetColor(255, 255, 255), "結果発表", true);
}