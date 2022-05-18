#include"OnAtach_Arrow.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;

OnAtach_Arrow::OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed) {
	pos = start;
	atach_Arrow_dir = dir;
	atach_Arrow_speed = speed;
	gamemanager->atach_arw.emplace_back(this);
}

void OnAtach_Arrow::update(const float deltatime) {
	pos.x += atach_Arrow_dir.x * atach_Arrow_speed;
	pos.y += atach_Arrow_dir.y * atach_Arrow_speed;
}
void OnAtach_Arrow::render(const float deltatime) {
	int p_x1 = (int)pos.x - (atach_Arrow_sizeW >> 1);
	int p_y1 = (int)pos.y - (atach_Arrow_sizeH >> 1);
	int p_x2 = (int)pos.x + (atach_Arrow_sizeW >> 1);
	int p_y2 = (int)pos.y + (atach_Arrow_sizeH >> 1);
	//SetDrawBlendMode(DX_BLENDMODE_SUB, 0);
	DrawBox(p_x1, p_y1, p_x2, p_y2, GetColor(0, 255, 0), false);
}