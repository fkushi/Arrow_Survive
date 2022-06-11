#pragma once
#include "Arrow_Base.h"
#include "../library/t2klib.h"
class Bullet_Player : public Arrow_Base {
private:
	t2k::Vector3 blt_dir;
	bool DIR;
	float RAD;
	int img_arrow = 0;

public:
	
	Bullet_Player(t2k::Vector3 start,t2k::Vector3 dir,float radian,int speed,bool bul_dir);

	bool init_flag = true;
	int blt_pla_w = 36;
	int blt_pla_h = 8;

	void update_arrow(const float deltatime)override;
	void render_arrow(const float deltatime)override;
};