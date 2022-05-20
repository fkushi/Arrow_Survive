#pragma once
#include"../library/t2klib.h"

class OnAtachEnter {
public:
	OnAtachEnter();

	bool pla_right = true;
	bool pla_left = true;
	bool pla_up = true;
	bool pla_down = true;
	int pla_enemyB_check;
	
	/*Player�����蔻��*/
	//��
	void Atach_Pla_Wall();
	//Enemy�����ꏊ
	void Atach_Pla_Pop();

	/*Enemy�����蔻��*/
	void Atach_Pla_Enemy();

	/*�ۗ�*/
	void Atach_Pla_Block(t2k::Vector3 pla_pos,int pla_w,int pla_h,t2k::Vector3 box_pos,int box_w,int box_h);
};