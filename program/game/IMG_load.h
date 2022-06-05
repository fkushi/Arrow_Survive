#pragma once
class IMG_load {
private:
	/*SCENE*/
	//tatitle
	bool init_img_title = false;
	/*Player*/
	bool init_img_pla = false;
	bool init_img_hp = false;
	/*Arrow*/
	bool init_img_blt_player = false;
	/*Stage*/
	bool init_img_wall = false;
	bool init_img_time_back = false;
	/*Enemy*/
	bool init_img_enmB = false;
public:
	/*Stage*/
	bool init_img_back = false;
	bool init_img_pop = false;
	
	/*STAGE*/
	int back;
	int img_wall_nomal;
	int img_wall_Bridge;
	int time_back;

	/*PLAYER*/
	int anim_pla_W = 38;
	int anim_pla_H = 45;
	int** anim_pla = nullptr;
	
	/*Enemy*/
	//•Û—¯
	int anim_enm_B_Size = 32;
	int** anim_enm_B = nullptr;
	int** img_enm_B = nullptr;
	
	/*Stage*/
	void img_back();
	void img_wall();
	/*Enemy*/
	void img_enemy_B();
	/*Player*/
	void img_player();
};