#pragma once
#include "Base.h"
#include "../library/t2klib.h"
class Bullet_Player : public Base {
private:
	t2k::Vector3 blt_dir;
	bool DIR;
	float RAD;
public:
	
	Bullet_Player(t2k::Vector3 start,t2k::Vector3 dir,float radian,int speed,bool bul_dir);

	bool init_flag = true;
	int blt_pla_w = 36;
	int blt_pla_h = 8;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};