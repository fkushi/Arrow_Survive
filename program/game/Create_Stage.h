#pragma once
class Create_Stage {
private:

public:
	Create_Stage();

	/*���݂̃X�e�[�W���*/
	int stage_type = 0;

	/*player���n���������ǂ̋����̔���*/
	int pla_next_pop = 0;

	//enum class CHOOSEWAY:uint32_t {
	enum class CHOOSEWAY : int {
		FAST,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		MAX
	};
	
	/*�t�F�[�h�C���A�t�F�[�h�A�E�g������flag*/
	bool init_fade = false;

	/*player���ړ�������X�e�[�W�ύX����flag*/
	//false�ɂȂ�����X�e�[�W�ύX
	bool init_change = true;
	
	void Changed_Delete();
	void create_Stage();
};