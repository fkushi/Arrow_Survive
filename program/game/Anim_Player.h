#pragma once
class Anim_Player {
private:
	int frame = 3;
	int anim_frame_count = 0;
	int anim_frame_Player = 3;


	bool init_img_pla = false;
	
	int anim_pla_W = 38;
	int anim_pla_H = 45;
	

public:
	Anim_Player();
	~Anim_Player();

	bool init_anim_pla = false;
	int anim_move = 0;
	int anim_frame = 0;

	/*アニメーションの描画ハンドル*/
	int** img_anim_pla = nullptr;

	void anim_Player_Controll(const float deltatime);
	void anim_Player_render(const float deltatime);
};