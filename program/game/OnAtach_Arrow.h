#pragma once
#include"Arrow_Base.h"
#include"../library/t2klib.h"
class OnAtach_Arrow : public Arrow_Base {
private:
	

	bool sequence_arw_win = false;
	bool preve_pla_dir = false;
	t2k::Vector3 atach_Arrow_dir;
	t2k::Vector3 preve_pos;
	t2k::Vector3 preve_arw_pos;
	t2k::Vector3 center_pos;
	t2k::Vector3 center_1;
	int atach_Arrow_speed = 0;

	/*��肪��锼�a*/
	int red_radius = 13;

	/*���锼�a*/
	int light_blue_radius = 100;
	
	/*�����蔻��̓��߂���l*/
	int img_alpha = 0;

	/*light_blue_radius�̎��񔼌a*/
	float radius = 0;
public:

	OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed,bool pla_dir,int type);

	int atach_Arrow_radius = 5;

	void update_arrow(const float deltatime)override;
	void render_arrow(const float deltatime)override;
};