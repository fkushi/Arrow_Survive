#include"Anim_Player.h"
#include"IMG_load.h"
#include"../library/t2klib.h"

extern IMG_load img;

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
	if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_UP) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_DOWN) ||
		t2k::Input::isKeyDown(t2k::Input::KEYBORD_RIGHT) || t2k::Input::isKeyDown(t2k::Input::KEYBORD_LEFT)) {
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