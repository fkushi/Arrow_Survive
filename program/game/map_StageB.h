#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class map_StageB : public Base {
private:

	/*�`��n���h��*/
	int img_StageB = 0;

public:
	map_StageB(int back,int wall);

	/*���ԂɂȂ�����Pop_EnemyB���C���X�^���X�����ł���flag*/
	bool init_plus_pos_B = false;

	void update(const float deltatime)override;
	void render(const float deltatime);
};