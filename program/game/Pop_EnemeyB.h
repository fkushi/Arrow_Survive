#pragma once
#include"Base.h"
#include"../library/t2klib.h"

class Pop_EnemyB : public Base {
private:
	bool init_count_time_cretate = false;
	bool init_count_enB_Create = false;
	float count_enmB_Create = 0;
	int speed = 0;
	int count_create_enmB = 0;
public:
	Pop_EnemyB(t2k::Vector3 start);

	int size_w = 35;
	int size_h = 32;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};