#include"Timer.h"
#include"GameManager.h"
#include"DxLib.h"
#include"../support/Support.h"

extern GameManager* gamemanager;

//-----------------------------------------------------------------------------------------------------------
/*�������Ԍv��������N���X*/
//-----------------------------------------------------------------------------------------------------------

Timer::Timer(t2k::Vector3 start) {

	pos = start;

	//------------------------------------------------------------------
	/*�`��n���h���̓ǂݍ���*/
	//------------------------------------------------------------------
	img_timer = gamemanager->LoadGraphEx("graphics/Timer_cover.png");

	gamemanager->time.emplace_back(this);
}

void Timer::update(const float deltatime) {
	//------------------------------------------------------------------
	/*�����X�e�[�W�ȊO�ɂȂ�����^�C�}�[���J�n����*/
	//------------------------------------------------------------------
	if (gamemanager->GetCreSt_stage_type() > 0) {
		if (s < 59.5) s += deltatime;
		else {
			m++;
			for (auto pop_b : gamemanager->pop_enemyB)pop_b->add_speed++;
			for (auto mb : gamemanager->map_stageB)mb->init_plus_pos_B = false;
			s = 0;
		}
	}

	//------------------------------------------------------------------
	/*Player���߂Â�����timer�𓧉߂���*/
	//------------------------------------------------------------------
	if (gamemanager->GetPosPlayer().y < pos.y + 70 && gamemanager->GetPosPlayer().x>pos.x - 50 &&
		gamemanager->GetPosPlayer().x < pos.x + 180)alpha = 80;
	else alpha = 225;

	//------------------------------------------------------------------
	/*DEBUG�R�}���h*/
	//------------------------------------------------------------------
	//30�b�o�߂�����
	if (gamemanager->down_shift && t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_3))s = 30;
	//1���o�߂�����
	if (gamemanager->down_shift && 
		t2k::Input::isKeyDown(t2k::Input::KEYBORD_1) && t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_0)) {
		m = 1;
	}
	//3���o��
	if (gamemanager->down_shift && 
		t2k::Input::isKeyDown(t2k::Input::KEYBORD_3) &&	t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_0)) {
		m = 3;
		for (auto mb : gamemanager->map_stageB)mb->init_plus_pos_B = false;
	}

}
void Timer::render(const float deltatime) {
	
	//------------------------------------------------------------------
	/*player���߂Â�����摜�̃u�����h�̃A���t�@�l��ς���*/
	//------------------------------------------------------------------
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

	//------------------------------------------------------------------
	/*timer�̔w�i�̕`��*/
	//------------------------------------------------------------------
	DrawExtendGraph(static_cast<int>(pos.x) - 50, static_cast<int>(pos.y) - 20, static_cast<int>(pos.x) + 180 , 
		static_cast<int>(pos.y) + 70, img_timer, true);

	//------------------------------------------------------------------
	/*timer�̃J�E���g�`��@m:���@s:�b*/
	//------------------------------------------------------------------
	SetFontSize(50);
	DrawStringEx(static_cast<int>(pos.x), static_cast<int>(pos.y), 255, "%02d:%02.0f", m, s);
}