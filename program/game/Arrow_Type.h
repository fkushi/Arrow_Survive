#pragma once
#include"Base.h"
#include"Arrow_Base.h"
#include"../library/t2klib.h"
class Arrow_Type : public Arrow_Base {
private:
	int arrow_type_max = 4;
	int arrow_type_min = 0;
	int arrow_type_blend_add = 255;
	int img_Arrow_Type;
public:

	Arrow_Type();

	//int arrow_type = 1;

	void update_arrow(const float deltatime)override;
	void render_arrow(const float deltatime)override;
};