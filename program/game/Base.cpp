#include"Base.h"
#include"GameManager.h"

extern GameManager* gamemanager;

Base::Base() {	
	gamemanager->base.emplace_back(this);
}