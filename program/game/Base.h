#pragma once
#include"../library/t2klib.h"
class Base {
public:
	Base();
	virtual ~Base() {}

	//•`‰æÀ•W
	t2k::Vector3 pos;
	t2k::Vector3 preve_pos;

	bool is_alive = true;

	int SPEED = 0;

	int stage_type = 0;
	enum {
		stage_A = 0,
		stage_B,
		stage_C,
	};

	virtual void update(const float deltatime) {}
	virtual void render(const float deltatime) {}
};