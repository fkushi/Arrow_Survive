#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Timer : public Base{
private:
	/*�`��n���h���̃u�����h������alpha�l*/
	int alpha = 255;

	/*�`��n���h��*/
	int img_timer = 0;
public:
	Timer(t2k::Vector3 start);

	/*s�͕b���J�E���g���Am�͕����J�E���g����*/
	float s = 0;
	int m = 0;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};