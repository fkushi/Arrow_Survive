#include"IMG_load.h"
#include"GameManager.h"
#include"Create_Stage.h"
#include"DxLib.h"

extern Create_Stage c_st;
extern GameManager* gamemanager;

//-------------------------------------------------------------------------------------------------------------------------
/*すべての描画画像をまとめているクラス*/
//-------------------------------------------------------------------------------------------------------------------------

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