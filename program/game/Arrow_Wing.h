#pragma once
#include"Arrow_Base.h"
#include"../library/t2klib.h"
class Arrow_Wing : public Arrow_Base {
private:
	t2k::Vector3 blt_dir;
	bool DIR;
	float RAD;

	bool init_move_rotate = false;
	bool init_preve = false;
	bool init_arw_rad = false;
	
	float angle = 0;
	float radius = angle * 3.14f / 180.0f;
	float arw_rad = 0;
	int expand_speed = 100;
	int img_arrow = 0;

	
	t2k::Vector3 make_pos;

public:

	Arrow_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir);
	
	t2k::Vector3 preve_Center;
	bool sequence_rotate = false;
	int blt_pla_w = 36;
	int blt_pla_h = 8;

	void update_arrow(const float deltatime)override;
	void render_arrow(const float deltatime)override;
};