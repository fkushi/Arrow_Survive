#include"SceneManager.h"
#include"Taitle.h"
#include"End.h"
#include"../library/t2klib.h"
#include"SONG_load.h"
#include"Create_Stage.h"
#include"GameManager.h"
#include"Fade.h"
#include"Fade_Manager.h"
#include"Dxlib.h"

extern GameManager* gamemanager;
extern Create_Stage	c_st;
extern Fade_Manager fade_manager;
SONG_load		song;
Taitle			taitle;
GameEnd			end;
//Fade fade;


//-------------------------------------------------------------------------------------------------------------------
/*�V�[������*/
//-------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
/*�^�C�g��*/
//----------------------------------------------------------------------------------------
bool SceneManager::seqTitle(const float deltatime) {

	if (sequence_.isStart()) {
		//------------------------------------------------------------------
		/*����_load*/
		//------------------------------------------------------------------
		song.init_bgm = false;
		song.SONG_bgm();
		
		//------------------------------------------------------------------
		/*���ʒ���*/
		//------------------------------------------------------------------
		ChangeVolumeSoundMem(100, song.bgm_taitle);

		//------------------------------------------------------------------
		/*��_PLAY*/
		//------------------------------------------------------------------
		PlaySoundMem(song.bgm_taitle, DX_PLAYTYPE_LOOP, false);

		fade_manager.init_fade = false;
	}

	//------------------------------------------------------------------
	/*�w�i�`��*/
	//------------------------------------------------------------------
	taitle.render(deltatime);

	//------------------------------------------------------------------
	/*ENTER�������玟�̃v���C�X�e�[�W_�V�[����*/
	//------------------------------------------------------------------
	if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_SPACE))fade_manager.FadeOut(5);
	else if (t2k::Input::isKeyDown(t2k::Input::KEYBORD_B))fade_manager.FadeIn(5);

	//------------------------------------------------------------------
	//�t�F�[�h���� & �V�[���ړ�
	// Enter����������t�F�[�h�A�E�g����A�t�F�[�h�A�E�g���I������V�[���ړ�
	//------------------------------------------------------------------
	fade_manager.Fade();
	if (gamemanager->trigger_enter) {
		fade_manager.init_fade = true;
	}

	if(fade_manager.FadeOut(0))sequence_.change(&SceneManager::seqStage);

	return true;
}

