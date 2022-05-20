#pragma once
#include"Base.h"
#include"../library/t2klib.h"
class Arrow_Wing : public Base {
private:

public:
	Arrow_Wing(t2k::Vector3 start);

	void update(const float deltatime)override;
	void render(const float deltatime)override;
};