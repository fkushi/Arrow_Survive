#include"Player.h"
#include"Anim_Player.h"
#include"SONG_load.h"
#include"GameManager.h"
#include"DxLib.h"
#include "../support/Support.h"

#define PLA_DEBUG false

extern GameManager* gamemanager;
extern SONG_load	song;
Anim_Player*		anim_player;

Player::Player(t2k::Vector3 start,int speed) {
	pos = start;
	pla_speed = speed;
	gamemanager->atach->pla_enemyB_check = false;

	//--------------------------------------------------------------------------------------------------
	/*�摜�n���h���̓ǂݍ���*/
	//--------------------------------------------------------------------------------------------------
	img_player_stand = gamemanager->LoadGraphEx("graphics/Player/player_Stand.png");
	hp_green = gamemanager->LoadGraphEx("graphics/Player/hp_green.png");
	hp_red = gamemanager->LoadGraphEx("graphics/Player/hp_red.png");
	hp_cover = gamemanager->LoadGraphEx("graphics/Player/hp_gold.png");

	anim_player = new Anim_Player();
}

void Player::update(const float deltatime) {

	//--------------------------------------------------------------------------------------------------
	/*�A�j���[�V����*/
	//--------------------------------------------------------------------------------------------------
	if (!anim_player->init_animation_player_dead)anim_player->anim_Player_Controll(deltatime);
	else anim_player->animation_Player_Dead(deltatime);
	
	//--------------------------------------------------------------------------------------------------
	/*�����蔻��*/
	//--------------------------------------------------------------------------------------------------
	gamemanager->atach->Atach_Pla_Wall();
	gamemanager->atach->Atach_Pla_Pop();
	preve_pos = pos;
	
	//--------------------------------------------------------------------------------------------------
	/*����*/
	//--------------------------------------------------------------------------------------------------
	//shift�������Ă���ԓ������~�߂�flag
	if (gamemanager->down_shift) {
		triger_push_sift = true;
		anim_player->init_anim_pla = false;
	}
	//shift�����ソ�Ƃ��A������flag
	else if (gamemanager->relese_shift) {
		triger_push_sift = false;
	}

	//���L�[���������ꍇ�A���W�𓮂�����
	/*if (gamemanager->isAttach()) {

	}*/
	//�E����������pla_dir = false�A������������pla_dir = true;
	if (!anim_player->init_animation_player_dead) {
		if (gamemanager->atach->pla_up && !triger_push_sift && gamemanager->down_up)pos.y -= pla_speed;
		if (gamemanager->atach->pla_down && !triger_push_sift && gamemanager->down_down)pos.y += pla_speed;
		if (gamemanager->atach->pla_right && !triger_push_sift && gamemanager->down_right) {
			pla_dir = false;
			pos.x += pla_speed;
		}
		if (gamemanager->atach->pla_left && !triger_push_sift && gamemanager->down_left) {
			pla_dir = true;
			pos.x -= pla_speed;
		}
	}
	//--------------------------------------------------------------------------------------------------
	/*Arrow*/
	//space���������Ƃ��A���̎��̖�̑����𔭎˂���
	//--------------------------------------------------------------------------------------------------
	if (gamemanager->trigger_sapce) {
		for (auto arw_m : gamemanager->arrow_manager)arw_m->Create_Arrow(pos,pla_dir);
	}

	//--------------------------------------------------------------------------------------------------
	/*HP�Q�[�W�̂������ꍇ�AHP�����鏈��*/
	//enemy�̍U����:3,enemy�ɓ��������ꍇ�AHP���ւ�
	//--------------------------------------------------------------------------------------------------

	//HP��0�ɂȂ����玀�S�A�j���[�V�����Ɉڍs����flag
	if (hp_gezi_now <= 0 || (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_Z) &&
		gamemanager->down_shift))anim_player->init_animation_player_dead = true;

	bool check = gamemanager->atach->pla_enemyB_check;

	if (check && count_interval == 0) {
		flag_atack_EnemyB = true;
		
		//1�b�Ԃ����v���C���ɖ��G���Ԃ�����
		count_interval = 1.0f;

		//1.5�t���[���A�G�l�~�[���U������
		count_atack_Enemy_interval = 1.5f;
	}

	//--------------------------------------------------------------------------
	/*flag_atack_EnemyB=true�Ȃ�1.5�t���[�������G�l�~�[���U��
	  flag_atack_EnemyB=false�ɂȂ����ꍇ�A�v���C����1�b�Ԃ������G���Ԃ�����*/
	//--------------------------------------------------------------------------
	if (flag_atack_EnemyB) {
		count_atack_Enemy_interval--;
		if (count_atack_Enemy_interval >= 0 && hp_frame % 2 == 0 && hp_gezi_now > hp_min_num) {
			hp_gezi_now -= 30;
			t2k::debugTrace("\n�_���[�W���󂯂�:[%d]\n", 3);
		}
		else {
			flag_atack_EnemyB = false;
		}
	}
	else {
		count_interval -= deltatime;
		if (count_interval <= 0) {
			count_interval = 0;
		}
	}
}

