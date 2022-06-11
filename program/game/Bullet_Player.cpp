#include"Bullet_Player.h"
#include"GameManager.h"
#include"DxLib.h"

extern GameManager* gamemanager;

//--------------------------------------------------------------------------------------------------------------------------
/*Arrow�̃N���X*/
//--------------------------------------------------------------------------------------------------------------------------
Bullet_Player::Bullet_Player(t2k::Vector3 start, t2k::Vector3 dir, float radian, int speed, bool pla_dir) {
	pos = start;
	blt_dir = dir;
	RAD = (radian * 3.14f) / 180;
	SPEED = speed;
	DIR = pla_dir;

	//-----------------------------------------------------------------
	/*���̓����蔻��̐V�K�C���X�^���X����*/
	//-----------------------------------------------------------------
	if (!pla_dir) {
		new OnAtach_Arrow(t2k::Vector3(start.x + (blt_pla_w >> 1) - 5, start.y, 0), dir, speed, pla_dir, 1);
	}
	else new OnAtach_Arrow(t2k::Vector3(start.x - (blt_pla_w >> 1) + 5, start.y, 0), dir, speed, pla_dir, 1);

	//-----------------------------------------------------------------
	/*�摜�n���h���̓ǂݍ���*/
	//-----------------------------------------------------------------
	img_arrow = gamemanager->LoadGraphEx("graphics/Player/Arrow.png");

	gamemanager->bullet_player.emplace_back(this);
}

void Bullet_Player::update_arrow(const float deltatime) {
	//-----------------------------------------------------------------
	/*�X�����ɐi�ޏ���*/
	//-----------------------------------------------------------------
	pos += (float)SPEED * blt_dir;

	//-----------------------------------------------------------------
	/*��ʊO�ɂł���DELETE*/
	//-----------------------------------------------------------------
	if (pos.x > 1024 >> 1 && gamemanager->down_shift)arrow_alive = false;
	if (pos.x < 0 || pos.x > 1024 || pos.y < 0 || pos.y > 768) arrow_alive = false;
} 
void Bullet_Player::render_arrow(const float deltatime) {
	
	//-----------------------------------------------------------------
	/*�摜�̃u�����h������ύX�����Ȃ��悤�ɂ���*/
	//-----------------------------------------------------------------
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(255, 255, 255);

	//-----------------------------------------------------------------
	/*�`��*/
	//-----------------------------------------------------------------
	DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, RAD, img_arrow, true, DIR);
}