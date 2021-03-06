#include"End.h"
#include"SceneManager.h"
#include"DxLib.h"
#include"GameManager.h"
#include "../support/Support.h"

extern GameManager* gamemanager;
extern SceneManager scene;

//-----------------------------------------------------------------------------------------------------------
/*playerが生き残った結果をみせるクラス*/
//-----------------------------------------------------------------------------------------------------------

GameEnd::GameEnd() {

}

void GameEnd::update(const float deltatime) {

}
void GameEnd::render(const float deltatime) {
	//------------------------------------------------------------------
	//描画ハンドルの読み込み
	//------------------------------------------------------------------
	img_end = gamemanager->LoadGraphEx("graphics/End.jpg");
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0f, 0, img_end, true);
	
	//------------------------------------------------------------------
	/*生存時間の描画*/
	//preve_m:分、preve_s:秒を描画する
	//------------------------------------------------------------------
	SetFontSize(100);
	DrawStringEx((1024 >> 1) - 150, 200, GetColor(255, 100, 100), "%02d:%02d", 
		scene.preve_m, scene.preve_s);
}