void Player::render(const float deltatime) {
	//--------------------------------------------------------------------------------------------------
	/*HP�Q�[�W�̕`��*/
	//HP_max�l:300
	//--------------------------------------------------------------------------------------------------
	int gezi_min_x = static_cast<int>(pos.x) - (pla_w >> 1) - 5;
	int gezi_min_y = static_cast<int>(pos.y) + (pla_h >> 1) + 5;
	int gezi_max_x = static_cast<int>(pos.x) + (pla_w >> 1) + 5;
	int gezi_max_y = static_cast<int>(pos.y) + (pla_h >> 1) + 10;
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255, 255, 255);

	//-----------------------------------------------------------
	//HP_CORVER�̕`��
	//-----------------------------------------------------------
	DrawExtendGraph(gezi_min_x - 1, gezi_min_y - 2, gezi_max_x + 2, gezi_max_y + 2, hp_cover, true);
	
	//-----------------------------------------------------------
	//HP_RED�̕`��
	//-----------------------------------------------------------
	DrawExtendGraph(gezi_min_x, gezi_min_y, gezi_max_x, gezi_max_y, hp_red, true);
	
	//-----------------------------------------------------------
	//HP�̕`��
	//-----------------------------------------------------------
	DrawExtendGraph(gezi_min_x, gezi_min_y,
		gezi_min_x + (gezi_max_x - gezi_min_x) * (hp_gezi_now - hp_min_num) / (hp_max_num - hp_min_num),
		gezi_max_y, hp_green, true);

	//--------------------------------------------------------------------------------------------------
	/*�`�揈��*/
	//Player�̃A�j���[�V�����̉摜�n���h���̓ǂݍ���
	//--------------------------------------------------------------------------------------------------
	anim_player->anim_Player_render();
	
	//------------------------------------------------------------------------------
	/*������������Player�̐ԐF�ɕς�鏈��*/
	//-------------------------------------------------------------------------------
	bool atach = gamemanager->atach->pla_enemyB_check;
	if(flag_atack_EnemyB)SetDrawBright(255, 0, 0);
	else SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//-------------------------------------------------------------------------------
	/*player�̕`��*/
	//init_anim_pla = true�Ȃ�����A�j���[�V����
	//init_animation_player_dead = true�Ȃ�player���S�̃A�j���[�V����
	//-------------------------------------------------------------------------------
	if (!anim_player->init_animation_player_dead) {
		if (!anim_player->init_anim_pla) DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, 0, 
			img_player_stand, true, pla_dir);
		else DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, 0, 
			anim_player->anim_pla[anim_player->anim_move][anim_player->anim_frame], true, pla_dir);
	}
	else {
		DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, 0, 
			anim_player->animation_player_dead[anim_player->anim_move][anim_player->anim_frame], true, pla_dir);
	}
#if PLA_DEBUG
	//-------------------------------------------------------------------------------
	/*Debug*/
	//-------------------------------------------------------------------------------
	SetFontSize(20);
	DrawStringEx(100, 100, 255, "posX:%1.0f,posY:%1.0f", pos.x, pos.y);
	DrawStringEx(100, 120, 255, "grand_atach = %d", gamemanager->GetAtachWall());
	DrawStringEx(100, 140, 255, "count_atack_Enemy_interval = %.1f", count_atack_Enemy_interval);
	DrawStringEx(100, 160, 255, "count_interval = %.1f", count_interval);
#endif
}