#include"Enemy_B.h"
#include"Anim_Enemy_B.h"
#include"IMG_load.h"
#include"GameManager.h"
#include"DxLib.h"
#define DEBUG_ENM_B 1

Anim_Enemy_B		anim_enmB;
extern IMG_load		img;
extern GameManager* gamemanager;

Enemy_B::Enemy_B(t2k::Vector3 start, int speed) {
	pos = start;
	SPEED = speed;
	gamemanager->enm_B.emplace_back(this);
}

void Enemy_B::update(const float deltatime) {
	/*pos‚ð•Û‘¶*/
	preve_pos = pos;

	//----------------------------------------------------------------
	/*ƒAƒjƒ[ƒVƒ‡ƒ“*/
	//----------------------------------------------------------------
	anim_enmB.enemy_anim_Controll(deltatime);

	#if DEBUG_ENM_B
	//----------------------------------------------------------------
	/*’Ç]*/
	//----------------------------------------------------------------
	float A, B, C, dx, dy;
	A = gamemanager->GetPosPlayer().x - pos.x;
	B = gamemanager->GetPosPlayer().y - pos.y;
	C = sqrt(A * A + B * B);

	dx = A / C;
	dy = B / C;
#if 1
	if (gamemanager->atach.pla_enemyB_check != 0)init_enmB_move = false;
	else init_enmB_move = true;

	if (init_enmB_move) {
		pos.x += dx * SPEED;
		pos.y += dy * SPEED;
	}
#endif
	/*ŽÀ‘•—\’è*/
	/*int check = gamemanager->atach.pla_enemyB_check;
	if (check != 0)init_enmB_move = false;
	else init_enmB_move = true;

	if (check == 1 && t2k::Input::isKeyDown(t2k::Input::KEYBORD_LEFT))pos.x += gamemanager->pla->pla_speed;

	if (init_enmB_move) {
		pos.x += dx * SPEED;
		pos.y += dy * SPEED;
	}*/
	
	//if(check == 1 && t2k::Input::isKeyDown(t2k::Input::KEYBORD_LEFT))

	
#endif
}
void Enemy_B::render(const float deltatime) {
	anim_enmB.enemy_render(deltatime);
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0,anim_enmB.img_enemy_B[0][anim_enmB.anim_frame], true);
}