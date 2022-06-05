#include"Taitle.h"
#include"GameManager.h"
#include"DxLib.h"
#include "../support/Support.h"

extern GameManager* gamemanager;

Taitle::Taitle() {

}
Taitle::~Taitle() {

}

void Taitle::update(float deltatime) {
	
}
void Taitle::render(float deltatime) {
	
	/*•`‰æƒnƒ“ƒhƒ‹‚Ì“Ç‚İ‚İ*/	
	img_Taitle = gamemanager->LoadGraphEx("graphics/taitle.png");

	DrawRotaGraph(1024 >> 1, 768 >> 1, 1.0f, 0, img_Taitle, false);

}