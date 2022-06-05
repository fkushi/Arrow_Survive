#pragma once
#include"Base.h"
class map_Wall : public Base{
private:

	/*�`��T�C�Y*/
	const int bridge_w = 96;
	const int bridge_h = 64;

	/*player�̕`��T�C�Y*/
	const int pla_w = 38;
	const int pla_h = 45;

	/*�`��n���h��*/
	int img_Wall_all = 0;
	int img_no_Bridge = 0;

public:
	map_Wall();

	/*player��wall���ǂ��ɓ����������̔���*/
	int atach_wal = atach_grand;
	enum {
		atach_grand = -1,
		atach_right = 0,
		atach_left,
		atach_up,
		atach_down,
		atach_corner_upR,
		atach_corner_upL,
		atach_corner_downR,
		atach_corner_downL
	};

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};