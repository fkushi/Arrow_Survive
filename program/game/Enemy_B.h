#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Enemy_B : public Base {
private:
	int SPEED;
	int touch = 1;
public:
	bool init_enmB_move = true;
	int enm_B_SIZE = 32;

	Enemy_B(t2k::Vector3 start,int speed);

	void update(const float deltatime)override;
	void render(const float detlatime)override;
};