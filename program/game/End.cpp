#include"End.h"
#include"SceneManager.h"
#include"DxLib.h"
#include"GameManager.h"
#include "../support/Support.h"

extern GameManager* gamemanager;
extern SceneManager scene;

//-----------------------------------------------------------------------------------------------------------
/*player‚ª¶‚«Žc‚Á‚½Œ‹‰Ê‚ð‚Ý‚¹‚éƒNƒ‰ƒX*/
//-----------------------------------------------------------------------------------------------------------

GameEnd::GameEnd() {

}

void GameEnd::update(const float deltatime) {

}
void GameEnd::render(const float deltatime) {
	//------------------------------------------------------------------
	//•`‰æƒnƒ“ƒhƒ‹‚Ì“Ç‚Ýž‚Ý
	//------------------------------------------------------------------
	img_end = gamemanager->LoadGraphEx("graphics/End.jpg");
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0f, 0, img_end, true);
	
	//------------------------------------------------------------------
	/*¶‘¶ŽžŠÔ‚Ì•`‰æ*/
	//preve_m:•ªApreve_s:•b‚ð•`‰æ‚·‚é
	//------------------------------------------------------------------
	SetFontSize(100);
	DrawStringEx((1024 >> 1) - 150, 200, GetColor(255, 100, 100), "%02d:%02d", 
		scene.preve_m, scene.preve_s);
}