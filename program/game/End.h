#pragma once
class GameEnd {
private:
	/*�`��n���h��*/
	int img_end = 0;

public:
	GameEnd();

	void update(const float deltatime);
	void render(const float deltatime);
};