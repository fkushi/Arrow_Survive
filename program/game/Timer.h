#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Timer : public Base{
private:
	/*描画ハンドルのブレンドをするalpha値*/
	int alpha = 255;

	/*描画ハンドル*/
	int img_timer = 0;
public:
	Timer(t2k::Vector3 start);

	/*sは秒をカウントし、mは分をカウントする*/
	float s = 0;
	int m = 0;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};