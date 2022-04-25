#pragma once
#include"Base.h"
class Anim_Enemy_B{
private:
	int frame_row = 3;
	int anim_frame_count = 0;
public:
	Anim_Enemy_B();
	~Anim_Enemy_B();

	int enemy_size = 32;

	int enemy_type = 0;

	bool init_img_enemy = false;
	int** img_enemy_B = nullptr;
	int anim_move = 0;
	int anim_frame = 0;
	
	void enemy_anim_Controll(float deltatime);
	void enemy_render(float deltatime);

};