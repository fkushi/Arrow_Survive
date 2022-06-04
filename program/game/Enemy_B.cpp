#include"Enemy_B.h"
#include"Anim_Enemy_B.h"
#include"GameManager.h"
#include"DxLib.h"

Anim_Enemy_B		anim_enmB;
extern GameManager* gamemanager;

Enemy_B::Enemy_B(t2k::Vector3 start, int speed) {
	pos = start;
	SPEED = speed;
	gamemanager->enemy_B.emplace_back(this);
}

void Enemy_B::update(const float deltatime) {
	/*posを保存*/
	preve_pos = pos;

	//----------------------------------------------------------------
	/*アニメーション*/
	//----------------------------------------------------------------
	anim_enmB.enemy_anim_Controll(deltatime);

	//----------------------------------------------------------------
	/*追従*/
	//----------------------------------------------------------------
	float A, B, C, dx, dy;
	A = gamemanager->GetPosPlayer().x - pos.x;
	B = gamemanager->GetPosPlayer().y - pos.y;
	C = sqrt(A * A + B * B);

	dx = A / C;
	dy = B / C;

	if (gamemanager->atach.pla_enemyB_check != 0)init_enmB_move = false;
	else init_enmB_move = true;

	if (init_enmB_move) {
		pos.x += dx * SPEED;
		pos.y += dy * SPEED;
	}
}
void Enemy_B::render(const float deltatime) {
	anim_enmB.enemy_render(deltatime);
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0,anim_enmB.img_enemy_B[0][anim_enmB.anim_frame], true);
}