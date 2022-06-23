#pragma once
#include"../library/t2klib.h"

class OnAtachEnter {
public:
	OnAtachEnter();
	//----------------------------------------
	/*壁の当たり判定*/
	//----------------------------------------
	bool pla_right = true;
	bool pla_left = true;
	bool pla_up = true;
	bool pla_down = true;

	void Atach_Pla_Wall();

	//----------------------------------------
	/*Player当たり判定*/
	//----------------------------------------
	int player_enemyB_atach = 0;
	bool pla_enemyB_check;
	bool arw_enm_check = false;
	int count_arw_wing = 0;
	
	//Enemy生成場所
	void Atach_Pla_Pop();

	//----------------------------------------
	/*Enemy当たり判定*/
	//----------------------------------------
	void Atach_Pla_Enemy();

};