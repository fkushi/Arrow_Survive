#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Arrow_Type : public Base {
private:
	int arrow_type_max = 4;
	int arrow_type_min = 0;
	int arrow_type_blend_add = 255;
	int img_Arrow_Type;
public:

	Arrow_Type();

	int arrow_type = 1;

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};