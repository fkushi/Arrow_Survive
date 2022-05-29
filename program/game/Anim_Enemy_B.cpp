#include"Anim_Enemy_B.h"
#include"DxLib.h"

/*Enemy_Bのアニメーションクラス*/
Anim_Enemy_B::Anim_Enemy_B() {
	img_enemy_B = new int* [frame_row];
	for (int i = 0; i < frame_row; ++i) {
		img_enemy_B[i] = new int[frame_row];
	}
}
Anim_Enemy_B::~Anim_Enemy_B() {
	for (int i = 0; i < frame_row; i++) {
		delete[] img_enemy_B[i];
	}
	delete[] img_enemy_B;
}

void Anim_Enemy_B::enemy_anim_Controll(float deltatime) {
	anim_move = 0;
	anim_frame_count++;
	if (anim_frame_count == 20) {
		anim_frame++;
		anim_frame_count = 0;
	}
	anim_frame %= frame_row;

}
void Anim_Enemy_B::enemy_render(float deltatime) {
	if (!init_img_enemy) {
		LoadDivGraph("graphics/Enemy/IMG/enemy_B_single.png", 3, 3, 1, enemy_size, enemy_size, img_enemy_B[0], true);
		init_img_enemy = true;
	}
}