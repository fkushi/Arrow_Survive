#include"OnAtach_Arrow.h"
#include"GameManager.h"

extern GameManager* gamemanager;

OnAtach_Arrow::OnAtach_Arrow(t2k::Vector3 start, t2k::Vector3 dir, int speed) {
	gamemanager->atach_arw.emplace_back(this);
}

void OnAtach_Arrow::update(const float deltatime) {

}
void OnAtach_Arrow::render(const float deltatime) {

}