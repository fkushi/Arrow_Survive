#pragma once
#include"../library/t2klib.h"

class OnAtachEnter {
public:
	OnAtachEnter();
	//----------------------------------------
	/*�ǂ̓����蔻��*/
	//----------------------------------------
	bool pla_right = true;
	bool pla_left = true;
	bool pla_up = true;
	bool pla_down = true;

	void Atach_Pla_Wall();

	//----------------------------------------
	/*Player�����蔻��*/
	//----------------------------------------
	int pla_enemyB_check;
	bool arw_enm_check = false;
	int count_arw_wing = 0;
	
	//Enemy�����ꏊ
	void Atach_Pla_Pop();

	//----------------------------------------
	/*Enemy�����蔻��*/
	//----------------------------------------
	void Atach_Pla_Enemy();

};