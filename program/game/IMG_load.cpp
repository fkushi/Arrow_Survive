#include"IMG_load.h"
#include"GameManager.h"
#include"Create_Stage.h"
#include"DxLib.h"

extern Create_Stage c_st;
extern GameManager* gamemanager;

/*Scene�C���[�W*/
//Title
void IMG_load::img_title() {
	if (!init_img_title) {
		title = LoadGraph("graphics/taitle.jpg");
		init_img_title = true;
	}
}
void IMG_load::img_end() {
	if (!init_img_end) {
		end = LoadGraph("graphics/End.jpg");
	}
}

/*Stage�C���[�W*/
void IMG_load::img_back() {
	if (!init_img_back) {
		if(c_st.stage_type == 0)back = LoadGraph("graphics/Back/Grass1.png");
		if(c_st.stage_type == 1)back = LoadGraph("graphics/Back/Grass2.png");
		init_img_back = true;
	}
}
//Wall�C���[�W
void IMG_load::img_wall() {
	if (!init_img_wall) {
		img_wall_nomal = LoadGraph("graphics/Wall/wall2_ALL.png");
		img_wall_Bridge = LoadGraph("graphics/Wall/river2_Li.png");
		init_img_wall = true;
	}
}
//Time�w�i�C���[�W
void IMG_load::img_time_back() {
	if (!init_img_time_back) {
		time_back = LoadGraph("graphics/Timer_cover.png");
		init_img_time_back = true;
	}
}
/*Enemy_Pop�C���[�W*/
void IMG_load::img_pop() {
	if (!init_img_pop) {
		if (c_st.stage_type == 1)pop = LoadGraph("graphics/Enemy/Pop/pop_B.png");
		init_img_pop = true;
	}
}
/*PLAYER�C���[�W*/
void IMG_load::img_player() {
	if (!init_img_pla) {
		img_pla = LoadGraph("graphics/Player/player_Stand.png");
		LoadDivGraph("graphics/Player/Player3_WALK.png", 3, 3, 1, anim_pla_W, anim_pla_H, anim_pla[0], true);
		init_img_pla = true;
	}
}
void IMG_load::img_blt_player() {
	if (!init_img_blt_player) {
		img_blt_Player = LoadGraph("graphics/Player/Arrow.png");
		init_img_blt_player = true;
	}
}
void IMG_load::img_hp() {
	if (!init_img_hp) {
		hp_green = LoadGraph("graphics/Player/hp_green.png");
		hp_red = LoadGraph("graphics/Player/hp_red.png");
		hp_cover = LoadGraph("graphics/Player/hp_gold.png");
		init_img_hp = true;
	}
}
/*Enemy�C���[�W*/
//Enemy_B
//�ۗ�
void IMG_load::img_enemy_B() {
	if (!init_img_enmB) {
		LoadDivGraph("graphics/Enemy/IMG/enemy_B_single.png", 3, 3, 1, anim_enm_B_Size, anim_enm_B_Size, img_enm_B[0], true);
		init_img_enmB = true;
	}
}