//----------------------------------------------------------------------------------------
/*�v���C�X�e�[�W*/
//----------------------------------------------------------------------------------------
bool SceneManager::seqStage(const float deltatime) {

	if (sequence_.isStart()) {

		fade_manager.init_fade = false;

		//------------------------------------------------------------------
		/*�ŏ��̃X�e�[�W*/
		//------------------------------------------------------------------
		new map_StageA();
		new map_Wall();
		new Timer(t2k::Vector3(450, 90, 0));
		gamemanager->atach = new OnAtachEnter();
		gamemanager->player = new Player(t2k::Vector3(1024 >> 1, 768 >> 1, 0), 5);
		
		new Arrow_Manager();

		/*Player�̎��S���̃V�[���ړ��C���^�[�o��������*/
		count_move_seqGameEnd_interval = 1.0f;

		//------------------------------------------------------------------
		/*������load*/
		//------------------------------------------------------------------
		song.init_bgm = false;
		song.init_se = false;
		song.SONG_SE_Arrow();
		
		init_st1_sound = false;
	}

	//------------------------------------------------------------------
	//�t�F�[�h����
	//------------------------------------------------------------------
	fade_manager.Fade();

	if (gamemanager->GetCreSt_stage_type() == 1) {
		//------------------------------------------------------------------
		/*��������*/
		//------------------------------------------------------------------
		if (!init_st1_sound) {
			//------------------------------------------------------------------
			//����_DELETE
			//------------------------------------------------------------------
			DeleteSoundMem(song.bgm_taitle);

			//------------------------------------------------------------------
			//����_PLAY
			//------------------------------------------------------------------
			PlaySoundMem(song.bgm_stage, DX_PLAYTYPE_LOOP,false);

			init_st1_sound = true;
		}
	}

	//----------------------------------------------------------------------------------------
	/*player�ړ����̃X�e�[�W����*/
	//----------------------------------------------------------------------------------------
	c_st.create_Stage();

	//----------------------------------------------------------------------------------------
	/*GameEnd*/
	//----------------------------------------------------------------------------------------
	if (count_move_seqGameEnd_interval < 0 || (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_Z) &&
		gamemanager->down_shift)){

		//------------------------------------------------------------------
		/*�������ԋL�^*/
		//------------------------------------------------------------------
		preve_m = gamemanager->GetTime_M();
		preve_s = gamemanager->GetTime_S();

		//------------------------------------------------------------------
		/*DELETE����*/
		//------------------------------------------------------------------
		Del_END();
		gamemanager->eraceCheck();
		gamemanager->eraceCheck_Base();

		//------------------------------------------------------------------
		/*STAGETYPE��������*/
		//------------------------------------------------------------------
		c_st.pla_next_pop = 0;

		//------------------------------------------------------------------
		/*���̃V�[���Ɉړ�*/
		//------------------------------------------------------------------
		sequence_.change(&SceneManager::seqGameEnd);
	}

	return true;
}
/*�Q�[���I��*/
bool SceneManager::seqGameEnd(const float deltatime) {

	if (sequence_.isStart()) {

		//------------------------------------------------------------------
		/*��������*/
		//load������������������
		//------------------------------------------------------------------
		DeleteSoundMem(song.bgm_stage);
		DeleteSoundMem(song.bgm_taitle);
		DeleteSoundMem(song.se_atach);
		DeleteSoundMem(song.se_shot);

		//------------------------------------------------------------------
		/*��_PLAY*/
		//------------------------------------------------------------------
		song.init_bgm = false;
		PlaySoundMem(song.bgm_end, DX_PLAYTYPE_LOOP, true);
	}

	//------------------------------------------------------------------
	/*�w�i�`��*/
	//------------------------------------------------------------------
	end.render(deltatime);
	
	//------------------------------------------------------------------
	/*ENTER���������玟�̃V�[����*/
	//------------------------------------------------------------------
	if (gamemanager->trigger_enter) {
		DeleteSoundMem(song.bgm_end);
		sequence_.change(&SceneManager::seqTitle);
	}

	return true;
}

//----------------------------------------------------------------------------------------
/*�S�f���[�g*/
//----------------------------------------------------------------------------------------
void SceneManager::Del_END() {
	//------------------------------------------------------------------
	/*player*/
	//------------------------------------------------------------------
	gamemanager->player = nullptr;

	//------------------------------------------------------------------
	/*stage_type������*/
	//------------------------------------------------------------------
	c_st.stage_type = 0;

	//------------------------------------------------------------------
	/*arrow*/
	//------------------------------------------------------------------
	for (auto bp : gamemanager->bullet_player)bp->arrow_alive = false;
	for (auto arw_w : gamemanager->arrow_wing)arw_w->arrow_alive = false;
	for (auto ataw : gamemanager->atach_arrow)ataw->arrow_alive = false;
	for (auto arw_t : gamemanager->arrow_type)arw_t->arrow_alive = false;
	for (auto arw_b : gamemanager->arrow_base)arw_b->arrow_alive = false;
	for (auto arw_m : gamemanager->arrow_manager)arw_m->is_alive = false;

	//------------------------------------------------------------------
	/*stage*/
	//------------------------------------------------------------------
	for (auto st_a : gamemanager->map_stageA)st_a->is_alive = false;
	for (auto st_b : gamemanager->map_stageB)st_b->is_alive = false;
	for (auto p_b : gamemanager->pop_enemyB)p_b->is_alive = false;

	//------------------------------------------------------------------
	/*enemy*/
	//------------------------------------------------------------------
	for (auto eb : gamemanager->enemy_B)eb->is_alive = false;

	//------------------------------------------------------------------
	/*base*/
	//------------------------------------------------------------------
	for (auto ba : gamemanager->base)ba->is_alive = false;
}