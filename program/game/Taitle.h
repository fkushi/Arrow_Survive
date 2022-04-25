#pragma once
class Taitle {
private:
	int img_Taitle = 0;
public:

	Taitle();
	~Taitle();

	void update(const float deltatime);
	void render(const float deltatime);
};