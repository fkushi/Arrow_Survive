#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class OnAtach_Arrow : public Base {
public:

	OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed);

	int atach_Arrow_speed = 0;

	int atach_Arrow_radius = 5;

	t2k::Vector3 atach_Arrow_dir;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};