#pragma once
class Fade {
public:
	Fade() : bright(0) {}
	~Fade() {}
	bool FadeIn(int fade_speed, int r = 255, int g = 255, int b = 255);
	bool FadeOut(int fade_speed, int r = 255, int g = 255, int b = 255);

private:
	int bright;
};