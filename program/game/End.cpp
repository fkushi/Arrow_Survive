#include"End.h"
#include"SceneManager.h"
#include"DxLib.h"
#include"GameManager.h"
#include "../support/Support.h"

extern GameManager* gamemanager;
extern SceneManager scene;

//-----------------------------------------------------------------------------------------------------------
/*player�������c�������ʂ��݂���N���X*/
//-----------------------------------------------------------------------------------------------------------

GameEnd::GameEnd() {

}

void GameEnd::update(const float deltatime) {

}
void GameEnd::render(const float deltatime) {
	//------------------------------------------------------------------
	//�`��n���h���̓ǂݍ���
	//------------------------------------------------------------------
	img_end = gamemanager->LoadGraphEx("graphics/End.jpg");
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0f, 0, img_end, true);
	
	//------------------------------------------------------------------
	/*�������Ԃ̕`��*/
	//preve_m:���Apreve_s:�b��`�悷��
	//------------------------------------------------------------------
	SetFontSize(100);
	DrawStringEx((1024 >> 1) - 150, 200, GetColor(255, 100, 100), "%02d:%02d", 
		scene.preve_m, scene.preve_s);
}