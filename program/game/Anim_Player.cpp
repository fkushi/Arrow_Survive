#include"Anim_Player.h"
#include"IMG_load.h"
#include"GameManager.h"
#include"../library/t2klib.h"

extern IMG_load img;
extern GameManager* gamemanager;

/*PLAYERのアニメーションクラス*/
Anim_Player::Anim_Player() {
	img.anim_pla = new int* [frame];
	for (int i = 0; i < frame; i++) {
		img.anim_pla[i] = new int[frame];
	}
}
Anim_Player::~Anim_Player() {
	for (int i = 0; i < frame; i++) {
		delete[] img.anim_pla[i];
	}
	delete[] img.anim_pla;
}

void Anim_Player::anim_Player_Controll(const float deltatime) {
	if (gamemanager->down_up || gamemanager->down_down ||
		gamemanager->down_right || gamemanager->down_left) {
		init_anim_pla = true;
		anim_move = 0;
		anim_frame_count++;
		if (anim_frame_count == 10) {
			anim_frame++;
			anim_frame_count = 0;
		}
		anim_frame %= anim_frame_Player;
	}
	else init_anim_pla = false;
}