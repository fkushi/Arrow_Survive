#pragma once
class Anim_Player {
private:
	bool init_img_pla = false;
	const int anim_pla_W = 38;
	const int anim_pla_H = 45;
	const int animation_Player_Dead_W = 60;
	const int animation_Player_Dead_H = 45;
	int frame = 3;
	int anim_frame_count = 0;
	int anim_frame_Player = 3;

public:
	Anim_Player();
	~Anim_Player();

	bool init_anim_pla = false;
	bool init_animation_player_dead = false;
	int** anim_pla = nullptr;
	int** animation_player_dead = nullptr;
	int anim_move = 0;
	int anim_frame = 0;

	void anim_Player_Controll(const float deltatime);
	void animation_Player_Dead(const float deltatime);
	void anim_Player_render();
};