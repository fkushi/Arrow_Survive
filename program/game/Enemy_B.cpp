#include"Enemy_B.h"
#include"Anim_Enemy_B.h"
#include"GameManager.h"
#include"DxLib.h"

Anim_Enemy_B		anim_enmB;
extern GameManager* gamemanager;

//--------------------------------------------------------------------------------------------------------------------------
/*Pop_EnemyB�ŃC���X�^���X���������Enemy�N���X*/
//--------------------------------------------------------------------------------------------------------------------------

Enemy_B::Enemy_B(t2k::Vector3 start, int speed) {
	pos = start;
	SPEED = speed;
	gamemanager->enemy_B.emplace_back(this);
}

void Enemy_B::update(const float deltatime) {
	
	//----------------------------------------------------------------
	/*pos��ۑ�*/
	//----------------------------------------------------------------
	preve_pos = pos;

	//----------------------------------------------------------------
	/*�A�j���[�V����*/
	//----------------------------------------------------------------
	anim_enmB.enemy_anim_Controll(deltatime);

	//----------------------------------------------------------------
	/*�Ǐ]*/
	//A:Enemy_B��player�Ƃ�x���W�̍�
	//B:Enemy_B��player�Ƃ�y���W�̍�
	//C:Enemy_B��player�̎Εӂ̒���
	//----------------------------------------------------------------
	float A, B, C, dx, dy;
	A = gamemanager->GetPosPlayer().x - pos.x;
	B = gamemanager->GetPosPlayer().y - pos.y;
	C = sqrt(A * A + B * B);

	dx = A / C;
	dy = B / C;

	//----------------------------------------------------------------
	/*player�ɓ���������u�Ԉꎞ�I�Ɏ~�܂�*/
	//----------------------------------------------------------------
	if (gamemanager->atach.pla_enemyB_check)init_enmB_move = false;
	else init_enmB_move = true;

	if (init_enmB_move) {
		pos.x += dx * SPEED;
		pos.y += dy * SPEED;
	}
}
void Enemy_B::render(const float deltatime) {

	//----------------------------------------------------------------
	/*EnemyB�̃A�j���[�V�����`��*/
	//----------------------------------------------------------------
	anim_enmB.enemy_render(deltatime);
	DrawRotaGraph((int)pos.x, (int)pos.y, 1.0f, 0,anim_enmB.img_enemy_B[0][anim_enmB.anim_frame], true);
}