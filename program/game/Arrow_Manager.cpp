#include"Arrow_Manager.h"
#include"GameManager.h"

extern GameManager* gamemanager;

Arrow_Manager::Arrow_Manager() {
	gamemanager->arrow_manager.emplace_back(this);
}
