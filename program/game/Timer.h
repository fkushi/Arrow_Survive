#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Timer : public Base{
private:
	int alpha = 255;
public:
	Timer(t2k::Vector3 start);
	

	float s = 0;
	int m = 0;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};