#include"Arrow_Wing.h"
#include"GameManager.h"

extern GameManager* gamemanager;

Arrow_Wing::Arrow_Wing(t2k::Vector3 start) {
	gamemanager->arw_win.emplace_back(this);
}

void Arrow_Wing::update(const float deltatime) {

}
void Arrow_Wing::render(const float deltatime) {

}