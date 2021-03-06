#include"map_StageB.h"
#include"DxLib.h"
#include"GameManager.h"

extern GameManager* gamemanager;

//-------------------------------------------------------------------------------------------------------------------
/*敵がたくさんでてくるステージ*/
//-------------------------------------------------------------------------------------------------------------------

map_StageB::map_StageB(int back, int wall) {

	//------------------------------------------------------------------
	/*Enemy生成するクラスの新規インスタンス生成*/
	//------------------------------------------------------------------
	new Pop_EnemyB(t2k::Vector3(1024>>1,768>>1,0));

	//------------------------------------------------------------------
	/*描画ハンドルの読み込み*/
	//------------------------------------------------------------------
	img_StageB = gamemanager->LoadGraphEx("graphics/Back/Grass2.png");
	
	gamemanager->map_stageB.emplace_back(this);
}

//------------------------------------------------------------------
/*時間が立つごとにPop_EnemyBのインスタンス生成をする*/
//------------------------------------------------------------------
void map_StageB::update(const float deltatime) {

	//------------------------------------------------------------------
	/*1分以上経ったら画面左上にPop_EnemyBをインスタンス生成する*/
	//------------------------------------------------------------------
	if (gamemanager->GetTime_M() >= 1 && gamemanager->GetTime_M() <= 2) {
		if (!init_plus_pos_B) {
			new Pop_EnemyB(t2k::Vector3(-500, -300, 0));
			init_plus_pos_B = true;
		}

		//------------------------------------------------------------------
		/*3分以上経ったら画面右上にPop_EnemyBをインスタンス生成する*/
		//------------------------------------------------------------------
	}else if (gamemanager->GetTime_M() >= 3) {
		if (!init_plus_pos_B) {
			new Pop_EnemyB(t2k::Vector3(1520, -300, 0));
			init_plus_pos_B = true;
		}
	}
}
void map_StageB::render(const float deltatime) {
	
	//------------------------------------------------------------------
	/*描画ハンドルのブレンドを変更しない*/
	//------------------------------------------------------------------
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//------------------------------------------------------------------
	/*描画*/
	//------------------------------------------------------------------
	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0, 0, img_StageB, true);
}