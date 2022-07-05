#pragma once
#include"Base.h"
#include"../library/t2klib.h"

class SceneManager {
private:


public:

	t2k::Sequence<SceneManager*> sequence_ =
		t2k::Sequence<SceneManager*>(this, &SceneManager::seqTitle);

	//title�V�[��
	bool seqTitle(const float deltatime);
	//�v���C�V�[��
	bool seqStage(const float deltatime);
	//���ʔ��\�V�[��
	bool seqGameEnd(const float deltatime);

	enum class SCENE:uint32_t {
		TITLE,
		STAGE,
		END,
		MAX
	};

	SCENE nowScene = SCENE::TITLE;

	/*inline int GetNowScene() {
		return static_cast<uint32_t>(nowScene);
	}*/



	bool init_st1_sound = false;
	
	//true�Ȃ猋�ʔ��\�V�[���Ɉڂ�
	bool init_move_seqGameEnd = false;

	//player�����S�A�j���[�V�������I��������1�b�Ԃ����V�[���ړ���҂�
	float count_move_seqGameEnd_interval = 1.0f;
	
	int preve_m = 0;
	int preve_s = 0;

	void Del_END();

};