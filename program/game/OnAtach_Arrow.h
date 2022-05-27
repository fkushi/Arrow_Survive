#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class OnAtach_Arrow : public Base {
private:
	int atach_Arrow_speed = 0;

	bool sequence_arw_win = false;
	bool preve_pla_dir = false;
	t2k::Vector3 preve_pos;
	t2k::Vector3 preve_arw_pos;
	t2k::Vector3 center_pos;
	t2k::Vector3 center_1;
	int red_radius = 13;
	int light_blue_radius = 100;
	float angle = 0;
	float radius = 0;

	t2k::Vector3 atach_Arrow_dir;
public:

	OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed,bool pla_dir,int type);

	int arrow_type = 1;
	int atach_Arrow_radius = 5;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};