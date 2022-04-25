#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class map_StageB : public Base {
public:
	map_StageB(int back,int wall);

	void update(const float deltatime)override;
	void render(const float deltatime);
};