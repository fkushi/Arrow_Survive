#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Arrow_Wing : public Base {
private:
	t2k::Vector3 blt_dir;
	int blt_pla_w = 36;
	bool DIR;
	float RAD;

	bool init_move_rotate = false;
	bool init_preve = false;
	bool init_arw_rad = false;
	bool sequence_rotate = false;
	float angle = 0;
	float radius = angle * 3.14f / 180.0f;
	float arw_rad = 0;
	int expand_speed = 100;

	t2k::Vector3 preve_Center;
	t2k::Vector3 make_pos;

public:

	Arrow_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir);		

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};