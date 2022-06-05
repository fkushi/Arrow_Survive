#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class map_StageB : public Base {
private:

	/*描画ハンドル*/
	int img_StageB = 0;

public:
	map_StageB(int back,int wall);

	/*時間になったらPop_EnemyBをインスタンス生成できるflag*/
	bool init_plus_pos_B = false;

	void update(const float deltatime)override;
	void render(const float deltatime);
};