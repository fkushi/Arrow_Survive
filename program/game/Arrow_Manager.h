#pragma once
#include"Base.h"
#include"../library/t2klib.h"

class Arrow_Manager : public Base{
private:

public:

	Arrow_Manager();

	/*ŠÖ”*/
	void Create_Arrow(t2k::Vector3 start, bool player_dir);

	void update(const float deltatime) override;
	void render(const float deltatime) override;
	
};