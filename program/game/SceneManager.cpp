#include"SceneManager.h"
#include"Taitle.h"
#include"End.h"
#include"../library/t2klib.h"
#include"IMG_load.h"
#include"SONG_load.h"
#include"Create_Stage.h"
#include"GameManager.h"
#include"Dxlib.h"

extern GameManager* gamemanager;
extern IMG_load img;
SONG_load		song;
Taitle			taitle;
GameEnd			end;
Create_Stage	c_st;

//----------------------------------------------------------------------------------------
/*�V�[������*/
//----------------------------------------------------------------------------------------
/*�^�C�g��*/
bool SceneManager::seqTitle(const float deltatime) {

	if (sequence_.isStart()) {
		//����_load
		song.init_bgm = false;
		song.SONG_bgm();
		
		//���ʒ���
		ChangeVolumeSoundMem(100, song.bgm_taitle);

		//��_PLAY
		PlaySoundMem(song.bgm_taitle, DX_PLAYTYPE_LOOP, false);
	}
	//�w�i�`��
	taitle.render(deltatime);

	//ENTER�������玟�̃V�[����
	if (gamemanager->triger_enter)sequence_.change(&SceneManager::seqStage);

	return true;
}
/*�v���C�X�e�[�W*/
bool SceneManager::seqStage(const float deltatime) {

	if (sequence_.isStart()) {
		/*�ŏ��̃X�e�[�W*/
		new map_StageA();
		new map_Wall();
		new Timer(t2k::Vector3(450, 90, 0));
		gamemanager->pla = new Player(t2k::Vector3(1024 >> 1, 768 >> 1, 0), 5);
		
		/*������load*/
		song.init_bgm = false;
		song.init_se = false;
		song.SONG_SE_Arrow();
		
		init_st1_sound = false;
	}

	if (gamemanager->GetCreSt_stage_type() == 1) {
		/*��������*/
		if (!init_st1_sound) {
			//����_DELETE
			DeleteSoundMem(song.bgm_taitle);

			//����_PLAY
			PlaySoundMem(song.bgm_stage, DX_PLAYTYPE_LOOP,false);

			init_st1_sound = true;
		}
	}

	//------------------------------------------------------------------------------
	/*player�ړ����̃X�e�[�W����*/
	c_st.create_Stage();

	//------------------------------------------------------------------------------
	/*GameEnd*/
	if (gamemanager->GetPlaHp_now() <= 0 || (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_Z) &&
		gamemanager->down_sift)){
		//�������ԋL�^
		preve_m = gamemanager->GetTime_M();
		preve_s = gamemanager->GetTime_S();

		//DELETE����
		Del_END();
		gamemanager->eraceCheck();

		//STAGETYPE��������
		c_st.pla_next_pop = 0;

		//���̃V�[���Ɉړ�
		sequence_.change(&SceneManager::seqGameEnd);
	}

	return true;
}
/*�Q�[���I��*/
bool SceneManager::seqGameEnd(const float deltatime) {

	if (sequence_.isStart()) {
		/*��������*/
		//load������������������
		DeleteSoundMem(song.bgm_stage);
		DeleteSoundMem(song.bgm_taitle);
		DeleteSoundMem(song.se_atach);
		DeleteSoundMem(song.se_shot);

		//��_PLAY
		song.init_bgm = false;
		
		PlaySoundMem(song.bgm_end, DX_PLAYTYPE_LOOP, true);
	}

	//�w�i�`��
	end.render(deltatime);
	
	//ENTER���������玟�̃V�[����
	if (gamemanager->triger_enter) {
		DeleteSoundMem(song.bgm_end);
		sequence_.change(&SceneManager::seqTitle);
	}

	return true;
}
/*�S�f���[�g*/
void SceneManager::Del_END() {
	/*player*/
	gamemanager->pla = nullptr;
	/*stage_type������*/
	c_st.stage_type = 0;
	/*�w�i�ύX*/
	img.init_img_back = false;
	/*arrow*/
	for (auto bp : gamemanager->blt_pla)bp->is_alive = false;
	for (auto ataw : gamemanager->atach_arw)ataw->is_alive = false;
	/*stage*/
	for (auto st_a : gamemanager->m_stA)st_a->is_alive = false;
	for (auto st_b : gamemanager->m_stB)st_b->is_alive = false;
	for (auto p_b : gamemanager->pop_stB)p_b->is_alive = false;
	/*enemy*/
	for (auto eb : gamemanager->enm_B)eb->is_alive = false;
	/*base*/
	for (auto ba : gamemanager->base)ba->is_alive = false;
}