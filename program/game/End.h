#pragma once
class GameEnd {
private:
	/*描画ハンドル*/
	int img_end = 0;

public:
	GameEnd();

	void update(const float deltatime);
	void render(const float deltatime);
};