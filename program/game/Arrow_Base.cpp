#include"Arrow_Base.h"
#include"GameManager.h"

extern GameManager* gamemanager;

Arrow_Base::Arrow_Base() {
	gamemanager->arrow_base.emplace_back(this);
}