#include"Anim_Player.h"
#include"GameManager.h"
#include"SceneManager.h"
#include"DxLib.h"
#include"../library/t2klib.h"

extern GameManager* gamemanager;
extern SceneManager scene;

//-------------------------------------------------------------------------------------------------------------
/*PLAYER�̃A�j���[�V�����N���X*/
//-------------------------------------------------------------------------------------------------------------
Anim_Player::Anim_Player() {
	//--------------------------------------------------------------------------------------------------
	//player�̕����A�j���[�V����
	//--------------------------------------------------------------------------------------------------
	anim_pla = new int* [frame];
	for (int i = 0; i < frame; i++) {
		anim_pla[i] = new int[frame];
	}

	//--------------------------------------------------------------------------------------------------
	//player�̎��S���̃A�j���[�V����
	//--------------------------------------------------------------------------------------------------
	animation_player_dead = new int* [frame];
	for (int i = 0; i < frame; i++) {
		animation_player_dead[i] = new int[frame];
	}
}
Anim_Player::~Anim_Player() {
	//--------------------------------------------------------------------------------------------------
	//player�̕����A�j���[�V����
	//--------------------------------------------------------------------------------------------------
	for (int i = 0; i < frame; i++) {
		delete[] anim_pla[i];
	}
	delete[] anim_pla;

	//--------------------------------------------------------------------------------------------------
	//player�̎��S���̃A�j���[�V����
	//--------------------------------------------------------------------------------------------------
	for (int i = 0; i < frame; i++) {
		delete[] animation_player_dead[i];
	}
	delete[] animation_player_dead;

}

//--------------------------------------------------------------------------------------------------
//player�̕����A�j���[�V�����֐�
//--------------------------------------------------------------------------------------------------
void Anim_Player::anim_Player_Controll(const float deltatime) {
	if (gamemanager->down_up || gamemanager->down_down ||
		gamemanager->down_right || gamemanager->down_left) {
		init_anim_pla = true;
		anim_move = 0;
		anim_frame_count++;
		if (anim_frame_count == 10) {
			anim_frame++;
			anim_frame_count = 0;
		}
		anim_frame %= anim_frame_Player;
	}
	else init_anim_pla = false;
}


//--------------------------------------------------------------------------------------------------
//player�̎��S���A�j���[�V����
//--------------------------------------------------------------------------------------------------
void Anim_Player::animation_Player_Dead(const float deltatime) {
	anim_move = 0;
	if (anim_frame < 3) {
		scene.count_move_seqGameEnd_interval = 2.0f;
		anim_frame_count++;
		if (anim_frame_count == 15) {
			anim_frame++;
			anim_frame_count = 0;
		}
		anim_frame %= 4;
	}

	//-----------------------------------------------------------------
	/*�A�j���[�V�����I����A�V�[���ړ��̃C���^�[�o���J�E���g���}�C�i�X���Ă���*/
	//-----------------------------------------------------------------
	else {
		anim_frame = 3;
		scene.count_move_seqGameEnd_interval -= deltatime;
	}
}

void Anim_Player::anim_Player_render() {
	if (!init_img_pla) {
		LoadDivGraph("graphics/Player/Player3_WALK.png", 3, 3, 1, anim_pla_W, anim_pla_H, anim_pla[0], true);
		LoadDivGraph("graphics/Player/player_dead.png", 4, 4, 1, animation_Player_Dead_W, animation_Player_Dead_H,
			animation_player_dead[0], true);
		init_img_pla = true;
	}
}