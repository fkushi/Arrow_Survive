#pragma once
#include"Base.h"
class map_Wall : public Base{
public:
	map_Wall();

	int bridge_w = 96;
	int bridge_h = 64;
	int pla_w = 38;
	int pla_h = 45;

	int atach_wal = atach_grand;
	enum {
		atach_grand = -1,
		atach_right = 0,
		atach_left,
		atach_up,
		atach_down,
		atach_corner_upR,
		atach_corner_upL,
		atach_corner_downR,
		atach_corner_downL
	};

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};