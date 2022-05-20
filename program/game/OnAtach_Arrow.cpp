#include"OnAtach_Arrow.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;

OnAtach_Arrow::OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed,int type) {
	pos = start;
	atach_Arrow_dir = dir;
	atach_Arrow_speed = speed;
	arrow_type = type;
	gamemanager->atach_arw.emplace_back(this);
}

void OnAtach_Arrow::update(const float deltatime) {
	if (arrow_type == 1) {
		pos.x += atach_Arrow_dir.x * atach_Arrow_speed;
		pos.y += atach_Arrow_dir.y * atach_Arrow_speed;
	}
	
}
void OnAtach_Arrow::render(const float deltatime) {
	
	DrawCircle((int)pos.x, (int)pos.y, atach_Arrow_radius, GetColor(0, 255, 0), false);

}