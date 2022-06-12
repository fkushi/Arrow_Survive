#pragma once
#include"../library/t2klib.h"

class OnAtachEnter {
public:
	OnAtachEnter();
	//----------------------------------------
	/*•Ç‚Ì“–‚½‚è”»’è*/
	//----------------------------------------
	bool pla_right = true;
	bool pla_left = true;
	bool pla_up = true;
	bool pla_down = true;

	void Atach_Pla_Wall();

	//----------------------------------------
	/*Player“–‚½‚è”»’è*/
	//----------------------------------------
	int pla_enemyB_check;
	bool arw_enm_check = false;
	int count_arw_wing = 0;
	
	//Enemy¶¬êŠ
	void Atach_Pla_Pop();

	//----------------------------------------
	/*Enemy“–‚½‚è”»’è*/
	//----------------------------------------
	void Atach_Pla_Enemy();

};