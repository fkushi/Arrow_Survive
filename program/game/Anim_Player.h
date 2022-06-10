#pragma once
class Anim_Player {
private:
	int frame = 3;
	int anim_frame_count = 0;
	int anim_frame_Player = 3;
public:
	Anim_Player();
	~Anim_Player();

	bool init_anim_pla = false;
	int anim_move = 0;
	int anim_frame = 0;

	void anim_Player_Controll(const float deltatime);
};