#pragma once
#include"../library/t2klib.h"

class Arrow_Base {
private:

public:

	Arrow_Base();
	~Arrow_Base() {}

	t2k::Vector3 pos;
	t2k::Vector3 preve_pos;
	t2k::Vector3 dir;

	bool arrow_alive = true;
	bool DIR = false;
	int SPEED = 0;

	int arrow_type = 1;

	enum class ARROW_TYPE : UINT32 {
		MIN,
		ARROW,
		WING,
		FIRE,
		MAX
	};

	virtual void update_arrow(const float deltatime) {}
	virtual void render_arrow(const float deltatime) {}
};