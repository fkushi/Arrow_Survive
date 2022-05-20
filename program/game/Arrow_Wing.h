#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Arrow_Wing : public Base {
private:
	t2k::Vector3 blt_dir;
	int blt_pla_w = 36;
	bool DIR;
	float RAD;
public:
	Arrow_Wing(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir);

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};