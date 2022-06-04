#pragma once
#include"Base.h"
#include"../library/t2klib.h"

//--------------------------------------------------------------------------------------------------------------------------
/*Enemy_Bを生成する場所のクラス*/
//--------------------------------------------------------------------------------------------------------------------------
class Pop_EnemyB : public Base {
private:
	bool init_count_time_cretate = false;
	bool init_count_enB_Create = false;

	//エネミーの生成間隔の変数
	float count_enmB_Create = 0;

	//Enemy_Bのスピード
	int speed = 0;

	//描画ハンドル
	int img_Pop_enemyB = 0;
	int count_create_enmB = 1;
public:

	Pop_EnemyB(t2k::Vector3 start);

	//描画ハンドルのサイズ
	int size_w = 35;
	int size_h = 32;

	int add_speed = 2;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};