#pragma once
class Fade_Manager {
public:

	Fade_Manager() : bright(0) {}
	~Fade_Manager(){}

	//true�Ȃ�t�F�[�h�A�E�g�Afalse�Ȃ�t�F�[�h�C��
	bool init_fade = false;

	bool FadeIn(int fade_speed);
	bool FadeOut(int fade_speed);

	void Fade();

private:

	int bright = 0;

};