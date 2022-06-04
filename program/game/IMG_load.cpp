#include"IMG_load.h"
#include"GameManager.h"
#include"Create_Stage.h"
#include"DxLib.h"

extern Create_Stage c_st;
extern GameManager* gamemanager;

//-------------------------------------------------------------------------------------------------------------------------
/*すべての描画画像をまとめているクラス*/
//-------------------------------------------------------------------------------------------------------------------------

/*Sceneイメージ*/
//Title
void IMG_load::img_title() {
	if (!init_img_title) {
		title = LoadGraph("graphics/taitle.png");
		init_img_title = true;
	}
}
void IMG_load::img_end() {
	if (!init_img_end) {
		end = LoadGraph("graphics/End.jpg");
	}
}

/*Stageイメージ*/
void IMG_load::img_back() {
	if (!init_img_back) {
		if(c_st.stage_type == 0)back = LoadGraph("graphics/Back/Grass_1_sousa.png");
		if(c_st.stage_type == 1)back = LoadGraph("graphics/Back/Grass2.png");
		init_img_back = true;
	}
}
//Wallイメージ
void IMG_load::img_wall() {
	if (!init_img_wall) {
		img_wall_nomal = LoadGraph("graphics/Wall/wall2_ALL.png");
		img_wall_Bridge = LoadGraph("graphics/Wall/river2_Li.png");
		init_img_wall = true;
	}
}
//Time背景イメージ
void IMG_load::img_time_back() {
	if (!init_img_time_back) {
		time_back = LoadGraph("graphics/Timer_cover.png");
		init_img_time_back = true;
	}
}
/*Enemy_Popイメージ*/
void IMG_load::img_pop() {
	if (!init_img_pop) {
		if (c_st.stage_type == 1)pop = LoadGraph("graphics/Enemy/Pop/pop_B.png");
		init_img_pop = true;
	}
}
/*PLAYERイメージ*/
void IMG_load::img_player() {
	if (!init_img_pla) {
		LoadDivGraph("graphics/Player/Player3_WALK.png", 3, 3, 1, anim_pla_W, anim_pla_H, anim_pla[0], true);
		init_img_pla = true;
	}
}
/*Enemyイメージ*/
//Enemy_B
//保留
void IMG_load::img_enemy_B() {
	if (!init_img_enmB) {
		LoadDivGraph("graphics/Enemy/IMG/enemy_B_single.png", 3, 3, 1, anim_enm_B_Size, anim_enm_B_Size, img_enm_B[0], true);
		init_img_enmB = true;
	}
}