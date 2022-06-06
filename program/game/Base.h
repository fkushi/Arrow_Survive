#pragma once
#include"../library/t2klib.h"
class Base {
public:
	Base();
	virtual ~Base() {}

	//ï`âÊç¿ïW
	t2k::Vector3 pos;
	t2k::Vector3 preve_pos;

	bool is_alive = true;

	int SPEED = 0;

	virtual void update(const float deltatime) {}
	virtual void render(const float deltatime) {}
};