#pragma once
#include"Base.h"
class Pop_EnemyB : public Base {
private:
	float count_enmB_Create = 0;
public:
	Pop_EnemyB();

	int size_w = 35;
	int size_h = 32;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};