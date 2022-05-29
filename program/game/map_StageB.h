#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class map_StageB : public Base {
private:

	//bool init_plus_pos_B = false;
	bool init_count_m = false;

public:
	map_StageB(int back,int wall);

	bool init_plus_pos_B = false;

	void update(const float deltatime)override;
	void render(const float deltatime);
};