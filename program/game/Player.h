#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Player : public Base {
private:

	int pla_speed = 0;

	/*HP*/
	bool flag_atack_EnemyB = false;
	float count_interval = 0;
	float count_atack_Enemy_interval = 0;
	int hp_frame = 0;
	int hp_min_num = 0;
	int hp_max_num = 300;

	/*‰æ‘œ‚Ìƒ[ƒh*/
	int img_player_stand = 0;
	int hp_red, hp_green, hp_cover;
	
public:

	t2k::Vector3 preve_pos;
	bool pla_dir = false;
	bool triger_push_sift = false;
	
	int pla_w = 38;
	int pla_h = 45;

	int gh = 0;

	/*HP*/
	int gezi_now_num = 300;

	Player(t2k::Vector3 start,int speed);

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};