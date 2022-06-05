#pragma once
class IMG_load {
private:
	
	/*Player*/
	bool init_img_pla = false;
	
public:
	
	/*PLAYER*/
	int anim_pla_W = 38;
	int anim_pla_H = 45;
	int** anim_pla = nullptr;
	
	
	/*Player*/
	void img_player();
};