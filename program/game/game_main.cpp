#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "game_main.h"
#include <time.h>
#include <list>
#include <map>
#include <algorithm>
#include"GameManager.h"

bool init = false;
GameManager* gamemanager;

void gameMain(float deltatime) {

	//�摜��
	if (!init) {
		gamemanager = new GameManager();
		gamemanager->initialize();
		init = true;
	}

	gamemanager->update(deltatime);
	gamemanager->render(deltatime);

}

