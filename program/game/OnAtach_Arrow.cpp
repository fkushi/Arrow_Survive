#include"OnAtach_Arrow.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;

OnAtach_Arrow::OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed, bool pla_dir,int type) {
	pos = start;
	preve_pos = start;
	atach_Arrow_dir = dir;
	atach_Arrow_speed = speed;
	arrow_type = type;
	//---------------------------------------------------------
	/*’lŽQÆ*/
	preve_pla_dir = pla_dir;
	//sequence_arw_win = false;
	//---------------------------------------------------------
	gamemanager->atach_arw.emplace_back(this);
}

void OnAtach_Arrow::update(const float deltatime) {
	/*Arrow*/
	if (arrow_type == 1) {
		pos += atach_Arrow_dir * (float)atach_Arrow_speed;
		if (pos.x < 0 || pos.x > 1024 || pos.y < 0 || pos.y > 768) is_alive = false;
	}
	/*Arrow_Wing*/
#if true
	if (arrow_type == 2) {
		float add_x = cos(radius + 1.57f) * red_radius;
		float add_y = sin(radius + 1.57f) * red_radius;
		float add_center_x = cos(radius) * light_blue_radius;
		float add_center_y = sin(radius) * light_blue_radius;

		if ((!preve_pla_dir && preve_pos.x + 200 <= pos.x) || (preve_pla_dir && preve_pos.x - 200 >= pos.x)) {
			sequence_arw_win = true;
		}

		if(!sequence_arw_win)pos.x += atach_Arrow_dir.x * atach_Arrow_speed;
		/*Œ´ˆö*/
		else {
			
			light_blue_radius++;
			
			for (auto arw_w : gamemanager->arw_win) {
				t2k::Vector3 center_1 = arw_w->preve_Center;
				if (!preve_pla_dir) {
					center_pos.x = center_1.x + add_center_x;
					center_pos.y = center_1.y + add_center_y;
					pos.x = center_pos.x + add_x;
					pos.y = center_pos.y + add_y;
				}
				else {
					center_pos.x = center_1.x - add_center_x;
					center_pos.y = center_1.y - add_center_y;
					pos.x = center_pos.x - add_x;
					pos.y = center_pos.y - add_y;
				}
			}
			
			radius += 0.05f;
		
		}

		if (pos.x < -150 || pos.x > 1124 || pos.y < -100 || pos.y > 1000) {
			sequence_arw_win = false;
			is_alive = false;
		}

	}
#endif
}
void OnAtach_Arrow::render(const float deltatime) {
	
	DrawCircle((int)pos.x, (int)pos.y, atach_Arrow_radius, GetColor(0, 0, 255), false);

}