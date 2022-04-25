#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class map_StageA : public Base {
private:
	int img_stageA = 0;
public:

	map_StageA();

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};