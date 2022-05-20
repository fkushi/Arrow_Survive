#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class OnAtach_Arrow : public Base {
private:
	int arrow_type = 1;
	int atach_Arrow_speed = 0;

	t2k::Vector3 atach_Arrow_dir;
public:

	OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed,int type);

	int atach_Arrow_radius = 5;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};