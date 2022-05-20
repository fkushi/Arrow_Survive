#pragma once
class IMG_load {
private:
	/*SCENE*/
	//tatitle
	bool init_img_title = false;
	//End
	bool init_img_end = false;
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
	/*SCENE*/
	//taitle
	int title;
	int end;

	/*Stage*/
	bool init_img_back = false;
	bool init_img_pop = false;
	
	/*STAGE*/
	int pop;
	int back;
	int img_wall_nomal;
	int img_wall_Bridge;
	int time_back;

	/*PLAYER*/
	int img_pla;
	int anim_pla_W = 38;
	int anim_pla_H = 45;
	int** anim_pla = nullptr;
	//HP
	int hp_red, hp_green,hp_cover;

	/*Arrow*/
	//type
	bool init_img_arw_type = false;
	int img_arrow_type;
	enum {
		arrow = 1, wing, fire
	};
	//Arrow
	int img_blt_Player;

	/*Enemy*/
	//•Û—¯
	int anim_enm_B_Size = 32;
	int** anim_enm_B = nullptr;
	int** img_enm_B = nullptr;
	
	/*SCENE*/
	//taitle
	void img_title();
	//end
	void img_end();
	/*Stage*/
	void img_back();
	void img_wall();
	void img_time_back();
	/*Enemy*/
	void img_pop();
	void img_enemy_B();
	/*Player*/
	void img_player();
	void img_hp();
	/*Arrow*/
	void img_blt_player();
	void img_arw_type();
	
};