#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Player : public Base {
private:
	
public:

	t2k::Vector3 preve_pos;
	bool pla_dir = false;
	int pla_speed = 0;
	int pla_w = 38;
	int pla_h = 45;

	/*HP*/
	int hp_frame = 0;
	int gezi_min_num = 0;
	int gezi_max_num = 300;
	int gezi_now_num = 300;

	Player(t2k::Vector3 start,int speed);

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};